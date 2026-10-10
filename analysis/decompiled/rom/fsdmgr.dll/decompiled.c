/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c03a2ecc FUN_c03a2ecc */

/* Boundary evidence: original MIPS .pdata c03a2ecc..c03a2f07. Semantic name remains unreviewed. */

undefined4 FUN_c03a2ecc(HMODULE param_1,int param_2)

{
  if ((param_2 != 0) && (param_2 == 1)) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c03a2f08 FUN_c03a2f08 */

/* Boundary evidence: original MIPS .pdata c03a2f08..c03a3133. Semantic name remains unreviewed. */

STRSAFE_LPWSTR
FUN_c03a2f08(HKEY param_1,uint param_2,STRSAFE_LPCWSTR param_3,STRSAFE_LPWSTR param_4,int param_5)

{
  STRSAFE_LPWSTR pwVar1;
  int iVar2;
  STRSAFE_LPWSTR pwVar3;
  DWORD DVar4;
  HKEY local_248;
  uint local_244;
  DWORD local_240;
  uint local_23c;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  local_240 = 0x104;
  DVar4 = 0;
  iVar2 = FUN_c03accd0(param_1,0,aWStack_238,&local_240);
  do {
    if (iVar2 != 0) {
      FUN_c03c216c(local_30);
      return param_4;
    }
    local_240 = 0x104;
    local_248 = (HKEY)0x0;
    iVar2 = FUN_c03acd00(param_1,aWStack_238,&local_248);
    if (iVar2 == 0) {
      local_244 = 0xffffffff;
      FUN_c03acafc(local_248,(LPCWSTR)PTR_u_Order_c03c52a8,(LPBYTE)&local_244);
      local_23c = 0;
      FUN_c03acafc(local_248,(LPCWSTR)PTR_u_LoadFlags_c03c52ac,(LPBYTE)&local_23c);
      if (((local_23c & 2) == 0) && ((local_23c & 1) == 0)) {
        local_23c = local_23c | 2;
      }
      if ((local_23c & param_2) == 0) {
        FUN_c03acd64(local_248);
      }
      else {
        pwVar1 = (STRSAFE_LPWSTR)0x0;
        for (pwVar3 = param_4; pwVar3 != (STRSAFE_LPWSTR)0x0;
            pwVar3 = *(STRSAFE_LPWSTR *)(pwVar3 + 0x20a)) {
          if (param_5 == 0) {
            if (local_244 < *(uint *)(pwVar3 + 0x208)) break;
          }
          else if (*(uint *)(pwVar3 + 0x208) < local_244) break;
          pwVar1 = pwVar3;
        }
        pwVar3 = operator_new(0x418);
        if (pwVar3 != (STRSAFE_LPWSTR)0x0) {
          if (param_3 != (STRSAFE_LPCWSTR)0x0) {
            StringCbCopyW(pwVar3,0x208,param_3);
          }
          *(uint *)(pwVar3 + 0x208) = local_244;
          StringCbCopyW(pwVar3 + 0x104,0x208,aWStack_238);
          if (pwVar1 == (STRSAFE_LPWSTR)0x0) {
            *(STRSAFE_LPWSTR *)(pwVar3 + 0x20a) = param_4;
            param_4 = pwVar3;
          }
          else {
            *(undefined4 *)(pwVar3 + 0x20a) = *(undefined4 *)(pwVar1 + 0x20a);
            *(STRSAFE_LPWSTR *)(pwVar1 + 0x20a) = pwVar3;
          }
        }
        FUN_c03acd64(local_248);
      }
    }
    DVar4 = DVar4 + 1;
    iVar2 = FUN_c03accd0(param_1,DVar4,aWStack_238,&local_240);
  } while( true );
}



/* c03a3134 STOREMGR_RegisterFileSystemFunction */

/* Boundary evidence: original MIPS .pdata c03a3134..c03a315b. Semantic name remains unreviewed. */

undefined4 STOREMGR_RegisterFileSystemFunction(undefined4 param_1)

{
                    /* 0x3134  43  STOREMGR_RegisterFileSystemFunction */
  FUN_c03af4a8(DAT_c03c623c,param_1);
  return 1;
}



/* c03a315c STOREMGR_ProcNotify */

/* Boundary evidence: original MIPS .pdata c03a315c..c03a317f. Semantic name remains unreviewed. */

void STOREMGR_ProcNotify(int param_1,int param_2)

{
                    /* 0x315c  41  STOREMGR_ProcNotify */
  if (param_1 == 0) {
    FS_ProcessCleanupVolumes(param_2);
  }
  return;
}



/* c03a3180 FUN_c03a3180 */

/* Boundary evidence: original MIPS .pdata c03a3180..c03a333f. Semantic name remains unreviewed. */

undefined4 FUN_c03a3180(int *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*param_1 == 0) {
    iVar3 = LoadDriver(param_2);
    *param_1 = iVar3;
    if (iVar3 == 0) {
      uVar2 = 0x7e;
    }
    else {
      iVar3 = GetProcAddressW(iVar3,PTR_u_FSDACL_CreateVolume_c03c51ec);
      puVar1 = PTR_u_FSDACL_DeleteVolume_c03c51f0;
      param_1[1] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_LockVolume_c03c51f4;
      param_1[2] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_UnlockVolume_c03c51f8;
      param_1[3] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_AddReference_c03c51fc;
      param_1[4] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_RemoveReference_c03c5200;
      param_1[5] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_FreeSecurityDescriptor_c03c5204;
      param_1[6] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_GetFileSecurity_c03c5208;
      param_1[7] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_SetFileSecurity_c03c520c;
      param_1[8] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      puVar1 = PTR_u_FSDACL_VolumeAccessCheck_c03c5210;
      param_1[9] = iVar3;
      iVar3 = GetProcAddressW(*param_1,puVar1);
      param_1[10] = iVar3;
      if ((((((param_1[1] == 0) || (param_1[2] == 0)) || (param_1[3] == 0)) ||
           ((param_1[4] == 0 || (param_1[5] == 0)))) ||
          ((param_1[6] == 0 || ((param_1[7] == 0 || (param_1[8] == 0)))))) ||
         ((param_1[9] == 0 || (iVar3 == 0)))) {
        FreeLibrary((HMODULE)*param_1);
        uVar2 = 0x7f;
        *param_1 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 0xb7;
  }
  return uVar2;
}



/* c03a3340 FUN_c03a3340 */

/* Boundary evidence: original MIPS .pdata c03a3340..c03a33af. Semantic name remains unreviewed. */

void FUN_c03a3340(int param_1)

{
  (**(code **)(param_1 + 0xac))(*(undefined4 *)(param_1 + 0x9c));
  return;
}



/* c03a33b0 FUN_c03a33b0 */

/* Boundary evidence: original MIPS .pdata c03a33b0..c03a33d7. Semantic name remains unreviewed. */

undefined4 FUN_c03a33b0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a33d8 FUN_c03a33d8 */

/* Boundary evidence: original MIPS .pdata c03a33d8..c03a3433. Semantic name remains unreviewed. */

void FUN_c03a33d8(int param_1)

{
  (**(code **)(param_1 + 0xb4))(*(undefined4 *)(param_1 + 0x9c));
  return;
}



/* c03a3434 FUN_c03a3434 */

/* Boundary evidence: original MIPS .pdata c03a3434..c03a345b. Semantic name remains unreviewed. */

undefined4 FUN_c03a3434(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a345c FUN_c03a345c */

/* Boundary evidence: original MIPS .pdata c03a345c..c03a34f3. Semantic name remains unreviewed. */

int FUN_c03a345c(int param_1,wchar_t *param_2,size_t param_3)

{
  int iVar1;
  undefined4 local_18 [2];
  
  if ((*(wchar_t **)(param_1 + 0xc) == (wchar_t *)0x0) ||
     (iVar1 = wcscmp(param_2,*(wchar_t **)(param_1 + 0xc)), iVar1 != 0)) {
    local_18[0] = 0;
    iVar1 = FUN_c03ac970(local_18,param_2,param_3);
    if (iVar1 == 0) {
      if (*(void **)(param_1 + 0xc) != (void *)0x0) {
        operator_delete(*(void **)(param_1 + 0xc));
      }
      *(undefined4 *)(param_1 + 0xc) = local_18[0];
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* c03a34f4 FUN_c03a34f4 */

/* Boundary evidence: original MIPS .pdata c03a34f4..c03a35cf. Semantic name remains unreviewed. */

void FUN_c03a34f4(int *param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
  HANDLE hDevice;
  
  hDevice = (HANDLE)(**(code **)(*param_1 + 0x10))();
  if (param_3 == (LPVOID)0x0) {
    if (param_5 == (LPVOID)0x0) goto LAB_c03a3530;
  }
  else if ((int)param_3 < 0) goto LAB_c03a3530;
  if ((param_5 == (LPVOID)0x0) || (-1 < (int)param_5)) {
    ForwardDeviceIoControl(hDevice,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
LAB_c03a3530:
  DeviceIoControl(hDevice,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c03a35d0 FUN_c03a35d0 */

/* Boundary evidence: original MIPS .pdata c03a35d0..c03a361b. Semantic name remains unreviewed. */

undefined4 * FUN_c03a35d0(undefined4 *param_1,uint param_2)

{
  FUN_c03b0f88(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03a361c FUN_c03a361c */

/* Boundary evidence: original MIPS .pdata c03a361c..c03a3687. Semantic name remains unreviewed. */

undefined4 * FUN_c03a361c(undefined4 *param_1,int param_2)

{
  HANDLE pvVar1;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = &PTR_FUN_c03a127c;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  if (param_2 != 0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
    param_1[5] = pvVar1;
  }
  return param_1;
}



/* c03a3688 FUN_c03a3688 */

/* Boundary evidence: original MIPS .pdata c03a3688..c03a36d7. Semantic name remains unreviewed. */

void FUN_c03a3688(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03a127c;
  if ((HANDLE)param_1[5] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[5]);
    param_1[5] = 0;
  }
  FUN_c03b0f88(param_1);
  return;
}



/* c03a36d8 FUN_c03a36d8 */

/* Boundary evidence: original MIPS .pdata c03a36d8..c03a3723. Semantic name remains unreviewed. */

undefined4 * FUN_c03a36d8(undefined4 *param_1,uint param_2)

{
  FUN_c03a3688(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03a3724 FUN_c03a3724 */

/* Boundary evidence: original MIPS .pdata c03a3724..c03a37a3. Semantic name remains unreviewed. */

undefined4 * FUN_c03a3724(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  *param_1 = &PTR_FUN_c03a129c;
  param_1[8] = 0;
  if ((param_2 != (LPCWSTR)0x0) && (*param_2 != L'\0')) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,param_2);
    param_1[8] = pvVar1;
  }
  param_1[7] = 0;
  return param_1;
}



/* c03a37a4 FUN_c03a37a4 */

/* Boundary evidence: original MIPS .pdata c03a37a4..c03a37ef. Semantic name remains unreviewed. */

void FUN_c03a37a4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03a129c;
  if ((HANDLE)param_1[8] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[8]);
  }
  FUN_c03a3688(param_1);
  return;
}



/* c03a37f0 FUN_c03a37f0 */

/* Boundary evidence: original MIPS .pdata c03a37f0..c03a3847. Semantic name remains unreviewed. */

undefined4 FUN_c03a37f0(undefined4 param_1,int param_2)

{
  memset((void *)(param_2 + 0x10),0,0x40);
  memset((void *)(param_2 + 0x50),0,0x40);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xffffffdf;
  return 0;
}



/* c03a3850 FUN_c03a3850 */

/* Boundary evidence: original MIPS .pdata c03a3850..c03a3877. Semantic name remains unreviewed. */

void FUN_c03a3850(int param_1)

{
  if (*(int *)(param_1 + 0x20) != 0) {
    EventModify(*(int *)(param_1 + 0x20),3);
  }
  return;
}



/* c03a3878 FUN_c03a3878 */

/* Boundary evidence: original MIPS .pdata c03a3878..c03a38b7. Semantic name remains unreviewed. */

undefined4 FUN_c03a3878(undefined4 param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
  HVar1 = StringCchCopyW(param_2,param_3,L"NullDisk");
  if (HVar1 < 0) {
    uVar2 = 0x7a;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03a38c0 FUN_c03a38c0 */

/* Boundary evidence: original MIPS .pdata c03a38c0..c03a390b. Semantic name remains unreviewed. */

undefined4 * FUN_c03a38c0(undefined4 *param_1,uint param_2)

{
  FUN_c03a37a4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03a390c FUN_c03a390c */

/* Boundary evidence: original MIPS .pdata c03a390c..c03a3987. Semantic name remains unreviewed. */

DWORD FUN_c03a390c(int param_1)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x3c);
  iVar1 = DeregisterAFS(uVar3);
  if ((iVar1 == 0) || (iVar1 = DeregisterAFSName(uVar3), iVar1 == 0)) {
    DVar2 = FUN_c03ac938(0x1f);
  }
  else {
    if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0x0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x14),0xffffffff);
    }
    DVar2 = 0;
  }
  return DVar2;
}



/* c03a3988 FUN_c03a3988 */

/* Boundary evidence: original MIPS .pdata c03a3988..c03a3b5b. Semantic name remains unreviewed. */

DWORD FUN_c03a3988(int *param_1,int *param_2,undefined4 param_3,int param_4)

{
  DWORD DVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  DVar1 = (**(code **)(*param_2 + 4))(param_2);
  if (DVar1 == 0) {
    puVar2 = operator_new(0x4c);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c03ad240(puVar2,DAT_c03c623c,param_1,param_2,DAT_c03c5390,param_3);
    }
    if (piVar3 == (int *)0x0) {
      DVar1 = 8;
    }
    else {
      param_1[6] = (int)piVar3;
      if (param_1[5] != 0) {
        EventModify(param_1[5],2);
      }
      if (param_4 != 0) {
        FUN_c03a33d8((int)param_2);
      }
      iVar4 = FUN_c03a3340((int)param_2);
      if (iVar4 == 0) {
        DVar1 = FUN_c03ac938(0x1f);
        iVar4 = (**(code **)(*param_1 + 0x1c))(param_1);
        if (iVar4 == 0) {
          DVar1 = 0x37;
        }
        uVar5 = piVar3[0xf];
        if (((int)uVar5 < 0) || (0xff < uVar5)) {
          param_1[6] = 0;
          if (param_1[5] != 0) {
            EventModify(param_1[5],3);
          }
          FUN_c03ad2b0((int)piVar3);
          operator_delete(piVar3);
          return DVar1;
        }
        iVar4 = __GetUserKData(0xc);
        FUN_c03af930(DAT_c03c623c,uVar5,iVar4,1);
      }
      else {
        DVar1 = FUN_c03adeac(piVar3);
        if (DVar1 == 0) {
          return 0;
        }
        uVar5 = piVar3[0xf];
        iVar4 = __GetUserKData(0xc);
        FUN_c03af930(DAT_c03c623c,uVar5,iVar4,1);
      }
      FUN_c03af374(DAT_c03c623c,uVar5,iVar4);
    }
  }
  return DVar1;
}



/* c03a3b5c FUN_c03a3b5c */

/* Boundary evidence: original MIPS .pdata c03a3b5c..c03a3d03. Semantic name remains unreviewed. */

void FUN_c03a3b5c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c03c623c + 0x48));
  local_38 = 0;
  uVar5 = *(uint *)(DAT_c03c623c + 0x34);
  local_34 = uVar5;
  if (uVar5 != 0xffffffff) {
    FUN_c03ae7dc(DAT_c03c623c,uVar5,&local_38,(undefined4 *)0x0);
  }
  if (local_38 != 0) {
    AFS_NotifyMountedFS(local_38,1);
  }
  iVar4 = *(int *)(DAT_c03c623c + 0x38);
  iVar2 = DAT_c03c623c;
  local_28 = iVar4;
  for (uVar3 = 0; local_30 = uVar3, (int)uVar3 <= iVar4; uVar3 = uVar3 + 1) {
    if ((uVar3 != uVar5) &&
       (iVar1 = FUN_c03ae7dc(iVar2,uVar3,&local_2c,(undefined4 *)0x0), iVar2 = DAT_c03c623c,
       iVar1 == 0)) {
      AFS_NotifyMountedFS(local_2c,1);
      iVar2 = DAT_c03c623c;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x48));
  return;
}



/* c03a3d04 FUN_c03a3d04 */

/* Boundary evidence: original MIPS .pdata c03a3d04..c03a3d0f. Semantic name remains unreviewed. */

undefined4 FUN_c03a3d04(void)

{
  return 1;
}



/* c03a3d10 FUN_c03a3d10 */

/* Boundary evidence: original MIPS .pdata c03a3d10..c03a3d1b. Semantic name remains unreviewed. */

undefined4 FUN_c03a3d10(void)

{
  return 1;
}



/* c03a3d1c FUN_c03a3d1c */

/* Boundary evidence: original MIPS .pdata c03a3d1c..c03a3ea7. Semantic name remains unreviewed. */

void FUN_c03a3d1c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c03c623c + 0x48));
  local_38 = 0;
  uVar4 = *(uint *)(DAT_c03c623c + 0x34);
  local_2c = uVar4;
  if (uVar4 != 0xffffffff) {
    FUN_c03ae7dc(DAT_c03c623c,uVar4,&local_38,(undefined4 *)0x0);
  }
  iVar5 = *(int *)(DAT_c03c623c + 0x38);
  iVar2 = DAT_c03c623c;
  local_28 = iVar5;
  for (uVar3 = 0; local_34 = uVar3, (int)uVar3 <= iVar5; uVar3 = uVar3 + 1) {
    if ((uVar3 != uVar4) &&
       (iVar1 = FUN_c03ae7dc(iVar2,uVar3,&local_30,(undefined4 *)0x0), iVar2 = DAT_c03c623c,
       iVar1 == 0)) {
      AFS_NotifyMountedFS(local_30,2);
      iVar2 = DAT_c03c623c;
    }
  }
  if (local_38 != 0) {
    AFS_NotifyMountedFS(local_38,2);
    iVar2 = DAT_c03c623c;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x48));
  return;
}



/* c03a3ea8 FUN_c03a3ea8 */

/* Boundary evidence: original MIPS .pdata c03a3ea8..c03a3eb3. Semantic name remains unreviewed. */

undefined4 FUN_c03a3ea8(void)

{
  return 1;
}



/* c03a3eb4 FUN_c03a3eb4 */

/* Boundary evidence: original MIPS .pdata c03a3eb4..c03a3ebf. Semantic name remains unreviewed. */

undefined4 FUN_c03a3eb4(void)

{
  return 1;
}



/* c03a3ec0 STOREMGR_NotifyFileSystems */

/* Boundary evidence: original MIPS .pdata c03a3ec0..c03a3f3f. Semantic name remains unreviewed. */

void STOREMGR_NotifyFileSystems(uint param_1)

{
                    /* 0x3ec0  40  STOREMGR_NotifyFileSystems */
  if ((param_1 & 2) == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_c03c623c + 0x48));
    FUN_c03a762c();
    FUN_c03a3b5c();
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    FUN_c03a3d1c();
    FUN_c03a7524();
    EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c03c623c + 0x48));
  }
  return;
}



/* c03a3f40 STOREMGR_GetOidInfoEx */

/* WARNING: Removing unreachable block (ram,0xc03a409c) */
/* Boundary evidence: original MIPS .pdata c03a3f40..c03a40d7. Semantic name remains unreviewed. */

undefined4 STOREMGR_GetOidInfoEx(uint param_1,int param_2)

{
  bool bVar1;
  DWORD dwErrCode;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint local_28;
  int iStack_24;
  
                    /* 0x3f40  42  STOREMGR_GetOidInfoEx */
  dwErrCode = FUN_c03ae7dc(DAT_c03c623c,param_1,&iStack_24,&local_28);
  if (dwErrCode == 0) {
    uVar2 = *(uint *)(DAT_c03c623c + 0x30);
    uVar3 = 0xffffffff;
    if (((int)uVar2 < 0) || (0xff < uVar2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    uVar4 = 1;
    if ((bVar1) && (param_1 != uVar2)) {
      uVar3 = uVar2 | 0xe0000000;
    }
    *(undefined2 *)(param_2 + 2) = 2;
    *(uint *)(param_2 + 8) = uVar3;
    *(undefined4 *)(param_2 + 4) = 0x10;
    if ((local_28 & 0x40) == 0) {
      *(undefined4 *)(param_2 + 4) = 0x110;
    }
    if ((local_28 & 0x20) != 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 4;
    }
    if ((local_28 & 1) != 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 2;
    }
    *(undefined2 *)(param_2 + 0xc) = 0x5c;
    FUN_c03ae5f0(DAT_c03c623c,param_1,(STRSAFE_LPWSTR)(param_2 + 0xe),0x103);
  }
  else {
    SetLastError(dwErrCode);
    uVar4 = 0;
  }
  return uVar4;
}



/* c03a40d8 FUN_c03a40d8 */

/* Boundary evidence: original MIPS .pdata c03a40d8..c03a40e3. Semantic name remains unreviewed. */

undefined4 FUN_c03a40d8(void)

{
  return 1;
}



/* c03a40e4 FUN_c03a40e4 */

/* Boundary evidence: original MIPS .pdata c03a40e4..c03a43cb. Semantic name remains unreviewed. */

DWORD FUN_c03a40e4(int param_1,HKEY param_2,STRSAFE_PCNZWCH param_3,STRSAFE_LPCWSTR param_4)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined3 extraout_var;
  code *pcVar7;
  HKEY local_440;
  int local_43c;
  uint local_438 [2];
  wchar_t awStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  local_440 = (HKEY)0x0;
  DVar2 = FUN_c03acd00(param_2,param_4,&local_440);
  if (DVar2 != 0) goto LAB_c03a43a4;
  local_43c = 0;
  iVar3 = FUN_c03acafc(local_440,(LPCWSTR)PTR_u_BootPhase_c03c52a0,(LPBYTE)&local_43c);
  if (iVar3 == 0) {
    local_43c = param_1;
    if (param_1 == 0) {
      local_43c = 1;
    }
    RegSetValueExW(local_440,(LPCWSTR)PTR_u_BootPhase_c03c52a0,0,4,(BYTE *)&local_43c,4);
  }
  if (param_1 == local_43c) {
    iVar3 = FUN_c03acbc4(local_440,(LPCWSTR)PTR_DAT_c03c529c,awStack_228,0x104);
    if (iVar3 == 0) {
      iVar3 = FUN_c03acbc4(local_440,(LPCWSTR)PTR_u_DriverPath_c03c52a4,awStack_430,0x104);
      if (iVar3 == 0) {
        DVar2 = 2;
      }
      else {
        DVar2 = 0;
        bVar1 = FUN_c03a6f94(param_4,(undefined4 *)&DAT_c03a1210,awStack_430,(int *)0x0);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          DVar2 = FUN_c03ac938(0x1f);
        }
      }
    }
    else {
      local_438[0] = 0;
      FUN_c03ae44c(DAT_c03c623c,local_440,local_438);
      iVar3 = FUN_c03acbc4(local_440,(LPCWSTR)PTR_u_ActivityEvent_c03c52c0,awStack_430,0x104);
      if (iVar3 == 0) {
        StringCchCopyW(awStack_430,0x104,(STRSAFE_LPCWSTR)PTR_DAT_c03c5304);
      }
      puVar4 = operator_new(0x24);
      if (puVar4 == (undefined4 *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = FUN_c03a3724(puVar4,awStack_430);
      }
      if (piVar5 == (int *)0x0) {
LAB_c03a42e4:
        DVar2 = 8;
      }
      else {
        DVar2 = FUN_c03b12dc((int)piVar5,(STRSAFE_PCNZWCH)PTR_u_System_StorageManager_c03c5264);
        if ((DVar2 == 0) && (DVar2 = FUN_c03b12dc((int)piVar5,param_3), DVar2 == 0)) {
          DVar2 = FUN_c03a345c((int)piVar5,param_4,0x104);
          if (DVar2 == 0) {
            puVar4 = operator_new(0xb8);
            if (puVar4 == (undefined4 *)0x0) {
              piVar6 = (int *)0x0;
            }
            else {
              piVar6 = FUN_c03b1ff8(puVar4,piVar5,awStack_228);
            }
            if (piVar6 == (int *)0x0) {
              (**(code **)*piVar5)(piVar5,1);
              goto LAB_c03a42e4;
            }
            DVar2 = FUN_c03a3988(piVar5,piVar6,local_438[0],0);
            if (DVar2 == 0) goto LAB_c03a4390;
            (**(code **)*piVar6)(piVar6,1);
            pcVar7 = *(code **)*piVar5;
          }
          else {
            pcVar7 = *(code **)*piVar5;
          }
        }
        else {
          pcVar7 = *(code **)*piVar5;
        }
        (*pcVar7)(piVar5,1);
      }
    }
  }
  else {
    DVar2 = 0x15;
  }
LAB_c03a4390:
  if (local_440 != (HKEY)0x0) {
    FUN_c03acd64(local_440);
  }
LAB_c03a43a4:
  FUN_c03c216c(local_20);
  return DVar2;
}



/* c03a43cc FUN_c03a43cc */

/* Boundary evidence: original MIPS .pdata c03a43cc..c03a446f. Semantic name remains unreviewed. */

undefined4 FUN_c03a43cc(int param_1,uint param_2)

{
  int iVar1;
  STRSAFE_LPWSTR pwVar2;
  STRSAFE_LPWSTR pwVar3;
  HKEY local_18 [2];
  
  iVar1 = FUN_c03acd2c((LPCWSTR)PTR_u_System_StorageManager_AutoLoad_c03c526c,local_18);
  if (iVar1 == 0) {
    pwVar2 = FUN_c03a2f08(local_18[0],param_2,(STRSAFE_LPCWSTR)0x0,(STRSAFE_LPWSTR)0x0,0);
    while (pwVar2 != (STRSAFE_LPWSTR)0x0) {
      FUN_c03a40e4(param_1,local_18[0],
                   (STRSAFE_PCNZWCH)PTR_u_System_StorageManager_AutoLoad_c03c526c,pwVar2 + 0x104);
      pwVar3 = *(STRSAFE_LPWSTR *)(pwVar2 + 0x20a);
      operator_delete(pwVar2);
      pwVar2 = pwVar3;
    }
    FUN_c03acd64(local_18[0]);
  }
  return 0;
}



/* c03a4470 FUN_c03a4470 */

/* Boundary evidence: original MIPS .pdata c03a4470..c03a45cb. Semantic name remains unreviewed. */

DWORD FUN_c03a4470(void)

{
  undefined4 *puVar1;
  int *piVar2;
  DWORD DVar3;
  int *piVar4;
  code *pcVar5;
  
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c03a3724(puVar1,(LPCWSTR)0x0);
  }
  if (piVar2 == (int *)0x0) {
LAB_c03a4564:
    DVar3 = 8;
  }
  else {
    DVar3 = FUN_c03b12dc((int)piVar2,(STRSAFE_PCNZWCH)PTR_u_System_StorageManager_c03c5264);
    if ((DVar3 == 0) &&
       (DVar3 = FUN_c03b12dc((int)piVar2,
                             (STRSAFE_PCNZWCH)PTR_u_System_StorageManager_AutoLoad_c03c526c),
       DVar3 == 0)) {
      DVar3 = FUN_c03a345c((int)piVar2,(wchar_t *)PTR_DAT_c03c52d0,0x104);
      if (DVar3 == 0) {
        puVar1 = operator_new(0xb8);
        if (puVar1 == (undefined4 *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = FUN_c03b1ff8(puVar1,piVar2,(STRSAFE_PCNZWCH)PTR_u_ROMFSD_DLL_c03c52d4);
        }
        if (piVar4 == (int *)0x0) {
          (**(code **)*piVar2)(piVar2,1);
          goto LAB_c03a4564;
        }
        DVar3 = FUN_c03a3988(piVar2,piVar4,0x71,0);
        if (DVar3 == 0) {
          return 0;
        }
        (**(code **)*piVar4)(piVar4,1);
        pcVar5 = *(code **)*piVar2;
      }
      else {
        pcVar5 = *(code **)*piVar2;
      }
    }
    else {
      pcVar5 = *(code **)*piVar2;
    }
    (*pcVar5)(piVar2,1);
  }
  return DVar3;
}



/* c03a45cc STOREMGR_Initialize */

/* Boundary evidence: original MIPS .pdata c03a45cc..c03a4657. Semantic name remains unreviewed. */

void STOREMGR_Initialize(void)

{
  int iVar1;
  DWORD DVar2;
  
                    /* 0x45cc  38  STOREMGR_Initialize */
  iVar1 = FUN_c03afec0();
  if ((((iVar1 == 0) && (iVar1 = FUN_c03a8868(), iVar1 == 0)) &&
      (iVar1 = FUN_c03b4cfc(), iVar1 == 0)) &&
     (((iVar1 = FUN_c03b32b0(), iVar1 == 0 && (iVar1 = FUN_c03b301c(), iVar1 == 0)) &&
      ((DVar2 = FUN_c03a64c0(), DVar2 == 0 && (iVar1 = FUN_c03b281c(), iVar1 == 0)))))) {
    FUN_c03a4470();
  }
  return;
}



/* c03a4658 STOREMGR_StartBootPhase */

/* Boundary evidence: original MIPS .pdata c03a4658..c03a479f. Semantic name remains unreviewed. */

DWORD STOREMGR_StartBootPhase(int param_1)

{
  int iVar1;
  DWORD DVar2;
  HKEY local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
                    /* 0x4658  39  STOREMGR_StartBootPhase */
  local_18 = DAT_c03c531c;
  if (param_1 == 0) {
    local_228[0] = (HKEY)0x0;
    iVar1 = FUN_c03acd2c((LPCWSTR)PTR_u_System_StorageManager_c03c5264,local_228);
    if (((iVar1 == 0) &&
        (iVar1 = FUN_c03acbc4(local_228[0],L"SecurityDll",awStack_220,0x104), iVar1 != 0)) &&
       (iVar1 = FUN_c03a3180(DAT_c03c623c,awStack_220), iVar1 != 0)) {
      NKDbgPrintfW(L"FSDMGR: File security dll load error (dll=\"%s\").\r\n",awStack_220);
      NKDbgPrintfW(L"FSDMGR: Halting system (%s)!!!\r\n",L"File security is required");
      trap(0x400);
      SetThreadPriority((HANDLE)0x41,0);
      KernelIoControl(0x1010040,0,0,0,0,0);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  DVar2 = FUN_c03a7ec0(param_1);
  if ((DVar2 == 0) && (DVar2 = FUN_c03a43cc(param_1,1), DVar2 == 0)) {
    DAT_c03c5214 = param_1;
    FUN_c03c216c(local_18);
    DVar2 = 0;
  }
  else {
    FUN_c03c216c(local_18);
  }
  return DVar2;
}



/* c03a47a0 FSDMGR_AdvertiseInterface */

/* Boundary evidence: original MIPS .pdata c03a47a0..c03a486f. Semantic name remains unreviewed. */

undefined4 FSDMGR_AdvertiseInterface(undefined4 param_1,short *param_2,undefined4 param_3)

{
  int iVar1;
  HMODULE hLibModule;
  code *pcVar2;
  undefined4 uVar3;
  
                    /* 0x47a0  2  FSDMGR_AdvertiseInterface */
  uVar3 = 0;
  if ((param_2 != (short *)0x0) && (*param_2 == 0)) {
    param_2 = (short *)&DAT_c03a13c4;
  }
  iVar1 = WaitForAPIReady(0x54,0);
  if ((iVar1 == 0) && (hLibModule = LoadLibraryW(L"coredll.dll"), hLibModule != (HMODULE)0x0)) {
    pcVar2 = (code *)FUN_c03acd88();
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(param_1,param_2,param_3);
    }
    FreeLibrary(hLibModule);
  }
  return uVar3;
}



/* c03a4870 FSDMGR_CreateFileHandle */

undefined4 FSDMGR_CreateFileHandle(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x4870  7  FSDMGR_CreateFileHandle
                       0x4870  8  FSDMGR_CreateSearchHandle */
  return param_3;
}



/* c03a4878 FSDMGR_DiskIoControl */

/* Boundary evidence: original MIPS .pdata c03a4878..c03a4903. Semantic name remains unreviewed. */

void FSDMGR_DiskIoControl(int *param_1)

{
                    /* 0x4878  12  FSDMGR_DiskIoControl */
  (**(code **)(*param_1 + 0x14))();
  return;
}



/* c03a4904 FUN_c03a4904 */

/* Boundary evidence: original MIPS .pdata c03a4904..c03a490f. Semantic name remains unreviewed. */

undefined4 FUN_c03a4904(void)

{
  return 1;
}



/* c03a4910 FUN_c03a4910 */

/* Boundary evidence: original MIPS .pdata c03a4910..c03a4ab3. Semantic name remains unreviewed. */

DWORD FUN_c03a4910(int *param_1,undefined4 *param_2)

{
  int *hMem;
  int iVar1;
  int iVar2;
  int *piVar3;
  DWORD DVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = (int *)param_1[1];
  if (*param_1 == 0) {
    hMem = LocalAlloc(0x40,param_1[5] * 8 + 0x14);
    if (hMem == (int *)0x0) {
      DVar4 = 0xe;
    }
    else {
      *hMem = param_1[2];
      hMem[1] = param_1[3];
      hMem[2] = param_1[5];
      hMem[3] = 0;
      hMem[4] = 0;
      uVar6 = 0;
      if (param_1[5] != 0) {
        iVar2 = 0;
        piVar3 = hMem + 6;
        do {
          uVar6 = uVar6 + 1;
          piVar3[-1] = *(int *)(iVar2 + param_1[6]);
          iVar1 = iVar2 + param_1[6];
          iVar2 = iVar2 + 8;
          *piVar3 = *(int *)(iVar1 + 4);
          piVar3 = piVar3 + 2;
        } while (uVar6 < (uint)param_1[5]);
      }
      iVar2 = FSDMGR_DiskIoControl(piVar5);
      if (iVar2 == 0) {
        DVar4 = FUN_c03ac938(0x1f);
      }
      else {
        DVar4 = 0;
      }
      LocalFree(hMem);
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = 0;
        if (DVar4 == 0) {
          param_2[1] = param_1[3];
        }
        else {
          param_2[1] = 0;
        }
      }
    }
  }
  else {
    DVar4 = 0x57;
  }
  return DVar4;
}



/* c03a4ab4 FSDMGR_ReadDisk */

/* Boundary evidence: original MIPS .pdata c03a4ab4..c03a4b0b. Semantic name remains unreviewed. */

void FSDMGR_ReadDisk(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 local_c;
  
                    /* 0x4ab4  25  FSDMGR_ReadDisk */
  local_2c = param_5;
  local_10 = &local_30;
  local_28 = 0;
  local_18 = 0;
  local_14 = 1;
  local_c = 0;
  local_30 = param_4;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  FUN_c03a4910(&local_28,(undefined4 *)0x0);
  return;
}



/* c03a4b0c FSDMGR_WriteDisk */

/* Boundary evidence: original MIPS .pdata c03a4b0c..c03a4b63. Semantic name remains unreviewed. */

void FSDMGR_WriteDisk(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 local_c;
  
                    /* 0x4b0c  35  FSDMGR_WriteDisk */
  local_2c = param_5;
  local_10 = &local_30;
  local_28 = 0;
  local_18 = 0;
  local_14 = 1;
  local_c = 0;
  local_30 = param_4;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  FUN_c03a4910(&local_28,(undefined4 *)0x0);
  return;
}



/* c03a4b64 FSDMGR_ReadDiskEx */

/* Boundary evidence: original MIPS .pdata c03a4b64..c03a4b7f. Semantic name remains unreviewed. */

void FSDMGR_ReadDiskEx(int *param_1,undefined4 *param_2)

{
                    /* 0x4b64  26  FSDMGR_ReadDiskEx */
  FUN_c03a4910(param_1,param_2);
  return;
}



/* c03a4b80 FSDMGR_WriteDiskEx */

/* Boundary evidence: original MIPS .pdata c03a4b80..c03a4b9b. Semantic name remains unreviewed. */

void FSDMGR_WriteDiskEx(int *param_1,undefined4 *param_2)

{
                    /* 0x4b80  36  FSDMGR_WriteDiskEx */
  FUN_c03a4910(param_1,param_2);
  return;
}



/* c03a4b9c FUN_c03a4b9c */

/* Boundary evidence: original MIPS .pdata c03a4b9c..c03a4bf3. Semantic name remains unreviewed. */

uint FUN_c03a4b9c(int param_1,int param_2)

{
  LONG LVar1;
  
  LVar1 = InterlockedExchangeAdd((LONG *)(param_1 + 0x38),-param_2);
  if ((LVar1 - param_2 & 0xfffffffbU) == 0) {
    FUN_c03ada3c(param_1);
  }
  return LVar1 - param_2;
}



/* c03a4bf4 FSDMGR_ParseSecurityDescriptor */

undefined4 FSDMGR_ParseSecurityDescriptor(int *param_1,int *param_2,uint *param_3)

{
  undefined4 uVar1;
  
                    /* 0x4bf4  82  FSDMGR_ParseSecurityDescriptor */
  if ((param_2 == (int *)0x0) || (param_3 == (uint *)0x0)) {
    uVar1 = 0x57;
  }
  else {
    if (param_1 == (int *)0x0) {
      *param_2 = 0;
      *param_3 = 0;
    }
    else {
      if (((*param_1 != 0xc) || (param_1[2] != 0)) || (-1 < param_1[1])) {
        return 0x53a;
      }
      *param_3 = (uint)*(ushort *)(param_1[1] + 2);
      *param_2 = param_1[1];
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c03a4c70 FSDMGR_AsyncEnterVolume */

/* Boundary evidence: original MIPS .pdata c03a4c70..c03a4d4b. Semantic name remains unreviewed. */

int FSDMGR_AsyncEnterVolume(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
                    /* 0x4c70  80  FSDMGR_AsyncEnterVolume */
  uVar1 = __GetUserKData(0xc);
  local_20 = LockAPIHandle(DAT_c03c6248,uVar1,param_1,&local_1c);
  if (local_20 == 0) {
    iVar2 = 0x651;
  }
  else {
    iVar2 = CeSafeCopyMemory(param_2,&local_20,4);
    if ((iVar2 == 0) || (iVar2 = CeSafeCopyMemory(param_3,&local_1c,4), iVar2 == 0)) {
      UnlockAPIHandle(DAT_c03c6248,local_20);
      iVar2 = 0x57;
    }
    else {
      iVar2 = FUN_c03ad44c(local_1c);
      if (iVar2 != 0) {
        UnlockAPIHandle(DAT_c03c6248,local_20);
      }
    }
  }
  return iVar2;
}



/* c03a4d4c FSDMGR_GetVolumeName */

/* Boundary evidence: original MIPS .pdata c03a4d4c..c03a4f2f. Semantic name remains unreviewed. */

undefined4 FSDMGR_GetVolumeName(undefined4 param_1,STRSAFE_LPWSTR param_2,uint param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  DWORD dwErrCode;
  uint uVar4;
  size_t local_34;
  int local_30;
  DWORD local_2c;
  HRESULT local_28;
  
                    /* 0x4d4c  22  FSDMGR_GetVolumeName */
  uVar2 = __GetUserKData(0xc);
  iVar3 = LockAPIHandle(DAT_c03c6248,uVar2,param_1,&local_30);
  if (iVar3 != 0) {
    uVar4 = *(uint *)(local_30 + 0x3c);
    if (((int)uVar4 < 0) || (bVar1 = true, 0xff < uVar4)) {
      bVar1 = false;
    }
    if (!bVar1) {
      UnlockAPIHandle(DAT_c03c6248,iVar3);
      dwErrCode = 3;
      goto LAB_c03a4dc4;
    }
    dwErrCode = FUN_c03ae5f0(DAT_c03c623c,uVar4,param_2,param_3);
    local_2c = dwErrCode;
    if (dwErrCode != 0) {
      UnlockAPIHandle(DAT_c03c6248,iVar3);
      goto LAB_c03a4dc4;
    }
    local_34 = 0;
    local_28 = StringCchLengthW(param_2,param_3,&local_34);
    if (-1 < local_28) {
      UnlockAPIHandle(DAT_c03c6248,iVar3);
      return local_34;
    }
    UnlockAPIHandle(DAT_c03c6248,iVar3);
  }
  dwErrCode = 0x57;
LAB_c03a4dc4:
  SetLastError(dwErrCode);
  return 0;
}



/* c03a4f30 FUN_c03a4f30 */

/* Boundary evidence: original MIPS .pdata c03a4f30..c03a4f3b. Semantic name remains unreviewed. */

undefined4 FUN_c03a4f30(void)

{
  return 1;
}



/* c03a4f3c FUN_c03a4f3c */

/* Boundary evidence: original MIPS .pdata c03a4f3c..c03a4f47. Semantic name remains unreviewed. */

undefined4 FUN_c03a4f3c(void)

{
  return 1;
}



/* c03a4f48 FUN_c03a4f48 */

/* Boundary evidence: original MIPS .pdata c03a4f48..c03a4fd7. Semantic name remains unreviewed. */

undefined4 FUN_c03a4f48(uint *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *local_18 [2];
  
  *param_2 = 0;
  uVar3 = 1;
  if ((*param_1 & 3) == 3) {
    local_18[0] = (uint *)0x0;
    uVar1 = __GetUserKData(0xc);
    iVar2 = LockAPIHandle(DAT_c03c537c,uVar1,*param_1,local_18);
    *param_2 = iVar2;
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      *param_1 = *local_18[0];
    }
  }
  return uVar3;
}



/* c03a4fd8 FSDMGR_GetRegistryValue */

/* Boundary evidence: original MIPS .pdata c03a4fd8..c03a50c3. Semantic name remains unreviewed. */

bool FSDMGR_GetRegistryValue(uint param_1,LPCWSTR param_2,LPBYTE param_3)

{
  int iVar1;
  DWORD dwErrCode;
  uint local_28;
  DWORD local_24;
  int local_20 [2];
  
                    /* 0x4fd8  20  FSDMGR_GetRegistryValue */
  local_20[0] = 0;
  dwErrCode = 0x1f;
  local_24 = 0x1f;
  local_28 = param_1;
  iVar1 = FUN_c03a4f48(&local_28,local_20);
  if (iVar1 != 0) {
    dwErrCode = FUN_c03b1140(local_28,param_2,param_3);
    local_24 = dwErrCode;
  }
  if (local_20[0] != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03a50c4 FUN_c03a50c4 */

/* Boundary evidence: original MIPS .pdata c03a50c4..c03a50cf. Semantic name remains unreviewed. */

undefined4 FUN_c03a50c4(void)

{
  return 1;
}



/* c03a50d0 FSDMGR_GetRegistryString */

/* Boundary evidence: original MIPS .pdata c03a50d0..c03a51cb. Semantic name remains unreviewed. */

bool FSDMGR_GetRegistryString(uint param_1,LPCWSTR param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  int iVar1;
  DWORD dwErrCode;
  uint local_28;
  DWORD local_24;
  int local_20 [2];
  
                    /* 0x50d0  19  FSDMGR_GetRegistryString */
  local_20[0] = 0;
  dwErrCode = 0x1f;
  local_24 = 0x1f;
  local_28 = param_1;
  iVar1 = FUN_c03a4f48(&local_28,local_20);
  if (iVar1 != 0) {
    dwErrCode = FUN_c03b0fe8(local_28,param_2,param_3,param_4);
    local_24 = dwErrCode;
  }
  if (local_20[0] != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03a51cc FUN_c03a51cc */

/* Boundary evidence: original MIPS .pdata c03a51cc..c03a51d7. Semantic name remains unreviewed. */

undefined4 FUN_c03a51cc(void)

{
  return 1;
}



/* c03a51d8 FSDMGR_GetRegistryFlag */

/* Boundary evidence: original MIPS .pdata c03a51d8..c03a52d3. Semantic name remains unreviewed. */

bool FSDMGR_GetRegistryFlag(uint param_1,LPCWSTR param_2,uint *param_3,uint param_4)

{
  int iVar1;
  DWORD dwErrCode;
  uint local_28;
  DWORD local_24;
  int local_20 [2];
  
                    /* 0x51d8  18  FSDMGR_GetRegistryFlag */
  local_20[0] = 0;
  dwErrCode = 0x1f;
  local_24 = 0x1f;
  local_28 = param_1;
  iVar1 = FUN_c03a4f48(&local_28,local_20);
  if (iVar1 != 0) {
    dwErrCode = FUN_c03b1274(local_28,param_2,param_3,param_4);
    local_24 = dwErrCode;
  }
  if (local_20[0] != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03a52d4 FUN_c03a52d4 */

/* Boundary evidence: original MIPS .pdata c03a52d4..c03a52df. Semantic name remains unreviewed. */

undefined4 FUN_c03a52d4(void)

{
  return 1;
}



/* c03a52e0 FUN_c03a52e0 */

/* Boundary evidence: original MIPS .pdata c03a52e0..c03a549f. Semantic name remains unreviewed. */

undefined4 FUN_c03a52e0(HMODULE param_1,undefined4 param_2)

{
  HMODULE pHVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  HMODULE hLibModule;
  code *pcVar4;
  undefined4 uVar5;
  HMODULE local_23c;
  int local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  local_238[0] = 0;
  uVar5 = 0x1f;
  local_23c = param_1;
  iVar3 = FUN_c03a4f48((uint *)&local_23c,local_238);
  pHVar1 = local_23c;
  if (iVar3 != 0) {
    bVar2 = FSDMGR_GetRegistryString((uint)local_23c,L"Util",awStack_230,0x104);
    if ((CONCAT31(extraout_var,bVar2) == 0) ||
       (hLibModule = LoadLibraryW(awStack_230), local_23c = hLibModule, hLibModule == (HMODULE)0x0))
    {
      uVar5 = 2;
    }
    else {
      pcVar4 = (code *)FUN_c03acd88();
      if (pcVar4 == (code *)0x0) {
        FreeLibrary(hLibModule);
        uVar5 = 0x32;
      }
      else {
        uVar5 = (**(code **)(pHVar1->unused + 0x10))(pHVar1);
        uVar5 = (*pcVar4)(uVar5,param_2);
        FreeLibrary(hLibModule);
      }
    }
  }
  if (local_238[0] != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  FUN_c03c216c(local_28);
  return uVar5;
}



/* c03a54a0 FUN_c03a54a0 */

/* Boundary evidence: original MIPS .pdata c03a54a0..c03a54ab. Semantic name remains unreviewed. */

undefined4 FUN_c03a54a0(void)

{
  return 1;
}



/* c03a54ac FUN_c03a54ac */

/* Boundary evidence: original MIPS .pdata c03a54ac..c03a54d3. Semantic name remains unreviewed. */

undefined4 FUN_c03a54ac(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a54d4 FSDMGR_ScanVolume */

/* Boundary evidence: original MIPS .pdata c03a54d4..c03a54f3. Semantic name remains unreviewed. */

void FSDMGR_ScanVolume(HMODULE param_1,undefined4 param_2)

{
                    /* 0x54d4  31  FSDMGR_ScanVolume */
  FUN_c03a52e0(param_1,param_2);
  return;
}



/* c03a54f4 FSDMGR_FormatVolume */

/* Boundary evidence: original MIPS .pdata c03a54f4..c03a5513. Semantic name remains unreviewed. */

void FSDMGR_FormatVolume(HMODULE param_1,undefined4 param_2)

{
                    /* 0x54f4  15  FSDMGR_FormatVolume */
  FUN_c03a52e0(param_1,param_2);
  return;
}



/* c03a5514 FSDMGR_GetDiskName */

/* Boundary evidence: original MIPS .pdata c03a5514..c03a55fb. Semantic name remains unreviewed. */

bool FSDMGR_GetDiskName(int *param_1,undefined4 param_2)

{
  int iVar1;
  DWORD dwErrCode;
  int *local_20;
  DWORD local_1c;
  int local_18 [2];
  
                    /* 0x5514  17  FSDMGR_GetDiskName */
  local_18[0] = 0;
  dwErrCode = 0x1f;
  local_1c = 0x1f;
  local_20 = param_1;
  iVar1 = FUN_c03a4f48((uint *)&local_20,local_18);
  if (iVar1 != 0) {
    dwErrCode = (**(code **)(*local_20 + 0xc))(local_20,param_2,0x104);
    local_1c = dwErrCode;
  }
  if (local_18[0] != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03a55fc FUN_c03a55fc */

/* Boundary evidence: original MIPS .pdata c03a55fc..c03a5607. Semantic name remains unreviewed. */

undefined4 FUN_c03a55fc(void)

{
  return 1;
}



/* c03a5608 FSDMGR_GetMountFlags */

/* Boundary evidence: original MIPS .pdata c03a5608..c03a56db. Semantic name remains unreviewed. */

undefined4 FSDMGR_GetMountFlags(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int local_20;
  int local_1c;
  
                    /* 0x5608  37  FSDMGR_GetMountFlags */
  uVar1 = __GetUserKData(0xc);
  local_1c = LockAPIHandle(DAT_c03c6248,uVar1,param_1,&local_20);
  if (local_1c == 0) {
    uVar1 = 0x57;
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(local_20 + 0x28);
    UnlockAPIHandle(DAT_c03c6248,local_1c);
  }
  return uVar1;
}



/* c03a56dc FUN_c03a56dc */

/* Boundary evidence: original MIPS .pdata c03a56dc..c03a56e7. Semantic name remains unreviewed. */

undefined4 FUN_c03a56dc(void)

{
  return 1;
}



/* c03a56e8 FSDMGR_RegisterVolume */

/* Boundary evidence: original MIPS .pdata c03a56e8..c03a592b. Semantic name remains unreviewed. */

int FSDMGR_RegisterVolume(int param_1,STRSAFE_LPCWSTR param_2,undefined4 param_3)

{
  HRESULT HVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  size_t local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
                    /* 0x56e8  27  FSDMGR_RegisterVolume */
  local_28 = DAT_c03c531c;
  piVar5 = *(int **)(param_1 + 0x18);
  if ((*param_2 == L'\\') || (*param_2 == L'/')) {
    param_2 = param_2 + 1;
  }
  if (piVar5[0xf] == -1) {
    HVar1 = StringCchCopyW(awStack_230,0x104,param_2);
    if ((HVar1 < 0) || (HVar1 = StringCchLengthW(awStack_230,0x103,local_238), HVar1 < 0)) {
      DVar3 = 0x57;
    }
    else {
      uVar6 = piVar5[10];
      if ((uVar6 & 0x80) == 0) {
        iVar2 = 1;
        do {
          if (1 < iVar2) {
            awStack_230[local_238[0]] = (short)iVar2 + L'0';
            awStack_230[local_238[0] + 1] = L'\0';
          }
          uVar4 = RegisterAFSName(awStack_230);
          if ((uVar4 != 0xffffffff) && (DVar3 = GetLastError(), DVar3 == 0)) break;
          iVar2 = iVar2 + 1;
          uVar4 = 0xffffffff;
        } while (iVar2 < 10);
        if (uVar4 == 0xffffffff) {
          DVar3 = 0x54;
          goto LAB_c03a58f0;
        }
      }
      else {
        uVar4 = 1;
      }
      *(undefined4 *)(piVar5[2] + 0xc) = param_3;
      iVar2 = RegisterAFSEx(uVar4,DAT_c03c6248,piVar5,4,uVar6);
      if (iVar2 == 0) {
        DeregisterAFSName(uVar4);
        goto LAB_c03a58f8;
      }
      DVar3 = FUN_c03ace58(piVar5,uVar4);
      if (((DVar3 == 0) && (DVar3 = FUN_c03ad93c((int)piVar5), DVar3 == 0)) &&
         (DVar3 = FUN_c03ad33c(piVar5), DVar3 == 0)) {
        if ((piVar5[0xc] & 4U) != 0) {
          FUN_c03adeac(piVar5);
        }
        FUN_c03c216c(local_28);
        return piVar5[0x10];
      }
      DeregisterAFS(uVar4);
      DeregisterAFSName(uVar4);
    }
  }
  else {
    DVar3 = 0xb7;
  }
LAB_c03a58f0:
  SetLastError(DVar3);
LAB_c03a58f8:
  FUN_c03c216c(local_28);
  return 0;
}



/* c03a592c FSDMGR_GetVolumeHandle */

undefined4 FSDMGR_GetVolumeHandle(int param_1)

{
                    /* 0x592c  21  FSDMGR_GetVolumeHandle */
  return *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x40);
}



/* c03a5938 FSDMGR_GetDiskInfo */

/* Boundary evidence: original MIPS .pdata c03a5938..c03a5aeb. Semantic name remains unreviewed. */

DWORD FSDMGR_GetDiskInfo(int *param_1)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  int *local_28;
  int local_24;
  DWORD local_20;
  
                    /* 0x5938  16  FSDMGR_GetDiskInfo */
  local_24 = 0;
  DVar3 = 0;
  local_28 = param_1;
  iVar2 = FUN_c03a4f48((uint *)&local_28,&local_24);
  piVar1 = local_28;
  if (iVar2 == 0) {
    DVar3 = 0x1f;
    goto LAB_c03a5aa4;
  }
  iVar2 = FSDMGR_DiskIoControl(local_28);
  if (iVar2 == 0) {
    iVar2 = FSDMGR_DiskIoControl(piVar1);
    if (iVar2 != 0) {
      piVar1[1] = piVar1[1] & 0xfffffff7;
      goto LAB_c03a5aa4;
    }
    iVar2 = FSDMGR_DiskIoControl(piVar1);
    if (iVar2 == 0) {
      piVar1[1] = piVar1[1] | 4;
      DVar3 = FUN_c03ac938(0x1f);
      local_20 = DVar3;
      goto LAB_c03a5aa4;
    }
  }
  piVar1[1] = piVar1[1] | 8;
LAB_c03a5aa4:
  if (local_24 != 0) {
    UnlockAPIHandle(DAT_c03c537c);
  }
  return DVar3;
}



/* c03a5aec FUN_c03a5aec */

/* Boundary evidence: original MIPS .pdata c03a5aec..c03a5af7. Semantic name remains unreviewed. */

undefined4 FUN_c03a5aec(void)

{
  return 1;
}



/* c03a5af8 FUN_c03a5af8 */

/* Boundary evidence: original MIPS .pdata c03a5af8..c03a5b8f. Semantic name remains unreviewed. */

uint FUN_c03a5af8(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_c03a4b9c(param_1,8);
  if ((((uVar1 & 1) != 0) && ((uVar1 & 2) == 0)) && ((uVar1 & 0xfffffff8) == 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x48),3);
  }
  if (((uVar1 & 4) != 0) && ((uVar1 & 0xfffffff8) == 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x48),3);
  }
  return uVar1;
}



/* c03a5b90 FSDMGR_AsyncExitVolume */

/* Boundary evidence: original MIPS .pdata c03a5b90..c03a5c27. Semantic name remains unreviewed. */

undefined4 FSDMGR_AsyncExitVolume(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x5b90  81  FSDMGR_AsyncExitVolume */
  FUN_c03a5af8(param_2);
  iVar1 = UnlockAPIHandle(DAT_c03c6248,param_1);
  if (iVar1 == 0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03a5c28 FUN_c03a5c28 */

/* Boundary evidence: original MIPS .pdata c03a5c28..c03a5c33. Semantic name remains unreviewed. */

undefined4 FUN_c03a5c28(void)

{
  return 1;
}



/* c03a5c34 FUN_c03a5c34 */

/* Boundary evidence: original MIPS .pdata c03a5c34..c03a5eab. Semantic name remains unreviewed. */

void FUN_c03a5c34(uint param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  bVar1 = FSDMGR_GetRegistryString(param_1,L"CacheDll",awStack_238,0x104);
  if (CONCAT31(extraout_var,bVar1) == 0) {
LAB_c03a5df8:
    if (DAT_c03c534c != (HMODULE)0x0) goto LAB_c03a5e74;
  }
  else {
    DAT_c03c534c = (HMODULE)LoadDriver(awStack_238);
    if (DAT_c03c534c != (HMODULE)0x0) {
      DAT_c03c5348 = (code *)FUN_c03acd88();
      DAT_c03c5344 = (code *)FUN_c03acd88();
      DAT_c03c5340 = (undefined1 *)FUN_c03acd88();
      DAT_c03c533c = (code *)FUN_c03acd88();
      DAT_c03c5338 = (code *)FUN_c03acd88();
      DAT_c03c5334 = (code *)FUN_c03acd88();
      DAT_c03c5330 = (undefined1 *)FUN_c03acd88();
      DAT_c03c532c = (undefined1 *)FUN_c03acd88();
      DAT_c03c5328 = (code *)FUN_c03acd88();
      if ((((((DAT_c03c5348 == (code *)0x0) || (DAT_c03c5344 == (code *)0x0)) ||
            (DAT_c03c5340 == (undefined1 *)0x0)) ||
           ((DAT_c03c533c == (code *)0x0 || (DAT_c03c5338 == (code *)0x0)))) ||
          ((DAT_c03c5334 == (code *)0x0 ||
           ((DAT_c03c5330 == (undefined1 *)0x0 || (DAT_c03c5328 == (code *)0x0)))))) ||
         (DAT_c03c532c == (undefined1 *)0x0)) {
        FreeLibrary(DAT_c03c534c);
        DAT_c03c534c = (HMODULE)0x0;
      }
      goto LAB_c03a5df8;
    }
  }
  DAT_c03c5348 = FUN_c03b7484;
  DAT_c03c5344 = FUN_c03b7114;
  DAT_c03c5340 = &LAB_c03a3848;
  DAT_c03c533c = FUN_c03b719c;
  DAT_c03c5338 = FUN_c03b720c;
  DAT_c03c5334 = FUN_c03b727c;
  DAT_c03c5330 = &LAB_c03a3848;
  DAT_c03c532c = &LAB_c03a3848;
  DAT_c03c5328 = FUN_c03b7304;
  FUN_c03b7400();
LAB_c03a5e74:
  FUN_c03c216c(local_30);
  return;
}



/* c03a5eac FSDMGR_CreateCache */

/* Boundary evidence: original MIPS .pdata c03a5eac..c03a5fbf. Semantic name remains unreviewed. */

int FSDMGR_CreateCache(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
                    /* 0x5eac  6  FSDMGR_CreateCache */
  if (DAT_c03c5350 == 0) {
    FUN_c03a5c34(param_1);
  }
  iVar1 = (*DAT_c03c5348)(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != -1) {
    DAT_c03c5350 = DAT_c03c5350 + 1;
  }
  return iVar1;
}



/* c03a5fc0 FUN_c03a5fc0 */

/* Boundary evidence: original MIPS .pdata c03a5fc0..c03a5fe7. Semantic name remains unreviewed. */

undefined4 FUN_c03a5fc0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a5fe8 FSDMGR_DeleteCache */

/* Boundary evidence: original MIPS .pdata c03a5fe8..c03a6083. Semantic name remains unreviewed. */

undefined4 FSDMGR_DeleteCache(void)

{
  undefined4 uVar1;
  
                    /* 0x5fe8  9  FSDMGR_DeleteCache */
  if (DAT_c03c5344 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5344)();
    DAT_c03c5350 = DAT_c03c5350 + -1;
    if (DAT_c03c5350 == 0) {
      if (DAT_c03c534c == 0) {
        FUN_c03b7444();
      }
      else {
        FreeLibrary((HMODULE)DAT_c03c534c);
      }
      DAT_c03c534c = 0;
    }
  }
  return uVar1;
}



/* c03a6084 FSDMGR_ResizeCache */

/* Boundary evidence: original MIPS .pdata c03a6084..c03a60ef. Semantic name remains unreviewed. */

undefined4 FSDMGR_ResizeCache(void)

{
  undefined4 uVar1;
  
                    /* 0x6084  30  FSDMGR_ResizeCache */
  if (DAT_c03c5340 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5340)();
  }
  return uVar1;
}



/* c03a60f0 FUN_c03a60f0 */

/* Boundary evidence: original MIPS .pdata c03a60f0..c03a6117. Semantic name remains unreviewed. */

undefined4 FUN_c03a60f0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a6118 FSDMGR_CachedRead */

/* Boundary evidence: original MIPS .pdata c03a6118..c03a618b. Semantic name remains unreviewed. */

undefined4 FSDMGR_CachedRead(void)

{
  undefined4 uVar1;
  
                    /* 0x6118  4  FSDMGR_CachedRead */
  if (DAT_c03c533c == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c533c)();
  }
  return uVar1;
}



/* c03a618c FUN_c03a618c */

/* Boundary evidence: original MIPS .pdata c03a618c..c03a61b3. Semantic name remains unreviewed. */

undefined4 FUN_c03a618c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a61b4 FSDMGR_CachedWrite */

/* Boundary evidence: original MIPS .pdata c03a61b4..c03a6227. Semantic name remains unreviewed. */

undefined4 FSDMGR_CachedWrite(void)

{
  undefined4 uVar1;
  
                    /* 0x61b4  5  FSDMGR_CachedWrite */
  if (DAT_c03c5338 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5338)();
  }
  return uVar1;
}



/* c03a6228 FUN_c03a6228 */

/* Boundary evidence: original MIPS .pdata c03a6228..c03a624f. Semantic name remains unreviewed. */

undefined4 FUN_c03a6228(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a6250 FSDMGR_FlushCache */

/* Boundary evidence: original MIPS .pdata c03a6250..c03a62bb. Semantic name remains unreviewed. */

undefined4 FSDMGR_FlushCache(void)

{
  undefined4 uVar1;
  
                    /* 0x6250  14  FSDMGR_FlushCache */
  if (DAT_c03c5334 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5334)();
  }
  return uVar1;
}



/* c03a62bc FUN_c03a62bc */

/* Boundary evidence: original MIPS .pdata c03a62bc..c03a62e3. Semantic name remains unreviewed. */

undefined4 FUN_c03a62bc(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a62e4 FSDMGR_SyncCache */

/* Boundary evidence: original MIPS .pdata c03a62e4..c03a634f. Semantic name remains unreviewed. */

undefined4 FSDMGR_SyncCache(void)

{
  undefined4 uVar1;
  
                    /* 0x62e4  32  FSDMGR_SyncCache */
  if (DAT_c03c5330 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5330)();
  }
  return uVar1;
}



/* c03a6350 FUN_c03a6350 */

/* Boundary evidence: original MIPS .pdata c03a6350..c03a6377. Semantic name remains unreviewed. */

undefined4 FUN_c03a6350(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a6378 FSDMGR_InvalidateCache */

/* Boundary evidence: original MIPS .pdata c03a6378..c03a63e3. Semantic name remains unreviewed. */

undefined4 FSDMGR_InvalidateCache(void)

{
  undefined4 uVar1;
  
                    /* 0x6378  24  FSDMGR_InvalidateCache */
  if (DAT_c03c532c == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c532c)();
  }
  return uVar1;
}



/* c03a63e4 FUN_c03a63e4 */

/* Boundary evidence: original MIPS .pdata c03a63e4..c03a640b. Semantic name remains unreviewed. */

undefined4 FUN_c03a63e4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a640c FSDMGR_CacheIoControl */

/* Boundary evidence: original MIPS .pdata c03a640c..c03a6497. Semantic name remains unreviewed. */

undefined4 FSDMGR_CacheIoControl(void)

{
  undefined4 uVar1;
  
                    /* 0x640c  3  FSDMGR_CacheIoControl */
  if (DAT_c03c5328 == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (*DAT_c03c5328)();
  }
  return uVar1;
}



/* c03a6498 FUN_c03a6498 */

/* Boundary evidence: original MIPS .pdata c03a6498..c03a64bf. Semantic name remains unreviewed. */

undefined4 FUN_c03a6498(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a64c0 FUN_c03a64c0 */

/* Boundary evidence: original MIPS .pdata c03a64c0..c03a66bb. Semantic name remains unreviewed. */

DWORD FUN_c03a64c0(void)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  DAT_c03c536c = CreateAPISet(&DAT_c03a18d4,3,&PTR_FUN_c03a1508,&DAT_c03a1520);
  if (((DAT_c03c536c != 0) &&
      (DAT_c03c5370 = CreateAPISet(&DAT_c03a18cc,3,&PTR_FUN_c03a1514,&DAT_c03a1538),
      DAT_c03c5370 != 0)) &&
     (DAT_c03c5374 = CreateAPISet(&DAT_c03a18c4,0x10,&PTR_FUN_c03a1550,&DAT_c03a15d0),
     DAT_c03c5374 != 0)) {
    RegisterAPISet(DAT_c03c536c,0x80000008);
    RegisterAPISet(DAT_c03c5370,0x80000008);
    RegisterAPISet(DAT_c03c5374,0x80000007);
    RegisterDirectMethods(DAT_c03c5374,&PTR_FUN_c03a1590);
    iVar1 = RegisterAFSName(L"StoreMgr");
    if ((iVar1 != -1) && (DVar2 = GetLastError(), DVar2 == 0)) {
      DAT_c03c5378 = CreateAPISet(&DAT_c03a18a8,0x18,&PTR_LAB_c03a1650,&DAT_c03a16b0);
      RegisterAPISet(DAT_c03c5378,0x80000010);
      if ((DAT_c03c5378 != 0) && (iVar3 = RegisterAFSEx(iVar1,DAT_c03c5378,1,4,1), iVar3 != 0)) {
        DAT_c03c537c = CreateAPISet(&DAT_c03a18a0,0x10,&PTR_FUN_c03a17b0,&DAT_c03a17f0);
        RegisterAPISet(DAT_c03c537c,0x80000007);
        RegisterDirectMethods(DAT_c03c537c,&PTR_FUN_c03a1770);
        return 0;
      }
      DVar2 = FUN_c03ac938(0x1f);
      DeregisterAFSName(iVar1);
      return DVar2;
    }
  }
  DVar2 = FUN_c03ac938(0x1f);
  return DVar2;
}



/* c03a66bc FUN_c03a66bc */

/* Boundary evidence: original MIPS .pdata c03a66bc..c03a6743. Semantic name remains unreviewed. */

undefined4 FUN_c03a66bc(STRSAFE_LPCWSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  puVar1 = operator_new(0xdb0);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03b9f24(puVar1,param_1,param_2);
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 8;
  }
  else {
    *param_3 = puVar1;
  }
  return uVar2;
}



/* c03a6744 FUN_c03a6744 */

/* Boundary evidence: original MIPS .pdata c03a6744..c03a678f. Semantic name remains unreviewed. */

DWORD FUN_c03a6744(STRSAFE_LPCWSTR param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD DVar2;
  
  DVar2 = 0;
  if ((param_1 != (STRSAFE_LPCWSTR)0x0) &&
     (bVar1 = FUN_c03ba184(param_2,param_1), CONCAT31(extraout_var,bVar1) == 0)) {
    DVar2 = FUN_c03ac938(0x1f);
  }
  return DVar2;
}



/* c03a6790 FUN_c03a6790 */

/* Boundary evidence: original MIPS .pdata c03a6790..c03a67bf. Semantic name remains unreviewed. */

void FUN_c03a6790(undefined4 param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3)

{
  if (*param_3 == L'\\') {
    param_3 = param_3 + 1;
  }
  FUN_c03b7ea4(param_3,param_2);
  return;
}



/* c03a67c0 FUN_c03a67c0 */

/* Boundary evidence: original MIPS .pdata c03a67c0..c03a6803. Semantic name remains unreviewed. */

int FUN_c03a67c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  
  if (param_5 == 0xf0) {
    iVar1 = FUN_c03b7b14(param_4,param_2);
  }
  else {
    SetLastError(0x57);
    iVar1 = -1;
  }
  return iVar1;
}



/* c03a6804 FSDMGR_DeviceHandleToHDSK */

undefined4 FSDMGR_DeviceHandleToHDSK(undefined4 param_1)

{
                    /* 0x6804  11  FSDMGR_DeviceHandleToHDSK */
  return param_1;
}



/* c03a680c FUN_c03a680c */

/* Boundary evidence: original MIPS .pdata c03a680c..c03a684b. Semantic name remains unreviewed. */

void FUN_c03a680c(int *param_1)

{
  ForwardDeviceIoControl(*(undefined4 *)(*param_1 + 0xda0));
  return;
}



/* c03a684c FUN_c03a684c */

/* Boundary evidence: original MIPS .pdata c03a684c..c03a688f. Semantic name remains unreviewed. */

void FUN_c03a684c(int param_1)

{
  if (*(code **)(param_1 + 0x24) != (code *)0x0) {
    (**(code **)(param_1 + 0x24))();
  }
  return;
}



/* c03a6890 FUN_c03a6890 */

/* Boundary evidence: original MIPS .pdata c03a6890..c03a68b7. Semantic name remains unreviewed. */

undefined4 FUN_c03a6890(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a68b8 FUN_c03a68b8 */

/* Boundary evidence: original MIPS .pdata c03a68b8..c03a68fb. Semantic name remains unreviewed. */

void FUN_c03a68b8(int param_1)

{
  if (*(code **)(param_1 + 0x28) != (code *)0x0) {
    (**(code **)(param_1 + 0x28))();
  }
  return;
}



/* c03a68fc FUN_c03a68fc */

/* Boundary evidence: original MIPS .pdata c03a68fc..c03a6923. Semantic name remains unreviewed. */

undefined4 FUN_c03a68fc(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03a6924 FUN_c03a6924 */

/* Boundary evidence: original MIPS .pdata c03a6924..c03a697f. Semantic name remains unreviewed. */

LONG FUN_c03a6924(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x24e);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c03a6980 FUN_c03a6980 */

/* Boundary evidence: original MIPS .pdata c03a6980..c03a69f3. Semantic name remains unreviewed. */

undefined4 FUN_c03a6980(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x20) == 1) {
    if ((*(uint *)(param_1 + -0x688) & 4) != 0) {
      return 0;
    }
  }
  else if ((*(uint *)(param_1 + -0x688) & 4) == 0) {
    return 0;
  }
  iVar1 = _wcsicmp(param_2,(wchar_t *)(param_1 + -0xd90));
  if (iVar1 != 0) {
    return 0;
  }
  return 1;
}



/* c03a69f4 FUN_c03a69f4 */

/* Boundary evidence: original MIPS .pdata c03a69f4..c03a6aa3. Semantic name remains unreviewed. */

int FUN_c03a69f4(STRSAFE_LPCWSTR param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  wchar_t local_58;
  undefined1 auStack_56 [62];
  undefined4 local_18;
  uint local_14;
  
  local_14 = DAT_c03c531c;
  local_58 = L'\0';
  iVar2 = 0;
  memset(auStack_56,0,0x3e);
  memset(&local_18,0,4);
  StringCchCopyW(&local_58,0x20,param_1);
  local_18 = param_2;
  iVar1 = FUN_c03bc29c(&DAT_c03c6140,FUN_c03a6980,&local_58);
  if (iVar1 != 0) {
    iVar2 = iVar1 + -0xda8;
  }
  FUN_c03c216c(local_14);
  return iVar2;
}



/* c03a6aa4 FUN_c03a6aa4 */

/* Boundary evidence: original MIPS .pdata c03a6aa4..c03a6b2b. Semantic name remains unreviewed. */

void FUN_c03a6aa4(undefined4 *param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  piVar1 = param_1 + 0x36a;
  if (piVar1 != (int *)*piVar1) {
    FUN_c03bc1b0((int)param_1);
    *(undefined4 *)(*piVar1 + 4) = param_1[0x36b];
    *(int *)param_1[0x36b] = *piVar1;
    param_1[0x36b] = piVar1;
    *piVar1 = (int)piVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  FUN_c03a6924(param_1);
  return;
}



/* c03a6b2c FUN_c03a6b2c */

/* Boundary evidence: original MIPS .pdata c03a6b2c..c03a6d6f. Semantic name remains unreviewed. */

undefined4 FUN_c03a6b2c(int *param_1,wchar_t *param_2,undefined4 *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_40;
  undefined4 *local_38;
  
  bVar3 = false;
  bVar2 = false;
  local_40 = 0;
  bVar1 = false;
  local_38 = (undefined4 *)0x0;
  puVar7 = (undefined4 *)&DAT_c03c5398;
  puVar8 = &DAT_c03c6140;
  puVar9 = (undefined4 *)0x0;
  while( true ) {
    while( true ) {
      puVar5 = DAT_c03c6140;
      if (puVar8 != (undefined4 *)*puVar8) {
        puVar5 = (undefined4 *)*puVar8;
      }
      puVar6 = puVar5 + -0x36a;
      if ((undefined4 **)puVar5 != &DAT_c03c6140) {
        InterlockedIncrement(puVar5 + -0x11c);
      }
      if (puVar7 != (undefined4 *)&DAT_c03c5398) {
        FUN_c03a6924(puVar7);
        puVar7 = (undefined4 *)0x0;
      }
      if ((undefined4 **)puVar5 == &DAT_c03c6140) goto LAB_c03a6c8c;
      iVar4 = _wcsicmp((wchar_t *)(puVar5 + -0x364),param_2);
      puVar8 = puVar5;
      if (iVar4 == 0) break;
      puVar7 = puVar6;
      if ((((puVar5[-0x1a2] & 4) != 0) && (puVar5 != (undefined4 *)*puVar5)) &&
         (puVar5[-3] == *(int *)(*param_1 + 0xd9c))) {
        bVar1 = true;
        puVar9 = puVar6;
      }
    }
    if ((puVar5[-0x1a2] & 4) == 0) break;
    if ((puVar5 != (undefined4 *)*puVar5) && (puVar5[-3] == *(int *)(*param_1 + 0xd9c))) {
      bVar1 = true;
      puVar9 = puVar6;
LAB_c03a6c8c:
      if ((bVar1) &&
         (iVar4 = FUN_c03bbf54((int)puVar9,(undefined4 *)*param_1), puVar6 = puVar9, iVar4 != 0)) {
        puVar9[0x1c8] = puVar9[0x1c8] & 0xfffffffb;
        FUN_c03b8fbc((int)puVar9);
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = puVar9;
        }
        bVar2 = true;
      }
      if (bVar3) {
        FUN_c03a6aa4(local_38);
      }
      if (bVar2) {
        FUN_c03bc1b0(*param_1);
        FUN_c03a6924((undefined4 *)*param_1);
        *param_1 = 0;
        FUN_c03a6924(puVar6);
      }
      if ((puVar7 != (undefined4 *)0x0) && (puVar7 != (undefined4 *)&DAT_c03c5398)) {
        FUN_c03a6924(puVar7);
      }
      return local_40;
    }
    bVar3 = true;
    puVar7 = puVar6;
    local_38 = puVar6;
  }
  bVar2 = true;
  local_40 = 0xb7;
  goto LAB_c03a6c8c;
}



/* c03a6d70 FUN_c03a6d70 */

/* Boundary evidence: original MIPS .pdata c03a6d70..c03a6ddb. Semantic name remains unreviewed. */

DWORD FUN_c03a6d70(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  
  DVar3 = 0;
  uVar1 = __GetUserKData(0xc);
  iVar2 = FUN_c03ba8cc(param_3,uVar1);
  *param_2 = iVar2;
  if (iVar2 == -1) {
    DVar3 = FUN_c03ac938(0x1f);
  }
  return DVar3;
}



/* c03a6ddc FUN_c03a6ddc */

/* Boundary evidence: original MIPS .pdata c03a6ddc..c03a6e6b. Semantic name remains unreviewed. */

void FUN_c03a6ddc(undefined4 *param_1)

{
  int iVar1;
  
  if ((HANDLE)param_1[0x368] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[0x368]);
    param_1[0x368] = 0xffffffff;
  }
  if ((HANDLE)param_1[0x369] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[0x369]);
    param_1[0x369] = 0xffffffff;
  }
  for (iVar1 = param_1[0x24e]; iVar1 != 0; iVar1 = iVar1 + -1) {
    FUN_c03a6924(param_1);
  }
  return;
}



/* c03a6e6c FUN_c03a6e6c */

/* Boundary evidence: original MIPS .pdata c03a6e6c..c03a6f0f. Semantic name remains unreviewed. */

DWORD FUN_c03a6e6c(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  DWORD DVar3;
  
  DVar3 = 0;
  if (((*(uint *)(*param_2 + 0x71c) & 0x20) != 0) &&
     (piVar1 = (int *)(*param_2 + 0xcd0), piVar2 = (int *)*piVar1, piVar1 != piVar2)) {
    do {
      DVar3 = FUN_c03bb58c(*param_2,piVar2 + -0xe4);
      if (DVar3 == 0x37) {
        FUN_c03bc1b0(*param_2);
        FUN_c03a6924((undefined4 *)*param_2);
        *param_2 = 0;
        return 0x37;
      }
      piVar2 = (int *)*piVar2;
    } while ((int *)(*param_2 + 0xcd0) != piVar2);
  }
  return DVar3;
}



/* c03a6f10 FUN_c03a6f10 */

/* Boundary evidence: original MIPS .pdata c03a6f10..c03a6f93. Semantic name remains unreviewed. */

void FUN_c03a6f10(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = DAT_c03c531c;
  puVar2 = (undefined4 *)(*param_1 + 0xda8);
  *(undefined4 **)(*param_1 + 0xdac) = DAT_c03c6144;
  *puVar2 = &DAT_c03c6140;
  *DAT_c03c6144 = puVar2;
  DAT_c03c6144 = puVar2;
  if (param_2 != (int *)0x0) {
    *param_2 = *param_1;
  }
  FSDMGR_AdvertiseInterface(&DAT_c03a1880,(short *)(*param_1 + 0x18),1);
  *param_1 = 0;
  FUN_c03c216c(uVar1);
  return;
}



/* c03a6f94 FUN_c03a6f94 */

/* Boundary evidence: original MIPS .pdata c03a6f94..c03a71b3. Semantic name remains unreviewed. */

bool FUN_c03a6f94(STRSAFE_LPCWSTR param_1,undefined4 *param_2,STRSAFE_LPCWSTR param_3,int *param_4)

{
  int *piVar1;
  HANDLE hObject;
  undefined4 *puVar2;
  int iVar3;
  DWORD dwErrCode;
  int *local_28;
  HANDLE local_24;
  
  local_28 = (int *)0x0;
  local_24 = (HANDLE)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  dwErrCode = 0;
  puVar2 = (undefined4 *)FUN_c03a69f4(param_1,1);
  if (puVar2 != (undefined4 *)0x0) {
    dwErrCode = 0xb7;
    FUN_c03a6924(puVar2);
  }
  if (dwErrCode == 0) {
    dwErrCode = FUN_c03a66bc(param_1,param_2,&local_28);
    piVar1 = local_28;
    if ((((dwErrCode == 0) && (dwErrCode = FUN_c03a6744(param_3,(int)local_28), dwErrCode == 0)) &&
        (dwErrCode = FUN_c03ba658(piVar1), dwErrCode == 0)) &&
       (dwErrCode = FUN_c03a6d70(param_1,(int *)&local_24,(int)piVar1), hObject = local_24,
       dwErrCode == 0)) {
      iVar3 = FUN_c03bb068((int)piVar1,local_24,0);
      if (iVar3 == 0) {
        dwErrCode = FUN_c03a6b2c((int *)&local_28,param_1,param_4);
        if (((dwErrCode == 0) && (local_28 != (int *)0x0)) &&
           (dwErrCode = FUN_c03a6e6c(param_1,(int *)&local_28), dwErrCode != 0x37)) {
          iVar3 = 0;
          puVar2 = (undefined4 *)FUN_c03a69f4(param_1,1);
          if (puVar2 != (undefined4 *)0x0) {
            iVar3 = 0xb7;
            FUN_c03a6924(puVar2);
          }
          piVar1 = local_28;
          if (iVar3 == 0) {
            FUN_c03a6f10((int *)&local_28,param_4);
            dwErrCode = 0;
          }
          else {
            FUN_c03bc1b0((int)local_28);
            FUN_c03a6924(piVar1);
            dwErrCode = 0xb7;
          }
        }
        goto LAB_c03a7164;
      }
      dwErrCode = FUN_c03ac938(0x1f);
      CloseHandle(hObject);
    }
    else if (piVar1 == (int *)0x0) goto LAB_c03a7164;
    FUN_c03a6ddc(piVar1);
  }
LAB_c03a7164:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03a71b4 FUN_c03a71b4 */

/* Boundary evidence: original MIPS .pdata c03a71b4..c03a72c3. Semantic name remains unreviewed. */

void FUN_c03a71b4(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  STRSAFE_LPCWSTR pwVar3;
  STRSAFE_LPCWSTR pwVar4;
  int local_230 [2];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
  uVar2 = param_1[0x1c8];
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x20) != 0) {
      pwVar3 = (STRSAFE_LPCWSTR)0x0;
      pwVar4 = (STRSAFE_LPCWSTR)(param_1 + 6);
      param_1[0x1c8] = uVar2 & 0xffffffdf;
      if (param_1[0x365] != 0) {
        StringCchCopyW(awStack_228,0x104,(STRSAFE_LPCWSTR)(param_1[0x365] + 0x2c));
        pwVar3 = awStack_228;
      }
      iVar1 = FUN_c03bc1b0((int)param_1);
      if (iVar1 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
        FUN_c03a6aa4(param_1);
        local_230[0] = 0;
        param_1 = (undefined4 *)0x0;
        FUN_c03a6f94(pwVar4,(undefined4 *)&DAT_c03a1870,pwVar3,local_230);
      }
    }
  }
  else {
    param_1[0x1c8] = uVar2 & 0xffffffdf;
  }
  if (param_1 != (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
  }
  FUN_c03c216c(local_20);
  return;
}



/* c03a72c4 FUN_c03a72c4 */

/* Boundary evidence: original MIPS .pdata c03a72c4..c03a7393. Semantic name remains unreviewed. */

void FUN_c03a72c4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_c03c6140;
  puVar3 = (undefined4 *)&DAT_c03c5398;
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    puVar1 = DAT_c03c6140;
    if (puVar2 != (undefined4 *)*puVar2) {
      puVar1 = (undefined4 *)*puVar2;
    }
    if ((undefined4 **)puVar1 != &DAT_c03c6140) {
      InterlockedIncrement(puVar1 + -0x11c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    if (puVar3 != (undefined4 *)&DAT_c03c5398) {
      FUN_c03a6924(puVar3);
    }
    if ((undefined4 **)puVar1 == &DAT_c03c6140) break;
    FUN_c03a71b4(puVar1 + -0x36a);
    puVar2 = puVar1;
    puVar3 = puVar1 + -0x36a;
  }
  return;
}



/* c03a7394 FUN_c03a7394 */

/* Boundary evidence: original MIPS .pdata c03a7394..c03a7523. Semantic name remains unreviewed. */

void FUN_c03a7394(uint param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  
  bVar1 = false;
  puVar3 = (undefined4 *)&DAT_c03c5398;
  puVar5 = &DAT_c03c6140;
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    puVar2 = DAT_c03c6140;
    if (puVar5 != (undefined4 *)*puVar5) {
      puVar2 = (undefined4 *)*puVar5;
    }
    puVar4 = puVar2 + -0x36a;
    if ((undefined4 **)puVar2 != &DAT_c03c6140) {
      InterlockedIncrement(puVar2 + -0x11c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    if (puVar3 != (undefined4 *)&DAT_c03c5398) {
      FUN_c03a6924(puVar3);
    }
    if ((undefined4 **)puVar2 == &DAT_c03c6140) break;
    lpCriticalSection = (LPCRITICAL_SECTION)(puVar2 + -0x24);
    EnterCriticalSection(lpCriticalSection);
    puVar3 = puVar4;
    puVar5 = puVar2;
    if ((((param_1 & 4) == 0) || ((puVar2[-0x1a2] & 4) == 0)) || ((puVar2[-0x1a2] & 0x40) != 0)) {
      if ((((param_1 & 8) != 0) && ((puVar2[-0x1a2] & 8) != 0)) && ((puVar2[-0x1a2] & 0x10) == 0)) {
        FUN_c03bb114((int)puVar4,0);
        puVar2[-0x1a2] = puVar2[-0x1a2] | 0x30;
        bVar1 = true;
      }
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      FUN_c03bc1b0((int)puVar4);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c03a6aa4(puVar4);
    }
  }
  if (bVar1) {
    FUN_c03a72c4();
  }
  return;
}



/* c03a7524 FUN_c03a7524 */

/* Boundary evidence: original MIPS .pdata c03a7524..c03a762b. Semantic name remains unreviewed. */

void FUN_c03a7524(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)&DAT_c03c5398;
  puVar3 = &DAT_c03c6140;
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    puVar1 = DAT_c03c6140;
    if (puVar3 != (undefined4 *)*puVar3) {
      puVar1 = (undefined4 *)*puVar3;
    }
    if ((undefined4 **)puVar1 != &DAT_c03c6140) {
      InterlockedIncrement(puVar1 + -0x11c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    if (puVar2 != (undefined4 *)&DAT_c03c5398) {
      FUN_c03a6924(puVar2);
    }
    if ((undefined4 **)puVar1 == &DAT_c03c6140) break;
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + -0x24));
    if (puVar1[-5] != 0) {
      FUN_c03a68b8(puVar1[-5]);
    }
    if ((puVar1[-0x1a3] & 0x800) != 0) {
      FUN_c03b8f74((int)(puVar1 + -0x36a));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + -0x24));
    puVar2 = puVar1 + -0x36a;
    puVar3 = puVar1;
  }
  return;
}



/* c03a762c FUN_c03a762c */

/* Boundary evidence: original MIPS .pdata c03a762c..c03a771b. Semantic name remains unreviewed. */

void FUN_c03a762c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_c03c6140;
  puVar3 = (undefined4 *)&DAT_c03c5398;
  while( true ) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    puVar1 = DAT_c03c6140;
    if (puVar2 != (undefined4 *)*puVar2) {
      puVar1 = (undefined4 *)*puVar2;
    }
    if ((undefined4 **)puVar1 != &DAT_c03c6140) {
      InterlockedIncrement(puVar1 + -0x11c);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    if (puVar3 != (undefined4 *)&DAT_c03c5398) {
      FUN_c03a6924(puVar3);
    }
    if ((undefined4 **)puVar1 == &DAT_c03c6140) break;
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + -0x24));
    if (puVar1[-5] != 0) {
      FUN_c03a684c(puVar1[-5]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + -0x24));
    puVar2 = puVar1;
    puVar3 = puVar1 + -0x36a;
  }
  return;
}



/* c03a771c FUN_c03a771c */

/* Boundary evidence: original MIPS .pdata c03a771c..c03a781f. Semantic name remains unreviewed. */

undefined4 FUN_c03a771c(STRSAFE_LPCWSTR param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  puVar1 = (undefined4 *)FUN_c03a69f4(param_1,1);
  if (puVar1 != (undefined4 *)0x0) {
    InterlockedIncrement(puVar1 + 0x24e);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  if (puVar1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    if ((puVar1[0x1c8] & 4) == 0) {
      puVar1[0x1c8] = puVar1[0x1c8] | 4;
      FUN_c03b8f74((int)puVar1);
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
      FUN_c03a6924(puVar1);
      puVar1 = (undefined4 *)0x0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
      DAT_c03c538c = DAT_c03c538c | 1;
      EventModify(DAT_c03c5388,3);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    }
    if (puVar1 != (undefined4 *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
      FUN_c03a6924(puVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* c03a7820 FUN_c03a7820 */

/* Boundary evidence: original MIPS .pdata c03a7820..c03a7937. Semantic name remains unreviewed. */

bool FUN_c03a7820(STRSAFE_LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  puVar1 = (undefined4 *)FUN_c03a69f4(param_1,1);
  if (puVar1 != (undefined4 *)0x0) {
    InterlockedIncrement(puVar1 + 0x24e);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 0x37;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    if ((puVar1[0x1c8] & 4) == 0) {
      FUN_c03bb6d0((int)puVar1);
    }
    else {
      iVar2 = 0x37;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    FUN_c03a6924(puVar1);
  }
  if (iVar2 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    DAT_c03c538c = DAT_c03c538c | 1;
    EventModify(DAT_c03c5388,3);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  }
  return iVar2 == 0;
}



/* c03a7938 FUN_c03a7938 */

/* Boundary evidence: original MIPS .pdata c03a7938..c03a7a0f. Semantic name remains unreviewed. */

bool FUN_c03a7938(STRSAFE_LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  puVar1 = (undefined4 *)FUN_c03a69f4(param_1,1);
  if (puVar1 != (undefined4 *)0x0) {
    InterlockedIncrement(puVar1 + 0x24e);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 0x37;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    if ((puVar1[0x1c8] & 4) == 0) {
      FUN_c03bb814((int)puVar1);
    }
    else {
      iVar2 = 0x37;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    FUN_c03a6924(puVar1);
  }
  return iVar2 == 0;
}



/* c03a7a10 FUN_c03a7a10 */

/* Boundary evidence: original MIPS .pdata c03a7a10..c03a7a7b. Semantic name remains unreviewed. */

undefined4 FUN_c03a7a10(STRSAFE_LPCWSTR param_1)

{
  if (param_1 != (STRSAFE_LPCWSTR)0x0) {
    if (*(int *)(param_1 + 0x10c) == 1) {
      CeSetThreadPriority(0x41,*(undefined4 *)(param_1 + 0x10e));
    }
    FUN_c03a6f94(param_1,(undefined4 *)(param_1 + 0x104),(STRSAFE_LPCWSTR)0x0,(int *)0x0);
    operator_delete(param_1);
  }
  return 0;
}



/* c03a7a7c FUN_c03a7a7c */

/* Boundary evidence: original MIPS .pdata c03a7a7c..c03a7ebf. Semantic name remains unreviewed. */

undefined4 FUN_c03a7a7c(void)

{
  int iVar1;
  HMODULE hLibModule;
  DWORD DVar2;
  STRSAFE_LPWSTR pszDest;
  HANDLE hObject;
  DWORD dwMilliseconds;
  code *pcVar3;
  uint uVar4;
  HKEY local_68;
  DWORD local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58 [2];
  HANDLE local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  memset(&local_3c,0,0x10);
  local_60 = 0xfffffffe;
  local_5c = 0;
  dwMilliseconds = 0xffffffff;
  local_58[0] = 0;
  local_50 = (HANDLE)0x0;
  local_4c = 0;
  local_48 = 0;
  local_64 = 5000;
  local_40 = 0x14;
  local_3c = 0;
  uVar4 = 0;
  local_38 = 0;
  pcVar3 = (code *)0x0;
  local_34 = 0xe8;
  local_30 = 1;
  DAT_c03c5380 = (HANDLE)CreateMsgQueue(0,&local_40);
  if (DAT_c03c5380 != (HANDLE)0x0) {
    local_4c = DAT_c03c5388;
    local_48 = DAT_c03c5394;
    local_50 = DAT_c03c5380;
    iVar1 = FUN_c03acd2c((LPCWSTR)PTR_u_System_StorageManager_c03c5264,&local_68);
    if (iVar1 == 0) {
      iVar1 = FUN_c03acafc(local_68,(LPCWSTR)PTR_u_PNPUnloadDelay_c03c5270,(LPBYTE)&local_64);
      if (iVar1 == 0) {
        local_64 = 5000;
      }
      iVar1 = FUN_c03acafc(local_68,(LPCWSTR)PTR_u_PNPThreadPrio256_c03c5278,(LPBYTE)&local_60);
      if (iVar1 != 0) {
        CeSetThreadPriority(0x41,local_60);
      }
      uVar4 = (uint)(iVar1 != 0);
      FUN_c03acd64(local_68);
    }
    hLibModule = LoadLibraryW(L"coredll.dll");
    if (hLibModule != (HMODULE)0x0) {
      pcVar3 = (code *)FUN_c03acd88();
      FUN_c03acd88();
    }
    FreeLibrary(hLibModule);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(&DAT_c03a1870,DAT_c03c5380,1);
      (*pcVar3)(&DAT_c03a1890,DAT_c03c5380,1);
    }
    do {
      while( true ) {
        while( true ) {
          while (DVar2 = WaitForMultipleObjects(3,&local_50,0,dwMilliseconds), DVar2 == 0x102) {
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
            dwMilliseconds = 0xffffffff;
            DAT_c03c538c = DAT_c03c538c & 0xfffffffe;
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
            FUN_c03a7394(0xc);
          }
          if (DVar2 != 0) break;
          iVar1 = ReadMsgQueue(DAT_c03c5380,&DAT_c03c6148,0xe8,local_58,0xffffffff,&local_5c);
          if (iVar1 != 0) {
            iVar1 = memcmp(&DAT_c03c6148,&DAT_c03a1870,0x10);
            if (iVar1 == 0) {
              if (DAT_c03c615c == 0) {
                FUN_c03a771c((STRSAFE_LPCWSTR)&DAT_c03c6164);
              }
              else {
                pszDest = operator_new(0x220);
                if (pszDest != (STRSAFE_LPWSTR)0x0) {
                  *(undefined4 *)(pszDest + 0x104) = DAT_c03c6148;
                  *(undefined4 *)(pszDest + 0x106) = DAT_c03c614c;
                  *(undefined4 *)(pszDest + 0x108) = DAT_c03c6150;
                  *(undefined4 *)(pszDest + 0x10a) = DAT_c03c6154;
                  StringCchCopyW(pszDest,0x104,(STRSAFE_LPCWSTR)&DAT_c03c6164);
                  *(undefined4 *)(pszDest + 0x10e) = local_60;
                  *(uint *)(pszDest + 0x10c) = uVar4;
                  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c03a7a10,pszDest,0,
                                         (LPDWORD)0x0);
                  if (hObject == (HANDLE)0xffffffff) {
                    FUN_c03a6f94(pszDest,(undefined4 *)(pszDest + 0x104),(STRSAFE_LPCWSTR)0x0,
                                 (int *)0x0);
                    operator_delete(pszDest);
                  }
                  else {
                    CloseHandle(hObject);
                  }
                }
              }
            }
            else {
              iVar1 = memcmp(&DAT_c03c6148,&DAT_c03a1890,0x10);
              if (iVar1 == 0) {
                if (DAT_c03c615c == 0) {
                  FUN_c03a7820((STRSAFE_LPCWSTR)&DAT_c03c6164);
                }
                else {
                  FUN_c03a7938((STRSAFE_LPCWSTR)&DAT_c03c6164);
                }
              }
            }
          }
        }
        if (DVar2 == 1) break;
        if (DVar2 == 2) {
          EventModify(DAT_c03c5394,2);
          FUN_c03a43cc(2,2);
        }
      }
      if ((DAT_c03c538c & 1) != 0) {
        dwMilliseconds = local_64;
      }
      if ((DAT_c03c538c & 2) != 0) {
        FUN_c03a72c4();
      }
    } while( true );
  }
  return 0;
}



/* c03a7ec0 FUN_c03a7ec0 */

/* Boundary evidence: original MIPS .pdata c03a7ec0..c03a801b. Semantic name remains unreviewed. */

DWORD FUN_c03a7ec0(int param_1)

{
  DWORD DVar1;
  int iVar2;
  HKEY local_20;
  undefined4 local_1c;
  
  if (DAT_c03c5384 == (HANDLE)0x0) {
    DAT_c03c5388 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (DAT_c03c5388 != (HANDLE)0x0) {
      DAT_c03c5394 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,L"SYSTEM/AutoLoadFileSystems");
      if (DAT_c03c5394 != (HANDLE)0x0) {
        local_20 = (HKEY)0x0;
        iVar2 = FUN_c03acd2c((LPCWSTR)PTR_u_System_StorageManager_c03c5264,&local_20);
        if (iVar2 == 0) {
          iVar2 = FUN_c03acafc(local_20,(LPCWSTR)PTR_u_PNPUnloadDelay_c03c5270,(LPBYTE)&local_1c);
          if (iVar2 == 0) {
            local_1c = 5000;
          }
          iVar2 = FUN_c03acafc(local_20,(LPCWSTR)PTR_u_PNPWaitIODelay_c03c5274,(LPBYTE)&DAT_c03c5390
                              );
          if (iVar2 == 0) {
            DAT_c03c5390 = local_1c;
          }
          FUN_c03acd64(local_20);
        }
        DAT_c03c5384 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c03a7a7c,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
        if (DAT_c03c5384 != (HANDLE)0x0) goto LAB_c03a7fe4;
      }
    }
    DVar1 = FUN_c03ac938(0x1f);
  }
  else {
LAB_c03a7fe4:
    if (param_1 == 2) {
      EventModify(DAT_c03c5394,3);
    }
    DVar1 = 0;
  }
  return DVar1;
}



/* c03a801c FUN_c03a801c */

/* Boundary evidence: original MIPS .pdata c03a801c..c03a811b. Semantic name remains unreviewed. */

undefined4 FUN_c03a801c(undefined4 param_1,STRSAFE_LPCWSTR param_2)

{
  undefined4 *puVar1;
  
  if (*param_2 == L'\\') {
    param_2 = param_2 + 1;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  puVar1 = (undefined4 *)FUN_c03a69f4(param_2,1);
  if (puVar1 != (undefined4 *)0x0) {
    InterlockedIncrement(puVar1 + 0x24e);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_c03a6f94(param_2,(undefined4 *)&DAT_c03a1870,(STRSAFE_LPCWSTR)0x0,(int *)0x0);
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    puVar1[0x1c8] = puVar1[0x1c8] | 0x20;
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x346));
    FUN_c03a6924(puVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    DAT_c03c538c = DAT_c03c538c | 2;
    EventModify(DAT_c03c5388,3);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  }
  return 1;
}



/* c03a811c FUN_c03a811c */

/* Boundary evidence: original MIPS .pdata c03a811c..c03a814f. Semantic name remains unreviewed. */

undefined4 FUN_c03a811c(undefined4 *param_1)

{
  FUN_c03a6924((undefined4 *)*param_1);
  operator_delete(param_1);
  return 1;
}



/* c03a8150 FSDMGR_InstallFileLock */

/* Boundary evidence: original MIPS .pdata c03a8150..c03a836f. Semantic name remains unreviewed. */

uint FSDMGR_InstallFileLock
               (undefined *param_1,undefined *param_2,int param_3,uint param_4,undefined4 param_5,
               uint param_6,int param_7,int param_8)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  int *piVar6;
  uint uVar7;
  int local_30 [2];
  
                    /* 0x8150  23  FSDMGR_InstallFileLock */
  bVar1 = false;
  iVar2 = (*(code *)param_1)(param_3,local_30);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (bVar1) {
      *(int *)(local_30[0] + 0x18) = *(int *)(local_30[0] + 0x18) + -1;
    }
    if (*(int *)(local_30[0] + 0x10) != 0) break;
    uVar7 = *(uint *)(local_30[0] + 8) & 0xc0000000;
    if (uVar7 == 0) goto LAB_c03a8324;
    piVar6 = (int *)(local_30[0] + 0x1c);
    if (*piVar6 == 0) {
      puVar3 = FUN_c03bc388();
      *(undefined4 **)(local_30[0] + 0x1c) = puVar3;
      piVar6 = (int *)(local_30[0] + 0x1c);
      if (*piVar6 == 0) goto LAB_c03a8320;
    }
    iVar2 = FUN_c03bc74c((int *)*piVar6,param_3,param_4,param_5,param_6,param_7,param_8);
    if (iVar2 == 0) goto LAB_c03a8320;
    if (iVar2 != 2) goto LAB_c03a8324;
    if (*(int *)(local_30[0] + 0x14) == 0) {
      pvVar4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
      *(HANDLE *)(local_30[0] + 0x14) = pvVar4;
      if (*(int *)(local_30[0] + 0x14) == 0) goto LAB_c03a8320;
    }
    *(int *)(local_30[0] + 0x18) = *(int *)(local_30[0] + 0x18) + 1;
    bVar1 = true;
    iVar2 = (*(code *)param_2)(param_3,local_30);
    if (iVar2 == 0) {
      return 0;
    }
    DVar5 = WaitForSingleObject(*(HANDLE *)(local_30[0] + 0x14),0xffffffff);
    if (DVar5 != 0) {
      return 0;
    }
    iVar2 = (*(code *)param_1)(param_3,local_30);
  }
  if (*(int *)(local_30[0] + 0x18) == 0) {
    EventModify(*(undefined4 *)(local_30[0] + 0x14),3);
  }
LAB_c03a8320:
  uVar7 = 0;
LAB_c03a8324:
  iVar2 = (*(code *)param_2)(param_3,local_30);
  if (iVar2 == 0) {
    return 0;
  }
  return uVar7;
}



/* c03a8370 FSDMGR_RemoveFileLock */

/* Boundary evidence: original MIPS .pdata c03a8370..c03a8477. Semantic name remains unreviewed. */

int FSDMGR_RemoveFileLock
              (undefined *param_1,undefined *param_2,int param_3,undefined4 param_4,uint param_5,
              int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
                    /* 0x8370  28  FSDMGR_RemoveFileLock */
  iVar1 = (*(code *)param_1)(param_3,local_20);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int **)(local_20[0] + 0x1c) != (int *)0x0) {
    iVar1 = FUN_c03bca68(*(int **)(local_20[0] + 0x1c),param_3,param_4,param_5,param_6,param_7);
    if (iVar1 == 0) goto LAB_c03a8440;
    if (*(int *)(local_20[0] + 0x18) == 0) {
      iVar2 = FUN_c03bc3c0(*(int **)(local_20[0] + 0x1c));
      if (iVar2 != 0) {
        FUN_c03bc700(*(int **)(local_20[0] + 0x1c));
        *(undefined4 *)(local_20[0] + 0x1c) = 0;
      }
      goto LAB_c03a8440;
    }
    iVar2 = EventModify(*(undefined4 *)(local_20[0] + 0x14),1);
    if (iVar2 != 0) goto LAB_c03a8440;
  }
  iVar1 = 0;
LAB_c03a8440:
  iVar2 = (*(code *)param_2)(param_3,local_20);
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c03a8478 FSDMGR_RemoveFileLockEx */

/* Boundary evidence: original MIPS .pdata c03a8478..c03a8563. Semantic name remains unreviewed. */

int FSDMGR_RemoveFileLockEx(undefined *param_1,undefined *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_18 [2];
  
                    /* 0x8478  29  FSDMGR_RemoveFileLockEx */
  iVar1 = (*(code *)param_1)(param_3,local_18);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (*(int *)(local_18[0] + 0x1c) == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = FUN_c03bc408(*(int **)(local_18[0] + 0x1c),param_3);
      if (iVar2 != 0) {
        if (*(int *)(local_18[0] + 0x18) == 0) {
          iVar1 = FUN_c03bc3c0(*(int **)(local_18[0] + 0x1c));
          if (iVar1 != 0) {
            FUN_c03bc700(*(int **)(local_18[0] + 0x1c));
            *(undefined4 *)(local_18[0] + 0x1c) = 0;
          }
        }
        else {
          iVar1 = EventModify(*(undefined4 *)(local_18[0] + 0x14),1);
          if (iVar1 == 0) {
            iVar2 = 0;
          }
        }
      }
    }
    iVar1 = (*(code *)param_2)(param_3,local_18);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* c03a8564 FSDMGR_TestFileLock */

/* Boundary evidence: original MIPS .pdata c03a8564..c03a861b. Semantic name remains unreviewed. */

undefined4
FSDMGR_TestFileLock(undefined *param_1,undefined *param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_20 [2];
  
                    /* 0x8564  33  FSDMGR_TestFileLock */
  iVar1 = (*(code *)param_1)(param_3,local_20);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (local_20[0][7] == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = FUN_c03bc528((int *)local_20[0][7],param_3,param_4,*local_20[0],local_20[0][1],param_5
                          );
    }
    iVar1 = (*(code *)param_2)(param_3,local_20);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c03a861c FSDMGR_TestFileLockEx */

/* Boundary evidence: original MIPS .pdata c03a861c..c03a86d3. Semantic name remains unreviewed. */

undefined4
FSDMGR_TestFileLockEx
          (undefined *param_1,undefined *param_2,int param_3,int param_4,uint param_5,
          undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
                    /* 0x861c  34  FSDMGR_TestFileLockEx */
  iVar1 = (*(code *)param_1)(param_3,local_20);
  uVar2 = 0;
  if (iVar1 != 0) {
    if (*(int *)(local_20[0] + 0x1c) == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = FUN_c03bc528(*(int **)(local_20[0] + 0x1c),param_3,param_4,param_6,param_7,param_5);
    }
    iVar1 = (*(code *)param_2)(param_3,local_20);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  return uVar2;
}



/* c03a86d4 FSDMGR_EmptyLockContainer */

/* Boundary evidence: original MIPS .pdata c03a86d4..c03a876f. Semantic name remains unreviewed. */

void FSDMGR_EmptyLockContainer(int param_1)

{
  int iVar1;
  
                    /* 0x86d4  13  FSDMGR_EmptyLockContainer */
  if ((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x10) = 1;
      iVar1 = EventModify(*(undefined4 *)(param_1 + 0x14),1);
      if (iVar1 != 0) {
        LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xc));
        WaitForSingleObject(*(HANDLE *)(param_1 + 0x14),0xffffffff);
        EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xc));
      }
    }
    FUN_c03bc700(*(int **)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 0xc));
  }
  return;
}



/* c03a8770 FUN_c03a8770 */

/* Boundary evidence: original MIPS .pdata c03a8770..c03a8867. Semantic name remains unreviewed. */

DWORD FUN_c03a8770(short *param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE hFindFile;
  int iVar1;
  DWORD DVar2;
  undefined4 local_648 [136];
  undefined1 auStack_428 [1040];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  if (DAT_c03c6230 != (code *)0x0) {
    if (*param_1 == 0x5c) {
      param_1 = param_1 + 1;
    }
    local_648[0] = 0x630;
    hFindFile = (HANDLE)(*DAT_c03c6230)(0,param_1,local_648);
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
      iVar1 = CeGetCanonicalPathNameW(auStack_428,param_2,param_3,0);
      if (iVar1 == 0) {
        DVar2 = FUN_c03ac938(0x1f);
        FUN_c03c216c(local_18);
        return DVar2;
      }
      FUN_c03c216c(local_18);
      return 0;
    }
  }
  FUN_c03c216c(local_18);
  return 0x37;
}



/* c03a8868 FUN_c03a8868 */

/* Boundary evidence: original MIPS .pdata c03a8868..c03a88af. Semantic name remains unreviewed. */

undefined4 FUN_c03a8868(void)

{
  GetModuleHandleW(L"coredll.dll");
  DAT_c03c6230 = FUN_c03acd88();
  return 0;
}



/* c03a88b0 FUN_c03a88b0 */

/* Boundary evidence: original MIPS .pdata c03a88b0..c03a8937. Semantic name remains unreviewed. */

bool FUN_c03a88b0(void)

{
  int iVar1;
  
  iVar1 = AFS_GetFileAttributesW();
  return iVar1 != -1;
}



/* c03a8938 FUN_c03a8938 */

/* Boundary evidence: original MIPS .pdata c03a8938..c03a8943. Semantic name remains unreviewed. */

undefined4 FUN_c03a8938(void)

{
  return 1;
}



/* c03a8944 FSEXT_FindNextChangeNotification */

/* Boundary evidence: original MIPS .pdata c03a8944..c03a898f. Semantic name remains unreviewed. */

void FSEXT_FindNextChangeNotification(HANDLE param_1)

{
                    /* 0x8944  71  FSEXT_FindNextChangeNotification */
  SetLastError(0);
  FUN_c03be46c(param_1,0,0,0,0,0);
  return;
}



/* c03a8990 FSINT_FindNextChangeNotification */

/* Boundary evidence: original MIPS .pdata c03a8990..c03a89db. Semantic name remains unreviewed. */

void FSINT_FindNextChangeNotification(undefined4 param_1)

{
                    /* 0x8990  70  FSINT_FindNextChangeNotification */
  SetLastError(0);
  FUN_c03be340(param_1,0,0,0,0,0);
  return;
}



/* c03a89dc FSEXT_FindCloseChangeNotification */

/* Boundary evidence: original MIPS .pdata c03a89dc..c03a8a13. Semantic name remains unreviewed. */

void FSEXT_FindCloseChangeNotification(HANDLE param_1)

{
                    /* 0x89dc  73  FSEXT_FindCloseChangeNotification */
  SetLastError(0);
  FUN_c03be6dc(param_1);
  return;
}



/* c03a8a14 FSINT_FindCloseChangeNotification */

/* Boundary evidence: original MIPS .pdata c03a8a14..c03a8a4b. Semantic name remains unreviewed. */

void FSINT_FindCloseChangeNotification(void)

{
                    /* 0x8a14  72  FSINT_FindCloseChangeNotification */
  SetLastError(0);
  FUN_c03be690();
  return;
}



/* c03a8a4c FSEXT_GetFileNotificationInfoW */

/* Boundary evidence: original MIPS .pdata c03a8a4c..c03a8ac3. Semantic name remains unreviewed. */

void FSEXT_GetFileNotificationInfoW
               (HANDLE param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
                    /* 0x8a4c  75  FSEXT_GetFileNotificationInfoW */
  SetLastError(0);
  FUN_c03be46c(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c03a8ac4 FSINT_GetFileNotificationInfoW */

/* Boundary evidence: original MIPS .pdata c03a8ac4..c03a8b3b. Semantic name remains unreviewed. */

void FSINT_GetFileNotificationInfoW
               (undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
                    /* 0x8ac4  74  FSINT_GetFileNotificationInfoW */
  SetLastError(0);
  FUN_c03be340(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c03a8b3c FUN_c03a8b3c */

/* Boundary evidence: original MIPS .pdata c03a8b3c..c03a8bc3. Semantic name remains unreviewed. */

undefined4 * FUN_c03a8b3c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar1 = operator_new(0x208);
    puVar2 = (undefined4 *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = puVar1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = *puVar2;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return puVar2;
}



/* c03a8bc4 FUN_c03a8bc4 */

/* Boundary evidence: original MIPS .pdata c03a8bc4..c03a8c47. Semantic name remains unreviewed. */

void FUN_c03a8bc4(uint *param_1,uint *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  if (param_1[6] < *param_1) {
    *param_2 = param_1[7];
    param_1[7] = (uint)param_2;
    param_1[6] = param_1[6] + 1;
  }
  else {
    operator_delete(param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
  return;
}



/* c03a8c48 FUN_c03a8c48 */

/* Boundary evidence: original MIPS .pdata c03a8c48..c03a8e07. Semantic name remains unreviewed. */

STRSAFE_PCNZWCH FUN_c03a8c48(int param_1)

{
  STRSAFE_PCNZWCH pwVar1;
  int iVar2;
  STRSAFE_PCNZWCH pwVar3;
  DWORD dwErrCode;
  
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
    pwVar3 = (STRSAFE_PCNZWCH)0x0;
  }
  else {
    pwVar1 = (STRSAFE_PCNZWCH)FUN_c03a8b3c(-0x3fc3ade8);
    if (pwVar1 == (STRSAFE_PCNZWCH)0x0) {
LAB_c03a8cb4:
      dwErrCode = 0xe;
      pwVar3 = pwVar1;
    }
    else {
      iVar2 = CeGetCanonicalPathNameW(param_1,pwVar1,0x104,0);
      if (iVar2 == 0) {
        dwErrCode = FUN_c03ac938(0x1f);
      }
      if (dwErrCode != 0) goto LAB_c03a8da0;
      iVar2 = FUN_c03afe00(pwVar1);
      pwVar3 = pwVar1;
      if (iVar2 != 0) {
        pwVar3 = (STRSAFE_PCNZWCH)FUN_c03a8b3c(-0x3fc3ade8);
        if (pwVar3 == (STRSAFE_PCNZWCH)0x0) goto LAB_c03a8cb4;
        dwErrCode = FUN_c03a8770(pwVar1,pwVar3,0x104);
        if (dwErrCode != 0) {
          FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar3);
          pwVar3 = pwVar1;
          goto LAB_c03a8d98;
        }
        FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar1);
      }
      dwErrCode = 0;
    }
  }
LAB_c03a8d98:
  pwVar1 = pwVar3;
  if (dwErrCode == 0) {
    return pwVar3;
  }
LAB_c03a8da0:
  if (pwVar1 != (STRSAFE_PCNZWCH)0x0) {
    FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar1);
  }
  SetLastError(dwErrCode);
  return (STRSAFE_PCNZWCH)0x0;
}



/* c03a8e08 FUN_c03a8e08 */

/* Boundary evidence: original MIPS .pdata c03a8e08..c03a8e13. Semantic name remains unreviewed. */

undefined4 FUN_c03a8e08(void)

{
  return 1;
}



/* c03a8e14 FS_GetDiskFreeSpaceExW */

/* Boundary evidence: original MIPS .pdata c03a8e14..c03a90fb. Semantic name remains unreviewed. */

int FS_GetDiskFreeSpaceExW(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  longlong lVar1;
  STRSAFE_PCNZWCH lpFileName;
  DWORD DVar2;
  int iVar3;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  STRSAFE_PCNZWCH local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
                    /* 0x8e14  62  FS_GetDiskFreeSpaceExW */
  lpFileName = FUN_c03a8c48(param_1);
  iVar3 = 0;
  if (lpFileName == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_34 = 0;
  local_2c = lpFileName;
  DVar2 = GetFileAttributesW(lpFileName);
  if (DVar2 == 0xffffffff) {
    DVar2 = 3;
  }
  else {
    if ((DVar2 & 0x10) == 0) {
      SetLastError(0x10b);
      goto LAB_c03a90ac;
    }
    DVar2 = FUN_c03af664(DAT_c03c623c,lpFileName,&local_28,&local_24,(undefined4 *)0x0,(int *)0x0);
    if (DVar2 == 0) {
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_30 = 0;
      SetLastError(0);
      iVar3 = AFS_GetDiskFreeSpace(local_24,local_28,&local_40,&local_3c,&local_38,&local_30);
      local_34 = iVar3;
      if (iVar3 != 0) {
        if (param_2 != (undefined4 *)0x0) {
          lVar1 = ((ulonglong)local_38 * (ulonglong)local_3c & 0xffffffff) * (ulonglong)local_40;
          *param_2 = (int)lVar1;
          param_2[1] = (int)((ulonglong)local_38 * (ulonglong)local_3c >> 0x20) * local_40 +
                       (int)((ulonglong)lVar1 >> 0x20);
        }
        if (param_4 != (undefined4 *)0x0) {
          lVar1 = ((ulonglong)local_38 * (ulonglong)local_3c & 0xffffffff) * (ulonglong)local_40;
          *param_4 = (int)lVar1;
          param_4[1] = (int)((ulonglong)local_38 * (ulonglong)local_3c >> 0x20) * local_40 +
                       (int)((ulonglong)lVar1 >> 0x20);
        }
        if (param_3 != (undefined4 *)0x0) {
          lVar1 = ((ulonglong)local_30 * (ulonglong)local_3c & 0xffffffff) * (ulonglong)local_40;
          *param_3 = (int)lVar1;
          param_3[1] = (int)((ulonglong)local_30 * (ulonglong)local_3c >> 0x20) * local_40 +
                       (int)((ulonglong)lVar1 >> 0x20);
        }
      }
      goto LAB_c03a90ac;
    }
  }
  SetLastError(DVar2);
LAB_c03a90ac:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)lpFileName);
  return iVar3;
}



/* c03a90fc FUN_c03a90fc */

/* Boundary evidence: original MIPS .pdata c03a90fc..c03a9107. Semantic name remains unreviewed. */

undefined4 FUN_c03a90fc(void)

{
  return 1;
}



/* c03a9108 FUN_c03a9108 */

/* Boundary evidence: original MIPS .pdata c03a9108..c03a9113. Semantic name remains unreviewed. */

undefined4 FUN_c03a9108(void)

{
  return 1;
}



/* c03a9114 FS_IsSystemFileW */

/* Boundary evidence: original MIPS .pdata c03a9114..c03a9263. Semantic name remains unreviewed. */

undefined4 FS_IsSystemFileW(int param_1)

{
  STRSAFE_PCNZWCH pwVar1;
  DWORD dwErrCode;
  uint uVar2;
  undefined4 uVar3;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  STRSAFE_PCNZWCH local_18;
  
                    /* 0x9114  67  FS_IsSystemFileW */
  pwVar1 = FUN_c03a8c48(param_1);
  uVar3 = 0;
  if (pwVar1 != (STRSAFE_PCNZWCH)0x0) {
    local_18 = pwVar1;
    dwErrCode = FUN_c03af664(DAT_c03c623c,pwVar1,&local_20,&local_1c,&local_24,(int *)0x0);
    if (dwErrCode == 0) {
      if ((local_24 & 0x20) == 0) {
        uVar2 = AFS_GetFileAttributesW(local_1c,local_20);
        if ((uVar2 == 0xffffffff) || (uVar3 = 1, (uVar2 & 4) == 0)) {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      SetLastError(dwErrCode);
    }
    FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar1);
  }
  return uVar3;
}



/* c03a9264 FUN_c03a9264 */

/* Boundary evidence: original MIPS .pdata c03a9264..c03a926f. Semantic name remains unreviewed. */

undefined4 FUN_c03a9264(void)

{
  return 1;
}



/* c03a9270 FUN_c03a9270 */

/* Boundary evidence: original MIPS .pdata c03a9270..c03a92e3. Semantic name remains unreviewed. */

undefined4
FUN_c03a9270(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = (**(code **)(param_1 + 0x28))
                      (param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                       param_11);
  }
  return uVar1;
}



/* c03a92e4 FSINT_CreateDirectoryW */

/* Boundary evidence: original MIPS .pdata c03a92e4..c03a95c7. Semantic name remains unreviewed. */

undefined4 FSINT_CreateDirectoryW(int param_1,undefined4 param_2)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  int iVar2;
  undefined3 extraout_var;
  size_t sVar3;
  DWORD dwErrCode;
  code *pcVar4;
  undefined4 uVar5;
  int local_38;
  short *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  STRSAFE_PCNZWCH local_1c;
  
                    /* 0x92e4  55  FSINT_CreateDirectoryW */
  _Str = FUN_c03a8c48(param_1);
  uVar5 = 0;
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_28 = 0;
  local_1c = _Str;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,&local_34,&local_20,&local_24,&local_38);
  pcVar4 = SetLastError_exref;
  if (iVar2 == 0) {
    if ((*local_34 == 0x5c) && (local_34[1] == 0)) {
      SetLastError(0xb7);
    }
    else {
      if (((local_24 & 4) == 0) || (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var,bVar1) == 0))
      {
LAB_c03a9418:
        if (local_38 != 0) {
          (**(code **)(DAT_c03c623c + 0xc))(local_38);
        }
        local_30 = 0;
        local_2c = 0;
        dwErrCode = FUN_c03a9270(DAT_c03c623c,local_38,local_34,7,0x43,0,4,0x10,param_2,&local_30,
                                 &local_2c);
        if (dwErrCode == 0) {
          SetLastError(0);
          uVar5 = AFS_CreateDirectoryW(local_20,local_34,0,local_30,local_2c);
          local_28 = uVar5;
        }
        else {
          SetLastError(dwErrCode);
        }
        if ((local_38 == 0) ||
           ((**(code **)(DAT_c03c623c + 0x1c))(local_38,param_2,local_30), local_38 == 0))
        goto LAB_c03a9588;
        pcVar4 = *(code **)(DAT_c03c623c + 0x10);
        iVar2 = local_38;
      }
      else {
        sVar3 = wcslen(_Str);
        iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar3);
        if (iVar2 == 0) goto LAB_c03a9418;
        iVar2 = 0xb7;
        pcVar4 = SetLastError_exref;
      }
      (*pcVar4)(iVar2);
    }
    if (local_38 == 0) goto LAB_c03a9588;
    iVar2 = local_38;
    pcVar4 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar4)(iVar2);
LAB_c03a9588:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return uVar5;
}



/* c03a95c8 FUN_c03a95c8 */

/* Boundary evidence: original MIPS .pdata c03a95c8..c03a95d3. Semantic name remains unreviewed. */

undefined4 FUN_c03a95c8(void)

{
  return 1;
}



/* c03a95d4 FS_RemoveDirectoryW */

/* Boundary evidence: original MIPS .pdata c03a95d4..c03a9867. Semantic name remains unreviewed. */

undefined4 FS_RemoveDirectoryW(int param_1)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  int iVar2;
  undefined3 extraout_var;
  size_t sVar3;
  DWORD dwErrCode;
  code *pcVar4;
  undefined4 uVar5;
  short *local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  STRSAFE_PCNZWCH local_1c;
  
                    /* 0x95d4  56  FS_RemoveDirectoryW */
  _Str = FUN_c03a8c48(param_1);
  uVar5 = 0;
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_28 = 0;
  local_1c = _Str;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,&local_30,&local_20,&local_24,&local_2c);
  pcVar4 = SetLastError_exref;
  if (iVar2 == 0) {
    if ((*local_30 == 0x5c) && (local_30[1] == 0)) {
      SetLastError(5);
    }
    else {
      if (((local_24 & 4) == 0) || (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var,bVar1) == 0))
      {
LAB_c03a96fc:
        if (local_2c != 0) {
          (**(code **)(DAT_c03c623c + 0xc))(local_2c);
        }
        dwErrCode = FUN_c03a9270(DAT_c03c623c,local_2c,local_30,7,0x43,0x10000,0x40,0xffffffff,0,0,0
                                );
        if (dwErrCode == 0) {
          SetLastError(0);
          uVar5 = AFS_RemoveDirectoryW(local_20,local_30);
          local_28 = uVar5;
        }
        else {
          SetLastError(dwErrCode);
        }
        if (local_2c == 0) goto LAB_c03a982c;
        pcVar4 = *(code **)(DAT_c03c623c + 0x10);
        iVar2 = local_2c;
      }
      else {
        sVar3 = wcslen(_Str);
        iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar3);
        if (iVar2 == 0) goto LAB_c03a96fc;
        iVar2 = 5;
        pcVar4 = SetLastError_exref;
      }
      (*pcVar4)(iVar2);
    }
    if (local_2c == 0) goto LAB_c03a982c;
    iVar2 = local_2c;
    pcVar4 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar4)(iVar2);
LAB_c03a982c:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return uVar5;
}



/* c03a9868 FUN_c03a9868 */

/* Boundary evidence: original MIPS .pdata c03a9868..c03a9873. Semantic name remains unreviewed. */

undefined4 FUN_c03a9868(void)

{
  return 1;
}



/* c03a9874 FS_GetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c03a9874..c03a9bff. Semantic name remains unreviewed. */

uint FS_GetFileAttributesW(int param_1)

{
  STRSAFE_PCNZWCH ******pppppppwVar1;
  STRSAFE_PCNZWCH ******pppppppwVar2;
  int iVar3;
  DWORD DVar4;
  STRSAFE_PCNZWCH ******pppppppwVar5;
  STRSAFE_PCNZWCH ******pppppppwVar6;
  undefined4 *puVar7;
  code *pcVar8;
  uint uVar9;
  undefined4 *puVar10;
  STRSAFE_PCNZWCH *****local_40;
  STRSAFE_PCNZWCH *****local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  STRSAFE_PCNZWCH *****local_2c;
  
                    /* 0x9874  57  FS_GetFileAttributesW */
  pppppppwVar1 = (STRSAFE_PCNZWCH ******)FUN_c03a8c48(param_1);
  if (pppppppwVar1 == (STRSAFE_PCNZWCH ******)0x0) {
    return 0xffffffff;
  }
  local_38 = 0xffffffff;
  puVar7 = &local_30;
  pppppppwVar6 = &local_3c;
  pppppppwVar5 = pppppppwVar1;
  local_2c = (STRSAFE_PCNZWCH *****)pppppppwVar1;
  pppppppwVar2 = (STRSAFE_PCNZWCH ******)
                 FUN_c03af664(DAT_c03c623c,(wchar_t *)pppppppwVar1,pppppppwVar6,puVar7,&local_34,
                              (int *)&local_40);
  pcVar8 = SetLastError_exref;
  uVar9 = 0xffffffff;
  if (pppppppwVar2 == (STRSAFE_PCNZWCH ******)0x0) {
    if ((*(wchar_t *)local_3c == L'\\') && (*(STRSAFE_PCNZWCH)((int)local_3c + 2) == L'\0')) {
      uVar9 = 0x10;
      if ((local_34 & 1) != 0) {
        uVar9 = 0x12;
      }
      if ((local_34 & 0x40) == 0) {
        uVar9 = uVar9 | 0x100;
      }
      if ((local_34 & 0x20) != 0) {
        uVar9 = uVar9 | 4;
      }
    }
    else {
      SetLastError(0);
      pppppppwVar5 = (STRSAFE_PCNZWCH ******)local_3c;
      uVar9 = AFS_GetFileAttributesW(local_30);
      local_38 = uVar9;
      if (uVar9 != 0xffffffff) {
        if ((local_34 & 0x10) == 0) {
          uVar9 = uVar9 & 0xffffdfbf;
        }
        if ((local_34 & 0x20) != 0) {
          uVar9 = uVar9 | 4;
        }
        puVar10 = (undefined4 *)0x7;
        if ((uVar9 & 0x10) == 0) {
          puVar10 = (undefined4 *)0x1;
        }
        if ((STRSAFE_PCNZWCH ******)local_40 != (STRSAFE_PCNZWCH ******)0x0) {
          (**(code **)(DAT_c03c623c + 0xc))(local_40);
        }
        pppppppwVar5 = (STRSAFE_PCNZWCH ******)local_40;
        pppppppwVar6 = (STRSAFE_PCNZWCH ******)local_3c;
        puVar7 = puVar10;
        DVar4 = FUN_c03a9270(DAT_c03c623c,(int)local_40,local_3c,puVar10,0x43,0x80,0,0xffffffff,0,0,
                             0);
        if (DVar4 == 5) {
          pppppppwVar5 = (STRSAFE_PCNZWCH ******)local_40;
          DVar4 = FUN_c03a9270(DAT_c03c623c,(int)local_40,local_3c,puVar10,0x43,0,1,0xffffffff,0,0,0
                              );
          pppppppwVar6 = (STRSAFE_PCNZWCH ******)local_3c;
          puVar7 = puVar10;
        }
        if (DVar4 != 0) {
          SetLastError(DVar4);
          uVar9 = 0xffffffff;
        }
        if ((STRSAFE_PCNZWCH ******)local_40 == (STRSAFE_PCNZWCH ******)0x0) goto LAB_c03a9b5c;
        (**(code **)(DAT_c03c623c + 0x10))();
      }
    }
    if ((STRSAFE_PCNZWCH ******)local_40 == (STRSAFE_PCNZWCH ******)0x0) goto LAB_c03a9b5c;
    pppppppwVar2 = (STRSAFE_PCNZWCH ******)local_40;
    pcVar8 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar8)(pppppppwVar2);
LAB_c03a9b5c:
  if ((uVar9 == 0xffffffff) && (iVar3 = FUN_c03afc28((wchar_t *)pppppppwVar1), iVar3 != 0)) {
    DVar4 = FUN_c03ac938(2);
    uVar9 = FUN_c03b001c(pppppppwVar1,pppppppwVar5,pppppppwVar6,puVar7);
    if (uVar9 == 0xffffffff) {
      SetLastError(DVar4);
    }
  }
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pppppppwVar1);
  return uVar9;
}



/* c03a9c00 FUN_c03a9c00 */

/* Boundary evidence: original MIPS .pdata c03a9c00..c03a9c0b. Semantic name remains unreviewed. */

undefined4 FUN_c03a9c00(void)

{
  return 1;
}



/* c03a9c0c FS_SetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c03a9c0c..c03a9f6f. Semantic name remains unreviewed. */

undefined4 FS_SetFileAttributesW(int param_1,uint param_2)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  size_t sVar3;
  DWORD dwErrCode;
  short *psVar4;
  short **ppsVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  code *pcVar8;
  short *local_40;
  int local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  STRSAFE_PCNZWCH local_2c;
  undefined4 local_28;
  
                    /* 0x9c0c  58  FS_SetFileAttributesW */
  _Str = FUN_c03a8c48(param_1);
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_28 = 0;
  puVar6 = &local_38;
  ppsVar5 = &local_40;
  local_2c = _Str;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,ppsVar5,puVar6,&local_34,&local_3c);
  pcVar8 = SetLastError_exref;
  if (iVar2 == 0) {
    if ((*local_40 == 0x5c) && (local_40[1] == 0)) {
      SetLastError(5);
    }
    else {
      if (((local_34 & 4) == 0) ||
         ((psVar4 = local_40, bVar1 = FUN_c03a88b0(), CONCAT31(extraout_var,bVar1) != 0 ||
          (bVar1 = FUN_c03b0dec(_Str,psVar4,ppsVar5,puVar6), CONCAT31(extraout_var_00,bVar1) == 0)))
         ) {
        if (((local_34 & 4) != 0) &&
           (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var_01,bVar1) != 0)) {
          sVar3 = wcslen(_Str);
          iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar3);
          if (iVar2 != 0) goto LAB_c03a9d1c;
        }
        if (local_3c != 0) {
          (**(code **)(DAT_c03c623c + 0xc))(local_3c,local_40);
        }
        local_30 = 0xffffffff;
        local_30 = AFS_GetFileAttributesW(local_38,local_40);
        if ((local_30 == 0xffffffff) || (uVar7 = 7, (local_30 & 0x10) == 0)) {
          uVar7 = 1;
        }
        dwErrCode = FUN_c03a9270(DAT_c03c623c,local_3c,local_40,uVar7,0x43,0x100,0,
                                 param_2 & 0xffffdfbf,0,0,0);
        if (dwErrCode == 0) {
          SetLastError(0);
          local_28 = AFS_SetFileAttributesW(local_38,local_40,param_2 & 0xffffdfbf);
        }
        else {
          SetLastError(dwErrCode);
        }
        if (local_3c == 0) goto LAB_c03a9f20;
        pcVar8 = *(code **)(DAT_c03c623c + 0x10);
        iVar2 = local_3c;
      }
      else {
LAB_c03a9d1c:
        iVar2 = 5;
        pcVar8 = SetLastError_exref;
      }
      (*pcVar8)(iVar2);
    }
    if (local_3c == 0) goto LAB_c03a9f20;
    iVar2 = local_3c;
    pcVar8 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar8)(iVar2);
LAB_c03a9f20:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return local_28;
}



/* c03a9f70 FUN_c03a9f70 */

/* Boundary evidence: original MIPS .pdata c03a9f70..c03a9f7b. Semantic name remains unreviewed. */

undefined4 FUN_c03a9f70(void)

{
  return 1;
}



/* c03a9f7c FUN_c03a9f7c */

/* Boundary evidence: original MIPS .pdata c03a9f7c..c03a9f87. Semantic name remains unreviewed. */

undefined4 FUN_c03a9f7c(void)

{
  return 1;
}



/* c03a9f88 FS_DeleteFileW */

/* Boundary evidence: original MIPS .pdata c03a9f88..c03aa267. Semantic name remains unreviewed. */

undefined4 FS_DeleteFileW(int param_1)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  int iVar2;
  undefined3 extraout_var;
  size_t sVar3;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  DWORD dwErrCode;
  short *psVar4;
  short *psVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined4 uVar8;
  short *local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  STRSAFE_PCNZWCH local_1c;
  
                    /* 0x9f88  59  FS_DeleteFileW */
  _Str = FUN_c03a8c48(param_1);
  uVar8 = 0;
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_20 = 0;
  puVar6 = &local_24;
  local_1c = _Str;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,&local_30,puVar6,&local_28,&local_2c);
  pcVar7 = SetLastError_exref;
  if (iVar2 == 0) {
    if ((*local_30 == 0x5c) && (local_30[1] == 0)) {
      SetLastError(2);
    }
    else {
      if (((local_28 & 4) == 0) || (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var,bVar1) == 0))
      {
LAB_c03aa0b4:
        if ((((local_28 & 4) == 0) ||
            (psVar4 = local_30, psVar5 = local_30, bVar1 = FUN_c03a88b0(),
            CONCAT31(extraout_var_00,bVar1) != 0)) ||
           (bVar1 = FUN_c03b0dec(_Str,psVar4,psVar5,puVar6), CONCAT31(extraout_var_01,bVar1) == 0))
        {
          if (local_2c != 0) {
            (**(code **)(DAT_c03c623c + 0xc))(local_2c);
          }
          dwErrCode = FUN_c03a9270(DAT_c03c623c,local_2c,local_30,1,0x43,0x10000,0x40,0xffffffff,0,0
                                   ,0);
          if (dwErrCode == 0) {
            SetLastError(0);
            uVar8 = AFS_DeleteFileW(local_24,local_30);
            local_20 = uVar8;
          }
          else {
            SetLastError(dwErrCode);
          }
          if (local_2c == 0) goto LAB_c03aa22c;
          iVar2 = local_2c;
          pcVar7 = *(code **)(DAT_c03c623c + 0x10);
        }
        else {
          iVar2 = 5;
          pcVar7 = SetLastError_exref;
        }
      }
      else {
        sVar3 = wcslen(_Str);
        iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar3);
        if (iVar2 == 0) goto LAB_c03aa0b4;
        iVar2 = 2;
        pcVar7 = SetLastError_exref;
      }
      (*pcVar7)(iVar2);
    }
    if (local_2c == 0) goto LAB_c03aa22c;
    iVar2 = local_2c;
    pcVar7 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar7)(iVar2);
LAB_c03aa22c:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return uVar8;
}



/* c03aa268 FUN_c03aa268 */

/* Boundary evidence: original MIPS .pdata c03aa268..c03aa273. Semantic name remains unreviewed. */

undefined4 FUN_c03aa268(void)

{
  return 1;
}



/* c03aa274 FS_MoveFileW */

/* Boundary evidence: original MIPS .pdata c03aa274..c03aa93b. Semantic name remains unreviewed. */

undefined4 FS_MoveFileW(int param_1,int param_2)

{
  bool bVar1;
  STRSAFE_PCNZWCH lpExistingFileName;
  STRSAFE_PCNZWCH lpNewFileName;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  size_t sVar3;
  undefined3 extraout_var_02;
  uint uVar4;
  BOOL BVar5;
  DWORD DVar6;
  short *psVar7;
  short **ppsVar8;
  int *piVar9;
  code *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  short *local_58;
  int local_54;
  int local_50;
  STRSAFE_PCNZWCH local_4c;
  STRSAFE_PCNZWCH local_48;
  uint local_44;
  short *local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  int local_30 [2];
  
                    /* 0xa274  60  FS_MoveFileW */
  lpExistingFileName = FUN_c03a8c48(param_1);
  if (lpExistingFileName == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_4c = lpExistingFileName;
  lpNewFileName = FUN_c03a8c48(param_2);
  local_48 = lpNewFileName;
  if (lpNewFileName == (STRSAFE_PCNZWCH)0x0) {
    FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)lpExistingFileName);
    return 0;
  }
  local_3c = 0;
  iVar2 = FUN_c03af664(DAT_c03c623c,lpExistingFileName,&local_58,&local_50,&local_44,&local_54);
  pcVar10 = SetLastError_exref;
  if (iVar2 == 0) {
    piVar9 = local_30;
    ppsVar8 = &local_40;
    iVar2 = FUN_c03af664(DAT_c03c623c,lpNewFileName,ppsVar8,piVar9,(undefined4 *)0x0,(int *)0x0);
    pcVar10 = SetLastError_exref;
    if (iVar2 == 0) {
      if (*local_58 == 0) {
        DVar6 = 5;
LAB_c03aa3a8:
        SetLastError(DVar6);
      }
      else {
        if (*local_40 == 0) {
          DVar6 = 0xb7;
          goto LAB_c03aa3a8;
        }
        if (local_50 == local_30[0]) {
          if ((((local_44 & 4) == 0) ||
              (psVar7 = local_58, bVar1 = FUN_c03a88b0(), CONCAT31(extraout_var,bVar1) != 0)) ||
             (bVar1 = FUN_c03b0dec(lpExistingFileName,psVar7,ppsVar8,piVar9),
             CONCAT31(extraout_var_00,bVar1) == 0)) {
            if (((local_44 & 4) != 0) &&
               (bVar1 = FUN_c03afce8(lpExistingFileName), CONCAT31(extraout_var_01,bVar1) != 0)) {
              sVar3 = wcslen(lpExistingFileName);
              iVar2 = FUN_c03ae6c8(DAT_c03c623c,lpExistingFileName,sVar3);
              if (iVar2 != 0) goto LAB_c03aa454;
            }
            if (((local_44 & 4) != 0) &&
               (bVar1 = FUN_c03afce8(lpNewFileName), CONCAT31(extraout_var_02,bVar1) != 0)) {
              sVar3 = wcslen(lpNewFileName);
              iVar2 = FUN_c03ae6c8(DAT_c03c623c,lpNewFileName,sVar3);
              if (iVar2 != 0) {
                iVar2 = 0xb7;
                pcVar10 = SetLastError_exref;
                goto LAB_c03aa68c;
              }
            }
            if (local_54 != 0) {
              (**(code **)(DAT_c03c623c + 0xc))();
            }
            local_38 = 0xffffffff;
            uVar4 = AFS_GetFileAttributesW(local_50,local_58);
            if ((uVar4 == 0xffffffff) || (uVar12 = 7, (uVar4 & 0x10) == 0)) {
              uVar12 = 1;
            }
            local_38 = uVar4;
            DVar6 = FUN_c03a9270(DAT_c03c623c,local_54,local_58,uVar12,0x43,0,0x40,0xffffffff,0,0,0)
            ;
            if (DVar6 == 0) {
              uVar11 = 2;
              if ((uVar4 != 0xffffffff) && ((uVar4 & 0x10) != 0)) {
                uVar11 = 4;
              }
              DVar6 = FUN_c03a9270(DAT_c03c623c,local_54,local_40,uVar12,0x43,0,uVar11,0xffffffff,0,
                                   0,0);
              if (DVar6 != 0) goto LAB_c03aa668;
              SetLastError(0);
              local_3c = AFS_MoveFileW(local_50,local_58,local_40);
            }
            else {
LAB_c03aa668:
              SetLastError(DVar6);
            }
            if (local_54 == 0) goto LAB_c03aa8cc;
            iVar2 = local_54;
            pcVar10 = *(code **)(DAT_c03c623c + 0x10);
          }
          else {
LAB_c03aa454:
            iVar2 = 5;
            pcVar10 = SetLastError_exref;
          }
LAB_c03aa68c:
          (*pcVar10)(iVar2);
        }
        else {
          local_34 = 0xffffffff;
          local_34 = AFS_GetFileAttributesW(local_50,local_58);
          if (local_34 != 0xffffffff) {
            if ((local_34 & 0x10) == 0) {
              if ((local_34 & 0x40) == 0) goto LAB_c03aa744;
              DVar6 = 5;
            }
            else {
              DVar6 = 0x11;
            }
            SetLastError(DVar6);
          }
LAB_c03aa744:
          BVar5 = CopyFileW(lpExistingFileName,lpNewFileName,1);
          if (BVar5 != 0) {
            if (local_54 != 0) {
              (**(code **)(DAT_c03c623c + 0xc))(local_54);
            }
            iVar2 = FUN_c03a9270(DAT_c03c623c,local_54,local_58,1,0x43,0x100,0,0x80,0,0,0);
            if (iVar2 == 0) {
              AFS_SetFileAttributesW(local_50,local_58,0x80);
            }
            iVar2 = FUN_c03a9270(DAT_c03c623c,local_54,local_58,1,0x43,0x10000,0x40,0xffffffff,0,0,0
                                );
            if (iVar2 == 0) {
              AFS_DeleteFileW(local_50,local_58);
            }
            if (local_54 != 0) {
              (**(code **)(DAT_c03c623c + 0x10))();
            }
            local_3c = 1;
          }
        }
      }
      if (local_54 == 0) goto LAB_c03aa8cc;
      iVar2 = local_54;
      pcVar10 = *(code **)(DAT_c03c623c + 0x18);
    }
  }
  (*pcVar10)(iVar2);
LAB_c03aa8cc:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)lpExistingFileName);
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)lpNewFileName);
  return local_3c;
}



/* c03aa93c FUN_c03aa93c */

/* Boundary evidence: original MIPS .pdata c03aa93c..c03aa947. Semantic name remains unreviewed. */

undefined4 FUN_c03aa93c(void)

{
  return 1;
}



/* c03aa948 FUN_c03aa948 */

/* Boundary evidence: original MIPS .pdata c03aa948..c03aa953. Semantic name remains unreviewed. */

undefined4 FUN_c03aa948(void)

{
  return 1;
}



/* c03aa954 FUN_c03aa954 */

/* Boundary evidence: original MIPS .pdata c03aa954..c03aa95f. Semantic name remains unreviewed. */

undefined4 FUN_c03aa954(void)

{
  return 1;
}



/* c03aa960 FUN_c03aa960 */

/* Boundary evidence: original MIPS .pdata c03aa960..c03aa96b. Semantic name remains unreviewed. */

undefined4 FUN_c03aa960(void)

{
  return 1;
}



/* c03aa96c FUN_c03aa96c */

/* Boundary evidence: original MIPS .pdata c03aa96c..c03aa977. Semantic name remains unreviewed. */

undefined4 FUN_c03aa96c(void)

{
  return 1;
}



/* c03aa978 FS_DeleteAndRenameFileW */

/* Boundary evidence: original MIPS .pdata c03aa978..c03aad7f. Semantic name remains unreviewed. */

undefined4 FS_DeleteAndRenameFileW(int param_1,int param_2)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  STRSAFE_PCNZWCH _Str_00;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  size_t sVar3;
  undefined3 extraout_var_04;
  DWORD dwErrCode;
  short *psVar4;
  short **ppsVar5;
  int *piVar6;
  code *pcVar7;
  undefined4 uVar8;
  int local_48;
  short *local_44;
  short *local_40;
  int local_3c;
  uint local_38;
  int local_34;
  undefined4 local_30;
  STRSAFE_PCNZWCH local_2c;
  STRSAFE_PCNZWCH local_28;
  
                    /* 0xa978  61  FS_DeleteAndRenameFileW */
  _Str = FUN_c03a8c48(param_2);
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_2c = _Str;
  _Str_00 = FUN_c03a8c48(param_1);
  local_28 = _Str_00;
  if (_Str_00 == (STRSAFE_PCNZWCH)0x0) {
    FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
    return 0;
  }
  uVar8 = 0;
  local_30 = 0;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,&local_40,&local_34,&local_38,(int *)0x0);
  pcVar7 = SetLastError_exref;
  if (iVar2 == 0) {
    piVar6 = &local_3c;
    ppsVar5 = &local_44;
    iVar2 = FUN_c03af664(DAT_c03c623c,_Str_00,ppsVar5,piVar6,(undefined4 *)0x0,&local_48);
    pcVar7 = SetLastError_exref;
    if (iVar2 == 0) {
      if ((*local_40 == 0) || (*local_44 == 0)) {
LAB_c03aad10:
        iVar2 = 5;
        pcVar7 = SetLastError_exref;
      }
      else if (local_34 == local_3c) {
        if (((local_38 & 4) != 0) &&
           (((psVar4 = local_40, bVar1 = FUN_c03a88b0(), CONCAT31(extraout_var,bVar1) == 0 &&
             (bVar1 = FUN_c03b0dec(_Str,psVar4,ppsVar5,piVar6), CONCAT31(extraout_var_00,bVar1) != 0
             )) || ((psVar4 = local_44, bVar1 = FUN_c03a88b0(), CONCAT31(extraout_var_01,bVar1) == 0
                    && (bVar1 = FUN_c03b0dec(_Str_00,psVar4,ppsVar5,piVar6),
                       CONCAT31(extraout_var_02,bVar1) != 0)))))) goto LAB_c03aad10;
        if (((local_38 & 4) != 0) &&
           (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var_03,bVar1) != 0)) {
          sVar3 = wcslen(_Str);
          iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar3);
          if (iVar2 != 0) goto LAB_c03aad10;
        }
        bVar1 = FUN_c03afce8(_Str_00);
        if (CONCAT31(extraout_var_04,bVar1) != 0) {
          sVar3 = wcslen(_Str_00);
          iVar2 = FUN_c03ae6c8(DAT_c03c623c,_Str_00,sVar3);
          if (iVar2 != 0) goto LAB_c03aad10;
        }
        if (local_48 != 0) {
          (**(code **)(DAT_c03c623c + 0xc))(local_48);
        }
        dwErrCode = FUN_c03a9270(DAT_c03c623c,local_48,local_40,1,0x43,0,0x40,0xffffffff,0,0,0);
        if ((dwErrCode == 0) &&
           (dwErrCode = FUN_c03a9270(DAT_c03c623c,local_48,local_44,1,0x43,0x10000,0x42,0xffffffff,0
                                     ,0,0), dwErrCode == 0)) {
          SetLastError(0);
          uVar8 = AFS_PrestoChangoFileName(local_34,local_44,local_40);
          local_30 = uVar8;
        }
        else {
          SetLastError(dwErrCode);
        }
        if ((local_48 == 0) || ((**(code **)(DAT_c03c623c + 0x10))(), local_48 == 0))
        goto LAB_c03aad24;
        iVar2 = local_48;
        pcVar7 = *(code **)(DAT_c03c623c + 0x18);
      }
      else {
        iVar2 = 0x11;
      }
    }
  }
  (*pcVar7)(iVar2);
LAB_c03aad24:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str_00);
  return uVar8;
}



/* c03aad80 FUN_c03aad80 */

/* Boundary evidence: original MIPS .pdata c03aad80..c03aad8b. Semantic name remains unreviewed. */

undefined4 FUN_c03aad80(void)

{
  return 1;
}



/* c03aad8c FUN_c03aad8c */

/* Boundary evidence: original MIPS .pdata c03aad8c..c03ab087. Semantic name remains unreviewed. */

int FUN_c03aad8c(int param_1,int param_2,LPWIN32_FIND_DATAW param_3,int param_4)

{
  bool bVar1;
  STRSAFE_PCNZWCH _Str;
  wchar_t *_Str2;
  int iVar2;
  DWORD dwErrCode;
  undefined3 extraout_var;
  code *pcVar3;
  int iVar4;
  int local_40;
  int local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  STRSAFE_PCNZWCH local_2c;
  
  _Str = FUN_c03a8c48(param_1);
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return -1;
  }
  local_2c = _Str;
  _Str2 = wcsrchr(_Str,L'\\');
  if ((_Str2 != (wchar_t *)0x0) && (iVar2 = wcscmp(L"\\*.*",_Str2), iVar2 == 0)) {
    _Str2[2] = L'\0';
  }
  iVar4 = -1;
  local_3c = -1;
  iVar2 = FUN_c03af664(DAT_c03c623c,_Str,&local_34,&local_30,&local_38,&local_40);
  pcVar3 = SetLastError_exref;
  if (iVar2 == 0) {
    if (((local_38 & 0x100) == 0) || (iVar2 = __GetUserKData(0xc), iVar2 == param_2)) {
      if (local_40 != 0) {
        (**(code **)(DAT_c03c623c + 0xc))(local_40);
      }
      dwErrCode = FUN_c03a9270(DAT_c03c623c,local_40,local_34,1,0x43,0,1,0xffffffff,0,0,0);
      if (dwErrCode == 0) {
        if ((((local_38 & 1) == 0) &&
            (bVar1 = FUN_c03afce8(_Str), CONCAT31(extraout_var,bVar1) != 0)) ||
           (iVar2 = FUN_c03afc28(_Str), iVar2 != 0)) {
          iVar4 = FUN_c03b0c44(param_2,_Str,param_3,param_4);
          local_3c = iVar4;
        }
        if (iVar4 == -1) {
          SetLastError(0);
          iVar4 = AFS_FindFirstFileW(local_30,param_2,local_34,param_3,param_4);
          local_3c = iVar4;
        }
      }
      else {
        SetLastError(dwErrCode);
      }
      if ((local_40 == 0) || ((**(code **)(DAT_c03c623c + 0x10))(), local_40 == 0))
      goto LAB_c03ab03c;
      iVar2 = local_40;
      pcVar3 = *(code **)(DAT_c03c623c + 0x18);
    }
    else {
      iVar2 = 5;
      pcVar3 = SetLastError_exref;
    }
  }
  (*pcVar3)(iVar2);
LAB_c03ab03c:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return iVar4;
}



/* c03ab088 FUN_c03ab088 */

/* Boundary evidence: original MIPS .pdata c03ab088..c03ab093. Semantic name remains unreviewed. */

undefined4 FUN_c03ab088(void)

{
  return 1;
}



/* c03ab094 FSINT_FindFirstFileW */

/* Boundary evidence: original MIPS .pdata c03ab094..c03ab0e7. Semantic name remains unreviewed. */

void FSINT_FindFirstFileW(int param_1,LPWIN32_FIND_DATAW param_2,int param_3)

{
  int iVar1;
  
                    /* 0xb094  64  FSINT_FindFirstFileW */
  iVar1 = __GetUserKData(0xc);
  FUN_c03aad8c(param_1,iVar1,param_2,param_3);
  return;
}



/* c03ab0e8 FSEXT_FindFirstFileW */

/* Boundary evidence: original MIPS .pdata c03ab0e8..c03ab18f. Semantic name remains unreviewed. */

HANDLE FSEXT_FindFirstFileW(int param_1,LPWIN32_FIND_DATAW param_2,int param_3)

{
  int iVar1;
  HANDLE pvVar2;
  HANDLE pvVar3;
  HANDLE local_18 [2];
  
                    /* 0xb0e8  63  FSEXT_FindFirstFileW */
  iVar1 = GetCallerVMProcessId();
  local_18[0] = (HANDLE)FUN_c03aad8c(param_1,iVar1,param_2,param_3);
  if (local_18[0] != (HANDLE)0xffffffff) {
    pvVar2 = (HANDLE)__GetUserKData(0xc);
    pvVar3 = (HANDLE)GetCallerVMProcessId();
    iVar1 = FUN_c03acdac(pvVar2,local_18[0],pvVar3,local_18,0,0,3);
    if (iVar1 == 0) {
      return (HANDLE)0xffffffff;
    }
  }
  return local_18[0];
}



/* c03ab190 FUN_c03ab190 */

/* Boundary evidence: original MIPS .pdata c03ab190..c03ab873. Semantic name remains unreviewed. */

int FUN_c03ab190(STRSAFE_PCNZWCH param_1,int param_2,uint param_3,undefined4 param_4,
                undefined4 param_5,int param_6,uint param_7,undefined4 param_8)

{
  bool bVar1;
  bool bVar2;
  STRSAFE_PCNZWCH _Str;
  int iVar3;
  undefined3 extraout_var;
  size_t sVar4;
  DWORD DVar5;
  int iVar6;
  undefined3 extraout_var_00;
  uint uVar7;
  int iVar8;
  wchar_t *pwVar9;
  wchar_t **ppwVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int *piVar15;
  uint local_68;
  wchar_t *local_60;
  int local_5c;
  int local_58;
  int *local_54;
  undefined4 local_50;
  uint local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  STRSAFE_PCNZWCH local_2c;
  
  local_58 = param_2;
  local_50 = param_4;
  _Str = FUN_c03a8c48((int)param_1);
  if (_Str == (STRSAFE_PCNZWCH)0x0) {
    return -1;
  }
  local_2c = _Str;
  iVar3 = FUN_c03afe00(param_1);
  if (iVar3 != 0) {
    param_6 = 3;
  }
  bVar1 = FUN_c03afce8(_Str);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    local_54 = &DAT_c03c623c;
  }
  else {
    sVar4 = wcslen(_Str);
    local_54 = &DAT_c03c623c;
    iVar3 = FUN_c03ae6c8(DAT_c03c623c,_Str,sVar4);
    if ((iVar3 != 0) && (param_6 != 3)) {
      SetLastError(5);
      FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
      return -1;
    }
  }
  iVar3 = -1;
  local_48 = -1;
  bVar1 = false;
  local_44 = 0;
  local_3c = 0;
  puVar11 = &local_30;
  ppwVar10 = &local_60;
  DVar5 = FUN_c03af664(DAT_c03c623c,_Str,ppwVar10,puVar11,&local_4c,&local_5c);
  if (DVar5 == 0) {
    if (local_5c != 0) {
      (**(code **)(DAT_c03c623c + 0xc))();
    }
    local_40 = 0;
    if ((local_4c & 4) != 0) {
      local_40 = FUN_c03afc28(local_60);
    }
    iVar8 = local_40;
    DVar5 = 0;
    if (((local_4c & 0x100) != 0) && (iVar6 = __GetUserKData(0xc), iVar6 != local_58)) {
      DVar5 = 5;
    }
    local_68 = param_3;
    if (DVar5 == 0) {
      pwVar9 = local_60;
      local_3c = AFS_GetFileAttributesW(local_30);
      bVar2 = false;
      bVar1 = false;
      if ((iVar8 != 0) && (local_3c == -1)) {
        bVar2 = true;
        local_44 = 1;
        bVar1 = true;
      }
      local_38 = local_3c;
      if (((!bVar2) || (param_6 != 4)) ||
         (bVar2 = FUN_c03b0dec(local_60,pwVar9,ppwVar10,puVar11), piVar15 = local_54,
         CONCAT31(extraout_var_00,bVar2) == 0)) {
        if (((param_6 != 3) && (iVar8 != 0)) &&
           (uVar7 = FUN_c03b001c(_Str,pwVar9,ppwVar10,puVar11), uVar7 != 0xffffffff)) {
          param_7 = uVar7 & 4 | param_7;
        }
        piVar15 = local_54;
        if ((local_4c & 0x80) == 0) {
          param_3 = param_3 & 0xdfffffff;
        }
        if ((param_3 & 0x80000000) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0x120089;
        }
        if ((param_3 & 0x40000000) == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = 0x120116;
        }
        if ((param_3 & 0x20000000) == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = 0x1200a0;
        }
        uVar14 = 0;
        if ((local_38 == -1) && (((param_6 == 1 || (param_6 == 2)) || (param_6 == 4)))) {
          uVar14 = 2;
        }
        local_40 = 0;
        local_34 = 0;
        DVar5 = FUN_c03a9270(*local_54,local_5c,local_60,1,0x43,uVar13 | uVar12 | uVar7,uVar14,
                             param_7 & 0xffff,param_5,&local_40,&local_34);
        if (DVar5 == 0) {
          SetLastError(0);
          iVar3 = AFS_CreateFileW(local_30,local_58,local_60,param_3,local_50,0,param_6,param_7,
                                  param_8,local_40,local_34);
          local_48 = iVar3;
        }
        else {
          SetLastError(DVar5);
        }
        if (local_5c == 0) goto LAB_c03ab770;
        (**(code **)(*piVar15 + 0x1c))(local_5c,param_5,local_40);
        local_68 = param_3;
      }
    }
    else {
      SetLastError(DVar5);
      bVar1 = false;
      piVar15 = &DAT_c03c623c;
    }
    param_3 = local_68;
    if ((local_5c != 0) && ((**(code **)(*piVar15 + 0x10))(), local_5c != 0)) {
      (**(code **)(*piVar15 + 0x18))();
    }
  }
  else {
    SetLastError(DVar5);
    iVar8 = FUN_c03afc28(_Str);
    if (iVar8 != 0) {
      bVar1 = true;
    }
  }
LAB_c03ab770:
  if ((bVar1) && (iVar3 == -1)) {
    DVar5 = FUN_c03ac938(2);
    iVar3 = FUN_c03b0120(local_58,_Str,param_3,local_50,param_5,param_6,param_7,param_8);
    if (iVar3 == -1) {
      SetLastError(DVar5);
    }
  }
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)_Str);
  return iVar3;
}



/* c03ab874 FUN_c03ab874 */

/* Boundary evidence: original MIPS .pdata c03ab874..c03ab87f. Semantic name remains unreviewed. */

undefined4 FUN_c03ab874(void)

{
  return 1;
}



/* c03ab880 FUN_c03ab880 */

/* Boundary evidence: original MIPS .pdata c03ab880..c03ab88b. Semantic name remains unreviewed. */

undefined4 FUN_c03ab880(void)

{
  return 1;
}



/* c03ab88c FSINT_CreateFileW */

/* Boundary evidence: original MIPS .pdata c03ab88c..c03ab907. Semantic name remains unreviewed. */

void FSINT_CreateFileW(STRSAFE_PCNZWCH param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                      int param_5,uint param_6,undefined4 param_7)

{
  int iVar1;
  
                    /* 0xb88c  66  FSINT_CreateFileW */
  iVar1 = __GetUserKData(0xc);
  FUN_c03ab190(param_1,iVar1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* c03ab908 FSEXT_CreateFileW */

/* Boundary evidence: original MIPS .pdata c03ab908..c03aba13. Semantic name remains unreviewed. */

HANDLE FSEXT_CreateFileW(STRSAFE_PCNZWCH param_1,uint param_2,undefined4 param_3,int param_4,
                        int param_5,uint param_6,undefined4 param_7)

{
  int iVar1;
  HANDLE pvVar2;
  HANDLE pvVar3;
  undefined1 *puVar4;
  HANDLE local_30 [2];
  undefined1 auStack_28 [16];
  
                    /* 0xb908  65  FSEXT_CreateFileW */
  if (param_4 == 0) {
    puVar4 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_28,param_4,0xc);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return (HANDLE)0xffffffff;
    }
    puVar4 = auStack_28;
  }
  iVar1 = GetCallerVMProcessId();
  local_30[0] = (HANDLE)FUN_c03ab190(param_1,iVar1,param_2,param_3,puVar4,param_5,param_6,param_7);
  if (local_30[0] != (HANDLE)0xffffffff) {
    pvVar2 = (HANDLE)__GetUserKData(0xc);
    pvVar3 = (HANDLE)GetCallerVMProcessId();
    iVar1 = FUN_c03acdac(pvVar2,local_30[0],pvVar3,local_30,0,0,3);
    if (iVar1 == 0) {
      return (HANDLE)0xffffffff;
    }
  }
  return local_30[0];
}



/* c03aba14 STOREMGR_FsIoControlW */

/* Boundary evidence: original MIPS .pdata c03aba14..c03abc97. Semantic name remains unreviewed. */

undefined4
STOREMGR_FsIoControlW
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  STRSAFE_PCNZWCH pwVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  int local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  STRSAFE_PCNZWCH local_28;
  undefined4 uStack_24;
  
                    /* 0xba14  44  STOREMGR_FsIoControlW */
  pwVar1 = FUN_c03a8c48(param_2);
  uVar4 = 0;
  if (pwVar1 == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  local_34 = 0;
  local_28 = pwVar1;
  DVar2 = FUN_c03af664(DAT_c03c623c,pwVar1,&uStack_24,&local_2c,&local_30,&local_38);
  if (DVar2 == 0) {
    if (((local_30 & 0x100) == 0) || (iVar3 = __GetUserKData(0xc), iVar3 == param_1)) {
      if (local_38 != 0) {
        (**(code **)(DAT_c03c623c + 0xc))(local_38);
      }
      DVar2 = FUN_c03a9270(DAT_c03c623c,local_38,&DAT_c03a13c4,7,0x43,0x1f01ff,0,0xffffffff,0,0,0);
      if ((local_38 != 0) && ((**(code **)(DAT_c03c623c + 0x10))(), local_38 != 0)) {
        (**(code **)(DAT_c03c623c + 0x18))();
      }
      if (DVar2 == 0) {
        SetLastError(0);
        uVar4 = AFS_FsIoControlW(local_2c,param_1,param_3,param_4,param_5,param_6,param_7,param_8,
                                 param_9);
        local_34 = uVar4;
      }
      else {
        SetLastError(DVar2);
        uVar4 = 0;
      }
      goto LAB_c03abc50;
    }
    DVar2 = 5;
  }
  SetLastError(DVar2);
LAB_c03abc50:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar1);
  return uVar4;
}



/* c03abc98 FUN_c03abc98 */

/* Boundary evidence: original MIPS .pdata c03abc98..c03abca3. Semantic name remains unreviewed. */

undefined4 FUN_c03abc98(void)

{
  return 1;
}



/* c03abca4 FUN_c03abca4 */

/* Boundary evidence: original MIPS .pdata c03abca4..c03abebf. Semantic name remains unreviewed. */

undefined4 FUN_c03abca4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  STRSAFE_PCNZWCH pwVar1;
  int iVar2;
  DWORD dwErrCode;
  code *pcVar3;
  undefined4 uVar4;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  STRSAFE_PCNZWCH local_28;
  
  pwVar1 = FUN_c03a8c48(param_2);
  uVar4 = 0xffffffff;
  if (pwVar1 == (STRSAFE_PCNZWCH)0x0) {
    return 0xffffffff;
  }
  local_30 = 0xffffffff;
  local_28 = pwVar1;
  iVar2 = FUN_c03af664(DAT_c03c623c,pwVar1,&local_34,&local_2c,(undefined4 *)0x0,&local_38);
  pcVar3 = SetLastError_exref;
  if (iVar2 == 0) {
    if (local_38 != 0) {
      (**(code **)(DAT_c03c623c + 0xc))(local_38);
    }
    dwErrCode = FUN_c03a9270(DAT_c03c623c,local_38,local_34,7,0x43,0x120089,0,0xffffffff,0,0,0);
    if (dwErrCode == 0) {
      SetLastError(0);
      uVar4 = AFS_FindFirstChangeNotificationW(local_2c,param_1,local_34,param_3,param_4);
      local_30 = uVar4;
    }
    else {
      SetLastError(dwErrCode);
    }
    if ((local_38 == 0) || ((**(code **)(DAT_c03c623c + 0x10))(), local_38 == 0)) goto LAB_c03abe78;
    iVar2 = local_38;
    pcVar3 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar3)(iVar2);
LAB_c03abe78:
  FUN_c03a8bc4((uint *)&DAT_c03c5218,(uint *)pwVar1);
  return uVar4;
}



/* c03abec0 FUN_c03abec0 */

/* Boundary evidence: original MIPS .pdata c03abec0..c03abecb. Semantic name remains unreviewed. */

undefined4 FUN_c03abec0(void)

{
  return 1;
}



/* c03abecc FSEXT_FindFirstChangeNotificationW */

/* Boundary evidence: original MIPS .pdata c03abecc..c03abf1b. Semantic name remains unreviewed. */

void FSEXT_FindFirstChangeNotificationW(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
                    /* 0xbecc  69  FSEXT_FindFirstChangeNotificationW */
  uVar1 = GetCallerVMProcessId();
  FUN_c03abca4(uVar1,param_1,param_2,param_3);
  return;
}



/* c03abf1c FSINT_FindFirstChangeNotificationW */

/* Boundary evidence: original MIPS .pdata c03abf1c..c03abf6f. Semantic name remains unreviewed. */

void FSINT_FindFirstChangeNotificationW(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
                    /* 0xbf1c  68  FSINT_FindFirstChangeNotificationW */
  uVar1 = __GetUserKData(0xc);
  FUN_c03abca4(uVar1,param_1,param_2,param_3);
  return;
}



/* c03abf70 FSINT_GetFileSecurityW */

/* Boundary evidence: original MIPS .pdata c03abf70..c03ac0a7. Semantic name remains unreviewed. */

undefined4
FSINT_GetFileSecurityW
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  STRSAFE_PCNZWCH pwVar1;
  DWORD DVar2;
  code *pcVar3;
  DWORD dwErrCode;
  DWORD local_30;
  undefined4 local_2c;
  undefined4 auStack_28 [2];
  
                    /* 0xbf70  76  FSINT_GetFileSecurityW */
  pwVar1 = FUN_c03a8c48(param_1);
  if (pwVar1 == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  DVar2 = FUN_c03af664(DAT_c03c623c,pwVar1,&local_2c,auStack_28,(undefined4 *)0x0,(int *)&local_30);
  pcVar3 = SetLastError_exref;
  dwErrCode = DVar2;
  if (DVar2 == 0) {
    if (local_30 != 0) {
      (**(code **)(DAT_c03c623c + 0xc))();
    }
    dwErrCode = 0x32;
    if (((local_30 == 0) ||
        (dwErrCode = (**(code **)(DAT_c03c623c + 0x20))
                               (local_30,0x43,local_2c,param_2,param_3,param_4,param_5),
        local_30 == 0)) || ((**(code **)(DAT_c03c623c + 0x10))(), local_30 == 0)) goto LAB_c03ac06c;
    DVar2 = local_30;
    pcVar3 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar3)(DVar2);
LAB_c03ac06c:
  SetLastError(dwErrCode);
  if (dwErrCode != 0) {
    return 0;
  }
  return 1;
}



/* c03ac0a8 FSEXT_GetFileSecurityW */

/* Boundary evidence: original MIPS .pdata c03ac0a8..c03ac1c7. Semantic name remains unreviewed. */

undefined4
FSEXT_GetFileSecurityW(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  undefined4 *puVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0xc0a8  77  FSEXT_GetFileSecurityW */
  local_20 = 0;
  if ((param_3 == 0) || (iVar1 = CeAllocDuplicateBuffer(&local_20,param_3,param_4,8), -1 < iVar1)) {
    puVar3 = &local_1c;
    local_1c = 0;
    if (param_5 == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    uVar2 = FSINT_GetFileSecurityW(param_1,param_2,local_20,param_4,puVar3);
    if ((param_3 != 0) && (iVar1 = CeFreeDuplicateBuffer(local_20,param_3,param_4,8), iVar1 < 0)) {
      SetLastError(0x57);
      uVar2 = 0;
    }
    if (param_5 == 0) {
      return uVar2;
    }
    iVar1 = CeSafeCopyMemory(param_5,&local_1c,4);
    if (iVar1 != 0) {
      return uVar2;
    }
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = 8;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03ac1c8 FSINT_SetFileSecurityW */

/* Boundary evidence: original MIPS .pdata c03ac1c8..c03ac2f7. Semantic name remains unreviewed. */

undefined4
FSINT_SetFileSecurityW(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  STRSAFE_PCNZWCH pwVar1;
  DWORD DVar2;
  code *pcVar3;
  DWORD dwErrCode;
  DWORD local_30;
  undefined4 local_2c;
  undefined4 auStack_28 [2];
  
                    /* 0xc1c8  78  FSINT_SetFileSecurityW */
  pwVar1 = FUN_c03a8c48(param_1);
  if (pwVar1 == (STRSAFE_PCNZWCH)0x0) {
    return 0;
  }
  DVar2 = FUN_c03af664(DAT_c03c623c,pwVar1,&local_2c,auStack_28,(undefined4 *)0x0,(int *)&local_30);
  pcVar3 = SetLastError_exref;
  dwErrCode = DVar2;
  if (DVar2 == 0) {
    if (local_30 != 0) {
      (**(code **)(DAT_c03c623c + 0xc))();
    }
    dwErrCode = 0x32;
    if (((local_30 == 0) ||
        (dwErrCode = (**(code **)(DAT_c03c623c + 0x24))
                               (local_30,0x43,local_2c,param_2,param_3,param_4), local_30 == 0)) ||
       ((**(code **)(DAT_c03c623c + 0x10))(), local_30 == 0)) goto LAB_c03ac2bc;
    DVar2 = local_30;
    pcVar3 = *(code **)(DAT_c03c623c + 0x18);
  }
  (*pcVar3)(DVar2);
LAB_c03ac2bc:
  SetLastError(dwErrCode);
  if (dwErrCode != 0) {
    return 0;
  }
  return 1;
}



/* c03ac2f8 FSEXT_SetFileSecurityW */

/* Boundary evidence: original MIPS .pdata c03ac2f8..c03ac3a3. Semantic name remains unreviewed. */

undefined4
FSEXT_SetFileSecurityW(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
                    /* 0xc2f8  79  FSEXT_SetFileSecurityW */
  local_20[0] = 0;
  iVar1 = CeAllocDuplicateBuffer(local_20,param_3,param_4,4);
  if (iVar1 < 0) {
    SetLastError(8);
    uVar2 = 0;
  }
  else {
    uVar2 = FSINT_SetFileSecurityW(param_1,param_2,local_20[0],param_4);
    CeFreeDuplicateBuffer(local_20[0],param_3,param_4,4);
  }
  return uVar2;
}



/* c03ac3a4 FSEXT_CreateDirectoryW */

/* Boundary evidence: original MIPS .pdata c03ac3a4..c03ac407. Semantic name remains unreviewed. */

undefined4 FSEXT_CreateDirectoryW(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_18 [16];
  
                    /* 0xc3a4  54  FSEXT_CreateDirectoryW */
  if (param_2 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_18,param_2,0xc);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_18;
  }
  uVar2 = FSINT_CreateDirectoryW(param_1,puVar3);
  return uVar2;
}



/* c03ac408 FSEXT_RegisterAFSName */

/* Boundary evidence: original MIPS .pdata c03ac408..c03ac4bf. Semantic name remains unreviewed. */

uint FSEXT_RegisterAFSName(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  STRSAFE_PCNZWCH local_18;
  uint local_14;
  
                    /* 0xc408  52  FSEXT_RegisterAFSName */
  local_18 = (STRSAFE_PCNZWCH)0x0;
  if ((param_1 == 0) || (iVar1 = CeAllocDuplicateBuffer(&local_18,param_1,0,5), -1 < iVar1)) {
    local_14 = 0xffffffff;
    uVar2 = GetCallerVMProcessId();
    dwErrCode = FUN_c03af06c(DAT_c03c623c,local_18,&local_14,uVar2);
    if (local_18 != (STRSAFE_PCNZWCH)0x0) {
      CeFreeDuplicateBuffer(local_18,param_1,0,5);
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(0xe);
    local_14 = 0xffffffff;
  }
  return local_14;
}



/* c03ac4c0 FSEXT_DeregisterAFSName */

/* Boundary evidence: original MIPS .pdata c03ac4c0..c03ac517. Semantic name remains unreviewed. */

bool FSEXT_DeregisterAFSName(uint param_1)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0xc4c0  50  FSEXT_DeregisterAFSName */
  iVar1 = GetCallerVMProcessId();
  dwErrCode = FUN_c03af374(DAT_c03c623c,param_1,iVar1);
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03ac518 FS_ProcessCleanupVolumes */

/* Boundary evidence: original MIPS .pdata c03ac518..c03ac5f7. Semantic name remains unreviewed. */

void FS_ProcessCleanupVolumes(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
                    /* 0xc518  53  FS_ProcessCleanupVolumes */
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c03c623c + 0x48));
  iVar5 = *(int *)(DAT_c03c623c + 0x38);
  uVar3 = 0;
  iVar1 = DAT_c03c623c;
  if (-1 < iVar5) {
    iVar4 = 0x5c;
    do {
      if ((uVar3 == 0xffffffff) || (0xff < uVar3)) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = *(int **)(iVar4 + iVar1);
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 == param_1)) {
        FUN_c03af930(iVar1,uVar3,param_1,1);
        FUN_c03af374(DAT_c03c623c,uVar3,param_1);
        iVar1 = DAT_c03c623c;
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 4;
    } while ((int)uVar3 <= iVar5);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x48));
  return;
}



/* c03ac5f8 FSINT_RegisterAFSName */

/* Boundary evidence: original MIPS .pdata c03ac5f8..c03ac653. Semantic name remains unreviewed. */

uint FSINT_RegisterAFSName(STRSAFE_PCNZWCH param_1)

{
  undefined4 uVar1;
  DWORD dwErrCode;
  uint local_10 [2];
  
                    /* 0xc5f8  51  FSINT_RegisterAFSName */
  local_10[0] = 0xffffffff;
  uVar1 = __GetUserKData(0xc);
  dwErrCode = FUN_c03af06c(DAT_c03c623c,param_1,local_10,uVar1);
  SetLastError(dwErrCode);
  return local_10[0];
}



/* c03ac654 FSINT_RegisterAFSEx */

/* Boundary evidence: original MIPS .pdata c03ac654..c03ac6f7. Semantic name remains unreviewed. */

bool FSINT_RegisterAFSEx(uint param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5
                        )

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0xc654  45  FSINT_RegisterAFSEx */
  iVar1 = __GetUserKData(0xc);
  if (param_4 == 4) {
    dwErrCode = FUN_c03aea9c(DAT_c03c623c,param_1,param_2,param_3,iVar1,param_5);
  }
  else {
    dwErrCode = 0x57;
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03ac6f8 FSEXT_RegisterAFSEx */

/* Boundary evidence: original MIPS .pdata c03ac6f8..c03ac7e7. Semantic name remains unreviewed. */

undefined4
FSEXT_RegisterAFSEx(uint param_1,HANDLE param_2,undefined4 param_3,int param_4,uint param_5)

{
  HANDLE pvVar1;
  HANDLE pvVar2;
  int iVar3;
  DWORD dwErrCode;
  HANDLE local_res4 [3];
  
  local_res4[0] = param_2;
                    /* 0xc6f8  46  FSEXT_RegisterAFSEx */
  pvVar1 = (HANDLE)__GetUserKData(0xc);
  pvVar2 = (HANDLE)GetCallerVMProcessId();
  iVar3 = FUN_c03acdac(pvVar2,local_res4[0],pvVar1,local_res4,0,0,2);
  if (iVar3 != 0) {
    iVar3 = GetCallerVMProcessId();
    if (param_4 == 4) {
      dwErrCode = FUN_c03aea9c(DAT_c03c623c,param_1,local_res4[0],param_3,iVar3,param_5);
    }
    else {
      dwErrCode = 0x57;
    }
    CloseHandle(local_res4[0]);
    SetLastError(dwErrCode);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  return 0;
}



/* c03ac7e8 FSINT_DeregisterAFS */

/* Boundary evidence: original MIPS .pdata c03ac7e8..c03ac863. Semantic name remains unreviewed. */

bool FSINT_DeregisterAFS(uint param_1)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0xc7e8  47  FSINT_DeregisterAFS */
  iVar1 = __GetUserKData(0xc);
  if (((int)param_1 < 0) || (0xff < param_1)) {
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = FUN_c03af930(DAT_c03c623c,param_1,iVar1,0);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03ac864 FSEXT_DeregisterAFS */

/* Boundary evidence: original MIPS .pdata c03ac864..c03ac8db. Semantic name remains unreviewed. */

bool FSEXT_DeregisterAFS(uint param_1)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0xc864  48  FSEXT_DeregisterAFS */
  iVar1 = GetCallerVMProcessId();
  if (((int)param_1 < 0) || (0xff < param_1)) {
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = FUN_c03af930(DAT_c03c623c,param_1,iVar1,0);
  }
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03ac8dc FSINT_DeregisterAFSName */

/* Boundary evidence: original MIPS .pdata c03ac8dc..c03ac937. Semantic name remains unreviewed. */

bool FSINT_DeregisterAFSName(uint param_1)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0xc8dc  49  FSINT_DeregisterAFSName */
  iVar1 = __GetUserKData(0xc);
  dwErrCode = FUN_c03af374(DAT_c03c623c,param_1,iVar1);
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03ac938 FUN_c03ac938 */

/* Boundary evidence: original MIPS .pdata c03ac938..c03ac96f. Semantic name remains unreviewed. */

DWORD FUN_c03ac938(DWORD param_1)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (DVar1 == 0) {
    DVar1 = param_1;
  }
  return DVar1;
}



/* c03ac970 FUN_c03ac970 */

/* Boundary evidence: original MIPS .pdata c03ac970..c03aca3f. Semantic name remains unreviewed. */

undefined4 FUN_c03ac970(undefined4 *param_1,STRSAFE_PCNZWCH param_2,size_t param_3)

{
  HRESULT HVar1;
  STRSAFE_LPWSTR pszDest;
  uint uVar2;
  size_t local_18 [2];
  
  HVar1 = StringCchLengthW(param_2,param_3,local_18);
  if (-1 < HVar1) {
    if (local_18[0] + 1 < 0x80000000) {
      uVar2 = (local_18[0] + 1) * 2;
    }
    else {
      uVar2 = 0xffffffff;
    }
    pszDest = operator_new(uVar2);
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      return 8;
    }
    HVar1 = StringCchCopyNW(pszDest,local_18[0] + 1,param_2,local_18[0]);
    if (-1 < HVar1) {
      *param_1 = pszDest;
      return 0;
    }
    operator_delete(pszDest);
  }
  return 0x57;
}



/* c03aca40 FUN_c03aca40 */

/* Boundary evidence: original MIPS .pdata c03aca40..c03acafb. Semantic name remains unreviewed. */

undefined4 FUN_c03aca40(wchar_t *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  iVar1 = swscanf(param_1,L"{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",param_2,param_2 + 4
                  ,param_2 + 6,&local_28,auStack_24,auStack_20,auStack_1c,auStack_18,auStack_14,
                  auStack_10,auStack_c);
  if (iVar1 == 0xb) {
    uVar4 = 0;
    puVar5 = &local_28;
    do {
      puVar3 = (undefined1 *)(param_2 + 8 + uVar4);
      uVar4 = uVar4 + 1;
      *puVar3 = (char)*puVar5;
      puVar5 = puVar5 + 1;
    } while (uVar4 < 8);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03acafc FUN_c03acafc */

/* Boundary evidence: original MIPS .pdata c03acafc..c03acbc3. Semantic name remains unreviewed. */

undefined4 FUN_c03acafc(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  DWORD local_20;
  DWORD local_1c;
  
  local_20 = 4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_1c,(LPBYTE)0x0,&local_20);
  if (((LVar1 == 0) && (local_1c == 4)) &&
     (LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_1c,param_3,&local_20), LVar1 == 0
     )) {
    return 1;
  }
  param_3[0] = '\0';
  param_3[1] = '\0';
  param_3[2] = '\0';
  param_3[3] = '\0';
  return 0;
}



/* c03acbc4 FUN_c03acbc4 */

/* Boundary evidence: original MIPS .pdata c03acbc4..c03acccf. Semantic name remains unreviewed. */

undefined4 FUN_c03acbc4(HKEY param_1,LPCWSTR param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  DWORD local_28;
  DWORD local_24;
  
  local_28 = 0;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,(LPBYTE)0x0,&local_28);
  if (((LVar1 != 0) ||
      (((uVar2 = 1, local_24 != 1 && (local_24 != 7)) || (param_4 << 1 < local_28)))) ||
     (LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,(LPBYTE)param_3,&local_28),
     LVar1 != 0)) {
    StringCchCopyW(param_3,param_4,L"");
    uVar2 = 0;
  }
  return uVar2;
}



/* c03accd0 FUN_c03accd0 */

/* Boundary evidence: original MIPS .pdata c03accd0..c03accff. Semantic name remains unreviewed. */

void FUN_c03accd0(HKEY param_1,DWORD param_2,LPWSTR param_3,LPDWORD param_4)

{
  RegEnumKeyExW(param_1,param_2,param_3,param_4,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0
               );
  return;
}



/* c03acd00 FUN_c03acd00 */

/* Boundary evidence: original MIPS .pdata c03acd00..c03acd2b. Semantic name remains unreviewed. */

void FUN_c03acd00(HKEY param_1,LPCWSTR param_2,PHKEY param_3)

{
  RegOpenKeyExW(param_1,param_2,0,0,param_3);
  return;
}



/* c03acd2c FUN_c03acd2c */

/* Boundary evidence: original MIPS .pdata c03acd2c..c03acd63. Semantic name remains unreviewed. */

void FUN_c03acd2c(LPCWSTR param_1,PHKEY param_2)

{
  RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,param_2);
  return;
}



/* c03acd64 FUN_c03acd64 */

/* Boundary evidence: original MIPS .pdata c03acd64..c03acd87. Semantic name remains unreviewed. */

void FUN_c03acd64(HKEY param_1)

{
  RegCloseKey(param_1);
  return;
}



/* c03acd88 FUN_c03acd88 */

/* Boundary evidence: original MIPS .pdata c03acd88..c03acdab. Semantic name remains unreviewed. */

void FUN_c03acd88(void)

{
  GetProcAddressW();
  return;
}



/* c03acdac FUN_c03acdac */

/* Boundary evidence: original MIPS .pdata c03acdac..c03acde3. Semantic name remains unreviewed. */

void FUN_c03acdac(HANDLE param_1,HANDLE param_2,HANDLE param_3,LPHANDLE param_4,DWORD param_5,
                 BOOL param_6,DWORD param_7)

{
  DuplicateHandle(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* c03acde4 FUN_c03acde4 */

/* Boundary evidence: original MIPS .pdata c03acde4..c03ace57. Semantic name remains unreviewed. */

undefined4 FUN_c03acde4(HKEY param_1,LPCWSTR param_2,uint *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  iVar1 = FUN_c03acafc(param_1,param_2,(LPBYTE)local_18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if (local_18[0] == 1) {
      *param_3 = *param_3 | param_4;
    }
    else {
      *param_3 = ~param_4 & *param_3;
    }
  }
  return uVar2;
}



/* c03ace58 FUN_c03ace58 */

/* Boundary evidence: original MIPS .pdata c03ace58..c03acebf. Semantic name remains unreviewed. */

int FUN_c03ace58(int *param_1,uint param_2)

{
  int iVar1;
  
  if (param_1[0xf] == -1) {
    iVar1 = FUN_c03ae7dc(*param_1,param_2,param_1 + 0x10,param_1 + 10);
    if (iVar1 == 0) {
      param_1[0xf] = param_2;
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0xb7;
  }
  return iVar1;
}



/* c03acec0 FUN_c03acec0 */

/* Boundary evidence: original MIPS .pdata c03acec0..c03acf2f. Semantic name remains unreviewed. */

void FUN_c03acec0(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x44))(param_2);
  return;
}



/* c03acf30 FUN_c03acf30 */

/* Boundary evidence: original MIPS .pdata c03acf30..c03acf57. Semantic name remains unreviewed. */

undefined4 FUN_c03acf30(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03acf58 FUN_c03acf58 */

/* Boundary evidence: original MIPS .pdata c03acf58..c03acfc7. Semantic name remains unreviewed. */

void FUN_c03acf58(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x68))(param_2);
  return;
}



/* c03acfc8 FUN_c03acfc8 */

/* Boundary evidence: original MIPS .pdata c03acfc8..c03acfef. Semantic name remains unreviewed. */

undefined4 FUN_c03acfc8(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03acff0 FUN_c03acff0 */

/* Boundary evidence: original MIPS .pdata c03acff0..c03ad05f. Semantic name remains unreviewed. */

void FUN_c03acff0(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x7c))(param_2);
  return;
}



/* c03ad060 FUN_c03ad060 */

/* Boundary evidence: original MIPS .pdata c03ad060..c03ad087. Semantic name remains unreviewed. */

undefined4 FUN_c03ad060(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03ad088 FUN_c03ad088 */

/* Boundary evidence: original MIPS .pdata c03ad088..c03ad127. Semantic name remains unreviewed. */

void FUN_c03ad088(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  (**(code **)(param_1 + 0x84))
            (*(undefined4 *)(param_1 + 0xc),param_3,param_4,param_5,param_6,param_7,param_8,param_9,
             0);
  return;
}



/* c03ad128 FUN_c03ad128 */

/* Boundary evidence: original MIPS .pdata c03ad128..c03ad14f. Semantic name remains unreviewed. */

undefined4 FUN_c03ad128(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03ad150 FUN_c03ad150 */

/* Boundary evidence: original MIPS .pdata c03ad150..c03ad19f. Semantic name remains unreviewed. */

void FUN_c03ad150(int param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c);
    if (iVar2 == 0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c03bd33c(iVar2,param_2);
    }
    *(undefined4 **)(param_1 + 0x10) = puVar1;
  }
  return;
}



/* c03ad1a0 FUN_c03ad1a0 */

/* Boundary evidence: original MIPS .pdata c03ad1a0..c03ad23f. Semantic name remains unreviewed. */

int FUN_c03ad1a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_20 [8];
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar1 = __GetUserKData(0xc);
    iVar2 = LockAPIHandle(DAT_c03c6248,uVar1,param_3,auStack_20);
    *(int *)(param_1 + 0x14) = iVar2;
    if ((iVar2 != 0) && (iVar3 = CreateAPIHandle(param_2,param_1), iVar3 == 0)) {
      UnlockAPIHandle(DAT_c03c6248,*(undefined4 *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
  }
  return iVar3;
}



/* c03ad240 FUN_c03ad240 */

/* Boundary evidence: original MIPS .pdata c03ad240..c03ad2af. Semantic name remains unreviewed. */

undefined4 *
FUN_c03ad240(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = param_6;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = param_5;
  param_1[0xe] = 0;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return param_1;
}



/* c03ad2b0 FUN_c03ad2b0 */

/* Boundary evidence: original MIPS .pdata c03ad2b0..c03ad33b. Semantic name remains unreviewed. */

void FUN_c03ad2b0(int param_1)

{
  int iVar1;
  
  if (*(HANDLE *)(param_1 + 0x44) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x48) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    if (*(int *)(iVar1 + 0x14) != 0) {
      EventModify(*(int *)(iVar1 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c03ad33c FUN_c03ad33c */

/* Boundary evidence: original MIPS .pdata c03ad33c..c03ad44b. Semantic name remains unreviewed. */

DWORD FUN_c03ad33c(int *param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  if (param_1[0xf] == -1) {
    FUN_c03c216c(DAT_c03c531c);
    return 2;
  }
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  param_1[0x11] = (int)pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
    param_1[0x12] = (int)pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      if ((param_1[10] & 1U) != 0) {
LAB_c03ad41c:
        InterlockedExchangeAdd(param_1 + 0xe,3);
        FUN_c03c216c(local_18);
        return 0;
      }
      DVar2 = FUN_c03ae5f0(*param_1,param_1[0xf],awStack_220,0x104);
      if (DVar2 == 0) {
        puVar3 = FUN_c03bcd48(awStack_220);
        param_1[0xb] = (int)puVar3;
        goto LAB_c03ad41c;
      }
      goto LAB_c03ad3b0;
    }
  }
  DVar2 = FUN_c03ac938(0x1f);
LAB_c03ad3b0:
  FUN_c03c216c(local_18);
  return DVar2;
}



/* c03ad44c FUN_c03ad44c */

/* Boundary evidence: original MIPS .pdata c03ad44c..c03ad4ff. Semantic name remains unreviewed. */

undefined4 FUN_c03ad44c(int param_1)

{
  uint Comperand;
  uint uVar1;
  
  while( true ) {
    Comperand = InterlockedExchangeAdd((LONG *)(param_1 + 0x38),0);
    if ((Comperand & 1) == 0) {
      return 0x651;
    }
    if (((Comperand & 2) == 0) || ((Comperand & 4) != 0)) break;
    uVar1 = InterlockedCompareExchange((LONG *)(param_1 + 0x38),Comperand + 8,Comperand);
    if (Comperand == uVar1) {
      if (*(int **)(param_1 + 4) != (int *)0x0) {
        (**(code **)(**(int **)(param_1 + 4) + 8))();
      }
      return 0;
    }
  }
  return 0x10df;
}



/* c03ad500 FUN_c03ad500 */

/* Boundary evidence: original MIPS .pdata c03ad500..c03ad547. Semantic name remains unreviewed. */

void FUN_c03ad500(int param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedExchangeAdd((LONG *)(param_1 + 0x38),2);
  if ((LVar1 + 2U & 4) == 0) {
    EventModify(*(undefined4 *)(param_1 + 0x44),3);
  }
  return;
}



/* c03ad548 FUN_c03ad548 */

/* Boundary evidence: original MIPS .pdata c03ad548..c03ad5eb. Semantic name remains unreviewed. */

DWORD FUN_c03ad548(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_res4 [3];
  undefined1 auStack_20 [8];
  
  iVar4 = *(int *)(param_1 + 8);
  uVar3 = 4;
  if (param_3 == 0) {
    uVar3 = 0;
  }
  local_res4[0] = param_2;
  uVar1 = __GetUserKData(0xc);
  iVar4 = FUN_c03ad088(iVar4,uVar1,0x900ac,local_res4,4,param_3,uVar3,auStack_20,0);
  if (iVar4 == 0) {
    DVar2 = FUN_c03ac938(0x1f);
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



/* c03ad5ec FUN_c03ad5ec */

/* Boundary evidence: original MIPS .pdata c03ad5ec..c03ad657. Semantic name remains unreviewed. */

void FUN_c03ad5ec(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if (((*(uint *)(iVar1 + 0x1c) & 1) != 0) &&
       ((*(uint *)(iVar1 + 0x20) & 0x40000000) == 0x40000000)) {
      FUN_c03acf58(*(int *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc));
    }
  }
  return;
}



/* c03ad658 FUN_c03ad658 */

/* Boundary evidence: original MIPS .pdata c03ad658..c03ad6f7. Semantic name remains unreviewed. */

void FUN_c03ad658(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (iVar1 = *(int *)(param_1 + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if ((*(uint *)(iVar1 + 0x1c) & 1) == 0) {
      if ((*(uint *)(iVar1 + 0x1c) & 2) != 0) {
        FUN_c03acec0(*(int *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc));
      }
    }
    else {
      FUN_c03acff0(*(int *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc));
    }
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x80000000;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c03ad6f8 FUN_c03ad6f8 */

/* Boundary evidence: original MIPS .pdata c03ad6f8..c03ad93b. Semantic name remains unreviewed. */

DWORD FUN_c03ad6f8(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  DWORD DVar4;
  int *piVar5;
  code *pcVar6;
  int *piVar7;
  HKEY local_438 [2];
  wchar_t awStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  local_438[0] = (HKEY)0x0;
  piVar7 = (int *)0x0;
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c03a3724(puVar1,(LPCWSTR)0x0);
  }
  if (piVar2 == (int *)0x0) {
LAB_c03ad84c:
    DVar4 = 8;
  }
  else {
    StringCchPrintfW(awStack_430,0x104,L"%s\\Filters",PTR_u_System_StorageManager_c03c5264);
    FUN_c03b12dc((int)piVar2,awStack_430);
    iVar3 = _wcsicmp(awStack_430,param_2);
    if (iVar3 != 0) {
      FUN_c03b12dc((int)piVar2,param_2);
    }
    FUN_c03a345c((int)piVar2,param_3,0x104);
    StringCchPrintfW(awStack_430,0x104,L"%s\\%s",param_2,param_3);
    DVar4 = FUN_c03acd2c(awStack_430,local_438);
    if (DVar4 == 0) {
      iVar3 = FUN_c03acbc4(local_438[0],(LPCWSTR)PTR_DAT_c03c529c,awStack_228,0x104);
      if (iVar3 == 0) {
        DVar4 = 2;
      }
      else {
        puVar1 = operator_new(0xb8);
        if (puVar1 == (undefined4 *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = FUN_c03b2284(puVar1,piVar2,awStack_228);
        }
        if (piVar7 == (int *)0x0) goto LAB_c03ad84c;
        DVar4 = (**(code **)(*piVar7 + 4))(piVar7);
        if (DVar4 == 0) {
          piVar2[6] = param_1;
          if (piVar2[5] != 0) {
            EventModify(piVar2[5],2);
          }
          piVar5 = FUN_c03b2550(piVar7,*(int *)(param_1 + 8));
          if (piVar5 == (int *)0x0) {
            DVar4 = FUN_c03ac938(0x1f);
          }
          else {
            *(int **)(param_1 + 8) = piVar5;
            DVar4 = 0;
          }
        }
      }
    }
  }
  if (local_438[0] != (HKEY)0x0) {
    FUN_c03acd64(local_438[0]);
  }
  if (DVar4 != 0) {
    if (piVar7 == (int *)0x0) {
      if (piVar2 == (int *)0x0) goto LAB_c03ad910;
      pcVar6 = *(code **)*piVar2;
    }
    else {
      (**(code **)(*piVar7 + 8))(piVar7);
      pcVar6 = *(code **)*piVar7;
      piVar2 = piVar7;
    }
    (*pcVar6)(piVar2,1);
  }
LAB_c03ad910:
  FUN_c03c216c(local_20);
  return DVar4;
}



/* c03ad93c FUN_c03ad93c */

/* Boundary evidence: original MIPS .pdata c03ad93c..c03ad9ab. Semantic name remains unreviewed. */

int FUN_c03ad93c(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *local_10 [2];
  
  local_10[0] = (wchar_t *)0x0;
  iVar2 = FUN_c03b0e24(*(int *)(param_1 + 4),local_10);
  if (iVar2 == 0) {
    while (local_10[0] != (wchar_t *)0x0) {
      FUN_c03ad6f8(param_1,local_10[0],local_10[0] + 0x104);
      pwVar1 = local_10[0];
      local_10[0] = *(wchar_t **)(local_10[0] + 0x20a);
      operator_delete(pwVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



/* c03ad9ac FUN_c03ad9ac */

/* Boundary evidence: original MIPS .pdata c03ad9ac..c03ada3b. Semantic name remains unreviewed. */

void FUN_c03ad9ac(int param_1,int *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (*param_2 == 0) {
    *(int *)(param_1 + 0x20) = param_2[1];
  }
  else {
    *(int *)(*param_2 + 4) = param_2[1];
  }
  if ((int *)param_2[1] != (int *)0x0) {
    *(int *)param_2[1] = *param_2;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  *param_2 = 0;
  param_2[1] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c03ada3c FUN_c03ada3c */

/* Boundary evidence: original MIPS .pdata c03ada3c..c03adaeb. Semantic name remains unreviewed. */

void FUN_c03ada3c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  EventModify(*(undefined4 *)(param_1 + 0x44),3);
  FUN_c03ad658(param_1);
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    FUN_c03be8b8(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x18) = 0;
    if (*(int *)(iVar2 + 0x14) != 0) {
      EventModify(*(int *)(iVar2 + 0x14),3);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80000000;
  return;
}



/* c03adaec FUN_c03adaec */

/* Boundary evidence: original MIPS .pdata c03adaec..c03adb87. Semantic name remains unreviewed. */

uint FUN_c03adaec(int param_1,uint param_2)

{
  DWORD DVar1;
  
  if ((param_2 & 0xfffffff8) != 0) {
    do {
      DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0x48),*(DWORD *)(param_1 + 0x34));
      EventModify(*(undefined4 *)(param_1 + 0x48),2);
      param_2 = InterlockedExchangeAdd((LONG *)(param_1 + 0x38),0);
      if (DVar1 == 0x102) {
        return param_2;
      }
    } while ((param_2 & 0xfffffff8) != 0);
  }
  return param_2;
}



/* c03adb88 FUN_c03adb88 */

/* Boundary evidence: original MIPS .pdata c03adb88..c03adbef. Semantic name remains unreviewed. */

void FUN_c03adb88(int param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  piVar1 = *(int **)(param_1 + 0x20);
  *(int **)(param_2 + 4) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
  }
  *(int *)(param_1 + 0x20) = param_2;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c03adbf0 FUN_c03adbf0 */

/* Boundary evidence: original MIPS .pdata c03adbf0..c03adc53. Semantic name remains unreviewed. */

undefined4 *
FUN_c03adbf0(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_3;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_2;
  param_1[7] = param_5;
  param_1[8] = param_6;
  if (param_2 != 0) {
    FUN_c03adb88(param_2,(int)param_1);
  }
  return param_1;
}



/* c03adc54 FUN_c03adc54 */

/* Boundary evidence: original MIPS .pdata c03adc54..c03adcb7. Semantic name remains unreviewed. */

void FUN_c03adc54(int *param_1)

{
  param_1[7] = param_1[7] | 0x80000000;
  param_1[4] = 0;
  if (param_1[6] != 0) {
    FUN_c03ad9ac(param_1[6],param_1);
    param_1[6] = 0;
  }
  if (param_1[5] != 0) {
    UnlockAPIHandle(DAT_c03c6248);
    param_1[5] = 0;
  }
  return;
}



/* c03adcb8 FUN_c03adcb8 */

/* Boundary evidence: original MIPS .pdata c03adcb8..c03adeab. Semantic name remains unreviewed. */

int FUN_c03adcb8(int *param_1)

{
  int iVar1;
  int local_38;
  undefined4 local_34;
  undefined4 local_30 [2];
  
  if ((param_1[10] & 4U) != 0) {
    local_38 = 0;
    iVar1 = FUN_c03af5a8(*param_1,param_1[0xf],&local_38);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_38 != 0) {
      (**(code **)(*param_1 + 0xc))();
    }
    iVar1 = AFS_GetFileAttributesW(param_1[0x10],PTR_u_Windows_c03c5308);
    if (iVar1 == -1) {
      local_30[0] = 0;
      local_34 = 0;
      iVar1 = FUN_c03a9270(*param_1,local_38,PTR_u_Windows_c03c5308,7,2,0,4,0x10,0,local_30,
                           &local_34);
      if (iVar1 == 0) {
        AFS_CreateDirectoryW(param_1[0x10],PTR_u_Windows_c03c5308,0,local_30[0],local_34);
      }
    }
    iVar1 = AFS_GetFileAttributesW(param_1[0x10],L"\\Temp");
    if (iVar1 == -1) {
      local_34 = 0;
      local_30[0] = 0;
      iVar1 = FUN_c03a9270(*param_1,local_38,L"\\Temp",7,2,0,4,0x10,0,&local_34,local_30);
      if (iVar1 == 0) {
        AFS_CreateDirectoryW(param_1[0x10],L"\\Temp",0,local_34,local_30[0]);
      }
    }
    if (local_38 != 0) {
      (**(code **)(*param_1 + 0x10))();
    }
    if (local_38 != 0) {
      (**(code **)(*param_1 + 0x18))();
    }
  }
  return 0;
}



/* c03adeac FUN_c03adeac */

/* Boundary evidence: original MIPS .pdata c03adeac..c03adfe7. Semantic name remains unreviewed. */

int FUN_c03adeac(int *param_1)

{
  int iVar1;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  if (param_1[0xf] == 0xffffffff) {
    param_1[0xc] = param_1[0xc] | 4;
  }
  else {
    iVar1 = FUN_c03ae5f0(*param_1,param_1[0xf],awStack_220,0x104);
    if ((iVar1 != 0) || (iVar1 = FUN_c03adcb8(param_1), iVar1 != 0)) {
      FUN_c03c216c(local_18);
      return iVar1;
    }
    FUN_c03ae8a4(*param_1,param_1[0xf],param_1[0xb]);
    if ((param_1[10] & 1U) == 0) {
      FSDMGR_AdvertiseInterface(&DAT_c03a1e68,awStack_220,1);
    }
    if ((param_1[10] & 2U) != 0) {
      FSDMGR_AdvertiseInterface(&DAT_c03a1e78,awStack_220,1);
    }
    if ((param_1[10] & 0x10U) != 0) {
      FSDMGR_AdvertiseInterface(&DAT_c03a1e98,awStack_220,1);
    }
    if ((param_1[10] & 4U) != 0) {
      FSDMGR_AdvertiseInterface(&DAT_c03a1e88,awStack_220,1);
    }
  }
  FUN_c03c216c(local_18);
  return 0;
}



/* c03adfe8 FUN_c03adfe8 */

/* Boundary evidence: original MIPS .pdata c03adfe8..c03ae02b. Semantic name remains unreviewed. */

void FUN_c03adfe8(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_c03a4b9c(param_1,4);
  if ((uVar1 & 2) != 0) {
    EventModify(*(undefined4 *)(param_1 + 0x44),3);
  }
  return;
}



/* c03ae02c FUN_c03ae02c */

/* Boundary evidence: original MIPS .pdata c03ae02c..c03ae083. Semantic name remains unreviewed. */

void FUN_c03ae02c(int param_1)

{
  LONG LVar1;
  
  EventModify(*(undefined4 *)(param_1 + 0x44),2);
  EventModify(*(undefined4 *)(param_1 + 0x48),2);
  LVar1 = InterlockedExchangeAdd((LONG *)(param_1 + 0x38),4);
  FUN_c03adaec(param_1,LVar1 + 4);
  FUN_c03ad5ec(param_1);
  return;
}



/* c03ae084 FUN_c03ae084 */

/* Boundary evidence: original MIPS .pdata c03ae084..c03ae0bb. Semantic name remains unreviewed. */

void FUN_c03ae084(int param_1)

{
  FUN_c03a4b9c(param_1,2);
  EventModify(*(undefined4 *)(param_1 + 0x44),2);
  return;
}



/* c03ae0bc FUN_c03ae0bc */

/* Boundary evidence: original MIPS .pdata c03ae0bc..c03ae1c3. Semantic name remains unreviewed. */

undefined4 FUN_c03ae0bc(int *param_1)

{
  int iVar1;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  if (param_1[0xf] != 0xffffffff) {
    iVar1 = FUN_c03ae5f0(*param_1,param_1[0xf],awStack_220,0x104);
    param_1[0xf] = -1;
    param_1[0xc] = param_1[0xc] | 2;
    if (iVar1 == 0) {
      if ((param_1[10] & 1U) == 0) {
        FSDMGR_AdvertiseInterface(&DAT_c03a1e68,awStack_220,0);
      }
      if ((param_1[10] & 2U) != 0) {
        FSDMGR_AdvertiseInterface(&DAT_c03a1e78,awStack_220,0);
      }
      if ((param_1[10] & 0x10U) != 0) {
        FSDMGR_AdvertiseInterface(&DAT_c03a1e98,awStack_220,0);
      }
      if ((param_1[10] & 4U) != 0) {
        FSDMGR_AdvertiseInterface(&DAT_c03a1e88,awStack_220,0);
      }
    }
    FUN_c03a4b9c((int)param_1,1);
  }
  FUN_c03c216c(local_18);
  return 0;
}



/* c03ae1c4 FUN_c03ae1c4 */

/* Boundary evidence: original MIPS .pdata c03ae1c4..c03ae2cf. Semantic name remains unreviewed. */

int FUN_c03ae1c4(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,wchar_t *param_5,
                undefined4 param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = -1;
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c03adbf0(puVar1,param_1,param_4,param_2,param_3,param_6);
  }
  if (piVar2 != (int *)0x0) {
    iVar3 = FUN_c03ad1a0((int)piVar2,DAT_c03c624c,*(undefined4 *)(param_1 + 0x40));
    if (iVar3 == 0) {
      FUN_c03adc54(piVar2);
      operator_delete(piVar2);
      iVar3 = -1;
    }
    else if (((param_3 & 0x40000000) == 0) && ((param_3 & 0x20000000) == 0)) {
      FUN_c03ad150((int)piVar2,param_5);
    }
  }
  return iVar3;
}



/* c03ae2d0 FUN_c03ae2d0 */

/* Boundary evidence: original MIPS .pdata c03ae2d0..c03ae39b. Semantic name remains unreviewed. */

int FUN_c03ae2d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = -1;
  puVar1 = operator_new(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c03adbf0(puVar1,param_1,param_3,param_2,2,0);
  }
  if ((piVar2 != (int *)0x0) &&
     (iVar3 = FUN_c03ad1a0((int)piVar2,DAT_c03c6244,*(undefined4 *)(param_1 + 0x40)), iVar3 == 0)) {
    FUN_c03adc54(piVar2);
    operator_delete(piVar2);
    iVar3 = -1;
  }
  return iVar3;
}



/* c03ae39c FUN_c03ae39c */

undefined4 FUN_c03ae39c(ushort *param_1,uint param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if ((param_2 < 0x104) && (param_2 != 0)) {
    do {
      uVar1 = *param_1;
      param_2 = param_2 - 1;
      if (((uVar1 < 0x20) ||
          ((((uVar1 == 0x2a || (uVar1 == 0x5c)) || (uVar1 == 0x2f)) ||
           ((uVar1 == 0x3f || (uVar1 == 0x3e)))))) ||
         ((uVar1 == 0x3c || (((uVar1 == 0x3a || (uVar1 == 0x22)) || (uVar1 == 0x7c))))))
      goto LAB_c03ae440;
      param_1 = param_1 + 1;
    } while (param_2 != 0);
    uVar2 = 1;
  }
  else {
LAB_c03ae440:
    uVar2 = 0;
  }
  return uVar2;
}



/* c03ae44c FUN_c03ae44c */

/* Boundary evidence: original MIPS .pdata c03ae44c..c03ae55b. Semantic name remains unreviewed. */

void FUN_c03ae44c(undefined4 param_1,HKEY param_2,uint *param_3)

{
  int iVar1;
  uint local_18 [2];
  
  local_18[0] = 0;
  iVar1 = FUN_c03acafc(param_2,(LPCWSTR)PTR_u_MountFlags_c03c52b8,(LPBYTE)local_18);
  if (iVar1 == 0) {
    local_18[0] = *param_3;
  }
  else {
    *param_3 = local_18[0];
  }
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountAsBootable_c03c52e0,local_18,2);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountAsROM_c03c52e4,local_18,0x10);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountHidden_c03c52dc,local_18,1);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountAsRoot_c03c52d8,local_18,4);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountSystem_c03c52e8,local_18,0x20);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountPermanent_c03c52ec,local_18,0x40);
  FUN_c03acde4(param_2,(LPCWSTR)PTR_u_MountAsNetwork_c03c52f0,local_18,0x80);
  *param_3 = local_18[0];
  return;
}



/* c03ae55c FUN_c03ae55c */

/* Boundary evidence: original MIPS .pdata c03ae55c..c03ae5ef. Semantic name remains unreviewed. */

undefined4 * FUN_c03ae55c(undefined4 *param_1)

{
  param_1[0xb] = 0xffffffff;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 0xffffffff;
  param_1[0xe] = 0xffffffff;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = DAT_c03c5390;
  param_1[0x117] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x12));
  memset(param_1 + 0x17,0,0x400);
  return param_1;
}



/* c03ae5f0 FUN_c03ae5f0 */

/* Boundary evidence: original MIPS .pdata c03ae5f0..c03ae6c7. Semantic name remains unreviewed. */

undefined4 FUN_c03ae5f0(int param_1,uint param_2,STRSAFE_LPWSTR param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((int)param_2 < 0) || (0xff < param_2)) {
    uVar3 = 0x585;
  }
  else {
    uVar3 = 2;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    piVar2 = (int *)((param_2 + 0x17) * 4 + param_1);
    iVar1 = *piVar2;
    if (iVar1 != 0) {
      if (*(uint *)(iVar1 + 0x14) < param_4) {
        iVar1 = *piVar2;
        StringCchCopyNW(param_3,param_4,(STRSAFE_PCNZWCH)(iVar1 + 0x18),*(size_t *)(iVar1 + 0x14));
        uVar3 = 0;
      }
      else {
        uVar3 = 0x7a;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  }
  return uVar3;
}



/* c03ae6c8 FUN_c03ae6c8 */

/* Boundary evidence: original MIPS .pdata c03ae6c8..c03ae7db. Semantic name remains unreviewed. */

undefined4 FUN_c03ae6c8(int param_1,wchar_t *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*param_2 == L'\\') {
    param_2 = param_2 + 1;
    param_3 = param_3 - 1;
  }
  if ((param_3 == 7) && (iVar1 = _wcsnicmp((wchar_t *)PTR_u_Windows_c03c530c,param_2,7), iVar1 == 0)
     ) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    iVar1 = 0;
    if (-1 < *(int *)(param_1 + 0x38)) {
      piVar4 = (int *)(param_1 + 0x5c);
      do {
        iVar2 = *piVar4;
        if (iVar2 != 0) {
          if ((*(size_t *)(iVar2 + 0x14) == param_3) &&
             (iVar2 = _wcsnicmp((wchar_t *)(iVar2 + 0x18),param_2,*(size_t *)(iVar2 + 0x14)),
             iVar2 == 0)) {
            uVar3 = 1;
            break;
          }
        }
        iVar1 = iVar1 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar1 <= *(int *)(param_1 + 0x38));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  }
  return uVar3;
}



/* c03ae7dc FUN_c03ae7dc */

/* Boundary evidence: original MIPS .pdata c03ae7dc..c03ae8a3. Semantic name remains unreviewed. */

undefined4 FUN_c03ae7dc(int param_1,uint param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((int)param_2 < 0) || (0xff < param_2)) {
    uVar3 = 0x585;
  }
  else {
    uVar3 = 3;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    piVar2 = (int *)((param_2 + 0x17) * 4 + param_1);
    iVar1 = *piVar2;
    if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 4), iVar1 != 0)) {
      *param_3 = iVar1;
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(*piVar2 + 0x10);
      }
      uVar3 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  }
  return uVar3;
}



/* c03ae8a4 FUN_c03ae8a4 */

/* Boundary evidence: original MIPS .pdata c03ae8a4..c03aea8f. Semantic name remains unreviewed. */

undefined4 FUN_c03ae8a4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  wchar_t *local_254;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  uVar3 = 0;
  iVar4 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  piVar5 = (int *)((param_2 + 0x17) * 4 + param_1);
  iVar1 = *piVar5;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) == 0)) {
    uVar3 = 2;
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x10);
    StringCchCopyW(awStack_238,0x104,L"\\");
    iVar1 = *piVar5;
    StringCchCatNW(awStack_238,0x104,(STRSAFE_PCNZWCH)(iVar1 + 0x18),*(size_t *)(iVar1 + 0x14));
    iVar4 = *(int *)(param_1 + 0x40);
    if ((uVar2 & 4) != 0) {
      *(undefined4 *)(param_1 + 0x40) = param_3;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  if ((iVar4 != 0) && ((uVar2 & 1) == 0)) {
    if (*(code **)(param_1 + 0x45c) != (code *)0x0) {
      local_260 = 0x24;
      local_258 = 0x2001;
      local_254 = awStack_238;
      local_25c = 0x100;
      local_24c = 0x10;
      if ((uVar2 & 0x40) == 0) {
        local_24c = 0x110;
      }
      local_248 = 0;
      local_244 = 0;
      local_240 = 0;
      (**(code **)(param_1 + 0x45c))(&local_260);
    }
    FUN_c03bdc64(iVar4,awStack_238,1,1);
  }
  FUN_c03c216c(local_30);
  return uVar3;
}



/* c03aea90 FUN_c03aea90 */

/* Boundary evidence: original MIPS .pdata c03aea90..c03aea9b. Semantic name remains unreviewed. */

undefined4 FUN_c03aea90(void)

{
  return 1;
}



/* c03aea9c FUN_c03aea9c */

/* Boundary evidence: original MIPS .pdata c03aea9c..c03aee13. Semantic name remains unreviewed. */

DWORD FUN_c03aea9c(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  uint param_6)

{
  int *piVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  HANDLE hObject;
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  if (((int)param_2 < 0) || (0xff < param_2)) {
    FUN_c03c216c(DAT_c03c531c);
    return 0x585;
  }
  hObject = (HANDLE)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x12));
  piVar4 = param_1 + param_2 + 0x17;
  piVar1 = (int *)*piVar4;
  if (piVar1 == (int *)0x0) {
    DVar3 = 2;
    goto LAB_c03aed78;
  }
  if (piVar1[1] != 0) {
    DVar3 = 0xb7;
    goto LAB_c03aed78;
  }
  if (*piVar1 != param_5) {
    DVar3 = 5;
    goto LAB_c03aed78;
  }
  if (param_6 != (param_6 & 0x1ff)) {
    param_6 = param_6 & 0x1ff;
  }
  if ((param_2 == 1) && (param_1[0xb] == -1)) {
    param_6 = param_6 | 0x80;
  }
  if (((param_6 & 4) != 0) && (param_1[0xc] != -1)) {
    param_6 = param_6 & 0xfffffffb;
  }
  if ((param_6 & 4) != 0) {
    param_6 = param_6 & 0xffffffee;
  }
  if (((param_6 & 2) != 0) && (param_1[0xd] != -1)) {
    param_6 = param_6 & 0xfffffffd;
  }
  if (((param_6 & 0x80) != 0) && (param_1[0xb] != -1)) {
    param_6 = param_6 & 0xffffff7f;
  }
  if ((param_6 & 8) != 0) {
    param_6 = param_6 & 0xfffffff7;
  }
  hObject = (HANDLE)CreateAPIHandle(param_3,param_4);
  if (hObject == (HANDLE)0x0) {
    DVar3 = FUN_c03ac938(0x1f);
LAB_c03aece4:
    if (DVar3 != 0) goto LAB_c03aed78;
  }
  else {
    *(uint *)(*piVar4 + 0x10) = param_6;
    *(HANDLE *)(*piVar4 + 4) = hObject;
    *(undefined4 *)(*piVar4 + 0xc) = param_4;
    if ((param_6 & 4) != 0) {
      param_1[0xc] = param_2;
      *(undefined4 *)(*piVar4 + 0x14) = 0;
      *(undefined2 *)(*piVar4 + 0x18) = 0;
    }
    DVar3 = 0;
    *(undefined4 *)(*piVar4 + 8) = 0;
    iVar2 = *piVar4;
    if ((*param_1 != 0) && ((code *)param_1[1] != (code *)0x0)) {
      DVar3 = (*(code *)param_1[1])
                        (*(undefined4 *)(iVar2 + 4),iVar2 + 0x18,*(undefined4 *)(iVar2 + 0x10),
                         iVar2 + 8);
    }
    if (DVar3 != 0) {
      *(undefined4 *)(*piVar4 + 0x10) = 0;
      *(undefined4 *)(*piVar4 + 0xc) = 0;
      *(undefined4 *)(*piVar4 + 4) = 0;
      *(undefined4 *)(*piVar4 + 8) = 0;
      goto LAB_c03aece4;
    }
  }
  if (((param_6 & 1) == 0) && (param_1[0x10] != 0)) {
    local_238[0] = L'\\';
    StringCchCatNW(local_238,0x104,(STRSAFE_PCNZWCH)(*piVar4 + 0x18),*(size_t *)(*piVar4 + 0x14));
  }
  if ((param_6 & 2) != 0) {
    param_1[0xd] = param_2;
  }
  if ((param_6 & 0x80) != 0) {
    param_1[0xb] = param_2;
  }
  if (((param_6 & 0x10) != 0) && (piVar1 = operator_new(8), piVar1 != (int *)0x0)) {
    piVar1[1] = *(int *)(*piVar4 + 4);
    *piVar1 = param_1[0xf];
    param_1[0xf] = (int)piVar1;
  }
LAB_c03aed78:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x12));
  if ((hObject != (HANDLE)0x0) && (DVar3 != 0)) {
    CloseHandle(hObject);
    hObject = (HANDLE)0x0;
  }
  if ((param_1[0x117] != 0) && (hObject != (HANDLE)0x0)) {
    AFS_RegisterFileSystemFunction(hObject);
  }
  FUN_c03c216c(local_30);
  return DVar3;
}



/* c03aee14 FUN_c03aee14 */

/* Boundary evidence: original MIPS .pdata c03aee14..c03af05f. Semantic name remains unreviewed. */

int FUN_c03aee14(int param_1,STRSAFE_PCNZWCH param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  uint local_30;
  int local_2c;
  int local_28 [2];
  
  if (((int)param_3 < 0) || (bVar1 = true, 0xff < param_3)) {
    bVar1 = false;
  }
  if (((bVar1) && (HVar2 = StringCchLengthW(param_2,0x104,&local_30), -1 < HVar2)) &&
     (iVar3 = FUN_c03ae39c((ushort *)param_2,local_30), iVar3 != 0)) {
    iVar6 = -1;
    local_2c = -1;
    iVar3 = FUN_c03ae7dc(param_1,*(uint *)(param_1 + 0x30),local_28,(undefined4 *)0x0);
    if (iVar3 == 0) {
      iVar6 = AFS_GetFileAttributesW(local_28[0],param_2);
      local_2c = iVar6;
    }
    if (iVar6 == -1) {
      puVar4 = operator_new((local_30 + 0xe) * 2);
      if (puVar4 == (undefined4 *)0x0) {
        iVar3 = 8;
      }
      else {
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = local_30;
        StringCchCopyNW((STRSAFE_LPWSTR)(puVar4 + 6),local_30 + 1,param_2,local_30);
        *puVar4 = param_4;
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
        piVar5 = (int *)((param_3 + 0x17) * 4 + param_1);
        if (*piVar5 == 0) {
          *piVar5 = (int)puVar4;
          iVar3 = 0;
        }
        else {
          iVar3 = 0x55;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
        if (iVar3 != 0) {
          operator_delete(puVar4);
        }
      }
    }
    else {
      iVar3 = 0xb7;
    }
  }
  else {
    iVar3 = 0x57;
  }
  return iVar3;
}



/* c03af060 FUN_c03af060 */

/* Boundary evidence: original MIPS .pdata c03af060..c03af06b. Semantic name remains unreviewed. */

undefined4 FUN_c03af060(void)

{
  return 1;
}



/* c03af06c FUN_c03af06c */

/* Boundary evidence: original MIPS .pdata c03af06c..c03af367. Semantic name remains unreviewed. */

undefined4 FUN_c03af06c(int param_1,STRSAFE_PCNZWCH param_2,uint *param_3,undefined4 param_4)

{
  bool bVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint local_38;
  int local_34;
  int *local_30;
  undefined4 local_2c;
  
  uVar9 = 0xffffffff;
  local_2c = 0xffffffff;
  HVar2 = StringCchLengthW(param_2,0x104,&local_38);
  if ((HVar2 < 0) || (iVar3 = FUN_c03ae39c((ushort *)param_2,local_38), iVar3 == 0)) {
    uVar7 = 0x57;
  }
  else {
    iVar5 = -1;
    local_34 = -1;
    iVar3 = FUN_c03ae7dc(param_1,*(uint *)(param_1 + 0x30),(int *)&local_30,(undefined4 *)0x0);
    if (iVar3 == 0) {
      iVar5 = AFS_GetFileAttributesW(local_30,param_2);
      local_34 = iVar5;
    }
    if (iVar5 == -1) {
      puVar4 = operator_new((local_38 + 0xe) * 2);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = local_38;
        StringCchCopyNW((STRSAFE_LPWSTR)(puVar4 + 6),local_38 + 1,param_2,local_38);
        *puVar4 = param_4;
        uVar7 = 0x4e0;
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
        uVar6 = 0xffffffff;
        uVar8 = 0;
        local_30 = (int *)(param_1 + 0x5c);
        do {
          iVar3 = *local_30;
          if (iVar3 == 0) {
            if ((uVar6 == 0xffffffff) && (1 < uVar8)) {
              uVar6 = uVar8;
            }
          }
          else {
            if (*(size_t *)(iVar3 + 0x14) == puVar4[5]) {
              iVar3 = _wcsnicmp((wchar_t *)(iVar3 + 0x18),(wchar_t *)(puVar4 + 6),
                                *(size_t *)(iVar3 + 0x14));
              bVar1 = true;
              if (iVar3 != 0) goto LAB_c03af288;
            }
            else {
LAB_c03af288:
              bVar1 = false;
            }
            if (bVar1) {
              uVar6 = 0xffffffff;
              uVar7 = 0xb7;
              uVar9 = uVar8;
              goto LAB_c03af2c4;
            }
          }
          uVar8 = uVar8 + 1;
          local_30 = local_30 + 1;
          if (0xff < uVar8) {
LAB_c03af2c4:
            if (uVar6 != 0xffffffff) {
              *(undefined4 **)((uVar6 + 0x17) * 4 + param_1) = puVar4;
              if (*(int *)(param_1 + 0x38) < (int)uVar6) {
                *(uint *)(param_1 + 0x38) = uVar6;
              }
              uVar7 = 0;
              uVar9 = uVar6;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
            if (uVar6 == 0xffffffff) {
              operator_delete(puVar4);
            }
            *param_3 = uVar9;
            return uVar7;
          }
        } while( true );
      }
      uVar7 = 8;
    }
    else {
      uVar7 = 0xb7;
    }
  }
  *param_3 = 0xffffffff;
  return uVar7;
}



/* c03af368 FUN_c03af368 */

/* Boundary evidence: original MIPS .pdata c03af368..c03af373. Semantic name remains unreviewed. */

undefined4 FUN_c03af368(void)

{
  return 1;
}



/* c03af374 FUN_c03af374 */

/* Boundary evidence: original MIPS .pdata c03af374..c03af4a7. Semantic name remains unreviewed. */

undefined4 FUN_c03af374(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (((int)param_2 < 0) || (0xff < param_2)) {
    return 0x585;
  }
  uVar3 = 0x585;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  puVar4 = (undefined4 *)((param_2 + 0x17) * 4 + param_1);
  piVar1 = (int *)*puVar4;
  if (piVar1 == (int *)0x0) goto LAB_c03af46c;
  if (piVar1[1] == 0) {
    if (piVar1 == (int *)0x0) goto LAB_c03af46c;
    if (*piVar1 == param_3) {
      if (piVar1 != (int *)0x0) {
        operator_delete(piVar1);
        *puVar4 = 0;
        if (param_2 == *(uint *)(param_1 + 0x38)) {
          iVar2 = *(int *)((*(uint *)(param_1 + 0x38) + 0x17) * 4 + param_1);
          while ((iVar2 == 0 && (iVar2 = *(int *)(param_1 + 0x38), -1 < iVar2))) {
            *(int *)(param_1 + 0x38) = iVar2 + -1;
            iVar2 = *(int *)((iVar2 + 0x16) * 4 + param_1);
          }
        }
        uVar3 = 0;
      }
      goto LAB_c03af46c;
    }
  }
  uVar3 = 5;
LAB_c03af46c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  return uVar3;
}



/* c03af4a8 FUN_c03af4a8 */

/* Boundary evidence: original MIPS .pdata c03af4a8..c03af59b. Semantic name remains unreviewed. */

void FUN_c03af4a8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  *(undefined4 *)(param_1 + 0x45c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  for (uVar2 = 0; (int)uVar2 <= *(int *)(param_1 + 0x38); uVar2 = uVar2 + 1) {
    iVar1 = FUN_c03ae7dc(param_1,uVar2,&local_1c,(undefined4 *)0x0);
    if (iVar1 == 0) {
      AFS_RegisterFileSystemFunction(local_1c,param_2);
    }
  }
  return;
}



/* c03af59c FUN_c03af59c */

/* Boundary evidence: original MIPS .pdata c03af59c..c03af5a7. Semantic name remains unreviewed. */

undefined4 FUN_c03af59c(void)

{
  return 1;
}



/* c03af5a8 FUN_c03af5a8 */

/* Boundary evidence: original MIPS .pdata c03af5a8..c03af663. Semantic name remains unreviewed. */

undefined4 FUN_c03af5a8(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (((int)param_2 < 0) || (0xff < param_2)) {
    uVar3 = 0x585;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    piVar2 = (int *)((param_2 + 0x17) * 4 + param_1);
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      uVar3 = 2;
    }
    else {
      if (*(int *)(iVar1 + 8) != 0) {
        (**(code **)(param_1 + 0x14))();
      }
      uVar3 = 0;
      *param_3 = *(undefined4 *)(*piVar2 + 8);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  }
  return uVar3;
}



/* c03af664 FUN_c03af664 */

/* Boundary evidence: original MIPS .pdata c03af664..c03af92f. Semantic name remains unreviewed. */

undefined4
FUN_c03af664(int param_1,wchar_t *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,int *param_6)

{
  wchar_t wVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  wchar_t *_Str2;
  int iVar5;
  int *piVar6;
  int iVar7;
  size_t sVar8;
  
  iVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  if ((*param_2 == L'\\') && (param_2[1] == L'\\')) {
    if (*(int *)(param_1 + 0x2c) == -1) {
      uVar3 = 0x4c6;
      goto LAB_c03af8d4;
    }
    *param_3 = param_2;
    *param_4 = *(undefined4 *)(*(int *)((*(int *)(param_1 + 0x2c) + 0x17) * 4 + param_1) + 4);
    iVar5 = *(int *)(*(int *)((*(int *)(param_1 + 0x2c) + 0x17) * 4 + param_1) + 8);
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(*(int *)((*(int *)(param_1 + 0x2c) + 0x17) * 4 + param_1) + 0x10);
    }
  }
  else {
    _Str2 = param_2;
    if (*param_2 == L'\\') {
      _Str2 = param_2 + 1;
    }
    wVar1 = *_Str2;
    pwVar4 = _Str2;
    while ((wVar1 != L'\0' && (wVar1 != L'\\'))) {
      pwVar4 = pwVar4 + 1;
      wVar1 = *pwVar4;
    }
    sVar8 = (int)pwVar4 - (int)_Str2 >> 1;
    if ((sVar8 != 0) && (iVar7 = 0, -1 < *(int *)(param_1 + 0x38))) {
      piVar6 = (int *)(param_1 + 0x5c);
      do {
        iVar2 = *piVar6;
        if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
          if ((*(size_t *)(iVar2 + 0x14) == sVar8) &&
             (iVar2 = _wcsnicmp((wchar_t *)(iVar2 + 0x18),_Str2,*(size_t *)(iVar2 + 0x14)),
             iVar2 == 0)) {
            if (*pwVar4 == L'\0') {
              *param_3 = PTR_DAT_c03c5310;
            }
            else {
              *param_3 = pwVar4;
            }
            piVar6 = (int *)((iVar7 + 0x17) * 4 + param_1);
            *param_4 = *(undefined4 *)(*piVar6 + 4);
            iVar7 = *piVar6;
            iVar5 = *(int *)(iVar7 + 8);
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = *(undefined4 *)(iVar7 + 0x10);
            }
            goto LAB_c03af8d0;
          }
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar7 <= *(int *)(param_1 + 0x38));
    }
    if (*(int *)(param_1 + 0x30) == -1) {
      uVar3 = 3;
      goto LAB_c03af8d4;
    }
    *param_3 = param_2;
    *param_4 = *(undefined4 *)(*(int *)((*(int *)(param_1 + 0x30) + 0x17) * 4 + param_1) + 4);
    iVar5 = *(int *)(*(int *)((*(int *)(param_1 + 0x30) + 0x17) * 4 + param_1) + 8);
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(*(int *)((*(int *)(param_1 + 0x30) + 0x17) * 4 + param_1) + 0x10);
    }
  }
LAB_c03af8d0:
  uVar3 = 0;
LAB_c03af8d4:
  if (param_6 != (int *)0x0) {
    if (iVar5 != 0) {
      (**(code **)(param_1 + 0x14))(iVar5);
    }
    *param_6 = iVar5;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
  return uVar3;
}



/* c03af930 FUN_c03af930 */

/* Boundary evidence: original MIPS .pdata c03af930..c03afc1b. Semantic name remains unreviewed. */

undefined4 FUN_c03af930(int param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  HANDLE hObject;
  int iVar6;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  wchar_t *local_254;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  if (((int)param_2 < 0) || (bVar1 = true, 0xff < param_2)) {
    bVar1 = false;
  }
  if (bVar1) {
    uVar3 = 0x585;
    iVar6 = 0;
    hObject = (HANDLE)0x0;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    piVar5 = (int *)((param_2 + 0x17) * 4 + param_1);
    piVar2 = (int *)*piVar5;
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      if ((*piVar2 == param_3) && ((param_4 != 0 || ((piVar2[4] & 0x40U) == 0)))) {
        uVar4 = *(uint *)(*piVar5 + 0x10);
        hObject = *(HANDLE *)(*piVar5 + 4);
        if ((uVar4 & 4) == 0) {
          if ((uVar4 & 1) == 0) {
            StringCchCopyNW(awStack_238,0x104,(STRSAFE_PCNZWCH)(*piVar5 + 0x18),
                            *(size_t *)(*piVar5 + 0x14));
            iVar6 = *(int *)(param_1 + 0x40);
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x40) = 0;
          *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
        }
        if ((uVar4 & 2) != 0) {
          *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
        }
        if ((uVar4 & 0x80) != 0) {
          *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
        }
        if ((uVar4 & 0x10) != 0) {
          for (piVar2 = *(int **)(param_1 + 0x3c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
            if ((HANDLE)piVar2[1] == hObject) {
              piVar2[1] = 0xffffffff;
              break;
            }
          }
        }
        if (*(int *)(*piVar5 + 8) != 0) {
          (**(code **)(param_1 + 8))();
        }
        *(undefined4 *)(*piVar5 + 4) = 0;
        *(undefined4 *)(*piVar5 + 8) = 0;
        *(undefined4 *)(*piVar5 + 0x10) = 0;
        *(undefined4 *)(*piVar5 + 0xc) = 0;
        uVar3 = 0;
      }
      else {
        uVar3 = 5;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x48));
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
    if (iVar6 != 0) {
      if (*(code **)(param_1 + 0x45c) != (code *)0x0) {
        local_260 = 0x24;
        local_258 = 0x2001;
        local_254 = awStack_238;
        local_25c = 0x80;
        (**(code **)(param_1 + 0x45c))(&local_260);
      }
      FUN_c03bdc64(iVar6,awStack_238,1,2);
    }
    FUN_c03c216c(local_30);
  }
  else {
    FUN_c03c216c(DAT_c03c531c);
    uVar3 = 0x585;
  }
  return uVar3;
}



/* c03afc1c FUN_c03afc1c */

/* Boundary evidence: original MIPS .pdata c03afc1c..c03afc27. Semantic name remains unreviewed. */

undefined4 FUN_c03afc1c(void)

{
  return 1;
}



/* c03afc28 FUN_c03afc28 */

/* Boundary evidence: original MIPS .pdata c03afc28..c03afce7. Semantic name remains unreviewed. */

undefined4 FUN_c03afc28(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  for (; (*param_1 == L'\\' || (*param_1 == L'/')); param_1 = param_1 + 1) {
  }
  sVar1 = wcslen(param_1);
  if ((7 < sVar1) &&
     (((iVar2 = _wcsnicmp(param_1,(wchar_t *)PTR_u_Windows_c03c5314,7), iVar2 == 0 &&
       ((param_1[7] == L'\\' || (param_1[7] == L'/')))) || (*param_1 == L'\0')))) {
    uVar3 = 1;
  }
  return uVar3;
}



/* c03afce8 FUN_c03afce8 */

bool FUN_c03afce8(short *param_1)

{
  short sVar1;
  
  for (; (*param_1 == 0x5c || (*param_1 == 0x2f)); param_1 = param_1 + 1) {
  }
  for (; ((sVar1 = *param_1, sVar1 != 0 && (sVar1 != 0x5c)) && (sVar1 != 0x2f));
      param_1 = param_1 + 1) {
  }
  return *param_1 == 0;
}



/* c03afd4c FUN_c03afd4c */

/* Boundary evidence: original MIPS .pdata c03afd4c..c03afda7. Semantic name remains unreviewed. */

undefined4 FUN_c03afd4c(wchar_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _wcsicmp(param_1,L"\\reg:");
  if ((iVar1 == 0) || (iVar1 = _wcsicmp(param_1,L"\\con"), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03afda8 FUN_c03afda8 */

/* Boundary evidence: original MIPS .pdata c03afda8..c03afdff. Semantic name remains unreviewed. */

undefined4 FUN_c03afda8(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  undefined4 uVar2;
  size_t local_10 [2];
  
  HVar1 = StringCchLengthW(param_1,0x104,local_10);
  if ((HVar1 < 0) || (uVar2 = 1, param_1[local_10[0] - 1] != L':')) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03afe00 FUN_c03afe00 */

/* Boundary evidence: original MIPS .pdata c03afe00..c03afe6f. Semantic name remains unreviewed. */

undefined4 FUN_c03afe00(STRSAFE_PCNZWCH param_1)

{
  HRESULT HVar1;
  undefined4 uVar2;
  size_t local_10 [2];
  
  if (*param_1 == L'\\') {
    param_1 = param_1 + 1;
  }
  HVar1 = StringCchLengthW(param_1,0x104,local_10);
  if (((HVar1 < 0) || (local_10[0] != 5)) || (uVar2 = 1, param_1[4] != L':')) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03afe70 FUN_c03afe70 */

/* Boundary evidence: original MIPS .pdata c03afe70..c03afebf. Semantic name remains unreviewed. */

undefined4 FUN_c03afe70(void *param_1)

{
  if (*(HANDLE *)((int)param_1 + 4) != (HANDLE)0xffffffff) {
    FindClose(*(HANDLE *)((int)param_1 + 4));
  }
  operator_delete(param_1);
  return 1;
}



/* c03afec0 FUN_c03afec0 */

/* Boundary evidence: original MIPS .pdata c03afec0..c03b001b. Semantic name remains unreviewed. */

undefined4 FUN_c03afec0(void)

{
  wchar_t wVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  HMODULE hModule;
  HRSRC hResInfo;
  wchar_t *pwVar4;
  short sVar5;
  uint uVar6;
  STRSAFE_PCNZWCH pwVar7;
  
  puVar2 = operator_new(0x460);
  if (puVar2 == (undefined4 *)0x0) {
    DAT_c03c623c = (undefined4 *)0x0;
  }
  else {
    DAT_c03c623c = FUN_c03ae55c(puVar2);
  }
  if (DAT_c03c623c == (undefined4 *)0x0) {
    uVar3 = 8;
  }
  else {
    DAT_c03c6238 = CreateAPISet(&DAT_c03a1f30,3,&PTR_FUN_c03a1ed8,&DAT_c03a1ee8);
    RegisterAPISet(DAT_c03c6238,0x80000008);
    hModule = LoadLibraryW(L"filesys.dll");
    if (hModule != (HMODULE)0x0) {
      hResInfo = FindResourceW(hModule,(LPCWSTR)0x1,(LPCWSTR)0x6);
      if ((hResInfo != (HRSRC)0x0) &&
         (pwVar4 = LoadResource(hModule,hResInfo), pwVar4 != (wchar_t *)0x0)) {
        wVar1 = *pwVar4;
        pwVar7 = pwVar4 + 1;
        sVar5 = 2;
        do {
          uVar6 = (uint)(ushort)wVar1;
          sVar5 = sVar5 + -1;
          wVar1 = pwVar7[uVar6];
          pwVar7 = pwVar7 + uVar6 + 1;
        } while (sVar5 != 0);
        uVar3 = __GetUserKData(0xc);
        FUN_c03aee14((int)DAT_c03c623c,pwVar7,1,uVar3);
      }
      FreeLibrary(hModule);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* c03b001c FUN_c03b001c */

/* Boundary evidence: original MIPS .pdata c03b001c..c03b0113. Semantic name remains unreviewed. */

void FUN_c03b001c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = -1;
  piVar1 = *(int **)(DAT_c03c623c + 0x3c);
  while ((piVar1 != (int *)0x0 && (iVar2 == -1))) {
    if (piVar1[1] != 0) {
      iVar2 = AFS_GetFileAttributesW(piVar1[1],param_1);
    }
    piVar1 = (int *)*piVar1;
  }
  return;
}



/* c03b0114 FUN_c03b0114 */

/* Boundary evidence: original MIPS .pdata c03b0114..c03b011f. Semantic name remains unreviewed. */

undefined4 FUN_c03b0114(void)

{
  return 1;
}



/* c03b0120 FUN_c03b0120 */

/* Boundary evidence: original MIPS .pdata c03b0120..c03b02b3. Semantic name remains unreviewed. */

int FUN_c03b0120(undefined4 param_1,STRSAFE_PCNZWCH param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_c03afda8(param_2);
  if (iVar1 == 0) {
    iVar1 = -1;
    piVar2 = *(int **)(DAT_c03c623c + 0x3c);
    while ((piVar2 != (int *)0x0 && (iVar1 == -1))) {
      if (piVar2[1] != 0) {
        iVar1 = AFS_CreateFileW(piVar2[1],param_1,param_2,param_3,param_4,param_5,param_6,param_7,
                                param_8,0,0);
      }
      piVar2 = (int *)*piVar2;
    }
  }
  else {
    SetLastError(5);
    iVar1 = -1;
  }
  return iVar1;
}



/* c03b02b4 FUN_c03b02b4 */

/* Boundary evidence: original MIPS .pdata c03b02b4..c03b02bf. Semantic name remains unreviewed. */

undefined4 FUN_c03b02b4(void)

{
  return 1;
}



/* c03b02c0 FUN_c03b02c0 */

/* Boundary evidence: original MIPS .pdata c03b02c0..c03b051f. Semantic name remains unreviewed. */

bool FUN_c03b02c0(STRSAFE_LPCWSTR param_1,int param_2)

{
  bool bVar1;
  HRESULT HVar2;
  int iVar3;
  int *piVar4;
  int local_230 [2];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  bVar1 = false;
  HVar2 = StringCchCopyW(awStack_228,0x104,L"\\");
  if ((((HVar2 < 0) ||
       (HVar2 = StringCchCatW(awStack_228,0x104,(STRSAFE_LPCWSTR)PTR_u_Windows_c03c5314), HVar2 < 0)
       ) || (HVar2 = StringCchCatW(awStack_228,0x104,L"\\"), HVar2 < 0)) ||
     (HVar2 = StringCchCatW(awStack_228,0x104,param_1), HVar2 < 0)) {
    FUN_c03c216c(local_20);
    bVar1 = false;
  }
  else {
    iVar3 = FUN_c03ae7dc(DAT_c03c623c,*(uint *)(DAT_c03c623c + 0x30),local_230,(undefined4 *)0x0);
    if (iVar3 == 0) {
      iVar3 = AFS_GetFileAttributesW(local_230[0],awStack_228);
      bVar1 = iVar3 != -1;
    }
    for (piVar4 = *(int **)(DAT_c03c623c + 0x3c);
        ((!bVar1 && (piVar4 != (int *)0x0)) && (piVar4 != (int *)param_2)); piVar4 = (int *)*piVar4)
    {
      local_230[0] = piVar4[1];
      if ((local_230[0] != 0) &&
         (iVar3 = AFS_GetFileAttributesW(local_230[0],awStack_228), iVar3 != -1)) {
        bVar1 = true;
      }
    }
    FUN_c03c216c(local_20);
  }
  return bVar1;
}



/* c03b0520 FUN_c03b0520 */

/* Boundary evidence: original MIPS .pdata c03b0520..c03b052b. Semantic name remains unreviewed. */

undefined4 FUN_c03b0520(void)

{
  return 1;
}



/* c03b052c FUN_c03b052c */

/* Boundary evidence: original MIPS .pdata c03b052c..c03b0537. Semantic name remains unreviewed. */

undefined4 FUN_c03b052c(void)

{
  return 1;
}



/* c03b0538 FUN_c03b0538 */

/* Boundary evidence: original MIPS .pdata c03b0538..c03b079f. Semantic name remains unreviewed. */

undefined4 FUN_c03b0538(int param_1,undefined4 param_2)

{
  bool bVar1;
  HRESULT HVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  BOOL BVar4;
  int iVar5;
  _WIN32_FIND_DATAW _Stack_468;
  uint local_30;
  
  local_30 = DAT_c03c531c;
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(DAT_c03c623c + 0x3c);
  }
LAB_c03b05c0:
  do {
    if (*(int *)(param_1 + 0xc) == 0) {
LAB_c03b074c:
      SetLastError(0x12);
      FUN_c03c216c(local_30);
      return 0;
    }
    if (*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) {
      HVar2 = StringCchCopyW(_Stack_468.cFileName + 0x102,0x104,(STRSAFE_LPCWSTR)(param_1 + 0x14));
      if (HVar2 < 0) {
        SetLastError(0xce);
        goto LAB_c03b074c;
      }
      uVar3 = __GetUserKData(0xc);
      iVar5 = (*(undefined4 **)(param_1 + 0xc))[1];
      if (iVar5 == 0) {
        *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 0xc);
        goto LAB_c03b05c0;
      }
      uVar3 = AFS_FindFirstFileW(iVar5,uVar3,_Stack_468.cFileName + 0x102,&_Stack_468,0x230);
      *(undefined4 *)(param_1 + 4) = uVar3;
      if (*(int *)(param_1 + 4) == -1) {
        *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 0xc);
        goto LAB_c03b05c0;
      }
    }
    else {
      BVar4 = FindNextFileW(*(HANDLE *)(param_1 + 4),&_Stack_468);
      if (BVar4 == 0) {
        FindClose(*(HANDLE *)(param_1 + 4));
        *(undefined4 *)(param_1 + 4) = 0xffffffff;
        *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 0xc);
        goto LAB_c03b05c0;
      }
    }
    bVar1 = FUN_c03b02c0((STRSAFE_LPCWSTR)&_Stack_468.dwReserved1,*(int *)(param_1 + 0xc));
    if (CONCAT31(extraout_var,bVar1) == 0) {
      CeSafeCopyMemory(param_2,&_Stack_468,0x230);
      FUN_c03c216c(local_30);
      return 1;
    }
  } while( true );
}



/* c03b07a0 FUN_c03b07a0 */

/* Boundary evidence: original MIPS .pdata c03b07a0..c03b07ab. Semantic name remains unreviewed. */

undefined4 FUN_c03b07a0(void)

{
  return 1;
}



/* c03b07ac FUN_c03b07ac */

/* Boundary evidence: original MIPS .pdata c03b07ac..c03b0977. Semantic name remains unreviewed. */

undefined4 FUN_c03b07ac(int param_1,LPWIN32_FIND_DATAW param_2)

{
  HRESULT HVar1;
  undefined4 uVar2;
  int iVar3;
  BOOL BVar4;
  int local_464;
  int local_460;
  undefined1 auStack_458 [560];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  local_460 = param_1;
  if (*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) {
    HVar1 = StringCchCopyW(awStack_228,0x104,(STRSAFE_LPCWSTR)(param_1 + 0x14));
    if (HVar1 < 0) {
      SetLastError(0xce);
    }
    else {
      uVar2 = __GetUserKData(0xc);
      iVar3 = FUN_c03ae7dc(DAT_c03c623c,*(uint *)(DAT_c03c623c + 0x30),&local_464,(undefined4 *)0x0)
      ;
      if (iVar3 == 0) {
        uVar2 = AFS_FindFirstFileW(local_464,uVar2,awStack_228,auStack_458,0x230);
        *(undefined4 *)(param_1 + 4) = uVar2;
        if (*(int *)(param_1 + 4) != -1) {
          uVar2 = CeSafeCopyMemory(param_2,auStack_458,0x230);
          FUN_c03c216c(local_20);
          return uVar2;
        }
      }
    }
  }
  else {
    BVar4 = FindNextFileW(*(HANDLE *)(param_1 + 4),param_2);
    if (BVar4 != 0) {
      FUN_c03c216c(local_20);
      return 1;
    }
    FindClose(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  FUN_c03c216c(local_20);
  return 0;
}



/* c03b0978 FUN_c03b0978 */

/* Boundary evidence: original MIPS .pdata c03b0978..c03b0983. Semantic name remains unreviewed. */

undefined4 FUN_c03b0978(void)

{
  return 1;
}



/* c03b0984 FUN_c03b0984 */

/* Boundary evidence: original MIPS .pdata c03b0984..c03b0b57. Semantic name remains unreviewed. */

undefined4 FUN_c03b0984(int param_1,uint *param_2)

{
  int iVar1;
  HRESULT HVar2;
  uint uVar3;
  int iVar4;
  uint local_240;
  size_t local_23c;
  _FILETIME local_238;
  int aiStack_230 [2];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  iVar4 = *(int *)(DAT_c03c623c + 0x38);
  uVar3 = *(int *)(param_1 + 8) + 1;
  *(uint *)(param_1 + 8) = uVar3;
  while( true ) {
    if (iVar4 < (int)uVar3) {
      *(undefined4 *)(param_1 + 8) = 0xffffffff;
      SetLastError(0x12);
      FUN_c03c216c(local_20);
      return 0;
    }
    iVar1 = FUN_c03ae7dc(DAT_c03c623c,uVar3,aiStack_230,&local_240);
    if ((((iVar1 == 0) && ((local_240 & 1) == 0)) &&
        (((local_240 & 4) == 0 || (*(int *)(param_1 + 0x10) == 0)))) &&
       (((iVar1 = FUN_c03ae5f0(DAT_c03c623c,*(uint *)(param_1 + 8),awStack_228,0x104), iVar1 == 0 &&
         (HVar2 = StringCchLengthW(awStack_228,0x104,&local_23c), -1 < HVar2)) &&
        (iVar1 = MatchesWildcardMask(*(undefined4 *)(param_1 + 0x10),param_1 + 0x14,local_23c,
                                     awStack_228), iVar1 != 0)))) break;
    uVar3 = *(int *)(param_1 + 8) + 1;
    *(uint *)(param_1 + 8) = uVar3;
  }
  SystemTimeToFileTime((SYSTEMTIME *)&DAT_c03a1f38,&local_238);
  *param_2 = 0x10;
  param_2[2] = local_238.dwHighDateTime;
  param_2[4] = local_238.dwHighDateTime;
  param_2[6] = local_238.dwHighDateTime;
  param_2[1] = local_238.dwLowDateTime;
  param_2[3] = local_238.dwLowDateTime;
  param_2[5] = local_238.dwLowDateTime;
  param_2[7] = 0;
  param_2[8] = 0;
  if ((local_240 & 0x40) == 0) {
    *param_2 = 0x110;
  }
  if ((local_240 & 0x20) != 0) {
    *param_2 = *param_2 | 4;
  }
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 10),0x104,awStack_228);
  param_2[9] = *(uint *)(param_1 + 8) | 0xe0000000;
  FUN_c03c216c(local_20);
  return 1;
}



/* c03b0b58 FUN_c03b0b58 */

/* Boundary evidence: original MIPS .pdata c03b0b58..c03b0c43. Semantic name remains unreviewed. */

undefined4 FUN_c03b0b58(uint *param_1,LPWIN32_FIND_DATAW param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_1 & 2) == 0) {
LAB_c03b0bac:
    if ((*param_1 & 1) != 0) {
      iVar1 = FUN_c03b07ac((int)param_1,param_2);
      if (iVar1 != 0) goto LAB_c03b0b90;
      *param_1 = *param_1 & 0xfffffffe;
    }
    if ((*param_1 & 4) != 0) {
      iVar1 = FUN_c03b0538((int)param_1,param_2);
      if (iVar1 != 0) goto LAB_c03b0b90;
      *param_1 = *param_1 & 0xfffffffb;
    }
    SetLastError(0x12);
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_c03b0984((int)param_1,&param_2->dwFileAttributes);
    if (iVar1 == 0) {
      *param_1 = *param_1 & 0xfffffffd;
      goto LAB_c03b0bac;
    }
LAB_c03b0b90:
    uVar2 = 1;
  }
  return uVar2;
}



/* c03b0c44 FUN_c03b0c44 */

/* Boundary evidence: original MIPS .pdata c03b0c44..c03b0deb. Semantic name remains unreviewed. */

int FUN_c03b0c44(undefined4 param_1,STRSAFE_PCNZWCH param_2,LPWIN32_FIND_DATAW param_3,int param_4)

{
  bool bVar1;
  HRESULT HVar2;
  uint *puVar3;
  undefined3 extraout_var;
  int iVar4;
  DWORD dwErrCode;
  STRSAFE_LPWSTR pszDest;
  size_t local_20 [2];
  
  if (param_4 == 0x230) {
    if (*param_2 == L'\\') {
      param_2 = param_2 + 1;
    }
    HVar2 = StringCchLengthW(param_2,0x104,local_20);
    if (-1 < HVar2) {
      puVar3 = operator_new((local_20[0] + 0xc) * 2);
      if (puVar3 == (uint *)0x0) {
        dwErrCode = 8;
        goto LAB_c03b0c78;
      }
      pszDest = (STRSAFE_LPWSTR)(puVar3 + 5);
      HVar2 = StringCchCopyNW(pszDest,local_20[0] + 1,param_2,local_20[0]);
      if (-1 < HVar2) {
        puVar3[4] = local_20[0];
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        *puVar3 = 1;
        bVar1 = FUN_c03afce8(pszDest);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          *puVar3 = 3;
        }
        iVar4 = FUN_c03afc28(pszDest);
        if (iVar4 != 0) {
          *puVar3 = *puVar3 | 4;
        }
        iVar4 = FUN_c03b0b58(puVar3,param_3);
        if (iVar4 == 0) {
          operator_delete(puVar3);
          SetLastError(0x12);
          return -1;
        }
        iVar4 = CreateAPIHandle(DAT_c03c6238,puVar3);
        if (iVar4 != 0) {
          return iVar4;
        }
        operator_delete(puVar3);
        return -1;
      }
      operator_delete(puVar3);
    }
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = 0x57;
  }
LAB_c03b0c78:
  SetLastError(dwErrCode);
  return -1;
}



/* c03b0dec FUN_c03b0dec */

/* Boundary evidence: original MIPS .pdata c03b0dec..c03b0e23. Semantic name remains unreviewed. */

bool FUN_c03b0dec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_c03b001c(param_1,param_2,param_3,param_4);
  return iVar1 != -1;
}



/* c03b0e24 FUN_c03b0e24 */

/* Boundary evidence: original MIPS .pdata c03b0e24..c03b0f87. Semantic name remains unreviewed. */

undefined4 FUN_c03b0e24(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  int iVar2;
  STRSAFE_LPWSTR pwVar3;
  undefined4 uVar4;
  int *piVar5;
  HKEY local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  piVar5 = *(int **)(param_1 + 8);
  local_238[0] = (HKEY)0x0;
  local_28 = DAT_c03c531c;
  while( true ) {
    if (piVar5 == (int *)0x0) {
      FUN_c03c216c(local_28);
      return 0;
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s\\%s\\Filters",piVar5 + 1,uVar4);
    if (HVar1 < 0) break;
    iVar2 = FUN_c03acd2c(awStack_230,local_238);
    if (iVar2 == 0) {
      uVar4 = 1;
      pwVar3 = FUN_c03a2f08(local_238[0],3,awStack_230,(STRSAFE_LPWSTR)*param_2,1);
      *param_2 = pwVar3;
      FUN_c03acd64(local_238[0]);
      local_238[0] = (HKEY)0x0;
    }
    HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s\\Filters",piVar5 + 1,uVar4);
    if (HVar1 < 0) break;
    iVar2 = FUN_c03acd2c(awStack_230,local_238);
    if (iVar2 == 0) {
      pwVar3 = FUN_c03a2f08(local_238[0],3,awStack_230,(STRSAFE_LPWSTR)*param_2,1);
      *param_2 = pwVar3;
      FUN_c03acd64(local_238[0]);
      local_238[0] = (HKEY)0x0;
    }
    piVar5 = (int *)*piVar5;
  }
  FUN_c03c216c(local_28);
  return 0x3f8;
}



/* c03b0f88 FUN_c03b0f88 */

/* Boundary evidence: original MIPS .pdata c03b0f88..c03b0fe7. Semantic name remains unreviewed. */

void FUN_c03b0f88(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  *param_1 = &PTR_FUN_c03a1264;
  puVar1 = (void *)param_1[2];
  while (puVar1 != (void *)0x0) {
    pvVar2 = (void *)*puVar1;
    operator_delete(puVar1);
    puVar1 = pvVar2;
  }
  param_1[2] = 0;
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  return;
}



/* c03b0fe8 FUN_c03b0fe8 */

/* Boundary evidence: original MIPS .pdata c03b0fe8..c03b113f. Semantic name remains unreviewed. */

DWORD FUN_c03b0fe8(int param_1,LPCWSTR param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  HRESULT HVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  HKEY local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  piVar4 = *(int **)(param_1 + 8);
  DVar3 = 2;
  local_238[0] = (HKEY)0x0;
  if (piVar4 != (int *)0x0) {
    do {
      HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s\\%s",piVar4 + 1,*(undefined4 *)(param_1 + 0xc)
                              );
      if (HVar1 < 0) {
        FUN_c03c216c(local_28);
        return 0x3f8;
      }
      DVar3 = FUN_c03acd2c(awStack_230,local_238);
      if (DVar3 == 0) {
        iVar2 = FUN_c03acbc4(local_238[0],param_2,param_3,param_4);
        if (iVar2 != 0) {
          DVar3 = 0;
          break;
        }
        DVar3 = FUN_c03ac938(2);
        FUN_c03acd64(local_238[0]);
        local_238[0] = (HKEY)0x0;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    if (local_238[0] != (HKEY)0x0) {
      FUN_c03acd64(local_238[0]);
      local_238[0] = (HKEY)0x0;
    }
    if (DVar3 == 0) goto LAB_c03b10fc;
  }
  StringCchCopyW(param_3,param_4,L"");
LAB_c03b10fc:
  FUN_c03c216c(local_28);
  return DVar3;
}



/* c03b1140 FUN_c03b1140 */

/* Boundary evidence: original MIPS .pdata c03b1140..c03b1273. Semantic name remains unreviewed. */

DWORD FUN_c03b1140(int param_1,LPCWSTR param_2,LPBYTE param_3)

{
  HRESULT HVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  HKEY local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  piVar4 = *(int **)(param_1 + 8);
  DVar3 = 2;
  local_238[0] = (HKEY)0x0;
  if (piVar4 != (int *)0x0) {
    do {
      HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s\\%s",piVar4 + 1,*(undefined4 *)(param_1 + 0xc)
                              );
      if (HVar1 < 0) {
        FUN_c03c216c(local_28);
        return 0x3f8;
      }
      DVar3 = FUN_c03acd2c(awStack_230,local_238);
      if (DVar3 == 0) {
        iVar2 = FUN_c03acafc(local_238[0],param_2,param_3);
        if (iVar2 != 0) {
          DVar3 = 0;
          break;
        }
        DVar3 = FUN_c03ac938(2);
        FUN_c03acd64(local_238[0]);
        local_238[0] = (HKEY)0x0;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    if (local_238[0] != (HKEY)0x0) {
      FUN_c03acd64(local_238[0]);
    }
    if (DVar3 == 0) goto LAB_c03b1234;
  }
  param_3[0] = '\0';
  param_3[1] = '\0';
  param_3[2] = '\0';
  param_3[3] = '\0';
LAB_c03b1234:
  FUN_c03c216c(local_28);
  return DVar3;
}



/* c03b1274 FUN_c03b1274 */

/* Boundary evidence: original MIPS .pdata c03b1274..c03b12db. Semantic name remains unreviewed. */

void FUN_c03b1274(int param_1,LPCWSTR param_2,uint *param_3,uint param_4)

{
  DWORD DVar1;
  int local_18 [2];
  
  DVar1 = FUN_c03b1140(param_1,param_2,(LPBYTE)local_18);
  if (DVar1 == 0) {
    if (local_18[0] == 0) {
      *param_3 = ~param_4 & *param_3;
    }
    else {
      *param_3 = *param_3 | param_4;
    }
  }
  return;
}



/* c03b12dc FUN_c03b12dc */

/* Boundary evidence: original MIPS .pdata c03b12dc..c03b138f. Semantic name remains unreviewed. */

undefined4 FUN_c03b12dc(int param_1,STRSAFE_PCNZWCH param_2)

{
  HRESULT HVar1;
  undefined4 *puVar2;
  size_t local_18 [2];
  
  HVar1 = StringCchLengthW(param_2,0x104,local_18);
  if (-1 < HVar1) {
    puVar2 = operator_new((local_18[0] + 4) * 2);
    if (puVar2 == (undefined4 *)0x0) {
      return 8;
    }
    HVar1 = StringCchCopyNW((STRSAFE_LPWSTR)(puVar2 + 1),local_18[0] + 1,param_2,local_18[0]);
    if (-1 < HVar1) {
      *puVar2 = *(undefined4 *)(param_1 + 8);
      *(undefined4 **)(param_1 + 8) = puVar2;
      return 0;
    }
    operator_delete(puVar2);
  }
  return 0x57;
}



/* c03b1390 FUN_c03b1390 */

/* Boundary evidence: original MIPS .pdata c03b1390..c03b146b. Semantic name remains unreviewed. */

void FUN_c03b1390(int param_1)

{
  int iVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(param_1 + 4);
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"Paging",puVar2,1);
  if (iVar1 != 0) {
    *puVar2 = *puVar2 | 1;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"PowerNotify",puVar2,8);
  if (iVar1 != 0) {
    *puVar2 = *puVar2 | 8;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"FsctlTrustRequired",puVar2,2);
  if (iVar1 != 0) {
    *puVar2 = *puVar2 | 2;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"LockIOBuffers",puVar2,4);
  if (iVar1 != 0) {
    *puVar2 = *puVar2 | 4;
  }
  return;
}



/* c03b146c FUN_c03b146c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c03b146c..c03b15d3. Semantic name remains unreviewed. */

void FUN_c03b146c(int param_1,void *param_2,void *param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_4 / _DAT_00005b04;
  if (_DAT_00005b04 == 0) {
    trap(0x1c00);
  }
  uVar4 = uVar3;
  if ((*(uint *)(param_1 + 4) & 4) != 0) {
    for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
      UnlockPages(*(undefined4 *)(uVar2 * 8 + (int)param_2),_DAT_00005b04);
    }
  }
  if (param_2 != param_3) {
    for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
      uVar1 = 4;
      if (param_5 == 0) {
        uVar1 = 8;
      }
      CeCloseCallerBuffer(*(undefined4 *)(uVar2 * 8 + (int)param_2),
                          *(undefined4 *)(uVar2 * 8 + (int)param_3),_DAT_00005b04,uVar1,uVar2,uVar4)
      ;
    }
    operator_delete(param_2);
  }
  return;
}



/* c03b15d4 FUN_c03b15d4 */

/* Boundary evidence: original MIPS .pdata c03b15d4..c03b15df. Semantic name remains unreviewed. */

undefined4 FUN_c03b15d4(void)

{
  return 1;
}



/* c03b15e0 FUN_c03b15e0 */

/* Boundary evidence: original MIPS .pdata c03b15e0..c03b15eb. Semantic name remains unreviewed. */

undefined4 FUN_c03b15e0(void)

{
  return 1;
}



/* c03b15ec FUN_c03b15ec */

/* Boundary evidence: original MIPS .pdata c03b15ec..c03b1727. Semantic name remains unreviewed. */

undefined4 FUN_c03b15ec(undefined4 param_1,STRSAFE_LPCWSTR param_2,int param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  size_t local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  HVar1 = StringCchCopyW(awStack_230,0x104,param_2);
  if ((HVar1 < 0) || (HVar1 = StringCchLengthW(awStack_230,0x104,local_238), HVar1 < 0)) {
LAB_c03b16f4:
    FUN_c03c216c(local_28);
    uVar3 = 0x57;
  }
  else {
    piVar4 = (int *)(param_3 + 8);
    uVar5 = 0;
    do {
      HVar1 = StringCchCopyW(awStack_230 + local_238[0],0x104 - local_238[0],
                             *(STRSAFE_LPCWSTR *)((int)&PTR_u_CloseVolume_c03a2388 + uVar5));
      if (HVar1 < 0) goto LAB_c03b16f4;
      iVar2 = FUN_c03acd88();
      *piVar4 = iVar2;
      if (iVar2 == 0) {
        iVar2 = FUN_c03acd88();
        *piVar4 = iVar2;
        if (iVar2 == 0) {
          *piVar4 = *(int *)((int)&PTR_FUN_c03a238c + uVar5);
        }
      }
      uVar5 = uVar5 + 8;
      piVar4 = piVar4 + 1;
    } while (uVar5 < 0x118);
    FUN_c03c216c(local_28);
    uVar3 = 0;
  }
  return uVar3;
}



/* c03b1728 FUN_c03b1728 */

/* Boundary evidence: original MIPS .pdata c03b1728..c03b187b. Semantic name remains unreviewed. */

DWORD FUN_c03b1728(HMODULE param_1,STRSAFE_LPWSTR param_2,uint param_3)

{
  wchar_t wVar1;
  STRSAFE_LPWSTR pwVar2;
  DWORD DVar3;
  int iVar4;
  STRSAFE_LPWSTR pwVar5;
  uint uVar6;
  wchar_t *pwVar7;
  
  if (param_3 < 3) {
    DVar3 = 0x7a;
  }
  else {
    iVar4 = FUN_c03acd88();
    if (iVar4 == 0) {
      DVar3 = GetModuleFileNameW(param_1,param_2,param_3);
      if (DVar3 == 0) {
        DVar3 = FUN_c03ac938(0x1f);
        return DVar3;
      }
      pwVar2 = param_2 + DVar3;
      while (pwVar5 = pwVar2, pwVar5 != param_2) {
        wVar1 = pwVar5[-1];
        if ((wVar1 == L'\\') || (pwVar2 = pwVar5 + -1, wVar1 == L'/')) break;
      }
      wVar1 = *pwVar5;
      pwVar7 = param_2;
      for (uVar6 = 0; ((wVar1 != L'\0' && (wVar1 != L'.')) && (uVar6 < param_3 - 2));
          uVar6 = uVar6 + 1) {
        pwVar5 = pwVar5 + 1;
        *pwVar7 = wVar1;
        wVar1 = *pwVar5;
        pwVar7 = pwVar7 + 1;
      }
      param_2[uVar6] = L'_';
      (param_2 + uVar6)[1] = L'\0';
    }
    else {
      StringCchCopyW(param_2,param_3,L"FSD_");
    }
    DVar3 = 0;
  }
  return DVar3;
}



/* c03b187c FUN_c03b187c */

/* Boundary evidence: original MIPS .pdata c03b187c..c03b196f. Semantic name remains unreviewed. */

DWORD FUN_c03b187c(int param_1)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    DVar1 = 8;
  }
  else {
    iVar2 = LoadDriver();
    *(int *)(param_1 + 0xa8) = iVar2;
    if (iVar2 == 0) {
      DVar1 = 0x7e;
    }
    else {
      iVar2 = FUN_c03acd88();
      *(int *)(param_1 + 0xac) = iVar2;
      if (iVar2 == 0) {
        uVar3 = FUN_c03acd88();
        *(undefined4 *)(param_1 + 0xac) = uVar3;
      }
      iVar2 = FUN_c03acd88();
      *(int *)(param_1 + 0xb0) = iVar2;
      if (iVar2 == 0) {
        uVar3 = FUN_c03acd88();
        *(undefined4 *)(param_1 + 0xb0) = uVar3;
      }
      if ((*(int *)(param_1 + 0xac) != 0) && (*(int *)(param_1 + 0xb0) != 0)) {
        DVar1 = FUN_c03b15ec(*(undefined4 *)(param_1 + 0xa8),L"FILTER_",param_1 + 8);
        return DVar1;
      }
      FreeLibrary(*(HMODULE *)(param_1 + 0xa8));
      DVar1 = 0x7f;
    }
    DVar1 = FUN_c03ac938(DVar1);
  }
  return DVar1;
}



/* c03b1970 FUN_c03b1970 */

/* Boundary evidence: original MIPS .pdata c03b1970..c03b19df. Semantic name remains unreviewed. */

void FUN_c03b1970(int param_1)

{
  (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b19e0 FUN_c03b19e0 */

/* Boundary evidence: original MIPS .pdata c03b19e0..c03b1a07. Semantic name remains unreviewed. */

undefined4 FUN_c03b19e0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b1a08 FUN_c03b1a08 */

/* Boundary evidence: original MIPS .pdata c03b1a08..c03b1a2b. Semantic name remains unreviewed. */

void FUN_c03b1a08(void)

{
  SetLastError(0x32);
  return;
}



/* c03b1a2c FUN_c03b1a2c */

/* Boundary evidence: original MIPS .pdata c03b1a2c..c03b1a53. Semantic name remains unreviewed. */

undefined4 FUN_c03b1a2c(void)

{
  SetLastError(0x32);
  return 0;
}



/* c03b1a54 FUN_c03b1a54 */

/* Boundary evidence: original MIPS .pdata c03b1a54..c03b1a7b. Semantic name remains unreviewed. */

undefined4 FUN_c03b1a54(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c03b1a7c FUN_c03b1a7c */

/* Boundary evidence: original MIPS .pdata c03b1a7c..c03b1aa3. Semantic name remains unreviewed. */

undefined4 FUN_c03b1a7c(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c03b1aa4 FUN_c03b1aa4 */

/* Boundary evidence: original MIPS .pdata c03b1aa4..c03b1acb. Semantic name remains unreviewed. */

undefined4 FUN_c03b1aa4(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c03b1acc FUN_c03b1acc */

/* Boundary evidence: original MIPS .pdata c03b1acc..c03b1af3. Semantic name remains unreviewed. */

undefined4 FUN_c03b1acc(void)

{
  SetLastError(0x32);
  return 0xffffffff;
}



/* c03b1af4 FUN_c03b1af4 */

/* Boundary evidence: original MIPS .pdata c03b1af4..c03b1b37. Semantic name remains unreviewed. */

undefined4 * FUN_c03b1af4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03a25c8;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03b1b38 FUN_c03b1b38 */

/* Boundary evidence: original MIPS .pdata c03b1b38..c03b1ba7. Semantic name remains unreviewed. */

void FUN_c03b1b38(int param_1)

{
  (**(code **)(param_1 + 0xb0))(*(undefined4 *)(param_1 + 0x9c));
  return;
}



/* c03b1ba8 FUN_c03b1ba8 */

/* Boundary evidence: original MIPS .pdata c03b1ba8..c03b1bcf. Semantic name remains unreviewed. */

undefined4 FUN_c03b1ba8(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b1bd0 FUN_c03b1bd0 */

/* Boundary evidence: original MIPS .pdata c03b1bd0..c03b1c3f. Semantic name remains unreviewed. */

void FUN_c03b1bd0(int param_1)

{
  (**(code **)(param_1 + 0xb0))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b1c40 FUN_c03b1c40 */

/* Boundary evidence: original MIPS .pdata c03b1c40..c03b1c4b. Semantic name remains unreviewed. */

undefined4 FUN_c03b1c40(void)

{
  return 1;
}



/* c03b1c4c FUN_c03b1c4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c03b1c4c..c03b1fd3. Semantic name remains unreviewed. */

DWORD FUN_c03b1c4c(int param_1,undefined4 *param_2,void *param_3,uint param_4,int param_5,
                  int param_6)

{
  int iVar1;
  void *_Dst;
  uint uVar2;
  undefined4 uVar3;
  DWORD DVar4;
  uint uVar5;
  
  if ((param_4 != 0) && (param_3 != (void *)0x0)) {
    if (_DAT_00005b04 == 0) {
      trap(0x1c00);
    }
    if (param_4 % _DAT_00005b04 == 0) {
      uVar5 = param_4 / _DAT_00005b04;
      if (_DAT_00005b04 == 0) {
        trap(0x1c00);
      }
      iVar1 = __GetUserKData(0xc);
      if (param_6 == iVar1) {
        _Dst = param_3;
        if ((*(uint *)(param_1 + 4) & 4) != 0) {
          for (uVar2 = 0; uVar2 < uVar5; uVar2 = uVar2 + 1) {
            uVar3 = 4;
            if (param_5 == 0) {
              uVar3 = 1;
            }
            iVar1 = LockPages(*(undefined4 *)(uVar2 * 8 + (int)param_3),_DAT_00005b04,0,uVar3);
            if (iVar1 == 0) {
              DVar4 = FUN_c03ac938(0x1f);
              FUN_c03b146c(param_1,param_3,param_3,_DAT_00005b04 * uVar2,param_5);
              return DVar4;
            }
          }
        }
      }
      else {
        if (uVar5 < 0x20000000) {
          uVar2 = uVar5 << 3;
        }
        else {
          uVar2 = 0xffffffff;
        }
        _Dst = operator_new(uVar2);
        if (_Dst == (void *)0x0) {
          return 0xe;
        }
        memset(_Dst,0,uVar5 << 3);
        for (uVar2 = 0; uVar2 < uVar5; uVar2 = uVar2 + 1) {
          uVar3 = 4;
          if (param_5 == 0) {
            uVar3 = 8;
          }
          iVar1 = CeOpenCallerBuffer((void *)(uVar2 * 8 + (int)_Dst),
                                     *(undefined4 *)(uVar2 * 8 + (int)param_3),_DAT_00005b04,uVar3,0
                                    );
          if (iVar1 < 0) {
            DVar4 = 0x57;
LAB_c03b1e64:
            FUN_c03b146c(param_1,_Dst,param_3,_DAT_00005b04 * uVar2,param_5);
            return DVar4;
          }
          if ((*(uint *)(param_1 + 4) & 4) != 0) {
            uVar3 = 4;
            if (param_5 == 0) {
              uVar3 = 1;
            }
            iVar1 = LockPages(*(undefined4 *)(uVar2 * 8 + (int)_Dst),_DAT_00005b04,0,uVar3);
            if (iVar1 == 0) {
              DVar4 = FUN_c03ac938(0x1f);
              goto LAB_c03b1e64;
            }
          }
        }
      }
      *param_2 = _Dst;
      return 0;
    }
  }
  return 0x57;
}



/* c03b1fd4 FUN_c03b1fd4 */

/* Boundary evidence: original MIPS .pdata c03b1fd4..c03b1fdf. Semantic name remains unreviewed. */

undefined4 FUN_c03b1fd4(void)

{
  return 1;
}



/* c03b1fe0 FUN_c03b1fe0 */

/* Boundary evidence: original MIPS .pdata c03b1fe0..c03b1feb. Semantic name remains unreviewed. */

undefined4 FUN_c03b1fe0(void)

{
  return 1;
}



/* c03b1fec FUN_c03b1fec */

/* Boundary evidence: original MIPS .pdata c03b1fec..c03b1ff7. Semantic name remains unreviewed. */

undefined4 FUN_c03b1fec(void)

{
  return 1;
}



/* c03b1ff8 FUN_c03b1ff8 */

/* Boundary evidence: original MIPS .pdata c03b1ff8..c03b208f. Semantic name remains unreviewed. */

undefined4 * FUN_c03b1ff8(undefined4 *param_1,undefined4 param_2,STRSAFE_PCNZWCH param_3)

{
  param_1[0x27] = param_2;
  param_1[1] = 0;
  memset(param_1 + 2,0,0x94);
  param_1[2] = 0x94;
  *param_1 = &PTR_FUN_c03a25d8;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x28] = 0;
  FUN_c03ac970(param_1 + 0x29,param_3,0x104);
  return param_1;
}



/* c03b2090 FUN_c03b2090 */

/* Boundary evidence: original MIPS .pdata c03b2090..c03b20f7. Semantic name remains unreviewed. */

void FUN_c03b2090(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03a25d8;
  if ((void *)param_1[0x29] != (void *)0x0) {
    operator_delete((void *)param_1[0x29]);
  }
  if ((HMODULE)param_1[0x2a] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[0x2a]);
    param_1[0x2a] = 0;
  }
  *param_1 = &PTR_FUN_c03a25c8;
  return;
}



/* c03b20f8 FUN_c03b20f8 */

/* Boundary evidence: original MIPS .pdata c03b20f8..c03b221b. Semantic name remains unreviewed. */

DWORD FUN_c03b20f8(int param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  int iVar3;
  DWORD DVar4;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  FUN_c03b1390(param_1);
  pHVar1 = (HMODULE)LoadDriver(*(undefined4 *)(param_1 + 0xa4));
  *(HMODULE *)(param_1 + 0xa8) = pHVar1;
  if (pHVar1 == (HMODULE)0x0) {
    DVar4 = 0x7e;
  }
  else {
    DVar4 = FUN_c03b1728(pHVar1,awStack_220,0x104);
    if (DVar4 != 0) goto LAB_c03b21fc;
    uVar2 = FUN_c03acd88();
    *(undefined4 *)(param_1 + 0xac) = uVar2;
    iVar3 = FUN_c03acd88();
    *(int *)(param_1 + 0xb0) = iVar3;
    if ((*(int *)(param_1 + 0xac) != 0) && (iVar3 != 0)) {
      DVar4 = FUN_c03b15ec(*(undefined4 *)(param_1 + 0xa8),awStack_220,param_1 + 8);
      if (DVar4 == 0) {
        iVar3 = FUN_c03acd88();
        *(int *)(param_1 + 0xb4) = iVar3;
        if (iVar3 == 0) {
          *(undefined1 **)(param_1 + 0xb4) = &LAB_c03c1a34;
        }
        FUN_c03c216c(local_18);
        return 0;
      }
      goto LAB_c03b21fc;
    }
    FreeLibrary(*(HMODULE *)(param_1 + 0xa8));
    DVar4 = 0x7f;
  }
  DVar4 = FUN_c03ac938(DVar4);
LAB_c03b21fc:
  FUN_c03c216c(local_18);
  return DVar4;
}



/* c03b221c FUN_c03b221c */

/* Boundary evidence: original MIPS .pdata c03b221c..c03b2283. Semantic name remains unreviewed. */

undefined4 FUN_c03b221c(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = FUN_c03b1b38(param_1), iVar1 != 0)) {
    FUN_c03b1970(param_1);
  }
  if (*(HMODULE *)(param_1 + 0xa8) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  return 0;
}



/* c03b2284 FUN_c03b2284 */

/* Boundary evidence: original MIPS .pdata c03b2284..c03b231f. Semantic name remains unreviewed. */

undefined4 * FUN_c03b2284(undefined4 *param_1,undefined4 param_2,STRSAFE_PCNZWCH param_3)

{
  param_1[0x27] = param_2;
  param_1[1] = 0;
  memset(param_1 + 2,0,0x94);
  param_1[2] = 0x94;
  *param_1 = &PTR_FUN_c03a2648;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x28] = 1;
  FUN_c03ac970(param_1 + 0x29,param_3,0x104);
  return param_1;
}



/* c03b2320 FUN_c03b2320 */

/* Boundary evidence: original MIPS .pdata c03b2320..c03b23a7. Semantic name remains unreviewed. */

void FUN_c03b2320(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_FUN_c03a2648;
  if ((void *)param_1[0x29] != (void *)0x0) {
    operator_delete((void *)param_1[0x29]);
  }
  if ((HMODULE)param_1[0x2a] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[0x2a]);
    param_1[0x2a] = 0;
  }
  puVar1 = (undefined4 *)param_1[0x27];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  param_1[0x27] = 0;
  *param_1 = &PTR_FUN_c03a25c8;
  return;
}



/* c03b23a8 FUN_c03b23a8 */

/* Boundary evidence: original MIPS .pdata c03b23a8..c03b24a3. Semantic name remains unreviewed. */

void FUN_c03b23a8(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)(param_1 + 4);
  uVar3 = *(uint *)(*(int *)(param_1 + 0xb4) + 4);
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"Paging",puVar2,1);
  if (iVar1 != 0) {
    *puVar2 = uVar3 & 1 | *puVar2;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"PowerNotify",puVar2,8);
  if (iVar1 != 0) {
    *puVar2 = uVar3 & 8 | *puVar2;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"FsctlTrustRequired",puVar2,2);
  if (iVar1 != 0) {
    *puVar2 = uVar3 & 2 | *puVar2;
  }
  iVar1 = FUN_c03b1274(*(int *)(param_1 + 0x9c),L"LockIOBuffers",puVar2,4);
  if (iVar1 != 0) {
    *puVar2 = uVar3 & 4 | *puVar2;
  }
  return;
}



/* c03b24a4 FUN_c03b24a4 */

/* Boundary evidence: original MIPS .pdata c03b24a4..c03b254f. Semantic name remains unreviewed. */

int FUN_c03b24a4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(param_1 + 0xc) != 0) && (iVar1 = FUN_c03b1bd0(param_1), iVar1 != 0)) {
    FUN_c03b1970(param_1);
  }
  if (*(HMODULE *)(param_1 + 0xa8) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0xa8));
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  if (*(int **)(param_1 + 0xb4) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xb4) + 8))();
    if (iVar1 != 0) {
      return iVar1;
    }
    puVar2 = *(undefined4 **)(param_1 + 0xb4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(puVar2,1);
    }
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return 0;
}



/* c03b2550 FUN_c03b2550 */

/* Boundary evidence: original MIPS .pdata c03b2550..c03b260f. Semantic name remains unreviewed. */

int * FUN_c03b2550(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)param_1[0x2b])(param_1[0x27],param_2 + 8);
  param_1[3] = iVar1;
  if (param_1[3] == 0) {
    param_1 = (int *)0x0;
  }
  else {
    param_1[0x2d] = param_2;
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  return param_1;
}



/* c03b2610 FUN_c03b2610 */

/* Boundary evidence: original MIPS .pdata c03b2610..c03b261b. Semantic name remains unreviewed. */

undefined4 FUN_c03b2610(void)

{
  return 1;
}



/* c03b261c FUN_c03b261c */

/* Boundary evidence: original MIPS .pdata c03b261c..c03b2667. Semantic name remains unreviewed. */

undefined4 * FUN_c03b261c(undefined4 *param_1,uint param_2)

{
  FUN_c03b2090(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03b2668 FUN_c03b2668 */

/* Boundary evidence: original MIPS .pdata c03b2668..c03b26b3. Semantic name remains unreviewed. */

undefined4 * FUN_c03b2668(undefined4 *param_1,uint param_2)

{
  FUN_c03b2320(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03b26b4 FUN_c03b26b4 */

/* Boundary evidence: original MIPS .pdata c03b26b4..c03b26db. Semantic name remains unreviewed. */

undefined4 FUN_c03b26b4(void)

{
  SetLastError(1);
  return 0;
}



/* c03b26dc FUN_c03b26dc */

/* Boundary evidence: original MIPS .pdata c03b26dc..c03b2703. Semantic name remains unreviewed. */

undefined4 FUN_c03b26dc(void)

{
  SetLastError(1);
  return 0;
}



/* c03b2704 FUN_c03b2704 */

/* Boundary evidence: original MIPS .pdata c03b2704..c03b272b. Semantic name remains unreviewed. */

undefined4 FUN_c03b2704(void)

{
  SetLastError(1);
  return 0xffffffff;
}



/* c03b272c FUN_c03b272c */

/* Boundary evidence: original MIPS .pdata c03b272c..c03b2753. Semantic name remains unreviewed. */

undefined4 FUN_c03b272c(void)

{
  SetLastError(1);
  return 0xffffffff;
}



/* c03b2754 FUN_c03b2754 */

/* Boundary evidence: original MIPS .pdata c03b2754..c03b277b. Semantic name remains unreviewed. */

undefined4 FUN_c03b2754(void)

{
  SetLastError(1);
  return 0;
}



/* c03b277c FUN_c03b277c */

/* Boundary evidence: original MIPS .pdata c03b277c..c03b27a3. Semantic name remains unreviewed. */

undefined4 FUN_c03b277c(void)

{
  SetLastError(1);
  return 0;
}



/* c03b27a4 FUN_c03b27a4 */

/* Boundary evidence: original MIPS .pdata c03b27a4..c03b27cb. Semantic name remains unreviewed. */

undefined4 FUN_c03b27a4(void)

{
  SetLastError(1);
  return 0;
}



/* c03b27cc FUN_c03b27cc */

/* Boundary evidence: original MIPS .pdata c03b27cc..c03b27f3. Semantic name remains unreviewed. */

undefined4 FUN_c03b27cc(void)

{
  SetLastError(1);
  return 0;
}



/* c03b27f4 FUN_c03b27f4 */

/* Boundary evidence: original MIPS .pdata c03b27f4..c03b281b. Semantic name remains unreviewed. */

undefined4 FUN_c03b27f4(void)

{
  SetLastError(1);
  return 0;
}



/* c03b281c FUN_c03b281c */

/* Boundary evidence: original MIPS .pdata c03b281c..c03b286b. Semantic name remains unreviewed. */

undefined4 FUN_c03b281c(void)

{
  DAT_c03c6240 = CreateAPISet(&DAT_c03a2718,0x10,&PTR_FUN_c03a2658,&DAT_c03a2698);
  RegisterAPISet(DAT_c03c6240,0x80000007);
  return 0;
}



/* c03b286c FUN_c03b286c */

/* Boundary evidence: original MIPS .pdata c03b286c..c03b2903. Semantic name remains unreviewed. */

undefined4 FUN_c03b286c(undefined4 param_1,wchar_t *param_2,STRSAFE_LPCWSTR param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  wchar_t awStack_68 [40];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    StringCchCopyW(awStack_68,0x28,param_3);
  }
  else {
    StringCchPrintfW(awStack_68,0x28,L"%s_%s",param_2,param_3);
  }
  uVar2 = FUN_c03acd88();
  FUN_c03c216c(local_18);
  return uVar2;
}



/* c03b2904 FUN_c03b2904 */

/* Boundary evidence: original MIPS .pdata c03b2904..c03b2c93. Semantic name remains unreviewed. */

int FUN_c03b2904(int *param_1)

{
  int iVar1;
  size_t sVar2;
  int iVar3;
  LPCWSTR _Str;
  HKEY local_250;
  BYTE local_24c [8];
  int *local_244;
  wchar_t awStack_240 [8];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  iVar3 = -1;
  local_24c[4] = 0xff;
  local_24c[5] = 0xff;
  local_24c[6] = 0xff;
  local_24c[7] = 0xff;
  _Str = (LPCWSTR)(param_1 + 0xb);
  local_244 = param_1;
  iVar1 = FUN_c03acd2c(_Str,&local_250);
  if (iVar1 == 0) {
    iVar1 = FUN_c03acbc4(local_250,L"Dll",awStack_230,0x104);
    if (iVar1 != 0) {
      iVar1 = LoadDriver(awStack_230);
      param_1[1] = iVar1;
      if (iVar1 != 0) {
        iVar1 = FUN_c03acbc4(local_250,L"Prefix",awStack_240,8);
        if (iVar1 == 0) {
          StringCchCopyW(awStack_240,8,L"");
        }
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,&UNK_c03a27a0);
        param_1[4] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,L"Deinit");
        param_1[5] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,&UNK_c03a2784);
        param_1[6] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,L"Close");
        param_1[7] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,L"IOControl");
        param_1[8] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,L"PowerDown");
        param_1[10] = iVar1;
        iVar1 = (**(code **)(*param_1 + 4))(param_1,awStack_240,L"PowerUp");
        param_1[9] = iVar1;
      }
    }
    if (((param_1[4] != 0) && (param_1[6] != 0)) && (param_1[8] != 0)) {
      sVar2 = wcslen(_Str);
      RegSetValueExW(local_250,L"Key",0,1,(BYTE *)_Str,(sVar2 + 1) * 2);
      iVar1 = (*(code *)param_1[4])(_Str);
      param_1[2] = iVar1;
      if (iVar1 != 0) {
        iVar1 = (*(code *)param_1[6])(iVar1,0xc0000000,0);
        param_1[3] = iVar1;
        if (iVar1 == 0) {
          (*(code *)param_1[5])(param_1[2]);
          param_1[2] = 0;
        }
      }
      if ((param_1[3] != 0) && (param_1[2] != 0)) {
        iVar3 = CreateAPIHandle(DAT_c03c6240,param_1);
        if (iVar3 == 0) {
          iVar3 = -1;
        }
        (**(code **)(*param_1 + 0xc))(param_1,local_250);
      }
    }
    local_24c[0] = '\x04';
    local_24c[1] = '\0';
    local_24c[2] = '\0';
    local_24c[3] = '\0';
    RegSetValueExW(local_250,L"Flags",0,4,local_24c,4);
  }
  FUN_c03c216c(local_28);
  return iVar3;
}



/* c03b2c94 FUN_c03b2c94 */

/* Boundary evidence: original MIPS .pdata c03b2c94..c03b2cbb. Semantic name remains unreviewed. */

undefined4 FUN_c03b2c94(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b2cbc FUN_c03b2cbc */

/* Boundary evidence: original MIPS .pdata c03b2cbc..c03b2dd7. Semantic name remains unreviewed. */

void FUN_c03b2cbc(int param_1,HKEY param_2)

{
  LSTATUS LVar1;
  undefined2 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  DWORD local_20 [2];
  
  local_20[0] = 0;
  LVar1 = RegQueryValueExW(param_2,L"IClass",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,local_20);
  if ((LVar1 == 0) && ((local_20[0] & 1) == 0)) {
    uVar5 = local_20[0] >> 1;
    uVar3 = uVar5 + 1;
    if (uVar3 < 0x80000000) {
      uVar3 = uVar3 * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    puVar2 = operator_new(uVar3);
    *(undefined2 **)(param_1 + 0x234) = puVar2;
    *puVar2 = 0;
    if (*(LPBYTE *)(param_1 + 0x234) != (LPBYTE)0x0) {
      LVar1 = RegQueryValueExW(param_2,L"IClass",(LPDWORD)0x0,(LPDWORD)0x0,
                               *(LPBYTE *)(param_1 + 0x234),local_20);
      if (LVar1 == 0) {
        iVar4 = uVar5 * 2;
        *(undefined2 *)(iVar4 + *(int *)(param_1 + 0x234) + -2) = 0;
        *(undefined2 *)(iVar4 + *(int *)(param_1 + 0x234)) = 0;
      }
    }
  }
  return;
}



/* c03b2dd8 FUN_c03b2dd8 */

/* Boundary evidence: original MIPS .pdata c03b2dd8..c03b2e9f. Semantic name remains unreviewed. */

void FUN_c03b2dd8(int param_1,undefined4 param_2,undefined4 param_3)

{
  wchar_t wVar1;
  int iVar2;
  STRSAFE_PCNZWCH psz;
  size_t local_238 [2];
  undefined1 auStack_230 [16];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  if (*(int *)(param_1 + 0x234) != 0) {
    StringCchPrintfW(awStack_220,0x104,L"\\StoreMgr\\%s",param_2);
    psz = *(STRSAFE_PCNZWCH *)(param_1 + 0x234);
    wVar1 = *psz;
    while (wVar1 != L'\0') {
      local_238[0] = 0;
      StringCchLengthW(psz,0x104,local_238);
      iVar2 = FUN_c03aca40(psz,(int)auStack_230);
      if (iVar2 != 0) {
        FSDMGR_AdvertiseInterface(auStack_230,awStack_220,param_3);
      }
      psz = psz + local_238[0] + 1;
      wVar1 = *psz;
    }
  }
  FUN_c03c216c(local_18);
  return;
}



/* c03b2ea0 FUN_c03b2ea0 */

/* Boundary evidence: original MIPS .pdata c03b2ea0..c03b2f07. Semantic name remains unreviewed. */

undefined4 FUN_c03b2ea0(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0xc));
  }
  return uVar1;
}



/* c03b2f08 FUN_c03b2f08 */

/* Boundary evidence: original MIPS .pdata c03b2f08..c03b2f2f. Semantic name remains unreviewed. */

undefined4 FUN_c03b2f08(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b2f30 FUN_c03b2f30 */

/* Boundary evidence: original MIPS .pdata c03b2f30..c03b2f9f. Semantic name remains unreviewed. */

void FUN_c03b2f30(int param_1)

{
  (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b2fa0 FUN_c03b2fa0 */

/* Boundary evidence: original MIPS .pdata c03b2fa0..c03b2fc7. Semantic name remains unreviewed. */

undefined4 FUN_c03b2fa0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b2fc8 FUN_c03b2fc8 */

/* Boundary evidence: original MIPS .pdata c03b2fc8..c03b2fe3. Semantic name remains unreviewed. */

void FUN_c03b2fc8(int param_1)

{
  FUN_c03b2ea0(param_1);
  return;
}



/* c03b2fe4 FUN_c03b2fe4 */

/* Boundary evidence: original MIPS .pdata c03b2fe4..c03b301b. Semantic name remains unreviewed. */

void FUN_c03b2fe4(int param_1)

{
  FUN_c03b2f30(param_1);
  return;
}



/* c03b301c FUN_c03b301c */

/* Boundary evidence: original MIPS .pdata c03b301c..c03b306b. Semantic name remains unreviewed. */

undefined4 FUN_c03b301c(void)

{
  DAT_c03c6244 = CreateAPISet(&DAT_c03a2810,3,&PTR_FUN_c03a27e8,&DAT_c03a27f8);
  RegisterAPISet(DAT_c03c6244,0x80000008);
  return 0;
}



/* c03b306c FUN_c03b306c */

/* Boundary evidence: original MIPS .pdata c03b306c..c03b30c3. Semantic name remains unreviewed. */

void FUN_c03b306c(int param_1)

{
  int iVar1;
  
  while (iVar1 = FUN_c03ad44c(param_1), iVar1 == 0x10df) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x44),*(DWORD *)(param_1 + 0x34));
  }
  return;
}



/* c03b30c4 FUN_c03b30c4 */

/* Boundary evidence: original MIPS .pdata c03b30c4..c03b313b. Semantic name remains unreviewed. */

void FUN_c03b30c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x40))(param_2,param_3,param_3,param_4,0);
  return;
}



/* c03b313c FUN_c03b313c */

/* Boundary evidence: original MIPS .pdata c03b313c..c03b3163. Semantic name remains unreviewed. */

undefined4 FUN_c03b313c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3164 FUN_c03b3164 */

/* Boundary evidence: original MIPS .pdata c03b3164..c03b3223. Semantic name remains unreviewed. */

undefined4 FUN_c03b3164(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x230) {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar2);
      if (dwErrCode == 0) {
        uVar1 = FUN_c03b30c4(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_4);
        FUN_c03a5af8(iVar2);
        return uVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c03b3224 FUN_c03b3224 */

/* Boundary evidence: original MIPS .pdata c03b3224..c03b32af. Semantic name remains unreviewed. */

undefined4 FUN_c03b3224(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[6];
  if (((param_1[7] & 0x80000000U) == 0) && (iVar1 = FUN_c03b306c(iVar2), iVar1 == 0)) {
    FUN_c03acec0(param_1[2],param_1[3]);
    FUN_c03adc54(param_1);
    operator_delete(param_1);
    FUN_c03a5af8(iVar2);
  }
  else {
    FUN_c03adc54(param_1);
    operator_delete(param_1);
  }
  return 1;
}



/* c03b32b0 FUN_c03b32b0 */

/* Boundary evidence: original MIPS .pdata c03b32b0..c03b331b. Semantic name remains unreviewed. */

undefined4 FUN_c03b32b0(void)

{
  DAT_c03c6248 = CreateAPISet(&DAT_c03a18a8,0x18,&DAT_c03a2878,&DAT_c03a28d8);
  RegisterAPISet(DAT_c03c6248,0x80000010);
  RegisterDirectMethods(DAT_c03c6248,&PTR_FUN_c03a2818);
  return 0;
}



/* c03b331c FUN_c03b331c */

/* Boundary evidence: original MIPS .pdata c03b331c..c03b335f. Semantic name remains unreviewed. */

bool FUN_c03b331c(int *param_1)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03ae0bc(param_1);
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c03b3360 FUN_c03b3360 */

/* Boundary evidence: original MIPS .pdata c03b3360..c03b33cf. Semantic name remains unreviewed. */

void FUN_c03b3360(int param_1)

{
  (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b33d0 FUN_c03b33d0 */

/* Boundary evidence: original MIPS .pdata c03b33d0..c03b33f7. Semantic name remains unreviewed. */

undefined4 FUN_c03b33d0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b33f8 FUN_c03b33f8 */

/* Boundary evidence: original MIPS .pdata c03b33f8..c03b3467. Semantic name remains unreviewed. */

void FUN_c03b33f8(int param_1)

{
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3468 FUN_c03b3468 */

/* Boundary evidence: original MIPS .pdata c03b3468..c03b348f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3468(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3490 FUN_c03b3490 */

/* Boundary evidence: original MIPS .pdata c03b3490..c03b3507. Semantic name remains unreviewed. */

void FUN_c03b3490(int param_1)

{
  (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3508 FUN_c03b3508 */

/* Boundary evidence: original MIPS .pdata c03b3508..c03b352f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3508(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3530 FUN_c03b3530 */

/* Boundary evidence: original MIPS .pdata c03b3530..c03b359f. Semantic name remains unreviewed. */

void FUN_c03b3530(int param_1)

{
  (**(code **)(param_1 + 0x20))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b35a0 FUN_c03b35a0 */

/* Boundary evidence: original MIPS .pdata c03b35a0..c03b35c7. Semantic name remains unreviewed. */

undefined4 FUN_c03b35a0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b35c8 FUN_c03b35c8 */

/* Boundary evidence: original MIPS .pdata c03b35c8..c03b3637. Semantic name remains unreviewed. */

void FUN_c03b35c8(int param_1)

{
  (**(code **)(param_1 + 0x24))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3638 FUN_c03b3638 */

/* Boundary evidence: original MIPS .pdata c03b3638..c03b365f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3638(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3660 FUN_c03b3660 */

/* Boundary evidence: original MIPS .pdata c03b3660..c03b36cf. Semantic name remains unreviewed. */

void FUN_c03b3660(int param_1)

{
  (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b36d0 FUN_c03b36d0 */

/* Boundary evidence: original MIPS .pdata c03b36d0..c03b36f7. Semantic name remains unreviewed. */

undefined4 FUN_c03b36d0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b36f8 FUN_c03b36f8 */

/* Boundary evidence: original MIPS .pdata c03b36f8..c03b3767. Semantic name remains unreviewed. */

void FUN_c03b36f8(int param_1)

{
  (**(code **)(param_1 + 0x2c))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3768 FUN_c03b3768 */

/* Boundary evidence: original MIPS .pdata c03b3768..c03b378f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3768(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3790 FUN_c03b3790 */

/* Boundary evidence: original MIPS .pdata c03b3790..c03b380f. Semantic name remains unreviewed. */

void FUN_c03b3790(int param_1)

{
  (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3810 FUN_c03b3810 */

/* Boundary evidence: original MIPS .pdata c03b3810..c03b3837. Semantic name remains unreviewed. */

undefined4 FUN_c03b3810(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3838 FUN_c03b3838 */

/* Boundary evidence: original MIPS .pdata c03b3838..c03b389f. Semantic name remains unreviewed. */

void FUN_c03b3838(int param_1)

{
  if ((*(uint *)(param_1 + 4) & 8) != 0) {
    (**(code **)(param_1 + 0x34))(*(undefined4 *)(param_1 + 0xc));
  }
  return;
}



/* c03b38a0 FUN_c03b38a0 */

/* Boundary evidence: original MIPS .pdata c03b38a0..c03b38c7. Semantic name remains unreviewed. */

undefined4 FUN_c03b38a0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b38c8 FUN_c03b38c8 */

/* Boundary evidence: original MIPS .pdata c03b38c8..c03b3937. Semantic name remains unreviewed. */

void FUN_c03b38c8(int param_1)

{
  (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3938 FUN_c03b3938 */

/* Boundary evidence: original MIPS .pdata c03b3938..c03b395f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3938(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3960 FUN_c03b3960 */

/* Boundary evidence: original MIPS .pdata c03b3960..c03b39d3. Semantic name remains unreviewed. */

void FUN_c03b3960(int param_1)

{
  (**(code **)(param_1 + 0x3c))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b39d4 FUN_c03b39d4 */

/* Boundary evidence: original MIPS .pdata c03b39d4..c03b39fb. Semantic name remains unreviewed. */

undefined4 FUN_c03b39d4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b39fc FUN_c03b39fc */

/* Boundary evidence: original MIPS .pdata c03b39fc..c03b3a97. Semantic name remains unreviewed. */

void FUN_c03b39fc(int param_1)

{
  (**(code **)(param_1 + 0x48))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3a98 FUN_c03b3a98 */

/* Boundary evidence: original MIPS .pdata c03b3a98..c03b3abf. Semantic name remains unreviewed. */

undefined4 FUN_c03b3a98(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3ac0 FUN_c03b3ac0 */

/* Boundary evidence: original MIPS .pdata c03b3ac0..c03b3b67. Semantic name remains unreviewed. */

void FUN_c03b3ac0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  (**(code **)(param_1 + 0x78))(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,0);
  return;
}



/* c03b3b68 FUN_c03b3b68 */

/* Boundary evidence: original MIPS .pdata c03b3b68..c03b3b8f. Semantic name remains unreviewed. */

undefined4 FUN_c03b3b68(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3b90 FUN_c03b3b90 */

/* Boundary evidence: original MIPS .pdata c03b3b90..c03b3bff. Semantic name remains unreviewed. */

void FUN_c03b3b90(int param_1)

{
  (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0xc));
  return;
}



/* c03b3c00 FUN_c03b3c00 */

/* Boundary evidence: original MIPS .pdata c03b3c00..c03b3c27. Semantic name remains unreviewed. */

undefined4 FUN_c03b3c00(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b3c28 FUN_c03b3c28 */

/* Boundary evidence: original MIPS .pdata c03b3c28..c03b3c63. Semantic name remains unreviewed. */

undefined4 FUN_c03b3c28(void *param_1)

{
  if (param_1 != (void *)0x0) {
    FUN_c03ad2b0((int)param_1);
    operator_delete(param_1);
  }
  return 1;
}



/* c03b3c64 FUN_c03b3c64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c03b3c64..c03b3df3. Semantic name remains unreviewed. */

undefined4 FUN_c03b3c64(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_148 [2];
  undefined4 local_140;
  uint local_13c;
  uint local_138;
  undefined4 local_134;
  undefined4 local_b0 [34];
  uint local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  
  local_1c = DAT_c03c531c;
  if (param_2 == 0) {
    memset(local_b0,0,0x94);
    local_b0[0] = 0x94;
    local_24 = _DAT_00005b04;
    FUN_c03b3b90(*(int *)(param_1 + 8));
    piVar3 = *(int **)(param_1 + 4);
    memset(&local_140,0,0x90);
    local_140 = 0x90;
    (**(code **)(*piVar3 + 0x18))(piVar3,&local_140);
    local_13c = local_13c | local_28;
    uVar1 = *(uint *)(param_1 + 0x28);
    local_138 = local_138 | local_20;
    local_134 = local_24;
    if ((uVar1 & 1) != 0) {
      local_13c = local_13c | 2;
    }
    if ((uVar1 & 2) != 0) {
      local_13c = local_13c | 0x10;
    }
    if ((uVar1 & 0x20) != 0) {
      local_13c = local_13c | 8;
    }
    if ((uVar1 & 0x80) != 0) {
      local_13c = local_13c | 0x10;
    }
    if (param_4 != 0) {
      local_148[0] = 0x90;
      CeSafeCopyMemory(param_4,local_148,4);
    }
    uVar2 = CeSafeCopyMemory(param_3,&local_140,0x90);
    FUN_c03c216c(local_1c);
  }
  else {
    SetLastError(0x57);
    FUN_c03c216c(local_1c);
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b3df4 FUN_c03b3df4 */

/* Boundary evidence: original MIPS .pdata c03b3df4..c03b3e6b. Semantic name remains unreviewed. */

void FUN_c03b3df4(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if ((*(uint *)(iVar1 + 4) & 8) != 0) {
    if ((param_2 & 2) != 0) {
      FUN_c03ae02c(param_1);
    }
    FUN_c03b3838(iVar1);
    if ((param_2 & 1) != 0) {
      FUN_c03adfe8(param_1);
    }
  }
  return;
}



/* c03b3e6c FUN_c03b3e6c */

/* Boundary evidence: original MIPS .pdata c03b3e6c..c03b3f33. Semantic name remains unreviewed. */

int FUN_c03b3e6c(int param_1,wchar_t *param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
  iVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar1 = FUN_c03b3360(*(int *)(param_1 + 8));
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      FUN_c03bdc64(*(int *)(param_1 + 0x2c),param_2,1,1);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar1;
}



/* c03b3f34 FUN_c03b3f34 */

/* Boundary evidence: original MIPS .pdata c03b3f34..c03b3fd3. Semantic name remains unreviewed. */

int FUN_c03b3f34(int param_1,wchar_t *param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
  iVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar1 = FUN_c03b33f8(*(int *)(param_1 + 8));
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      FUN_c03bdc64(*(int *)(param_1 + 0x2c),param_2,1,2);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar1;
}



/* c03b3fd4 FUN_c03b3fd4 */

/* Boundary evidence: original MIPS .pdata c03b3fd4..c03b4053. Semantic name remains unreviewed. */

undefined4 FUN_c03b3fd4(int param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    uVar1 = FUN_c03b3490(*(int *)(param_1 + 8));
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* c03b4054 FUN_c03b4054 */

/* Boundary evidence: original MIPS .pdata c03b4054..c03b4103. Semantic name remains unreviewed. */

int FUN_c03b4054(int param_1,wchar_t *param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
  iVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar1 = FUN_c03b3530(*(int *)(param_1 + 8));
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      FUN_c03bdc64(*(int *)(param_1 + 0x2c),param_2,0,3);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar1;
}



/* c03b4104 FUN_c03b4104 */

/* Boundary evidence: original MIPS .pdata c03b4104..c03b41a3. Semantic name remains unreviewed. */

int FUN_c03b4104(int param_1,wchar_t *param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
  iVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar1 = FUN_c03b35c8(*(int *)(param_1 + 8));
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x2c) != 0)) {
      FUN_c03bdc64(*(int *)(param_1 + 0x2c),param_2,0,2);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar1;
}



/* c03b41a4 FUN_c03b41a4 */

/* Boundary evidence: original MIPS .pdata c03b41a4..c03b428b. Semantic name remains unreviewed. */

int FUN_c03b41a4(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  DWORD dwErrCode;
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar3 = *(int *)(param_1 + 8);
    uVar1 = FUN_c03b3490(iVar3);
    iVar3 = FUN_c03b3660(iVar3);
    if (iVar3 != 0) {
      iVar2 = 0;
      if ((uVar1 != 0xffffffff) && ((uVar1 & 0x10) != 0)) {
        iVar2 = 1;
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        FUN_c03bdcdc(*(int *)(param_1 + 0x2c),param_2,param_3,iVar2);
      }
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar3;
}



/* c03b428c FUN_c03b428c */

/* Boundary evidence: original MIPS .pdata c03b428c..c03b4353. Semantic name remains unreviewed. */

int FUN_c03b428c(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  DWORD dwErrCode;
  int iVar1;
  
  iVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar1 = FUN_c03b36f8(*(int *)(param_1 + 8));
    if (iVar1 != 0) {
      if (*(int *)(param_1 + 0x2c) != 0) {
        FUN_c03bdc64(*(int *)(param_1 + 0x2c),param_2,0,2);
      }
      if (*(int *)(param_1 + 0x2c) != 0) {
        FUN_c03bdde0(*(int *)(param_1 + 0x2c),param_3,param_2);
      }
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return iVar1;
}



/* c03b4354 FUN_c03b4354 */

/* Boundary evidence: original MIPS .pdata c03b4354..c03b43ff. Semantic name remains unreviewed. */

undefined4 FUN_c03b4354(int param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  uVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    uVar1 = FUN_c03b3790(*(int *)(param_1 + 8));
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* c03b4400 FUN_c03b4400 */

/* Boundary evidence: original MIPS .pdata c03b4400..c03b447b. Semantic name remains unreviewed. */

undefined4 FUN_c03b4400(int param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  uVar1 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    uVar1 = FUN_c03b38c8(*(int *)(param_1 + 8));
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar1;
}



/* c03b447c FUN_c03b447c */

/* Boundary evidence: original MIPS .pdata c03b447c..c03b4583. Semantic name remains unreviewed. */

int FUN_c03b447c(int param_1)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000010;
  
  if (in_stack_00000010 == 0x230) {
    iVar2 = -1;
    dwErrCode = FUN_c03b306c(param_1);
    if (dwErrCode == 0) {
      iVar3 = *(int *)(param_1 + 8);
      iVar1 = FUN_c03b3960(iVar3);
      if ((iVar1 != -1) && (iVar2 = FUN_c03ae2d0(param_1,iVar1,iVar3), iVar2 == -1)) {
        FUN_c03acec0(iVar3,iVar1);
      }
      FUN_c03a5af8(param_1);
    }
    else {
      SetLastError(dwErrCode);
    }
  }
  else {
    SetLastError(0x57);
    iVar2 = -1;
  }
  return iVar2;
}



/* c03b4584 FUN_c03b4584 */

/* Boundary evidence: original MIPS .pdata c03b4584..c03b47e3. Semantic name remains unreviewed. */

int FUN_c03b4584(int param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,int param_7)

{
  DWORD dwErrCode;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = -1;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    return -1;
  }
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (param_7 != 3) {
    iVar4 = FUN_c03b3490(iVar3);
  }
  iVar1 = FUN_c03b39fc(iVar3);
  if (iVar1 == -1) {
    if ((param_3 != (wchar_t *)0x0) && (iVar4 = _wcsicmp(param_3,L"\\VOL:"), iVar4 == 0)) {
      SetLastError(0);
      iVar5 = FUN_c03ae1c4(param_1,0xffffffff,0x40000000,iVar3,param_3,param_4);
    }
  }
  else {
    uVar2 = 1;
    iVar5 = FUN_c03afd4c(param_3);
    if (iVar5 != 0) {
      uVar2 = 0x20000001;
    }
    iVar5 = FUN_c03ae1c4(param_1,iVar1,uVar2,iVar3,param_3,param_4);
    if (iVar5 == -1) {
      FUN_c03acff0(iVar3,iVar1);
    }
    else if ((uVar2 == 1) && (iVar3 = FUN_c03afda8(param_3), iVar3 == 0)) {
      if (iVar4 == -1) {
        iVar4 = *(int *)(param_1 + 0x2c);
        if (iVar4 == 0) goto LAB_c03b4794;
        iVar3 = 1;
      }
      else {
        if (((param_7 != 2) && (param_7 != 5)) || (iVar4 = *(int *)(param_1 + 0x2c), iVar4 == 0))
        goto LAB_c03b4794;
        iVar3 = 3;
      }
      FUN_c03bdc64(iVar4,param_3,0,iVar3);
    }
  }
LAB_c03b4794:
  FUN_c03a5af8(param_1);
  return iVar5;
}



/* c03b47e4 FUN_c03b47e4 */

/* Boundary evidence: original MIPS .pdata c03b47e4..c03b4917. Semantic name remains unreviewed. */

undefined4
FUN_c03b47e4(int param_1,HANDLE param_2,wchar_t *param_3,undefined4 param_4,undefined4 param_5)

{
  DWORD dwErrCode;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    uVar1 = FUN_c03b3490(*(int *)(param_1 + 8));
    iVar2 = wcscmp(param_3,L"\\");
    if (((iVar2 == 0) || (iVar2 = wcscmp(param_3,L""), iVar2 == 0)) ||
       ((uVar1 != 0xffffffff && ((uVar1 & 0x10) != 0)))) {
      if (*(int *)(param_1 + 0x2c) == 0) {
        SetLastError(3);
      }
      else {
        uVar3 = FUN_c03bd434(*(int *)(param_1 + 0x2c),param_2,param_3,param_4,param_5);
      }
    }
    else {
      SetLastError(3);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar3;
}



/* c03b4918 FUN_c03b4918 */

/* Boundary evidence: original MIPS .pdata c03b4918..c03b4a63. Semantic name remains unreviewed. */

undefined4
FUN_c03b4918(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,undefined4 param_9)

{
  DWORD dwErrCode;
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  uVar2 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    if (param_3 == 0x90080) {
      if ((((param_4 == 0) || (param_6 == 0)) || (param_5 != 4)) || (param_7 != 0x90)) {
        SetLastError(0x57);
      }
      else {
        iVar1 = CeSafeCopyMemory(local_20,param_4,4);
        if (iVar1 != 0) {
          uVar2 = FUN_c03b3c64(param_1,local_20[0],param_6,param_8);
        }
      }
    }
    else {
      uVar2 = FUN_c03ad088(*(int *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,param_7,
                           param_8,param_9);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar2;
}



/* c03b4a64 FUN_c03b4a64 */

/* Boundary evidence: original MIPS .pdata c03b4a64..c03b4bd7. Semantic name remains unreviewed. */

int FUN_c03b4a64(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                undefined4 param_6)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  DVar1 = FUN_c03b306c(param_1);
  if (DVar1 == 0) {
    iVar4 = *(int *)(param_1 + 8);
    __GetUserKData(0xc);
    iVar2 = FUN_c03b39fc(iVar4);
    if ((iVar2 == 0) || (iVar2 == -1)) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_c03b3ac0(iVar4,iVar2,0x900a8,0,0,param_4,param_5,param_6,0);
      FUN_c03acff0(iVar4,iVar2);
      if ((((iVar3 == 0) && (DVar1 = GetLastError(), DVar1 == 0x7a)) && (param_4 == 0)) &&
         (param_5 == 0)) {
        SetLastError(0);
        iVar3 = 1;
      }
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(DVar1);
  }
  return iVar3;
}



/* c03b4bd8 FUN_c03b4bd8 */

/* Boundary evidence: original MIPS .pdata c03b4bd8..c03b4cfb. Semantic name remains unreviewed. */

undefined4
FUN_c03b4bd8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  DWORD dwErrCode;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  dwErrCode = FUN_c03b306c(param_1);
  if (dwErrCode == 0) {
    iVar3 = *(int *)(param_1 + 8);
    __GetUserKData(0xc);
    iVar1 = FUN_c03b39fc(iVar3);
    if ((iVar1 == 0) || (iVar1 == -1)) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_c03b3ac0(iVar3,iVar1,0x900a8,param_4,param_5,0,0,0,0);
      FUN_c03acff0(iVar3,iVar1);
    }
    FUN_c03a5af8(param_1);
  }
  else {
    SetLastError(dwErrCode);
  }
  return uVar2;
}



/* c03b4cfc FUN_c03b4cfc */

/* Boundary evidence: original MIPS .pdata c03b4cfc..c03b4d67. Semantic name remains unreviewed. */

undefined4 FUN_c03b4cfc(void)

{
  DAT_c03c624c = CreateAPISet(&DAT_c03a2aa8,0x10,&PTR_FUN_c03a29a8,&DAT_c03a2a28);
  RegisterAPISet(DAT_c03c624c,0x80000007);
  RegisterDirectMethods(DAT_c03c624c,&PTR_FUN_c03a29e8);
  return 0;
}



/* c03b4d68 FUN_c03b4d68 */

/* Boundary evidence: original MIPS .pdata c03b4d68..c03b4eb3. Semantic name remains unreviewed. */

undefined4
FUN_c03b4d68(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_4 == 0) || (param_3 == 0)) || ((*(uint *)(param_1 + 4) & 4) == 0)) ||
     (iVar1 = LockPages(param_3,param_4,0,1), iVar1 != 0)) {
    uVar2 = (**(code **)(param_1 + 0x4c))(param_2,param_3,param_4,param_5,param_6);
    if (((param_4 != 0) && (param_3 != 0)) && ((*(uint *)(param_1 + 4) & 4) != 0)) {
      UnlockPages(param_3,param_4);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b4eb4 FUN_c03b4eb4 */

/* Boundary evidence: original MIPS .pdata c03b4eb4..c03b4edb. Semantic name remains unreviewed. */

undefined4 FUN_c03b4eb4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b4edc FUN_c03b4edc */

/* Boundary evidence: original MIPS .pdata c03b4edc..c03b506b. Semantic name remains unreviewed. */

undefined4
FUN_c03b4edc(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == 0) {
    if (param_4 != 0) goto LAB_c03b4f60;
    if ((*(uint *)(param_1 + 4) & 1) != 0) goto LAB_c03b4f58;
    SetLastError(0x32);
LAB_c03b4f4c:
    uVar2 = 0;
  }
  else {
LAB_c03b4f58:
    if (param_4 != 0) {
LAB_c03b4f60:
      if (((param_3 != 0) && ((*(uint *)(param_1 + 4) & 4) != 0)) &&
         (iVar1 = LockPages(param_3,param_4,0,1), iVar1 == 0)) goto LAB_c03b4f4c;
    }
    uVar2 = (**(code **)(param_1 + 0x50))(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    if (((param_4 != 0) && (param_3 != 0)) && ((*(uint *)(param_1 + 4) & 4) != 0)) {
      UnlockPages(param_3,param_4);
    }
  }
  return uVar2;
}



/* c03b506c FUN_c03b506c */

/* Boundary evidence: original MIPS .pdata c03b506c..c03b5093. Semantic name remains unreviewed. */

undefined4 FUN_c03b506c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5094 FUN_c03b5094 */

/* Boundary evidence: original MIPS .pdata c03b5094..c03b51df. Semantic name remains unreviewed. */

undefined4
FUN_c03b5094(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_4 == 0) || (param_3 == 0)) || ((*(uint *)(param_1 + 4) & 4) == 0)) ||
     (iVar1 = LockPages(param_3,param_4,0,4), iVar1 != 0)) {
    uVar2 = (**(code **)(param_1 + 0x54))(param_2,param_3,param_4,param_5,param_6);
    if (((param_4 != 0) && (param_3 != 0)) && ((*(uint *)(param_1 + 4) & 4) != 0)) {
      UnlockPages(param_3,param_4);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b51e0 FUN_c03b51e0 */

/* Boundary evidence: original MIPS .pdata c03b51e0..c03b5207. Semantic name remains unreviewed. */

undefined4 FUN_c03b51e0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5208 FUN_c03b5208 */

/* Boundary evidence: original MIPS .pdata c03b5208..c03b5363. Semantic name remains unreviewed. */

undefined4
FUN_c03b5208(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_4 == 0) || (param_3 == 0)) || ((*(uint *)(param_1 + 4) & 4) == 0)) ||
     (iVar1 = LockPages(param_3,param_4,0,4), iVar1 != 0)) {
    uVar2 = (**(code **)(param_1 + 0x58))(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    if (((param_4 != 0) && (param_3 != 0)) && ((*(uint *)(param_1 + 4) & 4) != 0)) {
      UnlockPages(param_3,param_4);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b5364 FUN_c03b5364 */

/* Boundary evidence: original MIPS .pdata c03b5364..c03b538b. Semantic name remains unreviewed. */

undefined4 FUN_c03b5364(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b538c FUN_c03b538c */

/* Boundary evidence: original MIPS .pdata c03b538c..c03b541b. Semantic name remains unreviewed. */

void FUN_c03b538c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_1 + 0x5c))(param_2,param_3,param_4,param_5,0xffffffff);
  return;
}



/* c03b541c FUN_c03b541c */

/* Boundary evidence: original MIPS .pdata c03b541c..c03b5443. Semantic name remains unreviewed. */

undefined4 FUN_c03b541c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5444 FUN_c03b5444 */

/* Boundary evidence: original MIPS .pdata c03b5444..c03b54c3. Semantic name remains unreviewed. */

void FUN_c03b5444(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x60))(param_2,param_3,param_3,param_4,0xffffffff);
  return;
}



/* c03b54c4 FUN_c03b54c4 */

/* Boundary evidence: original MIPS .pdata c03b54c4..c03b54eb. Semantic name remains unreviewed. */

undefined4 FUN_c03b54c4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b54ec FUN_c03b54ec */

/* Boundary evidence: original MIPS .pdata c03b54ec..c03b5563. Semantic name remains unreviewed. */

void FUN_c03b54ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 100))(param_2,param_3,param_3,param_4,0);
  return;
}



/* c03b5564 FUN_c03b5564 */

/* Boundary evidence: original MIPS .pdata c03b5564..c03b558b. Semantic name remains unreviewed. */

undefined4 FUN_c03b5564(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b558c FUN_c03b558c */

/* Boundary evidence: original MIPS .pdata c03b558c..c03b5613. Semantic name remains unreviewed. */

void FUN_c03b558c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_1 + 0x6c))(param_2,param_3,param_4,param_5,0);
  return;
}



/* c03b5614 FUN_c03b5614 */

/* Boundary evidence: original MIPS .pdata c03b5614..c03b563b. Semantic name remains unreviewed. */

undefined4 FUN_c03b5614(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b563c FUN_c03b563c */

/* Boundary evidence: original MIPS .pdata c03b563c..c03b56c3. Semantic name remains unreviewed. */

void FUN_c03b563c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_1 + 0x70))(param_2,param_3,param_4,param_5,0);
  return;
}



/* c03b56c4 FUN_c03b56c4 */

/* Boundary evidence: original MIPS .pdata c03b56c4..c03b56eb. Semantic name remains unreviewed. */

undefined4 FUN_c03b56c4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b56ec FUN_c03b56ec */

/* Boundary evidence: original MIPS .pdata c03b56ec..c03b575b. Semantic name remains unreviewed. */

void FUN_c03b56ec(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x74))(param_2);
  return;
}



/* c03b575c FUN_c03b575c */

/* Boundary evidence: original MIPS .pdata c03b575c..c03b5783. Semantic name remains unreviewed. */

undefined4 FUN_c03b575c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5784 FUN_c03b5784 */

/* Boundary evidence: original MIPS .pdata c03b5784..c03b581b. Semantic name remains unreviewed. */

void FUN_c03b5784(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  (**(code **)(param_1 + 0x88))(param_2,param_3,param_4,param_5,param_6,param_7,0);
  return;
}



/* c03b581c FUN_c03b581c */

/* Boundary evidence: original MIPS .pdata c03b581c..c03b5843. Semantic name remains unreviewed. */

undefined4 FUN_c03b581c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5844 FUN_c03b5844 */

/* Boundary evidence: original MIPS .pdata c03b5844..c03b58d3. Semantic name remains unreviewed. */

void FUN_c03b5844(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  (**(code **)(param_1 + 0x8c))(param_2,param_3,param_4,param_5,param_6);
  return;
}



/* c03b58d4 FUN_c03b58d4 */

/* Boundary evidence: original MIPS .pdata c03b58d4..c03b58fb. Semantic name remains unreviewed. */

undefined4 FUN_c03b58d4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b58fc FUN_c03b58fc */

/* Boundary evidence: original MIPS .pdata c03b58fc..c03b5a2f. Semantic name remains unreviewed. */

undefined4
FUN_c03b58fc(int param_1,undefined4 param_2,int param_3,void *param_4,uint param_5,
            undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  void *local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  local_20 = (void *)0x0;
  dwErrCode = FUN_c03b1c4c(param_1,&local_20,param_4,param_5,0,param_3);
  if (dwErrCode == 0) {
    uVar1 = (**(code **)(param_1 + 0x94))(param_2,local_20,param_5,param_6,param_7);
    local_1c = uVar1;
    FUN_c03b146c(param_1,local_20,param_4,param_5,0);
  }
  else {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c03b5a30 FUN_c03b5a30 */

/* Boundary evidence: original MIPS .pdata c03b5a30..c03b5a57. Semantic name remains unreviewed. */

undefined4 FUN_c03b5a30(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5a58 FUN_c03b5a58 */

/* Boundary evidence: original MIPS .pdata c03b5a58..c03b5b9b. Semantic name remains unreviewed. */

undefined4
FUN_c03b5a58(int param_1,undefined4 param_2,int param_3,void *param_4,uint param_5,
            undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  void *local_28;
  undefined4 local_24;
  
  local_24 = 0;
  local_28 = (void *)0x0;
  dwErrCode = FUN_c03b1c4c(param_1,&local_28,param_4,param_5,1,param_3);
  if (dwErrCode == 0) {
    uVar1 = (**(code **)(param_1 + 0x98))(param_2,local_28,param_5,param_6,param_7);
    local_24 = uVar1;
    FUN_c03b146c(param_1,local_28,param_4,param_5,1);
  }
  else {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c03b5b9c FUN_c03b5b9c */

/* Boundary evidence: original MIPS .pdata c03b5b9c..c03b5bc3. Semantic name remains unreviewed. */

undefined4 FUN_c03b5b9c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b5bc4 FUN_c03b5bc4 */

/* Boundary evidence: original MIPS .pdata c03b5bc4..c03b5c13. Semantic name remains unreviewed. */

void FUN_c03b5bc4(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x18) != 0) && (*(void **)(param_1 + 0x10) != (void *)0x0)) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c);
    if (iVar1 != 0) {
      FUN_c03be9b0(iVar1,*(void **)(param_1 + 0x10));
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}



/* c03b5c14 FUN_c03b5c14 */

/* Boundary evidence: original MIPS .pdata c03b5c14..c03b5cf3. Semantic name remains unreviewed. */

undefined4
FUN_c03b5c14(int param_1,int param_2,int param_3,void *param_4,uint param_5,undefined4 param_6,
            undefined4 param_7)

{
  undefined4 uVar1;
  
  if (param_4 == (void *)0x0) {
    SetLastError(0x57);
  }
  else {
    if (param_3 == 0x90048) {
      if ((*(uint *)(param_1 + 0x20) & 0x80000000) == 0x80000000) {
        uVar1 = FUN_c03b58fc(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_4,
                             param_5,param_6,param_7);
        return uVar1;
      }
    }
    else if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
      uVar1 = FUN_c03b5a58(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_4,
                           param_5,param_6,param_7);
      return uVar1;
    }
    SetLastError(5);
  }
  return 0;
}



/* c03b5cf4 FUN_c03b5cf4 */

/* Boundary evidence: original MIPS .pdata c03b5cf4..c03b5ddf. Semantic name remains unreviewed. */

undefined4 FUN_c03b5cf4(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 0x80000000) == 0x80000000) {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar2);
      if (dwErrCode == 0) {
        uVar1 = FUN_c03b4d68(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                             param_4,param_5);
        FUN_c03a5af8(iVar2);
        return uVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b5de0 FUN_c03b5de0 */

/* Boundary evidence: original MIPS .pdata c03b5de0..c03b5f03. Semantic name remains unreviewed. */

int FUN_c03b5de0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
    iVar3 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar3);
      if (dwErrCode == 0) {
        iVar1 = FUN_c03b5094(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                             param_4,param_5);
        if ((((iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) && (*(int *)(param_1 + 0x10) != 0))
           && (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c), iVar2 != 0)) {
          FUN_c03be324(iVar2,*(int *)(param_1 + 0x10),0x10);
        }
        FUN_c03a5af8(iVar3);
        return iVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b5f04 FUN_c03b5f04 */

/* Boundary evidence: original MIPS .pdata c03b5f04..c03b5fa7. Semantic name remains unreviewed. */

undefined4 FUN_c03b5f04(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
    dwErrCode = FUN_c03b306c(iVar2);
    if (dwErrCode == 0) {
      uVar1 = FUN_c03b5444(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_4);
      FUN_c03a5af8(iVar2);
      return uVar1;
    }
  }
  else {
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c03b5fa8 FUN_c03b5fa8 */

/* Boundary evidence: original MIPS .pdata c03b5fa8..c03b606b. Semantic name remains unreviewed. */

undefined4 FUN_c03b5fa8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
    dwErrCode = FUN_c03b306c(iVar2);
    if (dwErrCode == 0) {
      uVar1 = FUN_c03b538c(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                           param_4);
      FUN_c03a5af8(iVar2);
      return uVar1;
    }
  }
  else {
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c03b606c FUN_c03b606c */

/* Boundary evidence: original MIPS .pdata c03b606c..c03b612b. Semantic name remains unreviewed. */

undefined4 FUN_c03b606c(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0x38) {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar2);
      if (dwErrCode == 0) {
        uVar1 = FUN_c03b54ec(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_4);
        FUN_c03a5af8(iVar2);
        return uVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c03b612c FUN_c03b612c */

/* Boundary evidence: original MIPS .pdata c03b612c..c03b61e7. Semantic name remains unreviewed. */

undefined4 FUN_c03b612c(int param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar2);
      if (dwErrCode == 0) {
        uVar1 = FUN_c03acf58(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
        FUN_c03a5af8(iVar2);
        return uVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b61e8 FUN_c03b61e8 */

/* Boundary evidence: original MIPS .pdata c03b61e8..c03b62a7. Semantic name remains unreviewed. */

undefined4 FUN_c03b61e8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
    dwErrCode = FUN_c03b306c(iVar2);
    if (dwErrCode == 0) {
      uVar1 = FUN_c03b558c(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                           param_4);
      FUN_c03a5af8(iVar2);
      return uVar1;
    }
  }
  else {
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03b62a8 FUN_c03b62a8 */

/* Boundary evidence: original MIPS .pdata c03b62a8..c03b63c3. Semantic name remains unreviewed. */

int FUN_c03b62a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
    iVar3 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar3);
      if (dwErrCode == 0) {
        iVar1 = FUN_c03b563c(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                             param_4);
        if ((((iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) && (*(int *)(param_1 + 0x10) != 0))
           && (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c), iVar2 != 0)) {
          FUN_c03be324(iVar2,*(int *)(param_1 + 0x10),0x10);
        }
        FUN_c03a5af8(iVar3);
        return iVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b63c4 FUN_c03b63c4 */

/* Boundary evidence: original MIPS .pdata c03b63c4..c03b64b3. Semantic name remains unreviewed. */

int FUN_c03b63c4(int param_1)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
    iVar3 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar3);
      if (dwErrCode == 0) {
        iVar1 = FUN_c03b56ec(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
        if ((((iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) && (*(int *)(param_1 + 0x10) != 0))
           && (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c), iVar2 != 0)) {
          FUN_c03be324(iVar2,*(int *)(param_1 + 0x10),0x10);
        }
        FUN_c03a5af8(iVar3);
        return iVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b64b4 FUN_c03b64b4 */

/* Boundary evidence: original MIPS .pdata c03b64b4..c03b6717. Semantic name remains unreviewed. */

undefined4
FUN_c03b64b4(int param_1,int param_2,int param_3,void *param_4,uint param_5,int param_6,int param_7,
            int param_8,undefined4 param_9)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int local_28 [2];
  
  if (param_3 == 0x900a8) {
    SetLastError(5);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      DVar1 = FUN_c03b306c(iVar4);
      if (DVar1 == 0) {
        uVar3 = 0;
        if ((*(uint *)(param_1 + 0x1c) & 0x40000000) == 0) {
          if ((param_3 == 0x90044) || (param_3 == 0x90048)) {
            uVar3 = FUN_c03b5c14(param_1,param_2,param_3,param_4,param_5,param_6,param_9);
          }
          else if (param_3 == 0x90080) {
            if ((((param_4 == (void *)0x0) || (param_6 == 0)) || (param_5 != 4)) ||
               (param_7 != 0x90)) {
              SetLastError(0x57);
            }
            else {
              iVar2 = CeSafeCopyMemory(local_28,param_4,4);
              if (iVar2 != 0) {
                uVar3 = FUN_c03b3c64(iVar4,local_28[0],param_6,param_8);
              }
            }
          }
          else {
            uVar3 = FUN_c03b3ac0(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_3,
                                 param_4,param_5,param_6,param_7,param_8,param_9);
          }
        }
        else {
          DVar1 = (**(code **)(**(int **)(iVar4 + 4) + 4))
                            (*(int **)(iVar4 + 4),param_3,param_4,param_5,param_6,param_7,param_8,
                             param_9);
          SetLastError(DVar1);
          if (DVar1 == 0) {
            uVar3 = 1;
          }
          else {
            uVar3 = 0;
          }
        }
        FUN_c03a5af8(iVar4);
        return uVar3;
      }
    }
    else {
      DVar1 = 0x651;
    }
    SetLastError(DVar1);
  }
  return 0;
}



/* c03b6718 FUN_c03b6718 */

/* Boundary evidence: original MIPS .pdata c03b6718..c03b679b. Semantic name remains unreviewed. */

void FUN_c03b6718(int param_1,int param_2,void *param_3,uint param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8)

{
  int iVar1;
  
  iVar1 = __GetUserKData(0xc);
  FUN_c03b64b4(param_1,iVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c03b679c FUN_c03b679c */

/* Boundary evidence: original MIPS .pdata c03b679c..c03b6863. Semantic name remains unreviewed. */

undefined4
FUN_c03b679c(int param_1,int param_2,void *param_3,uint param_4,int param_5,int param_6,int param_7,
            int param_8)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_30 [24];
  
  if (param_8 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_8,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_30;
  }
  iVar1 = GetCallerVMProcessId();
  uVar2 = FUN_c03b64b4(param_1,iVar1,param_2,param_3,param_4,param_5,param_6,param_7,puVar3);
  return uVar2;
}



/* c03b6864 FUN_c03b6864 */

/* Boundary evidence: original MIPS .pdata c03b6864..c03b695f. Semantic name remains unreviewed. */

undefined4
FUN_c03b6864(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 0x80000000) == 0x80000000) {
    iVar2 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar2);
      if (dwErrCode == 0) {
        uVar1 = FUN_c03b4edc(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                             param_4,param_5,param_6,param_7);
        FUN_c03a5af8(iVar2);
        return uVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b6960 FUN_c03b6960 */

/* Boundary evidence: original MIPS .pdata c03b6960..c03b6a93. Semantic name remains unreviewed. */

int FUN_c03b6960(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x20) & 0x40000000) == 0x40000000) {
    iVar3 = *(int *)(param_1 + 0x18);
    if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
      dwErrCode = FUN_c03b306c(iVar3);
      if (dwErrCode == 0) {
        iVar1 = FUN_c03b5208(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                             param_4,param_5,param_6,param_7);
        if ((((iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) && (*(int *)(param_1 + 0x10) != 0))
           && (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 0x2c), iVar2 != 0)) {
          FUN_c03be324(iVar2,*(int *)(param_1 + 0x10),0x10);
        }
        FUN_c03a5af8(iVar3);
        return iVar1;
      }
    }
    else {
      dwErrCode = 0x651;
    }
    SetLastError(dwErrCode);
  }
  else {
    SetLastError(5);
  }
  return 0;
}



/* c03b6a94 FUN_c03b6a94 */

/* Boundary evidence: original MIPS .pdata c03b6a94..c03b6b63. Semantic name remains unreviewed. */

undefined4
FUN_c03b6a94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
    dwErrCode = FUN_c03b306c(iVar2);
    if (dwErrCode == 0) {
      uVar1 = FUN_c03b5784(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                           param_4,param_5,param_6);
      FUN_c03a5af8(iVar2);
      return uVar1;
    }
  }
  else {
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03b6b64 FUN_c03b6b64 */

/* Boundary evidence: original MIPS .pdata c03b6b64..c03b6c2b. Semantic name remains unreviewed. */

undefined4
FUN_c03b6b64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if ((*(uint *)(param_1 + 0x1c) & 0x80000000) == 0) {
    dwErrCode = FUN_c03b306c(iVar2);
    if (dwErrCode == 0) {
      uVar1 = FUN_c03b5844(*(int *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,param_3,
                           param_4,param_5);
      FUN_c03a5af8(iVar2);
      return uVar1;
    }
  }
  else {
    dwErrCode = 0x651;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03b6c2c FUN_c03b6c2c */

/* Boundary evidence: original MIPS .pdata c03b6c2c..c03b6ccf. Semantic name remains unreviewed. */

undefined4 FUN_c03b6c2c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[6];
  if (((param_1[7] & 0x80000000U) == 0) && (iVar1 = FUN_c03b306c(iVar2), iVar1 == 0)) {
    if (param_1[3] != -1) {
      FUN_c03acff0(param_1[2],param_1[3]);
      FUN_c03b5bc4((int)param_1);
    }
    FUN_c03adc54(param_1);
    operator_delete(param_1);
    FUN_c03a5af8(iVar2);
  }
  else {
    FUN_c03adc54(param_1);
    operator_delete(param_1);
  }
  return 1;
}



/* c03b6cd0 FUN_c03b6cd0 */

/* Boundary evidence: original MIPS .pdata c03b6cd0..c03b6d6b. Semantic name remains unreviewed. */

undefined4 FUN_c03b6cd0(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_30 [24];
  
  if (param_5 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_5,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_30;
  }
  uVar2 = FUN_c03b5cf4(param_1,param_2,param_3,param_4,puVar3);
  return uVar2;
}



/* c03b6d6c FUN_c03b6d6c */

/* Boundary evidence: original MIPS .pdata c03b6d6c..c03b6e07. Semantic name remains unreviewed. */

int FUN_c03b6d6c(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_30 [24];
  
  if (param_5 == 0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_5,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar2 = auStack_30;
  }
  iVar1 = FUN_c03b5de0(param_1,param_2,param_3,param_4,puVar2);
  return iVar1;
}



/* c03b6e08 FUN_c03b6e08 */

/* Boundary evidence: original MIPS .pdata c03b6e08..c03b6eb3. Semantic name remains unreviewed. */

undefined4
FUN_c03b6e08(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,undefined4 param_6,
            undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_30 [24];
  
  if (param_5 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_5,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_30;
  }
  uVar2 = FUN_c03b6864(param_1,param_2,param_3,param_4,puVar3,param_6,param_7);
  return uVar2;
}



/* c03b6eb4 FUN_c03b6eb4 */

/* Boundary evidence: original MIPS .pdata c03b6eb4..c03b6f5f. Semantic name remains unreviewed. */

int FUN_c03b6eb4(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_30 [24];
  
  if (param_5 == 0) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_5,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar2 = auStack_30;
  }
  iVar1 = FUN_c03b6960(param_1,param_2,param_3,param_4,puVar2,param_6,param_7);
  return iVar1;
}



/* c03b6f60 FUN_c03b6f60 */

/* Boundary evidence: original MIPS .pdata c03b6f60..c03b7003. Semantic name remains unreviewed. */

undefined4
FUN_c03b6f60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_30 [24];
  
  if (param_6 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_6,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_30;
  }
  uVar2 = FUN_c03b6a94(param_1,param_2,param_3,param_4,param_5,puVar3);
  return uVar2;
}



/* c03b7004 FUN_c03b7004 */

/* Boundary evidence: original MIPS .pdata c03b7004..c03b709f. Semantic name remains unreviewed. */

undefined4
FUN_c03b7004(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_30 [24];
  
  if (param_5 == 0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    iVar1 = CeSafeCopyMemory(auStack_30,param_5,0x14);
    if (iVar1 == 0) {
      SetLastError(0x57);
      return 0;
    }
    puVar3 = auStack_30;
  }
  uVar2 = FUN_c03b6b64(param_1,param_2,param_3,param_4,puVar3);
  return uVar2;
}



/* c03b70a0 FUN_c03b70a0 */

/* Boundary evidence: original MIPS .pdata c03b70a0..c03b7113. Semantic name remains unreviewed. */

int * FUN_c03b70a0(uint param_1)

{
  int *piVar1;
  
  WaitForSingleObject(DAT_c03c6264,0xffffffff);
  if ((DAT_c03c5318 <= param_1) || (piVar1 = (int *)(param_1 * 0xc + DAT_c03c6268), *piVar1 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



/* c03b7114 FUN_c03b7114 */

/* Boundary evidence: original MIPS .pdata c03b7114..c03b719b. Semantic name remains unreviewed. */

undefined4 FUN_c03b7114(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03b70a0(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x57;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
    *(undefined4 *)(param_1 * 0xc + DAT_c03c6268) = 0;
    DAT_c03c626c = DAT_c03c626c + -1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b719c FUN_c03b719c */

/* Boundary evidence: original MIPS .pdata c03b719c..c03b720b. Semantic name remains unreviewed. */

undefined4 FUN_c03b719c(uint param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03b70a0(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = FSDMGR_ReadDisk(*piVar1,param_2,param_3,param_4,piVar1[1] * param_3);
  }
  return uVar2;
}



/* c03b720c FUN_c03b720c */

/* Boundary evidence: original MIPS .pdata c03b720c..c03b727b. Semantic name remains unreviewed. */

undefined4 FUN_c03b720c(uint param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c03b70a0(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x57;
  }
  else {
    uVar2 = FSDMGR_WriteDisk(*piVar1,param_2,param_3,param_4,piVar1[1] * param_3);
  }
  return uVar2;
}



/* c03b727c FUN_c03b727c */

/* Boundary evidence: original MIPS .pdata c03b727c..c03b7303. Semantic name remains unreviewed. */

undefined4 FUN_c03b727c(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = FUN_c03b70a0(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x57;
  }
  else {
    if ((piVar1[2] & 2U) == 0) {
      iVar3 = FSDMGR_DiskIoControl((int *)*piVar1);
      if (iVar3 == 0) {
        piVar1[2] = piVar1[2] | 2;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b7304 FUN_c03b7304 */

/* Boundary evidence: original MIPS .pdata c03b7304..c03b73ff. Semantic name remains unreviewed. */

undefined4 FUN_c03b7304(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = FUN_c03b70a0(param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x57;
  }
  else if (param_2 == 0x71c4c) {
    if ((piVar1[2] & 1U) == 0) {
      iVar3 = FSDMGR_DiskIoControl((int *)*piVar1);
      if (iVar3 == 0) {
        piVar1[2] = piVar1[2] | 1;
      }
    }
    uVar2 = 1;
  }
  else {
    uVar2 = FSDMGR_DiskIoControl((int *)*piVar1);
  }
  return uVar2;
}



/* c03b7400 FUN_c03b7400 */

/* Boundary evidence: original MIPS .pdata c03b7400..c03b7443. Semantic name remains unreviewed. */

void FUN_c03b7400(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
  DAT_c03c6264 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  return;
}



/* c03b7444 FUN_c03b7444 */

/* Boundary evidence: original MIPS .pdata c03b7444..c03b7483. Semantic name remains unreviewed. */

void FUN_c03b7444(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
  CloseHandle(DAT_c03c6264);
  LocalFree(DAT_c03c6268);
  return;
}



/* c03b7484 FUN_c03b7484 */

/* Boundary evidence: original MIPS .pdata c03b7484..c03b7617. Semantic name remains unreviewed. */

uint FUN_c03b7484(int param_1)

{
  bool bVar1;
  int *piVar2;
  int in_stack_00000010;
  uint local_30;
  
  bVar1 = true;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
  if ((DAT_c03c6268 != (int *)0x0) ||
     (DAT_c03c6268 = LocalAlloc(0x40,DAT_c03c5318 * 0xc), DAT_c03c6268 != (int *)0x0)) {
    if (DAT_c03c626c == DAT_c03c5318) {
      EventModify(DAT_c03c6264,2);
      piVar2 = LocalReAlloc(DAT_c03c6268,DAT_c03c5318 * 0x18,0x42);
      if (piVar2 == (int *)0x0) {
        EventModify(DAT_c03c6264,3);
        goto LAB_c03b75d0;
      }
      DAT_c03c5318 = DAT_c03c5318 << 1;
      DAT_c03c6268 = piVar2;
      EventModify(DAT_c03c6264,3);
    }
    local_30 = 0;
    piVar2 = DAT_c03c6268;
    if (DAT_c03c5318 != 0) {
      do {
        if (*piVar2 == 0) {
          DAT_c03c6268[local_30 * 3] = param_1;
          DAT_c03c6268[local_30 * 3 + 1] = in_stack_00000010;
          break;
        }
        local_30 = local_30 + 1;
        piVar2 = piVar2 + 3;
      } while (local_30 < DAT_c03c5318);
    }
    DAT_c03c626c = DAT_c03c626c + 1;
    bVar1 = false;
  }
LAB_c03b75d0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6250);
  if (bVar1) {
    local_30 = 0xffffffff;
  }
  return local_30;
}



/* c03b7618 FUN_c03b7618 */

/* Boundary evidence: original MIPS .pdata c03b7618..c03b7637. Semantic name remains unreviewed. */

undefined4 FUN_c03b7618(void *param_1)

{
  operator_delete(param_1);
  return 0;
}



/* c03b7638 FUN_c03b7638 */

/* Boundary evidence: original MIPS .pdata c03b7638..c03b7677. Semantic name remains unreviewed. */

undefined4 FUN_c03b7638(void *param_1)

{
  FUN_c03bc314((int *)((int)param_1 + 0x10),FUN_c03b7618,0);
  operator_delete(param_1);
  return 1;
}



/* c03b7678 FUN_c03b7678 */

/* Boundary evidence: original MIPS .pdata c03b7678..c03b76ab. Semantic name remains unreviewed. */

undefined4 FUN_c03b7678(int *param_1)

{
  FUN_c03bbef4(param_1);
  operator_delete(param_1);
  return 1;
}



/* c03b76ac FUN_c03b76ac */

/* Boundary evidence: original MIPS .pdata c03b76ac..c03b76eb. Semantic name remains unreviewed. */

bool FUN_c03b76ac(int param_1)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03bb1ec(*(int *)(param_1 + 0x140));
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b76ec FUN_c03b76ec */

/* Boundary evidence: original MIPS .pdata c03b76ec..c03b7773. Semantic name remains unreviewed. */

undefined4 FUN_c03b76ec(STRSAFE_LPWSTR param_1,size_t param_2,STRSAFE_LPCWSTR param_3)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  HVar1 = StringCchCopyW(param_1,param_2,param_3);
  if ((-1 < HVar1) && (*param_1 != L'\0')) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c03b7774 FUN_c03b7774 */

/* Boundary evidence: original MIPS .pdata c03b7774..c03b777f. Semantic name remains unreviewed. */

undefined4 FUN_c03b7774(void)

{
  return 1;
}



/* c03b7780 FUN_c03b7780 */

/* Boundary evidence: original MIPS .pdata c03b7780..c03b783f. Semantic name remains unreviewed. */

undefined4
FUN_c03b7780(int param_1,STRSAFE_LPCWSTR param_2,uint param_3,int param_4,int param_5,
            undefined4 param_6)

{
  int iVar1;
  DWORD dwErrCode;
  int iVar2;
  undefined4 uVar3;
  wchar_t awStack_60 [32];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  iVar2 = param_4;
  iVar1 = FUN_c03b76ec(awStack_60,0x20,param_2);
  if (iVar1 == 0) {
    dwErrCode = 0xa0;
  }
  else {
    dwErrCode = FUN_c03bb2c8(*(int *)(param_1 + 0x140),awStack_60,param_3 & 0xff,iVar2,param_5,
                             param_4,param_6);
    if (dwErrCode == 0) {
      uVar3 = 1;
      goto LAB_c03b7818;
    }
  }
  SetLastError(dwErrCode);
  uVar3 = 0;
LAB_c03b7818:
  FUN_c03c216c(local_20);
  return uVar3;
}



/* c03b7840 FUN_c03b7840 */

/* Boundary evidence: original MIPS .pdata c03b7840..c03b78c7. Semantic name remains unreviewed. */

undefined4 FUN_c03b7840(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  wchar_t awStack_50 [32];
  uint local_10;
  
  local_10 = DAT_c03c531c;
  iVar1 = FUN_c03b76ec(awStack_50,0x20,param_2);
  if (iVar1 == 0) {
    dwErrCode = 0xa0;
  }
  else {
    dwErrCode = FUN_c03bb3c4(*(int *)(param_1 + 0x140),awStack_50);
    if (dwErrCode == 0) {
      uVar2 = 1;
      goto LAB_c03b78ac;
    }
  }
  SetLastError(dwErrCode);
  uVar2 = 0;
LAB_c03b78ac:
  FUN_c03c216c(local_10);
  return uVar2;
}



/* c03b78c8 FUN_c03b78c8 */

/* Boundary evidence: original MIPS .pdata c03b78c8..c03b790b. Semantic name remains unreviewed. */

bool FUN_c03b78c8(int param_1)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03bb63c(*(int *)(param_1 + 0x140),*(int *)(param_1 + 0x144));
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b790c FUN_c03b790c */

/* Boundary evidence: original MIPS .pdata c03b790c..c03b7997. Semantic name remains unreviewed. */

undefined4 FUN_c03b790c(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  wchar_t awStack_50 [32];
  uint local_10;
  
  local_10 = DAT_c03c531c;
  iVar1 = FUN_c03b76ec(awStack_50,0x20,param_2);
  if (iVar1 == 0) {
    dwErrCode = 0xa0;
  }
  else {
    dwErrCode = FUN_c03bb8e8(*(int *)(param_1 + 0x140),*(int *)(param_1 + 0x144),awStack_50);
    if (dwErrCode == 0) {
      uVar2 = 1;
      goto LAB_c03b797c;
    }
  }
  SetLastError(dwErrCode);
  uVar2 = 0;
LAB_c03b797c:
  FUN_c03c216c(local_10);
  return uVar2;
}



/* c03b7998 FUN_c03b7998 */

/* Boundary evidence: original MIPS .pdata c03b7998..c03b79df. Semantic name remains unreviewed. */

bool FUN_c03b7998(int param_1,undefined4 param_2)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03bb998(*(int *)(param_1 + 0x140),*(int *)(param_1 + 0x144),param_2);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b79e0 FUN_c03b79e0 */

/* Boundary evidence: original MIPS .pdata c03b79e0..c03b7a2b. Semantic name remains unreviewed. */

bool FUN_c03b79e0(int param_1,uint param_2,undefined4 param_3)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03bba48(*(int *)(param_1 + 0x140),*(int *)(param_1 + 0x144),param_2 & 0xff,
                           param_3);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b7a2c FUN_c03b7a2c */

/* Boundary evidence: original MIPS .pdata c03b7a2c..c03b7a6b. Semantic name remains unreviewed. */

undefined4 FUN_c03b7a2c(void *param_1)

{
  FUN_c03bc314((int *)((int)param_1 + 0x10),FUN_c03b7618,0);
  operator_delete(param_1);
  return 1;
}



/* c03b7a6c FUN_c03b7a6c */

/* Boundary evidence: original MIPS .pdata c03b7a6c..c03b7adb. Semantic name remains unreviewed. */

undefined4 *
FUN_c03b7a6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 4;
  param_1[2] = param_3;
  *param_1 = param_4;
  param_1[1] = param_2;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  *puVar2 = puVar2;
  param_1[5] = puVar2;
  if ((param_1[2] != 1) && (iVar1 = __GetUserKData(0xc), param_1[1] == iVar1)) {
    param_1[2] = 2;
  }
  return param_1;
}



/* c03b7adc FUN_c03b7adc */

/* Boundary evidence: original MIPS .pdata c03b7adc..c03b7b13. Semantic name remains unreviewed. */

bool FUN_c03b7adc(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = _wcsicmp(param_2,(wchar_t *)(param_1 + -0xd90));
  return iVar1 == 0;
}



/* c03b7b14 FUN_c03b7b14 */

/* Boundary evidence: original MIPS .pdata c03b7b14..c03b7de3. Semantic name remains unreviewed. */

int FUN_c03b7b14(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  
  if (*param_1 != 0xf0) {
    DVar4 = 0xa0;
LAB_c03b7d8c:
    SetLastError(DVar4);
    return -1;
  }
  puVar1 = operator_new(0x148);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03b7a6c(puVar1,param_2,0,1);
  }
  if (puVar1 == (undefined4 *)0x0) {
    DVar4 = 0xe;
    goto LAB_c03b7d8c;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  puVar8 = DAT_c03c6140;
  if ((undefined4 **)DAT_c03c6140 != &DAT_c03c6140) {
    do {
      if (((puVar8[-0x1a2] & 4) == 0) && (puVar2 = operator_new(0x130), puVar2 != (undefined4 *)0x0)
         ) {
        FUN_c03b898c((int)(puVar8 + -0x36a),(int)(puVar2 + 2));
        puVar2[2] = 0xf0;
        puVar5 = (undefined4 *)puVar1[5];
        puVar2[1] = puVar5;
        *puVar2 = puVar1 + 4;
        *puVar5 = puVar2;
        puVar1[5] = puVar2;
      }
      puVar8 = (undefined4 *)*puVar8;
    } while ((undefined4 **)puVar8 != &DAT_c03c6140);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
  piVar7 = puVar1 + 4;
  piVar6 = (int *)*piVar7;
  if (piVar7 == piVar6) {
    operator_delete(puVar1);
    DVar4 = 0x103;
    goto LAB_c03b7d8c;
  }
  *(int *)(*piVar6 + 4) = piVar6[1];
  *(int *)piVar6[1] = *piVar6;
  piVar6[1] = (int)piVar6;
  *piVar6 = (int)piVar6;
  iVar3 = CeSafeCopyMemory(param_1,piVar6 + 2,0xf0);
  if (iVar3 == 0) {
    operator_delete(puVar1);
    DVar4 = 0xa0;
  }
  else {
    iVar3 = CreateAPIHandle(DAT_c03c536c,puVar1);
    if (iVar3 != 0) goto LAB_c03b7d50;
    FUN_c03bc314(piVar7,FUN_c03b7618,0);
    operator_delete(puVar1);
    DVar4 = 0x1f;
  }
  iVar3 = -1;
  SetLastError(DVar4);
LAB_c03b7d50:
  operator_delete(piVar6);
  return iVar3;
}



/* c03b7de4 FUN_c03b7de4 */

/* Boundary evidence: original MIPS .pdata c03b7de4..c03b7def. Semantic name remains unreviewed. */

undefined4 FUN_c03b7de4(void)

{
  return 1;
}



/* c03b7df0 FUN_c03b7df0 */

/* Boundary evidence: original MIPS .pdata c03b7df0..c03b7ea3. Semantic name remains unreviewed. */

undefined4 FUN_c03b7df0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_3 == 0xf0) {
    piVar1 = *(int **)(param_1 + 0x10);
    uVar2 = 0;
    if ((int *)(param_1 + 0x10) == piVar1) {
      SetLastError(0x103);
    }
    else {
      *(int *)(*piVar1 + 4) = piVar1[1];
      *(int *)piVar1[1] = *piVar1;
      piVar1[1] = (int)piVar1;
      *piVar1 = (int)piVar1;
      uVar2 = CeSafeCopyMemory(param_2,piVar1 + 2,0xf0);
      operator_delete(piVar1);
    }
  }
  else {
    SetLastError(0x57);
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b7ea4 FUN_c03b7ea4 */

/* Boundary evidence: original MIPS .pdata c03b7ea4..c03b7fab. Semantic name remains unreviewed. */

int FUN_c03b7ea4(STRSAFE_LPCWSTR param_1,undefined4 param_2)

{
  HRESULT HVar1;
  int iVar2;
  DWORD dwErrCode;
  undefined4 *puVar3;
  int iVar4;
  wchar_t awStack_30 [8];
  uint local_20;
  
  local_20 = DAT_c03c531c;
  iVar4 = -1;
  HVar1 = StringCchCopyW(awStack_30,8,param_1);
  if (HVar1 < 0) {
    dwErrCode = 0x57;
  }
  else {
    puVar3 = (undefined4 *)0x0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    iVar2 = FUN_c03bc29c(&DAT_c03c6140,FUN_c03b7adc,param_1);
    if (iVar2 != 0) {
      puVar3 = (undefined4 *)(iVar2 + -0xda8);
      InterlockedIncrement((LONG *)(iVar2 + -0x470));
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c5358);
    if (puVar3 != (undefined4 *)0x0) {
      iVar4 = FUN_c03ba8cc((int)puVar3,param_2);
      FUN_c03a6924(puVar3);
      goto LAB_c03b7f80;
    }
    dwErrCode = 0x10df;
  }
  SetLastError(dwErrCode);
LAB_c03b7f80:
  FUN_c03c216c(local_20);
  return iVar4;
}



/* c03b7fac FUN_c03b7fac */

/* Boundary evidence: original MIPS .pdata c03b7fac..c03b80bf. Semantic name remains unreviewed. */

undefined4 FUN_c03b7fac(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  int iVar3;
  
  dwErrCode = 0;
  iVar3 = *(int *)(param_1 + 0x140);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0xd18));
  if ((*(uint *)(iVar3 + 0x720) & 4) == 0) {
    if (*param_2 == 0xf0) {
      iVar1 = FUN_c03b898c(iVar3,(int)param_2);
      if (iVar1 == 0) {
        dwErrCode = 0x1f;
      }
    }
    else {
      dwErrCode = 0xa0;
    }
  }
  else {
    dwErrCode = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0xd18));
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b80c0 FUN_c03b80c0 */

/* Boundary evidence: original MIPS .pdata c03b80c0..c03b80cb. Semantic name remains unreviewed. */

undefined4 FUN_c03b80c0(void)

{
  return 1;
}



/* c03b80cc FUN_c03b80cc */

/* Boundary evidence: original MIPS .pdata c03b80cc..c03b815f. Semantic name remains unreviewed. */

bool FUN_c03b80cc(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD dwErrCode;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x140);
  dwErrCode = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xd18));
  if (((*(uint *)(iVar2 + 0x720) & 4) == 0) &&
     (bVar1 = FUN_c03bb114(iVar2,0), CONCAT31(extraout_var,bVar1) == 0)) {
    dwErrCode = 0x1f;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xd18));
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b8160 FUN_c03b8160 */

/* Boundary evidence: original MIPS .pdata c03b8160..c03b81a7. Semantic name remains unreviewed. */

int FUN_c03b8160(int param_1,undefined4 param_2)

{
  DWORD dwErrCode;
  int local_10 [2];
  
  local_10[0] = -1;
  dwErrCode = FUN_c03bb4c4(*(int *)(param_1 + 0x140),param_2,local_10,*(undefined4 *)(param_1 + 4));
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return local_10[0];
}



/* c03b81a8 FUN_c03b81a8 */

/* Boundary evidence: original MIPS .pdata c03b81a8..c03b8287. Semantic name remains unreviewed. */

HANDLE FUN_c03b81a8(int param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  DWORD dwErrCode;
  HANDLE pvVar2;
  HANDLE pvVar3;
  HANDLE local_60 [2];
  wchar_t awStack_58 [32];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  local_60[0] = (HANDLE)0xffffffff;
  iVar1 = FUN_c03b76ec(awStack_58,0x20,param_2);
  if (iVar1 == 0) {
    dwErrCode = 0xa0;
  }
  else {
    local_60[0] = (HANDLE)FUN_c03b8160(param_1,awStack_58);
    if (local_60[0] == (HANDLE)0xffffffff) goto LAB_c03b8268;
    pvVar2 = (HANDLE)__GetUserKData(0xc);
    pvVar3 = (HANDLE)GetCallerVMProcessId();
    iVar1 = FUN_c03acdac(pvVar2,local_60[0],pvVar3,local_60,0,0,3);
    if ((iVar1 != 0) || (dwErrCode = FUN_c03ac938(0xe), dwErrCode == 0)) goto LAB_c03b8268;
  }
  SetLastError(dwErrCode);
LAB_c03b8268:
  pvVar2 = local_60[0];
  FUN_c03c216c(local_18);
  return pvVar2;
}



/* c03b8288 FUN_c03b8288 */

/* Boundary evidence: original MIPS .pdata c03b8288..c03b831b. Semantic name remains unreviewed. */

bool FUN_c03b8288(int param_1)

{
  int iVar1;
  DWORD dwErrCode;
  
  iVar1 = *(int *)(param_1 + 0x140);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xd18));
  if ((*(uint *)(iVar1 + 0x720) & 4) == 0) {
    dwErrCode = FUN_c03bb58c(iVar1,*(int **)(param_1 + 0x144));
  }
  else {
    dwErrCode = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xd18));
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03b831c FUN_c03b831c */

/* Boundary evidence: original MIPS .pdata c03b831c..c03b8687. Semantic name remains unreviewed. */

undefined4
FUN_c03b831c(int param_1,int param_2,int param_3,uint param_4,undefined4 *param_5,uint param_6,
            int param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  int local_res8;
  uint local_resc;
  undefined4 auStack_48 [8];
  
  local_res8 = param_3;
  local_resc = param_4;
  iVar2 = __GetUserKData(0xc);
  iVar3 = GetDirectCallerProcessId();
  if (iVar3 == iVar2) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (param_2 == 2) {
LAB_c03b8494:
      dwErrCode = FUN_c03beae0(&local_res8,param_3,param_4,8,auStack_48,8);
    }
    else {
      if (param_2 != 3) {
        if (param_2 == 0x24c04) {
          dwErrCode = FUN_c03bed74(&local_res8,param_3,param_4,8,auStack_48,8);
          goto joined_r0xc03b843c;
        }
        if (param_2 == 0x75c08) goto LAB_c03b8494;
        if (param_2 != 0x79c0c) goto LAB_c03b84d0;
      }
      dwErrCode = FUN_c03beae0(&local_res8,param_3,param_4,4,auStack_48,8);
    }
joined_r0xc03b843c:
    if (dwErrCode != 0) goto LAB_c03b8624;
  }
LAB_c03b84d0:
  dwErrCode = FUN_c03bbd10(*(int **)(param_1 + 0x140),*(int **)(param_1 + 0x144),param_2,local_res8,
                           param_4,param_5,param_6,param_7);
  if (bVar1) goto LAB_c03b8624;
  if (param_2 == 2) {
LAB_c03b85e8:
    FUN_c03bec9c(local_res8,param_3,param_4,8,auStack_48,8);
  }
  else {
    if (param_2 != 3) {
      if (param_2 == 0x24c04) {
        FUN_c03bef5c(local_res8,param_3,param_4,8,auStack_48,8);
        goto LAB_c03b8624;
      }
      if (param_2 == 0x75c08) goto LAB_c03b85e8;
      if (param_2 != 0x79c0c) goto LAB_c03b8624;
    }
    FUN_c03bec9c(local_res8,param_3,param_4,4,auStack_48,8);
  }
LAB_c03b8624:
  uVar4 = 1;
  if ((dwErrCode != 0) && (SetLastError(dwErrCode), dwErrCode != 0)) {
    uVar4 = 0;
  }
  return uVar4;
}



/* c03b8688 FUN_c03b8688 */

/* Boundary evidence: original MIPS .pdata c03b8688..c03b8693. Semantic name remains unreviewed. */

undefined4 FUN_c03b8688(void)

{
  return 1;
}



/* c03b8694 FUN_c03b8694 */

/* Boundary evidence: original MIPS .pdata c03b8694..c03b87a3. Semantic name remains unreviewed. */

undefined4 FUN_c03b8694(int param_1,int *param_2)

{
  undefined4 uVar1;
  DWORD dwErrCode;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x140);
  EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xd18));
  if ((*(uint *)(iVar2 + 0x720) & 4) == 0) {
    if (*param_2 == 0x128) {
      dwErrCode = FUN_c03b9004(iVar2,*(int *)(param_1 + 0x144),(int)param_2);
    }
    else {
      dwErrCode = 0xa0;
    }
  }
  else {
    dwErrCode = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0xd18));
  if ((dwErrCode == 0) || (SetLastError(dwErrCode), dwErrCode == 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c03b87a4 FUN_c03b87a4 */

/* Boundary evidence: original MIPS .pdata c03b87a4..c03b87af. Semantic name remains unreviewed. */

undefined4 FUN_c03b87a4(void)

{
  return 1;
}



/* c03b87b0 FUN_c03b87b0 */

/* Boundary evidence: original MIPS .pdata c03b87b0..c03b8843. Semantic name remains unreviewed. */

int FUN_c03b87b0(int param_1,int *param_2)

{
  DWORD dwErrCode;
  int local_c;
  
  local_c = -1;
  if (*param_2 == 0x128) {
    dwErrCode = FUN_c03bbb08(*(int *)(param_1 + 0x140),param_2,&local_c,*(undefined4 *)(param_1 + 4)
                            );
  }
  else {
    dwErrCode = 0xa0;
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return local_c;
}



/* c03b8844 FUN_c03b8844 */

/* Boundary evidence: original MIPS .pdata c03b8844..c03b884f. Semantic name remains unreviewed. */

undefined4 FUN_c03b8844(void)

{
  return 1;
}



/* c03b8850 FUN_c03b8850 */

/* Boundary evidence: original MIPS .pdata c03b8850..c03b88cf. Semantic name remains unreviewed. */

HANDLE FUN_c03b8850(int param_1,int *param_2)

{
  HANDLE pvVar1;
  HANDLE pvVar2;
  int iVar3;
  HANDLE pvVar4;
  HANDLE local_18 [2];
  
  local_18[0] = (HANDLE)FUN_c03b87b0(param_1,param_2);
  pvVar4 = (HANDLE)0xffffffff;
  if (local_18[0] != (HANDLE)0xffffffff) {
    pvVar1 = (HANDLE)__GetUserKData(0xc);
    pvVar2 = (HANDLE)GetCallerVMProcessId();
    iVar3 = FUN_c03acdac(pvVar1,local_18[0],pvVar2,local_18,0,0,3);
    if (iVar3 != 0) {
      pvVar4 = local_18[0];
    }
  }
  return pvVar4;
}



/* c03b88d0 FUN_c03b88d0 */

/* Boundary evidence: original MIPS .pdata c03b88d0..c03b898b. Semantic name remains unreviewed. */

undefined4 FUN_c03b88d0(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  DWORD dwErrCode;
  
  dwErrCode = 0x57;
  if (0x127 < param_3) {
    piVar2 = *(int **)(param_1 + 0x10);
    if ((int *)(param_1 + 0x10) == piVar2) {
      dwErrCode = 0x103;
    }
    else {
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      piVar2[1] = (int)piVar2;
      *piVar2 = (int)piVar2;
      iVar1 = CeSafeCopyMemory(param_2,piVar2 + 2,0x128);
      dwErrCode = 0;
      if (iVar1 == 0) {
        dwErrCode = 0xa0;
      }
      operator_delete(piVar2);
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03b898c FUN_c03b898c */

/* Boundary evidence: original MIPS .pdata c03b898c..c03b8ab7. Semantic name remains unreviewed. */

undefined4 FUN_c03b898c(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0xe0) = *(undefined4 *)(param_1 + 0xd10);
  *(undefined4 *)(param_2 + 200) = *(undefined4 *)(param_1 + 0xcf8);
  *(undefined4 *)(param_2 + 0xcc) = *(undefined4 *)(param_1 + 0xcfc);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_1 + 0xce8);
  *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(param_1 + 0xcf0);
  *(undefined4 *)(param_2 + 0xc4) = *(undefined4 *)(param_1 + 0xcf4);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_1 + 0xce0);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_1 + 0xce4);
  *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(param_1 + 0x710);
  *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_1 + 0x714);
  *(undefined4 *)(param_2 + 0x54) = *(undefined4 *)(param_1 + 0xd70);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_1 + 0xd78);
  *(undefined4 *)(param_2 + 0x58) = *(undefined4 *)(param_1 + 0xd74);
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 4),8,(STRSAFE_LPCWSTR)(param_1 + 0x18));
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x14),0x20,(STRSAFE_LPCWSTR)(param_1 + 0x28));
  *(undefined4 *)(param_2 + 0xd0) = *(undefined4 *)(param_1 + 0xd00);
  *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(param_1 + 0xd04);
  *(undefined4 *)(param_2 + 0xd8) = *(undefined4 *)(param_1 + 0xd08);
  *(undefined4 *)(param_2 + 0xdc) = *(undefined4 *)(param_1 + 0xd0c);
  memcpy((void *)(param_2 + 0x5c),(void *)(param_1 + 0xd2c),0x50);
  return 1;
}



/* c03b8ab8 FUN_c03b8ab8 */

/* Boundary evidence: original MIPS .pdata c03b8ab8..c03b8ac3. Semantic name remains unreviewed. */

undefined4 FUN_c03b8ab8(void)

{
  return 1;
}



/* c03b8ac4 FUN_c03b8ac4 */

/* Boundary evidence: original MIPS .pdata c03b8ac4..c03b8cb7. Semantic name remains unreviewed. */

undefined4 FUN_c03b8ac4(int param_1,HKEY param_2,HKEY param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  HKEY local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c03c531c;
  iVar2 = 0;
  iVar3 = 0;
  if (param_3 == (HKEY)0x0) {
LAB_c03b8b58:
    if (param_2 != (HKEY)0x0) {
      iVar3 = FUN_c03acbc4(param_2,(LPCWSTR)PTR_u_PartitionDriverName_c03c5290,
                           (STRSAFE_LPWSTR)(param_1 + 0xa8),0x20);
LAB_c03b8b7c:
      if (iVar3 != 0) {
        if (iVar2 != 0) goto LAB_c03b8c4c;
        goto LAB_c03b8b8c;
      }
LAB_c03b8c30:
      if (iVar2 != 0) goto LAB_c03b8c4c;
    }
  }
  else {
    iVar3 = FUN_c03acbc4(param_3,(LPCWSTR)PTR_u_PartitionDriverName_c03c5290,
                         (STRSAFE_LPWSTR)(param_1 + 0xa8),0x20);
    if (iVar3 == 0) {
      iVar2 = FUN_c03acbc4(param_3,(LPCWSTR)PTR_u_PartitionDriver_c03c5288,
                           (STRSAFE_LPWSTR)(param_1 + 0xe8),0x104);
      if (iVar2 == 0) goto LAB_c03b8b58;
      goto LAB_c03b8b7c;
    }
LAB_c03b8b8c:
    if ((param_3 != (HKEY)0x0) &&
       (iVar2 = FUN_c03acd00(param_3,(LPCWSTR)(param_1 + 0xa8),local_238), iVar2 == 0)) {
      iVar2 = FUN_c03acbc4(local_238[0],(LPCWSTR)PTR_DAT_c03c528c,(STRSAFE_LPWSTR)(param_1 + 0xe8),
                           0x104);
      FUN_c03acd64(local_238[0]);
      if (iVar2 != 0) goto LAB_c03b8c4c;
    }
    if (param_2 != (HKEY)0x0) {
      StringCchPrintfW(awStack_230,0x104,L"%s\\%s",PTR_u_System_StorageManager_c03c5264,
                       (LPCWSTR)(param_1 + 0xa8));
      iVar2 = FUN_c03acd2c(awStack_230,local_238);
      if (iVar2 == 0) {
        iVar2 = FUN_c03acbc4(local_238[0],(LPCWSTR)PTR_DAT_c03c528c,(STRSAFE_LPWSTR)(param_1 + 0xe8)
                             ,0x104);
        FUN_c03acd64(local_238[0]);
        goto LAB_c03b8c30;
      }
    }
  }
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xe8),0x104,(STRSAFE_LPCWSTR)PTR_u_mspart_dll_c03c52f4);
LAB_c03b8c4c:
  if (iVar3 == 0) {
    StringCbCopyW((STRSAFE_LPWSTR)(param_1 + 0xa8),0x40,(STRSAFE_LPCWSTR)(param_1 + 0xe8));
    pwVar1 = wcsstr((STRSAFE_LPWSTR)(param_1 + 0xa8),L".");
    if (pwVar1 != (wchar_t *)0x0) {
      *pwVar1 = L'\0';
    }
  }
  FUN_c03c216c(local_28);
  return 1;
}



/* c03b8cb8 FUN_c03b8cb8 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c03b8cb8..c03b8f73. Semantic name remains unreviewed. */

int FUN_c03b8cb8(HANDLE param_1,SIZE_T param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  byte local_50 [4];
  DWORD local_4c;
  int local_48 [5];
  char *local_34;
  SIZE_T local_30;
  
  local_50[0] = 0x27;
  local_50[1] = 0x27;
  local_50[2] = 0x43;
  local_50[3] = 100;
  local_4c = 0;
  local_48[0] = 0;
  iVar5 = 0;
  iVar6 = 0;
  memset(local_48 + 1,0,0x18);
  pcVar2 = LocalAlloc(0x40,param_2);
  local_48[0] = 0;
  local_48[1] = 1;
  local_48[2] = 1;
  local_48[3] = 0;
  local_48[4] = 0;
  if (pcVar2 != (char *)0x0) {
    local_34 = pcVar2;
    local_30 = param_2;
    DeviceIoControl(param_1,0x75c08,local_48,0x1c,(LPVOID)0x0,0,&local_4c,(LPOVERLAPPED)0x0);
    if ((uint)(byte)pcVar2[0x1fe] * 0x100 + (uint)(byte)pcVar2[0x1ff] == 0x55aa) {
      local_48[0] = (((uint)(byte)pcVar2[0x1c9] * 0x100 + (uint)(byte)pcVar2[0x1c8]) * 0x100 +
                    (uint)(byte)pcVar2[0x1c7]) * 0x100 + (uint)(byte)pcVar2[0x1c6];
      DeviceIoControl(param_1,0x75c08,local_48,0x1c,(LPVOID)0x0,0,&local_4c,(LPOVERLAPPED)0x0);
      if ((uint)(byte)pcVar2[0x1fe] * 0x100 + (uint)(byte)pcVar2[0x1ff] == 0x55aa) {
        cVar1 = *pcVar2;
        if (((cVar1 != -0x15) && (cVar1 != -0x17)) && (cVar1 != 'i')) {
          local_48[0] = local_48[0] + 1;
          DeviceIoControl(param_1,0x75c08,local_48,0x1c,(LPVOID)0x0,0,&local_4c,(LPOVERLAPPED)0x0);
        }
        if (pcVar2[0xd] == '\0') {
          iVar5 = 3;
        }
        else if ((uint)(byte)pcVar2[0x12] * 0x100 + (uint)(byte)pcVar2[0x11] == 0) {
          iVar5 = 2;
        }
        else {
          uVar3 = (uint)(byte)pcVar2[0x14] * 0x100 + (uint)(byte)pcVar2[0x13];
          if (uVar3 == 0) {
            uVar3 = (((uint)(byte)pcVar2[0x23] * 0x100 + (uint)(byte)pcVar2[0x22]) * 0x100 +
                    (uint)(byte)pcVar2[0x21]) * 0x100 + (uint)(byte)pcVar2[0x20];
          }
          if (0x7fa8 < uVar3) {
            iVar5 = 1;
          }
        }
        pbVar4 = (byte *)(pcVar2 + local_50[iVar5]);
        iVar6 = (((uint)pbVar4[1] + (uint)*pbVar4 * 0x100) * 0x100 + (uint)pbVar4[2]) * 0x100 +
                (uint)pbVar4[3];
      }
    }
  }
  return iVar6;
}



/* c03b8f74 FUN_c03b8f74 */

/* Boundary evidence: original MIPS .pdata c03b8f74..c03b8fbb. Semantic name remains unreviewed. */

void FUN_c03b8f74(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0xcd0); (int *)(param_1 + 0xcd0) != piVar1;
      piVar1 = (int *)*piVar1) {
    FUN_c03bff94((int)(piVar1 + -0xe4));
  }
  return;
}



/* c03b8fbc FUN_c03b8fbc */

/* Boundary evidence: original MIPS .pdata c03b8fbc..c03b9003. Semantic name remains unreviewed. */

void FUN_c03b8fbc(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0xcd0); (int *)(param_1 + 0xcd0) != piVar1;
      piVar1 = (int *)*piVar1) {
    FUN_c03bffe4((int)(piVar1 + -0xe4));
  }
  return;
}



/* c03b9004 FUN_c03b9004 */

/* Boundary evidence: original MIPS .pdata c03b9004..c03b906b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9004(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_c03bfc00(param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0xa0;
  }
  else {
    iVar1 = FUN_c03b8cb8(*(HANDLE *)(param_1 + 0xda0),*(SIZE_T *)(param_1 + 0xd80));
    if (iVar1 != 0) {
      *(int *)(param_1 + 0xd9c) = iVar1;
    }
  }
  return uVar2;
}



/* c03b906c FUN_c03b906c */

/* Boundary evidence: original MIPS .pdata c03b906c..c03b9103. Semantic name remains unreviewed. */

undefined4 FUN_c03b906c(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18 [2];
  
  uVar2 = 0;
  if (*(uint **)(param_1 + 0x934) == (uint *)0x0) {
    return 0x32;
  }
  local_18[0] = **(uint **)(param_1 + 0x934);
  if (param_3 < local_18[0]) {
    uVar2 = 0x7a;
  }
  else {
    iVar1 = CeSafeCopyMemory(param_2);
    if (iVar1 == 0) {
      return 0x57;
    }
    param_2 = param_4;
    if (param_4 == 0) {
      return 0;
    }
  }
  iVar1 = CeSafeCopyMemory(param_2,local_18,4);
  if (iVar1 == 0) {
    return 0x57;
  }
  return uVar2;
}



/* c03b9104 FUN_c03b9104 */

/* Boundary evidence: original MIPS .pdata c03b9104..c03b917b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9104(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  local_18[0] = 0x50;
  uVar2 = 0;
  iVar1 = CeSafeCopyMemory(param_2,param_1 + 0xd2c,0x50);
  if ((iVar1 == 0) || ((param_3 != 0 && (iVar1 = CeSafeCopyMemory(param_3,local_18,4), iVar1 == 0)))
     ) {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* c03b917c FUN_c03b917c */

/* Boundary evidence: original MIPS .pdata c03b917c..c03b91fb. Semantic name remains unreviewed. */

void FUN_c03b917c(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (param_2 == (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1,param_3,param_4,param_5,param_6,param_7,param_8,0);
  }
  else {
    (**(code **)(*param_2 + 4))(param_2);
  }
  return;
}



/* c03b91fc FUN_c03b91fc */

/* Boundary evidence: original MIPS .pdata c03b91fc..c03b9223. Semantic name remains unreviewed. */

void FUN_c03b91fc(int param_1)

{
  if (*(int *)(param_1 + 0x92c) != 0) {
    EventModify(*(int *)(param_1 + 0x92c),3);
  }
  return;
}



/* c03b9224 FUN_c03b9224 */

/* Boundary evidence: original MIPS .pdata c03b9224..c03b9263. Semantic name remains unreviewed. */

undefined4 FUN_c03b9224(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
  HVar1 = StringCchCopyW(param_2,param_3,(STRSAFE_LPCWSTR)(param_1 + 0x18));
  if (HVar1 < 0) {
    uVar2 = 0x7a;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03b926c FUN_c03b926c */

/* Boundary evidence: original MIPS .pdata c03b926c..c03b92cf. Semantic name remains unreviewed. */

undefined4 * FUN_c03b926c(undefined4 *param_1,STRSAFE_LPCWSTR param_2)

{
  *param_1 = &PTR_FUN_c03a2ac4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0x8d] = 0;
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xb),0x104,param_2);
  return param_1;
}



/* c03b92d0 FUN_c03b92d0 */

/* Boundary evidence: original MIPS .pdata c03b92d0..c03b9373. Semantic name remains unreviewed. */

void FUN_c03b92d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03a2ac4;
  if (param_1[1] != 0) {
    if (((code *)param_1[5] != (code *)0x0) && (param_1[2] != 0)) {
      (*(code *)param_1[5])();
    }
    FreeLibrary((HMODULE)param_1[1]);
  }
  if ((void *)param_1[0x8d] != (void *)0x0) {
    operator_delete((void *)param_1[0x8d]);
  }
  return;
}



/* c03b9374 FUN_c03b9374 */

/* Boundary evidence: original MIPS .pdata c03b9374..c03b939b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9374(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b939c FUN_c03b939c */

/* Boundary evidence: original MIPS .pdata c03b939c..c03b93e7. Semantic name remains unreviewed. */

undefined4 * FUN_c03b939c(undefined4 *param_1,uint param_2)

{
  FUN_c03b92d0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03b93e8 FUN_c03b93e8 */

/* Boundary evidence: original MIPS .pdata c03b93e8..c03b9447. Semantic name remains unreviewed. */

void FUN_c03b93e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(param_1 + 8))(param_2,param_3);
  return;
}



/* c03b9448 FUN_c03b9448 */

/* Boundary evidence: original MIPS .pdata c03b9448..c03b946f. Semantic name remains unreviewed. */

undefined4 FUN_c03b9448(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9470 FUN_c03b9470 */

/* Boundary evidence: original MIPS .pdata c03b9470..c03b94b3. Semantic name remains unreviewed. */

void FUN_c03b9470(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0xc))(param_2);
  return;
}



/* c03b94b4 FUN_c03b94b4 */

/* Boundary evidence: original MIPS .pdata c03b94b4..c03b94db. Semantic name remains unreviewed. */

undefined4 FUN_c03b94b4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b94dc FUN_c03b94dc */

/* Boundary evidence: original MIPS .pdata c03b94dc..c03b9533. Semantic name remains unreviewed. */

void FUN_c03b94dc(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x10))(param_2);
  return;
}



/* c03b9534 FUN_c03b9534 */

/* Boundary evidence: original MIPS .pdata c03b9534..c03b955b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9534(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b955c FUN_c03b955c */

/* Boundary evidence: original MIPS .pdata c03b955c..c03b95b3. Semantic name remains unreviewed. */

void FUN_c03b955c(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x14))(param_2);
  return;
}



/* c03b95b4 FUN_c03b95b4 */

/* Boundary evidence: original MIPS .pdata c03b95b4..c03b95db. Semantic name remains unreviewed. */

undefined4 FUN_c03b95b4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b95dc FUN_c03b95dc */

/* Boundary evidence: original MIPS .pdata c03b95dc..c03b963b. Semantic name remains unreviewed. */

void FUN_c03b95dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(param_1 + 0x18))(param_2,param_3);
  return;
}



/* c03b963c FUN_c03b963c */

/* Boundary evidence: original MIPS .pdata c03b963c..c03b9663. Semantic name remains unreviewed. */

undefined4 FUN_c03b963c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9664 FUN_c03b9664 */

/* Boundary evidence: original MIPS .pdata c03b9664..c03b96e3. Semantic name remains unreviewed. */

void FUN_c03b9664(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  (**(code **)(param_1 + 0x1c))(param_2,param_3,param_4,param_4,param_5,param_6,param_7);
  return;
}



/* c03b96e4 FUN_c03b96e4 */

/* Boundary evidence: original MIPS .pdata c03b96e4..c03b970b. Semantic name remains unreviewed. */

undefined4 FUN_c03b96e4(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b970c FUN_c03b970c */

/* Boundary evidence: original MIPS .pdata c03b970c..c03b976b. Semantic name remains unreviewed. */

void FUN_c03b970c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(param_1 + 0x20))(param_2,param_3);
  return;
}



/* c03b976c FUN_c03b976c */

/* Boundary evidence: original MIPS .pdata c03b976c..c03b9793. Semantic name remains unreviewed. */

undefined4 FUN_c03b976c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9794 FUN_c03b9794 */

/* Boundary evidence: original MIPS .pdata c03b9794..c03b97fb. Semantic name remains unreviewed. */

void FUN_c03b9794(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x28))(param_2,param_3,param_4);
  return;
}



/* c03b97fc FUN_c03b97fc */

/* Boundary evidence: original MIPS .pdata c03b97fc..c03b9823. Semantic name remains unreviewed. */

undefined4 FUN_c03b97fc(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9824 FUN_c03b9824 */

/* Boundary evidence: original MIPS .pdata c03b9824..c03b9893. Semantic name remains unreviewed. */

void FUN_c03b9824(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(param_1 + 0x30))(param_2,param_3,param_4,param_5);
  return;
}



/* c03b9894 FUN_c03b9894 */

/* Boundary evidence: original MIPS .pdata c03b9894..c03b98bb. Semantic name remains unreviewed. */

undefined4 FUN_c03b9894(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b98bc FUN_c03b98bc */

/* Boundary evidence: original MIPS .pdata c03b98bc..c03b9923. Semantic name remains unreviewed. */

void FUN_c03b98bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x34))(param_2,param_3,param_4);
  return;
}



/* c03b9924 FUN_c03b9924 */

/* Boundary evidence: original MIPS .pdata c03b9924..c03b994b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9924(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b994c FUN_c03b994c */

/* Boundary evidence: original MIPS .pdata c03b994c..c03b99ab. Semantic name remains unreviewed. */

void FUN_c03b994c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(param_1 + 0x38))(param_2,param_3);
  return;
}



/* c03b99ac FUN_c03b99ac */

/* Boundary evidence: original MIPS .pdata c03b99ac..c03b99d3. Semantic name remains unreviewed. */

undefined4 FUN_c03b99ac(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b99d4 FUN_c03b99d4 */

/* Boundary evidence: original MIPS .pdata c03b99d4..c03b9a33. Semantic name remains unreviewed. */

void FUN_c03b99d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(param_1 + 0x3c))(param_2,param_3);
  return;
}



/* c03b9a34 FUN_c03b9a34 */

/* Boundary evidence: original MIPS .pdata c03b9a34..c03b9a5b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9a34(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9a5c FUN_c03b9a5c */

/* Boundary evidence: original MIPS .pdata c03b9a5c..c03b9a9f. Semantic name remains unreviewed. */

void FUN_c03b9a5c(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x40))(param_2);
  return;
}



/* c03b9aa0 FUN_c03b9aa0 */

/* Boundary evidence: original MIPS .pdata c03b9aa0..c03b9ac7. Semantic name remains unreviewed. */

undefined4 FUN_c03b9aa0(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9ac8 FUN_c03b9ac8 */

/* Boundary evidence: original MIPS .pdata c03b9ac8..c03b9b2f. Semantic name remains unreviewed. */

void FUN_c03b9ac8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x44))(param_2,param_3,param_4);
  return;
}



/* c03b9b30 FUN_c03b9b30 */

/* Boundary evidence: original MIPS .pdata c03b9b30..c03b9b57. Semantic name remains unreviewed. */

undefined4 FUN_c03b9b30(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9b58 FUN_c03b9b58 */

/* Boundary evidence: original MIPS .pdata c03b9b58..c03b9b9b. Semantic name remains unreviewed. */

void FUN_c03b9b58(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x48))(param_2);
  return;
}



/* c03b9b9c FUN_c03b9b9c */

/* Boundary evidence: original MIPS .pdata c03b9b9c..c03b9bc3. Semantic name remains unreviewed. */

undefined4 FUN_c03b9b9c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9bc4 FUN_c03b9bc4 */

/* Boundary evidence: original MIPS .pdata c03b9bc4..c03b9c3b. Semantic name remains unreviewed. */

undefined4 FUN_c03b9bc4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x58) == (code *)0x0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x58))(param_2,param_3,param_4);
  }
  return uVar1;
}



/* c03b9c3c FUN_c03b9c3c */

/* Boundary evidence: original MIPS .pdata c03b9c3c..c03b9c63. Semantic name remains unreviewed. */

undefined4 FUN_c03b9c3c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03b9c64 FUN_c03b9c64 */

/* Boundary evidence: original MIPS .pdata c03b9c64..c03b9d57. Semantic name remains unreviewed. */

void FUN_c03b9c64(int param_1,undefined4 param_2,HANDLE param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPVOID param_7,DWORD param_8,LPDWORD param_9,LPOVERLAPPED param_10)

{
  if (*(code **)(param_1 + 0x5c) != (code *)0x0) {
    (**(code **)(param_1 + 0x5c))(param_2,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
    return;
  }
  if (param_5 == (LPVOID)0x0) {
    if (param_7 == (LPVOID)0x0) goto LAB_c03b9ccc;
  }
  else if ((int)param_5 < 0) goto LAB_c03b9ccc;
  if ((param_7 == (LPVOID)0x0) || (-1 < (int)param_7)) {
    ForwardDeviceIoControl(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
    return;
  }
LAB_c03b9ccc:
  DeviceIoControl(param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}



/* c03b9d58 FUN_c03b9d58 */

/* Boundary evidence: original MIPS .pdata c03b9d58..c03b9dbf. Semantic name remains unreviewed. */

undefined4 * FUN_c03b9d58(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03a2ad8;
  if ((HMODULE)param_1[1] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03b9dc0 FUN_c03b9dc0 */

/* Boundary evidence: original MIPS .pdata c03b9dc0..c03b9e1b. Semantic name remains unreviewed. */

LONG FUN_c03b9dc0(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0xbf);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* c03b9e1c FUN_c03b9e1c */

/* Boundary evidence: original MIPS .pdata c03b9e1c..c03b9e73. Semantic name remains unreviewed. */

bool FUN_c03b9e1c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_c03b9794(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 0x388),param_1 + 0x340,
                       param_2);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x20) = param_2;
  }
  return iVar1 == 0;
}



/* c03b9e74 FUN_c03b9e74 */

/* Boundary evidence: original MIPS .pdata c03b9e74..c03b9f23. Semantic name remains unreviewed. */

undefined4 * FUN_c03b9e74(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_FUN_c03a2adc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0xffffffff;
  param_1[0x1c4] = 0;
  param_1[0x1c5] = 0;
  param_1[0x1c6] = 0;
  param_1[0x1c7] = 0;
  param_1[0x1c8] = 4;
  param_1[0x24b] = 0;
  param_1[0x24c] = 0;
  param_1[0x24d] = 0;
  param_1[0x24f] = 0;
  FUN_c03bfaf0(param_1 + 0x250);
  param_1[0x365] = 0;
  param_1[0x366] = 0;
  param_1[0x367] = 0;
  param_1[0x368] = 0xffffffff;
  param_1[0x369] = 0xffffffff;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
  puVar1 = param_1 + 0x36a;
  *puVar1 = puVar1;
  param_1[0x36b] = puVar1;
  param_1[0x24e] = 1;
  param_1[4] = 1;
  return param_1;
}



/* c03b9f24 FUN_c03b9f24 */

/* Boundary evidence: original MIPS .pdata c03b9f24..c03ba087. Semantic name remains unreviewed. */

undefined4 * FUN_c03b9f24(undefined4 *param_1,STRSAFE_LPCWSTR param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_FUN_c03a2adc;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0xffffffff;
  param_1[0x1c4] = 0;
  param_1[0x1c5] = 0;
  param_1[0x1c6] = 0;
  param_1[0x1c7] = 0;
  param_1[0x1c8] = 4;
  param_1[0x24b] = 0;
  param_1[0x24c] = 0;
  param_1[0x24d] = 0;
  param_1[0x24f] = 0;
  FUN_c03bfaf0(param_1 + 0x250);
  param_1[0x365] = 0;
  param_1[0x366] = 0;
  param_1[0x367] = 0;
  param_1[0x368] = 0xffffffff;
  param_1[0x369] = 0xffffffff;
  memset(param_1 + 0x336,0,0x40);
  memset(param_1 + 0x34b,0,0x50);
  param_1[0x1c0] = *param_3;
  param_1[0x1c1] = param_3[1];
  param_1[0x1c2] = param_3[2];
  param_1[0x1c3] = param_3[3];
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined2 *)(param_1 + 0x2a) = 0;
  *(undefined2 *)(param_1 + 0xbc) = 0;
  *(undefined2 *)(param_1 + 0x1c9) = 0;
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 6),8,param_2);
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 10),0x20,
                 (STRSAFE_LPCWSTR)PTR_u_External_Storage_c03c52fc);
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x13e),0x104,(STRSAFE_LPCWSTR)PTR_u_FATFS_c03c52f8);
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x1a),0x20,
                 (STRSAFE_LPCWSTR)PTR_u_Mounted_Volume_c03c5300);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
  puVar1 = param_1 + 0x36a;
  *puVar1 = puVar1;
  param_1[0x36b] = puVar1;
  param_1[0x24e] = 1;
  param_1[4] = 1;
  return param_1;
}



/* c03ba088 FUN_c03ba088 */

/* Boundary evidence: original MIPS .pdata c03ba088..c03ba0e7. Semantic name remains unreviewed. */

void FUN_c03ba088(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x93c) != 0) {
    if (*(int *)(param_1 + 0xd98) != 0) {
      FUN_c03b9470(*(int *)(param_1 + 0x93c),*(int *)(param_1 + 0xd98));
    }
    puVar1 = *(undefined4 **)(param_1 + 0x93c);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    *(undefined4 *)(param_1 + 0x93c) = 0;
  }
  return;
}



/* c03ba0e8 FUN_c03ba0e8 */

/* Boundary evidence: original MIPS .pdata c03ba0e8..c03ba183. Semantic name remains unreviewed. */

void FUN_c03ba0e8(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_FUN_c03a2adc;
  FUN_c03ba088((int)param_1);
  if ((void *)param_1[0x24d] != (void *)0x0) {
    operator_delete((void *)param_1[0x24d]);
  }
  puVar1 = (undefined4 *)param_1[0x365];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x365] = 0;
  }
  if ((HANDLE)param_1[0x24b] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x24b]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x346));
  FUN_c03bfb9c(param_1 + 0x250);
  FUN_c03b0f88(param_1);
  return;
}



/* c03ba184 FUN_c03ba184 */

/* Boundary evidence: original MIPS .pdata c03ba184..c03ba1eb. Semantic name remains unreviewed. */

bool FUN_c03ba184(int param_1,STRSAFE_LPCWSTR param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x238);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03b926c(puVar1,param_2);
  }
  *(undefined4 **)(param_1 + 0xd94) = puVar1;
  return puVar1 != (undefined4 *)0x0;
}



/* c03ba1ec FUN_c03ba1ec */

/* Boundary evidence: original MIPS .pdata c03ba1ec..c03ba657. Semantic name remains unreviewed. */

undefined4 FUN_c03ba1ec(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  HKEY local_28;
  HKEY local_24;
  uint local_20 [2];
  
  uVar3 = 0;
  local_24 = (HKEY)0x0;
  local_28 = (HKEY)0x0;
  iVar1 = FUN_c03acd2c((LPCWSTR)PTR_u_System_StorageManager_Profiles_c03c5268,&local_24);
  if (iVar1 == 0) {
    StringCchPrintfW((LPCWSTR)(param_1 + 0x2f0),0x104,L"%s\\%s",
                     PTR_u_System_StorageManager_Profiles_c03c5268,param_1 + 0xd30);
    iVar1 = FUN_c03acd2c((LPCWSTR)(param_1 + 0x2f0),&local_28);
    if (iVar1 != 0) {
      local_28 = (HKEY)0x0;
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acde4(local_28,(LPCWSTR)PTR_u_AutoMount_c03c5280,(uint *)(param_1 + 0x71c),
                             0x20), iVar1 == 0)) {
      puVar2 = (uint *)(param_1 + 0x71c);
      iVar1 = FUN_c03acde4(local_24,(LPCWSTR)PTR_u_AutoMount_c03c5280,puVar2,0x20);
      if (iVar1 == 0) {
        *puVar2 = *puVar2 | 0x20;
      }
    }
    puVar2 = (uint *)(param_1 + 0x71c);
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acde4(local_28,(LPCWSTR)PTR_u_AutoFormat_c03c5284,puVar2,8), iVar1 == 0)) {
      FUN_c03acde4(local_24,(LPCWSTR)PTR_u_AutoFormat_c03c5284,puVar2,8);
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acde4(local_28,(LPCWSTR)PTR_u_AutoPart_c03c527c,puVar2,0x10), iVar1 == 0)) {
      FUN_c03acde4(local_24,(LPCWSTR)PTR_u_AutoPart_c03c527c,puVar2,0x10);
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acbc4(local_28,(LPCWSTR)PTR_u_DefaultFileSystem_c03c5298,
                             (STRSAFE_LPWSTR)(param_1 + 0x4f8),0x104), iVar1 == 0)) {
      iVar1 = FUN_c03acbc4(local_24,(LPCWSTR)PTR_u_DefaultFileSystem_c03c5298,
                           (STRSAFE_LPWSTR)(param_1 + 0x4f8),0x104);
      if (iVar1 == 0) {
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x4f8),0x104,(STRSAFE_LPCWSTR)PTR_u_FATFS_c03c52f8
                      );
      }
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acbc4(local_28,(LPCWSTR)PTR_u_Folder_c03c52b4,
                             (STRSAFE_LPWSTR)(param_1 + 0x68),0x20), iVar1 == 0)) {
      iVar1 = FUN_c03acbc4(local_24,(LPCWSTR)PTR_u_Folder_c03c52b4,(STRSAFE_LPWSTR)(param_1 + 0x68),
                           0x20);
      if (iVar1 == 0) {
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x68),0x20,
                       (STRSAFE_LPCWSTR)PTR_u_Mounted_Volume_c03c5300);
      }
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acbc4(local_28,(LPCWSTR)PTR_u_Name_c03c52b0,(STRSAFE_LPWSTR)(param_1 + 0x28),
                             0x20), iVar1 == 0)) {
      iVar1 = FUN_c03acbc4(local_24,(LPCWSTR)PTR_u_Name_c03c52b0,(STRSAFE_LPWSTR)(param_1 + 0x28),
                           0x20);
      if (iVar1 == 0) {
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x28),0x20,
                       (STRSAFE_LPCWSTR)PTR_u_External_Storage_c03c52fc);
      }
    }
    if (((local_28 == (HKEY)0x0) ||
        (iVar1 = FUN_c03acde4(local_28,(LPCWSTR)PTR_u_EnableActivityEvent_c03c52c4,puVar2,0x400),
        iVar1 == 0)) &&
       (iVar1 = FUN_c03acde4(local_24,(LPCWSTR)PTR_u_EnableActivityEvent_c03c52c4,puVar2,0x400),
       iVar1 == 0)) {
      *puVar2 = *puVar2 | 0x400;
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acbc4(local_28,(LPCWSTR)PTR_u_ActivityEvent_c03c52c0,
                             (STRSAFE_LPWSTR)(param_1 + 0x724),0x104), iVar1 == 0)) {
      iVar1 = FUN_c03acbc4(local_24,(LPCWSTR)PTR_u_ActivityEvent_c03c52c0,
                           (STRSAFE_LPWSTR)(param_1 + 0x724),0x104);
      if (iVar1 == 0) {
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x724),0x104,(STRSAFE_LPCWSTR)PTR_DAT_c03c5304);
      }
    }
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acde4(local_28,(LPCWSTR)PTR_u_DisableOnSuspend_c03c52cc,puVar2,0x800),
       iVar1 == 0)) {
      FUN_c03acde4(local_24,(LPCWSTR)PTR_u_DisableOnSuspend_c03c52cc,puVar2,0x800);
    }
    FUN_c03ae44c(DAT_c03c623c,local_24,(uint *)(param_1 + 0x930));
    FUN_c03ae44c(DAT_c03c623c,local_28,(uint *)(param_1 + 0x930));
    local_20[0] = 0;
    if ((local_28 == (HKEY)0x0) ||
       (iVar1 = FUN_c03acafc(local_28,(LPCWSTR)PTR_u_Attrib_c03c52bc,(LPBYTE)local_20), iVar1 == 0))
    {
      FUN_c03acafc(local_24,(LPCWSTR)PTR_u_Attrib_c03c52bc,(LPBYTE)local_20);
    }
    if ((local_20[0] & 1) != 0) {
      *puVar2 = *puVar2 | 1;
    }
  }
  iVar1 = FUN_c03b8ac4(param_1,local_24,local_28);
  if (((iVar1 != 0) &&
      (iVar1 = FUN_c03b12dc(param_1,(STRSAFE_PCNZWCH)(param_1 + 0x2f0)), iVar1 == 0)) &&
     (iVar1 = FUN_c03a345c(param_1,(wchar_t *)(param_1 + 0xa8),0x104), iVar1 == 0)) {
    if (((*(uint *)(param_1 + 0xd74) & 0x40000000) != 0) ||
       ((*(uint *)(param_1 + 0xd74) & 0x80000000) != 0)) {
      *(uint *)(param_1 + 0x71c) = *(uint *)(param_1 + 0x71c) | 2;
    }
    uVar3 = 1;
  }
  if (local_24 != (HKEY)0x0) {
    FUN_c03acd64(local_24);
  }
  if (local_28 != (HKEY)0x0) {
    FUN_c03acd64(local_28);
  }
  return uVar3;
}



/* c03ba658 FUN_c03ba658 */

/* Boundary evidence: original MIPS .pdata c03ba658..c03ba8cb. Semantic name remains unreviewed. */

DWORD FUN_c03ba658(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  HANDLE pvVar3;
  DWORD DVar4;
  undefined1 auStack_28 [8];
  
  DVar4 = 0;
  if ((int *)param_1[0x365] == (int *)0x0) {
    pvVar3 = CreateFileW((LPCWSTR)(param_1 + 6),0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                         (HANDLE)0x0);
    param_1[0x368] = (int)pvVar3;
    if ((pvVar3 != (HANDLE)0xffffffff) || (DVar4 = FUN_c03ac938(0x1f), DVar4 != 5))
    goto LAB_c03ba6bc;
    DVar4 = 0;
    pvVar3 = CreateFileW((LPCWSTR)(param_1 + 6),0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                         (HANDLE)0x0);
    param_1[0x368] = (int)pvVar3;
    if (pvVar3 != (HANDLE)0xffffffff) {
      param_1[0x1c7] = param_1[0x1c7] | 1;
      goto LAB_c03ba6bc;
    }
  }
  else {
    iVar1 = (**(code **)(*(int *)param_1[0x365] + 8))();
    param_1[0x368] = iVar1;
    if (iVar1 != -1) goto LAB_c03ba6bc;
  }
  DVar4 = FUN_c03ac938(0x1f);
LAB_c03ba6bc:
  if (param_1[0x368] != -1) {
    DVar4 = (**(code **)(*param_1 + 4))(param_1,1,param_1 + 0x35f,0x18,0,0,auStack_28,0);
    if ((DVar4 == 0x16) || (DVar4 == 0x32)) {
      memset(param_1 + 0x35f,0,0x18);
      DVar4 = 0;
    }
    if (DVar4 == 0) {
      iVar1 = (**(code **)(*param_1 + 4))(param_1,0x71800,param_1 + 0x34b,0x50,0,0,auStack_28,0);
      if (iVar1 != 0) {
        param_1[0x35c] = 1;
        param_1[0x35e] = 1;
        param_1[0x35d] = 0x20000000;
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x34c),0x20,L"Default");
      }
      SetLastError(0);
      iVar1 = FUN_c03b8cb8((HANDLE)param_1[0x368],param_1[0x360]);
      param_1[0x367] = iVar1;
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        DVar4 = 8;
        SetLastError(8);
      }
      else {
        *puVar2 = param_1;
        iVar1 = CreateAPIHandle(DAT_c03c537c,puVar2);
        param_1[0x369] = iVar1;
        if (iVar1 == 0) {
          param_1[0x369] = -1;
        }
        else {
          InterlockedIncrement(param_1 + 0x24e);
        }
      }
    }
  }
  return DVar4;
}



/* c03ba8cc FUN_c03ba8cc */

/* Boundary evidence: original MIPS .pdata c03ba8cc..c03ba98b. Semantic name remains unreviewed. */

int FUN_c03ba8cc(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = -1;
  puVar1 = operator_new(0x148);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03b7a6c(puVar1,param_2,0,0x596164);
  }
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[0x50] = param_1;
    iVar2 = CreateAPIHandle(DAT_c03c5374,puVar1);
    if (iVar2 == 0) {
      iVar2 = -1;
      operator_delete(puVar1);
    }
    else {
      InterlockedIncrement((LONG *)(param_1 + 0x938));
    }
  }
  return iVar2;
}



/* c03ba98c FUN_c03ba98c */

/* Boundary evidence: original MIPS .pdata c03ba98c..c03ba9fb. Semantic name remains unreviewed. */

undefined4 FUN_c03ba98c(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2 + 0xe4;
  *(undefined4 *)(*piVar1 + 4) = param_2[0xe5];
  *(int *)param_2[0xe5] = *piVar1;
  param_2[0xe5] = piVar1;
  *piVar1 = (int)piVar1;
  for (iVar2 = param_2[0xbf]; iVar2 != 0; iVar2 = iVar2 + -1) {
    FUN_c03b9dc0(param_2);
  }
  return 0;
}



/* c03ba9fc FUN_c03ba9fc */

/* Boundary evidence: original MIPS .pdata c03ba9fc..c03baa2b. Semantic name remains unreviewed. */

bool FUN_c03ba9fc(int param_1,wchar_t *param_2)

{
  int iVar1;
  
  iVar1 = _wcsicmp((wchar_t *)(param_1 + -0x50),param_2);
  return iVar1 == 0;
}



/* c03baa2c FUN_c03baa2c */

/* Boundary evidence: original MIPS .pdata c03baa2c..c03baab3. Semantic name remains unreviewed. */

void FUN_c03baa2c(int param_1)

{
  int iVar1;
  undefined4 local_80 [2];
  undefined1 auStack_78 [104];
  uint local_10;
  
  local_10 = DAT_c03c531c;
  *(undefined4 *)(param_1 + 0x710) = 0;
  iVar1 = FUN_c03b994c(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),local_80);
  if (iVar1 == 0) {
    while (iVar1 = FUN_c03b99d4(*(int *)(param_1 + 0x93c),local_80[0],auStack_78), iVar1 == 0) {
      *(int *)(param_1 + 0x710) = *(int *)(param_1 + 0x710) + 1;
    }
    FUN_c03b9a5c(*(int *)(param_1 + 0x93c),local_80[0]);
  }
  FUN_c03c216c(local_10);
  return;
}



/* c03baab4 FUN_c03baab4 */

/* Boundary evidence: original MIPS .pdata c03baab4..c03bac5f. Semantic name remains unreviewed. */

undefined4 FUN_c03baab4(int param_1,STRSAFE_LPCWSTR param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  DWORD DVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 local_28;
  HANDLE local_24;
  
  uVar7 = 0;
  iVar1 = FUN_c03b9ac8(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),param_2,&local_28)
  ;
  if (iVar1 == 0) {
    puVar2 = operator_new(0x398);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c03bf9f0(puVar2,param_1,*(undefined4 *)(param_1 + 0xd98),local_28,
                            *(undefined4 *)(param_1 + 0x93c),(STRSAFE_LPCWSTR)(param_1 + 0x68));
    }
    if (piVar3 == (int *)0x0) {
      FUN_c03b9b58(*(int *)(param_1 + 0x93c),local_28);
    }
    else {
      iVar1 = FUN_c03bfef0((int)piVar3,param_2,(STRSAFE_PCNZWCH)(param_1 + 0x2f0));
      if (iVar1 == 0) {
        FUN_c03b9b58(*(int *)(param_1 + 0x93c),local_28);
        FUN_c03b9dc0(piVar3);
      }
      else {
        uVar7 = 1;
        if (param_4 != 0) {
          piVar3[0xbd] = 1;
        }
        if ((param_3 != 0) && ((*(uint *)(param_1 + 0x71c) & 0x20) != 0)) {
          local_24 = (HANDLE)0xffffffff;
          uVar4 = __GetUserKData(0xc);
          DVar5 = FUN_c03c01c4((int)piVar3,(int *)&local_24,uVar4);
          if (DVar5 == 0) {
            iVar1 = FUN_c03c0408(piVar3,(int)local_24);
            if (iVar1 == 0) {
              CloseHandle(local_24);
            }
            else {
              *(int *)(param_1 + 0x714) = *(int *)(param_1 + 0x714) + 1;
            }
          }
        }
        puVar2 = *(undefined4 **)(param_1 + 0xcd4);
        piVar6 = piVar3 + 0xe4;
        piVar3[0xe5] = (int)puVar2;
        *piVar6 = param_1 + 0xcd0;
        *puVar2 = piVar6;
        *(int **)(param_1 + 0xcd4) = piVar6;
      }
    }
  }
  return uVar7;
}



/* c03bac60 FUN_c03bac60 */

/* Boundary evidence: original MIPS .pdata c03bac60..c03bad03. Semantic name remains unreviewed. */

void FUN_c03bac60(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_88 [2];
  undefined1 auStack_80 [4];
  wchar_t awStack_7c [50];
  uint local_18;
  
  local_18 = DAT_c03c531c;
  iVar1 = FUN_c03b994c(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),local_88);
  if (iVar1 == 0) {
    while (iVar1 = FUN_c03b99d4(*(int *)(param_1 + 0x93c),local_88[0],auStack_80), iVar1 == 0) {
      FUN_c03baab4(param_1,awStack_7c,param_2,param_3);
    }
    FUN_c03b9a5c(*(int *)(param_1 + 0x93c),local_88[0]);
  }
  FUN_c03c216c(local_18);
  return;
}



/* c03bad04 FUN_c03bad04 */

/* Boundary evidence: original MIPS .pdata c03bad04..c03bb067. Semantic name remains unreviewed. */

int FUN_c03bad04(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HANDLE pvVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  undefined4 local_68 [8];
  undefined4 local_48;
  undefined4 local_44;
  
  iVar7 = 0;
  puVar1 = operator_new(0x60);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_c03a2ad8;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
  }
  *(undefined4 **)(param_1 + 0x93c) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
LAB_c03badbc:
    iVar5 = 0xe;
  }
  else {
    psVar6 = (short *)(param_1 + 0xe8);
    iVar5 = FUN_c03bf054((int)puVar1,psVar6);
    if (iVar5 != 0) {
      return iVar5;
    }
    puVar1 = (undefined4 *)(param_1 + 0xd98);
    iVar5 = FUN_c03b93e8(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xda4),puVar1);
    if (iVar5 == 0x453) {
      FUN_c03ba088(param_1);
      *psVar6 = 0;
      puVar2 = operator_new(0x60);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_c03a2ad8;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
        puVar2[8] = 0;
        puVar2[9] = 0;
        puVar2[10] = 0;
        puVar2[0xb] = 0;
        puVar2[0xc] = 0;
        puVar2[0xd] = 0;
        puVar2[0xe] = 0;
        puVar2[0xf] = 0;
        puVar2[0x10] = 0;
        puVar2[0x11] = 0;
        puVar2[0x12] = 0;
        puVar2[0x13] = 0;
        puVar2[0x14] = 0;
        puVar2[0x15] = 0;
        puVar2[0x16] = 0;
        puVar2[0x17] = 0;
      }
      *(undefined4 **)(param_1 + 0x93c) = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_c03badbc;
      iVar5 = FUN_c03bf054((int)puVar2,psVar6);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = FUN_c03b93e8(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xda4),puVar1);
    }
    if (iVar5 == 0) {
      if (((*(int *)(param_1 + 0x92c) == 0) && ((*(uint *)(param_1 + 0x71c) & 0x400) != 0)) &&
         (*(LPCWSTR)(param_1 + 0x724) != L'\0')) {
        pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)(param_1 + 0x724));
        *(HANDLE *)(param_1 + 0x92c) = pvVar3;
      }
      puVar2 = (undefined4 *)(param_1 + 0xcd8);
      *puVar2 = 0x40;
      FUN_c03b95dc(*(int *)(param_1 + 0x93c),*puVar1,puVar2);
      iVar4 = FUN_c03b955c(*(int *)(param_1 + 0x93c),*puVar1);
      if ((iVar4 != 0) && ((*(uint *)(param_1 + 0x71c) & 8) != 0)) {
        FUN_c03b94dc(*(int *)(param_1 + 0x93c),*puVar1);
        FUN_c03b95dc(*(int *)(param_1 + 0x93c),*puVar1,puVar2);
      }
      iVar4 = FUN_c03b955c(*(int *)(param_1 + 0x93c),*puVar1);
      if (iVar4 == 0) {
        FUN_c03baa2c(param_1);
        if ((*(int *)(param_1 + 0x710) == 0) && ((*(uint *)(param_1 + 0x71c) & 0x10) != 0)) {
          local_68[0] = 0x40;
          FUN_c03b95dc(*(int *)(param_1 + 0x93c),*puVar1,local_68);
          iVar4 = FUN_c03b9664(*(int *)(param_1 + 0x93c),*puVar1,L"PART00",0,local_48,local_44,1);
          if ((iVar4 == 0) &&
             (iVar4 = FUN_c03b9824(*(int *)(param_1 + 0x93c),*puVar1,L"PART00",0,1), iVar4 == 0)) {
            FUN_c03b95dc(*(int *)(param_1 + 0x93c),*puVar1,puVar2);
            *(undefined4 *)(param_1 + 0x710) = 1;
            iVar7 = 1;
          }
        }
        FUN_c03bac60(param_1,param_3,iVar7);
      }
    }
  }
  return iVar5;
}



/* c03bb068 FUN_c03bb068 */

/* Boundary evidence: original MIPS .pdata c03bb068..c03bb113. Semantic name remains unreviewed. */

int FUN_c03bb068(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0x1f;
  iVar1 = FUN_c03ba1ec(param_1);
  if ((iVar1 != 0) && (iVar3 = FUN_c03bad04(param_1,param_2,param_3), iVar3 == 0)) {
    if ((*(int *)(param_1 + 0x714) != 0) &&
       (piVar2 = *(int **)(param_1 + 0xd94), piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 0x10))(piVar2,param_1 + 0x18,1);
    }
    *(undefined4 *)(param_1 + 0x14) = param_2;
    *(undefined4 *)(param_1 + 0x720) = 2;
  }
  return iVar3;
}



/* c03bb114 FUN_c03bb114 */

/* Boundary evidence: original MIPS .pdata c03bb114..c03bb1eb. Semantic name remains unreviewed. */

bool FUN_c03bb114(int param_1,int param_2)

{
  uint *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar3 = *(int **)(param_1 + 0xcd0);
joined_r0xc03bb13c:
  if ((int *)(param_1 + 0xcd0) == piVar3) {
    if ((*(int *)(param_1 + 0x714) == 0) &&
       (piVar3 = *(int **)(param_1 + 0xd94), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 0x10))(piVar3,param_1 + 0x18,0);
    }
    return *(int *)(param_1 + 0x714) == 0;
  }
  puVar4 = piVar3 + -0xe4;
  puVar1 = (uint *)(piVar3 + -0x26);
  piVar3 = (int *)*piVar3;
  if ((*puVar1 & 8) != 0) goto code_r0xc03bb158;
  goto LAB_c03bb174;
code_r0xc03bb158:
  bVar2 = FUN_c03c003c((int)puVar4);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    *(int *)(param_1 + 0x714) = *(int *)(param_1 + 0x714) + -1;
LAB_c03bb174:
    if (param_2 != 0) {
      FUN_c03ba98c(param_1,puVar4);
    }
  }
  goto joined_r0xc03bb13c;
}



/* c03bb1ec FUN_c03bb1ec */

/* Boundary evidence: original MIPS .pdata c03bb1ec..c03bb2c7. Semantic name remains unreviewed. */

int FUN_c03bb1ec(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    if (*(int *)(param_1 + 0x714) == 0) {
      if ((*(uint *)(param_1 + 0x71c) & 1) == 0) {
        iVar1 = FUN_c03b94dc(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98));
        if (iVar1 == 0) {
          if ((*(uint *)(param_1 + 0x720) & 2) != 0) {
            FUN_c03bb114(param_1,1);
          }
          *(undefined4 *)(param_1 + 0x710) = 0;
          *(undefined4 *)(param_1 + 0xcd8) = 0x40;
          FUN_c03b95dc(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),
                       (undefined4 *)(param_1 + 0xcd8));
        }
      }
      else {
        iVar1 = 5;
      }
    }
    else {
      iVar1 = 0x964;
    }
  }
  else {
    iVar1 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return iVar1;
}



/* c03bb2c8 FUN_c03bb2c8 */

/* Boundary evidence: original MIPS .pdata c03bb2c8..c03bb3c3. Semantic name remains unreviewed. */

int FUN_c03bb2c8(int param_1,STRSAFE_LPCWSTR param_2,undefined4 param_3,undefined4 param_4,
                int param_5,int param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    if (param_5 == 0 && param_6 == 0) {
      param_5 = *(int *)(param_1 + 0xcf8);
      param_6 = *(int *)(param_1 + 0xcfc);
    }
    iVar2 = FUN_c03b9664(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),param_2,param_3,
                         param_5,param_6,param_7);
    if (iVar2 == 0) {
      FUN_c03b95dc(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),param_1 + 0xcd8);
      FUN_c03baab4(param_1,param_2,1,1);
      *(int *)(param_1 + 0x710) = *(int *)(param_1 + 0x710) + 1;
      iVar1 = FUN_c03b8cb8(*(HANDLE *)(param_1 + 0xda4),*(SIZE_T *)(param_1 + 0xd80));
      *(int *)(param_1 + 0xd9c) = iVar1;
    }
  }
  else {
    iVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return iVar2;
}



/* c03bb3c4 FUN_c03bb3c4 */

/* Boundary evidence: original MIPS .pdata c03bb3c4..c03bb4c3. Semantic name remains unreviewed. */

int FUN_c03bb3c4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    iVar1 = FUN_c03bc29c((int *)(param_1 + 0xcd0),FUN_c03ba9fc,param_2);
    if ((iVar1 != 0) && ((undefined4 *)(iVar1 + -0x390) != (undefined4 *)0x0)) {
      if ((*(uint *)(iVar1 + -0x98) & 8) == 0) {
        iVar2 = FUN_c03b970c(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),param_2);
        if (iVar2 == 0) {
          iVar2 = FUN_c03ba98c(param_1,(undefined4 *)(iVar1 + -0x390));
          FUN_c03b95dc(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),param_1 + 0xcd8);
          *(int *)(param_1 + 0x710) = *(int *)(param_1 + 0x710) + -1;
        }
      }
      else {
        iVar2 = 0x964;
      }
    }
  }
  else {
    iVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return iVar2;
}



/* c03bb4c4 FUN_c03bb4c4 */

/* Boundary evidence: original MIPS .pdata c03bb4c4..c03bb58b. Semantic name remains unreviewed. */

DWORD FUN_c03bb4c4(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  DWORD DVar2;
  
  *param_3 = -1;
  DVar2 = 2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    iVar1 = FUN_c03bc29c((int *)(param_1 + 0xcd0),FUN_c03ba9fc,param_2);
    if ((iVar1 != 0) && (iVar1 + -0x390 != 0)) {
      DVar2 = FUN_c03c01c4(iVar1 + -0x390,param_3,param_4);
    }
  }
  else {
    DVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return DVar2;
}



/* c03bb58c FUN_c03bb58c */

/* Boundary evidence: original MIPS .pdata c03bb58c..c03bb63b. Semantic name remains unreviewed. */

DWORD FUN_c03bb58c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  HANDLE local_18 [2];
  
  if ((param_2[0xbe] & 8U) == 0) {
    uVar1 = __GetUserKData(0xc);
    DVar3 = FUN_c03c01c4((int)param_2,(int *)local_18,uVar1);
    if (DVar3 == 0) {
      iVar2 = FUN_c03c0408(param_2,(int)local_18[0]);
      if (iVar2 == 0) {
        DVar3 = FUN_c03ac938(0x1f);
        CloseHandle(local_18[0]);
      }
      else {
        *(int *)(param_1 + 0x714) = *(int *)(param_1 + 0x714) + 1;
      }
    }
  }
  else {
    DVar3 = 0xb7;
  }
  return DVar3;
}



/* c03bb63c FUN_c03bb63c */

/* Boundary evidence: original MIPS .pdata c03bb63c..c03bb6cf. Semantic name remains unreviewed. */

undefined4 FUN_c03bb63c(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_2 + 0x2f8) & 8) == 0) {
    uVar2 = 2;
  }
  else {
    bVar1 = FUN_c03c003c(param_2);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      uVar2 = 0x1f;
    }
    else {
      *(int *)(param_1 + 0x714) = *(int *)(param_1 + 0x714) + -1;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return uVar2;
}



/* c03bb6d0 FUN_c03bb6d0 */

/* Boundary evidence: original MIPS .pdata c03bb6d0..c03bb777. Semantic name remains unreviewed. */

void FUN_c03bb6d0(int param_1)

{
  int *piVar1;
  
  if ((*(uint *)(param_1 + 0x720) & 8) == 0) {
    FUN_c03b8f74(param_1);
    FUN_c03b9bc4(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),0,0);
    for (piVar1 = *(int **)(param_1 + 0xcd0); (int *)(param_1 + 0xcd0) != piVar1;
        piVar1 = (int *)*piVar1) {
      if (piVar1[-0xde] != 0) {
        FUN_c03ad548(piVar1[-0xde],0,0);
      }
      piVar1[-0x26] = piVar1[-0x26] | 4;
    }
    *(uint *)(param_1 + 0x720) = *(uint *)(param_1 + 0x720) | 8;
  }
  return;
}



/* c03bb778 FUN_c03bb778 */

/* Boundary evidence: original MIPS .pdata c03bb778..c03bb813. Semantic name remains unreviewed. */

void FUN_c03bb778(int param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  int local_18 [2];
  
  if (param_2[6] != 0) {
    local_18[0] = 0;
    DVar1 = FUN_c03ad548(param_2[6],1,(int)local_18);
    if (((DVar1 != 0) || (local_18[0] != 1)) ||
       (iVar2 = FUN_c03bb63c(param_1,(int)param_2), iVar2 != 0)) goto LAB_c03bb7e8;
  }
  FUN_c03bb58c(param_1,param_2);
LAB_c03bb7e8:
  param_2[0xbe] = param_2[0xbe] & 0xfffffffb;
  return;
}



/* c03bb814 FUN_c03bb814 */

/* Boundary evidence: original MIPS .pdata c03bb814..c03bb8e7. Semantic name remains unreviewed. */

void FUN_c03bb814(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int *piVar3;
  int local_18 [2];
  
  local_18[0] = 0;
  iVar2 = FUN_c03b9bc4(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),1,local_18);
  if ((iVar2 == 0) && (local_18[0] == 0)) {
    for (piVar3 = *(int **)(param_1 + 0xcd0); (int *)(param_1 + 0xcd0) != piVar3;
        piVar3 = (int *)*piVar3) {
      FUN_c03bb778(param_1,piVar3 + -0xe4);
    }
  }
  else {
    bVar1 = FUN_c03bb114(param_1,1);
    if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_c03bb8bc;
    FUN_c03ba088(param_1);
    FUN_c03bad04(param_1,*(undefined4 *)(param_1 + 0x14),1);
  }
  FUN_c03b8fbc(param_1);
LAB_c03bb8bc:
  *(uint *)(param_1 + 0x720) = *(uint *)(param_1 + 0x720) & 0xffffffe7;
  return;
}



/* c03bb8e8 FUN_c03bb8e8 */

/* Boundary evidence: original MIPS .pdata c03bb8e8..c03bb997. Semantic name remains unreviewed. */

DWORD FUN_c03bb8e8(int param_1,int param_2,STRSAFE_LPCWSTR param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD DVar2;
  
  DVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    bVar1 = FUN_c03c00d0(param_2,param_3);
    if ((CONCAT31(extraout_var,bVar1) == 0) && (DVar2 = GetLastError(), DVar2 == 0)) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return DVar2;
}



/* c03bb998 FUN_c03bb998 */

/* Boundary evidence: original MIPS .pdata c03bb998..c03bba47. Semantic name remains unreviewed. */

DWORD FUN_c03bb998(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD DVar2;
  
  DVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    bVar1 = FUN_c03b9e1c(param_2,param_3);
    if ((CONCAT31(extraout_var,bVar1) == 0) && (DVar2 = GetLastError(), DVar2 == 0)) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return DVar2;
}



/* c03bba48 FUN_c03bba48 */

/* Boundary evidence: original MIPS .pdata c03bba48..c03bbb07. Semantic name remains unreviewed. */

DWORD FUN_c03bba48(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD DVar2;
  
  DVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    bVar1 = FUN_c03c0144(param_2,param_3,param_4);
    if ((CONCAT31(extraout_var,bVar1) == 0) && (DVar2 = GetLastError(), DVar2 == 0)) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return DVar2;
}



/* c03bbb08 FUN_c03bbb08 */

/* Boundary evidence: original MIPS .pdata c03bbb08..c03bbd0f. Semantic name remains unreviewed. */

undefined4 FUN_c03bbb08(int param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  
  *param_3 = -1;
  uVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  if ((*(uint *)(param_1 + 0x720) & 4) == 0) {
    puVar1 = operator_new(0x148);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_c03b7a6c(puVar1,param_4,0,1);
    }
    if (puVar1 == (undefined4 *)0x0) {
      uVar6 = 0xe;
    }
    else {
      for (piVar7 = *(int **)(param_1 + 0xcd0); (int *)(param_1 + 0xcd0) != piVar7;
          piVar7 = (int *)*piVar7) {
        puVar2 = operator_new(0x130);
        if (puVar2 != (undefined4 *)0x0) {
          FUN_c03bfc00((int)(piVar7 + -0xe4),(int)(puVar2 + 2));
          puVar2[2] = 0x128;
          puVar4 = (undefined4 *)puVar1[5];
          puVar2[1] = puVar4;
          *puVar2 = puVar1 + 4;
          *puVar4 = puVar2;
          puVar1[5] = puVar2;
        }
      }
      piVar5 = puVar1 + 4;
      piVar7 = (int *)*piVar5;
      if (piVar5 == piVar7) {
        operator_delete(puVar1);
        uVar6 = 0x103;
      }
      else {
        *(int *)(*piVar7 + 4) = piVar7[1];
        *(int *)piVar7[1] = *piVar7;
        piVar7[1] = (int)piVar7;
        *piVar7 = (int)piVar7;
        iVar3 = CeSafeCopyMemory(param_2,piVar7 + 2,0x128);
        if (iVar3 == 0) {
          operator_delete(puVar1);
          uVar6 = 0xa0;
        }
        else {
          iVar3 = CreateAPIHandle(DAT_c03c5370,puVar1);
          *param_3 = iVar3;
          if (iVar3 == 0) {
            FUN_c03bc314(piVar5,FUN_c03b7618,0);
            operator_delete(puVar1);
            *param_3 = -1;
            uVar6 = 0x1f;
          }
        }
        operator_delete(piVar7);
      }
    }
  }
  else {
    uVar6 = 0x10df;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return uVar6;
}



/* c03bbd10 FUN_c03bbd10 */

/* Boundary evidence: original MIPS .pdata c03bbd10..c03bbe37. Semantic name remains unreviewed. */

undefined4
FUN_c03bbd10(int *param_1,int *param_2,int param_3,int param_4,uint param_5,undefined4 *param_6,
            uint param_7,int param_8)

{
  undefined4 uVar1;
  
  if (param_3 == 0x71800) {
    if ((param_4 != 0) && (0x4f < param_5)) {
      uVar1 = FUN_c03b9104((int)param_1,param_4,param_8);
      return uVar1;
    }
  }
  else {
    if (param_3 != 0x71c24) {
      uVar1 = FUN_c03b917c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar1;
    }
    if ((param_6 != (undefined4 *)0x0) && (0xf < param_7)) {
      *param_6 = 0;
      uVar1 = FUN_c03b906c((int)param_1,(int)param_6,param_7,param_8);
      return uVar1;
    }
  }
  return 0x57;
}



/* c03bbe38 FUN_c03bbe38 */

/* Boundary evidence: original MIPS .pdata c03bbe38..c03bbe43. Semantic name remains unreviewed. */

undefined4 FUN_c03bbe38(void)

{
  return 1;
}



/* c03bbe44 FUN_c03bbe44 */

/* Boundary evidence: original MIPS .pdata c03bbe44..c03bbe4f. Semantic name remains unreviewed. */

undefined4 FUN_c03bbe44(void)

{
  return 1;
}



/* c03bbe50 FUN_c03bbe50 */

/* Boundary evidence: original MIPS .pdata c03bbe50..c03bbe5b. Semantic name remains unreviewed. */

undefined4 FUN_c03bbe50(void)

{
  return 1;
}



/* c03bbe5c FUN_c03bbe5c */

/* Boundary evidence: original MIPS .pdata c03bbe5c..c03bbef3. Semantic name remains unreviewed. */

DWORD FUN_c03bbe5c(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                  DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
  int iVar1;
  DWORD DVar2;
  
  if (*(int *)(param_1 + 0x93c) == 0) {
    iVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0xda0),param_2,param_3,param_4,param_5,param_6,
                            param_7,param_8);
  }
  else {
    iVar1 = FUN_c03b9c64(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98),
                         *(HANDLE *)(param_1 + 0xda0),param_2,param_3,param_4,param_5,param_6,
                         param_7,param_8);
  }
  if (iVar1 == 0) {
    DVar2 = FUN_c03ac938(0x1f);
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



/* c03bbef4 FUN_c03bbef4 */

/* Boundary evidence: original MIPS .pdata c03bbef4..c03bbf53. Semantic name remains unreviewed. */

void FUN_c03bbef4(int *param_1)

{
  if (*param_1 == 0x596164) {
    FUN_c03a6924((undefined4 *)param_1[0x50]);
  }
  else {
    if (*param_1 != 0x64615900) {
      return;
    }
    FUN_c03b9dc0((undefined4 *)param_1[0x51]);
    param_1[0x51] = 0;
  }
  param_1[0x50] = 0;
  return;
}



/* c03bbf54 FUN_c03bbf54 */

/* Boundary evidence: original MIPS .pdata c03bbf54..c03bc163. Semantic name remains unreviewed. */

undefined4 FUN_c03bbf54(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *local_30;
  int local_2c;
  
  local_30 = (int *)0x0;
  iVar1 = LockAPIHandle(DAT_c03c537c,0x42,param_2[0x369],&local_30);
  local_2c = 0;
  iVar2 = LockAPIHandle(DAT_c03c5374,0x42,param_2[5],&local_2c);
  if (iVar1 != 0) {
    if (((local_30 != (int *)0x0) && (iVar2 != 0)) && (local_2c != 0)) {
      FUN_c03b9470(*(int *)(param_1 + 0x93c),*(undefined4 *)(param_1 + 0xd98));
      if (*(HANDLE *)(param_1 + 0xda0) != (HANDLE)0xffffffff) {
        CloseHandle(*(HANDLE *)(param_1 + 0xda0));
        *(undefined4 *)(param_1 + 0xda0) = 0xffffffff;
      }
      CloseHandle(*(HANDLE *)(param_1 + 0x14));
      CloseHandle(*(HANDLE *)(param_1 + 0xda4));
      if (param_2[0x369] != -1) {
        *(undefined4 *)(param_1 + 0xda4) = param_2[0x369];
        *local_30 = param_1;
        InterlockedIncrement((LONG *)(param_1 + 0x938));
        FUN_c03a6924(param_2);
        param_2[0x369] = 0xffffffff;
      }
      UnlockAPIHandle(DAT_c03c537c,iVar1);
      if (param_2[5] != -1) {
        *(undefined4 *)(param_1 + 0x14) = param_2[5];
        *(int *)(local_2c + 0x140) = param_1;
        InterlockedIncrement((LONG *)(param_1 + 0x938));
        FUN_c03a6924(param_2);
        param_2[5] = 0xffffffff;
      }
      UnlockAPIHandle(DAT_c03c5374,iVar2);
      *(undefined4 *)(param_1 + 0xd98) = param_2[0x366];
      *(undefined4 *)(param_1 + 0xda0) = param_2[0x368];
      param_2[0x366] = 0;
      param_2[0x368] = 0xffffffff;
      StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x18),8,(STRSAFE_LPCWSTR)(param_2 + 6));
      piVar3 = *(int **)(param_1 + 0xcd0);
      for (piVar4 = (int *)param_2[0x334];
          ((int *)(param_1 + 0xcd0) != piVar3 && (param_2 + 0x334 != piVar4));
          piVar4 = (int *)*piVar4) {
        piVar3[-3] = piVar4[-3];
        piVar3[-2] = piVar4[-2];
        piVar4[-3] = 0;
        piVar4[-2] = 0;
        piVar3 = (int *)*piVar3;
      }
      return 1;
    }
    UnlockAPIHandle(DAT_c03c537c,iVar1);
  }
  if (iVar2 != 0) {
    UnlockAPIHandle(DAT_c03c5374,iVar2);
  }
  return 0;
}



/* c03bc164 FUN_c03bc164 */

/* Boundary evidence: original MIPS .pdata c03bc164..c03bc1af. Semantic name remains unreviewed. */

undefined4 * FUN_c03bc164(undefined4 *param_1,uint param_2)

{
  FUN_c03ba0e8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03bc1b0 FUN_c03bc1b0 */

/* Boundary evidence: original MIPS .pdata c03bc1b0..c03bc29b. Semantic name remains unreviewed. */

int FUN_c03bc1b0(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  bVar1 = FUN_c03bb114(param_1,1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    FSDMGR_AdvertiseInterface(&DAT_c03a2ab0,(short *)(param_1 + 0x18),0);
    if (*(HANDLE *)(param_1 + 0xda0) != (HANDLE)0xffffffff) {
      CloseHandle(*(HANDLE *)(param_1 + 0xda0));
      *(undefined4 *)(param_1 + 0xda0) = 0xffffffff;
    }
    if (*(HANDLE *)(param_1 + 0xda4) != (HANDLE)0xffffffff) {
      CloseHandle(*(HANDLE *)(param_1 + 0xda4));
      *(undefined4 *)(param_1 + 0xda4) = 0xffffffff;
    }
    if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0xffffffff) {
      CloseHandle(*(HANDLE *)(param_1 + 0x14));
      *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
    }
    *(uint *)(param_1 + 0x720) = *(uint *)(param_1 + 0x720) | 0x40;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xd18));
  return CONCAT31(extraout_var,bVar1);
}



/* c03bc29c FUN_c03bc29c */

/* Boundary evidence: original MIPS .pdata c03bc29c..c03bc313. Semantic name remains unreviewed. */

int FUN_c03bc29c(int *param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  do {
    piVar1 = piVar3;
    if (piVar1 == param_1) {
      return 0;
    }
    piVar3 = (int *)*piVar1;
    iVar2 = (*(code *)param_2)(piVar1,param_3);
  } while (iVar2 == 0);
  return (int)piVar1;
}



/* c03bc314 FUN_c03bc314 */

/* Boundary evidence: original MIPS .pdata c03bc314..c03bc387. Semantic name remains unreviewed. */

void FUN_c03bc314(int *param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  
  while (piVar1 = (int *)*param_1, piVar1 != param_1) {
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)piVar1[1] = *piVar1;
    piVar1[1] = (int)piVar1;
    *piVar1 = (int)piVar1;
    (*(code *)param_2)(piVar1,param_3);
  }
  return;
}



/* c03bc388 FUN_c03bc388 */

/* Boundary evidence: original MIPS .pdata c03bc388..c03bc3bf. Semantic name remains unreviewed. */

undefined4 * FUN_c03bc388(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03c0de0(puVar1);
  }
  return puVar1;
}



/* c03bc3c0 FUN_c03bc3c0 */

/* Boundary evidence: original MIPS .pdata c03bc3c0..c03bc407. Semantic name remains unreviewed. */

undefined4 FUN_c03bc3c0(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 1;
  }
  else if (*param_1 == -0x21524111) {
    uVar1 = FUN_c03c0dfc((int)param_1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c03bc408 FUN_c03bc408 */

/* Boundary evidence: original MIPS .pdata c03bc408..c03bc527. Semantic name remains unreviewed. */

undefined4 FUN_c03bc408(int *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar4;
  
  if (((param_2 == 0) || (param_1 == (int *)0x0)) || (*param_1 != -0x21524111)) {
    uVar2 = 0;
  }
  else {
    if (((int *)param_1[1] != (int *)0x0) &&
       (piVar3 = FUN_c03c11bc((int *)param_1[1],param_2), piVar3 != (int *)0x0)) {
      FUN_c03c0d78((int)piVar3);
      operator_delete(piVar3);
      bVar1 = FUN_c03c0f70(param_1[1]);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        puVar4 = (undefined4 *)param_1[1];
        if (puVar4 != (undefined4 *)0x0) {
          FUN_c03c12ec(puVar4);
          operator_delete(puVar4);
        }
        param_1[1] = 0;
      }
    }
    if (((int *)param_1[2] != (int *)0x0) &&
       (piVar3 = FUN_c03c11bc((int *)param_1[2],param_2), piVar3 != (int *)0x0)) {
      FUN_c03c0d78((int)piVar3);
      operator_delete(piVar3);
      bVar1 = FUN_c03c0f70(param_1[2]);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        puVar4 = (undefined4 *)param_1[2];
        if (puVar4 != (undefined4 *)0x0) {
          FUN_c03c12ec(puVar4);
          operator_delete(puVar4);
        }
        param_1[2] = 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* c03bc528 FUN_c03bc528 */

/* Boundary evidence: original MIPS .pdata c03bc528..c03bc63b. Semantic name remains unreviewed. */

undefined4
FUN_c03bc528(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,uint param_6
            )

{
  int iVar1;
  undefined4 *puVar2;
  uint auStack_28 [4];
  
  FUN_c03c135c(auStack_28);
  if (((param_2 != 0) && (param_1 != (int *)0x0)) && (*param_1 == -0x21524111)) {
    FUN_c03c137c(auStack_28,param_4,param_5);
    FUN_c03c139c((int *)auStack_28,param_6,0);
    iVar1 = FUN_c03c14d0(auStack_28);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)param_1[1];
    if (param_3 == 0) {
      if ((puVar2 != (undefined4 *)0x0) &&
         (iVar1 = FUN_c03c1020(puVar2,auStack_28,param_2), iVar1 != 0)) {
        return 0;
      }
      if ((undefined4 *)param_1[2] == (undefined4 *)0x0) {
        return 1;
      }
      iVar1 = FUN_c03c0f88((undefined4 *)param_1[2],auStack_28);
    }
    else {
      if (puVar2 == (undefined4 *)0x0) {
        return 1;
      }
      iVar1 = FUN_c03c1020(puVar2,auStack_28,param_2);
    }
    if (iVar1 == 0) {
      return 1;
    }
    return 0;
  }
  return 0;
}



/* c03bc63c FUN_c03bc63c */

/* Boundary evidence: original MIPS .pdata c03bc63c..c03bc6ff. Semantic name remains unreviewed. */

undefined4 FUN_c03bc63c(int *param_1,int param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  
  uVar4 = 0;
  piVar2 = FUN_c03c11bc(param_1,param_2);
  if (piVar2 != (int *)0x0) {
    piVar3 = FUN_c03c0c2c((int)piVar2,param_3);
    if (piVar3 != (int *)0x0) {
      FUN_c03c0968(piVar3);
      operator_delete(piVar3);
      bVar1 = FUN_c03c0a48((int)piVar2);
      bVar1 = CONCAT31(extraout_var,bVar1) != 0;
      if (bVar1) {
        FUN_c03c0d78((int)piVar2);
        operator_delete(piVar2);
      }
      uVar4 = 1;
      if (bVar1) {
        return 1;
      }
    }
    FUN_c03c10c4(param_1,(int)piVar2);
  }
  return uVar4;
}



/* c03bc700 FUN_c03bc700 */

/* Boundary evidence: original MIPS .pdata c03bc700..c03bc74b. Semantic name remains unreviewed. */

void FUN_c03bc700(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 == -0x21524111)) {
    FUN_c03c0e60((int)param_1);
    operator_delete(param_1);
  }
  return;
}



/* c03bc74c FUN_c03bc74c */

/* Boundary evidence: original MIPS .pdata c03bc74c..c03bca67. Semantic name remains unreviewed. */

undefined4
FUN_c03bc74c(int *param_1,int param_2,uint param_3,undefined4 param_4,uint param_5,int param_6,
            int param_7)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 *puVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int *piVar9;
  int *local_30;
  
  uVar8 = 0;
  if (((((param_1 != (int *)0x0) && (param_2 != 0)) && (param_7 != 0)) &&
      ((param_5 != 0 || (param_6 != 0)))) && (*param_1 == -0x21524111)) {
    puVar4 = operator_new(0x10);
    if (puVar4 == (undefined4 *)0x0) {
      puVar5 = (uint *)0x0;
    }
    else {
      puVar5 = FUN_c03c135c(puVar4);
    }
    if (puVar5 != (uint *)0x0) {
      FUN_c03c137c(puVar5,*(undefined4 *)(param_7 + 8),*(undefined4 *)(param_7 + 0xc));
      FUN_c03c139c((int *)puVar5,param_5,param_6);
      bVar3 = false;
      bVar2 = false;
      bVar1 = true;
      iVar6 = FUN_c03c14d0(puVar5);
      piVar9 = local_30;
      if (iVar6 != 0) {
        if ((((undefined4 *)param_1[1] == (undefined4 *)0x0) ||
            (iVar6 = FUN_c03c0f88((undefined4 *)param_1[1],puVar5), iVar6 == 0)) &&
           (((undefined4 *)param_1[2] == (undefined4 *)0x0 ||
            (((param_3 & 2) == 0 ||
             (iVar6 = FUN_c03c0f88((undefined4 *)param_1[2],puVar5), iVar6 == 0)))))) {
          if ((param_3 & 2) == 0) {
            if (param_1[2] == 0) {
              puVar4 = operator_new(8);
              if (puVar4 == (undefined4 *)0x0) {
                puVar4 = (undefined4 *)0x0;
              }
              else {
                puVar4 = FUN_c03c0ec0(puVar4);
              }
              param_1[2] = (int)puVar4;
              if (puVar4 == (undefined4 *)0x0) goto LAB_c03bc860;
              bVar3 = true;
            }
            piVar9 = (int *)param_1[2];
          }
          else {
            if (param_1[1] == 0) {
              puVar4 = operator_new(8);
              if (puVar4 == (undefined4 *)0x0) {
                puVar4 = (undefined4 *)0x0;
              }
              else {
                puVar4 = FUN_c03c0ec0(puVar4);
              }
              param_1[1] = (int)puVar4;
              if (puVar4 == (undefined4 *)0x0) goto LAB_c03bc860;
              bVar3 = true;
            }
            piVar9 = (int *)param_1[1];
          }
          bVar2 = false;
          bVar1 = true;
          local_30 = FUN_c03c11bc(piVar9,param_2);
          if (local_30 == (int *)0x0) {
            puVar4 = operator_new(0x10);
            if (puVar4 == (undefined4 *)0x0) {
              local_30 = (int *)0x0;
            }
            else {
              local_30 = FUN_c03c0990(puVar4);
            }
            if (local_30 == (int *)0x0) goto LAB_c03bc860;
            bVar2 = true;
            bVar1 = true;
            if (local_30[1] == 0) goto LAB_c03bc860;
            *local_30 = param_2;
          }
          bVar1 = true;
          local_30[3] = 0;
          puVar4 = operator_new(8);
          if (puVar4 == (undefined4 *)0x0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = FUN_c03c0958(puVar4);
          }
          if (piVar7 != (int *)0x0) {
            *piVar7 = (int)puVar5;
            FUN_c03c0b34((int)local_30,piVar7);
            FUN_c03c10c4(piVar9,(int)local_30);
            uVar8 = 1;
            bVar3 = false;
            bVar2 = false;
            bVar1 = false;
          }
        }
        else if ((param_3 & 1) == 0) {
          uVar8 = 2;
        }
      }
LAB_c03bc860:
      if (bVar1) {
        operator_delete(puVar5);
      }
      if ((bVar2) && (local_30 != (int *)0x0)) {
        FUN_c03c0d78((int)local_30);
        operator_delete(local_30);
      }
      if (!bVar3) {
        return uVar8;
      }
      if (piVar9 != (int *)0x0) {
        FUN_c03c12ec(piVar9);
        operator_delete(piVar9);
      }
      if ((param_3 & 2) != 0) {
        param_1[1] = 0;
        return uVar8;
      }
      param_1[2] = 0;
      return uVar8;
    }
  }
  return 0;
}



/* c03bca68 FUN_c03bca68 */

/* Boundary evidence: original MIPS .pdata c03bca68..c03bcbeb. Semantic name remains unreviewed. */

undefined4
FUN_c03bca68(int *param_1,int param_2,undefined4 param_3,uint param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 *puVar3;
  uint auStack_28 [4];
  
  FUN_c03c135c(auStack_28);
  if (((((param_1 != (int *)0x0) && (param_2 != 0)) && (param_6 != 0)) &&
      ((param_4 != 0 || (param_5 != 0)))) && (*param_1 == -0x21524111)) {
    FUN_c03c137c(auStack_28,*(undefined4 *)(param_6 + 8),*(undefined4 *)(param_6 + 0xc));
    FUN_c03c139c((int *)auStack_28,param_4,param_5);
    iVar2 = FUN_c03c14d0(auStack_28);
    if (iVar2 != 0) {
      iVar2 = FUN_c03c0dfc((int)param_1);
      if (iVar2 != 0) {
        return 0;
      }
      if (((int *)param_1[1] == (int *)0x0) ||
         (iVar2 = FUN_c03bc63c((int *)param_1[1],param_2,(int *)auStack_28), iVar2 == 0)) {
        if ((int *)param_1[2] == (int *)0x0) {
          return 0;
        }
        iVar2 = FUN_c03bc63c((int *)param_1[2],param_2,(int *)auStack_28);
        if (iVar2 == 0) {
          return 0;
        }
        bVar1 = FUN_c03c0f70(param_1[2]);
        if (CONCAT31(extraout_var_00,bVar1) != 0) {
          puVar3 = (undefined4 *)param_1[2];
          if (puVar3 != (undefined4 *)0x0) {
            FUN_c03c12ec(puVar3);
            operator_delete(puVar3);
          }
          param_1[2] = 0;
        }
      }
      else {
        bVar1 = FUN_c03c0f70(param_1[1]);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          puVar3 = (undefined4 *)param_1[1];
          if (puVar3 != (undefined4 *)0x0) {
            FUN_c03c12ec(puVar3);
            operator_delete(puVar3);
          }
          param_1[1] = 0;
        }
      }
      return 1;
    }
  }
  return 0;
}



/* c03bcbec FUN_c03bcbec */

/* Boundary evidence: original MIPS .pdata c03bcbec..c03bcc6b. Semantic name remains unreviewed. */

void FUN_c03bcbec(void)

{
  return;
}



/* c03bcc6c FUN_c03bcc6c */

/* Boundary evidence: original MIPS .pdata c03bcc6c..c03bcc77. Semantic name remains unreviewed. */

undefined4 FUN_c03bcc6c(void)

{
  return 1;
}



/* c03bcc78 FUN_c03bcc78 */

/* Boundary evidence: original MIPS .pdata c03bcc78..c03bcd47. Semantic name remains unreviewed. */

undefined4 * FUN_c03bcc78(wchar_t *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  uint _Size;
  
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    sVar2 = wcslen(param_1);
    _Size = (sVar2 + 1) * 2;
    *puVar1 = 0x47444744;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[4] = 0;
    puVar1[2] = param_2;
    puVar1[3] = 0;
    if (_Size < 0x80000000) {
      uVar3 = (sVar2 + 1) * 4;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    puVar1[1] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
  }
  return puVar1;
}



/* c03bcd48 FUN_c03bcd48 */

/* Boundary evidence: original MIPS .pdata c03bcd48..c03bce97. Semantic name remains unreviewed. */

undefined4 * FUN_c03bcd48(wchar_t *param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint uVar3;
  uint _Size;
  
  sVar1 = wcslen(param_1);
  _Size = (sVar1 + 1) * 2;
  puVar2 = operator_new(0x2c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0xffffffff;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar2 + 1));
    *puVar2 = 0x47544754;
    puVar2[7] = 0;
    if (_Size < 0x80000000) {
      uVar3 = (sVar1 + 1) * 4;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    puVar2[6] = _Dst;
    puVar2[9] = 0;
    puVar2[8] = 0;
    puVar2[10] = 0;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
    if (DAT_c03c6284 == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6270);
      DAT_c03c6284 = CreateAPISet(&DAT_c03a2b48,3,&DAT_c03a2b24,&DAT_c03a2b30);
      RegisterDirectMethods(DAT_c03c6284,&PTR_FUN_c03a2b18);
      RegisterAPISet(DAT_c03c6284,0x80000008);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6270);
    if (DAT_c03c6288 != (undefined4 *)0x0) {
      puVar2[10] = DAT_c03c6288;
    }
    DAT_c03c6288 = puVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6270);
  }
  return puVar2;
}



/* c03bce98 FUN_c03bce98 */

/* Boundary evidence: original MIPS .pdata c03bce98..c03bceef. Semantic name remains unreviewed. */

void FUN_c03bce98(void *param_1)

{
  void *pvVar1;
  
  while (param_1 != (void *)0x0) {
    pvVar1 = *(void **)((int)param_1 + 0x10);
    if (*(void **)((int)param_1 + 0xc) != (void *)0x0) {
      operator_delete(*(void **)((int)param_1 + 0xc));
    }
    operator_delete(param_1);
    param_1 = pvVar1;
  }
  return;
}



/* c03bcef0 FUN_c03bcef0 */

/* Boundary evidence: original MIPS .pdata c03bcef0..c03bcf4b. Semantic name remains unreviewed. */

void FUN_c03bcef0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x20);
  while (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = puVar2[3];
    operator_delete((void *)*puVar2);
    operator_delete(puVar2);
    iVar1 = *(int *)(param_1 + 0x20);
  }
  return;
}



/* c03bcf4c FUN_c03bcf4c */

/* Boundary evidence: original MIPS .pdata c03bcf4c..c03bd33b. Semantic name remains unreviewed. */

undefined4 *
FUN_c03bcf4c(int param_1,wchar_t *param_2,int *param_3,int param_4,int param_5,undefined4 *param_6)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *_Dest;
  wchar_t *pwVar3;
  uint uVar4;
  wchar_t *_Str1;
  undefined4 *puVar5;
  wchar_t *_Str;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  char local_38;
  undefined4 *local_30;
  int local_2c;
  
  puVar8 = *(undefined4 **)(param_1 + 0x1c);
  wVar1 = *param_2;
  while ((wVar1 != L'\0' && (wVar1 == L'\\'))) {
    param_2 = param_2 + 1;
    wVar1 = *param_2;
  }
  sVar2 = wcslen(param_2);
  uVar6 = 0xffffffff;
  uVar4 = (sVar2 + 1) * 2;
  if (0x7fffffff < sVar2 + 1) {
    uVar4 = uVar6;
  }
  _Dest = operator_new(uVar4);
  if (_Dest == (wchar_t *)0x0) {
LAB_c03bcffc:
    puVar5 = (undefined4 *)0x0;
  }
  else {
    wcscpy(_Dest,param_2);
    local_30 = (undefined4 *)0x0;
    puVar5 = (undefined4 *)0x0;
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    local_38 = '\0';
    _Str1 = _Dest;
    local_2c = param_4;
    if (*_Dest != L'\0') {
      do {
        wVar1 = *_Str1;
        _Str = _Str1;
        while ((wVar1 != L'\0' && (*_Str != L'\\'))) {
          _Str = _Str + 1;
          wVar1 = *_Str;
        }
        if (*_Str == L'\0') {
          if (local_2c != 0) {
            local_2c = 0;
            goto LAB_c03bd160;
          }
          if ((*_Str1 != L'\0') && (param_3 != (int *)0x0)) {
            sVar2 = wcslen(_Str1);
            uVar4 = (sVar2 + 1) * 2;
            if (0x7fffffff < sVar2 + 1) {
              uVar4 = uVar6;
            }
            pwVar3 = operator_new(uVar4);
            *param_3 = (int)pwVar3;
            if (pwVar3 != (wchar_t *)0x0) {
              wcscpy(pwVar3,_Str1);
            }
          }
        }
        else {
          *_Str = L'\0';
          _Str = _Str + 1;
LAB_c03bd160:
          puVar7 = (undefined4 *)0x0;
          puVar9 = puVar8;
          if (puVar8 != (undefined4 *)0x0) {
            do {
              puVar9 = puVar8;
              if ((wchar_t *)puVar8[1] == (wchar_t *)0x0) goto LAB_c03bd1ac;
              uVar4 = _wcsicmp(_Str1,(wchar_t *)puVar8[1]);
            } while ((0 < (int)uVar4) &&
                    (puVar9 = (undefined4 *)puVar8[7], uVar4 = uVar6, puVar7 = puVar8,
                    puVar8 = puVar9, puVar9 != (undefined4 *)0x0));
            if (uVar4 == 0) {
              puVar8 = (undefined4 *)puVar9[5];
              puVar5 = puVar9;
              local_30 = puVar9;
              goto LAB_c03bd0d4;
            }
          }
LAB_c03bd1ac:
          if (param_5 != 0) {
            if ((param_6 != (undefined4 *)0x0) && ((*_Str != L'\0' || (param_3 == (int *)0x0)))) {
              *param_6 = 0;
            }
            if (*_Str == L'\0') {
              if (((*_Str1 == L'\0') || (param_3 == (int *)0x0)) || (param_6 == (undefined4 *)0x0))
              goto LAB_c03bd304;
              sVar2 = wcslen(_Str1);
              if (sVar2 + 1 < 0x80000000) {
                uVar6 = (sVar2 + 1) * 2;
              }
              pwVar3 = operator_new(uVar6);
              *param_3 = (int)pwVar3;
            }
            else {
              if (param_3 == (int *)0x0) goto LAB_c03bd304;
              sVar2 = wcslen(_Str);
              if (sVar2 + 1 < 0x80000000) {
                uVar6 = (sVar2 + 1) * 2;
              }
              pwVar3 = operator_new(uVar6);
              *param_3 = (int)pwVar3;
              _Str1 = _Str;
            }
            if (pwVar3 == (wchar_t *)0x0) goto LAB_c03bd304;
            goto LAB_c03bd2fc;
          }
          puVar5 = FUN_c03bcc78(_Str1,param_1);
          if (puVar5 == (undefined4 *)0x0) goto LAB_c03bcffc;
          *(char *)(puVar5 + 9) = local_38;
          if (puVar7 == (undefined4 *)0x0) {
            if (local_30 == (undefined4 *)0x0) {
              *(undefined4 **)(param_1 + 0x1c) = puVar5;
            }
            else {
              local_30[5] = puVar5;
            }
          }
          else {
            puVar7[7] = puVar5;
          }
          if (puVar9 != (undefined4 *)0x0) {
            puVar9[8] = puVar5;
          }
          puVar5[8] = puVar7;
          puVar5[7] = puVar9;
          puVar5[6] = local_30;
          puVar8 = (undefined4 *)0x0;
          local_30 = puVar5;
          if (*(int *)(param_1 + 0x1c) == 0) {
            *(undefined4 **)(param_1 + 0x1c) = puVar5;
          }
        }
LAB_c03bd0d4:
        local_38 = local_38 + '\x01';
        _Str1 = _Str;
      } while (*_Str != L'\0');
      if (((puVar5 != (undefined4 *)0x0) && (param_3 != (int *)0x0)) &&
         ((*param_3 == 0 && ((wchar_t *)puVar5[1] != (wchar_t *)0x0)))) {
        sVar2 = wcslen((wchar_t *)puVar5[1]);
        if (sVar2 + 1 < 0x80000000) {
          uVar6 = (sVar2 + 1) * 2;
        }
        pwVar3 = operator_new(uVar6);
        *param_3 = (int)pwVar3;
        if (pwVar3 != (wchar_t *)0x0) {
          _Str1 = (wchar_t *)puVar5[1];
LAB_c03bd2fc:
          wcscpy(pwVar3,_Str1);
        }
      }
    }
LAB_c03bd304:
    operator_delete(_Dest);
  }
  return puVar5;
}



/* c03bd33c FUN_c03bd33c */

/* Boundary evidence: original MIPS .pdata c03bd33c..c03bd433. Semantic name remains unreviewed. */

undefined4 * FUN_c03bd33c(int param_1,wchar_t *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_18 [2];
  
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  puVar1 = FUN_c03bcf4c(param_1,param_2,local_18,0,0,(undefined4 *)0x0);
  puVar2 = operator_new(0x18);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0xffffffff;
  }
  else {
    puVar2[2] = puVar1;
    *puVar2 = 0x54475447;
    puVar2[3] = local_18[0];
    puVar2[5] = 0;
    puVar2[1] = 0;
    if (puVar1 == (undefined4 *)0x0) {
      if (param_1 == 0) {
        return puVar2;
      }
      puVar2[4] = *(undefined4 *)(param_1 + 0x24);
      if (*(int *)(param_1 + 0x24) != 0) {
        *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x14) = puVar2;
      }
      *(undefined4 **)(param_1 + 0x24) = puVar2;
    }
    else {
      puVar2[4] = puVar1[4];
      if (puVar1[4] != 0) {
        *(undefined4 **)(puVar1[4] + 0x14) = puVar2;
      }
      puVar1[4] = puVar2;
    }
    if (param_1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
  }
  return puVar2;
}



/* c03bd434 FUN_c03bd434 */

/* Boundary evidence: original MIPS .pdata c03bd434..c03bd67f. Semantic name remains unreviewed. */

undefined4
FUN_c03bd434(int param_1,HANDLE param_2,wchar_t *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  HANDLE pvVar3;
  BOOL BVar4;
  int iVar5;
  LPHANDLE lpTargetHandle;
  HANDLE local_20;
  HANDLE local_1c;
  
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  puVar1 = FUN_c03bcf4c(param_1,param_3,(int *)0x0,1,0,(undefined4 *)0x0);
  puVar2 = operator_new(0x34);
  if (puVar2 == (undefined4 *)0x0) {
LAB_c03bd4a0:
    if (param_1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
    return 0xffffffff;
  }
  puVar2[6] = 0;
  *puVar2 = 0x44474447;
  puVar2[2] = param_5;
  puVar2[1] = param_2;
  puVar2[3] = param_4;
  pvVar3 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  puVar2[4] = pvVar3;
  if (pvVar3 == (HANDLE)0x0) {
    operator_delete(puVar2);
    goto LAB_c03bd4a0;
  }
  puVar2[10] = puVar1;
  puVar2[0xc] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    if (param_1 == 0) goto LAB_c03bd574;
    puVar2[0xb] = *(undefined4 *)(param_1 + 0x20);
    if (*(int *)(param_1 + 0x20) != 0) {
      *(undefined4 **)(*(int *)(param_1 + 0x20) + 0x30) = puVar2;
    }
    *(undefined4 **)(param_1 + 0x20) = puVar2;
  }
  else {
    puVar2[0xb] = puVar1[3];
    if (puVar1[3] != 0) {
      *(undefined4 **)(puVar1[3] + 0x30) = puVar2;
    }
    puVar1[3] = puVar2;
  }
  if (param_1 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
LAB_c03bd574:
  puVar2[7] = param_1;
  local_20 = (HANDLE)CreateAPIHandle(DAT_c03c6284,puVar2);
  pvVar3 = (HANDLE)__GetUserKData(0xc);
  lpTargetHandle = (LPHANDLE)(puVar2 + 5);
  BVar4 = DuplicateHandle(pvVar3,local_20,param_2,lpTargetHandle,0,0,3);
  if (BVar4 == 0) {
    return 0xffffffff;
  }
  iVar5 = SetEventData(puVar2[4],*lpTargetHandle);
  if (iVar5 != 0) {
    pvVar3 = (HANDLE)__GetUserKData(0xc);
    BVar4 = DuplicateHandle(pvVar3,(HANDLE)puVar2[4],param_2,&local_1c,0,0,2);
    if (BVar4 != 0) {
      return local_1c;
    }
  }
  pvVar3 = (HANDLE)__GetUserKData(0xc);
  DuplicateHandle(param_2,*lpTargetHandle,pvVar3,&local_20,0,0,3);
  CloseHandle(local_20);
  return 0xffffffff;
}



/* c03bd680 FUN_c03bd680 */

/* Boundary evidence: original MIPS .pdata c03bd680..c03bd75f. Semantic name remains unreviewed. */

void FUN_c03bd680(int param_1,void *param_2)

{
  void *pvVar1;
  
  while ((((param_2 != (void *)0x0 && (*(int *)((int)param_2 + 0x10) == 0)) &&
          (*(int *)((int)param_2 + 0xc) == 0)) && (*(int *)((int)param_2 + 0x14) == 0))) {
    pvVar1 = *(void **)((int)param_2 + 0x18);
    if (pvVar1 == (void *)0x0) {
      if (*(void **)(param_1 + 0x1c) == param_2) {
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)((int)param_2 + 0x1c);
      }
    }
    else if (*(void **)((int)pvVar1 + 0x14) == param_2) {
      *(undefined4 *)((int)pvVar1 + 0x14) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    if (*(int *)((int)param_2 + 0x20) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x20) + 0x1c) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    if (*(int *)((int)param_2 + 0x1c) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x1c) + 0x20) = *(undefined4 *)((int)param_2 + 0x20);
    }
    if (*(void **)((int)param_2 + 4) != (void *)0x0) {
      operator_delete(*(void **)((int)param_2 + 4));
    }
    operator_delete(param_2);
    param_2 = pvVar1;
  }
  return;
}



/* c03bd760 FUN_c03bd760 */

/* Boundary evidence: original MIPS .pdata c03bd760..c03bd843. Semantic name remains unreviewed. */

undefined4 FUN_c03bd760(void *param_1)

{
  int iVar1;
  
  if (*(int *)((int)param_1 + 0x1c) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)((int)param_1 + 0x1c) + 4));
    iVar1 = *(int *)((int)param_1 + 0x28);
    if (iVar1 == 0) {
      if (*(void **)(*(int *)((int)param_1 + 0x1c) + 0x20) == param_1) {
        *(undefined4 *)(*(int *)((int)param_1 + 0x1c) + 0x20) = *(undefined4 *)((int)param_1 + 0x2c)
        ;
      }
    }
    else if (*(void **)(iVar1 + 0xc) == param_1) {
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)((int)param_1 + 0x2c);
    }
    if (*(int *)((int)param_1 + 0x30) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x30) + 0x2c) = *(undefined4 *)((int)param_1 + 0x2c);
    }
    if (*(int *)((int)param_1 + 0x2c) != 0) {
      *(undefined4 *)(*(int *)((int)param_1 + 0x2c) + 0x30) = *(undefined4 *)((int)param_1 + 0x30);
    }
    if (*(void **)((int)param_1 + 0x28) != (void *)0x0) {
      FUN_c03bd680(*(int *)((int)param_1 + 0x1c),*(void **)((int)param_1 + 0x28));
    }
    if (*(int *)((int)param_1 + 0x1c) != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)((int)param_1 + 0x1c) + 4));
    }
  }
  FUN_c03bcef0((int)param_1);
  CloseHandle(*(HANDLE *)((int)param_1 + 0x10));
  operator_delete(param_1);
  return 1;
}



/* c03bd844 FUN_c03bd844 */

/* Boundary evidence: original MIPS .pdata c03bd844..c03bd95f. Semantic name remains unreviewed. */

void FUN_c03bd844(int param_1,wchar_t *param_2,uint param_3,undefined4 param_4)

{
  size_t sVar1;
  undefined4 *puVar2;
  wchar_t *_Dest;
  uint uVar3;
  
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
      if ((((*(uint *)(param_1 + 8) & 0x80000000) != 0) && ((*(uint *)(param_1 + 8) & param_3) != 0)
          ) && (puVar2 = operator_new(0x10), puVar2 != (undefined4 *)0x0)) {
        puVar2[1] = sVar1 << 1;
        if (sVar1 + 1 < 0x80000000) {
          uVar3 = (sVar1 + 1) * 2;
        }
        else {
          uVar3 = 0xffffffff;
        }
        _Dest = operator_new(uVar3);
        *puVar2 = _Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,param_2);
        }
        puVar2[2] = param_4;
        puVar2[3] = 0;
        if (*(int *)(param_1 + 0x20) == 0) {
          *(undefined4 **)(param_1 + 0x20) = puVar2;
        }
        if (*(int *)(param_1 + 0x24) != 0) {
          *(undefined4 **)(*(int *)(param_1 + 0x24) + 0xc) = puVar2;
        }
        *(undefined4 **)(param_1 + 0x24) = puVar2;
      }
    }
  }
  return;
}



/* c03bd960 FUN_c03bd960 */

/* Boundary evidence: original MIPS .pdata c03bd960..c03bda0f. Semantic name remains unreviewed. */

void FUN_c03bd960(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
    if ((param_2 != 0) || (*(int *)(param_1 + 0xc) != 0)) {
      if (param_3 == 0) {
        uVar1 = *(uint *)(param_1 + 8) & 1;
      }
      else {
        uVar1 = *(uint *)(param_1 + 8) & 2;
      }
      if (uVar1 != 0) {
        if (*(int *)(param_1 + 0x18) == 0) {
          EventModify(*(undefined4 *)(param_1 + 0x10),3);
        }
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      }
    }
  }
  return;
}



/* c03bda10 FUN_c03bda10 */

/* Boundary evidence: original MIPS .pdata c03bda10..c03bdc63. Semantic name remains unreviewed. */

void FUN_c03bda10(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  wchar_t *local_38;
  int local_34;
  wchar_t *local_30;
  
  local_34 = 1;
  local_38 = (wchar_t *)0x0;
  local_30 = param_2;
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  uVar5 = 2;
  if ((param_4 == 0) || ((param_5 != 2 && (param_5 != 4)))) {
    if (param_3 == (wchar_t *)0x0) {
      puVar1 = FUN_c03bcf4c(param_1,local_30,(int *)&local_38,0,1,&local_34);
      pwVar4 = local_38;
      param_3 = local_38;
    }
    else {
      puVar1 = FUN_c03bcf4c(param_1,local_30,(int *)0x0,0,1,&local_34);
      pwVar4 = (wchar_t *)0x0;
    }
    iVar2 = local_34;
    if (local_34 == 0) goto LAB_c03bdbe4;
    if (param_4 == 0) {
      uVar5 = 1;
    }
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar3 = puVar1[3];
    }
  }
  else {
    puVar1 = FUN_c03bcf4c(param_1,local_30,(int *)&local_38,param_4,1,(undefined4 *)0x0);
    pwVar4 = local_38;
    if (puVar1 == (undefined4 *)0x0) {
LAB_c03bdafc:
      if (pwVar4 != (wchar_t *)0x0) {
        operator_delete(pwVar4);
        local_38 = (wchar_t *)0x0;
      }
    }
    else if (local_38 != (wchar_t *)0x0) {
      iVar2 = wcscmp(local_38,(wchar_t *)puVar1[1]);
      if (iVar2 == 0) {
        FUN_c03bd844(puVar1[3],L"\\",2,2);
        FUN_c03bd960(puVar1[3],1,param_4);
      }
      goto LAB_c03bdafc;
    }
    puVar1 = FUN_c03bcf4c(param_1,local_30,(int *)&local_38,0,1,&local_34);
    iVar2 = local_34;
    pwVar4 = local_38;
    if (local_34 == 0) goto LAB_c03bdbe4;
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar3 = puVar1[3];
    }
    uVar5 = 2;
    param_3 = local_38;
  }
  iVar2 = local_34;
  FUN_c03bd844(iVar3,param_3,uVar5,param_5);
LAB_c03bdbe4:
  if (pwVar4 != (wchar_t *)0x0) {
    operator_delete(pwVar4);
  }
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[6]) {
    FUN_c03bd960(puVar1[3],iVar2,param_4);
    iVar2 = 0;
  }
  if (param_1 != 0) {
    FUN_c03bd960(*(int *)(param_1 + 0x20),iVar2,param_4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



/* c03bdc64 FUN_c03bdc64 */

/* Boundary evidence: original MIPS .pdata c03bdc64..c03bdc87. Semantic name remains unreviewed. */

void FUN_c03bdc64(int param_1,wchar_t *param_2,int param_3,int param_4)

{
  FUN_c03bda10(param_1,param_2,(wchar_t *)0x0,param_3,param_4);
  return;
}



/* c03bdc88 FUN_c03bdc88 */

/* Boundary evidence: original MIPS .pdata c03bdc88..c03bdcdb. Semantic name remains unreviewed. */

void FUN_c03bdc88(wchar_t *param_1)

{
  size_t sVar1;
  wchar_t *pwVar2;
  
  sVar1 = wcslen(param_1);
  if (sVar1 != 0) {
    pwVar2 = param_1 + sVar1;
    do {
      if (*pwVar2 == L'\\') {
        return;
      }
      sVar1 = sVar1 - 1;
      pwVar2 = pwVar2 + -1;
    } while (sVar1 != 0);
  }
  return;
}



/* c03bdcdc FUN_c03bdcdc */

/* Boundary evidence: original MIPS .pdata c03bdcdc..c03bdddf. Semantic name remains unreviewed. */

void FUN_c03bdcdc(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4)

{
  bool bVar1;
  size_t _MaxCount;
  size_t sVar2;
  int iVar3;
  int iVar4;
  
  _MaxCount = FUN_c03bdc88(param_2);
  iVar4 = 1;
  bVar1 = true;
  sVar2 = FUN_c03bdc88(param_3);
  if ((_MaxCount != sVar2) || (iVar3 = wcsncmp(param_2,param_3,_MaxCount), iVar3 != 0)) {
    bVar1 = false;
  }
  if (param_1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  iVar3 = 4;
  if (!bVar1) {
    iVar3 = 2;
  }
  FUN_c03bda10(param_1,param_2,(wchar_t *)0x0,param_4,iVar3);
  if (bVar1) {
    iVar4 = 5;
  }
  FUN_c03bda10(param_1,param_3,(wchar_t *)0x0,param_4,iVar4);
  if (param_1 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



/* c03bdde0 FUN_c03bdde0 */

/* Boundary evidence: original MIPS .pdata c03bdde0..c03bddfb. Semantic name remains unreviewed. */

void FUN_c03bdde0(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  FUN_c03bdcdc(param_1,param_2,param_3,0);
  return;
}



/* c03bddfc FUN_c03bddfc */

/* Boundary evidence: original MIPS .pdata c03bddfc..c03be18b. Semantic name remains unreviewed. */

int FUN_c03bddfc(int param_1,int param_2)

{
  DWORD dwErrCode;
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_48;
  
  iVar6 = 1;
  iVar7 = *(int *)(param_1 + 0x1c);
  SetLastError(0);
  if (iVar7 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar7 + 4));
  }
  EventModify(*(undefined4 *)(param_1 + 0x10),2);
  if ((param_2 == 0) || (*(int *)(param_1 + 0x18) == 0)) {
    if (*(int *)(param_1 + 0x18) == 0) {
      if (param_2 != 0) {
        **(undefined4 **)(param_2 + 0xc) = 0;
        **(undefined4 **)(param_2 + 0x10) = 0;
        SetLastError(0x103);
        iVar6 = 0;
      }
    }
    else {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    }
  }
  else {
    uVar10 = 0;
    uVar8 = 0;
    local_48 = 0;
    puVar2 = (uint *)0x0;
    uVar5 = 0;
    while (puVar4 = *(undefined4 **)(param_1 + 0x20), puVar4 != (undefined4 *)0x0) {
      if ((puVar4[1] + 2 < 2) || (uVar9 = puVar4[1] + 0x12, uVar9 < 0x10)) {
        SetLastError(0x216);
        iVar6 = 0;
        break;
      }
      if ((uVar9 & 3) != 0) {
        uVar9 = (uVar9 - (uVar9 & 3)) + 4;
      }
      uVar1 = uVar9 + local_48;
      if ((*(uint *)(param_2 + 8) < uVar1) || (uVar1 < uVar9)) {
        if (uVar10 == 0) {
          dwErrCode = 0x7a;
        }
        else {
          dwErrCode = 0xea;
        }
        SetLastError(dwErrCode);
        break;
      }
      if (puVar2 != (uint *)0x0) {
        *puVar2 = uVar5;
      }
      puVar2 = (uint *)(*(int *)(param_2 + 4) + local_48);
      *puVar2 = 0;
      puVar2[1] = puVar4[2];
      puVar2[2] = puVar4[1];
      memcpy(puVar2 + 3,(void *)*puVar4,puVar4[1] + 2);
      uVar10 = uVar10 + 1;
      *(undefined4 *)(param_1 + 0x20) = puVar4[3];
      operator_delete((void *)*puVar4);
      operator_delete(puVar4);
      uVar5 = uVar9;
      local_48 = uVar1;
    }
    iVar3 = *(int *)(param_1 + 0x20);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (*(int *)(param_2 + 0x10) != 0) {
      for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xc)) {
        uVar8 = *(int *)(iVar3 + 4) + uVar8 + 0x12;
        if ((uVar8 & 3) != 0) {
          uVar8 = (uVar8 - (uVar8 & 3)) + 4;
        }
      }
      **(uint **)(param_2 + 0x10) = uVar8;
    }
    if (*(uint **)(param_2 + 0xc) != (uint *)0x0) {
      **(uint **)(param_2 + 0xc) = local_48;
    }
    if (uVar10 < *(uint *)(param_1 + 0x18)) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) - uVar10;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  if ((iVar6 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    EventModify(*(undefined4 *)(param_1 + 0x10),3);
  }
  if (iVar7 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar7 + 4));
  }
  return iVar6;
}



/* c03be18c FUN_c03be18c */

/* Boundary evidence: original MIPS .pdata c03be18c..c03be197. Semantic name remains unreviewed. */

undefined4 FUN_c03be18c(void)

{
  return 1;
}



/* c03be198 FUN_c03be198 */

/* Boundary evidence: original MIPS .pdata c03be198..c03be1a3. Semantic name remains unreviewed. */

undefined4 FUN_c03be198(void)

{
  return 1;
}



/* c03be1a4 FUN_c03be1a4 */

/* Boundary evidence: original MIPS .pdata c03be1a4..c03be233. Semantic name remains unreviewed. */

void FUN_c03be1a4(int param_1,uint param_2,int param_3)

{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
    if (((param_3 != 0) || (*(int *)(param_1 + 0xc) != 0)) &&
       ((*(uint *)(param_1 + 8) & param_2) != 0)) {
      if (*(int *)(param_1 + 0x18) == 0) {
        EventModify(*(undefined4 *)(param_1 + 0x10),3);
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    }
  }
  return;
}



/* c03be234 FUN_c03be234 */

/* Boundary evidence: original MIPS .pdata c03be234..c03be323. Semantic name remains unreviewed. */

void FUN_c03be234(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = 1;
  iVar1 = FUN_c03bcbec();
  if (iVar1 != 0) {
    if (param_1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 2;
    if (iVar2 == 0) {
      iVar1 = *(int *)(param_1 + 0x20);
    }
    else {
      iVar1 = *(int *)(iVar2 + 0xc);
    }
    FUN_c03bd844(iVar1,*(wchar_t **)(param_2 + 0xc),param_3,param_4);
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
      FUN_c03be1a4(*(int *)(iVar2 + 0xc),param_3,iVar3);
      iVar3 = 0;
    }
    FUN_c03be1a4(*(int *)(param_1 + 0x20),param_3,iVar3);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



/* c03be324 FUN_c03be324 */

/* Boundary evidence: original MIPS .pdata c03be324..c03be33f. Semantic name remains unreviewed. */

void FUN_c03be324(int param_1,int param_2,uint param_3)

{
  FUN_c03be234(param_1,param_2,param_3,3);
  return;
}



/* c03be340 FUN_c03be340 */

/* Boundary evidence: original MIPS .pdata c03be340..c03be45f. Semantic name remains unreviewed. */

undefined4
FUN_c03be340(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  iVar1 = GetEventData();
  if (iVar1 == 0) {
    SetLastError(6);
    uVar2 = 0;
  }
  else if ((((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) &&
          ((param_5 == 0 && (param_6 == 0)))) {
    uVar2 = (*(code *)&SUB_ffff9bfa)(iVar1,0,0);
  }
  else {
    local_24 = param_5;
    local_20 = param_6;
    local_30 = param_2;
    local_2c = param_3;
    local_28 = param_4;
    uVar2 = (*(code *)&SUB_ffff9bfa)(iVar1,&local_30,0x14);
  }
  return uVar2;
}



/* c03be460 FUN_c03be460 */

/* Boundary evidence: original MIPS .pdata c03be460..c03be46b. Semantic name remains unreviewed. */

undefined4 FUN_c03be460(void)

{
  return 1;
}



/* c03be46c FUN_c03be46c */

/* Boundary evidence: original MIPS .pdata c03be46c..c03be683. Semantic name remains unreviewed. */

undefined4 FUN_c03be46c(HANDLE param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  HANDLE pvVar1;
  BOOL BVar2;
  HANDLE hSourceProcessHandle;
  undefined4 uVar3;
  code *pcVar4;
  HANDLE local_res0 [4];
  HANDLE local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_res0[0] = param_1;
  pvVar1 = (HANDLE)GetCallerVMProcessId();
  BVar2 = DuplicateHandle(pvVar1,local_res0[0],(HANDLE)0x42,local_res0,0,0,2);
  if (BVar2 != 0) {
    pvVar1 = (HANDLE)GetEventData(local_res0[0]);
    if (pvVar1 == (HANDLE)0x0) {
      CloseHandle(local_res0[0]);
      pvVar1 = (HANDLE)0x6;
      pcVar4 = SetLastError_exref;
    }
    else {
      hSourceProcessHandle = (HANDLE)GetCallerVMProcessId();
      BVar2 = DuplicateHandle(hSourceProcessHandle,pvVar1,(HANDLE)0x42,&local_40,0,0,2);
      pvVar1 = local_res0[0];
      pcVar4 = CloseHandle_exref;
      if (BVar2 != 0) {
        if ((((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) &&
           ((param_5 == 0 && (param_6 == 0)))) {
          uVar3 = (*(code *)&SUB_ffff9bfa)(local_40,0,0);
        }
        else {
          local_2c = param_5;
          local_28 = param_6;
          local_38 = param_2;
          local_34 = param_3;
          local_30 = param_4;
          uVar3 = (*(code *)&SUB_ffff9bfa)(local_40,&local_38,0x14);
        }
        local_3c = uVar3;
        CloseHandle(local_res0[0]);
        CloseHandle(local_40);
        return uVar3;
      }
    }
    (*pcVar4)(pvVar1);
  }
  return 0;
}



/* c03be684 FUN_c03be684 */

/* Boundary evidence: original MIPS .pdata c03be684..c03be68f. Semantic name remains unreviewed. */

undefined4 FUN_c03be684(void)

{
  return 1;
}



/* c03be690 FUN_c03be690 */

/* Boundary evidence: original MIPS .pdata c03be690..c03be6db. Semantic name remains unreviewed. */

BOOL FUN_c03be690(void)

{
  HANDLE hObject;
  BOOL BVar1;
  
  hObject = (HANDLE)GetEventData();
  if (hObject == (HANDLE)0x0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = CloseHandle(hObject);
  }
  return BVar1;
}



/* c03be6dc FUN_c03be6dc */

/* Boundary evidence: original MIPS .pdata c03be6dc..c03be7df. Semantic name remains unreviewed. */

BOOL FUN_c03be6dc(HANDLE param_1)

{
  HANDLE pvVar1;
  BOOL BVar2;
  HANDLE hSourceProcessHandle;
  HANDLE local_res0 [4];
  HANDLE local_20 [2];
  
  local_res0[0] = param_1;
  pvVar1 = (HANDLE)GetCallerVMProcessId();
  BVar2 = DuplicateHandle(pvVar1,local_res0[0],(HANDLE)0x42,local_res0,0,0,3);
  if (BVar2 != 0) {
    pvVar1 = (HANDLE)GetEventData(local_res0[0]);
    if (pvVar1 == (HANDLE)0x0) {
      CloseHandle(local_res0[0]);
      SetLastError(6);
    }
    else {
      CloseHandle(local_res0[0]);
      hSourceProcessHandle = (HANDLE)GetCallerVMProcessId();
      BVar2 = DuplicateHandle(hSourceProcessHandle,pvVar1,(HANDLE)0x42,local_20,0,0,3);
      if (BVar2 != 0) {
        BVar2 = CloseHandle(local_20[0]);
        return BVar2;
      }
    }
  }
  return 0;
}



/* c03be7e0 FUN_c03be7e0 */

/* Boundary evidence: original MIPS .pdata c03be7e0..c03be83f. Semantic name remains unreviewed. */

void FUN_c03be7e0(int param_1)

{
  int iVar1;
  
  for (iVar1 = param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x2c)) {
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  FUN_c03bd844(param_1,L"\\",2,2);
  FUN_c03bd960(param_1,1,1);
  return;
}



/* c03be840 FUN_c03be840 */

/* Boundary evidence: original MIPS .pdata c03be840..c03be8b7. Semantic name remains unreviewed. */

void FUN_c03be840(void *param_1)

{
  void *pvVar1;
  
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  do {
    FUN_c03bce98(*(void **)((int)param_1 + 0x10));
    FUN_c03be7e0(*(int *)((int)param_1 + 0xc));
    if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
      FUN_c03be840(*(void **)((int)param_1 + 0x14));
    }
    pvVar1 = *(void **)((int)param_1 + 0x1c);
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    if (*(void **)((int)param_1 + 4) != (void *)0x0) {
      operator_delete(*(void **)((int)param_1 + 4));
    }
    operator_delete(param_1);
    param_1 = pvVar1;
  } while (pvVar1 != (void *)0x0);
  return;
}



/* c03be8b8 FUN_c03be8b8 */

/* Boundary evidence: original MIPS .pdata c03be8b8..c03be9af. Semantic name remains unreviewed. */

void FUN_c03be8b8(void *param_1)

{
  void *pvVar1;
  void *pvVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_1 != (void *)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 4);
    EnterCriticalSection(lpCriticalSection);
    if (*(void **)((int)param_1 + 0x1c) != (void *)0x0) {
      FUN_c03be840(*(void **)((int)param_1 + 0x1c));
    }
    FUN_c03bce98(*(void **)((int)param_1 + 0x24));
    FUN_c03be7e0(*(int *)((int)param_1 + 0x20));
    LeaveCriticalSection(lpCriticalSection);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6270);
    pvVar2 = DAT_c03c6288;
    if (DAT_c03c6288 == param_1) {
      DAT_c03c6288 = *(void **)((int)param_1 + 0x28);
    }
    else {
      do {
        pvVar1 = pvVar2;
        if (pvVar1 == (void *)0x0) goto LAB_c03be96c;
        pvVar2 = *(void **)((int)pvVar1 + 0x28);
      } while (*(void **)((int)pvVar1 + 0x28) != param_1);
      *(undefined4 *)((int)pvVar1 + 0x28) = *(undefined4 *)((int)param_1 + 0x28);
    }
LAB_c03be96c:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c03c6270);
    DeleteCriticalSection(lpCriticalSection);
    if (*(void **)((int)param_1 + 0x18) != (void *)0x0) {
      operator_delete(*(void **)((int)param_1 + 0x18));
    }
    operator_delete(param_1);
  }
  return;
}



/* c03be9b0 FUN_c03be9b0 */

/* Boundary evidence: original MIPS .pdata c03be9b0..c03beadf. Semantic name remains unreviewed. */

void FUN_c03be9b0(int param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = FUN_c03bcbec();
  if (iVar1 != 0) {
    if ((*(uint *)((int)param_2 + 4) & 2) != 0) {
      FUN_c03be234(param_1,(int)param_2,0x7c,0x10000);
    }
    if (param_1 != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
    iVar1 = *(int *)((int)param_2 + 8);
    if (iVar1 == 0) {
      if ((param_1 != 0) && (*(void **)(param_1 + 0x24) == param_2)) {
        *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)((int)param_2 + 0x10);
      }
    }
    else if (*(void **)(iVar1 + 0x10) == param_2) {
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)((int)param_2 + 0x10);
    }
    if (*(int *)((int)param_2 + 0x14) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x14) + 0x10) = *(undefined4 *)((int)param_2 + 0x10);
    }
    if (*(int *)((int)param_2 + 0x10) != 0) {
      *(undefined4 *)(*(int *)((int)param_2 + 0x10) + 0x14) = *(undefined4 *)((int)param_2 + 0x14);
    }
    iVar1 = FUN_c03bcbec();
    if (iVar1 != 0) {
      FUN_c03bd680(param_1,*(void **)((int)param_2 + 8));
    }
    if (param_1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    }
    if (*(void **)((int)param_2 + 0xc) != (void *)0x0) {
      operator_delete(*(void **)((int)param_2 + 0xc));
    }
    operator_delete(param_2);
  }
  return;
}



/* c03beae0 FUN_c03beae0 */

/* Boundary evidence: original MIPS .pdata c03beae0..c03bec9b. Semantic name remains unreviewed. */

undefined4
FUN_c03beae0(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
            uint param_6)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int local_30 [2];
  
  local_30[0] = 0;
  uVar5 = 0;
  memset(param_5,0,param_6 << 2);
  if (param_3 < 0x1c) {
    uVar4 = 0x57;
  }
  else {
    iVar1 = CeAllocDuplicateBuffer(local_30,param_2,param_3,4);
    if (iVar1 == -0x7ff8fff2) {
LAB_c03bec2c:
      uVar4 = 0xe;
    }
    else {
      if ((-1 < iVar1) && (*(uint *)(local_30[0] + 8) <= param_6)) {
        uVar5 = 0;
        if (*(uint *)(local_30[0] + 8) != 0) {
          iVar1 = 0;
          puVar6 = param_5;
          do {
            puVar3 = (undefined4 *)(iVar1 + local_30[0] + 0x14);
            uVar4 = *puVar3;
            *puVar6 = uVar4;
            iVar2 = CeOpenCallerBuffer(puVar3,uVar4,*(undefined4 *)(iVar1 + local_30[0] + 0x18),
                                       param_4,0);
            if (iVar2 == -0x7ff8fff2) goto LAB_c03bec2c;
            if (iVar2 < 0) goto LAB_c03beb7c;
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + 1;
            iVar1 = iVar1 + 8;
          } while (uVar5 < *(uint *)(local_30[0] + 8));
        }
        *param_1 = local_30[0];
        return 0;
      }
LAB_c03beb7c:
      uVar4 = 0x57;
    }
    if (local_30[0] != 0) {
      if (uVar5 != 0) {
        iVar1 = 0;
        do {
          CeCloseCallerBuffer(*(undefined4 *)(iVar1 + local_30[0] + 0x14),*param_5,
                              *(undefined4 *)(iVar1 + local_30[0] + 0x18),param_4);
          param_5 = param_5 + 1;
          uVar5 = uVar5 - 1;
          iVar1 = iVar1 + 8;
        } while (uVar5 != 0);
      }
      CeFreeDuplicateBuffer(local_30[0],param_2,param_3,4);
    }
  }
  return uVar4;
}



/* c03bec9c FUN_c03bec9c */

/* Boundary evidence: original MIPS .pdata c03bec9c..c03bed73. Semantic name remains unreviewed. */

undefined4
FUN_c03bec9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,uint param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if (*(uint *)(param_1 + 8) <= param_6) {
    uVar3 = 0;
    if (*(uint *)(param_1 + 8) != 0) {
      puVar2 = (undefined4 *)(param_1 + 0x18);
      do {
        iVar1 = CeCloseCallerBuffer(puVar2[-1],*param_5,*puVar2,param_4);
        if (iVar1 < 0) {
          return 0x57;
        }
        uVar3 = uVar3 + 1;
        param_5 = param_5 + 1;
        puVar2 = puVar2 + 2;
      } while (uVar3 < *(uint *)(param_1 + 8));
    }
    iVar1 = CeFreeDuplicateBuffer(param_1,param_2,param_3,4);
    if (-1 < iVar1) {
      return 0;
    }
  }
  return 0x57;
}



/* c03bed74 FUN_c03bed74 */

/* Boundary evidence: original MIPS .pdata c03bed74..c03bef5b. Semantic name remains unreviewed. */

undefined4
FUN_c03bed74(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
            uint param_6)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int local_30 [2];
  
  local_30[0] = 0;
  uVar5 = 0;
  memset(param_5,0,param_6 << 2);
  if (param_3 < 0x20) {
    uVar4 = 0x57;
  }
  else {
    iVar1 = CeAllocDuplicateBuffer(local_30,param_2,param_3,4);
    if (iVar1 == -0x7ff8fff2) {
LAB_c03beedc:
      uVar4 = 0xe;
    }
    else {
      if ((-1 < iVar1) && (*(uint *)(local_30[0] + 0x14) <= param_6)) {
        uVar5 = 0;
        if (*(uint *)(local_30[0] + 0x14) != 0) {
          iVar1 = 0;
          puVar6 = param_5;
          do {
            puVar3 = (undefined4 *)(iVar1 + local_30[0] + 0x18);
            uVar4 = *puVar3;
            *puVar6 = uVar4;
            iVar2 = CeOpenCallerBuffer(puVar3,uVar4,*(undefined4 *)(iVar1 + local_30[0] + 0x1c),
                                       param_4,0);
            if (iVar2 == -0x7ff8fff2) goto LAB_c03beedc;
            if (iVar2 < 0) goto LAB_c03bee10;
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + 1;
            iVar1 = iVar1 + 8;
          } while (uVar5 < *(uint *)(local_30[0] + 0x14));
        }
        *param_1 = local_30[0];
        return 0;
      }
LAB_c03bee10:
      uVar4 = 0x57;
    }
    if (local_30[0] != 0) {
      if (uVar5 != 0) {
        iVar1 = 0;
        do {
          CeCloseCallerBuffer(*(undefined4 *)(iVar1 + local_30[0] + 0x18),*param_5,
                              *(undefined4 *)(iVar1 + local_30[0] + 0x1c),param_4);
          param_5 = param_5 + 1;
          uVar5 = uVar5 - 1;
          iVar1 = iVar1 + 8;
        } while (uVar5 != 0);
      }
      CeFreeDuplicateBuffer(local_30[0],param_2,param_3,4);
    }
  }
  return uVar4;
}



/* c03bef5c FUN_c03bef5c */

/* Boundary evidence: original MIPS .pdata c03bef5c..c03bf053. Semantic name remains unreviewed. */

undefined4
FUN_c03bef5c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  if (uVar2 <= param_6) {
    uVar4 = 0;
    if (uVar2 != 0) {
      puVar3 = (undefined4 *)(param_1 + 0x18);
      do {
        iVar1 = CeCloseCallerBuffer(*puVar3,*param_5,puVar3[1],param_4);
        if (iVar1 < 0) {
          return 0x57;
        }
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 2;
        param_5 = param_5 + 1;
      } while (uVar4 < *(uint *)(param_1 + 0x14));
    }
    iVar1 = CeFreeDuplicateBuffer(param_1,param_2,param_3,4);
    if (-1 < iVar1) {
      return 0;
    }
  }
  return 0x57;
}



/* c03bf054 FUN_c03bf054 */

/* Boundary evidence: original MIPS .pdata c03bf054..c03bf3f7. Semantic name remains unreviewed. */

undefined4 FUN_c03bf054(int param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined1 **)(param_1 + 8) = &LAB_c03c1510;
  *(code **)(param_1 + 0xc) = FSDMGR_DeregisterVolume;
  *(code **)(param_1 + 0x10) = FUN_c03c1524;
  *(undefined1 **)(param_1 + 0x14) = &LAB_c03a3848;
  *(code **)(param_1 + 0x18) = FUN_c03c1640;
  *(undefined1 **)(param_1 + 0x1c) = &LAB_c03c1730;
  *(undefined1 **)(param_1 + 0x20) = &LAB_c03c1730;
  *(undefined1 **)(param_1 + 0x24) = &LAB_c03c1730;
  *(undefined1 **)(param_1 + 0x28) = &LAB_c03c1730;
  *(code **)(param_1 + 0x30) = FUN_c03c1738;
  *(code **)(param_1 + 0x34) = FUN_c03c1754;
  *(code **)(param_1 + 0x38) = FUN_c03c1844;
  *(code **)(param_1 + 0x3c) = FUN_c03c1894;
  *(code **)(param_1 + 0x40) = FUN_c03c19ac;
  *(undefined1 **)(param_1 + 0x44) = &LAB_c03c19c8;
  *(code **)(param_1 + 0x48) = FSDMGR_DeregisterVolume;
  *(undefined1 **)(param_1 + 0x2c) = &LAB_c03c1730;
  *(code **)(param_1 + 0x54) = FUN_c03c19d4;
  *(undefined1 **)(param_1 + 0x58) = &LAB_c03c1a34;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  uVar3 = 0;
  if (*param_2 != 0) {
    iVar1 = LoadDriver(param_2);
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) {
      uVar3 = 2;
    }
    else {
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 8) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0xc) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x10) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x14) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x18) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x1c) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x20) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x24) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x28) = uVar2;
      iVar1 = FUN_c03acd88();
      *(int *)(param_1 + 0x2c) = iVar1;
      if (iVar1 == 0) {
        *(undefined1 **)(param_1 + 0x2c) = &LAB_c03c1730;
      }
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x30) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x34) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x38) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x3c) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x40) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x44) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x48) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x54) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x58) = uVar2;
      uVar2 = FUN_c03acd88();
      *(undefined4 *)(param_1 + 0x5c) = uVar2;
      if (((((((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
             (*(int *)(param_1 + 0x10) == 0)) ||
            ((*(int *)(param_1 + 0x14) == 0 || (*(int *)(param_1 + 0x18) == 0)))) ||
           ((*(int *)(param_1 + 0x1c) == 0 ||
            ((*(int *)(param_1 + 0x20) == 0 || (*(int *)(param_1 + 0x24) == 0)))))) ||
          (*(int *)(param_1 + 0x28) == 0)) ||
         ((((*(int *)(param_1 + 0x30) == 0 || (*(int *)(param_1 + 0x34) == 0)) ||
           (*(int *)(param_1 + 0x38) == 0)) ||
          (((*(int *)(param_1 + 0x3c) == 0 || (*(int *)(param_1 + 0x40) == 0)) ||
           ((*(int *)(param_1 + 0x44) == 0 ||
            ((*(int *)(param_1 + 0x48) == 0 || (*(int *)(param_1 + 0x54) == 0)))))))))) {
        uVar3 = 0x7d1;
      }
    }
  }
  return uVar3;
}



/* c03bf3f8 FUN_c03bf3f8 */

/* Boundary evidence: original MIPS .pdata c03bf3f8..c03bf41f. Semantic name remains unreviewed. */

void FUN_c03bf3f8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x38c) + 8))();
  return;
}



/* c03bf420 FUN_c03bf420 */

/* Boundary evidence: original MIPS .pdata c03bf420..c03bf45f. Semantic name remains unreviewed. */

undefined4 FUN_c03bf420(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
  HVar1 = StringCchCopyW(param_2,param_3,(STRSAFE_LPCWSTR)(param_1 + 0x340));
  if (HVar1 < 0) {
    uVar2 = 0x7a;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03bf468 FUN_c03bf468 */

/* Boundary evidence: original MIPS .pdata c03bf468..c03bf6a7. Semantic name remains unreviewed. */

DWORD FUN_c03bf468(int param_1,HKEY param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  STRSAFE_LPWSTR pwVar1;
  void *pvVar2;
  int iVar3;
  HRESULT HVar4;
  STRSAFE_LPWSTR pwVar5;
  DWORD DVar6;
  uint uVar7;
  HKEY local_468;
  STRSAFE_LPWSTR local_464;
  STRSAFE_LPWSTR local_460;
  HKEY local_45c;
  size_t local_458;
  undefined4 auStack_450 [4];
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  DVar6 = 0x3ed;
  local_464 = param_3;
  local_45c = param_2;
  local_458 = param_4;
  pwVar1 = FUN_c03a2f08(param_2,3,(STRSAFE_LPCWSTR)0x0,(STRSAFE_LPWSTR)0x0,0);
  uVar7 = *(uint *)(*(int *)(param_1 + 0x38c) + 0xce8);
  local_460 = pwVar1;
  if (pwVar1 != (STRSAFE_LPWSTR)0x0) {
    pvVar2 = operator_new(uVar7);
    if (pvVar2 != (void *)0x0) {
      iVar3 = FSDMGR_ReadDisk(param_1,0,1,pvVar2,uVar7);
      if (iVar3 != 0) {
        operator_delete(pvVar2);
        pvVar2 = (void *)0x0;
      }
    }
    local_468 = (HKEY)0xc03a2e4c;
    do {
      if (DVar6 != 0x3ed) break;
      local_468 = (HKEY)0x0;
      iVar3 = FUN_c03acd00(local_45c,pwVar1 + 0x104,&local_468);
      if (iVar3 == 0) {
        iVar3 = FUN_c03acbc4(local_468,L"Guid",awStack_440,0x104);
        if ((((iVar3 != 0) && (iVar3 = FUN_c03aca40(awStack_440,(int)auStack_450), iVar3 != 0)) &&
            (iVar3 = FUN_c03acbc4(local_468,L"Dll",awStack_440,0x104), iVar3 != 0)) &&
           (iVar3 = FUN_c03acbc4(local_468,L"Export",awStack_238,0x104), iVar3 != 0)) {
          DVar6 = FUN_c03c1a3c((undefined4 *)(param_1 + 0x2dc),param_1,awStack_440,awStack_238,
                               auStack_450,pvVar2,uVar7);
        }
        FUN_c03acd64(local_468);
        local_468 = (HKEY)0x0;
        if ((DVar6 == 0) && (HVar4 = StringCchCopyW(local_464,local_458,pwVar1 + 0x104), HVar4 < 0))
        {
          DVar6 = 0x7a;
        }
      }
      pwVar1 = *(STRSAFE_LPWSTR *)(pwVar1 + 0x20a);
    } while (pwVar1 != (STRSAFE_LPWSTR)0x0);
    pwVar1 = local_460;
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    do {
      pwVar5 = *(STRSAFE_LPWSTR *)(pwVar1 + 0x20a);
      operator_delete(pwVar1);
      pwVar1 = pwVar5;
    } while (pwVar5 != (STRSAFE_LPWSTR)0x0);
  }
  FUN_c03c216c(local_30);
  return DVar6;
}



/* c03bf6a8 FUN_c03bf6a8 */

/* Boundary evidence: original MIPS .pdata c03bf6a8..c03bf7b3. Semantic name remains unreviewed. */

DWORD FUN_c03bf6a8(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  HRESULT HVar1;
  int iVar2;
  DWORD DVar3;
  int *piVar4;
  HKEY local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  piVar4 = *(int **)(param_1 + 8);
  DVar3 = 0x3ed;
  local_238[0] = (HKEY)0x0;
  local_28 = DAT_c03c531c;
  for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    HVar1 = StringCchPrintfW(awStack_230,0x104,L"%s\\%s\\Detectors",piVar4 + 1,
                             *(undefined4 *)(param_1 + 0xc));
    if (HVar1 < 0) {
      FUN_c03c216c(local_28);
      return 0x3f8;
    }
    iVar2 = FUN_c03acd2c(awStack_230,local_238);
    if (iVar2 == 0) {
      DVar3 = FUN_c03bf468(param_1,local_238[0],param_2,param_3);
      FUN_c03acd64(local_238[0]);
      if (DVar3 != 0x3ed) break;
      local_238[0] = (HKEY)0x0;
    }
  }
  FUN_c03c216c(local_28);
  return DVar3;
}



/* c03bf7b4 FUN_c03bf7b4 */

/* Boundary evidence: original MIPS .pdata c03bf7b4..c03bf8af. Semantic name remains unreviewed. */

undefined4 FUN_c03bf7b4(int param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  HLOCAL local_1c;
  SIZE_T local_18;
  
  uVar2 = 1;
  memset(&local_2c,0,0x18);
  local_30 = 0;
  local_2c = 1;
  local_28 = 1;
  local_20 = 0;
  local_18 = *(SIZE_T *)(*(int *)(param_1 + 0x38c) + 0xd80);
  local_1c = LocalAlloc(0x40,local_18);
  if (local_1c != (HLOCAL)0x0) {
    local_38[0] = 0;
    BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x38c) + 0xda0),0x75c08,&local_30,0x1c,
                            (LPVOID)0x0,0,local_38,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x38c) + 0xda0),2,&local_30,0x1c,
                              (LPVOID)0x0,0,local_38,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        uVar2 = 0;
      }
    }
    LocalFree(local_1c);
  }
  return uVar2;
}



/* c03bf8b0 FUN_c03bf8b0 */

/* Boundary evidence: original MIPS .pdata c03bf8b0..c03bf917. Semantic name remains unreviewed. */

void FUN_c03bf8b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x24))(param_2,param_3,param_4);
  return;
}



/* c03bf918 FUN_c03bf918 */

/* Boundary evidence: original MIPS .pdata c03bf918..c03bf93f. Semantic name remains unreviewed. */

undefined4 FUN_c03bf918(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03bf940 FUN_c03bf940 */

/* Boundary evidence: original MIPS .pdata c03bf940..c03bf9c7. Semantic name remains unreviewed. */

void FUN_c03bf940(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  (**(code **)(param_1 + 0x54))(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c03bf9c8 FUN_c03bf9c8 */

/* Boundary evidence: original MIPS .pdata c03bf9c8..c03bf9ef. Semantic name remains unreviewed. */

undefined4 FUN_c03bf9c8(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* c03bf9f0 FUN_c03bf9f0 */

/* Boundary evidence: original MIPS .pdata c03bf9f0..c03bfaef. Semantic name remains unreviewed. */

undefined4 *
FUN_c03bf9f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,STRSAFE_LPCWSTR param_6)

{
  undefined4 *puVar1;
  
  FUN_c03a361c(param_1,1);
  param_1[0xb6] = 0xffffffff;
  *param_1 = &PTR_FUN_c03a2e88;
  param_1[8] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  memset(param_1 + 0xb9,0,0x10);
  param_1[0xbd] = 0;
  param_1[0xbe] = 0;
  param_1[0xe0] = param_5;
  param_1[0xe1] = param_4;
  param_1[0xe2] = param_3;
  param_1[0xe3] = param_2;
  memset(param_1 + 10,0,0x68);
  *(undefined2 *)(param_1 + 0xd0) = 0;
  *(undefined2 *)(param_1 + 0xa6) = 0;
  *(undefined2 *)(param_1 + 0x24) = 0;
  StringCbCopyW((STRSAFE_LPWSTR)(param_1 + 0xc0),0x40,param_6);
  puVar1 = param_1 + 0xe4;
  *puVar1 = puVar1;
  param_1[0xe5] = puVar1;
  param_1[0xbf] = 1;
  if (param_1[0xe3] != 0) {
    InterlockedIncrement((LONG *)(param_1[0xe3] + 0x938));
  }
  param_1[7] = 1;
  return param_1;
}



/* c03bfaf0 FUN_c03bfaf0 */

/* Boundary evidence: original MIPS .pdata c03bfaf0..c03bfb9b. Semantic name remains unreviewed. */

undefined4 * FUN_c03bfaf0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  param_1[0xb6] = 0xffffffff;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  *param_1 = &PTR_FUN_c03a2e88;
  param_1[8] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = 0;
  memset(param_1 + 0xb9,0,0x10);
  puVar1 = param_1 + 0xe4;
  param_1[0xbd] = 0;
  param_1[0xbe] = 0;
  param_1[0xe0] = 0;
  param_1[0xe1] = 0;
  param_1[0xe2] = 0;
  param_1[0xe3] = 0;
  *(undefined2 *)(param_1 + 0xd0) = 0;
  *(undefined2 *)(param_1 + 0xa6) = 0;
  *(undefined2 *)(param_1 + 0x24) = 0;
  *puVar1 = puVar1;
  param_1[0xe5] = puVar1;
  param_1[0xbf] = 1;
  param_1[7] = 1;
  return param_1;
}



/* c03bfb9c FUN_c03bfb9c */

/* Boundary evidence: original MIPS .pdata c03bfb9c..c03bfbff. Semantic name remains unreviewed. */

void FUN_c03bfb9c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03a2e88;
  if ((undefined4 *)param_1[0xe3] != (undefined4 *)0x0) {
    FUN_c03a6924((undefined4 *)param_1[0xe3]);
  }
  if ((HMODULE)param_1[0xb7] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[0xb7]);
    param_1[0xb7] = 0;
  }
  FUN_c03a3688(param_1);
  return;
}



/* c03bfc00 FUN_c03bfc00 */

/* Boundary evidence: original MIPS .pdata c03bfc00..c03bfd33. Semantic name remains unreviewed. */

undefined4 FUN_c03bfc00(int param_1,int param_2)

{
  STRSAFE_LPCWSTR pszSrc;
  uint uVar1;
  
  *(undefined1 *)(param_2 + 0x124) = *(undefined1 *)(param_1 + 0x8c);
  uVar1 = *(uint *)(param_1 + 0x20);
  *(uint *)(param_2 + 0x120) = uVar1;
  if ((*(uint *)(param_1 + 0x2f8) & 8) != 0) {
    *(uint *)(param_2 + 0x120) = uVar1 | 0x10;
  }
  *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(param_2 + 0x114) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(param_2 + 0x118) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_2 + 0x11c) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(param_2 + 0x10c) = *(undefined4 *)(param_1 + 0x74);
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 4),0x20,(STRSAFE_LPCWSTR)(param_1 + 0x340));
  pszSrc = (STRSAFE_LPCWSTR)(param_1 + 0x90);
  if (*pszSrc == L'\0') {
    pszSrc = (STRSAFE_LPCWSTR)(param_1 + 0x298);
  }
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x44),0x20,pszSrc);
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x84),0x40,L"");
  if (*(int *)(param_1 + 0x18) != 0) {
    FSDMGR_GetVolumeName
              (*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x40),(STRSAFE_LPWSTR)(param_2 + 0x84),
               0x40);
  }
  return 1;
}



/* c03bfd34 FUN_c03bfd34 */

/* Boundary evidence: original MIPS .pdata c03bfd34..c03bfd3f. Semantic name remains unreviewed. */

undefined4 FUN_c03bfd34(void)

{
  return 1;
}



/* c03bfd40 FUN_c03bfd40 */

/* Boundary evidence: original MIPS .pdata c03bfd40..c03bfe1f. Semantic name remains unreviewed. */

undefined4
FUN_c03bfd40(int param_1,int param_2,undefined4 param_3,undefined4 param_4,STRSAFE_LPWSTR param_5,
            uint param_6,int *param_7)

{
  undefined4 uVar1;
  size_t local_10 [2];
  
  if ((param_2 == 0x71c20) || (param_2 == 9)) {
    local_10[0] = 0;
    StringCchLengthW((STRSAFE_PCNZWCH)(param_1 + 0x300),0x20,local_10);
    if ((param_5 == (STRSAFE_LPWSTR)0x0) || (param_6 < (local_10[0] + 1) * 2)) {
      uVar1 = 0x7a;
    }
    else {
      StringCbCopyW(param_5,param_6,(STRSAFE_PCNZWCH)(param_1 + 0x300));
      if (param_7 != (int *)0x0) {
        *param_7 = (local_10[0] + 1) * 2;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_c03bf940(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 900),param_2,param_3,
                         param_4,param_5,param_6,param_7);
  }
  return uVar1;
}



/* c03bfe20 FUN_c03bfe20 */

/* Boundary evidence: original MIPS .pdata c03bfe20..c03bfeef. Semantic name remains unreviewed. */

undefined4 FUN_c03bfe20(int param_1,int param_2)

{
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x50),0x20,(STRSAFE_LPCWSTR)(param_1 + 0x340));
  StringCchCopyW((STRSAFE_LPWSTR)(param_2 + 0x10),0x20,
                 (STRSAFE_LPCWSTR)(*(int *)(param_1 + 0x38c) + 0x18));
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x20;
  if ((((*(uint *)(*(int *)(param_1 + 0x38c) + 0x71c) & 1) != 0) ||
      ((*(uint *)(*(int *)(param_1 + 0x38c) + 0xd10) & 1) != 0)) ||
     ((*(uint *)(param_1 + 0x88) & 2) != 0)) {
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
  }
  if (((*(uint *)(*(int *)(param_1 + 0x38c) + 0x71c) & 2) != 0) ||
     ((*(uint *)(*(int *)(param_1 + 0x38c) + 0xd10) & 2) != 0)) {
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 4;
  }
  return 0;
}



/* c03bfef0 FUN_c03bfef0 */

/* Boundary evidence: original MIPS .pdata c03bfef0..c03bff93. Semantic name remains unreviewed. */

undefined4 FUN_c03bfef0(int param_1,STRSAFE_LPCWSTR param_2,STRSAFE_PCNZWCH param_3)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x340),0x20,param_2);
  FUN_c03b98bc(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 0x388),param_2,param_1 + 0x28);
  dwErrCode = FUN_c03b12dc(param_1,(STRSAFE_PCNZWCH)PTR_u_System_StorageManager_c03c5264);
  if ((dwErrCode == 0) && (dwErrCode = FUN_c03b12dc(param_1,param_3), dwErrCode == 0)) {
    uVar1 = 1;
  }
  else {
    SetLastError(dwErrCode);
    uVar1 = 0;
  }
  return uVar1;
}



/* c03bff94 FUN_c03bff94 */

/* Boundary evidence: original MIPS .pdata c03bff94..c03bffe3. Semantic name remains unreviewed. */

void FUN_c03bff94(int param_1)

{
  if ((*(uint *)(param_1 + 0x2f8) & 2) == 0) {
    if (*(int *)(param_1 + 0x18) != 0) {
      FUN_c03ae084(*(int *)(param_1 + 0x18));
    }
    *(uint *)(param_1 + 0x2f8) = *(uint *)(param_1 + 0x2f8) | 2;
  }
  return;
}



/* c03bffe4 FUN_c03bffe4 */

/* Boundary evidence: original MIPS .pdata c03bffe4..c03c003b. Semantic name remains unreviewed. */

void FUN_c03bffe4(int param_1)

{
  if ((*(uint *)(param_1 + 0x2f8) & 2) != 0) {
    if (*(int *)(param_1 + 0x18) != 0) {
      FUN_c03ad500(*(int *)(param_1 + 0x18));
    }
    *(uint *)(param_1 + 0x2f8) = *(uint *)(param_1 + 0x2f8) & 0xfffffffd;
  }
  return;
}



/* c03c003c FUN_c03c003c */

/* Boundary evidence: original MIPS .pdata c03c003c..c03c00cf. Semantic name remains unreviewed. */

bool FUN_c03c003c(int param_1)

{
  DWORD dwErrCode;
  
  FUN_c03bff94(param_1);
  dwErrCode = FUN_c03a390c(param_1);
  if (dwErrCode == 0) {
    *(uint *)(param_1 + 0x2f8) = *(uint *)(param_1 + 0x2f8) & 0xfffffff7;
    CloseHandle(*(HANDLE *)(param_1 + 0x2d8));
    *(undefined4 *)(param_1 + 0x2d8) = 0xffffffff;
  }
  else {
    FUN_c03bffe4(param_1);
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c03c00d0 FUN_c03c00d0 */

/* Boundary evidence: original MIPS .pdata c03c00d0..c03c0143. Semantic name remains unreviewed. */

bool FUN_c03c00d0(int param_1,STRSAFE_LPCWSTR param_2)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03bf8b0(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 0x388),
                           (STRSAFE_LPWSTR)(param_1 + 0x340),param_2);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  else {
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x340),0x20,param_2);
  }
  return dwErrCode == 0;
}



/* c03c0144 FUN_c03c0144 */

/* Boundary evidence: original MIPS .pdata c03c0144..c03c01c3. Semantic name remains unreviewed. */

bool FUN_c03c0144(int param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD dwErrCode;
  
  dwErrCode = FUN_c03b9824(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 0x388),
                           param_1 + 0x340,param_2,param_3);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  else {
    FUN_c03b98bc(*(int *)(param_1 + 0x380),*(undefined4 *)(param_1 + 0x388),param_1 + 0x340,
                 param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x2f4) = 1;
  }
  return dwErrCode == 0;
}



/* c03c01c4 FUN_c03c01c4 */

/* Boundary evidence: original MIPS .pdata c03c01c4..c03c02b3. Semantic name remains unreviewed. */

DWORD FUN_c03c01c4(int param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  
  DVar2 = 0x1f;
  iVar3 = -1;
  puVar1 = operator_new(0x148);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03b7a6c(puVar1,param_3,0,0x64615900);
  }
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[0x51] = param_1;
    puVar1[0x50] = *(undefined4 *)(param_1 + 0x38c);
    iVar3 = CreateAPIHandle(DAT_c03c5374,puVar1);
    if (iVar3 == 0) {
      iVar3 = -1;
      DVar2 = FUN_c03ac938(0x1f);
      operator_delete(puVar1);
    }
    else {
      InterlockedIncrement((LONG *)(param_1 + 0x2fc));
      DVar2 = 0;
    }
  }
  *param_2 = iVar3;
  return DVar2;
}



/* c03c02b4 FUN_c03c02b4 */

/* Boundary evidence: original MIPS .pdata c03c02b4..c03c03bb. Semantic name remains unreviewed. */

undefined4
FUN_c03c02b4(int *param_1,DWORD param_2,LPVOID param_3,DWORD param_4,undefined4 *param_5,
            DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
  undefined4 uVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((param_1[0xbe] & 8U) == 0) {
    uVar1 = CeSetDirectCall(1);
    dwErrCode = FUN_c03bbd10((int *)param_1[0xe3],param_1,param_2,(int)param_3,param_4,param_5,
                             param_6,(int)param_7);
    CeSetDirectCall(uVar1);
    if (dwErrCode != 0) {
      SetLastError(dwErrCode);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = FUN_c03a34f4(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar2;
}



/* c03c03bc FUN_c03c03bc */

/* Boundary evidence: original MIPS .pdata c03c03bc..c03c0407. Semantic name remains unreviewed. */

undefined4 * FUN_c03c03bc(undefined4 *param_1,uint param_2)

{
  FUN_c03bfb9c(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c03c0408 FUN_c03c0408 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c03c0408..c03c0957. Semantic name remains unreviewed. */

undefined4 FUN_c03c0408(int *param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int *piVar4;
  wchar_t *pwVar5;
  size_t _SizeInWords;
  int iVar6;
  LPCWSTR pWVar7;
  undefined4 uVar8;
  HKEY local_6d0;
  uint local_6cc;
  int local_6c8;
  int local_6c4 [3];
  undefined1 auStack_6b8 [240];
  undefined1 auStack_5c8 [296];
  uint local_4a0;
  wchar_t local_498;
  wchar_t awStack_496 [11];
  wchar_t awStack_480 [32];
  wchar_t awStack_440 [260];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_c03c531c;
  iVar6 = param_1[0xe3];
  local_6cc = *(uint *)(iVar6 + 0x930);
  pWVar7 = (LPCWSTR)(iVar6 + 0x2f0);
  uVar8 = 0;
  local_6d0 = (HKEY)0x0;
  local_6c4[0] = 0;
  FUN_c03acd2c(pWVar7,&local_6d0);
  if (local_6d0 != (HKEY)0x0) {
    FUN_c03acafc(local_6d0,(LPCWSTR)PTR_u_CheckForFormat_c03c52c8,(LPBYTE)local_6c4);
    FUN_c03acd64(local_6d0);
    local_6d0 = (HKEY)0x0;
  }
  StringCchPrintfW(awStack_440,0x104,L"%s\\%s",pWVar7,PTR_u_PartitionTable_c03c5294);
  iVar1 = FUN_c03acd2c(awStack_440,&local_6d0);
  if (iVar1 != 0) {
    StringCchPrintfW(awStack_440,0x104,L"%s\\%s",PTR_u_System_StorageManager_c03c5264,
                     PTR_u_PartitionTable_c03c5294);
    FUN_c03acd2c(awStack_440,&local_6d0);
  }
  if (local_6d0 == (HKEY)0x0) {
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xa6),0x20,(STRSAFE_LPCWSTR)(iVar6 + 0x4f8));
  }
  else {
    pwVar5 = &local_498;
    _SizeInWords = 10;
    if (*(byte *)(param_1 + 0x23) < 0x10) {
      local_498 = L'0';
      pwVar5 = awStack_496;
      _SizeInWords = 9;
    }
    _itow_s((uint)*(byte *)(param_1 + 0x23),pwVar5,_SizeInWords,0x10);
    iVar1 = FUN_c03acbc4(local_6d0,&local_498,(STRSAFE_LPWSTR)(param_1 + 0xa6),0x20);
    if (iVar1 == 0) {
      StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xa6),0x20,(STRSAFE_LPCWSTR)(iVar6 + 0x4f8));
    }
    FUN_c03acd64(local_6d0);
    local_6d0 = (HKEY)0x0;
  }
  pwVar5 = (wchar_t *)(param_1 + 0xa6);
  if (*pwVar5 == L'\0') {
    SetLastError(2);
    goto LAB_c03c0920;
  }
  DVar2 = FUN_c03a345c((int)param_1,pwVar5,0x20);
  if (DVar2 != 0) {
    SetLastError(DVar2);
    goto LAB_c03c0920;
  }
  local_238 = L'\0';
  memset(auStack_236,0,0x206);
  FUN_c03b0fe8((int)param_1,(LPCWSTR)PTR_DAT_c03c529c,&local_238,0x104);
  FUN_c03b0fe8((int)param_1,(LPCWSTR)PTR_DAT_c03c529c,(STRSAFE_LPWSTR)(param_1 + 0x24),0x104);
  param_1[0xb6] = param_2;
  if (local_238 == L'\0') {
    DVar2 = FUN_c03bf6a8((int)param_1,pwVar5,0x20);
    if (DVar2 == 0x3ed) {
      DVar2 = FUN_c03b0fe8((int)param_1,(LPCWSTR)PTR_u_DefaultFileSystem_c03c5298,pwVar5,0x10);
    }
    if ((DVar2 == 0) && (DVar2 = FUN_c03a345c((int)param_1,pwVar5,0x104), DVar2 == 0)) {
      FUN_c03b0fe8((int)param_1,(LPCWSTR)PTR_DAT_c03c529c,&local_238,0x104);
      FUN_c03b0fe8((int)param_1,(LPCWSTR)PTR_DAT_c03c529c,(STRSAFE_LPWSTR)(param_1 + 0x24),0x104);
      if (local_238 != L'\0') goto LAB_c03c06d0;
      DVar2 = 0x7e;
    }
  }
  else {
LAB_c03c06d0:
    puVar3 = operator_new(0xb8);
    if (puVar3 == (undefined4 *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = FUN_c03b1ff8(puVar3,param_1,&local_238);
    }
    if (piVar4 == (int *)0x0) {
      DVar2 = 8;
    }
    else {
      StringCchPrintfW(awStack_440,0x104,L"%s\\%s",pWVar7,pwVar5);
      iVar6 = FUN_c03acd2c(awStack_440,&local_6d0);
      if (iVar6 == 0) {
        FUN_c03ae44c(DAT_c03c623c,local_6d0,&local_6cc);
        iVar6 = FUN_c03acafc(local_6d0,(LPCWSTR)PTR_u_CheckForFormat_c03c52c8,(LPBYTE)&local_6c8);
        if (iVar6 != 0) {
          local_6c4[0] = local_6c8;
        }
        iVar6 = FUN_c03acbc4(local_6d0,(LPCWSTR)PTR_u_Folder_c03c52b4,awStack_480,0x20);
        if (iVar6 != 0) {
          StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xc0),0x20,awStack_480);
        }
        FUN_c03acd64(local_6d0);
        local_6d0 = (HKEY)0x0;
      }
      StringCchPrintfW(awStack_440,0x104,L"%s\\%s",pWVar7,param_1 + 0xd0);
      iVar6 = FUN_c03acd2c(awStack_440,&local_6d0);
      if (iVar6 == 0) {
        FUN_c03ae44c(DAT_c03c623c,local_6d0,&local_6cc);
        iVar6 = FUN_c03acbc4(local_6d0,(LPCWSTR)PTR_u_Folder_c03c52b4,awStack_480,0x20);
        if (iVar6 != 0) {
          StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0xc0),0x20,awStack_480);
        }
        FUN_c03acd64(local_6d0);
        local_6d0 = (HKEY)0x0;
      }
      FUN_c03bffe4((int)param_1);
      if (local_6c4[0] != 0) {
        local_6c8 = 0;
        memset(auStack_6b8,0,0x220);
        local_6c4[1] = 0x228;
        FUN_c03b898c(param_1[0xe3],(int)auStack_6b8);
        FUN_c03bfc00((int)param_1,(int)auStack_5c8);
        local_4a0 = local_6cc;
        iVar6 = KernelIoControl(0x1010118,local_6c4 + 1,0x228,&local_6c8,4,0);
        if ((iVar6 != 0) && (local_6c8 != 0)) {
          FUN_c03c0144((int)param_1,(uint)*(byte *)(param_1 + 0x23),0);
        }
      }
      DVar2 = FUN_c03a3988(param_1,piVar4,local_6cc,param_1[0xbd]);
      if (DVar2 == 0) {
        param_1[0xbd] = 0;
        uVar8 = 1;
        param_1[0xbe] = param_1[0xbe] | 8;
        goto LAB_c03c0920;
      }
      (**(code **)*piVar4)(piVar4,1);
    }
  }
  SetLastError(DVar2);
  param_1[0xb6] = -1;
LAB_c03c0920:
  FUN_c03c216c(local_30);
  return uVar8;
}



/* c03c0958 FUN_c03c0958 */

undefined4 * FUN_c03c0958(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



/* c03c0968 FUN_c03c0968 */

/* Boundary evidence: original MIPS .pdata c03c0968..c03c098f. Semantic name remains unreviewed. */

void FUN_c03c0968(undefined4 *param_1)

{
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  return;
}



/* c03c0990 FUN_c03c0990 */

/* Boundary evidence: original MIPS .pdata c03c0990..c03c09e7. Semantic name remains unreviewed. */

undefined4 * FUN_c03c0990(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = 0;
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03c135c(puVar1);
  }
  param_1[1] = puVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* c03c09e8 FUN_c03c09e8 */

int * FUN_c03c09e8(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar3 = 0;
  piVar2 = *(int **)(param_1 + 8);
  piVar1 = piVar2;
  for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
    uVar5 = *(uint *)(*piVar2 + 0xc);
    uVar6 = *(uint *)(*piVar2 + 8);
    if ((uVar3 <= uVar5) && ((uVar3 != uVar5 || (uVar4 < uVar6)))) {
      piVar1 = piVar2;
      uVar3 = uVar5;
      uVar4 = uVar6;
    }
  }
  return piVar1;
}



/* c03c0a48 FUN_c03c0a48 */

bool FUN_c03c0a48(int param_1)

{
  return *(int *)(param_1 + 8) == 0;
}



/* c03c0a60 FUN_c03c0a60 */

/* Boundary evidence: original MIPS .pdata c03c0a60..c03c0b33. Semantic name remains unreviewed. */

undefined4 FUN_c03c0a60(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = FUN_c03c13d0(*(uint **)(param_1 + 4),param_2);
    if (0 < iVar1) {
      if (iVar1 < 3) {
        return 0;
      }
      if (iVar1 == 4) {
        return 1;
      }
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    while ((puVar2 != (undefined4 *)0x0 &&
           (iVar1 = FUN_c03c13d0(param_2,(uint *)*puVar2), iVar1 != 1))) {
      if (iVar1 == 2) {
        puVar2 = (undefined4 *)puVar2[1];
      }
      else if ((2 < iVar1) && (iVar1 < 5)) {
        return 1;
      }
    }
  }
  return 0;
}



/* c03c0b34 FUN_c03c0b34 */

void FUN_c03c0b34(int param_1,int *param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  
  puVar1 = *(uint **)(param_1 + 4);
  uVar5 = ((uint *)*param_2)[1];
  uVar7 = *(uint *)*param_2;
  if ((uVar5 <= puVar1[1]) && ((uVar5 != puVar1[1] || (uVar7 < *puVar1)))) {
    *puVar1 = uVar7;
    puVar1[1] = uVar5;
  }
  iVar2 = *(int *)(param_1 + 4);
  uVar5 = *(uint *)(*param_2 + 0xc);
  uVar7 = *(uint *)(*param_2 + 8);
  if ((*(uint *)(iVar2 + 0xc) <= uVar5) &&
     ((uVar5 != *(uint *)(iVar2 + 0xc) || (*(uint *)(iVar2 + 8) < uVar7)))) {
    *(uint *)(iVar2 + 8) = uVar7;
    *(uint *)(iVar2 + 0xc) = uVar5;
  }
  piVar6 = *(int **)(param_1 + 8);
  if (piVar6 != (int *)0x0) {
    uVar5 = ((uint *)*param_2)[1];
    piVar4 = piVar6;
    piVar8 = piVar6;
    while( true ) {
      piVar3 = piVar4;
      uVar7 = ((uint *)*piVar3)[1];
      piVar4 = piVar3;
      if (uVar5 < uVar7) break;
      if (((uVar5 == uVar7) && (*(uint *)*param_2 < *(uint *)*piVar3)) ||
         (piVar4 = (int *)piVar3[1], piVar8 = piVar3, piVar4 == (int *)0x0)) break;
    }
    if (piVar4 != piVar6) {
      piVar8[1] = (int)param_2;
      param_2[1] = (int)piVar4;
      return;
    }
    param_2[1] = (int)piVar6;
  }
  *(int **)(param_1 + 8) = param_2;
  return;
}



/* c03c0c2c FUN_c03c0c2c */

/* Boundary evidence: original MIPS .pdata c03c0c2c..c03c0d77. Semantic name remains unreviewed. */

int * FUN_c03c0c2c(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  piVar3 = *(int **)(param_1 + 8);
  piVar6 = *(int **)(param_1 + 8);
  while( true ) {
    piVar1 = piVar3;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar2 = FUN_c03c148c((int *)*piVar1,param_2);
    if (iVar2 != 0) break;
    piVar3 = (int *)piVar1[1];
    piVar6 = piVar1;
  }
  if (piVar1 == *(int **)(param_1 + 8)) {
    *(int *)(param_1 + 8) = piVar1[1];
  }
  else {
    piVar6[1] = piVar1[1];
  }
  if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    puVar5 = *(undefined4 **)(param_1 + 4);
    *puVar5 = 0xffffffff;
    puVar5[1] = 0xffffffff;
    iVar2 = *(int *)(param_1 + 4);
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  else {
    piVar6 = *(int **)(param_1 + 4);
    if ((*piVar6 == *(int *)*piVar1) && (piVar6[1] == ((int *)*piVar1)[1])) {
      piVar3 = (int *)**(undefined4 **)(param_1 + 8);
      *piVar6 = *piVar3;
      piVar6[1] = piVar3[1];
    }
    iVar2 = *(int *)(param_1 + 4);
    if ((*(int *)(iVar2 + 8) == *(int *)(*piVar1 + 8)) &&
       (*(int *)(iVar2 + 0xc) == *(int *)(*piVar1 + 0xc))) {
      piVar6 = FUN_c03c09e8(param_1);
      iVar4 = *piVar6;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar4 + 0xc);
    }
  }
  piVar1[1] = 0;
  return piVar1;
}



/* c03c0d78 FUN_c03c0d78 */

/* Boundary evidence: original MIPS .pdata c03c0d78..c03c0ddf. Semantic name remains unreviewed. */

void FUN_c03c0d78(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 4));
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar1[1];
    puVar1[1] = 0;
    FUN_c03c0968(puVar1);
    operator_delete(puVar1);
    puVar1 = puVar2;
  }
  return;
}



/* c03c0de0 FUN_c03c0de0 */

undefined4 * FUN_c03c0de0(undefined4 *param_1)

{
  param_1[1] = 0;
  *param_1 = 0xdeadbeef;
  param_1[2] = 0;
  return param_1;
}



/* c03c0dfc FUN_c03c0dfc */

/* Boundary evidence: original MIPS .pdata c03c0dfc..c03c0e5f. Semantic name remains unreviewed. */

undefined4 FUN_c03c0dfc(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  undefined3 extraout_var_00;
  
  if (((*(int *)(param_1 + 4) == 0) ||
      (bVar1 = FUN_c03c0f70(*(int *)(param_1 + 4)), CONCAT31(extraout_var,bVar1) != 0)) &&
     ((*(int *)(param_1 + 8) == 0 ||
      (bVar1 = FUN_c03c0f70(*(int *)(param_1 + 8)), CONCAT31(extraout_var_00,bVar1) != 0)))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03c0e60 FUN_c03c0e60 */

/* Boundary evidence: original MIPS .pdata c03c0e60..c03c0ebf. Semantic name remains unreviewed. */

void FUN_c03c0e60(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c03c12ec(puVar1);
    operator_delete(puVar1);
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c03c12ec(puVar1);
    operator_delete(puVar1);
  }
  return;
}



/* c03c0ec0 FUN_c03c0ec0 */

/* Boundary evidence: original MIPS .pdata c03c0ec0..c03c0f0f. Semantic name remains unreviewed. */

undefined4 * FUN_c03c0ec0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c03c135c(puVar1);
  }
  *param_1 = puVar1;
  param_1[1] = 0;
  return param_1;
}



/* c03c0f10 FUN_c03c0f10 */

int FUN_c03c0f10(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0;
  uVar3 = 0;
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = iVar2;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
    uVar5 = *(uint *)(*(int *)(iVar2 + 4) + 0xc);
    uVar6 = *(uint *)(*(int *)(iVar2 + 4) + 8);
    if ((uVar3 <= uVar5) && ((uVar3 != uVar5 || (uVar4 < uVar6)))) {
      iVar1 = iVar2;
      uVar3 = uVar5;
      uVar4 = uVar6;
    }
  }
  return iVar1;
}



/* c03c0f70 FUN_c03c0f70 */

bool FUN_c03c0f70(int param_1)

{
  return *(int *)(param_1 + 4) == 0;
}



/* c03c0f88 FUN_c03c0f88 */

/* Boundary evidence: original MIPS .pdata c03c0f88..c03c101f. Semantic name remains unreviewed. */

undefined4 FUN_c03c0f88(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] != 0) {
    iVar1 = FUN_c03c13d0((uint *)*param_1,param_2);
    if (0 < iVar1) {
      if (iVar1 < 3) {
        return 0;
      }
      if (iVar1 == 4) {
        return 1;
      }
    }
    for (iVar1 = param_1[1]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      iVar2 = FUN_c03c0a60(iVar1,param_2);
      if (iVar2 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



/* c03c1020 FUN_c03c1020 */

/* Boundary evidence: original MIPS .pdata c03c1020..c03c10c3. Semantic name remains unreviewed. */

undefined4 FUN_c03c1020(undefined4 *param_1,uint *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[1] != 0) &&
     ((iVar1 = FUN_c03c13d0((uint *)*param_1,param_2), iVar1 < 1 || (2 < iVar1)))) {
    for (piVar2 = (int *)param_1[1]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[3]) {
      if ((*piVar2 != param_3) && (iVar1 = FUN_c03c0a60((int)piVar2,param_2), iVar1 != 0)) {
        return 1;
      }
    }
  }
  return 0;
}



/* c03c10c4 FUN_c03c10c4 */

void FUN_c03c10c4(int *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  puVar1 = (uint *)*param_1;
  uVar5 = (*(uint **)(param_2 + 4))[1];
  uVar6 = **(uint **)(param_2 + 4);
  if ((uVar5 <= puVar1[1]) && ((uVar5 != puVar1[1] || (uVar6 < *puVar1)))) {
    *puVar1 = uVar6;
    puVar1[1] = uVar5;
  }
  iVar2 = *param_1;
  uVar5 = *(uint *)(*(int *)(param_2 + 4) + 0xc);
  uVar6 = *(uint *)(*(int *)(param_2 + 4) + 8);
  if ((*(uint *)(iVar2 + 0xc) <= uVar5) &&
     ((uVar5 != *(uint *)(iVar2 + 0xc) || (*(uint *)(iVar2 + 8) < uVar6)))) {
    *(uint *)(iVar2 + 8) = uVar6;
    *(uint *)(iVar2 + 0xc) = uVar5;
  }
  iVar2 = param_1[1];
  if (iVar2 != 0) {
    uVar5 = (*(uint **)(param_2 + 4))[1];
    iVar4 = iVar2;
    iVar7 = iVar2;
    while( true ) {
      iVar3 = iVar4;
      uVar6 = (*(uint **)(iVar3 + 4))[1];
      iVar4 = iVar3;
      if (uVar5 < uVar6) break;
      if (((uVar5 == uVar6) && (**(uint **)(param_2 + 4) < **(uint **)(iVar3 + 4))) ||
         (iVar4 = *(int *)(iVar3 + 0xc), iVar7 = iVar3, iVar4 == 0)) break;
    }
    if (iVar4 != iVar2) {
      *(int *)(iVar7 + 0xc) = param_2;
      *(int *)(param_2 + 0xc) = iVar4;
      return;
    }
    *(int *)(param_2 + 0xc) = iVar2;
  }
  param_1[1] = param_2;
  return;
}



/* c03c11bc FUN_c03c11bc */

/* Boundary evidence: original MIPS .pdata c03c11bc..c03c12eb. Semantic name remains unreviewed. */

int * FUN_c03c11bc(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  
  piVar3 = (int *)param_1[1];
  piVar4 = piVar3;
  piVar6 = piVar3;
  while( true ) {
    piVar1 = piVar4;
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    if (param_2 == *piVar1) break;
    piVar4 = (int *)piVar1[3];
    piVar6 = piVar1;
  }
  if (piVar1 == piVar3) {
    param_1[1] = piVar1[3];
  }
  else {
    piVar6[3] = piVar1[3];
  }
  if (param_1[1] == 0) {
    puVar5 = (undefined4 *)*param_1;
    *puVar5 = 0xffffffff;
    puVar5[1] = 0xffffffff;
    iVar7 = *param_1;
    *(undefined4 *)(iVar7 + 8) = 0;
    *(undefined4 *)(iVar7 + 0xc) = 0;
  }
  else {
    piVar6 = (int *)*param_1;
    if ((*piVar6 == *(int *)piVar1[1]) && (piVar6[1] == ((int *)piVar1[1])[1])) {
      piVar4 = *(int **)(param_1[1] + 4);
      *piVar6 = *piVar4;
      piVar6[1] = piVar4[1];
    }
    iVar7 = *param_1;
    if ((*(int *)(iVar7 + 8) == *(int *)(piVar1[1] + 8)) &&
       (*(int *)(iVar7 + 0xc) == *(int *)(piVar1[1] + 0xc))) {
      iVar2 = FUN_c03c0f10((int)param_1);
      iVar2 = *(int *)(iVar2 + 4);
      *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
    }
  }
  piVar1[3] = 0;
  return piVar1;
}



/* c03c12ec FUN_c03c12ec */

/* Boundary evidence: original MIPS .pdata c03c12ec..c03c135b. Semantic name remains unreviewed. */

void FUN_c03c12ec(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  pvVar1 = (void *)param_1[1];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 0xc);
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    FUN_c03c0d78((int)pvVar1);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* c03c135c FUN_c03c135c */

undefined4 * FUN_c03c135c(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  return param_1;
}



/* c03c137c FUN_c03c137c */

void FUN_c03c137c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}



/* c03c139c FUN_c03c139c */

void FUN_c03c139c(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + *param_1;
  param_1[2] = uVar1 - 1;
  param_1[3] = param_3 + param_1[1] + (uint)(uVar1 < param_2) + -1 + (uint)(uVar1 - 1 < uVar1);
  return;
}



/* c03c13d0 FUN_c03c13d0 */

undefined4 FUN_c03c13d0(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_1[3];
  uVar4 = param_2[1];
  if ((uVar4 < uVar2) || ((uVar2 == uVar4 && (*param_2 <= param_1[2])))) {
    uVar3 = param_2[3];
    uVar5 = param_1[1];
    if ((uVar5 < uVar3) || ((uVar5 == uVar3 && (*param_1 <= param_2[2])))) {
      if (((uVar4 < uVar5) || (((uVar4 == uVar5 && (*param_2 <= *param_1)) || (uVar2 < uVar3)))) ||
         ((uVar3 == uVar2 && (param_1[2] <= param_2[2])))) {
        uVar1 = 4;
      }
      else {
        uVar1 = 3;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c03c148c FUN_c03c148c */

undefined4 FUN_c03c148c(int *param_1,int *param_2)

{
  if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) {
    if ((param_1[2] == param_2[2]) && (param_1[3] == param_2[3])) {
      return 1;
    }
  }
  return 0;
}



/* c03c14d0 FUN_c03c14d0 */

undefined4 FUN_c03c14d0(uint *param_1)

{
  undefined4 uVar1;
  
  if ((param_1[1] < param_1[3]) || ((param_1[1] == param_1[3] && (*param_1 <= param_1[2])))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c03c151c FSDMGR_DeregisterVolume */

void FSDMGR_DeregisterVolume(void)

{
                    /* 0x2151c  10  FSDMGR_DeregisterVolume */
  return;
}



/* c03c1524 FUN_c03c1524 */

/* Boundary evidence: original MIPS .pdata c03c1524..c03c163f. Semantic name remains unreviewed. */

undefined4 FUN_c03c1524(HANDLE param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD aDStack_70 [2];
  undefined4 local_68;
  undefined1 auStack_64 [72];
  uint local_1c;
  uint local_18;
  
  local_18 = DAT_c03c531c;
  memset(auStack_64,0,0x4c);
  local_68 = 0x50;
  BVar1 = DeviceIoControl(param_1,0x71800,&local_68,0x50,(LPVOID)0x0,0,aDStack_70,(LPOVERLAPPED)0x0)
  ;
  if ((BVar1 == 0) || ((local_1c & 2) == 0)) {
    BVar1 = DeviceIoControl(param_1,0x79c14,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_70,(LPOVERLAPPED)0x0
                           );
    if (BVar1 == 0) {
      BVar1 = DeviceIoControl(param_1,6,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_70,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) goto LAB_c03c1614;
    }
    uVar2 = 0;
  }
  else {
LAB_c03c1614:
    uVar2 = 0x1f;
  }
  FUN_c03c216c(local_18);
  return uVar2;
}



/* c03c1640 FUN_c03c1640 */

/* Boundary evidence: original MIPS .pdata c03c1640..c03c172f. Semantic name remains unreviewed. */

undefined4 FUN_c03c1640(HANDLE param_1,undefined4 *param_2)

{
  BOOL BVar1;
  DWORD aDStack_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  
  memset(&local_30,0,0x18);
  memset(param_2,0,0x40);
  *param_2 = 0x40;
  BVar1 = DeviceIoControl(param_1,0x71c00,&local_30,0x18,&local_30,0x18,aDStack_38,(LPOVERLAPPED)0x0
                         );
  if (BVar1 == 0) {
    DeviceIoControl(param_1,1,&local_30,0x18,&local_30,0x18,aDStack_38,(LPOVERLAPPED)0x0);
  }
  param_2[4] = local_2c;
  param_2[2] = local_30;
  param_2[3] = 0;
  return 1;
}



/* c03c1738 FUN_c03c1738 */

/* Boundary evidence: original MIPS .pdata c03c1738..c03c1753. Semantic name remains unreviewed. */

void FUN_c03c1738(HANDLE param_1)

{
  FUN_c03c1524(param_1);
  return;
}



/* c03c1754 FUN_c03c1754 */

/* Boundary evidence: original MIPS .pdata c03c1754..c03c1843. Semantic name remains unreviewed. */

undefined4 FUN_c03c1754(HANDLE param_1,undefined4 param_2,undefined4 *param_3)

{
  BOOL BVar1;
  DWORD aDStack_38 [2];
  undefined4 local_30 [6];
  
  memset(local_30,0,0x18);
  memset(param_3,0,0x68);
  *param_3 = 0x68;
  BVar1 = DeviceIoControl(param_1,0x71c00,local_30,0x18,local_30,0x18,aDStack_38,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DeviceIoControl(param_1,1,local_30,0x18,local_30,0x18,aDStack_38,(LPOVERLAPPED)0x0);
  }
  param_3[0x12] = local_30[0];
  param_3[0x13] = 0;
  *(undefined1 *)(param_3 + 0x19) = 4;
  return 1;
}



/* c03c1844 FUN_c03c1844 */

/* Boundary evidence: original MIPS .pdata c03c1844..c03c1893. Semantic name remains unreviewed. */

undefined4 FUN_c03c1844(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xe;
  }
  else {
    *puVar1 = param_1;
    *param_2 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c03c1894 FUN_c03c1894 */

/* Boundary evidence: original MIPS .pdata c03c1894..c03c19ab. Semantic name remains unreviewed. */

undefined4 FUN_c03c1894(int *param_1,undefined4 *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD aDStack_38 [2];
  undefined4 local_30 [6];
  
  if (*param_1 == 0) {
    uVar2 = 0x12;
  }
  else {
    memset(local_30,0,0x18);
    memset(param_2,0,0x68);
    *param_2 = 0x68;
    BVar1 = DeviceIoControl((HANDLE)*param_1,0x71c00,local_30,0x18,local_30,0x18,aDStack_38,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DeviceIoControl((HANDLE)*param_1,1,local_30,0x18,local_30,0x18,aDStack_38,(LPOVERLAPPED)0x0);
    }
    param_2[0x12] = local_30[0];
    param_2[0x13] = 0;
    *(undefined1 *)(param_2 + 0x19) = 4;
    StringCbCopyW((STRSAFE_LPWSTR)(param_2 + 1),0x40,L"PART00");
    uVar2 = 0;
    *param_1 = 0;
  }
  return uVar2;
}



/* c03c19ac FUN_c03c19ac */

/* Boundary evidence: original MIPS .pdata c03c19ac..c03c19c7. Semantic name remains unreviewed. */

void FUN_c03c19ac(void *param_1)

{
  operator_delete(param_1);
  return;
}



/* c03c19d4 FUN_c03c19d4 */

/* Boundary evidence: original MIPS .pdata c03c19d4..c03c1a33. Semantic name remains unreviewed. */

DWORD FUN_c03c19d4(void)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = ForwardDeviceIoControl();
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



/* c03c1a3c FUN_c03c1a3c */

/* Boundary evidence: original MIPS .pdata c03c1a3c..c03c1b57. Semantic name remains unreviewed. */

DWORD FUN_c03c1a3c(undefined4 *param_1,undefined4 param_2,LPCWSTR param_3,undefined4 param_4,
                  undefined4 *param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE pHVar1;
  code *pcVar2;
  int iVar3;
  DWORD DVar4;
  
  if ((HMODULE)*param_1 != (HMODULE)0x0) {
    FreeLibrary((HMODULE)*param_1);
    *param_1 = 0;
    param_1[1] = 0;
  }
  pHVar1 = LoadLibraryW(param_3);
  *param_1 = pHVar1;
  if (pHVar1 != (HMODULE)0x0) {
    pcVar2 = (code *)FUN_c03acd88();
    param_1[1] = pcVar2;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)(param_2,param_5,param_6,param_7);
      if (iVar3 == 0) {
        DVar4 = 0x3ed;
        goto LAB_c03c1adc;
      }
      goto LAB_c03c1b34;
    }
  }
  DVar4 = FUN_c03ac938(0x1f);
  if (DVar4 != 0) {
LAB_c03c1adc:
    param_1[1] = 0;
    if ((HMODULE)*param_1 != (HMODULE)0x0) {
      FreeLibrary((HMODULE)*param_1);
      *param_1 = 0;
      return DVar4;
    }
    return DVar4;
  }
LAB_c03c1b34:
  param_1[2] = *param_5;
  param_1[3] = param_5[1];
  param_1[4] = param_5[2];
  param_1[5] = param_5[3];
  return 0;
}



/* c03c1eb8 FUN_c03c1eb8 */

/* Boundary evidence: original MIPS .pdata c03c1eb8..c03c1ff3. Semantic name remains unreviewed. */

int FUN_c03c1eb8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c03c629c != (code *)0x0) {
      iVar2 = (*DAT_c03c629c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c03c1f68;
    FUN_c03c263c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c03a2ecc(param_1,param_2);
  }
LAB_c03c1f68:
  if (((param_2 == 0) && (FUN_c03c25c4(), iVar1 != 0)) && (DAT_c03c629c != (code *)0x0)) {
    iVar1 = (*DAT_c03c629c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c03c1ff4 FUN_c03c1ff4 */

/* Boundary evidence: original MIPS .pdata c03c1ff4..c03c201f. Semantic name remains unreviewed. */

void FUN_c03c1ff4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c03c2020 entry */

/* Boundary evidence: original MIPS .pdata c03c2020..c03c2077. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c03c2078();
  }
  FUN_c03c1eb8(param_1,param_2,param_3);
  return;
}



/* c03c2078 FUN_c03c2078 */

/* Boundary evidence: original MIPS .pdata c03c2078..c03c20eb. Semantic name remains unreviewed. */

void FUN_c03c2078(void)

{
  uint uVar1;
  
  if ((DAT_c03c531c == 0) || (DAT_c03c531c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c03c531c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c03c531c == 0) {
      DAT_c03c531c = 0xb064;
    }
  }
  DAT_c03c5320 = ~DAT_c03c531c;
  return;
}



/* c03c20ec FUN_c03c20ec */

/* Boundary evidence: original MIPS .pdata c03c20ec..c03c213f. Semantic name remains unreviewed. */

void FUN_c03c20ec(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c03c216c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c03c2140 FUN_c03c2140 */

/* Boundary evidence: original MIPS .pdata c03c2140..c03c216b. Semantic name remains unreviewed. */

undefined4 FUN_c03c2140(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c03c20ec(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c03c216c FUN_c03c216c */

/* Boundary evidence: original MIPS .pdata c03c216c..c03c21b3. Semantic name remains unreviewed. */

void FUN_c03c216c(uint param_1)

{
  if ((param_1 == DAT_c03c531c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c03c21b4 FUN_c03c21b4 */

/* Boundary evidence: original MIPS .pdata c03c21b4..c03c222f. Semantic name remains unreviewed. */

void FUN_c03c21b4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c03c20ec(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c03c2230 FUN_c03c2230 */

/* Boundary evidence: original MIPS .pdata c03c2230..c03c233b. Semantic name remains unreviewed. */

undefined4 FUN_c03c2230(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c03c6294;
  puVar3 = DAT_c03c6290;
  iVar4 = (int)DAT_c03c6290 - (int)DAT_c03c6294;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c03c2274:
    param_1 = 0;
  }
  else {
    if (DAT_c03c6294 != (void *)0x0) {
      uVar1 = _msize(DAT_c03c6294);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c03c22e8:
        if (pvVar2 == (void *)0x0) goto LAB_c03c2274;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c03c22e8;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c03c6290 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c03c6294 = pvVar2;
  }
  return param_1;
}



/* c03c233c FUN_c03c233c */

/* Boundary evidence: original MIPS .pdata c03c233c..c03c2427. Semantic name remains unreviewed. */

undefined4 FUN_c03c233c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c03c6298 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c03c6298,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c03c6298 == (LPCRITICAL_SECTION)0x0) goto LAB_c03c23e0;
  }
  EnterCriticalSection(DAT_c03c6298);
LAB_c03c23e0:
  uVar2 = FUN_c03c2230(param_1);
  FUN_c03c2428();
  return uVar2;
}



/* c03c2428 FUN_c03c2428 */

/* Boundary evidence: original MIPS .pdata c03c2428..c03c2473. Semantic name remains unreviewed. */

void FUN_c03c2428(void)

{
  if (DAT_c03c6298 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c03c6298);
  }
  return;
}



/* c03c2474 FUN_c03c2474 */

/* Boundary evidence: original MIPS .pdata c03c2474..c03c24a3. Semantic name remains unreviewed. */

undefined4 FUN_c03c2474(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c03c233c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03c24a4 FUN_c03c24a4 */

/* Boundary evidence: original MIPS .pdata c03c24a4..c03c25c3. Semantic name remains unreviewed. */

void FUN_c03c24a4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c03c628c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c03c6294;
    if (DAT_c03c6294 != (undefined4 *)0x0) {
      while (DAT_c03c6290 = DAT_c03c6290 + -1, _Memory <= DAT_c03c6290) {
        if ((code *)*DAT_c03c6290 != (code *)0x0) {
          (*(code *)*DAT_c03c6290)();
          _Memory = DAT_c03c6294;
        }
      }
      free(_Memory);
      DAT_c03c6290 = (undefined4 *)0x0;
      DAT_c03c6294 = (undefined4 *)0x0;
    }
    FUN_c03c25e8((undefined4 *)&DAT_c03a1018,(undefined4 *)&DAT_c03a101c);
  }
  FUN_c03c25e8((undefined4 *)&DAT_c03a1020,(undefined4 *)&DAT_c03a1024);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c03c6298,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c03c25c4 FUN_c03c25c4 */

/* Boundary evidence: original MIPS .pdata c03c25c4..c03c25e7. Semantic name remains unreviewed. */

void FUN_c03c25c4(void)

{
  FUN_c03c24a4(0,0,1);
  return;
}



/* c03c25e8 FUN_c03c25e8 */

/* Boundary evidence: original MIPS .pdata c03c25e8..c03c263b. Semantic name remains unreviewed. */

void FUN_c03c25e8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c03c263c FUN_c03c263c */

/* Boundary evidence: original MIPS .pdata c03c263c..c03c2677. Semantic name remains unreviewed. */

void FUN_c03c263c(void)

{
  FUN_c03c25e8((undefined4 *)&DAT_c03a1010,(undefined4 *)&DAT_c03a1014);
  FUN_c03c25e8((undefined4 *)&DAT_c03a1000,(undefined4 *)&DAT_c03a100c);
  return;
}



/* c03c2818 FUN_c03c2818 */

/* Boundary evidence: original MIPS .pdata c03c2818..c03c2843. Semantic name remains unreviewed. */

void FUN_c03c2818(void)

{
  FUN_c03b9e74((undefined4 *)&DAT_c03c5398);
  FUN_c03c2474(FUN_c03c2874);
  return;
}



/* c03c2844 FUN_c03c2844 */

/* Boundary evidence: original MIPS .pdata c03c2844..c03c2873. Semantic name remains unreviewed. */

void FUN_c03c2844(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c03c521c);
  FUN_c03c2474(FUN_c03c2894);
  return;
}



/* c03c2874 FUN_c03c2874 */

/* Boundary evidence: original MIPS .pdata c03c2874..c03c2893. Semantic name remains unreviewed. */

void FUN_c03c2874(void)

{
  FUN_c03ba0e8((undefined4 *)&DAT_c03c5398);
  return;
}



/* c03c2894 FUN_c03c2894 */

/* Boundary evidence: original MIPS .pdata c03c2894..c03c28b7. Semantic name remains unreviewed. */

void FUN_c03c2894(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c03c521c);
  return;
}


