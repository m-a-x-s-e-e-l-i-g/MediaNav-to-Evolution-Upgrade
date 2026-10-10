/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0332264 FUN_c0332264 */

/* Boundary evidence: original MIPS .pdata c0332264..c033229f. Semantic name remains unreviewed. */

LPVOID FUN_c0332264(SIZE_T param_1)

{
  LPVOID pvVar1;
  
  if (DAT_c034d33c == (HANDLE)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = HeapAlloc(DAT_c034d33c,0,param_1);
  }
  return pvVar1;
}



/* c03322a0 FUN_c03322a0 */

/* Boundary evidence: original MIPS .pdata c03322a0..c03322c7. Semantic name remains unreviewed. */

void FUN_c03322a0(LPVOID param_1)

{
  HeapFree(DAT_c034d33c,0,param_1);
  return;
}



/* c03322c8 FUN_c03322c8 */

/* Boundary evidence: original MIPS .pdata c03322c8..c0332307. Semantic name remains unreviewed. */

LPVOID FUN_c03322c8(LPVOID param_1,SIZE_T param_2)

{
  LPVOID pvVar1;
  
  if (DAT_c034d33c == (HANDLE)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = HeapReAlloc(DAT_c034d33c,0,param_1,param_2);
  }
  return pvVar1;
}



/* c0332308 FSD_MountDisk */

/* Boundary evidence: original MIPS .pdata c0332308..c0332353. Semantic name remains unreviewed. */

bool FSD_MountDisk(int param_1)

{
  DWORD dwErrCode;
  
                    /* 0x2308  19  FSD_MountDisk */
  dwErrCode = FUN_c0336d8c(-0x3fcb2cc0,param_1);
  SetLastError(dwErrCode);
  return dwErrCode == 0;
}



/* c0332354 FSD_UnmountDisk */

/* Boundary evidence: original MIPS .pdata c0332354..c033239b. Semantic name remains unreviewed. */

bool FSD_UnmountDisk(int param_1)

{
  DWORD dwErrCode;
  
                    /* 0x2354  31  FSD_UnmountDisk */
  dwErrCode = FUN_c0335a28(-0x3fcb2cc0,param_1);
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return dwErrCode == 0;
}



/* c033239c FUN_c033239c */

/* Boundary evidence: original MIPS .pdata c033239c..c033240b. Semantic name remains unreviewed. */

undefined4 FUN_c033239c(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_c0333d18(-0x3fcb2cc0);
    HeapDestroy(DAT_c034d33c);
  }
  else if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_c034d33c = HeapCreate(0,0x1000,0);
  }
  return 1;
}



/* c033240c FUN_c033240c */

/* Boundary evidence: original MIPS .pdata c033240c..c0332463. Semantic name remains unreviewed. */

undefined4 * FUN_c033240c(undefined4 *param_1,uint param_2)

{
  FUN_c0333d90(param_1);
  if ((param_2 & 1) != 0) {
    HeapFree(DAT_c034d33c,0,param_1);
  }
  return param_1;
}



/* c0332464 FUN_c0332464 */

/* Boundary evidence: original MIPS .pdata c0332464..c03324fb. Semantic name remains unreviewed. */

void FUN_c0332464(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = *(int *)(param_1 + 8);
  while (iVar1 == 0) {
    EventModify(*(undefined4 *)(param_1 + 4),2);
    LeaveCriticalSection(lpCriticalSection);
    WaitForSingleObject(*(HANDLE *)(param_1 + 4),0xffffffff);
    EnterCriticalSection(lpCriticalSection);
    iVar1 = *(int *)(param_1 + 8);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  LeaveCriticalSection(lpCriticalSection);
  return;
}



/* c03324fc FUN_c03324fc */

/* Boundary evidence: original MIPS .pdata c03324fc..c0332577. Semantic name remains unreviewed. */

undefined4 FUN_c03324fc(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  if (param_1[2] < *param_1) {
    uVar1 = param_1[2] + 1;
    uVar2 = 1;
    param_1[2] = uVar1;
    if (uVar1 == 1) {
      EventModify(param_1[1],3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return uVar2;
}



/* c0332578 FSD_CreateFileW */

/* Boundary evidence: original MIPS .pdata c0332578..c033263b. Semantic name remains unreviewed. */

int FSD_CreateFileW(int *param_1,undefined4 param_2,wchar_t *param_3,uint param_4,uint param_5,
                   int param_6,int param_7,uint param_8)

{
  DWORD dwErrCode;
  int local_20 [2];
  
                    /* 0x2578  3  FSD_CreateFileW */
  local_20[0] = -1;
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c033700c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                             local_20);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return local_20[0];
    }
  }
  SetLastError(dwErrCode);
  return local_20[0];
}



/* c033263c FSD_CloseFile */

/* Boundary evidence: original MIPS .pdata c033263c..c03326bf. Semantic name remains unreviewed. */

undefined4 FSD_CloseFile(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
                    /* 0x263c  1  FSD_CloseFile */
  if (param_1 == (undefined4 *)0x0) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else {
    piVar2 = (int *)param_1[3];
    uVar1 = 1;
    if (piVar2 != (int *)0x0) {
      FUN_c0332464(piVar2[0x1c]);
      FUN_c03375dc(piVar2,param_1,1);
      FUN_c03324fc((uint *)piVar2[0x1c]);
    }
  }
  return uVar1;
}



/* c03326c0 FSD_ReadFile */

/* Boundary evidence: original MIPS .pdata c03326c0..c03327d3. Semantic name remains unreviewed. */

undefined4 FSD_ReadFile(int param_1,void *param_2,uint param_3,uint *param_4)

{
  void *pvVar1;
  uint uVar2;
  DWORD dwErrCode;
  uint local_20 [2];
  
                    /* 0x26c0  22  FSD_ReadFile */
  local_20[0] = 0;
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else if ((*(uint *)(param_1 + 0x14) & 0x80000000) == 0) {
    dwErrCode = 5;
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0) {
      pvVar1 = param_2;
      FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
      dwErrCode = FUN_c033a3b0(*(int *)(param_1 + 0x10),pvVar1,*(uint *)(param_1 + 0x20),
                               *(uint *)(param_1 + 0x24),param_2,param_3,local_20);
      FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
    }
    uVar2 = local_20[0] + *(int *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar2;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar2 < local_20[0]);
    if (param_4 != (uint *)0x0) {
      *param_4 = local_20[0];
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03327d4 FSD_ReadFileWithSeek */

/* Boundary evidence: original MIPS .pdata c03327d4..c03328f3. Semantic name remains unreviewed. */

undefined4
FSD_ReadFileWithSeek
          (int param_1,void *param_2,uint param_3,undefined4 *param_4,undefined4 param_5,
          uint param_6,uint param_7)

{
  void *pvVar1;
  DWORD dwErrCode;
  undefined4 local_28 [2];
  
                    /* 0x27d4  24  FSD_ReadFileWithSeek */
  local_28[0] = 0;
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    if ((*(uint *)(param_1 + 0x14) & 0x80000000) != 0) {
      if ((param_2 != (void *)0x0) || (param_3 != 0)) {
        if (*(int *)(param_1 + 0x10) != 0) {
          pvVar1 = param_2;
          FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
          dwErrCode = FUN_c033a3b0(*(int *)(param_1 + 0x10),pvVar1,param_6,param_7,param_2,param_3,
                                   local_28);
          FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
        }
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = local_28[0];
        }
        if (dwErrCode != 0) goto LAB_c03328b0;
      }
      return 1;
    }
    dwErrCode = 5;
  }
LAB_c03328b0:
  SetLastError(dwErrCode);
  return 0;
}



/* c03328f4 FSD_ReadFileScatter */

/* Boundary evidence: original MIPS .pdata c03328f4..c03329fb. Semantic name remains unreviewed. */

undefined4 FSD_ReadFileScatter(int param_1,void *param_2,uint param_3,int param_4)

{
  uint uVar1;
  DWORD dwErrCode;
  
                    /* 0x28f4  23  FSD_ReadFileScatter */
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    if ((*(uint *)(param_1 + 0x14) & 0x80000000) != 0) {
      if (*(int *)(param_1 + 0x10) != 0) {
        FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
        dwErrCode = FUN_c033a434(*(int *)(param_1 + 0x10),param_2,param_3,param_4,
                                 *(uint *)(param_1 + 0x20),*(uint *)(param_1 + 0x24));
        FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
        if (dwErrCode != 0) goto LAB_c0332998;
      }
      if (param_4 != 0) {
        return 1;
      }
      uVar1 = param_3 + *(int *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar1 < param_3);
      return 1;
    }
    dwErrCode = 5;
  }
LAB_c0332998:
  SetLastError(dwErrCode);
  if (dwErrCode == 0) {
    return 1;
  }
  return 0;
}



/* c03329fc FSD_WriteFile */

/* Boundary evidence: original MIPS .pdata c03329fc..c0332b0f. Semantic name remains unreviewed. */

undefined4 FSD_WriteFile(int param_1,void *param_2,uint param_3,uint *param_4)

{
  void *pvVar1;
  uint uVar2;
  DWORD dwErrCode;
  uint local_20 [2];
  
                    /* 0x29fc  32  FSD_WriteFile */
  local_20[0] = 0;
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
    dwErrCode = 5;
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0) {
      pvVar1 = param_2;
      FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
      dwErrCode = FUN_c033a95c(*(uint **)(param_1 + 0x10),pvVar1,*(uint *)(param_1 + 0x20),
                               *(uint *)(param_1 + 0x24),param_2,param_3,(int *)local_20);
      FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
    }
    uVar2 = local_20[0] + *(int *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar2;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar2 < local_20[0]);
    if (param_4 != (uint *)0x0) {
      *param_4 = local_20[0];
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0332b10 FSD_WriteFileWithSeek */

/* Boundary evidence: original MIPS .pdata c0332b10..c0332c1f. Semantic name remains unreviewed. */

undefined4
FSD_WriteFileWithSeek
          (int param_1,void *param_2,uint param_3,int *param_4,undefined4 param_5,uint param_6,
          uint param_7)

{
  void *pvVar1;
  DWORD dwErrCode;
  int local_28 [2];
  
                    /* 0x2b10  34  FSD_WriteFileWithSeek */
  local_28[0] = 0;
  dwErrCode = 0;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
    dwErrCode = 5;
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0) {
      pvVar1 = param_2;
      FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
      dwErrCode = FUN_c033a95c(*(uint **)(param_1 + 0x10),pvVar1,param_6,param_7,param_2,param_3,
                               local_28);
      FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
    }
    if (param_4 != (int *)0x0) {
      *param_4 = local_28[0];
    }
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0332c20 FSD_WriteFileGather */

/* Boundary evidence: original MIPS .pdata c0332c20..c0332d27. Semantic name remains unreviewed. */

undefined4 FSD_WriteFileGather(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  DWORD dwErrCode;
  
                    /* 0x2c20  33  FSD_WriteFileGather */
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    if ((*(uint *)(param_1 + 0x14) & 0x40000000) != 0) {
      if (*(int *)(param_1 + 0x10) != 0) {
        FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
        dwErrCode = FUN_c033aa68(*(uint **)(param_1 + 0x10),param_2,param_3,param_4,
                                 *(uint *)(param_1 + 0x20),*(uint *)(param_1 + 0x24));
        FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
        if (dwErrCode != 0) goto LAB_c0332cc4;
      }
      if (param_4 != 0) {
        return 1;
      }
      uVar1 = param_3 + *(int *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(uVar1 < param_3);
      return 1;
    }
    dwErrCode = 5;
  }
LAB_c0332cc4:
  SetLastError(dwErrCode);
  if (dwErrCode == 0) {
    return 1;
  }
  return 0;
}



/* c0332d28 FSD_SetFilePointer */

/* Boundary evidence: original MIPS .pdata c0332d28..c0332e77. Semantic name remains unreviewed. */

uint FSD_SetFilePointer(int param_1,uint param_2,int *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  DWORD dwErrCode;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
                    /* 0x2d28  29  FSD_SetFilePointer */
  dwErrCode = 0;
  uVar4 = 0xffffffff;
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x14) & 0xc0000000) == 0) {
      dwErrCode = 5;
      param_2 = uVar4;
      goto LAB_c0332e40;
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      if (param_3 == (int *)0x0) {
        iVar3 = (int)param_2 >> 0x1f;
      }
      else {
        iVar3 = *param_3;
      }
      if (param_4 != 0) {
        if (param_4 == 1) {
          iVar2 = *(int *)(param_1 + 0x24);
          param_2 = *(uint *)(param_1 + 0x20) + param_2;
          bVar1 = param_2 < *(uint *)(param_1 + 0x20);
        }
        else {
          if (param_4 != 2) goto LAB_c0332dc0;
          uVar5 = FUN_c0338ac4(*(int *)(param_1 + 0x10));
          iVar2 = (int)((ulonglong)uVar5 >> 0x20);
          param_2 = (uint)uVar5 + param_2;
          bVar1 = param_2 < (uint)uVar5;
        }
        iVar3 = iVar2 + iVar3 + (uint)bVar1;
      }
      if (((iVar3 == 0) || ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x20) != 0)) &&
         ((0 < iVar3 || (iVar3 == 0)))) {
        *(uint *)(param_1 + 0x20) = param_2;
        *(int *)(param_1 + 0x24) = iVar3;
        if (param_3 != (int *)0x0) {
          *param_3 = iVar3;
        }
      }
      else {
        dwErrCode = 0x83;
        param_2 = uVar4;
      }
      goto LAB_c0332e40;
    }
  }
LAB_c0332dc0:
  dwErrCode = 0x57;
  param_2 = uVar4;
LAB_c0332e40:
  SetLastError(dwErrCode);
  return param_2;
}



/* c0332e78 FSD_GetFileSize */

/* Boundary evidence: original MIPS .pdata c0332e78..c0332f23. Semantic name remains unreviewed. */

undefined4 FSD_GetFileSize(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  DWORD dwErrCode;
  undefined8 uVar2;
  undefined1 auStack_14 [4];
  
                    /* 0x2e78  16  FSD_GetFileSize */
  dwErrCode = 0;
  memset(auStack_14,0,4);
  if ((param_1 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    uVar1 = 0;
    dwErrCode = 0x57;
  }
  else {
    uVar2 = FUN_c0338ac4(*(int *)(param_1 + 0x10));
    uVar1 = (undefined4)uVar2;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = (int)((ulonglong)uVar2 >> 0x20);
    }
  }
  SetLastError(dwErrCode);
  if ((dwErrCode != 0) && (uVar1 = 0xffffffff, param_2 != (undefined4 *)0x0)) {
    *param_2 = 0xffffffff;
  }
  return uVar1;
}



/* c0332f24 FSD_GetFileInformationByHandle */

/* Boundary evidence: original MIPS .pdata c0332f24..c0332f93. Semantic name remains unreviewed. */

undefined4 FSD_GetFileInformationByHandle(int param_1,undefined4 *param_2)

{
  DWORD dwErrCode;
  
                    /* 0x2f24  15  FSD_GetFileInformationByHandle */
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    dwErrCode = 0x57;
  }
  else {
    if (*(int *)(param_1 + 0x10) == 0) {
      dwErrCode = 0x57;
      goto LAB_c0332f6c;
    }
    dwErrCode = FUN_c0339698(*(int *)(param_1 + 0x10),param_2);
  }
  if (dwErrCode == 0) {
    return 1;
  }
LAB_c0332f6c:
  SetLastError(dwErrCode);
  return 0;
}



/* c0332f94 FSD_FlushFileBuffers */

/* Boundary evidence: original MIPS .pdata c0332f94..c033306f. Semantic name remains unreviewed. */

undefined4 FSD_FlushFileBuffers(int param_1)

{
  int *piVar1;
  DWORD dwErrCode;
  
                    /* 0x2f94  11  FSD_FlushFileBuffers */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    dwErrCode = 0x57;
  }
  else {
    if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
      dwErrCode = 5;
      goto LAB_c0333040;
    }
    piVar1 = *(int **)(param_1 + 0xc);
    FUN_c0332464(piVar1[0x1c]);
    (**(code **)(*piVar1 + 0x34))(piVar1,2,1);
    dwErrCode = FUN_c033a618(*(int *)(param_1 + 0x10),0,1);
    (**(code **)(*piVar1 + 0x38))(piVar1);
    FUN_c03324fc((uint *)piVar1[0x1c]);
  }
  if (dwErrCode == 0) {
    return 1;
  }
LAB_c0333040:
  SetLastError(dwErrCode);
  return 0;
}



/* c0333070 FSD_GetFileTime */

/* Boundary evidence: original MIPS .pdata c0333070..c03330cb. Semantic name remains unreviewed. */

undefined4 FSD_GetFileTime(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  DWORD dwErrCode;
  
                    /* 0x3070  17  FSD_GetFileTime */
  if ((param_1 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = FUN_c0338968(*(int *)(param_1 + 0x10),param_2,param_3,param_4);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03330cc FSD_SetFileTime */

/* Boundary evidence: original MIPS .pdata c03330cc..c0333143. Semantic name remains unreviewed. */

undefined4 FSD_SetFileTime(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  DWORD dwErrCode;
  
                    /* 0x30cc  30  FSD_SetFileTime */
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
      dwErrCode = 5;
      goto LAB_c033311c;
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      dwErrCode = FUN_c033a7f0(*(int *)(param_1 + 0x10),param_2,param_3,param_4);
      if (dwErrCode == 0) {
        return 1;
      }
      goto LAB_c033311c;
    }
  }
  dwErrCode = 0x57;
LAB_c033311c:
  SetLastError(dwErrCode);
  return 0;
}



/* c0333144 FSD_SetEndOfFile */

/* Boundary evidence: original MIPS .pdata c0333144..c03331f3. Semantic name remains unreviewed. */

undefined4 FSD_SetEndOfFile(int param_1,undefined4 param_2)

{
  DWORD dwErrCode;
  int iVar1;
  
                    /* 0x3144  27  FSD_SetEndOfFile */
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0x14) & 0x40000000) == 0) {
      dwErrCode = 5;
      goto LAB_c03331c4;
    }
    iVar1 = *(int *)(param_1 + 0x10);
    if (iVar1 != 0) {
      FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
      dwErrCode = FUN_c033ada0(iVar1,param_2,*(uint *)(param_1 + 0x20),*(uint *)(param_1 + 0x24));
      FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
      if (dwErrCode == 0) {
        return 1;
      }
      goto LAB_c03331c4;
    }
  }
  dwErrCode = 0x57;
LAB_c03331c4:
  SetLastError(dwErrCode);
  return 0;
}



/* c03331f4 FSD_DeviceIoControl */

/* Boundary evidence: original MIPS .pdata c03331f4..c03332db. Semantic name remains unreviewed. */

undefined4
FSD_DeviceIoControl(int param_1,int param_2,uint *param_3,uint param_4,int *param_5,uint param_6,
                   undefined4 *param_7,undefined4 param_8)

{
  DWORD dwErrCode;
  
                    /* 0x31f4  7  FSD_DeviceIoControl */
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
    if (*(int *)(param_1 + 0x10) == 0) {
      dwErrCode = FUN_c033630c(*(int **)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6,
                               param_7);
    }
    else {
      dwErrCode = FUN_c033980c(*(int *)(param_1 + 0x10),param_2,param_3,param_4,param_5,param_6,
                               (int)param_7,param_8);
    }
    FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03332dc FSD_GetVolumeInfo */

/* Boundary evidence: original MIPS .pdata c03332dc..c033332b. Semantic name remains unreviewed. */

undefined4 FSD_GetVolumeInfo(int param_1,int param_2)

{
  DWORD dwErrCode;
  
                    /* 0x32dc  18  FSD_GetVolumeInfo */
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    dwErrCode = FUN_c033618c(param_1,param_2);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c033332c FSD_FindFirstFileW */

/* Boundary evidence: original MIPS .pdata c033332c..c03333ef. Semantic name remains unreviewed. */

int FSD_FindFirstFileW(int param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3,undefined4 *param_4)

{
  DWORD dwErrCode;
  int local_20 [2];
  
                    /* 0x332c  9  FSD_FindFirstFileW */
  local_20[0] = -1;
  if (((param_1 == 0) || (param_3 == (STRSAFE_LPCWSTR)0x0)) || (param_4 == (undefined4 *)0x0)) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(*(int *)(param_1 + 0x70));
    dwErrCode = FUN_c033769c(param_1,param_2,param_3,param_4,local_20);
    FUN_c03324fc(*(uint **)(param_1 + 0x70));
    if (dwErrCode == 2) {
      dwErrCode = 0x12;
    }
  }
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
  }
  return local_20[0];
}



/* c03333f0 FSD_FindNextFileW */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c03333f0..c03335a3. Semantic name remains unreviewed. */

undefined4 FSD_FindNextFileW(int param_1,undefined4 *param_2)

{
  DWORD dwErrCode;
  int *piVar1;
  undefined4 uVar2;
  int local_b0 [6];
  undefined4 auStack_98 [20];
  undefined4 local_48;
  undefined1 auStack_44 [12];
  undefined4 *local_38;
  uint local_1c;
  
                    /* 0x33f0  10  FSD_FindNextFileW */
  local_1c = DAT_c034d334;
  local_b0[0] = 0;
  memset(local_b0 + 1,0,0xc);
  FUN_c033af24(auStack_98);
  local_48 = 0;
  memset(auStack_44,0,0x28);
  if ((param_1 == 0) || (param_2 == (undefined4 *)0x0)) {
    dwErrCode = 0x57;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x10);
    local_b0[0] = param_1 + 0x28;
    local_b0[1] = 1;
    local_b0[2] = *(undefined4 *)(param_1 + 0x20);
    local_38 = param_2 + 10;
    FUN_c0332464(*(int *)(*(int *)(param_1 + 0xc) + 0x70));
    dwErrCode = (**(code **)(*piVar1 + 0xc))(piVar1,local_b0,auStack_98,&local_48);
    FUN_c03324fc(*(uint **)(*(int *)(param_1 + 0xc) + 0x70));
    if (dwErrCode == 0) {
      FUN_c033b008((int)auStack_98,param_2);
      *(undefined4 *)(param_1 + 0x20) = local_48;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (dwErrCode == 2) {
      dwErrCode = 0x12;
    }
  }
  uVar2 = 1;
  if ((dwErrCode != 0) && (SetLastError(dwErrCode), dwErrCode != 0)) {
    uVar2 = 0;
  }
  FUN_c034b674(local_1c);
  return uVar2;
}



/* c03335a4 FUN_c03335a4 */

/* Boundary evidence: original MIPS .pdata c03335a4..c03335af. Semantic name remains unreviewed. */

undefined4 FUN_c03335a4(void)

{
  return 1;
}



/* c03335b0 FSD_FindClose */

/* Boundary evidence: original MIPS .pdata c03335b0..c0333627. Semantic name remains unreviewed. */

undefined4 FSD_FindClose(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
                    /* 0x35b0  8  FSD_FindClose */
  if (param_1 == (undefined4 *)0x0) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else {
    piVar2 = (int *)param_1[3];
    if (piVar2 != (int *)0x0) {
      FUN_c0332464(piVar2[0x1c]);
      FUN_c03375dc(piVar2,param_1,0);
      FUN_c03324fc((uint *)piVar2[0x1c]);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c0333628 FSD_CreateDirectoryW */

/* Boundary evidence: original MIPS .pdata c0333628..c03336b3. Semantic name remains unreviewed. */

undefined4 FSD_CreateDirectoryW(int *param_1,STRSAFE_LPCWSTR param_2,int param_3)

{
  DWORD dwErrCode;
  
                    /* 0x3628  2  FSD_CreateDirectoryW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c03379a0(param_1,param_2,param_3);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03336b4 FSD_RemoveDirectoryW */

/* Boundary evidence: original MIPS .pdata c03336b4..c033372f. Semantic name remains unreviewed. */

undefined4 FSD_RemoveDirectoryW(int *param_1,STRSAFE_LPCWSTR param_2)

{
  DWORD dwErrCode;
  
                    /* 0x36b4  26  FSD_RemoveDirectoryW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c0337af0(param_1,param_2);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0333730 FSD_GetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c0333730..c03337b3. Semantic name remains unreviewed. */

int FSD_GetFileAttributesW(int param_1,STRSAFE_LPCWSTR param_2)

{
  DWORD dwErrCode;
  int local_18 [2];
  
                    /* 0x3730  14  FSD_GetFileAttributesW */
  local_18[0] = -1;
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(*(int *)(param_1 + 0x70));
    dwErrCode = FUN_c0337d44(param_1,param_2,local_18);
    FUN_c03324fc(*(uint **)(param_1 + 0x70));
    if (dwErrCode == 0) {
      return local_18[0];
    }
  }
  SetLastError(dwErrCode);
  return local_18[0];
}



/* c03337b4 FSD_SetFileAttributesW */

/* Boundary evidence: original MIPS .pdata c03337b4..c033383f. Semantic name remains unreviewed. */

undefined4 FSD_SetFileAttributesW(int *param_1,STRSAFE_LPCWSTR param_2,uint param_3)

{
  DWORD dwErrCode;
  
                    /* 0x37b4  28  FSD_SetFileAttributesW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c0337ddc(param_1,param_2,param_3);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0333840 FSD_DeleteFileW */

/* Boundary evidence: original MIPS .pdata c0333840..c03338c7. Semantic name remains unreviewed. */

undefined4 FSD_DeleteFileW(int *param_1,STRSAFE_LPCWSTR param_2)

{
  DWORD dwErrCode;
  
                    /* 0x3840  5  FSD_DeleteFileW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c0337f0c(param_1,param_2,1);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03338c8 FSD_MoveFileW */

/* Boundary evidence: original MIPS .pdata c03338c8..c0333957. Semantic name remains unreviewed. */

undefined4 FSD_MoveFileW(int *param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3)

{
  DWORD dwErrCode;
  
                    /* 0x38c8  20  FSD_MoveFileW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c03380f8(param_1,param_2,param_3,0);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0333958 FSD_DeleteAndRenameFileW */

/* Boundary evidence: original MIPS .pdata c0333958..c03339e3. Semantic name remains unreviewed. */

undefined4 FSD_DeleteAndRenameFileW(int *param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3)

{
  DWORD dwErrCode;
  
                    /* 0x3958  4  FSD_DeleteAndRenameFileW */
  if (param_1 == (int *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(param_1[0x1c]);
    dwErrCode = FUN_c03386d8(param_1,param_2,param_3);
    FUN_c03324fc((uint *)param_1[0x1c]);
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c03339e4 FSD_GetDiskFreeSpaceW */

/* Boundary evidence: original MIPS .pdata c03339e4..c0333a7b. Semantic name remains unreviewed. */

undefined4
FSD_GetDiskFreeSpaceW
          (int param_1,undefined4 param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6
          )

{
  DWORD dwErrCode;
  
                    /* 0x39e4  13  FSD_GetDiskFreeSpaceW */
  if (param_1 == 0) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c0332464(*(int *)(param_1 + 0x70));
    dwErrCode = FUN_c0334cd0(param_1,param_3,param_4,param_5,param_6);
    FUN_c03324fc(*(uint **)(param_1 + 0x70));
    if (dwErrCode == 0) {
      return 1;
    }
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0333a7c FSD_FormatVolume */

/* Boundary evidence: original MIPS .pdata c0333a7c..c0333a9f. Semantic name remains unreviewed. */

void FSD_FormatVolume(undefined4 param_1)

{
                    /* 0x3a7c  12  FSD_FormatVolume */
  FUN_c03340bc(&DAT_c034d340,param_1);
  return;
}



/* c0333aa0 FSD_DetectVolume */

/* Boundary evidence: original MIPS .pdata c0333aa0..c0333b2f. Semantic name remains unreviewed. */

undefined4 FSD_DetectVolume(undefined4 param_1,undefined4 param_2,int *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x3aa0  6  FSD_DetectVolume */
  iVar1 = FUN_c0334118(&DAT_c034d340,(char *)param_3,param_4);
  if (((iVar1 == 0) && (iVar1 = FUN_c03342b4(&DAT_c034d340,(char *)param_3,param_4), iVar1 == 0)) &&
     (iVar1 = FUN_c0334410(&DAT_c034d340,param_3), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* c0333b30 FSD_Notify */

/* Boundary evidence: original MIPS .pdata c0333b30..c0333b5f. Semantic name remains unreviewed. */

void FSD_Notify(int *param_1,uint param_2)

{
                    /* 0x3b30  21  FSD_Notify */
  if ((param_2 & 2) != 0) {
    (**(code **)(*param_1 + 0x14))();
  }
  return;
}



/* c0333b60 FUN_c0333b60 */

/* Boundary evidence: original MIPS .pdata c0333b60..c0333ba3. Semantic name remains unreviewed. */

undefined4 * FUN_c0333b60(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03311ac;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[8] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return param_1;
}



/* c0333ba4 FUN_c0333ba4 */

undefined4 FUN_c0333ba4(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* c0333bac FUN_c0333bac */

undefined4 FUN_c0333bac(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 8);
  }
  return uVar1;
}



/* c0333bc8 FUN_c0333bc8 */

undefined4 FUN_c0333bc8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 4);
  }
  return uVar1;
}



/* c0333be4 FUN_c0333be4 */

undefined4 FUN_c0333be4(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



/* c0333bec FUN_c0333bec */

/* Boundary evidence: original MIPS .pdata c0333bec..c0333c6b. Semantic name remains unreviewed. */

void FUN_c0333bec(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 4) != 0) {
    *(int *)(*(int *)(param_1 + 4) + 8) = param_2;
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 8) = param_2;
  }
  *(int *)(param_1 + 4) = param_2;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c0333c6c FUN_c0333c6c */

/* Boundary evidence: original MIPS .pdata c0333c6c..c0333d17. Semantic name remains unreviewed. */

void FUN_c0333c6c(int param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (*(int *)(param_2 + 8) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 8) + 4) = *(undefined4 *)(param_2 + 4);
  }
  if (*(int *)(param_2 + 4) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 4) + 8) = *(undefined4 *)(param_2 + 8);
  }
  if (*(int *)(param_2 + 8) == 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  }
  if (*(int *)(param_2 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c0333d18 FUN_c0333d18 */

/* Boundary evidence: original MIPS .pdata c0333d18..c0333d8f. Semantic name remains unreviewed. */

void FUN_c0333d18(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  puVar1 = *(undefined4 **)(param_1 + 4);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)puVar1[1];
    (**(code **)*puVar1)(puVar1,1);
    puVar1 = puVar2;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c0333d90 FUN_c0333d90 */

/* Boundary evidence: original MIPS .pdata c0333d90..c0333dcb. Semantic name remains unreviewed. */

void FUN_c0333d90(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c03311ac;
  FUN_c0333d18((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return;
}



/* c0333dcc FUN_c0333dcc */

/* Boundary evidence: original MIPS .pdata c0333dcc..c0333e2b. Semantic name remains unreviewed. */

undefined4 * FUN_c0333dcc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c03311ac;
  FUN_c0333d18((int)param_1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0333e2c FUN_c0333e2c */

/* Boundary evidence: original MIPS .pdata c0333e2c..c0333e6f. Semantic name remains unreviewed. */

undefined4 * FUN_c0333e2c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c033161c;
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0333e70 FUN_c0333e70 */

/* Boundary evidence: original MIPS .pdata c0333e70..c0333ec3. Semantic name remains unreviewed. */

undefined4 * FUN_c0333e70(undefined4 *param_1,undefined4 param_2)

{
  HANDLE pvVar1;
  
  *param_1 = param_2;
  param_1[2] = param_2;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  param_1[1] = pvVar1;
  return param_1;
}



/* c0333ec4 FUN_c0333ec4 */

/* Boundary evidence: original MIPS .pdata c0333ec4..c0333f27. Semantic name remains unreviewed. */

int FUN_c0333ec4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0333ba4(param_1);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (**(int **)(iVar1 + 0x14) == param_2) break;
    iVar1 = FUN_c0333bc8(param_1,iVar1);
  }
  return iVar1;
}



/* c0333f28 FUN_c0333f28 */

/* Boundary evidence: original MIPS .pdata c0333f28..c03340bb. Semantic name remains unreviewed. */

void FUN_c0333f28(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int local_30;
  int local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_1c = 0;
  local_24 = 0;
  local_18 = 0;
  local_14 = 0;
  local_28 = 0;
  FSDMGR_GetRegistryValue(param_2,L"FormatTfat",&local_30);
  FSDMGR_GetRegistryValue(param_2,L"FormatExfat",&local_2c);
  FSDMGR_GetRegistryValue(param_2,L"FormatClusterSize",&local_20);
  FSDMGR_GetRegistryValue(param_2,L"FormatFatVersion",&local_1c);
  FSDMGR_GetRegistryValue(param_2,L"FormatNumberOfFats",&local_24);
  FSDMGR_GetRegistryValue(param_2,L"FullFormat",&local_18);
  FSDMGR_GetRegistryValue(param_2,L"SecureWipe",&local_14);
  if (local_30 != 0) {
    local_2c = 1;
  }
  FSDMGR_GetRegistryValue(param_2,L"Flags",&local_28);
  if (((local_28 & 0x10) != 0) || (local_30 != 0)) {
    local_24 = 2;
  }
  *param_3 = 0x3c;
  param_3[2] = 0x200;
  param_3[1] = local_20;
  param_3[3] = local_1c;
  param_3[4] = local_24;
  param_3[5] = 4;
  param_3[0xd] = 0;
  param_3[0xe] = 0;
  if (local_30 != 0) {
    param_3[5] = 6;
  }
  if (local_2c != 0) {
    param_3[5] = param_3[5] | 0x10;
  }
  if (local_18 != 0) {
    param_3[5] = param_3[5] | 1;
  }
  if (local_14 != 0) {
    param_3[5] = param_3[5] | 8;
  }
  return;
}



/* c03340bc FUN_c03340bc */

/* Boundary evidence: original MIPS .pdata c03340bc..c0334117. Semantic name remains unreviewed. */

void FUN_c03340bc(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_50;
  undefined1 auStack_4c [60];
  
  local_50 = 0;
  memset(auStack_4c,0,0x38);
  FUN_c0333f28(param_1,param_2,&local_50);
  FSDMGR_FormatVolume(param_2,&local_50);
  return;
}



/* c0334118 FUN_c0334118 */

/* Boundary evidence: original MIPS .pdata c0334118..c03342b3. Semantic name remains unreviewed. */

undefined4 FUN_c0334118(undefined4 param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 != (char *)0x0) {
    uVar4 = 1 << ((byte)param_2[0x6c] & 0x1f);
    cVar1 = *param_2;
    if (((cVar1 == -0x70) || (cVar1 == -0x15)) || (cVar1 == -0x17)) {
      uVar3 = 0;
      do {
        if (param_2[uVar3 + 0xb] != '\0') {
          return 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x35);
      if ((((0x1ff < uVar4) && (iVar2 = memcmp(param_2 + 3,"EXFAT   ",8), iVar2 == 0)) &&
          ((*(int *)(param_2 + 0x48) != 0 || *(int *)(param_2 + 0x4c) != 0 &&
           ((*(int *)(param_2 + 0x50) != 0 && (*(int *)(param_2 + 0x58) != 0)))))) &&
         ((*(int *)(param_2 + 0x54) != 0 &&
          (((((1 < *(uint *)(param_2 + 0x60) && (param_2[0x6e] != '\0')) &&
             (*(short *)(param_2 + 0x1fe) == -0x55ab)) &&
            ((*(int *)(param_2 + 0x5c) != 0 && (param_3 == uVar4)))) && (param_2[0x69] == '\x01'))))
         )) {
        return 1;
      }
    }
  }
  return 0;
}



/* c03342b4 FUN_c03342b4 */

/* Boundary evidence: original MIPS .pdata c03342b4..c033440f. Semantic name remains unreviewed. */

undefined4 FUN_c03342b4(undefined4 param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 != (char *)0x0) &&
     (((cVar1 = *param_2, cVar1 == -0x70 || (cVar1 == -0x15)) || (cVar1 == -0x17)))) {
    uVar3 = (uint)*(ushort *)(param_2 + 0xb);
    if ((((0x1ff < uVar3) && (iVar2 = FUN_c033b768(uVar3), iVar2 != -1)) && (param_2[0x10] != '\0'))
       && (((param_2[0x13] != '\0' || param_2[0x14] != '\0' || (*(int *)(param_2 + 0x20) != 0)) &&
           ((*(short *)(param_2 + 0x1fe) == -0x55ab &&
            (((param_2[0x16] != '\0' || param_2[0x17] != '\0' ||
              ((*(int *)(param_2 + 0x24) != 0 && (param_2[0x2a] == '\0' && param_2[0x2b] == '\0'))))
             && (param_3 == *(ushort *)(param_2 + 0xb))))))))) {
      return 1;
    }
  }
  return 0;
}



/* c0334410 FUN_c0334410 */

undefined4 FUN_c0334410(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2 == (int *)0x0) || (uVar1 = 1, *param_2 != -0x5e4d3c2c)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0334438 FUN_c0334438 */

/* Boundary evidence: original MIPS .pdata c0334438..c03344bf. Semantic name remains unreviewed. */

undefined4 * FUN_c0334438(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[5] = param_2;
  param_1[0x1d] = param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_c033162c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0x19] = 1;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  *(undefined2 *)(param_1 + 0x1e) = 0;
  memset(param_1 + 8,0,0x44);
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa2));
  return param_1;
}



/* c03344c0 FUN_c03344c0 */

/* Boundary evidence: original MIPS .pdata c03344c0..c033451b. Semantic name remains unreviewed. */

LPVOID FUN_c03344c0(LPVOID param_1,uint param_2)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0xc));
  CloseHandle(*(HANDLE *)((int)param_1 + 4));
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c033451c FUN_c033451c */

/* Boundary evidence: original MIPS .pdata c033451c..c033453b. Semantic name remains unreviewed. */

void FUN_c033451c(int param_1)

{
  FSDMGR_GetRegistryValue(**(undefined4 **)(param_1 + 0x14));
  return;
}



/* c033453c FUN_c033453c */

/* Boundary evidence: original MIPS .pdata c033453c..c0334707. Semantic name remains unreviewed. */

undefined4 FUN_c033453c(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  uVar3 = **(undefined4 **)(param_1 + 0x14);
  puVar2 = (uint *)(param_1 + 0x68);
  *puVar2 = 0x54;
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"Flags",puVar2);
  if (iVar1 == 0) {
    FSDMGR_GetRegistryFlag(uVar3,L"UpdateAccess",puVar2,1);
    FSDMGR_GetRegistryFlag(uVar3,L"DisableAutoScan",puVar2,4);
    FSDMGR_GetRegistryFlag(uVar3,L"ForceWritethrough",puVar2,0x20);
    FSDMGR_GetRegistryFlag(uVar3,L"DisableAutoFormat",puVar2,0x40);
    FSDMGR_GetRegistryFlag(uVar3,L"TransactData",puVar2,0x40000);
    FSDMGR_GetRegistryFlag(uVar3,L"NonatomicSector",puVar2,0x80000);
    FSDMGR_GetRegistryFlag(uVar3,L"LFNExtendedAlways",puVar2,0x800000);
    FSDMGR_GetRegistryFlag(uVar3,L"SecuritySupport",puVar2,0x80);
    FSDMGR_GetRegistryFlag(uVar3,L"DirHandleWrite",puVar2,0x100);
    FSDMGR_GetRegistryFlag(uVar3,L"ForceNoFileBuffering",puVar2,0x200);
    FSDMGR_GetRegistryFlag(uVar3,L"ScanOnDirtyVolume",puVar2,0x2000000);
    FSDMGR_GetRegistryFlag(uVar3,L"EnableDebugLog",puVar2,0x8000000);
  }
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"CodePage",(undefined4 *)(param_1 + 100));
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 100) = 1;
  }
  iVar1 = FSDMGR_GetRegistryFlag(uVar3,L"ZeroInvalidData",puVar2,0x4000000);
  if ((iVar1 == 0) && ((*(uint *)(param_1 + 0x6c) & 0x10) != 0)) {
    *puVar2 = *puVar2 | 0x4000000;
  }
  return 0;
}



/* c0334708 FUN_c0334708 */

undefined4 FUN_c0334708(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x4c);
  uVar2 = *(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x3c);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if ((uVar2 / uVar1) * uVar1 == uVar2) {
    if ((((*(uint *)(param_1 + 0x3c) <= *(uint *)(param_1 + 0x50)) &&
         (*(uint *)(param_1 + 0x50) <= *(uint *)(param_1 + 0x54))) &&
        (*(uint *)(param_1 + 0x3c) < *(uint *)(param_1 + 0x58))) &&
       ((*(uint *)(param_1 + 0x40) < *(uint *)(param_1 + 0x58) &&
        (*(uint *)(param_1 + 0x5c) <= *(uint *)(param_1 + 0x48))))) {
      return 0;
    }
  }
  return 0xb;
}



/* c03347a4 FUN_c03347a4 */

/* Boundary evidence: original MIPS .pdata c03347a4..c03347e7. Semantic name remains unreviewed. */

void FUN_c03347a4(int *param_1)

{
  if ((param_1[0x1b] & 0x10U) == 0) {
    FUN_c033b300(param_1[5]);
  }
  else {
    (**(code **)(*param_1 + 0x28))(param_1,1);
  }
  return;
}



/* c03347e8 FUN_c03347e8 */

/* Boundary evidence: original MIPS .pdata c03347e8..c033485f. Semantic name remains unreviewed. */

undefined4 FUN_c03347e8(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  (**(code **)(*param_1 + 0x14))(param_1);
  if ((int *)param_1[6] != (int *)0x0) {
    uVar1 = (**(code **)(*(int *)param_1[6] + 8))();
  }
  if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
    FUN_c033e0d4((undefined4 *)param_1[7]);
  }
  return uVar1;
}



/* c0334860 FUN_c0334860 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0334860..c03349e7. Semantic name remains unreviewed. */

DWORD FUN_c0334860(int param_1)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  STRSAFE_LPWSTR pszDest;
  int local_230 [2];
  wchar_t local_228 [260];
  uint local_20;
  
  local_20 = DAT_c034d334;
  local_230[1] = 0;
  local_230[0] = 0;
  uVar3 = **(undefined4 **)(param_1 + 0x14);
  DVar2 = 0;
  StringCchCopyW(local_228,0x104,L"");
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"MountLabel",local_230);
  if ((iVar1 != 0) && (local_230[0] == 1)) {
    FSDMGR_GetDiskName(uVar3,local_228);
  }
  if (local_228[0] == L'\0') {
    iVar1 = FSDMGR_DiskIoControl(uVar3,0x71c20,0,0,local_228,0x208,local_230 + 1,0);
    if (iVar1 == 0) {
      StringCchCopyW(local_228,0x104,L"Mounted Volume");
    }
  }
  iVar1 = FSDMGR_RegisterVolume(uVar3,local_228,param_1);
  *(int *)(param_1 + 0x280) = iVar1;
  if (iVar1 == 0) {
    DVar2 = GetLastError();
    if (DVar2 == 0) {
      DVar2 = 0x1f;
    }
  }
  else {
    pszDest = (STRSAFE_LPWSTR)(param_1 + 0x78);
    iVar1 = FSDMGR_GetVolumeName(iVar1,pszDest,0x104);
    if (iVar1 == 0) {
      StringCchCopyW(pszDest,0x104,L"\\");
    }
    FSDMGR_AdvertiseInterface(&DAT_c033160c,pszDest,1);
  }
  FUN_c034b674(local_20);
  return DVar2;
}



/* c03349e8 FUN_c03349e8 */

/* Boundary evidence: original MIPS .pdata c03349e8..c0334a5b. Semantic name remains unreviewed. */

undefined4 FUN_c03349e8(int param_1)

{
  STRSAFE_LPWSTR pszDest;
  
  if (*(int *)(param_1 + 0x280) != 0) {
    FSDMGR_DeregisterVolume();
    *(undefined4 *)(param_1 + 0x280) = 0;
  }
  pszDest = (STRSAFE_LPWSTR)(param_1 + 0x78);
  if (*pszDest != L'\0') {
    FSDMGR_AdvertiseInterface(&DAT_c033160c,pszDest,0);
    StringCchCopyW(pszDest,0x104,L"");
  }
  return 0;
}



/* c0334a5c FUN_c0334a5c */

/* Boundary evidence: original MIPS .pdata c0334a5c..c0334ac3. Semantic name remains unreviewed. */

undefined4 FUN_c0334a5c(int param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  iVar1 = FSDMGR_GetRegistryValue(**(undefined4 **)(param_1 + 0x14),L"EnableWriteBack",local_10);
  if (iVar1 == 0) {
    if ((*(uint *)(param_1 + 0x6c) & 0x10) == 0) {
      local_10[0] = 0;
    }
    else {
      local_10[0] = 1;
    }
  }
  return local_10[0];
}



/* c0334ac4 FUN_c0334ac4 */

/* Boundary evidence: original MIPS .pdata c0334ac4..c0334bd7. Semantic name remains unreviewed. */

undefined4 FUN_c0334ac4(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_28;
  int local_24;
  int local_20 [2];
  
  local_28 = 0;
  local_24 = 0;
  local_20[0] = 0;
  uVar3 = **(undefined4 **)(param_1 + 0x14);
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"EnableCache",&local_24);
  if ((iVar1 != 0) && (local_24 != 0)) {
    FSDMGR_GetRegistryValue(uVar3,L"EnableFatCacheWarm",local_20);
    FSDMGR_GetRegistryValue(uVar3,L"FatCacheSize",&local_28);
    iVar1 = FUN_c0334a5c(param_1);
    if ((local_28 == 0) && (local_28 = *(uint *)(param_1 + 0x4c), 0x200 < local_28)) {
      local_28 = 0x200;
    }
    uVar2 = (uint)(local_20[0] != 0);
    if (iVar1 != 0) {
      uVar2 = uVar2 | 2;
    }
    iVar1 = *(int *)(param_1 + 0x4c);
    if ((*(uint *)(param_1 + 0x6c) & 0x40) != 0) {
      iVar1 = *(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50);
    }
    FUN_c033b228(*(undefined4 **)(param_1 + 0x14),*(int *)(param_1 + 0x50),iVar1,local_28,uVar2);
  }
  return 0;
}



/* c0334bd8 FUN_c0334bd8 */

/* Boundary evidence: original MIPS .pdata c0334bd8..c0334ccf. Semantic name remains unreviewed. */

undefined4 FUN_c0334bd8(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_20;
  int local_1c;
  int local_18 [2];
  
  local_20 = 0;
  local_1c = 0;
  local_18[0] = 0;
  uVar3 = **(undefined4 **)(param_1 + 0x14);
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"EnableCache",&local_1c);
  if ((iVar1 != 0) && (local_1c != 0)) {
    FSDMGR_GetRegistryValue(uVar3,L"EnableDataCacheWarm",local_18);
    FSDMGR_GetRegistryValue(uVar3,L"DataCacheSize",&local_20);
    iVar1 = FUN_c0334a5c(param_1);
    if ((local_20 == 0) && (local_20 = *(int *)(param_1 + 0x4c) << 1, 0x200 < local_20)) {
      local_20 = 0x200;
    }
    uVar2 = (uint)(local_18[0] != 0);
    if (iVar1 != 0) {
      uVar2 = uVar2 | 2;
    }
    FUN_c033b228(*(undefined4 **)(param_1 + 0x14),*(int *)(param_1 + 0x54),
                 *(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x54),local_20,uVar2);
  }
  return 0;
}



/* c0334cd0 FUN_c0334cd0 */

/* Boundary evidence: original MIPS .pdata c0334cd0..c0334db7. Semantic name remains unreviewed. */

void FUN_c0334cd0(int param_1,int *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x2c))(*(int **)(param_1 + 0x18),local_20);
  if (iVar1 == 0) {
    if (param_2 != (int *)0x0) {
      *param_2 = 1 << (*(byte *)(param_1 + 0x35) & 0x1f);
    }
    if (param_3 != (int *)0x0) {
      *param_3 = 1 << (*(byte *)(param_1 + 0x34) & 0x1f);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_20[0];
    }
    if (param_5 != (int *)0x0) {
      *param_5 = *(int *)(param_1 + 0x48) + -1;
    }
  }
  return;
}



/* c0334db8 FUN_c0334db8 */

/* Boundary evidence: original MIPS .pdata c0334db8..c0334dc3. Semantic name remains unreviewed. */

undefined4 FUN_c0334db8(void)

{
  return 1;
}



/* c0334dc4 FUN_c0334dc4 */

/* Boundary evidence: original MIPS .pdata c0334dc4..c0334eeb. Semantic name remains unreviewed. */

undefined4 FUN_c0334dc4(int param_1,void *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  
  memset(param_2,0,0x168);
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 0x18) & 1) != 0) {
    *(undefined1 *)((int)param_2 + 0xc) = 0xf8;
  }
  uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x14) + 8);
  *(char *)((int)param_2 + 0xd) = (char)uVar1;
  *(char *)((int)param_2 + 0xe) = (char)((ushort)uVar1 >> 8);
  *(char *)((int)param_2 + 0xf) = (char)(1 << (*(byte *)(param_1 + 0x35) & 0x1f));
  *(undefined4 *)((int)param_2 + 0x1e) = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x3c);
  *(char *)((int)param_2 + 0x10) = (char)uVar1;
  *(char *)((int)param_2 + 0x11) = (char)((ushort)uVar1 >> 8);
  uVar2 = *(uint *)(param_1 + 0x4c);
  if (uVar2 != 0) {
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    *(char *)((int)param_2 + 0x12) =
         (char)((uint)(*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x3c)) / uVar2);
  }
  uVar2 = *(uint *)(param_1 + 0x60) >> 5 & 0xffff;
  *(char *)((int)param_2 + 0x13) = (char)uVar2;
  *(char *)((int)param_2 + 0x14) = (char)(uVar2 >> 8);
  *(char *)((int)param_2 + 0x17) = (char)*(undefined4 *)(param_1 + 0x20);
  uVar1 = *(undefined2 *)(param_1 + 0x4c);
  *(char *)((int)param_2 + 0x18) = (char)uVar1;
  *(char *)((int)param_2 + 0x19) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x14) + 0x14);
  *(char *)((int)param_2 + 0x1a) = (char)uVar1;
  *(char *)((int)param_2 + 0x1b) = (char)((ushort)uVar1 >> 8);
  uVar1 = *(undefined2 *)(*(int *)(param_1 + 0x14) + 0x10);
  *(char *)((int)param_2 + 0x1c) = (char)uVar1;
  *(char *)((int)param_2 + 0x1d) = (char)((ushort)uVar1 >> 8);
  *(undefined4 *)((int)param_2 + 0x22) = *(undefined4 *)(param_1 + 0x58);
  return 0;
}



/* c0334eec FUN_c0334eec */

/* Boundary evidence: original MIPS .pdata c0334eec..c0334fd3. Semantic name remains unreviewed. */

undefined4 FUN_c0334eec(int param_1)

{
  int iVar1;
  undefined4 *_Dst;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  iVar1 = FSDMGR_DiskIoControl(**(undefined4 **)(param_1 + 0x14),0x71c80,0,0,0,0,local_18,0);
  if (iVar1 == 0) {
    _Dst = FUN_c0332264(1 << (*(byte *)(param_1 + 0x34) & 0x1f));
    if (_Dst == (undefined4 *)0x0) {
      uVar2 = 8;
    }
    else {
      memset(_Dst,0,1 << (*(byte *)(param_1 + 0x34) & 0x1f));
      *_Dst = 0xa1b2c3d4;
      uVar2 = FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),4,0,1,_Dst);
      FUN_c033b384(*(undefined4 **)(param_1 + 0x14));
      FUN_c03322a0(_Dst);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c0334fd4 FUN_c0334fd4 */

/* Boundary evidence: original MIPS .pdata c0334fd4..c0335073. Semantic name remains unreviewed. */

undefined4 FUN_c0334fd4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
  if ((*(uint *)(param_1 + 0x6c) & 0x300) == 0) {
    if ((*(int *)(param_1 + 0xc) == 0) ||
       (iVar1 = FUN_c033f34c(*(int *)(param_1 + 0xc)), iVar1 != 0)) {
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | param_2;
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 0x6c;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
  return uVar2;
}



/* c0335074 FUN_c0335074 */

/* Boundary evidence: original MIPS .pdata c0335074..c03350a7. Semantic name remains unreviewed. */

void FUN_c0335074(int param_1,uint param_2,int param_3,undefined4 param_4,uint param_5)

{
  FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),param_5 | 1,param_2,param_3,param_4);
  return;
}



/* c03350a8 FUN_c03350a8 */

/* Boundary evidence: original MIPS .pdata c03350a8..c033518f. Semantic name remains unreviewed. */

void FUN_c03350a8(int param_1,uint param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),param_5 | 2,param_2,param_3,param_4);
  if ((((iVar1 == 0) && ((*(uint *)(param_1 + 0x6c) & 0x40) != 0)) &&
      (*(uint *)(param_1 + 0x50) <= param_2)) &&
     ((param_2 < *(uint *)(param_1 + 0x54) &&
      (uVar2 = *(int *)(param_1 + 0x4c) + param_2, uVar2 < *(uint *)(param_1 + 0x54))))) {
    do {
      FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),param_5 | 2,uVar2,param_3,param_4);
      uVar2 = *(int *)(param_1 + 0x4c) + uVar2;
    } while (uVar2 < *(uint *)(param_1 + 0x54));
  }
  return;
}



/* c0335190 FUN_c0335190 */

/* Boundary evidence: original MIPS .pdata c0335190..c033520b. Semantic name remains unreviewed. */

undefined4 FUN_c0335190(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((*(uint *)(param_1 + 0x6c) & 0x400) == 0) {
    if (param_2 == 0) {
      uVar2 = *(uint *)(param_1 + 0x54);
    }
    else {
      uVar2 = (param_2 + -2 << (*(byte *)(param_1 + 0x35) & 0x1f)) + *(int *)(param_1 + 0x40);
    }
    iVar1 = FUN_c033b46c(*(undefined4 **)(param_1 + 0x14),uVar2,
                         param_3 << (*(byte *)(param_1 + 0x35) & 0x1f));
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x400;
    }
  }
  return 0;
}



/* c033520c FUN_c033520c */

/* Boundary evidence: original MIPS .pdata c033520c..c0335247. Semantic name remains unreviewed. */

bool FUN_c033520c(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  
  iVar1 = wcsncmp(param_2,param_3,0x104);
  return iVar1 == 0;
}



/* c0335248 FUN_c0335248 */

/* Boundary evidence: original MIPS .pdata c0335248..c03352c7. Semantic name remains unreviewed. */

undefined4 FUN_c0335248(undefined4 param_1,int param_2,int param_3,wint_t *param_4)

{
  wint_t wVar1;
  wint_t *pwVar2;
  int iVar3;
  
  if (param_3 != 0) {
    pwVar2 = param_4;
    iVar3 = param_3;
    do {
      wVar1 = towupper(*(wint_t *)((param_2 - (int)param_4) + (int)pwVar2));
      iVar3 = iVar3 + -1;
      *pwVar2 = wVar1;
      pwVar2 = pwVar2 + 1;
    } while (iVar3 != 0);
  }
  param_4[param_3] = 0;
  return 0;
}



/* c03352c8 FUN_c03352c8 */

uint FUN_c03352c8(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 0x14) + 0x98) & 1;
}



/* c03352d8 FUN_c03352d8 */

undefined4 FUN_c03352d8(int param_1,int param_2)

{
  if (*(uint *)(param_2 + 0x3c) <= *(uint *)(param_1 + 0x48)) {
    if ((*(uint *)(param_2 + 0x4c) <= *(uint *)(param_2 + 0x44)) &&
       ((*(uint *)(param_2 + 0x4c) != *(uint *)(param_2 + 0x44) ||
        (*(uint *)(param_2 + 0x48) <= *(uint *)(param_2 + 0x40))))) {
      return 1;
    }
  }
  return 0;
}



/* c033532c FUN_c033532c */

/* Boundary evidence: original MIPS .pdata c033532c..c03353bb. Semantic name remains unreviewed. */

undefined4 FUN_c033532c(int param_1,STRSAFE_PCNZWCH param_2,STRSAFE_PCNZWCH param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 0x284) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
    piVar1 = FUN_c033e8e4(*(int **)(param_1 + 0x284),param_2);
    if (piVar1 != (int *)0x0) {
      uVar2 = FUN_c033ee58((int)piVar1,param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
  }
  return uVar2;
}



/* c03353bc FUN_c03353bc */

/* Boundary evidence: original MIPS .pdata c03353bc..c033544b. Semantic name remains unreviewed. */

undefined4 FUN_c03353bc(int param_1,STRSAFE_PCNZWCH param_2,STRSAFE_PCNZWCH param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(int *)(param_1 + 0x284) != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
    piVar1 = FUN_c033e8e4(*(int **)(param_1 + 0x284),param_2);
    if (piVar1 != (int *)0x0) {
      uVar2 = FUN_c033f04c((int)piVar1,param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
  }
  return uVar2;
}



/* c033544c FUN_c033544c */

/* Boundary evidence: original MIPS .pdata c033544c..c03354cf. Semantic name remains unreviewed. */

void FUN_c033544c(int param_1,int param_2)

{
  int iVar1;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c034d334;
  if ((*(int *)(param_1 + 0x284) != 0) &&
     (iVar1 = FUN_c03393a4(param_2,awStack_220,0x104), iVar1 != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
    FUN_c033ea20(*(int **)(param_1 + 0x284),awStack_220);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x288));
  }
  FUN_c034b674(local_18);
  return;
}



/* c03354d0 FUN_c03354d0 */

/* Boundary evidence: original MIPS .pdata c03354d0..c033551b. Semantic name remains unreviewed. */

void FUN_c03354d0(int *param_1)

{
  if ((int *)param_1[0xa8] != (int *)0x0) {
    FUN_c0340548((int *)param_1[0xa8]);
  }
  (**(code **)(*param_1 + 0x14))(param_1);
  FUN_c03347e8(param_1);
  return;
}



/* c033551c FUN_c033551c */

/* Boundary evidence: original MIPS .pdata c033551c..c033573f. Semantic name remains unreviewed. */

int FUN_c033551c(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1[0x1d];
  if (1 < *(byte *)(iVar7 + 0x6e)) {
    param_1[0x1b] = param_1[0x1b] | 0x10;
  }
  param_1[0xf] = *(uint *)(iVar7 + 0x50);
  uVar4 = *(uint *)(iVar7 + 0x48);
  if (*(int *)(iVar7 + 0x4c) == 0) {
    param_1[0x16] = uVar4;
    if (uVar4 <= *(uint *)(iVar7 + 0x50)) {
      param_1[0x16] = *(int *)(param_1[5] + 4);
    }
    if (*(uint *)(param_1[5] + 4) < (uint)param_1[0x16]) {
      param_1[0x16] = *(uint *)(param_1[5] + 4);
    }
    bVar1 = *(byte *)(iVar7 + 0x6d);
    *(byte *)((int)param_1 + 0x35) = bVar1;
    bVar2 = *(byte *)(iVar7 + 0x6c);
    *(byte *)(param_1 + 0xd) = bVar2;
    uVar4 = 1 << ((uint)bVar2 + (uint)bVar1 & 0x1f);
    param_1[0xe] = uVar4;
    if (uVar4 < 0x10000001) {
      uVar4 = param_1[0x1b];
      param_1[0x1b] = uVar4 | 0x20;
      if ((*(byte *)(iVar7 + 0x6a) & 2) == 2) {
        param_1[0x1b] = uVar4 | 0x2020;
      }
      iVar3 = (**(code **)(*param_1 + 0x40))(param_1);
      if (iVar3 == 0) {
        piVar5 = (int *)(iVar7 + 0x54);
        param_1[9] = *(int *)(iVar7 + 100);
        param_1[0x13] = *piVar5;
        iVar3 = (uint)*(byte *)(iVar7 + 0x6e) * *piVar5 + param_1[0xf];
        param_1[0x15] = iVar3;
        param_1[0x14] = iVar3 - *piVar5;
        param_1[0x17] = *(int *)(iVar7 + 0x60);
        param_1[0x18] = 0;
        iVar3 = *(int *)(iVar7 + 0x58);
        param_1[0x10] = iVar3;
        uVar6 = ((uint)(param_1[0x13] << (*(byte *)(param_1 + 0xd) & 0x1f)) >> 2) - 2;
        uVar4 = (uint)(param_1[0x16] - iVar3) >> (*(byte *)((int)param_1 + 0x35) & 0x1f);
        if (uVar6 < uVar4) {
          uVar4 = uVar6;
        }
        if (*(uint *)(iVar7 + 0x5c) < uVar4) {
          uVar4 = *(uint *)(iVar7 + 0x5c);
        }
        param_1[0x12] = uVar4 + 1;
        param_1[0x11] = -1;
        iVar3 = FUN_c0334708((int)param_1);
      }
    }
    else {
      iVar3 = 0xb;
    }
  }
  else {
    iVar3 = 0x3ed;
  }
  return iVar3;
}



/* c0335740 FUN_c0335740 */

/* Boundary evidence: original MIPS .pdata c0335740..c03358b7. Semantic name remains unreviewed. */

int FUN_c0335740(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  local_40 = 0;
  local_38 = 0;
  local_3c = 0;
  uVar3 = **(undefined4 **)(param_1 + 0x14);
  iVar4 = 0;
  iVar1 = FSDMGR_GetRegistryValue(uVar3,L"EnableCache",&local_38);
  if ((iVar1 != 0) && (local_38 != 0)) {
    iVar1 = FSDMGR_GetRegistryValue(uVar3,L"EnableBitmapCacheWarm",&local_3c);
    if (iVar1 == 0) {
      local_3c = 1;
    }
    FSDMGR_GetRegistryValue(uVar3,L"BitmapCacheSize",&local_40);
    iVar1 = FUN_c0334a5c(param_1);
    local_30 = 0;
    local_34 = 0;
    local_28[0] = 0;
    local_2c = 0;
    iVar4 = (**(code **)(**(int **)(param_1 + 0x18) + 0x48))
                      (*(int **)(param_1 + 0x18),&local_30,&local_34,local_28,&local_2c);
    if (iVar4 == 0) {
      if ((local_40 == 0) && (local_40 = 0x200, local_34 < 0x201)) {
        local_40 = local_34;
      }
      uVar2 = (uint)(local_3c != 0);
      if (iVar1 != 0) {
        uVar2 = uVar2 | 2;
      }
      FUN_c033b228(*(undefined4 **)(param_1 + 0x14),local_30,local_34,local_40,uVar2);
      if (local_2c != 0) {
        FUN_c033b228(*(undefined4 **)(param_1 + 0x14),local_28[0],local_2c,local_40,uVar2);
      }
    }
  }
  return iVar4;
}



/* c03358b8 FUN_c03358b8 */

/* Boundary evidence: original MIPS .pdata c03358b8..c0335947. Semantic name remains unreviewed. */

undefined4 FUN_c03358b8(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x74);
  uVar1 = *(ushort *)(iVar2 + 0x6a);
  uVar3 = 0;
  if ((uVar1 & 2) == 0) {
    *(byte *)(iVar2 + 0x6a) = (byte)uVar1 | 2;
    *(char *)(iVar2 + 0x6b) = (char)(uVar1 >> 8);
    uVar3 = FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),10,0,1,*(undefined4 *)(param_1 + 0x74));
    FUN_c033b384(*(undefined4 **)(param_1 + 0x14));
  }
  return uVar3;
}



/* c0335948 FUN_c0335948 */

/* Boundary evidence: original MIPS .pdata c0335948..c03359ef. Semantic name remains unreviewed. */

undefined4 FUN_c0335948(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x74);
  uVar3 = 0;
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 0x98) & 1) == 0) {
    uVar1 = *(ushort *)(iVar2 + 0x6a);
    if ((uVar1 & 8) == 8) {
      *(byte *)(iVar2 + 0x6a) = *(byte *)(iVar2 + 0x6a) & 0xf7;
      *(char *)(iVar2 + 0x6b) = (char)(uVar1 >> 8);
      uVar3 = FUN_c033b5fc(*(undefined4 **)(param_1 + 0x14),10,0,1,*(undefined4 *)(param_1 + 0x74));
      FUN_c033b384(*(undefined4 **)(param_1 + 0x14));
    }
  }
  return uVar3;
}



/* c03359f0 FUN_c03359f0 */

/* Boundary evidence: original MIPS .pdata c03359f0..c0335a27. Semantic name remains unreviewed. */

void FUN_c03359f0(int param_1,int param_2,int param_3,wint_t *param_4)

{
  if (*(int *)(param_1 + 0x29c) == 0) {
    FUN_c0335248(param_1,param_2,param_3,param_4);
  }
  else {
    FUN_c03400f4(*(int *)(param_1 + 0x29c),param_2,param_3,param_4);
  }
  return;
}



/* c0335a28 FUN_c0335a28 */

/* Boundary evidence: original MIPS .pdata c0335a28..c0335adb. Semantic name remains unreviewed. */

undefined4 FUN_c0335a28(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    uVar2 = 0x57;
  }
  else {
    piVar1 = (int *)FUN_c0333ec4(param_1,param_2);
    if (piVar1 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar1 + 8))(piVar1);
      FUN_c0333c6c(param_1,(int)piVar1);
      (**(code **)*piVar1)(piVar1,1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return uVar2;
}



/* c0335adc FUN_c0335adc */

/* Boundary evidence: original MIPS .pdata c0335adc..c0335bef. Semantic name remains unreviewed. */

void FUN_c0335adc(undefined4 *param_1)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  int *piVar3;
  
  puVar1 = (undefined4 *)param_1[6];
  *param_1 = &PTR_FUN_c033162c;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  puVar1 = (undefined4 *)param_1[3];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  puVar1 = (undefined4 *)param_1[4];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  pvVar2 = (LPVOID)param_1[5];
  if (pvVar2 != (LPVOID)0x0) {
    FUN_c033b0d4((int)pvVar2);
    FUN_c03322a0(pvVar2);
  }
  if ((LPVOID)param_1[0x1d] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[0x1d]);
  }
  pvVar2 = (LPVOID)param_1[7];
  if (pvVar2 != (LPVOID)0x0) {
    FUN_c033e0b8((int)pvVar2);
    FUN_c03322a0(pvVar2);
  }
  if ((LPVOID)param_1[0x1c] != (LPVOID)0x0) {
    FUN_c03344c0((LPVOID)param_1[0x1c],1);
  }
  piVar3 = (int *)param_1[0xa1];
  if (piVar3 != (int *)0x0) {
    FUN_c033f0b4(piVar3);
    FUN_c03322a0(piVar3);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa2));
  *param_1 = &PTR_FUN_c033161c;
  return;
}



/* c0335bf0 FUN_c0335bf0 */

/* Boundary evidence: original MIPS .pdata c0335bf0..c0335c27. Semantic name remains unreviewed. */

void FUN_c0335bf0(int *param_1)

{
  (**(code **)(*param_1 + 0x10))(param_1);
  FUN_c03349e8((int)param_1);
  return;
}



/* c0335c28 FUN_c0335c28 */

/* Boundary evidence: original MIPS .pdata c0335c28..c0335fc7. Semantic name remains unreviewed. */

void FUN_c0335c28(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x74);
  *(uint *)(param_1 + 0x20) = (uint)*(byte *)(iVar8 + 0x15);
  *(uint *)(param_1 + 0x3c) = (uint)*(ushort *)(iVar8 + 0xe);
  uVar2 = *(ushort *)(iVar8 + 0x13);
  *(uint *)(param_1 + 0x58) = (uint)uVar2;
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar8 + 0x20);
  }
  if (*(uint *)(param_1 + 0x58) <= (uint)*(ushort *)(iVar8 + 0xe)) {
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
  }
  uVar6 = *(uint *)(*(int *)(param_1 + 0x14) + 4);
  if (uVar6 < *(uint *)(param_1 + 0x58)) {
    *(uint *)(param_1 + 0x58) = uVar6;
  }
  iVar3 = FUN_c033b768((uint)*(byte *)(iVar8 + 0xd));
  *(char *)(param_1 + 0x35) = (char)iVar3;
  iVar3 = FUN_c033b768((uint)*(ushort *)(iVar8 + 0xb));
  *(char *)(param_1 + 0x34) = (char)iVar3;
  *(int *)(param_1 + 0x38) = 1 << ((uint)*(byte *)(param_1 + 0x35) + iVar3 & 0x1f);
  if (*(char *)(iVar8 + 0x16) == '\0' && *(char *)(iVar8 + 0x17) == '\0') {
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 8;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar8 + 0x43);
    memcpy((void *)(param_1 + 0x28),(void *)(iVar8 + 0x47),0xb);
    piVar4 = (int *)(iVar8 + 0x24);
    *(int *)(param_1 + 0x4c) = *piVar4;
    uVar6 = 0;
    if ((*(byte *)(iVar8 + 0x28) & 0x80) == 0) {
      if (1 < *(byte *)(iVar8 + 0x10)) {
        *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x40;
      }
    }
    else {
      uVar6 = *(byte *)(iVar8 + 0x28) & 0xf;
    }
    *(uint *)(param_1 + 0x50) = uVar6 * *piVar4 + *(int *)(param_1 + 0x3c);
    iVar3 = (uint)*(byte *)(iVar8 + 0x10) * *piVar4 + *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x54) = iVar3;
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar8 + 0x2c);
    *(int *)(param_1 + 0x40) = iVar3;
    uVar7 = ((uint)(*(int *)(param_1 + 0x4c) << (*(byte *)(param_1 + 0x34) & 0x1f)) >> 2) - 2;
    uVar6 = (uint)(*(int *)(param_1 + 0x58) - iVar3) >> (*(byte *)(param_1 + 0x35) & 0x1f);
    *(undefined4 *)(param_1 + 0x60) = 0;
    if (uVar7 < uVar6) {
      uVar6 = uVar7;
    }
    *(undefined4 *)(param_1 + 0x44) = 0xffffff8;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar8 + 0x27);
    memcpy((void *)(param_1 + 0x28),(void *)(iVar8 + 0x2b),0xb);
    *(uint *)(param_1 + 0x4c) = (uint)*(ushort *)(iVar8 + 0x16);
    if (1 < *(byte *)(iVar8 + 0x10)) {
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x40;
    }
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x3c);
    uVar2 = *(ushort *)(iVar8 + 0x16);
    bVar1 = *(byte *)(iVar8 + 0x10);
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(uint *)(param_1 + 0x54) = (uint)uVar2 * (uint)bVar1 + *(int *)(param_1 + 0x3c);
    iVar3 = (uint)*(ushort *)(iVar8 + 0x11) * 0x20;
    *(int *)(param_1 + 0x60) = iVar3;
    iVar8 = (((uint)*(ushort *)(iVar8 + 0xb) + iVar3) - 1 >> (*(byte *)(param_1 + 0x34) & 0x1f)) +
            *(int *)(param_1 + 0x54);
    uVar6 = (uint)(*(int *)(param_1 + 0x58) - iVar8) >> (*(byte *)(param_1 + 0x35) & 0x1f);
    uVar7 = *(int *)(param_1 + 0x4c) << (*(byte *)(param_1 + 0x34) + 3 & 0x1f);
    *(int *)(param_1 + 0x40) = iVar8;
    if (uVar6 < 0xff6) {
      uVar7 = uVar7 / 0xc;
      uVar5 = 0xff0;
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 2;
      if (0xfee < uVar6) {
        uVar5 = 0xff8;
      }
    }
    else {
      uVar7 = uVar7 >> 4;
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 4;
      uVar5 = 0xfff8;
    }
    *(undefined4 *)(param_1 + 0x44) = uVar5;
    if (uVar7 - 2 < uVar6) {
      uVar6 = uVar7 - 2;
    }
  }
  *(uint *)(param_1 + 0x48) = uVar6 + 1;
  FUN_c0334708(param_1);
  return;
}



/* c0335fc8 FUN_c0335fc8 */

/* Boundary evidence: original MIPS .pdata c0335fc8..c033618b. Semantic name remains unreviewed. */

int FUN_c0335fc8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_18 [2];
  
  puVar1 = FUN_c0332264(0x44);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c0342440(puVar1,param_1);
  }
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_c03425f0((int)puVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    puVar1 = FUN_c0332264(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c0333e70(puVar1,*(uint *)(*(int *)(param_1 + 0x10) + 0x28) >> 2);
    }
    *(int **)(param_1 + 0x70) = piVar3;
    if (piVar3 != (int *)0x0) {
      if (*piVar3 == 0) {
        return 0x57;
      }
      if ((piVar3[1] != 0) && (piVar3[5] != 0)) {
        puVar1 = FUN_c0332264(0x50);
        if (puVar1 == (undefined4 *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = FUN_c0340f44(puVar1,param_1);
        }
        *(int **)(param_1 + 0x18) = piVar3;
        if (piVar3 != (int *)0x0) {
          iVar2 = (**(code **)(*piVar3 + 4))(piVar3);
          if (iVar2 != 0) {
            return iVar2;
          }
          puVar1 = FUN_c0332264(0x34);
          if (puVar1 == (undefined4 *)0x0) {
            puVar1 = (undefined4 *)0x0;
          }
          else {
            puVar1 = FUN_c033f0fc(puVar1,param_1,0);
          }
          *(undefined4 **)(param_1 + 0xc) = puVar1;
          if (puVar1 != (undefined4 *)0x0) {
            iVar2 = FUN_c033f82c((int)puVar1);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = FUN_c0334ac4(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = FUN_c0334bd8(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            local_18[0] = 0;
            iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x28))
                              (*(int **)(param_1 + 0x18),local_18);
            if (iVar2 != 0) {
              return iVar2;
            }
            FUN_c033e708(param_1);
            return 0;
          }
        }
      }
    }
  }
  return 8;
}



/* c033618c FUN_c033618c */

/* Boundary evidence: original MIPS .pdata c033618c..c033626b. Semantic name remains unreviewed. */

undefined4 FUN_c033618c(int param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x8c) = *(undefined4 *)(param_1 + 0x38);
  if ((*(uint *)(*(int *)(param_1 + 0x14) + 0x98) & 1) != 0) {
    *(undefined4 *)(param_2 + 0x88) = 1;
  }
  *(undefined4 *)(param_2 + 0x90) = 0xc;
  if ((*(uint *)(param_1 + 0x6c) & 0x10) != 0) {
    *(undefined4 *)(param_2 + 0x90) = 0xd;
  }
  if ((*(uint *)(param_1 + 0x68) & 0x40000) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) | 2;
  }
  if ((*(uint *)(param_1 + 0x6c) & 0x20) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) | 0x100;
  }
  if ((*(uint *)(param_1 + 0x6c) & 0x1000) != 0) {
    *(uint *)(param_2 + 0x90) = *(uint *)(param_2 + 0x90) | 0x80;
  }
  return 0;
}



/* c033626c FUN_c033626c */

/* Boundary evidence: original MIPS .pdata c033626c..c0336277. Semantic name remains unreviewed. */

undefined4 FUN_c033626c(void)

{
  return 1;
}



/* c0336278 FUN_c0336278 */

/* Boundary evidence: original MIPS .pdata c0336278..c033630b. Semantic name remains unreviewed. */

void FUN_c0336278(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = **(undefined4 **)(param_1 + 0x14);
  local_50 = 0x3c;
  local_4c = 4;
  local_48 = 1;
  local_20 = 0;
  local_1c = 0;
  if ((param_2 & 2) == 0) {
    local_4c = 5;
  }
  iVar1 = FUN_c0334fd4(param_1,0x100);
  if (iVar1 == 0) {
    FSDMGR_ScanVolume(uVar2,&local_50);
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffcff;
  }
  return;
}



/* c033630c FUN_c033630c */

/* Boundary evidence: original MIPS .pdata c033630c..c03364a3. Semantic name remains unreviewed. */

undefined4
FUN_c033630c(int *param_1,int param_2,uint *param_3,uint param_4,int *param_5,uint param_6,
            undefined4 *param_7)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 == 0x70200) || (param_2 == 0x70204)) {
    if (param_6 < 0x168) {
      return 0x57;
    }
    uVar1 = FUN_c0334dc4((int)param_1,param_5);
    if (param_7 == (undefined4 *)0x0) {
      return uVar1;
    }
    uVar3 = 0x168;
  }
  else {
    if (param_2 != 0x70208) {
      if (param_2 == 0x70224) {
        uVar2 = 1;
        if ((3 < param_4) && (param_3 != (uint *)0x0)) {
          uVar2 = *param_3;
        }
        uVar1 = FUN_c0336278((int)param_1,uVar2);
        if (param_7 == (undefined4 *)0x0) {
          return uVar1;
        }
        *param_7 = 0;
        return uVar1;
      }
      if (param_2 == 0x71c80) {
        uVar1 = FUN_c0334eec((int)param_1);
        return uVar1;
      }
      if (param_2 != 0x90084) {
        return 0x57;
      }
      uVar1 = (**(code **)(*param_1 + 0x14))();
      return uVar1;
    }
    if (param_6 < 0x10) {
      return 0x57;
    }
    uVar1 = FUN_c0334cd0((int)param_1,param_5,param_5 + 1,param_5 + 2,param_5 + 3);
    if (param_7 == (undefined4 *)0x0) {
      return uVar1;
    }
    uVar3 = 0x10;
  }
  *param_7 = uVar3;
  return uVar1;
}



/* c03364a4 FUN_c03364a4 */

/* Boundary evidence: original MIPS .pdata c03364a4..c03364af. Semantic name remains unreviewed. */

undefined4 FUN_c03364a4(void)

{
  return 1;
}



/* c03364b0 FUN_c03364b0 */

/* Boundary evidence: original MIPS .pdata c03364b0..c0336537. Semantic name remains unreviewed. */

undefined4 FUN_c03364b0(int param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c034d334;
  uVar2 = 1;
  if ((*(int *)(param_1 + 0x284) != 0) &&
     (iVar1 = FUN_c03393a4(param_2,awStack_220,0x104), iVar1 != 0)) {
    uVar2 = FUN_c03353bc(param_1,awStack_220,param_3);
  }
  FUN_c034b674(local_18);
  return uVar2;
}



/* c0336538 FUN_c0336538 */

/* Boundary evidence: original MIPS .pdata c0336538..c0336703. Semantic name remains unreviewed. */

void FUN_c0336538(int param_1,int *param_2,STRSAFE_PCNZWCH param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined *local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 auStack_2d8 [20];
  undefined4 local_288;
  undefined1 auStack_284 [12];
  wchar_t *local_278;
  undefined4 local_258;
  undefined1 auStack_254 [36];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c034d334;
  if (*(int *)(param_1 + 0x284) != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x288);
    EnterCriticalSection(lpCriticalSection);
    piVar1 = FUN_c033e8e4(*(int **)(param_1 + 0x284),param_3);
    LeaveCriticalSection(lpCriticalSection);
    if ((piVar1 == (int *)0x0) && (piVar1 = FUN_c033efb4(param_3), piVar1 != (int *)0x0)) {
      local_258 = 0;
      memset(auStack_254,0,0x22c);
      local_2e8 = (undefined *)0x0;
      memset(&local_2e4,0,0xc);
      FUN_c033af24(auStack_2d8);
      local_288 = 0;
      memset(auStack_284,0,0x28);
      local_2e8 = &DAT_c0331674;
      local_2e4 = 1;
      do {
        local_278 = awStack_230;
        iVar2 = (**(code **)(*param_2 + 0xc))(param_2,&local_2e8,auStack_2d8,&local_288);
        if (iVar2 != 0) break;
        FUN_c033b008((int)auStack_2d8,&local_258);
        local_2e0 = local_288;
        iVar3 = FUN_c033f04c((int)piVar1,local_278);
        if (iVar3 == 0) {
          iVar2 = 0x1f;
        }
      } while (iVar2 == 0);
      if (iVar2 == 2) {
        EnterCriticalSection(lpCriticalSection);
        piVar4 = FUN_c033e8e4(*(int **)(param_1 + 0x284),param_3);
        if (piVar4 == (int *)0x0) {
          FUN_c033ea98(*(int **)(param_1 + 0x284),piVar1);
          piVar1 = (int *)0x0;
        }
        LeaveCriticalSection(lpCriticalSection);
      }
      if (piVar1 != (int *)0x0) {
        FUN_c03322a0((LPVOID)piVar1[3]);
        FUN_c03322a0((LPVOID)piVar1[4]);
        FUN_c03322a0(piVar1);
      }
    }
  }
  FUN_c034b674(local_28);
  return;
}



/* c0336704 FUN_c0336704 */

/* Boundary evidence: original MIPS .pdata c0336704..c0336773. Semantic name remains unreviewed. */

void FUN_c0336704(undefined4 *param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = (LPVOID)param_1[0xa7];
  *param_1 = &PTR_FUN_c0331678;
  if (pvVar1 != (LPVOID)0x0) {
    FUN_c03400cc((int)pvVar1);
    FUN_c03322a0(pvVar1);
  }
  pvVar1 = (LPVOID)param_1[0xa8];
  if (pvVar1 != (LPVOID)0x0) {
    FUN_c034050c((int)pvVar1);
    FUN_c03322a0(pvVar1);
  }
  FUN_c0335adc(param_1);
  return;
}



/* c0336774 FUN_c0336774 */

/* Boundary evidence: original MIPS .pdata c0336774..c0336a3f. Semantic name remains unreviewed. */

int FUN_c0336774(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  LPVOID pvVar4;
  
  puVar1 = FUN_c0332264(0x44);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c0342440(puVar1,param_1);
  }
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_c03425f0((int)puVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    puVar1 = FUN_c0332264(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_c0333e70(puVar1,*(uint *)(*(int *)(param_1 + 0x10) + 0x28) >> 2);
    }
    *(int **)(param_1 + 0x70) = piVar3;
    if (piVar3 != (int *)0x0) {
      if (*piVar3 == 0) {
        return 0x57;
      }
      if ((piVar3[1] != 0) && (piVar3[5] != 0)) {
        puVar1 = FUN_c0332264(0x34);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = FUN_c033f0fc(puVar1,param_1,1);
        }
        *(undefined4 **)(param_1 + 0xc) = puVar1;
        if (puVar1 != (undefined4 *)0x0) {
          iVar2 = FUN_c033f82c((int)puVar1);
          if (iVar2 != 0) {
            return iVar2;
          }
          if ((*(uint *)(param_1 + 0x6c) & 0x10) == 0) {
            puVar1 = FUN_c0332264(0x58);
            if (puVar1 == (undefined4 *)0x0) {
              puVar1 = (undefined4 *)0x0;
            }
            else {
              puVar1 = FUN_c0342f54(puVar1,param_1);
            }
            *(undefined4 **)(param_1 + 0x18) = puVar1;
            if (puVar1 == (undefined4 *)0x0) {
              return 8;
            }
            iVar2 = FUN_c0334ac4(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 4))();
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = FUN_c0335740(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar2 = FUN_c0334bd8(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
            FUN_c033e708(param_1);
          }
          else {
            iVar2 = FUN_c033d294(param_1);
            if (iVar2 != 0) {
              return iVar2;
            }
          }
          puVar1 = FUN_c0332264(8);
          if (puVar1 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_c03400bc(puVar1,param_1);
          }
          if (piVar3 != (int *)0x0) {
            iVar2 = FUN_c0340294(piVar3);
            *(int **)(param_1 + 0x29c) = piVar3;
            if (iVar2 != 0) {
              return iVar2;
            }
            piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 0x28);
            if (piVar3 == (int *)0x0) {
              return 0x1f;
            }
            iVar2 = (**(code **)(*piVar3 + 0x28))();
            if (iVar2 != 0) {
              return iVar2;
            }
            if ((*(uint *)(param_1 + 0x68) & 0x80) == 0) {
              return 0;
            }
            puVar1 = FUN_c0332264(0x24);
            if (puVar1 == (undefined4 *)0x0) {
              piVar3 = (int *)0x0;
            }
            else {
              piVar3 = FUN_c03404d0(puVar1,param_1);
            }
            *(int **)(param_1 + 0x2a0) = piVar3;
            if (piVar3 != (int *)0x0) {
              iVar2 = FUN_c0340dd8(piVar3);
              if (iVar2 == 0x546) {
                FUN_c0340548(*(int **)(param_1 + 0x2a0));
                pvVar4 = *(LPVOID *)(param_1 + 0x2a0);
                if (pvVar4 != (LPVOID)0x0) {
                  FUN_c034050c((int)pvVar4);
                  FUN_c03322a0(pvVar4);
                }
                *(undefined4 *)(param_1 + 0x2a0) = 0;
                return 0;
              }
              if (iVar2 == 0) {
                *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 0x1000;
                return 0;
              }
              return iVar2;
            }
          }
        }
      }
    }
  }
  return 8;
}



/* c0336a40 FUN_c0336a40 */

/* Boundary evidence: original MIPS .pdata c0336a40..c0336bc7. Semantic name remains unreviewed. */

int FUN_c0336a40(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  SIZE_T SVar4;
  
  *param_4 = 0;
  SVar4 = param_2[2];
  piVar1 = FUN_c0332264(SVar4);
  if (piVar1 == (int *)0x0) {
    return 8;
  }
  iVar2 = FUN_c033b5fc(param_2,1,0,1,piVar1);
  if (iVar2 != 0) goto LAB_c0336ae0;
  if (*piVar1 == -0x5e4d3c2c) {
    *param_4 = 1;
LAB_c0336adc:
    iVar2 = 0xb;
  }
  else {
    iVar2 = FUN_c0334118(param_1,(char *)piVar1,SVar4);
    if (iVar2 == 0) {
      iVar2 = FUN_c03342b4(param_1,(char *)piVar1,SVar4);
      if (iVar2 == 0) goto LAB_c0336adc;
      puVar3 = FUN_c0332264(0x29c);
      if (puVar3 == (undefined4 *)0x0) goto LAB_c0336bac;
      puVar3 = FUN_c0334438(puVar3,param_2,piVar1);
    }
    else {
      puVar3 = FUN_c0332264(0x2a4);
      if (puVar3 == (undefined4 *)0x0) {
LAB_c0336bac:
        puVar3 = (undefined4 *)0x0;
      }
      else {
        FUN_c0334438(puVar3,param_2,piVar1);
        *puVar3 = &PTR_FUN_c0331678;
        puVar3[0xa7] = 0;
        puVar3[0xa8] = 0;
      }
    }
    if (puVar3 != (undefined4 *)0x0) {
      *param_3 = puVar3;
      return 0;
    }
    iVar2 = 8;
  }
LAB_c0336ae0:
  FUN_c03322a0(piVar1);
  return iVar2;
}



/* c0336bc8 FUN_c0336bc8 */

/* Boundary evidence: original MIPS .pdata c0336bc8..c0336c13. Semantic name remains unreviewed. */

undefined4 * FUN_c0336bc8(undefined4 *param_1,uint param_2)

{
  FUN_c0335adc(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0336c14 FUN_c0336c14 */

/* Boundary evidence: original MIPS .pdata c0336c14..c0336d3f. Semantic name remains unreviewed. */

DWORD FUN_c0336c14(int *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  DWORD DVar3;
  
  if ((*(uint *)(param_1[5] + 0x18) & 4) == 0) {
    DVar3 = (**(code **)(*param_1 + 0x3c))(param_1);
    if ((DVar3 == 0) && (DVar3 = FUN_c033453c((int)param_1), DVar3 == 0)) {
      if (((param_1[0x1a] & 4U) == 0) ||
         (((param_1[0x1b] & 0x2000U) != 0 && ((param_1[0x1a] & 0x2000000U) != 0)))) {
        DVar3 = FUN_c0336278((int)param_1,0);
        if (DVar3 != 0) {
          return DVar3;
        }
        param_1[0x1b] = param_1[0x1b] & 0xffffdfff;
      }
      DVar3 = (**(code **)(*param_1 + 0xc))(param_1);
      if ((DVar3 == 0) && (DVar3 = FUN_c0334860((int)param_1), DVar3 == 0)) {
        pvVar1 = FUN_c0332264(0x20);
        if (pvVar1 == (LPVOID)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = FUN_c033e8bc((int)pvVar1);
        }
        param_1[0xa1] = iVar2;
      }
    }
  }
  else {
    DVar3 = 0xb;
  }
  return DVar3;
}



/* c0336d40 FUN_c0336d40 */

/* Boundary evidence: original MIPS .pdata c0336d40..c0336d8b. Semantic name remains unreviewed. */

undefined4 * FUN_c0336d40(undefined4 *param_1,uint param_2)

{
  FUN_c0336704(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0336d8c FUN_c0336d8c */

/* Boundary evidence: original MIPS .pdata c0336d8c..c0336fcb. Semantic name remains unreviewed. */

int FUN_c0336d8c(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *local_28;
  uint local_24;
  
  piVar4 = (int *)0x0;
  piVar5 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (param_2 == 0) {
    iVar3 = 0x57;
  }
  else {
    piVar4 = (int *)FUN_c0333ec4(param_1,param_2);
    local_28 = piVar4;
    if (piVar4 == (int *)0x0) {
      puVar1 = FUN_c0332264(0x9c);
      if (puVar1 == (undefined4 *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = FUN_c033b094(puVar1,param_2);
      }
      if (piVar5 == (int *)0x0) {
        iVar3 = 8;
      }
      else {
        iVar3 = FUN_c033b134(piVar5);
        if (iVar3 == 0) {
          local_24 = 0;
          iVar3 = FUN_c0336a40(param_1,piVar5,&local_28,&local_24);
          piVar4 = local_28;
          if ((iVar3 != 0) || (iVar3 = (**(code **)(*local_28 + 4))(local_28), iVar3 == 0)) {
            if (iVar3 == 0xb) {
              if (local_24 == 0) {
                local_24 = 0x40;
                iVar2 = FSDMGR_GetRegistryValue(param_2,L"Flags",&local_24);
                if (iVar2 == 0) {
                  FSDMGR_GetRegistryFlag(param_2,L"DisableAutoFormat",&local_24,0x40);
                }
                if ((local_24 & 0x40) != 0) goto LAB_c0336f54;
              }
              iVar3 = FUN_c03340bc(param_1,param_2);
              if (iVar3 != 0) goto LAB_c0336f54;
              iVar3 = FUN_c0336a40(param_1,piVar5,&local_28,&local_24);
              piVar4 = local_28;
              if ((iVar3 != 0) || (iVar3 = (**(code **)(*local_28 + 4))(local_28), iVar3 != 0))
              goto LAB_c0336f54;
            }
            if (iVar3 == 0) {
              FUN_c0333bec(param_1,(int)piVar4);
            }
          }
        }
      }
    }
    else {
      iVar3 = 0xb7;
    }
  }
LAB_c0336f54:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if (iVar3 != 0) {
    if (piVar4 == (int *)0x0) {
      if (piVar5 != (int *)0x0) {
        FUN_c033b0d4((int)piVar5);
        FUN_c03322a0(piVar5);
      }
    }
    else {
      (**(code **)*piVar4)(piVar4,1);
    }
  }
  return iVar3;
}



/* c0336fcc FUN_c0336fcc */

undefined4 *
FUN_c0336fcc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  param_1[6] = param_5;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[5] = param_4;
  param_1[8] = param_7;
  param_1[9] = param_8;
  *param_1 = &PTR_FUN_c0331740;
  return param_1;
}



/* c033700c FUN_c033700c */

/* Boundary evidence: original MIPS .pdata c033700c..c03375db. Semantic name remains unreviewed. */

int FUN_c033700c(int *param_1,undefined4 param_2,wchar_t *param_3,uint param_4,uint param_5,
                int param_6,int param_7,uint param_8,int *param_9)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *local_3c;
  uint local_38;
  wchar_t *local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  
  *param_9 = -1;
  iVar6 = 0;
  puVar7 = (undefined4 *)0x0;
  local_3c = (int *)0x0;
  bVar1 = false;
  local_38 = 0;
  local_34 = param_3;
  local_2c = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  uVar8 = 4;
  iVar2 = (**(code **)(*param_1 + 0x34))(param_1,4,0);
  if (((param_4 & 0x3fffffff) != 0) || ((param_8 & 0x58) != 0)) {
    iVar6 = 0x57;
    bVar1 = false;
    goto LAB_c0337150;
  }
  local_30 = (undefined4 *)(param_8 & 0x7f | 0x20);
  if ((param_5 & 0xfffffffc) != 0) {
    iVar6 = 0x57;
    bVar1 = false;
    goto LAB_c0337150;
  }
  if (param_7 == 1) {
    uVar8 = 0x74;
  }
  else if (param_7 == 2) {
    uVar8 = 100;
  }
  else if (param_7 != 3) {
    if (param_7 == 4) {
      uVar8 = 0x24;
    }
    else {
      if (param_7 != 5) {
        iVar6 = 0x57;
        goto LAB_c0337150;
      }
      if ((param_4 & 0x40000000) == 0) {
        iVar6 = 5;
        goto LAB_c0337150;
      }
      uVar8 = 0x44;
    }
  }
  if (((((param_1[0x1a] & 0x100U) == 0) && ((param_4 & 0x40000000) != 0)) || ((uVar8 & 0x60) != 0))
     || ((param_8 & 0x2000000) == 0)) {
    uVar8 = uVar8 | 1;
  }
  uVar3 = FUN_c03352c8((int)param_1);
  if (((uVar3 == 0) && ((param_1[0x1b] & 0x100U) == 0)) ||
     (((uVar8 & 0x60) == 0 && ((param_4 & 0x40000000) == 0)))) {
    if (iVar2 != 0) {
      uVar8 = uVar8 & 0xffffffdf;
    }
    puVar7 = FUN_c0332264(0x28);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7[1] = 0;
      puVar7[2] = 0;
      *puVar7 = &PTR_FUN_c033173c;
      puVar7[3] = param_1;
      puVar7[4] = 0;
      puVar7[5] = param_4;
      puVar7[6] = param_5;
      puVar7[8] = 0;
      puVar7[9] = 0;
    }
    if (puVar7 == (undefined4 *)0x0) {
      iVar6 = 0xe;
      goto LAB_c0337150;
    }
    iVar4 = _wcsicmp(local_34,L"\\VOL:");
    if (iVar4 != 0) {
      iVar6 = FUN_c033fe48(param_1[3],local_34,uVar8,(uint)local_30,param_6,&local_3c,&local_38);
      if (iVar6 != 0) {
        if (((iVar2 != 0) && (param_7 != 3)) &&
           ((param_7 != 5 && (bVar1 = false, (local_38 & 0x100) == 0)))) {
          iVar6 = 0x70;
        }
        goto LAB_c0337150;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(local_3c + 0x28));
      if ((local_38 & 0x100) != 0) {
        uVar3 = local_3c[0x13];
        if (uVar3 == 0) {
          uVar3 = 0;
        }
        if (((uVar3 & 1) != 0) && ((param_4 & 0x40000000) != 0)) goto LAB_c03373d0;
      }
      iVar6 = FUN_c0338d58((int)local_3c,param_4,param_5,uVar8 & 0x40);
      if (iVar6 != 0) goto LAB_c0337150;
      puVar7[4] = local_3c;
      if ((local_38 & 0x100) == 0) {
        FUN_c033e7c8((int)param_1,0x25,(int)local_3c,uVar8,0,1);
      }
    }
    iVar2 = FSDMGR_CreateFileHandle(param_1[0xa0],local_2c,puVar7);
    if (iVar2 == 0) {
      iVar6 = 0xe;
    }
    else {
      if (local_3c != (int *)0x0) {
        puVar5 = puVar7;
        FUN_c0333bec((int)(local_3c + 6),(int)puVar7);
        iVar6 = 0;
        bVar1 = true;
        if (((param_8 & 0x80000000) != 0) || ((param_1[0x1a] & 0x20U) != 0)) {
          local_3c[0x27] = local_3c[0x27] | 1;
        }
        if (((param_8 & 0x20000000) != 0) || ((param_1[0x1a] & 0x200U) != 0)) {
          local_3c[0x27] = local_3c[0x27] | 4;
        }
        if (((param_1[0x1b] & 0x10U) != 0) && ((param_1[0x1a] & 0x40000U) != 0)) {
          local_3c[0x27] = local_3c[0x27] | 2;
        }
        if ((param_7 == 2) && ((local_38 & 0x100) != 0)) {
          puVar5 = local_30;
          FUN_c0338a5c((int)local_3c,(int)local_30);
        }
        if ((uVar8 & 0x40) != 0) {
          local_3c[0x27] = local_3c[0x27] | 0x200;
          iVar6 = FUN_c033ada0((int)local_3c,puVar5,0,0);
          if (iVar6 != 0) goto LAB_c0337150;
        }
      }
      *param_9 = iVar2;
    }
  }
  else {
LAB_c03373d0:
    iVar6 = 5;
  }
LAB_c0337150:
  (**(code **)(*param_1 + 0x38))(param_1);
  if (local_3c != (int *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_3c + 0x28));
  }
  if (iVar6 == 0) {
    if ((local_38 & 0x100) != 0) {
      SetLastError(0xb7);
    }
  }
  else {
    if (puVar7 != (undefined4 *)0x0) {
      if (bVar1) {
        FUN_c0333c6c((int)(local_3c + 6),(int)puVar7);
      }
      (**(code **)*puVar7)(puVar7,1);
    }
    if (local_3c != (int *)0x0) {
      FUN_c033f954(param_1[3],local_3c,(uint)((local_38 & 0x100) == 0));
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  return iVar6;
}



/* c03375dc FUN_c03375dc */

/* Boundary evidence: original MIPS .pdata c03375dc..c033769b. Semantic name remains unreviewed. */

int FUN_c03375dc(int *param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_2[4];
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    if (param_3 != 0) {
      (**(code **)(*param_1 + 0x34))(param_1,2,1);
      iVar2 = FUN_c033a618((int)piVar1,0,0);
      (**(code **)(*param_1 + 0x38))(param_1);
    }
    FUN_c0333c6c((int)(piVar1 + 6),(int)param_2);
    FUN_c033f954(param_1[3],piVar1,0);
  }
  (**(code **)*param_2)(param_2,1);
  return iVar2;
}



/* c033769c FUN_c033769c */

/* Boundary evidence: original MIPS .pdata c033769c..c0337993. Semantic name remains unreviewed. */

int FUN_c033769c(int param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3,undefined4 *param_4,
                int *param_5)

{
  int iVar1;
  STRSAFE_PCNZWCH pszSrc;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  STRSAFE_LPWSTR pszDest;
  int **ppiVar5;
  int *local_d0;
  undefined4 *local_cc;
  int local_c8;
  undefined4 local_c4;
  int local_c0;
  int *local_bc;
  STRSAFE_LPWSTR local_b8;
  undefined4 local_b4 [3];
  undefined4 auStack_a8 [20];
  undefined4 local_58;
  undefined1 auStack_54 [12];
  undefined4 *local_48;
  uint local_2c;
  
  local_2c = DAT_c034d334;
  local_bc = param_5;
  local_d0 = (int *)0x0;
  local_b8 = (STRSAFE_LPWSTR)0x0;
  local_c8 = param_1;
  local_c4 = param_2;
  memset(local_b4,0,0xc);
  FUN_c033af24(auStack_a8);
  local_58 = 0;
  memset(auStack_54,0,0x28);
  puVar4 = (undefined4 *)0x0;
  ppiVar5 = &local_d0;
  iVar1 = FUN_c033fe48(*(int *)(param_1 + 0xc),param_3,0x202,0,0,ppiVar5,(uint *)0x0);
  if (iVar1 == 0) {
    puVar4 = FUN_c0332264(0x230);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = FUN_c0336fcc(puVar4,param_1,local_d0,0x80000000,3,ppiVar5,0,0);
    }
    local_cc = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      iVar1 = 8;
    }
    else {
      pszDest = (STRSAFE_LPWSTR)(puVar4 + 10);
      pszSrc = FUN_c033b8f0(param_3);
      HVar2 = StringCchCopyW(pszDest,0x104,pszSrc);
      if (HVar2 < 0) {
        iVar1 = 0x1f;
      }
      else {
        local_b4[0] = 1;
        local_b8 = pszDest;
        iVar1 = wcscmp(pszDest,L"*.*");
        if (iVar1 == 0) {
          *(undefined2 *)((int)puVar4 + 0x2a) = 0;
        }
        local_48 = param_4 + 10;
        iVar1 = (**(code **)(*local_d0 + 0xc))(local_d0,&local_b8,auStack_a8,&local_58);
        local_c0 = iVar1;
        if (iVar1 == 0) {
          FUN_c033b008((int)auStack_a8,param_4);
          puVar4[8] = local_58;
          puVar4[9] = 0;
          iVar3 = FSDMGR_CreateFileHandle(*(undefined4 *)(param_1 + 0x280),param_2,puVar4);
          if (iVar3 == 0) {
            iVar1 = 0xe;
            goto LAB_c0337908;
          }
          FUN_c0333bec((int)(local_d0 + 6),(int)puVar4);
          iVar1 = 0;
          *param_5 = iVar3;
        }
        if (iVar1 == 0) goto LAB_c0337944;
      }
    }
  }
LAB_c0337908:
  if (local_d0 != (int *)0x0) {
    FUN_c033f954(*(int *)(param_1 + 0xc),local_d0,0);
  }
  if (puVar4 != (undefined4 *)0x0) {
    (**(code **)*puVar4)(puVar4,1);
  }
LAB_c0337944:
  FUN_c034b674(local_2c);
  return iVar1;
}



/* c0337994 FUN_c0337994 */

/* Boundary evidence: original MIPS .pdata c0337994..c033799f. Semantic name remains unreviewed. */

undefined4 FUN_c0337994(void)

{
  return 1;
}



/* c03379a0 FUN_c03379a0 */

/* Boundary evidence: original MIPS .pdata c03379a0..c0337aef. Semantic name remains unreviewed. */

int FUN_c03379a0(int *param_1,STRSAFE_LPCWSTR param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *local_28;
  uint local_24;
  
  local_28 = (int *)0x0;
  uVar4 = 0x32;
  iVar3 = 5;
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,5,0);
  if (iVar1 != 0) {
    uVar4 = 0x12;
  }
  uVar2 = FUN_c03352c8((int)param_1);
  if (uVar2 == 0) {
    local_24 = 0;
    iVar3 = FUN_c033fe48(param_1[3],param_2,uVar4,0x10,param_3,&local_28,&local_24);
    if (iVar3 == 0) {
      FUN_c033e7c8((int)param_1,0x27,(int)local_28,0,0,1);
      iVar3 = (**(code **)(*param_1 + 0x28))(param_1,0);
    }
    else if ((iVar1 != 0) && ((local_24 & 0x100) == 0)) {
      iVar3 = 0x70;
    }
  }
  (**(code **)(*param_1 + 0x38))(param_1);
  if (local_28 != (int *)0x0) {
    FUN_c033f954(param_1[3],local_28,0);
  }
  return iVar3;
}



/* c0337af0 FUN_c0337af0 */

/* Boundary evidence: original MIPS .pdata c0337af0..c0337d43. Semantic name remains unreviewed. */

int FUN_c0337af0(int *param_1,STRSAFE_LPCWSTR param_2)

{
  int iVar1;
  uint uVar2;
  int *local_b8;
  undefined4 local_b4;
  uint local_b0 [2];
  undefined4 *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 auStack_98 [20];
  undefined4 local_48;
  undefined1 auStack_44 [40];
  uint local_1c;
  
  local_1c = DAT_c034d334;
  local_b8 = (int *)0x0;
  FUN_c033af24(auStack_98);
  local_48 = 0;
  memset(auStack_44,0,0x28);
  local_a8 = (undefined4 *)0x0;
  memset(&local_a4,0,0xc);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,2,1);
  if (iVar1 == 0) {
    uVar2 = FUN_c03352c8((int)param_1);
    if (uVar2 == 0) {
      local_b0[0] = 0;
      iVar1 = FUN_c033fe48(param_1[3],param_2,2,0x10,0,&local_b8,local_b0);
      if (iVar1 != 0) goto LAB_c0337ce0;
      if (local_b8[5] != 0) {
        uVar2 = local_b8[0x13];
        if (uVar2 == 0) {
          uVar2 = 0;
        }
        if ((uVar2 & 1) == 0) {
          if ((local_b8[0xe] == 0) && ((uint)local_b8[0x24] < 2)) {
            local_a8 = &local_b4;
            local_b4 = 0x2a;
            local_a4 = 1;
            local_a0 = 0;
            iVar1 = (**(code **)(*local_b8 + 0xc))(local_b8,&local_a8,auStack_98,&local_48);
            if (iVar1 == 0) {
              iVar1 = 0x91;
            }
            else {
              iVar1 = (**(code **)(*(int *)local_b8[5] + 0x18))
                                ((int *)local_b8[5],local_b8 + 0x10,1);
              if (iVar1 == 0) {
                FUN_c033e7c8((int)param_1,0x28,(int)local_b8,0,0,1);
                iVar1 = FUN_c033f954(param_1[3],local_b8,1);
                local_b8 = (int *)0x0;
                if (iVar1 == 0) {
                  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,0);
                }
              }
            }
          }
          else {
            iVar1 = 0x20;
          }
          goto LAB_c0337ce0;
        }
      }
    }
    iVar1 = 5;
  }
LAB_c0337ce0:
  (**(code **)(*param_1 + 0x38))(param_1);
  if ((iVar1 != 0) && (local_b8 != (int *)0x0)) {
    FUN_c033f954(param_1[3],local_b8,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  FUN_c034b674(local_1c);
  return iVar1;
}



/* c0337d44 FUN_c0337d44 */

/* Boundary evidence: original MIPS .pdata c0337d44..c0337ddb. Semantic name remains unreviewed. */

int FUN_c0337d44(int param_1,STRSAFE_LPCWSTR param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *local_18;
  uint local_14;
  
  local_18 = (int *)0x0;
  local_14 = 0;
  iVar1 = FUN_c033fe48(*(int *)(param_1 + 0xc),param_2,0,0,0,&local_18,&local_14);
  if (iVar1 == 0) {
    iVar2 = local_18[0x13];
    if (iVar2 == 0) {
      iVar2 = 0x80;
    }
    *param_3 = iVar2;
  }
  if (local_18 != (int *)0x0) {
    FUN_c033f954(*(int *)(param_1 + 0xc),local_18,0);
  }
  return iVar1;
}



/* c0337ddc FUN_c0337ddc */

/* Boundary evidence: original MIPS .pdata c0337ddc..c0337f0b. Semantic name remains unreviewed. */

int FUN_c0337ddc(int *param_1,STRSAFE_LPCWSTR param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *local_20;
  uint local_1c;
  
  local_20 = (int *)0x0;
  local_1c = 0;
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,2,0);
  if (iVar1 != 0) goto LAB_c0337ec4;
  uVar2 = FUN_c03352c8((int)param_1);
  if (uVar2 == 0) {
    iVar1 = FUN_c033fe48(param_1[3],param_2,0,0,0,&local_20,&local_1c);
    if (iVar1 != 0) goto LAB_c0337ec4;
    uVar2 = param_3 & 0x27;
    if ((local_20[0x13] & 0x10U) != 0) {
      if (local_20[5] == 0) goto LAB_c0337e90;
      uVar2 = uVar2 | 0x10;
    }
    iVar1 = FUN_c0338a5c((int)local_20,uVar2);
    if (iVar1 == 0) {
      iVar1 = FUN_c033a618((int)local_20,0,0);
    }
  }
  else {
LAB_c0337e90:
    iVar1 = 5;
  }
LAB_c0337ec4:
  (**(code **)(*param_1 + 0x38))(param_1);
  if (local_20 != (int *)0x0) {
    FUN_c033f954(param_1[3],local_20,0);
  }
  return iVar1;
}



/* c0337f0c FUN_c0337f0c */

/* Boundary evidence: original MIPS .pdata c0337f0c..c03380f7. Semantic name remains unreviewed. */

int FUN_c0337f0c(int *param_1,STRSAFE_LPCWSTR param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *local_20;
  uint local_1c;
  
  local_20 = (int *)0x0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  if ((param_3 == 0) || (iVar1 = (**(code **)(*param_1 + 0x34))(param_1,2,1), iVar1 == 0)) {
    uVar2 = FUN_c03352c8((int)param_1);
    if (uVar2 == 0) {
      local_1c = 0;
      iVar1 = FUN_c033fe48(param_1[3],param_2,1,0,0,&local_20,&local_1c);
      if (iVar1 == 0) {
        uVar2 = local_20[0x13];
        if (uVar2 == 0) {
          uVar2 = 0;
        }
        if ((uVar2 & 0x11) == 0) {
          if ((local_20[0xe] == 0) && ((uint)local_20[0x24] < 2)) {
            iVar1 = (**(code **)(*(int *)local_20[5] + 0x18))((int *)local_20[5],local_20 + 0x10,1);
            if (iVar1 == 0) {
              FUN_c033e7c8((int)param_1,0x26,(int)local_20,0,0,1);
              iVar1 = FUN_c033f954(param_1[3],local_20,1);
              local_20 = (int *)0x0;
              if (iVar1 == 0) {
                if (param_3 == 0) goto LAB_c0337fc0;
                iVar1 = (**(code **)(*param_1 + 0x28))(param_1,0);
              }
            }
          }
          else {
            iVar1 = 0x20;
          }
        }
        else {
          iVar1 = 5;
        }
      }
    }
    else {
      iVar1 = 5;
    }
  }
  if (param_3 != 0) {
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  if ((iVar1 != 0) && (local_20 != (int *)0x0)) {
    FUN_c033f954(param_1[3],local_20,0);
  }
LAB_c0337fc0:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  return iVar1;
}



/* c03380f8 FUN_c03380f8 */

/* Boundary evidence: original MIPS .pdata c03380f8..c03386d7. Semantic name remains unreviewed. */

int FUN_c03380f8(int *param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *local_2e0;
  int *local_2dc;
  int *local_2d8;
  uint local_2d4;
  size_t local_2d0 [2];
  STRSAFE_PCNZWCH local_2c8;
  undefined4 local_2c4 [2];
  uint local_2bc;
  undefined4 auStack_2b8 [20];
  undefined4 local_268;
  undefined1 auStack_264 [44];
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c034d334;
  local_2e0 = (int *)0x0;
  local_2d8 = (int *)0x0;
  piVar6 = (int *)0x0;
  local_2dc = (int *)0x0;
  FUN_c033af24(auStack_2b8);
  local_2c8 = (STRSAFE_PCNZWCH)0x0;
  memset(local_2c4,0,0xc);
  local_268 = 0;
  memset(auStack_264,0,0x28);
  local_2d0[0] = 0;
  local_238[0] = L'\0';
  bVar1 = false;
  bVar2 = FUN_c033520c(param_1,param_2,param_3);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    FUN_c034b674(local_30);
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  iVar3 = (**(code **)(*param_1 + 0x34))(param_1,6,0);
  if (iVar3 != 0) goto LAB_c03385a0;
  uVar4 = FUN_c03352c8((int)param_1);
  if (uVar4 != 0) {
LAB_c0338434:
    iVar3 = 5;
    goto LAB_c03385a0;
  }
  local_2d4 = 0;
  iVar3 = FUN_c033fe48(param_1[3],param_2,0,0,0,&local_2e0,&local_2d4);
  if (iVar3 != 0) goto LAB_c03385a0;
  EnterCriticalSection((LPCRITICAL_SECTION)(local_2e0 + 0x28));
  piVar6 = (int *)local_2e0[5];
  if (piVar6 == (int *)0x0) goto LAB_c0338434;
  EnterCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0x28));
  iVar3 = FUN_c0338e28((int)local_2e0);
  if (iVar3 != 0) {
    iVar3 = 0x20;
    goto LAB_c03385a0;
  }
  iVar3 = FUN_c033fe48(param_1[3],param_3,0x202,0,0,&local_2dc,&local_2d4);
  if (iVar3 != 0) goto LAB_c03385a0;
  EnterCriticalSection((LPCRITICAL_SECTION)(local_2dc + 0x28));
  if ((param_1[0x1b] & 0x10U) != 0) {
    if (local_2dc[5] != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(local_2dc[5] + 0xa0));
    }
    FUN_c03410b8(param_1[6]);
    bVar1 = true;
  }
  FUN_c033e7c8((int)param_1,0x29,(int)local_2e0,param_4,0,0);
  if (param_4 == 0) {
    iVar3 = FUN_c033fe48(param_1[3],param_3,0,0,0,&local_2d8,&local_2d4);
    if (iVar3 == 0) {
      if (local_2e0 != local_2d8) {
        FUN_c033f954(param_1[3],local_2d8,0);
        iVar3 = 0xb7;
        goto LAB_c03385a0;
      }
      iVar3 = (**(code **)(*local_2dc + 0x18))(local_2dc,local_2d8 + 0x10);
      FUN_c033f954(param_1[3],local_2d8,0);
      goto LAB_c03383a4;
    }
  }
  else {
    if ((local_2e0[0x13] & 0x10U) != 0) goto LAB_c0338434;
    iVar3 = FUN_c0337f0c(param_1,param_3,0);
LAB_c03383a4:
    if (iVar3 != 0) goto LAB_c03385a0;
  }
  piVar7 = local_2dc;
  if ((local_2e0[0x13] & 0x10U) != 0) {
    for (; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[5]) {
      if (local_2e0 == piVar7) goto LAB_c0338434;
    }
  }
  piVar7 = local_2e0 + 0x10;
  local_2c8 = FUN_c033b8f0(param_3);
  local_2c4[0] = 4;
  local_2bc = FUN_c033b060(piVar7);
  iVar3 = (**(code **)(*local_2dc + 0xc))(local_2dc,&local_2c8,0,&local_268);
  if (iVar3 == 2) {
    memcpy(auStack_2b8,piVar7,0x50);
    iVar3 = (**(code **)(*local_2dc + 0x10))(local_2dc,&local_268,auStack_2b8);
    if ((iVar3 == 0) &&
       (iVar3 = (**(code **)(*local_2dc + 0x14))
                          (local_2dc,local_2c8,&local_268,piVar7,piVar6[4],auStack_2b8), iVar3 == 0)
       ) {
      if ((local_2e0 == local_2d8) ||
         (iVar3 = (**(code **)(*piVar6 + 0x18))(piVar6,local_2e0 + 0x10,0), iVar3 == 0)) {
        memcpy(local_2e0 + 0x10,auStack_2b8,0x50);
        FUN_c0338f7c((int)local_2e0,(int)local_2dc);
        if ((((local_2e0[0x13] & 0x10U) == 0) || ((param_1[0x1b] & 0x20U) != 0)) ||
           (iVar3 = (**(code **)(*local_2e0 + 0x24))(), iVar3 == 0)) {
          StringCchLengthW(local_2c8,0x104,local_2d0);
          (**(code **)(*param_1 + 0x24))(param_1,local_2c8,local_2d0[0],local_238);
          iVar3 = (**(code **)(*param_1 + 0x28))(param_1,0);
        }
      }
      else {
        (**(code **)(*local_2dc + 0x18))(local_2dc,auStack_2b8,0);
      }
    }
  }
  else {
    iVar3 = 0x1f;
  }
LAB_c03385a0:
  (**(code **)(*param_1 + 0x38))(param_1);
  if (((bVar1) && (FUN_c03410d4((int *)param_1[6]), local_2dc != (int *)0x0)) && (local_2dc[5] != 0)
     ) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_2dc[5] + 0xa0));
  }
  if (piVar6 != (int *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar6 + 0x28));
  }
  if (local_2dc != (int *)0x0) {
    if ((iVar3 == 0) && (iVar5 = FUN_c03364b0((int)param_1,(int)local_2dc,local_238), iVar5 == 0)) {
      FUN_c033544c((int)param_1,(int)local_2dc);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_2dc + 0x28));
    FUN_c033f954(param_1[3],local_2dc,0);
  }
  if (local_2e0 != (int *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(local_2e0 + 0x28));
    if (iVar3 == 0) {
      FUN_c0338ea8((int)local_2e0,local_238);
      FUN_c033e7c8((int)param_1,0x29,(int)local_2e0,param_4,1,1);
    }
    FUN_c033f954(param_1[3],local_2e0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[3] + 0xc));
  FUN_c034b674(local_30);
  return iVar3;
}



/* c03386d8 FUN_c03386d8 */

/* Boundary evidence: original MIPS .pdata c03386d8..c03386ff. Semantic name remains unreviewed. */

void FUN_c03386d8(int *param_1,STRSAFE_LPCWSTR param_2,STRSAFE_LPCWSTR param_3)

{
  FUN_c03380f8(param_1,param_3,param_2,1);
  return;
}



/* c0338708 FUN_c0338708 */

/* Boundary evidence: original MIPS .pdata c0338708..c033873f. Semantic name remains unreviewed. */

undefined4 FUN_c0338708(int param_1,int param_2,void *param_3,uint param_4,uint *param_5)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2a0) == 0) {
    uVar1 = 0x32;
  }
  else {
    uVar1 = FUN_c034057c(*(int *)(param_1 + 0x2a0),param_2,param_3,param_4,param_5);
  }
  return uVar1;
}



/* c0338740 FUN_c0338740 */

/* Boundary evidence: original MIPS .pdata c0338740..c0338773. Semantic name remains unreviewed. */

int FUN_c0338740(int param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x2a0) == (int *)0x0) {
    iVar1 = 0x32;
  }
  else {
    iVar1 = FUN_c034091c(*(int **)(param_1 + 0x2a0),param_2,param_3,param_4);
  }
  return iVar1;
}



/* c0338774 FUN_c0338774 */

/* Boundary evidence: original MIPS .pdata c0338774..c03387b7. Semantic name remains unreviewed. */

undefined4 * FUN_c0338774(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c033161c;
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03387b8 FUN_c03387b8 */

/* Boundary evidence: original MIPS .pdata c03387b8..c03387fb. Semantic name remains unreviewed. */

undefined4 * FUN_c03387b8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c033161c;
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03387fc FUN_c03387fc */

/* Boundary evidence: original MIPS .pdata c03387fc..c0338863. Semantic name remains unreviewed. */

void FUN_c03387fc(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (param_5 != 0) {
    uVar1 = *(int *)(param_1 + 0x38) - 1;
    param_3 = uVar1 + param_3;
    param_4 = param_4 + (uint)(param_3 < uVar1);
  }
  uVar2 = __ull_rshift(param_3,param_4,*(undefined1 *)(param_1 + 0x34));
  __ull_rshift((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),*(undefined1 *)(param_1 + 0x35));
  return;
}



/* c0338864 FUN_c0338864 */

/* Boundary evidence: original MIPS .pdata c0338864..c03388af. Semantic name remains unreviewed. */

undefined4 * FUN_c0338864(undefined4 *param_1,uint param_2)

{
  FUN_c0333d90(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03388b0 FUN_c03388b0 */

/* Boundary evidence: original MIPS .pdata c03388b0..c033892b. Semantic name remains unreviewed. */

void FUN_c03388b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[4];
  *param_1 = &PTR_FUN_c03317c4;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[4] = 0;
  }
  if ((LPVOID)param_1[0x25] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[0x25]);
    param_1[0x25] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  FUN_c0333d90(param_1 + 6);
  *param_1 = &PTR_FUN_c033161c;
  return;
}



/* c0338968 FUN_c0338968 */

/* Boundary evidence: original MIPS .pdata c0338968..c0338a4f. Semantic name remains unreviewed. */

undefined4 FUN_c0338968(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x58);
    param_2[1] = *(undefined4 *)(param_1 + 0x5c);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x60);
    param_3[1] = *(undefined4 *)(param_1 + 100);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x68);
    param_4[1] = *(undefined4 *)(param_1 + 0x6c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return 0;
}



/* c0338a50 FUN_c0338a50 */

/* Boundary evidence: original MIPS .pdata c0338a50..c0338a5b. Semantic name remains unreviewed. */

undefined4 FUN_c0338a50(void)

{
  return 1;
}



/* c0338a5c FUN_c0338a5c */

/* Boundary evidence: original MIPS .pdata c0338a5c..c0338ac3. Semantic name remains unreviewed. */

undefined4 FUN_c0338a5c(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x4c) != param_2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
    *(int *)(param_1 + 0x4c) = param_2;
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x4100;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  }
  return 0;
}



/* c0338ac4 FUN_c0338ac4 */

undefined8 FUN_c0338ac4(int param_1)

{
  return *(undefined8 *)(*(int *)(*(int *)(param_1 + 0x10) + 0x14) + 8);
}



/* c0338ad8 FUN_c0338ad8 */

void FUN_c0338ad8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  puVar1 = *(uint **)(iVar2 + 0x14);
  *puVar1 = *puVar1 & 0xfffffffb;
  iVar2 = *(int *)(iVar2 + 0x14);
  *(undefined4 *)(iVar2 + 8) = param_3;
  *(undefined4 *)(iVar2 + 0xc) = param_4;
  return;
}



/* c0338b04 FUN_c0338b04 */

bool FUN_c0338b04(int param_1)

{
  return (*(uint *)(param_1 + 0x78) & 4) != 0;
}



/* c0338b20 FUN_c0338b20 */

void FUN_c0338b20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x88) = param_3;
  *(undefined4 *)(param_1 + 0x8c) = param_4;
  return;
}



/* c0338b2c FUN_c0338b2c */

/* Boundary evidence: original MIPS .pdata c0338b2c..c0338b47. Semantic name remains unreviewed. */

void FUN_c0338b2c(int param_1,int param_2)

{
  FUN_c03443d4(*(int *)(param_1 + 0x10),param_2);
  return;
}



/* c0338b48 FUN_c0338b48 */

/* Boundary evidence: original MIPS .pdata c0338b48..c0338d57. Semantic name remains unreviewed. */

int FUN_c0338b48(int param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = *(int *)(param_1 + 0x10);
  uVar6 = *(uint *)(*(int *)(iVar2 + 0x14) + 8);
  uVar7 = *(uint *)(*(int *)(iVar2 + 0x14) + 0xc);
  if ((uVar6 != param_3) || (uVar7 != param_4)) {
    uVar3 = *(uint *)(param_1 + 0x9c);
    *(uint *)(param_1 + 0x9c) = uVar3 | 0x200;
    uVar1 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
    uVar4 = uVar1 + uVar6;
    uVar5 = uVar1 + param_3;
    if (((uVar4 - 1 & ~(uVar1 - 1)) == (uVar5 - 1 & ~(uVar1 - 1))) &&
       ((uVar7 + (uVar4 < uVar1) + -1 + (uint)(uVar4 - 1 < uVar4) & ~((uVar1 - 1 < uVar1) - 1)) ==
        (param_4 + (uVar5 < uVar1) + -1 + (uint)(uVar5 - 1 < uVar5) & ~((uVar1 - 1 < uVar1) - 1))))
    {
      **(uint **)(iVar2 + 0x14) = **(uint **)(iVar2 + 0x14) & 0xfffffffb;
      iVar2 = *(int *)(iVar2 + 0x14);
      *(uint *)(iVar2 + 8) = param_3;
      *(uint *)(iVar2 + 0xc) = param_4;
    }
    else {
      *(uint *)(param_1 + 0x9c) = uVar3 | 0x1200;
      iVar2 = FUN_c0344634(iVar2,param_2,param_3,param_4);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
    uVar1 = *(uint *)(iVar2 + 0xc);
    uVar3 = *(uint *)(iVar2 + 8);
    if ((uVar1 <= *(uint *)(param_1 + 0x8c)) &&
       ((uVar1 != *(uint *)(param_1 + 0x8c) || (uVar3 < *(uint *)(param_1 + 0x88))))) {
      *(uint *)(param_1 + 0x8c) = uVar1;
      *(uint *)(param_1 + 0x88) = uVar3;
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x400;
    }
    if ((((*(uint *)(param_1 + 0x9c) & 4) != 0) && (uVar7 <= param_4)) &&
       ((param_4 != uVar7 || (uVar6 < param_3)))) {
      FUN_c0345bc8(*(int *)(param_1 + 0x10),param_2,uVar6,uVar7,param_3 - uVar6,
                   (param_4 - uVar7) - (uint)(param_3 < uVar6));
    }
    FUN_c033e7c8(*(int *)(param_1 + 0xc),0x2a,param_1,uVar6,param_3,1);
  }
  return 0;
}



/* c0338d58 FUN_c0338d58 */

/* Boundary evidence: original MIPS .pdata c0338d58..c0338e27. Semantic name remains unreviewed. */

undefined4 FUN_c0338d58(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = (uint)((param_2 & 0x80000000) != 0);
  if ((param_4 != 0) || ((param_2 & 0x40000000) != 0)) {
    uVar2 = uVar2 | 2;
  }
  if ((param_3 & 1) == 0) {
    uVar3 = 0x80000000;
  }
  if ((param_3 & 2) == 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  iVar1 = FUN_c0333ba4(param_1 + 0x18);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (((*(uint *)(iVar1 + 0x18) & uVar2) != uVar2) || ((*(uint *)(iVar1 + 0x14) & uVar3) != 0))
    break;
    iVar1 = FUN_c0333bc8(param_1 + 0x18,iVar1);
  }
  return 0x20;
}



/* c0338e28 FUN_c0338e28 */

/* Boundary evidence: original MIPS .pdata c0338e28..c0338ea7. Semantic name remains unreviewed. */

undefined4 FUN_c0338e28(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0333ba4(param_1 + 0x18);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if ((((*(uint *)(iVar1 + 0x18) & 1) == 0) || ((*(uint *)(iVar1 + 0x14) & 0x40000000) != 0)) &&
       ((*(uint *)(iVar1 + 0x18) & 2) == 0)) break;
    iVar1 = FUN_c0333bc8(param_1 + 0x18,iVar1);
  }
  return 1;
}



/* c0338ea8 FUN_c0338ea8 */

/* Boundary evidence: original MIPS .pdata c0338ea8..c0338f7b. Semantic name remains unreviewed. */

undefined4 FUN_c0338ea8(int param_1,STRSAFE_PCNZWCH param_2)

{
  HRESULT HVar1;
  STRSAFE_LPWSTR pszDest;
  SIZE_T SVar2;
  undefined4 uVar3;
  size_t local_18 [2];
  
  uVar3 = 0x1f;
  local_18[0] = 0;
  if (*(LPVOID *)(param_1 + 0x94) != (LPVOID)0x0) {
    FUN_c03322a0(*(LPVOID *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  HVar1 = StringCchLengthW(param_2,0x104,local_18);
  if (-1 < HVar1) {
    *(size_t *)(param_1 + 0x98) = local_18[0];
    if (local_18[0] + 1 < 0x80000000) {
      SVar2 = (local_18[0] + 1) * 2;
    }
    else {
      SVar2 = 0xffffffff;
    }
    pszDest = FUN_c0332264(SVar2);
    *(STRSAFE_LPWSTR *)(param_1 + 0x94) = pszDest;
    if (pszDest == (STRSAFE_LPWSTR)0x0) {
      uVar3 = 8;
    }
    else {
      HVar1 = StringCchCopyW(pszDest,*(int *)(param_1 + 0x98) + 1,param_2);
      if (-1 < HVar1) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



/* c0338f7c FUN_c0338f7c */

/* Boundary evidence: original MIPS .pdata c0338f7c..c0338feb. Semantic name remains unreviewed. */

void FUN_c0338f7c(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 8))();
  }
  *(int *)(param_1 + 0x14) = param_2;
  *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + 1;
  if ((*(uint *)(param_1 + 0x4c) & 0x10) != 0) {
    FUN_c033544c(*(int *)(param_1 + 0xc),param_1);
  }
  return;
}



/* c0338fec FUN_c0338fec */

/* Boundary evidence: original MIPS .pdata c0338fec..c03392a7. Semantic name remains unreviewed. */

DWORD FUN_c0338fec(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  SIZE_T SVar6;
  uint *puVar7;
  DWORD DVar8;
  undefined4 *puVar9;
  
  puVar5 = (undefined4 *)0x0;
  if ((*(int *)(param_2 + 8) == 0) && (*(int *)(param_2 + 0xc) != 0)) {
    DVar4 = 0x57;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
    if (*(int *)(iVar2 + 8) == 0 && *(int *)(iVar2 + 0xc) == 0) {
      DVar4 = 0x26;
    }
    else {
      iVar2 = param_2;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
      uVar1 = FUN_c0344228(*(int *)(param_1 + 0x10),iVar2);
      SVar6 = (uVar1 + 0x45) * 8;
      if (uVar1 == 0) {
        trap(0x1c00);
      }
      if ((SVar6 - 0x228) / uVar1 == 8) {
        puVar5 = FUN_c0332264(SVar6);
        if (puVar5 == (undefined4 *)0x0) {
          DVar4 = 0xe;
        }
        else {
          *puVar5 = 0x228;
          puVar5[1] = *(undefined4 *)(param_2 + 4);
          puVar5[2] = *(undefined4 *)(param_2 + 8);
          puVar5[3] = *(undefined4 *)(param_2 + 0xc);
          puVar9 = puVar5;
          wcscpy_s((wchar_t *)(puVar5 + 4),0x104,(wchar_t *)(param_2 + 0x10));
          puVar5[0x88] = 0;
          puVar5[0x89] = uVar1 << 3;
          iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
          uVar3 = *(undefined4 *)(iVar2 + 0xc);
          puVar5[0x86] = *(undefined4 *)(iVar2 + 8);
          puVar5[0x87] = uVar3;
          puVar7 = puVar5 + 0x8a;
          DVar4 = FUN_c0344ea0(*(int *)(param_1 + 0x10),puVar7);
          if (DVar4 == 0) {
            DVar8 = DVar4;
            if (*(int *)(param_2 + 4) == 1) {
              FUN_c033b528(*(int *)(*(int *)(param_1 + 0xc) + 0x14),puVar7,uVar1,0);
            }
            else {
              FUN_c033b598(*(int *)(*(int *)(param_1 + 0xc) + 0x14),puVar7,uVar1);
            }
            iVar2 = FSDMGR_DiskIoControl
                              (**(undefined4 **)(*(int *)(param_1 + 0xc) + 0x14),0x71c58,puVar5,
                               SVar6,param_3,param_4,0,0,DVar8,puVar9);
            if (iVar2 == 0) {
              DVar4 = GetLastError();
            }
          }
        }
      }
      else {
        DVar4 = 0x57;
      }
      if (puVar5 != (undefined4 *)0x0) {
        FUN_c03322a0(puVar5);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
    }
  }
  return DVar4;
}



/* c03392a8 FUN_c03392a8 */

/* Boundary evidence: original MIPS .pdata c03392a8..c03392b3. Semantic name remains unreviewed. */

undefined4 FUN_c03392a8(void)

{
  return 1;
}



/* c03392b4 FUN_c03392b4 */

/* Boundary evidence: original MIPS .pdata c03392b4..c03393a3. Semantic name remains unreviewed. */

undefined4 FUN_c03392b4(int param_1)

{
  _FILETIME local_38;
  _FILETIME _Stack_30;
  SYSTEMTIME SStack_28;
  _SYSTEMTIME _Stack_18;
  
  GetLocalTime(&_Stack_18);
  if (((*(uint *)(*(int *)(param_1 + 0xc) + 0x68) & 1) != 0) &&
     ((*(uint *)(param_1 + 0x9c) & 0x20) == 0)) {
    memcpy(&SStack_28,&_Stack_18,0x10);
    SStack_28.wMilliseconds = 0;
    SStack_28.wSecond = 0;
    SStack_28.wMinute = 0;
    SStack_28.wHour = 0;
    SStack_28.wDayOfWeek = 0;
    SystemTimeToFileTime(&SStack_28,&_Stack_30);
    LocalFileTimeToFileTime(&_Stack_30,&local_38);
    if ((*(DWORD *)(param_1 + 0x60) != local_38.dwLowDateTime) ||
       (*(DWORD *)(param_1 + 100) != local_38.dwHighDateTime)) {
      *(DWORD *)(param_1 + 100) = local_38.dwHighDateTime;
      *(DWORD *)(param_1 + 0x60) = local_38.dwLowDateTime;
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x120;
    }
  }
  if (((*(uint *)(param_1 + 0x9c) & 0x800) != 0) && ((*(uint *)(param_1 + 0x9c) & 0x40) == 0)) {
    SystemTimeToFileTime(&_Stack_18,&_Stack_30);
    LocalFileTimeToFileTime(&_Stack_30,(LPFILETIME)(param_1 + 0x68));
  }
  return 0;
}



/* c03393a4 FUN_c03393a4 */

/* Boundary evidence: original MIPS .pdata c03393a4..c03394d3. Semantic name remains unreviewed. */

undefined4 FUN_c03393a4(int param_1,undefined2 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  iVar3 = 1;
  for (iVar2 = *(int *)(param_1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
    if (*(int *)(iVar2 + 0x98) != 0) {
      iVar3 = iVar3 + *(int *)(iVar2 + 0x98) + 1;
    }
  }
  iVar3 = *(int *)(param_1 + 0x98) + iVar3;
  if (iVar3 + 1U <= param_3) {
    *param_2 = 0x5c;
    iVar5 = iVar3 - *(int *)(param_1 + 0x98);
    for (iVar2 = *(int *)(param_1 + 0x14); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x14)) {
      iVar4 = *(int *)(iVar2 + 0x98);
      if (iVar4 != 0) {
        iVar5 = (iVar5 - iVar4) + -1;
        memcpy(param_2 + iVar5,*(void **)(iVar2 + 0x94),iVar4 << 1);
        param_2[iVar5 + iVar4] = 0x5c;
      }
    }
    iVar2 = *(int *)(param_1 + 0x98);
    param_2[iVar3 - iVar2] = 0;
    if (*(int *)(param_1 + 0x98) != 0) {
      memcpy(param_2 + (iVar3 - iVar2),*(void **)(param_1 + 0x94),(*(int *)(param_1 + 0x98) + 1) * 2
            );
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c03394d4 FUN_c03394d4 */

/* Boundary evidence: original MIPS .pdata c03394d4..c033957b. Semantic name remains unreviewed. */

undefined4 * FUN_c03394d4(undefined4 *param_1,undefined4 param_2,void *param_3,undefined4 param_4)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_c03317c4;
  param_1[3] = param_2;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_c0333b60(param_1 + 6);
  param_1[6] = &PTR_FUN_c03317c0;
  memcpy(param_1 + 0x10,param_3,0x50);
  param_1[0x24] = 1;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = param_4;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  return param_1;
}



/* c033957c FUN_c033957c */

/* Boundary evidence: original MIPS .pdata c033957c..c03395c7. Semantic name remains unreviewed. */

undefined4 * FUN_c033957c(undefined4 *param_1,uint param_2)

{
  FUN_c03388b0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03395c8 FUN_c03395c8 */

/* Boundary evidence: original MIPS .pdata c03395c8..c0339697. Semantic name remains unreviewed. */

int FUN_c03395c8(int param_1,int param_2,STRSAFE_PCNZWCH param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x14) = param_2;
  if (param_2 != 0) {
    *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + 1;
  }
  puVar1 = FUN_c0332264(0x90);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c0343ce0(puVar1,*(int *)(param_1 + 0xc),(uint *)(param_1 + 0x78));
  }
  *(undefined4 **)(param_1 + 0x10) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = 8;
  }
  else {
    iVar2 = FUN_c0338ea8(param_1,param_3);
    if (iVar2 == 0) {
      return 0;
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(LPVOID *)(param_1 + 0x94) != (LPVOID)0x0) {
    FUN_c03322a0(*(LPVOID *)(param_1 + 0x94));
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  return iVar2;
}



/* c0339698 FUN_c0339698 */

/* Boundary evidence: original MIPS .pdata c0339698..c03397b7. Semantic name remains unreviewed. */

undefined4 FUN_c0339698(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
  uVar2 = *(undefined4 *)(iVar1 + 8);
  uVar3 = *(undefined4 *)(iVar1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 0x4c);
  param_2[1] = *(undefined4 *)(param_1 + 0x58);
  param_2[2] = *(undefined4 *)(param_1 + 0x5c);
  param_2[3] = *(undefined4 *)(param_1 + 0x60);
  param_2[4] = *(undefined4 *)(param_1 + 100);
  param_2[5] = *(undefined4 *)(param_1 + 0x68);
  param_2[6] = *(undefined4 *)(param_1 + 0x6c);
  param_2[7] = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x24);
  param_2[8] = uVar3;
  param_2[9] = uVar2;
  param_2[10] = 1;
  if (*(int *)(param_1 + 0x14) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x7c);
  }
  param_2[0xb] = uVar2;
  param_2[0xc] = *(undefined4 *)(param_1 + 0x40);
  param_2[0xd] = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return 0;
}



/* c03397b8 FUN_c03397b8 */

/* Boundary evidence: original MIPS .pdata c03397b8..c03397c3. Semantic name remains unreviewed. */

undefined4 FUN_c03397b8(void)

{
  return 1;
}



/* c03397c4 FUN_c03397c4 */

/* Boundary evidence: original MIPS .pdata c03397c4..c033980b. Semantic name remains unreviewed. */

void FUN_c03397c4(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_c03442a0(*(int *)(param_1 + 0x10),param_2);
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(iVar1 + 0xc);
  }
  return;
}



/* c033980c FUN_c033980c */

/* Boundary evidence: original MIPS .pdata c033980c..c03399d7. Semantic name remains unreviewed. */

void FUN_c033980c(int param_1,int param_2,uint *param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,undefined4 param_8)

{
  if (param_2 == 0x90034) {
    if (((param_3 != (uint *)0x0) && (3 < param_4)) && ((*param_3 & 1) != 0)) {
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 2;
    }
  }
  else if (param_2 == 0x9004c) {
    if ((param_3 != (uint *)0x0) && (0x217 < param_4)) {
      FUN_c0338fec(param_1,(int)param_3,param_5,param_6);
    }
  }
  else if (param_2 == 0x90050) {
    FSDMGR_DiskIoControl
              (**(undefined4 **)(*(int *)(param_1 + 0xc) + 0x14),0x71c5c,param_3,param_4,param_5,
               param_6,param_7,param_8);
  }
  else if (param_2 == 0x900a8) {
    if ((param_3 == (uint *)0x0) || (param_4 == 0)) {
      if (param_7 != 0) {
        (**(code **)(**(int **)(param_1 + 0xc) + 0x18))
                  (*(int **)(param_1 + 0xc),param_1,param_5,param_6,param_7);
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))(*(int **)(param_1 + 0xc),param_1,param_3);
    }
  }
  return;
}



/* c03399d8 FUN_c03399d8 */

/* Boundary evidence: original MIPS .pdata c03399d8..c03399e3. Semantic name remains unreviewed. */

undefined4 FUN_c03399d8(void)

{
  return 1;
}



/* c03399e4 FUN_c03399e4 */

/* Boundary evidence: original MIPS .pdata c03399e4..c0339b6b. Semantic name remains unreviewed. */

int FUN_c03399e4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  
  if ((*(int *)(param_1 + 0x14) == 0) ||
     ((uVar4 = *(uint *)(param_1 + 0x9c), (uVar4 & 8) != 0 && ((uVar4 & 0x100) == 0)))) {
    iVar1 = 0;
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & 0xffff808f;
  }
  else {
    if ((uVar4 & 0x7600) != 0) {
      *(uint *)(param_1 + 0x9c) = uVar4 | 0x20000;
    }
    iVar1 = FUN_c03392b4(param_1);
    if ((iVar1 == 0) && ((*(uint *)(param_1 + 0x9c) & 0x7f00) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
      uVar4 = *(uint *)(param_1 + 0x9c);
      uVar2 = 0;
      bVar3 = (uVar4 & 0x1600) != 0;
      if ((uVar4 & 0x2000) != 0) {
        bVar3 = bVar3 | 2;
        uVar2 = 2;
      }
      if (((uVar4 & 0x1000) != 0) || ((*(uint *)(*(int *)(param_1 + 0xc) + 0x68) & 0x80000) != 0)) {
        uVar2 = 2;
      }
      if (((uVar4 & 0x400) != 0) &&
         (((*(uint *)(*(int *)(param_1 + 0xc) + 0x68) & 0x4000000) != 0 ||
          ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x1000) != 0)))) {
        uVar2 = 2;
      }
      iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 0x1c))
                        (*(int **)(param_1 + 0x14),param_1 + 0x40,uVar2,bVar3);
      if (iVar1 == 0) {
        *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & 0xffff808f;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
    }
  }
  return iVar1;
}



/* c0339b6c FUN_c0339b6c */

/* Boundary evidence: original MIPS .pdata c0339b6c..c0339d4b. Semantic name remains unreviewed. */

int FUN_c0339b6c(int param_1,void *param_2,uint param_3,uint param_4,void *param_5,uint param_6,
                int *param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar1 = 0;
  if ((param_5 == (void *)0x0) && (param_6 != 0)) {
    iVar1 = 0x57;
  }
  else {
    uVar8 = 0;
    if ((*(uint *)(param_1 + 0x9c) & 4) != 0) {
      uVar8 = 8;
    }
    if (((*(uint *)(param_1 + 0x78) & 4) == 0) ||
       (iVar1 = FUN_c03397c4(param_1,param_2), iVar1 == 0)) {
      uVar7 = param_6 + param_3;
      uVar2 = *(uint *)(param_1 + 0x8c);
      uVar6 = param_4 + (uVar7 < param_6);
      uVar3 = *(uint *)(param_1 + 0x88);
      if ((param_4 < uVar2) || ((param_4 == uVar2 && (param_3 < uVar3)))) {
        uVar5 = param_6;
        if ((uVar2 <= uVar6) && ((uVar6 != uVar2 || (uVar3 < uVar7)))) {
          uVar5 = uVar3 - param_3;
        }
        if (uVar5 != 0) {
          iVar1 = FUN_c034522c(*(int *)(param_1 + 0x10),param_2,param_3,param_4,param_5,uVar5,uVar8,
                               param_7);
        }
      }
      else {
        uVar5 = 0;
      }
      if (((iVar1 == 0) && (uVar5 < param_6)) && (param_6 - uVar5 <= param_6)) {
        iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
        uVar8 = *(uint *)(iVar4 + 0xc);
        uVar2 = *(uint *)(iVar4 + 8);
        if ((uVar8 <= uVar6) && ((uVar6 != uVar8 || (uVar2 <= uVar7)))) {
          uVar6 = uVar8;
          uVar7 = uVar2;
        }
        uVar8 = param_4 + (uVar5 + param_3 < uVar5);
        if ((uVar8 <= uVar6) && ((uVar8 != uVar6 || (uVar5 + param_3 < uVar7)))) {
          *param_7 = ((uVar7 - param_3) - uVar5) + *param_7;
        }
      }
    }
  }
  return iVar1;
}



/* c0339d4c FUN_c0339d4c */

/* Boundary evidence: original MIPS .pdata c0339d4c..c033a12f. Semantic name remains unreviewed. */

int FUN_c0339d4c(uint *param_1,uint *param_2,uint param_3,uint param_4,void *param_5,uint param_6,
                int *param_7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  local_38 = 0;
  iVar4 = 0;
  bVar1 = false;
  if (((*(uint *)(param_1[3] + 0x6c) & 0x10) != 0) && (param_1[5] != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1[5] + 0xa0));
  }
  uVar2 = FUN_c03352c8(param_1[3]);
  if (uVar2 != 0) {
    iVar4 = 0x13;
    goto LAB_c033a0d8;
  }
  if ((param_5 == (void *)0x0) && (param_6 != 0)) {
    iVar4 = 0x57;
    goto LAB_c033a0d8;
  }
  if (((param_1[0x1e] & 4) != 0) && (iVar4 = FUN_c03397c4((int)param_1,param_2), iVar4 != 0))
  goto LAB_c033a0d8;
  if (param_6 == 0) {
    param_1[0x27] = param_1[0x27] & 0xffffffbf | 0x800;
    goto LAB_c033a0d8;
  }
  if (((*(uint *)(param_1[3] + 0x6c) & 0x10) == 0) || ((param_1[0x27] & 2) == 0)) {
LAB_c0339e94:
    uVar2 = 0;
    if ((param_1[0x27] & 1) != 0) {
      uVar2 = 4;
    }
    if ((param_1[0x27] & 4) != 0) {
      uVar2 = uVar2 | 8;
    }
    uVar5 = param_6 + param_3;
    uVar3 = *(uint *)(*(int *)(param_1[4] + 0x14) + 0xc);
    uVar8 = param_4 + (uVar5 < param_6);
    uVar7 = param_1[0x22];
    uVar6 = param_1[0x23];
    local_34 = uVar5;
    if ((uVar8 < uVar3) ||
       ((uVar8 == uVar3 && (uVar5 <= *(uint *)(*(int *)(param_1[4] + 0x14) + 8))))) {
LAB_c0339f50:
      if (((((*(uint *)(param_1[3] + 0x68) & 0x4000000) != 0) ||
           ((*(uint *)(param_1[3] + 0x6c) & 0x1000) != 0)) && (uVar6 <= param_4)) &&
         ((uVar6 != param_4 || (uVar7 < param_3)))) {
        local_30 = 0;
        local_2c = 0;
        iVar4 = FUN_c0345a80(param_1[4],param_2,uVar7,uVar6,param_3 - uVar7,
                             (param_4 - uVar6) - (uint)(param_3 < uVar7),uVar2,&local_30);
        if (iVar4 != 0) goto LAB_c033a0c0;
        uVar7 = local_30 + uVar7;
        uVar6 = local_2c + uVar6 + (uint)(uVar7 < local_30);
      }
      iVar4 = FUN_c0345604(param_1[4],param_2,param_3,param_4,param_5,param_6,uVar2,&local_38);
      if (iVar4 == 0) {
        *param_7 = *param_7 + local_38;
        uVar2 = param_1[0x27];
        param_1[0x27] = uVar2 & 0xffffffbf | 0x800;
        if ((uVar6 <= uVar8) && ((uVar6 != uVar8 || (uVar7 < local_34)))) {
          uVar6 = uVar8;
          uVar7 = local_34;
        }
        if ((uVar7 != param_1[0x22]) || (uVar6 != param_1[0x23])) {
          param_1[0x27] = uVar2 & 0xffffffbf | 0xc00;
          param_1[0x22] = uVar7;
          param_1[0x23] = uVar6;
        }
        if ((param_1[0x27] & 0x3600) != 0) {
          iVar4 = FUN_c03399e4((int)param_1);
        }
      }
    }
    else {
      if ((!bVar1) && ((*(uint *)(param_1[3] + 0x6c) & 0x10) != 0)) {
        FUN_c03410b8(*(int *)(param_1[3] + 0x18));
        bVar1 = true;
      }
      iVar4 = FUN_c0338b48((int)param_1,param_2,uVar5,uVar8);
      if (iVar4 == 0) goto LAB_c0339f50;
    }
LAB_c033a0c0:
    if (!bVar1) goto LAB_c033a0d8;
  }
  else {
    FUN_c03410b8(*(int *)(param_1[3] + 0x18));
    bVar1 = true;
    param_2 = param_1;
    iVar4 = (**(code **)(*(int *)param_1[3] + 0x30))
                      ((int *)param_1[3],param_1,param_3,param_4,param_6);
    if (iVar4 == 0) goto LAB_c0339e94;
  }
  FUN_c03410d4(*(int **)(param_1[3] + 0x18));
LAB_c033a0d8:
  if (((*(uint *)(param_1[3] + 0x6c) & 0x10) != 0) && (param_1[5] != 0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[5] + 0xa0));
  }
  return iVar4;
}



/* c033a130 FUN_c033a130 */

/* Boundary evidence: original MIPS .pdata c033a130..c033a2b3. Semantic name remains unreviewed. */

int FUN_c033a130(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  
  iVar7 = 0;
  if ((param_5 == 0) ||
     (((*(uint *)(param_1 + 0x78) & 4) != 0 && (iVar1 = FUN_c03397c4(param_1,param_2), iVar1 != 0)))
     ) {
    iVar7 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (((*(uint *)(iVar1 + 0x6c) & 0x10) == 0) || ((*(uint *)(param_1 + 0x9c) & 2) == 0)) {
      uVar6 = param_5 + param_3;
      iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
      uVar2 = *(uint *)(iVar3 + 0xc);
      uVar5 = param_4 + (uint)(uVar6 < param_5);
      uVar4 = *(uint *)(iVar3 + 8);
      if ((uVar2 <= uVar5) && ((uVar5 != uVar2 || (uVar4 < uVar6)))) {
        iVar3 = FUN_c03387fc(iVar1,param_2,uVar4,uVar2,1);
        iVar7 = FUN_c03387fc(iVar1,param_2,uVar6,uVar5,1);
        iVar7 = iVar7 - iVar3;
      }
    }
    else {
      uVar4 = param_5 + param_3;
      uVar8 = __ull_rshift(uVar4 - 1,
                           param_4 + (uint)(uVar4 < param_5) + -1 + (uint)(uVar4 - 1 < uVar4),
                           *(undefined1 *)(iVar1 + 0x34));
      iVar7 = __ull_rshift((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),*(undefined1 *)(iVar1 + 0x35))
      ;
      uVar8 = __ull_rshift(param_3,param_4,*(undefined1 *)(iVar1 + 0x34));
      iVar1 = __ull_rshift((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),*(undefined1 *)(iVar1 + 0x35))
      ;
      iVar7 = (iVar7 - iVar1) + 1;
    }
    iVar7 = iVar7 + 2;
  }
  return iVar7;
}



/* c033a2b4 FUN_c033a2b4 */

/* Boundary evidence: original MIPS .pdata c033a2b4..c033a3af. Semantic name remains unreviewed. */

int FUN_c033a2b4(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  *param_5 = 0;
  iVar2 = 0;
  if (((*(uint *)(param_1 + 0x78) & 4) == 0) || (iVar1 = FUN_c03397c4(param_1,param_2), iVar1 == 0))
  {
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
    uVar3 = *(uint *)(iVar1 + 0xc);
    uVar4 = *(uint *)(iVar1 + 8);
    if ((param_4 < uVar3) || ((param_4 == uVar3 && (param_3 <= uVar4)))) {
      *param_5 = 1;
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
      iVar2 = FUN_c03387fc(iVar1,param_2,param_3,param_4,1);
      iVar1 = FUN_c03387fc(iVar1,param_2,uVar4,uVar3,1);
      iVar2 = iVar2 - iVar1;
    }
    iVar2 = iVar2 + 2;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* c033a3b0 FUN_c033a3b0 */

/* Boundary evidence: original MIPS .pdata c033a3b0..c033a433. Semantic name remains unreviewed. */

int FUN_c033a3b0(int param_1,undefined4 param_2,uint param_3,uint param_4,void *param_5,uint param_6
                ,void *param_7)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  iVar1 = FUN_c0339b6c(param_1,param_7,param_3,param_4,param_5,param_6,param_7);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar1;
}



/* c033a434 FUN_c033a434 */

/* Boundary evidence: original MIPS .pdata c033a434..c033a60b. Semantic name remains unreviewed. */

int FUN_c033a434(int param_1,void *param_2,uint param_3,int param_4,uint param_5,uint param_6)

{
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_58;
  int local_54;
  _SYSTEM_INFO _Stack_50;
  
  iVar5 = 0;
  pvVar1 = param_2;
  GetSystemInfo(&_Stack_50);
  if (param_3 != 0) {
    if (_Stack_50.dwPageSize == 0) {
      trap(0x1c00);
    }
    if (param_3 % _Stack_50.dwPageSize == 0) {
      uVar7 = param_3 / _Stack_50.dwPageSize;
      if (_Stack_50.dwPageSize == 0) {
        trap(0x1c00);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
      uVar6 = 0;
      do {
        if (uVar7 <= uVar6) {
LAB_c033a598:
          LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
          return iVar5;
        }
        uVar2 = param_5;
        uVar3 = param_6;
        if (param_4 != 0) {
          puVar4 = (uint *)(uVar6 * 8 + param_4);
          uVar2 = *puVar4;
          uVar3 = puVar4[1];
        }
        local_58 = 0;
        iVar5 = FUN_c0339b6c(param_1,pvVar1,uVar2,uVar3,*(void **)(uVar6 * 8 + (int)param_2),
                             _Stack_50.dwPageSize,(int *)&local_58);
        local_54 = iVar5;
        if (iVar5 != 0) goto LAB_c033a598;
        if (local_58 != _Stack_50.dwPageSize) {
          iVar5 = 0x26;
          local_54 = 0x26;
          goto LAB_c033a598;
        }
        if (param_4 == 0) {
          param_5 = local_58 + param_5;
          param_6 = param_6 + (param_5 < local_58);
        }
        uVar6 = uVar6 + 1;
      } while( true );
    }
  }
  return 0x57;
}



/* c033a60c FUN_c033a60c */

/* Boundary evidence: original MIPS .pdata c033a60c..c033a617. Semantic name remains unreviewed. */

undefined4 FUN_c033a60c(void)

{
  return 1;
}



/* c033a618 FUN_c033a618 */

/* Boundary evidence: original MIPS .pdata c033a618..c033a7ef. Semantic name remains unreviewed. */

int FUN_c033a618(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xa0);
  EnterCriticalSection(lpCriticalSection);
  iVar2 = FUN_c03443d4(*(int *)(param_1 + 0x10),(uint)((*(uint *)(param_1 + 0x9c) & 1) != 0));
  if (iVar2 == 0) {
    iVar2 = FUN_c03399e4(param_1);
    bVar1 = (*(uint *)(param_1 + 0x9c) & 0x20000) != 0;
    if (((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) != 0) && (param_2 != 0)) {
      bVar1 = false;
    }
    if (bVar1) {
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) & 0xfffdffff;
    }
    LeaveCriticalSection(lpCriticalSection);
    if (iVar2 == 0) {
      piVar4 = *(int **)(param_1 + 0xc);
      if (((piVar4[0x1b] & 0x10U) != 0) && (bVar1)) {
        iVar2 = (**(code **)(*piVar4 + 0x28))(piVar4,param_3);
      }
      if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) == 0) {
        if (*(int *)(param_1 + 0x14) != 0) {
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
          iVar3 = FUN_c03443d4(*(int *)(*(int *)(param_1 + 0x14) + 0x10),
                               (uint)((*(uint *)(param_1 + 0x9c) & 1) != 0));
          LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
          iVar2 = 0;
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        if (bVar1) {
          piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
          iVar2 = (**(code **)(*piVar4 + 0x30))(piVar4,(*(uint *)(param_1 + 0x9c) & 1) != 0);
        }
      }
    }
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar2;
}



/* c033a7f0 FUN_c033a7f0 */

/* Boundary evidence: original MIPS .pdata c033a7f0..c033a94f. Semantic name remains unreviewed. */

int FUN_c033a7f0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x58) = *param_2;
    *(undefined4 *)(param_1 + 0x5c) = param_2[1];
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x110;
  }
  if (param_3 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x60) = *param_3;
    *(undefined4 *)(param_1 + 100) = param_3[1];
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x120;
  }
  if (param_4 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x68) = *param_4;
    *(undefined4 *)(param_1 + 0x6c) = param_4[1];
    *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 0x140;
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))(*(int **)(param_1 + 0xc),2,0);
  if (iVar1 == 0) {
    iVar1 = FUN_c03399e4(param_1);
    (**(code **)(**(int **)(param_1 + 0xc) + 0x38))();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar1;
}



/* c033a950 FUN_c033a950 */

/* Boundary evidence: original MIPS .pdata c033a950..c033a95b. Semantic name remains unreviewed. */

undefined4 FUN_c033a950(void)

{
  return 1;
}



/* c033a95c FUN_c033a95c */

/* Boundary evidence: original MIPS .pdata c033a95c..c033aa67. Semantic name remains unreviewed. */

int FUN_c033a95c(uint *param_1,undefined4 param_2,uint param_3,uint param_4,void *param_5,
                uint param_6,int *param_7)

{
  uint *puVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  puVar1 = (uint *)FUN_c033a130((int)param_1,param_2,param_3,param_4,param_6);
  iVar2 = (**(code **)(*(int *)param_1[3] + 0x34))((int *)param_1[3],puVar1,0);
  if (iVar2 == 0) {
    iVar2 = FUN_c0339d4c(param_1,puVar1,param_3,param_4,param_5,param_6,param_7);
    if ((iVar2 == 0) && ((param_1[0x27] & 1) != 0)) {
      iVar2 = FUN_c033a618((int)param_1,0,1);
    }
  }
  (**(code **)(*(int *)param_1[3] + 0x38))();
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
  return iVar2;
}



/* c033aa68 FUN_c033aa68 */

/* Boundary evidence: original MIPS .pdata c033aa68..c033ad93. Semantic name remains unreviewed. */

int FUN_c033aa68(uint *param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_60;
  int local_5c;
  int local_58;
  uint local_54;
  _SYSTEM_INFO _Stack_50;
  
  local_58 = param_2;
  GetSystemInfo(&_Stack_50);
  if (param_3 != 0) {
    if (_Stack_50.dwPageSize == 0) {
      trap(0x1c00);
    }
    if (param_3 % _Stack_50.dwPageSize == 0) {
      uVar5 = param_3 / _Stack_50.dwPageSize;
      if (_Stack_50.dwPageSize == 0) {
        trap(0x1c00);
      }
      local_54 = uVar5;
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
      if (param_1[5] != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1[5] + 0xa0));
      }
      FUN_c03410b8(*(int *)(param_1[3] + 0x18));
      uVar3 = *(uint *)(param_1[3] + 0x38);
      if (uVar3 < _Stack_50.dwPageSize) {
        uVar6 = _Stack_50.dwPageSize / uVar3;
        if (uVar3 == 0) {
          trap(0x1c00);
        }
      }
      else {
        uVar6 = 1;
      }
      puVar2 = (uint *)(uVar6 * uVar5 + 2);
      iVar1 = (**(code **)(*(int *)param_1[3] + 0x34))((int *)param_1[3],puVar2,0);
      if (iVar1 == 0) {
        for (uVar3 = 0; uVar3 < uVar5; uVar3 = uVar3 + 1) {
          uVar5 = param_6;
          uVar6 = param_5;
          if (param_4 != 0) {
            puVar4 = (uint *)(uVar3 * 8 + param_4);
            uVar5 = puVar4[1];
            uVar6 = *puVar4;
          }
          local_60 = 0;
          iVar1 = FUN_c0339d4c(param_1,puVar2,uVar6,uVar5,*(void **)(uVar3 * 8 + local_58),
                               _Stack_50.dwPageSize,(int *)&local_60);
          local_5c = iVar1;
          if (iVar1 != 0) goto LAB_c033ace4;
          if (param_4 == 0) {
            param_5 = local_60 + param_5;
            param_6 = param_6 + (param_5 < local_60);
          }
          puVar2 = (uint *)0x2b;
          FUN_c033e7c8(param_1[3],0x2b,(int)param_1,uVar6,local_60,0);
          uVar5 = local_54;
        }
        if ((iVar1 == 0) && ((param_1[0x27] & 1) != 0)) {
          iVar1 = FUN_c033a618((int)param_1,0,1);
          local_5c = iVar1;
        }
      }
LAB_c033ace4:
      FUN_c033e7c8(param_1[3],0x2b,(int)param_1,0xffffffff,iVar1,1);
      (**(code **)(*(int *)param_1[3] + 0x38))();
      FUN_c03410d4(*(int **)(param_1[3] + 0x18));
      if (param_1[5] != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1[5] + 0xa0));
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));
      return iVar1;
    }
  }
  return 0x57;
}



/* c033ad94 FUN_c033ad94 */

/* Boundary evidence: original MIPS .pdata c033ad94..c033ad9f. Semantic name remains unreviewed. */

undefined4 FUN_c033ad94(void)

{
  return 1;
}



/* c033ada0 FUN_c033ada0 */

/* Boundary evidence: original MIPS .pdata c033ada0..c033af03. Semantic name remains unreviewed. */

int FUN_c033ada0(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) != 0) {
    if (*(int *)(param_1 + 0x14) != 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
    }
    FUN_c03410b8(*(int *)(*(int *)(param_1 + 0xc) + 0x18));
  }
  puVar1 = (uint *)FUN_c033a2b4(param_1,param_2,param_3,param_4,local_20);
  iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x34))
                    (*(int **)(param_1 + 0xc),puVar1,local_20[0]);
  if ((iVar2 == 0) && (iVar2 = FUN_c0338b48(param_1,puVar1,param_3,param_4), iVar2 == 0)) {
    if ((*(uint *)(param_1 + 0x9c) & 1) == 0) {
      iVar2 = FUN_c03399e4(param_1);
    }
    else {
      iVar2 = FUN_c033a618(param_1,0,1);
    }
  }
  (**(code **)(**(int **)(param_1 + 0xc) + 0x38))();
  if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) != 0) {
    FUN_c03410d4(*(int **)(*(int *)(param_1 + 0xc) + 0x18));
    if (*(int *)(param_1 + 0x14) != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar2;
}



/* c033af04 FUN_c033af04 */

undefined4 * FUN_c033af04(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* c033af24 FUN_c033af24 */

/* Boundary evidence: original MIPS .pdata c033af24..c033afb3. Semantic name remains unreviewed. */

undefined4 * FUN_c033af24(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xc] = 5;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  memset(param_1 + 6,0,8);
  memset(param_1 + 8,0,8);
  memset(param_1 + 10,0,8);
  return param_1;
}



/* c033afb4 FUN_c033afb4 */

/* Boundary evidence: original MIPS .pdata c033afb4..c033b007. Semantic name remains unreviewed. */

void FUN_c033afb4(int param_1)

{
  _FILETIME local_20;
  _SYSTEMTIME _Stack_18;
  
  GetSystemTime(&_Stack_18);
  SystemTimeToFileTime(&_Stack_18,&local_20);
  *(DWORD *)(param_1 + 0x18) = local_20.dwLowDateTime;
  *(DWORD *)(param_1 + 0x1c) = local_20.dwHighDateTime;
  *(DWORD *)(param_1 + 0x20) = local_20.dwLowDateTime;
  *(DWORD *)(param_1 + 0x24) = local_20.dwHighDateTime;
  *(DWORD *)(param_1 + 0x28) = local_20.dwLowDateTime;
  *(DWORD *)(param_1 + 0x2c) = local_20.dwHighDateTime;
  return;
}



/* c033b008 FUN_c033b008 */

void FUN_c033b008(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  param_2[1] = *(undefined4 *)(param_1 + 0x18);
  param_2[2] = *(undefined4 *)(param_1 + 0x1c);
  param_2[3] = *(undefined4 *)(param_1 + 0x20);
  param_2[4] = *(undefined4 *)(param_1 + 0x24);
  param_2[5] = *(undefined4 *)(param_1 + 0x28);
  param_2[6] = *(undefined4 *)(param_1 + 0x2c);
  uVar1 = *(undefined4 *)(param_1 + 0x40);
  param_2[7] = *(undefined4 *)(param_1 + 0x44);
  param_2[8] = uVar1;
  param_2[9] = 0xffffffff;
  return;
}



/* c033b060 FUN_c033b060 */

uint FUN_c033b060(int *param_1)

{
  uint uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)((param_1[2] * 0x20 - param_1[1]) + *param_1) >> 5;
  }
  return uVar1;
}



/* c033b094 FUN_c033b094 */

/* Boundary evidence: original MIPS .pdata c033b094..c033b0d3. Semantic name remains unreviewed. */

undefined4 * FUN_c033b094(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  memset(param_1 + 1,0,0x18);
  return param_1;
}



/* c033b0d4 FUN_c033b0d4 */

/* Boundary evidence: original MIPS .pdata c033b0d4..c033b133. Semantic name remains unreviewed. */

void FUN_c033b0d4(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x94) != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x1c);
    do {
      FSDMGR_DeleteCache(*puVar1);
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 3;
    } while (uVar2 < *(uint *)(param_1 + 0x94));
  }
  *(undefined4 *)(param_1 + 0x94) = 0;
  return;
}



/* c033b134 FUN_c033b134 */

/* Boundary evidence: original MIPS .pdata c033b134..c033b227. Semantic name remains unreviewed. */

int FUN_c033b134(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_70 [8];
  undefined4 local_68 [19];
  uint local_1c;
  uint local_18;
  
  local_18 = DAT_c034d334;
  if (*param_1 == 0) {
    iVar2 = 0x57;
  }
  else {
    iVar2 = FSDMGR_GetDiskInfo(*param_1,param_1 + 1);
    if (iVar2 == 0) {
      if ((param_1[6] & 0x10U) != 0) {
        param_1[0x26] = param_1[0x26] | 1;
      }
      memset(local_68,0,0x50);
      local_68[0] = 0x50;
      iVar1 = FSDMGR_DiskIoControl(*param_1,0x71800,local_68,0x50,0,0,auStack_70,0);
      if ((iVar1 != 0) && ((local_1c & 2) != 0)) {
        param_1[0x26] = param_1[0x26] | 1;
      }
    }
  }
  FUN_c034b674(local_18);
  return iVar2;
}



/* c033b228 FUN_c033b228 */

/* Boundary evidence: original MIPS .pdata c033b228..c033b2ff. Semantic name remains unreviewed. */

undefined4
FUN_c033b228(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0x25] + 1 < 10) {
    iVar2 = param_2 + param_3 + -1;
    iVar1 = FSDMGR_CreateCache(*param_1,param_2,iVar2,param_4,param_1[2],param_5);
    if (iVar1 != -1) {
      param_1[param_1[0x25] * 3 + 7] = iVar1;
      param_1[param_1[0x25] * 3 + 8] = param_2;
      param_1[(param_1[0x25] + 3) * 3] = iVar2;
      param_1[0x25] = param_1[0x25] + 1;
      return 0;
    }
  }
  return 0x1f;
}



/* c033b300 FUN_c033b300 */

/* Boundary evidence: original MIPS .pdata c033b300..c033b383. Semantic name remains unreviewed. */

int FUN_c033b300(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  iVar2 = 0;
  uVar4 = 0;
  if (*(int *)(param_1 + 0x94) != 0) {
    puVar3 = (undefined4 *)(param_1 + 0x1c);
    do {
      iVar1 = FSDMGR_FlushCache(*puVar3,0,0,0);
      if (iVar1 != 0) {
        iVar2 = iVar1;
      }
      uVar4 = uVar4 + 1;
      puVar3 = puVar3 + 3;
    } while (uVar4 < *(uint *)(param_1 + 0x94));
  }
  return iVar2;
}



/* c033b384 FUN_c033b384 */

/* Boundary evidence: original MIPS .pdata c033b384..c033b3fb. Semantic name remains unreviewed. */

undefined4 FUN_c033b384(undefined4 *param_1)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
  dwErrCode = GetLastError();
  uVar1 = FSDMGR_DiskIoControl(*param_1,0x71c54,0,0,0,0,0,0);
  SetLastError(dwErrCode);
  return uVar1;
}



/* c033b3fc FUN_c033b3fc */

undefined4 FUN_c033b3fc(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x94) != 0) {
    puVar1 = (uint *)(param_1 + 0x20);
    do {
      if ((*puVar1 <= param_2) && ((param_2 + param_3) - 1 <= puVar1[1])) {
        return *(undefined4 *)(uVar2 * 0xc + param_1 + 0x1c);
      }
      uVar2 = uVar2 + 1;
      puVar1 = puVar1 + 3;
    } while (uVar2 < *(uint *)(param_1 + 0x94));
  }
  return 0xffffffff;
}



/* c033b46c FUN_c033b46c */

/* Boundary evidence: original MIPS .pdata c033b46c..c033b527. Semantic name remains unreviewed. */

undefined4 FUN_c033b46c(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 local_20 [2];
  undefined4 local_18;
  uint local_14;
  int local_10;
  
  local_18 = 0xc;
  local_20[0] = 0;
  local_14 = param_2;
  local_10 = param_3;
  if (param_1[0x25] == 0) {
    iVar1 = FSDMGR_DiskIoControl(*param_1,0x71c4c,&local_18,0xc,0,0,local_20,0);
  }
  else {
    iVar1 = FUN_c033b3fc((int)param_1,param_2,param_3);
    if (iVar1 == -1) {
      return 0;
    }
    iVar1 = FSDMGR_CacheIoControl(iVar1,0x71c4c,&local_18,0xc,0,0,local_20,0);
  }
  if (iVar1 != 0) {
    return 0;
  }
  return 0x1f;
}



/* c033b528 FUN_c033b528 */

/* Boundary evidence: original MIPS .pdata c033b528..c033b597. Semantic name remains unreviewed. */

undefined4 FUN_c033b528(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c033b3fc(param_1,*param_2,1);
  if (iVar1 == -1) {
    uVar2 = 0x1f;
  }
  else {
    uVar2 = FSDMGR_FlushCache(iVar1,param_2,param_3,param_4);
  }
  return uVar2;
}



/* c033b598 FUN_c033b598 */

/* Boundary evidence: original MIPS .pdata c033b598..c033b5fb. Semantic name remains unreviewed. */

undefined4 FUN_c033b598(int param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c033b3fc(param_1,*param_2,1);
  if (iVar1 == -1) {
    uVar2 = 0x1f;
  }
  else {
    uVar2 = FSDMGR_InvalidateCache(iVar1,param_2,param_3,0);
  }
  return uVar2;
}



/* c033b5fc FUN_c033b5fc */

/* Boundary evidence: original MIPS .pdata c033b5fc..c033b767. Semantic name remains unreviewed. */

void FUN_c033b5fc(undefined4 *param_1,uint param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint local_20;
  int local_1c;
  
  iVar2 = param_1[0x25];
  if (iVar2 != 0) {
    if (((param_2 & 8) == 0) && (iVar1 = FUN_c033b3fc((int)param_1,param_3,param_4), iVar1 != -1)) {
      if ((param_2 & 1) != 0) {
        FSDMGR_CachedRead(iVar1,param_3,param_4,param_5,0);
        return;
      }
      FSDMGR_CachedWrite(iVar1,param_3,param_4,param_5,(param_2 & 4) != 0);
      return;
    }
    if ((iVar2 != 0) && ((param_2 & 8) != 0)) {
      local_20 = param_3;
      local_1c = param_4;
      if ((param_2 & 1) == 0) {
        FUN_c033b598((int)param_1,&local_20,1);
      }
      else {
        FUN_c033b528((int)param_1,&local_20,1,1);
      }
    }
  }
  if ((param_2 & 1) == 0) {
    FSDMGR_WriteDisk(*param_1,param_3,param_4,param_5,param_1[2] * param_4);
  }
  else {
    FSDMGR_ReadDisk();
  }
  return;
}



/* c033b768 FUN_c033b768 */

int FUN_c033b768(uint param_1)

{
  int iVar1;
  
  iVar1 = -1;
  if ((param_1 - 1 & param_1) == 0) {
    for (; param_1 != 0; param_1 = param_1 >> 1) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}



/* c033b794 FUN_c033b794 */

int FUN_c033b794(byte *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  do {
    uVar2 = (uint)*param_1;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      if (param_2 == 0) {
        return iVar1;
      }
      return -1;
    }
    param_1 = param_1 + 1;
    iVar1 = iVar1 * 10 + uVar2 + -0x30;
  } while ((param_2 == 0) || (param_2 = param_2 + -1, param_2 != 0));
  return iVar1;
}



/* c033b7f8 FUN_c033b7f8 */

void FUN_c033b7f8(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = 0;
  if ((-1 < param_1) && (param_1 < 10000)) {
    piVar4 = &DAT_c0331930;
    do {
      if (((iVar1 != 0) || (iVar2 = *piVar4, iVar2 == 1)) || (iVar2 <= param_1)) {
        iVar3 = *piVar4;
        if (iVar3 == 0) {
          trap(0x1c00);
        }
        if ((iVar3 == -1) && (param_1 == -0x80000000)) {
          trap(0x1800);
        }
        *param_2 = (char)(param_1 / iVar3) + '0';
        iVar2 = *piVar4;
        param_2 = param_2 + 1;
        iVar1 = iVar1 + 1;
        param_1 = param_1 - iVar2 * (param_1 / iVar3);
      }
      piVar4 = piVar4 + 1;
    } while (iVar2 != 1);
  }
  return;
}



/* c033b89c FUN_c033b89c */

int FUN_c033b89c(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      for (uVar3 = (uint)*(byte *)(uVar2 + param_1); uVar3 != 0; uVar3 = uVar3 >> 1) {
        if ((uVar3 & 1) != 0) {
          iVar1 = iVar1 + 1;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return iVar1;
}



/* c033b8f0 FUN_c033b8f0 */

/* Boundary evidence: original MIPS .pdata c033b8f0..c033b96b. Semantic name remains unreviewed. */

STRSAFE_PCNZWCH FUN_c033b8f0(STRSAFE_PCNZWCH param_1)

{
  STRSAFE_PCNZWCH pwVar1;
  HRESULT HVar2;
  STRSAFE_PCNZWCH pwVar3;
  size_t local_10 [2];
  
  local_10[0] = 0;
  HVar2 = StringCchLengthW(param_1,0x104,local_10);
  if (HVar2 < 0) {
    pwVar3 = (STRSAFE_PCNZWCH)0x0;
  }
  else {
    pwVar1 = param_1 + local_10[0];
    do {
      pwVar3 = pwVar1;
      if (local_10[0] == 0) {
        return pwVar3;
      }
      local_10[0] = local_10[0] - 1;
      pwVar1 = pwVar3 + -1;
    } while (pwVar3[-1] != L'\\');
  }
  return pwVar3;
}



/* c033b988 FUN_c033b988 */

short * FUN_c033b988(short *param_1)

{
  while( true ) {
    if (*param_1 == 0) {
      return param_1;
    }
    if (*param_1 == 0x5c) break;
    param_1 = param_1 + 1;
  }
  *param_1 = 0;
  return param_1 + 1;
}



/* c033b9ac FUN_c033b9ac */

/* Boundary evidence: original MIPS .pdata c033b9ac..c033ba9b. Semantic name remains unreviewed. */

undefined4 FUN_c033b9ac(uint param_1,uint param_2,short param_3,LPFILETIME param_4)

{
  BOOL BVar1;
  _FILETIME _Stack_20;
  SYSTEMTIME local_18;
  
  local_18.wMilliseconds = param_3 * 10;
  local_18.wDay = (ushort)param_1 & 0x1f;
  local_18.wYear = (short)(param_1 >> 9) + 0x7bc;
  local_18.wHour = (WORD)(param_2 >> 0xb);
  local_18.wDayOfWeek = 0;
  local_18.wMonth = (WORD)((param_1 & 0x1e0) >> 5);
  local_18.wMinute = (WORD)((param_2 & 0x7e0) >> 5);
  local_18.wSecond = (WORD)((param_2 & 0x1f) << 1);
  if (local_18.wMilliseconds < 2000) {
    if (999 < local_18.wMilliseconds) {
      local_18.wSecond = local_18.wSecond + 1;
      local_18.wMilliseconds = local_18.wMilliseconds - 1000;
    }
    BVar1 = SystemTimeToFileTime(&local_18,&_Stack_20);
    if ((BVar1 != 0) && (BVar1 = LocalFileTimeToFileTime(&_Stack_20,param_4), BVar1 != 0)) {
      return 0;
    }
  }
  return 0x1f;
}



/* c033ba9c FUN_c033ba9c */

/* Boundary evidence: original MIPS .pdata c033ba9c..c033bb63. Semantic name remains unreviewed. */

undefined4 FUN_c033ba9c(FILETIME *param_1,ushort *param_2,ushort *param_3,undefined1 *param_4)

{
  _FILETIME _Stack_28;
  _SYSTEMTIME local_20;
  
  FileTimeToLocalFileTime(param_1,&_Stack_28);
  FileTimeToSystemTime(&_Stack_28,&local_20);
  *param_2 = ((local_20.wYear - 0x3c) * 0x10 | local_20.wMonth) << 5 | local_20.wDay;
  if (param_3 != (ushort *)0x0) {
    *param_3 = (local_20.wHour << 6 | local_20.wMinute) << 5 | local_20.wSecond >> 1;
  }
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = (char)(local_20.wMilliseconds / 10);
  }
  return 0;
}



/* c033bb64 FUN_c033bb64 */

/* Boundary evidence: original MIPS .pdata c033bb64..c033bc63. Semantic name remains unreviewed. */

undefined4 FUN_c033bb64(uint param_1,short param_2,undefined4 param_3,LPFILETIME param_4)

{
  BOOL BVar1;
  ushort local_res0;
  ushort uStackX_2;
  _FILETIME _Stack_20;
  SYSTEMTIME local_18;
  
  local_18.wMilliseconds = param_2 * 10;
  uStackX_2 = (ushort)(param_1 >> 0x10);
  local_18.wDayOfWeek = 0;
  local_18.wYear = (uStackX_2 >> 9) + 0x7bc;
  local_res0 = (ushort)param_1;
  local_18.wDay = uStackX_2 & 0x1f;
  local_18.wHour = local_res0 >> 0xb;
  local_18.wMinute = (WORD)((param_1 & 0x7e0) >> 5);
  local_18.wMonth = (WORD)((uStackX_2 & 0x1e0) >> 5);
  local_18.wSecond = (WORD)((param_1 & 0x1f) << 1);
  if (local_18.wMilliseconds < 2000) {
    if (999 < local_18.wMilliseconds) {
      local_18.wSecond = local_18.wSecond + 1;
      local_18.wMilliseconds = local_18.wMilliseconds - 1000;
    }
    BVar1 = SystemTimeToFileTime(&local_18,&_Stack_20);
    if ((BVar1 != 0) && (BVar1 = LocalFileTimeToFileTime(&_Stack_20,param_4), BVar1 != 0)) {
      return 0;
    }
  }
  return 0x1f;
}



/* c033bc64 FUN_c033bc64 */

/* Boundary evidence: original MIPS .pdata c033bc64..c033bd27. Semantic name remains unreviewed. */

undefined4 FUN_c033bc64(FILETIME *param_1,ushort *param_2,undefined1 *param_3)

{
  _FILETIME _Stack_28;
  _SYSTEMTIME local_20;
  
  FileTimeToLocalFileTime(param_1,&_Stack_28);
  FileTimeToSystemTime(&_Stack_28,&local_20);
  param_2[1] = ((local_20.wYear - 0x3c) * 0x10 | local_20.wMonth & 0xf) << 5 | local_20.wDay & 0x1f;
  *param_2 = (local_20.wMinute & 0x3f | local_20.wHour << 6) << 5 |
             (ushort)((local_20.wSecond & 0x3e) >> 1);
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = (char)(local_20.wMilliseconds / 10);
  }
  return 0;
}



/* c033bd28 FSD_RegisterFileSystemFunction */

undefined4 FSD_RegisterFileSystemFunction(void)

{
                    /* 0xbd28  25  FSD_RegisterFileSystemFunction */
  return 0;
}



/* c033bd30 FUN_c033bd30 */

/* Boundary evidence: original MIPS .pdata c033bd30..c033bd93. Semantic name remains unreviewed. */

undefined4 * FUN_c033bd30(undefined4 *param_1,undefined4 param_2)

{
  FUN_c0342f54(param_1,param_2);
  *param_1 = &PTR_FUN_c03319e0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  return param_1;
}



/* c033bd94 FUN_c033bd94 */

/* Boundary evidence: original MIPS .pdata c033bd94..c033be2b. Semantic name remains unreviewed. */

void FUN_c033bd94(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[0x17];
  *param_1 = &PTR_FUN_c03319e0;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x17] = 0;
  }
  puVar1 = (undefined4 *)param_1[0x18];
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
    param_1[0x18] = 0;
  }
  if ((LPVOID)param_1[0x1b] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[0x1b]);
  }
  if ((LPVOID)param_1[0x1d] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[0x1d]);
  }
  FUN_c0342f90(param_1);
  return;
}



/* c033be2c FUN_c033be2c */

/* Boundary evidence: original MIPS .pdata c033be2c..c033be67. Semantic name remains unreviewed. */

void FUN_c033be2c(int param_1)

{
  FUN_c033f954(*(int *)(*(int *)(param_1 + 8) + 0xc),*(int **)(param_1 + 0x58),1);
  FUN_c034301c(param_1);
  return;
}



/* c033be68 FUN_c033be68 */

undefined4 FUN_c033be68(int param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x74);
  *param_2 = (uint)((*(byte *)(iVar1 + 0x6a) & 1) != 0);
  if ((*(byte *)(iVar1 + 0x6a) & 0x10) != 0) {
    *param_2 = 2;
  }
  return 0;
}



/* c033bec8 FUN_c033bec8 */

/* Boundary evidence: original MIPS .pdata c033bec8..c033bfcf. Semantic name remains unreviewed. */

int FUN_c033bec8(int param_1,uint param_2)

{
  undefined2 uVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_20 [2];
  
  puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + 0x14);
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x74);
  iVar2 = FUN_c033be68(param_1,local_20);
  if (param_2 != local_20[0]) {
    uVar1 = *(undefined2 *)(iVar5 + 0x6a);
    bVar3 = (*(byte *)(iVar5 + 0x6a) ^ param_2 == 1) & 1 ^ (byte)uVar1;
    *(byte *)(iVar5 + 0x6a) = bVar3;
    *(undefined1 *)(iVar5 + 0x6b) = *(undefined1 *)(iVar5 + 0x6b);
    *(byte *)(iVar5 + 0x6a) = ((param_2 == 2) << 4 ^ bVar3) & 0x10 ^ bVar3;
    *(char *)(iVar5 + 0x6b) = (char)((ushort)uVar1 >> 8);
    FUN_c033b384(puVar4);
    iVar2 = FUN_c033b5fc(puVar4,10,0,1,iVar5);
    if (iVar2 == 0) {
      FUN_c033b384(puVar4);
    }
  }
  return iVar2;
}



/* c033bfd0 FUN_c033bfd0 */

/* Boundary evidence: original MIPS .pdata c033bfd0..c033c063. Semantic name remains unreviewed. */

int FUN_c033bfd0(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(int *)(*(int *)(param_1 + 0x60) + 0xc) + *(int *)(*(int *)(param_1 + 0x5c) + 0xc);
  iVar1 = 0;
  if (uVar3 == 0) {
    *param_3 = 0;
    iVar1 = 0;
  }
  else {
    if (((*(uint *)(*(int *)(param_1 + 8) + 0x68) & 0x80000) != 0) || (iVar2 = 0, 1 < uVar3)) {
      iVar2 = 1;
    }
    *param_2 = iVar2;
    if ((iVar2 == 0) || (iVar1 = FUN_c033bec8(param_1,1), iVar1 == 0)) {
      *param_3 = 1;
    }
  }
  return iVar1;
}



/* c033c064 FUN_c033c064 */

/* Boundary evidence: original MIPS .pdata c033c064..c033c2e3. Semantic name remains unreviewed. */

int FUN_c033c064(int *param_1,int param_2)

{
  SIZE_T SVar1;
  LPVOID pvVar2;
  int iVar3;
  size_t _Size;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  uint local_38;
  undefined4 *local_34;
  void *local_30;
  
  iVar4 = param_1[2];
  local_38 = 0;
  puVar9 = *(undefined4 **)(iVar4 + 0x14);
  iVar8 = 0;
  iVar10 = 0;
  iVar11 = 0;
  local_34 = puVar9;
  FUN_c03410b8((int)param_1);
  uVar5 = 1 << (*(byte *)(iVar4 + 0x35) & 0x1f);
  FSDMGR_GetRegistryValue(**(undefined4 **)(param_1[2] + 0x14),L"SectorsPerSyncAtInit",&local_38);
  if (((local_38 < uVar5) || (0x400 < local_38)) && (local_38 = 0x20, 0x1f < uVar5)) {
    local_38 = uVar5;
  }
  SVar1 = __ll_lshift(local_38,0,*(undefined1 *)(param_1[2] + 0x34));
  pvVar2 = FUN_c0332264(SVar1);
  param_1[0x1b] = (int)pvVar2;
  pvVar2 = FUN_c0332264(SVar1);
  local_30 = (void *)param_1[0x1b];
  if ((local_30 == (void *)0x0) || (pvVar2 == (LPVOID)0x0)) {
    iVar8 = 8;
  }
  else {
    param_1[0x1c] = local_38;
    if (param_2 == 0) {
      iVar10 = *(int *)(iVar4 + 0x3c);
      iVar11 = *(int *)(iVar4 + 0x4c) + iVar10;
    }
    else if (param_2 == 1) {
      iVar11 = *(int *)(iVar4 + 0x3c);
      iVar10 = *(int *)(iVar4 + 0x4c) + iVar11;
    }
    else if (param_2 == 2) goto LAB_c033c298;
    uVar5 = *(uint *)(iVar4 + 0x4c);
    uVar7 = 0;
    if (uVar5 != 0) {
      do {
        uVar6 = local_38;
        if (uVar5 < uVar7 + local_38) {
          uVar6 = uVar5 - uVar7;
        }
        iVar8 = FUN_c033b5fc(puVar9,1,uVar7 + iVar10,uVar6,local_30);
        if (iVar8 != 0) break;
        iVar3 = FUN_c033b5fc(local_34,1,uVar7 + iVar11,uVar6,pvVar2);
        if (iVar3 == 0) {
          _Size = __ll_lshift(uVar6,0,*(undefined1 *)(param_1[2] + 0x34));
          iVar3 = memcmp(local_30,pvVar2,_Size);
          puVar9 = local_34;
          if (iVar3 != 0) goto LAB_c033c23c;
        }
        else {
LAB_c033c23c:
          puVar9 = local_34;
          iVar8 = FUN_c033b5fc(local_34,4,uVar7 + iVar11,uVar6,local_30);
          if (iVar8 != 0) break;
        }
        uVar5 = *(uint *)(iVar4 + 0x4c);
        uVar7 = uVar7 + local_38;
      } while (uVar7 < uVar5);
    }
  }
LAB_c033c298:
  FUN_c03410d4(param_1);
  if (pvVar2 != (LPVOID)0x0) {
    FUN_c03322a0(pvVar2);
  }
  return iVar8;
}



/* c033c2e4 FUN_c033c2e4 */

/* WARNING: Removing unreachable block (ram,0xc033c4f8) */
/* WARNING: Removing unreachable block (ram,0xc033c5d4) */
/* Boundary evidence: original MIPS .pdata c033c2e4..c033c65f. Semantic name remains unreviewed. */

int FUN_c033c2e4(int *param_1,int param_2)

{
  bool bVar1;
  SIZE_T SVar2;
  LPVOID _Buf2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  uint uVar7;
  void *pvVar8;
  ulonglong uVar9;
  void *local_40;
  void *local_3c;
  void *local_38;
  uint local_34;
  int local_30;
  SIZE_T local_2c;
  
  local_38 = (void *)0x0;
  local_30 = 0;
  local_34 = 0;
  iVar4 = 0;
  pvVar8 = (void *)0x0;
  FUN_c03410b8((int)param_1);
  local_2c = __ll_lshift(param_1[0x1c],0,*(undefined1 *)(param_1[2] + 0x34));
  pvVar6 = (void *)param_1[0x1b];
  local_3c = pvVar6;
  _Buf2 = FUN_c0332264(local_2c);
  if ((pvVar6 == (void *)0x0) || (_Buf2 == (LPVOID)0x0)) {
    iVar4 = 8;
    goto LAB_c033c614;
  }
  bVar1 = false;
  if (param_2 == 0) {
    pvVar8 = (void *)param_1[0x14];
    bVar1 = false;
LAB_c033c3b4:
    local_38 = (void *)param_1[0x16];
  }
  else if (param_2 == 1) {
    local_38 = (void *)param_1[0x14];
    pvVar8 = (void *)param_1[0x16];
    bVar1 = false;
  }
  else if (param_2 == 2) {
    bVar1 = true;
    goto LAB_c033c3b4;
  }
  pvVar5 = (void *)0x0;
  uVar7 = 0;
  uVar9 = FUN_c0338ac4(param_1[0x14]);
  SVar2 = local_2c;
  pvVar6 = local_3c;
  if (bVar1) {
    if (uVar9 != 0) {
      do {
        local_3c = (void *)0x0;
        iVar4 = FUN_c0343644(param_1,local_38,(uint)pvVar5,uVar7,pvVar6,SVar2,(int *)&local_3c);
        if (iVar4 != 0) goto LAB_c033c614;
        iVar3 = FUN_c033b89c((int)pvVar6,(uint)local_3c);
        local_34 = iVar3 + local_34;
        pvVar5 = (void *)((int)local_3c + (int)pvVar5);
        uVar7 = uVar7 + (pvVar5 < local_3c);
      } while (CONCAT44(uVar7,pvVar5) < uVar9);
    }
  }
  else if (uVar9 != 0) {
    do {
      SVar2 = local_2c;
      local_40 = (void *)0x0;
      iVar4 = FUN_c0343644(param_1,local_38,(uint)pvVar5,uVar7,local_3c,local_2c,(int *)&local_40);
      if ((iVar4 != 0) ||
         (iVar4 = FUN_c0343644(param_1,pvVar8,(uint)pvVar5,uVar7,_Buf2,SVar2,(int *)&local_40),
         pvVar6 = local_40, iVar4 != 0)) goto LAB_c033c614;
      iVar3 = memcmp(local_3c,_Buf2,(size_t)local_40);
      if (iVar3 != 0) {
        iVar4 = FUN_c03436cc(param_1,pvVar8,(uint)pvVar5,uVar7,local_3c,(uint)pvVar6,
                             (int *)&local_40);
        if (iVar4 != 0) goto LAB_c033c614;
        local_30 = 1;
        pvVar6 = local_40;
      }
      iVar3 = FUN_c033b89c((int)local_3c,(uint)pvVar6);
      local_34 = iVar3 + local_34;
      pvVar5 = (void *)((int)local_40 + (int)pvVar5);
      uVar7 = uVar7 + (pvVar5 < local_40);
    } while (CONCAT44(uVar7,pvVar5) < uVar9);
    if ((local_30 != 0) &&
       ((iVar4 = FUN_c0338b2c((int)pvVar8,1), iVar4 != 0 ||
        (iVar4 = FUN_c033b300(*(int *)(param_1[2] + 0x14)), iVar4 != 0)))) goto LAB_c033c614;
  }
  uVar7 = *(int *)(param_1[2] + 0x48) - 1;
  if (uVar7 < local_34) {
    iVar4 = 0xb;
  }
  else {
    param_1[0xc] = uVar7 - local_34;
  }
LAB_c033c614:
  FUN_c03410d4(param_1);
  if (_Buf2 != (LPVOID)0x0) {
    FUN_c03322a0(_Buf2);
  }
  return iVar4;
}



/* c033c660 FUN_c033c660 */

/* Boundary evidence: original MIPS .pdata c033c660..c033c76f. Semantic name remains unreviewed. */

int FUN_c033c660(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_18;
  uint local_14;
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 8) + 0x14);
  if (*(int *)(*(int *)(param_1 + 0x5c) + 0xc) != 0) {
    local_18 = 0;
    local_14 = 0;
    FUN_c0345ed0(*(int *)(param_1 + 0x5c),0,*(uint *)(param_1 + 0x70),(int *)&local_18,&local_14);
    while (local_14 != 0) {
      iVar1 = FUN_c033b5fc(puVar2,1,local_18 + *(int *)(param_1 + 0x68),local_14,
                           *(undefined4 *)(param_1 + 0x6c));
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_c033b5fc(puVar2,4,*(int *)(param_1 + 100) + local_18,local_14,
                           *(undefined4 *)(param_1 + 0x6c));
      if (iVar1 != 0) {
        return iVar1;
      }
      local_18 = local_14 + local_18;
      FUN_c0345ed0(*(int *)(param_1 + 0x5c),local_18,*(uint *)(param_1 + 0x70),(int *)&local_18,
                   &local_14);
    }
    FUN_c0345f90(*(int *)(param_1 + 0x5c));
  }
  return 0;
}



/* c033c770 FUN_c033c770 */

/* Boundary evidence: original MIPS .pdata c033c770..c033c8e3. Semantic name remains unreviewed. */

int FUN_c033c770(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint local_28;
  uint local_24;
  uint local_20 [3];
  undefined4 local_14;
  
  local_20[0] = 0;
  iVar2 = 0;
  if (*(int *)(*(int *)(param_1 + 0x60) + 0xc) != 0) {
    local_28 = 0;
    local_24 = 0;
    FUN_c0345ed0(*(int *)(param_1 + 0x60),0,*(uint *)(param_1 + 0x70),(int *)&local_28,&local_24);
    while (local_24 != 0) {
      uVar1 = *(undefined1 *)(*(int *)(param_1 + 8) + 0x34);
      uVar3 = __ll_lshift(local_24,0,uVar1);
      local_14 = (undefined4)((ulonglong)uVar3 >> 0x20);
      uVar4 = __ll_lshift(local_28,0,uVar1);
      iVar2 = FUN_c0343644(param_1,*(void **)(param_1 + 0x50),(uint)uVar4,
                           (uint)((ulonglong)uVar4 >> 0x20),*(void **)(param_1 + 0x6c),(uint)uVar3,
                           (int *)local_20);
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar3 = __ll_lshift(local_28,0,*(undefined1 *)(*(int *)(param_1 + 8) + 0x34));
      iVar2 = FUN_c03436cc(param_1,*(void **)(param_1 + 0x58),(uint)uVar3,
                           (uint)((ulonglong)uVar3 >> 0x20),*(void **)(param_1 + 0x6c),local_20[0],
                           (int *)local_20);
      if (iVar2 != 0) {
        return iVar2;
      }
      local_28 = local_24 + local_28;
      FUN_c0345ed0(*(int *)(param_1 + 0x60),local_28,*(uint *)(param_1 + 0x70),(int *)&local_28,
                   &local_24);
    }
    FUN_c0345f90(*(int *)(param_1 + 0x60));
    iVar2 = FUN_c0338b2c(*(int *)(param_1 + 0x58),1);
    if (iVar2 == 0) {
      iVar2 = FUN_c033b300(*(int *)(*(int *)(param_1 + 8) + 0x14));
    }
  }
  return iVar2;
}



/* c033c8e4 FUN_c033c8e4 */

/* Boundary evidence: original MIPS .pdata c033c8e4..c033c9ef. Semantic name remains unreviewed. */

void FUN_c033c8e4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint local_18;
  uint local_14;
  
  local_18 = 0;
  iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,&local_18);
  if (iVar1 != 0) {
    return;
  }
  if (local_18 != 0) {
    local_14 = 0;
    iVar1 = FUN_c034354c(param_1,param_1[0x16],param_2,&local_14);
    if (iVar1 != 0) {
      return;
    }
    if (local_14 == 0) {
      param_1[0xc] = param_1[0xc] + 1;
    }
    else {
      if ((param_1[0x1d] != 0) && ((uint)param_1[0x1e] < 0x4000)) {
        *(int *)(param_1[0x1e] * 4 + param_1[0x1d]) = param_2;
      }
      param_1[0x1e] = param_1[0x1e] + 1;
    }
    iVar1 = FUN_c03434e4(param_1,param_1[0x14],param_2);
    if (iVar1 != 0) {
      return;
    }
  }
  if (param_3 != 0) {
    (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3);
  }
  return;
}



/* c033c9f0 FUN_c033c9f0 */

/* Boundary evidence: original MIPS .pdata c033c9f0..c033cae3. Semantic name remains unreviewed. */

int FUN_c033c9f0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((*(int *)(param_1 + 0x74) != 0) && ((*(uint *)(*(int *)(param_1 + 8) + 0x6c) & 0x400) == 0)) {
    uVar2 = *(uint *)(param_1 + 0x78);
    if (0x3fff < uVar2) {
      uVar2 = 0x4000;
    }
    if (uVar2 != 0) {
      iVar3 = 0;
      do {
        iVar1 = FUN_c0335190(*(int *)(param_1 + 8),*(int *)(iVar3 + *(int *)(param_1 + 0x74)),1);
        if (iVar1 != 0) {
          iVar4 = iVar1;
        }
        uVar2 = uVar2 - 1;
        iVar3 = iVar3 + 4;
      } while (uVar2 != 0);
    }
    if ((*(uint *)(*(int *)(param_1 + 8) + 0x6c) & 0x400) != 0) {
      FUN_c03322a0(*(LPVOID *)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x74) = 0;
    }
  }
  if (*(int *)(param_1 + 0x30) != -1) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x30);
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  return iVar4;
}



/* c033cae4 FUN_c033cae4 */

/* Boundary evidence: original MIPS .pdata c033cae4..c033cb73. Semantic name remains unreviewed. */

void FUN_c033cae4(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  uint local_14;
  
  local_18 = 0;
  local_14 = 0;
  iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,&local_18);
  if (iVar1 == 0) {
    FUN_c034354c(param_1,param_1[0x16],param_2,&local_14);
  }
  if ((local_18 != 0) || (uVar2 = 1, local_14 != 0)) {
    uVar2 = 0;
  }
  *param_3 = uVar2;
  return;
}



/* c033cb74 FUN_c033cb74 */

/* Boundary evidence: original MIPS .pdata c033cb74..c033ccc3. Semantic name remains unreviewed. */

int FUN_c033cb74(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  SIZE_T SVar4;
  SIZE_T SVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *(int *)(*(int *)(param_1 + 0x58) + 0x10);
  iVar7 = *(int *)(*(int *)(param_1 + 0x50) + 0x10);
  puVar3 = param_2;
  uVar1 = FUN_c0344228(iVar6,param_2);
  SVar5 = 0xffffffff;
  SVar4 = uVar1 << 3;
  if (0x1fffffff < uVar1) {
    SVar4 = SVar5;
  }
  puVar2 = FUN_c0332264(SVar4);
  uVar1 = FUN_c0344228(iVar7,puVar3);
  if (uVar1 < 0x20000000) {
    SVar5 = uVar1 << 3;
  }
  puVar3 = FUN_c0332264(SVar5);
  if ((puVar2 == (undefined4 *)0x0) || (puVar3 == (undefined4 *)0x0)) {
    iVar6 = 8;
  }
  else {
    iVar6 = FUN_c0344ea0(iVar6,puVar2);
    if ((iVar6 == 0) && (iVar6 = FUN_c0344ea0(iVar7,puVar3), iVar6 == 0)) {
      *param_2 = *puVar2;
      *param_3 = puVar2[1];
      *param_4 = *puVar3;
      *param_5 = puVar3[1];
    }
  }
  if (puVar2 != (undefined4 *)0x0) {
    FUN_c03322a0(puVar2);
  }
  if (puVar3 != (undefined4 *)0x0) {
    FUN_c03322a0(puVar3);
  }
  return iVar6;
}



/* c033ccc4 FUN_c033ccc4 */

/* Boundary evidence: original MIPS .pdata c033ccc4..c033cd53. Semantic name remains unreviewed. */

void FUN_c033ccc4(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint local_18;
  uint local_14;
  
  local_18 = 0;
  local_14 = 0;
  iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,&local_18);
  if (iVar1 == 0) {
    FUN_c034354c(param_1,param_1[0x16],param_2,&local_14);
  }
  if ((local_18 == 0) || (uVar2 = 1, local_14 != 0)) {
    uVar2 = 0;
  }
  *param_3 = uVar2;
  return;
}



/* c033cd54 FUN_c033cd54 */

/* Boundary evidence: original MIPS .pdata c033cd54..c033cdbf. Semantic name remains unreviewed. */

void FUN_c033cd54(int *param_1,int param_2,uint param_3,int *param_4,uint *param_5)

{
  int iVar1;
  uint local_10 [2];
  
  local_10[0] = 0;
  iVar1 = FUN_c0343074(param_1,param_2,param_3,param_4,local_10);
  if (iVar1 == 0) {
    if ((uint)param_1[0x1f] < local_10[0]) {
      param_1[0x1f] = 0;
    }
    else {
      param_1[0x1f] = param_1[0x1f] - local_10[0];
    }
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = local_10[0];
  }
  return;
}



/* c033cdc0 FUN_c033cdc0 */

/* Boundary evidence: original MIPS .pdata c033cdc0..c033ce13. Semantic name remains unreviewed. */

void FUN_c033cdc0(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0343074(param_1,-1,1,param_2,(uint *)0x0);
  if ((iVar1 == 0) && (param_1[0x1f] != 0)) {
    param_1[0x1f] = param_1[0x1f] + -1;
  }
  return;
}



/* c033ce14 FUN_c033ce14 */

/* Boundary evidence: original MIPS .pdata c033ce14..c033ce9f. Semantic name remains unreviewed. */

void FUN_c033ce14(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int local_18 [2];
  
  iVar2 = param_1[0x1f];
  local_18[0] = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,local_18);
  if (iVar1 == 0) {
    if ((uint)(param_1[0x1e] + local_18[0]) < iVar2 + 8U) {
      local_18[0] = 0;
    }
    else {
      local_18[0] = (param_1[0x1e] + local_18[0]) - (iVar2 + 8U);
    }
  }
  *param_2 = local_18[0];
  return;
}



/* c033cea0 FUN_c033cea0 */

/* Boundary evidence: original MIPS .pdata c033cea0..c033cfa7. Semantic name remains unreviewed. */

int FUN_c033cea0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  if ((((param_4 == 0) ||
       (iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_4,param_3,0), iVar1 == 0)) &&
      (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2,local_20), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_3,local_20[0],0), iVar1 == 0)) {
    FUN_c033e7c8(param_1[2],0x2c,0,param_2,param_3,0);
    FUN_c033e7c8(param_1[2],0x2d,0,param_4,local_20[0],0);
  }
  return iVar1;
}



/* c033cfa8 FUN_c033cfa8 */

/* Boundary evidence: original MIPS .pdata c033cfa8..c033d0af. Semantic name remains unreviewed. */

void FUN_c033cfa8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 == 0) {
    uVar3 = *(uint *)(iVar1 + 0x54);
  }
  else {
    uVar3 = (param_2 + -2 << (*(byte *)(iVar1 + 0x35) & 0x1f)) + *(int *)(iVar1 + 0x40);
  }
  if (param_3 == 0) {
    uVar2 = *(uint *)(iVar1 + 0x54);
  }
  else {
    uVar2 = (param_3 + -2 << (*(byte *)(iVar1 + 0x35) & 0x1f)) + *(int *)(iVar1 + 0x40);
  }
  iVar5 = 1 << (*(byte *)(*(int *)(param_1 + 8) + 0x35) & 0x1f);
  iVar1 = FUN_c0342994(*(int *)(*(int *)(param_1 + 8) + 0x10),uVar3,uVar2,iVar5);
  if ((iVar1 == 0) && (param_4 != 0)) {
    puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + 0x14);
    iVar1 = FUN_c033b5fc(puVar4,1,uVar3,iVar5,*(undefined4 *)(param_1 + 0x6c));
    if (iVar1 == 0) {
      FUN_c033b5fc(puVar4,2,uVar2,iVar5,*(undefined4 *)(param_1 + 0x6c));
    }
  }
  return;
}



/* c033d0b0 FUN_c033d0b0 */

/* Boundary evidence: original MIPS .pdata c033d0b0..c033d12b. Semantic name remains unreviewed. */

int FUN_c033d0b0(int param_1)

{
  int iVar1;
  uint local_10 [2];
  
  local_10[0] = 0;
  iVar1 = FUN_c0344360(*(int *)(param_1 + 0xc),local_10);
  if (iVar1 == 0) {
    if (local_10[0] < *(uint *)(param_1 + 0x68)) {
      iVar1 = 0x1f;
    }
    else {
      FUN_c0345e2c(*(int *)(param_1 + 0x5c),local_10[0] - *(uint *)(param_1 + 0x68));
      iVar1 = FUN_c033bec8(param_1,0);
      if (iVar1 == 0) {
        iVar1 = FUN_c0341d90(param_1);
      }
    }
  }
  return iVar1;
}



/* c033d12c FUN_c033d12c */

/* Boundary evidence: original MIPS .pdata c033d12c..c033d167. Semantic name remains unreviewed. */

void FUN_c033d12c(int param_1)

{
  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_c03441c4(*(int *)(*(int *)(param_1 + 0x58) + 0x10));
  }
  FUN_c03437c0(param_1);
  return;
}



/* c033d168 FUN_c033d168 */

/* Boundary evidence: original MIPS .pdata c033d168..c033d24b. Semantic name remains unreviewed. */

int FUN_c033d168(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint local_20 [2];
  
  local_20[0] = 0;
  FUN_c03410b8((int)param_1);
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,local_20);
  if (iVar1 != 0) goto LAB_c033d218;
  uVar3 = param_1[0x1f];
  if (uVar3 <= local_20[0]) {
    iVar2 = 0;
    if (param_3 == 0) {
      iVar2 = 2;
    }
    uVar4 = uVar3 + iVar2 + param_2;
    if (uVar4 <= local_20[0]) {
      param_1[0x1f] = uVar3 + param_2;
      goto LAB_c033d218;
    }
    if (uVar4 <= param_1[0x1e] + local_20[0]) {
      iVar1 = 0x2023;
      goto LAB_c033d218;
    }
  }
  iVar1 = 0x70;
LAB_c033d218:
  param_1[0x20] = param_1[0x20] + 1;
  FUN_c03410d4(param_1);
  return iVar1;
}



/* c033d24c FUN_c033d24c */

/* Boundary evidence: original MIPS .pdata c033d24c..c033d293. Semantic name remains unreviewed. */

undefined4 FUN_c033d24c(int *param_1)

{
  int iVar1;
  
  FUN_c03410b8((int)param_1);
  iVar1 = param_1[0x20];
  param_1[0x20] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    param_1[0x1f] = 0;
  }
  FUN_c03410d4(param_1);
  return 0;
}



/* c033d294 FUN_c033d294 */

/* Boundary evidence: original MIPS .pdata c033d294..c033d407. Semantic name remains unreviewed. */

int FUN_c033d294(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint local_20 [2];
  
  puVar2 = FUN_c0332264(0x88);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_c033bd30(puVar2,param_1);
  }
  if (piVar3 == (int *)0x0) {
    iVar4 = 8;
  }
  else {
    *(int **)(param_1 + 0x18) = piVar3;
    local_20[0] = 2;
    iVar4 = FUN_c033be68((int)piVar3,local_20);
    if ((iVar4 == 0) && (iVar4 = FUN_c0334ac4(param_1), uVar1 = local_20[0], iVar4 == 0)) {
      iVar4 = FUN_c033c064(piVar3,local_20[0]);
      if (((iVar4 == 0) &&
          (((iVar4 = (**(code **)(*piVar3 + 4))(piVar3), iVar4 == 0 &&
            (iVar4 = FUN_c0335740(param_1), iVar4 == 0)) &&
           (iVar4 = FUN_c033c2e4(piVar3,uVar1), iVar4 == 0)))) &&
         (((uVar1 == 2 || (iVar4 = FUN_c033bec8((int)piVar3,2), iVar4 == 0)) &&
          (iVar4 = FUN_c0334bd8(param_1), iVar4 == 0)))) {
        FUN_c033e708(param_1);
        FUN_c033e7c8(param_1,0x2e,0,uVar1,0,1);
      }
    }
  }
  return iVar4;
}



/* c033d408 FUN_c033d408 */

/* Boundary evidence: original MIPS .pdata c033d408..c033d687. Semantic name remains unreviewed. */

int FUN_c033d408(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  
  if (param_2 == 0) {
    return 0x1f;
  }
  piVar4 = *(int **)(param_1 + 0x18);
  iVar5 = *(int *)(param_2 + 0x10);
  iVar6 = *(int *)(param_2 + 0x7c);
  iVar1 = param_2;
  FUN_c03410b8((int)piVar4);
  iVar1 = FUN_c0344580(iVar5,iVar1,param_3,0,&local_30);
  if ((iVar1 == 0) && (iVar6 != local_30)) {
    local_28 = 0;
    iVar2 = local_30;
    iVar1 = FUN_c033ccc4(piVar4,local_30,&local_28);
    if ((iVar1 == 0) && (local_28 == 0)) {
      puVar3 = *(uint **)(iVar5 + 0x14);
      if ((*puVar3 & 2) != 0) {
        iVar1 = FUN_c03387fc(param_1,iVar2,puVar3[2],puVar3[3],1);
        iVar1 = (**(code **)(*piVar4 + 0x18))(piVar4,iVar6,iVar1 + iVar6 + -1,1);
        if (iVar1 != 0) goto LAB_c033d638;
        *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x1000;
        **(uint **)(iVar5 + 0x14) = **(uint **)(iVar5 + 0x14) & 0xfffffffd;
      }
      iVar1 = FUN_c033cdc0(piVar4,(int *)&local_2c);
      if ((iVar1 == 0) && (local_2c != 0xffffffff)) {
        iVar6 = local_30;
        iVar1 = FUN_c033cfa8((int)piVar4,local_30,local_2c,1);
        if (iVar1 == 0) {
          local_24 = 0;
          if ((((param_3 < *(uint *)(param_1 + 0x38)) ||
               (iVar1 = FUN_c0344580(iVar5,iVar6,param_3 - *(uint *)(param_1 + 0x38),0,&local_24),
               iVar1 == 0)) && (iVar1 = FUN_c033cea0(piVar4,local_30,local_2c,local_24), iVar1 == 0)
              ) && (iVar1 = (**(code **)(*piVar4 + 0x20))(piVar4,local_30,0), iVar1 == 0)) {
            FUN_c0346214((int *)(iVar5 + 0x18),local_30,~(*(int *)(param_1 + 0x38) - 1U) & param_3,0
                        );
            iVar1 = FUN_c034684c((int *)(iVar5 + 0x18),*(int *)(param_1 + 0x38),
                                 ~(*(int *)(param_1 + 0x38) - 1U) & param_3,0,local_2c);
          }
        }
      }
      else {
        iVar1 = 0x70;
      }
    }
  }
LAB_c033d638:
  FUN_c03410d4(piVar4);
  if ((*(uint *)(param_2 + 0x9c) & 0x1000) != 0) {
    iVar1 = FUN_c03399e4(param_2);
  }
  return iVar1;
}



/* c033d688 FUN_c033d688 */

/* Boundary evidence: original MIPS .pdata c033d688..c033dad3. Semantic name remains unreviewed. */

int FUN_c033d688(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  longlong lVar9;
  undefined8 uVar10;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  
  piVar7 = *(int **)(param_1 + 0x18);
  iVar8 = *(int *)(param_2 + 0x10);
  iVar6 = 0;
  local_48 = 0;
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  uVar3 = param_2;
  if (((*(uint *)(param_2 + 0x4c) & 0x10) == 0) && (lVar9 = FUN_c0338ac4(param_2), lVar9 != 0)) {
    uVar2 = *(uint *)(param_1 + 0x38);
    if (((param_4 == 0) && (uVar1 = uVar3, param_3 < uVar2)) ||
       (iVar6 = FUN_c0344580(iVar8,uVar3,param_3 - uVar2,param_4 - (param_3 < uVar2),
                             (int *)&local_3c), uVar1 = uVar3, iVar6 == 0)) {
      local_2c = 0;
      uVar2 = *(uint *)(param_1 + 0x38) - 1;
      uVar5 = ~((uVar2 < *(uint *)(param_1 + 0x38)) - 1);
      uVar3 = param_5 + param_3;
      uVar2 = ~uVar2;
      local_38 = param_4 + (uVar3 < param_5) + -1 + (uint)(uVar3 - 1 < uVar3) & uVar5;
      uVar5 = uVar5 & param_4;
      local_34 = uVar3 - 1 & uVar2;
      uVar2 = uVar2 & param_3;
      uVar3 = uVar1;
      if ((uVar5 <= local_38) && ((uVar5 != local_38 || (uVar2 <= local_34)))) {
        do {
          iVar6 = FUN_c0344580(iVar8,uVar1,uVar2,uVar5,(int *)&local_48);
          uVar3 = uVar1;
          if (iVar6 != 0) goto LAB_c033da80;
          local_30 = 0;
          uVar1 = local_48;
          iVar6 = FUN_c033ccc4(piVar7,local_48,&local_30);
          uVar3 = uVar1;
          if (iVar6 != 0) goto LAB_c033da80;
          if (local_30 == 0) {
            puVar4 = *(uint **)(iVar8 + 0x14);
            if ((*puVar4 & 2) != 0) {
              uVar3 = puVar4[1];
              iVar6 = FUN_c03387fc(param_1,uVar1,puVar4[2],puVar4[3],1);
              iVar6 = (**(code **)(*piVar7 + 0x18))(piVar7,uVar3,iVar6 + (uVar3 - 1),1);
              if (iVar6 != 0) goto LAB_c033da80;
              *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x1000;
              **(uint **)(iVar8 + 0x14) = **(uint **)(iVar8 + 0x14) & 0xfffffffd;
            }
            if (local_40 == 0) {
              uVar10 = __ull_rshift(local_34 - uVar2,(local_38 - uVar5) - (uint)(local_34 < uVar2),
                                    *(undefined1 *)(param_1 + 0x34));
              iVar6 = __ull_rshift((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
                                   *(undefined1 *)(param_1 + 0x35));
              uVar3 = 0xffffffff;
              iVar6 = (**(code **)(*piVar7 + 0x1c))(piVar7,0xffffffff,iVar6 + 1,&local_44,&local_40)
              ;
              if (iVar6 != 0) goto LAB_c033da80;
            }
            else {
              local_44 = local_44 + 1;
            }
            local_40 = local_40 + -1;
            if ((uVar5 < param_4) || ((uVar5 == param_4 && (uVar2 < param_3)))) {
LAB_c033d994:
              iVar6 = 1;
            }
            else {
              if ((uVar2 == local_34) && (uVar5 == local_38)) {
                uVar3 = (param_5 - local_34) + param_3;
                if ((((local_2c - local_38) - (uint)(param_5 < local_34)) + param_4 +
                     (uint)(uVar3 < param_5 - local_34) == 0) && (uVar3 < *(uint *)(param_1 + 0x38))
                   ) goto LAB_c033d994;
              }
              iVar6 = 0;
            }
            uVar3 = local_48;
            iVar6 = FUN_c033cfa8((int)piVar7,local_48,local_44,iVar6);
            if ((iVar6 != 0) ||
               (uVar3 = local_48, iVar6 = FUN_c033cea0(piVar7,local_48,local_44,local_3c),
               iVar6 != 0)) goto LAB_c033da80;
            if (*(uint *)(*(int *)(iVar8 + 0x14) + 4) == local_48) {
              *(uint *)(*(int *)(iVar8 + 0x14) + 4) = local_44;
              *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x1000;
            }
            uVar3 = local_48;
            iVar6 = (**(code **)(*piVar7 + 0x20))(piVar7,local_48,0);
            if (iVar6 != 0) goto LAB_c033da80;
            local_48 = local_44;
            uVar1 = uVar3;
          }
          uVar2 = *(uint *)(param_1 + 0x38) + uVar2;
          uVar5 = uVar5 + (uVar2 < *(uint *)(param_1 + 0x38));
          local_3c = local_48;
        } while ((uVar5 < local_38) || ((uVar3 = uVar1, uVar5 == local_38 && (uVar2 <= local_34))));
      }
      if (local_40 != 0) {
        piVar7[0xd] = local_44;
      }
    }
LAB_c033da80:
    if (iVar6 == 0x26) {
      iVar6 = 0;
    }
    if (iVar6 != 0) {
      return iVar6;
    }
  }
  FUN_c0343d80(iVar8,uVar3);
  return 0;
}



/* c033dad4 FUN_c033dad4 */

/* Boundary evidence: original MIPS .pdata c033dad4..c033db7b. Semantic name remains unreviewed. */

int FUN_c033dad4(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((param_1[0x1b] & 0x10U) == 0) {
    iVar1 = 0;
  }
  else {
    piVar2 = (int *)param_1[6];
    iVar1 = FUN_c033d168(piVar2,param_2,param_3);
    if (iVar1 == 0x2023) {
      FUN_c033d24c(piVar2);
      iVar1 = (**(code **)(*param_1 + 0x28))(param_1,1);
      if (iVar1 == 0) {
        iVar1 = FUN_c033d168(piVar2,param_2,param_3);
      }
    }
  }
  return iVar1;
}



/* c033db7c FUN_c033db7c */

/* Boundary evidence: original MIPS .pdata c033db7c..c033dbaf. Semantic name remains unreviewed. */

undefined4 FUN_c033db7c(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x6c) & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c033d24c(*(int **)(param_1 + 0x18));
  }
  return uVar1;
}



/* c033dbb0 FUN_c033dbb0 */

/* Boundary evidence: original MIPS .pdata c033dbb0..c033dd63. Semantic name remains unreviewed. */

int FUN_c033dbb0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_18;
  int local_14;
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 0x6c) & 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x18);
    if ((((param_2 != 0) || (0x3fff < (uint)piVar2[0x1e])) ||
        ((*(uint *)(param_1 + 0x6c) & 0x4000) == 0)) &&
       ((iVar1 = FUN_c0342e5c(*(int *)(param_1 + 0x10),0,0,0), iVar1 == 0 &&
        (iVar1 = FUN_c033b300(*(int *)(param_1 + 0x14)), iVar1 == 0)))) {
      FUN_c03410b8((int)piVar2);
      iVar1 = FUN_c0342e5c(*(int *)(param_1 + 0x10),0,0,0);
      if ((iVar1 == 0) && (iVar1 = FUN_c033b300(*(int *)(param_1 + 0x14)), iVar1 == 0)) {
        local_14 = 0;
        local_18 = 0;
        iVar1 = FUN_c033bfd0((int)piVar2,&local_14,&local_18);
        if ((iVar1 == 0) && (local_18 != 0)) {
          FUN_c033e7c8(param_1,0x2f,0,0,0,0);
          iVar1 = FUN_c033c770((int)piVar2);
          if ((iVar1 == 0) && (iVar1 = FUN_c033c660((int)piVar2), iVar1 == 0)) {
            iVar1 = 0;
            if (local_14 != 0) {
              iVar1 = FUN_c033bec8((int)piVar2,2);
            }
            if ((iVar1 == 0) && (iVar1 = FUN_c033c9f0((int)piVar2), iVar1 == 0)) {
              FUN_c033e7c8(param_1,0x2f,0,0,1,1);
            }
          }
        }
      }
      FUN_c03410d4(piVar2);
    }
  }
  return iVar1;
}



/* c033dd64 FUN_c033dd64 */

/* Boundary evidence: original MIPS .pdata c033dd64..c033ddaf. Semantic name remains unreviewed. */

undefined4 * FUN_c033dd64(undefined4 *param_1,uint param_2)

{
  FUN_c033bd94(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c033ddb0 FUN_c033ddb0 */

/* Boundary evidence: original MIPS .pdata c033ddb0..c033dfd3. Semantic name remains unreviewed. */

int FUN_c033ddb0(int param_1)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  iVar4 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar4 + 0x3c);
  iVar3 = *(int *)(iVar4 + 0x3c) + *(int *)(iVar4 + 0x4c);
  *(int *)(param_1 + 0x68) = iVar3;
  *(int *)(param_1 + 0x14) = iVar3;
  uVar6 = __ll_lshift(*(undefined4 *)(iVar4 + 0x4c),0,*(undefined1 *)(iVar4 + 0x34));
  puVar5 = (uint *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x18) = uVar6;
  *(undefined8 *)(param_1 + 0x20) = uVar6;
  *puVar5 = *puVar5 | 1;
  puVar1 = FUN_c0332264(0x90);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c0343ce0(puVar1,*(int *)(param_1 + 8),puVar5);
  }
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
LAB_c033dfb4:
    iVar3 = 8;
  }
  else {
    iVar3 = FUN_c033fe48(*(int *)(*(int *)(param_1 + 8) + 0xc),L"$BITMAP0",0x401,0,0,
                         (undefined4 *)(param_1 + 0x58),(uint *)0x0);
    if (iVar3 == 0) {
      iVar3 = FUN_c033fe48(*(int *)(*(int *)(param_1 + 8) + 0xc),L"$BITMAP1",0x401,0,0,
                           (int *)(param_1 + 0x50),(uint *)0x0);
      if (iVar3 == 0) {
        iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x4c);
        lVar7 = FUN_c0338ac4(*(int *)(param_1 + 0x50));
        lVar7 = lVar7 + (ulonglong)((1 << (*(byte *)(*(int *)(param_1 + 8) + 0x34) & 0x1f)) - 1);
        iVar3 = __ull_rshift((int)lVar7,(int)((ulonglong)lVar7 >> 0x20));
        puVar1 = FUN_c0332264(0x10);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = FUN_c0345d50(puVar1);
        }
        *(undefined4 **)(param_1 + 0x5c) = puVar1;
        puVar1 = FUN_c0332264(0x10);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = FUN_c0345d50(puVar1);
        }
        *(undefined4 **)(param_1 + 0x60) = puVar1;
        if ((*(int *)(param_1 + 0x5c) != 0) && (puVar1 != (undefined4 *)0x0)) {
          iVar4 = FUN_c0345da4(*(int *)(param_1 + 0x5c),iVar4);
          if (iVar4 != 0) {
            return iVar4;
          }
          iVar3 = FUN_c0345da4(*(int *)(param_1 + 0x60),iVar3);
          if (iVar3 != 0) {
            return iVar3;
          }
          if ((*(uint *)(*(int *)(param_1 + 8) + 0x6c) & 0x400) != 0) {
            return 0;
          }
          pvVar2 = FUN_c0332264(0x10000);
          *(LPVOID *)(param_1 + 0x74) = pvVar2;
          return 0;
        }
        goto LAB_c033dfb4;
      }
    }
    iVar3 = 0xb;
  }
  return iVar3;
}



/* c033dfd4 FUN_c033dfd4 */

/* Boundary evidence: original MIPS .pdata c033dfd4..c033e063. Semantic name remains unreviewed. */

void FUN_c033dfd4(int param_1,int param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = __ull_rshift(param_3,0,*(undefined1 *)(*(int *)(param_1 + 8) + 0x34));
  FUN_c0345e2c(*(int *)(param_1 + 0x60),uVar1);
  iVar2 = FUN_c033bec8(param_1,0);
  if (iVar2 == 0) {
    FUN_c03435f0(param_1,param_2,param_3,param_4);
  }
  return;
}



/* c033e064 FUN_c033e064 */

/* Boundary evidence: original MIPS .pdata c033e064..c033e0b7. Semantic name remains unreviewed. */

undefined4 * FUN_c033e064(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  return param_1;
}



/* c033e0b8 FUN_c033e0b8 */

/* Boundary evidence: original MIPS .pdata c033e0b8..c033e0d3. Semantic name remains unreviewed. */

void FUN_c033e0b8(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c033e0d4 FUN_c033e0d4 */

/* Boundary evidence: original MIPS .pdata c033e0d4..c033e0ff. Semantic name remains unreviewed. */

int FUN_c033e0d4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    iVar1 = FUN_c03375dc((int *)*param_1,(undefined4 *)param_1[2],1);
  }
  return iVar1;
}



/* c033e100 FUN_c033e100 */

/* Boundary evidence: original MIPS .pdata c033e100..c033e1af. Semantic name remains unreviewed. */

void FUN_c033e100(int param_1,void *param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_10 [2];
  
  uVar1 = *(uint *)(param_1 + 0x28) + 0x20;
  uVar2 = *(int *)(param_1 + 0x2c) + (uint)(uVar1 < *(uint *)(param_1 + 0x28));
  if ((*(uint *)(param_1 + 0x34) <= uVar2) &&
     ((uVar2 != *(uint *)(param_1 + 0x34) || (*(uint *)(param_1 + 0x30) < uVar1)))) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  local_10[0] = 0;
  FUN_c0345604(*(int *)(*(int *)(param_1 + 4) + 0x10),param_2,*(uint *)(param_1 + 0x28),
               *(uint *)(param_1 + 0x2c),param_2,0x20,0,(int *)local_10);
  uVar1 = local_10[0] + *(int *)(param_1 + 0x28);
  *(uint *)(param_1 + 0x28) = uVar1;
  *(uint *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + (uint)(uVar1 < local_10[0]);
  return;
}



/* c033e1b0 FUN_c033e1b0 */

/* Boundary evidence: original MIPS .pdata c033e1b0..c033e247. Semantic name remains unreviewed. */

void FUN_c033e1b0(int *param_1,LPSTR param_2,STRSAFE_PCNZWCH param_3,uint param_4)

{
  uint cchWideChar;
  size_t local_20 [2];
  
  local_20[0] = 0;
  StringCchLengthW(param_3,0x104,local_20);
  cchWideChar = local_20[0];
  if (param_4 <= local_20[0]) {
    cchWideChar = param_4;
  }
  WideCharToMultiByte(*(UINT *)(*param_1 + 100),0,param_3,cchWideChar,param_2,param_4,(LPCSTR)0x0,
                      (LPBOOL)0x0);
  return;
}



/* c033e248 FUN_c033e248 */

/* Boundary evidence: original MIPS .pdata c033e248..c033e5df. Semantic name remains unreviewed. */

int FUN_c033e248(int *param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  undefined8 uVar13;
  int local_58 [2];
  uint local_50;
  undefined1 auStack_4c [3];
  byte local_49;
  uint local_30;
  
  local_30 = DAT_c034d334;
  local_50 = 0;
  memset(auStack_4c,0,0x1c);
  iVar4 = 4;
  if (param_2 == 0) {
    iVar4 = 3;
  }
  piVar5 = param_1 + 2;
  pvVar3 = (void *)0x0;
  iVar4 = FUN_c033700c((int *)*param_1,0,L"Tfat1234.log",0xc0000000,1,0,iVar4,6,piVar5);
  if (iVar4 == 0) {
    iVar2 = *(int *)(*piVar5 + 0x10);
    param_1[1] = iVar2;
    lVar12 = FUN_c0338ac4(iVar2);
    if (lVar12 == 0) {
      if (param_3 == 0xffffffff) {
        iVar2 = *param_1;
        bVar1 = *(byte *)(iVar2 + 0x34);
        uVar13 = __ll_lshift(*(undefined4 *)(iVar2 + 0x58),0,(uint)bVar1);
        pvVar3 = (void *)((ulonglong)uVar13 >> 0x20);
        uVar11 = 1 << (bVar1 & 0x1f);
        uVar13 = __ull_div((int)uVar13,pvVar3,0x14,0);
        iVar4 = (int)((ulonglong)uVar13 >> 0x20);
        uVar7 = (uint)uVar13;
        uVar10 = 0x6400000;
        uVar9 = uVar7 + uVar11;
        if (((iVar4 + (uint)(uVar9 < uVar7) + -1 + (uint)(uVar9 - 1 < uVar9) &
             ~((uVar11 - 1 < uVar11) - 1)) == 0) && ((uVar9 - 1 & ~(uVar11 - 1)) < 0x6400000)) {
          uVar11 = 1 << (*(byte *)(iVar2 + 0x34) & 0x1f);
          uVar9 = uVar7 + uVar11;
          uVar10 = uVar9 - 1 & ~(uVar11 - 1);
          uVar7 = iVar4 + (uint)(uVar9 < uVar7) + -1 + (uint)(uVar9 - 1 < uVar9) &
                  ~((uVar11 - 1 < uVar11) - 1);
        }
        else {
          uVar7 = 0;
        }
        param_1[0xc] = uVar10;
      }
      else {
        uVar9 = 1 << (*(byte *)(*param_1 + 0x34) & 0x1f);
        uVar7 = param_3 + uVar9;
        param_1[0xc] = uVar7 - 1 & ~(uVar9 - 1);
        uVar7 = ((uVar7 < param_3) - 1) + (uint)(uVar7 - 1 < uVar7) & ~((uVar9 - 1 < uVar9) - 1);
      }
      param_1[0xd] = uVar7;
      FUN_c0338b20(param_1[1],pvVar3,param_1[0xc],uVar7);
      iVar4 = FUN_c033ada0(param_1[1],pvVar3,param_1[0xc],param_1[0xd]);
      if (iVar4 != 0) goto LAB_c033e5a4;
      pvVar3 = (void *)0x1;
      FUN_c033a618(param_1[1],1,0);
    }
    else {
      uVar13 = FUN_c0338ac4(param_1[1]);
      *(undefined8 *)(param_1 + 0xc) = uVar13;
    }
    uVar7 = 0;
    uVar6 = 0;
    uVar10 = 0;
    uVar11 = 0;
    uVar9 = 0;
    if ((param_1[0xd] != 0) || (param_1[0xc] != 0)) {
      while( true ) {
        local_58[0] = 0;
        iVar4 = FUN_c034522c(*(int *)(param_1[1] + 0x10),pvVar3,uVar7,uVar6,&local_50,0x20,0,
                             local_58);
        uVar8 = uVar7;
        if ((iVar4 != 0) || (((local_58[0] != 0x20 || (local_49 < 0x25)) || (0x31 < local_49))))
        break;
        if (uVar9 <= local_50) {
          uVar9 = local_50;
          uVar10 = uVar7;
          uVar11 = uVar6;
        }
        uVar8 = uVar7 + 0x20;
        uVar6 = uVar6 + (uVar8 < uVar7);
        uVar7 = uVar8;
        if (((uint)param_1[0xd] <= uVar6) &&
           ((uVar6 != param_1[0xd] || ((uint)param_1[0xc] <= uVar8)))) break;
      }
      if (uVar8 != 0 || uVar6 != 0) {
        param_1[9] = uVar9 + 1;
        param_1[10] = uVar10 + 0x20;
        param_1[0xb] = uVar11 + (uVar10 + 0x20 < uVar10);
      }
    }
    param_1[8] = 1;
  }
  else {
    *piVar5 = 0;
  }
LAB_c033e5a4:
  FUN_c034b674(local_30);
  return iVar4;
}



/* c033e5e0 FUN_c033e5e0 */

/* Boundary evidence: original MIPS .pdata c033e5e0..c033e707. Semantic name remains unreviewed. */

undefined4
FUN_c033e5e0(int *param_1,undefined1 param_2,STRSAFE_PCNZWCH param_3,STRSAFE_PCNZWCH param_4,
            undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  int local_48;
  undefined2 local_44;
  undefined1 local_42;
  undefined1 local_41;
  CHAR aCStack_40 [8];
  CHAR aCStack_38 [8];
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_28 = DAT_c034d334;
  local_48 = 0;
  uVar1 = 0;
  memset(&local_44,0,0x1c);
  if (param_1[8] != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
    local_48 = param_1[9];
    param_1[9] = local_48 + 1;
    local_30 = param_5;
    local_2c = param_6;
    local_41 = param_2;
    FUN_c033e1b0(param_1,aCStack_40,param_3,8);
    FUN_c033e1b0(param_1,aCStack_38,param_4,8);
    uVar1 = __GetUserKData(8);
    local_44 = (undefined2)((uint)uVar1 >> 0x10);
    local_42 = (undefined1)uVar1;
    uVar1 = FUN_c033e100((int)param_1,&local_48);
    if (param_7 != 0) {
      FUN_c0338b2c(param_1[1],1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 3));
  }
  FUN_c034b674(local_28);
  return uVar1;
}



/* c033e708 FUN_c033e708 */

/* Boundary evidence: original MIPS .pdata c033e708..c033e7c7. Semantic name remains unreviewed. */

void FUN_c033e708(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  LPVOID pvVar4;
  
  puVar1 = FUN_c0332264(0x38);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c033e064(puVar1,param_1);
  }
  *(int **)(param_1 + 0x1c) = piVar2;
  if ((piVar2 != (int *)0x0) &&
     (iVar3 = FUN_c033e248(piVar2,(uint)((*(uint *)(param_1 + 0x68) & 0x8000000) != 0),0xffffffff),
     iVar3 != 0)) {
    puVar1 = (undefined4 *)(*(undefined4 **)(param_1 + 0x1c))[2];
    if (puVar1 != (undefined4 *)0x0) {
      FUN_c03375dc((int *)**(undefined4 **)(param_1 + 0x1c),puVar1,1);
    }
    pvVar4 = *(LPVOID *)(param_1 + 0x1c);
    if (pvVar4 != (LPVOID)0x0) {
      DeleteCriticalSection((LPCRITICAL_SECTION)((int)pvVar4 + 0xc));
      FUN_c03322a0(pvVar4);
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}



/* c033e7c8 FUN_c033e7c8 */

/* Boundary evidence: original MIPS .pdata c033e7c8..c033e81f. Semantic name remains unreviewed. */

void FUN_c033e7c8(int param_1,undefined1 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  STRSAFE_PCNZWCH pwVar1;
  STRSAFE_PCNZWCH pwVar2;
  
  if (*(int **)(param_1 + 0x1c) != (int *)0x0) {
    pwVar1 = (STRSAFE_PCNZWCH)0x0;
    pwVar2 = (STRSAFE_PCNZWCH)0x0;
    if (param_3 != 0) {
      pwVar1 = *(STRSAFE_PCNZWCH *)(param_3 + 0x94);
      if (*(int *)(param_3 + 0x14) != 0) {
        pwVar2 = *(STRSAFE_PCNZWCH *)(*(int *)(param_3 + 0x14) + 0x94);
      }
    }
    FUN_c033e5e0(*(int **)(param_1 + 0x1c),param_2,pwVar2,pwVar1,param_4,param_5,param_6);
  }
  return;
}



/* c033e820 FUN_c033e820 */

undefined4 FUN_c033e820(byte *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((((param_1[1] != 0) || (bVar1 = *param_1, bVar1 < 0x20)) || (0x7e < bVar1)) ||
     ((bVar1 == 0x3f || (uVar2 = 0, bVar1 == 0x2a)))) {
    uVar2 = 1;
  }
  return uVar2;
}



/* c033e870 FUN_c033e870 */

/* Boundary evidence: original MIPS .pdata c033e870..c033e8bb. Semantic name remains unreviewed. */

undefined4 FUN_c033e870(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((uint)*(ushort *)(param_2 + 1) == (uint)*(ushort *)(param_1 + 0x14)) &&
     (iVar1 = memcmp(*(void **)(param_1 + 0x10),(void *)*param_2,(uint)*(ushort *)(param_2 + 1) << 1
                    ), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c033e8bc FUN_c033e8bc */

int FUN_c033e8bc(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined2 *)(param_1 + 0x14) = 0;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return param_1;
}



/* c033e8e4 FUN_c033e8e4 */

/* Boundary evidence: original MIPS .pdata c033e8e4..c033ea1f. Semantic name remains unreviewed. */

int * FUN_c033e8e4(int *param_1,STRSAFE_PCNZWCH param_2)

{
  byte bVar1;
  size_t sVar2;
  HRESULT HVar3;
  int iVar4;
  int *piVar5;
  STRSAFE_PCNZWCH pwVar6;
  int *piVar7;
  uint uVar8;
  size_t local_30 [2];
  STRSAFE_PCNZWCH local_28;
  undefined2 local_24 [2];
  
  local_30[0] = 0;
  local_28 = (STRSAFE_PCNZWCH)0x0;
  memset(local_24,0,4);
  HVar3 = StringCchLengthW(param_2,0x104,local_30);
  sVar2 = local_30[0];
  piVar7 = (int *)0x0;
  if (-1 < HVar3) {
    uVar8 = 0;
    pwVar6 = param_2;
    if (local_30[0] != 0) {
      do {
        iVar4 = FUN_c033e820((byte *)pwVar6);
        if (iVar4 != 0) {
          return (int *)0x0;
        }
        bVar1 = (byte)*pwVar6;
        if ((0x60 < bVar1) && (bVar1 < 0x7b)) {
          *(byte *)pwVar6 = bVar1 - 0x20;
        }
        uVar8 = uVar8 + 1;
        pwVar6 = pwVar6 + 1;
      } while (uVar8 < sVar2);
    }
    local_24[0] = (undefined2)sVar2;
    local_28 = param_2;
    piVar5 = (int *)FUN_c0346a3c(param_1,FUN_c033e870,&local_28);
    if ((piVar5 != (int *)0x0) && (piVar7 = piVar5, piVar5 != (int *)*param_1)) {
      *(int *)(*piVar5 + 4) = piVar5[1];
      *(int *)piVar5[1] = *piVar5;
      iVar4 = *param_1;
      *piVar5 = iVar4;
      piVar5[1] = (int)param_1;
      *(int **)(iVar4 + 4) = piVar5;
      *param_1 = (int)piVar5;
    }
  }
  return piVar7;
}



/* c033ea20 FUN_c033ea20 */

/* Boundary evidence: original MIPS .pdata c033ea20..c033ea97. Semantic name remains unreviewed. */

void FUN_c033ea20(int *param_1,STRSAFE_PCNZWCH param_2)

{
  int *piVar1;
  
  piVar1 = FUN_c033e8e4(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)piVar1[1] = *piVar1;
    FUN_c03322a0((LPVOID)piVar1[3]);
    FUN_c03322a0((LPVOID)piVar1[4]);
    FUN_c03322a0(piVar1);
    param_1[7] = param_1[7] + -1;
  }
  return;
}



/* c033ea98 FUN_c033ea98 */

/* Boundary evidence: original MIPS .pdata c033ea98..c033eb27. Semantic name remains unreviewed. */

void FUN_c033ea98(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_1;
  *param_2 = iVar1;
  param_2[1] = (int)param_1;
  *(int **)(iVar1 + 4) = param_2;
  iVar1 = param_1[7];
  param_1[7] = iVar1 + 1U;
  *param_1 = (int)param_2;
  if (8 < iVar1 + 1U) {
    piVar2 = (int *)param_1[1];
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[1] = *piVar2;
    FUN_c03322a0((LPVOID)piVar2[3]);
    FUN_c03322a0((LPVOID)piVar2[4]);
    FUN_c03322a0(piVar2);
    param_1[7] = param_1[7] + -1;
  }
  return;
}



/* c033eb28 FUN_c033eb28 */

/* Boundary evidence: original MIPS .pdata c033eb28..c033ec7f. Semantic name remains unreviewed. */

undefined4 FUN_c033eb28(int param_1,STRSAFE_PCNZWCH param_2)

{
  byte bVar1;
  LPVOID _Dst;
  HRESULT HVar2;
  STRSAFE_LPWSTR pszDest;
  int iVar3;
  SIZE_T SVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 uVar9;
  size_t local_28 [2];
  
  local_28[0] = 0;
  *(undefined4 *)(param_1 + 8) = 0x1000;
  uVar9 = 0;
  _Dst = FUN_c0332264(0x1000);
  *(LPVOID *)(param_1 + 0xc) = _Dst;
  if (_Dst != (LPVOID)0x0) {
    memset(_Dst,0,*(size_t *)(param_1 + 8));
    HVar2 = StringCchLengthW(param_2,0x104,local_28);
    if (-1 < HVar2) {
      if (local_28[0] + 1 < 0x80000000) {
        SVar4 = (local_28[0] + 1) * 2;
      }
      else {
        SVar4 = 0xffffffff;
      }
      pszDest = FUN_c0332264(SVar4);
      *(STRSAFE_LPWSTR *)(param_1 + 0x10) = pszDest;
      if ((pszDest != (STRSAFE_LPWSTR)0x0) &&
         (HVar2 = StringCchCopyW(pszDest,local_28[0] + 1,param_2), -1 < HVar2)) {
        uVar8 = 0;
        *(short *)(param_1 + 0x14) = (short)local_28[0];
        if (local_28[0] != 0) {
          iVar6 = 0;
          uVar5 = local_28[0];
          do {
            pbVar7 = (byte *)(iVar6 + *(int *)(param_1 + 0x10));
            iVar3 = FUN_c033e820(pbVar7);
            if (iVar3 != 0) {
              return 0;
            }
            bVar1 = *pbVar7;
            if ((0x60 < bVar1) && (bVar1 < 0x7b)) {
              *pbVar7 = bVar1 - 0x20;
              uVar5 = local_28[0];
            }
            uVar8 = uVar8 + 1;
            iVar6 = iVar6 + 2;
          } while (uVar8 < uVar5);
        }
        uVar9 = 1;
      }
    }
  }
  return uVar9;
}



/* c033ec80 FUN_c033ec80 */

/* Boundary evidence: original MIPS .pdata c033ec80..c033ee13. Semantic name remains unreviewed. */

undefined8 FUN_c033ec80(undefined4 param_1,STRSAFE_PCNZWCH param_2)

{
  ulonglong uVar1;
  uint uVar2;
  size_t sVar3;
  HRESULT HVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  size_t local_30 [2];
  
  local_30[0] = 0;
  uVar7 = 0;
  iVar8 = 0;
  uVar10 = 1;
  iVar11 = 0;
  HVar4 = StringCchLengthW(param_2,0x104,local_30);
  sVar3 = local_30[0];
  if ((-1 < HVar4) && (uVar9 = 0, local_30[0] != 0)) {
    do {
      iVar5 = FUN_c033e820((byte *)param_2);
      if (iVar5 != 0) {
        uVar7 = 0;
        iVar8 = 0;
        break;
      }
      uVar6 = (uint)(byte)*param_2;
      if ((uVar6 < 0x61) || (0x7a < uVar6)) {
        uVar2 = (uint)((ulonglong)uVar6 * (ulonglong)uVar10);
        uVar7 = uVar2 + uVar7;
        iVar8 = uVar6 * iVar11 + (int)((ulonglong)uVar6 * (ulonglong)uVar10 >> 0x20) + iVar8 +
                (uint)(uVar7 < uVar2);
      }
      else {
        uVar6 = uVar6 - 0x20;
        uVar2 = (uint)((ulonglong)uVar6 * (ulonglong)uVar10);
        uVar7 = uVar2 + uVar7;
        iVar8 = uVar6 * iVar11 + ((int)uVar6 >> 0x1f) * uVar10 +
                (int)((ulonglong)uVar6 * (ulonglong)uVar10 >> 0x20) + iVar8 + (uint)(uVar7 < uVar2);
      }
      uVar9 = uVar9 + 1;
      uVar1 = (ulonglong)uVar10;
      uVar10 = (uint)(uVar1 * 0x6b);
      iVar11 = iVar11 * 0x6b + (int)(uVar1 * 0x6b >> 0x20);
      param_2 = param_2 + 1;
    } while (uVar9 < sVar3);
  }
  return CONCAT44(iVar8,uVar7);
}



/* c033ee14 FUN_c033ee14 */

/* Boundary evidence: original MIPS .pdata c033ee14..c033ee57. Semantic name remains unreviewed. */

undefined4 FUN_c033ee14(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_c03322a0(*(LPVOID *)((int)param_1 + 0xc));
    FUN_c03322a0(*(LPVOID *)((int)param_1 + 0x10));
    FUN_c03322a0(param_1);
  }
  return 0;
}



/* c033ee58 FUN_c033ee58 */

/* Boundary evidence: original MIPS .pdata c033ee58..c033efb3. Semantic name remains unreviewed. */

undefined4 FUN_c033ee58(int param_1,STRSAFE_PCNZWCH param_2)

{
  size_t sVar1;
  HRESULT HVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  size_t local_238 [2];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c034d334;
  local_238[0] = 0;
  uVar5 = 1;
  HVar2 = StringCchLengthW(param_2,0x104,local_238);
  sVar1 = local_238[0];
  if (-1 < HVar2) {
    uVar4 = 0;
    if (local_238[0] != 0) {
      iVar6 = (int)awStack_230 - (int)param_2;
      do {
        iVar3 = FUN_c033e820((byte *)param_2);
        if (iVar3 != 0) goto LAB_c033ef84;
        if (((byte)*param_2 < 0x61) || (0x7a < (byte)*param_2)) {
          *(wchar_t *)(iVar6 + (int)param_2) = *param_2;
        }
        else {
          *(wchar_t *)(iVar6 + (int)param_2) = *param_2 + L'￠';
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 1;
      } while (uVar4 < sVar1);
    }
    awStack_230[uVar4] = L'\0';
    uVar7 = FUN_c033ec80(param_1,awStack_230);
    uVar4 = __ull_rem((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),*(int *)(param_1 + 8) << 3,0);
    if (((uint)*(byte *)((uVar4 >> 3) + *(int *)(param_1 + 0xc)) & 1 << (uVar4 & 7)) == 0) {
      uVar5 = 0;
    }
  }
LAB_c033ef84:
  FUN_c034b674(local_28);
  return uVar5;
}



/* c033efb4 FUN_c033efb4 */

/* Boundary evidence: original MIPS .pdata c033efb4..c033f04b. Semantic name remains unreviewed. */

LPVOID FUN_c033efb4(STRSAFE_PCNZWCH param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  pvVar1 = FUN_c0332264(0x18);
  if (pvVar1 == (LPVOID)0x0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 8) = 0;
    *(undefined4 *)((int)pvVar1 + 0xc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x10) = 0;
    *(undefined2 *)((int)pvVar1 + 0x14) = 0;
    *(LPVOID *)pvVar1 = pvVar1;
    *(LPVOID *)((int)pvVar1 + 4) = pvVar1;
  }
  if ((pvVar1 != (LPVOID)0x0) && (iVar2 = FUN_c033eb28((int)pvVar1,param_1), iVar2 == 0)) {
    FUN_c03322a0(*(LPVOID *)((int)pvVar1 + 0xc));
    FUN_c03322a0(*(LPVOID *)((int)pvVar1 + 0x10));
    FUN_c03322a0(pvVar1);
    pvVar1 = (LPVOID)0x0;
  }
  return pvVar1;
}



/* c033f04c FUN_c033f04c */

/* Boundary evidence: original MIPS .pdata c033f04c..c033f0b3. Semantic name remains unreviewed. */

undefined4 FUN_c033f04c(int param_1,STRSAFE_PCNZWCH param_2)

{
  uint uVar1;
  byte *pbVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_c033ec80(param_1,param_2);
  uVar1 = __ull_rem((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),*(uint *)(param_1 + 8) << 3,
                    *(uint *)(param_1 + 8) >> 0x1d);
  pbVar2 = (byte *)(*(int *)(param_1 + 0xc) + (uVar1 >> 3));
  *pbVar2 = (byte)(1 << (uVar1 & 7)) | *pbVar2;
  return 1;
}



/* c033f0b4 FUN_c033f0b4 */

/* Boundary evidence: original MIPS .pdata c033f0b4..c033f0fb. Semantic name remains unreviewed. */

void FUN_c033f0b4(int *param_1)

{
  FUN_c0346aac(param_1,FUN_c033ee14,0);
  param_1[7] = 0;
  FUN_c03322a0((LPVOID)param_1[3]);
  FUN_c03322a0((LPVOID)param_1[4]);
  return;
}



/* c033f0fc FUN_c033f0fc */

/* Boundary evidence: original MIPS .pdata c033f0fc..c033f15f. Semantic name remains unreviewed. */

undefined4 * FUN_c033f0fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_c0333b60(param_1);
  param_1[9] = param_2;
  param_1[0xc] = param_3;
  *param_1 = &PTR_FUN_c0331c4c;
  param_1[10] = 0;
  param_1[0xb] = 100;
  return param_1;
}



/* c033f160 FUN_c033f160 */

/* Boundary evidence: original MIPS .pdata c033f160..c033f1df. Semantic name remains unreviewed. */

void FUN_c033f160(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_c0331c4c;
  for (iVar1 = FUN_c0333ba4((int)param_1); iVar1 != 0; iVar1 = FUN_c0333bc8(param_1,iVar1)) {
    if (*(int **)(iVar1 + 0x14) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x14) + 8))();
    }
  }
  FUN_c0333d90(param_1);
  return;
}



/* c033f1e0 FUN_c033f1e0 */

/* Boundary evidence: original MIPS .pdata c033f1e0..c033f34b. Semantic name remains unreviewed. */

undefined4 FUN_c033f1e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x2c);
  uVar5 = 0;
  iVar2 = FUN_c0333be4(param_1);
  while ((iVar2 != 0 && (uVar5 < uVar6))) {
    if ((*(int *)(iVar2 + 0x90) == 0) && ((*(uint *)(iVar2 + 0x9c) & 0x10000) == 0)) {
      piVar4 = *(int **)(iVar2 + 0x14);
      uVar5 = uVar5 + 1;
      *(uint *)(iVar2 + 0x9c) = *(uint *)(iVar2 + 0x9c) | 0x10000;
      while (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(piVar4);
        if ((uVar5 < uVar6) && (piVar4[0x24] == 0)) {
          piVar4[0x27] = piVar4[0x27] | 0x10000;
          piVar4 = (int *)piVar4[5];
          uVar5 = uVar5 + 1;
        }
        else {
          piVar4 = (int *)0x0;
        }
      }
    }
    iVar2 = FUN_c0333bac(param_1,iVar2);
  }
  puVar3 = (undefined4 *)FUN_c0333be4(param_1);
  while ((puVar1 = puVar3, uVar5 != 0 && (puVar1 != (undefined4 *)0x0))) {
    puVar3 = (undefined4 *)FUN_c0333bac(param_1,(int)puVar1);
    if ((puVar1[0x27] & 0x10000) != 0) {
      FUN_c0333c6c(param_1,(int)puVar1);
      (**(code **)*puVar1)(puVar1,1);
      uVar5 = uVar5 - 1;
    }
  }
  return 0;
}



/* c033f34c FUN_c033f34c */

/* Boundary evidence: original MIPS .pdata c033f34c..c033f3c7. Semantic name remains unreviewed. */

undefined4 FUN_c033f34c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  iVar1 = FUN_c0333ba4(param_1);
  do {
    if (iVar1 == 0) {
      uVar2 = 1;
LAB_c033f3a0:
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
      return uVar2;
    }
    if (*(int *)(iVar1 + 0x38) != 0) {
      uVar2 = 0;
      goto LAB_c033f3a0;
    }
    iVar1 = FUN_c0333bc8(param_1,iVar1);
  } while( true );
}



/* c033f3c8 FUN_c033f3c8 */

/* Boundary evidence: original MIPS .pdata c033f3c8..c033f54f. Semantic name remains unreviewed. */

int FUN_c033f3c8(int param_1,int param_2,undefined4 param_3,void *param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  int iVar4;
  
  iVar4 = 8;
  if ((*(uint *)((int)param_4 + 0xc) & 0x10) == 0) {
    puVar2 = FUN_c0332264(0xb8);
    if (puVar2 != (undefined4 *)0x0) {
      piVar1 = FUN_c03394d4(puVar2,*(undefined4 *)(param_1 + 0x24),param_4,0);
      goto LAB_c033f4b4;
    }
LAB_c033f4b0:
    piVar1 = (int *)0x0;
  }
  else {
    if (*(int *)(param_1 + 0x30) == 0) {
      piVar1 = FUN_c0332264(0xb8);
      if (piVar1 == (int *)0x0) goto LAB_c033f4b0;
      FUN_c03394d4(piVar1,*(undefined4 *)(param_1 + 0x24),param_4,8);
      ppuVar3 = &PTR_FUN_c0331bf8;
    }
    else {
      piVar1 = FUN_c0332264(0xb8);
      if (piVar1 == (int *)0x0) goto LAB_c033f4b0;
      FUN_c03394d4(piVar1,*(undefined4 *)(param_1 + 0x24),param_4,0);
      ppuVar3 = &PTR_FUN_c0331c20;
    }
    *piVar1 = (int)ppuVar3;
  }
LAB_c033f4b4:
  if (piVar1 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar1 + 4))(piVar1,param_2,param_3);
    if (iVar4 == 0) {
      FUN_c0333bec(param_1,(int)piVar1);
      *param_5 = piVar1;
    }
    else {
      if ((param_2 != 0) && (*(int *)(param_2 + 0x90) != 0)) {
        *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + -1;
      }
      (**(code **)*piVar1)(piVar1,1);
    }
  }
  return iVar4;
}



/* c033f550 FUN_c033f550 */

/* Boundary evidence: original MIPS .pdata c033f550..c033f747. Semantic name remains unreviewed. */

int FUN_c033f550(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                int param_6,undefined4 param_7,undefined4 *param_8)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t local_88;
  void *local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 auStack_78 [3];
  uint local_6c;
  uint local_68;
  undefined4 local_64;
  
  FUN_c033af24(auStack_78);
  iVar3 = *(int *)(param_1 + 0x24);
  local_80 = 0;
  local_7c = 0;
  bVar1 = false;
  if (((*(uint *)(iVar3 + 0x6c) & 0x1000) != 0) && (param_6 != 0)) {
    local_84 = (void *)0x0;
    local_88 = 0;
    iVar2 = FSDMGR_ParseSecurityDescriptor(param_6,&local_84,&local_88);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar3 = FUN_c03406b4(*(int **)(iVar3 + 0x2a0),local_84,local_88,&local_80);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  local_6c = param_5;
  local_68 = local_80;
  local_64 = local_7c;
  FUN_c033afb4((int)auStack_78);
  iVar3 = (**(code **)(*param_2 + 0x10))(param_2,param_7,auStack_78);
  if (iVar3 == 0) {
    if (((param_5 & 0x10) != 0) && ((*(uint *)(*(int *)(param_1 + 0x24) + 0x6c) & 0x10) != 0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x28));
      FUN_c03410b8(*(int *)(*(int *)(param_1 + 0x24) + 0x18));
      bVar1 = true;
    }
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2,param_3,param_7,0,0,auStack_78);
    if (((iVar3 == 0) &&
        (iVar3 = FUN_c033f3c8(param_1,(int)param_2,param_4,auStack_78,param_8), iVar3 == 0)) &&
       ((param_5 & 0x10) != 0)) {
      iVar3 = (**(code **)(*(int *)*param_8 + 0x20))();
    }
    if (bVar1) {
      FUN_c03410d4(*(int **)(*(int *)(param_1 + 0x24) + 0x18));
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x28));
    }
  }
  return iVar3;
}



/* c033f748 FUN_c033f748 */

/* Boundary evidence: original MIPS .pdata c033f748..c033f793. Semantic name remains unreviewed. */

undefined4 * FUN_c033f748(undefined4 *param_1,uint param_2)

{
  FUN_c03388b0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c033f794 FUN_c033f794 */

/* Boundary evidence: original MIPS .pdata c033f794..c033f7df. Semantic name remains unreviewed. */

undefined4 * FUN_c033f794(undefined4 *param_1,uint param_2)

{
  FUN_c03388b0(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c033f7e0 FUN_c033f7e0 */

/* Boundary evidence: original MIPS .pdata c033f7e0..c033f82b. Semantic name remains unreviewed. */

undefined4 * FUN_c033f7e0(undefined4 *param_1,uint param_2)

{
  FUN_c033f160(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c033f82c FUN_c033f82c */

/* Boundary evidence: original MIPS .pdata c033f82c..c033f953. Semantic name remains unreviewed. */

int FUN_c033f82c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 auStack_68 [3];
  undefined4 local_5c;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_c033af24(auStack_68);
  local_5c = 0x10;
  iVar1 = *(int *)(param_1 + 0x24);
  local_28 = *(undefined4 *)(iVar1 + 0x60);
  local_24 = 0;
  local_1c = 0;
  if (*(int *)(iVar1 + 0x5c) == 0) {
    local_30 = local_30 | 1;
    local_2c = *(undefined4 *)(iVar1 + 0x54);
  }
  else {
    local_30 = local_30 | 4;
    local_2c = *(undefined4 *)(iVar1 + 0x5c);
  }
  local_20 = local_28;
  iVar1 = FUN_c033451c(iVar1);
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) == 0)) {
    *(int *)(param_1 + 0x2c) = 100;
  }
  iVar1 = FUN_c033f3c8(param_1,0,&DAT_c0331bd4,auStack_68,(int *)(param_1 + 0x28));
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x28);
    *(uint *)(iVar2 + 0x9c) = *(uint *)(iVar2 + 0x9c) | 8;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return iVar1;
}



/* c033f954 FUN_c033f954 */

/* Boundary evidence: original MIPS .pdata c033f954..c033fa57. Semantic name remains unreviewed. */

undefined4 FUN_c033f954(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  uVar1 = (**(code **)(*param_2 + 8))(param_2);
  if (param_2[0x24] == 0) {
    if (param_3 == 0) {
      if (*(uint *)(param_1 + 0x2c) < *(uint *)(param_1 + 0x20)) {
        uVar1 = FUN_c033f1e0(param_1);
      }
    }
    else {
      piVar2 = (int *)param_2[5];
      FUN_c0333c6c(param_1,(int)param_2);
      if ((param_2[0x13] & 0x10U) != 0) {
        FUN_c033544c(*(int *)(param_1 + 0x24),(int)param_2);
      }
      (**(code **)*param_2)(param_2,1);
      if (piVar2 != (int *)0x0) {
        uVar1 = FUN_c033f954(param_1,piVar2,0);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return uVar1;
}



/* c033fa58 FUN_c033fa58 */

/* Boundary evidence: original MIPS .pdata c033fa58..c033fe47. Semantic name remains unreviewed. */

int FUN_c033fa58(int param_1,STRSAFE_PCNZWCH param_2,int *param_3,STRSAFE_PCNZWCH param_4,
                uint param_5,uint param_6,int param_7,int *param_8,uint *param_9)

{
  bool bVar1;
  HRESULT HVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *local_2d8;
  size_t local_2d4;
  int *local_2d0;
  int local_2cc;
  STRSAFE_PCNZWCH local_2c8;
  undefined4 local_2c4 [2];
  undefined4 local_2bc;
  undefined4 auStack_2b8 [20];
  undefined4 local_268;
  undefined1 auStack_264 [44];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c034d334;
  local_2cc = param_7;
  local_2d0 = param_8;
  FUN_c033af24(auStack_2b8);
  local_268 = 0;
  memset(auStack_264,0,0x28);
  local_2d4 = 0;
  HVar2 = StringCchLengthW(param_4,0x104,&local_2d4);
  if (HVar2 < 0) {
    iVar6 = 0x1f;
    goto LAB_c033fd3c;
  }
  iVar6 = (**(code **)(**(int **)(param_1 + 0x24) + 0x24))
                    (*(int **)(param_1 + 0x24),param_4,local_2d4,awStack_238);
  if (iVar6 != 0) goto LAB_c033fd3c;
  piVar3 = (int *)FUN_c0333ba4(param_1);
  *param_8 = 0;
  local_2d8 = piVar3;
  if (piVar3 == (int *)0x0) {
LAB_c033fb90:
    if (param_3 == (int *)0x0) {
LAB_c033fb98:
      iVar6 = 3;
    }
    else {
      iVar4 = FUN_c033532c(*(int *)(param_1 + 0x24),param_2,param_4);
      if ((iVar4 != 0) || ((param_5 & 0x20) != 0)) {
        memset(local_2c4,0,0xc);
        if (((param_5 & 0x20) != 0) &&
           (local_2c4[0] = 4, (*(uint *)(*(int *)(param_1 + 0x24) + 0x6c) & 0x1000) != 0)) {
          local_2bc = 1;
        }
        if ((param_5 & 0x400) != 0) {
          local_2c4[0] = 8;
        }
        local_2c8 = param_4;
        iVar4 = (**(code **)(*param_3 + 0xc))(param_3,&local_2c8,auStack_2b8,&local_268);
        if (iVar4 == 0) {
          iVar6 = FUN_c033f3c8(param_1,(int)param_3,awStack_238,auStack_2b8,&local_2d8);
          piVar3 = local_2d8;
          if (iVar6 != 0) goto LAB_c033fe28;
LAB_c033fc80:
          if (piVar3 != (int *)0x0) goto LAB_c033fd80;
          if ((param_5 & 0x20) == 0) {
            if ((param_5 & 2) == 0) {
              iVar6 = 2;
            }
            else {
              iVar6 = 3;
            }
            goto LAB_c033fd3c;
          }
          iVar6 = FUN_c033f550(param_1,param_3,param_4,awStack_238,param_6,local_2cc,&local_268,
                               &local_2d8);
          piVar3 = local_2d8;
          if (iVar6 != 0) goto LAB_c033fe28;
          iVar4 = FUN_c03353bc(*(int *)(param_1 + 0x24),param_2,param_4);
          if (iVar4 == 0) {
            FUN_c033544c(*(int *)(param_1 + 0x24),(int)param_3);
          }
          piVar3 = local_2d8;
          if (param_9 != (uint *)0x0) {
            *param_9 = *param_9 | 0x80;
          }
        }
        else {
          if (iVar4 == 2) goto LAB_c033fc80;
LAB_c033fe20:
          iVar6 = iVar4;
          if (iVar6 != 0) goto LAB_c033fe28;
        }
LAB_c033fd34:
        *local_2d0 = (int)piVar3;
        goto LAB_c033fd3c;
      }
      if ((param_5 & 2) != 0) goto LAB_c033fb98;
      iVar6 = 2;
    }
  }
  else {
    do {
      local_2d8 = piVar3;
      if ((param_3 == (int *)piVar3[5]) &&
         (bVar1 = FUN_c033520c(*(undefined4 *)(param_1 + 0x24),awStack_238,(wchar_t *)piVar3[0x25]),
         CONCAT31(extraout_var,bVar1) != 0)) {
        piVar3[0x24] = piVar3[0x24] + 1;
        break;
      }
      piVar3 = (int *)FUN_c0333bc8(param_1,(int)piVar3);
      local_2d8 = piVar3;
    } while (piVar3 != (int *)0x0);
    if (piVar3 == (int *)0x0) goto LAB_c033fb90;
LAB_c033fd80:
    uVar5 = piVar3[0x13];
    if (uVar5 == 0) {
      uVar5 = 0;
    }
    if (param_9 != (uint *)0x0) {
      *param_9 = *param_9 | 0x100;
    }
    if (((param_5 & 0x40) == 0) || ((uVar5 & 1) == 0)) {
      if ((param_5 & 0x10) == 0) {
        if ((uVar5 & 0x10) == 0) {
          if ((param_5 & 2) != 0) goto LAB_c033fb98;
        }
        else if ((param_5 & 1) != 0) {
          iVar4 = 5;
          goto LAB_c033fe20;
        }
        goto LAB_c033fd34;
      }
      if (((uVar5 & 0x10) == 0) && ((param_5 & 2) == 0)) {
        iVar6 = 0x50;
      }
      else {
        iVar6 = 0xb7;
      }
    }
    else {
      iVar6 = 5;
    }
  }
LAB_c033fe28:
  if (piVar3 != (int *)0x0) {
    FUN_c033f954(param_1,piVar3,0);
  }
LAB_c033fd3c:
  FUN_c034b674(local_30);
  return iVar6;
}



/* c033fe48 FUN_c033fe48 */

/* Boundary evidence: original MIPS .pdata c033fe48..c03400bb. Semantic name remains unreviewed. */

int FUN_c033fe48(int param_1,STRSAFE_LPCWSTR param_2,uint param_3,uint param_4,int param_5,
                undefined4 *param_6,uint *param_7)

{
  HRESULT HVar1;
  wchar_t *pwVar2;
  STRSAFE_LPWSTR pszDest;
  size_t sVar3;
  wchar_t *pwVar4;
  int *piVar5;
  int iVar6;
  wchar_t *_Str;
  wchar_t *pwVar7;
  LPCRITICAL_SECTION lpCriticalSection;
  uint uVar8;
  int *local_458;
  uint local_454;
  LPCRITICAL_SECTION local_450;
  int local_44c;
  uint *local_448;
  wchar_t local_440 [260];
  wchar_t local_238;
  wchar_t awStack_236 [259];
  uint local_30;
  
  local_30 = DAT_c034d334;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  local_44c = param_5;
  iVar6 = 0;
  piVar5 = (int *)0x0;
  local_448 = param_7;
  local_458 = (int *)0x0;
  local_454 = param_4;
  local_450 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  pszDest = &local_238;
  sVar3 = 0x104;
  if (*param_2 != L'\\') {
    local_238 = L'\\';
    pszDest = awStack_236;
    sVar3 = 0x103;
  }
  HVar1 = StringCchCopyW(pszDest,sVar3,param_2);
  if (HVar1 < 0) {
    iVar6 = 0x1f;
  }
  else {
    pwVar7 = &local_238;
    pwVar2 = thunk_FUN_c033b988(&local_238);
    local_440[0] = L'\\';
    local_440[1] = 0;
    pwVar4 = local_440;
    _Str = pwVar7;
    if (*pwVar2 != L'\0') {
      do {
        pwVar7 = pwVar2;
        iVar6 = FUN_c033fa58(param_1,local_440,piVar5,_Str,2,0,0,(int *)&local_458,(uint *)0x0);
        if (piVar5 != (int *)0x0) {
          FUN_c033f954(param_1,piVar5,0);
        }
        piVar5 = local_458;
        lpCriticalSection = local_450;
        if (iVar6 != 0) goto LAB_c0340078;
        sVar3 = wcslen(_Str);
        uVar8 = sVar3 & 0xffff;
        if (uVar8 != 0) {
          *pwVar4 = L'\\';
          memcpy(pwVar4 + 1,_Str,(uVar8 + 1) * 2);
          pwVar4 = pwVar4 + 1 + uVar8;
        }
        pwVar2 = thunk_FUN_c033b988(pwVar7);
        _Str = pwVar7;
      } while (*pwVar2 != L'\0');
      if (piVar5 != (int *)0x0) {
        FUN_c0336538(*(int *)(param_1 + 0x24),piVar5,local_440);
      }
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
    if ((param_3 & 0x200) == 0) {
      iVar6 = FUN_c033fa58(param_1,local_440,piVar5,pwVar7,param_3,local_454,local_44c,
                           (int *)&local_458,local_448);
      if (piVar5 != (int *)0x0) {
        FUN_c033f954(param_1,piVar5,0);
      }
      if (iVar6 == 0) {
        *param_6 = local_458;
      }
    }
    else if (piVar5 == (int *)0x0) {
      iVar6 = 3;
    }
    else {
      *param_6 = piVar5;
    }
  }
LAB_c0340078:
  LeaveCriticalSection(lpCriticalSection);
  FUN_c034b674(local_30);
  return iVar6;
}



/* c03400bc FUN_c03400bc */

undefined4 * FUN_c03400bc(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  return param_1;
}



/* c03400cc FUN_c03400cc */

/* Boundary evidence: original MIPS .pdata c03400cc..c03400f3. Semantic name remains unreviewed. */

void FUN_c03400cc(int param_1)

{
  if (*(LPVOID *)(param_1 + 4) != (LPVOID)0x0) {
    FUN_c03322a0(*(LPVOID *)(param_1 + 4));
  }
  return;
}



/* c03400f4 FUN_c03400f4 */

undefined4 FUN_c03400f4(int param_1,int param_2,int param_3,undefined2 *param_4)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 4) == 0) || (param_2 == 0)) || (param_4 == (undefined2 *)0x0)) {
    uVar1 = 0x57;
  }
  else {
    if (param_3 != 0) {
      puVar2 = param_4;
      iVar3 = param_3;
      do {
        iVar3 = iVar3 + -1;
        *puVar2 = *(undefined2 *)
                   ((uint)*(ushort *)((param_2 - (int)param_4) + (int)puVar2) * 2 +
                   *(int *)(param_1 + 4));
        puVar2 = puVar2 + 1;
      } while (iVar3 != 0);
    }
    param_4[param_3] = 0;
    uVar1 = 0;
  }
  return uVar1;
}



/* c034016c FUN_c034016c */

undefined4 FUN_c034016c(undefined4 param_1,short *param_2,uint param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  
  uVar1 = 0xb;
  uVar3 = 0;
  uVar7 = 0;
  uVar5 = 1;
  if (param_5 != 0) {
    uVar2 = 1;
    psVar6 = param_2;
    do {
      if (param_3 <= uVar3) {
        return 0xb;
      }
      if ((*psVar6 == -1) && (uVar2 != param_3)) {
        if (param_3 <= uVar2) {
          return 0xb;
        }
        uVar7 = (ushort)psVar6[1] + uVar7;
        uVar3 = uVar3 + 2;
        uVar2 = uVar2 + 2;
        psVar6 = psVar6 + 2;
        if (param_5 < uVar7) {
          return 0xb;
        }
      }
      else {
        uVar7 = uVar7 + 1;
        uVar3 = uVar3 + 1;
        uVar2 = uVar2 + 1;
        psVar6 = psVar6 + 1;
      }
    } while (uVar7 < param_5);
  }
  if (uVar3 == param_3) {
    uVar3 = 0;
    if (param_5 != 0) {
      do {
        if ((*param_2 == -1) && (uVar5 != param_3)) {
          uVar7 = (ushort)param_2[1] + uVar3;
          param_2 = param_2 + 2;
          uVar5 = uVar5 + 2;
          if (uVar3 < uVar7) {
            puVar4 = (undefined2 *)(uVar3 * 2 + param_4);
            do {
              *puVar4 = (short)uVar3;
              uVar3 = uVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (uVar3 < uVar7);
          }
        }
        else {
          *(short *)(uVar3 * 2 + param_4) = *param_2;
          param_2 = param_2 + 1;
          uVar3 = uVar3 + 1;
          uVar5 = uVar5 + 1;
        }
      } while (uVar3 < param_5);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c0340294 FUN_c0340294 */

/* Boundary evidence: original MIPS .pdata c0340294..c034047f. Semantic name remains unreviewed. */

int FUN_c0340294(int *param_1)

{
  int iVar1;
  uint uVar2;
  LPVOID pvVar3;
  SIZE_T SVar4;
  wchar_t *pwVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  short *psVar9;
  uint uVar10;
  ulonglong uVar11;
  int *local_28;
  uint local_24;
  
  local_28 = (int *)0x0;
  pwVar5 = L"$UPCASETABLE";
  psVar9 = (short *)0x0;
  iVar1 = FUN_c033fe48(*(int *)(*param_1 + 0xc),L"$UPCASETABLE",0x401,0,0,&local_28,(uint *)0x0);
  if (iVar1 != 0) {
    iVar1 = 0xb;
    goto LAB_c034043c;
  }
  uVar11 = FUN_c0338ac4((int)local_28);
  uVar2 = (uint)uVar11;
  uVar10 = uVar2 >> 1;
  if ((0x10000 < uVar10) || ((uVar11 & 1) != 0)) goto LAB_c0340428;
  if (uVar10 < 0x80000000) {
    SVar4 = uVar10 << 1;
  }
  else {
    SVar4 = 0xffffffff;
  }
  psVar9 = FUN_c0332264(SVar4);
  if (psVar9 == (short *)0x0) {
LAB_c03403fc:
    iVar1 = 8;
  }
  else {
    local_24 = 0;
    iVar1 = FUN_c033a3b0((int)local_28,pwVar5,0,0,psVar9,uVar2,&local_24);
    if (iVar1 == 0) {
      if (uVar2 == local_24) {
        uVar7 = 0;
        uVar8 = 0;
        if (uVar2 != 0) {
          do {
            iVar1 = -0x80000000;
            if ((uVar7 & 1) == 0) {
              iVar1 = 0;
            }
            pbVar6 = (byte *)(uVar8 + (int)psVar9);
            uVar8 = uVar8 + 1;
            uVar7 = (uint)*pbVar6 + (uVar7 >> 1) + iVar1;
          } while (uVar8 < uVar2);
        }
        if (uVar7 == local_28[0x1d]) {
          pvVar3 = FUN_c0332264(0x20000);
          param_1[1] = (int)pvVar3;
          if (pvVar3 == (LPVOID)0x0) goto LAB_c03403fc;
          iVar1 = FUN_c034016c(param_1,psVar9,uVar10,(int)pvVar3,0x10000);
          goto LAB_c034042c;
        }
      }
LAB_c0340428:
      iVar1 = 0xb;
    }
  }
LAB_c034042c:
  if (psVar9 != (short *)0x0) {
    FUN_c03322a0(psVar9);
  }
LAB_c034043c:
  if (local_28 != (int *)0x0) {
    FUN_c033f954(*(int *)(*param_1 + 0xc),local_28,1);
  }
  return iVar1;
}



/* c0340480 FUN_c0340480 */

void FUN_c0340480(int param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 0;
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      iVar3 = 0x8000;
      if ((uVar1 & 1) == 0) {
        iVar3 = 0;
      }
      pbVar2 = (byte *)(uVar4 + param_1);
      uVar4 = uVar4 + 1;
      uVar1 = (uint)*pbVar2 + (uVar1 >> 1) + iVar3 & 0xffff;
    } while (uVar4 < param_2);
  }
  return;
}



/* c03404d0 FUN_c03404d0 */

/* Boundary evidence: original MIPS .pdata c03404d0..c034050b. Semantic name remains unreviewed. */

undefined4 * FUN_c03404d0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return param_1;
}



/* c034050c FUN_c034050c */

/* Boundary evidence: original MIPS .pdata c034050c..c0340547. Semantic name remains unreviewed. */

void FUN_c034050c(int param_1)

{
  if (*(LPVOID *)(param_1 + 8) != (LPVOID)0x0) {
    FUN_c03322a0(*(LPVOID *)(param_1 + 8));
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  return;
}



/* c0340548 FUN_c0340548 */

/* Boundary evidence: original MIPS .pdata c0340548..c034057b. Semantic name remains unreviewed. */

undefined4 FUN_c0340548(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1[2] != 0) {
    uVar1 = FUN_c033f954(*(int *)(*param_1 + 0xc),(int *)param_1[1],1);
  }
  return uVar1;
}



/* c034057c FUN_c034057c */

/* Boundary evidence: original MIPS .pdata c034057c..c03406b3. Semantic name remains unreviewed. */

undefined4 FUN_c034057c(int param_1,int param_2,void *param_3,uint param_4,uint *param_5)

{
  uint _Size;
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  uVar1 = *(uint *)(param_2 + 0x50);
  if ((uVar1 & 3) == 0) {
    uVar4 = FUN_c0338ac4(*(int *)(param_1 + 4));
    if (((int)((ulonglong)uVar4 >> 0x20) != 0) || (uVar1 <= (uint)uVar4)) {
      if (uVar1 == 0) {
        uVar2 = 0x546;
        goto LAB_c0340680;
      }
      iVar3 = *(int *)(param_1 + 8) + uVar1;
      _Size = *(uint *)(iVar3 + 4);
      if ((param_4 < _Size) || (param_3 == (void *)0x0)) {
        uVar2 = 0x7a;
        *param_5 = _Size;
        goto LAB_c0340680;
      }
      uVar4 = FUN_c0338ac4(*(int *)(param_1 + 4));
      if (((int)((ulonglong)uVar4 >> 0x20) != 0) || (_Size + uVar1 + 8 <= (uint)uVar4)) {
        memcpy(param_3,(void *)(iVar3 + 8),_Size);
        goto LAB_c0340680;
      }
    }
  }
  uVar2 = 0xb;
LAB_c0340680:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  return uVar2;
}



/* c03406b4 FUN_c03406b4 */

/* Boundary evidence: original MIPS .pdata c03406b4..c034091b. Semantic name remains unreviewed. */

int FUN_c03406b4(int *param_1,void *param_2,size_t param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  SIZE_T SVar4;
  size_t _Size;
  byte *pbVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_34;
  LPCRITICAL_SECTION local_30;
  
  local_30 = (LPCRITICAL_SECTION)(param_1 + 4);
  iVar8 = 0;
  EnterCriticalSection(local_30);
  iVar1 = FUN_c0340480((int)param_2,param_3);
  uVar9 = 0x20;
  uVar12 = FUN_c0338ac4(param_1[1]);
  uVar6 = (uint)uVar12;
  if (uVar6 < 0x21) {
LAB_c03407b0:
    uVar11 = param_3 + 8;
    uVar10 = uVar11 + uVar9;
    if ((uint)param_1[3] < uVar10) {
      SVar4 = *(int *)(*param_1 + 0x38) + uVar11 + uVar9;
      param_1[3] = SVar4;
      pvVar3 = FUN_c03322c8((LPVOID)param_1[2],SVar4);
      param_1[2] = (int)pvVar3;
      if (pvVar3 == (LPVOID)0x0) {
        iVar8 = 8;
        goto LAB_c03408e0;
      }
      memset((void *)((int)pvVar3 + uVar6),0,param_1[3] - uVar6);
    }
    piVar7 = (int *)(param_1[2] + uVar9);
    piVar7[1] = param_3;
    *piVar7 = iVar1;
    memcpy(piVar7 + 2,param_2,param_3);
    local_34 = 0;
    iVar8 = FUN_c033a95c((uint *)param_1[1],param_2,uVar9,0,piVar7,uVar11,&local_34);
    if (iVar8 != 0) goto LAB_c03408e0;
    uVar6 = 0;
    uVar11 = 0;
    if (uVar10 != 0) {
      do {
        iVar1 = -0x80000000;
        if ((uVar6 & 1) == 0) {
          iVar1 = 0;
        }
        pbVar5 = (byte *)(param_1[2] + uVar11);
        uVar11 = uVar11 + 1;
        uVar6 = (uint)*pbVar5 + (uVar6 >> 1) + iVar1;
      } while (uVar11 < uVar10);
    }
    *(uint *)(param_1[1] + 0x74) = uVar6;
    *(uint *)(param_1[1] + 0x9c) = *(uint *)(param_1[1] + 0x9c) | 0x100;
    iVar8 = FUN_c033a618(param_1[1],1,0);
    if (iVar8 != 0) goto LAB_c03408e0;
  }
  else {
    do {
      piVar7 = (int *)(param_1[2] + uVar9);
      _Size = piVar7[1];
      if (uVar6 < _Size + uVar9 + 8) {
        iVar8 = 0xb;
        goto LAB_c03408e0;
      }
    } while ((((*piVar7 != iVar1) || (_Size != param_3)) ||
             (iVar2 = memcmp(param_2,piVar7 + 2,_Size), iVar2 != 0)) &&
            (uVar9 = _Size + uVar9 + 0xb & 0xfffffffc, uVar9 < uVar6));
    if (uVar6 <= uVar9) goto LAB_c03407b0;
  }
  *param_4 = uVar9;
  param_4[1] = 0;
LAB_c03408e0:
  LeaveCriticalSection(local_30);
  return iVar8;
}



/* c034091c FUN_c034091c */

/* Boundary evidence: original MIPS .pdata c034091c..c0340a83. Semantic name remains unreviewed. */

int FUN_c034091c(int *param_1,int param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  void *pvVar6;
  uint local_28;
  int local_24;
  
  local_28 = 0;
  local_24 = 0;
  iVar3 = FUN_c03406b4(param_1,param_3,param_4,&local_28);
  iVar2 = local_24;
  uVar1 = local_28;
  if (iVar3 == 0) {
    pvVar6 = (void *)(param_2 + 0x40);
    if ((local_28 != *(uint *)(param_2 + 0x50)) || (local_24 != *(int *)(param_2 + 0x54))) {
      *(uint *)(param_2 + 0x50) = local_28;
      *(int *)(param_2 + 0x54) = local_24;
      pvVar4 = pvVar6;
      memcpy(pvVar6,pvVar6,0x50);
      piVar5 = *(int **)(param_2 + 0x14);
      if (piVar5 == (int *)0x0) {
        pvVar6 = (void *)param_1[2];
        if ((*(uint *)((int)pvVar6 + 0x18) != uVar1) || (*(int *)((int)pvVar6 + 0x1c) != iVar2)) {
          *(uint *)((int)pvVar6 + 0x18) = uVar1;
          *(int *)((int)pvVar6 + 0x1c) = iVar2;
          local_28 = 0;
          iVar3 = FUN_c033a95c((uint *)param_1[1],pvVar4,0,0,pvVar6,0x20,(int *)&local_28);
          if (iVar3 == 0) {
            iVar3 = FUN_c033a618(param_1[1],1,0);
          }
        }
      }
      else {
        iVar3 = (**(code **)(*piVar5 + 0x1c))(piVar5,pvVar6,2,2);
        if (iVar3 == 0) {
          iVar3 = FUN_c0338b2c((int)piVar5,0);
        }
      }
    }
  }
  return iVar3;
}



/* c0340a84 FUN_c0340a84 */

/* Boundary evidence: original MIPS .pdata c0340a84..c0340b93. Semantic name remains unreviewed. */

int FUN_c0340a84(int *param_1)

{
  int iVar1;
  int *piVar2;
  wchar_t *local_a0;
  undefined4 local_9c [3];
  undefined4 auStack_90 [12];
  undefined4 local_60;
  undefined4 local_40;
  undefined1 auStack_3c [40];
  uint local_14;
  
  local_14 = DAT_c034d334;
  FUN_c033af24(auStack_90);
  local_40 = 0;
  memset(auStack_3c,0,0x28);
  memset(local_9c,0,0xc);
  local_a0 = L"$ACLTABLE";
  local_9c[0] = 0xc;
  piVar2 = *(int **)(*(int *)(*param_1 + 0xc) + 0x28);
  iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_a0,0,&local_40);
  if (iVar1 == 2) {
    local_60 = 3;
    iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,&local_40,auStack_90);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,0,&local_40,0,0,auStack_90);
    }
  }
  FUN_c034b674(local_14);
  return iVar1;
}



/* c0340b94 FUN_c0340b94 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0340b94..c0340cbb. Semantic name remains unreviewed. */

int FUN_c0340b94(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int local_40 [2];
  byte local_38 [32];
  uint local_18;
  
  local_18 = DAT_c034d334;
  local_40[1] = 0x14;
  uVar2 = 0x14;
  local_38[0] = 0x20;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0x18] = 0;
  local_38[0x19] = 0;
  local_38[0x1a] = 0;
  local_38[0x1b] = 0;
  local_38[0x1c] = 0;
  local_38[0x1d] = 0;
  local_38[0x1e] = 0;
  local_38[0x1f] = 0;
  iVar1 = GetDeviceUniqueID(L"$ACLTABLE",0x14,1,local_38 + 4,local_40 + 1);
  if (iVar1 < 0) {
    iVar1 = 0x1f;
  }
  else {
    local_40[0] = 0;
    iVar1 = FUN_c033a95c(*(uint **)(param_1 + 4),uVar2,0,0,local_38,0x20,local_40);
    if (iVar1 == 0) {
      uVar4 = 0;
      uVar5 = 0;
      do {
        iVar1 = -0x80000000;
        if ((uVar4 & 1) == 0) {
          iVar1 = 0;
        }
        pbVar3 = local_38 + uVar5;
        uVar5 = uVar5 + 1;
        uVar4 = (uint)*pbVar3 + (uVar4 >> 1) + iVar1;
      } while (uVar5 < 0x20);
      *(uint *)(*(int *)(param_1 + 4) + 0x74) = uVar4;
      *(uint *)(*(int *)(param_1 + 4) + 0x9c) = *(uint *)(*(int *)(param_1 + 4) + 0x9c) | 0x100;
      iVar1 = FUN_c033a618(*(int *)(param_1 + 4),0,0);
    }
  }
  FUN_c034b674(local_18);
  return iVar1;
}



/* c0340cbc FUN_c0340cbc */

/* Boundary evidence: original MIPS .pdata c0340cbc..c0340dd7. Semantic name remains unreviewed. */

undefined4 FUN_c0340cbc(int param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined8 uVar7;
  undefined4 local_30 [2];
  undefined1 auStack_28 [20];
  uint local_14;
  
  local_14 = DAT_c034d334;
  piVar6 = *(int **)(param_1 + 8);
  uVar5 = 0;
  if (*piVar6 == 0x20) {
    uVar7 = FUN_c0338ac4(*(int *)(param_1 + 4));
    uVar3 = 0;
    uVar4 = 0;
    if ((uint)uVar7 != 0) {
      do {
        iVar2 = -0x80000000;
        if ((uVar3 & 1) == 0) {
          iVar2 = 0;
        }
        pbVar1 = (byte *)(*(int *)(param_1 + 8) + uVar4);
        uVar4 = uVar4 + 1;
        uVar3 = (uint)*pbVar1 + (uVar3 >> 1) + iVar2;
      } while (uVar4 < (uint)uVar7);
    }
    if (uVar3 == *(uint *)(*(int *)(param_1 + 4) + 0x74)) {
      local_30[0] = 0x14;
      iVar2 = GetDeviceUniqueID(L"$ACLTABLE",0x14,1,auStack_28,local_30);
      if (iVar2 < 0) {
        uVar5 = 0x1f;
      }
      else {
        iVar2 = memcmp(auStack_28,piVar6 + 1,0x14);
        if (iVar2 != 0) {
          uVar5 = 0x546;
        }
      }
    }
    else {
      uVar5 = 0xb;
    }
  }
  else {
    uVar5 = 0x32;
  }
  FUN_c034b674(local_14);
  return uVar5;
}



/* c0340dd8 FUN_c0340dd8 */

/* Boundary evidence: original MIPS .pdata c0340dd8..c0340f43. Semantic name remains unreviewed. */

int FUN_c0340dd8(int *param_1)

{
  int iVar1;
  LPVOID _Dst;
  SIZE_T SVar2;
  undefined4 uVar3;
  int *piVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined4 local_18 [2];
  
  piVar4 = param_1 + 1;
  iVar1 = FUN_c033fe48(*(int *)(*param_1 + 0xc),L"$ACLTABLE",0x401,0,0,piVar4,(uint *)0x0);
  if (iVar1 != 0) {
    iVar1 = FUN_c0340a84(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_c033fe48(*(int *)(*param_1 + 0xc),L"$ACLTABLE",0x401,0,0,piVar4,(uint *)0x0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  lVar5 = FUN_c0338ac4(*piVar4);
  if ((lVar5 != 0) || (iVar1 = FUN_c0340b94((int)param_1), iVar1 == 0)) {
    *(uint *)(*piVar4 + 0x9c) = *(uint *)(*piVar4 + 0x9c) | 2;
    uVar6 = FUN_c0338ac4(*piVar4);
    if ((int)((ulonglong)uVar6 >> 0x20) == 0) {
      iVar1 = *(int *)(*param_1 + 0x38);
      uVar6 = FUN_c0338ac4(*piVar4);
      SVar2 = (int)uVar6 + iVar1;
      param_1[3] = SVar2;
      _Dst = FUN_c0332264(SVar2);
      param_1[2] = (int)_Dst;
      if (_Dst == (LPVOID)0x0) {
        iVar1 = 8;
      }
      else {
        uVar3 = 0;
        memset(_Dst,0,param_1[3]);
        local_18[0] = 0;
        uVar6 = FUN_c0338ac4(*piVar4);
        iVar1 = FUN_c033a3b0(*piVar4,uVar3,0,0,(void *)param_1[2],(uint)uVar6,local_18);
        if (iVar1 == 0) {
          iVar1 = FUN_c0340cbc((int)param_1);
        }
      }
    }
    else {
      iVar1 = 0xb;
    }
  }
  return iVar1;
}



/* c0340f44 FUN_c0340f44 */

/* Boundary evidence: original MIPS .pdata c0340f44..c0340fa7. Semantic name remains unreviewed. */

undefined4 * FUN_c0340f44(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &PTR_FUN_c0331dac;
  param_1[2] = param_2;
  param_1[3] = 0;
  FUN_c033af04(param_1 + 4);
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0xffffffff;
  param_1[0xd] = 1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  return param_1;
}



/* c0340fa8 FUN_c0340fa8 */

/* Boundary evidence: original MIPS .pdata c0340fa8..c0341007. Semantic name remains unreviewed. */

void FUN_c0340fa8(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[3];
  *param_1 = &PTR_FUN_c0331dac;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,1);
  }
  if ((LPVOID)param_1[10] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[10]);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  return;
}



/* c0341008 FUN_c0341008 */

/* Boundary evidence: original MIPS .pdata c0341008..c03410b7. Semantic name remains unreviewed. */

undefined4 FUN_c0341008(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  undefined8 uVar5;
  
  iVar3 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar3 + 0x3c);
  uVar5 = __ll_lshift(*(undefined4 *)(iVar3 + 0x4c),0,*(undefined1 *)(iVar3 + 0x34));
  puVar4 = (uint *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x18) = uVar5;
  *(undefined8 *)(param_1 + 0x20) = uVar5;
  *puVar4 = *puVar4 | 1;
  puVar1 = FUN_c0332264(0x90);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c0343ce0(puVar1,*(int *)(param_1 + 8),puVar4);
  }
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 8;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c03410b8 FUN_c03410b8 */

/* Boundary evidence: original MIPS .pdata c03410b8..c03410d3. Semantic name remains unreviewed. */

void FUN_c03410b8(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  return;
}



/* c03410d4 FUN_c03410d4 */

/* Boundary evidence: original MIPS .pdata c03410d4..c034110b. Semantic name remains unreviewed. */

void FUN_c03410d4(int *param_1)

{
  (**(code **)(*param_1 + 0x44))(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
  return;
}



/* c034110c FUN_c034110c */

/* Boundary evidence: original MIPS .pdata c034110c..c03411ab. Semantic name remains unreviewed. */

int FUN_c034110c(int *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  
  do {
    if (param_3 <= param_2) {
      if (param_4 == 0) {
        return 0;
      }
      iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_3,0xffffffff,0);
      return iVar1;
    }
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2,param_2 + 1,0);
    param_2 = param_2 + 1;
  } while (iVar1 == 0);
  return iVar1;
}



/* c03411ac FUN_c03411ac */

/* Boundary evidence: original MIPS .pdata c03411ac..c0341447. Semantic name remains unreviewed. */

int FUN_c03411ac(int *param_1,int param_2,undefined4 param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  uint uVar8;
  int local_30;
  uint local_2c;
  
  *param_4 = 0xffffffff;
  if (param_1[0xc] != 0) {
    if (param_2 == -1) {
      param_2 = param_1[0xd];
    }
    uVar2 = param_2 + 1;
    if (param_1[10] == 0) {
      uVar8 = 2;
      if (1 < *(uint *)(param_1[2] + 0x48)) {
        do {
          if (*(uint *)(param_1[2] + 0x48) < uVar2) {
            uVar2 = 2;
          }
          iVar3 = (**(code **)(*param_1 + 0xc))(param_1,uVar2,&local_30);
          if (iVar3 != 0) goto LAB_c034134c;
          if (local_30 == 0) {
            param_1[0xd] = uVar2;
            *param_4 = uVar2;
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = 1;
            }
            goto LAB_c034134c;
          }
          uVar8 = uVar8 + 1;
          uVar2 = uVar2 + 1;
        } while (uVar8 <= *(uint *)(param_1[2] + 0x48));
      }
    }
    else {
      if (*(uint *)(param_1[2] + 0x48) < uVar2) {
        uVar2 = 2;
      }
      piVar6 = (int *)((uVar2 >> 9) * 4 + param_1[10]);
      uVar8 = 0;
      do {
        if (*piVar6 != 0) {
          local_2c = uVar2 >> 7 & 3;
          pcVar7 = (char *)(local_2c + (int)piVar6);
          uVar5 = uVar2 + 0x80 & 0xffffff80;
          uVar4 = uVar2;
          for (; local_2c < 4; local_2c = local_2c + 1) {
            if (*pcVar7 != '\0') {
              uVar1 = *(int *)(param_1[2] + 0x48) + 1;
              if (uVar1 <= uVar5) {
                uVar5 = uVar1;
              }
              for (; uVar4 < uVar5; uVar4 = uVar4 + 1) {
                iVar3 = (**(code **)(*param_1 + 0xc))(param_1,uVar4,&local_30);
                if (iVar3 != 0) goto LAB_c034134c;
                if (local_30 == 0) {
                  param_1[0xd] = uVar4;
                  *param_4 = uVar4;
                  if (param_5 != (undefined4 *)0x0) {
                    *param_5 = 1;
                  }
                  goto LAB_c034134c;
                }
              }
            }
            uVar4 = uVar5;
            pcVar7 = pcVar7 + 1;
            uVar5 = uVar4 + 0x80;
          }
        }
        uVar2 = uVar2 + 0x200 & 0xfffffe00;
        piVar6 = piVar6 + 1;
        uVar8 = uVar8 + 1;
        if (*(uint *)(param_1[2] + 0x48) < uVar2) {
          piVar6 = (int *)param_1[10];
          uVar2 = 2;
        }
      } while (uVar8 <= (uint)param_1[0xb] >> 2);
    }
    param_1[0xc] = 0;
  }
  iVar3 = 0x70;
LAB_c034134c:
  FUN_c033e7c8(param_1[2],0x30,0,*param_4,1,0);
  return iVar3;
}



/* c0341448 FUN_c0341448 */

/* Boundary evidence: original MIPS .pdata c0341448..c0341593. Semantic name remains unreviewed. */

int FUN_c0341448(int *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_res4 [3];
  
  local_res4[0] = param_2;
  if (param_3 == 0 && param_4 == 0) {
    if (1 < param_2) {
      while (local_res4[0] < *(uint *)(param_1[2] + 0x44)) {
        FUN_c033e7c8(param_1[2],0x31,0,local_res4[0],1,0);
        iVar1 = (**(code **)(*param_1 + 0x20))(param_1,local_res4[0],local_res4);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (local_res4[0] < 2) {
          return 0;
        }
      }
    }
  }
  else {
    iVar1 = FUN_c03387fc(param_1[2],param_2,param_3,param_4,1);
    uVar3 = param_2;
    if (param_2 < iVar1 + param_2) {
      do {
        iVar2 = (**(code **)(*param_1 + 0x20))(param_1,uVar3,0);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = uVar3 + 1;
        param_2 = local_res4[0];
      } while (uVar3 < iVar1 + local_res4[0]);
    }
    FUN_c033e7c8(param_1[2],0x31,0,param_2,iVar1,0);
  }
  return 0;
}



/* c0341594 FUN_c0341594 */

/* Boundary evidence: original MIPS .pdata c0341594..c034164b. Semantic name remains unreviewed. */

int FUN_c0341594(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[0xc] == -1) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
    iVar1 = (**(code **)(*param_1 + 0x34))(param_1);
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*param_1 + 0x38))(param_1);
    }
    (**(code **)(*param_1 + 0x44))(param_1);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  *param_2 = param_1[0xc];
  return 0;
}



/* c034164c FUN_c034164c */

/* Boundary evidence: original MIPS .pdata c034164c..c034166f. Semantic name remains unreviewed. */

void FUN_c034164c(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}



/* c0341670 FUN_c0341670 */

/* Boundary evidence: original MIPS .pdata c0341670..c034170b. Semantic name remains unreviewed. */

int FUN_c0341670(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_18 [2];
  
  local_18[0] = 0;
  iVar2 = 0;
  uVar3 = 2;
  if (1 < *(uint *)(param_1[2] + 0x48)) {
    do {
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,uVar3,local_18);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (local_18[0] == 0) {
        iVar2 = iVar2 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 <= *(uint *)(param_1[2] + 0x48));
  }
  param_1[0xc] = iVar2;
  return 0;
}



/* c034170c FUN_c034170c */

/* Boundary evidence: original MIPS .pdata c034170c..c034182f. Semantic name remains unreviewed. */

int FUN_c034170c(int *param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined1 *local_20;
  ushort *local_1c;
  
  *param_3 = 0xffffffff;
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar2 = 0xd;
  }
  else {
    iVar3 = (param_2 >> 1) + param_2;
    iVar2 = (**(code **)(*param_1 + 0x3c))(param_1,iVar3,&local_1c,&local_20);
    if (iVar2 == 0) {
      if ((int)local_20 - (int)local_1c < 2) {
        uVar1 = *local_1c;
        iVar2 = (**(code **)(*param_1 + 0x3c))(param_1,iVar3 + 1,&local_20,0);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar1 = CONCAT11(*local_20,(char)uVar1);
        iVar2 = 0;
      }
      else {
        uVar1 = *local_1c;
      }
      if ((param_2 & 1) != 0) {
        uVar1 = uVar1 >> 4;
      }
      *param_3 = uVar1 & 0xfff;
    }
  }
  return iVar2;
}



/* c0341830 FUN_c0341830 */

/* Boundary evidence: original MIPS .pdata c0341830..c0341a93. Semantic name remains unreviewed. */

int FUN_c0341830(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort *local_30;
  undefined1 *local_2c;
  
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar5 = 0xd;
  }
  else {
    iVar7 = (param_2 >> 1) + param_2;
    iVar5 = (**(code **)(*param_1 + 0x3c))(param_1,iVar7,&local_30,&local_2c);
    if (iVar5 == 0) {
      if ((int)local_2c - (int)local_30 < 2) {
        iVar4 = *(int *)(param_1[3] + 0x10);
        if (iVar4 != 0) {
          InterlockedIncrement((LONG *)(iVar4 + 0x18));
        }
        uVar1 = *local_30;
        iVar5 = (**(code **)(*param_1 + 0x3c))(param_1,iVar7 + 1,&local_2c,0);
        if (iVar5 != 0) {
          if (iVar4 == 0) {
            return iVar5;
          }
          InterlockedDecrement((LONG *)(iVar4 + 0x18));
          return iVar5;
        }
        uVar2 = 0xfff;
        uVar1 = CONCAT11(*local_2c,(char)uVar1);
        uVar3 = (uint)uVar1;
        uVar6 = uVar3;
        if ((param_2 & 1) != 0) {
          param_3 = param_3 << 4;
          uVar2 = 0xfff0;
          uVar6 = (uint)(uVar1 >> 4);
        }
        uVar2 = ~uVar2 & uVar3 | uVar2 & param_3;
        if (uVar2 != uVar3) {
          if ((iVar4 != 0) && (iVar5 = FUN_c0342590(iVar4), iVar5 != 0)) {
            return iVar5;
          }
          *(char *)local_30 = (char)uVar2;
          iVar5 = (**(code **)(*param_1 + 0x40))(param_1);
          if (iVar5 != 0) {
            return iVar5;
          }
          *local_2c = (char)(uVar2 >> 8);
        }
        iVar5 = 0;
        if (iVar4 != 0) {
          InterlockedDecrement((LONG *)(iVar4 + 0x18));
        }
      }
      else {
        uVar2 = (uint)*local_30;
        uVar3 = 0xfff;
        uVar6 = uVar2;
        if ((param_2 & 1) != 0) {
          param_3 = param_3 << 4;
          uVar3 = 0xfff0;
          uVar6 = (uint)(*local_30 >> 4);
        }
        uVar3 = ~uVar3 & uVar2 | uVar3 & param_3;
        if (uVar3 != uVar2) {
          iVar5 = (**(code **)(*param_1 + 0x40))(param_1);
          if (iVar5 != 0) {
            return iVar5;
          }
          *(char *)local_30 = (char)uVar3;
          *(char *)((int)local_30 + 1) = (char)(uVar3 >> 8);
          iVar5 = 0;
        }
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar6 & 0xfff;
      }
    }
  }
  return iVar5;
}



/* c0341a94 FUN_c0341a94 */

/* Boundary evidence: original MIPS .pdata c0341a94..c0341b07. Semantic name remains unreviewed. */

int FUN_c0341a94(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  ushort *local_10 [2];
  
  *param_3 = 0xffffffff;
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar1 = 0xd;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,param_2 << 1,local_10,0);
    if (iVar1 == 0) {
      *param_3 = (uint)*local_10[0];
    }
  }
  return iVar1;
}



/* c0341b08 FUN_c0341b08 */

/* Boundary evidence: original MIPS .pdata c0341b08..c0341bc7. Semantic name remains unreviewed. */

int FUN_c0341b08(int *param_1,uint param_2,ushort param_3,uint *param_4)

{
  ushort uVar1;
  int iVar2;
  ushort *local_20 [2];
  
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar2 = 0xd;
  }
  else {
    iVar2 = (**(code **)(*param_1 + 0x3c))(param_1,param_2 << 1,local_20,0);
    if (iVar2 == 0) {
      uVar1 = *local_20[0];
      if ((uint)uVar1 != (uint)param_3) {
        iVar2 = (**(code **)(*param_1 + 0x40))(param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        *local_20[0] = param_3;
        iVar2 = 0;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = (uint)uVar1;
      }
    }
  }
  return iVar2;
}



/* c0341bc8 FUN_c0341bc8 */

/* Boundary evidence: original MIPS .pdata c0341bc8..c0341c7b. Semantic name remains unreviewed. */

int FUN_c0341bc8(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint *local_18 [2];
  
  *param_3 = 0xffffffff;
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar1 = 0xd;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,param_2 << 2,local_18,0);
    if (iVar1 == 0) {
      if ((*(uint *)(param_1[2] + 0x6c) & 0x20) == 0) {
        *param_3 = *local_18[0] & 0xfffffff;
      }
      else {
        *param_3 = *local_18[0];
      }
    }
  }
  return iVar1;
}



/* c0341c7c FUN_c0341c7c */

/* Boundary evidence: original MIPS .pdata c0341c7c..c0341d63. Semantic name remains unreviewed. */

int FUN_c0341c7c(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint *local_20 [2];
  
  if (*(uint *)(param_1[2] + 0x48) < param_2) {
    iVar1 = 0xd;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,param_2 << 2,local_20,0);
    if (iVar1 == 0) {
      if ((*(uint *)(param_1[2] + 0x6c) & 0x20) == 0) {
        param_3 = param_3 & 0xfffffff;
        uVar2 = *local_20[0] & 0xfffffff;
      }
      else {
        uVar2 = *local_20[0];
      }
      if (uVar2 != param_3) {
        iVar1 = (**(code **)(*param_1 + 0x40))(param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        *local_20[0] = param_3;
        iVar1 = 0;
      }
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar2;
      }
    }
  }
  return iVar1;
}



/* c0341d64 FUN_c0341d64 */

/* Boundary evidence: original MIPS .pdata c0341d64..c0341d8f. Semantic name remains unreviewed. */

void FUN_c0341d64(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  FUN_c03451b8(*(int *)(param_1 + 0xc),param_2,param_2,0,param_3,param_4);
  return;
}



/* c0341d90 FUN_c0341d90 */

/* Boundary evidence: original MIPS .pdata c0341d90..c0341dab. Semantic name remains unreviewed. */

void FUN_c0341d90(int param_1)

{
  FUN_c0344200(*(int *)(param_1 + 0xc));
  return;
}



/* c0341dac FUN_c0341dac */

/* Boundary evidence: original MIPS .pdata c0341dac..c0341dd3. Semantic name remains unreviewed. */

undefined4 FUN_c0341dac(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar1 = FUN_c03441c4(*(int *)(param_1 + 0xc));
  }
  return uVar1;
}



/* c0341dd4 FUN_c0341dd4 */

/* Boundary evidence: original MIPS .pdata c0341dd4..c0341def. Semantic name remains unreviewed. */

void FUN_c0341dd4(int param_1,int param_2)

{
  FUN_c03443d4(*(int *)(param_1 + 0xc),param_2);
  return;
}



/* c0341df0 FUN_c0341df0 */

void FUN_c0341df0(int param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  
  if (*(uint *)(param_1 + 0x30) < *(int *)(*(int *)(param_1 + 8) + 0x48) + 1U) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) + 1;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    pbVar2 = (byte *)((param_2 >> 7) + *(int *)(param_1 + 0x28));
    bVar1 = *pbVar2;
    if (bVar1 < 0x80) {
      *pbVar2 = bVar1 + 1;
    }
  }
  return;
}



/* c0341e4c FUN_c0341e4c */

void FUN_c0341e4c(int param_1,uint param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    pcVar2 = (char *)((param_2 >> 7) + *(int *)(param_1 + 0x28));
    cVar1 = *pcVar2;
    if (cVar1 != '\0') {
      *pcVar2 = cVar1 + -1;
    }
  }
  return;
}



/* c0341e94 FUN_c0341e94 */

/* Boundary evidence: original MIPS .pdata c0341e94..c0341edf. Semantic name remains unreviewed. */

undefined4 * FUN_c0341e94(undefined4 *param_1,uint param_2)

{
  FUN_c0340fa8(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0341ee0 FUN_c0341ee0 */

/* Boundary evidence: original MIPS .pdata c0341ee0..c0341eff. Semantic name remains unreviewed. */

void FUN_c0341ee0(int param_1)

{
  FUN_c03443d4(*(int *)(param_1 + 0xc),1);
  return;
}



/* c0341f00 FUN_c0341f00 */

/* Boundary evidence: original MIPS .pdata c0341f00..c0341f73. Semantic name remains unreviewed. */

int FUN_c0341f00(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1[2] + 0x6c);
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 4) == 0) {
      if ((uVar2 & 8) == 0) {
        iVar1 = 0x57;
      }
      else {
        iVar1 = FUN_c0341bc8(param_1,param_2,param_3);
      }
    }
    else {
      iVar1 = FUN_c0341a94(param_1,param_2,param_3);
    }
  }
  else {
    iVar1 = FUN_c034170c(param_1,param_2,param_3);
  }
  return iVar1;
}



/* c0341f74 FUN_c0341f74 */

/* Boundary evidence: original MIPS .pdata c0341f74..c0342083. Semantic name remains unreviewed. */

int FUN_c0341f74(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_20 [2];
  
  uVar2 = *(uint *)(param_1[2] + 0x6c);
  local_20[0] = 0;
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 4) == 0) {
      if ((uVar2 & 8) == 0) {
        return 0x57;
      }
      iVar1 = FUN_c0341c7c(param_1,param_2,param_3,local_20);
    }
    else {
      iVar1 = FUN_c0341b08(param_1,param_2,(ushort)param_3,local_20);
    }
  }
  else {
    iVar1 = FUN_c0341830(param_1,param_2,param_3,local_20);
  }
  uVar2 = local_20[0];
  if (iVar1 == 0) {
    if (((param_1[0xc] != -1) && (param_3 != local_20[0])) && (local_20[0] == 0)) {
      FUN_c0341e4c((int)param_1,param_2);
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c0342084 FUN_c0342084 */

/* Boundary evidence: original MIPS .pdata c0342084..c034218b. Semantic name remains unreviewed. */

int FUN_c0342084(int *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint local_20 [2];
  
  uVar2 = *(uint *)(param_1[2] + 0x6c);
  local_20[0] = 0;
  if ((uVar2 & 2) == 0) {
    if ((uVar2 & 4) == 0) {
      if ((uVar2 & 8) == 0) {
        return 0x57;
      }
      iVar1 = FUN_c0341c7c(param_1,param_2,0,local_20);
    }
    else {
      iVar1 = FUN_c0341b08(param_1,param_2,0,local_20);
    }
  }
  else {
    iVar1 = FUN_c0341830(param_1,param_2,0,local_20);
  }
  uVar2 = local_20[0];
  if (iVar1 == 0) {
    if ((param_1[0xc] != -1) && (local_20[0] != 0)) {
      FUN_c0341df0((int)param_1,param_2);
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = uVar2;
    }
    iVar1 = FUN_c0335190(param_1[2],param_2,1);
  }
  return iVar1;
}



/* c034218c FUN_c034218c */

/* Boundary evidence: original MIPS .pdata c034218c..c034243f. Semantic name remains unreviewed. */

int FUN_c034218c(int param_1)

{
  bool bVar1;
  undefined1 uVar2;
  uint dwSize;
  int iVar3;
  int *lpAddress;
  LPVOID _Dst;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_30;
  
  iVar6 = *(int *)(param_1 + 8);
  uVar2 = *(undefined1 *)(iVar6 + 0x34);
  iVar7 = *(int *)(iVar6 + 0x4c);
  dwSize = __ll_lshift(iVar7,0,uVar2);
  bVar1 = (*(uint *)(iVar6 + 0x6c) & 4) == 0;
  if (((*(uint *)(iVar6 + 0x6c) & 2) == 0) && (iVar3 = __ull_rshift(dwSize,0,uVar2), iVar3 == iVar7)
     ) {
    uVar9 = 4;
    uVar10 = 2;
    if (!bVar1) {
      uVar9 = 2;
    }
    if (uVar9 == 0) {
      trap(0x1c00);
    }
    if (*(uint *)(iVar6 + 0x48) <= dwSize / uVar9) {
      if (0x3ffff < dwSize) {
        dwSize = 0x40000;
      }
      lpAddress = VirtualAlloc((LPVOID)0x0,dwSize,0x1000,4);
      if (lpAddress != (int *)0x0) {
        uVar5 = (*(int *)(*(int *)(param_1 + 8) + 0x48) + 0x80U >> 7) + 3 & 0xfffffffc;
        *(uint *)(param_1 + 0x2c) = uVar5;
        _Dst = FUN_c0332264(uVar5);
        *(LPVOID *)(param_1 + 0x28) = _Dst;
        if (_Dst != (LPVOID)0x0) {
          memset(_Dst,0,*(size_t *)(param_1 + 0x2c));
        }
        iVar7 = *(int *)(param_1 + 8);
        uVar5 = *(uint *)(iVar7 + 0x3c);
        iVar6 = __ull_rshift(dwSize,0,*(undefined1 *)(iVar7 + 0x34));
        iVar7 = FUN_c0335074(iVar7,uVar5,iVar6,lpAddress,0);
        if (iVar7 == 0) {
          *(undefined4 *)(param_1 + 0x30) = 0;
          piVar8 = (int *)(uVar9 * 2 + (int)lpAddress);
          local_30 = iVar6;
          if (1 < *(uint *)(*(int *)(param_1 + 8) + 0x48)) {
            do {
              if (dwSize <= (uint)((int)piVar8 - (int)lpAddress)) {
                iVar7 = *(int *)(param_1 + 8);
                uVar4 = __ull_rshift(0x40000,0,*(undefined1 *)(iVar7 + 0x34));
                uVar11 = *(int *)(iVar7 + 0x4c) - iVar6;
                if (uVar4 <= uVar11) {
                  uVar11 = uVar4;
                }
                iVar7 = FUN_c0335074(iVar7,local_30 + uVar5,uVar11,lpAddress,0);
                if (iVar7 != 0) break;
                iVar6 = uVar11 + local_30;
                piVar8 = lpAddress;
                local_30 = iVar6;
              }
              if (bVar1) {
                if (*piVar8 == 0) goto LAB_c03423d8;
              }
              else if ((short)*piVar8 == 0) {
LAB_c03423d8:
                FUN_c0341df0(param_1,uVar10);
              }
              uVar10 = uVar10 + 1;
              piVar8 = (int *)(uVar9 + (int)piVar8);
            } while (uVar10 <= *(uint *)(*(int *)(param_1 + 8) + 0x48));
          }
        }
        VirtualFree(lpAddress,0,0x8000);
        return iVar7;
      }
    }
  }
  return 0x1f;
}



/* c0342440 FUN_c0342440 */

/* Boundary evidence: original MIPS .pdata c0342440..c0342497. Semantic name remains unreviewed. */

undefined4 * FUN_c0342440(undefined4 *param_1,undefined4 param_2)

{
  FUN_c0333b60(param_1);
  *param_1 = &PTR_FUN_c0331e80;
  param_1[9] = param_2;
  param_1[10] = 0;
  param_1[0xb] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return param_1;
}



/* c0342498 FUN_c0342498 */

/* Boundary evidence: original MIPS .pdata c0342498..c03424e7. Semantic name remains unreviewed. */

void FUN_c0342498(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0331e80;
  VirtualFree((LPVOID)param_1[0xb],0,0x8000);
  param_1[0xb] = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  FUN_c0333d90(param_1);
  return;
}



/* c03424e8 FUN_c03424e8 */

/* Boundary evidence: original MIPS .pdata c03424e8..c0342567. Semantic name remains unreviewed. */

undefined4 FUN_c03424e8(int param_1,int param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (iVar1 = FUN_c0333ba4(param_1); iVar1 != 0; iVar1 = FUN_c0333bc8(param_1,iVar1)) {
    if (*(int *)(iVar1 + 0xc) == param_2) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}



/* c0342568 FUN_c0342568 */

/* Boundary evidence: original MIPS .pdata c0342568..c034258f. Semantic name remains unreviewed. */

undefined4 FUN_c0342568(int param_1,int param_2)

{
  if (param_2 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  return 0;
}



/* c0342590 FUN_c0342590 */

undefined4 FUN_c0342590(int param_1)

{
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x80;
  return 0;
}



/* c03425a4 FUN_c03425a4 */

/* Boundary evidence: original MIPS .pdata c03425a4..c03425ef. Semantic name remains unreviewed. */

undefined4 * FUN_c03425a4(undefined4 *param_1,uint param_2)

{
  FUN_c0342498(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03425f0 FUN_c03425f0 */

/* Boundary evidence: original MIPS .pdata c03425f0..c03427b7. Semantic name remains unreviewed. */

undefined4 FUN_c03425f0(int param_1)

{
  LPVOID pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  
  uVar6 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  puVar7 = (uint *)(param_1 + 0x28);
  FUN_c033451c(*(int *)(param_1 + 0x24));
  uVar5 = *puVar7;
  uVar4 = 1 << (*(byte *)(*(int *)(param_1 + 0x24) + 0x34) & 0x1f);
  uVar3 = uVar5 * uVar4;
  if (uVar4 == 0) {
    trap(0x1c00);
  }
  if (uVar3 / uVar4 == uVar5) {
    if (((uVar5 < 4) || ((uVar5 & 3) != 0)) || ((uVar3 & 0xfff) != 0)) {
      *puVar7 = 0x40;
      uVar4 = 1 << (*(byte *)(*(int *)(param_1 + 0x24) + 0x34) & 0x1f);
      uVar3 = uVar4 << 6;
      if (uVar4 == 0) {
        trap(0x1c00);
      }
      if (uVar3 / uVar4 != 0x40) goto LAB_c034267c;
    }
    pvVar1 = VirtualAlloc((LPVOID)0x0,uVar3,0x3000,4);
    *(LPVOID *)(param_1 + 0x2c) = pvVar1;
    if (pvVar1 == (LPVOID)0x0) {
LAB_c034277c:
      uVar6 = 8;
    }
    else {
      uVar3 = 0;
      if (*puVar7 != 0) {
        do {
          puVar2 = FUN_c0332264(0x20);
          if (puVar2 == (undefined4 *)0x0) {
            puVar2 = (undefined4 *)0x0;
          }
          else {
            puVar2[1] = 0;
            puVar2[2] = 0;
            *puVar2 = &PTR_FUN_c0331e84;
            puVar2[3] = 0;
            puVar2[4] = 0;
            puVar2[5] = pvVar1;
            puVar2[6] = 0;
            puVar2[7] = 0;
          }
          if (puVar2 == (undefined4 *)0x0) goto LAB_c034277c;
          pvVar1 = (LPVOID)((1 << (*(byte *)(*(int *)(param_1 + 0x24) + 0x34) & 0x1f)) + (int)pvVar1
                           );
          FUN_c0333bec(param_1,(int)puVar2);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *puVar7);
      }
    }
  }
  else {
LAB_c034267c:
    uVar6 = 0x57;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return uVar6;
}



/* c03427b8 FUN_c03427b8 */

/* Boundary evidence: original MIPS .pdata c03427b8..c0342993. Semantic name remains unreviewed. */

int FUN_c03427b8(int param_1,int param_2,uint param_3,uint param_4,uint param_5,uint *param_6,
                int *param_7,int param_8,int param_9)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_30;
  int local_2c;
  
  local_30 = 0;
  local_2c = 0;
  if ((((1 << (*(byte *)(*(int *)(param_1 + 0x24) + 0x34) & 0x1f)) - 1U & param_3) == 0) &&
     (iVar4 = FUN_c034506c(param_2,param_2,param_3,param_4,param_5,0,(int *)&local_30,&local_2c),
     local_2c != 0)) {
    uVar5 = local_2c + local_30;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    if (param_9 == 0) {
      iVar1 = FUN_c0333ba4(param_1);
      while (iVar1 != 0) {
        uVar3 = *(uint *)(iVar1 + 0x1c);
        uVar6 = uVar5;
        if ((((uVar3 & 8) == 0) && (uVar2 = *(uint *)(iVar1 + 0x10), local_30 <= uVar2)) &&
           (uVar2 < uVar5)) {
          if ((local_2c == 1) && (uVar2 == local_30)) {
            iVar4 = 0x1f;
            goto LAB_c034294c;
          }
          if (param_8 == 0) {
            if (((uVar3 & 0x80) != 0) && (uVar6 = uVar2, uVar2 == local_30)) {
              iVar4 = 0x1f;
              break;
            }
          }
          else {
            *(undefined4 *)(iVar1 + 0xc) = 0;
            *(undefined4 *)(iVar1 + 0x10) = 0;
            *(uint *)(iVar1 + 0x1c) = uVar3 & 0xffffff7f | 8;
            if (*(int *)(param_2 + 0x10) == iVar1) {
              FUN_c03441c4(param_2);
            }
          }
        }
        iVar1 = FUN_c0333bc8(param_1,iVar1);
        uVar5 = uVar6;
      }
    }
    if (iVar4 == 0) {
      *param_6 = local_30;
      *param_7 = uVar5 - local_30;
      if (param_8 != 0) {
        return 0;
      }
    }
LAB_c034294c:
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  }
  else {
    iVar4 = 0x57;
  }
  return iVar4;
}



/* c0342994 FUN_c0342994 */

/* Boundary evidence: original MIPS .pdata c0342994..c0342a87. Semantic name remains unreviewed. */

undefined4 FUN_c0342994(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (iVar1 = FUN_c0333ba4(param_1); iVar1 != 0; iVar1 = FUN_c0333bc8(param_1,iVar1)) {
    if ((*(uint *)(iVar1 + 0x1c) & 8) == 0) {
      uVar2 = *(uint *)(iVar1 + 0x10);
      if ((uVar2 < param_3) || (param_3 + param_4 <= uVar2)) {
        if ((param_2 <= uVar2) && (uVar2 < param_2 + param_4)) {
          *(uint *)(iVar1 + 0x10) = (uVar2 - param_2) + param_3;
        }
      }
      else {
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 8;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return 0;
}



/* c0342a88 FUN_c0342a88 */

/* Boundary evidence: original MIPS .pdata c0342a88..c0342b47. Semantic name remains unreviewed. */

void FUN_c0342a88(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (iVar1 = FUN_c0333ba4(param_1); iVar1 != 0; iVar1 = FUN_c0333bc8(param_1,iVar1)) {
    if ((((*(uint *)(iVar1 + 0x1c) & 8) == 0) && (param_2 <= *(uint *)(iVar1 + 0x10))) &&
       (*(uint *)(iVar1 + 0x10) < param_2 + param_3)) {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) & 0xffffff7f | 8;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return;
}



/* c0342b48 FUN_c0342b48 */

/* Boundary evidence: original MIPS .pdata c0342b48..c0342b8b. Semantic name remains unreviewed. */

undefined4 * FUN_c0342b48(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c033161c;
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0342b8c FUN_c0342b8c */

/* Boundary evidence: original MIPS .pdata c0342b8c..c0342c57. Semantic name remains unreviewed. */

int FUN_c0342b8c(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((*(uint *)(param_1 + 0x1c) & 8) == 0) && ((*(uint *)(param_1 + 0x1c) & 0x80) != 0)) {
    InterlockedIncrement((LONG *)(param_1 + 0x18));
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xffffff7f;
    uVar2 = 4;
    if (param_3 == 0) {
      uVar2 = 0;
    }
    iVar1 = FUN_c03350a8(param_2,*(uint *)(param_1 + 0x10),1,*(undefined4 *)(param_1 + 0x14),uVar2);
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 8;
    }
    InterlockedDecrement((LONG *)(param_1 + 0x18));
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0342c58 FUN_c0342c58 */

/* Boundary evidence: original MIPS .pdata c0342c58..c0342e5b. Semantic name remains unreviewed. */

int FUN_c0342c58(int param_1,uint param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  if ((param_3 == 0) || (iVar3 = *(int *)(param_3 + 0x10), iVar3 == 0)) {
LAB_c0342cd8:
    iVar1 = FUN_c0333ba4(param_1);
    iVar4 = 0;
    if (iVar1 != 0) {
      do {
        uVar2 = *(uint *)(iVar1 + 0x1c);
        if (((uVar2 & 0x18) == 0) && (iVar3 = iVar1, *(uint *)(iVar1 + 0x10) == param_2))
        goto LAB_c0342dd8;
        iVar3 = iVar4;
        if ((((uVar2 & 0x10) != 0) || (*(int *)(iVar1 + 0x18) == 0)) &&
           (((iVar4 == 0 || ((uVar2 & 0x80) == 0)) || ((*(uint *)(iVar4 + 0x1c) & 0x80) != 0)))) {
          iVar3 = iVar1;
        }
        iVar1 = FUN_c0333bc8(param_1,iVar1);
        iVar4 = iVar3;
      } while (iVar1 != 0);
      if (iVar3 != 0) {
        iVar5 = FUN_c0342b8c(iVar3,*(int *)(param_1 + 0x24),0);
        if (iVar5 != 0) goto LAB_c0342e24;
        *(uint *)(iVar3 + 0x10) = param_2;
        *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xffffffe7;
        if (param_4 == 0) {
          iVar5 = FUN_c0335074(*(int *)(param_1 + 0x24),param_2,1,*(undefined4 *)(iVar3 + 0x14),0);
          if (iVar5 != 0) {
            *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | 8;
            goto LAB_c0342e24;
          }
        }
LAB_c0342dd8:
        FUN_c0333c6c(param_1,iVar3);
        FUN_c0333bec(param_1,iVar3);
        goto LAB_c0342df0;
      }
    }
    iVar5 = 0x7a;
  }
  else {
    if (((*(uint *)(iVar3 + 0x1c) & 8) != 0) || (*(uint *)(iVar3 + 0x10) != param_2)) {
      FUN_c03441c4(param_3);
      goto LAB_c0342cd8;
    }
LAB_c0342df0:
    if (param_3 == 0) {
      InterlockedIncrement((LONG *)(iVar3 + 0x18));
    }
    else {
      FUN_c0344148(param_3,iVar3);
    }
    *param_5 = iVar3;
  }
LAB_c0342e24:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return iVar5;
}



/* c0342e5c FUN_c0342e5c */

/* Boundary evidence: original MIPS .pdata c0342e5c..c0342f53. Semantic name remains unreviewed. */

int FUN_c0342e5c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  for (iVar1 = FUN_c0333be4(param_1); iVar1 != 0; iVar1 = FUN_c0333bac(param_1,iVar1)) {
    if (((param_2 == 0) || (*(int *)(iVar1 + 0xc) == param_2)) && (*(int *)(iVar1 + 0x18) == 0)) {
      iVar2 = FUN_c0342b8c(iVar1,*(int *)(param_1 + 0x24),param_3);
      if (iVar2 != 0) {
        iVar3 = iVar2;
      }
      if (param_4 != 0) {
        *(undefined4 *)(iVar1 + 0xc) = 0;
        *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 8;
        *(undefined4 *)(iVar1 + 0x10) = 0;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
  return iVar3;
}



/* c0342f54 FUN_c0342f54 */

/* Boundary evidence: original MIPS .pdata c0342f54..c0342f8f. Semantic name remains unreviewed. */

undefined4 * FUN_c0342f54(undefined4 *param_1,undefined4 param_2)

{
  FUN_c0340f44(param_1,param_2);
  *param_1 = &PTR_FUN_c0331efc;
  param_1[0x14] = 0;
  return param_1;
}



/* c0342f90 FUN_c0342f90 */

/* Boundary evidence: original MIPS .pdata c0342f90..c0342fb3. Semantic name remains unreviewed. */

void FUN_c0342f90(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0331efc;
  FUN_c0340fa8(param_1);
  return;
}



/* c0342fb4 FUN_c0342fb4 */

/* Boundary evidence: original MIPS .pdata c0342fb4..c034301b. Semantic name remains unreviewed. */

int FUN_c0342fb4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0341008(param_1);
  if (iVar1 == 0) {
    iVar2 = FUN_c033fe48(*(int *)(*(int *)(param_1 + 8) + 0xc),L"$BITMAP0",0x401,0,0,
                         (undefined4 *)(param_1 + 0x50),(uint *)0x0);
    iVar1 = 0;
    if (iVar2 != 0) {
      iVar1 = 0xb;
    }
  }
  return iVar1;
}



/* c034301c FUN_c034301c */

/* Boundary evidence: original MIPS .pdata c034301c..c0343057. Semantic name remains unreviewed. */

void FUN_c034301c(int param_1)

{
  FUN_c033f954(*(int *)(*(int *)(param_1 + 8) + 0xc),*(int **)(param_1 + 0x50),1);
  FUN_c0341ee0(param_1);
  return;
}



/* c0343058 FUN_c0343058 */

/* Boundary evidence: original MIPS .pdata c0343058..c0343073. Semantic name remains unreviewed. */

void FUN_c0343058(int *param_1,uint param_2,uint *param_3)

{
  FUN_c0341bc8(param_1,param_2,param_3);
  return;
}



/* c0343074 FUN_c0343074 */

/* Boundary evidence: original MIPS .pdata c0343074..c0343297. Semantic name remains unreviewed. */

int FUN_c0343074(int *param_1,int param_2,uint param_3,int *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  uVar2 = 0;
  uVar4 = 0;
  if (param_1[0xc] != 0) {
    if (param_2 == -1) {
      param_2 = param_1[0xd];
    }
    local_38 = 0;
    uVar6 = param_2 + 1;
    uVar8 = 2;
    iVar1 = 0;
    iVar7 = 0;
    local_2c = param_3;
    if (1 < *(uint *)(param_1[2] + 0x48)) {
      do {
        iVar3 = iVar1;
        uVar5 = uVar4;
        if (*(uint *)(param_1[2] + 0x48) < uVar6) {
          local_38 = 0;
          uVar6 = 2;
          if (uVar4 < uVar2) {
            uVar5 = uVar2;
            iVar7 = iVar3;
          }
          uVar2 = 0;
        }
        local_30 = 0;
        local_34 = 0;
        if (uVar6 < local_38) {
LAB_c034317c:
          iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,uVar6,&local_30);
          if (iVar1 != 0) {
            return iVar1;
          }
          uVar6 = uVar6 + 1;
          uVar8 = uVar8 + 1;
        }
        else {
          iVar1 = (**(code **)(*param_1 + 0x50))(param_1,uVar6,&local_38,&local_34);
          if (iVar1 != 0) {
            return iVar1;
          }
          if (local_34 == 0) goto LAB_c034317c;
          uVar8 = local_34 + uVar8;
          uVar6 = local_34 + uVar6;
        }
        if (local_30 == 0) {
          if (uVar5 < uVar2) {
            uVar5 = uVar2;
            iVar7 = iVar3;
          }
          uVar2 = 0;
          iVar1 = iVar3;
        }
        else {
          if (uVar2 == 0) {
            iVar3 = uVar6 - 1;
          }
          uVar4 = uVar2 + 1;
          uVar2 = uVar4;
          iVar1 = iVar3;
          if (uVar4 == local_2c) {
            iVar1 = uVar4 + iVar3;
            goto LAB_c0343220;
          }
        }
        iVar3 = iVar7;
        uVar4 = uVar5;
        iVar7 = iVar3;
      } while (uVar8 <= *(uint *)(param_1[2] + 0x48));
      if (uVar4 != 0) {
        iVar1 = uVar4 + iVar3;
LAB_c0343220:
        param_1[0xd] = iVar1 + -1;
        *param_4 = iVar3;
        if (param_5 != (uint *)0x0) {
          *param_5 = uVar4;
        }
        FUN_c033e7c8(param_1[2],0x30,0,iVar3,uVar4,0);
        return 0;
      }
    }
    param_1[0xc] = 0;
  }
  return 0x70;
}



/* c0343298 FUN_c0343298 */

/* Boundary evidence: original MIPS .pdata c0343298..c034336b. Semantic name remains unreviewed. */

int FUN_c0343298(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  SIZE_T SVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x50) + 0x10);
  uVar1 = FUN_c0344228(iVar4,param_2);
  if (uVar1 < 0x20000000) {
    SVar3 = uVar1 << 3;
  }
  else {
    SVar3 = 0xffffffff;
  }
  puVar2 = FUN_c0332264(SVar3);
  if (puVar2 == (undefined4 *)0x0) {
    iVar4 = 8;
  }
  else {
    iVar4 = FUN_c0344ea0(iVar4,puVar2);
    if (iVar4 == 0) {
      *param_2 = *puVar2;
      *param_3 = puVar2[1];
      *param_4 = 0;
      *param_5 = 0;
    }
    FUN_c03322a0(puVar2);
  }
  return iVar4;
}



/* c034336c FUN_c034336c */

/* Boundary evidence: original MIPS .pdata c034336c..c034347f. Semantic name remains unreviewed. */

void FUN_c034336c(int param_1,int param_2,uint *param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *local_28;
  int *local_24;
  
  uVar3 = param_2 - 2U >> 3 & 0x1ffffffc;
  *param_4 = 0;
  local_28 = (int *)0x0;
  local_24 = (int *)0x0;
  uVar4 = uVar3 * 8 + 0x22;
  bVar1 = false;
  iVar2 = FUN_c03451b8(*(int *)(*(int *)(param_1 + 0x50) + 0x10),param_2,uVar3,0,(int *)&local_28,
                       (int *)&local_24);
  if (iVar2 == 0) {
    if (local_28 < local_24) {
      do {
        if ((*local_28 != -1) || (*(uint *)(*(int *)(param_1 + 8) + 0x48) < uVar4)) break;
        local_28 = local_28 + 1;
        uVar4 = uVar4 + 0x20;
        bVar1 = true;
      } while (local_28 < local_24);
      if (bVar1) {
        *param_4 = (uVar4 - param_2) + -0x20;
      }
    }
  }
  *param_3 = uVar4;
  return;
}



/* c0343480 FUN_c0343480 */

/* Boundary evidence: original MIPS .pdata c0343480..c03434e3. Semantic name remains unreviewed. */

void FUN_c0343480(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte *local_10 [2];
  
  local_10[0] = (byte *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,param_2,param_3 - 2U >> 3,local_10);
  if (iVar1 == 0) {
    *local_10[0] = (byte)(1 << (param_3 - 2U & 7)) | *local_10[0];
  }
  return;
}



/* c03434e4 FUN_c03434e4 */

/* Boundary evidence: original MIPS .pdata c03434e4..c034354b. Semantic name remains unreviewed. */

void FUN_c03434e4(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte *local_10 [2];
  
  local_10[0] = (byte *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x58))(param_1,param_2,param_3 - 2U >> 3,local_10);
  if (iVar1 == 0) {
    *local_10[0] = ~(byte)(1 << (param_3 - 2U & 7)) & *local_10[0];
  }
  return;
}



/* c034354c FUN_c034354c */

/* Boundary evidence: original MIPS .pdata c034354c..c03435c7. Semantic name remains unreviewed. */

void FUN_c034354c(int *param_1,undefined4 param_2,int param_3,uint *param_4)

{
  int iVar1;
  byte *local_18 [2];
  
  local_18[0] = (byte *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x54))(param_1,param_2,param_3 - 2U >> 3,local_18);
  if (iVar1 == 0) {
    *param_4 = (uint)((1 << (param_3 - 2U & 7) & (uint)*local_18[0]) != 0);
  }
  return;
}



/* c03435c8 FUN_c03435c8 */

/* Boundary evidence: original MIPS .pdata c03435c8..c03435ef. Semantic name remains unreviewed. */

void FUN_c03435c8(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  FUN_c03451b8(*(int *)(param_2 + 0x10),param_2,param_3,0,param_4,(int *)0x0);
  return;
}



/* c03435f0 FUN_c03435f0 */

/* Boundary evidence: original MIPS .pdata c03435f0..c0343643. Semantic name remains unreviewed. */

int FUN_c03435f0(undefined4 param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = FUN_c03451b8(*(int *)(param_2 + 0x10),param_2,param_3,0,param_4,(int *)0x0);
  if (iVar1 == 0) {
    FUN_c0344200(*(int *)(param_2 + 0x10));
  }
  return iVar1;
}



/* c0343644 FUN_c0343644 */

/* Boundary evidence: original MIPS .pdata c0343644..c03436cb. Semantic name remains unreviewed. */

int FUN_c0343644(undefined4 param_1,void *param_2,uint param_3,uint param_4,void *param_5,
                uint param_6,int *param_7)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)((int)param_2 + 0xa0));
  iVar1 = FUN_c034522c(*(int *)((int)param_2 + 0x10),pvVar2,param_3,param_4,param_5,param_6,0,
                       param_7);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_2 + 0xa0));
  return iVar1;
}



/* c03436cc FUN_c03436cc */

/* Boundary evidence: original MIPS .pdata c03436cc..c0343753. Semantic name remains unreviewed. */

int FUN_c03436cc(undefined4 param_1,void *param_2,uint param_3,uint param_4,void *param_5,
                uint param_6,int *param_7)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)((int)param_2 + 0xa0));
  iVar1 = FUN_c0345604(*(int *)((int)param_2 + 0x10),pvVar2,param_3,param_4,param_5,param_6,0,
                       param_7);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)param_2 + 0xa0));
  return iVar1;
}



/* c0343754 FUN_c0343754 */

/* Boundary evidence: original MIPS .pdata c0343754..c03437bf. Semantic name remains unreviewed. */

int FUN_c0343754(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0338b2c(*(int *)(param_1 + 0x50),param_2);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  iVar1 = FUN_c0341dd4(param_1,param_2);
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}



/* c03437c0 FUN_c03437c0 */

/* Boundary evidence: original MIPS .pdata c03437c0..c03437fb. Semantic name remains unreviewed. */

void FUN_c03437c0(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_c03441c4(*(int *)(*(int *)(param_1 + 0x50) + 0x10));
  }
  FUN_c0341dac(param_1);
  return;
}



/* c03437fc FUN_c03437fc */

/* Boundary evidence: original MIPS .pdata c03437fc..c0343853. Semantic name remains unreviewed. */

undefined4 * FUN_c03437fc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0331efc;
  FUN_c0340fa8(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0343854 FUN_c0343854 */

/* Boundary evidence: original MIPS .pdata c0343854..c034391b. Semantic name remains unreviewed. */

void FUN_c0343854(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  iVar1 = FUN_c0341c7c(param_1,param_2,param_3,&local_14);
  if (iVar1 == 0) {
    if (param_1[0xc] != -1) {
      local_18 = 0;
      iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,&local_18);
      if (iVar1 != 0) {
        return;
      }
      if (local_18 == 0) {
        param_1[0xc] = param_1[0xc] + -1;
      }
    }
    iVar1 = FUN_c0343480(param_1,param_1[0x14],param_2);
    if ((iVar1 == 0) && (param_4 != (uint *)0x0)) {
      *param_4 = local_14;
    }
  }
  return;
}



/* c034391c FUN_c034391c */

/* Boundary evidence: original MIPS .pdata c034391c..c034399f. Semantic name remains unreviewed. */

void FUN_c034391c(int *param_1,int param_2)

{
  int iVar1;
  uint local_18 [2];
  
  if (param_1[0xc] != -1) {
    local_18[0] = 0;
    iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,local_18);
    if (iVar1 != 0) {
      return;
    }
    if (local_18[0] == 0) {
      param_1[0xc] = param_1[0xc] + -1;
    }
  }
  FUN_c0343480(param_1,param_1[0x14],param_2);
  return;
}



/* c03439a0 FUN_c03439a0 */

/* Boundary evidence: original MIPS .pdata c03439a0..c0343a6f. Semantic name remains unreviewed. */

void FUN_c03439a0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint local_18 [2];
  
  if (param_1[0xc] != -1) {
    local_18[0] = 0;
    iVar1 = FUN_c034354c(param_1,param_1[0x14],param_2,local_18);
    if (iVar1 != 0) {
      return;
    }
    if (local_18[0] != 0) {
      param_1[0xc] = param_1[0xc] + 1;
    }
  }
  iVar1 = FUN_c03434e4(param_1,param_1[0x14],param_2);
  if ((iVar1 == 0) &&
     ((param_3 == 0 || (iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2,param_3), iVar1 == 0))
     )) {
    FUN_c0335190(param_1[2],param_2,1);
  }
  return;
}



/* c0343a70 FUN_c0343a70 */

/* WARNING: Removing unreachable block (ram,0xc0343b88) */
/* Boundary evidence: original MIPS .pdata c0343a70..c0343bff. Semantic name remains unreviewed. */

int FUN_c0343a70(int param_1)

{
  ulonglong uVar1;
  LPVOID lpAddress;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint local_30;
  undefined4 local_2c;
  
  iVar3 = 0;
  uVar4 = 0;
  uVar5 = 0;
  uVar6 = 0;
  uVar7 = FUN_c0338ac4(*(int *)(param_1 + 0x50));
  if (((int)(uVar7 >> 0x20) != 0) || (uVar1 = uVar7, 0x3ffff < (uint)uVar7)) {
    uVar1 = 0x40000;
  }
  local_2c = (undefined4)(uVar1 >> 0x20);
  lpAddress = VirtualAlloc((LPVOID)0x0,(SIZE_T)uVar1,0x1000,4);
  if (lpAddress == (LPVOID)0x0) {
    iVar3 = 0x1f;
  }
  else {
    if (uVar7 != 0) {
      do {
        local_30 = 0;
        iVar3 = FUN_c0343644(param_1,*(void **)(param_1 + 0x50),uVar5,uVar6,lpAddress,(SIZE_T)uVar1,
                             (int *)&local_30);
        if (iVar3 != 0) goto LAB_c0343bbc;
        iVar2 = FUN_c033b89c((int)lpAddress,local_30);
        uVar5 = local_30 + uVar5;
        uVar6 = uVar6 + (uVar5 < local_30);
        uVar4 = iVar2 + uVar4;
      } while (CONCAT44(uVar6,uVar5) < uVar7);
    }
    uVar5 = *(int *)(*(int *)(param_1 + 8) + 0x48) - 1;
    if (uVar5 < uVar4) {
      iVar3 = 0xb;
    }
    else {
      *(uint *)(param_1 + 0x30) = uVar5 - uVar4;
    }
LAB_c0343bbc:
    VirtualFree(lpAddress,0,0x8000);
  }
  return iVar3;
}



/* c0343c00 FUN_c0343c00 */

/* Boundary evidence: original MIPS .pdata c0343c00..c0343c97. Semantic name remains unreviewed. */

int FUN_c0343c00(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_18 [2];
  
  iVar2 = 0;
  uVar3 = 2;
  if (1 < *(uint *)(param_1[2] + 0x48)) {
    do {
      local_18[0] = 0;
      iVar1 = FUN_c034354c(param_1,param_1[0x14],uVar3,local_18);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (local_18[0] == 0) {
        iVar2 = iVar2 + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 <= *(uint *)(param_1[2] + 0x48));
  }
  param_1[0xc] = iVar2;
  return 0;
}



/* c0343c98 FUN_c0343c98 */

/* Boundary evidence: original MIPS .pdata c0343c98..c0343cdf. Semantic name remains unreviewed. */

void FUN_c0343c98(int *param_1,int param_2,uint *param_3)

{
  uint local_10 [2];
  
  local_10[0] = 0;
  FUN_c034354c(param_1,param_1[0x14],param_2,local_10);
  *param_3 = (uint)(local_10[0] == 0);
  return;
}



/* c0343ce0 FUN_c0343ce0 */

/* Boundary evidence: original MIPS .pdata c0343ce0..c0343d2f. Semantic name remains unreviewed. */

undefined4 * FUN_c0343ce0(undefined4 *param_1,int param_2,uint *param_3)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_FUN_c0331fcc;
  param_1[3] = param_2;
  param_1[4] = 0;
  param_1[5] = param_3;
  FUN_c034618c(param_1 + 6,param_2,param_3);
  param_1[0x22] = 0;
  return param_1;
}



/* c0343d30 FUN_c0343d30 */

/* Boundary evidence: original MIPS .pdata c0343d30..c0343d7f. Semantic name remains unreviewed. */

void FUN_c0343d30(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0331fcc;
  if (*(int *)(param_1[3] + 0x10) != 0) {
    FUN_c03424e8(*(int *)(param_1[3] + 0x10),(int)param_1);
  }
  *param_1 = &PTR_FUN_c033161c;
  return;
}



/* c0343d80 FUN_c0343d80 */

/* Boundary evidence: original MIPS .pdata c0343d80..c0343dbb. Semantic name remains unreviewed. */

undefined4 FUN_c0343d80(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
    uVar1 = FUN_c0346030((int *)(param_1 + 0x18),param_2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0343dbc FUN_c0343dbc */

/* Boundary evidence: original MIPS .pdata c0343dbc..c0344043. Semantic name remains unreviewed. */

int FUN_c0343dbc(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int local_30 [2];
  
  local_30[0] = 0;
  piVar7 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  uVar8 = 0;
  uVar9 = 0;
  if (param_5 == 0) {
    local_30[0] = *(int *)(*(int *)(param_1 + 0x14) + 4);
    *(undefined4 *)(*(int *)(param_1 + 0x14) + 4) = 0xffffffff;
    puVar3 = *(uint **)(param_1 + 0x14);
    if ((*puVar3 & 2) != 0) {
      uVar8 = puVar3[2];
      uVar9 = puVar3[3];
    }
  }
  else {
    puVar3 = *(uint **)(param_1 + 0x14);
    if ((*puVar3 & 2) == 0) {
      iVar2 = (**(code **)(*piVar7 + 0x10))(piVar7,param_5,0xffffffff,local_30);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      local_30[0] = param_5 + 1;
      uVar9 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
      uVar4 = puVar3[2] + uVar9;
      uVar10 = uVar4 - 1 & ~(uVar9 - 1);
      uVar6 = uVar9 + param_3;
      uVar5 = uVar6 - 1 & ~(uVar9 - 1);
      uVar8 = uVar10 - uVar5;
      uVar9 = ((puVar3[3] + (uint)(uVar4 < puVar3[2]) + -1 + (uint)(uVar4 - 1 < uVar4) &
               ~((uVar9 - 1 < uVar9) - 1)) -
              (param_4 + (uVar6 < uVar9) + -1 + (uint)(uVar6 - 1 < uVar6) &
              ~((uVar9 - 1 < uVar9) - 1))) - (uint)(uVar10 < uVar5);
    }
  }
  iVar2 = local_30[0];
  iVar1 = (**(code **)(*piVar7 + 0x24))(piVar7,local_30[0],uVar8,uVar9);
  if (iVar1 == 0) {
    **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffb;
    iVar1 = *(int *)(param_1 + 0x14);
    piVar7 = (int *)(param_1 + 0x18);
    *(uint *)(iVar1 + 8) = param_3;
    *(uint *)(iVar1 + 0xc) = param_4;
    iVar1 = FUN_c0346214(piVar7,iVar2,param_3,param_4);
    if (iVar1 == 0) {
      uVar9 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
      uVar8 = uVar9 + param_3;
      iVar1 = FUN_c034684c(piVar7,iVar2,uVar8 - 1 & ~(uVar9 - 1),
                           param_4 + (uVar8 < uVar9) + -1 + (uint)(uVar8 - 1 < uVar8) &
                           ~((uVar9 - 1 < uVar9) - 1),0xffffffff);
      if (((iVar1 == 0) && ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x20) != 0)) &&
         (iVar2 = FUN_c0346124(piVar7,iVar2), iVar2 != 0)) {
        **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) | 2;
      }
    }
  }
  return iVar1;
}



/* c0344044 FUN_c0344044 */

/* Boundary evidence: original MIPS .pdata c0344044..c0344147. Semantic name remains unreviewed. */

int FUN_c0344044(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint local_20 [2];
  
  piVar4 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  FUN_c03410b8((int)piVar4);
  local_20[0] = FUN_c0346810(param_1 + 0x18);
  if ((local_20[0] < 2) || (*(uint *)(*(int *)(param_1 + 0xc) + 0x44) <= local_20[0])) {
    iVar3 = 0x26;
  }
  else if ((**(uint **)(param_1 + 0x14) & 2) == 0) {
    do {
      uVar1 = local_20[0];
      uVar2 = local_20[0];
      iVar3 = (**(code **)(*piVar4 + 0xc))(piVar4,local_20[0],local_20);
      if ((iVar3 != 0) ||
         (iVar3 = FUN_c034684c((int *)(param_1 + 0x18),uVar2,0xffffffff,0xffffffff,local_20[0]),
         iVar3 != 0)) break;
    } while (local_20[0] == uVar1 + 1);
  }
  else {
    iVar3 = 0x1f;
  }
  FUN_c03410d4(piVar4);
  return iVar3;
}



/* c0344148 FUN_c0344148 */

/* Boundary evidence: original MIPS .pdata c0344148..c03441c3. Semantic name remains unreviewed. */

int FUN_c0344148(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (((*(int *)(param_2 + 0xc) == param_1) ||
      (iVar1 = FUN_c0342b8c(param_2,*(int *)(param_1 + 0xc),0), iVar1 == 0)) &&
     (*(int *)(param_2 + 0xc) = param_1, *(int *)(param_1 + 0x10) == 0)) {
    InterlockedIncrement((LONG *)(param_2 + 0x18));
    *(int *)(param_1 + 0x10) = param_2;
  }
  return iVar1;
}



/* c03441c4 FUN_c03441c4 */

/* Boundary evidence: original MIPS .pdata c03441c4..c03441ff. Semantic name remains unreviewed. */

undefined4 FUN_c03441c4(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x10) + 0x18));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 0;
}



/* c0344200 FUN_c0344200 */

/* Boundary evidence: original MIPS .pdata c0344200..c0344227. Semantic name remains unreviewed. */

undefined4 FUN_c0344200(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    uVar1 = FUN_c0342590(*(int *)(param_1 + 0x10));
  }
  return uVar1;
}



/* c0344228 FUN_c0344228 */

/* Boundary evidence: original MIPS .pdata c0344228..c034429f. Semantic name remains unreviewed. */

int FUN_c0344228(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((**(uint **)(param_1 + 0x14) & 2) == 0) {
    if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
      FUN_c0346030((int *)(param_1 + 0x18),param_2);
    }
    while (iVar1 = FUN_c0344044(param_1), iVar1 == 0) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = 1;
  }
  return iVar2;
}



/* c03442a0 FUN_c03442a0 */

/* Boundary evidence: original MIPS .pdata c03442a0..c034435f. Semantic name remains unreviewed. */

undefined4 FUN_c03442a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(*(int *)(param_1 + 0xc) + 0x48);
  uVar4 = 0;
  if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
    FUN_c0346030((int *)(param_1 + 0x18),param_2);
  }
  do {
    iVar1 = FUN_c0344044(param_1);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x28);
      uVar2 = *(undefined4 *)(param_1 + 0x2c);
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffb;
      iVar1 = *(int *)(param_1 + 0x14);
      *(undefined4 *)(iVar1 + 8) = uVar3;
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      return 0;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= uVar5);
  return 0xd;
}



/* c0344360 FUN_c0344360 */

undefined4 FUN_c0344360(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    uVar1 = 0x1f;
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
  }
  return uVar1;
}



/* c0344388 FUN_c0344388 */

/* Boundary evidence: original MIPS .pdata c0344388..c03443d3. Semantic name remains unreviewed. */

undefined4 * FUN_c0344388(undefined4 *param_1,uint param_2)

{
  FUN_c0343d30(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c03443d4 FUN_c03443d4 */

/* Boundary evidence: original MIPS .pdata c03443d4..c034442b. Semantic name remains unreviewed. */

void FUN_c03443d4(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x10) + 0x18));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_c0342e5c(*(int *)(*(int *)(param_1 + 0xc) + 0x10),param_1,param_2,0);
  return;
}



/* c034442c FUN_c034442c */

/* Boundary evidence: original MIPS .pdata c034442c..c034447b. Semantic name remains unreviewed. */

void FUN_c034442c(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x10) + 0x18));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  FUN_c0342e5c(*(int *)(*(int *)(param_1 + 0xc) + 0x10),param_1,1,1);
  return;
}



/* c034447c FUN_c034447c */

/* Boundary evidence: original MIPS .pdata c034447c..c034457f. Semantic name remains unreviewed. */

int FUN_c034447c(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x48);
  iVar3 = 0;
  if ((param_3 & param_4) != 0xffffffff) {
    if ((*(uint *)(param_1 + 0x24) < param_4) ||
       ((param_4 == *(uint *)(param_1 + 0x24) && (*(uint *)(param_1 + 0x20) <= param_3))))
    goto joined_r0xc0344500;
  }
  if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
    FUN_c0346030((int *)(param_1 + 0x18),param_2);
  }
joined_r0xc0344500:
  while (iVar1 = iVar2, iVar1 != 0) {
    if ((param_4 < *(uint *)(param_1 + 0x2c)) ||
       (((param_4 == *(uint *)(param_1 + 0x2c) && (param_3 < *(uint *)(param_1 + 0x28))) ||
        (iVar3 = FUN_c0344044(param_1), iVar2 = iVar1 + -1, iVar3 != 0)))) break;
  }
  if (iVar1 == 1) {
    iVar3 = 0xd;
  }
  return iVar3;
}



/* c0344580 FUN_c0344580 */

/* Boundary evidence: original MIPS .pdata c0344580..c0344633. Semantic name remains unreviewed. */

int FUN_c0344580(int param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  
  if (param_5 == (int *)0x0) {
    iVar1 = 0xd;
  }
  else {
    *param_5 = -1;
    iVar1 = FUN_c034447c(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
        FUN_c03466b0((int *)(param_1 + 0x18),param_2,param_3,param_4,param_5);
      }
      else {
        *param_5 = 0;
      }
    }
  }
  return iVar1;
}



/* c0344634 FUN_c0344634 */

/* Boundary evidence: original MIPS .pdata c0344634..c034487b. Semantic name remains unreviewed. */

int FUN_c0344634(int param_1,uint *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_20 [2];
  
  puVar1 = *(uint **)(param_1 + 0x14);
  local_20[0] = 0;
  uVar3 = puVar1[3];
  if ((puVar1[2] != param_3) || (uVar3 != param_4)) {
    if ((*puVar1 & 1) == 0) {
      uVar3 = FUN_c03352c8(*(int *)(param_1 + 0xc));
      if (uVar3 != 0) {
        return 0x13;
      }
      puVar1 = *(uint **)(param_1 + 0x14);
      uVar3 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
      uVar4 = puVar1[2] + uVar3;
      uVar5 = uVar3 + param_3;
      if (((uVar4 - 1 & ~(uVar3 - 1)) != (uVar5 - 1 & ~(uVar3 - 1))) ||
         ((puVar1[3] + (uint)(uVar4 < puVar1[2]) + -1 + (uint)(uVar4 - 1 < uVar4) &
          ~((uVar3 - 1 < uVar3) - 1)) !=
          (param_4 + (uVar5 < uVar3) + -1 + (uint)(uVar5 - 1 < uVar5) & ~((uVar3 - 1 < uVar3) - 1)))
         ) {
        if (param_3 == 0 && param_4 == 0) {
          if ((*puVar1 & 1) == 0) {
            iVar2 = FUN_c0346030((int *)(param_1 + 0x18),param_2);
          }
          else {
            iVar2 = 0;
          }
          if (iVar2 != 0) {
            return iVar2;
          }
          local_20[0] = 0;
        }
        else {
          iVar2 = FUN_c0344580(param_1,param_2,param_3 - 1,
                               (param_4 - 1) + (uint)(param_3 - 1 < param_3),local_20);
          if (iVar2 == 0x26) {
            iVar2 = 0;
          }
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        FUN_c03410b8(*(int *)(*(int *)(param_1 + 0xc) + 0x18));
        if (local_20[0] == -1) {
          iVar2 = FUN_c034487c(param_1,param_2,param_3,param_4);
        }
        else {
          iVar2 = FUN_c0343dbc(param_1,param_2,param_3,param_4,local_20[0]);
        }
        FUN_c03410d4(*(int **)(*(int *)(param_1 + 0xc) + 0x18));
        return iVar2;
      }
      *puVar1 = *puVar1 & 0xfffffffb;
      iVar2 = *(int *)(param_1 + 0x14);
      *(uint *)(iVar2 + 8) = param_3;
      *(uint *)(iVar2 + 0xc) = param_4;
    }
    else if ((uVar3 < param_4) || ((param_4 == uVar3 && (puVar1[2] < param_3)))) {
      return 0x70;
    }
  }
  return 0;
}



/* c034487c FUN_c034487c */

/* Boundary evidence: original MIPS .pdata c034487c..c0344cd7. Semantic name remains unreviewed. */

int FUN_c034487c(int param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  local_3c = (uint *)0xffffffff;
  local_2c = *(uint *)(*(int *)(param_1 + 0x14) + 8);
  local_30 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
  uVar9 = *(uint *)(param_1 + 0x28);
  uVar10 = *(uint *)(param_1 + 0x2c);
  iVar8 = 0;
  if (((uVar10 != 0) || (uVar9 != 0)) &&
     (iVar8 = FUN_c03466b0((int *)(param_1 + 0x18),param_2,uVar9 - 1,
                           (uVar10 - 1) + (uint)(uVar9 - 1 < uVar9),(int *)&local_3c), iVar8 != 0))
  goto LAB_c0344c94;
  puVar2 = local_3c;
  iVar6 = *(int *)(param_1 + 0xc);
  uVar1 = FUN_c03387fc(iVar6,param_2,param_3 - uVar9,(param_4 - uVar10) - (uint)(param_3 < uVar9),1)
  ;
  piVar7 = *(int **)(iVar6 + 0x18);
  if (piVar7[0xc] != -1) {
    param_2 = &local_34;
    local_34 = 0;
    (**(code **)(*piVar7 + 0x28))(piVar7);
    puVar2 = local_3c;
    if (local_34 < uVar1) {
      return 0x70;
    }
  }
  local_40 = (uint *)0x0;
  local_38 = 0;
  puVar3 = param_2;
  if (uVar10 <= param_4) {
    puVar5 = local_40;
    if (uVar10 == param_4) goto LAB_c0344c04;
    do {
      do {
        local_40 = puVar5;
        if (local_38 == 0) {
          iVar8 = (**(code **)(*piVar7 + 0x1c))(piVar7,puVar2,uVar1,&local_40,&local_38);
          uVar1 = uVar1 - local_38;
          param_2 = puVar2;
          puVar2 = local_3c;
        }
        if (puVar2 == local_40) {
          iVar8 = 0x70;
        }
        if (iVar8 != 0) goto LAB_c0344c94;
        puVar3 = param_2;
        if (((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x20) == 0) ||
           ((**(uint **)(param_1 + 0x14) & 2) == 0)) {
LAB_c0344b5c:
          param_2 = puVar2;
          if (param_2 == (uint *)0xffffffff) goto LAB_c0344b6c;
          iVar8 = (**(code **)(*piVar7 + 0x10))(piVar7,param_2,local_40,0);
          if (iVar8 != 0) goto LAB_c0344c94;
        }
        else {
          if ((uVar1 == 0) &&
             ((local_40 == (uint *)((int)puVar2 + 1) || (puVar2 == (uint *)0xffffffff)))) {
            uVar1 = 0;
            if (local_38 != 0) goto LAB_c0344a58;
            goto LAB_c0344acc;
          }
          if (puVar2 != (uint *)0xffffffff) {
            **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffd;
            param_2 = *(uint **)(*(int *)(param_1 + 0x14) + 4);
            iVar8 = (**(code **)(*piVar7 + 0x18))(piVar7,param_2,local_3c,0);
            puVar3 = param_2;
            puVar2 = local_3c;
            if (iVar8 == 0) goto LAB_c0344b5c;
            goto LAB_c0344c94;
          }
LAB_c0344b6c:
          param_2 = puVar3;
          *(uint **)(*(int *)(param_1 + 0x14) + 4) = local_40;
        }
        iVar8 = FUN_c034684c((int *)(param_1 + 0x18),param_2,uVar9,uVar10,(uint)local_40);
        if (iVar8 != 0) goto LAB_c0344c94;
        uVar4 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
        local_3c = local_40;
        uVar9 = uVar4 + uVar9;
        local_38 = local_38 - 1;
        uVar10 = uVar10 + (uVar9 < uVar4);
        puVar5 = (uint *)((int)local_40 + 1);
        puVar2 = local_40;
      } while (uVar10 < param_4);
      puVar3 = param_2;
      local_40 = puVar5;
      if (uVar10 != param_4) break;
LAB_c0344c04:
      puVar3 = param_2;
      puVar5 = local_40;
    } while (uVar9 < param_3);
  }
  param_2 = puVar2;
  if (param_2 != (uint *)0xffffffff) {
    iVar8 = (**(code **)(*piVar7 + 0x10))(piVar7,param_2,0xffffffff,0);
    if (iVar8 != 0) goto LAB_c0344c94;
    iVar8 = FUN_c034684c((int *)(param_1 + 0x18),param_2,uVar9,uVar10,0xffffffff);
    goto LAB_c0344c5c;
  }
  goto LAB_c0344c8c;
  while( true ) {
    uVar1 = uVar1 + 1;
    uVar4 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
    uVar9 = uVar4 + uVar9;
    uVar10 = uVar10 + (uVar9 < uVar4);
    puVar2 = local_3c;
    if (local_38 <= uVar1) break;
LAB_c0344a58:
    param_2 = (uint *)(uVar1 + (int)local_40);
    iVar8 = (**(code **)(*piVar7 + 0x14))(piVar7);
    if ((iVar8 != 0) ||
       (iVar8 = FUN_c034684c((int *)(param_1 + 0x18),param_2,uVar9,uVar10,uVar1 + (int)local_40),
       iVar8 != 0)) goto LAB_c0344c94;
  }
LAB_c0344acc:
  if (puVar2 == (uint *)0xffffffff) {
    *(uint **)(*(int *)(param_1 + 0x14) + 4) = local_40;
  }
  iVar8 = FUN_c034684c((int *)(param_1 + 0x18),param_2,uVar9,uVar10,0xffffffff);
LAB_c0344c5c:
  if (iVar8 != 0) goto LAB_c0344c94;
  **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffb;
  iVar6 = *(int *)(param_1 + 0x14);
  *(uint *)(iVar6 + 8) = param_3;
  *(uint *)(iVar6 + 0xc) = param_4;
  puVar3 = param_2;
LAB_c0344c8c:
  param_2 = puVar3;
  if (iVar8 == 0) {
    return 0;
  }
LAB_c0344c94:
  FUN_c0344634(param_1,param_2,local_2c,local_30);
  return iVar8;
}



/* c0344cd8 FUN_c0344cd8 */

/* Boundary evidence: original MIPS .pdata c0344cd8..c0344e9f. Semantic name remains unreviewed. */

int FUN_c0344cd8(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,int *param_6,
                int *param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_50 [2];
  uint local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_30;
  
  iVar3 = 1;
  uVar5 = 1 << (*(byte *)(*(int *)(param_1 + 0xc) + 0x34) & 0x1f);
  if ((*(uint *)(param_1 + 0x24) <= param_4) &&
     ((param_4 != *(uint *)(param_1 + 0x24) || (*(uint *)(param_1 + 0x20) <= param_3)))) {
    if ((param_4 <= *(uint *)(param_1 + 0x2c)) &&
       ((param_4 != *(uint *)(param_1 + 0x2c) || (param_3 < *(uint *)(param_1 + 0x28))))) {
      iVar1 = FUN_c0346458((int *)(param_1 + 0x18),param_2,param_3,param_4,(ulonglong *)&local_48);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar4 = *(int *)(param_1 + 0xc);
      uVar2 = (uint)*(byte *)(iVar4 + 0x34);
      iVar1 = __ull_rshift(param_3 - local_48,(param_4 - local_44) - (uint)(param_3 < local_48),
                           uVar2);
      uVar2 = (1 << (uVar2 & 0x1f)) - 1U & param_3 - local_48;
      if ((param_5 < uVar5) || (uVar2 != 0)) {
        iVar3 = 0;
      }
      iVar3 = FUN_c0342c58(*(int *)(iVar4 + 0x10),iVar1 + local_30,param_1,iVar3,local_50);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar3 = uVar2 + *(int *)(local_50[0] + 0x14);
      *param_6 = iVar3;
      if (param_7 == (int *)0x0) {
        return 0;
      }
      iVar1 = uVar5 + *(int *)(local_50[0] + 0x14);
      if ((local_3c - param_4 == (uint)(local_40 < param_3)) &&
         ((local_3c - param_4 != (uint)(local_40 < param_3) || (local_40 - param_3 < uVar5 - uVar2))
         )) {
        iVar1 = (local_40 - param_3) + iVar3;
      }
      *param_7 = iVar1;
      return 0;
    }
  }
  return 0xd;
}



/* c0344ea0 FUN_c0344ea0 */

/* Boundary evidence: original MIPS .pdata c0344ea0..c034506b. Semantic name remains unreviewed. */

int FUN_c0344ea0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_30;
  
  iVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  if ((**(uint **)(param_1 + 0x14) & 2) == 0) {
    puVar3 = param_2;
    if ((**(uint **)(param_1 + 0x14) & 1) == 0) {
      FUN_c0346030((int *)(param_1 + 0x18),param_2);
    }
    iVar2 = FUN_c0344044(param_1);
    if (iVar2 == 0) {
      do {
        iVar2 = FUN_c0346458((int *)(param_1 + 0x18),puVar3,uVar8,uVar9,(ulonglong *)&local_48);
        iVar7 = local_44;
        uVar6 = local_48;
        if (iVar2 != 0) {
          return iVar2;
        }
        *param_2 = local_30;
        uVar4 = (1 << (*(byte *)(*(int *)(param_1 + 0xc) + 0x34) & 0x1f)) - 1;
        uVar5 = uVar4 - local_48;
        puVar3 = (undefined4 *)
                 ((-(uint)(uVar4 < local_48) - local_44) + local_3c +
                 (uint)(uVar5 + local_40 < uVar5));
        uVar1 = __ull_rshift();
        uVar8 = uVar6 + uVar8;
        param_2[1] = uVar1;
        param_2 = param_2 + 2;
        uVar9 = iVar7 + uVar9 + (uint)(uVar8 < uVar6);
        iVar2 = FUN_c0344044(param_1);
        iVar7 = 0;
      } while (iVar2 == 0);
    }
  }
  else {
    iVar7 = FUN_c0346458((int *)(param_1 + 0x18),param_2,0,0,(ulonglong *)&local_48);
    if (iVar7 == 0) {
      *param_2 = local_30;
      uVar9 = (1 << (*(byte *)(*(int *)(param_1 + 0xc) + 0x34) & 0x1f)) - 1;
      uVar6 = uVar9 - local_48;
      uVar8 = uVar6 + local_40;
      uVar1 = __ull_rshift(uVar8,(-(uint)(uVar9 < local_48) - local_44) + local_3c +
                                 (uint)(uVar8 < uVar6));
      param_2[1] = uVar1;
    }
  }
  return iVar7;
}



/* c034506c FUN_c034506c */

/* Boundary evidence: original MIPS .pdata c034506c..c03451b7. Semantic name remains unreviewed. */

int FUN_c034506c(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                int *param_7,undefined4 *param_8)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_20;
  
  if ((*(uint *)(param_1 + 0x24) <= param_4) &&
     ((param_4 != *(uint *)(param_1 + 0x24) || (*(uint *)(param_1 + 0x20) <= param_3)))) {
    if ((param_4 <= *(uint *)(param_1 + 0x2c)) &&
       ((param_4 != *(uint *)(param_1 + 0x2c) || (param_3 < *(uint *)(param_1 + 0x28))))) {
      iVar1 = FUN_c0346458((int *)(param_1 + 0x18),param_2,param_3,param_4,(ulonglong *)&local_38);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = __ull_rshift(param_3 - local_38,(param_4 - local_34) - (uint)(param_3 < local_38),
                           *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x34));
      uVar3 = (local_2c - param_4) - (uint)(local_30 < param_3);
      *param_7 = iVar1 + local_20;
      if ((uVar3 <= param_6) && ((param_6 != uVar3 || (local_30 - param_3 < param_5)))) {
        param_5 = local_30 - param_3;
        param_6 = uVar3;
      }
      uVar2 = __ull_rshift(param_5,param_6,*(undefined1 *)(*(int *)(param_1 + 0xc) + 0x34));
      *param_8 = uVar2;
      return 0;
    }
  }
  return 0x57;
}



/* c03451b8 FUN_c03451b8 */

/* Boundary evidence: original MIPS .pdata c03451b8..c034522b. Semantic name remains unreviewed. */

void FUN_c03451b8(int param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,int *param_6
                 )

{
  int iVar1;
  
  iVar1 = FUN_c034447c(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    FUN_c0344cd8(param_1,param_2,param_3,param_4,0,param_5,param_6);
  }
  return;
}



/* c034522c FUN_c034522c */

/* Boundary evidence: original MIPS .pdata c034522c..c03455eb. Semantic name remains unreviewed. */

int FUN_c034522c(int param_1,void *param_2,uint param_3,uint param_4,void *param_5,uint param_6,
                uint param_7,int *param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint _Size;
  uint uVar6;
  void *local_50;
  int local_48;
  uint local_44;
  uint local_40;
  void *local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  iVar5 = 0;
  _Size = 0;
  local_34 = 0;
  uVar6 = (uint)(param_7 == 8);
  if (param_8 != (int *)0x0) {
    *param_8 = 0;
  }
  uVar2 = *(uint *)(*(int *)(param_1 + 0x14) + 8);
  uVar4 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
  if ((param_4 < uVar4) || ((param_4 == uVar4 && (param_3 <= uVar2)))) {
    uVar1 = uVar2 - param_3;
    iVar3 = (uVar4 - param_4) - (uint)(uVar2 < param_3);
  }
  else {
    uVar1 = 0;
    iVar3 = 0;
  }
  if ((iVar3 == 0) && (uVar1 < param_6)) {
    param_6 = uVar1;
  }
  local_50 = param_5;
  local_44 = uVar6;
  do {
    if ((param_6 == 0) || (iVar5 = FUN_c034447c(param_1,param_2,param_3,param_4), iVar5 != 0))
    goto LAB_c0345590;
    local_40 = 0;
    local_48 = 0;
    iVar5 = param_1;
    iVar3 = FUN_c03427b8(*(int *)(*(int *)(param_1 + 0xc) + 0x10),param_1,param_3,param_4,param_6,
                         &local_40,&local_48,0,uVar6);
    if (iVar3 == 0) {
      iVar5 = FUN_c0335074(*(int *)(param_1 + 0xc),local_40,local_48,local_50,param_7);
      local_30 = iVar5;
      if (iVar5 == 0) {
        _Size = __ll_lshift(local_48,0,*(undefined1 *)(*(int *)(param_1 + 0xc) + 0x34));
        local_50 = (void *)(_Size + (int)local_50);
        if (param_8 != (int *)0x0) {
          *param_8 = *param_8 + _Size;
        }
      }
      param_2 = (void *)0x0;
      FUN_c0342568(*(int *)(*(int *)(param_1 + 0xc) + 0x10),0);
    }
    else {
      local_34 = 1;
      local_3c = (void *)0x0;
      local_38 = 0;
      iVar5 = FUN_c03451b8(param_1,iVar5,param_3,param_4,(int *)&local_3c,&local_38);
      if (iVar5 != 0) {
LAB_c0345590:
        if ((local_34 != 0) && (uVar6 != 0)) {
          FUN_c034442c(param_1);
        }
        return iVar5;
      }
      _Size = local_38 - (int)local_3c;
      if (param_6 < (uint)(local_38 - (int)local_3c)) {
        _Size = param_6;
      }
      param_2 = local_3c;
      memcpy(local_50,local_3c,_Size);
      local_50 = (void *)(_Size + (int)local_50);
      if (param_8 != (int *)0x0) {
        *param_8 = *param_8 + _Size;
      }
      if (*(int *)(param_1 + 0x10) != 0) {
        InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x10) + 0x18));
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
    }
    if (iVar5 != 0) goto LAB_c0345590;
    param_6 = param_6 - _Size;
    param_3 = _Size + param_3;
    param_4 = param_4 + (param_3 < _Size);
  } while( true );
}



/* c03455ec FUN_c03455ec */

/* Boundary evidence: original MIPS .pdata c03455ec..c03455f7. Semantic name remains unreviewed. */

undefined4 FUN_c03455ec(void)

{
  return 1;
}



/* c03455f8 FUN_c03455f8 */

/* Boundary evidence: original MIPS .pdata c03455f8..c0345603. Semantic name remains unreviewed. */

undefined4 FUN_c03455f8(void)

{
  return 1;
}



/* c0345604 FUN_c0345604 */

/* Boundary evidence: original MIPS .pdata c0345604..c0345a67. Semantic name remains unreviewed. */

int FUN_c0345604(int param_1,void *param_2,uint param_3,uint param_4,void *param_5,uint param_6,
                uint param_7,int *param_8)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_68;
  void *local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  ulonglong uStack_48;
  int local_40;
  
  iVar7 = 0;
  local_54 = 0;
  uVar1 = (uint)(param_7 == 8);
  local_60 = uVar1;
  if (param_8 != (int *)0x0) {
    *param_8 = 0;
  }
  do {
    if ((param_6 == 0) || (iVar7 = FUN_c034447c(param_1,param_2,param_3,param_4), iVar7 != 0))
    goto LAB_c03457e8;
    uVar8 = 0;
    local_5c = 0;
    local_68 = 0;
    iVar7 = 0x1f;
    if (param_5 != (void *)0x0) {
      iVar7 = FUN_c03427b8(*(int *)(*(int *)(param_1 + 0xc) + 0x10),param_1,param_3,param_4,param_6,
                           &local_5c,&local_68,1,uVar1);
    }
    if (iVar7 == 0) {
      iVar7 = FUN_c03350a8(*(int *)(param_1 + 0xc),local_5c,local_68,param_5,param_7);
      local_50 = iVar7;
      if (iVar7 == 0) {
        uVar8 = __ll_lshift(local_68,0,*(undefined1 *)(*(int *)(param_1 + 0xc) + 0x34));
        param_5 = (void *)(uVar8 + (int)param_5);
        if (param_8 != (int *)0x0) {
          *param_8 = *param_8 + uVar8;
        }
      }
      param_2 = (void *)0x1;
      FUN_c0342568(*(int *)(*(int *)(param_1 + 0xc) + 0x10),1);
      if (iVar7 != 0) goto LAB_c03457e8;
    }
    else {
      local_54 = 1;
      local_64 = (void *)0x0;
      local_58 = 0;
      uVar8 = local_5c;
      iVar7 = FUN_c0346458((int *)(param_1 + 0x18),local_5c,param_3,param_4,&uStack_48);
      if (iVar7 != 0) {
LAB_c03457e8:
        if (*(int *)(param_1 + 0x10) != 0) {
          InterlockedDecrement((LONG *)(*(int *)(param_1 + 0x10) + 0x18));
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        if ((local_54 != 0) && (uVar1 != 0)) {
          iVar7 = FUN_c034442c(param_1);
        }
        return iVar7;
      }
      uVar2 = *(uint *)(*(int *)(param_1 + 0x14) + 0xc);
      uVar6 = param_4 + (param_6 + param_3 < param_6);
      if ((uVar2 < uVar6) ||
         ((uVar3 = param_6, uVar6 == uVar2 &&
          (*(uint *)(*(int *)(param_1 + 0x14) + 8) <= param_6 + param_3)))) {
        uVar3 = local_40 - param_3;
      }
      iVar7 = FUN_c0344cd8(param_1,uVar8,param_3,param_4,uVar3,(int *)&local_64,&local_58);
      if (iVar7 != 0) goto LAB_c03457e8;
      uVar8 = local_58 - (int)local_64;
      if (param_6 < (uint)(local_58 - (int)local_64)) {
        uVar8 = param_6;
      }
      iVar7 = 0;
      if (*(int *)(param_1 + 0x10) != 0) {
        iVar7 = FUN_c0342590(*(int *)(param_1 + 0x10));
      }
      if (iVar7 != 0) goto LAB_c03457e8;
      if (param_5 == (void *)0x0) {
        param_2 = (void *)0x0;
        memset(local_64,0,uVar8);
      }
      else {
        param_2 = param_5;
        memcpy(local_64,param_5,uVar8);
        param_5 = (void *)(uVar8 + (int)param_5);
      }
      if (param_8 != (int *)0x0) {
        *param_8 = *param_8 + uVar8;
      }
    }
    param_6 = param_6 - uVar8;
    param_3 = uVar8 + param_3;
    param_4 = param_4 + (param_3 < uVar8);
    puVar4 = *(uint **)(param_1 + 0x14);
    if ((puVar4[3] <= param_4) && ((param_4 != puVar4[3] || (puVar4[2] < param_3)))) {
      *puVar4 = *puVar4 & 0xfffffffb;
      iVar5 = *(int *)(param_1 + 0x14);
      *(uint *)(iVar5 + 8) = param_3;
      *(uint *)(iVar5 + 0xc) = param_4;
    }
  } while( true );
}



/* c0345a68 FUN_c0345a68 */

/* Boundary evidence: original MIPS .pdata c0345a68..c0345a73. Semantic name remains unreviewed. */

undefined4 FUN_c0345a68(void)

{
  return 1;
}



/* c0345a74 FUN_c0345a74 */

/* Boundary evidence: original MIPS .pdata c0345a74..c0345a7f. Semantic name remains unreviewed. */

undefined4 FUN_c0345a74(void)

{
  return 1;
}



/* c0345a80 FUN_c0345a80 */

/* Boundary evidence: original MIPS .pdata c0345a80..c0345bc7. Semantic name remains unreviewed. */

int FUN_c0345a80(int param_1,void *param_2,uint param_3,uint param_4,uint param_5,int param_6,
                uint param_7,uint *param_8)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_30 [2];
  
  if (param_8 != (uint *)0x0) {
    *param_8 = 0;
    param_8[1] = 0;
  }
  if (param_5 != 0 || param_6 != 0) {
    do {
      uVar3 = 0xffffffff;
      if ((param_6 == 0) && (param_5 != 0xffffffff)) {
        uVar3 = param_5;
      }
      local_30[1] = 0;
      local_30[0] = 0;
      iVar1 = FUN_c0345604(param_1,param_2,param_3,param_4,(void *)0x0,param_5,param_7,
                           (int *)local_30);
      if (param_8 != (uint *)0x0) {
        uVar2 = *param_8;
        *param_8 = local_30[0] + uVar2;
        param_8[1] = param_8[1] + (uint)(local_30[0] + uVar2 < local_30[0]);
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = param_5 - uVar3;
      param_3 = uVar3 + param_3;
      param_6 = param_6 - (uint)(param_5 < uVar3);
      param_4 = param_4 + (param_3 < uVar3);
      param_5 = uVar2;
    } while (uVar2 != 0 || param_6 != 0);
  }
  return 0;
}



/* c0345bc8 FUN_c0345bc8 */

/* Boundary evidence: original MIPS .pdata c0345bc8..c0345d4f. Semantic name remains unreviewed. */

int FUN_c0345bc8(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  int local_28;
  uint local_24;
  
  local_24 = 0;
  uVar10 = 1 << (*(byte *)(*(int *)(param_1 + 0xc) + 0x34) & 0x1f);
  uVar7 = ~(uVar10 - 1) & param_3;
  uVar5 = uVar10 + param_3;
  uVar9 = ~((uVar10 - 1 < uVar10) - 1) & param_4;
  lVar1 = CONCAT44(uVar9,uVar7);
  uVar4 = uVar5 + param_5;
  uVar6 = uVar4 - 1 & ~(uVar10 - 1);
  uVar8 = uVar6 - uVar7;
  uVar4 = ((param_4 + (uVar5 < uVar10) + param_6 + (uint)(uVar4 < uVar5) + -1 +
            (uint)(uVar4 - 1 < uVar4) & ~((uVar10 - 1 < uVar10) - 1)) - uVar9) -
          (uint)(uVar6 < uVar7);
  local_28 = 0;
  if (uVar8 != 0 || uVar4 != 0) {
    do {
      iVar3 = FUN_c034506c(param_1,param_2,(uint)lVar1,(uint)((ulonglong)lVar1 >> 0x20),uVar8,uVar4,
                           (int *)&local_24,&local_28);
      iVar2 = local_28;
      if (iVar3 != 0) {
        return iVar3;
      }
      FUN_c0342a88(*(int *)(*(int *)(param_1 + 0xc) + 0x10),local_24,local_28);
      param_2 = 0;
      lVar11 = __ll_lshift(iVar2,0,*(undefined1 *)(*(int *)(param_1 + 0xc) + 0x34));
      lVar1 = lVar11 + lVar1;
      uVar5 = uVar8 - (uint)lVar11;
      uVar4 = (uVar4 - (int)((ulonglong)lVar11 >> 0x20)) - (uint)(uVar8 < (uint)lVar11);
      uVar8 = uVar5;
    } while (uVar5 != 0 || uVar4 != 0);
  }
  return 0;
}



/* c0345d50 FUN_c0345d50 */

undefined4 * FUN_c0345d50(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0332044;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* c0345d70 FUN_c0345d70 */

/* Boundary evidence: original MIPS .pdata c0345d70..c0345da3. Semantic name remains unreviewed. */

void FUN_c0345d70(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0332044;
  if ((LPVOID)param_1[1] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[1]);
  }
  return;
}



/* c0345da4 FUN_c0345da4 */

/* Boundary evidence: original MIPS .pdata c0345da4..c0345e2b. Semantic name remains unreviewed. */

undefined4 FUN_c0345da4(int param_1,int param_2)

{
  LPVOID _Dst;
  undefined4 uVar1;
  SIZE_T SVar2;
  uint uVar3;
  
  uVar3 = param_2 + 0x1fU >> 5;
  if (uVar3 < 0x40000000) {
    SVar2 = uVar3 << 2;
  }
  else {
    SVar2 = 0xffffffff;
  }
  _Dst = FUN_c0332264(SVar2);
  *(LPVOID *)(param_1 + 4) = _Dst;
  if (_Dst == (LPVOID)0x0) {
    uVar1 = 8;
  }
  else {
    memset(_Dst,0,uVar3 << 2);
    *(int *)(param_1 + 8) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}



/* c0345e2c FUN_c0345e2c */

void FUN_c0345e2c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_2 < *(uint *)(param_1 + 8)) {
    puVar3 = (uint *)((param_2 >> 5) * 4 + *(int *)(param_1 + 4));
    uVar1 = *puVar3;
    uVar2 = 1 << (param_2 & 0x1f);
    if ((uVar2 & uVar1) == 0) {
      *puVar3 = uVar2 | uVar1;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
  }
  return;
}



/* c0345e88 FUN_c0345e88 */

undefined4 FUN_c0345e88(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) <= param_2) ||
     (uVar1 = 1,
     (*(uint *)((param_2 >> 5) * 4 + *(int *)(param_1 + 4)) & 1 << (param_2 & 0x1f)) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0345ed0 FUN_c0345ed0 */

/* Boundary evidence: original MIPS .pdata c0345ed0..c0345f8f. Semantic name remains unreviewed. */

void FUN_c0345ed0(int param_1,uint param_2,uint param_3,int *param_4,uint *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 8);
  uVar3 = 0;
  bVar1 = false;
  while ((param_2 < uVar4 && (uVar3 < param_3))) {
    iVar2 = FUN_c0345e88(param_1,param_2);
    if (iVar2 == 0) {
      if (bVar1) break;
    }
    else {
      bVar1 = true;
      uVar3 = uVar3 + 1;
    }
    param_2 = param_2 + 1;
  }
  *param_4 = param_2 - uVar3;
  *param_5 = uVar3;
  return;
}



/* c0345f90 FUN_c0345f90 */

/* Boundary evidence: original MIPS .pdata c0345f90..c0345fcf. Semantic name remains unreviewed. */

void FUN_c0345f90(int param_1)

{
  memset(*(void **)(param_1 + 4),0,(*(int *)(param_1 + 8) + 0x1fU >> 5) << 2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



/* c0345fd0 FUN_c0345fd0 */

/* Boundary evidence: original MIPS .pdata c0345fd0..c034602f. Semantic name remains unreviewed. */

undefined4 * FUN_c0345fd0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0332044;
  if ((LPVOID)param_1[1] != (LPVOID)0x0) {
    FUN_c03322a0((LPVOID)param_1[1]);
  }
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0346030 FUN_c0346030 */

/* Boundary evidence: original MIPS .pdata c0346030..c0346123. Semantic name remains unreviewed. */

undefined4 FUN_c0346030(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = (uint *)param_1[1];
  param_1[2] = 0;
  param_1[3] = 0;
  uVar4 = puVar2[1];
  if ((uVar4 == 0) || (uVar4 == 0xffffffff)) {
    param_1[7] = -1;
    param_1[8] = 0;
    param_1[4] = 0;
  }
  else {
    if ((*puVar2 & 2) != 0) {
      iVar3 = *param_1;
      uVar1 = FUN_c03387fc(iVar3,param_2,puVar2[2],puVar2[3],1);
      param_1[7] = uVar4;
      param_1[8] = uVar1;
      param_1[9] = -1;
      param_1[10] = 0;
      uVar4 = *(uint *)(iVar3 + 0x38);
      param_1[6] = 1;
      *(ulonglong *)(param_1 + 4) = (ulonglong)uVar4 * (ulonglong)uVar1;
      return 0;
    }
    param_1[8] = 1;
    param_1[7] = uVar4;
    param_1[4] = *(int *)(*param_1 + 0x38);
  }
  param_1[6] = 0;
  param_1[5] = 0;
  return 0;
}



/* c0346124 FUN_c0346124 */

/* Boundary evidence: original MIPS .pdata c0346124..c034618b. Semantic name remains unreviewed. */

undefined4 FUN_c0346124(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1[2] == 0 && param_1[3] == 0) &&
     (iVar1 = FUN_c03387fc(*param_1,param_2,param_1[4],param_1[5],1), iVar1 == param_1[8])) {
    return 1;
  }
  return 0;
}



/* c034618c FUN_c034618c */

/* Boundary evidence: original MIPS .pdata c034618c..c0346213. Semantic name remains unreviewed. */

int * FUN_c034618c(int *param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  uVar1 = 0;
  param_1[1] = (int)param_3;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  memset(param_1 + 7,0,0x50);
  if ((*param_3 & 1) == 0) {
    FUN_c0346030(param_1,uVar1);
  }
  else {
    param_1[4] = param_3[2];
    param_1[5] = param_3[3];
  }
  return param_1;
}



/* c0346214 FUN_c0346214 */

/* WARNING: Removing unreachable block (ram,0xc03462f4) */
/* WARNING: Removing unreachable block (ram,0xc0346370) */
/* Boundary evidence: original MIPS .pdata c0346214..c0346457. Semantic name remains unreviewed. */

undefined4 FUN_c0346214(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint local_30;
  
  puVar1 = (ulonglong *)(param_1 + 2);
  uVar2 = *puVar1;
  uVar3 = *puVar1;
  if (((uint)param_1[3] <= param_4) && ((param_4 != param_1[3] || ((uint)*puVar1 <= param_3)))) {
    if ((param_4 <= (uint)param_1[5]) && ((param_4 != param_1[5] || (param_3 <= (uint)param_1[4]))))
    {
      iVar8 = *param_1;
      piVar9 = param_1 + 8;
      uVar7 = 0;
      uVar10 = __ll_lshift(*piVar9,0,*(undefined1 *)(iVar8 + 0x34));
      uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
      lVar11 = __ll_lshift((int)uVar10,uVar4,*(undefined1 *)(iVar8 + 0x35));
      if (lVar11 + uVar3 < CONCAT44(param_4,param_3)) {
        uVar5 = param_1[6];
        uVar3 = lVar11 + uVar3;
        do {
          uVar2 = uVar3;
          uVar7 = uVar7 + 1;
          piVar9 = piVar9 + 2;
          if (uVar5 < uVar7) {
            return 0x57;
          }
          uVar10 = __ll_lshift(*piVar9,0,*(undefined1 *)(*param_1 + 0x34));
          uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
          lVar11 = __ll_lshift((int)uVar10,uVar4,*(undefined1 *)(*param_1 + 0x35));
          uVar5 = param_1[6];
          uVar3 = lVar11 + uVar2;
        } while (uVar2 + lVar11 < CONCAT44(param_4,param_3));
      }
      local_30 = (uint)uVar2;
      iVar8 = FUN_c03387fc(*param_1,uVar4,param_3 - local_30,
                           (param_4 - (int)(uVar2 >> 0x20)) - (uint)(param_3 < local_30),1);
      param_1[(uVar7 + 4) * 2] = iVar8;
      iVar6 = *param_1;
      uVar10 = __ll_lshift(iVar8,0,*(undefined1 *)(iVar6 + 0x34));
      lVar11 = __ll_lshift((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),
                           *(undefined1 *)(iVar6 + 0x35));
      *(ulonglong *)(param_1 + 4) = lVar11 + uVar2;
      if (param_1[(uVar7 + 4) * 2] == 0) {
        if (uVar7 == 0) {
          param_1[7] = 0;
        }
        else {
          uVar7 = uVar7 - 1;
        }
      }
      param_1[6] = uVar7;
      return 0;
    }
  }
  return 0x57;
}



/* c0346458 FUN_c0346458 */

/* WARNING: Removing unreachable block (ram,0xc0346580) */
/* WARNING: Removing unreachable block (ram,0xc0346604) */
/* Boundary evidence: original MIPS .pdata c0346458..c03466af. Semantic name remains unreviewed. */

undefined4
FUN_c0346458(int *param_1,undefined4 param_2,uint param_3,uint param_4,ulonglong *param_5)

{
  ulonglong *puVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  int *local_30;
  
  uVar5 = param_1[3];
  puVar1 = (ulonglong *)(param_1 + 2);
  uVar3 = *puVar1;
  uVar2 = *puVar1;
  if ((uVar5 <= param_4) && ((param_4 != uVar5 || ((uint)*puVar1 <= param_3)))) {
    if ((param_4 <= (uint)param_1[5]) && ((param_4 != param_1[5] || (param_3 <= (uint)param_1[4]))))
    {
      if ((*(uint *)param_1[1] & 1) != 0) {
        *(uint *)param_5 = (uint)*puVar1;
        *(uint *)((int)param_5 + 4) = uVar5;
        *(int *)(param_5 + 1) = param_1[4];
        *(int *)((int)param_5 + 0xc) = param_1[5];
        *(undefined4 *)(param_5 + 2) = 0;
        *(undefined4 *)((int)param_5 + 0x14) = 0;
        *(undefined4 *)(param_5 + 3) = *(undefined4 *)(param_1[1] + 4);
        return 0;
      }
      iVar6 = *param_1;
      local_30 = param_1 + 8;
      uVar5 = 0;
      uVar8 = __ll_lshift(*local_30,0,*(undefined1 *)(iVar6 + 0x34));
      lVar9 = __ll_lshift((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),*(undefined1 *)(iVar6 + 0x35));
      uVar2 = lVar9 + uVar2;
      if (uVar2 <= CONCAT44(param_4,param_3)) {
        uVar4 = param_1[6];
        do {
          uVar3 = uVar2;
          uVar5 = uVar5 + 1;
          local_30 = local_30 + 2;
          if (uVar4 < uVar5) {
            return 0x57;
          }
          uVar8 = __ll_lshift(*local_30,0,*(undefined1 *)(*param_1 + 0x34));
          lVar9 = __ll_lshift((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),
                              *(undefined1 *)(*param_1 + 0x35));
          uVar2 = uVar3 + lVar9;
          uVar4 = param_1[6];
        } while (lVar9 + uVar3 <= CONCAT44(param_4,param_3));
      }
      *param_5 = uVar3;
      param_5[1] = uVar2;
      iVar6 = param_1[uVar5 * 2 + 7];
      *(int *)(param_5 + 2) = iVar6;
      *(int *)((int)param_5 + 0x14) = param_1[(uVar5 + 4) * 2];
      iVar7 = *param_1;
      if (iVar6 == 0) {
        iVar6 = *(int *)(iVar7 + 0x54);
      }
      else {
        iVar6 = (iVar6 + -2 << (*(byte *)(iVar7 + 0x35) & 0x1f)) + *(int *)(iVar7 + 0x40);
      }
      *(int *)(param_5 + 3) = iVar6;
      return 0;
    }
  }
  return 0x57;
}



/* c03466b0 FUN_c03466b0 */

/* Boundary evidence: original MIPS .pdata c03466b0..c0346777. Semantic name remains unreviewed. */

int FUN_c03466b0(int *param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_38;
  int local_34;
  int local_28;
  
  *param_5 = -1;
  iVar1 = FUN_c0346458(param_1,param_2,param_3,param_4,(ulonglong *)&local_38);
  if (iVar1 == 0) {
    iVar2 = *param_1;
    uVar3 = __ull_rshift(param_3 - local_38,(param_4 - local_34) - (uint)(param_3 < local_38),
                         *(undefined1 *)(iVar2 + 0x34));
    iVar2 = __ull_rshift((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),*(undefined1 *)(iVar2 + 0x35));
    *param_5 = iVar2 + local_28;
  }
  return iVar1;
}



/* c0346778 FUN_c0346778 */

/* Boundary evidence: original MIPS .pdata c0346778..c034680f. Semantic name remains unreviewed. */

undefined4 FUN_c0346778(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  iVar3 = *param_1;
  uVar4 = __ll_lshift(param_1[8],0,*(undefined1 *)(iVar3 + 0x34));
  lVar5 = __ll_lshift((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),*(undefined1 *)(iVar3 + 0x35));
  piVar1 = param_1 + 7;
  piVar2 = param_1 + 9;
  *(longlong *)(param_1 + 2) = lVar5 + *(longlong *)(param_1 + 2);
  do {
    *piVar1 = *piVar2;
    piVar1 = piVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (piVar1 != param_1 + 0x19);
  return 0;
}



/* c0346810 FUN_c0346810 */

int FUN_c0346810(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((*(int *)(param_1 + 0x18) + 4) * 8 + param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x18) * 8 + param_1 + 0x1c);
  if (1 < uVar2) {
    iVar1 = uVar2 + iVar1 + -1;
  }
  return iVar1;
}



/* c034684c FUN_c034684c */

/* Boundary evidence: original MIPS .pdata c034684c..c0346a3b. Semantic name remains unreviewed. */

undefined4 FUN_c034684c(int *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  bVar1 = param_5 < *(uint *)(*param_1 + 0x44);
  if (((param_3 & param_4) == 0xffffffff) || ((param_3 == param_1[4] && (param_4 == param_1[5])))) {
    iVar2 = param_1[6];
    if ((param_1[(iVar2 + 4) * 2] == 0) && (iVar2 != 0)) {
      param_1[6] = iVar2 + -1;
    }
    if (bVar1) {
      iVar6 = param_1[6];
      iVar2 = param_1[iVar6 * 2 + 7];
      if (1 < (uint)param_1[(iVar6 + 4) * 2]) {
        iVar2 = param_1[(iVar6 + 4) * 2] + iVar2 + -1;
      }
      if (iVar2 + 1U == param_5) {
        param_1[(iVar6 + 4) * 2] = param_1[(iVar6 + 4) * 2] + 1;
        uVar3 = *(uint *)(*param_1 + 0x38);
        uVar4 = uVar3 + param_1[4];
        param_1[4] = uVar4;
        param_1[5] = param_1[5] + (uint)(uVar4 < uVar3);
        return 0;
      }
    }
    iVar2 = param_1[6];
    if (iVar2 == 9) {
      FUN_c0346778(param_1);
    }
    else if (param_1[(iVar2 + 4) * 2] != 0) {
      param_1[6] = iVar2 + 1;
    }
    param_1[param_1[6] * 2 + 7] = param_5;
    if (bVar1) {
      param_1[(param_1[6] + 4) * 2] = 1;
      uVar3 = *(uint *)(*param_1 + 0x38);
      uVar4 = uVar3 + param_1[4];
      param_1[4] = uVar4;
      param_1[5] = param_1[5] + (uint)(uVar4 < uVar3);
    }
    else {
      param_1[(param_1[6] + 4) * 2] = 0;
    }
  }
  else {
    uVar5 = 0x57;
  }
  return uVar5;
}



/* c0346a3c FUN_c0346a3c */

/* Boundary evidence: original MIPS .pdata c0346a3c..c0346aab. Semantic name remains unreviewed. */

int FUN_c0346a3c(int *param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while( true ) {
    if (piVar2 == param_1) {
      return 0;
    }
    iVar1 = (*(code *)param_2)(piVar2,param_3);
    if (iVar1 != 0) break;
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* c0346aac FUN_c0346aac */

/* Boundary evidence: original MIPS .pdata c0346aac..c0346b17. Semantic name remains unreviewed. */

void FUN_c0346aac(int *param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  
  while (piVar1 = (int *)*param_1, piVar1 != param_1) {
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)piVar1[1] = *piVar1;
    (*(code *)param_2)(piVar1,param_3);
  }
  return;
}



/* c0346b18 FUN_c0346b18 */

/* Boundary evidence: original MIPS .pdata c0346b18..c0346b4f. Semantic name remains unreviewed. */

undefined4 * FUN_c0346b18(undefined4 *param_1)

{
  FUN_c0345d50(param_1);
  *param_1 = &PTR_FUN_c0332130;
  return param_1;
}



/* c0346b50 FUN_c0346b50 */

/* Boundary evidence: original MIPS .pdata c0346b50..c0346c0b. Semantic name remains unreviewed. */

void FUN_c0346b50(uint param_1,uint param_2,int *param_3,int *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0xc);
  uVar2 = param_2;
  if (((((piVar3[0x1b] & 0x10U) == 0) || (param_5 == 0)) ||
      (uVar2 = param_1, iVar1 = (**(code **)(*piVar3 + 0x2c))(piVar3,param_1,param_2), param_5 != 2)
      ) || (iVar1 == 0)) {
    iVar1 = FUN_c03451b8(*(int *)(param_1 + 0x10),uVar2,param_2,0,param_3,param_4);
    if (iVar1 == 0) {
      FUN_c0344200(*(int *)(param_1 + 0x10));
    }
  }
  return;
}



/* c0346c0c FUN_c0346c0c */

/* Boundary evidence: original MIPS .pdata c0346c0c..c0346da3. Semantic name remains unreviewed. */

int FUN_c0346c0c(int param_1,LPWSTR param_2,BYTE *param_3)

{
  BOOL BVar1;
  int iVar2;
  BYTE *pBVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  pBVar3 = param_3;
  do {
    if (*pBVar3 == ' ') break;
    BVar1 = IsDBCSLeadByte(*pBVar3);
    if (BVar1 == 0) {
      iVar2 = iVar2 + 1;
      pBVar3 = pBVar3 + 1;
    }
    else {
      iVar2 = iVar2 + 2;
      pBVar3 = pBVar3 + 2;
    }
  } while (iVar2 < 8);
  if (iVar2 != 0) {
    iVar4 = MultiByteToWideChar(*(UINT *)(*(int *)(param_1 + 0xc) + 100),1,(LPCSTR)param_3,iVar2,
                                param_2,8);
    param_2 = param_2 + iVar4;
  }
  iVar2 = 0;
  pBVar3 = param_3 + 8;
  do {
    if (*pBVar3 == ' ') break;
    BVar1 = IsDBCSLeadByte(*pBVar3);
    if (BVar1 == 0) {
      iVar2 = iVar2 + 1;
      pBVar3 = pBVar3 + 1;
    }
    else {
      iVar2 = iVar2 + 2;
      pBVar3 = pBVar3 + 2;
    }
  } while (iVar2 < 3);
  if (iVar2 != 0) {
    *param_2 = L'.';
    iVar2 = MultiByteToWideChar(*(UINT *)(*(int *)(param_1 + 0xc) + 100),1,(LPCSTR)(param_3 + 8),
                                iVar2,param_2 + 1,3);
    param_2 = param_2 + 1 + iVar2;
    iVar4 = iVar2 + iVar4 + 1;
  }
  *param_2 = L'\0';
  return iVar4;
}



/* c0346da4 FUN_c0346da4 */

/* Boundary evidence: original MIPS .pdata c0346da4..c034713b. Semantic name remains unreviewed. */

int FUN_c0346da4(int param_1,wchar_t *param_2,CHAR *param_3)

{
  bool bVar1;
  bool bVar2;
  wint_t wVar3;
  size_t sVar4;
  undefined2 extraout_var;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  CHAR *pCVar11;
  int iVar12;
  CHAR local_40 [2];
  WCHAR local_3e;
  CHAR local_3c [4];
  size_t local_38;
  int local_34;
  wchar_t *local_30;
  int local_2c;
  
  iVar12 = 0;
  iVar9 = 1;
  bVar2 = false;
  local_34 = param_1;
  sVar4 = wcslen(param_2);
  local_38 = sVar4;
  local_30 = wcsrchr(param_2,L'.');
LAB_c0346e10:
  iVar10 = 8;
  bVar1 = false;
  memset(param_3,0x20,0xb);
  pCVar11 = param_3;
  do {
    if (sVar4 == 0) {
LAB_c03470f0:
      if ((0 < iVar9) && (bVar2)) {
        iVar9 = 3;
      }
      return iVar9;
    }
    uVar7 = (uint)(ushort)*param_2;
    if ((((((uVar7 < 0x20) || (uVar7 == 0x5c)) || (uVar7 == 0x2f)) ||
         ((uVar7 == 0x3e || (uVar7 == 0x3c)))) || (uVar7 == 0x3a)) ||
       ((uVar7 == 0x22 || (uVar7 == 0x7c)))) {
      iVar9 = -2;
      goto LAB_c03470f0;
    }
    if (-1 < iVar9) {
      if ((uVar7 == 0x3f) || (uVar7 == 0x2a)) {
        iVar9 = -1;
      }
      else {
        if (uVar7 != 0x20) {
          if ((((uVar7 == 0x2b) || (uVar7 == 0x2c)) || (uVar7 == 0x3b)) ||
             (((uVar7 == 0x3d || (uVar7 == 0x5b)) || (uVar7 == 0x5d)))) {
            iVar9 = 0;
            uVar5 = 0x5f;
          }
          else {
            wVar3 = towupper(*param_2);
            uVar5 = CONCAT22(extraout_var,wVar3);
          }
          local_3e = (WCHAR)uVar5;
          if ((iVar9 == 1) && (uVar5 != uVar7)) {
            iVar9 = 2;
          }
          if (uVar5 == 0x2e) {
            iVar12 = iVar12 + 1;
            if ((2 < iVar12) || (iVar12 != 9 - iVar10)) {
              if (1 < iVar12) {
                iVar9 = 0;
              }
              if (local_30 < param_2 + 1) {
                pCVar11 = param_3 + 8;
                iVar10 = 3;
              }
              goto LAB_c03470cc;
            }
            bVar1 = true;
          }
          else {
            if (bVar1) break;
            if ((((*(uint *)(*(int *)(local_34 + 0xc) + 0x68) & 0x800000) != 0) && (0x7f < uVar5))
               || (iVar10 == 0)) goto LAB_c0346ec8;
          }
          local_40[0] = '_';
          local_40[1] = 0;
          iVar6 = WideCharToMultiByte(*(UINT *)(*(int *)(local_34 + 0xc) + 100),0,&local_3e,1,
                                      local_3c,2,local_40,&local_2c);
          if ((iVar6 != 0) && (iVar6 <= iVar10)) {
            iVar10 = iVar10 - iVar6;
            iVar8 = 0;
            if (0 < iVar6) {
              do {
                if ((pCVar11 == param_3) && (local_3c[iVar8] == -0x1b)) {
                  *pCVar11 = '_';
                }
                else {
                  *pCVar11 = local_3c[iVar8];
                }
                iVar8 = iVar8 + 1;
                pCVar11 = pCVar11 + 1;
              } while (iVar8 < iVar6);
            }
            if ((local_2c != 0) || (1 < iVar6)) {
              bVar2 = true;
            }
            goto LAB_c03470cc;
          }
          iVar10 = 0;
        }
LAB_c0346ec8:
        iVar9 = 0;
      }
    }
LAB_c03470cc:
    sVar4 = local_38 - 1;
    param_2 = param_2 + 1;
    local_38 = sVar4;
  } while( true );
  iVar9 = 0;
  sVar4 = local_38;
  goto LAB_c0346e10;
}



/* c034713c FUN_c034713c */

uint FUN_c034713c(int param_1,int param_2)

{
  uint uVar1;
  
  if (*(uint *)(*(int *)(param_1 + 0xc) + 0x44) < 0x10000) {
    uVar1 = (uint)*(ushort *)(param_2 + 0x1a);
  }
  else {
    uVar1 = (uint)*(ushort *)(param_2 + 0x14) * 0x10000 + (uint)*(ushort *)(param_2 + 0x1a);
  }
  return uVar1;
}



/* c03471a8 FUN_c03471a8 */

/* Boundary evidence: original MIPS .pdata c03471a8..c03472d3. Semantic name remains unreviewed. */

void FUN_c03471a8(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  bVar1 = *(byte *)(param_3 + 0xb);
  *(uint *)(param_2 + 0xc) = bVar1 & 0xffffffbf;
  if ((bVar1 & 0xbf) == 0) {
    *(undefined4 *)(param_2 + 0xc) = 0x80;
  }
  uVar2 = FUN_c034713c(param_1,param_3);
  *(uint *)(param_2 + 0x3c) = uVar2;
  if ((*(uint *)(param_2 + 0xc) & 0x10) == 0) {
    *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined4 *)(param_2 + 0x44) = 0;
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  else {
    *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 4;
  }
  FUN_c033b9ac((uint)*(ushort *)(param_3 + 0x10),(uint)*(ushort *)(param_3 + 0xe),
               (ushort)*(byte *)(param_3 + 0xd),(LPFILETIME)(param_2 + 0x18));
  FUN_c033b9ac((uint)*(ushort *)(param_3 + 0x18),(uint)*(ushort *)(param_3 + 0x16),0,
               (LPFILETIME)(param_2 + 0x28));
  FUN_c033b9ac((uint)*(ushort *)(param_3 + 0x12),0,0,(LPFILETIME)(param_2 + 0x20));
  return;
}



/* c03472d4 FUN_c03472d4 */

/* Boundary evidence: original MIPS .pdata c03472d4..c0347e4b. Semantic name remains unreviewed. */

int FUN_c03472d4(int param_1,undefined4 *param_2,uint *param_3,uint *param_4)

{
  bool bVar1;
  uint *puVar2;
  bool bVar3;
  HRESULT HVar4;
  uint uVar5;
  uint uVar6;
  undefined3 extraout_var;
  int iVar7;
  wchar_t *_Buf2;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  wchar_t *pwVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  size_t sVar14;
  size_t _Size;
  undefined8 uVar15;
  wchar_t *local_28c;
  size_t local_288;
  wchar_t *local_284;
  uint local_280;
  wchar_t *local_27c;
  wchar_t *local_278;
  undefined4 local_274;
  uint local_270;
  int local_26c;
  wchar_t *local_268;
  undefined4 *local_264;
  uint local_260;
  uint local_25c;
  wchar_t *local_258;
  wchar_t *local_254;
  uint local_250;
  uint *local_24c;
  int local_248;
  uint *local_244;
  wchar_t *local_240;
  uint local_23c;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c034d334;
  iVar11 = 0;
  local_28c = (wchar_t *)0x0;
  local_268 = (wchar_t *)0x0;
  local_25c = 0;
  puVar13 = (undefined4 *)0x0;
  local_264 = (undefined4 *)0x0;
  bVar1 = false;
  bVar3 = false;
  local_274 = 0;
  local_258 = (wchar_t *)0x0;
  local_26c = 0;
  local_284 = (wchar_t *)0x0;
  local_278 = (wchar_t *)*param_2;
  local_288 = 0;
  local_280 = param_2[1];
  uVar12 = param_2[2];
  local_270 = uVar12;
  local_250 = local_280;
  local_24c = param_4;
  local_248 = param_1;
  local_244 = param_3;
  if ((local_280 & 4) != 0) {
    puVar13 = FUN_c0332264(0x20);
    if (puVar13 == (undefined4 *)0x0) {
      puVar13 = (undefined4 *)0x0;
    }
    else {
      puVar13 = FUN_c0346b18(puVar13);
    }
    local_264 = puVar13;
    if (puVar13 == (undefined4 *)0x0) {
      FUN_c034b674(local_30);
      return 8;
    }
    iVar11 = FUN_c034a99c((int)puVar13);
    if (iVar11 != 0) goto LAB_c03473fc;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  HVar4 = StringCchLengthW((STRSAFE_PCNZWCH)*param_2,0x104,&local_288);
  pwVar9 = local_278;
  if (HVar4 < 0) {
    iVar11 = 0x1f;
  }
  else if (param_2[2] == -1) {
    iVar11 = 2;
  }
  else {
    local_27c = (wchar_t *)param_4[4];
    if (local_27c == (wchar_t *)0x0) {
      local_27c = awStack_238;
    }
    param_4[5] = 0xffffffff;
    pwVar8 = (wchar_t *)(param_4 + 8);
    _Buf2 = local_278;
    uVar5 = FUN_c0346da4(param_1,local_278,(CHAR *)pwVar8);
    param_4[3] = uVar5;
    if ((uVar5 == 0xfffffffe) || ((uVar5 == 0xffffffff && ((local_280 & 1) == 0)))) {
      iVar11 = 0x7b;
      bVar1 = bVar3;
    }
    else {
      if (0 < (int)uVar5) {
        if (uVar5 == 1) {
          local_280 = local_280 & 0xfffffffb;
          bVar3 = true;
          local_274 = 1;
          local_250 = local_280;
        }
        else if (uVar5 == 2) {
          param_4[7] = local_288;
          param_4[6] = (uint)pwVar9;
          bVar3 = true;
          local_274 = 1;
        }
        else {
          param_4[3] = 0;
        }
      }
      if (param_4[3] == 0) {
        local_26c = 1;
        pwVar9 = pwVar9 + local_288;
        param_4[6] = (uint)pwVar9;
        param_4[3] = (local_288 + 0xc) / 0xd + 1;
        param_4[7] = local_288 % 0xd;
        if (local_288 % 0xd == 0) {
          param_4[7] = 0xd;
        }
        param_4[6] = (uint)(pwVar9 + -param_4[7]);
      }
      uVar5 = 0xffffffff;
      bVar1 = bVar3;
      if ((puVar13 == (undefined4 *)0x0) ||
         (iVar11 = FUN_c034a9bc((int)puVar13,pwVar8), _Buf2 = pwVar8, iVar11 == 0)) {
        while (iVar11 == 0) {
          iVar11 = FUN_c03451b8(*(int *)(param_1 + 0x10),_Buf2,uVar12,0,(int *)&local_28c,
                                (int *)&local_268);
          pwVar9 = local_28c;
          if (iVar11 != 0) {
            if ((iVar11 == 0x26) && (iVar11 = 0xd, uVar12 != 0)) {
              iVar11 = 2;
            }
            param_4[5] = 0xffffffff;
            break;
          }
          if (((*(int *)(param_1 + 0x14) != 0) && (uVar12 == 0)) &&
             (pwVar8 = local_28c + 0x10, pwVar8 < local_268)) {
            if ((*(uint *)local_28c != 0x2020202e) || (*(uint *)pwVar8 != 0x20202e2e)) {
              iVar11 = 0xd;
              break;
            }
            uVar6 = FUN_c034713c(param_1,(int)local_28c);
            if (uVar6 != *(uint *)(param_1 + 0x7c)) {
              iVar11 = 0x570;
              break;
            }
            FUN_c034713c(param_1,(int)pwVar8);
            _Buf2 = pwVar8;
          }
          do {
            pwVar8 = local_284;
            uVar6 = (uint)(byte)*pwVar9;
            if (uVar6 == 0xe5) {
              uVar5 = param_4[1];
              local_28c = pwVar9;
              if (((int)uVar5 < (int)param_4[3]) && (param_4[1] = uVar5 + 1, uVar5 == 0)) {
                param_4[2] = uVar12;
              }
LAB_c0347c44:
              local_260 = 0xffffffff;
              param_4[5] = 0xffffffff;
            }
            else {
              if (uVar6 == 0) {
                uVar5 = param_4[1];
                if (((int)uVar5 < (int)param_4[3]) && (param_4[1] = uVar5 + 1, uVar5 == 0)) {
                  param_4[2] = uVar12;
                }
                bVar3 = FUN_c0338b04(param_1);
                if (CONCAT31(extraout_var,bVar3) != 0) {
                  uVar6 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
                  uVar5 = uVar12 + 0x20 + uVar6;
                  FUN_c0338ad8(param_1,_Buf2,uVar5 - 1 & ~(uVar6 - 1),
                               ((uVar5 < uVar12 + 0x20) - 1) + (uint)(uVar5 - 1 < uVar5) &
                               ~((uVar6 - 1 < uVar6) - 1));
                  uVar15 = FUN_c0338ac4(param_1);
                  FUN_c0338b20(param_1,_Buf2,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
                }
                param_4[5] = 0xffffffff;
                iVar11 = 2;
                goto LAB_c0347d6c;
              }
              if ((*(byte *)((int)pwVar9 + 0xb) & 0x1f) != 0xf) {
                if (((*(byte *)((int)pwVar9 + 0xb) & 0x18) == 8) ||
                   (((local_280 & 2) == 0 &&
                    ((*(uint *)pwVar9 == 0x2020202e || (*(uint *)pwVar9 == 0x20202e2e))))))
                goto LAB_c0347c28;
                if (uVar5 == 0) {
                  uVar6 = 0;
                  pwVar10 = pwVar9;
                  for (iVar7 = 0; iVar7 < 0xb; iVar7 = iVar7 + 1) {
                    uVar6 = (uVar6 << 7 | uVar6 >> 1) + (uint)(byte)*pwVar10 & 0xff;
                    pwVar10 = (wchar_t *)((int)pwVar10 + 1);
                  }
                  if (local_25c != uVar6) {
                    if (param_4[1] * 0x20 + param_4[2] == param_4[5]) {
                      param_4[1] = param_4[1] + (uVar12 - param_4[5] >> 5);
                    }
                    else {
                      param_4[1] = 0;
                    }
                    uVar5 = 0xffffffff;
                    local_260 = 0xffffffff;
                    goto LAB_c0347b68;
                  }
                  sVar14 = wcslen(local_284);
                  if (local_26c == 0) {
                    if (param_4[3] != 0xffffffff) {
                      if ((sVar14 != local_288) ||
                         (_Buf2 = local_278, iVar7 = _wcsnicmp(pwVar8,local_278,sVar14),
                         pwVar9 = local_28c, iVar7 != 0)) goto LAB_c0347b68;
                      goto LAB_c0347c84;
                    }
LAB_c0347be4:
                    _Buf2 = local_278;
                    iVar7 = MatchesWildcardMask(local_288,local_278,sVar14,pwVar8);
                    pwVar9 = local_28c;
                    if (iVar7 == 0) goto LAB_c0347c0c;
                  }
                }
                else {
LAB_c0347b68:
                  if (param_4[3] != 0xffffffff) {
                    if (bVar3) {
                      _Buf2 = (wchar_t *)(param_4 + 8);
                      iVar7 = memcmp(pwVar9,_Buf2,0xb);
                      if (iVar7 == 0) goto LAB_c0347ba0;
                    }
LAB_c0347c0c:
                    if (puVar13 != (undefined4 *)0x0) {
                      FUN_c034aa8c((int)puVar13,pwVar9);
                      _Buf2 = pwVar9;
                      pwVar9 = local_28c;
                    }
                    goto LAB_c0347c28;
                  }
LAB_c0347ba0:
                  pwVar8 = local_27c;
                  if (uVar5 != 0xffffffff) {
                    iVar11 = 0x7b;
                    goto LAB_c0347d6c;
                  }
                  local_284 = local_27c;
                  local_254 = local_27c;
                  sVar14 = FUN_c0346c0c(param_1,local_27c,(BYTE *)pwVar9);
                  pwVar9 = local_28c;
                  if (!bVar3) goto LAB_c0347be4;
                }
LAB_c0347c84:
                puVar2 = local_244;
                if (local_244 == (uint *)0x0) {
LAB_c0347d0c:
                  pwVar9 = local_27c;
                  if (pwVar8 != local_27c) {
                    memcpy(local_27c,pwVar8,sVar14 * 2);
                    pwVar9[sVar14] = L'\0';
                  }
                  local_28c = (wchar_t *)0x0;
                  uVar12 = uVar12 + 0x20;
                  local_270 = uVar12;
                }
                else {
                  uVar5 = param_4[5];
                  if (uVar5 == 0xffffffff) {
                    local_244[2] = 1;
LAB_c0347cd8:
                    *local_244 = uVar12;
                    FUN_c03471a8(param_1,(int)local_244,(int)pwVar9);
                    iVar7 = FUN_c03352d8(*(int *)(param_1 + 0xc),(int)puVar2);
                    if (iVar7 != 0) goto LAB_c0347d0c;
                  }
                  else if (uVar5 <= uVar12) {
                    local_244[2] = (uVar12 - uVar5 >> 5) + 1;
                    goto LAB_c0347cd8;
                  }
                  iVar11 = 0x1f;
                }
                goto LAB_c0347d6c;
              }
              sVar14 = 0xd;
              _Size = 4;
              if ((byte)pwVar9[6] != 0) {
LAB_c0347c28:
                local_28c = pwVar9;
                if ((int)param_4[1] < (int)param_4[3]) {
                  param_4[1] = 0;
                }
                goto LAB_c0347c44;
              }
              if (((byte)*pwVar9 & 0x40) == 0) {
                if (uVar5 != 0xffffffff) {
                  if ((uVar5 == uVar6) && (local_25c == *(byte *)((int)pwVar9 + 0xd)))
                  goto LAB_c03478f8;
                  uVar5 = param_4[5];
                  if (uVar5 != 0xffffffff) {
                    if (param_4[1] * 0x20 + param_4[2] == uVar5) {
                      param_4[1] = param_4[1] + (uVar12 - uVar5 >> 5);
                    }
                  }
                }
                goto LAB_c0347c28;
              }
              uVar5 = uVar6 & 0xffffffbf;
              if ((0x14 < uVar5) ||
                 (((!bVar3 && (1 < (int)param_4[3])) && (uVar5 != param_4[3] - 1))))
              goto LAB_c0347c28;
              local_25c = (uint)*(byte *)((int)pwVar9 + 0xd);
              param_4[5] = uVar12;
              sVar14 = param_4[7];
              local_258 = (wchar_t *)param_4[6];
              local_284 = local_27c + 0x103;
              *local_284 = L'\0';
              local_260 = uVar5;
              local_240 = local_258;
              local_23c = local_25c;
              if (uVar5 == 0x14) {
                local_284 = local_27c + 0x104;
                _Size = 2;
              }
LAB_c03478f8:
              if ((int)param_4[1] < (int)param_4[3]) {
                param_4[1] = 0;
              }
              local_284 = local_284 + -0xd;
              local_254 = local_284;
              memcpy(local_284,(byte *)((int)pwVar9 + 1),10);
              memcpy(local_284 + 5,pwVar9 + 7,0xc);
              pwVar8 = local_284;
              _Buf2 = pwVar9 + 0xe;
              memcpy(local_284 + 0xb,_Buf2,_Size);
              pwVar9 = local_258;
              if (local_26c != 0) {
                if (((sVar14 != 0xd) && (pwVar8[sVar14] != L'\0')) ||
                   (_Buf2 = local_258, iVar7 = _wcsnicmp(pwVar8,local_258,sVar14), iVar7 != 0))
                goto LAB_c0347c44;
                local_258 = pwVar9 + -0xd;
                local_240 = local_258;
              }
              local_260 = uVar5 - 1;
            }
            uVar12 = uVar12 + 0x20;
            pwVar9 = local_28c + 0x10;
            uVar5 = local_260;
            local_28c = pwVar9;
            local_270 = uVar12;
          } while (pwVar9 < local_268);
        }
      }
    }
  }
LAB_c0347d6c:
  uVar5 = local_280;
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  if ((((uVar5 & 4) != 0) && (puVar13 != (undefined4 *)0x0)) && (!bVar1)) {
    FUN_c034ad04((int)puVar13,param_4 + 8);
  }
  *param_4 = uVar12;
  if (puVar13 != (undefined4 *)0x0) {
    (**(code **)*puVar13)(puVar13,1);
  }
LAB_c03473fc:
  FUN_c034b674(local_30);
  return iVar11;
}



/* c0347e4c FUN_c0347e4c */

/* Boundary evidence: original MIPS .pdata c0347e4c..c0347e57. Semantic name remains unreviewed. */

undefined4 FUN_c0347e4c(void)

{
  return 1;
}



/* c0347e58 FUN_c0347e58 */

/* Boundary evidence: original MIPS .pdata c0347e58..c0347ea3. Semantic name remains unreviewed. */

undefined4 * FUN_c0347e58(undefined4 *param_1,uint param_2)

{
  FUN_c0345d70(param_1);
  if ((param_2 & 1) != 0) {
    FUN_c03322a0(param_1);
  }
  return param_1;
}



/* c0347ea4 FUN_c0347ea4 */

/* Boundary evidence: original MIPS .pdata c0347ea4..c0348127. Semantic name remains unreviewed. */

int FUN_c0347ea4(int param_1,uint *param_2,uint *param_3)

{
  bool bVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined8 uVar9;
  
  piVar8 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  iVar6 = 0;
  bVar1 = false;
  if ((int)param_2[3] < 0) {
    return 0x57;
  }
  puVar3 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  uVar7 = *param_2;
  if (param_2[1] != 0) {
    uVar7 = param_2[2];
  }
  bVar2 = FUN_c0338b04(param_1);
  if ((CONCAT31(extraout_var,bVar2) != 0) && (iVar6 = FUN_c03397c4(param_1,puVar3), iVar6 != 0))
  goto LAB_c03480f0;
  uVar4 = param_2[3] * 0x20 + uVar7;
  uVar9 = FUN_c0338ac4(param_1);
  if (((int)((ulonglong)uVar9 >> 0x20) == 0) && ((uint)uVar9 < uVar4)) {
    if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) != 0) {
      if (*(int *)(param_1 + 0x14) != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
      }
      FUN_c03410b8((int)piVar8);
      bVar1 = true;
    }
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 0x38);
    uVar5 = (iVar6 + uVar7) - 1 & ~(iVar6 - 1U);
    uVar4 = (iVar6 + uVar4) - 1 & ~(iVar6 - 1U);
    if (uVar4 < 0x200001) {
      iVar6 = FUN_c0338b48(param_1,puVar3,uVar4,0);
      if ((iVar6 == 0) &&
         (iVar6 = FUN_c0345a80(*(int *)(param_1 + 0x10),puVar3,uVar5,0,uVar4 - uVar5,0,0,(uint *)0x0
                              ), iVar6 == 0)) {
        FUN_c0338b20(param_1,puVar3,uVar4,0);
        iVar6 = FUN_c03399e4(param_1);
        if ((iVar6 == 0) &&
           ((((uVar4 = *(uint *)(*(int *)(param_1 + 0xc) + 0x6c), (uVar4 & 0x20) == 0 ||
              ((uVar4 & 0x10) != 0)) || (*(int *)(param_1 + 0x14) == 0)) ||
            (iVar6 = FUN_c0338b2c(*(int *)(param_1 + 0x14),0), iVar6 == 0)))) goto LAB_c03480c0;
      }
    }
    else {
      iVar6 = 0x70;
    }
  }
  else {
LAB_c03480c0:
    *param_3 = uVar7;
    param_3[2] = param_2[3];
  }
  if (bVar1) {
    FUN_c03410d4(piVar8);
    if (*(int *)(param_1 + 0x14) != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(*(int *)(param_1 + 0x14) + 0xa0));
    }
  }
LAB_c03480f0:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar6;
}



/* c0348128 FUN_c0348128 */

/* Boundary evidence: original MIPS .pdata c0348128..c034831f. Semantic name remains unreviewed. */

int FUN_c0348128(uint param_1,uint *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined1 *local_30;
  undefined1 *local_2c;
  
  local_30 = (undefined1 *)0x0;
  local_2c = (undefined1 *)0x0;
  piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  FUN_c03410b8((int)piVar3);
  uVar4 = *param_2;
  iVar2 = FUN_c0346b50(param_1,uVar4,(int *)&local_30,(int *)&local_2c,1);
  if (iVar2 == 0) {
    *local_30 = 0xe5;
    if (((param_2[2] - 1) * 0x20 <= uVar4) &&
       (uVar4 = uVar4 + (param_2[2] - 1) * -0x20, uVar4 != 0xffffffff)) {
      bVar1 = false;
      do {
        iVar2 = FUN_c0346b50(param_1,uVar4,(int *)&local_30,(int *)&local_2c,1);
        if (iVar2 != 0) break;
        for (; local_30 < local_2c; local_30 = local_30 + 0x20) {
          if ((local_30[0xb] & 0x1f) != 0xf) {
            bVar1 = true;
            break;
          }
          *local_30 = 0xe5;
          uVar4 = uVar4 + 0x20;
        }
      } while (!bVar1);
    }
    iVar2 = FUN_c03443d4(*(int *)(param_1 + 0x10),0);
    if ((((iVar2 == 0) && (param_3 != 0)) && (param_2[0xf] != 0xffffffff)) &&
       (iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_2[0xf],0,0), iVar2 == 0)) {
      iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,0);
    }
  }
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  FUN_c03410d4(piVar3);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar2;
}



/* c0348320 FUN_c0348320 */

/* Boundary evidence: original MIPS .pdata c0348320..c034840f. Semantic name remains unreviewed. */

int FUN_c0348320(uint param_1)

{
  uint uVar1;
  int iVar2;
  int local_18 [2];
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
    local_18[0] = 0;
    iVar2 = FUN_c0346b50(param_1,0x20,local_18,(int *)0x0,0);
    if (iVar2 == 0) {
      uVar1 = 0;
      if (*(int *)(*(int *)(param_1 + 0x14) + 0x14) != 0) {
        uVar1 = *(uint *)(*(int *)(param_1 + 0x14) + 0x7c);
      }
      *(char *)(local_18[0] + 0x1a) = (char)(uVar1 & 0xffff);
      *(char *)(local_18[0] + 0x1b) = (char)((uVar1 & 0xffff) >> 8);
      if (0xffff < *(uint *)(*(int *)(param_1 + 0xc) + 0x44)) {
        *(char *)(local_18[0] + 0x14) = (char)(uVar1 >> 0x10);
        *(char *)(local_18[0] + 0x15) = (char)(uVar1 >> 0x18);
      }
      iVar2 = FUN_c03443d4(*(int *)(param_1 + 0x10),0);
    }
    FUN_c03441c4(*(int *)(param_1 + 0x10));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  }
  return iVar2;
}



/* c0348410 FUN_c0348410 */

/* Boundary evidence: original MIPS .pdata c0348410..c034856b. Semantic name remains unreviewed. */

undefined4 FUN_c0348410(int param_1,void *param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    memset(param_2,0x20,0xb);
    memset((void *)((int)param_2 + 0xb),0,0x15);
  }
  *(char *)((int)param_2 + 0xb) = (char)*(undefined4 *)(param_3 + 0xc);
  if ((*(uint *)(param_3 + 0xc) & 0x10) == 0) {
    *(undefined4 *)((int)param_2 + 0x1c) = *(undefined4 *)(param_3 + 0x40);
  }
  else {
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
  }
  uVar1 = *(uint *)(param_3 + 0x3c);
  if ((uVar1 == 0xffffffff) || (uVar1 < 2)) {
    *(undefined1 *)((int)param_2 + 0x1a) = 0;
    *(undefined1 *)((int)param_2 + 0x1b) = 0;
    if (0xffff < *(uint *)(*(int *)(param_1 + 0xc) + 0x44)) {
      *(undefined1 *)((int)param_2 + 0x14) = 0;
      *(undefined1 *)((int)param_2 + 0x15) = 0;
    }
  }
  else {
    *(char *)((int)param_2 + 0x1a) = (char)(uVar1 & 0xffff);
    *(char *)((int)param_2 + 0x1b) = (char)((uVar1 & 0xffff) >> 8);
    if (0xffff < *(uint *)(*(int *)(param_1 + 0xc) + 0x44)) {
      *(char *)((int)param_2 + 0x14) = (char)(uVar1 >> 0x10);
      *(char *)((int)param_2 + 0x15) = (char)(uVar1 >> 0x18);
    }
  }
  FUN_c033ba9c((FILETIME *)(param_3 + 0x18),(ushort *)((int)param_2 + 0x10),
               (ushort *)((int)param_2 + 0xe),(undefined1 *)((int)param_2 + 0xd));
  FUN_c033ba9c((FILETIME *)(param_3 + 0x28),(ushort *)((int)param_2 + 0x18),
               (ushort *)((int)param_2 + 0x16),(undefined1 *)0x0);
  FUN_c033ba9c((FILETIME *)(param_3 + 0x20),(ushort *)((int)param_2 + 0x12),(ushort *)0x0,
               (undefined1 *)0x0);
  return 0;
}



/* c034856c FUN_c034856c */

/* Boundary evidence: original MIPS .pdata c034856c..c03486b7. Semantic name remains unreviewed. */

int FUN_c034856c(int param_1)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  undefined1 auStack_a8 [60];
  undefined4 local_6c;
  undefined1 local_58 [32];
  undefined1 local_38;
  undefined1 local_37;
  uint local_18;
  
  local_18 = DAT_c034d334;
  iVar3 = *(int *)(param_1 + 0x10);
  puVar2 = *(uint **)(iVar3 + 0x14);
  *puVar2 = *puVar2 & 0xfffffffb;
  iVar3 = *(int *)(iVar3 + 0x14);
  *(undefined4 *)(iVar3 + 8) = 0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  memcpy(auStack_a8,(void *)(param_1 + 0x40),0x50);
  FUN_c0348410(param_1,local_58,(int)auStack_a8,1);
  local_58[0] = 0x2e;
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x14) == 0) {
    local_6c = 0;
  }
  else {
    local_6c = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x7c);
  }
  puVar1 = &local_38;
  FUN_c0348410(param_1,puVar1,(int)auStack_a8,1);
  local_38 = 0x2e;
  local_37 = 0x2e;
  iVar3 = FUN_c0345604(*(int *)(param_1 + 0x10),puVar1,0,0,local_58,0x40,0,(int *)0x0);
  if (iVar3 == 0) {
    iVar3 = FUN_c0345a80(*(int *)(param_1 + 0x10),puVar1,0x40,0,
                         *(int *)(*(int *)(param_1 + 0xc) + 0x38) - 0x40,0,0,(uint *)0x0);
    if (iVar3 == 0) {
      iVar3 = FUN_c0338b2c(param_1,0);
    }
  }
  FUN_c034b674(local_18);
  return iVar3;
}



/* c03486b8 FUN_c03486b8 */

/* Boundary evidence: original MIPS .pdata c03486b8..c0348acf. Semantic name remains unreviewed. */

int FUN_c03486b8(uint param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                uint *param_6)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  void *_Src;
  byte local_50;
  byte *local_4c;
  int local_48;
  uint local_44;
  int local_40;
  byte *local_3c;
  int local_38;
  byte *local_34;
  byte *local_30;
  int local_2c;
  
  local_44 = 0xffffffff;
  piVar6 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  uVar7 = param_6[3];
  local_48 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  local_30 = (byte *)(param_3 + 0x20);
  if (*local_30 == 0) {
    iVar4 = 0x70;
    iVar3 = 0;
  }
  else {
    if ((param_4 == 0) && ((uVar7 & 0x10) != 0)) {
      FUN_c03410b8((int)piVar6);
      local_48 = 1;
      iVar4 = (**(code **)(*piVar6 + 0x1c))(piVar6,0xffffffff,1,&local_44,0);
      iVar3 = 1;
      if ((iVar4 != 0) ||
         (iVar4 = (**(code **)(*piVar6 + 0x10))(piVar6,local_44,0xffffffff,0), iVar4 != 0))
      goto LAB_c0348a4c;
      param_6[0xf] = local_44;
    }
    uVar7 = *(uint *)(param_3 + 0x1c);
    _Src = *(void **)(param_3 + 0x18);
    uVar9 = *param_6;
    uVar8 = *(uint *)(param_3 + 0xc);
    local_38 = 0;
    local_4c = (byte *)0x0;
    local_34 = (byte *)0x0;
    if (uVar7 < 0xd) {
      uVar7 = uVar7 + 1;
    }
    uVar5 = 0;
    local_50 = 0;
    if (1 < uVar8) {
      local_40 = uVar8 + 0xff;
      do {
        if (local_34 <= local_4c) {
          iVar4 = FUN_c0346b50(param_1,uVar9,(int *)&local_4c,(int *)&local_34,2);
          iVar3 = local_48;
          if (iVar4 != 0) goto LAB_c0348a4c;
          uVar5 = (uint)local_50;
        }
        memset(local_4c,0xff,0x20);
        *local_4c = (byte)local_40;
        if (local_38 == 0) {
          uVar5 = 0;
          iVar3 = 0xb;
          pbVar2 = local_30;
          do {
            uVar1 = (uVar5 << 7 | uVar5 >> 1) + (uint)*pbVar2;
            uVar5 = uVar1 & 0xff;
            iVar3 = iVar3 + -1;
            pbVar2 = pbVar2 + 1;
          } while (iVar3 != 0);
          local_50 = (byte)uVar1;
          *local_4c = *local_4c | 0x40;
        }
        local_4c[0xb] = 0xf;
        local_4c[0xc] = 0;
        local_4c[0xd] = (byte)uVar5;
        local_4c[0x1a] = 0;
        local_4c[0x1b] = 0;
        uVar1 = 5;
        if (uVar7 < 5) {
          uVar1 = uVar7;
        }
        local_38 = local_38 + 1;
        memcpy(local_4c + 1,_Src,uVar1 << 1);
        if (uVar7 < 0xb) {
          iVar3 = uVar7 - 5;
          if (0 < iVar3) goto LAB_c034892c;
        }
        else {
          iVar3 = 6;
LAB_c034892c:
          memcpy(local_4c + 0xe,(void *)((int)_Src + 10),iVar3 << 1);
        }
        if (uVar7 < 0xd) {
          iVar3 = uVar7 - 0xb;
          if (0 < iVar3) goto LAB_c0348960;
        }
        else {
          iVar3 = 2;
LAB_c0348960:
          memcpy(local_4c + 0x1c,(void *)((int)_Src + 0x16),iVar3 << 1);
        }
        local_40 = local_40 + -1;
        local_4c = local_4c + 0x20;
        uVar8 = uVar8 - 1;
        _Src = (void *)((int)_Src + -0x1a);
        uVar7 = 0xd;
        uVar9 = uVar9 + 0x20;
      } while (1 < uVar8);
    }
    local_2c = 0;
    local_3c = local_4c;
    iVar4 = FUN_c0346b50(param_1,uVar9,(int *)&local_3c,&local_2c,2);
    iVar3 = local_48;
    if (iVar4 == 0) {
      *param_6 = uVar9;
      iVar4 = FUN_c0348410(param_1,local_3c,(int)param_6,1);
      iVar3 = local_48;
      if (iVar4 == 0) {
        memcpy(local_3c,local_30,0xb);
        iVar4 = FUN_c03443d4(*(int *)(param_1 + 0x10),0);
        iVar3 = local_48;
        if (iVar4 == 0) {
          iVar4 = (**(code **)(*piVar6 + 0x30))(piVar6,0);
          iVar3 = local_48;
        }
      }
    }
  }
LAB_c0348a4c:
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  if ((local_44 != 0xffffffff) && (iVar4 != 0)) {
    (**(code **)(*piVar6 + 0x10))(piVar6,local_44,0,0);
  }
  if (iVar3 != 0) {
    FUN_c03410d4(piVar6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar4;
}



/* c0348ad0 FUN_c0348ad0 */

/* Boundary evidence: original MIPS .pdata c0348ad0..c0348b6f. Semantic name remains unreviewed. */

int FUN_c0348ad0(uint param_1,uint *param_2,int param_3)

{
  int iVar1;
  void *local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  local_20[0] = (void *)0x0;
  iVar1 = FUN_c0346b50(param_1,*param_2,(int *)local_20,(int *)0x0,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_c0348410(param_1,local_20[0],(int)param_2,0);
  }
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar1;
}



/* c0348b70 FUN_c0348b70 */

uint FUN_c0348b70(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if ((param_2 == 0) || ((uVar2 != 2 && (uVar2 != 3)))) {
      iVar1 = 0x8000;
      if ((param_3 & 1) == 0) {
        iVar1 = 0;
      }
      param_3 = (uint)*(byte *)(uVar2 + param_1) + (param_3 >> 1) + iVar1 & 0xffff;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x20);
  return param_3;
}



/* c0348bdc FUN_c0348bdc */

/* Boundary evidence: original MIPS .pdata c0348bdc..c0348cd3. Semantic name remains unreviewed. */

void FUN_c0348bdc(int param_1,void *param_2)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_38 [32];
  
  iVar2 = *(int *)(param_1 + 0xc);
  if ((*(uint *)(iVar2 + 0x6c) & 0x10) == 0) {
    iVar2 = FUN_c0345a80(*(int *)(param_1 + 0x10),param_2,0,0,*(uint *)(iVar2 + 0x38),0,0,
                         (uint *)0x0);
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    pvVar1 = (void *)0x0;
    memset(local_38,0,0x20);
    local_38[0] = 0xa1;
    uVar3 = 0;
    if (*(int *)(iVar2 + 0x38) != 0) {
      do {
        iVar2 = FUN_c0345604(*(int *)(param_1 + 0x10),pvVar1,uVar3,0,local_38,0x20,0,(int *)0x0);
        if (iVar2 != 0) {
          return;
        }
        uVar3 = uVar3 + 0x20;
      } while (uVar3 < *(uint *)(*(int *)(param_1 + 0xc) + 0x38));
    }
  }
  FUN_c0338b2c(param_1,0);
  return;
}



/* c0348cd4 FUN_c0348cd4 */

/* Boundary evidence: original MIPS .pdata c0348cd4..c0348d2b. Semantic name remains unreviewed. */

int FUN_c0348cd4(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c03451b8(*(int *)(param_1 + 0x10),param_2,param_2,0,param_3,(int *)0x0);
  if (((iVar1 != 0) && (iVar1 == 0x26)) && (iVar1 = 0xd, param_2 != 0)) {
    iVar1 = 2;
  }
  return iVar1;
}



/* c0348d2c FUN_c0348d2c */

/* Boundary evidence: original MIPS .pdata c0348d2c..c0348ddb. Semantic name remains unreviewed. */

undefined4 FUN_c0348d2c(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 != 0) {
    memset(param_2,0,0x20);
    *param_2 = 0x85;
  }
  *(short *)(param_2 + 4) = (short)*(undefined4 *)(param_3 + 0xc);
  if (*(uint *)(param_3 + 8) < 0x100) {
    param_2[1] = (char)*(uint *)(param_3 + 8) + -1;
    FUN_c033bc64((FILETIME *)(param_3 + 0x18),(ushort *)(param_2 + 8),param_2 + 0x14);
    FUN_c033bc64((FILETIME *)(param_3 + 0x28),(ushort *)(param_2 + 0xc),param_2 + 0x15);
    FUN_c033bc64((FILETIME *)(param_3 + 0x20),(ushort *)(param_2 + 0x10),(undefined1 *)0x0);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c0348ddc FUN_c0348ddc */

/* Boundary evidence: original MIPS .pdata c0348ddc..c0348ea3. Semantic name remains unreviewed. */

undefined4 FUN_c0348ddc(undefined4 param_1,undefined1 *param_2,uint *param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  
  if (param_4 != 0) {
    memset(param_2,0,0x20);
    *param_2 = 0xc0;
  }
  *(uint *)(param_2 + 0x18) = param_3[2];
  *(uint *)(param_2 + 0x1c) = param_3[3];
  *(uint *)(param_2 + 8) = param_3[4];
  *(uint *)(param_2 + 0xc) = param_3[5];
  uVar2 = param_3[1];
  if ((uVar2 == 0xffffffff) || (uVar2 < 2)) {
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  else {
    *(uint *)(param_2 + 0x14) = uVar2;
  }
  bVar1 = param_2[1];
  param_2[1] = bVar1 | 1;
  if ((*param_3 & 2) == 0) {
    param_2[1] = bVar1 & 0xfd | 1;
  }
  else {
    param_2[1] = bVar1 | 3;
  }
  return 0;
}



/* c0348ea4 FUN_c0348ea4 */

/* Boundary evidence: original MIPS .pdata c0348ea4..c0348f3f. Semantic name remains unreviewed. */

undefined4 FUN_c0348ea4(undefined4 param_1,undefined1 *param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_4 != 0) {
    memset(param_2,0,0x20);
    *param_2 = 0xa2;
  }
  param_2[1] = 0;
  if (*(int *)(param_3 + 0x3c) != -1) {
    *(int *)(param_2 + 0x14) = *(int *)(param_3 + 0x3c);
  }
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_3 + 0x40);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_3 + 0x44);
  *(undefined2 *)(param_2 + 4) = 1;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_3 + 0x34);
  uVar1 = FUN_c0348b70((int)param_2,1,0);
  *(short *)(param_2 + 2) = (short)uVar1;
  return 0;
}



/* c0348f40 FUN_c0348f40 */

/* Boundary evidence: original MIPS .pdata c0348f40..c034906f. Semantic name remains unreviewed. */

undefined4 FUN_c0348f40(int param_1,wchar_t *param_2,uint param_3,undefined4 *param_4)

{
  wchar_t wVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  bVar2 = FUN_c033520c(*(undefined4 *)(param_1 + 0xc),param_2,L".");
  if ((CONCAT31(extraout_var,bVar2) == 0) &&
     (bVar2 = FUN_c033520c(*(undefined4 *)(param_1 + 0xc),param_2,L".."),
     CONCAT31(extraout_var_00,bVar2) == 0)) {
    uVar4 = 0;
    uVar3 = 1;
    if (param_3 != 0) {
      do {
        wVar1 = *param_2;
        if (((((wVar1 == L'\\') || (wVar1 == L'/')) || (wVar1 == L'>')) ||
            ((wVar1 == L'<' || (wVar1 == L':')))) || ((wVar1 == L'\"' || (wVar1 == L'|'))))
        goto LAB_c0349050;
        if (((wVar1 == L'*') || (wVar1 == L'?')) && (param_4 != (undefined4 *)0x0)) {
          *param_4 = 1;
        }
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 1;
      } while (uVar4 < param_3);
    }
  }
  else {
LAB_c0349050:
    uVar3 = 0;
  }
  return uVar3;
}



/* c0349070 FUN_c0349070 */

/* Boundary evidence: original MIPS .pdata c0349070..c0349123. Semantic name remains unreviewed. */

void FUN_c0349070(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar1 = *(ushort *)(param_3 + 4);
  *(uint *)(param_2 + 0xc) = uVar1 & 0xffffffbf;
  if ((uVar1 & 0xffbf) == 0) {
    *(undefined4 *)(param_2 + 0xc) = 0x80;
  }
  *(uint *)(param_2 + 8) = *(byte *)(param_3 + 1) + 1;
  FUN_c033bb64(*(uint *)(param_3 + 8),(ushort)*(byte *)(param_3 + 0x14),
               (uint)*(byte *)(param_3 + 0x16),(LPFILETIME)(param_2 + 0x18));
  FUN_c033bb64(*(uint *)(param_3 + 0xc),(ushort)*(byte *)(param_3 + 0x15),
               (uint)*(byte *)(param_3 + 0x17),(LPFILETIME)(param_2 + 0x28));
  FUN_c033bb64(*(uint *)(param_3 + 0x10),0,(uint)*(byte *)(param_3 + 0x18),
               (LPFILETIME)(param_2 + 0x20));
  return;
}



/* c0349124 FUN_c0349124 */

void FUN_c0349124(undefined4 param_1,uint *param_2,int param_3)

{
  param_2[1] = *(uint *)(param_3 + 0x14);
  param_2[4] = *(uint *)(param_3 + 8);
  param_2[5] = *(uint *)(param_3 + 0xc);
  param_2[2] = *(uint *)(param_3 + 0x18);
  param_2[3] = *(uint *)(param_3 + 0x1c);
  if ((*(byte *)(param_3 + 1) & 2) != 0) {
    *param_2 = *param_2 | 2;
  }
  return;
}



/* c0349170 FUN_c0349170 */

/* Boundary evidence: original MIPS .pdata c0349170..c03491f7. Semantic name remains unreviewed. */

int FUN_c0349170(int param_1,wchar_t *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &PTR_u__BITMAP0_c034d30c;
  iVar2 = 0;
  do {
    bVar1 = FUN_c033520c(*(undefined4 *)(param_1 + 0xc),(wchar_t *)*ppuVar3,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return iVar2;
    }
    ppuVar3 = ppuVar3 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)ppuVar3 < -0x3fcb2ce0);
  return 5;
}



/* c03491f8 FUN_c03491f8 */

/* Boundary evidence: original MIPS .pdata c03491f8..c0349b63. Semantic name remains unreviewed. */

int FUN_c03491f8(int param_1,undefined4 *param_2,uint *param_3,uint *param_4)

{
  byte bVar1;
  byte *pbVar2;
  bool bVar3;
  HRESULT HVar4;
  undefined3 extraout_var;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  wchar_t *pwVar12;
  int iVar13;
  undefined8 uVar14;
  byte *local_4b8;
  int local_4b4;
  size_t local_4b0;
  wchar_t *local_4ac;
  uint local_4a8;
  int local_4a4;
  wchar_t *local_4a0;
  short local_49c;
  uint local_498;
  uint *local_494;
  int local_490;
  int local_48c;
  uint local_488;
  undefined4 local_484;
  undefined1 auStack_480 [2];
  ushort local_47e;
  undefined1 auStack_460 [32];
  wchar_t awStack_440 [260];
  wchar_t local_238 [260];
  uint local_30;
  
  local_30 = DAT_c034d334;
  local_4b8 = (byte *)0x0;
  local_4a4 = 0;
  pwVar12 = (wchar_t *)*param_2;
  local_4b0 = 0;
  uVar10 = param_2[1];
  uVar11 = param_2[2];
  local_494 = param_4;
  local_48c = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  HVar4 = StringCchLengthW((STRSAFE_PCNZWCH)*param_2,0x104,&local_4b0);
  if (HVar4 < 0) {
    iVar13 = 0x1f;
    local_4b4 = iVar13;
  }
  else if (uVar11 == 0xffffffff) {
LAB_c03492ac:
    iVar13 = 2;
    local_4b4 = iVar13;
  }
  else {
    local_4a0 = (wchar_t *)param_4[4];
    if (local_4a0 == (wchar_t *)0x0) {
      local_4a0 = local_238;
    }
    iVar13 = FUN_c0348f40(param_1,pwVar12,local_4b0,&local_4a4);
    if ((iVar13 == 0) || ((local_4a4 != 0 && ((uVar10 & 1) == 0)))) {
      iVar13 = 0x7b;
      local_4b4 = iVar13;
    }
    else {
      iVar13 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                         (*(int **)(param_1 + 0xc),pwVar12,local_4b0,awStack_440);
      local_4b4 = iVar13;
      if (iVar13 == 0) {
        local_49c = FUN_c0340480((int)awStack_440,local_4b0 << 1);
        local_498 = FUN_c0349170(param_1,awStack_440);
        if ((local_498 == 5) || ((uVar10 & 8) != 0)) {
          uVar8 = uVar11;
          if ((uVar10 & 4) != 0) {
            if (local_498 == 5) {
              param_4[3] = (int)(local_4b0 + 0xe) / 0xf + param_2[3] + 2;
            }
            else {
              param_4[3] = 1;
            }
          }
LAB_c03493e8:
          do {
            uVar5 = uVar8;
            uVar10 = uVar5;
            local_4a8 = uVar5;
            iVar13 = FUN_c0348cd4(param_1,uVar5,(int *)&local_4b8);
            pbVar2 = local_4b8;
            uVar11 = uVar5;
            local_4b4 = iVar13;
            if (iVar13 != 0) goto LAB_c0349ad4;
            if (*local_4b8 == 0) {
              if (((int)param_4[1] < (int)param_4[3]) &&
                 (uVar8 = param_4[1] + 1, param_4[1] = uVar8, uVar8 == 1)) {
                param_4[2] = uVar5;
              }
              bVar3 = FUN_c0338b04(param_1);
              if (CONCAT31(extraout_var,bVar3) != 0) {
                uVar9 = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
                uVar8 = uVar5 + 0x20 + uVar9;
                FUN_c0338ad8(param_1,uVar10,uVar8 - 1 & ~(uVar9 - 1),
                             ((uVar8 < uVar5 + 0x20) - 1) + (uint)(uVar8 - 1 < uVar8) &
                             ~((uVar9 - 1 < uVar9) - 1));
                uVar14 = FUN_c0338ac4(param_1);
                FUN_c0338b20(param_1,uVar10,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
              }
              goto LAB_c03492ac;
            }
            if ((*local_4b8 & 0x80) == 0) {
              if (((int)param_4[1] < (int)param_4[3]) &&
                 (uVar11 = param_4[1] + 1, param_4[1] = uVar11, uVar11 == 1)) {
                param_4[2] = uVar5;
              }
              uVar8 = uVar5 + 0x20;
              goto LAB_c03493e8;
            }
            if ((int)param_4[1] < (int)param_4[3]) {
              param_4[1] = 0;
            }
            uVar11 = uVar5 + 0x20;
            bVar1 = *local_4b8;
            uVar8 = uVar11;
          } while ((bVar1 & 0x40) != 0);
          if (bVar1 == 0xa1) {
            iVar13 = *(int *)(*(int *)(param_1 + 0xc) + 0x38);
            local_484 = 0;
            uVar8 = (iVar13 + uVar11) - 1 & ~(iVar13 - 1U);
            goto LAB_c03493e8;
          }
          uVar10 = FUN_c0348b70((int)local_4b8,1,0);
          uVar7 = (ushort)uVar10;
          if ((uint)bVar1 != *(uint *)(&DAT_c03321a8 + local_498 * 4)) goto LAB_c03493e8;
          if (param_3 != (uint *)0x0) {
            *param_3 = local_4a8;
            param_3[0xc] = local_498;
          }
          if (local_498 == 5) {
            memcpy(auStack_480,pbVar2,0x20);
            uVar8 = (uint)pbVar2[1] * 0x20 + uVar11;
            iVar13 = FUN_c0348cd4(param_1,uVar11,(int *)&local_4b8);
            pbVar2 = local_4b8;
            local_4b4 = iVar13;
            if (iVar13 != 0) goto LAB_c0349ad4;
            if (*local_4b8 == 0xc0) {
              if ((local_4a4 != 0) || (*(short *)(local_4b8 + 4) == local_49c)) {
                memcpy(auStack_460,local_4b8,0x20);
                local_4ac = local_4a0;
                uVar10 = (uint)pbVar2[3];
                local_488 = uVar10;
                if (uVar10 < 0x104) {
                  uVar11 = FUN_c0348b70((int)pbVar2,0,(uint)uVar7);
                  uVar7 = (ushort)uVar11;
                  uVar11 = uVar5 + 0x40;
                  while( true ) {
                    uVar5 = uVar11;
                    if ((uVar10 == 0) || (uVar8 <= uVar11)) goto LAB_c03498d8;
                    iVar13 = FUN_c0348cd4(param_1,uVar11,(int *)&local_4b8);
                    local_4b4 = iVar13;
                    if (iVar13 != 0) goto LAB_c0349ad4;
                    if (*local_4b8 != 0xc1) break;
                    uVar5 = uVar10;
                    if (0xe < uVar10) {
                      uVar5 = 0xf;
                    }
                    local_4a8 = uVar5;
                    memcpy(local_4ac,local_4b8 + 2,uVar5 * 2);
                    local_4ac = local_4ac + uVar5;
                    uVar10 = uVar10 - local_4a8;
                    uVar5 = FUN_c0348b70((int)local_4b8,0,(uint)uVar7);
                    uVar7 = (ushort)uVar5;
                    uVar11 = uVar11 + 0x20;
                  }
                  (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
LAB_c03498d8:
                  uVar9 = local_488;
                  pwVar12 = local_4a0;
                  *local_4ac = L'\0';
                  if (uVar10 == 0) {
                    (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                              (*(int **)(param_1 + 0xc),local_4a0,local_488,local_238,uVar7,uVar5);
                    iVar6 = MatchesWildcardMask(local_4b0,awStack_440,uVar9,local_238);
                    if (iVar6 != 0) {
                      local_490 = 0;
                      iVar6 = FUN_c0348f40(param_1,pwVar12,uVar9,&local_490);
                      if ((iVar6 != 0) && (local_490 == 0)) {
                        if (param_3 != (uint *)0x0) {
                          FUN_c0349070(param_1,(int)param_3,(int)auStack_480);
                          FUN_c0349124(param_1,param_3 + 0xe,(int)auStack_460);
                          iVar6 = FUN_c03352d8(*(int *)(param_1 + 0xc),(int)param_3);
                          if (iVar6 == 0) goto LAB_c03493e8;
                          if (uVar11 < uVar8) {
                            param_3[1] = uVar11;
                          }
                        }
                        bVar3 = false;
                        for (; uVar11 < uVar8; uVar11 = uVar11 + 0x20) {
                          iVar13 = FUN_c0348cd4(param_1,uVar11,(int *)&local_4b8);
                          local_4b4 = iVar13;
                          if (iVar13 != 0) goto LAB_c0349ad4;
                          bVar1 = *local_4b8;
                          if ((bVar1 & 0x40) == 0) {
                            (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
                            uVar8 = uVar11;
                            goto LAB_c03493e8;
                          }
                          if (bVar1 == 0xe2) {
                            if (param_3 != (uint *)0x0) {
                              param_3[4] = *(uint *)(local_4b8 + 8);
                              param_3[5] = *(uint *)(local_4b8 + 0xc);
                            }
                          }
                          else if ((bVar1 & 0x20) == 0) {
                            bVar3 = true;
                            uVar11 = uVar8;
                            break;
                          }
                          uVar10 = FUN_c0348b70((int)local_4b8,0,(uint)uVar7);
                          uVar7 = (ushort)uVar10;
                        }
                        uVar8 = uVar11;
                        if (!bVar3) {
                          if (local_47e == uVar7) goto LAB_c0349ad4;
                          (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
                        }
                      }
                    }
                  }
                }
                else {
                  (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
                }
              }
            }
            else {
              (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
            }
            goto LAB_c03493e8;
          }
          if (param_3 == (uint *)0x0) goto LAB_c0349ad4;
          bVar1 = *pbVar2;
          if (bVar1 != 0x81) {
            if (bVar1 == 0x82) {
              param_3[0xf] = *(uint *)(pbVar2 + 0x14);
              param_3[0x10] = *(uint *)(pbVar2 + 0x18);
              param_3[0x11] = *(uint *)(pbVar2 + 0x1c);
              param_3[0x12] = *(uint *)(pbVar2 + 0x18);
              param_3[0x13] = *(uint *)(pbVar2 + 0x1c);
              uVar10 = *(uint *)(pbVar2 + 4);
            }
            else {
              if (bVar1 != 0xa2) goto LAB_c0349ad4;
              param_3[0xf] = *(uint *)(pbVar2 + 0x14);
              param_3[0x10] = *(uint *)(pbVar2 + 0x18);
              param_3[0x11] = *(uint *)(pbVar2 + 0x1c);
              param_3[0x12] = *(uint *)(pbVar2 + 0x18);
              param_3[0x13] = *(uint *)(pbVar2 + 0x1c);
              uVar10 = *(uint *)(pbVar2 + 8);
            }
            param_3[0xd] = uVar10;
            goto LAB_c0349ad4;
          }
          if (((pbVar2[1] & 1) == 0) != (local_498 == 0)) goto LAB_c03493e8;
          param_3[0xf] = *(uint *)(pbVar2 + 0x14);
          param_3[0x10] = *(uint *)(pbVar2 + 0x18);
          param_3[0x11] = *(uint *)(pbVar2 + 0x1c);
          param_3[0x12] = *(uint *)(pbVar2 + 0x18);
          param_3[0x13] = *(uint *)(pbVar2 + 0x1c);
        }
        else {
          iVar13 = 5;
          local_4b4 = iVar13;
        }
      }
    }
  }
LAB_c0349ad4:
  *param_4 = uVar11;
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  FUN_c034b674(local_30);
  return iVar13;
}



/* c0349b64 FUN_c0349b64 */

/* Boundary evidence: original MIPS .pdata c0349b64..c0349b6f. Semantic name remains unreviewed. */

undefined4 FUN_c0349b64(void)

{
  return 1;
}



/* c0349b70 FUN_c0349b70 */

/* Boundary evidence: original MIPS .pdata c0349b70..c0349c2b. Semantic name remains unreviewed. */

int FUN_c0349b70(int param_1)

{
  int iVar1;
  int iVar2;
  byte *local_20 [2];
  
  local_20[0] = (byte *)0x0;
  iVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  do {
    iVar1 = FUN_c0348cd4(param_1,iVar2,(int *)local_20);
    if (iVar1 != 0) {
LAB_c0349bec:
      FUN_c03441c4(*(int *)(param_1 + 0x10));
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
      if (iVar1 == 2) {
        iVar1 = 0;
      }
      return iVar1;
    }
    if ((0x85 < *local_20[0]) && (*local_20[0] < 0xa0)) {
      iVar1 = 0x3ed;
      goto LAB_c0349bec;
    }
    iVar2 = iVar2 + 0x20;
  } while( true );
}



/* c0349c2c FUN_c0349c2c */

/* Boundary evidence: original MIPS .pdata c0349c2c..c034a013. Semantic name remains unreviewed. */

int FUN_c0349c2c(uint param_1,uint *param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  byte *local_40;
  byte *local_3c;
  undefined4 local_38;
  int local_34;
  uint *local_30;
  
  local_40 = (byte *)0x0;
  local_3c = (byte *)0x0;
  piVar9 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  local_34 = param_3;
  local_30 = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  FUN_c03410b8((int)piVar9);
  uVar7 = *param_2;
  iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_40,(int *)&local_3c,1);
  if (iVar3 == 0) {
    if (((*local_40 & 0x40) == 0) && (*local_40 == 0x85)) {
      *local_40 = 5;
      uVar8 = 0;
      uVar4 = (uint)local_40[1];
      uVar11 = 0;
      bVar2 = false;
      uVar7 = uVar7 + 0x20;
      local_38 = 0;
      uVar5 = 0;
      if (uVar4 != 0) {
        do {
          iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_40,(int *)&local_3c,1);
          if ((iVar3 != 0) || (uVar4 <= uVar5)) break;
          do {
            uVar6 = uVar5;
            if (local_3c <= local_40) break;
            bVar1 = *local_40;
            uVar6 = uVar4;
            if ((bVar1 >> 6 & 1) == 0) break;
            if ((bVar1 == 0xc0) && (uVar8 = *(uint *)(local_40 + 0x14), (local_40[1] & 2) != 0)) {
              local_38 = *(undefined4 *)(local_40 + 0x1c);
              uVar11 = *(undefined4 *)(local_40 + 0x18);
            }
            if (((((bVar1 & 0x20) == 0x20) && ((bVar1 >> 6 & 1) == 1)) && ((local_40[1] & 1) != 0))
               && (*(uint *)(local_40 + 0x14) < *(uint *)(*(int *)(param_1 + 0xc) + 0x44))) {
              bVar2 = true;
            }
            *local_40 = bVar1 & 0x7f;
            local_40 = local_40 + 0x20;
            uVar5 = uVar5 + 1;
            uVar7 = uVar7 + 0x20;
            uVar6 = uVar5;
          } while (uVar5 < uVar4);
          uVar5 = uVar6;
        } while (uVar6 < uVar4);
      }
      iVar3 = FUN_c03443d4(*(int *)(param_1 + 0x10),0);
      if ((((iVar3 == 0) && (local_34 != 0)) &&
          (((uVar8 == 0 || (*(uint *)(*(int *)(param_1 + 0xc) + 0x44) <= uVar8)) ||
           ((iVar3 = (**(code **)(*piVar9 + 0x24))(piVar9,uVar8,uVar11,local_38), iVar3 == 0 &&
            (iVar3 = (**(code **)(*piVar9 + 0x30))(piVar9,0), iVar3 == 0)))))) && (bVar2)) {
        uVar5 = 0;
        uVar7 = *local_30;
        if (uVar4 != 0) {
          do {
            uVar7 = uVar7 + 0x20;
            uVar11 = 0;
            uVar10 = 0;
            iVar3 = FUN_c0348cd4(param_1,uVar7,(int *)&local_40);
            if (iVar3 != 0) break;
            bVar1 = *local_40 >> 6;
            if ((bVar1 & 1) == 0) break;
            if ((((*local_40 & 0x20) == 0x20) && ((bVar1 & 1) == 1)) && ((local_40[1] & 1) != 0)) {
              uVar8 = *(uint *)(local_40 + 0x14);
              if ((local_40[1] & 2) != 0) {
                uVar11 = *(undefined4 *)(local_40 + 0x18);
                uVar10 = *(undefined4 *)(local_40 + 0x1c);
              }
              if (((uVar8 != 0) && (uVar8 < *(uint *)(*(int *)(param_1 + 0xc) + 0x44))) &&
                 (iVar3 = (**(code **)(*piVar9 + 0x24))(piVar9,uVar8,uVar11,uVar10), iVar3 != 0))
              goto LAB_c0349fcc;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar4);
        }
        iVar3 = (**(code **)(*piVar9 + 0x30))(piVar9,0);
      }
    }
    else {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
      iVar3 = 2;
    }
  }
LAB_c0349fcc:
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  FUN_c03410d4(piVar9);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar3;
}



/* c034a014 FUN_c034a014 */

/* Boundary evidence: original MIPS .pdata c034a014..c034a283. Semantic name remains unreviewed. */

int FUN_c034a014(uint param_1,uint *param_2,int param_3,uint param_4)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *local_30;
  uint local_2c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  uVar5 = *param_2;
  local_30 = (char *)0x0;
  if ((param_4 & 1) != 0) {
    uVar4 = 1 << (*(byte *)(*(int *)(param_1 + 0xc) + 0x34) & 0x1f);
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    if (uVar5 % uVar4 == uVar4 - 0x20) {
      param_3 = 2;
    }
  }
  iVar2 = FUN_c0346b50(param_1,uVar5,(int *)&local_30,(int *)0x0,param_3);
  if (iVar2 == 0) {
    if (param_2[0xc] == 3) {
      iVar2 = FUN_c0348ea4(param_1,local_30,(int)param_2,0);
    }
    else {
      iVar2 = FUN_c0348d2c(param_1,local_30,(int)param_2,0);
      pcVar1 = local_30;
      if (iVar2 == 0) {
        uVar3 = FUN_c0348b70((int)local_30,1,0);
        uVar4 = (uint)(byte)pcVar1[1];
        while ((uVar5 = uVar5 + 0x20, local_2c = uVar4, uVar4 != 0 &&
               (iVar2 = FUN_c0348cd4(param_1,uVar5,(int *)&local_30), iVar2 == 0))) {
          if ((((param_4 & 1) != 0) && (*local_30 == -0x40)) &&
             ((iVar2 = FUN_c0346b50(param_1,uVar5,(int *)&local_30,(int *)0x0,param_3), iVar2 != 0
              || (iVar2 = FUN_c0348ddc(param_1,local_30,param_2 + 0xe,0), uVar4 = local_2c,
                 iVar2 != 0)))) goto LAB_c034a244;
          if (((param_4 & 2) != 0) && (*local_30 == -0x1e)) {
            iVar2 = FUN_c0346b50(param_1,uVar5,(int *)&local_30,(int *)0x0,param_3);
            if (iVar2 != 0) goto LAB_c034a244;
            *(uint *)(local_30 + 8) = param_2[4];
            *(uint *)(local_30 + 0xc) = param_2[5];
            uVar4 = local_2c;
          }
          uVar3 = FUN_c0348b70((int)local_30,0,uVar3);
          uVar4 = uVar4 - 1;
        }
        iVar2 = FUN_c0346b50(param_1,*param_2,(int *)&local_30,(int *)0x0,0);
        if (iVar2 == 0) {
          *(short *)(local_30 + 2) = (short)uVar3;
        }
      }
    }
  }
LAB_c034a244:
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar2;
}



/* c034a284 FUN_c034a284 */

/* Boundary evidence: original MIPS .pdata c034a284..c034a69f. Semantic name remains unreviewed. */

int FUN_c034a284(uint param_1,STRSAFE_PCNZWCH param_2,int *param_3,int param_4,uint *param_5)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  HRESULT HVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *local_250;
  STRSAFE_PCNZWCH local_24c;
  undefined1 *local_248;
  size_t local_244;
  undefined1 *local_240;
  int local_23c;
  undefined1 auStack_238 [520];
  uint local_30;
  
  local_30 = DAT_c034d334;
  uVar7 = *param_5;
  local_250 = (byte *)0x0;
  local_24c = param_2;
  local_23c = param_4;
  iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_250,(int *)0x0,2);
  if ((iVar3 == 0) && (iVar3 = FUN_c0348d2c(param_1,local_250,(int)param_5,1), iVar3 == 0)) {
    uVar4 = FUN_c0348b70((int)local_250,1,0);
    iVar3 = FUN_c0346b50(param_1,uVar7 + 0x20,(int *)&local_250,(int *)0x0,2);
    if ((iVar3 == 0) && (iVar3 = FUN_c0348ddc(param_1,local_250,param_5 + 0xe,1), iVar3 == 0)) {
      local_244 = 0;
      HVar5 = StringCchLengthW(param_2,0x104,&local_244);
      if (HVar5 < 0) {
        iVar3 = 0x1f;
      }
      else {
        local_250[3] = (byte)local_244;
        iVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                          (*(int **)(param_1 + 0xc),param_2,local_244,auStack_238);
        if (iVar3 == 0) {
          uVar2 = FUN_c0340480((int)auStack_238,local_244 << 1);
          *(undefined2 *)(local_250 + 4) = uVar2;
          uVar6 = 0;
          uVar4 = FUN_c0348b70((int)local_250,0,uVar4);
          uVar7 = uVar7 + 0x40;
          local_248 = (undefined1 *)0x0;
          local_240 = (undefined1 *)0x0;
          iVar3 = local_23c;
          for (uVar9 = local_244; local_23c = iVar3, uVar9 != 0; uVar9 = uVar9 - uVar8) {
            if ((local_240 <= local_248) &&
               (iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_248,(int *)&local_240,2),
               iVar3 != 0)) goto LAB_c034a668;
            memset(local_248,0,0x20);
            *local_248 = 0xc1;
            uVar8 = uVar9;
            if (0xe < uVar9) {
              uVar8 = 0xf;
            }
            memcpy(local_248 + 2,local_24c,uVar8 * 2);
            puVar1 = local_248;
            local_24c = local_24c + uVar8;
            uVar6 = 0;
            uVar7 = uVar7 + 0x20;
            uVar4 = FUN_c0348b70((int)local_248,0,uVar4);
            local_248 = puVar1 + 0x20;
            iVar3 = local_23c;
          }
          if ((iVar3 == 0) || (uVar9 = param_3[1], uVar9 == 0)) {
            if ((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x1000) != 0) {
              local_24c = (STRSAFE_PCNZWCH)0x0;
              iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_24c,(int *)0x0,2);
              if (iVar3 != 0) goto LAB_c034a668;
              memset(local_24c,0,0x20);
              *(undefined1 *)local_24c = 0xe2;
              *(uint *)(local_24c + 4) = param_5[4];
              *(uint *)(local_24c + 6) = param_5[5];
              param_5[1] = uVar7;
              uVar4 = FUN_c0348b70((int)local_24c,0,uVar4);
            }
          }
          else {
            local_24c = (STRSAFE_PCNZWCH)0x0;
            uVar8 = FUN_c033b060(param_3);
            param_5[1] = uVar7;
            uVar10 = 0;
            if (uVar8 != 0) {
              do {
                iVar3 = FUN_c03451b8(iVar3,uVar6,uVar9,0,(int *)&local_24c,(int *)0x0);
                if ((iVar3 != 0) ||
                   (iVar3 = FUN_c0346b50(param_1,uVar7,(int *)&local_250,(int *)0x0,2), iVar3 != 0))
                goto LAB_c034a668;
                memcpy(local_250,local_24c,0x20);
                *local_250 = *local_250 | 0x80;
                uVar6 = 0;
                uVar4 = FUN_c0348b70((int)local_250,0,uVar4);
                uVar10 = uVar10 + 1;
                uVar7 = uVar7 + 0x20;
                uVar9 = uVar9 + 0x20;
                iVar3 = local_23c;
              } while (uVar10 < uVar8);
            }
          }
          iVar3 = FUN_c0346b50(param_1,*param_5,(int *)&local_250,(int *)0x0,2);
          if (iVar3 == 0) {
            *(short *)(local_250 + 2) = (short)uVar4;
          }
        }
      }
    }
  }
LAB_c034a668:
  FUN_c034b674(local_30);
  return iVar3;
}



/* c034a6a0 FUN_c034a6a0 */

/* Boundary evidence: original MIPS .pdata c034a6a0..c034a707. Semantic name remains unreviewed. */

void FUN_c034a6a0(uint param_1,uint *param_2)

{
  int iVar1;
  undefined1 *local_18 [2];
  
  local_18[0] = (undefined1 *)0x0;
  iVar1 = FUN_c0346b50(param_1,*param_2,(int *)local_18,(int *)0x0,2);
  if (iVar1 == 0) {
    FUN_c0348ea4(param_1,local_18[0],(int)param_2,1);
  }
  return;
}



/* c034a708 FUN_c034a708 */

/* Boundary evidence: original MIPS .pdata c034a708..c034a99b. Semantic name remains unreviewed. */

int FUN_c034a708(uint param_1,STRSAFE_PCNZWCH param_2,undefined4 param_3,int *param_4,int param_5,
                uint *param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint local_30;
  STRSAFE_PCNZWCH local_2c;
  
  local_30 = 0xffffffff;
  piVar3 = *(int **)(*(int *)(param_1 + 0xc) + 0x18);
  uVar4 = param_6[3];
  local_2c = param_2;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  bVar1 = (*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) != 0;
  if (bVar1) {
    FUN_c03410b8((int)piVar3);
  }
  if ((param_4 == (int *)0x0) && ((uVar4 & 0x10) != 0)) {
    if (!bVar1) {
      FUN_c03410b8((int)piVar3);
    }
    bVar1 = true;
    iVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,0xffffffff,1,&local_30,0);
    if ((iVar2 != 0) ||
       (iVar2 = (**(code **)(*piVar3 + 0x10))(piVar3,local_30,0xffffffff,0), iVar2 != 0))
    goto LAB_c034a8f4;
    param_6[0xf] = local_30;
    param_6[0x12] = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
    param_6[0x13] = 0;
    param_6[0x10] = *(uint *)(*(int *)(param_1 + 0xc) + 0x38);
    param_6[0x11] = 0;
    param_2 = local_2c;
  }
  if (param_6[0xc] == 5) {
    if ((((*(uint *)(*(int *)(param_1 + 0xc) + 0x6c) & 0x10) == 0) || ((uVar4 & 0x10) == 0)) &&
       (param_4 == (int *)0x0)) {
      param_6[0xe] = param_6[0xe] | 2;
    }
    iVar2 = FUN_c034a284(param_1,param_2,param_4,param_5,param_6);
  }
  else if (param_6[0xc] == 3) {
    iVar2 = FUN_c034a6a0(param_1,param_6);
  }
  else {
    iVar2 = 0x57;
  }
  if ((iVar2 == 0) && (iVar2 = FUN_c03443d4(*(int *)(param_1 + 0x10),0), iVar2 == 0)) {
    iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,0);
  }
LAB_c034a8f4:
  if ((local_30 != 0xffffffff) && (iVar2 != 0)) {
    (**(code **)(*piVar3 + 0x10))(piVar3,local_30,0,0);
  }
  if (((param_5 != 0) && (param_4 != (int *)0x0)) && (param_4[1] != 0)) {
    FUN_c03441c4(param_5);
  }
  FUN_c03441c4(*(int *)(param_1 + 0x10));
  if (bVar1) {
    FUN_c03410d4(piVar3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xa0));
  return iVar2;
}



/* c034a99c FUN_c034a99c */

/* Boundary evidence: original MIPS .pdata c034a99c..c034a9bb. Semantic name remains unreviewed. */

void FUN_c034a99c(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_c0345da4(param_1,1000);
  return;
}



/* c034a9bc FUN_c034a9bc */

/* Boundary evidence: original MIPS .pdata c034a9bc..c034aa8b. Semantic name remains unreviewed. */

undefined4 FUN_c034a9bc(int param_1,void *param_2)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = 0;
  iVar3 = 0;
  do {
    if (iVar3 == 0) {
      uVar4 = uVar2;
    }
    BVar1 = IsDBCSLeadByte(*(BYTE *)(uVar2 + (int)param_2));
    if (BVar1 == 0) {
      if (*(BYTE *)(uVar2 + (int)param_2) != ' ') goto LAB_c034aa20;
      iVar3 = iVar3 + 1;
    }
    else {
      uVar2 = uVar2 + 1;
LAB_c034aa20:
      iVar3 = 0;
    }
    uVar2 = uVar2 + 1;
    if (6 < uVar2) {
      memcpy((void *)(param_1 + 0x14),param_2,0xb);
      *(uint *)(param_1 + 0x10) = uVar4;
      return 0;
    }
  } while( true );
}



/* c034aa8c FUN_c034aa8c */

/* Boundary evidence: original MIPS .pdata c034aa8c..c034ac87. Semantic name remains unreviewed. */

void FUN_c034aa8c(int param_1,void *param_2)

{
  BYTE BVar1;
  BOOL BVar2;
  int iVar3;
  uint uVar4;
  undefined1 *_Buf1;
  int iVar5;
  uint uVar6;
  undefined1 local_3a [14];
  uint local_2c;
  
  local_2c = DAT_c034d334;
  iVar5 = 0;
  uVar6 = 0xffffffff;
  uVar4 = 0;
  do {
    BVar2 = IsDBCSLeadByte(*(BYTE *)((int)param_2 + uVar4));
    if (BVar2 == 0) {
      BVar1 = *(BYTE *)((int)param_2 + uVar4);
      if (BVar1 == '~') {
        if ((*(uint *)(param_1 + 0x10) < uVar4) || (uVar4 < *(uint *)(param_1 + 0x10) - 2))
        goto LAB_c034ab04;
        iVar5 = 0;
        uVar6 = uVar4;
      }
      else if ((uVar6 != 0xffffffff) && (BVar1 != ' ')) {
        iVar5 = iVar5 + 1;
      }
    }
    else {
      uVar4 = uVar4 + 1;
LAB_c034ab04:
      uVar6 = 0xffffffff;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  if ((uVar6 == 0xffffffff) || (iVar5 == 0)) {
    iVar5 = FUN_c0345e88(param_1,0);
    if (iVar5 != 0) goto LAB_c034ac50;
    _Buf1 = (undefined1 *)(param_1 + 0x14);
    iVar5 = 0;
  }
  else {
    memcpy(local_3a + 2,(void *)(param_1 + 0x14),0xb);
    memcpy(local_3a + uVar6 + 2,(void *)((int)param_2 + uVar6),iVar5 + 1);
    iVar3 = iVar5 + uVar6 + 1;
    if (iVar3 < 8) {
      memset(local_3a + iVar5 + uVar6 + 3,0x20,8 - iVar3);
    }
    _Buf1 = local_3a + 2;
    if ((uVar6 != 0) && (*(char *)((int)((int)param_2 + uVar6) + -1) == '~')) {
      local_3a[uVar6 + 1] = 0x7e;
    }
  }
  iVar3 = memcmp(_Buf1,param_2,0xb);
  if ((iVar3 == 0) &&
     ((uVar4 = 0, iVar5 == 0 || (uVar4 = FUN_c033b794(_Buf1 + uVar6 + 1,iVar5), 0 < (int)uVar4)))) {
    FUN_c0345e2c(param_1,uVar4);
  }
LAB_c034ac50:
  FUN_c034b674(local_2c);
  return;
}



/* c034ac88 FUN_c034ac88 */

/* Boundary evidence: original MIPS .pdata c034ac88..c034ad03. Semantic name remains unreviewed. */

byte FUN_c034ac88(undefined4 param_1,int param_2,int param_3)

{
  BOOL BVar1;
  byte bVar2;
  
  bVar2 = 0;
  while ((-1 < param_3 && (BVar1 = IsDBCSLeadByte(*(BYTE *)(param_3 + param_2)), BVar1 != 0))) {
    param_3 = param_3 + -1;
    bVar2 = bVar2 ^ 1;
  }
  return bVar2;
}



/* c034ad04 FUN_c034ad04 */

/* Boundary evidence: original MIPS .pdata c034ad04..c034ae5f. Semantic name remains unreviewed. */

void FUN_c034ad04(int param_1,void *param_2)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0xc) + 1U < *(uint *)(param_1 + 8)) {
    uVar4 = 1;
    if (1 < (int)*(uint *)(param_1 + 8)) {
      do {
        iVar2 = FUN_c0345e88(param_1,uVar4);
        if (iVar2 == 0) {
          iVar2 = *(int *)(param_1 + 0x10);
          if (9 < (int)uVar4) {
            if ((int)uVar4 < 100) {
              if (5 < iVar2) {
                iVar2 = 5;
              }
            }
            else {
              if (999 < (int)uVar4) break;
              if (4 < iVar2) {
                iVar2 = 4;
              }
            }
          }
          if ((iVar2 != 0) &&
             (bVar1 = FUN_c034ac88(param_1,param_1 + 0x14,iVar2 + -1),
             CONCAT31(extraout_var,bVar1) != 0)) {
            *(undefined1 *)(iVar2 + param_1 + 0x13) = 0x7e;
          }
          *(undefined1 *)(iVar2 + param_1 + 0x14) = 0x7e;
          iVar3 = FUN_c033b7f8(uVar4,(char *)(iVar2 + param_1 + 0x15));
          iVar2 = iVar3 + iVar2 + 1;
          if (iVar2 < 8) {
            memset((void *)(iVar2 + param_1 + 0x14),0x20,8 - iVar2);
          }
          break;
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < *(int *)(param_1 + 8));
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  memcpy(param_2,(void *)(param_1 + 0x14),0xb);
  return;
}



/* c034b150 FUN_c034b150 */

/* Boundary evidence: original MIPS .pdata c034b150..c034b28b. Semantic name remains unreviewed. */

int FUN_c034b150(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c034d374 != (code *)0x0) {
      iVar2 = (*DAT_c034d374)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c034b200;
    FUN_c034b8d4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c033239c(param_1,param_2);
  }
LAB_c034b200:
  if (((param_2 == 0) && (FUN_c034b85c(), iVar1 != 0)) && (DAT_c034d374 != (code *)0x0)) {
    iVar1 = (*DAT_c034d374)(param_1,0,param_3);
  }
  return iVar1;
}



/* c034b28c FUN_c034b28c */

/* Boundary evidence: original MIPS .pdata c034b28c..c034b2b7. Semantic name remains unreviewed. */

void FUN_c034b28c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c034b2b8 entry */

/* Boundary evidence: original MIPS .pdata c034b2b8..c034b30f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c034b584();
  }
  FUN_c034b150(param_1,param_2,param_3);
  return;
}



/* c034b310 FUN_c034b310 */

/* Boundary evidence: original MIPS .pdata c034b310..c034b41b. Semantic name remains unreviewed. */

undefined4 FUN_c034b310(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c034d36c;
  puVar3 = DAT_c034d368;
  iVar4 = (int)DAT_c034d368 - (int)DAT_c034d36c;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c034b354:
    param_1 = 0;
  }
  else {
    if (DAT_c034d36c != (void *)0x0) {
      uVar1 = _msize(DAT_c034d36c);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c034b3c8:
        if (pvVar2 == (void *)0x0) goto LAB_c034b354;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c034b3c8;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c034d368 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c034d36c = pvVar2;
  }
  return param_1;
}



/* c034b41c FUN_c034b41c */

/* Boundary evidence: original MIPS .pdata c034b41c..c034b507. Semantic name remains unreviewed. */

undefined4 FUN_c034b41c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c034d370 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c034d370,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c034d370 == (LPCRITICAL_SECTION)0x0) goto LAB_c034b4c0;
  }
  EnterCriticalSection(DAT_c034d370);
LAB_c034b4c0:
  uVar2 = FUN_c034b310(param_1);
  FUN_c034b508();
  return uVar2;
}



/* c034b508 FUN_c034b508 */

/* Boundary evidence: original MIPS .pdata c034b508..c034b553. Semantic name remains unreviewed. */

void FUN_c034b508(void)

{
  if (DAT_c034d370 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c034d370);
  }
  return;
}



/* c034b554 FUN_c034b554 */

/* Boundary evidence: original MIPS .pdata c034b554..c034b583. Semantic name remains unreviewed. */

undefined4 FUN_c034b554(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c034b41c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c034b584 FUN_c034b584 */

/* Boundary evidence: original MIPS .pdata c034b584..c034b5f7. Semantic name remains unreviewed. */

void FUN_c034b584(void)

{
  uint uVar1;
  
  if ((DAT_c034d334 == 0) || (DAT_c034d334 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c034d334 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c034d334 == 0) {
      DAT_c034d334 = 0xb064;
    }
  }
  DAT_c034d338 = ~DAT_c034d334;
  return;
}



/* c034b5f8 FUN_c034b5f8 */

/* Boundary evidence: original MIPS .pdata c034b5f8..c034b673. Semantic name remains unreviewed. */

void FUN_c034b5f8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c034b6bc(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c034b674 FUN_c034b674 */

/* Boundary evidence: original MIPS .pdata c034b674..c034b6bb. Semantic name remains unreviewed. */

void FUN_c034b674(uint param_1)

{
  if ((param_1 == DAT_c034d334) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c034b6bc FUN_c034b6bc */

/* Boundary evidence: original MIPS .pdata c034b6bc..c034b70f. Semantic name remains unreviewed. */

void FUN_c034b6bc(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c034b674(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c034b710 FUN_c034b710 */

/* Boundary evidence: original MIPS .pdata c034b710..c034b73b. Semantic name remains unreviewed. */

undefined4 FUN_c034b710(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c034b6bc(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c034b73c FUN_c034b73c */

/* Boundary evidence: original MIPS .pdata c034b73c..c034b85b. Semantic name remains unreviewed. */

void FUN_c034b73c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c034d364 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c034d36c;
    if (DAT_c034d36c != (undefined4 *)0x0) {
      while (DAT_c034d368 = DAT_c034d368 + -1, _Memory <= DAT_c034d368) {
        if ((code *)*DAT_c034d368 != (code *)0x0) {
          (*(code *)*DAT_c034d368)();
          _Memory = DAT_c034d36c;
        }
      }
      free(_Memory);
      DAT_c034d368 = (undefined4 *)0x0;
      DAT_c034d36c = (undefined4 *)0x0;
    }
    FUN_c034b880((undefined4 *)&DAT_c0331014,(undefined4 *)&DAT_c0331018);
  }
  FUN_c034b880((undefined4 *)&DAT_c033101c,(undefined4 *)&DAT_c0331020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c034d370,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c034b85c FUN_c034b85c */

/* Boundary evidence: original MIPS .pdata c034b85c..c034b87f. Semantic name remains unreviewed. */

void FUN_c034b85c(void)

{
  FUN_c034b73c(0,0,1);
  return;
}



/* c034b880 FUN_c034b880 */

/* Boundary evidence: original MIPS .pdata c034b880..c034b8d3. Semantic name remains unreviewed. */

void FUN_c034b880(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c034b8d4 FUN_c034b8d4 */

/* Boundary evidence: original MIPS .pdata c034b8d4..c034b90f. Semantic name remains unreviewed. */

void FUN_c034b8d4(void)

{
  FUN_c034b880((undefined4 *)&DAT_c033100c,(undefined4 *)&DAT_c0331010);
  FUN_c034b880((undefined4 *)&DAT_c0331000,(undefined4 *)&DAT_c0331008);
  return;
}



/* c034bab0 FUN_c034bab0 */

/* Boundary evidence: original MIPS .pdata c034bab0..c034baf3. Semantic name remains unreviewed. */

void FUN_c034bab0(void)

{
  FUN_c0333b60(&DAT_c034d340);
  DAT_c034d340 = &PTR_FUN_c03310c0;
  FUN_c034b554(FUN_c034baf4);
  return;
}



/* c034baf4 FUN_c034baf4 */

/* Boundary evidence: original MIPS .pdata c034baf4..c034bb13. Semantic name remains unreviewed. */

void FUN_c034baf4(void)

{
  FUN_c0333d90(&DAT_c034d340);
  return;
}


