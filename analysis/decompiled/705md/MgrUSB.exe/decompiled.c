/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..00011053. Semantic name remains unreviewed. */

bool FUN_00011000(void)

{
  HRESULT HVar1;
  
  HVar1 = CoInitializeEx((LPVOID)0x0,0);
  if (-1 >= HVar1) {
    MessageBoxW((HWND)0x0,L"CoInitializeEx is failed",(LPCWSTR)0x0,0);
  }
  return -1 < HVar1;
}



/* 00011054 FUN_00011054 */

/* Boundary evidence: original MIPS .pdata 00011054..0001111b. Semantic name remains unreviewed. */

undefined4 FUN_00011054(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 uVar3;
  LPVOID *ppv;
  
  ppv = (LPVOID *)(param_1 + 0x10);
  uVar3 = 1;
  HVar1 = CoCreateInstance((IID *)&DAT_0002d2bc,(LPUNKNOWN)0x0,1,(IID *)&DAT_0002e32c,ppv);
  if (HVar1 == 0) {
    iVar2 = FUN_000231a4();
    *(undefined4 *)(iVar2 + 0x28) = 1;
  }
  else {
    FUN_00023aac(5,3,L"%S  CoCreateInstance FAILED(hr=0x%x)(hGp=0x%x)","CDshowManager::FilterCreate"
                );
    iVar2 = FUN_000231a4();
    *(undefined4 *)(iVar2 + 0x28) = 0;
    if (*ppv != (int *)0x0) {
      (**(code **)(*(int *)*ppv + 8))();
      *ppv = (LPVOID)0x0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 0001111c FUN_0001111c */

/* Boundary evidence: original MIPS .pdata 0001111c..0001122f. Semantic name remains unreviewed. */

undefined4 FUN_0001111c(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    local_18 = (uint)((ulonglong)param_2 * 10000000);
    local_14 = ((int)param_2 >> 0x1f) * 10000000 + (int)((ulonglong)param_2 * 10000000 >> 0x20);
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(*(int **)(param_1 + 0xc),&local_10);
    if (-1 < iVar1) {
      uVar2 = local_10 - local_18;
      iVar1 = (local_c - local_14) - (uint)(local_10 < local_18);
      if ((iVar1 < 1) && ((iVar1 != 0 || (uVar2 < 1500000)))) {
        uVar3 = uVar2 + local_18;
        local_18 = uVar3 - 1500000;
        local_14 = (iVar1 + local_14 + (uint)(uVar3 < uVar2)) - (uint)(uVar3 < 1500000);
      }
    }
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x38))
                      (*(int **)(param_1 + 0xc),&local_18,1,0,0);
    if (-1 < iVar1) {
      return 1;
    }
  }
  return 0xffffffff;
}



/* 00011230 FUN_00011230 */

/* Boundary evidence: original MIPS .pdata 00011230..0001137b. Semantic name remains unreviewed. */

int FUN_00011230(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(*(int **)(param_1 + 0xc),&local_28);
    if (-1 < iVar2) {
      if ((local_24 < 0) || ((local_24 == 0 && (local_28 == 0)))) {
        return 0;
      }
      (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(*(int **)(param_1 + 0xc),&local_20);
      iVar2 = local_1c;
      uVar1 = local_20;
      uVar4 = local_28;
      iVar3 = local_24;
      if ((local_1c <= local_24) && ((local_24 != local_1c || (local_20 < local_28)))) {
        uVar4 = local_20;
        iVar3 = local_1c;
      }
      iVar3 = __ll_div(uVar4,iVar3,10000,0);
      iVar5 = iVar3 / 1000;
      if (0x351 < iVar3 % 1000) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = __ll_div(uVar1,iVar2,10000,0);
      if (iVar5 <= iVar2 / 1000) {
        return iVar5;
      }
      return iVar2 / 1000;
    }
  }
  return -1;
}



/* 0001137c FUN_0001137c */

/* Boundary evidence: original MIPS .pdata 0001137c..000113df. Semantic name remains unreviewed. */

uint FUN_0001137c(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x28))(*(int **)(param_1 + 0xc),&local_10),
     iVar2 < 0)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = __ll_div(local_10,local_c,10000,0);
    uVar1 = uVar1 / 1000;
  }
  return uVar1;
}



/* 000113e0 FUN_000113e0 */

void FUN_000113e0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}



/* 000113e8 FUN_000113e8 */

undefined4 FUN_000113e8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



/* 000113f0 FUN_000113f0 */

/* Boundary evidence: original MIPS .pdata 000113f0..0001144b. Semantic name remains unreviewed. */

undefined4 * FUN_000113f0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000260fc;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[6] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  FUN_00011000();
  return param_1;
}



/* 0001144c FUN_0001144c */

/* Boundary evidence: original MIPS .pdata 0001144c..0001149f. Semantic name remains unreviewed. */

void FUN_0001144c(void)

{
  undefined4 *puVar1;
  
  if (DAT_0002f968 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x28);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_0002f968 = (undefined4 *)0x0;
    }
    else {
      DAT_0002f968 = FUN_000113f0(puVar1);
    }
  }
  return;
}



/* 000114a0 FUN_000114a0 */

/* Boundary evidence: original MIPS .pdata 000114a0..00011567. Semantic name remains unreviewed. */

undefined4 FUN_000114a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
LAB_000114c4:
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x24) != 2) {
      piVar3 = *(int **)(param_1 + 0x14);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x1c))(piVar3,0);
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))();
      FUN_000231a4();
      FUN_0001ed94();
      if (iVar2 < 0) {
        FUN_00023aac(5,1,L"%S Run failed","CDshowManager::Run");
        goto LAB_000114c4;
      }
      *(undefined4 *)(param_1 + 0x24) = 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 00011568 FUN_00011568 */

/* Boundary evidence: original MIPS .pdata 00011568..0001178f. Semantic name remains unreviewed. */

undefined4 FUN_00011568(int param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_30 [2];
  
  if ((*(int *)(param_1 + 4) == 0) || (DAT_0002f96c == 0)) {
    FUN_00023aac(5,3,L"%S  line %d  --DSHOW Stop-- [0x%x, %d] -----","CDshowManager::Stop");
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    if ((*(int *)(param_1 + 0x24) == 2) || (*(int *)(param_1 + 0x24) == 1)) {
      piVar2 = *(int **)(param_1 + 0x14);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x1c))(piVar2,0xffffd8f0);
      }
      bVar1 = false;
      uVar5 = 0;
      do {
        piVar2 = *(int **)(param_1 + 4);
        if (piVar2 == (int *)0x0) {
          NKDbgPrintfW(L"\r\n==[NULLNULL]==> CDshowManager::Stop(%d) [%d]\r\n",param_2,uVar5);
          break;
        }
        (**(code **)(*piVar2 + 0x28))(piVar2,0xffffffff,local_30);
        if (local_30[0] == 2) {
          pcVar3 = *(code **)(**(int **)(param_1 + 4) + 0x20);
LAB_00011654:
          (*pcVar3)();
        }
        else {
          if (local_30[0] == 1) {
            pcVar3 = *(code **)(**(int **)(param_1 + 4) + 0x24);
            goto LAB_00011654;
          }
          if (local_30[0] == 0) {
            bVar1 = true;
          }
        }
        Sleep(5);
        FUN_00023aac(5,0,L"%S  line %d  => CDshowManager::Stop(%d) [%d : %d]","CDshowManager::Stop")
        ;
        uVar5 = uVar5 + 1;
        if (1000 < uVar5) {
          NKDbgPrintfW(L"\r\n======================================\r\n");
          NKDbgPrintfW(L"==================[%d]=================\r\n",uVar5);
          NKDbgPrintfW(L"======================================\r\n");
          break;
        }
      } while (!bVar1);
      if (param_2 != 0) {
        FUN_0001111c(param_1,0);
      }
      *(undefined4 *)(param_1 + 0x24) = 3;
    }
  }
  return uVar4;
}



/* 00011790 FUN_00011790 */

/* Boundary evidence: original MIPS .pdata 00011790..00011917. Semantic name remains unreviewed. */

undefined4 FUN_00011790(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int local_28 [2];
  
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x24) != 2)) {
LAB_000118e8:
    uVar3 = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))(piVar2,0xffffd8f0);
    }
    bVar1 = false;
    uVar4 = 0;
    uVar3 = 1;
    do {
      piVar2 = *(int **)(param_1 + 4);
      if (piVar2 == (int *)0x0) {
        NKDbgPrintfW(L"\r\n=^^=[NULL]==> CDshowManager::RealPause() [%d]\r\n",uVar4);
        goto LAB_000118e8;
      }
      (**(code **)(*piVar2 + 0x28))(piVar2,0xffffffff,local_28);
      if (local_28[0] == 2) {
        (**(code **)(**(int **)(param_1 + 4) + 0x20))();
      }
      else if ((local_28[0] == 1) || (local_28[0] == 0)) {
        bVar1 = true;
      }
      Sleep(5);
      NKDbgPrintfW(L"=^^= CDshowManager::RealPause() [%d : %d]\r\n",uVar4,local_28[0]);
      uVar4 = uVar4 + 1;
      if (1000 < uVar4) {
        NKDbgPrintfW(L"\r\n^^======================================\r\n");
        NKDbgPrintfW(L"^^==================[%d]=================\r\n",uVar4);
        NKDbgPrintfW(L"^^======================================\r\n");
        if (!bVar1) goto LAB_000118e8;
        break;
      }
    } while (!bVar1);
    *(undefined4 *)(param_1 + 0x24) = 1;
  }
  return uVar3;
}



/* 00011918 FUN_00011918 */

/* Boundary evidence: original MIPS .pdata 00011918..00011aaf. Semantic name remains unreviewed. */

undefined4 FUN_00011918(int param_1)

{
  bool bVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_28 [2];
  
  if ((*(int *)(param_1 + 4) == 0) || (*(int *)(param_1 + 0x24) != 2)) {
LAB_00011a80:
    uVar4 = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))(piVar2,0xffffd8f0);
    }
    bVar1 = false;
    uVar5 = 0;
    uVar4 = 1;
    do {
      piVar2 = *(int **)(param_1 + 4);
      if (piVar2 == (int *)0x0) {
        NKDbgPrintfW(L"\r\n=////=[NULLNULL]==> CDshowManager::Pause() [%d]\r\n",uVar5);
        goto LAB_00011a80;
      }
      (**(code **)(*piVar2 + 0x28))(piVar2,0xffffffff,local_28);
      if (local_28[0] == 2) {
        pcVar3 = *(code **)(**(int **)(param_1 + 4) + 0x20);
LAB_000119e0:
        (*pcVar3)();
      }
      else {
        if (local_28[0] == 1) {
          pcVar3 = *(code **)(**(int **)(param_1 + 4) + 0x24);
          goto LAB_000119e0;
        }
        if (local_28[0] == 0) {
          bVar1 = true;
        }
      }
      Sleep(5);
      NKDbgPrintfW(L"=//= CDshowManager::Pause() [%d : %d]\r\n",uVar5,local_28[0]);
      uVar5 = uVar5 + 1;
      if (1000 < uVar5) {
        NKDbgPrintfW(L"\r\n//======================================\r\n");
        NKDbgPrintfW(L"//==================[%d]=================\r\n",uVar5);
        NKDbgPrintfW(L"//======================================\r\n");
        if (!bVar1) goto LAB_00011a80;
        break;
      }
    } while (!bVar1);
    *(undefined4 *)(param_1 + 0x24) = 1;
  }
  return uVar4;
}



/* 00011ab0 FUN_00011ab0 */

/* Boundary evidence: original MIPS .pdata 00011ab0..00011e1f. Semantic name remains unreviewed. */

undefined4 FUN_00011ab0(int param_1)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  wchar_t *pwVar4;
  undefined4 uVar5;
  int iVar6;
  int local_40;
  int local_3c;
  int local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  wchar_t *local_2c;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 8) == 0) {
    uVar5 = 0;
  }
  else {
    iVar6 = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                      (*(int **)(param_1 + 8),&local_38,&local_3c,&local_40,0);
    if (-1 < iVar1) {
      local_30 = L"%S DShow Event : Undefined [%d]";
      local_34 = L"%S DShow Event : EC_COMPLETE ERROR_DEVICE_REMOVED catch!!!!!!!";
      local_2c = L"%S DShow Event : EC_COMPLETE %d, %d";
      do {
        pwVar4 = local_34;
        if (local_38 == 1) {
          iVar6 = local_3c;
          FUN_00023aac(5,3,local_2c,"CDshowManager::EventHandler");
          iVar1 = FUN_000231a4();
          if ((*(int *)(iVar1 + 0x28) == 0) || (local_40 != 0)) goto LAB_00011d94;
          iVar1 = FUN_000231a4();
          DVar2 = GetTickCount();
          if (DVar2 - *(int *)(iVar1 + 0x2c) < 300) {
            pwVar4 = L"%S DShow Event : EC_COMPLETE ERROR_DEVICE_REMOVED 300ms catch!!!!!!!";
            goto LAB_00011d94;
          }
          DVar2 = GetTickCount();
          iVar1 = FUN_000231a4();
          *(DWORD *)(iVar1 + 0x2c) = DVar2;
          iVar1 = FUN_000231a4();
          if (*(int *)(iVar1 + 8) == 0) {
            iVar6 = FUN_00011230(param_1);
            iVar1 = FUN_000231a4();
            FUN_0001dd5c(*(int *)(iVar1 + 0x4c),iVar6);
            Sleep(100);
            iVar6 = FUN_00011230(param_1);
            if ((0 < iVar6) && (uVar3 = FUN_0001137c(param_1), 0 < (int)uVar3)) {
              uVar3 = FUN_0001137c(param_1);
              iVar6 = FUN_000231a4();
              FUN_0001dd5c(*(int *)(iVar6 + 0x4c),uVar3);
              iVar6 = FUN_000231a4();
              FUN_0001dd78(*(int *)(iVar6 + 0x4c));
            }
            iVar6 = 0;
            FUN_00023580(5,5,0x6c,0,(LPARAM *)0x0);
          }
          else {
            iVar1 = FUN_0001144c();
            FUN_0001111c(iVar1,0);
          }
        }
        else {
          if (local_38 == 2) {
            pwVar4 = L"%S DShow Event : EC_USERABORT";
          }
          else if (local_38 == 3) {
            pwVar4 = L"%S DShow Event : EC_ERRORABORT";
          }
          else if (local_38 == 6) {
            pwVar4 = L"%S DShow Event : EC_STREAM_ERROR_STOPPED";
          }
          else if (local_38 == 7) {
            pwVar4 = L"%S DShow Event : EC_STREAM_ERROR_STILLPLAYING";
          }
          else {
            pwVar4 = L"%S DShow Event : EC_VIDEO_SIZE_CHANGED";
            if ((local_38 != 10) &&
               (pwVar4 = L"%S DShow Event : EC_VIDEOFRAMEREADY", local_38 != 0x49)) {
              iVar6 = local_38;
              FUN_00023aac(5,3,local_30,"CDshowManager::EventHandler");
              goto LAB_00011d9c;
            }
          }
LAB_00011d94:
          FUN_00023aac(5,3,pwVar4,"CDshowManager::EventHandler");
        }
LAB_00011d9c:
        uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x30))
                          (*(int **)(param_1 + 8),local_38,local_3c,local_40,iVar6);
        iVar6 = 0;
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                          (*(int **)(param_1 + 8),&local_38,&local_3c,&local_40);
      } while (-1 < iVar1);
    }
  }
  return uVar5;
}



/* 00011e20 FUN_00011e20 */

/* Boundary evidence: original MIPS .pdata 00011e20..00011e7b. Semantic name remains unreviewed. */

undefined4 * FUN_00011e20(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000260fc;
  CoUninitialize();
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00011e7c FUN_00011e7c */

/* Boundary evidence: original MIPS .pdata 00011e7c..00011f77. Semantic name remains unreviewed. */

undefined4 FUN_00011e7c(int param_1)

{
  int iVar1;
  
  FUN_00011568(param_1,1);
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 8))();
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 8))();
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 8) + 8))();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 4) + 8))();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x10) + 8))();
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return 1;
}



/* 00011f78 FUN_00011f78 */

/* Boundary evidence: original MIPS .pdata 00011f78..00012263. Semantic name remains unreviewed. */

int FUN_00011f78(int param_1,undefined4 param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_00011e7c(param_1);
  }
  iVar1 = FUN_00011054(param_1);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      pwVar2 = L"%S RenderFile init FAIL";
    }
    else {
      FUN_00023aac(5,1,L"%S RenderFile init","CDshowManager::RenderFile");
      iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),param_2,0);
      if (-1 < iVar1) {
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002cbcc,param_1 + 4);
        if (iVar1 < 0) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002cbec,(int *)(param_1 + 8));
        if (iVar1 < 0) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002e25c,param_1 + 0xc);
        if (iVar1 < 0) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002cc0c,param_1 + 0x14);
        if (iVar1 < 0) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002cbfc,param_1 + 0x18);
        if (iVar1 < 0) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        piVar3 = *(int **)(param_1 + 8);
        if ((piVar3 != (int *)0x0) &&
           (iVar1 = (**(code **)(*piVar3 + 0x34))(piVar3,*(undefined4 *)(param_1 + 0x1c),0x8001,0),
           iVar1 < 0)) {
          FUN_00023aac(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1);
          return iVar1;
        }
        return 1;
      }
      pwVar2 = L"%S RenderFile failed";
    }
    FUN_00023aac(5,1,pwVar2,"CDshowManager::RenderFile");
  }
  return 0;
}



/* 00012264 FUN_00012264 */

/* Boundary evidence: original MIPS .pdata 00012264..00012443. Semantic name remains unreviewed. */

undefined4 FUN_00012264(int param_1,wchar_t *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 auStack_28 [2];
  
  FUN_00023aac(5,0,L"%S  line %d","CDshowManager::LoadFile");
  FUN_000209e0(auStack_28);
  uVar4 = 1;
  if ((param_3 != 1) && (param_3 != 2)) {
    FUN_000209d0(auStack_28);
    return 4;
  }
  iVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
  if (iVar2 == 0) {
    FUN_00023aac(5,3,L"-- %S Line %d -- NO USB ??? --","CDshowManager::LoadFile");
  }
  else {
    bVar1 = FUN_00024b90(auStack_28,param_2);
    if ((CONCAT31(extraout_var,bVar1) != 0) || (sVar3 = wcslen(param_2), sVar3 < 0x105)) {
      FUN_00023aac(5,0,L"%S  line %d","CDshowManager::LoadFile");
      *(int *)(param_1 + 0x20) = param_3;
      iVar2 = FUN_00011f78(param_1,param_2);
      if (iVar2 == 1) {
        FUN_00023aac(5,0,L"%S  line %d","CDshowManager::LoadFile");
        DAT_0002f96c = 1;
      }
      else {
        FUN_00023aac(5,0,L"%S  line %d","CDshowManager::LoadFile");
        DAT_0002f96c = 0;
        uVar4 = 3;
      }
      goto LAB_00012408;
    }
    FUN_00023aac(5,0,L"%S  line %d","CDshowManager::LoadFile");
  }
  uVar4 = 4;
LAB_00012408:
  FUN_000209d0(auStack_28);
  return uVar4;
}



/* 00012444 Unwind@00012444 */

/* Boundary evidence: original MIPS .pdata 00012444..00012473. Semantic name remains unreviewed. */

void Unwind_00012444(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 00012474 FUN_00012474 */

/* Boundary evidence: original MIPS .pdata 00012474..0001253f. Semantic name remains unreviewed. */

undefined * FUN_00012474(void)

{
  undefined8 uVar1;
  undefined8 uVar2;
  _MEMORYSTATUS local_30;
  
  memset(&local_30.dwMemoryLoad,0,0x1c);
  local_30.dwLength = 0x20;
  GlobalMemoryStatus(&local_30);
  uVar1 = __ultodp(local_30.dwTotalVirtual - local_30.dwAvailVirtual);
  uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x3eb00000);
  uVar2 = __ultodp(local_30.dwTotalPhys - local_30.dwAvailPhys);
  uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3eb00000);
  swprintf((wchar_t *)&DAT_0002f970,0x26ff0,(wchar_t *)uVar2,(int)((ulonglong)uVar2 >> 0x20),
           (int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  return &DAT_0002f970;
}



/* 00012540 FUN_00012540 */

/* Boundary evidence: original MIPS .pdata 00012540..00012603. Semantic name remains unreviewed. */

void FUN_00012540(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1028;
  WCHAR aWStack_1018 [1024];
  wchar_t awStack_818 [1026];
  uint local_14;
  
  local_14 = DAT_0002f960;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf_s(awStack_818,0x400,param_1,(va_list)&local_res4);
  GetLocalTime(&_Stack_1028);
  DVar1 = GetTickCount();
  DVar2 = GetTickCount();
  wsprintfW(aWStack_1018,L"[%d,%05d] %s\r\n",DVar2 % 1000,DVar1 / 10,awStack_818);
  OutputDebugStringW(aWStack_1018);
  FUN_00025510(local_14);
  return;
}



/* 00012604 FUN_00012604 */

/* Boundary evidence: original MIPS .pdata 00012604..0001271b. Semantic name remains unreviewed. */

undefined4 FUN_00012604(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  DWORD DVar2;
  undefined4 local_30;
  HKEY local_2c;
  DWORD local_28 [4];
  
  local_28[0] = 4;
  local_28[1] = 4;
  local_30 = param_4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_2c,local_28 + 2);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExW(local_2c,param_3,(LPDWORD)0x0,local_28 + 1,(LPBYTE)&local_30,local_28);
    if (LVar1 != 0) {
      local_30 = param_4;
    }
    RegCloseKey(local_2c);
  }
  else {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"\t[Error] CRegUtil::RegReadInt() [0x%08x, 0x%08x]:[0x%08x]\r\n",param_1,param_2,
                 DVar2);
  }
  return local_30;
}



/* 0001271c FUN_0001271c */

void FUN_0001271c(short *param_1,int param_2,short *param_3)

{
  short sVar1;
  
  if (((param_1 != (short *)0x0) && (param_3 != (short *)0x0)) && (0 < param_2)) {
    sVar1 = *param_3;
    do {
      param_3 = param_3 + 1;
      *param_1 = sVar1;
      sVar1 = *param_3;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
      if (sVar1 == 0) break;
    } while (0 < param_2);
    *param_1 = 0;
  }
  return;
}



/* 00012768 FUN_00012768 */

/* Boundary evidence: original MIPS .pdata 00012768..000127f3. Semantic name remains unreviewed. */

void FUN_00012768(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_0002f1e8 == -1) {
    param_4 = 0;
    param_3 = 0;
    param_2 = 0;
    DAT_0002f1e8 = (int)CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if ((HANDLE)DAT_0002f1e8 == (HANDLE)0xffffffff) goto LAB_000127d4;
  }
  if (DAT_0002f1e8 != 0) {
    return;
  }
LAB_000127d4:
  FUN_00012540(L"****[ExtMemory Alloc] failed, Driver handle create failed",param_2,param_3,param_4)
  ;
  return;
}



/* 000127f4 FUN_000127f4 */

/* Boundary evidence: original MIPS .pdata 000127f4..00012843. Semantic name remains unreviewed. */

void FUN_000127f4(void)

{
  if (DAT_0002f1e8 != -1) {
    CloseHandle((HANDLE)DAT_0002f1e8);
  }
  DAT_0002f1e8 = -1;
  return;
}



/* 00012844 FUN_00012844 */

/* Boundary evidence: original MIPS .pdata 00012844..000129c7. Semantic name remains unreviewed. */

undefined4 FUN_00012844(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HANDLE hDevice;
  int iVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  uint local_res0 [4];
  DWORD local_28 [2];
  int local_20;
  undefined4 local_1c [3];
  
  local_res0[0] = param_1;
  if (DAT_0002f1e8 == (HANDLE)0xffffffff) {
    FUN_00012768(param_1,param_2,param_3,param_4);
  }
  hDevice = DAT_0002f1e8;
  if (local_res0[0] < 0x1400001) {
    local_20 = 0;
    memset(local_1c,0,0xc);
    uVar3 = 4;
    local_28[0] = 0;
    DeviceIoControl(hDevice,0x15,local_res0,4,&local_20,0x10,local_28,(LPOVERLAPPED)0x0);
    iVar1 = DAT_0002fe98;
    if (local_20 == 0) {
      (&DAT_0002fb7c)[DAT_0002fe98 * 2] = 0;
      local_1c[0] = __2_YAPAXI_Z(local_res0[0]);
      pwVar2 = L"**[IntMemory Alloc] successed, [SYS] size:%d, addredd:%X";
      (&DAT_0002fb78)[DAT_0002fe98 * 2] = local_1c[0];
    }
    else {
      (&DAT_0002fb7c)[DAT_0002fe98 * 2] = 1;
      (&DAT_0002fb78)[iVar1 * 2] = local_20;
      pwVar2 = L"**[ExtMemory Alloc] successed, [EXT] size:%d, addredd:%X";
    }
    FUN_00012540(pwVar2,local_res0[0],local_1c[0],uVar3);
    DAT_0002fe98 = DAT_0002fe98 + 1;
  }
  else {
    FUN_00012540(L"****[ExtMemory Alloc] failed, alloc size over, size: %d",local_res0[0],
                 local_res0[0],param_4);
    local_1c[0] = 0;
  }
  return local_1c[0];
}



/* 000129c8 FUN_000129c8 */

/* Boundary evidence: original MIPS .pdata 000129c8..00012aa3. Semantic name remains unreviewed. */

void FUN_000129c8(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20 [2];
  
  if (DAT_0002fe98 != 0) {
    local_20[0] = 0;
    iVar3 = 0;
    if (0 < DAT_0002fe98) {
      piVar2 = &DAT_0002fb78;
      iVar1 = DAT_0002fe98;
      do {
        if (*piVar2 != 0) {
          if (piVar2[1] == 0) {
            __3_YAXPAX_Z();
          }
          else {
            local_20[0] = *piVar2;
            DeviceIoControl(DAT_0002f1e8,0x16,local_20,4,(LPVOID)0x0,0,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
            piVar2[1] = 0;
          }
          iVar1 = DAT_0002fe98;
          *piVar2 = 0;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar3 < iVar1);
    }
    DAT_0002fe98 = 0;
    FUN_000127f4();
  }
  return;
}



/* 00012aa4 FUN_00012aa4 */

/* Boundary evidence: original MIPS .pdata 00012aa4..00012aef. Semantic name remains unreviewed. */

undefined4 *
FUN_00012aa4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_000272c0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  uVar1 = FUN_00012844(0x284880,param_2,param_3,param_4);
  param_1[4] = uVar1;
  return param_1;
}



/* 00012af0 FUN_00012af0 */

/* Boundary evidence: original MIPS .pdata 00012af0..00012b2b. Semantic name remains unreviewed. */

void FUN_00012af0(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    memset(*(void **)(param_1 + 0x10),0,0x284880);
  }
  return;
}



/* 00012b2c FUN_00012b2c */

int FUN_00012b2c(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 0x210 + *(int *)(param_1 + 0x10);
  }
  return iVar1;
}



/* 00012b64 FUN_00012b64 */

/* Boundary evidence: original MIPS .pdata 00012b64..00012ba7. Semantic name remains unreviewed. */

void FUN_00012b64(int param_1,int param_2,wchar_t *param_3)

{
  if ((-1 < param_2) && (param_2 < 5000)) {
    wcscpy_s((wchar_t *)(param_2 * 0x210 + *(int *)(param_1 + 0x10)),0x104,param_3);
  }
  return;
}



/* 00012ba8 FUN_00012ba8 */

void FUN_00012ba8(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar1 = param_2 * 0x210 + *(int *)(param_1 + 0x10);
    *(char *)(iVar1 + 0x208) = (char)param_3;
    *(char *)(iVar1 + 0x209) = (char)((ushort)param_3 >> 8);
  }
  return;
}



/* 00012bec FUN_00012bec */

void FUN_00012bec(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar1 = param_2 * 0x210 + *(int *)(param_1 + 0x10);
    *(char *)(iVar1 + 0x20e) = (char)param_3;
    *(char *)(iVar1 + 0x20f) = (char)((ushort)param_3 >> 8);
  }
  return;
}



/* 00012c30 FUN_00012c30 */

void FUN_00012c30(int param_1,int param_2,undefined4 param_3)

{
  if ((-1 < param_2) && (param_2 < 5000)) {
    *(undefined4 *)(param_2 * 0x210 + *(int *)(param_1 + 0x10) + 0x20a) = param_3;
  }
  return;
}



/* 00012c68 FUN_00012c68 */

undefined4 FUN_00012c68(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 * 0x210 + *(int *)(param_1 + 0x10) + 0x20a);
  }
  return uVar1;
}



/* 00012cac FUN_00012cac */

int FUN_00012cac(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)*(short *)(param_2 * 0x210 + *(int *)(param_1 + 0x10) + 0x20e);
  }
  return iVar1;
}



/* 00012cfc FUN_00012cfc */

int FUN_00012cfc(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(short *)(param_2 * 0x210 + *(int *)(param_1 + 0x10) + 0x208);
  }
  return iVar1;
}



/* 00012d4c FUN_00012d4c */

undefined4 FUN_00012d4c(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 00012d54 FUN_00012d54 */

void FUN_00012d54(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



/* 00012d5c FUN_00012d5c */

int FUN_00012d5c(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 0x210 + *(int *)(param_1 + 0x10);
  }
  return iVar1;
}



/* 00012d88 FUN_00012d88 */

/* Boundary evidence: original MIPS .pdata 00012d88..00012dcf. Semantic name remains unreviewed. */

void FUN_00012d88(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000272c0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((void *)param_1[4] != (void *)0x0) {
    memset((void *)param_1[4],0,0x284880);
  }
  return;
}



/* 00012dd0 FUN_00012dd0 */

/* Boundary evidence: original MIPS .pdata 00012dd0..00012e1b. Semantic name remains unreviewed. */

undefined4 * FUN_00012dd0(undefined4 *param_1,uint param_2)

{
  FUN_00012d88(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00012e1c FUN_00012e1c */

/* Boundary evidence: original MIPS .pdata 00012e1c..00012e7f. Semantic name remains unreviewed. */

void FUN_00012e1c(int param_1)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_00012af0(param_1 + 8);
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    memset(*(void **)(param_1 + 0x38),0,0x298100);
  }
  memset((void *)(param_1 + 0x40),0,0x2712);
  return;
}



/* 00012e80 FUN_00012e80 */

/* Boundary evidence: original MIPS .pdata 00012e80..00012eb3. Semantic name remains unreviewed. */

void FUN_00012e80(int param_1)

{
  FUN_00012e1c(param_1);
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return;
}



/* 00012eb4 FUN_00012eb4 */

undefined4 FUN_00012eb4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}



/* 00012ebc FUN_00012ebc */

/* Boundary evidence: original MIPS .pdata 00012ebc..00012ed7. Semantic name remains unreviewed. */

void FUN_00012ebc(int param_1)

{
  FUN_00012d4c(param_1 + 8);
  return;
}



/* 00012ed8 FUN_00012ed8 */

int FUN_00012ed8(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(param_2 * 0x220 + *(int *)(param_1 + 0x38) + 0x214);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00012f10 FUN_00012f10 */

int FUN_00012f10(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(param_2 * 0x220 + *(int *)(param_1 + 0x38) + 0x212);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* 00012f48 FUN_00012f48 */

int FUN_00012f48(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(param_2 * 0x220 + *(int *)(param_1 + 0x38) + 0x214);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* 00012f80 FUN_00012f80 */

/* Boundary evidence: original MIPS .pdata 00012f80..0001311b. Semantic name remains unreviewed. */

undefined4
FUN_00012f80(int param_1,int param_2,wchar_t *param_3,int param_4,undefined2 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 < 5000) {
    iVar3 = param_1 + 8;
    FUN_00012b64(iVar3,param_2,param_3);
    FUN_00012ba8(iVar3,param_2,(short)param_4);
    FUN_00012bec(iVar3,param_2,param_5);
    FUN_00012c30(iVar3,param_2,param_6);
    iVar1 = FUN_00012d4c(iVar3);
    FUN_00012d54(iVar3,iVar1 + 1);
    iVar1 = param_4 * 0x220 + *(int *)(param_1 + 0x38);
    if (*(int *)(iVar1 + 0x21c) != 2) {
      *(undefined4 *)(iVar1 + 0x21c) = 2;
    }
    iVar1 = FUN_000231a4();
    uVar2 = 1;
    if (*(int *)(iVar1 + 8) == 0) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 8) = 1;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 4) = 1;
      iVar1 = FUN_000231a4();
      iVar1 = FUN_0001dca8(*(int *)(iVar1 + 0x4c),param_2,1,1,0);
      if (iVar1 == 1) {
        iVar1 = FUN_000231a4();
        FUN_0001dc00(*(int *)(iVar1 + 0x4c),0);
      }
      else {
        iVar1 = FUN_000231a4();
        FUN_0001dd20(*(int *)(iVar1 + 0x4c),1);
        iVar1 = FUN_000231a4();
        FUN_0001dc64(*(int *)(iVar1 + 0x4c),2);
      }
      FUN_00023580(5,5,0x68,0,(LPARAM *)0x0);
    }
  }
  else {
    FUN_00023aac(5,0,L"%S Not addMusicName[%d] : %s","CFileMgr::AddMusicFile");
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001311c FUN_0001311c */

/* Boundary evidence: original MIPS .pdata 0001311c..000131c7. Semantic name remains unreviewed. */

undefined4
FUN_0001311c(int param_1,int param_2,wchar_t *param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 1000) && (*(int *)(param_1 + 0x3c) != 0)) {
    iVar1 = param_2 * 0x11b8;
    wcscpy_s((wchar_t *)(iVar1 + *(int *)(param_1 + 0x3c)),0x104,param_3);
    *(undefined2 *)(*(int *)(param_1 + 0x3c) + iVar1 + 0x20c) = param_4;
    *(short *)(*(int *)(param_1 + 0x3c) + iVar1 + 0x208) = (short)param_2;
    *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar1 + 0x210) = 0;
    uVar2 = 1;
    *(undefined2 *)(*(int *)(param_1 + 0x3c) + iVar1 + 0x20a) = param_5;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 000131c8 FUN_000131c8 */

/* Boundary evidence: original MIPS .pdata 000131c8..0001329f. Semantic name remains unreviewed. */

undefined4
FUN_000131c8(int param_1,int param_2,undefined4 param_3,undefined2 param_4,wchar_t *param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 5000) {
    iVar1 = param_2 * 0x220;
    wcscpy_s((wchar_t *)(*(int *)(param_1 + 0x38) + iVar1),0x104,param_5);
    *(undefined2 *)(*(int *)(param_1 + 0x38) + iVar1 + 0x20c) = param_4;
    *(undefined4 *)(*(int *)(param_1 + 0x38) + iVar1 + 0x208) = param_6;
    if (param_2 == 0) {
      *(undefined2 *)(*(int *)(param_1 + 0x38) + 0x20c) = 0xffff;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    uVar2 = 1;
  }
  else {
    FUN_00023aac(5,0,L"%S Not addDir[%d] : %s, PID : %d, ","CFileMgr::AddDir");
    uVar2 = 0;
  }
  return uVar2;
}



/* 000132a0 FUN_000132a0 */

int FUN_000132a0(int param_1,int param_2)

{
  return (int)*(short *)(param_2 * 0x220 + *(int *)(param_1 + 0x38) + 0x20c);
}



/* 000132c0 FUN_000132c0 */

/* Boundary evidence: original MIPS .pdata 000132c0..000132fb. Semantic name remains unreviewed. */

int FUN_000132c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_00012cfc(param_1 + 8,param_2);
  return iVar1 * 0x220 + *(int *)(param_1 + 0x38);
}



/* 000132fc FUN_000132fc */

/* Boundary evidence: original MIPS .pdata 000132fc..00013317. Semantic name remains unreviewed. */

void FUN_000132fc(int param_1,int param_2)

{
  FUN_00012cfc(param_1 + 8,param_2);
  return;
}



/* 00013318 FUN_00013318 */

/* Boundary evidence: original MIPS .pdata 00013318..00013333. Semantic name remains unreviewed. */

void FUN_00013318(int param_1,int param_2)

{
  FUN_00012b2c(param_1 + 8,param_2);
  return;
}



/* 00013334 FUN_00013334 */

/* Boundary evidence: original MIPS .pdata 00013334..0001334f. Semantic name remains unreviewed. */

void FUN_00013334(int param_1,int param_2)

{
  FUN_00012cac(param_1 + 8,param_2);
  return;
}



/* 00013350 FUN_00013350 */

/* Boundary evidence: original MIPS .pdata 00013350..0001355b. Semantic name remains unreviewed. */

void FUN_00013350(int param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *_Str;
  wchar_t local_848;
  undefined1 auStack_846 [2078];
  uint local_28;
  
  local_28 = DAT_0002f960;
  local_848 = L'\0';
  memset(auStack_846,0,0x81e);
  iVar4 = param_1 + 8;
  iVar1 = FUN_00012c68(iVar4,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_00012cfc(iVar4,param_2);
    iVar4 = FUN_00012b2c(iVar4,param_2);
    swprintf_s(param_3,0x104,L"%s",iVar4);
    sVar2 = wcslen(param_3);
    if ((int)sVar2 < 0x100) {
      for (; 0 < iVar1; iVar1 = (int)*(short *)(*(int *)(param_1 + 0x38) + iVar1 * 0x220 + 0x20c)) {
        Sleep(1);
        memset(&local_848,0,0x410);
        _Str = (wchar_t *)(*(int *)(param_1 + 0x38) + iVar1 * 0x220);
        sVar3 = wcslen(_Str);
        if (0x104 < (int)(sVar3 + sVar2)) goto LAB_00013528;
        swprintf_s(&local_848,0x410,L"%s\\%s",_Str,param_3);
        wcsncpy_s(param_3,0x410,&local_848,0x410);
      }
      swprintf_s(&local_848,0x410,L"\\%s\\%s",&DAT_000272cc,param_3);
      wcsncpy_s(param_3,0x410,&local_848,0x410);
    }
LAB_00013528:
    param_3[0x103] = L'\0';
  }
  else {
    iVar1 = FUN_00012b2c(iVar4,param_2);
    swprintf_s(param_3,0x104,L"%s",iVar1);
    if (*param_3 == L'\\') {
      swprintf_s(param_3,0x104,L"%s",param_3 + 1);
    }
  }
  FUN_00025510(local_28);
  return;
}



/* 0001355c FUN_0001355c */

int FUN_0001355c(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x38);
  iVar1 = param_2 * 0x220 + iVar3;
  if (*(short *)(iVar1 + 0x214) < 1) {
    iVar1 = (int)*(short *)(iVar1 + 0x20e);
    if (iVar1 < *(int *)(param_1 + 0x1c)) {
      psVar2 = (short *)(iVar1 * 0x220 + iVar3 + 0x214);
      do {
        if (0 < *psVar2) {
          return (int)*(short *)(iVar1 * 0x220 + iVar3 + 0x212);
        }
        iVar1 = iVar1 + 1;
        psVar2 = psVar2 + 0x110;
      } while (iVar1 < *(int *)(param_1 + 0x1c));
    }
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(short *)(iVar1 + 0x212);
  }
  return iVar1;
}



/* 000135f0 FUN_000135f0 */

/* Boundary evidence: original MIPS .pdata 000135f0..0001362f. Semantic name remains unreviewed. */

void FUN_000135f0(ushort *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00017150();
  FUN_000173d8((int)puVar1,param_1,param_2);
  return;
}



/* 00013630 FUN_00013630 */

/* Boundary evidence: original MIPS .pdata 00013630..0001376f. Semantic name remains unreviewed. */

undefined4 FUN_00013630(int param_1,undefined4 param_2)

{
  HANDLE hFindFile;
  undefined4 uVar1;
  undefined4 auStack_458 [2];
  _WIN32_FIND_DATAW local_450;
  uint local_18;
  
  local_18 = DAT_0002f960;
  FUN_000209e0(auStack_458);
  local_450.dwFileAttributes = 0;
  memset(&local_450.ftCreationTime,0,0x22c);
  local_450.cFileName[0x102] = L'\0';
  memset(local_450.cFileName + 0x103,0,0x206);
  swprintf_s(local_450.cFileName + 0x102,0x104,L"%s\\*.*",param_2);
  FUN_00023aac(5,3,L"%S  FullPath: %s","CFileMgr::CheckMD");
  uVar1 = 1;
  if (*(int *)(param_1 + 0x30) == 1) {
    FUN_00023aac(5,3,L"%S m_bStop stop","CFileMgr::CheckMD");
    uVar1 = 0;
  }
  else {
    hFindFile = FindFirstFileW(local_450.cFileName + 0x102,&local_450);
    FindClose(hFindFile);
    if (hFindFile == (HANDLE)0xffffffff) {
      uVar1 = 0;
    }
  }
  FUN_000209d0(auStack_458);
  FUN_00025510(local_18);
  return uVar1;
}



/* 00013770 Unwind@00013770 */

/* Boundary evidence: original MIPS .pdata 00013770..0001379f. Semantic name remains unreviewed. */

void Unwind_00013770(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x458));
  return;
}



/* 000137a0 FUN_000137a0 */

/* Boundary evidence: original MIPS .pdata 000137a0..00013893. Semantic name remains unreviewed. */

undefined4 FUN_000137a0(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_20;
  int local_1c [3];
  
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",0,0,&local_20);
  if (LVar1 == 0) {
    local_1c[1] = 4;
    local_1c[0] = 0;
    RegQueryValueExW(local_20,L"CallState",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_1c,
                     (LPDWORD)(local_1c + 1));
    RegCloseKey(local_20);
    if (local_1c[0] == 0) {
      Sleep(0);
    }
    else {
      WaitForSingleObject(*(HANDLE *)(param_1 + 4),10);
      NKDbgPrintfW(&DAT_00027448);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 00013894 FUN_00013894 */

/* Boundary evidence: original MIPS .pdata 00013894..00013cc3. Semantic name remains unreviewed. */

undefined4
FUN_00013894(int param_1,LPWIN32_FIND_DATAW param_2,HANDLE param_3,int param_4,int param_5,
            int *param_6,int *param_7,int *param_8)

{
  int iVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  BOOL BVar4;
  undefined2 uVar5;
  uint uVar6;
  undefined2 uVar7;
  DWORD *pDVar8;
  int iVar9;
  wchar_t local_248;
  undefined1 auStack_246 [14];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_0002f960;
  local_248 = L'\0';
  memset(auStack_246,0,0xe);
  do {
    if (*(int *)(param_1 + 0x30) != 0) {
      FindClose(param_3);
LAB_00013c88:
      FUN_00025510(local_30);
      return 0;
    }
    iVar1 = FUN_000231a4();
    if ((*(int *)(iVar1 + 0x38) == 0) || (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x18) == 1)) {
      iVar1 = FUN_000231a4();
      iVar9 = FUN_000231a4();
      NKDbgPrintfW(L"\r\nEXITEXIT SearchDir1() [%d, %d]\r\n",*(undefined4 *)(iVar9 + 0x38),
                   *(undefined4 *)(iVar1 + 0x18));
      goto LAB_00013c88;
    }
    iVar9 = param_1 + 8;
    iVar1 = FUN_00012d4c(iVar9);
    if (4999 < iVar1) break;
    uVar6 = param_2->dwFileAttributes;
    uVar5 = (undefined2)param_4;
    if ((((uVar6 & 0x10) == 0) || ((uVar6 & 2) != 0)) || ((uVar6 & 4) != 0)) {
      if (uVar6 == 0x26) goto LAB_00013c18;
      if ((uVar6 & 2) == 0) {
        pDVar8 = &param_2->dwReserved1;
        wcscpy_s(awStack_238,0x104,(wchar_t *)pDVar8);
        sVar2 = wcslen((wchar_t *)pDVar8);
        _wcsupr_s(awStack_238,0x104);
        wcscpy_s(&local_248,7,awStack_238 + (sVar2 - 4));
        pwVar3 = wcsstr(&local_248,L".MP3");
        if (pwVar3 == (wchar_t *)0x0) {
          pwVar3 = wcsstr(&local_248,L".WMA");
          if (pwVar3 == (wchar_t *)0x0) {
            pwVar3 = wcsstr(&local_248,L".M3U");
            if (pwVar3 == (wchar_t *)0x0) {
              pwVar3 = wcsstr(&local_248,L".PLS");
              if (pwVar3 == (wchar_t *)0x0) {
                pwVar3 = wcsstr(&local_248,L".WPL");
                if (pwVar3 == (wchar_t *)0x0) goto LAB_00013c18;
                uVar7 = 9;
              }
              else {
                uVar7 = 8;
              }
            }
            else {
              uVar7 = 7;
            }
            iVar1 = FUN_000131c8(param_1,*(int *)(param_1 + 0x1c),param_5 + 1,uVar5,
                                 (wchar_t *)pDVar8,1);
            if (iVar1 != 0) {
              *param_6 = *param_6 + 1;
              iVar1 = FUN_0001311c(param_1,*param_8,(wchar_t *)pDVar8,uVar5,uVar7);
              if (iVar1 != 0) {
                *param_8 = *param_8 + 1;
              }
            }
            goto LAB_00013c18;
          }
          uVar5 = 2;
        }
        else {
          uVar5 = 1;
        }
        iVar1 = FUN_00012d4c(iVar9);
        if (iVar1 < 5000) {
          iVar1 = FUN_00012d4c(iVar9);
          iVar1 = FUN_00012f80(param_1,iVar1,(wchar_t *)pDVar8,param_4,uVar5,0);
          if (iVar1 != 0) {
            *param_7 = *param_7 + 1;
          }
        }
        goto LAB_00013c18;
      }
    }
    else {
      pDVar8 = &param_2->dwReserved1;
      iVar1 = wcscmp((wchar_t *)pDVar8,L".");
      if ((((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)pDVar8,L".."), iVar1 != 0)) &&
          ((iVar1 = wcscmp((wchar_t *)pDVar8,L"Recycled"), iVar1 != 0 &&
           ((iVar1 = wcscmp((wchar_t *)pDVar8,L"System Volume Information"), iVar1 != 0 &&
            (iVar1 = wcscmp((wchar_t *)pDVar8,L".Trashes"), iVar1 != 0)))))) &&
         (iVar1 = FUN_000131c8(param_1,*(int *)(param_1 + 0x1c),param_5 + 1,uVar5,(wchar_t *)pDVar8,
                               0), iVar1 != 0)) {
        *param_6 = *param_6 + 1;
      }
LAB_00013c18:
      FUN_000137a0(param_1);
    }
    BVar4 = FindNextFileW(param_3,param_2);
  } while (BVar4 != 0);
  FUN_00025510(local_30);
  return 1;
}



/* 00013cc4 FUN_00013cc4 */

/* Boundary evidence: original MIPS .pdata 00013cc4..00013d87. Semantic name remains unreviewed. */

undefined4 FUN_00013cc4(int param_1,wchar_t *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_000231a4();
  if ((*(int *)(iVar1 + 0x38) == 0) || (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x18) == 1)) {
    iVar1 = FUN_000231a4();
    iVar2 = FUN_000231a4();
    NKDbgPrintfW(L"\r\nEXITEXIT SearchDir3() [%d, %d]\r\n",*(undefined4 *)(iVar2 + 0x38),
                 *(undefined4 *)(iVar1 + 0x18));
  }
  else {
    iVar1 = FUN_00015620(param_1,param_2,param_3,param_4);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 00013d88 FUN_00013d88 */

/* Boundary evidence: original MIPS .pdata 00013d88..00013f0f. Semantic name remains unreviewed. */

void FUN_00013d88(int param_1,size_t param_2,int param_3,size_t param_4,int param_5,int param_6)

{
  void *_Base;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)param_3;
  if ((int)param_2 < 2) {
    if (param_2 == 1) {
      *(undefined2 *)(param_3 * 0x220 + *(int *)(param_1 + 0x38) + 0x21a) = uVar4;
    }
  }
  else if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
    iVar3 = param_3 * 0x220;
    qsort(*(undefined **)(param_1 + 0x38) + iVar3,param_2,0x220,FUN_000135f0);
    iVar2 = param_2 + param_3;
    for (; param_3 < iVar2; param_3 = param_3 + 1) {
      *(short *)(*(int *)(param_1 + 0x38) + iVar3 + 0x21a) = (short)param_3;
      iVar3 = iVar3 + 0x220;
    }
  }
  if ((1 < (int)param_4) && (*(undefined **)(param_1 + 0x38) != &DAT_000275c4)) {
    _Base = (void *)FUN_00012d5c(param_1 + 8,param_5);
    qsort(_Base,param_4,0x210,FUN_000135f0);
  }
  if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
    *(undefined2 *)(param_6 + 0x20e) = uVar4;
    *(short *)(param_6 + 0x210) = (short)param_2;
  }
  if (param_4 == 0) {
    if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
      *(undefined2 *)(param_6 + 0x212) = 0xffff;
    }
  }
  else if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
    uVar1 = FUN_00012d4c(param_1 + 8);
    *(short *)(param_6 + 0x212) = (short)uVar1 - (short)param_4;
  }
  if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
    *(short *)(param_6 + 0x214) = (short)param_4;
  }
  return;
}



/* 00013f10 FUN_00013f10 */

/* Boundary evidence: original MIPS .pdata 00013f10..000140af. Semantic name remains unreviewed. */

void FUN_00013f10(undefined4 param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_0002f960;
  FUN_00023aac(5,0,L"%S Line %d ------------ start -----------","CFileMgr::getCurrentPath");
  if (param_3 != (wchar_t *)0x0) {
    iVar1 = FUN_000231a4();
    iVar1 = *(int *)(*(int *)(iVar1 + 0x48) + 0x38);
    if (iVar1 != 0) {
      local_228 = L'\0';
      memset(auStack_226,0,0x206);
      memset(param_3,0,0x208);
      iVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
      if (iVar2 == 0) {
        FUN_00023aac(5,0,L"%S Line %d ------------ No USB device return -----------",
                     "CFileMgr::getCurrentPath");
      }
      else {
        while (-1 < param_2) {
          memset(&local_228,0,0x208);
          iVar2 = param_2 * 0x220 + iVar1;
          swprintf_s(&local_228,0x104,L"%s\\%s",iVar2,param_3);
          wcsncpy_s(param_3,0x104,&local_228,0x104);
          param_2 = (int)*(short *)(iVar2 + 0x20c);
        }
        FUN_00023aac(5,0,L"%S Line %d ------------ end -----------","CFileMgr::getCurrentPath");
      }
    }
  }
  FUN_00025510(local_20);
  return;
}



/* 000140b0 FUN_000140b0 */

/* Boundary evidence: original MIPS .pdata 000140b0..0001438f. Semantic name remains unreviewed. */

int FUN_000140b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *_Src;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar4 = 0;
  }
  else {
    iVar3 = param_2 * 0x220 + *(int *)(param_1 + 0x38);
    iVar4 = 0;
    if (iVar3 != 0) {
      iVar2 = (int)*(short *)(iVar3 + 0x20e);
      if (iVar2 < *(short *)(iVar3 + 0x210) + iVar2) {
        do {
          Sleep(1);
          iVar1 = iVar2;
          if (iVar2 < 0) {
            iVar1 = 0;
          }
          _Src = (void *)(iVar1 * 0x220 + *(int *)(param_1 + 0x38));
          if (((_Src != (void *)0x0) && (*(short *)((int)_Src + 0x21a) != 0)) &&
             (*(int *)((int)_Src + 0x21c) == 2)) {
            if (param_3 != 0) {
              memcpy((void *)(DAT_0002fea4 * 0x220 + param_3),_Src,0x208);
              iVar4 = iVar4 + 1;
              *(undefined4 *)(DAT_0002fea4 * 0x220 + param_3 + 0x208) =
                   *(undefined4 *)((int)_Src + 0x208);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x20c) =
                   *(undefined2 *)((int)_Src + 0x20c);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x20e) =
                   *(undefined2 *)((int)_Src + 0x20e);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x210) =
                   *(undefined2 *)((int)_Src + 0x210);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x212) =
                   *(undefined2 *)((int)_Src + 0x212);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x214) =
                   *(undefined2 *)((int)_Src + 0x214);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x216) =
                   *(undefined2 *)((int)_Src + 0x216);
              *(undefined2 *)(DAT_0002fea4 * 0x220 + param_3 + 0x218) =
                   *(undefined2 *)((int)_Src + 0x218);
              *(undefined4 *)(DAT_0002fea4 * 0x220 + param_3 + 0x21c) =
                   *(undefined4 *)((int)_Src + 0x21c);
              *(short *)(DAT_0002fea4 * 0x220 + param_3 + 0x21a) = (short)iVar2;
              DAT_0002fea4 = DAT_0002fea4 + 1;
            }
            iVar1 = FUN_000140b0(param_1,iVar2,param_3);
            iVar4 = iVar1 + iVar4;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)*(short *)(iVar3 + 0x210) + (int)*(short *)(iVar3 + 0x20e));
      }
      iVar1 = (int)*(short *)(iVar3 + 0x20e);
      iVar2 = *(short *)(iVar3 + 0x210) + iVar1;
      for (; iVar1 < iVar2; iVar1 = iVar1 + 1) {
        Sleep(1);
        iVar2 = iVar1;
        if (iVar1 < 0) {
          iVar2 = 0;
        }
        iVar2 = iVar2 * 0x220 + *(int *)(param_1 + 0x38);
        if ((iVar2 != 0) && (*(int *)(iVar2 + 0x21c) == 1)) {
          iVar2 = FUN_000140b0(param_1,iVar1,param_3);
          iVar4 = iVar2 + iVar4;
        }
        iVar2 = (int)*(short *)(iVar3 + 0x210) + (int)*(short *)(iVar3 + 0x20e);
      }
    }
  }
  return iVar4;
}



/* 00014390 FUN_00014390 */

/* Boundary evidence: original MIPS .pdata 00014390..000146eb. Semantic name remains unreviewed. */

undefined4 FUN_00014390(int param_1,int param_2,undefined2 param_3,int param_4)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  size_t _NumOfElements;
  int iVar7;
  short sVar8;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar7 = param_2 * 0x220 + *(int *)(param_1 + 0x38);
    if (iVar7 != 0) {
      iVar4 = (int)*(short *)(iVar7 + 0x20e);
      sVar8 = 0;
      if (*(short *)(iVar7 + 0x210) + iVar4 <= iVar4) {
        return 1;
      }
      while (iVar3 = FUN_000231a4(), *(int *)(iVar3 + 0x18) == 0) {
        Sleep(1);
        iVar3 = iVar4;
        if (iVar4 < 0) {
          iVar3 = 0;
        }
        pvVar6 = (void *)(iVar3 * 0x220 + *(int *)(param_1 + 0x38));
        if ((pvVar6 != (void *)0x0) && (0 < *(int *)((int)pvVar6 + 0x21c))) {
          if (param_4 < 3) {
            if (param_2 * 0x220 + *(int *)(param_1 + 0x38) == 0) {
              return 0;
            }
            *(undefined2 *)((int)pvVar6 + 0x216) = param_3;
            sVar2 = *(short *)((int)pvVar6 + 0x21a);
            *(short *)((int)pvVar6 + 0x218) = sVar8;
            sVar8 = sVar8 + 1;
            if ((-1 < sVar2) && (sVar2 < 5000)) {
              *(short *)(*(short *)(param_1 + 0x2750) * 2 + param_1 + 0x40) = sVar2;
              *(short *)(param_1 + 0x2750) = *(short *)(param_1 + 0x2750) + 1;
            }
            FUN_00014390(param_1,iVar4,(short)iVar4,param_4 + 1);
          }
          else {
            DAT_0002fea4 = 0;
            bVar1 = 0 < *(short *)((int)pvVar6 + 0x214);
            if (bVar1) {
              memcpy(DAT_0002fea0,pvVar6,0x208);
              *(undefined4 *)((int)DAT_0002fea0 + 0x208) = *(undefined4 *)((int)pvVar6 + 0x208);
              *(undefined2 *)((int)DAT_0002fea0 + 0x20c) = *(undefined2 *)((int)pvVar6 + 0x20c);
              *(undefined2 *)((int)DAT_0002fea0 + 0x20e) = *(undefined2 *)((int)pvVar6 + 0x20e);
              *(undefined2 *)((int)DAT_0002fea0 + 0x210) = *(undefined2 *)((int)pvVar6 + 0x210);
              *(undefined2 *)((int)DAT_0002fea0 + 0x212) = *(undefined2 *)((int)pvVar6 + 0x212);
              *(undefined2 *)((int)DAT_0002fea0 + 0x214) = *(undefined2 *)((int)pvVar6 + 0x214);
              *(undefined2 *)((int)DAT_0002fea0 + 0x216) = *(undefined2 *)((int)pvVar6 + 0x216);
              *(undefined2 *)((int)DAT_0002fea0 + 0x218) = *(undefined2 *)((int)pvVar6 + 0x218);
              *(undefined4 *)((int)DAT_0002fea0 + 0x21c) = *(undefined4 *)((int)pvVar6 + 0x21c);
              *(short *)((int)DAT_0002fea0 + 0x21a) = (short)iVar4;
            }
            DAT_0002fea4 = (uint)bVar1;
            iVar3 = FUN_000140b0(param_1,iVar4,(int)DAT_0002fea0);
            _NumOfElements = iVar3 + (uint)bVar1;
            if (0 < (int)_NumOfElements) {
              if (1 < (int)_NumOfElements) {
                qsort(DAT_0002fea0,_NumOfElements,0x220,FUN_000135f0);
              }
              if (0 < (int)_NumOfElements) {
                iVar3 = 0;
                pvVar6 = DAT_0002fea0;
                do {
                  iVar5 = (int)*(short *)((int)pvVar6 + iVar3 + 0x21a);
                  if (iVar5 < 0) {
                    iVar5 = 0;
                  }
                  iVar5 = iVar5 * 0x220 + *(int *)(param_1 + 0x38);
                  if (iVar5 != 0) {
                    sVar2 = *(short *)(iVar5 + 0x21a);
                    *(short *)(iVar5 + 0x218) = sVar8;
                    sVar8 = sVar8 + 1;
                    *(undefined2 *)(iVar5 + 0x216) = param_3;
                    pvVar6 = DAT_0002fea0;
                    if ((-1 < sVar2) && (sVar2 < 5000)) {
                      *(short *)(*(short *)(param_1 + 0x2750) * 2 + param_1 + 0x40) = sVar2;
                      *(short *)(param_1 + 0x2750) = *(short *)(param_1 + 0x2750) + 1;
                      pvVar6 = DAT_0002fea0;
                    }
                  }
                  _NumOfElements = _NumOfElements - 1;
                  iVar3 = iVar3 + 0x220;
                } while (_NumOfElements != 0);
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
        if ((int)*(short *)(iVar7 + 0x210) + (int)*(short *)(iVar7 + 0x20e) <= iVar4) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 000146ec FUN_000146ec */

int FUN_000146ec(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 0x2750) < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(short *)((*(short *)(param_1 + 0x2750) + 0x1f) * 2 + param_1);
  }
  return iVar1;
}



/* 00014720 FUN_00014720 */

/* Boundary evidence: original MIPS .pdata 00014720..00014883. Semantic name remains unreviewed. */

int FUN_00014720(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x2750)) {
    psVar3 = (short *)(param_1 + 0x40);
    do {
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x18) != 0) {
        return 0;
      }
      Sleep(1);
      iVar1 = iVar4;
      if (param_2 == *psVar3) break;
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 1;
      iVar1 = 0;
    } while (iVar4 < *(short *)(param_1 + 0x2750));
  }
  while( true ) {
    iVar4 = FUN_000231a4();
    if (*(int *)(iVar4 + 0x18) != 0) {
      return 0;
    }
    Sleep(1);
    iVar1 = iVar1 + 1;
    if (*(short *)(param_1 + 0x2750) <= iVar1) {
      iVar1 = 0;
    }
    iVar2 = (int)*(short *)((iVar1 + 0x20) * 2 + param_1);
    iVar4 = iVar2;
    if (iVar2 < 0) {
      iVar4 = 0;
    }
    iVar4 = iVar4 * 0x220 + *(int *)(param_1 + 0x38);
    if ((iVar4 != 0) && (0 < *(short *)(iVar4 + 0x214))) break;
    if (param_2 == iVar2) {
      return param_2;
    }
  }
  return (int)*(short *)((iVar1 + 0x20) * 2 + param_1);
}



/* 00014884 FUN_00014884 */

/* Boundary evidence: original MIPS .pdata 00014884..000149df. Semantic name remains unreviewed. */

int FUN_00014884(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x2750)) {
    psVar2 = (short *)(param_1 + 0x40);
    do {
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x18) != 0) {
        return 0;
      }
      Sleep(1);
      iVar1 = iVar3;
      if (param_2 == *psVar2) break;
      iVar3 = iVar3 + 1;
      psVar2 = psVar2 + 1;
      iVar1 = 0;
    } while (iVar3 < *(short *)(param_1 + 0x2750));
  }
  while( true ) {
    iVar3 = FUN_000231a4();
    if (*(int *)(iVar3 + 0x18) != 0) {
      return 0;
    }
    Sleep(1);
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      iVar1 = *(short *)(param_1 + 0x2750) + -1;
    }
    iVar3 = (int)*(short *)((iVar1 + 0x20) * 2 + param_1);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar3 = iVar3 * 0x220 + *(int *)(param_1 + 0x38);
    if ((iVar3 != 0) && (0 < *(short *)(iVar3 + 0x214))) break;
    if (param_2 == iVar1) {
      return param_2;
    }
  }
  return (int)*(short *)((iVar1 + 0x20) * 2 + param_1);
}



/* 000149e0 FUN_000149e0 */

/* Boundary evidence: original MIPS .pdata 000149e0..00014ab7. Semantic name remains unreviewed. */

int FUN_000149e0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar3 = 0;
  }
  else {
    iVar2 = param_2 * 0x220 + *(int *)(param_1 + 0x38);
    iVar3 = 0;
    if (iVar2 != 0) {
      psVar4 = (short *)(iVar2 + 0x216);
      sVar1 = *psVar4;
      while (0 < sVar1) {
        Sleep(1);
        iVar2 = (int)*psVar4;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        iVar2 = iVar2 * 0x220 + *(int *)(param_1 + 0x38);
        if (iVar2 == 0) {
          return iVar3;
        }
        psVar4 = (short *)(iVar2 + 0x216);
        iVar3 = iVar3 + 1;
        sVar1 = *psVar4;
      }
    }
  }
  return iVar3;
}



/* 00014ab8 FUN_00014ab8 */

int FUN_00014ab8(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < *(short *)(param_1 + 0x2750)) {
    psVar2 = (short *)(param_1 + 0x40);
    do {
      if (param_2 == *psVar2) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 1;
    } while (iVar1 < *(short *)(param_1 + 0x2750));
  }
  return 0;
}



/* 00014b00 FUN_00014b00 */

/* Boundary evidence: original MIPS .pdata 00014b00..00014c53. Semantic name remains unreviewed. */

undefined4 *
FUN_00014b00(undefined4 *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  int iVar1;
  HANDLE pvVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  
  *param_1 = &PTR_FUN_000278cc;
  FUN_00012aa4(param_1 + 2,param_2,param_3,param_4);
  FUN_000209e0(param_1 + 0x9d5);
  FUN_00012e1c((int)param_1);
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  iVar1 = FUN_00012844(0x4536c0,param_2,param_3,param_4);
  pwVar5 = L"** [MgrUsb] ExtMemory Alloc Successed  %s, %d **";
  pwVar6 = L"CFileMgr::CFileMgr";
  uVar3 = 3;
  param_1[0xf] = iVar1;
  if (iVar1 == 0) {
    pwVar4 = L"***[MgrUsb] CExtMemUtil::getExtMemory(m_pstPlayList); ExtMemory Alloc failed***";
    FUN_00023aac(5,3,
                 L"***[MgrUsb] CExtMemUtil::getExtMemory(m_pstPlayList); ExtMemory Alloc failed***",
                 param_4);
  }
  else {
    pwVar4 = pwVar5;
    param_4 = pwVar6;
    FUN_00023aac(5,3,L"** [MgrUsb] ExtMemory Alloc Successed  %s, %d **",L"CFileMgr::CFileMgr");
  }
  DAT_0002fea0 = FUN_00012844(0x298100,uVar3,pwVar4,param_4);
  uVar3 = 3;
  if (DAT_0002fea0 == 0) {
    pwVar5 = L"***[MgrUsb] CExtMemUtil::getExtMemory(gpSubAllDirInfo); ExtMemory Alloc failed***";
    FUN_00023aac(5,3,
                 L"***[MgrUsb] CExtMemUtil::getExtMemory(gpSubAllDirInfo); ExtMemory Alloc failed***"
                 ,param_4);
    pwVar6 = param_4;
  }
  else {
    FUN_00023aac(5,3,L"** [MgrUsb] ExtMemory Alloc Successed  %s, %d **",L"CFileMgr::CFileMgr");
  }
  uVar3 = FUN_00012844(0x298100,uVar3,pwVar5,pwVar6);
  param_1[0xe] = uVar3;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[1] = pvVar2;
  return param_1;
}



/* 00014c54 Unwind@00014c54 */

/* Boundary evidence: original MIPS .pdata 00014c54..00014c87. Semantic name remains unreviewed. */

void Unwind_00014c54(void)

{
  int *in_v0;
  
  FUN_00012d88((undefined4 *)(*in_v0 + 8));
  return;
}



/* 00014c88 Unwind@00014c88 */

/* Boundary evidence: original MIPS .pdata 00014c88..00014cbb. Semantic name remains unreviewed. */

void Unwind_00014c88(void)

{
  int *in_v0;
  
  FUN_000209d0((undefined4 *)(*in_v0 + 0x2754));
  return;
}



/* 00014cbc FUN_00014cbc */

/* Boundary evidence: original MIPS .pdata 00014cbc..00014d47. Semantic name remains unreviewed. */

void FUN_00014cbc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000278cc;
  FUN_00012e1c((int)param_1);
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
    param_1[1] = 0;
  }
  FUN_000209d0(param_1 + 0x9d5);
  FUN_00012d88(param_1 + 2);
  return;
}



/* 00014d48 Unwind@00014d48 */

/* Boundary evidence: original MIPS .pdata 00014d48..00014d7b. Semantic name remains unreviewed. */

void Unwind_00014d48(void)

{
  int *in_v0;
  
  FUN_00012d88((undefined4 *)(*in_v0 + 8));
  return;
}



/* 00014d7c Unwind@00014d7c */

/* Boundary evidence: original MIPS .pdata 00014d7c..00014daf. Semantic name remains unreviewed. */

void Unwind_00014d7c(void)

{
  int *in_v0;
  
  FUN_000209d0((undefined4 *)(*in_v0 + 0x2754));
  return;
}



/* 00014db0 FUN_00014db0 */

/* Boundary evidence: original MIPS .pdata 00014db0..00014e1b. Semantic name remains unreviewed. */

void FUN_00014db0(undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  undefined4 *puVar1;
  
  if (DAT_0002fe9c == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x275c);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_0002fe9c = (undefined4 *)0x0;
    }
    else {
      DAT_0002fe9c = FUN_00014b00(puVar1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 00014e1c Unwind@00014e1c */

/* Boundary evidence: original MIPS .pdata 00014e1c..00014e4b. Semantic name remains unreviewed. */

void Unwind_00014e1c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00014e4c FUN_00014e4c */

/* Boundary evidence: original MIPS .pdata 00014e4c..00014f93. Semantic name remains unreviewed. */

int FUN_00014e4c(int param_1,wchar_t *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((DAT_0002fec0 & 1) == 0) {
    DAT_0002fec0 = DAT_0002fec0 | 1;
    FUN_00015b44((undefined4 *)&DAT_0002fea8,param_2,param_3,param_4);
    FUN_000258bc(FUN_00025e80);
  }
  iVar2 = FUN_00015ba0((int *)&DAT_0002fea8,param_2,param_3);
  iVar1 = DAT_0002feb4;
  if ((iVar2 != 0) && (iVar2 = 0, 0 < DAT_0002feb4)) {
    do {
      pwVar3 = (wchar_t *)FUN_000160d0(0x2fea8,iVar2);
      if (pwVar3 == (wchar_t *)0x0) {
        return iVar5;
      }
      iVar4 = FUN_00012d4c(param_1 + 8);
      iVar4 = FUN_00012f80(param_1,iVar4,pwVar3,param_4 + param_5,
                           (short)*(undefined4 *)(pwVar3 + 0x106),1);
      if (iVar4 != 0) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar5;
}



/* 00014f94 Unwind@00014f94 */

/* Boundary evidence: original MIPS .pdata 00014f94..00014fb7. Semantic name remains unreviewed. */

void Unwind_00014f94(void)

{
  DAT_0002fec0 = DAT_0002fec0 & 0xfffffffe;
  return;
}



/* 00014fb8 FUN_00014fb8 */

/* Boundary evidence: original MIPS .pdata 00014fb8..000150ff. Semantic name remains unreviewed. */

int FUN_00014fb8(int param_1,wchar_t *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((DAT_0002fedc & 1) == 0) {
    DAT_0002fedc = DAT_0002fedc | 1;
    FUN_0001658c((undefined4 *)&DAT_0002fec4,param_2,param_3,param_4);
    FUN_000258bc(FUN_00025ea0);
  }
  iVar2 = FUN_00015ba0((int *)&DAT_0002fec4,param_2,param_3);
  iVar1 = DAT_0002fed0;
  if ((iVar2 != 0) && (iVar2 = 0, 0 < DAT_0002fed0)) {
    do {
      pwVar3 = (wchar_t *)FUN_000160d0(0x2fec4,iVar2);
      if (pwVar3 == (wchar_t *)0x0) {
        return iVar5;
      }
      iVar4 = FUN_00012d4c(param_1 + 8);
      iVar4 = FUN_00012f80(param_1,iVar4,pwVar3,param_4 + param_5,
                           (short)*(undefined4 *)(pwVar3 + 0x106),1);
      if (iVar4 != 0) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar5;
}



/* 00015100 Unwind@00015100 */

/* Boundary evidence: original MIPS .pdata 00015100..00015123. Semantic name remains unreviewed. */

void Unwind_00015100(void)

{
  DAT_0002fedc = DAT_0002fedc & 0xfffffffe;
  return;
}



/* 00015124 FUN_00015124 */

/* Boundary evidence: original MIPS .pdata 00015124..0001527f. Semantic name remains unreviewed. */

int FUN_00015124(int param_1,wchar_t *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = DAT_0002f960;
  if ((DAT_0002fef8 & 1) == 0) {
    DAT_0002fef8 = DAT_0002fef8 | 1;
    FUN_000168b4((undefined4 *)&DAT_0002fee0,param_2,param_3,param_4);
    FUN_000258bc(FUN_00025ec0);
  }
  iVar6 = 0;
  iVar3 = FUN_00015ba0((int *)&DAT_0002fee0,param_2,param_3);
  iVar2 = DAT_0002feec;
  if ((iVar3 != 0) && (iVar3 = 0, 0 < DAT_0002feec)) {
    do {
      pwVar4 = (wchar_t *)FUN_000160d0(0x2fee0,iVar3);
      if (pwVar4 != (wchar_t *)0x0) {
        iVar5 = FUN_00012d4c(param_1 + 8);
        iVar5 = FUN_00012f80(param_1,iVar5,pwVar4,param_4 + param_5,
                             (short)*(undefined4 *)(pwVar4 + 0x106),1);
        if (iVar5 != 0) {
          iVar6 = iVar6 + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00025510(uVar1);
  return iVar6;
}



/* 00015280 Unwind@00015280 */

/* Boundary evidence: original MIPS .pdata 00015280..000152a3. Semantic name remains unreviewed. */

void Unwind_00015280(void)

{
  DAT_0002fef8 = DAT_0002fef8 & 0xfffffffe;
  return;
}



/* 000152a4 FUN_000152a4 */

/* Boundary evidence: original MIPS .pdata 000152a4..0001561f. Semantic name remains unreviewed. */

undefined4
FUN_000152a4(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4,int param_5,int param_6,
            int param_7,int *param_8,int param_9)

{
  wchar_t wVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *_Base;
  undefined2 *puVar5;
  wchar_t *_Str1;
  size_t _NumOfElements;
  int iVar6;
  int iVar7;
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_0002f960;
  iVar7 = 0;
  if (0 < param_4) {
    puVar5 = (undefined2 *)(param_9 + 0x210);
    do {
      if (0x13 < param_6) break;
      swprintf(param_2,0x27394,param_3,puVar5 + -0x108);
      param_2[0x207] = L'\0';
      iVar2 = FUN_00012d4c(param_1 + 8);
      *param_8 = iVar2;
      if (*(int *)(puVar5 + -4) == 0) {
        iVar2 = FUN_00013cc4(param_1,param_2,iVar7 + param_5,param_6 + 1);
        if (iVar2 == 0) {
          FUN_00025510(local_30);
          return 0;
        }
        if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
          iVar2 = FUN_00012d4c(param_1 + 8);
          if (*param_8 == iVar2) {
            *(undefined4 *)(puVar5 + 6) = 0;
          }
          else {
            if (*(int *)(puVar5 + 6) != 2) {
              *(undefined4 *)(puVar5 + 6) = 1;
            }
            *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
          }
        }
LAB_000155a8:
        FUN_000137a0(param_1);
      }
      else {
        iVar2 = 0;
        if (0 < param_7) {
          iVar6 = 0;
          do {
            if ((iVar2 < 1000) && (*(int *)(param_1 + 0x3c) != 0)) {
              _Str1 = (wchar_t *)(iVar6 + *(int *)(param_1 + 0x3c));
              if (_Str1 != (wchar_t *)0x0) {
                iVar3 = wcscmp(_Str1,puVar5 + -0x108);
                if (iVar3 != 0) goto LAB_000153bc;
                break;
              }
            }
            else {
LAB_000153bc:
              _Str1 = (wchar_t *)0x0;
            }
            iVar2 = iVar2 + 1;
            iVar6 = iVar6 + 0x11b8;
          } while (iVar2 < param_7);
          if (_Str1 != (wchar_t *)0x0) {
            local_238 = L'\0';
            _NumOfElements = 0;
            memset(auStack_236,0,0x206);
            swprintf_s(&local_238,0x104,L"%s\\%s",param_3,_Str1);
            wVar1 = _Str1[0x105];
            if (wVar1 == L'\a') {
              _NumOfElements = FUN_00014e4c(param_1,&local_238,param_3,param_5,iVar7);
            }
            else if (wVar1 == L'\b') {
              _NumOfElements = FUN_00014fb8(param_1,&local_238,param_3,param_5,iVar7);
            }
            else if (wVar1 == L'\t') {
              _NumOfElements = FUN_00015124(param_1,&local_238,param_3,param_5,iVar7);
            }
            if (*(undefined **)(param_1 + 0x38) != &DAT_000275c4) {
              if ((int)_NumOfElements < 1) {
                puVar5[1] = 0xffff;
                puVar5[2] = 0;
                *(undefined4 *)(puVar5 + 6) = 0;
              }
              else {
                uVar4 = FUN_00012d4c(param_1 + 8);
                puVar5[2] = (short)_NumOfElements;
                puVar5[1] = (short)uVar4 - (short)_NumOfElements;
                if (*(int *)(puVar5 + 6) != 2) {
                  *(undefined4 *)(puVar5 + 6) = 1;
                }
                *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
              }
              _Base = (void *)FUN_00012d5c(param_1 + 8,*param_8);
              if (1 < (int)_NumOfElements) {
                qsort(_Base,_NumOfElements,0x210,FUN_000135f0);
              }
              puVar5[-1] = 0;
              *puVar5 = 0;
            }
            goto LAB_000155a8;
          }
        }
      }
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 0x110;
    } while (iVar7 < param_4);
  }
  FUN_00025510(local_30);
  return 1;
}



/* 00015620 FUN_00015620 */

/* Boundary evidence: original MIPS .pdata 00015620..0001584b. Semantic name remains unreviewed. */

undefined4 FUN_00015620(int param_1,wchar_t *param_2,int param_3,int param_4)

{
  size_t sVar1;
  bool bVar2;
  int iVar3;
  HANDLE hFindFile;
  int iVar4;
  undefined4 uVar5;
  undefined3 extraout_var;
  int iVar6;
  size_t local_688;
  size_t local_684;
  int local_680;
  int local_67c;
  int local_678;
  _WIN32_FIND_DATAW local_670 [2];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_0002f960;
  local_670[0].dwFileAttributes = 0;
  memset(&local_670[0].ftCreationTime,0,0x22c);
  local_670[0].cFileName[0x102] = L'\0';
  memset(local_670[0].cFileName + 0x103,0,0x40e);
  iVar3 = FUN_00012d4c(param_1 + 8);
  iVar6 = *(int *)(param_1 + 0x1c);
  local_684 = 0;
  local_67c = 0;
  local_688 = 0;
  local_678 = param_3 * 0x220 + *(int *)(param_1 + 0x38);
  local_680 = iVar6 * 0x220 + *(int *)(param_1 + 0x38);
  swprintf(local_670[0].cFileName + 0x102,0x27ab8,param_2);
  local_32 = 0;
  hFindFile = FindFirstFileW(local_670[0].cFileName + 0x102,local_670);
  if (hFindFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"[INFO] No File in folder\r\n");
    bVar2 = FUN_00024b90(param_1 + 0x2754,L"MD");
    if (CONCAT31(extraout_var,bVar2) != 0) {
      FUN_00025510(local_30);
      return 1;
    }
  }
  else {
    iVar4 = FUN_00013894(param_1,local_670,hFindFile,param_3,param_4,(int *)&local_684,
                         (int *)&local_688,(int *)(param_1 + 0x24));
    if (iVar4 != 0) {
      FindClose(hFindFile);
      sVar1 = local_684;
      FUN_00013d88(param_1,local_684,iVar6,local_688,iVar3,local_678);
      uVar5 = FUN_000152a4(param_1,local_670[0].cFileName + 0x102,param_2,sVar1,iVar6,param_4,
                           *(int *)(param_1 + 0x24),&local_67c,local_680);
      FUN_00025510(local_30);
      return uVar5;
    }
    FindClose(hFindFile);
  }
  FUN_00025510(local_30);
  return 0;
}



/* 0001584c FUN_0001584c */

/* Boundary evidence: original MIPS .pdata 0001584c..00015a93. Semantic name remains unreviewed. */

int FUN_0001584c(int param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  void *_Src;
  int iVar5;
  int iVar6;
  int *piVar7;
  short *psVar8;
  
  if (param_3 != (int *)0x0) {
    uVar1 = (int)param_3 + 0xfU & 3;
    puVar2 = (uint *)(((int)param_3 + 0xfU) - uVar1);
    *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
    uVar1 = (int)param_3 + 3U & 3;
    puVar2 = (uint *)(((int)param_3 + 3U) - uVar1);
    *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
    uVar1 = (uint)(param_3 + 3) & 3;
    puVar2 = (uint *)((int)(param_3 + 3) - uVar1);
    *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
    uVar1 = (uint)param_3 & 3;
    *(uint *)((int)param_3 - uVar1) =
         *(uint *)((int)param_3 - uVar1) & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
    FUN_00023aac(5,3,L"%S  line %d  pList->nDataSize = %d","CFileMgr::getListValidSubFolder");
  }
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar6 = 0;
  }
  else {
    iVar3 = FUN_00014ab8(param_1,param_2);
    iVar6 = 0;
    if ((iVar3 != 0) || (iVar5 = 0, 0 < *(short *)(*(int *)(param_1 + 0x38) + 0x214))) {
      iVar5 = iVar3 + 1;
    }
    if (iVar5 < *(short *)(param_1 + 0x2750)) {
      piVar7 = param_3 + 0x24a76;
      psVar8 = (short *)((iVar5 + 0x20) * 2 + param_1);
      do {
        Sleep(0);
        iVar4 = (int)*psVar8;
        iVar3 = iVar4;
        if (iVar4 < 0) {
          iVar3 = 0;
        }
        _Src = (void *)(iVar3 * 0x220 + *(int *)(param_1 + 0x38));
        if (((_Src != (void *)0x0) && (*(short *)((int)_Src + 0x216) == param_2)) &&
           (param_3 != (int *)0x0)) {
          memcpy(param_3 + *param_3 * 0x1e + 0x86,_Src,0x78);
          iVar3 = *param_3;
          iVar6 = iVar6 + 1;
          *(undefined1 *)((int)param_3 + iVar3 * 0x78 + 0x28e) = 0;
          *(undefined1 *)((int)param_3 + iVar3 * 0x78 + 0x28f) = 0;
          *piVar7 = iVar4;
          piVar7 = piVar7 + 1;
          *param_3 = *param_3 + 1;
        }
        iVar5 = iVar5 + 1;
        psVar8 = psVar8 + 1;
      } while (iVar5 < *(short *)(param_1 + 0x2750));
    }
    if (param_3 == (int *)0x0) {
      FUN_00023aac(5,3,L"%S  line %d  pList==NULL //   nAddCount = %d",
                   "CFileMgr::getListValidSubFolder");
    }
    else {
      FUN_00023aac(5,3,L"%S  line %d  pList->nDataSize = %d  //   nAddCount = %d",
                   "CFileMgr::getListValidSubFolder");
    }
  }
  return iVar6;
}



/* 00015a94 FUN_00015a94 */

/* Boundary evidence: original MIPS .pdata 00015a94..00015af7. Semantic name remains unreviewed. */

undefined4 FUN_00015a94(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x38) + 0x21c) == 2) {
    *(undefined2 *)(*(short *)(param_1 + 0x2750) * 2 + param_1 + 0x40) = 0;
    *(short *)(param_1 + 0x2750) = *(short *)(param_1 + 0x2750) + 1;
  }
  DAT_0002fea4 = 0;
  FUN_00014390(param_1,0,0,0);
  return 1;
}



/* 00015af8 FUN_00015af8 */

/* Boundary evidence: original MIPS .pdata 00015af8..00015b43. Semantic name remains unreviewed. */

undefined4 * FUN_00015af8(undefined4 *param_1,uint param_2)

{
  FUN_00014cbc(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015b44 FUN_00015b44 */

/* Boundary evidence: original MIPS .pdata 00015b44..00015b7b. Semantic name remains unreviewed. */

undefined4 *
FUN_00015b44(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001640c(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_FUN_00027bfc;
  return param_1;
}



/* 00015b7c FUN_00015b7c */

/* Boundary evidence: original MIPS .pdata 00015b7c..00015b9f. Semantic name remains unreviewed. */

void FUN_00015b7c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027bfc;
  FUN_00016474(param_1);
  return;
}



/* 00015ba0 FUN_00015ba0 */

/* Boundary evidence: original MIPS .pdata 00015ba0..00015bff. Semantic name remains unreviewed. */

int FUN_00015ba0(int *param_1,wchar_t *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_000164c0((int)param_1,param_2);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 4))(param_1,param_3);
  }
  return iVar1;
}



/* 00015c00 FUN_00015c00 */

/* Boundary evidence: original MIPS .pdata 00015c00..00015df3. Semantic name remains unreviewed. */

void FUN_00015c00(int param_1,wchar_t *param_2)

{
  bool bVar1;
  char *pcVar2;
  size_t sVar3;
  int cchWideChar;
  wchar_t *pwVar4;
  undefined3 extraout_var;
  wchar_t awStack_540 [259];
  undefined2 local_33a;
  int local_334;
  char local_330;
  undefined1 auStack_32f [261];
  short sStack_22a;
  WCHAR local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_0002f960;
  if (*(int *)(param_1 + 8) != 0) {
    local_228 = L'\0';
    memset(auStack_226,0,0x206);
    local_330 = '\0';
    memset(auStack_32f,0,0x103);
    pcVar2 = FUN_00015e4c(param_1,&local_330,0x104);
    while (pcVar2 != (char *)0x0) {
      memset(&local_228,0,0x208);
      sVar3 = strlen(&local_330);
      cchWideChar = MultiByteToWideChar(0xfde9,8,&local_330,sVar3,(LPWSTR)0x0,0);
      if (cchWideChar != 0) {
        sVar3 = strlen(&local_330);
        MultiByteToWideChar(0xfde9,8,&local_330,sVar3,&local_228,cchWideChar);
        if (((&sStack_22a)[cchWideChar] == 10) && (cchWideChar < 0x104)) {
          (&sStack_22a)[cchWideChar] = 0;
        }
        sVar3 = wcslen(&local_228);
        if ((sVar3 != 0) && (local_228 != L'#')) {
          pwVar4 = FUN_000161b4(param_1,&local_228,param_2);
          FUN_0001271c(awStack_540,0x104,pwVar4);
          local_33a = 0;
          local_334 = FUN_00016340(param_1,awStack_540);
          bVar1 = FUN_00016150(param_1,awStack_540);
          if ((CONCAT31(extraout_var,bVar1) != 0) && ((local_334 == 1 || (local_334 == 2)))) {
            FUN_00016104(param_1,awStack_540);
          }
        }
        memset(&local_330,0,0x104);
      }
      pcVar2 = FUN_00015e4c(param_1,&local_330,0x104);
    }
  }
  FUN_00025510(local_20);
  return;
}



/* 00015df4 FUN_00015df4 */

/* Boundary evidence: original MIPS .pdata 00015df4..00015e4b. Semantic name remains unreviewed. */

undefined4 * FUN_00015df4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027bfc;
  FUN_00016474(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015e4c FUN_00015e4c */

/* Boundary evidence: original MIPS .pdata 00015e4c..00015f2f. Semantic name remains unreviewed. */

char * FUN_00015e4c(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  char *pcVar2;
  
  if ((*(int *)(param_1 + 8) == 0) || (param_2 == (char *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = fgets(param_2,param_3,*(FILE **)(param_1 + 4));
    param_2[param_3 + -1] = '\0';
    sVar1 = strlen(param_2);
    if (0 < (int)sVar1) {
      if (((param_2[sVar1 - 1] == '\n') || (param_2[sVar1 - 1] == '\r')) && ((int)sVar1 < 0x104)) {
        param_2[sVar1 - 1] = '\0';
      }
    }
    if (1 < (int)sVar1) {
      if (((param_2[sVar1 - 2] == '\n') || (param_2[sVar1 - 2] == '\r')) && ((int)sVar1 < 0x104)) {
        param_2[sVar1 - 2] = '\0';
      }
    }
  }
  return pcVar2;
}



/* 00015f30 FUN_00015f30 */

/* Boundary evidence: original MIPS .pdata 00015f30..0001608b. Semantic name remains unreviewed. */

undefined4 FUN_00015f30(int param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  DWORD local_30 [2];
  char local_28;
  char local_27;
  char local_26;
  uint local_1c;
  
  local_1c = DAT_0002f960;
  local_28 = '\0';
  memset(&local_27,0,9);
  local_30[0] = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  ReadFile(hFile,&local_28,3,local_30,(LPOVERLAPPED)0x0);
  if (((local_28 == -0x11) && (local_27 == -0x45)) && (local_26 == -0x41)) {
    *(undefined4 *)(param_1 + 0x14) = 3;
  }
  else if ((local_28 == -1) && (local_27 == -2)) {
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  else if ((local_28 == -2) && (local_27 == -1)) {
    *(undefined4 *)(param_1 + 0x14) = 2;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (hFile != (HANDLE)0x0) {
    CloseHandle(hFile);
  }
  FUN_00025510(local_1c);
  return *(undefined4 *)(param_1 + 0x14);
}



/* 0001608c FUN_0001608c */

/* Boundary evidence: original MIPS .pdata 0001608c..000160cf. Semantic name remains unreviewed. */

void FUN_0001608c(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    if (*(FILE **)(param_1 + 4) != (FILE *)0x0) {
      fclose(*(FILE **)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



/* 000160d0 FUN_000160d0 */

int FUN_000160d0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0xc)) {
    iVar1 = param_2 * 0x210 + *(int *)(param_1 + 0x10);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00016104 FUN_00016104 */

/* Boundary evidence: original MIPS .pdata 00016104..0001614f. Semantic name remains unreviewed. */

void FUN_00016104(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = iVar1 + 1;
  if (iVar2 < 1000) {
    *(int *)(param_1 + 0xc) = iVar2;
    memcpy((void *)(iVar1 * 0x210 + *(int *)(param_1 + 0x10)),param_2,0x210);
  }
  return;
}



/* 00016150 FUN_00016150 */

/* Boundary evidence: original MIPS .pdata 00016150..0001618b. Semantic name remains unreviewed. */

bool FUN_00016150(undefined4 param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(param_2);
  return DVar1 != 0x10;
}



/* 0001618c FUN_0001618c */

/* Boundary evidence: original MIPS .pdata 0001618c..000161b3. Semantic name remains unreviewed. */

uint FUN_0001618c(undefined4 param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(param_2);
  return DVar1 & 2;
}



/* 000161b4 FUN_000161b4 */

/* Boundary evidence: original MIPS .pdata 000161b4..0001633f. Semantic name remains unreviewed. */

wchar_t * FUN_000161b4(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  short sVar2;
  size_t sVar3;
  wchar_t *_Count;
  
  memset(&DAT_0002fefc,0,0x208);
  if (param_2 == (wchar_t *)0x0) {
    param_2 = (wchar_t *)0x0;
  }
  else {
    sVar3 = wcslen(param_2);
    if ((0 < (int)sVar3) && (sVar3 = wcslen(param_2), 2 < sVar3)) {
      wVar1 = param_2[1];
      if (*param_2 == L'\\') {
        if ((wVar1 == L'M') || (wVar1 == L'm')) {
          if (param_2[2] == L'D') {
            return param_2;
          }
          if (param_2[2] == L'd') {
            return param_2;
          }
        }
        param_3 = L"MD";
        _Count = L"\\%s%s";
      }
      else if ((wVar1 == L':') && (param_2[2] == L'\\')) {
        param_3 = L"MD";
        _Count = L"\\%s\\%s";
      }
      else {
        if (param_3 == (wchar_t *)0x0) {
          return param_2;
        }
        if (*param_3 == L'\\') {
          _Count = L"%s\\%s";
        }
        else {
          _Count = L"\\%s\\%s";
        }
      }
      swprintf((wchar_t *)&DAT_0002fefc,(size_t)_Count,param_3,param_2);
      sVar3 = wcslen((wchar_t *)&DAT_0002fefc);
      sVar2 = *(short *)((int)&DAT_0002fef8 + sVar3 * 2 + 2);
      if (((sVar2 == 0xd) || (sVar2 == 10)) && ((int)sVar3 < 0x104)) {
        *(undefined2 *)((int)&DAT_0002fef8 + sVar3 * 2 + 2) = 0;
      }
      param_2 = (wchar_t *)&DAT_0002fefc;
    }
  }
  return param_2;
}



/* 00016340 FUN_00016340 */

/* Boundary evidence: original MIPS .pdata 00016340..0001640b. Semantic name remains unreviewed. */

undefined4 FUN_00016340(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t local_20;
  undefined1 auStack_1e [14];
  uint local_10;
  
  local_10 = DAT_0002f960;
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    FUN_00025510(DAT_0002f960);
    uVar3 = 0;
  }
  else {
    local_20 = L'\0';
    memset(auStack_1e,0,0xe);
    sVar1 = wcslen(param_2);
    wcscpy_s(&local_20,7,param_2 + (sVar1 - 4));
    iVar2 = _wcsicmp(&local_20,L".MP3");
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      iVar2 = _wcsicmp(&local_20,L".WMA");
      uVar3 = 2;
      if (iVar2 != 0) {
        uVar3 = 0;
      }
    }
    FUN_00025510(local_10);
  }
  return uVar3;
}



/* 0001640c FUN_0001640c */

/* Boundary evidence: original MIPS .pdata 0001640c..00016473. Semantic name remains unreviewed. */

undefined4 *
FUN_0001640c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *_Dst;
  
  *param_1 = &PTR_FUN_00027c10;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 4;
  _Dst = (void *)FUN_00012844(0x80e80,param_2,param_3,param_4);
  param_1[4] = _Dst;
  param_1[3] = 0;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,1000);
  }
  return param_1;
}



/* 00016474 FUN_00016474 */

/* Boundary evidence: original MIPS .pdata 00016474..000164bf. Semantic name remains unreviewed. */

void FUN_00016474(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027c10;
  FUN_0001608c((int)param_1);
  param_1[3] = 0;
  if ((void *)param_1[4] != (void *)0x0) {
    memset((void *)param_1[4],0,1000);
  }
  return;
}



/* 000164c0 FUN_000164c0 */

/* Boundary evidence: original MIPS .pdata 000164c0..0001653f. Semantic name remains unreviewed. */

undefined4 FUN_000164c0(int param_1,wchar_t *param_2)

{
  FILE *pFVar1;
  
  FUN_0001608c(param_1);
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    memset(*(void **)(param_1 + 0x10),0,1000);
  }
  pFVar1 = _wfopen(param_2,L"rt");
  *(FILE **)(param_1 + 4) = pFVar1;
  *(uint *)(param_1 + 8) = (uint)(pFVar1 != (FILE *)0x0);
  FUN_00015f30(param_1,param_2);
  return *(undefined4 *)(param_1 + 8);
}



/* 00016540 FUN_00016540 */

/* Boundary evidence: original MIPS .pdata 00016540..0001658b. Semantic name remains unreviewed. */

undefined4 * FUN_00016540(undefined4 *param_1,uint param_2)

{
  FUN_00016474(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001658c FUN_0001658c */

/* Boundary evidence: original MIPS .pdata 0001658c..000165c3. Semantic name remains unreviewed. */

undefined4 *
FUN_0001658c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001640c(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_FUN_00027c20;
  return param_1;
}



/* 000165c4 FUN_000165c4 */

/* Boundary evidence: original MIPS .pdata 000165c4..000165e7. Semantic name remains unreviewed. */

void FUN_000165c4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027c20;
  FUN_00016474(param_1);
  return;
}



/* 000165e8 FUN_000165e8 */

/* Boundary evidence: original MIPS .pdata 000165e8..0001685b. Semantic name remains unreviewed. */

void FUN_000165e8(int param_1,wchar_t *param_2)

{
  bool bVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *pwVar5;
  undefined3 extraout_var;
  uint uVar6;
  WCHAR *pWVar7;
  wchar_t awStack_750 [259];
  undefined2 local_54a;
  int local_544;
  char local_540;
  undefined1 auStack_53f [261];
  short sStack_43a;
  WCHAR local_438;
  undefined1 auStack_436 [518];
  wchar_t local_230;
  undefined1 auStack_22e [518];
  uint local_28;
  
  local_28 = DAT_0002f960;
  if (*(int *)(param_1 + 8) != 0) {
    local_540 = '\0';
    memset(auStack_53f,0,0x103);
    local_438 = L'\0';
    memset(auStack_436,0,0x206);
    pcVar2 = FUN_00015e4c(param_1,&local_540,0x104);
    while (pcVar2 != (char *)0x0) {
      memset(&local_438,0,0x208);
      sVar3 = strlen(&local_540);
      iVar4 = MultiByteToWideChar(0xfde9,8,&local_540,sVar3,(LPWSTR)0x0,0);
      if (iVar4 != 0) {
        sVar3 = strlen(&local_540);
        MultiByteToWideChar(0xfde9,8,&local_540,sVar3,&local_438,iVar4);
        if (((&sStack_43a)[iVar4] == 10) && (iVar4 < 0x104)) {
          (&sStack_43a)[iVar4] = 0;
        }
        iVar4 = _wcsnicmp(&local_438,L"File",4);
        if (iVar4 == 0) {
          uVar6 = 0;
          sVar3 = wcslen(&local_438);
          if (sVar3 != 0) {
            pWVar7 = &local_438;
            do {
              uVar6 = uVar6 + 1;
              if (*pWVar7 == L'=') {
                if (4 < (int)uVar6) {
                  local_230 = L'\0';
                  memset(auStack_22e,0,0x206);
                  FUN_0001271c(&local_230,0x104,(short *)(auStack_436 + uVar6 * 2 + -2));
                  pwVar5 = FUN_000161b4(param_1,&local_230,param_2);
                  FUN_0001271c(awStack_750,0x104,pwVar5);
                  local_54a = 0;
                  local_544 = FUN_00016340(param_1,awStack_750);
                  bVar1 = FUN_00016150(param_1,awStack_750);
                  if ((CONCAT31(extraout_var,bVar1) != 0) && ((local_544 == 1 || (local_544 == 2))))
                  {
                    FUN_00016104(param_1,awStack_750);
                  }
                }
                break;
              }
              pWVar7 = pWVar7 + 1;
              sVar3 = wcslen(&local_438);
            } while (uVar6 < sVar3);
          }
        }
      }
      pcVar2 = FUN_00015e4c(param_1,&local_540,0x104);
    }
  }
  FUN_00025510(local_28);
  return;
}



/* 0001685c FUN_0001685c */

/* Boundary evidence: original MIPS .pdata 0001685c..000168b3. Semantic name remains unreviewed. */

undefined4 * FUN_0001685c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027c20;
  FUN_00016474(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000168b4 FUN_000168b4 */

/* Boundary evidence: original MIPS .pdata 000168b4..000168eb. Semantic name remains unreviewed. */

undefined4 *
FUN_000168b4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001640c(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_FUN_00027c34;
  return param_1;
}



/* 000168ec FUN_000168ec */

/* Boundary evidence: original MIPS .pdata 000168ec..0001690f. Semantic name remains unreviewed. */

void FUN_000168ec(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027c34;
  FUN_00016474(param_1);
  return;
}



/* 00016910 FUN_00016910 */

/* Boundary evidence: original MIPS .pdata 00016910..00016c7f. Semantic name remains unreviewed. */

void FUN_00016910(int param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  char *pcVar4;
  size_t sVar5;
  int iVar6;
  wchar_t *pwVar7;
  undefined3 extraout_var;
  uint uVar8;
  int iVar9;
  int iVar10;
  wchar_t awStack_758 [259];
  undefined2 local_552;
  int local_54c;
  char local_548;
  undefined1 auStack_547 [263];
  WCHAR local_440;
  undefined1 auStack_43e [518];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_0002f960;
  if (*(int *)(param_1 + 8) != 0) {
    local_548 = '\0';
    memset(auStack_547,0,0x103);
    local_440 = L'\0';
    memset(auStack_43e,0,0x206);
    pcVar4 = FUN_00015e4c(param_1,&local_548,0x104);
    while (pcVar4 != (char *)0x0) {
      memset(&local_440,0,0x208);
      sVar5 = strlen(&local_548);
      iVar6 = MultiByteToWideChar(0xfde9,8,&local_548,sVar5,(LPWSTR)0x0,0);
      if (iVar6 != 0) {
        sVar5 = strlen(&local_548);
        MultiByteToWideChar(0xfde9,8,&local_548,sVar5,&local_440,iVar6);
        sVar5 = wcslen(&local_440);
        iVar9 = -1;
        bVar3 = false;
        bVar2 = false;
        iVar10 = 0;
        iVar6 = -1;
        if (0 < (int)sVar5) {
          pwVar7 = &local_440;
          do {
            wVar1 = *pwVar7;
            if (bVar3) {
              if (wVar1 == L'=') {
                bVar2 = true;
              }
              if ((bVar2) && (wVar1 == L'\"')) {
                iVar6 = iVar10;
                if (-1 < iVar9) break;
                iVar9 = iVar10 + 1;
              }
            }
            else if ((wVar1 == L'<') && (iVar6 = _wcsnicmp(pwVar7,L"<media src",10), iVar6 == 0)) {
              bVar3 = true;
            }
            iVar10 = iVar10 + 1;
            pwVar7 = pwVar7 + 1;
            iVar6 = -1;
          } while (iVar10 < (int)sVar5);
        }
        local_238 = L'\0';
        memset(auStack_236,0,0x206);
        if (((((bVar3) && (bVar2)) && (-1 < iVar9)) && ((-1 < iVar6 && (iVar9 < 0x104)))) &&
           ((iVar6 < 0x104 && (-1 < iVar6 - iVar9)))) {
          wcsncpy(&local_238,(wchar_t *)(auStack_43e + iVar9 * 2 + -2),iVar6 - iVar9);
          pwVar7 = FUN_000161b4(param_1,&local_238,param_2);
          wcsncpy(awStack_758,pwVar7,0x103);
          pwVar7 = awStack_758;
          while ((pwVar7 = wcsstr(pwVar7,L"&apos;"), pwVar7 != (wchar_t *)0x0 &&
                 ((int)((int)pwVar7 - (int)awStack_758 & 0xfffffffeU) < 0x208))) {
            swprintf(pwVar7,0x27c64,pwVar7 + 6);
          }
          local_552 = 0;
          local_54c = FUN_00016340(param_1,awStack_758);
          bVar3 = FUN_00016150(param_1,awStack_758);
          if (((CONCAT31(extraout_var,bVar3) != 0) &&
              (uVar8 = FUN_0001618c(param_1,awStack_758), uVar8 == 0)) &&
             ((local_54c == 1 || (local_54c == 2)))) {
            FUN_00016104(param_1,awStack_758);
          }
        }
      }
      pcVar4 = FUN_00015e4c(param_1,&local_548,0x104);
    }
  }
  FUN_00025510(local_30);
  return;
}



/* 00016c80 FUN_00016c80 */

/* Boundary evidence: original MIPS .pdata 00016c80..00016cd7. Semantic name remains unreviewed. */

undefined4 * FUN_00016c80(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027c34;
  FUN_00016474(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016cd8 FUN_00016cd8 */

undefined4 FUN_00016cd8(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* 00016ce8 FUN_00016ce8 */

/* Boundary evidence: original MIPS .pdata 00016ce8..00016e1f. Semantic name remains unreviewed. */

void FUN_00016ce8(int param_1,int param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  short sVar3;
  short sVar4;
  size_t sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  sVar7 = 0;
  sVar8 = 0;
  bVar2 = false;
  if (param_2 < 0x2e4) {
    sVar5 = wcslen(param_3);
    sVar6 = 0;
    sVar3 = 0;
    sVar4 = 0;
    if (0 < (int)sVar5) {
      do {
        sVar8 = sVar4;
        sVar7 = sVar3;
        wVar1 = *param_3;
        if (wVar1 == L',') {
          bVar2 = true;
        }
        else {
          if (((ushort)wVar1 < 0x30) || (0x39 < (ushort)wVar1)) {
            if (((ushort)wVar1 < 0x41) || (0x5a < (ushort)wVar1)) {
              if ((0x60 < (ushort)wVar1) && ((ushort)wVar1 < 0x7b)) {
                sVar6 = wVar1 + L'ﾩ';
              }
            }
            else {
              sVar6 = wVar1 + L'￉';
            }
          }
          else {
            sVar6 = wVar1 + L'￐';
          }
          if (bVar2) {
            sVar7 = sVar7 * 0x10 + sVar6;
          }
          else {
            sVar8 = sVar8 * 0x10 + sVar6;
          }
        }
        param_3 = param_3 + 1;
        sVar5 = sVar5 - 1;
        sVar3 = sVar7;
        sVar4 = sVar8;
      } while (sVar5 != 0);
    }
    *(short *)((param_2 + 3) * 4 + param_1) = sVar7;
    *(short *)(param_2 * 4 + param_1 + 0xe) = sVar8;
  }
  return;
}



/* 00016e20 FUN_00016e20 */

int FUN_00016e20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = *(int *)(param_1 + 8);
    iVar4 = 0;
    if (-1 < iVar3) {
      do {
        iVar1 = iVar3 + iVar4;
        if (iVar1 < 0) {
          iVar1 = iVar1 + 1;
        }
        iVar1 = iVar1 >> 1;
        iVar2 = (int)*(short *)(iVar1 * 4 + param_1 + 0xe);
        if (iVar2 < param_2) {
          iVar4 = iVar1 + 1;
        }
        else {
          if (iVar2 <= param_2) {
            return (int)*(short *)((iVar1 + 3) * 4 + param_1);
          }
          iVar3 = iVar1 + -1;
        }
      } while (iVar4 <= iVar3);
    }
  }
  return param_2;
}



/* 00016eb0 FUN_00016eb0 */

/* Boundary evidence: original MIPS .pdata 00016eb0..00017053. Semantic name remains unreviewed. */

int FUN_00016eb0(int param_1,wchar_t *param_2)

{
  short sVar1;
  FILE *_File;
  wchar_t *pwVar2;
  size_t sVar3;
  int iVar4;
  short sStack_ea;
  wchar_t local_e8;
  undefined1 auStack_e6 [198];
  uint local_20;
  
  local_20 = DAT_0002f960;
  _File = _wfopen(param_2,L"rt");
  if (_File == (FILE *)0x0) {
    FUN_00025510(local_20);
    iVar4 = 0;
  }
  else {
    local_e8 = L'\0';
    iVar4 = 0;
    memset(auStack_e6,0,0xc6);
    pwVar2 = fgetws(&local_e8,100,_File);
    while ((pwVar2 != (wchar_t *)0x0 && (iVar4 < 0x2e4))) {
      sVar3 = wcslen(&local_e8);
      if (-1 < (int)sVar3) {
        if ((((&sStack_ea)[sVar3] == 10) || ((&sStack_ea)[sVar3] == 0xd)) && ((int)sVar3 < 100)) {
          (&sStack_ea)[sVar3] = 0;
        }
        if (1 < (int)sVar3) {
          sVar1 = *(short *)(auStack_e6 + (sVar3 - 2) * 2 + -2);
          if (((sVar1 == 10) || (sVar1 == 0xd)) && ((int)sVar3 < 100)) {
            *(short *)(auStack_e6 + (sVar3 - 2) * 2 + -2) = 0;
          }
        }
        FUN_00016ce8(param_1,iVar4,&local_e8);
        iVar4 = iVar4 + 1;
        memset(&local_e8,0,100);
      }
      pwVar2 = fgetws(&local_e8,100,_File);
    }
    fclose(_File);
    *(int *)(param_1 + 8) = iVar4;
    *(undefined4 *)(param_1 + 4) = 1;
    FUN_00025510(local_20);
  }
  return iVar4;
}



/* 00017054 FUN_00017054 */

/* Boundary evidence: original MIPS .pdata 00017054..0001709b. Semantic name remains unreviewed. */

undefined4 * FUN_00017054(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002ac08;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_00016eb0((int)param_1,L"\\storage Card\\system\\data\\LatinSortData.txt");
  return param_1;
}



/* 0001709c FUN_0001709c */

/* Boundary evidence: original MIPS .pdata 0001709c..0001711b. Semantic name remains unreviewed. */

void FUN_0001709c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027cc4;
  if (DAT_00030104 != (undefined4 *)0x0) {
    (**(code **)*DAT_00030104)(DAT_00030104,1);
    DAT_00030104 = (undefined4 *)0x0;
  }
  FUN_000209d0(param_1 + 1);
  return;
}



/* 0001711c Unwind@0001711c */

/* Boundary evidence: original MIPS .pdata 0001711c..0001714f. Semantic name remains unreviewed. */

void Unwind_0001711c(void)

{
  int *in_v0;
  
  FUN_000209d0((undefined4 *)(*in_v0 + 4));
  return;
}



/* 00017150 FUN_00017150 */

/* Boundary evidence: original MIPS .pdata 00017150..000171d7. Semantic name remains unreviewed. */

undefined4 * FUN_00017150(void)

{
  undefined4 *puVar1;
  
  if (DAT_00030104 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0xba0);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00030104 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_00027cc4;
      FUN_00017054(puVar1 + 1);
      DAT_00030104 = puVar1;
    }
  }
  return DAT_00030104;
}



/* 000171d8 Unwind@000171d8 */

/* Boundary evidence: original MIPS .pdata 000171d8..00017207. Semantic name remains unreviewed. */

void Unwind_000171d8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00017208 FUN_00017208 */

undefined4 FUN_00017208(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*param_2 != 0) {
    iVar2 = 0;
    do {
      if (*(int *)(iVar2 + param_3) == 0) break;
      if (*(int *)(iVar2 + (int)param_2) != *(int *)(iVar2 + param_3)) {
        if ((uint)param_2[iVar3] <= *(uint *)(iVar3 * 4 + param_3)) {
          return 0xffffffff;
        }
        goto LAB_000172b4;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar3 * 4;
    } while (param_2[iVar3] != 0);
  }
  if ((param_2[iVar3] == 0) && (*(int *)(iVar3 * 4 + param_3) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
    if (*(int *)(iVar3 * 4 + param_3) == 0) {
LAB_000172b4:
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 000172c0 FUN_000172c0 */

/* Boundary evidence: original MIPS .pdata 000172c0..0001738b. Semantic name remains unreviewed. */

void FUN_000172c0(int param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_2 != (ushort *)0x0) && (param_3 != (uint *)0x0)) {
    uVar1 = *param_2;
    for (iVar4 = 0; (uVar1 != 0 && (iVar4 < 0x104)); iVar4 = iVar4 + 1) {
      iVar2 = FUN_00016cd8(param_1 + 4);
      if (iVar2 == 0) {
        *param_3 = (uint)*param_2;
      }
      else {
        uVar3 = FUN_00016e20(param_1 + 4,(int)(short)*param_2);
        *param_3 = uVar3;
      }
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_3 = *param_3 << 0x10 | (uint)uVar1;
      uVar1 = *param_2;
      param_3 = param_3 + 1;
    }
  }
  return;
}



/* 0001738c FUN_0001738c */

/* Boundary evidence: original MIPS .pdata 0001738c..000173d7. Semantic name remains unreviewed. */

undefined4 * FUN_0001738c(undefined4 *param_1,uint param_2)

{
  FUN_0001709c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000173d8 FUN_000173d8 */

/* Boundary evidence: original MIPS .pdata 000173d8..00017467. Semantic name remains unreviewed. */

void FUN_000173d8(int param_1,ushort *param_2,ushort *param_3)

{
  uint local_830;
  undefined1 auStack_82c [1036];
  uint local_420;
  undefined1 auStack_41c [1036];
  
  local_420 = 0;
  memset(auStack_41c,0,0x40c);
  local_830 = 0;
  memset(auStack_82c,0,0x40c);
  FUN_000172c0(param_1,param_2,&local_420);
  FUN_000172c0(param_1,param_3,&local_830);
  FUN_00017208(param_1,(int *)&local_420,(int)&local_830);
  return;
}



/* 00017468 FUN_00017468 */

/* Boundary evidence: original MIPS .pdata 00017468..000174f7. Semantic name remains unreviewed. */

void * FUN_00017468(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xe44;
  uVar2 = 0;
  memset(param_1,0,0xe44);
  *(undefined4 *)((int)param_1 + 0xe44) = 0;
  iVar1 = FUN_00012844(0x800000,uVar2,uVar3,param_4);
  *(int *)((int)param_1 + 0xe44) = iVar1;
  if (iVar1 == 0) {
    FUN_00023aac(5,3,
                 L"**********[MgrUsb/CID3Tag] CExtMemUtil::getExtMemory(%d); ExtMemory Alloc failed*****"
                 ,0x800000);
  }
  else {
    FUN_00023aac(5,3,L"** [MgrUsb/CID3Tag] ExtMemory Alloc Successed  %s, %d **",L"CID3Tag::CID3Tag"
                );
  }
  return param_1;
}



/* 000174f8 FUN_000174f8 */

void FUN_000174f8(void)

{
  return;
}



/* 00017500 FUN_00017500 */

/* Boundary evidence: original MIPS .pdata 00017500..0001778f. Semantic name remains unreviewed. */

undefined4 FUN_00017500(undefined4 param_1,void *param_2,wchar_t *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  wchar_t *_Str;
  undefined4 auStack_a8 [2];
  char local_a0;
  char local_9f;
  char local_9e;
  undefined1 auStack_9d [29];
  undefined1 local_80;
  undefined1 auStack_7f [29];
  undefined1 local_62;
  undefined1 auStack_61 [29];
  undefined1 local_44;
  byte local_21;
  uint local_20;
  
  local_20 = DAT_0002f960;
  FUN_000209e0(auStack_a8);
  memcpy(&local_a0,param_2,0x80);
  if (((local_a0 == 'T') && (local_9f == 'A')) && (local_9e == 'G')) {
    local_80 = 0;
    local_62 = 0;
    local_44 = 0;
    if (((*(uint *)(param_3 + 0x720) & 1) == 0) || (sVar1 = wcslen(param_3 + 0x208), sVar1 == 0)) {
      memcpy(param_3 + 0x514,auStack_9d,0x1e);
      FUN_00024e04((int)auStack_a8,(char *)(param_3 + 0x514),param_3 + 0x208,0x1e);
      iVar2 = FUN_00024c44(auStack_a8,param_3 + 0x208,0x103);
      if (iVar2 != 0) {
        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 1;
      }
    }
    if (((*(uint *)(param_3 + 0x720) & 4) == 0) || (sVar1 = wcslen(param_3), sVar1 == 0)) {
      memcpy(param_3 + 0x410,auStack_7f,0x1e);
      FUN_00024e04((int)auStack_a8,(char *)(param_3 + 0x410),param_3,0x1e);
      iVar2 = FUN_00024c44(auStack_a8,param_3,0x81);
      if (iVar2 != 0) {
        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 4;
      }
    }
    if (((*(uint *)(param_3 + 0x720) & 2) == 0) || (sVar1 = wcslen(param_3 + 0x104), sVar1 == 0)) {
      memcpy(param_3 + 0x492,auStack_61,0x1e);
      FUN_00024e04((int)auStack_a8,(char *)(param_3 + 0x492),param_3 + 0x104,0x1e);
      iVar2 = FUN_00024c44(auStack_a8,param_3 + 0x104,0x81);
      if (iVar2 != 0) {
        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 2;
      }
    }
    if (((*(uint *)(param_3 + 0x720) & 0x10) == 0) || (sVar1 = wcslen(param_3 + 0x30c), sVar1 == 0))
    {
      uVar4 = (uint)local_21;
      if (0x94 < uVar4) {
        uVar4 = 0x94;
      }
      _Str = (wchar_t *)(&PTR_u_Blues_0002f1ec)[uVar4];
      sVar1 = wcslen(_Str);
      memcpy(param_3 + 0x30c,_Str,(sVar1 + 1) * 2);
      *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x10;
    }
    FUN_000209d0(auStack_a8);
    FUN_00025510(local_20);
    uVar3 = 1;
  }
  else {
    FUN_000209d0(auStack_a8);
    FUN_00025510(local_20);
    uVar3 = 0;
  }
  return uVar3;
}



/* 00017790 Unwind@00017790 */

/* Boundary evidence: original MIPS .pdata 00017790..000177bf. Semantic name remains unreviewed. */

void Unwind_00017790(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0xa8));
  return;
}



/* 000177c0 FUN_000177c0 */

int FUN_000177c0(undefined4 param_1,char *param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  if ((((((param_3 < 10) || (*param_2 != 'I')) || (param_2[1] != 'D')) ||
       ((param_2[2] != '3' || (param_2[3] == 0xff)))) ||
      ((param_2[4] == -1 || ((0x7f < (byte)param_2[6] || (0x7f < (byte)param_2[7])))))) ||
     ((0x7f < (byte)param_2[8] || (0x7f < (byte)param_2[9])))) {
    iVar3 = 0;
  }
  else {
    uVar2 = 0;
    iVar3 = 0;
    do {
      pbVar1 = (byte *)(param_2 + 6 + iVar3);
      iVar3 = iVar3 + 1;
      uVar2 = *pbVar1 & 0x7f | uVar2 << 7;
    } while (iVar3 < 4);
    iVar3 = uVar2 + 10;
    if ((3 < (byte)param_2[3]) && ((param_2[5] & 0x10U) != 0)) {
      iVar3 = uVar2 + 0x14;
    }
  }
  return iVar3;
}



/* 000178bc FUN_000178bc */

/* Boundary evidence: original MIPS .pdata 000178bc..000182ab. Semantic name remains unreviewed. */

undefined4 FUN_000178bc(uint *param_1,char *param_2,wchar_t *param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  size_t sVar8;
  uint uVar9;
  size_t _Size;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  uint uVar16;
  wchar_t *pwVar17;
  uint uVar18;
  byte *pbVar19;
  undefined4 uVar20;
  uint *local_48;
  byte *local_40;
  undefined4 auStack_30 [2];
  
  FUN_000209e0(auStack_30);
  uVar6 = FUN_000177c0(param_1,param_2,param_4);
  uVar20 = 1;
  if (uVar6 != 0) {
    bVar2 = param_2[3];
    bVar3 = param_2[5];
    if (((1 < bVar2) && (bVar2 < 5)) && (uVar6 <= param_4)) {
      pbVar19 = (byte *)(param_2 + 10);
      uVar6 = uVar6 - 10;
      if ((bVar2 < 4) && ((bVar3 & 0x80) != 0)) {
        pbVar7 = (byte *)__2_YAPAXI_Z(uVar6);
        if (pbVar7 == (byte *)0x0) {
          uVar20 = 0;
          goto LAB_00018268;
        }
        pbVar15 = pbVar19 + uVar6;
        pbVar13 = pbVar7;
        if (pbVar19 != pbVar15) {
          pbVar11 = (byte *)(param_2 + 0xb);
          pbVar10 = pbVar19;
          do {
            *pbVar13 = *pbVar10;
            if (((pbVar11 != pbVar15) && (*pbVar10 == 0xff)) && (*pbVar11 == 0)) {
              pbVar10 = pbVar10 + 1;
              pbVar11 = pbVar11 + 1;
            }
            pbVar10 = pbVar10 + 1;
            pbVar11 = pbVar11 + 1;
            pbVar13 = pbVar13 + 1;
          } while (pbVar10 != pbVar15);
        }
        uVar6 = (int)pbVar13 - (int)pbVar7;
        memcpy(pbVar19,pbVar7,uVar6);
        __3_YAXPAX_Z(pbVar7);
      }
      if (((bVar3 & 0x40) != 0) && (3 < uVar6)) {
        uVar12 = 0;
        iVar14 = 0;
        if (bVar2 < 4) {
          do {
            pbVar7 = pbVar19 + iVar14;
            iVar14 = iVar14 + 1;
            uVar12 = (uint)*pbVar7 | uVar12 << 8;
          } while (iVar14 < 4);
        }
        else {
          do {
            pbVar7 = pbVar19 + iVar14;
            iVar14 = iVar14 + 1;
            uVar12 = *pbVar7 & 0x7f | uVar12 << 7;
          } while (iVar14 < 4);
        }
        pbVar19 = pbVar19 + uVar12 + 4;
        uVar6 = (uVar6 - uVar12) - 4;
      }
      local_48 = param_1;
      if (uVar6 != 0) {
LAB_00017aa8:
        bVar3 = *pbVar19;
        if (bVar3 != 0) {
          local_40 = (byte *)0x0;
          bVar1 = false;
          bVar4 = false;
          uVar9 = 0;
          uVar12 = 0;
          uVar16 = 0;
          if (bVar2 == 2) {
            if (5 < uVar6) {
              uVar9 = ((pbVar19[2] | 0x2000) << 8 | (uint)pbVar19[1]) << 8 | (uint)bVar3;
              uVar12 = 0;
              iVar14 = 0;
              do {
                iVar5 = iVar14 + 3;
                iVar14 = iVar14 + 1;
                uVar12 = (uint)pbVar19[iVar5] | uVar12 << 8;
              } while (iVar14 < 3);
              local_48 = (uint *)&DAT_0002887c;
              if (uVar6 < uVar12) goto LAB_00017dd8;
              pbVar19 = pbVar19 + 6;
              uVar6 = uVar6 - 6;
              local_48 = (uint *)&DAT_0002887c;
            }
LAB_00017c30:
            pbVar7 = pbVar19 + uVar12;
            uVar6 = uVar6 - uVar12;
            if ((uVar9 != 0) && (uVar6 != 0)) {
              for (; *local_48 != 0; local_48 = local_48 + 2) {
                if (*local_48 == uVar9) {
                  pbVar13 = pbVar19;
                  pbVar15 = (byte *)0x0;
                  if (!bVar4) goto LAB_00017e88;
                  pbVar13 = (byte *)__2_YAPAXI_Z(uVar12);
                  pbVar15 = pbVar13;
                  pbVar10 = pbVar19;
                  if (pbVar13 != (byte *)0x0) goto joined_r0x00017e30;
                  break;
                }
              }
            }
            goto LAB_00018240;
          }
          if (bVar2 != 3) {
            if ((bVar2 == 4) && (9 < uVar6)) {
              uVar9 = CONCAT31(*(undefined3 *)(pbVar19 + 1),bVar3);
              uVar12 = 0;
              iVar14 = 0;
              do {
                iVar5 = iVar14 + 4;
                iVar14 = iVar14 + 1;
                uVar12 = (uint)pbVar19[iVar5] | uVar12 << 8;
              } while (iVar14 < 4);
              local_48 = &DAT_000288c4;
              if (uVar6 < uVar12) goto LAB_00017dd8;
              iVar14 = 0;
              do {
                bVar3 = pbVar19[iVar14 + 8];
                iVar14 = iVar14 + 1;
              } while (iVar14 < 2);
              pbVar7 = pbVar19 + 10;
              uVar18 = uVar6 - 10;
              if ((bVar3 & 0xd4) != 0) {
                uVar9 = 0;
              }
              if (((bVar3 & 0x40) != 0) && (uVar18 != 0)) {
                pbVar7 = pbVar19 + 0xb;
                uVar18 = uVar6 - 0xb;
              }
              if (((bVar3 & 1) != 0) && (3 < uVar18)) {
                uVar16 = 0;
                iVar14 = 0;
                do {
                  pbVar19 = pbVar7 + iVar14;
                  iVar14 = iVar14 + 1;
                  uVar16 = (uint)*pbVar19 | uVar16 << 8;
                } while (iVar14 < 4);
                pbVar7 = pbVar7 + 4;
                uVar18 = uVar18 - 4;
              }
              bVar1 = (bVar3 & 8) != 0;
              if ((bVar3 & 2) != 0) {
                bVar4 = true;
              }
LAB_00017c2c:
              local_48 = &DAT_000288c4;
              uVar6 = uVar18;
              pbVar19 = pbVar7;
            }
            goto LAB_00017c30;
          }
          if (uVar6 < 10) goto LAB_00017c30;
          uVar9 = CONCAT31(*(undefined3 *)(pbVar19 + 1),bVar3);
          uVar12 = 0;
          iVar14 = 0;
          do {
            iVar5 = iVar14 + 4;
            iVar14 = iVar14 + 1;
            uVar12 = (uint)pbVar19[iVar5] | uVar12 << 8;
          } while (iVar14 < 4);
          local_48 = &DAT_000288c4;
          if (uVar12 <= uVar6) {
            iVar14 = 0;
            do {
              bVar3 = pbVar19[iVar14 + 8];
              iVar14 = iVar14 + 1;
            } while (iVar14 < 2);
            pbVar7 = pbVar19 + 10;
            uVar18 = uVar6 - 10;
            if ((bVar3 & 0x5f) != 0) {
              uVar9 = 0;
            }
            if (((bVar3 & 0x80) != 0) && (3 < uVar18)) {
              bVar1 = true;
              uVar16 = 0;
              iVar14 = 0;
              do {
                pbVar13 = pbVar7 + iVar14;
                iVar14 = iVar14 + 1;
                uVar16 = (uint)*pbVar13 | uVar16 << 8;
              } while (iVar14 < 4);
              pbVar7 = pbVar19 + 0xe;
              uVar18 = uVar6 - 0xe;
            }
            if (((bVar3 & 0x20) != 0) && (uVar18 != 0)) {
              pbVar7 = pbVar7 + 1;
              uVar18 = uVar18 - 1;
            }
            goto LAB_00017c2c;
          }
LAB_00017dd8:
          pbVar7 = pbVar19 + 1;
          uVar6 = uVar6 - 1;
          goto LAB_0001825c;
        }
        goto LAB_00018264;
      }
    }
  }
  goto LAB_00018268;
joined_r0x00017e30:
  for (; pbVar19 != pbVar7; pbVar19 = pbVar19 + 1) {
    pbVar11 = pbVar10 + 1;
    *pbVar15 = *pbVar19;
    if (((pbVar11 != pbVar7) && (*pbVar19 == 0xff)) && (*pbVar11 == 0)) {
      pbVar19 = pbVar19 + 1;
      pbVar11 = pbVar10 + 2;
    }
    pbVar15 = pbVar15 + 1;
    pbVar10 = pbVar11;
  }
  uVar12 = (int)pbVar15 - (int)pbVar13;
  pbVar15 = pbVar13;
LAB_00017e88:
  if ((bVar1) && (0 < (int)uVar16)) {
    pbVar13 = (byte *)__2_YAPAXI_Z(uVar16);
    uVar12 = uVar16;
    local_40 = pbVar13;
  }
  uVar9 = local_48[1];
  if (uVar9 == 0x110) {
    if ((int)uVar12 < 2) goto LAB_00018218;
    if (0x104 < (int)uVar12) {
      uVar12 = 0x104;
    }
    memcpy(param_3 + 0x514,pbVar13 + 1,uVar12 - 1);
    pwVar17 = param_3 + 0x208;
    FUN_00024e04((int)auStack_30,(char *)(param_3 + 0x514),pwVar17,uVar12 - 1);
    iVar14 = FUN_00024c44(auStack_30,pwVar17,0x103);
    if ((iVar14 == 0) || (sVar8 = wcslen(pwVar17), sVar8 == 0)) goto LAB_00018218;
    uVar9 = *(uint *)(param_3 + 0x720) | 1;
  }
  else if (uVar9 == 0x111) {
    if (((int)uVar12 < 2) || (sVar8 = wcslen(param_3), sVar8 != 0)) goto LAB_00018218;
    if (0x104 < (int)uVar12) {
      uVar12 = 0x104;
    }
    memcpy(param_3 + 0x410,pbVar13 + 1,uVar12 - 1);
    FUN_00024e04((int)auStack_30,(char *)(param_3 + 0x410),param_3,uVar12 - 1);
    iVar14 = FUN_00024c44(auStack_30,param_3,0x81);
    if (iVar14 == 0) goto LAB_00018218;
    uVar9 = *(uint *)(param_3 + 0x720) | 4;
  }
  else if (uVar9 == 0x112) {
    if ((int)uVar12 < 2) goto LAB_00018218;
    if (0x104 < (int)uVar12) {
      uVar12 = 0x104;
    }
    memcpy(param_3 + 0x492,pbVar13 + 1,uVar12 - 1);
    pwVar17 = param_3 + 0x104;
    FUN_00024e04((int)auStack_30,(char *)(param_3 + 0x492),pwVar17,uVar12 - 1);
    iVar14 = FUN_00024c44(auStack_30,pwVar17,0x81);
    if ((iVar14 == 0) || (sVar8 = wcslen(pwVar17), sVar8 == 0)) goto LAB_00018218;
    uVar9 = *(uint *)(param_3 + 0x720) | 2;
  }
  else if (uVar9 == 0x114) {
    if ((int)uVar12 < 2) goto LAB_00018218;
    if (0x104 < (int)uVar12) {
      uVar12 = 0x104;
    }
    memcpy(param_3 + 0x596,pbVar13 + 1,uVar12 - 1);
    FUN_00024e04((int)auStack_30,(char *)(param_3 + 0x596),param_3 + 0x30c,uVar12 - 1);
    iVar14 = FUN_00024c44(auStack_30,param_3 + 0x30c,0x81);
    if (iVar14 == 0) goto LAB_00018218;
    uVar9 = *(uint *)(param_3 + 0x720) | 0x10;
  }
  else {
    if ((uVar9 != 0x11b) || ((int)uVar12 < 2)) goto LAB_00018218;
    pbVar19 = pbVar13 + 1;
    sVar8 = strlen((char *)pbVar19);
    iVar14 = strncmp("image",(char *)pbVar19,5);
    if (iVar14 != 0) {
      NKDbgPrintfW(L"==== Opss!!! COVER == iFrameLen %d =====\r\n",uVar12);
      goto LAB_00018218;
    }
    pbVar13 = pbVar13 + 7;
    iVar14 = _stricmp("jpg",(char *)pbVar13);
    if (iVar14 == 0) {
      uVar20 = 0x10;
LAB_00017fe4:
      *(undefined4 *)(param_3 + 0x618) = uVar20;
    }
    else {
      iVar14 = _stricmp("jpeg",(char *)pbVar13);
      if (iVar14 == 0) {
        uVar20 = 0x12;
        goto LAB_00017fe4;
      }
      iVar14 = _stricmp("png",(char *)pbVar13);
      if (iVar14 == 0) {
        uVar20 = 0x17;
        goto LAB_00017fe4;
      }
      iVar14 = _stricmp("bmp",(char *)pbVar13);
      if (iVar14 == 0) {
        uVar20 = 0x15;
        goto LAB_00017fe4;
      }
      iVar14 = _stricmp("gif",(char *)pbVar13);
      if (iVar14 == 0) {
        uVar20 = 0x16;
        goto LAB_00017fe4;
      }
    }
    _Size = (uVar12 - sVar8) - 3;
    *(size_t *)(param_3 + 0x61a) = _Size;
    if ((void *)param_1[0x391] != (void *)0x0) {
      memcpy((void *)param_1[0x391],pbVar19 + sVar8 + 3,_Size);
    }
    uVar9 = *(uint *)(param_3 + 0x720) | 8;
  }
  *(uint *)(param_3 + 0x720) = uVar9;
LAB_00018218:
  if (pbVar15 != (byte *)0x0) {
    __3_YAXPAX_Z(pbVar15);
  }
  if (local_40 != (byte *)0x0) {
    __3_YAXPAX_Z(local_40);
  }
LAB_00018240:
  if ((uVar6 < 10) && (uVar12 == 0)) goto LAB_00018264;
LAB_0001825c:
  pbVar19 = pbVar7;
  if (uVar6 == 0) goto LAB_00018264;
  goto LAB_00017aa8;
LAB_00018264:
  uVar20 = 1;
LAB_00018268:
  FUN_000209d0(auStack_30);
  return uVar20;
}



/* 000182ac Unwind@000182ac */

/* Boundary evidence: original MIPS .pdata 000182ac..000182db. Semantic name remains unreviewed. */

void Unwind_000182ac(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 000182dc FUN_000182dc */

/* Boundary evidence: original MIPS .pdata 000182dc..00018f53. Semantic name remains unreviewed. */

undefined4 FUN_000182dc(undefined4 param_1,LPCWSTR param_2,short *param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *_Buf2;
  size_t sVar7;
  uint uVar8;
  byte bVar9;
  undefined *_Buf2_00;
  byte local_298;
  DWORD local_294;
  undefined4 auStack_290 [2];
  ushort local_288;
  ushort local_286;
  ushort local_284;
  ushort local_282;
  ushort local_280;
  undefined *local_27c;
  undefined *local_278;
  uint local_274;
  undefined1 auStack_270 [16];
  int local_260;
  int local_25c;
  undefined1 auStack_258 [24];
  int local_240;
  undefined4 local_238;
  ushort local_234;
  ushort local_232;
  ushort local_230;
  uint local_228;
  int local_224;
  int local_220;
  wchar_t awStack_130 [128];
  uint local_30;
  
  local_30 = DAT_0002f960;
  FUN_000209e0(auStack_290);
  local_238 = local_238 & 0xffffff00;
  memset((void *)((int)&local_238 + 1),0,0x103);
  bVar9 = 0;
  local_294 = 0;
  local_298 = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    memset(param_3,0,0xe44);
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    SetFilePointer(hFile,0,(PLONG)0x0,0);
    BVar2 = ReadFile(hFile,&local_238,0x1e,&local_294,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
      if (hFile != (HANDLE)0x0) {
        CloseHandle(hFile);
      }
    }
    else {
      memcpy(auStack_258,&local_238,0x1e);
      if ((local_220 < 1) || (0x10 < local_220)) {
        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
        if (hFile != (HANDLE)0x0) {
          CloseHandle(hFile);
        }
      }
      else {
        iVar3 = memcmp(auStack_258,&DAT_0002884c,0x10);
        if ((iVar3 == 0) && (iVar3 = 0, 0 < local_220)) {
          _Buf2 = &DAT_0002885c;
          _Buf2_00 = &DAT_0002886c;
          local_27c = &DAT_0002885c;
          local_278 = &DAT_0002886c;
          do {
            memset(&local_238,0,0x80);
            BVar2 = ReadFile(hFile,&local_238,0x18,&local_294,(LPOVERLAPPED)0x0);
            if (BVar2 == 0) {
              *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
              if (hFile != (HANDLE)0x0) {
                CloseHandle(hFile);
              }
              goto LAB_00018f08;
            }
            memcpy(auStack_270,&local_238,0x18);
            if ((local_224 < 0) ||
               ((((local_224 == 0 && (local_228 < 0x19)) || (0 < local_224)) ||
                ((local_224 == 0 && (DVar1 <= local_228)))))) {
              *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
              if (hFile != (HANDLE)0x0) {
                CloseHandle(hFile);
              }
              goto LAB_00018f08;
            }
            iVar6 = local_228 - 0x18;
            local_25c = local_224 - (uint)(local_228 < 0x18);
            local_260 = iVar6;
            iVar4 = memcmp(auStack_270,_Buf2_00,0x10);
            if (iVar4 == 0) {
              BVar2 = ReadFile(hFile,&local_238,10,&local_294,(LPOVERLAPPED)0x0);
              if (BVar2 == 0) {
                *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00018f08;
              }
              memcpy(&local_288,&local_238,10);
              uVar5 = local_238 & 0xffff;
              if (((DVar1 < uVar5) || (DVar1 < local_238 >> 0x10)) ||
                 ((DVar1 < local_232 || ((DVar1 < local_230 || (DVar1 < local_234)))))) {
                *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00018f08;
              }
              sVar7 = (size_t)local_288;
              if (uVar5 < 0x81) {
                BVar2 = ReadFile(hFile,&local_238,uVar5,&local_294,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
              }
              else {
                BVar2 = ReadFile(hFile,&local_238,0x80,&local_294,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
                SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
              }
              if (0x3c < sVar7) {
                sVar7 = 0x3c;
                local_288 = 0x3c;
              }
              memcpy(param_3 + 0x208,&local_238,sVar7);
              param_3[0x226] = 0;
              iVar4 = FUN_00024c44(auStack_290,param_3 + 0x208,0x103);
              if (iVar4 != 0) {
                *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 1;
              }
              sVar7 = (size_t)local_286;
              if (sVar7 < 0x81) {
                BVar2 = ReadFile(hFile,&local_238,sVar7,&local_294,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
              }
              else {
                BVar2 = ReadFile(hFile,&local_238,0x80,&local_294,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
                SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
              }
              if (0x3c < sVar7) {
                sVar7 = 0x3c;
                local_286 = 0x3c;
              }
              memcpy(param_3,&local_238,sVar7);
              param_3[0x1e] = 0;
              iVar4 = FUN_00024c44(auStack_290,param_3,0x103);
              if (iVar4 != 0) {
                *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 4;
              }
              SetFilePointer(hFile,(uint)local_284 + (uint)local_280 + (uint)local_282,(PLONG)0x0,1)
              ;
              local_298 = bVar9 | 1;
              _Buf2 = local_27c;
              bVar9 = local_298;
              if (local_298 == 3) {
                *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00018f08;
              }
            }
            else {
              iVar4 = memcmp(auStack_270,_Buf2,0x10);
              if (iVar4 == 0) {
                BVar2 = ReadFile(hFile,&local_238,2,&local_294,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
                uVar5 = local_238 & 0xffff;
                if (DVar1 < uVar5) {
                  *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00018f08;
                }
                iVar4 = 0;
                _Buf2_00 = local_278;
                bVar9 = local_298;
                if (uVar5 != 0) {
                  do {
                    BVar2 = ReadFile(hFile,&local_238,2,&local_294,(LPOVERLAPPED)0x0);
                    if (BVar2 == 0) {
                      *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                      if (hFile != (HANDLE)0x0) {
                        CloseHandle(hFile);
                      }
                      goto LAB_00018f08;
                    }
                    uVar8 = local_238 & 0xffff;
                    if (DVar1 < uVar8) {
                      *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                      if (hFile != (HANDLE)0x0) {
                        CloseHandle(hFile);
                      }
                      goto LAB_00018f08;
                    }
                    if (uVar8 < 0x65) {
                      BVar2 = ReadFile(hFile,&local_238,uVar8,&local_294,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                    }
                    else {
                      BVar2 = ReadFile(hFile,&local_238,100,&local_294,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                      SetFilePointer(hFile,uVar8 - 100,(PLONG)0x0,1);
                    }
                    memcpy(awStack_130,&local_238,uVar8);
                    iVar6 = _wcsicmp(awStack_130,L"WM/ALBUMTITLE");
                    if (iVar6 == 0) {
                      local_298 = local_298 | 2;
                      BVar2 = ReadFile(hFile,&local_238,4,&local_294,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                      uVar8 = (uint)local_238._2_2_;
                      local_274 = local_238;
                      if (DVar1 < uVar8) {
                        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                      if ((char)local_238 == '\0' && local_238._1_1_ == '\0') {
                        sVar7 = (size_t)local_238._2_2_;
                        if (uVar8 < 0x81) {
                          BVar2 = ReadFile(hFile,&local_238,uVar8,&local_294,(LPOVERLAPPED)0x0);
                          if (BVar2 == 0) {
                            *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                            if (hFile != (HANDLE)0x0) {
                              CloseHandle(hFile);
                            }
                            goto LAB_00018f08;
                          }
                        }
                        else {
                          BVar2 = ReadFile(hFile,&local_238,0x80,&local_294,(LPOVERLAPPED)0x0);
                          if (BVar2 == 0) {
                            *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                            if (hFile != (HANDLE)0x0) {
                              CloseHandle(hFile);
                            }
                            goto LAB_00018f08;
                          }
                          SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
                        }
                        if (0x3c < sVar7) {
                          sVar7 = 0x3c;
                        }
                        memcpy(param_3 + 0x104,&local_238,sVar7);
                        param_3[0x122] = 0;
                        iVar6 = FUN_00024c44(auStack_290,param_3 + 0x104,0x103);
                        if (iVar6 != 0) {
                          *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 2;
                        }
                      }
                      if (local_298 == 3) {
                        *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                    }
                    else {
                      BVar2 = ReadFile(hFile,&local_238,4,&local_294,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        if (hFile != (HANDLE)0x0) {
                          *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
                          CloseHandle(hFile);
                        }
                        goto LAB_00018f08;
                      }
                      SetFilePointer(hFile,local_238 >> 0x10,(PLONG)0x0,1);
                    }
                    iVar4 = iVar4 + 1;
                    _Buf2 = local_27c;
                    _Buf2_00 = local_278;
                    bVar9 = local_298;
                  } while (iVar4 < (int)uVar5);
                }
              }
              else {
                SetFilePointer(hFile,iVar6,&local_25c,1);
              }
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < local_240);
        }
        if (hFile != (HANDLE)0x0) {
          *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
          CloseHandle(hFile);
        }
      }
    }
  }
LAB_00018f08:
  FUN_000209d0(auStack_290);
  FUN_00025510(local_30);
  return 0;
}



/* 00018f54 Unwind@00018f54 */

/* Boundary evidence: original MIPS .pdata 00018f54..00018f83. Semantic name remains unreviewed. */

void Unwind_00018f54(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x290));
  return;
}



/* 00018f84 FUN_00018f84 */

/* Boundary evidence: original MIPS .pdata 00018f84..00019253. Semantic name remains unreviewed. */

undefined4 FUN_00018f84(uint *param_1,LPCWSTR param_2,wchar_t *param_3)

{
  HANDLE hFile;
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  char *_Dst;
  undefined4 uVar4;
  DWORD local_c8 [2];
  char acStack_c0 [16];
  undefined1 auStack_b0 [128];
  uint local_30;
  
  local_30 = DAT_0002f960;
  uVar4 = 0;
  hFile = CreateFileW(param_2,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0xa0,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) goto LAB_0001900c;
  _Dst = (char *)0x0;
  DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
  SetFilePointer(hFile,0,(PLONG)0x0,0);
  BVar2 = ReadFile(hFile,acStack_c0,10,local_c8,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
    if (hFile != (HANDLE)0x0) {
      CloseHandle(hFile);
    }
    goto LAB_0001900c;
  }
  uVar3 = FUN_000177c0(param_1,acStack_c0,10);
  if (((uVar3 == 0) || (DVar1 <= uVar3)) ||
     (_Dst = (char *)__2_YAPAXI_Z(uVar3), _Dst == (char *)0x0)) {
LAB_0001915c:
    SetFilePointer(hFile,-0x80,(PLONG)0x0,2);
    BVar2 = ReadFile(hFile,auStack_b0,0x80,local_c8,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      if (local_c8[0] == 0x80) {
        uVar4 = FUN_00017500(param_1,auStack_b0,param_3);
      }
      if (_Dst != (char *)0x0) {
        __3_YAXPAX_Z(_Dst);
      }
      *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
      CloseHandle(hFile);
      FUN_00025510(local_30);
      return uVar4;
    }
    *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
    if (hFile != (HANDLE)0x0) {
      CloseHandle(hFile);
    }
    if (_Dst == (char *)0x0) goto LAB_0001900c;
  }
  else {
    memcpy(_Dst,acStack_c0,10);
    BVar2 = ReadFile(hFile,_Dst + 10,uVar3 - 10,local_c8,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      uVar4 = FUN_000178bc(param_1,_Dst,param_3,uVar3);
      goto LAB_0001915c;
    }
    *(uint *)(param_3 + 0x720) = *(uint *)(param_3 + 0x720) | 0x80;
    if (hFile != (HANDLE)0x0) {
      CloseHandle(hFile);
    }
  }
  __3_YAXPAX_Z(_Dst);
LAB_0001900c:
  FUN_00025510(local_30);
  return 0;
}



/* 00019254 FUN_00019254 */

/* Boundary evidence: original MIPS .pdata 00019254..00019447. Semantic name remains unreviewed. */

undefined4 FUN_00019254(wchar_t *param_1,wchar_t *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_28 [2];
  
  iVar1 = wcsncmp(param_1 + 0x61c,param_2,0x104);
  if (iVar1 == 0) {
    if ((param_4 != 0) && (param_3 == 1)) {
      FUN_000209e0(auStack_28);
      if ((*(uint *)(param_1 + 0x720) & 1) != 0) {
        memset(param_1 + 0x208,0,0x208);
        FUN_00024e04((int)auStack_28,(char *)(param_1 + 0x514),param_1 + 0x208,0x103);
      }
      if ((*(uint *)(param_1 + 0x720) & 2) != 0) {
        memset(param_1 + 0x104,0,0x208);
        FUN_00024e04((int)auStack_28,(char *)(param_1 + 0x492),param_1 + 0x104,0x103);
      }
      if ((*(uint *)(param_1 + 0x720) & 4) != 0) {
        memset(param_1,0,0x208);
        FUN_00024e04((int)auStack_28,(char *)(param_1 + 0x410),param_1,0x103);
      }
      if ((*(uint *)(param_1 + 0x720) & 0x10) != 0) {
        memset(param_1 + 0x30c,0,0x208);
        FUN_00024e04((int)auStack_28,(char *)(param_1 + 0x596),param_1 + 0x30c,0x103);
      }
      FUN_000209d0(auStack_28);
    }
  }
  else {
    param_1[0x61a] = L'\0';
    param_1[0x61b] = L'\0';
    memset(param_1,0,0xe44);
    if (param_3 == 1) {
      FUN_00018f84((uint *)param_1,param_2,param_1);
    }
    else if (param_3 == 2) {
      FUN_000182dc(param_1,param_2,param_1);
    }
    wcsncpy_s(param_1 + 0x61c,0x104,param_2,0x103);
  }
  return 0;
}



/* 00019448 Unwind@00019448 */

/* Boundary evidence: original MIPS .pdata 00019448..00019477. Semantic name remains unreviewed. */

void Unwind_00019448(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 00019478 FUN_00019478 */

/* Boundary evidence: original MIPS .pdata 00019478..00019507. Semantic name remains unreviewed. */

void FUN_00019478(int param_1)

{
  memset((void *)(param_1 + 6),0,0x208);
  memset((void *)(param_1 + 0x20e),0,0x208);
  memset((void *)(param_1 + 0x416),0,0x208);
  memset((void *)(param_1 + 0x61e),0,0x208);
  memset((void *)(param_1 + 0xa2e),0,0x208);
  memset((void *)(param_1 + 0xc36),0,0x208);
  memset((void *)(param_1 + 0x826),0,0x208);
  return;
}



/* 00019508 FUN_00019508 */

/* Boundary evidence: original MIPS .pdata 00019508..00019563. Semantic name remains unreviewed. */

void FUN_00019508(undefined4 *param_1)

{
  HGDIOBJ ho;
  
  ho = *(HGDIOBJ *)((int)param_1 + 0x2926);
  *param_1 = &PTR_FUN_00029050;
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
    *(undefined4 *)((int)param_1 + 0x2926) = 0;
  }
  FUN_000174f8();
  return;
}



/* 00019564 FUN_00019564 */

/* Boundary evidence: original MIPS .pdata 00019564..000196c3. Semantic name remains unreviewed. */

int FUN_00019564(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 auStack_20 [2];
  
  FUN_000209e0(auStack_20);
  if (*(int *)(param_1 + 0x291e) == 0) {
    iVar1 = FUN_000231a4();
    iVar2 = FUN_000132fc(*(int *)(iVar1 + 0x48),param_2);
    iVar1 = FUN_000231a4();
    iVar3 = FUN_0001355c(*(int *)(iVar1 + 0x48),iVar2);
    iVar1 = FUN_000231a4();
    iVar1 = FUN_00012ed8(*(int *)(iVar1 + 0x48),iVar2);
    iVar1 = iVar1 + iVar3;
    if (param_2 == iVar3) {
      iVar1 = FUN_000231a4();
      iVar1 = FUN_00014884(*(int *)(iVar1 + 0x48),iVar2);
      iVar2 = FUN_000231a4();
      iVar3 = FUN_0001355c(*(int *)(iVar2 + 0x48),iVar1);
      iVar2 = FUN_000231a4();
      iVar1 = FUN_00012ed8(*(int *)(iVar2 + 0x48),iVar1);
      iVar1 = iVar1 + iVar3;
    }
    iVar1 = iVar1 + -1;
    if ((iVar3 < param_2) && (param_2 <= iVar1)) {
      iVar1 = param_2 + -1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe58) + -1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(param_1 + 0xe4c) + -1;
    }
    if (param_3 == 0) {
      *(int *)(param_1 + 0xe58) = iVar1;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xe5c) + iVar1 * 4);
  }
  FUN_000209d0(auStack_20);
  return iVar1;
}



/* 000196c4 Unwind@000196c4 */

/* Boundary evidence: original MIPS .pdata 000196c4..000196f3. Semantic name remains unreviewed. */

void Unwind_000196c4(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 000196f4 FUN_000196f4 */

/* Boundary evidence: original MIPS .pdata 000196f4..0001972f. Semantic name remains unreviewed. */

void FUN_000196f4(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ec);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x70) = 0;
  return;
}



/* 00019730 FUN_00019730 */

/* Boundary evidence: original MIPS .pdata 00019730..0001975f. Semantic name remains unreviewed. */

void FUN_00019730(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ed);
  return;
}



/* 00019760 FUN_00019760 */

/* Boundary evidence: original MIPS .pdata 00019760..000197bb. Semantic name remains unreviewed. */

void FUN_00019760(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    FUN_00023580(5,0x15,0x6c,0,(LPARAM *)0x0);
  }
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
  return;
}



/* 000197bc FUN_000197bc */

/* Boundary evidence: original MIPS .pdata 000197bc..000197e3. Semantic name remains unreviewed. */

void FUN_000197bc(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
  return;
}



/* 000197e4 FUN_000197e4 */

void FUN_000197e4(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x293c) = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x1add) = 0;
    *(undefined1 *)(param_1 + 0x1adb) = 0;
    *(undefined1 *)(param_1 + 0x1adc) = 0;
  }
  else {
    uVar1 = param_2 / 0x3c;
    if (uVar1 < 0x3c) {
      *(undefined1 *)(param_1 + 0x1add) = 0;
      *(char *)(param_1 + 0x1adb) = (char)uVar1;
    }
    else {
      *(char *)(param_1 + 0x1add) = (char)(uVar1 / 0x3c);
      *(char *)(param_1 + 0x1adb) = (char)(uVar1 % 0x3c);
    }
    *(char *)(param_1 + 0x1adc) = (char)(param_2 % 0x3c);
  }
  return;
}



/* 00019864 FUN_00019864 */

void FUN_00019864(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x2940) = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x1ada) = 0;
    *(undefined1 *)(param_1 + 0x1ad8) = 0;
    *(undefined1 *)(param_1 + 0x1ad9) = 0;
  }
  else {
    uVar1 = param_2 / 0x3c;
    if (uVar1 < 0x3c) {
      *(undefined1 *)(param_1 + 0x1ada) = 0;
      *(char *)(param_1 + 0x1ad8) = (char)uVar1;
    }
    else {
      *(char *)(param_1 + 0x1ada) = (char)(uVar1 / 0x3c);
      *(char *)(param_1 + 0x1ad8) = (char)(uVar1 % 0x3c);
    }
    *(char *)(param_1 + 0x1ad9) = (char)(param_2 % 0x3c);
  }
  return;
}



/* 000198e4 FUN_000198e4 */

/* Boundary evidence: original MIPS .pdata 000198e4..00019adf. Semantic name remains unreviewed. */

undefined4
FUN_000198e4(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int local_4e58;
  uint local_4e54;
  int *local_4e50;
  int aiStack_4e4c [5001];
  
  uVar2 = (param_4 - param_3) + 1;
  local_4e58 = -1;
  iVar5 = 0;
  if (0 < (int)uVar2) {
    iVar3 = 0;
    local_4e50 = param_2;
    if (0 < (int)uVar2) {
      piVar6 = aiStack_4e4c;
      do {
        piVar6 = piVar6 + 1;
        *piVar6 = iVar3 + param_3;
        Sleep(1);
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x18) != 0) {
          return 0xffffffff;
        }
        if (param_7 == iVar3 + param_3) {
          local_4e58 = iVar3;
        }
        if (*(int *)(param_1 + 0x291e) == 0) {
          return 0xffffffff;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)uVar2);
    }
    piVar6 = local_4e50;
    local_4e54 = 0;
    if (1 < (int)uVar2) {
      piVar4 = aiStack_4e4c + uVar2;
      do {
        if ((param_7 < 0) || (iVar5 != 0)) {
          rand_s(&local_4e54);
          if (uVar2 == 0) {
            trap(0x1c00);
          }
          piVar6[iVar5] = aiStack_4e4c[local_4e54 % uVar2 + 1];
          aiStack_4e4c[local_4e54 % uVar2 + 1] = *piVar4;
        }
        else {
          iVar3 = *piVar4;
          *piVar6 = aiStack_4e4c[local_4e58 + 1];
          aiStack_4e4c[local_4e58 + 1] = iVar3;
        }
        iVar5 = iVar5 + 1;
        uVar2 = uVar2 - 1;
        piVar4 = piVar4 + -1;
        if (*(int *)(param_1 + 0x291e) == 0) {
          return 0xffffffff;
        }
        iVar3 = FUN_000231a4();
        if (*(int *)(iVar3 + 0x18) != 0) {
          return 0xffffffff;
        }
        Sleep(1);
      } while (1 < (int)uVar2);
    }
    piVar6[iVar5] = aiStack_4e4c[1];
  }
  return 0;
}



/* 00019ae0 FUN_00019ae0 */

void FUN_00019ae0(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x291e) = (uint)(param_2 != 0);
  return;
}



/* 00019af8 FUN_00019af8 */

/* Boundary evidence: original MIPS .pdata 00019af8..00019c93. Semantic name remains unreviewed. */

undefined4 FUN_00019af8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0xe58) = 0;
  *(undefined4 *)(param_1 + 0xe4c) = 0;
  if (*(int *)(param_1 + 0xe5c) != 0) {
    *(undefined4 *)(param_1 + 0xe5c) = 0;
  }
  iVar1 = FUN_000231a4();
  iVar2 = FUN_000132fc(*(int *)(iVar1 + 0x48),*(int *)(param_1 + 0x2916));
  iVar6 = 0;
  *(undefined **)(param_1 + 0xe5c) = &DAT_00030108;
  iVar1 = iVar2;
  do {
    iVar3 = FUN_000231a4();
    if ((*(int *)(iVar3 + 0x18) != 0) || (*(int *)(param_1 + 0x291e) == 0)) {
      return 0xffffffff;
    }
    Sleep(1);
    iVar3 = FUN_000231a4();
    iVar3 = FUN_00012f10(*(int *)(iVar3 + 0x48),iVar1);
    *(int *)(param_1 + 0xe50) = iVar3;
    iVar4 = FUN_000231a4();
    iVar4 = FUN_00012f48(*(int *)(iVar4 + 0x48),iVar1);
    iVar4 = iVar4 + iVar3 + -1;
    *(int *)(param_1 + 0xe54) = iVar4;
    if (iVar1 == iVar2) {
      uVar5 = FUN_000198e4(param_1,(int *)(&DAT_00030108 + iVar6 * 4),iVar3,iVar4,1,1,
                           *(int *)(param_1 + 0x2916));
    }
    else {
      uVar5 = FUN_000198e4(param_1,(int *)(&DAT_00030108 + iVar6 * 4),iVar3,iVar4,1,1,-1);
    }
    iVar3 = FUN_000231a4();
    iVar3 = FUN_00012ed8(*(int *)(iVar3 + 0x48),iVar1);
    iVar6 = iVar3 + iVar6;
    *(int *)(param_1 + 0xe4c) = iVar6;
    iVar3 = FUN_000231a4();
    iVar1 = FUN_00014720(*(int *)(iVar3 + 0x48),iVar1);
  } while (iVar1 != iVar2);
  *(undefined **)(param_1 + 0xe5c) = &DAT_00030108;
  return uVar5;
}



/* 00019c94 FUN_00019c94 */

/* Boundary evidence: original MIPS .pdata 00019c94..00019d3b. Semantic name remains unreviewed. */

void FUN_00019c94(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0);
  if (iVar1 == 1) {
    iVar1 = FUN_000231a4();
    if (-1 < *(int *)(iVar1 + 0x74)) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(param_1 + 0x2916) = *(undefined4 *)(iVar1 + 0x74);
    }
    FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
  }
  else {
    *(undefined4 *)(param_1 + 0x2916) = param_2;
  }
  return;
}



/* 00019d3c FUN_00019d3c */

/* Boundary evidence: original MIPS .pdata 00019d3c..0001a0d3. Semantic name remains unreviewed. */

undefined4 FUN_00019d3c(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  wchar_t *_Src;
  size_t _Count;
  int iVar5;
  wchar_t *_Dest;
  undefined4 uVar6;
  wchar_t *_Dst;
  wchar_t *_Dst_00;
  undefined1 auStack_28f0 [520];
  undefined1 auStack_26e8 [520];
  undefined1 auStack_24e0 [2608];
  uint local_1ab0;
  undefined1 auStack_1aa8 [3656];
  wchar_t local_c60;
  wchar_t awStack_c5e [259];
  wchar_t local_a58;
  undefined1 auStack_a56 [518];
  wchar_t awStack_850 [1040];
  uint local_30;
  
  local_30 = DAT_0002f960;
  iVar1 = FUN_000231a4();
  iVar5 = *(int *)(iVar1 + 0x48);
  iVar1 = FUN_00013334(iVar5,param_2);
  uVar6 = 1;
  if ((iVar1 == 1) || (iVar1 == 2)) {
    memset(awStack_850,0,0x820);
    FUN_00013350(iVar5,param_2,awStack_850);
    _Src = (wchar_t *)(param_1 + 4);
    FUN_00019254(_Src,awStack_850,iVar1,param_3);
    _Dest = (wchar_t *)(param_1 + 0x1ce6);
    memset(_Dest,0,0x208);
    _Dst = (wchar_t *)(param_1 + 0x20f6);
    memset(_Dst,0,0x208);
    _Dst_00 = (wchar_t *)(param_1 + 0x1eee);
    memset(_Dst_00,0,0x208);
    memcpy(auStack_28f0,_Src,0xe44);
    if ((local_1ab0 & 1) == 0) {
      memset(awStack_c5e,0,0x206);
      local_a58 = L'\0';
      memset(auStack_a56,0,0x206);
      pvVar2 = (void *)FUN_00013318(iVar5,param_2);
      memcpy(&local_c60,pvVar2,0x103);
      if (local_c60 == L'\\') {
        _Count = 0;
        sVar3 = wcslen(&local_c60);
        if (0 < (int)sVar3) {
          pwVar4 = awStack_c5e + (sVar3 - 1);
          do {
            if (*pwVar4 == L'\\') {
              wcsncpy(&local_a58,awStack_c5e + sVar3,_Count);
              break;
            }
            _Count = _Count + 1;
            sVar3 = sVar3 - 1;
            pwVar4 = pwVar4 + -1;
          } while (0 < (int)sVar3);
        }
        sVar3 = wcslen(&local_a58);
        wcsncpy(_Dest,&local_a58,sVar3);
      }
      else {
        pvVar2 = (void *)FUN_00013318(iVar5,param_2);
        memcpy(_Dest,pvVar2,0x103);
      }
      FUN_00023aac(5,0,L"%S %d Track Name : %s","CPlayControl::setID3Info");
    }
    else {
      memcpy(auStack_28f0,_Src,0xe44);
      memcpy(_Dest,auStack_24e0,0x81);
      memcpy(auStack_1aa8,_Src,0xe44);
      FUN_00023aac(5,0,L"%S %d Track Name : %s","CPlayControl::setID3Info");
    }
    memcpy(auStack_28f0,_Src,0xe44);
    if ((local_1ab0 & 2) == 0) {
      wcscpy_s(_Dst,0x104,L"No Album");
    }
    else {
      memcpy(auStack_28f0,_Src,0xe44);
      memcpy(_Dst,auStack_26e8,0x81);
    }
    memcpy(auStack_28f0,_Src,0xe44);
    if ((local_1ab0 & 4) == 0) {
      wcscpy_s(_Dst_00,0x104,L"No Artist");
    }
    else {
      memcpy(auStack_1aa8,_Src,0xe44);
      memcpy(_Dst_00,auStack_1aa8,0x81);
    }
    FUN_00025510(local_30);
  }
  else {
    FUN_00023aac(5,2,L"%S error current media type is not MP3","CPlayControl::setID3Info");
    FUN_00025510(local_30);
    uVar6 = 0;
  }
  return uVar6;
}



/* 0001a0d4 FUN_0001a0d4 */

/* Boundary evidence: original MIPS .pdata 0001a0d4..0001a317. Semantic name remains unreviewed. */

undefined4 FUN_0001a0d4(int param_1,wchar_t *param_2,int param_3)

{
  wchar_t *_Src;
  undefined4 uVar1;
  wchar_t *_Dst;
  wchar_t *_Dst_00;
  void *_Dst_01;
  undefined1 auStack_1cb0 [520];
  undefined1 auStack_1aa8 [520];
  undefined1 auStack_18a0 [2608];
  uint local_e70;
  undefined1 auStack_e68 [3656];
  
  uVar1 = 1;
  if ((param_3 == 1) || (param_3 == 2)) {
    _Src = (wchar_t *)(param_1 + 4);
    FUN_00019254(_Src,param_2,param_3,0);
    _Dst_01 = (void *)(param_1 + 0x1ce6);
    memset(_Dst_01,0,0x208);
    _Dst = (wchar_t *)(param_1 + 0x20f6);
    memset(_Dst,0,0x208);
    _Dst_00 = (wchar_t *)(param_1 + 0x1eee);
    memset(_Dst_00,0,0x208);
    memcpy(auStack_1cb0,_Src,0xe44);
    if ((local_e70 & 1) == 0) {
      memcpy(_Dst_01,(void *)(param_1 + 0x1290),0x81);
      FUN_00023aac(5,0,L"%S %d Track Name : %s","CPlayControl::setResumeID3Info");
    }
    else {
      memcpy(auStack_1cb0,_Src,0xe44);
      memcpy(_Dst_01,auStack_18a0,0x81);
      memcpy(auStack_e68,_Src,0xe44);
      FUN_00023aac(5,0,L"%S %d Track Name : %s","CPlayControl::setResumeID3Info");
    }
    memcpy(auStack_1cb0,_Src,0xe44);
    if ((local_e70 & 2) == 0) {
      wcscpy_s(_Dst,0x104,L"No Album");
    }
    else {
      memcpy(auStack_1cb0,_Src,0xe44);
      memcpy(_Dst,auStack_1aa8,0x81);
    }
    memcpy(auStack_1cb0,_Src,0xe44);
    if ((local_e70 & 4) == 0) {
      wcscpy_s(_Dst_00,0x104,L"No Artist");
    }
    else {
      memcpy(auStack_e68,_Src,0xe44);
      memcpy(_Dst_00,auStack_e68,0x81);
    }
  }
  else {
    FUN_00023aac(5,2,L"%S error current media type is not MP3","CPlayControl::setResumeID3Info");
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001a318 FUN_0001a318 */

/* Boundary evidence: original MIPS .pdata 0001a318..0001a60b. Semantic name remains unreviewed. */

undefined4 FUN_0001a318(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HBITMAP h;
  int *local_f00;
  int *local_efc;
  byte *local_ef8 [2];
  BITMAPINFO local_ef0;
  tagRECT tStack_ec0;
  undefined1 auStack_eb0 [3124];
  int local_27c;
  undefined1 auStack_68 [64];
  uint local_28;
  
  local_28 = DAT_0002f960;
  h = (HBITMAP)0x0;
  local_f00 = (int *)0x0;
  local_efc = (int *)0x0;
  HVar1 = CoCreateInstance((IID *)&DAT_00028e80,(LPUNKNOWN)0x0,1,(IID *)&DAT_00028e70,&local_f00);
  if (-1 < HVar1) {
    memcpy(auStack_eb0,(void *)(param_1 + 4),0xe44);
    if ((local_27c != 0) &&
       (iVar2 = (**(code **)(*local_f00 + 0x14))
                          (local_f00,*(undefined4 *)(param_1 + 0xe48),0x800000,0,&local_efc),
       -1 < iVar2)) {
      hdc = CreateCompatibleDC((HDC)0x0);
      (**(code **)(*local_efc + 0x10))(local_efc,auStack_68);
      memset(&local_ef0,0,0x28);
      local_ef0.bmiHeader.biSize = 0x28;
      local_ef0.bmiHeader.biBitCount = 0x18;
      iVar2 = FUN_000231a4();
      local_ef0.bmiHeader.biWidth = *(int *)(iVar2 + 0x7c);
      iVar2 = FUN_000231a4();
      local_ef0.bmiHeader.biHeight = *(int *)(iVar2 + 0x80);
      local_ef0.bmiHeader.biPlanes = 1;
      h = CreateDIBSection(hdc,&local_ef0,0,local_ef8,(HANDLE)0x0,0);
      if (h != (HBITMAP)0x0) {
        pvVar3 = SelectObject(hdc,h);
        SetRect(&tStack_ec0,0,0,local_ef0.bmiHeader.biWidth,local_ef0.bmiHeader.biHeight);
        (**(code **)(*local_efc + 0x18))(local_efc,hdc,&tStack_ec0,0);
        SelectObject(hdc,pvVar3);
        iVar6 = 0;
        iVar2 = local_ef0.bmiHeader.biHeight;
        iVar4 = local_ef0.bmiHeader.biWidth;
        if (0 < local_ef0.bmiHeader.biHeight) {
          do {
            iVar5 = 0;
            if (0 < iVar4) {
              do {
                if ((((7 < *local_ef8[0]) && (*local_ef8[0] < 0x10)) && (local_ef8[0][1] < 4)) &&
                   (local_ef8[0][2] < 8)) {
                  memset(local_ef8[0],0,3);
                  iVar4 = local_ef0.bmiHeader.biWidth;
                }
                iVar5 = iVar5 + 1;
                local_ef8[0] = local_ef8[0] + 3;
                iVar2 = local_ef0.bmiHeader.biHeight;
              } while (iVar5 < iVar4);
            }
            iVar6 = iVar6 + 1;
            local_ef8[0] = local_ef8[0] + 2;
          } while (iVar6 < iVar2);
        }
      }
      DeleteDC(hdc);
      (**(code **)(*local_efc + 8))();
    }
    (**(code **)(*local_f00 + 8))();
    local_f00 = (int *)0x0;
  }
  pvVar3 = *(HGDIOBJ *)(param_1 + 0x2926);
  if (pvVar3 != (HGDIOBJ)0x0) {
    DeleteObject(pvVar3);
  }
  *(HBITMAP *)(param_1 + 0x2926) = h;
  iVar2 = FUN_000231a4();
  if (*(int *)(iVar2 + 0x40) != 0) {
    iVar2 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar2 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  FUN_00023580(5,0x15,0x67,0,(LPARAM *)0x0);
  FUN_00025510(local_28);
  return 0xffffffff;
}



/* 0001a60c FUN_0001a60c */

/* Boundary evidence: original MIPS .pdata 0001a60c..0001a69b. Semantic name remains unreviewed. */

void FUN_0001a60c(int param_1)

{
  int iVar1;
  HGDIOBJ ho;
  
  ho = *(HGDIOBJ *)(param_1 + 0x2926);
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
    *(undefined4 *)(param_1 + 0x2926) = 0;
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x40) != 0) {
      iVar1 = FUN_000231a4();
      FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
    }
    FUN_00023580(5,0x15,0x67,0,(LPARAM *)0x0);
  }
  return;
}



/* 0001a69c FUN_0001a69c */

/* Boundary evidence: original MIPS .pdata 0001a69c..0001a7cf. Semantic name remains unreviewed. */

DWORD * FUN_0001a69c(undefined4 param_1,DWORD *param_2,LPCWSTR param_3)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  _BY_HANDLE_FILE_INFORMATION _Stack_50;
  
  memset(param_2,0,8);
  hFile = CreateFileW(param_3,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"error CreateFile(%s) : 0x%x\r\n",param_3,DVar2);
  }
  else {
    BVar1 = GetFileInformationByHandle(hFile,&_Stack_50);
    if (BVar1 == 1) {
      param_2[1] = _Stack_50.dwVolumeSerialNumber;
      *param_2 = _Stack_50.nFileSizeLow;
      NKDbgPrintfW(L"\r\ngood GetFileInformationByHandle(%s) [0x%x - 0x%x]\r\n",param_3);
    }
    else {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"error GetFileInformationByHandle() : 0x%x\r\n",DVar2);
    }
    CloseHandle(hFile);
  }
  return param_2;
}



/* 0001a7d0 FUN_0001a7d0 */

/* Boundary evidence: original MIPS .pdata 0001a7d0..0001a9e3. Semantic name remains unreviewed. */

void FUN_0001a7d0(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  DWORD *pDVar6;
  BOOL BVar7;
  uint uVar8;
  uint uVar9;
  ULARGE_INTEGER local_858;
  ULARGE_INTEGER local_850;
  DWORD aDStack_848 [2];
  ULARGE_INTEGER UStack_840;
  wchar_t local_838;
  undefined1 auStack_836 [2078];
  uint local_18;
  
  local_18 = DAT_0002f960;
  if (param_2 == -1) {
    param_2 = *(int *)(param_1 + 0x2916);
  }
  iVar3 = FUN_000231a4();
  iVar3 = FUN_000132a0(*(int *)(iVar3 + 0x48),param_2);
  *(int *)(param_1 + 0xe6c) = iVar3;
  *(int *)(param_1 + 0xe74) = param_2;
  *(undefined4 *)(param_1 + 0xe7c) = 0;
  iVar3 = FUN_000231a4();
  uVar4 = FUN_00013334(*(int *)(iVar3 + 0x48),param_2);
  *(undefined4 *)(param_1 + 0xe78) = uVar4;
  iVar3 = FUN_000231a4();
  uVar4 = FUN_00012ebc(*(int *)(iVar3 + 0x48));
  *(undefined4 *)(param_1 + 0xe70) = uVar4;
  iVar3 = FUN_000231a4();
  uVar5 = FUN_00012eb4(*(int *)(iVar3 + 0x48));
  uVar8 = *(uint *)(param_1 + 0x291a);
  uVar9 = *(uint *)(param_1 + 0x291e);
  uVar1 = param_1 + 0xe6bU & 3;
  puVar2 = (uint *)((param_1 + 0xe6bU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar5 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x1ab3U & 3;
  puVar2 = (uint *)((param_1 + 0x1ab3U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar8 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x1ab7U & 3;
  puVar2 = (uint *)((param_1 + 0x1ab7U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar9 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0xe68U & 3;
  puVar2 = (uint *)((param_1 + 0xe68U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar5 << uVar1 * 8;
  uVar1 = param_1 + 0x1ab0U & 3;
  puVar2 = (uint *)((param_1 + 0x1ab0U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar8 << uVar1 * 8;
  uVar1 = param_1 + 0x1ab4U & 3;
  puVar2 = (uint *)((param_1 + 0x1ab4U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar9 << uVar1 * 8;
  local_838 = L'\0';
  memset(auStack_836,0,0x81e);
  iVar3 = FUN_000231a4();
  FUN_00013350(*(int *)(iVar3 + 0x48),param_2,&local_838);
  memcpy((void *)(param_1 + 0x1088),&local_838,0x207);
  pDVar6 = FUN_0001a69c(param_1,aDStack_848,&local_838);
  *(DWORD *)(param_1 + 0x1ac8) = *pDVar6;
  *(DWORD *)(param_1 + 0x1acc) = pDVar6[1];
  memcpy((void *)(param_1 + 0x18a8),(void *)(param_1 + 0x2506),0x208);
  memcpy((void *)(param_1 + 0xe80),(void *)(param_1 + 0x270e),0x208);
  memcpy((void *)(param_1 + 0x1498),(void *)(param_1 + 0x20f6),0x208);
  memcpy((void *)(param_1 + 0x1290),(void *)(param_1 + 0x1ce6),0x208);
  memcpy((void *)(param_1 + 0x16a0),(void *)(param_1 + 0x1eee),0x208);
  BVar7 = GetDiskFreeSpaceExW(L"MD",&UStack_840,&local_850,&local_858);
  if (BVar7 == 0) {
    *(undefined4 *)(param_1 + 0x1ab8) = 0;
    *(undefined4 *)(param_1 + 0x1abc) = 0;
    *(undefined4 *)(param_1 + 0x1ac0) = 0;
    *(undefined4 *)(param_1 + 0x1ac4) = 0;
  }
  else {
    *(DWORD *)(param_1 + 0x1ab8) = local_858.s.LowPart;
    *(DWORD *)(param_1 + 0x1abc) = local_858.s.HighPart;
    *(DWORD *)(param_1 + 0x1ac0) = local_850.s.LowPart;
    *(DWORD *)(param_1 + 0x1ac4) = local_850.s.HighPart;
  }
  FUN_00025510(local_18);
  return;
}



/* 0001a9e4 FUN_0001a9e4 */

/* Boundary evidence: original MIPS .pdata 0001a9e4..0001ab4f. Semantic name remains unreviewed. */

void FUN_0001a9e4(int param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t local_420 [260];
  wchar_t local_218;
  undefined1 auStack_216 [518];
  uint local_10;
  
  local_10 = DAT_0002f960;
  memcpy((void *)(param_1 + 0x2506),(void *)(param_1 + 0x18a8),0x208);
  memcpy((void *)(param_1 + 0x1ce6),(void *)(param_1 + 0x1290),0x208);
  memcpy((void *)(param_1 + 0x1eee),(void *)(param_1 + 0x16a0),0x208);
  memcpy((void *)(param_1 + 0x20f6),(void *)(param_1 + 0x1498),0x208);
  memcpy((void *)(param_1 + 0x270e),(void *)(param_1 + 0xe80),0x208);
  iVar1 = FUN_0001144c();
  uVar2 = FUN_0001137c(iVar1);
  FUN_000197e4(param_1,uVar2);
  memcpy(local_420,(void *)(param_1 + 0x1088),0x208);
  if (local_420[0] != L'\\') {
    local_218 = L'\0';
    memset(auStack_216,0,0x206);
    swprintf(&local_218,0x29278,local_420);
    memcpy(local_420,&local_218,0x208);
  }
  FUN_0001a0d4(param_1,local_420,*(int *)(param_1 + 0xe78));
  FUN_00019864(param_1,*(int *)(param_1 + 0xe7c));
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
  FUN_00025510(local_10);
  return;
}



/* 0001ab50 FUN_0001ab50 */

undefined4 FUN_0001ab50(undefined4 param_1,byte *param_2,int param_3)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 1;
  iVar4 = 0;
  uVar3 = 0;
  iVar5 = 1;
  if (1 < param_3) {
    do {
      pbVar2 = param_2 + iVar5;
      iVar5 = iVar5 + 1;
      uVar3 = uVar3 + *pbVar2 & 0xff;
      iVar4 = (uint)*pbVar2 + iVar4;
    } while (iVar5 < param_3);
  }
  if ((uVar3 != *param_2) || (iVar4 == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001abac FUN_0001abac */

void FUN_0001abac(int param_1)

{
  *(undefined4 *)(param_1 + 0x291a) = *(undefined4 *)(param_1 + 0x1ab0);
  *(undefined4 *)(param_1 + 0x2934) = *(undefined4 *)(param_1 + 0x1ab0);
  *(undefined4 *)(param_1 + 0x291e) = *(undefined4 *)(param_1 + 0x1ab4);
  *(undefined4 *)(param_1 + 0x2938) = *(undefined4 *)(param_1 + 0x1ab4);
  return;
}



/* 0001abe0 FUN_0001abe0 */

/* Boundary evidence: original MIPS .pdata 0001abe0..0001ac57. Semantic name remains unreviewed. */

void FUN_0001abe0(void)

{
  undefined4 local_10 [2];
  
  FUN_00023aac(5,0,L"%S ---------- requestMediaFadeIn ----------","CPlayControl::requestMediaFadeIn"
              );
  local_10[0] = 1;
  FUN_000237b4(5,3,0x8b,4,local_10);
  FUN_00023aac(5,0,L"%S ---------- requestMediaFadeIn---END ----------",
               "CPlayControl::requestMediaFadeIn");
  return;
}



/* 0001ac58 FUN_0001ac58 */

/* Boundary evidence: original MIPS .pdata 0001ac58..0001accb. Semantic name remains unreviewed. */

void FUN_0001ac58(void)

{
  undefined4 local_10 [2];
  
  FUN_00023aac(5,0,L"%S ---------- requestMediaFadeOUt ----------",
               "CPlayControl::requestMediaFadeOut");
  local_10[0] = 0;
  FUN_000237b4(5,3,0x8b,4,local_10);
  FUN_00023aac(5,0,L"%S ---------- requestMediaFadeOUt---END ----------",
               "CPlayControl::requestMediaFadeOut");
  return;
}



/* 0001accc FUN_0001accc */

/* Boundary evidence: original MIPS .pdata 0001accc..0001ad37. Semantic name remains unreviewed. */

void FUN_0001accc(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1ad9) = *(undefined1 *)(param_1 + 0x1adc);
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  FUN_00023580(5,0x15,0x65,0,(LPARAM *)0x0);
  return;
}



/* 0001ad38 FUN_0001ad38 */

/* Boundary evidence: original MIPS .pdata 0001ad38..0001ad83. Semantic name remains unreviewed. */

undefined4 * FUN_0001ad38(undefined4 *param_1,uint param_2)

{
  FUN_00019508(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001ad84 FUN_0001ad84 */

/* Boundary evidence: original MIPS .pdata 0001ad84..0001ae53. Semantic name remains unreviewed. */

void FUN_0001ad84(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  HGDIOBJ ho;
  
  ho = *(HGDIOBJ *)(param_1 + 0x2926);
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
    *(undefined4 *)(param_1 + 0x2926) = 0;
    iVar3 = FUN_000231a4();
    if (*(int *)(iVar3 + 0x40) != 0) {
      iVar3 = FUN_000231a4();
      FUN_00024094(*(int *)(iVar3 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
    }
  }
  uVar1 = param_1 + 0x2925U & 3;
  puVar2 = (uint *)((param_1 + 0x2925U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x2921U & 3;
  puVar2 = (uint *)((param_1 + 0x2921U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x291dU & 3;
  puVar2 = (uint *)((param_1 + 0x291dU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  *(undefined4 *)(param_1 + 0x1ad0) = 0;
  uVar1 = param_1 + 0x2922U & 3;
  puVar2 = (uint *)((param_1 + 0x2922U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x291eU & 3;
  puVar2 = (uint *)((param_1 + 0x291eU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x291aU & 3;
  puVar2 = (uint *)((param_1 + 0x291aU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  *(undefined4 *)(param_1 + 0x2930) = 0;
  *(undefined4 *)(param_1 + 0x293c) = 0;
  *(undefined4 *)(param_1 + 0x2940) = 0;
  *(undefined4 *)(param_1 + 0xe60) = 0;
  *(undefined4 *)(param_1 + 0xe4c) = 0;
  *(undefined4 *)(param_1 + 0xe58) = 0;
  *(undefined4 *)(param_1 + 0xe54) = 0;
  *(undefined4 *)(param_1 + 0xe50) = 0;
  *(undefined4 *)(param_1 + 0xe5c) = 0;
  *(undefined4 *)(param_1 + 0x1ad4) = 1;
  memset((void *)(param_1 + 0xe64),0,0xc6c);
  return;
}



/* 0001ae54 FUN_0001ae54 */

/* Boundary evidence: original MIPS .pdata 0001ae54..0001af27. Semantic name remains unreviewed. */

void FUN_0001ae54(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x2922) = param_2;
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  FUN_00023aac(5,0,L"%S PlayStatus %s","CPlayControl::setPlayStatus");
  return;
}



/* 0001af28 FUN_0001af28 */

/* Boundary evidence: original MIPS .pdata 0001af28..0001afbb. Semantic name remains unreviewed. */

undefined4 FUN_0001af28(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
  FUN_0001ae54(param_1,3);
  iVar1 = FUN_0001144c();
  uVar2 = FUN_00011568(iVar1,1);
  FUN_00019864(param_1,0);
  return uVar2;
}



/* 0001afbc FUN_0001afbc */

/* Boundary evidence: original MIPS .pdata 0001afbc..0001b14b. Semantic name remains unreviewed. */

int FUN_0001afbc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 auStack_28 [2];
  
  FUN_000209e0(auStack_28);
  iVar1 = FUN_000231a4();
  iVar1 = FUN_000132fc(*(int *)(iVar1 + 0x48),param_2);
  iVar2 = FUN_000231a4();
  iVar2 = FUN_0001355c(*(int *)(iVar2 + 0x48),iVar1);
  iVar3 = FUN_000231a4();
  iVar3 = FUN_00012ed8(*(int *)(iVar3 + 0x48),iVar1);
  iVar3 = iVar3 + iVar2 + -1;
  if (((*(int *)(param_1 + 0x291a) == 2) && (*(int *)(param_1 + 0x291e) == 0)) &&
     (iVar4 = FUN_000231a4(), *(int *)(iVar4 + 0x1c) == 0)) {
    if (*(int *)(param_1 + 0x2916) == iVar3) {
      FUN_00019c94(param_1,iVar2 + -1);
    }
  }
  else if (*(int *)(param_1 + 0x2916) == iVar3) {
    iVar2 = FUN_000231a4();
    iVar1 = FUN_00014720(*(int *)(iVar2 + 0x48),iVar1);
    iVar2 = FUN_000231a4();
    iVar2 = FUN_0001355c(*(int *)(iVar2 + 0x48),iVar1);
    iVar3 = FUN_000231a4();
    iVar1 = FUN_00012ed8(*(int *)(iVar3 + 0x48),iVar1);
    iVar3 = iVar1 + iVar2 + -1;
  }
  if ((param_2 < iVar3) && (iVar2 <= param_2)) {
    iVar2 = param_2 + 1;
  }
  FUN_000209d0(auStack_28);
  return iVar2;
}



/* 0001b14c Unwind@0001b14c */

/* Boundary evidence: original MIPS .pdata 0001b14c..0001b17b. Semantic name remains unreviewed. */

void Unwind_0001b14c(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 0001b17c FUN_0001b17c */

/* Boundary evidence: original MIPS .pdata 0001b17c..0001b1bf. Semantic name remains unreviewed. */

void FUN_0001b17c(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),1000,500,(TIMERPROC)0x0);
  return;
}



/* 0001b1c0 FUN_0001b1c0 */

/* Boundary evidence: original MIPS .pdata 0001b1c0..0001b233. Semantic name remains unreviewed. */

void FUN_0001b1c0(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ec);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x70) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 1;
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ec,1000,(TIMERPROC)0x0);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x70) = 1;
  return;
}



/* 0001b234 FUN_0001b234 */

/* Boundary evidence: original MIPS .pdata 0001b234..0001b2a7. Semantic name remains unreviewed. */

void FUN_0001b234(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ec);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x70) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 1;
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ec,10,(TIMERPROC)0x0);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x70) = 1;
  return;
}



/* 0001b2a8 FUN_0001b2a8 */

/* Boundary evidence: original MIPS .pdata 0001b2a8..0001b2ff. Semantic name remains unreviewed. */

void FUN_0001b2a8(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ed);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 1;
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ed,1000,(TIMERPROC)0x0);
  return;
}



/* 0001b300 FUN_0001b300 */

/* Boundary evidence: original MIPS .pdata 0001b300..0001b373. Semantic name remains unreviewed. */

void FUN_0001b300(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3e9,300,(TIMERPROC)0x0);
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ea,5000,(TIMERPROC)0x0);
  return;
}



/* 0001b374 FUN_0001b374 */

/* Boundary evidence: original MIPS .pdata 0001b374..0001b3af. Semantic name remains unreviewed. */

void FUN_0001b374(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xe60) = 0;
  *(undefined4 *)(param_1 + 0x2930) = param_2;
  iVar1 = FUN_0001144c();
  FUN_00011918(iVar1);
  FUN_0001b300();
  return;
}



/* 0001b3b0 FUN_0001b3b0 */

/* Boundary evidence: original MIPS .pdata 0001b3b0..0001b483. Semantic name remains unreviewed. */

void FUN_0001b3b0(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x2922) == 1) || (*(int *)(param_1 + 0x2922) == 2)) {
    iVar1 = FUN_0001144c();
    iVar1 = FUN_00011230(iVar1);
    if (-1 < iVar1) {
      *(int *)(param_1 + 0xe7c) = iVar1;
    }
    FUN_00019864(param_1,iVar1);
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x40) != 0) {
      iVar1 = FUN_000231a4();
      FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
    }
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x84) == 1) {
      FUN_00023580(5,0x15,0x65,0,(LPARAM *)0x0);
    }
  }
  return;
}



/* 0001b484 FUN_0001b484 */

/* Boundary evidence: original MIPS .pdata 0001b484..0001b543. Semantic name remains unreviewed. */

void FUN_0001b484(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = FUN_0001144c();
    iVar1 = FUN_0001111c(iVar1,param_2);
    if (iVar1 != 0) {
      *(uint *)(param_1 + 0xe7c) = param_2;
    }
  }
  FUN_00019864(param_1,param_2);
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x84) == 1) {
    FUN_00023580(5,0x15,0x65,0,(LPARAM *)0x0);
  }
  return;
}



/* 0001b544 FUN_0001b544 */

/* Boundary evidence: original MIPS .pdata 0001b544..0001b5af. Semantic name remains unreviewed. */

void FUN_0001b544(int param_1,int param_2)

{
  int iVar1;
  
  if (3 < param_2) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x291a) = param_2;
  *(int *)(param_1 + 0x1ab0) = param_2;
  *(int *)(param_1 + 0x2934) = param_2;
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  return;
}



/* 0001b5b0 FUN_0001b5b0 */

/* Boundary evidence: original MIPS .pdata 0001b5b0..0001b66f. Semantic name remains unreviewed. */

void FUN_0001b5b0(int param_1,int param_2)

{
  int iVar1;
  
  if (1 < param_2) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x291e) = param_2;
  *(int *)(param_1 + 0x2938) = param_2;
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x40) != 0) {
    iVar1 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
  }
  *(int *)(param_1 + 0x1ab4) = param_2;
  if (*(int *)(param_1 + 0x291e) == 1) {
    FUN_00019af8(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xe58) = 0;
    *(undefined4 *)(param_1 + 0xe4c) = 0;
    if (*(int *)(param_1 + 0xe5c) != 0) {
      *(undefined4 *)(param_1 + 0xe5c) = 0;
    }
  }
  return;
}



/* 0001b670 FUN_0001b670 */

/* Boundary evidence: original MIPS .pdata 0001b670..0001b75f. Semantic name remains unreviewed. */

void FUN_0001b670(int param_1)

{
  int iVar1;
  wchar_t *_Src;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x2916);
  *(undefined1 *)(param_1 + 0x1ce6) = 0;
  *(undefined1 *)(param_1 + 0x1ce7) = 0;
  *(undefined1 *)(param_1 + 0x1eee) = 0;
  *(undefined1 *)(param_1 + 0x1eef) = 0;
  *(undefined1 *)(param_1 + 0x20f6) = 0;
  *(undefined1 *)(param_1 + 0x20f7) = 0;
  if (-1 < iVar2) {
    iVar1 = FUN_000231a4();
    iVar2 = FUN_00013318(*(int *)(iVar1 + 0x48),iVar2);
    if (iVar2 != 0) {
      iVar1 = *(int *)(param_1 + 0x2916);
      iVar2 = FUN_000231a4();
      _Src = (wchar_t *)FUN_00013318(*(int *)(iVar2 + 0x48),iVar1);
      wcscpy_s((wchar_t *)(param_1 + 0x270e),0x104,_Src);
    }
  }
  iVar2 = FUN_000231a4();
  if (*(int *)(iVar2 + 0x40) != 0) {
    iVar2 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar2 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
    FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
  }
  return;
}



/* 0001b760 FUN_0001b760 */

/* Boundary evidence: original MIPS .pdata 0001b760..0001ba3b. Semantic name remains unreviewed. */

undefined4 FUN_0001b760(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  LPARAM local_28 [2];
  
  if ((param_2 < 5000) && (-1 < param_2)) {
    iVar1 = FUN_000231a4();
    iVar9 = *(int *)(iVar1 + 0x48);
    iVar1 = FUN_00012d5c(iVar9 + 8,0);
    FUN_00019478(param_1 + 0x1ad8);
    iVar2 = FUN_00013334(iVar9,param_2);
    if (iVar2 == -1) {
      FUN_00023aac(5,0,L"%S not support ext","CPlayControl::makeSongInfo");
    }
    else {
      iVar2 = FUN_000132c0(iVar9,param_2);
      if (iVar2 != 0) {
        pwVar3 = (wchar_t *)FUN_00013318(iVar9,param_2);
        wcscpy_s((wchar_t *)(param_1 + 0x270e),0x104,pwVar3);
        FUN_00013f10(iVar9,(int)*(short *)(param_2 * 0x210 + iVar1 + 0x208),
                     (wchar_t *)(param_1 + 0x2506));
        FUN_00019c94(param_1,param_2);
        uVar4 = FUN_00019d3c(param_1,param_2,param_4);
        if (param_3 != 1) {
          return uVar4;
        }
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x40) != 0) {
          iVar1 = FUN_000231a4();
          pwVar3 = (wchar_t *)0xe56;
          uVar6 = 0;
          FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
          iVar1 = FUN_000231a4();
          FUN_0001f34c(*(int *)(iVar1 + 0x4c),param_2,uVar6,pwVar3);
          pwVar3 = (wchar_t *)0x0;
          uVar7 = 100;
          uVar5 = 0x15;
          uVar6 = 5;
          FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
          iVar8 = *(int *)(param_1 + 0x2916);
          local_28[0] = 0;
          iVar1 = FUN_00014db0(uVar6,uVar5,uVar7,pwVar3);
          iVar2 = FUN_000132fc(iVar1,iVar8);
          iVar9 = FUN_00014db0(iVar1,iVar8,uVar7,pwVar3);
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          iVar2 = iVar2 * 0x220 + *(int *)(iVar9 + 0x38);
          if (((*(int *)(param_1 + 0x291e) == 0) && (*(int *)(param_1 + 0x291a) == 0)) &&
             (*(int *)(param_1 + 0x2916) ==
              (int)*(short *)(iVar2 + 0x214) + (int)*(short *)(iVar2 + 0x212) + -1)) {
            iVar1 = FUN_00014db0(iVar1,iVar8,uVar7,pwVar3);
            iVar1 = FUN_000146ec(iVar1);
            if (iVar1 == *(short *)(iVar2 + 0x21a)) {
              local_28[0] = 1;
            }
          }
          FUN_00023580(5,0x15,0x72,4,local_28);
          return uVar4;
        }
        FUN_00023aac(5,3,L"%S getGlobalVal()->m_ocsharedMemory NULL","CPlayControl::makeSongInfo");
        return uVar4;
      }
    }
    FUN_0001b670(param_1);
  }
  else {
    FUN_00023aac(5,3,L"%S over ULC_MAX_FILE_NUM index : %d","CPlayControl::makeSongInfo");
  }
  return 0;
}



/* 0001ba3c FUN_0001ba3c */

/* Boundary evidence: original MIPS .pdata 0001ba3c..0001be4f. Semantic name remains unreviewed. */

undefined4 FUN_0001ba3c(int param_1)

{
  size_t sVar1;
  int iVar2;
  LONG LVar3;
  BOOL BVar4;
  uint uVar5;
  ULARGE_INTEGER local_450;
  ULARGE_INTEGER local_448;
  FILETIME FStack_440;
  ULARGE_INTEGER UStack_438;
  wchar_t local_430 [260];
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_0002f960;
  sVar1 = wcslen((wchar_t *)(param_1 + 0x1088));
  if (sVar1 != 0) {
    iVar2 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar2 + 0x3c),0x3e9);
    iVar2 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar2 + 0x3c),0x3ea);
    memcpy(local_430,(wchar_t *)(param_1 + 0x1088),0x208);
    if (local_430[0] != L'\\') {
      local_228 = L'\0';
      memset(auStack_226,0,0x206);
      swprintf(&local_228,0x29278,local_430);
      memcpy(local_430,&local_228,0x208);
    }
    FUN_0001a69c(param_1,&FStack_440.dwLowDateTime,local_430);
    LVar3 = CompareFileTime(&FStack_440,(FILETIME *)(param_1 + 0x1ac8));
    if (LVar3 == 0) {
      BVar4 = GetDiskFreeSpaceExW(L"MD",&UStack_438,&local_448,&local_450);
      if (BVar4 == 0) {
        FUN_00023aac(5,3,
                     L"%S Line %d tchFolderName %s ++++USB Disk size diffrent+++++++++++++++++++",
                     "CPlayControl::resumePlay");
      }
      else if ((*(DWORD *)(param_1 + 0x1ab8) == local_450.s.LowPart) &&
              (*(DWORD *)(param_1 + 0x1abc) == local_450.s.HighPart)) {
        if ((*(DWORD *)(param_1 + 0x1ac0) == local_448.s.LowPart) &&
           (*(DWORD *)(param_1 + 0x1ac4) == local_448.s.HighPart)) {
          FUN_00019254((wchar_t *)(param_1 + 4),local_430,*(int *)(param_1 + 0xe78),0);
          FUN_0001a318(param_1);
          iVar2 = FUN_0001144c();
          iVar2 = FUN_00012264(iVar2,local_430,*(int *)(param_1 + 0xe78));
          if (iVar2 == 1) {
            memcpy((void *)(param_1 + 0x2506),(void *)(param_1 + 0x18a8),0x208);
            memcpy((void *)(param_1 + 0x1ce6),(void *)(param_1 + 0x1290),0x208);
            memcpy((void *)(param_1 + 0x1eee),(void *)(param_1 + 0x16a0),0x208);
            memcpy((void *)(param_1 + 0x20f6),(void *)(param_1 + 0x1498),0x208);
            memcpy((void *)(param_1 + 0x270e),(void *)(param_1 + 0xe80),0x208);
            iVar2 = FUN_0001144c();
            uVar5 = FUN_0001137c(iVar2);
            FUN_000197e4(param_1,uVar5);
            iVar2 = FUN_0001144c();
            FUN_0001111c(iVar2,*(uint *)(param_1 + 0xe7c));
            FUN_00019864(param_1,*(uint *)(param_1 + 0xe7c));
            iVar2 = FUN_000231a4();
            if (*(int *)(iVar2 + 0x40) != 0) {
              iVar2 = FUN_000231a4();
              FUN_00024094(*(int *)(iVar2 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
            }
            FUN_00023aac(5,0,L"%S resumeTime : %d","CPlayControl::resumePlay");
            FUN_0001ae54(param_1,1);
            *(undefined4 *)(param_1 + 0x292a) = 1;
            iVar2 = FUN_000231a4();
            FUN_0001dc00(*(int *)(iVar2 + 0x4c),1);
            iVar2 = FUN_000231a4();
            if (-1 < *(int *)(iVar2 + 0x74)) {
              iVar2 = FUN_000231a4();
              FUN_00019c94(param_1,*(undefined4 *)(iVar2 + 0x74));
            }
            FUN_0001a9e4(param_1);
            FUN_00023aac(5,1,L"%S Play success","CPlayControl::resumePlay");
            FUN_00025510(local_20);
            return 1;
          }
          FUN_0001b670(param_1);
          FUN_00023aac(5,2,L"%S Line %d doesn\'t suppported file format %s / %d",
                       "CPlayControl::resumePlay");
        }
        else {
          FUN_00023aac(5,3,
                       L"%S Line %d tchFolderName %s ++++USB Disk lpTotalNumberOfBytes diffrent+++++++++++++++++++"
                       ,"CPlayControl::resumePlay");
        }
      }
      else {
        FUN_00023aac(5,3,
                     L"%S Line %d tchFolderName %s ++++USB Disk lpTotalNumberOfFreeBytes diffrent+++++++++++++++++++"
                     ,"CPlayControl::resumePlay");
      }
    }
  }
  FUN_00025510(local_20);
  return 0;
}



/* 0001be50 FUN_0001be50 */

/* Boundary evidence: original MIPS .pdata 0001be50..0001c17b. Semantic name remains unreviewed. */

undefined4 FUN_0001be50(int param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  size_t sVar3;
  DWORD DVar4;
  wchar_t *pwVar5;
  int iVar6;
  byte *lpBuffer;
  DWORD local_268 [2];
  uint local_260 [10];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_0002f960;
  local_268[0] = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    GetLastError();
    FUN_00023aac(5,3,L"%S resume file invalid handle error %d","CPlayControl::loadResumeData");
  }
  else {
    lpBuffer = (byte *)(param_1 + 0xe64);
    BVar1 = ReadFile(hFile,lpBuffer,0xc6c,local_268,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    if (BVar1 == 1) {
      if (local_268[0] == 0xc6c) {
        iVar2 = FUN_0001ab50(param_1,lpBuffer,0xc6c);
        if (iVar2 == 1) {
          FUN_00023aac(5,0,L"%S line: %d, Resume Data Verify Success","CPlayControl::loadResumeData"
                      );
          CloseHandle(hFile);
          *(undefined1 *)(param_1 + 0x128e) = 0;
          *(undefined1 *)(param_1 + 0x128f) = 0;
          sVar3 = wcslen((wchar_t *)(param_1 + 0x1088));
          memcpy(awStack_238,(wchar_t *)(param_1 + 0x1088),0x208);
          iVar2 = sVar3 - 1;
          if (-1 < iVar2) {
            pwVar5 = awStack_238 + iVar2;
            iVar6 = iVar2;
            do {
              if (((*pwVar5 == L'\\') || (iVar6 == iVar2)) &&
                 (sVar3 = wcslen(awStack_238), sVar3 != 0)) {
                if (iVar6 < iVar2) {
                  *pwVar5 = L'\0';
                }
                GetFileAttributesExW(awStack_238,GetFileExInfoStandard,local_260);
                if ((local_260[0] & 2) != 0) {
                  memset(lpBuffer,0,0xc6c);
                  FUN_00023aac(5,3,L"%S %s Resume Data Hidden property",
                               "CPlayControl::loadResumeData");
                  goto LAB_0001c140;
                }
              }
              iVar6 = iVar6 + -1;
              pwVar5 = pwVar5 + -1;
            } while (-1 < iVar6);
          }
          DVar4 = GetFileAttributesW((LPCWSTR)(param_1 + 0x18a8));
          if (DVar4 != 0xffffffff) {
            iVar2 = FUN_000231a4();
            *(undefined4 *)(iVar2 + 0x1c) = 1;
            FUN_00025510(local_30);
            return 1;
          }
          goto LAB_0001c140;
        }
        pwVar5 = L"%S Resume Data Verify Failed";
      }
      else {
        pwVar5 = L"%S Resume Data size is failed";
      }
      FUN_00023aac(5,1,pwVar5,"CPlayControl::loadResumeData");
    }
    else {
      GetLastError();
      FUN_00023aac(5,1,L"%S Resume Data Read Fail %d","CPlayControl::loadResumeData");
    }
    memset(lpBuffer,0,0xc6c);
  }
LAB_0001c140:
  FUN_00025510(local_30);
  return 0;
}



/* 0001c17c FUN_0001c17c */

/* Boundary evidence: original MIPS .pdata 0001c17c..0001c2e7. Semantic name remains unreviewed. */

BOOL FUN_0001c17c(int param_1,LPCWSTR param_2)

{
  int iVar1;
  HANDLE hFile;
  int iVar2;
  char cVar3;
  char *lpBuffer;
  BOOL BVar4;
  DWORD aDStack_20 [2];
  
  BVar4 = 0;
  iVar1 = FUN_000231a4();
  iVar2 = 1;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  lpBuffer = (char *)(param_1 + 0xe64);
  cVar3 = '\0';
  do {
    cVar3 = lpBuffer[iVar2] + cVar3;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc6c);
  *lpBuffer = cVar3;
  hFile = CreateFileW(param_2,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    GetLastError();
    FUN_00023aac(5,3,L"%S (%s)file open error[0x%08x]","CPlayControl::saveResumeData");
  }
  else {
    FUN_00023aac(5,1,L"%S WRITE","CPlayControl::saveResumeData");
    BVar4 = WriteFile(hFile,lpBuffer,0xc6c,aDStack_20,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    FUN_00023aac(5,1,L"%S End","CPlayControl::saveResumeData");
  }
  return BVar4;
}



/* 0001c2e8 FUN_0001c2e8 */

/* Boundary evidence: original MIPS .pdata 0001c2e8..0001c453. Semantic name remains unreviewed. */

BOOL FUN_0001c2e8(int param_1,LPCWSTR param_2)

{
  int iVar1;
  HANDLE hFile;
  int iVar2;
  char cVar3;
  char *lpBuffer;
  BOOL BVar4;
  DWORD aDStack_20 [2];
  
  BVar4 = 0;
  iVar1 = FUN_000231a4();
  iVar2 = 1;
  *(undefined4 *)(iVar1 + 0x1c) = 1;
  lpBuffer = (char *)(param_1 + 0xe64);
  cVar3 = '\0';
  do {
    cVar3 = lpBuffer[iVar2] + cVar3;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0xc6c);
  *lpBuffer = cVar3;
  hFile = CreateFileW(param_2,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    GetLastError();
    FUN_00023aac(5,3,L"%S (%s)file open error[0x%08x]","CPlayControl::deletesaveResumeData");
  }
  else {
    FUN_00023aac(5,1,L"%S WRITE","CPlayControl::deletesaveResumeData");
    BVar4 = WriteFile(hFile,lpBuffer,0xc6c,aDStack_20,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    FUN_00023aac(5,1,L"%S End","CPlayControl::deletesaveResumeData");
  }
  return BVar4;
}



/* 0001c454 FUN_0001c454 */

/* Boundary evidence: original MIPS .pdata 0001c454..0001c4d3. Semantic name remains unreviewed. */

void FUN_0001c454(int param_1)

{
  *(uint *)(param_1 + 0x291e) = (uint)(*(int *)(param_1 + 0x2938) == 1);
  FUN_000231a4();
  FUN_00022f54();
  FUN_0001b544(param_1,*(int *)(param_1 + 0x2934));
  FUN_00023aac(5,0,L"%S  shuffle Mode : %d, repeat Mode : %d",
               "CPlayControl::setResumeShuffleNRepeat");
  return;
}



/* 0001c4d4 FUN_0001c4d4 */

/* Boundary evidence: original MIPS .pdata 0001c4d4..0001c533. Semantic name remains unreviewed. */

undefined4 *
FUN_0001c4d4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = &PTR_FUN_00029050;
  FUN_00017468(param_1 + 1,param_2,param_3,param_4);
  param_1[0xa4d] = 0;
  param_1[0xa4e] = 0;
  FUN_0001ad84((int)param_1);
  return param_1;
}



/* 0001c534 Unwind@0001c534 */

/* Boundary evidence: original MIPS .pdata 0001c534..0001c567. Semantic name remains unreviewed. */

void Unwind_0001c534(void)

{
  FUN_000174f8();
  return;
}



/* 0001c568 FUN_0001c568 */

/* Boundary evidence: original MIPS .pdata 0001c568..0001c66b. Semantic name remains unreviewed. */

void FUN_0001c568(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2922);
  if (((iVar1 != 2) && (iVar1 != 3)) && (iVar1 != 0)) {
    if (param_2 == 0) {
      FUN_0001ae54(param_1,2);
    }
    iVar1 = FUN_0001144c();
    iVar1 = FUN_000113e8(iVar1);
    if (iVar1 == 2) {
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x84) == 1) {
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x84) = 0;
        FUN_0001b3b0(param_1);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x84) = 1;
      }
      else {
        FUN_0001b3b0(param_1);
      }
    }
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
    iVar1 = FUN_0001144c();
    FUN_00011568(iVar1,0);
    FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
  }
  return;
}



/* 0001c66c FUN_0001c66c */

/* Boundary evidence: original MIPS .pdata 0001c66c..0001c697. Semantic name remains unreviewed. */

void FUN_0001c66c(int param_1)

{
  FUN_0001b760(param_1,*(int *)(param_1 + 0x2916),1,1);
  return;
}



/* 0001c698 FUN_0001c698 */

/* Boundary evidence: original MIPS .pdata 0001c698..0001c6df. Semantic name remains unreviewed. */

void FUN_0001c698(int param_1,int param_2)

{
  if (((*(int *)(param_1 + 0x1ad0) == 0) || (param_2 != 0)) &&
     (*(int *)(param_1 + 0x1ad0) = *(int *)(param_1 + 0x2922), *(int *)(param_1 + 0x2922) == 1)) {
    FUN_0001c568(param_1,1);
  }
  return;
}



/* 0001c6e0 FUN_0001c6e0 */

/* Boundary evidence: original MIPS .pdata 0001c6e0..0001cd93. Semantic name remains unreviewed. */

undefined4 FUN_0001c6e0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  wchar_t *pwVar6;
  int iVar7;
  char *pcVar8;
  LPARAM local_1078 [2];
  wchar_t local_1070;
  undefined1 auStack_106e [2078];
  wchar_t local_850;
  undefined1 auStack_84e [2078];
  uint local_30;
  
  local_30 = DAT_0002f960;
  iVar2 = FUN_000231a4();
  if (*(int *)(iVar2 + 0x30) == 0) goto LAB_0001cd58;
  local_1070 = L'\0';
  memset(auStack_106e,0,0x81e);
  FUN_00019760(param_1,1);
  iVar2 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar2 + 0x3c),1000);
  FUN_0001af28(param_1);
  iVar2 = FUN_000231a4();
  FUN_00013350(*(int *)(iVar2 + 0x48),param_2,&local_1070);
  if (local_1070 != L'\\') {
    local_850 = L'\0';
    memset(auStack_84e,0,0x81e);
    swprintf(&local_850,0x29278,&local_1070);
    memcpy(&local_1070,&local_850,0x81f);
  }
  iVar2 = FUN_000231a4();
  iVar2 = FUN_00013334(*(int *)(iVar2 + 0x48),param_2);
  iVar3 = FUN_0001b760(param_1,param_2,1,0);
  pcVar8 = "CPlayControl::play";
  if (iVar3 == 0) {
    iVar2 = 2;
LAB_0001c818:
    FUN_00023aac(5,2,L"%S doesn\'t suppported file format %s","CPlayControl::play");
  }
  else {
    FUN_0001a318(param_1);
    iVar3 = FUN_0001144c();
    iVar2 = FUN_00012264(iVar3,&local_1070,iVar2);
    if (iVar2 != 1) goto LAB_0001c818;
    iVar3 = FUN_000231a4();
    *(int *)(iVar3 + 0x74) = param_2;
    FUN_0001a7d0(param_1,-1);
  }
  FUN_00023aac(5,1,L"%S index=%d path=%s / %d","CPlayControl::play");
  if (iVar2 == 1) {
    iVar2 = FUN_0001144c();
    uVar4 = FUN_0001137c(iVar2);
    FUN_000197e4(param_1,uVar4);
    FUN_0001b17c();
    FUN_0001ae54(param_1,1);
    iVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0);
    if ((((param_4 == 0) && (iVar3 = FUN_000231a4(), *(int *)(iVar3 + 0x34) == 0)) && (iVar2 == 0))
       && (iVar3 = FUN_000231a4(), *(int *)(iVar3 + 0x30) == 1)) {
      FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
      iVar2 = FUN_0001144c();
      FUN_000114a0(iVar2);
    }
    else {
      if (*(int *)(param_1 + 0x1ad0) == 2) {
        iVar2 = 0;
      }
      else {
        if ((iVar2 != 0) && (iVar2 = FUN_000231a4(), 0 < *(int *)(iVar2 + 0x38))) {
          iVar2 = FUN_000231a4();
          FUN_0001a7d0(param_1,*(int *)(iVar2 + 0x74));
          iVar2 = FUN_000231a4();
          FUN_0001c17c(*(int *)(iVar2 + 0x4c) + 8,L"\\Storage Card2\\USBMusicResume.dat");
        }
        if ((*(int *)(param_1 + 0x1ad0) != 0) ||
           (*(int *)(param_1 + 0x1ad0) = *(int *)(param_1 + 0x2922), *(int *)(param_1 + 0x2922) != 1
           )) goto LAB_0001c9fc;
        iVar2 = 1;
      }
      FUN_0001c568(param_1,iVar2);
    }
LAB_0001c9fc:
    iVar2 = FUN_000231a4();
    if (*(int *)(iVar2 + 0x1c) == 0) {
      FUN_00023580(5,0x15,0x6f,0,(LPARAM *)0x0);
      iVar2 = FUN_000231a4();
      *(undefined4 *)(iVar2 + 0x1c) = 1;
    }
    FUN_00019c94(param_1,param_2);
    *(undefined4 *)(param_1 + 0x292a) = 0;
    FUN_00023580(0x15,5,0x79,0,(LPARAM *)0x0);
    *(undefined4 *)(param_1 + 0x1ad4) = 1;
    FUN_000231a4();
    FUN_00023aac(5,3,L"%S Play success => LastPlayedIndex = %d","CPlayControl::play");
    FUN_00025510(local_30);
    return 1;
  }
  iVar2 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar2 + 0x3c),1000);
  FUN_0001a60c(param_1);
  FUN_0001ae54(param_1,1);
  iVar2 = FUN_000231a4();
  if (*(int *)(iVar2 + 0x30) == 0) {
    iVar2 = FUN_000231a4();
    FUN_00019c94(param_1,*(undefined4 *)(iVar2 + 0x74));
    *(undefined4 *)(param_1 + 0x1ad0) = 0;
    FUN_00023aac(5,3,
                 L"%S Line %d ++++++++ getGlobalVal()->m_bAudioPathUSBStatus == FALSE +++++++++++++++++"
                 ,"CPlayControl::play");
  }
  FUN_000231a4();
  pwVar6 = 
  L"%S nRet => FILE_LOAD_FAIL // bErrProc=%d // nMediaIndex=%d // m_bDevRemove=%d //bVirtualPause=%d"
  ;
  iVar2 = 2;
  FUN_00023aac(5,2,
               L"%S nRet => FILE_LOAD_FAIL // bErrProc=%d // nMediaIndex=%d // m_bDevRemove=%d //bVirtualPause=%d"
               ,"CPlayControl::play");
  if (param_5 == 0) {
    FUN_00023580(0x15,5,0x76,0,(LPARAM *)0x0);
    goto LAB_0001cd58;
  }
  iVar3 = FUN_000231a4();
  if (*(int *)(iVar3 + 0x30) == 1) {
    FUN_00019c94(param_1,param_2);
    iVar2 = param_2;
  }
  iVar3 = FUN_000231a4();
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  iVar3 = FUN_000231a4();
  if ((*(int *)(iVar3 + 0x18) == 0) && (param_4 == 0)) {
    iVar7 = *(int *)(param_1 + 0x2916);
    local_1078[0] = 0;
    iVar2 = FUN_00014db0(0,iVar2,pwVar6,(wchar_t *)pcVar8);
    iVar3 = FUN_000132fc(iVar2,iVar7);
    iVar5 = FUN_00014db0(iVar2,iVar7,pwVar6,(wchar_t *)pcVar8);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar5 = iVar3 * 0x220 + *(int *)(iVar5 + 0x38);
    iVar3 = (int)*(short *)(iVar5 + 0x214) + (int)*(short *)(iVar5 + 0x212);
    if (((*(int *)(param_1 + 0x291e) == 0) && (*(int *)(param_1 + 0x291a) == 0)) &&
       (*(int *)(param_1 + 0x2916) == iVar3 + -1)) {
      sVar1 = *(short *)(iVar5 + 0x21a);
      iVar2 = FUN_00014db0(iVar2,iVar7,pwVar6,(wchar_t *)pcVar8);
      iVar2 = FUN_000146ec(iVar2);
      if (iVar2 != sVar1) goto LAB_0001cd04;
      if ((iVar3 == 1) && (sVar1 == 0)) {
        iVar2 = FUN_000231a4();
        iVar2 = FUN_00012ebc(*(int *)(iVar2 + 0x48));
        if (iVar2 < 2) goto LAB_0001ccdc;
        iVar2 = FUN_000231a4();
        if (*(int *)(*(int *)(iVar2 + 0x4c) + 4) != 0) {
          FUN_00019c94(param_1,1);
          iVar2 = FUN_000231a4();
          *(undefined4 *)(iVar2 + 0x74) = 1;
        }
        local_1078[0] = 0;
        FUN_00023580(5,0x15,0x71,4,local_1078);
      }
      else {
LAB_0001ccdc:
        local_1078[0] = 1;
        FUN_00023580(5,0x15,0x73,4,local_1078);
      }
    }
    else {
LAB_0001cd04:
      local_1078[0] = 0;
      FUN_00023580(5,0x15,0x71,4,local_1078);
    }
    FUN_00023580(5,0x15,0x6e,0,(LPARAM *)0x0);
  }
  *(undefined4 *)(param_1 + 0x1ad4) = 0;
  FUN_00023580(0x15,5,0x79,0,(LPARAM *)0x0);
LAB_0001cd58:
  FUN_00025510(local_30);
  return 0;
}



/* 0001cd94 FUN_0001cd94 */

/* Boundary evidence: original MIPS .pdata 0001cd94..0001cf37. Semantic name remains unreviewed. */

void FUN_0001cd94(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  FUN_00023aac(5,1,L"%S Enter resume play","CPlayControl::remainPlay");
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
  iVar1 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
  if (iVar1 != 0) {
    if ((param_2 == 0) || (param_3 == 1)) {
      FUN_0001ae54(param_1,1);
      FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
    }
    iVar1 = FUN_0001144c();
    FUN_0001111c(iVar1,*(uint *)(param_1 + 0xe7c));
    iVar1 = FUN_0001144c();
    iVar1 = FUN_000114a0(iVar1);
    if (iVar1 == 0) {
      uVar2 = *(uint *)(param_1 + 0xe7c);
      FUN_0001c6e0(param_1,*(int *)(param_1 + 0x2916),1,0,1);
      iVar1 = FUN_0001144c();
      FUN_0001111c(iVar1,uVar2);
    }
    else {
      FUN_0001b17c();
      if (param_3 == 0) {
        FUN_0001a9e4(param_1);
      }
    }
    GetTickCount();
    FUN_00023aac(5,1,L"%S ********************Process TIME : %d ms*********************",
                 "CPlayControl::remainPlay");
  }
  return;
}



/* 0001cf38 FUN_0001cf38 */

/* Boundary evidence: original MIPS .pdata 0001cf38..0001d143. Semantic name remains unreviewed. */

void FUN_0001cf38(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_000231a4();
  iVar1 = *(int *)(iVar1 + 0x48);
  FUN_00012ebc(iVar1);
  if (*(int *)(param_1 + 0x291e) == 0) {
    piVar4 = (int *)(param_1 + 0x2916);
    iVar1 = FUN_0001afbc(param_1,*piVar4);
    if (iVar1 == *piVar4) {
      iVar1 = FUN_0001afbc(param_1,*piVar4);
    }
    FUN_00019c94(param_1,iVar1);
    iVar1 = *piVar4;
  }
  else {
    if ((*(int *)(param_1 + 0x291a) == 1) && (*(int *)(param_1 + 0x1ad4) == 0)) {
      iVar1 = FUN_00014db0(iVar1,(int *)(param_1 + 0x291e),param_3,param_4);
      iVar3 = *(int *)(param_1 + 0x2916);
      iVar2 = FUN_000132fc(iVar1,iVar3);
      iVar1 = FUN_00014db0(iVar1,iVar3,param_3,param_4);
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      iVar3 = *(int *)(param_1 + 0x2916) + 1;
      iVar1 = iVar2 * 0x220 + *(int *)(iVar1 + 0x38);
      if ((int)*(short *)(iVar1 + 0x214) + (int)*(short *)(iVar1 + 0x212) + -1 < iVar3) {
        iVar1 = FUN_000231a4();
        KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ec);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x78) = 0;
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x70) = 0;
        FUN_0001af28(param_1);
        FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
        return;
      }
      FUN_0001c6e0(param_1,iVar3,3,0,1);
      return;
    }
    iVar1 = *(int *)(param_1 + 0xe58) + 1;
    *(int *)(param_1 + 0xe58) = iVar1;
    if (*(int *)(param_1 + 0xe4c) <= iVar1) {
      *(undefined4 *)(param_1 + 0xe58) = 0;
    }
    if (*(int *)(param_1 + 0xe5c) == 0) {
      FUN_00019c94(param_1,0);
      iVar1 = 0;
    }
    else {
      FUN_00019c94(param_1,*(undefined4 *)
                            (*(int *)(param_1 + 0xe58) * 4 + *(int *)(param_1 + 0xe5c)));
      iVar1 = *(int *)(*(int *)(param_1 + 0xe58) * 4 + *(int *)(param_1 + 0xe5c));
    }
  }
  FUN_0001b760(param_1,iVar1,1,0);
  return;
}



/* 0001d144 FUN_0001d144 */

/* Boundary evidence: original MIPS .pdata 0001d144..0001d1af. Semantic name remains unreviewed. */

void FUN_0001d144(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x1ad0) == 1) {
    FUN_00023aac(5,3,L"%S m_nBFVirtualStatus = %d","CPlayControl::virtualResume");
    FUN_0001cd94(param_1,1,param_2);
  }
  *(undefined4 *)(param_1 + 0x1ad0) = 0;
  return;
}



/* 0001d1b0 FUN_0001d1b0 */

/* Boundary evidence: original MIPS .pdata 0001d1b0..0001d23b. Semantic name remains unreviewed. */

void FUN_0001d1b0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2930) != 0) {
    *(undefined4 *)(param_1 + 0xe60) = 0;
    *(undefined4 *)(param_1 + 0x2930) = 0;
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
    if ((*(int *)(param_1 + 0x2922) == 1) && (*(int *)(param_1 + 0x1ad0) == 0)) {
      FUN_0001cd94(param_1,0,0);
    }
  }
  return;
}



/* 0001d23c FUN_0001d23c */

/* Boundary evidence: original MIPS .pdata 0001d23c..0001d78b. Semantic name remains unreviewed. */

void FUN_0001d23c(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  
  pcVar5 = "CPlayControl::dshowEndAutoNextPlay";
  pwVar4 = L"%S dshowEndAutoNextPlay";
  FUN_00023aac(5,0,L"%S dshowEndAutoNextPlay","CPlayControl::dshowEndAutoNextPlay");
  uVar3 = 1;
  FUN_00019760(param_1,1);
  FUN_0001abe0();
  FUN_0001d1b0(param_1);
  iVar1 = FUN_000231a4();
  iVar1 = *(int *)(iVar1 + 0x48);
  FUN_00012ebc(iVar1);
  piVar9 = (int *)(param_1 + 0x2916);
  iVar6 = *(int *)(param_1 + 0x291a);
  iVar8 = *piVar9;
  if (iVar6 == 3) {
    FUN_0001cf38(param_1,uVar3,pwVar4,(wchar_t *)pcVar5);
    FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
  }
  else if (iVar6 == 1) {
    FUN_0001c6e0(param_1,iVar8,3,0,1);
  }
  else if (iVar6 == 2) {
    if (*(int *)(param_1 + 0x291e) == 0) {
      iVar6 = FUN_00014db0(iVar1,uVar3,pwVar4,(wchar_t *)pcVar5);
      iVar1 = iVar8;
      iVar2 = FUN_000132fc(iVar6,iVar8);
      iVar1 = FUN_00014db0(iVar6,iVar1,pwVar4,(wchar_t *)pcVar5);
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      iVar6 = iVar2 * 0x220 + *(int *)(iVar1 + 0x38);
      iVar1 = (int)*(short *)(iVar6 + 0x212);
      if ((iVar8 < iVar1) || (*(short *)(iVar6 + 0x214) + iVar1 + -1 <= iVar8)) {
        FUN_0001c6e0(param_1,iVar1,3,0,1);
      }
      else {
        FUN_0001cf38(param_1,iVar1,pwVar4,(wchar_t *)pcVar5);
        FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
      }
    }
    else {
      iVar6 = *(int *)(param_1 + 0xe58);
      iVar8 = *(int *)(param_1 + 0xe5c);
      iVar1 = FUN_00014db0(iVar1,uVar3,pwVar4,(wchar_t *)pcVar5);
      iVar2 = *(int *)(iVar6 * 4 + iVar8);
      iVar6 = FUN_000132fc(iVar1,iVar2);
      iVar8 = FUN_00014db0(iVar1,iVar2,pwVar4,(wchar_t *)pcVar5);
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      iVar7 = *(int *)(param_1 + 0xe58);
      iVar6 = iVar6 * 0x220 + *(int *)(iVar8 + 0x38);
      if (iVar7 + 1 < *(int *)(param_1 + 0xe4c)) {
        iVar8 = *(int *)(param_1 + 0xe5c);
        iVar1 = FUN_00014db0(iVar1,iVar2,pwVar4,(wchar_t *)pcVar5);
        iVar2 = *(int *)((iVar7 + 1) * 4 + iVar8);
        iVar8 = FUN_000132fc(iVar1,iVar2);
        iVar1 = FUN_00014db0(iVar1,iVar2,pwVar4,(wchar_t *)pcVar5);
        if (iVar8 < 0) {
          iVar8 = 0;
        }
        if (*(short *)(iVar6 + 0x21a) == *(short *)(iVar8 * 0x220 + *(int *)(iVar1 + 0x38) + 0x21a))
        {
          FUN_0001cf38(param_1,iVar2,pwVar4,(wchar_t *)pcVar5);
          FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
          return;
        }
        iVar1 = (*(int *)(param_1 + 0xe58) - (int)*(short *)(iVar6 + 0x214)) + 1;
        *(int *)(param_1 + 0xe58) = iVar1;
      }
      else {
        iVar1 = (iVar7 - *(short *)(iVar6 + 0x214)) + 1;
        *(int *)(param_1 + 0xe58) = iVar1;
      }
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0xe58) = 0;
      }
      FUN_0001c6e0(param_1,*(int *)(*(int *)(param_1 + 0xe58) * 4 + *(int *)(param_1 + 0xe5c)),3,0,1
                  );
    }
  }
  else if (*(int *)(param_1 + 0x291e) == 0) {
    iVar6 = FUN_00014db0(iVar1,uVar3,pwVar4,(wchar_t *)pcVar5);
    iVar1 = iVar8;
    iVar2 = FUN_000132fc(iVar6,iVar8);
    iVar7 = FUN_00014db0(iVar6,iVar1,pwVar4,(wchar_t *)pcVar5);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = iVar2 * 0x220 + *(int *)(iVar7 + 0x38);
    if ((iVar8 < *(short *)(iVar2 + 0x212)) ||
       ((int)*(short *)(iVar2 + 0x214) + (int)*(short *)(iVar2 + 0x212) + -1 <= iVar8)) {
      iVar6 = FUN_00014db0(iVar6,iVar1,pwVar4,(wchar_t *)pcVar5);
      iVar6 = FUN_000146ec(iVar6);
      if (iVar6 == *(short *)(iVar2 + 0x21a)) {
        *(undefined1 *)(param_1 + 0x1ad9) = *(undefined1 *)(param_1 + 0x1adc);
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x40) != 0) {
          iVar1 = FUN_000231a4();
          FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
        }
        FUN_00023580(5,0x15,0x65,0,(LPARAM *)0x0);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x1c) = 0;
        FUN_0001af28(param_1);
        FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
        *(undefined1 *)(param_1 + 0x1ada) = *(undefined1 *)(param_1 + 0x1add);
        *(undefined1 *)(param_1 + 0x1ad8) = *(undefined1 *)(param_1 + 0x1adb);
        *(undefined1 *)(param_1 + 0x1ad9) = *(undefined1 *)(param_1 + 0x1adc);
      }
      else {
        FUN_0001cf38(param_1,iVar1,pwVar4,(wchar_t *)pcVar5);
        FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
      }
    }
    else {
      FUN_0001cf38(param_1,iVar1,pwVar4,(wchar_t *)pcVar5);
      FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
    }
  }
  else if (*(int *)(param_1 + 0xe58) < *(int *)(param_1 + 0xe4c) + -1) {
    FUN_0001cf38(param_1,uVar3,pwVar4,(wchar_t *)pcVar5);
    FUN_0001c6e0(param_1,*piVar9,3,(uint)(*(int *)(param_1 + 0x1ad0) != 0),1);
  }
  else {
    FUN_0001af28(param_1);
    FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
  }
  return;
}



/* 0001d78c FUN_0001d78c */

/* Boundary evidence: original MIPS .pdata 0001d78c..0001d87f. Semantic name remains unreviewed. */

void FUN_0001d78c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_000231a4();
  FUN_00012ebc(*(int *)(iVar1 + 0x48));
  FUN_0001d1b0(param_1);
  if (*(int *)(param_1 + 0x291e) == 0) {
    piVar2 = (int *)(param_1 + 0x2916);
    iVar1 = FUN_00019564(param_1,*piVar2,0);
    if (iVar1 == *piVar2) {
      iVar1 = FUN_00019564(param_1,*piVar2,0);
    }
    FUN_00019c94(param_1,iVar1);
    iVar1 = *piVar2;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe58) + -1;
    *(int *)(param_1 + 0xe58) = iVar1;
    if (iVar1 < 0) {
      *(int *)(param_1 + 0xe58) = *(int *)(param_1 + 0xe4c) + -1;
    }
    FUN_00019c94(param_1,*(undefined4 *)(*(int *)(param_1 + 0xe58) * 4 + *(int *)(param_1 + 0xe5c)))
    ;
    iVar1 = *(int *)(*(int *)(param_1 + 0xe58) * 4 + *(int *)(param_1 + 0xe5c));
  }
  FUN_0001b760(param_1,iVar1,1,0);
  return;
}



/* 0001d880 FUN_0001d880 */

/* Boundary evidence: original MIPS .pdata 0001d880..0001dacb. Semantic name remains unreviewed. */

void FUN_0001d880(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x2930) == 1) {
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
    iVar1 = FUN_0001144c();
    FUN_00011790(iVar1);
    iVar1 = FUN_0001144c();
    uVar2 = FUN_0001137c(iVar1);
    iVar1 = FUN_0001144c();
    iVar1 = FUN_00011230(iVar1);
    if (*(int *)(param_1 + 0xe60) == 0) {
      uVar3 = iVar1 + 3;
    }
    else {
      uVar3 = *(int *)(param_1 + 0xe60) * 3 + iVar1;
    }
    if ((int)uVar2 <= (int)uVar3) {
      FUN_00019760(param_1,1);
      iVar1 = FUN_0001144c();
      FUN_0001111c(iVar1,uVar2);
      FUN_00019864(param_1,uVar2);
      if ((*(int *)(param_1 + 0x2922) == 1) || (*(int *)(param_1 + 0x2922) == 2)) {
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x40) != 0) {
          iVar1 = FUN_000231a4();
          FUN_00024094(*(int *)(iVar1 + 0x40),(void *)(param_1 + 0x1ad8),0,0xe56);
        }
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x84) == 1) {
          FUN_00023580(5,0x15,0x65,0,(LPARAM *)0x0);
        }
      }
      *(undefined4 *)(param_1 + 0xe60) = 0;
      *(undefined4 *)(param_1 + 0x2930) = 0;
      iVar1 = FUN_000231a4();
      KillTimer(*(HWND *)(iVar1 + 0x3c),0x3e9);
      iVar1 = FUN_000231a4();
      KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
      FUN_0001d23c(param_1);
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x2930) != 2) {
      FUN_0001d1b0(param_1);
      return;
    }
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),1000);
    iVar1 = FUN_0001144c();
    FUN_00011790(iVar1);
    iVar1 = FUN_0001144c();
    iVar1 = FUN_00011230(iVar1);
    if (*(int *)(param_1 + 0xe60) == 0) {
      uVar3 = iVar1 - 3;
    }
    else {
      uVar3 = iVar1 + *(int *)(param_1 + 0xe60) * -3;
    }
    if ((int)uVar3 < 0) {
      uVar3 = 0;
      *(undefined4 *)(param_1 + 0xe60) = 0;
    }
  }
  iVar1 = FUN_0001144c();
  FUN_0001111c(iVar1,uVar3);
  FUN_00019864(param_1,uVar3);
  FUN_0001b3b0(param_1);
  return;
}



/* 0001dacc FUN_0001dacc */

/* Boundary evidence: original MIPS .pdata 0001dacc..0001db4b. Semantic name remains unreviewed. */

void FUN_0001dacc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00029fd4;
  if (DAT_00034f28 != (undefined4 *)0x0) {
    (**(code **)*DAT_00034f28)(DAT_00034f28,1);
    DAT_00034f28 = (undefined4 *)0x0;
  }
  FUN_00019508(param_1 + 2);
  return;
}



/* 0001db4c Unwind@0001db4c */

/* Boundary evidence: original MIPS .pdata 0001db4c..0001db7f. Semantic name remains unreviewed. */

void Unwind_0001db4c(void)

{
  int *in_v0;
  
  FUN_00019508((undefined4 *)(*in_v0 + 8));
  return;
}



/* 0001db80 FUN_0001db80 */

/* Boundary evidence: original MIPS .pdata 0001db80..0001dbff. Semantic name remains unreviewed. */

void FUN_0001db80(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x9a358) = 0;
  memset((void *)(param_1 + 0x294c),0,0x977fc);
  memset((void *)(param_1 + 0x9a148),0,4);
  memset((void *)(param_1 + 0x9a14c),0,0x20a);
  FUN_0001ad84(param_1 + 8);
  return;
}



/* 0001dc00 FUN_0001dc00 */

/* Boundary evidence: original MIPS .pdata 0001dc00..0001dc1b. Semantic name remains unreviewed. */

void FUN_0001dc00(int param_1,int param_2)

{
  FUN_0001c698(param_1 + 8,param_2);
  return;
}



/* 0001dc1c FUN_0001dc1c */

/* Boundary evidence: original MIPS .pdata 0001dc1c..0001dc63. Semantic name remains unreviewed. */

void FUN_0001dc1c(int param_1,int param_2)

{
  if (param_2 != 0) {
    FUN_0001ba3c(param_1 + 8);
  }
  FUN_0001d144(param_1 + 8,param_2);
  return;
}



/* 0001dc64 FUN_0001dc64 */

/* Boundary evidence: original MIPS .pdata 0001dc64..0001dc7f. Semantic name remains unreviewed. */

void FUN_0001dc64(int param_1,undefined4 param_2)

{
  FUN_0001ae54(param_1 + 8,param_2);
  return;
}



/* 0001dc80 FUN_0001dc80 */

undefined4 FUN_0001dc80(int param_1)

{
  return *(undefined4 *)(param_1 + 0x292a);
}



/* 0001dc90 FUN_0001dc90 */

undefined4 FUN_0001dc90(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2938);
}



/* 0001dc98 FUN_0001dc98 */

undefined4 FUN_0001dc98(int param_1)

{
  return *(undefined4 *)(param_1 + 0x291e);
}



/* 0001dca8 FUN_0001dca8 */

/* Boundary evidence: original MIPS .pdata 0001dca8..0001dccb. Semantic name remains unreviewed. */

void FUN_0001dca8(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  FUN_0001c6e0(param_1 + 8,param_2,param_3,param_4,param_5);
  return;
}



/* 0001dccc FUN_0001dccc */

/* Boundary evidence: original MIPS .pdata 0001dccc..0001dce7. Semantic name remains unreviewed. */

void FUN_0001dccc(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  FUN_0001cf38(param_1 + 8,param_2,param_3,param_4);
  return;
}



/* 0001dce8 FUN_0001dce8 */

/* Boundary evidence: original MIPS .pdata 0001dce8..0001dd03. Semantic name remains unreviewed. */

void FUN_0001dce8(int param_1)

{
  FUN_0001d78c(param_1 + 8);
  return;
}



/* 0001dd04 FUN_0001dd04 */

/* Boundary evidence: original MIPS .pdata 0001dd04..0001dd1f. Semantic name remains unreviewed. */

void FUN_0001dd04(int param_1)

{
  FUN_0001af28(param_1 + 8);
  return;
}



/* 0001dd20 FUN_0001dd20 */

/* Boundary evidence: original MIPS .pdata 0001dd20..0001dd3b. Semantic name remains unreviewed. */

void FUN_0001dd20(int param_1,int param_2)

{
  FUN_0001c568(param_1 + 8,param_2);
  return;
}



/* 0001dd3c FUN_0001dd3c */

/* Boundary evidence: original MIPS .pdata 0001dd3c..0001dd5b. Semantic name remains unreviewed. */

void FUN_0001dd3c(int param_1,int param_2)

{
  FUN_0001cd94(param_1 + 8,param_2,0);
  return;
}



/* 0001dd5c FUN_0001dd5c */

/* Boundary evidence: original MIPS .pdata 0001dd5c..0001dd77. Semantic name remains unreviewed. */

void FUN_0001dd5c(int param_1,int param_2)

{
  FUN_00019864(param_1 + 8,param_2);
  return;
}



/* 0001dd78 FUN_0001dd78 */

/* Boundary evidence: original MIPS .pdata 0001dd78..0001dd93. Semantic name remains unreviewed. */

void FUN_0001dd78(int param_1)

{
  FUN_0001accc(param_1 + 8);
  return;
}



/* 0001dd94 FUN_0001dd94 */

/* Boundary evidence: original MIPS .pdata 0001dd94..0001ddaf. Semantic name remains unreviewed. */

void FUN_0001dd94(int param_1,int param_2)

{
  FUN_0001b5b0(param_1 + 8,param_2);
  return;
}



/* 0001ddb0 FUN_0001ddb0 */

/* Boundary evidence: original MIPS .pdata 0001ddb0..0001ddcb. Semantic name remains unreviewed. */

void FUN_0001ddb0(int param_1,int param_2)

{
  FUN_00019ae0(param_1 + 8,param_2);
  return;
}



/* 0001ddcc FUN_0001ddcc */

/* Boundary evidence: original MIPS .pdata 0001ddcc..0001dde7. Semantic name remains unreviewed. */

void FUN_0001ddcc(int param_1,int param_2)

{
  FUN_0001b544(param_1 + 8,param_2);
  return;
}



/* 0001dde8 FUN_0001dde8 */

/* Boundary evidence: original MIPS .pdata 0001dde8..0001de03. Semantic name remains unreviewed. */

void FUN_0001dde8(void)

{
  FUN_000197bc();
  return;
}



/* 0001de04 FUN_0001de04 */

/* Boundary evidence: original MIPS .pdata 0001de04..0001de1f. Semantic name remains unreviewed. */

void FUN_0001de04(int param_1)

{
  FUN_0001d23c(param_1 + 8);
  return;
}



/* 0001de20 FUN_0001de20 */

/* Boundary evidence: original MIPS .pdata 0001de20..0001de3b. Semantic name remains unreviewed. */

void FUN_0001de20(int param_1,undefined4 param_2)

{
  FUN_0001b374(param_1 + 8,param_2);
  return;
}



/* 0001de3c FUN_0001de3c */

/* Boundary evidence: original MIPS .pdata 0001de3c..0001de57. Semantic name remains unreviewed. */

void FUN_0001de3c(int param_1)

{
  FUN_0001d1b0(param_1 + 8);
  return;
}



/* 0001de58 FUN_0001de58 */

/* Boundary evidence: original MIPS .pdata 0001de58..0001e3d3. Semantic name remains unreviewed. */

undefined4 FUN_0001de58(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  int *piVar7;
  short *psVar8;
  int iVar9;
  wchar_t *_Str;
  int iVar10;
  size_t _Count;
  wchar_t *_Dest;
  int local_260;
  int local_25c;
  int *local_254;
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
  local_30 = DAT_0002f960;
  iVar2 = FUN_000231a4();
  iVar9 = param_2;
  if (param_2 < 0) {
    iVar9 = 0;
  }
  iVar9 = iVar9 * 0x220 + *(int *)(*(int *)(iVar2 + 0x48) + 0x38);
  if (iVar9 != 0) {
    iVar6 = (int)*(short *)(iVar9 + 0x214);
    local_25c = (int)*(short *)(iVar9 + 0x212);
    memset((void *)(param_1 + 0x294c),0,0x977fc);
    FUN_00023aac(5,1,L"%S Line %d nRootIdx : %d","CUSBMgr::getUSBFile");
    iVar2 = FUN_000231a4();
    iVar2 = FUN_00012d5c(*(int *)(iVar2 + 0x48) + 8,0);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x9a144) = param_2;
      iVar3 = FUN_000231a4();
      *(bool *)(param_1 + 0x2950) = *(int *)(*(int *)(iVar3 + 0x48) + 0x20) == 0;
      iVar3 = FUN_000231a4();
      FUN_00013f10(*(undefined4 *)(iVar3 + 0x48),param_2,(wchar_t *)(param_1 + 0x295c));
      if (0 < *(short *)(iVar9 + 0x210)) {
        sVar1 = *(short *)(iVar9 + 0x21a);
        iVar3 = FUN_000231a4();
        iVar3 = FUN_000149e0(*(int *)(iVar3 + 0x48),(int)sVar1);
        if (iVar3 < 3) {
          iVar3 = (int)*(short *)(iVar9 + 0x21a);
          iVar9 = FUN_000231a4();
          if (iVar3 < 0) {
            iVar3 = 0;
          }
          iVar9 = iVar3 * 0x220 + *(int *)(*(int *)(iVar9 + 0x48) + 0x38);
          if (iVar9 == 0) goto LAB_0001dec8;
          iVar3 = 0;
          if (0 < *(short *)(iVar9 + 0x210)) {
            do {
              iVar10 = *(short *)(iVar9 + 0x20e) + iVar3;
              iVar4 = FUN_000231a4();
              if (iVar10 < 0) {
                iVar10 = 0;
              }
              iVar4 = iVar10 * 0x220 + *(int *)(*(int *)(iVar4 + 0x48) + 0x38);
              if ((iVar4 != 0) && (0 < *(int *)(iVar4 + 0x21c))) {
                *(undefined1 *)(param_1 + 0x2951) = 1;
                break;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(short *)(iVar9 + 0x210));
          }
        }
      }
      iVar9 = 0;
      if (0 < iVar6) {
        iVar3 = local_25c * 0x108;
        _Dest = (wchar_t *)(param_1 + 0x2b64);
        _Str = (wchar_t *)(local_25c * 0x210 + iVar2);
        local_254 = (int *)(param_1 + 0x95324);
        local_260 = iVar6;
        do {
          if (*_Str == L'\\') {
            local_238 = L'\0';
            memset(auStack_236,0,0x206);
            _Count = 0;
            sVar5 = wcslen(_Str);
            if (0 < (int)sVar5) {
              psVar8 = (short *)((iVar3 + sVar5) * 2 + iVar2);
              do {
                if (*psVar8 == 0x5c) {
                  wcsncpy(&local_238,(wchar_t *)((iVar3 + sVar5 + 1) * 2 + iVar2),_Count);
                  break;
                }
                _Count = _Count + 1;
                sVar5 = sVar5 - 1;
                psVar8 = psVar8 + -1;
              } while (0 < (int)sVar5);
            }
            FUN_00023aac(5,0,L"%S %d setFile Name : %s === 22 ====","CUSBMgr::getUSBFile");
            wcsncpy(_Dest,&local_238,0x3b);
            *(undefined1 *)(_Dest + 0x3b) = 0;
            *(undefined1 *)((int)_Dest + 0x77) = 0;
            FUN_00023aac(5,0,L"%S %d tchTitle Name : %s === 33 ===","CUSBMgr::getUSBFile");
          }
          else {
            memcpy(_Dest,_Str,0x78);
            *(undefined1 *)(_Dest + 0x3b) = 0;
            *(undefined1 *)((int)_Dest + 0x77) = 0;
          }
          *local_254 = local_25c;
          if (*(int *)(_Str + 0x105) == 0) {
            *(undefined4 *)(param_1 + 0x2958) = 1;
          }
          else {
            *(undefined4 *)(param_1 + 0x2958) = 2;
          }
          local_260 = local_260 + -1;
          local_254 = local_254 + 1;
          local_25c = local_25c + 1;
          iVar3 = iVar3 + 0x108;
          _Str = _Str + 0x108;
          _Dest = _Dest + 0x3c;
          iVar9 = iVar6;
        } while (local_260 != 0);
      }
      *(int *)(param_1 + 0x294c) = iVar9;
      FUN_00023aac(5,1,L"%S  line %d  m_stUsbList.nDataSize = %d","CUSBMgr::getUSBFile");
      iVar2 = 0;
      if (0 < iVar9) {
        piVar7 = (int *)(param_1 + 0x95324);
        do {
          if (*piVar7 == *(int *)(param_1 + 0x291e)) {
            *(char *)(param_1 + 0x2956) = (char)iVar2;
            *(char *)(param_1 + 0x2957) = (char)((uint)iVar2 >> 8);
            goto LAB_0001e314;
          }
          iVar2 = iVar2 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar2 < iVar9);
      }
      *(undefined1 *)(param_1 + 0x2956) = 0xff;
      *(undefined1 *)(param_1 + 0x2957) = 0xff;
LAB_0001e314:
      iVar9 = FUN_000231a4();
      if (*(int *)(iVar9 + 0x44) != 0) {
        iVar9 = FUN_000231a4();
        FUN_00024094(*(int *)(iVar9 + 0x44),(int *)(param_1 + 0x294c),0,0x977fc);
      }
      FUN_00023aac(5,0,L"%S  line %d  nRootIdx : %d","CUSBMgr::getUSBFile");
      FUN_00023580(5,0x15,0x69,0,(LPARAM *)0x0);
      FUN_00025510(local_30);
      return 1;
    }
  }
LAB_0001dec8:
  FUN_00025510(local_30);
  return 0;
}



/* 0001e3d4 FUN_0001e3d4 */

/* Boundary evidence: original MIPS .pdata 0001e3d4..0001e617. Semantic name remains unreviewed. */

undefined4 FUN_0001e3d4(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  int iVar6;
  void *_Dst;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  
  iVar2 = FUN_000231a4();
  iVar5 = param_2;
  if (param_2 < 0) {
    iVar5 = 0;
  }
  iVar5 = iVar5 * 0x220 + *(int *)(*(int *)(iVar2 + 0x48) + 0x38);
  if (iVar5 != 0) {
    _Dst = (void *)(param_1 + 0x9a14c);
    memset(_Dst,0,0x20a);
    iVar2 = FUN_000231a4();
    iVar2 = FUN_00012d5c(*(int *)(iVar2 + 0x48) + 8,0);
    if (iVar2 != 0) {
      iVar2 = FUN_000231a4();
      *(bool *)_Dst = *(int *)(*(int *)(iVar2 + 0x48) + 0x20) == 0;
      iVar2 = FUN_000231a4();
      FUN_00013f10(*(undefined4 *)(iVar2 + 0x48),param_2,(wchar_t *)(param_1 + 0x9a14e));
      if (0 < *(short *)(iVar5 + 0x210)) {
        sVar1 = *(short *)(iVar5 + 0x21a);
        iVar2 = FUN_000231a4();
        iVar2 = FUN_000149e0(*(int *)(iVar2 + 0x48),(int)sVar1);
        if (iVar2 < 3) {
          iVar2 = (int)*(short *)(iVar5 + 0x21a);
          iVar5 = FUN_000231a4();
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          iVar5 = iVar2 * 0x220 + *(int *)(*(int *)(iVar5 + 0x48) + 0x38);
          if (iVar5 == 0) {
            return 0;
          }
          iVar2 = 0;
          if (0 < *(short *)(iVar5 + 0x210)) {
            do {
              iVar6 = *(short *)(iVar5 + 0x20e) + iVar2;
              iVar3 = FUN_000231a4();
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              iVar3 = iVar6 * 0x220 + *(int *)(*(int *)(iVar3 + 0x48) + 0x38);
              if ((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x21c))) {
                *(undefined1 *)(param_1 + 0x9a14d) = 1;
                break;
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(short *)(iVar5 + 0x210));
          }
        }
      }
      memset(&local_34,0,8);
      local_38 = 1;
      local_34 = 0x20a;
      local_30 = _Dst;
      pHVar4 = FindWindowW(L"AppMain",L"AppMain");
      local_40[0] = 0;
      SendMessageTimeout(pHVar4,0x4a,0xd13,&local_38,0,0x5dc,local_40);
      return 1;
    }
  }
  return 0;
}



/* 0001e618 FUN_0001e618 */

/* Boundary evidence: original MIPS .pdata 0001e618..0001e6ef. Semantic name remains unreviewed. */

undefined4 FUN_0001e618(int param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x291e);
  iVar1 = FUN_00014db0(param_1,param_2,param_3,param_4);
  iVar2 = FUN_000132fc(iVar1,iVar4);
  iVar3 = FUN_00014db0(iVar1,iVar4,param_3,param_4);
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar2 = iVar2 * 0x220 + *(int *)(iVar3 + 0x38);
  if (iVar2 != 0) {
    do {
      if (param_2 == *(short *)(iVar2 + 0x21a)) {
        return 1;
      }
      iVar3 = (int)*(short *)(iVar2 + 0x20c);
      iVar2 = FUN_00014db0(iVar1,iVar4,param_3,param_4);
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      iVar2 = iVar3 * 0x220 + *(int *)(iVar2 + 0x38);
    } while ((iVar2 != 0) && (-1 < *(short *)(iVar2 + 0x20c)));
  }
  return 0;
}



/* 0001e6f0 FUN_0001e6f0 */

/* Boundary evidence: original MIPS .pdata 0001e6f0..0001e74b. Semantic name remains unreviewed. */

int FUN_0001e6f0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_000231a4();
    iVar1 = param_2 * 0x220 + *(int *)(*(int *)(iVar1 + 0x48) + 0x38);
  }
  return iVar1;
}



/* 0001e74c FUN_0001e74c */

/* Boundary evidence: original MIPS .pdata 0001e74c..0001e80b. Semantic name remains unreviewed. */

void FUN_0001e74c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar2 = FUN_000231a4();
    iVar2 = FUN_000132fc(*(int *)(iVar2 + 0x48),param_2);
    iVar3 = FUN_0001e6f0(param_1,iVar2);
    if (iVar3 != 0) {
      sVar1 = *(short *)(iVar3 + 0x210);
      iVar4 = 0;
      if (0 < sVar1) {
        do {
          FUN_0001e6f0(param_1,*(short *)(iVar3 + 0x20e) + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < sVar1);
      }
    }
    FUN_0001de58(param_1,iVar2);
  }
  return;
}



/* 0001e80c FUN_0001e80c */

/* Boundary evidence: original MIPS .pdata 0001e80c..0001e8cb. Semantic name remains unreviewed. */

void FUN_0001e80c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar2 = FUN_000231a4();
    iVar2 = FUN_000132fc(*(int *)(iVar2 + 0x48),param_2);
    iVar3 = FUN_0001e6f0(param_1,iVar2);
    if (iVar3 != 0) {
      sVar1 = *(short *)(iVar3 + 0x210);
      iVar4 = 0;
      if (0 < sVar1) {
        do {
          FUN_0001e6f0(param_1,*(short *)(iVar3 + 0x20e) + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < sVar1);
      }
    }
    FUN_0001e3d4(param_1,iVar2);
  }
  return;
}



/* 0001e8cc FUN_0001e8cc */

/* Boundary evidence: original MIPS .pdata 0001e8cc..0001e9fb. Semantic name remains unreviewed. */

int FUN_0001e8cc(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  wchar_t *_Str2;
  int iVar3;
  int iVar4;
  wchar_t local_228;
  undefined1 auStack_226 [518];
  uint local_20;
  
  local_20 = DAT_0002f960;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    iVar1 = FUN_000231a4();
    iVar1 = FUN_00012ebc(*(int *)(iVar1 + 0x48));
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = FUN_000231a4();
        _Str2 = (wchar_t *)FUN_00013318(*(int *)(iVar2 + 0x48),iVar4);
        if ((_Str2 != (wchar_t *)0x0) && (iVar2 = wcscmp(param_2,_Str2), iVar2 == 0)) {
          local_228 = L'\0';
          memset(auStack_226,0,0x206);
          iVar2 = FUN_000231a4();
          iVar2 = FUN_000132fc(*(int *)(iVar2 + 0x48),iVar4);
          iVar3 = FUN_000231a4();
          FUN_00013f10(*(undefined4 *)(iVar3 + 0x48),iVar2,&local_228);
          iVar2 = wcscmp(param_3,&local_228);
          if (iVar2 == 0) {
            FUN_00025510(local_20);
            return iVar4;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  FUN_00025510(local_20);
  return -1;
}



/* 0001e9fc FUN_0001e9fc */

/* Boundary evidence: original MIPS .pdata 0001e9fc..0001ea9b. Semantic name remains unreviewed. */

void FUN_0001e9fc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x38) == 0) {
    iVar1 = param_1 + 8;
    FUN_0001be50(iVar1,L"\\Storage Card2\\USBMusicResume.dat");
    FUN_0001b5b0(iVar1,0);
    FUN_0001b544(iVar1,0);
    FUN_0001c17c(iVar1,L"\\Storage Card2\\USBMusicResume.dat");
  }
  else {
    FUN_0001b5b0(param_1 + 8,0);
    FUN_0001b544(param_1 + 8,0);
  }
  return;
}



/* 0001ea9c FUN_0001ea9c */

/* Boundary evidence: original MIPS .pdata 0001ea9c..0001eac3. Semantic name remains unreviewed. */

void FUN_0001ea9c(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3eb);
  return;
}



/* 0001eac4 FUN_0001eac4 */

/* Boundary evidence: original MIPS .pdata 0001eac4..0001ec87. Semantic name remains unreviewed. */

void FUN_0001eac4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_18 [2];
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3eb);
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x18) == 0) {
    FUN_00023aac(5,3,L"%S  line %d resume play Start","CUSBMgr::procAttachTimer");
    iVar3 = param_1 + 8;
    iVar1 = FUN_0001be50(iVar3,L"\\Storage Card2\\USBMusicResume.dat");
    if (iVar1 != 0) {
      FUN_0001abac(iVar3);
      uVar2 = FUN_0001ba3c(iVar3);
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 8) = uVar2;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 4) = 1;
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 8) != 0) {
        memset(local_18,0,4);
        local_18[0] = local_18[0] & 0xffe03f13 | 0x202013;
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x18) == 0) {
          FUN_00023580(5,1,9,4,(LPARAM *)local_18);
        }
        FUN_00023aac(5,3,L"%S  line %d resume play!!!!!!!!","CUSBMgr::procAttachTimer");
      }
    }
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x18) == 0) {
      iVar1 = FUN_000231a4();
      FUN_00012e80(*(int *)(iVar1 + 0x48));
      FUN_000231a4();
      FUN_00022f80();
      iVar1 = FUN_000231a4();
      FUN_00012eb4(*(int *)(iVar1 + 0x48));
      iVar1 = FUN_000231a4();
      FUN_00012ebc(*(int *)(iVar1 + 0x48));
      FUN_00023aac(5,3,L"%S  line %d, media: %d, Dir: %d","CUSBMgr::procAttachTimer");
    }
  }
  return;
}



/* 0001ec88 FUN_0001ec88 */

/* Boundary evidence: original MIPS .pdata 0001ec88..0001ecb7. Semantic name remains unreviewed. */

void FUN_0001ec88(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ee);
  return;
}



/* 0001ecb8 FUN_0001ecb8 */

void FUN_0001ecb8(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x9a148) = *param_2;
  }
  return;
}



/* 0001ecdc FUN_0001ecdc */

int FUN_0001ecdc(int param_1)

{
  return param_1 + 0x9a148;
}



/* 0001ecec FUN_0001ecec */

/* Boundary evidence: original MIPS .pdata 0001ecec..0001ed07. Semantic name remains unreviewed. */

void FUN_0001ecec(void)

{
  FUN_0001b17c();
  return;
}



/* 0001ed08 FUN_0001ed08 */

/* Boundary evidence: original MIPS .pdata 0001ed08..0001ed2f. Semantic name remains unreviewed. */

void FUN_0001ed08(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ef);
  return;
}



/* 0001ed30 FUN_0001ed30 */

/* Boundary evidence: original MIPS .pdata 0001ed30..0001ed4b. Semantic name remains unreviewed. */

void FUN_0001ed30(int param_1)

{
  FUN_0001b3b0(param_1 + 8);
  return;
}



/* 0001ed4c FUN_0001ed4c */

/* Boundary evidence: original MIPS .pdata 0001ed4c..0001ed67. Semantic name remains unreviewed. */

void FUN_0001ed4c(int param_1,uint param_2,int param_3)

{
  FUN_0001b484(param_1 + 8,param_2,param_3);
  return;
}



/* 0001ed68 FUN_0001ed68 */

/* Boundary evidence: original MIPS .pdata 0001ed68..0001ed93. Semantic name remains unreviewed. */

void FUN_0001ed68(int param_1)

{
  memset((void *)(param_1 + 0x9a148),0,4);
  return;
}



/* 0001ed94 FUN_0001ed94 */

/* Boundary evidence: original MIPS .pdata 0001ed94..0001edaf. Semantic name remains unreviewed. */

void FUN_0001ed94(void)

{
  FUN_0001ac58();
  return;
}



/* 0001edb0 FUN_0001edb0 */

/* Boundary evidence: original MIPS .pdata 0001edb0..0001edcb. Semantic name remains unreviewed. */

void FUN_0001edb0(void)

{
  FUN_0001abe0();
  return;
}



/* 0001edcc FUN_0001edcc */

/* Boundary evidence: original MIPS .pdata 0001edcc..0001ee23. Semantic name remains unreviewed. */

undefined4 *
FUN_0001edcc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = &PTR_FUN_00029fd4;
  FUN_0001c4d4(param_1 + 2,param_2,param_3,param_4);
  FUN_0001db80((int)param_1);
  return param_1;
}



/* 0001ee24 Unwind@0001ee24 */

/* Boundary evidence: original MIPS .pdata 0001ee24..0001ee57. Semantic name remains unreviewed. */

void Unwind_0001ee24(void)

{
  int *in_v0;
  
  FUN_00019508((undefined4 *)(*in_v0 + 8));
  return;
}



/* 0001ee58 FUN_0001ee58 */

/* Boundary evidence: original MIPS .pdata 0001ee58..0001eea3. Semantic name remains unreviewed. */

undefined4 * FUN_0001ee58(undefined4 *param_1,uint param_2)

{
  FUN_0001dacc(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001eea4 FUN_0001eea4 */

/* Boundary evidence: original MIPS .pdata 0001eea4..0001ef17. Semantic name remains unreviewed. */

void FUN_0001eea4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (DAT_00034f28 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x9a35c);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00034f28 = (undefined4 *)0x0;
    }
    else {
      DAT_00034f28 = FUN_0001edcc(puVar1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 0001ef18 Unwind@0001ef18 */

/* Boundary evidence: original MIPS .pdata 0001ef18..0001ef47. Semantic name remains unreviewed. */

void Unwind_0001ef18(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001ef48 FUN_0001ef48 */

/* Boundary evidence: original MIPS .pdata 0001ef48..0001f34b. Semantic name remains unreviewed. */

void FUN_0001ef48(int param_1,int param_2,int param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  uint uVar3;
  int iVar4;
  uint local_440 [2];
  wchar_t local_438;
  undefined1 auStack_436 [1038];
  uint local_28;
  
  local_28 = DAT_0002f960;
  FUN_00023aac(5,0,L"%S ----------------------Search Start---------------------------",
               "CUSBMgr::searchThreadFunc");
  *(undefined4 *)(param_1 + 4) = 1;
  local_438 = L'\0';
  memset(auStack_436,0,0x40e);
  wcscpy(&local_438,L"MD");
  iVar1 = FUN_000231a4();
  iVar4 = -1;
  FUN_000131c8(*(int *)(iVar1 + 0x48),0,0,0xffff,&local_438,0);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(*(int *)(iVar1 + 0x48) + 0x24) = 0;
  iVar1 = FUN_000231a4();
  if (*(int *)(iVar1 + 0x18) == 0) {
    iVar1 = FUN_000231a4();
    FUN_00015620(*(int *)(iVar1 + 0x48),&local_438,0,0);
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x18) == 0) {
      iVar1 = FUN_000231a4();
      FUN_00015a94(*(int *)(iVar1 + 0x48));
      iVar1 = FUN_000231a4();
      if ((*(int *)(iVar1 + 0x38) != 0) && (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x18) != 1)) {
        iVar1 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
        if (iVar1 == 0) {
          FUN_00023aac(5,3,L"%S Line %d ------------ No USB device return -----------",
                       "CUSBMgr::searchThreadFunc");
        }
        else {
          iVar1 = FUN_000231a4();
          iVar1 = FUN_00012ebc(*(int *)(iVar1 + 0x48));
          if (((iVar1 < 1) || (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 8) == 0)) &&
             ((param_2 != 0 || (param_3 != 0)))) {
            memset(local_440,0,4);
            if (param_3 == 0) {
              uVar3 = local_440[0] & 0xffffff13 | 0x13;
            }
            else {
              uVar3 = local_440[0] & 0xffffff33 | 0x33;
            }
            local_440[0] = uVar3 & 0xffc03fff | 0x2000;
            iVar1 = FUN_000231a4();
            if (*(int *)(iVar1 + 0x18) == 0) {
              FUN_00023580(5,1,9,4,(LPARAM *)local_440);
            }
            pwVar2 = L"%S empty media file";
          }
          else {
            iVar1 = FUN_000231a4();
            FUN_00012eb4(*(int *)(iVar1 + 0x48));
            iVar1 = FUN_000231a4();
            FUN_00012ebc(*(int *)(iVar1 + 0x48));
            FUN_00023aac(5,0,L"%S  line %d, media: %d, Dir: %d","CUSBMgr::searchThreadFunc");
            if (((wchar_t *)(param_1 + 0x2716) != (wchar_t *)0x0) &&
               ((wchar_t *)(param_1 + 0x250e) != (wchar_t *)0x0)) {
              FUN_00023aac(5,0,L"%S  line %d %s / %s","CUSBMgr::searchThreadFunc");
              iVar4 = FUN_0001e8cc(param_1,(wchar_t *)(param_1 + 0x2716),
                                   (wchar_t *)(param_1 + 0x250e));
              if (iVar4 < 0) {
                iVar4 = 0;
              }
              iVar1 = FUN_000231a4();
              *(int *)(iVar1 + 0x74) = iVar4;
            }
            FUN_00019c94(param_1 + 8,iVar4);
            FUN_00023aac(5,0,L"%S  line %d / ResumePlay match index : %d",
                         "CUSBMgr::searchThreadFunc");
            FUN_0001c454(param_1 + 8);
            if (param_2 != 0) {
              iVar1 = FUN_000231a4();
              *(undefined4 *)(iVar1 + 8) = 0;
            }
            iVar1 = FUN_000231a4();
            if (*(int *)(iVar1 + 0x18) != 0) goto LAB_0001f31c;
            FUN_000237b4(0x15,5,0x72,0,(void *)0x0);
            FUN_00023580(5,0x15,0x6a,0,(LPARAM *)0x0);
            pwVar2 = 
            L"%S ----------------------------IDM_MUSB_INDEXING_COMPLETE--------------------";
          }
          FUN_00023aac(5,1,pwVar2,"CUSBMgr::searchThreadFunc");
        }
      }
      goto LAB_0001f31c;
    }
    pwVar2 = L"Exit!!! searchThreadFunc#2\r\n";
  }
  else {
    pwVar2 = L"Exit!!! searchThreadFunc#1\r\n";
  }
  NKDbgPrintfW(pwVar2);
LAB_0001f31c:
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_00025510(local_28);
  return;
}



/* 0001f34c FUN_0001f34c */

/* Boundary evidence: original MIPS .pdata 0001f34c..0001f4a7. Semantic name remains unreviewed. */

void FUN_0001f34c(int param_1,int param_2,undefined4 param_3,wchar_t *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = (int *)(param_1 + 0x294c);
  if (*(int *)(param_1 + 0x2958) == 0) {
    iVar3 = *piVar2 + -1;
    if (-1 < iVar3) {
      piVar4 = (int *)((*piVar2 + 0x254c8) * 4 + param_1);
      do {
        iVar1 = FUN_0001e618(param_1,*piVar4,param_3,param_4);
        if (iVar1 != 0) {
          *(char *)(param_1 + 0x2956) = (char)iVar3;
          *(char *)(param_1 + 0x2957) = (char)((uint)iVar3 >> 8);
LAB_0001f428:
          iVar3 = FUN_000231a4();
          if (*(int *)(iVar3 + 0x44) == 0) {
            return;
          }
          goto LAB_0001f3d8;
        }
        iVar3 = iVar3 + -1;
        piVar4 = piVar4 + -1;
      } while (-1 < iVar3);
    }
  }
  else {
    iVar3 = 0;
    if (0 < *piVar2) {
      piVar4 = (int *)(param_1 + 0x95324);
      do {
        if (*piVar4 == param_2) {
          *(char *)(param_1 + 0x2956) = (char)iVar3;
          *(char *)(param_1 + 0x2957) = (char)((uint)iVar3 >> 8);
          goto LAB_0001f428;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar3 < *piVar2);
    }
  }
  *(undefined1 *)(param_1 + 0x2956) = 0xff;
  *(undefined1 *)(param_1 + 0x2957) = 0xff;
LAB_0001f3d8:
  iVar3 = FUN_000231a4();
  FUN_00024094(*(int *)(iVar3 + 0x44),piVar2,0,0x977fc);
  return;
}



/* 0001f4a8 FUN_0001f4a8 */

/* Boundary evidence: original MIPS .pdata 0001f4a8..0001f7fb. Semantic name remains unreviewed. */

undefined4 FUN_0001f4a8(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  wchar_t *pwVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  char *pcVar16;
  
  iVar6 = FUN_000231a4();
  iVar13 = param_2;
  if (param_2 < 0) {
    iVar13 = 0;
  }
  piVar15 = (int *)(param_1 + 0x294c);
  sVar1 = *(short *)(iVar13 * 0x220 + *(int *)(*(int *)(iVar6 + 0x48) + 0x38) + 0x214);
  memset(piVar15,0,0x977fc);
  pcVar16 = "CUSBMgr::getUSBFolder";
  FUN_00023aac(5,1,L"%S nRootIdx : %d","CUSBMgr::getUSBFolder");
  iVar13 = FUN_000231a4();
  uVar7 = FUN_0001584c(*(int *)(iVar13 + 0x48),param_2,piVar15);
  *(int *)(param_1 + 0x9a144) = param_2;
  *(undefined4 *)(param_1 + 0x2958) = 0;
  *(bool *)(param_1 + 0x2950) = param_2 == 0;
  iVar13 = FUN_000231a4();
  FUN_00013f10(*(undefined4 *)(iVar13 + 0x48),param_2,(wchar_t *)(param_1 + 0x295c));
  if ((0 < sVar1) && (0 < (int)uVar7)) {
    FUN_00023aac(5,0,L"%S %s","CUSBMgr::getUSBFolder");
    memmove((void *)(param_1 + 0x2bdc),(wchar_t *)(param_1 + 0x2b64),0x92748);
    memmove((void *)(param_1 + 0x95328),(int *)(param_1 + 0x95324),0x4e1c);
    wcscpy((wchar_t *)(param_1 + 0x2b64),L"Root");
    *(int *)(param_1 + 0x95324) = param_2;
    *(undefined1 *)(param_1 + 0x2952) = 1;
    uVar7 = uVar7 + 1;
  }
  FUN_00023aac(5,0,L"%S nValideListCount : %d","CUSBMgr::getUSBFolder");
  uVar2 = param_1 + 0x294fU & 3;
  puVar3 = (uint *)((param_1 + 0x294fU) - uVar2);
  *puVar3 = *puVar3 & -1 << (uVar2 + 1) * 8 | uVar7 >> (3 - uVar2) * 8;
  pwVar12 = L"%S  line %d  m_stUsbList.nDataSize = %d";
  uVar11 = 3;
  uVar10 = 5;
  uVar2 = (uint)piVar15 & 3;
  *(uint *)((int)piVar15 - uVar2) =
       *(uint *)((int)piVar15 - uVar2) & 0xffffffffU >> (4 - uVar2) * 8 | uVar7 << uVar2 * 8;
  FUN_00023aac(5,3,L"%S  line %d  m_stUsbList.nDataSize = %d","CUSBMgr::getUSBFolder");
  iVar6 = *(int *)(param_1 + 0x291e);
  bVar5 = false;
  iVar13 = FUN_00014db0(uVar10,uVar11,pwVar12,(wchar_t *)pcVar16);
  iVar6 = FUN_000132fc(iVar13,iVar6);
  iVar13 = FUN_000231a4();
  iVar8 = FUN_000149e0(*(int *)(iVar13 + 0x48),iVar6);
  bVar4 = false;
  iVar13 = 0;
  iVar14 = 0;
  if (0 < (int)uVar7) {
    piVar15 = (int *)(param_1 + 0x95324);
    do {
      iVar9 = FUN_0001e618(param_1,*piVar15,pwVar12,(wchar_t *)pcVar16);
      if (iVar9 != 0) {
        if (iVar6 == *piVar15) {
          bVar4 = true;
          iVar13 = iVar14;
        }
        if (bVar4) {
          *(char *)(param_1 + 0x2956) = (char)iVar13;
          *(char *)(param_1 + 0x2957) = (char)((uint)iVar13 >> 8);
        }
        else {
          *(char *)(param_1 + 0x2956) = (char)iVar14;
          *(char *)(param_1 + 0x2957) = (char)((uint)iVar14 >> 8);
        }
        bVar5 = true;
        if ((iVar8 < 3) && ((*(char *)(param_1 + 0x2952) == '\0' || (0 < iVar14))))
        goto LAB_0001f780;
      }
      iVar14 = iVar14 + 1;
      piVar15 = piVar15 + 1;
    } while (iVar14 < (int)uVar7);
    if (bVar5) goto LAB_0001f780;
  }
  *(undefined1 *)(param_1 + 0x2956) = 0xff;
  *(undefined1 *)(param_1 + 0x2957) = 0xff;
LAB_0001f780:
  iVar13 = FUN_000231a4();
  if (*(int *)(iVar13 + 0x40) != 0) {
    iVar13 = FUN_000231a4();
    FUN_00024094(*(int *)(iVar13 + 0x44),(void *)(param_1 + 0x294c),0,0x977fc);
  }
  FUN_00023580(5,0x15,0x69,0,(LPARAM *)0x0);
  return 1;
}



/* 0001f7fc FUN_0001f7fc */

/* Boundary evidence: original MIPS .pdata 0001f7fc..0001faf7. Semantic name remains unreviewed. */

undefined4 FUN_0001f7fc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x294c) == 0) {
    pwVar4 = L"%S error there is any item in previous list";
  }
  else {
    if (-1 < param_2) {
      if (*(int *)(param_1 + 0x2958) < 1) {
        if (4999 < param_2) {
          param_2 = 0;
        }
        iVar5 = *(int *)((param_2 + 0x254c9) * 4 + param_1);
        iVar1 = FUN_000231a4();
        iVar1 = FUN_000149e0(*(int *)(iVar1 + 0x48),iVar5);
        if (((*(char *)(param_1 + 0x2952) == '\0') || (param_2 != 0)) && (iVar1 < 3)) {
          iVar2 = FUN_000231a4();
          iVar1 = iVar5;
          if (iVar5 < 0) {
            iVar1 = 0;
          }
          if (0 < *(short *)(iVar1 * 0x220 + *(int *)(*(int *)(iVar2 + 0x48) + 0x38) + 0x210)) {
            iVar2 = FUN_000231a4();
            iVar1 = iVar5;
            if (iVar5 < 0) {
              iVar1 = 0;
            }
            iVar1 = iVar1 * 0x220 + *(int *)(*(int *)(iVar2 + 0x48) + 0x38);
            if (iVar1 == 0) {
              return 1;
            }
            iVar2 = 0;
            if (0 < *(short *)(iVar1 + 0x210)) {
              do {
                iVar6 = *(short *)(iVar1 + 0x20e) + iVar2;
                iVar3 = FUN_000231a4();
                if (iVar6 < 0) {
                  iVar6 = 0;
                }
                iVar3 = iVar6 * 0x220 + *(int *)(*(int *)(iVar3 + 0x48) + 0x38);
                if ((iVar3 != 0) && (0 < *(int *)(iVar3 + 0x21c))) {
                  FUN_0001f4a8(param_1,iVar5);
                  return 1;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < *(short *)(iVar1 + 0x210));
            }
          }
        }
        FUN_0001de58(param_1,iVar5);
        return 0;
      }
      iVar5 = *(int *)(param_1 + 0x9a144);
      iVar1 = FUN_000231a4();
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      iVar1 = *(short *)(iVar5 * 0x220 + *(int *)(*(int *)(iVar1 + 0x48) + 0x38) + 0x212) + param_2;
      FUN_00023aac(5,3,L"%S Play index:%d","CUSBMgr::getUSBMediaItem");
      if (((*(int *)(param_1 + 0x291e) == iVar1) && (*(int *)(param_1 + 0x2948) < 1)) &&
         (*(int *)(param_1 + 0x1adc) != 0)) {
        return 0;
      }
      FUN_0001c6e0(param_1 + 8,iVar1,1,(uint)(*(int *)(param_1 + 0x1ad8) != 0),1);
      if (*(int *)(param_1 + 0x2922) == 1) {
        return 0;
      }
      if (*(int *)(param_1 + 0x2926) != 1) {
        return 0;
      }
      FUN_00019ae0(param_1 + 8,1);
      FUN_000231a4();
      FUN_00022f54();
      return 0;
    }
    pwVar4 = L"%S error iFileOffInList is less than zero";
  }
  FUN_00023aac(5,3,pwVar4,"CUSBMgr::getUSBMediaItem");
  return 0;
}



/* 0001faf8 FUN_0001faf8 */

/* Boundary evidence: original MIPS .pdata 0001faf8..0001fc8b. Semantic name remains unreviewed. */

void FUN_0001faf8(int param_1,int param_2)

{
  int iVar1;
  void *_Dst;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  pcVar4 = "CUSBMgr::selectListItem";
  FUN_00023aac(5,1,L"%S stCategory.nSelIdx:%d ","CUSBMgr::selectListItem");
  FUN_00023aac(5,1,L"%S stCategory.nCat:%d ","CUSBMgr::selectListItem");
  _Dst = (void *)(param_1 + 0x295c);
  uVar3 = 0x104;
  memset(_Dst,0,0x104);
  iVar2 = (param_2 << 8) >> 0x10;
  if (-1 < iVar2) {
    FUN_0001f7fc(param_1,iVar2);
    return;
  }
  if (*(int *)(param_1 + 0x2958) == 0) {
LAB_0001fbfc:
    iVar1 = *(int *)(param_1 + 0x9a144);
  }
  else {
    iVar1 = FUN_000231a4();
    iVar2 = *(int *)(param_1 + 0x9a144);
    iVar1 = FUN_000149e0(*(int *)(iVar1 + 0x48),iVar2);
    _Dst = (void *)(uint)(iVar1 < 3);
    if (_Dst == (void *)0x0) goto LAB_0001fbfc;
    iVar1 = *(int *)(param_1 + 0x9a144);
    if (*(char *)(param_1 + 0x2951) != '\0') goto LAB_0001fc34;
  }
  iVar2 = FUN_00014db0(_Dst,iVar2,uVar3,(wchar_t *)pcVar4);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar1 = (int)*(short *)(iVar1 * 0x220 + *(int *)(iVar2 + 0x38) + 0x216);
LAB_0001fc34:
  FUN_00023aac(5,0,L"%S  line %d  iParentFolder : %d / m_stUsbList.nPID : %d",
               "CUSBMgr::selectListItem");
  FUN_0001f4a8(param_1,iVar1);
  return;
}



/* 0001fc8c FUN_0001fc8c */

/* Boundary evidence: original MIPS .pdata 0001fc8c..0001fccf. Semantic name remains unreviewed. */

void FUN_0001fc8c(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3eb);
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3eb,1000,(TIMERPROC)0x0);
  return;
}



/* 0001fcd0 FUN_0001fcd0 */

/* Boundary evidence: original MIPS .pdata 0001fcd0..0001fd27. Semantic name remains unreviewed. */

void FUN_0001fcd0(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 0;
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ee);
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x78) = 1;
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ee,500,(TIMERPROC)0x0);
  return;
}



/* 0001fd28 FUN_0001fd28 */

/* Boundary evidence: original MIPS .pdata 0001fd28..0001fd6b. Semantic name remains unreviewed. */

void FUN_0001fd28(void)

{
  int iVar1;
  
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ef);
  iVar1 = FUN_000231a4();
  SetTimer(*(HWND *)(iVar1 + 0x3c),0x3ef,500,(TIMERPROC)0x0);
  return;
}



/* 0001fd6c FUN_0001fd6c */

/* Boundary evidence: original MIPS .pdata 0001fd6c..0002033f. Semantic name remains unreviewed. */

void FUN_0001fd6c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_38 [8];
  
  iVar3 = 1;
  *(undefined4 *)(param_1 + 0x9a358) = 1;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 0x38) = 1;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar1 = FUN_000231a4();
  *(undefined4 *)(iVar1 + 4) = 0;
  iVar1 = FUN_000231a4();
  FUN_0001db80(*(int *)(iVar1 + 0x4c));
  iVar1 = FUN_000231a4();
  FUN_00012e80(*(int *)(iVar1 + 0x48));
  iVar1 = FUN_000231a4();
  iVar1 = FUN_00013630(*(int *)(iVar1 + 0x48),&DAT_000272cc);
  if (iVar1 == 0) {
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x38) = 0;
    memset(local_38,0,4);
    local_38[0] = local_38[0] & 0xffc02833 | 0x2833;
    FUN_00023aac(5,0,L"%S  line %d BOOT Resume Fail","CUSBMgr::bootResumeThreadFunc");
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x18) == 0) {
      FUN_00023580(5,1,9,4,(LPARAM *)local_38);
    }
  }
  else {
    FUN_00023aac(5,3,L"%S  line %d == bResumeCmd = %d ==","CUSBMgr::bootResumeThreadFunc");
    if (param_2 == 0) {
      iVar1 = FUN_0001be50(param_1 + 8,L"\\Storage Card2\\USBMusicResume.dat");
      if (iVar1 != 0) {
        iVar1 = FUN_000231a4();
        FUN_0001abac(*(int *)(iVar1 + 0x4c) + 8);
        uVar2 = FUN_0001ba3c(param_1 + 8);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 8) = uVar2;
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 4) = 1;
        memset(local_38,0,4);
        iVar1 = FUN_000231a4();
        if ((*(int *)(iVar1 + 8) != 0) && (iVar1 = FUN_000231a4(), 0 < *(int *)(iVar1 + 0x38))) {
          local_38[0] = local_38[0] & 0xffe02133 | 0x202133;
          FUN_00023580(5,1,9,4,(LPARAM *)local_38);
        }
      }
      FUN_00023aac(5,0,L"%S  line %d -----------Search start","CUSBMgr::bootResumeThreadFunc");
      FUN_0001ef48(param_1,0,0);
      FUN_00023aac(5,0,L"%S  line %d -----------Search end","CUSBMgr::bootResumeThreadFunc");
      iVar1 = FUN_000231a4();
      if (0 < *(int *)(iVar1 + 0x38)) {
        memset(local_38,0,4);
        local_38[0] = local_38[0] & 0xffe03f33 | 0x2033;
        iVar1 = FUN_000231a4();
        iVar1 = FUN_00012ebc(*(int *)(iVar1 + 0x48));
        if ((iVar1 < 1) || (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 8) == 0)) {
          iVar3 = 0;
        }
        local_38[0] = (iVar3 << 0x15 ^ local_38[0]) & 0x200000 ^ local_38[0];
        if ((local_38[0] & 0x200000) == 0x200000) {
          local_38[0] = local_38[0] & 0xffffe1ff | 0x100;
        }
        else {
          local_38[0] = local_38[0] & 0xffffe8ff | 0x800;
        }
        FUN_00023aac(5,0,L"%S  line %d usbDev.bAudio %d ++++++++++++++++++++",
                     "CUSBMgr::bootResumeThreadFunc");
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x18) == 0) {
          FUN_00023580(5,1,9,4,(LPARAM *)local_38);
        }
      }
      FUN_00023aac(5,0,L"%S  line %d Boot not cmd resume play!!!!!!!!",
                   "CUSBMgr::bootResumeThreadFunc");
    }
    else {
      iVar1 = FUN_0001be50(param_1 + 8,L"\\Storage Card2\\USBMusicResume.dat");
      if (iVar1 != 0) {
        iVar1 = FUN_000231a4();
        FUN_0001abac(*(int *)(iVar1 + 0x4c) + 8);
        uVar2 = FUN_0001ba3c(param_1 + 8);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 8) = uVar2;
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 4) = 1;
        iVar1 = FUN_000231a4();
        if ((*(int *)(iVar1 + 8) != 0) && (iVar1 = FUN_000231a4(), 0 < *(int *)(iVar1 + 0x38))) {
          memset(local_38,0,4);
          local_38[0] = local_38[0] & 0xffe03f13 | 0x202013;
          Sleep(2000);
          iVar1 = FUN_000231a4();
          if (*(int *)(iVar1 + 0x18) == 0) {
            FUN_00023580(5,1,9,4,(LPARAM *)local_38);
          }
        }
        FUN_00023aac(5,0,L"%S  line %d Boot cmd resume play!!!!!!!!","CUSBMgr::bootResumeThreadFunc"
                    );
      }
      FUN_0001ef48(param_1,0,1);
      iVar1 = FUN_000231a4();
      if (0 < *(int *)(iVar1 + 0x38)) {
        memset(local_38,0,4);
        local_38[0] = local_38[0] & 0xffe02133 | 0x2133;
        iVar1 = FUN_000231a4();
        iVar1 = FUN_00012ebc(*(int *)(iVar1 + 0x48));
        if ((iVar1 < 1) || (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 8) == 0)) {
          iVar3 = 0;
        }
        local_38[0] = (iVar3 << 0x15 ^ local_38[0]) & 0x200000 ^ local_38[0];
        if ((local_38[0] & 0x200000) == 0) {
          local_38[0] = local_38[0] & 0xffffe8ff | 0x800;
        }
        iVar1 = FUN_000231a4();
        if (*(int *)(iVar1 + 0x18) == 0) {
          FUN_00023580(5,1,9,4,(LPARAM *)local_38);
        }
      }
      FUN_00023aac(5,0,L"%S  line %d Boot cmd resume Status update!!!!!!!!",
                   "CUSBMgr::bootResumeThreadFunc");
    }
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(param_1 + 0x9a358) = 0;
  }
  return;
}



/* 00020340 FUN_00020340 */

/* Boundary evidence: original MIPS .pdata 00020340..000205cf. Semantic name remains unreviewed. */

void FUN_00020340(int param_1,undefined4 param_2)

{
  int iVar1;
  LPARAM local_18 [2];
  
  switch(param_2) {
  case 1000:
    FUN_0001b3b0(param_1 + 8);
    break;
  case 0x3e9:
    FUN_0001d880(param_1 + 8);
    break;
  case 0x3ea:
    *(undefined4 *)(param_1 + 0xe68) = 4;
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ea);
    break;
  case 0x3eb:
    FUN_0001eac4(param_1);
    break;
  case 0x3ec:
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x78) = 0;
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ec);
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x70) = 0;
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x30) != 0) {
      FUN_0001c6e0(param_1 + 8,*(int *)(param_1 + 0x291e),3,(uint)(*(int *)(param_1 + 0x1ad8) != 0),
                   1);
    }
    break;
  case 0x3ed:
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x78) = 0;
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ed);
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x30) != 0) {
      FUN_0001c6e0(param_1 + 8,*(int *)(param_1 + 0x291e),2,(uint)(*(int *)(param_1 + 0x1ad8) != 0),
                   1);
    }
    break;
  case 0x3ee:
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x78) = 0;
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x78) = 0;
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ee);
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x30) != 0) {
      FUN_0001faf8(param_1,*(int *)(param_1 + 0x9a148));
    }
    memset((void *)(param_1 + 0x9a148),0,4);
    break;
  case 0x3ef:
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3ef);
    if (*(int *)(param_1 + 0x1ad8) == 0) {
      iVar1 = FUN_0001144c();
      FUN_000114a0(iVar1);
    }
    break;
  case 0x3f1:
    FUN_00023aac(5,3,L"%S  line %d TIMER_ID_USB_MOUNT_RESUME_WAIT","CUSBMgr::timerProc");
    iVar1 = FUN_000231a4();
    KillTimer(*(HWND *)(iVar1 + 0x3c),0x3f1);
    local_18[0] = 0x2933;
    FUN_00023580(5,1,9,4,local_18);
  }
  return;
}



/* 000205d0 FUN_000205d0 */

undefined4 * FUN_000205d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002ac08;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* 000205f8 FUN_000205f8 */

/* Boundary evidence: original MIPS .pdata 000205f8..0002061f. Semantic name remains unreviewed. */

void FUN_000205f8(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 1;
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 00020620 FUN_00020620 */

/* Boundary evidence: original MIPS .pdata 00020620..000206a3. Semantic name remains unreviewed. */

void FUN_00020620(int param_1,int param_2)

{
  int iVar1;
  LPARAM lParam;
  
  iVar1 = wcscmp(L"MD",(wchar_t *)(param_2 + 0x1c));
  if (iVar1 == 0) {
    lParam = 0;
  }
  else {
    iVar1 = wcscmp(L"RMD0:",(wchar_t *)(param_2 + 0x1c));
    if (iVar1 != 0) {
      return;
    }
    lParam = 3;
  }
  PostMessageW(*(HWND *)(param_1 + 4),*(UINT *)(param_1 + 0x10),*(WPARAM *)(param_2 + 0x14),lParam);
  return;
}



/* 000206a4 FUN_000206a4 */

/* Boundary evidence: original MIPS .pdata 000206a4..00020953. Semantic name remains unreviewed. */

undefined4 FUN_000206a4(int param_1)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  HANDLE local_118;
  int local_114;
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [8];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 auStack_e8 [192];
  uint local_28;
  
  local_28 = DAT_0002f960;
  memset(&local_118,0,0xc);
  local_100 = 0x14;
  local_fc = 1;
  local_f8 = 0;
  local_f4 = 0xc0;
  local_f0 = 1;
  local_118 = (HANDLE)CreateMsgQueue(0,&local_100);
  local_114 = CreateMsgQueue(0,&local_100);
  if ((local_118 == (HANDLE)0x0) || (local_114 == 0)) {
    DVar3 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Create Msg Q.\n",DVar3);
  }
  else {
    iVar1 = RequestDeviceNotifications(&DAT_0002aaa8,local_118,1);
    iVar2 = RequestDeviceNotifications(&DAT_0002aab8,local_114,1);
    if ((iVar1 != 0) && (iVar2 != 0)) {
      iVar4 = *(int *)(param_1 + 0x14);
      *(HANDLE *)(param_1 + 8) = local_118;
      *(int *)(param_1 + 0xc) = local_114;
      do {
        if (iVar4 != 0) {
          StopDeviceNotifications(iVar1);
          StopDeviceNotifications(iVar2);
          if (local_118 != (HANDLE)0x0) {
            CloseMsgQueue();
          }
          if (local_114 != 0) {
            CloseMsgQueue();
          }
                    /* WARNING: Subroutine does not return */
          ExitThread(0);
        }
        DVar3 = WaitForMultipleObjects(2,&local_118,0,0xffffffff);
        if (DVar3 == 0) {
          iVar4 = ReadMsgQueue(local_118,auStack_e8,0xc0,auStack_108,0,auStack_10c);
LAB_00020808:
          if (iVar4 == 0) {
            DVar3 = GetLastError();
            NKDbgPrintfW(L"ERROR(%d): Fail to Read Q\n",DVar3);
          }
          else {
            FUN_00020620(param_1,(int)auStack_e8);
          }
        }
        else if (DVar3 == 1) {
          iVar4 = ReadMsgQueue(local_114,auStack_e8,0xc0,auStack_108,0,auStack_10c);
          goto LAB_00020808;
        }
        iVar4 = *(int *)(param_1 + 0x14);
      } while( true );
    }
    DVar3 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Request Device Notifications\n",DVar3);
    if (iVar1 != 0) {
      StopDeviceNotifications(iVar1);
    }
    if (iVar2 != 0) {
      StopDeviceNotifications(iVar2);
    }
  }
  if (local_118 != (HANDLE)0x0) {
    CloseMsgQueue();
  }
  if (local_114 != 0) {
    CloseMsgQueue();
  }
  FUN_00025510(local_28);
  return 0;
}



/* 00020954 FUN_00020954 */

/* Boundary evidence: original MIPS .pdata 00020954..000209cf. Semantic name remains unreviewed. */

void FUN_00020954(LPVOID param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE hObject;
  DWORD DVar1;
  
  *(undefined4 *)((int)param_1 + 4) = param_2;
  *(undefined4 *)((int)param_1 + 0x10) = param_3;
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000206a4,param_1,0,(LPDWORD)0x0);
  if (hObject == (HANDLE)0x0) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t create ThreadProcDevNotify\n",DVar1);
  }
  else {
    CloseHandle(hObject);
  }
  return;
}



/* 000209d0 FUN_000209d0 */

void FUN_000209d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002ac08;
  return;
}



/* 000209e0 FUN_000209e0 */

undefined4 * FUN_000209e0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002ac08;
  return param_1;
}



/* 000209f4 FUN_000209f4 */

/* Boundary evidence: original MIPS .pdata 000209f4..00020a37. Semantic name remains unreviewed. */

undefined4 * FUN_000209f4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002ac08;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00020a38 FUN_00020a38 */

/* Boundary evidence: original MIPS .pdata 00020a38..00020eab. Semantic name remains unreviewed. */

undefined4 FUN_00020a38(void)

{
  int iVar1;
  int in_a3;
  int in_stack_00000010;
  uint local_20 [2];
  
  FUN_00023aac(5,3,L"%S - %d [%d | %d] +++","CDeviceMsgHandler::deviceChangeHandler");
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3f1);
  iVar1 = FUN_000231a4();
  KillTimer(*(HWND *)(iVar1 + 0x3c),0x3f0);
  if (in_stack_00000010 == 3) {
    memset(local_20,0,4);
    if (in_a3 == 0) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x18) = 1;
      FUN_000231a4();
      FUN_0001ea9c();
      FUN_000231a4();
      FUN_0001dde8();
      FUN_000231a4();
      FUN_0001ec88();
      FUN_000231a4();
      FUN_0001ed08();
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x28) != 0) {
        iVar1 = FUN_0001144c();
        FUN_00011e7c(iVar1);
      }
      iVar1 = FUN_000231a4();
      if ((*(int *)(iVar1 + 0x38) != 0) && (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 4) != 0)) {
        iVar1 = FUN_000231a4();
        FUN_0001c17c(*(int *)(iVar1 + 0x4c) + 8,L"\\Storage Card2\\USBMusicResume.dat");
      }
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x38) = 0;
      local_20[0] = local_20[0] & 0xffe03f43 | 0x2043;
      FUN_000237b4(5,1,9,4,local_20);
      local_20[0] = local_20[0] & 0xffffff0f;
      FUN_00023580(5,1,9,4,(LPARAM *)local_20);
      return 1;
    }
    FUN_000231a4();
    FUN_00023aac(5,3,L"%S Line %d m_nAttachedUSBNum %d","CDeviceMsgHandler::deviceChangeHandler");
    iVar1 = FUN_000231a4();
    SetTimer(*(HWND *)(iVar1 + 0x3c),0x3f1,6000,(TIMERPROC)0x0);
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x38) == 0) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 4) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x18) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x10) = 1;
      local_20[0] = local_20[0] & 0xffc03f23 | 0x2023;
      FUN_000237b4(5,1,9,4,local_20);
      return 1;
    }
  }
  else {
    if (in_stack_00000010 != 0) {
      return 1;
    }
    if (in_a3 == 0) {
      FUN_000231a4();
      FUN_0001ea9c();
      FUN_000231a4();
      FUN_0001dde8();
      FUN_000231a4();
      FUN_0001ec88();
      FUN_000231a4();
      FUN_0001ed08();
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x38) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 8) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x14) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar1 = FUN_000231a4();
      FUN_0001db80(*(int *)(iVar1 + 0x4c));
      return 1;
    }
    FUN_000231a4();
    FUN_00023aac(5,3,L"%S - m_bBootResumeStart[%d]","CDeviceMsgHandler::deviceChangeHandler");
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x10) == 0) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x38) = 1;
      FUN_000231a4();
      FUN_00022fac();
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x10) = 1;
      return 1;
    }
    FUN_00023aac(5,3,L"%S getGlobalVal()->m_nAttachedUSBNum == 0   ",
                 "CDeviceMsgHandler::deviceChangeHandler");
    iVar1 = FUN_000231a4();
    if (*(int *)(iVar1 + 0x18) == 0) {
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x14) = 1;
      GetTickCount();
      FUN_000231a4();
      FUN_00023aac(5,3,L"%S *** m_bDevRemove(%d) Process TIME : %d ms ***",
                   "CDeviceMsgHandler::deviceChangeHandler");
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x18) == 0) {
        iVar1 = FUN_000231a4();
        FUN_0001db80(*(int *)(iVar1 + 0x4c));
        iVar1 = FUN_000231a4();
        FUN_00012e80(*(int *)(iVar1 + 0x48));
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 8) = 0;
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x38) = 1;
        FUN_000231a4();
        FUN_0001fc8c();
        return 1;
      }
    }
    else {
      FUN_00023aac(5,3,L"%S getGlobalVal()->m_bDevRemove   ",
                   "CDeviceMsgHandler::deviceChangeHandler");
    }
  }
  return 0;
}



/* 00020eac FUN_00020eac */

/* Boundary evidence: original MIPS .pdata 00020eac..00021beb. Semantic name remains unreviewed. */

undefined4
FUN_00020eac(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,uint *param_5)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  wchar_t *pwVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint local_18 [2];
  
  uVar10 = 1;
  switch(param_3) {
  case 100:
    pcVar11 = "CIPCMsgHandler::msgFromMe";
    FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_NEXT_TRACK ","CIPCMsgHandler::msgFromMe");
    FUN_000231a4();
    FUN_0001ed08();
    FUN_000231a4();
    FUN_00019730();
    FUN_000231a4();
    FUN_000196f4();
    iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    if ((iVar5 != 0) && (iVar5 = FUN_000231a4(), *(int *)(iVar5 + 0x30) != 0)) {
      iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0);
      if (iVar5 != 1) {
        if (*param_5 == 0) {
          FUN_000231a4();
          FUN_0001edb0();
        }
        iVar5 = FUN_000231a4();
        *(undefined4 *)(iVar5 + 0x84) = 0;
        iVar5 = FUN_000231a4();
        FUN_0001dd20(*(int *)(iVar5 + 0x4c),1);
        iVar5 = FUN_000231a4();
        FUN_0001dc64(*(int *)(iVar5 + 0x4c),1);
        pwVar7 = L"%S  line %d";
        uVar10 = 0;
        FUN_00023aac(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe");
        FUN_000231a4();
        FUN_0001b1c0();
        iVar5 = FUN_000231a4();
        iVar9 = *(int *)(*(int *)(iVar5 + 0x4c) + 0x291e);
        iVar5 = FUN_00014db0(*(int *)(iVar5 + 0x4c),uVar10,pwVar7,(wchar_t *)pcVar11);
        iVar6 = FUN_000132fc(iVar5,iVar9);
        iVar5 = FUN_00014db0(iVar5,iVar9,pwVar7,(wchar_t *)pcVar11);
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        iVar5 = iVar6 * 0x220 + *(int *)(iVar5 + 0x38);
        sVar1 = *(short *)(iVar5 + 0x214);
        sVar2 = *(short *)(iVar5 + 0x212);
        iVar5 = FUN_000231a4();
        if ((((*(int *)(*(int *)(iVar5 + 0x4c) + 0x1adc) == 0) &&
             (iVar5 = FUN_000231a4(), *(int *)(*(int *)(iVar5 + 0x4c) + 0x2922) == 1)) &&
            (iVar5 = FUN_000231a4(), *(int *)(*(int *)(iVar5 + 0x4c) + 0x2926) == 1)) &&
           (iVar5 = FUN_000231a4(),
           (int)sVar1 + (int)sVar2 + -1 < *(int *)(*(int *)(iVar5 + 0x4c) + 0x291e) + 1)) {
          iVar5 = FUN_000231a4();
          uVar10 = 3;
          FUN_0001ddcc(*(int *)(iVar5 + 0x4c),3);
          iVar5 = FUN_000231a4();
          FUN_0001dccc(*(int *)(iVar5 + 0x4c),uVar10,pwVar7,(wchar_t *)pcVar11);
          iVar5 = FUN_000231a4();
          FUN_0001ddcc(*(int *)(iVar5 + 0x4c),1);
        }
        else {
          iVar5 = FUN_000231a4();
          FUN_0001dccc(*(int *)(iVar5 + 0x4c),iVar9,pwVar7,(wchar_t *)pcVar11);
        }
        iVar5 = FUN_000231a4();
        FUN_0001ed4c(*(int *)(iVar5 + 0x4c),0,0);
LAB_0002121c:
        iVar5 = FUN_000231a4();
        *(undefined4 *)(iVar5 + 0x84) = 1;
        return 1;
      }
      iVar5 = FUN_000231a4();
      if (-1 < *(int *)(iVar5 + 0x74)) {
        iVar5 = FUN_000231a4();
        iVar6 = FUN_000231a4();
        FUN_00019c94(*(int *)(iVar6 + 0x4c) + 8,*(undefined4 *)(iVar5 + 0x74));
      }
      FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
    }
  default:
switchD_00020efc_default:
    uVar10 = 0;
    break;
  case 0x65:
    FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_PREV_TRACK ","CIPCMsgHandler::msgFromMe");
    FUN_000231a4();
    FUN_0001ed08();
    FUN_000231a4();
    FUN_000196f4();
    FUN_000231a4();
    FUN_00019730();
    iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    if ((iVar5 != 0) && (iVar5 = FUN_000231a4(), *(int *)(iVar5 + 0x30) != 0)) {
      iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0);
      if (iVar5 != 1) {
        if (*param_5 == 0) {
          FUN_000231a4();
          FUN_0001edb0();
        }
        iVar5 = FUN_000231a4();
        *(undefined4 *)(iVar5 + 0x84) = 0;
        iVar5 = FUN_000231a4();
        FUN_0001dd20(*(int *)(iVar5 + 0x4c),1);
        iVar5 = FUN_000231a4();
        if (3 < *(int *)(*(int *)(iVar5 + 0x4c) + 0x2948)) {
          iVar5 = FUN_000231a4();
          *(undefined4 *)(iVar5 + 0x84) = 1;
          iVar5 = FUN_0001144c();
          FUN_0001111c(iVar5,0);
          iVar5 = FUN_000231a4();
          FUN_0001dd5c(*(int *)(iVar5 + 0x4c),0);
          iVar5 = FUN_000231a4();
          FUN_0001ed4c(*(int *)(iVar5 + 0x4c),0,1);
          iVar5 = FUN_000231a4();
          iVar5 = FUN_0001dc80(*(int *)(iVar5 + 0x4c));
          if (iVar5 == 1) {
            FUN_000231a4();
            FUN_0001fd28();
            FUN_000231a4();
            FUN_0001ecec();
          }
          FUN_000231a4();
          FUN_0001ed94();
          return 1;
        }
        iVar5 = FUN_000231a4();
        FUN_0001dce8(*(int *)(iVar5 + 0x4c));
        iVar5 = FUN_000231a4();
        FUN_0001ed4c(*(int *)(iVar5 + 0x4c),0,0);
        FUN_000231a4();
        FUN_0001b2a8();
        goto LAB_0002121c;
      }
      iVar5 = FUN_000231a4();
      if (-1 < *(int *)(iVar5 + 0x74)) {
        iVar5 = FUN_000231a4();
        iVar6 = FUN_000231a4();
        FUN_00019c94(*(int *)(iVar6 + 0x4c) + 8,*(undefined4 *)(iVar5 + 0x74));
      }
      FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
    }
    goto switchD_00020efc_default;
  case 0x66:
    FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_SHUFFLE ","CIPCMsgHandler::msgFromMe");
    iVar5 = FUN_000231a4();
    FUN_0001ddb0(*(int *)(iVar5 + 0x4c),*param_5);
    FUN_000231a4();
    FUN_00022f54();
    break;
  case 0x67:
    FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_REPEAT ","CIPCMsgHandler::msgFromMe");
    iVar5 = FUN_000231a4();
    FUN_0001ddcc(*(int *)(iVar5 + 0x4c),*param_5);
    break;
  case 0x68:
    iVar5 = FUN_000231a4();
    if ((*(int *)(iVar5 + 0x38) != 0) && (iVar5 = FUN_000231a4(), *(int *)(iVar5 + 0x18) == 0)) {
      memset(local_18,0,4);
      local_18[0] = local_18[0] & 0xffe03ff3 | 0x202003;
      iVar5 = FUN_000231a4();
      if (*(int *)(*(int *)(iVar5 + 0x4c) + 0x9a358) == 0) {
        iVar5 = FUN_000231a4();
        if ((*(int *)(iVar5 + 0xc) == 0) && (iVar5 = FUN_000231a4(), *(int *)(iVar5 + 0x14) == 0)) {
          local_18[0] = local_18[0] & 0xffffe13f | 0x130;
          goto LAB_000215f8;
        }
      }
      else {
        local_18[0] = local_18[0] & 0xffffe1ff | 0x100;
        iVar5 = FUN_000231a4();
        if (*(int *)(iVar5 + 0xc) == 0) {
          local_18[0] = local_18[0] & 0xffffff3f | 0x30;
          goto LAB_000215f8;
        }
      }
      local_18[0] = local_18[0] & 0xffffff1f | 0x10;
LAB_000215f8:
      FUN_00023aac(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe");
      FUN_00023580(5,1,9,4,(LPARAM *)local_18);
      return 1;
    }
    goto switchD_00020efc_default;
  case 0x69:
    memset(local_18,0,4);
    local_18[0] = local_18[0] & 0xffe03f03 | 0x2003;
    FUN_00023aac(5,3,L"%S *IDM_MUSB_MUSB_DEV_DISCONNECT-line %d","CIPCMsgHandler::msgFromMe");
    FUN_00023580(5,1,9,4,(LPARAM *)local_18);
    local_18[0] = local_18[0] & 0xffffff4f | 0x40;
    FUN_000237b4(5,1,9,4,local_18);
    FUN_00023aac(5,3,L"%S -IDM_MUSB_MUSB_DEV_DISCONNECT- line %d","CIPCMsgHandler::msgFromMe");
    break;
  case 0x6a:
    uVar8 = *param_5;
    iVar5 = FUN_0001144c();
    uVar3 = FUN_0001137c(iVar5);
    iVar5 = FUN_0001144c();
    uVar4 = FUN_00011230(iVar5);
    if ((-1 < (int)uVar3) && (uVar8 != uVar4)) {
      if ((int)uVar3 < (int)uVar8) {
        uVar8 = uVar3;
      }
      iVar5 = FUN_000231a4();
      FUN_0001dd5c(*(int *)(iVar5 + 0x4c),uVar8);
      iVar5 = FUN_0001144c();
      FUN_00011918(iVar5);
      iVar5 = FUN_0001144c();
      FUN_0001111c(iVar5,uVar8);
    }
    break;
  case 0x6b:
    iVar5 = FUN_000231a4();
    FUN_0001ecb8(*(int *)(iVar5 + 0x4c),param_5);
    FUN_000231a4();
    FUN_0001fcd0();
    break;
  case 0x6c:
    iVar5 = FUN_000231a4();
    FUN_0001de04(*(int *)(iVar5 + 0x4c));
    break;
  case 0x6d:
    FUN_00023aac(5,0,L"%S Line %d IDM_AMAIN_MUSB_VIRTUAL_PAUSE ","CIPCMsgHandler::msgFromMe");
    *(undefined4 *)(param_1 + 4) = 0;
    iVar5 = FUN_000231a4();
    FUN_0001dc00(*(int *)(iVar5 + 0x4c),0);
    iVar5 = FUN_000231a4();
    if (*(int *)(iVar5 + 0x70) == 1) {
      FUN_000231a4();
      FUN_00019730();
      FUN_000231a4();
      FUN_000196f4();
      iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0);
      if (iVar5 == 1) {
        iVar5 = FUN_000231a4();
        if (-1 < *(int *)(iVar5 + 0x74)) {
          iVar5 = FUN_000231a4();
          iVar6 = FUN_000231a4();
          FUN_00019c94(*(int *)(iVar6 + 0x4c) + 8,*(undefined4 *)(iVar5 + 0x74));
        }
        FUN_00023580(5,0x15,100,0,(LPARAM *)0x0);
      }
    }
    break;
  case 0x6e:
    iVar5 = FUN_000231a4();
    FUN_0001dc90(*(int *)(iVar5 + 0x4c));
    FUN_00023aac(5,0,L"%S Line %d IDM_MUSB_MUSB_VIRTUAL_RESUME getPlayFastStatus = %d ",
                 "CIPCMsgHandler::msgFromMe");
    iVar5 = FUN_000231a4();
    iVar5 = FUN_0001dc90(*(int *)(iVar5 + 0x4c));
    if (iVar5 == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      iVar5 = FUN_000231a4();
      FUN_0001dc1c(*(int *)(iVar5 + 0x4c),0);
      FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
    }
    else {
      *(undefined4 *)(param_1 + 4) = 1;
    }
    break;
  case 0x6f:
    pcVar11 = "CIPCMsgHandler::msgFromMe";
    FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_NEXT_TRACK ","CIPCMsgHandler::msgFromMe");
    FUN_000231a4();
    FUN_0001ed08();
    FUN_000231a4();
    FUN_00019730();
    FUN_000231a4();
    FUN_000196f4();
    iVar5 = FUN_000231a4();
    FUN_0001dc64(*(int *)(iVar5 + 0x4c),1);
    iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    if (((iVar5 != 0) && (iVar5 = FUN_000231a4(), *(int *)(iVar5 + 0x30) != 0)) &&
       (iVar5 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\BTCall",L"CallState",0),
       iVar5 != 1)) {
      if (*param_5 == 0) {
        FUN_000231a4();
        FUN_0001edb0();
      }
      iVar5 = FUN_000231a4();
      *(undefined4 *)(iVar5 + 0x84) = 0;
      iVar5 = FUN_000231a4();
      FUN_0001dd20(*(int *)(iVar5 + 0x4c),1);
      pwVar7 = L"%S  line %d";
      uVar10 = 0;
      FUN_00023aac(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe");
      iVar5 = FUN_000231a4();
      iVar9 = *(int *)(*(int *)(iVar5 + 0x4c) + 0x291e);
      iVar5 = FUN_00014db0(*(int *)(iVar5 + 0x4c),uVar10,pwVar7,(wchar_t *)pcVar11);
      iVar6 = FUN_000132fc(iVar5,iVar9);
      iVar5 = FUN_00014db0(iVar5,iVar9,pwVar7,(wchar_t *)pcVar11);
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      iVar5 = iVar6 * 0x220 + *(int *)(iVar5 + 0x38);
      sVar1 = *(short *)(iVar5 + 0x214);
      sVar2 = *(short *)(iVar5 + 0x212);
      iVar5 = FUN_000231a4();
      if (((*(int *)(*(int *)(iVar5 + 0x4c) + 0x1adc) == 0) &&
          (iVar5 = FUN_000231a4(), *(int *)(*(int *)(iVar5 + 0x4c) + 0x2922) == 1)) &&
         ((iVar5 = FUN_000231a4(), *(int *)(*(int *)(iVar5 + 0x4c) + 0x2926) == 1 &&
          (iVar5 = FUN_000231a4(),
          (int)sVar1 + (int)sVar2 + -1 < *(int *)(*(int *)(iVar5 + 0x4c) + 0x291e) + 1)))) {
        iVar5 = FUN_000231a4();
        uVar10 = 3;
        FUN_0001ddcc(*(int *)(iVar5 + 0x4c),3);
        iVar5 = FUN_000231a4();
        FUN_0001dccc(*(int *)(iVar5 + 0x4c),uVar10,pwVar7,(wchar_t *)pcVar11);
        iVar5 = FUN_000231a4();
        FUN_0001ddcc(*(int *)(iVar5 + 0x4c),1);
      }
      else {
        iVar5 = FUN_000231a4();
        FUN_0001dccc(*(int *)(iVar5 + 0x4c),iVar9,pwVar7,(wchar_t *)pcVar11);
      }
      iVar5 = FUN_000231a4();
      FUN_0001ed4c(*(int *)(iVar5 + 0x4c),0,0);
      iVar5 = FUN_000231a4();
      *(undefined4 *)(iVar5 + 0x84) = 1;
      FUN_000231a4();
      FUN_0001b234();
      return 1;
    }
    goto switchD_00020efc_default;
  }
  return uVar10;
}



/* 00021bec FUN_00021bec */

/* Boundary evidence: original MIPS .pdata 00021bec..00021c57. Semantic name remains unreviewed. */

bool FUN_00021bec(undefined4 param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  
  if (param_3 == 10) {
    iVar1 = FUN_000231a4();
    FUN_0001dd04(*(int *)(iVar1 + 0x4c));
    FUN_00023580(5,1,0xb,0,(LPARAM *)0x0);
  }
  return param_3 == 10;
}



/* 00021c58 FUN_00021c58 */

/* Boundary evidence: original MIPS .pdata 00021c58..00021ce7. Semantic name remains unreviewed. */

void FUN_00021c58(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_000231a4();
  piVar2 = (int *)FUN_0001ecdc(*(int *)(iVar1 + 0x4c));
  iVar1 = *piVar2;
  FUN_000231a4();
  FUN_0001ec88();
  if ((char)iVar1 == '\0') {
    FUN_00023580(5,0x15,0x66,0,(LPARAM *)0x0);
  }
  else {
    iVar3 = FUN_000231a4();
    FUN_0001faf8(*(int *)(iVar3 + 0x4c),iVar1);
    iVar1 = FUN_000231a4();
    FUN_0001ed68(*(int *)(iVar1 + 0x4c));
  }
  return;
}



/* 00021ce8 FUN_00021ce8 */

undefined4 * FUN_00021ce8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002ac08;
  param_1[1] = 0;
  return param_1;
}



/* 00021d00 FUN_00021d00 */

/* Boundary evidence: original MIPS .pdata 00021d00..0002271b. Semantic name remains unreviewed. */

undefined4
FUN_00021d00(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint local_a68;
  uint local_a64;
  uint local_a60;
  uint local_a5c;
  undefined4 local_a58;
  uint local_a54;
  undefined4 local_a50;
  wchar_t local_a48;
  undefined1 auStack_a46 [518];
  wchar_t local_840;
  undefined1 auStack_83e [2078];
  uint local_20;
  
  local_20 = DAT_0002f960;
  local_a68 = 0;
  local_a64 = 0;
  local_a58 = param_2;
  local_a54 = param_3;
  local_a50 = param_4;
  iVar1 = FUN_000231a4();
  uVar8 = local_a54 & 0xffff;
  if ((((*(int *)(iVar1 + 0x18) == 0) && (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x38) != 0)) ||
      (uVar8 == 0x71)) || ((uVar8 == 0x73 || (uVar8 == 0x74)))) {
    uVar7 = 1;
    switch(uVar8) {
    case 100:
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_PREV_TRACK ","CIPCMsgHandler::msgFromAppMain");
      local_a68 = *param_5;
      FUN_00023580(5,5,0x65,4,(LPARAM *)&local_a68);
      break;
    case 0x65:
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_NEXT_TRACK ","CIPCMsgHandler::msgFromAppMain");
      local_a68 = *param_5;
      FUN_00023580(5,5,100,4,(LPARAM *)&local_a68);
      break;
    case 0x66:
    case 0x68:
      FUN_000231a4();
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_FAST_FWD/RWD_START[%d], g_bFFREWStartTimerStatus : %d",
                   "CIPCMsgHandler::msgFromAppMain");
      iVar1 = FUN_000231a4();
      if (*(int *)(iVar1 + 0x78) == 1) goto LAB_000226ec;
      uVar6 = 1;
      if (uVar8 != 0x66) {
        uVar6 = 2;
      }
      iVar1 = FUN_000231a4();
      FUN_0001de20(*(int *)(iVar1 + 0x4c),uVar6);
      break;
    case 0x67:
    case 0x69:
      FUN_00023aac(5,1,L"%S IDM_AMAIN_MUSB_FAST_FWD/RWD_END[%d]","CIPCMsgHandler::msgFromAppMain");
      iVar1 = FUN_000231a4();
      FUN_0001de3c(*(int *)(iVar1 + 0x4c));
      if (*(int *)(param_1 + 4) == 1) {
        FUN_00023580(5,5,0x6e,0,(LPARAM *)0x0);
      }
      break;
    case 0x6a:
      local_a5c = *param_5;
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_SHUFFLE ","CIPCMsgHandler::msgFromAppMain");
      FUN_00023580(5,5,0x66,4,(LPARAM *)&local_a5c);
      break;
    case 0x6b:
      local_a60 = *param_5;
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_REPEAT ","CIPCMsgHandler::msgFromAppMain");
      FUN_00023580(5,5,0x67,4,(LPARAM *)&local_a60);
      break;
    case 0x6c:
      uVar8 = *param_5;
      iVar1 = FUN_000231a4();
      iVar1 = FUN_0001dc80(*(int *)(iVar1 + 0x4c));
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_PLAY_STATUS stTemp %d, current %d",
                   "CIPCMsgHandler::msgFromAppMain");
      FUN_000231a4();
      FUN_0001ed08();
      if ((iVar1 == 1) || (uVar8 != 1)) {
        if (uVar8 == 2) {
          FUN_00023aac(5,0,L"%S ST_PAUSE","CIPCMsgHandler::msgFromAppMain");
          iVar1 = FUN_000231a4();
          FUN_0001dd20(*(int *)(iVar1 + 0x4c),0);
          iVar1 = FUN_000231a4();
          if (*(int *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) != 0) {
            iVar1 = FUN_000231a4();
            *(undefined4 *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) = 2;
          }
        }
      }
      else {
        FUN_000231a4();
        FUN_000231a4();
        FUN_00023aac(5,0,L"%S ST_PLAY getVirtualPauseStatus %d, getVirtualPauseBeforeStatus",
                     "CIPCMsgHandler::msgFromAppMain");
        iVar1 = FUN_000231a4();
        if (*(int *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) == 0) {
          iVar1 = FUN_000231a4();
          if (*(int *)(iVar1 + 0x1c) == 0) {
            iVar1 = FUN_000231a4();
            iVar5 = *(int *)(*(int *)(iVar1 + 0x4c) + 0x1ad8);
            iVar1 = FUN_000231a4();
            iVar1 = FUN_0001dc98(*(int *)(iVar1 + 0x4c));
            iVar4 = FUN_000231a4();
            FUN_0001dca8(*(int *)(iVar4 + 0x4c),iVar1,1,(uint)(iVar5 != 0),1);
          }
          else {
            iVar1 = FUN_000231a4();
            FUN_0001dd3c(*(int *)(iVar1 + 0x4c),0);
          }
        }
        else {
          iVar1 = FUN_000231a4();
          FUN_0001dc64(*(int *)(iVar1 + 0x4c),1);
          iVar1 = FUN_000231a4();
          *(undefined4 *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) = 1;
        }
      }
      break;
    case 0x6d:
      uVar8 = *param_5;
      iVar1 = FUN_0001144c();
      uVar2 = FUN_0001137c(iVar1);
      iVar1 = FUN_0001144c();
      uVar3 = FUN_00011230(iVar1);
      if ((-1 < (int)uVar2) && (uVar8 != uVar3)) {
        if ((int)uVar2 < (int)uVar8) {
          uVar8 = uVar2;
        }
        iVar1 = FUN_0001144c();
        FUN_00011918(iVar1);
        iVar1 = FUN_0001144c();
        FUN_0001111c(iVar1,uVar8);
        iVar1 = FUN_000231a4();
        FUN_0001ed30(*(int *)(iVar1 + 0x4c));
        iVar1 = FUN_000231a4();
        iVar1 = FUN_0001dc80(*(int *)(iVar1 + 0x4c));
        if (iVar1 == 1) {
          FUN_000231a4();
          FUN_0001fd28();
        }
      }
      break;
    case 0x6e:
      FUN_00023580(5,5,0x6d,0,(LPARAM *)0x0);
      break;
    case 0x6f:
      FUN_00023580(5,5,0x6e,0,(LPARAM *)0x0);
      break;
    case 0x70:
      local_a64 = *param_5;
      if (((int)((local_a64 & 0xffffff00) << 8) < 0) || ((char)local_a64 == '\0')) {
        FUN_00021c58();
        iVar1 = FUN_000231a4();
        FUN_0001faf8(*(int *)(iVar1 + 0x4c),local_a64);
      }
      else {
        FUN_00023580(5,5,0x6b,4,(LPARAM *)&local_a64);
      }
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_SELECT_CATEGORY nCat:%d nSelIdx:%d",
                   "CIPCMsgHandler::msgFromAppMain");
      break;
    case 0x71:
      iVar1 = FUN_000231a4();
      FUN_0001e9fc(*(int *)(iVar1 + 0x4c));
      break;
    case 0x72:
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_MOVE_PLAY_FOLDER","CIPCMsgHandler::msgFromAppMain");
      FUN_00021c58();
      iVar1 = FUN_000231a4();
      iVar1 = FUN_0001dc98(*(int *)(iVar1 + 0x4c));
      iVar4 = FUN_000231a4();
      FUN_0001e74c(*(int *)(iVar4 + 0x4c),iVar1);
      break;
    case 0x73:
      iVar1 = FUN_000231a4();
      if ((*(int *)(iVar1 + 0x38) != 0) && (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 4) != 0)) {
LAB_000224a0:
        iVar1 = FUN_000231a4();
        FUN_0001c17c(*(int *)(iVar1 + 0x4c) + 8,L"\\Storage Card2\\USBMusicResume.dat");
      }
      break;
    case 0x74:
      break;
    case 0x75:
      FUN_00021c58();
      iVar1 = FUN_000231a4();
      FUN_0001f4a8(*(int *)(iVar1 + 0x4c),0);
      break;
    case 0x76:
      FUN_00023aac(5,0,L"%S IDM_AMAIN_MUSB_ERROR_NEXT_PLAY ","CIPCMsgHandler::msgFromAppMain");
      iVar1 = FUN_000231a4();
      if (*(int *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) == 2) {
        iVar1 = FUN_000231a4();
        *(undefined4 *)(*(int *)(iVar1 + 0x4c) + 0x1ad8) = 1;
      }
      local_a68 = *param_5;
      FUN_00023580(5,5,0x6f,4,(LPARAM *)&local_a68);
      break;
    case 0x77:
      iVar1 = FUN_000231a4();
      FUN_0001dd20(*(int *)(iVar1 + 0x4c),0);
      break;
    case 0x78:
      iVar1 = FUN_000231a4();
      if (0 < *(int *)(iVar1 + 0x38)) goto LAB_000224a0;
      break;
    case 0x79:
      iVar1 = FUN_000231a4();
      iVar1 = FUN_0001dc98(*(int *)(iVar1 + 0x4c));
      iVar4 = FUN_000231a4();
      FUN_0001e80c(*(int *)(iVar4 + 0x4c),iVar1);
      break;
    case 0x7a:
      uVar8 = *param_5;
      iVar1 = FUN_000231a4();
      *(uint *)(iVar1 + 0x30) = uVar8;
      if ((uVar8 == 0) &&
         ((iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x1c) == 0 ||
          (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x78) != 0)))) {
        FUN_00023580(5,0x15,0x6f,0,(LPARAM *)0x0);
        iVar1 = FUN_000231a4();
        *(undefined4 *)(iVar1 + 0x1c) = 1;
        FUN_000231a4();
        FUN_00023aac(5,3,
                     L"%S Line %d == IDM_AMAIN_MUSB_AUDIO_PATH_USB_STATUS g_nLastPlayedIndex = %d",
                     "CIPCMsgHandler::msgFromAppMain");
        iVar1 = FUN_000231a4();
        if (-1 < *(int *)(iVar1 + 0x74)) {
          iVar1 = FUN_000231a4();
          iVar4 = FUN_000231a4();
          FUN_00019c94(*(int *)(iVar4 + 0x4c) + 8,*(undefined4 *)(iVar1 + 0x74));
          iVar1 = FUN_000231a4();
          iVar4 = FUN_000231a4();
          FUN_0001b760(*(int *)(iVar4 + 0x4c) + 8,*(int *)(iVar1 + 0x74),1,0);
          local_840 = L'\0';
          memset(auStack_83e,0,0x81e);
          iVar1 = FUN_000231a4();
          iVar4 = FUN_000231a4();
          FUN_00013350(*(int *)(iVar4 + 0x48),*(int *)(iVar1 + 0x74),&local_840);
          if (local_840 != L'\\') {
            local_a48 = L'\0';
            memset(auStack_a46,0,0x206);
            swprintf(&local_a48,0x29278,&local_840);
            memcpy(&local_840,&local_a48,0x208);
          }
          iVar1 = FUN_000231a4();
          FUN_0001a318(*(int *)(iVar1 + 0x4c) + 8);
        }
      }
      break;
    case 0x7b:
      uVar8 = *param_5;
      iVar1 = FUN_000231a4();
      *(uint *)(iVar1 + 0x34) = uVar8;
      break;
    case 0x7c:
      iVar1 = FUN_000231a4();
      if (0 < *(int *)(iVar1 + 0x38)) {
        iVar1 = FUN_000231a4();
        FUN_0001c2e8(*(int *)(iVar1 + 0x4c) + 8,L"\\Storage Card2\\USBMusicResume.dat");
      }
      break;
    default:
      FUN_00023aac(5,0,L"%S unsupported mssage ","CIPCMsgHandler::msgFromAppMain");
      goto LAB_000226ec;
    }
    FUN_00025510(local_20);
  }
  else {
LAB_000226ec:
    FUN_00025510(local_20);
    uVar7 = 0;
  }
  return uVar7;
}



/* 0002271c FUN_0002271c */

/* Boundary evidence: original MIPS .pdata 0002271c..00022803. Semantic name remains unreviewed. */

undefined4 FUN_0002271c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  ushort auStack_18 [8];
  
  puVar1 = (uint *)FUN_0002325c(auStack_18,param_3,param_4,(undefined4 *)&stack0x00000010);
  uVar2 = *puVar1 & 0xffff;
  if (uVar2 == 1) {
    FUN_00021bec(param_1,*puVar1,(short)puVar1[1]);
  }
  else if (uVar2 == 5) {
    FUN_00020eac(param_1,*puVar1,(short)puVar1[1],puVar1[2],(uint *)puVar1[3]);
  }
  else if (uVar2 == 0x15) {
    FUN_00021d00(param_1,*puVar1,puVar1[1],puVar1[2],(uint *)puVar1[3]);
  }
  return 1;
}



/* 00022804 FUN_00022804 */

/* Boundary evidence: original MIPS .pdata 00022804..0002285b. Semantic name remains unreviewed. */

undefined4 * FUN_00022804(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b450;
  FUN_000209e0(param_1 + 1);
  FUN_00021ce8(param_1 + 2);
  return param_1;
}



/* 0002285c Unwind@0002285c */

/* Boundary evidence: original MIPS .pdata 0002285c..0002288f. Semantic name remains unreviewed. */

void Unwind_0002285c(void)

{
  int *in_v0;
  
  FUN_000209d0((undefined4 *)(*in_v0 + 4));
  return;
}



/* 00022890 FUN_00022890 */

/* Boundary evidence: original MIPS .pdata 00022890..000228e7. Semantic name remains unreviewed. */

void FUN_00022890(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b450;
  FUN_000209d0(param_1 + 2);
  FUN_000209d0(param_1 + 1);
  return;
}



/* 000228e8 Unwind@000228e8 */

/* Boundary evidence: original MIPS .pdata 000228e8..0002291b. Semantic name remains unreviewed. */

void Unwind_000228e8(void)

{
  int *in_v0;
  
  FUN_000209d0((undefined4 *)(*in_v0 + 4));
  return;
}



/* 0002291c FUN_0002291c */

/* Boundary evidence: original MIPS .pdata 0002291c..00022987. Semantic name remains unreviewed. */

void FUN_0002291c(void)

{
  undefined4 *puVar1;
  
  if (DAT_00034f2c == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00034f2c = (undefined4 *)0x0;
    }
    else {
      DAT_00034f2c = FUN_00022804(puVar1);
    }
  }
  return;
}



/* 00022988 Unwind@00022988 */

/* Boundary evidence: original MIPS .pdata 00022988..000229b7. Semantic name remains unreviewed. */

void Unwind_00022988(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 000229b8 FUN_000229b8 */

/* Boundary evidence: original MIPS .pdata 000229b8..00022a3f. Semantic name remains unreviewed. */

undefined4 FUN_000229b8(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  if (param_3 == 0x8002) {
    FUN_00020a38();
  }
  else if (param_3 == 0x8064) {
    FUN_0002271c(param_1 + 8,param_2,0x8064,param_4);
  }
  else {
    FUN_00023aac(5,2,L"%S [unknown] %x, %d, %d","CMsgHandler::msgHandler");
  }
  return 1;
}



/* 00022a40 FUN_00022a40 */

/* Boundary evidence: original MIPS .pdata 00022a40..00022a8b. Semantic name remains unreviewed. */

undefined4 * FUN_00022a40(undefined4 *param_1,uint param_2)

{
  FUN_00022890(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00022a8c FUN_00022a8c */

/* Boundary evidence: original MIPS .pdata 00022a8c..00022b3f. Semantic name remains unreviewed. */

void FUN_00022a8c(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  while (DAT_00034f30 == 0) {
    DVar1 = WaitForSingleObject(DAT_00034f40,0xffffffff);
    if (DVar1 == 0) {
      if (DAT_00034f30 != 0) break;
      iVar2 = FUN_000231a4();
      iVar3 = *(int *)(*(int *)(iVar2 + 0x4c) + 0x2926);
      iVar2 = FUN_000231a4();
      FUN_0001dd94(*(int *)(iVar2 + 0x4c),iVar3);
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022b40 FUN_00022b40 */

/* Boundary evidence: original MIPS .pdata 00022b40..00022bd7. Semantic name remains unreviewed. */

void FUN_00022b40(void)

{
  DWORD DVar1;
  int iVar2;
  
  while (DAT_00034f34 == 0) {
    DVar1 = WaitForSingleObject(DAT_00034f3c,0xffffffff);
    if (DVar1 == 0) {
      if (DAT_00034f34 != 0) break;
      iVar2 = FUN_000231a4();
      FUN_0001ef48(*(int *)(iVar2 + 0x4c),1,0);
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022bd8 FUN_00022bd8 */

/* Boundary evidence: original MIPS .pdata 00022bd8..00022c7b. Semantic name remains unreviewed. */

void FUN_00022bd8(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  while (DAT_00034f38 == 0) {
    DVar1 = WaitForSingleObject(DAT_00034f44,0xffffffff);
    if (DVar1 == 0) {
      if (DAT_00034f38 != 0) break;
      iVar2 = FUN_000231a4();
      iVar3 = FUN_000231a4();
      FUN_0001fd6c(*(int *)(iVar3 + 0x4c),*(int *)(iVar2 + 0xc));
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022c7c FUN_00022c7c */

undefined4 * FUN_00022c7c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b550;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* 00022c9c FUN_00022c9c */

/* Boundary evidence: original MIPS .pdata 00022c9c..00022d13. Semantic name remains unreviewed. */

bool FUN_00022c9c(int param_1)

{
  HANDLE pvVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    DAT_00034f34 = 0;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022b40,(LPVOID)0x0,0,(LPDWORD)0x0);
    *(HANDLE *)(param_1 + 4) = pvVar1;
  }
  else {
    NKDbgPrintfW(L"ERROR : createUSB_SearchThread() m_hUSBSearchThread %0x%x \n");
  }
  return *(int *)(param_1 + 4) != 0;
}



/* 00022d14 FUN_00022d14 */

/* Boundary evidence: original MIPS .pdata 00022d14..00022d83. Semantic name remains unreviewed. */

void FUN_00022d14(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    DAT_00034f34 = 1;
    EventModify(DAT_00034f3c,3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 4),0x5dc);
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



/* 00022d84 FUN_00022d84 */

/* Boundary evidence: original MIPS .pdata 00022d84..00022dfb. Semantic name remains unreviewed. */

bool FUN_00022d84(int param_1)

{
  HANDLE pvVar1;
  
  if (*(int *)(param_1 + 8) == 0) {
    DAT_00034f30 = 0;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022a8c,(LPVOID)0x0,0,(LPDWORD)0x0);
    *(HANDLE *)(param_1 + 8) = pvVar1;
  }
  else {
    NKDbgPrintfW(L"ERROR : createUSB_SearchThread() m_hUSBShuffleThread %0x%x \n");
  }
  return *(int *)(param_1 + 8) != 0;
}



/* 00022dfc FUN_00022dfc */

/* Boundary evidence: original MIPS .pdata 00022dfc..00022e6b. Semantic name remains unreviewed. */

void FUN_00022dfc(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    DAT_00034f30 = 1;
    EventModify(DAT_00034f40,3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 8),0x5dc);
    CloseHandle(*(HANDLE *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



/* 00022e6c FUN_00022e6c */

/* Boundary evidence: original MIPS .pdata 00022e6c..00022ee3. Semantic name remains unreviewed. */

bool FUN_00022e6c(int param_1)

{
  HANDLE pvVar1;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    DAT_00034f38 = 0;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022bd8,(LPVOID)0x0,0,(LPDWORD)0x0);
    *(HANDLE *)(param_1 + 0xc) = pvVar1;
  }
  else {
    NKDbgPrintfW(L"ERROR : createUSBBootResumeThread() m_hUSBBBootThread %0x%x \n");
  }
  return *(int *)(param_1 + 0xc) != 0;
}



/* 00022ee4 FUN_00022ee4 */

/* Boundary evidence: original MIPS .pdata 00022ee4..00022f53. Semantic name remains unreviewed. */

void FUN_00022ee4(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    DAT_00034f38 = 1;
    EventModify(DAT_00034f44,3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),0x5dc);
    CloseHandle(*(HANDLE *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}



/* 00022f54 FUN_00022f54 */

/* Boundary evidence: original MIPS .pdata 00022f54..00022f7f. Semantic name remains unreviewed. */

void FUN_00022f54(void)

{
  if (DAT_00034f40 != 0) {
    EventModify(DAT_00034f40,3);
  }
  return;
}



/* 00022f80 FUN_00022f80 */

/* Boundary evidence: original MIPS .pdata 00022f80..00022fab. Semantic name remains unreviewed. */

void FUN_00022f80(void)

{
  if (DAT_00034f3c != 0) {
    EventModify(DAT_00034f3c,3);
  }
  return;
}



/* 00022fac FUN_00022fac */

/* Boundary evidence: original MIPS .pdata 00022fac..00022fd7. Semantic name remains unreviewed. */

void FUN_00022fac(void)

{
  if (DAT_00034f44 != 0) {
    EventModify(DAT_00034f44,3);
  }
  return;
}



/* 00022fd8 FUN_00022fd8 */

/* Boundary evidence: original MIPS .pdata 00022fd8..0002307b. Semantic name remains unreviewed. */

void FUN_00022fd8(int param_1)

{
  DAT_00034f44 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00034f3c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_00034f40 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  FUN_00022c9c(param_1);
  FUN_00022e6c(param_1);
  FUN_00022d84(param_1);
  return;
}



/* 0002307c FUN_0002307c */

/* Boundary evidence: original MIPS .pdata 0002307c..00023127. Semantic name remains unreviewed. */

void FUN_0002307c(int param_1)

{
  FUN_00022d14(param_1);
  FUN_00022ee4(param_1);
  FUN_00022dfc(param_1);
  if (DAT_00034f44 != 0) {
    CloseHandle((HANDLE)DAT_00034f44);
    DAT_00034f44 = 0;
  }
  if (DAT_00034f3c != 0) {
    CloseHandle((HANDLE)DAT_00034f3c);
    DAT_00034f3c = 0;
  }
  if (DAT_00034f40 != 0) {
    CloseHandle((HANDLE)DAT_00034f40);
    DAT_00034f40 = 0;
  }
  return;
}



/* 00023128 FUN_00023128 */

/* Boundary evidence: original MIPS .pdata 00023128..0002314b. Semantic name remains unreviewed. */

void FUN_00023128(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b550;
  FUN_0002307c((int)param_1);
  return;
}



/* 0002314c FUN_0002314c */

/* Boundary evidence: original MIPS .pdata 0002314c..000231a3. Semantic name remains unreviewed. */

undefined4 * FUN_0002314c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002b550;
  FUN_0002307c((int)param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000231a4 FUN_000231a4 */

undefined4 FUN_000231a4(void)

{
  return DAT_00035138;
}



/* 000231b0 FUN_000231b0 */

/* Boundary evidence: original MIPS .pdata 000231b0..0002325b. Semantic name remains unreviewed. */

void FUN_000231b0(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x30) = 1;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  iVar2 = param_1;
  uVar1 = FUN_00014db0(param_1,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0x48) = uVar1;
  uVar1 = FUN_0001eea4(iVar2,param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 100) = 1;
  *(undefined4 *)(param_1 + 0x6c) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0x116;
  *(undefined4 *)(param_1 + 0x80) = 0x116;
  return;
}



/* 0002325c FUN_0002325c */

/* Boundary evidence: original MIPS .pdata 0002325c..00023327. Semantic name remains unreviewed. */

ushort * FUN_0002325c(ushort *param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  *param_1 = 0;
  memset(param_1 + 1,0,0xe);
  if (param_2 == 0x4a) {
    puVar3 = (uint *)*param_4;
    uVar1 = *puVar3;
    uVar2 = puVar3[2];
    *(uint *)(param_1 + 4) = puVar3[1];
    *(uint *)(param_1 + 6) = uVar2;
    *param_1 = (ushort)((uVar1 & 0x7fff) / 100);
    param_1[2] = *(ushort *)((int)puVar3 + 2);
  }
  else if (param_2 == 0x8064) {
    param_1[2] = (ushort)(param_3 >> 0x10);
    *param_1 = (ushort)(param_3 >> 8) & 0xff;
    *(uint *)(param_1 + 4) = param_3 & 0xff;
    *(undefined4 **)(param_1 + 6) = param_4;
  }
  return param_1;
}



/* 00023328 FUN_00023328 */

/* Boundary evidence: original MIPS .pdata 00023328..00023473. Semantic name remains unreviewed. */

void FUN_00023328(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1028;
  WCHAR aWStack_1018 [1024];
  wchar_t awStack_818 [1026];
  uint local_14;
  
  local_14 = DAT_0002f960;
  local_resc = param_4;
  if ((param_2 == 3) ||
     ((*(int *)(&DAT_00034f48 + param_1 * 4) != 0 &&
      (*(int *)(&DAT_00034fec + param_1 * 4) <= param_2)))) {
    vswprintf_s(awStack_818,0x400,param_3,(va_list)&local_resc);
    GetLocalTime(&_Stack_1028);
    if (param_1 < 0x29) {
      pwVar3 = u_MgrDbg_0002f440 + param_1 * 0x10;
    }
    else {
      pwVar3 = u_MgrDbg_0002f440;
    }
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    wsprintfW(aWStack_1018,L"[%02d:%02d:%02d:%d,%05d][%s] %s\r\n",(uint)_Stack_1028.wHour,
              (uint)_Stack_1028.wMinute,(uint)_Stack_1028.wSecond,DVar2 % 1000,DVar1 / 10,pwVar3,
              awStack_818);
    OutputDebugStringW(aWStack_1018);
  }
  FUN_00025510(local_14);
  return;
}



/* 00023474 FUN_00023474 */

/* Boundary evidence: original MIPS .pdata 00023474..000234cf. Semantic name remains unreviewed. */

wchar_t * FUN_00023474(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x29) {
    pwVar1 = u_MgrDbg_0002f440 + param_1 * 0x10;
  }
  else {
    FUN_00023328(0x25,3,L"%S fail iPid=%d","IntGetProcessName");
    pwVar1 = u_MgrDbg_0002f440;
  }
  return pwVar1;
}



/* 000234d0 FUN_000234d0 */

/* Boundary evidence: original MIPS .pdata 000234d0..0002357f. Semantic name remains unreviewed. */

int * FUN_000234d0(int param_1)

{
  wchar_t *lpClassName;
  HWND pHVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_00035094 + param_1 * 4);
  if (*piVar2 == 0) {
    lpClassName = FUN_00023474(param_1);
    pHVar1 = FindWindowW(lpClassName,(LPCWSTR)0x0);
    *piVar2 = (int)pHVar1;
    if (pHVar1 == (HWND)0x0) {
      GetLastError();
      FUN_00023474(param_1);
      FUN_00023328(0x25,3,L"%S FindWindow fail, %s(%d), errCode=%d","IntGetProcessHandle");
    }
  }
  return piVar2;
}



/* 00023580 FUN_00023580 */

/* Boundary evidence: original MIPS .pdata 00023580..000237b3. Semantic name remains unreviewed. */

undefined4 FUN_00023580(uint param_1,int param_2,int param_3,uint param_4,LPARAM *param_5)

{
  int *piVar1;
  BOOL BVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  LPARAM lParam;
  HWND hWnd;
  LPARAM local_30 [2];
  
  local_30[0] = 0;
  piVar1 = FUN_000234d0(param_2);
  hWnd = (HWND)*piVar1;
  if (hWnd == (HWND)0x0) {
    FUN_00023474(param_2);
    FUN_00023328(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcPostMsg"
                );
  }
  else {
    if (param_4 < 5) {
      memcpy(local_30,param_5,param_4);
      lParam = local_30[0];
    }
    else {
      FUN_00023328(0x25,3,L"%S extra data overflow, size=%d","IpcPostMsg");
      lParam = *param_5;
    }
    BVar2 = PostMessageW(hWnd,0x8064,(param_3 << 8 | param_1) << 8 | param_4,lParam);
    if (BVar2 != 0) {
      if (param_3 != 0x65) {
        FUN_00023474(param_2);
        FUN_00023474(param_1);
        FUN_00023328(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcPostMsg");
      }
      return 1;
    }
    DVar3 = GetLastError();
    if (DVar3 == 6) {
      pwVar4 = L"%S invalid handle";
    }
    else if (DVar3 == 0x578) {
      pwVar4 = L"%S invalid window handle";
    }
    else if (DVar3 == 0x583) {
      pwVar4 = L"%S class does not exist";
    }
    else {
      if (DVar3 != 0x5b4) {
        FUN_00023328(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcPostMsg")
        ;
        return 0;
      }
      pwVar4 = L"%S timed out";
    }
    FUN_00023328(0x25,3,pwVar4,"IpcPostMsg");
  }
  return 0;
}



/* 000237b4 FUN_000237b4 */

/* Boundary evidence: original MIPS .pdata 000237b4..00023a57. Semantic name remains unreviewed. */

undefined4 FUN_000237b4(uint param_1,int param_2,int param_3,uint param_4,void *param_5)

{
  int *piVar1;
  int iVar2;
  DWORD local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  void *local_28;
  
  local_38 = 0;
  local_34 = 0;
  piVar1 = FUN_000234d0(param_2);
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    FUN_00023474(param_2);
    FUN_00023328(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcSendMsg"
                );
  }
  else {
    if (param_4 < 5) {
      memcpy(&local_34,param_5,param_4);
      iVar2 = SendMessageTimeout(iVar2,0x8064,(param_3 << 8 | param_1) << 8 | param_4 & 0xff,
                                 local_34,0,0x5dc,&local_38);
    }
    else {
      FUN_00023328(0x25,3,L"%S extra data send using wm_copydata, size=%d","IpcSendMsg");
      memset(&local_30,0,0xc);
      local_28 = param_5;
      local_30 = param_1 * 100 + param_2 + 0x8000 | param_3 << 0x10;
      local_2c = param_4;
      iVar2 = SendMessageTimeout(iVar2,0x4a,0,&local_30,0,0x5dc,&local_38);
    }
    if (iVar2 != 0) {
      FUN_00023474(param_2);
      FUN_00023474(param_1);
      FUN_00023328(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcSendMsg");
      return 1;
    }
    local_38 = GetLastError();
    if (local_38 == 0) {
      FUN_00023328(0x25,3,L"%S timeout, src=%d, dst=%d, cmd=%d","IpcSendMsg");
    }
    else if (local_38 == 6) {
      FUN_00023328(0x25,3,L"%S invalid handle, src=%d, dst=%d, cmd=%d","IpcSendMsg");
    }
    else if (local_38 == 0x578) {
      FUN_00023328(0x25,3,L"%S invalid window handle, src=%d, dst=%d, cmd=%d","IpcSendMsg");
    }
    else {
      FUN_00023328(0x25,3,L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, errCode=%d",
                   "IpcSendMsg");
    }
  }
  return 0;
}



/* 00023a58 FUN_00023a58 */

/* Boundary evidence: original MIPS .pdata 00023a58..00023aab. Semantic name remains unreviewed. */

wchar_t * FUN_00023a58(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x29) {
    pwVar1 = FUN_00023474(param_1);
  }
  else {
    FUN_00023328(0x25,3,L"%S overflow, pid=%d","IpcGetProcessName");
    pwVar1 = u_MgrDbg_0002f440;
  }
  return pwVar1;
}



/* 00023aac FUN_00023aac */

/* Boundary evidence: original MIPS .pdata 00023aac..00023bf3. Semantic name remains unreviewed. */

void FUN_00023aac(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  DWORD DVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  undefined4 local_resc;
  _SYSTEMTIME _Stack_1028;
  WCHAR aWStack_1018 [1024];
  wchar_t awStack_818 [1026];
  uint local_14;
  
  local_14 = DAT_0002f960;
  local_resc = param_4;
  if ((param_2 == 3) ||
     ((*(int *)(&DAT_00034f48 + param_1 * 4) != 0 &&
      (*(int *)(&DAT_00034fec + param_1 * 4) <= param_2)))) {
    vswprintf_s(awStack_818,0x400,param_3,(va_list)&local_resc);
    GetLocalTime(&_Stack_1028);
    if (param_1 < 0x29) {
      pwVar3 = u_MgrDbg_0002f440 + param_1 * 0x10;
    }
    else {
      pwVar3 = u_MgrDbg_0002f440;
    }
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    wsprintfW(aWStack_1018,L"[%02d:%02d:%02d:%d,%05d][%s] %s\r\n",0xd,(uint)_Stack_1028.wMinute,
              (uint)_Stack_1028.wSecond,DVar2 % 1000,DVar1 / 10,pwVar3,awStack_818);
    OutputDebugStringW(aWStack_1018);
  }
  FUN_00025510(local_14);
  return;
}



/* 00023bf4 FUN_00023bf4 */

void FUN_00023bf4(int param_1,undefined4 param_2)

{
  if (param_1 < 0x29) {
    *(undefined4 *)(&DAT_00034f48 + param_1 * 4) = param_2;
  }
  return;
}



/* 00023c1c FUN_00023c1c */

void FUN_00023c1c(int param_1,undefined4 param_2)

{
  if (param_1 < 0x29) {
    *(undefined4 *)(&DAT_00034fec + param_1 * 4) = param_2;
  }
  return;
}



/* 00023c44 FUN_00023c44 */

/* Boundary evidence: original MIPS .pdata 00023c44..00023cd7. Semantic name remains unreviewed. */

void FUN_00023c44(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_00023328(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::write");
  }
  else {
    memcpy((void *)(*(int *)(param_1 + 8) + param_3),param_2,param_4);
  }
  return;
}



/* 00023cd8 FUN_00023cd8 */

/* Boundary evidence: original MIPS .pdata 00023cd8..00023ce3. Semantic name remains unreviewed. */

undefined4 FUN_00023cd8(void)

{
  return 1;
}



/* 00023ce4 FUN_00023ce4 */

/* Boundary evidence: original MIPS .pdata 00023ce4..00023d7b. Semantic name remains unreviewed. */

undefined4 FUN_00023ce4(undefined4 param_1,HANDLE param_2)

{
  BOOL BVar1;
  
  FUN_00023328(0x26,3,L"%S invoked","CSharedMem::releaseShmMutex");
  if ((param_2 != (HANDLE)0x0) && (BVar1 = ReleaseMutex(param_2), BVar1 == 0)) {
    GetLastError();
    FUN_00023328(0x26,3,L"%S ReleaseMutex fail, error=%d","CSharedMem::releaseShmMutex");
  }
  return 1;
}



/* 00023d7c FUN_00023d7c */

/* Boundary evidence: original MIPS .pdata 00023d7c..00023e53. Semantic name remains unreviewed. */

undefined4 FUN_00023d7c(undefined4 *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,param_2);
  *param_1 = pvVar1;
  DVar2 = GetLastError();
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_00023328(0x26,3,L"%S CreateMutex(%s) error = %d","CSharedMem::createShmMutex");
    uVar3 = 0;
  }
  else if (DVar2 == 0xb7) {
    FUN_00023328(0x26,3,L"%S CreateMutex(%s) already exist","CSharedMem::createShmMutex");
  }
  else {
    FUN_00023ce4(param_1,(HANDLE)*param_1);
  }
  return uVar3;
}



/* 00023e54 FUN_00023e54 */

/* Boundary evidence: original MIPS .pdata 00023e54..00024063. Semantic name remains unreviewed. */

bool FUN_00023e54(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,HANDLE param_4)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  LPVOID pvVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_00023328(0x26,3,L"%S lpName=%s, m_hxMutex=NULL","CSharedMem::createShmMappingReadWrite");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,2000);
    if (DVar1 == 0) {
      hFileMappingObject =
           CreateFileMappingW(param_4,(LPSECURITY_ATTRIBUTES)0x0,4,0,param_3,param_2);
      param_1[1] = hFileMappingObject;
      if (hFileMappingObject != (HANDLE)0x0) {
        pvVar2 = MapViewOfFile(hFileMappingObject,0xf001f,0,0,0);
        param_1[2] = pvVar2;
        if (pvVar2 != (LPVOID)0x0) {
          FUN_00023328(0x26,3,L"%S lpName=%s success","CSharedMem::createShmMappingReadWrite");
        }
        else {
          GetLastError();
          FUN_00023328(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                       "CSharedMem::createShmMappingReadWrite");
          CloseHandle((HANDLE)param_1[1]);
          param_1[1] = 0;
        }
        FUN_00023ce4(param_1,(HANDLE)*param_1);
        return pvVar2 != (LPVOID)0x0;
      }
      DVar1 = GetLastError();
      FUN_00023328(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite");
      if (DVar1 == 0xb7) {
        FUN_00023328(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadWrite");
      }
      FUN_00023ce4(param_1,(HANDLE)*param_1);
    }
    else {
      GetLastError();
      FUN_00023328(0x26,3,L"%S lpName=%s, WaitForSingleObject fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite");
    }
  }
  return false;
}



/* 00024064 FUN_00024064 */

/* Boundary evidence: original MIPS .pdata 00024064..00024093. Semantic name remains unreviewed. */

bool FUN_00024064(undefined4 *param_1,LPCWSTR param_2,DWORD param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_00023e54(param_1,param_2,param_3,(HANDLE)0xffffffff);
  return CONCAT31(extraout_var,bVar1) != 0;
}



/* 00024094 FUN_00024094 */

/* Boundary evidence: original MIPS .pdata 00024094..000240af. Semantic name remains unreviewed. */

void FUN_00024094(int param_1,void *param_2,int param_3,size_t param_4)

{
  FUN_00023c44(param_1,param_2,param_3,param_4);
  return;
}



/* 000240b0 FUN_000240b0 */

/* Boundary evidence: original MIPS .pdata 000240b0..00024107. Semantic name remains unreviewed. */

undefined4 *
FUN_000240b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  *param_1 = &PTR_FUN_0002b6c4;
  FUN_00022c7c(param_1 + 0x14);
  FUN_000231b0((int)param_1,param_2,param_3,param_4);
  return param_1;
}



/* 00024108 Unwind@00024108 */

/* Boundary evidence: original MIPS .pdata 00024108..0002413b. Semantic name remains unreviewed. */

void Unwind_00024108(void)

{
  int *in_v0;
  
  FUN_00023128((undefined4 *)(*in_v0 + 0x50));
  return;
}



/* 0002413c FUN_0002413c */

/* Boundary evidence: original MIPS .pdata 0002413c..00024193. Semantic name remains unreviewed. */

undefined4 * FUN_0002413c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002b6c4;
  FUN_00023128(param_1 + 0x14);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00024194 FUN_00024194 */

/* Boundary evidence: original MIPS .pdata 00024194..000241ff. Semantic name remains unreviewed. */

void FUN_00024194(undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  undefined4 *puVar1;
  
  if (DAT_00035090 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x88);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_00035090 = (undefined4 *)0x0;
    }
    else {
      DAT_00035090 = FUN_000240b0(puVar1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 00024200 Unwind@00024200 */

/* Boundary evidence: original MIPS .pdata 00024200..0002422f. Semantic name remains unreviewed. */

void Unwind_00024200(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00024230 FUN_00024230 */

/* Boundary evidence: original MIPS .pdata 00024230..0002435f. Semantic name remains unreviewed. */

void FUN_00024230(undefined4 *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_00023328(0x26,3,L"%S already mutex=NULL","CSharedMem::closeShmMapping");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,2000);
    if (DVar1 == 0) {
      FUN_00023ce4(param_1,(HANDLE)*param_1);
    }
    else {
      GetLastError();
      FUN_00023328(0x26,3,L"%S WaitForSingleObject fail, error=%d","CSharedMem::closeShmMapping");
    }
    CloseHandle((HANDLE)*param_1);
  }
  if (((LPCVOID)param_1[2] != (LPCVOID)0x0) &&
     (BVar2 = UnmapViewOfFile((LPCVOID)param_1[2]), BVar2 == 0)) {
    GetLastError();
    FUN_00023328(0x26,3,L"%S UnmapViewOfFile fail, error=%d","CSharedMem::closeShmMapping");
  }
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
  }
  return;
}



/* 00024360 FUN_00024360 */

/* Boundary evidence: original MIPS .pdata 00024360..00024407. Semantic name remains unreviewed. */

undefined4 * FUN_00024360(LPCWSTR param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00023328(0x26,3,L"%S not created","MSHM_Dll_CreateShmClassObj");
  }
  else {
    iVar2 = FUN_00023d7c(puVar1,param_1);
    if (iVar2 == 0) {
      FUN_00024230(puVar1);
      __3_YAXPAX_Z(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}



/* 00024408 FUN_00024408 */

/* Boundary evidence: original MIPS .pdata 00024408..0002447f. Semantic name remains unreviewed. */

bool FUN_00024408(LPCWSTR param_1)

{
  DWORD DVar1;
  
  DAT_0003513c = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_1);
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    CloseHandle(DAT_0003513c);
    DAT_0003513c = (HANDLE)0x0;
  }
  return DVar1 != 0xb7;
}



/* 00024480 FUN_00024480 */

/* Boundary evidence: original MIPS .pdata 00024480..0002454b. Semantic name remains unreviewed. */

undefined4 FUN_00024480(wchar_t *param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  pwVar1 = wcstok(param_1,L" ");
  if (pwVar1 != (wchar_t *)0x0) {
    iVar2 = wcscmp(pwVar1,L"1");
    if (iVar2 == 0) {
      iVar2 = FUN_000231a4();
      pwVar1 = L"%S Boot resume cmd";
      *(undefined4 *)(iVar2 + 0xc) = 1;
    }
    else {
      iVar2 = FUN_000231a4();
      pwVar1 = L"%S No Boot resume cmd";
      *(undefined4 *)(iVar2 + 0xc) = 0;
    }
    FUN_00023aac(5,0,pwVar1,"ParseCmdLine");
  }
  pwVar1 = wcstok((wchar_t *)0x0,L" ");
  if ((pwVar1 == (wchar_t *)0x0) || (iVar2 = wcscmp(pwVar1,L"bd9r2a@_4G2g=J2tq7X@app"), iVar2 != 0))
  {
    uVar3 = 0;
  }
  return uVar3;
}



/* 0002454c FUN_0002454c */

/* Boundary evidence: original MIPS .pdata 0002454c..000245ef. Semantic name remains unreviewed. */

bool FUN_0002454c(HINSTANCE param_1)

{
  wchar_t *lpWindowName;
  wchar_t *lpClassName;
  HWND hWnd;
  
  lpWindowName = FUN_00023a58(5);
  lpClassName = FUN_00023a58(5);
  hWnd = CreateWindowExW(0x4000000,lpClassName,lpWindowName,0x2000000,0,0,800,0x1e0,(HWND)0x0,
                         (HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd != (HWND)0x0) {
    ShowWindow(hWnd,0);
    UpdateWindow(hWnd);
  }
  return hWnd != (HWND)0x0;
}



/* 000245f0 FUN_000245f0 */

/* Boundary evidence: original MIPS .pdata 000245f0..00024a07. Semantic name remains unreviewed. */

LRESULT FUN_000245f0(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  UINT UVar4;
  WPARAM WVar5;
  LPARAM LVar6;
  LRESULT LVar7;
  undefined4 auStack_20 [2];
  
  puVar3 = auStack_20;
  UVar4 = param_2;
  WVar5 = param_3;
  LVar6 = param_4;
  FUN_000209e0(puVar3);
  if (param_2 == 1) {
    FUN_00023bf4(5,1);
    FUN_00023c1c(5,2);
    uVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x38) = uVar2;
    uVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemInfo",L"ALBUMART_WIDTH",0x116);
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x7c) = uVar2;
    uVar2 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemInfo",L"ALBUMART_HEIGHT",0x116);
    iVar1 = FUN_000231a4();
    *(undefined4 *)(iVar1 + 0x80) = uVar2;
    FUN_00023aac(5,0,L"%S MgrUSB Create","WndProc");
    FUN_000231a4();
    FUN_000231a4();
    FUN_000231a4();
    FUN_00023aac(5,3,L"** MgrUsb ver:%S %S (%d, %d)[%d] **","Feb 16 2016");
    iVar1 = FUN_000231a4();
    *(HWND *)(iVar1 + 0x3c) = param_1;
    puVar3 = FUN_00024360(L"ShmMxMgrUsbAppMain");
    iVar1 = FUN_000231a4();
    *(undefined4 **)(iVar1 + 0x40) = puVar3;
    iVar1 = FUN_000231a4();
    FUN_00024064(*(undefined4 **)(iVar1 + 0x40),L"ShmFmMgrUsbAppMain",0xe56);
    puVar3 = FUN_00024360(L"ShmMxMgrUsbAppMainList");
    iVar1 = FUN_000231a4();
    *(undefined4 **)(iVar1 + 0x44) = puVar3;
    iVar1 = FUN_000231a4();
    FUN_00024064(*(undefined4 **)(iVar1 + 0x44),L"ShmFmMgrUsbAppMainList",0x977fc);
    iVar1 = FUN_000231a4();
    FUN_00022fd8(iVar1 + 0x50);
    iVar1 = FUN_0001144c();
    FUN_000113e0(iVar1,param_1);
    iVar1 = FUN_000231a4();
    if ((*(int *)(iVar1 + 0xc) != 0) && (iVar1 = FUN_000231a4(), *(int *)(iVar1 + 0x38) != 0)) {
      SetTimer(param_1,0x3f0,5000,(TIMERPROC)0x0);
    }
    FUN_00020954(&DAT_00035140,param_1,0x8002);
    FUN_000231a4();
    FUN_00012474();
    FUN_00023aac(5,3,L"%S  Memory Use : %s m_bBootResumeCmd : %d ","WndProc");
  }
  else if (param_2 == 2) {
    iVar1 = FUN_000231a4();
    FUN_0002307c(iVar1 + 0x50);
    FUN_000205f8(0x35140);
    PostQuitMessage(0);
    if (DAT_0003513c != 0) {
      CloseHandle((HANDLE)DAT_0003513c);
      DAT_0003513c = 0;
    }
  }
  else if (param_2 == 0x113) {
    if (param_3 == 0x3f0) {
      KillTimer(param_1,0x3f0);
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0xc) = 0;
      iVar1 = FUN_000231a4();
      *(undefined4 *)(iVar1 + 0x10) = 1;
    }
    else {
      iVar1 = FUN_0001eea4(puVar3,UVar4,WVar5,LVar6);
      FUN_00020340(iVar1,param_3);
    }
  }
  else if (param_2 == 0x8001) {
    iVar1 = FUN_0001144c();
    FUN_00011ab0(iVar1);
  }
  else if ((param_2 == 0x8002) || (param_2 == 0x8064)) {
    iVar1 = FUN_0002291c();
    FUN_000229b8(iVar1,param_1,param_2,param_3);
  }
  else {
    if (DAT_00035158 != param_2) {
      LVar7 = DefWindowProcW(param_1,param_2,param_3,param_4);
      goto LAB_000249d4;
    }
    if (param_3 == 0) {
      iVar1 = FUN_0001eea4(puVar3,UVar4,WVar5,LVar6);
      FUN_0001c66c(iVar1 + 8);
    }
  }
  LVar7 = 0;
LAB_000249d4:
  FUN_000209d0(auStack_20);
  return LVar7;
}



/* 00024a08 Unwind@00024a08 */

/* Boundary evidence: original MIPS .pdata 00024a08..00024a37. Semantic name remains unreviewed. */

void Unwind_00024a08(void)

{
  int in_v0;
  
  FUN_000209d0((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 00024a38 FUN_00024a38 */

/* Boundary evidence: original MIPS .pdata 00024a38..00024a8f. Semantic name remains unreviewed. */

void FUN_00024a38(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_000245f0;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.hInstance = param_1;
  local_30.lpszClassName = FUN_00023a58(5);
  RegisterClassW(&local_30);
  return;
}



/* 00024a90 FUN_00024a90 */

/* Boundary evidence: original MIPS .pdata 00024a90..00024b8f. Semantic name remains unreviewed. */

undefined4 FUN_00024a90(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  wchar_t *pwVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  BOOL BVar4;
  MSG MStack_30;
  
  pwVar2 = FUN_00023a58(5);
  bVar1 = FUN_00024408(pwVar2);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_000129c8();
    FUN_00023aac(5,0,L"%S process is already running. Execution is ignored!","WinMain");
  }
  else {
    iVar3 = FUN_00024480(param_3);
    if (iVar3 != 0) {
      FUN_00024a38(param_1);
      bVar1 = FUN_0002454c(param_1);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        FUN_0002291c();
        while (BVar4 = GetMessageW(&MStack_30,(HWND)0x0,0,0), BVar4 != 0) {
          TranslateMessage(&MStack_30);
          DispatchMessageW(&MStack_30);
        }
        FUN_000129c8();
        return MStack_30.wParam;
      }
    }
    FUN_000129c8();
  }
  return 0;
}



/* 00024b90 FUN_00024b90 */

/* Boundary evidence: original MIPS .pdata 00024b90..00024c43. Semantic name remains unreviewed. */

bool FUN_00024b90(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  HANDLE hFindFile;
  DWORD local_240;
  undefined1 auStack_23c [556];
  uint local_10;
  
  local_10 = DAT_0002f960;
  local_240 = 0;
  memset(auStack_23c,0,0x22c);
  sVar1 = wcslen(param_2);
  if (param_2[sVar1 - 1] == L'\n') {
    param_2[sVar1 - 1] = L'\0';
  }
  hFindFile = FindFirstFileW(param_2,(LPWIN32_FIND_DATAW)&local_240);
  if (hFindFile == (HANDLE)0xffffffff) {
    FUN_00025510(local_10);
  }
  else {
    FindClose(hFindFile);
    FUN_00025510(local_10);
  }
  return hFindFile != (HANDLE)0xffffffff;
}



/* 00024c44 FUN_00024c44 */

undefined4 FUN_00024c44(undefined4 param_1,short *param_2,int param_3)

{
  int iVar1;
  
  if (*param_2 != 0) {
    if (*param_2 != 0x20) {
      return 1;
    }
    iVar1 = 1;
    if (1 < param_3) {
      do {
        param_2 = param_2 + 1;
        if ((*param_2 != 0x20) && (*param_2 != 0)) {
          return 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_3);
    }
  }
  return 0;
}



/* 00024ca4 FUN_00024ca4 */

/* Boundary evidence: original MIPS .pdata 00024ca4..00024cf7. Semantic name remains unreviewed. */

bool FUN_00024ca4(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00012604((HKEY)0x80000002,L"LGE\\SystemInfo",L"LANG_INDEX",0);
  *(int *)(param_1 + 4) = iVar1;
  return 0 < iVar1;
}



/* 00024cf8 FUN_00024cf8 */

/* Boundary evidence: original MIPS .pdata 00024cf8..00024e03. Semantic name remains unreviewed. */

UINT FUN_00024cf8(int param_1,LPCSTR param_2,LPWSTR param_3,int param_4,int param_5,int param_6)

{
  UINT CodePage;
  
  FUN_00024ca4(param_1);
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
  case 0x1f:
    CodePage = 0x4e8;
    break;
  default:
    CodePage = 0x4e4;
    break;
  case 7:
  case 0x14:
  case 0x16:
  case 0x17:
    CodePage = 0x4e3;
    break;
  case 9:
  case 0xb:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
    CodePage = 0x4e2;
    break;
  case 10:
    CodePage = 0x4e6;
    break;
  case 0xd:
    CodePage = 0x3a4;
    break;
  case 0xe:
    CodePage = 0x4e5;
    break;
  case 0x15:
    CodePage = 0x4e7;
  }
  MultiByteToWideChar(CodePage,8,param_2,param_6,param_3,param_4);
  param_3[param_5] = L'\0';
  return CodePage;
}



/* 00024e04 FUN_00024e04 */

/* Boundary evidence: original MIPS .pdata 00024e04..0002510b. Semantic name remains unreviewed. */

wchar_t * FUN_00024e04(int param_1,char *param_2,wchar_t *param_3,size_t param_4)

{
  size_t sVar1;
  BOOL BVar2;
  int iVar3;
  wchar_t local_1b8;
  undefined1 auStack_1b6 [398];
  uint local_28;
  
  local_28 = DAT_0002f960;
  if ((*param_2 == -1) || (*param_2 == -0x11)) {
    local_1b8 = L'\0';
    memset(auStack_1b6,0,0x18e);
    if ((int)param_4 < 0xc9) {
      memcpy(&local_1b8,param_2 + 2,param_4);
      sVar1 = (int)(param_4 - 2) >> 1;
      if ((int)(param_4 - 2) < 0) {
        sVar1 = (int)(param_4 - 1) >> 1;
      }
    }
    else {
      memcpy(&local_1b8,param_2 + 2,200);
      sVar1 = 199;
    }
    wcsncpy_s(param_3,200,&local_1b8,sVar1);
  }
  else {
    FUN_00024ca4(param_1);
    if ((*(int *)(param_1 + 4) == 2) || (*(int *)(param_1 + 4) == 0x1c)) {
      iVar3 = 0;
      if (0 < (int)param_4) {
        do {
          BVar2 = IsDBCSLeadByteEx(0x3b5,param_2[iVar3]);
          if (BVar2 == 1) {
            sVar1 = strlen(param_2);
            sVar1 = MultiByteToWideChar(0x3b5,8,param_2,sVar1 + 1,(LPWSTR)0x0,0);
            if (sVar1 == 0) {
              sVar1 = MultiByteToWideChar(0xfde9,8,param_2,param_4,(LPWSTR)0x0,0);
              if ((int)sVar1 < 1) {
                FUN_00024cf8(param_1,param_2,param_3,param_4,param_4,param_4);
                goto LAB_000250dc;
              }
              if ((int)sVar1 < (int)param_4) {
                sVar1 = param_4;
              }
              MultiByteToWideChar(0xfde9,8,param_2,param_4,param_3,sVar1);
            }
            else {
              if ((int)sVar1 < (int)param_4) {
                sVar1 = param_4;
              }
              MultiByteToWideChar(0x3b5,8,param_2,param_4,param_3,sVar1);
            }
            goto LAB_000250d4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)param_4);
      }
      FUN_00024cf8(param_1,param_2,param_3,param_4,param_4,param_4);
      goto LAB_000250dc;
    }
    sVar1 = MultiByteToWideChar(0xfde9,8,param_2,param_4,(LPWSTR)0x0,0);
    if ((int)sVar1 < 1) {
      FUN_00024cf8(param_1,param_2,param_3,param_4,param_4,param_4);
      goto LAB_000250dc;
    }
    if ((int)sVar1 < (int)param_4) {
      sVar1 = param_4;
    }
    MultiByteToWideChar(0xfde9,8,param_2,param_4,param_3,sVar1);
  }
LAB_000250d4:
  param_3[sVar1] = L'\0';
LAB_000250dc:
  FUN_00025510(local_28);
  return param_3;
}



/* 0002541c FUN_0002541c */

/* Boundary evidence: original MIPS .pdata 0002541c..0002548f. Semantic name remains unreviewed. */

void FUN_0002541c(void)

{
  uint uVar1;
  
  if ((DAT_0002f960 == 0) || (DAT_0002f960 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0002f960 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0002f960 == 0) {
      DAT_0002f960 = 0xb064;
    }
  }
  DAT_0002f964 = ~DAT_0002f960;
  return;
}



/* 00025490 FUN_00025490 */

/* Boundary evidence: original MIPS .pdata 00025490..000254e3. Semantic name remains unreviewed. */

void FUN_00025490(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00025510(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000254e4 FUN_000254e4 */

/* Boundary evidence: original MIPS .pdata 000254e4..0002550f. Semantic name remains unreviewed. */

undefined4 FUN_000254e4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00025490(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00025510 FUN_00025510 */

/* Boundary evidence: original MIPS .pdata 00025510..00025557. Semantic name remains unreviewed. */

void FUN_00025510(uint param_1)

{
  if ((param_1 == DAT_0002f960) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 000255d8 FUN_000255d8 */

/* Boundary evidence: original MIPS .pdata 000255d8..00025647. Semantic name remains unreviewed. */

void FUN_000255d8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00025490(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 00025678 FUN_00025678 */

/* Boundary evidence: original MIPS .pdata 00025678..00025783. Semantic name remains unreviewed. */

undefined4 FUN_00025678(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00035164;
  puVar3 = DAT_00035160;
  iVar4 = (int)DAT_00035160 - (int)DAT_00035164;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_000256bc:
    param_1 = 0;
  }
  else {
    if (DAT_00035164 != (void *)0x0) {
      uVar1 = _msize(DAT_00035164);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00025730:
        if (pvVar2 == (void *)0x0) goto LAB_000256bc;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00025730;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00035160 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00035164 = pvVar2;
  }
  return param_1;
}



/* 00025784 FUN_00025784 */

/* Boundary evidence: original MIPS .pdata 00025784..0002586f. Semantic name remains unreviewed. */

undefined4 FUN_00025784(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00035168 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00035168,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00035168 == (LPCRITICAL_SECTION)0x0) goto LAB_00025828;
  }
  EnterCriticalSection(DAT_00035168);
LAB_00025828:
  uVar2 = FUN_00025678(param_1);
  FUN_00025870();
  return uVar2;
}



/* 00025870 FUN_00025870 */

/* Boundary evidence: original MIPS .pdata 00025870..000258bb. Semantic name remains unreviewed. */

void FUN_00025870(void)

{
  if (DAT_00035168 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00035168);
  }
  return;
}



/* 000258bc FUN_000258bc */

/* Boundary evidence: original MIPS .pdata 000258bc..000258eb. Semantic name remains unreviewed. */

undefined4 FUN_000258bc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00025784(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 000259dc FUN_000259dc */

/* Boundary evidence: original MIPS .pdata 000259dc..00025a6f. Semantic name remains unreviewed. */

void FUN_000259dc(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_00025d5c();
  UVar1 = FUN_00024a90(param_1,param_2,param_3);
  FUN_00025c9c(UVar1);
  FUN_00025cbc(UVar1);
  return;
}



/* 00025a70 FUN_00025a70 */

/* Boundary evidence: original MIPS .pdata 00025a70..00025aaf. Semantic name remains unreviewed. */

void FUN_00025a70(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00025ab0 entry */

/* Boundary evidence: original MIPS .pdata 00025ab0..00025b0b. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_0002541c();
  FUN_000259dc(param_1,param_2,param_3);
  return;
}



/* 00025b7c FUN_00025b7c */

/* Boundary evidence: original MIPS .pdata 00025b7c..00025c9b. Semantic name remains unreviewed. */

void FUN_00025b7c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0003515c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00035164;
    if (DAT_00035164 != (undefined4 *)0x0) {
      while (DAT_00035160 = DAT_00035160 + -1, _Memory <= DAT_00035160) {
        if ((code *)*DAT_00035160 != (code *)0x0) {
          (*(code *)*DAT_00035160)();
          _Memory = DAT_00035164;
        }
      }
      free(_Memory);
      DAT_00035160 = (undefined4 *)0x0;
      DAT_00035164 = (undefined4 *)0x0;
    }
    FUN_00025d08((undefined4 *)&DAT_0002601c,(undefined4 *)&DAT_00026020);
  }
  FUN_00025d08((undefined4 *)&DAT_00026024,(undefined4 *)&DAT_00026028);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00035168,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00025c9c FUN_00025c9c */

/* Boundary evidence: original MIPS .pdata 00025c9c..00025cbb. Semantic name remains unreviewed. */

void FUN_00025c9c(UINT param_1)

{
  FUN_00025b7c(param_1,0,0);
  return;
}



/* 00025cbc FUN_00025cbc */

/* Boundary evidence: original MIPS .pdata 00025cbc..00025d07. Semantic name remains unreviewed. */

void FUN_00025cbc(UINT param_1)

{
  DAT_0003515c = 0;
  FUN_00025d08((undefined4 *)&DAT_00026024,(undefined4 *)&DAT_00026028);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00025d08 FUN_00025d08 */

/* Boundary evidence: original MIPS .pdata 00025d08..00025d5b. Semantic name remains unreviewed. */

void FUN_00025d08(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00025d5c FUN_00025d5c */

/* Boundary evidence: original MIPS .pdata 00025d5c..00025d97. Semantic name remains unreviewed. */

void FUN_00025d5c(void)

{
  FUN_00025d08((undefined4 *)&DAT_00026014,(undefined4 *)&DAT_00026018);
  FUN_00025d08((undefined4 *)&DAT_00026000,(undefined4 *)&DAT_00026010);
  return;
}



/* 00025e08 FUN_00025e08 */

/* Boundary evidence: original MIPS .pdata 00025e08..00025e2b. Semantic name remains unreviewed. */

void FUN_00025e08(undefined4 param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4)

{
  DAT_00035138 = FUN_00024194(param_1,param_2,param_3,param_4);
  return;
}



/* 00025e2c FUN_00025e2c */

/* Boundary evidence: original MIPS .pdata 00025e2c..00025e53. Semantic name remains unreviewed. */

void FUN_00025e2c(void)

{
  DAT_00035158 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 00025e54 FUN_00025e54 */

/* Boundary evidence: original MIPS .pdata 00025e54..00025e7f. Semantic name remains unreviewed. */

void FUN_00025e54(void)

{
  FUN_000205d0((undefined4 *)&DAT_00035140);
  FUN_000258bc(FUN_00025ee0);
  return;
}



/* 00025e80 FUN_00025e80 */

/* Boundary evidence: original MIPS .pdata 00025e80..00025e9f. Semantic name remains unreviewed. */

void FUN_00025e80(void)

{
  FUN_00015b7c((undefined4 *)&DAT_0002fea8);
  return;
}



/* 00025ea0 FUN_00025ea0 */

/* Boundary evidence: original MIPS .pdata 00025ea0..00025ebf. Semantic name remains unreviewed. */

void FUN_00025ea0(void)

{
  FUN_000165c4((undefined4 *)&DAT_0002fec4);
  return;
}



/* 00025ec0 FUN_00025ec0 */

/* Boundary evidence: original MIPS .pdata 00025ec0..00025edf. Semantic name remains unreviewed. */

void FUN_00025ec0(void)

{
  FUN_000168ec((undefined4 *)&DAT_0002fee0);
  return;
}



/* 00025ee0 FUN_00025ee0 */

/* Boundary evidence: original MIPS .pdata 00025ee0..00025eff. Semantic name remains unreviewed. */

void FUN_00025ee0(void)

{
  FUN_000209d0((undefined4 *)&DAT_00035140);
  return;
}


