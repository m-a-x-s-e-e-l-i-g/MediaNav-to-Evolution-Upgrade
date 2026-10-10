/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 0001151c entry */

/* Boundary evidence: original MIPS .pdata 0001151c..0001257f. Semantic name remains unreviewed. */

undefined4 entry(void)

{
  LSTATUS LVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  uint uVar5;
  LPBYTE lpData;
  BYTE *pBVar6;
  DWORD local_1cb8;
  HKEY local_1cb4;
  undefined4 local_1cb0;
  DWORD DStack_1cac;
  int local_1ca8;
  BYTE aBStack_1ca4 [4];
  undefined4 local_1ca0;
  undefined4 local_1c9c;
  undefined4 local_1c98;
  undefined4 local_1c94;
  undefined1 auStack_1c90 [22];
  undefined1 auStack_1c7a [258];
  undefined4 local_1b78;
  undefined1 local_1b74;
  undefined1 local_1b73;
  undefined1 local_1b72;
  undefined1 local_1b71;
  undefined1 local_1b70;
  undefined1 local_1b6f;
  undefined1 local_1b6e;
  undefined1 local_1b6d;
  undefined1 local_1b6c;
  undefined1 local_1b6b;
  undefined1 local_1b6a;
  undefined1 local_1b69;
  undefined1 local_1b68;
  undefined1 local_1b67;
  undefined1 local_1b66;
  undefined1 local_1b65;
  undefined1 local_1b64;
  undefined1 local_1b63;
  undefined1 local_1b62;
  undefined1 local_1b61;
  undefined4 local_1b60;
  undefined4 local_1b5c;
  undefined4 local_1b58;
  undefined1 auStack_1b54 [520];
  undefined1 auStack_194c [520];
  undefined1 auStack_1744 [520];
  undefined1 auStack_153c [34];
  undefined1 auStack_151a [258];
  undefined1 auStack_1418 [66];
  undefined1 auStack_13d6 [402];
  undefined1 auStack_1244 [402];
  undefined1 auStack_10b2 [402];
  undefined4 local_f20;
  char local_f10 [5];
  char local_f0b;
  char local_f0a;
  undefined1 auStack_f09 [97];
  undefined1 auStack_ea8 [29];
  char local_e8b;
  undefined1 auStack_e89 [73];
  BYTE aBStack_e40 [1000];
  WCHAR aWStack_a58 [100];
  wchar_t awStack_990 [100];
  BYTE aBStack_8c8 [400];
  BYTE aBStack_738 [1800];
  uint local_30;
  
  local_30 = DAT_00013030;
  local_f10[4] = 0x79;
  builtin_strncpy(local_f10,"Entr",4);
  local_f0b = ' ';
  local_f0a = '\0';
  memset(auStack_f09,0,0x5d);
  memcpy(auStack_ea8,"\\Comm\\Ras\\Init\\RasEntry\\Entry ",0x1f);
  memset(auStack_e89,0,0x45);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"\\Comm\\Ras\\Init",0,0xf003f,&local_1cb4);
  if (LVar1 == 0) {
    local_1cb8 = 4;
    LVar1 = RegQueryValueExW(local_1cb4,L"AutoCnct",(LPDWORD)0x0,&DStack_1cac,(LPBYTE)&local_1ca8,
                             &local_1cb8);
    if (LVar1 == 0) {
      local_1cb8 = 200;
      LVar1 = RegQueryValueExW(local_1cb4,L"Cnct",(LPDWORD)0x0,&DStack_1cac,(LPBYTE)awStack_990,
                               &local_1cb8);
      if (LVar1 == 0) {
        uVar4 = 1;
        lpData = aBStack_738;
        do {
          local_f0b = (char)uVar4 + '0';
          wsprintfW(aWStack_a58,L"%S",local_f10);
          local_1cb8 = 0x2a;
          LVar1 = RegQueryValueExW(local_1cb4,aWStack_a58,(LPDWORD)0x0,&DStack_1cac,lpData,
                                   &local_1cb8);
          if (LVar1 != 0) break;
          uVar4 = uVar4 + 1;
          lpData = lpData + 200;
        } while (uVar4 < 10);
        RegCloseKey(local_1cb4);
        LVar1 = RegOpenKeyExW((HKEY)0x80000001,L"\\ControlPanel\\Comm",0,0xf003f,&local_1cb4);
        if (LVar1 != 0) goto LAB_000115f4;
        local_1cb8 = 4;
        LVar1 = RegQueryValueExW(local_1cb4,L"AutoCnct",(LPDWORD)0x0,&DStack_1cac,aBStack_1ca4,
                                 &local_1cb8);
        if (LVar1 == 0) {
          local_1cb8 = 200;
          LVar1 = RegQueryValueExW(local_1cb4,L"Cnct",(LPDWORD)0x0,&DStack_1cac,aBStack_8c8,
                                   &local_1cb8);
          if (LVar1 == 0) {
            if ((local_1ca8 != 1) &&
               ((local_1ca8 != 2 || (iVar2 = RasValidateEntryName(0,aBStack_8c8), iVar2 == 0xb7))))
            {
LAB_00011874:
              RegCloseKey(local_1cb4);
              uVar5 = 1;
              if (uVar4 != 1) {
                pBVar6 = aBStack_738;
                do {
                  memset(&local_1ca0,0,0xd90);
                  local_1ca0 = 0xd90;
                  local_e8b = (char)uVar5 + '0';
                  wsprintfW(aWStack_a58,L"%S",auStack_ea8);
                  LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_a58,0,0xf003f,&local_1cb4);
                  if (LVar1 != 0) goto LAB_000115f4;
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwfOptions",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1c9c = local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwCountryID",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1c98 = local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwCountryCode",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1c94 = local_1cb0;
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szAreaCode",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1c90,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szLocalPhoneNumber",(LPDWORD)0x0,
                                           &DStack_1cac,aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1c7a,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwAlternateOffset",(LPDWORD)0x0,&DStack_1cac
                                           ,(LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b78 = local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddr_a",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b74 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddr_b",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b73 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddr_c",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b72 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddr_d",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b71 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDns_a",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b70 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDns_b",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6f = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDns_c",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6e = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDns_d",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6d = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDnsAlt_a",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6c = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDnsAlt_b",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6b = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDnsAlt_c",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b6a = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrDnsAlt_d",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b69 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWins_a",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b68 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWins_b",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b67 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWins_c",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b66 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWins_d",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b65 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWinsAlt_a",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b64 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWinsAlt_b",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b63 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWinsAlt_c",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b62 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"ipaddrWinsAlt_d",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b61 = (undefined1)local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwFrameSize",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b60 = local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwfNetProtocols",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b5c = local_1cb0;
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwFramingProtocol",(LPDWORD)0x0,&DStack_1cac
                                           ,(LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_1b58 = local_1cb0;
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szScript",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1b54,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szAutodialDll",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_194c,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szAutodialFunc",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1744,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szDeviceType",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_153c,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szDeviceName",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_151a,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szX25PadType",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1418,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szX25Address",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_13d6,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szX25Facilities",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_1244,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 1000;
                  LVar1 = RegQueryValueExW(local_1cb4,L"szX25UserData",(LPDWORD)0x0,&DStack_1cac,
                                           aBStack_e40,&local_1cb8);
                  if (LVar1 == 0) {
                    memcpy(auStack_10b2,aBStack_e40,local_1cb8);
                  }
                  local_1cb8 = 4;
                  LVar1 = RegQueryValueExW(local_1cb4,L"dwChannels",(LPDWORD)0x0,&DStack_1cac,
                                           (LPBYTE)&local_1cb0,&local_1cb8);
                  if (LVar1 == 0) {
                    local_f20 = local_1cb0;
                  }
                  iVar2 = RasSetEntryProperties(0,pBVar6,&local_1ca0,0xd90,0,0);
                  if (iVar2 != 0) {
                    RegCloseKey(local_1cb4);
                    goto LAB_000115f4;
                  }
                  RegCloseKey(local_1cb4);
                  uVar5 = uVar5 + 1;
                  pBVar6 = pBVar6 + 200;
                } while (uVar5 <= uVar4 - 1);
              }
              FUN_00012630(local_30);
              return 1;
            }
            local_1ca8 = 1;
            LVar1 = RegSetValueExW(local_1cb4,L"AutoCnct",0,4,(BYTE *)&local_1ca8,4);
            if (LVar1 == 0) {
              sVar3 = wcslen(awStack_990);
              LVar1 = RegSetValueExW(local_1cb4,L"Cnct",0,1,(BYTE *)awStack_990,(sVar3 + 1) * 2);
              if (LVar1 == 0) goto LAB_00011874;
            }
          }
        }
      }
    }
    RegCloseKey(local_1cb4);
  }
LAB_000115f4:
  FUN_00012630(local_30);
  return 0;
}



/* 000125b0 FUN_000125b0 */

/* Boundary evidence: original MIPS .pdata 000125b0..00012603. Semantic name remains unreviewed. */

void FUN_000125b0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012630(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012604 FUN_00012604 */

/* Boundary evidence: original MIPS .pdata 00012604..0001262f. Semantic name remains unreviewed. */

undefined4 FUN_00012604(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000125b0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012630 FUN_00012630 */

/* Boundary evidence: original MIPS .pdata 00012630..00012677. Semantic name remains unreviewed. */

void FUN_00012630(uint param_1)

{
  if ((param_1 == DAT_00013030) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


