/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40443fe0 DllCanUnloadNow */

/* Boundary evidence: original MIPS .pdata 40443fe0..40444017. Semantic name remains unreviewed. */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x3fe0  8  DllCanUnloadNow */
  if (DAT_4046dec0 == 0) {
    HVar1 = 0x78;
  }
  else {
    HVar1 = FUN_4046a82c();
  }
  return HVar1;
}



/* 40444018 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40444018..4044404f. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  HRESULT HVar1;
  
                    /* 0x4018  9  DllGetClassObject */
  if (DAT_4046dec0 == 0) {
    HVar1 = 0x78;
  }
  else {
    HVar1 = FUN_4046a82c();
  }
  return HVar1;
}



/* 40444050 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40444050..40444087. Semantic name remains unreviewed. */

undefined4 DllRegisterServer(void)

{
  undefined4 uVar1;
  
                    /* 0x4050  10  DllRegisterServer */
  if (DAT_4046dec0 == 0) {
    uVar1 = 0x78;
  }
  else {
    uVar1 = FUN_4046a82c();
  }
  return uVar1;
}



/* 40444088 DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40444088..404440bf. Semantic name remains unreviewed. */

undefined4 DllUnregisterServer(void)

{
  undefined4 uVar1;
  
                    /* 0x4088  11  DllUnregisterServer */
  if (DAT_4046dec0 == 0) {
    uVar1 = 0x78;
  }
  else {
    uVar1 = FUN_4046a82c();
  }
  return uVar1;
}



/* 404440c0 FUN_404440c0 */

/* Boundary evidence: original MIPS .pdata 404440c0..4044421f. Semantic name remains unreviewed. */

undefined4 FUN_404440c0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  if (param_2 == 0) {
    FUN_40452398();
    iVar1 = __GetUserKData(0xc);
    iVar2 = GetOwnerProcess();
    if ((iVar1 == iVar2) && (pvVar3 = TlsGetValue(DAT_4046d1b0), pvVar3 != (LPVOID)0x0)) {
      CoSetState(0);
    }
    FUN_404576c0();
    FUN_404574a4();
  }
  else if (param_2 == 1) {
    DAT_4046d1c0 = param_1;
    FUN_40457484();
    DAT_4046d1c4 = 0x53d;
    iVar1 = FUN_4045802c();
    if (iVar1 < 0) {
      uVar4 = 0;
    }
  }
  else if (param_2 == 3) {
    iVar1 = __GetUserKData(0xc);
    iVar2 = GetOwnerProcess();
    if ((iVar1 == iVar2) && (pvVar3 = TlsGetValue(DAT_4046d1b0), pvVar3 != (LPVOID)0x0)) {
      CoSetState(0);
    }
  }
  return uVar4;
}



/* 40444220 FUN_40444220 */

/* Boundary evidence: original MIPS .pdata 40444220..4044422b. Semantic name remains unreviewed. */

undefined4 FUN_40444220(void)

{
  return 1;
}



/* 4044422c FUN_4044422c */

/* Boundary evidence: original MIPS .pdata 4044422c..4044427b. Semantic name remains unreviewed. */

undefined4 FUN_4044422c(SIZE_T param_1,undefined4 *param_2)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  pvVar1 = CoTaskMemAlloc(param_1);
  if (pvVar1 == (LPVOID)0x0) {
    uVar2 = 0x8007000e;
  }
  *param_2 = pvVar1;
  return uVar2;
}



/* 4044427c FUN_4044427c */

/* Boundary evidence: original MIPS .pdata 4044427c..404442a7. Semantic name remains unreviewed. */

void FUN_4044427c(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    CoTaskMemFree(param_1);
  }
  return;
}



/* 404442a8 FUN_404442a8 */

/* Boundary evidence: original MIPS .pdata 404442a8..404444ef. Semantic name remains unreviewed. */

undefined4 FUN_404442a8(LCID param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 extraout_var;
  WCHAR local_40 [2];
  WCHAR local_3c [2];
  WCHAR local_38 [10];
  uint local_24;
  
  local_24 = DAT_4046d1b8;
  FUN_404529b0();
  if ((DAT_4046d1d0 == param_2) &&
     ((DAT_4046d1cc == param_1 ||
      (((param_1 == 0x400 || (param_1 == 0x800)) &&
       (param_1 = GetUserDefaultLCID(), DAT_4046d1cc == param_1)))))) goto LAB_404444bc;
  iVar2 = GetLocaleInfoW(param_1,param_2 | 0x14,local_38,10);
  iVar2 = iVar2 + -1;
  if (iVar2 < 1) {
    DAT_4046d1dc = L'$';
    DAT_4046d1d4 = 1;
LAB_404443f0:
    DAT_4046d1d8 = 1;
  }
  else {
    LCMapStringW(param_1,0x100,local_38,iVar2,&DAT_4046d1dc,10);
    DAT_4046d1d8 = 0;
    DAT_4046d1d4 = iVar2;
    if ((iVar2 == 1) &&
       (LCMapStringW(param_1,0x200,&DAT_4046d1dc,1,local_38,1), DAT_4046d1dc == local_38[0]))
    goto LAB_404443f0;
  }
  iVar2 = GetLocaleInfoW(param_1,param_2 | 0xe,local_40,2);
  DAT_4046d1f0 = L'.';
  if (1 < iVar2) {
    DAT_4046d1f0 = local_40[0];
  }
  iVar2 = GetLocaleInfoW(param_1,param_2 | 0xf,local_40,2);
  DAT_4046d1f2 = L'\0';
  if (1 < iVar2) {
    DAT_4046d1f2 = local_40[0];
  }
  if (DAT_4046d1f2 == DAT_4046d1f0) {
    DAT_4046d1f2 = L'\0';
  }
  uVar1 = FUN_4044e650(param_1,DAT_4046d1f2,8);
  DAT_4046d1f4 = L' ';
  if (CONCAT22(extraout_var,uVar1) == 0) {
    DAT_4046d1f4 = DAT_4046d1f2;
  }
  local_3c[0] = L'1';
  GetLocaleInfoW(param_1,param_2 | 0x12,local_3c,2);
  DAT_4046d1f6 = (ushort)(local_3c[0] != L'0');
  DAT_4046d1cc = param_1;
  DAT_4046d1d0 = param_2;
LAB_404444bc:
  FUN_4046ace8(local_24);
  return 0;
}



/* 404444f0 VarBoolFromI1 */

HRESULT VarBoolFromI1(LONG lIn,VARIANT_BOOL *pboolOut)

{
  VARIANT_BOOL VVar1;
  
                    /* 0x44f0  55  VarBoolFromI1
                       0x44f0  56  VarBoolFromI2
                       0x44f0  57  VarBoolFromI4
                       0x44f0  61  VarBoolFromUI1
                       0x44f0  62  VarBoolFromUI2
                       0x44f0  63  VarBoolFromUI4 */
  VVar1 = -1;
  if (lIn == 0) {
    VVar1 = 0;
  }
  *pboolOut = VVar1;
  return 0;
}



/* 40444508 VarBoolFromR4 */

/* Boundary evidence: original MIPS .pdata 40444508..40444543. Semantic name remains unreviewed. */

HRESULT VarBoolFromR4(FLOAT fltIn,VARIANT_BOOL *pboolOut)

{
  int iVar1;
  undefined4 in_a0;
  VARIANT_BOOL VVar2;
  
                    /* 0x4508  58  VarBoolFromR4 */
  iVar1 = __nes(in_a0,0);
  VVar2 = -1;
  if (iVar1 == 0) {
    VVar2 = 0;
  }
  *pboolOut = VVar2;
  return 0;
}



/* 40444544 VarBoolFromR8 */

/* Boundary evidence: original MIPS .pdata 40444544..40444583. Semantic name remains unreviewed. */

HRESULT VarBoolFromR8(DOUBLE dblIn,VARIANT_BOOL *pboolOut)

{
  int iVar1;
  undefined4 in_a0;
  undefined4 in_a1;
  VARIANT_BOOL VVar2;
  
                    /* 0x4544  59  VarBoolFromR8 */
  iVar1 = __ned(in_a0,in_a1,0,0);
  VVar2 = -1;
  if (iVar1 == 0) {
    VVar2 = 0;
  }
  *pboolOut = VVar2;
  return 0;
}



/* 40444584 VarBoolFromDate */

/* Boundary evidence: original MIPS .pdata 40444584..404445c3. Semantic name remains unreviewed. */

HRESULT VarBoolFromDate(DATE dateIn,VARIANT_BOOL *pboolOut)

{
  int iVar1;
  undefined4 in_a0;
  undefined4 in_a1;
  VARIANT_BOOL VVar2;
  
                    /* 0x4584  52  VarBoolFromDate */
  iVar1 = __ned(in_a0,in_a1,0,0);
  VVar2 = -1;
  if (iVar1 == 0) {
    VVar2 = 0;
  }
  *pboolOut = VVar2;
  return 0;
}



/* 404445c4 VarBoolFromCy */

HRESULT VarBoolFromCy(CY cyIn,VARIANT_BOOL *pboolOut)

{
  VARIANT_BOOL VVar1;
  
                    /* 0x45c4  51  VarBoolFromCy */
  VVar1 = -1;
  if (cyIn.s.Lo == 0 && cyIn.s.Hi == 0) {
    VVar1 = 0;
  }
  *pboolOut = VVar1;
  return 0;
}



/* 404445e0 VarUI1FromI2 */

HRESULT VarUI1FromI2(SHORT sIn,BYTE *pbOut)

{
  HRESULT HVar1;
  
                    /* 0x45e0  190  VarUI1FromI2 */
  if ((ushort)sIn < 0x100) {
    *pbOut = (BYTE)sIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 4044460c VarUI1FromI4 */

HRESULT VarUI1FromI4(LONG lIn,BYTE *pbOut)

{
  HRESULT HVar1;
  
                    /* 0x460c  191  VarUI1FromI4
                       0x460c  195  VarUI1FromUI2
                       0x460c  196  VarUI1FromUI4 */
  if ((uint)lIn < 0x100) {
    *pbOut = (BYTE)lIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 40444634 VarUI1FromCy */

/* Boundary evidence: original MIPS .pdata 40444634..4044468b. Semantic name remains unreviewed. */

HRESULT VarUI1FromCy(CY cyIn,BYTE *pbOut)

{
  int iVar1;
  ushort local_10 [4];
  
                    /* 0x4634  185  VarUI1FromCy */
  iVar1 = FUN_40458964(cyIn.s.Lo,cyIn.s.Hi,local_10);
  if (iVar1 == 0) {
    if (local_10[0] < 0x100) {
      *pbOut = (BYTE)local_10[0];
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ffdfff6;
    }
  }
  return iVar1;
}



/* 4044468c VarUI1FromI1 */

HRESULT VarUI1FromI1(CHAR cIn,BYTE *pbOut)

{
  HRESULT HVar1;
  int3 in_register_00000011;
  
                    /* 0x468c  189  VarUI1FromI1 */
  if (in_register_00000011 < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pbOut = cIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 404446b0 VarI2FromBool */

HRESULT VarI2FromBool(CHAR cIn,SHORT *psOut)

{
  undefined1 in_register_00000011;
  
                    /* 0x46b0  130  VarI2FromBool
                       0x46b0  135  VarI2FromI1
                       0x46b0  140  VarI2FromUI1
                       0x46b0  197  VarUI2FromBool
                       0x46b0  208  VarUI2FromUI1 */
  *psOut = CONCAT11(in_register_00000011,cIn);
  return 0;
}



/* 404446bc VarI2FromI4 */

HRESULT VarI2FromI4(LONG lIn,SHORT *psOut)

{
  HRESULT HVar1;
  
                    /* 0x46bc  136  VarI2FromI4 */
  if ((lIn < -0x8000) || (0x7fff < lIn)) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *psOut = (SHORT)lIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 404446f4 VarI2FromCy */

/* Boundary evidence: original MIPS .pdata 404446f4..4044470f. Semantic name remains unreviewed. */

HRESULT VarI2FromCy(CY cyIn,SHORT *psOut)

{
  int iVar1;
  
                    /* 0x46f4  131  VarI2FromCy */
  iVar1 = FUN_40458964(cyIn.s.Lo,cyIn.s.Hi,psOut);
  return iVar1;
}



/* 40444710 VarI2FromStr */

/* Boundary evidence: original MIPS .pdata 40444710..404447c7. Semantic name remains unreviewed. */

HRESULT VarI2FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,SHORT *psOut)

{
  HRESULT HVar1;
  NUMPARSE local_48;
  VARIANT VStack_30;
  BYTE aBStack_20 [12];
  uint local_14;
  
                    /* 0x4710  139  VarI2FromStr */
  local_14 = DAT_4046d1b8;
  local_48.cDig = 0xc;
  local_48.dwInFlags = 0x1fff;
  HVar1 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_48,aBStack_20);
  if (((HVar1 == 0) || (-1 < HVar1)) &&
     ((HVar1 = VarNumFromParseNum(&local_48,aBStack_20,4,&VStack_30), HVar1 == 0 || (-1 < HVar1))))
  {
    *psOut = VStack_30.n1._8_2_;
    FUN_4046ace8(local_14);
    HVar1 = 0;
  }
  else {
    FUN_4046ace8(local_14);
  }
  return HVar1;
}



/* 404447c8 VarI2FromUI2 */

HRESULT VarI2FromUI2(ULONG ulIn,SHORT *psOut)

{
  HRESULT HVar1;
  
                    /* 0x47c8  141  VarI2FromUI2
                       0x47c8  142  VarI2FromUI4 */
  if (ulIn < 0x8000) {
    *psOut = (SHORT)ulIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 404447f4 VarI4FromBool */

HRESULT VarI4FromBool(CHAR cIn,LONG *plOut)

{
  undefined3 in_register_00000011;
  
                    /* 0x47f4  143  VarI4FromBool
                       0x47f4  148  VarI4FromI1
                       0x47f4  149  VarI4FromI2
                       0x47f4  153  VarI4FromUI1
                       0x47f4  154  VarI4FromUI2
                       0x47f4  210  VarUI4FromBool
                       0x47f4  221  VarUI4FromUI1
                       0x47f4  222  VarUI4FromUI2 */
  *plOut = CONCAT31(in_register_00000011,cIn);
  return 0;
}



/* 40444800 VarI4FromCy */

/* Boundary evidence: original MIPS .pdata 40444800..4044481b. Semantic name remains unreviewed. */

HRESULT VarI4FromCy(CY cyIn,LONG *plOut)

{
  HRESULT HVar1;
  
                    /* 0x4800  144  VarI4FromCy */
  HVar1 = FUN_40458620(cyIn.s.Lo,cyIn.s.Hi,(uint *)plOut);
  return HVar1;
}



/* 4044481c VarI4FromStr */

/* Boundary evidence: original MIPS .pdata 4044481c..40444a57. Semantic name remains unreviewed. */

HRESULT VarI4FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,LONG *plOut)

{
  byte bVar1;
  HRESULT HVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  NUMPARSE local_38;
  byte local_20 [12];
  uint local_14;
  
                    /* 0x481c  152  VarI4FromStr */
  local_14 = DAT_4046d1b8;
  local_38.cDig = 0xb;
  local_38.dwInFlags = 0x1fff;
  HVar2 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_38,local_20);
  if ((HVar2 != 0) && (HVar2 < 0)) {
    FUN_4046ace8(local_14);
    return HVar2;
  }
  uVar4 = 0;
  pbVar6 = local_20;
  if (local_38.nBaseShift != 0) {
    if ((local_38.nBaseShift * local_38.cDig < 0x22) &&
       ((iVar5 = local_38.cDig, local_38.nBaseShift * local_38.cDig != 0x21 || (local_20[0] < 4))))
    {
      for (; 0 < iVar5; iVar5 = iVar5 + -1) {
        uVar4 = (uVar4 << (local_38.nBaseShift & 0x1fU)) + (uint)*pbVar6;
        pbVar6 = pbVar6 + 1;
      }
      goto LAB_40444a44;
    }
    goto LAB_404448c4;
  }
  iVar3 = local_38.nPwr10 + local_38.cDig;
  iVar5 = local_38.cDig;
  if (iVar3 < 10) {
    if (0 < iVar3) goto LAB_404448f4;
LAB_40444944:
    if ((0 < iVar5) && (iVar3 == 0)) {
      if (*pbVar6 < 6) {
        if (*pbVar6 != 5) goto LAB_404449c0;
        if ((local_38.dwOutFlags & 0x20000) == 0) {
          for (; 1 < iVar5; iVar5 = iVar5 + -1) {
            pbVar6 = pbVar6 + 1;
            if (*pbVar6 != 0) goto LAB_404449bc;
          }
          if ((uVar4 & 1) != 1) goto LAB_404449c0;
        }
      }
LAB_404449bc:
      uVar4 = uVar4 + 1;
    }
  }
  else {
    if ((iVar3 != 10) || (2 < local_20[0])) goto LAB_404448c4;
LAB_404448f4:
    do {
      if (iVar5 < 1) break;
      bVar1 = *pbVar6;
      pbVar6 = pbVar6 + 1;
      iVar3 = iVar3 + -1;
      iVar5 = iVar5 + -1;
      uVar4 = uVar4 * 10 + (uint)bVar1;
    } while (0 < iVar3);
    if (iVar3 < 1) goto LAB_40444944;
    uVar4 = *(int *)(&DAT_40441050 + iVar3 * 4) * uVar4;
  }
LAB_404449c0:
  if ((local_38.dwOutFlags & 0x10000) == 0) {
    if (-1 < (int)uVar4) goto LAB_40444a44;
  }
  else {
    uVar4 = -uVar4;
    if ((int)uVar4 < 1) {
LAB_40444a44:
      *plOut = uVar4;
      FUN_4046ace8(local_14);
      return 0;
    }
  }
LAB_404448c4:
  FUN_4046ace8(local_14);
  return -0x7ffdfff6;
}



/* 40444a58 VarI4FromUI4 */

HRESULT VarI4FromUI4(ULONG ulIn,LONG *plOut)

{
  HRESULT HVar1;
  
                    /* 0x4a58  155  VarI4FromUI4 */
  if (ulIn < 0x80000000) {
    *plOut = ulIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 40444a84 FUN_40444a84 */

/* Boundary evidence: original MIPS .pdata 40444a84..40444b43. Semantic name remains unreviewed. */

uint FUN_40444a84(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = __dptoli(param_1,param_2);
  uVar4 = __litodp(uVar1);
  uVar4 = __dpsub(param_1,param_2,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  uVar3 = (uint)((ulonglong)uVar4 >> 0x20);
  iVar2 = __ned((int)uVar4,uVar3 & 0x7fffffff,0,0x3fe00000);
  if ((iVar2 != 0) || ((uVar1 & 1) != 0)) {
    uVar4 = __dpmul((int)uVar4,uVar3,0,0xc0000000);
    iVar2 = __dptoli((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    uVar1 = uVar1 - iVar2;
  }
  return uVar1;
}



/* 40444b44 FUN_40444b44 */

/* Boundary evidence: original MIPS .pdata 40444b44..40444c37. Semantic name remains unreviewed. */

uint FUN_40444b44(double param_1)

{
  undefined4 extraout_v0;
  uint uVar1;
  int iVar2;
  undefined4 extraout_v1;
  undefined4 local_20;
  undefined4 local_1c;
  
  modf(param_1,(double *)&local_20);
  uVar1 = __dptoul(local_20,local_1c);
  iVar2 = __gtd(extraout_v0,extraout_v1,0,0x3fe00000);
  if ((iVar2 == 0) &&
     ((iVar2 = __eqd(extraout_v0,extraout_v1,0,0x3fe00000), iVar2 == 0 || ((uVar1 & 1) == 0)))) {
    iVar2 = __ltd(extraout_v0,extraout_v1,0,0xbfe00000);
    if ((iVar2 != 0) ||
       ((iVar2 = __eqd(extraout_v0,extraout_v1,0,0xbfe00000), iVar2 != 0 && ((uVar1 & 1) != 0)))) {
      uVar1 = uVar1 - 1;
    }
  }
  else {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}



/* 40444c38 VarR4FromUI1 */

/* Boundary evidence: original MIPS .pdata 40444c38..40444c63. Semantic name remains unreviewed. */

HRESULT VarR4FromUI1(BYTE bIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4c38  168  VarR4FromUI1 */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444c64 VarR4FromI2 */

/* Boundary evidence: original MIPS .pdata 40444c64..40444c8f. Semantic name remains unreviewed. */

HRESULT VarR4FromI2(SHORT sIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4c64  164  VarR4FromI2 */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444c90 VarR4FromBool */

/* Boundary evidence: original MIPS .pdata 40444c90..40444cbb. Semantic name remains unreviewed. */

HRESULT VarR4FromBool(VARIANT_BOOL boolIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4c90  158  VarR4FromBool */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444cbc VarR4FromI4 */

/* Boundary evidence: original MIPS .pdata 40444cbc..40444ce7. Semantic name remains unreviewed. */

HRESULT VarR4FromI4(LONG lIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4cbc  165  VarR4FromI4 */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444ce8 VarR4FromR8 */

/* Boundary evidence: original MIPS .pdata 40444ce8..40444d9b. Semantic name remains unreviewed. */

HRESULT VarR4FromR8(DOUBLE dblIn,FLOAT *pfltOut)

{
  int iVar1;
  FLOAT FVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x4ce8  166  VarR4FromR8 */
  iVar1 = __ged(in_a0,in_a1,0xefffffff,0xc7efffff);
  if ((iVar1 == 0) || (iVar1 = __led(in_a0,in_a1,0xefffffff,0x47efffff), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    FVar2 = (FLOAT)__dptofp(in_a0,in_a1);
    *pfltOut = FVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40444d9c VarR4FromCy */

/* Boundary evidence: original MIPS .pdata 40444d9c..40444db7. Semantic name remains unreviewed. */

HRESULT VarR4FromCy(CY cyIn,FLOAT *pfltOut)

{
  HRESULT HVar1;
  
                    /* 0x4d9c  159  VarR4FromCy */
  HVar1 = FUN_40458480(cyIn.s.Lo,cyIn.s.Hi,pfltOut);
  return HVar1;
}



/* 40444db8 VarR4FromDate */

/* Boundary evidence: original MIPS .pdata 40444db8..40444dd3. Semantic name remains unreviewed. */

HRESULT VarR4FromDate(DATE dateIn,FLOAT *pfltOut)

{
  HRESULT HVar1;
  
                    /* 0x4db8  160  VarR4FromDate */
  HVar1 = VarR4FromR8(dateIn,pfltOut);
  return HVar1;
}



/* 40444dd4 VarR4FromStr */

/* Boundary evidence: original MIPS .pdata 40444dd4..40444e8b. Semantic name remains unreviewed. */

HRESULT VarR4FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,FLOAT *pfltOut)

{
  HRESULT HVar1;
  NUMPARSE local_48;
  VARIANT VStack_30;
  BYTE aBStack_20 [12];
  uint local_14;
  
                    /* 0x4dd4  167  VarR4FromStr */
  local_14 = DAT_4046d1b8;
  local_48.cDig = 0xc;
  local_48.dwInFlags = 0x1fff;
  HVar1 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_48,aBStack_20);
  if (((HVar1 == 0) || (-1 < HVar1)) &&
     ((HVar1 = VarNumFromParseNum(&local_48,aBStack_20,0x10,&VStack_30), HVar1 == 0 || (-1 < HVar1))
     )) {
    *pfltOut = (FLOAT)VStack_30.n1._8_4_;
    FUN_4046ace8(local_14);
    HVar1 = 0;
  }
  else {
    FUN_4046ace8(local_14);
  }
  return HVar1;
}



/* 40444e8c VarR4FromI1 */

/* Boundary evidence: original MIPS .pdata 40444e8c..40444eb7. Semantic name remains unreviewed. */

HRESULT VarR4FromI1(CHAR cIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4e8c  163  VarR4FromI1 */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444eb8 VarR4FromUI2 */

/* Boundary evidence: original MIPS .pdata 40444eb8..40444ee3. Semantic name remains unreviewed. */

HRESULT VarR4FromUI2(USHORT uiIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4eb8  169  VarR4FromUI2 */
  FVar1 = (FLOAT)__litofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444ee4 VarR4FromUI4 */

/* Boundary evidence: original MIPS .pdata 40444ee4..40444f0f. Semantic name remains unreviewed. */

HRESULT VarR4FromUI4(ULONG ulIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  
                    /* 0x4ee4  170  VarR4FromUI4 */
  FVar1 = (FLOAT)__ultofp();
  *pfltOut = FVar1;
  return 0;
}



/* 40444f10 VarR8FromUI1 */

/* Boundary evidence: original MIPS .pdata 40444f10..40444f3f. Semantic name remains unreviewed. */

HRESULT VarR8FromUI1(BYTE bIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x4f10  181  VarR8FromUI1 */
  DVar1 = (DOUBLE)__ultodp();
  *pdblOut = DVar1;
  return 0;
}



/* 40444f40 VarR8FromI2 */

/* Boundary evidence: original MIPS .pdata 40444f40..40444f6f. Semantic name remains unreviewed. */

HRESULT VarR8FromI2(SHORT sIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x4f40  177  VarR8FromI2 */
  DVar1 = (DOUBLE)__litodp();
  *pdblOut = DVar1;
  return 0;
}



/* 40444f70 VarR8FromBool */

/* Boundary evidence: original MIPS .pdata 40444f70..40444f9f. Semantic name remains unreviewed. */

HRESULT VarR8FromBool(VARIANT_BOOL boolIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x4f70  171  VarR8FromBool */
  DVar1 = (DOUBLE)__litodp();
  *pdblOut = DVar1;
  return 0;
}



/* 40444fa0 VarR8FromI4 */

/* Boundary evidence: original MIPS .pdata 40444fa0..40444fcf. Semantic name remains unreviewed. */

HRESULT VarR8FromI4(LONG lIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x4fa0  178  VarR8FromI4 */
  DVar1 = (DOUBLE)__litodp();
  *pdblOut = DVar1;
  return 0;
}



/* 40444fd0 VarR8FromR4 */

/* Boundary evidence: original MIPS .pdata 40444fd0..40444fff. Semantic name remains unreviewed. */

HRESULT VarR8FromR4(FLOAT fltIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x4fd0  179  VarR8FromR4 */
  DVar1 = (DOUBLE)__fptodp();
  *pdblOut = DVar1;
  return 0;
}



/* 40445000 VarR8FromCy */

/* Boundary evidence: original MIPS .pdata 40445000..4044501b. Semantic name remains unreviewed. */

HRESULT VarR8FromCy(CY cyIn,DOUBLE *pdblOut)

{
  HRESULT HVar1;
  
                    /* 0x5000  172  VarR8FromCy */
  HVar1 = FUN_40458528(cyIn.s.Lo,cyIn.s.Hi,pdblOut);
  return HVar1;
}



/* 4044501c VarR8FromDate */

HRESULT VarR8FromDate(DATE dateIn,DOUBLE *pdblOut)

{
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x501c  173  VarR8FromDate */
  *(undefined4 *)pdblOut = in_a0;
  *(undefined4 *)((int)pdblOut + 4) = in_a1;
  return 0;
}



/* 4044502c VarR8FromStr */

/* Boundary evidence: original MIPS .pdata 4044502c..404450eb. Semantic name remains unreviewed. */

HRESULT VarR8FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,DOUBLE *pdblOut)

{
  HRESULT HVar1;
  VARIANT VStack_50;
  NUMPARSE local_40;
  BYTE aBStack_28 [20];
  uint local_14;
  
                    /* 0x502c  180  VarR8FromStr */
  local_14 = DAT_4046d1b8;
  local_40.cDig = 0x14;
  local_40.dwInFlags = 0x1fff;
  HVar1 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_40,aBStack_28);
  if (((HVar1 == 0) || (-1 < HVar1)) &&
     ((HVar1 = VarNumFromParseNum(&local_40,aBStack_28,0x20,&VStack_50), HVar1 == 0 || (-1 < HVar1))
     )) {
    *(undefined4 *)pdblOut = VStack_50.n1._8_4_;
    *(undefined4 *)((int)pdblOut + 4) = VStack_50.n1._12_4_;
    FUN_4046ace8(local_14);
    HVar1 = 0;
  }
  else {
    FUN_4046ace8(local_14);
  }
  return HVar1;
}



/* 404450ec VarR8FromI1 */

/* Boundary evidence: original MIPS .pdata 404450ec..4044511b. Semantic name remains unreviewed. */

HRESULT VarR8FromI1(CHAR cIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x50ec  176  VarR8FromI1 */
  DVar1 = (DOUBLE)__litodp();
  *pdblOut = DVar1;
  return 0;
}



/* 4044511c VarR8FromUI2 */

/* Boundary evidence: original MIPS .pdata 4044511c..4044514b. Semantic name remains unreviewed. */

HRESULT VarR8FromUI2(USHORT uiIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x511c  182  VarR8FromUI2 */
  DVar1 = (DOUBLE)__ultodp();
  *pdblOut = DVar1;
  return 0;
}



/* 4044514c VarR8FromUI4 */

/* Boundary evidence: original MIPS .pdata 4044514c..4044517b. Semantic name remains unreviewed. */

HRESULT VarR8FromUI4(ULONG ulIn,DOUBLE *pdblOut)

{
  DOUBLE DVar1;
  
                    /* 0x514c  183  VarR8FromUI4 */
  DVar1 = (DOUBLE)__ultodp();
  *pdblOut = DVar1;
  return 0;
}



/* 4044517c VarDateFromI2 */

/* Boundary evidence: original MIPS .pdata 4044517c..4044520f. Semantic name remains unreviewed. */

HRESULT VarDateFromI2(SHORT sIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined2 in_register_00000012;
  DATE DVar4;
  
                    /* 0x517c  95  VarDateFromI2 */
  DVar4 = (DATE)__litodp(CONCAT22(in_register_00000012,sIn));
  uVar3 = (undefined4)((ulonglong)DVar4 >> 0x20);
  iVar1 = __ged(SUB84(DVar4,0),uVar3,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(SUB84(DVar4,0),uVar3,0,0xc1241036), iVar1 == 0)) {
    HVar2 = 0;
    *pdateOut = DVar4;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 40445210 VarDateFromBool */

/* Boundary evidence: original MIPS .pdata 40445210..4044522b. Semantic name remains unreviewed. */

HRESULT VarDateFromBool(VARIANT_BOOL boolIn,DATE *pdateOut)

{
  HRESULT HVar1;
  
                    /* 0x5210  90  VarDateFromBool */
  HVar1 = VarDateFromI2(boolIn,pdateOut);
  return HVar1;
}



/* 4044522c VarDateFromI4 */

/* Boundary evidence: original MIPS .pdata 4044522c..404452bf. Semantic name remains unreviewed. */

HRESULT VarDateFromI4(LONG lIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  DATE DVar4;
  
                    /* 0x522c  96  VarDateFromI4 */
  DVar4 = (DATE)__litodp();
  uVar3 = (undefined4)((ulonglong)DVar4 >> 0x20);
  iVar1 = __ged(SUB84(DVar4,0),uVar3,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(SUB84(DVar4,0),uVar3,0,0xc1241036), iVar1 == 0)) {
    HVar2 = 0;
    *pdateOut = DVar4;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 404452c0 VarDateFromR4 */

/* Boundary evidence: original MIPS .pdata 404452c0..4044533b. Semantic name remains unreviewed. */

HRESULT VarDateFromR4(FLOAT fltIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 in_a0;
  DATE DVar3;
  
                    /* 0x52c0  97  VarDateFromR4 */
  iVar1 = __ges(in_a0,0x4a349208);
  if ((iVar1 == 0) && (iVar1 = __les(in_a0,0xc92081b0), iVar1 == 0)) {
    DVar3 = (DATE)__fptodp(in_a0);
    HVar2 = 0;
    *pdateOut = DVar3;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 4044533c VarDateFromR8 */

/* Boundary evidence: original MIPS .pdata 4044533c..404453cb. Semantic name remains unreviewed. */

HRESULT VarDateFromR8(DOUBLE dblIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x533c  98  VarDateFromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(in_a0,in_a1,0,0xc1241036), iVar1 == 0)) {
    *(undefined4 *)pdateOut = in_a0;
    HVar2 = 0;
    *(undefined4 *)((int)pdateOut + 4) = in_a1;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 404453cc VarDateFromCy */

/* Boundary evidence: original MIPS .pdata 404453cc..4044546b. Semantic name remains unreviewed. */

HRESULT VarDateFromCy(CY cyIn,DATE *pdateOut)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x53cc  91  VarDateFromCy */
  iVar1 = FUN_40458528(cyIn.s.Lo,cyIn.s.Hi,(undefined8 *)&local_18);
  if (iVar1 == 0) {
    iVar1 = __ged(local_18,local_14,0,0x41469241);
    if ((iVar1 == 0) && (iVar1 = __led(local_18,local_14,0,0xc1241036), iVar1 == 0)) {
      *(undefined4 *)pdateOut = local_18;
      iVar1 = 0;
      *(undefined4 *)((int)pdateOut + 4) = local_14;
    }
    else {
      iVar1 = -0x7ffdfffb;
    }
  }
  return iVar1;
}



/* 4044546c VarDateFromI1 */

/* Boundary evidence: original MIPS .pdata 4044546c..404454ff. Semantic name remains unreviewed. */

HRESULT VarDateFromI1(CHAR cIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined3 in_register_00000011;
  DATE DVar4;
  
                    /* 0x546c  94  VarDateFromI1 */
  DVar4 = (DATE)__litodp(CONCAT31(in_register_00000011,cIn));
  uVar3 = (undefined4)((ulonglong)DVar4 >> 0x20);
  iVar1 = __ged(SUB84(DVar4,0),uVar3,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(SUB84(DVar4,0),uVar3,0,0xc1241036), iVar1 == 0)) {
    HVar2 = 0;
    *pdateOut = DVar4;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 40445500 VarDateFromUI2 */

/* Boundary evidence: original MIPS .pdata 40445500..40445593. Semantic name remains unreviewed. */

HRESULT VarDateFromUI2(USHORT uiIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined2 in_register_00000012;
  DATE DVar4;
  
                    /* 0x5500  101  VarDateFromUI2 */
  DVar4 = (DATE)__ultodp(CONCAT22(in_register_00000012,uiIn));
  uVar3 = (undefined4)((ulonglong)DVar4 >> 0x20);
  iVar1 = __ged(SUB84(DVar4,0),uVar3,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(SUB84(DVar4,0),uVar3,0,0xc1241036), iVar1 == 0)) {
    HVar2 = 0;
    *pdateOut = DVar4;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 40445594 VarDateFromUI4 */

/* Boundary evidence: original MIPS .pdata 40445594..40445627. Semantic name remains unreviewed. */

HRESULT VarDateFromUI4(ULONG ulIn,DATE *pdateOut)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  DATE DVar4;
  
                    /* 0x5594  102  VarDateFromUI4 */
  DVar4 = (DATE)__ultodp();
  uVar3 = (undefined4)((ulonglong)DVar4 >> 0x20);
  iVar1 = __ged(SUB84(DVar4,0),uVar3,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(SUB84(DVar4,0),uVar3,0,0xc1241036), iVar1 == 0)) {
    HVar2 = 0;
    *pdateOut = DVar4;
  }
  else {
    HVar2 = -0x7ffdfffb;
  }
  return HVar2;
}



/* 40445628 VarCyFromUI1 */

/* Boundary evidence: original MIPS .pdata 40445628..40445643. Semantic name remains unreviewed. */

HRESULT VarCyFromUI1(BYTE bIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined3 in_register_00000011;
  
                    /* 0x5628  87  VarCyFromUI1 */
  HVar1 = FUN_404585c8(CONCAT31(in_register_00000011,bIn),(uint *)pcyOut);
  return HVar1;
}



/* 40445644 VarCyFromI2 */

/* Boundary evidence: original MIPS .pdata 40445644..4044565f. Semantic name remains unreviewed. */

HRESULT VarCyFromI2(SHORT sIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  
                    /* 0x5644  82  VarCyFromI2 */
  HVar1 = FUN_404585c8(CONCAT22(in_register_00000012,sIn),(uint *)pcyOut);
  return HVar1;
}



/* 40445660 VarCyFromI4 */

/* Boundary evidence: original MIPS .pdata 40445660..4044567b. Semantic name remains unreviewed. */

HRESULT VarCyFromI4(LONG lIn,CY *pcyOut)

{
  HRESULT HVar1;
  
                    /* 0x5660  83  VarCyFromI4 */
  HVar1 = FUN_4045814c(lIn,(uint *)pcyOut);
  return HVar1;
}



/* 4044567c VarCyFromR4 */

/* Boundary evidence: original MIPS .pdata 4044567c..4044569b. Semantic name remains unreviewed. */

HRESULT VarCyFromR4(FLOAT fltIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined1 local_res0 [16];
  
                    /* 0x567c  84  VarCyFromR4 */
  HVar1 = FUN_404585e4((undefined4 *)local_res0,(ulonglong *)pcyOut);
  return HVar1;
}



/* 4044569c VarCyFromR8 */

/* Boundary evidence: original MIPS .pdata 4044569c..404456c3. Semantic name remains unreviewed. */

HRESULT VarCyFromR8(DOUBLE dblIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined1 local_res0 [16];
  
                    /* 0x569c  85  VarCyFromR8 */
  HVar1 = FUN_404581dc((undefined4 *)local_res0,(ulonglong *)pcyOut);
  return HVar1;
}



/* 404456c4 VarCyFromDate */

/* Boundary evidence: original MIPS .pdata 404456c4..404456eb. Semantic name remains unreviewed. */

HRESULT VarCyFromDate(DATE dateIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined4 local_10 [2];
  
                    /* 0x56c4  78  VarCyFromDate */
  HVar1 = FUN_404581dc(local_10,(ulonglong *)pcyOut);
  return HVar1;
}



/* 404456ec VarCyFromBool */

/* Boundary evidence: original MIPS .pdata 404456ec..40445707. Semantic name remains unreviewed. */

HRESULT VarCyFromBool(VARIANT_BOOL boolIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  
                    /* 0x56ec  77  VarCyFromBool */
  HVar1 = FUN_404585c8(CONCAT22(in_register_00000012,boolIn),(uint *)pcyOut);
  return HVar1;
}



/* 40445708 VarCyFromStr */

/* Boundary evidence: original MIPS .pdata 40445708..404457c7. Semantic name remains unreviewed. */

HRESULT VarCyFromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,CY *pcyOut)

{
  HRESULT HVar1;
  VARIANT VStack_58;
  NUMPARSE local_48;
  BYTE aBStack_30 [24];
  uint local_18;
  
                    /* 0x5708  86  VarCyFromStr */
  local_18 = DAT_4046d1b8;
  local_48.cDig = 0x15;
  local_48.dwInFlags = 0x1fff;
  HVar1 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_48,aBStack_30);
  if (((HVar1 == 0) || (-1 < HVar1)) &&
     ((HVar1 = VarNumFromParseNum(&local_48,aBStack_30,0x40,&VStack_58), HVar1 == 0 || (-1 < HVar1))
     )) {
    (pcyOut->s).Lo = VStack_58.n1._8_4_;
    (pcyOut->s).Hi = VStack_58.n1._12_4_;
    FUN_4046ace8(local_18);
    HVar1 = 0;
  }
  else {
    FUN_4046ace8(local_18);
  }
  return HVar1;
}



/* 404457c8 VarCyFromI1 */

/* Boundary evidence: original MIPS .pdata 404457c8..404457e3. Semantic name remains unreviewed. */

HRESULT VarCyFromI1(CHAR cIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined3 in_register_00000011;
  
                    /* 0x57c8  81  VarCyFromI1 */
  HVar1 = FUN_404585c8(CONCAT31(in_register_00000011,cIn),(uint *)pcyOut);
  return HVar1;
}



/* 404457e4 VarCyFromUI2 */

/* Boundary evidence: original MIPS .pdata 404457e4..404457ff. Semantic name remains unreviewed. */

HRESULT VarCyFromUI2(USHORT uiIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  
                    /* 0x57e4  88  VarCyFromUI2 */
  HVar1 = FUN_4045814c(CONCAT22(in_register_00000012,uiIn),(uint *)pcyOut);
  return HVar1;
}



/* 40445800 VarCyFromUI4 */

/* Boundary evidence: original MIPS .pdata 40445800..40445833. Semantic name remains unreviewed. */

HRESULT VarCyFromUI4(ULONG ulIn,CY *pcyOut)

{
  HRESULT HVar1;
  undefined4 local_10 [2];
  
                    /* 0x5800  89  VarCyFromUI4 */
  local_10[0] = __ultofp();
  HVar1 = FUN_404585e4(local_10,(ulonglong *)pcyOut);
  return HVar1;
}



/* 40445834 FUN_40445834 */

/* Boundary evidence: original MIPS .pdata 40445834..40445903. Semantic name remains unreviewed. */

int FUN_40445834(LCID param_1,wchar_t *param_2,undefined4 *param_3)

{
  size_t sVar1;
  int iVar2;
  
  *param_3 = 0;
  sVar1 = wcslen(param_2);
  iVar2 = FUN_4044422c((sVar1 + 1) * 2,param_3);
  if ((iVar2 == 0) || (-1 < iVar2)) {
    iVar2 = LCMapStringW(param_1,0x400000,param_2,-1,(LPWSTR)*param_3,sVar1 + 1 & 0x7fffffff);
    if (iVar2 == 0) {
      if ((LPVOID)*param_3 != (LPVOID)0x0) {
        CoTaskMemFree((LPVOID)*param_3);
      }
      iVar2 = -0x7ffdfffb;
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* 40445904 VarBstrFromI2 */

/* Boundary evidence: original MIPS .pdata 40445904..40445953. Semantic name remains unreviewed. */

HRESULT VarBstrFromI2(SHORT iVal,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  OLECHAR aOStack_60 [40];
  uint local_10;
  
                    /* 0x5904  70  VarBstrFromI2 */
  local_10 = DAT_4046d1b8;
  FUN_40452290(CONCAT22(in_register_00000012,iVal),aOStack_60);
  HVar1 = FUN_4044bad4(aOStack_60,pbstrOut);
  FUN_4046ace8(local_10);
  return HVar1;
}



/* 40445954 VarBstrFromBool */

/* Boundary evidence: original MIPS .pdata 40445954..4044598b. Semantic name remains unreviewed. */

HRESULT VarBstrFromBool(VARIANT_BOOL boolIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  wchar_t *pwVar2;
  
                    /* 0x5954  64  VarBstrFromBool */
  if (CONCAT22(in_register_00000012,boolIn) == 0) {
    pwVar2 = L"False";
  }
  else {
    pwVar2 = L"True";
  }
  HVar1 = FUN_4044bad4(pwVar2,pbstrOut);
  return HVar1;
}



/* 4044598c VarBstrFromI4 */

/* Boundary evidence: original MIPS .pdata 4044598c..404459db. Semantic name remains unreviewed. */

HRESULT VarBstrFromI4(LONG lIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  OLECHAR aOStack_60 [40];
  uint local_10;
  
                    /* 0x598c  71  VarBstrFromI4 */
  local_10 = DAT_4046d1b8;
  FUN_404522cc(lIn,aOStack_60);
  HVar1 = FUN_4044bad4(aOStack_60,pbstrOut);
  FUN_4046ace8(local_10);
  return HVar1;
}



/* 404459dc VarBstrFromCy */

/* Boundary evidence: original MIPS .pdata 404459dc..40445c97. Semantic name remains unreviewed. */

HRESULT VarBstrFromCy(CY cyIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  short *psVar5;
  wchar_t *pwVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  wchar_t *_Dest;
  uint uVar10;
  int iVar11;
  uint local_c0 [4];
  wchar_t awStack_b0 [26];
  wchar_t local_7c;
  short local_76 [3];
  wchar_t local_70;
  wchar_t awStack_6e [39];
  uint local_20;
  
                    /* 0x59dc  65  VarBstrFromCy */
  uVar9 = cyIn.s.Hi;
  uVar10 = cyIn.s.Lo;
  local_20 = DAT_4046d1b8;
  _Dest = &local_70;
  iVar4 = FUN_404442a8(lcid,dwFlags);
  if ((iVar4 == 0) || (-1 < iVar4)) {
    bVar3 = false;
    if ((longlong)cyIn < 0) {
      uVar10 = -uVar10;
      uVar9 = ~uVar9;
      if (uVar10 == 0) {
        uVar9 = uVar9 + 1;
      }
      bVar3 = true;
    }
    local_c0[0] = uVar10 & 0xffff;
    local_c0[1] = uVar10 >> 0x10;
    local_c0[2] = uVar9 & 0xffff;
    iVar4 = 0x1f;
    local_c0[3] = uVar9 >> 0x10;
    do {
      bVar2 = false;
      iVar8 = 3;
      puVar7 = local_c0 + 2;
      do {
        uVar10 = puVar7[1] / 10000;
        *puVar7 = puVar7[1] % 10000 << 0x10 | *puVar7;
        puVar7[1] = uVar10;
        if (uVar10 != 0) {
          bVar2 = true;
        }
        iVar8 = iVar8 + -1;
        puVar7 = puVar7 + -1;
      } while (0 < iVar8);
      uVar10 = local_c0[iVar8] % 10000;
      local_c0[0] = local_c0[0] / 10000;
      if (local_c0[0] != 0) {
        bVar2 = true;
      }
      pwVar6 = awStack_b0 + iVar4;
      iVar8 = 4;
      iVar4 = iVar4 + -4;
      do {
        iVar11 = (int)uVar10 % 10;
        pwVar6 = pwVar6 + -1;
        iVar8 = iVar8 + -1;
        uVar10 = (int)uVar10 / 10;
        *pwVar6 = (short)iVar11 + L'0';
      } while (iVar8 != 0);
      if (iVar4 == 0x1b) {
        iVar4 = 0x1a;
        local_7c = DAT_4046d1f0;
      }
    } while (bVar2);
    pwVar6 = awStack_b0 + iVar4;
    wVar1 = *pwVar6;
    while (wVar1 == L'0') {
      pwVar6 = pwVar6 + 1;
      iVar4 = iVar4 + 1;
      wVar1 = *pwVar6;
    }
    if ((DAT_4046d1f6 != 0) && (awStack_b0[iVar4] == DAT_4046d1f0)) {
      iVar4 = iVar4 + -1;
      awStack_b0[iVar4] = L'0';
    }
    iVar8 = 0x1e;
    if (local_76[1] == 0x30) {
      psVar5 = local_76 + 1;
      do {
        psVar5 = psVar5 + -1;
        iVar8 = iVar8 + -1;
      } while (*psVar5 == 0x30);
    }
    if (awStack_b0[iVar8] == DAT_4046d1f0) {
      if (iVar8 == iVar4) {
        iVar4 = iVar4 + -1;
        awStack_b0[iVar4] = L'0';
      }
      iVar8 = iVar8 + -1;
    }
    awStack_b0[iVar8 + 1] = L'\0';
    if (bVar3) {
      local_70 = L'-';
      _Dest = awStack_6e;
    }
    wcscpy(_Dest,awStack_b0 + iVar4);
    iVar4 = FUN_4044bad4(&local_70,pbstrOut);
  }
  FUN_4046ace8(local_20);
  return iVar4;
}



/* 40445c98 VarBstrFromI1 */

/* Boundary evidence: original MIPS .pdata 40445c98..40445cb3. Semantic name remains unreviewed. */

HRESULT VarBstrFromI1(CHAR cIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  undefined1 in_register_00000011;
  
                    /* 0x5c98  69  VarBstrFromI1 */
  HVar1 = VarBstrFromI2(CONCAT11(in_register_00000011,cIn),lcid,dwFlags,pbstrOut);
  return HVar1;
}



/* 40445cb4 VarBstrFromUI4 */

/* Boundary evidence: original MIPS .pdata 40445cb4..40445d03. Semantic name remains unreviewed. */

HRESULT VarBstrFromUI4(ULONG ulIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  OLECHAR aOStack_60 [40];
  uint local_10;
  
                    /* 0x5cb4  76  VarBstrFromUI4 */
  local_10 = DAT_4046d1b8;
  FUN_40452304(ulIn,aOStack_60);
  HVar1 = FUN_4044bad4(aOStack_60,pbstrOut);
  FUN_4046ace8(local_10);
  return HVar1;
}



/* 40445d04 VarI1FromI2 */

HRESULT VarI1FromI2(SHORT uiIn,CHAR *pcOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  
                    /* 0x5d04  122  VarI1FromI2 */
  if ((CONCAT22(in_register_00000012,uiIn) < -0x80) || (0x7f < CONCAT22(in_register_00000012,uiIn)))
  {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pcOut = (CHAR)uiIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40445d3c VarI1FromI4 */

HRESULT VarI1FromI4(LONG lIn,CHAR *pcOut)

{
  HRESULT HVar1;
  
                    /* 0x5d3c  123  VarI1FromI4 */
  if ((lIn < -0x80) || (0x7f < lIn)) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pcOut = (CHAR)lIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40445d70 VarI1FromR8 */

/* Boundary evidence: original MIPS .pdata 40445d70..40445e07. Semantic name remains unreviewed. */

HRESULT VarI1FromR8(DOUBLE dblIn,CHAR *pcOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x5d70  125  VarI1FromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0xc0601000);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0,0x405fe000), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444a84(in_a0,in_a1);
    *pcOut = (CHAR)uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40445e08 VarI1FromDate */

/* Boundary evidence: original MIPS .pdata 40445e08..40445e23. Semantic name remains unreviewed. */

HRESULT VarI1FromDate(DATE dateIn,CHAR *pcOut)

{
  HRESULT HVar1;
  
                    /* 0x5e08  119  VarI1FromDate */
  HVar1 = VarI1FromR8(dateIn,pcOut);
  return HVar1;
}



/* 40445e24 VarI1FromCy */

/* Boundary evidence: original MIPS .pdata 40445e24..40445e87. Semantic name remains unreviewed. */

HRESULT VarI1FromCy(CY cyIn,CHAR *pcOut)

{
  int iVar1;
  short local_10 [4];
  
                    /* 0x5e24  118  VarI1FromCy */
  iVar1 = FUN_40458964(cyIn.s.Lo,cyIn.s.Hi,local_10);
  if (iVar1 == 0) {
    if ((local_10[0] < -0x80) || (0x7f < local_10[0])) {
      iVar1 = -0x7ffdfff6;
    }
    else {
      *pcOut = (CHAR)local_10[0];
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40445e88 VarI1FromStr */

/* Boundary evidence: original MIPS .pdata 40445e88..40445eeb. Semantic name remains unreviewed. */

HRESULT VarI1FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,CHAR *pcOut)

{
  HRESULT HVar1;
  short local_10 [4];
  
                    /* 0x5e88  126  VarI1FromStr */
  HVar1 = VarI2FromStr(strIn,lcid,dwFlags,local_10);
  if (HVar1 == 0) {
    if ((local_10[0] < -0x80) || (0x7f < local_10[0])) {
      HVar1 = -0x7ffdfff6;
    }
    else {
      *pcOut = (CHAR)local_10[0];
      HVar1 = 0;
    }
  }
  return HVar1;
}



/* 40445eec VarI1FromBool */

HRESULT VarI1FromBool(VARIANT_BOOL boolIn,BYTE *pbOut)

{
                    /* 0x5eec  117  VarI1FromBool
                       0x5eec  184  VarUI1FromBool */
  *pbOut = (BYTE)boolIn;
  return 0;
}



/* 40445ef8 VarI1FromUI1 */

HRESULT VarI1FromUI1(ULONG ulIn,CHAR *pcOut)

{
  HRESULT HVar1;
  
                    /* 0x5ef8  127  VarI1FromUI1
                       0x5ef8  128  VarI1FromUI2
                       0x5ef8  129  VarI1FromUI4 */
  if (ulIn < 0x80) {
    *pcOut = (CHAR)ulIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 40445f20 VarUI2FromI2 */

HRESULT VarUI2FromI2(SHORT uiIn,USHORT *puiOut)

{
  HRESULT HVar1;
  short in_register_00000012;
  
                    /* 0x5f20  203  VarUI2FromI2 */
  if (in_register_00000012 < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *puiOut = uiIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40445f44 VarUI2FromI4 */

HRESULT VarUI2FromI4(LONG lIn,USHORT *puiOut)

{
  HRESULT HVar1;
  
                    /* 0x5f44  204  VarUI2FromI4
                       0x5f44  209  VarUI2FromUI4 */
  if ((uint)lIn < 0x10000) {
    *puiOut = (USHORT)lIn;
    HVar1 = 0;
  }
  else {
    HVar1 = -0x7ffdfff6;
  }
  return HVar1;
}



/* 40445f70 VarUI2FromR8 */

/* Boundary evidence: original MIPS .pdata 40445f70..40446003. Semantic name remains unreviewed. */

HRESULT VarUI2FromR8(DOUBLE dblIn,USHORT *puiOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x5f70  206  VarUI2FromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0xbfe00000);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0,0x40effff0), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444a84(in_a0,in_a1);
    *puiOut = (USHORT)uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40446004 VarUI2FromDate */

/* Boundary evidence: original MIPS .pdata 40446004..4044601f. Semantic name remains unreviewed. */

HRESULT VarUI2FromDate(DATE dateIn,USHORT *puiOut)

{
  HRESULT HVar1;
  
                    /* 0x6004  199  VarUI2FromDate */
  HVar1 = VarUI2FromR8(dateIn,puiOut);
  return HVar1;
}



/* 40446020 VarUI2FromCy */

/* Boundary evidence: original MIPS .pdata 40446020..40446077. Semantic name remains unreviewed. */

HRESULT VarUI2FromCy(CY cyIn,USHORT *puiOut)

{
  int iVar1;
  uint local_10 [2];
  
                    /* 0x6020  198  VarUI2FromCy */
  iVar1 = FUN_40458620(cyIn.s.Lo,cyIn.s.Hi,local_10);
  if (iVar1 == 0) {
    if (local_10[0] < 0x10000) {
      *puiOut = (USHORT)local_10[0];
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ffdfff6;
    }
  }
  return iVar1;
}



/* 40446078 VarUI2FromStr */

/* Boundary evidence: original MIPS .pdata 40446078..404460cf. Semantic name remains unreviewed. */

HRESULT VarUI2FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,USHORT *puiOut)

{
  HRESULT HVar1;
  uint local_10 [2];
  
                    /* 0x6078  207  VarUI2FromStr */
  HVar1 = VarI4FromStr(strIn,lcid,dwFlags,(LONG *)local_10);
  if (HVar1 == 0) {
    if (local_10[0] < 0x10000) {
      *puiOut = (USHORT)local_10[0];
      HVar1 = 0;
    }
    else {
      HVar1 = -0x7ffdfff6;
    }
  }
  return HVar1;
}



/* 404460d0 VarUI2FromI1 */

HRESULT VarUI2FromI1(CHAR cIn,USHORT *puiOut)

{
  HRESULT HVar1;
  int3 in_register_00000011;
  
                    /* 0x60d0  202  VarUI2FromI1 */
  if (in_register_00000011 < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *puiOut = (ushort)(byte)cIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 404460f8 VarUI4FromI2 */

HRESULT VarUI4FromI2(SHORT uiIn,ULONG *pulOut)

{
  HRESULT HVar1;
  short in_register_00000012;
  
                    /* 0x60f8  216  VarUI4FromI2 */
  if (in_register_00000012 < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pulOut = (uint)(ushort)uiIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40446120 VarUI4FromI4 */

HRESULT VarUI4FromI4(LONG lIn,ULONG *pulOut)

{
  HRESULT HVar1;
  
                    /* 0x6120  217  VarUI4FromI4 */
  if (lIn < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pulOut = lIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40446144 VarUI4FromR8 */

/* Boundary evidence: original MIPS .pdata 40446144..404461d7. Semantic name remains unreviewed. */

HRESULT VarUI4FromR8(DOUBLE dblIn,ULONG *pulOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x6144  219  VarUI4FromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0xbfe00000);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0xfff00000,0x41efffff), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444b44(dblIn);
    *pulOut = uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 404461d8 VarUI4FromDate */

/* Boundary evidence: original MIPS .pdata 404461d8..404461f3. Semantic name remains unreviewed. */

HRESULT VarUI4FromDate(DATE dateIn,ULONG *pulOut)

{
  HRESULT HVar1;
  
                    /* 0x61d8  212  VarUI4FromDate */
  HVar1 = VarUI4FromR8(dateIn,pulOut);
  return HVar1;
}



/* 404461f4 VarUI4FromCy */

/* Boundary evidence: original MIPS .pdata 404461f4..40446233. Semantic name remains unreviewed. */

HRESULT VarUI4FromCy(CY cyIn,ULONG *pulOut)

{
  int iVar1;
  DOUBLE in_f12_13;
  undefined8 local_10;
  
                    /* 0x61f4  211  VarUI4FromCy */
  iVar1 = FUN_40458528(cyIn.s.Lo,cyIn.s.Hi,&local_10);
  if (iVar1 == 0) {
    iVar1 = VarUI4FromR8(in_f12_13,pulOut);
  }
  return iVar1;
}



/* 40446234 VarUI4FromStr */

/* Boundary evidence: original MIPS .pdata 40446234..404462eb. Semantic name remains unreviewed. */

HRESULT VarUI4FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,ULONG *pulOut)

{
  HRESULT HVar1;
  NUMPARSE local_48;
  VARIANT VStack_30;
  BYTE aBStack_20 [12];
  uint local_14;
  
                    /* 0x6234  220  VarUI4FromStr */
  local_14 = DAT_4046d1b8;
  local_48.cDig = 0xb;
  local_48.dwInFlags = 0x1fff;
  HVar1 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_48,aBStack_20);
  if (((HVar1 == 0) || (-1 < HVar1)) &&
     ((HVar1 = VarNumFromParseNum(&local_48,aBStack_20,0x80000,&VStack_30), HVar1 == 0 ||
      (-1 < HVar1)))) {
    *pulOut = VStack_30.n1._8_4_;
    FUN_4046ace8(local_14);
    HVar1 = 0;
  }
  else {
    FUN_4046ace8(local_14);
  }
  return HVar1;
}



/* 404462ec VarUI4FromI1 */

HRESULT VarUI4FromI1(CHAR cIn,ULONG *pulOut)

{
  HRESULT HVar1;
  int3 in_register_00000011;
  
                    /* 0x62ec  215  VarUI4FromI1 */
  if (in_register_00000011 < 0) {
    HVar1 = -0x7ffdfff6;
  }
  else {
    *pulOut = (uint)(byte)cIn;
    HVar1 = 0;
  }
  return HVar1;
}



/* 40446314 FUN_40446314 */

/* Boundary evidence: original MIPS .pdata 40446314..4044665b. Semantic name remains unreviewed. */

void FUN_40446314(wchar_t *param_1,int param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  int iVar5;
  wchar_t *pwVar6;
  int iVar7;
  
  wVar1 = *param_1;
  pwVar6 = param_1;
  do {
    if (wVar1 == L'\0') {
LAB_40446384:
      if (*param_1 == L'-') {
        param_1 = param_1 + 1;
      }
      sVar3 = wcslen(param_1);
      pwVar6 = param_1 + (sVar3 - 5);
      if (((int)sVar3 < 7) || (*pwVar6 != L'e')) {
        if (param_1[sVar3 - 1] == DAT_4046d1f0) {
          param_1[sVar3 - 1] = L'\0';
        }
        if (DAT_4046d1f6 != 0) {
          return;
        }
        if (*param_1 != L'0') {
          return;
        }
        pwVar6 = param_1 + 1;
        if (*pwVar6 != DAT_4046d1f0) {
          return;
        }
      }
      else {
        if (pwVar6[1] == L'-') {
          iVar7 = sVar3 - 7;
          iVar5 = (((ushort)pwVar6[2] - 0x30) * 10 + (uint)(ushort)pwVar6[3]) * 10 +
                  (uint)(ushort)pwVar6[4] + -0x210 + iVar7;
          if (iVar5 <= param_2) {
            param_1[iVar5 + 1] = L'\0';
            pwVar6 = param_1 + (sVar3 - 6);
            pwVar4 = param_1 + iVar5 + 1;
            for (; pwVar2 = pwVar4 + -1, iVar7 != 0; iVar7 = iVar7 + -1) {
              *pwVar2 = *pwVar6;
              pwVar6 = pwVar6 + -1;
              pwVar4 = pwVar2;
            }
            *pwVar2 = *param_1;
            for (pwVar4 = pwVar4 + -2; param_1 < pwVar4; pwVar4 = pwVar4 + -1) {
              *pwVar4 = L'0';
            }
            *pwVar4 = DAT_4046d1f0;
            if (DAT_4046d1f6 != 0) {
              sVar3 = wcslen(param_1);
              memmove(param_1 + 1,param_1,(sVar3 + 1) * 2);
              *param_1 = L'0';
            }
          }
        }
        else if ((pwVar6[1] == L'+') &&
                (iVar7 = (((ushort)pwVar6[2] - 0x30) * 10 + (uint)(ushort)pwVar6[3]) * 10 +
                         (uint)(ushort)pwVar6[4] + -0x210, iVar7 == param_2 + -1)) {
          for (pwVar6 = param_1 + 2; (0x2f < (ushort)*pwVar6 && ((ushort)*pwVar6 < 0x3a));
              pwVar6 = pwVar6 + 1) {
            pwVar6[-1] = *pwVar6;
            iVar7 = iVar7 + -1;
          }
          pwVar6 = pwVar6 + -1;
          if (iVar7 != 0) {
            if (iVar7 != 0) {
              pwVar4 = pwVar6;
              do {
                *pwVar4 = L'0';
                pwVar4 = pwVar4 + 1;
              } while (pwVar4 != pwVar6 + iVar7);
            }
            pwVar6 = pwVar6 + iVar7;
          }
          *pwVar6 = L'\0';
        }
        if (*pwVar6 != L'e') {
          return;
        }
        *pwVar6 = L'E';
        if (pwVar6[2] == L'0') {
          sVar3 = wcslen(pwVar6);
          memmove(pwVar6 + 2,pwVar6 + 3,(sVar3 + 1) * 2);
        }
        param_1 = pwVar6 + -1;
        if (*param_1 != DAT_4046d1f0) {
          return;
        }
      }
      sVar3 = wcslen(pwVar6);
      memmove(param_1,pwVar6,(sVar3 + 1) * 2);
      return;
    }
    if (*pwVar6 == L'.') {
      *pwVar6 = DAT_4046d1f0;
      goto LAB_40446384;
    }
    pwVar6 = pwVar6 + 1;
    wVar1 = *pwVar6;
  } while( true );
}



/* 4044665c FUN_4044665c */

/* Boundary evidence: original MIPS .pdata 4044665c..40446697. Semantic name remains unreviewed. */

void FUN_4044665c(undefined4 param_1,LCID param_2,VARTYPE param_3,VARIANTARG *param_4)

{
  _union_2683 local_18;
  
  local_18.n2.vt = 9;
  local_18._8_4_ = param_1;
  VariantChangeTypeEx(param_4,(VARIANTARG *)&local_18.n2,param_2,0,param_3);
  return;
}



/* 40446698 VectorFromBstr */

/* Boundary evidence: original MIPS .pdata 40446698..40446723. Semantic name remains unreviewed. */

HRESULT VectorFromBstr(BSTR bstr,SAFEARRAY **ppsa)

{
  UINT _Size;
  SAFEARRAY *pSVar1;
  HRESULT HVar2;
  SAFEARRAYBOUND local_18;
  
                    /* 0x6698  231  VectorFromBstr */
  *ppsa = (SAFEARRAY *)0x0;
  local_18.lLbound = 0;
  _Size = SysStringByteLen(bstr);
  local_18.cElements = _Size;
  pSVar1 = SafeArrayCreate(0x11,1,&local_18);
  *ppsa = pSVar1;
  if (pSVar1 == (SAFEARRAY *)0x0) {
    HVar2 = -0x7ff8fff2;
  }
  else {
    if (pSVar1->pvData != (void *)0x0) {
      memcpy(pSVar1->pvData,bstr,_Size);
    }
    HVar2 = 0;
  }
  return HVar2;
}



/* 40446724 BstrFromVector */

/* Boundary evidence: original MIPS .pdata 40446724..404467ab. Semantic name remains unreviewed. */

HRESULT BstrFromVector(SAFEARRAY *psa,BSTR *pbstr)

{
  BSTR pOVar1;
  UINT len;
  
                    /* 0x6724  1  BstrFromVector */
  *pbstr = (BSTR)0x0;
  if (psa != (SAFEARRAY *)0x0) {
    if ((psa->cDims != 1) || (psa->cbElements != 1)) {
      return -0x7ffdfffb;
    }
    len = psa->rgsabound[0].cElements;
    if ((psa->pvData != (LPCSTR)0x0) && (len != 0)) {
      pOVar1 = SysAllocStringByteLen(psa->pvData,len);
      *pbstr = pOVar1;
      if (pOVar1 == (BSTR)0x0) {
        return -0x7ff8fff2;
      }
    }
  }
  return 0;
}



/* 404467ac FUN_404467ac */

/* Boundary evidence: original MIPS .pdata 404467ac..404467fb. Semantic name remains unreviewed. */

bool FUN_404467ac(uint param_1)

{
  if ((param_1 == 0x400) || (param_1 == 0)) {
    param_1 = GetUserDefaultLCID();
  }
  return (param_1 & 0xffff) == 0x411;
}



/* 404467fc FUN_404467fc */

/* Boundary evidence: original MIPS .pdata 404467fc..4044684b. Semantic name remains unreviewed. */

bool FUN_404467fc(uint param_1)

{
  if ((param_1 == 0x400) || (param_1 == 0)) {
    param_1 = GetUserDefaultLCID();
  }
  return (param_1 & 0xffff) == 0x412;
}



/* 4044684c FUN_4044684c */

/* Boundary evidence: original MIPS .pdata 4044684c..4044689b. Semantic name remains unreviewed. */

bool FUN_4044684c(uint param_1)

{
  if ((param_1 == 0x400) || (param_1 == 0)) {
    param_1 = GetUserDefaultLCID();
  }
  return (param_1 & 0xffff) == 0x404;
}



/* 4044689c FUN_4044689c */

/* Boundary evidence: original MIPS .pdata 4044689c..4044690b. Semantic name remains unreviewed. */

undefined4 FUN_4044689c(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 == 0x400) || (param_1 == 0)) {
    param_1 = GetUserDefaultLCID();
  }
  if (((param_1 & 0x3ff) != 4) || (uVar1 = 1, (param_1 & 0xfc00) == 0x400)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4044690c FUN_4044690c */

/* Boundary evidence: original MIPS .pdata 4044690c..40446983. Semantic name remains unreviewed. */

undefined4 FUN_4044690c(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((param_1 == 0x400) || (param_1 == 0)) {
    param_1 = GetUserDefaultLCID();
  }
  uVar2 = (param_1 & 0xffff) >> 10;
  if (((param_1 & 0x3ff) == 4) && ((uVar2 == 3 || (uVar2 == 5)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40446984 VarBoolFromStr */

/* Boundary evidence: original MIPS .pdata 40446984..40446b9b. Semantic name remains unreviewed. */

HRESULT VarBoolFromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,VARIANT_BOOL *pboolOut)

{
  size_t sVar1;
  int iVar2;
  VARIANT_BOOL VVar3;
  uint uVar4;
  HRESULT HVar5;
  LPCOLESTR local_30;
  undefined4 local_2c;
  
                    /* 0x6984  60  VarBoolFromStr */
  if (strIn != (LPCOLESTR)0x0) {
    HVar5 = 0;
    local_30 = strIn;
    sVar1 = wcslen(strIn);
    if (sVar1 != 0) {
      uVar4 = lcid & 0x3ff;
      if ((uVar4 == 4) || ((0x10 < uVar4 && (uVar4 < 0x13)))) {
        iVar2 = FUN_40445834(lcid,strIn,&local_30);
        strIn = local_30;
        if ((iVar2 != 0) && (iVar2 < 0)) {
          return iVar2;
        }
        sVar1 = wcslen(local_30);
      }
      iVar2 = wcscmp(strIn,L"#FALSE#");
      if (((iVar2 == 0) && (sVar1 == 7)) ||
         ((iVar2 = _wcsicmp(strIn,L"FALSE"), iVar2 == 0 && (sVar1 == 5)))) {
        *pboolOut = 0;
      }
      else {
        iVar2 = wcscmp(strIn,L"#TRUE#");
        if (((iVar2 == 0) && (sVar1 == 6)) ||
           ((iVar2 = _wcsicmp(strIn,L"TRUE"), iVar2 == 0 && (sVar1 == 4)))) {
          *pboolOut = -1;
        }
        else {
          HVar5 = VarR8FromStr(strIn,lcid,dwFlags,(DOUBLE *)&local_30);
          if (HVar5 == 0) {
            iVar2 = __ned(local_30,local_2c,0,0);
            VVar3 = -1;
            if (iVar2 == 0) {
              VVar3 = 0;
            }
            *pboolOut = VVar3;
          }
        }
      }
      if (uVar4 != 4) {
        if (uVar4 < 0x11) {
          return HVar5;
        }
        if (0x12 < uVar4) {
          return HVar5;
        }
      }
      if (strIn == (wchar_t *)0x0) {
        return HVar5;
      }
      CoTaskMemFree(strIn);
      return HVar5;
    }
  }
  return -0x7ffdfffb;
}



/* 40446b9c VarBoolFromDisp */

/* Boundary evidence: original MIPS .pdata 40446b9c..40446bf3. Semantic name remains unreviewed. */

HRESULT VarBoolFromDisp(IDispatch *pdispIn,LCID lcid,VARIANT_BOOL *pboolOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6b9c  54  VarBoolFromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,0xb);
  if (HVar1 == 0) {
    *pboolOut = VStack_18.n1._8_2_;
  }
  return HVar1;
}



/* 40446bf4 VarUI1FromR8 */

/* Boundary evidence: original MIPS .pdata 40446bf4..40446c87. Semantic name remains unreviewed. */

HRESULT VarUI1FromR8(DOUBLE dblIn,BYTE *pbOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x6bf4  193  VarUI1FromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0xbfe00000);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0,0x406ff000), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444a84(in_a0,in_a1);
    *pbOut = (BYTE)uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40446c88 VarUI1FromDate */

/* Boundary evidence: original MIPS .pdata 40446c88..40446ca3. Semantic name remains unreviewed. */

HRESULT VarUI1FromDate(DATE dateIn,BYTE *pbOut)

{
  HRESULT HVar1;
  
                    /* 0x6c88  186  VarUI1FromDate */
  HVar1 = VarUI1FromR8(dateIn,pbOut);
  return HVar1;
}



/* 40446ca4 VarUI1FromStr */

/* Boundary evidence: original MIPS .pdata 40446ca4..40446cfb. Semantic name remains unreviewed. */

HRESULT VarUI1FromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,BYTE *pbOut)

{
  HRESULT HVar1;
  ushort local_10 [4];
  
                    /* 0x6ca4  194  VarUI1FromStr */
  HVar1 = VarI2FromStr(strIn,lcid,dwFlags,(SHORT *)local_10);
  if (HVar1 == 0) {
    if (local_10[0] < 0x100) {
      *pbOut = (BYTE)local_10[0];
      HVar1 = 0;
    }
    else {
      HVar1 = -0x7ffdfff6;
    }
  }
  return HVar1;
}



/* 40446cfc VarUI1FromDisp */

/* Boundary evidence: original MIPS .pdata 40446cfc..40446d53. Semantic name remains unreviewed. */

HRESULT VarUI1FromDisp(IDispatch *pdispIn,LCID lcid,BYTE *pbOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6cfc  188  VarUI1FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,0x11);
  if (HVar1 == 0) {
    *pbOut = VStack_18.n1._8_1_;
  }
  return HVar1;
}



/* 40446d54 VarI2FromR8 */

/* Boundary evidence: original MIPS .pdata 40446d54..40446deb. Semantic name remains unreviewed. */

HRESULT VarI2FromR8(DOUBLE dblIn,SHORT *psOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x6d54  138  VarI2FromR8 */
  iVar1 = __ged(in_a0,in_a1,0,0xc0e00010);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0,0x40dfffe0), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444a84(in_a0,in_a1);
    *psOut = (SHORT)uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40446dec VarI2FromDate */

/* Boundary evidence: original MIPS .pdata 40446dec..40446e07. Semantic name remains unreviewed. */

HRESULT VarI2FromDate(DATE dateIn,SHORT *psOut)

{
  HRESULT HVar1;
  
                    /* 0x6dec  132  VarI2FromDate */
  HVar1 = VarI2FromR8(dateIn,psOut);
  return HVar1;
}



/* 40446e08 VarI2FromDisp */

/* Boundary evidence: original MIPS .pdata 40446e08..40446e5f. Semantic name remains unreviewed. */

HRESULT VarI2FromDisp(IDispatch *pdispIn,LCID lcid,SHORT *psOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6e08  134  VarI2FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,2);
  if (HVar1 == 0) {
    *psOut = VStack_18.n1._8_2_;
  }
  return HVar1;
}



/* 40446e60 VarI4FromR8 */

/* Boundary evidence: original MIPS .pdata 40446e60..40446ef3. Semantic name remains unreviewed. */

HRESULT VarI4FromR8(DOUBLE dblIn,LONG *plOut)

{
  int iVar1;
  uint uVar2;
  HRESULT HVar3;
  undefined4 in_a0;
  undefined4 in_a1;
  
                    /* 0x6e60  151  VarI4FromR8 */
  iVar1 = __ged(in_a0,in_a1,0x100000,0xc1e00000);
  if ((iVar1 == 0) || (iVar1 = __ltd(in_a0,in_a1,0xffe00000,0x41dfffff), iVar1 == 0)) {
    HVar3 = -0x7ffdfff6;
  }
  else {
    uVar2 = FUN_40444a84(in_a0,in_a1);
    *plOut = uVar2;
    HVar3 = 0;
  }
  return HVar3;
}



/* 40446ef4 VarI4FromDate */

/* Boundary evidence: original MIPS .pdata 40446ef4..40446f0f. Semantic name remains unreviewed. */

HRESULT VarI4FromDate(DATE dateIn,LONG *plOut)

{
  HRESULT HVar1;
  
                    /* 0x6ef4  145  VarI4FromDate */
  HVar1 = VarI4FromR8(dateIn,plOut);
  return HVar1;
}



/* 40446f10 VarI4FromDisp */

/* Boundary evidence: original MIPS .pdata 40446f10..40446f67. Semantic name remains unreviewed. */

HRESULT VarI4FromDisp(IDispatch *pdispIn,LCID lcid,LONG *plOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6f10  147  VarI4FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,3);
  if (HVar1 == 0) {
    *plOut = VStack_18.n1._8_4_;
  }
  return HVar1;
}



/* 40446f68 VarR4FromDisp */

/* Boundary evidence: original MIPS .pdata 40446f68..40446fbf. Semantic name remains unreviewed. */

HRESULT VarR4FromDisp(IDispatch *pdispIn,LCID lcid,FLOAT *pfltOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6f68  162  VarR4FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,4);
  if (HVar1 == 0) {
    *pfltOut = (FLOAT)VStack_18.n1._8_4_;
  }
  return HVar1;
}



/* 40446fc0 VarR8FromDisp */

/* Boundary evidence: original MIPS .pdata 40446fc0..4044701f. Semantic name remains unreviewed. */

HRESULT VarR8FromDisp(IDispatch *pdispIn,LCID lcid,DOUBLE *pdblOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x6fc0  175  VarR8FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,5);
  if (HVar1 == 0) {
    *(undefined4 *)pdblOut = VStack_18.n1._8_4_;
    *(undefined4 *)((int)pdblOut + 4) = VStack_18.n1._12_4_;
  }
  return HVar1;
}



/* 40447020 VarDateFromUI1 */

/* Boundary evidence: original MIPS .pdata 40447020..4044703b. Semantic name remains unreviewed. */

HRESULT VarDateFromUI1(BYTE bIn,DATE *pdateOut)

{
  HRESULT HVar1;
  undefined1 in_register_00000011;
  
                    /* 0x7020  100  VarDateFromUI1 */
  HVar1 = VarDateFromI2(CONCAT11(in_register_00000011,bIn),pdateOut);
  return HVar1;
}



/* 4044703c VarDateFromDisp */

/* Boundary evidence: original MIPS .pdata 4044703c..4044709b. Semantic name remains unreviewed. */

HRESULT VarDateFromDisp(IDispatch *pdispIn,LCID lcid,DATE *pdateOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x703c  93  VarDateFromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,7);
  if (HVar1 == 0) {
    *(undefined4 *)pdateOut = VStack_18.n1._8_4_;
    *(undefined4 *)((int)pdateOut + 4) = VStack_18.n1._12_4_;
  }
  return HVar1;
}



/* 4044709c VarCyFromDisp */

/* Boundary evidence: original MIPS .pdata 4044709c..404470fb. Semantic name remains unreviewed. */

HRESULT VarCyFromDisp(IDispatch *pdispIn,LCID lcid,CY *pcyOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x709c  80  VarCyFromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,6);
  if (HVar1 == 0) {
    (pcyOut->s).Lo = VStack_18.n1._8_4_;
    (pcyOut->s).Hi = VStack_18.n1._12_4_;
  }
  return HVar1;
}



/* 404470fc VarBstrFromUI1 */

/* Boundary evidence: original MIPS .pdata 404470fc..40447117. Semantic name remains unreviewed. */

HRESULT VarBstrFromUI1(BYTE bVal,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  undefined1 in_register_00000011;
  
                    /* 0x70fc  74  VarBstrFromUI1 */
  HVar1 = VarBstrFromI2(CONCAT11(in_register_00000011,bVal),lcid,dwFlags,pbstrOut);
  return HVar1;
}



/* 40447118 VarBstrFromR4 */

/* Boundary evidence: original MIPS .pdata 40447118..404471c7. Semantic name remains unreviewed. */

HRESULT VarBstrFromR4(FLOAT fltIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  int iVar1;
  undefined4 in_f13;
  undefined8 uVar2;
  WCHAR aWStack_68 [40];
  uint local_18;
  
                    /* 0x7118  72  VarBstrFromR4 */
  local_18 = DAT_4046d1b8;
  uVar2 = __fptodp();
  FUN_40452334((double)CONCAT44(in_f13,fltIn),(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),7,
               aWStack_68,0x28);
  iVar1 = FUN_404442a8(lcid,dwFlags);
  if ((iVar1 == 0) || (-1 < iVar1)) {
    FUN_40446314(aWStack_68,7);
    iVar1 = FUN_4044bad4(aWStack_68,pbstrOut);
  }
  FUN_4046ace8(local_18);
  return iVar1;
}



/* 404471c8 VarBstrFromR8 */

/* Boundary evidence: original MIPS .pdata 404471c8..40447267. Semantic name remains unreviewed. */

HRESULT VarBstrFromR8(DOUBLE dblIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  int iVar1;
  undefined4 in_a0;
  undefined4 in_a1;
  WCHAR aWStack_68 [40];
  uint local_18;
  
                    /* 0x71c8  73  VarBstrFromR8 */
  local_18 = DAT_4046d1b8;
  FUN_40452334(dblIn,in_a0,in_a1,0xf,aWStack_68,0x28);
  iVar1 = FUN_404442a8(lcid,dwFlags);
  if ((iVar1 == 0) || (-1 < iVar1)) {
    FUN_40446314(aWStack_68,0xf);
    iVar1 = FUN_4044bad4(aWStack_68,pbstrOut);
  }
  FUN_4046ace8(local_18);
  return iVar1;
}



/* 40447268 VarBstrFromDisp */

/* Boundary evidence: original MIPS .pdata 40447268..404472bf. Semantic name remains unreviewed. */

HRESULT VarBstrFromDisp(IDispatch *pdispIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x7268  68  VarBstrFromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,8);
  if (HVar1 == 0) {
    *pbstrOut = (BSTR)VStack_18.n1._8_4_;
  }
  return HVar1;
}



/* 404472c0 VarBstrFromUI2 */

/* Boundary evidence: original MIPS .pdata 404472c0..404472db. Semantic name remains unreviewed. */

HRESULT VarBstrFromUI2(USHORT uiIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  HRESULT HVar1;
  undefined2 in_register_00000012;
  
                    /* 0x72c0  75  VarBstrFromUI2 */
  HVar1 = VarBstrFromUI4(CONCAT22(in_register_00000012,uiIn),lcid,dwFlags,pbstrOut);
  return HVar1;
}



/* 404472dc VarI1FromR4 */

/* Boundary evidence: original MIPS .pdata 404472dc..4044730f. Semantic name remains unreviewed. */

HRESULT VarI1FromR4(FLOAT fltIn,CHAR *pcOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x72dc  124  VarI1FromR4 */
  __fptodp();
  HVar1 = VarI1FromR8((DOUBLE)CONCAT44(in_f13,fltIn),pcOut);
  return HVar1;
}



/* 40447310 VarI1FromDisp */

/* Boundary evidence: original MIPS .pdata 40447310..40447367. Semantic name remains unreviewed. */

HRESULT VarI1FromDisp(IDispatch *pdispIn,LCID lcid,CHAR *pcOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x7310  121  VarI1FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,0x10);
  if (HVar1 == 0) {
    *pcOut = VStack_18.n1._8_1_;
  }
  return HVar1;
}



/* 40447368 VarUI2FromR4 */

/* Boundary evidence: original MIPS .pdata 40447368..4044739b. Semantic name remains unreviewed. */

HRESULT VarUI2FromR4(FLOAT fltIn,USHORT *puiOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x7368  205  VarUI2FromR4 */
  __fptodp();
  HVar1 = VarUI2FromR8((DOUBLE)CONCAT44(in_f13,fltIn),puiOut);
  return HVar1;
}



/* 4044739c VarUI2FromDisp */

/* Boundary evidence: original MIPS .pdata 4044739c..404473f3. Semantic name remains unreviewed. */

HRESULT VarUI2FromDisp(IDispatch *pdispIn,LCID lcid,USHORT *puiOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x739c  201  VarUI2FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,0x12);
  if (HVar1 == 0) {
    *puiOut = VStack_18.n1._8_2_;
  }
  return HVar1;
}



/* 404473f4 VarUI4FromR4 */

/* Boundary evidence: original MIPS .pdata 404473f4..40447427. Semantic name remains unreviewed. */

HRESULT VarUI4FromR4(FLOAT fltIn,ULONG *pulOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x73f4  218  VarUI4FromR4 */
  __fptodp();
  HVar1 = VarUI4FromR8((DOUBLE)CONCAT44(in_f13,fltIn),pulOut);
  return HVar1;
}



/* 40447428 VarUI4FromDisp */

/* Boundary evidence: original MIPS .pdata 40447428..4044747f. Semantic name remains unreviewed. */

HRESULT VarUI4FromDisp(IDispatch *pdispIn,LCID lcid,ULONG *pulOut)

{
  HRESULT HVar1;
  _union_2683 local_28;
  VARIANTARG VStack_18;
  
                    /* 0x7428  214  VarUI4FromDisp */
  local_28.n2.vt = 9;
  local_28._8_4_ = pdispIn;
  HVar1 = VariantChangeTypeEx(&VStack_18,(VARIANTARG *)&local_28.n2,lcid,0,0x13);
  if (HVar1 == 0) {
    *pulOut = VStack_18.n1._8_4_;
  }
  return HVar1;
}



/* 40447480 VarUI1FromR4 */

/* Boundary evidence: original MIPS .pdata 40447480..404474b3. Semantic name remains unreviewed. */

HRESULT VarUI1FromR4(FLOAT fltIn,BYTE *pbOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x7480  192  VarUI1FromR4 */
  __fptodp();
  HVar1 = VarUI1FromR8((DOUBLE)CONCAT44(in_f13,fltIn),pbOut);
  return HVar1;
}



/* 404474b4 VarI2FromR4 */

/* Boundary evidence: original MIPS .pdata 404474b4..404474e7. Semantic name remains unreviewed. */

HRESULT VarI2FromR4(FLOAT fltIn,SHORT *psOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x74b4  137  VarI2FromR4 */
  __fptodp();
  HVar1 = VarI2FromR8((DOUBLE)CONCAT44(in_f13,fltIn),psOut);
  return HVar1;
}



/* 404474e8 VarI4FromR4 */

/* Boundary evidence: original MIPS .pdata 404474e8..4044751b. Semantic name remains unreviewed. */

HRESULT VarI4FromR4(FLOAT fltIn,LONG *plOut)

{
  HRESULT HVar1;
  undefined4 in_f13;
  
                    /* 0x74e8  150  VarI4FromR4 */
  __fptodp();
  HVar1 = VarI4FromR8((DOUBLE)CONCAT44(in_f13,fltIn),plOut);
  return HVar1;
}



/* 4044751c FUN_4044751c */

/* Boundary evidence: original MIPS .pdata 4044751c..4044756b. Semantic name remains unreviewed. */

void FUN_4044751c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404410f0;
  param_1[1] = &PTR_LAB_404410d0;
  SysFreeString((BSTR)param_1[7]);
  SysFreeString((BSTR)param_1[8]);
  SysFreeString((BSTR)param_1[9]);
  return;
}



/* 4044756c FUN_4044756c */

/* Boundary evidence: original MIPS .pdata 4044756c..40447587. Semantic name remains unreviewed. */

void FUN_4044756c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



/* 404475b0 FUN_404475b0 */

/* Boundary evidence: original MIPS .pdata 404475b0..404475cb. Semantic name remains unreviewed. */

void FUN_404475b0(int param_1,undefined4 *param_2)

{
  FUN_4044bb1c(*(LPCSTR *)(param_1 + 0x1c),param_2);
  return;
}



/* 404475cc FUN_404475cc */

/* Boundary evidence: original MIPS .pdata 404475cc..404475e7. Semantic name remains unreviewed. */

void FUN_404475cc(int param_1,undefined4 *param_2)

{
  FUN_4044bb1c(*(LPCSTR *)(param_1 + 0x20),param_2);
  return;
}



/* 404475e8 FUN_404475e8 */

/* Boundary evidence: original MIPS .pdata 404475e8..40447603. Semantic name remains unreviewed. */

void FUN_404475e8(int param_1,undefined4 *param_2)

{
  FUN_4044bb1c(*(LPCSTR *)(param_1 + 0x24),param_2);
  return;
}



/* 4044763c FUN_4044763c */

/* Boundary evidence: original MIPS .pdata 4044763c..4044767f. Semantic name remains unreviewed. */

void FUN_4044763c(int param_1,OLECHAR *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x18);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  FUN_4044bad4(param_2,puVar1);
  return;
}



/* 40447680 FUN_40447680 */

/* Boundary evidence: original MIPS .pdata 40447680..404476c3. Semantic name remains unreviewed. */

void FUN_40447680(int param_1,OLECHAR *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x1c);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  FUN_4044bad4(param_2,puVar1);
  return;
}



/* 404476c4 FUN_404476c4 */

/* Boundary evidence: original MIPS .pdata 404476c4..40447707. Semantic name remains unreviewed. */

void FUN_404476c4(int param_1,OLECHAR *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x20);
  SysFreeString((BSTR)*puVar1);
  *puVar1 = 0;
  FUN_4044bad4(param_2,puVar1);
  return;
}



/* 40447728 FUN_40447728 */

/* Boundary evidence: original MIPS .pdata 40447728..40447783. Semantic name remains unreviewed. */

int FUN_40447728(undefined4 *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  pvVar1 = TlsGetValue(DAT_4046d1b0);
  *param_1 = pvVar1;
  if (pvVar1 == (LPVOID)0x0) {
    iVar2 = FUN_40457730();
    if (iVar2 < 0) {
      return iVar2;
    }
    pvVar1 = TlsGetValue(DAT_4046d1b0);
    *param_1 = pvVar1;
  }
  return 0;
}



/* 40447784 FUN_40447784 */

/* Boundary evidence: original MIPS .pdata 40447784..40447857. Semantic name remains unreviewed. */

undefined4 FUN_40447784(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  iVar1 = memcmp(param_2,&DAT_40443ebc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40443eac,0x10), iVar1 == 0)) {
    *param_3 = param_1;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40443e9c,0x10);
    if (iVar1 != 0) {
      return 0x80004002;
    }
    iVar1 = param_1 + 4;
    if (param_1 == 0) {
      iVar1 = 0;
    }
    *param_3 = iVar1;
  }
  if ((int *)*param_3 == (int *)0x0) {
    return 0x80004002;
  }
  (**(code **)(*(int *)*param_3 + 4))();
  return 0;
}



/* 40447858 SetErrorInfo */

/* Boundary evidence: original MIPS .pdata 40447858..404478cf. Semantic name remains unreviewed. */

HRESULT SetErrorInfo(ULONG dwReserved,IErrorInfo *perrinfo)

{
  int iVar1;
  int *local_18 [2];
  
                    /* 0x7858  41  SetErrorInfo */
  iVar1 = FUN_40447728(local_18);
  if (-1 < iVar1) {
    if ((int *)*local_18[0] != (int *)0x0) {
      (**(code **)(*(int *)*local_18[0] + 8))();
    }
    *local_18[0] = (int)perrinfo;
    if (perrinfo != (IErrorInfo *)0x0) {
      (*perrinfo->lpVtbl->AddRef)(perrinfo);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 404478d0 GetErrorInfo */

/* Boundary evidence: original MIPS .pdata 404478d0..4044791f. Semantic name remains unreviewed. */

HRESULT GetErrorInfo(ULONG dwReserved,IErrorInfo **pperrinfo)

{
  int iVar1;
  IErrorInfo *pIVar2;
  undefined4 *local_10 [2];
  
                    /* 0x78d0  13  GetErrorInfo */
  iVar1 = FUN_40447728(local_10);
  if (-1 < iVar1) {
    pIVar2 = (IErrorInfo *)*local_10[0];
    *pperrinfo = pIVar2;
    if (pIVar2 == (IErrorInfo *)0x0) {
      iVar1 = 1;
    }
    else {
      *local_10[0] = 0;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40447934 FUN_40447934 */

/* Boundary evidence: original MIPS .pdata 40447934..404479e3. Semantic name remains unreviewed. */

undefined4 FUN_40447934(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_404589c4(0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_404410f0;
    puVar1[1] = &PTR_LAB_404410d0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    puVar1[2] = 1;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 404479e4 FUN_404479e4 */

/* Boundary evidence: original MIPS .pdata 404479e4..40447a3b. Semantic name remains unreviewed. */

LONG FUN_404479e4(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4044751c(param_1);
    FUN_40458abc(param_1);
  }
  return LVar1;
}



/* 40447a3c CreateErrorInfo */

/* Boundary evidence: original MIPS .pdata 40447a3c..40447a93. Semantic name remains unreviewed. */

HRESULT CreateErrorInfo(ICreateErrorInfo **pperrinfo)

{
  int iVar1;
  ICreateErrorInfo *pIVar2;
  int local_10 [2];
  
                    /* 0x7a3c  2  CreateErrorInfo */
  iVar1 = FUN_40447934(local_10);
  if ((iVar1 == 0) || (-1 < iVar1)) {
    if (local_10[0] == 0) {
      pIVar2 = (ICreateErrorInfo *)0x0;
    }
    else {
      pIVar2 = (ICreateErrorInfo *)(local_10[0] + 4);
    }
    *pperrinfo = pIVar2;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40447aa8 CreateTypeLib2 */

/* Boundary evidence: original MIPS .pdata 40447aa8..40447b73. Semantic name remains unreviewed. */

HRESULT CreateTypeLib2(SYSKIND syskind,LPCOLESTR szFile,ICreateTypeLib2 **ppctlib)

{
  int iVar1;
  ICreateTypeLib2 *local_20 [2];
  
                    /* 0x7aa8  3  CreateTypeLib2
                       0x7aa8  16  OACreateTypeLib2 */
  if ((szFile == (LPCOLESTR)0x0) || (ppctlib == (ICreateTypeLib2 **)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *ppctlib = (ICreateTypeLib2 *)0x0;
    iVar1 = FUN_40457730();
    if (-1 < iVar1) {
      iVar1 = FUN_40459d40(1,(int *)0x0,szFile,0,(ushort)syskind,local_20);
      if (iVar1 < 0) {
        if (local_20[0] != (ICreateTypeLib2 *)0x0) {
          (*local_20[0]->lpVtbl->Release)(local_20[0]);
        }
      }
      else {
        iVar1 = 0;
        *ppctlib = local_20[0];
      }
    }
  }
  return iVar1;
}



/* 40447c70 DispCallFunc */

/* Boundary evidence: original MIPS .pdata 40447c70..404480e3. Semantic name remains unreviewed. */

HRESULT DispCallFunc(void *pvInstance,ULONG_PTR oVft,CALLCONV cc,VARTYPE vtReturn,UINT cActuals,
                    VARTYPE *prgvt,VARIANTARG **prgpvarg,VARIANT *pvargResult)

{
  UINT UVar1;
  uint uVar2;
  VARIANTARG **in_t2;
  VARTYPE *in_t3;
  VARTYPE *pVVar3;
  VARIANTARG *pVVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  code *pcVar8;
  _union_2685 _Var9;
  uint local_50 [4];
  uint local_40 [4];
  uint local_20;
  ULONG local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x7c70  4  DispCallFunc */
  pcVar8 = DispCallFunc;
  if ((vtReturn & 0x4000) != 0) {
LAB_404480b4:
    return -0x7ff8ffa9;
  }
  if (cActuals == 0) {
    puVar7 = local_50;
  }
  else {
    uVar6 = 0;
    if (pvInstance != (void *)0x0) {
      uVar6 = 4;
    }
    UVar1 = cActuals;
    pVVar3 = prgvt;
    if (((vtReturn & 0x6000) == 0) && ((&DAT_40447b98)[vtReturn] != '\0')) {
      uVar6 = uVar6 + 4;
    }
    do {
      uVar2 = 4;
      if ((*pVVar3 & 0x6000) == 0) {
        uVar2 = *pVVar3 & 0xff;
        if (0x17 < uVar2) {
          return -0x7ff8ffa9;
        }
        uVar2 = (uint)(byte)(&DAT_40447b80)[uVar2];
        if ((7 < uVar2) && ((uVar6 & 7) != 0)) {
          uVar6 = uVar6 + 4;
        }
      }
      uVar6 = uVar6 + uVar2;
      pVVar3 = pVVar3 + 1;
      UVar1 = UVar1 - 1;
    } while (UVar1 != 0);
    if ((uVar6 & 7) != 0) {
      uVar6 = uVar6 + 4;
    }
    puVar7 = (uint *)((int)local_40 - uVar6);
    pcVar8 = (code *)(prgpvarg + (cActuals - 1));
    in_t2 = prgpvarg;
    in_t3 = prgvt;
  }
  puVar5 = puVar7;
  if (pvInstance != (void *)0x0) {
    *puVar7 = (uint)pvInstance;
    puVar5 = puVar7 + 1;
  }
  if (((vtReturn & 0x6000) == 0) && ((&DAT_40447b98)[vtReturn] != '\0')) {
    *puVar5 = (uint)&local_20;
    puVar5 = puVar5 + 1;
  }
  if (cActuals != 0) {
    do {
      pVVar4 = *in_t2;
      if ((*in_t3 & 0x6000) == 0) {
        switch(*in_t3 & 0xff) {
        case 0:
          break;
        case 1:
        case 3:
        case 4:
        case 8:
        case 9:
        case 10:
        case 0xd:
        case 0x13:
        case 0x16:
        case 0x17:
          goto switchD_40447e40_caseD_1;
        case 2:
        case 0xb:
          *puVar5 = (int)*(short *)((int)&pVVar4->n1 + 8);
          puVar5 = puVar5 + 1;
          break;
        case 5:
        case 7:
          if (((uint)puVar5 & 7) != 0) {
            puVar5 = puVar5 + 1;
          }
          *puVar5 = *(uint *)((int)&pVVar4->n1 + 8);
          puVar5[1] = *(uint *)((int)&pVVar4->n1 + 0xc);
          puVar5 = puVar5 + 2;
          break;
        case 6:
          if (((uint)puVar5 & 7) != 0) {
            puVar5 = puVar5 + 1;
          }
          *puVar5 = *(uint *)((int)&pVVar4->n1 + 8);
          puVar5[1] = *(uint *)((int)&pVVar4->n1 + 0xc);
          puVar5 = puVar5 + 2;
          break;
        case 0xc:
        case 0xe:
          if (((uint)puVar5 & 7) != 0) {
            puVar5 = puVar5 + 1;
          }
          *puVar5 = *(uint *)&pVVar4->n1;
          puVar5[1] = (pVVar4->n1).decVal.Hi32;
          puVar5[2] = *(uint *)((int)&pVVar4->n1 + 8);
          puVar5[3] = *(uint *)((int)&pVVar4->n1 + 0xc);
          puVar5 = puVar5 + 4;
          break;
        default:
          goto LAB_404480b4;
        case 0x10:
          *puVar5 = (int)*(char *)((int)&pVVar4->n1 + 8);
          puVar5 = puVar5 + 1;
          break;
        case 0x11:
          *puVar5 = (uint)*(byte *)((int)&pVVar4->n1 + 8);
          puVar5 = puVar5 + 1;
          break;
        case 0x12:
          *puVar5 = (uint)*(ushort *)((int)&pVVar4->n1 + 8);
          puVar5 = puVar5 + 1;
        }
      }
      else {
switchD_40447e40_caseD_1:
        *puVar5 = *(uint *)((int)&pVVar4->n1 + 8);
        puVar5 = puVar5 + 1;
      }
      in_t2 = in_t2 + 1;
      in_t3 = in_t3 + 1;
    } while ((int)in_t2 <= (int)pcVar8);
  }
  if (pvInstance != (void *)0x0) {
    oVft = *(undefined4 *)(*(int *)pvInstance + oVft);
  }
  _Var9.llVal = (LONGLONG)(*(code *)oVft)(*puVar7,puVar7[1],puVar7[2],puVar7[3]);
  (pvargResult->n1).n2.vt = vtReturn;
  if ((vtReturn & 0x6000) != 0) {
switchD_4044800c_caseD_1:
    *(LONG *)((int)&pvargResult->n1 + 8) = _Var9.lVal;
    return 0;
  }
  switch(vtReturn & 0xff) {
  case 0:
    break;
  case 1:
  case 3:
  case 8:
  case 9:
  case 10:
  case 0xd:
  case 0x13:
  case 0x16:
  case 0x17:
    goto switchD_4044800c_caseD_1;
  case 2:
  case 0xb:
  case 0x10:
  case 0x11:
  case 0x12:
    *(SHORT *)((int)&pvargResult->n1 + 8) = _Var9.iVal;
    break;
  case 4:
    *(LONG *)((int)&pvargResult->n1 + 8) = _Var9.lVal;
    break;
  case 5:
  case 7:
    (pvargResult->n1).n2.n3 = _Var9;
    break;
  case 6:
    *(uint *)((int)&pvargResult->n1 + 8) = local_20;
    *(ULONG *)((int)&pvargResult->n1 + 0xc) = local_1c;
    break;
  case 0xc:
    goto LAB_4044803c;
  case 0xe:
    local_20 = local_20 & 0xffff0000 | 0xe;
LAB_4044803c:
    *(uint *)&pvargResult->n1 = local_20;
    (pvargResult->n1).decVal.Hi32 = local_1c;
    *(undefined4 *)((int)&pvargResult->n1 + 8) = local_18;
    *(undefined4 *)((int)&pvargResult->n1 + 0xc) = local_14;
    break;
  default:
    goto LAB_404480b4;
  }
  return 0;
}



/* 404480e4 FUN_404480e4 */

undefined4 FUN_404480e4(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0xc);
  iVar2 = 0;
  if (0 < iVar4) {
    piVar3 = *(int **)(param_1 + 4);
    do {
      if (*piVar3 == param_2) goto LAB_40448134;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar4);
  }
  iVar2 = (*(int *)(param_1 + 8) - param_2) + -1;
  if (iVar2 < iVar4) {
    uVar1 = 0x80020004;
  }
  else {
LAB_40448134:
    *param_3 = iVar2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40448144 DispGetParam */

/* Boundary evidence: original MIPS .pdata 40448144..404481d7. Semantic name remains unreviewed. */

HRESULT DispGetParam(DISPPARAMS *pdispparams,UINT position,VARTYPE vtTarg,VARIANT *pvarResult,
                    UINT *puArgErr)

{
  int iVar1;
  UINT local_20 [2];
  
                    /* 0x8144  6  DispGetParam */
  iVar1 = FUN_404480e4((int)pdispparams,position,(int *)local_20);
  if ((iVar1 == 0) || (-1 < iVar1)) {
    iVar1 = VariantChangeType(pvarResult,pdispparams->rgvarg + local_20[0],0,vtTarg);
    if ((iVar1 != 0) && (puArgErr != (UINT *)0x0)) {
      *puArgErr = local_20[0];
    }
  }
  return iVar1;
}



/* 404481d8 DispGetIDsOfNames */

/* Boundary evidence: original MIPS .pdata 404481d8..404481fb. Semantic name remains unreviewed. */

HRESULT DispGetIDsOfNames(ITypeInfo *ptinfo,OLECHAR **rgszNames,UINT cNames,DISPID *rgdispid)

{
  HRESULT HVar1;
  
                    /* 0x81d8  5  DispGetIDsOfNames */
  HVar1 = (*ptinfo->lpVtbl->GetIDsOfNames)(ptinfo,rgszNames,cNames,rgdispid);
  return HVar1;
}



/* 404481fc DispInvoke */

/* Boundary evidence: original MIPS .pdata 404481fc..40448247. Semantic name remains unreviewed. */

HRESULT DispInvoke(void *_this,ITypeInfo *ptinfo,DISPID dispidMember,WORD wFlags,DISPPARAMS *pparams
                  ,VARIANT *pvarResult,EXCEPINFO *pexcepinfo,UINT *puArgErr)

{
  HRESULT HVar1;
  
                    /* 0x81fc  7  DispInvoke */
  HVar1 = (*ptinfo->lpVtbl->Invoke)
                    (ptinfo,_this,dispidMember,wFlags,pparams,pvarResult,pexcepinfo,puArgErr);
  return HVar1;
}



/* 40448248 FreePropVariantArray */

/* Boundary evidence: original MIPS .pdata 40448248..404482f3. Semantic name remains unreviewed. */

HRESULT FreePropVariantArray(ULONG cVariants,PROPVARIANT *rgvars)

{
  BOOL BVar1;
  HRESULT HVar2;
  HRESULT HVar3;
  
                    /* 0x8248  12  FreePropVariantArray */
  HVar3 = 0;
  BVar1 = IsBadWritePtr(rgvars,cVariants << 4);
  if (BVar1 == 0) {
    if ((rgvars != (PROPVARIANT *)0x0) && (cVariants != 0)) {
      do {
        HVar2 = PropVariantClear(rgvars);
        if (HVar2 == -0x7ffcffa9) {
          HVar3 = -0x7ffcffa9;
        }
        rgvars = rgvars + 0x10;
        cVariants = cVariants - 1;
      } while (cVariants != 0);
    }
  }
  else {
    HVar3 = -0x7ff8ffa9;
  }
  return HVar3;
}



/* 404482f4 FUN_404482f4 */

/* Boundary evidence: original MIPS .pdata 404482f4..4044837f. Semantic name remains unreviewed. */

LPVOID FUN_404482f4(size_t param_1,void *param_2,undefined4 *param_3)

{
  LPVOID _Dst;
  
  _Dst = CoTaskMemAlloc(param_1);
  if (_Dst == (LPVOID)0x0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x80030008;
    }
  }
  else {
    memcpy(_Dst,param_2,param_1);
  }
  return _Dst;
}



/* 40448380 FUN_40448380 */

undefined1 FUN_40448380(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  
  if ((param_2 < 0) || (0x1f < param_2)) {
    if ((param_2 < 0x40) || (0x49 < param_2)) {
      uVar1 = 8;
      if (param_2 != 0xfff) {
        uVar1 = 0x20;
      }
    }
    else {
      uVar1 = *(undefined1 *)((int)&PTR_FUN_404410f0 + param_2);
    }
  }
  else {
    uVar1 = (&DAT_40441110)[param_2];
  }
  return uVar1;
}



/* 404483ec PropVariantClear */

/* Boundary evidence: original MIPS .pdata 404483ec..404488b3. Semantic name remains unreviewed. */

HRESULT PropVariantClear(PROPVARIANT *pvar)

{
  ushort uVar1;
  BOOL BVar2;
  LPVOID pvVar3;
  ushort uVar4;
  HRESULT HVar5;
  int iVar6;
  uint uVar7;
  
                    /* 0x83ec  17  PropVariantClear */
  HVar5 = 0;
  if (pvar == (PROPVARIANT *)0x0) {
    return 0;
  }
  BVar2 = IsBadWritePtr(pvar,0x10);
  if (BVar2 != 0) {
    return -0x7ff8ffa9;
  }
  uVar1 = *(ushort *)pvar;
  if (0x48 < uVar1) {
    if (uVar1 < 0x1016) {
      if (uVar1 < 0x1010) {
        if (uVar1 < 0x1009) {
          if (uVar1 == 0x1008) {
            if ((*(int *)(pvar + 0xc) != 0) && (uVar7 = 0, *(int *)(pvar + 8) != 0)) {
              iVar6 = 0;
              do {
                if (*(BSTR *)(iVar6 + *(int *)(pvar + 0xc)) != (BSTR)0x0) {
                  SysFreeString(*(BSTR *)(iVar6 + *(int *)(pvar + 0xc)));
                }
                uVar7 = uVar7 + 1;
                iVar6 = iVar6 + 4;
              } while (uVar7 < *(uint *)(pvar + 8));
            }
          }
          else {
            if (uVar1 == 0x49) {
              if (*(int *)(pvar + 8) == 0) goto LAB_404484f0;
              if (*(int *)(*(int *)(pvar + 8) + 0x10) != 0) {
                (**(code **)(**(int **)(*(int *)(pvar + 8) + 0x10) + 8))();
              }
              goto LAB_404486c0;
            }
            if (uVar1 == 0xfff) {
              pvVar3 = *(LPVOID *)(pvar + 0xc);
              if (pvVar3 == (LPVOID)0x0) goto LAB_404484f0;
              goto LAB_40448680;
            }
            if ((uVar1 < 0x1002) || (0x1007 < uVar1)) goto LAB_404484cc;
          }
        }
        else {
          if (uVar1 < 0x100a) goto LAB_404484cc;
          if (0x100b < uVar1) {
            if (uVar1 != 0x100c) goto LAB_404484cc;
            if (*(PROPVARIANT **)(pvar + 0xc) != (PROPVARIANT *)0x0) {
              HVar5 = FreePropVariantArray(*(ULONG *)(pvar + 8),*(PROPVARIANT **)(pvar + 0xc));
            }
          }
        }
      }
    }
    else {
      if (uVar1 < 0x101e) goto LAB_404484cc;
      if (uVar1 < 0x1020) {
        if ((*(int *)(pvar + 0xc) != 0) && (uVar7 = 0, *(int *)(pvar + 8) != 0)) {
          iVar6 = 0;
          do {
            CoTaskMemFree(*(LPVOID *)(iVar6 + *(int *)(pvar + 0xc)));
            uVar7 = uVar7 + 1;
            iVar6 = iVar6 + 4;
          } while (uVar7 < *(uint *)(pvar + 8));
        }
      }
      else if (uVar1 != 0x1040) {
        if (uVar1 == 0x1047) {
          if ((*(int *)(pvar + 0xc) != 0) && (uVar7 = 0, *(int *)(pvar + 8) != 0)) {
            iVar6 = 0;
            do {
              CoTaskMemFree(*(LPVOID *)(iVar6 + *(int *)(pvar + 0xc) + 8));
              uVar7 = uVar7 + 1;
              iVar6 = iVar6 + 0xc;
            } while (uVar7 < *(uint *)(pvar + 8));
          }
        }
        else if (uVar1 != 0x1048) {
          if (uVar1 != 0x1fff) {
            uVar4 = 0xffff;
            goto LAB_404487a8;
          }
          if ((*(int *)(pvar + 0xc) != 0) && (uVar7 = 0, *(int *)(pvar + 8) != 0)) {
            iVar6 = 0;
            do {
              pvVar3 = *(LPVOID *)(iVar6 + *(int *)(pvar + 0xc) + 4);
              if (pvVar3 != (LPVOID)0x0) {
                CoTaskMemFree(pvVar3);
              }
              uVar7 = uVar7 + 1;
              iVar6 = iVar6 + 8;
            } while (uVar7 < *(uint *)(pvar + 8));
          }
        }
      }
    }
    CoTaskMemFree(*(LPVOID *)(pvar + 0xc));
    goto LAB_404484f0;
  }
  if (uVar1 == 0x48) {
LAB_404486c0:
    pvVar3 = *(LPVOID *)(pvar + 8);
LAB_40448680:
    CoTaskMemFree(pvVar3);
  }
  else {
    if (uVar1 < 0x42) {
      if (uVar1 == 0x41) {
LAB_404485d4:
        pvVar3 = *(LPVOID *)(pvar + 0xc);
        goto LAB_40448680;
      }
      if (uVar1 < 0x16) {
        if ((0xf < uVar1) || (uVar1 < 8)) goto LAB_404484f0;
        if (uVar1 == 8) {
          if (*(BSTR *)(pvar + 8) != (BSTR)0x0) {
            SysFreeString(*(BSTR *)(pvar + 8));
          }
          goto LAB_404484f0;
        }
        if ((9 < uVar1) && (uVar1 < 0xc)) goto LAB_404484f0;
      }
      else if (0x1d < uVar1) {
        if (uVar1 < 0x20) goto LAB_404486c0;
        uVar4 = 0x40;
LAB_404487a8:
        if (uVar1 == uVar4) goto LAB_404484f0;
      }
    }
    else {
      if ((((uVar1 == 0x42) || (uVar1 == 0x43)) || (uVar1 == 0x44)) || (uVar1 == 0x45)) {
        if (*(int **)(pvar + 8) != (int *)0x0) {
          (**(code **)(**(int **)(pvar + 8) + 8))();
        }
        goto LAB_404484f0;
      }
      if (uVar1 == 0x46) goto LAB_404485d4;
      if (uVar1 == 0x47) {
        if (*(int *)(pvar + 8) == 0) goto LAB_404484f0;
        CoTaskMemFree(*(LPVOID *)(*(int *)(pvar + 8) + 8));
        pvVar3 = *(LPVOID *)(pvar + 8);
        goto LAB_40448680;
      }
    }
LAB_404484cc:
    HVar5 = VariantClear((VARIANTARG *)pvar);
    if (HVar5 == -0x7ffdfff8) {
      HVar5 = -0x7ffcffa9;
    }
  }
LAB_404484f0:
  memset(pvar,0,0x10);
  return HVar5;
}



/* 404488b4 PropVariantCopy */

/* Boundary evidence: original MIPS .pdata 404488b4..40449213. Semantic name remains unreviewed. */

HRESULT PropVariantCopy(PROPVARIANT *pvarDest,PROPVARIANT *pvarSrc)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  BOOL BVar4;
  size_t sVar5;
  LPVOID pvVar6;
  int iVar7;
  char *_Str;
  void *pvVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 uVar12;
  int iVar13;
  wchar_t *pwVar14;
  uint uVar15;
  BSTR pOVar16;
  int local_40 [2];
  _union_2683 local_38;
  
                    /* 0x88b4  18  PropVariantCopy */
  iVar13 = 0;
  local_40[0] = 0;
  BVar4 = IsBadReadPtr(pvarSrc,0x10);
  if ((BVar4 != 0) || (BVar4 = IsBadWritePtr(pvarDest,0x10), BVar4 != 0)) {
    return -0x7ff8ffa9;
  }
  local_38._0_4_ = *(undefined4 *)pvarSrc;
  local_38.decVal.Hi32 = *(undefined4 *)(pvarSrc + 4);
  uVar1 = *(ushort *)pvarSrc;
  uVar15 = (uint)uVar1;
  local_38._12_4_ = *(undefined4 *)(pvarSrc + 0xc);
  uVar12 = *(undefined4 *)(pvarSrc + 8);
  local_38._8_4_ = uVar12;
  bVar3 = FUN_40448380(&DAT_4046d1c8,uVar15 & 0xffffefff);
  if ((bVar3 & 0x20) != 0) {
    memset(&local_38,0,0x10);
    iVar13 = VariantCopy((VARIANTARG *)&local_38.n2,(VARIANTARG *)pvarSrc);
    goto LAB_4044916c;
  }
  if ((uVar1 & 0x1000) == 0) {
    if ((bVar3 & 0x40) != 0) goto LAB_404491c4;
    pOVar16 = (BSTR)0xffffffff;
    if (uVar15 < 0x45) {
      if (uVar15 == 0x44) {
LAB_40448abc:
        if ((BSTR)uVar12 != (BSTR)0x0) {
          (**(code **)(*(int *)uVar12 + 4))(uVar12);
          uVar12 = local_38._8_4_;
        }
        goto LAB_404491c4;
      }
      if (uVar15 == 8) {
        if (*(OLECHAR **)(pvarSrc + 8) == (OLECHAR *)0x0) goto LAB_404491c4;
        pOVar16 = SysAllocString(*(OLECHAR **)(pvarSrc + 8));
        local_38._8_4_ = pOVar16;
        goto LAB_40448a38;
      }
      if (uVar15 == 0x1e) {
        pwVar14 = *(wchar_t **)(pvarSrc + 8);
        if (pwVar14 == (wchar_t *)0x0) goto LAB_404491c4;
        sVar5 = strlen((char *)pwVar14);
        sVar5 = sVar5 + 1;
      }
      else {
        if (uVar15 != 0x1f) {
          if (uVar15 == 0x41) goto LAB_40448c84;
          if (uVar15 != 0x42) {
            if (uVar15 != 0x43) goto LAB_40448b24;
            goto LAB_40448a1c;
          }
          goto LAB_40448abc;
        }
        pwVar14 = *(wchar_t **)(pvarSrc + 8);
        if (pwVar14 == (wchar_t *)0x0) goto LAB_404491c4;
        sVar5 = wcslen(pwVar14);
        sVar5 = (sVar5 + 1) * 2;
      }
LAB_40448a6c:
      pOVar16 = FUN_404482f4(sVar5,pwVar14,(undefined4 *)0x0);
      local_38._8_4_ = pOVar16;
    }
    else if (uVar15 == 0x45) {
LAB_40448a1c:
      if ((BSTR)uVar12 == (BSTR)0x0) goto LAB_404491c4;
      (**(code **)(*(int *)uVar12 + 4))(uVar12);
    }
    else if (uVar15 == 0x46) {
LAB_40448c84:
      pvVar8 = *(void **)(pvarSrc + 0xc);
      if (pvVar8 == (void *)0x0) {
        if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
        goto LAB_40448b24;
      }
      uVar12 = *(undefined4 *)(pvarSrc + 8);
LAB_40448b40:
      pOVar16 = FUN_404482f4(uVar12,pvVar8,(undefined4 *)0x0);
      local_38._12_4_ = pOVar16;
    }
    else {
      if (uVar15 != 0x47) {
        if (uVar15 == 0x48) {
          pwVar14 = *(wchar_t **)(pvarSrc + 8);
          if (pwVar14 == (wchar_t *)0x0) goto LAB_404491c4;
          sVar5 = 0x10;
          goto LAB_40448a6c;
        }
        if (uVar15 != 0x49) {
          if (uVar15 != 0xfff) goto LAB_40448b24;
          pvVar8 = *(void **)(pvarSrc + 0xc);
          if (pvVar8 == (void *)0x0) goto LAB_404491c4;
          goto LAB_40448b40;
        }
        if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
        uVar12 = CoTaskMemAlloc(0x14);
        if ((BSTR)uVar12 != (BSTR)0x0) {
          puVar10 = *(undefined4 **)(pvarSrc + 8);
          *(undefined4 *)uVar12 = *puVar10;
          *(undefined4 *)(uVar12 + 4) = puVar10[1];
          *(undefined4 *)(uVar12 + 8) = puVar10[2];
          *(undefined4 *)(uVar12 + 0xc) = puVar10[3];
          piVar11 = (int *)puVar10[4];
          *(int **)(uVar12 + 0x10) = piVar11;
          if (piVar11 != (int *)0x0) {
            (**(code **)(*piVar11 + 4))();
          }
          goto LAB_404491c4;
        }
        iVar13 = -0x7ff8fff2;
        goto LAB_40449184;
      }
      if (*(void **)(pvarSrc + 8) == (void *)0x0) goto LAB_404491c4;
      pOVar16 = FUN_404482f4(0xc,*(void **)(pvarSrc + 8),(undefined4 *)0x0);
      local_38._8_4_ = pOVar16;
      if (pOVar16 == (BSTR)0x0) goto LAB_40448a40;
      pOVar16[4] = L'\0';
      pOVar16[5] = L'\0';
      if ((*(int **)(pvarSrc + 8))[2] == 0) {
        if (**(int **)(pvarSrc + 8) != 4) {
          iVar13 = -0x7ffcffa9;
          CoTaskMemFree(pOVar16);
          local_38._8_4_ = (BSTR)0x0;
          goto LAB_40449184;
        }
      }
      else {
        pvVar6 = FUN_404482f4(**(int **)(pvarSrc + 8) - 4,(void *)(*(int **)(pvarSrc + 8))[2],
                              (undefined4 *)0x0);
        *(LPVOID *)(local_38._8_4_ + 8) = pvVar6;
        pOVar16 = *(BSTR *)(local_38._8_4_ + 8);
      }
    }
LAB_40448a38:
    uVar12 = local_38._8_4_;
    if (pOVar16 != (BSTR)0x0) goto LAB_404491c4;
LAB_40448a40:
    iVar13 = -0x7ffcfff8;
LAB_40449184:
    iVar7 = memcmp(&local_38,pvarSrc,0x10);
    if (iVar7 == 0) {
      memset(&local_38,0,0x10);
    }
    else {
      PropVariantClear((PROPVARIANT *)&local_38.n2);
    }
  }
  else {
    if ((bVar3 & 0x1f) == 0) {
LAB_40448b24:
      iVar13 = -0x7ffcffa9;
      goto LAB_40449184;
    }
    if ((*(void **)(pvarSrc + 0xc) == (void *)0x0) || (*(int *)(pvarSrc + 8) == 0))
    goto LAB_404491c4;
    pOVar16 = FUN_404482f4(*(int *)(pvarSrc + 8) * (bVar3 & 0x1f),*(void **)(pvarSrc + 0xc),
                           (undefined4 *)0x0);
    local_38._12_4_ = pOVar16;
    if (pOVar16 == (BSTR)0x0) goto LAB_40448a40;
    uVar12 = local_38._8_4_;
    if ((bVar3 & 0x80) != 0) goto LAB_404491c4;
    uVar1 = *(ushort *)pvarSrc;
    if (uVar1 != 0x1008) {
      if (uVar1 == 0x100c) {
        uVar15 = 0;
        if (*(int *)(pvarSrc + 8) != 0) {
          iVar7 = 0;
          do {
            *(undefined2 *)(iVar7 + (int)pOVar16) = 0xffff;
            uVar15 = uVar15 + 1;
            iVar7 = iVar7 + 0x10;
          } while (uVar15 < *(uint *)(pvarSrc + 8));
        }
        goto LAB_40448e7c;
      }
      if (0x101d < uVar1) {
        if (uVar1 < 0x1020) {
          uVar15 = 0;
          if (*(int *)(pvarSrc + 8) != 0) {
            iVar7 = 0;
            do {
              *(undefined4 *)(iVar7 + (int)pOVar16) = 0;
              uVar15 = uVar15 + 1;
              iVar7 = iVar7 + 4;
            } while (uVar15 < *(uint *)(pvarSrc + 8));
          }
        }
        else if (uVar1 == 0x1047) {
          uVar15 = 0;
          if (*(int *)(pvarSrc + 8) != 0) {
            iVar7 = 0;
            do {
              *(undefined4 *)((int)pOVar16 + iVar7 + 8) = 0;
              uVar15 = uVar15 + 1;
              iVar7 = iVar7 + 0xc;
            } while (uVar15 < *(uint *)(pvarSrc + 8));
          }
        }
        else {
          if (uVar1 != 0x1fff) goto LAB_40448df8;
          uVar15 = 0;
          if (*(int *)(pvarSrc + 8) != 0) {
            iVar7 = 0;
            do {
              memset((void *)(iVar7 + local_38._12_4_),0,8);
              uVar15 = uVar15 + 1;
              iVar7 = iVar7 + 8;
            } while (uVar15 < *(uint *)(pvarSrc + 8));
          }
        }
        goto LAB_40448e7c;
      }
LAB_40448df8:
      CoTaskMemFree(pOVar16);
      goto LAB_40448b24;
    }
    uVar15 = 0;
    if (*(int *)(pvarSrc + 8) != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)(iVar7 + (int)pOVar16) = 0;
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 4;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
LAB_40448e7c:
    sVar2 = *(short *)pvarSrc;
    uVar12 = local_38._8_4_;
    if (sVar2 == 0x1008) {
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) != 0) {
        iVar7 = 0;
        do {
          if (*(OLECHAR **)(*(int *)(pvarSrc + 0xc) + iVar7) != (OLECHAR *)0x0) {
            pOVar16 = SysAllocString(*(OLECHAR **)(*(int *)(pvarSrc + 0xc) + iVar7));
            *(BSTR *)(iVar7 + local_38._12_4_) = pOVar16;
            if (*(int *)(iVar7 + local_38._12_4_) == 0) {
              iVar13 = -0x7ffcfff8;
              goto LAB_4044916c;
            }
          }
          uVar15 = uVar15 + 1;
          iVar7 = iVar7 + 4;
          uVar12 = local_38._8_4_;
        } while (uVar15 < *(uint *)(pvarSrc + 8));
      }
      goto LAB_404491c4;
    }
    if (sVar2 == 0x100c) {
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
      iVar7 = 0;
      do {
        iVar13 = PropVariantCopy((PROPVARIANT *)(iVar7 + local_38._12_4_),
                                 (PROPVARIANT *)(*(int *)(pvarSrc + 0xc) + iVar7));
        if (iVar13 != 0) goto LAB_40449174;
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 0x10;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
    else if (sVar2 == 0x101e) {
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
      iVar7 = 0;
      do {
        iVar9 = *(int *)(pvarSrc + 0xc);
        _Str = *(char **)(iVar9 + iVar7);
        if (_Str != (char *)0x0) {
          sVar5 = strlen(_Str);
          pvVar6 = FUN_404482f4(sVar5 + 1,*(void **)(iVar9 + iVar7),local_40);
          *(LPVOID *)(iVar7 + local_38._12_4_) = pvVar6;
          iVar13 = local_40[0];
          if (local_40[0] != 0) goto LAB_40449174;
        }
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 4;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
    else if (sVar2 == 0x101f) {
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
      iVar7 = 0;
      do {
        iVar9 = *(int *)(pvarSrc + 0xc);
        pwVar14 = *(wchar_t **)(iVar9 + iVar7);
        if (pwVar14 != (wchar_t *)0x0) {
          sVar5 = wcslen(pwVar14);
          pvVar6 = FUN_404482f4((sVar5 + 1) * 2,*(void **)(iVar9 + iVar7),local_40);
          *(LPVOID *)(iVar7 + local_38._12_4_) = pvVar6;
          iVar13 = local_40[0];
          if (local_40[0] != 0) goto LAB_40449174;
        }
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 4;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
    else if (sVar2 == 0x1047) {
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
      iVar7 = 0;
      do {
        if (((int *)(*(int *)(pvarSrc + 0xc) + iVar7))[2] == 0) {
          if (*(int *)(*(int *)(pvarSrc + 0xc) + iVar7) != 4) goto LAB_40448b24;
        }
        else {
          pvVar6 = FUN_404482f4(*(int *)(*(int *)(pvarSrc + 0xc) + iVar7) - 4,
                                (void *)((int *)(*(int *)(pvarSrc + 0xc) + iVar7))[2],local_40);
          *(LPVOID *)(iVar7 + local_38._12_4_ + 8) = pvVar6;
          iVar13 = local_40[0];
          if (local_40[0] != 0) goto LAB_40449174;
        }
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 0xc;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
    else {
      if (sVar2 != 0x1fff) goto LAB_40448df8;
      uVar15 = 0;
      if (*(int *)(pvarSrc + 8) == 0) goto LAB_404491c4;
      iVar7 = 0;
      do {
        if (*(int *)(*(int *)(pvarSrc + 0xc) + iVar7 + 4) != 0) {
          *(undefined4 *)(iVar7 + local_38._12_4_) =
               *(undefined4 *)(*(int *)(pvarSrc + 0xc) + iVar7);
          pvVar6 = FUN_404482f4(*(size_t *)(*(int *)(pvarSrc + 0xc) + iVar7),
                                (void *)((size_t *)(*(int *)(pvarSrc + 0xc) + iVar7))[1],local_40);
          *(LPVOID *)(iVar7 + local_38._12_4_ + 4) = pvVar6;
          iVar13 = local_40[0];
          if (local_40[0] != 0) goto LAB_40449174;
        }
        uVar15 = uVar15 + 1;
        iVar7 = iVar7 + 8;
      } while (uVar15 < *(uint *)(pvarSrc + 8));
    }
LAB_4044916c:
    if (iVar13 != 0) {
LAB_40449174:
      if (iVar13 != -0x7ff8ffa9) goto LAB_40449184;
    }
  }
  uVar12 = local_38._8_4_;
  if (iVar13 < 0) {
    return iVar13;
  }
LAB_404491c4:
  *(undefined4 *)pvarDest = local_38._0_4_;
  *(ULONG *)(pvarDest + 4) = local_38.decVal.Hi32;
  *(undefined4 *)(pvarDest + 8) = uVar12;
  *(undefined4 *)(pvarDest + 0xc) = local_38._12_4_;
  return iVar13;
}



/* 40449214 FUN_40449214 */

/* Boundary evidence: original MIPS .pdata 40449214..404492af. Semantic name remains unreviewed. */

undefined4 FUN_40449214(wchar_t *param_1,undefined4 *param_2,int param_3)

{
  wchar_t *_Dest;
  undefined4 uVar1;
  
  _Dest = FUN_404589c4(0x208);
  param_2[2] = _Dest;
  if (_Dest == (wchar_t *)0x0) {
    FUN_40458abc((LPVOID)0x0);
    uVar1 = 0x8007000e;
    param_2[2] = 0;
    *param_2 = 0;
    param_2[1] = 0;
  }
  else {
    if (param_3 == 0) {
      param_2[3] = 1;
    }
    else {
      wcscpy(_Dest,param_1);
    }
    param_2[7] = 1;
    uVar1 = 0;
    param_2[6] = 1;
  }
  return uVar1;
}



/* 404492b0 FUN_404492b0 */

/* Boundary evidence: original MIPS .pdata 404492b0..40449373. Semantic name remains unreviewed. */

undefined4 FUN_404492b0(wchar_t *param_1,wchar_t *param_2,int *param_3)

{
  wchar_t *pwVar1;
  uint uVar2;
  int iVar3;
  
  wcscpy(param_2,param_1);
  pwVar1 = wcsrchr(param_2,L'\\');
  if (pwVar1 != (wchar_t *)0x0) {
    *pwVar1 = L'\0';
    *param_3 = 0;
    iVar3 = 0;
    do {
      pwVar1 = pwVar1 + 1;
      uVar2 = (uint)(ushort)*pwVar1;
      if (uVar2 == 0) {
        return 1;
      }
      if (uVar2 < 0x30) {
        return 0;
      }
      if (0x39 < uVar2) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      *param_3 = *param_3 * 10 + uVar2 + -0x30;
    } while (iVar3 < 10);
  }
  return 0;
}



/* 40449374 FUN_40449374 */

/* Boundary evidence: original MIPS .pdata 40449374..4044959b. Semantic name remains unreviewed. */

DWORD FUN_40449374(wchar_t *param_1,uint param_2,int *param_3)

{
  size_t sVar1;
  DWORD DVar2;
  int iVar3;
  int local_298;
  uint local_294 [2];
  HLOCAL local_28c;
  LPVOID local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_22c;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_4046d1b8;
  if ((((param_1 != (wchar_t *)0x0) && (param_3 != (int *)0x0)) && (param_2 < 3)) &&
     (sVar1 = wcslen(param_1), sVar1 < 0x104)) {
    *param_3 = 0;
    local_288 = (LPVOID)0x0;
    local_294[1] = 0;
    local_28c = (HLOCAL)0x0;
    local_284 = 0;
    local_280 = 0;
    local_27c = 0;
    local_278 = 0;
    local_274 = 0xffffffff;
    local_270 = 1;
    local_22c = 0;
    DVar2 = FUN_40457730();
    if (-1 < (int)DVar2) {
      if (*param_1 == L'\0') {
        DVar2 = 0x80030002;
      }
      else {
        local_294[0] = 0;
        iVar3 = FUN_404492b0(param_1,awStack_228,(int *)local_294);
        if (iVar3 == 0) {
          local_28c = (HLOCAL)0x0;
        }
        else {
          local_28c = (HLOCAL)ExtractResource(awStack_228,local_294[0] & 0xffff,L"TYPELIB");
        }
        if ((local_28c == (HLOCAL)0x0) &&
           (local_28c = (HLOCAL)ExtractResource(param_1,1,L"TYPELIB"), local_28c == (HLOCAL)0x0)) {
          DVar2 = GetLastError();
          if ((int)DVar2 < 1) {
            DVar2 = GetLastError();
          }
          else {
            DVar2 = GetLastError();
            DVar2 = DVar2 & 0xffff | 0x80070000;
          }
        }
        else {
          iVar3 = FUN_40449214(param_1,local_294 + 1,0);
          if (iVar3 == 0) {
            DVar2 = FUN_40459d40(0,(int *)(local_294 + 1),param_1,0,1,&local_298);
            if (-1 < (int)DVar2) {
              iVar3 = local_298 + 4;
              if (local_298 == 0) {
                iVar3 = 0;
              }
              local_298 = 0;
              FUN_40458abc(local_288);
              *param_3 = iVar3;
              FUN_4046ace8(local_20);
              return 0;
            }
          }
          else {
            DVar2 = 0x8007000e;
            LocalFree(local_28c);
          }
        }
      }
    }
    FUN_40458abc(local_288);
    FUN_4046ace8(local_20);
    return DVar2;
  }
  FUN_4046ace8(local_20);
  return 0x80070057;
}



/* 4044959c RegisterTypeLib */

/* Boundary evidence: original MIPS .pdata 4044959c..40449847. Semantic name remains unreviewed. */

HRESULT RegisterTypeLib(ITypeLib *ptlib,LPCOLESTR szFullPath,LPCOLESTR szHelpDir)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  size_t sVar3;
  HRESULT HVar4;
  HKEY local_310;
  TLIBATTR *local_30c;
  DWORD aDStack_308 [2];
  OLECHAR aOStack_300 [40];
  wchar_t awStack_2b0 [322];
  uint local_2c;
  
                    /* 0x959c  19  RegisterTypeLib */
  local_2c = DAT_4046d1b8;
  if ((ptlib == (ITypeLib *)0x0) || (szFullPath == (LPCOLESTR)0x0)) {
    FUN_4046ace8(DAT_4046d1b8);
    HVar4 = -0x7ff8ffa9;
  }
  else {
    HVar1 = (*ptlib->lpVtbl->GetLibAttr)(ptlib,&local_30c);
    HVar4 = HVar1;
    if (-1 < HVar1) {
      if (local_30c->syskind == SYS_WIN32) {
        StringFromGUID2(&local_30c->guid,aOStack_300,0x27);
        StringCchPrintfW(awStack_2b0,0x141,L"TypeLib\\%s\\%x.%x\\%x",aOStack_300,
                         (uint)local_30c->wMajorVerNum,(uint)local_30c->wMinorVerNum,local_30c->lcid
                        );
        LVar2 = RegCreateKeyExW((HKEY)0x80000000,awStack_2b0,0,(LPWSTR)0x0,0,0xf003f,
                                (LPSECURITY_ATTRIBUTES)0x0,&local_310,aDStack_308);
        if (LVar2 == 0) {
          sVar3 = wcslen(szFullPath);
          LVar2 = RegSetValueExW(local_310,(LPCWSTR)0x0,0,1,(BYTE *)szFullPath,(sVar3 + 1) * 2);
          HVar4 = -0x7ffd7fe4;
          if (LVar2 != 0) {
            HVar1 = -0x7ffd7fe4;
          }
          RegCloseKey(local_310);
          wsprintfW(awStack_2b0,L"TypeLib\\%s\\%x.%x\\%x\\win32",aOStack_300,
                    (uint)local_30c->wMajorVerNum,(uint)local_30c->wMinorVerNum,local_30c->lcid);
          LVar2 = RegCreateKeyExW((HKEY)0x80000000,awStack_2b0,0,(LPWSTR)0x0,0,0xf003f,
                                  (LPSECURITY_ATTRIBUTES)0x0,&local_310,aDStack_308);
          if (LVar2 == 0) {
            sVar3 = wcslen(szFullPath);
            LVar2 = RegSetValueExW(local_310,(LPCWSTR)0x0,0,1,(BYTE *)szFullPath,(sVar3 + 1) * 2);
            if (LVar2 != 0) {
              HVar1 = HVar4;
            }
            RegCloseKey(local_310);
            HVar4 = HVar1;
          }
        }
        else {
          HVar4 = -0x7ffd7fe4;
        }
      }
      else {
        HVar4 = -0x7ffd7fe3;
      }
      (*ptlib->lpVtbl->ReleaseTLibAttr)(ptlib,local_30c);
    }
    FUN_4046ace8(local_2c);
  }
  return HVar4;
}



/* 40449848 FUN_40449848 */

/* Boundary evidence: original MIPS .pdata 40449848..404498d7. Semantic name remains unreviewed. */

void FUN_40449848(BSTR param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != (BSTR)0x0) {
    if ((*(int *)(param_1 + 6) != 0) && (uVar1 = 0, *(int *)param_1 != 0)) {
      iVar2 = 0;
      do {
        if (*(char *)(*(int *)(param_1 + 0xc) + uVar1) != '\0') {
          VariantClear((VARIANTARG *)(*(int *)(param_1 + 6) + iVar2));
        }
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x10;
      } while (uVar1 < *(uint *)param_1);
    }
    SysFreeString(param_1);
  }
  return;
}



/* 404498d8 FUN_404498d8 */

/* Boundary evidence: original MIPS .pdata 404498d8..40449b97. Semantic name remains unreviewed. */

HRESULT FUN_404498d8(uint *param_1)

{
  ushort uVar1;
  HRESULT HVar2;
  SAFEARRAYBOUND *pSVar3;
  int iVar4;
  SAFEARRAY *psa;
  ushort *puVar5;
  ULONG _Size;
  uint uVar6;
  SAFEARRAY *psa_00;
  VARIANTARG *pvargDest;
  int iVar7;
  uint uVar8;
  ushort uVar9;
  int iVar10;
  
  uVar8 = 0;
  if (*param_1 != 0) {
    iVar10 = 0;
    iVar7 = 0;
    do {
      puVar5 = *(ushort **)(iVar7 + param_1[5]);
      if (puVar5 != (ushort *)0x0) {
        uVar1 = *puVar5;
        pvargDest = (VARIANTARG *)(param_1[3] + iVar10);
        uVar6 = uVar1 & 0xbfff;
        if ((uVar6 != (pvargDest->n1).n2.vt) &&
           (HVar2 = VariantChangeTypeEx(pvargDest,pvargDest,0x400,0,(VARTYPE)uVar6), HVar2 != 0)) {
          return HVar2;
        }
        if ((uVar1 & 0x2000) == 0) {
          if (uVar6 == 8) {
            SysFreeString((BSTR)**(undefined4 **)(puVar5 + 4));
          }
          else if (((uVar6 == 9) || (uVar6 == 0xd)) && (**(int **)(puVar5 + 4) != 0)) {
            (**(code **)(*(int *)**(int **)(puVar5 + 4) + 8))();
          }
          memcpy(*(void **)(puVar5 + 4),(void *)((int)&pvargDest->n1 + 8),
                 (int)(char)(&DAT_40441a84)[uVar6] & 0xffff);
        }
        else {
          psa = (SAFEARRAY *)**(undefined4 **)(puVar5 + 4);
          psa_00 = *(SAFEARRAY **)((int)&pvargDest->n1 + 8);
          if (psa != (SAFEARRAY *)0x0) {
            uVar1 = psa->fFeatures;
            if ((uVar1 & 0x10) != 0) {
              uVar6 = (uint)psa->cDims;
              if ((uVar6 != psa_00->cDims) || (_Size = psa->cbElements, _Size != psa_00->cbElements)
                 ) {
                return -0x7ffdfffb;
              }
              if (uVar6 != 0) {
                pSVar3 = psa->rgsabound + (uVar6 - 1);
                uVar9 = 0;
                if (uVar6 != 0) {
                  iVar4 = ((psa_00->cDims - uVar6) * 8 - (int)psa) + (int)psa_00;
                  do {
                    if (pSVar3->cElements != *(ULONG *)(iVar4 + (int)pSVar3)) {
                      return -0x7ffdfffb;
                    }
                    if (pSVar3->lLbound != *(int *)((int)pSVar3 + iVar4 + 4)) {
                      return -0x7ffdfffb;
                    }
                    _Size = pSVar3->cElements * _Size;
                    uVar9 = uVar9 + 1;
                    pSVar3 = pSVar3 + -1;
                  } while (uVar9 < psa->cDims);
                }
                psa->fFeatures = uVar1 & 0xf00 | 2;
                SafeArrayDestroyData(psa);
                psa->fFeatures = uVar1;
                memcpy(psa->pvData,psa_00->pvData,_Size);
                psa_00->fFeatures = 0;
                SafeArrayDestroy(psa_00);
              }
              goto LAB_40449b28;
            }
            HVar2 = SafeArrayDestroy(psa);
            if (HVar2 < 0) {
              SafeArrayDestroy(psa_00);
              return HVar2;
            }
          }
          **(undefined4 **)(puVar5 + 4) = psa_00;
        }
LAB_40449b28:
        (pvargDest->n1).n2.vt = 0;
      }
      uVar8 = uVar8 + 1;
      iVar7 = iVar7 + 4;
      iVar10 = iVar10 + 0x10;
    } while (uVar8 < *param_1);
  }
  return 0;
}



/* 40449b98 FUN_40449b98 */

/* Boundary evidence: original MIPS .pdata 40449b98..4044a107. Semantic name remains unreviewed. */

HRESULT FUN_40449b98(VARIANTARG *param_1,uint param_2,int param_3,undefined *param_4,int param_5,
                    int param_6,USHORT param_7)

{
  ushort uVar1;
  VARTYPE VVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  ushort *puVar7;
  VARTYPE *pVVar8;
  VARIANTARG *pVVar9;
  HRESULT HVar10;
  ushort vt;
  
  HVar10 = 0;
  vt = (ushort)param_2;
  if (0x13 < (int)param_2) {
    if (0x15 < (int)param_2) {
      if ((int)param_2 < 0x18) goto LAB_40449d9c;
      if (param_2 == 0x2011) {
        VVar2 = (param_1->n1).n2.vt;
        if (VVar2 == 0x2011) goto LAB_40449e1c;
        if (VVar2 == 8) {
          pVVar9 = (VARIANTARG *)(*(int *)(param_5 + 0xc) + param_6 * 0x10);
          HVar10 = VariantChangeTypeEx(pVVar9,param_1,0x400,param_7,0x2011);
          *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = pVVar9;
          *(undefined1 *)(*(int *)(param_5 + 0x18) + param_6) = 1;
          return HVar10;
        }
      }
    }
LAB_40449c30:
    if ((param_2 & 0x2000) != 0) {
      *(undefined1 *)(*(int *)(param_5 + 0x18) + param_6) = 0;
    }
    if ((param_2 & 0x6000) == 0) {
      return -0x7ffdfff8;
    }
    pVVar9 = (VARIANTARG *)(*(int *)(param_5 + 0xc) + param_6 * 0x10);
    if (((param_2 == 0x400d) || (param_2 == 0x4009)) &&
       ((uVar6 = (uint)(param_1->n1).n2.vt, uVar6 == 0x400d || (uVar6 == 0x4009)))) {
      if ((param_3 == 2) && (**(int **)((int)&param_1->n1 + 8) != 0)) {
LAB_40449fec:
        puVar4 = (undefined4 *)**(undefined4 **)((int)&param_1->n1 + 8);
        iVar3 = (**(code **)*puVar4)(puVar4,param_4,(undefined1 *)((int)&pVVar9->n1 + 8));
        if (iVar3 != 0) goto LAB_40449df4;
      }
      else {
        if (uVar6 == param_2) goto LAB_4044a01c;
        if ((param_2 == 0x4009) && (**(int **)((int)&param_1->n1 + 8) != 0)) {
          param_4 = &DAT_40443edc;
          goto LAB_40449fec;
        }
        piVar5 = (int *)**(int **)((int)&param_1->n1 + 8);
        *(int **)((int)&pVVar9->n1 + 8) = piVar5;
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 4))();
        }
      }
      (pVVar9->n1).n2.vt = vt & 0xbfff;
      *(VARIANTARG **)(*(int *)(param_5 + 0x14) + param_6 * 4) = param_1;
LAB_4044a08c:
      puVar7 = (ushort *)(*(int *)(param_5 + 0x10) + param_6 * 0x10);
      *puVar7 = vt;
      if ((param_2 & 0xffffbfff) == 0xc) {
        *(VARIANTARG **)(puVar7 + 4) = pVVar9;
      }
      else {
        *(undefined1 **)(puVar7 + 4) = (undefined1 *)((int)&pVVar9->n1 + 8);
      }
      *(ushort **)(*(int *)(param_5 + 8) + param_6 * 4) = puVar7;
      return 0;
    }
    uVar1 = (param_1->n1).n2.vt;
    uVar6 = (uint)uVar1;
    if (uVar6 == param_2) {
LAB_4044a01c:
      *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = param_1;
      return 0;
    }
    if ((((uVar6 & 0x6000) == 0x6000) && ((param_2 & 0x6000) == 0x2000)) &&
       ((uVar6 & 0xffffbfff) == param_2)) {
      (pVVar9->n1).n2.vt = vt;
      *(undefined4 *)((int)&pVVar9->n1 + 8) = **(undefined4 **)((int)&param_1->n1 + 8);
      *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = pVVar9;
      *(undefined1 *)(*(int *)(param_5 + 0x18) + param_6) = 0;
      return 0;
    }
    if (((param_2 & 0x4000) != 0) && ((uVar1 & 0x4000) == 0)) {
      HVar10 = FUN_40449b98(param_1,param_2 & 0xbfff,param_3,param_4,param_5,param_6,0);
      if (HVar10 != 0) {
        return HVar10;
      }
      if (*(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) != pVVar9) {
        HVar10 = VariantCopy(pVVar9,param_1);
        if (HVar10 != 0) {
          return HVar10;
        }
        *(undefined1 *)(*(int *)(param_5 + 0x18) + param_6) = 1;
      }
      goto LAB_4044a08c;
    }
    if ((param_2 == 0x400c) && ((uVar1 & 0x4000) != 0)) {
      (pVVar9->n1).n2.vt = 0x400c;
      *(VARIANTARG **)((int)&pVVar9->n1 + 8) = param_1;
      *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = pVVar9;
      return 0;
    }
    goto LAB_40449df4;
  }
  if (0xf < (int)param_2) goto LAB_40449d9c;
  if ((int)param_2 < 2) goto LAB_40449c30;
  if ((int)param_2 < 0xc) {
LAB_40449d9c:
    if ((param_1->n1).n2.vt == param_2) {
      if ((param_3 != 2) ||
         (puVar4 = *(undefined4 **)((int)&param_1->n1 + 8), puVar4 == (undefined4 *)0x0))
      goto LAB_40449e1c;
      pVVar8 = (VARTYPE *)(*(int *)(param_5 + 0xc) + param_6 * 0x10);
      iVar3 = (**(code **)*puVar4)(puVar4,param_4,pVVar8 + 4);
      if (iVar3 == 0) {
        *pVVar8 = (param_1->n1).n2.vt;
        *(VARTYPE **)(*(int *)(param_5 + 8) + param_6 * 4) = pVVar8;
        return 0;
      }
    }
    else {
      pVVar9 = (VARIANTARG *)(*(int *)(param_5 + 0xc) + param_6 * 0x10);
      HVar10 = VariantChangeTypeEx(pVVar9,param_1,0x400,param_7,vt);
      if (HVar10 != 0) {
        if (HVar10 != -0x7ffdfffb) {
          return HVar10;
        }
        if ((param_1->n1).n2.vt != 10) {
          return -0x7ffdfffb;
        }
        if (*(int *)((int)&param_1->n1 + 8) != -0x7ffdfffc) {
          return -0x7ffdfffb;
        }
        return -0x7ffdfff1;
      }
      *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = pVVar9;
      if (param_3 != 2) {
        return 0;
      }
      piVar5 = (int *)((int)&pVVar9->n1 + 8);
      if ((int *)*piVar5 == (int *)0x0) {
        return 0;
      }
      (**(code **)(*(int *)*piVar5 + 8))();
      iVar3 = (*(code *)**(undefined4 **)*piVar5)((undefined4 *)*piVar5,param_4,piVar5);
      if (iVar3 == 0) {
        return 0;
      }
      (pVVar9->n1).n2.vt = 0;
    }
LAB_40449df4:
    HVar10 = -0x7ffdfffb;
  }
  else {
    if (param_2 != 0xc) {
      if (((int)param_2 < 0xd) || (0xe < (int)param_2)) goto LAB_40449c30;
      goto LAB_40449d9c;
    }
LAB_40449e1c:
    *(VARIANTARG **)(*(int *)(param_5 + 8) + param_6 * 4) = param_1;
  }
  return HVar10;
}



/* 4044a108 LoadTypeLib */

/* Boundary evidence: original MIPS .pdata 4044a108..4044a127. Semantic name remains unreviewed. */

HRESULT LoadTypeLib(LPCOLESTR szFile,ITypeLib **pptlib)

{
  DWORD DVar1;
  
                    /* 0xa108  15  LoadTypeLib */
  DVar1 = FUN_40449374(szFile,0,(int *)pptlib);
  return DVar1;
}



/* 4044a128 LoadRegTypeLib */

/* Boundary evidence: original MIPS .pdata 4044a128..4044a2ef. Semantic name remains unreviewed. */

HRESULT LoadRegTypeLib(GUID *rguid,WORD wVerMajor,WORD wVerMinor,LCID lcid,ITypeLib **pptlib)

{
  uint uVar1;
  undefined2 in_register_00000016;
  undefined2 in_register_0000001a;
  int iVar2;
  wchar_t **ppwVar3;
  HKEY local_2a0;
  DWORD local_29c;
  wchar_t *local_298 [4];
  OLECHAR aOStack_288 [40];
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0xa128  14  LoadRegTypeLib */
  local_30 = DAT_4046d1b8;
  local_298[0] = L"TypeLib\\%s\\%x.%x\\%x\\win32";
  local_298[1] = L"TypeLib\\%s\\%x.%x\\0\\win32";
  local_298[2] = L"TypeLib\\%s\\%x.%x\\%x";
  local_298[3] = L"TypeLib\\%s\\%x.%x\\0";
  StringFromGUID2(rguid,aOStack_288,0x27);
  iVar2 = 0;
  ppwVar3 = local_298;
  do {
    StringCchPrintfW(awStack_238,0x104,*ppwVar3,aOStack_288,CONCAT22(in_register_00000016,wVerMajor)
                     ,CONCAT22(in_register_0000001a,wVerMinor),lcid);
    uVar1 = RegOpenKeyExW((HKEY)0x80000000,awStack_238,0,0xf003f,&local_2a0);
    if (uVar1 == 0) {
      local_29c = 0x104;
      uVar1 = RegQueryValueExW(local_2a0,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_238,
                               &local_29c);
      if (uVar1 == 0) {
        uVar1 = FUN_40449374(awStack_238,0,(int *)pptlib);
      }
      else if (0 < (int)uVar1) {
        uVar1 = uVar1 & 0xffff | 0x80070000;
      }
      RegCloseKey(local_2a0);
      goto LAB_4044a2b4;
    }
    iVar2 = iVar2 + 1;
    ppwVar3 = ppwVar3 + 1;
  } while (iVar2 < 4);
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
LAB_4044a2b4:
  FUN_4046ace8(local_30);
  return uVar1;
}



/* 4044a2f0 FUN_4044a2f0 */

/* Boundary evidence: original MIPS .pdata 4044a2f0..4044a3db. Semantic name remains unreviewed. */

undefined4 FUN_4044a2f0(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  switch(param_1) {
  case 2:
  case 0xb:
  case 0x12:
    uVar1 = 2;
    break;
  case 5:
  case 6:
  case 7:
    uVar1 = 8;
    break;
  case 8:
    uVar1 = 0x100;
    goto LAB_4044a3b4;
  case 9:
    uVar1 = 0x400;
LAB_4044a3b4:
    *param_3 = uVar1;
    *param_2 = 4;
    return 0;
  case 0xc:
    *param_3 = 0x800;
    uVar1 = 0x10;
    break;
  case 0xd:
    *param_3 = 0x200;
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    uVar1 = 4;
    goto LAB_4044a374;
  case 0xe:
    uVar1 = 0x10;
LAB_4044a374:
    *param_2 = uVar1;
    return 0;
  default:
    return 0x80070057;
  case 0x10:
  case 0x11:
    *param_2 = 1;
    return 0;
  }
  *param_2 = uVar1;
  return 0;
}



/* 4044a3dc FUN_4044a3dc */

/* Boundary evidence: original MIPS .pdata 4044a3dc..4044a503. Semantic name remains unreviewed. */

void FUN_4044a3dc(VARIANTARG *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_2 / param_4;
  if (param_4 == 0) {
    trap(0x1c00);
  }
  if ((param_3 & 0x100) == 0) {
    if ((param_3 & 0x200) == 0) {
      if ((param_3 & 0x400) == 0) {
        if ((param_3 & 0x800) != 0) {
          for (; uVar1 != 0; uVar1 = uVar1 - 1) {
            VariantClear(param_1);
            param_1 = param_1 + 1;
          }
        }
      }
      else {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          if (*(int **)&param_1->n1 != (int *)0x0) {
            (**(code **)(**(int **)&param_1->n1 + 8))();
          }
          param_1 = (VARIANTARG *)((int)&param_1->n1 + 4);
        }
      }
    }
    else {
      for (; uVar1 != 0; uVar1 = uVar1 - 1) {
        if (*(int **)&param_1->n1 != (int *)0x0) {
          (**(code **)(**(int **)&param_1->n1 + 8))();
        }
        param_1 = (VARIANTARG *)((int)&param_1->n1 + 4);
      }
    }
  }
  else {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      SysFreeString(*(BSTR *)&param_1->n1);
      param_1 = (VARIANTARG *)((int)&param_1->n1 + 4);
    }
  }
  return;
}



/* 4044a504 SafeArrayGetDim */

UINT SafeArrayGetDim(SAFEARRAY *psa)

{
                    /* 0xa504  30  SafeArrayGetDim */
  return (uint)psa->cDims;
}



/* 4044a510 SafeArrayGetElemsize */

UINT SafeArrayGetElemsize(SAFEARRAY *psa)

{
                    /* 0xa510  32  SafeArrayGetElemsize */
  return psa->cbElements;
}



/* 4044a518 SafeArrayGetUBound */

HRESULT SafeArrayGetUBound(SAFEARRAY *psa,UINT nDim,LONG *plUbound)

{
  HRESULT HVar1;
  int *piVar2;
  
                    /* 0xa518  34  SafeArrayGetUBound */
  if (psa == (SAFEARRAY *)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else if ((nDim == 0) || (psa->cDims < nDim)) {
    HVar1 = -0x7ffdfff5;
  }
  else {
    piVar2 = (int *)(((psa->cDims - nDim) + 2) * 8 + (int)psa);
    *plUbound = piVar2[1] + *piVar2 + -1;
    HVar1 = 0;
  }
  return HVar1;
}



/* 4044a580 SafeArrayGetLBound */

HRESULT SafeArrayGetLBound(SAFEARRAY *psa,UINT nDim,LONG *plLbound)

{
  HRESULT HVar1;
  
                    /* 0xa580  33  SafeArrayGetLBound */
  if (psa == (SAFEARRAY *)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else if ((nDim == 0) || (psa->cDims < nDim)) {
    HVar1 = -0x7ffdfff5;
  }
  else {
    *plLbound = *(LONG *)((int)psa + (psa->cDims - nDim) * 8 + 0x14);
    HVar1 = 0;
  }
  return HVar1;
}



/* 4044a5d8 SafeArrayLock */

HRESULT SafeArrayLock(SAFEARRAY *psa)

{
  HRESULT HVar1;
  
                    /* 0xa5d8  35  SafeArrayLock */
  if (psa == (SAFEARRAY *)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else if (psa->cLocks == 0xffff) {
    HVar1 = -0x7fff0001;
  }
  else {
    psa->cLocks = psa->cLocks + 1;
    HVar1 = 0;
  }
  return HVar1;
}



/* 4044a61c SafeArrayAccessData */

/* Boundary evidence: original MIPS .pdata 4044a61c..4044a66b. Semantic name remains unreviewed. */

HRESULT SafeArrayAccessData(SAFEARRAY *psa,void **ppvData)

{
  HRESULT HVar1;
  
                    /* 0xa61c  20  SafeArrayAccessData */
  HVar1 = SafeArrayLock(psa);
  if ((HVar1 == 0) || (-1 < HVar1)) {
    HVar1 = 0;
    *ppvData = psa->pvData;
  }
  return HVar1;
}



/* 4044a66c SafeArrayUnaccessData */

HRESULT SafeArrayUnaccessData(SAFEARRAY *psa)

{
  HRESULT HVar1;
  
                    /* 0xa66c  39  SafeArrayUnaccessData
                       0xa66c  40  SafeArrayUnlock */
  if (psa == (SAFEARRAY *)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else if (psa->cLocks == 0) {
    HVar1 = -0x7fff0001;
  }
  else {
    psa->cLocks = psa->cLocks - 1;
    HVar1 = 0;
  }
  return HVar1;
}



/* 4044a6ac SafeArrayPtrOfIndex */

HRESULT SafeArrayPtrOfIndex(SAFEARRAY *psa,LONG *rgIndices,void **ppvData)

{
  int iVar1;
  ULONG UVar2;
  SAFEARRAYBOUND *pSVar3;
  LONG *pLVar4;
  int iVar5;
  
                    /* 0xa6ac  36  SafeArrayPtrOfIndex */
  if (psa->cDims != 0) {
    pLVar4 = rgIndices + (psa->cDims - 1);
    iVar1 = *pLVar4 - psa->rgsabound[0].lLbound;
    iVar5 = 0;
    if (-1 < iVar1) {
      UVar2 = psa->rgsabound[0].cElements;
      pSVar3 = psa->rgsabound;
      do {
        if ((int)UVar2 <= iVar1) {
          return -0x7ffdfff5;
        }
        if (pLVar4 == rgIndices) {
          *ppvData = (PVOID)(psa->cbElements * (iVar1 + iVar5) + (int)psa->pvData);
          return 0;
        }
        UVar2 = pSVar3[1].cElements;
        iVar5 = UVar2 * (iVar1 + iVar5);
        pLVar4 = pLVar4 + -1;
        iVar1 = *pLVar4 - *(int *)((int)(pSVar3 + 1) + 4);
        pSVar3 = pSVar3 + 1;
      } while (-1 < iVar1);
    }
  }
  return -0x7ffdfff5;
}



/* 4044a748 SafeArrayGetElement */

/* Boundary evidence: original MIPS .pdata 4044a748..4044a873. Semantic name remains unreviewed. */

HRESULT SafeArrayGetElement(SAFEARRAY *psa,LONG *rgIndices,void *pv)

{
  ushort uVar1;
  HRESULT HVar2;
  int *piVar3;
  VARIANTARG *local_18 [2];
  
                    /* 0xa748  31  SafeArrayGetElement */
  if ((psa == (SAFEARRAY *)0x0) || (pv == (void *)0x0)) {
    return -0x7ff8ffa9;
  }
  HVar2 = SafeArrayLock(psa);
  if ((HVar2 < 0) || (HVar2 = SafeArrayPtrOfIndex(psa,rgIndices,local_18), HVar2 < 0))
  goto LAB_4044a83c;
  uVar1 = psa->fFeatures;
  if ((uVar1 & 0x100) == 0) {
    if (((uVar1 & 0x200) == 0) && ((uVar1 & 0x400) == 0)) {
      if ((uVar1 & 0x800) != 0) {
        *(undefined2 *)pv = 0;
        HVar2 = VariantCopy(pv,local_18[0]);
        goto LAB_4044a820;
      }
      memcpy(pv,local_18[0],psa->cbElements);
    }
    else {
      piVar3 = *(int **)&local_18[0]->n1;
      *(int **)pv = piVar3;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))();
      }
    }
  }
  else {
    HVar2 = FUN_4044bb64(*(LPCSTR *)&local_18[0]->n1,pv);
LAB_4044a820:
    if (HVar2 < 0) goto LAB_4044a83c;
  }
  HVar2 = 0;
LAB_4044a83c:
  if (psa->cLocks != 0) {
    psa->cLocks = psa->cLocks - 1;
  }
  return HVar2;
}



/* 4044a874 SafeArrayPutElement */

/* Boundary evidence: original MIPS .pdata 4044a874..4044a9c3. Semantic name remains unreviewed. */

HRESULT SafeArrayPutElement(SAFEARRAY *psa,LONG *rgIndices,void *pv)

{
  ushort uVar1;
  HRESULT HVar2;
  BSTR bstrString;
  VARIANTARG *local_18 [2];
  
                    /* 0xa874  37  SafeArrayPutElement */
  if ((psa == (SAFEARRAY *)0x0) || (pv == (void *)0x0)) {
    return -0x7ff8ffa9;
  }
  HVar2 = SafeArrayLock(psa);
  if (HVar2 < 0) {
    return HVar2;
  }
  HVar2 = SafeArrayPtrOfIndex(psa,rgIndices,local_18);
  if (-1 < HVar2) {
    uVar1 = psa->fFeatures;
    if ((uVar1 & 0x100) == 0) {
      if (((uVar1 & 0x200) == 0) && ((uVar1 & 0x400) == 0)) {
        if ((uVar1 & 0x800) == 0) {
          memcpy(local_18[0],pv,psa->cbElements);
        }
        else {
          HVar2 = VariantCopy(local_18[0],pv);
          if (HVar2 < 0) goto LAB_4044a98c;
        }
      }
      else {
        if (*(int **)&local_18[0]->n1 != (int *)0x0) {
          (**(code **)(**(int **)&local_18[0]->n1 + 8))();
        }
        *(void **)&local_18[0]->n1 = pv;
        (**(code **)(*(int *)pv + 4))(pv);
      }
    }
    else {
      bstrString = *(BSTR *)&local_18[0]->n1;
      HVar2 = FUN_4044bb1c(pv,(undefined4 *)local_18[0]);
      if (HVar2 < 0) goto LAB_4044a98c;
      SysFreeString(bstrString);
    }
    HVar2 = 0;
  }
LAB_4044a98c:
  if (psa->cLocks != 0) {
    psa->cLocks = psa->cLocks - 1;
  }
  return HVar2;
}



/* 4044a9c4 FUN_4044a9c4 */

uint FUN_4044a9c4(uint param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if ((param_1 != 0) && (uVar3 = 0, uVar1 = param_2, param_1 != 0)) {
    do {
      uVar1 = *param_3;
      if (param_2 >> 0x10 == 0) {
        if (uVar1 >> 0x10 != 0) goto LAB_4044aa20;
        param_2 = (uVar1 & 0xffff) * (param_2 & 0xffff);
      }
      else {
        if (uVar1 >> 0x10 != 0) {
          return 0xffffffff;
        }
LAB_4044aa20:
        uVar2 = uVar1;
        if (uVar1 >> 0x10 != 0) {
          uVar2 = param_2;
          param_2 = uVar1;
        }
        uVar1 = (param_2 >> 0x10) * (uVar2 & 0xffff);
        if ((uVar1 >> 0x10 != 0) ||
           (uVar2 = (param_2 & 0xffff) * (uVar2 & 0xffff), param_2 = uVar1 * 0x10000 + uVar2,
           param_2 < uVar2)) {
          return 0xffffffff;
        }
      }
      uVar3 = uVar3 + 1 & 0xffff;
      param_3 = param_3 + 2;
      uVar1 = param_2;
    } while (uVar3 < param_1);
  }
  return uVar1;
}



/* 4044aaa4 SafeArrayCreateVector */

/* Boundary evidence: original MIPS .pdata 4044aaa4..4044abab. Semantic name remains unreviewed. */

SAFEARRAY * SafeArrayCreateVector(VARTYPE vt,LONG lLbound,ULONG cElements)

{
  int iVar1;
  uint uVar2;
  SAFEARRAY *_Dst;
  undefined2 in_register_00000012;
  ushort local_30;
  ushort local_2e [3];
  ULONG local_28;
  LONG local_24;
  
                    /* 0xaaa4  26  SafeArrayCreateVector */
  local_28 = cElements;
  local_24 = lLbound;
  iVar1 = FUN_4044a2f0(CONCAT22(in_register_00000012,vt),&local_30,local_2e);
  if (-1 < iVar1) {
    uVar2 = FUN_4044a9c4(1,(uint)local_30,&local_28);
    if ((uVar2 != 0xffffffff) && (uVar2 < 0x7fffffe8)) {
      _Dst = CoTaskMemAlloc(uVar2 + 0x18);
      if (_Dst != (SAFEARRAY *)0x0) {
        memset(_Dst,0,uVar2 + 0x18);
        _Dst->pvData = _Dst + 1;
        _Dst->cDims = 1;
        _Dst->cbElements = (uint)local_30;
        _Dst->fFeatures = local_2e[0] | 0x2000;
        _Dst->rgsabound[0].cElements = cElements;
        _Dst->rgsabound[0].lLbound = lLbound;
        return _Dst;
      }
    }
  }
  return (SAFEARRAY *)0x0;
}



/* 4044abac SafeArrayAllocDescriptor */

/* Boundary evidence: original MIPS .pdata 4044abac..4044ac4b. Semantic name remains unreviewed. */

HRESULT SafeArrayAllocDescriptor(UINT cDims,SAFEARRAY **ppsaOut)

{
  HRESULT HVar1;
  SAFEARRAY *_Dst;
  SIZE_T _Size;
  
                    /* 0xabac  22  SafeArrayAllocDescriptor */
  if ((cDims == 0) || (0xffff < cDims)) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    _Size = (cDims + 2) * 8;
    _Dst = FUN_404589c4(_Size);
    if (_Dst == (SAFEARRAY *)0x0) {
      HVar1 = -0x7ff8fff2;
    }
    else {
      memset(_Dst,0,_Size);
      _Dst->cDims = (USHORT)cDims;
      *ppsaOut = _Dst;
      HVar1 = 0;
    }
  }
  return HVar1;
}



/* 4044ac4c SafeArrayAllocData */

/* Boundary evidence: original MIPS .pdata 4044ac4c..4044ace3. Semantic name remains unreviewed. */

HRESULT SafeArrayAllocData(SAFEARRAY *psa)

{
  HRESULT HVar1;
  uint cb;
  LPVOID _Dst;
  
                    /* 0xac4c  21  SafeArrayAllocData */
  if (psa == (SAFEARRAY *)0x0) {
    HVar1 = -0x7ff8ffa9;
  }
  else {
    cb = FUN_4044a9c4((uint)psa->cDims,psa->cbElements,&psa->rgsabound[0].cElements);
    if (cb != 0xffffffff) {
      _Dst = CoTaskMemAlloc(cb);
      psa->pvData = _Dst;
      if (_Dst != (LPVOID)0x0) {
        memset(_Dst,0,cb);
        return 0;
      }
    }
    HVar1 = -0x7ff8fff2;
  }
  return HVar1;
}



/* 4044ace4 SafeArrayDestroyData */

/* Boundary evidence: original MIPS .pdata 4044ace4..4044ade3. Semantic name remains unreviewed. */

HRESULT SafeArrayDestroyData(SAFEARRAY *psa)

{
  ushort uVar1;
  uint _Size;
  uint uVar2;
  VARIANTARG *pVVar3;
  
                    /* 0xace4  28  SafeArrayDestroyData */
  if (psa != (SAFEARRAY *)0x0) {
    if (psa->cLocks != 0) {
      return -0x7ffdfff3;
    }
    pVVar3 = psa->pvData;
    if (pVVar3 != (VARIANTARG *)0x0) {
      uVar2 = psa->cbElements;
      _Size = FUN_4044a9c4((uint)psa->cDims,uVar2,&psa->rgsabound[0].cElements);
      FUN_4044a3dc(pVVar3,_Size,(uint)psa->fFeatures,uVar2);
      if ((psa->fFeatures & 2) != 0) {
        memset(psa->pvData,0,_Size);
      }
      uVar1 = psa->fFeatures;
      if (((uVar1 & 7) == 0) || ((uVar1 & 0x1000) != 0)) {
        if ((uVar1 & 0x2000) == 0) {
          CoTaskMemFree(psa->pvData);
          psa->pvData = (PVOID)0x0;
        }
        else {
          psa->fFeatures = uVar1 & 0xdfff;
        }
      }
    }
  }
  return 0;
}



/* 4044ade4 SafeArrayDestroyDescriptor */

/* Boundary evidence: original MIPS .pdata 4044ade4..4044ae8f. Semantic name remains unreviewed. */

HRESULT SafeArrayDestroyDescriptor(SAFEARRAY *psa)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
                    /* 0xade4  29  SafeArrayDestroyDescriptor */
  if (psa != (SAFEARRAY *)0x0) {
    if (psa->cLocks != 0) {
      return -0x7ffdfff3;
    }
    uVar1 = psa->fFeatures;
    if ((uVar1 & 0x2000) == 0) {
      FUN_40458abc(psa);
    }
    else {
      uVar3 = psa->cbElements;
      uVar2 = FUN_4044a9c4((uint)psa->cDims,uVar3,&psa->rgsabound[0].cElements);
      FUN_4044a3dc(psa->pvData,uVar2,(uint)uVar1,uVar3);
      CoTaskMemFree(psa);
    }
  }
  return 0;
}



/* 4044ae90 SafeArrayDestroy */

/* Boundary evidence: original MIPS .pdata 4044ae90..4044afc3. Semantic name remains unreviewed. */

HRESULT SafeArrayDestroy(SAFEARRAY *psa)

{
  ushort uVar1;
  uint _Size;
  HRESULT HVar2;
  uint uVar3;
  
                    /* 0xae90  27  SafeArrayDestroy */
  if (psa != (SAFEARRAY *)0x0) {
    if (psa->cLocks != 0) {
      return -0x7ffdfff3;
    }
    uVar1 = psa->fFeatures;
    if ((uVar1 & 0x2000) == 0) {
      if (((psa->pvData != (PVOID)0x0) && (HVar2 = SafeArrayDestroyData(psa), HVar2 != 0)) &&
         (HVar2 < 0)) {
        return HVar2;
      }
      if (((psa->fFeatures & 7) == 0) || ((psa->fFeatures & 0x1000) != 0)) {
        FUN_40458abc(psa);
      }
    }
    else {
      uVar3 = psa->cbElements;
      _Size = FUN_4044a9c4((uint)psa->cDims,uVar3,&psa->rgsabound[0].cElements);
      FUN_4044a3dc(psa->pvData,_Size,(uint)uVar1,uVar3);
      if (((psa->fFeatures & 2) == 0) || ((psa->fFeatures & 0x1000) != 0)) {
        CoTaskMemFree(psa);
      }
      else {
        memset(psa->pvData,0,_Size);
      }
    }
  }
  return 0;
}



/* 4044afc4 SafeArrayRedim */

/* Boundary evidence: original MIPS .pdata 4044afc4..4044b243. Semantic name remains unreviewed. */

HRESULT SafeArrayRedim(SAFEARRAY *psa,SAFEARRAYBOUND *psaboundNew)

{
  ushort uVar1;
  ushort uVar2;
  uint _Size;
  LPVOID pvVar3;
  LONG LVar4;
  size_t _Size_00;
  HRESULT HVar5;
  uint uVar6;
  VARIANTARG *_Dst;
  SAFEARRAYBOUND *pSVar7;
  ULONG UVar8;
  
                    /* 0xafc4  38  SafeArrayRedim */
  uVar1 = psa->fFeatures;
  if ((psa->cLocks != 0) || ((uVar1 & 0x10) != 0)) {
    return -0x7ffdfff3;
  }
  uVar6 = psa->cbElements;
  uVar2 = psa->cDims;
  pSVar7 = psa->rgsabound;
  _Dst = (VARIANTARG *)0x0;
  _Size = FUN_4044a9c4((uint)uVar2,uVar6,&pSVar7->cElements);
  LVar4 = psa->rgsabound[0].lLbound;
  UVar8 = pSVar7->cElements;
  pSVar7->cElements = psaboundNew->cElements;
  psa->rgsabound[0].lLbound = psaboundNew->lLbound;
  uVar6 = FUN_4044a9c4((uint)uVar2,uVar6,&pSVar7->cElements);
  if (uVar6 == 0xffffffff) {
    return -0x7ff8fff2;
  }
  _Size_00 = uVar6 - _Size;
  if (_Size_00 == 0) {
    return 0;
  }
  if (((int)_Size_00 < 0) && ((uVar1 & 0xf00) != 0)) {
    if ((uVar1 & 0x2000) != 0) {
      _Dst = (VARIANTARG *)((int)psa->pvData + uVar6);
      goto LAB_4044b0fc;
    }
    _Dst = CoTaskMemAlloc(-_Size_00);
    if (_Dst != (VARIANTARG *)0x0) {
      memcpy(_Dst,(void *)((int)psa->pvData + uVar6),-_Size_00);
      goto LAB_4044b0fc;
    }
LAB_4044b1c4:
    HVar5 = -0x7ff8fff2;
  }
  else {
LAB_4044b0fc:
    if ((uVar1 & 0x2000) == 0) {
      pvVar3 = CoTaskMemRealloc(psa->pvData,uVar6);
      if (pvVar3 == (LPVOID)0x0) {
        if (uVar6 != 0) goto LAB_4044b1b8;
        pvVar3 = CoTaskMemAlloc(0);
      }
      psa->pvData = pvVar3;
    }
    else if (_Size < uVar6) {
      pvVar3 = CoTaskMemAlloc(uVar6);
      if (pvVar3 == (LPVOID)0x0) {
LAB_4044b1b8:
        pSVar7->cElements = UVar8;
        psa->rgsabound[0].lLbound = LVar4;
        goto LAB_4044b1c4;
      }
      memcpy(pvVar3,psa->pvData,_Size);
      psa->pvData = pvVar3;
      psa->fFeatures = psa->fFeatures & 0xdfff;
    }
    if ((int)_Size_00 < 0) {
      if (_Dst != (VARIANTARG *)0x0) {
        FUN_4044a3dc(_Dst,-_Size_00,(uint)psa->fFeatures,psa->cbElements);
      }
      if ((uVar1 & 0x2000) != 0) {
        _Dst = (VARIANTARG *)0x0;
      }
    }
    else {
      memset((void *)((int)psa->pvData + _Size),0,_Size_00);
    }
    HVar5 = 0;
  }
  if (_Dst != (VARIANTARG *)0x0) {
    CoTaskMemFree(_Dst);
  }
  return HVar5;
}



/* 4044b244 SafeArrayCopyData */

/* Boundary evidence: original MIPS .pdata 4044b244..4044b557. Semantic name remains unreviewed. */

HRESULT SafeArrayCopyData(SAFEARRAY *psaSource,SAFEARRAY *psaTarget)

{
  ushort uVar1;
  HRESULT HVar2;
  uint uVar3;
  SAFEARRAYBOUND *pSVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  VARIANTARG *pvargSrc;
  undefined4 *puVar9;
  int *piVar10;
  VARIANTARG *pvargDest;
  
                    /* 0xb244  24  SafeArrayCopyData */
  if (((psaSource == (SAFEARRAY *)0x0) || (psaTarget == (SAFEARRAY *)0x0)) ||
     (psaSource->cDims != psaTarget->cDims)) {
    return -0x7ff8ffa9;
  }
  uVar5 = 0;
  if (psaSource->cDims != 0) {
    pSVar4 = psaTarget->rgsabound;
    do {
      if (*(ULONG *)(((int)psaSource - (int)psaTarget) + (int)pSVar4) != pSVar4->cElements) {
        return -0x7ff8ffa9;
      }
      uVar5 = uVar5 + 1;
      pSVar4 = pSVar4 + 1;
    } while (uVar5 < psaSource->cDims);
  }
  HVar2 = SafeArrayLock(psaSource);
  if (HVar2 < 0) {
    return HVar2;
  }
  HVar2 = SafeArrayLock(psaTarget);
  if (-1 < HVar2) {
    uVar6 = psaSource->cbElements;
    uVar3 = FUN_4044a9c4((uint)psaSource->cDims,uVar6,&psaSource->rgsabound[0].cElements);
    uVar5 = uVar3 / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    uVar1 = psaSource->fFeatures;
    if ((uVar1 & 0x100) == 0) {
      if ((uVar1 & 0x200) == 0) {
        if ((uVar1 & 0x400) == 0) {
          if ((uVar1 & 0x800) == 0) {
            if (uVar3 != 0) {
              memcpy(psaTarget->pvData,psaSource->pvData,uVar3);
            }
          }
          else {
            pvargSrc = psaSource->pvData;
            pvargDest = psaTarget->pvData;
            uVar3 = 0;
            if (uVar5 != 0) {
              do {
                HVar2 = VariantCopy(pvargDest,pvargSrc);
                if (HVar2 < 0) goto LAB_4044b4a0;
                uVar3 = uVar3 + 1;
                pvargDest = pvargDest + 1;
                pvargSrc = pvargSrc + 1;
              } while (uVar3 < uVar5);
            }
          }
        }
        else {
          piVar8 = psaSource->pvData;
          piVar10 = psaTarget->pvData;
          for (; uVar5 != 0; uVar5 = uVar5 - 1) {
            if ((int *)*piVar8 != (int *)0x0) {
              (**(code **)(*(int *)*piVar8 + 4))();
            }
            if ((int *)*piVar10 != (int *)0x0) {
              (**(code **)(*(int *)*piVar10 + 8))();
            }
            *piVar10 = *piVar8;
            piVar10 = piVar10 + 1;
            piVar8 = piVar8 + 1;
          }
        }
      }
      else {
        piVar8 = psaSource->pvData;
        piVar10 = psaTarget->pvData;
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          if ((int *)*piVar8 != (int *)0x0) {
            (**(code **)(*(int *)*piVar8 + 4))();
          }
          if ((int *)*piVar10 != (int *)0x0) {
            (**(code **)(*(int *)*piVar10 + 8))();
          }
          *piVar10 = *piVar8;
          piVar10 = piVar10 + 1;
          piVar8 = piVar8 + 1;
        }
      }
    }
    else {
      puVar9 = psaSource->pvData;
      puVar7 = psaTarget->pvData;
      uVar3 = 0;
      if (uVar5 != 0) {
        do {
          if ((BSTR)*puVar7 != (BSTR)0x0) {
            SysFreeString((BSTR)*puVar7);
          }
          HVar2 = FUN_4044bb1c((LPCSTR)*puVar9,puVar7);
          if (HVar2 < 0) goto LAB_4044b4a0;
          uVar3 = uVar3 + 1;
          puVar7 = puVar7 + 1;
          puVar9 = puVar9 + 1;
        } while (uVar3 < uVar5);
      }
    }
    if (psaTarget->cLocks != 0) {
      psaTarget->cLocks = psaTarget->cLocks - 1;
      if (psaSource->cLocks != 0) {
        psaSource->cLocks = psaSource->cLocks - 1;
        return 0;
      }
      return -0x7fff0001;
    }
    HVar2 = -0x7fff0001;
  }
LAB_4044b4b4:
  if (psaSource->cLocks != 0) {
    psaSource->cLocks = psaSource->cLocks - 1;
  }
  return HVar2;
LAB_4044b4a0:
  if (psaTarget->cLocks != 0) {
    psaTarget->cLocks = psaTarget->cLocks - 1;
  }
  goto LAB_4044b4b4;
}



/* 4044b558 SafeArrayCopy */

/* Boundary evidence: original MIPS .pdata 4044b558..4044b64f. Semantic name remains unreviewed. */

HRESULT SafeArrayCopy(SAFEARRAY *psa,SAFEARRAY **ppsaOut)

{
  HRESULT HVar1;
  SAFEARRAY *local_20 [2];
  
                    /* 0xb558  23  SafeArrayCopy */
  if (ppsaOut == (SAFEARRAY **)0x0) {
    return -0x7ff8ffa9;
  }
  *ppsaOut = (SAFEARRAY *)0x0;
  if (psa != (SAFEARRAY *)0x0) {
    HVar1 = SafeArrayAllocDescriptor((uint)psa->cDims,local_20);
    if ((HVar1 != 0) && (HVar1 < 0)) {
      return HVar1;
    }
    local_20[0]->cLocks = 0;
    local_20[0]->cDims = psa->cDims;
    local_20[0]->fFeatures = psa->fFeatures & 0xcfe8;
    local_20[0]->cbElements = psa->cbElements;
    memcpy(local_20[0]->rgsabound,psa->rgsabound,(uint)psa->cDims << 3);
    HVar1 = SafeArrayAllocData(local_20[0]);
    if ((HVar1 < 0) || (HVar1 = SafeArrayCopyData(psa,local_20[0]), HVar1 < 0)) {
      SafeArrayDestroy(local_20[0]);
      return HVar1;
    }
    *ppsaOut = local_20[0];
  }
  return 0;
}



/* 4044b650 SafeArrayCreate */

/* Boundary evidence: original MIPS .pdata 4044b650..4044b72f. Semantic name remains unreviewed. */

SAFEARRAY * SafeArrayCreate(VARTYPE vt,UINT cDims,SAFEARRAYBOUND *rgsabound)

{
  SAFEARRAYBOUND *pSVar1;
  int iVar2;
  HRESULT HVar3;
  undefined2 in_register_00000012;
  SAFEARRAYBOUND *pSVar4;
  ushort local_18;
  USHORT local_16;
  SAFEARRAY *local_14;
  
                    /* 0xb650  25  SafeArrayCreate */
  if ((((cDims != 0) && (cDims < 0x10000)) &&
      (iVar2 = FUN_4044a2f0(CONCAT22(in_register_00000012,vt),&local_18,&local_16), -1 < iVar2)) &&
     (HVar3 = SafeArrayAllocDescriptor(cDims,&local_14), -1 < HVar3)) {
    local_14->cDims = (USHORT)cDims;
    local_14->cbElements = (uint)local_18;
    local_14->fFeatures = local_16;
    if (cDims != 0) {
      pSVar4 = local_14->rgsabound;
      pSVar1 = rgsabound + cDims;
      do {
        cDims = cDims - 1;
        pSVar4->cElements = pSVar1[-1].cElements;
        pSVar4->lLbound = pSVar1[-1].lLbound;
        pSVar4 = pSVar4 + 1;
        pSVar1 = pSVar1 + -1;
      } while (cDims != 0);
    }
    HVar3 = SafeArrayAllocData(local_14);
    if (-1 < HVar3) {
      return local_14;
    }
    SafeArrayDestroy(local_14);
  }
  return (SAFEARRAY *)0x0;
}



/* 4044b730 SysStringLen */

UINT SysStringLen(BSTR param_1)

{
  uint uVar1;
  
                    /* 0xb730  49  SysStringLen */
  if (param_1 == (BSTR)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(param_1 + -2) >> 1;
  }
  return uVar1;
}



/* 4044b750 SysStringByteLen */

UINT SysStringByteLen(BSTR bstr)

{
  UINT UVar1;
  
                    /* 0xb750  48  SysStringByteLen */
  UVar1 = 0;
  if (bstr != (BSTR)0x0) {
    UVar1 = *(UINT *)(bstr + -2);
  }
  return UVar1;
}



/* 4044b764 SysAllocStringLen */

/* Boundary evidence: original MIPS .pdata 4044b764..4044b81f. Semantic name remains unreviewed. */

BSTR SysAllocStringLen(OLECHAR *strIn,UINT ui)

{
  int iVar1;
  BSTR _Dst;
  size_t _Size;
  int local_18 [2];
  
                    /* 0xb764  44  SysAllocStringLen */
  if ((ui < 0x7ffffff4) && (iVar1 = FUN_40447728(local_18), -1 < iVar1)) {
    _Size = ui * 2;
    _Dst = FUN_40457d14(local_18[0],_Size + 0x19 & 0xfffffff0);
    if (_Dst != (BSTR)0x0) {
      _Dst[0] = L'瑲';
      _Dst[1] = L'扳';
      *(size_t *)(_Dst + 2) = _Size;
      _Dst = _Dst + 4;
      if (strIn != (OLECHAR *)0x0) {
        memcpy(_Dst,strIn,_Size);
      }
      _Dst[ui] = L'\0';
    }
  }
  else {
    _Dst = (BSTR)0x0;
  }
  return _Dst;
}



/* 4044b820 SysReAllocStringLen */

/* Boundary evidence: original MIPS .pdata 4044b820..4044b8f3. Semantic name remains unreviewed. */

INT SysReAllocStringLen(BSTR *pbstr,OLECHAR *psz,uint len)

{
  undefined4 *puVar1;
  BSTR pOVar2;
  size_t _Size;
  
                    /* 0xb820  47  SysReAllocStringLen */
  if (len < 0x7ffffff4) {
    _Size = len * 2;
    pOVar2 = *pbstr;
    if (pOVar2 != (BSTR)0x0) {
      if (psz == pOVar2) {
        psz = (OLECHAR *)0x0;
      }
      pOVar2 = pOVar2 + -4;
    }
    puVar1 = CoTaskMemRealloc(pOVar2,_Size + 0x19 & 0xfffffff0);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0x62737472;
      puVar1[1] = _Size;
      pOVar2 = (BSTR)(puVar1 + 2);
      if (psz != (OLECHAR *)0x0) {
        memcpy(pOVar2,psz,_Size);
      }
      pOVar2[len] = L'\0';
      *pbstr = pOVar2;
      return 1;
    }
  }
  return 0;
}



/* 4044b8f4 SysFreeString */

/* Boundary evidence: original MIPS .pdata 4044b8f4..4044b967. Semantic name remains unreviewed. */

void SysFreeString(BSTR bstrString)

{
  LPVOID pvVar1;
  
                    /* 0xb8f4  45  SysFreeString */
  if (bstrString != (BSTR)0x0) {
    pvVar1 = TlsGetValue(DAT_4046d1b0);
    if (pvVar1 == (LPVOID)0x0) {
      CoTaskMemFree(bstrString + -4);
    }
    else {
      FUN_40457ba4((int)pvVar1,bstrString + -4);
    }
  }
  return;
}



/* 4044b968 SysAllocStringByteLen */

/* Boundary evidence: original MIPS .pdata 4044b968..4044ba33. Semantic name remains unreviewed. */

BSTR SysAllocStringByteLen(LPCSTR psz,UINT len)

{
  int iVar1;
  BSTR _Dst;
  int local_18 [2];
  
                    /* 0xb968  43  SysAllocStringByteLen */
  if ((len < 0xffffffe7) && (iVar1 = FUN_40447728(local_18), -1 < iVar1)) {
    _Dst = FUN_40457d14(local_18[0],len + 0x19 & 0xfffffff0);
    if (_Dst != (BSTR)0x0) {
      _Dst[0] = L'瑲';
      _Dst[1] = L'扳';
      *(UINT *)(_Dst + 2) = len;
      _Dst = _Dst + 4;
      if (psz != (LPCSTR)0x0) {
        memcpy(_Dst,psz,len);
      }
      *(undefined1 *)((int)_Dst + len) = 0;
      *(undefined2 *)((len + 1 & 0xfffffffe) + (int)_Dst) = 0;
    }
  }
  else {
    _Dst = (BSTR)0x0;
  }
  return _Dst;
}



/* 4044ba34 SysAllocString */

/* Boundary evidence: original MIPS .pdata 4044ba34..4044ba77. Semantic name remains unreviewed. */

BSTR SysAllocString(OLECHAR *psz)

{
  BSTR pOVar1;
  size_t ui;
  
                    /* 0xba34  42  SysAllocString */
  if (psz == (OLECHAR *)0x0) {
    pOVar1 = (BSTR)0x0;
  }
  else {
    ui = wcslen(psz);
    pOVar1 = SysAllocStringLen(psz,ui);
  }
  return pOVar1;
}



/* 4044ba78 SysReAllocString */

/* Boundary evidence: original MIPS .pdata 4044ba78..4044bad3. Semantic name remains unreviewed. */

INT SysReAllocString(BSTR *pbstr,OLECHAR *psz)

{
  INT IVar1;
  size_t len;
  
                    /* 0xba78  46  SysReAllocString */
  if (psz == (OLECHAR *)0x0) {
    SysFreeString(*pbstr);
    IVar1 = 1;
    *pbstr = (BSTR)0x0;
  }
  else {
    len = wcslen(psz);
    IVar1 = SysReAllocStringLen(pbstr,psz,len);
  }
  return IVar1;
}



/* 4044bad4 FUN_4044bad4 */

/* Boundary evidence: original MIPS .pdata 4044bad4..4044bb1b. Semantic name remains unreviewed. */

undefined4 FUN_4044bad4(OLECHAR *param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  
  if (param_1 == (OLECHAR *)0x0) {
    *param_2 = 0;
  }
  else {
    pOVar1 = SysAllocString(param_1);
    *param_2 = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
      return 0x8007000e;
    }
  }
  return 0;
}



/* 4044bb1c FUN_4044bb1c */

/* Boundary evidence: original MIPS .pdata 4044bb1c..4044bb63. Semantic name remains unreviewed. */

undefined4 FUN_4044bb1c(LPCSTR param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  
  if (param_1 == (LPCSTR)0x0) {
    *param_2 = 0;
  }
  else {
    pOVar1 = SysAllocStringByteLen(param_1,*(UINT *)(param_1 + -4));
    *param_2 = pOVar1;
    if (pOVar1 == (BSTR)0x0) {
      return 0x8007000e;
    }
  }
  return 0;
}



/* 4044bb64 FUN_4044bb64 */

/* Boundary evidence: original MIPS .pdata 4044bb64..4044bbaf. Semantic name remains unreviewed. */

undefined4 FUN_4044bb64(LPCSTR param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  undefined4 uVar2;
  UINT len;
  
  len = 0;
  if (param_1 != (LPCSTR)0x0) {
    len = *(UINT *)(param_1 + -4);
  }
  pOVar1 = SysAllocStringByteLen(param_1,len);
  *param_2 = pOVar1;
  if (pOVar1 == (BSTR)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4044bbb0 SystemTimeToVariantTime */

/* Boundary evidence: original MIPS .pdata 4044bbb0..4044bccb. Semantic name remains unreviewed. */

INT SystemTimeToVariantTime(LPSYSTEMTIME lpSystemTime,DOUBLE *pvtime)

{
  int iVar1;
  undefined2 local_30 [4];
  undefined4 local_28;
  undefined4 local_24;
  UDATE local_20;
  
                    /* 0xbbb0  50  SystemTimeToVariantTime */
  local_20.st.wDayOfWeek = lpSystemTime->wDayOfWeek;
  local_20.st.wYear = lpSystemTime->wYear;
  local_20.st.wMonth = lpSystemTime->wMonth;
  local_20.st.wDay = lpSystemTime->wDay;
  local_20.st.wHour = lpSystemTime->wHour;
  local_20.st.wMinute = lpSystemTime->wMinute;
  local_20.st.wSecond = lpSystemTime->wSecond;
  if (((((-1 < (short)local_20.st.wYear) && (-1 < (short)local_20.st.wMonth)) &&
       (-1 < (short)local_20.st.wDay)) &&
      (((((short)local_20.st.wYear < 10000 && ((short)local_20.st.wMonth < 0xd)) &&
        (((short)local_20.st.wDay < 0x20 &&
         ((-1 < (short)local_20.st.wHour && (-1 < (short)local_20.st.wMinute)))))) &&
       (-1 < (short)local_20.st.wSecond)))) &&
     ((((short)local_20.st.wHour < 0x18 && ((short)local_20.st.wMinute < 0x3c)) &&
      ((short)local_20.st.wSecond < 0x3c)))) {
    local_30[0] = 0;
    iVar1 = FUN_4045309c(&local_20,local_30,0,0);
    if (iVar1 == 0) {
      *(undefined4 *)pvtime = local_28;
      *(undefined4 *)((int)pvtime + 4) = local_24;
      return 1;
    }
  }
  return 0;
}



/* 4044bccc VariantTimeToSystemTime */

/* Boundary evidence: original MIPS .pdata 4044bccc..4044bd5b. Semantic name remains unreviewed. */

INT VariantTimeToSystemTime(DOUBLE vtime,LPSYSTEMTIME lpSystemTime)

{
  HRESULT HVar1;
  short local_30 [8];
  UDATE local_20;
  
                    /* 0xbccc  230  VariantTimeToSystemTime */
  local_30[0] = 5;
  HVar1 = FUN_404534d4(vtime,&local_20,local_30,0);
  if (HVar1 == 0) {
    lpSystemTime->wYear = local_20.st.wYear;
    lpSystemTime->wMonth = local_20.st.wMonth;
    lpSystemTime->wDayOfWeek = local_20.st.wDayOfWeek;
    lpSystemTime->wDay = local_20.st.wDay;
    lpSystemTime->wHour = local_20.st.wHour;
    lpSystemTime->wMinute = local_20.st.wMinute;
    lpSystemTime->wSecond = local_20.st.wSecond;
    lpSystemTime->wMilliseconds = 0;
  }
  return (uint)(HVar1 == 0);
}



/* 4044bd5c FUN_4044bd5c */

undefined8 FUN_4044bd5c(uint param_1,uint param_2)

{
  if (param_2 == 0) {
    trap(0x1c00);
  }
  if (param_2 == 0) {
    trap(0x1c00);
  }
  return CONCAT44(param_1 % param_2,param_1 / param_2);
}



/* 4044bd88 FUN_4044bd88 */

/* Boundary evidence: original MIPS .pdata 4044bd88..4044bdfb. Semantic name remains unreviewed. */

undefined8 FUN_4044bd88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = __ull_div(param_1,param_2,param_3,0);
  uVar2 = __ull_rem(param_1,param_2,param_3,0);
  return CONCAT44(uVar2,uVar1);
}



/* 4044bdfc FUN_4044bdfc */

longlong FUN_4044bdfc(uint param_1,uint param_2)

{
  return (ulonglong)param_1 * (ulonglong)param_2;
}



/* 4044be10 FUN_4044be10 */

void FUN_4044be10(undefined2 *param_1,undefined2 param_2,int param_3)

{
  undefined2 *local_res0;
  int local_res8;
  
  local_res0 = param_1;
  for (local_res8 = param_3; local_res8 != 0; local_res8 = local_res8 + -1) {
    *local_res0 = param_2;
    local_res0 = local_res0 + 1;
  }
  return;
}



/* 4044be64 FUN_4044be64 */

/* Boundary evidence: original MIPS .pdata 4044be64..4044bed7. Semantic name remains unreviewed. */

short * FUN_4044be64(short *param_1,short param_2,int param_3)

{
  short *local_res0;
  int local_res8;
  
  local_res8 = param_3;
  for (local_res0 = param_1; (local_res8 != 0 && (*local_res0 == param_2));
      local_res0 = local_res0 + 1) {
    local_res8 = local_res8 + -1;
  }
  return local_res0;
}



/* 4044bed8 VarDecFromUI1 */

/* Boundary evidence: original MIPS .pdata 4044bed8..4044bf1f. Semantic name remains unreviewed. */

HRESULT VarDecFromUI1(BYTE bIn,DECIMAL *pdecOut)

{
                    /* 0xbed8  114  VarDecFromUI1 */
  *(uint *)&pdecOut->u2 = (uint)bIn;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).signscale = 0;
  return 0;
}



/* 4044bf20 VarDecFromI2 */

/* Boundary evidence: original MIPS .pdata 4044bf20..4044bf9b. Semantic name remains unreviewed. */

HRESULT VarDecFromI2(SHORT uiIn,DECIMAL *pdecOut)

{
  uint uVar1;
  
                    /* 0xbf20  109  VarDecFromI2 */
  uVar1 = (int)uiIn >> 0x1f;
  (pdecOut->u2).s2.Lo32 = ((int)uiIn ^ uVar1) - uVar1 & 0xffff;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).s.sign = (byte)((ushort)uiIn >> 8) & 0x80;
  (pdecOut->u).s.scale = '\0';
  return 0;
}



/* 4044bf9c VarDecFromI4 */

/* Boundary evidence: original MIPS .pdata 4044bf9c..4044c007. Semantic name remains unreviewed. */

HRESULT VarDecFromI4(LONG lIn,DECIMAL *pdecOut)

{
                    /* 0xbf9c  110  VarDecFromI4 */
  (pdecOut->u2).s2.Lo32 = (lIn ^ lIn >> 0x1f) - (lIn >> 0x1f);
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).s.sign = (byte)((uint)lIn >> 0x18) & 0x80;
  (pdecOut->u).s.scale = '\0';
  return 0;
}



/* 4044c008 VarDecFromR4 */

/* Boundary evidence: original MIPS .pdata 4044c008..4044c603. Semantic name remains unreviewed. */

HRESULT VarDecFromR4(FLOAT fltIn,DECIMAL *pdecOut)

{
  undefined4 uVar1;
  uint in_a0;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  int local_98;
  uint local_90;
  int local_8c;
  uint local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  HRESULT local_68;
  ULONG local_50;
  ULONG local_4c;
  ULONG local_2c;
  ULONG local_28;
  int local_c;
  
                    /* 0xc008  111  VarDecFromR4 */
  uVar2 = in_a0 >> 0x17 & 0xff;
  iVar3 = uVar2 - 0x7e;
  if (iVar3 < -0x5e) {
    (pdecOut->u2).s2.Lo32 = 0;
    (pdecOut->u2).s2.Mid32 = 0;
    pdecOut->Hi32 = 0;
    (pdecOut->u).signscale = 0;
    local_68 = 0;
  }
  else if (iVar3 < 0x61) {
    (pdecOut->u).s.sign = (byte)(in_a0 >> 0x18) & 0x80;
    if (iVar3 < 0x18) {
      uVar6 = __fptodp(in_a0);
      uVar7 = uVar6 & 0x7fffffffffffffff;
      local_78 = 0;
      if (iVar3 < 0x14) {
        local_78 = (0x14 - iVar3) * 0x4d10 + 0xffff >> 0x10;
        if (0x1c < local_78) {
          local_78 = 0x1c;
        }
        uVar7 = __dpmul((int)uVar6,(uint)(uVar6 >> 0x20) & 0x7fffffff,
                        *(undefined4 *)(&DAT_40441210 + local_78 * 8),
                        *(undefined4 *)(&DAT_40441214 + local_78 * 8));
      }
      local_7c = (undefined4)(uVar7 >> 0x20);
      local_80 = (undefined4)uVar7;
      iVar3 = __ltd(local_80,local_7c,0,0x412e8480);
      if ((iVar3 != 0) && (local_78 < 0x1c)) {
        uVar7 = __dpmul(local_80,local_7c,0,0x40240000);
        local_78 = local_78 + 1;
      }
      local_7c = (undefined4)(uVar7 >> 0x20);
      local_80 = (undefined4)uVar7;
      local_88 = __dptoli(local_80,local_7c);
      uVar8 = __ultodp(local_88);
      uVar8 = __dpsub(local_80,local_7c,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20));
      uVar1 = (undefined4)((ulonglong)uVar8 >> 0x20);
      iVar3 = __gtd((int)uVar8,uVar1,0,0x3fe00000);
      if ((iVar3 != 0) ||
         ((iVar3 = __eqd((int)uVar8,uVar1,0,0x3fe00000), iVar3 != 0 && ((local_88 & 1) != 0)))) {
        local_88 = local_88 + 1;
      }
      if (local_88 == 0) {
        local_78 = 0;
        (pdecOut->u).s.sign = '\0';
      }
      if (local_78 < 6) {
        local_c = local_78;
      }
      else {
        local_c = 6;
      }
      local_84 = local_c;
      for (local_98 = 4; local_98 != 0; local_98 = local_98 >> 1) {
        if (local_98 <= local_84) {
          uVar8 = FUN_4044bd5c(local_88,*(uint *)(&DAT_40441050 + local_98 * 4));
          local_8c = (int)((ulonglong)uVar8 >> 0x20);
          if (local_8c == 0) {
            local_90 = (uint)uVar8;
            local_88 = local_90;
            local_78 = local_78 - local_98;
            local_84 = local_84 - local_98;
          }
        }
      }
      (pdecOut->u2).s2.Lo32 = local_88;
      (pdecOut->u2).s2.Mid32 = 0;
      pdecOut->Hi32 = 0;
      (pdecOut->u).s.scale = (BYTE)local_78;
      local_68 = 0;
    }
    else {
      uVar4 = in_a0 & 0x7fffff | 0x800000;
      (pdecOut->u).s.scale = '\0';
      if (iVar3 < 0x38) {
        uVar5 = uVar2 - 0x96;
        uVar2 = uVar2 - 0xb6;
        if ((int)uVar2 < 0) {
          local_50 = uVar4 << (uVar5 & 0x1f);
          if (uVar5 == 0) {
            local_4c = 0;
          }
          else {
            local_4c = 0 << (uVar5 & 0x1f) | uVar4 >> (-uVar2 & 0x1f);
          }
        }
        else {
          local_50 = 0;
          local_4c = uVar4 << (uVar2 & 0x1f);
        }
        (pdecOut->u2).s2.Lo32 = local_50;
        (pdecOut->u2).s2.Mid32 = local_4c;
        pdecOut->Hi32 = 0;
      }
      else {
        (pdecOut->u2).s2.Lo32 = 0;
        if (iVar3 < 0x58) {
          uVar5 = uVar2 - 0xb6;
          uVar2 = uVar2 - 0xd6;
          if ((int)uVar2 < 0) {
            local_2c = uVar4 << (uVar5 & 0x1f);
            if (uVar5 == 0) {
              local_28 = 0;
            }
            else {
              local_28 = 0 << (uVar5 & 0x1f) | uVar4 >> (-uVar2 & 0x1f);
            }
          }
          else {
            local_2c = 0;
            local_28 = uVar4 << (uVar2 & 0x1f);
          }
          (pdecOut->u2).s2.Mid32 = local_2c;
          pdecOut->Hi32 = local_28;
        }
        else {
          (pdecOut->u2).s2.Mid32 = 0;
          pdecOut->Hi32 = uVar4 << (uVar2 - 0xd6 & 0x1f);
        }
      }
      local_68 = 0;
    }
  }
  else {
    local_68 = -0x7ffdfff6;
  }
  return local_68;
}



/* 4044c604 VarDecFromR8 */

/* Boundary evidence: original MIPS .pdata 4044c604..4044cd93. Semantic name remains unreviewed. */

HRESULT VarDecFromR8(DOUBLE dblIn,DECIMAL *pdecOut)

{
  undefined4 uVar1;
  uint in_a0;
  uint in_a1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  _struct_1698 _Var6;
  ULONG local_e0;
  int local_dc;
  undefined8 local_d0;
  int local_c8;
  uint local_c0;
  uint local_bc;
  ULONG local_b8;
  uint local_b4;
  int local_b0;
  HRESULT local_90;
  ULONG local_78;
  ULONG local_74;
  uint local_54;
  ULONG local_50;
  ULONG local_30;
  ULONG local_2c;
  int local_14;
  
                    /* 0xc604  112  VarDecFromR8 */
  uVar2 = in_a1 >> 0x14 & 0x7ff;
  iVar3 = uVar2 - 0x3fe;
  if (iVar3 < -0x5e) {
    (pdecOut->u2).s2.Lo32 = 0;
    (pdecOut->u2).s2.Mid32 = 0;
    pdecOut->Hi32 = 0;
    (pdecOut->u).signscale = 0;
    local_90 = 0;
  }
  else if (iVar3 < 0x61) {
    (pdecOut->u).s.sign = (byte)(in_a1 >> 0x18) & 0x80;
    if (iVar3 < 0x35) {
      local_bc = in_a1 & 0x7fffffff;
      local_b0 = 0;
      local_c0 = in_a0;
      if (iVar3 < 0x2e) {
        local_b0 = (0x2e - iVar3) * 0x4d10 + 0xffff >> 0x10;
        if (0x1c < local_b0) {
          local_b0 = 0x1c;
        }
        uVar5 = __dpmul(in_a0,local_bc,*(undefined4 *)(&DAT_40441210 + local_b0 * 8),
                        *(undefined4 *)(&DAT_40441214 + local_b0 * 8));
        local_bc = (uint)((ulonglong)uVar5 >> 0x20);
        local_c0 = (uint)uVar5;
      }
      iVar3 = __ltd(local_c0,local_bc,0x1e900000,0x42d6bcc4);
      uVar5 = CONCAT44(local_bc,local_c0);
      if ((iVar3 != 0) && (uVar5 = CONCAT44(local_bc,local_c0), local_b0 < 0x1c)) {
        uVar5 = __dpmul(local_c0,local_bc,0,0x40240000);
        local_b0 = local_b0 + 1;
      }
      local_bc = (uint)((ulonglong)uVar5 >> 0x20);
      local_c0 = (uint)uVar5;
      _Var6 = (_struct_1698)__d_to_ll(local_c0,local_bc);
      uVar5 = __ll_to_d(_Var6.Lo32,_Var6.Mid32);
      uVar5 = __dpsub(local_c0,local_bc,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      uVar1 = (undefined4)((ulonglong)uVar5 >> 0x20);
      iVar3 = __gtd((int)uVar5,uVar1,0,0x3fe00000);
      if ((iVar3 != 0) ||
         ((iVar3 = __eqd((int)uVar5,uVar1,0,0x3fe00000), iVar3 != 0 && (((ulonglong)_Var6 & 1) != 0)
          ))) {
        _Var6 = (_struct_1698)((longlong)_Var6 + 1);
      }
      if (_Var6 == (_struct_1698)0x0) {
        local_b0 = 0;
        (pdecOut->u).s.sign = '\0';
      }
      if (local_b0 < 0xe) {
        local_14 = local_b0;
      }
      else {
        local_14 = 0xe;
      }
      local_c8 = local_14;
      local_dc = 8;
      while( true ) {
        local_b4 = _Var6.Mid32;
        local_b8 = _Var6.Lo32;
        if (local_dc == 0) break;
        if (local_dc <= local_c8) {
          uVar2 = *(uint *)(&DAT_40441050 + local_dc * 4);
          if (local_b4 < uVar2) {
            local_e0 = 0;
            local_d0 = FUN_4044bd88(local_b8,local_b4,uVar2);
          }
          else {
            uVar5 = FUN_4044bd88(local_b4,0,uVar2);
            local_d0._0_4_ = (ULONG)uVar5;
            local_e0 = (ULONG)local_d0;
            local_d0._4_4_ = (int)((ulonglong)uVar5 >> 0x20);
            local_d0 = FUN_4044bd88(local_b8,local_d0._4_4_,uVar2);
          }
          if (local_d0._4_4_ == 0) {
            _Var6.Mid32 = local_e0;
            _Var6.Lo32 = (ULONG)local_d0;
            local_b0 = local_b0 - local_dc;
            local_c8 = local_c8 - local_dc;
          }
        }
        local_dc = local_dc >> 1;
      }
      pdecOut->Hi32 = 0;
      (pdecOut->u).s.scale = (BYTE)local_b0;
      (pdecOut->u2).s2 = _Var6;
      local_90 = 0;
    }
    else {
      local_74 = in_a1 & 0xfffff | 0x100000;
      (pdecOut->u).s.scale = '\0';
      if (iVar3 < 0x41) {
        uVar4 = uVar2 - 0x433;
        uVar2 = uVar2 - 0x453;
        if ((int)uVar2 < 0) {
          local_78 = in_a0 << (uVar4 & 0x1f);
          if (uVar4 != 0) {
            local_74 = local_74 << (uVar4 & 0x1f) | in_a0 >> (-uVar2 & 0x1f);
          }
        }
        else {
          local_78 = 0;
          local_74 = in_a0 << (uVar2 & 0x1f);
        }
        (pdecOut->u2).s2.Lo32 = local_78;
        (pdecOut->u2).s2.Mid32 = local_74;
        pdecOut->Hi32 = 0;
      }
      else if (iVar3 < 0x55) {
        (pdecOut->u2).s2.Lo32 = in_a0 << (uVar2 - 0x433 & 0x1f);
        uVar4 = -iVar3 + 0x55;
        uVar2 = -iVar3 + 0x35;
        if ((int)uVar2 < 0) {
          local_50 = local_74 >> (uVar4 & 0x1f);
          local_54 = in_a0;
          if (uVar4 != 0) {
            local_54 = in_a0 >> (uVar4 & 0x1f) | local_74 << (-uVar2 & 0x1f);
          }
        }
        else {
          local_54 = local_74 >> (uVar2 & 0x1f);
          local_50 = 0;
        }
        (pdecOut->u2).s2.Mid32 = local_54;
        pdecOut->Hi32 = local_50;
      }
      else {
        (pdecOut->u2).s2.Lo32 = 0;
        uVar4 = uVar2 - 0x453;
        uVar2 = uVar2 - 0x473;
        if ((int)uVar2 < 0) {
          local_30 = in_a0 << (uVar4 & 0x1f);
          local_2c = local_74;
          if (uVar4 != 0) {
            local_2c = local_74 << (uVar4 & 0x1f) | in_a0 >> (-uVar2 & 0x1f);
          }
        }
        else {
          local_30 = 0;
          local_2c = in_a0 << (uVar2 & 0x1f);
        }
        (pdecOut->u2).s2.Mid32 = local_30;
        pdecOut->Hi32 = local_2c;
      }
      local_90 = 0;
    }
  }
  else {
    local_90 = -0x7ffdfff6;
  }
  return local_90;
}



/* 4044cd94 VarDecFromCy */

/* Boundary evidence: original MIPS .pdata 4044cd94..4044ce43. Semantic name remains unreviewed. */

HRESULT VarDecFromCy(CY cyIn,DECIMAL *pdecOut)

{
  ULONG UVar1;
  ULONG local_res0;
  ULONG local_res4;
  
                    /* 0xcd94  105  VarDecFromCy */
  local_res4 = cyIn.s.Hi;
  UVar1 = cyIn.s.Lo;
  (pdecOut->u).s.sign = cyIn.s.Hi._3_1_ & 0x80;
  local_res0 = UVar1;
  if ((pdecOut->u).s.sign != '\0') {
    local_res0 = -UVar1;
    local_res4 = -(uint)(UVar1 != 0) - local_res4;
  }
  (pdecOut->u2).s2.Lo32 = local_res0;
  (pdecOut->u2).s2.Mid32 = local_res4;
  (pdecOut->u).s.scale = '\x04';
  pdecOut->Hi32 = 0;
  return 0;
}



/* 4044ce44 VarDecFromDate */

/* Boundary evidence: original MIPS .pdata 4044ce44..4044ce87. Semantic name remains unreviewed. */

HRESULT VarDecFromDate(DATE dateIn,DECIMAL *pdecOut)

{
  HRESULT HVar1;
  
                    /* 0xce44  106  VarDecFromDate */
  HVar1 = VarDecFromR8(dateIn,pdecOut);
  return HVar1;
}



/* 4044ce88 VarDecFromStr */

/* Boundary evidence: original MIPS .pdata 4044ce88..4044cfaf. Semantic name remains unreviewed. */

HRESULT VarDecFromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,DECIMAL *pdecOut)

{
  BYTE aBStack_68 [32];
  NUMPARSE local_48;
  _union_2683 local_30;
  HRESULT local_20;
  HRESULT local_1c;
  uint local_18;
  HRESULT local_10;
  
                    /* 0xce88  113  VarDecFromStr */
  local_18 = DAT_4046d1b8;
  local_48.cDig = 0x1e;
  local_48.dwInFlags = 0x1fff;
  local_20 = VarParseNumFromStr(strIn,lcid,dwFlags,&local_48,aBStack_68);
  if ((local_20 == 0) || (-1 < local_20)) {
    local_1c = VarNumFromParseNum(&local_48,aBStack_68,0x4000,(VARIANT *)&local_30.n2);
    if ((local_1c == 0) || (-1 < local_1c)) {
      pdecOut->wReserved = local_30._0_2_;
      pdecOut->u = (_union_1695)local_30.n2.wReserved1;
      pdecOut->Hi32 = local_30.decVal.Hi32;
      (pdecOut->u2).s2.Lo32 = local_30._8_4_;
      (pdecOut->u2).s2.Mid32 = local_30._12_4_;
      FUN_4046ace8(local_18);
      local_10 = 0;
    }
    else {
      FUN_4046ace8(local_18);
      local_10 = local_1c;
    }
  }
  else {
    FUN_4046ace8(local_18);
    local_10 = local_20;
  }
  return local_10;
}



/* 4044cfb0 VarDecFromDisp */

/* Boundary evidence: original MIPS .pdata 4044cfb0..4044d02b. Semantic name remains unreviewed. */

HRESULT VarDecFromDisp(IDispatch *pdispIn,LCID lcid,DECIMAL *pdecOut)

{
  int iVar1;
  _union_2683 local_20;
  
                    /* 0xcfb0  107  VarDecFromDisp */
  iVar1 = FUN_4044665c(pdispIn,lcid,0xe,(VARIANTARG *)&local_20.n2);
  if (iVar1 == 0) {
    pdecOut->wReserved = local_20._0_2_;
    pdecOut->u = (_union_1695)local_20.n2.wReserved1;
    pdecOut->Hi32 = local_20.decVal.Hi32;
    (pdecOut->u2).s2.Lo32 = local_20._8_4_;
    (pdecOut->u2).s2.Mid32 = local_20._12_4_;
  }
  return iVar1;
}



/* 4044d02c VarDecFromBool */

/* Boundary evidence: original MIPS .pdata 4044d02c..4044d09f. Semantic name remains unreviewed. */

HRESULT VarDecFromBool(VARIANT_BOOL boolIn,DECIMAL *pdecOut)

{
                    /* 0xd02c  104  VarDecFromBool */
  (pdecOut->u2).s2.Lo32 = 0;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).signscale = 0;
  if (boolIn != 0) {
    (pdecOut->u2).s2.Lo32 = 1;
    (pdecOut->u).s.sign = 0x80;
  }
  return 0;
}



/* 4044d0a0 VarDecFromI1 */

/* Boundary evidence: original MIPS .pdata 4044d0a0..4044d10b. Semantic name remains unreviewed. */

HRESULT VarDecFromI1(CHAR cIn,DECIMAL *pdecOut)

{
  uint uVar1;
  
                    /* 0xd0a0  108  VarDecFromI1 */
  uVar1 = (int)cIn >> 0x1f;
  (pdecOut->u2).s2.Lo32 = ((int)cIn ^ uVar1) - uVar1 & 0xffff;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).s.sign = cIn & 0x80;
  (pdecOut->u).s.scale = '\0';
  return 0;
}



/* 4044d10c VarDecFromUI2 */

/* Boundary evidence: original MIPS .pdata 4044d10c..4044d153. Semantic name remains unreviewed. */

HRESULT VarDecFromUI2(USHORT uiIn,DECIMAL *pdecOut)

{
                    /* 0xd10c  115  VarDecFromUI2 */
  *(uint *)&pdecOut->u2 = (uint)uiIn;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).signscale = 0;
  return 0;
}



/* 4044d154 VarDecFromUI4 */

/* Boundary evidence: original MIPS .pdata 4044d154..4044d19b. Semantic name remains unreviewed. */

HRESULT VarDecFromUI4(ULONG ulIn,DECIMAL *pdecOut)

{
                    /* 0xd154  116  VarDecFromUI4 */
  (pdecOut->u2).s2.Lo32 = ulIn;
  (pdecOut->u2).s2.Mid32 = 0;
  pdecOut->Hi32 = 0;
  (pdecOut->u).signscale = 0;
  return 0;
}



/* 4044d19c VarR8FromDec */

/* Boundary evidence: original MIPS .pdata 4044d19c..4044d3cb. Semantic name remains unreviewed. */

HRESULT VarR8FromDec(DECIMAL *pdecIn,DOUBLE *pdblOut)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 local_30;
  uint local_2c;
  
                    /* 0xd19c  174  VarR8FromDec */
  if ((int)(pdecIn->u2).s2.Mid32 < 0) {
    uVar2 = __ll_to_d((pdecIn->u2).s2.Lo32,(pdecIn->u2).s2.Mid32);
    uVar2 = __dpadd(0,0x43f00000,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    uVar3 = __ultodp(pdecIn->Hi32);
    uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x43f00000);
    uVar2 = __dpadd((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,
                    (int)((ulonglong)uVar3 >> 0x20));
    iVar1 = (uint)(pdecIn->u).s.scale * 8;
    uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),
                    *(undefined4 *)(&DAT_40441210 + iVar1),*(undefined4 *)(&DAT_40441214 + iVar1));
  }
  else {
    uVar2 = __ll_to_d((pdecIn->u2).s2.Lo32,(pdecIn->u2).s2.Mid32);
    uVar3 = __ultodp(pdecIn->Hi32);
    uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,0x43f00000);
    uVar2 = __dpadd((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,
                    (int)((ulonglong)uVar3 >> 0x20));
    iVar1 = (uint)(pdecIn->u).s.scale * 8;
    uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),
                    *(undefined4 *)(&DAT_40441210 + iVar1),*(undefined4 *)(&DAT_40441214 + iVar1));
  }
  local_2c = (uint)((ulonglong)uVar2 >> 0x20);
  local_30 = (undefined4)uVar2;
  if ((pdecIn->u).s.sign != '\0') {
    local_2c = local_2c ^ 0x80000000;
  }
  *(undefined4 *)pdblOut = local_30;
  *(uint *)((int)pdblOut + 4) = local_2c;
  return 0;
}



/* 4044d3cc VarCyFromDec */

/* Boundary evidence: original MIPS .pdata 4044d3cc..4044da07. Semantic name remains unreviewed. */

HRESULT VarCyFromDec(DECIMAL *pdecIn,CY *pcyOut)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ULONG UVar6;
  ULONG UVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  uint local_78;
  uint local_74;
  uint local_70;
  undefined8 local_68;
  HRESULT local_28;
  int local_14;
  
                    /* 0xd3cc  79  VarCyFromDec */
  uVar4 = (uint)(pdecIn->u).s.scale;
  iVar5 = uVar4 - 4;
  if (iVar5 == 0) {
    if ((pdecIn->Hi32 == 0) &&
       (((pdecIn->u2).s2.Mid32 < 0x80000000 ||
        ((((pdecIn->u2).s2.Lo32 == 0 && ((pdecIn->u2).s2.Mid32 == 0x80000000)) &&
         ((pdecIn->u).s.sign != '\0')))))) {
      if ((pdecIn->u).s.sign == '\0') {
        (pcyOut->s).Lo = (pdecIn->u2).s2.Lo32;
        (pcyOut->s).Hi = (pdecIn->u2).s2.Mid32;
      }
      else {
        UVar6 = (pdecIn->u2).s2.Lo32;
        UVar7 = (pdecIn->u2).s2.Mid32;
        (pcyOut->s).Lo = -UVar6;
        (pcyOut->s).Hi = -(uint)(UVar6 != 0) - UVar7;
      }
      local_28 = 0;
    }
    else {
      local_28 = -0x7ffdfff6;
    }
  }
  else {
    if (iVar5 < 0) {
      lVar8 = FUN_4044bdfc(*(uint *)(&DAT_40441050 + iVar5 * -4),(pdecIn->u2).s2.Mid32);
      lVar9 = FUN_4044bdfc(*(uint *)(&DAT_40441050 + iVar5 * -4),(pdecIn->u2).s2.Lo32);
      local_68._4_4_ = (uint)((ulonglong)lVar9 >> 0x20);
      local_78 = (uint)lVar8;
      local_68._4_4_ = local_68._4_4_ + local_78;
      local_68._0_4_ = (uint)lVar9;
      if (((pdecIn->Hi32 != 0) || (local_74 = (uint)((ulonglong)lVar8 >> 0x20), local_74 != 0)) ||
         (local_68._4_4_ < local_78)) {
        return -0x7ffdfff6;
      }
    }
    else if (iVar5 < 10) {
      uVar4 = *(uint *)(&DAT_40441050 + iVar5 * 4);
      if (uVar4 <= pdecIn->Hi32) {
        return -0x7ffdfff6;
      }
      uVar10 = FUN_4044bd88((pdecIn->u2).s2.Mid32,pdecIn->Hi32,uVar4);
      local_78 = (uint)uVar10;
      uVar2 = local_78;
      local_74 = (uint)((ulonglong)uVar10 >> 0x20);
      uVar11 = FUN_4044bd88((pdecIn->u2).s2.Lo32,local_74,uVar4);
      local_78 = (uint)uVar11;
      local_68 = CONCAT44(uVar2,local_78);
      local_74 = (uint)(uVar11 >> 0x20);
      if ((uVar4 >> 1 < local_74) || ((local_74 == uVar4 >> 1 && ((uVar11 & 1) != 0)))) {
        local_68 = CONCAT44(uVar2 + (local_78 + 1 < local_78),local_78 + 1);
      }
    }
    else {
      bVar1 = pdecIn->Hi32 < 2500000000;
      if (bVar1) {
        UVar6 = pdecIn->Hi32;
      }
      else {
        UVar6 = pdecIn->Hi32 + 0x6afd0700;
      }
      local_68._4_4_ = (uint)!bVar1;
      uVar10 = FUN_4044bd88((pdecIn->u2).s2.Mid32,UVar6,2500000000);
      local_78 = (uint)uVar10;
      local_74 = (uint)((ulonglong)uVar10 >> 0x20);
      uVar10 = FUN_4044bd88((pdecIn->u2).s2.Lo32,local_74,2500000000);
      if ((int)(uVar4 - 0xe) < 9) {
        local_14 = uVar4 - 0xe;
      }
      else {
        local_14 = 9;
      }
      local_70 = *(int *)(&DAT_40441050 + local_14 * 4) << 2;
      uVar12 = FUN_4044bd88(local_78,local_68._4_4_,local_70);
      local_68._0_4_ = (uint)uVar12;
      uVar3 = (uint)local_68;
      local_78 = (uint)uVar10;
      local_68._4_4_ = (uint)((ulonglong)uVar12 >> 0x20);
      uVar12 = FUN_4044bd88(local_78,local_68._4_4_,local_70);
      local_68._4_4_ = (uint)((ulonglong)uVar12 >> 0x20);
      uVar2 = local_68._4_4_;
      local_74 = (uint)((ulonglong)uVar10 >> 0x20);
      local_78 = local_68._4_4_;
      local_68._0_4_ = (uint)uVar12;
      local_68 = CONCAT44(uVar3,(uint)local_68);
      if (0x13 < iVar5) {
        local_70 = *(uint *)(&DAT_40441050 + (uVar4 - 0x17) * 4);
        uVar11 = FUN_4044bd88((uint)local_68,uVar3,local_70);
        local_74 = local_74 | uVar2;
        local_68._4_4_ = (uint)(uVar11 >> 0x20);
        local_78 = local_68._4_4_;
        local_68 = uVar11 & 0xffffffff;
      }
      if ((local_70 >> 1 < local_78) ||
         ((local_78 == local_70 >> 1 && (((local_68 & 1) != 0 || (local_74 != 0)))))) {
        local_68 = CONCAT44(local_68._4_4_ + ((uint)local_68 + 1 < (uint)local_68),
                            (uint)local_68 + 1);
      }
    }
    if ((local_68._4_4_ < 0x80000000) ||
       ((((uint)local_68 == 0 && (local_68._4_4_ == 0x80000000)) && ((pdecIn->u).s.sign != '\0'))))
    {
      if ((pdecIn->u).s.sign != '\0') {
        local_68 = CONCAT44(-(uint)((uint)local_68 != 0) - local_68._4_4_,-(uint)local_68);
      }
      (pcyOut->s).Lo = (uint)local_68;
      (pcyOut->s).Hi = local_68._4_4_;
      local_28 = 0;
    }
    else {
      local_28 = -0x7ffdfff6;
    }
  }
  return local_28;
}



/* 4044da08 VarDateFromDec */

/* Boundary evidence: original MIPS .pdata 4044da08..4044dab7. Semantic name remains unreviewed. */

HRESULT VarDateFromDec(DECIMAL *pdecIn,DATE *pdateOut)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  HRESULT local_10;
  
                    /* 0xda08  92  VarDateFromDec */
  VarR8FromDec(pdecIn,(DOUBLE *)&local_18);
  iVar1 = __ged(local_18,local_14,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(local_18,local_14,0,0xc1241036), iVar1 == 0)) {
    *(undefined4 *)pdateOut = local_18;
    *(undefined4 *)((int)pdateOut + 4) = local_14;
    local_10 = 0;
  }
  else {
    local_10 = -0x7ffdfffb;
  }
  return local_10;
}



/* 4044dab8 VarBstrFromDec */

/* Boundary evidence: original MIPS .pdata 4044dab8..4044df6f. Semantic name remains unreviewed. */

HRESULT VarBstrFromDec(DECIMAL *pdecIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  short *_Src;
  short *local_b8;
  int local_b0;
  short *local_ac;
  UINT local_a8;
  short local_58;
  short sStack_56;
  BSTR local_54;
  ULONG local_50;
  ULONG local_4c;
  undefined8 local_48;
  ULONG local_40;
  undefined4 local_3c;
  int local_38;
  uint local_18;
  HRESULT local_14;
  _union_1697 *local_10;
  
                    /* 0xdab8  67  VarBstrFromDec */
  local_18 = DAT_4046d1b8;
  local_ac = &sStack_56;
  local_b8 = &local_58;
  local_10 = &pdecIn->u2;
  local_50 = (local_10->s2).Lo32;
  local_4c = (pdecIn->u2).s2.Mid32;
  local_40 = pdecIn->Hi32;
  local_3c = 0;
  do {
    if (local_40 == 0) {
      local_48 = 0;
    }
    else {
      local_48 = FUN_4044bd88(local_40,local_3c,1000000000);
      local_40 = (ULONG)local_48;
    }
    local_48 = CONCAT44(local_48._4_4_,local_4c);
    if (local_4c != 0 || local_48._4_4_ != 0) {
      local_48 = FUN_4044bd88(local_4c,local_48._4_4_,1000000000);
      local_4c = (ULONG)local_48;
    }
    local_48 = CONCAT44(local_48._4_4_,local_50);
    local_48 = FUN_4044bd88(local_50,local_48._4_4_,1000000000);
    local_50 = (ULONG)local_48;
    for (local_b0 = 0; local_b0 < 9; local_b0 = local_b0 + 1) {
      local_ac = local_ac + -1;
      *local_ac = (short)(local_48._4_4_ % 10) + 0x30;
      local_48 = CONCAT44(local_48._4_4_ / 10,(ULONG)local_48);
    }
  } while ((local_50 != 0 || local_4c != 0) || (local_40 != 0));
  _Src = &sStack_56 + -(uint)(pdecIn->u).s.scale;
  if (_Src < local_ac) {
    FUN_4044be10(_Src,0x30,(int)local_ac - (int)_Src >> 1);
    local_ac = _Src;
  }
  else {
    local_ac = FUN_4044be64(local_ac,0x30,(int)_Src - (int)local_ac >> 1);
  }
  for (; (*local_b8 == 0x30 && (_Src <= local_b8)); local_b8 = local_b8 + -1) {
  }
  local_a8 = 1;
  if (_Src <= local_b8) {
    local_38 = FUN_404442a8(lcid,dwFlags);
    if ((local_38 != 0) && (local_38 < 0)) {
      FUN_4046ace8(local_18);
      return local_38;
    }
    local_a8 = 2;
    if ((local_ac == _Src) && (DAT_4046d1f6 != 0)) {
      local_ac = local_ac + -1;
      *local_ac = 0x30;
    }
  }
  local_a8 = local_a8 + ((int)local_b8 - (int)local_ac >> 1);
  if (local_a8 == 0) {
    local_ac = local_ac + -1;
    *local_ac = 0x30;
    local_a8 = 1;
  }
  else if ((pdecIn->u).s.sign != '\0') {
    local_ac = local_ac + -1;
    *local_ac = 0x2d;
    local_a8 = local_a8 + 1;
  }
  local_54 = SysAllocStringLen((OLECHAR *)0x0,local_a8);
  if (local_54 == (BSTR)0x0) {
    FUN_4046ace8(local_18);
    local_14 = -0x7ff8fff2;
  }
  else {
    *pbstrOut = local_54;
    memcpy(local_54,local_ac,((int)_Src - (int)local_ac >> 1) << 1);
    if (_Src <= local_b8) {
      local_54 = local_54 + ((int)_Src - (int)local_ac >> 1);
      *local_54 = DAT_4046d1f0;
      memcpy(local_54 + 1,_Src,(((int)local_b8 - (int)_Src >> 1) + 1) * 2);
    }
    FUN_4046ace8(local_18);
    local_14 = 0;
  }
  return local_14;
}



/* 4044df70 VarBoolFromDec */

/* Boundary evidence: original MIPS .pdata 4044df70..4044dfd7. Semantic name remains unreviewed. */

HRESULT VarBoolFromDec(DECIMAL *pdecIn,VARIANT_BOOL *pboolOut)

{
                    /* 0xdf70  53  VarBoolFromDec */
  if ((pdecIn->Hi32 == 0 && (pdecIn->u2).s2.Mid32 == 0) && (pdecIn->u2).s2.Lo32 == 0) {
    *pboolOut = 0;
  }
  else {
    *pboolOut = -1;
  }
  return 0;
}



/* 4044dfd8 VarI1FromDec */

/* Boundary evidence: original MIPS .pdata 4044dfd8..4044e0fb. Semantic name remains unreviewed. */

HRESULT VarI1FromDec(DECIMAL *pdecIn,CHAR *pcOut)

{
  DOUBLE in_f12_13;
  uint local_20;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xdfd8  120  VarI1FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    if (((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) {
      local_20 = (pdecIn->u2).s2.Lo32;
      if ((local_20 < 0x80) || ((local_20 == 0x80 && ((pdecIn->u).s.sign != '\0')))) {
        if ((pdecIn->u).s.sign != '\0') {
          local_20 = -local_20;
        }
        *pcOut = (CHAR)local_20;
        local_10 = 0;
      }
      else {
        local_10 = -0x7ffdfff6;
      }
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarI1FromR8(in_f12_13,pcOut);
  }
  return local_10;
}



/* 4044e0fc VarUI1FromDec */

/* Boundary evidence: original MIPS .pdata 4044e0fc..4044e1ef. Semantic name remains unreviewed. */

HRESULT VarUI1FromDec(DECIMAL *pdecIn,BYTE *pbOut)

{
  uint uVar1;
  DOUBLE in_f12_13;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xe0fc  187  VarUI1FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    uVar1 = (pdecIn->u2).s2.Lo32;
    if (((((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) && ((uVar1 & 0xffffff00) == 0)) &&
       (((pdecIn->u).s.sign == '\0' || (uVar1 == 0)))) {
      *pbOut = (BYTE)uVar1;
      local_10 = 0;
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarUI1FromR8(in_f12_13,pbOut);
  }
  return local_10;
}



/* 4044e1f0 VarI2FromDec */

/* Boundary evidence: original MIPS .pdata 4044e1f0..4044e317. Semantic name remains unreviewed. */

HRESULT VarI2FromDec(DECIMAL *pdecIn,SHORT *psOut)

{
  DOUBLE in_f12_13;
  uint local_20;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xe1f0  133  VarI2FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    if (((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) {
      local_20 = (pdecIn->u2).s2.Lo32;
      if ((local_20 < 0x8000) || ((local_20 == 0x8000 && ((pdecIn->u).s.sign != '\0')))) {
        if ((pdecIn->u).s.sign != '\0') {
          local_20 = -local_20;
        }
        *psOut = (SHORT)local_20;
        local_10 = 0;
      }
      else {
        local_10 = -0x7ffdfff6;
      }
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarI2FromR8(in_f12_13,psOut);
  }
  return local_10;
}



/* 4044e318 VarUI2FromDec */

/* Boundary evidence: original MIPS .pdata 4044e318..4044e407. Semantic name remains unreviewed. */

HRESULT VarUI2FromDec(DECIMAL *pdecIn,USHORT *puiOut)

{
  uint uVar1;
  DOUBLE in_f12_13;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xe318  200  VarUI2FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    uVar1 = (pdecIn->u2).s2.Lo32;
    if (((((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) && ((uVar1 & 0xffff0000) == 0)) &&
       (((pdecIn->u).s.sign == '\0' || (uVar1 == 0)))) {
      *puiOut = (USHORT)uVar1;
      local_10 = 0;
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarUI2FromR8(in_f12_13,puiOut);
  }
  return local_10;
}



/* 4044e408 VarI4FromDec */

/* Boundary evidence: original MIPS .pdata 4044e408..4044e527. Semantic name remains unreviewed. */

HRESULT VarI4FromDec(DECIMAL *pdecIn,LONG *plOut)

{
  DOUBLE in_f12_13;
  uint local_20;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xe408  146  VarI4FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    if (((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) {
      local_20 = (pdecIn->u2).s2.Lo32;
      if ((local_20 < 0x80000000) || ((local_20 == 0x80000000 && ((pdecIn->u).s.sign != '\0')))) {
        if ((pdecIn->u).s.sign != '\0') {
          local_20 = -local_20;
        }
        *plOut = local_20;
        local_10 = 0;
      }
      else {
        local_10 = -0x7ffdfff6;
      }
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarI4FromR8(in_f12_13,plOut);
  }
  return local_10;
}



/* 4044e528 VarUI4FromDec */

/* Boundary evidence: original MIPS .pdata 4044e528..4044e5fb. Semantic name remains unreviewed. */

HRESULT VarUI4FromDec(DECIMAL *pdecIn,ULONG *pulOut)

{
  DOUBLE in_f12_13;
  DOUBLE local_18;
  HRESULT local_10;
  
                    /* 0xe528  213  VarUI4FromDec */
  if ((pdecIn->u).s.scale == '\0') {
    if ((((pdecIn->u2).s2.Mid32 == 0) && (pdecIn->Hi32 == 0)) &&
       (((pdecIn->u).s.sign == '\0' || ((pdecIn->u2).s2.Lo32 == 0)))) {
      *pulOut = (pdecIn->u2).s2.Lo32;
      local_10 = 0;
    }
    else {
      local_10 = -0x7ffdfff6;
    }
  }
  else {
    VarR8FromDec(pdecIn,&local_18);
    local_10 = VarUI4FromR8(in_f12_13,pulOut);
  }
  return local_10;
}



/* 4044e5fc VarR4FromDec */

/* Boundary evidence: original MIPS .pdata 4044e5fc..4044e64f. Semantic name remains unreviewed. */

HRESULT VarR4FromDec(DECIMAL *pdecIn,FLOAT *pfltOut)

{
  FLOAT FVar1;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0xe5fc  161  VarR4FromDec */
  VarR8FromDec(pdecIn,(DOUBLE *)&local_18);
  FVar1 = (FLOAT)__dptofp(local_18,local_14);
  *pfltOut = FVar1;
  return 0;
}



/* 4044e650 FUN_4044e650 */

/* Boundary evidence: original MIPS .pdata 4044e650..4044e69f. Semantic name remains unreviewed. */

ushort FUN_4044e650(LCID param_1,WCHAR param_2,ushort param_3)

{
  WCHAR local_10 [4];
  
  local_10[1] = 0;
  local_10[0] = param_2;
  GetStringTypeExW(param_1,1,local_10,-1,(LPWORD)(local_10 + 2));
  return local_10[2] & param_3;
}



/* 4044e6a0 FUN_4044e6a0 */

/* Boundary evidence: original MIPS .pdata 4044e6a0..4044e73b. Semantic name remains unreviewed. */

size_t FUN_4044e6a0(PCNZWCH param_1,uint param_2,wchar_t *param_3)

{
  size_t cchCount1;
  int iVar1;
  
  cchCount1 = wcslen(param_3);
  if (((cchCount1 != 0) && (cchCount1 <= param_2)) &&
     (iVar1 = CompareStringW(DAT_4046d1f8,1,param_1,cchCount1,param_3,cchCount1), iVar1 == 2)) {
    return cchCount1;
  }
  return 0;
}



/* 4044e73c FUN_4044e73c */

/* Boundary evidence: original MIPS .pdata 4044e73c..4044e9d7. Semantic name remains unreviewed. */

int FUN_4044e73c(PCNZWCH param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined **ppuVar4;
  PCNZWCH pWVar5;
  PCNZWCH pWVar6;
  
  if ((param_3 & 8) == 0) {
    iVar3 = 0;
    pWVar6 = (PCNZWCH)&DAT_4046dde4;
    pWVar5 = (PCNZWCH)&DAT_4046d560;
    do {
      iVar1 = CompareStringW(DAT_4046d1f8,1,param_1,param_2,pWVar5,
                             (uint)(byte)(&DAT_4046d6e0)[iVar3]);
      if ((iVar1 == 2) ||
         (((DAT_4046dae0 != 0 || (DAT_4046de44 != 0)) &&
          (iVar1 = CompareStringW(0x409,1,param_1,param_2,pWVar6,-1), iVar1 == 2))))
      goto LAB_4044e9a4;
      pWVar5 = pWVar5 + 0x10;
      iVar3 = iVar3 + 1;
      pWVar6 = pWVar6 + 4;
    } while ((int)pWVar5 < 0x4046d6e0);
    if (2 < param_2) {
      iVar3 = 0;
      pWVar5 = (PCNZWCH)&DAT_4046d260;
      iVar1 = 0;
      do {
        iVar2 = CompareStringW(DAT_4046d1f8,1,param_1,param_2,pWVar5,param_2);
        if (iVar2 == 2) {
LAB_4044e9a4:
          return iVar3 + 1;
        }
        if (DAT_4046d1f8 == 0x415) {
          pWVar6 = *(PCNZWCH *)((int)&PTR_u_stycznia_40441580 + iVar1);
LAB_4044e90c:
          iVar2 = CompareStringW(DAT_4046d1f8,1,param_1,param_2,pWVar6,param_2);
          if (iVar2 == 2) goto LAB_4044e9a4;
        }
        else if (DAT_4046d1f8 == 0x419) {
          pWVar6 = *(PCNZWCH *)((int)&PTR_DAT_404415b4 + iVar1);
          goto LAB_4044e90c;
        }
        if (((DAT_4046dae0 != 0) || (DAT_4046de44 != 0)) &&
           (iVar2 = CompareStringW(0x409,1,param_1,param_2,pWVar5 + 0x442,param_2), iVar2 == 2))
        goto LAB_4044e9a4;
        pWVar5 = pWVar5 + 0x20;
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + 4;
      } while ((int)pWVar5 < 0x4046d560);
    }
  }
  else {
    ppuVar4 = &PTR_DAT_4044154c;
    iVar3 = 0;
    do {
      iVar1 = CompareStringW(0x401,1,param_1,param_2,(PCNZWCH)*ppuVar4,param_2);
      if (iVar1 == 2) {
        return iVar3 + 1;
      }
      ppuVar4 = ppuVar4 + 1;
      iVar3 = iVar3 + 1;
    } while ((int)ppuVar4 < 0x4044157c);
  }
  return 0;
}



/* 4044e9d8 FUN_4044e9d8 */

/* Boundary evidence: original MIPS .pdata 4044e9d8..4044eb0b. Semantic name remains unreviewed. */

undefined4 FUN_4044e9d8(LCID param_1,uint param_2,LPWSTR param_3,int param_4)

{
  WCHAR WVar1;
  int iVar2;
  
  iVar2 = GetLocaleInfoW(param_1,param_2,param_3,param_4);
  if (1 < iVar2) {
    if (param_2 == 0x21) {
      if (iVar2 == 2) {
        WVar1 = *param_3;
        if (WVar1 == L'0') {
          return 0;
        }
        if (WVar1 == L'1') {
          return 0;
        }
        if (WVar1 == L'2') {
          return 0;
        }
      }
    }
    else {
      if ((param_2 != 0x23) && (param_2 != 0x25)) {
        return 0;
      }
      if (iVar2 == 2) {
        if (*param_3 == L'0') {
          return 0;
        }
        if (*param_3 == L'1') {
          return 0;
        }
      }
    }
  }
  iVar2 = GetLocaleInfoW(param_1,param_2 | 0x80000000,param_3,param_4);
  if (1 < iVar2) {
    return 0;
  }
  return 0x80004005;
}



/* 4044eb0c FUN_4044eb0c */

/* Boundary evidence: original MIPS .pdata 4044eb0c..4044ebdb. Semantic name remains unreviewed. */

int FUN_4044eb0c(void)

{
  int iVar1;
  LPWSTR pWVar2;
  LPWSTR pWVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_4046d76c == 0) {
    iVar4 = 0;
    pWVar3 = (LPWSTR)&DAT_4046d92c;
    pWVar2 = &DAT_4046d76c;
    do {
      iVar5 = (iVar4 + 6) % 7;
      iVar1 = FUN_4044e9d8(DAT_4046d1f8,iVar5 + 0x2a,pWVar2,0x20);
      if ((iVar1 != 0) && (iVar1 < 0)) {
        return iVar1;
      }
      iVar1 = FUN_4044e9d8(DAT_4046d1f8,iVar5 + 0x31,pWVar3,0x10);
      if ((iVar1 != 0) && (iVar1 < 0)) {
        return iVar1;
      }
      pWVar2 = pWVar2 + 0x20;
      iVar4 = iVar4 + 1;
      pWVar3 = pWVar3 + 0x10;
    } while ((int)pWVar2 < 0x4046d92c);
  }
  return 0;
}



/* 4044ebdc FUN_4044ebdc */

/* Boundary evidence: original MIPS .pdata 4044ebdc..4044ed07. Semantic name remains unreviewed. */

undefined4 FUN_4044ebdc(wchar_t *param_1,size_t *param_2)

{
  size_t sVar1;
  size_t sVar2;
  undefined4 uVar3;
  
  sVar1 = wcslen(param_1);
  if ((((DAT_4046d25c == 0) &&
       (sVar2 = FUN_4044e6a0(param_1,sVar1,(wchar_t *)&DAT_4046daac), sVar2 != 0)) ||
      (sVar2 = FUN_4044e6a0(param_1,sVar1,DAT_4046daa4), sVar2 != 0)) ||
     (sVar2 = FUN_4044e6a0(param_1,sVar1,L"am"), sVar2 != 0)) {
    uVar3 = 1;
  }
  else {
    if (((DAT_4046d25c != 0) ||
        (sVar2 = FUN_4044e6a0(param_1,sVar1,(wchar_t *)&DAT_4046dac4), sVar2 == 0)) &&
       ((sVar2 = FUN_4044e6a0(param_1,sVar1,DAT_4046daa8), sVar2 == 0 &&
        (sVar2 = FUN_4044e6a0(param_1,sVar1,L"pm"), sVar2 == 0)))) {
      return 0;
    }
    uVar3 = 2;
  }
  *param_2 = sVar2;
  return uVar3;
}



/* 4044ed08 FUN_4044ed08 */

/* Boundary evidence: original MIPS .pdata 4044ed08..4044f1f7. Semantic name remains unreviewed. */

undefined4 FUN_4044ed08(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar2;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  size_t sVar3;
  size_t sVar4;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  wchar_t *pwVar5;
  wchar_t *_Str;
  wchar_t *pwVar6;
  undefined4 uVar7;
  WCHAR *pWVar8;
  size_t local_28 [2];
  
  _Str = (wchar_t *)*param_1;
  uVar7 = 0;
  uVar1 = FUN_4044e650(DAT_4046d1f8,*_Str,8);
  if (CONCAT22(extraout_var,uVar1) != 0) {
    while (uVar1 = FUN_4044e650(DAT_4046d1f8,*_Str,8), CONCAT22(extraout_var_00,uVar1) != 0) {
      _Str = _Str + 1;
    }
    uVar7 = 2;
  }
  pwVar6 = _Str;
  if (*_Str == L'\0') {
    uVar7 = 1;
    goto LAB_4044f1c8;
  }
  if ((DAT_4046dae0 == 0) || (iVar2 = FUN_4044ebdc(_Str,local_28), iVar2 == 0)) {
    uVar1 = FUN_4044e650(DAT_4046d1f8,*_Str,0x100);
    if (CONCAT22(extraout_var_02,uVar1) == 0) {
      pwVar5 = wcschr((wchar_t *)&DAT_4046d234,*_Str);
      if (pwVar5 == (wchar_t *)0x0) {
        pwVar5 = wcschr(&DAT_4046d244,*_Str);
        if (pwVar5 == (wchar_t *)0x0) {
          pwVar5 = wcschr(L",/-",*_Str);
          if (pwVar5 != (wchar_t *)0x0) goto LAB_4044f174;
          pwVar5 = wcschr(L".:",*_Str);
          if (pwVar5 == (wchar_t *)0x0) goto LAB_4044f1c8;
        }
        uVar7 = 6;
      }
      else {
LAB_4044f174:
        uVar7 = 5;
      }
      pwVar6 = _Str + 1;
      goto LAB_4044f1c8;
    }
    sVar3 = wcslen(_Str);
    if (DAT_4046d25c == 0) {
      if (DAT_4046dae0 == 0) goto LAB_4044eeac;
      sVar4 = FUN_4044e6a0(_Str,sVar3,(wchar_t *)&DAT_4046daac);
      if (sVar4 != 0) goto LAB_4044f108;
      if (DAT_4046d25c != 0) goto LAB_4044eef0;
      if (DAT_4046dae0 == 0) {
LAB_4044eeac:
        sVar4 = FUN_4044e6a0(_Str,sVar3,&DAT_4046d204);
        if (sVar4 != 0) goto LAB_4044f108;
        if ((DAT_4046d25c != 0) || (sVar4 = FUN_4044e6a0(_Str,sVar3,&DAT_4046d21c), sVar4 == 0))
        goto LAB_4044eef0;
      }
      else {
        sVar4 = FUN_4044e6a0(_Str,sVar3,(wchar_t *)&DAT_4046dac4);
        if (sVar4 == 0) {
          if (DAT_4046d25c != 0) goto LAB_4044eef0;
          goto LAB_4044eeac;
        }
      }
LAB_4044f100:
      uVar7 = 4;
    }
    else {
LAB_4044eef0:
      sVar4 = FUN_4044e6a0(_Str,sVar3,L"am");
      if ((sVar4 == 0) &&
         ((sVar4 = FUN_4044e6a0(_Str,sVar3,L"a"), sVar4 == 0 ||
          (uVar1 = FUN_4044e650(DAT_4046d1f8,_Str[1],0x100), CONCAT22(extraout_var_03,uVar1) != 0)))
         ) {
        sVar4 = FUN_4044e6a0(_Str,sVar3,L"pm");
        if ((sVar4 == 0) &&
           ((sVar4 = FUN_4044e6a0(_Str,sVar3,L"p"), sVar4 == 0 ||
            (uVar1 = FUN_4044e650(DAT_4046d1f8,_Str[1],0x100), CONCAT22(extraout_var_04,uVar1) != 0)
            ))) {
          if (DAT_4046dae0 != 0) {
            sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046da8c);
            if (sVar4 == 0) {
              sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046da90);
              if (sVar4 == 0) {
                sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046da94);
                if (sVar4 == 0) {
                  sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046da98);
                  if (sVar4 == 0) {
                    sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046da9c);
                    if (sVar4 == 0) {
                      sVar4 = FUN_4044e6a0(_Str,sVar3,DAT_4046daa0);
                      if (sVar4 == 0) goto LAB_4044f1c8;
                      uVar7 = 0xc;
                    }
                    else {
                      uVar7 = 0xb;
                    }
                  }
                  else {
                    uVar7 = 10;
                  }
                  pwVar6 = _Str + sVar4;
                  while (uVar1 = FUN_4044e650(DAT_4046d1f8,*pwVar6,8),
                        CONCAT22(extraout_var_05,uVar1) != 0) {
                    pwVar6 = pwVar6 + 1;
                  }
                  iVar2 = FUN_4044ebdc(pwVar6,local_28);
                  if (iVar2 != 0) {
                    pWVar8 = pwVar6 + local_28[0];
                    while (uVar1 = FUN_4044e650(DAT_4046d1f8,*pWVar8,8),
                          CONCAT22(extraout_var_06,uVar1) != 0) {
                      pWVar8 = pWVar8 + 1;
                    }
                    if ((*param_2 == 0) && (*pWVar8 == L'\0')) {
                      *param_2 = iVar2;
                      pwVar6 = pWVar8;
                    }
                  }
                  goto LAB_4044f1c8;
                }
                uVar7 = 9;
              }
              else {
                uVar7 = 8;
              }
            }
            else {
              uVar7 = 7;
            }
            pwVar6 = _Str + sVar4;
          }
          goto LAB_4044f1c8;
        }
        goto LAB_4044f100;
      }
LAB_4044f108:
      uVar7 = 3;
    }
    pwVar6 = _Str + sVar4;
    if (DAT_4046dae0 == 0) goto LAB_4044f1c8;
    while (uVar1 = FUN_4044e650(DAT_4046d1f8,*pwVar6,8), CONCAT22(extraout_var_07,uVar1) != 0) {
      pwVar6 = pwVar6 + 1;
    }
    if ((*param_2 == 0) && (*pwVar6 == L'\0')) goto LAB_4044f1c8;
  }
  else {
    pwVar6 = _Str + local_28[0];
    while (uVar1 = FUN_4044e650(DAT_4046d1f8,*pwVar6,8), CONCAT22(extraout_var_01,uVar1) != 0) {
      pwVar6 = pwVar6 + 1;
    }
    if ((*param_2 == 0) && (*pwVar6 == L'\0')) {
      uVar7 = 3;
      if (iVar2 != 1) {
        uVar7 = 4;
      }
      goto LAB_4044f1c8;
    }
  }
  uVar7 = 2;
  pwVar6 = _Str;
LAB_4044f1c8:
  *param_1 = pwVar6;
  return uVar7;
}



/* 4044f1f8 FUN_4044f1f8 */

undefined4 FUN_4044f1f8(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_3 < 1) || (0x1f < param_3)) ||
      ((param_3 == 0x1f &&
       (((0 < param_2 && (param_2 < 0xd)) && (*(int *)(&DAT_404416dc + param_2 * 4) == 0)))))) ||
     ((param_2 == 2 &&
      ((param_3 == 0x1e ||
       ((param_3 == 0x1d &&
        (((param_1 & 3) != 0 || (((int)param_1 % 100 == 0 && ((int)param_1 % 400 != 0)))))))))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 4044f2b4 FUN_4044f2b4 */

/* Boundary evidence: original MIPS .pdata 4044f2b4..4044f4ef. Semantic name remains unreviewed. */

undefined4 FUN_4044f2b4(int param_1,WORD *param_2)

{
  WORD WVar1;
  undefined2 extraout_var;
  int iVar3;
  WORD WVar4;
  int iVar5;
  WORD WVar6;
  int iVar7;
  uint uVar2;
  
  iVar7 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 8);
  WVar1 = FUN_40451fcc();
  uVar2 = CONCAT22(extraout_var,WVar1);
  WVar6 = (WORD)iVar7;
  WVar4 = (WORD)iVar5;
  if (DAT_4046d200 == 0) {
    if (((0 < iVar7) && (iVar7 < 0xd)) && (iVar3 = FUN_4044f1f8(uVar2,iVar7,iVar5), iVar3 != 0)) {
LAB_4044f338:
      param_2[1] = WVar6;
LAB_4044f33c:
      *param_2 = WVar1;
      param_2[3] = WVar4;
      return 1;
    }
    if (((0 < iVar5) && (iVar5 < 0xd)) && (iVar3 = FUN_4044f1f8(uVar2,iVar5,iVar7), iVar3 != 0)) {
      param_2[1] = WVar4;
LAB_4044f374:
      *param_2 = WVar1;
      param_2[3] = WVar6;
      return 1;
    }
    if ((iVar7 < 1) || (0xc < iVar7)) {
      if (iVar5 < 1) {
        return 0;
      }
      if (0xc < iVar5) {
        return 0;
      }
      param_2[1] = WVar4;
      goto LAB_4044f4bc;
    }
  }
  else {
    if (DAT_4046d200 == 1) {
      if (((0 < iVar5) && (iVar5 < 0xd)) && (iVar3 = FUN_4044f1f8(uVar2,iVar5,iVar7), iVar3 != 0)) {
        *param_2 = WVar1;
        param_2[3] = WVar6;
LAB_4044f428:
        param_2[1] = WVar4;
        return 1;
      }
      if ((iVar7 < 1) || (0xc < iVar7)) {
        if (iVar5 < 1) {
          return 0;
        }
        if (0xc < iVar5) {
          return 0;
        }
        *param_2 = WVar6;
        param_2[3] = 1;
        goto LAB_4044f428;
      }
      iVar5 = FUN_4044f1f8(uVar2,iVar7,iVar5);
      param_2[1] = WVar6;
      if (iVar5 != 0) goto LAB_4044f33c;
      *param_2 = WVar4;
      goto LAB_4044f4c0;
    }
    if (DAT_4046d200 != 2) {
      return 0;
    }
    if (((0 < iVar7) && (iVar7 < 0xd)) && (iVar3 = FUN_4044f1f8(uVar2,iVar7,iVar5), iVar3 != 0))
    goto LAB_4044f338;
    if ((0 < iVar5) && (iVar5 < 0xd)) {
      iVar5 = FUN_4044f1f8(uVar2,iVar5,iVar7);
      param_2[1] = WVar4;
      if (iVar5 != 0) goto LAB_4044f374;
LAB_4044f4bc:
      *param_2 = WVar6;
      goto LAB_4044f4c0;
    }
    if (iVar7 < 1) {
      return 0;
    }
    if (0xc < iVar7) {
      return 0;
    }
  }
  *param_2 = WVar4;
  param_2[1] = WVar6;
LAB_4044f4c0:
  param_2[3] = 1;
  return 1;
}



/* 4044f4f0 FUN_4044f4f0 */

/* Boundary evidence: original MIPS .pdata 4044f4f0..4044f75f. Semantic name remains unreviewed. */

undefined4 FUN_4044f4f0(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  
  uVar5 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  uVar7 = *(uint *)(param_1 + 0xc);
  FUN_40451fcc();
  uVar4 = (undefined2)uVar5;
  uVar2 = (undefined2)iVar3;
  uVar6 = (undefined2)uVar7;
  if (DAT_4046d200 == 0) {
    if (((0 < (int)uVar5) && ((int)uVar5 < 0xd)) &&
       (iVar1 = FUN_4044f1f8(uVar7,uVar5,iVar3), iVar1 != 0)) {
      param_2[1] = uVar4;
      param_2[3] = uVar2;
LAB_4044f72c:
      *param_2 = uVar6;
      return 1;
    }
    if ((0 < iVar3) && (iVar3 < 0xd)) {
      iVar1 = FUN_4044f1f8(uVar5,iVar3,uVar7);
      if (iVar1 != 0) {
        *param_2 = uVar4;
        param_2[1] = uVar2;
        param_2[3] = uVar6;
        return 1;
      }
      iVar3 = FUN_4044f1f8(uVar7,iVar3,uVar5);
      if (iVar3 != 0) {
        param_2[1] = uVar2;
        param_2[3] = uVar4;
        goto LAB_4044f72c;
      }
    }
  }
  else {
    if (DAT_4046d200 != 1) {
      if (DAT_4046d200 != 2) {
        return 1;
      }
      if (((iVar3 < 1) || (0xc < iVar3)) || (iVar1 = FUN_4044f1f8(uVar5,iVar3,uVar7), iVar1 == 0)) {
        if (((0 < (int)uVar5) && ((int)uVar5 < 0xd)) &&
           (iVar1 = FUN_4044f1f8(uVar7,uVar5,iVar3), iVar1 != 0)) {
          *param_2 = uVar6;
          param_2[1] = uVar4;
          param_2[3] = uVar2;
          return 1;
        }
        if (iVar3 < 1) {
          return 0;
        }
        if (0xc < iVar3) {
          return 0;
        }
        iVar3 = FUN_4044f1f8(uVar7,iVar3,uVar5);
        if (iVar3 == 0) {
          return 0;
        }
        *param_2 = uVar6;
        param_2[3] = uVar4;
      }
      else {
        *param_2 = uVar4;
        param_2[3] = uVar6;
      }
      param_2[1] = uVar2;
      return 1;
    }
    if ((0 < iVar3) && (iVar3 < 0xd)) {
      iVar1 = FUN_4044f1f8(uVar7,iVar3,uVar5);
      if (iVar1 != 0) {
        param_2[1] = uVar2;
        param_2[3] = uVar4;
        goto LAB_4044f690;
      }
      iVar1 = FUN_4044f1f8(uVar5,iVar3,uVar7);
      if (iVar1 != 0) {
        *param_2 = uVar4;
        param_2[1] = uVar2;
        param_2[3] = uVar6;
        return 1;
      }
    }
    if (((0 < (int)uVar5) && ((int)uVar5 < 0xd)) &&
       (iVar3 = FUN_4044f1f8(uVar7,uVar5,iVar3), iVar3 != 0)) {
      param_2[1] = uVar4;
      param_2[3] = uVar2;
LAB_4044f690:
      *param_2 = uVar6;
      return 1;
    }
  }
  return 0;
}



/* 4044f760 FUN_4044f760 */

/* Boundary evidence: original MIPS .pdata 4044f760..4044f7df. Semantic name remains unreviewed. */

undefined4 FUN_4044f760(int param_1,WORD *param_2)

{
  WORD WVar1;
  undefined2 extraout_var;
  int iVar2;
  int iVar3;
  WORD WVar4;
  int iVar5;
  
  WVar1 = FUN_40451fcc();
  iVar5 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x14);
  iVar2 = FUN_4044f1f8(CONCAT22(extraout_var,WVar1),iVar3,iVar5);
  param_2[1] = (WORD)iVar3;
  WVar4 = (WORD)iVar5;
  if (iVar2 == 0) {
    *param_2 = WVar4;
    param_2[3] = 1;
  }
  else {
    *param_2 = WVar1;
    param_2[3] = WVar4;
  }
  return 1;
}



/* 4044f7e0 FUN_4044f7e0 */

/* Boundary evidence: original MIPS .pdata 4044f7e0..4044f897. Semantic name remains unreviewed. */

undefined4 FUN_4044f7e0(int param_1,undefined2 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(uint *)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  if ((DAT_4046d200 == 0) || (DAT_4046d200 == 1)) {
    iVar4 = *(int *)(param_1 + 0x14);
    iVar1 = FUN_4044f1f8(uVar3,iVar4,uVar2);
    param_2[1] = (short)iVar4;
    if (iVar1 != 0) goto LAB_4044f88c;
  }
  else {
    if (DAT_4046d200 != 2) {
      return 1;
    }
    iVar4 = *(int *)(param_1 + 0x14);
    iVar1 = FUN_4044f1f8(uVar2,iVar4,uVar3);
    param_2[1] = (short)iVar4;
    if (iVar1 == 0) {
LAB_4044f88c:
      *param_2 = (short)uVar3;
      param_2[3] = (short)uVar2;
      return 1;
    }
  }
  *param_2 = (short)uVar2;
  param_2[3] = (short)uVar3;
  return 1;
}



/* 4044f898 FUN_4044f898 */

/* Boundary evidence: original MIPS .pdata 4044f898..4044f953. Semantic name remains unreviewed. */

undefined4 FUN_4044f898(int param_1,WORD *param_2)

{
  WORD WVar1;
  
  if (*(uint *)(param_1 + 0x10) <= param_1 + 8U) {
    if (((*param_2 == 0xffff) && (param_2[1] != 0xffff)) && (param_2[3] != 0xffff)) {
      WVar1 = FUN_40451fcc();
      *param_2 = WVar1;
    }
    if (((param_2[3] == 0xffff) && (*param_2 != 0xffff)) && (param_2[1] != 0xffff)) {
      param_2[3] = 1;
    }
    if (((*param_2 != 0xffff) && (param_2[1] != 0xffff)) && (param_2[3] != 0xffff)) {
      return 1;
    }
  }
  return 0;
}



/* 4044f954 FUN_4044f954 */

/* Boundary evidence: original MIPS .pdata 4044f954..4044fa8b. Semantic name remains unreviewed. */

int FUN_4044f954(UDATE *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  UDATE *pUVar5;
  undefined2 auStack_50 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined2 auStack_40 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined2 auStack_30 [4];
  undefined4 local_28;
  undefined4 local_24;
  
  iVar3 = FUN_4045309c(param_1,auStack_40,1,0);
  if (((iVar3 == 0) && (iVar3 = FUN_4045309c((UDATE *)&DAT_4046da0c,auStack_50,1,0), iVar3 == 0)) &&
     (iVar3 = __ltd(local_38,local_34,local_48,local_44), iVar3 == 0)) {
    iVar3 = 0;
    pUVar5 = (UDATE *)&DAT_4046da2c;
    do {
      iVar4 = FUN_4045309c(pUVar5,auStack_30,1,0);
      uVar2 = local_34;
      uVar1 = local_38;
      if (iVar4 != 0) goto LAB_4044fa5c;
      iVar4 = __ged(local_38,local_34,local_48,local_44);
      local_44 = local_24;
      local_48 = local_28;
      if ((iVar4 != 0) && (iVar4 = __ltd(uVar1,uVar2,local_28,local_24), iVar4 != 0)) {
        return iVar3;
      }
      pUVar5 = (UDATE *)&pUVar5[1].st.wMilliseconds;
      iVar3 = iVar3 + 1;
    } while ((int)pUVar5 < 0x4046da8c);
    iVar3 = 3;
  }
  else {
LAB_4044fa5c:
    iVar3 = -1;
  }
  return iVar3;
}



/* 4044fa8c FUN_4044fa8c */

/* Boundary evidence: original MIPS .pdata 4044fa8c..4044ff8f. Semantic name remains unreviewed. */

int FUN_4044fa8c(UDATE *param_1,wchar_t *param_2,undefined4 *param_3)

{
  WORD WVar1;
  wchar_t wVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  size_t sVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  wchar_t *_Dest;
  int iVar11;
  wchar_t *pwVar10;
  
  wVar2 = *param_2;
  _Dest = (wchar_t *)*param_3;
  bVar3 = false;
  do {
    if (wVar2 == L'\0') {
      *_Dest = L'\0';
      *param_3 = _Dest;
      return 0;
    }
    if ((ushort)wVar2 < 0x65) {
      if (wVar2 == L'd') {
        WVar1 = (param_1->st).wDay;
        bVar3 = true;
LAB_4044fb48:
        uVar7 = (uint)(short)WVar1;
        pwVar9 = param_2 + 1;
        if (wVar2 != *pwVar9) {
LAB_4044ff14:
          FUN_40452290(uVar7,_Dest);
          goto LAB_4044ff1c;
        }
        if (*pwVar9 != param_2[2]) goto joined_r0x4044fcd8;
        iVar11 = uVar7 - 1;
        iVar5 = FUN_4044eb0c();
        if ((iVar5 != 0) && (iVar5 < 0)) {
          return iVar5;
        }
        pwVar9 = param_2 + 3;
        if (param_2[2] == *pwVar9) {
          if ((*param_2 == L'd') || (*param_2 == L'D')) {
            pwVar8 = &DAT_4046d76c + (short)(param_1->st).wDayOfWeek * 0x20;
          }
          else {
            if ((DAT_4046d1f8 == 0x415) || (DAT_4046d1f8 == 0x419)) {
              if (bVar3) {
LAB_4044fd3c:
                if (DAT_4046d1f8 == 0x415) {
                  pwVar8 = (wchar_t *)(&PTR_u_stycznia_40441580)[iVar11];
                }
                else {
                  pwVar8 = (wchar_t *)(&PTR_DAT_404415b4)[iVar11];
                }
                goto LAB_4044fd7c;
              }
              pwVar9 = param_2 + 4;
              wVar2 = *pwVar9;
              while (wVar2 != L'\0') {
                if ((wVar2 == L'd') || (wVar2 == L'D')) {
                  bVar3 = true;
                  goto LAB_4044fd3c;
                }
                pwVar8 = pwVar9;
                if (wVar2 == L'\'') {
                  do {
                    pwVar10 = pwVar9 + 1;
                    pwVar8 = pwVar10;
                    if (*pwVar10 == L'\'') break;
                    pwVar8 = pwVar9;
                    pwVar9 = pwVar10;
                  } while (*pwVar10 != L'\0');
                }
                pwVar9 = pwVar8 + 1;
                wVar2 = *pwVar9;
              }
            }
            pwVar8 = (wchar_t *)(&DAT_4046d260 + iVar11 * 0x40);
          }
LAB_4044fd7c:
          pwVar9 = param_2 + 4;
        }
        else if ((*param_2 == L'd') || (*param_2 == L'D')) {
          pwVar8 = (wchar_t *)(&DAT_4046d92c + (short)(param_1->st).wDayOfWeek * 0x20);
        }
        else {
          pwVar8 = (wchar_t *)(&DAT_4046d560 + iVar11 * 0x20);
        }
        wcscpy(_Dest,pwVar8);
        sVar6 = wcslen(_Dest);
LAB_4044ff24:
        _Dest = _Dest + sVar6;
      }
      else {
        if (wVar2 != L'\'') {
          if (wVar2 != L'E') {
            if (wVar2 != L'G') {
              if (wVar2 != L'M') goto LAB_4044fc70;
              goto LAB_4044fb40;
            }
            goto LAB_4044fdf8;
          }
          goto LAB_4044fe8c;
        }
        pwVar9 = param_2 + 1;
        while ((wVar2 = *pwVar9, wVar2 != L'\0' && (pwVar9 = pwVar9 + 1, wVar2 != L'\''))) {
          *_Dest = wVar2;
          _Dest = _Dest + 1;
        }
      }
    }
    else {
      if (wVar2 != L'e') {
        if (wVar2 != L'g') {
          if (wVar2 == L'm') {
LAB_4044fb40:
            WVar1 = (param_1->st).wMonth;
            goto LAB_4044fb48;
          }
          if (wVar2 != L'y') {
LAB_4044fc70:
            *_Dest = wVar2;
            _Dest = _Dest + 1;
            pwVar9 = param_2 + 1;
            goto LAB_4044ff44;
          }
          if (param_2[1] != L'y') goto LAB_4044fe8c;
          uVar7 = (uint)(short)(param_1->st).wYear;
          if ((param_2[2] == L'y') && (param_2[3] == L'y')) {
            pwVar9 = param_2 + 4;
            goto LAB_4044ff14;
          }
          if ((0x789 < (int)uVar7) && ((int)uVar7 < 0x7ee)) {
            uVar7 = (int)uVar7 % 100;
          }
joined_r0x4044fcd8:
          pwVar9 = param_2 + 2;
          if (9 < (int)uVar7) goto LAB_4044ff14;
          pwVar9 = param_2 + 2;
          *_Dest = L'0';
LAB_4044ff10:
          _Dest = _Dest + 1;
          goto LAB_4044ff14;
        }
LAB_4044fdf8:
        pwVar9 = param_2 + 1;
        bVar4 = FUN_404467ac(DAT_4046d1f8);
        if (CONCAT31(extraout_var,bVar4) == 0) goto LAB_4044ff44;
        wVar2 = *pwVar9;
        iVar5 = 0;
        if (((wVar2 == L'g') || (wVar2 == L'G')) &&
           ((param_2[2] == L'g' || (iVar5 = 1, wVar2 == L'G')))) {
          iVar5 = 2;
        }
        pwVar9 = pwVar9 + iVar5;
        iVar11 = FUN_4044f954(param_1);
        if (iVar11 < 0) {
          uVar7 = (uint)(short)(param_1->st).wYear;
          goto LAB_4044ff14;
        }
        wcscpy(_Dest,(wchar_t *)(&DAT_4046da20)[iVar11 * 8 + iVar5]);
LAB_4044ff1c:
        sVar6 = wcslen(_Dest);
        goto LAB_4044ff24;
      }
LAB_4044fe8c:
      pwVar9 = param_2 + 1;
      bVar4 = FUN_404467ac(DAT_4046d1f8);
      if (CONCAT31(extraout_var_00,bVar4) != 0) {
        bVar4 = false;
        if ((*pwVar9 == L'e') || (*pwVar9 == L'E')) {
          bVar4 = true;
          pwVar9 = param_2 + 2;
        }
        iVar5 = FUN_4044f954(param_1);
        if (-1 < iVar5) {
          uVar7 = ((int)(short)(param_1->st).wYear - (int)(short)(&DAT_4046da0c)[iVar5 * 0x10]) + 1;
          if ((9 < (int)uVar7) || (!bVar4)) goto LAB_4044ff14;
          *_Dest = L'0';
          goto LAB_4044ff10;
        }
      }
    }
LAB_4044ff44:
    wVar2 = *pwVar9;
    param_2 = pwVar9;
  } while( true );
}



/* 4044ff90 FUN_4044ff90 */

void FUN_4044ff90(int *param_1,int param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  
  if (DAT_4046d258 == 0) {
    if (DAT_4046d25c == 0) {
      return;
    }
  }
  else if (*(short *)(param_2 + 8) < 0xc) {
    psVar2 = &DAT_4046d204;
    goto LAB_4044ffcc;
  }
  psVar2 = &DAT_4046d21c;
LAB_4044ffcc:
  if (*psVar2 != 0) {
    if (param_3 != 0) goto LAB_40450004;
    *(undefined2 *)*param_1 = 0x20;
    while( true ) {
      *param_1 = *param_1 + 2;
LAB_40450004:
      sVar1 = *psVar2;
      if (sVar1 == 0) break;
      psVar2 = psVar2 + 1;
      *(short *)*param_1 = sVar1;
    }
    if (param_3 != 0) {
      *(undefined2 *)*param_1 = 0x20;
      *param_1 = *param_1 + 2;
    }
  }
  return;
}



/* 40450034 FUN_40450034 */

/* Boundary evidence: original MIPS .pdata 40450034..404501b7. Semantic name remains unreviewed. */

undefined4 FUN_40450034(int param_1,undefined4 *param_2)

{
  size_t sVar1;
  uint uVar2;
  wchar_t *_Str;
  int iVar3;
  uint *puVar4;
  wchar_t *local_38 [2];
  uint local_30 [4];
  
  local_38[0] = (wchar_t *)*param_2;
  if ((DAT_4046dae0 != 0) && (DAT_4046dadc != 0)) {
    FUN_4044ff90((int *)local_38,param_1,1);
  }
  local_30[0] = (uint)*(short *)(param_1 + 8);
  if (DAT_4046d258 != 0) {
    if ((int)local_30[0] < 0xd) {
      if (local_30[0] == 0) {
        local_30[0] = 0xc;
      }
    }
    else {
      local_30[0] = local_30[0] - 0xc;
    }
  }
  iVar3 = 0;
  puVar4 = local_30;
  local_30[1] = (int)*(short *)(param_1 + 10);
  local_30[2] = (int)*(short *)(param_1 + 0xc);
  do {
    uVar2 = *puVar4;
    _Str = local_38[0];
    if (((int)uVar2 < 10) && ((0 < iVar3 || (DAT_4046d254 != 0)))) {
      *local_38[0] = L'0';
      _Str = local_38[0] + 1;
    }
    FUN_40452290(uVar2,_Str);
    sVar1 = wcslen(_Str);
    local_38[0] = _Str + sVar1;
    if (iVar3 < 2) {
      *local_38[0] = DAT_4046d244;
      local_38[0] = local_38[0] + 1;
    }
    iVar3 = iVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar3 < 3);
  if ((DAT_4046dae0 == 0) || (DAT_4046dadc == 0)) {
    FUN_4044ff90((int *)local_38,param_1,0);
  }
  *local_38[0] = L'\0';
  *param_2 = local_38[0];
  return 0;
}



/* 404501b8 FUN_404501b8 */

/* Boundary evidence: original MIPS .pdata 404501b8..404502db. Semantic name remains unreviewed. */

undefined4 FUN_404501b8(LCID param_1,WCHAR *param_2,int *param_3)

{
  WCHAR WVar1;
  ushort uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  while (uVar2 = FUN_4044e650(param_1,*param_2,8), CONCAT22(extraout_var,uVar2) != 0) {
    param_2 = param_2 + 1;
  }
  WVar1 = *param_2;
  if ((WVar1 == L'-') || (WVar1 == L'+')) {
    param_2 = param_2 + 1;
  }
  iVar5 = 0;
  for (; (uVar4 = (uint)(ushort)*param_2, 0x2f < uVar4 && (uVar4 < 0x3a)); param_2 = param_2 + 1) {
    iVar5 = iVar5 * 10 + uVar4 + -0x30;
  }
  while (uVar2 = FUN_4044e650(param_1,*param_2,8), CONCAT22(extraout_var_00,uVar2) != 0) {
    param_2 = param_2 + 1;
  }
  if (*param_2 == L'\0') {
    if (WVar1 == L'-') {
      iVar5 = -iVar5;
    }
    *param_3 = iVar5;
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80070057;
  }
  return uVar3;
}



/* 404502dc FUN_404502dc */

void FUN_404502dc(void)

{
  DAT_4046d1cc = 0xffffffff;
  DAT_4046d1f8 = 0xffffffff;
  return;
}



/* 404502f8 FUN_404502f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 404502f8..40450b3b. Semantic name remains unreviewed. */

int FUN_404502f8(LCID param_1,uint param_2)

{
  LCID LVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar6;
  uint uVar7;
  LPWSTR pWVar8;
  wchar_t *_Str;
  LPWSTR pWVar9;
  WCHAR local_30 [4];
  
  FUN_404529b0();
  uVar7 = param_2 & 0xfffffff7;
  if ((DAT_4046d1fc != uVar7) ||
     ((LVar1 = DAT_4046d1f8, uVar6 = DAT_4046d1fc, DAT_4046d1f8 != param_1 &&
      (((param_1 != 0x400 && (param_1 != 0x800)) ||
       (param_1 = GetUserDefaultLCID(), LVar1 = DAT_4046d1f8, uVar6 = DAT_4046d1fc,
       DAT_4046d1f8 != param_1)))))) {
    uVar6 = param_1 & 0x3ff;
    if ((uVar6 == 4) || ((0x10 < uVar6 && (uVar6 < 0x13)))) {
      DAT_4046dae0 = 1;
    }
    else {
      DAT_4046dae0 = 0;
    }
    DAT_4046de44 = (uint)(uVar6 == 1);
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x21,local_30,2);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    DAT_4046d200 = (ushort)local_30[0] - 0x30;
    DAT_4046d25c = 0;
    iVar3 = GetLocaleInfoW(param_1,uVar7 | 0x28,&DAT_4046d204,0xc);
    iVar3 = iVar3 + 1;
    if (iVar3 < 2) {
      DAT_4046d204 = 0;
    }
    iVar4 = GetLocaleInfoW(param_1,uVar7 | 0x29,&DAT_4046d21c,0xc);
    iVar4 = iVar4 + 1;
    if (iVar4 < 2) {
      DAT_4046d21c = 0;
    }
    if (DAT_4046dae0 == 0) {
      iVar3 = CompareStringW(param_1,1,&DAT_4046d204,iVar3,&DAT_4046d21c,iVar4);
    }
    else {
      iVar3 = LCMapStringW(param_1,0x400000,&DAT_4046d204,iVar3,(LPWSTR)&DAT_4046daac,iVar3);
      iVar4 = LCMapStringW(param_1,0x400000,&DAT_4046d21c,iVar4,(LPWSTR)&DAT_4046dac4,iVar4);
      iVar3 = CompareStringW(param_1,1,(PCNZWCH)&DAT_4046daac,iVar3,(PCNZWCH)&DAT_4046dac4,iVar4);
    }
    if (iVar3 == 2) {
      DAT_4046d25c = 1;
    }
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x1d,(LPWSTR)&DAT_4046d234,8);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x1e,&DAT_4046d244,8);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x25,local_30,2);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    DAT_4046d254 = (ushort)local_30[0] - 0x30;
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x23,local_30,2);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    DAT_4046d258 = (uint)(local_30[0] == L'0');
    uVar6 = 0x38;
    _Str = (wchar_t *)&DAT_4046d560;
    pWVar8 = (LPWSTR)&DAT_4046d260;
    do {
      iVar3 = FUN_4044e9d8(param_1,uVar6,pWVar8,0x20);
      if ((iVar3 != 0) && (iVar3 < 0)) {
        return iVar3;
      }
      iVar3 = FUN_4044e9d8(param_1,uVar6 + 0xc,_Str,0x10);
      if ((iVar3 != 0) && (iVar3 < 0)) {
        return iVar3;
      }
      sVar5 = wcslen(_Str);
      pWVar8 = pWVar8 + 0x20;
      *(char *)(uVar6 + 0x4046d6a8) = (char)sVar5;
      uVar6 = uVar6 + 1;
      _Str = _Str + 0x10;
    } while ((int)pWVar8 < 0x4046d560);
    if (DAT_4046dae0 == 0) {
      iVar4 = 0;
      iVar3 = 0;
      do {
        if ((-1 < (int)((byte)(&DAT_4046d6e0)[iVar4] - 1)) &&
           (*(short *)(&DAT_4046d560 + (iVar3 + ((byte)(&DAT_4046d6e0)[iVar4] - 1)) * 2) == 0x2e)) {
          *(short *)(&DAT_4046d560 + (iVar3 + ((byte)(&DAT_4046d6e0)[iVar4] - 1)) * 2) = 0;
        }
        iVar3 = iVar3 + 0x10;
        iVar4 = iVar4 + 1;
      } while (iVar3 < 0xc0);
    }
    DAT_4046d76c = 0;
    iVar3 = FUN_4044e9d8(param_1,uVar7 | 0x1f,(LPWSTR)&DAT_4046d6ec,0x40);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    bVar2 = FUN_404467ac(param_1);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      bVar2 = FUN_404467fc(param_1);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        bVar2 = FUN_4044684c(param_1);
        if (CONCAT31(extraout_var_01,bVar2) == 0) {
          iVar3 = FUN_4044689c(param_1);
          if (iVar3 != 0) {
            iVar3 = FUN_4044690c(param_1);
            if (iVar3 == 0) {
              DAT_4046da98 = &DAT_40441740;
            }
            else {
              DAT_4046da98 = &DAT_40441794;
            }
            DAT_4046da8c = &DAT_404417a0;
            DAT_4046da90 = &DAT_4044179c;
            DAT_4046da94 = &DAT_40441798;
            DAT_4046da9c = &DAT_40441790;
            DAT_4046daa0 = &DAT_4044178c;
            DAT_4046daa4 = &DAT_4044174c;
            DAT_4046daa8 = &DAT_40441744;
            _DAT_4046da0c = &DAT_40441738;
          }
        }
        else {
          DAT_4046da8c = &DAT_404417a0;
          DAT_4046da90 = &DAT_4044179c;
          DAT_4046da94 = &DAT_40441798;
          DAT_4046da98 = &DAT_40441794;
          DAT_4046da9c = &DAT_40441790;
          DAT_4046daa0 = &DAT_4044178c;
          DAT_4046daa4 = &DAT_4044174c;
          DAT_4046de68 = 0x570b6c11;
          DAT_4046daa8 = &DAT_40441744;
          DAT_4046de6c = 0x524d;
          DAT_4046de5c = 0x83ef4e2d;
          DAT_4046de60 = 0x570b6c11;
          DAT_4046de64 = 0x524d;
          DAT_4046de54 = 0x6c11;
          DAT_4046de56 = 0x570b;
          DAT_4046de58 = 0;
          _DAT_4046da0c = (undefined *)0x1;
          DAT_4046da10 = &DAT_4046de68;
          DAT_4046da14 = &DAT_4046de5c;
          DAT_4046da18 = 0;
          DAT_4046de48 = 0x83ef4e2d;
          DAT_4046da1c = &DAT_4046de54;
          DAT_4046de4c = 0x570b6c11;
          DAT_4046de50 = 0;
          DAT_4046da20 = &DAT_4046de48;
        }
      }
      else {
        DAT_4046da8c = &DAT_40441778;
        DAT_4046da90 = &DAT_40441774;
        DAT_4046da94 = &DAT_40441770;
        DAT_4046da98 = &DAT_4044176c;
        DAT_4046da9c = &DAT_40441768;
        DAT_4046daa0 = &DAT_40441764;
        DAT_4046daa4 = &DAT_4044175c;
        DAT_4046daa8 = &DAT_40441754;
      }
    }
    else {
      _DAT_4046da0c = (undefined *)0xa074c;
      DAT_4046da10 = (undefined4 *)CONCAT22(0x17,DAT_4046da10._0_2_);
      DAT_4046da20 = (undefined4 *)&DAT_404417e0;
      DAT_4046da24 = &DAT_404417dc;
      DAT_4046da28 = &DAT_404417d4;
      DAT_4046da2c = 0x778;
      DAT_4046da2e = 7;
      DAT_4046da32 = 0x1e;
      DAT_4046da40 = &DAT_404417d0;
      DAT_4046da44 = &DAT_404417cc;
      DAT_4046da48 = &DAT_404417c4;
      DAT_4046da4c = 0x786;
      DAT_4046da4e = 0xc;
      DAT_4046da52 = 0x19;
      DAT_4046da60 = &DAT_404417c0;
      DAT_4046da64 = &DAT_404417bc;
      DAT_4046da68 = &DAT_404417b4;
      DAT_4046da6c = 0x7c5;
      DAT_4046da6e = 1;
      DAT_4046da72 = 8;
      DAT_4046da80 = &DAT_404417b0;
      DAT_4046da84 = &DAT_404417ac;
      DAT_4046da88 = &DAT_404417a4;
      DAT_4046da8c = &DAT_404417a0;
      DAT_4046da90 = &DAT_4044179c;
      DAT_4046da94 = &DAT_40441798;
      DAT_4046da98 = &DAT_40441794;
      DAT_4046da9c = &DAT_40441790;
      DAT_4046daa0 = &DAT_4044178c;
      DAT_4046daa4 = &DAT_40441784;
      DAT_4046daa8 = &DAT_4044177c;
    }
    LVar1 = param_1;
    uVar6 = uVar7;
    if (DAT_4046dae0 != 0) {
      DAT_4046dadc = 0;
      iVar3 = 0;
      pWVar9 = (LPWSTR)&DAT_4046dde4;
      pWVar8 = (LPWSTR)&DAT_4046dae4;
      do {
        iVar4 = FUN_4044e9d8(0x409,iVar3 + 0x38,pWVar8,0x20);
        if ((iVar4 != 0) && (iVar4 < 0)) {
          return iVar4;
        }
        iVar4 = FUN_4044e9d8(0x409,iVar3 + 0x44,pWVar9,4);
        if ((iVar4 != 0) && (iVar4 < 0)) {
          return iVar4;
        }
        pWVar8 = pWVar8 + 0x20;
        iVar3 = iVar3 + 1;
        pWVar9 = pWVar9 + 4;
        LVar1 = param_1;
      } while ((int)pWVar8 < 0x4046dde4);
    }
  }
  DAT_4046d1fc = uVar6;
  DAT_4046d1f8 = LVar1;
  return 0;
}



/* 40450b3c FUN_40450b3c */

/* Boundary evidence: original MIPS .pdata 40450b3c..40450e4b. Semantic name remains unreviewed. */

undefined4 FUN_40450b3c(int *param_1,int *param_2)

{
  WCHAR WVar1;
  WCHAR WVar2;
  ushort uVar3;
  size_t sVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 *_Src;
  WCHAR *_Str;
  int iVar5;
  WCHAR *pWVar6;
  undefined4 *puVar7;
  int iVar8;
  wchar_t *pwVar9;
  uint uVar10;
  short local_90 [14];
  undefined4 local_74;
  WCHAR local_70 [32];
  uint local_30;
  
  local_30 = DAT_4046d1b8;
  pwVar9 = (wchar_t *)*param_1;
  uVar10 = 0;
  iVar8 = 0;
  _Src = &DAT_4046da0c;
LAB_40450b9c:
  memcpy(local_90,_Src,0x20);
  iVar5 = 2;
  puVar7 = &local_74;
  while( true ) {
    sVar4 = wcslen(pwVar9);
    sVar4 = FUN_4044e6a0(pwVar9,sVar4,(wchar_t *)*puVar7);
    if (sVar4 != 0) break;
    iVar5 = iVar5 + -1;
    puVar7 = puVar7 + -1;
    if (iVar5 < 0) goto code_r0x40450be0;
  }
  _Str = pwVar9 + sVar4;
  while (uVar3 = FUN_4044e650(DAT_4046d1f8,*_Str,8), CONCAT22(extraout_var,uVar3) != 0) {
    _Str = _Str + 1;
  }
  pwVar9 = wcschr((wchar_t *)&DAT_4046d234,*_Str);
  if ((pwVar9 == (wchar_t *)0x0) && (pwVar9 = wcschr(L",/-",*_Str), pwVar9 == (wchar_t *)0x0))
  goto LAB_40450c54;
  do {
    _Str = _Str + 1;
LAB_40450c54:
    uVar3 = FUN_4044e650(DAT_4046d1f8,*_Str,8);
  } while (CONCAT22(extraout_var_00,uVar3) != 0);
  uVar3 = FUN_4044e650(DAT_4046d1f8,*_Str,4);
  if (CONCAT22(extraout_var_01,uVar3) == 0) goto LAB_40450c84;
  uVar3 = FUN_4044e650(DAT_4046d1f8,*_Str,4);
  if (CONCAT22(extraout_var_02,uVar3) != 0) {
    pWVar6 = local_70;
    do {
      if (0x1e < uVar10) break;
      WVar1 = *_Str;
      _Str = _Str + 1;
      WVar2 = *_Str;
      *pWVar6 = WVar1;
      uVar10 = uVar10 + 1;
      pWVar6 = pWVar6 + 1;
      uVar3 = FUN_4044e650(DAT_4046d1f8,WVar2,4);
    } while (CONCAT22(extraout_var_03,uVar3) != 0);
  }
  local_70[uVar10] = L'\0';
  FUN_404501b8(DAT_4046d1f8,local_70,param_2);
  if (*param_2 < 1) {
    *param_2 = -1;
  }
  else {
    iVar5 = (int)local_90[0] + *param_2 + -1;
    *param_2 = iVar5;
    if ((iVar8 < 4) &&
       ((iVar5 < local_90[0] || ((iVar8 != 3 && ((short)(&DAT_4046da2c)[iVar8 * 0x10] < iVar5))))))
    {
      *param_2 = -1;
    }
    else {
      while (uVar3 = FUN_4044e650(DAT_4046d1f8,*_Str,8), CONCAT22(extraout_var_04,uVar3) != 0) {
        _Str = _Str + 1;
      }
      sVar4 = wcslen(_Str);
      sVar4 = FUN_4044e6a0(_Str,sVar4,DAT_4046da8c);
      if (sVar4 != 0) {
        *param_1 = (int)(_Str + sVar4);
        FUN_4046ace8(local_30);
        return 2;
      }
      pwVar9 = wcschr((wchar_t *)&DAT_4046d234,*_Str);
      if ((pwVar9 != (wchar_t *)0x0) || (pwVar9 = wcschr(L",/-",*_Str), pwVar9 != (wchar_t *)0x0)) {
        _Str = _Str + 1;
      }
      *param_1 = (int)_Str;
    }
  }
  FUN_4046ace8(local_30);
  return 1;
code_r0x40450be0:
  _Src = _Src + 0x10;
  iVar8 = iVar8 + 1;
  if (0x4046da8b < (int)_Src) {
LAB_40450c84:
    FUN_4046ace8(local_30);
    return 0;
  }
  goto LAB_40450b9c;
}



/* 40450e4c FUN_40450e4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40450e4c..4045119b. Semantic name remains unreviewed. */

undefined4 FUN_40450e4c(int *param_1,int *param_2)

{
  WCHAR WVar1;
  WCHAR WVar2;
  ushort uVar3;
  int iVar4;
  size_t sVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  WCHAR *pWVar6;
  int *piVar7;
  WCHAR *pWVar8;
  wchar_t *pwVar9;
  int *piVar10;
  int iVar11;
  uint local_88;
  int local_78 [2];
  WCHAR local_70 [32];
  uint local_30;
  
  local_30 = DAT_4046d1b8;
  pwVar9 = (wchar_t *)*param_1;
  local_88 = 0;
  iVar4 = FUN_4044689c(DAT_4046d1f8);
  if (iVar4 != 0) {
    sVar5 = wcslen(pwVar9);
    sVar5 = FUN_4044e6a0(pwVar9,sVar5,_DAT_4046da0c);
    if (sVar5 != 0) {
      pWVar6 = (WCHAR *)(sVar5 * 2 + *param_1);
      *param_1 = (int)pWVar6;
      while (uVar3 = FUN_4044e650(DAT_4046d1f8,*pWVar6,8), CONCAT22(extraout_var,uVar3) != 0) {
        pWVar6 = (WCHAR *)(*param_1 + 2);
        *param_1 = (int)pWVar6;
      }
    }
LAB_40450f08:
    FUN_4046ace8(local_30);
    return 0;
  }
  piVar7 = (int *)&DAT_4046da0c;
LAB_40450f20:
  iVar11 = *piVar7;
  local_78[0] = piVar7[2];
  iVar4 = 1;
  piVar10 = local_78;
  while( true ) {
    sVar5 = wcslen(pwVar9);
    sVar5 = FUN_4044e6a0(pwVar9,sVar5,(wchar_t *)*piVar10);
    if (sVar5 != 0) break;
    iVar4 = iVar4 + -1;
    piVar10 = piVar10 + -1;
    if (iVar4 < 0) goto code_r0x40450f6c;
  }
  pWVar6 = pwVar9 + sVar5;
  while (uVar3 = FUN_4044e650(DAT_4046d1f8,*pWVar6,8), CONCAT22(extraout_var_00,uVar3) != 0) {
    pWVar6 = pWVar6 + 1;
  }
  pwVar9 = wcschr((wchar_t *)&DAT_4046d234,*pWVar6);
  if ((pwVar9 == (wchar_t *)0x0) && (pwVar9 = wcschr(L",/-",*pWVar6), pwVar9 == (wchar_t *)0x0))
  goto LAB_40450fe0;
  do {
    pWVar6 = pWVar6 + 1;
LAB_40450fe0:
    uVar3 = FUN_4044e650(DAT_4046d1f8,*pWVar6,8);
  } while (CONCAT22(extraout_var_01,uVar3) != 0);
  uVar3 = FUN_4044e650(DAT_4046d1f8,*pWVar6,4);
  if (CONCAT22(extraout_var_02,uVar3) != 0) {
    pWVar8 = local_70;
    do {
      if (0x1e < local_88) break;
      WVar1 = *pWVar6;
      pWVar6 = pWVar6 + 1;
      WVar2 = *pWVar6;
      *pWVar8 = WVar1;
      local_88 = local_88 + 1;
      pWVar8 = pWVar8 + 1;
      uVar3 = FUN_4044e650(DAT_4046d1f8,WVar2,4);
    } while (CONCAT22(extraout_var_03,uVar3) != 0);
  }
  local_70[local_88] = L'\0';
  FUN_404501b8(DAT_4046d1f8,local_70,param_2);
  iVar4 = *param_2;
  if (iVar4 < 1) {
    *param_2 = -1;
  }
  else {
    if (iVar11 == 0) {
      *param_2 = iVar4 + 0x777;
    }
    else {
      *param_2 = 0x778 - iVar4;
    }
    if (*param_2 < 1) {
      *param_2 = -1;
    }
    else {
      while (uVar3 = FUN_4044e650(DAT_4046d1f8,*pWVar6,8), CONCAT22(extraout_var_04,uVar3) != 0) {
        pWVar6 = pWVar6 + 1;
      }
      if (*pWVar6 != L'\0') {
        sVar5 = wcslen(pWVar6);
        sVar5 = FUN_4044e6a0(pWVar6,sVar5,DAT_4046da8c);
        if (sVar5 != 0) {
          *param_1 = (int)(pWVar6 + sVar5);
          FUN_4046ace8(local_30);
          return 2;
        }
        pwVar9 = wcschr((wchar_t *)&DAT_4046d234,*pWVar6);
        if ((pwVar9 != (wchar_t *)0x0) ||
           (pwVar9 = wcschr(L",/-",*pWVar6), pwVar9 != (wchar_t *)0x0)) {
          pWVar6 = pWVar6 + 1;
        }
      }
      *param_1 = (int)pWVar6;
    }
  }
  FUN_4046ace8(local_30);
  return 1;
code_r0x40450f6c:
  piVar7 = piVar7 + 3;
  if (0x4046da23 < (int)piVar7) goto LAB_40450f08;
  goto LAB_40450f20;
}



/* 4045119c FUN_4045119c */

/* Boundary evidence: original MIPS .pdata 4045119c..4045161b. Semantic name remains unreviewed. */

undefined4 FUN_4045119c(undefined4 *param_1,int *param_2,int *param_3,uint param_4)

{
  bool bVar1;
  ushort uVar2;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  int iVar4;
  undefined2 extraout_var_07;
  undefined4 uVar5;
  WCHAR WVar6;
  WCHAR *pWVar7;
  WCHAR *pWVar8;
  WCHAR *pWVar9;
  WCHAR *local_80;
  WCHAR *local_7c;
  undefined4 *local_78;
  WCHAR local_70 [32];
  uint local_30;
  
  local_30 = DAT_4046d1b8;
  pWVar7 = (WCHAR *)*param_1;
  *param_2 = 0xb;
  param_2[3] = 0;
  pWVar8 = local_70;
  local_7c = pWVar7;
  local_78 = param_1;
  uVar2 = FUN_4044e650(DAT_4046d1f8,*pWVar7,8);
  iVar3 = CONCAT22(extraout_var_01,uVar2);
  pWVar9 = local_7c;
  while (iVar3 != 0) {
    pWVar7 = pWVar7 + 1;
    uVar2 = FUN_4044e650(DAT_4046d1f8,*pWVar7,8);
    pWVar9 = pWVar7;
    iVar3 = CONCAT22(extraout_var_02,uVar2);
  }
  local_7c = pWVar9;
  if (*pWVar7 == L'\0') {
    *param_2 = 0;
    goto LAB_404515dc;
  }
  if (DAT_4046dae0 != 0) {
    bVar1 = FUN_404467ac(DAT_4046d1f8);
    if (CONCAT31(extraout_var,bVar1) == 0) {
LAB_404512b8:
      iVar3 = FUN_4044689c(DAT_4046d1f8);
      if ((iVar3 != 0) || (bVar1 = FUN_4044684c(DAT_4046d1f8), CONCAT31(extraout_var_00,bVar1) != 0)
         ) {
        iVar3 = FUN_40450e4c((int *)&local_7c,(int *)&local_80);
        if (iVar3 == 1) goto LAB_40451320;
        pWVar7 = local_7c;
        if (iVar3 == 2) goto LAB_4045128c;
      }
      iVar3 = FUN_4044ebdc(pWVar7,(size_t *)&local_80);
      if (iVar3 != 0) {
        pWVar9 = pWVar7 + (int)local_80;
        while (uVar2 = FUN_4044e650(DAT_4046d1f8,*pWVar9,8), CONCAT22(extraout_var_03,uVar2) != 0) {
          pWVar9 = pWVar9 + 1;
        }
        param_1 = local_78;
        if (((*param_3 == 0) && (*pWVar9 != L'\0')) && ((int *)param_3[4] == param_3 + 1)) {
          *param_3 = iVar3;
          pWVar7 = pWVar9;
        }
      }
      goto LAB_40451384;
    }
    iVar3 = FUN_40450b3c((int *)&local_7c,(int *)&local_80);
    if (iVar3 == 1) {
LAB_40451320:
      *param_2 = 4;
LAB_404512a8:
      param_2[1] = (int)local_80;
      pWVar7 = local_7c;
      goto LAB_404515dc;
    }
    pWVar7 = local_7c;
    if (iVar3 != 2) goto LAB_404512b8;
LAB_4045128c:
    pWVar7 = local_7c;
    if (local_80 != (WCHAR *)0xffffffff) {
      *param_2 = 9;
      param_2[3] = 1;
      goto LAB_404512a8;
    }
    goto switchD_40451510_default;
  }
LAB_40451384:
  uVar2 = FUN_4044e650(DAT_4046d1f8,*pWVar7,0x100);
  WVar6 = *pWVar7;
  if (CONCAT22(extraout_var_04,uVar2) != 0) {
    while (uVar2 = FUN_4044e650(DAT_4046d1f8,WVar6,0x104), CONCAT22(extraout_var_06,uVar2) != 0) {
      if (local_70 + 0x1f <= pWVar8) goto LAB_4045146c;
      WVar6 = *pWVar7;
      pWVar7 = pWVar7 + 1;
      *pWVar8 = WVar6;
      WVar6 = *pWVar7;
      pWVar8 = pWVar8 + 1;
    }
    *pWVar8 = L'\0';
    if (*pWVar7 == L'.') {
      pWVar7 = pWVar7 + 1;
    }
    iVar3 = FUN_4044e73c(local_70,(int)pWVar8 - (int)local_70 >> 1,param_4);
    if (iVar3 != 0) {
      local_80 = pWVar7;
      iVar4 = FUN_4044ed08(&local_80,param_3);
      if (iVar4 == 1) {
        *param_2 = 6;
      }
      else {
        if (iVar4 == 2) {
          iVar4 = 7;
        }
        else {
          if (iVar4 != 5) goto switchD_40451510_default;
          iVar4 = 8;
        }
        *param_2 = iVar4;
      }
      param_2[1] = iVar3;
      pWVar7 = local_80;
    }
    goto switchD_40451510_default;
  }
  uVar2 = FUN_4044e650(DAT_4046d1f8,WVar6,4);
  if (CONCAT22(extraout_var_05,uVar2) == 0) goto switchD_40451510_default;
  while (uVar2 = FUN_4044e650(DAT_4046d1f8,*pWVar7,4), CONCAT22(extraout_var_07,uVar2) != 0) {
    if (local_70 + 0x1f <= pWVar8) {
LAB_4045146c:
      FUN_4046ace8(local_30);
      return 0;
    }
    WVar6 = *pWVar7;
    pWVar7 = pWVar7 + 1;
    *pWVar8 = WVar6;
    pWVar8 = pWVar8 + 1;
  }
  *pWVar8 = L'\0';
  local_80 = pWVar7;
  uVar5 = FUN_4044ed08(&local_80,param_3);
  pWVar9 = local_80;
  switch(uVar5) {
  case 1:
    *param_2 = 1;
    break;
  case 2:
    iVar3 = 3;
    goto LAB_404515b4;
  case 3:
    param_2[2] = 1;
    goto LAB_4045153c;
  case 4:
    param_2[2] = 2;
LAB_4045153c:
    *param_2 = 2;
    break;
  case 5:
    *param_2 = 4;
    break;
  case 6:
    iVar3 = 5;
    goto LAB_404515b4;
  case 7:
    *param_2 = 9;
    param_2[3] = 1;
    break;
  case 8:
    iVar3 = 9;
    param_2[3] = 2;
    goto LAB_404515b4;
  case 9:
    iVar3 = 9;
    iVar4 = 3;
    goto LAB_40451588;
  case 10:
    param_2[3] = 4;
    goto LAB_404515b0;
  case 0xb:
    iVar3 = 10;
    iVar4 = 5;
LAB_40451588:
    *param_2 = iVar3;
    param_2[3] = iVar4;
    break;
  case 0xc:
    param_2[3] = 6;
LAB_404515b0:
    iVar3 = 10;
LAB_404515b4:
    *param_2 = iVar3;
    break;
  default:
    goto switchD_40451510_default;
  }
  FUN_404501b8(DAT_4046d1f8,local_70,param_2 + 1);
  pWVar7 = pWVar9;
switchD_40451510_default:
  if (*param_2 != 0xb) {
LAB_404515dc:
    *param_1 = pWVar7;
  }
  FUN_4046ace8(local_30);
  return 1;
}



/* 4045161c VarDateFromStr */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4045161c..40451dcf. Semantic name remains unreviewed. */

HRESULT VarDateFromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,DATE *pdateOut)

{
  OLECHAR OVar1;
  bool bVar2;
  WORD WVar3;
  WORD WVar4;
  WORD WVar5;
  WORD WVar6;
  WORD WVar7;
  WORD WVar8;
  WORD WVar9;
  WORD WVar10;
  wchar_t *pwVar11;
  bool bVar12;
  int iVar13;
  undefined3 extraout_var;
  int iVar14;
  code *pcVar15;
  WORD WVar16;
  LPCOLESTR pOVar17;
  int iVar18;
  uint uVar19;
  OLECHAR *pOVar20;
  LPCOLESTR pOVar21;
  int iVar22;
  UDATE local_178;
  int local_160;
  undefined4 ******local_15c;
  int local_158;
  int local_154;
  int local_150;
  undefined4 ******local_14c;
  undefined4 ******local_148 [2];
  undefined4 *******local_140;
  undefined4 ******local_13c;
  wchar_t *local_138;
  wchar_t *local_134;
  OLECHAR local_130 [128];
  uint local_30;
  
                    /* 0x1161c  99  VarDateFromStr */
  local_30 = DAT_4046d1b8;
  iVar22 = -0x7ffdfffb;
  if (strIn == (LPCOLESTR)0x0) {
LAB_40451d94:
    FUN_4046ace8(local_30);
    return iVar22;
  }
  iVar13 = FUN_404502f8(lcid,dwFlags & 0x80000000);
  if ((iVar13 != 0) && (iVar13 < 0)) {
    FUN_4046ace8(local_30);
    return iVar13;
  }
  bVar12 = FUN_404467ac(DAT_4046d1f8);
  if (CONCAT31(extraout_var,bVar12) != 0) {
    iVar13 = 0;
    iVar18 = 0;
    pOVar20 = local_130;
    pOVar21 = strIn + 2;
    pOVar17 = strIn;
    do {
      OVar1 = *pOVar17;
      if (OVar1 == L'\0') break;
      if (((OVar1 == L'(') && (pOVar17[1] != L'\0')) && (*pOVar21 == L')')) {
        iVar18 = iVar18 + 2;
        pOVar21 = pOVar21 + 2;
        pOVar17 = pOVar17 + 2;
        iVar13 = iVar13 + -1;
        pOVar20 = pOVar20 + -1;
      }
      else {
        *pOVar20 = OVar1;
      }
      iVar13 = iVar13 + 1;
      iVar18 = iVar18 + 1;
      pOVar21 = pOVar21 + 1;
      pOVar17 = pOVar17 + 1;
      pOVar20 = pOVar20 + 1;
    } while (iVar13 < 0x80);
    if ((iVar18 != iVar13) && (iVar13 < 0x80)) {
      local_130[iVar13] = L'\0';
      strIn = local_130;
    }
  }
  pwVar11 = strIn;
  if (((DAT_4046dae0 != 0) &&
      (iVar13 = FUN_40445834(lcid,strIn,&local_138), pwVar11 = local_138, iVar13 != 0)) &&
     (iVar13 < 0)) {
    FUN_4046ace8(local_30);
    return iVar13;
  }
  local_138 = pwVar11;
  iVar13 = 0;
  iVar18 = 0;
  local_178.st.wSecond = 0xffff;
  bVar12 = false;
  local_178.st.wMinute = 0xffff;
  bVar2 = false;
  local_178.st.wHour = 0xffff;
  local_178.st.wDay = 0xffff;
  local_178.st.wMonth = 0xffff;
  local_178.st.wYear = 0xffff;
  local_13c = (undefined4 ******)0x0;
  local_150 = 0;
  local_15c = (undefined4 ******)0x0;
  local_160 = 0;
  local_154 = 0;
  local_158 = 0;
  uVar19 = DAT_4046d1f8;
  local_134 = local_138;
LAB_40451838:
  if (iVar18 == 0) {
    local_140 = &local_14c;
  }
  WVar5 = local_178.st.wYear;
  WVar6 = local_178.st.wMonth;
  WVar7 = local_178.st.wDay;
  WVar8 = local_178.st.wHour;
  WVar9 = local_178.st.wMinute;
  WVar10 = local_178.st.wSecond;
  if (iVar18 >= 0xd) goto switchD_404518ac_default;
  iVar13 = FUN_4045119c(&local_134,&local_160,&local_150,dwFlags);
  if (iVar13 == 0) goto switchD_40451a7c_caseD_d;
  uVar19 = DAT_4046d1f8;
  iVar13 = local_160;
  WVar5 = local_178.st.wYear;
  WVar6 = local_178.st.wMonth;
  WVar7 = local_178.st.wDay;
  WVar8 = local_178.st.wHour;
  WVar9 = local_178.st.wMinute;
  WVar10 = local_178.st.wSecond;
  switch(local_160) {
  case 1:
  case 3:
  case 4:
  case 5:
    goto switchD_404518ac_caseD_1;
  case 2:
    local_150 = local_158;
switchD_404518ac_caseD_1:
    if (local_140 < &local_140) {
      *local_140 = local_15c;
      local_140 = local_140 + 1;
    }
    break;
  case 6:
  case 7:
  case 8:
    local_13c = local_15c;
    break;
  case 9:
  case 10:
    WVar16 = (WORD)local_15c;
    WVar3 = local_178.st.wYear;
    WVar5 = WVar16;
    if (local_154 == 1) {
joined_r0x404519a4:
      if (bVar12) goto switchD_40451a7c_caseD_d;
    }
    else {
      if (local_154 == 2) {
        WVar3 = local_178.st.wSecond;
        WVar4 = local_178.st.wMonth;
        if (!bVar12) {
joined_r0x40451990:
          WVar5 = local_178.st.wYear;
          WVar6 = WVar16;
          WVar7 = local_178.st.wDay;
          WVar8 = local_178.st.wHour;
          WVar9 = local_178.st.wMinute;
          WVar10 = WVar3;
          if (WVar4 == 0xffff) break;
        }
        goto switchD_40451a7c_caseD_d;
      }
      WVar3 = local_178.st.wDay;
      WVar7 = WVar16;
      WVar5 = local_178.st.wYear;
      if (local_154 == 3) goto joined_r0x404519a4;
      WVar8 = WVar16;
      WVar7 = local_178.st.wDay;
      WVar3 = local_178.st.wHour;
      if ((local_154 != 4) &&
         (WVar9 = WVar16, WVar8 = local_178.st.wHour, WVar3 = local_178.st.wMinute, local_154 != 5))
      {
        WVar9 = local_178.st.wMinute;
        WVar3 = WVar16;
        WVar16 = local_178.st.wMonth;
        WVar4 = local_178.st.wSecond;
        if (local_154 != 6) break;
        goto joined_r0x40451990;
      }
    }
    if (WVar3 != 0xffff) goto switchD_40451a7c_caseD_d;
  }
switchD_404518ac_default:
  local_178.st.wSecond = WVar10;
  local_178.st.wMinute = WVar9;
  local_178.st.wHour = WVar8;
  local_178.st.wDay = WVar7;
  local_178.st.wMonth = WVar6;
  local_178.st.wYear = WVar5;
  pcVar15 = FUN_4044f2b4;
  switch(iVar18) {
  case 0:
    if (iVar13 == 0) {
      if (!bVar12) {
        if (!bVar2) goto switchD_40451a7c_caseD_d;
        local_178.st.wMonth = 0xc;
        local_178.st.wDay = 0x1e;
        local_178.st.wYear = 0x76b;
      }
      if (bVar2) {
        if (local_150 == 1) {
          if (local_178.st.wHour == 0xc) goto LAB_40451d4c;
        }
        else if ((local_150 == 2) && ((short)local_178.st.wHour < 0xc)) {
          local_178.st.wHour = local_178.st.wHour + 0xc;
        }
      }
      else {
        local_178.st.wMinute = 0;
        local_178.st.wSecond = 0;
LAB_40451d4c:
        local_178.st.wHour = 0;
      }
      iVar13 = FUN_4045309c(&local_178,(undefined2 *)&local_160,1,dwFlags);
      if (iVar13 == 0) {
        iVar22 = 0;
        *(int *)pdateOut = local_158;
        *(int *)((int)pdateOut + 4) = local_154;
      }
switchD_40451a7c_caseD_d:
      if (DAT_4046dae0 != 0) {
        FUN_4044427c(local_138);
      }
      goto LAB_40451d94;
    }
    break;
  case 1:
  case 3:
  case 6:
  case 8:
  case 9:
  case 10:
    break;
  case 2:
  case 4:
    if ((iVar13 != 2) && (iVar13 != 5)) goto LAB_40451c70;
LAB_40451b10:
    if ((!bVar12) && (iVar14 = (*pcVar15)(&local_150,&local_178), iVar14 != 0)) {
      local_140 = local_148;
      local_150 = local_158;
      local_14c = local_15c;
      goto LAB_40451b44;
    }
    goto switchD_40451a7c_caseD_d;
  case 5:
    if ((uVar19 == 0x40e) && (iVar13 == 4)) {
      iVar13 = 3;
      local_160 = 3;
    }
    break;
  case 7:
    pcVar15 = FUN_4044f760;
    if ((iVar13 == 2) || (iVar13 == 5)) goto LAB_40451b10;
    break;
  case 0xb:
    if (iVar13 != 9) goto switchD_40451a7c_caseD_12;
    break;
  case 0xc:
    goto switchD_40451a7c_caseD_c;
  default:
    goto switchD_40451a7c_caseD_d;
  case 0xe:
    goto LAB_40451b70;
  case 0xf:
    pcVar15 = FUN_4044f4f0;
    goto LAB_40451b70;
  case 0x10:
    pcVar15 = FUN_4044f760;
    goto LAB_40451b70;
  case 0x11:
    pcVar15 = FUN_4044f7e0;
LAB_40451b70:
    if (bVar12) goto switchD_40451a7c_caseD_d;
    iVar14 = (*pcVar15)(&local_150,&local_178);
LAB_40451b84:
    if (iVar14 == 0) goto switchD_40451a7c_caseD_d;
LAB_40451b44:
    bVar12 = true;
    uVar19 = DAT_4046d1f8;
LAB_40451c70:
    if (iVar18 < 0xd) break;
    iVar18 = 0;
    goto LAB_40451838;
  case 0x12:
switchD_40451a7c_caseD_12:
    iVar14 = FUN_4044f898((int)&local_150,(WORD *)&local_178);
    goto LAB_40451b84;
  case 0x13:
    if (local_150 != 0) {
      local_178.st.wMinute = 0;
      local_178.st.wSecond = 0;
      goto LAB_40451bd4;
    }
    goto switchD_40451a7c_caseD_d;
  case 0x14:
    local_178.st.wSecond = 0;
    goto LAB_40451bc4;
  case 0x15:
    local_178.st.wSecond = (WORD)local_148[1];
LAB_40451bc4:
    local_178.st.wMinute = (WORD)local_148[0];
LAB_40451bd4:
    local_178.st.wHour = (WORD)local_14c;
    if (!bVar2) {
LAB_40451c24:
      if (local_150 == 1) {
        if (local_178.st.wHour == 0xc) {
          local_178.st.wHour = 0;
        }
      }
      else if ((local_150 == 2) && ((short)local_178.st.wHour < 0xc)) {
        local_178.st.wHour = local_178.st.wHour + 0xc;
      }
      local_150 = 0;
switchD_40451a7c_caseD_c:
      bVar2 = true;
      goto LAB_40451c70;
    }
    goto switchD_40451a7c_caseD_d;
  case 0x16:
    if (local_140 == &local_14c) {
      if (local_178.st.wHour == 0xffff) {
        local_178.st.wHour = 0;
      }
      if (local_178.st.wMinute == 0xffff) {
        local_178.st.wMinute = 0;
      }
      if (local_178.st.wSecond == 0xffff) {
        local_178.st.wSecond = 0;
      }
      goto LAB_40451c24;
    }
    goto switchD_40451a7c_caseD_d;
  }
  iVar18 = (int)(char)(&DAT_404415e8)[iVar18 * 0xb + iVar13];
  goto LAB_40451838;
}



/* 40451dd0 VarBstrFromDate */

/* Boundary evidence: original MIPS .pdata 40451dd0..40451fcb. Semantic name remains unreviewed. */

HRESULT VarBstrFromDate(DATE dateIn,LCID lcid,ULONG dwFlags,BSTR *pbstrOut)

{
  bool bVar1;
  int iVar2;
  OLECHAR *local_158 [2];
  UDATE local_150;
  short local_138 [8];
  OLECHAR local_128 [128];
  uint local_28;
  
                    /* 0x11dd0  66  VarBstrFromDate */
  local_28 = DAT_4046d1b8;
  if (((dwFlags & 0x7ffffff4) != 0) || (((dwFlags & 1) != 0 && ((dwFlags & 2) != 0)))) {
    FUN_4046ace8(DAT_4046d1b8);
    return -0x7ff8ffa9;
  }
  iVar2 = FUN_404502f8(lcid,dwFlags & 0xfffffffc);
  if ((iVar2 != 0) && (iVar2 < 0)) goto LAB_40451e60;
  local_138[0] = 7;
  iVar2 = FUN_404534d4(dateIn,&local_150,local_138,dwFlags & 0xfffffffc);
  if ((iVar2 != 0) && (iVar2 < 0)) goto LAB_40451e60;
  local_158[0] = local_128;
  if (((local_150.st.wMonth == 0xc) && (local_150.st.wDay == 0x1e)) && (local_150.st.wYear == 0x76b)
     ) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if ((((dwFlags & 1) == 0) &&
        (iVar2 = FUN_4044fa8c(&local_150,(wchar_t *)&DAT_4046d6ec,local_158), iVar2 != 0)) &&
       (iVar2 < 0)) goto LAB_40451e60;
  }
  if ((dwFlags & 2) == 0) {
    if (!bVar1) {
      if (((local_150.st.wHour == 0) && (local_150.st.wMinute == 0)) && (local_150.st.wSecond == 0))
      goto LAB_40451f7c;
      *local_158[0] = L' ';
      local_158[0] = local_158[0] + 1;
    }
    iVar2 = FUN_40450034((int)&local_150,local_158);
    if ((iVar2 != 0) && (iVar2 < 0)) goto LAB_40451e60;
  }
LAB_40451f7c:
  iVar2 = FUN_4044bad4(local_128,pbstrOut);
LAB_40451e60:
  FUN_4046ace8(local_28);
  return iVar2;
}



/* 40451fcc FUN_40451fcc */

/* Boundary evidence: original MIPS .pdata 40451fcc..40451fef. Semantic name remains unreviewed. */

WORD FUN_40451fcc(void)

{
  _SYSTEMTIME local_18;
  
  GetLocalTime(&local_18);
  return local_18.wYear;
}



/* 40451ff0 FUN_40451ff0 */

/* Boundary evidence: original MIPS .pdata 40451ff0..4045208b. Semantic name remains unreviewed. */

undefined4 FUN_40451ff0(int param_1)

{
  undefined4 uVar1;
  undefined4 auStack_3c [15];
  
  auStack_3c[2] = 0x1e;
  auStack_3c[3] = 0x3b;
  auStack_3c[7] = 0xb1;
  auStack_3c[4] = 0x59;
  auStack_3c[5] = 0x76;
  auStack_3c[6] = 0x94;
  auStack_3c[8] = 0xcf;
  auStack_3c[0xc] = 0x145;
  auStack_3c[1] = 0;
  auStack_3c[9] = 0xec;
  auStack_3c[10] = 0x10a;
  auStack_3c[0xb] = 0x127;
  auStack_3c[0xd] = 0x163;
  if ((param_1 < 1) || (0xd < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = auStack_3c[param_1];
  }
  return uVar1;
}



/* 4045208c FUN_4045208c */

int FUN_4045208c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (param_1 * 400) / 0x23ab1;
  iVar1 = iVar3 + 1;
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar2 = iVar3 + 4;
  }
  if (((iVar1 / 400 + iVar1 * 0x16d) - iVar1 / 100) + (iVar2 >> 2) < param_1) {
    iVar1 = iVar3 + 2;
  }
  else {
    iVar2 = iVar3;
    if (iVar3 < 0) {
      iVar2 = iVar3 + 3;
    }
    if (param_1 <= ((iVar3 / 400 + iVar3 * 0x16d) - iVar3 / 100) + (iVar2 >> 2)) {
      iVar1 = iVar3;
    }
  }
  return iVar1;
}



/* 40452174 FUN_40452174 */

/* Boundary evidence: original MIPS .pdata 40452174..4045220f. Semantic name remains unreviewed. */

undefined4 FUN_40452174(int param_1)

{
  undefined4 uVar1;
  undefined4 auStack_3c [15];
  
  auStack_3c[2] = 0x1f;
  auStack_3c[3] = 0x3b;
  auStack_3c[7] = 0xb5;
  auStack_3c[4] = 0x5a;
  auStack_3c[5] = 0x78;
  auStack_3c[6] = 0x97;
  auStack_3c[8] = 0xd4;
  auStack_3c[0xc] = 0x14e;
  auStack_3c[1] = 0;
  auStack_3c[9] = 0xf3;
  auStack_3c[10] = 0x111;
  auStack_3c[0xb] = 0x130;
  auStack_3c[0xd] = 0x16d;
  if ((param_1 < 1) || (0xd < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = auStack_3c[param_1];
  }
  return uVar1;
}



/* 40452210 FUN_40452210 */

void FUN_40452210(uint param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  uint uVar4;
  
  psVar2 = param_2;
  if (param_3 != 0) {
    *param_2 = 0x2d;
    param_2 = param_2 + 1;
    param_1 = -param_1;
    psVar2 = param_2;
  }
  do {
    psVar3 = psVar2;
    uVar4 = param_1 % 10;
    param_1 = param_1 / 10;
    *psVar3 = (short)uVar4 + 0x30;
    psVar2 = psVar3 + 1;
  } while (param_1 != 0);
  psVar3[1] = 0;
  do {
    sVar1 = *psVar3;
    *psVar3 = *param_2;
    *param_2 = sVar1;
    psVar3 = psVar3 + -1;
    param_2 = param_2 + 1;
  } while (param_2 < psVar3);
  return;
}



/* 40452290 FUN_40452290 */

/* Boundary evidence: original MIPS .pdata 40452290..404522cb. Semantic name remains unreviewed. */

short * FUN_40452290(uint param_1,short *param_2)

{
  FUN_40452210(param_1,param_2,(uint)((int)param_1 < 0));
  return param_2;
}



/* 404522cc FUN_404522cc */

/* Boundary evidence: original MIPS .pdata 404522cc..40452303. Semantic name remains unreviewed. */

short * FUN_404522cc(uint param_1,short *param_2)

{
  FUN_40452210(param_1,param_2,(uint)((int)param_1 < 0));
  return param_2;
}



/* 40452304 FUN_40452304 */

/* Boundary evidence: original MIPS .pdata 40452304..40452333. Semantic name remains unreviewed. */

short * FUN_40452304(uint param_1,short *param_2)

{
  FUN_40452210(param_1,param_2,0);
  return param_2;
}



/* 40452334 FUN_40452334 */

/* Boundary evidence: original MIPS .pdata 40452334..40452397. Semantic name remains unreviewed. */

void FUN_40452334(double param_1,undefined4 param_2,undefined4 param_3,int param_4,LPWSTR param_5,
                 int param_6)

{
  char acStack_38 [40];
  uint local_10;
  
  local_10 = DAT_4046d1b8;
  _gcvt(param_1,param_4,acStack_38);
  MultiByteToWideChar(0,1,acStack_38,-1,param_5,param_6);
  FUN_4046ace8(local_10);
  return;
}



/* 40452398 FUN_40452398 */

/* Boundary evidence: original MIPS .pdata 40452398..4045241f. Semantic name remains unreviewed. */

void FUN_40452398(void)

{
  BOOL BVar1;
  LONG LVar2;
  
  if (((DAT_4046de70 != (HWND)0x0) && (BVar1 = IsWindow(DAT_4046de70), BVar1 != 0)) &&
     (LVar2 = GetWindowLongW(DAT_4046de70,-0x15), LVar2 == DAT_4046d1c0)) {
    DestroyWindow(DAT_4046de70);
    DAT_4046de70 = (HWND)0x0;
  }
  if (DAT_4046de74 != (HANDLE)0x0) {
    WaitForSingleObject(DAT_4046de74,0xffffffff);
  }
  return;
}



/* 40452420 FUN_40452420 */

/* Boundary evidence: original MIPS .pdata 40452420..40452467. Semantic name remains unreviewed. */

LRESULT FUN_40452420(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if (param_2 != 1) {
    if (param_2 != 0x1a) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    FUN_404502dc();
  }
  return 0;
}



/* 40452468 FUN_40452468 */

/* Boundary evidence: original MIPS .pdata 40452468..4045256f. Semantic name remains unreviewed. */

int FUN_40452468(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_30 [12];
  
  iVar4 = (param_1 + -1) / 0x1e;
  iVar1 = param_1 + iVar4 * -0x1e;
  iVar4 = (iVar4 * 0x4ddd2) / 0x1e + 0x376c5;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return iVar4;
    }
    local_30[0] = 2;
    local_30[2] = 7;
    local_30[3] = 10;
    local_30[4] = 0xd;
    local_30[1] = 5;
    local_30[5] = 0xf;
    local_30[7] = 0x15;
    local_30[8] = 0x18;
    local_30[9] = 0x1a;
    local_30[6] = 0x12;
    local_30[10] = 0x1d;
    iVar3 = 0;
    piVar2 = local_30;
    do {
      if (iVar1 % 0x1e == *piVar2) {
        iVar3 = 1;
        goto LAB_40452558;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 0xb);
    iVar3 = 0;
LAB_40452558:
    iVar4 = iVar3 + iVar4 + 0x162;
  } while( true );
}



/* 40452570 FUN_40452570 */

/* Boundary evidence: original MIPS .pdata 40452570..4045265b. Semantic name remains unreviewed. */

int FUN_40452570(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((param_3 % 4 != 0) ||
     (((param_3 % 100 < 1 && (param_3 % 400 != 0)) || (iVar4 = 1, param_2 < 3)))) {
    iVar4 = 0;
  }
  iVar3 = param_3 + -1;
  iVar2 = FUN_40452174(param_2);
  iVar5 = iVar3 / 400;
  iVar1 = iVar3 * 0x16d;
  iVar6 = iVar3 / 100;
  if (iVar3 < 0) {
    iVar3 = param_3 + 2;
  }
  return iVar2 + ((iVar5 + iVar1) - iVar6) + (iVar3 >> 2) + iVar4 + param_1;
}



/* 4045265c FUN_4045265c */

/* Boundary evidence: original MIPS .pdata 4045265c..404526f7. Semantic name remains unreviewed. */

int FUN_4045265c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = ((param_1 + -0x376c5) * 0x1e) / 0x2987;
  iVar1 = FUN_40452468(iVar3 + 1);
  if (iVar1 < param_1) {
    iVar2 = iVar3 + 2;
    iVar1 = FUN_40452468(iVar2);
    iVar3 = iVar3 + 1;
    if (iVar1 < param_1) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}



/* 404526f8 FUN_404526f8 */

/* Boundary evidence: original MIPS .pdata 404526f8..4045283b. Semantic name remains unreviewed. */

int FUN_404526f8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = 1;
  iVar2 = FUN_4045208c(param_1);
  iVar5 = iVar2 + -1;
  if ((iVar2 % 4 == 0) && ((0 < iVar2 % 100 || (iVar2 % 400 == 0)))) {
    iVar3 = iVar2 + -1;
    iVar7 = iVar3 / 400;
    iVar1 = iVar3 * -0x16d;
    iVar8 = iVar3 / 100;
    if (iVar3 < 0) {
      iVar3 = iVar2 + 2;
    }
    iVar4 = 1;
    if (0x3b < (((iVar1 - iVar7) + iVar8) - (iVar3 >> 2)) + param_1) goto LAB_404527b4;
  }
  iVar4 = 0;
LAB_404527b4:
  iVar3 = iVar5 / 400;
  iVar1 = iVar5 * -0x16d;
  iVar7 = iVar5 / 100;
  if (iVar5 < 0) {
    iVar5 = iVar2 + 2;
  }
  while (iVar2 = FUN_40452174(iVar6),
        iVar2 < ((((iVar1 - iVar3) + iVar7) - (iVar5 >> 2)) - iVar4) + param_1) {
    iVar6 = iVar6 + 1;
  }
  return iVar6 + -1;
}



/* 4045283c FUN_4045283c */

/* Boundary evidence: original MIPS .pdata 4045283c..404529af. Semantic name remains unreviewed. */

undefined4 FUN_4045283c(void)

{
  ATOM AVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  undefined4 uVar3;
  MSG MStack_58;
  tagWNDCLASSW local_38;
  
  if (DAT_4046de70 == (HWND)0x0) {
    FUN_404574c4();
    if (DAT_4046de70 != (HWND)0x0) {
      uVar3 = 1;
LAB_404528f4:
      FUN_404574e4();
      return uVar3;
    }
    WaitForAPIReady(0x51,0xffffffff);
    BVar2 = GetClassInfoW(DAT_4046d1c0,L"OLEAUT32",&local_38);
    if (BVar2 == 0) {
      local_38.style = 0;
      local_38.lpfnWndProc = FUN_40452420;
      local_38.cbClsExtra = 0;
      local_38.cbWndExtra = 0;
      local_38.hInstance = DAT_4046d1c0;
      local_38.hIcon = (HICON)0x0;
      local_38.hCursor = (HCURSOR)0x0;
      local_38.hbrBackground = (HBRUSH)0x0;
      local_38.lpszMenuName = (LPCWSTR)0x0;
      local_38.lpszClassName = L"OLEAUT32";
      AVar1 = RegisterClassW(&local_38);
      if (CONCAT22(extraout_var,AVar1) == 0) {
        uVar3 = 0;
        goto LAB_404528f4;
      }
    }
    DAT_4046de70 = CreateWindowExW(0,L"OLEAUT32",(LPCWSTR)0x0,0xc00000,0,0,0,0,(HWND)0x0,(HMENU)0x0,
                                   DAT_4046d1c0,(LPVOID)0x0);
    FUN_404574e4();
    if (DAT_4046de70 == (HWND)0x0) {
      return 0;
    }
    SetWindowLongW(DAT_4046de70,-0x15,(LONG)DAT_4046d1c0);
    while (BVar2 = GetMessageW(&MStack_58,(HWND)0x0,0,0), BVar2 != 0) {
      DispatchMessageW(&MStack_58);
    }
  }
  return 1;
}



/* 404529b0 FUN_404529b0 */

/* Boundary evidence: original MIPS .pdata 404529b0..40452a1f. Semantic name remains unreviewed. */

undefined4 FUN_404529b0(void)

{
  FUN_404574c4();
  if (DAT_4046de74 == (HANDLE)0x0) {
    FUN_40457504();
    DAT_4046de74 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_4045283c,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
    FUN_404502dc();
  }
  FUN_404574e4();
  return 1;
}



/* 40452a20 FUN_40452a20 */

/* Boundary evidence: original MIPS .pdata 40452a20..40452cef. Semantic name remains unreviewed. */

undefined4 FUN_40452a20(short *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  sVar5 = *param_1;
  if (sVar5 < 0) {
LAB_40452cc4:
    uVar3 = 0x80020005;
  }
  else {
    if (sVar5 < 100) {
      if (param_2 == 0) {
        if (sVar5 < 0x1e) {
          sVar6 = 2000;
        }
        else {
          sVar6 = 0x76c;
        }
      }
      else {
        sVar6 = 0x578;
      }
      *param_1 = sVar5 + sVar6;
    }
    iVar7 = 1;
    if (param_3 == 0) {
      if (param_2 != 1) goto LAB_40452cc4;
      if (param_4 == 0) {
        iVar7 = param_1[1] + -1;
        sVar5 = (short)(iVar7 / 0xc);
        if (iVar7 < 0) {
          sVar5 = sVar5 + *param_1 + -1;
          sVar6 = 0xc - (short)(-iVar7 % 0xc);
        }
        else {
          sVar6 = (short)(iVar7 % 0xc);
          sVar5 = sVar5 + *param_1;
        }
        param_1[1] = sVar6 + 1;
        *param_1 = sVar5;
      }
      iVar7 = FUN_40451ff0((int)param_1[1]);
      iVar1 = FUN_40452468((int)*param_1);
      iVar8 = iVar7 + iVar1 + (int)param_1[3];
      iVar7 = FUN_4045208c(iVar8);
      iVar1 = FUN_404526f8(iVar8);
      iVar2 = FUN_40452570(1,iVar1,iVar7);
      iVar8 = ((iVar8 - iVar2) + 1) * 0x10000;
      iVar2 = (int)(short)iVar7;
      param_1[3] = (short)((uint)iVar8 >> 0x10);
      param_1[1] = (short)iVar1;
      *param_1 = (short)iVar7;
      iVar7 = iVar2 + -1;
      iVar1 = FUN_40452570(iVar8 >> 0x10,(int)(short)iVar1,iVar2);
      iVar8 = iVar7 / 400;
      sVar5 = (short)iVar7;
      iVar9 = iVar7 / 100;
      if (iVar7 < 0) {
        iVar7 = iVar2 + 2;
      }
      param_1[8] = (short)iVar1 +
                   (((sVar5 * -0x16d - (short)iVar8) + (short)iVar9) - (short)(iVar7 >> 2));
    }
    else {
      if ((param_3 != 1) || (param_2 != 0)) goto LAB_40452cc4;
      iVar8 = FUN_40452570((int)param_1[3],(int)param_1[1],(int)*param_1);
      iVar1 = 1;
      iVar9 = FUN_4045265c(iVar8);
      iVar2 = FUN_40452468(iVar9);
      iVar8 = iVar8 - iVar2;
      iVar4 = FUN_40451ff0(1);
      iVar2 = iVar4;
      while (iVar2 < iVar8) {
        iVar1 = iVar1 + 1;
        iVar2 = FUN_40451ff0(iVar1);
      }
      iVar1 = (iVar1 + -1) * 0x10000;
      param_1[1] = (short)((uint)iVar1 >> 0x10);
      *param_1 = (short)iVar9;
      while (iVar4 < iVar8) {
        iVar7 = iVar7 + 1;
        iVar4 = FUN_40451ff0(iVar7);
      }
      uVar3 = FUN_40451ff0(iVar7 + -1);
      sVar5 = (short)iVar8 - (short)uVar3;
      param_1[3] = sVar5;
      uVar3 = FUN_40451ff0(iVar1 >> 0x10);
      param_1[8] = (short)uVar3 + sVar5;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 40452cf0 VarDateFromUdate */

/* Boundary evidence: original MIPS .pdata 40452cf0..4045309b. Semantic name remains unreviewed. */

HRESULT VarDateFromUdate(UDATE *pudateIn,ULONG dwFlags,DATE *pdateOut)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  DATE DVar10;
  UDATE local_30;
  
                    /* 0x12cf0  103  VarDateFromUdate */
  if ((dwFlags & 8) != 0) {
    memcpy(&local_30,pudateIn,0x12);
    pudateIn = &local_30;
    iVar3 = FUN_40452a20((short *)&local_30,1,0,(uint)((dwFlags & 4) != 0));
    if (iVar3 != 0) {
      return -0x7ffdfffb;
    }
  }
  uVar6 = (uint)(short)(pudateIn->st).wYear;
  uVar4 = dwFlags & 4;
  iVar3 = (int)(((pudateIn->st).wMonth - 1) * 0x10000) >> 0x10;
  if (uVar4 == 0) {
    iVar5 = iVar3 / 0xc + uVar6;
    if (iVar3 < 0) {
      iVar5 = iVar5 + -1;
      iVar3 = (0xc - -iVar3 % 0xc) * 0x10000;
    }
    else {
      iVar3 = iVar3 % 0xc << 0x10;
    }
    iVar3 = iVar3 >> 0x10;
    uVar6 = iVar5 * 0x10000 >> 0x10;
  }
  if ((int)uVar6 < 100) {
    iVar5 = 2000;
    if (0x1d < (int)uVar6) {
      iVar5 = 0x76c;
    }
    uVar6 = (int)((uVar6 + iVar5) * 0x10000) >> 0x10;
  }
  iVar5 = (int)(short)(pudateIn->st).wDay;
  if (((uVar6 & 3) == 0) && (((int)uVar6 % 100 != 0 || ((int)uVar6 % 400 == 0)))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((((-1 < (int)uVar6) && ((int)uVar6 < 10000)) && (-1 < iVar3)) &&
     ((iVar3 < 0xd &&
      (((uVar4 == 0 ||
        (((iVar3 < 0xc && (0 < iVar5)) &&
         (iVar5 <= (int)((&DAT_404417ec)[iVar3] - (&DAT_404417e8)[iVar3]))))) ||
       (((iVar3 == 1 && (iVar5 == 0x1d)) && (bVar2)))))))) {
    iVar7 = (int)uVar6 / 400;
    iVar1 = uVar6 * 0x16d;
    iVar8 = (int)uVar6 / 100;
    if ((int)uVar6 < 0) {
      uVar6 = uVar6 + 3;
    }
    iVar5 = (((&DAT_404417e8)[iVar3] + iVar7 + iVar1) - iVar8) + ((int)uVar6 >> 2) + iVar5;
    if ((iVar3 < 2) && (bVar2)) {
      iVar5 = iVar5 + -1;
    }
    iVar5 = iVar5 + -0xa96c7;
    if (((iVar5 < 0x2d2482) && (-0xa081b < iVar5)) &&
       ((uVar4 == 0 ||
        ((((pudateIn->st).wHour < 0x18 && ((pudateIn->st).wMinute < 0x3c)) &&
         ((pudateIn->st).wSecond < 0x3c)))))) {
      uVar9 = __litodp(((short)(pudateIn->st).wHour * 0x3c + (int)(short)(pudateIn->st).wMinute) *
                       0x3c + (int)(short)(pudateIn->st).wSecond);
      DVar10 = (DATE)__dpdiv((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0,0x40f51800);
      uVar6 = (uint)((ulonglong)DVar10 >> 0x20);
      if ((dwFlags & 1) == 0) {
        if ((dwFlags & 2) == 0) {
          if (iVar5 < 0) {
            uVar6 = uVar6 ^ 0x80000000;
          }
          uVar9 = __litodp(iVar5);
          DVar10 = (DATE)__dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),SUB84(DVar10,0),uVar6);
        }
        else {
          DVar10 = (DATE)__litodp(iVar5);
        }
        *pdateOut = DVar10;
      }
      else {
        *pdateOut = DVar10;
      }
      return 0;
    }
  }
  return -0x7ffdfffb;
}



/* 4045309c FUN_4045309c */

/* Boundary evidence: original MIPS .pdata 4045309c..404530ef. Semantic name remains unreviewed. */

void FUN_4045309c(UDATE *param_1,undefined2 *param_2,int param_3,ULONG param_4)

{
  HRESULT HVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_3 != 0) {
    param_4 = param_4 | 4;
  }
  HVar1 = VarDateFromUdate(param_1,param_4,(DATE *)&local_10);
  if (HVar1 == 0) {
    *param_2 = 7;
    *(undefined4 *)(param_2 + 4) = local_10;
    *(undefined4 *)(param_2 + 6) = local_c;
  }
  return;
}



/* 404530f0 VarUdateFromDate */

/* Boundary evidence: original MIPS .pdata 404530f0..404534d3. Semantic name remains unreviewed. */

HRESULT VarUdateFromDate(DATE dateIn,ULONG dwFlags,UDATE *pudateOut)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_a0;
  undefined4 in_a1;
  uint uVar5;
  short sVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
                    /* 0x130f0  223  VarUdateFromDate */
  bVar1 = true;
  iVar2 = __ged(in_a0,in_a1,0,0x41469241);
  if ((iVar2 != 0) || (iVar2 = __led(in_a0,in_a1,0,0xc1241036), iVar2 != 0)) {
    return -0x7ffdfffb;
  }
  iVar2 = __gtd(in_a0,in_a1,0,0);
  uVar5 = 0x3ed80000;
  if (iVar2 == 0) {
    uVar5 = 0xbed80000;
  }
  uVar14 = __dpadd(0xa0ce5129,uVar5 | 0x45c8,in_a0,in_a1);
  uVar8 = (undefined4)((ulonglong)uVar14 >> 0x20);
  iVar2 = __led((int)uVar14,uVar8,0x80000000,0x41469240);
  uVar15 = CONCAT44(in_a1,in_a0);
  if ((iVar2 != 0) &&
     (iVar2 = __ged((int)uVar14,uVar8,0,0xc1241036), uVar15 = CONCAT44(in_a1,in_a0), iVar2 != 0)) {
    uVar15 = uVar14;
  }
  uVar5 = (uint)((ulonglong)uVar15 >> 0x20);
  uVar8 = (undefined4)uVar15;
  iVar2 = __dptoli(uVar8,uVar5);
  iVar2 = iVar2 + 0xa96c7;
  iVar3 = __ltd(uVar8,uVar5,0,0);
  if (iVar3 != 0) {
    uVar5 = uVar5 ^ 0x80000000;
  }
  uVar4 = __dptoli(uVar8,uVar5);
  uVar15 = __litodp(uVar4);
  uVar15 = __dpsub(uVar8,uVar5,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
  uVar15 = __dpmul((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,0x40f51800);
  iVar3 = __dptoli((int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  (pudateOut->st).wDayOfWeek = (WORD)((iVar2 + -1) % 7);
  iVar12 = iVar2 % 0x23ab1;
  iVar9 = (iVar12 + -1) / 0x8eac;
  if (iVar9 == 0) {
    iVar10 = iVar12 / 0x5b5;
LAB_40453340:
    iVar12 = iVar12 % 0x5b5;
    sVar6 = (short)iVar10;
    iVar13 = iVar12 + -1;
    iVar11 = iVar13 / 0x16d;
    if (iVar11 != 0) goto LAB_4045335c;
  }
  else {
    iVar13 = (iVar12 + -1) % 0x8eac;
    iVar12 = iVar13 + 1;
    iVar10 = iVar12 / 0x5b5;
    if (iVar10 != 0) goto LAB_40453340;
    iVar11 = iVar13 / 0x16d;
    bVar1 = false;
LAB_4045335c:
    sVar6 = (short)iVar10;
    iVar12 = iVar13 % 0x16d;
  }
  pudateOut->wDayOfYear = (short)iVar12 + 1;
  (pudateOut->st).wYear =
       (((short)(iVar2 / 0x23ab1) * 4 + (short)iVar9) * 0x19 + sVar6) * 4 + (short)iVar11;
  if ((iVar11 == 0) && (bVar1)) {
    if (iVar12 == 0x3b) {
      (pudateOut->st).wMonth = 2;
      (pudateOut->st).wDay = 0x1d;
      goto LAB_40453414;
    }
    if (0x3b < iVar12) {
      iVar12 = iVar12 + -1;
    }
  }
  iVar12 = iVar12 + 1;
  iVar2 = (iVar12 >> 5) + 1;
  for (piVar7 = &DAT_404417e8 + iVar2; *piVar7 < iVar12; piVar7 = piVar7 + 1) {
    iVar2 = iVar2 + 1;
  }
  (pudateOut->st).wMonth = (WORD)iVar2;
  (pudateOut->st).wDay = (short)iVar12 - (short)piVar7[-1];
LAB_40453414:
  if (iVar3 == 0) {
    (pudateOut->st).wHour = 0;
    (pudateOut->st).wMinute = 0;
    (pudateOut->st).wSecond = 0;
  }
  else {
    (pudateOut->st).wSecond = (WORD)(iVar3 % 0x3c);
    (pudateOut->st).wMinute = (WORD)((iVar3 / 0x3c) % 0x3c);
    (pudateOut->st).wHour = (WORD)((iVar3 / 0x3c) / 0x3c);
  }
  if ((dwFlags & 8) != 0) {
    FUN_40452a20((short *)pudateOut,0,1,1);
  }
  return 0;
}



/* 404534d4 FUN_404534d4 */

/* Boundary evidence: original MIPS .pdata 404534d4..40453527. Semantic name remains unreviewed. */

HRESULT FUN_404534d4(DATE param_1,UDATE *param_2,short *param_3,ULONG param_4)

{
  HRESULT HVar1;
  
  if ((*param_3 == 7) || (*param_3 == 5)) {
    HVar1 = VarUdateFromDate(param_1,param_4,param_2);
  }
  else {
    HVar1 = -0x7ff8ffa9;
  }
  return HVar1;
}



/* 40453528 FUN_40453528 */

/* Boundary evidence: original MIPS .pdata 40453528..404537ef. Semantic name remains unreviewed. */

void FUN_40453528(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar14 = param_1[1];
  uVar13 = *param_1 & 0xf8000000;
  uVar15 = __dpsub(*param_1,uVar14,uVar13,uVar14);
  uVar4 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar1 = (undefined4)uVar15;
  uVar12 = param_2[1];
  uVar11 = *param_2 & 0xf8000000;
  uVar15 = __dpsub(*param_2,uVar12,uVar11,uVar12);
  uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar2 = (undefined4)uVar15;
  uVar9 = param_2[2];
  uVar10 = param_2[3];
  uVar15 = __dpmul(uVar2,uVar5,uVar13,uVar14);
  uVar16 = __dpmul(uVar1,uVar4,uVar11,uVar12);
  uVar15 = __dpadd((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar16,
                   (int)((ulonglong)uVar16 >> 0x20));
  uVar6 = (undefined4)((ulonglong)uVar15 >> 0x20);
  uVar16 = __dpmul(uVar13,uVar14,uVar11,uVar12);
  uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar3 = (undefined4)uVar16;
  uVar16 = __dpadd(uVar3,uVar7,(int)uVar15,uVar6);
  uVar16 = __dpsub((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar3,uVar7);
  uVar8 = (undefined4)((ulonglong)uVar16 >> 0x20);
  uVar17 = __dpadd((int)uVar16,uVar8,uVar3,uVar7);
  *(undefined8 *)param_1 = uVar17;
  uVar17 = __dpmul(uVar2,uVar5,uVar1,uVar4);
  uVar18 = __dpmul(uVar9,uVar10,uVar13,uVar14);
  uVar17 = __dpadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
  uVar18 = __dpmul(param_1[2],param_1[3],uVar11,uVar12);
  uVar17 = __dpadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
  uVar18 = __dpmul(uVar2,uVar5,param_1[2],param_1[3]);
  uVar19 = __dpmul(uVar9,uVar10,uVar1,uVar4);
  uVar18 = __dpadd((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                   (int)((ulonglong)uVar19 >> 0x20));
  uVar17 = __dpadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                   (int)((ulonglong)uVar18 >> 0x20));
  uVar15 = __dpsub((int)uVar15,uVar6,(int)uVar16,uVar8);
  uVar15 = __dpadd((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar15,
                   (int)((ulonglong)uVar15 >> 0x20));
  *(undefined8 *)(param_1 + 2) = uVar15;
  return;
}



/* 404537f0 FUN_404537f0 */

/* Boundary evidence: original MIPS .pdata 404537f0..40453b3f. Semantic name remains unreviewed. */

undefined4
FUN_404537f0(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined4 local_30;
  uint local_2c;
  
  uVar6 = (param_5 ^ (int)param_5 >> 0x1f) - ((int)param_5 >> 0x1f);
  iVar3 = __eqd(param_3,param_4,0,0);
  if ((iVar3 == 0) || (0x16 < (int)uVar6)) {
    iVar3 = (uVar6 & 0xf) * 8;
    local_48 = *(uint *)(&DAT_40441210 + iVar3);
    local_44 = *(undefined4 *)(&DAT_40441214 + iVar3);
    uVar4 = (int)uVar6 >> 4 & 0xf;
    local_40 = 0;
    local_3c = 0;
    if (uVar4 != 0) {
      FUN_40453528(&local_48,(uint *)(L"OLEAUT32" + uVar4 * 8 + 8));
    }
    bVar1 = (int)uVar6 >> 4 < 0x10;
    if (!bVar1) {
      if ((int)param_5 < -0x15e) {
        *param_1 = 0;
        param_1[1] = 0;
        return 0;
      }
      if (0x134 < (int)param_5) {
        return 0x8002000a;
      }
      FUN_40453528(&local_48,(uint *)&DAT_40441938);
    }
    uVar2 = local_44;
    uVar6 = local_48;
    uVar4 = *param_1;
    local_38._4_4_ = param_1[1];
    local_38._0_4_ = uVar4;
    local_30 = param_3;
    local_2c = param_4;
    if (-1 < (int)param_5) {
      FUN_40453528((uint *)&local_38,&local_48);
      uVar7 = __dpadd(local_30,local_2c,(uint)local_38,local_38._4_4_);
      uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
      uVar6 = (uint)uVar7;
      *(undefined8 *)param_1 = uVar7;
      if (bVar1) {
        return 0;
      }
      uVar5 = (uVar4 >> 0x14 & 0x7ff) + 0x100;
      if (0x7fe < uVar5) {
        return 0x8002000a;
      }
      param_1[1] = (uVar5 * 0x100000 ^ uVar4) & 0x7ff00000 ^ uVar4;
      goto LAB_40453b08;
    }
    uVar5 = local_38._4_4_;
    if (!bVar1) {
      uVar5 = (((local_38._4_4_ >> 0x14) - 0x100) * 0x100000 ^ local_38._4_4_) & 0x7ff00000 ^
              local_38._4_4_;
      iVar3 = __ned(param_3,param_4,0,0);
      if (iVar3 != 0) {
        param_4 = (((param_4 >> 0x14) - 0x100) * 0x100000 ^ param_4) & 0x7ff00000 ^ param_4;
      }
    }
    local_38 = __dpdiv(uVar4,uVar5,uVar6,uVar2);
    *(undefined8 *)param_1 = local_38;
    local_30 = 0;
    local_2c = 0;
    FUN_40453528((uint *)&local_38,&local_48);
    uVar7 = __dpsub(uVar4,uVar5,(uint)local_38,local_38._4_4_);
    uVar8 = __dpsub(param_3,param_4,local_30,local_2c);
    uVar7 = __dpadd((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                    (int)((ulonglong)uVar7 >> 0x20));
    uVar8 = __dpadd(local_40,local_3c,uVar6,uVar2);
    uVar7 = __dpdiv((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                    (int)((ulonglong)uVar8 >> 0x20));
    uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),*param_1,param_1[1]);
  }
  else if ((int)param_5 < 0) {
    uVar7 = __dpdiv(*param_1,param_1[1],*(undefined4 *)(&DAT_40441210 + uVar6 * 8),
                    *(undefined4 *)(&DAT_40441214 + uVar6 * 8));
  }
  else {
    uVar7 = __dpmul(*(undefined4 *)(&DAT_40441210 + param_5 * 8),
                    *(undefined4 *)(&DAT_40441214 + param_5 * 8),*param_1,param_1[1]);
  }
  uVar6 = (uint)uVar7;
  param_1[1] = (uint)((ulonglong)uVar7 >> 0x20);
LAB_40453b08:
  *param_1 = uVar6;
  return 0;
}



/* 40453b40 FUN_40453b40 */

undefined4 FUN_40453b40(uint param_1,uint param_2,uint param_3,uint param_4,longlong *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)((ulonglong)param_4 * (ulonglong)param_1);
  uVar3 = (uint)((ulonglong)param_4 * (ulonglong)param_1 >> 0x20);
  uVar2 = (int)((ulonglong)param_3 * (ulonglong)param_1 >> 0x20) + uVar1;
  if (uVar2 < uVar1) {
    uVar3 = uVar3 + 1;
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)param_3);
  uVar4 = (uint)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20);
  if (uVar2 + uVar1 < uVar1) {
    uVar4 = uVar4 + 1;
  }
  *param_5 = (ulonglong)param_2 * (ulonglong)param_4 + (ulonglong)uVar3 + (ulonglong)uVar4;
  return (int)((ulonglong)param_3 * (ulonglong)param_1);
}



/* 40453c78 VarNumFromParseNum */

/* WARNING: Removing unreachable block (ram,0x40454978) */
/* WARNING: Removing unreachable block (ram,0x40454a18) */
/* Boundary evidence: original MIPS .pdata 40453c78..40455073. Semantic name remains unreviewed. */

HRESULT VarNumFromParseNum(NUMPARSE *pnumprs,BYTE *rgbDig,ULONG dwVtBits,VARIANT *pvar)

{
  byte bVar1;
  longlong lVar2;
  _union_2685 _Var3;
  ulonglong uVar4;
  longlong lVar5;
  _union_2685 _Var6;
  _union_2685 _Var7;
  ulonglong uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 *puVar11;
  VARTYPE VVar12;
  BYTE *pBVar13;
  BYTE *pBVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  BYTE *pBVar19;
  uint uVar20;
  BYTE *pBVar21;
  uint uVar22;
  BYTE *pBVar23;
  undefined4 *puVar24;
  byte *pbVar25;
  BYTE *pBVar26;
  int iVar27;
  uint uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  byte *local_6c;
  uint local_64;
  int local_60;
  uint local_48;
  uint local_44;
  undefined8 local_40;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
  uVar29 = CONCAT44(local_40._4_4_,(uint)local_40);
                    /* 0x13c78  156  VarNumFromParseNum */
  pBVar26 = (BYTE *)pnumprs->cDig;
  uVar22 = pnumprs->nPwr10;
  puVar11 = &DAT_40441840;
  uVar28 = pnumprs->dwOutFlags;
  pBVar19 = pBVar26 + uVar22;
  uVar16 = pnumprs->nBaseShift;
  uVar20 = 0;
  local_60 = 0;
  local_6c = rgbDig;
  if (uVar16 == 0) {
    if ((int)uVar22 < 0) {
      local_60 = -uVar22;
    }
    uVar16 = dwVtBits & 0x4070;
    pBVar23 = pBVar26;
    if (uVar16 == 0) {
      pBVar23 = pBVar26 + -local_60;
      uVar22 = local_60 + uVar22;
    }
    local_64 = uVar28;
    if ((int)pBVar23 < 10) {
LAB_404542b8:
      pBVar26 = pBVar26 + -(int)pBVar23;
      for (; 0 < (int)pBVar23; pBVar23 = pBVar23 + -1) {
        bVar1 = *local_6c;
        local_6c = local_6c + 1;
        uVar20 = uVar20 * 10 + (uint)bVar1;
      }
      if (0 < (int)pBVar26) {
        bVar1 = *local_6c;
        if (bVar1 < 6) {
          local_6c = local_6c + 1;
          if (bVar1 == 5) {
            if ((uVar28 & 0x20000) == 0) {
              for (; 1 < (int)pBVar26; pBVar26 = pBVar26 + -1) {
                bVar1 = *local_6c;
                local_6c = local_6c + 1;
                if (bVar1 != 0) goto LAB_4045435c;
              }
              if ((uVar20 & 1) == 0) goto LAB_40454188;
            }
LAB_4045435c:
            uVar20 = uVar20 + 1;
          }
        }
        else {
          uVar20 = uVar20 + 1;
        }
      }
    }
    else {
      iVar10 = local_60;
      if (pBVar23 != (BYTE *)0xa) goto LAB_40454674;
      if (*rgbDig < 4) goto LAB_404542b8;
      if (*rgbDig != 4) goto LAB_40454674;
      uVar20 = 0;
      iVar27 = 10;
      do {
        bVar1 = *local_6c;
        local_6c = local_6c + 1;
        iVar27 = iVar27 + -1;
        uVar20 = uVar20 * 10 + (uint)bVar1;
      } while (0 < iVar27);
      if (uVar20 < 4000000000) goto LAB_40454674;
      pBVar26 = rgbDig + ((int)pBVar26 - (int)local_6c);
    }
LAB_40454188:
    uVar15 = uVar20;
    if ((((dwVtBits & 0xf000c) != 0) && ((int)pBVar19 < 0xb)) && ((local_60 == 0 || (uVar16 == 0))))
    {
      uVar16 = uVar20;
      if (0 < (int)uVar22) {
        uVar16 = *(int *)(&DAT_40441050 + uVar22 * 4) * uVar20;
        if (((pBVar19 == (BYTE *)0xa) && (3 < *rgbDig)) && ((4 < *rgbDig || (uVar16 < 4000000000))))
        goto LAB_40453eac;
        uVar22 = 0;
      }
      uVar20 = uVar16;
      if ((uVar28 & 0x10000) != 0) {
        dwVtBits = dwVtBits & 0xfff1ffff;
        uVar20 = -uVar16;
      }
      if (((dwVtBits & 0x30004) != 0) && (uVar16 < 0x8001)) {
        if (((dwVtBits & 0x30000) != 0) && (uVar16 < 0x100)) {
          if ((((dwVtBits & 0x10000) != 0) && (uVar16 < 0x81)) && ((int)uVar20 < 0x80))
          goto LAB_4045428c;
          if ((dwVtBits & 0x20000) != 0) {
LAB_40454370:
            (pvar->n1).n2.vt = 0x11;
            *(char *)((int)&pvar->n1 + 8) = (char)uVar16;
            return 0;
          }
        }
        if (((dwVtBits & 4) != 0) && ((int)uVar20 < 0x8000)) {
LAB_4045439c:
          (pvar->n1).n2.vt = 2;
          *(short *)((int)&pvar->n1 + 8) = (short)uVar20;
          return 0;
        }
      }
      uVar15 = uVar16;
      if ((dwVtBits & 0xc0008) != 0) {
        if (((dwVtBits & 0x40000) != 0) && (uVar16 < 0x10000)) goto LAB_404543dc;
        if (((dwVtBits & 8) != 0) && (uVar16 < 0x80000001)) {
LAB_40454408:
          (pvar->n1).n2.vt = 3;
          *(uint *)((int)&pvar->n1 + 8) = uVar20;
          return 0;
        }
        if ((dwVtBits & 0x80000) != 0) {
LAB_40454428:
          (pvar->n1).n2.vt = 0x13;
          *(uint *)((int)&pvar->n1 + 8) = uVar16;
          return 0;
        }
      }
    }
  }
  else {
    if ((0x21 < (int)((int)pBVar26 * uVar16)) || (((int)pBVar26 * uVar16 == 0x21 && (3 < *rgbDig))))
    {
      return -0x7ffdfff6;
    }
    for (; 0 < (int)pBVar26; pBVar26 = pBVar26 + -1) {
      uVar20 = (uVar20 << (uVar16 & 0x1f)) + (uint)*local_6c;
      local_6c = local_6c + 1;
    }
    if ((dwVtBits & 0xf000c) != 0) {
      uVar16 = uVar20;
      if ((dwVtBits & 0x30000) != 0) {
        if (((dwVtBits & 0x10000) == 0) || ((0xff < uVar20 && (uVar20 < 0xffffff80)))) {
          if (((dwVtBits & 0x20000) != 0) && (uVar20 < 0x100)) goto LAB_40454370;
          goto LAB_40453dec;
        }
LAB_4045428c:
        VVar12 = 0x10;
        *(char *)((int)&pvar->n1 + 8) = (char)uVar20;
        goto LAB_40454294;
      }
LAB_40453dec:
      if ((dwVtBits & 0x40004) == 0) {
LAB_40453e48:
        if ((dwVtBits & 8) != 0) goto LAB_40454408;
        if ((dwVtBits & 0x80000) != 0) goto LAB_40454428;
        goto LAB_40453e64;
      }
      if (((dwVtBits & 4) != 0) && ((uVar20 < 0x10000 || (0xffff7fff < uVar20)))) goto LAB_4045439c;
      if (((dwVtBits & 0x40000) == 0) || (0xffff < uVar20)) goto LAB_40453e48;
LAB_404543dc:
      VVar12 = 0x12;
      *(short *)((int)&pvar->n1 + 8) = (short)uVar16;
      goto LAB_40454294;
    }
LAB_40453e64:
    if ((uVar20 & 0x80000000) != 0) {
      uVar28 = uVar28 | 0x10000;
      pnumprs->dwOutFlags = uVar28;
      uVar20 = -uVar20;
    }
    uVar15 = uVar20;
    local_64 = uVar28;
    if ((9999999 < uVar20) && ((dwVtBits & 0x4060) != 0)) {
      dwVtBits = dwVtBits & 0xffffffef;
    }
  }
LAB_40453eac:
  local_40 = CONCAT44(local_40._4_4_,(uint)local_40);
  if ((dwVtBits & 0x30) != 0) {
    local_40 = uVar29;
    if ((dwVtBits & 0x4040) == 0) goto LAB_40454028;
    local_40 = CONCAT44(local_40._4_4_,(uint)local_40);
    if (local_60 == 0) {
      local_40 = uVar29;
      if ((int)pBVar19 < 8) goto LAB_40454028;
      local_40 = CONCAT44(local_40._4_4_,(uint)local_40);
      if (((int)pBVar19 < 0x10) && (local_40 = uVar29, (dwVtBits & 0x20) != 0)) goto LAB_40454028;
    }
  }
  do {
    uVar28 = local_64;
    if ((((dwVtBits & 0x40) != 0) && ((int)pBVar19 < 0x10)) &&
       ((((dwVtBits & 0x4030) == 0 || (local_60 < 5)) ||
        (((dwVtBits & 0x4020) == 0 && (3 < (int)pBVar19)))))) {
      uVar20 = 0;
      pBVar23 = (BYTE *)(uVar22 + 4);
      local_44 = 0;
      iVar10 = local_60;
      if (-1 < (int)pBVar23) {
        uVar16 = dwVtBits & 0x4070;
        local_48 = uVar15;
        goto LAB_40454530;
      }
      if ((int)pBVar23 < -9) {
        uVar22 = 0;
        goto LAB_40454478;
      }
      uVar17 = *(uint *)(&DAT_40441050 + (int)pBVar23 * -4);
      uVar22 = uVar15 / uVar17;
      if (uVar17 == 0) {
        trap(0x1c00);
      }
      if (uVar17 == 0) {
        trap(0x1c00);
      }
      uVar15 = uVar15 % uVar17 << 1;
      uVar20 = local_44;
      uVar16 = dwVtBits;
      if ((uVar17 < uVar15) ||
         ((uVar15 == uVar17 && (((uVar22 & 1) != 0 || ((local_64 & 0x20000) != 0)))))) {
        uVar22 = uVar22 + 1;
      }
      goto LAB_404544f8;
    }
    if ((((dwVtBits & 0x4000) != 0) && ((int)pBVar19 < 0x1e)) &&
       ((((dwVtBits & 0x30) == 0 || (local_60 < 0x1d)) ||
        (((dwVtBits & 0x20) == 0 && (7 < (pnumprs->cDig - local_60) + 0x1c)))))) {
      if ((int)uVar22 < 10) {
        uVar17 = 0;
        if ((int)uVar22 < 1) {
          uVar4 = 0;
          _Var7.brecVal.pRecInfo = (IRecordInfo *)0x0;
          _Var7.ulVal = uVar15;
          if (-0x1d < (int)uVar22) goto LAB_40454ff0;
          if (-0x26 < (int)uVar22) {
            uVar20 = *(uint *)(&DAT_40441050 + (uVar22 + 0x1c) * -4);
            uVar16 = uVar15 / uVar20;
            if (uVar20 == 0) {
              trap(0x1c00);
            }
            _Var6.brecVal.pRecInfo = (IRecordInfo *)0x0;
            _Var6.ulVal = uVar16;
            _Var7.brecVal.pRecInfo = (IRecordInfo *)0x0;
            _Var7.ulVal = uVar16;
            uVar22 = 0xffffffe4;
            if (uVar20 == 0) {
              trap(0x1c00);
            }
            uVar15 = uVar15 % uVar20 << 1;
            if ((uVar20 < uVar15) ||
               ((uVar15 == uVar20 &&
                (((uVar16 & 1) != 0 || (_Var7 = _Var6, (local_64 & 0x20000) != 0)))))) {
              _Var7.brecVal.pRecInfo = (IRecordInfo *)0x0;
              _Var7.bstrVal = (BSTR)(uVar16 + 1);
            }
LAB_40454ff0:
            (pvar->n1).n2.vt = 0xe;
            *(char *)((int)&pvar->n1 + 2) = -(char)uVar22;
            (pvar->n1).n2.n3 = _Var7;
            (pvar->n1).decVal.Hi32 = uVar17;
            if ((uVar28 & 0x10000) != 0) {
              *(undefined1 *)((int)&pvar->n1 + 3) = 0x80;
              return 0;
            }
            *(undefined1 *)((int)&pvar->n1 + 3) = 0;
            return 0;
          }
          uVar9 = 0;
        }
        else {
          uVar9 = (undefined4)((ulonglong)*(uint *)(&DAT_40441050 + uVar22 * 4) * (ulonglong)uVar15)
          ;
          uVar4 = (ulonglong)*(uint *)(&DAT_40441050 + uVar22 * 4) * (ulonglong)uVar15 >> 0x20;
        }
      }
      else if ((int)uVar22 < 0x13) {
        uVar4 = ((ulonglong)*(uint *)(&DAT_40441050 + (uVar22 - 9) * 4) * (ulonglong)uVar15 &
                0xffffffff) * 1000000000;
        uVar9 = (undefined4)uVar4;
        uVar4 = ((ulonglong)*(uint *)(&DAT_40441050 + (uVar22 - 9) * 4) * (ulonglong)uVar15 >> 0x20)
                * 1000000000 + (uVar4 >> 0x20);
      }
      else {
        if (0x1b < (int)uVar22) {
          uVar15 = *(int *)(&DAT_40441050 + (uVar22 - 0x1b) * 4) * uVar15;
          uVar22 = 0x1b;
        }
        puVar11 = (undefined4 *)
                  ((ulonglong)*(uint *)(&DAT_40441050 + (uVar22 - 0x12) * 4) * (ulonglong)uVar15 >>
                  0x20);
        uVar9 = FUN_40453b40((uint)((ulonglong)*(uint *)(&DAT_40441050 + (uVar22 - 0x12) * 4) *
                                   (ulonglong)uVar15),(uint)puVar11,0xa7640000,0xde0b6b3,
                             (longlong *)&local_38);
        if (local_34 != 0) {
          uVar22 = pnumprs->nPwr10;
          goto LAB_4045401c;
        }
        uVar4 = CONCAT44(local_38,extraout_v1);
      }
      uVar17 = (uint)(uVar4 >> 0x20);
      _Var7.brecVal.pRecInfo = (IRecordInfo *)(int)uVar4;
      _Var7.lVal = uVar9;
      uVar22 = 0;
      goto LAB_40454ff0;
    }
LAB_4045401c:
    if ((dwVtBits & 0x30) == 0) {
      return -0x7ffdfff6;
    }
LAB_40454028:
    uVar29 = __ultodp(uVar15);
    local_40 = uVar29;
    iVar10 = FUN_404537f0((uint *)&local_40,puVar11,0,0,uVar22);
    puVar24 = local_40._4_4_;
    uVar20 = (uint)local_40;
    if ((iVar10 != 0) && (iVar10 < 0)) {
      return iVar10;
    }
    puVar11 = local_40._4_4_;
    iVar10 = __gtd((uint)local_40,local_40._4_4_,0xefffffff,0x47efffff);
    if (iVar10 != 0) {
      dwVtBits = dwVtBits & 0xffffffef;
    }
    if ((local_64 & 0x10000) != 0) {
      puVar24 = (undefined4 *)((uint)puVar24 ^ 0x80000000);
    }
    if (((dwVtBits & 0x10) != 0) &&
       (((dwVtBits & 0x4060) == 0 || (((int)pBVar19 < 8 && (local_60 == 0)))))) {
LAB_404540e0:
      (pvar->n1).n2.vt = 4;
      uVar9 = __dptofp(uVar20,puVar24);
      *(undefined4 *)((int)&pvar->n1 + 8) = uVar9;
      return 0;
    }
  } while ((dwVtBits & 0x20) == 0);
  VVar12 = 5;
  *(uint *)((int)&pvar->n1 + 8) = uVar20;
  *(undefined4 **)((int)&pvar->n1 + 0xc) = puVar24;
LAB_40454294:
  (pvar->n1).n2.vt = VVar12;
  return 0;
LAB_404544f8:
  do {
    if ((uVar28 & 0x10000) == 0) {
      if (-1 < (int)uVar20) break;
    }
    else {
      if (uVar22 == 0) {
        uVar20 = -uVar20;
      }
      else {
        uVar22 = -uVar22;
        uVar20 = ~uVar20;
      }
      if ((int)uVar20 < 1) break;
    }
LAB_4045465c:
    do {
      do {
        uVar20 = 0xffffffbf;
LAB_4045466c:
        uVar16 = uVar16 & uVar20;
        uVar29 = local_40;
LAB_40454674:
        while( true ) {
          puVar11 = &DAT_40441840;
          if (uVar16 == 0) {
            return -0x7ffdfff6;
          }
          pBVar26 = (BYTE *)pnumprs->cDig;
          uVar22 = pnumprs->nPwr10;
          if (((uVar16 & 0x4040) == 0) ||
             ((((uVar16 & 0x20) != 0 && (iVar10 == 0)) && ((int)pBVar26 < 0x10)))) {
            uVar29 = 0;
            local_40._0_4_ = 0;
            local_40._4_4_ = (undefined4 *)0x0;
            pBVar19 = pBVar26;
            if (0xe < (int)pBVar26) {
              pBVar19 = (BYTE *)0xf;
            }
            iVar10 = (int)pBVar26 - (int)pBVar19;
            for (; 0 < (int)pBVar19; pBVar19 = pBVar19 + -1) {
              uVar29 = __dpmul((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),0,0x40240000);
              puVar11 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
              uVar30 = __ultodp(*rgbDig);
              uVar29 = __dpadd((int)uVar29,puVar11,(int)uVar30,(int)((ulonglong)uVar30 >> 0x20));
              rgbDig = rgbDig + 1;
            }
            uVar30 = 0;
            iVar27 = iVar10;
            local_40 = uVar29;
            if (0 < iVar10) {
              do {
                local_40 = uVar29;
                uVar29 = __dpmul((int)uVar30,(int)((ulonglong)uVar30 >> 0x20),0,0x40240000);
                uVar30 = __ultodp(*rgbDig);
                uVar30 = __dpadd((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),(int)uVar30,
                                 (int)((ulonglong)uVar30 >> 0x20));
                puVar11 = (undefined4 *)((ulonglong)uVar30 >> 0x20);
                iVar27 = iVar27 + -1;
                rgbDig = rgbDig + 1;
                uVar29 = local_40;
              } while (0 < iVar27);
              uVar30 = __dpdiv((int)uVar30,puVar11,*(undefined4 *)(&DAT_40441210 + iVar10 * 8),
                               *(undefined4 *)(&DAT_40441214 + iVar10 * 8));
              uVar22 = iVar10 + uVar22;
            }
            iVar10 = FUN_404537f0((uint *)&local_40,puVar11,(int)uVar30,
                                  (uint)((ulonglong)uVar30 >> 0x20),uVar22);
            puVar24 = local_40._4_4_;
            uVar20 = (uint)local_40;
            if ((iVar10 != 0) && (iVar10 < 0)) {
              return iVar10;
            }
            iVar10 = __gtd((uint)local_40,local_40._4_4_,0xefffffff,0x47efffff);
            if (iVar10 != 0) {
              uVar16 = uVar16 & 0xffef;
            }
            if ((local_64 & 0x10000) != 0) {
              puVar24 = (undefined4 *)((uint)puVar24 ^ 0x80000000);
            }
            if ((uVar16 & 0x20) == 0) {
              if ((uVar16 & 0x10) == 0) {
                return -0x7ffdfff6;
              }
              goto LAB_404540e0;
            }
            VVar12 = 5;
            *(uint *)((int)&pvar->n1 + 8) = uVar20;
            *(undefined4 **)((int)&pvar->n1 + 0xc) = puVar24;
            goto LAB_40454294;
          }
          local_40 = uVar29;
          if ((((uVar16 & 0x40) != 0) && ((int)pBVar19 < 0x10)) &&
             (((((uVar16 & 0x4030) == 0 || (iVar10 < 5)) ||
               (((uVar16 & 0x4000) == 0 && (0xb < (int)pBVar19)))) ||
              (((uVar16 & 0x20) == 0 && (3 < (int)pBVar19)))))) break;
          if ((((uVar16 & 0x4000) != 0) && ((int)pBVar19 < 0x1e)) &&
             ((((uVar16 & 0x30) == 0 ||
               ((iVar10 < 0x1d || (0xf < (int)(pBVar26 + (0x1c - iVar10)))))) ||
              (((uVar16 & 0x20) == 0 && (7 < (int)(pBVar26 + (0x1c - iVar10))))))))
          goto LAB_4045476c;
          uVar16 = uVar16 & 0xffffbfbf;
        }
        uVar20 = 0;
        pBVar21 = pBVar19 + 4;
        local_48 = 0;
        local_44 = 0;
        pBVar23 = pBVar21;
        if ((int)pBVar21 < 1) {
          pBVar23 = (BYTE *)0x0;
        }
        pBVar13 = pBVar26;
        if (((int)pBVar23 < (int)pBVar26) && (pBVar13 = pBVar21, (int)pBVar21 < 1)) {
          pBVar13 = (BYTE *)0x0;
        }
        pBVar26 = pBVar26 + -(int)pBVar13;
        pBVar23 = pBVar26 + uVar22 + 4;
        pBVar21 = pBVar13;
        local_6c = rgbDig;
        if ((int)pBVar13 < 10) break;
        if ((int)pBVar13 < 0x13) {
          pBVar14 = pBVar13 + -9;
          pBVar21 = pBVar13 + -(int)pBVar14;
          do {
            bVar1 = *local_6c;
            local_6c = local_6c + 1;
            pBVar14 = pBVar14 + -1;
            uVar20 = uVar20 * 10 + (uint)bVar1;
            local_48 = uVar20;
          } while (pBVar14 != (BYTE *)0x0);
        }
        else {
          local_30 = (uint)*rgbDig;
          local_6c = rgbDig + 1;
          local_2c = 0;
          FUN_40458764(local_30,0,1000000000,&local_30);
          pBVar21 = pBVar13 + -1;
          if (9 < (int)pBVar21) {
            pBVar13 = pBVar13 + -10;
            pBVar21 = pBVar21 + -(int)pBVar13;
            do {
              bVar1 = *local_6c;
              local_6c = local_6c + 1;
              pBVar13 = pBVar13 + -1;
              local_48 = local_48 * 10 + (uint)bVar1;
            } while (pBVar13 != (BYTE *)0x0);
          }
          local_48 = local_30 + local_48;
          local_44 = local_2c + local_44;
          uVar29 = local_40;
          if (local_48 < local_30) {
            local_44 = local_44 + 1;
          }
        }
        local_40 = uVar29;
        iVar27 = FUN_40458764(local_48,local_44,1000000000,&local_48);
        uVar20 = local_48;
        uVar28 = local_64;
      } while (iVar27 < 0);
      uVar22 = 0;
      for (; 0 < (int)pBVar21; pBVar21 = pBVar21 + -1) {
        bVar1 = *local_6c;
        local_6c = local_6c + 1;
        uVar22 = uVar22 * 10 + (uint)bVar1;
      }
      local_48 = uVar20 + uVar22;
      if (local_48 < uVar22) {
        local_44 = local_44 + 1;
      }
LAB_40454530:
      if ((int)pBVar23 < 1) {
        uVar22 = local_48;
        uVar20 = local_44;
        if ((0 < (int)pBVar26) && (pBVar23 == (BYTE *)0x0)) {
          if (5 < *local_6c) goto LAB_40454628;
          if (*local_6c == 5) {
            if ((uVar28 & 0x20000) != 0) goto LAB_40454628;
            goto joined_r0x404545f8;
          }
        }
        break;
      }
      for (; uVar28 = local_64, 9 < (int)pBVar23; pBVar23 = pBVar23 + -9) {
        iVar27 = FUN_40458764(local_48,local_44,1000000000,&local_48);
        if (iVar27 < 0) goto LAB_4045465c;
      }
      iVar27 = FUN_40458764(local_48,local_44,*(uint *)(&DAT_40441050 + (int)pBVar23 * 4),&local_48)
      ;
      uVar22 = local_48;
      uVar20 = local_44;
    } while (iVar27 < 0);
  } while( true );
LAB_40454478:
  VVar12 = 6;
  *(uint *)((int)&pvar->n1 + 8) = uVar22;
  *(uint *)((int)&pvar->n1 + 0xc) = uVar20;
  goto LAB_40454294;
joined_r0x404545f8:
  if ((int)pBVar26 < 2) goto LAB_4045461c;
  local_6c = local_6c + 1;
  if (*local_6c != 0) goto LAB_40454628;
  pBVar26 = pBVar26 + -1;
  goto joined_r0x404545f8;
LAB_4045461c:
  if ((local_48 & 1) != 0) {
LAB_40454628:
    uVar22 = local_48 + 1;
    if (uVar22 == 0) {
      uVar20 = local_44 + 1;
    }
  }
  goto LAB_404544f8;
LAB_4045476c:
  pBVar21 = pBVar19 + 0x1c;
  pBVar23 = pBVar21;
  if ((int)pBVar21 < 1) {
    pBVar23 = (BYTE *)0x0;
  }
  pBVar13 = pBVar26;
  if (((int)pBVar23 < (int)pBVar26) && (pBVar13 = pBVar21, (int)pBVar21 < 1)) {
    pBVar13 = (BYTE *)0x0;
  }
  if ((int)pBVar13 < 0x1d) {
    pBVar13 = pBVar21;
    if ((int)pBVar21 < 1) {
      pBVar13 = (BYTE *)0x0;
    }
    pBVar23 = pBVar26;
    if (((int)pBVar13 < (int)pBVar26) && (pBVar23 = pBVar21, (int)pBVar21 < 1)) {
      pBVar23 = (BYTE *)0x0;
    }
  }
  else {
    pBVar23 = (BYTE *)0x1d;
  }
  iVar27 = (int)pBVar26 - (int)pBVar23;
  pBVar26 = pBVar19;
  if ((int)pBVar19 <= (int)pBVar23) {
    pBVar26 = pBVar23;
  }
  local_38 = 0;
  local_34 = 0;
  uVar22 = uVar22 + iVar27;
  lVar5 = 0;
  uVar15 = 0;
  uVar20 = 0;
  iVar18 = 0;
  pbVar25 = rgbDig;
  if (9 < (int)pBVar26) {
    lVar2 = 0;
    if (0x1b < (int)pBVar26) {
      do {
        if ((int)pBVar23 < 1) break;
        bVar1 = *pbVar25;
        pBVar26 = pBVar26 + -1;
        pbVar25 = pbVar25 + 1;
        uVar15 = uVar15 * 10 + (uint)bVar1;
        pBVar23 = pBVar23 + -1;
      } while (0x1b < (int)pBVar26);
      iVar10 = local_60;
      lVar2 = lVar5;
      if (uVar15 != 0) {
        lVar2 = (ulonglong)uVar15 * 1000000000;
      }
    }
    uVar15 = 0;
    for (; (0x12 < (int)pBVar26 && (0 < (int)pBVar23)); pBVar23 = pBVar23 + -1) {
      bVar1 = *pbVar25;
      pBVar26 = pBVar26 + -1;
      pbVar25 = pbVar25 + 1;
      uVar15 = uVar15 * 10 + (uint)bVar1;
    }
    lVar2 = lVar2 + (ulonglong)uVar15;
    lVar5 = 0;
    if (lVar2 != 0) {
      uVar9 = FUN_40453b40((uint)lVar2,(uint)((ulonglong)lVar2 >> 0x20),0xa7640000,0xde0b6b3,
                           (longlong *)&local_38);
      lVar5 = CONCAT44(extraout_v1_00,uVar9);
      uVar15 = 0;
      uVar28 = local_64;
    }
    for (; (9 < (int)pBVar26 && (0 < (int)pBVar23)); pBVar23 = pBVar23 + -1) {
      bVar1 = *pbVar25;
      pBVar26 = pBVar26 + -1;
      pbVar25 = pbVar25 + 1;
      uVar15 = uVar15 * 10 + (uint)bVar1;
    }
    uVar20 = local_38;
    iVar18 = local_34;
    if (uVar15 != 0) {
      uVar4 = (ulonglong)uVar15 * 1000000000;
      uVar8 = lVar5 + uVar4;
      lVar5 = uVar4 + lVar5;
      if (uVar8 < uVar4) {
        uVar20 = local_38 + 1;
        iVar18 = local_34 + (uint)(uVar20 < local_38);
      }
    }
  }
  uVar15 = 0;
  for (; 0 < (int)pBVar23; pBVar23 = pBVar23 + -1) {
    bVar1 = *pbVar25;
    pbVar25 = pbVar25 + 1;
    uVar15 = uVar15 * 10 + (uint)bVar1;
  }
  if ((int)uVar22 < 1) {
    _Var3.brecVal.pRecInfo = (IRecordInfo *)0x0;
    _Var3.ulVal = uVar15;
  }
  else {
    _Var3 = (_union_2685)((ulonglong)*(uint *)(&DAT_40441050 + uVar22 * 4) * (ulonglong)uVar15);
    uVar22 = 0;
  }
  _Var6.llVal = lVar5 + _Var3.llVal;
  uVar17 = uVar20;
  if ((ulonglong)_Var6 < (ulonglong)_Var3) {
    uVar17 = uVar20 + 1;
    iVar18 = iVar18 + (uint)(uVar17 < uVar20);
  }
  if (iVar18 == 0) {
    _Var7 = _Var6;
    if ((iVar27 < 1) || ((int)pBVar19 < -0x1d)) goto LAB_40454ff0;
    if (*pbVar25 < 6) {
      if (*pbVar25 != 5) goto LAB_40454ff0;
      if ((uVar28 & 0x20000) == 0) {
        for (; 1 < iVar27; iVar27 = iVar27 + -1) {
          pbVar25 = pbVar25 + 1;
          if (*pbVar25 != 0) goto LAB_40454ab8;
        }
        if ((_Var6.ulVal & 1) != 1) goto LAB_40454ff0;
      }
    }
LAB_40454ab8:
    _Var7.llVal = _Var6.llVal + 1;
    if ((_Var6.ulVal != 0xffffffff || (int)((longlong)_Var6 + 1U >> 0x20) != 0) ||
       (uVar17 = uVar17 + 1, _Var7.llVal = _Var6.llVal + 1, uVar17 != 0)) goto LAB_40454ff0;
  }
  uVar20 = 0xffffbfff;
  goto LAB_4045466c;
}



/* 40455074 VarParseNumFromStr */

/* Boundary evidence: original MIPS .pdata 40455074..40455a73. Semantic name remains unreviewed. */

HRESULT VarParseNumFromStr(LPCOLESTR strIn,LCID lcid,ULONG dwFlags,NUMPARSE *pnumprs,BYTE *rgbDig)

{
  OLECHAR OVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  LPCOLESTR pOVar10;
  LPCOLESTR pOVar11;
  uint uVar12;
  BYTE *pBVar13;
  uint uVar14;
  BYTE *pBVar15;
  int iVar16;
  int iVar17;
  LPCOLESTR local_5c;
  int local_58;
  BYTE *local_54;
  uint local_50;
  LPCOLESTR local_4c;
  NUMPARSE *local_48;
  int local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  
                    /* 0x15074  157  VarParseNumFromStr */
  iVar16 = 0;
  local_5c = (LPCOLESTR)0x0;
  if ((rgbDig == (BYTE *)0x0) || (pnumprs == (NUMPARSE *)0x0)) {
    return -0x7ff8ffa9;
  }
  iVar17 = 0;
  local_2c = 0;
  uVar14 = pnumprs->dwInFlags;
  uVar12 = 0;
  pBVar15 = rgbDig + pnumprs->cDig;
  local_40 = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_54 = pBVar15;
  local_50 = uVar14;
  local_48 = pnumprs;
  local_3c = uVar14;
  if (strIn == (LPCOLESTR)0x0) {
    iVar16 = -0x7ffdfffb;
    goto LAB_40455a24;
  }
  uVar6 = lcid & 0x3ff;
  if (((uVar6 == 4) || ((0x10 < uVar6 && (uVar6 < 0x13)))) &&
     ((iVar4 = FUN_40445834(lcid,strIn,&local_5c), strIn = local_5c, iVar4 != 0 && (iVar4 < 0)))) {
    return iVar4;
  }
  uVar6 = (uint)(ushort)*strIn;
  pOVar11 = strIn + 1;
  local_4c = pOVar11;
  iVar4 = iswctype(*strIn,8);
  if ((iVar4 != 0) && ((uVar14 & 1) != 0)) {
    uVar12 = 1;
    local_38 = 1;
    do {
      uVar6 = (uint)(ushort)*pOVar11;
      iVar4 = iswctype(*pOVar11,8);
      pOVar11 = pOVar11 + 1;
    } while (iVar4 != 0);
  }
  pBVar13 = rgbDig;
  if ((uVar6 == 0x26) && ((uVar14 & 0x40) != 0)) {
    uVar6 = (uint)(ushort)*pOVar11;
    bVar2 = false;
    if ((uVar6 == 0x68) || (uVar6 == 0x48)) {
      local_30 = 4;
      iVar17 = 0xf;
LAB_40455224:
      uVar6 = (uint)(ushort)pOVar11[1];
      pOVar10 = pOVar11 + 2;
    }
    else {
      local_30 = 3;
      iVar17 = 7;
      if ((uVar6 == 0x6f) || (pOVar10 = pOVar11 + 1, uVar6 == 0x4f)) goto LAB_40455224;
    }
    pOVar11 = pOVar10;
    if (uVar6 == 0x30) {
      bVar2 = true;
      do {
        uVar6 = (uint)(ushort)*pOVar11;
        pOVar11 = pOVar11 + 1;
      } while (uVar6 == 0x30);
    }
    while( true ) {
      if ((uVar6 < 0x30) || (0x39 < uVar6)) {
        if ((uVar6 < 0x61) || (0x66 < uVar6)) {
          if ((uVar6 < 0x41) || (0x46 < uVar6)) goto LAB_404552e4;
          iVar4 = uVar6 - 0x37;
        }
        else {
          iVar4 = uVar6 - 0x57;
        }
      }
      else {
        iVar4 = uVar6 - 0x30;
      }
      if (iVar17 < iVar4) goto LAB_404552e4;
      if (pBVar15 <= pBVar13) break;
      *pBVar13 = (BYTE)iVar4;
      uVar6 = (uint)(ushort)*pOVar11;
      pBVar13 = pBVar13 + 1;
      pOVar11 = pOVar11 + 1;
    }
    iVar16 = -0x7ffdfff6;
LAB_404552e4:
    if (pBVar13 == rgbDig) {
      if (!bVar2) {
LAB_40455a08:
        iVar16 = -0x7ffdfffb;
        goto LAB_40455a10;
      }
      *pBVar13 = '\0';
      pBVar13 = pBVar13 + 1;
    }
    local_38 = uVar12 | 0x40;
    iVar17 = iswctype((wint_t)uVar6,8);
    if ((iVar17 != 0) && ((uVar14 & 2) != 0)) {
      local_38 = uVar12 | 0x42;
      do {
        uVar6 = (uint)(ushort)*pOVar11;
        iVar17 = iswctype(*pOVar11,8);
        pOVar11 = pOVar11 + 1;
      } while (iVar17 != 0);
    }
    goto LAB_4045534c;
  }
  iVar4 = 0;
  bVar2 = false;
  local_58 = 0;
  iVar16 = FUN_404442a8(lcid,dwFlags);
  if (-1 < iVar16) {
    uVar7 = (uint)DAT_4046d1f0;
    do {
      if ((0x2f < uVar6) && (uVar6 < 0x3a)) {
LAB_40455590:
        uVar8 = (uint)DAT_4046d1f4;
        uVar9 = (uint)DAT_4046d1f2;
        goto LAB_404555a4;
      }
      iVar5 = iswctype((wint_t)uVar6,8);
      if (iVar5 == 0) {
        if (uVar6 == 0x2b) {
          if (((uVar14 & 4) != 0) && ((uVar12 & 0xbc) == 0)) {
            uVar12 = uVar12 | 4;
            goto LAB_40455540;
          }
          goto LAB_40455a08;
        }
        if (uVar6 == 0x2d) {
          if (((uVar14 & 0x10) != 0) && ((uVar12 & 0xbc) == 0)) {
            uVar6 = 0x10010;
LAB_40455450:
            uVar12 = uVar12 | uVar6;
            goto LAB_40455540;
          }
          goto LAB_40455a08;
        }
        if (uVar6 == 0x28) {
          if (((uVar14 & 0x80) != 0) && ((uVar12 & 0xbc) == 0)) {
            uVar6 = 0x10080;
            bVar2 = true;
            goto LAB_40455450;
          }
          goto LAB_40455a08;
        }
        uVar7 = (uint)DAT_4046d1f0;
        if (uVar6 == uVar7) {
          uVar6 = (uint)(ushort)*pOVar11;
          pOVar11 = pOVar11 + 1;
          if ((((uVar14 & 0x100) != 0) && (0x2f < uVar6)) && (uVar6 < 0x3a)) {
            uVar12 = uVar12 | 0x100;
            iVar4 = -1;
            local_38 = uVar12;
            goto LAB_40455590;
          }
          goto LAB_40455a08;
        }
        if (((uVar14 & 0x400) == 0) || ((uVar12 & 0x400) != 0)) goto LAB_40455a08;
        if (DAT_4046d1d8 == 0) {
          pOVar11 = pOVar11 + -1;
          pOVar10 = pOVar11 + DAT_4046d1d4;
          while (pOVar11 < pOVar10) {
            OVar1 = *pOVar11;
            pOVar11 = pOVar11 + 1;
            if (OVar1 == L'\0') goto LAB_40455a08;
          }
          iVar5 = CompareStringW(lcid,1,pOVar11 + -DAT_4046d1d4,DAT_4046d1d4,(PCNZWCH)&DAT_4046d1dc,
                                 DAT_4046d1d4);
          if (iVar5 == 2) {
            uVar12 = uVar12 | 0x400;
            goto LAB_40455540;
          }
          goto LAB_40455a08;
        }
        if (uVar6 != DAT_4046d1dc) goto LAB_40455a08;
        uVar12 = uVar12 | 0x400;
      }
      else {
        if ((uVar14 & 1) == 0) goto LAB_40455a08;
        uVar12 = uVar12 | 1;
LAB_40455540:
        uVar7 = (uint)DAT_4046d1f0;
      }
      uVar6 = (uint)(ushort)*pOVar11;
      pOVar11 = pOVar11 + 1;
      local_38 = uVar12;
    } while( true );
  }
LAB_40455a10:
  if (local_5c != (LPCOLESTR)0x0) {
    FUN_4044427c(local_5c);
  }
LAB_40455a24:
  memcpy(local_48,&local_40,0x18);
  return iVar16;
LAB_404555a4:
  if (uVar6 == 0x30) {
    iVar17 = iVar4 + iVar17;
    local_2c = iVar17;
LAB_404556ec:
    uVar6 = (uint)(ushort)*pOVar11;
    pOVar11 = pOVar11 + 1;
    goto LAB_404555a4;
  }
  if ((uVar6 == uVar9) || (uVar6 == uVar8)) {
    if ((uVar6 != 0) && ((uVar14 & 0x200) != 0)) {
      uVar12 = uVar12 | 0x200;
      local_38 = uVar12;
      goto LAB_404556ec;
    }
    goto LAB_4045599c;
  }
  do {
    while ((0x2f < uVar6 && (uVar6 < 0x3a))) {
      if (pBVar13 < local_54) {
        iVar17 = iVar4 + iVar17;
        *pBVar13 = (char)uVar6 + 0xd0;
        uVar8 = (uint)DAT_4046d1f4;
        uVar9 = (uint)DAT_4046d1f2;
        uVar7 = (uint)DAT_4046d1f0;
        pBVar13 = pBVar13 + 1;
        local_2c = iVar17;
      }
      else {
        if (uVar6 != 0x30) {
          uVar12 = uVar12 | 0x20000;
          local_38 = uVar12;
        }
        iVar17 = iVar4 + iVar17 + 1;
        local_2c = iVar17;
      }
LAB_404556c0:
      OVar1 = *pOVar11;
      pOVar11 = pOVar11 + 1;
      uVar6 = (uint)(ushort)OVar1;
    }
    if ((uVar6 == uVar9) || (uVar6 == uVar8)) {
      if ((uVar6 != 0) && ((uVar14 & 0x200) != 0)) {
        uVar12 = uVar12 | 0x200;
        local_38 = uVar12;
        goto LAB_404556c0;
      }
      goto LAB_4045599c;
    }
    if (uVar6 != uVar7) {
      bVar3 = bVar2;
      if (((((uVar6 != 0x65) && (uVar6 != 0x45)) && (uVar6 != 100)) && (uVar6 != 0x44)) ||
         ((uVar14 & 0x800) == 0)) goto joined_r0x40455818;
      uVar6 = (uint)(ushort)*pOVar11;
      pOVar10 = pOVar11 + 1;
      if (uVar6 == 0x2d) {
        iVar4 = 1;
LAB_4045575c:
        uVar6 = (uint)(ushort)*pOVar10;
        pOVar10 = pOVar11 + 2;
      }
      else {
        iVar4 = local_58;
        if (uVar6 == 0x2b) goto LAB_4045575c;
      }
      if ((0x2f < uVar6) && (uVar6 < 0x3a)) goto LAB_404557bc;
      uVar6 = (uint)(ushort)pOVar11[-1];
      goto joined_r0x40455818;
    }
    if (((uVar14 & 0x100) == 0) || ((uVar12 & 0x100) != 0)) goto LAB_4045599c;
    uVar12 = uVar12 | 0x100;
    uVar6 = (uint)(ushort)*pOVar11;
    iVar4 = -1;
    pOVar11 = pOVar11 + 1;
    local_38 = uVar12;
  } while (pBVar13 != rgbDig);
  goto LAB_404555a4;
LAB_404557bc:
  iVar5 = uVar6 - 0x30;
  uVar6 = (uint)(ushort)*pOVar10;
  if ((uVar6 < 0x30) || (0x39 < uVar6)) goto LAB_404557d4;
  if (0x6666665 < iVar5) {
    iVar16 = -0x7ffdfff6;
    goto LAB_4045599c;
  }
  uVar6 = iVar5 * 10 + uVar6;
  pOVar10 = pOVar10 + 1;
  goto LAB_404557bc;
LAB_404557d4:
  pOVar11 = pOVar10 + 1;
  if (iVar4 != 0) {
    iVar5 = -iVar5;
  }
  iVar17 = iVar5 + iVar17;
  uVar12 = uVar12 | 0x800;
  local_38 = uVar12;
  local_2c = iVar17;
joined_r0x40455818:
  do {
    if (uVar6 == 0) break;
    iVar4 = iswctype((wint_t)uVar6,8);
    if (iVar4 == 0) {
      if (uVar6 == 0x29) {
        if (bVar3) {
          bVar2 = false;
          bVar3 = false;
        }
        else {
LAB_404558d0:
          if (((uVar14 & 0x400) == 0) || ((uVar12 & 0x400) != 0)) break;
          if (DAT_4046d1d8 == 0) {
            pOVar11 = pOVar11 + -1;
            pOVar10 = pOVar11 + DAT_4046d1d4;
            while (pOVar11 < pOVar10) {
              OVar1 = *pOVar11;
              pOVar11 = pOVar11 + 1;
              if (OVar1 == L'\0') goto LAB_40455990;
            }
            iVar4 = CompareStringW(lcid,1,pOVar11 + -DAT_4046d1d4,DAT_4046d1d4,
                                   (PCNZWCH)&DAT_4046d1dc,DAT_4046d1d4);
            if (iVar4 != 2) {
LAB_40455990:
              pOVar11 = pOVar10 + (1 - DAT_4046d1d4);
              break;
            }
          }
          else if (uVar6 != DAT_4046d1dc) break;
          uVar12 = uVar12 | 0x400;
          local_38 = uVar12;
        }
      }
      else if (uVar6 == 0x2b) {
        if (((uVar14 & 8) == 0) || ((uVar12 & 0xbc) != 0)) break;
        uVar12 = uVar12 | 8;
        local_38 = uVar12;
      }
      else {
        if (uVar6 != 0x2d) goto LAB_404558d0;
        if (((uVar14 & 0x20) == 0) || ((uVar12 & 0xbc) != 0)) break;
        uVar12 = uVar12 | 0x10020;
        local_38 = uVar12;
      }
    }
    else {
      if ((uVar14 & 2) == 0) break;
      uVar12 = uVar12 | 2;
      local_38 = uVar12;
    }
    uVar6 = (uint)(ushort)*pOVar11;
    pOVar11 = pOVar11 + 1;
  } while( true );
LAB_4045599c:
  while ((rgbDig + 1 < pBVar13 && (uVar14 = local_50, pBVar13[-1] == '\0'))) {
    iVar17 = iVar17 + 1;
    pBVar13 = pBVar13 + -1;
    local_2c = iVar17;
  }
  if (pBVar13 == rgbDig) {
    *pBVar13 = '\0';
    pBVar13 = pBVar13 + 1;
  }
  if (bVar2) {
    iVar16 = -0x7ffdfffb;
  }
LAB_4045534c:
  local_40 = (int)pBVar13 - (int)rgbDig;
  local_34 = (int)pOVar11 - (int)local_4c >> 1;
  if ((uVar6 != 0) && ((uVar14 & 0x1000) != 0)) {
    iVar16 = -0x7ffdfffb;
  }
  goto LAB_40455a10;
}



/* 40455a74 VariantInit */

void VariantInit(VARIANTARG *pvarg)

{
                    /* 0x15a74  229  VariantInit */
  (pvarg->n1).n2.vt = 0;
  return;
}



/* 40455a7c FUN_40455a7c */

/* Boundary evidence: original MIPS .pdata 40455a7c..40455af7. Semantic name remains unreviewed. */

undefined4 FUN_40455a7c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __ged(param_1,param_2,0,0x41469241);
  if ((iVar1 == 0) && (iVar1 = __led(param_1,param_2,0,0xc1241036), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80020005;
  }
  return uVar2;
}



/* 40455af8 FUN_40455af8 */

undefined4 FUN_40455af8(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & 0x6000) != 0) {
    param_1 = param_1 & 0x9fff;
  }
  if ((((param_1 < 2) || (0xe < param_1)) && ((param_1 < 0x10 || (0x13 < param_1)))) &&
     ((param_1 != 0x16 && (param_1 != 0x17)))) {
    uVar1 = 0x80020008;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40455b70 VariantClear */

/* Boundary evidence: original MIPS .pdata 40455b70..40455cab. Semantic name remains unreviewed. */

HRESULT VariantClear(VARIANTARG *pvarg)

{
  ushort uVar1;
  int iVar2;
  HRESULT HVar3;
  uint uVar4;
  LPVOID pvVar5;
  int *piVar6;
  
                    /* 0x15b70  226  VariantClear */
  uVar4 = (uint)(pvarg->n1).n2.vt;
  if (7 < uVar4) {
    if ((uVar4 & 0xffffbfff) == 0x48) {
      pvVar5 = (LPVOID)(pvarg->n1).decVal.Hi32;
      if (pvVar5 != (LPVOID)0x0) {
        FUN_40458abc(pvVar5);
      }
    }
    else if (((0xb < uVar4) && (iVar2 = FUN_40455af8(uVar4), iVar2 != 0)) && (iVar2 < 0)) {
      return iVar2;
    }
    if (uVar4 == 8) {
      SysFreeString(*(BSTR *)((int)&pvarg->n1 + 8));
    }
    else if (((uVar4 == 9) || (uVar4 == 0xd)) || (uVar4 == 0x48)) {
      piVar6 = *(int **)((int)&pvarg->n1 + 8);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 8))();
      }
    }
    else {
      uVar1 = (pvarg->n1).n2.vt;
      if ((((uVar1 & 0x2000) != 0) && ((uVar1 & 0x4000) == 0)) &&
         ((HVar3 = SafeArrayDestroy(*(SAFEARRAY **)((int)&pvarg->n1 + 8)), HVar3 != 0 && (HVar3 < 0)
          ))) {
        return HVar3;
      }
    }
  }
  (pvarg->n1).n2.vt = 0;
  return 0;
}



/* 40455cac VariantCopy */

/* Boundary evidence: original MIPS .pdata 40455cac..40455df3. Semantic name remains unreviewed. */

HRESULT VariantCopy(VARIANTARG *pvargDest,VARIANTARG *pvargSrc)

{
  ushort uVar1;
  int iVar2;
  HRESULT HVar3;
  int *piVar4;
  uint uVar5;
  
                    /* 0x15cac  227  VariantCopy */
  uVar1 = (pvargSrc->n1).n2.vt;
  uVar5 = (uint)uVar1;
  if (((uVar5 < 0xc) || (iVar2 = FUN_40455af8(uVar5), iVar2 == 0)) || (-1 < iVar2)) {
    if (pvargDest != pvargSrc) {
      HVar3 = VariantClear(pvargDest);
      if ((HVar3 != 0) && (HVar3 < 0)) {
        return HVar3;
      }
      if ((uVar5 & 0x6000) == 0x2000) {
        HVar3 = SafeArrayCopy(*(SAFEARRAY **)((int)&pvargSrc->n1 + 8),
                              (SAFEARRAY **)((int)&pvargDest->n1 + 8));
        if ((HVar3 != 0) && (HVar3 < 0)) {
          return HVar3;
        }
        (pvargDest->n1).n2.vt = uVar1;
      }
      else if (uVar5 == 8) {
        iVar2 = FUN_4044bb64(*(LPCSTR *)((int)&pvargSrc->n1 + 8),
                             (undefined4 *)((int)&pvargDest->n1 + 8));
        if ((iVar2 != 0) && (iVar2 < 0)) {
          return iVar2;
        }
        (pvargDest->n1).n2.vt = 8;
      }
      else {
        *(undefined4 *)&pvargDest->n1 = *(undefined4 *)&pvargSrc->n1;
        (pvargDest->n1).decVal.Hi32 = (pvargSrc->n1).decVal.Hi32;
        *(undefined4 *)((int)&pvargDest->n1 + 8) = *(undefined4 *)((int)&pvargSrc->n1 + 8);
        *(undefined4 *)((int)&pvargDest->n1 + 0xc) = *(undefined4 *)((int)&pvargSrc->n1 + 0xc);
        if (((uVar5 == 9) || (uVar5 == 0xd)) &&
           (piVar4 = *(int **)((int)&pvargDest->n1 + 8), piVar4 != (int *)0x0)) {
          (**(code **)(*piVar4 + 4))();
        }
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* 40455df4 VariantCopyInd */

/* Boundary evidence: original MIPS .pdata 40455df4..40456047. Semantic name remains unreviewed. */

HRESULT VariantCopyInd(VARIANT *pvarDest,VARIANTARG *pvargSrc)

{
  ushort uVar1;
  HRESULT HVar2;
  int iVar3;
  int *piVar4;
  VARIANTARG *pvargSrc_00;
  undefined4 uVar5;
  undefined4 *puVar6;
  ushort uVar7;
  
                    /* 0x15df4  228  VariantCopyInd */
  if (((pvargSrc->n1).n2.vt & 0x4000) == 0) {
    HVar2 = VariantCopy(pvarDest,pvargSrc);
    return HVar2;
  }
  if (((pvarDest != pvargSrc) && (HVar2 = VariantClear(pvarDest), HVar2 != 0)) && (HVar2 < 0)) {
    return HVar2;
  }
  uVar1 = (pvargSrc->n1).n2.vt;
  uVar7 = uVar1 & 0xbfff;
  switch(uVar7) {
  case 2:
  case 0xb:
  case 0x12:
    *(undefined2 *)((int)&pvarDest->n1 + 8) = **(undefined2 **)((int)&pvargSrc->n1 + 8);
    break;
  case 3:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    *(undefined4 *)((int)&pvarDest->n1 + 8) = **(undefined4 **)((int)&pvargSrc->n1 + 8);
    break;
  case 4:
    *(undefined4 *)((int)&pvarDest->n1 + 8) = **(undefined4 **)((int)&pvargSrc->n1 + 8);
    break;
  case 5:
  case 7:
    puVar6 = *(undefined4 **)((int)&pvargSrc->n1 + 8);
    *(undefined4 *)((int)&pvarDest->n1 + 8) = *puVar6;
    uVar5 = puVar6[1];
    goto LAB_40455f38;
  case 6:
    puVar6 = *(undefined4 **)((int)&pvargSrc->n1 + 8);
    *(undefined4 *)((int)&pvarDest->n1 + 8) = *puVar6;
    uVar5 = puVar6[1];
LAB_40455f38:
    *(undefined4 *)((int)&pvarDest->n1 + 0xc) = uVar5;
    break;
  case 8:
    iVar3 = FUN_4044bb64((LPCSTR)**(undefined4 **)((int)&pvargSrc->n1 + 8),
                         (undefined4 *)((int)&pvarDest->n1 + 8));
    goto joined_r0x40456010;
  case 9:
    piVar4 = (int *)**(int **)((int)&pvargSrc->n1 + 8);
    *(int **)((int)&pvarDest->n1 + 8) = piVar4;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))();
    }
    break;
  case 0xc:
    pvargSrc_00 = *(VARIANTARG **)((int)&pvargSrc->n1 + 8);
    if ((pvargSrc_00->n1).n2.vt == 0x400c) {
      return -0x7ff8ffa9;
    }
    HVar2 = VariantCopyInd(pvarDest,pvargSrc_00);
    if (HVar2 == 0) {
      return 0;
    }
    if (-1 < HVar2) {
      return 0;
    }
    return HVar2;
  case 0xd:
    piVar4 = (int *)**(int **)((int)&pvargSrc->n1 + 8);
    *(int **)((int)&pvarDest->n1 + 8) = piVar4;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 4))();
    }
    break;
  case 0xe:
    puVar6 = *(undefined4 **)((int)&pvargSrc->n1 + 8);
    *(undefined4 *)&pvarDest->n1 = *puVar6;
    (pvarDest->n1).decVal.Hi32 = puVar6[1];
    *(undefined4 *)((int)&pvarDest->n1 + 8) = puVar6[2];
    *(undefined4 *)((int)&pvarDest->n1 + 0xc) = puVar6[3];
    break;
  default:
    if ((uVar1 & 0x2000) == 0) {
      return -0x7ff8ffa9;
    }
    iVar3 = SafeArrayCopy((SAFEARRAY *)**(undefined4 **)((int)&pvargSrc->n1 + 8),
                          (SAFEARRAY **)((int)&pvarDest->n1 + 8));
joined_r0x40456010:
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    break;
  case 0x10:
  case 0x11:
    *(undefined1 *)((int)&pvarDest->n1 + 8) = **(undefined1 **)((int)&pvargSrc->n1 + 8);
  }
  (pvarDest->n1).n2.vt = uVar7;
  return 0;
}



/* 40456048 VariantChangeTypeEx */

/* Boundary evidence: original MIPS .pdata 40456048..4045745f. Semantic name remains unreviewed. */

HRESULT VariantChangeTypeEx(VARIANTARG *pvargDest,VARIANTARG *pvarSrc,LCID lcid,USHORT wFlags,
                           VARTYPE vt)

{
  _union_2685 _Var1;
  undefined2 uVar2;
  int iVar3;
  HRESULT HVar4;
  int iVar5;
  PVOID pvVar6;
  undefined *puVar7;
  SHORT SVar8;
  int *piVar9;
  undefined4 *puVar10;
  code *pcVar11;
  uint uVar12;
  IUnknown *This;
  uint dwFlags;
  uint uVar13;
  FLOAT in_f12;
  undefined4 in_f13;
  _union_2685 _Var14;
  undefined1 local_58 [8];
  CY local_50;
  _union_2683 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
                    /* 0x16048  225  VariantChangeTypeEx */
  uVar12 = (uint)vt;
  uVar13 = (uint)(pvarSrc->n1).n2.vt;
  if (0xb < uVar12) {
    iVar3 = FUN_40455af8(uVar12);
    if ((iVar3 != 0) && (iVar3 < 0)) {
      return iVar3;
    }
    if (((vt & 0xe000) != 0) && (uVar12 != 0x2011)) {
      return -0x7ffdfffb;
    }
  }
  dwFlags = 0x80000000;
  iVar3 = 0;
  if ((wFlags & 4) == 0) {
    dwFlags = 0;
  }
  local_48.n2.vt = 0;
LAB_40456108:
  _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
  _Var14.lVal = local_50.s.Lo;
  uVar2 = local_50.s.Lo._2_2_;
  switch(uVar13 * 0x18 + (uint)vt) {
  case 0:
  case 1:
  case 0x19:
  case 0x30:
  case 0x31:
  case 0x48:
  case 0x49:
  case 0x60:
  case 0x61:
  case 0x78:
  case 0x79:
  case 0x90:
  case 0x91:
  case 0xa8:
  case 0xa9:
  case 0xc0:
  case 0xc1:
  case 0xd8:
  case 0xd9:
  case 0x108:
  case 0x109:
  case 0x138:
  case 0x139:
  case 0x150:
  case 0x151:
  case 0x180:
  case 0x181:
  case 0x198:
  case 0x199:
  case 0x1b0:
  case 0x1b1:
  case 0x1c8:
  case 0x1c9:
  case 0x210:
  case 0x211:
  case 0x228:
  case 0x229:
    break;
  case 2:
  case 0xb:
  case 0x12:
    _Var14 = (_union_2685)((ulonglong)CONCAT42(local_50.s.Hi,uVar2) << 0x10);
    break;
  case 3:
  case 4:
  case 0x13:
  case 0x16:
  case 0x17:
    goto switchD_4045613c_caseD_3;
  case 5:
  case 6:
  case 7:
    _Var14.llVal = 0.0;
    break;
  case 8:
    iVar3 = FUN_4044bad4(L"",(undefined4 *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  default:
    if (uVar13 < 0xc) {
LAB_40457368:
      _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
      _Var14.lVal = local_50.s.Lo;
      if ((uVar13 == 0x2011) && (uVar12 == 8)) {
        iVar3 = BstrFromVector((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                               (BSTR *)(local_58 + 8));
        _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
        _Var14.lVal = local_50.s.Lo;
      }
      else if (uVar12 == 0x2011) {
        if (uVar13 == 8) {
          iVar3 = VectorFromBstr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                                 (SAFEARRAY **)(local_58 + 8));
          _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
          _Var14.lVal = local_50.s.Lo;
        }
        else {
          if (uVar13 != 0x2011) goto LAB_404573d4;
          iVar3 = SafeArrayCopy((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                                (SAFEARRAY **)(local_58 + 8));
          _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
          _Var14.lVal = local_50.s.Lo;
        }
      }
      else {
LAB_404573d4:
        iVar3 = -0x7ffdfffb;
      }
      break;
    }
    iVar3 = FUN_40455af8(uVar13);
    _Var1.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var1.lVal = local_50.s.Lo;
    if (iVar3 < 0) goto LAB_404566d4;
    if ((uVar13 & 0x4000) == 0) goto LAB_40457368;
    uVar13 = uVar13 & 0xbfff;
    pvarSrc = (VARIANTARG *)(((__tagVARIANT *)pvarSrc)->n3).parray;
    if (uVar13 != 0xe) {
      if (uVar13 == 0xc) goto code_r0x404566bc;
      pvarSrc = (VARIANTARG *)((int)&pvarSrc[-1].n1 + 8);
    }
    goto LAB_40456108;
  case 0xe:
    local_58._4_4_ = 0;
    local_58._0_4_ = local_58._0_4_ & 0xffff;
    _Var14.llVal = 0.0;
    break;
  case 0x10:
  case 0x11:
    _Var14 = (_union_2685)((ulonglong)CONCAT43(local_50.s.Hi,local_50.s.Lo._1_3_) << 8);
    break;
  case 0x32:
  case 0x42:
  case 0x10a:
  case 0x113:
  case 0x11a:
    SVar8 = (((__tagVARIANT *)pvarSrc)->n3).iVal;
    goto LAB_4045677c;
  case 0x33:
  case 0x43:
  case 0x46:
  case 0x47:
  case 0x10b:
  case 0x11b:
  case 0x11e:
  case 0x11f:
    _Var14.lVal = (LONG)(int)(((__tagVARIANT *)pvarSrc)->n3).iVal;
    break;
  case 0x34:
  case 0x10c:
    pvVar6 = (PVOID)(int)(((__tagVARIANT *)pvarSrc)->n3).iVal;
    goto LAB_404567b0;
  case 0x35:
  case 0x10d:
    pvVar6 = (PVOID)(int)(((__tagVARIANT *)pvarSrc)->n3).iVal;
    goto LAB_404567c8;
  case 0x36:
  case 0x10e:
    iVar3 = VarCyFromI2((((__tagVARIANT *)pvarSrc)->n3).iVal,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x37:
  case 0x10f:
    pvVar6 = (PVOID)(int)(((__tagVARIANT *)pvarSrc)->n3).iVal;
    goto LAB_4045680c;
  case 0x38:
switchD_4045613c_caseD_38:
    iVar3 = VarBstrFromI2((((__tagVARIANT *)pvarSrc)->n3).iVal,lcid,dwFlags,(BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x3b:
    local_50.s.Lo._0_2_ = 0xffff;
    if ((((__tagVARIANT *)pvarSrc)->n3).iVal == 0) {
      local_50.s.Lo._0_2_ = 0;
    }
    local_50.s.Lo = CONCAT22(uVar2,local_50.s.Lo._0_2_);
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x3e:
  case 0x116:
    iVar3 = VarDecFromI2((((__tagVARIANT *)pvarSrc)->n3).iVal,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x40:
    iVar3 = VarI1FromI2((((__tagVARIANT *)pvarSrc)->n3).iVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x41:
    iVar3 = VarUI1FromI2((((__tagVARIANT *)pvarSrc)->n3).iVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x4a:
  case 0x212:
    iVar3 = VarI2FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                        (SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x4b:
  case 0x5b:
  case 0x5e:
  case 0x5f:
  case 100:
  case 0xfa:
  case 0x1cb:
  case 0x1db:
  case 0x1de:
  case 0x1df:
  case 0x213:
  case 0x223:
  case 0x226:
  case 0x227:
  case 0x22b:
  case 0x23b:
  case 0x23e:
  case 0x23f:
    goto switchD_4045613c_caseD_4b;
  case 0x4c:
  case 0x214:
    pvVar6 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    goto LAB_404567b0;
  case 0x4d:
  case 0x215:
    pvVar6 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
LAB_404567c8:
    _Var14.llVal = (LONGLONG)__litodp(pvVar6);
    break;
  case 0x4e:
  case 0x216:
    iVar3 = VarCyFromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,(CY *)(local_58 + 8))
    ;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x4f:
  case 0x217:
    pvVar6 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    goto LAB_4045680c;
  case 0x50:
  case 0x218:
    iVar3 = VarBstrFromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                          (BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x53:
  case 0x1d3:
  case 0x21b:
  case 0x233:
    local_50.s.Lo._0_2_ = 0xffff;
    if ((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord != (PVOID)0x0) goto LAB_40456944;
    goto LAB_40456940;
  case 0x56:
  case 0x21e:
    iVar3 = VarDecFromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,(DECIMAL *)local_58)
    ;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x58:
  case 0x220:
    iVar3 = VarI1FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x59:
  case 0x221:
    iVar3 = VarUI1FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x5a:
  case 0x222:
    iVar3 = VarUI2FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x62:
    iVar3 = VarI2FromR4(in_f12,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 99:
  case 0x76:
    iVar3 = VarI4FromR4(in_f12,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x65:
    _Var14.llVal = (LONGLONG)__fptodp((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord);
    break;
  case 0x66:
    iVar3 = VarCyFromR4(in_f12,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x67:
    local_50.int64 = (LONGLONG)__fptodp((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord);
    goto LAB_40456814;
  case 0x68:
    iVar3 = VarBstrFromR4(in_f12,lcid,dwFlags,(BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x6b:
    iVar5 = __nes((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,0);
    goto LAB_40456a20;
  case 0x6e:
    iVar3 = VarDecFromR4(in_f12,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x70:
    iVar3 = VarI1FromR4(in_f12,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x71:
    iVar3 = VarUI1FromR4(in_f12,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x72:
    iVar3 = VarUI2FromR4(in_f12,(USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x73:
  case 0x77:
    iVar3 = VarUI4FromR4(in_f12,(ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x7a:
  case 0xaa:
    iVar3 = VarI2FromR8((DOUBLE)CONCAT44(in_f13,in_f12),(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x7b:
  case 0x8e:
  case 0xab:
  case 0xbe:
    iVar3 = VarI4FromR8((DOUBLE)CONCAT44(in_f13,in_f12),(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x7c:
  case 0xac:
    iVar3 = VarR4FromR8((DOUBLE)CONCAT44(in_f13,in_f12),(FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x7d:
  case 0x96:
  case 0xad:
  case 0xaf:
    goto switchD_4045613c_caseD_7d;
  case 0x7e:
  case 0xae:
    iVar3 = VarCyFromR8((DOUBLE)CONCAT44(in_f13,in_f12),(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x7f:
    iVar3 = FUN_40455a7c((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (((__tagVARIANT *)pvarSrc)->n3).brecVal.pRecInfo);
switchD_4045613c_caseD_7d:
    _Var14.brecVal = *(_union_2685 *)&(((__tagVARIANT *)pvarSrc)->n3).brecVal;
    break;
  case 0x80:
    iVar3 = VarBstrFromR8((DOUBLE)CONCAT44(in_f13,in_f12),lcid,dwFlags,(BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x83:
  case 0xb3:
    iVar5 = __ned((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                  (((__tagVARIANT *)pvarSrc)->n3).brecVal.pRecInfo,0,0);
LAB_40456a20:
    SVar8 = -1;
    if (iVar5 == 0) {
      SVar8 = 0;
    }
    goto LAB_4045677c;
  case 0x86:
  case 0xb6:
    iVar3 = VarDecFromR8((DOUBLE)CONCAT44(in_f13,in_f12),(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x88:
  case 0xb8:
    iVar3 = VarI1FromR8((DOUBLE)CONCAT44(in_f13,in_f12),local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x89:
  case 0xb9:
    iVar3 = VarUI1FromR8((DOUBLE)CONCAT44(in_f13,in_f12),local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x8a:
  case 0xba:
    iVar3 = VarUI2FromR8((DOUBLE)CONCAT44(in_f13,in_f12),(USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x8b:
  case 0x8f:
  case 0xbb:
  case 0xbf:
    iVar3 = VarUI4FromR8((DOUBLE)CONCAT44(in_f13,in_f12),(ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x92:
    iVar3 = VarI2FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x93:
  case 0xa6:
    iVar3 = VarI4FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x94:
    iVar3 = VarR4FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x95:
    iVar3 = VarR8FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(DOUBLE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x97:
    iVar3 = VarDateFromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(DATE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x98:
    iVar3 = VarBstrFromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,lcid,dwFlags,(BSTR *)(local_58 + 8))
    ;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x9b:
    iVar3 = VarBoolFromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(VARIANT_BOOL *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x9e:
    iVar3 = VarDecFromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xa0:
    iVar3 = VarI1FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xa1:
    iVar3 = VarUI1FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xa2:
    iVar3 = VarUI2FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xa3:
  case 0xa7:
    iVar3 = VarUI4FromCy((((__tagVARIANT *)pvarSrc)->n3).cyVal,(ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xb0:
    uVar12 = 8;
    if ((wFlags & 8) == 0) {
      uVar12 = 0;
    }
    iVar3 = VarBstrFromDate((DATE)CONCAT44(in_f13,in_f12),lcid,uVar12 | dwFlags,
                            (BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xc2:
    iVar3 = VarI2FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                         (SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xc3:
  case 0xd6:
    iVar3 = VarI4FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                         (LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xc4:
    iVar3 = VarR4FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                         (FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xc5:
    iVar3 = VarR8FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                         (DOUBLE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xc6:
    iVar3 = VarCyFromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                         (CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 199:
    uVar12 = 8;
    if ((wFlags & 8) == 0) {
      uVar12 = 0;
    }
    iVar3 = VarDateFromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,uVar12 | dwFlags,
                           (DATE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 200:
    iVar3 = FUN_4044bb64((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (undefined4 *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xcb:
    iVar3 = VarBoolFromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                           (VARIANT_BOOL *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xce:
    iVar3 = VarDecFromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                          (DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xd0:
    iVar3 = VarI1FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,local_58 + 8)
    ;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xd1:
    iVar3 = VarUI1FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,local_58 + 8
                         );
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xd2:
    iVar3 = VarUI2FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                          (USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xd3:
  case 0xd7:
    iVar3 = VarUI4FromStr((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                          (ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0xda:
  case 0xdb:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
  case 0xe0:
  case 0xe3:
  case 0xe6:
  case 0xe8:
  case 0xe9:
  case 0xea:
  case 0xeb:
  case 0xee:
  case 0xef:
    This = (((__tagVARIANT *)pvarSrc)->n3).punkVal;
    if (((wFlags & 1) == 0) && (This != (IUnknown *)0x0)) {
      (*This->lpVtbl->AddRef)(This);
      local_30 = 0;
      local_38 = 0;
      local_2c = 0;
      local_34 = 0;
      HVar4 = (*This->lpVtbl[2].QueryInterface)(This,(IID *)0x0,(void **)&DAT_40443ecc);
      (*This->lpVtbl->Release)(This);
      if ((HVar4 == 0) && (uVar13 = (uint)local_48.n2.vt, uVar13 != 9)) {
        pvarSrc = (VARIANTARG *)&local_48;
        iVar3 = 0;
        goto LAB_40456108;
      }
    }
    iVar3 = -0x7ffdfffb;
    goto LAB_404566d4;
  case 0xe1:
  case 0x145:
    piVar9 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 4))();
    }
switchD_4045613c_caseD_4b:
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.byref = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    break;
  case 0xe5:
    puVar10 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    if (puVar10 == (undefined4 *)0x0) goto switchD_4045613c_caseD_3;
    pcVar11 = *(code **)*puVar10;
    puVar7 = &DAT_40443ebc;
LAB_40456ff8:
    iVar3 = (*pcVar11)(puVar10,puVar7,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x110:
    if ((wFlags & 2) == 0) goto switchD_4045613c_caseD_38;
    iVar3 = VarBstrFromBool((((__tagVARIANT *)pvarSrc)->n3).boolVal,lcid,dwFlags,
                            (BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x118:
    iVar3 = VarI1FromBool((((__tagVARIANT *)pvarSrc)->n3).boolVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x119:
    iVar3 = VarI1FromBool((((__tagVARIANT *)pvarSrc)->n3).boolVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x141:
    puVar10 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
    if (puVar10 != (undefined4 *)0x0) {
      pcVar11 = *(code **)*puVar10;
      puVar7 = &DAT_40443edc;
      goto LAB_40456ff8;
    }
switchD_4045613c_caseD_3:
    _Var14 = (_union_2685)((ulonglong)(uint)local_50.s.Hi << 0x20);
    break;
  case 0x152:
    iVar3 = VarI2FromDec((DECIMAL *)pvarSrc,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x153:
  case 0x166:
    iVar3 = VarI4FromDec((DECIMAL *)pvarSrc,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x154:
    iVar3 = VarR4FromDec((DECIMAL *)pvarSrc,(FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x155:
    iVar3 = VarR8FromDec((DECIMAL *)pvarSrc,(DOUBLE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x156:
    iVar3 = VarCyFromDec((DECIMAL *)pvarSrc,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x157:
    iVar3 = VarDateFromDec((DECIMAL *)pvarSrc,(DATE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x158:
    iVar3 = VarBstrFromDec((DECIMAL *)pvarSrc,lcid,dwFlags,(BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x15b:
    iVar3 = VarBoolFromDec((DECIMAL *)pvarSrc,(VARIANT_BOOL *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x15e:
    local_58._0_4_ = *(undefined4 *)pvarSrc;
    local_58._4_4_ = ((DECIMAL *)pvarSrc)->Hi32;
    _Var14.brecVal = *(_union_2685 *)&(((__tagVARIANT *)pvarSrc)->n3).brecVal;
    break;
  case 0x160:
    iVar3 = VarI1FromDec((DECIMAL *)pvarSrc,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x161:
    iVar3 = VarUI1FromDec((DECIMAL *)pvarSrc,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x162:
    iVar3 = VarUI2FromDec((DECIMAL *)pvarSrc,(USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x163:
  case 0x167:
    iVar3 = VarUI4FromDec((DECIMAL *)pvarSrc,(ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x182:
    iVar3 = VarI2FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x183:
  case 0x196:
    iVar3 = VarI4FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x184:
    iVar3 = VarR4FromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x185:
    iVar3 = VarR8FromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(DOUBLE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x186:
    iVar3 = VarCyFromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x187:
    pvVar6 = (PVOID)(int)(((__tagVARIANT *)pvarSrc)->n3).cVal;
LAB_4045680c:
    local_50.int64 = (LONGLONG)__litodp(pvVar6);
LAB_40456814:
    iVar3 = FUN_40455a7c((PVOID)local_50.s.Lo,(IRecordInfo *)local_50.s.Hi);
    _Var14.llVal = local_50.int64;
    break;
  case 0x188:
    iVar3 = VarBstrFromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,lcid,dwFlags,(BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x18b:
    uVar12 = (uint)(((__tagVARIANT *)pvarSrc)->n3).cVal;
    goto LAB_404570d0;
  case 0x18e:
    iVar3 = VarDecFromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 400:
  case 0x191:
    local_50.s.Lo._0_1_ = (((__tagVARIANT *)pvarSrc)->n3).bVal;
    goto LAB_404570e4;
  case 0x192:
    iVar3 = VarUI2FromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x193:
  case 0x197:
    iVar3 = VarUI4FromI1((((__tagVARIANT *)pvarSrc)->n3).cVal,(ULONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19a:
    iVar3 = VarI2FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19b:
  case 0x1ae:
    iVar3 = VarI4FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19c:
    iVar3 = VarR4FromUI1((((__tagVARIANT *)pvarSrc)->n3).bVal,(FLOAT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19d:
    iVar3 = VarR8FromUI1((((__tagVARIANT *)pvarSrc)->n3).bVal,(DOUBLE *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19e:
    iVar3 = VarCyFromUI1((((__tagVARIANT *)pvarSrc)->n3).bVal,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x19f:
    pvVar6 = (PVOID)(uint)(((__tagVARIANT *)pvarSrc)->n3).bVal;
    goto LAB_40457194;
  case 0x1a0:
    iVar3 = VarBstrFromUI1((((__tagVARIANT *)pvarSrc)->n3).bVal,lcid,dwFlags,(BSTR *)(local_58 + 8))
    ;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1a3:
    uVar12 = (uint)(((__tagVARIANT *)pvarSrc)->n3).bVal;
LAB_404570d0:
    local_50.s.Lo._0_2_ = 0xffff;
    if (uVar12 == 0) {
LAB_40456940:
      local_50.s.Lo._0_2_ = 0;
    }
LAB_40456944:
    local_50.s.Lo = CONCAT22(uVar2,local_50.s.Lo._0_2_);
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1a6:
    iVar3 = VarDecFromUI1((((__tagVARIANT *)pvarSrc)->n3).bVal,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1a8:
  case 0x1a9:
    local_50.s.Lo._0_1_ = (((__tagVARIANT *)pvarSrc)->n3).bVal;
LAB_404570e4:
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1aa:
    iVar3 = VarI2FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1ab:
  case 0x1af:
    iVar3 = VarI4FromBool((((__tagVARIANT *)pvarSrc)->n3).cVal,(LONG *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1b2:
  case 0x1c2:
    SVar8 = (((__tagVARIANT *)pvarSrc)->n3).iVal;
LAB_4045677c:
    local_50.s.Lo._0_2_ = SVar8;
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1b3:
  case 0x1c3:
  case 0x1c6:
  case 0x1c7:
    _Var14.lVal._2_2_ = 0;
    _Var14.iVal = (((__tagVARIANT *)pvarSrc)->n3).uiVal;
    break;
  case 0x1b4:
    pvVar6 = (PVOID)(uint)(((__tagVARIANT *)pvarSrc)->n3).uiVal;
LAB_404567b0:
    pvVar6 = (PVOID)__litofp(pvVar6);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = (LONG)pvVar6;
    break;
  case 0x1b5:
    pvVar6 = (PVOID)(uint)(((__tagVARIANT *)pvarSrc)->n3).uiVal;
    goto LAB_40457218;
  case 0x1b6:
    iVar3 = VarCyFromUI2((((__tagVARIANT *)pvarSrc)->n3).uiVal,(CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1b7:
    pvVar6 = (PVOID)(uint)(((__tagVARIANT *)pvarSrc)->n3).uiVal;
    goto LAB_40457194;
  case 0x1b8:
    iVar3 = VarBstrFromUI2((((__tagVARIANT *)pvarSrc)->n3).uiVal,lcid,dwFlags,(BSTR *)(local_58 + 8)
                          );
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1bb:
    local_50.s.Lo._0_2_ = 0xffff;
    if ((((__tagVARIANT *)pvarSrc)->n3).iVal == 0) goto LAB_40456940;
    goto LAB_40456944;
  case 0x1be:
    iVar3 = VarDecFromUI2((((__tagVARIANT *)pvarSrc)->n3).uiVal,(DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1c0:
    iVar3 = VarI1FromUI1((uint)(((__tagVARIANT *)pvarSrc)->n3).uiVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1c1:
    iVar3 = VarUI1FromI4((uint)(((__tagVARIANT *)pvarSrc)->n3).uiVal,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1ca:
  case 0x22a:
    iVar3 = VarI2FromUI2((ULONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (SHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1cc:
  case 0x22c:
    pvVar6 = (PVOID)__ultofp((((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = (LONG)pvVar6;
    break;
  case 0x1cd:
  case 0x22d:
    pvVar6 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
LAB_40457218:
    _Var14.llVal = (LONGLONG)__ultodp(pvVar6);
    break;
  case 0x1ce:
  case 0x22e:
    iVar3 = VarCyFromUI4((ULONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (CY *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1cf:
  case 0x22f:
    pvVar6 = (((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord;
LAB_40457194:
    local_50.int64 = (LONGLONG)__ultodp(pvVar6);
    goto LAB_40456814;
  case 0x1d0:
  case 0x230:
    iVar3 = VarBstrFromUI4((ULONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,lcid,dwFlags,
                           (BSTR *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1d6:
  case 0x236:
    iVar3 = VarDecFromUI4((ULONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                          (DECIMAL *)local_58);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1d8:
  case 0x238:
    iVar3 = VarI1FromUI1((ULONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1d9:
  case 0x239:
    iVar3 = VarUI1FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,local_58 + 8);
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
    break;
  case 0x1da:
  case 0x23a:
    iVar3 = VarUI2FromI4((LONG)(((__tagVARIANT *)pvarSrc)->n3).brecVal.pvRecord,
                         (USHORT *)(local_58 + 8));
    _Var14.brecVal.pRecInfo = (IRecordInfo *)local_50.s.Hi;
    _Var14.lVal = local_50.s.Lo;
  }
  local_50.int64 = _Var14.llVal;
  if (iVar3 < 0) goto LAB_404566d4;
  local_58._0_2_ = vt;
  if (7 < (pvargDest->n1).n2.vt) {
    iVar3 = VariantClear(pvargDest);
    if (iVar3 < 0) {
      VariantClear((VARIANTARG *)local_58);
      goto LAB_404566d4;
    }
  }
  *(undefined4 *)&pvargDest->n1 = local_58._0_4_;
  (pvargDest->n1).decVal.Hi32 = local_58._4_4_;
  (pvargDest->n1).n2.n3.brecVal = (__tagBRECORD)local_50;
  if (7 < local_48.n2.vt) {
    VariantClear((VARIANTARG *)&local_48.n2);
  }
  return 0;
code_r0x404566bc:
  uVar13 = (uint)((__tagVARIANT *)pvarSrc)->vt;
  if (uVar13 == 0x400c) {
    iVar3 = -0x7ff8ffa9;
    local_50.int64 = _Var1.llVal;
LAB_404566d4:
    VariantClear((VARIANTARG *)&local_48.n2);
    return iVar3;
  }
  goto LAB_40456108;
}



/* 40457460 VariantChangeType */

/* Boundary evidence: original MIPS .pdata 40457460..40457483. Semantic name remains unreviewed. */

HRESULT VariantChangeType(VARIANTARG *pvargDest,VARIANTARG *pvarSrc,USHORT wFlags,VARTYPE vt)

{
  HRESULT HVar1;
  
                    /* 0x17460  224  VariantChangeType */
  HVar1 = VariantChangeTypeEx(pvargDest,pvarSrc,0x400,wFlags,vt);
  return HVar1;
}



/* 40457484 FUN_40457484 */

/* Boundary evidence: original MIPS .pdata 40457484..404574a3. Semantic name remains unreviewed. */

void FUN_40457484(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
  return;
}



/* 404574a4 FUN_404574a4 */

/* Boundary evidence: original MIPS .pdata 404574a4..404574c3. Semantic name remains unreviewed. */

void FUN_404574a4(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
  return;
}



/* 404574c4 FUN_404574c4 */

/* Boundary evidence: original MIPS .pdata 404574c4..404574e3. Semantic name remains unreviewed. */

void FUN_404574c4(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
  return;
}



/* 404574e4 FUN_404574e4 */

/* Boundary evidence: original MIPS .pdata 404574e4..40457503. Semantic name remains unreviewed. */

void FUN_404574e4(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
  return;
}



/* 40457504 FUN_40457504 */

/* Boundary evidence: original MIPS .pdata 40457504..4045756b. Semantic name remains unreviewed. */

void FUN_40457504(void)

{
  if (DAT_4046de98 == (HMODULE)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
    if (DAT_4046de98 == (HMODULE)0x0) {
      DAT_4046de98 = LoadLibraryW(L"oleaut32.dll");
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4046de80);
  }
  return;
}



/* 4045756c FUN_4045756c */

/* Boundary evidence: original MIPS .pdata 4045756c..404575bb. Semantic name remains unreviewed. */

void FUN_4045756c(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 404575bc FUN_404575bc */

/* Boundary evidence: original MIPS .pdata 404575bc..404576bf. Semantic name remains unreviewed. */

int FUN_404575bc(undefined4 *param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  SIZE_T local_18 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_18[0] = param_1[3];
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)param_1[2],
                             local_18);
    if (LVar1 == 0) {
      if (param_1[2] != 0) {
        return param_1[2];
      }
    }
    else if (LVar1 != 0xea) {
      return 0;
    }
    if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[2]);
      param_1[2] = 0;
      param_1[3] = 0;
    }
    lpData = LocalAlloc(0,local_18[0]);
    param_1[2] = lpData;
    if (lpData != (LPBYTE)0x0) {
      param_1[3] = local_18[0];
      LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,lpData,local_18);
      if (LVar1 == 0) {
        return param_1[2];
      }
    }
  }
  return 0;
}



/* 404576c0 FUN_404576c0 */

/* Boundary evidence: original MIPS .pdata 404576c0..40457727. Semantic name remains unreviewed. */

void FUN_404576c0(void)

{
  DAT_4046de94 = DAT_4046de94 + -1;
  if (DAT_4046de94 == 0) {
    TlsCall(1,DAT_4046d1b0);
    if (DAT_4046debc != 0) {
      FreeLibrary((HMODULE)DAT_4046debc);
      DAT_4046debc = 0;
    }
  }
  return;
}



/* 40457730 FUN_40457730 */

/* Boundary evidence: original MIPS .pdata 40457730..40457813. Semantic name remains unreviewed. */

int FUN_40457730(void)

{
  LPVOID pvVar1;
  BOOL BVar2;
  int iVar3;
  
  pvVar1 = TlsGetValue(DAT_4046d1b0);
  if (pvVar1 == (LPVOID)0x0) {
    FUN_40457504();
    pvVar1 = CoTaskMemAlloc(0xc4);
    if (pvVar1 == (LPVOID)0x0) {
      return -0x7ff8fff2;
    }
    memset(pvVar1,0,0xc4);
    BVar2 = TlsSetValue(DAT_4046d1b0,pvVar1);
    if (BVar2 == 0) {
      iVar3 = -0x7ff8fff2;
    }
    else {
      iVar3 = CoSetState(&PTR_PTR_4046d1b4);
      if (-1 < iVar3) goto LAB_404577f4;
      TlsSetValue(DAT_4046d1b0,(LPVOID)0x0);
    }
    CoTaskMemFree(pvVar1);
  }
  else {
LAB_404577f4:
    iVar3 = 0;
  }
  return iVar3;
}



/* 40457814 FUN_40457814 */

/* Boundary evidence: original MIPS .pdata 40457814..404578bb. Semantic name remains unreviewed. */

void FUN_40457814(uint *param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1[1] != 0) {
    uVar2 = 0;
    if (*param_1 != 0) {
      psVar1 = (short *)(param_1[1] + 0x14);
      do {
        if (*psVar1 != 0) {
          return;
        }
        uVar2 = uVar2 + 1;
        psVar1 = psVar1 + 0xc;
      } while (uVar2 < *param_1);
    }
    uVar2 = 0;
    if (*param_1 != 0) {
      iVar3 = 0;
      do {
        FUN_40458abc(*(LPVOID *)(iVar3 + param_1[1] + 0x10));
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 0x18;
      } while (uVar2 < *param_1);
    }
    FUN_40458abc((LPVOID)param_1[1]);
    param_1[1] = 0;
  }
  return;
}



/* 404578bc FUN_404578bc */

/* Boundary evidence: original MIPS .pdata 404578bc..40457a3f. Semantic name remains unreviewed. */

undefined4 FUN_404578bc(uint *param_1,undefined4 *param_2,uint *param_3)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  void *_Buf1;
  void *pvVar6;
  uint uVar7;
  
  uVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  uVar7 = *param_1;
  uVar5 = 0;
  if (uVar7 != 0) {
    pvVar6 = (void *)param_1[1];
    _Buf1 = pvVar6;
    do {
      iVar1 = memcmp(_Buf1,param_2,0x10);
      if (iVar1 == 0) {
        *(short *)((int)pvVar6 + uVar5 * 0x18 + 0x14) =
             *(short *)((int)pvVar6 + uVar5 * 0x18 + 0x14) + 1;
        goto LAB_40457a00;
      }
      uVar5 = uVar5 + 1;
      _Buf1 = (void *)((int)_Buf1 + 0x18);
    } while (uVar5 < *param_1);
  }
  pvVar2 = FUN_40458a64((LPVOID)param_1[1],(uVar7 + 1) * 0x18);
  if (pvVar2 != (LPVOID)0x0) {
    iVar1 = uVar5 * 0x18;
    param_1[1] = (uint)pvVar2;
    pvVar2 = FUN_40458a0c(4);
    *(LPVOID *)(param_1[1] + iVar1 + 0x10) = pvVar2;
    puVar3 = (undefined4 *)(param_1[1] + iVar1);
    if (puVar3[4] != 0) {
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      puVar3[2] = param_2[2];
      puVar3[3] = param_2[3];
      *(undefined2 *)(param_1[1] + iVar1 + 0x14) = 1;
      *param_1 = *param_1 + 1;
LAB_40457a00:
      *param_3 = uVar5;
      goto LAB_40457a04;
    }
  }
  uVar4 = 0x8007000e;
LAB_40457a04:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return uVar4;
}



/* 40457a40 FUN_40457a40 */

/* Boundary evidence: original MIPS .pdata 40457a40..40457b0b. Semantic name remains unreviewed. */

void FUN_40457a40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar1 = param_2 * 0x18;
  iVar2 = *(int *)(param_1 + 4) + iVar1;
  *(short *)(iVar2 + 0x14) = *(short *)(iVar2 + 0x14) + -1;
  iVar2 = *(int *)(param_1 + 4);
  if ((*(short *)(iVar2 + iVar1 + 0x14) == 0) && (**(int **)(iVar2 + iVar1 + 0x10) != 0)) {
    (**(code **)(*(int *)**(undefined4 **)(iVar2 + iVar1 + 0x10) + 8))();
    **(undefined4 **)(*(int *)(param_1 + 4) + iVar1 + 0x10) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return;
}



/* 40457b0c FUN_40457b0c */

/* Boundary evidence: original MIPS .pdata 40457b0c..40457ba3. Semantic name remains unreviewed. */

void FUN_40457b0c(uint *param_1,uint param_2,undefined4 *param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if ((param_2 == 0xffffffff) || (*param_1 <= param_2)) {
    *param_3 = 0;
  }
  else {
    *param_3 = *(undefined4 *)(param_2 * 0x18 + param_1[1] + 0x10);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



/* 40457ba4 FUN_40457ba4 */

/* Boundary evidence: original MIPS .pdata 40457ba4..40457d13. Semantic name remains unreviewed. */

void FUN_40457ba4(int param_1,LPVOID param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  LPVOID pvVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *local_18;
  
  if (DAT_4046de7c != 0) {
    iVar1 = __GetUserKData(0xc);
    iVar2 = GetOwnerProcess();
    if (iVar1 == iVar2) {
      uVar3 = CoTaskMemSize(param_2);
      if (uVar3 < 0x39) {
        if (uVar3 < 0x11) {
          puVar4 = (uint *)(param_1 + 4);
        }
        else {
          puVar4 = (uint *)(param_1 + 0x34);
        }
      }
      else if (uVar3 < 0xd1) {
        puVar4 = (uint *)(param_1 + 100);
      }
      else {
        puVar4 = (uint *)(param_1 + 0x94);
        if (0x20000 < uVar3) goto LAB_40457ca4;
      }
      uVar9 = 0;
      puVar6 = puVar4;
      uVar7 = uVar3;
      do {
        uVar8 = *puVar6;
        if (uVar8 == 0) {
          uVar9 = uVar9 + 1;
          *puVar6 = uVar3;
          puVar6[1] = (uint)param_2;
          if (5 < uVar9) {
            return;
          }
          puVar4 = puVar4 + uVar9 * 2;
          iVar1 = 6 - uVar9;
          do {
            if ((LPVOID)puVar4[1] == param_2) {
              *puVar4 = 0;
            }
            iVar1 = iVar1 + -1;
            puVar4 = puVar4 + 2;
          } while (iVar1 != 0);
          return;
        }
        if ((LPVOID)puVar6[1] == param_2) {
          return;
        }
        if (uVar8 < uVar7) {
          local_18 = puVar6;
          uVar7 = uVar8;
        }
        uVar9 = uVar9 + 1;
        puVar6 = puVar6 + 2;
      } while (uVar9 < 6);
      if (uVar7 < uVar3) {
        pvVar5 = (LPVOID)local_18[1];
        local_18[1] = (uint)param_2;
        *local_18 = uVar3;
        param_2 = pvVar5;
      }
    }
  }
LAB_40457ca4:
  CoTaskMemFree(param_2);
  return;
}



/* 40457d14 FUN_40457d14 */

/* Boundary evidence: original MIPS .pdata 40457d14..40457de3. Semantic name remains unreviewed. */

LPVOID FUN_40457d14(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  uint *puVar4;
  uint uVar5;
  
  if (DAT_4046de7c != 0) {
    iVar1 = __GetUserKData(0xc);
    iVar2 = GetOwnerProcess();
    if (iVar1 == iVar2) {
      if (param_2 < 0x39) {
        if (param_2 < 0x11) {
          puVar4 = (uint *)(param_1 + 4);
        }
        else {
          puVar4 = (uint *)(param_1 + 0x34);
        }
      }
      else {
        puVar4 = (uint *)(param_1 + 100);
        if (0xd0 < param_2) {
          puVar4 = (uint *)(param_1 + 0x94);
        }
      }
      uVar5 = 0;
      do {
        if (param_2 <= *puVar4) {
          *puVar4 = 0;
          return (LPVOID)puVar4[1];
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 2;
      } while (uVar5 < 6);
    }
  }
  pvVar3 = CoTaskMemAlloc(param_2);
  return pvVar3;
}



/* 40457de4 FUN_40457de4 */

/* Boundary evidence: original MIPS .pdata 40457de4..40457e83. Semantic name remains unreviewed. */

void FUN_40457de4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_4046de7c != 0) {
    iVar1 = __GetUserKData(0xc);
    iVar2 = GetOwnerProcess();
    if (iVar1 == iVar2) {
      puVar3 = (undefined4 *)(param_1 + 8);
      iVar1 = 4;
      do {
        iVar2 = 6;
        do {
          if (puVar3[-1] != 0) {
            CoTaskMemFree((LPVOID)*puVar3);
          }
          puVar3[-1] = 0;
          iVar2 = iVar2 + -1;
          puVar3 = puVar3 + 2;
        } while (iVar2 != 0);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}



/* 40457e84 FUN_40457e84 */

/* Boundary evidence: original MIPS .pdata 40457e84..40457f1b. Semantic name remains unreviewed. */

bool FUN_40457e84(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_4,param_1);
  return LVar1 == 0;
}



/* 40457f1c FUN_40457f1c */

/* Boundary evidence: original MIPS .pdata 40457f1c..4045802b. Semantic name remains unreviewed. */

void FUN_40457f1c(void)

{
  wchar_t wVar1;
  DWORD DVar2;
  wchar_t *_SubStr;
  wchar_t *pwVar3;
  size_t sVar4;
  HKEY local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_4046d1b8;
  DAT_4046de7c = 1;
  DVar2 = GetModuleFileNameW((HMODULE)0x42,aWStack_220,0x104);
  if (DVar2 != 0) {
    local_230 = (HKEY)0x0;
    local_22c = 0;
    local_228 = 0;
    local_224 = 0;
    FUN_40457e84(&local_230,(HKEY)0x80000002,L"Software\\Microsoft\\OLE",0x20019);
    if ((local_230 != (HKEY)0x0) &&
       (_SubStr = (wchar_t *)FUN_404575bc(&local_230,L"NoBstrCache"), _SubStr != (wchar_t *)0x0)) {
      wVar1 = *_SubStr;
      while (wVar1 != L'\0') {
        pwVar3 = wcsstr(aWStack_220,_SubStr);
        if (pwVar3 != (wchar_t *)0x0) {
          DAT_4046de7c = 0;
          break;
        }
        sVar4 = wcslen(_SubStr);
        _SubStr = _SubStr + sVar4 + 1;
        wVar1 = *_SubStr;
      }
    }
    FUN_4045756c(&local_230);
  }
  FUN_4046ace8(local_18);
  return;
}



/* 4045802c FUN_4045802c */

/* Boundary evidence: original MIPS .pdata 4045802c..404580a3. Semantic name remains unreviewed. */

undefined4 FUN_4045802c(void)

{
  if ((DAT_4046d1b0 == -1) && (DAT_4046d1b0 = TlsCall(0,0), DAT_4046d1b0 == -1)) {
    return 0x8007000e;
  }
  FUN_40457f1c();
  DAT_4046de94 = DAT_4046de94 + 1;
  return 0;
}



/* 404580a4 FUN_404580a4 */

/* Boundary evidence: original MIPS .pdata 404580a4..4045812b. Semantic name remains unreviewed. */

void FUN_404580a4(void)

{
  int *pv;
  
  pv = TlsGetValue(DAT_4046d1b0);
  if (pv != (int *)0x0) {
    FUN_40457814((uint *)&DAT_4046de9c);
    if ((int *)*pv != (int *)0x0) {
      (**(code **)(*(int *)*pv + 8))();
    }
    FUN_40457de4((int)pv);
    CoTaskMemFree(pv);
    TlsSetValue(DAT_4046d1b0,(LPVOID)0x0);
  }
  return;
}



/* 4045812c FUN_4045812c */

/* Boundary evidence: original MIPS .pdata 4045812c..4045814b. Semantic name remains unreviewed. */

undefined4 FUN_4045812c(void)

{
  FUN_404580a4();
  return 0;
}



/* 4045814c FUN_4045814c */

undefined4 FUN_4045814c(uint param_1,uint *param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = (int)param_1 < 0;
  if (bVar1) {
    param_1 = -param_1;
  }
  uVar2 = (param_1 & 0xffff) * 10000;
  uVar3 = (param_1 >> 0x10) * 10000 >> 0x10;
  uVar4 = (param_1 >> 0x10) * 0x27100000 + uVar2;
  param_2[1] = uVar3;
  *param_2 = uVar4;
  if (uVar4 < uVar2) {
    param_2[1] = uVar3 + 1;
  }
  if (bVar1) {
    uVar2 = param_2[1];
    param_2[1] = ~uVar2;
    *param_2 = -uVar4;
    if (-uVar4 == 0) {
      param_2[1] = ~uVar2 + 1;
    }
  }
  return 0;
}



/* 404581dc FUN_404581dc */

/* Boundary evidence: original MIPS .pdata 404581dc..4045847f. Semantic name remains unreviewed. */

undefined4 FUN_404581dc(undefined4 *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  
  uVar6 = param_1[1];
  uVar5 = *param_1;
  iVar2 = __ged(uVar5,uVar6,0xeb1c432d,0x430a36e2);
  if ((iVar2 == 0) && (iVar2 = __led(uVar5,uVar6,0xeb1c432d,0xc30a36e2), iVar2 == 0)) {
    iVar2 = __ltd(uVar5,uVar6,0,0);
    if (iVar2 != 0) {
      uVar6 = uVar6 ^ 0x80000000;
    }
    uVar3 = __dptofp(uVar5,uVar6);
    uVar7 = __fptodp(uVar3);
    uVar3 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar8 = __dpsub(uVar5,uVar6,(int)uVar7,uVar3);
    uVar7 = __dpmul((int)uVar7,uVar3,0,0x40c38800);
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    uVar8 = __dpmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),0,0x40c38800);
    uVar3 = (undefined4)((ulonglong)uVar8 >> 0x20);
    lVar9 = __d_to_ll((int)uVar8,uVar3);
    lVar10 = __d_to_ll((int)uVar7,uVar5);
    uVar1 = lVar9 + lVar10;
    *param_2 = uVar1;
    uVar11 = __litodp((int)(uVar1 >> 0x20));
    uVar11 = __dpmul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,0x41f00000);
    uVar7 = __dpsub((int)uVar7,uVar5,(int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
    uVar7 = __dpadd((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,uVar3);
    uVar8 = __ultodp((int)uVar1);
    uVar7 = __dpsub((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar8,
                    (int)((ulonglong)uVar8 >> 0x20));
    uVar5 = (undefined4)((ulonglong)uVar7 >> 0x20);
    iVar4 = __gtd((int)uVar7,uVar5,0,0x3fe00000);
    if ((iVar4 != 0) ||
       ((iVar4 = __eqd((int)uVar7,uVar5,0,0x3fe00000), iVar4 != 0 && ((uVar1 & 1) != 0)))) {
      uVar1 = *param_2;
      uVar6 = (uint)uVar1 + 1;
      *(uint *)param_2 = uVar6;
      *(uint *)((int)param_2 + 4) = *(int *)((int)param_2 + 4) + (uint)(uVar6 < (uint)uVar1);
    }
    if (iVar2 != 0) {
      uVar1 = *param_2;
      *(int *)param_2 = -(int)uVar1;
      *(uint *)((int)param_2 + 4) = -(uint)((int)uVar1 != 0) - *(int *)((int)param_2 + 4);
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0x8002000a;
  }
  return uVar5;
}



/* 40458480 FUN_40458480 */

/* Boundary evidence: original MIPS .pdata 40458480..40458527. Semantic name remains unreviewed. */

undefined4 FUN_40458480(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = __litodp(param_2);
  uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x41f00000);
  uVar3 = __ultodp(param_1);
  uVar2 = __dpadd((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,
                  (int)((ulonglong)uVar3 >> 0x20));
  uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x40c38800);
  uVar1 = __dptofp((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  *param_3 = uVar1;
  return 0;
}



/* 40458528 FUN_40458528 */

/* Boundary evidence: original MIPS .pdata 40458528..404585c7. Semantic name remains unreviewed. */

undefined4 FUN_40458528(undefined4 param_1,undefined4 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = __litodp(param_2);
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x41f00000);
  uVar2 = __ultodp(param_1);
  uVar1 = __dpadd((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),(int)uVar2,
                  (int)((ulonglong)uVar2 >> 0x20));
  uVar1 = __dpdiv((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x40c38800);
  *param_3 = uVar1;
  return 0;
}



/* 404585c8 FUN_404585c8 */

/* Boundary evidence: original MIPS .pdata 404585c8..404585e3. Semantic name remains unreviewed. */

void FUN_404585c8(uint param_1,uint *param_2)

{
  FUN_4045814c(param_1,param_2);
  return;
}



/* 404585e4 FUN_404585e4 */

/* Boundary evidence: original MIPS .pdata 404585e4..4045861f. Semantic name remains unreviewed. */

void FUN_404585e4(undefined4 *param_1,ulonglong *param_2)

{
  undefined8 local_10;
  
  local_10 = __fptodp(*param_1);
  FUN_404581dc((undefined4 *)&local_10,param_2);
  return;
}



/* 40458620 FUN_40458620 */

/* Boundary evidence: original MIPS .pdata 40458620..40458763. Semantic name remains unreviewed. */

undefined4 FUN_40458620(uint param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_c [3];
  
  iVar6 = 0;
  if ((int)param_2 < 0) {
    param_1 = -param_1;
    param_2 = ~param_2;
    if (param_1 == 0) {
      param_2 = param_2 + 1;
    }
    iVar6 = 1;
  }
  local_c[1] = param_2 & 0xffff;
  local_c[2] = param_2 >> 0x10;
  iVar4 = 3;
  puVar2 = local_c + 1;
  do {
    iVar4 = iVar4 + -1;
    *puVar2 = puVar2[1] % 10000 << 0x10 | *puVar2;
    puVar2[1] = puVar2[1] / 10000;
    puVar2 = puVar2 + -1;
  } while (0 < iVar4);
  uVar7 = (param_1 & 0xffff) / 10000;
  uVar3 = (ushort)((param_1 & 0xffff) % 10000);
  uVar5 = param_1 & 0xffff0000 | uVar7;
  local_c[1] = local_c[2] << 0x10 | local_c[1];
  if (((5000 < uVar3) || ((uVar3 == 5000 && ((uVar7 & 1) != 0)))) && (uVar5 = uVar5 + 1, uVar5 == 0)
     ) {
    local_c[1] = local_c[1] + 1;
  }
  if ((local_c[1] == 0) && (uVar5 <= iVar6 + 0x7fffffffU)) {
    if (iVar6 != 0) {
      uVar5 = -uVar5;
    }
    *param_3 = uVar5;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x8002000a;
  }
  return uVar1;
}



/* 40458764 FUN_40458764 */

/* Boundary evidence: original MIPS .pdata 40458764..40458963. Semantic name remains unreviewed. */

undefined4 FUN_40458764(uint param_1,uint param_2,uint param_3,uint *param_4)

{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  bool bVar11;
  uint local_50 [4];
  uint local_40 [4];
  uint local_30 [5];
  int local_1c;
  int local_18;
  int local_14;
  
  local_40[3] = -(uint)((int)param_3 < 0);
  bVar5 = 0;
  if ((int)param_2 < 0) {
    param_1 = -param_1;
    param_2 = ~param_2;
    if (param_1 == 0) {
      param_2 = param_2 + 1;
    }
    bVar5 = 1;
  }
  bVar3 = 0;
  if ((int)local_40[3] < 0) {
    param_3 = -param_3;
    local_40[3] = ~local_40[3];
    if (param_3 == 0) {
      local_40[3] = local_40[3] + 1;
    }
    bVar3 = 1;
  }
  bVar11 = (bool)(bVar3 ^ bVar5);
  local_50[0] = param_1 & 0xffff;
  local_50[1] = param_1 >> 0x10;
  local_50[2] = param_2 & 0xffff;
  local_50[3] = param_2 >> 0x10;
  local_40[0] = param_3 & 0xffff;
  local_40[1] = param_3 >> 0x10;
  local_40[2] = local_40[3] & 0xffff;
  local_40[3] = local_40[3] >> 0x10;
  memset(local_30,0,0x20);
  iVar2 = 0;
  iVar7 = 0;
  do {
    iVar8 = *(int *)((int)local_50 + iVar7);
    if (iVar8 != 0) {
      puVar9 = local_40;
      piVar6 = (int *)((int)local_30 + iVar7);
      iVar10 = 4;
      do {
        uVar4 = *puVar9;
        puVar9 = puVar9 + 1;
        iVar10 = iVar10 + -1;
        *piVar6 = iVar8 * uVar4 + *piVar6;
        piVar6 = piVar6 + 1;
      } while (iVar10 != 0);
      if (iVar2 < iVar2 + 4) {
        piVar6 = (int *)((int)local_30 + iVar7 + 4);
        iVar8 = (iVar2 + 4) - iVar2;
        do {
          uVar1 = *(ushort *)((int)piVar6 + -2);
          *(undefined2 *)((int)piVar6 + -2) = 0;
          *piVar6 = (uint)uVar1 + *piVar6;
          iVar8 = iVar8 + -1;
          piVar6 = piVar6 + 1;
        } while (iVar8 != 0);
      }
    }
    iVar7 = iVar7 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar7 < 0x10);
  if (((local_30[4] == 0 && local_1c == 0) && local_18 == 0) && local_14 == 0) {
    local_30[0] = local_30[1] << 0x10 | local_30[0];
    local_30[2] = local_30[3] << 0x10 | local_30[2];
    if (bVar11 != false) {
      local_30[0] = -local_30[0];
      local_30[2] = ~local_30[2];
      if ((local_30[0] == 0) && (local_30[2] = local_30[2] + 1, local_30[2] == 0)) {
        bVar11 = false;
      }
    }
    if (bVar11 != -1 < (int)local_30[2]) {
      *param_4 = local_30[0];
      param_4[1] = local_30[2];
      return 0;
    }
  }
  return 0x8002000a;
}



/* 40458964 FUN_40458964 */

/* Boundary evidence: original MIPS .pdata 40458964..404589c3. Semantic name remains unreviewed. */

int FUN_40458964(uint param_1,uint param_2,undefined2 *param_3)

{
  int iVar1;
  uint local_10 [2];
  
  iVar1 = FUN_40458620(param_1,param_2,local_10);
  if (iVar1 == 0) {
    if (((int)local_10[0] < -0x8000) || (0x7fff < (int)local_10[0])) {
      iVar1 = -0x7ffdfff6;
    }
    else {
      *param_3 = (short)local_10[0];
    }
  }
  return iVar1;
}



/* 404589c4 FUN_404589c4 */

/* Boundary evidence: original MIPS .pdata 404589c4..40458a0b. Semantic name remains unreviewed. */

LPVOID FUN_404589c4(SIZE_T param_1)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 auStack_10 [2];
  
  iVar1 = FUN_40447728(auStack_10);
  if (iVar1 < 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = CoTaskMemAlloc(param_1);
  }
  return pvVar2;
}



/* 40458a0c FUN_40458a0c */

/* Boundary evidence: original MIPS .pdata 40458a0c..40458a63. Semantic name remains unreviewed. */

LPVOID FUN_40458a0c(SIZE_T param_1)

{
  LPVOID _Dst;
  
  _Dst = FUN_404589c4(param_1);
  if (_Dst == (LPVOID)0x0) {
    _Dst = (LPVOID)0x0;
  }
  else {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



/* 40458a64 FUN_40458a64 */

/* Boundary evidence: original MIPS .pdata 40458a64..40458abb. Semantic name remains unreviewed. */

LPVOID FUN_40458a64(LPVOID param_1,SIZE_T param_2)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 auStack_18 [2];
  
  iVar1 = FUN_40447728(auStack_18);
  if (iVar1 < 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = CoTaskMemRealloc(param_1,param_2);
  }
  return pvVar2;
}



/* 40458abc FUN_40458abc */

/* Boundary evidence: original MIPS .pdata 40458abc..40458aff. Semantic name remains unreviewed. */

void FUN_40458abc(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    TlsGetValue(DAT_4046d1b0);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40458b00 FUN_40458b00 */

undefined4 FUN_40458b00(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)(*(int *)(param_1 + 0x1a0) + param_2);
  for (iVar2 = param_4; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  *(int *)(param_1 + 0x1a4) = param_2 + param_4;
  return 0;
}



/* 40458b38 FUN_40458b38 */

undefined4 FUN_40458b38(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1a4) = param_2;
  return 0;
}



/* 40458b44 FUN_40458b44 */

/* Boundary evidence: original MIPS .pdata 40458b44..40458b9f. Semantic name remains unreviewed. */

void FUN_40458b44(int param_1)

{
  if ((*(LPVOID *)(param_1 + 0x10) != (LPVOID)0x0) && ((*(uint *)(param_1 + 0xc) & 4) != 0)) {
    FUN_40458abc(*(LPVOID *)(param_1 + 0x10));
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffff3;
  return;
}



/* 40458ba0 FUN_40458ba0 */

/* Boundary evidence: original MIPS .pdata 40458ba0..40458c23. Semantic name remains unreviewed. */

void FUN_40458ba0(int param_1)

{
  if ((*(uint *)(param_1 + 0xc) & 4) != 0) {
    if (*(LPVOID *)(param_1 + 0x1c) != (LPVOID)0x0) {
      FUN_40458abc(*(LPVOID *)(param_1 + 0x1c));
    }
    if (*(LPVOID *)(param_1 + 0x20) != (LPVOID)0x0) {
      FUN_40458abc(*(LPVOID *)(param_1 + 0x20));
    }
    if (*(LPVOID *)(param_1 + 0x24) != (LPVOID)0x0) {
      FUN_40458abc(*(LPVOID *)(param_1 + 0x24));
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_40458b44(param_1);
  return;
}



/* 40458c24 FUN_40458c24 */

/* Boundary evidence: original MIPS .pdata 40458c24..40458dfb. Semantic name remains unreviewed. */

undefined4 FUN_40458c24(int param_1,ushort param_2)

{
  bool bVar1;
  LCID LVar2;
  undefined3 extraout_var;
  uint uVar3;
  ushort uVar4;
  
  *(undefined4 *)(param_1 + 0xc) = 0x10002;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xf;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = 0xf;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = 0xf;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x58) = 0xf;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x94) = 0xf;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa8) = 0xf;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xbc) = 0xf;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd0) = 0xf;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe4) = 0xf;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xf8) = 0xf;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10c) = 0xf;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x120) = 0xf;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x134) = 0xf;
  FUN_4045c34c(param_1);
  FUN_4045bce0(param_1);
  *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
  LVar2 = GetUserDefaultLCID();
  *(LCID *)(param_1 + 0x140) = LVar2;
  bVar1 = FUN_40459f3c(LVar2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    *(undefined4 *)(param_1 + 0x140) = 0x409;
  }
  *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x140);
  uVar3 = *(uint *)(param_1 + 0x140) & 0x3ff;
  if ((uVar3 == 4) || ((0x10 < uVar3 && (uVar3 < 0x13)))) {
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  *(undefined4 *)(param_1 + 0x158) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x16c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x170) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x174) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x178) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x184) = 0xffffffff;
  *(ushort *)(param_1 + 0x148) = (uVar4 | 8) << 2 | *(ushort *)(param_1 + 0x148) & 8 | param_2 & 3;
  *(undefined2 *)(param_1 + 0x14a) = 0;
  *(undefined2 *)(param_1 + 0x14c) = 0;
  *(undefined2 *)(param_1 + 0x14e) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x188) = 0;
  return 0;
}



/* 40458dfc FUN_40458dfc */

undefined4 FUN_40458dfc(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)(*(int *)(param_1 + 0x1a0) + *(int *)(param_1 + 0x1a4));
  for (iVar2 = param_3; iVar2 != 0; iVar2 = iVar2 + -1) {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  *(int *)(param_1 + 0x1a4) = param_3 + *(int *)(param_1 + 0x1a4);
  return 0;
}



/* 40458e3c FUN_40458e3c */

/* Boundary evidence: original MIPS .pdata 40458e3c..40458e97. Semantic name remains unreviewed. */

int FUN_40458e3c(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x6c) & 8) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x60),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x74),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40458e98 FUN_40458e98 */

/* Boundary evidence: original MIPS .pdata 40458e98..40458ef3. Semantic name remains unreviewed. */

int FUN_40458e98(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x6c) & 4) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x60),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x74),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40458ef4 FUN_40458ef4 */

/* Boundary evidence: original MIPS .pdata 40458ef4..40458f4f. Semantic name remains unreviewed. */

int FUN_40458ef4(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x30) & 4) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x24),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x38),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40458f50 FUN_40458f50 */

/* Boundary evidence: original MIPS .pdata 40458f50..40458fab. Semantic name remains unreviewed. */

int FUN_40458f50(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x94) & 4) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x88),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x9c),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40458fac FUN_40458fac */

/* Boundary evidence: original MIPS .pdata 40458fac..40459007. Semantic name remains unreviewed. */

int FUN_40458fac(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0xd0) & 4) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0xc4),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0xd8),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40459008 FUN_40459008 */

/* Boundary evidence: original MIPS .pdata 40459008..404591d7. Semantic name remains unreviewed. */

void FUN_40459008(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  *param_1 = &PTR_FUN_40441a20;
  uVar4 = 0;
  param_1[1] = &PTR_LAB_404419dc;
  param_1[2] = &PTR_LAB_404419c8;
  if (param_1[0x55] != 0) {
    iVar2 = 0;
    do {
      iVar1 = *(int *)(param_1[99] + iVar2) + param_1[8];
      if ((iVar1 != 0) && ((*(uint *)(iVar1 + 0x10) & 4) != 0)) {
        FUN_40458ba0(iVar1 + 4);
      }
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 4;
    } while (uVar4 < (uint)param_1[0x55]);
  }
  piVar3 = (int *)param_1[0x6f];
  if (piVar3 != (int *)0x0) {
    iVar2 = param_1[0x6e];
    while (iVar2 != 0) {
      iVar2 = iVar2 + -1;
      if ((int *)*piVar3 != (int *)0x0) {
        (**(code **)(*(int *)*piVar3 + 8))();
      }
      piVar3 = piVar3 + 1;
    }
    FUN_40458abc((LPVOID)param_1[0x6f]);
  }
  if ((LPVOID)param_1[0x71] != (LPVOID)0x0) {
    FUN_40458abc((LPVOID)param_1[0x71]);
  }
  if ((LPVOID)param_1[99] != (LPVOID)0x0) {
    FUN_40458abc((LPVOID)param_1[99]);
  }
  if ((HLOCAL)param_1[0x68] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x68]);
  }
  SysFreeString((BSTR)param_1[0x6a]);
  SysFreeString((BSTR)param_1[0x70]);
  if ((int *)param_1[0x74] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x74] + 8))();
  }
  FUN_40458b44((int)(param_1 + 0x4a));
  FUN_40458b44((int)(param_1 + 0x45));
  FUN_40458b44((int)(param_1 + 0x40));
  FUN_40458b44((int)(param_1 + 0x3b));
  FUN_40458b44((int)(param_1 + 0x36));
  FUN_40458b44((int)(param_1 + 0x31));
  FUN_40458b44((int)(param_1 + 0x2c));
  FUN_40458b44((int)(param_1 + 0x27));
  FUN_40458b44((int)(param_1 + 0x22));
  FUN_40458b44((int)(param_1 + 0x1d));
  FUN_40458b44((int)(param_1 + 0x18));
  FUN_40458b44((int)(param_1 + 0x13));
  FUN_40458b44((int)(param_1 + 0xe));
  FUN_40458b44((int)(param_1 + 9));
  FUN_40458b44((int)(param_1 + 4));
  return;
}



/* 40459250 FUN_40459250 */

undefined4 FUN_40459250(int param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)(*(int *)(param_1 + 0x1a0) + *(int *)(param_1 + 0x1a4));
  iVar3 = 4;
  do {
    uVar1 = *puVar2;
    puVar2 = puVar2 + 1;
    *param_2 = uVar1;
    iVar3 = iVar3 + -1;
    param_2 = param_2 + 1;
  } while (iVar3 != 0);
  *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 4;
  return 0;
}



/* 4045928c FUN_4045928c */

/* Boundary evidence: original MIPS .pdata 4045928c..4045944f. Semantic name remains unreviewed. */

int FUN_4045928c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(uint *)(param_1 + 0x1ac) & 1) != 0) {
    iVar1 = FUN_40458e98(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((*(uint *)(param_1 + 0x58) & 4) == 0) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x4c),param_1);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_40458ef4(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_40458f50(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((*(uint *)(param_1 + 0xbc) & 4) == 0) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0xb0),param_1);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_40458fac(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((*(uint *)(param_1 + 0xf8) & 4) == 0) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0xec),param_1);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((*(uint *)(param_1 + 0x10c) & 4) == 0) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x100),param_1);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar3 = 0;
    if (*(int *)(param_1 + 0x154) != 0) {
      iVar1 = 0;
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x18c) + iVar1) + *(int *)(param_1 + 0x20);
        if ((*(uint *)(iVar2 + 0x10) & 4) == 0) {
          iVar2 = FUN_4045a504((int *)(iVar2 + 4),param_1,1);
        }
        else {
          iVar2 = 0;
        }
        if (iVar2 < 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1;
        iVar1 = iVar1 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0x154));
    }
    *(uint *)(param_1 + 0x1ac) = *(uint *)(param_1 + 0x1ac) & 0xfffffffe;
  }
  return 0;
}



/* 40459450 FUN_40459450 */

undefined4 * FUN_40459450(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40441a20;
  param_1[1] = &PTR_LAB_404419dc;
  param_1[2] = &PTR_LAB_404419c8;
  param_1[8] = 0;
  param_1[4] = 0xffffffff;
  param_1[0xd] = 0;
  param_1[9] = 0xffffffff;
  param_1[0x12] = 0;
  param_1[0xe] = 0xffffffff;
  param_1[0x17] = 0;
  param_1[0x13] = 0xffffffff;
  param_1[0x1c] = 0;
  param_1[0x18] = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x26] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x2b] = 0;
  param_1[0x27] = 0xffffffff;
  param_1[0x30] = 0;
  param_1[0x2c] = 0xffffffff;
  param_1[0x35] = 0;
  param_1[0x31] = 0xffffffff;
  param_1[0x3a] = 0;
  param_1[0x36] = 0xffffffff;
  param_1[0x3f] = 0;
  param_1[0x3b] = 0xffffffff;
  param_1[0x44] = 0;
  param_1[0x40] = 0xffffffff;
  param_1[0x49] = 0;
  param_1[0x45] = 0xffffffff;
  param_1[0x4e] = 0;
  param_1[0x4a] = 0xffffffff;
  return param_1;
}



/* 404594fc FUN_404594fc */

/* Boundary evidence: original MIPS .pdata 404594fc..40459d3f. Semantic name remains unreviewed. */

int FUN_404594fc(int param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  LPVOID pvVar3;
  int *piVar4;
  undefined1 *puVar5;
  SIZE_T SVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  uint *puVar13;
  SIZE_T SVar14;
  uint uVar15;
  uint *puVar16;
  ushort *puVar17;
  int local_28;
  int iStack_24;
  
  iVar7 = *(int *)(param_1 + 0x1a4);
  iVar9 = *(int *)(param_1 + 0x1a0);
  piVar4 = &local_28;
  puVar5 = (undefined1 *)(iVar9 + iVar7);
  do {
    *(undefined1 *)piVar4 = *puVar5;
    piVar4 = (int *)((int)piVar4 + 1);
    puVar5 = puVar5 + 1;
  } while (piVar4 != &iStack_24);
  iVar7 = iVar7 + 4;
  *(int *)(param_1 + 0x1a4) = iVar7;
  if (local_28 == 0x5446534d) {
    iVar11 = 4;
    puVar5 = (undefined1 *)(iVar7 + iVar9);
    iVar7 = 4;
    piVar4 = (int *)(param_1 + 0xc);
    do {
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      *(undefined1 *)piVar4 = uVar1;
      iVar7 = iVar7 + -1;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (iVar7 != 0);
    iVar7 = *(int *)(param_1 + 0x1a4) + 4;
    *(int *)(param_1 + 0x1a4) = iVar7;
    if (*(int *)(param_1 + 0xc) == 0x10002) {
      puVar5 = (undefined1 *)(param_1 + 0x13c);
      puVar8 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar7 = 4;
      do {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        *puVar5 = uVar1;
        iVar7 = iVar7 + -1;
        puVar5 = puVar5 + 1;
      } while (iVar7 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x140);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x144);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar17 = (ushort *)(param_1 + 0x148);
      iVar9 = 2;
      *(int *)(param_1 + 0x1a4) = iVar7;
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar7 = 2;
      puVar12 = puVar17;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *(undefined1 *)puVar12 = uVar1;
        iVar7 = iVar7 + -1;
        puVar12 = (ushort *)((int)puVar12 + 1);
      } while (iVar7 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 2;
      puVar8 = (undefined1 *)(param_1 + 0x14a);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar10 = 2;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar10 = iVar10 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar10 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 2;
      puVar8 = (undefined1 *)(param_1 + 0x14c);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar10 = 2;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar10 = iVar10 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar10 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 2;
      puVar5 = (undefined1 *)(param_1 + 0x14e);
      puVar8 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        *puVar5 = uVar1;
        iVar9 = iVar9 + -1;
        puVar5 = puVar5 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 2;
      puVar8 = (undefined1 *)(param_1 + 0x150);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar16 = (uint *)(param_1 + 0x154);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      *(int *)(param_1 + 0x1a4) = iVar7;
      iVar7 = 4;
      puVar13 = puVar16;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *(undefined1 *)puVar13 = uVar1;
        iVar7 = iVar7 + -1;
        puVar13 = (uint *)((int)puVar13 + 1);
      } while (iVar7 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x158);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x15c);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x160);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x164);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x168);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x16c);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x170);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x178);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x17c);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x180);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x184);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      puVar8 = (undefined1 *)(param_1 + 0x188);
      puVar5 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
      iVar9 = 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      uVar2 = *puVar17;
      iVar7 = *(int *)(param_1 + 0x1a4) + 4;
      *(int *)(param_1 + 0x1a4) = iVar7;
      if (((uVar2 & 0xfe00) != 0) || (0x5f < (uVar2 & 0xe0))) {
        *puVar17 = uVar2 & 0xf;
      }
      if ((*puVar17 & 0x100) == 0) {
        *(undefined4 *)(param_1 + 0x174) = 0xffffffff;
      }
      else {
        puVar5 = (undefined1 *)(param_1 + 0x174);
        puVar8 = (undefined1 *)(iVar7 + *(int *)(param_1 + 0x1a0));
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + 1;
          *puVar5 = uVar1;
          iVar11 = iVar11 + -1;
          puVar5 = puVar5 + 1;
        } while (iVar11 != 0);
        *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 4;
      }
      SVar14 = *puVar16 * 4;
      *(uint *)(param_1 + 0x1b0) = *puVar16;
      puVar8 = FUN_404589c4(SVar14);
      puVar5 = (undefined1 *)(*(int *)(param_1 + 0x1a0) + *(int *)(param_1 + 0x1a4));
      *(undefined1 **)(param_1 + 0x18c) = puVar8;
      for (SVar6 = SVar14; SVar6 != 0; SVar6 = SVar6 - 1) {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
      }
      *(SIZE_T *)(param_1 + 0x1a4) = SVar14 + *(int *)(param_1 + 0x1a4);
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x10),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x24),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x38),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x4c),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x60),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x74),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x88),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x9c),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0xb0),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0xc4),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0xd8),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0xec),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x100),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x114),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      iVar7 = FUN_4045a10c((int *)(param_1 + 0x128),param_1);
      if (iVar7 < 0) {
        return iVar7;
      }
      if ((*(uint *)(param_1 + 0x1c) & 4) == 0) {
        iVar7 = FUN_4045a028((int *)(param_1 + 0x10),param_1);
      }
      else {
        iVar7 = 0;
      }
      if (iVar7 < 0) {
        return iVar7;
      }
      if (*puVar16 == 0) {
        *(undefined4 *)(param_1 + 0x1cc) = 0;
        *(undefined4 *)(param_1 + 0x1c8) = 0;
      }
      else {
        pvVar3 = FUN_404589c4(*puVar16 * 0x2c);
        *(LPVOID *)(param_1 + 0x1c4) = pvVar3;
        if (pvVar3 == (LPVOID)0x0) {
          return -0x7ff8fff2;
        }
        uVar15 = 0;
        *(LPVOID *)(param_1 + 0x1cc) = pvVar3;
        *(LPVOID *)(param_1 + 0x1c8) = (LPVOID)(*puVar16 * 0x2c + (int)pvVar3);
        if (*puVar16 != 0) {
          iVar9 = 0;
          iVar7 = 0;
          do {
            iVar11 = iVar7 + *(int *)(param_1 + 0x1c4);
            *(int *)(iVar11 + 0xc) = iVar11 + 0x2c;
            if ((*puVar17 & 0xe0) == 0) {
              iVar11 = *(int *)(iVar9 + *(int *)(param_1 + 0x18c)) + *(int *)(param_1 + 0x20);
              *(undefined4 *)(iVar11 + 0x5c) = 0;
              FUN_4045a4d8(iVar11 + 4);
            }
            uVar15 = uVar15 + 1;
            iVar7 = iVar7 + 0x2c;
            iVar9 = iVar9 + 4;
          } while (uVar15 < *puVar16);
        }
        *(undefined4 *)(*puVar16 * 0x2c + *(int *)(param_1 + 0x1c4) + -0x20) = 0;
      }
      iVar7 = FUN_40458e3c(param_1);
      return iVar7;
    }
  }
  return -0x7ffd7fe7;
}



/* 40459d40 FUN_40459d40 */

/* Boundary evidence: original MIPS .pdata 40459d40..40459f2f. Semantic name remains unreviewed. */

int FUN_40459d40(int param_1,int *param_2,OLECHAR *param_3,short param_4,ushort param_5,
                undefined4 *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  BSTR pOVar3;
  int iVar4;
  
  puVar1 = FUN_404589c4(0x1d4);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40459450(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    iVar4 = -0x7ff8fff2;
  }
  else {
    piVar2[0x66] = 1;
    if (param_2 == (int *)0x0) {
      piVar2[0x67] = 0;
      piVar2[0x68] = 0;
    }
    else {
      piVar2[0x67] = *param_2;
      piVar2[0x68] = param_2[1];
    }
    piVar2[0x69] = 0;
    piVar2[0x6a] = 0;
    piVar2[100] = -1;
    piVar2[0x65] = -1;
    piVar2[99] = 0;
    piVar2[0x71] = 0;
    piVar2[0x6d] = 0;
    piVar2[0x55] = 0;
    piVar2[0x6f] = 0;
    piVar2[0x6e] = 0;
    piVar2[0x70] = 0;
    piVar2[0x74] = 0;
    if (param_1 == 0) {
      piVar2[0x6b] = piVar2[0x6b] | 1;
      iVar4 = FUN_404594fc((int)piVar2);
    }
    else {
      piVar2[0x6b] = piVar2[0x6b] & 0xfffffffe;
      iVar4 = FUN_40458c24((int)piVar2,param_5);
    }
    if (-1 < iVar4) {
      pOVar3 = SysAllocString(param_3);
      piVar2[0x6a] = (int)pOVar3;
      if (pOVar3 != (BSTR)0x0) {
        *(ushort *)(piVar2 + 0x52) =
             (param_4 << 3 ^ *(ushort *)(piVar2 + 0x52)) & 8 ^ *(ushort *)(piVar2 + 0x52);
        *param_6 = piVar2;
        return 0;
      }
      iVar4 = -0x7ff8fff2;
    }
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return iVar4;
}



/* 40459f30 FUN_40459f30 */

/* Boundary evidence: original MIPS .pdata 40459f30..40459f3b. Semantic name remains unreviewed. */

undefined4 FUN_40459f30(void)

{
  return 1;
}



/* 40459f3c FUN_40459f3c */

/* Boundary evidence: original MIPS .pdata 40459f3c..40459fdb. Semantic name remains unreviewed. */

bool FUN_40459f3c(LCID param_1)

{
  int iVar1;
  bool bVar2;
  WCHAR aWStack_18 [6];
  uint local_c;
  
  local_c = DAT_4046d1b8;
  memcpy(aWStack_18,L"Test",10);
  if (param_1 == 0) {
    FUN_4046ace8(local_c);
    bVar2 = false;
  }
  else {
    iVar1 = CompareStringW(param_1,3,aWStack_18,-1,aWStack_18,-1);
    bVar2 = iVar1 == 2;
    FUN_4046ace8(local_c);
  }
  return bVar2;
}



/* 40459fdc FUN_40459fdc */

void FUN_40459fdc(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 0x1a0) == 0) {
    param_1[3] = param_1[3] & 0xfffffff3;
    param_1[4] = 0;
  }
  else {
    param_1[3] = param_1[3] & 0xfffffffbU | 8;
    param_1[4] = *param_1 + *(int *)(param_2 + 0x1a0);
  }
  return;
}



/* 4045a028 FUN_4045a028 */

/* Boundary evidence: original MIPS .pdata 4045a028..4045a0ab. Semantic name remains unreviewed. */

int FUN_4045a028(int *param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    param_1[4] = 0;
  }
  else {
    puVar1 = FUN_404589c4(param_1[1]);
    param_1[4] = (int)puVar1;
    if (puVar1 == (undefined1 *)0x0) {
      return -0x7ff8fff2;
    }
    iVar2 = FUN_40458b00(param_2,*param_1,puVar1,param_1[1]);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  param_1[3] = param_1[3] | 0xc;
  return 0;
}



/* 4045a0ac FUN_4045a0ac */

/* Boundary evidence: original MIPS .pdata 4045a0ac..4045a10b. Semantic name remains unreviewed. */

undefined4 FUN_4045a0ac(int param_1,SIZE_T param_2)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  
  pvVar1 = FUN_40458a64(*(LPVOID *)(param_1 + 0x10),param_2);
  if ((pvVar1 == (LPVOID)0x0) && (param_2 != 0)) {
    uVar2 = 0x8007000e;
  }
  else {
    *(LPVOID *)(param_1 + 0x10) = pvVar1;
    uVar2 = 0;
    *(SIZE_T *)(param_1 + 4) = param_2;
  }
  return uVar2;
}



/* 4045a10c FUN_4045a10c */

/* Boundary evidence: original MIPS .pdata 4045a10c..4045a197. Semantic name remains unreviewed. */

int FUN_4045a10c(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_40459250(param_2,(undefined1 *)param_1);
  if ((((-1 < iVar1) && (iVar1 = FUN_40459250(param_2,(undefined1 *)(param_1 + 1)), -1 < iVar1)) &&
      (iVar1 = FUN_40459250(param_2,(undefined1 *)(param_1 + 2)), -1 < iVar1)) &&
     (iVar1 = FUN_40459250(param_2,(undefined1 *)(param_1 + 3)), -1 < iVar1)) {
    FUN_40459fdc(param_1,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045a198 FUN_4045a198 */

void FUN_4045a198(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)(param_1 + 0xc) & 1) == 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + param_2);
    *piVar1 = param_3;
    piVar1[1] = *(int *)(param_1 + 8);
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + param_2);
    uVar6 = 0xffffffff;
    *piVar1 = param_3;
    uVar2 = *(uint *)(param_1 + 8);
    uVar3 = uVar6;
    if (*(uint *)(param_1 + 8) != 0xffffffff) {
      do {
        uVar6 = uVar2;
        if (param_2 < uVar6) {
          if (uVar3 == 0xffffffff) {
            *(uint *)(param_1 + 8) = param_2;
          }
          else {
            piVar4 = (int *)(*(int *)(param_1 + 0x10) + uVar3);
            if (*piVar4 + uVar3 == param_2) {
              *piVar4 = *piVar4 + param_3;
              piVar1 = piVar4;
              goto LAB_4045a270;
            }
            piVar4[1] = param_2;
          }
          piVar1[1] = uVar6;
LAB_4045a270:
          piVar4 = (int *)(*(int *)(param_1 + 0x10) + uVar6);
          if ((int *)(*piVar1 + (int)piVar1) == piVar4) {
            *piVar1 = *piVar1 + *piVar4;
            uVar6 = piVar4[1];
          }
          piVar1[1] = uVar6;
          return;
        }
        uVar2 = *(uint *)(*(int *)(param_1 + 0x10) + uVar6 + 4);
        uVar3 = uVar6;
      } while (uVar2 != 0xffffffff);
      piVar4 = (int *)(*(int *)(param_1 + 0x10) + uVar6);
      iVar5 = *piVar4;
      if (iVar5 + uVar6 == param_2) {
        *piVar4 = iVar5 + param_3;
        return;
      }
    }
    *piVar1 = param_3;
    piVar1[1] = -1;
    if (uVar6 != 0xffffffff) {
      *(uint *)(*(int *)(param_1 + 0x10) + uVar6 + 4) = param_2;
      return;
    }
  }
  *(uint *)(param_1 + 8) = param_2;
  return;
}



/* 4045a2bc FUN_4045a2bc */

void FUN_4045a2bc(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  if ((param_2 < 8) && ((*(uint *)(param_1 + 0xc) & 2) != 0)) {
    uVar5 = 8;
  }
  else {
    uVar5 = param_2 + 3 & 0xfffffffc;
  }
  puVar4 = (uint *)(param_1 + 8);
  if (*puVar4 != 0xffffffff) {
    uVar1 = *puVar4;
    uVar6 = 0xffffffff;
    do {
      uVar2 = uVar1;
      puVar7 = (uint *)(*(int *)(param_1 + 0x10) + uVar2);
      uVar1 = uVar2;
      if (uVar5 + 8 <= *puVar7) break;
      uVar1 = puVar7[1];
      uVar6 = uVar2;
    } while (uVar1 != 0xffffffff);
    if (uVar1 != 0xffffffff) {
      uVar2 = *puVar7;
      piVar3 = (int *)(*(int *)(param_1 + 0x10) + uVar1 + uVar5);
      piVar3[1] = puVar7[1];
      *piVar3 = uVar2 - uVar5;
      if (uVar6 != 0xffffffff) {
        puVar4 = (uint *)(*(int *)(param_1 + 0x10) + uVar6 + 4);
      }
      *puVar4 = uVar1 + uVar5;
    }
  }
  return;
}



/* 4045a374 FUN_4045a374 */

/* Boundary evidence: original MIPS .pdata 4045a374..4045a487. Semantic name remains unreviewed. */

int FUN_4045a374(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  while( true ) {
    if ((param_3 < 8) && ((*(uint *)(param_1 + 0xc) & 2) != 0)) {
      uVar3 = 8;
    }
    else {
      uVar3 = param_3 + 3 & 0xfffffffc;
    }
    iVar1 = FUN_4045a2bc(param_1,uVar3);
    if (iVar1 != -1) break;
    uVar4 = *(uint *)(param_1 + 4);
    uVar2 = uVar3 + 8;
    if (uVar3 + 8 <= uVar4) {
      uVar2 = uVar4;
    }
    iVar1 = FUN_4045a0ac(param_1,uVar2 + uVar4);
    if ((iVar1 != 0) && (iVar1 < 0)) {
      return iVar1;
    }
    FUN_4045a198(param_1,uVar4,*(int *)(param_1 + 4) - uVar4);
  }
  memset((void *)(*(int *)(param_1 + 0x10) + iVar1 + param_3),0x57,uVar3 - param_3);
  *param_2 = iVar1;
  return 0;
}



/* 4045a488 FUN_4045a488 */

/* Boundary evidence: original MIPS .pdata 4045a488..4045a4d7. Semantic name remains unreviewed. */

void FUN_4045a488(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_3 < 8) && ((*(uint *)(param_1 + 0xc) & 2) != 0)) {
    uVar1 = 8;
  }
  else {
    uVar1 = param_3 + 3 & 0xfffffffc;
  }
  FUN_4045a198(param_1,param_2,uVar1);
  return;
}



/* 4045a4d8 FUN_4045a4d8 */

void FUN_4045a4d8(int param_1)

{
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffff3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



/* 4045a504 FUN_4045a504 */

/* Boundary evidence: original MIPS .pdata 4045a504..4045a6d7. Semantic name remains unreviewed. */

int FUN_4045a504(int *param_1,int param_2,int param_3)

{
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  SIZE_T SVar5;
  int iVar6;
  uint local_20;
  int local_1c;
  
  FUN_40459fdc(param_1,param_2);
  iVar6 = (uint)*(ushort *)((int)param_1 + 0x16) + (uint)*(ushort *)(param_1 + 5);
  if (((param_3 == 0) && (iVar6 != 0)) && ((param_1[3] & 8U) != 0)) {
    iVar2 = *(int *)param_1[4];
    param_1[2] = -1;
    piVar4 = (int *)param_1[4] + 1;
    iVar3 = (int)piVar4 + iVar2;
    param_1[1] = iVar2;
    iVar2 = iVar3 + iVar6 * 4;
    param_1[8] = iVar2;
    param_1[4] = (int)piVar4;
    param_1[7] = iVar3;
    param_1[9] = iVar2 + iVar6 * 4;
  }
  else {
    param_1[1] = 0;
    param_1[2] = -1;
    param_1[3] = 0xf;
    param_1[4] = 0;
    if (iVar6 != 0) {
      iVar2 = FUN_40458b38(param_2,*param_1);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_40459250(param_2,(undefined1 *)&local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
      FUN_4045a374((int)param_1,&local_1c,local_20);
      iVar2 = FUN_40458dfc(param_2,(undefined1 *)(param_1[4] + local_1c),local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
      SVar5 = iVar6 * 4;
      pvVar1 = FUN_404589c4(SVar5);
      param_1[7] = (int)pvVar1;
      pvVar1 = FUN_404589c4(SVar5);
      param_1[8] = (int)pvVar1;
      pvVar1 = FUN_404589c4(SVar5);
      param_1[9] = (int)pvVar1;
      if ((((undefined1 *)param_1[7] == (undefined1 *)0x0) || (param_1[8] == 0)) ||
         (pvVar1 == (LPVOID)0x0)) {
        return -0x7ff8fff2;
      }
      param_1[6] = iVar6;
      iVar6 = FUN_40458dfc(param_2,(undefined1 *)param_1[7],SVar5);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_40458dfc(param_2,(undefined1 *)param_1[8],SVar5);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_40458dfc(param_2,(undefined1 *)param_1[9],SVar5);
      if (iVar6 < 0) {
        return iVar6;
      }
    }
  }
  return 0;
}



/* 4045a6d8 FUN_4045a6d8 */

/* Boundary evidence: original MIPS .pdata 4045a6d8..4045a8ab. Semantic name remains unreviewed. */

void FUN_4045a6d8(int param_1,int param_2,uint param_3,int param_4)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  size_t _Size;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0x14);
  uVar10 = *(ushort *)(param_1 + 0x16) + uVar3;
  sVar2 = (short)param_4;
  uVar5 = param_3;
  if ((param_3 < uVar3) && (uVar5 = 0, uVar3 != 0)) {
    iVar9 = 0;
    do {
      iVar8 = *(int *)(iVar9 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10);
      if (param_3 <= *(ushort *)(iVar8 + 2)) {
        *(ushort *)(iVar8 + 2) = *(ushort *)(iVar8 + 2) + sVar2;
      }
      if (param_3 <= *(ushort *)(iVar8 + 0x12)) {
        *(ushort *)(iVar8 + 0x12) = *(ushort *)(iVar8 + 0x12) + sVar2;
      }
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 4;
    } while (uVar5 < *(ushort *)(param_1 + 0x14));
  }
  if (uVar5 < uVar10) {
    iVar8 = uVar5 << 2;
    iVar9 = uVar10 - uVar5;
    do {
      iVar6 = *(int *)(iVar8 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10);
      uVar1 = *(ushort *)(iVar6 + 2);
      if (param_3 <= uVar1) {
        *(ushort *)(iVar6 + 2) = uVar1 + sVar2;
      }
      iVar9 = iVar9 + -1;
      iVar8 = iVar8 + 4;
    } while (iVar9 != 0);
  }
  if (param_4 == -1) {
    _Size = param_2 << 2;
    iVar9 = param_3 * 4;
    iVar8 = (param_3 + 1) * 4;
    memcpy((void *)(iVar9 + *(int *)(param_1 + 0x1c)),(void *)(*(int *)(param_1 + 0x1c) + iVar8),
           _Size);
    memcpy((void *)(iVar9 + *(int *)(param_1 + 0x20)),(void *)(*(int *)(param_1 + 0x20) + iVar8),
           _Size);
    memcpy((void *)(iVar9 + *(int *)(param_1 + 0x24)),(void *)(*(int *)(param_1 + 0x24) + iVar8),
           _Size);
  }
  else if (param_2 != 0) {
    iVar9 = (param_2 + param_3) * 4;
    iVar8 = (param_2 + param_3 + -1) * 4;
    do {
      *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x1c)) =
           *(undefined4 *)(iVar8 + *(int *)(param_1 + 0x1c));
      *(undefined4 *)(iVar9 + *(int *)(param_1 + 0x20)) =
           *(undefined4 *)(iVar8 + *(int *)(param_1 + 0x20));
      puVar4 = (undefined4 *)(iVar8 + *(int *)(param_1 + 0x24));
      puVar7 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x24));
      param_2 = param_2 + -1;
      iVar8 = iVar8 + -4;
      iVar9 = iVar9 + -4;
      *puVar7 = *puVar4;
    } while (param_2 != 0);
  }
  return;
}



/* 4045a8ac FUN_4045a8ac */

undefined4 FUN_4045a8ac(int param_1,uint param_2,uint param_3,int param_4,uint *param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 == 0xffffffff) || (*(ushort *)(param_1 + 0x14) <= param_2)) {
LAB_4045a9d4:
    uVar2 = 0x8002802b;
  }
  else {
    if ((param_3 == 0) || (param_3 == 0xf)) {
      *param_5 = param_2;
    }
    else {
      iVar5 = *(int *)(param_1 + 0x24);
      iVar6 = *(int *)(param_1 + 0x10);
      iVar4 = *(int *)(param_2 * 4 + iVar5) + iVar6;
      uVar1 = *(ushort *)(iVar4 + 0x10);
      while ((uVar1 >> 3 & param_3 & 0xf) == 0) {
        iVar4 = *(int *)((uint)*(ushort *)(iVar4 + 0x12) * 4 + iVar5) + iVar6;
        if (*(ushort *)(iVar4 + 2) == param_2) goto LAB_4045a9d4;
        uVar1 = *(ushort *)(iVar4 + 0x10);
      }
      if (param_4 == 0) {
        iVar3 = *(int *)((uint)*(ushort *)(iVar4 + 0x12) * 4 + iVar5) + iVar6;
        uVar1 = *(ushort *)(iVar3 + 2);
        while (uVar1 != param_2) {
          if ((*(ushort *)(iVar3 + 0x10) >> 3 & param_3 & 0xf) != 0) {
            return 0x8002802c;
          }
          iVar3 = *(int *)((uint)*(ushort *)(iVar3 + 0x12) * 4 + iVar5) + iVar6;
          uVar1 = *(ushort *)(iVar3 + 2);
        }
      }
      *param_5 = (uint)*(ushort *)(iVar4 + 2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 4045a9e4 FUN_4045a9e4 */

/* Boundary evidence: original MIPS .pdata 4045a9e4..4045aa7b. Semantic name remains unreviewed. */

undefined4 FUN_4045a9e4(int param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  if (((param_2 == -1) || ((param_3 & 0xf) == 0)) || ((param_3 & 0xfffffff0) != 0)) {
    uVar1 = 0x80070057;
  }
  else {
    uVar4 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
    uVar2 = 0;
    if (uVar4 != 0) {
      piVar3 = *(int **)(param_1 + 0x1c);
      do {
        if (*piVar3 == param_2) goto LAB_4045aa54;
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar2 < uVar4);
    }
    uVar2 = 0xffffffff;
LAB_4045aa54:
    uVar1 = FUN_4045a8ac(param_1,uVar2,param_3,1,param_4);
  }
  return uVar1;
}



/* 4045aa7c FUN_4045aa7c */

undefined4 FUN_4045aa7c(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  
  if (param_2 == -1) {
    uVar1 = 0x80070057;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_1 + 0x14);
    uVar5 = *(ushort *)(param_1 + 0x16) + uVar2;
    uVar3 = 0;
    if (uVar5 != 0) {
      piVar4 = *(int **)(param_1 + 0x1c);
      do {
        if (*piVar4 == param_2) goto LAB_4045aad0;
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < uVar5);
    }
    uVar3 = 0xffffffff;
LAB_4045aad0:
    if ((uVar3 == 0xffffffff) || (uVar3 < uVar2)) {
      uVar1 = 0x8002802b;
    }
    else {
      *param_3 = uVar3 - uVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4045ab04 FUN_4045ab04 */

undefined4 FUN_4045ab04(int param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  uVar3 = *param_2;
  uVar4 = 0;
  uVar7 = 0;
  if (*(short *)(param_1 + 0x14) != 0) {
    iVar6 = 0;
    uVar5 = uVar3;
    do {
      iVar8 = *(int *)(*(int *)(param_1 + 0x24) + iVar6) + *(int *)(param_1 + 0x10);
      uVar1 = *(ushort *)(iVar8 + 0xc);
      if ((uVar1 & 1) == 0) {
        if (uVar3 != 0) {
          uVar4 = uVar4 | 2;
        }
        *(short *)(iVar8 + 0xc) = (short)uVar3;
        uVar3 = uVar3 + 4;
      }
      else {
        uVar2 = uVar1 & 0xfffffffc;
        uVar4 = uVar4 | 1;
        if (uVar2 <= uVar5) {
          if (uVar2 != uVar5) {
            return 0x800288cf;
          }
          uVar5 = uVar5 + 4;
        }
        if (uVar3 <= uVar2) {
          uVar3 = uVar2 + 4;
        }
      }
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar7 < *(ushort *)(param_1 + 0x14));
    if (uVar4 == 3) {
      return 0x800288cf;
    }
  }
  *param_2 = uVar3;
  return 0;
}



/* 4045abd0 FUN_4045abd0 */

/* Boundary evidence: original MIPS .pdata 4045abd0..4045ad3f. Semantic name remains unreviewed. */

int FUN_4045abd0(int param_1,ushort *param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_38;
  uint local_34;
  ushort *local_30;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x14);
  uVar8 = *(ushort *)(param_1 + 0x16) + uVar2;
  uVar4 = 0;
  uVar5 = 1;
  if (uVar2 < uVar8) {
    iVar6 = uVar2 << 2;
    local_30 = param_2;
    do {
      iVar7 = *(int *)(iVar6 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10);
      iVar1 = FUN_4045ffc4(*(int *)(local_30 + 0x2e),*(uint *)(iVar7 + 4),&local_34,&local_38);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar3 = *local_30 >> 6 & 0x1f;
      if (uVar3 <= local_38) {
        local_38 = uVar3;
      }
      if ((*local_30 & 0xf) == 7) {
        *(undefined4 *)(iVar7 + 0x10) = 0;
        if (uVar4 < local_34) {
          uVar4 = local_34;
        }
      }
      else {
        uVar4 = (local_38 + uVar4) - 1 & ~(local_38 - 1);
        *(uint *)(iVar7 + 0x10) = uVar4;
        uVar4 = uVar4 + local_34;
      }
      if (uVar5 < local_38) {
        uVar5 = local_38;
      }
      uVar2 = uVar2 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar2 < uVar8);
  }
  *param_3 = uVar4;
  *param_4 = uVar5;
  return 0;
}



/* 4045ad40 FUN_4045ad40 */

undefined4 FUN_4045ad40(int param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 < *(ushort *)(param_1 + 0x14)) {
    iVar3 = param_2 * 4;
    iVar4 = *(int *)(*(int *)(param_1 + 0x24) + iVar3) + *(int *)(param_1 + 0x10);
    piVar5 = (int *)((char)(&DAT_40441af0)[*(ushort *)(iVar4 + 0x10) >> 3 & 0xf] * 4 + param_4);
    iVar2 = *piVar5;
    if (iVar2 != iVar4) {
      if (iVar2 != 0) goto LAB_4045ad50;
      *piVar5 = iVar4;
      iVar2 = param_3 * 4;
      if (*(int *)(*(int *)(param_1 + 0x1c) + iVar3) != *(int *)(iVar2 + *(int *)(param_1 + 0x1c)))
      {
        iVar4 = *(int *)(param_1 + 0x1c);
        if (*(int *)(iVar4 + iVar2) == -1) {
          *(undefined4 *)(iVar4 + iVar2) = *(undefined4 *)(iVar4 + iVar3);
        }
        else {
          if (*(int *)(iVar4 + iVar3) != -1) {
            return 0x80029c83;
          }
          *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar3) =
               *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar2);
        }
      }
    }
    uVar1 = 0;
  }
  else {
LAB_4045ad50:
    uVar1 = 0x800288c6;
  }
  return uVar1;
}



/* 4045ae40 FUN_4045ae40 */

/* Boundary evidence: original MIPS .pdata 4045ae40..4045b02f. Semantic name remains unreviewed. */

undefined4 FUN_4045ae40(undefined4 param_1,int param_2,ushort *param_3,ushort *param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  
  puVar4 = param_3;
  if ((param_3[8] & 0x78) != 0x10) {
    puVar4 = param_4;
    param_4 = param_3;
  }
  uVar5 = (uint)param_4[10];
  uVar8 = (uint)puVar4[10];
  if ((uVar5 - (param_4[8] >> 0xe) & 0xffff) != 0) {
    uVar2 = puVar4[8] >> 3 & 0xf;
    if (uVar2 == 2) {
      uVar6 = uVar8;
      if (uVar5 < uVar8) {
        return 0x80029c83;
      }
    }
    else {
      if ((uVar8 - (puVar4[8] >> 0xe) & 0xffff) == 0) {
        return 0x80029c83;
      }
      if (uVar8 != uVar5) {
        return 0x80029c83;
      }
      uVar6 = uVar8 - 1;
    }
    uVar1 = 0;
    puVar7 = (uint *)((uint)*puVar4 + uVar8 * -0xc + (int)puVar4);
    if (uVar6 != 0) {
      iVar3 = (((uVar8 - param_4[10]) * 0xc - (uint)*puVar4) - (int)puVar4) + (uint)*param_4 +
              (int)param_4;
      do {
        if (((*(ushort *)((int)puVar7 + iVar3 + 8) ^ (ushort)puVar7[2]) & 4) != 0) {
          return 0x80029c83;
        }
        if (((ushort)puVar7[2] & 8) == 0) {
          if (puVar7[1] != *(uint *)((int)puVar7 + iVar3 + 4)) {
            return 0x80029c83;
          }
          uVar8 = *puVar7;
          uVar9 = *(uint *)(iVar3 + (int)puVar7);
          if (uVar8 != uVar9) {
            if ((uVar8 & 0x80000000) != 0) {
              return 0x80029c83;
            }
            if ((uVar9 & 0x80000000) != 0) {
              return 0x80029c83;
            }
            if (*(short *)(*(int *)(param_2 + 0xd4) + uVar8) != 0x1c) {
              return 0x80029c83;
            }
            if (*(short *)(*(int *)(param_2 + 0xd4) + uVar9) != 0x1c) {
              return 0x80029c83;
            }
          }
        }
        else {
          uVar5 = uVar5 + 1;
        }
        uVar1 = uVar1 + 1;
        puVar7 = puVar7 + 3;
      } while (uVar1 < uVar6);
    }
    if ((uVar2 != 2) || (uVar6 + 1 == uVar5)) {
      return 0;
    }
  }
  return 0x80029c83;
}



/* 4045b030 FUN_4045b030 */

/* Boundary evidence: original MIPS .pdata 4045b030..4045b0cb. Semantic name remains unreviewed. */

void FUN_4045b030(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
  if (iVar3 != 0) {
    iVar4 = iVar3 * 4;
    do {
      iVar4 = iVar4 + -4;
      piVar2 = (int *)(iVar4 + *(int *)(param_1 + 0x20));
      iVar1 = *piVar2;
      iVar3 = iVar3 + -1;
      if (iVar1 != -1) {
        *piVar2 = -1;
        FUN_4045d830(param_2,iVar1,(int *)(*(int *)(param_2 + 0xac) + iVar1));
      }
    } while (iVar3 != 0);
  }
  FUN_40458ba0(param_1);
  return;
}



/* 4045b0cc FUN_4045b0cc */

/* Boundary evidence: original MIPS .pdata 4045b0cc..4045b22b. Semantic name remains unreviewed. */

int FUN_4045b0cc(int param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  LPVOID pvVar2;
  undefined2 *puVar3;
  int iVar4;
  int local_20 [2];
  
  iVar1 = FUN_4045a374(param_1,local_20,param_3);
  if (-1 < iVar1) {
    puVar3 = (undefined2 *)(*(int *)(param_1 + 0x10) + local_20[0]);
    *puVar3 = (short)param_3;
    puVar3[1] = (short)param_2;
    *(undefined4 *)(puVar3 + 2) = 0xffffffff;
    iVar1 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
    if (iVar1 == *(int *)(param_1 + 0x18)) {
      iVar4 = *(int *)(param_1 + 0x18) + 0x10;
      *(int *)(param_1 + 0x18) = iVar4;
      pvVar2 = FUN_40458a64(*(LPVOID *)(param_1 + 0x1c),iVar4 * 4);
      *(LPVOID *)(param_1 + 0x1c) = pvVar2;
      pvVar2 = FUN_40458a64(*(LPVOID *)(param_1 + 0x20),*(int *)(param_1 + 0x18) << 2);
      *(LPVOID *)(param_1 + 0x20) = pvVar2;
      pvVar2 = FUN_40458a64(*(LPVOID *)(param_1 + 0x24),*(int *)(param_1 + 0x18) << 2);
      *(LPVOID *)(param_1 + 0x24) = pvVar2;
      if (((*(int *)(param_1 + 0x1c) == 0) || (*(int *)(param_1 + 0x20) == 0)) ||
         (pvVar2 == (LPVOID)0x0)) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        return -0x7ff8fff2;
      }
    }
    iVar1 = iVar1 - param_2;
    if (iVar1 != 0) {
      FUN_4045a6d8(param_1,iVar1,param_2,1);
    }
    iVar4 = param_2 * 4;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar4) = 0xffffffff;
    *(undefined4 *)(*(int *)(param_1 + 0x20) + iVar4) = 0xffffffff;
    iVar1 = 0;
    *(int *)(*(int *)(param_1 + 0x24) + iVar4) = local_20[0];
    *param_4 = local_20[0];
  }
  return iVar1;
}



/* 4045b22c FUN_4045b22c */

/* Boundary evidence: original MIPS .pdata 4045b22c..4045b2d7. Semantic name remains unreviewed. */

int FUN_4045b22c(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(ushort *)(param_1 + 0x16) < param_2) {
    iVar1 = -0x7ffd7fd5;
  }
  else {
    iVar1 = FUN_4045b0cc(param_1,*(ushort *)(param_1 + 0x14) + param_2,0x28,param_3);
    if (-1 < iVar1) {
      *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + 1;
      iVar2 = *(int *)(param_1 + 0x10) + *param_3;
      iVar1 = 0;
      *(undefined2 *)(iVar2 + 0xc) = 0;
      *(undefined2 *)(iVar2 + 0xe) = 0xffff;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x18) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x1c) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x20) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x24) = 0;
    }
  }
  return iVar1;
}



/* 4045b2d8 FUN_4045b2d8 */

/* Boundary evidence: original MIPS .pdata 4045b2d8..4045b467. Semantic name remains unreviewed. */

int FUN_4045b2d8(int param_1,uint param_2,int param_3,uint param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  
  if (*(ushort *)(param_1 + 0x14) < param_2) {
    iVar1 = -0x7ffd7fd5;
  }
  else {
    iVar1 = 4;
    if (param_4 == 0) {
      iVar1 = 0;
    }
    iVar1 = FUN_4045b0cc(param_1,param_2,(iVar1 + 0x10) * param_3 + 0x34U & 0xffff,param_5);
    if (-1 < iVar1) {
      *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + 1;
      puVar3 = (ushort *)(*(int *)(param_1 + 0x10) + *param_5);
      puVar3[10] = (ushort)param_3;
      puVar3[6] = 0xffff;
      puVar3[7] = 0xffff;
      puVar3[9] = (ushort)param_2;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[8] = (ushort)((param_4 & 1) << 0xc);
      puVar3[0xb] = 0;
      puVar3[0xc] = 0;
      puVar3[0xd] = 0;
      puVar3[0xe] = 0xffff;
      puVar3[0xf] = 0xffff;
      puVar3[0x10] = 0xffff;
      puVar3[0x11] = 0xffff;
      puVar3[0x12] = 0xffff;
      puVar3[0x13] = 0xffff;
      puVar3[0x14] = 0xffff;
      puVar3[0x15] = 0xffff;
      puVar3[0x16] = 0;
      puVar3[0x17] = 0;
      memset(puVar3 + 0x18,-1,param_3 * 4 + 4);
      if (param_4 != 0) {
        memset((void *)((uint)*puVar3 + (uint)puVar3[10] * -0x10 + (int)puVar3),-1,param_3 * 4);
      }
      puVar2 = (undefined4 *)((uint)*puVar3 + (uint)puVar3[10] * -0xc + (int)puVar3);
      for (; param_3 != 0; param_3 = param_3 + -1) {
        *puVar2 = 0xffffffff;
        puVar2[1] = 0xffffffff;
        *(undefined2 *)(puVar2 + 2) = 0;
        *(undefined2 *)((int)puVar2 + 10) = 0;
        puVar2 = puVar2 + 3;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4045b468 FUN_4045b468 */

/* Boundary evidence: original MIPS .pdata 4045b468..4045b513. Semantic name remains unreviewed. */

void FUN_4045b468(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = (int *)(*(int *)(param_1 + 0x20) + param_3 * 4);
  iVar1 = *piVar2;
  *piVar2 = -1;
  FUN_4045c31c(param_2,iVar1);
  iVar1 = (((uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14)) - param_3) + -1;
  uVar3 = *(uint *)(*(int *)(param_1 + 0x24) + param_3 * 4);
  if (iVar1 != 0) {
    FUN_4045a6d8(param_1,iVar1,param_3,-1);
  }
  FUN_4045a488(param_1,uVar3,(uint)*(ushort *)(*(int *)(param_1 + 0x10) + uVar3));
  return;
}



/* 4045b514 FUN_4045b514 */

/* Boundary evidence: original MIPS .pdata 4045b514..4045b573. Semantic name remains unreviewed. */

undefined4 FUN_4045b514(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_3 < *(ushort *)(param_1 + 0x16)) {
    FUN_4045b468(param_1,param_2,*(ushort *)(param_1 + 0x14) + param_3);
    *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + -1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x8002802b;
  }
  return uVar1;
}



/* 4045b574 FUN_4045b574 */

/* Boundary evidence: original MIPS .pdata 4045b574..4045b617. Semantic name remains unreviewed. */

undefined4 FUN_4045b574(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 < *(ushort *)(param_1 + 0x14)) {
    uVar1 = *(ushort *)
             (*(int *)(param_3 * 4 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10) + 0x12);
    uVar4 = (uint)uVar1;
    if (uVar4 != param_3) {
      do {
        iVar3 = *(int *)(uVar4 * 4 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10);
        uVar4 = (uint)*(ushort *)(iVar3 + 0x12);
      } while (uVar4 != param_3);
      *(ushort *)(iVar3 + 0x12) = uVar1;
    }
    FUN_4045b468(param_1,param_2,param_3);
    *(short *)(param_1 + 0x14) = *(short *)(param_1 + 0x14) + -1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x8002802b;
  }
  return uVar2;
}



/* 4045b618 FUN_4045b618 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4045b618..4045babf. Semantic name remains unreviewed. */

int FUN_4045b618(int param_1,int param_2,int *param_3,ushort param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ushort *puVar17;
  uint *puVar18;
  int local_38 [4];
  
  uVar16 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
  uVar10 = 0;
  if (*(ushort *)(param_1 + 0x14) != 0) {
    iVar8 = 0;
    do {
      *(short *)(*(int *)(iVar8 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10) + 0x12) =
           (short)uVar10;
      uVar10 = uVar10 + 1;
      iVar8 = iVar8 + 4;
    } while (uVar10 < *(ushort *)(param_1 + 0x14));
  }
  uVar10 = 0;
  if (*(short *)(param_1 + 0x14) != 0) {
    iVar8 = 0;
LAB_4045b6c8:
    puVar17 = (ushort *)(*(int *)(iVar8 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10));
    if (puVar17[9] == uVar10) {
      memset(local_38,0,0x10);
      local_38[(char)(&DAT_40441af0)[puVar17[8] >> 3 & 0xf]] = (int)puVar17;
      uVar14 = uVar10;
      do {
        uVar14 = uVar14 + 1;
        uVar11 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
        if (uVar14 < uVar11) {
          piVar9 = (int *)(uVar14 * 4 + *(int *)(param_1 + 0x20));
          do {
            if (*piVar9 == *(int *)(iVar8 + *(int *)(param_1 + 0x20))) goto LAB_4045b778;
            uVar14 = uVar14 + 1;
            piVar9 = piVar9 + 1;
          } while (uVar14 < uVar11);
        }
        uVar14 = 0xffffffff;
LAB_4045b778:
        if (uVar14 == 0xffffffff) goto LAB_4045b7b0;
        iVar2 = FUN_4045ad40(param_1,uVar14,uVar10,(int)local_38);
        if (iVar2 < 0) {
          return iVar2;
        }
      } while( true );
    }
    goto LAB_4045b8b0;
  }
LAB_4045b8d8:
  uVar10 = 0;
  if (uVar16 == 0) {
    return 0;
  }
  iVar8 = 0;
  uVar14 = uVar16;
LAB_4045b8e8:
  uVar11 = 0xffffffff;
  puVar18 = *(uint **)(param_1 + 0x1c);
  uVar15 = *(uint *)(iVar8 + (int)puVar18);
  if (uVar15 == 0xffffffff) {
    uVar15 = (uint)param_4 * 0x10000 + uVar10;
    uVar13 = uVar15 | 0x40000000;
    if (uVar10 < *(ushort *)(param_1 + 0x14)) {
      uVar13 = uVar15 | 0x60000000;
    }
    uVar12 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
    uVar7 = 0;
    puVar6 = puVar18;
    uVar15 = uVar11;
    if (uVar12 != 0) {
      do {
        uVar15 = uVar7;
        if (*puVar6 == uVar13) break;
        uVar7 = uVar7 + 1;
        puVar6 = puVar6 + 1;
        uVar15 = uVar11;
      } while (uVar7 < uVar12);
    }
    if (uVar15 != 0xffffffff) {
      do {
        uVar7 = 0;
        uVar15 = uVar11;
        if (uVar12 != 0) {
          puVar6 = puVar18;
          do {
            uVar15 = uVar7;
            if (*puVar6 == uVar14 + (uVar13 - uVar10)) break;
            uVar7 = uVar7 + 1;
            puVar6 = puVar6 + 1;
            uVar15 = uVar11;
          } while (uVar7 < uVar12);
        }
        if (uVar15 == 0xffffffff) goto LAB_4045b9b4;
        uVar14 = uVar14 + 1;
      } while( true );
    }
    goto LAB_4045b9b8;
  }
  if ((param_3 != (int *)0x0) &&
     (iVar2 = (**(code **)(*param_3 + 0x30))(param_3,uVar15,0,0,0,0), iVar2 == 0)) {
    return -0x7ffd773a;
  }
  goto LAB_4045ba68;
LAB_4045b7b0:
  iVar2 = *(int *)(iVar8 + *(int *)(param_1 + 0x1c));
  uVar14 = uVar10;
  if (iVar2 != -1) {
    do {
      uVar15 = uVar14 + 1;
      uVar11 = (uint)*(ushort *)(param_1 + 0x16) + (uint)*(ushort *)(param_1 + 0x14);
      uVar14 = 0xffffffff;
      if (uVar15 < uVar11) {
        piVar9 = (int *)(uVar15 * 4 + *(int *)(param_1 + 0x1c));
        do {
          uVar14 = uVar15;
          if (*piVar9 == iVar2) break;
          uVar15 = uVar15 + 1;
          piVar9 = piVar9 + 1;
          uVar14 = 0xffffffff;
        } while (uVar15 < uVar11);
      }
      if (uVar14 == 0xffffffff) break;
      iVar3 = FUN_4045ad40(param_1,uVar14,uVar10,(int)local_38);
      if (iVar3 < 0) {
        return iVar3;
      }
    } while( true );
  }
  iVar3 = local_38[0];
  uVar14 = 1;
  piVar9 = local_38;
  do {
    piVar9 = piVar9 + 1;
    puVar5 = (ushort *)*piVar9;
    if (puVar5 != (ushort *)0x0) {
      if (iVar3 != 0) {
        return -0x7ffd637d;
      }
      uVar1 = puVar17[9];
      puVar17[9] = puVar5[1];
      puVar5[9] = uVar1;
      if (((puVar5 != puVar17) && (iVar2 != 0x7d5)) &&
         (iVar4 = FUN_4045ae40(param_1,param_2,puVar17,puVar5), iVar4 < 0)) {
        return iVar4;
      }
    }
    uVar14 = uVar14 + 1;
  } while (uVar14 < 4);
LAB_4045b8b0:
  uVar10 = uVar10 + 1;
  iVar8 = iVar8 + 4;
  if (*(ushort *)(param_1 + 0x14) <= uVar10) goto LAB_4045b8d8;
  goto LAB_4045b6c8;
LAB_4045b9b4:
  uVar13 = uVar14 + (uVar13 - uVar10);
LAB_4045b9b8:
  *(uint *)(iVar8 + (int)puVar18) = uVar13;
  if (uVar10 < *(ushort *)(param_1 + 0x14)) {
    uVar1 = *(ushort *)
             (*(int *)(iVar8 + *(int *)(param_1 + 0x24)) + *(int *)(param_1 + 0x10) + 0x12);
    while (uVar1 != uVar10) {
      iVar4 = (uint)uVar1 * 4;
      iVar3 = *(int *)(iVar4 + *(int *)(param_1 + 0x24));
      iVar2 = *(int *)(param_1 + 0x10);
      *(uint *)(iVar4 + *(int *)(param_1 + 0x1c)) = uVar13;
      uVar1 = *(ushort *)(iVar3 + iVar2 + 0x12);
    }
  }
LAB_4045ba68:
  uVar10 = uVar10 + 1;
  iVar8 = iVar8 + 4;
  if (uVar16 <= uVar10) {
    return 0;
  }
  goto LAB_4045b8e8;
}



/* 4045bac0 FUN_4045bac0 */

undefined4 FUN_4045bac0(undefined4 param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)(param_2 + 8) | (*(byte *)(param_2 + 9) & 3) << 8;
  if (uVar4 != 0) {
    pcVar3 = (char *)(param_2 + 0xc);
    do {
      uVar1 = (uint)*pcVar3;
      if ((0x40 < (int)uVar1) && ((int)uVar1 < 0x5b)) {
        uVar1 = uVar1 + 0x20;
      }
      uVar2 = (uint)*param_3;
      if ((0x40 < uVar2) && (uVar2 < 0x5b)) {
        uVar2 = uVar2 + 0x20;
      }
      if (uVar1 != uVar2) {
        return 0;
      }
      pcVar3 = pcVar3 + 1;
      param_3 = param_3 + 1;
    } while ((int)(pcVar3 + (-0xc - param_2)) < (int)uVar4);
  }
  return 1;
}



/* 4045bb68 FUN_4045bb68 */

/* Boundary evidence: original MIPS .pdata 4045bb68..4045bbbf. Semantic name remains unreviewed. */

void FUN_4045bb68(ITypeLib **param_1)

{
  HRESULT HVar1;
  
  HVar1 = LoadRegTypeLib((GUID *)&DAT_40441d0c,2,0,0,param_1);
  if (HVar1 != 0) {
    FUN_40449374(L"oleaut32.dll",0,(int *)param_1);
  }
  return;
}



/* 4045bbc0 FUN_4045bbc0 */

/* Boundary evidence: original MIPS .pdata 4045bbc0..4045bc07. Semantic name remains unreviewed. */

undefined4 FUN_4045bbc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ITypeLib **ppIVar2;
  
  ppIVar2 = (ITypeLib **)(param_1 + 0x1d0);
  uVar1 = 0;
  if (*ppIVar2 == (ITypeLib *)0x0) {
    uVar1 = FUN_4045bb68(ppIVar2);
  }
  *param_2 = *ppIVar2;
  return uVar1;
}



/* 4045bc08 FUN_4045bc08 */

/* Boundary evidence: original MIPS .pdata 4045bc08..4045bc93. Semantic name remains unreviewed. */

undefined4 FUN_4045bc08(char *param_1,UINT param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  undefined4 uVar2;
  int iVar3;
  
  pOVar1 = SysAllocStringLen((OLECHAR *)0x0,param_2);
  *param_3 = pOVar1;
  if (pOVar1 == (BSTR)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    iVar3 = param_2 + 1;
    while (1 < iVar3) {
      iVar3 = iVar3 + -1;
      if (*param_1 == '\0') break;
      *pOVar1 = (short)*param_1;
      pOVar1 = pOVar1 + 1;
      param_1 = param_1 + 1;
    }
    *pOVar1 = L'\0';
    uVar2 = 0;
  }
  return uVar2;
}



/* 4045bc94 FUN_4045bc94 */

/* Boundary evidence: original MIPS .pdata 4045bc94..4045bcdf. Semantic name remains unreviewed. */

undefined4 FUN_4045bc94(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x1b4) == 0) {
    uVar1 = FUN_40460620(*(ushort *)(param_1 + 0x148) & 3,*(uint *)(param_1 + 0x140),
                         (ushort *)&DAT_40441afc);
    *(uint *)(param_1 + 0x1b4) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x1b4);
}



/* 4045bce0 FUN_4045bce0 */

/* Boundary evidence: original MIPS .pdata 4045bce0..4045bd77. Semantic name remains unreviewed. */

int FUN_4045bce0(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x94) = 0xf;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xa8) = 0xf;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x180) = 0x80;
  iVar1 = FUN_4045a0ac(param_1 + 0x88,0x200);
  if (-1 < iVar1) {
    puVar3 = *(undefined4 **)(param_1 + 0x98);
    uVar2 = 0;
    if (*(int *)(param_1 + 0x180) != 0) {
      do {
        *puVar3 = 0xffffffff;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x180));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045bd78 FUN_4045bd78 */

/* Boundary evidence: original MIPS .pdata 4045bd78..4045be43. Semantic name remains unreviewed. */

int FUN_4045bd78(int param_1,ushort *param_2,int param_3,short param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x98) + param_3 * 4);
  if (iVar2 != -1) {
    iVar4 = *(int *)(param_1 + 0xac);
    do {
      iVar3 = iVar4 + iVar2;
      if ((*(short *)(iVar3 + 10) == param_4) &&
         (iVar1 = FUN_4045bac0(*(undefined4 *)(param_1 + 0x140),iVar3,param_2), iVar1 != 0)) {
        return iVar2;
      }
      iVar2 = *(int *)(iVar3 + 4);
    } while (iVar2 != -1);
  }
  return iVar2;
}



/* 4045be44 FUN_4045be44 */

/* Boundary evidence: original MIPS .pdata 4045be44..4045beef. Semantic name remains unreviewed. */

void FUN_4045be44(int param_1,ushort *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  
  if ((param_3 == 0) || (uVar1 = FUN_4045bc94(param_1), ((uVar1 ^ param_3) & 0xff0000) != 0)) {
    param_3 = FUN_40460620(*(ushort *)(param_1 + 0x148) & 3,*(uint *)(param_1 + 0x140),param_2);
  }
  uVar1 = param_3 % *(uint *)(param_1 + 0x180);
  if (*(uint *)(param_1 + 0x180) == 0) {
    trap(0x1c00);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1;
  }
  FUN_4045bd78(param_1,param_2,uVar1,(short)param_3);
  return;
}



/* 4045bef0 FUN_4045bef0 */

/* Boundary evidence: original MIPS .pdata 4045bef0..4045bf9f. Semantic name remains unreviewed. */

void FUN_4045bef0(int param_1,ushort *param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_40460620(*(ushort *)(param_1 + 0x148) & 3,*(uint *)(param_1 + 0x140),param_2);
  uVar1 = uVar1 % *(uint *)(param_1 + 0x180);
  if (*(uint *)(param_1 + 0x180) == 0) {
    trap(0x1c00);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar1;
  }
  uVar2 = FUN_40460620(*(ushort *)(param_1 + 0x148) & 3,*(uint *)(param_1 + 0x140),param_2);
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2 & 0xffff;
  }
  FUN_4045bd78(param_1,param_2,uVar1,(short)uVar2);
  return;
}



/* 4045bfa0 FUN_4045bfa0 */

/* Boundary evidence: original MIPS .pdata 4045bfa0..4045c1b7. Semantic name remains unreviewed. */

int FUN_4045bfa0(int param_1,wchar_t *param_2,int *param_3)

{
  size_t _Size;
  size_t sVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  wchar_t *pwVar5;
  undefined4 *puVar6;
  int local_430;
  uint local_42c;
  uint local_428 [2];
  undefined1 local_420 [1024];
  uint local_20;
  
  local_20 = DAT_4046d1b8;
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    *param_3 = -1;
  }
  else {
    _Size = wcslen(param_2);
    sVar1 = wcslen(param_2);
    iVar2 = sVar1 + 1;
    puVar3 = local_420;
    pwVar5 = param_2;
    while (1 < iVar2) {
      iVar2 = iVar2 + -1;
      if (*pwVar5 == L'\0') break;
      *puVar3 = (char)*pwVar5;
      puVar3 = puVar3 + 1;
      pwVar5 = pwVar5 + 1;
    }
    *puVar3 = 0;
    iVar2 = FUN_4045bef0(param_1,(ushort *)param_2,&local_42c,local_428);
    if (iVar2 == -1) {
      iVar2 = FUN_4045a374(param_1 + 0x9c,&local_430,_Size + 0xc);
      if (iVar2 < 0) {
        FUN_4046ace8(local_20);
        return iVar2;
      }
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0xac) + local_430);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)0x0;
      }
      else {
        *puVar6 = 0xffffffff;
        puVar6[1] = 0xffffffff;
        *(undefined1 *)(puVar6 + 2) = 0;
        *(undefined1 *)((int)puVar6 + 9) = 0;
        *(undefined1 *)((int)puVar6 + 10) = 0;
        *(undefined1 *)((int)puVar6 + 0xb) = 0;
      }
      puVar6[1] = *(undefined4 *)(local_42c * 4 + *(int *)(param_1 + 0x98));
      *(int *)(local_42c * 4 + *(int *)(param_1 + 0x98)) = local_430;
      uVar4 = (*(ushort *)(puVar6 + 2) ^ _Size) & 0x3ff ^ (uint)*(ushort *)(puVar6 + 2);
      *(char *)(puVar6 + 2) = (char)uVar4;
      *(char *)((int)puVar6 + 10) = (char)(undefined2)local_428[0];
      *(char *)((int)puVar6 + 9) = (char)(uVar4 >> 8);
      *(char *)((int)puVar6 + 0xb) = (char)((ushort)(undefined2)local_428[0] >> 8);
      memcpy(puVar6 + 3,local_420,_Size);
      *(int *)(param_1 + 0x164) = *(int *)(param_1 + 0x164) + 1;
      *(size_t *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + _Size;
      iVar2 = local_430;
    }
    *param_3 = iVar2;
  }
  FUN_4046ace8(local_20);
  return 0;
}



/* 4045c1b8 FUN_4045c1b8 */

/* Boundary evidence: original MIPS .pdata 4045c1b8..4045c1e7. Semantic name remains unreviewed. */

undefined4 FUN_4045c1b8(int param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_4045be44(param_1,param_2,param_3,(uint *)0x0);
  *param_4 = uVar1;
  return 0;
}



/* 4045c1e8 FUN_4045c1e8 */

/* Boundary evidence: original MIPS .pdata 4045c1e8..4045c2c3. Semantic name remains unreviewed. */

int FUN_4045c1e8(int param_1,wchar_t *param_2,int *param_3)

{
  size_t _Size;
  int iVar1;
  undefined1 *puVar2;
  int local_20 [2];
  
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    *param_3 = -1;
  }
  else {
    _Size = wcslen(param_2);
    if (0xffff < _Size) {
      return -0x7ff8fff2;
    }
    iVar1 = FUN_4045a374(param_1 + 0xb0,local_20,_Size + 2);
    if (iVar1 < 0) {
      return iVar1;
    }
    puVar2 = (undefined1 *)(*(int *)(param_1 + 0xc0) + local_20[0]);
    *puVar2 = (char)(_Size & 0xffff);
    puVar2[1] = (char)((_Size & 0xffff) >> 8);
    memcpy(puVar2 + 2,param_2,_Size);
    *param_3 = local_20[0];
  }
  return 0;
}



/* 4045c2c4 FUN_4045c2c4 */

/* Boundary evidence: original MIPS .pdata 4045c2c4..4045c31b. Semantic name remains unreviewed. */

undefined4 FUN_4045c2c4(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == -1) {
    *param_3 = 0;
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xac) + param_2;
    uVar1 = FUN_4045bc08((char *)(iVar2 + 0xc),
                         (uint)*(byte *)(iVar2 + 8) | (*(byte *)(iVar2 + 9) & 3) << 8,param_3);
  }
  return uVar1;
}



/* 4045c31c FUN_4045c31c */

/* Boundary evidence: original MIPS .pdata 4045c31c..4045c34b. Semantic name remains unreviewed. */

void FUN_4045c31c(int param_1,int param_2)

{
  if (param_2 != -1) {
    FUN_4045d830(param_1,param_2,(int *)(*(int *)(param_1 + 0xac) + param_2));
  }
  return;
}



/* 4045c34c FUN_4045c34c */

/* Boundary evidence: original MIPS .pdata 4045c34c..4045c3e3. Semantic name remains unreviewed. */

int FUN_4045c34c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x6c) = 0xf;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x80) = 0xf;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x17c) = 0x20;
  iVar1 = FUN_4045a0ac(param_1 + 0x60,0x80);
  if (-1 < iVar1) {
    puVar3 = *(undefined4 **)(param_1 + 0x70);
    uVar2 = 0;
    if (*(int *)(param_1 + 0x17c) != 0) {
      do {
        *puVar3 = 0xffffffff;
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar2 < *(uint *)(param_1 + 0x17c));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045c3e4 FUN_4045c3e4 */

/* Boundary evidence: original MIPS .pdata 4045c3e4..4045c4d7. Semantic name remains unreviewed. */

undefined4 FUN_4045c3e4(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  void *_Buf1;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = 4;
  puVar2 = param_2;
  do {
    uVar4 = *puVar2 ^ uVar4;
    iVar3 = iVar3 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  if (*(uint *)(param_1 + 0x17c) == 0) {
    trap(0x1c00);
  }
  iVar3 = *(int *)(((uVar4 >> 0x10 ^ uVar4 & 0xffff) % *(uint *)(param_1 + 0x17c)) * 4 +
                  *(int *)(param_1 + 0x70));
  if (iVar3 != -1) {
    iVar5 = *(int *)(param_1 + 0x84);
    do {
      _Buf1 = (void *)(iVar5 + iVar3);
      iVar1 = memcmp(_Buf1,param_2,0x10);
      if (iVar1 == 0) {
        if (iVar3 == -1) {
          return 0x8002802b;
        }
        *param_3 = iVar3;
        return 0;
      }
      iVar3 = *(int *)((int)_Buf1 + 0x14);
    } while (iVar3 != -1);
  }
  return 0x8002802b;
}



/* 4045c4d8 FUN_4045c4d8 */

/* Boundary evidence: original MIPS .pdata 4045c4d8..4045c64f. Semantic name remains unreviewed. */

int FUN_4045c4d8(int param_1,uint *param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int local_20;
  int local_1c;
  
  iVar1 = FUN_4045c3e4(param_1,param_2,&local_1c);
  if (iVar1 == 0) {
    if (param_3 != 0xffffffff) {
      iVar1 = *(int *)(param_1 + 0x84) + local_1c;
      if (*(int *)(iVar1 + 0x10) != -1) {
        return -0x7ffd773a;
      }
      *(uint *)(iVar1 + 0x10) = param_3;
    }
  }
  else {
    uVar3 = 0;
    iVar1 = 4;
    puVar4 = param_2;
    do {
      uVar3 = *puVar4 ^ uVar3;
      iVar1 = iVar1 + -1;
      puVar4 = puVar4 + 1;
    } while (iVar1 != 0);
    uVar2 = *(uint *)(param_1 + 0x17c);
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    iVar1 = FUN_4045a374(param_1 + 0x74,&local_20,0x18);
    if (iVar1 < 0) {
      return iVar1;
    }
    puVar4 = (uint *)(*(int *)(param_1 + 0x84) + local_20);
    if (puVar4 == (uint *)0x0) {
      puVar4 = (uint *)0x0;
    }
    else {
      puVar4[4] = 0xffffffff;
      puVar4[5] = 0xffffffff;
    }
    iVar1 = ((uVar3 >> 0x10 ^ uVar3 & 0xffff) % uVar2) * 4;
    *puVar4 = *param_2;
    puVar4[1] = param_2[1];
    puVar4[2] = param_2[2];
    puVar4[3] = param_2[3];
    puVar4[4] = param_3;
    puVar4[5] = *(uint *)(*(int *)(param_1 + 0x70) + iVar1);
    *(int *)(*(int *)(param_1 + 0x70) + iVar1) = local_20;
    local_1c = local_20;
  }
  *param_4 = local_1c;
  return 0;
}



/* 4045c650 FUN_4045c650 */

/* Boundary evidence: original MIPS .pdata 4045c650..4045cab7. Semantic name remains unreviewed. */

int FUN_4045c650(int param_1,int *param_2,int *param_3,undefined4 param_4,uint *param_5)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined2 *puVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int *local_res4 [3];
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  int *local_30;
  int local_2c;
  
  local_40 = (uint *)0x0;
  local_30 = (int *)0x0;
  local_res4[0] = param_2;
  iVar3 = (**(code **)(*param_2 + 0x1c))(param_2,&local_3c);
  puVar7 = local_3c;
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = memcmp(local_3c,&DAT_40441d0c,0x10);
  bVar2 = true;
  piVar5 = param_3;
  if (((iVar3 == 0) && ((short)puVar7[6] == 1)) && (*(short *)((int)puVar7 + 0x1a) == 0)) {
    (**(code **)(*param_2 + 0x30))(param_2,puVar7);
    iVar3 = FUN_4045bbc0(param_1,local_res4);
    param_2 = local_res4[0];
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*local_res4[0] + 0x1c))(local_res4[0],&local_3c);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(*param_2 + 0x10))(param_2,param_4,&local_30);
    puVar7 = local_40;
    piVar5 = local_30;
    if (iVar3 < 0) goto LAB_4045ca38;
  }
  iVar3 = (**(code **)(*piVar5 + 0xc))(piVar5,&local_40);
  puVar7 = local_40;
  param_3 = piVar5;
  if (iVar3 < 0) goto LAB_4045ca38;
  iVar3 = FUN_4045c4d8(param_1,local_3c,0xffffffff,&local_2c);
  iVar9 = local_2c;
  if (iVar3 < 0) {
    return iVar3;
  }
  puVar8 = (uint *)(*(int *)(param_1 + 0x84) + local_2c + 0x10);
  local_34 = *puVar8;
  if (local_34 == 0xffffffff) {
    iVar3 = FUN_4045a374(param_1 + 0x38,(int *)&local_34,0xe);
    puVar7 = local_40;
    if (iVar3 < 0) goto LAB_4045ca38;
    *puVar8 = local_34 | 2;
    piVar5 = (int *)(*(int *)(param_1 + 0x48) + local_34);
    *piVar5 = iVar9;
    piVar5[1] = local_3c[4];
    uVar4 = local_3c[6];
    *(char *)(piVar5 + 2) = (char)(short)uVar4;
    *(char *)((int)piVar5 + 9) = (char)((ushort)(short)uVar4 >> 8);
    uVar1 = *(undefined2 *)((int)local_3c + 0x1a);
    *(char *)((int)piVar5 + 10) = (char)uVar1;
    *(char *)((int)piVar5 + 0xb) = (char)((ushort)uVar1 >> 8);
    *(byte *)(piVar5 + 3) = (byte)local_3c[5] & 3;
    *(undefined1 *)((int)piVar5 + 0xd) = 0;
    memcpy((void *)((int)piVar5 + 0xe),(void *)0x0,0);
  }
  else {
    if ((local_34 == 0xfffffffe) || ((local_34 & 2) != 2)) {
      return -0x7ffd773a;
    }
    local_34 = local_34 & 0xfffffffc;
  }
  puVar7 = local_40;
  iVar3 = memcmp(local_40,&DAT_40443ecc,0x10);
  iVar9 = local_2c;
  if (iVar3 == 0) {
LAB_4045c944:
    bVar2 = false;
LAB_4045c948:
    iVar3 = FUN_4045a374(param_1 + 0x24,(int *)&local_38,0xc);
    puVar7 = local_40;
    if (iVar3 < 0) goto LAB_4045ca38;
    puVar6 = (undefined2 *)(*(int *)(param_1 + 0x34) + local_38);
    *puVar6 = (short)*(undefined4 *)(param_1 + 0x188);
    *(int *)(param_1 + 0x188) = *(int *)(param_1 + 0x188) + 1;
    *(bool *)(puVar6 + 1) = bVar2;
    *(char *)((int)puVar6 + 3) = (char)local_40[10];
    *(uint *)(puVar6 + 2) = local_34;
    if (bVar2) {
      *puVar8 = local_38 | 1;
      *(int *)(puVar6 + 4) = iVar9;
      if ((*(int *)(param_1 + 0x184) == -1) &&
         (iVar3 = memcmp(local_40,&DAT_40443edc,0x10), iVar3 == 0)) {
        *(uint *)(param_1 + 0x184) = local_38 | 1;
      }
    }
    else {
      *(undefined4 *)(puVar6 + 4) = param_4;
    }
  }
  else {
    iVar3 = FUN_4045c4d8(param_1,puVar7,0xffffffff,&local_2c);
    if (iVar3 < 0) {
      return iVar3;
    }
    puVar8 = (uint *)(*(int *)(param_1 + 0x84) + local_2c + 0x10);
    local_38 = *puVar8;
    iVar9 = local_2c;
    if (local_38 == 0xffffffff) goto LAB_4045c948;
    if (((local_38 & 1) != 1) ||
       (puVar7 = local_40,
       *(uint *)((local_38 & 0xfffffffc) + *(int *)(param_1 + 0x34) + 4) != local_34))
    goto LAB_4045c944;
  }
  uVar4 = local_38 | 1;
  if ((puVar7[10] == 3) && ((*(ushort *)((int)puVar7 + 0x36) & 0x40) != 0)) {
    uVar4 = local_38 | 3;
  }
  iVar3 = 0;
  *param_5 = uVar4;
LAB_4045ca38:
  if (puVar7 != (uint *)0x0) {
    (**(code **)(*param_3 + 0x4c))(param_3,puVar7);
  }
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))();
  }
  (**(code **)(*param_2 + 0x30))(param_2,local_3c);
  return iVar3;
}



/* 4045cab8 FUN_4045cab8 */

/* Boundary evidence: original MIPS .pdata 4045cab8..4045cb13. Semantic name remains unreviewed. */

int FUN_4045cab8(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x30) & 8) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x24),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x38),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045cb14 FUN_4045cb14 */

/* Boundary evidence: original MIPS .pdata 4045cb14..4045cbbf. Semantic name remains unreviewed. */

int FUN_4045cb14(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  ushort *puVar2;
  
  if (param_2 == -1) {
    *param_3 = 0;
    iVar1 = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0xbc) & 8) == 0) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0xb0),param_1);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      puVar2 = (ushort *)(*(int *)(param_1 + 0xc0) + param_2);
      iVar1 = FUN_4045bc08((char *)(puVar2 + 1),(uint)*puVar2,param_3);
    }
  }
  return iVar1;
}



/* 4045cbc0 FUN_4045cbc0 */

/* Boundary evidence: original MIPS .pdata 4045cbc0..4045ceef. Semantic name remains unreviewed. */

DWORD FUN_4045cbc0(int param_1,int param_2,int *param_3)

{
  DWORD DVar1;
  LPVOID pvVar2;
  HRESULT HVar3;
  uint uVar4;
  ushort *puVar5;
  int *piVar6;
  ITypeLib *local_240;
  ITypeInfo *local_23c;
  TYPEKIND local_238 [2];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_4046d1b8;
  DVar1 = FUN_4045cab8(param_1);
  if ((int)DVar1 < 0) goto LAB_4045cdf8;
  puVar5 = (ushort *)(*(int *)(param_1 + 0x34) + param_2);
  uVar4 = (uint)*puVar5;
  if (uVar4 < *(uint *)(param_1 + 0x1b8)) {
    piVar6 = *(int **)(uVar4 * 4 + *(int *)(param_1 + 0x1bc));
    if (piVar6 != (int *)0x0) {
      *param_3 = (int)piVar6;
      (**(code **)(*piVar6 + 4))();
      FUN_4046ace8(local_28);
      return 0;
    }
  }
  else {
    pvVar2 = FUN_40458a64(*(LPVOID *)(param_1 + 0x1bc),*(int *)(param_1 + 0x188) << 2);
    if (pvVar2 == (LPVOID)0x0) {
      FUN_4046ace8(local_28);
      return 0x8007000e;
    }
    *(LPVOID *)(param_1 + 0x1bc) = pvVar2;
    memset((void *)(*(int *)(param_1 + 0x1b8) * 4 + (int)pvVar2),0,
           (*(int *)(param_1 + 0x188) - *(int *)(param_1 + 0x1b8)) * 4);
    *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x188);
  }
  piVar6 = (int *)(*(int *)(param_1 + 0x48) + *(int *)(puVar5 + 2));
  local_240 = (ITypeLib *)0x0;
  DVar1 = LoadRegTypeLib((GUID *)(*(int *)(param_1 + 0x84) + *piVar6),*(WORD *)(piVar6 + 2),
                         *(WORD *)((int)piVar6 + 10),piVar6[1],&local_240);
  if ((DVar1 != 0) && (*(ushort *)(piVar6 + 3) >> 2 != 0)) {
    MultiByteToWideChar(0,0,(LPCSTR)((int)piVar6 + 0xe),(uint)(*(ushort *)(piVar6 + 3) >> 2),
                        aWStack_230,0x104);
    aWStack_230[*(ushort *)(piVar6 + 3) >> 2] = L'\0';
    DVar1 = FUN_40449374(aWStack_230,0,(int *)&local_240);
  }
  if ((int)DVar1 < 0) goto LAB_4045cdf8;
  if ((puVar5[1] & 1) == 0) {
    DVar1 = (*local_240->lpVtbl->GetTypeInfo)(local_240,*(UINT *)(puVar5 + 4),&local_23c);
    if (-1 < (int)DVar1) {
      HVar3 = (*local_240->lpVtbl->GetTypeInfoType)(local_240,*(UINT *)(puVar5 + 4),local_238);
      if ((((HVar3 == 0) && (local_238[0] == *(byte *)((int)puVar5 + 3))) ||
          (*(char *)((int)puVar5 + 3) == '\x03')) || (*(char *)((int)puVar5 + 3) == '\x04'))
      goto LAB_4045cdb4;
      DVar1 = 0x8002802a;
      (*local_23c->lpVtbl->Release)(local_23c);
    }
  }
  else {
    DVar1 = (*local_240->lpVtbl->GetTypeInfoOfGuid)
                      (local_240,(GUID *)(*(int *)(puVar5 + 4) + *(int *)(param_1 + 0x84)),
                       &local_23c);
    if (-1 < (int)DVar1) {
LAB_4045cdb4:
      (*local_23c->lpVtbl->AddRef)(local_23c);
      *(ITypeInfo **)(uVar4 * 4 + *(int *)(param_1 + 0x1bc)) = local_23c;
      *param_3 = (int)local_23c;
    }
  }
  (*local_240->lpVtbl->Release)(local_240);
LAB_4045cdf8:
  FUN_4046ace8(local_28);
  return DVar1;
}



/* 4045cef0 FUN_4045cef0 */

/* Boundary evidence: original MIPS .pdata 4045cef0..4045cf0b. Semantic name remains unreviewed. */

void FUN_4045cef0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x198));
  return;
}



/* 4045cf0c FUN_4045cf0c */

/* Boundary evidence: original MIPS .pdata 4045cf0c..4045cf5b. Semantic name remains unreviewed. */

int FUN_4045cf0c(int param_1,wchar_t *param_2)

{
  int iVar1;
  int local_10 [2];
  
  if (param_2 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_4045bfa0(param_1,param_2,local_10);
    if (-1 < iVar1) {
      iVar1 = 0;
      *(int *)(param_1 + 0x16c) = local_10[0];
    }
  }
  return iVar1;
}



/* 4045cf6c FUN_4045cf6c */

/* Boundary evidence: original MIPS .pdata 4045cf6c..4045cf97. Semantic name remains unreviewed. */

int FUN_4045cf6c(int param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_4045c4d8(param_1,param_2,0xfffffffe,(int *)(param_1 + 0x13c));
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045cf98 FUN_4045cf98 */

/* Boundary evidence: original MIPS .pdata 4045cf98..4045cfc7. Semantic name remains unreviewed. */

int FUN_4045cf98(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  if (param_2 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_4045c1e8(param_1,param_2,(int *)(param_1 + 0x158));
  }
  return iVar1;
}



/* 4045d01c FUN_4045d01c */

/* Boundary evidence: original MIPS .pdata 4045d01c..4045d037. Semantic name remains unreviewed. */

void FUN_4045d01c(int param_1,uint *param_2,ushort *param_3)

{
  FUN_4045fb60(param_1,param_2,param_3,(int *)(param_1 + 0x178));
  return;
}



/* 4045d04c FUN_4045d04c */

/* Boundary evidence: original MIPS .pdata 4045d04c..4045d09f. Semantic name remains unreviewed. */

undefined4 FUN_4045d04c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    iVar2 = param_1 + 4;
    if (param_1 == 4) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
    (**(code **)(*(int *)(param_1 + -4) + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 4045d0a0 FUN_4045d0a0 */

undefined4 FUN_4045d0a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = 0;
  return 0;
}



/* 4045d0ac FUN_4045d0ac */

/* Boundary evidence: original MIPS .pdata 4045d0ac..4045d0ef. Semantic name remains unreviewed. */

void FUN_4045d0ac(undefined4 param_1,LPVOID param_2)

{
  LPVOID pvVar1;
  
  if (param_2 != (LPVOID)0x0) {
    pvVar1 = TlsGetValue(DAT_4046d1b0);
    FUN_40457ba4((int)pvVar1,param_2);
  }
  return;
}



/* 4045d0f0 FUN_4045d0f0 */

/* Boundary evidence: original MIPS .pdata 4045d0f0..4045d133. Semantic name remains unreviewed. */

int FUN_4045d0f0(int param_1,void *param_2,undefined2 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_40460428(param_1 + -4,*(int *)(param_1 + 0x174),param_2,param_3,(int *)0x0);
  }
  return iVar1;
}



/* 4045d134 FUN_4045d134 */

/* Boundary evidence: original MIPS .pdata 4045d134..4045d177. Semantic name remains unreviewed. */

int FUN_4045d134(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_2 = 0;
    iVar1 = FUN_40460428(param_1 + -4,*(int *)(param_1 + 0x174),(void *)0x0,(undefined2 *)0x0,
                         param_2);
  }
  return iVar1;
}



/* 4045d1a0 FUN_4045d1a0 */

/* Boundary evidence: original MIPS .pdata 4045d1a0..4045d1eb. Semantic name remains unreviewed. */

void FUN_4045d1a0(int *param_1,int *param_2,undefined4 *param_3)

{
  code *pcVar1;
  
  if (*param_2 == 1) {
    pcVar1 = *(code **)(*param_1 + 0x50);
  }
  else {
    if (*param_2 != 2) {
      return;
    }
    pcVar1 = *(code **)(*param_1 + 0x54);
  }
  (*pcVar1)(param_1,*param_3);
  return;
}



/* 4045d1ec FUN_4045d1ec */

/* Boundary evidence: original MIPS .pdata 4045d1ec..4045d237. Semantic name remains unreviewed. */

void FUN_4045d1ec(int param_1,LPVOID param_2)

{
  if ((param_2 < *(LPVOID *)(param_1 + 0x1c4)) || (*(LPVOID *)(param_1 + 0x1c8) <= param_2)) {
    FUN_40458abc(param_2);
  }
  else {
    *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(param_1 + 0x1cc);
    *(LPVOID *)(param_1 + 0x1cc) = param_2;
  }
  return;
}



/* 4045d238 FUN_4045d238 */

void FUN_4045d238(ushort *param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_1 & 0xffc0 | param_2 & 0xf;
  iVar2 = 2;
  *param_1 = (ushort)uVar3;
  if (param_3 != 2) {
    iVar2 = 4;
  }
  uVar3 = (iVar2 << 6 ^ uVar3) & 0x7c0 ^ uVar3;
  *param_1 = ((ushort)(uVar3 << 5) ^ (ushort)uVar3) & 0x7ff ^ (ushort)(uVar3 << 5);
  param_1[1] = 0;
  puVar1 = param_1 + 2;
  if (puVar1 != (ushort *)0x0) {
    param_1[10] = 0;
    param_1[0xb] = 0;
    puVar1[0] = 0xffff;
    puVar1[1] = 0xffff;
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0xffff;
  param_1[7] = 0xffff;
  param_1[8] = 0xf;
  param_1[9] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0xffff;
  param_1[0x17] = 0xffff;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0xffff;
  param_1[0x1b] = 0xffff;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0xffff;
  param_1[0x1f] = 0xffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0xffff;
  param_1[0x25] = 0xffff;
  param_1[0x26] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x27] = 0;
  param_1[0x2a] = 0xffff;
  param_1[0x2b] = 0xffff;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  return;
}



/* 4045d30c FUN_4045d30c */

/* Boundary evidence: original MIPS .pdata 4045d30c..4045d46f. Semantic name remains unreviewed. */

int FUN_4045d30c(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar1 = memcmp(param_2,&DAT_40441cec,0x10);
  if (iVar1 != 0) {
    iVar1 = memcmp(param_2,&DAT_40443f2c,0x10);
    if ((iVar1 != 0) && (iVar1 = memcmp(param_2,&DAT_40443f1c,0x10), iVar1 != 0)) {
      iVar1 = memcmp(param_2,&DAT_40443f0c,0x10);
      if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40443efc,0x10), iVar1 == 0)) {
LAB_4045d420:
        piVar2 = param_1 + 1;
      }
      else {
        iVar1 = memcmp(param_2,&DAT_40443eec,0x10);
        if (iVar1 != 0) {
          iVar1 = memcmp(param_2,&DAT_40443ebc,0x10);
          if (iVar1 != 0) {
            *param_3 = 0;
            return -0x7fffbffe;
          }
          goto LAB_4045d420;
        }
        piVar2 = param_1 + 2;
      }
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      *param_3 = (int)piVar2;
      goto LAB_4045d434;
    }
    iVar1 = FUN_4045928c((int)param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  *param_3 = (int)param_1;
LAB_4045d434:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 4045d470 FUN_4045d470 */

/* Boundary evidence: original MIPS .pdata 4045d470..4045d5e3. Semantic name remains unreviewed. */

int FUN_4045d470(int param_1,wchar_t *param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  ushort uVar3;
  uint _Size;
  ushort *puVar4;
  int *piVar5;
  ushort *puVar6;
  int local_20 [2];
  
  if (param_2 == (wchar_t *)0x0) {
    return -0x7ff8ffa9;
  }
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    local_20[0] = -1;
  }
  else {
    iVar2 = FUN_4045c1e8(param_1,param_2,local_20);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  if (param_3 == 0) {
    if ((*(ushort *)(param_1 + 0x148) & 0x10) != 0) {
LAB_4045d540:
      piVar5 = (int *)((param_3 + 100) * 4 + param_1);
      *piVar5 = local_20[0];
      if (local_20[0] == -1) {
        return 0;
      }
      iVar2 = *(int *)((param_3 + 0x5c) * 4 + param_1);
      if (iVar2 == -1) {
        return 0;
      }
      puVar4 = (ushort *)(*(int *)(param_1 + 0xc0) + local_20[0]);
      puVar6 = (ushort *)(*(int *)(param_1 + 0xc0) + iVar2);
      _Size = (uint)*puVar4;
      if (_Size != *puVar6) {
        return 0;
      }
      iVar2 = memcmp(puVar4 + 1,puVar6 + 1,_Size);
      if (iVar2 != 0) {
        return 0;
      }
      *piVar5 = -1;
      return 0;
    }
    *(int *)(param_1 + 0x170) = local_20[0];
    uVar3 = *(ushort *)(param_1 + 0x148) | 0x10;
  }
  else {
    if ((param_3 != 1) || ((*(ushort *)(param_1 + 0x148) & 0x100) != 0)) goto LAB_4045d540;
    *(int *)(param_1 + 0x174) = local_20[0];
    uVar3 = *(ushort *)(param_1 + 0x148) | 0x100;
  }
  *(ushort *)(param_1 + 0x148) = uVar3;
  return 0;
}



/* 4045d5e4 FUN_4045d5e4 */

/* Boundary evidence: original MIPS .pdata 4045d5e4..4045d5ff. Semantic name remains unreviewed. */

void FUN_4045d5e4(int param_1,wchar_t *param_2)

{
  FUN_4045d470(param_1,param_2,0);
  return;
}



/* 4045d600 FUN_4045d600 */

/* Boundary evidence: original MIPS .pdata 4045d600..4045d61b. Semantic name remains unreviewed. */

void FUN_4045d600(int param_1,wchar_t *param_2)

{
  FUN_4045d470(param_1,param_2,1);
  return;
}



/* 4045d61c FUN_4045d61c */

/* Boundary evidence: original MIPS .pdata 4045d61c..4045d6cf. Semantic name remains unreviewed. */

undefined4 FUN_4045d61c(int param_1,LCID param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  short sVar3;
  
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x140) = 0x409;
  }
  else {
    bVar1 = FUN_40459f3c(param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0x8002802e;
    }
    *(LCID *)(param_1 + 0x140) = param_2;
  }
  uVar2 = param_2 & 0x3ff;
  *(LCID *)(param_1 + 0x144) = param_2;
  if ((uVar2 == 4) || ((0x10 < uVar2 && (uVar2 < 0x13)))) {
    sVar3 = 1;
  }
  else {
    sVar3 = 0;
  }
  *(ushort *)(param_1 + 0x148) =
       (sVar3 << 2 ^ *(ushort *)(param_1 + 0x148)) & 4 ^ *(ushort *)(param_1 + 0x148);
  return 0;
}



/* 4045d730 FUN_4045d730 */

/* Boundary evidence: original MIPS .pdata 4045d730..4045d82f. Semantic name remains unreviewed. */

undefined4 FUN_4045d730(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ushort uVar5;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_2 = 0;
    pvVar2 = TlsGetValue(DAT_4046d1b0);
    puVar3 = FUN_40457d14((int)pvVar2,0x20);
    if (puVar3 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      puVar3[4] = *(undefined4 *)(param_1 + 0x140);
      puVar3[5] = *(ushort *)(param_1 + 0x144) & 3;
      uVar5 = 8;
      if ((*(uint *)(param_1 + 0x1a8) & 1) == 0) {
        uVar5 = 0;
      }
      *(ushort *)(puVar3 + 7) = (ushort)*(undefined4 *)(param_1 + 0x14c) | uVar5;
      *(undefined2 *)(puVar3 + 6) = *(undefined2 *)(param_1 + 0x148);
      *(undefined2 *)((int)puVar3 + 0x1a) = *(undefined2 *)(param_1 + 0x14a);
      if (*(int *)(param_1 + 0x138) == -1) {
        puVar4 = &DAT_40443ecc;
      }
      else {
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0x80) + *(int *)(param_1 + 0x138));
      }
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar4[2];
      puVar3[3] = puVar4[3];
      *param_2 = puVar3;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4045d830 FUN_4045d830 */

/* Boundary evidence: original MIPS .pdata 4045d830..4045d977. Semantic name remains unreviewed. */

void FUN_4045d830(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if ((*(byte *)((int)param_3 + 9) & 8) == 0) {
    uVar7 = 0;
    if (*(int *)(param_1 + 0x154) != 0) {
      iVar9 = 0;
      do {
        iVar8 = *(int *)(*(int *)(param_1 + 0x18c) + iVar9);
        iVar4 = *(int *)(param_1 + 0x20) + iVar8;
        if ((*(uint *)(iVar4 + 0x10) & 8) == 0) {
          iVar1 = FUN_4045a504((int *)(iVar4 + 4),param_1,0);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 == 0) {
          uVar6 = (uint)*(ushort *)(iVar4 + 0x1a) + (uint)*(ushort *)(iVar4 + 0x18);
          uVar2 = 0;
          uVar3 = 0xffffffff;
          if (uVar6 != 0) {
            piVar5 = *(int **)(iVar4 + 0x24);
            do {
              uVar3 = uVar2;
              if (*piVar5 == param_2) break;
              uVar2 = uVar2 + 1;
              piVar5 = piVar5 + 1;
              uVar3 = 0xffffffff;
            } while (uVar2 < uVar6);
          }
          if (uVar3 != 0xffffffff) {
            *param_3 = iVar8;
            return;
          }
        }
        uVar7 = uVar7 + 1;
        iVar9 = iVar9 + 4;
      } while (uVar7 < *(uint *)(param_1 + 0x154));
    }
    *param_3 = -1;
  }
  return;
}



/* 4045da0c FUN_4045da0c */

/* Boundary evidence: original MIPS .pdata 4045da0c..4045da67. Semantic name remains unreviewed. */

int FUN_4045da0c(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x94) & 8) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x88),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0x9c),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045da68 FUN_4045da68 */

/* Boundary evidence: original MIPS .pdata 4045da68..4045dadb. Semantic name remains unreviewed. */

LONG FUN_4045da68(undefined4 *param_1)

{
  LONG LVar1;
  LPVOID pvVar2;
  
  LVar1 = InterlockedDecrement(param_1 + 0x66);
  if ((LVar1 == 0) && (pvVar2 = TlsGetValue(DAT_4046d1b0), pvVar2 != (LPVOID)0x0)) {
    if (param_1 != (undefined4 *)0x0) {
      FUN_40459008(param_1);
      FUN_40458abc(param_1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[0x66];
  }
  return LVar1;
}



/* 4045dadc FUN_4045dadc */

/* Boundary evidence: original MIPS .pdata 4045dadc..4045dccf. Semantic name remains unreviewed. */

int FUN_4045dadc(int param_1,ushort *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int local_28 [2];
  
  if (param_2 == (ushort *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_4045c1b8(param_1,param_2,0,local_28);
    if (-1 < iVar1) {
      if ((local_28[0] == -1) ||
         (puVar4 = (uint *)(*(int *)(param_1 + 0xac) + local_28[0]),
         (*(byte *)((int)puVar4 + 9) & 8) == 0)) {
        iVar1 = -0x7ffd7fd5;
      }
      else {
        uVar6 = *puVar4;
        iVar5 = *(int *)(param_1 + 0x20) + uVar6;
        if (*(int *)(iVar5 + 0x5c) == 0) {
          if ((*(uint *)(iVar5 + 0x10) & 8) == 0) {
            iVar1 = FUN_4045a504((int *)(iVar5 + 4),param_1,0);
          }
          else {
            iVar1 = 0;
          }
          if (-1 < iVar1) {
            *(char *)(puVar4 + 2) = (char)puVar4[2];
            *(byte *)((int)puVar4 + 9) = *(byte *)((int)puVar4 + 9) & 0xf7;
            FUN_4045d830(param_1,local_28[0],(int *)puVar4);
            if (*(int *)(iVar5 + 0x2c) != -1) {
              *(undefined4 *)(*(int *)(param_1 + 0x84) + *(int *)(iVar5 + 0x2c) + 0x10) = 0xffffffff
              ;
            }
            FUN_4045b030(iVar5 + 4,param_1);
            uVar3 = *(ushort *)(iVar5 + 2) + 1;
            if (uVar3 < *(uint *)(param_1 + 0x154)) {
              iVar1 = uVar3 * 4;
              do {
                puVar2 = (undefined4 *)(*(int *)(param_1 + 0x18c) + iVar1);
                uVar3 = uVar3 + 1;
                puVar2[-1] = *puVar2;
                iVar5 = *(int *)(*(int *)(param_1 + 0x18c) + iVar1) + *(int *)(param_1 + 0x20);
                *(short *)(iVar5 + 2) = *(short *)(iVar5 + 2) + -1;
                iVar1 = iVar1 + 4;
              } while (uVar3 < *(uint *)(param_1 + 0x154));
            }
            FUN_4045a488(param_1 + 0x10,uVar6,0x60);
            *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + -1;
            iVar1 = 0;
          }
        }
        else {
          iVar1 = -0x7fffbffb;
        }
      }
    }
  }
  return iVar1;
}



/* 4045dcd0 FUN_4045dcd0 */

/* Boundary evidence: original MIPS .pdata 4045dcd0..4045ded7. Semantic name remains unreviewed. */

int FUN_4045dcd0(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  BSTR pOVar3;
  BSTR local_30;
  BSTR local_2c;
  
  local_30 = (BSTR)0x0;
  local_2c = (BSTR)0x0;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    iVar1 = FUN_4045da0c(param_1 + -4);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  if (param_2 == 0xffffffff) {
    if (((param_3 == (undefined4 *)0x0) ||
        (iVar2 = FUN_4045c2c4(param_1 + -4,*(int *)(param_1 + 0x168),&local_30), -1 < iVar2)) &&
       ((param_4 == (undefined4 *)0x0 ||
        (iVar2 = FUN_4045cb14(param_1 + -4,*(int *)(param_1 + 0x154),&local_2c), -1 < iVar2)))) {
      pOVar3 = local_2c;
      if (param_5 != (undefined4 *)0x0) {
        pOVar3 = *(BSTR *)(param_1 + 0x15c);
      }
LAB_4045de6c:
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = local_30;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_2c;
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = 0;
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = pOVar3;
      }
      return 0;
    }
  }
  else if (param_2 < *(uint *)(param_1 + 0x150)) {
    iVar1 = *(int *)(param_1 + 0x1c) + *(int *)(*(int *)(param_1 + 0x188) + param_2 * 4);
    if (((param_3 == (undefined4 *)0x0) ||
        (iVar2 = FUN_4045c2c4(param_1 + -4,*(int *)(iVar1 + 0x34),&local_30), -1 < iVar2)) &&
       ((param_4 == (undefined4 *)0x0 ||
        (iVar2 = FUN_4045cb14(param_1 + -4,*(int *)(iVar1 + 0x3c),&local_2c), -1 < iVar2)))) {
      pOVar3 = local_2c;
      if (param_5 != (undefined4 *)0x0) {
        pOVar3 = *(BSTR *)(iVar1 + 0x44);
      }
      goto LAB_4045de6c;
    }
  }
  else {
    iVar2 = -0x7ffd7fd5;
  }
  SysFreeString(local_30);
  SysFreeString(local_2c);
  SysFreeString((BSTR)0x0);
  return iVar2;
}



/* 4045df50 FUN_4045df50 */

/* Boundary evidence: original MIPS .pdata 4045df50..4045dffb. Semantic name remains unreviewed. */

undefined4 FUN_4045df50(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x1cc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = FUN_404589c4(0x2c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_40441ba8;
      puVar1[1] = &PTR_LAB_40441b14;
      puVar1[2] = &PTR_LAB_40441b00;
    }
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1cc) = puVar1[3];
    *puVar1 = &PTR_FUN_40441ba8;
    puVar1[1] = &PTR_LAB_40441b14;
    puVar1[2] = &PTR_LAB_40441b00;
  }
  *param_2 = puVar1;
  return 0;
}



/* 4045dffc FUN_4045dffc */

/* Boundary evidence: original MIPS .pdata 4045dffc..4045e203. Semantic name remains unreviewed. */

int FUN_4045dffc(int *param_1,wchar_t *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  ushort *puVar4;
  uint local_38;
  int local_34;
  int *local_30 [2];
  
  if ((param_2 == (wchar_t *)0x0) || (param_4 == (undefined4 *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    iVar1 = FUN_4045bfa0((int)param_1,param_2,&local_34);
    if (-1 < iVar1) {
      piVar3 = local_30[0];
      if ((local_34 == -1) ||
         (piVar3 = (int *)(param_1[0x2b] + local_34),
         (*(byte *)(param_1[0x2b] + local_34 + 9) & 8) == 0)) {
        if (param_1[0x55] == param_1[0x6c]) {
          pvVar2 = FUN_40458a64((LPVOID)param_1[99],(param_1[0x6c] + 0x10) * 4);
          if (pvVar2 == (LPVOID)0x0) {
            return -0x7ff8fff2;
          }
          param_1[99] = (int)pvVar2;
          param_1[0x6c] = param_1[0x6c] + 0x10;
        }
        iVar1 = FUN_4045a374((int)(param_1 + 4),(int *)&local_38,0x60);
        if (-1 < iVar1) {
          puVar4 = (ushort *)(param_1[8] + local_38);
          iVar1 = FUN_4045df50((int)param_1,local_30);
          if (iVar1 < 0) {
            FUN_4045a488((int)(param_1 + 4),local_38,0x60);
          }
          else {
            FUN_4045d238(puVar4,param_3,*(ushort *)(param_1 + 0x52) & 3);
            *(uint *)(param_1[0x55] * 4 + param_1[99]) = local_38;
            puVar4[1] = (ushort)param_1[0x55];
            FUN_40460810((int)local_30[0],param_1,local_38,param_3);
            *(int **)(puVar4 + 0x2e) = local_30[0];
            if (local_34 != -1) {
              FUN_40460998((int)local_30[0],(int)puVar4,local_34,piVar3);
            }
            param_1[0x55] = param_1[0x55] + 1;
            *param_4 = local_30[0];
            iVar1 = 0;
          }
        }
      }
      else {
        iVar1 = -0x7ffd7fd3;
      }
    }
  }
  return iVar1;
}



/* 4045e204 FUN_4045e204 */

/* Boundary evidence: original MIPS .pdata 4045e204..4045e2f7. Semantic name remains unreviewed. */

int FUN_4045e204(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  ushort *puVar3;
  int *local_28 [2];
  
  puVar3 = (ushort *)(param_1[8] + param_2);
  piVar2 = *(int **)(puVar3 + 0x2e);
  local_28[0] = piVar2;
  if (piVar2 == (int *)0x0) {
    iVar1 = FUN_4045df50((int)param_1,local_28);
    piVar2 = local_28[0];
    if (iVar1 < 0) {
      return iVar1;
    }
    FUN_40460810((int)local_28[0],param_1,param_2,*puVar3 & 0xf);
    *(int **)(puVar3 + 0x2e) = piVar2;
    if (((*(uint *)(puVar3 + 0x18) & 0x40) != 0) &&
       (iVar1 = FUN_40460888((int)piVar2,puVar3), iVar1 < 0)) {
      (**(code **)(*piVar2 + 8))(piVar2);
      return iVar1;
    }
  }
  else {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  *param_3 = piVar2;
  return 0;
}



/* 4045e2f8 FUN_4045e2f8 */

/* Boundary evidence: original MIPS .pdata 4045e2f8..4045e4ff. Semantic name remains unreviewed. */

int FUN_4045e2f8(int param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int *local_38;
  int local_34;
  int *local_30;
  undefined4 uStack_2c;
  
  piVar4 = (int *)0x0;
  local_38 = (int *)0x0;
  if ((param_2 == (ushort *)0x0) || (param_4 == (undefined4 *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    piVar5 = (int *)(param_1 + -4);
    iVar1 = FUN_4045da0c((int)piVar5);
    if ((-1 < iVar1) && (iVar1 = FUN_4045c1b8((int)piVar5,param_2,param_3,&local_34), -1 < iVar1)) {
      uVar7 = 0;
      if ((local_34 == -1) ||
         (local_30 = (int *)(*(int *)(param_1 + 0xa8) + local_34), *local_30 == -1)) {
        uVar6 = 0;
        if (*(int *)(param_1 + 0x150) != 0) {
          iVar1 = 0;
          do {
            iVar2 = *(int *)(iVar1 + *(int *)(param_1 + 0x188));
            puVar3 = (ushort *)(iVar2 + *(int *)(param_1 + 0x1c));
            if (((*puVar3 & 0xf) == 5) && ((*(uint *)(puVar3 + 0x18) & 1) != 0)) {
              iVar2 = FUN_4045e204(piVar5,iVar2,&local_38);
              piVar4 = local_38;
              if (iVar2 < 0) {
                return iVar2;
              }
              iVar2 = FUN_40467294(local_38,param_2,local_34,param_3,1,&local_30,&uStack_2c);
              if (iVar2 < 0) goto LAB_4045e4a4;
              if (local_30 != (int *)0x0) goto LAB_4045e478;
              (**(code **)(*piVar4 + 8))(piVar4);
              local_38 = (int *)0x0;
            }
            uVar6 = uVar6 + 1;
            iVar1 = iVar1 + 4;
          } while (uVar6 < *(uint *)(param_1 + 0x150));
        }
      }
      else {
LAB_4045e478:
        uVar7 = 1;
        memcpy(param_2,local_30 + 3,
               (uint)*(byte *)(local_30 + 2) | (*(byte *)((int)local_30 + 9) & 3) << 8);
LAB_4045e4a4:
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 8))(piVar4);
        }
      }
      *param_4 = uVar7;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4045e500 FUN_4045e500 */

/* Boundary evidence: original MIPS .pdata 4045e500..4045e7e3. Semantic name remains unreviewed. */

int FUN_4045e500(int *param_1,ushort *param_2,int param_3,uint param_4,int *param_5,
                undefined4 *param_6,ushort *param_7)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *local_50;
  int local_4c;
  int local_48;
  uint local_44;
  int local_40;
  ushort *local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  
  local_34 = (uint)*param_7;
  uVar6 = 0;
  local_44 = 0;
  if (local_34 != 0) {
    local_40 = 0;
    iVar7 = (int)param_5 - (int)param_6;
    local_4c = param_3;
    local_48 = iVar7;
    local_3c = param_2;
    local_30 = param_4;
    do {
      uVar5 = local_30;
      if ((uint)param_1[0x55] <= local_44) break;
      iVar8 = *(int *)(param_1[99] + local_40);
      puVar4 = (ushort *)(param_1[8] + iVar8);
      if (((*puVar4 & 0x10) == 0) || ((*(uint *)(puVar4 + 0x18) & 0x40) != 0)) {
        if ((*(uint *)(puVar4 + 8) & 8) == 0) {
          iVar1 = FUN_4045a504((int *)(puVar4 + 2),(int)param_1,0);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < 0) goto joined_r0x4045e764;
        uVar5 = 0;
        if ((uint)puVar4[0xd] + (uint)puVar4[0xc] != 0) {
          piVar3 = *(int **)(puVar4 + 0x12);
          do {
            if (*piVar3 == local_4c) goto LAB_4045e6bc;
            uVar5 = uVar5 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar5 < (uint)puVar4[0xd] + (uint)puVar4[0xc]);
        }
        uVar5 = 0xffffffff;
LAB_4045e6bc:
        iVar7 = local_48;
        if (uVar5 != 0xffffffff) {
          iVar1 = FUN_4045e204(param_1,iVar8,&local_50);
          if (iVar1 < 0) goto joined_r0x4045e764;
          *param_6 = *(undefined4 *)(*(int *)(puVar4 + 0x10) + uVar5 * 4);
          piVar3 = local_50;
          iVar7 = local_48;
LAB_4045e6fc:
          piVar2 = piVar3 + 1;
          if (piVar3 == (int *)0x0) {
            piVar2 = (int *)0x0;
          }
          *(int **)(iVar7 + (int)param_6) = piVar2;
          param_6 = param_6 + 1;
          uVar6 = uVar6 + 1;
        }
      }
      else {
        iVar1 = FUN_4045e204(param_1,iVar8,&local_50);
        piVar3 = local_50;
        if (iVar1 < 0) goto joined_r0x4045e764;
        iVar1 = FUN_40467294(local_50,local_3c,local_4c,uVar5,0,&local_38,param_6);
        if (iVar1 < 0) {
          (**(code **)(*piVar3 + 8))(piVar3);
joined_r0x4045e764:
          for (; uVar6 != 0; uVar6 = uVar6 - 1) {
            if ((int *)*param_5 != (int *)0x0) {
              (**(code **)(*(int *)*param_5 + 8))();
              *param_5 = 0;
            }
            param_5 = param_5 + 1;
          }
          return iVar1;
        }
        if (local_38 != 0) goto LAB_4045e6fc;
        (**(code **)(*piVar3 + 8))(piVar3);
      }
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
    } while (uVar6 < local_34);
  }
  *param_7 = (ushort)uVar6;
  return 0;
}



/* 4045e7e4 FUN_4045e7e4 */

/* Boundary evidence: original MIPS .pdata 4045e7e4..4045ead7. Semantic name remains unreviewed. */

int FUN_4045e7e4(int param_1,ushort *param_2,uint param_3,int *param_4,undefined4 *param_5,
                ushort *param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  ushort *puVar5;
  ushort *_Dst;
  int *piVar6;
  int *piVar7;
  int local_38;
  ushort *local_34;
  int local_30 [2];
  
  if ((((param_2 == (ushort *)0x0) || (param_4 == (int *)0x0)) || (param_5 == (undefined4 *)0x0)) ||
     (param_6 == (ushort *)0x0)) {
    return -0x7ff8ffa9;
  }
  uVar1 = *param_6;
  if (uVar1 == 0) {
    return 0;
  }
  piVar7 = (int *)(param_1 + -4);
  local_34 = param_2;
  iVar2 = FUN_4045da0c((int)piVar7);
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_4045c1b8((int)piVar7,param_2,param_3,&local_38);
  _Dst = local_34;
  if (iVar2 < 0) {
    return iVar2;
  }
  if (local_38 == -1) {
LAB_4045ea94:
    *param_6 = 0;
    return 0;
  }
  piVar6 = (int *)(*(int *)(param_1 + 0xa8) + local_38);
  local_30[0] = *piVar6;
  if ((local_30[0] == -2) || (local_30[0] == -1)) goto LAB_4045ea94;
  puVar5 = (ushort *)(*(int *)(param_1 + 0x1c) + local_30[0]);
  if ((uVar1 == 1) || ((*(byte *)((int)piVar6 + 9) & 0x10) != 0)) {
    if ((*(byte *)((int)piVar6 + 9) & 8) == 0) {
      if ((uVar1 != 1) && ((*puVar5 & 0xf) == 3)) goto LAB_4045e948;
      if ((*(uint *)(puVar5 + 8) & 8) == 0) {
        iVar2 = FUN_4045a504((int *)(puVar5 + 2),(int)piVar7,0);
      }
      else {
        iVar2 = 0;
      }
      if (iVar2 < 0) {
        return iVar2;
      }
      uVar3 = 0;
      if ((uint)puVar5[0xd] + (uint)puVar5[0xc] != 0) {
        piVar4 = *(int **)(puVar5 + 0x12);
        do {
          if (*piVar4 == local_38) goto LAB_4045ea0c;
          uVar3 = uVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar3 < (uint)puVar5[0xd] + (uint)puVar5[0xc]);
      }
      uVar3 = 0xffffffff;
LAB_4045ea0c:
      *param_5 = *(undefined4 *)(*(int *)(puVar5 + 0x10) + uVar3 * 4);
    }
    else {
      *param_5 = 0xffffffff;
    }
    iVar2 = FUN_4045e204(piVar7,local_30[0],local_30);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_30[0] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = local_30[0] + 4;
    }
    *param_4 = iVar2;
    *param_6 = 1;
    _Dst = local_34;
  }
  else {
LAB_4045e948:
    iVar2 = FUN_4045e500(piVar7,local_34,local_38,param_3,param_4,param_5,param_6);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*param_4 == 0) {
      return 0;
    }
  }
  memcpy(_Dst,piVar6 + 3,(uint)*(byte *)(piVar6 + 2) | (*(byte *)((int)piVar6 + 9) & 3) << 8);
  return 0;
}



/* 4045ead8 FUN_4045ead8 */

/* Boundary evidence: original MIPS .pdata 4045ead8..4045f10b. Semantic name remains unreviewed. */

int FUN_4045ead8(int param_1,ushort *param_2,uint param_3,uint param_4,int *param_5,int *param_6,
                int *param_7)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  ushort uVar8;
  ushort *puVar9;
  int *piVar10;
  ushort uVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int *local_64;
  int local_60;
  int local_5c;
  int *local_58;
  uint local_54;
  int local_50;
  int local_4c;
  ushort *local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  piVar10 = (int *)0x0;
  local_64 = (int *)0x0;
  local_58 = (int *)0x0;
  piVar12 = (int *)0x0;
  local_60 = 0;
  if ((((param_2 == (ushort *)0x0) || (param_5 == (int *)0x0)) || (param_6 == (int *)0x0)) ||
     (param_7 == (int *)0x0)) {
    return -0x7ff8ffa9;
  }
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  if ((param_4 & 0xfffffff0) != 0) {
    return -0x7ff8ffa9;
  }
  piVar13 = (int *)(param_1 + -8);
  local_5c = param_1;
  local_54 = param_3;
  local_48 = param_2;
  iVar4 = FUN_4045da0c((int)piVar13);
  if (iVar4 < 0) {
    return iVar4;
  }
  iVar4 = FUN_4045c1b8((int)piVar13,param_2,local_54,&local_50);
  if (iVar4 < 0) {
    return iVar4;
  }
  if (local_50 == -1) {
LAB_4045ebf8:
    local_60 = 1;
  }
  else {
    piVar7 = (int *)(*(int *)(param_1 + 0xa4) + local_50);
    iVar5 = *piVar7;
    if (iVar5 != -2) {
      if (iVar5 == -1) goto LAB_4045ebf8;
      puVar9 = (ushort *)(*(int *)(param_1 + 0x18) + iVar5);
      uVar11 = *puVar9 & 0xf;
      if ((uVar11 == 2) || (bVar2 = false, (*puVar9 & 0xf) == 0)) {
        bVar2 = true;
      }
      bVar1 = *(byte *)((int)piVar7 + 9);
      param_1 = local_5c;
      if ((bVar1 & 8) == 0) {
        if ((bVar1 & 0x10) != 0) {
          if (bVar2) {
            iVar4 = FUN_4045e204(piVar13,iVar5,&local_64);
            piVar10 = local_64;
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar4 = FUN_40466ee4(local_64,local_48,local_50,local_54,(ushort)param_4,0,param_5,
                                 param_6,param_7);
            goto LAB_4045f070;
          }
          if ((uVar11 != 3) && (uVar11 != 4)) {
            return 0;
          }
          local_60 = 1;
        }
      }
      else {
        if ((bVar2) || ((uVar11 == 5 && ((*(uint *)(puVar9 + 0x18) & 1) != 0)))) {
          iVar4 = FUN_4045e204(piVar13,iVar5,&local_64);
          piVar10 = local_64;
          if (iVar4 < 0) {
            return iVar4;
          }
          if ((uVar11 == 5) && ((*(uint *)(puVar9 + 0x18) & 9) != 0)) {
            iVar4 = FUN_4046111c((int)local_64,&local_4c);
            if (iVar4 < 0) goto LAB_4045f070;
            *param_6 = 2;
            piVar12 = piVar10 + 1;
            *param_7 = local_4c;
            if (piVar10 == (int *)0x0) {
              piVar12 = (int *)0x0;
            }
            *param_5 = (int)piVar12;
          }
          else {
            *param_6 = 3;
            if (local_64 == (int *)0x0) {
              local_64 = (int *)0x0;
            }
            else {
              local_64 = local_64 + 2;
            }
            *param_7 = (int)local_64;
          }
          return 0;
        }
        if ((bVar1 & 0x10) != 0) {
          return 0;
        }
      }
    }
  }
  bVar2 = false;
  local_44 = 0;
  if (*(int *)(param_1 + 0x14c) != 0) {
    local_40 = 0;
    local_3c = local_2c;
    local_38 = local_30;
    local_34 = local_2c;
    iVar5 = local_60;
    do {
      iVar6 = *(int *)(local_40 + *(int *)(param_1 + 0x184));
      puVar9 = (ushort *)(*(int *)(param_1 + 0x18) + iVar6);
      uVar11 = *puVar9;
      uVar8 = uVar11 & 0xf;
      if ((uVar8 == 5) && ((*(uint *)(puVar9 + 0x18) & 1) != 0)) {
        iVar14 = 1;
LAB_4045ee38:
        bVar3 = true;
      }
      else {
        iVar14 = 0;
        if ((uVar8 == 2) || (bVar3 = false, (uVar11 & 0xf) == 0)) goto LAB_4045ee38;
      }
      if (iVar5 == 0) {
        if (bVar3) goto LAB_4045ee5c;
      }
      else if (iVar14 != 0) {
LAB_4045ee5c:
        iVar4 = FUN_4045e204((int *)(param_1 + -8),iVar6,&local_64);
        piVar10 = local_64;
        piVar13 = local_58;
        if (iVar4 < 0) goto LAB_4045f028;
        *param_5 = 0;
        *param_6 = 0;
        *param_7 = 0;
        iVar4 = FUN_40466ee4(local_64,local_48,local_50,local_54,(ushort)param_4,0,param_5,param_6,
                             param_7);
        piVar13 = local_58;
        if (iVar4 < 0) goto LAB_4045f028;
        iVar5 = *param_6;
        if ((bVar2) && (iVar5 != 0)) {
          iVar4 = -0x7ffd7fd4;
          goto LAB_4045f028;
        }
        if (iVar5 != 0) {
          local_38 = *param_7;
          local_58 = (int *)*param_5;
          local_3c = iVar5;
          local_34 = iVar14;
          local_30 = local_38;
          local_2c = iVar5;
          if (iVar14 != 0) {
            (**(code **)(*piVar10 + 4))(piVar10);
            piVar12 = piVar10;
          }
          bVar2 = true;
        }
        iVar5 = local_60;
        param_1 = local_5c;
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 8))(piVar10);
          piVar10 = (int *)0x0;
          local_64 = (int *)0x0;
          iVar5 = local_60;
          param_1 = local_5c;
        }
      }
      piVar13 = local_58;
      local_44 = local_44 + 1;
      local_40 = local_40 + 4;
    } while (local_44 < *(uint *)(param_1 + 0x14c));
    if (bVar2) {
      *param_5 = (int)local_58;
      *param_6 = local_3c;
      bVar2 = false;
      *param_7 = local_38;
      if (local_34 != 0) {
        FUN_4045d1a0((int *)*param_5,param_6,param_7);
        if ((int *)*param_5 != (int *)0x0) {
          (**(code **)(*(int *)*param_5 + 8))();
          *param_5 = 0;
        }
        piVar7 = piVar12 + 1;
        if (piVar12 == (int *)0x0) {
          piVar7 = (int *)0x0;
        }
        *param_5 = (int)piVar7;
        *param_6 = 4;
        *param_7 = 0;
        iVar4 = FUN_4046111c((int)piVar12,&local_4c);
        if (-1 < iVar4) {
          *param_7 = local_4c;
LAB_4045f028:
          if (bVar2) {
            FUN_4045d1a0(piVar13,&local_2c,&local_30);
            if (piVar13 != (int *)0x0) {
              (**(code **)(*piVar13 + 8))(piVar13);
            }
            if (piVar12 != (int *)0x0) {
              (**(code **)(*piVar12 + 8))(piVar12);
            }
          }
        }
      }
    }
  }
LAB_4045f070:
  if (iVar4 != 0) {
    if ((int *)*param_5 != (int *)0x0) {
      FUN_4045d1a0((int *)*param_5,param_6,param_7);
      (**(code **)(*(int *)*param_5 + 8))();
      *param_5 = 0;
    }
    *param_6 = 0;
    *param_7 = 0;
  }
  if (piVar10 != (int *)0x0) {
    (**(code **)(*piVar10 + 8))(piVar10);
    return iVar4;
  }
  return iVar4;
}



/* 4045f10c FUN_4045f10c */

/* Boundary evidence: original MIPS .pdata 4045f10c..4045f23b. Semantic name remains unreviewed. */

int FUN_4045f10c(int param_1,ushort *param_2,uint param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  
  local_20 = 0;
  if (((param_2 == (ushort *)0x0) || (param_4 == (int *)0x0)) || (param_5 == (undefined4 *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    piVar4 = (int *)(param_1 + -8);
    *param_4 = 0;
    *param_5 = 0;
    iVar1 = FUN_4045da0c((int)piVar4);
    if ((-1 < iVar1) && (iVar1 = FUN_4045c1b8((int)piVar4,param_2,param_3,&local_1c), -1 < iVar1)) {
      if (local_1c != -1) {
        piVar3 = (int *)(*(int *)(param_1 + 0xa4) + local_1c);
        iVar2 = *piVar3;
        if (iVar2 != -1) {
          if ((*(byte *)((int)piVar3 + 9) & 8) == 0) {
            return iVar1;
          }
          iVar1 = FUN_4045e204(piVar4,iVar2,&local_20);
          if (iVar1 < 0) {
            return iVar1;
          }
          if (local_20 == 0) {
            local_20 = 0;
          }
          else {
            local_20 = local_20 + 4;
          }
          *param_4 = local_20;
          return iVar1;
        }
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4045f23c FUN_4045f23c */

/* Boundary evidence: original MIPS .pdata 4045f23c..4045f2cf. Semantic name remains unreviewed. */

int FUN_4045f23c(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int local_10 [2];
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    if (param_2 < *(uint *)(param_1 + 0x150)) {
      iVar1 = FUN_4045e204((int *)(param_1 + -4),*(int *)(*(int *)(param_1 + 0x188) + param_2 * 4),
                           local_10);
      if (-1 < iVar1) {
        if (local_10[0] == 0) {
          local_10[0] = 0;
        }
        else {
          local_10[0] = local_10[0] + 4;
        }
        *param_3 = local_10[0];
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 4045f2d0 FUN_4045f2d0 */

/* Boundary evidence: original MIPS .pdata 4045f2d0..4045f397. Semantic name remains unreviewed. */

int FUN_4045f2d0(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int local_18;
  int local_14;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_4045c3e4(param_1 + -4,param_2,&local_18);
    if (-1 < iVar1) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x80) + local_18 + 0x10);
      if ((uVar2 == 0xfffffffe) || ((uVar2 & 1) != 0)) {
        iVar1 = -0x7ffd7fd5;
      }
      else {
        iVar1 = FUN_4045e204((int *)(param_1 + -4),uVar2,&local_14);
        if (-1 < iVar1) {
          if (local_14 == 0) {
            local_14 = 0;
          }
          else {
            local_14 = local_14 + 4;
          }
          *param_3 = local_14;
        }
      }
    }
  }
  return iVar1;
}



/* 4045f398 FUN_4045f398 */

/* Boundary evidence: original MIPS .pdata 4045f398..4045f433. Semantic name remains unreviewed. */

void FUN_4045f398(int *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) {
    if (param_1[1] != 0) {
      iVar3 = iVar2 << 5;
      do {
        iVar3 = iVar3 + -0x20;
        iVar2 = iVar2 + -1;
        VariantClear((VARIANTARG *)(iVar3 + param_1[1] + 0x10));
      } while (iVar2 != 0);
      pvVar1 = TlsGetValue(DAT_4046d1b0);
      FUN_40457ba4((int)pvVar1,(LPVOID)param_1[1]);
      param_1[1] = 0;
    }
    *param_1 = 0;
  }
  return;
}



/* 4045f434 FUN_4045f434 */

/* Boundary evidence: original MIPS .pdata 4045f434..4045f82b. Semantic name remains unreviewed. */

int FUN_4045f434(int param_1,uint *param_2,uint *param_3,short *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  size_t _Size;
  uint local_38;
  uint local_34;
  int *local_30;
  int *local_2c;
  uint local_28 [2];
  
  uVar8 = param_2[1];
  uVar7 = (uint)(ushort)uVar8;
  if (uVar7 < 0x1a) {
LAB_4045f738:
    uVar8 = uVar7;
    if (((0xe < uVar7) && (uVar7 != 0x19)) && ((uVar7 < 0x10 || (0x15 < uVar7)))) {
      if (uVar7 == 0x16) {
        uVar8 = 3;
      }
      else if (uVar7 == 0x17) {
        uVar8 = 0x13;
      }
      else if (uVar7 == 0x18) {
        uVar8 = 0;
      }
      else {
        if ((uVar7 < 0x1e) || (0x1f < uVar7)) {
          return -0x7ffdfff8;
        }
        uVar8 = 0x7ffe;
      }
    }
    *param_3 = local_34 & 0x80000000 | uVar7 | (uVar8 & 0x7fff) << 0x10 | 0x80000000;
  }
  else {
    if (uVar7 < 0x1c) {
      *param_4 = *param_4 + 8;
      iVar1 = FUN_4045f434(param_1,(uint *)*param_2,&local_38,param_4);
      if (iVar1 < 0) {
        return iVar1;
      }
      if ((local_38 & 0x80000000) == 0) {
        uVar3 = (uint)*(ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0xd4) + local_38 + 2);
      }
      else {
        uVar3 = local_38 >> 0x10 & 0x7fff;
      }
      uVar5 = uVar3;
      if (((uVar3 != 0x7ffe) && (uVar3 != 0x7fff)) && (uVar5 = 0x7ffe, (uVar3 & 0x4000) == 0)) {
        if (uVar7 == 0x1a) {
          uVar5 = uVar3 | 0x4000;
        }
        else if ((uVar3 & 0x2000) == 0) {
          uVar5 = uVar3 | 0x2000;
        }
      }
    }
    else if (uVar7 == 0x1c) {
      puVar9 = (uint *)*param_2;
      _Size = (uint)(ushort)puVar9[2] * 8;
      iVar1 = FUN_4045a374(*(int *)(param_1 + 0x10) + 0xd8,(int *)&local_38,_Size + 8);
      if (iVar1 < 0) {
        return iVar1;
      }
      *param_4 = *param_4 + (short)_Size + 0xc;
      iVar1 = FUN_4045f434(param_1,puVar9,local_28,param_4);
      if (iVar1 < 0) {
        return iVar1;
      }
      puVar6 = (uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0xe8) + local_38);
      *puVar6 = local_28[0];
      *(short *)(puVar6 + 1) = (short)puVar9[2];
      memcpy(puVar6 + 2,puVar9 + 3,_Size);
      *(short *)((int)puVar6 + 6) = (short)_Size;
      uVar5 = 0x7ffe;
    }
    else {
      if (uVar7 != 0x1d) goto LAB_4045f738;
      local_38 = *param_2;
      iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x38))((int *)(param_1 + 4),local_38,&local_30);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar5 = 0x7fff;
      iVar1 = (**(code **)*local_30)(local_30,&DAT_40441cfc,&local_2c);
      if (iVar1 == 0) {
        if (local_2c[5] == 0) {
          uVar5 = 3;
        }
        (**(code **)(*local_2c + 8))();
      }
      (**(code **)(*local_30 + 8))();
    }
    iVar1 = *(int *)(param_1 + 0x10);
    iVar2 = *(int *)(iVar1 + 0xcc);
    puVar4 = *(ushort **)(iVar1 + 0xd4);
    if (iVar2 == -1) {
      iVar2 = *(int *)(iVar1 + 200);
    }
    for (; (puVar4 = (ushort *)((int)puVar4 + 3U & 0xfffffffc),
           puVar4 < (ushort *)(*(int *)(iVar1 + 0xd4) + iVar2) && (puVar4 != (ushort *)0x0));
        puVar4 = puVar4 + 4) {
      if ((*puVar4 == uVar7) && ((puVar4[1] == uVar5 && (*(uint *)(puVar4 + 2) == local_38)))) {
        local_34 = (int)puVar4 - *(int *)(*(int *)(param_1 + 0x10) + 0xd4);
        goto LAB_4045f730;
      }
    }
    iVar1 = FUN_4045a374(*(int *)(param_1 + 0x10) + 0xc4,(int *)&local_34,8);
    if (iVar1 < 0) {
      return iVar1;
    }
    puVar4 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0xd4) + local_34);
    *puVar4 = (ushort)uVar8;
    puVar4[1] = (ushort)uVar5;
    *(uint *)(puVar4 + 2) = local_38;
LAB_4045f730:
    *param_3 = local_34;
  }
  return 0;
}



/* 4045f82c FUN_4045f82c */

/* Boundary evidence: original MIPS .pdata 4045f82c..4045fb5f. Semantic name remains unreviewed. */

int FUN_4045f82c(int param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  size_t _Size;
  uint *_Src;
  ushort *puVar8;
  uint uVar9;
  uint local_38 [3];
  uint *local_2c;
  
  uVar1 = *param_2;
  uVar9 = (uint)uVar1;
  iVar7 = 0;
  switch(uVar9) {
  case 2:
  case 0xb:
  case 0x12:
    local_38[0] = (param_2[4] ^ local_38[0]) & 0x3ffffff ^ local_38[0];
    goto LAB_4045f954;
  case 5:
  case 6:
  case 7:
  case 0x14:
  case 0x15:
    _Size = 8;
    _Src = (uint *)(param_2 + 4);
    break;
  case 8:
    if (*(int *)(param_2 + 4) == 0) {
      _Size = 4;
      local_38[1] = 0xffffffff;
      _Src = local_38 + 1;
    }
    else {
      _Src = (uint *)(*(int *)(param_2 + 4) + -4);
      _Size = *_Src + 4;
    }
    break;
  case 9:
  case 0xd:
    if (*(int *)(param_2 + 4) != 0) {
      return -0x7ffdfffb;
    }
  case 3:
  case 4:
  case 10:
  case 0x13:
  case 0x16:
  case 0x17:
    _Src = (uint *)(param_2 + 4);
    local_38[0] = (*_Src ^ local_38[0]) & 0x3ffffff ^ local_38[0];
    if ((local_38[0] & 0x3ffffff) == *_Src) {
LAB_4045f954:
      *param_3 = (uVar9 << 0x1a ^ (local_38[0] | 0x80000000)) & 0x7c000000 ^
                 (local_38[0] | 0x80000000);
      return 0;
    }
    _Size = 4;
    break;
  default:
LAB_4045fb2c:
    return -0x7ffdfff8;
  case 0xe:
    _Size = 0xe;
    _Src = (uint *)(param_2 + 1);
    break;
  case 0x10:
  case 0x11:
    local_38[0] = ((byte)param_2[4] ^ local_38[0]) & 0x3ffffff ^ local_38[0];
    goto LAB_4045f954;
  }
  puVar8 = *(ushort **)(param_1 + 0xfc);
  iVar5 = *(int *)(param_1 + 0xf4);
  if (iVar5 == -1) {
    iVar5 = *(int *)(param_1 + 0xf0);
  }
  iVar4 = *(int *)(param_1 + 0xfc);
  puVar6 = puVar8;
  local_38[2] = param_1;
  local_2c = param_3;
  do {
    puVar6 = (ushort *)((int)puVar6 + 3U & 0xfffffffc);
    if (((ushort *)(iVar4 + iVar5) <= puVar6) || (puVar6 == (ushort *)0x0)) {
      iVar7 = FUN_4045a374(param_1 + 0xec,(int *)local_38,_Size + 2);
      if (iVar7 < 0) {
        return iVar7;
      }
      puVar8 = (ushort *)(local_38[0] + *(int *)(local_38[2] + 0xfc));
      *puVar8 = uVar1;
      memcpy(puVar8 + 1,_Src,_Size);
LAB_4045fb18:
      *local_2c = local_38[0];
      return iVar7;
    }
    uVar2 = *puVar6;
    if ((uVar2 == uVar9) && (iVar3 = memcmp(puVar6 + 1,_Src,_Size), iVar3 == 0)) {
      local_38[0] = (int)puVar6 - (int)puVar8;
      goto LAB_4045fb18;
    }
    switch((uint)uVar2) {
    case 3:
    case 4:
    case 10:
    case 0x13:
    case 0x16:
    case 0x17:
      puVar6 = puVar6 + 3;
      break;
    case 5:
    case 6:
    case 7:
    case 0x14:
    case 0x15:
      puVar6 = puVar6 + 5;
      break;
    case 8:
      iVar3 = *(int *)(puVar6 + 1);
      if (iVar3 == -1) {
        iVar3 = 0;
      }
      puVar6 = (ushort *)((int)puVar6 + iVar3 + 6);
      break;
    default:
      goto LAB_4045fb2c;
    case 0xe:
      puVar6 = puVar6 + 8;
    }
  } while( true );
}



/* 4045fb60 FUN_4045fb60 */

/* Boundary evidence: original MIPS .pdata 4045fb60..4045fc8b. Semantic name remains unreviewed. */

int FUN_4045fb60(int param_1,uint *param_2,ushort *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_28;
  uint local_24;
  
  if (param_3 == (ushort *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_4045f82c(param_1,param_3,&local_24);
    if (-1 < iVar1) {
      local_28 = *param_4;
      if (local_28 != -1) {
        iVar1 = *(int *)(param_1 + 0x110);
        iVar4 = *(int *)(param_1 + 0x84);
        do {
          piVar3 = (int *)(iVar1 + local_28);
          iVar2 = memcmp(param_2,(void *)(iVar4 + *piVar3),0x10);
          if (iVar2 == 0) goto LAB_4045fc58;
          local_28 = piVar3[2];
        } while (local_28 != -1);
      }
      iVar1 = FUN_4045a374(param_1 + 0x100,&local_28,0xc);
      if (-1 < iVar1) {
        piVar3 = (int *)(*(int *)(param_1 + 0x110) + local_28);
        iVar1 = FUN_4045c4d8(param_1,param_2,0xffffffff,piVar3);
        if (-1 < iVar1) {
          piVar3[2] = *param_4;
          *param_4 = local_28;
LAB_4045fc58:
          iVar1 = 0;
          piVar3[1] = local_24;
        }
      }
    }
  }
  return iVar1;
}



/* 4045fc8c FUN_4045fc8c */

/* Boundary evidence: original MIPS .pdata 4045fc8c..4045fce7. Semantic name remains unreviewed. */

int FUN_4045fc8c(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0xd0) & 8) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0xc4),param_1);
    if (-1 < iVar1) {
      iVar1 = FUN_4045a028((int *)(param_1 + 0xd8),param_1);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4045fce8 FUN_4045fce8 */

/* Boundary evidence: original MIPS .pdata 4045fce8..4045fe63. Semantic name remains unreviewed. */

int FUN_4045fce8(int param_1,uint param_2,uint *param_3,int param_4,uint *param_5)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  if ((param_2 & 0x80000000) == 0) {
    iVar2 = FUN_4045fc8c(param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    puVar3 = (ushort *)(*(int *)(param_1 + 0xd4) + param_2);
    uVar1 = *puVar3;
    *(ushort *)(param_3 + 1) = uVar1;
    if (0x19 < uVar1) {
      if (uVar1 < 0x1c) {
        *param_3 = *param_5;
        *param_5 = *param_5 + 8;
        iVar2 = FUN_4045fce8(param_1,*(uint *)(puVar3 + 2),(uint *)*param_3,param_4,param_5);
      }
      else {
        if (uVar1 != 0x1c) {
          if (uVar1 != 0x1d) {
            return 0;
          }
          *param_3 = *(uint *)(puVar3 + 2) | param_4 << 0x18;
          return 0;
        }
        puVar5 = (uint *)(*(int *)(param_1 + 0xe8) + *(int *)(puVar3 + 2));
        puVar4 = (uint *)*param_5;
        *param_5 = (int)puVar4 + *(ushort *)((int)puVar5 + 6) + 0xc;
        *param_3 = (uint)puVar4;
        *(short *)(puVar4 + 2) = (short)puVar5[1];
        memcpy(puVar4 + 3,puVar5 + 2,(uint)*(ushort *)((int)puVar5 + 6));
        iVar2 = FUN_4045fce8(param_1,*puVar5,puVar4,param_4,param_5);
      }
      if (iVar2 < 0) {
        return iVar2;
      }
    }
  }
  else {
    *(short *)(param_3 + 1) = (short)param_2;
    *param_3 = 0;
  }
  return 0;
}



/* 4045fe64 FUN_4045fe64 */

/* Boundary evidence: original MIPS .pdata 4045fe64..4045ffc3. Semantic name remains unreviewed. */

int FUN_4045fe64(int param_1,uint param_2,short *param_3,undefined4 *param_4,ushort *param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 *local_238 [2];
  uint auStack_230 [2];
  undefined1 auStack_228 [512];
  uint local_28;
  
  local_28 = DAT_4046d1b8;
  if ((param_2 & 0x80000000) != 0) {
    uVar2 = param_2 >> 0x10 & 0x7fff;
LAB_4045feb8:
    if (uVar2 != 0x7ffe) {
      *param_5 = (ushort)uVar2;
      *param_3 = 0;
      FUN_4046ace8(local_28);
      return 0;
    }
    FUN_4046ace8(local_28);
    return -0x7ffdfff8;
  }
  iVar1 = FUN_4045fc8c(*(int *)(param_1 + 0x10));
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_1 + 0x10);
    uVar2 = (uint)*(ushort *)(*(int *)(iVar1 + 0xd4) + param_2 + 2);
    if (uVar2 != 0x7fff) goto LAB_4045feb8;
    local_238[0] = auStack_228;
    iVar1 = FUN_4045fce8(iVar1,param_2,auStack_230,
                         *(ushort *)(*(int *)(iVar1 + 0x20) + *(int *)(param_1 + 0xc) + 0x58) + 1,
                         (uint *)local_238);
    if (-1 < iVar1) {
      iVar1 = FUN_40469828((int *)(param_1 + 4),auStack_230,param_3,param_4,param_5);
      FUN_4046ace8(local_28);
      if (-1 < iVar1) {
        return 0;
      }
      return iVar1;
    }
  }
  FUN_4046ace8(local_28);
  return iVar1;
}



/* 4045ffc4 FUN_4045ffc4 */

/* Boundary evidence: original MIPS .pdata 4045ffc4..40460227. Semantic name remains unreviewed. */

int FUN_4045ffc4(int param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  
  local_28 = (int *)0x0;
  if ((param_2 & 0x80000000) == 0) {
    iVar7 = FUN_4045fc8c(*(int *)(param_1 + 0x10));
    if (-1 < iVar7) {
      puVar5 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0xd4) + param_2);
      uVar2 = *puVar5;
      if (0x19 < uVar2) {
        if (uVar2 < 0x1c) {
          *param_3 = 4;
          *param_4 = 4;
        }
        else if (uVar2 == 0x1c) {
          puVar8 = (uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0xe8) + *(int *)(puVar5 + 2));
          iVar7 = FUN_4045ffc4(param_1,*puVar8,&local_24,&local_1c);
          if (iVar7 < 0) {
            return iVar7;
          }
          puVar1 = puVar8 + 1;
          if (local_24 == 0) {
            return -0x7ffd7360;
          }
          local_24 = (local_24 + local_1c) - 1 & ~(local_1c - 1);
          uVar3 = 1;
          uVar6 = 0;
          uVar4 = uVar3;
          if ((ushort)*puVar1 != 0) {
            do {
              puVar8 = puVar8 + 2;
              uVar3 = *puVar8 * uVar4;
              if (uVar3 < uVar4) {
                return -0x7ffd773b;
              }
              uVar6 = uVar6 + 1;
              uVar4 = uVar3;
            } while (uVar6 < (ushort)*puVar1);
          }
          uVar4 = uVar3 * local_24;
          if ((uVar4 < uVar3) || (uVar4 < local_24)) {
            return -0x7ffd773b;
          }
          *param_3 = uVar4;
          *param_4 = local_1c;
        }
        else if (uVar2 == 0x1d) {
          iVar7 = (**(code **)(*(int *)(param_1 + 4) + 0x38))
                            ((int *)(param_1 + 4),*(undefined4 *)(puVar5 + 2),&local_28);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar7 = (**(code **)(*local_28 + 0xc))(local_28,&local_20);
          if (-1 < iVar7) {
            *param_3 = *(uint *)(local_20 + 0x24);
            *param_4 = (uint)*(ushort *)(local_20 + 0x34);
            (**(code **)(*local_28 + 0x4c))();
          }
        }
      }
      if (local_28 != (int *)0x0) {
        (**(code **)(*local_28 + 8))();
      }
    }
  }
  else {
    *param_3 = (int)(char)(&DAT_40441a84)[param_2 & 0xffff];
    iVar7 = 0;
    *param_4 = (int)(char)(&DAT_40441ac4)[param_2 & 0xffff];
  }
  return iVar7;
}



/* 40460228 FUN_40460228 */

/* Boundary evidence: original MIPS .pdata 40460228..40460427. Semantic name remains unreviewed. */

int FUN_40460228(int param_1,uint param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *_Src;
  
  if ((param_2 & 0x80000000) == 0) {
    if ((*(uint *)(param_1 + 0xf8) & 8) == 0) {
      iVar2 = FUN_4045a028((int *)(param_1 + 0xec),param_1);
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    _Src = (undefined2 *)(*(int *)(param_1 + 0xfc) + param_2);
    uVar1 = *_Src;
    switch(uVar1) {
    case 3:
    case 4:
    case 10:
    case 0x13:
    case 0x16:
    case 0x17:
      *(undefined4 *)(param_3 + 4) = *(undefined4 *)(_Src + 1);
      break;
    case 5:
    case 6:
    case 7:
    case 0x14:
    case 0x15:
      *(undefined4 *)(param_3 + 4) = *(undefined4 *)(_Src + 1);
      *(undefined4 *)(param_3 + 6) = *(undefined4 *)(_Src + 3);
      break;
    case 8:
      if (*(UINT *)(_Src + 1) == 0xffffffff) {
        *(undefined4 *)(param_3 + 4) = 0;
      }
      else {
        iVar2 = FUN_4045bc08((char *)(_Src + 3),*(UINT *)(_Src + 1),(undefined4 *)(param_3 + 4));
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      break;
    default:
      goto LAB_40460410;
    case 0xe:
      memcpy(param_3,_Src,0x10);
      return 0;
    }
    *param_3 = uVar1;
  }
  else {
    uVar3 = param_2 >> 0x1a & 0x1f;
    *param_3 = (short)uVar3;
    switch(uVar3) {
    case 2:
    case 0xb:
    case 0x12:
      param_3[4] = (short)param_2;
      break;
    case 3:
    case 4:
    case 9:
    case 10:
    case 0xd:
    case 0x13:
    case 0x16:
    case 0x17:
      *(uint *)(param_3 + 4) = param_2 & 0x3ffffff;
      break;
    default:
LAB_40460410:
      return -0x7ffdfff8;
    case 0x10:
    case 0x11:
      *(char *)(param_3 + 4) = (char)param_2;
    }
  }
  return 0;
}



/* 40460428 FUN_40460428 */

/* Boundary evidence: original MIPS .pdata 40460428..4046061f. Semantic name remains unreviewed. */

int FUN_40460428(int param_1,int param_2,void *param_3,undefined2 *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_30;
  undefined4 *local_2c;
  
  if ((*(uint *)(param_1 + 0x10c) & 8) == 0) {
    iVar1 = FUN_4045a028((int *)(param_1 + 0x100),param_1);
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if (param_5 == (int *)0x0) {
    if (param_2 == -1) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0x110);
    iVar7 = *(int *)(param_1 + 0x84);
    do {
      piVar6 = (int *)(iVar1 + param_2);
      iVar2 = memcmp(param_3,(void *)(*piVar6 + iVar7),0x10);
      if (iVar2 == 0) {
        iVar1 = FUN_40460228(param_1,piVar6[1],param_4);
        return iVar1;
      }
      param_2 = piVar6[2];
    } while (param_2 != -1);
    return 0;
  }
  iVar1 = 0;
  if (param_2 != -1) {
    iVar7 = param_2;
    do {
      iVar7 = *(int *)(*(int *)(param_1 + 0x110) + iVar7 + 8);
      iVar1 = iVar1 + 1;
    } while (iVar7 != -1);
    if (iVar1 != 0) {
      pvVar3 = TlsGetValue(DAT_4046d1b0);
      puVar4 = FUN_40457d14((int)pvVar3,iVar1 * 0x20);
      if (puVar4 == (undefined4 *)0x0) {
        return -0x7ff8fff2;
      }
      local_30 = 0;
      puVar8 = puVar4;
      local_2c = puVar4;
      do {
        iVar1 = local_30;
        piVar6 = (int *)(*(int *)(param_1 + 0x110) + param_2);
        puVar5 = (undefined4 *)(*piVar6 + *(int *)(param_1 + 0x84));
        *puVar8 = *puVar5;
        puVar8[1] = puVar5[1];
        puVar8[2] = puVar5[2];
        puVar8[3] = puVar5[3];
        iVar7 = FUN_40460228(param_1,piVar6[1],(undefined2 *)(puVar8 + 4));
        if (iVar7 < 0) {
          FUN_4045f398(&local_30);
          return iVar7;
        }
        local_30 = iVar1 + 1;
        param_2 = piVar6[2];
        puVar8 = puVar8 + 8;
      } while (param_2 != -1);
      goto LAB_404605e0;
    }
  }
  local_30 = 0;
  puVar4 = local_2c;
LAB_404605e0:
  *param_5 = local_30;
  param_5[1] = (int)puVar4;
  return 0;
}



/* 40460620 FUN_40460620 */

/* Boundary evidence: original MIPS .pdata 40460620..4046080f. Semantic name remains unreviewed. */

uint FUN_40460620(int param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == (ushort *)0x0) {
    return 0;
  }
  if (param_2 == 0x409) {
    iVar2 = 1;
    goto LAB_40460760;
  }
  if (0x415 < param_2) {
    if (param_2 < 0x420) {
      if (param_2 == 0x41f) {
        iVar2 = 10;
        goto LAB_40460760;
      }
      if (param_2 == 0x419) {
        iVar2 = 3;
        goto LAB_40460760;
      }
      if (param_2 == 0x41b) goto switchD_40460694_caseD_405;
    }
    else {
      if (param_2 == 0x814) {
        iVar2 = 0xb;
        goto LAB_40460760;
      }
      if (param_2 == 0x1809) {
        iVar2 = 0xc;
        goto LAB_40460760;
      }
    }
switchD_40460694_caseD_406:
    if (((param_2 & 0xff) == 1) || (param_2 == 0x429)) {
      iVar2 = 0xd;
    }
    else {
      iVar2 = 1;
    }
    goto LAB_40460760;
  }
  if (param_2 == 0x415) {
switchD_40460694_caseD_405:
    iVar2 = 2;
  }
  else {
    switch(param_2) {
    case 0x405:
    case 0x40e:
      goto switchD_40460694_caseD_405;
    default:
      goto switchD_40460694_caseD_406;
    case 0x408:
      iVar2 = 8;
      break;
    case 0x40d:
      iVar2 = 0xe;
      break;
    case 0x40f:
      iVar2 = 9;
    }
  }
LAB_40460760:
  uVar3 = 0xdeadbee;
  uVar1 = *param_3;
  while (uVar1 != 0) {
    param_3 = param_3 + 1;
    uVar3 = (uint)*(byte *)((uVar1 & 0xff) +
                           *(int *)(&UNK_40442f8c + (iVar2 * 2 + (uint)(param_1 == 2)) * 4)) +
            uVar3 * 0x25;
    uVar1 = *param_3;
  }
  return uVar3 + (uVar3 / 0x1003f) * -0x3f & 0xffff | (iVar2 << 4 | (uint)(param_1 == 2)) << 0x10;
}



/* 40460810 FUN_40460810 */

/* Boundary evidence: original MIPS .pdata 40460810..40460887. Semantic name remains unreviewed. */

void FUN_40460810(int param_1,int *param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(int *)(param_1 + 0x14) = param_4;
  if (param_4 == 5) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  (**(code **)(*param_2 + 4))(param_2);
  *(int **)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}



/* 40460888 FUN_40460888 */

/* Boundary evidence: original MIPS .pdata 40460888..4046095b. Semantic name remains unreviewed. */

int FUN_40460888(int param_1,ushort *param_2)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = FUN_4045df50(*(int *)(param_1 + 0x10),local_18);
  if (-1 < iVar1) {
    *(undefined4 *)(local_18[0] + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(local_18[0] + 0x28) = *(undefined4 *)(param_1 + 0x28);
    *(int *)(local_18[0] + 0x1c) = param_1;
    *(int *)(param_1 + 0x1c) = local_18[0];
    *param_2 = *param_2 | 0x10;
    if (*(int *)(param_1 + 0x14) == 3) {
      *(undefined4 *)(local_18[0] + 0x14) = 4;
      *param_2 = *param_2 & 0xfff0 | 4;
      *(int *)(param_2 + 0x2e) = local_18[0];
    }
    else {
      *(undefined4 *)(local_18[0] + 0x14) = 3;
    }
    iVar1 = 0;
    *(undefined4 *)(local_18[0] + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(local_18[0] + 0x20) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(local_18[0] + 0x24) = *(undefined4 *)(param_1 + 0x24);
  }
  return iVar1;
}



/* 4046095c FUN_4046095c */

/* Boundary evidence: original MIPS .pdata 4046095c..40460997. Semantic name remains unreviewed. */

void FUN_4046095c(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    InterlockedIncrement((LONG *)(*(int *)(param_1 + 0x1c) + 0x28));
  }
  InterlockedIncrement((LONG *)(param_1 + 0x28));
  return;
}



/* 40460998 FUN_40460998 */

void FUN_40460998(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  
  *(undefined4 *)(param_2 + 0x34) = param_3;
  iVar2 = *param_4;
  bVar1 = (byte)((ushort)(short)param_4[2] >> 8) | 0x28;
  *param_4 = *(int *)(param_1 + 0xc);
  uVar3 = (undefined1)(short)param_4[2];
  *(undefined1 *)(param_4 + 2) = uVar3;
  *(byte *)((int)param_4 + 9) = bVar1;
  *(undefined1 *)(param_4 + 2) = uVar3;
  *(byte *)((int)param_4 + 9) = ((byte)(((uint)(iVar2 == -1) << 0xc) >> 8) ^ bVar1) & 0x10 ^ bVar1;
  return;
}



/* 40460a0c FUN_40460a0c */

/* Boundary evidence: original MIPS .pdata 40460a0c..40460a5f. Semantic name remains unreviewed. */

undefined4 FUN_40460a0c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    iVar2 = param_1 + 4;
    if (param_1 == 4) {
      iVar2 = 0;
    }
    *param_2 = iVar2;
    (**(code **)(*(int *)(param_1 + -4) + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40460a60 FUN_40460a60 */

/* Boundary evidence: original MIPS .pdata 40460a60..40460b83. Semantic name remains unreviewed. */

HRESULT FUN_40460a60(int param_1,int param_2,IID *param_3,LPVOID *param_4)

{
  uint uVar1;
  DWORD dwClsContext;
  int iVar2;
  ulong *puVar3;
  HRESULT HVar4;
  IID local_20;
  uint local_10;
  
  uVar1 = DAT_4046d1b8;
  local_10 = DAT_4046d1b8;
  if (param_4 == (LPVOID *)0x0) {
    FUN_4046ace8(DAT_4046d1b8);
    HVar4 = -0x7ff8ffa9;
  }
  else {
    *param_4 = (LPVOID)0x0;
    dwClsContext = 5;
    if (*(int *)(param_1 + 0x10) == 5) {
      if (param_2 == 0) {
        iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8) + 0x2c);
        if (iVar2 == -1) {
          puVar3 = &DAT_40443ecc;
        }
        else {
          puVar3 = (ulong *)(*(int *)(*(int *)(param_1 + 0xc) + 0x84) + iVar2);
        }
        local_20.Data1 = *puVar3;
        local_20._4_4_ = puVar3[1];
        local_20.Data4._0_4_ = puVar3[2];
        local_20.Data4._4_4_ = puVar3[3];
        if (0x4d1 < DAT_4046d1c4) {
          dwClsContext = 0x15;
        }
        HVar4 = CoCreateInstance(&local_20,(LPUNKNOWN)0x0,dwClsContext,param_3,param_4);
        FUN_4046ace8(local_10);
      }
      else {
        FUN_4046ace8(uVar1);
        HVar4 = -0x7ffbfef0;
      }
    }
    else {
      FUN_4046ace8(uVar1);
      HVar4 = -0x7ffd7743;
    }
  }
  return HVar4;
}



/* 40460ba8 FUN_40460ba8 */

/* Boundary evidence: original MIPS .pdata 40460ba8..40460c2f. Semantic name remains unreviewed. */

undefined4 FUN_40460ba8(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 4))();
    iVar1 = *(int *)(param_1 + 0xc) + 4;
    if (*(int *)(param_1 + 0xc) == 0) {
      iVar1 = 0;
    }
    *param_2 = iVar1;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = (uint)*(ushort *)
                      (*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8) + 2);
  }
  return 0;
}



/* 40460c30 FUN_40460c30 */

/* Boundary evidence: original MIPS .pdata 40460c30..40460c4b. Semantic name remains unreviewed. */

void FUN_40460c30(undefined4 param_1,BSTR param_2)

{
  SysFreeString(param_2);
  return;
}



/* 40460c4c FUN_40460c4c */

/* Boundary evidence: original MIPS .pdata 40460c4c..40460cf7. Semantic name remains unreviewed. */

void FUN_40460c4c(undefined4 param_1,BSTR param_2)

{
  VARIANTARG *pvarg;
  int iVar1;
  int iVar2;
  
  if (param_2 != (BSTR)0x0) {
    if (((param_2[0x16] & 0x20U) != 0) && (iVar1 = (int)param_2[0xc], iVar1 != 0)) {
      iVar2 = 0;
      do {
        if (((*(ushort *)(iVar2 + *(int *)(param_2 + 4) + 0xc) & 0x20) != 0) &&
           (pvarg = (VARIANTARG *)(*(int *)(iVar2 + *(int *)(param_2 + 4) + 8) + 8),
           (pvarg->n1).n2.vt == 8)) {
          VariantClear(pvarg);
        }
        iVar1 = iVar1 + -1;
        iVar2 = iVar2 + 0x10;
      } while (iVar1 != 0);
    }
    SysFreeString(param_2);
  }
  return;
}



/* 40460cf8 FUN_40460cf8 */

/* Boundary evidence: original MIPS .pdata 40460cf8..40460d53. Semantic name remains unreviewed. */

void FUN_40460cf8(undefined4 param_1,BSTR param_2)

{
  if (param_2 != (BSTR)0x0) {
    if ((*(int *)(param_2 + 0x10) == 2) && (7 < ((*(VARIANTARG **)(param_2 + 4))->n1).n2.vt)) {
      VariantClear(*(VARIANTARG **)(param_2 + 4));
    }
    SysFreeString(param_2);
  }
  return;
}



/* 40460db4 FUN_40460db4 */

/* Boundary evidence: original MIPS .pdata 40460db4..40460e9f. Semantic name remains unreviewed. */

int FUN_40460db4(int param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  ushort *puVar2;
  
  if (param_4 == (uint *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    puVar2 = (ushort *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8));
    if ((*puVar2 & 0x20) == 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + -4) + 100))();
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      if ((*(uint *)(puVar2 + 8) & 8) == 0) {
        iVar1 = FUN_4045a504((int *)(puVar2 + 2),*(int *)(param_1 + 0xc),0);
      }
      else {
        iVar1 = 0;
      }
      if (-1 < iVar1) {
        iVar1 = FUN_4045a9e4((int)(puVar2 + 2),param_2,param_3,param_4);
      }
    }
  }
  return iVar1;
}



/* 40460ea0 FUN_40460ea0 */

/* Boundary evidence: original MIPS .pdata 40460ea0..40460f37. Semantic name remains unreviewed. */

int FUN_40460ea0(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8);
    piVar2 = (int *)(iVar1 + 4);
    if ((*(uint *)(iVar1 + 0x10) & 8) == 0) {
      iVar1 = FUN_4045a504(piVar2,*(int *)(param_1 + 0xc),0);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = FUN_4045aa7c((int)piVar2,param_2,param_3);
    }
  }
  return iVar1;
}



/* 40460f38 FUN_40460f38 */

/* Boundary evidence: original MIPS .pdata 40460f38..40460f87. Semantic name remains unreviewed. */

int FUN_40460f38(int param_1,void *param_2,undefined2 *param_3)

{
  int iVar1;
  
  if (param_3 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_40460428(*(int *)(param_1 + 0xc),
                         *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8) +
                                 0x48),param_2,param_3,(int *)0x0);
  }
  return iVar1;
}



/* 40460f88 FUN_40460f88 */

/* Boundary evidence: original MIPS .pdata 40460f88..40460fd7. Semantic name remains unreviewed. */

int FUN_40460f88(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_2 = 0;
    iVar1 = FUN_40460428(*(int *)(param_1 + 0xc),
                         *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8) +
                                 0x48),(void *)0x0,(undefined2 *)0x0,param_2);
  }
  return iVar1;
}



/* 40460fd8 FUN_40460fd8 */

/* Boundary evidence: original MIPS .pdata 40460fd8..404610df. Semantic name remains unreviewed. */

int FUN_40460fd8(int param_1,uint param_2,void *param_3,undefined2 *param_4,int *param_5)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(uint *)(iVar3 + 0x10) & 8) == 0) {
    iVar1 = FUN_4045a504((int *)(iVar3 + 4),*(int *)(param_1 + 0x10),0);
  }
  else {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 < *(ushort *)(iVar3 + 0x1a)) {
      puVar2 = (ushort *)
               (*(int *)(iVar3 + 0x14) +
               *(int *)((*(ushort *)(iVar3 + 0x18) + param_2) * 4 + *(int *)(iVar3 + 0x28)));
      if (*puVar2 < 0x21) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_40460428(*(int *)(param_1 + 0x10),*(int *)(puVar2 + 0x10),param_3,param_4,
                             param_5);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 4046111c FUN_4046111c */

/* Boundary evidence: original MIPS .pdata 4046111c..404611b3. Semantic name remains unreviewed. */

undefined4 FUN_4046111c(int param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  undefined4 uVar2;
  
  pOVar1 = SysAllocStringByteLen((LPCSTR)0x0,0x2c);
  if (pOVar1 == (BSTR)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    pOVar1[0] = L'\xfffe';
    pOVar1[1] = L'\xffff';
    pOVar1[0x10] = L'\x01';
    pOVar1[0x11] = L'\0';
    pOVar1[2] = L'\0';
    pOVar1[3] = L'\0';
    pOVar1[0xe] = L'\0';
    pOVar1[4] = L'\0';
    pOVar1[5] = L'\0';
    pOVar1[10] = L'\0';
    pOVar1[0xb] = L'\0';
    pOVar1[0xc] = L'\0';
    pOVar1[8] = L'\x1a';
    pOVar1[0x14] = L'\x1d';
    *(undefined4 *)(pOVar1 + 0x12) = *(undefined4 *)(param_1 + 0xc);
    *(BSTR *)(pOVar1 + 6) = pOVar1 + 0x12;
    *param_2 = pOVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 404611b4 FUN_404611b4 */

undefined4 FUN_404611b4(uint param_1)

{
  undefined4 uVar1;
  
  if (((((param_1 & 0x80000000) == 0) ||
       ((-9 < (int)param_1 && (((int)param_1 < -3 || (param_1 == 0xffffffff)))))) ||
      ((-1000 < (int)param_1 && ((int)param_1 < -499)))) ||
     ((((-4000 < (int)param_1 && ((int)param_1 < -1999)) ||
       ((-0x157c < (int)param_1 && ((int)param_1 < -4999)))) || (param_1 >> 0x10 == 0x8001)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 40461258 FUN_40461258 */

/* Boundary evidence: original MIPS .pdata 40461258..40461497. Semantic name remains unreviewed. */

int FUN_40461258(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_3 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar1 = memcmp(param_2,&DAT_40441cfc,0x10);
  if (iVar1 != 0) {
    iVar1 = memcmp(param_2,&DAT_40443f8c,0x10);
    if ((iVar1 != 0) && (iVar1 = memcmp(param_2,&DAT_40443f7c,0x10), iVar1 != 0)) {
      iVar1 = memcmp(param_2,&DAT_40443f6c,0x10);
      if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40443f5c,0x10), iVar1 == 0)) {
LAB_4046136c:
        piVar3 = param_1 + 1;
      }
      else {
        iVar1 = memcmp(param_2,&DAT_40443eec,0x10);
        if (iVar1 != 0) {
          iVar1 = memcmp(param_2,&DAT_40443ebc,0x10);
          if (iVar1 != 0) {
            iVar1 = memcmp(param_2,&DAT_40443f4c,0x10);
            if ((iVar1 != 0) && (iVar1 = memcmp(param_2,&DAT_40441ccc,0x10), iVar1 != 0)) {
              *param_3 = 0;
              return -0x7fffbffe;
            }
            if ((param_1[8] == 0) || (param_1[9] == 0)) {
              *param_3 = 0;
              puVar2 = FUN_4046a730();
              param_1[8] = (int)puVar2;
              if (puVar2 == (undefined4 *)0x0) {
                return -0x7ff8fff2;
              }
              puVar2 = FUN_4046a6e4();
              param_1[9] = (int)puVar2;
              if (puVar2 == (undefined4 *)0x0) {
                return -0x7ff8fff2;
              }
              if (param_1[7] != 0) {
                *(int *)(param_1[7] + 0x20) = param_1[8];
                *(int *)(param_1[7] + 0x24) = param_1[9];
              }
              iVar1 = FUN_4046a2cc(param_1[9],(int *)param_1[8],(undefined4 *)&DAT_40443f3c);
              if (iVar1 < 0) {
                return iVar1;
              }
            }
            (**(code **)(*(int *)param_1[8] + 4))();
            *param_3 = param_1[8];
            return 0;
          }
          goto LAB_4046136c;
        }
        piVar3 = param_1 + 2;
      }
      if (param_1 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      *param_3 = (int)piVar3;
      goto LAB_40461380;
    }
    iVar1 = FUN_4045928c(param_1[4]);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  *param_3 = (int)param_1;
LAB_40461380:
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}



/* 40461498 FUN_40461498 */

/* Boundary evidence: original MIPS .pdata 40461498..404615df. Semantic name remains unreviewed. */

LONG FUN_40461498(LPVOID param_1)

{
  LONG LVar1;
  LPVOID pvVar2;
  int *piVar3;
  
  pvVar2 = *(LPVOID *)((int)param_1 + 0x1c);
  if ((pvVar2 != (LPVOID)0x0) &&
     (LVar1 = InterlockedDecrement((LONG *)((int)pvVar2 + 0x28)), LVar1 == 0)) {
    FUN_4045d1ec(*(int *)((int)pvVar2 + 0x10),pvVar2);
  }
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 0x28));
  if (LVar1 == 0) {
    *(undefined4 *)
     (*(int *)(*(int *)((int)param_1 + 0x10) + 0x20) + *(int *)((int)param_1 + 0xc) + 0x5c) = 0;
    if (*(int *)((int)param_1 + 0x14) == 5) {
      if (*(int *)((int)param_1 + 0x18) != -1) {
        FUN_40457a40(0x4046de9c,*(int *)((int)param_1 + 0x18));
      }
    }
    else if ((*(int *)((int)param_1 + 0x14) == 2) &&
            ((HMODULE)0x20 < *(HMODULE *)((int)param_1 + 0x18))) {
      FreeLibrary(*(HMODULE *)((int)param_1 + 0x18));
    }
    if (*(int **)((int)param_1 + 0x24) != (int *)0x0) {
      (**(code **)(**(int **)((int)param_1 + 0x24) + 8))();
    }
    if (*(int **)((int)param_1 + 0x20) != (int *)0x0) {
      (**(code **)(**(int **)((int)param_1 + 0x20) + 8))();
    }
    piVar3 = *(int **)((int)param_1 + 0x10);
    FUN_4045d1ec((int)piVar3,param_1);
    (**(code **)(*piVar3 + 8))(piVar3);
    LVar1 = 0;
  }
  else {
    LVar1 = *(LONG *)((int)param_1 + 0x28);
  }
  return LVar1;
}



/* 404615e0 FUN_404615e0 */

/* Boundary evidence: original MIPS .pdata 404615e0..4046171b. Semantic name remains unreviewed. */

int FUN_404615e0(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    piVar4 = (int *)(iVar3 + iVar2 + 0x2c);
    if (*piVar4 != -1) {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + 0x84) + *piVar4 + 0x10) = 0xffffffff;
    }
    iVar2 = memcmp(param_2,&DAT_40443ecc,0x10);
    if (iVar2 == 0) {
      *piVar4 = -1;
    }
    else {
      iVar2 = FUN_4045c4d8(*(int *)(param_1 + 0x10),param_2,*(uint *)(param_1 + 0xc),piVar4);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = memcmp(param_2,&DAT_40443edc,0x10);
      if ((iVar2 == 0) && (*(int *)(*(int *)(param_1 + 0x10) + 0x184) == -1)) {
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x184) = *(undefined4 *)(param_1 + 0xc);
      }
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 4046171c FUN_4046171c */

/* Boundary evidence: original MIPS .pdata 4046171c..4046194f. Semantic name remains unreviewed. */

int FUN_4046171c(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int *local_28;
  int *local_24;
  undefined1 auStack_20 [8];
  
  puVar3 = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
  if ((param_1[9] == 0) || (iVar1 = FUN_4046a358(param_1[9],4,param_1 + 1,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((param_2 & 0xffff0000) != 0) {
    return -0x7ff8ffa9;
  }
  iVar1 = param_1[5];
  if (iVar1 < 0) goto LAB_404617e8;
  if (iVar1 < 3) {
LAB_40461924:
    uVar2 = 0xfffffdef;
LAB_404618f4:
    uVar2 = param_2 & uVar2;
  }
  else {
    if (iVar1 != 3) {
      if (iVar1 != 4) {
        if (iVar1 == 5) {
          if ((param_2 & 0xfffff9c0) != 0) {
            return -0x7ffd7743;
          }
          if ((param_2 & 1) != 0) {
            param_2 = param_2 | 8;
          }
          goto LAB_404617e8;
        }
        if ((iVar1 < 6) || (7 < iVar1)) goto LAB_404617e8;
        goto LAB_40461924;
      }
      uVar2 = 0xffffe52f;
      goto LAB_404618f4;
    }
    uVar2 = param_2 & 0xffffc42f;
  }
  if (uVar2 != 0) {
    return -0x7ffd7743;
  }
LAB_404617e8:
  if (((param_2 & 0x40) != 0) && ((*(uint *)(puVar3 + 0x18) & 0x40) == 0)) {
    if (*(int *)(param_1[4] + 0x184) == -1) {
      iVar1 = FUN_4045bbc0(param_1[4],&local_24);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = (**(code **)(*local_24 + 0x18))(local_24,&DAT_40443edc,&local_28);
      if (iVar1 < 0) {
        return iVar1;
      }
      (**(code **)(*param_1 + 0x20))(param_1,local_28,auStack_20);
      (**(code **)(*local_28 + 8))();
    }
    iVar1 = FUN_40460888((int)param_1,puVar3);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  *(uint *)(puVar3 + 0x18) = param_2;
  if (param_1[9] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_4046a418(param_1[9],4,param_1 + 1,0);
  }
  return iVar1;
}



/* 40461950 FUN_40461950 */

/* Boundary evidence: original MIPS .pdata 40461950..40461a13. Semantic name remains unreviewed. */

int FUN_40461950(int param_1,wchar_t *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 == (wchar_t *)0x0) {
      iVar1 = -0x7ff8ffa9;
    }
    else {
      iVar1 = FUN_4045c1e8(*(int *)(param_1 + 0x10),param_2,(int *)(iVar3 + iVar2 + 0x3c));
      if (-1 < iVar1) {
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
        }
      }
    }
  }
  return iVar1;
}



/* 40461a14 FUN_40461a14 */

/* Boundary evidence: original MIPS .pdata 40461a14..40461aaf. Semantic name remains unreviewed. */

int FUN_40461a14(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    *(undefined4 *)(iVar3 + iVar2 + 0x44) = param_2;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40461ab0 FUN_40461ab0 */

/* Boundary evidence: original MIPS .pdata 40461ab0..40461b5b. Semantic name remains unreviewed. */

int FUN_40461ab0(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    *(undefined2 *)(iVar2 + 0x38) = param_2;
    *(undefined2 *)(iVar2 + 0x3a) = param_3;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40461b5c FUN_40461b5c */

/* Boundary evidence: original MIPS .pdata 40461b5c..40461d07. Semantic name remains unreviewed. */

int FUN_40461b5c(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *local_28;
  undefined4 local_24;
  int local_20 [2];
  
  if ((param_2 == (int *)0x0) || (param_3 == (uint *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),0,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(*param_2 + 0x48))(param_2,&local_28,&local_24), -1 < iVar1)) {
      piVar2 = (int *)(*(int *)(param_1 + 0x10) + 4);
      if (*(int *)(param_1 + 0x10) == 0) {
        piVar2 = (int *)0x0;
      }
      if (local_28 == piVar2) {
        if (param_2[4] == 2) {
          iVar1 = -0x7ffd7360;
        }
        else {
          uVar3 = param_2[2];
          if ((param_2[4] == 3) && (param_2[6] != 0)) {
            uVar3 = uVar3 | 2;
          }
          *param_3 = uVar3;
        }
      }
      else {
        iVar1 = (**(code **)(*local_28 + 0x14))(local_28,local_24,local_20);
        if (-1 < iVar1) {
          if (local_20[0] == 2) {
            iVar1 = -0x7ffd7360;
          }
          else {
            iVar1 = FUN_4045c650(*(int *)(param_1 + 0x10),local_28,param_2,local_24,param_3);
          }
        }
      }
      (**(code **)(*local_28 + 8))();
      if (-1 < iVar1) {
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),0,param_1 + 4,0);
        }
      }
    }
  }
  return iVar1;
}



/* 40461d08 FUN_40461d08 */

/* Boundary evidence: original MIPS .pdata 40461d08..4046209b. Semantic name remains unreviewed. */

int FUN_40461d08(int param_1,uint param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  ushort *puVar6;
  int *piVar7;
  int *local_38;
  int local_34;
  int local_30;
  int *local_2c;
  
  local_38 = (int *)0x0;
  if (param_3 == -1) {
    return -0x7ff8ffa9;
  }
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar2 = FUN_4046a358(*(int *)(param_1 + 0x24),0,param_1 + 4,0), -1 < iVar2)) {
    iVar2 = 0;
  }
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  puVar6 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  *puVar6 = *puVar6 & 0xffdf;
  if ((iVar2 < 3) || (5 < iVar2)) goto LAB_40461f18;
  piVar7 = (int *)(param_1 + 4);
  iVar3 = (**(code **)(*piVar7 + 0x38))(piVar7,param_3,&local_38);
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = (**(code **)(*local_38 + 0xc))(local_38,&local_30);
  if (iVar3 < 0) goto LAB_40461f20;
  iVar3 = *(int *)(local_30 + 0x28);
  uVar1 = *(ushort *)(local_30 + 0x36);
  (**(code **)(*local_38 + 0x4c))();
  if ((iVar3 == 3) || ((uVar1 & 0x40) != 0)) {
    if (((*(uint *)(puVar6 + 0x18) & 0x40) != 0) || (iVar2 == 4)) {
      iVar3 = (**(code **)*local_38)(local_38,&DAT_40441cfc,&local_2c);
      if (iVar3 != 0) {
        iVar3 = -0x7ffd7fe7;
        goto LAB_40461f20;
      }
      (**(code **)(*local_2c + 8))();
    }
  }
  else if ((iVar2 != 5) || (iVar3 != 4)) {
    iVar3 = -0x7ffd7fd6;
    goto LAB_40461f20;
  }
  if (param_2 != puVar6[0x26]) {
    iVar3 = -0x7ffd7fd5;
    goto LAB_40461f20;
  }
  if (iVar2 == 5) {
    iVar3 = FUN_4045a374(*(int *)(param_1 + 0x10) + 0x4c,&local_34,0x10);
    if (iVar3 < 0) goto LAB_40461f20;
    puVar5 = puVar6 + 0x2a;
    piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + 0x5c) + local_34);
    *piVar4 = param_3;
    piVar4[1] = 0;
    piVar4[2] = -1;
    piVar4[3] = -1;
    if (*(int *)puVar5 != -1) {
      do {
        puVar5 = (ushort *)(*(int *)puVar5 + *(int *)(*(int *)(param_1 + 0x10) + 0x5c) + 0xc);
      } while (*(int *)puVar5 != -1);
    }
    *(int *)puVar5 = local_34;
    puVar6[0x26] = puVar6[0x26] + 1;
  }
  else {
    if (*(int *)(puVar6 + 0x2a) != -1) goto LAB_40461f18;
    if (iVar2 == 4) {
      if (param_2 == 0) {
        if (param_3 == *(int *)(*(int *)(param_1 + 0x10) + 0x184)) goto LAB_40461f94;
      }
      else if (param_2 < 2) {
        *(int *)(puVar6 + 0x2a) = param_3;
        *puVar6 = *puVar6 | 0x10;
        goto LAB_40461f9c;
      }
LAB_40461f18:
      iVar3 = -0x7ffd7743;
      goto LAB_40461f20;
    }
    *(int *)(puVar6 + 0x2a) = param_3;
LAB_40461f94:
    puVar6[0x26] = puVar6[0x26] + 1;
LAB_40461f9c:
    if ((param_3 == *(int *)(*(int *)(param_1 + 0x10) + 0x184)) || ((uVar1 & 0x1000) != 0)) {
      *(uint *)(puVar6 + 0x18) = *(uint *)(puVar6 + 0x18) | 0x1000;
    }
    if ((uVar1 & 0x800) != 0) {
      *(uint *)(puVar6 + 0x18) = *(uint *)(puVar6 + 0x18) | 0x800;
    }
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_4046a418(*(int *)(param_1 + 0x24),0,piVar7,0);
  }
LAB_40461f20:
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  return iVar3;
}



/* 40462188 FUN_40462188 */

/* Boundary evidence: original MIPS .pdata 40462188..40462777. Semantic name remains unreviewed. */

int FUN_40462188(int *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  ushort uVar8;
  uint *puVar9;
  VARIANTARG *pvargDest;
  uint *puVar10;
  VARTYPE vt;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  short local_48 [2];
  uint local_44;
  uint *local_40;
  ushort *local_3c;
  uint local_38;
  uint local_34;
  int local_30 [2];
  
  uVar7 = 0;
  if (param_3 != (uint *)0x0) {
    local_3c = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
    local_34 = param_2;
    if ((param_1[9] == 0) || (iVar2 = FUN_4046a358(param_1[9],0,param_1 + 1,0), -1 < iVar2)) {
      iVar2 = 0;
    }
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = param_1[5];
    if (iVar2 == 2) {
      if (param_3[3] != 3) {
        return -0x7ffd7743;
      }
    }
    else if (iVar2 == 3) {
      if (param_3[3] != 1) {
        return -0x7ffd7743;
      }
    }
    else if ((iVar2 != 4) || (param_3[3] != 4)) {
      return -0x7ffd7743;
    }
    uVar12 = *param_3;
    iVar2 = FUN_404611b4(uVar12);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (((int)param_3[4] < 9) && ((int)param_3[5] < 9)) {
      uVar8 = (ushort)param_3[7];
      if (uVar8 == 0xffff) {
        uVar8 = 0;
      }
      if ((uVar8 & 3) == 0) {
        uVar1 = param_3[6];
        local_44 = (uint)(ushort)uVar1;
        uVar11 = param_3[2];
        uVar4 = 0;
        if (local_44 != 0) {
          puVar3 = (ushort *)(uVar11 + 0xc);
          do {
            if ((*puVar3 & 0x20) != 0) {
              uVar7 = 1;
              break;
            }
            uVar4 = uVar4 + 1;
            puVar3 = puVar3 + 8;
          } while (uVar4 < local_44);
        }
        iVar2 = FUN_4045b2d8((int)(local_3c + 2),local_34,local_44,uVar7,local_30);
        if (iVar2 < 0) {
          return iVar2;
        }
        *local_3c = *local_3c & 0xffdf;
        puVar3 = (ushort *)(*(int *)(local_3c + 10) + local_30[0]);
        *(uint *)(puVar3 + 4) = (uint)(ushort)param_3[0xc];
        *(uint *)((uint)puVar3[1] * 4 + *(int *)(local_3c + 0x10)) = uVar12;
        uVar6 = (puVar3[8] ^ (ushort)param_3[3]) & 7 ^ puVar3[8];
        puVar3[8] = uVar6;
        uVar6 = ((ushort)(param_3[4] << 3) ^ uVar6) & 0x78 ^ uVar6;
        puVar3[8] = uVar6;
        uVar7 = param_3[5];
        puVar3[10] = (ushort)uVar1;
        puVar3[8] = ((ushort)(uVar7 << 8) ^ uVar6) & 0xf00 ^ uVar6;
        puVar3[0xb] = *(ushort *)((int)param_3 + 0x1a);
        uVar6 = 0;
        if (uVar8 != 0) {
          uVar6 = uVar8 | 1;
        }
        puVar3[6] = uVar6;
        local_48[0] = 0;
        iVar2 = FUN_4045f434((int)param_1,param_3 + 8,(uint *)(puVar3 + 2),local_48);
        if (-1 < iVar2) {
          if (((puVar3[8] & 0x60) == 0) ||
             ((uVar7 = *(uint *)(puVar3 + 2), (uVar7 & 0x80000000) != 0 &&
              ((uVar7 = uVar7 >> 0x10 & 0x7fff, uVar7 == 0 || (uVar7 == 0x19)))))) {
            puVar9 = (uint *)((uint)*puVar3 + (uint)puVar3[10] * -0x10 + (int)puVar3);
            local_38 = 0;
            puVar10 = (uint *)((uint)*puVar3 + (uint)puVar3[10] * -0xc + (int)puVar3);
            local_40 = puVar9;
            if (local_44 != 0) {
              piVar13 = (int *)(uVar11 + 8);
              uVar7 = local_44;
              do {
                local_40 = puVar9;
                iVar2 = FUN_4045f434((int)param_1,(uint *)(piVar13 + -2),puVar10,local_48);
                if (iVar2 < 0) goto LAB_4046245c;
                uVar8 = *(ushort *)(piVar13 + 1);
                *(ushort *)(puVar10 + 2) = uVar8;
                if ((uVar8 & 0xc) != 0) {
                  puVar3[8] = (puVar3[8] & 0xc000) + 0x4000 ^ puVar3[8] & 0x3fff;
                }
                *(undefined2 *)((int)puVar10 + 10) = 0;
                if ((puVar10[2] & 0x20) == 0) {
                  if ((puVar3[8] & 0x1000) != 0) {
                    *puVar9 = 0xffffffff;
                  }
                }
                else {
                  iVar5 = *piVar13;
                  if (iVar5 == 0) {
                    iVar2 = -0x7ff8ffa9;
                    goto LAB_4046245c;
                  }
                  uVar12 = *puVar10;
                  if ((uVar12 & 0x80000000) == 0) {
                    uVar12 = (uint)*(ushort *)(*(int *)(param_1[4] + 0xd4) + uVar12 + 2);
                  }
                  else {
                    uVar12 = uVar12 >> 0x10 & 0x7fff;
                  }
                  pvargDest = (VARIANTARG *)(iVar5 + 8);
                  if (uVar12 == 0x7ffe) {
LAB_4046271c:
                    iVar2 = -0x7ffd7360;
                    goto LAB_4046245c;
                  }
                  if (uVar12 != 0x7fff) {
                    uVar12 = uVar12 & 0xbfff;
                    vt = (VARTYPE)uVar12;
                    if ((((uVar12 == 8) && ((pvargDest->n1).n2.vt != 8)) || (uVar12 == 9)) ||
                       (uVar12 == 0xd)) {
                      iVar2 = VariantChangeTypeEx(pvargDest,pvargDest,0x400,0,3);
                      if (iVar2 < 0) goto LAB_4046245c;
                      if (*(int *)(iVar5 + 0x10) != 0) goto LAB_4046271c;
LAB_40462638:
                      (pvargDest->n1).n2.vt = vt;
                      uVar7 = local_44;
                    }
                    else {
                      uVar7 = local_44;
                      if (uVar12 != 0xc) {
                        if (uVar12 == 10) {
                          vt = 0x13;
                        }
                        iVar2 = VariantChangeTypeEx(pvargDest,pvargDest,0x400,0,vt);
                        if (iVar2 < 0) goto LAB_4046245c;
                        vt = 10;
                        uVar7 = local_44;
                        if (uVar12 == 10) goto LAB_40462638;
                      }
                    }
                  }
                  iVar2 = FUN_4045f82c(param_1[4],(ushort *)pvargDest,local_40);
                  if (iVar2 < 0) goto LAB_4046245c;
                  local_48[0] = local_48[0] + 0x18;
                  puVar9 = local_40;
                }
                puVar9 = puVar9 + 1;
                local_38 = local_38 + 1;
                puVar10 = puVar10 + 3;
                piVar13 = piVar13 + 4;
                local_40 = puVar9;
              } while (local_38 < uVar7);
            }
            puVar3[7] = (short)param_3[6] * 0x10 + local_48[0] + 0x34;
            if ((*(uint *)(puVar3 + 4) & 0x800) != 0) {
              *(uint *)(local_3c + 0x18) = *(uint *)(local_3c + 0x18) | 0x800;
            }
            *(undefined4 *)(puVar3 + 0x12) = *(undefined4 *)(param_1[4] + 400);
            if (param_1[9] == 0) {
              return 0;
            }
            iVar2 = FUN_4046a418(param_1[9],0,param_1 + 1,0);
            return iVar2;
          }
          iVar2 = -0x7ffd637d;
        }
LAB_4046245c:
        (**(code **)(*param_1 + 0x68))(param_1,local_34);
        return iVar2;
      }
    }
  }
  return -0x7ff8ffa9;
}



/* 40462778 FUN_40462778 */

/* Boundary evidence: original MIPS .pdata 40462778..40462a33. Semantic name remains unreviewed. */

int FUN_40462778(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  short local_30 [2];
  int local_2c;
  
  if (param_3 == (uint *)0x0) {
    return -0x7ff8ffa9;
  }
  if ((param_1[9] == 0) || (iVar1 = FUN_4046a358(param_1[9],0,param_1 + 1,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = param_1[5];
  puVar3 = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
  if (iVar1 == 0) {
    if (param_3[8] != 2) {
      return -0x7ffd7743;
    }
  }
  else if (iVar1 == 1) {
LAB_40462840:
    if (param_3[8] != 0) {
      return -0x7ffd7743;
    }
  }
  else if (iVar1 == 2) {
    if ((param_3[8] != 2) && (param_3[8] != 1)) {
      return -0x7ffd7743;
    }
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 7) {
        return -0x7ffd7743;
      }
      goto LAB_40462840;
    }
    if (param_3[8] != 3) {
      return -0x7ffd7743;
    }
  }
  uVar4 = *param_3;
  iVar1 = FUN_404611b4(uVar4);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_4045b22c((int)(puVar3 + 2),param_2,&local_2c);
  if (iVar1 < 0) {
    return iVar1;
  }
  *puVar3 = *puVar3 & 0xffdf;
  iVar2 = *(int *)(puVar3 + 10) + local_2c;
  *(short *)(iVar2 + 0xc) = (short)param_3[8];
  *(uint *)(iVar2 + 8) = (uint)(ushort)param_3[7];
  *(uint *)((uint)*(ushort *)(iVar2 + 2) * 4 + *(int *)(puVar3 + 0x10)) = uVar4;
  local_30[0] = 0;
  iVar1 = FUN_4045f434((int)param_1,param_3 + 3,(uint *)(iVar2 + 4),local_30);
  if (iVar1 < 0) {
LAB_404629ec:
    (**(code **)(*param_1 + 0x70))(param_1,param_2);
    return iVar1;
  }
  uVar4 = param_3[8];
  if (uVar4 == 0) {
    *(uint *)(iVar2 + 0x10) = param_3[2];
    goto LAB_4046298c;
  }
  if (uVar4 != 1) {
    if (uVar4 == 2) {
      iVar1 = FUN_4045f82c(param_1[4],(ushort *)param_3[2],(uint *)(iVar2 + 0x10));
      if (iVar1 < 0) goto LAB_404629ec;
      local_30[0] = local_30[0] + 0x10;
      goto LAB_4046298c;
    }
    if (uVar4 != 3) goto LAB_4046298c;
  }
  *(undefined4 *)(iVar2 + 0x10) = 0;
LAB_4046298c:
  *(short *)(iVar2 + 0xe) = local_30[0] + 0x24;
  if ((*(uint *)(iVar2 + 8) & 0x800) != 0) {
    *(uint *)(puVar3 + 0x18) = *(uint *)(puVar3 + 0x18) | 0x800;
  }
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_1[4] + 400);
  if (param_1[9] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_4046a418(param_1[9],0,param_1 + 1,0);
  }
  return iVar1;
}



/* 40462a34 FUN_40462a34 */

void FUN_40462a34(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar5 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + 0xac) + param_2);
  iVar6 = 1;
  if (*piVar5 == -1) {
    iVar2 = piVar5[2];
    bVar3 = *(byte *)((int)piVar5 + 9) & 0xf7;
    *(char *)(piVar5 + 2) = (char)iVar2;
    *(byte *)((int)piVar5 + 9) = bVar3;
    if ((*(int *)(param_1 + 0x14) == 3) || (iVar4 = 1, *(int *)(param_1 + 0x14) == 4)) {
      iVar4 = 0;
    }
    *(char *)(piVar5 + 2) = (char)iVar2;
    *(byte *)((int)piVar5 + 9) = ((byte)((uint)(iVar4 << 0xc) >> 8) ^ bVar3) & 0x10 ^ bVar3;
    *piVar5 = *(int *)(param_1 + 0xc);
  }
  else if (*piVar5 != *(int *)(param_1 + 0xc)) {
    *(char *)(piVar5 + 2) = (char)piVar5[2];
    *(byte *)((int)piVar5 + 9) = *(byte *)((int)piVar5 + 9) & 0xef;
  }
  uVar1 = *(ushort *)(piVar5 + 2);
  if ((uVar1 & 0x2000) == 0) {
    if ((*(int *)(param_1 + 0x14) != 2) && (*(int *)(param_1 + 0x14) != 0)) {
      iVar6 = 0;
    }
    bVar3 = (byte)(uVar1 >> 8);
    *(char *)(piVar5 + 2) = (char)uVar1;
    *(byte *)((int)piVar5 + 9) = ((byte)((uint)(iVar6 << 0xd) >> 8) ^ bVar3) & 0x20 ^ bVar3;
  }
  return;
}



/* 40462b60 FUN_40462b60 */

/* Boundary evidence: original MIPS .pdata 40462b60..40462e07. Semantic name remains unreviewed. */

int FUN_40462b60(int param_1,uint param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  ushort uVar9;
  ushort *puVar10;
  int iVar11;
  int local_28 [2];
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7ff8ffa9;
  }
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),2,param_1 + 4,*param_3), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if (param_2 < *(ushort *)(iVar1 + 0x18)) {
    iVar11 = param_2 * 4;
    puVar10 = (ushort *)(*(int *)(iVar1 + 0x14) + *(int *)(*(int *)(iVar1 + 0x28) + iVar11));
    uVar4 = (uint)puVar10[10];
    if ((puVar10[8] & 0x60) != 0) {
      uVar4 = uVar4 - 1;
    }
    if (uVar4 + 1 == param_4) {
      iVar2 = FUN_4045bfa0(*(int *)(param_1 + 0x10),(wchar_t *)*param_3,local_28);
      if (iVar2 < 0) {
        return iVar2;
      }
      piVar5 = (int *)(iVar11 + *(int *)(iVar1 + 0x24));
      iVar2 = *piVar5;
      if (local_28[0] == -1) {
LAB_40462d2c:
        *(int *)(iVar11 + *(int *)(iVar1 + 0x24)) = local_28[0];
        FUN_4045c31c(*(int *)(param_1 + 0x10),iVar2);
        if (local_28[0] != -1) {
          FUN_40462a34(param_1,local_28[0]);
        }
        uVar3 = 0;
        if (uVar4 != 0) {
          piVar5 = (int *)((int)puVar10 + (uint)*puVar10 + (uint)puVar10[10] * -0xc + 4);
          do {
            param_3 = param_3 + 1;
            iVar1 = FUN_4045bfa0(*(int *)(param_1 + 0x10),(wchar_t *)*param_3,piVar5);
            if (iVar1 < 0) {
              return iVar1;
            }
            uVar3 = uVar3 + 1;
            piVar5 = piVar5 + 3;
          } while (uVar3 < uVar4);
        }
        if (*(int *)(param_1 + 0x24) != 0) {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),2,param_1 + 4,0);
          return iVar1;
        }
        return 0;
      }
      *piVar5 = -1;
      uVar7 = 0;
      uVar3 = (uint)*(ushort *)(iVar1 + 0x1a) + (uint)*(ushort *)(iVar1 + 0x18);
      do {
        uVar8 = 0xffffffff;
        if (uVar7 < uVar3) {
          piVar5 = (int *)(*(int *)(iVar1 + 0x24) + uVar7 * 4);
          do {
            uVar8 = uVar7;
            if (*piVar5 == local_28[0]) break;
            uVar7 = uVar7 + 1;
            piVar5 = piVar5 + 1;
            uVar8 = 0xffffffff;
          } while (uVar7 < uVar3);
        }
        if (uVar8 == 0xffffffff) goto LAB_40462d2c;
        if (*(ushort *)(iVar1 + 0x18) <= uVar8) {
LAB_40462d14:
          *(int *)(iVar11 + *(int *)(iVar1 + 0x24)) = iVar2;
          return -0x7ffd7fd4;
        }
        uVar9 = puVar10[8] >> 3 & 0xf;
        if (((uVar9 == 1) ||
            (uVar6 = *(ushort *)
                      (*(int *)(uVar8 * 4 + *(int *)(iVar1 + 0x28)) + *(int *)(iVar1 + 0x14) + 0x10)
                     >> 3 & 0xf, uVar6 == 1)) || (uVar6 == uVar9)) goto LAB_40462d14;
        uVar7 = uVar8 + 1;
      } while( true );
    }
  }
  return -0x7ffd7fd5;
}



/* 40462e08 FUN_40462e08 */

/* Boundary evidence: original MIPS .pdata 40462e08..40462f9f. Semantic name remains unreviewed. */

int FUN_40462e08(int param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int local_20 [2];
  
  if (param_3 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),2,param_1 + 4,param_3), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
      if (param_2 < *(ushort *)(iVar7 + 0x1a)) {
        iVar1 = FUN_4045bfa0(*(int *)(param_1 + 0x10),param_3,local_20);
        if (-1 < iVar1) {
          iVar5 = (*(ushort *)(iVar7 + 0x18) + param_2) * 4;
          piVar2 = (int *)(*(int *)(iVar7 + 0x24) + iVar5);
          iVar1 = *piVar2;
          if (local_20[0] != -1) {
            *piVar2 = -1;
            uVar6 = (uint)*(ushort *)(iVar7 + 0x1a) + (uint)*(ushort *)(iVar7 + 0x18);
            uVar3 = 0;
            uVar4 = 0xffffffff;
            if (uVar6 != 0) {
              piVar2 = *(int **)(iVar7 + 0x24);
              do {
                uVar4 = uVar3;
                if (*piVar2 == local_20[0]) break;
                uVar3 = uVar3 + 1;
                piVar2 = piVar2 + 1;
                uVar4 = 0xffffffff;
              } while (uVar3 < uVar6);
            }
            if (uVar4 != 0xffffffff) {
              *(int *)(*(int *)(iVar7 + 0x24) + iVar5) = iVar1;
              return -0x7ffd7fd4;
            }
          }
          *(int *)(*(int *)(iVar7 + 0x24) + iVar5) = local_20[0];
          FUN_4045c31c(*(int *)(param_1 + 0x10),iVar1);
          if (local_20[0] != -1) {
            FUN_40462a34(param_1,local_20[0]);
          }
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),2,param_1 + 4,0);
          }
        }
      }
      else {
        iVar1 = -0x7ffd7fd5;
      }
    }
  }
  return iVar1;
}



/* 40462fa0 FUN_40462fa0 */

/* Boundary evidence: original MIPS .pdata 40462fa0..40463097. Semantic name remains unreviewed. */

int FUN_40462fa0(int param_1,uint *param_2)

{
  int iVar1;
  ushort *puVar2;
  ushort local_18 [4];
  
  if (param_2 == (uint *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      puVar2 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
      if (*(int *)(param_1 + 0x14) == 6) {
        *puVar2 = *puVar2 & 0xffdf;
        local_18[0] = 0;
        iVar1 = FUN_4045f434(param_1,param_2,(uint *)(puVar2 + 0x2a),(short *)local_18);
        if (-1 < iVar1) {
          puVar2[0x2c] = local_18[0];
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
          }
        }
      }
      else {
        iVar1 = -0x7ffd7743;
      }
    }
  }
  return iVar1;
}



/* 40463098 FUN_40463098 */

/* Boundary evidence: original MIPS .pdata 40463098..4046326b. Semantic name remains unreviewed. */

int FUN_40463098(int param_1,uint param_2,wchar_t *param_3,wchar_t *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_28;
  wchar_t *local_24;
  
  if (param_3 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),2,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = *(int *)(param_1 + 0x10);
      iVar2 = *(int *)(iVar1 + 0x20) + *(int *)(param_1 + 0xc);
      if (*(int *)(param_1 + 0x14) == 2) {
        if (param_2 < *(ushort *)(iVar2 + 0x18)) {
          iVar3 = *(int *)(iVar2 + 0x14) + *(int *)(*(int *)(iVar2 + 0x28) + param_2 * 4);
          if (*(int *)(iVar2 + 0x54) == -1) {
            iVar1 = FUN_4045c1e8(iVar1,param_3,&local_28);
            if (iVar1 < 0) {
              return iVar1;
            }
            *(int *)(iVar2 + 0x54) = local_28;
          }
          else {
            iVar1 = FUN_4045cb14(iVar1,*(int *)(iVar2 + 0x54),&local_24);
            if (iVar1 < 0) {
              return iVar1;
            }
            iVar1 = wcscmp(local_24,param_3);
            SysFreeString(local_24);
            if (iVar1 != 0) {
              iVar1 = FUN_4045c1e8(*(int *)(param_1 + 0x10),param_3,&local_28);
              if (iVar1 < 0) {
                return iVar1;
              }
              *(int *)(iVar3 + 0x28) = local_28;
            }
          }
          if ((uint)param_4 >> 0x10 == 0) {
            *(wchar_t **)(iVar3 + 0x20) = param_4;
            *(ushort *)(iVar3 + 0x10) = *(ushort *)(iVar3 + 0x10) | 0x2000;
          }
          else {
            iVar1 = FUN_4045c1e8(*(int *)(param_1 + 0x10),param_4,(int *)(iVar3 + 0x20));
            if (iVar1 < 0) {
              return iVar1;
            }
          }
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),2,param_1 + 4,0);
          }
        }
        else {
          iVar1 = -0x7ffd7fd5;
        }
      }
      else {
        iVar1 = -0x7ffd7743;
      }
    }
  }
  return iVar1;
}



/* 4046326c FUN_4046326c */

/* Boundary evidence: original MIPS .pdata 4046326c..40463363. Semantic name remains unreviewed. */

int FUN_4046326c(int param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  
  if (param_3 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
      if (param_2 < *(ushort *)(iVar1 + 0x18)) {
        iVar1 = FUN_4045c1e8(*(int *)(param_1 + 0x10),param_3,
                             (int *)(*(int *)(iVar1 + 0x14) +
                                     *(int *)(*(int *)(iVar1 + 0x28) + param_2 * 4) + 0x1c));
        if (-1 < iVar1) {
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
          }
        }
      }
      else {
        iVar1 = -0x7ffd7fd5;
      }
    }
  }
  return iVar1;
}



/* 40463364 FUN_40463364 */

/* Boundary evidence: original MIPS .pdata 40463364..40463463. Semantic name remains unreviewed. */

int FUN_40463364(int param_1,uint param_2,wchar_t *param_3)

{
  int iVar1;
  
  if (param_3 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
      if (param_2 < *(ushort *)(iVar1 + 0x1a)) {
        iVar1 = FUN_4045c1e8(*(int *)(param_1 + 0x10),param_3,
                             (int *)(*(int *)(iVar1 + 0x14) +
                                     *(int *)((*(ushort *)(iVar1 + 0x18) + param_2) * 4 +
                                             *(int *)(iVar1 + 0x28)) + 0x18));
        if (-1 < iVar1) {
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
          }
        }
      }
      else {
        iVar1 = -0x7ffd7fd5;
      }
    }
  }
  return iVar1;
}



/* 40463464 FUN_40463464 */

/* Boundary evidence: original MIPS .pdata 40463464..40463537. Semantic name remains unreviewed. */

int FUN_40463464(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
    if (param_2 < *(ushort *)(iVar1 + 0x18)) {
      *(undefined4 *)
       (*(int *)(iVar1 + 0x14) + *(int *)(*(int *)(iVar1 + 0x28) + param_2 * 4) + 0x18) = param_3;
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40463538 FUN_40463538 */

/* Boundary evidence: original MIPS .pdata 40463538..40463613. Semantic name remains unreviewed. */

int FUN_40463538(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
    if (param_2 < *(ushort *)(iVar1 + 0x1a)) {
      *(undefined4 *)
       (*(int *)(iVar1 + 0x14) +
        *(int *)((*(ushort *)(iVar1 + 0x18) + param_2) * 4 + *(int *)(iVar1 + 0x28)) + 0x14) =
           param_3;
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40463614 FUN_40463614 */

bool FUN_40463614(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0xc <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 40463660 FUN_40463660 */

bool FUN_40463660(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0xe <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 404636ac FUN_404636ac */

bool FUN_404636ac(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0x10 <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 404636f8 FUN_404636f8 */

bool FUN_404636f8(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0x12 <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 40463744 FUN_40463744 */

bool FUN_40463744(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0x14 <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 40463790 FUN_40463790 */

bool FUN_40463790(ushort *param_1)

{
  int iVar1;
  
  iVar1 = 4;
  if ((param_1[8] & 0x1000) == 0) {
    iVar1 = 0;
  }
  return param_1 + 0x16 <
         (ushort *)(((uint)*param_1 - (uint)param_1[10] * (iVar1 + 0xc)) + (int)param_1);
}



/* 404637dc FUN_404637dc */

/* Boundary evidence: original MIPS .pdata 404637dc..40463897. Semantic name remains unreviewed. */

int FUN_404637dc(int param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),1,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if ((-1 < iVar1) &&
     (iVar1 = FUN_4045b574((int)(puVar2 + 2),*(int *)(param_1 + 0x10),param_2), -1 < iVar1)) {
    *puVar2 = *puVar2 & 0xffdf;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),1,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40463898 FUN_40463898 */

/* Boundary evidence: original MIPS .pdata 40463898..40463953. Semantic name remains unreviewed. */

int FUN_40463898(int param_1,uint param_2)

{
  int iVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),1,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if ((-1 < iVar1) &&
     (iVar1 = FUN_4045b514((int)(puVar2 + 2),*(int *)(param_1 + 0x10),param_2), -1 < iVar1)) {
    *puVar2 = *puVar2 & 0xffdf;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),1,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40463954 FUN_40463954 */

/* Boundary evidence: original MIPS .pdata 40463954..40463a03. Semantic name remains unreviewed. */

void FUN_40463954(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  ushort *puVar2;
  uint local_20 [2];
  
  puVar2 = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
  if ((*puVar2 & 0x20) == 0) {
    iVar1 = (**(code **)(*param_1 + 100))(param_1);
  }
  else {
    iVar1 = 0;
  }
  if ((-1 < iVar1) && (iVar1 = FUN_4045a9e4((int)(puVar2 + 2),param_2,param_3,local_20), -1 < iVar1)
     ) {
    (**(code **)(*param_1 + 0x68))(param_1,local_20[0]);
  }
  return;
}



/* 40463a04 FUN_40463a04 */

/* Boundary evidence: original MIPS .pdata 40463a04..40463a5b. Semantic name remains unreviewed. */

void FUN_40463a04(int *param_1,int param_2)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = FUN_4045aa7c(*(int *)(param_1[4] + 0x20) + param_1[3] + 4,param_2,local_10);
  if (-1 < iVar1) {
    (**(code **)(*param_1 + 0x70))(param_1,local_10[0]);
  }
  return;
}



/* 40463a5c FUN_40463a5c */

/* Boundary evidence: original MIPS .pdata 40463a5c..40463b9b. Semantic name remains unreviewed. */

int FUN_40463a5c(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  ushort *puVar4;
  
  puVar4 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if (param_2 < puVar4[0x26]) {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),1,param_1 + 4,0), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      *puVar4 = *puVar4 & 0xffdf;
      if (*(int *)(param_1 + 0x14) == 5) {
        puVar3 = (uint *)(puVar4 + 0x2a);
        uVar2 = *puVar3;
        for (; iVar1 = uVar2 + *(int *)(*(int *)(param_1 + 0x10) + 0x5c), param_2 != 0;
            param_2 = param_2 - 1) {
          puVar3 = (uint *)(iVar1 + 0xc);
          uVar2 = *puVar3;
        }
        uVar2 = *puVar3;
        *puVar3 = *(uint *)(iVar1 + 0xc);
        FUN_4045a488(*(int *)(param_1 + 0x10) + 0x4c,uVar2,0x10);
      }
      else {
        puVar4[0x2a] = 0xffff;
        puVar4[0x2b] = 0xffff;
      }
      puVar4[0x26] = puVar4[0x26] - 1;
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),1,param_1 + 4,0);
      }
    }
  }
  else {
    iVar1 = -0x7ffd7fd5;
  }
  return iVar1;
}



/* 40463b9c FUN_40463b9c */

/* Boundary evidence: original MIPS .pdata 40463b9c..40463c5b. Semantic name remains unreviewed. */

int FUN_40463b9c(int param_1,uint *param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if ((-1 < iVar1) &&
     (iVar1 = FUN_4045fb60(*(int *)(param_1 + 0x10),param_2,param_3,(int *)(iVar3 + iVar2 + 0x48)),
     -1 < iVar1)) {
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40463c5c FUN_40463c5c */

/* Boundary evidence: original MIPS .pdata 40463c5c..40463d67. Semantic name remains unreviewed. */

int FUN_40463c5c(int param_1,uint param_2,uint *param_3,ushort *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 < *(ushort *)(iVar2 + 0x18)) {
      iVar2 = *(int *)(iVar2 + 0x14) + *(int *)(*(int *)(iVar2 + 0x28) + param_2 * 4);
      iVar1 = FUN_4045fb60(*(int *)(param_1 + 0x10),param_3,param_4,(int *)(iVar2 + 0x30));
      if (-1 < iVar1) {
        *(ushort *)(iVar2 + 0x10) = *(ushort *)(iVar2 + 0x10) | 0x80;
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
        }
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40463d68 FUN_40463d68 */

/* Boundary evidence: original MIPS .pdata 40463d68..40463e8b. Semantic name remains unreviewed. */

int FUN_40463d68(int param_1,uint param_2,uint param_3,uint *param_4,ushort *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if ((param_2 < *(ushort *)(iVar2 + 0x18)) &&
       (iVar2 = *(int *)(iVar2 + 0x14) + *(int *)(*(int *)(iVar2 + 0x28) + param_2 * 4),
       param_3 < *(ushort *)(iVar2 + 0x14))) {
      iVar1 = FUN_4045fb60(*(int *)(param_1 + 0x10),param_4,param_5,
                           (int *)((param_3 + 0xd) * 4 + iVar2));
      if (-1 < iVar1) {
        *(ushort *)(iVar2 + 0x10) = *(ushort *)(iVar2 + 0x10) | 0x80;
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
        }
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40463e8c FUN_40463e8c */

/* Boundary evidence: original MIPS .pdata 40463e8c..40463f93. Semantic name remains unreviewed. */

int FUN_40463e8c(int param_1,uint param_2,uint *param_3,ushort *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 < *(ushort *)(iVar2 + 0x1a)) {
      iVar1 = FUN_4045fb60(*(int *)(param_1 + 0x10),param_3,param_4,
                           (int *)(*(int *)(iVar2 + 0x14) +
                                   *(int *)((*(ushort *)(iVar2 + 0x18) + param_2) * 4 +
                                           *(int *)(iVar2 + 0x28)) + 0x20));
      if (-1 < iVar1) {
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
        }
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40463f94 FUN_40463f94 */

/* Boundary evidence: original MIPS .pdata 40463f94..404640b3. Semantic name remains unreviewed. */

int FUN_40463f94(int param_1,uint param_2,uint *param_3,ushort *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),4,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (*(int *)(param_1 + 0x14) == 5) {
      if (param_2 < *(ushort *)(iVar2 + 0x4c)) {
        iVar2 = *(int *)(iVar2 + 0x54);
        for (; iVar2 = iVar2 + *(int *)(*(int *)(param_1 + 0x10) + 0x5c), param_2 != 0;
            param_2 = param_2 - 1) {
          iVar2 = *(int *)(iVar2 + 0xc);
        }
        iVar1 = FUN_4045fb60(*(int *)(param_1 + 0x10),param_3,param_4,(int *)(iVar2 + 8));
        if (-1 < iVar1) {
          if (*(int *)(param_1 + 0x24) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),4,param_1 + 4,0);
          }
        }
      }
      else {
        iVar1 = -0x7ffd7fd5;
      }
    }
    else {
      iVar1 = -0x7ffd7743;
    }
  }
  return iVar1;
}



/* 404640b4 FUN_404640b4 */

/* Boundary evidence: original MIPS .pdata 404640b4..4046414f. Semantic name remains unreviewed. */

int FUN_404640b4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20);
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    *(undefined4 *)(iVar3 + iVar2 + 0x40) = param_2;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40464150 FUN_40464150 */

/* Boundary evidence: original MIPS .pdata 40464150..4046422b. Semantic name remains unreviewed. */

int FUN_40464150(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 < *(ushort *)(iVar2 + 0x18)) {
      *(undefined4 *)
       (*(int *)(iVar2 + 0x14) + *(int *)(*(int *)(iVar2 + 0x28) + param_2 * 4) + 0x2c) = param_3;
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 4046422c FUN_4046422c */

/* Boundary evidence: original MIPS .pdata 4046422c..4046430f. Semantic name remains unreviewed. */

int FUN_4046422c(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),3,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (param_2 < *(ushort *)(iVar2 + 0x1a)) {
      *(undefined4 *)
       (*(int *)(iVar2 + 0x14) +
        *(int *)((*(ushort *)(iVar2 + 0x18) + param_2) * 4 + *(int *)(iVar2 + 0x28)) + 0x24) =
           param_3;
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),3,param_1 + 4,0);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40464310 FUN_40464310 */

/* Boundary evidence: original MIPS .pdata 40464310..40464387. Semantic name remains unreviewed. */

int FUN_40464310(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x24) == 0) ||
     (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),5,param_1 + 4,0), -1 < iVar1)) {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),5,param_1 + 4,0);
    }
  }
  return iVar1;
}



/* 40464388 FUN_40464388 */

/* Boundary evidence: original MIPS .pdata 40464388..404644f7. Semantic name remains unreviewed. */

int FUN_40464388(int param_1,wchar_t *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20 [2];
  
  if (param_2 == (wchar_t *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    if ((*(int *)(param_1 + 0x24) == 0) ||
       (iVar1 = FUN_4046a358(*(int *)(param_1 + 0x24),2,param_1 + 4,param_2), -1 < iVar1)) {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
      iVar1 = FUN_4045bfa0(*(int *)(param_1 + 0x10),param_2,local_20);
      if (-1 < iVar1) {
        iVar1 = *(int *)(iVar3 + 0x34);
        if (local_20[0] != iVar1) {
          if (local_20[0] != -1) {
            piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + 0xac) + local_20[0]);
            if ((*(byte *)((int)piVar2 + 9) & 8) != 0) {
              return -0x7ffd7fd3;
            }
            FUN_40460998(param_1,iVar3,local_20[0],piVar2);
          }
          if (iVar1 != -1) {
            piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x10) + 0xac) + iVar1);
            *(char *)(piVar2 + 2) = (char)piVar2[2];
            *(byte *)((int)piVar2 + 9) = *(byte *)((int)piVar2 + 9) & 0xf7;
            FUN_4045d830(*(int *)(param_1 + 0x10),iVar1,piVar2);
          }
        }
        if (*(int *)(param_1 + 0x24) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = FUN_4046a418(*(int *)(param_1 + 0x24),2,param_1 + 4,0);
        }
      }
    }
  }
  return iVar1;
}



/* 404644f8 FUN_404644f8 */

/* Boundary evidence: original MIPS .pdata 404644f8..40464723. Semantic name remains unreviewed. */

int FUN_404644f8(int *param_1,undefined4 *param_2)

{
  OLECHAR OVar1;
  ushort uVar2;
  BSTR pOVar3;
  UINT len;
  undefined4 *puVar4;
  int iVar5;
  ushort *puVar6;
  BSTR local_28 [2];
  
  if (param_2 == (undefined4 *)0x0) {
    iVar5 = -0x7ff8ffa9;
  }
  else {
    puVar6 = (ushort *)(*(int *)(param_1[3] + 0x20) + param_1[2]);
    if ((*puVar6 & 0x20) == 0) {
      iVar5 = (**(code **)(param_1[-1] + 100))();
    }
    else {
      iVar5 = 0;
    }
    if (-1 < iVar5) {
      iVar5 = param_1[4];
      if (iVar5 == 6) {
        len = puVar6[0x2c] + 0x4c;
      }
      else {
        len = 0x4c;
      }
      pOVar3 = SysAllocStringByteLen((LPCSTR)0x0,len);
      if (pOVar3 == (BSTR)0x0) {
        iVar5 = -0x7ff8fff2;
      }
      else {
        if (*(int *)(puVar6 + 0x16) == -1) {
          puVar4 = &DAT_40443ecc;
        }
        else {
          puVar4 = (undefined4 *)(*(int *)(param_1[3] + 0x84) + *(int *)(puVar6 + 0x16));
        }
        *(undefined4 *)pOVar3 = *puVar4;
        *(undefined4 *)(pOVar3 + 2) = puVar4[1];
        *(undefined4 *)(pOVar3 + 4) = puVar4[2];
        *(undefined4 *)(pOVar3 + 6) = puVar4[3];
        *(undefined4 *)(pOVar3 + 8) = *(undefined4 *)(param_1[3] + 0x144);
        pOVar3[10] = L'\0';
        pOVar3[0xb] = L'\0';
        pOVar3[0xc] = L'\xffff';
        pOVar3[0xd] = L'\xffff';
        pOVar3[0xe] = L'\xffff';
        pOVar3[0xf] = L'\xffff';
        pOVar3[0x10] = L'\0';
        pOVar3[0x11] = L'\0';
        pOVar3[0x17] = puVar6[0xd];
        pOVar3[0x1c] = puVar6[0x1c];
        pOVar3[0x1d] = puVar6[0x1d];
        pOVar3[0x22] = L'\0';
        pOVar3[0x23] = L'\0';
        pOVar3[0x24] = L'\0';
        *(int *)(pOVar3 + 0x14) = iVar5;
        pOVar3[0x18] = puVar6[0x26];
        pOVar3[0x1a] = *puVar6 >> 0xb;
        *(undefined4 *)(pOVar3 + 0x12) = *(undefined4 *)(puVar6 + 0x28);
        OVar1 = puVar6[0xc];
        if (iVar5 == 4) {
          uVar2 = puVar6[0x2d];
          pOVar3[0x19] = L'\x1c';
          pOVar3[0x16] = uVar2 + OVar1;
          pOVar3[0x1b] = (ushort)*(undefined4 *)(puVar6 + 0x18) & 0x1ad0;
        }
        else {
          pOVar3[0x16] = OVar1;
          pOVar3[0x19] = puVar6[0x27];
          pOVar3[0x1b] = (OLECHAR)*(undefined4 *)(puVar6 + 0x18);
          if (iVar5 == 6) {
            local_28[0] = pOVar3 + 0x26;
            if ((*(uint *)(puVar6 + 0x2a) != 0xffffffff) &&
               (iVar5 = FUN_4045fce8(param_1[3],*(uint *)(puVar6 + 0x2a),(uint *)(pOVar3 + 0x1e),0,
                                     (uint *)local_28), iVar5 < 0)) {
              (**(code **)(*param_1 + 0x4c))(param_1,pOVar3);
              return iVar5;
            }
          }
        }
        *param_2 = pOVar3;
        iVar5 = 0;
      }
    }
  }
  return iVar5;
}



/* 40464724 FUN_40464724 */

/* Boundary evidence: original MIPS .pdata 40464724..4046495f. Semantic name remains unreviewed. */

int FUN_40464724(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  BSTR pOVar2;
  int iVar3;
  ushort *puVar4;
  BSTR local_28 [2];
  
  if (param_3 == (undefined4 *)0x0) {
    return -0x7ff8ffa9;
  }
  *param_3 = 0;
  puVar4 = (ushort *)(*(int *)(param_1[3] + 0x20) + param_1[2]);
  if ((*puVar4 & 0x20) == 0) {
    iVar1 = (**(code **)(param_1[-1] + 100))();
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((*(uint *)(puVar4 + 8) & 8) == 0) {
    iVar1 = FUN_4045a504((int *)(puVar4 + 2),param_1[3],0);
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if (puVar4[0xd] <= param_2) {
    return -0x7ffd7fd5;
  }
  iVar1 = *(int *)(puVar4 + 10) + *(int *)((puVar4[0xc] + param_2) * 4 + *(int *)(puVar4 + 0x14));
  pOVar2 = SysAllocStringByteLen((LPCSTR)0x0,(uint)*(ushort *)(iVar1 + 0xe));
  if (pOVar2 == (BSTR)0x0) {
    return -0x7ff8fff2;
  }
  local_28[0] = pOVar2 + 0x12;
  *(undefined4 *)pOVar2 =
       *(undefined4 *)((uint)*(ushort *)(iVar1 + 2) * 4 + *(int *)(puVar4 + 0x10));
  pOVar2[2] = L'\0';
  pOVar2[3] = L'\0';
  *(uint *)(pOVar2 + 0x10) = (uint)*(ushort *)(iVar1 + 0xc);
  pOVar2[0xe] = (OLECHAR)*(undefined4 *)(iVar1 + 8);
  iVar3 = *(int *)(pOVar2 + 0x10);
  if (iVar3 == 0) {
    *(undefined4 *)(pOVar2 + 4) = *(undefined4 *)(iVar1 + 0x10);
  }
  else if (iVar3 == 1) {
LAB_40464898:
    pOVar2[4] = L'\0';
    pOVar2[5] = L'\0';
  }
  else if (iVar3 == 2) {
    *(BSTR *)(pOVar2 + 4) = local_28[0];
    iVar3 = FUN_40460228(param_1[3],*(uint *)(iVar1 + 0x10),local_28[0]);
    if (iVar3 < 0) goto LAB_40464908;
    local_28[0] = local_28[0] + 8;
  }
  else if (iVar3 == 3) goto LAB_40464898;
  pOVar2[10] = L'\0';
  pOVar2[0xb] = L'\0';
  pOVar2[0xc] = L'\0';
  iVar3 = FUN_4045fce8(param_1[3],*(uint *)(iVar1 + 4),(uint *)(pOVar2 + 6),0,(uint *)local_28);
  if (-1 < iVar3) {
    *param_3 = pOVar2;
    return 0;
  }
LAB_40464908:
  (**(code **)(*param_1 + 0x54))(param_1,pOVar2);
  return iVar3;
}



/* 40464960 FUN_40464960 */

/* Boundary evidence: original MIPS .pdata 40464960..40464ab7. Semantic name remains unreviewed. */

int FUN_40464960(int param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 == (uint *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  iVar5 = *(int *)(iVar4 + 0x20) + *(int *)(param_1 + 8);
  if (param_2 < *(ushort *)(iVar5 + 0x4c)) {
    iVar2 = *(int *)(param_1 + 0x10);
    if (iVar2 == 3) {
      *param_3 = *(uint *)(iVar5 + 0x54) | 2;
      return 0;
    }
    if (iVar2 != 4) {
      if (iVar2 != 5) {
        return 0;
      }
      if ((*(uint *)(iVar4 + 0x58) & 8) == 0) {
        iVar4 = FUN_4045a028((int *)(iVar4 + 0x4c),iVar4);
      }
      else {
        iVar4 = 0;
      }
      if (-1 < iVar4) {
        uVar3 = *(uint *)(iVar5 + 0x54);
        for (; puVar1 = (uint *)(uVar3 + *(int *)(*(int *)(param_1 + 0xc) + 0x5c)), param_2 != 0;
            param_2 = param_2 - 1) {
          uVar3 = puVar1[3];
        }
        *param_3 = *puVar1 & 0xfffffffd;
        return 0;
      }
      return iVar4;
    }
    uVar3 = *(uint *)(iVar4 + 0x184);
  }
  else {
    if ((param_2 != 0xffffffff) || ((*(uint *)(iVar5 + 0x30) & 0x40) == 0)) {
      return -0x7ffd7fd5;
    }
    uVar3 = 0xfffffffe;
  }
  *param_3 = uVar3;
  return 0;
}



/* 40464ab8 FUN_40464ab8 */

/* Boundary evidence: original MIPS .pdata 40464ab8..40464ba3. Semantic name remains unreviewed. */

int FUN_40464ab8(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = *(int *)(param_1 + 0xc);
    iVar2 = *(int *)(iVar1 + 0x20) + *(int *)(param_1 + 8);
    if (param_2 < *(ushort *)(iVar2 + 0x4c)) {
      if (*(int *)(param_1 + 0x10) == 5) {
        if ((*(uint *)(iVar1 + 0x58) & 8) == 0) {
          iVar1 = FUN_4045a028((int *)(iVar1 + 0x4c),iVar1);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar1 = *(int *)(iVar2 + 0x54);
        for (; iVar1 = iVar1 + *(int *)(*(int *)(param_1 + 0xc) + 0x5c), param_2 != 0;
            param_2 = param_2 - 1) {
          iVar1 = *(int *)(iVar1 + 0xc);
        }
        *param_3 = *(undefined4 *)(iVar1 + 4);
      }
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40464ba4 FUN_40464ba4 */

/* Boundary evidence: original MIPS .pdata 40464ba4..40464db7. Semantic name remains unreviewed. */

int FUN_40464ba4(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5,
                undefined2 *param_6)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ushort *puVar3;
  ushort *puVar4;
  uint local_30 [2];
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined2 *)0x0) {
    *param_6 = 0;
  }
  puVar4 = (ushort *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8));
  if ((*puVar4 & 0x20) == 0) {
    iVar2 = (**(code **)(*(int *)(param_1 + -4) + 100))();
  }
  else {
    iVar2 = 0;
  }
  if (-1 < iVar2) {
    if (*(int *)(param_1 + 0x10) == 2) {
      if ((*(uint *)(puVar4 + 8) & 8) == 0) {
        iVar2 = FUN_4045a504((int *)(puVar4 + 2),*(int *)(param_1 + 0xc),0);
      }
      else {
        iVar2 = 0;
      }
      if ((-1 < iVar2) &&
         (iVar2 = FUN_4045a9e4((int)(puVar4 + 2),param_2,param_3,local_30), -1 < iVar2)) {
        puVar3 = (ushort *)
                 (*(int *)(*(int *)(puVar4 + 0x14) + local_30[0] * 4) + *(int *)(puVar4 + 10));
        if (param_4 != (undefined4 *)0x0) {
          bVar1 = FUN_40463744(puVar3);
          if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar2 = *(int *)(puVar3 + 0x14), iVar2 == -1))
          {
            iVar2 = *(int *)(puVar4 + 0x2a);
          }
          iVar2 = FUN_4045cb14(*(int *)(param_1 + 0xc),iVar2,param_4);
          if (iVar2 < 0) {
            return iVar2;
          }
        }
        if ((puVar3[8] & 0x2000) == 0) {
          if (((param_5 != (undefined4 *)0x0) &&
              (bVar1 = FUN_404636ac(puVar3), CONCAT31(extraout_var_00,bVar1) != 0)) &&
             (iVar2 = FUN_4045cb14(*(int *)(param_1 + 0xc),*(int *)(puVar3 + 0x10),param_5),
             iVar2 < 0)) {
            SysFreeString((BSTR)*param_4);
            *param_4 = 0;
            return iVar2;
          }
        }
        else if (param_6 != (undefined2 *)0x0) {
          *param_6 = (short)*(undefined4 *)(puVar3 + 0x10);
        }
        iVar2 = 0;
      }
    }
    else {
      iVar2 = -0x7ffd7743;
    }
  }
  return iVar2;
}



/* 40464db8 FUN_40464db8 */

/* Boundary evidence: original MIPS .pdata 40464db8..404650fb. Semantic name remains unreviewed. */

int FUN_40464db8(int param_1,int param_2,ushort *param_3,int *param_4)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  wchar_t *pwVar3;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  HMODULE hLibModule;
  ushort *local_238;
  wchar_t local_230 [260];
  uint local_28;
  
  local_28 = DAT_4046d1b8;
  iVar5 = *(int *)(param_1 + 0x10);
  if ((*(uint *)(iVar5 + 0xbc) & 8) == 0) {
    iVar5 = FUN_4045a028((int *)(iVar5 + 0xb0),iVar5);
  }
  else {
    iVar5 = 0;
  }
  if (-1 < iVar5) {
    bVar1 = FUN_40463744(param_3);
    if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar5 = *(int *)(param_3 + 0x14), iVar5 == -1)) {
      iVar5 = *(int *)(param_2 + 0x54);
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((iVar5 == -1) || (bVar2 = FUN_404636ac(param_3), CONCAT31(extraout_var_00,bVar2) == 0)) {
      FUN_4046ace8(local_28);
      return -0x7ffd7fd1;
    }
    iVar6 = *(int *)(*(int *)(param_1 + 0x10) + 0xc0);
    puVar7 = (ushort *)(iVar6 + iVar5);
    if ((param_3[8] & 0x2000) == 0) {
      local_238 = (ushort *)(*(int *)(param_3 + 0x10) + iVar6);
    }
    memcpy(local_230,puVar7 + 1,(uint)*puVar7);
    local_230[*puVar7] = L'\0';
    if ((local_230[0] == L'\\') || (pwVar3 = wcschr(local_230,L':'), pwVar3 != (wchar_t *)0x0)) {
      pwVar3 = wcsrchr(local_230,L'\\');
      if (pwVar3 == (wchar_t *)0x0) {
        pwVar3 = wcsrchr(local_230,L':');
      }
      wcscpy(local_230,pwVar3);
    }
    hLibModule = *(HMODULE *)(param_1 + 0x18);
    if ((hLibModule < (HMODULE)0x20) || (bVar1)) {
      hLibModule = LoadLibraryW(local_230);
      DVar4 = GetLastError();
      if (hLibModule < (HMODULE)0x20) {
        if (DVar4 == 0) {
          FUN_4046ace8(local_28);
          return -0x7ff8fff2;
        }
        if (DVar4 != 2) {
          if (DVar4 == 3) {
            FUN_4046ace8(local_28);
            return -0x7ffcfffd;
          }
          if ((DVar4 < 0x7e) || (0x7f < DVar4)) {
            FUN_4046ace8(local_28);
            return -0x7ffd63b6;
          }
        }
        FUN_4046ace8(local_28);
        return -0x7ffcfffe;
      }
    }
    iVar5 = 0;
    if ((param_3[8] & 0x2000) == 0) {
      memcpy(local_230,local_238 + 1,(uint)*local_238);
      local_230[*local_238] = L'\0';
      pwVar3 = local_230;
    }
    else {
      pwVar3 = (wchar_t *)(uint)param_3[0x10];
    }
    iVar6 = GetProcAddressW(hLibModule,pwVar3);
    *param_4 = iVar6;
    if (iVar6 == 0) {
      iVar5 = -0x7ffd7fd1;
    }
    if (bVar1) {
      FreeLibrary(hLibModule);
    }
    else {
      *(HMODULE *)(param_1 + 0x18) = hLibModule;
    }
  }
  FUN_4046ace8(local_28);
  return iVar5;
}



/* 404650fc FUN_404650fc */

/* Boundary evidence: original MIPS .pdata 404650fc..40465133. Semantic name remains unreviewed. */

int FUN_404650fc(int param_1,uint param_2,void *param_3,undefined2 *param_4)

{
  int iVar1;
  
  if (param_4 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    iVar1 = FUN_40460fd8(param_1 + -4,param_2,param_3,param_4,(int *)0x0);
  }
  return iVar1;
}



/* 40465134 FUN_40465134 */

/* Boundary evidence: original MIPS .pdata 40465134..40465173. Semantic name remains unreviewed. */

int FUN_40465134(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_40460fd8(param_1 + -4,param_2,(void *)0x0,(undefined2 *)0x0,param_3);
  }
  return iVar1;
}



/* 40465174 FUN_40465174 */

/* Boundary evidence: original MIPS .pdata 40465174..4046525f. Semantic name remains unreviewed. */

int FUN_40465174(int param_1,uint param_2,void *param_3,undefined2 *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(iVar1 + 0x20) + *(int *)(param_1 + 0xc);
  if ((param_2 < *(ushort *)(iVar2 + 0x4c)) && (*(int *)(param_1 + 0x14) == 5)) {
    if ((*(uint *)(iVar1 + 0x58) & 8) == 0) {
      iVar1 = FUN_4045a028((int *)(iVar1 + 0x4c),iVar1);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = *(int *)(iVar2 + 0x54);
      for (; iVar1 = iVar1 + *(int *)(*(int *)(param_1 + 0x10) + 0x5c), param_2 != 0;
          param_2 = param_2 - 1) {
        iVar1 = *(int *)(iVar1 + 0xc);
      }
      iVar1 = FUN_40460428(*(int *)(param_1 + 0x10),*(int *)(iVar1 + 8),param_3,param_4,param_5);
    }
  }
  else {
    iVar1 = -0x7ffd7fd5;
  }
  return iVar1;
}



/* 40465260 FUN_40465260 */

/* Boundary evidence: original MIPS .pdata 40465260..404653ff. Semantic name remains unreviewed. */

int FUN_40465260(int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *local_20 [2];
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 == 3) {
    puVar2 = *(undefined4 **)(param_2 + 0x54);
  }
  else if (iVar1 == 4) {
    puVar2 = *(undefined4 **)(param_2 + 0x54);
    if (*(undefined4 **)(param_2 + 0x54) == (undefined4 *)0xffffffff) {
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x184);
    }
  }
  else {
    puVar2 = local_20[0];
    if (iVar1 == 5) {
      iVar1 = *(int *)(param_1 + 0x10);
      if ((*(uint *)(iVar1 + 0x58) & 8) == 0) {
        iVar1 = FUN_4045a028((int *)(iVar1 + 0x4c),iVar1);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar3 = *(uint *)(param_2 + 0x54);
      if (uVar3 != 0xffffffff) {
        do {
          puVar4 = (uint *)(*(int *)(*(int *)(param_1 + 0x10) + 0x5c) + uVar3);
          if ((puVar4[1] & 3) == 1) {
            puVar2 = (undefined4 *)(*puVar4 & 0xfffffffd);
            goto LAB_40465374;
          }
          uVar3 = puVar4[3];
        } while (uVar3 != 0xffffffff);
      }
      return -0x7ffd7fd5;
    }
  }
LAB_40465374:
  iVar1 = (**(code **)(*(int *)(param_1 + 4) + 0x38))((int *)(param_1 + 4),puVar2,local_20);
  if (-1 < iVar1) {
    if (param_3 == (uint *)0x0) {
      if (local_20[0] == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = local_20[0] + -1;
      }
      *param_4 = puVar2;
    }
    else {
      *param_3 = (uint)local_20[0];
      if (param_4 != (undefined4 *)0x0) {
        (**(code **)*local_20[0])(local_20[0],&DAT_40441cfc,param_4);
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40465400 FUN_40465400 */

/* Boundary evidence: original MIPS .pdata 40465400..404658c3. Semantic name remains unreviewed. */

int FUN_40465400(int param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  ushort uVar8;
  int *local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  int *local_2c;
  
  local_48 = (int *)0x0;
  puVar5 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if ((*puVar5 & 0x20) != 0) {
    return 0;
  }
  uVar7 = *(uint *)(puVar5 + 0x28);
  if (uVar7 == 0xffffffff) {
    return -0x7ffd637c;
  }
  puVar5[0x28] = 0xffff;
  puVar5[0x29] = 0xffff;
  uVar8 = 0;
  local_38 = 0;
  local_44 = 0;
  local_40 = 1;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    goto switchD_404654b8_caseD_0;
  case 1:
  case 7:
    iVar2 = FUN_4045abd0((int)(puVar5 + 2),puVar5,&local_44,&local_40);
    goto LAB_40465800;
  case 2:
    local_44 = 2;
    break;
  case 3:
    goto switchD_404654b8_caseD_3;
  case 4:
    if ((((*puVar5 & 0x10) != 0) && (*(int *)(param_1 + 0x1c) == 0)) &&
       ((puVar5[0xc] != 0 || (puVar5[0xd] != 0)))) {
      return -0x7ffd7743;
    }
switchD_404654b8_caseD_3:
    uVar3 = 0;
    if (*(int *)(puVar5 + 0x2a) != -1) {
      iVar2 = FUN_40465260(param_1,(int)puVar5,(uint *)&local_48,&local_3c);
      if (iVar2 < 0) goto LAB_40465870;
      if (local_3c == (int *)0x0) {
        iVar2 = (**(code **)(*local_48 + 0xc))(local_48,&local_34);
        if (iVar2 < 0) goto LAB_40465870;
        local_38 = (uint)*(ushort *)(local_34 + 0x32);
        (**(code **)(*local_48 + 0x4c))();
        uVar8 = 1;
        while (iVar2 = (**(code **)(*local_48 + 0x20))(local_48,0,&local_30), iVar2 == 0) {
          iVar2 = (**(code **)(*local_48 + 0x38))(local_48,local_30,&local_2c);
          if (iVar2 < 0) goto LAB_40465870;
          (**(code **)(*local_48 + 8))();
          local_48 = local_2c;
          iVar2 = (**(code **)(*local_2c + 0xc))(local_2c,&local_34);
          if (iVar2 < 0) goto LAB_40465870;
          uVar3 = *(short *)(local_34 + 0x2c) + uVar3;
          (**(code **)(*local_48 + 0x4c))();
        }
      }
      else {
        iVar2 = (**(code **)(*local_3c + 100))();
        if (iVar2 == 0) {
          iVar1 = *(int *)(local_3c[4] + 0x20) + local_3c[3];
          local_38 = (uint)*(ushort *)(iVar1 + 0x4e);
          uVar3 = *(short *)(iVar1 + 0x5a) + *(short *)(iVar1 + 0x18);
          uVar8 = *(short *)(iVar1 + 0x58) + 1;
        }
        (**(code **)(*local_3c + 8))();
        if (iVar2 < 0) goto LAB_40465870;
      }
    }
    puVar5[0x2c] = uVar8;
    puVar5[0x2d] = uVar3;
    iVar2 = FUN_4045ab04((int)(puVar5 + 2),&local_38);
    if (iVar2 < 0) goto LAB_40465870;
    goto switchD_404654b8_caseD_0;
  case 5:
    iVar2 = *(int *)(param_1 + 0x10);
    if ((*(uint *)(iVar2 + 0x58) & 8) == 0) {
      iVar2 = FUN_4045a028((int *)(iVar2 + 0x4c),iVar2);
    }
    else {
      iVar2 = 0;
    }
    if (iVar2 < 0) goto LAB_40465870;
    uVar4 = (uint)puVar5[0x26];
    iVar2 = *(int *)(puVar5 + 0x2a);
    if (uVar4 != 0) {
      do {
        puVar6 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + 0x5c) + iVar2);
        uVar4 = uVar4 - 1;
        iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x38))((int *)(param_1 + 4),*puVar6,&local_48);
        if (iVar2 < 0) goto LAB_40465870;
        iVar1 = (**(code **)*local_48)(local_48,&DAT_40441cfc,&local_3c);
        if (iVar1 == 0) {
          iVar2 = (**(code **)(*local_3c + 100))();
          (**(code **)(*local_3c + 8))();
        }
        (**(code **)(*local_48 + 8))();
        local_48 = (int *)0x0;
        if (iVar2 < 0) goto LAB_40465870;
        iVar2 = puVar6[3];
      } while (uVar4 != 0);
    }
    local_38 = 0;
switchD_404654b8_caseD_0:
    local_44 = 4;
    local_40 = 4;
    break;
  case 6:
    iVar2 = FUN_4045ffc4(param_1,*(uint *)(puVar5 + 0x2a),&local_44,&local_40);
LAB_40465800:
    if (iVar2 < 0) goto LAB_40465870;
  }
  iVar2 = FUN_4045b618((int)(puVar5 + 2),*(int *)(param_1 + 0x10),local_48,uVar8);
  if (-1 < iVar2) {
    puVar5[0x27] = (ushort)local_38;
    uVar4 = *puVar5 >> 6 & 0x1f;
    uVar7 = local_40;
    if (uVar4 <= local_40) {
      uVar7 = uVar4;
    }
    *puVar5 = *puVar5 & 0x7df | (ushort)(uVar7 << 0xb) | 0x20;
    uVar7 = local_44;
  }
LAB_40465870:
  *(uint *)(puVar5 + 0x28) = uVar7;
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))();
  }
  return iVar2;
}



/* 404658c4 FUN_404658c4 */

/* Boundary evidence: original MIPS .pdata 404658c4..40465d37. Semantic name remains unreviewed. */

int FUN_404658c4(int param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  OLECHAR OVar1;
  ushort uVar2;
  int iVar3;
  BSTR pOVar4;
  undefined4 *puVar5;
  BSTR pOVar6;
  ushort *puVar7;
  int iVar8;
  uint *puVar9;
  BSTR pOVar10;
  BSTR pOVar11;
  int *piVar12;
  int iVar13;
  BSTR local_40;
  int *local_3c;
  uint local_38;
  uint *local_34;
  undefined4 *local_30;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  iVar13 = 0;
  local_30 = param_3;
  if ((param_4 & 1) != 0) {
    if (param_2 < *(ushort *)(iVar8 + 0x5a)) {
      iVar8 = FUN_40465260(param_1,iVar8,(uint *)0x0,&local_3c);
      if (iVar8 < 0) {
        return iVar8;
      }
      iVar8 = FUN_404658c4((int)local_3c,param_2,param_3,param_4);
      (**(code **)(*local_3c + 8))();
      return iVar8;
    }
    param_2 = param_2 - *(ushort *)(iVar8 + 0x5a);
    iVar13 = *(ushort *)(iVar8 + 0x58) + 1;
  }
  if ((*(uint *)(iVar8 + 0x10) & 8) == 0) {
    iVar3 = FUN_4045a504((int *)(iVar8 + 4),*(int *)(param_1 + 0x10),0);
  }
  else {
    iVar3 = 0;
  }
  if (-1 < iVar3) {
    if (param_2 < *(ushort *)(iVar8 + 0x18)) {
      puVar7 = (ushort *)(*(int *)(iVar8 + 0x14) + *(int *)(*(int *)(iVar8 + 0x28) + param_2 * 4));
      pOVar4 = SysAllocStringByteLen((LPCSTR)0x0,(uint)puVar7[7]);
      if (pOVar4 == (BSTR)0x0) {
        iVar3 = -0x7ff8fff2;
      }
      else {
        piVar12 = (int *)(param_4 & 2);
        *(undefined4 *)pOVar4 = *(undefined4 *)((uint)puVar7[1] * 4 + *(int *)(iVar8 + 0x20));
        pOVar4[2] = L'\0';
        pOVar4[3] = L'\0';
        *(uint *)(pOVar4 + 8) = puVar7[8] >> 3 & 0xf;
        *(uint *)(pOVar4 + 10) = *(byte *)((int)puVar7 + 0x11) & 0xf;
        OVar1 = puVar7[10];
        if (piVar12 == (int *)0x0) {
          pOVar4[0xc] = OVar1;
          *(uint *)(pOVar4 + 6) = puVar7[8] & 7;
        }
        else {
          uVar2 = puVar7[8];
          pOVar4[6] = L'\x04';
          pOVar4[7] = L'\0';
          pOVar4[0xc] = OVar1 - (uVar2 >> 0xe);
        }
        if (*(int *)(pOVar4 + 6) == 4) {
          pOVar4[0xe] = L'\0';
        }
        else {
          pOVar4[0xe] = puVar7[6] & 0xfffc;
        }
        pOVar10 = pOVar4 + 0x10;
        pOVar4[0xd] = puVar7[0xb];
        pOVar4[0xf] = L'\0';
        pOVar4[0x18] = (OLECHAR)*(undefined4 *)(puVar7 + 4);
        local_40 = pOVar4 + 0x1a;
        pOVar4[0x14] = L'\0';
        pOVar4[0x15] = L'\0';
        pOVar4[0x16] = L'\0';
        local_3c = piVar12;
        iVar3 = FUN_4045fce8(*(int *)(param_1 + 0x10),*(uint *)(puVar7 + 2),(uint *)pOVar10,iVar13,
                             (uint *)&local_40);
        if (iVar3 < 0) {
LAB_40465ce0:
          (**(code **)(*(int *)(param_1 + 4) + 0x50))((int *)(param_1 + 4),pOVar4);
        }
        else {
          if (puVar7[10] == 0) {
            pOVar4[4] = L'\0';
            pOVar4[5] = L'\0';
          }
          else {
            *(BSTR *)(pOVar4 + 4) = local_40;
            pOVar6 = local_40 + (uint)(ushort)OVar1 * 8;
            puVar9 = (uint *)((uint)*puVar7 + (uint)puVar7[10] * -0xc + (int)puVar7);
            local_34 = (uint *)((uint)*puVar7 + (uint)puVar7[10] * -0x10 + (int)puVar7);
            local_38 = 0;
            pOVar11 = local_40;
            local_40 = pOVar6;
            if (puVar7[10] != 0) {
              do {
                if (piVar12 == (int *)0x0) {
LAB_40465bc8:
                  if ((puVar9[2] & 0x20) == 0) {
                    pOVar11[4] = L'\0';
                    pOVar11[5] = L'\0';
                  }
                  else {
                    local_40 = pOVar6 + 0xc;
                    *(BSTR *)(pOVar11 + 4) = pOVar6;
                    pOVar6[0] = L'\x18';
                    pOVar6[1] = L'\0';
                    iVar3 = FUN_40460228(*(int *)(param_1 + 0x10),*local_34,pOVar6 + 4);
                    if (iVar3 < 0) goto LAB_40465ce0;
                    piVar12 = local_3c;
                    if (pOVar6[4] == L'\b') {
                      pOVar4[0x16] = L' ';
                    }
                  }
                  pOVar11[6] = *(OLECHAR *)(puVar9 + 2);
                  iVar3 = FUN_4045fce8(*(int *)(param_1 + 0x10),*puVar9,(uint *)pOVar11,iVar13,
                                       (uint *)&local_40);
                  if (iVar3 < 0) goto LAB_40465ce0;
                  pOVar11 = pOVar11 + 8;
                  pOVar6 = local_40;
                }
                else if ((puVar9[2] & 4) == 0) {
                  if ((puVar9[2] & 8) == 0) goto LAB_40465bc8;
                  iVar3 = FUN_4045fce8(*(int *)(param_1 + 0x10),*puVar9,(uint *)pOVar10,iVar13,
                                       (uint *)&local_40);
                  if (iVar3 < 0) goto LAB_40465ce0;
                  puVar5 = *(undefined4 **)pOVar10;
                  *(undefined4 *)pOVar10 = *puVar5;
                  *(undefined4 *)(pOVar4 + 0x12) = puVar5[1];
                  goto LAB_40465b34;
                }
                local_34 = local_34 + 1;
                local_38 = local_38 + 1;
                puVar9 = puVar9 + 3;
              } while (local_38 < puVar7[10]);
            }
          }
          if ((piVar12 != (int *)0x0) && (pOVar4[0x12] == L'\x19')) {
            pOVar4[0x12] = L'\x18';
          }
LAB_40465b34:
          iVar3 = 0;
          *local_30 = pOVar4;
        }
      }
    }
    else {
      iVar3 = -0x7ffd7fd5;
    }
  }
  return iVar3;
}



/* 40465d38 FUN_40465d38 */

/* Boundary evidence: original MIPS .pdata 40465d38..40466083. Semantic name remains unreviewed. */

int FUN_40465d38(int param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5,int param_6)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  ushort *puVar9;
  int *local_30;
  int *local_2c;
  
  puVar9 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if (((*puVar9 & 0x10) == 0) || (iVar3 = 1, *(int *)(param_1 + 0x14) != 4)) {
    iVar3 = param_6;
  }
  if ((*(uint *)(puVar9 + 8) & 8) == 0) {
    iVar2 = FUN_4045a504((int *)(puVar9 + 2),*(int *)(param_1 + 0x10),0);
  }
  else {
    iVar2 = 0;
  }
  if (-1 < iVar2) {
    uVar7 = 0;
    uVar5 = 0xffffffff;
    if ((uint)puVar9[0xd] + (uint)puVar9[0xc] != 0) {
      piVar4 = *(int **)(puVar9 + 0x10);
      do {
        uVar5 = uVar7;
        if (*piVar4 == param_2) break;
        uVar7 = uVar7 + 1;
        piVar4 = piVar4 + 1;
        uVar5 = 0xffffffff;
      } while (uVar7 < (uint)puVar9[0xd] + (uint)puVar9[0xc]);
    }
    if (uVar5 == 0xffffffff) {
      if (puVar9[0x26] == 0) {
        iVar2 = -0x7ffd7fd5;
      }
      else {
        iVar2 = FUN_40465260(param_1,(int)puVar9,(uint *)&local_2c,&local_30);
        if (-1 < iVar2) {
          if (local_30 == (int *)0x0) {
            iVar2 = (**(code **)(*local_2c + 0x1c))(local_2c);
          }
          else {
            iVar2 = FUN_40465d38((int)local_30,param_2,param_3,param_4,param_5,iVar3);
            (**(code **)(*local_30 + 8))();
          }
          (**(code **)(*local_2c + 8))(local_2c);
        }
      }
    }
    else {
      uVar7 = 0;
      if (param_4 != 0) {
        iVar2 = FUN_4045da0c(*(int *)(param_1 + 0x10));
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_4045c2c4(*(int *)(param_1 + 0x10),*(int *)(*(int *)(puVar9 + 0x12) + uVar5 * 4),
                             param_3);
        if (iVar2 < 0) {
          return iVar2;
        }
        uVar7 = 1;
        puVar6 = (ushort *)(*(int *)(*(int *)(puVar9 + 0x14) + uVar5 * 4) + *(int *)(puVar9 + 10));
        if (uVar5 < puVar9[0xc]) {
          uVar1 = puVar6[8];
          while (((uVar1 & 0x60) != 0 &&
                 (puVar6 = (ushort *)
                           (*(int *)((uint)puVar6[9] * 4 + *(int *)(puVar9 + 0x14)) +
                           *(int *)(puVar9 + 10)), puVar6[1] != uVar5))) {
            uVar1 = puVar6[8];
          }
          uVar5 = (uint)puVar6[10];
          iVar2 = uVar5 * -0xc;
          if ((puVar6[8] & 0x60) != 0) {
            uVar5 = uVar5 + 0xffff & 0xffff;
          }
          if (iVar3 != 0) {
            uVar5 = uVar5 - (puVar6[8] >> 0xe) & 0xffff;
          }
          if (uVar5 != 0) {
            piVar4 = (int *)((int)puVar6 + (uint)*puVar6 + iVar2 + 4);
            puVar8 = param_3;
            do {
              puVar8 = puVar8 + 1;
              if (param_4 == uVar7) break;
              iVar3 = FUN_4045c2c4(*(int *)(param_1 + 0x10),*piVar4,puVar8);
              if (iVar3 < 0) {
                if (uVar7 == 0) {
                  return iVar3;
                }
                puVar8 = param_3 + uVar7;
                do {
                  puVar8 = puVar8 + -1;
                  uVar7 = uVar7 - 1;
                  SysFreeString((BSTR)*puVar8);
                  *puVar8 = 0;
                } while (uVar7 != 0);
                return iVar3;
              }
              uVar7 = uVar7 + 1;
              piVar4 = piVar4 + 3;
            } while (uVar7 <= uVar5);
          }
        }
      }
      iVar2 = 0;
      *param_5 = uVar7;
    }
  }
  return iVar2;
}



/* 40466084 FUN_40466084 */

/* Boundary evidence: original MIPS .pdata 40466084..4046647b. Semantic name remains unreviewed. */

int FUN_40466084(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5
                ,undefined4 *param_6)

{
  ushort uVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined4 uVar8;
  int iVar9;
  int local_34;
  int *local_30 [2];
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  iVar9 = *(int *)(iVar3 + 0x20) + *(int *)(param_1 + 8);
  if (param_2 == -1) {
    iVar3 = (**(code **)(*(int *)(iVar3 + 4) + 0x24))
                      ((int *)(iVar3 + 4),*(undefined2 *)(iVar9 + 2),param_3,param_4,param_5,param_6
                      );
    return iVar3;
  }
  if ((*(uint *)(iVar9 + 0x10) & 8) == 0) {
    iVar3 = FUN_4045a504((int *)(iVar9 + 4),iVar3,0);
  }
  else {
    iVar3 = 0;
  }
  if (iVar3 < 0) {
    return iVar3;
  }
  local_34 = -1;
  if (((param_2 == -2) && (*(int *)(param_1 + 0x10) == 5)) && ((*(uint *)(iVar9 + 0x30) & 9) != 0))
  {
    local_30[0] = *(int **)(iVar9 + 0x34);
    uVar8 = *(undefined4 *)(iVar9 + 0x44);
    iVar3 = *(int *)(iVar9 + 0x3c);
  }
  else {
    uVar5 = (uint)*(ushort *)(iVar9 + 0x1a) + (uint)*(ushort *)(iVar9 + 0x18);
    uVar6 = 0;
    if (uVar5 != 0) {
      piVar4 = *(int **)(iVar9 + 0x20);
      do {
        if (*piVar4 == param_2) goto LAB_404662cc;
        uVar6 = uVar6 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar6 < uVar5);
    }
    uVar6 = 0xffffffff;
LAB_404662cc:
    if (uVar6 == 0xffffffff) {
      if (*(short *)(iVar9 + 0x4c) == 0) {
        return -0x7ffd7fd5;
      }
      iVar3 = FUN_40465260(param_1 + -4,iVar9,(uint *)local_30,(undefined4 *)0x0);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)(*local_30[0] + 0x30))
                        (local_30[0],param_2,param_3,param_4,param_5,param_6);
      (**(code **)(*local_30[0] + 8))(local_30[0]);
      return iVar3;
    }
    local_30[0] = *(int **)(*(int *)(iVar9 + 0x24) + uVar6 * 4);
    puVar7 = (ushort *)(*(int *)(*(int *)(iVar9 + 0x28) + uVar6 * 4) + *(int *)(iVar9 + 0x14));
    iVar3 = -1;
    if (uVar6 < *(ushort *)(iVar9 + 0x18)) {
      bVar2 = FUN_40463614(puVar7);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(puVar7 + 0xc);
      }
      bVar2 = FUN_40463660(puVar7);
      if (CONCAT31(extraout_var_00,bVar2) != 0) {
        iVar3 = *(int *)(puVar7 + 0xe);
      }
      bVar2 = FUN_404636f8(puVar7);
      if (CONCAT31(extraout_var_01,bVar2) != 0) {
        local_34 = *(int *)(puVar7 + 0x12);
      }
    }
    else {
      uVar1 = *puVar7;
      if (uVar1 < 0x15) {
        uVar8 = 0;
      }
      else {
        uVar8 = *(undefined4 *)(puVar7 + 10);
      }
      if (0x18 < uVar1) {
        iVar3 = *(int *)(puVar7 + 0xc);
      }
      if (0x1c < uVar1) {
        local_34 = *(int *)(puVar7 + 0xe);
      }
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar9 = FUN_4045da0c(*(int *)(param_1 + 0xc));
    if (iVar9 < 0) {
      return iVar9;
    }
    iVar9 = FUN_4045c2c4(*(int *)(param_1 + 0xc),(int)local_30[0],param_3);
    if (iVar9 < 0) {
      return iVar9;
    }
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = uVar8;
  }
  if (((param_4 == (undefined4 *)0x0) || (iVar3 == -1)) ||
     (iVar3 = FUN_4045cb14(*(int *)(param_1 + 0xc),iVar3,param_4), -1 < iVar3)) {
    if (param_6 != (undefined4 *)0x0) {
      iVar3 = *(int *)(param_1 + 0xc);
      if (local_34 == -1) {
        iVar3 = FUN_4045d0a0(iVar3,*(undefined4 *)(iVar3 + 0x170),param_6);
      }
      else {
        iVar3 = FUN_4045d0a0(iVar3,local_34,param_6);
      }
      if (iVar3 < 0) goto LAB_40466430;
    }
    iVar3 = 0;
  }
  else {
LAB_40466430:
    if (param_3 != (undefined4 *)0x0) {
      SysFreeString((BSTR)*param_3);
      *param_3 = 0;
    }
    if (param_4 != (undefined4 *)0x0) {
      SysFreeString((BSTR)*param_4);
      *param_4 = 0;
    }
    if (param_6 != (undefined4 *)0x0) {
      SysFreeString((BSTR)*param_6);
      *param_6 = 0;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
    }
  }
  return iVar3;
}



/* 4046647c FUN_4046647c */

/* Boundary evidence: original MIPS .pdata 4046647c..404666af. Semantic name remains unreviewed. */

DWORD FUN_4046647c(int param_1,uint param_2,int *param_3)

{
  DWORD DVar1;
  int iVar2;
  uint local_res4 [3];
  int *local_18;
  int local_14;
  
  if ((param_3 == (int *)0x0) || (param_2 == 0xffffffff)) {
    return 0x80070057;
  }
  local_res4[0] = param_2;
  if (param_2 == 0xfffffffe) {
    (**(code **)(**(int **)(param_1 + 0x18) + 4))();
    local_14 = *(int *)(param_1 + 0x18);
  }
  else {
    *param_3 = 0;
    if ((param_2 >> 0x18 != 0) &&
       (iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8),
       param_2 >> 0x18 != *(ushort *)(iVar2 + 0x58) + 1)) {
      DVar1 = FUN_40465260(param_1 + -4,iVar2,(uint *)&local_18,(undefined4 *)0x0);
      if ((int)DVar1 < 0) {
        return DVar1;
      }
      DVar1 = (**(code **)(*local_18 + 0x38))(local_18,local_res4[0],param_3);
      iVar2 = *local_18;
LAB_40466564:
      (**(code **)(iVar2 + 8))(local_18);
      return DVar1;
    }
    if ((param_2 & 1) == 1) {
      DVar1 = FUN_4045cbc0((int)*(int **)(param_1 + 0xc),param_2 & 0xfffffc,(int *)&local_18);
      if ((int)DVar1 < 0) {
        return DVar1;
      }
      if (((local_res4[0] & 2) != 0) &&
         (DVar1 = (**(code **)(*local_18 + 0x20))(local_18,0xffffffff,local_res4),
         DVar1 != 0x8002802b)) {
        if (DVar1 == 0) {
          DVar1 = (**(code **)(*local_18 + 0x38))(local_18,local_res4[0],param_3);
        }
        iVar2 = *local_18;
        goto LAB_40466564;
      }
      goto LAB_404664e4;
    }
    DVar1 = FUN_4045e204(*(int **)(param_1 + 0xc),param_2 & 0xfffffc,&local_14);
    if ((int)DVar1 < 0) {
      return DVar1;
    }
    if ((((local_res4[0] & 2) != 0) && (*(int *)(local_14 + 0x14) == 4)) &&
       (*(int *)(local_14 + 0x1c) != 0)) {
      local_14 = *(int *)(local_14 + 0x1c);
    }
  }
  local_18 = (int *)(local_14 + 4);
  if (local_14 == 0) {
    local_18 = (int *)0x0;
  }
LAB_404664e4:
  *param_3 = (int)local_18;
  return 0;
}



/* 404666b0 FUN_404666b0 */

/* Boundary evidence: original MIPS .pdata 404666b0..404668b3. Semantic name remains unreviewed. */

int FUN_404666b0(int param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  ushort *puVar4;
  int *piVar5;
  uint local_28 [2];
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
    puVar4 = (ushort *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8));
    piVar5 = (int *)(param_1 + -4);
    if ((*puVar4 & 0x20) == 0) {
      iVar1 = (**(code **)(*piVar5 + 100))(piVar5);
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_2 == -2) {
      if ((*(int *)(param_1 + 0x10) != 5) || ((*(uint *)(puVar4 + 0x18) & 9) == 0)) {
        return -0x7ffd7fd5;
      }
      puVar3 = (uint *)(param_1 + 0x14);
      if (*puVar3 == 0xffffffff) {
        if (*(int *)(puVar4 + 0x16) == -1) {
          puVar2 = &DAT_40443ecc;
        }
        else {
          puVar2 = (undefined4 *)
                   (*(int *)(*(int *)(param_1 + 0xc) + 0x84) + *(int *)(puVar4 + 0x16));
        }
        iVar1 = FUN_404578bc((uint *)&DAT_4046de9c,puVar2,puVar3);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
      FUN_40457b0c((uint *)&DAT_4046de9c,*puVar3,param_4);
      return 0;
    }
    if ((param_2 != -1) && ((param_3 & 0xf) != 0)) {
      if (*(int *)(param_1 + 0x10) != 2) {
        return -0x7ffd7743;
      }
      if ((*(uint *)(puVar4 + 8) & 8) == 0) {
        iVar1 = FUN_4045a504((int *)(puVar4 + 2),*(int *)(param_1 + 0xc),0);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = FUN_4045a9e4((int)(puVar4 + 2),param_2,param_3,local_28);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = FUN_40464db8((int)piVar5,(int)puVar4,
                           (ushort *)
                           (*(int *)(*(int *)(puVar4 + 0x14) + local_28[0] * 4) +
                           *(int *)(puVar4 + 10)),param_4);
      return iVar1;
    }
  }
  return -0x7ff8ffa9;
}



/* 404668b4 FUN_404668b4 */

/* Boundary evidence: original MIPS .pdata 404668b4..404668eb. Semantic name remains unreviewed. */

int FUN_404668b4(int param_1,uint param_2,void *param_3,undefined2 *param_4)

{
  int iVar1;
  
  if (param_4 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    iVar1 = FUN_40465174(param_1 + -4,param_2,param_3,param_4,(int *)0x0);
  }
  return iVar1;
}



/* 404668ec FUN_404668ec */

/* Boundary evidence: original MIPS .pdata 404668ec..4046692b. Semantic name remains unreviewed. */

int FUN_404668ec(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_40465174(param_1 + -4,param_2,(void *)0x0,(undefined2 *)0x0,param_3);
  }
  return iVar1;
}



/* 4046692c FUN_4046692c */

/* Boundary evidence: original MIPS .pdata 4046692c..40466b07. Semantic name remains unreviewed. */

int FUN_4046692c(int param_1,uint param_2,uint param_3,uint param_4,void *param_5,
                undefined2 *param_6,int *param_7)

{
  int iVar1;
  ushort *puVar2;
  int *local_28 [2];
  
  puVar2 = (ushort *)(*(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc));
  if ((((param_3 & 4) != 0) && ((*puVar2 & 0x10) != 0)) && (*(int *)(param_1 + 0x14) == 4)) {
    param_3 = 1;
  }
  if ((param_3 & 1) != 0) {
    if (param_2 < puVar2[0x2d]) {
      iVar1 = FUN_40465260(param_1,(int)puVar2,(uint *)0x0,local_28);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = FUN_4046692c((int)local_28[0],param_2,param_3,param_4,param_5,param_6,param_7);
      (**(code **)(*local_28[0] + 8))();
      return iVar1;
    }
    param_2 = param_2 - puVar2[0x2d];
  }
  if ((*(uint *)(puVar2 + 8) & 8) == 0) {
    iVar1 = FUN_4045a504((int *)(puVar2 + 2),*(int *)(param_1 + 0x10),0);
  }
  else {
    iVar1 = 0;
  }
  if (-1 < iVar1) {
    if ((param_2 < puVar2[0xc]) &&
       (iVar1 = *(int *)(puVar2 + 10) + *(int *)(*(int *)(puVar2 + 0x14) + param_2 * 4),
       param_4 <= *(ushort *)(iVar1 + 0x14))) {
      if ((*(ushort *)(iVar1 + 0x10) & 0x80) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_40460428(*(int *)(param_1 + 0x10),*(int *)((param_4 + 0xc) * 4 + iVar1),param_5,
                             param_6,param_7);
      }
    }
    else {
      iVar1 = -0x7ffd7fd5;
    }
  }
  return iVar1;
}



/* 40466b08 FUN_40466b08 */

/* Boundary evidence: original MIPS .pdata 40466b08..40466d3f. Semantic name remains unreviewed. */

int FUN_40466b08(int param_1,int param_2,undefined4 param_3,undefined4 *param_4,undefined4 *param_5,
                undefined4 *param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  int *local_30 [2];
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  iVar8 = *(int *)(iVar2 + 0x20) + *(int *)(param_1 + 8);
  if (param_2 == -1) {
    iVar2 = (**(code **)(*(int *)(iVar2 + 4) + 0x3c))
                      ((int *)(iVar2 + 4),*(undefined2 *)(iVar8 + 2),param_3,param_4,param_5,param_6
                      );
    return iVar2;
  }
  if ((*(uint *)(iVar8 + 0x10) & 8) == 0) {
    iVar2 = FUN_4045a504((int *)(iVar8 + 4),iVar2,0);
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 < 0) {
    return iVar2;
  }
  uVar5 = (uint)*(ushort *)(iVar8 + 0x1a) + (uint)*(ushort *)(iVar8 + 0x18);
  uVar6 = 0;
  if (uVar5 != 0) {
    piVar4 = *(int **)(iVar8 + 0x20);
    do {
      if (*piVar4 == param_2) goto LAB_40466c28;
      uVar6 = uVar6 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar6 < uVar5);
  }
  uVar6 = 0xffffffff;
LAB_40466c28:
  if (uVar6 != 0xffffffff) {
    puVar7 = (ushort *)(*(int *)(*(int *)(iVar8 + 0x28) + uVar6 * 4) + *(int *)(iVar8 + 0x14));
    if (param_5 != (undefined4 *)0x0) {
      if (uVar6 < *(ushort *)(iVar8 + 0x18)) {
        bVar1 = FUN_40463790(puVar7);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          return 0;
        }
        uVar3 = *(undefined4 *)(puVar7 + 0x16);
      }
      else {
        if (*puVar7 < 0x25) {
          return 0;
        }
        uVar3 = *(undefined4 *)(puVar7 + 0x12);
      }
      *param_5 = uVar3;
    }
    return 0;
  }
  if (*(short *)(iVar8 + 0x4c) == 0) {
    return -0x7ffd7fd5;
  }
  iVar2 = FUN_40465260(param_1 + -4,iVar8,(uint *)0x0,local_30);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(local_30[0][1] + 0x7c))
                      (local_30[0] + 1,param_2,param_3,param_4,param_5,param_6);
    (**(code **)(*local_30[0] + 8))();
    return iVar2;
  }
  return iVar2;
}



/* 40466d40 FUN_40466d40 */

/* Boundary evidence: original MIPS .pdata 40466d40..40466ee3. Semantic name remains unreviewed. */

int FUN_40466d40(int *param_1,int param_2,int param_3,ushort *param_4,int param_5,uint param_6,
                ushort param_7,int param_8,int *param_9,undefined4 *param_10,undefined4 *param_11)

{
  int *piVar1;
  int iVar2;
  int *local_28;
  int *local_24;
  
  iVar2 = FUN_40465260((int)param_1,param_2,(uint *)&local_24,&local_28);
  piVar1 = local_24;
  if (iVar2 != 0) {
    if (iVar2 != -0x7ffd7fd5) {
      return iVar2;
    }
    return 0;
  }
  if (local_28 == (int *)0x0) {
    iVar2 = (**(code **)(*local_24 + 0x10))(local_24,&local_24);
    if (iVar2 < 0) goto LAB_40466eac;
    iVar2 = (**(code **)(*local_24 + 0xc))
                      (local_24,param_4,param_6,param_7,param_9,param_10,param_11);
    local_28 = local_24;
  }
  else {
    if (local_28[4] != param_1[4]) {
      param_5 = -2;
    }
    iVar2 = FUN_40466ee4(local_28,param_4,param_5,param_6,param_7,param_8,param_9,param_10,param_11)
    ;
  }
  (**(code **)(*local_28 + 8))();
  if ((param_3 != 0) && ((int *)*param_9 != (int *)0x0)) {
    (**(code **)(*(int *)*param_9 + 8))();
    (**(code **)(*param_1 + 4))(param_1);
    *param_9 = (int)(param_1 + 1);
  }
LAB_40466eac:
  (**(code **)(*piVar1 + 8))(piVar1);
  return iVar2;
}



/* 40466ee4 FUN_40466ee4 */

/* Boundary evidence: original MIPS .pdata 40466ee4..40467293. Semantic name remains unreviewed. */

int FUN_40466ee4(int *param_1,ushort *param_2,int param_3,uint param_4,ushort param_5,int param_6,
                int *param_7,undefined4 *param_8,undefined4 *param_9)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  ushort uVar8;
  int local_res8 [2];
  int local_30;
  uint local_2c;
  
  iVar5 = 0;
  local_30 = 0;
  local_res8[0] = param_3;
  if ((param_3 != -2) ||
     ((iVar1 = FUN_4045da0c(param_1[4]), -1 < iVar1 &&
      (iVar1 = FUN_4045c1b8(param_1[4],param_2,param_4,local_res8), -1 < iVar1)))) {
    puVar6 = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
    if ((*puVar6 & 0x20) == 0) {
      iVar1 = (**(code **)(*param_1 + 100))(param_1);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      if (((*puVar6 & 0x10) != 0) && (param_1[5] == 4)) {
        iVar5 = 1;
        local_30 = 1;
        param_6 = 1;
      }
      uVar8 = puVar6[0x26];
      uVar7 = (uint)param_5;
      if ((uVar8 != 0) && ((*(uint *)(puVar6 + 0x18) & 0x2000) != 0)) {
        iVar1 = FUN_40466d40(param_1,(int)puVar6,iVar5,param_2,local_res8[0],param_4,param_5,param_6
                             ,param_7,param_8,param_9);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*param_7 != 0) {
          return iVar1;
        }
        uVar8 = 0;
      }
      if ((local_res8[0] != -1) && (*(int *)(*(int *)(param_1[4] + 0xac) + local_res8[0]) != -1)) {
        if ((*(uint *)(puVar6 + 8) & 8) == 0) {
          iVar1 = FUN_4045a504((int *)(puVar6 + 2),param_1[4],0);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar2 = (uint)puVar6[0xc];
        uVar4 = 0;
        if (puVar6[0xd] + uVar2 != 0) {
          piVar3 = *(int **)(puVar6 + 0x12);
          do {
            if (*piVar3 == local_res8[0]) goto LAB_40467104;
            uVar4 = uVar4 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar4 < puVar6[0xd] + uVar2);
        }
        uVar4 = 0xffffffff;
LAB_40467104:
        if (uVar4 != 0xffffffff) {
          if (uVar4 < uVar2) {
            iVar5 = FUN_4045a8ac((int)(puVar6 + 2),uVar4,uVar7,0,&local_2c);
            if (iVar5 == -0x7ffd7fd5) {
              iVar5 = -0x7ffd7360;
            }
            if (iVar5 < 0) {
              return iVar5;
            }
            uVar7 = 2;
            if (param_6 == 0) {
              uVar7 = 0;
            }
            iVar5 = FUN_404658c4((int)param_1,local_2c,param_9,uVar7);
            if (iVar5 < 0) {
              return iVar5;
            }
            *param_8 = 1;
          }
          else {
            if ((uVar7 == 1) ||
               (((uVar7 != 0 && ((param_5 & 2) == 0)) &&
                ((*(uint *)(*(int *)(*(int *)(puVar6 + 0x14) + uVar4 * 4) + *(int *)(puVar6 + 10) +
                           8) & 1) != 0)))) {
              return -0x7ffd7360;
            }
            iVar5 = (**(code **)(param_1[1] + 0x18))(param_1 + 1,uVar4 - uVar2,param_9);
            if (iVar5 < 0) {
              return iVar5;
            }
            *param_8 = 2;
          }
          (**(code **)(*param_1 + 4))(param_1);
          *param_7 = (int)(param_1 + 1);
          return 0;
        }
      }
      if (uVar8 != 0) {
        iVar1 = FUN_40466d40(param_1,(int)puVar6,local_30,param_2,local_res8[0],param_4,param_5,
                             param_6,param_7,param_8,param_9);
      }
    }
  }
  return iVar1;
}



/* 40467294 FUN_40467294 */

/* Boundary evidence: original MIPS .pdata 40467294..40467507. Semantic name remains unreviewed. */

int FUN_40467294(int *param_1,ushort *param_2,int param_3,uint param_4,int param_5,
                undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  ushort *puVar5;
  int local_res8 [2];
  int *local_30 [2];
  
  *param_6 = 0;
  local_res8[0] = param_3;
  if (param_3 == -2) {
    iVar1 = FUN_4045da0c(param_1[4]);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_4045c1b8(param_1[4],param_2,param_4,local_res8);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  puVar5 = (ushort *)(*(int *)(param_1[4] + 0x20) + param_1[3]);
  if ((*puVar5 & 0x20) == 0) {
    iVar1 = (**(code **)(*param_1 + 100))(param_1);
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((param_5 == 0) && (local_res8[0] != -1)) {
    piVar4 = (int *)(*(int *)(param_1[4] + 0xac) + local_res8[0]);
    if (*piVar4 != -1) {
      if ((*(uint *)(puVar5 + 8) & 8) == 0) {
        iVar1 = FUN_4045a504((int *)(puVar5 + 2),param_1[4],0);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = 0;
      if ((uint)puVar5[0xd] + (uint)puVar5[0xc] != 0) {
        piVar3 = *(int **)(puVar5 + 0x12);
        do {
          if (*piVar3 == local_res8[0]) goto LAB_40467404;
          uVar2 = uVar2 + 1;
          piVar3 = piVar3 + 1;
        } while (uVar2 < (uint)puVar5[0xd] + (uint)puVar5[0xc]);
      }
      uVar2 = 0xffffffff;
LAB_40467404:
      if (uVar2 != 0xffffffff) {
        *param_6 = piVar4;
        *param_7 = *(undefined4 *)(*(int *)(puVar5 + 0x10) + uVar2 * 4);
        return 0;
      }
    }
  }
  if (puVar5[0x26] != 0) {
    iVar1 = FUN_40465260((int)param_1,(int)puVar5,(uint *)0x0,local_30);
    if (iVar1 == 0) {
      if (local_30[0][4] != param_1[4]) {
        local_res8[0] = -2;
        param_5 = 0;
      }
      FUN_40467294(local_30[0],param_2,local_res8[0],param_4,param_5,param_6,param_7);
      (**(code **)(*local_30[0] + 8))();
    }
    else if ((iVar1 != -0x7ffd7fd5) && (iVar1 != -0x7fffbffe)) {
      return iVar1;
    }
  }
  return 0;
}



/* 40467508 FUN_40467508 */

/* Boundary evidence: original MIPS .pdata 40467508..404675db. Semantic name remains unreviewed. */

int FUN_40467508(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int *piVar4;
  
  if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    puVar3 = (ushort *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8));
    piVar4 = (int *)(param_1 + -4);
    if ((*puVar3 & 0x20) == 0) {
      iVar1 = (**(code **)(*piVar4 + 100))(piVar4);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      if (((*puVar3 & 0x10) == 0) || (uVar2 = 3, *(int *)(param_1 + 0x10) != 4)) {
        uVar2 = 0;
      }
      iVar1 = FUN_404658c4((int)piVar4,param_2,param_3,uVar2);
    }
  }
  return iVar1;
}



/* 404675dc FUN_404675dc */

/* Boundary evidence: original MIPS .pdata 404675dc..404676c7. Semantic name remains unreviewed. */

int FUN_404675dc(int param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 == (undefined4 *)0x0) || (param_5 == (uint *)0x0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    *param_5 = 0;
    if ((param_2 == -2) && (*(int *)(param_1 + 0x10) == 5)) {
      iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8);
      if ((*(uint *)(iVar2 + 0x30) & 9) != 0) {
        if (param_4 != 0) {
          iVar1 = FUN_4045da0c(*(int *)(param_1 + 0xc));
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar2 = FUN_4045c2c4(*(int *)(param_1 + 0xc),*(int *)(iVar2 + 0x34),param_3);
          if (iVar2 < 0) {
            return iVar2;
          }
          *param_5 = 1;
        }
        return 0;
      }
    }
    iVar2 = FUN_40465d38(param_1 + -4,param_2,param_3,param_4,param_5,0);
  }
  return iVar2;
}



/* 404676c8 FUN_404676c8 */

/* Boundary evidence: original MIPS .pdata 404676c8..4046770f. Semantic name remains unreviewed. */

int FUN_404676c8(int param_1,uint param_2,void *param_3,undefined2 *param_4)

{
  int iVar1;
  
  if (param_4 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    iVar1 = FUN_4046692c(param_1 + -4,param_2,4,0,param_3,param_4,(int *)0x0);
  }
  return iVar1;
}



/* 40467710 FUN_40467710 */

/* Boundary evidence: original MIPS .pdata 40467710..40467773. Semantic name remains unreviewed. */

int FUN_40467710(int param_1,uint param_2,int param_3,void *param_4,undefined2 *param_5)

{
  int iVar1;
  
  if (param_5 == (undefined2 *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_5 = 0;
    if (param_3 == -1) {
      iVar1 = -0x7ffd7fd5;
    }
    else {
      iVar1 = FUN_4046692c(param_1 + -4,param_2,4,param_3 + 1,param_4,param_5,(int *)0x0);
    }
  }
  return iVar1;
}



/* 40467774 FUN_40467774 */

/* Boundary evidence: original MIPS .pdata 40467774..404677bb. Semantic name remains unreviewed. */

int FUN_40467774(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_3 = 0;
    iVar1 = FUN_4046692c(param_1 + -4,param_2,4,0,(void *)0x0,(undefined2 *)0x0,param_3);
  }
  return iVar1;
}



/* 404677bc FUN_404677bc */

/* Boundary evidence: original MIPS .pdata 404677bc..4046781f. Semantic name remains unreviewed. */

int FUN_404677bc(int param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (param_4 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    *param_4 = 0;
    if (param_3 == -1) {
      iVar1 = -0x7ffd7fd5;
    }
    else {
      iVar1 = FUN_4046692c(param_1 + -4,param_2,4,param_3 + 1,(void *)0x0,(undefined2 *)0x0,param_4)
      ;
    }
  }
  return iVar1;
}



/* 40467820 FUN_40467820 */

/* Boundary evidence: original MIPS .pdata 40467820..40467c17. Semantic name remains unreviewed. */

int FUN_40467820(int param_1,ushort *param_2,uint param_3,uint param_4,int *param_5,
                undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  ushort *puVar7;
  ushort uVar8;
  int local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30 [2];
  
  if ((((param_2 != (ushort *)0x0) && (param_5 != (int *)0x0)) && (param_6 != (undefined4 *)0x0)) &&
     (param_7 != (undefined4 *)0x0)) {
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
    if ((param_4 & 0xfffffff0) == 0) {
      piVar5 = (int *)(param_1 + -8);
      iVar6 = 0;
      local_38 = 0;
      local_40 = -2;
      local_3c = 0;
      local_34 = param_3;
      iVar1 = FUN_4045da0c(*(int *)(param_1 + 8));
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = FUN_4045c1b8(*(int *)(param_1 + 8),param_2,param_3,&local_40);
      if (iVar1 < 0) {
        return iVar1;
      }
      puVar7 = (ushort *)(*(int *)(param_1 + 4) + *(int *)(*(int *)(param_1 + 8) + 0x20));
      if ((*puVar7 & 0x20) == 0) {
        iVar1 = (**(code **)(*piVar5 + 100))(piVar5);
      }
      else {
        iVar1 = 0;
      }
      if (iVar1 < 0) {
        return iVar1;
      }
      if (((*puVar7 & 0x10) != 0) && (*(int *)(param_1 + 0xc) == 4)) {
        iVar6 = 1;
        local_38 = 1;
        local_3c = 1;
      }
      uVar8 = puVar7[0x26];
      if ((uVar8 != 0) && ((*(uint *)(puVar7 + 0x18) & 0x2000) != 0)) {
        iVar1 = FUN_40466d40(piVar5,(int)puVar7,local_3c,param_2,local_40,local_34,(ushort)param_4,
                             iVar6,param_5,param_6,param_7);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (*param_5 != 0) {
          return iVar1;
        }
        uVar8 = 0;
      }
      if ((local_40 != -1) && (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0xac) + local_40) != -1)) {
        if ((*(uint *)(puVar7 + 8) & 8) == 0) {
          iVar1 = FUN_4045a504((int *)(puVar7 + 2),*(int *)(param_1 + 8),0);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        uVar2 = (uint)puVar7[0xc];
        uVar4 = 0;
        if (puVar7[0xd] + uVar2 != 0) {
          piVar3 = *(int **)(puVar7 + 0x12);
          do {
            if (*piVar3 == local_40) goto LAB_40467a74;
            uVar4 = uVar4 + 1;
            piVar3 = piVar3 + 1;
          } while (uVar4 < puVar7[0xd] + uVar2);
        }
        uVar4 = 0xffffffff;
LAB_40467a74:
        if (uVar4 != 0xffffffff) {
          if (uVar4 < uVar2) {
            iVar1 = FUN_4045a8ac((int)(puVar7 + 2),uVar4,param_4,0,local_30);
            if (iVar1 == -0x7ffd7fd5) {
              iVar1 = -0x7ffd7360;
            }
            if (iVar1 < 0) {
              return iVar1;
            }
            uVar2 = 2;
            if (local_38 == 0) {
              uVar2 = 0;
            }
            iVar1 = FUN_404658c4((int)piVar5,local_30[0],param_7,uVar2);
            if (iVar1 < 0) {
              return iVar1;
            }
            *param_6 = 1;
          }
          else {
            if ((param_4 == 1) ||
               (((param_4 != 0 && ((param_4 & 2) == 0)) &&
                ((*(uint *)(*(int *)(*(int *)(puVar7 + 0x14) + uVar4 * 4) + *(int *)(puVar7 + 10) +
                           8) & 1) != 0)))) {
              return -0x7ffd7360;
            }
            iVar1 = (**(code **)(*(int *)(param_1 + -4) + 0x18))
                              ((int *)(param_1 + -4),uVar4 - uVar2,param_7);
            if (iVar1 < 0) {
              return iVar1;
            }
            *param_6 = 2;
          }
          (**(code **)(*piVar5 + 4))(piVar5);
          *param_5 = param_1 + -4;
          return 0;
        }
      }
      if (uVar8 == 0) {
        return iVar1;
      }
      iVar1 = FUN_40466d40(piVar5,(int)puVar7,local_3c,param_2,local_40,local_34,(ushort)param_4,
                           local_38,param_5,param_6,param_7);
      return iVar1;
    }
  }
  return -0x7ff8ffa9;
}



/* 40467c18 FUN_40467c18 */

/* Boundary evidence: original MIPS .pdata 40467c18..40467d03. Semantic name remains unreviewed. */

int FUN_40467c18(int param_1,int param_2,int param_3,undefined4 *param_4,uint param_5,uint *param_6)

{
  int iVar1;
  int *local_20;
  int *local_1c;
  
  iVar1 = FUN_40465260(param_1,param_2,(uint *)&local_1c,&local_20);
  if (-1 < iVar1) {
    if (local_20 == (int *)0x0) {
      iVar1 = (**(code **)(*local_1c + 0x28))(local_1c,param_4,param_5,param_6);
    }
    else {
      if (local_20[4] != *(int *)(param_1 + 0x10)) {
        param_3 = -2;
      }
      iVar1 = FUN_40468574((int)local_20,param_3,param_4,param_5,param_6);
      (**(code **)(*local_20 + 8))();
    }
    (**(code **)(*local_1c + 8))();
  }
  return iVar1;
}



/* 40467d04 FUN_40467d04 */

/* Boundary evidence: original MIPS .pdata 40467d04..40468573. Semantic name remains unreviewed. */

int FUN_40467d04(int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
                int *param_6,void *param_7,int *param_8,ULONG *param_9,int param_10)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  ushort *puVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  VARIANTARG *pVVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  ULONG UVar14;
  int iVar15;
  uint uVar16;
  BSTR local_88;
  ushort local_84 [2];
  int local_80;
  int local_7c;
  ULONG local_78;
  LONG local_74;
  int *local_70;
  ushort local_6c [2];
  uint local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  int *local_58;
  int *local_54;
  uint local_50;
  void *local_4c;
  ULONG *local_48;
  int local_44;
  undefined4 auStack_40 [4];
  uint local_30;
  
  local_30 = DAT_4046d1b8;
  local_70 = param_5;
  local_54 = param_6;
  uVar6 = (uint)param_2[10];
  local_4c = param_7;
  local_58 = param_8;
  local_48 = param_9;
  local_5c = (uint)param_2[0xb];
  local_74 = 0;
  iVar2 = (uint)*param_2 + uVar6 * -0xc;
  local_44 = (uint)*param_2 + uVar6 * -0x10 + (int)param_2;
  uVar3 = uVar6 - (param_2[8] >> 0xe) & 0xffff;
  local_78 = 0xffffffff;
  UVar14 = local_78;
  if (local_5c == 0xffff) {
    local_5c = 0;
    UVar14 = uVar3 - 1;
  }
  uVar16 = param_5[2];
  iVar4 = uVar3 - local_5c;
  local_68 = uVar6;
  local_60 = param_1;
  local_50 = uVar16;
  if ((param_2[8] & 0x60) == 0) {
    local_64 = 0xffffffff;
    uVar3 = uVar16;
  }
  else {
    if (iVar4 == 0) {
      FUN_4046ace8(DAT_4046d1b8);
      return -0x7ffdfff1;
    }
    local_64 = uVar6 - 1;
    iVar4 = iVar4 + -1;
    uVar3 = uVar16 - 1;
    if (UVar14 != 0xffffffff) {
      UVar14 = UVar14 - 1;
    }
  }
  if (iVar4 != 0) {
    puVar7 = (ushort *)((int)param_2 + iVar4 * 0xc + iVar2 + -4);
    do {
      if ((*puVar7 & 0x30) == 0) break;
      iVar4 = iVar4 + -1;
      puVar7 = puVar7 + -6;
    } while (iVar4 != 0);
  }
  if (UVar14 != 0xffffffff) {
    local_78 = (uVar3 - iVar4) + 1;
  }
  iVar4 = FUN_40469cd8(uVar6,local_78,&local_88);
  if (iVar4 == 0) {
    iVar13 = 0;
    uVar11 = 0;
    uVar12 = 0;
    if (uVar6 != 0) {
      local_80 = 0;
      iVar15 = 0;
      local_7c = 0;
      puVar7 = (ushort *)((int)param_2 + iVar2 + 8);
      do {
        iVar2 = local_60;
        iVar4 = FUN_4045fe64(local_60,*(uint *)(puVar7 + -4),(short *)local_6c,auStack_40,local_84);
        piVar1 = local_70;
        if (iVar4 != 0) goto LAB_4046850c;
        if ((*puVar7 & 4) == 0) {
          if ((*puVar7 & 8) != 0) {
            *(ushort *)(*(int *)(local_88 + 2) + local_80) = local_84[0];
            puVar9 = (ushort *)(*(int *)(local_88 + 6) + local_7c);
            *puVar9 = local_84[0];
            *(void **)(puVar9 + 4) = local_4c;
            memset(local_4c,0,0x10);
            *(ushort **)(*(int *)(local_88 + 4) + iVar15) = puVar9;
            *local_54 = (int)puVar9;
            goto LAB_40467f64;
          }
          if (uVar12 == UVar14) {
            puVar8 = (undefined2 *)(*(int *)(local_88 + 6) + local_7c);
            *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(local_88 + 0xe);
            *puVar8 = 0x200c;
            if ((local_84[0] & 0x4000) == 0) {
              *(undefined2 **)(*(int *)(local_88 + 4) + iVar15) = puVar8;
              *(undefined2 *)(*(int *)(local_88 + 2) + local_80) = 0x200c;
            }
            else {
              puVar9 = (ushort *)(*(int *)(local_88 + 8) + local_7c);
              *puVar9 = local_84[0];
              *(undefined2 **)(puVar9 + 4) = puVar8 + 4;
              *(ushort **)(*(int *)(local_88 + 4) + iVar15) = puVar9;
              *(ushort *)(*(int *)(local_88 + 2) + local_80) = local_84[0];
            }
            for (; uVar11 < uVar3; uVar11 = uVar11 + 1) {
              iVar4 = FUN_404480e4((int)piVar1,uVar11,(int *)&local_78);
              if ((iVar4 != 0) ||
                 (iVar4 = SafeArrayPutElement(*(SAFEARRAY **)(local_88 + 0xe),&local_74,
                                              (void *)(local_78 * 0x10 + *piVar1)), iVar4 != 0))
              goto LAB_4046850c;
              local_74 = local_74 + 1;
            }
            local_74 = local_74 + -1;
          }
          else if (uVar12 == local_64) {
            if ((local_70[3] == 0) || (*(int *)local_70[1] != -3)) {
              iVar4 = -0x7ffdfffc;
              goto LAB_4046850c;
            }
            local_78 = 0;
LAB_404681a0:
            pVVar10 = (VARIANTARG *)(local_78 * 0x10 + *local_70);
            uVar11 = uVar11 + 1;
            if (((((pVVar10->n1).n2.vt == 10) && (*(int *)((int)&pVVar10->n1 + 8) == -0x7ffdfffc))
                && (uVar5 = *puVar7, (uVar5 & 0x10) != 0)) &&
               (((local_84[0] & 0xbfff) != 0xc || ((uVar5 & 0x20) != 0)))) {
LAB_4046820c:
              pVVar10 = (VARIANTARG *)(*(int *)(local_88 + 6) + local_7c);
              if ((uVar5 & 0x20) == 0) {
                if ((local_84[0] & 0xbfff) == 0xc) goto LAB_4046836c;
              }
              else if ((pVVar10->n1).n2.vt == 0) {
                iVar4 = FUN_40460228(*(int *)(local_60 + 0x10),*(uint *)(iVar15 + local_44),
                                     (undefined2 *)pVVar10);
                if (iVar4 < 0) goto LAB_4046850c;
                if ((local_84[0] == 8) && ((pVVar10->n1).n2.vt == 8)) {
                  *(undefined1 *)(*(int *)(local_88 + 0xc) + uVar12) = 1;
                }
              }
            }
            *(ushort *)(*(int *)(local_88 + 2) + local_80) = local_84[0];
            iVar4 = FUN_40449b98(pVVar10,(uint)local_84[0],(uint)local_6c[0],(undefined *)auStack_40
                                 ,(int)local_88,uVar12,2);
            if (iVar4 != 0) {
              *local_48 = local_78;
              goto LAB_4046850c;
            }
            if ((*puVar7 & 3) == 2) {
              puVar9 = *(ushort **)(*(int *)(local_88 + 4) + iVar15);
              uVar5 = *puVar9;
              if (uVar5 == 0x4008) {
                SysFreeString((BSTR)**(undefined4 **)(puVar9 + 4));
LAB_40468458:
                **(undefined4 **)(puVar9 + 4) = 0;
              }
              else if (uVar5 == 0x4009) {
                if (*(int **)(puVar9 + 4) != (int *)0x0) {
                  iVar2 = **(int **)(puVar9 + 4);
LAB_40468410:
                  if (iVar2 != 0) {
                    (**(code **)(*(int *)**(undefined4 **)(puVar9 + 4) + 8))();
                    goto LAB_40468458;
                  }
                }
              }
              else if (uVar5 == 0x400d) {
                if (*(int **)(puVar9 + 4) != (int *)0x0) {
                  iVar2 = **(int **)(puVar9 + 4);
                  goto LAB_40468410;
                }
              }
              else if ((uVar5 & 0x2000) != 0) {
                iVar4 = SafeArrayDestroy((SAFEARRAY *)**(undefined4 **)(puVar9 + 4));
                if ((iVar4 != 0) && (iVar4 < 0)) goto LAB_4046851c;
                **(undefined4 **)(puVar9 + 4) = 0;
              }
            }
          }
          else {
            iVar2 = FUN_404480e4((int)local_70,uVar12,(int *)&local_78);
            if (iVar2 == 0) goto LAB_404681a0;
            if (uVar12 < local_68 - local_5c) {
              uVar5 = *puVar7;
              if ((uVar5 & 0x10) != 0) {
                iVar13 = iVar13 + 1;
                goto LAB_4046820c;
              }
              goto LAB_40468504;
            }
            iVar13 = iVar13 + 1;
LAB_4046836c:
            *(undefined2 *)(*(int *)(local_88 + 2) + local_80) = 0xc;
            puVar8 = (undefined2 *)(*(int *)(local_88 + 6) + local_7c);
            *puVar8 = 10;
            *(undefined4 *)(puVar8 + 4) = 0x80020004;
            *(undefined2 **)(*(int *)(local_88 + 4) + iVar15) = puVar8;
            if ((local_84[0] & 0x4000) != 0) {
              puVar9 = (ushort *)(*(int *)(local_88 + 8) + local_7c);
              *puVar9 = local_84[0];
              *(undefined2 **)(puVar9 + 4) = puVar8;
              *(ushort **)(*(int *)(local_88 + 4) + iVar15) = puVar9;
              *(ushort *)(*(int *)(local_88 + 2) + local_80) = local_84[0];
            }
          }
        }
        else {
          *(undefined2 *)(*(int *)(local_88 + 2) + local_80) = 3;
          puVar8 = (undefined2 *)(*(int *)(local_88 + 6) + local_7c);
          *puVar8 = 3;
          *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x140);
          *(undefined2 **)(*(int *)(local_88 + 4) + iVar15) = puVar8;
LAB_40467f64:
          iVar13 = iVar13 + 1;
        }
        local_7c = local_7c + 0x10;
        local_80 = local_80 + 2;
        uVar12 = uVar12 + 1;
        puVar7 = puVar7 + 6;
        iVar15 = iVar15 + 4;
        uVar6 = local_68;
        uVar16 = local_50;
      } while (uVar12 < local_68);
    }
    if ((uVar11 == uVar16) || (((param_10 != 0 && (uVar11 == uVar16 - 1)) || (uVar11 == 0)))) {
      if (uVar6 == (iVar13 - local_74) + uVar11) {
        *local_58 = (int)local_88;
        FUN_4046ace8(local_30);
        return 0;
      }
LAB_40468504:
      iVar4 = -0x7ffdfff2;
    }
    else {
      iVar4 = -0x7ffdfffc;
    }
LAB_4046850c:
    FUN_40449848(local_88);
    *local_58 = 0;
  }
LAB_4046851c:
  FUN_4046ace8(local_30);
  return iVar4;
}



/* 40468574 FUN_40468574 */

/* Boundary evidence: original MIPS .pdata 40468574..404688f3. Semantic name remains unreviewed. */

int FUN_40468574(int param_1,int param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  short sVar10;
  uint uVar11;
  int local_res4 [3];
  
  local_res4[0] = param_2;
  if (param_2 == -2) {
    iVar3 = FUN_4045da0c(*(int *)(param_1 + 0x10));
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = FUN_4045c1b8(*(int *)(param_1 + 0x10),(ushort *)*param_3,0,local_res4);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x20) + *(int *)(param_1 + 0xc);
  sVar10 = *(short *)(iVar3 + 0x4c);
  if ((sVar10 != 0) && ((*(uint *)(iVar3 + 0x30) & 0x2000) != 0)) {
    iVar4 = FUN_40467c18(param_1,iVar3,local_res4[0],param_3,param_4,param_5);
    if (iVar4 != -0x7ffdfffa) {
      return iVar4;
    }
    sVar10 = 0;
  }
  if ((local_res4[0] != -1) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x10) + 0xac) + local_res4[0]) != -1)) {
    if ((*(uint *)(iVar3 + 0x10) & 8) == 0) {
      iVar4 = FUN_4045a504((int *)(iVar3 + 4),*(int *)(param_1 + 0x10),0);
    }
    else {
      iVar4 = 0;
    }
    if (iVar4 < 0) {
      return iVar4;
    }
    uVar6 = (uint)*(ushort *)(iVar3 + 0x1a) + (uint)*(ushort *)(iVar3 + 0x18);
    uVar8 = 0;
    if (uVar6 != 0) {
      piVar5 = *(int **)(iVar3 + 0x24);
      do {
        if (*piVar5 == local_res4[0]) goto LAB_404686f4;
        uVar8 = uVar8 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar8 < uVar6);
    }
    uVar8 = 0xffffffff;
LAB_404686f4:
    if (uVar8 != 0xffffffff) {
      *param_5 = *(uint *)(*(int *)(iVar3 + 0x20) + uVar8 * 4);
      if ((1 < param_4) && (uVar8 < *(ushort *)(iVar3 + 0x18))) {
        puVar9 = (ushort *)(*(int *)(*(int *)(iVar3 + 0x28) + uVar8 * 4) + *(int *)(iVar3 + 0x14));
        uVar1 = puVar9[8];
        while (((uVar1 & 0x60) != 0 &&
               (puVar9 = (ushort *)
                         (*(int *)((uint)puVar9[9] * 4 + *(int *)(iVar3 + 0x28)) +
                         *(int *)(iVar3 + 0x14)), puVar9[1] != uVar8))) {
          uVar1 = puVar9[8];
        }
        uVar1 = puVar9[10];
        uVar6 = (uint)uVar1 - (uint)(puVar9[8] >> 0xe) & 0xffff;
        if ((puVar9[8] & 0x60) != 0) {
          uVar6 = uVar6 - 1;
        }
        uVar11 = 1;
        uVar8 = 0;
        uVar2 = *puVar9;
        if (1 < param_4) {
          iVar3 = (int)param_3 - (int)param_5;
          do {
            param_5 = param_5 + 1;
            iVar4 = FUN_4045c1b8(*(int *)(param_1 + 0x10),*(ushort **)(iVar3 + (int)param_5),0,
                                 local_res4);
            if (iVar4 < 0) {
              return iVar4;
            }
            if (local_res4[0] == -1) {
              return -0x7ffdfffa;
            }
            uVar7 = 0;
            if (uVar6 != 0) {
              do {
                if (uVar8 == uVar6) {
                  uVar8 = 0;
                }
                if (*(int *)((int)puVar9 + uVar8 * 0xc + (uint)uVar2 + (uint)uVar1 * -0xc + 4) ==
                    local_res4[0]) {
                  *param_5 = uVar8;
                  break;
                }
                uVar7 = uVar7 + 1;
                uVar8 = uVar8 + 1;
              } while (uVar7 < uVar6);
            }
            if (uVar7 == uVar6) {
              return -0x7ffdfffa;
            }
            uVar11 = uVar11 + 1;
            uVar8 = uVar8 + 1;
          } while (uVar11 < param_4);
        }
      }
      return 0;
    }
  }
  if (sVar10 == 0) {
    iVar3 = -0x7ffdfffa;
  }
  else {
    iVar3 = FUN_40467c18(param_1,iVar3,local_res4[0],param_3,param_4,param_5);
  }
  return iVar3;
}



/* 404688f4 FUN_404688f4 */

/* Boundary evidence: original MIPS .pdata 404688f4..404692fb. Semantic name remains unreviewed. */

int FUN_404688f4(int param_1,void *param_2,int param_3,uint param_4,int *param_5,
                _union_2683 *param_6,void *param_7,ULONG *param_8)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  int iVar4;
  VARTYPE VVar5;
  ushort uVar6;
  ushort uVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  ushort *puVar12;
  BSTR pOVar13;
  VARTYPE local_88;
  ushort local_86;
  short asStack_84 [2];
  ULONG *local_80;
  uint local_7c;
  BSTR local_78;
  int local_74;
  void *local_70;
  ushort *local_6c;
  int local_68;
  int *local_64;
  ULONG UStack_60;
  uint local_5c;
  int *local_58;
  IRecordInfo *local_54;
  int *local_50;
  IRecordInfo *local_4c;
  _union_2683 local_48;
  _union_2683 local_38;
  
  local_86 = (ushort)param_4;
  puVar12 = (ushort *)(*(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8));
  pOVar13 = (BSTR)(param_1 + -4);
  local_6c = (ushort *)0x0;
  local_74 = 0;
  local_78 = pOVar13;
  local_70 = param_2;
  local_68 = param_1;
  if ((*puVar12 & 0x20) == 0) {
    iVar1 = (**(code **)(*(int *)pOVar13 + 100))(pOVar13);
    param_4 = (uint)local_86;
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  if (((*(uint *)(*(int *)(local_68 + 0xc) + 0x150) & 1) == 0) &&
     ((*(uint *)(puVar12 + 0x18) & 0x200) == 0)) {
    iVar1 = *(int *)(local_68 + 0x10);
    if (iVar1 == 2) {
      return -0x7fffbfff;
    }
    uVar9 = 4;
    if (iVar1 == 3) {
LAB_40468a28:
      if (((((local_70 != (void *)0x0) && (param_5 != (int *)0x0)) &&
           ((uint)param_5[3] <= (uint)param_5[2])) && ((param_5[3] == 0 || (param_5[1] != 0)))) &&
         ((param_4 != 0 && ((param_4 & 0xfffffff0) == 0)))) {
        local_80 = param_8;
        if (param_8 == (ULONG *)0x0) {
          local_80 = &UStack_60;
        }
        if (param_6 == (_union_2683 *)0x0) {
          local_38.n2.vt = 0;
          param_6 = &local_38;
        }
        puVar8 = puVar12 + 2;
        if ((*(uint *)(puVar12 + 8) & 8) == 0) {
          iVar1 = FUN_4045a504((int *)puVar8,*(int *)(local_68 + 0xc),0);
        }
        else {
          iVar1 = 0;
        }
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar1 = FUN_4045a9e4((int)puVar8,param_3,param_4,&local_7c);
        if (iVar1 == 0) {
          puVar10 = (ushort *)
                    (*(int *)(local_7c * 4 + *(int *)(puVar12 + 0x14)) + *(int *)(puVar12 + 10));
          uVar9 = (uint)puVar10[10] - (uint)(puVar10[8] >> 0xe) & 0xffff;
          if (puVar10[0xb] == 0xffff) {
            uVar9 = 0xffffffff;
            if ((param_5[3] != 0) && ((param_5[3] != 1 || (*(int *)param_5[1] != -3)))) {
              return -0x7ffdfff9;
            }
          }
          if (uVar9 < (uint)param_5[2]) {
            if ((param_4 & 2) == 0) {
              if ((param_4 & 0xc) == 0) {
                return -0x7ffdfff2;
              }
              iVar1 = FUN_4045a9e4((int)puVar8,param_3,2,&local_7c);
              if (iVar1 != 0) {
                return -0x7ffdfff2;
              }
              puVar10 = (ushort *)
                        (*(int *)(local_7c * 4 + *(int *)(puVar12 + 0x14)) + *(int *)(puVar12 + 10))
              ;
              uVar9 = (uint)puVar10[10] - (uint)(puVar10[8] >> 0xe) & 0xffff;
              if (uVar9 != 0) {
                if (uVar9 != param_5[2] - 1U) {
                  return -0x7ffdfff2;
                }
                local_74 = 1;
              }
            }
            else if (uVar9 != 0) {
              return -0x7ffdfff2;
            }
            iVar1 = -0x7ffdffef;
            goto LAB_40468c2c;
          }
          if ((-1 < param_3) && ((*(uint *)(puVar10 + 4) & 1) != 0)) goto LAB_404692c0;
          iVar1 = FUN_40467d04((int)pOVar13,puVar10,puVar12,(uint)local_86,param_5,(int *)&local_6c,
                               &local_58,(int *)&local_78,local_80,0);
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar1 = FUN_4045fe64((int)pOVar13,*(uint *)(puVar10 + 2),asStack_84,(undefined4 *)0x0,
                               &local_88);
          pOVar13 = local_78;
          if (iVar1 != 0) goto LAB_4046902c;
          VVar5 = 10;
          if (local_88 != 0x19) {
            VVar5 = local_88;
          }
          iVar1 = DispCallFunc(local_70,puVar10[6] & 0xfffffffc,CC_CDECL,VVar5,*(UINT *)local_78,
                               *(VARTYPE **)(local_78 + 2),*(VARIANTARG ***)(local_78 + 4),
                               (VARIANT *)&param_6->n2);
          if (((((_union_2683 *)&(param_6->n2).vt)->n2).vt & 0x4000) != 0) {
            iVar1 = -0x7ffdfff0;
          }
          if ((iVar1 != 0) || (iVar1 = FUN_404498d8((uint *)pOVar13), iVar1 != 0))
          goto LAB_4046902c;
          if (local_88 == 0x19) {
            if ((param_6->n2).n3.lVal < 0) {
              if (param_7 != (void *)0x0) {
                FUN_4046a774(param_7);
                *(LONG *)((int)param_7 + 0x1c) = (param_6->n2).n3.lVal;
              }
              iVar1 = -0x7ffdfff7;
            }
            else if (local_6c != (ushort *)0x0) {
              uVar6 = *local_6c & 0xbfff;
              if (uVar6 == 0xc) {
                *(int **)param_6 = local_58;
                (param_6->decVal).Hi32 = (ULONG)local_54;
                (param_6->n2).n3.lVal = (LONG)local_50;
                (param_6->n2).n3.brecVal.pRecInfo = local_4c;
              }
              else {
                if (uVar6 == 0xe) {
                  *(int **)param_6 = local_58;
                  (param_6->decVal).Hi32 = (ULONG)local_54;
                  (param_6->n2).n3.lVal = (LONG)local_50;
                  (param_6->n2).n3.brecVal.pRecInfo = local_4c;
                }
                else {
                  (param_6->n2).n3.lVal = (LONG)local_58;
                  (param_6->n2).n3.brecVal.pRecInfo = local_54;
                }
                (((_union_2683 *)&(param_6->n2).vt)->n2).vt = uVar6;
              }
              goto LAB_40468dfc;
            }
            (((_union_2683 *)&(param_6->n2).vt)->n2).vt = 0;
          }
LAB_40468dfc:
          if (param_6 == &local_38) {
            VariantClear((VARIANTARG *)&param_6->n2);
          }
          goto LAB_4046902c;
        }
        param_8 = local_80;
        if ((param_4 & 0xc) != 0) {
          if (param_4 == 4) {
            uVar9 = 8;
          }
          iVar1 = FUN_4045a9e4((int)puVar8,param_3,uVar9,&local_5c);
          param_8 = local_80;
          if ((iVar1 != 0) &&
             (iVar1 = FUN_4045a9e4((int)puVar8,param_3,2,&local_7c), param_8 = local_80, iVar1 == 0)
             ) {
            puVar10 = (ushort *)
                      (*(int *)(*(int *)(puVar12 + 0x14) + local_7c * 4) + *(int *)(puVar12 + 10));
            uVar9 = (uint)puVar10[10] - (uint)(puVar10[8] >> 0xe) & 0xffff;
            iVar1 = -0x7ffdfff2;
            if (uVar9 != 0) {
              pOVar13 = local_78;
              if (uVar9 != param_5[2] - 1U) goto LAB_40469234;
              local_74 = 1;
            }
LAB_40468c2c:
            iVar4 = local_74;
            pOVar13 = local_78;
            if ((param_3 < 0) || ((*(uint *)(puVar10 + 4) & 1) == 0)) {
              iVar2 = FUN_4045fe64((int)local_78,*(uint *)(puVar10 + 2),asStack_84,(undefined4 *)0x0
                                   ,&local_88);
              if (iVar2 < 0) {
                return iVar2;
              }
              if (puVar10[10] == 0) {
                if ((local_88 != 9) && (local_88 != 0xc)) {
                  return iVar1;
                }
                HVar3 = DispCallFunc(local_70,puVar10[6] & 0xfffffffc,CC_CDECL,local_88,0,
                                     (VARTYPE *)0x0,(VARIANTARG **)0x0,(VARIANT *)&local_48.n2);
              }
              else {
                iVar4 = FUN_40467d04((int)pOVar13,puVar10,puVar12,(uint)local_86,param_5,
                                     (int *)&local_6c,&local_58,(int *)&local_78,local_80,iVar4);
                puVar12 = local_6c;
                pOVar13 = local_78;
                if (iVar4 < 0) {
                  return iVar4;
                }
                VVar5 = 10;
                if (local_88 != 0x19) {
                  VVar5 = local_88;
                }
                if (((local_88 != 9) && (local_88 != 0xc)) &&
                   ((local_88 != 0x19 || (local_6c == (ushort *)0x0)))) {
LAB_4046902c:
                  FUN_40449848(pOVar13);
                  return iVar1;
                }
                HVar3 = DispCallFunc(local_70,puVar10[6] & 0xfffffffc,CC_CDECL,VVar5,
                                     *(UINT *)local_78,*(VARTYPE **)(local_78 + 2),
                                     *(VARIANTARG ***)(local_78 + 4),(VARIANT *)&local_48.n2);
                if ((HVar3 == 0) && (local_88 == 0x19)) {
                  if ((int *)local_48._8_4_ == (int *)0x0) {
                    if (puVar12 != (ushort *)0x0) {
                      uVar6 = *puVar12;
                      uVar7 = uVar6 & 0xbfff;
                      if (uVar7 == 0xc) {
                        local_48._0_4_ = local_58;
                        local_48.decVal.Hi32 = (ULONG)local_54;
                        local_48._8_4_ = local_50;
                        local_48._12_4_ = local_4c;
                      }
                      else {
                        if (uVar7 == 0xe) {
                          local_48._0_4_ = local_58;
                          local_48.decVal.Hi32 = (ULONG)local_54;
                          local_48._8_4_ = local_50;
                          local_48._12_4_ = local_4c;
                        }
                        else {
                          local_48._8_4_ = local_58;
                          local_48._12_4_ = local_54;
                        }
                        local_48._0_4_ = CONCAT22(local_48.n2.wReserved1,uVar6) & 0xffffbfff;
                      }
                    }
                  }
                  else {
                    if (param_7 != (void *)0x0) {
                      FUN_4046a774(param_7);
                      *(undefined4 *)((int)param_7 + 0x1c) = local_48._8_4_;
                    }
                    HVar3 = -0x7ffdfff7;
                  }
                }
                FUN_40449848(pOVar13);
              }
              iVar4 = local_74;
              if (HVar3 == 0) {
                if (local_48.n2.vt == 9) {
                  if ((int *)local_48._8_4_ == (int *)0x0) {
                    iVar1 = -0x7ffdfffd;
                  }
                  else {
                    uVar9 = local_5c;
                    uVar11 = local_5c;
                    if (local_74 != 0) {
                      uVar9 = param_5[2];
                      uVar11 = param_5[3];
                      param_5[3] = 1;
                      param_5[2] = 1;
                    }
                    iVar1 = (**(code **)(*(int *)local_48._8_4_ + 0x18))
                                      (local_48._8_4_,0,&DAT_40443ecc,
                                       *(undefined4 *)(*(int *)(local_68 + 0xc) + 0x140),local_86,
                                       param_5,param_6,param_7,local_80);
                    if (iVar4 != 0) {
                      param_5[2] = uVar9;
                      param_5[3] = uVar11;
                    }
                    if ((iVar1 == 0) && (param_6 == &local_38)) {
                      VariantClear((VARIANTARG *)&param_6->n2);
                    }
                  }
                }
                VariantClear((VARIANTARG *)&local_48.n2);
                return iVar1;
              }
              return HVar3;
            }
            goto LAB_404692c0;
          }
        }
LAB_40469234:
        if (puVar12[0x26] != 0) {
          iVar1 = FUN_40465260((int)pOVar13,(int)puVar12,(uint *)&local_64,(undefined4 *)0x0);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_64 + 0x2c))
                              (local_64,local_70,param_3,local_86,param_5,param_6,param_7,param_8);
            (**(code **)(*local_64 + 8))();
            return iVar1;
          }
          return iVar1;
        }
        goto LAB_404692c0;
      }
    }
    else {
      if (iVar1 == 4) {
        if ((*(uint *)(puVar12 + 0x18) & 0x40) != 0) goto LAB_40468a28;
        if ((*puVar12 & 0x10) == 0) goto LAB_404692c0;
        goto LAB_40469234;
      }
      if (iVar1 == 5) {
        return -0x7fffbfff;
      }
    }
    iVar1 = -0x7ff8ffa9;
  }
  else {
LAB_404692c0:
    iVar1 = -0x7ffdfffd;
  }
  return iVar1;
}



/* 404692fc FUN_404692fc */

/* Boundary evidence: original MIPS .pdata 404692fc..4046969f. Semantic name remains unreviewed. */

int FUN_404692fc(int param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  short sVar11;
  uint uVar12;
  int local_30 [2];
  
  if (((param_2 == (undefined4 *)0x0) || (param_4 == (uint *)0x0)) || (param_3 == 0)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    if ((param_3 != 0) && (param_3 != 0)) {
      puVar5 = param_4;
      do {
        *puVar5 = 0xffffffff;
        puVar5 = puVar5 + 1;
      } while (puVar5 != param_4 + param_3);
    }
    local_30[0] = -2;
    iVar3 = FUN_4045da0c(*(int *)(param_1 + 0xc));
    if ((-1 < iVar3) &&
       (iVar3 = FUN_4045c1b8(*(int *)(param_1 + 0xc),(ushort *)*param_2,0,local_30), -1 < iVar3)) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x20) + *(int *)(param_1 + 8);
      sVar11 = *(short *)(iVar3 + 0x4c);
      if ((sVar11 != 0) && ((*(uint *)(iVar3 + 0x30) & 0x2000) != 0)) {
        iVar4 = FUN_40467c18(param_1 + -4,iVar3,local_30[0],param_2,param_3,param_4);
        if (iVar4 != -0x7ffdfffa) {
          return iVar4;
        }
        sVar11 = 0;
      }
      if ((local_30[0] != -1) &&
         (*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0xac) + local_30[0]) != -1)) {
        if ((*(uint *)(iVar3 + 0x10) & 8) == 0) {
          iVar4 = FUN_4045a504((int *)(iVar3 + 4),*(int *)(param_1 + 0xc),0);
        }
        else {
          iVar4 = 0;
        }
        if (iVar4 < 0) {
          return iVar4;
        }
        uVar7 = (uint)*(ushort *)(iVar3 + 0x1a) + (uint)*(ushort *)(iVar3 + 0x18);
        uVar9 = 0;
        if (uVar7 != 0) {
          piVar6 = *(int **)(iVar3 + 0x24);
          do {
            if (*piVar6 == local_30[0]) goto LAB_4046949c;
            uVar9 = uVar9 + 1;
            piVar6 = piVar6 + 1;
          } while (uVar9 < uVar7);
        }
        uVar9 = 0xffffffff;
LAB_4046949c:
        if (uVar9 != 0xffffffff) {
          *param_4 = *(uint *)(*(int *)(iVar3 + 0x20) + uVar9 * 4);
          if ((1 < param_3) && (uVar9 < *(ushort *)(iVar3 + 0x18))) {
            puVar10 = (ushort *)
                      (*(int *)(*(int *)(iVar3 + 0x28) + uVar9 * 4) + *(int *)(iVar3 + 0x14));
            uVar1 = puVar10[8];
            while (((uVar1 & 0x60) != 0 &&
                   (puVar10 = (ushort *)
                              (*(int *)((uint)puVar10[9] * 4 + *(int *)(iVar3 + 0x28)) +
                              *(int *)(iVar3 + 0x14)), puVar10[1] != uVar9))) {
              uVar1 = puVar10[8];
            }
            uVar1 = puVar10[10];
            uVar7 = (uint)uVar1 - (uint)(puVar10[8] >> 0xe) & 0xffff;
            if ((puVar10[8] & 0x60) != 0) {
              uVar7 = uVar7 - 1;
            }
            uVar12 = 1;
            uVar9 = 0;
            uVar2 = *puVar10;
            if (1 < param_3) {
              iVar3 = (int)param_2 - (int)param_4;
              do {
                param_4 = param_4 + 1;
                iVar4 = FUN_4045c1b8(*(int *)(param_1 + 0xc),*(ushort **)(iVar3 + (int)param_4),0,
                                     local_30);
                if (iVar4 < 0) {
                  return iVar4;
                }
                if (local_30[0] == -1) {
                  return -0x7ffdfffa;
                }
                uVar8 = 0;
                if (uVar7 != 0) {
                  do {
                    if (uVar9 == uVar7) {
                      uVar9 = 0;
                    }
                    if (*(int *)((int)puVar10 + uVar9 * 0xc + (uint)uVar2 + (uint)uVar1 * -0xc + 4)
                        == local_30[0]) {
                      *param_4 = uVar9;
                      break;
                    }
                    uVar8 = uVar8 + 1;
                    uVar9 = uVar9 + 1;
                  } while (uVar8 < uVar7);
                }
                if (uVar8 == uVar7) {
                  return -0x7ffdfffa;
                }
                uVar12 = uVar12 + 1;
                uVar9 = uVar9 + 1;
              } while (uVar12 < param_3);
            }
          }
          return 0;
        }
      }
      if (sVar11 == 0) {
        iVar3 = -0x7ffdfffa;
      }
      else {
        iVar3 = FUN_40467c18(param_1 + -4,iVar3,local_30[0],param_2,param_3,param_4);
      }
    }
  }
  return iVar3;
}



/* 404696a0 FUN_404696a0 */

/* Boundary evidence: original MIPS .pdata 404696a0..40469827. Semantic name remains unreviewed. */

int FUN_404696a0(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  void *local_28;
  undefined4 local_24;
  int *local_20 [2];
  
  *param_2 = 0;
  (**(code **)(*param_1 + 4))(param_1);
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1,&local_28);
  if (-1 < iVar2) {
    while ((pvVar1 = local_28, *(int *)((int)local_28 + 0x28) != 4 &&
           (iVar3 = memcmp(local_28,&DAT_40443edc,0x10), iVar3 != 0))) {
      if (*(short *)((int)pvVar1 + 0x30) == 0) {
        *param_2 = 0;
        goto LAB_404697e0;
      }
      (**(code **)(*param_1 + 0x4c))(param_1,pvVar1);
      iVar2 = (**(code **)(*param_1 + 0x20))(param_1,0,&local_24);
      if ((iVar2 < 0) ||
         (iVar2 = (**(code **)(*param_1 + 0x38))(param_1,local_24,local_20), iVar2 < 0))
      goto LAB_404697f4;
      (**(code **)(*param_1 + 8))(param_1);
      param_1 = local_20[0];
      iVar2 = (**(code **)(*local_20[0] + 0xc))(local_20[0],&local_28);
      if (iVar2 < 0) goto LAB_404697f4;
    }
    *param_2 = 1;
LAB_404697e0:
    (**(code **)(*param_1 + 0x4c))(param_1,pvVar1);
  }
LAB_404697f4:
  (**(code **)(*param_1 + 8))(param_1);
  return iVar2;
}



/* 40469828 FUN_40469828 */

/* Boundary evidence: original MIPS .pdata 40469828..40469cd7. Semantic name remains unreviewed. */

int FUN_40469828(int *param_1,undefined4 *param_2,short *param_3,undefined4 *param_4,ushort *param_5
                )

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort local_48 [2];
  int *local_44;
  undefined4 *local_40;
  int *local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 *local_30 [2];
  
  *param_3 = 0;
  uVar1 = *(ushort *)(param_2 + 1);
  if (((uVar1 < 0xe) || (uVar1 == 0x19)) || ((0xf < uVar1 && (uVar1 < 0x14)))) {
    *param_5 = uVar1;
    return 0;
  }
  if (uVar1 == 0x16) {
    *param_5 = 3;
    return 0;
  }
  if (uVar1 == 0x17) {
    local_48[0] = 0x13;
LAB_40469c84:
    *param_5 = local_48[0];
    return 0;
  }
  if (uVar1 == 0x18) {
    *param_5 = 0;
    return 0;
  }
  if (uVar1 == 0x1a) {
    iVar2 = FUN_40469828(param_1,(undefined4 *)*param_2,param_3,param_4,local_48);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (*param_3 == 1) {
      *param_5 = local_48[0];
      *param_3 = *param_3 + 1;
      return 0;
    }
    if ((local_48[0] & 0x4000) != 0) {
      return -0x7ffdfff8;
    }
    local_48[0] = local_48[0] | 0x4000;
    goto LAB_40469c84;
  }
  if (uVar1 == 0x1b) {
    iVar2 = FUN_40469828(param_1,(undefined4 *)*param_2,param_3,param_4,local_48);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((local_48[0] & 0x6000) != 0) {
      return -0x7ffdfff8;
    }
    local_48[0] = local_48[0] | 0x2000;
    goto LAB_40469c84;
  }
  if (uVar1 != 0x1d) {
    return -0x7ffdfff8;
  }
  iVar2 = (**(code **)(*param_1 + 0x38))(param_1,*param_2,&local_44);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(*local_44 + 0xc))(local_44,&local_40);
  if (iVar2 != 0) goto LAB_40469bac;
  iVar3 = local_40[10];
  if (iVar3 == 0) {
    *param_5 = 3;
    goto LAB_40469b98;
  }
  if (iVar3 == 3) {
    iVar2 = FUN_404696a0(local_44,local_30);
    if (-1 < iVar2) {
      if (local_30[0] != (undefined4 *)0x0) goto LAB_40469b10;
      *param_5 = 0xd;
    }
LAB_40469b50:
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *local_40;
      param_4[1] = local_40[1];
      param_4[2] = local_40[2];
      param_4[3] = local_40[3];
    }
    *param_3 = *param_3 + 1;
  }
  else {
    if (iVar3 == 4) {
LAB_40469b10:
      *param_5 = 9;
      goto LAB_40469b50;
    }
    if (iVar3 == 5) {
      *param_5 = 9;
      if (param_4 != (undefined4 *)0x0) {
        uVar4 = (uint)*(ushort *)(local_40 + 0xc);
        uVar5 = 0;
        if (uVar4 != 0) {
          do {
            iVar2 = (**(code **)(*local_44 + 0x24))(local_44,uVar5,&local_38);
            if (iVar2 < 0) goto LAB_40469b98;
            if ((local_38 & 3) == 1) {
              iVar2 = (**(code **)(*local_44 + 0x20))(local_44,uVar5,&local_34);
              if ((iVar2 < 0) ||
                 (iVar2 = (**(code **)(*local_44 + 0x38))(local_44,local_34,&local_3c), iVar2 < 0))
              goto LAB_40469b98;
              break;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar4);
        }
        if (uVar5 == uVar4) {
          iVar2 = -0x7ffdfffb;
          goto LAB_40469b98;
        }
        iVar2 = (**(code **)(*local_3c + 0xc))(local_3c,local_30);
        if (iVar2 == 0) {
          *param_4 = *local_30[0];
          param_4[1] = local_30[0][1];
          param_4[2] = local_30[0][2];
          param_4[3] = local_30[0][3];
          if ((local_30[0][10] == 3) && ((*(ushort *)((int)local_30[0] + 0x36) & 0x40) == 0)) {
            *param_5 = 0xd;
          }
          (**(code **)(*local_3c + 0x4c))();
        }
        (**(code **)(*local_3c + 8))();
      }
      *param_3 = *param_3 + 1;
    }
    else if (iVar3 == 6) {
      iVar2 = FUN_40469828(local_44,local_40 + 0xf,param_3,param_4,param_5);
    }
    else {
      iVar2 = -0x7ffdfff8;
    }
  }
LAB_40469b98:
  (**(code **)(*local_44 + 0x4c))(local_44,local_40);
LAB_40469bac:
  (**(code **)(*local_44 + 8))();
  return iVar2;
}



/* 40469cd8 FUN_40469cd8 */

/* Boundary evidence: original MIPS .pdata 40469cd8..40469e9f. Semantic name remains unreviewed. */

undefined4 FUN_40469cd8(uint param_1,ULONG param_2,undefined4 *param_3)

{
  BSTR bstrString;
  undefined4 uVar1;
  HRESULT HVar2;
  SAFEARRAY *pSVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  SAFEARRAY **ppsaOut;
  uint uVar7;
  SAFEARRAYBOUND local_20;
  
  bstrString = SysAllocStringByteLen((LPCSTR)0x0,param_1 * 0x2b + 0x20);
  if (bstrString == (BSTR)0x0) {
LAB_40469e78:
    uVar1 = 0x8007000e;
  }
  else {
    ppsaOut = (SAFEARRAY **)(bstrString + 0xe);
    *(uint *)bstrString = param_1;
    *ppsaOut = (SAFEARRAY *)0x0;
    if (param_1 == 0) {
      bstrString[6] = L'\0';
      bstrString[7] = L'\0';
      bstrString[4] = L'\0';
      bstrString[5] = L'\0';
      bstrString[2] = L'\0';
      bstrString[3] = L'\0';
      bstrString[0xc] = L'\0';
      bstrString[0xd] = L'\0';
    }
    else {
      *(BSTR *)(bstrString + 6) = bstrString + 0x10;
      *(BSTR *)(bstrString + 8) = bstrString + (param_1 + 2) * 8;
      *(BSTR *)(bstrString + 4) = bstrString + (param_1 + 1) * 0x10;
      uVar7 = 0;
      *(BSTR *)(bstrString + 10) = bstrString + param_1 * 0x12 + 0x10;
      *(BSTR *)(bstrString + 2) = bstrString + param_1 * 0x14 + 0x10;
      *(BSTR *)(bstrString + 0xc) = bstrString + param_1 * 0x15 + 0x10;
      if (param_1 != 0) {
        iVar5 = 0;
        iVar6 = 0;
        do {
          *(undefined2 *)(*(int *)(bstrString + 6) + iVar6) = 0;
          *(undefined4 *)(*(int *)(bstrString + 10) + iVar5) = 0;
          puVar4 = (undefined1 *)(*(int *)(bstrString + 0xc) + uVar7);
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0x10;
          *puVar4 = 1;
          iVar5 = iVar5 + 4;
        } while (uVar7 < param_1);
      }
      if (param_2 != 0xffffffff) {
        if (param_2 == 0) {
          HVar2 = SafeArrayAllocDescriptor(1,ppsaOut);
          if (HVar2 != 0) {
LAB_40469e70:
            SysFreeString(bstrString);
            goto LAB_40469e78;
          }
        }
        else {
          local_20.lLbound = 0;
          local_20.cElements = param_2;
          pSVar3 = SafeArrayCreate(0xc,1,&local_20);
          *ppsaOut = pSVar3;
          if (pSVar3 == (SAFEARRAY *)0x0) goto LAB_40469e70;
        }
      }
    }
    *param_3 = bstrString;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40469ea0 FUN_40469ea0 */

/* Boundary evidence: original MIPS .pdata 40469ea0..40469ebb. Semantic name remains unreviewed. */

void FUN_40469ea0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40469ebc FUN_40469ebc */

/* Boundary evidence: original MIPS .pdata 40469ebc..40469f03. Semantic name remains unreviewed. */

LONG FUN_40469ebc(LPVOID param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 4));
  if (LVar1 == 0) {
    FUN_40458abc(param_1);
  }
  return LVar1;
}



/* 40469f04 FUN_40469f04 */

/* Boundary evidence: original MIPS .pdata 40469f04..40469f6f. Semantic name remains unreviewed. */

undefined4 FUN_40469f04(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    piVar2 = FUN_404589c4(8);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      *piVar2 = param_2;
      piVar2[1] = *(int *)(param_1 + 8);
      *(int **)(param_1 + 8) = piVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40469f70 FUN_40469f70 */

/* Boundary evidence: original MIPS .pdata 40469f70..40469ff7. Semantic name remains unreviewed. */

undefined4 FUN_40469f70(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0x80070057;
  }
  else {
    piVar1 = (int *)0x0;
    for (piVar2 = *(int **)(param_1 + 8); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      if (param_2 == *piVar2) {
        if (piVar1 == (int *)0x0) {
          *(int *)(param_1 + 8) = piVar2[1];
        }
        else {
          piVar1[1] = piVar2[1];
        }
        FUN_40458abc(piVar2);
        return 0;
      }
      piVar1 = piVar2;
    }
    uVar3 = 0x80004003;
  }
  return uVar3;
}



/* 40469ff8 FUN_40469ff8 */

/* Boundary evidence: original MIPS .pdata 40469ff8..4046a013. Semantic name remains unreviewed. */

void FUN_40469ff8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 4046a014 FUN_4046a014 */

/* Boundary evidence: original MIPS .pdata 4046a014..4046a0ab. Semantic name remains unreviewed. */

LONG FUN_4046a014(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    while (param_1[7] != 0) {
      (**(code **)(*param_1 + 0x18))(param_1,param_1[7]);
    }
    if (param_1[6] != 0) {
      FUN_40469f70(param_1[6],(int)param_1);
      (**(code **)(*(int *)param_1[6] + 8))();
    }
    FUN_40458abc(param_1);
  }
  return LVar1;
}



/* 4046a0ec FUN_4046a0ec */

/* Boundary evidence: original MIPS .pdata 4046a0ec..4046a12f. Semantic name remains unreviewed. */

undefined4 FUN_4046a0ec(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x18);
    *param_2 = piVar2;
    (**(code **)(*piVar2 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 4046a130 FUN_4046a130 */

/* Boundary evidence: original MIPS .pdata 4046a130..4046a1fb. Semantic name remains unreviewed. */

undefined4 FUN_4046a130(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  if ((param_3 == (undefined4 *)0x0) || (*param_3 = 0, param_2 == (undefined4 *)0x0)) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = FUN_404589c4(8);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      iVar3 = (**(code **)*param_2)(param_2,param_1 + 8,local_20);
      if (iVar3 < 0) {
        FUN_40458abc(puVar2);
        uVar1 = 0x80004002;
      }
      else {
        uVar1 = 0;
        *puVar2 = local_20[0];
        puVar2[1] = *(undefined4 *)(param_1 + 0x1c);
        *(undefined4 **)(param_1 + 0x1c) = puVar2;
        *param_3 = puVar2;
      }
    }
  }
  return uVar1;
}



/* 4046a1fc FUN_4046a1fc */

/* Boundary evidence: original MIPS .pdata 4046a1fc..4046a2a3. Semantic name remains unreviewed. */

undefined4 FUN_4046a1fc(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
    for (puVar2 = *(undefined4 **)(param_1 + 0x1c); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[1]) {
      if (param_2 == puVar2) {
        (**(code **)(*(int *)*puVar2 + 8))();
        if (puVar1 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0x1c) = puVar2[1];
        }
        else {
          puVar1[1] = puVar2[1];
        }
        FUN_40458abc(puVar2);
        return 0;
      }
      puVar1 = puVar2;
    }
  }
  return 0x80070057;
}



/* 4046a2cc FUN_4046a2cc */

/* Boundary evidence: original MIPS .pdata 4046a2cc..4046a357. Semantic name remains unreviewed. */

int FUN_4046a2cc(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_40469f04((int)param_2,param_1);
  if ((iVar1 == 0) || (-1 < iVar1)) {
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 0x18) = param_2;
    iVar1 = 0;
    *(undefined4 *)(param_1 + 8) = *param_3;
    *(undefined4 *)(param_1 + 0xc) = param_3[1];
    *(undefined4 *)(param_1 + 0x10) = param_3[2];
    *(undefined4 *)(param_1 + 0x14) = param_3[3];
  }
  return iVar1;
}



/* 4046a358 FUN_4046a358 */

/* Boundary evidence: original MIPS .pdata 4046a358..4046a417. Semantic name remains unreviewed. */

int FUN_4046a358(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int local_20 [2];
  
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x20) == 0) {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
      local_20[0] = 0;
      iVar1 = (**(code **)(*(int *)*puVar2 + 0xc))((int *)*puVar2,param_2,param_3,param_4,local_20);
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_20[0] != 0) {
        return -0x7fffbffb;
      }
    }
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return 0;
}



/* 4046a418 FUN_4046a418 */

/* Boundary evidence: original MIPS .pdata 4046a418..4046a4c3. Semantic name remains unreviewed. */

int FUN_4046a418(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x20) == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)puVar2[1]) {
      iVar1 = (**(code **)(*(int *)*puVar2 + 0x10))((int *)*puVar2,param_2,param_3,param_4);
      if ((iVar1 != 0) && (iVar1 < 0)) {
        return iVar1;
      }
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 4046a4c4 FUN_4046a4c4 */

/* Boundary evidence: original MIPS .pdata 4046a4c4..4046a587. Semantic name remains unreviewed. */

undefined4 FUN_4046a4c4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40443ebc,0x10);
    if (((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40441ccc,0x10), iVar2 == 0)) ||
       (iVar2 = memcmp(param_2,&DAT_40443f4c,0x10), iVar2 == 0)) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 4046a588 FUN_4046a588 */

/* Boundary evidence: original MIPS .pdata 4046a588..4046a61f. Semantic name remains unreviewed. */

undefined4 FUN_4046a588(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
    for (piVar2 = *(int **)(param_1 + 8); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      iVar1 = memcmp(param_2,(void *)(*piVar2 + 8),0x10);
      if (iVar1 == 0) {
        piVar2 = (int *)*piVar2;
        *param_3 = (int)piVar2;
        (**(code **)(*piVar2 + 4))();
        return 0;
      }
    }
  }
  return 0x80070057;
}



/* 4046a620 FUN_4046a620 */

/* Boundary evidence: original MIPS .pdata 4046a620..4046a6e3. Semantic name remains unreviewed. */

undefined4 FUN_4046a620(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40443ebc,0x10);
    if (((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40443f9c,0x10), iVar2 == 0)) ||
       (iVar2 = memcmp(param_2,&DAT_40441cdc,0x10), iVar2 == 0)) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 4046a6e4 FUN_4046a6e4 */

/* Boundary evidence: original MIPS .pdata 4046a6e4..4046a72f. Semantic name remains unreviewed. */

undefined4 * FUN_4046a6e4(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_404589c4(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = 1;
    puVar1[6] = 0;
    puVar1[7] = 0;
    *puVar1 = &PTR_FUN_40443e68;
    puVar1[8] = 0;
  }
  return puVar1;
}



/* 4046a730 FUN_4046a730 */

/* Boundary evidence: original MIPS .pdata 4046a730..4046a773. Semantic name remains unreviewed. */

undefined4 * FUN_4046a730(void)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_404589c4(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_40443e88;
    puVar1[1] = 1;
    puVar1[2] = 0;
  }
  return puVar1;
}



/* 4046a774 FUN_4046a774 */

/* Boundary evidence: original MIPS .pdata 4046a774..4046a82b. Semantic name remains unreviewed. */

HRESULT FUN_4046a774(void *param_1)

{
  HRESULT HVar1;
  IErrorInfo *local_18 [2];
  
  memset(param_1,0,0x20);
  HVar1 = GetErrorInfo(0,local_18);
  if (HVar1 == 0) {
    (*local_18[0]->lpVtbl->GetSource)(local_18[0],(BSTR *)((int)param_1 + 4));
    (*local_18[0]->lpVtbl->GetDescription)(local_18[0],(BSTR *)((int)param_1 + 8));
    (*local_18[0]->lpVtbl->GetHelpFile)(local_18[0],(BSTR *)((int)param_1 + 0xc));
    (*local_18[0]->lpVtbl->GetHelpContext)(local_18[0],(DWORD *)((int)param_1 + 0x10));
    (*local_18[0]->lpVtbl->Release)(local_18[0]);
  }
  return HVar1;
}



/* 4046a82c FUN_4046a82c */

undefined4 FUN_4046a82c(void)

{
  return 0x78;
}



/* 4046aa34 FUN_4046aa34 */

/* Boundary evidence: original MIPS .pdata 4046aa34..4046ab6f. Semantic name remains unreviewed. */

int FUN_4046aa34(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_4046ded4 != (code *)0x0) {
      iVar2 = (*DAT_4046ded4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4046aae4;
    FUN_4046b13c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_404440c0(param_1,param_2);
  }
LAB_4046aae4:
  if (((param_2 == 0) && (FUN_4046b0c4(), iVar1 != 0)) && (DAT_4046ded4 != (code *)0x0)) {
    iVar1 = (*DAT_4046ded4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 4046ab70 FUN_4046ab70 */

/* Boundary evidence: original MIPS .pdata 4046ab70..4046ab9b. Semantic name remains unreviewed. */

void FUN_4046ab70(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 4046ab9c entry */

/* Boundary evidence: original MIPS .pdata 4046ab9c..4046abf3. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_4046abf4();
  }
  FUN_4046aa34(param_1,param_2,param_3);
  return;
}



/* 4046abf4 FUN_4046abf4 */

/* Boundary evidence: original MIPS .pdata 4046abf4..4046ac67. Semantic name remains unreviewed. */

void FUN_4046abf4(void)

{
  uint uVar1;
  
  if ((DAT_4046d1b8 == 0) || (DAT_4046d1b8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4046d1b8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4046d1b8 == 0) {
      DAT_4046d1b8 = 0xb064;
    }
  }
  DAT_4046d1bc = ~DAT_4046d1b8;
  return;
}



/* 4046ac68 FUN_4046ac68 */

/* Boundary evidence: original MIPS .pdata 4046ac68..4046acbb. Semantic name remains unreviewed. */

void FUN_4046ac68(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4046ace8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4046acbc FUN_4046acbc */

/* Boundary evidence: original MIPS .pdata 4046acbc..4046ace7. Semantic name remains unreviewed. */

undefined4 FUN_4046acbc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4046ac68(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4046ace8 FUN_4046ace8 */

/* Boundary evidence: original MIPS .pdata 4046ace8..4046ad2f. Semantic name remains unreviewed. */

void FUN_4046ace8(uint param_1)

{
  if ((param_1 == DAT_4046d1b8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 4046ad30 FUN_4046ad30 */

/* Boundary evidence: original MIPS .pdata 4046ad30..4046ae3b. Semantic name remains unreviewed. */

undefined4 FUN_4046ad30(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_4046decc;
  puVar3 = DAT_4046dec8;
  iVar4 = (int)DAT_4046dec8 - (int)DAT_4046decc;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_4046ad74:
    param_1 = 0;
  }
  else {
    if (DAT_4046decc != (void *)0x0) {
      uVar1 = _msize(DAT_4046decc);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_4046ade8:
        if (pvVar2 == (void *)0x0) goto LAB_4046ad74;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_4046ade8;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_4046dec8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_4046decc = pvVar2;
  }
  return param_1;
}



/* 4046ae3c FUN_4046ae3c */

/* Boundary evidence: original MIPS .pdata 4046ae3c..4046af27. Semantic name remains unreviewed. */

undefined4 FUN_4046ae3c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_4046ded0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_4046ded0,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_4046ded0 == (LPCRITICAL_SECTION)0x0) goto LAB_4046aee0;
  }
  EnterCriticalSection(DAT_4046ded0);
LAB_4046aee0:
  uVar2 = FUN_4046ad30(param_1);
  FUN_4046af28();
  return uVar2;
}



/* 4046af28 FUN_4046af28 */

/* Boundary evidence: original MIPS .pdata 4046af28..4046af73. Semantic name remains unreviewed. */

void FUN_4046af28(void)

{
  if (DAT_4046ded0 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_4046ded0);
  }
  return;
}



/* 4046af74 FUN_4046af74 */

/* Boundary evidence: original MIPS .pdata 4046af74..4046afa3. Semantic name remains unreviewed. */

undefined4 FUN_4046af74(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4046ae3c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4046afa4 FUN_4046afa4 */

/* Boundary evidence: original MIPS .pdata 4046afa4..4046b0c3. Semantic name remains unreviewed. */

void FUN_4046afa4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4046dec4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4046decc;
    if (DAT_4046decc != (undefined4 *)0x0) {
      while (DAT_4046dec8 = DAT_4046dec8 + -1, _Memory <= DAT_4046dec8) {
        if ((code *)*DAT_4046dec8 != (code *)0x0) {
          (*(code *)*DAT_4046dec8)();
          _Memory = DAT_4046decc;
        }
      }
      free(_Memory);
      DAT_4046dec8 = (undefined4 *)0x0;
      DAT_4046decc = (undefined4 *)0x0;
    }
    FUN_4046b0e8((undefined4 *)&DAT_40441014,(undefined4 *)&DAT_40441018);
  }
  FUN_4046b0e8((undefined4 *)&DAT_4044101c,(undefined4 *)&DAT_40441020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_4046ded0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4046b0c4 FUN_4046b0c4 */

/* Boundary evidence: original MIPS .pdata 4046b0c4..4046b0e7. Semantic name remains unreviewed. */

void FUN_4046b0c4(void)

{
  FUN_4046afa4(0,0,1);
  return;
}



/* 4046b0e8 FUN_4046b0e8 */

/* Boundary evidence: original MIPS .pdata 4046b0e8..4046b13b. Semantic name remains unreviewed. */

void FUN_4046b0e8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4046b13c FUN_4046b13c */

/* Boundary evidence: original MIPS .pdata 4046b13c..4046b177. Semantic name remains unreviewed. */

void FUN_4046b13c(void)

{
  FUN_4046b0e8((undefined4 *)&DAT_4044100c,(undefined4 *)&DAT_40441010);
  FUN_4046b0e8((undefined4 *)&DAT_40441000,(undefined4 *)&DAT_40441008);
  return;
}



/* 4046b4a8 FUN_4046b4a8 */

/* Boundary evidence: original MIPS .pdata 4046b4a8..4046b4d7. Semantic name remains unreviewed. */

void FUN_4046b4a8(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4046dea4);
  FUN_4046af74(FUN_4046b4d8);
  return;
}



/* 4046b4d8 FUN_4046b4d8 */

/* Boundary evidence: original MIPS .pdata 4046b4d8..4046b4fb. Semantic name remains unreviewed. */

void FUN_4046b4d8(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4046dea4);
  return;
}


