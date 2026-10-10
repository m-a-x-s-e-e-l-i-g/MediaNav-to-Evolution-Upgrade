/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0671900 FUN_c0671900 */

/* Boundary evidence: original MIPS .pdata c0671900..c06719ab. Semantic name remains unreviewed. */

void FUN_c0671900(void)

{
  int *hMem;
  int iVar1;
  int *piVar2;
  undefined4 local_18 [2];
  
  hMem = FUN_c067e044(&DAT_c0686160);
  if (hMem != (int *)0x0) {
    if (*hMem != 0) {
      local_18[0] = 0xed000000;
      iVar1 = *hMem;
      piVar2 = hMem;
      while (iVar1 != 0) {
        piVar2 = piVar2 + 1;
        (**(code **)(*(int *)(iVar1 + 0x18) + 0x28))(0xed000000,0,0xffffffff,0,local_18,4);
        iVar1 = *piVar2;
      }
    }
    LocalFree(hMem);
  }
  return;
}



/* c06719ac FUN_c06719ac */

/* Boundary evidence: original MIPS .pdata c06719ac..c0671a63. Semantic name remains unreviewed. */

void FUN_c06719ac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if ((param_1 == 0) || (param_1 == 4)) {
    piVar3 = (int *)0x0;
    while( true ) {
      uVar5 = 0;
      piVar1 = FUN_c067c5ac(param_2,piVar3,(wchar_t *)0x0);
      if (piVar1 == (int *)0x0) break;
      FUN_c067a798(piVar1,piVar3,uVar5,param_4);
      FUN_c06825a0(piVar1,piVar3,uVar5,param_4);
      piVar3 = piVar1;
    }
    puVar4 = (undefined4 *)0x0;
    while (puVar2 = FUN_c067c848(param_2,puVar4), puVar2 != (undefined4 *)0x0) {
      FUN_c0673f0c(puVar2,puVar4,uVar5,param_4);
      FUN_c068185c(puVar2);
      puVar4 = puVar2;
    }
  }
  else if (param_1 == 5) {
    FUN_c0671900();
  }
  return;
}



/* c0671a6c FUN_c0671a6c */

/* Boundary evidence: original MIPS .pdata c0671a6c..c0671d4f. Semantic name remains unreviewed. */

undefined4 FUN_c0671a6c(void)

{
  LSTATUS LVar1;
  int iVar2;
  DWORD dwIndex;
  HKEY local_160;
  HKEY local_15c;
  undefined4 local_158;
  DWORD local_154;
  int local_150;
  int local_14c;
  DWORD DStack_148;
  DWORD local_144;
  int local_140;
  DWORD DStack_13c;
  _FILETIME _Stack_138;
  WCHAR aWStack_130 [128];
  uint local_30;
  
  local_30 = DAT_c068610c;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"TAPI\\TSP",0,0x20019,&local_160);
  if (LVar1 != 0) {
    LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"TAPI\\TSP",0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,&local_160,&DStack_148);
    if (LVar1 != 0) {
      FUN_c0684adc(local_30);
      return 0xffffffff;
    }
    local_158 = 1;
    RegSetValueExW(local_160,L"PPID",0,4,(BYTE *)&local_158,4);
    LVar1 = RegCreateKeyExW(local_160,L"unimodem.dll",0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                            &local_15c,&DStack_148);
    if (LVar1 == 0) {
      RegSetValueExW(local_15c,L"PPID",0,4,(BYTE *)&local_158,4);
      RegCloseKey(local_15c);
    }
  }
  dwIndex = 0;
  local_154 = 0x80;
  iVar2 = RegEnumKeyExW(local_160,0,aWStack_130,&local_154,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                        &_Stack_138);
  while (iVar2 == 0) {
    iVar2 = FUN_c067daa0(aWStack_130,&local_140,&local_150);
    if (((iVar2 == 0) &&
        (iVar2 = FUN_c067fe54(aWStack_130,local_140,local_150,&local_14c), iVar2 == 0)) &&
       (LVar1 = RegOpenKeyExW(local_160,aWStack_130,0,0x20019,&local_15c), LVar1 == 0)) {
      local_144 = 4;
      RegQueryValueExW(local_15c,L"PPID",(LPDWORD)0x0,&DStack_13c,(LPBYTE)&local_158,&local_144);
      RegCloseKey(local_15c);
      *(undefined4 *)(local_14c + 0xc) = local_158;
    }
    dwIndex = dwIndex + 1;
    local_154 = 0x80;
    iVar2 = RegEnumKeyExW(local_160,dwIndex,aWStack_130,&local_154,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,&_Stack_138);
  }
  RegCloseKey(local_160);
  FUN_c0684adc(local_30);
  return 0;
}



/* c0671d50 FUN_c0671d50 */

/* Boundary evidence: original MIPS .pdata c0671d50..c0671f23. Semantic name remains unreviewed. */

void FUN_c0671d50(void)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  memset(&DAT_c0686140,0,0xcc);
  DAT_c06861d0 = 0x80000050;
  DAT_c06861e0 = 0x90000022;
  DAT_c0686148 = 0;
  DAT_c06861ec = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_c06861f0 = 0;
  DAT_c0686164 = &DAT_c0686160;
  DAT_c0686160 = &DAT_c0686160;
  DAT_c0686194 = &DAT_c0686190;
  DAT_c0686190 = &DAT_c0686190;
  DAT_c0686184 = &DAT_c0686180;
  DAT_c0686180 = &DAT_c0686180;
  DAT_c068618c = &DAT_c0686188;
  DAT_c0686188 = &DAT_c0686188;
  DAT_c0686174 = &DAT_c0686170;
  DAT_c0686170 = &DAT_c0686170;
  DAT_c068617c = &DAT_c0686178;
  DAT_c0686178 = &DAT_c0686178;
  DAT_c068616c = &DAT_c0686168;
  DAT_c0686168 = &DAT_c0686168;
  DAT_c06861ac = &DAT_c06861a8;
  DAT_c06861a8 = &DAT_c06861a8;
  DAT_c068619c = &DAT_c0686198;
  DAT_c0686198 = &DAT_c0686198;
  DAT_c06861a4 = &DAT_c06861a0;
  DAT_c06861a0 = &DAT_c06861a0;
  DAT_c06861b4 = &DAT_c06861b0;
  DAT_c06861b0 = &DAT_c06861b0;
  DAT_c06861e4 = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"TAPI",0,0x20019,&local_20);
  if (LVar1 == 0) {
    local_1c = 4;
    LVar1 = RegQueryValueExW(local_20,L"AsyncReplyDelayMs",(LPDWORD)0x0,aDStack_18,
                             (LPBYTE)&DAT_c06861f4,&local_1c);
    RegCloseKey(local_20);
    if (LVar1 == 0) goto LAB_c0671f08;
  }
  DAT_c06861f4 = 200;
LAB_c0671f08:
  FUN_c0671a6c();
  return;
}



/* c0671f24 FUN_c0671f24 */

/* Boundary evidence: original MIPS .pdata c0671f24..c0671f57. Semantic name remains unreviewed. */

undefined4 FUN_c0671f24(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0671f58 FUN_c0671f58 */

/* Boundary evidence: original MIPS .pdata c0671f58..c067208b. Semantic name remains unreviewed. */

undefined4 FUN_c0671f58(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  HKEY hKey;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined4 local_38;
  undefined1 auStack_34 [12];
  uint local_28;
  
  local_28 = DAT_c068610c;
  local_38 = 0;
  memset(auStack_34,0,0xc);
  uVar1 = RequestDeviceNotifications(&local_38,param_1,1);
  iVar2 = ReadMsgQueue(param_1,&DAT_c0686220,0xe8,auStack_40,0xffffffff,auStack_3c);
  while (iVar2 == 1) {
    hKey = (HKEY)RegOpenProcessKey(DAT_c0686230);
    FUN_c067f038(hKey,&DAT_c068623c,(uint)(DAT_c0686234 == 0));
    RegCloseKey(hKey);
    iVar2 = ReadMsgQueue(param_1,&DAT_c0686220,0xe8,auStack_40,0xffffffff,auStack_3c);
  }
  StopDeviceNotifications(uVar1);
  FUN_c0684adc(local_28);
  return 0;
}



/* c06720c0 Init */

/* Boundary evidence: original MIPS .pdata c06720c0..c06721af. Semantic name remains unreviewed. */

undefined4 Init(void)

{
  undefined4 uVar1;
  LPVOID lpParameter;
  HANDLE hObject;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x20c0  2  Init */
  FUN_c0671d50();
  uVar1 = CreateAPISet(&DAT_c0671680,0x5d,&PTR_FUN_c067104c,&DAT_c0671338);
  SetAPIErrorHandler(uVar1,&LAB_c067208c);
  RegisterDirectMethods(uVar1,&PTR_FUN_c06711c0);
  RegisterAPISet(uVar1,0x57);
  local_20 = 0x14;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0xe8;
  local_10 = 1;
  lpParameter = (LPVOID)CreateMsgQueue(0,&local_20);
  if (lpParameter != (LPVOID)0x0) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0671f58,lpParameter,0,(LPDWORD)0x0);
    if (hObject == (HANDLE)0x0) {
      hObject = lpParameter;
    }
    CloseHandle(hObject);
  }
  return 0x454e494c;
}



/* c06721b0 Deinit */

undefined4 Deinit(void)

{
                    /* 0x21b0  1  Deinit */
  return 1;
}



/* c06721b8 FUN_c06721b8 */

/* Boundary evidence: original MIPS .pdata c06721b8..c06723db. Semantic name remains unreviewed. */

uint FUN_c06721b8(uint param_1)

{
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if ((param_1 & 0x80000000) != 0) {
    switch(param_1) {
    case 0x80000001:
      param_1 = 0x90000001;
      break;
    case 0x80000002:
      param_1 = 0x90000002;
      break;
    case 0x8000000c:
      param_1 = 0x90000003;
      break;
    case 0x8000000d:
      param_1 = 0x90000004;
      break;
    case 0x8000000e:
      param_1 = 0x90000005;
      break;
    case 0x8000000f:
      param_1 = 0x90000006;
      break;
    case 0x80000014:
      param_1 = 0x90000007;
      break;
    case 0x80000015:
      param_1 = 0x90000008;
      break;
    case 0x80000023:
      param_1 = 0x9000000d;
      break;
    case 0x80000029:
      param_1 = 0x9000000e;
      break;
    case 0x80000032:
      param_1 = 0x90000012;
      break;
    case 0x80000035:
      param_1 = 0x90000015;
      break;
    case 0x80000042:
      param_1 = 0x90000018;
      break;
    case 0x80000043:
      param_1 = 0x90000019;
      break;
    case 0x80000044:
      param_1 = 0x9000001a;
      break;
    case 0x80000046:
      param_1 = 0x9000001b;
      break;
    case 0x80000048:
      param_1 = 0x9000001c;
      break;
    case 0x80000049:
      param_1 = 0x9000001d;
      break;
    case 0x8000004b:
      param_1 = 0x9000001f;
      break;
    case 0x8000004c:
      param_1 = 0x90000020;
      break;
    case 0x8000004d:
      param_1 = 0x90000021;
      break;
    case 0x80000050:
      param_1 = 0x90000022;
      break;
    case 0x80000052:
      param_1 = 0x90000023;
    }
  }
  return param_1;
}



/* c06723dc FUN_c06723dc */

/* Boundary evidence: original MIPS .pdata c06723dc..c06724a3. Semantic name remains unreviewed. */

void FUN_c06723dc(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c067d338(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x90000013;
  }
  else {
    uVar2 = 0;
    FUN_c067bc18();
    FUN_c0680014((int)param_1);
    FUN_c067bc40();
    FUN_c0681344(param_1);
    FUN_c0681344(param_1);
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c06724a4 FUN_c06724a4 */

/* Boundary evidence: original MIPS .pdata c06724a4..c06724af. Semantic name remains unreviewed. */

undefined4 FUN_c06724a4(void)

{
  return 1;
}



/* c06724b0 FUN_c06724b0 */

/* Boundary evidence: original MIPS .pdata c06724b0..c067257b. Semantic name remains unreviewed. */

void FUN_c06724b0(int param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  int *piVar1;
  uint uVar2;
  HLOCAL hMem;
  
  hMem = (HLOCAL)0x0;
  if ((param_3 == (STRSAFE_PCNZWCH)0x0) || (hMem = FUN_c067c2ec(param_3), hMem != (HLOCAL)0x0)) {
    uVar2 = FUN_c067c458(param_2);
    if (uVar2 == 0) {
      piVar1 = FUN_c067c998(param_1);
      if (piVar1 == (int *)0x0) {
        uVar2 = 0x90000002;
      }
      else {
        uVar2 = (**(code **)(*(int *)(piVar1[5] + 0x18) + 300))(param_1,param_2,hMem);
      }
    }
  }
  else {
    uVar2 = 0x90000015;
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c067257c FUN_c067257c */

/* Boundary evidence: original MIPS .pdata c067257c..c06726ab. Semantic name remains unreviewed. */

void FUN_c067257c(int *param_1,int param_2,int *param_3,int *param_4)

{
  bool bVar1;
  HLOCAL hMem;
  int iVar2;
  HLOCAL pvVar3;
  uint uVar4;
  int local_20;
  int local_1c;
  
  local_20 = -0x6fffffee;
  uVar4 = 0x90000015;
  pvVar3 = (HLOCAL)0x0;
  if (param_3 != (int *)0x0) {
    pvVar3 = (HLOCAL)0x0;
    hMem = FUN_c067c1e4(param_2,(uint)param_3,0);
    if (hMem != (HLOCAL)0x0) {
      iVar2 = FUN_c067d338(param_1);
      if (iVar2 == 0) {
        uVar4 = 0x90000013;
      }
      else {
        param_4 = &local_20;
        pvVar3 = (HLOCAL)0x0;
        uVar4 = FUN_c067f070(0x19,param_1,(int *)0x0,param_4,&local_1c,(int *)0x0,hMem,0);
        bVar1 = uVar4 == 0;
        if (bVar1) {
          pvVar3 = hMem;
          uVar4 = (**(code **)(*(int *)(*(int *)(local_1c + 0x14) + 0x18) + 0x130))
                            (local_20,*(undefined4 *)(local_1c + 0x18));
          FUN_c0681344(param_1);
          param_4 = param_3;
        }
        FUN_c0681344(param_1);
        if (bVar1) goto LAB_c0672678;
      }
      LocalFree(hMem);
    }
  }
LAB_c0672678:
  uVar4 = FUN_c06721b8(uVar4);
  FUN_c067c160(uVar4,local_20,(int)pvVar3,(int)param_4);
  return;
}



/* c06726ac FUN_c06726ac */

/* Boundary evidence: original MIPS .pdata c06726ac..c06727fb. Semantic name remains unreviewed. */

void FUN_c06726ac(undefined4 *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *local_28 [2];
  
  local_28[0] = (undefined4 *)0x0;
  uVar1 = FUN_c067e1b0(param_5,0xc4,local_28,1,param_6);
  if ((uVar1 == 0) && (iVar2 = FUN_c067d24c((int)param_1), uVar1 = DAT_c06861e0, iVar2 != 0)) {
    piVar3 = FUN_c067c998(param_2);
    if (piVar3 == (int *)0x0) {
      uVar1 = 0x90000002;
    }
    else {
      iVar2 = FUN_c067cd94(param_3,piVar3[0xb]);
      if (iVar2 == 0) {
        uVar1 = 0x90000003;
      }
      else {
        iVar2 = FUN_c067cde8(param_4,piVar3[0xc]);
        if (iVar2 == 0) {
          uVar1 = 0x90000004;
        }
        else {
          uVar1 = (**(code **)(*(int *)(piVar3[5] + 0x18) + 0x134))
                            (param_2,piVar3[0xb],param_3,local_28[0]);
        }
      }
    }
    FUN_c068185c(param_1);
  }
  FUN_c067e2f4(param_5,local_28[0],param_6);
  FUN_c06721b8(uVar1);
  return;
}



/* c06727fc FUN_c06727fc */

/* Boundary evidence: original MIPS .pdata c06727fc..c06728cb. Semantic name remains unreviewed. */

void FUN_c06727fc(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
  if (((param_2 == 0) || ((param_2 - 1 & param_2) != 0)) || (7 < param_2)) {
    uVar2 = 0x9000000f;
  }
  else {
    iVar1 = FUN_c067d338(param_1);
    if (iVar1 == 0) {
      uVar2 = 0x90000013;
    }
    else {
      uVar2 = (**(code **)(*(int *)(*(int *)(param_1[8] + 0x14) + 0x18) + 0x13c))
                        (*(undefined4 *)(param_1[8] + 0x18),param_2,local_18);
      FUN_c0681344(param_1);
      iVar1 = FUN_c067c558(param_3,local_18[0]);
      if (iVar1 == 0) {
        uVar2 = 0x90000015;
      }
    }
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c06728cc FUN_c06728cc */

/* Boundary evidence: original MIPS .pdata c06728cc..c0672967. Semantic name remains unreviewed. */

void FUN_c06728cc(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
  iVar1 = FUN_c067d338(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x90000013;
  }
  else {
    uVar2 = (**(code **)(*(int *)(*(int *)(param_1[8] + 0x14) + 0x18) + 0x140))
                      (*(undefined4 *)(param_1[8] + 0x18),local_18);
    FUN_c0681344(param_1);
    iVar1 = FUN_c067c558(param_2,local_18[0]);
    if (iVar1 == 0) {
      uVar2 = 0x90000015;
    }
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c0672968 FUN_c0672968 */

/* Boundary evidence: original MIPS .pdata c0672968..c0672a27. Semantic name remains unreviewed. */

void FUN_c0672968(int param_1,STRSAFE_PCNZWCH param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  HLOCAL hMem;
  uint uVar3;
  undefined4 local_18 [2];
  
  hMem = (HLOCAL)0x0;
  if ((param_2 == (STRSAFE_PCNZWCH)0x0) || (hMem = FUN_c067c2ec(param_2), hMem != (HLOCAL)0x0)) {
    piVar1 = FUN_c067c998(param_1);
    if (piVar1 == (int *)0x0) {
      uVar3 = 0x90000002;
      goto LAB_c06729f8;
    }
    uVar3 = (**(code **)(*(int *)(piVar1[5] + 0x18) + 0x144))(param_1,hMem,local_18);
    iVar2 = FUN_c067c558(param_3,local_18[0]);
    if (iVar2 != 0) goto LAB_c06729f8;
  }
  uVar3 = 0x90000015;
LAB_c06729f8:
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  FUN_c06721b8(uVar3);
  return;
}



/* c0672a28 FUN_c0672a28 */

/* Boundary evidence: original MIPS .pdata c0672a28..c0672b1f. Semantic name remains unreviewed. */

void FUN_c0672a28(int *param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  uint uVar1;
  HLOCAL hMem;
  int iVar2;
  undefined4 *local_20 [2];
  
  local_20[0] = (undefined4 *)0x0;
  uVar1 = FUN_c067e1b0(param_2,0x18,local_20,1,0);
  if (uVar1 == 0) {
    hMem = FUN_c067c2ec(param_3);
    if (hMem == (HLOCAL)0x0) {
      uVar1 = 0x90000015;
    }
    else {
      iVar2 = FUN_c067d338(param_1);
      if (iVar2 == 0) {
        uVar1 = 0x90000013;
      }
      else {
        uVar1 = (**(code **)(*(int *)(*(int *)(param_1[8] + 0x14) + 0x18) + 0x148))
                          (*(undefined4 *)(param_1[8] + 0x18),local_20[0],hMem);
        FUN_c0681344(param_1);
      }
    }
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
  }
  FUN_c067e2f4(param_2,local_20[0],0);
  FUN_c06721b8(uVar1);
  return;
}



/* c0672b20 FUN_c0672b20 */

/* Boundary evidence: original MIPS .pdata c0672b20..c0672d67. Semantic name remains unreviewed. */

void FUN_c0672b20(int *param_1,int param_2,DWORD param_3,int param_4)

{
  bool bVar1;
  HLOCAL _Dst;
  int iVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  undefined3 extraout_var_00;
  uint uVar4;
  
  _Dst = FUN_c067c1e4(param_2,0x18,param_4);
  if (_Dst == (HLOCAL)0x0) {
    uVar4 = 0x90000015;
    goto LAB_c0672cf8;
  }
  iVar2 = FUN_c067d24c((int)param_1);
  uVar4 = DAT_c06861e0;
  if (iVar2 == 0) goto LAB_c0672cf8;
  iVar2 = FUN_c067bc18();
  uVar4 = 0;
  bVar1 = FUN_c067c020(param_1 + 9,_Dst);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    memset(_Dst,0,0x18);
    *(undefined4 *)((int)_Dst + 4) = 0xffffffff;
    FUN_c067bc40();
    DVar3 = WaitForSingleObject((HANDLE)param_1[0xb],param_3);
    iVar2 = FUN_c067bc18();
    if (DVar3 == 0) {
      if (*param_1 == 0xce) {
        uVar4 = 0;
        bVar1 = FUN_c067c020(param_1 + 9,_Dst);
        if (CONCAT31(extraout_var_00,bVar1) == 0) goto LAB_c0672ca8;
      }
      else {
        uVar4 = 0x90000007;
      }
    }
    else {
LAB_c0672ca8:
      uVar4 = 0x9000001c;
    }
  }
  if (iVar2 != 0) {
    FUN_c067bc40();
  }
  FUN_c068185c(param_1);
LAB_c0672cf8:
  if (_Dst != (HLOCAL)0x0) {
    FUN_c067c3b4(param_2,_Dst,0x18,param_4);
  }
  FUN_c06721b8(uVar4);
  return;
}



/* c0672d68 FUN_c0672d68 */

/* Boundary evidence: original MIPS .pdata c0672d68..c0672d73. Semantic name remains unreviewed. */

undefined4 FUN_c0672d68(void)

{
  return 1;
}



/* c0672d74 FUN_c0672d74 */

/* Boundary evidence: original MIPS .pdata c0672d74..c0672e33. Semantic name remains unreviewed. */

void FUN_c0672d74(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar1 = FUN_c067d338(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x90000013;
  }
  else {
    uVar2 = (**(code **)(*(int *)(*(int *)(param_1[8] + 0x14) + 0x18) + 0x14c))
                      (*(undefined4 *)(param_1[8] + 0x18),&local_20,&local_1c);
    FUN_c0681344(param_1);
    iVar1 = FUN_c067c558(param_2,local_20);
    if ((iVar1 == 0) || (iVar1 = FUN_c067c558(param_3,local_1c), iVar1 == 0)) {
      uVar2 = 0x90000015;
    }
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c0672e34 FUN_c0672e34 */

/* Boundary evidence: original MIPS .pdata c0672e34..c067309b. Semantic name remains unreviewed. */

void FUN_c0672e34(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  
  local_30 = (uint *)0x0;
  uVar1 = FUN_c067e1b0(param_2,0x68,&local_30,1,param_3);
  if (uVar1 != 0) goto LAB_c0672ebc;
  iVar2 = FUN_c067d338(param_1);
  if (iVar2 == 0) {
    uVar1 = 0x90000013;
    goto LAB_c0672ebc;
  }
  iVar2 = param_1[8];
  uVar1 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x14) + 0x18) + 0x150))
                    (*(undefined4 *)(iVar2 + 0x18),local_30);
  local_30[4] = *(uint *)(iVar2 + 0x38);
  local_30[5] = *(uint *)(iVar2 + 0x3c);
  local_30[0x15] = 0;
  local_30[0x16] = 0;
  puVar6 = (undefined4 *)0x0;
  local_2c = (undefined4 *)0x0;
  FUN_c067bc18();
  local_28 = *(undefined4 **)(iVar2 + 0xc);
  do {
    puVar4 = local_28;
    local_28 = puVar4;
    if (puVar4 == (undefined4 *)(iVar2 + 0xc)) goto LAB_c0672fa8;
    local_28 = (undefined4 *)*puVar4;
  } while ((puVar4[8] & 2) == 0);
  puVar6 = (undefined4 *)puVar4[4];
  local_2c = puVar6;
LAB_c0672fa8:
  FUN_c067bc40();
  if (uVar1 == 0) {
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)param_1[7];
    }
    iVar2 = FUN_c067d24c((int)puVar6);
    if (iVar2 != 0) {
      puVar5 = local_30 + 1;
      uVar3 = *local_30;
      if (*puVar5 < uVar3) {
        if (uVar3 - local_30[2] < (uint)puVar6[0xd]) goto LAB_c0673060;
        FUN_c067bc68((int)local_30,uVar3,(int *)(local_30 + 2),puVar5,(int *)(local_30 + 0x16),
                     local_30 + 0x15,puVar6 + 0xe,puVar6[0xd]);
      }
      else {
LAB_c0673060:
        *puVar5 = puVar6[0xd] + *puVar5;
      }
      FUN_c068185c(puVar6);
    }
  }
  FUN_c0681344(param_1);
LAB_c0672ebc:
  FUN_c067e2f4(param_2,local_30,param_3);
  FUN_c06721b8(uVar1);
  return;
}



/* c067309c FUN_c067309c */

/* Boundary evidence: original MIPS .pdata c067309c..c06730a7. Semantic name remains unreviewed. */

undefined4 FUN_c067309c(void)

{
  return 1;
}



/* c06730a8 FUN_c06730a8 */

/* Boundary evidence: original MIPS .pdata c06730a8..c0673163. Semantic name remains unreviewed. */

void FUN_c06730a8(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c067d338(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x90000013;
  }
  else {
    iVar1 = FUN_c067c558(param_2,param_1[0xd]);
    if (((iVar1 == 0) || (iVar1 = FUN_c067c558(param_3,param_1[0xe]), iVar1 == 0)) ||
       (iVar1 = FUN_c067c558(param_4,param_1[0xf]), iVar1 == 0)) {
      uVar2 = 0x90000015;
    }
    else {
      uVar2 = 0;
    }
    FUN_c0681344(param_1);
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c0673164 FUN_c0673164 */

/* Boundary evidence: original MIPS .pdata c0673164..c0673233. Semantic name remains unreviewed. */

void FUN_c0673164(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 local_18 [2];
  
  if (((param_2 == 0) || ((param_2 - 1 & param_2) != 0)) || (7 < param_2)) {
    uVar2 = 0x9000000f;
  }
  else {
    iVar1 = FUN_c067d338(param_1);
    if (iVar1 == 0) {
      uVar2 = 0x90000013;
    }
    else {
      uVar2 = (**(code **)(*(int *)(*(int *)(param_1[8] + 0x14) + 0x18) + 0x154))
                        (*(undefined4 *)(param_1[8] + 0x18),param_2,local_18);
      FUN_c0681344(param_1);
      iVar1 = FUN_c067c558(param_3,local_18[0]);
      if (iVar1 == 0) {
        uVar2 = 0x90000015;
      }
    }
  }
  FUN_c06721b8(uVar2);
  return;
}



/* c0673234 FUN_c0673234 */

/* Boundary evidence: original MIPS .pdata c0673234..c06733cf. Semantic name remains unreviewed. */

void FUN_c0673234(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 *param_5,undefined4 *param_6,int param_7,int param_8)

{
  int iVar1;
  wchar_t *hMem;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *local_30 [2];
  
  local_30[0] = (undefined4 *)0x0;
  iVar1 = FUN_c067c558(param_1,0);
  uVar2 = 0x90000015;
  if (iVar1 != 0) {
    iVar1 = FUN_c067c558(param_5,0);
    uVar2 = 0x90000015;
    if ((iVar1 != 0) && (hMem = FUN_c067c2ec(param_4), hMem != (wchar_t *)0x0)) {
      uVar2 = FUN_c067e1b0(param_7,0x18,local_30,1,param_8);
      if (uVar2 == 0) {
        uVar3 = FUN_c067c500();
        iVar1 = FUN_c067c558(param_6,uVar3);
        if (iVar1 == 0) {
          uVar2 = 0x90000015;
        }
        else if (uVar3 < 0x20000) {
          uVar2 = 0x90000003;
        }
        else {
          puVar4 = FUN_c0681174(hMem,local_30[0] + 5);
          if (puVar4 == (undefined4 *)0x0) {
            uVar2 = 0x9000001c;
          }
          else {
            FUN_c067c558(param_1,puVar4);
            FUN_c067c558(param_5,DAT_c06861d8);
            DAT_c06861d4 = DAT_c06861d4 + 1;
            DAT_c06861e0 = 0x90000007;
          }
        }
      }
      LocalFree(hMem);
    }
  }
  FUN_c067e2f4(param_7,local_30[0],param_8);
  FUN_c06721b8(uVar2);
  return;
}



/* c06733d0 FUN_c06733d0 */

/* Boundary evidence: original MIPS .pdata c06733d0..c067358f. Semantic name remains unreviewed. */

void FUN_c06733d0(undefined4 *param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5,
                 int param_6,int param_7)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  HLOCAL _Dst;
  
  _Dst = (void *)0x0;
  uVar3 = 0x90000015;
  if ((param_6 == 0) || (_Dst = FUN_c067c1e4(param_6,0x10,param_7), _Dst != (HLOCAL)0x0)) {
    iVar1 = FUN_c067c558(param_5,0);
    if (iVar1 != 0) {
      if (((param_4 < param_3) || (0x20000 < param_3)) || (param_4 < 0x20000)) {
        uVar3 = 0x90000003;
      }
      else {
        iVar1 = FUN_c067d24c((int)param_1);
        uVar3 = DAT_c06861e0;
        if (iVar1 != 0) {
          piVar2 = FUN_c067c998(param_2);
          if (piVar2 == (int *)0x0) {
            uVar3 = 0x90000002;
          }
          else if (piVar2[0xb] == 0x20000) {
            FUN_c067c558(param_5,0x20000);
            if ((_Dst != (void *)0x0) &&
               (iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x138))(param_2,0x20000,_Dst),
               iVar1 != 0)) {
              memset(_Dst,0,0x10);
            }
            uVar3 = 0;
          }
          else {
            uVar3 = 0x90000003;
          }
          FUN_c068185c(param_1);
        }
      }
    }
    if (_Dst != (void *)0x0) {
      FUN_c067c3b4(param_6,_Dst,0x10,param_7);
    }
  }
  FUN_c06721b8(uVar3);
  return;
}



/* c0673590 FUN_c0673590 */

/* Boundary evidence: original MIPS .pdata c0673590..c06736b7. Semantic name remains unreviewed. */

void FUN_c0673590(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 *param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_20 [2];
  
  iVar1 = FUN_c067d24c((int)param_1);
  uVar3 = DAT_c06861e0;
  if (iVar1 != 0) {
    piVar2 = FUN_c067c998(param_2);
    if (piVar2 == (int *)0x0) {
      uVar3 = 0x90000002;
    }
    else {
      iVar1 = FUN_c067cd94(param_3,piVar2[0xb]);
      if (iVar1 == 0) {
        uVar3 = 0x90000003;
      }
      else {
        uVar3 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x158))
                          (piVar2[7],*(undefined4 *)(piVar2[5] + 0x14),param_4,param_5,local_20);
        if (uVar3 == 0) {
          if (local_20[0] == 0) {
            uVar3 = 0x90000004;
          }
          else {
            piVar2[0xc] = local_20[0];
            iVar1 = FUN_c067c558(param_6,local_20[0]);
            if (iVar1 == 0) {
              uVar3 = 0x90000015;
            }
          }
        }
      }
    }
    FUN_c068185c(param_1);
  }
  FUN_c06721b8(uVar3);
  return;
}



/* c06736b8 FUN_c06736b8 */

/* Boundary evidence: original MIPS .pdata c06736b8..c0673833. Semantic name remains unreviewed. */

void FUN_c06736b8(undefined4 *param_1,int param_2,undefined4 *param_3,uint param_4,int param_5,
                 undefined4 param_6,uint param_7)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 local_28 [2];
  
  iVar1 = FUN_c067c558(param_3,0);
  if (iVar1 == 0) {
    uVar3 = 0x90000015;
    goto LAB_c0673808;
  }
  if ((param_7 == 1) || (param_7 == 2)) {
    piVar2 = FUN_c067c998(param_2);
    if (piVar2 == (int *)0x0) {
      uVar3 = 0x90000002;
      goto LAB_c0673808;
    }
    if ((param_7 != 2) || (piVar2[0xe] == 0)) {
      iVar1 = FUN_c067cd94(param_4,piVar2[0xb]);
      if (iVar1 == 0) {
        uVar3 = 0x90000003;
      }
      else {
        iVar1 = FUN_c067cde8(param_5,piVar2[0xc]);
        if (iVar1 == 0) {
          uVar3 = 0x90000004;
        }
        else {
          iVar1 = FUN_c067d24c((int)param_1);
          uVar3 = DAT_c06861e0;
          if (iVar1 != 0) {
            uVar3 = FUN_c0680c84((int)piVar2,(int)param_1,param_5,param_7,param_6,local_28);
            if (uVar3 == 0) {
              FUN_c067c558(param_3,local_28[0]);
            }
            FUN_c068185c(param_1);
          }
        }
      }
      goto LAB_c0673808;
    }
  }
  uVar3 = 0x90000016;
LAB_c0673808:
  FUN_c06721b8(uVar3);
  return;
}



/* c0673834 FUN_c0673834 */

/* Boundary evidence: original MIPS .pdata c0673834..c067394f. Semantic name remains unreviewed. */

void FUN_c0673834(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x6fffffee;
  if (param_1 == (int *)0x0) {
    uVar1 = 0x90000013;
  }
  else if (((param_2 == (int *)0x0) || (((int)param_2 - 1U & (uint)param_2) != 0)) ||
          ((int *)0x7 < param_2)) {
    uVar1 = 0x9000000f;
  }
  else {
    piVar2 = param_3;
    if ((int *)0xffff < param_3) {
      piVar2 = (int *)0xffff;
    }
    param_4 = &local_20;
    param_3 = (int *)0x0;
    uVar1 = FUN_c067f070(0x1a,param_1,(int *)0x0,param_4,&local_1c,(int *)0x0,0,0);
    if (uVar1 == 0) {
      uVar1 = (**(code **)(*(int *)(*(int *)(local_1c + 0x14) + 0x18) + 0x168))
                        (local_20,*(undefined4 *)(local_1c + 0x18));
      FUN_c0681344(param_1);
      param_3 = param_2;
      param_4 = piVar2;
    }
  }
  uVar1 = FUN_c06721b8(uVar1);
  FUN_c067c160(uVar1,local_20,(int)param_3,(int)param_4);
  return;
}



/* c0673950 FUN_c0673950 */

/* Boundary evidence: original MIPS .pdata c0673950..c0673a6f. Semantic name remains unreviewed. */

void FUN_c0673950(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x6fffffee;
  piVar1 = param_3;
  if (param_1 == (int *)0x0) {
    uVar2 = 0x90000013;
  }
  else if (((param_3 == (int *)0x0) || (((int)param_3 - 1U & (uint)param_3) != 0)) ||
          ((int *)0x8 < param_3)) {
    uVar2 = 0x90000010;
  }
  else if (param_2 < (int *)0x8) {
    param_4 = &local_20;
    piVar1 = (int *)0x0;
    uVar2 = FUN_c067f070(0x1b,param_1,(int *)0x0,param_4,&local_1c,(int *)0x0,0,0);
    if (uVar2 == 0) {
      uVar2 = (**(code **)(*(int *)(*(int *)(local_1c + 0x14) + 0x18) + 0x16c))
                        (local_20,*(undefined4 *)(local_1c + 0x18));
      FUN_c0681344(param_1);
      piVar1 = param_2;
      param_4 = param_3;
    }
  }
  else {
    uVar2 = 0x9000000f;
  }
  uVar2 = FUN_c06721b8(uVar2);
  FUN_c067c160(uVar2,local_20,(int)piVar1,(int)param_4);
  return;
}



/* c0673a70 FUN_c0673a70 */

/* Boundary evidence: original MIPS .pdata c0673a70..c0673b57. Semantic name remains unreviewed. */

void FUN_c0673a70(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x6fffffee;
  if (param_1 == (int *)0x0) {
    uVar1 = 0x90000013;
  }
  else {
    piVar2 = param_3;
    if ((int *)0xffff < param_3) {
      piVar2 = (int *)0xffff;
    }
    param_4 = &local_20;
    param_3 = (int *)0x0;
    uVar1 = FUN_c067f070(0x1c,param_1,(int *)0x0,param_4,&local_1c,(int *)0x0,0,0);
    if (uVar1 == 0) {
      uVar1 = (**(code **)(*(int *)(*(int *)(local_1c + 0x14) + 0x18) + 0x170))
                        (local_20,*(undefined4 *)(local_1c + 0x18));
      FUN_c0681344(param_1);
      param_3 = param_2;
      param_4 = piVar2;
    }
  }
  uVar1 = FUN_c06721b8(uVar1);
  FUN_c067c160(uVar1,local_20,(int)param_3,(int)param_4);
  return;
}



/* c0673b58 FUN_c0673b58 */

/* Boundary evidence: original MIPS .pdata c0673b58..c0673de3. Semantic name remains unreviewed. */

void FUN_c0673b58(int *param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  
  if ((param_2 & 0xff000000) != 0) {
    uVar4 = 0x90000014;
    goto LAB_c0673d94;
  }
  if ((param_4 & 0xfffffff0) == 0) {
    if ((param_3 & 0xffffffc0) != 0) {
      uVar4 = 0x9000000a;
      goto LAB_c0673d94;
    }
    if ((param_3 == 0) || (param_4 != 0)) {
      iVar2 = FUN_c067d338(param_1);
      if (iVar2 == 0) {
        uVar4 = 0x90000013;
      }
      else {
        iVar5 = param_1[8];
        uVar4 = 0;
        uVar3 = param_4;
        uVar8 = param_2;
        uVar9 = param_3;
        uVar10 = param_4;
        iVar2 = iVar5;
        FUN_c067bc18();
        puVar1 = *(undefined4 **)(iVar5 + 0xc);
        uVar6 = param_2;
        uVar7 = param_3;
        while (puVar11 = puVar1, puVar11 != (undefined4 *)(iVar5 + 0xc)) {
          puVar1 = (undefined4 *)*puVar11;
          if (puVar11 + -3 != param_1) {
            uVar6 = puVar11[10] | uVar6;
            uVar7 = puVar11[0xb] | uVar7;
            uVar3 = puVar11[0xc] | uVar3;
            uVar8 = uVar6;
            uVar9 = uVar7;
            uVar10 = uVar3;
          }
        }
        FUN_c067bc40();
        if (((*(uint *)(iVar5 + 0x20) != uVar6) || (*(uint *)(iVar5 + 0x24) != uVar7)) ||
           (*(uint *)(iVar5 + 0x28) != uVar3)) {
          uVar4 = (**(code **)(*(int *)(*(int *)(iVar5 + 0x14) + 0x18) + 0x174))
                            (*(undefined4 *)(iVar5 + 0x18),param_2,param_3,param_4,uVar3,uVar8,uVar9
                             ,uVar10,puVar11,iVar2);
        }
        if (uVar4 == 0) {
          param_1[0xd] = param_2;
          param_1[0xe] = param_3;
          param_1[0xf] = param_4;
          *(uint *)(iVar5 + 0x20) = uVar6;
          *(uint *)(iVar5 + 0x24) = uVar7;
          *(uint *)(iVar5 + 0x28) = uVar3;
        }
        FUN_c0681344(param_1);
      }
      goto LAB_c0673d94;
    }
  }
  uVar4 = 0x9000000b;
LAB_c0673d94:
  FUN_c06721b8(uVar4);
  return;
}



/* c0673de4 FUN_c0673de4 */

/* Boundary evidence: original MIPS .pdata c0673de4..c0673def. Semantic name remains unreviewed. */

undefined4 FUN_c0673de4(void)

{
  return 1;
}



/* c0673df0 FUN_c0673df0 */

/* Boundary evidence: original MIPS .pdata c0673df0..c0673f0b. Semantic name remains unreviewed. */

void FUN_c0673df0(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x6fffffee;
  if (param_1 == (int *)0x0) {
    uVar1 = 0x90000013;
  }
  else if (((param_2 == (int *)0x0) || (((int)param_2 - 1U & (uint)param_2) != 0)) ||
          ((int *)0x7 < param_2)) {
    uVar1 = 0x9000000f;
  }
  else {
    piVar2 = param_3;
    if ((int *)0xffff < param_3) {
      piVar2 = (int *)0xffff;
    }
    param_4 = &local_20;
    param_3 = (int *)0x0;
    uVar1 = FUN_c067f070(0x1c,param_1,(int *)0x0,param_4,&local_1c,(int *)0x0,0,0);
    if (uVar1 == 0) {
      uVar1 = (**(code **)(*(int *)(*(int *)(local_1c + 0x14) + 0x18) + 0x178))
                        (local_20,*(undefined4 *)(local_1c + 0x18));
      FUN_c0681344(param_1);
      param_3 = param_2;
      param_4 = piVar2;
    }
  }
  uVar1 = FUN_c06721b8(uVar1);
  FUN_c067c160(uVar1,local_20,(int)param_3,(int)param_4);
  return;
}



/* c0673f0c FUN_c0673f0c */

/* Boundary evidence: original MIPS .pdata c0673f0c..c067406b. Semantic name remains unreviewed. */

void FUN_c0673f0c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *local_20;
  
  bVar1 = false;
  FUN_c067bc18();
  iVar2 = FUN_c067d24c((int)param_1);
  uVar4 = DAT_c06861e0;
  if (iVar2 != 0) {
    bVar1 = true;
    *param_1 = 0;
    if (param_1[0xb] != 0) {
      param_1[0xc] = param_1[0xb];
      param_1[0xb] = 0;
    }
    for (iVar2 = param_1[6]; iVar2 != 0; iVar2 = iVar2 + -1) {
      EventModify(param_1[0xc],3);
    }
    piVar3 = param_1 + 1;
    *(int *)param_1[2] = *piVar3;
    *(undefined4 *)(*piVar3 + 4) = param_1[2];
    param_1[2] = piVar3;
    *piVar3 = (int)piVar3;
    local_20 = param_1;
    uVar4 = 0;
  }
  FUN_c067bc40();
  if (bVar1) {
    FUN_c068185c(local_20);
    FUN_c068185c(local_20);
  }
  FUN_c06721b8(uVar4);
  return;
}



/* c067406c FUN_c067406c */

/* Boundary evidence: original MIPS .pdata c067406c..c0674077. Semantic name remains unreviewed. */

undefined4 FUN_c067406c(void)

{
  return 1;
}



/* c0674078 FUN_c0674078 */

/* Boundary evidence: original MIPS .pdata c0674078..c067409f. Semantic name remains unreviewed. */

void FUN_c0674078(undefined4 *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  FUN_c06726ac(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c06740a0 FUN_c06740a0 */

/* Boundary evidence: original MIPS .pdata c06740a0..c06740bb. Semantic name remains unreviewed. */

void FUN_c06740a0(int *param_1,int param_2,DWORD param_3)

{
  FUN_c0672b20(param_1,param_2,param_3,1);
  return;
}



/* c06740bc FUN_c06740bc */

/* Boundary evidence: original MIPS .pdata c06740bc..c06740d7. Semantic name remains unreviewed. */

void FUN_c06740bc(int *param_1,int param_2)

{
  FUN_c0672e34(param_1,param_2,1);
  return;
}



/* c06740d8 FUN_c06740d8 */

/* Boundary evidence: original MIPS .pdata c06740d8..c067410f. Semantic name remains unreviewed. */

void FUN_c06740d8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 *param_5,undefined4 *param_6,int param_7)

{
  FUN_c0673234(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  return;
}



/* c0674110 FUN_c0674110 */

/* Boundary evidence: original MIPS .pdata c0674110..c067413f. Semantic name remains unreviewed. */

void FUN_c0674110(undefined4 *param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5,
                 int param_6)

{
  FUN_c06733d0(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* c0674140 FUN_c0674140 */

/* Boundary evidence: original MIPS .pdata c0674140..c0674163. Semantic name remains unreviewed. */

void FUN_c0674140(undefined4 *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  FUN_c06726ac(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c0674164 FUN_c0674164 */

/* Boundary evidence: original MIPS .pdata c0674164..c067417f. Semantic name remains unreviewed. */

void FUN_c0674164(int *param_1,int param_2,DWORD param_3)

{
  FUN_c0672b20(param_1,param_2,param_3,0);
  return;
}



/* c0674180 FUN_c0674180 */

/* Boundary evidence: original MIPS .pdata c0674180..c067419b. Semantic name remains unreviewed. */

void FUN_c0674180(int *param_1,int param_2)

{
  FUN_c0672e34(param_1,param_2,0);
  return;
}



/* c067419c FUN_c067419c */

/* Boundary evidence: original MIPS .pdata c067419c..c06741cf. Semantic name remains unreviewed. */

void FUN_c067419c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 *param_5,undefined4 *param_6,int param_7)

{
  FUN_c0673234(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c06741d0 FUN_c06741d0 */

/* Boundary evidence: original MIPS .pdata c06741d0..c06741fb. Semantic name remains unreviewed. */

void FUN_c06741d0(undefined4 *param_1,int param_2,uint param_3,uint param_4,undefined4 *param_5,
                 int param_6)

{
  FUN_c06733d0(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* c06741fc FUN_c06741fc */

/* Boundary evidence: original MIPS .pdata c06741fc..c06742b7. Semantic name remains unreviewed. */

undefined4 FUN_c06741fc(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c06742b8 FUN_c06742b8 */

/* Boundary evidence: original MIPS .pdata c06742b8..c06743a7. Semantic name remains unreviewed. */

undefined4
FUN_c06742b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c06743a8 FUN_c06743a8 */

/* Boundary evidence: original MIPS .pdata c06743a8..c067444f. Semantic name remains unreviewed. */

undefined4 FUN_c06743a8(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_20 [2];
  DWORD local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = *param_2;
  local_20[0] = 0;
  local_18 = 0;
  local_14 = param_1;
  iVar1 = FUN_c06741fc(0x51,60000);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_c06742b8(L"netui.dll",L"LineTranslateDialogExt",&local_18,0xc,&local_18,0xc,
                           local_20), iVar1 != 0)) {
    if (local_18 == 0) {
      return 1;
    }
    SetLastError(local_18);
  }
  return 0;
}



/* c0674450 FUN_c0674450 */

/* Boundary evidence: original MIPS .pdata c0674450..c06745f7. Semantic name remains unreviewed. */

int FUN_c0674450(undefined4 param_1,int param_2,uint param_3,int param_4,undefined4 param_5,
                undefined4 param_6,uint param_7,uint *param_8,int param_9,undefined4 *param_10)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  uint *local_30 [2];
  
  local_30[0] = (uint *)0x0;
  if (param_9 != 0) {
    if (param_8 == (uint *)0x0) {
      return -0x7fffffcb;
    }
    iVar1 = FUN_c067db98(param_8,local_30,param_3);
    if (iVar1 != 0) goto LAB_c06745a8;
  }
  piVar2 = FUN_c067c75c(param_2);
  if (piVar2 == (int *)0x0) {
    iVar1 = -0x7ffffffe;
  }
  else {
    iVar1 = FUN_c067cd94(param_3,piVar2[0xb]);
    if (iVar1 == 0) {
      iVar1 = -0x7ffffff4;
    }
    else {
      iVar1 = FUN_c067cde8(param_4,piVar2[0xc]);
      if (iVar1 == 0) {
        iVar1 = -0x7ffffff3;
      }
      else {
        iVar1 = FUN_c068035c((int)piVar2,param_1,param_3,param_4,param_6,param_7,param_5,param_10);
        if ((iVar1 == 0) && (param_9 != 0)) {
          uVar3 = piVar2[8] | param_7;
          puVar4 = local_30[0];
          iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x20))(piVar2[6]);
          if (iVar1 != 0) {
            FUN_c0681e1c((HLOCAL)*param_10,uVar3,puVar4,param_4);
          }
        }
      }
    }
  }
LAB_c06745a8:
  if ((local_30[0] != (uint *)0x0) && (local_30[0] != param_8)) {
    LocalFree(local_30[0]);
  }
  return iVar1;
}



/* c06745f8 FUN_c06745f8 */

/* Boundary evidence: original MIPS .pdata c06745f8..c0674743. Semantic name remains unreviewed. */

void FUN_c06745f8(undefined4 *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  
  cVar1 = *(char *)((int)param_1 + param_2 + 0x28);
  if (((param_3 != 0) || (cVar1 != '\0')) && ((param_3 != 1 || (cVar1 != '\x01')))) {
    FUN_c067bc18();
    *(char *)((int)param_1 + param_2 + 0x28) = (char)param_3;
    puVar4 = DAT_c0686190;
LAB_c0674670:
    if ((undefined4 **)puVar4 != &DAT_c0686190) {
      puVar2 = puVar4 + -1;
      puVar4 = (undefined4 *)*puVar4;
      if (puVar2 != param_1) {
        cVar3 = *(char *)((int)puVar2 + param_2 + 0x28);
        if (cVar3 != '\0') {
          if (cVar1 == '\0') {
            *(char *)((int)puVar2 + param_2 + 0x28) =
                 *(char *)((int)puVar2 + param_2 + 0x28) + '\x01';
            goto LAB_c0674670;
          }
          if (param_3 == 0) {
            if (cVar3 <= cVar1) goto LAB_c0674670;
            cVar3 = *(char *)((int)puVar2 + param_2 + 0x28) + -1;
          }
          else {
            if (cVar1 <= cVar3) goto LAB_c0674670;
            cVar3 = *(char *)((int)puVar2 + param_2 + 0x28) + '\x01';
          }
          *(char *)((int)puVar2 + param_2 + 0x28) = cVar3;
        }
      }
      goto LAB_c0674670;
    }
    FUN_c067bc40();
  }
  return;
}



/* c0674744 FUN_c0674744 */

/* Boundary evidence: original MIPS .pdata c0674744..c067474f. Semantic name remains unreviewed. */

undefined4 FUN_c0674744(void)

{
  return 1;
}



/* c0674750 FUN_c0674750 */

/* Boundary evidence: original MIPS .pdata c0674750..c0674877. Semantic name remains unreviewed. */

void FUN_c0674750(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *hMem;
  int iVar3;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar2 = (int *)0x0;
  if ((param_2 == 0) || (param_3 == (int *)0x0)) {
    param_3 = (int *)0x0;
LAB_c06747f0:
    param_4 = &local_20;
    piVar1 = param_1;
    iVar3 = FUN_c067f070(1,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,piVar2,0);
    hMem = piVar2;
    if (iVar3 == 0) {
      if (*(int *)(local_1c + 0x1c) == 0) {
        *(undefined4 *)(local_1c + 0x1c) = *(undefined4 *)(param_1[5] + 0x14);
      }
      iVar3 = (*(code *)**(undefined4 **)(*(int *)(local_1c + 0x18) + 0x18))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      goto LAB_c06747c4;
    }
  }
  else {
    piVar1 = (int *)0x0;
    piVar2 = FUN_c067c1e4(param_2,(uint)param_3,0);
    if (piVar2 != (int *)0x0) goto LAB_c06747f0;
    iVar3 = -0x7fffffcb;
    hMem = piVar2;
  }
  param_3 = param_4;
  piVar2 = piVar1;
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
LAB_c06747c4:
  FUN_c067c160(iVar3,local_20,(int)piVar2,(int)param_3);
  return;
}



/* c0674878 FUN_c0674878 */

/* Boundary evidence: original MIPS .pdata c0674878..c067498f. Semantic name remains unreviewed. */

undefined4 FUN_c0674878(HKEY param_1,HKEY param_2,int param_3,int *param_4)

{
  int local_30 [4];
  
  local_30[0] = 0;
  local_30[1] = 4;
  RegQueryValueExW(param_1,L"PPID",(LPDWORD)0x0,(LPDWORD)(local_30 + 2),(LPBYTE)local_30,
                   (LPDWORD)(local_30 + 1));
  if (param_4 == (int *)0x0) {
    if (local_30[0] == param_3) {
      local_30[0] = local_30[0] + -1;
    }
  }
  else {
    local_30[0] = local_30[0] + 1;
    RegSetValueExW(param_2,L"PPID",0,4,(BYTE *)local_30,4);
    *param_4 = local_30[0];
  }
  RegSetValueExW(param_1,L"PPID",0,4,(BYTE *)local_30,4);
  return 0;
}



/* c0674990 FUN_c0674990 */

/* Boundary evidence: original MIPS .pdata c0674990..c0674bbf. Semantic name remains unreviewed. */

int FUN_c0674990(STRSAFE_PCNZWCH param_1,int param_2,undefined4 *param_3)

{
  wchar_t *lpSubKey;
  int iVar1;
  LSTATUS LVar2;
  int iVar3;
  HKEY local_40;
  int local_3c;
  HKEY local_38;
  int local_34;
  DWORD DStack_30;
  int local_2c;
  int local_28 [2];
  
  local_40 = (HKEY)0x0;
  iVar3 = -0x7fffffcb;
  local_38 = (HKEY)0x0;
  lpSubKey = FUN_c067c2ec(param_1);
  if (lpSubKey == (wchar_t *)0x0) {
    return -0x7fffffcb;
  }
  if ((((param_3 != (undefined4 *)0x0) && (iVar1 = FUN_c067c558(param_3,0), iVar1 == 0)) ||
      (iVar3 = FUN_c067c458(param_2), iVar3 != 0)) ||
     (iVar3 = FUN_c067daa0(lpSubKey,&local_2c,&local_34), iVar3 != 0)) goto LAB_c0674b90;
  LVar2 = RegCreateKeyExW((HKEY)0x80000002,L"TAPI\\TSP",0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0
                          ,&local_40,&DStack_30);
  if (LVar2 != 0) {
    iVar3 = -0x7fffffb8;
    goto LAB_c0674b90;
  }
  LVar2 = RegCreateKeyExW(local_40,lpSubKey,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_38,
                          &DStack_30);
  if (LVar2 == 0) {
    iVar1 = 0;
    local_3c = 0;
    if (param_3 == (undefined4 *)0x0) {
LAB_c0674b18:
      iVar3 = FUN_c067fe54(lpSubKey,local_2c,local_34,local_28);
    }
    else {
      iVar3 = FUN_c0674878(local_40,local_38,0,&local_3c);
      iVar1 = local_3c;
      if (iVar3 == 0) {
        FUN_c067c558(param_3,local_3c);
        iVar3 = (**(code **)(local_34 + 0xfc))(param_2,iVar1);
        if (iVar3 == 0) goto LAB_c0674b18;
      }
    }
    RegCloseKey(local_38);
    if (iVar3 == 0) {
      *(int *)(local_28[0] + 0xc) = iVar1;
    }
    else {
      RegDeleteKeyW(local_40,lpSubKey);
      if (param_3 != (undefined4 *)0x0) {
        FUN_c0674878(local_40,(HKEY)0x0,iVar1,(int *)0x0);
      }
    }
  }
  else {
    iVar3 = -0x7fffffb8;
  }
  RegCloseKey(local_40);
LAB_c0674b90:
  LocalFree(lpSubKey);
  return iVar3;
}



/* c0674bc0 FUN_c0674bc0 */

/* Boundary evidence: original MIPS .pdata c0674bc0..c0674d6f. Semantic name remains unreviewed. */

void FUN_c0674bc0(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  uVar1 = FUN_c067e31c(param_1,4);
  if (uVar1 == 0) {
    iVar3 = param_1[6];
    if (*(int *)(iVar3 + 0x68) == iVar3) {
      param_4 = &local_20;
      param_3 = param_2;
      uVar1 = FUN_c067f070(2,(int *)0x0,param_2,param_4,(int *)0x0,&local_1c,0,0);
      if (uVar1 == 0) {
        iVar2 = *(int *)(local_1c + 0x60);
        if (((((iVar2 == 0x20) || (iVar2 == 0x100)) || (iVar2 == 0x200)) || (iVar2 == 0x400)) &&
           ((*(int *)(local_1c + 0x68) == 0 || (*(int *)(local_1c + 0x68) == iVar3)))) {
          if (param_1[5] == param_2[5]) {
            param_3 = *(int **)(local_1c + 0x24);
            uVar1 = (**(code **)(*(int *)(*(int *)(iVar3 + 0x18) + 0x18) + 4))
                              (local_20,*(undefined4 *)(iVar3 + 0x24));
            if ((uVar1 & 0x80000000) == 0) {
              *(int *)(local_1c + 0x68) = iVar3;
            }
          }
          else {
            uVar1 = 0x80000018;
          }
        }
        else {
          uVar1 = 0x80000021;
        }
        FUN_c068179c(param_2);
      }
      else if (uVar1 == 0x80000018) {
        uVar1 = 0x80000021;
      }
    }
    else {
      uVar1 = 0x80000020;
    }
    FUN_c068179c(param_1);
  }
  else if (uVar1 == 0x80000018) {
    uVar1 = 0x80000020;
  }
  FUN_c067c160(uVar1,local_20,(int)param_3,(int)param_4);
  return;
}



/* c0674d70 FUN_c0674d70 */

/* Boundary evidence: original MIPS .pdata c0674d70..c0674e97. Semantic name remains unreviewed. */

void FUN_c0674d70(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *hMem;
  int iVar3;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar2 = (int *)0x0;
  if ((param_2 == 0) || (param_3 == (int *)0x0)) {
    param_3 = (int *)0x0;
LAB_c0674e10:
    param_4 = &local_20;
    piVar1 = param_1;
    iVar3 = FUN_c067f070(3,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,piVar2,0);
    hMem = piVar2;
    if (iVar3 == 0) {
      if (*(int *)(local_1c + 0x1c) == 0) {
        *(undefined4 *)(local_1c + 0x1c) = *(undefined4 *)(param_1[5] + 0x14);
      }
      iVar3 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 8))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      goto LAB_c0674de4;
    }
  }
  else {
    piVar1 = (int *)0x0;
    piVar2 = FUN_c067c1e4(param_2,(uint)param_3,0);
    if (piVar2 != (int *)0x0) goto LAB_c0674e10;
    iVar3 = -0x7fffffcb;
    hMem = piVar2;
  }
  param_3 = param_4;
  piVar2 = piVar1;
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
LAB_c0674de4:
  FUN_c067c160(iVar3,local_20,(int)piVar2,(int)param_3);
  return;
}



/* c0674e98 FUN_c0674e98 */

/* Boundary evidence: original MIPS .pdata c0674e98..c0674f7f. Semantic name remains unreviewed. */

void FUN_c0674e98(int *param_1,STRSAFE_PCNZWCH param_2,int *param_3,int *param_4)

{
  int *hMem;
  int *piVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar1 = param_3;
  hMem = FUN_c067c2ec(param_2);
  if (hMem == (int *)0x0) {
    iVar2 = -0x7fffffcb;
  }
  else {
    param_4 = &local_20;
    piVar1 = param_1;
    iVar2 = FUN_c067f070(4,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,hMem,0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0xc))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      piVar1 = hMem;
      param_4 = param_3;
    }
    else {
      LocalFree(hMem);
    }
  }
  FUN_c067c160(iVar2,local_20,(int)piVar1,(int)param_4);
  return;
}



/* c0674f80 FUN_c0674f80 */

/* Boundary evidence: original MIPS .pdata c0674f80..c067511f. Semantic name remains unreviewed. */

undefined4 FUN_c0674f80(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar2 = FUN_c067d14c(param_1);
  if (iVar2 == 0) {
    uVar5 = 0x8000002b;
  }
  else {
    iVar4 = param_1[6];
    bVar1 = false;
    iVar2 = FUN_c067bc18();
    FUN_c067ffc8((int)param_1);
    if (param_1[0x11] == 0) {
      bVar1 = true;
      param_1[0x11] = 1;
      if ((*(short *)(iVar4 + 0x38) == 1) && (*(int *)(iVar4 + 0x3c) != 0)) {
        uVar3 = *(undefined4 *)(iVar4 + 0x18);
        *(undefined4 *)(iVar4 + 0x18) = 0;
        *(undefined4 *)(iVar4 + 0x3c) = 0;
        iVar2 = FUN_c067bc40();
        (**(code **)(*(int *)(*(int *)(iVar4 + 0x14) + 0x18) + 0x10))(uVar3);
      }
    }
    if (iVar2 != 0) {
      FUN_c067bc40();
    }
    FUN_c0681e1c(param_1,param_2,param_3,param_4);
    if (bVar1) {
      FUN_c0681e1c(param_1,param_2,param_3,param_4);
    }
    else {
      uVar5 = 0x8000002b;
    }
    if (*(int *)(iVar4 + 0x3c) != 0) {
      FUN_c067d440(iVar4,param_2,param_3,param_4);
    }
  }
  return uVar5;
}



/* c0675120 FUN_c0675120 */

/* Boundary evidence: original MIPS .pdata c0675120..c067512b. Semantic name remains unreviewed. */

undefined4 FUN_c0675120(void)

{
  return 1;
}



/* c067512c FUN_c067512c */

/* Boundary evidence: original MIPS .pdata c067512c..c067541b. Semantic name remains unreviewed. */

void FUN_c067512c(HLOCAL *param_1,int *param_2,HLOCAL *param_3,int *param_4,int param_5)

{
  int iVar1;
  HLOCAL *ppvVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  HLOCAL *ppvVar6;
  HLOCAL pvVar7;
  int *piVar8;
  int *local_40;
  int local_3c;
  HLOCAL local_38;
  HLOCAL *local_34;
  HLOCAL local_30;
  HLOCAL *local_2c;
  
  local_34 = (HLOCAL *)0x0;
  local_3c = -0x7fffffce;
  ppvVar6 = (HLOCAL *)0x0;
  ppvVar2 = param_3;
  piVar3 = param_4;
  if ((param_4 != (int *)0x1) && (param_4 != (int *)0x2)) {
    uVar4 = 0x8000003f;
    goto LAB_c06753e4;
  }
  uVar5 = (uint)param_4 & 2;
  if (uVar5 == 0) {
LAB_c06751fc:
    uVar4 = FUN_c067e31c((int *)param_1,4);
    if (uVar4 == 0) {
      pvVar7 = param_1[6];
      local_30 = pvVar7;
      uVar4 = FUN_c067e31c(param_2,4);
      if (uVar4 == 0) {
        local_2c = *(HLOCAL **)(param_2[6] + 0x24);
        if (pvVar7 == (HLOCAL)param_2[6]) {
          uVar4 = 0x80000018;
        }
        else {
          if (*(int *)((int)param_1[5] + 0x18) == *(int *)(param_2[5] + 0x18)) {
            if (uVar5 == 0) {
              local_40 = (int *)0x0;
              piVar8 = (int *)0x0;
            }
            else {
              piVar3 = (int *)0x0;
              ppvVar2 = &local_38;
              uVar4 = FUN_c06821dc(param_1[5],&local_40,ppvVar2,0);
              if (uVar4 != 0) goto LAB_c067539c;
              piVar8 = local_40 + 9;
            }
            piVar3 = &local_3c;
            ppvVar2 = param_1;
            uVar4 = FUN_c067f070(5,(int *)0x0,(int *)param_1,piVar3,(int *)0x0,(int *)0x0,0,0);
            if (uVar4 == 0) {
              FUN_c068179c(param_1);
              if (uVar5 != 0) {
                piVar3 = FUN_c0682990(local_3c);
                piVar3[9] = (int)local_40;
                piVar3[10] = (int)local_38;
                FUN_c06828c4(piVar3);
                local_40[0x1a] = *(int *)((int)local_30 + 0x68);
              }
              ppvVar2 = local_2c;
              piVar3 = local_40;
              uVar4 = (**(code **)(*(int *)(*(int *)((int)local_30 + 0x18) + 0x18) + 0x1c))
                                (local_3c,*(undefined4 *)((int)local_30 + 0x24),local_2c,local_40,
                                 piVar8,param_4);
              if (uVar5 == 0) goto LAB_c06753b8;
              if ((uVar4 & 0x80000000) == 0) {
                FUN_c067c558(ppvVar6,local_38);
              }
              else {
                local_40[9] = 0;
              }
            }
          }
          else {
            uVar4 = 0x80000018;
          }
LAB_c067539c:
          if ((uVar5 != 0) && ((uVar4 & 0x80000000) != 0)) {
            FUN_c068179c(local_38);
          }
        }
LAB_c06753b8:
        FUN_c068179c(param_2);
      }
      else if (uVar4 == 0x80000018) {
        uVar4 = 0x80000021;
      }
      FUN_c068179c(param_1);
    }
  }
  else {
    ppvVar6 = param_3;
    if (param_5 == 0) {
LAB_c06751e8:
      iVar1 = FUN_c067c558(ppvVar6,0);
      if (iVar1 != 0) goto LAB_c06751fc;
    }
    else {
      piVar3 = (int *)0xc;
      ppvVar2 = (HLOCAL *)0x4;
      iVar1 = CeOpenCallerBuffer(&local_34,param_3,4,0xc,0);
      ppvVar6 = local_34;
      if (-1 < iVar1) goto LAB_c06751e8;
    }
    uVar4 = 0x80000035;
  }
  if (local_34 != (HLOCAL *)0x0) {
    piVar3 = (int *)0xc;
    ppvVar2 = (HLOCAL *)0x4;
    CeCloseCallerBuffer(local_34,param_3);
  }
LAB_c06753e4:
  FUN_c067c160(uVar4,local_3c,(int)ppvVar2,(int)piVar3);
  return;
}



/* c067541c FUN_c067541c */

/* Boundary evidence: original MIPS .pdata c067541c..c067559f. Semantic name remains unreviewed. */

int FUN_c067541c(int param_1,int param_2,STRSAFE_PCNZWCH param_3,int param_4,uint param_5,
                int param_6,int param_7)

{
  int iVar1;
  HLOCAL hMem;
  HLOCAL hMem_00;
  undefined4 *local_38;
  int *local_34;
  int local_30;
  
  local_38 = (undefined4 *)0x0;
  hMem = (HLOCAL)0x0;
  hMem_00 = (HLOCAL)0x0;
  local_30 = param_1;
  local_34 = FUN_c067c75c(param_1);
  if (local_34 == (int *)0x0) {
    iVar1 = -0x7ffffffe;
  }
  else {
    iVar1 = FUN_c067c458(param_2);
    if ((iVar1 == 0) &&
       ((iVar1 = -0x7fffffcb, param_3 == (STRSAFE_PCNZWCH)0x0 ||
        (hMem = FUN_c067c2ec(param_3), hMem != (HLOCAL)0x0)))) {
      if ((param_5 == 0) || (hMem_00 = FUN_c067c1e4(param_4,param_5,0), hMem_00 != (HLOCAL)0x0)) {
        iVar1 = FUN_c067e1b0(param_6,0x18,&local_38,1,param_7);
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*(int *)(local_34[5] + 0x18) + 0x120))
                            (local_30,param_2,hMem,hMem_00,param_5,local_38);
        }
      }
      if (hMem != (HLOCAL)0x0) {
        LocalFree(hMem);
      }
      if (hMem_00 != (HLOCAL)0x0) {
        LocalFree(hMem_00);
      }
    }
  }
  FUN_c067e2f4(param_6,local_38,param_7);
  return iVar1;
}



/* c06755a0 FUN_c06755a0 */

/* Boundary evidence: original MIPS .pdata c06755a0..c067562b. Semantic name remains unreviewed. */

int FUN_c06755a0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c067e31c(param_1,1);
  if (iVar1 == 0) {
    if (param_1[0xd] == 0) {
      iVar1 = FUN_c067cd5c((int)param_1);
      if (iVar1 == 0) {
        iVar1 = -0x7fffffe4;
      }
      else {
        FUN_c067d5e4(param_1);
        iVar1 = 0;
      }
      FUN_c068179c(param_1);
    }
    else {
      iVar1 = -0x7fffffe8;
    }
  }
  return iVar1;
}



/* c067562c FUN_c067562c */

/* Boundary evidence: original MIPS .pdata c067562c..c06757a7. Semantic name remains unreviewed. */

void FUN_c067562c(int *param_1,int *param_2,int *param_3,int *param_4,uint param_5)

{
  HLOCAL hMem;
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  int local_24;
  
  iVar3 = -0x7fffffcb;
  local_28 = -0x7fffffce;
  piVar2 = param_3;
  if (param_5 == 0) goto LAB_c0675774;
  piVar2 = (int *)0x0;
  hMem = FUN_c067c1e4((int)param_4,param_5,0);
  if (hMem == (HLOCAL)0x0) goto LAB_c0675774;
  LocalFree(hMem);
  if (param_3 == (int *)0x0) {
    piVar4 = (int *)0x0;
LAB_c06756e4:
    if (param_1 == (int *)0x0) {
      iVar3 = -0x7fffffd5;
    }
    else {
      param_4 = &local_28;
      piVar2 = (int *)0x0;
      iVar3 = FUN_c067f070(6,param_1,(int *)0x0,param_4,&local_24,(int *)0x0,0,0);
      if (iVar3 == 0) {
        uVar1 = *(undefined4 *)(local_24 + 0x18);
        iVar3 = (**(code **)(*(int *)(*(int *)(local_24 + 0x14) + 0x18) + 0x28))(local_28);
        FUN_c0681e1c(param_1,uVar1,param_2,piVar4);
        piVar2 = param_2;
        param_4 = piVar4;
      }
    }
  }
  else {
    iVar3 = FUN_c067e31c(param_3,4);
    if (iVar3 != 0) goto LAB_c0675774;
    if ((int *)param_3[5] == param_1) {
      piVar4 = *(int **)(param_3[6] + 0x24);
      goto LAB_c06756e4;
    }
    iVar3 = -0x7fffffe8;
  }
  if (param_3 != (int *)0x0) {
    FUN_c068179c(param_3);
  }
LAB_c0675774:
  FUN_c067c160(iVar3,local_28,(int)piVar2,(int)param_4);
  return;
}



/* c06757a8 FUN_c06757a8 */

/* Boundary evidence: original MIPS .pdata c06757a8..c067589b. Semantic name remains unreviewed. */

void FUN_c06757a8(int *param_1,STRSAFE_PCNZWCH param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *hMem;
  int iVar4;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar3 = (int *)0x0;
  if ((param_2 == (STRSAFE_PCNZWCH)0x0) ||
     (piVar1 = param_3, piVar3 = FUN_c067c2ec(param_2), piVar3 != (int *)0x0)) {
    piVar2 = &local_20;
    piVar1 = param_1;
    iVar4 = FUN_c067f070(7,(int *)0x0,param_1,piVar2,(int *)0x0,&local_1c,piVar3,0);
    hMem = piVar3;
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0x30))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      goto LAB_c0675808;
    }
  }
  else {
    iVar4 = -0x7fffffcb;
    piVar2 = param_4;
    hMem = piVar3;
  }
  param_3 = piVar2;
  piVar3 = piVar1;
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
LAB_c0675808:
  FUN_c067c160(iVar4,local_20,(int)piVar3,(int)param_3);
  return;
}



/* c067589c FUN_c067589c */

/* Boundary evidence: original MIPS .pdata c067589c..c06759cf. Semantic name remains unreviewed. */

void FUN_c067589c(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *hMem;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  hMem = (int *)0x0;
  if ((param_2 == 0) || (param_3 == (int *)0x0)) {
    param_3 = (int *)0x0;
LAB_c067593c:
    param_4 = &local_20;
    piVar1 = param_1;
    iVar2 = FUN_c067f070(8,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,hMem,0);
    if (iVar2 == 0) {
      if (*(int *)(local_1c + 0x60) == 1) {
        iVar2 = -0x7fffffe4;
      }
      else if (*(int *)(local_1c + 0x24) != 0) {
        iVar2 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0x34))
                          (local_20,*(int *)(local_1c + 0x24));
        piVar1 = hMem;
        param_4 = param_3;
      }
      FUN_c068179c(param_1);
      goto LAB_c0675910;
    }
  }
  else {
    piVar1 = (int *)0x0;
    hMem = FUN_c067c1e4(param_2,(uint)param_3,0);
    if (hMem != (int *)0x0) goto LAB_c067593c;
    iVar2 = -0x7fffffcb;
  }
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
LAB_c0675910:
  FUN_c067c160(iVar2,local_20,(int)piVar1,(int)param_4);
  return;
}



/* c06759d0 FUN_c06759d0 */

/* Boundary evidence: original MIPS .pdata c06759d0..c0675c73. Semantic name remains unreviewed. */

void FUN_c06759d0(int ****param_1,int ****param_2,int ****param_3,int ****param_4,undefined4 param_5
                 ,undefined4 *param_6,int param_7,int param_8)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *******pppppppiVar4;
  int *******pppppppiVar5;
  int ******ppppppiVar6;
  uint uVar7;
  int ******local_48;
  int *****local_44;
  int *****local_40;
  int *****local_3c;
  int ****local_38;
  int local_34;
  int ******local_30;
  
  local_44 = (int *****)0x0;
  local_40 = (int *****)0x0;
  bVar2 = true;
  bVar1 = false;
  local_38 = (int ****)0x80000032;
  pppppppiVar5 = (int *******)param_3;
  ppppppiVar6 = (int ******)param_4;
  local_30 = (int ******)param_2;
  iVar3 = FUN_c067c558(param_6,0);
  if (iVar3 == 0) {
    uVar7 = 0x80000035;
  }
  else {
    if (param_7 != 0) {
      ppppppiVar6 = (int ******)0x0;
      pppppppiVar5 = (int *******)&local_40;
      uVar7 = FUN_c067e1b0(param_7,0xb4,pppppppiVar5,0,param_8);
      if (uVar7 != 0) goto LAB_c0675c14;
    }
    if (param_4 != (int ****)0x0) {
      ppppppiVar6 = (int ******)0x0;
      pppppppiVar5 = (int *******)&local_44;
      uVar7 = FUN_c067e1b0((int)param_4,0x20,pppppppiVar5,0,param_8);
      if (uVar7 != 0) goto LAB_c0675c14;
      if ((int *****)local_44[1] != (int *****)0x0) {
        bVar1 = true;
      }
    }
    iVar3 = FUN_c067d14c((int *)param_1);
    if (iVar3 == 0) {
      uVar7 = 0x8000002b;
    }
    else {
      if (bVar1) {
        pppppppiVar5 = &local_48;
        pppppppiVar4 = (int *******)&local_3c;
        ppppppiVar6 = (int ******)local_40;
        uVar7 = FUN_c06821dc((int *)param_1,pppppppiVar4,pppppppiVar5,local_40);
        if (uVar7 == 0) goto LAB_c0675b08;
      }
      else {
        local_48 = (int ******)0x0;
LAB_c0675b08:
        ppppppiVar6 = (int ******)&local_38;
        pppppppiVar4 = (int *******)param_1;
        pppppppiVar5 = (int *******)local_48;
        uVar7 = FUN_c067f070(9,(int *)param_1,(int *)local_48,(int *)ppppppiVar6,&local_34,
                             (int *)0x0,local_44,local_40);
        if (uVar7 == 0) {
          bVar2 = false;
          if (bVar1) {
            FUN_c068179c(local_48);
          }
          pppppppiVar4 = *(int ********)(local_34 + 0x18);
          pppppppiVar5 = (int *******)local_30;
          uVar7 = (**(code **)(*(int *)(*(int *)(local_34 + 0x14) + 0x18) + 0x38))(local_38);
          if (bVar1) {
            if ((uVar7 & 0x80000000) == 0) {
              pppppppiVar4 = (int *******)local_48;
              FUN_c067c558(param_6,local_48);
            }
            else {
              local_3c[9] = (int ****)0x0;
            }
          }
          FUN_c0681e1c(param_1,pppppppiVar4,pppppppiVar5,param_3);
          ppppppiVar6 = (int ******)param_3;
        }
        if ((bVar1) && ((uVar7 & 0x80000000) != 0)) {
          FUN_c067d5e4(local_48);
        }
      }
      FUN_c0681e1c(param_1,pppppppiVar4,pppppppiVar5,ppppppiVar6);
      if (!bVar2) goto LAB_c0675c3c;
    }
  }
LAB_c0675c14:
  if ((int ******)local_44 != (int ******)0x0) {
    LocalFree(local_44);
  }
  if ((int ******)local_40 != (int ******)0x0) {
    LocalFree(local_40);
  }
LAB_c0675c3c:
  FUN_c067c160(uVar7,(int)local_38,(int)pppppppiVar5,(int)ppppppiVar6);
  return;
}



/* c0675c74 FUN_c0675c74 */

/* Boundary evidence: original MIPS .pdata c0675c74..c0675d67. Semantic name remains unreviewed. */

int FUN_c0675c74(int *param_1,int param_2,STRSAFE_PCNZWCH param_3,undefined4 param_4)

{
  int iVar1;
  HLOCAL hMem;
  
  hMem = (HLOCAL)0x0;
  if ((param_3 == (STRSAFE_PCNZWCH)0x0) || (hMem = FUN_c067c2ec(param_3), hMem != (HLOCAL)0x0)) {
    if ((param_2 == 1) || (param_2 == 2)) {
      iVar1 = FUN_c067e31c(param_1,4);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 0x40))
                          (*(undefined4 *)(param_1[6] + 0x24),param_1,param_2,hMem,param_4);
        FUN_c068179c(param_1);
      }
    }
    else {
      iVar1 = -0x7fffffd9;
    }
  }
  else {
    iVar1 = -0x7fffffcb;
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  return iVar1;
}



/* c0675d68 FUN_c0675d68 */

/* Boundary evidence: original MIPS .pdata c0675d68..c0675e9b. Semantic name remains unreviewed. */

int FUN_c0675d68(int *param_1,uint param_2,undefined4 param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  HLOCAL hMem;
  
  hMem = (HLOCAL)0x0;
  iVar1 = FUN_c067e31c(param_1,4);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (((param_2 == 0) || ((param_2 - 1 & param_2) != 0)) || ((param_2 & 0x1f) == 0)) {
    iVar1 = -0x7fffffc2;
  }
  else {
    if (((param_2 & 1) != 0) && (param_4 != 0)) {
      iVar1 = -0x7fffffcb;
      if (((int)((ulonglong)param_4 * 0x10 >> 0x20) != 0) ||
         (hMem = FUN_c067c1e4(param_5,(uint)((ulonglong)param_4 * 0x10),param_6),
         hMem == (HLOCAL)0x0)) goto LAB_c0675e5c;
    }
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 0x44))
                      (*(undefined4 *)(param_1[6] + 0x24),param_1,param_2,param_3,param_4,hMem);
  }
LAB_c0675e5c:
  FUN_c068179c(param_1);
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  return iVar1;
}



/* c0675e9c FUN_c0675e9c */

/* Boundary evidence: original MIPS .pdata c0675e9c..c0675f13. Semantic name remains unreviewed. */

int FUN_c0675e9c(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_c067e31c(param_1,4);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 0x18c))
                      (*(undefined4 *)(param_1[6] + 0x24),param_2);
    FUN_c068179c(param_1);
  }
  return iVar1;
}



/* c0675f14 FUN_c0675f14 */

/* Boundary evidence: original MIPS .pdata c0675f14..c0675f7b. Semantic name remains unreviewed. */

int FUN_c0675f14(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c067e31c(param_1,4);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 400))
                      (*(undefined4 *)(param_1[6] + 0x24));
    FUN_c068179c(param_1);
  }
  return iVar1;
}



/* c0675f7c FUN_c0675f7c */

/* Boundary evidence: original MIPS .pdata c0675f7c..c06760ef. Semantic name remains unreviewed. */

int FUN_c0675f7c(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5,int param_6,
                int param_7)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *local_28 [2];
  
  local_28[0] = (undefined4 *)0x0;
  iVar1 = FUN_c067e1b0(param_6,0xe4,local_28,1,param_7);
  if (iVar1 == 0) {
    piVar2 = FUN_c067c75c(param_2);
    if (piVar2 == (int *)0x0) {
      iVar1 = -0x7ffffffe;
    }
    else {
      iVar1 = FUN_c067cd94(param_4,piVar2[0xb]);
      if (iVar1 == 0) {
        iVar1 = -0x7ffffff4;
      }
      else {
        iVar1 = FUN_c067cde8(param_5,piVar2[0xc]);
        if (iVar1 == 0) {
          iVar1 = -0x7ffffff3;
        }
        else {
          iVar3 = FUN_c067d02c(param_1);
          iVar1 = DAT_c06861d0;
          if (iVar3 != 0) {
            iVar4 = piVar2[0xc];
            iVar3 = piVar2[0xb];
            iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x48))(param_2);
            local_28[0][10] = local_28[0][10] | 0x3800;
            local_28[0][0x10] = local_28[0][0x10] | 0x8000;
            FUN_c06825a0(param_1,param_3,iVar3,iVar4);
          }
        }
      }
    }
  }
  FUN_c067e2f4(param_6,local_28[0],param_7);
  return iVar1;
}



/* c06760f0 FUN_c06760f0 */

/* Boundary evidence: original MIPS .pdata c06760f0..c06761ef. Semantic name remains unreviewed. */

int FUN_c06760f0(int *param_1,undefined4 *param_2,int param_3,int param_4,uint param_5,int param_6)

{
  HLOCAL hMem;
  int iVar1;
  undefined4 ***pppuVar2;
  undefined4 uVar3;
  HLOCAL pvVar4;
  int iVar5;
  undefined4 **local_20 [2];
  
  if (param_3 == 2) {
    iVar5 = -0x7fffffcb;
    hMem = FUN_c067c1e4(param_4,param_5,param_6);
    if (hMem != (HLOCAL)0x0) {
      iVar1 = FUN_c067c558(param_2,0);
      if (iVar1 != 0) {
        iVar5 = FUN_c067d14c(param_1);
        if (iVar5 == 0) {
          iVar5 = -0x7fffffd5;
        }
        else {
          uVar3 = 2;
          pppuVar2 = local_20;
          pvVar4 = hMem;
          iVar5 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x14) + 0x18) + 0x4c))
                            (*(undefined4 *)(param_1[6] + 0x18));
          if (iVar5 == 0) {
            FUN_c067c558(param_2,local_20[0]);
            pppuVar2 = (undefined4 ***)local_20[0];
          }
          FUN_c0681e1c(param_1,pppuVar2,uVar3,pvVar4);
        }
      }
      LocalFree(hMem);
    }
  }
  else {
    iVar5 = -0x7fffffee;
  }
  return iVar5;
}



/* c06761f0 FUN_c06761f0 */

/* Boundary evidence: original MIPS .pdata c06761f0..c06762bf. Semantic name remains unreviewed. */

int FUN_c06761f0(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *local_20 [2];
  
  uVar3 = 1;
  local_20[0] = (undefined4 *)0x0;
  iVar1 = FUN_c067e1b0(param_3,0x40,local_20,1,param_4);
  if (iVar1 == 0) {
    iVar1 = FUN_c067d14c(param_1);
    if (iVar1 == 0) {
      iVar1 = -0x7fffffd5;
    }
    else {
      puVar2 = local_20[0];
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x14) + 0x18) + 0x50))
                        (*(undefined4 *)(param_1[6] + 0x18));
      FUN_c0681e1c(param_1,param_2,puVar2,uVar3);
    }
  }
  FUN_c067e2f4(param_3,local_20[0],param_4);
  return iVar1;
}



/* c06762c0 FUN_c06762c0 */

/* Boundary evidence: original MIPS .pdata c06762c0..c06763a7. Semantic name remains unreviewed. */

undefined4
FUN_c06762c0(STRSAFE_PCNZWCH param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  wchar_t *hMem;
  int iVar2;
  undefined4 *puVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_c067ca84(param_2);
  if (iVar1 == -1) {
    uVar5 = 0x8000002f;
  }
  else {
    uVar5 = 0x80000035;
    hMem = FUN_c067c2ec(param_1);
    if (hMem != (wchar_t *)0x0) {
      iVar2 = FUN_c067c558(param_6,0);
      if (iVar2 != 0) {
        pwVar4 = hMem;
        puVar3 = FUN_c067c5ac(0,(undefined4 *)0x0,hMem);
        if (puVar3 == (undefined4 *)0x0) {
          uVar5 = 0x80000015;
        }
        else {
          iVar1 = (int)*(char *)((int)puVar3 + iVar1 + 0x28);
          uVar5 = 0;
          FUN_c067c558(param_6,iVar1);
          FUN_c06825a0(puVar3,iVar1,pwVar4,param_4);
        }
      }
      LocalFree(hMem);
    }
  }
  return uVar5;
}



/* c06763a8 FUN_c06763a8 */

/* Boundary evidence: original MIPS .pdata c06763a8..c067657f. Semantic name remains unreviewed. */

int FUN_c06763a8(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint **ppuVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *local_20 [2];
  
  puVar5 = (uint *)0x1;
  ppuVar4 = local_20;
  local_20[0] = (uint *)0x0;
  iVar1 = FUN_c067e1b0(param_2,0x148,ppuVar4,1,param_3);
  if ((iVar1 != 0) || (iVar1 = FUN_c067e31c(param_1,2), iVar1 != 0)) goto LAB_c067654c;
  iVar7 = param_1[6];
  iVar1 = (**(code **)(*(int *)(*(int *)(iVar7 + 0x18) + 0x18) + 0x58))
                    (*(undefined4 *)(iVar7 + 0x24),local_20[0]);
  local_20[0][3] = param_1[5];
  local_20[0][0xd] = 0xffff;
  local_20[0][0xe] = param_1[0xc];
  local_20[0][0xf] = param_1[0xb];
  local_20[0][0x17] = *(uint *)(iVar7 + 0x34);
  local_20[0][0x18] = *(uint *)(iVar7 + 0x38);
  local_20[0][0x34] = 0;
  local_20[0][0x35] = 0;
  local_20[0][0x36] = 0;
  local_20[0][0x37] = 0;
  local_20[0][0x38] = 0;
  local_20[0][0x39] = 0;
  iVar2 = FUN_c067d02c(*(int **)(iVar7 + 0x1c));
  if (iVar2 != 0) {
    puVar6 = local_20[0] + 1;
    uVar3 = *local_20[0];
    if (*puVar6 < uVar3) {
      ppuVar4 = (uint **)(local_20[0] + 2);
      iVar2 = *(int *)(iVar7 + 0x1c);
      if (uVar3 - (int)*ppuVar4 < *(uint *)(iVar2 + 0x40)) goto LAB_c0676528;
      FUN_c067bc68((int)local_20[0],uVar3,(int *)ppuVar4,puVar6,(int *)(local_20[0] + 0x35),
                   local_20[0] + 0x34,(void *)(iVar2 + 0x44),*(size_t *)(iVar2 + 0x40));
      puVar5 = puVar6;
    }
    else {
LAB_c0676528:
      *puVar6 = *(int *)(*(int *)(iVar7 + 0x1c) + 0x40) + *puVar6;
    }
    FUN_c06825a0(*(undefined4 **)(iVar7 + 0x1c),uVar3,ppuVar4,puVar5);
  }
  FUN_c068179c(param_1);
LAB_c067654c:
  FUN_c067e2f4(param_2,local_20[0],param_3);
  return iVar1;
}



/* c0676580 FUN_c0676580 */

/* Boundary evidence: original MIPS .pdata c0676580..c0676647. Semantic name remains unreviewed. */

int FUN_c0676580(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *local_20 [2];
  
  local_20[0] = (undefined4 *)0x0;
  iVar1 = FUN_c067e1b0(param_2,0x38,local_20,1,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_c067e31c(param_1,2), iVar1 == 0)) {
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 0x5c))
                      (*(undefined4 *)(param_1[6] + 0x24),local_20[0]);
    local_20[0][5] = param_1[9];
    FUN_c068179c(param_1);
  }
  FUN_c067e2f4(param_2,local_20[0],param_3);
  return iVar1;
}



/* c0676648 FUN_c0676648 */

/* Boundary evidence: original MIPS .pdata c0676648..c06769c7. Semantic name remains unreviewed. */

int FUN_c0676648(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  int *local_50;
  int local_4c;
  uint local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  
  uVar9 = 1;
  local_50 = (int *)0x0;
  local_38 = param_1;
  local_34 = param_3;
  local_30 = param_2;
  iVar1 = FUN_c067e1b0(param_2,0x18,&local_50,1,param_3);
  if ((iVar1 != 0) || (iVar1 = FUN_c067e31c(param_1,2), local_40 = iVar1, iVar1 != 0))
  goto LAB_c0676988;
  piVar11 = *(int **)(param_1[6] + 0x68);
  if ((piVar11 == (int *)0x0) || (iVar2 = FUN_c067cf2c(piVar11), iVar2 == 0)) {
    iVar1 = -0x7fffffbf;
  }
  else {
    piVar14 = *(int **)(param_1[5] + 0x14);
    iVar2 = FUN_c067d02c(piVar14);
    if (iVar2 == 0) {
      iVar1 = -0x7fffffb8;
    }
    else {
      piVar8 = (int *)0xffffffff;
      local_50[3] = 0;
      local_50[5] = 0x18;
      local_50[4] = 0;
      local_4c = 0;
      uVar12 = *local_50 - 0x18U >> 2;
      piVar13 = local_50 + 6;
      piVar7 = piVar11;
      local_48 = uVar12;
      local_44 = piVar13;
      piVar3 = FUN_c067e440((int)piVar14,piVar11,0xffffffff);
      iVar2 = local_4c;
      if (piVar3 != (int *)0x0) {
        local_4c = 1;
        if (uVar12 != 0) {
          piVar7 = (int *)0x0;
          piVar8 = piVar11;
          piVar4 = FUN_c067e58c((int)piVar14,0,piVar11);
          if (piVar4 == (int *)0x0) {
            piVar8 = (int *)0x2;
            piVar7 = piVar11;
            piVar4 = FUN_c0681edc(piVar3,piVar11,2,uVar9);
            if (piVar4 == (int *)0x0) goto LAB_c06767ec;
            piVar4[8] = piVar4[8] + 1;
          }
          local_48 = uVar12 - 1;
          piVar13[local_50[3]] = (int)piVar4;
          local_50[3] = local_50[3] + 1;
          FUN_c068179c(piVar4);
        }
LAB_c06767ec:
        FUN_c0681e1c(piVar3,piVar7,piVar8,uVar9);
        iVar2 = 1;
      }
      local_3c = FUN_c067e044(&DAT_c0686170);
      piVar3 = local_44;
      if (local_3c != (int *)0x0) {
        iVar10 = *local_3c;
        piVar13 = local_3c;
        iVar15 = local_4c;
        uVar12 = local_48;
        while (iVar10 != 0) {
          iVar1 = *piVar13;
          piVar4 = (int *)(iVar1 + -4);
          piVar13 = piVar13 + 1;
          if ((piVar4 != piVar11) && (iVar2 = FUN_c067cf2c(piVar4), iVar2 != 0)) {
            if ((*(int *)(iVar1 + 0x5c) == 0x800) && (*(int **)(iVar1 + 100) == piVar11)) {
              piVar8 = (int *)0xffffffff;
              piVar7 = piVar4;
              piVar5 = FUN_c067e440((int)piVar14,piVar4,0xffffffff);
              if (piVar5 != (int *)0x0) {
                iVar15 = iVar15 + 1;
                if (uVar12 != 0) {
                  piVar7 = (int *)0x0;
                  piVar8 = piVar4;
                  piVar6 = FUN_c067e58c((int)piVar14,0,piVar4);
                  if (piVar6 == (int *)0x0) {
                    piVar8 = (int *)0x2;
                    piVar7 = piVar4;
                    piVar6 = FUN_c0681edc(piVar5,piVar4,2,uVar9);
                    if (piVar6 == (int *)0x0) goto LAB_c0676900;
                    piVar6[8] = piVar6[8] + 1;
                  }
                  piVar3[local_50[3]] = (int)piVar6;
                  uVar12 = uVar12 - 1;
                  local_50[3] = local_50[3] + 1;
                  FUN_c068179c(piVar6);
                }
LAB_c0676900:
                FUN_c0681e1c(piVar5,piVar7,piVar8,uVar9);
              }
            }
            FUN_c0681284(piVar4);
          }
          param_1 = local_38;
          iVar1 = local_40;
          iVar2 = iVar15;
          iVar10 = *piVar13;
        }
        local_4c = iVar15;
        LocalFree(local_3c);
      }
      FUN_c06825a0(piVar14,piVar7,piVar8,uVar9);
      local_50[4] = local_50[3] << 2;
      local_50[2] = local_50[4] + 0x18;
      local_50[1] = (iVar2 + 6) * 4;
      param_3 = local_34;
      param_2 = local_30;
    }
    FUN_c0681284(piVar11);
  }
  FUN_c068179c(param_1);
LAB_c0676988:
  FUN_c067e2f4(param_2,local_50,param_3);
  return iVar1;
}



/* c06769c8 FUN_c06769c8 */

/* Boundary evidence: original MIPS .pdata c06769c8..c0676b7b. Semantic name remains unreviewed. */

int FUN_c06769c8(int *param_1,int param_2,uint param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *local_30 [2];
  
  local_30[0] = (uint *)0x0;
  uVar4 = 0xec;
  if (0x1ffff < param_3) {
    uVar4 = 0x124;
  }
  iVar1 = FUN_c067e1b0(param_5,uVar4,local_30,1,param_6);
  if (iVar1 == 0) {
    if ((0x1ffff < param_3) || (0x123 < *local_30[0])) {
      piVar2 = FUN_c067c75c(param_2);
      if (piVar2 == (int *)0x0) {
        iVar1 = -0x7ffffffe;
      }
      else {
        iVar1 = FUN_c067cd94(param_3,piVar2[0xb]);
        if (iVar1 == 0) {
          iVar1 = -0x7ffffff4;
        }
        else {
          iVar1 = FUN_c067cde8(param_4,piVar2[0xc]);
          if (iVar1 == 0) {
            iVar1 = -0x7ffffff3;
          }
          else {
            iVar3 = FUN_c067d02c(param_1);
            iVar1 = DAT_c06861d0;
            if (iVar3 != 0) {
              iVar3 = piVar2[0xb];
              puVar5 = local_30[0];
              iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x60))(param_2);
              local_30[0][0x20] = local_30[0][0x20] | 0x40600;
              FUN_c06825a0(param_1,iVar3,param_4,puVar5);
            }
          }
        }
      }
    }
    else {
      local_30[0][1] = 0x124;
      local_30[0][2] = 0x124;
      iVar1 = 0;
    }
  }
  FUN_c067e2f4(param_5,local_30[0],param_6);
  return iVar1;
}



/* c0676b7c FUN_c0676b7c */

/* Boundary evidence: original MIPS .pdata c0676b7c..c0676c5f. Semantic name remains unreviewed. */

int FUN_c0676b7c(int param_1,int param_2,STRSAFE_PCNZWCH param_3,int param_4)

{
  HLOCAL hMem;
  int *piVar1;
  int iVar2;
  undefined4 *local_20 [2];
  
  local_20[0] = (undefined4 *)0x0;
  iVar2 = -0x7fffffcb;
  hMem = FUN_c067c2ec(param_3);
  if (hMem != (HLOCAL)0x0) {
    iVar2 = FUN_c067e1b0(param_2,0x18,local_20,1,param_4);
    if (iVar2 == 0) {
      piVar1 = FUN_c067c75c(param_1);
      if (piVar1 == (int *)0x0) {
        iVar2 = -0x7ffffffe;
      }
      else {
        iVar2 = (**(code **)(*(int *)(piVar1[5] + 0x18) + 100))(param_1,local_20[0],hMem);
      }
    }
    LocalFree(hMem);
  }
  FUN_c067e2f4(param_2,local_20[0],param_4);
  return iVar2;
}



/* c0676c60 FUN_c0676c60 */

/* Boundary evidence: original MIPS .pdata c0676c60..c0676d2f. Semantic name remains unreviewed. */

undefined4 FUN_c0676c60(int param_1,STRSAFE_PCNZWCH param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  HLOCAL hMem;
  undefined4 uVar3;
  undefined4 local_20 [2];
  
  hMem = (HLOCAL)0x0;
  uVar3 = 0x80000035;
  if ((param_2 == (STRSAFE_PCNZWCH)0x0) || (hMem = FUN_c067c2ec(param_2), hMem != (HLOCAL)0x0)) {
    iVar1 = FUN_c067c558(param_3,0);
    if (iVar1 != 0) {
      piVar2 = FUN_c067c75c(param_1);
      if (piVar2 == (int *)0x0) {
        uVar3 = 0x80000002;
      }
      else {
        uVar3 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x6c))(param_1,hMem,local_20);
        FUN_c067c558(param_3,local_20[0]);
      }
    }
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
  }
  return uVar3;
}



/* c0676d30 FUN_c0676d30 */

/* Boundary evidence: original MIPS .pdata c0676d30..c0676f0b. Semantic name remains unreviewed. */

int FUN_c0676d30(int *param_1,undefined4 param_2,int *param_3,uint param_4,int param_5,
                STRSAFE_PCNZWCH param_6,int param_7)

{
  int iVar1;
  HLOCAL hMem;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 **ppuVar4;
  uint uVar5;
  int iVar6;
  undefined4 *local_30;
  undefined4 local_2c;
  
  uVar5 = 1;
  ppuVar4 = &local_30;
  uVar3 = 0x18;
  local_30 = (undefined4 *)0x0;
  iVar6 = 0;
  local_2c = param_2;
  iVar1 = FUN_c067e1b0(param_5,0x18,ppuVar4,1,param_7);
  if (iVar1 != 0) goto LAB_c0676ecc;
  hMem = FUN_c067c2ec(param_6);
  if (hMem == (HLOCAL)0x0) {
    iVar1 = -0x7fffffcb;
  }
  else if (param_4 == 0) {
LAB_c0676eb4:
    iVar1 = -0x7fffffe5;
  }
  else if (param_4 < 3) {
    param_3 = (int *)0x0;
    iVar1 = FUN_c067d14c(param_1);
    if (iVar1 == 0) {
      iVar1 = -0x7fffffd5;
    }
    else {
      iVar1 = param_1[6];
LAB_c0676e24:
      if (iVar1 == 0) {
        iVar1 = -0x7fffffce;
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 0x18);
        if (iVar6 == 0) {
          ppuVar4 = (undefined4 **)0x0;
        }
        else {
          ppuVar4 = *(undefined4 ***)(iVar6 + 0x24);
        }
        local_30[2] = 0x18;
        uVar3 = local_2c;
        uVar5 = param_4;
        iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x14) + 0x18) + 0x70))(uVar2);
      }
      if (param_4 < 3) {
        FUN_c0681e1c(param_1,uVar3,ppuVar4,uVar5);
      }
      else if (param_4 == 4) {
        FUN_c068179c(param_3);
      }
    }
  }
  else {
    if (param_4 != 4) goto LAB_c0676eb4;
    uVar3 = 1;
    iVar1 = FUN_c067e31c(param_3,1);
    if (iVar1 == 0) {
      iVar6 = param_3[6];
      iVar1 = *(int *)(iVar6 + 0x20);
      goto LAB_c0676e24;
    }
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
LAB_c0676ecc:
  FUN_c067e2f4(param_5,local_30,param_7);
  return iVar1;
}



/* c0676f0c FUN_c0676f0c */

/* Boundary evidence: original MIPS .pdata c0676f0c..c0676ffb. Semantic name remains unreviewed. */

int FUN_c0676f0c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *local_20 [2];
  
  uVar4 = 1;
  ppuVar3 = local_20;
  local_20[0] = (undefined4 *)0x0;
  iVar1 = FUN_c067e1b0(param_2,0x58,ppuVar3,1,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_c067d14c(param_1);
    if (iVar1 == 0) {
      iVar1 = -0x7fffffd5;
    }
    else {
      iVar5 = param_1[6];
      puVar2 = local_20[0];
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar5 + 0x14) + 0x18) + 0x74))
                        (*(undefined4 *)(iVar5 + 0x18));
      local_20[0][3] = (uint)*(ushort *)(iVar5 + 0x38);
      local_20[0][4] = *(undefined4 *)(iVar5 + 0x20);
      local_20[0][0x15] = 0;
      local_20[0][0x14] = 0;
      FUN_c0681e1c(param_1,puVar2,ppuVar3,uVar4);
    }
  }
  FUN_c067e2f4(param_2,local_20[0],param_3);
  return iVar1;
}



/* c0676ffc FUN_c0676ffc */

/* Boundary evidence: original MIPS .pdata c0676ffc..c067723f. Semantic name remains unreviewed. */

undefined4 FUN_c0676ffc(int *param_1,int param_2,HLOCAL param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  DWORD DVar4;
  undefined3 extraout_var_00;
  HLOCAL pvVar5;
  int iVar6;
  undefined4 uVar7;
  HLOCAL _Dst;
  
  _Dst = (HLOCAL)0x0;
  iVar6 = param_4;
  iVar2 = FUN_c067d02c(param_1);
  uVar7 = DAT_c06861d0;
  if (iVar2 == 0) goto LAB_c06771d8;
  iVar2 = param_4;
  _Dst = FUN_c067c1e4(param_2,0x18,param_4);
  if (_Dst == (HLOCAL)0x0) {
    uVar7 = 0x80000035;
    goto LAB_c06771d8;
  }
  iVar3 = FUN_c067bc18();
  uVar7 = 0;
  pvVar5 = _Dst;
  bVar1 = FUN_c067c020(param_1 + 6,_Dst);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = 0x18;
    memset(_Dst,0,0x18);
    *(undefined4 *)((int)_Dst + 4) = 0xffffffff;
    FUN_c067bc40();
    DVar4 = WaitForSingleObject((HANDLE)param_1[8],(DWORD)param_3);
    iVar3 = FUN_c067bc18();
    if (DVar4 == 0) {
      if (*param_1 == 0xcb) {
        uVar7 = 0;
        param_3 = _Dst;
        bVar1 = FUN_c067c020(param_1 + 6,_Dst);
        pvVar5 = param_3;
        if (CONCAT31(extraout_var_00,bVar1) == 0) goto LAB_c0677188;
      }
      else {
        uVar7 = 0x80000014;
        pvVar5 = param_3;
      }
    }
    else {
LAB_c0677188:
      uVar7 = 0x80000048;
      pvVar5 = param_3;
    }
  }
  if (iVar3 != 0) {
    FUN_c067bc40();
  }
  FUN_c06825a0(param_1,pvVar5,iVar2,iVar6);
LAB_c06771d8:
  if (_Dst != (HLOCAL)0x0) {
    FUN_c067c3b4(param_2,_Dst,0x18,param_4);
  }
  return uVar7;
}



/* c0677240 FUN_c0677240 */

/* Boundary evidence: original MIPS .pdata c0677240..c067724b. Semantic name remains unreviewed. */

undefined4 FUN_c0677240(void)

{
  return 1;
}



/* c067724c FUN_c067724c */

/* Boundary evidence: original MIPS .pdata c067724c..c0677557. Semantic name remains unreviewed. */

int FUN_c067724c(int **param_1,int **param_2,int **param_3,int param_4,int param_5)

{
  int **ppiVar1;
  int *piVar2;
  undefined4 *puVar3;
  int **ppiVar4;
  int **ppiVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int *local_48;
  uint local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  
  local_48 = (int *)0x0;
  local_30 = param_4;
  if ((param_3 == (int **)0x1) || (param_3 == (int **)0x2)) {
    ppiVar4 = param_2;
    ppiVar5 = param_3;
    iVar6 = param_4;
    iVar8 = FUN_c067d14c((int *)param_1);
    if (iVar8 == 0) {
      iVar8 = -0x7fffffd5;
    }
    else {
      if ((param_3 == (int **)0x2) &&
         (ppiVar1 = (int **)FUN_c067cc04((int)param_1), ppiVar1 <= param_2)) {
        iVar8 = -0x7fffffef;
      }
      else {
        iVar6 = 1;
        ppiVar5 = &local_48;
        ppiVar4 = (int **)0x18;
        iVar8 = FUN_c067e1b0(param_4,0x18,ppiVar5,1,param_5);
        if (iVar8 == 0) {
          piVar9 = param_1[5];
          iVar12 = 0;
          local_34 = piVar9;
          iVar8 = FUN_c067d02c(piVar9);
          if (iVar8 == 0) {
            iVar8 = -0x7fffffb8;
          }
          else {
            local_40 = param_1[6];
            local_48[3] = 0;
            local_48[5] = 0x18;
            local_3c = local_48 + 6;
            local_44 = *local_48 - 0x18U >> 2;
            local_38 = FUN_c067e044(&DAT_c0686170);
            if (local_38 != (int *)0x0) {
              iVar8 = *local_38;
              piVar10 = local_38;
              uVar11 = local_44;
              while (iVar8 != 0) {
                iVar7 = *piVar10;
                ppiVar1 = (int **)(iVar7 + -4);
                piVar10 = piVar10 + 1;
                iVar8 = FUN_c067cf2c((int *)ppiVar1);
                if (iVar8 != 0) {
                  if ((((uint)param_3 & 2) == 0) || (*(int ***)(iVar7 + 0x40) == param_2)) {
                    FUN_c067bc18();
                    piVar9 = *(int **)(iVar7 + 8);
                    if (piVar9 == (int *)(iVar7 + 8)) {
                      FUN_c067bc40();
                    }
                    else {
                      FUN_c067bc40();
                      iVar8 = FUN_c067d14c((int *)piVar9[2]);
                      if (iVar8 != 0) {
                        if (*(int **)(piVar9[2] + 0x18) == local_40) {
                          ppiVar4 = param_1;
                          ppiVar5 = ppiVar1;
                          piVar2 = FUN_c067e58c(0,(int)param_1,(int *)ppiVar1);
                          if (piVar2 == (int *)0x0) {
                            iVar12 = iVar12 + 1;
                            if (uVar11 != 0) {
                              ppiVar5 = (int **)0x2;
                              ppiVar4 = ppiVar1;
                              puVar3 = FUN_c0681edc((int *)param_1,(int *)ppiVar1,2,iVar6);
                              if (puVar3 != (undefined4 *)0x0) {
                                uVar11 = uVar11 - 1;
                                local_3c[local_48[3]] = (int)puVar3;
                                local_48[3] = local_48[3] + 1;
                              }
                            }
                          }
                          else {
                            FUN_c068179c(piVar2);
                          }
                        }
                        FUN_c0681e1c((HLOCAL)piVar9[2],ppiVar4,ppiVar5,iVar6);
                      }
                    }
                  }
                  FUN_c0681284(ppiVar1);
                }
                piVar9 = local_34;
                param_4 = local_30;
                iVar8 = *piVar10;
              }
              LocalFree(local_38);
            }
            FUN_c06825a0(piVar9,ppiVar4,ppiVar5,iVar6);
            iVar8 = 0;
            local_48[4] = local_48[3] << 2;
            local_48[2] = local_48[4] + 0x18;
            local_48[1] = (iVar12 + 6) * 4;
          }
        }
      }
      FUN_c0681e1c(param_1,ppiVar4,ppiVar5,iVar6);
    }
  }
  else {
    iVar8 = -0x7fffffe5;
  }
  FUN_c067e2f4(param_4,local_48,param_5);
  return iVar8;
}



/* c0677558 FUN_c0677558 */

/* Boundary evidence: original MIPS .pdata c0677558..c0677717. Semantic name remains unreviewed. */

undefined4 FUN_c0677558(int *param_1,uint param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  uVar4 = 0;
  puVar5 = param_3;
  iVar2 = FUN_c067c558(param_3,0);
  if (iVar2 == 0) {
    uVar8 = 0x80000035;
  }
  else {
    iVar2 = FUN_c067d14c(param_1);
    if (iVar2 == 0) {
      uVar8 = 0x8000002b;
    }
    else {
      uVar3 = FUN_c067cc04((int)param_1);
      if (param_2 < uVar3) {
        iVar2 = param_1[6];
        uVar8 = 0;
        FUN_c067bc18();
        puVar6 = *(undefined4 **)(iVar2 + 0xc);
        uVar4 = 0xffffffff;
        while (puVar6 != (undefined4 *)(iVar2 + 0xc)) {
          puVar7 = (undefined4 *)*puVar6;
          piVar1 = puVar6 + 0xf;
          puVar6 = puVar7;
          if (((*piVar1 != 0) && (uVar3 = *(uint *)(param_2 * 4 + *piVar1), uVar3 != 0xffffffff)) &&
             ((uVar4 == 0xffffffff || (uVar3 < uVar4)))) {
            uVar4 = uVar3;
          }
        }
        FUN_c067bc40();
        FUN_c067c558(param_3,uVar4);
      }
      else {
        uVar8 = 0x80000011;
      }
      FUN_c0681e1c(param_1,uVar4,puVar5,param_4);
    }
  }
  return uVar8;
}



/* c0677718 FUN_c0677718 */

/* Boundary evidence: original MIPS .pdata c0677718..c0677723. Semantic name remains unreviewed. */

undefined4 FUN_c0677718(void)

{
  return 1;
}



/* c0677724 FUN_c0677724 */

/* Boundary evidence: original MIPS .pdata c0677724..c06779d7. Semantic name remains unreviewed. */

int FUN_c0677724(undefined4 param_1,int param_2,int param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *local_58;
  int *local_54;
  undefined4 *local_50;
  uint local_4c;
  wchar_t *local_48;
  wchar_t *local_44;
  int local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  int local_30;
  
  local_58 = (int *)0x0;
  iVar2 = FUN_c067e1b0(param_2,0x18,&local_58,1,param_3);
  if (iVar2 == 0) {
    iVar10 = 0x18;
    local_54 = (int *)0x18;
    iVar4 = *local_58;
    iVar7 = 0;
    FUN_c067bc18();
    local_50 = DAT_c0686160;
    uVar6 = iVar4 - 0x18;
    puVar9 = DAT_c0686160;
    while ((undefined4 **)puVar9 != &DAT_c0686160) {
      puVar8 = (undefined4 *)*puVar9;
      local_50 = puVar8;
      sVar3 = wcslen((wchar_t *)(puVar9 + 7));
      uVar5 = (sVar3 + 7) * 2;
      local_54 = (int *)(uVar5 + (int)local_54);
      puVar9 = puVar8;
      local_34 = local_54;
      if (uVar6 < uVar5) {
        local_4c = 0;
        uVar6 = local_4c;
      }
      else {
        local_4c = uVar6 + (sVar3 + 7) * -2;
        iVar10 = uVar5 + iVar10;
        iVar7 = iVar7 + 1;
        uVar6 = local_4c;
        local_38 = iVar7;
        local_30 = iVar10;
      }
    }
    local_58[1] = (int)local_54;
    local_58[2] = iVar10;
    local_58[3] = iVar7;
    local_58[4] = iVar10 + -0x18;
    local_58[5] = 0x18;
    if (iVar7 != 0) {
      local_54 = local_58 + 6;
      iVar4 = (iVar7 + 2) * 0xc;
      local_44 = (wchar_t *)(local_58 + (iVar7 + 2) * 3);
      local_4c = *local_58 - 0x18;
      local_50 = DAT_c0686160;
      puVar9 = DAT_c0686160;
      do {
        local_48 = local_44;
        local_40 = iVar4;
        local_3c = local_54;
        if ((undefined4 **)puVar9 == &DAT_c0686160) break;
        puVar8 = (undefined4 *)*puVar9;
        *local_54 = puVar9[3];
        local_50 = puVar8;
        sVar3 = wcslen((wchar_t *)(puVar9 + 7));
        pwVar1 = local_48;
        local_54[1] = (sVar3 + 1) * 2;
        local_54[2] = iVar4;
        wcscpy(local_48,(wchar_t *)(puVar9 + 7));
        local_48 = (wchar_t *)((local_54[1] & 0xfffffffeU) + (int)pwVar1);
        iVar4 = local_54[1] + iVar4;
        local_54 = local_54 + 3;
        iVar7 = iVar7 + -1;
        puVar9 = puVar8;
        local_44 = local_48;
        local_40 = iVar4;
        local_3c = local_54;
        local_38 = iVar7;
      } while (iVar7 != 0);
    }
    FUN_c067bc40();
  }
  FUN_c067e2f4(param_2,local_58,param_3);
  return iVar2;
}



/* c06779d8 FUN_c06779d8 */

/* Boundary evidence: original MIPS .pdata c06779d8..c06779e3. Semantic name remains unreviewed. */

undefined4 FUN_c06779d8(void)

{
  return 1;
}



/* c06779e4 FUN_c06779e4 */

/* Boundary evidence: original MIPS .pdata c06779e4..c0677a97. Semantic name remains unreviewed. */

undefined4 FUN_c06779e4(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80000035;
  puVar2 = param_3;
  iVar1 = FUN_c067c558(param_2,0);
  if ((iVar1 != 0) && (iVar1 = FUN_c067c558(param_3,0), iVar1 != 0)) {
    iVar1 = FUN_c067d14c(param_1);
    if (iVar1 == 0) {
      uVar3 = 0x8000002b;
    }
    else {
      uVar3 = 0;
      FUN_c067c558(param_2,param_1[0xb]);
      iVar1 = param_1[0xc];
      FUN_c067c558(param_3,iVar1);
      FUN_c0681e1c(param_1,iVar1,puVar2,param_4);
    }
  }
  return uVar3;
}



/* c0677a98 FUN_c0677a98 */

/* Boundary evidence: original MIPS .pdata c0677a98..c0677e8b. Semantic name remains unreviewed. */

int FUN_c0677a98(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  LSTATUS LVar5;
  void *pvVar6;
  long lVar7;
  size_t sVar8;
  LPWSTR _Str;
  PHKEY ppHVar9;
  wchar_t *****pppppwVar10;
  SIZE_T *****pppppSVar11;
  int *piVar12;
  long *plVar13;
  wchar_t ***pppwVar14;
  PHKEY ppHVar15;
  wchar_t ***local_70;
  wchar_t **local_6c;
  wchar_t ****local_68;
  HKEY local_64;
  int local_60;
  HKEY local_5c;
  SIZE_T ****local_58;
  int local_54;
  long local_50;
  wchar_t *local_4c;
  wchar_t *local_3c;
  wchar_t *local_38;
  wchar_t *local_34;
  int local_30;
  
  local_68 = (wchar_t ****)0x0;
  bVar1 = false;
  local_70 = (wchar_t ***)0x0;
  local_64 = (HKEY)0x0;
  local_5c = (HKEY)0x0;
  local_60 = param_3;
  local_54 = param_4;
  if (param_1 != (int *)0x0) {
    iVar3 = FUN_c067d02c(param_1);
    iVar4 = DAT_c06861d0;
    if (iVar3 == 0) goto LAB_c0677e08;
    bVar1 = true;
  }
  pppppSVar11 = (SIZE_T *****)0x1;
  pppppwVar10 = (wchar_t *****)&local_70;
  ppHVar9 = (PHKEY)0x2c;
  iVar4 = FUN_c067e1b0(param_3,0x2c,pppppwVar10,1,param_4);
  if (iVar4 == 0) {
    local_70[2] = (wchar_t **)0x2c;
    pppppSVar11 = &local_58;
    local_70[1] = (wchar_t **)0x2c;
    pppppwVar10 = &local_68;
    ppHVar9 = &local_64;
    LVar5 = FUN_c06834ec(&local_5c,ppHVar9,pppppwVar10,(SIZE_T *)pppppSVar11,(LPDWORD)&local_6c,
                         (LPBYTE)(local_70 + 6));
    if (LVar5 == 0) {
      ppHVar9 = (PHKEY)*local_70;
      pppppSVar11 = (SIZE_T *****)(local_70 + 1);
      pppppwVar10 = (wchar_t *****)(local_70 + 2);
      pvVar6 = FUN_c067bc68((int)local_70,(uint)ppHVar9,(int *)pppppwVar10,(uint *)pppppSVar11,
                            (int *)(local_70 + 5),(size_t *)(local_70 + 4),(void *)0x0,
                            (int)local_6c * 0x44);
      iVar4 = 0;
      if (pvVar6 != (void *)0x0) {
        local_70[3] = (wchar_t **)0x0;
        ppHVar15 = (PHKEY)0x0;
        if (local_70[3] < local_6c) {
          do {
            ppHVar9 = ppHVar15;
            pppppwVar10 = (wchar_t *****)local_68;
            pppppSVar11 = (SIZE_T *****)local_58;
            LVar5 = FUN_c06836c0(local_64,ppHVar15,(wchar_t *)local_68,(DWORD)local_58,&local_50);
            if (LVar5 == 0) {
              pppppwVar10 = (wchar_t *****)0x0;
              plVar13 = (long *)((int)local_70[3] * 0x44 + (int)pvVar6);
              *plVar13 = local_50;
              ppHVar9 = (PHKEY)0x0;
              lVar7 = wcstol(local_34,(wchar_t **)0x0,0);
              pwVar2 = local_3c;
              plVar13[3] = lVar7;
              if (local_3c != (wchar_t *)0x0) {
                sVar8 = wcslen(local_3c);
                ppHVar9 = (PHKEY)*local_70;
                pppppSVar11 = (SIZE_T *****)(local_70 + 1);
                pppppwVar10 = (wchar_t *****)(local_70 + 2);
                FUN_c067bc68((int)local_70,(uint)ppHVar9,(int *)pppppwVar10,(uint *)pppppSVar11,
                             plVar13 + 5,(size_t *)(plVar13 + 4),pwVar2,(sVar8 + 1) * 2);
              }
              pwVar2 = local_38;
              if (local_38 != (wchar_t *)0x0) {
                sVar8 = wcslen(local_38);
                ppHVar9 = (PHKEY)*local_70;
                pppppSVar11 = (SIZE_T *****)(local_70 + 1);
                pppppwVar10 = (wchar_t *****)(local_70 + 2);
                FUN_c067bc68((int)local_70,(uint)ppHVar9,(int *)pppppwVar10,(uint *)pppppSVar11,
                             plVar13 + 0x10,(size_t *)(plVar13 + 0xf),pwVar2,(sVar8 + 1) * 2);
              }
              pwVar2 = local_4c;
              if (local_4c != (wchar_t *)0x0) {
                sVar8 = wcslen(local_4c);
                ppHVar9 = (PHKEY)*local_70;
                pppppSVar11 = (SIZE_T *****)(local_70 + 1);
                pppppwVar10 = (wchar_t *****)(local_70 + 2);
                FUN_c067bc68((int)local_70,(uint)ppHVar9,(int *)pppppwVar10,(uint *)pppppSVar11,
                             plVar13 + 2,(size_t *)(plVar13 + 1),pwVar2,(sVar8 + 1) * 2);
              }
              plVar13[0xe] = (uint)(local_30 != 0);
              local_70[3] = (wchar_t **)((int)local_70[3] + 1);
            }
            else {
              local_6c = (wchar_t **)((int)local_6c - 1);
            }
            ppHVar15 = (PHKEY)((int)ppHVar15 + 1);
            param_4 = local_54;
          } while (local_70[3] < local_6c);
        }
        pppwVar14 = (wchar_t ***)0x0;
        if ((wchar_t ***)local_6c != (wchar_t ***)0x0) {
          piVar12 = (int *)((int)pvVar6 + 0x30);
          do {
            _Str = FUN_c0683d84(piVar12[-0xc]);
            if (_Str == (LPWSTR)0x0) {
              local_6c = (wchar_t **)((int)local_6c - 1);
            }
            else {
              sVar8 = wcslen(_Str);
              ppHVar9 = (PHKEY)*local_70;
              pppppSVar11 = (SIZE_T *****)(local_70 + 1);
              pppppwVar10 = (wchar_t *****)(local_70 + 2);
              FUN_c067bc68((int)local_70,(uint)ppHVar9,(int *)pppppwVar10,(uint *)pppppSVar11,
                           piVar12,(size_t *)(piVar12 + -1),_Str,(sVar8 + 1) * 2);
              LocalFree(_Str);
            }
            pppwVar14 = (wchar_t ***)((int)pppwVar14 + 1);
            piVar12 = piVar12 + 0x11;
          } while (pppwVar14 < local_6c);
        }
      }
    }
    else {
      iVar4 = -0x7fffffb0;
    }
  }
  param_3 = local_60;
  if (bVar1) {
    FUN_c06825a0(param_1,ppHVar9,pppppwVar10,pppppSVar11);
    param_3 = local_60;
  }
LAB_c0677e08:
  if ((wchar_t *****)local_68 != (wchar_t *****)0x0) {
    LocalFree(local_68);
  }
  if (local_64 != (HKEY)0x0) {
    RegCloseKey(local_64);
  }
  if (local_5c != (HKEY)0x0) {
    RegCloseKey(local_5c);
  }
  FUN_c067e2f4(param_3,local_70,param_4);
  return iVar4;
}



/* c0677e8c FUN_c0677e8c */

/* Boundary evidence: original MIPS .pdata c0677e8c..c0678247. Semantic name remains unreviewed. */

int FUN_c0677e8c(int *param_1,STRSAFE_PCNZWCH param_2,wchar_t *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  wchar_t *hMem;
  int *piVar8;
  
  hMem = (wchar_t *)0x0;
  if (param_2 == (STRSAFE_PCNZWCH)0x0) {
    iVar5 = FUN_c067ca84((uint)param_3);
    if (iVar5 == -1) {
      iVar5 = -0x7fffffd1;
      goto LAB_c06781ec;
    }
    piVar1 = FUN_c067e788(iVar5,'\x01');
  }
  else {
    hMem = FUN_c067c2ec(param_2);
    if (hMem == (wchar_t *)0x0) {
      iVar5 = -0x7fffffcb;
      goto LAB_c06781ec;
    }
    param_3 = hMem;
    piVar1 = FUN_c067c5ac(0,(undefined4 *)0x0,hMem);
  }
  if (piVar1 == (int *)0x0) {
    iVar5 = -0x7fffffb2;
    goto LAB_c06781ec;
  }
  piVar3 = (int *)0x4;
  iVar5 = FUN_c067e31c(param_1,4);
  if (iVar5 == 0) {
    iVar5 = FUN_c067d14c((int *)param_1[5]);
    if (iVar5 == 0) {
      iVar5 = -0x7fffffb8;
    }
    else {
      if (*(int **)(param_1[5] + 0x14) == piVar1) {
        iVar5 = -0x7fffffb1;
      }
      else {
        piVar8 = *(int **)(param_1[5] + 0x18);
        FUN_c067bc18();
        piVar6 = piVar8 + 3;
        for (piVar4 = (int *)*piVar6; piVar4 != piVar6; piVar4 = (int *)*piVar4) {
          piVar7 = piVar4 + -3;
          if ((int *)piVar4[2] == piVar1) {
            if (piVar4 != piVar6) goto LAB_c0678038;
            break;
          }
        }
        piVar7 = (int *)0x0;
LAB_c0678038:
        iVar5 = -0x7fffffb8;
        FUN_c067bc40();
        iVar2 = FUN_c067d14c(piVar7);
        if (iVar2 == 0) {
          iVar5 = -0x7fffffb2;
        }
        else {
          piVar6 = (int *)param_1[6];
          piVar4 = FUN_c067e58c((int)piVar1,0,piVar6);
          if (piVar4 == (int *)0x0) {
            param_3 = (wchar_t *)0x4;
            piVar3 = piVar6;
            piVar4 = FUN_c0681edc(piVar7,piVar6,4,param_4);
            if (piVar4 != (int *)0x0) {
              piVar4[8] = piVar4[8] + 1;
              FUN_c067bf04((int)(piVar1 + 6),(int)piVar7,0x17,piVar7[0xe],piVar6[0x11],(int)piVar4,4
                          );
              iVar5 = 0;
              param_4 = (int *)0x800;
              goto LAB_c067814c;
            }
          }
          else {
            iVar5 = 4;
            piVar6[0xe] = piVar6[0xe] + -1;
            param_4 = (int *)0x2800;
LAB_c067814c:
            piVar6[0xd] = piVar6[0xd] + 1;
            piVar4[9] = 4;
            FUN_c067bf04((int)(piVar1 + 6),(int)piVar4,2,piVar7[0xe],piVar6[0x18],piVar6[0x19],iVar5
                        );
            param_3 = (wchar_t *)0x1;
            FUN_c067f860(piVar8,piVar6,1,param_4,(int *)0x0,(int *)0x0);
            iVar5 = 0;
            FUN_c068179c(piVar4);
            piVar3 = piVar6;
          }
          FUN_c0681e1c(piVar7,piVar3,param_3,param_4);
        }
      }
      FUN_c0681e1c((HLOCAL)param_1[5],piVar3,param_3,param_4);
    }
    FUN_c068179c(param_1);
  }
  FUN_c06825a0(piVar1,piVar3,param_3,param_4);
LAB_c06781ec:
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
  return iVar5;
}



/* c0678248 FUN_c0678248 */

/* Boundary evidence: original MIPS .pdata c0678248..c0678253. Semantic name remains unreviewed. */

undefined4 FUN_c0678248(void)

{
  return 1;
}



/* c0678254 FUN_c0678254 */

/* Boundary evidence: original MIPS .pdata c0678254..c06782ef. Semantic name remains unreviewed. */

void FUN_c0678254(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_18;
  int local_14;
  
  piVar3 = &local_18;
  local_18 = -0x7fffffce;
  piVar2 = param_1;
  iVar1 = FUN_c067f070(10,(int *)0x0,param_1,piVar3,(int *)0x0,&local_14,0,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(local_14 + 0x18) + 0x18) + 0x7c))
                      (local_18,*(undefined4 *)(local_14 + 0x24));
    FUN_c068179c(param_1);
  }
  FUN_c067c160(iVar1,local_18,(int)piVar2,(int)piVar3);
  return;
}



/* c06782fc FUN_c06782fc */

/* Boundary evidence: original MIPS .pdata c06782fc..c06784cb. Semantic name remains unreviewed. */

int FUN_c06782fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                undefined4 *param_5,undefined4 *param_6,int param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  wchar_t *hMem;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *local_30;
  undefined4 *local_2c;
  
  local_30 = (undefined4 *)0x0;
  iVar4 = -0x7fffffcb;
  local_2c = param_1;
  iVar1 = FUN_c067c558(param_1,0);
  if (iVar1 == 0) goto LAB_c067848c;
  iVar1 = FUN_c067c558(param_5,0);
  if (iVar1 == 0) goto LAB_c067848c;
  uVar2 = FUN_c067c500();
  iVar1 = FUN_c067c558(param_6,uVar2);
  if ((iVar1 == 0) || (hMem = FUN_c067c2ec(param_4), hMem == (wchar_t *)0x0)) goto LAB_c067848c;
  iVar4 = FUN_c067e1b0(param_7,0x18,&local_30,1,param_8);
  if (iVar4 == 0) {
    if (uVar2 < 0x20001) {
      iVar1 = FUN_c067cd94(uVar2,0);
      if (iVar1 == 0) {
        iVar4 = -0x7ffffff4;
        goto LAB_c0678484;
      }
    }
    else {
      uVar2 = 0x20000;
    }
    if (DAT_c0686148 == 0) {
      puVar3 = FUN_c068095c(hMem,local_30 + 5);
      if (puVar3 == (undefined4 *)0x0) {
        iVar4 = -0x7fffffb8;
      }
      else {
        iVar4 = 0;
        FUN_c067c558(local_2c,puVar3);
        FUN_c067c558(param_5,DAT_c06861c4);
        FUN_c067c558(param_6,uVar2);
        DAT_c06861c0 = DAT_c06861c0 + 1;
        DAT_c06861d0 = 0x80000014;
      }
    }
    else {
      iVar4 = -0x7fffffae;
    }
  }
LAB_c0678484:
  LocalFree(hMem);
LAB_c067848c:
  FUN_c067e2f4(param_7,local_30,param_8);
  return iVar4;
}



/* c06784cc FUN_c06784cc */

/* Boundary evidence: original MIPS .pdata c06784cc..c0678773. Semantic name remains unreviewed. */

void FUN_c06784cc(STRSAFE_PCNZWCH *****param_1,undefined4 *param_2,STRSAFE_PCNZWCH *****param_3,
                 STRSAFE_PCNZWCH *****param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  STRSAFE_PCNZWCH *******ppppppppwVar3;
  uint uVar4;
  HLOCAL hMem;
  STRSAFE_PCNZWCH ******local_40;
  STRSAFE_PCNZWCH ******local_3c;
  STRSAFE_PCNZWCH ******local_38;
  STRSAFE_PCNZWCH ******local_34;
  STRSAFE_PCNZWCH *****local_30;
  int local_2c;
  
  local_38 = (STRSAFE_PCNZWCH ******)0x0;
  hMem = (HLOCAL)0x0;
  local_3c = (STRSAFE_PCNZWCH ******)0x0;
  bVar1 = true;
  local_30 = (STRSAFE_PCNZWCH *****)0x80000032;
  uVar4 = 0x80000035;
  if (((param_3 == (STRSAFE_PCNZWCH *****)0x0) ||
      (hMem = FUN_c067c2ec((STRSAFE_PCNZWCH)param_3), hMem != (HLOCAL)0x0)) &&
     (iVar2 = FUN_c067c558(param_2,0), iVar2 != 0)) {
    if (param_5 != 0) {
      param_4 = (STRSAFE_PCNZWCH *****)0x0;
      param_3 = (STRSAFE_PCNZWCH *****)&local_38;
      uVar4 = FUN_c067e1b0(param_5,0xb4,param_3,0,param_6);
      if (uVar4 != 0) goto LAB_c0678704;
    }
    iVar2 = FUN_c067d14c((int *)param_1);
    if (iVar2 == 0) {
      uVar4 = 0x8000002b;
    }
    else {
      if ((STRSAFE_PCNZWCH *******)local_38 == (STRSAFE_PCNZWCH *******)0x0) {
LAB_c06785dc:
        param_3 = (STRSAFE_PCNZWCH *****)&local_34;
        ppppppppwVar3 = &local_40;
        param_4 = (STRSAFE_PCNZWCH *****)local_3c;
        uVar4 = FUN_c06821dc((int *)param_1,ppppppppwVar3,param_3,local_3c);
        if (uVar4 == 0) {
          param_4 = (STRSAFE_PCNZWCH *****)&local_30;
          ppppppppwVar3 = (STRSAFE_PCNZWCH *******)param_1;
          param_3 = (STRSAFE_PCNZWCH *****)local_34;
          uVar4 = FUN_c067f070(0xb,(int *)param_1,(int *)local_34,(int *)param_4,&local_2c,
                               (int *)0x0,hMem,local_3c);
          if (uVar4 == 0) {
            local_40[7] = (STRSAFE_PCNZWCH *****)param_1[5];
            local_40[6] = (STRSAFE_PCNZWCH *****)*(STRSAFE_PCNZWCH *******)(local_2c + 0x14);
            local_40[0x17] = (STRSAFE_PCNZWCH *****)0x1;
            local_40[0x14] = (STRSAFE_PCNZWCH *****)0x1;
            local_40[0x18] = (STRSAFE_PCNZWCH *****)0x8000;
            bVar1 = false;
            FUN_c067c558(param_2,local_34);
            param_4 = (STRSAFE_PCNZWCH *****)(local_40 + 9);
            ppppppppwVar3 = *(STRSAFE_PCNZWCH ********)(local_2c + 0x18);
            param_3 = (STRSAFE_PCNZWCH *****)local_40;
            uVar4 = (*(code *)local_40[6][6][0x20])(local_30);
            if ((uVar4 & 0x80000000) != 0) {
              local_40[0x14] = (STRSAFE_PCNZWCH *****)0x0;
              local_40[0x18] = (STRSAFE_PCNZWCH *****)0x1;
            }
            FUN_c068179c(local_34);
            FUN_c0681e1c(param_1,ppppppppwVar3,param_3,param_4);
          }
          if ((uVar4 & 0x80000000) != 0) {
            FUN_c067d5e4(local_34);
          }
        }
      }
      else {
        param_3 = (STRSAFE_PCNZWCH *****)param_1[8];
        ppppppppwVar3 = &local_3c;
        uVar4 = FUN_c067db98((uint *)local_38,ppppppppwVar3,(uint)param_3);
        if (local_3c != local_38) {
          LocalFree(local_38);
          local_38 = (STRSAFE_PCNZWCH ******)0x0;
        }
        if (uVar4 == 0) goto LAB_c06785dc;
      }
      FUN_c0681e1c(param_1,ppppppppwVar3,param_3,param_4);
      if (!bVar1) goto LAB_c067873c;
    }
  }
LAB_c0678704:
  if ((STRSAFE_PCNZWCH *******)local_3c != (STRSAFE_PCNZWCH *******)0x0) {
    LocalFree(local_3c);
  }
  if ((STRSAFE_PCNZWCH *******)local_38 != (STRSAFE_PCNZWCH *******)0x0) {
    LocalFree(local_38);
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
LAB_c067873c:
  FUN_c067c160(uVar4,(int)local_30,(int)param_3,(int)param_4);
  return;
}



/* c0678774 FUN_c0678774 */

/* Boundary evidence: original MIPS .pdata c0678774..c06788b3. Semantic name remains unreviewed. */

int FUN_c0678774(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 < 8) {
    iVar2 = FUN_c067e31c(param_1,1);
    if (iVar2 == 0) {
      param_1[0xc] = param_2;
      iVar2 = param_1[6];
      FUN_c067bc18();
      for (puVar1 = *(undefined4 **)(iVar2 + 0xc); puVar1 != (undefined4 *)(iVar2 + 0xc);
          puVar1 = (undefined4 *)*puVar1) {
        param_2 = puVar1[9] | param_2;
      }
      FUN_c067bc40();
      iVar2 = (**(code **)(*(int *)(*(int *)(iVar2 + 0x18) + 0x18) + 0x84))
                        (*(undefined4 *)(iVar2 + 0x24),param_2);
      FUN_c068179c(param_1);
    }
  }
  else {
    iVar2 = -0x7fffffd9;
  }
  return iVar2;
}



/* c06788b4 FUN_c06788b4 */

/* Boundary evidence: original MIPS .pdata c06788b4..c06788bf. Semantic name remains unreviewed. */

undefined4 FUN_c06788b4(void)

{
  return 1;
}



/* c06788c0 FUN_c06788c0 */

/* Boundary evidence: original MIPS .pdata c06788c0..c0678a0f. Semantic name remains unreviewed. */

int FUN_c06788c0(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_2 < 0x40000) && ((param_2 & 1) == 0)) {
    iVar1 = FUN_c067e31c(param_1,1);
    if (iVar1 == 0) {
      param_1[0xb] = param_2;
      iVar1 = param_1[6];
      FUN_c067bc18();
      for (puVar2 = *(undefined4 **)(iVar1 + 0xc); puVar2 != (undefined4 *)(iVar1 + 0xc);
          puVar2 = (undefined4 *)*puVar2) {
        param_2 = puVar2[8] | param_2;
      }
      FUN_c067bc40();
      iVar1 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x18) + 0x18) + 0x88))
                        (*(undefined4 *)(iVar1 + 0x24),param_2);
      FUN_c068179c(param_1);
    }
  }
  else {
    iVar1 = -0x7fffffd1;
  }
  return iVar1;
}



/* c0678a10 FUN_c0678a10 */

/* Boundary evidence: original MIPS .pdata c0678a10..c0678a1b. Semantic name remains unreviewed. */

undefined4 FUN_c0678a10(void)

{
  return 1;
}



/* c0678a1c FUN_c0678a1c */

/* Boundary evidence: original MIPS .pdata c0678a1c..c0678cbf. Semantic name remains unreviewed. */

undefined4
FUN_c0678a1c(int *param_1,uint param_2,void *param_3,void *param_4,undefined4 *param_5,int param_6,
            void *param_7)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 uVar7;
  void *_Dst;
  void *pvVar8;
  uint uVar9;
  
  _Dst = (void *)0x0;
  uVar9 = 0x20000;
  uVar6 = uVar9;
  if ((DAT_c06861c4 <= param_2) && (param_2 != 0xffffffff)) {
    uVar7 = 0x80000002;
    goto LAB_c0678c74;
  }
  pvVar4 = param_3;
  pvVar5 = param_4;
  if ((param_6 == 0) ||
     (pvVar4 = param_7, _Dst = FUN_c067c1e4(param_6,0x10,(int)param_7), _Dst != (HLOCAL)0x0)) {
    if ((param_4 < param_3) || (((void *)0x20000 < param_3 || (param_4 < (void *)0x10003)))) {
LAB_c0678c6c:
      uVar7 = 0x8000000c;
      uVar6 = uVar9;
      goto LAB_c0678c74;
    }
    pvVar3 = (void *)0x0;
    iVar1 = FUN_c067c558(param_5,0);
    if (iVar1 != 0) {
      if ((param_4 < (void *)0x20000) &&
         ((uVar6 = 0x10005, param_4 < (void *)0x10005 || ((void *)0x10005 < param_3)))) {
        if ((param_4 < (void *)0x10004) || ((void *)0x10004 < param_3)) {
          if ((void *)0x10003 < param_3) goto LAB_c0678c6c;
          uVar6 = 0x10003;
        }
        else {
          uVar6 = 0x10004;
        }
      }
      iVar1 = FUN_c067d02c(param_1);
      uVar7 = DAT_c06861d0;
      if (iVar1 == 0) goto LAB_c0678c74;
      pvVar8 = _Dst;
      if (param_2 == 0xffffffff) {
LAB_c0678c4c:
        uVar7 = 0;
        _Dst = pvVar8;
      }
      else {
        piVar2 = FUN_c067c75c(param_2);
        if (piVar2 == (int *)0x0) {
          uVar7 = 0x80000002;
        }
        else {
          pvVar3 = *(void **)(piVar2[5] + 0x14);
          if (param_3 <= pvVar3) {
            if ((uint)param_1[4] < uVar6) {
              param_1[4] = uVar6;
            }
            if (_Dst != (void *)0x0) {
              iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x68))(param_2,pvVar3,_Dst);
              if (iVar1 != 0) {
                memset(_Dst,0,0x10);
              }
              pvVar4 = (void *)0x10;
              FUN_c067c3b4(param_6,_Dst,0x10,(int)param_7);
              pvVar8 = (void *)0x0;
              pvVar3 = _Dst;
              pvVar5 = param_7;
            }
            goto LAB_c0678c4c;
          }
          uVar7 = 0x8000000c;
        }
      }
      FUN_c06825a0(param_1,pvVar3,pvVar4,pvVar5);
      goto LAB_c0678c74;
    }
  }
  uVar7 = 0x80000035;
LAB_c0678c74:
  FUN_c067c558(param_5,uVar6);
  if (_Dst != (HLOCAL)0x0) {
    LocalFree(_Dst);
  }
  return uVar7;
}



/* c0678cc0 FUN_c0678cc0 */

/* Boundary evidence: original MIPS .pdata c0678cc0..c0678e07. Semantic name remains unreviewed. */

int FUN_c0678cc0(int *param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_28 [2];
  
  local_28[0] = FUN_c067c500();
  iVar1 = FUN_c067c558(param_6,0);
  if (iVar1 == 0) {
    iVar1 = -0x7fffffcb;
  }
  else {
    piVar2 = FUN_c067c75c(param_2);
    if (piVar2 == (int *)0x0) {
      iVar1 = -0x7ffffffe;
    }
    else {
      iVar1 = FUN_c067cd94(param_3,piVar2[0xb]);
      if (iVar1 == 0) {
        iVar1 = -0x7ffffff4;
      }
      else {
        iVar3 = FUN_c067d02c(param_1);
        iVar1 = DAT_c06861d0;
        if (iVar3 != 0) {
          iVar1 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x90))
                            (piVar2[7],*(undefined4 *)(piVar2[5] + 0x14),param_4,param_5,local_28);
          if (iVar1 == 0) {
            if (local_28[0] == 0) {
              iVar1 = -0x7ffffff3;
            }
            else {
              piVar2[0xc] = local_28[0];
            }
          }
          iVar3 = local_28[0];
          FUN_c067c558(param_6,local_28[0]);
          FUN_c06825a0(param_1,iVar3,param_4,param_5);
        }
      }
    }
  }
  return iVar1;
}



/* c0678e08 FUN_c0678e08 */

/* Boundary evidence: original MIPS .pdata c0678e08..c067900b. Semantic name remains unreviewed. */

void FUN_c0678e08(STRSAFE_PCNZWCH ******param_1,STRSAFE_PCNZWCH ******param_2,
                 STRSAFE_PCNZWCH ******param_3,STRSAFE_PCNZWCH *****param_4,STRSAFE_PCNZWCH param_5)

{
  bool bVar1;
  int iVar2;
  STRSAFE_PCNZWCH ********pppppppppwVar3;
  STRSAFE_PCNZWCH ********pppppppppwVar4;
  STRSAFE_PCNZWCH *******ppppppppwVar5;
  uint uVar6;
  HLOCAL hMem;
  HLOCAL hMem_00;
  STRSAFE_PCNZWCH *******local_38;
  STRSAFE_PCNZWCH *****local_34;
  STRSAFE_PCNZWCH ******local_30;
  int local_2c;
  
  local_34 = (STRSAFE_PCNZWCH *****)0x80000032;
  hMem_00 = (HLOCAL)0x0;
  hMem = (HLOCAL)0x0;
  bVar1 = true;
  uVar6 = 0x80000035;
  pppppppppwVar4 = (STRSAFE_PCNZWCH ********)param_3;
  ppppppppwVar5 = (STRSAFE_PCNZWCH *******)param_4;
  iVar2 = FUN_c067c558(param_3,0);
  if ((iVar2 != 0) &&
     ((param_4 == (STRSAFE_PCNZWCH *****)0x0 ||
      (hMem_00 = FUN_c067c2ec((STRSAFE_PCNZWCH)param_4), hMem_00 != (HLOCAL)0x0)))) {
    if ((param_5 == (STRSAFE_PCNZWCH)0x0) || (hMem = FUN_c067c2ec(param_5), hMem != (HLOCAL)0x0)) {
      iVar2 = FUN_c067d14c((int *)param_1);
      if (iVar2 == 0) {
        uVar6 = 0x8000002b;
      }
      else {
        ppppppppwVar5 = (STRSAFE_PCNZWCH *******)0x0;
        pppppppppwVar4 = &local_38;
        pppppppppwVar3 = (STRSAFE_PCNZWCH ********)&local_30;
        uVar6 = FUN_c06821dc((int *)param_1,pppppppppwVar3,pppppppppwVar4,0);
        if (uVar6 == 0) {
          ppppppppwVar5 = (STRSAFE_PCNZWCH *******)&local_34;
          pppppppppwVar3 = (STRSAFE_PCNZWCH ********)param_1;
          pppppppppwVar4 = (STRSAFE_PCNZWCH ********)local_38;
          uVar6 = FUN_c067f070(0xc,(int *)param_1,(int *)local_38,(int *)ppppppppwVar5,&local_2c,
                               (int *)0x0,hMem_00,hMem);
          if (uVar6 == 0) {
            bVar1 = false;
            FUN_c068179c(local_38);
            pppppppppwVar3 = *(STRSAFE_PCNZWCH *********)(local_2c + 0x18);
            ppppppppwVar5 = (STRSAFE_PCNZWCH *******)local_30;
            uVar6 = (*(code *)local_30[6][6][0x28])(local_34);
            if ((uVar6 & 0x80000000) == 0) {
              pppppppppwVar3 = (STRSAFE_PCNZWCH ********)local_38;
              FUN_c067c558(param_3,local_38);
              pppppppppwVar4 = (STRSAFE_PCNZWCH ********)param_2;
            }
            else {
              local_30[9] = (STRSAFE_PCNZWCH *****)0x0;
              pppppppppwVar4 = (STRSAFE_PCNZWCH ********)param_2;
            }
            FUN_c0681e1c(param_1,pppppppppwVar3,pppppppppwVar4,ppppppppwVar5);
          }
          if ((uVar6 & 0x80000000) != 0) {
            FUN_c067d5e4(local_38);
          }
        }
        FUN_c0681e1c(param_1,pppppppppwVar3,pppppppppwVar4,ppppppppwVar5);
        if (!bVar1) goto LAB_c0678fd4;
      }
    }
    if (hMem_00 != (HLOCAL)0x0) {
      LocalFree(hMem_00);
    }
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
  }
LAB_c0678fd4:
  FUN_c067c160(uVar6,(int)local_34,(int)pppppppppwVar4,(int)ppppppppwVar5);
  return;
}



/* c067900c FUN_c067900c */

/* Boundary evidence: original MIPS .pdata c067900c..c0679217. Semantic name remains unreviewed. */

void FUN_c067900c(int ***param_1,undefined4 *param_2,int param_3,int ***param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *****pppppiVar4;
  int *****pppppiVar5;
  int ****local_30;
  int local_2c;
  int ***local_28;
  int ****local_24;
  int ***local_20 [2];
  
  local_30 = (int ****)0x0;
  local_28 = (int ***)0x80000032;
  pppppiVar4 = (int *****)0x0;
  pppppiVar5 = (int *****)param_4;
  if (param_3 == 0) {
LAB_c0679068:
    iVar2 = FUN_c067c558(param_2,0);
    if (iVar2 == 0) {
      uVar1 = 0x80000035;
    }
    else {
      pppppiVar5 = (int *****)&local_28;
      pppppiVar4 = (int *****)param_1;
      uVar1 = FUN_c067f070(0xd,(int *)0x0,(int *)param_1,(int *)pppppiVar5,(int *)0x0,&local_2c,
                           local_30,0);
      if (uVar1 == 0) {
        piVar3 = FUN_c0682990((int)local_28);
        if (piVar3 != (int *)0x0) {
          piVar3[7] = 0;
          piVar3[8] = 0;
        }
        if (*(int *)(local_2c + 0x68) == local_2c) {
          pppppiVar4 = (int *****)local_20;
          pppppiVar5 = (int *****)local_30;
          uVar1 = FUN_c06821dc((int *)param_1[5],&local_24,pppppiVar4,local_30);
          if (uVar1 == 0) {
            local_24[0x1a] = (int ***)*(int *****)(local_2c + 0x68);
            if (piVar3 != (int *)0x0) {
              piVar3[7] = (int)local_24;
              piVar3[8] = (int)local_20[0];
              piVar3[9] = local_2c;
              piVar3[10] = (int)param_1;
            }
            pppppiVar5 = (int *****)(local_24 + 9);
            uVar1 = (**(code **)(*(int *)(*(int *)(local_2c + 0x18) + 0x18) + 0xa4))
                              (local_28,*(undefined4 *)(local_2c + 0x24),local_24,pppppiVar5,
                               local_30);
            if ((uVar1 & 0x80000000) == 0) {
              FUN_c067c558(param_2,local_20[0]);
              pppppiVar4 = (int *****)local_24;
            }
            else {
              FUN_c067d5e4(local_20[0]);
              pppppiVar4 = (int *****)local_24;
            }
          }
        }
        else {
          uVar1 = 0x80000020;
        }
        FUN_c068179c(param_1);
        if (piVar3 != (int *)0x0) {
          FUN_c06828c4(piVar3);
        }
        goto LAB_c06791f0;
      }
      if (uVar1 == 0x80000018) {
        uVar1 = 0x80000020;
      }
    }
  }
  else {
    pppppiVar5 = (int *****)0x0;
    pppppiVar4 = &local_30;
    uVar1 = FUN_c067e1b0(param_3,0xb4,pppppiVar4,0,(int)param_4);
    if (uVar1 == 0) goto LAB_c0679068;
  }
  if ((int *****)local_30 != (int *****)0x0) {
    LocalFree(local_30);
  }
LAB_c06791f0:
  FUN_c067c160(uVar1,(int)local_28,(int)pppppiVar4,(int)pppppiVar5);
  return;
}



/* c0679218 FUN_c0679218 */

/* Boundary evidence: original MIPS .pdata c0679218..c06792ff. Semantic name remains unreviewed. */

void FUN_c0679218(int *param_1,STRSAFE_PCNZWCH param_2,int *param_3,int *param_4)

{
  int *hMem;
  int *piVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar1 = param_3;
  hMem = FUN_c067c2ec(param_2);
  if (hMem == (int *)0x0) {
    iVar2 = -0x7fffffcb;
  }
  else {
    param_4 = &local_20;
    piVar1 = param_1;
    iVar2 = FUN_c067f070(0xe,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,hMem,0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0xa8))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      piVar1 = hMem;
      param_4 = param_3;
    }
    else {
      LocalFree(hMem);
    }
  }
  FUN_c067c160(iVar2,local_20,(int)piVar1,(int)param_4);
  return;
}



/* c0679300 FUN_c0679300 */

/* Boundary evidence: original MIPS .pdata c0679300..c067939b. Semantic name remains unreviewed. */

void FUN_c0679300(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_18;
  int local_14;
  
  piVar3 = &local_18;
  local_18 = -0x7fffffce;
  piVar2 = param_1;
  iVar1 = FUN_c067f070(0xf,(int *)0x0,param_1,piVar3,(int *)0x0,&local_14,0,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(local_14 + 0x18) + 0x18) + 0x124))
                      (local_18,*(undefined4 *)(local_14 + 0x24));
    FUN_c068179c(param_1);
  }
  FUN_c067c160(iVar1,local_18,(int)piVar2,(int)piVar3);
  return;
}



/* c067939c FUN_c067939c */

/* Boundary evidence: original MIPS .pdata c067939c..c067944f. Semantic name remains unreviewed. */

void FUN_c067939c(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_18;
  int local_14;
  
  piVar3 = &local_18;
  local_18 = -0x7fffffce;
  piVar2 = param_1;
  iVar1 = FUN_c067f070(0x10,(int *)0x0,param_1,piVar3,(int *)0x0,&local_14,0,0);
  if (iVar1 == 0) {
    if (*(int *)(local_14 + 0x68) == 0) {
      iVar1 = -0x7fffffe8;
    }
    else {
      iVar1 = (**(code **)(*(int *)(*(int *)(local_14 + 0x18) + 0x18) + 0xac))
                        (local_18,*(undefined4 *)(local_14 + 0x24));
    }
    FUN_c068179c(param_1);
  }
  FUN_c067c160(iVar1,local_18,(int)piVar2,(int)piVar3);
  return;
}



/* c0679450 FUN_c0679450 */

/* Boundary evidence: original MIPS .pdata c0679450..c067955b. Semantic name remains unreviewed. */

void FUN_c0679450(int *param_1,int param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int *hMem;
  int iVar3;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  piVar2 = (int *)0x0;
  if ((param_2 == 0) || (param_3 == (int *)0x0)) {
    param_3 = (int *)0x0;
LAB_c06794f0:
    param_4 = &local_20;
    piVar1 = param_1;
    iVar3 = FUN_c067f070(0x11,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,piVar2,0);
    hMem = piVar2;
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0xb8))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
      goto LAB_c06794c4;
    }
  }
  else {
    piVar1 = (int *)0x0;
    piVar2 = FUN_c067c1e4(param_2,(uint)param_3,0);
    if (piVar2 != (int *)0x0) goto LAB_c06794f0;
    iVar3 = -0x7fffffcb;
    hMem = piVar2;
  }
  param_3 = param_4;
  piVar2 = piVar1;
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
LAB_c06794c4:
  FUN_c067c160(iVar3,local_20,(int)piVar2,(int)param_3);
  return;
}



/* c067955c FUN_c067955c */

/* Boundary evidence: original MIPS .pdata c067955c..c067965f. Semantic name remains unreviewed. */

undefined4
FUN_c067955c(STRSAFE_PCNZWCH param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  int iVar1;
  wchar_t *hMem;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_c067ca84(param_2);
  if (iVar1 == -1) {
    uVar3 = 0x8000002f;
  }
  else if ((param_6 == 1) || (param_6 == 0)) {
    hMem = FUN_c067c2ec(param_1);
    if (hMem == (wchar_t *)0x0) {
      uVar3 = 0x80000035;
    }
    else {
      puVar2 = FUN_c067c5ac(0,(undefined4 *)0x0,hMem);
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x80000015;
      }
      else {
        uVar3 = 0;
        FUN_c06745f8(puVar2,iVar1,param_6);
        FUN_c06825a0(puVar2,iVar1,param_6,param_4);
      }
    }
    if (hMem != (wchar_t *)0x0) {
      LocalFree(hMem);
    }
  }
  else {
    uVar3 = 0x80000032;
  }
  return uVar3;
}



/* c0679660 FUN_c0679660 */

/* Boundary evidence: original MIPS .pdata c0679660..c06797ab. Semantic name remains unreviewed. */

void FUN_c0679660(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,int *param_6)

{
  int *piVar1;
  int *piVar2;
  HLOCAL hMem;
  int iVar3;
  int local_28;
  int local_24;
  
  local_28 = -0x7fffffce;
  hMem = (HLOCAL)0x0;
  if (((param_2 == (int *)0x0) || (((int)param_2 - 1U & (uint)param_2) != 0)) ||
     ((int *)0x40 < param_2)) {
    iVar3 = -0x7fffffea;
    piVar1 = param_3;
    piVar2 = param_4;
  }
  else {
    if (param_5 != 0) {
      piVar2 = param_4;
      hMem = FUN_c067c1e4(param_5,0x10,(int)param_6);
      if (hMem == (HLOCAL)0x0) {
        iVar3 = -0x7fffffcb;
        piVar1 = param_6;
        goto LAB_c067976c;
      }
    }
    piVar2 = &local_28;
    piVar1 = param_1;
    iVar3 = FUN_c067f070(0x12,(int *)0x0,param_1,piVar2,(int *)0x0,&local_24,hMem,0);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(*(int *)(*(int *)(local_24 + 0x18) + 0x18) + 0xc0))
                        (local_28,*(undefined4 *)(local_24 + 0x24),param_2,param_3,param_4,hMem);
      FUN_c068179c(param_1);
      goto LAB_c067977c;
    }
  }
LAB_c067976c:
  param_3 = piVar2;
  param_2 = piVar1;
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
LAB_c067977c:
  FUN_c067c160(iVar3,local_28,(int)param_2,(int)param_3);
  return;
}



/* c06797ac FUN_c06797ac */

/* Boundary evidence: original MIPS .pdata c06797ac..c0679907. Semantic name remains unreviewed. */

int FUN_c06797ac(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_2 == 2) || (param_2 == 4)) {
    iVar3 = FUN_c067e31c(param_1,1);
    if (iVar3 == 0) {
      piVar1 = (int *)param_1[6];
      if ((((param_2 == 2) && (piVar1[0x18] != 1)) && ((param_1[9] & 4U) != 0)) &&
         (piVar1[0xd] == 1)) {
        iVar3 = -0x7fffffe4;
      }
      else {
        uVar2 = param_1[9];
        if (param_2 != uVar2) {
          if ((uVar2 & 4) == 0) {
            if ((uVar2 & 2) != 0) {
              piVar1[0xe] = piVar1[0xe] + -1;
            }
          }
          else {
            piVar1[0xd] = piVar1[0xd] + -1;
          }
          if (param_2 == 4) {
            piVar1[0xd] = piVar1[0xd] + 1;
          }
          else {
            piVar1[0xe] = piVar1[0xe] + 1;
          }
          param_1[9] = param_2;
          uVar2 = 0x800;
          if (param_2 != 4) {
            uVar2 = 0x1000;
          }
          FUN_c067f6cc(piVar1,param_1,1,(int *)(uVar2 | 0x2000),0);
        }
      }
      FUN_c068179c(param_1);
    }
  }
  else {
    iVar3 = -0x7fffffe6;
  }
  return iVar3;
}



/* c0679908 FUN_c0679908 */

/* Boundary evidence: original MIPS .pdata c0679908..c0679abb. Semantic name remains unreviewed. */

LSTATUS FUN_c0679908(int *param_1,PHKEY param_2)

{
  bool bVar1;
  int iVar2;
  LSTATUS LVar3;
  int *hMem;
  wchar_t *pwVar4;
  wchar_t ***pppwVar5;
  SIZE_T ***pppSVar6;
  int *piVar7;
  PHKEY local_res4 [3];
  wchar_t **local_58;
  HKEY local_54;
  HKEY local_50;
  SIZE_T **local_4c;
  BYTE aBStack_48 [4];
  DWORD DStack_44;
  long alStack_40 [10];
  
  local_58 = (wchar_t **)0x0;
  bVar1 = false;
  local_54 = (HKEY)0x0;
  local_50 = (HKEY)0x0;
  local_res4[0] = param_2;
  if (param_1 != (int *)0x0) {
    iVar2 = FUN_c067d02c(param_1);
    LVar3 = DAT_c06861d0;
    if (iVar2 == 0) goto LAB_c0679a54;
    bVar1 = true;
  }
  pppSVar6 = &local_4c;
  pppwVar5 = &local_58;
  pwVar4 = (wchar_t *)&local_54;
  LVar3 = FUN_c06834ec(&local_50,(PHKEY)pwVar4,pppwVar5,(SIZE_T *)pppSVar6,&DStack_44,aBStack_48);
  if ((LVar3 == 0) &&
     (pwVar4 = (wchar_t *)local_res4[0], pppwVar5 = (wchar_t ***)local_58,
     LVar3 = FUN_c06836c0(local_54,local_res4[0],(wchar_t *)local_58,(DWORD)local_4c,alStack_40),
     pppSVar6 = (SIZE_T ***)local_4c, LVar3 == 0)) {
    pppSVar6 = (SIZE_T ***)0x4;
    pppwVar5 = (wchar_t ***)0x0;
    pwVar4 = L"CurrentLoc";
    LVar3 = RegSetValueExW(local_50,L"CurrentLoc",0,4,(BYTE *)local_res4,4);
    hMem = FUN_c067e044(&DAT_c0686160);
    if (hMem != (int *)0x0) {
      iVar2 = *hMem;
      piVar7 = hMem;
      while (iVar2 != 0) {
        piVar7 = piVar7 + 1;
        (**(code **)(*(int *)(iVar2 + 0x18) + 0x11c))(local_res4[0]);
        iVar2 = *piVar7;
      }
      LocalFree(hMem);
    }
  }
  else {
    LVar3 = -0x7fffffd3;
  }
  if (bVar1) {
    FUN_c06825a0(param_1,pwVar4,pppwVar5,pppSVar6);
  }
LAB_c0679a54:
  if ((wchar_t ***)local_58 != (wchar_t ***)0x0) {
    LocalFree(local_58);
  }
  if (local_54 != (HKEY)0x0) {
    RegCloseKey(local_54);
  }
  if (local_50 != (HKEY)0x0) {
    RegCloseKey(local_50);
  }
  return LVar3;
}



/* c0679abc FUN_c0679abc */

/* Boundary evidence: original MIPS .pdata c0679abc..c0679baf. Semantic name remains unreviewed. */

undefined4 FUN_c0679abc(int param_1,int param_2,uint param_3,STRSAFE_PCNZWCH param_4)

{
  int *piVar1;
  HLOCAL hMem;
  undefined4 uVar2;
  HLOCAL hMem_00;
  
  hMem_00 = (HLOCAL)0x0;
  piVar1 = FUN_c067c75c(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x80000002;
  }
  else {
    uVar2 = 0x80000035;
    hMem = FUN_c067c2ec(param_4);
    if (hMem != (HLOCAL)0x0) {
      if (((param_3 == 0) || (hMem_00 = FUN_c067c1e4(param_2,param_3,0), hMem_00 != (HLOCAL)0x0)) &&
         (uVar2 = (**(code **)(*(int *)(piVar1[5] + 0x18) + 200))(param_1,hMem_00,param_3,hMem),
         hMem_00 != (HLOCAL)0x0)) {
        LocalFree(hMem_00);
      }
      LocalFree(hMem);
    }
  }
  return uVar2;
}



/* c0679bb0 FUN_c0679bb0 */

/* Boundary evidence: original MIPS .pdata c0679bb0..c0679c6b. Semantic name remains unreviewed. */

int FUN_c0679bb0(int *param_1,uint param_2)

{
  int iVar1;
  
  if (((param_2 & 0xfffc0001) == 0) &&
     (((param_2 != 0 && ((param_2 - 1 & param_2) == 0)) || ((param_2 & 2) != 0)))) {
    iVar1 = FUN_c067e31c(param_1,4);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1[6] + 0x18) + 0x18) + 0xd0))
                        (*(undefined4 *)(param_1[6] + 0x24),param_2);
      FUN_c068179c(param_1);
    }
  }
  else {
    iVar1 = -0x7fffffd1;
  }
  return iVar1;
}



/* c0679c6c FUN_c0679c6c */

/* Boundary evidence: original MIPS .pdata c0679c6c..c0679d67. Semantic name remains unreviewed. */

undefined4 FUN_c0679c6c(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  HLOCAL pvVar3;
  uint uBytes;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uBytes = param_2;
  uVar4 = param_3;
  iVar1 = FUN_c067d14c(param_1);
  if (iVar1 == 0) {
    return 0x8000002b;
  }
  uVar2 = FUN_c067cc04((int)param_1);
  if (param_2 < uVar2) {
    if (param_1[0x12] == 0) {
      uBytes = uVar2 << 2;
      pvVar3 = LocalAlloc(0x40,uBytes);
      param_1[0x12] = (int)pvVar3;
      if (pvVar3 == (HLOCAL)0x0) {
        uVar5 = 0x80000044;
        goto LAB_c0679d40;
      }
      if (uVar2 != 0) {
        iVar1 = 0;
        do {
          *(undefined4 *)(param_1[0x12] + iVar1) = 0xffffffff;
          uVar2 = uVar2 - 1;
          iVar1 = iVar1 + 4;
        } while (uVar2 != 0);
      }
    }
    uVar5 = 0;
    *(undefined4 *)(param_2 * 4 + param_1[0x12]) = param_3;
  }
  else {
    uVar5 = 0x80000011;
  }
LAB_c0679d40:
  FUN_c0681e1c(param_1,uBytes,uVar4,param_4);
  return uVar5;
}



/* c0679d68 FUN_c0679d68 */

/* Boundary evidence: original MIPS .pdata c0679d68..c0679f67. Semantic name remains unreviewed. */

int FUN_c0679d68(int *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_2 & 0xfe000000) == 0) {
    if ((param_3 & 0xfffffe00) == 0) {
      uVar2 = param_2;
      uVar3 = param_3;
      iVar1 = FUN_c067d14c(param_1);
      if (iVar1 == 0) {
        iVar5 = -0x7fffffd5;
      }
      else {
        iVar1 = param_1[6];
        FUN_c067bc18();
        uVar6 = param_3;
        uVar7 = param_2;
        for (puVar4 = *(undefined4 **)(iVar1 + 0xc); puVar4 != (undefined4 *)(iVar1 + 0xc);
            puVar4 = (undefined4 *)*puVar4) {
          if (puVar4 + -3 != param_1) {
            uVar6 = puVar4[9] | uVar6;
            uVar7 = puVar4[8] | uVar7;
          }
        }
        FUN_c067bc40();
        if ((*(uint *)(iVar1 + 0x24) == uVar7) && (*(uint *)(iVar1 + 0x28) == uVar6)) {
          iVar5 = 0;
        }
        else {
          uVar2 = uVar7;
          uVar3 = uVar6;
          iVar5 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x14) + 0x18) + 0xd4))
                            (*(undefined4 *)(iVar1 + 0x18));
        }
        if (iVar5 == 0) {
          param_1[0xc] = param_3;
          param_1[0xb] = param_2;
          *(uint *)(iVar1 + 0x24) = uVar7;
          *(uint *)(iVar1 + 0x28) = uVar6;
        }
        FUN_c0681e1c(param_1,uVar2,uVar3,param_4);
      }
    }
    else {
      iVar5 = -0x7fffffed;
    }
  }
  else {
    iVar5 = -0x7fffffd4;
  }
  return iVar5;
}



/* c0679f68 FUN_c0679f68 */

/* Boundary evidence: original MIPS .pdata c0679f68..c0679f73. Semantic name remains unreviewed. */

undefined4 FUN_c0679f68(void)

{
  return 1;
}



/* c0679f74 FUN_c0679f74 */

/* Boundary evidence: original MIPS .pdata c0679f74..c067a143. Semantic name remains unreviewed. */

void FUN_c0679f74(int *param_1,int *param_2,int *param_3,int *param_4,uint param_5)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_28 [2];
  
  local_28[0] = -0x7fffffce;
  piVar2 = param_3;
  piVar3 = param_4;
  if (((param_4 == (int *)0x0) || (((int)param_4 - 1U & (uint)param_4) != 0)) ||
     (((uint)param_4 & 0x1f) == 0)) {
    iVar4 = -0x7fffffe5;
  }
  else if (((param_5 & 0xff) == 0) || (0xff < param_5)) {
    iVar4 = -0x7fffffc6;
  }
  else {
    if (param_4 == (int *)0x4) {
      if (param_3 == (int *)0x0) {
        iVar4 = -0x7fffffe8;
        goto LAB_c067a110;
      }
      piVar3 = local_28;
      iVar4 = FUN_c067f070(0x13,(int *)0x0,param_3,piVar3,(int *)0x0,(int *)0x0,0,0);
      if (iVar4 != 0) goto LAB_c067a110;
      iVar4 = *(int *)(param_3[6] + 0x18);
      piVar3 = *(int **)(param_3[6] + 0x24);
      uVar1 = 0;
    }
    else {
      if (param_1 == (int *)0x0) {
        iVar4 = -0x7fffffd5;
        goto LAB_c067a110;
      }
      piVar3 = local_28;
      piVar2 = (int *)0x0;
      iVar4 = FUN_c067f070(0x13,param_1,(int *)0x0,piVar3,(int *)0x0,(int *)0x0,0,0);
      if (iVar4 != 0) goto LAB_c067a110;
      piVar3 = (int *)0x0;
      iVar4 = *(int *)(param_1[6] + 0x14);
      uVar1 = *(undefined4 *)(param_1[6] + 0x18);
    }
    iVar4 = (**(code **)(*(int *)(iVar4 + 0x18) + 0xd8))(local_28[0]);
    if (param_4 == (int *)0x4) {
      FUN_c068179c(param_3);
      piVar2 = param_2;
    }
    else {
      FUN_c0681e1c(param_1,uVar1,param_2,piVar3);
      piVar2 = param_2;
    }
  }
LAB_c067a110:
  FUN_c067c160(iVar4,local_28[0],(int)piVar2,(int)piVar3);
  return;
}



/* c067a144 FUN_c067a144 */

/* Boundary evidence: original MIPS .pdata c067a144..c067a267. Semantic name remains unreviewed. */

undefined4 FUN_c067a144(int *param_1,int param_2,STRSAFE_PCNZWCH param_3,uint param_4)

{
  int *piVar1;
  wchar_t *hMem;
  int iVar2;
  undefined4 uVar3;
  STRSAFE_PCNZWCH pwVar4;
  uint uVar5;
  
  pwVar4 = param_3;
  uVar5 = param_4;
  piVar1 = FUN_c067c75c(param_2);
  if (piVar1 == (int *)0x0) {
    return 0x80000002;
  }
  if ((param_4 != 1) && (param_4 != 2)) {
    return 0x80000032;
  }
  hMem = FUN_c067c2ec(param_3);
  if (hMem == (wchar_t *)0x0) {
    uVar3 = 0x80000035;
  }
  else {
    if (param_1 != (int *)0x0) {
      iVar2 = FUN_c067d02c(param_1);
      uVar3 = DAT_c06861d0;
      if (iVar2 == 0) goto LAB_c067a238;
      FUN_c06825a0(param_1,param_2,pwVar4,uVar5);
    }
    iVar2 = FUN_c0683c20(hMem);
    uVar3 = 0;
    if ((param_4 & 1) == 0) {
      if (iVar2 == 0) goto LAB_c067a238;
    }
    else if (iVar2 != 0) goto LAB_c067a238;
    uVar3 = FUN_c0683c84(hMem,param_4);
  }
LAB_c067a238:
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
  return uVar3;
}



/* c067a268 FUN_c067a268 */

/* Boundary evidence: original MIPS .pdata c067a268..c067a5d3. Semantic name remains unreviewed. */

void FUN_c067a268(int *param_1,int *param_2,int ****param_3,int ***param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  int ****ppppiVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *****pppppiVar6;
  int ******ppppppiVar7;
  int *****pppppiVar8;
  int ******ppppppiVar9;
  int *****pppppiVar10;
  int ****local_48;
  int ***local_44;
  int ***local_40;
  int *****local_3c;
  int ****local_38;
  int ****local_34;
  int local_30;
  int local_2c;
  
  local_48 = (int ****)0x0;
  local_30 = 1;
  local_44 = (int ***)0x80000032;
  ppppppiVar7 = (int ******)param_3;
  pppppiVar8 = (int *****)param_4;
  if (param_6 == 0) {
LAB_c067a2e4:
    uVar2 = 0x80000035;
    iVar3 = FUN_c067c558(param_3,0);
    if ((iVar3 != 0) && (iVar3 = FUN_c067c558(param_4,0), iVar3 != 0)) {
      iVar3 = 1;
      if (param_1 == (int *)0x0) {
        if ((param_2 != (int *)0x0) && (iVar4 = FUN_c067d14c(param_2), iVar4 != 0)) {
          pppppiVar10 = (int *****)0x0;
          ppppppiVar9 = *(int *******)(param_2[6] + 0x18);
LAB_c067a3cc:
          if (param_2 != (int *)0x0) {
            ppppppiVar7 = &local_3c;
            local_2c = *(int *)(param_2[6] + 0x14);
            pppppiVar6 = &local_38;
            pppppiVar8 = (int *****)local_48;
            uVar2 = FUN_c06821dc(param_2,pppppiVar6,ppppppiVar7,local_48);
            ppppiVar1 = local_38;
            if (uVar2 == 0) {
              pppppiVar8 = (int *****)&local_44;
              local_38[0x1a] = (int ***)local_38;
              pppppiVar6 = (int *****)0x0;
              ppppppiVar7 = (int ******)local_3c;
              uVar2 = FUN_c067f070(0x14,(int *)0x0,(int *)local_3c,(int *)pppppiVar8,(int *)0x0,
                                   (int *)0x0,local_48,0);
              if (uVar2 == 0) {
                local_30 = 0;
                FUN_c068179c(local_3c);
                ppppppiVar7 = (int ******)&local_34;
                pppppiVar6 = (int *****)&local_40;
                pppppiVar8 = (int *****)local_48;
                uVar2 = FUN_c06821dc(param_2,pppppiVar6,ppppppiVar7,local_48);
                if (uVar2 == 0) {
                  local_40[0x1a] = (int **)ppppiVar1;
                  piVar5 = FUN_c0682990((int)local_44);
                  if (piVar5 != (int *)0x0) {
                    piVar5[9] = (int)local_40;
                    piVar5[10] = (int)local_34;
                    FUN_c06828c4(piVar5);
                  }
                  pppppiVar8 = (int *****)local_38;
                  uVar2 = (**(code **)(*(int *)(local_2c + 0x18) + 0xdc))(local_44);
                  if ((uVar2 & 0x80000000) == 0) {
                    FUN_c067c558(param_3,local_3c);
                    FUN_c067c558(param_4,local_34);
                    pppppiVar6 = (int *****)local_34;
                    ppppppiVar7 = ppppppiVar9;
                  }
                  else {
                    local_38[9] = (int ***)0x0;
                    local_40[9] = (int **)0x0;
                    FUN_c067d5e4(local_34);
                    pppppiVar6 = pppppiVar10;
                    ppppppiVar7 = ppppppiVar9;
                  }
                }
                else {
                  FUN_c0682aec((int)local_44);
                }
              }
              iVar3 = local_30;
              if ((uVar2 & 0x80000000) != 0) {
                FUN_c067d5e4(local_3c);
                iVar3 = local_30;
              }
            }
LAB_c067a558:
            if (param_1 != (int *)0x0) {
              FUN_c068179c(param_1);
            }
            FUN_c0681e1c(param_2,pppppiVar6,ppppppiVar7,pppppiVar8);
            if (iVar3 == 0) goto LAB_c067a59c;
            goto LAB_c067a588;
          }
        }
        uVar2 = 0x8000002b;
      }
      else {
        pppppiVar6 = (int *****)0x4;
        uVar2 = FUN_c067e31c(param_1,4);
        if (uVar2 == 0) {
          if (*(int *)(param_1[6] + 0x68) == 0) {
            param_2 = (int *)param_1[5];
            iVar4 = FUN_c067d14c(param_2);
            if (iVar4 != 0) {
              iVar4 = param_1[6];
              *(int *)(iVar4 + 0x68) = iVar4;
              pppppiVar10 = *(int ******)(param_1[6] + 0x24);
              ppppppiVar9 = (int ******)0x0;
              if (*(int *)(iVar4 + 0x60) == 0x100) goto LAB_c067a3cc;
              uVar2 = 0x80000018;
              goto LAB_c067a558;
            }
            uVar2 = 0x80000048;
          }
          else {
            uVar2 = 0x80000018;
          }
          FUN_c068179c(param_1);
        }
      }
    }
  }
  else {
    pppppiVar8 = (int *****)0x0;
    ppppppiVar7 = (int ******)&local_48;
    uVar2 = FUN_c067e1b0(param_6,0xb4,ppppppiVar7,0,param_7);
    if (uVar2 == 0) goto LAB_c067a2e4;
  }
LAB_c067a588:
  if ((int *****)local_48 != (int *****)0x0) {
    LocalFree(local_48);
  }
LAB_c067a59c:
  FUN_c067c160(uVar2,(int)local_44,(int)ppppppiVar7,(int)pppppiVar8);
  return;
}



/* c067a5d4 FUN_c067a5d4 */

/* Boundary evidence: original MIPS .pdata c067a5d4..c067a797. Semantic name remains unreviewed. */

void FUN_c067a5d4(int ***param_1,undefined4 *param_2,int param_3,int ***param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *****pppppiVar4;
  int *****pppppiVar5;
  int ****local_28;
  int ***local_24;
  int local_20;
  int ****local_1c;
  int ***local_18 [2];
  
  local_28 = (int ****)0x0;
  local_24 = (int ***)0x80000032;
  pppppiVar4 = (int *****)0x0;
  pppppiVar5 = (int *****)param_4;
  if (param_3 == 0) {
LAB_c067a62c:
    iVar2 = FUN_c067c558(param_2,0);
    if (iVar2 == 0) {
      uVar1 = 0x80000035;
    }
    else {
      pppppiVar5 = (int *****)&local_24;
      pppppiVar4 = (int *****)param_1;
      uVar1 = FUN_c067f070(0x15,(int *)0x0,(int *)param_1,(int *)pppppiVar5,(int *)0x0,&local_20,
                           local_28,0);
      if (uVar1 == 0) {
        pppppiVar4 = (int *****)local_18;
        pppppiVar5 = (int *****)local_28;
        uVar1 = FUN_c06821dc((int *)param_1[5],&local_1c,pppppiVar4,local_28);
        if (uVar1 == 0) {
          *(int *)(local_20 + 0x68) = local_20;
          piVar3 = FUN_c0682990((int)local_24);
          if (piVar3 != (int *)0x0) {
            piVar3[7] = (int)local_1c;
            piVar3[8] = (int)local_18[0];
            piVar3[9] = local_20;
            piVar3[10] = (int)param_1;
            FUN_c06828c4(piVar3);
          }
          pppppiVar5 = (int *****)(local_1c + 9);
          pppppiVar4 = (int *****)local_1c;
          uVar1 = (**(code **)(*(int *)(*(int *)(local_20 + 0x18) + 0x18) + 0xe0))
                            (local_24,*(undefined4 *)(local_20 + 0x24),local_1c,pppppiVar5,local_28)
          ;
          if ((uVar1 & 0x80000000) == 0) {
            FUN_c067c558(param_2,local_18[0]);
          }
          else {
            local_1c[9] = (int ***)0x0;
            FUN_c067d5e4(local_18[0]);
          }
        }
        else {
          FUN_c0682aec((int)local_24);
        }
        FUN_c068179c(param_1);
        goto LAB_c067a65c;
      }
    }
  }
  else {
    pppppiVar5 = (int *****)0x0;
    pppppiVar4 = &local_28;
    uVar1 = FUN_c067e1b0(param_3,0xb4,pppppiVar4,0,(int)param_4);
    if (uVar1 == 0) goto LAB_c067a62c;
  }
  if ((int *****)local_28 != (int *****)0x0) {
    LocalFree(local_28);
  }
LAB_c067a65c:
  FUN_c067c160(uVar1,(int)local_24,(int)pppppiVar4,(int)pppppiVar5);
  return;
}



/* c067a798 FUN_c067a798 */

/* Boundary evidence: original MIPS .pdata c067a798..c067a90b. Semantic name remains unreviewed. */

int FUN_c067a798(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  FUN_c067bc18();
  iVar1 = FUN_c067d02c(param_1);
  iVar3 = DAT_c06861d0;
  if (iVar1 != 0) {
    *param_1 = 0;
    if (param_1[8] != 0) {
      param_1[9] = param_1[8];
      param_1[8] = 0;
    }
    for (iVar3 = param_1[0xf]; iVar3 != 0; iVar3 = iVar3 + -1) {
      param_2 = 3;
      EventModify(param_1[9]);
    }
    piVar2 = param_1 + 1;
    *(int *)param_1[2] = *piVar2;
    *(int *)(*piVar2 + 4) = param_1[2];
    param_1[2] = (int)piVar2;
    *piVar2 = (int)piVar2;
    iVar3 = 0;
  }
  FUN_c067bc40();
  if (iVar3 == 0) {
    FUN_c06825a0(param_1,param_2,param_3,param_4);
    uVar4 = 0;
    do {
      if ((uint)param_1[0xf] < 2) break;
      Sleep(100);
      uVar4 = uVar4 + 100;
    } while (uVar4 < 10000);
    FUN_c06825a0(param_1,param_2,param_3,param_4);
  }
  return iVar3;
}



/* c067a90c FUN_c067a90c */

/* Boundary evidence: original MIPS .pdata c067a90c..c067a917. Semantic name remains unreviewed. */

undefined4 FUN_c067a90c(void)

{
  return 1;
}



/* c067a918 FUN_c067a918 */

/* Boundary evidence: original MIPS .pdata c067a918..c067aa0f. Semantic name remains unreviewed. */

void FUN_c067a918(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20;
  int local_1c;
  
  local_20 = -0x7fffffce;
  iVar1 = FUN_c067e31c(param_2,4);
  if (iVar1 == 0) {
    param_4 = &local_20;
    iVar3 = param_2[6];
    param_3 = param_1;
    iVar1 = FUN_c067f070(0x16,(int *)0x0,param_1,param_4,(int *)0x0,&local_1c,0,0);
    if (iVar1 == 0) {
      piVar2 = FUN_c0682990(local_20);
      if (piVar2 != (int *)0x0) {
        piVar2[9] = iVar3;
        piVar2[10] = (int)param_2;
        FUN_c06828c4(piVar2);
      }
      param_3 = *(int **)(iVar3 + 0x24);
      iVar1 = (**(code **)(*(int *)(*(int *)(local_1c + 0x18) + 0x18) + 0xe4))
                        (local_20,*(undefined4 *)(local_1c + 0x24));
      FUN_c068179c(param_1);
    }
    FUN_c068179c(param_2);
  }
  FUN_c067c160(iVar1,local_20,(int)param_3,(int)param_4);
  return;
}



/* c067aa10 FUN_c067aa10 */

/* Boundary evidence: original MIPS .pdata c067aa10..c067abdb. Semantic name remains unreviewed. */

int FUN_c067aa10(int *param_1,int param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                undefined4 param_5,uint param_6,int param_7,int param_8)

{
  int iVar1;
  wchar_t *hMem;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  STRSAFE_PCNZWCH pwVar5;
  int iVar6;
  uint *local_30 [2];
  
  local_30[0] = (uint *)0x0;
  if (param_1 != (int *)0x0) {
    iVar3 = param_2;
    uVar4 = param_3;
    pwVar5 = param_4;
    iVar1 = FUN_c067d02c(param_1);
    iVar6 = DAT_c06861d0;
    if (iVar1 == 0) goto LAB_c067ab9c;
    FUN_c06825a0(param_1,iVar3,uVar4,pwVar5);
  }
  hMem = FUN_c067c2ec(param_4);
  if (hMem == (wchar_t *)0x0) {
    iVar6 = -0x7fffffcb;
  }
  else {
    iVar6 = FUN_c067e1b0(param_7,0x28,local_30,1,param_8);
    if (iVar6 == 0) {
      piVar2 = FUN_c067c75c(param_2);
      if (piVar2 == (int *)0x0) {
        iVar6 = -0x7ffffffe;
      }
      else if ((param_6 & 0xc) == 0xc) {
        iVar6 = -0x7fffffce;
      }
      else {
        iVar6 = 0;
        if (((0x2000f < (uint)piVar2[0xb]) &&
            (iVar6 = (**(code **)(*(int *)(piVar2[5] + 0x18) + 0x188))
                               (param_2,hMem,param_6,local_30[0]), iVar6 == -0x7fffffb7)) ||
           ((uint)piVar2[0xb] < 0x20010)) {
          iVar6 = FUN_c0684484(param_2,param_3,hMem,param_5,param_6,local_30[0]);
        }
      }
    }
  }
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
LAB_c067ab9c:
  FUN_c067e2f4(param_7,local_30[0],param_8);
  return iVar6;
}



/* c067abdc FUN_c067abdc */

/* Boundary evidence: original MIPS .pdata c067abdc..c067ae63. Semantic name remains unreviewed. */

int FUN_c067abdc(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                STRSAFE_PCNZWCH param_5)

{
  int iVar1;
  HLOCAL hMem;
  LONG LVar2;
  HMODULE pHVar3;
  code *pcVar4;
  int iVar5;
  wchar_t *pwVar6;
  int iVar7;
  
  iVar7 = param_4;
  iVar1 = FUN_c067c458(param_4);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_c067d02c(param_1);
  if (iVar1 == 0) {
    return DAT_c06861d0;
  }
  if (param_5 != (STRSAFE_PCNZWCH)0x0) {
    hMem = FUN_c067c2ec(param_5);
    if (hMem == (HLOCAL)0x0) {
      return -0x7fffffcb;
    }
    LocalFree(hMem);
  }
  pwVar6 = (wchar_t *)0x1;
  LVar2 = InterlockedExchange(&DAT_c06861e4,1);
  if (LVar2 != 0) {
    if ((DAT_c06861e8 != 0) && (pHVar3 = LoadLibraryW(L"COREDLL.DLL"), pHVar3 != (HMODULE)0x0)) {
      pwVar6 = L"SetForegroundWindow";
      pcVar4 = (code *)GetProcAddressW(pHVar3);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(DAT_c06861e8 | 1);
      }
      FreeLibrary(pHVar3);
    }
    iVar1 = -0x7ffffff1;
    goto LAB_c067ae24;
  }
  pHVar3 = LoadLibraryW(L"COREDLL.DLL");
  if (pHVar3 == (HMODULE)0x0) {
LAB_c067adf0:
    iVar1 = -0x7fffffb8;
  }
  else {
    iVar1 = GetProcAddressW(pHVar3,L"EnableWindow");
    pwVar6 = L"SetForegroundWindow";
    iVar5 = GetProcAddressW(pHVar3);
    if ((iVar1 == 0) || (iVar5 == 0)) goto LAB_c067adf0;
    iVar1 = 0;
    pwVar6 = (wchar_t *)&DAT_c06861e8;
    iVar5 = FUN_c06743a8(param_4,&DAT_c06861e8);
    if (iVar5 == 0) {
      iVar1 = -0x7fffffb8;
    }
  }
  DAT_c06861e4 = 0;
  DAT_c06861e8 = 0;
  if (pHVar3 != (HMODULE)0x0) {
    FreeLibrary(pHVar3);
  }
LAB_c067ae24:
  FUN_c06825a0(param_1,pwVar6,param_3,iVar7);
  return iVar1;
}



/* c067ae64 FUN_c067ae64 */

/* Boundary evidence: original MIPS .pdata c067ae64..c067ae6f. Semantic name remains unreviewed. */

undefined4 FUN_c067ae64(void)

{
  return 1;
}



/* c067ae70 FUN_c067ae70 */

/* Boundary evidence: original MIPS .pdata c067ae70..c067af0b. Semantic name remains unreviewed. */

void FUN_c067ae70(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_18;
  int local_14;
  
  piVar3 = &local_18;
  local_18 = -0x7fffffce;
  piVar2 = param_1;
  iVar1 = FUN_c067f070(0x17,(int *)0x0,param_1,piVar3,(int *)0x0,&local_14,0,0);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)(local_14 + 0x18) + 0x18) + 0xec))
                      (local_18,*(undefined4 *)(local_14 + 0x24));
    FUN_c068179c(param_1);
  }
  FUN_c067c160(iVar1,local_18,(int)piVar2,(int)piVar3);
  return;
}



/* c067af0c FUN_c067af0c */

/* Boundary evidence: original MIPS .pdata c067af0c..c067af2b. Semantic name remains unreviewed. */

void FUN_c067af0c(HLOCAL *param_1,int *param_2,HLOCAL *param_3,int *param_4)

{
  FUN_c067512c(param_1,param_2,param_3,param_4,1);
  return;
}



/* c067af2c FUN_c067af2c */

/* Boundary evidence: original MIPS .pdata c067af2c..c067af5b. Semantic name remains unreviewed. */

void FUN_c067af2c(int param_1,int param_2,STRSAFE_PCNZWCH param_3,int param_4,uint param_5,
                 int param_6)

{
  FUN_c067541c(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* c067af5c FUN_c067af5c */

/* Boundary evidence: original MIPS .pdata c067af5c..c067af93. Semantic name remains unreviewed. */

void FUN_c067af5c(int ****param_1,int ****param_2,int ****param_3,int ****param_4,undefined4 param_5
                 ,undefined4 *param_6,int param_7)

{
  FUN_c06759d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  return;
}



/* c067af94 FUN_c067af94 */

/* Boundary evidence: original MIPS .pdata c067af94..c067afbb. Semantic name remains unreviewed. */

void FUN_c067af94(int *param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  FUN_c0675d68(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c067afbc FUN_c067afbc */

/* Boundary evidence: original MIPS .pdata c067afbc..c067afeb. Semantic name remains unreviewed. */

void FUN_c067afbc(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5,int param_6)

{
  FUN_c0675f7c(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* c067afec FUN_c067afec */

/* Boundary evidence: original MIPS .pdata c067afec..c067b013. Semantic name remains unreviewed. */

void FUN_c067afec(int *param_1,undefined4 *param_2,int param_3,int param_4,uint param_5)

{
  FUN_c06760f0(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c067b014 FUN_c067b014 */

/* Boundary evidence: original MIPS .pdata c067b014..c067b02f. Semantic name remains unreviewed. */

void FUN_c067b014(int *param_1,undefined4 param_2,int param_3)

{
  FUN_c06761f0(param_1,param_2,param_3,1);
  return;
}



/* c067b030 FUN_c067b030 */

/* Boundary evidence: original MIPS .pdata c067b030..c067b04b. Semantic name remains unreviewed. */

void FUN_c067b030(int *param_1,int param_2)

{
  FUN_c06763a8(param_1,param_2,1);
  return;
}



/* c067b04c FUN_c067b04c */

/* Boundary evidence: original MIPS .pdata c067b04c..c067b067. Semantic name remains unreviewed. */

void FUN_c067b04c(int *param_1,int param_2)

{
  FUN_c0676580(param_1,param_2,1);
  return;
}



/* c067b068 FUN_c067b068 */

/* Boundary evidence: original MIPS .pdata c067b068..c067b083. Semantic name remains unreviewed. */

void FUN_c067b068(int *param_1,int param_2)

{
  FUN_c0676648(param_1,param_2,1);
  return;
}



/* c067b084 FUN_c067b084 */

/* Boundary evidence: original MIPS .pdata c067b084..c067b0ab. Semantic name remains unreviewed. */

void FUN_c067b084(int *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  FUN_c06769c8(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c067b0ac FUN_c067b0ac */

/* Boundary evidence: original MIPS .pdata c067b0ac..c067b0c7. Semantic name remains unreviewed. */

void FUN_c067b0ac(int param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  FUN_c0676b7c(param_1,param_2,param_3,1);
  return;
}



/* c067b0c8 FUN_c067b0c8 */

/* Boundary evidence: original MIPS .pdata c067b0c8..c067b0f7. Semantic name remains unreviewed. */

void FUN_c067b0c8(int *param_1,undefined4 param_2,int *param_3,uint param_4,int param_5,
                 STRSAFE_PCNZWCH param_6)

{
  FUN_c0676d30(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* c067b0f8 FUN_c067b0f8 */

/* Boundary evidence: original MIPS .pdata c067b0f8..c067b113. Semantic name remains unreviewed. */

void FUN_c067b0f8(int *param_1,int param_2)

{
  FUN_c0676f0c(param_1,param_2,1);
  return;
}



/* c067b114 FUN_c067b114 */

/* Boundary evidence: original MIPS .pdata c067b114..c067b12f. Semantic name remains unreviewed. */

void FUN_c067b114(int *param_1,int param_2,HLOCAL param_3)

{
  FUN_c0676ffc(param_1,param_2,param_3,1);
  return;
}



/* c067b130 FUN_c067b130 */

/* Boundary evidence: original MIPS .pdata c067b130..c067b14f. Semantic name remains unreviewed. */

void FUN_c067b130(int **param_1,int **param_2,int **param_3,int param_4)

{
  FUN_c067724c(param_1,param_2,param_3,param_4,1);
  return;
}



/* c067b150 FUN_c067b150 */

/* Boundary evidence: original MIPS .pdata c067b150..c067b16b. Semantic name remains unreviewed. */

void FUN_c067b150(undefined4 param_1,int param_2)

{
  FUN_c0677724(param_1,param_2,1);
  return;
}



/* c067b16c FUN_c067b16c */

/* Boundary evidence: original MIPS .pdata c067b16c..c067b187. Semantic name remains unreviewed. */

void FUN_c067b16c(int *param_1,undefined4 param_2,int param_3)

{
  FUN_c0677a98(param_1,param_2,param_3,1);
  return;
}



/* c067b188 FUN_c067b188 */

/* Boundary evidence: original MIPS .pdata c067b188..c067b1bf. Semantic name remains unreviewed. */

void FUN_c067b188(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 *param_5,undefined4 *param_6,int param_7)

{
  FUN_c06782fc(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  return;
}



/* c067b1c0 FUN_c067b1c0 */

/* Boundary evidence: original MIPS .pdata c067b1c0..c067b1e7. Semantic name remains unreviewed. */

void FUN_c067b1c0(STRSAFE_PCNZWCH *****param_1,undefined4 *param_2,STRSAFE_PCNZWCH *****param_3,
                 STRSAFE_PCNZWCH *****param_4,int param_5)

{
  FUN_c06784cc(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



/* c067b1e8 FUN_c067b1e8 */

/* Boundary evidence: original MIPS .pdata c067b1e8..c067b217. Semantic name remains unreviewed. */

void FUN_c067b1e8(int *param_1,uint param_2,void *param_3,void *param_4,undefined4 *param_5,
                 int param_6)

{
  FUN_c0678a1c(param_1,param_2,param_3,param_4,param_5,param_6,(void *)0x1);
  return;
}



/* c067b218 FUN_c067b218 */

/* Boundary evidence: original MIPS .pdata c067b218..c067b233. Semantic name remains unreviewed. */

void FUN_c067b218(int ***param_1,undefined4 *param_2,int param_3)

{
  FUN_c067900c(param_1,param_2,param_3,(int ***)0x1);
  return;
}



/* c067b234 FUN_c067b234 */

/* Boundary evidence: original MIPS .pdata c067b234..c067b25b. Semantic name remains unreviewed. */

void FUN_c067b234(int *param_1,int *param_2,int *param_3,int *param_4,int param_5)

{
  FUN_c0679660(param_1,param_2,param_3,param_4,param_5,(int *)0x1);
  return;
}



/* c067b25c FUN_c067b25c */

/* Boundary evidence: original MIPS .pdata c067b25c..c067b28b. Semantic name remains unreviewed. */

void FUN_c067b25c(int *param_1,int *param_2,int ****param_3,int ***param_4,undefined4 param_5,
                 int param_6)

{
  FUN_c067a268(param_1,param_2,param_3,param_4,param_5,param_6,1);
  return;
}



/* c067b28c FUN_c067b28c */

/* Boundary evidence: original MIPS .pdata c067b28c..c067b2a7. Semantic name remains unreviewed. */

void FUN_c067b28c(int ***param_1,undefined4 *param_2,int param_3)

{
  FUN_c067a5d4(param_1,param_2,param_3,(int ***)0x1);
  return;
}



/* c067b2a8 FUN_c067b2a8 */

/* Boundary evidence: original MIPS .pdata c067b2a8..c067b2df. Semantic name remains unreviewed. */

void FUN_c067b2a8(int *param_1,int param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 param_5,uint param_6,int param_7)

{
  FUN_c067aa10(param_1,param_2,param_3,param_4,param_5,param_6,param_7,1);
  return;
}



/* c067b2e0 FUN_c067b2e0 */

/* Boundary evidence: original MIPS .pdata c067b2e0..c067b2fb. Semantic name remains unreviewed. */

void FUN_c067b2e0(HLOCAL *param_1,int *param_2,HLOCAL *param_3,int *param_4)

{
  FUN_c067512c(param_1,param_2,param_3,param_4,0);
  return;
}



/* c067b2fc FUN_c067b2fc */

/* Boundary evidence: original MIPS .pdata c067b2fc..c067b327. Semantic name remains unreviewed. */

void FUN_c067b2fc(int param_1,int param_2,STRSAFE_PCNZWCH param_3,int param_4,uint param_5,
                 int param_6)

{
  FUN_c067541c(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* c067b328 FUN_c067b328 */

/* Boundary evidence: original MIPS .pdata c067b328..c067b35b. Semantic name remains unreviewed. */

void FUN_c067b328(int ****param_1,int ****param_2,int ****param_3,int ****param_4,undefined4 param_5
                 ,undefined4 *param_6,int param_7)

{
  FUN_c06759d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c067b35c FUN_c067b35c */

/* Boundary evidence: original MIPS .pdata c067b35c..c067b37f. Semantic name remains unreviewed. */

void FUN_c067b35c(int *param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  FUN_c0675d68(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c067b380 FUN_c067b380 */

/* Boundary evidence: original MIPS .pdata c067b380..c067b3ab. Semantic name remains unreviewed. */

void FUN_c067b380(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5,int param_6)

{
  FUN_c0675f7c(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* c067b3ac FUN_c067b3ac */

/* Boundary evidence: original MIPS .pdata c067b3ac..c067b3cf. Semantic name remains unreviewed. */

void FUN_c067b3ac(int *param_1,undefined4 *param_2,int param_3,int param_4,uint param_5)

{
  FUN_c06760f0(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c067b3d0 FUN_c067b3d0 */

/* Boundary evidence: original MIPS .pdata c067b3d0..c067b3eb. Semantic name remains unreviewed. */

void FUN_c067b3d0(int *param_1,undefined4 param_2,int param_3)

{
  FUN_c06761f0(param_1,param_2,param_3,0);
  return;
}



/* c067b3ec FUN_c067b3ec */

/* Boundary evidence: original MIPS .pdata c067b3ec..c067b407. Semantic name remains unreviewed. */

void FUN_c067b3ec(int *param_1,int param_2)

{
  FUN_c06763a8(param_1,param_2,0);
  return;
}



/* c067b408 FUN_c067b408 */

/* Boundary evidence: original MIPS .pdata c067b408..c067b423. Semantic name remains unreviewed. */

void FUN_c067b408(int *param_1,int param_2)

{
  FUN_c0676580(param_1,param_2,0);
  return;
}



/* c067b424 FUN_c067b424 */

/* Boundary evidence: original MIPS .pdata c067b424..c067b43f. Semantic name remains unreviewed. */

void FUN_c067b424(int *param_1,int param_2)

{
  FUN_c0676648(param_1,param_2,0);
  return;
}



/* c067b440 FUN_c067b440 */

/* Boundary evidence: original MIPS .pdata c067b440..c067b463. Semantic name remains unreviewed. */

void FUN_c067b440(int *param_1,int param_2,uint param_3,int param_4,int param_5)

{
  FUN_c06769c8(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c067b464 FUN_c067b464 */

/* Boundary evidence: original MIPS .pdata c067b464..c067b47f. Semantic name remains unreviewed. */

void FUN_c067b464(int param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  FUN_c0676b7c(param_1,param_2,param_3,0);
  return;
}



/* c067b480 FUN_c067b480 */

/* Boundary evidence: original MIPS .pdata c067b480..c067b4ab. Semantic name remains unreviewed. */

void FUN_c067b480(int *param_1,undefined4 param_2,int *param_3,uint param_4,int param_5,
                 STRSAFE_PCNZWCH param_6)

{
  FUN_c0676d30(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* c067b4ac FUN_c067b4ac */

/* Boundary evidence: original MIPS .pdata c067b4ac..c067b4c7. Semantic name remains unreviewed. */

void FUN_c067b4ac(int *param_1,int param_2)

{
  FUN_c0676f0c(param_1,param_2,0);
  return;
}



/* c067b4c8 FUN_c067b4c8 */

/* Boundary evidence: original MIPS .pdata c067b4c8..c067b4e3. Semantic name remains unreviewed. */

void FUN_c067b4c8(int *param_1,int param_2,HLOCAL param_3)

{
  FUN_c0676ffc(param_1,param_2,param_3,0);
  return;
}



/* c067b4e4 FUN_c067b4e4 */

/* Boundary evidence: original MIPS .pdata c067b4e4..c067b4ff. Semantic name remains unreviewed. */

void FUN_c067b4e4(int **param_1,int **param_2,int **param_3,int param_4)

{
  FUN_c067724c(param_1,param_2,param_3,param_4,0);
  return;
}



/* c067b500 FUN_c067b500 */

/* Boundary evidence: original MIPS .pdata c067b500..c067b51b. Semantic name remains unreviewed. */

void FUN_c067b500(undefined4 param_1,int param_2)

{
  FUN_c0677724(param_1,param_2,0);
  return;
}



/* c067b51c FUN_c067b51c */

/* Boundary evidence: original MIPS .pdata c067b51c..c067b537. Semantic name remains unreviewed. */

void FUN_c067b51c(int *param_1,undefined4 param_2,int param_3)

{
  FUN_c0677a98(param_1,param_2,param_3,0);
  return;
}



/* c067b538 FUN_c067b538 */

/* Boundary evidence: original MIPS .pdata c067b538..c067b56b. Semantic name remains unreviewed. */

void FUN_c067b538(undefined4 *param_1,undefined4 param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 *param_5,undefined4 *param_6,int param_7)

{
  FUN_c06782fc(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c067b56c FUN_c067b56c */

/* Boundary evidence: original MIPS .pdata c067b56c..c067b58f. Semantic name remains unreviewed. */

void FUN_c067b56c(STRSAFE_PCNZWCH *****param_1,undefined4 *param_2,STRSAFE_PCNZWCH *****param_3,
                 STRSAFE_PCNZWCH *****param_4,int param_5)

{
  FUN_c06784cc(param_1,param_2,param_3,param_4,param_5,0);
  return;
}



/* c067b590 FUN_c067b590 */

/* Boundary evidence: original MIPS .pdata c067b590..c067b5bb. Semantic name remains unreviewed. */

void FUN_c067b590(int *param_1,uint param_2,void *param_3,void *param_4,undefined4 *param_5,
                 int param_6)

{
  FUN_c0678a1c(param_1,param_2,param_3,param_4,param_5,param_6,(void *)0x0);
  return;
}



/* c067b5bc FUN_c067b5bc */

/* Boundary evidence: original MIPS .pdata c067b5bc..c067b5d7. Semantic name remains unreviewed. */

void FUN_c067b5bc(int ***param_1,undefined4 *param_2,int param_3)

{
  FUN_c067900c(param_1,param_2,param_3,(int ***)0x0);
  return;
}



/* c067b5d8 FUN_c067b5d8 */

/* Boundary evidence: original MIPS .pdata c067b5d8..c067b5fb. Semantic name remains unreviewed. */

void FUN_c067b5d8(int *param_1,int *param_2,int *param_3,int *param_4,int param_5)

{
  FUN_c0679660(param_1,param_2,param_3,param_4,param_5,(int *)0x0);
  return;
}



/* c067b5fc FUN_c067b5fc */

/* Boundary evidence: original MIPS .pdata c067b5fc..c067b627. Semantic name remains unreviewed. */

void FUN_c067b5fc(int *param_1,int *param_2,int ****param_3,int ***param_4,undefined4 param_5,
                 int param_6)

{
  FUN_c067a268(param_1,param_2,param_3,param_4,param_5,param_6,0);
  return;
}



/* c067b628 FUN_c067b628 */

/* Boundary evidence: original MIPS .pdata c067b628..c067b643. Semantic name remains unreviewed. */

void FUN_c067b628(int ***param_1,undefined4 *param_2,int param_3)

{
  FUN_c067a5d4(param_1,param_2,param_3,(int ***)0x0);
  return;
}



/* c067b644 FUN_c067b644 */

/* Boundary evidence: original MIPS .pdata c067b644..c067b677. Semantic name remains unreviewed. */

void FUN_c067b644(int *param_1,int param_2,undefined4 param_3,STRSAFE_PCNZWCH param_4,
                 undefined4 param_5,uint param_6,int param_7)

{
  FUN_c067aa10(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c067b678 FUN_c067b678 */

/* Boundary evidence: original MIPS .pdata c067b678..c067bb2b. Semantic name remains unreviewed. */

int FUN_c067b678(int *param_1,int *param_2,uint **param_3,uint **param_4,uint **param_5,
                undefined4 param_6,uint param_7,uint param_8,int param_9,int param_10)

{
  int iVar1;
  uint **ppuVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint **ppuVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *local_40;
  uint *local_3c;
  uint **local_38;
  int local_34;
  int local_30;
  uint **local_2c;
  
  iVar10 = 0;
  local_34 = 0;
  local_3c = (uint *)0x0;
  if (DAT_c0686148 != 0) {
    return -0x7fffffae;
  }
  iVar7 = -0x7fffffcb;
  ppuVar2 = param_3;
  ppuVar5 = param_4;
  local_38 = param_4;
  local_2c = param_3;
  if (param_9 != 0) {
    ppuVar5 = (uint **)0x0;
    ppuVar2 = &local_3c;
    iVar7 = FUN_c067e1b0(param_9,0xb4,ppuVar2,0,param_10);
    if (iVar7 != 0) goto LAB_c067bae8;
  }
  piVar4 = (int *)0x0;
  iVar1 = FUN_c067c558(param_3,0);
  if (iVar1 == 0) goto LAB_c067bae8;
  uVar6 = param_7 & 0x7fffffff;
  if ((uVar6 == 0) || (((2 < uVar6 && (uVar6 != 4)) && (uVar6 != 6)))) {
    iVar7 = -0x7fffffca;
    goto LAB_c067bae8;
  }
  if ((param_7 & 0x80000000) != 0) {
    if (local_3c == (uint *)0x0) {
      return -0x7fffffef;
    }
    if ((local_3c[6] & 1) == 0) {
      iVar7 = -0x7fffffef;
      goto LAB_c067bae8;
    }
  }
  if (((param_7 & 4) != 0) && ((param_8 == 0 || ((param_8 & 0xfe4001) != 0)))) {
    iVar7 = -0x7fffffd1;
    goto LAB_c067bae8;
  }
  iVar1 = FUN_c067d02c(param_1);
  iVar7 = DAT_c06861d0;
  if (iVar1 == 0) goto LAB_c067bae8;
  if (param_2 == (int *)0xffffffff) {
    piVar9 = (int *)0x0;
    param_2 = piVar4;
    param_4 = ppuVar2;
    if (DAT_c06861c4 != (int *)0x0) {
      do {
        param_2 = piVar9;
        param_4 = local_38;
        ppuVar5 = param_5;
        iVar7 = FUN_c0674450(param_1,(int)piVar9,(uint)local_38,(int)param_5,param_6,param_7,param_8
                             ,local_3c,1,&local_40);
        if (iVar7 == 0) {
          iVar10 = 1;
          break;
        }
        if ((piVar9 == (int *)0x0) &&
           (((iVar7 == -0x7ffffffe || (iVar7 == -0x7fffffcb)) || (iVar7 + 0x7fffffcbU < 2))))
        goto LAB_c067bad0;
        piVar9 = (int *)((int)piVar9 + 1);
        iVar10 = local_34;
      } while (piVar9 < DAT_c06861c4);
      param_5 = ppuVar5;
      if (piVar9 < DAT_c06861c4) goto LAB_c067b910;
    }
    param_5 = ppuVar5;
    iVar7 = -0x7fffffc0;
LAB_c067b910:
    uVar6 = 1;
    if (iVar7 == 0) {
      if (param_8 != 0) {
        do {
          uVar8 = uVar6 & param_8;
          if (uVar8 != 0) {
            param_5 = (uint **)0x0;
            param_4 = (uint **)0x0;
            iVar7 = FUN_c06762c0((STRSAFE_PCNZWCH)(param_1 + 0x11),uVar8,0,0,0,&local_30);
            if ((((iVar7 == 0) && (local_30 == 0)) && (iVar7 = FUN_c067ca84(uVar8), iVar7 != -1)) &&
               (ppuVar2 = FUN_c067c2ec((STRSAFE_PCNZWCH)(param_1 + 0x11)), ppuVar2 != (uint **)0x0))
            {
              param_4 = ppuVar2;
              puVar3 = FUN_c067c5ac(0,(undefined4 *)0x0,(wchar_t *)ppuVar2);
              if (puVar3 != (undefined4 *)0x0) {
                param_4 = (uint **)0x1;
                FUN_c06745f8(puVar3,iVar7,1);
                FUN_c06825a0(puVar3,iVar7,param_4,param_5);
              }
              LocalFree(ppuVar2);
            }
          }
          uVar6 = uVar6 << 1;
        } while (uVar6 != 0);
        iVar7 = FUN_c067ca84(2);
        param_2 = (int *)0x1;
        piVar4 = FUN_c067e788(iVar7,'\x01');
        if (piVar4 == (int *)0x0) {
          piVar4 = (int *)FUN_c067ca84(2);
          if ((piVar4 != (int *)0xffffffff) &&
             (ppuVar2 = FUN_c067c2ec((STRSAFE_PCNZWCH)(param_1 + 0x11)), ppuVar2 != (uint **)0x0)) {
            param_2 = (int *)0x0;
            param_4 = ppuVar2;
            puVar3 = FUN_c067c5ac(0,(undefined4 *)0x0,(wchar_t *)ppuVar2);
            if (puVar3 != (undefined4 *)0x0) {
              param_4 = (uint **)0x1;
              FUN_c06745f8(puVar3,(int)piVar4,1);
              FUN_c06825a0(puVar3,piVar4,param_4,param_5);
              param_2 = piVar4;
            }
            LocalFree(ppuVar2);
          }
        }
        else {
          FUN_c06825a0(piVar4,param_2,param_4,param_5);
        }
        iVar7 = FUN_c067d440(local_40[6],param_2,param_4,param_5);
        if (iVar7 != 0) goto LAB_c067bab8;
      }
      FUN_c067c558(local_2c,local_40);
      param_5 = (uint **)0x200;
      local_40[0xf] = 0;
      param_4 = (uint **)0x8;
      param_2 = local_40;
      FUN_c067eb1c(local_40[6],local_40,8,0x200,0,0);
    }
LAB_c067bab8:
    ppuVar5 = param_5;
    if ((iVar10 != 0) && (iVar7 != 0)) {
      FUN_c0681e1c(local_40,param_2,param_4,param_5);
      ppuVar5 = param_5;
    }
  }
  else {
    iVar7 = FUN_c0674450(param_1,(int)param_2,(uint)param_4,(int)param_5,param_6,param_7,param_8,
                         local_3c,0,&local_40);
    ppuVar5 = param_5;
    if (iVar7 == 0) {
      iVar10 = 1;
      goto LAB_c067b910;
    }
  }
LAB_c067bad0:
  FUN_c06825a0(param_1,param_2,param_4,ppuVar5);
LAB_c067bae8:
  if (local_3c != (uint *)0x0) {
    LocalFree(local_3c);
  }
  return iVar7;
}



/* c067bb2c FUN_c067bb2c */

/* Boundary evidence: original MIPS .pdata c067bb2c..c067bb73. Semantic name remains unreviewed. */

void FUN_c067bb2c(int *param_1,int *param_2,uint **param_3,uint **param_4,uint **param_5,
                 undefined4 param_6,uint param_7,uint param_8,int param_9)

{
  FUN_c067b678(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,1);
  return;
}



/* c067bb74 FUN_c067bb74 */

/* Boundary evidence: original MIPS .pdata c067bb74..c067bbb7. Semantic name remains unreviewed. */

void FUN_c067bb74(int *param_1,int *param_2,uint **param_3,uint **param_4,uint **param_5,
                 undefined4 param_6,uint param_7,uint param_8,int param_9)

{
  FUN_c067b678(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,0);
  return;
}



/* c067bbb8 FUN_c067bbb8 */

/* Boundary evidence: original MIPS .pdata c067bbb8..c067bc17. Semantic name remains unreviewed. */

void FUN_c067bbb8(int *param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
  EnterCriticalSection(param_3);
  *param_2 = *param_1;
  param_2[1] = (int)param_1;
  *(int **)(*param_1 + 4) = param_2;
  *param_1 = (int)param_2;
  LeaveCriticalSection(param_3);
  return;
}



/* c067bc18 FUN_c067bc18 */

/* Boundary evidence: original MIPS .pdata c067bc18..c067bc3f. Semantic name remains unreviewed. */

undefined4 FUN_c067bc18(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return 1;
}



/* c067bc40 FUN_c067bc40 */

/* Boundary evidence: original MIPS .pdata c067bc40..c067bc67. Semantic name remains unreviewed. */

undefined4 FUN_c067bc40(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return 0;
}



/* c067bc68 FUN_c067bc68 */

/* Boundary evidence: original MIPS .pdata c067bc68..c067bd27. Semantic name remains unreviewed. */

void * FUN_c067bc68(int param_1,uint param_2,int *param_3,uint *param_4,int *param_5,size_t *param_6
                   ,void *param_7,size_t param_8)

{
  uint uVar1;
  void *_Dst;
  
  uVar1 = *param_4 + param_8;
  _Dst = (void *)0x0;
  if ((uVar1 < *param_4) || (param_2 < uVar1)) {
    *param_6 = 0;
    *param_5 = 0;
  }
  else {
    *param_6 = param_8;
    *param_5 = *param_3;
    _Dst = (void *)(*param_3 + param_1);
    if (param_7 != (void *)0x0) {
      memcpy(_Dst,param_7,param_8);
    }
    *param_3 = *param_3 + param_8;
  }
  *param_4 = *param_4 + param_8;
  return _Dst;
}



/* c067bd28 FUN_c067bd28 */

/* Boundary evidence: original MIPS .pdata c067bd28..c067be13. Semantic name remains unreviewed. */

int * FUN_c067bd28(void)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  piVar1 = (int *)0x0;
  if ((int **)DAT_c06861b0 != &DAT_c06861b0) {
    *(int ***)(*DAT_c06861b0 + 4) = &DAT_c06861b0;
    DAT_c06861b8 = DAT_c06861b8 + -1;
    piVar1 = DAT_c06861b0;
    DAT_c06861b0 = (int *)*DAT_c06861b0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if ((piVar1 == (int *)0x0) && (piVar1 = LocalAlloc(0x40,0x20), piVar1 != (int *)0x0)) {
    DAT_c0686204 = DAT_c0686204 + 1;
  }
  return piVar1;
}



/* c067be14 FUN_c067be14 */

/* Boundary evidence: original MIPS .pdata c067be14..c067be1f. Semantic name remains unreviewed. */

undefined4 FUN_c067be14(void)

{
  return 1;
}



/* c067be20 FUN_c067be20 */

/* Boundary evidence: original MIPS .pdata c067be20..c067bef7. Semantic name remains unreviewed. */

void FUN_c067be20(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if (DAT_c06861b8 < 0x10) {
    *param_1 = &DAT_c06861b0;
    param_1[1] = DAT_c06861b4;
    *DAT_c06861b4 = param_1;
    DAT_c06861b8 = DAT_c06861b8 + 1;
    DAT_c06861b4 = param_1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  }
  else {
    DAT_c0686204 = DAT_c0686204 + -1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    LocalFree(param_1);
  }
  return;
}



/* c067bef8 FUN_c067bef8 */

/* Boundary evidence: original MIPS .pdata c067bef8..c067bf03. Semantic name remains unreviewed. */

undefined4 FUN_c067bef8(void)

{
  return 1;
}



/* c067bf04 FUN_c067bf04 */

/* Boundary evidence: original MIPS .pdata c067bf04..c067c013. Semantic name remains unreviewed. */

undefined4
FUN_c067bf04(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c067bd28();
  if (piVar1 == (int *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    piVar1[2] = param_2;
    piVar1[3] = param_3;
    piVar1[4] = param_4;
    piVar1[5] = param_5;
    piVar1[6] = param_6;
    piVar1[7] = param_7;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    *piVar1 = param_1;
    piVar1[1] = *(int *)(param_1 + 4);
    **(undefined4 **)(param_1 + 4) = piVar1;
    *(int **)(param_1 + 4) = piVar1;
    EventModify(*(undefined4 *)(param_1 + 8),3);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    uVar2 = 0;
  }
  return uVar2;
}



/* c067c014 FUN_c067c014 */

/* Boundary evidence: original MIPS .pdata c067c014..c067c01f. Semantic name remains unreviewed. */

undefined4 FUN_c067c014(void)

{
  return 1;
}



/* c067c020 FUN_c067c020 */

/* Boundary evidence: original MIPS .pdata c067c020..c067c153. Semantic name remains unreviewed. */

bool FUN_c067c020(int *param_1,void *param_2)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  piVar1 = (int *)*param_1;
  piVar2 = (int *)0x0;
  if (piVar1 != param_1) {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
    piVar2 = piVar1;
  }
  if ((int *)*param_1 == param_1) {
    WaitForSingleObject((HANDLE)param_1[2],0);
  }
  else {
    EventModify((HANDLE)param_1[2],3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if (piVar2 != (int *)0x0) {
    memcpy(param_2,piVar2 + 2,0x18);
    FUN_c067be20(piVar2);
  }
  return piVar2 != (int *)0x0;
}



/* c067c154 FUN_c067c154 */

/* Boundary evidence: original MIPS .pdata c067c154..c067c15f. Semantic name remains unreviewed. */

undefined4 FUN_c067c154(void)

{
  return 1;
}



/* c067c160 FUN_c067c160 */

/* Boundary evidence: original MIPS .pdata c067c160..c067c1e3. Semantic name remains unreviewed. */

int FUN_c067c160(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  if (param_2 != -0x7fffffce) {
    if (param_1 < 1) {
      piVar1 = FUN_c0682990(param_2);
      if (piVar1 != (int *)0x0) {
        FUN_c0682cb8((int)piVar1);
        FUN_c06828c4(piVar1);
        FUN_c0682a84(piVar1);
      }
    }
    else {
      FUN_c06832d4(param_2,param_2,param_3,param_4);
      param_1 = param_2;
    }
  }
  return param_1;
}



/* c067c1e4 FUN_c067c1e4 */

/* Boundary evidence: original MIPS .pdata c067c1e4..c067c2eb. Semantic name remains unreviewed. */

HLOCAL FUN_c067c1e4(int param_1,uint param_2,int param_3)

{
  int iVar1;
  HLOCAL pvVar2;
  int iVar3;
  int local_20 [2];
  
  local_20[0] = 0;
  if (param_2 < 0x20001) {
    if (param_2 == 0) {
      pvVar2 = LocalAlloc(0x40,0);
      return pvVar2;
    }
    iVar3 = param_1;
    if ((param_3 == 0) ||
       (iVar1 = CeOpenCallerBuffer(local_20,param_1,param_2,4,0), iVar3 = local_20[0], -1 < iVar1))
    {
      pvVar2 = LocalAlloc(0x40,param_2);
      if ((pvVar2 != (HLOCAL)0x0) && (iVar3 = CeSafeCopyMemory(pvVar2,iVar3,param_2), iVar3 == 0)) {
        LocalFree(pvVar2);
        pvVar2 = (HLOCAL)0x0;
      }
      if (local_20[0] == 0) {
        return pvVar2;
      }
      CeCloseCallerBuffer(local_20[0],param_1,param_2,4);
      return pvVar2;
    }
  }
  return (HLOCAL)0x0;
}



/* c067c2ec FUN_c067c2ec */

/* Boundary evidence: original MIPS .pdata c067c2ec..c067c3a7. Semantic name remains unreviewed. */

HLOCAL FUN_c067c2ec(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  HLOCAL pvVar2;
  STRSAFE_PCNZWCH pwVar3;
  size_t local_18;
  STRSAFE_PCNZWCH local_14;
  
  local_18 = 0;
  HVar1 = StringCchLengthW(param_1,0x104,&local_18);
  pwVar3 = (STRSAFE_PCNZWCH)0x0;
  if (-1 < HVar1) {
    pwVar3 = param_1;
    local_14 = param_1;
  }
  if (local_18 == 0) {
    pvVar2 = (HLOCAL)0x0;
  }
  else {
    pvVar2 = FUN_c067c1e4((int)pwVar3,(local_18 + 1) * 2,0);
  }
  return pvVar2;
}



/* c067c3a8 FUN_c067c3a8 */

/* Boundary evidence: original MIPS .pdata c067c3a8..c067c3b3. Semantic name remains unreviewed. */

undefined4 FUN_c067c3a8(void)

{
  return 1;
}



/* c067c3b4 FUN_c067c3b4 */

/* Boundary evidence: original MIPS .pdata c067c3b4..c067c457. Semantic name remains unreviewed. */

void FUN_c067c3b4(int param_1,HLOCAL param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_18 [2];
  
  local_18[0] = 0;
  if (param_2 != (HLOCAL)0x0) {
    iVar2 = param_1;
    if ((param_4 == 0) ||
       (iVar1 = CeOpenCallerBuffer(local_18,param_1,param_3,8,0), iVar2 = local_18[0], -1 < iVar1))
    {
      CeSafeCopyMemory(iVar2,param_2,param_3);
    }
    LocalFree(param_2);
    if (local_18[0] != 0) {
      CeCloseCallerBuffer(local_18[0],param_1,param_3,8);
    }
  }
  return;
}



/* c067c458 FUN_c067c458 */

/* Boundary evidence: original MIPS .pdata c067c458..c067c4ff. Semantic name remains unreviewed. */

undefined4 FUN_c067c458(int param_1)

{
  undefined4 uVar1;
  HMODULE hLibModule;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
LAB_c067c478:
    uVar1 = 0;
  }
  else {
    iVar3 = 0;
    hLibModule = LoadLibraryW(L"COREDLL.DLL");
    if (hLibModule != (HMODULE)0x0) {
      pcVar2 = (code *)GetProcAddressW(hLibModule,L"IsWindow");
      if (pcVar2 != (code *)0x0) {
        iVar3 = (*pcVar2)(param_1);
      }
      FreeLibrary(hLibModule);
      if (iVar3 != 0) goto LAB_c067c478;
    }
    uVar1 = 0x80000032;
  }
  return uVar1;
}



/* c067c500 FUN_c067c500 */

/* Boundary evidence: original MIPS .pdata c067c500..c067c54b. Semantic name remains unreviewed. */

void FUN_c067c500(void)

{
  return;
}



/* c067c54c FUN_c067c54c */

/* Boundary evidence: original MIPS .pdata c067c54c..c067c557. Semantic name remains unreviewed. */

undefined4 FUN_c067c54c(void)

{
  return 1;
}



/* c067c558 FUN_c067c558 */

/* Boundary evidence: original MIPS .pdata c067c558..c067c59f. Semantic name remains unreviewed. */

undefined4 FUN_c067c558(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return 1;
}



/* c067c5a0 FUN_c067c5a0 */

/* Boundary evidence: original MIPS .pdata c067c5a0..c067c5ab. Semantic name remains unreviewed. */

undefined4 FUN_c067c5a0(void)

{
  return 1;
}



/* c067c5ac FUN_c067c5ac */

/* Boundary evidence: original MIPS .pdata c067c5ac..c067c74f. Semantic name remains unreviewed. */

undefined4 * FUN_c067c5ac(int param_1,undefined4 *param_2,wchar_t *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_3c;
  
  bVar1 = param_2 == (undefined4 *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar3 = DAT_c0686190;
  puVar6 = DAT_c0686190;
  puVar4 = (undefined4 *)0x0;
LAB_c067c620:
  do {
    puVar5 = puVar4;
    if ((undefined4 **)puVar6 != &DAT_c0686190) {
      puVar5 = puVar6 + -1;
      local_3c = puVar5;
      if (param_1 != 0) {
        if (bVar1) {
          if (puVar6[2] == param_1) goto LAB_c067c6b0;
        }
        else if (param_2 == puVar5) {
          bVar1 = true;
        }
      }
      if ((param_3 == (wchar_t *)0x0) ||
         (iVar2 = _wcsicmp(param_3,(wchar_t *)(puVar6 + 0x10)), puVar3 = DAT_c0686190, iVar2 != 0))
      {
        puVar6 = (undefined4 *)*puVar6;
        goto LAB_c067c620;
      }
    }
LAB_c067c6b0:
    if ((param_1 == 0) || (bVar1)) {
      if (puVar5 != (undefined4 *)0x0) {
        local_3c[0xf] = local_3c[0xf] + 1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
      return puVar5;
    }
    bVar1 = true;
    puVar6 = puVar3;
    puVar4 = puVar5;
  } while( true );
}



/* c067c750 FUN_c067c750 */

/* Boundary evidence: original MIPS .pdata c067c750..c067c75b. Semantic name remains unreviewed. */

undefined4 FUN_c067c750(void)

{
  return 1;
}



/* c067c75c FUN_c067c75c */

/* Boundary evidence: original MIPS .pdata c067c75c..c067c83b. Semantic name remains unreviewed. */

int * FUN_c067c75c(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar2 = DAT_c0686180;
  do {
    piVar4 = (int *)0x0;
    if ((undefined4 **)puVar2 == &DAT_c0686180) break;
    piVar4 = puVar2 + -1;
    puVar3 = (undefined4 *)*puVar2;
    piVar1 = puVar2 + 6;
    puVar2 = puVar3;
  } while ((*piVar1 != param_1) || (*piVar4 != 0x454e494c));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return piVar4;
}



/* c067c83c FUN_c067c83c */

/* Boundary evidence: original MIPS .pdata c067c83c..c067c847. Semantic name remains unreviewed. */

undefined4 FUN_c067c83c(void)

{
  return 1;
}



/* c067c848 FUN_c067c848 */

/* Boundary evidence: original MIPS .pdata c067c848..c067c98b. Semantic name remains unreviewed. */

undefined4 * FUN_c067c848(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  bVar1 = param_2 == (undefined4 *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar2 = DAT_c06861a8;
  puVar4 = (undefined4 *)0x0;
  puVar3 = DAT_c06861a8;
  do {
    while (puVar5 = puVar4, (undefined4 **)puVar2 == &DAT_c06861a8) {
LAB_c067c914:
      puVar2 = puVar3;
      if (bVar1) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
        return puVar5;
      }
      bVar1 = true;
      puVar4 = puVar5;
      puVar3 = puVar2;
    }
    puVar5 = puVar2 + -1;
    if (param_1 != 0) {
      if (bVar1) {
        if (puVar2[4] == param_1) {
          puVar2[5] = puVar2[5] + 1;
          puVar3 = DAT_c06861a8;
          goto LAB_c067c914;
        }
      }
      else if (param_2 == puVar5) {
        bVar1 = true;
      }
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c067c98c FUN_c067c98c */

/* Boundary evidence: original MIPS .pdata c067c98c..c067c997. Semantic name remains unreviewed. */

undefined4 FUN_c067c98c(void)

{
  return 1;
}



/* c067c998 FUN_c067c998 */

/* Boundary evidence: original MIPS .pdata c067c998..c067ca77. Semantic name remains unreviewed. */

int * FUN_c067c998(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar2 = DAT_c0686198;
  do {
    piVar4 = (int *)0x0;
    if ((undefined4 **)puVar2 == &DAT_c0686198) break;
    piVar4 = puVar2 + -1;
    puVar3 = (undefined4 *)*puVar2;
    piVar1 = puVar2 + 6;
    puVar2 = puVar3;
  } while ((*piVar1 != param_1) || (*piVar4 != 0x4e4f4850));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return piVar4;
}



/* c067ca78 FUN_c067ca78 */

/* Boundary evidence: original MIPS .pdata c067ca78..c067ca83. Semantic name remains unreviewed. */

undefined4 FUN_c067ca78(void)

{
  return 1;
}



/* c067ca84 FUN_c067ca84 */

undefined4 FUN_c067ca84(uint param_1)

{
  if (param_1 < 0x201) {
    if (param_1 == 0x200) {
      return 7;
    }
    if (param_1 < 0x21) {
      if (param_1 == 0x20) {
        return 4;
      }
      if (param_1 == 2) {
        return 0;
      }
      if (param_1 == 4) {
        return 1;
      }
      if (param_1 == 8) {
        return 2;
      }
      if (param_1 == 0x10) {
        return 6;
      }
    }
    else {
      if (param_1 == 0x40) {
        return 0xb;
      }
      if (param_1 == 0x80) {
        return 5;
      }
      if (param_1 == 0x100) {
        return 3;
      }
    }
  }
  else if (param_1 < 0x4001) {
    if (param_1 == 0x4000) {
      return 0xd;
    }
    if (param_1 == 0x400) {
      return 8;
    }
    if (param_1 == 0x800) {
      return 9;
    }
    if (param_1 == 0x1000) {
      return 10;
    }
    if (param_1 == 0x2000) {
      return 0xc;
    }
  }
  else {
    if (param_1 == 0x8000) {
      return 0xe;
    }
    if (param_1 == 0x10000) {
      return 0xf;
    }
    if (param_1 == 0x20000) {
      return 0x10;
    }
  }
  return 0xffffffff;
}



/* c067cc04 FUN_c067cc04 */

/* Boundary evidence: original MIPS .pdata c067cc04..c067cc67. Semantic name remains unreviewed. */

undefined4 FUN_c067cc04(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x14) + 0x18) + 0x78))
                    (*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x18),local_10);
  if (iVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x40) = local_10[0];
  }
  else {
    local_10[0] = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x40) = 1;
  }
  return local_10[0];
}



/* c067cc68 FUN_c067cc68 */

/* Boundary evidence: original MIPS .pdata c067cc68..c067cd4f. Semantic name remains unreviewed. */

undefined4 * FUN_c067cc68(wchar_t *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar3 = DAT_c0686160;
  do {
    puVar2 = (undefined4 *)0x0;
    if ((undefined4 **)puVar3 == &DAT_c0686160) break;
    puVar4 = (undefined4 *)*puVar3;
    iVar1 = _wcsicmp((wchar_t *)(puVar3 + 7),param_1);
    puVar2 = puVar3;
    puVar3 = puVar4;
  } while (iVar1 != 0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return puVar2;
}



/* c067cd50 FUN_c067cd50 */

/* Boundary evidence: original MIPS .pdata c067cd50..c067cd5b. Semantic name remains unreviewed. */

undefined4 FUN_c067cd50(void)

{
  return 1;
}



/* c067cd5c FUN_c067cd5c */

undefined4 FUN_c067cd5c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(uint *)(param_1 + 0x24) & 4) != 0) && (*(int *)(*(int *)(param_1 + 0x18) + 0x34) == 1))
     && (*(int *)(*(int *)(param_1 + 0x18) + 0x60) != 1)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c067cd94 FUN_c067cd94 */

undefined4 FUN_c067cd94(uint param_1,uint param_2)

{
  if ((0x10002 < param_1) && ((param_1 < 0x10006 || (param_1 == 0x20000)))) {
    if (param_2 == 0) {
      param_2 = 0x20000;
    }
    if (param_1 <= param_2) {
      return 1;
    }
  }
  return 0;
}



/* c067cde8 FUN_c067cde8 */

undefined4 FUN_c067cde8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (uVar1 = 0, param_2 == param_1)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c067ce04 FUN_c067ce04 */

/* Boundary evidence: original MIPS .pdata c067ce04..c067cecf. Semantic name remains unreviewed. */

undefined4 FUN_c067ce04(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar1 = (undefined4 *)*param_2;
  do {
    if (puVar1 == param_2) {
LAB_c067ce74:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
      return uVar2;
    }
    if (puVar1 == param_1) {
      uVar2 = 1;
      goto LAB_c067ce74;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}



/* c067ced0 FUN_c067ced0 */

/* Boundary evidence: original MIPS .pdata c067ced0..c067cedb. Semantic name remains unreviewed. */

undefined4 FUN_c067ced0(void)

{
  return 1;
}



/* c067cedc FUN_c067cedc */

undefined4 FUN_c067cedc(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 != 1) {
    if (param_1 == 2) {
      uVar1 = param_2 & 6;
    }
    else {
      if (param_1 != 4) {
        return 0;
      }
      uVar1 = param_2 & 4;
    }
    if (uVar1 == 0) {
      return 0;
    }
  }
  return 1;
}



/* c067cf2c FUN_c067cf2c */

/* Boundary evidence: original MIPS .pdata c067cf2c..c067cffb. Semantic name remains unreviewed. */

undefined4 FUN_c067cf2c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04(param_1 + 1,&DAT_c0686170);
  if ((iVar1 != 0) && (*param_1 == 0x4c4c4143)) {
    uVar2 = 1;
    param_1[10] = param_1[10] + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return uVar2;
}



/* c067cffc FUN_c067cffc */

/* Boundary evidence: original MIPS .pdata c067cffc..c067d007. Semantic name remains unreviewed. */

undefined4 FUN_c067cffc(void)

{
  return 1;
}



/* c067d008 FUN_c067d008 */

/* Boundary evidence: original MIPS .pdata c067d008..c067d02b. Semantic name remains unreviewed. */

void FUN_c067d008(undefined4 *param_1)

{
  FUN_c067ce04(param_1,&DAT_c0686160);
  return;
}



/* c067d02c FUN_c067d02c */

/* Boundary evidence: original MIPS .pdata c067d02c..c067d103. Semantic name remains unreviewed. */

undefined4 FUN_c067d02c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04(param_1 + 1,&DAT_c0686190);
  if (((iVar1 != 0) && (*param_1 == 0xcb)) && (param_1[5] == 0)) {
    uVar2 = 1;
    param_1[0xf] = param_1[0xf] + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return uVar2;
}



/* c067d104 FUN_c067d104 */

/* Boundary evidence: original MIPS .pdata c067d104..c067d10f. Semantic name remains unreviewed. */

undefined4 FUN_c067d104(void)

{
  return 1;
}



/* c067d110 FUN_c067d110 */

/* Boundary evidence: original MIPS .pdata c067d110..c067d14b. Semantic name remains unreviewed. */

bool FUN_c067d110(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c067ce04((undefined4 *)(param_1 + 4),&DAT_c0686180);
  return iVar1 != 0;
}



/* c067d14c FUN_c067d14c */

/* Boundary evidence: original MIPS .pdata c067d14c..c067d23f. Semantic name remains unreviewed. */

undefined4 FUN_c067d14c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04(param_1 + 1,&DAT_c0686188);
  if ((((iVar1 != 0) && (*param_1 == 0xca)) && (param_1[0x10] == 0)) &&
     (iVar1 = FUN_c067ce04((undefined4 *)(param_1[6] + 4),&DAT_c0686180), iVar1 != 0)) {
    uVar2 = 1;
    param_1[7] = param_1[7] + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return uVar2;
}



/* c067d240 FUN_c067d240 */

/* Boundary evidence: original MIPS .pdata c067d240..c067d24b. Semantic name remains unreviewed. */

undefined4 FUN_c067d240(void)

{
  return 1;
}



/* c067d24c FUN_c067d24c */

/* Boundary evidence: original MIPS .pdata c067d24c..c067d303. Semantic name remains unreviewed. */

int FUN_c067d24c(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04((undefined4 *)(param_1 + 4),&DAT_c06861a8);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return iVar1;
}



/* c067d304 FUN_c067d304 */

/* Boundary evidence: original MIPS .pdata c067d304..c067d30f. Semantic name remains unreviewed. */

undefined4 FUN_c067d304(void)

{
  return 1;
}



/* c067d310 FUN_c067d310 */

/* Boundary evidence: original MIPS .pdata c067d310..c067d337. Semantic name remains unreviewed. */

void FUN_c067d310(int param_1)

{
  FUN_c067ce04((undefined4 *)(param_1 + 4),&DAT_c0686198);
  return;
}



/* c067d338 FUN_c067d338 */

/* Boundary evidence: original MIPS .pdata c067d338..c067d40f. Semantic name remains unreviewed. */

undefined4 FUN_c067d338(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04(param_1 + 1,&DAT_c06861a0);
  if (((iVar1 != 0) && (*param_1 == 0xcd)) && (param_1[0x11] == 0)) {
    uVar2 = 1;
    param_1[9] = param_1[9] + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return uVar2;
}



/* c067d410 FUN_c067d410 */

/* Boundary evidence: original MIPS .pdata c067d410..c067d41b. Semantic name remains unreviewed. */

undefined4 FUN_c067d410(void)

{
  return 1;
}



/* c067d41c FUN_c067d41c */

undefined4 FUN_c067d41c(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x19) || (uVar1 = 1, 0x1d < param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c067d440 FUN_c067d440 */

/* Boundary evidence: original MIPS .pdata c067d440..c067d563. Semantic name remains unreviewed. */

int FUN_c067d440(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  for (puVar1 = *(undefined4 **)(param_1 + 0xc); puVar1 != (undefined4 *)(param_1 + 0xc);
      puVar1 = (undefined4 *)*puVar1) {
    uVar3 = puVar1[10] | uVar3;
  }
  iVar4 = *(int *)(param_1 + 0x18);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if ((iVar4 != 0) &&
     (iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 0x18) + 0xc4))(iVar4,uVar3),
     iVar2 == 0)) {
    *(uint *)(param_1 + 0x20) = uVar3;
  }
  return iVar2;
}



/* c067d564 FUN_c067d564 */

/* Boundary evidence: original MIPS .pdata c067d564..c067d56f. Semantic name remains unreviewed. */

undefined4 FUN_c067d564(void)

{
  return 1;
}



/* c067d570 FUN_c067d570 */

/* Boundary evidence: original MIPS .pdata c067d570..c067d5e3. Semantic name remains unreviewed. */

bool FUN_c067d570(int param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  bVar1 = *(int *)(param_1 + 0x4c) == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x4c) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if (bVar1) {
    FUN_c0681284((HLOCAL)param_1);
  }
  return bVar1;
}



/* c067d5e4 FUN_c067d5e4 */

/* Boundary evidence: original MIPS .pdata c067d5e4..c067d65f. Semantic name remains unreviewed. */

bool FUN_c067d5e4(HLOCAL param_1)

{
  bool bVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  bVar1 = *(int *)((int)param_1 + 0x38) == 0;
  if (bVar1) {
    FUN_c067ffc8((int)param_1);
    *(undefined4 *)((int)param_1 + 0x38) = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if (bVar1) {
    FUN_c068179c(param_1);
  }
  return bVar1;
}



/* c067d660 FUN_c067d660 */

/* Boundary evidence: original MIPS .pdata c067d660..c067d80f. Semantic name remains unreviewed. */

undefined4 FUN_c067d660(HKEY param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t wVar1;
  STRSAFE_PCNZWCH _Str;
  LSTATUS LVar2;
  STRSAFE_PCNZWCH lpData;
  size_t sVar3;
  undefined4 *puVar4;
  int iVar5;
  wchar_t *_Str_00;
  undefined4 uVar6;
  DWORD local_30;
  DWORD local_2c;
  
  uVar6 = 0;
  LVar2 = RegQueryValueExW(param_1,L"Tsp",(LPDWORD)0x0,&local_2c,(LPBYTE)0x0,&local_30);
  if ((LVar2 == 0) && (lpData = LocalAlloc(0x40,local_30 + 5), lpData != (STRSAFE_PCNZWCH)0x0)) {
    LVar2 = RegQueryValueExW(param_1,L"Tsp",(LPDWORD)0x0,&local_2c,(LPBYTE)lpData,&local_30);
    if (LVar2 == 0) {
      wVar1 = *lpData;
      iVar5 = 0;
      _Str_00 = lpData;
      while ((_Str = lpData, wVar1 != L'\0' && (iVar5 = iVar5 + 1, local_2c == 7))) {
        sVar3 = wcslen(_Str_00);
        _Str_00 = _Str_00 + sVar3 + 1;
        wVar1 = *_Str_00;
      }
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        FUN_c0674990(_Str,0,(undefined4 *)0x0);
        puVar4 = FUN_c067cc68(_Str);
        if (puVar4 != (undefined4 *)0x0) {
          (**(code **)(puVar4[6] + 0x114))(param_2,param_3,param_4);
          (**(code **)(puVar4[6] + 0x17c))(param_2,param_3,param_4);
          uVar6 = 1;
        }
        sVar3 = wcslen(_Str);
        _Str = _Str + sVar3 + 1;
      }
    }
    LocalFree(lpData);
  }
  return uVar6;
}



/* c067d810 FUN_c067d810 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c067d810..c067da9f. Semantic name remains unreviewed. */

int FUN_c067d810(HKEY param_1,undefined4 param_2)

{
  int iVar1;
  LSTATUS LVar2;
  size_t sVar3;
  undefined4 *puVar4;
  DWORD local_548;
  HKEY local_544;
  DWORD local_540;
  HKEY local_53c;
  DWORD aDStack_538 [2];
  WCHAR aWStack_530 [64];
  wchar_t awStack_4b0 [63];
  wchar_t awStack_432 [257];
  WCHAR aWStack_230 [256];
  uint local_30;
  
  local_30 = DAT_c068610c;
  local_540 = 0x200;
  local_548 = 0x200;
  iVar1 = GetDeviceKeys(param_2,aWStack_230,&local_548,awStack_432 + 1,&local_540);
  if ((iVar1 == 0) &&
     (LVar2 = RegOpenKeyExW((HKEY)0x80000002,aWStack_230,0,0,&local_53c), LVar2 == 0)) {
    wcscat(awStack_432 + 1,L"\\");
    sVar3 = wcslen(awStack_432 + 1);
    local_540 = 0;
    local_544 = (HKEY)0x0;
    iVar1 = 0;
    while( true ) {
      if (local_544 != (HKEY)0x0) {
        RegCloseKey(local_544);
        local_544 = (HKEY)0x0;
      }
      local_548 = 0x40;
      LVar2 = RegEnumKeyExW(param_1,local_540,aWStack_530,&local_548,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (LVar2 != 0) break;
      local_540 = local_540 + 1;
      LVar2 = RegOpenKeyExW(param_1,aWStack_530,0,0,&local_544);
      if (LVar2 == 0) {
        local_548 = 0x80;
        LVar2 = RegQueryValueExW(local_544,L"Tsp",(LPDWORD)0x0,aDStack_538,(LPBYTE)awStack_4b0,
                                 &local_548);
        if (LVar2 == 0) {
          FUN_c0674990(awStack_4b0,0,(undefined4 *)0x0);
          puVar4 = FUN_c067cc68(awStack_4b0);
          if (puVar4 != (undefined4 *)0x0) {
            wcscpy(awStack_432 + sVar3 + 1,aWStack_530);
            (**(code **)(puVar4[6] + 0x114))(local_53c,awStack_432 + 1,param_2);
            (**(code **)(puVar4[6] + 0x17c))(local_53c,awStack_432 + 1,param_2);
            iVar1 = 1;
          }
        }
      }
    }
    if (iVar1 == 0) {
      awStack_432[sVar3] = L'\0';
      iVar1 = FUN_c067d660(param_1,local_53c,awStack_432 + 1,param_2);
    }
    RegCloseKey(local_53c);
    FUN_c0684adc(local_30);
  }
  else {
    FUN_c0684adc(local_30);
    iVar1 = 0;
  }
  return iVar1;
}



/* c067daa0 FUN_c067daa0 */

/* Boundary evidence: original MIPS .pdata c067daa0..c067db47. Semantic name remains unreviewed. */

undefined4 FUN_c067daa0(wchar_t *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HMODULE pHVar3;
  code *pcVar4;
  
  puVar1 = FUN_c067cc68(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    pHVar3 = LoadLibraryW(param_1);
    *param_2 = pHVar3;
    if (pHVar3 == (HMODULE)0x0) {
      uVar2 = 0x80000032;
    }
    else {
      pcVar4 = (code *)GetProcAddressW(pHVar3,L"TSPI_lineGetProcTable");
      if (pcVar4 == (code *)0x0) {
        uVar2 = 0x80000048;
      }
      else {
        (*pcVar4)(param_3);
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0x80000056;
  }
  return uVar2;
}



/* c067db48 FUN_c067db48 */

undefined4 FUN_c067db48(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if (param_3 != 0) {
    if (((param_4 < param_2) || (param_1 <= param_4)) || (param_1 < param_3 + param_4)) {
      return 1;
    }
    if (param_3 + param_4 < param_3) {
      return 1;
    }
  }
  return 0;
}



/* c067db98 FUN_c067db98 */

/* Boundary evidence: original MIPS .pdata c067db98..c067e043. Semantic name remains unreviewed. */

undefined4 FUN_c067db98(uint *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  SIZE_T *_Dst;
  uint uVar2;
  uint uVar3;
  uint _Size;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_3 == 0x10003) {
    uVar2 = 0x3f;
  }
  else {
    if ((param_3 != 0x10004) && (1 < param_3 - 0x10004)) {
      if (param_3 - 0x10004 != 0xfffc) {
        return 0x80000048;
      }
      _Size = 0xb4;
      uVar2 = 0xff;
      goto LAB_c067dc30;
    }
    uVar2 = 0x7f;
  }
  _Size = 0x6c;
LAB_c067dc30:
  uVar4 = *param_1;
  if (uVar4 < _Size) {
    uVar5 = 0x8000004d;
  }
  else {
    uVar3 = param_1[1];
    uVar5 = 0x80000019;
    if ((uVar3 == 0) || (((uVar3 - 1 & uVar3) == 0 && ((~uVar2 & uVar3) == 0)))) {
      uVar2 = param_1[4];
      if (((uVar2 & 0xfc0001) != 0) ||
         (((uVar2 == 0 || ((uVar2 - 1 & uVar2) != 0)) && ((uVar2 & 2) == 0)))) {
        if (uVar2 != 0) {
          return 0x8000002f;
        }
        param_1[4] = 4;
      }
      if ((param_1[5] & 0xffffffe0) == 0) {
        uVar2 = param_1[6];
        if ((uVar2 != 1) && (uVar2 != 2)) {
          if (uVar2 != 0) {
            return 0x80000012;
          }
          param_1[6] = 1;
        }
        iVar1 = FUN_c067db48(uVar4,_Size,param_1[0xc],param_1[0xd]);
        if (((iVar1 == 0) &&
            (iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x14],param_1[0x15]), iVar1 == 0)) &&
           ((iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x16],param_1[0x17]), iVar1 == 0 &&
            ((iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x18],param_1[0x19]), iVar1 == 0 &&
             (iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x1a],param_1[0x1b]), iVar1 == 0)))))) {
          iVar1 = FUN_c067db48(uVar4,_Size,param_1[0xe],param_1[0xf]);
          if (iVar1 != 0) {
            if (0x1ffff < param_3) {
              return 0x80000019;
            }
            param_1[0xf] = 0;
            param_1[0xe] = 0;
          }
          iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x10],param_1[0x11]);
          if (iVar1 != 0) {
            if (0x1ffff < param_3) {
              return 0x80000019;
            }
            param_1[0x11] = 0;
            param_1[0x10] = 0;
          }
          iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x12],param_1[0x13]);
          if (iVar1 != 0) {
            if (0x1ffff < param_3) {
              return 0x80000019;
            }
            param_1[0x13] = 0;
            param_1[0x12] = 0;
          }
          if (0x10005 < param_3) {
            if ((param_1[0x1c] & 0xffff0000) != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x1d],param_1[0x1e]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x1f],param_1[0x20]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x21],param_1[0x22]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x23],param_1[0x24]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x25],param_1[0x26]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x27],param_1[0x28]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            iVar1 = FUN_c067db48(uVar4,_Size,param_1[0x2a],param_1[0x2b]);
            if (iVar1 != 0) {
              return 0x80000019;
            }
            if (param_1[0x2c] == 0) {
              param_1[0x2c] = 1;
            }
          }
          if (_Size < 0xb4) {
            iVar1 = 0xb4 - _Size;
            _Dst = LocalAlloc(0x40,iVar1 + uVar4);
            if (_Dst == (SIZE_T *)0x0) {
              return 0x80000044;
            }
            memcpy(_Dst,param_1,_Size);
            *_Dst = iVar1 + uVar4;
            memcpy(_Dst + 0x2d,(void *)(_Size + (int)param_1),uVar4 - _Size);
            _Dst[0xd] = _Dst[0xd] + iVar1;
            _Dst[0xf] = _Dst[0xf] + iVar1;
            _Dst[0x11] = _Dst[0x11] + iVar1;
            _Dst[0x13] = _Dst[0x13] + iVar1;
            _Dst[0x15] = _Dst[0x15] + iVar1;
            _Dst[0x17] = _Dst[0x17] + iVar1;
            _Dst[0x19] = _Dst[0x19] + iVar1;
            _Dst[0x1b] = _Dst[0x1b] + iVar1;
            *param_2 = _Dst;
          }
          else {
            *param_2 = param_1;
          }
          uVar5 = 0;
        }
      }
    }
    else {
      uVar5 = 0x80000016;
    }
  }
  return uVar5;
}



/* c067e044 FUN_c067e044 */

/* Boundary evidence: original MIPS .pdata c067e044..c067e1a3. Semantic name remains unreviewed. */

HLOCAL FUN_c067e044(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  HLOCAL pvVar3;
  int iVar4;
  
  pvVar3 = (HLOCAL)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar4 = 0;
  for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)*puVar1) {
    iVar4 = iVar4 + 1;
  }
  if (iVar4 != 0) {
    pvVar3 = LocalAlloc(0x40,(iVar4 + 1) * 4);
    if (pvVar3 != (HLOCAL)0x0) {
      iVar2 = 0;
      for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)*puVar1) {
        *(undefined4 **)(iVar2 * 4 + (int)pvVar3) = puVar1;
        iVar2 = iVar2 + 1;
        if (iVar4 == iVar2) break;
      }
      *(undefined4 *)(iVar4 * 4 + (int)pvVar3) = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return pvVar3;
}



/* c067e1a4 FUN_c067e1a4 */

/* Boundary evidence: original MIPS .pdata c067e1a4..c067e1af. Semantic name remains unreviewed. */

undefined4 FUN_c067e1a4(void)

{
  return 1;
}



/* c067e1b0 FUN_c067e1b0 */

/* Boundary evidence: original MIPS .pdata c067e1b0..c067e2f3. Semantic name remains unreviewed. */

undefined4 FUN_c067e1b0(int param_1,uint param_2,undefined4 *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  HLOCAL pvVar3;
  undefined4 uVar4;
  int local_40 [2];
  uint local_38 [6];
  
  local_40[0] = 0;
  iVar2 = param_1;
  if (((param_5 == 0) ||
      (iVar1 = CeOpenCallerBuffer(local_40,param_1,0x18,0xc,0), iVar2 = local_40[0], -1 < iVar1)) &&
     (iVar1 = CeSafeCopyMemory(local_38,iVar2,0x18), iVar1 != 0)) {
    if (local_38[0] < param_2) {
      uVar4 = 0x8000004d;
      if ((param_4 == 0) || (iVar2 = FUN_c067c558((undefined4 *)(iVar2 + 4),param_2), iVar2 != 0))
      goto LAB_c067e268;
    }
    else {
      if ((param_5 != 0) && (local_40[0] != 0)) {
        CeCloseCallerBuffer(local_40[0],param_1,0x18,0xc);
        local_40[0] = 0;
      }
      pvVar3 = FUN_c067c1e4(param_1,local_38[0],param_5);
      *param_3 = pvVar3;
      if (pvVar3 != (HLOCAL)0x0) {
        uVar4 = 0;
        goto LAB_c067e268;
      }
    }
  }
  uVar4 = 0x80000035;
LAB_c067e268:
  if (local_40[0] != 0) {
    CeCloseCallerBuffer(local_40[0],param_1,0x18,0xc);
  }
  return uVar4;
}



/* c067e2f4 FUN_c067e2f4 */

/* Boundary evidence: original MIPS .pdata c067e2f4..c067e31b. Semantic name remains unreviewed. */

void FUN_c067e2f4(int param_1,undefined4 *param_2,int param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    FUN_c067c3b4(param_1,param_2,*param_2,param_3);
  }
  return;
}



/* c067e31c FUN_c067e31c */

/* Boundary evidence: original MIPS .pdata c067e31c..c067e433. Semantic name remains unreviewed. */

undefined4 FUN_c067e31c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80000018;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  iVar1 = FUN_c067ce04(param_1 + 1,&DAT_c0686178);
  if (((iVar1 != 0) && (*param_1 == 0xcc)) && (param_1[0xd] == 0)) {
    iVar1 = FUN_c067cedc(param_2,param_1[9]);
    if (iVar1 == 0) {
      uVar2 = 0x80000046;
    }
    else {
      uVar2 = 0;
      param_1[8] = param_1[8] + 1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return uVar2;
}



/* c067e434 FUN_c067e434 */

/* Boundary evidence: original MIPS .pdata c067e434..c067e43f. Semantic name remains unreviewed. */

undefined4 FUN_c067e434(void)

{
  return 1;
}



/* c067e440 FUN_c067e440 */

/* Boundary evidence: original MIPS .pdata c067e440..c067e57f. Semantic name remains unreviewed. */

undefined4 * FUN_c067e440(int param_1,int *param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_c067cf2c(param_2);
  if (iVar2 == 0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar2 = param_2[8];
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    puVar1 = *(undefined4 **)(iVar2 + 0xc);
    do {
      puVar3 = puVar1;
      puVar4 = (undefined4 *)0x0;
      if (puVar3 == (undefined4 *)(iVar2 + 0xc)) goto LAB_c067e50c;
      puVar4 = puVar3 + -3;
      puVar1 = (undefined4 *)*puVar3;
    } while ((puVar3[2] != param_1) || ((puVar3[10] & param_3) == 0));
    puVar3[4] = puVar3[4] + 1;
LAB_c067e50c:
    FUN_c0681284(param_2);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  }
  return puVar4;
}



/* c067e580 FUN_c067e580 */

/* Boundary evidence: original MIPS .pdata c067e580..c067e58b. Semantic name remains unreviewed. */

undefined4 FUN_c067e580(void)

{
  return 1;
}



/* c067e58c FUN_c067e58c */

/* Boundary evidence: original MIPS .pdata c067e58c..c067e6ff. Semantic name remains unreviewed. */

int * FUN_c067e58c(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *local_2c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  piVar5 = param_3 + 3;
  if (((int *)*piVar5 == piVar5) || (iVar2 = FUN_c067cf2c(param_3), iVar2 == 0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    piVar4 = (int *)0x0;
  }
  else {
    piVar1 = (int *)*piVar5;
    while (piVar3 = piVar1, piVar4 = (int *)0x0, piVar3 != piVar5) {
      local_2c = piVar3 + -3;
      piVar4 = local_2c;
      if (((param_1 != 0) && (*(int *)(piVar3[2] + 0x14) == param_1)) ||
         ((piVar1 = (int *)*piVar3, param_2 != 0 && (piVar3[2] == param_2)))) break;
    }
    if (piVar4 != (int *)0x0) {
      local_2c[8] = local_2c[8] + 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    FUN_c0681284(param_3);
  }
  return piVar4;
}



/* c067e700 FUN_c067e700 */

/* Boundary evidence: original MIPS .pdata c067e700..c067e70b. Semantic name remains unreviewed. */

undefined4 FUN_c067e700(void)

{
  return 1;
}



/* c067e70c FUN_c067e70c */

/* Boundary evidence: original MIPS .pdata c067e70c..c067e787. Semantic name remains unreviewed. */

undefined4 FUN_c067e70c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c067cf2c(param_1);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(param_1[6] + 0x18) + 0x54))(param_1[9],param_1 + 0x11);
    if (iVar1 != 0) {
      param_1[0x11] = 0;
    }
    iVar1 = FUN_c0681284(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* c067e788 FUN_c067e788 */

/* Boundary evidence: original MIPS .pdata c067e788..c067e887. Semantic name remains unreviewed. */

int * FUN_c067e788(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  puVar2 = DAT_c0686190;
  do {
    piVar3 = (int *)0x0;
    if ((undefined4 **)puVar2 == &DAT_c0686190) goto LAB_c067e828;
    piVar4 = puVar2 + -1;
    puVar2 = (undefined4 *)*puVar2;
  } while (*(char *)((int)piVar4 + param_1 + 0x28) != param_2);
  iVar1 = FUN_c067d02c(piVar4);
  if (iVar1 != 0) {
    piVar3 = piVar4;
  }
LAB_c067e828:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  return piVar3;
}



/* c067e888 FUN_c067e888 */

/* Boundary evidence: original MIPS .pdata c067e888..c067e893. Semantic name remains unreviewed. */

undefined4 FUN_c067e888(void)

{
  return 1;
}



/* c067e894 FUN_c067e894 */

/* Boundary evidence: original MIPS .pdata c067e894..c067eb1b. Semantic name remains unreviewed. */

int * FUN_c067e894(int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar2 = FUN_c067cf2c(param_1);
  if (iVar2 != 0) {
    uVar9 = DAT_c06861c8 + 1;
    uVar8 = 1;
    if (param_2 != (int *)0x2) {
      bVar1 = true;
      uVar11 = 1;
      if (1 < uVar9) {
        do {
          if (!bVar1) break;
          bVar1 = false;
          uVar10 = 0x20000;
          do {
            if ((((uVar10 & (uint)param_2) != 0) && (iVar2 = FUN_c067ca84(uVar10), iVar2 != -1)) &&
               (piVar3 = FUN_c067e788(iVar2,(char)uVar11), piVar3 != (int *)0x0)) {
              piVar6 = (int *)0x0;
              bVar1 = true;
              piVar7 = param_1;
              piVar4 = FUN_c067e58c((int)piVar3,0,param_1);
              if (piVar4 != (int *)0x0) goto LAB_c067eaf4;
              piVar6 = param_1;
              piVar7 = param_2;
              piVar5 = FUN_c067e440((int)piVar3,param_1,(uint)param_2);
              if (piVar5 != (int *)0x0) {
                piVar7 = (int *)piVar5[10];
                if ((((uint)piVar7 & param_3) != 0) &&
                   (piVar6 = param_1, piVar4 = FUN_c0681edc(piVar5,param_1,(uint)piVar7,param_4),
                   piVar4 != (int *)0x0)) goto LAB_c067eae0;
                FUN_c0681e1c(piVar5,piVar6,piVar7,param_4);
              }
              FUN_c06825a0(piVar3,piVar6,piVar7,param_4);
            }
            uVar10 = uVar10 >> 1;
          } while (2 < uVar10);
          uVar11 = uVar11 + 1;
        } while (uVar11 < uVar9);
      }
    }
    if (1 < uVar9) {
      do {
        piVar3 = FUN_c067e788(0,(char)uVar8);
        if (piVar3 != (int *)0x0) {
          piVar6 = (int *)0x0;
          piVar7 = param_1;
          piVar4 = FUN_c067e58c((int)piVar3,0,param_1);
          if (piVar4 != (int *)0x0) goto LAB_c067eaf4;
          piVar7 = (int *)0x2;
          piVar6 = param_1;
          piVar5 = FUN_c067e440((int)piVar3,param_1,2);
          if (piVar5 != (int *)0x0) {
            piVar7 = (int *)piVar5[10];
            if ((((uint)piVar7 & param_3) != 0) &&
               (piVar6 = param_1, piVar4 = FUN_c0681edc(piVar5,param_1,(uint)piVar7,param_4),
               piVar4 != (int *)0x0)) {
LAB_c067eae0:
              piVar4[8] = piVar4[8] + 1;
              FUN_c0681e1c(piVar5,piVar6,piVar7,param_4);
LAB_c067eaf4:
              if (param_1[7] == 0) {
                param_1[7] = (int)piVar3;
              }
              FUN_c0681284(param_1);
              FUN_c06825a0(piVar3,piVar6,piVar7,param_4);
              return piVar4;
            }
            FUN_c0681e1c(piVar5,piVar6,piVar7,param_4);
          }
          FUN_c06825a0(piVar3,piVar6,piVar7,param_4);
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < uVar9);
    }
    FUN_c0681284(param_1);
  }
  return (int *)0x0;
}



/* c067eb1c FUN_c067eb1c */

/* Boundary evidence: original MIPS .pdata c067eb1c..c067ec7b. Semantic name remains unreviewed. */

void FUN_c067eb1c(int param_1,int *param_2,int param_3,uint param_4,uint param_5,int param_6)

{
  int iVar1;
  int *hMem;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  piVar3 = &DAT_c0686180;
  iVar4 = param_3;
  uVar5 = param_4;
  iVar1 = FUN_c067ce04((undefined4 *)(param_1 + 4),&DAT_c0686180);
  if ((iVar1 != 0) && (hMem = FUN_c067e044((undefined4 *)(param_1 + 0xc)), hMem != (int *)0x0)) {
    iVar1 = *hMem;
    piVar7 = hMem;
    while (iVar1 != 0) {
      iVar1 = *piVar7;
      piVar6 = (int *)(iVar1 + -0xc);
      piVar7 = piVar7 + 1;
      if ((param_2 != piVar6) && (iVar2 = FUN_c067d14c(piVar6), iVar2 != 0)) {
        if ((((*(int **)(iVar1 + 8) != (int *)0x0) &&
             ((param_3 != 8 || ((*(uint *)(iVar1 + 0x20) & param_4) != 0)))) &&
            ((param_3 != 0 || ((*(uint *)(iVar1 + 0x24) & param_5) != 0)))) &&
           (iVar2 = FUN_c067d02c(*(int **)(iVar1 + 8)), iVar2 != 0)) {
          uVar5 = *(uint *)(iVar1 + 0x2c);
          piVar3 = piVar6;
          iVar4 = param_3;
          FUN_c067bf04(*(int *)(iVar1 + 8) + 0x18,(int)piVar6,param_3,uVar5,param_4,param_5,param_6)
          ;
          FUN_c06825a0(*(undefined4 **)(iVar1 + 8),piVar3,iVar4,uVar5);
        }
        FUN_c0681e1c(piVar6,piVar3,iVar4,uVar5);
      }
      iVar1 = *piVar7;
    }
    LocalFree(hMem);
  }
  return;
}



/* c067ec7c FUN_c067ec7c */

/* Boundary evidence: original MIPS .pdata c067ec7c..c067edef. Semantic name remains unreviewed. */

void FUN_c067ec7c(int param_1,int *param_2,int param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  int *hMem;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar1 = FUN_c067ce04((undefined4 *)(param_1 + 4),&DAT_c0686198);
  if ((iVar1 != 0) && (hMem = FUN_c067e044((undefined4 *)(param_1 + 0xc)), hMem != (int *)0x0)) {
    iVar1 = *hMem;
    piVar4 = hMem;
    while (iVar1 != 0) {
      iVar1 = *piVar4;
      piVar3 = (int *)(iVar1 + -0xc);
      piVar4 = piVar4 + 1;
      if ((param_2 != piVar3) && (iVar2 = FUN_c067d338(piVar3), iVar2 != 0)) {
        if ((((*(int *)(iVar1 + 0x10) != 0) &&
             ((param_3 != 0xe ||
              (((*(uint *)(iVar1 + 0x2c) & param_5) != 0 &&
               ((*(uint *)(iVar1 + 0x30) & param_6) != 0)))))) &&
            ((param_3 != 0x12 || ((*(uint *)(iVar1 + 0x28) & param_4) != 0)))) &&
           (iVar2 = FUN_c067d24c(*(int *)(iVar1 + 0x10)), iVar2 != 0)) {
          FUN_c067bf04(*(int *)(iVar1 + 0x10) + 0x24,(int)piVar3,param_3,*(int *)(iVar1 + 0x24),
                       param_4,param_5,param_6);
          FUN_c068185c(*(undefined4 **)(iVar1 + 0x10));
        }
        FUN_c0681344(piVar3);
      }
      iVar1 = *piVar4;
    }
    LocalFree(hMem);
  }
  return;
}



/* c067edf0 FUN_c067edf0 */

/* Boundary evidence: original MIPS .pdata c067edf0..c067ef83. Semantic name remains unreviewed. */

void FUN_c067edf0(int *param_1,int *param_2,int *param_3,int param_4)

{
  int *hMem;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (((param_2 != (int *)0x0) && (param_1 != (int *)0x0)) &&
     (piVar2 = param_3, iVar3 = param_4, hMem = FUN_c067e044(param_2 + 3), hMem != (int *)0x0)) {
    iVar4 = *hMem;
    piVar7 = hMem;
    while (iVar4 != 0) {
      iVar5 = *piVar7;
      piVar6 = (int *)(iVar5 + -0xc);
      piVar7 = piVar7 + 1;
      iVar4 = FUN_c067d14c(piVar6);
      if (iVar4 != 0) {
        if ((*(uint *)(iVar5 + 0x1c) & 2) != 0) {
          piVar8 = *(int **)(iVar5 + 8);
          iVar4 = FUN_c067d02c(piVar8);
          if (iVar4 != 0) {
            param_2 = (int *)0x0;
            piVar2 = param_1;
            piVar1 = FUN_c067e58c((int)piVar8,0,param_1);
            if (piVar1 == (int *)0x0) {
              piVar2 = (int *)0x2;
              param_2 = param_1;
              piVar1 = FUN_c0681edc(piVar6,param_1,2,iVar3);
              if (piVar1 != (int *)0x0) {
                FUN_c067bf04((int)(piVar8 + 6),(int)piVar6,0x17,*(int *)(iVar5 + 0x2c),param_1[0x11]
                             ,(int)piVar1,2);
                piVar1[10] = 1;
                iVar3 = *(int *)(iVar5 + 0x2c);
                piVar2 = (int *)0x2;
                FUN_c067bf04((int)(piVar8 + 6),(int)piVar1,2,iVar3,(int)param_3,param_4,0);
                param_2 = piVar1;
              }
            }
            else {
              FUN_c068179c(piVar1);
            }
            FUN_c06825a0(piVar8,param_2,piVar2,iVar3);
          }
        }
        FUN_c0681e1c(piVar6,param_2,piVar2,iVar3);
      }
      iVar4 = *piVar7;
    }
    LocalFree(hMem);
  }
  return;
}



/* c067ef84 FUN_c067ef84 */

/* Boundary evidence: original MIPS .pdata c067ef84..c067f037. Semantic name remains unreviewed. */

undefined4 FUN_c067ef84(undefined4 param_1)

{
  int *hMem;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  
  uVar2 = 0;
  hMem = FUN_c067e044(&DAT_c0686160);
  if (hMem == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    piVar3 = hMem;
    if (*hMem == 0) {
      uVar2 = 0;
    }
    else {
      do {
        piVar4 = piVar3 + 1;
        iVar1 = (**(code **)(*(int *)(*piVar3 + 0x18) + 0x184))(param_1);
        if (iVar1 == 0) {
          uVar2 = 1;
        }
        piVar3 = piVar4;
      } while (*piVar4 != 0);
    }
    LocalFree(hMem);
  }
  return uVar2;
}



/* c067f038 FUN_c067f038 */

/* Boundary evidence: original MIPS .pdata c067f038..c067f06f. Semantic name remains unreviewed. */

void FUN_c067f038(HKEY param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 1) {
    FUN_c067ef84(param_2);
  }
  else {
    FUN_c067d810(param_1,param_2);
  }
  return;
}



/* c067f070 FUN_c067f070 */

/* Boundary evidence: original MIPS .pdata c067f070..c067f3fb. Semantic name remains unreviewed. */

int FUN_c067f070(uint param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                undefined4 param_7,undefined4 param_8)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uStack_68;
  int local_64;
  uint local_60;
  int local_5c;
  int *local_58;
  int local_54;
  int *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_30;
  
  iVar8 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  bVar4 = false;
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  piVar5 = param_2;
  piVar6 = param_3;
  piVar7 = param_4;
  if ((param_1 < 0x19) || (0x1d < param_1)) {
    if (param_2 != (int *)0x0) {
      iVar8 = FUN_c067d14c(param_2);
      if (iVar8 == 0) {
        return -0x7fffffd5;
      }
      bVar1 = true;
      if (param_5 != (int *)0x0) {
        *param_5 = param_2[6];
      }
      iVar8 = param_2[5];
    }
    if (param_3 == (int *)0x0) {
      switch(param_1) {
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 7:
      case 8:
      case 10:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x15:
      case 0x16:
      case 0x17:
        iVar8 = -0x7fffffe8;
        break;
      case 6:
      case 9:
      case 0xb:
      case 0xc:
      case 0x13:
      case 0x14:
        goto switchD_c067f314_caseD_6;
      default:
        goto switchD_c067f314_default;
      }
    }
    else {
      if (((param_1 == 6) || (param_1 == 0xb)) || (piVar5 = (int *)0x4, param_1 == 0x13)) {
        piVar5 = (int *)0x2;
      }
      iVar8 = FUN_c067e31c(param_3,(int)piVar5);
      if (iVar8 == 0) {
        bVar4 = true;
        if (param_2 == (int *)0x0) {
          param_2 = (int *)param_3[5];
          iVar8 = FUN_c067d14c(param_2);
          if (iVar8 == 0) {
            iVar8 = -0x7fffffb8;
            goto LAB_c067f254;
          }
          bVar1 = true;
          bVar2 = true;
        }
        if (param_6 != (int *)0x0) {
          *param_6 = param_3[6];
        }
        if ((param_5 != (int *)0x0) && (*param_5 == 0)) {
          *param_5 = *(int *)(param_3[5] + 0x18);
        }
        iVar8 = *(int *)(param_3[5] + 0x14);
switchD_c067f314_caseD_6:
switchD_c067f314_default:
        if (param_4 == (int *)0x0) goto LAB_c067f3bc;
        if (param_2 == (int *)0x0) {
          local_5c = 0;
        }
        else {
          local_5c = param_2[6];
        }
        if (param_3 == (int *)0x0) {
          local_54 = 0;
        }
        else {
          local_54 = param_3[6];
        }
        bVar3 = false;
        local_50 = param_3;
        goto LAB_c067f364;
      }
    }
  }
  else {
    if (param_2 == (int *)0x0) {
      bVar3 = false;
    }
    else {
      iVar8 = FUN_c067d338(param_2);
      if (iVar8 == 0) {
        return -0x6fffffed;
      }
      bVar3 = true;
      if (param_5 != (int *)0x0) {
        *param_5 = param_2[8];
      }
      iVar8 = param_2[7];
    }
    if (param_1 != 0x19) {
      if (param_2 == (int *)0x0) {
        iVar8 = -0x6fffffed;
        goto LAB_c067f264;
      }
      if ((param_2[0xb] & 2U) == 0) {
        iVar8 = -0x6fffffe5;
        goto LAB_c067f264;
      }
    }
    if (param_4 == (int *)0x0) {
      return 0;
    }
    if (param_2 == (int *)0x0) {
      local_5c = 0;
    }
    else {
      local_5c = param_2[8];
    }
    local_54 = 0;
    local_50 = (int *)0x0;
LAB_c067f364:
    local_60 = param_1;
    local_58 = param_2;
    if (iVar8 != 0) {
      local_4c = 0;
      local_48 = 0;
      local_44 = param_7;
      local_40 = param_8;
      local_64 = iVar8;
      local_30 = CeGetThreadPriority(0x41);
      iVar8 = FUN_c0682b2c(&uStack_68,param_4);
      piVar5 = param_4;
      if (iVar8 != 0) {
LAB_c067f3bc:
        if (!bVar2) {
          return 0;
        }
        FUN_c0681e1c(param_2,piVar5,piVar6,piVar7);
        return 0;
      }
    }
    iVar8 = -0x7fffffb8;
  }
LAB_c067f254:
  if (bVar1) {
    FUN_c0681e1c(param_2,piVar5,piVar6,piVar7);
  }
LAB_c067f264:
  if (bVar3) {
    FUN_c0681344(param_2);
  }
  if (bVar4) {
    FUN_c068179c(param_3);
  }
  return iVar8;
}



/* c067f3fc FUN_c067f3fc */

/* Boundary evidence: original MIPS .pdata c067f3fc..c067f5df. Semantic name remains unreviewed. */

void FUN_c067f3fc(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  piVar1 = FUN_c0682990(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
  if (piVar1 == (int *)0x0) {
    return;
  }
  FUN_c06833a8(piVar1,param_2,param_3,param_4);
  if (param_2 != 0) {
    FUN_c0682cb8((int)piVar1);
    goto switchD_c067f4c0_caseD_6;
  }
  switch(piVar1[4]) {
  case 5:
  case 0x14:
    iVar2 = FUN_c067cf2c((int *)piVar1[9]);
    if (iVar2 == 0) goto switchD_c067f4c0_caseD_b;
    *(undefined4 *)(piVar1[9] + 0x50) = 2;
    FUN_c067e70c((int *)piVar1[9]);
    FUN_c0681284((HLOCAL)piVar1[9]);
    break;
  default:
    goto switchD_c067f4c0_caseD_6;
  case 9:
  case 0xc:
  case 0xd:
  case 0x15:
    goto LAB_c067f550;
  case 0xb:
switchD_c067f4c0_caseD_b:
    break;
  case 0x10:
    iVar2 = FUN_c067cf2c((int *)piVar1[7]);
    if (iVar2 == 0) goto switchD_c067f4c0_caseD_6;
    *(undefined4 *)(piVar1[7] + 0x68) = 0;
    goto LAB_c067f590;
  }
  iVar2 = FUN_c067e70c((int *)piVar1[7]);
  if (iVar2 == 0) {
LAB_c067f550:
    iVar2 = FUN_c067cf2c((int *)piVar1[7]);
    if (iVar2 != 0) {
      *(undefined4 *)(piVar1[7] + 0x50) = 2;
LAB_c067f590:
      FUN_c0681284((HLOCAL)piVar1[7]);
    }
  }
switchD_c067f4c0_caseD_6:
  FUN_c06828c4(piVar1);
  return;
}



/* c067f5e0 FUN_c067f5e0 */

/* Boundary evidence: original MIPS .pdata c067f5e0..c067f5eb. Semantic name remains unreviewed. */

undefined4 FUN_c067f5e0(void)

{
  return 1;
}



/* c067f5ec FUN_c067f5ec */

/* Boundary evidence: original MIPS .pdata c067f5ec..c067f6cb. Semantic name remains unreviewed. */

void FUN_c067f5ec(int *param_1,int param_2,undefined4 *param_3,int *param_4,uint param_5)

{
  if (param_2 == 0xe) {
LAB_c067f69c:
    FUN_c067ec7c((int)param_1,(int *)0x0,param_2,(uint)param_3,(uint)param_4,param_5);
  }
  else {
    if (param_2 != 0xf) {
      if ((param_2 == 0x10) || (param_2 == 0x12)) goto LAB_c067f69c;
      if (param_2 == 0x14) {
        FUN_c0680b10(param_3,param_4);
        return;
      }
      if (param_2 != 0x1a) {
        return;
      }
      param_1 = FUN_c067c998((int)param_3);
      if (param_1 == (int *)0x0) {
        return;
      }
      FUN_c067ec7c((int)param_1,(int *)0x0,0x1a,(uint)param_3,0,0);
    }
    FUN_c0681da8(param_1);
  }
  return;
}



/* c067f6cc FUN_c067f6cc */

/* Boundary evidence: original MIPS .pdata c067f6cc..c067f85f. Semantic name remains unreviewed. */

void FUN_c067f6cc(int *param_1,int *param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int *hMem;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  iVar5 = param_3;
  piVar6 = param_4;
  iVar1 = FUN_c067cf2c(param_1);
  if (iVar1 != 0) {
    hMem = FUN_c067e044(param_1 + 3);
    if (hMem != (int *)0x0) {
      iVar1 = *hMem;
      piVar8 = hMem;
      while (iVar1 != 0) {
        iVar1 = *piVar8;
        piVar7 = (int *)(iVar1 + -0xc);
        piVar8 = piVar8 + 1;
        if (piVar7 != param_2) {
          iVar4 = 1;
          iVar2 = FUN_c067e31c(piVar7,1);
          if (iVar2 == 0) {
            iVar2 = 0;
            if (*(int *)(iVar1 + 0x1c) == 0) {
              iVar2 = *(int *)(iVar1 + 0x18);
            }
            *(undefined4 *)(iVar1 + 0x1c) = 1;
            iVar3 = FUN_c067d14c(*(int **)(iVar1 + 8));
            if (iVar3 != 0) {
              iVar3 = FUN_c067d02c(*(int **)(*(int *)(iVar1 + 8) + 0x14));
              if (iVar3 != 0) {
                piVar6 = *(int **)(*(int *)(iVar1 + 8) + 0x38);
                iVar5 = param_3;
                FUN_c067bf04(*(int *)(*(int *)(iVar1 + 8) + 0x14) + 0x18,(int)piVar7,param_3,
                             (int)piVar6,(int)param_4,param_5,iVar2);
                iVar4 = *(int *)(iVar1 + 8);
                FUN_c06825a0(*(undefined4 **)(iVar4 + 0x14),iVar4,iVar5,piVar6);
              }
              FUN_c0681e1c(*(HLOCAL *)(iVar1 + 8),iVar4,iVar5,piVar6);
            }
            FUN_c068179c(piVar7);
          }
        }
        iVar1 = *piVar8;
      }
      LocalFree(hMem);
    }
    if ((param_3 == 2) && (param_4 != (int *)0x1)) {
      FUN_c067edf0(param_1,(int *)param_1[8],param_4,param_5);
    }
    FUN_c0681284(param_1);
  }
  return;
}



/* c067f860 FUN_c067f860 */

/* Boundary evidence: original MIPS .pdata c067f860..c067fe47. Semantic name remains unreviewed. */

void FUN_c067f860(int *param_1,int *param_2,uint param_3,int *param_4,int *param_5,int *param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int *local_38;
  int *local_2c;
  
  bVar1 = false;
  local_2c = (int *)0x0;
  bVar3 = false;
  bVar2 = false;
  if (0x19 < param_3) {
    if (((param_3 != 500) || (iVar4 = FUN_c067ce04(param_1 + 1,&DAT_c0686180), iVar4 == 0)) ||
       (param_2 = FUN_c0680084((int)param_1), local_38 = param_2, param_2 == (int *)0x0))
    goto switchD_c067f8f4_caseD_5;
    param_2[0x12] = 0;
    param_2[9] = (int)param_4;
    param_2[0x14] = 2;
    FUN_c067e70c(param_2);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    if (param_1[0xf] == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
LAB_c067fdc8:
      FUN_c067d570((int)param_2);
      goto switchD_c067f8f4_caseD_5;
    }
    *param_5 = (int)param_2;
LAB_c067fdac:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
    goto switchD_c067f8f4_caseD_5;
  }
  if (param_3 == 0x19) {
    param_1 = FUN_c067c75c((int)param_4);
    if (param_1 == (int *)0x0) goto switchD_c067f8f4_caseD_5;
    param_3 = 0x19;
    piVar5 = (int *)0x0;
    FUN_c067eb1c((int)param_1,(int *)0x0,0x19,(uint)param_4,0,0);
LAB_c067fb1c:
    FUN_c06827f0(param_1,piVar5,param_3,(int)param_4);
  }
  else {
    switch(param_3) {
    case 0:
    case 4:
    case 8:
      FUN_c067eb1c((int)param_1,(int *)0x0,param_3,(uint)param_4,(uint)param_5,(int)param_6);
      break;
    case 1:
      iVar4 = FUN_c067cf2c(param_2);
      if (iVar4 != 0) {
        bVar2 = true;
        FUN_c067f6cc(param_2,(int *)0x0,1,param_4,(int)param_5);
      }
      break;
    case 2:
      piVar5 = param_4;
      iVar4 = FUN_c067ce04(param_1 + 1,&DAT_c0686180);
      if ((iVar4 == 0) || (iVar4 = FUN_c067cf2c(param_2), iVar4 == 0)) break;
      param_2[0x18] = (int)param_4;
      param_2[0x19] = (int)param_5;
      bVar2 = true;
      if (param_4 == (int *)0x2) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
        if (param_2[0x17] == 0x80) goto LAB_c067fdac;
        param_2[0x17] = 0x80;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c068614c);
        if (param_6 == (int *)0x0) {
          param_6 = (int *)0x2;
        }
        uVar6 = 4;
        piVar7 = param_6;
        local_38 = FUN_c067e894(param_2,param_6,4,piVar5);
        if (local_38 == (int *)0x0) {
          uVar6 = 2;
          local_38 = FUN_c067e894(param_2,param_6,2,piVar5);
          piVar7 = param_6;
          if (local_38 == (int *)0x0) goto LAB_c067fdc8;
        }
        bVar1 = true;
        param_2[0x12] = 1;
        iVar4 = FUN_c067d14c((int *)local_38[5]);
        if (iVar4 != 0) {
          iVar4 = FUN_c067d02c(*(int **)(local_38[5] + 0x14));
          if (iVar4 != 0) {
            piVar7 = (int *)local_38[5];
            piVar5 = (int *)piVar7[0xe];
            uVar6 = 0x17;
            FUN_c067bf04(piVar7[5] + 0x18,(int)piVar7,0x17,(int)piVar5,param_2[0x11],(int)local_38,
                         piVar7[10]);
            FUN_c06825a0(*(undefined4 **)(local_38[5] + 0x14),piVar7,uVar6,piVar5);
          }
          FUN_c0681e1c((HLOCAL)local_38[5],piVar7,uVar6,piVar5);
        }
      }
      if (param_4 == (int *)0x100) {
        if (((int *)param_2[0x1a] != (int *)0x0) && (param_2 != (int *)param_2[0x1a])) {
          param_2[0x1a] = 0;
        }
      }
      else if (param_4 == (int *)0x800) {
        local_2c = param_5;
        iVar4 = FUN_c067cf2c(param_5);
        if (iVar4 != 0) {
          bVar3 = true;
          param_2[0x1a] = (int)param_5;
        }
      }
      FUN_c067f6cc(param_2,(int *)0x0,2,param_4,(int)param_5);
      break;
    case 3:
      piVar5 = param_2;
      goto LAB_c067fb1c;
    case 7:
      local_38 = param_5;
      piVar5 = (int *)0x4;
      piVar7 = param_4;
      iVar4 = FUN_c067e31c(param_5,4);
      if (iVar4 == 0) {
        bVar1 = true;
        iVar4 = FUN_c067d14c((int *)param_5[5]);
        if (iVar4 != 0) {
          iVar4 = FUN_c067d02c(*(int **)(param_5[5] + 0x14));
          if (iVar4 != 0) {
            if (param_6 == (int *)0x0) {
              param_6 = (int *)GetTickCount();
            }
            piVar7 = *(int **)(param_5[5] + 0x38);
            param_3 = 7;
            piVar5 = param_5;
            FUN_c067bf04(*(int *)(param_5[5] + 0x14) + 0x18,(int)param_5,7,(int)piVar7,(int)param_4,
                         0,(int)param_6);
            FUN_c06825a0(*(undefined4 **)(param_5[5] + 0x14),piVar5,param_3,piVar7);
          }
          FUN_c0681e1c((HLOCAL)param_5[5],piVar5,param_3,piVar7);
        }
      }
      break;
    case 9:
    case 10:
      iVar4 = FUN_c067cf2c(param_2);
      if (iVar4 != 0) {
        bVar2 = true;
        if (param_6 == (int *)0x0) {
          GetTickCount();
        }
        FUN_c067f6cc(param_2,(int *)0x0,param_3,param_4,(int)param_5);
      }
      break;
    case 0x13:
      FUN_c06806f8(param_4,param_5);
    }
  }
switchD_c067f8f4_caseD_5:
  if (bVar1) {
    FUN_c068179c(local_38);
  }
  if (bVar2) {
    FUN_c0681284(param_2);
  }
  if (bVar3) {
    FUN_c0681284(local_2c);
  }
  return;
}



/* c067fe48 FUN_c067fe48 */

/* Boundary evidence: original MIPS .pdata c067fe48..c067fe53. Semantic name remains unreviewed. */

undefined4 FUN_c067fe48(void)

{
  return 1;
}



/* c067fe54 FUN_c067fe54 */

/* Boundary evidence: original MIPS .pdata c067fe54..c067ffc7. Semantic name remains unreviewed. */

undefined4 FUN_c067fe54(wchar_t *param_1,int param_2,int param_3,undefined4 *param_4)

{
  size_t sVar1;
  int *hMem;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  
  *param_4 = 0;
  sVar1 = wcslen(param_1);
  hMem = LocalAlloc(0x40,(sVar1 + 0x11) * 2);
  if (hMem == (int *)0x0) {
    uVar2 = 0x80000044;
  }
  else {
    hMem[2] = param_2;
    wcscpy((wchar_t *)(hMem + 7),param_1);
    hMem[6] = param_3;
    iVar3 = (**(code **)(param_3 + 0x94))(0xffffffff,0x20000,0x20010,hMem + 5);
    if ((iVar3 == 0) &&
       (iVar3 = (**(code **)(hMem[6] + 0xf8))(hMem[5],0,0,0,0,0,FUN_c067f3fc,hMem + 4), iVar3 == 0))
    {
      FUN_c067bbb8(&DAT_c0686160,hMem,(LPCRITICAL_SECTION)&DAT_c068614c);
      (**(code **)(hMem[6] + 0x108))(0,auStack_1c,auStack_20,hMem,FUN_c067f860,FUN_c067f5ec);
      *param_4 = hMem;
      return 0;
    }
    FreeLibrary((HMODULE)hMem[2]);
    LocalFree(hMem);
    uVar2 = 0x80000048;
  }
  return uVar2;
}



/* c067ffc8 FUN_c067ffc8 */

void FUN_c067ffc8(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 4);
  piVar1 = (int *)(param_1 + 0xc);
  **(int **)(param_1 + 8) = *piVar2;
  *(undefined4 *)(*piVar2 + 4) = *(undefined4 *)(param_1 + 8);
  **(int **)(param_1 + 0x10) = *piVar1;
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x10);
  *(int **)(param_1 + 8) = piVar2;
  *piVar2 = (int)piVar2;
  *(int **)(param_1 + 0x10) = piVar1;
  *piVar1 = (int)piVar1;
  return;
}



/* c0680014 FUN_c0680014 */

void FUN_c0680014(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 4);
  piVar2 = (int *)(param_1 + 0xc);
  **(int **)(param_1 + 8) = *piVar3;
  piVar1 = (int *)(param_1 + 0x14);
  *(undefined4 *)(*piVar3 + 4) = *(undefined4 *)(param_1 + 8);
  **(int **)(param_1 + 0x10) = *piVar2;
  *(undefined4 *)(*piVar2 + 4) = *(undefined4 *)(param_1 + 0x10);
  **(int **)(param_1 + 0x18) = *piVar1;
  *(undefined4 *)(*piVar1 + 4) = *(undefined4 *)(param_1 + 0x18);
  *(int **)(param_1 + 8) = piVar3;
  *piVar3 = (int)piVar3;
  *(int **)(param_1 + 0x10) = piVar2;
  *piVar2 = (int)piVar2;
  *(int **)(param_1 + 0x18) = piVar1;
  *piVar1 = (int)piVar1;
  return;
}



/* c0680084 FUN_c0680084 */

/* Boundary evidence: original MIPS .pdata c0680084..c0680137. Semantic name remains unreviewed. */

undefined4 * FUN_c0680084(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = LocalAlloc(0x40,0x6c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    DAT_c06861fc = DAT_c06861fc + 1;
    puVar1[10] = 1;
    puVar1[0x12] = 1;
    puVar2 = puVar1 + 3;
    *puVar1 = 0x4c4c4143;
    puVar1[4] = puVar2;
    *puVar2 = puVar2;
    puVar1[0x11] = 0xffffffff;
    puVar1[0x18] = 0x8000;
    puVar1[8] = param_1;
    puVar1[6] = *(undefined4 *)(param_1 + 0x14);
    FUN_c067bbb8(&DAT_c0686170,puVar1 + 1,(LPCRITICAL_SECTION)&DAT_c068614c);
  }
  return puVar1;
}



/* c0680138 FUN_c0680138 */

/* Boundary evidence: original MIPS .pdata c0680138..c068035b. Semantic name remains unreviewed. */

void FUN_c0680138(HLOCAL param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int *hMem;
  undefined3 extraout_var;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if (*(int *)((int)param_1 + 0x14) == 0) {
    *(undefined4 *)((int)param_1 + 0x14) = 1;
    hMem = FUN_c067e044((undefined4 *)((int)param_1 + 0xc));
    piVar4 = (int *)((int)param_1 + 4);
    **(int **)((int)param_1 + 8) = *piVar4;
    *(undefined4 *)(*piVar4 + 4) = *(undefined4 *)((int)param_1 + 8);
    *(int **)((int)param_1 + 8) = piVar4;
    *piVar4 = (int)piVar4;
    if (hMem != (int *)0x0) {
      iVar2 = *hMem;
      piVar4 = hMem;
      while (iVar2 != 0) {
        piVar3 = (int *)*piVar4;
        if (piVar3[0xb] == 0) {
          piVar3[0xb] = 1;
          piVar3[3] = 0;
        }
        else {
          *piVar4 = 1;
        }
        piVar5 = piVar3 + -2;
        *(int *)piVar3[-1] = *piVar5;
        piVar4 = piVar4 + 1;
        *(int *)(*piVar5 + 4) = piVar3[-1];
        *(int *)piVar3[1] = *piVar3;
        *(int *)(*piVar3 + 4) = piVar3[1];
        piVar3[-1] = (int)piVar5;
        *piVar5 = (int)piVar5;
        piVar3[1] = (int)piVar3;
        *piVar3 = (int)piVar3;
        iVar2 = *piVar4;
      }
    }
    iVar2 = FUN_c067bc40();
    *param_2 = iVar2;
    if (hMem != (int *)0x0) {
      iVar2 = *hMem;
      piVar4 = hMem;
      while (iVar2 != 0) {
        iVar2 = *piVar4;
        piVar4 = piVar4 + 1;
        if (iVar2 != 1) {
          FUN_c068179c((HLOCAL)(iVar2 + -0xc));
        }
        iVar2 = *piVar4;
      }
      LocalFree(hMem);
    }
    iVar2 = *(int *)((int)param_1 + 0x50);
    while ((iVar2 == 1 && (*(int *)((int)param_1 + 0x24) == 0))) {
      Sleep(100);
      iVar2 = *(int *)((int)param_1 + 0x50);
    }
    if (*(int *)((int)param_1 + 0x24) != 0) {
      iVar2 = FUN_c067bc18();
      *param_2 = iVar2;
      bVar1 = FUN_c067d110(*(int *)((int)param_1 + 0x20));
      if ((CONCAT31(extraout_var,bVar1) != 0) &&
         (*(int *)(*(int *)((int)param_1 + 0x20) + 0x3c) != 0)) {
        iVar2 = FUN_c067bc40();
        *param_2 = iVar2;
        (**(code **)(*(int *)(*(int *)((int)param_1 + 0x18) + 0x18) + 0x14))
                  (*(undefined4 *)((int)param_1 + 0x24));
      }
      if (*param_2 != 0) {
        iVar2 = FUN_c067bc40();
        *param_2 = iVar2;
      }
    }
    LocalFree(param_1);
    DAT_c06861fc = DAT_c06861fc + -1;
  }
  else {
    iVar2 = FUN_c067bc40();
    *param_2 = iVar2;
  }
  return;
}



/* c068035c FUN_c068035c */

/* Boundary evidence: original MIPS .pdata c068035c..c06806eb. Semantic name remains unreviewed. */

int FUN_c068035c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  undefined4 *hMem;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  *param_8 = 0;
  hMem = LocalAlloc(0x40,0x4c);
  if (hMem == (undefined4 *)0x0) {
    return -0x7fffffb8;
  }
  hMem[7] = 1;
  hMem[5] = param_2;
  *hMem = 0xca;
  hMem[8] = param_3;
  hMem[9] = param_4;
  hMem[10] = param_5;
  hMem[0xd] = param_6;
  hMem[6] = param_1;
  hMem[0xe] = param_7;
  piVar5 = hMem + 1;
  hMem[2] = piVar5;
  *piVar5 = (int)piVar5;
  piVar6 = hMem + 3;
  hMem[4] = piVar6;
  *piVar6 = (int)piVar6;
  hMem[0xf] = 1;
  iVar1 = FUN_c067bc18();
  iVar4 = 0;
  if (*(int *)(hMem[5] + 0x14) == 0) {
    *piVar5 = (int)DAT_c0686188;
    hMem[2] = &DAT_c0686188;
    DAT_c0686188[1] = (int)piVar5;
    piVar3 = (int *)(param_1 + 0xc);
    DAT_c0686188 = piVar5;
    *piVar6 = *piVar3;
    hMem[4] = piVar3;
    *(int **)(*piVar3 + 4) = piVar6;
    *piVar3 = (int)piVar6;
    *(short *)(param_1 + 0x38) = *(short *)(param_1 + 0x38) + 1;
    if (*(int *)(param_1 + 0x3c) != 0) {
      if (*(int *)(param_1 + 0x18) == 0) {
        do {
          if (*(int *)(param_1 + 0x18) != 0) break;
          FUN_c067bc40();
          Sleep(100);
          iVar1 = FUN_c067bc18();
        } while (*(int *)(param_1 + 0x3c) != 0);
      }
      goto LAB_c0680610;
    }
    *(undefined4 *)(param_1 + 0x3c) = 1;
    FUN_c067bc40();
    iVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 0x18) + 0x98))
                      (*(undefined4 *)(param_1 + 0x1c),param_1,param_1 + 0x18,
                       *(undefined4 *)(param_1 + 0x2c),FUN_c067f860);
    iVar1 = FUN_c067bc18();
    iVar4 = 0;
    if (iVar2 == 0) goto LAB_c0680610;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(short *)(param_1 + 0x38) = *(short *)(param_1 + 0x38) + -1;
    *(int *)hMem[2] = *piVar5;
    *(undefined4 *)(*piVar5 + 4) = hMem[2];
    *(int *)hMem[4] = *piVar6;
    *(undefined4 *)(*piVar6 + 4) = hMem[4];
    hMem[2] = piVar5;
    *piVar5 = (int)piVar5;
    hMem[4] = piVar6;
    *piVar6 = (int)piVar6;
    iVar1 = FUN_c067bc40();
    LocalFree(hMem);
  }
  else {
    LocalFree(hMem);
  }
  iVar4 = -0x7fffffb8;
LAB_c0680610:
  if (iVar1 != 0) {
    FUN_c067bc40();
  }
  if (iVar4 == 0) {
    if ((param_4 != 0) &&
       (iVar1 = *(int *)(param_1 + 0x34), *(int *)(param_1 + 0x34) = iVar1 + 1, iVar1 == 0)) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 0x18) + 0xb4))
                (*(undefined4 *)(param_1 + 0x18),param_4);
    }
    *param_8 = hMem;
    DAT_c0686208 = DAT_c0686208 + 1;
  }
  return iVar4;
}



/* c06806ec FUN_c06806ec */

/* Boundary evidence: original MIPS .pdata c06806ec..c06806f7. Semantic name remains unreviewed. */

undefined4 FUN_c06806ec(void)

{
  return 1;
}



/* c06806f8 FUN_c06806f8 */

/* Boundary evidence: original MIPS .pdata c06806f8..c0680863. Semantic name remains unreviewed. */

void FUN_c06806f8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_c067d008(param_1);
  if ((iVar1 == 0) || (puVar2 = LocalAlloc(0x40,0x44), puVar2 == (undefined4 *)0x0)) {
    *param_2 = -1;
  }
  else {
    *puVar2 = 0x454e494c;
    puVar3 = puVar2 + 3;
    puVar2[4] = puVar3;
    *puVar3 = puVar3;
    iVar1 = DAT_c06861c4;
    puVar2[7] = DAT_c06861c4;
    *param_2 = iVar1;
    puVar2[5] = param_1;
    (**(code **)(param_1[6] + 0x94))(puVar2[7],0x20000,0x20010,puVar2 + 0xb);
    FUN_c067bbb8(&DAT_c0686180,puVar2 + 1,(LPCRITICAL_SECTION)&DAT_c068614c);
    DAT_c06861c4 = DAT_c06861c4 + 1;
    FUN_c067bc18();
    puVar3 = DAT_c0686190;
    while ((undefined4 **)puVar3 != &DAT_c0686190) {
      puVar4 = (undefined4 *)*puVar3;
      FUN_c067bf04((int)(puVar3 + 5),0,0x13,0,puVar2[7],0,0);
      puVar3 = puVar4;
    }
    FUN_c067bc40();
  }
  return;
}



/* c0680864 FUN_c0680864 */

/* Boundary evidence: original MIPS .pdata c0680864..c068086f. Semantic name remains unreviewed. */

undefined4 FUN_c0680864(void)

{
  return 1;
}



/* c0680870 FUN_c0680870 */

/* Boundary evidence: original MIPS .pdata c0680870..c068095b. Semantic name remains unreviewed. */

HANDLE FUN_c0680870(undefined4 param_1,int *param_2,int param_3)

{
  HANDLE hObject;
  DWORD DVar1;
  wchar_t *pwVar2;
  wchar_t awStack_90 [64];
  uint local_10;
  
  local_10 = DAT_c068610c;
  *param_2 = DAT_c06861cc;
  DAT_c06861cc = DAT_c06861cc + 1;
  if (param_3 == 0) {
    pwVar2 = L"PHONE";
  }
  else {
    pwVar2 = L"LINE";
  }
  StringCchPrintfW(awStack_90,0x40,L"TAPI%s%08lx",pwVar2,*param_2);
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,awStack_90);
  if (hObject != (HANDLE)0x0) {
    DVar1 = GetLastError();
    if (DVar1 != 0xb7) {
      FUN_c0684adc(local_10);
      return hObject;
    }
    CloseHandle(hObject);
  }
  FUN_c0684adc(local_10);
  return (HANDLE)0x0;
}



/* c068095c FUN_c068095c */

/* Boundary evidence: original MIPS .pdata c068095c..c0680a5f. Semantic name remains unreviewed. */

undefined4 * FUN_c068095c(wchar_t *param_1,int *param_2)

{
  size_t sVar1;
  undefined4 *hMem;
  HANDLE pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  if (param_1 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_1);
    iVar5 = (sVar1 + 1) * 2;
    hMem = LocalAlloc(0x40,iVar5 + 0x48);
    if (hMem != (undefined4 *)0x0) {
      hMem[0xf] = 1;
      hMem[0x10] = iVar5;
      wcscpy((wchar_t *)(hMem + 0x11),param_1);
      pvVar2 = FUN_c0680870(hMem,param_2,1);
      if (pvVar2 != (HANDLE)0x0) {
        puVar4 = hMem + 6;
        hMem[8] = pvVar2;
        hMem[9] = 0;
        hMem[7] = puVar4;
        *puVar4 = puVar4;
        *hMem = 0xcb;
        hMem[4] = 0x20000;
        uVar3 = GetCallerProcess();
        hMem[3] = uVar3;
        FUN_c067bbb8(&DAT_c0686190,hMem + 1,(LPCRITICAL_SECTION)&DAT_c068614c);
        DAT_c06861c8 = DAT_c06861c8 + 1;
        return hMem;
      }
      LocalFree(hMem);
    }
  }
  return (undefined4 *)0x0;
}



/* c0680a60 FUN_c0680a60 */

/* Boundary evidence: original MIPS .pdata c0680a60..c0680b0f. Semantic name remains unreviewed. */

int FUN_c0680a60(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar1 = FUN_c067bc18();
  *param_2 = uVar1;
  while (piVar2 = (int *)*param_1, piVar2 != param_1) {
    *(int **)(*piVar2 + 4) = param_1;
    *param_1 = *piVar2;
    FUN_c067be20(piVar2);
    iVar3 = iVar3 + 1;
  }
  if (param_1[2] != 0) {
    param_1[3] = param_1[2];
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    EventModify(param_1[3],3);
    CloseHandle((HANDLE)param_1[3]);
  }
  uVar1 = FUN_c067bc40();
  *param_2 = uVar1;
  return iVar3;
}



/* c0680b10 FUN_c0680b10 */

/* Boundary evidence: original MIPS .pdata c0680b10..c0680c77. Semantic name remains unreviewed. */

void FUN_c0680b10(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_c067d008(param_1);
  if ((iVar1 == 0) || (puVar2 = LocalAlloc(0x40,0x48), puVar2 == (undefined4 *)0x0)) {
    *param_2 = -1;
  }
  else {
    *puVar2 = 0x4e4f4850;
    puVar3 = puVar2 + 3;
    puVar2[4] = puVar3;
    *puVar3 = puVar3;
    iVar1 = DAT_c06861d8;
    puVar2[7] = DAT_c06861d8;
    *param_2 = iVar1;
    puVar2[5] = param_1;
    (**(code **)(param_1[6] + 0x15c))(puVar2[7],0x20000,0x20000,puVar2 + 0xb);
    FUN_c067bbb8(&DAT_c0686198,puVar2 + 1,(LPCRITICAL_SECTION)&DAT_c068614c);
    DAT_c06861d8 = DAT_c06861d8 + 1;
    FUN_c067bc18();
    puVar3 = DAT_c06861a8;
    while ((undefined4 **)puVar3 != &DAT_c06861a8) {
      puVar4 = (undefined4 *)*puVar3;
      FUN_c067bf04((int)(puVar3 + 8),0,0x14,0,puVar2[7],0,0);
      puVar3 = puVar4;
    }
    FUN_c067bc40();
  }
  return;
}



/* c0680c78 FUN_c0680c78 */

/* Boundary evidence: original MIPS .pdata c0680c78..c0680c83. Semantic name remains unreviewed. */

undefined4 FUN_c0680c78(void)

{
  return 1;
}



/* c0680c84 FUN_c0680c84 */

/* Boundary evidence: original MIPS .pdata c0680c84..c0680f3f. Semantic name remains unreviewed. */

undefined4
FUN_c0680c84(int param_1,int param_2,int param_3,uint param_4,undefined4 param_5,undefined4 *param_6
            )

{
  undefined4 *hMem;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  *param_6 = 0;
  hMem = LocalAlloc(0x40,0x48);
  if (hMem == (undefined4 *)0x0) {
LAB_c0680e30:
    uVar2 = 0x9000001c;
  }
  else {
    hMem[9] = 1;
    hMem[7] = param_2;
    *hMem = 0xcd;
    hMem[10] = param_3;
    hMem[0xb] = param_4;
    hMem[8] = param_1;
    hMem[0xc] = param_5;
    hMem[0x10] = 1;
    FUN_c067bc18();
    puVar5 = hMem + 1;
    *puVar5 = DAT_c06861a0;
    hMem[2] = &DAT_c06861a0;
    DAT_c06861a0[1] = puVar5;
    piVar4 = hMem + 3;
    piVar3 = (int *)(param_1 + 0xc);
    DAT_c06861a0 = puVar5;
    *piVar4 = *piVar3;
    hMem[4] = piVar3;
    *(int **)(*piVar3 + 4) = piVar4;
    *piVar3 = (int)piVar4;
    piVar4 = hMem + 5;
    piVar3 = (int *)(param_2 + 0xc);
    *piVar4 = *piVar3;
    hMem[6] = piVar3;
    *(int **)(*piVar3 + 4) = piVar4;
    *piVar3 = (int)piVar4;
    FUN_c067bc40();
    if (*(int *)(param_1 + 0x44) == 0) {
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 0x18) + 0x160))
                        (*(undefined4 *)(param_1 + 0x1c),param_1,param_1 + 0x18,
                         *(undefined4 *)(param_1 + 0x2c),FUN_c067f5ec);
      if (iVar1 != 0) {
        FUN_c067bc18();
        FUN_c0680014((int)hMem);
        FUN_c067bc40();
        LocalFree(hMem);
        goto LAB_c0680e30;
      }
      *(undefined4 *)(param_1 + 0x44) = 1;
    }
    *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
    if ((param_4 & 2) == 0) {
      puVar5 = hMem;
      puVar6 = hMem;
      if ((param_4 & 1) != 0) {
        puVar5 = (undefined4 *)(*(int *)(param_1 + 0x3c) + 1);
        *(undefined4 **)(param_1 + 0x3c) = puVar5;
        puVar6 = (undefined4 *)0x10;
      }
    }
    else {
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0x38) + 1);
      *(undefined4 **)(param_1 + 0x38) = puVar5;
      puVar6 = (undefined4 *)0x8;
    }
    if ((param_3 != 0) &&
       (iVar1 = *(int *)(param_1 + 0x34), *(int *)(param_1 + 0x34) = iVar1 + 1, iVar1 == 0)) {
      (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 0x18) + 0x164))
                (*(undefined4 *)(param_1 + 0x18),param_3);
    }
    FUN_c067ec7c(param_1,(int *)0x0,0x12,(uint)puVar6,(uint)puVar5,0);
    *param_6 = hMem;
    uVar2 = 0;
  }
  return uVar2;
}



/* c0680f40 FUN_c0680f40 */

/* Boundary evidence: original MIPS .pdata c0680f40..c0680f4b. Semantic name remains unreviewed. */

undefined4 FUN_c0680f40(void)

{
  return 1;
}



/* c0680f4c FUN_c0680f4c */

/* Boundary evidence: original MIPS .pdata c0680f4c..c0680f57. Semantic name remains unreviewed. */

undefined4 FUN_c0680f4c(void)

{
  return 1;
}



/* c0680f58 FUN_c0680f58 */

/* Boundary evidence: original MIPS .pdata c0680f58..c0681173. Semantic name remains unreviewed. */

void FUN_c0680f58(HLOCAL param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_20;
  
  if (*(int *)((int)param_1 + 0x44) == 0) {
    *(undefined4 *)((int)param_1 + 0x44) = 1;
    piVar5 = (int *)((int)param_1 + 4);
    iVar1 = *(int *)((int)param_1 + 0x20);
    **(int **)((int)param_1 + 8) = *piVar5;
    piVar4 = (int *)((int)param_1 + 0xc);
    *(undefined4 *)(*piVar5 + 4) = *(undefined4 *)((int)param_1 + 8);
    piVar3 = (int *)((int)param_1 + 0x14);
    **(int **)((int)param_1 + 0x10) = *piVar4;
    *(undefined4 *)(*piVar4 + 4) = *(undefined4 *)((int)param_1 + 0x10);
    **(int **)((int)param_1 + 0x18) = *piVar3;
    *(undefined4 *)(*piVar3 + 4) = *(undefined4 *)((int)param_1 + 0x18);
    *(int **)((int)param_1 + 8) = piVar5;
    *piVar5 = (int)piVar5;
    *(int **)((int)param_1 + 0x10) = piVar4;
    *piVar4 = (int)piVar4;
    *(int **)((int)param_1 + 0x18) = piVar3;
    *piVar3 = (int)piVar3;
    if ((*(int *)((int)param_1 + 0x28) != 0) &&
       (iVar2 = *(int *)(iVar1 + 0x34) + -1, *(int *)(iVar1 + 0x34) = iVar2, iVar2 == 0)) {
      iVar2 = FUN_c067bc40();
      *param_2 = iVar2;
      (**(code **)(*(int *)(*(int *)(iVar1 + 0x14) + 0x18) + 0x164))
                (*(undefined4 *)(iVar1 + 0x18),0);
      iVar2 = FUN_c067bc18();
      *param_2 = iVar2;
    }
    uVar6 = 0;
    iVar2 = FUN_c067d310(iVar1);
    if (iVar2 != 0) {
      *(short *)(iVar1 + 0x40) = *(short *)(iVar1 + 0x40) + -1;
      if ((*(uint *)((int)param_1 + 0x2c) & 2) == 0) {
        if ((*(uint *)((int)param_1 + 0x2c) & 1) != 0) {
          local_20 = *(int *)(iVar1 + 0x3c) - 1;
          *(uint *)(iVar1 + 0x3c) = local_20;
          uVar6 = 0x10;
        }
      }
      else {
        local_20 = *(int *)(iVar1 + 0x38) - 1;
        *(uint *)(iVar1 + 0x38) = local_20;
        uVar6 = 8;
      }
    }
    if (*(short *)(iVar1 + 0x40) == 0) {
      if (*(int *)(iVar1 + 0x44) != 0) {
        uVar7 = *(undefined4 *)(iVar1 + 0x18);
        *(undefined4 *)(iVar1 + 0x18) = 0;
        *(undefined4 *)(iVar1 + 0x44) = 0;
        iVar2 = FUN_c067bc40();
        *param_2 = iVar2;
        (**(code **)(*(int *)(*(int *)(iVar1 + 0x14) + 0x18) + 0x128))(uVar7);
      }
    }
    else if (uVar6 != 0) {
      FUN_c067ec7c(iVar1,(int *)0x0,0x12,uVar6,local_20,0);
    }
    if (*param_2 != 0) {
      iVar1 = FUN_c067bc40();
      *param_2 = iVar1;
    }
    FUN_c0682d74(0,(int)param_1,0);
    LocalFree(param_1);
  }
  else {
    iVar1 = FUN_c067bc40();
    *param_2 = iVar1;
  }
  return;
}



/* c0681174 FUN_c0681174 */

/* Boundary evidence: original MIPS .pdata c0681174..c0681283. Semantic name remains unreviewed. */

undefined4 * FUN_c0681174(wchar_t *param_1,int *param_2)

{
  size_t sVar1;
  undefined4 *hMem;
  HANDLE pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  if (param_1 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_1);
    iVar6 = (sVar1 + 1) * 2;
    hMem = LocalAlloc(0x40,iVar6 + 0x3c);
    if (hMem != (undefined4 *)0x0) {
      hMem[6] = 1;
      hMem[0xd] = iVar6;
      wcscpy((wchar_t *)(hMem + 0xe),param_1);
      pvVar2 = FUN_c0680870(hMem,param_2,0);
      if (pvVar2 != (HANDLE)0x0) {
        puVar4 = hMem + 3;
        puVar5 = hMem + 9;
        hMem[0xb] = pvVar2;
        hMem[0xc] = 0;
        hMem[4] = puVar4;
        *puVar4 = puVar4;
        hMem[10] = puVar5;
        *puVar5 = puVar5;
        *hMem = 0xce;
        hMem[7] = 0x20000;
        uVar3 = GetCallerProcess();
        hMem[5] = uVar3;
        FUN_c067bbb8(&DAT_c06861a8,hMem + 1,(LPCRITICAL_SECTION)&DAT_c068614c);
        DAT_c06861dc = DAT_c06861dc + 1;
        return hMem;
      }
      LocalFree(hMem);
    }
  }
  return (undefined4 *)0x0;
}



/* c0681284 FUN_c0681284 */

/* Boundary evidence: original MIPS .pdata c0681284..c0681337. Semantic name remains unreviewed. */

undefined4 FUN_c0681284(HLOCAL param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((*(int *)((int)param_1 + 0x28) != 0) &&
     (iVar1 = *(int *)((int)param_1 + 0x28) + -1, *(int *)((int)param_1 + 0x28) = iVar1, iVar1 == 0)
     ) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c0680138(param_1,local_18);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c0681338 FUN_c0681338 */

/* Boundary evidence: original MIPS .pdata c0681338..c0681343. Semantic name remains unreviewed. */

undefined4 FUN_c0681338(void)

{
  return 1;
}



/* c0681344 FUN_c0681344 */

/* Boundary evidence: original MIPS .pdata c0681344..c06813f7. Semantic name remains unreviewed. */

undefined4 FUN_c0681344(HLOCAL param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((*(int *)((int)param_1 + 0x24) != 0) &&
     (iVar1 = *(int *)((int)param_1 + 0x24) + -1, *(int *)((int)param_1 + 0x24) = iVar1, iVar1 == 0)
     ) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c0680f58(param_1,local_18);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c06813f8 FUN_c06813f8 */

/* Boundary evidence: original MIPS .pdata c06813f8..c0681403. Semantic name remains unreviewed. */

undefined4 FUN_c06813f8(void)

{
  return 1;
}



/* c0681404 FUN_c0681404 */

/* Boundary evidence: original MIPS .pdata c0681404..c06815f3. Semantic name remains unreviewed. */

void FUN_c0681404(HLOCAL param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(int *)((int)param_1 + 0x34) == 0) {
    piVar8 = *(int **)((int)param_1 + 0x18);
    *(undefined4 *)((int)param_1 + 0x34) = 1;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    iVar4 = FUN_c067cf2c(piVar8);
    if ((iVar4 == 0) || (piVar8[5] != 0)) {
      bVar2 = false;
      iVar4 = 0;
    }
    else {
      bVar2 = true;
      iVar4 = 2;
    }
    piVar7 = (int *)((int)param_1 + 4);
    piVar6 = (int *)((int)param_1 + 0xc);
    **(int **)((int)param_1 + 8) = *piVar7;
    bVar1 = false;
    *(undefined4 *)(*piVar7 + 4) = *(undefined4 *)((int)param_1 + 8);
    **(int **)((int)param_1 + 0x10) = *piVar6;
    *(undefined4 *)(*piVar6 + 4) = *(undefined4 *)((int)param_1 + 0x10);
    *(int **)((int)param_1 + 8) = piVar7;
    *piVar7 = (int)piVar7;
    *(int **)((int)param_1 + 0x10) = piVar6;
    *piVar6 = (int)piVar6;
    if (bVar2) {
      if ((*(uint *)((int)param_1 + 0x24) & 4) == 0) {
        if ((*(uint *)((int)param_1 + 0x24) & 2) != 0) {
          piVar8[0xe] = piVar8[0xe] + -1;
        }
      }
      else {
        piVar8[0xd] = piVar8[0xd] + -1;
      }
      if ((int *)piVar8[3] == piVar8 + 3) {
        bVar1 = true;
      }
    }
    uVar3 = FUN_c067bc40();
    *param_2 = uVar3;
    if (bVar2) {
      if (bVar1) {
        FUN_c067d570((int)piVar8);
      }
      else {
        piVar6 = (int *)0x1000;
        if (*(int *)((int)param_1 + 0x24) != 4) {
          piVar6 = (int *)0x2000;
        }
        FUN_c067f6cc(piVar8,(int *)0x0,1,piVar6,0);
      }
    }
    while ((iVar4 != 0 && (iVar5 = FUN_c0681284(piVar8), iVar5 == 0))) {
      iVar4 = iVar4 + -1;
    }
    FUN_c0682d74(0,0,(int)param_1);
    LocalFree(param_1);
    DAT_c0686200 = DAT_c0686200 + -1;
  }
  else {
    uVar3 = FUN_c067bc40();
    *param_2 = uVar3;
  }
  return;
}



/* c06815f4 FUN_c06815f4 */

/* Boundary evidence: original MIPS .pdata c06815f4..c068179b. Semantic name remains unreviewed. */

void FUN_c06815f4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *hMem;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (param_1[8] == 0) {
    *(undefined4 *)param_1[2] = param_1[1];
    *(undefined4 *)(param_1[1] + 4) = param_1[2];
    param_1[8] = 1;
    *param_1 = 0;
    if (param_1[0xb] != 0) {
      param_1[0xc] = param_1[0xb];
      param_1[0xb] = 0;
    }
    EventModify(param_1[0xc],3);
    hMem = FUN_c067e044(param_1 + 3);
    if (hMem != (int *)0x0) {
      piVar2 = (int *)*hMem;
      piVar6 = hMem;
      while (piVar2 != (int *)0x0) {
        piVar5 = piVar2 + -4;
        piVar4 = piVar2 + -2;
        *(int *)piVar2[-3] = *piVar5;
        *(int *)(*piVar5 + 4) = piVar2[-3];
        piVar6 = piVar6 + 1;
        *(int *)piVar2[-1] = *piVar4;
        *(int *)(*piVar4 + 4) = piVar2[-1];
        *(int *)piVar2[1] = *piVar2;
        *(int *)(*piVar2 + 4) = piVar2[1];
        piVar2[-3] = (int)piVar5;
        *piVar5 = (int)piVar5;
        piVar2[-1] = (int)piVar4;
        *piVar4 = (int)piVar4;
        piVar2[1] = (int)piVar2;
        *piVar2 = (int)piVar2;
        piVar2 = (int *)*piVar6;
      }
    }
    uVar1 = FUN_c067bc40();
    *param_2 = uVar1;
    if (hMem != (int *)0x0) {
      iVar3 = *hMem;
      piVar2 = hMem;
      while (iVar3 != 0) {
        piVar2 = piVar2 + 1;
        FUN_c0681344((HLOCAL)(iVar3 + -0x14));
        iVar3 = *piVar2;
      }
      LocalFree(hMem);
    }
    FUN_c0682d74((int)param_1,0,0);
    FUN_c0680a60(param_1 + 9,param_2);
    LocalFree(param_1);
    DAT_c06861dc = DAT_c06861dc + -1;
  }
  else {
    uVar1 = FUN_c067bc40();
    *param_2 = uVar1;
  }
  return;
}



/* c068179c FUN_c068179c */

/* Boundary evidence: original MIPS .pdata c068179c..c068184f. Semantic name remains unreviewed. */

undefined4 FUN_c068179c(HLOCAL param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((*(int *)((int)param_1 + 0x20) != 0) &&
     (iVar1 = *(int *)((int)param_1 + 0x20) + -1, *(int *)((int)param_1 + 0x20) = iVar1, iVar1 == 0)
     ) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c0681404(param_1,local_18);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c0681850 FUN_c0681850 */

/* Boundary evidence: original MIPS .pdata c0681850..c068185b. Semantic name remains unreviewed. */

undefined4 FUN_c0681850(void)

{
  return 1;
}



/* c068185c FUN_c068185c */

/* Boundary evidence: original MIPS .pdata c068185c..c068190f. Semantic name remains unreviewed. */

undefined4 FUN_c068185c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((param_1[6] != 0) && (iVar1 = param_1[6] + -1, param_1[6] = iVar1, iVar1 == 0)) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c06815f4(param_1,local_18);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c0681910 FUN_c0681910 */

/* Boundary evidence: original MIPS .pdata c0681910..c068191b. Semantic name remains unreviewed. */

undefined4 FUN_c0681910(void)

{
  return 1;
}



/* c068191c FUN_c068191c */

/* Boundary evidence: original MIPS .pdata c068191c..c0681bf3. Semantic name remains unreviewed. */

void FUN_c068191c(HLOCAL param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  
  if (*(int *)((int)param_1 + 0x40) == 0) {
    piVar9 = (int *)((int)param_1 + 4);
    *(undefined4 *)((int)param_1 + 0x40) = 1;
    iVar2 = *(int *)((int)param_1 + 0x18);
    uVar10 = *(undefined4 *)(iVar2 + 0x18);
    **(int **)((int)param_1 + 8) = *piVar9;
    piVar7 = (int *)((int)param_1 + 0xc);
    *(undefined4 *)(*piVar9 + 4) = *(undefined4 *)((int)param_1 + 8);
    **(int **)((int)param_1 + 0x10) = *piVar7;
    *(undefined4 *)(*piVar7 + 4) = *(undefined4 *)((int)param_1 + 0x10);
    *(int **)((int)param_1 + 8) = piVar9;
    *piVar9 = (int)piVar9;
    *(int **)((int)param_1 + 0x10) = piVar7;
    *piVar7 = (int)piVar7;
    bVar1 = FUN_c067d110(iVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      *(short *)(iVar2 + 0x38) = *(short *)(iVar2 + 0x38) + -1;
    }
    piVar7 = FUN_c067e044(&DAT_c0686178);
    if (piVar7 != (int *)0x0) {
      iVar5 = *piVar7;
      piVar9 = piVar7;
      while (iVar5 != 0) {
        piVar6 = (int *)*piVar9;
        if (((HLOCAL)piVar6[4] == param_1) && (piVar6[0xd] == 0)) {
          piVar6[0xd] = 1;
          piVar8 = piVar6 + 2;
          *(int *)piVar6[1] = *piVar6;
          *(int *)(*piVar6 + 4) = piVar6[1];
          *(int *)piVar6[3] = *piVar8;
          *(int *)(*piVar8 + 4) = piVar6[3];
          piVar6[1] = (int)piVar6;
          *piVar6 = (int)piVar6;
          piVar6[3] = (int)piVar8;
          *piVar8 = (int)piVar8;
        }
        else {
          *piVar9 = 1;
        }
        piVar9 = piVar9 + 1;
        iVar5 = *piVar9;
      }
    }
    iVar5 = FUN_c067bc40();
    *param_2 = iVar5;
    if ((*(int *)((int)param_1 + 0x24) != 0) &&
       (iVar5 = *(int *)(iVar2 + 0x34) + -1, *(int *)(iVar2 + 0x34) = iVar5, iVar5 == 0)) {
      (**(code **)(*(int *)(*(int *)(iVar2 + 0x14) + 0x18) + 0xb4))(*(undefined4 *)(iVar2 + 0x18),0)
      ;
    }
    uVar4 = 0;
    FUN_c0682d74(0,(int)param_1,0);
    if (*(HLOCAL *)((int)param_1 + 0x48) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)((int)param_1 + 0x48));
    }
    LocalFree(param_1);
    iVar5 = DAT_c0686208;
    DAT_c0686208 = DAT_c0686208 + -1;
    iVar3 = FUN_c067bc18();
    *param_2 = iVar3;
    if (*(short *)(iVar2 + 0x38) == 0) {
      if (*(int *)(iVar2 + 0x3c) != 0) {
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined4 *)(iVar2 + 0x3c) = 0;
        iVar3 = FUN_c067bc40();
        *param_2 = iVar3;
        (**(code **)(*(int *)(*(int *)(iVar2 + 0x14) + 0x18) + 0x10))(uVar10);
      }
    }
    else {
      param_4 = 0x400;
      uVar4 = 8;
      iVar5 = 0;
      FUN_c067eb1c(iVar2,(int *)0x0,8,0x400,0,0);
    }
    if (*param_2 != 0) {
      iVar3 = FUN_c067bc40();
      *param_2 = iVar3;
    }
    if (*(int *)(iVar2 + 0x3c) != 0) {
      FUN_c067d440(iVar2,iVar5,uVar4,param_4);
    }
    if (piVar7 != (int *)0x0) {
      iVar2 = *piVar7;
      piVar9 = piVar7;
      while (iVar2 != 0) {
        iVar2 = *piVar9;
        piVar9 = piVar9 + 1;
        if (iVar2 != 1) {
          FUN_c068179c((HLOCAL)(iVar2 + -4));
        }
        iVar2 = *piVar9;
      }
      LocalFree(piVar7);
    }
  }
  else {
    iVar2 = FUN_c067bc40();
    *param_2 = iVar2;
  }
  return;
}



/* c0681bf4 FUN_c0681bf4 */

/* Boundary evidence: original MIPS .pdata c0681bf4..c0681da7. Semantic name remains unreviewed. */

void FUN_c0681bf4(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *hMem;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (param_1 != (int *)0x0) {
    uVar1 = FUN_c067bc18();
    *param_2 = uVar1;
    if (*param_1 == 0x424d4f5a) {
      uVar1 = FUN_c067bc40();
      *param_2 = uVar1;
    }
    else {
      *param_1 = 0x424d4f5a;
      *(int *)param_1[2] = param_1[1];
      *(int *)(param_1[1] + 4) = param_1[2];
      hMem = FUN_c067e044(param_1 + 3);
      if (hMem != (int *)0x0) {
        piVar2 = (int *)*hMem;
        piVar7 = hMem;
        while (piVar2 != (int *)0x0) {
          piVar6 = piVar2 + -2;
          *(int *)piVar2[-1] = *piVar6;
          piVar5 = piVar2 + 2;
          *(int *)(*piVar6 + 4) = piVar2[-1];
          piVar7 = piVar7 + 1;
          *(int *)piVar2[1] = *piVar2;
          *(int *)(*piVar2 + 4) = piVar2[1];
          *(int *)piVar2[3] = *piVar5;
          *(int *)(*piVar5 + 4) = piVar2[3];
          piVar2[-1] = (int)piVar6;
          *piVar6 = (int)piVar6;
          piVar2[1] = (int)piVar2;
          *piVar2 = (int)piVar2;
          piVar2[3] = (int)piVar5;
          *piVar5 = (int)piVar5;
          piVar2 = (int *)*piVar7;
        }
      }
      uVar1 = FUN_c067bc40();
      *param_2 = uVar1;
      if (hMem != (int *)0x0) {
        iVar3 = *hMem;
        piVar2 = hMem;
        while (iVar3 != 0) {
          iVar4 = *piVar2;
          piVar2 = piVar2 + 1;
          iVar3 = FUN_c067d24c(*(int *)(iVar4 + 0x10));
          if (iVar3 != 0) {
            FUN_c067bf04(*(int *)(iVar4 + 0x10) + 0x24,iVar4 + -0xc,0xf,*(int *)(iVar4 + 0x24),0,0,0
                        );
            FUN_c068185c(*(undefined4 **)(iVar4 + 0x10));
          }
          FUN_c0681344((HLOCAL)(iVar4 + -0xc));
          iVar3 = *piVar2;
        }
        LocalFree(hMem);
      }
      LocalFree(param_1);
    }
  }
  return;
}



/* c0681da8 FUN_c0681da8 */

/* Boundary evidence: original MIPS .pdata c0681da8..c0681e0f. Semantic name remains unreviewed. */

void FUN_c0681da8(int *param_1)

{
  int local_10 [2];
  
  local_10[0] = 0;
  FUN_c0681bf4(param_1,local_10);
  if (local_10[0] != 0) {
    FUN_c067bc40();
  }
  return;
}



/* c0681e10 FUN_c0681e10 */

/* Boundary evidence: original MIPS .pdata c0681e10..c0681e1b. Semantic name remains unreviewed. */

undefined4 FUN_c0681e10(void)

{
  return 1;
}



/* c0681e1c FUN_c0681e1c */

/* Boundary evidence: original MIPS .pdata c0681e1c..c0681ecf. Semantic name remains unreviewed. */

undefined4 FUN_c0681e1c(HLOCAL param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((*(int *)((int)param_1 + 0x1c) != 0) &&
     (iVar1 = *(int *)((int)param_1 + 0x1c) + -1, *(int *)((int)param_1 + 0x1c) = iVar1, iVar1 == 0)
     ) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c068191c(param_1,local_18,param_3,param_4);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c0681ed0 FUN_c0681ed0 */

/* Boundary evidence: original MIPS .pdata c0681ed0..c0681edb. Semantic name remains unreviewed. */

undefined4 FUN_c0681ed0(void)

{
  return 1;
}



/* c0681edc FUN_c0681edc */

/* Boundary evidence: original MIPS .pdata c0681edc..c06821cf. Semantic name remains unreviewed. */

undefined4 * FUN_c0681edc(int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *hMem;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  uVar3 = param_3;
  iVar1 = FUN_c067cf2c(param_2);
  if (iVar1 != 0) {
    iVar1 = FUN_c067d14c(param_1);
    if (iVar1 == 0) {
      FUN_c0681284(param_2);
    }
    else {
      uVar2 = 0x3c;
      hMem = LocalAlloc(0x40,0x3c);
      if (hMem != (undefined4 *)0x0) {
        puVar5 = hMem + 1;
        hMem[2] = puVar5;
        *puVar5 = puVar5;
        piVar6 = hMem + 3;
        hMem[4] = piVar6;
        *piVar6 = (int)piVar6;
        hMem[8] = 1;
        *hMem = 0xcc;
        hMem[5] = param_1;
        hMem[6] = param_2;
        hMem[7] = param_1[5];
        if (param_2[7] == 0) {
          param_2[7] = param_1[5];
        }
        hMem[9] = param_3;
        if ((param_3 & 4) == 0) {
          if ((param_3 & 2) != 0) {
            param_2[0xe] = param_2[0xe] + 1;
          }
        }
        else {
          param_2[0xd] = param_2[0xd] + 1;
        }
        FUN_c067bc18();
        if (*(int *)(hMem[7] + 0x14) == 0) {
          *puVar5 = DAT_c0686178;
          hMem[2] = &DAT_c0686178;
          DAT_c0686178[1] = puVar5;
          piVar4 = param_2 + 3;
          DAT_c0686178 = puVar5;
          *piVar6 = *piVar4;
          hMem[4] = piVar4;
          *(int **)(*piVar4 + 4) = piVar6;
          *piVar4 = (int)piVar6;
        }
        else {
          LocalFree(hMem);
          if ((param_3 & 4) == 0) {
            if ((param_3 & 2) != 0) {
              param_2[0xe] = param_2[0xe] + -1;
            }
          }
          else {
            param_2[0xd] = param_2[0xd] + -1;
          }
          hMem = (undefined4 *)0x0;
        }
        FUN_c067bc40();
        if (hMem == (undefined4 *)0x0) {
          FUN_c0681284(param_2);
        }
        else {
          DAT_c0686200 = DAT_c0686200 + 1;
        }
        FUN_c0681e1c(param_1,uVar2,uVar3,param_4);
        return hMem;
      }
      FUN_c0681284(param_2);
      FUN_c0681e1c(param_1,uVar2,uVar3,param_4);
    }
  }
  return (undefined4 *)0x0;
}



/* c06821d0 FUN_c06821d0 */

/* Boundary evidence: original MIPS .pdata c06821d0..c06821db. Semantic name remains unreviewed. */

undefined4 FUN_c06821d0(void)

{
  return 1;
}



/* c06821dc FUN_c06821dc */

/* Boundary evidence: original MIPS .pdata c06821dc..c0682277. Semantic name remains unreviewed. */

undefined4 FUN_c06821dc(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = FUN_c0680084(param_1[6]);
  if (piVar1 != (int *)0x0) {
    piVar1[7] = param_1[5];
    puVar2 = FUN_c0681edc(param_1,piVar1,4,param_4);
    if (puVar2 != (undefined4 *)0x0) {
      *param_2 = piVar1;
      *param_3 = puVar2;
      return 0;
    }
    FUN_c067d570((int)piVar1);
  }
  return 0x80000044;
}



/* c0682278 FUN_c0682278 */

/* Boundary evidence: original MIPS .pdata c0682278..c068259f. Semantic name remains unreviewed. */

void FUN_c0682278(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  
  if (param_1[5] == 0) {
    param_1[5] = 1;
    *param_1 = 0;
    if (param_1[8] != 0) {
      param_1[9] = param_1[8];
      param_1[8] = 0;
    }
    uVar1 = 3;
    EventModify(param_1[9]);
    piVar2 = FUN_c067e044(&DAT_c0686178);
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
      piVar3 = piVar2;
      while (iVar5 != 0) {
        piVar6 = (int *)*piVar3;
        if (((undefined4 *)piVar6[6] == param_1) && (piVar6[0xd] == 0)) {
          piVar6[0xd] = 1;
          piVar7 = piVar6 + 2;
          *(int *)piVar6[1] = *piVar6;
          *(int *)(*piVar6 + 4) = piVar6[1];
          *(int *)piVar6[3] = *piVar7;
          *(int *)(*piVar7 + 4) = piVar6[3];
          piVar6[1] = (int)piVar6;
          *piVar6 = (int)piVar6;
          piVar6[3] = (int)piVar7;
          *piVar7 = (int)piVar7;
        }
        else {
          *piVar3 = 1;
        }
        piVar3 = piVar3 + 1;
        iVar5 = *piVar3;
      }
    }
    piVar3 = FUN_c067e044(&DAT_c0686188);
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
      piVar6 = piVar3;
      while (iVar5 != 0) {
        piVar7 = (int *)*piVar6;
        if (((undefined4 *)piVar7[4] == param_1) && (piVar7[0x10] == 0)) {
          piVar7[0x10] = 1;
          piVar8 = piVar7 + 2;
          *(int *)piVar7[1] = *piVar7;
          *(int *)(*piVar7 + 4) = piVar7[1];
          *(int *)piVar7[3] = *piVar8;
          *(int *)(*piVar8 + 4) = piVar7[3];
          piVar7[1] = (int)piVar7;
          *piVar7 = (int)piVar7;
          piVar7[3] = (int)piVar8;
          *piVar8 = (int)piVar8;
        }
        else {
          *piVar6 = 1;
        }
        piVar6 = piVar6 + 1;
        iVar5 = *piVar6;
      }
    }
    *(undefined4 *)param_1[2] = param_1[1];
    *(undefined4 *)(param_1[1] + 4) = param_1[2];
    uVar4 = FUN_c067bc40();
    *param_2 = uVar4;
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
      piVar6 = piVar2;
      while (iVar5 != 0) {
        iVar5 = *piVar6;
        piVar6 = piVar6 + 1;
        if (iVar5 != 1) {
          FUN_c068179c((HLOCAL)(iVar5 + -4));
        }
        iVar5 = *piVar6;
      }
      LocalFree(piVar2);
    }
    FUN_c067bc18();
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
      piVar2 = piVar3;
      while (iVar5 != 0) {
        iVar5 = *piVar2;
        piVar2 = piVar2 + 1;
        if (iVar5 != 1) {
          iVar10 = *(int *)(iVar5 + 0x14);
          FUN_c067bc40();
          FUN_c0681e1c((HLOCAL)(iVar5 + -4),uVar1,param_3,param_4);
          param_4 = 0x400;
          param_3 = 8;
          uVar1 = 0;
          FUN_c067eb1c(iVar10,(int *)0x0,8,0x400,(uint)param_1,0);
          FUN_c067bc18();
        }
        iVar5 = *piVar2;
      }
      LocalFree(piVar3);
    }
    FUN_c067bc40();
    uVar9 = 0;
    do {
      if (*(char *)((int)param_1 + uVar9 + 0x28) != '\0') {
        FUN_c06745f8(param_1,uVar9,0);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x11);
    FUN_c0682d74((int)param_1,0,0);
    FUN_c0680a60(param_1 + 6,param_2);
    LocalFree(param_1);
    DAT_c06861c8 = DAT_c06861c8 + -1;
  }
  else {
    uVar1 = FUN_c067bc40();
    *param_2 = uVar1;
  }
  return;
}



/* c06825a0 FUN_c06825a0 */

/* Boundary evidence: original MIPS .pdata c06825a0..c0682653. Semantic name remains unreviewed. */

undefined4
FUN_c06825a0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0;
  local_18[0] = FUN_c067bc18();
  if ((param_1[0xf] != 0) && (iVar1 = param_1[0xf] + -1, param_1[0xf] = iVar1, iVar1 == 0)) {
    uVar2 = 1;
    local_18[1] = 1;
    FUN_c0682278(param_1,local_18,param_3,param_4);
  }
  if (local_18[0] != 0) {
    FUN_c067bc40();
  }
  return uVar2;
}



/* c0682654 FUN_c0682654 */

/* Boundary evidence: original MIPS .pdata c0682654..c068265f. Semantic name remains unreviewed. */

undefined4 FUN_c0682654(void)

{
  return 1;
}



/* c0682660 FUN_c0682660 */

/* Boundary evidence: original MIPS .pdata c0682660..c06827ef. Semantic name remains unreviewed. */

void FUN_c0682660(int *param_1,undefined4 *param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int *hMem;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  if (param_1 != (int *)0x0) {
    puVar2 = param_2;
    uVar1 = FUN_c067bc18();
    *param_2 = uVar1;
    if (*param_1 == 0x424d4f5a) {
      uVar1 = FUN_c067bc40();
      *param_2 = uVar1;
    }
    else {
      *param_1 = 0x424d4f5a;
      *(int *)param_1[2] = param_1[1];
      *(int *)(param_1[1] + 4) = param_1[2];
      hMem = FUN_c067e044(param_1 + 3);
      if (hMem != (int *)0x0) {
        piVar3 = (int *)*hMem;
        piVar8 = hMem;
        while (piVar3 != (int *)0x0) {
          piVar6 = piVar3 + -2;
          *(int *)piVar3[-1] = *piVar6;
          piVar8 = piVar8 + 1;
          *(int *)(*piVar6 + 4) = piVar3[-1];
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          piVar3[-1] = (int)piVar6;
          *piVar6 = (int)piVar6;
          piVar3[1] = (int)piVar3;
          *piVar3 = (int)piVar3;
          piVar3 = (int *)*piVar8;
        }
      }
      uVar1 = FUN_c067bc40();
      *param_2 = uVar1;
      if (hMem != (int *)0x0) {
        iVar4 = *hMem;
        piVar3 = hMem;
        while (iVar4 != 0) {
          iVar5 = *piVar3;
          puVar7 = (undefined4 *)(iVar5 + -0xc);
          piVar3 = piVar3 + 1;
          iVar4 = FUN_c067d02c(*(int **)(iVar5 + 8));
          if (iVar4 != 0) {
            param_4 = *(int *)(iVar5 + 0x2c);
            param_3 = 3;
            puVar2 = puVar7;
            FUN_c067bf04(*(int *)(iVar5 + 8) + 0x18,(int)puVar7,3,param_4,0,0,0);
            FUN_c06825a0(*(undefined4 **)(iVar5 + 8),puVar2,param_3,param_4);
          }
          FUN_c0681e1c(puVar7,puVar2,param_3,param_4);
          iVar4 = *piVar3;
        }
        LocalFree(hMem);
      }
      LocalFree(param_1);
    }
  }
  return;
}



/* c06827f0 FUN_c06827f0 */

/* Boundary evidence: original MIPS .pdata c06827f0..c0682857. Semantic name remains unreviewed. */

void FUN_c06827f0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_10 [2];
  
  local_10[0] = 0;
  FUN_c0682660(param_1,local_10,param_3,param_4);
  if (local_10[0] != 0) {
    FUN_c067bc40();
  }
  return;
}



/* c0682858 FUN_c0682858 */

/* Boundary evidence: original MIPS .pdata c0682858..c0682863. Semantic name remains unreviewed. */

undefined4 FUN_c0682858(void)

{
  return 1;
}



/* c0682864 FUN_c0682864 */

/* Boundary evidence: original MIPS .pdata c0682864..c06828c3. Semantic name remains unreviewed. */

void FUN_c0682864(int param_1,int *param_2,LPCRITICAL_SECTION param_3)

{
  EnterCriticalSection(param_3);
  *param_2 = param_1;
  param_2[1] = *(int *)(param_1 + 4);
  **(undefined4 **)(param_1 + 4) = param_2;
  *(int **)(param_1 + 4) = param_2;
  LeaveCriticalSection(param_3);
  return;
}



/* c06828c4 FUN_c06828c4 */

/* Boundary evidence: original MIPS .pdata c06828c4..c0682983. Semantic name remains unreviewed. */

void FUN_c06828c4(int *param_1)

{
  int iVar1;
  
  FUN_c067bc18();
  if ((param_1[0xd] != 0) && (iVar1 = param_1[0xd] + -1, param_1[0xd] = iVar1, iVar1 == 0)) {
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    if ((HLOCAL)param_1[0xb] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0xb]);
    }
    if ((HLOCAL)param_1[0xc] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0xc]);
    }
    LocalFree(param_1);
    DAT_c06861f8 = DAT_c06861f8 + -1;
  }
  FUN_c067bc40();
  return;
}



/* c0682984 FUN_c0682984 */

/* Boundary evidence: original MIPS .pdata c0682984..c068298f. Semantic name remains unreviewed. */

undefined4 FUN_c0682984(void)

{
  return 1;
}



/* c0682990 FUN_c0682990 */

/* Boundary evidence: original MIPS .pdata c0682990..c0682a77. Semantic name remains unreviewed. */

undefined4 * FUN_c0682990(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_c067bc18();
  puVar2 = DAT_c0686168;
  do {
    while( true ) {
      puVar1 = puVar2;
      puVar2 = (undefined4 *)0x0;
      if ((undefined4 **)puVar1 == &DAT_c0686168) goto LAB_c0682a30;
      puVar2 = (undefined4 *)*puVar1;
      if (param_1 != -0x7fffffce) break;
      if (puVar1[0xe] == 3) goto LAB_c0682a1c;
    }
  } while (puVar1[2] != param_1);
LAB_c0682a1c:
  puVar1[0xd] = puVar1[0xd] + 1;
  puVar2 = puVar1;
LAB_c0682a30:
  FUN_c067bc40();
  return puVar2;
}



/* c0682a78 FUN_c0682a78 */

/* Boundary evidence: original MIPS .pdata c0682a78..c0682a83. Semantic name remains unreviewed. */

undefined4 FUN_c0682a78(void)

{
  return 1;
}



/* c0682a84 FUN_c0682a84 */

/* Boundary evidence: original MIPS .pdata c0682a84..c0682aeb. Semantic name remains unreviewed. */

void FUN_c0682a84(int *param_1)

{
  bool bVar1;
  
  FUN_c067bc18();
  bVar1 = (param_1[0xe] & 4U) == 0;
  if (bVar1) {
    param_1[0xe] = param_1[0xe] | 4;
  }
  FUN_c067bc40();
  if (bVar1) {
    FUN_c06828c4(param_1);
  }
  return;
}



/* c0682aec FUN_c0682aec */

/* Boundary evidence: original MIPS .pdata c0682aec..c0682b2b. Semantic name remains unreviewed. */

void FUN_c0682aec(int param_1)

{
  int *piVar1;
  
  piVar1 = FUN_c0682990(param_1);
  if (piVar1 != (int *)0x0) {
    FUN_c06828c4(piVar1);
    FUN_c0682a84(piVar1);
  }
  return;
}



/* c0682b2c FUN_c0682b2c */

/* Boundary evidence: original MIPS .pdata c0682b2c..c0682c0b. Semantic name remains unreviewed. */

undefined4 FUN_c0682b2c(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  LONG LVar2;
  undefined4 uVar3;
  
  piVar1 = LocalAlloc(0x40,0x44);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    LVar2 = InterlockedIncrement(&DAT_c06861bc);
    uVar3 = 1;
    if (LVar2 < 1) {
      DAT_c06861bc = 1;
    }
    *param_1 = DAT_c06861bc;
    param_1[0xb] = 1;
    param_1[0xc] = 0;
    memcpy(piVar1 + 2,param_1,0x3c);
    FUN_c0682864(-0x3f979e98,piVar1,(LPCRITICAL_SECTION)&DAT_c068614c);
    DAT_c06861f8 = DAT_c06861f8 + 1;
    *param_2 = piVar1[2];
  }
  return uVar3;
}



/* c0682c0c FUN_c0682c0c */

/* Boundary evidence: original MIPS .pdata c0682c0c..c0682cb7. Semantic name remains unreviewed. */

void FUN_c0682c0c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_c067bc18();
  iVar1 = FUN_c067cf2c(param_1);
  if (iVar1 == 0) {
    FUN_c067bc40();
  }
  else {
    iVar1 = param_1[10];
    if (iVar1 == 2) {
      piVar2 = param_1 + 1;
      *(int *)param_1[2] = *piVar2;
      *(int *)(*piVar2 + 4) = param_1[2];
      param_1[2] = (int)piVar2;
      *piVar2 = (int)piVar2;
    }
    FUN_c067bc40();
    FUN_c0681284(param_1);
    if (iVar1 == 2) {
      FUN_c0681284(param_1);
    }
  }
  return;
}



/* c0682cb8 FUN_c0682cb8 */

/* Boundary evidence: original MIPS .pdata c0682cb8..c0682d73. Semantic name remains unreviewed. */

void FUN_c0682cb8(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  if (uVar3 == 2) {
    iVar1 = FUN_c067cf2c(*(int **)(param_1 + 0x1c));
    if (iVar1 == 0) {
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x68) = 0;
    FUN_c0681284(*(HLOCAL *)(param_1 + 0x1c));
    return;
  }
  if (uVar3 == 5) {
LAB_c0682d3c:
    piVar2 = *(int **)(param_1 + 0x24);
  }
  else {
    if (uVar3 != 9) {
      if (uVar3 < 0xb) {
        return;
      }
      if (0xd < uVar3) {
        if (uVar3 == 0x14) {
          FUN_c0682c0c(*(int **)(param_1 + 0x1c));
          goto LAB_c0682d3c;
        }
        if (uVar3 != 0x15) {
          return;
        }
      }
    }
    piVar2 = *(int **)(param_1 + 0x1c);
  }
  FUN_c0682c0c(piVar2);
  return;
}



/* c0682d74 FUN_c0682d74 */

/* Boundary evidence: original MIPS .pdata c0682d74..c0682f1f. Semantic name remains unreviewed. */

void FUN_c0682d74(int param_1,int param_2,int param_3)

{
  int *hMem;
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_c067bc18();
  hMem = FUN_c067e044(&DAT_c0686168);
  piVar3 = hMem;
  if (hMem != (int *)0x0) {
    for (; piVar1 = (int *)*piVar3, piVar1 != (int *)0x0; piVar3 = piVar3 + 1) {
      if (((((param_1 == 0) || (param_1 != piVar1[3])) && ((param_2 == 0 || (param_2 != piVar1[6])))
           ) && ((param_3 == 0 || (param_3 != piVar1[8])))) || ((piVar1[0xe] & 4U) != 0)) {
        *piVar3 = 1;
      }
      else {
        *(int *)piVar1[1] = *piVar1;
        *(int *)(*piVar1 + 4) = piVar1[1];
        piVar1[1] = (int)piVar1;
        *piVar1 = (int)piVar1;
        piVar1[0xe] = piVar1[0xe] | 4;
      }
    }
  }
  FUN_c067bc40();
  if (hMem != (int *)0x0) {
    iVar2 = *hMem;
    piVar3 = hMem;
    while (iVar2 != 0) {
      piVar1 = (int *)*piVar3;
      piVar3 = piVar3 + 1;
      if (piVar1 != (int *)0x1) {
        FUN_c0682cb8((int)piVar1);
        FUN_c06828c4(piVar1);
      }
      iVar2 = *piVar3;
    }
    LocalFree(hMem);
  }
  return;
}



/* c0682f20 FUN_c0682f20 */

/* Boundary evidence: original MIPS .pdata c0682f20..c0682f2b. Semantic name remains unreviewed. */

undefined4 FUN_c0682f20(void)

{
  return 1;
}



/* c0682f2c FUN_c0682f2c */

/* Boundary evidence: original MIPS .pdata c0682f2c..c0683047. Semantic name remains unreviewed. */

void FUN_c0682f2c(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_c067d41c(param_1[4]);
  if (iVar1 == 0) {
    iVar2 = FUN_c067d02c((int *)param_1[3]);
    if (iVar2 == 0) goto LAB_c0683020;
    iVar3 = param_1[3] + 0x18;
    iVar2 = FUN_c067d14c((int *)param_1[6]);
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1[6] + 0x38);
      FUN_c0681e1c((HLOCAL)param_1[6],param_2,param_3,param_4);
      param_4 = iVar2;
      param_3 = 0xc;
      goto LAB_c0682fd8;
    }
  }
  else {
    iVar2 = FUN_c067d24c(param_1[3]);
    if (iVar2 == 0) goto LAB_c0683020;
    iVar3 = param_1[3] + 0x24;
    iVar2 = FUN_c067d338((int *)param_1[6]);
    if (iVar2 != 0) {
      param_4 = *(int *)(param_1[6] + 0x30);
      FUN_c0681344((HLOCAL)param_1[6]);
      param_3 = 0x11;
LAB_c0682fd8:
      param_2 = 0;
      FUN_c067bf04(iVar3,0,param_3,param_4,param_1[2],param_1[0xf],0);
    }
    if (iVar1 != 0) {
      FUN_c068185c((undefined4 *)param_1[3]);
      goto LAB_c0683020;
    }
  }
  FUN_c06825a0((undefined4 *)param_1[3],param_2,param_3,param_4);
LAB_c0683020:
  FUN_c06828c4(param_1);
  return;
}



/* c0683048 FUN_c0683048 */

/* Boundary evidence: original MIPS .pdata c0683048..c06831d3. Semantic name remains unreviewed. */

undefined4 FUN_c0683048(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  
  uVar1 = CeGetThreadPriority(0x41);
  DVar5 = 0;
  while( true ) {
    while( true ) {
      FUN_c067bc18();
      piVar2 = FUN_c0682990(-0x7fffffce);
      if (piVar2 == (int *)0x0) break;
      DVar5 = 0;
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
      iVar4 = piVar2[0xe];
      piVar2[1] = (int)piVar2;
      *piVar2 = (int)piVar2;
      if (iVar4 == 3) {
        piVar2[0xe] = 7;
      }
      FUN_c067bc40();
      if (iVar4 == 3) {
        uVar3 = piVar2[0x10] + 1;
        if (0xff < uVar3) {
          uVar3 = 0xff;
        }
        CeSetThreadPriority(0x41);
        Sleep(DAT_c06861f4);
        FUN_c0682f2c(piVar2,uVar3,param_3,param_4);
        CeSetThreadPriority(0x41,uVar1);
      }
      FUN_c06828c4(piVar2);
    }
    if (DVar5 == 0x102) break;
    if (DVar5 != 0) {
      return 0;
    }
    FUN_c067bc40();
    DVar5 = WaitForSingleObject(DAT_c06861ec,15000);
  }
  DAT_c06861f0 = 0;
  FUN_c067bc40();
  return 0;
}



/* c06831d4 FUN_c06831d4 */

/* Boundary evidence: original MIPS .pdata c06831d4..c06832c7. Semantic name remains unreviewed. */

undefined4 FUN_c06831d4(void)

{
  HANDLE hObject;
  undefined4 uVar1;
  
  uVar1 = 1;
  FUN_c067bc18();
  if (DAT_c06861f0 == 0) {
    DAT_c06861f0 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0683048,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject == (HANDLE)0x0) {
      DAT_c06861f0 = 0;
      uVar1 = 0;
    }
    else {
      CloseHandle(hObject);
    }
  }
  else {
    EventModify(DAT_c06861ec,3);
  }
  FUN_c067bc40();
  return uVar1;
}



/* c06832c8 FUN_c06832c8 */

/* Boundary evidence: original MIPS .pdata c06832c8..c06832d3. Semantic name remains unreviewed. */

undefined4 FUN_c06832c8(void)

{
  return 1;
}



/* c06832d4 FUN_c06832d4 */

/* Boundary evidence: original MIPS .pdata c06832d4..c068339b. Semantic name remains unreviewed. */

void FUN_c06832d4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = FUN_c0682990(param_1);
  if (piVar1 != (int *)0x0) {
    FUN_c067bc18();
    uVar3 = piVar1[0xe];
    piVar1[0xe] = uVar3 | 1;
    FUN_c067bc40();
    if (((uVar3 | 1) == 3) && (iVar2 = FUN_c06831d4(), iVar2 == 0)) {
      FUN_c0682f2c(piVar1,param_2,param_3,param_4);
    }
    FUN_c06828c4(piVar1);
  }
  return;
}



/* c068339c FUN_c068339c */

/* Boundary evidence: original MIPS .pdata c068339c..c06833a7. Semantic name remains unreviewed. */

undefined4 FUN_c068339c(void)

{
  return 1;
}



/* c06833a8 FUN_c06833a8 */

/* Boundary evidence: original MIPS .pdata c06833a8..c068345b. Semantic name remains unreviewed. */

void FUN_c06833a8(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2;
  FUN_c067bc18();
  uVar3 = param_1[0xe];
  param_1[0xe] = uVar3 | 2;
  param_1[0xf] = param_2;
  FUN_c067bc40();
  if (((uVar3 | 2) == 3) && (iVar1 = FUN_c06831d4(), iVar1 == 0)) {
    FUN_c0682f2c(param_1,iVar2,param_3,param_4);
  }
  return;
}



/* c068345c FUN_c068345c */

/* Boundary evidence: original MIPS .pdata c068345c..c0683467. Semantic name remains unreviewed. */

undefined4 FUN_c068345c(void)

{
  return 1;
}



/* c0683468 FUN_c0683468 */

ushort * FUN_c0683468(ushort *param_1,uint param_2,undefined4 *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  *param_3 = 0;
  if (param_1 == (ushort *)0x0) {
    param_1 = DAT_c0686120;
  }
  uVar1 = *param_1;
  puVar2 = param_1;
  while ((uVar1 != 0 && (*puVar2 != param_2))) {
    iVar3 = iVar3 + 1;
    puVar2 = param_1 + iVar3;
    uVar1 = *puVar2;
  }
  puVar2 = param_1 + iVar3;
  DAT_c0686120 = puVar2;
  if (*puVar2 != 0) {
    DAT_c0686120 = puVar2 + 1;
    *puVar2 = 0;
    *param_3 = 1;
  }
  return param_1;
}



/* c06834ec FUN_c06834ec */

/* Boundary evidence: original MIPS .pdata c06834ec..c06836bf. Semantic name remains unreviewed. */

LSTATUS FUN_c06834ec(PHKEY param_1,PHKEY param_2,undefined4 *param_3,SIZE_T *param_4,LPDWORD param_5
                    ,LPBYTE param_6)

{
  LSTATUS LVar1;
  HLOCAL pvVar2;
  HKEY hKey;
  DWORD local_48;
  DWORD local_44;
  DWORD DStack_40;
  DWORD DStack_3c;
  DWORD DStack_38;
  DWORD DStack_34;
  DWORD aDStack_30 [2];
  
  *param_1 = (HKEY)0x0;
  *param_2 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial",0,0x20019,param_1);
  if (LVar1 == 0) {
    local_48 = 4;
    LVar1 = RegQueryValueExW(*param_1,L"CurrentLoc",(LPDWORD)0x0,&DStack_40,param_6,&local_48);
    hKey = *param_1;
    if (LVar1 == 0) {
      LVar1 = RegOpenKeyExW(hKey,L"Locations",0,0x20019,param_2);
      if (LVar1 == 0) {
        RegQueryInfoKeyW(*param_2,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,aDStack_30,&DStack_34,
                         &DStack_38,param_5,&DStack_3c,&local_44,(LPDWORD)0x0,(PFILETIME)0x0);
        *param_4 = local_44 + 2;
        pvVar2 = LocalAlloc(0x40,local_44 + 2);
        *param_3 = pvVar2;
        if (pvVar2 == (HLOCAL)0x0) {
          RegCloseKey(*param_1);
          RegCloseKey(*param_2);
          *param_4 = 0;
          return -0x7ff8fff2;
        }
        return 0;
      }
      hKey = *param_1;
    }
    RegCloseKey(hKey);
  }
  return LVar1;
}



/* c06836c0 FUN_c06836c0 */

/* Boundary evidence: original MIPS .pdata c06836c0..c068385b. Semantic name remains unreviewed. */

LSTATUS FUN_c06836c0(HKEY param_1,undefined4 param_2,wchar_t *param_3,DWORD param_4,long *param_5)

{
  LSTATUS LVar1;
  long lVar2;
  wchar_t *pwVar3;
  int iVar4;
  DWORD local_resc;
  DWORD local_48 [2];
  wchar_t awStack_40 [16];
  uint local_20;
  
  local_20 = DAT_c068610c;
  local_48[0] = 7;
  local_resc = param_4;
  memset(param_5,0,0x24);
  StringCchPrintfW(awStack_40,0x10,L"%d",param_2);
  LVar1 = RegQueryValueExW(param_1,awStack_40,(LPDWORD)0x0,local_48,(LPBYTE)param_3,&local_resc);
  if (LVar1 == 0) {
    lVar2 = wcstol(awStack_40,(wchar_t **)0x0,10);
    *param_5 = lVar2;
    param_5[1] = (long)param_3;
    pwVar3 = wcschr(param_3,L'\0');
    param_5[2] = (long)(pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    param_5[3] = (long)(pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    param_5[4] = (long)(pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    param_5[5] = (long)(pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    param_5[6] = (long)(pwVar3 + 1);
    iVar4 = wcscmp(pwVar3 + 1,L"noCW");
    if (iVar4 == 0) {
      param_5[6] = 0;
    }
    pwVar3 = wcschr((wchar_t *)param_5[6],L'\0');
    param_5[7] = (long)(pwVar3 + 1);
    pwVar3 = wcschr(pwVar3 + 1,L'\0');
    iVar4 = wcsncmp(pwVar3 + 1,L"1",1);
    if (iVar4 == 0) {
      param_5[8] = 1;
    }
    FUN_c0684adc(local_20);
    LVar1 = 0;
  }
  else {
    FUN_c0684adc(local_20);
  }
  return LVar1;
}



/* c068385c FUN_c068385c */

/* Boundary evidence: original MIPS .pdata c068385c..c06838db. Semantic name remains unreviewed. */

undefined4 FUN_c068385c(wchar_t *param_1,wchar_t param_2)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (param_1 != (wchar_t *)0x0) {
    while (param_1 = wcschr(param_1,param_2), param_1 != (wchar_t *)0x0) {
      uVar4 = 1;
      wVar1 = *param_1;
      pwVar2 = param_1;
      while (wVar1 != L'\0') {
        pwVar3 = pwVar2 + 1;
        *pwVar2 = *pwVar3;
        pwVar2 = pwVar3;
        wVar1 = *pwVar3;
      }
    }
  }
  return uVar4;
}



/* c06838dc FUN_c06838dc */

/* Boundary evidence: original MIPS .pdata c06838dc..c0683aa7. Semantic name remains unreviewed. */

undefined4 FUN_c06838dc(int param_1,int param_2)

{
  int iVar1;
  LSTATUS LVar2;
  STRSAFE_LPWSTR pszDest;
  HKEY local_30;
  DWORD local_2c;
  HKEY local_28;
  int local_24;
  DWORD aDStack_20 [2];
  
  LVar2 = RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Dial",0,0x20019,&local_30);
  if (LVar2 != 0) {
    return 0;
  }
  iVar1 = param_1;
  if (param_1 == -1) {
    local_2c = 4;
    LVar2 = RegQueryValueExW(local_30,L"CurrentLoc",(LPDWORD)0x0,aDStack_20,(LPBYTE)&local_24,
                             &local_2c);
    iVar1 = local_24;
    if (LVar2 != 0) goto LAB_c0683994;
  }
  local_24 = iVar1;
  local_2c = 0x24;
  pszDest = LocalAlloc(0x40,0x48);
  if (pszDest != (STRSAFE_LPWSTR)0x0) {
    StringCchPrintfW(pszDest,local_2c,L"%s\\%s\\%d",L"Locations",L"TollLists",local_24);
    LVar2 = RegOpenKeyExW(local_30,pszDest,0,0x20019,&local_28);
    if ((LVar2 != 0) &&
       ((param_2 == 0 ||
        (LVar2 = RegCreateKeyExW(local_30,pszDest,0,(LPWSTR)0x0,0,0,(LPSECURITY_ATTRIBUTES)0x0,
                                 &local_28,&local_2c), LVar2 != 0)))) {
      local_28 = (HKEY)0x0;
    }
    RegCloseKey(local_30);
    LocalFree(pszDest);
    return local_28;
  }
LAB_c0683994:
  RegCloseKey(local_30);
  return 0;
}



/* c0683aa8 FUN_c0683aa8 */

/* Boundary evidence: original MIPS .pdata c0683aa8..c0683b3b. Semantic name remains unreviewed. */

undefined4 FUN_c0683aa8(LPCWSTR param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  DWORD local_20;
  BYTE aBStack_1c [4];
  DWORD aDStack_18 [2];
  
  hKey = (HKEY)FUN_c06838dc(-1,0);
  if (hKey != (HKEY)0x0) {
    local_20 = 4;
    LVar1 = RegQueryValueExW(hKey,param_1,(LPDWORD)0x0,aDStack_18,aBStack_1c,&local_20);
    RegCloseKey(hKey);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c0683b3c FUN_c0683b3c */

/* Boundary evidence: original MIPS .pdata c0683b3c..c0683c1f. Semantic name remains unreviewed. */

undefined4 FUN_c0683b3c(wchar_t *param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  uint uVar6;
  
  if ((*param_1 == L'+') && (pwVar2 = wcschr(param_1,L' '), pwVar2 != (wchar_t *)0x0)) {
    pwVar3 = wcschr(param_1,L'|');
    if (pwVar3 == (wchar_t *)0x0) {
      sVar4 = wcslen(param_1);
      pwVar3 = param_1 + sVar4;
    }
    pwVar2 = pwVar2 + 1;
    pwVar5 = wcschr(pwVar2,L' ');
    if (pwVar5 != (wchar_t *)0x0) {
      pwVar2 = pwVar5 + 1;
    }
    uVar6 = 0;
    pwVar5 = param_2;
    do {
      if (pwVar3 <= pwVar2) break;
      uVar6 = uVar6 + 1;
      *pwVar5 = *pwVar2;
      pwVar2 = pwVar2 + 1;
      pwVar5 = pwVar5 + 1;
    } while (uVar6 < 3);
    param_2[3] = L'\0';
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0683c20 FUN_c0683c20 */

/* Boundary evidence: original MIPS .pdata c0683c20..c0683c83. Semantic name remains unreviewed. */

undefined4 FUN_c0683c20(wchar_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_20 [8];
  uint local_10;
  
  local_10 = DAT_c068610c;
  iVar1 = FUN_c0683b3c(param_1,awStack_20);
  if (iVar1 == 0) {
    FUN_c0684adc(local_10);
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_c0683aa8(awStack_20);
    FUN_c0684adc(local_10);
  }
  return uVar2;
}



/* c0683c84 FUN_c0683c84 */

/* Boundary evidence: original MIPS .pdata c0683c84..c0683d83. Semantic name remains unreviewed. */

undefined4 FUN_c0683c84(wchar_t *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  HKEY hKey;
  BYTE local_30 [8];
  wchar_t awStack_28 [8];
  uint local_18;
  
  local_18 = DAT_c068610c;
  iVar1 = FUN_c0683b3c(param_1,awStack_28);
  if (iVar1 == 0) {
    FUN_c0684adc(local_18);
    uVar2 = 0x80000010;
  }
  else {
    hKey = (HKEY)FUN_c06838dc(-1,param_2 & 1);
    if (hKey != (HKEY)0x0) {
      if ((param_2 & 1) == 0) {
        iVar1 = RegDeleteValueW(hKey,awStack_28);
      }
      else {
        local_30[0] = '\0';
        local_30[1] = '\0';
        local_30[2] = '\0';
        local_30[3] = '\0';
        iVar1 = RegSetValueExW(hKey,awStack_28,0,4,local_30,4);
      }
      RegCloseKey(hKey);
      if (iVar1 == 0) {
        FUN_c0684adc(local_18);
        return 0;
      }
    }
    FUN_c0684adc(local_18);
    uVar2 = 0x80000048;
  }
  return uVar2;
}



/* c0683d84 FUN_c0683d84 */

/* WARNING: Removing unreachable block (ram,0xc0683ecc) */
/* Boundary evidence: original MIPS .pdata c0683d84..c0683eff. Semantic name remains unreviewed. */

LPWSTR FUN_c0683d84(int param_1)

{
  HKEY hKey;
  LSTATUS LVar1;
  LPWSTR pWVar2;
  LPWSTR lpValueName;
  DWORD dwIndex;
  DWORD local_38 [3];
  BYTE aBStack_2c [4];
  DWORD aDStack_28 [2];
  
  hKey = (HKEY)FUN_c06838dc(param_1,0);
  pWVar2 = (LPWSTR)0x0;
  if (hKey != (HKEY)0x0) {
    LVar1 = RegQueryInfoKeyW(hKey,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPDWORD)0x0,local_38,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (PFILETIME)0x0);
    if ((LVar1 == 0) && (pWVar2 = LocalAlloc(0x40,local_38[0] * 8 + 2), pWVar2 != (LPWSTR)0x0)) {
      dwIndex = 0;
      *pWVar2 = L'\0';
      lpValueName = pWVar2;
      do {
        local_38[1] = 4;
        local_38[2] = 4;
        LVar1 = RegEnumValueW(hKey,dwIndex,lpValueName,local_38 + 2,(LPDWORD)0x0,aDStack_28,
                              aBStack_2c,local_38 + 1);
        if (LVar1 == 0) {
          if (pWVar2 < lpValueName) {
            lpValueName[-1] = L',';
          }
          lpValueName[3] = L'\0';
          lpValueName = lpValueName + 4;
        }
        dwIndex = dwIndex + 1;
      } while (LVar1 == 0);
      RegCloseKey(hKey);
    }
    else {
      RegCloseKey(hKey);
      pWVar2 = (LPWSTR)0x0;
    }
  }
  return pWVar2;
}



/* c0683f00 FUN_c0683f00 */

/* Boundary evidence: original MIPS .pdata c0683f00..c0684483. Semantic name remains unreviewed. */

void FUN_c0683f00(wchar_t *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,
                 wchar_t *param_5,wchar_t *param_6,wchar_t *param_7,undefined4 param_8,
                 wchar_t *param_9,undefined4 param_10,wchar_t *param_11,int param_12,uint param_13,
                 int param_14)

{
  wchar_t wVar1;
  bool bVar2;
  undefined *_Source;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  int local_3c;
  wchar_t local_38;
  undefined1 auStack_36 [2];
  wchar_t *local_34;
  wchar_t *local_30;
  
  local_38 = L'\0';
  memset(auStack_36,0,2);
  bVar2 = false;
  sVar3 = wcslen(param_1);
  uVar9 = (sVar3 + 1) * 2;
  if (uVar9 < 8) {
    return;
  }
  pwVar4 = LocalAlloc(0x40,uVar9);
  if (pwVar4 == (wchar_t *)0x0) {
    return;
  }
  local_30 = pwVar4;
  wcscpy(pwVar4,param_1);
  pwVar5 = (wchar_t *)FUN_c0683468((ushort *)(pwVar4 + 1),0x20,&local_3c);
  local_34 = pwVar5;
  pwVar6 = (wchar_t *)FUN_c0683468((ushort *)0x0,0x20,&local_3c);
  pwVar4 = (wchar_t *)PTR_DAT_c0686104;
  if (*pwVar6 == L'(') {
    pwVar6 = pwVar6 + 1;
    if ((*pwVar6 != L')') && (sVar3 = wcslen(pwVar6), pwVar4 = pwVar6, pwVar6[sVar3 - 1] == L')')) {
      sVar3 = wcslen(pwVar6);
      pwVar6[sVar3 - 1] = L'\0';
    }
    pwVar6 = (wchar_t *)FUN_c0683468((ushort *)0x0,0,&local_3c);
  }
  else if (local_3c != 0) {
    sVar3 = wcslen(pwVar6);
    pwVar6[sVar3 - 1] = L' ';
  }
  uVar9 = 0;
  wVar1 = *pwVar6;
  pwVar11 = pwVar6;
  while (wVar1 != L'\0') {
    wVar1 = *pwVar11;
    if ((((wVar1 == L'|') || (wVar1 == L'^')) || (wVar1 == L'\r')) || (wVar1 == L'\n')) {
      pwVar6[uVar9] = L'\0';
      break;
    }
    uVar9 = uVar9 + 1 & 0xffff;
    pwVar11 = pwVar6 + uVar9;
    wVar1 = *pwVar11;
  }
  if (param_14 == 1) {
    FUN_c068385c(pwVar6,L'-');
  }
  FUN_c068385c(pwVar6,L' ');
  pwVar11 = local_30;
  if (param_14 != 1) {
LAB_c068425c:
    if (param_14 == 2) {
      if ((*(uint *)(param_12 + 0x24) & 8) == 0) {
        pwVar11 = param_5;
        if ((*(uint *)(param_12 + 0x24) & 2) != 0) {
          pwVar11 = param_6;
        }
      }
      else if (((param_13 & 4) != 0) || (pwVar11 = param_4, pwVar4 == (wchar_t *)PTR_DAT_c0686104))
      {
        bVar2 = true;
        pwVar11 = param_4;
      }
    }
    goto LAB_c06842b0;
  }
  if (pwVar5 == (wchar_t *)0x0) {
    *(undefined4 *)(param_12 + 0x20) = 0;
  }
  else {
    lVar7 = wcstol(pwVar5,(wchar_t **)0x0,10);
    *(long *)(param_12 + 0x20) = lVar7;
  }
  if (param_9 == (wchar_t *)0x0) {
    *(undefined4 *)(param_12 + 0x1c) = 0;
  }
  else {
    lVar7 = wcstol(param_9,(wchar_t **)0x0,10);
    *(long *)(param_12 + 0x1c) = lVar7;
  }
  iVar8 = wcscmp(local_34,param_9);
  if (iVar8 == 0) {
    if (pwVar4 == (wchar_t *)0x0) {
      if (param_7 == (wchar_t *)0x0) goto LAB_c06841cc;
    }
    else if (param_7 != (wchar_t *)0x0) {
LAB_c06841cc:
      iVar8 = wcscmp(pwVar4,param_7);
      if (iVar8 == 0) {
        if ((param_13 & 8) != 0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 4;
          pwVar11 = param_5;
          goto LAB_c06842b0;
        }
        iVar8 = FUN_c0683c20(param_1);
        if (iVar8 == 0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 0x28;
          pwVar11 = param_4;
          goto LAB_c068425c;
        }
        uVar9 = *(uint *)(param_12 + 0x24) | 0x10;
        param_6 = param_5;
        goto LAB_c068417c;
      }
    }
    if (((param_13 & 4) != 0) || (pwVar4 == (wchar_t *)PTR_DAT_c0686104)) {
      bVar2 = true;
      *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 8;
      pwVar11 = param_4;
      goto LAB_c06842b0;
    }
    uVar9 = *(uint *)(param_12 + 0x24) | 4;
    param_6 = param_5;
  }
  else {
    uVar9 = *(uint *)(param_12 + 0x24) | 2;
  }
LAB_c068417c:
  *(uint *)(param_12 + 0x24) = uVar9;
  pwVar11 = param_6;
LAB_c06842b0:
  pwVar5 = local_34;
  _Source = PTR_DAT_c0686108;
  wVar1 = *pwVar11;
  do {
    if (wVar1 == L'\0') {
      LocalFree(local_30);
      if (param_14 == 1) {
        pwVar4 = wcschr(param_11,L'$');
        if (pwVar4 != (wchar_t *)0x0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 0x40;
        }
        pwVar4 = wcschr(param_11,L'@');
        if (pwVar4 != (wchar_t *)0x0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 0x80;
        }
        pwVar4 = wcschr(param_11,L'W');
        if (pwVar4 != (wchar_t *)0x0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 0x100;
        }
        pwVar4 = wcschr(param_11,L'?');
        if (pwVar4 != (wchar_t *)0x0) {
          *(uint *)(param_12 + 0x24) = *(uint *)(param_12 + 0x24) | 0x200;
        }
      }
      return;
    }
    if ((wVar1 == L'e') || (wVar1 == L'E')) {
      pwVar10 = pwVar5;
      if (pwVar5 != (wchar_t *)0x0) {
LAB_c0684388:
        wcscat(param_11,pwVar10);
        pwVar10 = (wchar_t *)_Source;
        if (param_14 == 2) goto LAB_c06843a0;
      }
    }
    else if ((wVar1 == L'f') || (wVar1 == L'F')) {
      if (pwVar4 != (wchar_t *)0x0) {
        pwVar10 = pwVar4;
        if (param_14 == 2) {
          wcscat(param_11,(wchar_t *)_Source);
        }
        goto LAB_c0684388;
      }
    }
    else {
      if ((wVar1 == L'g') || (wVar1 == L'G')) {
        pwVar10 = pwVar6;
        if ((pwVar4 != (wchar_t *)0x0) && ((bVar2 && (wcscat(param_11,pwVar4), param_14 == 2)))) {
          wcscat(param_11,(wchar_t *)_Source);
        }
      }
      else {
        pwVar10 = &local_38;
        local_38 = wVar1;
      }
LAB_c06843a0:
      wcscat(param_11,pwVar10);
    }
    pwVar11 = pwVar11 + 1;
    wVar1 = *pwVar11;
  } while( true );
}



/* c0684484 FUN_c0684484 */

/* Boundary evidence: original MIPS .pdata c0684484..c06847d3. Semantic name remains unreviewed. */

undefined4
FUN_c0684484(undefined4 param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4,uint param_5,
            uint *param_6)

{
  LSTATUS LVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *_Dest;
  SIZE_T uBytes;
  wchar_t *hMem;
  uint *puVar5;
  wchar_t *local_68;
  HKEY local_64;
  HKEY local_60;
  DWORD local_5c;
  undefined4 local_58;
  DWORD DStack_54;
  long local_50;
  undefined4 local_4c;
  wchar_t *local_48;
  wchar_t *local_44;
  wchar_t *local_40;
  wchar_t *local_3c;
  wchar_t *local_38;
  wchar_t *local_34;
  int local_30;
  
  puVar5 = param_6 + 2;
  *puVar5 = 0x28;
  param_6[1] = 0x28;
  param_6[7] = 0;
  param_6[8] = 0;
  param_6[9] = 0;
  _Dest = (wchar_t *)0x0;
  local_60 = (HKEY)0x0;
  local_64 = (HKEY)0x0;
  local_68 = (wchar_t *)0x0;
  hMem = local_68;
  if (*param_3 == L'+') {
    sVar3 = wcslen(param_3);
    uBytes = (sVar3 + 0x51) * 2;
    _Dest = LocalAlloc(0x40,uBytes);
    if (_Dest == (wchar_t *)0x0) {
      return 0x8007000e;
    }
    *_Dest = L'\0';
    param_6[9] = param_6[9] | 1;
    LVar1 = FUN_c06834ec(&local_60,&local_64,&local_68,&local_5c,&DStack_54,(LPBYTE)&local_58);
    hMem = local_68;
    if (LVar1 == 0) {
      FUN_c06836c0(local_64,local_58,local_68,local_5c,&local_50);
      if (local_30 == 0) {
        pwVar4 = L"T";
      }
      else {
        pwVar4 = L"P";
      }
      wcscpy(_Dest,pwVar4);
      if (local_38 != (wchar_t *)0x0) {
        wcscat(_Dest,local_38);
      }
      FUN_c0683f00(param_3,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
                   local_30,_Dest,(int)param_6,param_5,1);
      pwVar2 = LocalAlloc(0x40,uBytes);
      pwVar4 = _Dest;
      if (pwVar2 != (wchar_t *)0x0) {
        FUN_c0683f00(param_3,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34
                     ,local_30,pwVar2,(int)param_6,param_5,2);
        pwVar4 = pwVar2;
      }
      param_3 = _Dest;
      pwVar2 = _Dest;
      if (pwVar4 != (wchar_t *)0x0) goto LAB_c06846b4;
    }
  }
  pwVar4 = param_3;
  pwVar2 = pwVar4;
LAB_c06846b4:
  sVar3 = wcslen(pwVar2);
  FUN_c067bc68((int)param_6,*param_6,(int *)puVar5,param_6 + 1,(int *)(param_6 + 4),param_6 + 3,
               pwVar2,(sVar3 + 1) * 2);
  sVar3 = wcslen(pwVar4);
  FUN_c067bc68((int)param_6,*param_6,(int *)puVar5,param_6 + 1,(int *)(param_6 + 6),param_6 + 5,
               pwVar4,(sVar3 + 1) * 2);
  if (hMem != (wchar_t *)0x0) {
    LocalFree(hMem);
  }
  if (_Dest != (wchar_t *)0x0) {
    LocalFree(_Dest);
  }
  if (((pwVar4 != _Dest) && (pwVar4 != pwVar2)) && (pwVar4 != (wchar_t *)0x0)) {
    LocalFree(pwVar4);
  }
  if (local_64 != (HKEY)0x0) {
    RegCloseKey(local_64);
  }
  if (local_60 != (HKEY)0x0) {
    RegCloseKey(local_60);
  }
  return 0;
}



/* c0684974 entry */

/* Boundary evidence: original MIPS .pdata c0684974..c06849e7. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c06849e8();
    FUN_c0684cbc();
  }
  uVar1 = FUN_c0671f24(param_1,param_2);
  if (param_2 == 0) {
    FUN_c0684c44();
  }
  return uVar1;
}



/* c06849e8 FUN_c06849e8 */

/* Boundary evidence: original MIPS .pdata c06849e8..c0684a5b. Semantic name remains unreviewed. */

void FUN_c06849e8(void)

{
  uint uVar1;
  
  if ((DAT_c068610c == 0) || (DAT_c068610c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c068610c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c068610c == 0) {
      DAT_c068610c = 0xb064;
    }
  }
  DAT_c0686110 = ~DAT_c068610c;
  return;
}



/* c0684a5c FUN_c0684a5c */

/* Boundary evidence: original MIPS .pdata c0684a5c..c0684aaf. Semantic name remains unreviewed. */

void FUN_c0684a5c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0684adc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0684ab0 FUN_c0684ab0 */

/* Boundary evidence: original MIPS .pdata c0684ab0..c0684adb. Semantic name remains unreviewed. */

undefined4 FUN_c0684ab0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0684a5c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0684adc FUN_c0684adc */

/* Boundary evidence: original MIPS .pdata c0684adc..c0684b23. Semantic name remains unreviewed. */

void FUN_c0684adc(uint param_1)

{
  if ((param_1 == DAT_c068610c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0684b24 FUN_c0684b24 */

/* Boundary evidence: original MIPS .pdata c0684b24..c0684c43. Semantic name remains unreviewed. */

void FUN_c0684b24(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0686124 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c068630c;
    if (DAT_c068630c != (undefined4 *)0x0) {
      while (DAT_c0686308 = DAT_c0686308 + -1, _Memory <= DAT_c0686308) {
        if ((code *)*DAT_c0686308 != (code *)0x0) {
          (*(code *)*DAT_c0686308)();
          _Memory = DAT_c068630c;
        }
      }
      free(_Memory);
      DAT_c0686308 = (undefined4 *)0x0;
      DAT_c068630c = (undefined4 *)0x0;
    }
    FUN_c0684c68((undefined4 *)&DAT_c0671010,(undefined4 *)&DAT_c0671014);
  }
  FUN_c0684c68((undefined4 *)&DAT_c0671018,(undefined4 *)&DAT_c067101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c0686310,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0684c44 FUN_c0684c44 */

/* Boundary evidence: original MIPS .pdata c0684c44..c0684c67. Semantic name remains unreviewed. */

void FUN_c0684c44(void)

{
  FUN_c0684b24(0,0,1);
  return;
}



/* c0684c68 FUN_c0684c68 */

/* Boundary evidence: original MIPS .pdata c0684c68..c0684cbb. Semantic name remains unreviewed. */

void FUN_c0684c68(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0684cbc FUN_c0684cbc */

/* Boundary evidence: original MIPS .pdata c0684cbc..c0684cf7. Semantic name remains unreviewed. */

void FUN_c0684cbc(void)

{
  FUN_c0684c68((undefined4 *)&DAT_c0671008,(undefined4 *)&DAT_c067100c);
  FUN_c0684c68((undefined4 *)&DAT_c0671000,(undefined4 *)&DAT_c0671004);
  return;
}


