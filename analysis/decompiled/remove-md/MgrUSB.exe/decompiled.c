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

/* Boundary evidence: original MIPS .pdata 00011054..000110f7. Semantic name remains unreviewed. */

bool FUN_00011054(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  
  HVar1 = CoCreateInstance((IID *)&DAT_0002d7a8,(LPUNKNOWN)0x0,1,(IID *)&DAT_0002e818,
                           (LPVOID *)(param_1 + 0x10));
  if (HVar1 == 0) {
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x34) = 1;
  }
  else {
    FUN_000235a8(5,1,L"%S  CoCreateInstance FAILED(hr=0x%x)","CDshowManager::FilterCreate",1);
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x34) = 0;
    *(LPVOID *)(param_1 + 0x10) = (LPVOID)0x0;
  }
  return HVar1 == 0;
}



/* 000110f8 FUN_000110f8 */

/* Boundary evidence: original MIPS .pdata 000110f8..000111eb. Semantic name remains unreviewed. */

undefined4 FUN_000110f8(int param_1)

{
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
  Sleep(100);
  return 1;
}



/* 000111ec FUN_000111ec */

/* Boundary evidence: original MIPS .pdata 000111ec..000114d7. Semantic name remains unreviewed. */

int FUN_000111ec(int param_1,undefined4 param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_000110f8(param_1);
  }
  iVar1 = FUN_00011054(param_1);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      pwVar2 = L"%S RenderFile init FAIL";
    }
    else {
      FUN_000235a8(5,1,L"%S RenderFile init","CDshowManager::RenderFile");
      iVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),param_2,0);
      if (-1 < iVar1) {
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002d0b8,param_1 + 4);
        if (iVar1 < 0) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pGraphBuilder->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl)"
                      );
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002d0d8,(int *)(param_1 + 8));
        if (iVar1 < 0) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pGraphBuilder->QueryInterface(IID_IMediaEventEx, (void **)&m_pMediaEventEx)"
                      );
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002e748,param_1 + 0xc);
        if (iVar1 < 0) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pGraphBuilder->QueryInterface(IID_IMediaSeeking, (void **)&m_pMediaSeeking)"
                      );
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002d0f8,param_1 + 0x14);
        if (iVar1 < 0) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pGraphBuilder->QueryInterface(IID_IBasicAudio, (void **)&m_pBasicAudio)")
          ;
          return iVar1;
        }
        iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                          (*(undefined4 **)(param_1 + 0x10),&UNK_0002d0e8,param_1 + 0x18);
        if (iVar1 < 0) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pGraphBuilder->QueryInterface(IID_IMediaPosition, (void **)&m_pMediaPosition)"
                      );
          return iVar1;
        }
        piVar3 = *(int **)(param_1 + 8);
        if ((piVar3 != (int *)0x0) &&
           (iVar1 = (**(code **)(*piVar3 + 0x34))(piVar3,*(undefined4 *)(param_1 + 0x1c),0x8001,0),
           iVar1 < 0)) {
          FUN_000235a8(5,1,L"FAILED(hr=0x%x) in %s \n",iVar1,
                       L"m_pMediaEventEx->SetNotifyWindow((OAHWND)m_hEventWnd, WM_DSHOW_NOTYFY, 0)")
          ;
          return iVar1;
        }
        return 1;
      }
      pwVar2 = L"%S RenderFile failed";
    }
    FUN_000235a8(5,1,pwVar2,"CDshowManager::RenderFile");
  }
  return 0;
}



/* 000114d8 FUN_000114d8 */

/* Boundary evidence: original MIPS .pdata 000114d8..0001166f. Semantic name remains unreviewed. */

undefined4 FUN_000114d8(int param_1,wchar_t *param_2,int param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_50 [40];
  
  FUN_000235a8(5,0,L"%S  line %d","CDshowManager::LoadFile",0xd5);
  DAT_0002f970 = 0;
  FUN_00024cc4(auStack_50);
  uVar3 = 1;
  if ((param_3 == 1) || (param_3 == 2)) {
    iVar1 = FUN_00024d08(auStack_50,param_2);
    if ((iVar1 == 0) && (sVar2 = wcslen(param_2), 0x104 < sVar2)) {
      FUN_000235a8(5,0,L"%S  line %d","CDshowManager::LoadFile",0xf7);
      DAT_0002f970 = 0;
      uVar3 = 4;
    }
    else {
      FUN_000235a8(5,0,L"%S  line %d","CDshowManager::LoadFile",0xe2);
      *(int *)(param_1 + 0x20) = param_3;
      iVar1 = FUN_000111ec(param_1,param_2);
      if (iVar1 == 1) {
        FUN_000235a8(5,0,L"%S  line %d","CDshowManager::LoadFile",0xea);
        DAT_0002f970 = 1;
      }
      else {
        FUN_000235a8(5,0,L"%S  line %d","CDshowManager::LoadFile",0xf0);
        DAT_0002f970 = 0;
        uVar3 = 3;
      }
    }
  }
  else {
    uVar3 = 4;
  }
  FUN_000207e4(auStack_50);
  return uVar3;
}



/* 00011670 Unwind@00011670 */

/* Boundary evidence: original MIPS .pdata 00011670..0001169f. Semantic name remains unreviewed. */

void Unwind_00011670(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x50);
  return;
}



/* 000116a0 FUN_000116a0 */

/* Boundary evidence: original MIPS .pdata 000116a0..000117b3. Semantic name remains unreviewed. */

undefined4 FUN_000116a0(int param_1,uint param_2)

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
      if ((iVar1 < 1) && ((iVar1 != 0 || (uVar2 < 1000000)))) {
        uVar3 = uVar2 + local_18;
        local_18 = uVar3 - 1000000;
        local_14 = (iVar1 + local_14 + (uint)(uVar3 < uVar2)) - (uint)(uVar3 < 1000000);
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



/* 000117b4 FUN_000117b4 */

/* Boundary evidence: original MIPS .pdata 000117b4..00011837. Semantic name remains unreviewed. */

undefined4 FUN_000117b4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    local_10 = 0;
    local_c = 0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(*(int **)(param_1 + 0xc),&local_10);
    if (-1 < iVar1) {
      if ((-1 < local_c) && ((local_c != 0 || (local_10 != 0)))) {
        uVar2 = __ll_div(local_10,local_c,10000000,0);
        return uVar2;
      }
      return 0;
    }
  }
  return 0xffffffff;
}



/* 00011838 FUN_00011838 */

/* Boundary evidence: original MIPS .pdata 00011838..0001189b. Semantic name remains unreviewed. */

uint FUN_00011838(int param_1)

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



/* 0001189c FUN_0001189c */

void FUN_0001189c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}



/* 000118a4 FUN_000118a4 */

undefined4 FUN_000118a4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



/* 000118ac FUN_000118ac */

/* Boundary evidence: original MIPS .pdata 000118ac..00011907. Semantic name remains unreviewed. */

undefined4 * FUN_000118ac(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_000275c8;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[6] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  FUN_00011000(param_1);
  return param_1;
}



/* 00011908 FUN_00011908 */

/* Boundary evidence: original MIPS .pdata 00011908..0001195b. Semantic name remains unreviewed. */

void FUN_00011908(void)

{
  int iVar1;
  
  if (DAT_0002f96c == 0) {
    iVar1 = __2_YAPAXI_Z(0x28);
    if (iVar1 == 0) {
      DAT_0002f96c = 0;
    }
    else {
      DAT_0002f96c = FUN_000118ac(iVar1);
    }
  }
  return;
}



/* 0001195c FUN_0001195c */

/* Boundary evidence: original MIPS .pdata 0001195c..00011a23. Semantic name remains unreviewed. */

undefined4 FUN_0001195c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 4) == 0) {
LAB_00011980:
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x24) != 2) {
      piVar4 = *(int **)(param_1 + 0x14);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x1c))(piVar4,0);
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))();
      iVar3 = FUN_00023424();
      FUN_0001eba4(*(undefined4 *)(iVar3 + 0x5c));
      if (iVar2 < 0) {
        FUN_000235a8(5,1,L"%S Run failed","CDshowManager::Run");
        goto LAB_00011980;
      }
      *(undefined4 *)(param_1 + 0x24) = 2;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 00011a24 FUN_00011a24 */

/* Boundary evidence: original MIPS .pdata 00011a24..00011c17. Semantic name remains unreviewed. */

undefined4 FUN_00011a24(int param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  int local_30 [2];
  
  if ((*(int *)(param_1 + 4) == 0) || (DAT_0002f970 == 0)) {
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
LAB_00011b08:
          (*pcVar3)();
        }
        else {
          if (local_30[0] == 1) {
            pcVar3 = *(code **)(**(int **)(param_1 + 4) + 0x24);
            goto LAB_00011b08;
          }
          if (local_30[0] == 0) {
            bVar1 = true;
          }
        }
        Sleep(5);
        FUN_000235a8(5,0,L"%S  line %d  => CDshowManager::Stop(%d) [%d : %d]","CDshowManager::Stop",
                     0x127,param_2,uVar5,local_30[0]);
        uVar5 = uVar5 + 1;
        if (1000 < uVar5) {
          NKDbgPrintfW(L"\r\n======================================\r\n");
          NKDbgPrintfW(L"==================[%d]=================\r\n",uVar5);
          NKDbgPrintfW(L"======================================\r\n");
          break;
        }
      } while (!bVar1);
      if (param_2 != 0) {
        FUN_000116a0(param_1,0);
      }
      *(undefined4 *)(param_1 + 0x24) = 3;
    }
  }
  return uVar4;
}



/* 00011c18 FUN_00011c18 */

/* Boundary evidence: original MIPS .pdata 00011c18..00011cab. Semantic name remains unreviewed. */

undefined4 FUN_00011c18(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x24) == 2)) {
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))(piVar2,0xffffd8f0);
    }
    Sleep(100);
    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x20))();
    if (-1 < iVar1) {
      return 1;
    }
  }
  return 0;
}



/* 00011cac FUN_00011cac */

/* Boundary evidence: original MIPS .pdata 00011cac..00011d3f. Semantic name remains unreviewed. */

undefined4 FUN_00011cac(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x24) == 2)) {
    piVar2 = *(int **)(param_1 + 0x14);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x1c))(piVar2,0xffffd8f0);
    }
    Sleep(100);
    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x24))();
    if (-1 < iVar1) {
      *(undefined4 *)(param_1 + 0x24) = 1;
      return 1;
    }
  }
  return 0;
}



/* 00011d40 FUN_00011d40 */

/* Boundary evidence: original MIPS .pdata 00011d40..00012043. Semantic name remains unreviewed. */

undefined4 FUN_00011d40(int param_1)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  int *piVar5;
  undefined4 uVar6;
  int local_40;
  undefined4 local_3c;
  int local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  
  piVar5 = *(int **)(param_1 + 8);
  uVar6 = 0;
  if (piVar5 == (int *)0x0) {
LAB_00012010:
    uVar6 = 0;
  }
  else {
    iVar1 = (**(code **)(*piVar5 + 0x20))(piVar5,&local_38,&local_3c,&local_40,0);
    if (-1 < iVar1) {
      local_34 = L"%S DShow Event : EC_USERABORT";
      local_30 = L"%S DShow Event : EC_COMPLETE %d, %d";
      do {
        if (local_38 == 1) {
          uVar6 = local_3c;
          iVar1 = local_40;
          FUN_000235a8(5,3,local_30,"CDshowManager::EventHandler",local_3c,local_40);
          iVar2 = FUN_00023424();
          if (*(int *)(iVar2 + 0x48) != 0) {
            iVar2 = FUN_00023424();
            if ((*(int *)(iVar2 + 0x34) == 0) || (local_40 != 0)) {
              pwVar4 = L"%S DShow Event : EC_COMPLETE ERROR_DEVICE_REMOVED catch!!!!!!!";
            }
            else {
              iVar2 = FUN_00023424();
              DVar3 = GetTickCount();
              if (299 < DVar3 - *(int *)(iVar2 + 0x38)) {
                DVar3 = GetTickCount();
                iVar1 = FUN_00023424();
                *(DWORD *)(iVar1 + 0x38) = DVar3;
                iVar1 = FUN_00023424();
                if (*(int *)(iVar1 + 0xc) == 0) {
                  uVar6 = FUN_000117b4(param_1);
                  iVar1 = FUN_00023424();
                  FUN_0001da7c(*(undefined4 *)(iVar1 + 0x5c),uVar6);
                  Sleep(100);
                  FUN_0002381c(5,5,0x6c,0,0);
                }
                else {
                  uVar6 = FUN_00011908();
                  FUN_000116a0(uVar6,0);
                }
                goto LAB_00011f94;
              }
              pwVar4 = L"%S DShow Event : EC_COMPLETE ERROR_DEVICE_REMOVED 300ms catch!!!!!!!";
            }
            FUN_000235a8(5,3,pwVar4,"CDshowManager::EventHandler",uVar6,iVar1);
          }
          goto LAB_00012010;
        }
        pwVar4 = local_34;
        if (local_38 != 2) {
          if (local_38 == 3) {
            pwVar4 = L"%S DShow Event : EC_ERRORABORT";
          }
          else if (local_38 == 6) {
            pwVar4 = L"%S DShow Event : EC_STREAM_ERROR_STOPPED";
          }
          else if (local_38 == 7) {
            pwVar4 = L"%S DShow Event : EC_STREAM_ERROR_STILLPLAYING";
          }
          else if (local_38 == 10) {
            pwVar4 = L"%S DShow Event : EC_VIDEO_SIZE_CHANGED";
          }
          else {
            pwVar4 = L"%S DShow Event : EC_VIDEOFRAMEREADY";
            if (local_38 != 0x49) goto LAB_00011f94;
          }
        }
        FUN_000235a8(5,3,pwVar4,"CDshowManager::EventHandler");
LAB_00011f94:
        uVar6 = (**(code **)(**(int **)(param_1 + 8) + 0x30))
                          (*(int **)(param_1 + 8),local_38,local_3c,local_40);
        iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                          (*(int **)(param_1 + 8),&local_38,&local_3c,&local_40,0);
      } while (-1 < iVar1);
    }
  }
  return uVar6;
}



/* 00012044 FUN_00012044 */

/* Boundary evidence: original MIPS .pdata 00012044..0001209f. Semantic name remains unreviewed. */

undefined4 * FUN_00012044(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000275c8;
  CoUninitialize();
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000120a0 FUN_000120a0 */

/* Boundary evidence: original MIPS .pdata 000120a0..0001216b. Semantic name remains unreviewed. */

undefined * FUN_000120a0(void)

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
  swprintf((wchar_t *)&DAT_000305a4,0x27b0c,(wchar_t *)uVar2,(int)((ulonglong)uVar2 >> 0x20),
           (int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  return &DAT_000305a4;
}



/* 0001216c FUN_0001216c */

/* Boundary evidence: original MIPS .pdata 0001216c..0001223f. Semantic name remains unreviewed. */

undefined4 FUN_0001216c(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  HKEY local_28;
  undefined4 local_24;
  DWORD local_20 [4];
  
  local_20[1] = 4;
  LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20019,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_28,local_20 + 2);
  if (LVar1 == 0) {
    local_20[0] = 4;
    LVar1 = RegQueryValueExW(local_28,param_3,(LPDWORD)0x0,local_20 + 1,(LPBYTE)&local_24,local_20);
    if (LVar1 != 0) {
      local_24 = param_4;
    }
    RegCloseKey(local_28);
  }
  else {
    local_24 = 0;
  }
  return local_24;
}



/* 00012240 FUN_00012240 */

void FUN_00012240(short *param_1,int param_2,short *param_3)

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



/* 0001228c FUN_0001228c */

/* Boundary evidence: original MIPS .pdata 0001228c..000122db. Semantic name remains unreviewed. */

undefined4 * FUN_0001228c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027b6c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  memset(param_1 + 4,0,0x284880);
  return param_1;
}



/* 000122dc FUN_000122dc */

/* Boundary evidence: original MIPS .pdata 000122dc..0001230f. Semantic name remains unreviewed. */

void FUN_000122dc(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  memset((void *)(param_1 + 0x10),0,0x284880);
  return;
}



/* 00012310 FUN_00012310 */

int FUN_00012310(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = param_2 * 0x210 + param_1 + 0x10;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00012340 FUN_00012340 */

/* Boundary evidence: original MIPS .pdata 00012340..0001237b. Semantic name remains unreviewed. */

void FUN_00012340(int param_1,int param_2,wchar_t *param_3)

{
  if (param_2 < 5000) {
    wcscpy_s((wchar_t *)(param_2 * 0x210 + param_1 + 0x10),0x104,param_3);
  }
  return;
}



/* 0001237c FUN_0001237c */

void FUN_0001237c(int param_1,int param_2,undefined2 param_3)

{
  if (param_2 < 5000) {
    param_1 = param_2 * 0x210 + param_1;
    *(char *)(param_1 + 0x218) = (char)param_3;
    *(char *)(param_1 + 0x219) = (char)((ushort)param_3 >> 8);
  }
  return;
}



/* 000123b4 FUN_000123b4 */

void FUN_000123b4(int param_1,int param_2,undefined2 param_3)

{
  if (param_2 < 5000) {
    param_1 = param_2 * 0x210 + param_1;
    *(char *)(param_1 + 0x21e) = (char)param_3;
    *(char *)(param_1 + 0x21f) = (char)((ushort)param_3 >> 8);
  }
  return;
}



/* 000123ec FUN_000123ec */

void FUN_000123ec(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 < 5000) {
    *(undefined4 *)(param_2 * 0x210 + param_1 + 0x21a) = param_3;
  }
  return;
}



/* 00012418 FUN_00012418 */

undefined4 FUN_00012418(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 5000) {
    uVar1 = *(undefined4 *)(param_2 * 0x210 + param_1 + 0x21a);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 00012450 FUN_00012450 */

int FUN_00012450(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(param_2 * 0x210 + param_1 + 0x21e);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* 00012494 FUN_00012494 */

int FUN_00012494(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(param_2 * 0x210 + param_1 + 0x218);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 000124d8 FUN_000124d8 */

undefined4 FUN_000124d8(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 000124e0 FUN_000124e0 */

void FUN_000124e0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



/* 000124e8 FUN_000124e8 */

int FUN_000124e8(int param_1,int param_2)

{
  return param_2 * 0x210 + param_1 + 0x10;
}



/* 00012500 FUN_00012500 */

/* Boundary evidence: original MIPS .pdata 00012500..0001253f. Semantic name remains unreviewed. */

void FUN_00012500(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027b6c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  memset(param_1 + 4,0,0x284880);
  return;
}



/* 00012540 FUN_00012540 */

/* Boundary evidence: original MIPS .pdata 00012540..000125af. Semantic name remains unreviewed. */

undefined4 * FUN_00012540(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027b6c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  memset(param_1 + 4,0,0x284880);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000125b0 FUN_000125b0 */

/* Boundary evidence: original MIPS .pdata 000125b0..0001264b. Semantic name remains unreviewed. */

void FUN_000125b0(int param_1)

{
  *(undefined4 *)(&DAT_0028489c + param_1) = 0;
  *(undefined4 *)(&DAT_00284898 + param_1) = 0;
  *(undefined4 *)(&DAT_002848a0 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x2848a4) = 0;
  FUN_000122dc(param_1 + 8);
  memset((void *)(param_1 + 0x284abc),0,0x298100);
  memset(&DAT_0051cbbc + param_1,0,0x2712);
  return;
}



/* 0001264c FUN_0001264c */

/* Boundary evidence: original MIPS .pdata 0001264c..000126df. Semantic name remains unreviewed. */

void FUN_0001264c(int param_1)

{
  FUN_000125b0(param_1);
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_000122dc(param_1 + 8);
  *(undefined4 *)(&DAT_00284ab8 + param_1) = 0;
  *(undefined4 *)(&DAT_00284ab4 + param_1) = 0;
  *(undefined4 *)(&DAT_00284ab0 + param_1) = 0;
  *(undefined4 *)(&DAT_00284898 + param_1) = 0;
  *(undefined4 *)(&DAT_0028489c + param_1) = 0;
  *(undefined2 *)(&DAT_002848a8 + param_1) = 0;
  return;
}



/* 000126e0 FUN_000126e0 */

undefined4 FUN_000126e0(int param_1)

{
  return *(undefined4 *)(&DAT_00284898 + param_1);
}



/* 000126f4 FUN_000126f4 */

/* Boundary evidence: original MIPS .pdata 000126f4..0001270f. Semantic name remains unreviewed. */

void FUN_000126f4(int param_1)

{
  FUN_000124d8(param_1 + 8);
  return;
}



/* 00012710 FUN_00012710 */

int FUN_00012710(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(&DAT_00284cd0 + param_2 * 0x220 + param_1);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00012750 FUN_00012750 */

int FUN_00012750(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(&DAT_00284cce + param_2 * 0x220 + param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* 00012790 FUN_00012790 */

int FUN_00012790(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 5000) {
    iVar1 = (int)*(short *)(&DAT_00284cd0 + param_2 * 0x220 + param_1);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



/* 000127d0 FUN_000127d0 */

/* Boundary evidence: original MIPS .pdata 000127d0..0001296f. Semantic name remains unreviewed. */

undefined4
FUN_000127d0(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 < 5000) {
    iVar3 = param_1 + 8;
    FUN_00012340(iVar3,param_2);
    FUN_0001237c(iVar3,param_2,param_4);
    FUN_000123b4(iVar3,param_2,param_5);
    FUN_000123ec(iVar3,param_2,param_6);
    iVar1 = FUN_000124d8(iVar3);
    FUN_000124e0(iVar3,iVar1 + 1);
    if (*(int *)(&DAT_00284cd8 + param_4 * 0x220 + param_1) != 2) {
      *(int *)(&DAT_00284cd8 + param_4 * 0x220 + param_1) = 2;
    }
    iVar1 = FUN_00023424();
    uVar2 = 1;
    if (*(int *)(iVar1 + 0xc) == 0) {
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0xc) = 1;
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 8) = 1;
      iVar1 = FUN_00023424();
      iVar1 = FUN_0001d9cc(*(undefined4 *)(iVar1 + 0x5c),param_2,1,1,0);
      if (iVar1 == 1) {
        iVar1 = FUN_00023424();
        FUN_0001d950(*(undefined4 *)(iVar1 + 0x5c));
      }
      else {
        iVar1 = FUN_00023424();
        FUN_0001da44(*(undefined4 *)(iVar1 + 0x5c),1);
        iVar1 = FUN_00023424();
        FUN_0001d988(*(undefined4 *)(iVar1 + 0x5c),2);
      }
      FUN_0002381c(5,5,0x68,0,0);
    }
  }
  else {
    FUN_000235a8(5,0,L"%S Not addMusicName[%d] : %s","CFileMgr::AddMusicFile",param_2,param_3);
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012970 FUN_00012970 */

/* Boundary evidence: original MIPS .pdata 00012970..00012a23. Semantic name remains unreviewed. */

undefined4
FUN_00012970(int param_1,int param_2,wchar_t *param_3,undefined2 param_4,undefined2 param_5)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 < 1000) {
    piVar2 = (int *)(&DAT_0051f2d0 + param_1);
    if (*piVar2 != 0) {
      iVar1 = param_2 * 0x11b8;
      wcscpy_s((wchar_t *)(iVar1 + *piVar2),0x104,param_3);
      *(undefined2 *)(*piVar2 + iVar1 + 0x20c) = param_4;
      *(short *)(*piVar2 + iVar1 + 0x208) = (short)param_2;
      *(undefined4 *)(*piVar2 + iVar1 + 0x210) = 0;
      *(undefined2 *)(*piVar2 + iVar1 + 0x20a) = param_5;
      return 1;
    }
  }
  return 0;
}



/* 00012a24 FUN_00012a24 */

/* Boundary evidence: original MIPS .pdata 00012a24..00012b17. Semantic name remains unreviewed. */

undefined4
FUN_00012a24(int param_1,int param_2,undefined4 param_3,undefined4 param_4,wchar_t *param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 5000) {
    iVar2 = param_2 * 0x220 + param_1;
    wcscpy_s((wchar_t *)(iVar2 + 0x284abc),0x104,param_5);
    *(short *)(&DAT_00284cc8 + iVar2) = (short)param_4;
    *(undefined4 *)(&DAT_00284cc4 + iVar2) = param_6;
    if (param_2 == 0) {
      *(undefined2 *)(&DAT_00284cc8 + param_1) = 0xffff;
    }
    *(int *)(&DAT_00284898 + param_1) = *(int *)(&DAT_00284898 + param_1) + 1;
    uVar1 = 1;
  }
  else {
    FUN_000235a8(5,0,L"%S Not addDir[%d] : %s, PID : %d, ","CFileMgr::AddDir",param_2,param_5,
                 param_4);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00012b18 FUN_00012b18 */

int FUN_00012b18(int param_1,int param_2)

{
  return (int)*(short *)(&DAT_00284cc8 + param_2 * 0x220 + param_1);
}



/* 00012b40 FUN_00012b40 */

/* Boundary evidence: original MIPS .pdata 00012b40..00012b83. Semantic name remains unreviewed. */

int FUN_00012b40(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00012494(param_1 + 8);
  return iVar1 * 0x220 + param_1 + 0x284abc;
}



/* 00012b84 FUN_00012b84 */

/* Boundary evidence: original MIPS .pdata 00012b84..00012b9f. Semantic name remains unreviewed. */

void FUN_00012b84(int param_1)

{
  FUN_00012494(param_1 + 8);
  return;
}



/* 00012ba0 FUN_00012ba0 */

/* Boundary evidence: original MIPS .pdata 00012ba0..00012bbb. Semantic name remains unreviewed. */

void FUN_00012ba0(int param_1)

{
  FUN_00012310(param_1 + 8);
  return;
}



/* 00012bbc FUN_00012bbc */

/* Boundary evidence: original MIPS .pdata 00012bbc..00012bd7. Semantic name remains unreviewed. */

void FUN_00012bbc(int param_1)

{
  FUN_00012450(param_1 + 8);
  return;
}



/* 00012bd8 FUN_00012bd8 */

/* Boundary evidence: original MIPS .pdata 00012bd8..00012def. Semantic name remains unreviewed. */

void FUN_00012bd8(int param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  wchar_t *_Str;
  wchar_t local_848;
  undefined1 auStack_846 [2078];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  local_848 = L'\0';
  memset(auStack_846,0,0x81e);
  iVar5 = param_1 + 8;
  iVar1 = FUN_00012418(iVar5,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_00012494(iVar5,param_2);
    uVar2 = FUN_00012310(iVar5,param_2);
    swprintf_s(param_3,0x104,L"%s",uVar2);
    sVar3 = wcslen(param_3);
    if ((int)sVar3 < 0x100) {
      for (; 0 < iVar1; iVar1 = (int)*(short *)(&DAT_00284cc8 + iVar1)) {
        Sleep(1);
        memset(&local_848,0,0x410);
        iVar1 = iVar1 * 0x220 + param_1;
        _Str = (wchar_t *)(iVar1 + 0x284abc);
        sVar4 = wcslen(_Str);
        if (0x104 < (int)(sVar4 + sVar3)) goto LAB_00012dbc;
        swprintf_s(&local_848,0x410,L"%s\\%s",_Str,param_3);
        wcsncpy_s(param_3,0x410,&local_848,0x410);
      }
      swprintf_s(&local_848,0x410,L"\\%s\\%s",&DAT_00027b78,param_3);
      wcsncpy_s(param_3,0x410,&local_848,0x410);
    }
LAB_00012dbc:
    param_3[0x103] = L'\0';
  }
  else {
    uVar2 = FUN_00012310();
    swprintf_s(param_3,0x104,L"%s",uVar2);
    if (*param_3 == L'\\') {
      swprintf_s(param_3,0x104,L"%s",param_3 + 1);
    }
  }
  FUN_00025660(local_28);
  return;
}



/* 00012df0 FUN_00012df0 */

int FUN_00012df0(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = param_2 * 0x220 + param_1;
  if (*(short *)(&DAT_00284cd0 + iVar1) < 1) {
    iVar1 = (int)*(short *)(&DAT_00284cca + iVar1);
    if (iVar1 < *(int *)(&DAT_00284898 + param_1)) {
      psVar2 = (short *)(&DAT_00284cd0 + iVar1 * 0x220 + param_1);
      do {
        if (0 < *psVar2) {
          return (int)*(short *)(&DAT_00284cce + iVar1 * 0x220 + param_1);
        }
        iVar1 = iVar1 + 1;
        psVar2 = psVar2 + 0x110;
      } while (iVar1 < *(int *)(&DAT_00284898 + param_1));
    }
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(short *)(&DAT_00284cce + iVar1);
  }
  return iVar1;
}



/* 00012ebc FUN_00012ebc */

/* Boundary evidence: original MIPS .pdata 00012ebc..00012efb. Semantic name remains unreviewed. */

void FUN_00012ebc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00016804();
  FUN_00016a98(uVar1,param_1,param_2);
  return;
}



/* 00012efc FUN_00012efc */

/* Boundary evidence: original MIPS .pdata 00012efc..00013047. Semantic name remains unreviewed. */

undefined4 FUN_00012efc(int param_1,undefined4 param_2)

{
  HANDLE hFindFile;
  undefined4 uVar1;
  WCHAR *pWVar2;
  undefined1 auStack_478 [40];
  _WIN32_FIND_DATAW local_450;
  undefined4 local_18;
  
  local_18 = DAT_0002f964;
  FUN_00024cc4(auStack_478);
  local_450.dwFileAttributes = 0;
  memset(&local_450.ftCreationTime,0,0x22c);
  local_450.cFileName[0x102] = L'\0';
  memset(local_450.cFileName + 0x103,0,0x206);
  swprintf_s(local_450.cFileName + 0x102,0x104,L"%s\\*.*",param_2);
  pWVar2 = local_450.cFileName + 0x102;
  FUN_000235a8(5,3,L"%S  FullPath: %s","CFileMgr::CheckMD",pWVar2);
  uVar1 = 1;
  if (*(int *)(&DAT_00284ab4 + param_1) == 1) {
    FUN_000235a8(5,1,L"%S m_bStop stop","CFileMgr::CheckMD",pWVar2);
    uVar1 = 0;
  }
  else {
    hFindFile = FindFirstFileW(local_450.cFileName + 0x102,&local_450);
    FindClose(hFindFile);
    if (hFindFile == (HANDLE)0xffffffff) {
      uVar1 = 0;
    }
  }
  FUN_000207e4(auStack_478);
  FUN_00025660(local_18);
  return uVar1;
}



/* 00013048 Unwind@00013048 */

/* Boundary evidence: original MIPS .pdata 00013048..00013077. Semantic name remains unreviewed. */

void Unwind_00013048(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x478);
  return;
}



/* 00013078 FUN_00013078 */

/* Boundary evidence: original MIPS .pdata 00013078..000134a3. Semantic name remains unreviewed. */

undefined4
FUN_00013078(int param_1,LPWIN32_FIND_DATAW param_2,HANDLE param_3,undefined4 param_4,int param_5,
            int *param_6,int *param_7,int *param_8)

{
  int iVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  BOOL BVar5;
  uint uVar6;
  DWORD *pDVar7;
  undefined4 uVar8;
  int iVar9;
  wchar_t local_40;
  undefined1 auStack_3e [14];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  local_40 = L'\0';
  memset(auStack_3e,0,0xe);
  do {
    if (*(int *)(&DAT_00284ab4 + param_1) != 0) {
      FindClose(param_3);
      FUN_00025660(local_30);
      return 0;
    }
    iVar9 = param_1 + 8;
    iVar1 = FUN_000124d8(iVar9);
    if (4999 < iVar1) break;
    uVar6 = param_2->dwFileAttributes;
    if ((((uVar6 & 0x10) == 0) || ((uVar6 & 2) != 0)) || ((uVar6 & 4) != 0)) {
      if (uVar6 == 0x26) goto LAB_0001341c;
      if ((uVar6 & 2) == 0) {
        pDVar7 = &param_2->dwReserved1;
        wcscpy_s((wchar_t *)(&DAT_002848a8 + param_1),0x104,(wchar_t *)pDVar7);
        sVar2 = wcslen((wchar_t *)pDVar7);
        _wcsupr_s((wchar_t *)(&DAT_002848a8 + param_1),0x104);
        wcscpy_s(&local_40,7,(wchar_t *)((sVar2 + 0x142450) * 2 + param_1));
        pwVar3 = wcsstr(&local_40,L".MP3");
        if (pwVar3 == (wchar_t *)0x0) {
          pwVar3 = wcsstr(&local_40,L".WMA");
          if (pwVar3 == (wchar_t *)0x0) {
            pwVar3 = wcsstr(&local_40,L".M3U");
            if (pwVar3 == (wchar_t *)0x0) {
              pwVar3 = wcsstr(&local_40,L".PLS");
              if (pwVar3 == (wchar_t *)0x0) {
                pwVar3 = wcsstr(&local_40,L".WPL");
                if (pwVar3 == (wchar_t *)0x0) goto LAB_0001341c;
                uVar8 = 9;
              }
              else {
                uVar8 = 8;
              }
            }
            else {
              uVar8 = 7;
            }
            iVar1 = FUN_00012a24(param_1,*(undefined4 *)(&DAT_00284898 + param_1),param_5 + 1,
                                 param_4,pDVar7,1);
            if (iVar1 != 0) {
              *param_6 = *param_6 + 1;
              iVar1 = FUN_00012970(param_1,*param_8,pDVar7,param_4,uVar8);
              if (iVar1 != 0) {
                *param_8 = *param_8 + 1;
              }
            }
            goto LAB_0001341c;
          }
          uVar8 = 2;
        }
        else {
          uVar8 = 1;
        }
        iVar1 = FUN_000124d8(iVar9);
        if (iVar1 < 5000) {
          uVar4 = FUN_000124d8(iVar9);
          iVar1 = FUN_000127d0(param_1,uVar4,pDVar7,param_4,uVar8,0);
          if (iVar1 != 0) {
            *param_7 = *param_7 + 1;
          }
        }
        goto LAB_0001341c;
      }
    }
    else {
      pDVar7 = &param_2->dwReserved1;
      iVar1 = wcscmp((wchar_t *)pDVar7,L".");
      if ((((iVar1 != 0) && (iVar1 = wcscmp((wchar_t *)pDVar7,L".."), iVar1 != 0)) &&
          ((iVar1 = wcscmp((wchar_t *)pDVar7,L"Recycled"), iVar1 != 0 &&
           ((iVar1 = wcscmp((wchar_t *)pDVar7,L"System Volume Information"), iVar1 != 0 &&
            (iVar1 = wcscmp((wchar_t *)pDVar7,L".Trashes"), iVar1 != 0)))))) &&
         (iVar1 = FUN_00012a24(param_1,*(undefined4 *)(&DAT_00284898 + param_1),param_5 + 1,param_4,
                               pDVar7,0), iVar1 != 0)) {
        *param_6 = *param_6 + 1;
      }
LAB_0001341c:
      Sleep(0);
    }
    BVar5 = FindNextFileW(param_3,param_2);
  } while (BVar5 != 0);
  FUN_00025660(local_30);
  return 1;
}



/* 000134a4 FUN_000134a4 */

/* Boundary evidence: original MIPS .pdata 000134a4..00013633. Semantic name remains unreviewed. */

void FUN_000134a4(int param_1,size_t param_2,int param_3,size_t param_4,undefined4 param_5,
                 int param_6)

{
  short sVar1;
  void *_Base;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  uVar5 = (undefined2)param_3;
  if ((int)param_2 < 2) {
    if (param_2 == 1) {
      *(undefined2 *)(&DAT_00284cd6 + param_3 * 0x220 + param_1) = uVar5;
    }
  }
  else if (param_1 != -0x25cd20) {
    iVar4 = param_3 * 0x220 + param_1;
    qsort((void *)(iVar4 + 0x284abc),param_2,0x220,FUN_00012ebc);
    iVar3 = param_2 + param_3;
    if (param_3 < iVar3) {
      puVar2 = (undefined2 *)(&DAT_00284cd6 + iVar4);
      do {
        *puVar2 = (short)param_3;
        param_3 = param_3 + 1;
        puVar2 = puVar2 + 0x110;
      } while (param_3 < iVar3);
    }
  }
  if ((1 < (int)param_4) && (param_1 != -0x25cd20)) {
    _Base = (void *)FUN_000124e8(param_1 + 8,param_5);
    qsort(_Base,param_4,0x210,FUN_00012ebc);
  }
  if (param_1 != -0x25cd20) {
    *(undefined2 *)(param_6 + 0x20e) = uVar5;
    *(short *)(param_6 + 0x210) = (short)param_2;
    if (param_1 != -0x25cd20) {
      if (param_4 == 0) {
        *(undefined2 *)(param_6 + 0x212) = 0xffff;
      }
      else {
        sVar1 = FUN_000124d8(param_1 + 8);
        *(short *)(param_6 + 0x212) = sVar1 - (short)param_4;
      }
      if (param_1 != -0x25cd20) {
        *(short *)(param_6 + 0x214) = (short)param_4;
      }
    }
  }
  return;
}



/* 00013634 FUN_00013634 */

/* Boundary evidence: original MIPS .pdata 00013634..00013727. Semantic name remains unreviewed. */

void FUN_00013634(undefined4 param_1,int param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  wchar_t awStack_228 [260];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  if (param_3 != (wchar_t *)0x0) {
    iVar1 = FUN_00023424();
    iVar1 = *(int *)(iVar1 + 0x58) + 0x284abc;
    if (iVar1 != 0) {
      memset(param_3,0,0x208);
      while (-1 < param_2) {
        memset(awStack_228,0,0x208);
        iVar2 = param_2 * 0x220 + iVar1;
        swprintf_s(awStack_228,0x104,L"%s\\%s",iVar2,param_3);
        wcsncpy_s(param_3,0x104,awStack_228,0x104);
        param_2 = (int)*(short *)(iVar2 + 0x20c);
      }
    }
  }
  FUN_00025660(local_20);
  return;
}



/* 00013728 FUN_00013728 */

/* Boundary evidence: original MIPS .pdata 00013728..00013a17. Semantic name remains unreviewed. */

int FUN_00013728(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar4 = 0;
  }
  else {
    iVar3 = param_2 * 0x220 + param_1;
    iVar4 = 0;
    if (iVar3 != -0x284abc) {
      iVar2 = (int)*(short *)(&DAT_00284cca + iVar3);
      if (iVar2 < *(short *)(&DAT_00284ccc + iVar3) + iVar2) {
        do {
          Sleep(1);
          iVar1 = iVar2;
          if (iVar2 < 0) {
            iVar1 = 0;
          }
          iVar1 = iVar1 * 0x220 + param_1;
          if ((((void *)(iVar1 + 0x284abc) != (void *)0x0) &&
              (*(short *)(&DAT_00284cd6 + iVar1) != 0)) && (*(int *)(&DAT_00284cd8 + iVar1) == 2)) {
            if (param_3 != 0) {
              memcpy((void *)(DAT_000307b4 * 0x220 + param_3),(void *)(iVar1 + 0x284abc),0x208);
              iVar4 = iVar4 + 1;
              *(undefined4 *)(DAT_000307b4 * 0x220 + param_3 + 0x208) =
                   *(undefined4 *)(&DAT_00284cc4 + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x20c) =
                   *(undefined2 *)(&DAT_00284cc8 + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x20e) =
                   *(undefined2 *)(&DAT_00284cca + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x210) =
                   *(undefined2 *)(&DAT_00284ccc + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x212) =
                   *(undefined2 *)(&DAT_00284cce + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x214) =
                   *(undefined2 *)(&DAT_00284cd0 + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x216) =
                   *(undefined2 *)(&DAT_00284cd2 + iVar1);
              *(undefined2 *)(DAT_000307b4 * 0x220 + param_3 + 0x218) =
                   *(undefined2 *)(&DAT_00284cd4 + iVar1);
              *(undefined4 *)(DAT_000307b4 * 0x220 + param_3 + 0x21c) =
                   *(undefined4 *)(&DAT_00284cd8 + iVar1);
              *(short *)(DAT_000307b4 * 0x220 + param_3 + 0x21a) = (short)iVar2;
              DAT_000307b4 = DAT_000307b4 + 1;
            }
            iVar1 = FUN_00013728(param_1,iVar2,param_3);
            iVar4 = iVar1 + iVar4;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)*(short *)(&DAT_00284ccc + iVar3) +
                         (int)*(short *)(&DAT_00284cca + iVar3));
      }
      iVar1 = (int)*(short *)(&DAT_00284cca + iVar3);
      iVar2 = *(short *)(&DAT_00284ccc + iVar3) + iVar1;
      for (; iVar1 < iVar2; iVar1 = iVar1 + 1) {
        Sleep(1);
        iVar2 = iVar1;
        if (iVar1 < 0) {
          iVar2 = 0;
        }
        iVar2 = iVar2 * 0x220 + param_1;
        if ((iVar2 != -0x284abc) && (*(int *)(&DAT_00284cd8 + iVar2) == 1)) {
          iVar2 = FUN_00013728(param_1,iVar1,param_3);
          iVar4 = iVar2 + iVar4;
        }
        iVar2 = (int)*(short *)(&DAT_00284ccc + iVar3) + (int)*(short *)(&DAT_00284cca + iVar3);
      }
    }
  }
  return iVar4;
}



/* 00013a18 FUN_00013a18 */

/* Boundary evidence: original MIPS .pdata 00013a18..00013d9b. Semantic name remains unreviewed. */

undefined4 FUN_00013a18(int param_1,int param_2,undefined2 param_3,int param_4)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  size_t _NumOfElements;
  undefined4 uVar8;
  short sVar9;
  
  if (((param_2 < 0) || (4999 < param_2)) || (iVar6 = param_2 * 0x220 + param_1, iVar6 == -0x284abc)
     ) {
LAB_00013d68:
    uVar8 = 0;
  }
  else {
    iVar4 = (int)*(short *)(&DAT_00284cca + iVar6);
    sVar9 = 0;
    uVar8 = 1;
    if (iVar4 < *(short *)(&DAT_00284ccc + iVar6) + iVar4) {
      do {
        iVar3 = FUN_00023424();
        if (*(int *)(iVar3 + 0x20) != 0) goto LAB_00013d68;
        Sleep(1);
        iVar3 = iVar4;
        if (iVar4 < 0) {
          iVar3 = 0;
        }
        iVar3 = iVar3 * 0x220 + param_1;
        if (((void *)(iVar3 + 0x284abc) != (void *)0x0) && (0 < *(int *)(&DAT_00284cd8 + iVar3))) {
          if (param_4 < 3) {
            if (iVar6 == -0x284abc) goto LAB_00013d68;
            sVar2 = *(short *)(&DAT_00284cd6 + iVar3);
            *(short *)(&DAT_00284cd4 + iVar3) = sVar9;
            *(undefined2 *)(&DAT_00284cd2 + iVar3) = param_3;
            sVar9 = sVar9 + 1;
            if ((-1 < sVar2) && (sVar2 < 5000)) {
              *(short *)(&DAT_0051cbbc + *(short *)(&DAT_0051f2cc + param_1) * 2 + param_1) = sVar2;
              *(short *)(&DAT_0051f2cc + param_1) = *(short *)(&DAT_0051f2cc + param_1) + 1;
            }
            FUN_00013a18(param_1,iVar4,iVar4,param_4 + 1);
          }
          else {
            DAT_000307b4 = 0;
            bVar1 = 0 < *(short *)(&DAT_00284cd0 + iVar3);
            if (bVar1) {
              memcpy(DAT_000307ac,(void *)(iVar3 + 0x284abc),0x208);
              *(undefined4 *)((int)DAT_000307ac + 0x208) = *(undefined4 *)(&DAT_00284cc4 + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x20c) = *(undefined2 *)(&DAT_00284cc8 + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x20e) = *(undefined2 *)(&DAT_00284cca + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x210) = *(undefined2 *)(&DAT_00284ccc + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x212) = *(undefined2 *)(&DAT_00284cce + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x214) = *(undefined2 *)(&DAT_00284cd0 + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x216) = *(undefined2 *)(&DAT_00284cd2 + iVar3);
              *(undefined2 *)((int)DAT_000307ac + 0x218) = *(undefined2 *)(&DAT_00284cd4 + iVar3);
              *(undefined4 *)((int)DAT_000307ac + 0x21c) = *(undefined4 *)(&DAT_00284cd8 + iVar3);
              *(short *)((int)DAT_000307ac + 0x21a) = (short)iVar4;
            }
            DAT_000307b4 = (uint)bVar1;
            iVar3 = FUN_00013728(param_1,iVar4,DAT_000307ac);
            _NumOfElements = iVar3 + (uint)bVar1;
            if (0 < (int)_NumOfElements) {
              if (1 < (int)_NumOfElements) {
                qsort(DAT_000307ac,_NumOfElements,0x220,FUN_00012ebc);
              }
              if (0 < (int)_NumOfElements) {
                iVar3 = 0;
                pvVar7 = DAT_000307ac;
                do {
                  iVar5 = (int)*(short *)((int)pvVar7 + iVar3 + 0x21a);
                  if (iVar5 < 0) {
                    iVar5 = 0;
                  }
                  iVar5 = iVar5 * 0x220 + param_1;
                  if (iVar5 != -0x284abc) {
                    sVar2 = *(short *)(&DAT_00284cd6 + iVar5);
                    *(short *)(&DAT_00284cd4 + iVar5) = sVar9;
                    sVar9 = sVar9 + 1;
                    *(undefined2 *)(&DAT_00284cd2 + iVar5) = param_3;
                    pvVar7 = DAT_000307ac;
                    if ((-1 < sVar2) && (sVar2 < 5000)) {
                      *(short *)(&DAT_0051cbbc + *(short *)(&DAT_0051f2cc + param_1) * 2 + param_1)
                           = sVar2;
                      *(short *)(&DAT_0051f2cc + param_1) = *(short *)(&DAT_0051f2cc + param_1) + 1;
                      pvVar7 = DAT_000307ac;
                    }
                  }
                  _NumOfElements = _NumOfElements - 1;
                  iVar3 = iVar3 + 0x220;
                } while (_NumOfElements != 0);
              }
            }
          }
        }
        uVar8 = 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)*(short *)(&DAT_00284ccc + iVar6) +
                       (int)*(short *)(&DAT_00284cca + iVar6));
    }
  }
  return uVar8;
}



/* 00013d9c FUN_00013d9c */

int FUN_00013d9c(int param_1)

{
  int iVar1;
  
  if (*(short *)(&DAT_0051f2cc + param_1) < 1) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(short *)((*(short *)(&DAT_0051f2cc + param_1) + 0x28e5dd) * 2 + param_1);
  }
  return iVar1;
}



/* 00013de4 FUN_00013de4 */

/* Boundary evidence: original MIPS .pdata 00013de4..00013f73. Semantic name remains unreviewed. */

int FUN_00013de4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  
  psVar5 = (short *)(&DAT_0051f2cc + param_1);
  iVar3 = 0;
  iVar1 = 0;
  if (0 < *psVar5) {
    psVar4 = (short *)(&DAT_0051cbbc + param_1);
    do {
      iVar1 = FUN_00023424();
      if (*(int *)(iVar1 + 0x20) != 0) {
        return 0;
      }
      Sleep(1);
      iVar1 = iVar3;
      if (param_2 == *psVar4) break;
      iVar3 = iVar3 + 1;
      psVar4 = psVar4 + 1;
      iVar1 = 0;
    } while (iVar3 < *psVar5);
  }
  while( true ) {
    iVar3 = FUN_00023424();
    if (*(int *)(iVar3 + 0x20) != 0) {
      return 0;
    }
    Sleep(1);
    iVar1 = iVar1 + 1;
    if (*psVar5 <= iVar1) {
      iVar1 = 0;
    }
    iVar2 = (int)*(short *)((iVar1 + 0x28e5de) * 2 + param_1);
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = 0;
    }
    iVar3 = iVar3 * 0x220 + param_1;
    if ((iVar3 != -0x284abc) && (0 < *(short *)(&DAT_00284cd0 + iVar3))) break;
    if (param_2 == iVar2) {
      return param_2;
    }
  }
  return (int)*(short *)((iVar1 + 0x28e5de) * 2 + param_1);
}



/* 00013f74 FUN_00013f74 */

/* Boundary evidence: original MIPS .pdata 00013f74..000140fb. Semantic name remains unreviewed. */

int FUN_00013f74(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
  psVar4 = (short *)(&DAT_0051f2cc + param_1);
  iVar2 = 0;
  iVar1 = 0;
  if (0 < *psVar4) {
    psVar3 = (short *)(&DAT_0051cbbc + param_1);
    do {
      iVar1 = FUN_00023424();
      if (*(int *)(iVar1 + 0x20) != 0) {
        return 0;
      }
      Sleep(1);
      iVar1 = iVar2;
      if (param_2 == *psVar3) break;
      iVar2 = iVar2 + 1;
      psVar3 = psVar3 + 1;
      iVar1 = 0;
    } while (iVar2 < *psVar4);
  }
  while( true ) {
    iVar2 = FUN_00023424();
    if (*(int *)(iVar2 + 0x20) != 0) {
      return 0;
    }
    Sleep(1);
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      iVar1 = *psVar4 + -1;
    }
    iVar2 = (int)*(short *)((iVar1 + 0x28e5de) * 2 + param_1);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = iVar2 * 0x220 + param_1;
    if ((iVar2 != -0x284abc) && (0 < *(short *)(&DAT_00284cd0 + iVar2))) break;
    if (param_2 == iVar1) {
      return param_2;
    }
  }
  return (int)*(short *)((iVar1 + 0x28e5de) * 2 + param_1);
}



/* 000140fc FUN_000140fc */

/* Boundary evidence: original MIPS .pdata 000140fc..000141e3. Semantic name remains unreviewed. */

int FUN_000140fc(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar3 = 0;
  }
  else {
    iVar2 = param_2 * 0x220 + param_1;
    iVar3 = 0;
    if (iVar2 != -0x284abc) {
      psVar4 = (short *)(&DAT_00284cd2 + iVar2);
      sVar1 = *psVar4;
      while (0 < sVar1) {
        Sleep(1);
        iVar2 = (int)*psVar4;
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        iVar2 = iVar2 * 0x220 + param_1;
        if (iVar2 == -0x284abc) {
          return iVar3;
        }
        psVar4 = (short *)(&DAT_00284cd2 + iVar2);
        iVar3 = iVar3 + 1;
        sVar1 = *psVar4;
      }
    }
  }
  return iVar3;
}



/* 000141e4 FUN_000141e4 */

int FUN_000141e4(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < *(short *)(&DAT_0051f2cc + param_1)) {
    psVar2 = (short *)(&DAT_0051cbbc + param_1);
    do {
      if (param_2 == *psVar2) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 1;
    } while (iVar1 < *(short *)(&DAT_0051f2cc + param_1));
  }
  return 0;
}



/* 00014240 FUN_00014240 */

/* Boundary evidence: original MIPS .pdata 00014240..00014283. Semantic name remains unreviewed. */

void FUN_00014240(int param_1)

{
  int iVar1;
  
  if (*(int *)(&DAT_0051f2d0 + param_1) == 0) {
    iVar1 = __2_YAPAXI_Z(&DAT_004536c0);
    *(int *)(&DAT_0051f2d0 + param_1) = iVar1;
  }
  return;
}



/* 00014284 FUN_00014284 */

/* Boundary evidence: original MIPS .pdata 00014284..000142c3. Semantic name remains unreviewed. */

void FUN_00014284(int param_1)

{
  if (*(int *)(&DAT_0051f2d0 + param_1) != 0) {
    __3_YAXPAX_Z();
    *(int *)(&DAT_0051f2d0 + param_1) = 0;
  }
  return;
}



/* 000142c4 FUN_000142c4 */

/* Boundary evidence: original MIPS .pdata 000142c4..0001433f. Semantic name remains unreviewed. */

undefined4 * FUN_000142c4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027da0;
  FUN_0001228c(param_1 + 2);
  FUN_00024cc4(param_1 + 0x147cb5);
  FUN_0001264c(param_1);
  param_1[0x147cb4] = 0;
  return param_1;
}



/* 00014340 Unwind@00014340 */

/* Boundary evidence: original MIPS .pdata 00014340..00014373. Semantic name remains unreviewed. */

void Unwind_00014340(void)

{
  int *in_v0;
  
  FUN_00012500(*in_v0 + 8);
  return;
}



/* 00014374 Unwind@00014374 */

/* Boundary evidence: original MIPS .pdata 00014374..000143af. Semantic name remains unreviewed. */

void Unwind_00014374(void)

{
  int *in_v0;
  
  FUN_000207e4(*in_v0 + 0x51f2d4);
  return;
}



/* 000143b0 FUN_000143b0 */

/* Boundary evidence: original MIPS .pdata 000143b0..00014447. Semantic name remains unreviewed. */

void FUN_000143b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027da0;
  FUN_0001264c(param_1);
  if (param_1[0x147cb4] != 0) {
    __3_YAXPAX_Z();
    param_1[0x147cb4] = 0;
  }
  FUN_000207e4(param_1 + 0x147cb5);
  FUN_00012500(param_1 + 2);
  return;
}



/* 00014448 Unwind@00014448 */

/* Boundary evidence: original MIPS .pdata 00014448..0001447b. Semantic name remains unreviewed. */

void Unwind_00014448(void)

{
  int *in_v0;
  
  FUN_00012500(*in_v0 + 8);
  return;
}



/* 0001447c Unwind@0001447c */

/* Boundary evidence: original MIPS .pdata 0001447c..000144b7. Semantic name remains unreviewed. */

void Unwind_0001447c(void)

{
  int *in_v0;
  
  FUN_000207e4(*in_v0 + 0x51f2d4);
  return;
}



/* 000144b8 FUN_000144b8 */

/* Boundary evidence: original MIPS .pdata 000144b8..0001452b. Semantic name remains unreviewed. */

void FUN_000144b8(void)

{
  int iVar1;
  
  if (DAT_000307b0 == 0) {
    iVar1 = __2_YAPAXI_Z(&DAT_0051f2f8);
    if (iVar1 == 0) {
      DAT_000307b0 = 0;
    }
    else {
      DAT_000307b0 = FUN_000142c4(iVar1);
    }
  }
  return;
}



/* 0001452c Unwind@0001452c */

/* Boundary evidence: original MIPS .pdata 0001452c..0001455b. Semantic name remains unreviewed. */

void Unwind_0001452c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001455c FUN_0001455c */

/* Boundary evidence: original MIPS .pdata 0001455c..000146a3. Semantic name remains unreviewed. */

int FUN_0001455c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((DAT_000b164c & 1) == 0) {
    DAT_000b164c = DAT_000b164c | 1;
    FUN_00015284(&DAT_000307b8);
    FUN_00025a6c(FUN_00026028);
  }
  iVar2 = FUN_00015cf0(&DAT_000307b8,param_2,param_3);
  iVar1 = DAT_000307c4;
  if ((iVar2 != 0) && (iVar2 = 0, 0 < DAT_000307c4)) {
    do {
      iVar3 = FUN_000157e8(&DAT_000307b8,iVar2);
      if (iVar3 == 0) {
        return iVar5;
      }
      uVar4 = FUN_000124d8(param_1 + 8);
      iVar3 = FUN_000127d0(param_1,uVar4,iVar3,param_4 + param_5,*(undefined4 *)(iVar3 + 0x20c),1);
      if (iVar3 != 0) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar5;
}



/* 000146a4 Unwind@000146a4 */

/* Boundary evidence: original MIPS .pdata 000146a4..000146c7. Semantic name remains unreviewed. */

void Unwind_000146a4(void)

{
  DAT_000b164c = DAT_000b164c & 0xfffffffe;
  return;
}



/* 000146c8 FUN_000146c8 */

/* Boundary evidence: original MIPS .pdata 000146c8..0001480f. Semantic name remains unreviewed. */

int FUN_000146c8(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((DAT_001324e4 & 1) == 0) {
    DAT_001324e4 = DAT_001324e4 | 1;
    FUN_00015c94(&DAT_000b1650);
    FUN_00025a6c(FUN_00026048);
  }
  iVar2 = FUN_00015cf0(&DAT_000b1650,param_2,param_3);
  iVar1 = DAT_000b165c;
  if ((iVar2 != 0) && (iVar2 = 0, 0 < DAT_000b165c)) {
    do {
      iVar3 = FUN_000157e8(&DAT_000b1650,iVar2);
      if (iVar3 == 0) {
        return iVar5;
      }
      uVar4 = FUN_000124d8(param_1 + 8);
      iVar3 = FUN_000127d0(param_1,uVar4,iVar3,param_4 + param_5,*(undefined4 *)(iVar3 + 0x20c),1);
      if (iVar3 != 0) {
        iVar5 = iVar5 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  return iVar5;
}



/* 00014810 Unwind@00014810 */

/* Boundary evidence: original MIPS .pdata 00014810..00014833. Semantic name remains unreviewed. */

void Unwind_00014810(void)

{
  DAT_001324e4 = DAT_001324e4 & 0xfffffffe;
  return;
}



/* 00014834 FUN_00014834 */

/* Boundary evidence: original MIPS .pdata 00014834..0001498f. Semantic name remains unreviewed. */

int FUN_00014834(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar1 = DAT_0002f964;
  if ((DAT_001b337c & 1) == 0) {
    DAT_001b337c = DAT_001b337c | 1;
    FUN_0001601c(&DAT_001324e8);
    FUN_00025a6c(FUN_00026068);
  }
  iVar6 = 0;
  iVar3 = FUN_00015cf0(&DAT_001324e8,param_2,param_3);
  iVar2 = DAT_001324f4;
  if ((iVar3 != 0) && (iVar3 = 0, 0 < DAT_001324f4)) {
    do {
      iVar4 = FUN_000157e8(&DAT_001324e8,iVar3);
      if (iVar4 != 0) {
        uVar5 = FUN_000124d8(param_1 + 8);
        iVar4 = FUN_000127d0(param_1,uVar5,iVar4,param_4 + param_5,*(undefined4 *)(iVar4 + 0x20c),1)
        ;
        if (iVar4 != 0) {
          iVar6 = iVar6 + 1;
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  FUN_00025660(uVar1);
  return iVar6;
}



/* 00014990 Unwind@00014990 */

/* Boundary evidence: original MIPS .pdata 00014990..000149b3. Semantic name remains unreviewed. */

void Unwind_00014990(void)

{
  DAT_001b337c = DAT_001b337c & 0xfffffffe;
  return;
}



/* 000149b4 FUN_000149b4 */

/* Boundary evidence: original MIPS .pdata 000149b4..00014d67. Semantic name remains unreviewed. */

undefined4
FUN_000149b4(int param_1,wchar_t *param_2,wchar_t *param_3,int param_4,int param_5,int param_6,
            int param_7,int *param_8,int param_9)

{
  wchar_t wVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  void *_Base;
  undefined2 *puVar5;
  wchar_t *_Str1;
  size_t _NumOfElements;
  int iVar6;
  int iVar7;
  wchar_t local_238;
  undefined1 auStack_236 [518];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  iVar7 = 0;
  if (0 < param_4) {
    puVar5 = (undefined2 *)(param_9 + 0x210);
    do {
      if (0x13 < param_6) break;
      swprintf(param_2,0x27c40,param_3,puVar5 + -0x108);
      param_2[0x207] = L'\0';
      iVar3 = FUN_000124d8(param_1 + 8);
      *param_8 = iVar3;
      if (*(int *)(puVar5 + -4) == 0) {
        iVar3 = FUN_00014d68(param_1,param_2,iVar7 + param_5,param_6 + 1);
        if (iVar3 == 0) {
          FUN_00025660(local_30);
          return 0;
        }
        if (param_1 != -0x25cd20) {
          iVar3 = FUN_000124d8(param_1 + 8);
          if (*param_8 == iVar3) {
            *(undefined4 *)(puVar5 + 6) = 0;
          }
          else {
            if (*(int *)(puVar5 + 6) != 2) {
              *(undefined4 *)(puVar5 + 6) = 1;
            }
            *(int *)(&DAT_0028489c + param_1) = *(int *)(&DAT_0028489c + param_1) + 1;
          }
        }
LAB_00014ce8:
        Sleep(0);
      }
      else {
        iVar3 = 0;
        if (0 < param_7) {
          iVar6 = 0;
          do {
            if ((iVar3 < 1000) && (*(int *)(&DAT_0051f2d0 + param_1) != 0)) {
              _Str1 = (wchar_t *)(iVar6 + *(int *)(&DAT_0051f2d0 + param_1));
              if (_Str1 != (wchar_t *)0x0) {
                iVar4 = wcscmp(_Str1,puVar5 + -0x108);
                if (iVar4 != 0) goto LAB_00014ad4;
                break;
              }
            }
            else {
LAB_00014ad4:
              _Str1 = (wchar_t *)0x0;
            }
            iVar3 = iVar3 + 1;
            iVar6 = iVar6 + 0x11b8;
          } while (iVar3 < param_7);
          if (_Str1 != (wchar_t *)0x0) {
            local_238 = L'\0';
            _NumOfElements = 0;
            memset(auStack_236,0,0x206);
            swprintf_s(&local_238,0x104,L"%s\\%s",param_3,_Str1);
            wVar1 = _Str1[0x105];
            if (wVar1 == L'\a') {
              _NumOfElements = FUN_0001455c(param_1,&local_238,param_3,param_5,iVar7);
            }
            else if (wVar1 == L'\b') {
              _NumOfElements = FUN_000146c8(param_1,&local_238,param_3,param_5,iVar7);
            }
            else if (wVar1 == L'\t') {
              _NumOfElements = FUN_00014834(param_1,&local_238,param_3,param_5,iVar7);
            }
            if (param_1 != -0x25cd20) {
              if ((int)_NumOfElements < 1) {
                puVar5[1] = 0xffff;
                puVar5[2] = 0;
                *(undefined4 *)(puVar5 + 6) = 0;
              }
              else {
                sVar2 = FUN_000124d8(param_1 + 8);
                puVar5[2] = (short)_NumOfElements;
                puVar5[1] = sVar2 - (short)_NumOfElements;
                if (*(int *)(puVar5 + 6) != 2) {
                  *(undefined4 *)(puVar5 + 6) = 1;
                }
                *(int *)(&DAT_0028489c + param_1) = *(int *)(&DAT_0028489c + param_1) + 1;
              }
              _Base = (void *)FUN_000124e8(param_1 + 8,*param_8);
              if (1 < (int)_NumOfElements) {
                qsort(_Base,_NumOfElements,0x210,FUN_00012ebc);
              }
              puVar5[-1] = 0;
              *puVar5 = 0;
            }
            goto LAB_00014ce8;
          }
        }
      }
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 0x110;
    } while (iVar7 < param_4);
  }
  FUN_00025660(local_30);
  return 1;
}



/* 00014d68 FUN_00014d68 */

/* Boundary evidence: original MIPS .pdata 00014d68..00014f9b. Semantic name remains unreviewed. */

undefined4 FUN_00014d68(int param_1,wchar_t *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  HANDLE hFindFile;
  int iVar3;
  int iVar4;
  undefined4 local_680;
  undefined4 local_67c;
  undefined4 local_678 [2];
  _WIN32_FIND_DATAW local_670 [2];
  undefined2 local_32;
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  local_670[0].dwFileAttributes = 0;
  memset(&local_670[0].ftCreationTime,0,0x22c);
  local_670[0].cFileName[0x102] = L'\0';
  memset(local_670[0].cFileName + 0x103,0,0x40e);
  uVar2 = FUN_000124d8(param_1 + 8);
  iVar4 = *(int *)(&DAT_00284898 + param_1);
  local_67c = 0;
  local_678[0] = 0;
  local_680 = 0;
  swprintf(local_670[0].cFileName + 0x102,0x27ca4,param_2);
  local_32 = 0;
  hFindFile = FindFirstFileW(local_670[0].cFileName + 0x102,local_670);
  if (hFindFile == (HANDLE)0xffffffff) {
    iVar4 = FUN_00024d08(param_1 + 0x51f2d4,&DAT_00027b78);
    if (iVar4 != 0) {
      FUN_00025660(local_30);
      return 1;
    }
  }
  else {
    iVar3 = FUN_00013078(param_1,local_670,hFindFile,param_3,param_4,&local_67c,&local_680,
                         &DAT_002848a0 + param_1);
    if (iVar3 != 0) {
      FindClose(hFindFile);
      uVar1 = local_67c;
      FUN_000134a4(param_1,local_67c,iVar4,local_680,uVar2,param_3 * 0x220 + param_1 + 0x284abc);
      uVar2 = FUN_000149b4(param_1,local_670[0].cFileName + 0x102,param_2,uVar1,iVar4,param_4,
                           *(undefined4 *)(&DAT_002848a0 + param_1),local_678,
                           iVar4 * 0x220 + param_1 + 0x284abc);
      FUN_00025660(local_30);
      return uVar2;
    }
    FindClose(hFindFile);
  }
  FUN_00025660(local_30);
  return 0;
}



/* 00014f9c FUN_00014f9c */

/* Boundary evidence: original MIPS .pdata 00014f9c..0001518f. Semantic name remains unreviewed. */

int FUN_00014f9c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  void *_Src;
  int iVar3;
  int iVar4;
  short *psVar5;
  int *local_30;
  
  if (param_3 != (int *)0x0) {
    param_3[3] = 0;
    *param_3 = 0;
  }
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar4 = 0;
  }
  else {
    iVar1 = FUN_000141e4(param_1,param_2);
    iVar4 = 0;
    if ((iVar1 != 0) || (iVar3 = 0, 0 < *(short *)(&DAT_00284cd0 + param_1))) {
      iVar3 = iVar1 + 1;
    }
    if (iVar3 < *(short *)(&DAT_0051f2cc + param_1)) {
      local_30 = param_3 + 0x24a76;
      psVar5 = (short *)((iVar3 + 0x28e5de) * 2 + param_1);
      do {
        Sleep(0);
        iVar2 = (int)*psVar5;
        iVar1 = iVar2;
        if (iVar2 < 0) {
          iVar1 = 0;
        }
        iVar1 = iVar1 * 0x220 + param_1;
        _Src = (void *)(iVar1 + 0x284abc);
        if ((_Src != (void *)0x0) && (*(short *)(&DAT_00284cd2 + iVar1) == param_2)) {
          if (param_3 != (int *)0x0) {
            memcpy(param_3 + *param_3 * 0x1e + 0x86,_Src,0x78);
            iVar1 = *param_3;
            *(undefined1 *)((int)param_3 + iVar1 * 0x78 + 0x28e) = 0;
            *(undefined1 *)((int)param_3 + iVar1 * 0x78 + 0x28f) = 0;
            *local_30 = iVar2;
            *param_3 = *param_3 + 1;
          }
          local_30 = local_30 + 1;
          iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 1;
        psVar5 = psVar5 + 1;
      } while (iVar3 < *(short *)(&DAT_0051f2cc + param_1));
    }
  }
  return iVar4;
}



/* 00015190 FUN_00015190 */

/* Boundary evidence: original MIPS .pdata 00015190..00015237. Semantic name remains unreviewed. */

undefined4 FUN_00015190(int param_1)

{
  if (*(int *)(&DAT_00284cd8 + param_1) == 2) {
    *(undefined2 *)(&DAT_0051cbbc + *(short *)(&DAT_0051f2cc + param_1) * 2 + param_1) = 0;
    *(short *)(&DAT_0051f2cc + param_1) = *(short *)(&DAT_0051f2cc + param_1) + 1;
  }
  DAT_000307ac = __2_YAPAXI_Z(&DAT_00298100);
  DAT_000307b4 = 0;
  FUN_00013a18(param_1,0,0,0);
  __3_YAXPAX_Z(DAT_000307ac);
  return 1;
}



/* 00015238 FUN_00015238 */

/* Boundary evidence: original MIPS .pdata 00015238..00015283. Semantic name remains unreviewed. */

undefined4 FUN_00015238(undefined4 param_1,uint param_2)

{
  FUN_000143b0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015284 FUN_00015284 */

/* Boundary evidence: original MIPS .pdata 00015284..000152bb. Semantic name remains unreviewed. */

undefined4 * FUN_00015284(undefined4 *param_1)

{
  FUN_00015b24(param_1);
  *param_1 = &PTR_FUN_00027f88;
  return param_1;
}



/* 000152bc FUN_000152bc */

/* Boundary evidence: original MIPS .pdata 000152bc..000152df. Semantic name remains unreviewed. */

void FUN_000152bc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027f88;
  FUN_00015b84();
  return;
}



/* 000152e0 FUN_000152e0 */

/* Boundary evidence: original MIPS .pdata 000152e0..000154d3. Semantic name remains unreviewed. */

void FUN_000152e0(int param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_540 [518];
  undefined2 local_33a;
  int local_334;
  char local_330;
  undefined1 auStack_32f [261];
  short sStack_22a;
  WCHAR local_228;
  undefined1 auStack_226 [518];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  if (*(int *)(param_1 + 8) != 0) {
    local_228 = L'\0';
    memset(auStack_226,0,0x206);
    local_330 = '\0';
    memset(auStack_32f,0,0x103);
    iVar1 = FUN_0001552c(param_1,&local_330,0x104);
    while (iVar1 != 0) {
      memset(&local_228,0,0x208);
      sVar2 = strlen(&local_330);
      iVar1 = MultiByteToWideChar(0xfde9,8,&local_330,sVar2,(LPWSTR)0x0,0);
      if (iVar1 != 0) {
        sVar2 = strlen(&local_330);
        MultiByteToWideChar(0xfde9,8,&local_330,sVar2,&local_228,iVar1);
        if (((&sStack_22a)[iVar1] == 10) && (iVar1 < 0x104)) {
          (&sStack_22a)[iVar1] = 0;
        }
        sVar2 = wcslen(&local_228);
        if ((sVar2 != 0) && (local_228 != L'#')) {
          uVar3 = FUN_000158cc(param_1,&local_228,param_2);
          FUN_00012240(auStack_540,0x104,uVar3);
          local_33a = 0;
          local_334 = FUN_00015a58(param_1,auStack_540);
          iVar1 = FUN_00015868(param_1,auStack_540);
          if ((iVar1 != 0) && ((local_334 == 1 || (local_334 == 2)))) {
            FUN_0001581c(param_1,auStack_540);
          }
        }
        memset(&local_330,0,0x104);
      }
      iVar1 = FUN_0001552c(param_1,&local_330,0x104);
    }
  }
  FUN_00025660(local_20);
  return;
}



/* 000154d4 FUN_000154d4 */

/* Boundary evidence: original MIPS .pdata 000154d4..0001552b. Semantic name remains unreviewed. */

undefined4 * FUN_000154d4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027f88;
  FUN_00015b84(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001552c FUN_0001552c */

/* Boundary evidence: original MIPS .pdata 0001552c..0001560f. Semantic name remains unreviewed. */

char * FUN_0001552c(int param_1,char *param_2,int param_3)

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



/* 00015610 FUN_00015610 */

/* Boundary evidence: original MIPS .pdata 00015610..000157a3. Semantic name remains unreviewed. */

undefined4 FUN_00015610(int param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  DWORD local_30 [2];
  char local_28;
  char local_27;
  char local_26;
  undefined4 local_1c;
  
  local_1c = DAT_0002f964;
  local_28 = '\0';
  memset(&local_27,0,9);
  local_30[0] = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  ReadFile(hFile,&local_28,3,local_30,(LPOVERLAPPED)0x0);
  if (((local_28 == -0x11) && (local_27 == -0x45)) && (local_26 == -0x41)) {
    *(undefined4 *)(&DAT_00080e90 + param_1) = 3;
  }
  else if ((local_28 == -1) && (local_27 == -2)) {
    *(undefined4 *)(&DAT_00080e90 + param_1) = 1;
  }
  else if ((local_28 == -2) && (local_27 == -1)) {
    *(undefined4 *)(&DAT_00080e90 + param_1) = 2;
  }
  else {
    *(undefined4 *)(&DAT_00080e90 + param_1) = 0;
  }
  if (hFile != (HANDLE)0x0) {
    CloseHandle(hFile);
  }
  FUN_00025660(local_1c);
  return *(undefined4 *)(&DAT_00080e90 + param_1);
}



/* 000157a4 FUN_000157a4 */

/* Boundary evidence: original MIPS .pdata 000157a4..000157e7. Semantic name remains unreviewed. */

void FUN_000157a4(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    if (*(FILE **)(param_1 + 4) != (FILE *)0x0) {
      fclose(*(FILE **)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



/* 000157e8 FUN_000157e8 */

int FUN_000157e8(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0xc)) {
    iVar1 = param_2 * 0x210 + param_1 + 0x10;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 0001581c FUN_0001581c */

/* Boundary evidence: original MIPS .pdata 0001581c..00015867. Semantic name remains unreviewed. */

void FUN_0001581c(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = iVar1 + 1;
  if (iVar2 < 1000) {
    *(int *)(param_1 + 0xc) = iVar2;
    memcpy((void *)(iVar1 * 0x210 + param_1 + 0x10),param_2,0x210);
  }
  return;
}



/* 00015868 FUN_00015868 */

/* Boundary evidence: original MIPS .pdata 00015868..000158a3. Semantic name remains unreviewed. */

bool FUN_00015868(undefined4 param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(param_2);
  return DVar1 != 0x10;
}



/* 000158a4 FUN_000158a4 */

/* Boundary evidence: original MIPS .pdata 000158a4..000158cb. Semantic name remains unreviewed. */

uint FUN_000158a4(undefined4 param_1,LPCWSTR param_2)

{
  DWORD DVar1;
  
  DVar1 = GetFileAttributesW(param_2);
  return DVar1 & 2;
}



/* 000158cc FUN_000158cc */

/* Boundary evidence: original MIPS .pdata 000158cc..00015a57. Semantic name remains unreviewed. */

wchar_t * FUN_000158cc(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  wchar_t wVar1;
  short sVar2;
  size_t sVar3;
  wchar_t *_Count;
  
  memset(&DAT_001b3380,0,0x208);
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
      swprintf((wchar_t *)&DAT_001b3380,(size_t)_Count,param_3,param_2);
      sVar3 = wcslen((wchar_t *)&DAT_001b3380);
      sVar2 = *(short *)((int)&DAT_001b337c + sVar3 * 2 + 2);
      if (((sVar2 == 0xd) || (sVar2 == 10)) && ((int)sVar3 < 0x104)) {
        *(undefined2 *)((int)&DAT_001b337c + sVar3 * 2 + 2) = 0;
      }
      param_2 = (wchar_t *)&DAT_001b3380;
    }
  }
  return param_2;
}



/* 00015a58 FUN_00015a58 */

/* Boundary evidence: original MIPS .pdata 00015a58..00015b23. Semantic name remains unreviewed. */

undefined4 FUN_00015a58(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t local_20;
  undefined1 auStack_1e [14];
  undefined4 local_10;
  
  local_10 = DAT_0002f964;
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    FUN_00025660(DAT_0002f964);
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
    FUN_00025660(local_10);
  }
  return uVar3;
}



/* 00015b24 FUN_00015b24 */

/* Boundary evidence: original MIPS .pdata 00015b24..00015b83. Semantic name remains unreviewed. */

undefined4 * FUN_00015b24(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027f9c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x203a4] = 4;
  param_1[3] = 0;
  memset(param_1 + 4,0,1000);
  return param_1;
}



/* 00015b84 FUN_00015b84 */

/* Boundary evidence: original MIPS .pdata 00015b84..00015bcb. Semantic name remains unreviewed. */

void FUN_00015b84(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027f9c;
  FUN_000157a4(param_1);
  param_1[3] = 0;
  memset(param_1 + 4,0,1000);
  return;
}



/* 00015bcc FUN_00015bcc */

/* Boundary evidence: original MIPS .pdata 00015bcc..00015c47. Semantic name remains unreviewed. */

undefined4 FUN_00015bcc(int param_1,wchar_t *param_2)

{
  FILE *pFVar1;
  
  FUN_000157a4(param_1);
  *(undefined4 *)(param_1 + 0xc) = 0;
  memset((void *)(param_1 + 0x10),0,1000);
  pFVar1 = _wfopen(param_2,L"rt");
  *(FILE **)(param_1 + 4) = pFVar1;
  *(uint *)(param_1 + 8) = (uint)(pFVar1 != (FILE *)0x0);
  FUN_00015610(param_1,param_2);
  return *(undefined4 *)(param_1 + 8);
}



/* 00015c48 FUN_00015c48 */

/* Boundary evidence: original MIPS .pdata 00015c48..00015c93. Semantic name remains unreviewed. */

undefined4 FUN_00015c48(undefined4 param_1,uint param_2)

{
  FUN_00015b84(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015c94 FUN_00015c94 */

/* Boundary evidence: original MIPS .pdata 00015c94..00015ccb. Semantic name remains unreviewed. */

undefined4 * FUN_00015c94(undefined4 *param_1)

{
  FUN_00015b24(param_1);
  *param_1 = &PTR_FUN_00027fac;
  return param_1;
}



/* 00015ccc FUN_00015ccc */

/* Boundary evidence: original MIPS .pdata 00015ccc..00015cef. Semantic name remains unreviewed. */

void FUN_00015ccc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027fac;
  FUN_00015b84();
  return;
}



/* 00015cf0 FUN_00015cf0 */

/* Boundary evidence: original MIPS .pdata 00015cf0..00015d4f. Semantic name remains unreviewed. */

int FUN_00015cf0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00015bcc(param_1);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 4))(param_1,param_3);
  }
  return iVar1;
}



/* 00015d50 FUN_00015d50 */

/* Boundary evidence: original MIPS .pdata 00015d50..00015fc3. Semantic name remains unreviewed. */

void FUN_00015d50(int param_1,undefined4 param_2)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  WCHAR *pWVar5;
  undefined1 auStack_750 [518];
  undefined2 local_54a;
  int local_544;
  char local_540;
  undefined1 auStack_53f [261];
  short sStack_43a;
  WCHAR local_438;
  undefined1 auStack_436 [518];
  undefined2 local_230;
  undefined1 auStack_22e [518];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  if (*(int *)(param_1 + 8) != 0) {
    local_540 = '\0';
    memset(auStack_53f,0,0x103);
    local_438 = L'\0';
    memset(auStack_436,0,0x206);
    iVar1 = FUN_0001552c(param_1,&local_540,0x104);
    while (iVar1 != 0) {
      memset(&local_438,0,0x208);
      sVar2 = strlen(&local_540);
      iVar1 = MultiByteToWideChar(0xfde9,8,&local_540,sVar2,(LPWSTR)0x0,0);
      if (iVar1 != 0) {
        sVar2 = strlen(&local_540);
        MultiByteToWideChar(0xfde9,8,&local_540,sVar2,&local_438,iVar1);
        if (((&sStack_43a)[iVar1] == 10) && (iVar1 < 0x104)) {
          (&sStack_43a)[iVar1] = 0;
        }
        iVar1 = _wcsnicmp(&local_438,L"File",4);
        if (iVar1 == 0) {
          uVar4 = 0;
          sVar2 = wcslen(&local_438);
          if (sVar2 != 0) {
            pWVar5 = &local_438;
            do {
              uVar4 = uVar4 + 1;
              if (*pWVar5 == L'=') {
                if (4 < (int)uVar4) {
                  local_230 = 0;
                  memset(auStack_22e,0,0x206);
                  FUN_00012240(&local_230,0x104,auStack_436 + uVar4 * 2 + -2);
                  uVar3 = FUN_000158cc(param_1,&local_230,param_2);
                  FUN_00012240(auStack_750,0x104,uVar3);
                  local_54a = 0;
                  local_544 = FUN_00015a58(param_1,auStack_750);
                  iVar1 = FUN_00015868(param_1,auStack_750);
                  if ((iVar1 != 0) && ((local_544 == 1 || (local_544 == 2)))) {
                    FUN_0001581c(param_1,auStack_750);
                  }
                }
                break;
              }
              pWVar5 = pWVar5 + 1;
              sVar2 = wcslen(&local_438);
            } while (uVar4 < sVar2);
          }
        }
      }
      iVar1 = FUN_0001552c(param_1,&local_540,0x104);
    }
  }
  FUN_00025660(local_28);
  return;
}



/* 00015fc4 FUN_00015fc4 */

/* Boundary evidence: original MIPS .pdata 00015fc4..0001601b. Semantic name remains unreviewed. */

undefined4 * FUN_00015fc4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027fac;
  FUN_00015b84(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001601c FUN_0001601c */

/* Boundary evidence: original MIPS .pdata 0001601c..00016053. Semantic name remains unreviewed. */

undefined4 * FUN_0001601c(undefined4 *param_1)

{
  FUN_00015b24(param_1);
  *param_1 = &PTR_FUN_00027fc0;
  return param_1;
}



/* 00016054 FUN_00016054 */

/* Boundary evidence: original MIPS .pdata 00016054..00016077. Semantic name remains unreviewed. */

void FUN_00016054(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00027fc0;
  FUN_00015b84();
  return;
}



/* 00016078 FUN_00016078 */

/* Boundary evidence: original MIPS .pdata 00016078..000163e7. Semantic name remains unreviewed. */

void FUN_00016078(int param_1,undefined4 param_2)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  size_t sVar5;
  wchar_t *pwVar6;
  int iVar7;
  int iVar8;
  wchar_t awStack_758 [259];
  undefined2 local_552;
  int local_54c;
  char local_548;
  undefined1 auStack_547 [263];
  WCHAR local_440;
  undefined1 auStack_43e [518];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  if (*(int *)(param_1 + 8) != 0) {
    local_548 = '\0';
    memset(auStack_547,0,0x103);
    local_440 = L'\0';
    memset(auStack_43e,0,0x206);
    iVar4 = FUN_0001552c(param_1,&local_548,0x104);
    while (iVar4 != 0) {
      memset(&local_440,0,0x208);
      sVar5 = strlen(&local_548);
      iVar4 = MultiByteToWideChar(0xfde9,8,&local_548,sVar5,(LPWSTR)0x0,0);
      if (iVar4 != 0) {
        sVar5 = strlen(&local_548);
        MultiByteToWideChar(0xfde9,8,&local_548,sVar5,&local_440,iVar4);
        sVar5 = wcslen(&local_440);
        iVar7 = -1;
        bVar2 = false;
        bVar3 = false;
        iVar8 = 0;
        iVar4 = -1;
        if (0 < (int)sVar5) {
          pwVar6 = &local_440;
          do {
            wVar1 = *pwVar6;
            if (bVar2) {
              if (wVar1 == L'=') {
                bVar3 = true;
              }
              if ((bVar3) && (wVar1 == L'\"')) {
                iVar4 = iVar8;
                if (-1 < iVar7) break;
                iVar7 = iVar8 + 1;
              }
            }
            else if ((wVar1 == L'<') && (iVar4 = _wcsnicmp(pwVar6,L"<media src",10), iVar4 == 0)) {
              bVar2 = true;
            }
            iVar8 = iVar8 + 1;
            pwVar6 = pwVar6 + 1;
            iVar4 = -1;
          } while (iVar8 < (int)sVar5);
        }
        local_238 = L'\0';
        memset(auStack_236,0,0x206);
        if (((((bVar2) && (bVar3)) && (-1 < iVar7)) && ((-1 < iVar4 && (iVar7 < 0x104)))) &&
           ((iVar4 < 0x104 && (-1 < iVar4 - iVar7)))) {
          wcsncpy(&local_238,(wchar_t *)(auStack_43e + iVar7 * 2 + -2),iVar4 - iVar7);
          pwVar6 = (wchar_t *)FUN_000158cc(param_1,&local_238,param_2);
          wcsncpy(awStack_758,pwVar6,0x103);
          pwVar6 = awStack_758;
          while ((pwVar6 = wcsstr(pwVar6,L"&apos;"), pwVar6 != (wchar_t *)0x0 &&
                 ((int)((int)pwVar6 - (int)awStack_758 & 0xfffffffeU) < 0x208))) {
            swprintf(pwVar6,0x27ff0,pwVar6 + 6);
          }
          local_552 = 0;
          local_54c = FUN_00015a58(param_1,awStack_758);
          iVar4 = FUN_00015868(param_1,awStack_758);
          if (((iVar4 != 0) && (iVar4 = FUN_000158a4(param_1,awStack_758), iVar4 == 0)) &&
             ((local_54c == 1 || (local_54c == 2)))) {
            FUN_0001581c(param_1,awStack_758);
          }
        }
      }
      iVar4 = FUN_0001552c(param_1,&local_548,0x104);
    }
  }
  FUN_00025660(local_30);
  return;
}



/* 000163e8 FUN_000163e8 */

/* Boundary evidence: original MIPS .pdata 000163e8..0001643f. Semantic name remains unreviewed. */

undefined4 * FUN_000163e8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00027fc0;
  FUN_00015b84(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016440 FUN_00016440 */

undefined4 FUN_00016440(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* 00016450 FUN_00016450 */

/* Boundary evidence: original MIPS .pdata 00016450..00016587. Semantic name remains unreviewed. */

void FUN_00016450(int param_1,int param_2,wchar_t *param_3)

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



/* 00016588 FUN_00016588 */

int FUN_00016588(int param_1,int param_2)

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



/* 00016618 FUN_00016618 */

/* Boundary evidence: original MIPS .pdata 00016618..000167bb. Semantic name remains unreviewed. */

int FUN_00016618(int param_1,wchar_t *param_2)

{
  short sVar1;
  FILE *_File;
  wchar_t *pwVar2;
  size_t sVar3;
  int iVar4;
  short sStack_ea;
  wchar_t local_e8;
  undefined1 auStack_e6 [198];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  _File = _wfopen(param_2,L"rt");
  if (_File == (FILE *)0x0) {
    FUN_00025660(local_20);
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
        FUN_00016450(param_1,iVar4,&local_e8);
        iVar4 = iVar4 + 1;
        memset(&local_e8,0,100);
      }
      pwVar2 = fgetws(&local_e8,100,_File);
    }
    fclose(_File);
    *(int *)(param_1 + 8) = iVar4;
    *(undefined4 *)(param_1 + 4) = 1;
    FUN_00025660(local_20);
  }
  return iVar4;
}



/* 000167bc FUN_000167bc */

/* Boundary evidence: original MIPS .pdata 000167bc..00016803. Semantic name remains unreviewed. */

undefined4 * FUN_000167bc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_00016618(param_1,L"\\storage Card\\system\\data\\LatinSortData.txt");
  return param_1;
}



/* 00016804 FUN_00016804 */

/* Boundary evidence: original MIPS .pdata 00016804..0001688b. Semantic name remains unreviewed. */

undefined4 * FUN_00016804(void)

{
  undefined4 *puVar1;
  
  if (DAT_001b3588 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0xba0);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_001b3588 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_00028050;
      FUN_000167bc(puVar1 + 1);
      DAT_001b3588 = puVar1;
    }
  }
  return DAT_001b3588;
}



/* 0001688c Unwind@0001688c */

/* Boundary evidence: original MIPS .pdata 0001688c..000168bb. Semantic name remains unreviewed. */

void Unwind_0001688c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 000168bc FUN_000168bc */

undefined4 FUN_000168bc(undefined4 param_1,int *param_2,int param_3)

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
        goto LAB_00016968;
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
LAB_00016968:
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 00016974 FUN_00016974 */

/* Boundary evidence: original MIPS .pdata 00016974..00016a3f. Semantic name remains unreviewed. */

void FUN_00016974(int param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_2 != (ushort *)0x0) && (param_3 != (uint *)0x0)) {
    uVar1 = *param_2;
    for (iVar4 = 0; (uVar1 != 0 && (iVar4 < 0x104)); iVar4 = iVar4 + 1) {
      iVar2 = FUN_00016440(param_1 + 4);
      if (iVar2 == 0) {
        *param_3 = (uint)*param_2;
      }
      else {
        uVar3 = FUN_00016588(param_1 + 4,(int)(short)*param_2);
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



/* 00016a40 FUN_00016a40 */

/* Boundary evidence: original MIPS .pdata 00016a40..00016a97. Semantic name remains unreviewed. */

undefined4 * FUN_00016a40(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00028050;
  FUN_000207e4(param_1 + 1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016a98 FUN_00016a98 */

/* Boundary evidence: original MIPS .pdata 00016a98..00016b27. Semantic name remains unreviewed. */

void FUN_00016a98(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_830;
  undefined1 auStack_82c [1036];
  undefined4 local_420;
  undefined1 auStack_41c [1036];
  
  local_420 = 0;
  memset(auStack_41c,0,0x40c);
  local_830 = 0;
  memset(auStack_82c,0,0x40c);
  FUN_00016974(param_1,param_2,&local_420);
  FUN_00016974(param_1,param_3,&local_830);
  FUN_000168bc(param_1,&local_420,&local_830);
  return;
}



/* 00016b28 FUN_00016b28 */

undefined4 * FUN_00016b28(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  return param_1;
}



/* 00016b3c FUN_00016b3c */

/* Boundary evidence: original MIPS .pdata 00016b3c..00016df3. Semantic name remains unreviewed. */

undefined4 FUN_00016b3c(undefined4 param_1,HANDLE param_2,int param_3)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  DWORD local_150 [2];
  undefined1 auStack_148 [40];
  undefined1 auStack_120 [30];
  undefined1 local_102;
  byte local_fe;
  undefined4 local_1c;
  
  local_1c = DAT_0002f964;
  FUN_000235a8(5,0,L"%S %d ReadID3v1","CID3Tag::ReadID3v1",0x18e);
  FUN_00024cc4(auStack_148);
  local_150[0] = 0;
  memset(auStack_120,0,0x104);
  BVar1 = ReadFile(param_2,auStack_120,0x1e,local_150,(LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    local_102 = 0;
    FUN_00025144(auStack_148,auStack_120,param_3 + 0x410,0x104);
    iVar2 = FUN_00024f1c(auStack_148,param_3 + 0x410,0x103);
    if (iVar2 != 0) {
      *(uint *)(param_3 + 0x820) = *(uint *)(param_3 + 0x820) | 1;
    }
    memset(auStack_120,0,0x104);
    BVar1 = ReadFile(param_2,auStack_120,0x1e,local_150,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      local_102 = 0;
      FUN_00025144(auStack_148,auStack_120,param_3,0x82);
      iVar2 = FUN_00024f1c(auStack_148,param_3,0x81);
      if (iVar2 != 0) {
        *(uint *)(param_3 + 0x820) = *(uint *)(param_3 + 0x820) | 4;
      }
      memset(auStack_120,0,0x104);
      BVar1 = ReadFile(param_2,auStack_120,0x1e,local_150,(LPOVERLAPPED)0x0);
      if (BVar1 != 0) {
        local_102 = 0;
        FUN_00025144(auStack_148,auStack_120,param_3 + 0x208,0x82);
        iVar2 = FUN_00024f1c(auStack_148,param_3 + 0x208,0x81);
        if (iVar2 != 0) {
          *(uint *)(param_3 + 0x820) = *(uint *)(param_3 + 0x820) | 2;
        }
        memset(auStack_120,0,0x104);
        BVar1 = ReadFile(param_2,auStack_120,0x23,local_150,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          uVar4 = 0;
        }
        else {
          uVar3 = (uint)local_fe;
          if (0x94 < uVar3) {
            uVar3 = 0x94;
          }
          FUN_00012240(param_3 + 0x618,0x82,(&PTR_u_Blues_0002f1f0)[uVar3]);
          *(uint *)(param_3 + 0x820) = *(uint *)(param_3 + 0x820) | 0x10;
          uVar4 = 1;
        }
        FUN_000207e4(auStack_148);
        FUN_00025660(local_1c);
        return uVar4;
      }
    }
  }
  FUN_000207e4(auStack_148);
  FUN_00025660(local_1c);
  return 0;
}



/* 00016df4 Unwind@00016df4 */

/* Boundary evidence: original MIPS .pdata 00016df4..00016e23. Semantic name remains unreviewed. */

void Unwind_00016df4(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x148);
  return;
}



/* 00016e24 FUN_00016e24 */

/* Boundary evidence: original MIPS .pdata 00016e24..00016ff7. Semantic name remains unreviewed. */

undefined4 FUN_00016e24(undefined4 param_1,char *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 3) {
    iVar1 = strcmp(param_2,"TIT2");
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = strcmp(param_2,"TOPE");
    if (iVar1 == 0) {
      return 10;
    }
    iVar1 = strcmp(param_2,"TPE1");
    if (iVar1 == 0) {
      return 2;
    }
    iVar1 = strcmp(param_2,"TPE2");
    if (iVar1 == 0) {
      return 8;
    }
    iVar1 = strcmp(param_2,"TPE3");
    if (iVar1 == 0) {
      return 9;
    }
    iVar1 = strcmp(param_2,"TALB");
    if (iVar1 == 0) {
      return 7;
    }
    iVar1 = strcmp(param_2,"TCON");
    if (iVar1 == 0) {
      return 6;
    }
    iVar1 = strcmp(param_2,"TYER");
    if (iVar1 == 0) {
      return 4;
    }
    iVar1 = strcmp(param_2,"COMM");
    if (iVar1 == 0) {
      return 5;
    }
    iVar1 = strcmp(param_2,"APIC");
    if (iVar1 == 0) {
      return 100;
    }
  }
  else if (param_3 == 2) {
    iVar1 = strcmp(param_2,"TT2");
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = strcmp(param_2,"TP1");
    if (iVar1 == 0) {
      return 2;
    }
    iVar1 = strcmp(param_2,"TAL");
    if (iVar1 == 0) {
      return 3;
    }
  }
  return 0;
}



/* 00016ff8 FUN_00016ff8 */

/* Boundary evidence: original MIPS .pdata 00016ff8..00017c6f. Semantic name remains unreviewed. */

undefined4 FUN_00016ff8(undefined4 param_1,LPCWSTR param_2,void *param_3)

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
  byte local_2b8;
  DWORD local_2b4;
  undefined1 auStack_2b0 [40];
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
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  FUN_00024cc4(auStack_2b0);
  local_238 = local_238 & 0xffffff00;
  memset((void *)((int)&local_238 + 1),0,0x103);
  bVar9 = 0;
  local_2b4 = 0;
  local_2b8 = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    memset(param_3,0,0x824);
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    SetFilePointer(hFile,0,(PLONG)0x0,0);
    BVar2 = ReadFile(hFile,&local_238,0x1e,&local_2b4,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
      if (hFile != (HANDLE)0x0) {
        CloseHandle(hFile);
      }
    }
    else {
      memcpy(auStack_258,&local_238,0x1e);
      if ((local_220 < 1) || (0x10 < local_220)) {
        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
        if (hFile != (HANDLE)0x0) {
          CloseHandle(hFile);
        }
      }
      else {
        iVar3 = memcmp(auStack_258,&DAT_00028ba8,0x10);
        if ((iVar3 == 0) && (iVar3 = 0, 0 < local_220)) {
          _Buf2 = &DAT_00028bb8;
          _Buf2_00 = &DAT_00028bc8;
          local_27c = &DAT_00028bb8;
          local_278 = &DAT_00028bc8;
          do {
            memset(&local_238,0,0x80);
            BVar2 = ReadFile(hFile,&local_238,0x18,&local_2b4,(LPOVERLAPPED)0x0);
            if (BVar2 == 0) {
              *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
              if (hFile != (HANDLE)0x0) {
                CloseHandle(hFile);
              }
              goto LAB_00017c24;
            }
            memcpy(auStack_270,&local_238,0x18);
            if ((local_224 < 0) ||
               ((((local_224 == 0 && (local_228 < 0x19)) || (0 < local_224)) ||
                ((local_224 == 0 && (DVar1 <= local_228)))))) {
              *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
              if (hFile != (HANDLE)0x0) {
                CloseHandle(hFile);
              }
              goto LAB_00017c24;
            }
            iVar6 = local_228 - 0x18;
            local_25c = local_224 - (uint)(local_228 < 0x18);
            local_260 = iVar6;
            iVar4 = memcmp(auStack_270,_Buf2_00,0x10);
            if (iVar4 == 0) {
              BVar2 = ReadFile(hFile,&local_238,10,&local_2b4,(LPOVERLAPPED)0x0);
              if (BVar2 == 0) {
                *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00017c24;
              }
              memcpy(&local_288,&local_238,10);
              uVar5 = local_238 & 0xffff;
              if (((DVar1 < uVar5) || (DVar1 < local_238 >> 0x10)) ||
                 ((DVar1 < local_232 || ((DVar1 < local_230 || (DVar1 < local_234)))))) {
                *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00017c24;
              }
              sVar7 = (size_t)local_288;
              if (uVar5 < 0x81) {
                BVar2 = ReadFile(hFile,&local_238,uVar5,&local_2b4,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
              }
              else {
                BVar2 = ReadFile(hFile,&local_238,0x80,&local_2b4,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
                SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
              }
              if (0x3c < sVar7) {
                sVar7 = 0x3c;
                local_288 = 0x3c;
              }
              memcpy((void *)((int)param_3 + 0x410),&local_238,sVar7);
              *(undefined2 *)((int)param_3 + 0x44c) = 0;
              iVar4 = FUN_00024f1c(auStack_2b0,(void *)((int)param_3 + 0x410),0x103);
              if (iVar4 != 0) {
                *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 1;
              }
              sVar7 = (size_t)local_286;
              if (sVar7 < 0x81) {
                BVar2 = ReadFile(hFile,&local_238,sVar7,&local_2b4,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
              }
              else {
                BVar2 = ReadFile(hFile,&local_238,0x80,&local_2b4,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
                SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
              }
              if (0x3c < sVar7) {
                sVar7 = 0x3c;
                local_286 = 0x3c;
              }
              memcpy(param_3,&local_238,sVar7);
              *(undefined2 *)((int)param_3 + 0x3c) = 0;
              iVar4 = FUN_00024f1c(auStack_2b0,param_3,0x103);
              if (iVar4 != 0) {
                *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 4;
              }
              SetFilePointer(hFile,(uint)local_284 + (uint)local_280 + (uint)local_282,(PLONG)0x0,1)
              ;
              local_2b8 = bVar9 | 1;
              _Buf2 = local_27c;
              bVar9 = local_2b8;
              if (local_2b8 == 3) {
                *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                if (hFile != (HANDLE)0x0) {
                  CloseHandle(hFile);
                }
                goto LAB_00017c24;
              }
            }
            else {
              iVar4 = memcmp(auStack_270,_Buf2,0x10);
              if (iVar4 == 0) {
                BVar2 = ReadFile(hFile,&local_238,2,&local_2b4,(LPOVERLAPPED)0x0);
                if (BVar2 == 0) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
                uVar5 = local_238 & 0xffff;
                if (DVar1 < uVar5) {
                  *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                  if (hFile != (HANDLE)0x0) {
                    CloseHandle(hFile);
                  }
                  goto LAB_00017c24;
                }
                iVar4 = 0;
                _Buf2_00 = local_278;
                bVar9 = local_2b8;
                if (uVar5 != 0) {
                  do {
                    BVar2 = ReadFile(hFile,&local_238,2,&local_2b4,(LPOVERLAPPED)0x0);
                    if (BVar2 == 0) {
                      *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                      if (hFile != (HANDLE)0x0) {
                        CloseHandle(hFile);
                      }
                      goto LAB_00017c24;
                    }
                    uVar8 = local_238 & 0xffff;
                    if (DVar1 < uVar8) {
                      *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                      if (hFile != (HANDLE)0x0) {
                        CloseHandle(hFile);
                      }
                      goto LAB_00017c24;
                    }
                    if (uVar8 < 0x65) {
                      BVar2 = ReadFile(hFile,&local_238,uVar8,&local_2b4,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                    }
                    else {
                      BVar2 = ReadFile(hFile,&local_238,100,&local_2b4,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                      SetFilePointer(hFile,uVar8 - 100,(PLONG)0x0,1);
                    }
                    memcpy(awStack_130,&local_238,uVar8);
                    iVar6 = _wcsicmp(awStack_130,L"WM/ALBUMTITLE");
                    if (iVar6 == 0) {
                      local_2b8 = local_2b8 | 2;
                      BVar2 = ReadFile(hFile,&local_238,4,&local_2b4,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                      uVar8 = (uint)local_238._2_2_;
                      local_274 = local_238;
                      if (DVar1 < uVar8) {
                        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                      if ((char)local_238 == '\0' && local_238._1_1_ == '\0') {
                        sVar7 = (size_t)local_238._2_2_;
                        if (uVar8 < 0x81) {
                          BVar2 = ReadFile(hFile,&local_238,uVar8,&local_2b4,(LPOVERLAPPED)0x0);
                          if (BVar2 == 0) {
                            *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80
                            ;
                            if (hFile != (HANDLE)0x0) {
                              CloseHandle(hFile);
                            }
                            goto LAB_00017c24;
                          }
                        }
                        else {
                          BVar2 = ReadFile(hFile,&local_238,0x80,&local_2b4,(LPOVERLAPPED)0x0);
                          if (BVar2 == 0) {
                            *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80
                            ;
                            if (hFile != (HANDLE)0x0) {
                              CloseHandle(hFile);
                            }
                            goto LAB_00017c24;
                          }
                          SetFilePointer(hFile,sVar7 - 0x80,(PLONG)0x0,1);
                        }
                        if (0x3c < sVar7) {
                          sVar7 = 0x3c;
                        }
                        memcpy((void *)((int)param_3 + 0x208),&local_238,sVar7);
                        *(undefined2 *)((int)param_3 + 0x244) = 0;
                        iVar6 = FUN_00024f1c(auStack_2b0,(void *)((int)param_3 + 0x208),0x103);
                        if (iVar6 != 0) {
                          *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 2;
                        }
                      }
                      if (local_2b8 == 3) {
                        *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                        if (hFile != (HANDLE)0x0) {
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                    }
                    else {
                      BVar2 = ReadFile(hFile,&local_238,4,&local_2b4,(LPOVERLAPPED)0x0);
                      if (BVar2 == 0) {
                        if (hFile != (HANDLE)0x0) {
                          *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
                          CloseHandle(hFile);
                        }
                        goto LAB_00017c24;
                      }
                      SetFilePointer(hFile,local_238 >> 0x10,(PLONG)0x0,1);
                    }
                    iVar4 = iVar4 + 1;
                    _Buf2 = local_27c;
                    _Buf2_00 = local_278;
                    bVar9 = local_2b8;
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
          *(uint *)((int)param_3 + 0x820) = *(uint *)((int)param_3 + 0x820) | 0x80;
          CloseHandle(hFile);
        }
      }
    }
  }
LAB_00017c24:
  FUN_000207e4(auStack_2b0);
  FUN_00025660(local_30);
  return 0;
}



/* 00017c70 Unwind@00017c70 */

/* Boundary evidence: original MIPS .pdata 00017c70..00017c9f. Semantic name remains unreviewed. */

void Unwind_00017c70(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x2b0);
  return;
}



/* 00017ca0 FUN_00017ca0 */

/* Boundary evidence: original MIPS .pdata 00017ca0..0001858f. Semantic name remains unreviewed. */

undefined4 FUN_00017ca0(undefined4 param_1,HANDLE param_2,uint param_3,void *param_4)

{
  bool bVar1;
  DWORD DVar2;
  BOOL BVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  uint uVar7;
  void *pvVar8;
  wchar_t *pwVar9;
  uint nNumberOfBytesToRead;
  uint uVar10;
  DWORD local_308;
  char local_304;
  char local_303;
  char local_302;
  char local_301;
  uint local_300;
  undefined1 auStack_2f8 [36];
  DWORD local_2d4;
  uint local_2d0;
  undefined4 local_2cc;
  undefined1 local_2c8;
  undefined1 auStack_2c7 [99];
  undefined1 local_264;
  wchar_t awStack_1c0 [200];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  local_2d0 = param_3;
  local_2cc = param_1;
  FUN_00024cc4(auStack_2f8);
  local_300 = 0;
  local_2c8 = 0;
  memset(auStack_2c7,0,0x103);
  local_308 = 0;
  local_304 = '\0';
  memset(&local_303,0,3);
  uVar10 = 0;
  bVar1 = false;
  DVar2 = GetFileSize(param_2,(LPDWORD)0x0);
  local_2d4 = DVar2;
  memset(awStack_1c0,0,400);
  if (param_3 != 0) {
    while( true ) {
      memset(&local_2c8,0,0x104);
      BVar3 = ReadFile(param_2,&local_2c8,4,&local_308,(LPOVERLAPPED)0x0);
      if (BVar3 == 0) goto LAB_00018578;
      iVar4 = FUN_00016e24(param_1,&local_2c8,3);
      memset(&local_304,0,4);
      BVar3 = ReadFile(param_2,&local_304,4,&local_308,(LPOVERLAPPED)0x0);
      if ((BVar3 == 0) ||
         (((((local_304 == '\0' && (local_303 == '\0')) && (local_302 == '\0')) &&
           (local_301 == '\0')) ||
          (uVar7 = CONCAT31(CONCAT21(CONCAT11(local_304,local_303),local_302),local_301),
          DVar2 <= uVar7)))) goto LAB_00018578;
      nNumberOfBytesToRead = uVar7 - 1;
      BVar3 = ReadFile(param_2,&local_2c8,3,&local_308,(LPOVERLAPPED)0x0);
      if (BVar3 == 0) goto LAB_00018578;
      memset(&local_2c8,0,0x104);
      if (iVar4 != 7) break;
      if (nNumberOfBytesToRead < 0x65) {
        BVar3 = ReadFile(param_2,&local_2c8,nNumberOfBytesToRead,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          *(undefined1 *)((int)&local_2cc + uVar7 + 3) = 0;
          goto LAB_00017ef8;
        }
        goto LAB_000184ec;
      }
      BVar3 = ReadFile(param_2,&local_2c8,100,&local_308,(LPOVERLAPPED)0x0);
      if (BVar3 == 0) goto LAB_000184ec;
      SetFilePointer(param_2,uVar7 - 0x65,(PLONG)0x0,1);
      local_264 = 0;
LAB_00017ef8:
      if (nNumberOfBytesToRead != 0) {
        if ((*(uint *)((int)param_4 + 0x820) & 1) == 0) {
          pvVar8 = (void *)((int)param_4 + 0x410);
          memset(pvVar8,0,0x208);
          FUN_00025144(auStack_2f8,&local_2c8,pvVar8,nNumberOfBytesToRead);
          FUN_00024f1c(auStack_2f8,pvVar8,0x103);
        }
        if ((*(uint *)((int)param_4 + 0x820) & 2) == 0) {
          pvVar8 = (void *)((int)param_4 + 0x208);
          memset(pvVar8,0,0x104);
          FUN_00025144(auStack_2f8,&local_2c8,pvVar8,nNumberOfBytesToRead);
          FUN_00024f1c(auStack_2f8,pvVar8,0x81);
        }
        wcscpy_s(awStack_1c0,200,(wchar_t *)((int)param_4 + 0x410));
        bVar1 = true;
        break;
      }
LAB_000184b8:
      local_300 = nNumberOfBytesToRead + local_300 + 0xb;
      DVar2 = local_2d4;
      param_1 = local_2cc;
      if (local_2d0 <= local_300) goto LAB_00018098;
    }
    if (iVar4 == 1) {
      if (nNumberOfBytesToRead < 0x65) {
        BVar3 = ReadFile(param_2,&local_2c8,nNumberOfBytesToRead,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          *(undefined1 *)((int)&local_2cc + uVar7 + 3) = 0;
          goto LAB_00018024;
        }
      }
      else {
        BVar3 = ReadFile(param_2,&local_2c8,100,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          SetFilePointer(param_2,uVar7 - 0x65,(PLONG)0x0,1);
          local_264 = 0;
LAB_00018024:
          if (nNumberOfBytesToRead != 0) {
            pwVar9 = (wchar_t *)((int)param_4 + 0x410);
            memset(pwVar9,0,0x208);
            FUN_00025144(auStack_2f8,&local_2c8,pwVar9,nNumberOfBytesToRead);
            iVar4 = FUN_00024f1c(auStack_2f8,pwVar9,0x103);
            if ((iVar4 != 0) && (sVar5 = wcslen(pwVar9), sVar5 != 0)) {
              *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 1;
            }
          }
          uVar10 = uVar10 | 1;
LAB_0001808c:
          if (uVar10 != 0xf) goto LAB_000184b8;
          goto LAB_00018098;
        }
      }
    }
    else if (((iVar4 == 2) || (iVar4 == 9)) || ((iVar4 == 8 || (iVar4 == 10)))) {
      if (nNumberOfBytesToRead < 0x65) {
        BVar3 = ReadFile(param_2,&local_2c8,nNumberOfBytesToRead,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          *(undefined1 *)((int)&local_2cc + uVar7 + 3) = 0;
          goto LAB_000183d0;
        }
      }
      else {
        BVar3 = ReadFile(param_2,&local_2c8,100,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          SetFilePointer(param_2,uVar7 - 0x65,(PLONG)0x0,1);
          local_264 = 0;
          SetFilePointer(param_2,nNumberOfBytesToRead,(PLONG)0x0,1);
LAB_000183d0:
          if (nNumberOfBytesToRead != 0) {
            if (iVar4 < DAT_0002f1ec) {
              memset(param_4,0,0x104);
              FUN_00025144(auStack_2f8,&local_2c8,param_4,nNumberOfBytesToRead);
              DAT_0002f1ec = iVar4;
            }
            iVar6 = FUN_00024f1c(auStack_2f8,param_4,0x81);
            if (iVar6 != 0) {
              *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 4;
            }
            uVar10 = uVar10 | 2;
            if (uVar10 != 0xf) goto LAB_00018460;
            goto LAB_00018098;
          }
          goto LAB_00018460;
        }
      }
    }
    else if (iVar4 == 3) {
      if (nNumberOfBytesToRead < 0x65) {
        BVar3 = ReadFile(param_2,&local_2c8,nNumberOfBytesToRead,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          *(undefined1 *)((int)&local_2cc + uVar7 + 3) = 0;
          goto LAB_000181f8;
        }
      }
      else {
        BVar3 = ReadFile(param_2,&local_2c8,100,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          SetFilePointer(param_2,-100,(PLONG)0x0,1);
          local_264 = 0;
LAB_000181f8:
          if (nNumberOfBytesToRead != 0) {
            pwVar9 = (wchar_t *)((int)param_4 + 0x208);
            memset(pwVar9,0,0x104);
            FUN_00025144(auStack_2f8,&local_2c8,pwVar9,nNumberOfBytesToRead);
            iVar4 = FUN_00024f1c(auStack_2f8,pwVar9,0x81);
            if ((iVar4 != 0) && (sVar5 = wcslen(pwVar9), sVar5 != 0)) {
              *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 2;
            }
          }
          uVar10 = uVar10 | 4;
          goto LAB_0001808c;
        }
      }
    }
    else {
      if (iVar4 != 6) {
LAB_00018460:
        if (((((iVar4 != 7) && (iVar4 != 6)) && (iVar4 != 3)) && ((iVar4 != 2 && (iVar4 != 9)))) &&
           ((iVar4 != 8 && (iVar4 != 10)))) {
          SetFilePointer(param_2,nNumberOfBytesToRead,(PLONG)0x0,1);
        }
        goto LAB_000184b8;
      }
      if (nNumberOfBytesToRead < 0x65) {
        BVar3 = ReadFile(param_2,&local_2c8,nNumberOfBytesToRead,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          *(undefined1 *)((int)&local_2cc + uVar7 + 3) = 0;
          goto LAB_000182e4;
        }
      }
      else {
        BVar3 = ReadFile(param_2,&local_2c8,100,&local_308,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          SetFilePointer(param_2,-100,(PLONG)0x0,1);
          local_264 = 0;
LAB_000182e4:
          if (nNumberOfBytesToRead != 0) {
            pvVar8 = (void *)((int)param_4 + 0x618);
            memset(pvVar8,0,0x104);
            FUN_00025144(auStack_2f8,&local_2c8,pvVar8,nNumberOfBytesToRead);
            iVar4 = FUN_00024f1c(auStack_2f8,pvVar8,0x81);
            if (iVar4 != 0) {
              *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 0x10;
            }
          }
          uVar10 = uVar10 | 8;
          goto LAB_0001808c;
        }
      }
    }
LAB_000184ec:
    if (bVar1) {
      sVar5 = wcslen((wchar_t *)((int)param_4 + 0x410));
      if (sVar5 == 0) {
        memcpy((wchar_t *)((int)param_4 + 0x410),awStack_1c0,0x81);
        *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 1;
      }
      sVar5 = wcslen((wchar_t *)((int)param_4 + 0x208));
      if (sVar5 == 0) {
        memcpy((wchar_t *)((int)param_4 + 0x208),awStack_1c0,0x81);
        *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 2;
      }
    }
LAB_00018578:
    FUN_000207e4(auStack_2f8);
    FUN_00025660(local_30);
    return 0;
  }
  goto LAB_00018100;
LAB_00018098:
  if (bVar1) {
    sVar5 = wcslen((wchar_t *)((int)param_4 + 0x410));
    if (sVar5 == 0) {
      memcpy((wchar_t *)((int)param_4 + 0x410),awStack_1c0,0x81);
      *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 1;
    }
    sVar5 = wcslen((wchar_t *)((int)param_4 + 0x208));
    if (sVar5 == 0) {
      memcpy((wchar_t *)((int)param_4 + 0x208),awStack_1c0,0x81);
      *(uint *)((int)param_4 + 0x820) = *(uint *)((int)param_4 + 0x820) | 2;
    }
  }
LAB_00018100:
  FUN_000207e4(auStack_2f8);
  FUN_00025660(local_30);
  return 1;
}



/* 00018590 Unwind@00018590 */

/* Boundary evidence: original MIPS .pdata 00018590..000185bf. Semantic name remains unreviewed. */

void Unwind_00018590(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x2f8);
  return;
}



/* 000185c0 FUN_000185c0 */

/* Boundary evidence: original MIPS .pdata 000185c0..00018c3b. Semantic name remains unreviewed. */

undefined4 FUN_000185c0(undefined4 param_1,HANDLE param_2,uint param_3,int param_4)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  DWORD local_168;
  char local_164;
  char local_163;
  char local_162;
  uint local_160;
  undefined4 local_15c;
  undefined1 auStack_158 [39];
  undefined1 auStack_131 [101];
  undefined1 local_cc;
  undefined4 local_2c;
  
  local_2c = DAT_0002f964;
  local_15c = param_1;
  FUN_00024cc4(auStack_158);
  auStack_131[1] = 0;
  uVar7 = 0;
  memset(auStack_131 + 2,0,0x103);
  local_168 = 0;
  local_164 = '\0';
  memset(&local_163,0,3);
  local_160 = GetFileSize(param_2,(LPDWORD)0x0);
  uVar6 = 0;
  uVar4 = 1;
  if (param_3 != 0) {
    do {
      uVar5 = local_160;
      memset(auStack_131 + 1,0,0x104);
      BVar1 = ReadFile(param_2,auStack_131 + 1,3,&local_168,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
LAB_00018bdc:
        FUN_000207e4(auStack_158);
        FUN_00025660(local_2c);
        return 0;
      }
      iVar2 = FUN_00016e24(param_1,auStack_131 + 1,2);
      memset(&local_164,0,4);
      BVar1 = ReadFile(param_2,&local_164,3,&local_168,(LPOVERLAPPED)0x0);
      if (((BVar1 == 0) || (((local_164 == '\0' && (local_163 == '\0')) && (local_162 == '\0')))) ||
         (uVar3 = (uint)CONCAT21(CONCAT11(local_164,local_163),local_162), uVar5 <= uVar3))
      goto LAB_00018bdc;
      uVar5 = uVar3 - 1;
      memset(auStack_131 + 1,0,0x104);
      BVar1 = ReadFile(param_2,auStack_131 + 1,1,&local_168,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) goto LAB_00018bdc;
      if (iVar2 != 1) {
        if (((iVar2 == 2) || (iVar2 == 9)) || ((iVar2 == 8 || (iVar2 == 10)))) {
          if (uVar5 < 0x65) {
            BVar1 = ReadFile(param_2,auStack_131 + 1,uVar5,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              auStack_131[uVar3] = 0;
              goto LAB_00018ae0;
            }
          }
          else {
            BVar1 = ReadFile(param_2,auStack_131 + 1,100,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              SetFilePointer(param_2,uVar3 - 0x65,(PLONG)0x0,1);
              local_cc = 0;
LAB_00018ae0:
              if (uVar5 != 0) {
                if (iVar2 < DAT_0002f1ec) {
                  FUN_00025144(auStack_158,auStack_131 + 1,param_4,0x82);
                  DAT_0002f1ec = iVar2;
                }
                iVar2 = FUN_00024f1c(auStack_158,param_4,0x81);
                if (iVar2 != 0) {
                  *(uint *)(param_4 + 0x820) = *(uint *)(param_4 + 0x820) | 4;
                }
              }
              uVar6 = uVar6 | 2;
joined_r0x00018a34:
              if (uVar6 != 0xf) goto LAB_00018b4c;
              break;
            }
          }
        }
        else if (iVar2 == 3) {
          if (uVar5 < 0x65) {
            BVar1 = ReadFile(param_2,auStack_131 + 1,uVar5,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              auStack_131[uVar3] = 0;
              goto LAB_00018908;
            }
          }
          else {
            BVar1 = ReadFile(param_2,auStack_131 + 1,100,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              SetFilePointer(param_2,uVar3 - 0x65,(PLONG)0x0,1);
              local_cc = 0;
LAB_00018908:
              if (uVar5 != 0) {
                FUN_00025144(auStack_158,auStack_131 + 1,param_4 + 0x208,0x82);
                iVar2 = FUN_00024f1c(auStack_158,param_4 + 0x208,0x81);
                if (iVar2 != 0) {
                  *(uint *)(param_4 + 0x820) = *(uint *)(param_4 + 0x820) | 2;
                }
              }
              uVar6 = uVar6 | 4;
              goto joined_r0x00018a34;
            }
          }
        }
        else {
          if (iVar2 != 6) {
            SetFilePointer(param_2,uVar5,(PLONG)0x0,1);
            goto LAB_00018b4c;
          }
          if (uVar5 < 0x65) {
            BVar1 = ReadFile(param_2,auStack_131 + 1,uVar5,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              auStack_131[uVar3] = 0;
              goto LAB_000189e8;
            }
          }
          else {
            BVar1 = ReadFile(param_2,auStack_131 + 1,100,&local_168,(LPOVERLAPPED)0x0);
            if (BVar1 != 0) {
              SetFilePointer(param_2,uVar3 - 0x65,(PLONG)0x0,1);
              local_cc = 0;
LAB_000189e8:
              if (uVar5 != 0) {
                FUN_00025144(auStack_158,auStack_131 + 1,param_4 + 0x618,0x82);
                iVar2 = FUN_00024f1c(auStack_158,param_4 + 0x618,0x81);
                if (iVar2 != 0) {
                  *(uint *)(param_4 + 0x820) = *(uint *)(param_4 + 0x820) | 0x10;
                }
              }
              uVar6 = uVar6 | 4;
              goto joined_r0x00018a34;
            }
          }
        }
LAB_00018ba8:
        uVar4 = 0;
        break;
      }
      if (uVar5 < 0x65) {
        BVar1 = ReadFile(param_2,auStack_131 + 1,uVar5,&local_168,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) goto LAB_00018ba8;
        auStack_131[uVar3] = 0;
      }
      else {
        BVar1 = ReadFile(param_2,auStack_131 + 1,100,&local_168,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) goto LAB_00018bdc;
        SetFilePointer(param_2,uVar3 - 0x65,(PLONG)0x0,1);
        local_cc = 0;
      }
      if (uVar5 != 0) {
        FUN_00025144(auStack_158,auStack_131 + 1,param_4 + 0x410,0x104);
        iVar2 = FUN_00024f1c(auStack_158,param_4 + 0x410,0x103);
        if (iVar2 != 0) {
          *(uint *)(param_4 + 0x820) = *(uint *)(param_4 + 0x820) | 1;
        }
      }
      uVar6 = uVar6 | 1;
      if (uVar6 == 0xf) break;
LAB_00018b4c:
      uVar7 = uVar5 + uVar7 + 6;
      param_1 = local_15c;
    } while (uVar7 < param_3);
  }
  FUN_000207e4(auStack_158);
  FUN_00025660(local_2c);
  return uVar4;
}



/* 00018c3c Unwind@00018c3c */

/* Boundary evidence: original MIPS .pdata 00018c3c..00018c6b. Semantic name remains unreviewed. */

void Unwind_00018c3c(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x158);
  return;
}



/* 00018c6c FUN_00018c6c */

/* Boundary evidence: original MIPS .pdata 00018c6c..00018f47. Semantic name remains unreviewed. */

BOOL FUN_00018c6c(undefined4 param_1,HANDLE param_2,wchar_t *param_3)

{
  byte bVar1;
  DWORD DVar2;
  BOOL BVar3;
  size_t sVar4;
  uint uVar5;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  DWORD local_2c;
  
  FUN_000235a8(5,0,L"%S %d ReadID3v2","CID3Tag::ReadID3v2",0x1ef);
  local_2c = 0;
  local_30 = 0;
  memset(&local_2f,0,3);
  DVar2 = GetFileSize(param_2,(LPDWORD)0x0);
  memset(&local_30,0,4);
  BVar3 = ReadFile(param_2,&local_30,2,&local_2c,(LPOVERLAPPED)0x0);
  bVar1 = local_30;
  if (BVar3 != 0) {
    memset(&local_30,0,4);
    BVar3 = ReadFile(param_2,&local_30,1,&local_2c,(LPOVERLAPPED)0x0);
    if (BVar3 != 0) {
      memset(&local_30,0,4);
      BVar3 = ReadFile(param_2,&local_30,4,&local_2c,(LPOVERLAPPED)0x0);
      if (BVar3 != 0) {
        uVar5 = (((uint)local_30 << 7 | (uint)local_2f) << 7 | (uint)local_2e) << 7 | (uint)local_2d
        ;
        if (uVar5 < DVar2) {
          if ((bVar1 == 3) || (bVar1 == 4)) {
            BVar3 = FUN_00017ca0(param_1,param_2,uVar5,param_3);
            FUN_000235a8(5,0,L"%S %d ReadID3Ver3Frame","CID3Tag::ReadID3v2",0x228);
          }
          else if (bVar1 == 2) {
            BVar3 = FUN_000185c0(param_1,param_2,uVar5,param_3);
            FUN_000235a8(5,0,L"%S %d ReadID3Ver2Frame","CID3Tag::ReadID3v2",0x22e);
          }
          else if (bVar1 == 1) {
            FUN_000235a8(5,0,L"%S %d ReadID3Ver1Frame","CID3Tag::ReadID3v2",0x234);
          }
        }
        sVar4 = wcslen(param_3 + 0x104);
        if (sVar4 != 0) {
          *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 2;
        }
        sVar4 = wcslen(param_3);
        if (sVar4 != 0) {
          *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 4;
        }
        sVar4 = wcslen(param_3 + 0x30c);
        if (sVar4 != 0) {
          *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 0x10;
        }
        sVar4 = wcslen(param_3 + 0x208);
        if (sVar4 == 0) {
          return BVar3;
        }
        *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 1;
        return BVar3;
      }
    }
  }
  return 0;
}



/* 00018f48 FUN_00018f48 */

/* Boundary evidence: original MIPS .pdata 00018f48..000193a3. Semantic name remains unreviewed. */

undefined4 FUN_00018f48(undefined4 param_1,LPCWSTR param_2,wchar_t *param_3)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  DWORD local_878 [2];
  wchar_t awStack_870 [260];
  wchar_t awStack_668 [260];
  wchar_t awStack_460 [260];
  wchar_t awStack_258 [264];
  char local_48;
  char local_47 [31];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  local_48 = '\0';
  memset(local_47,0,0x1e);
  DAT_0002f1ec = 0xb;
  local_878[0] = 0;
  uVar4 = 0;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    memset(param_3,0,0x824);
    memset(&local_48,0,0x1f);
    BVar1 = ReadFile(hFile,&local_48,3,local_878,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      iVar2 = strcmp(&local_48,"ID3");
      if (iVar2 == 0) {
        uVar4 = FUN_00018c6c(param_1,hFile,param_3);
        if (*(int *)(param_3 + 0x410) == 0) {
          SetFilePointer(hFile,-0x80,(PLONG)0x0,2);
          BVar1 = ReadFile(hFile,&local_48,3,local_878,(LPOVERLAPPED)0x0);
          if (BVar1 != 0) {
            iVar2 = strcmp(&local_48,"TAG");
            if (iVar2 == 0) {
              uVar4 = FUN_00016b3c(param_1,hFile,param_3);
            }
LAB_00019350:
            *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 0x80;
            if (hFile != (HANDLE)0x0) {
              CloseHandle(hFile);
            }
            FUN_00025660(local_28);
            return uVar4;
          }
        }
        else {
          SetFilePointer(hFile,-0x80,(PLONG)0x0,2);
          BVar1 = ReadFile(hFile,&local_48,3,local_878,(LPOVERLAPPED)0x0);
          if (BVar1 != 0) {
            iVar2 = strcmp(&local_48,"TAG");
            if (iVar2 == 0) {
              memset(awStack_870,0,0x824);
              uVar4 = FUN_00016b3c(param_1,hFile,awStack_870);
              sVar3 = wcslen(param_3 + 0x104);
              if ((sVar3 == 0) && (sVar3 = wcslen(awStack_668), sVar3 != 0)) {
                FUN_00012240(param_3 + 0x104,0x82,awStack_668);
                *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 2;
              }
              sVar3 = wcslen(param_3);
              if ((sVar3 == 0) && (sVar3 = wcslen(awStack_870), sVar3 != 0)) {
                FUN_00012240(param_3,0x82,awStack_870);
                *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 4;
              }
              sVar3 = wcslen(param_3 + 0x30c);
              if ((sVar3 == 0) && (sVar3 = wcslen(awStack_258), sVar3 != 0)) {
                FUN_00012240(param_3 + 0x30c,0x82,awStack_258);
                *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 0x10;
              }
              sVar3 = wcslen(param_3 + 0x208);
              if ((sVar3 == 0) && (sVar3 = wcslen(awStack_460), sVar3 != 0)) {
                FUN_00012240(param_3 + 0x208,0x82,awStack_460);
                *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 1;
              }
            }
            goto LAB_00019350;
          }
        }
      }
      else {
        SetFilePointer(hFile,-0x80,(PLONG)0x0,2);
        BVar1 = ReadFile(hFile,&local_48,3,local_878,(LPOVERLAPPED)0x0);
        if (BVar1 != 0) {
          iVar2 = strcmp(&local_48,"TAG");
          if (iVar2 == 0) {
            uVar4 = FUN_00016b3c(param_1,hFile,param_3);
          }
          SetFilePointer(hFile,0,(PLONG)0x0,0);
          BVar1 = ReadFile(hFile,&local_48,2,local_878,(LPOVERLAPPED)0x0);
          if (((BVar1 != 0) && (local_48 == -1)) && (local_47[0] == -5)) {
            uVar4 = 1;
          }
          goto LAB_00019350;
        }
      }
    }
    *(uint *)(param_3 + 0x410) = *(uint *)(param_3 + 0x410) | 0x80;
    if (hFile != (HANDLE)0x0) {
      CloseHandle(hFile);
    }
  }
  FUN_00025660(local_28);
  return 0;
}



/* 000193a4 FUN_000193a4 */

/* Boundary evidence: original MIPS .pdata 000193a4..00019433. Semantic name remains unreviewed. */

void FUN_000193a4(int param_1)

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



/* 00019434 FUN_00019434 */

/* Boundary evidence: original MIPS .pdata 00019434..0001947b. Semantic name remains unreviewed. */

void FUN_00019434(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00029314;
  if ((HGDIOBJ)param_1[0x325] != (HGDIOBJ)0x0) {
    DeleteObject((HGDIOBJ)param_1[0x325]);
    param_1[0x325] = 0;
  }
  FUN_000207e4(param_1 + 1);
  return;
}



/* 0001947c FUN_0001947c */

/* Boundary evidence: original MIPS .pdata 0001947c..0001950b. Semantic name remains unreviewed. */

void FUN_0001947c(int param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if (*(HGDIOBJ *)(param_1 + 0xc94) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0xc94));
    *(undefined4 *)(param_1 + 0xc94) = 0;
  }
  uVar1 = param_1 + 0x1ae5U & 3;
  puVar2 = (uint *)((param_1 + 0x1ae5U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x1ae1U & 3;
  puVar2 = (uint *)((param_1 + 0x1ae1U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x1addU & 3;
  puVar2 = (uint *)((param_1 + 0x1addU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 0U >> (3 - uVar1) * 8;
  *(undefined4 *)(param_1 + 0xc8c) = 0;
  uVar1 = param_1 + 0x1ae2U & 3;
  puVar2 = (uint *)((param_1 + 0x1ae2U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x1adeU & 3;
  puVar2 = (uint *)((param_1 + 0x1adeU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  uVar1 = param_1 + 0x1adaU & 3;
  puVar2 = (uint *)((param_1 + 0x1adaU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | 0 << uVar1 * 8;
  *(undefined4 *)(param_1 + 0x1af0) = 0;
  *(undefined4 *)(param_1 + 0x1afc) = 0;
  *(undefined4 *)(param_1 + 0x1b00) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0xc90) = 1;
  memset((void *)(param_1 + 0x20),0,0xc6c);
  return;
}



/* 0001950c FUN_0001950c */

/* Boundary evidence: original MIPS .pdata 0001950c..000195db. Semantic name remains unreviewed. */

void FUN_0001950c(int param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  
  *(int *)(param_1 + 0x1ae2) = param_2;
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  iVar1 = *(int *)(param_1 + 0x1ae2);
  if (iVar1 == 0) {
    pwVar2 = L"ST_NONE";
  }
  else if (iVar1 == 1) {
    pwVar2 = L"ST_PLAY";
  }
  else if (iVar1 == 2) {
    pwVar2 = L"ST_PAUSE";
  }
  else {
    pwVar2 = L"ST_STOP";
  }
  FUN_000235a8(5,2,L"%S PlayStatus %s","CPlayControl::setPlayStatus",pwVar2);
  return;
}



/* 000195dc FUN_000195dc */

/* Boundary evidence: original MIPS .pdata 000195dc..00019763. Semantic name remains unreviewed. */

int FUN_000195dc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_48 [40];
  
  FUN_00024cc4(auStack_48);
  iVar1 = FUN_00023424();
  uVar2 = FUN_00012b84(*(undefined4 *)(iVar1 + 0x58),param_2);
  iVar1 = FUN_00023424();
  iVar1 = FUN_00012df0(*(undefined4 *)(iVar1 + 0x58),uVar2);
  iVar3 = FUN_00023424();
  iVar3 = FUN_00012710(*(undefined4 *)(iVar3 + 0x58),uVar2);
  iVar3 = iVar3 + iVar1 + -1;
  if (((*(int *)(param_1 + 0x1ada) == 2) && (*(int *)(param_1 + 0x1ade) == 0)) &&
     (iVar4 = FUN_00023424(), *(int *)(iVar4 + 0x24) == 0)) {
    if (*(int *)(param_1 + 0x1ad6) == iVar3) {
      *(int *)(param_1 + 0x1ad6) = iVar1 + -1;
    }
  }
  else if (*(int *)(param_1 + 0x1ad6) == iVar3) {
    iVar1 = FUN_00023424();
    uVar2 = FUN_00013de4(*(undefined4 *)(iVar1 + 0x58),uVar2);
    iVar1 = FUN_00023424();
    iVar1 = FUN_00012df0(*(undefined4 *)(iVar1 + 0x58),uVar2);
    iVar3 = FUN_00023424();
    iVar3 = FUN_00012710(*(undefined4 *)(iVar3 + 0x58),uVar2);
    iVar3 = iVar3 + iVar1 + -1;
  }
  if ((param_2 < iVar3) && (iVar1 <= param_2)) {
    iVar1 = param_2 + 1;
  }
  FUN_000207e4(auStack_48);
  return iVar1;
}



/* 00019764 Unwind@00019764 */

/* Boundary evidence: original MIPS .pdata 00019764..00019793. Semantic name remains unreviewed. */

void Unwind_00019764(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x48);
  return;
}



/* 00019794 FUN_00019794 */

/* Boundary evidence: original MIPS .pdata 00019794..000198f3. Semantic name remains unreviewed. */

int FUN_00019794(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_40 [40];
  
  FUN_00024cc4(auStack_40);
  if (*(int *)(param_1 + 0x1ade) == 0) {
    iVar1 = FUN_00023424();
    uVar2 = FUN_00012b84(*(undefined4 *)(iVar1 + 0x58),param_2);
    iVar1 = FUN_00023424();
    iVar3 = FUN_00012df0(*(undefined4 *)(iVar1 + 0x58),uVar2);
    iVar1 = FUN_00023424();
    iVar1 = FUN_00012710(*(undefined4 *)(iVar1 + 0x58),uVar2);
    iVar1 = iVar1 + iVar3;
    if (param_2 == iVar3) {
      iVar1 = FUN_00023424();
      uVar2 = FUN_00013f74(*(undefined4 *)(iVar1 + 0x58),uVar2);
      iVar1 = FUN_00023424();
      iVar3 = FUN_00012df0(*(undefined4 *)(iVar1 + 0x58),uVar2);
      iVar1 = FUN_00023424();
      iVar1 = FUN_00012710(*(undefined4 *)(iVar1 + 0x58),uVar2);
      iVar1 = iVar1 + iVar3;
    }
    iVar1 = iVar1 + -1;
    if ((iVar3 < param_2) && (param_2 <= iVar1)) {
      iVar1 = param_2 + -1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14) + -1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(param_1 + 8) + -1;
    }
    if (param_3 == 0) {
      *(int *)(param_1 + 0x14) = iVar1;
    }
    iVar1 = *(int *)(iVar1 * 4 + *(int *)(param_1 + 0x18));
  }
  FUN_000207e4(auStack_40);
  return iVar1;
}



/* 000198f4 Unwind@000198f4 */

/* Boundary evidence: original MIPS .pdata 000198f4..00019923. Semantic name remains unreviewed. */

void Unwind_000198f4(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x40);
  return;
}



/* 00019924 FUN_00019924 */

/* Boundary evidence: original MIPS .pdata 00019924..0001995f. Semantic name remains unreviewed. */

void FUN_00019924(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),5);
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa0) = 0;
  return;
}



/* 00019960 FUN_00019960 */

/* Boundary evidence: original MIPS .pdata 00019960..0001998f. Semantic name remains unreviewed. */

void FUN_00019960(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),6);
  return;
}



/* 00019990 FUN_00019990 */

/* Boundary evidence: original MIPS .pdata 00019990..000199b7. Semantic name remains unreviewed. */

void FUN_00019990(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  return;
}



/* 000199b8 FUN_000199b8 */

void FUN_000199b8(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x1afc) = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0xc9d) = 0;
    *(undefined1 *)(param_1 + 0xc9b) = 0;
    *(undefined1 *)(param_1 + 0xc9c) = 0;
  }
  else {
    uVar1 = param_2 / 0x3c & 0xff;
    *(char *)(param_1 + 0xc9b) = (char)(param_2 / 0x3c);
    if (uVar1 < 0x3c) {
      *(undefined1 *)(param_1 + 0xc9d) = 0;
    }
    else {
      *(char *)(param_1 + 0xc9d) = (char)(uVar1 / 0x3c);
      *(char *)(param_1 + 0xc9b) = (char)(uVar1 % 0x3c);
    }
    *(char *)(param_1 + 0xc9c) = (char)(param_2 % 0x3c);
  }
  return;
}



/* 00019a38 FUN_00019a38 */

void FUN_00019a38(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x1b00) = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0xc9a) = 0;
    *(undefined1 *)(param_1 + 0xc98) = 0;
    *(undefined1 *)(param_1 + 0xc99) = 0;
  }
  else {
    uVar1 = param_2 / 0x3c & 0xff;
    *(char *)(param_1 + 0xc98) = (char)(param_2 / 0x3c);
    if (uVar1 < 0x3c) {
      *(undefined1 *)(param_1 + 0xc9a) = 0;
    }
    else {
      *(char *)(param_1 + 0xc9a) = (char)(uVar1 / 0x3c);
      *(char *)(param_1 + 0xc98) = (char)(uVar1 % 0x3c);
    }
    *(char *)(param_1 + 0xc99) = (char)(param_2 % 0x3c);
  }
  return;
}



/* 00019ab8 FUN_00019ab8 */

/* Boundary evidence: original MIPS .pdata 00019ab8..00019b23. Semantic name remains unreviewed. */

void FUN_00019ab8(int param_1,int param_2)

{
  int iVar1;
  
  if (3 < param_2) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x1ada) = param_2;
  *(int *)(param_1 + 0xc6c) = param_2;
  *(int *)(param_1 + 0x1af4) = param_2;
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  return;
}



/* 00019b24 FUN_00019b24 */

/* Boundary evidence: original MIPS .pdata 00019b24..00019d1f. Semantic name remains unreviewed. */

undefined4
FUN_00019b24(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6,
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
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x20) != 0) {
          return 0xffffffff;
        }
        if (param_7 == iVar3 + param_3) {
          local_4e58 = iVar3;
        }
        if (*(int *)(param_1 + 0x1ade) == 0) {
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
        if (*(int *)(param_1 + 0x1ade) == 0) {
          return 0xffffffff;
        }
        iVar3 = FUN_00023424();
        if (*(int *)(iVar3 + 0x20) != 0) {
          return 0xffffffff;
        }
        Sleep(1);
      } while (1 < (int)uVar2);
    }
    piVar6[iVar5] = aiStack_4e4c[1];
  }
  return 0;
}



/* 00019d20 FUN_00019d20 */

void FUN_00019d20(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x1ade) = (uint)(param_2 != 0);
  return;
}



/* 00019d38 FUN_00019d38 */

/* Boundary evidence: original MIPS .pdata 00019d38..00019ed3. Semantic name remains unreviewed. */

undefined4 FUN_00019d38(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  iVar1 = FUN_00023424();
  iVar2 = FUN_00012b84(*(undefined4 *)(iVar1 + 0x58),*(undefined4 *)(param_1 + 0x1ad6));
  iVar6 = 0;
  *(undefined **)(param_1 + 0x18) = &DAT_001b358c;
  iVar1 = iVar2;
  do {
    iVar3 = FUN_00023424();
    if ((*(int *)(iVar3 + 0x20) != 0) || (*(int *)(param_1 + 0x1ade) == 0)) {
      return 0xffffffff;
    }
    Sleep(1);
    iVar3 = FUN_00023424();
    iVar3 = FUN_00012750(*(undefined4 *)(iVar3 + 0x58),iVar1);
    *(int *)(param_1 + 0xc) = iVar3;
    iVar4 = FUN_00023424();
    iVar4 = FUN_00012790(*(undefined4 *)(iVar4 + 0x58),iVar1);
    iVar4 = iVar4 + iVar3 + -1;
    *(int *)(param_1 + 0x10) = iVar4;
    if (iVar1 == iVar2) {
      uVar5 = FUN_00019b24(param_1,&DAT_001b358c + iVar6 * 4,iVar3,iVar4,1,1,
                           *(undefined4 *)(param_1 + 0x1ad6));
    }
    else {
      uVar5 = FUN_00019b24(param_1,&DAT_001b358c + iVar6 * 4,iVar3,iVar4,1,1,0xffffffff);
    }
    iVar3 = FUN_00023424();
    iVar3 = FUN_00012710(*(undefined4 *)(iVar3 + 0x58),iVar1);
    iVar6 = iVar3 + iVar6;
    *(int *)(param_1 + 8) = iVar6;
    iVar3 = FUN_00023424();
    iVar1 = FUN_00013de4(*(undefined4 *)(iVar3 + 0x58),iVar1);
  } while (iVar1 != iVar2);
  *(undefined **)(param_1 + 0x18) = &DAT_001b358c;
  return uVar5;
}



/* 00019ed4 FUN_00019ed4 */

/* Boundary evidence: original MIPS .pdata 00019ed4..00019f5b. Semantic name remains unreviewed. */

void FUN_00019ed4(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0xea6) = 0;
  *(undefined1 *)(param_1 + 0xea7) = 0;
  *(undefined1 *)(param_1 + 0x10ae) = 0;
  *(undefined1 *)(param_1 + 0x10af) = 0;
  *(undefined1 *)(param_1 + 0x12b6) = 0;
  *(undefined1 *)(param_1 + 0x12b7) = 0;
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
    FUN_0002381c(5,0x15,100,0,0);
  }
  return;
}



/* 00019f5c FUN_00019f5c */

/* Boundary evidence: original MIPS .pdata 00019f5c..0001a287. Semantic name remains unreviewed. */

undefined4 FUN_00019f5c(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  size_t _Count;
  wchar_t *_Dest;
  wchar_t *_Dst;
  wchar_t *_Dst_00;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_1490 [8];
  undefined1 auStack_1488 [520];
  undefined1 auStack_1280 [520];
  undefined1 auStack_1078 [1040];
  uint local_c68;
  wchar_t local_c60;
  wchar_t awStack_c5e [259];
  wchar_t local_a58;
  undefined1 auStack_a56 [518];
  undefined1 auStack_850 [2080];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  iVar1 = FUN_00023424();
  uVar5 = *(undefined4 *)(iVar1 + 0x58);
  iVar1 = FUN_00012bbc(uVar5,param_2);
  uVar6 = 1;
  if ((iVar1 == 1) || (iVar1 == 2)) {
    memset(auStack_1490,0,0x82c);
    memset(auStack_850,0,0x410);
    FUN_00012bd8(uVar5,param_2,auStack_850);
    if (iVar1 == 2) {
      FUN_00016ff8();
    }
    else {
      FUN_00018f48(param_1 + 4,auStack_850,auStack_1488);
    }
    _Dest = (wchar_t *)(param_1 + 0xea6);
    memset(_Dest,0,0x208);
    _Dst_00 = (wchar_t *)(param_1 + 0x12b6);
    memset(_Dst_00,0,0x208);
    _Dst = (wchar_t *)(param_1 + 0x10ae);
    memset(_Dst,0,0x208);
    if ((local_c68 & 1) == 0) {
      memset(awStack_c5e,0,0x206);
      local_a58 = L'\0';
      memset(auStack_a56,0,0x206);
      pvVar2 = (void *)FUN_00012ba0(uVar5,param_2);
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
        pvVar2 = (void *)FUN_00012ba0(uVar5,param_2);
        memcpy(_Dest,pvVar2,0x103);
      }
      FUN_000235a8(5,0,L"%S %d Track Name : %s","CPlayControl::setID3Info",0x77c,_Dest);
    }
    else {
      memcpy(_Dest,auStack_1078,0x81);
      FUN_000235a8(5,0,L"%S %d Track Name : %s","CPlayControl::setID3Info",0x782,auStack_1078);
    }
    if ((local_c68 & 2) == 0) {
      wcscpy_s(_Dst_00,0x104,L"No Album");
    }
    else {
      memcpy(_Dst_00,auStack_1280,0x81);
    }
    if ((local_c68 & 4) == 0) {
      wcscpy_s(_Dst,0x104,L"No Artist");
    }
    else {
      memcpy(_Dst,auStack_1488,0x81);
    }
    FUN_00025660(local_30);
  }
  else {
    FUN_000235a8(5,2,L"%S error current media type is not MP3","CPlayControl::setID3Info");
    FUN_00025660(local_30);
    uVar6 = 0;
  }
  return uVar6;
}



/* 0001a288 FUN_0001a288 */

/* Boundary evidence: original MIPS .pdata 0001a288..0001a47f. Semantic name remains unreviewed. */

undefined4 FUN_0001a288(int param_1,undefined4 param_2,int param_3)

{
  wchar_t *_Dst;
  wchar_t *_Dst_00;
  undefined4 uVar1;
  void *_Dst_01;
  undefined1 auStack_848 [8];
  undefined1 auStack_840 [520];
  undefined1 auStack_638 [520];
  undefined1 auStack_430 [1040];
  uint local_20;
  undefined4 local_1c;
  
  local_1c = DAT_0002f964;
  uVar1 = 1;
  if ((param_3 == 1) || (param_3 == 2)) {
    memset(auStack_848,0,0x82c);
    if (param_3 == 2) {
      FUN_00016ff8();
    }
    else {
      FUN_00018f48(param_1 + 4,param_2,auStack_840);
    }
    _Dst_01 = (void *)(param_1 + 0xea6);
    memset(_Dst_01,0,0x208);
    _Dst_00 = (wchar_t *)(param_1 + 0x12b6);
    memset(_Dst_00,0,0x208);
    _Dst = (wchar_t *)(param_1 + 0x10ae);
    memset(_Dst,0,0x208);
    if ((local_20 & 1) == 0) {
      memcpy(_Dst_01,(void *)(param_1 + 0x44c),0x81);
      FUN_000235a8(5,0,L"%S %d Track Name : %s","CPlayControl::setResumeID3Info",0x7b3,_Dst_01);
    }
    else {
      memcpy(_Dst_01,auStack_430,0x81);
      FUN_000235a8(5,0,L"%S %d Track Name : %s","CPlayControl::setResumeID3Info",0x7b9,auStack_430);
    }
    if ((local_20 & 2) == 0) {
      wcscpy_s(_Dst_00,0x104,L"No Album");
    }
    else {
      memcpy(_Dst_00,auStack_638,0x81);
    }
    if ((local_20 & 4) == 0) {
      wcscpy_s(_Dst,0x104,L"No Artist");
    }
    else {
      memcpy(_Dst,auStack_840,0x81);
    }
    FUN_00025660(local_1c);
  }
  else {
    FUN_000235a8(5,2,L"%S error current media type is not MP3","CPlayControl::setResumeID3Info");
    FUN_00025660(local_1c);
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001a480 FUN_0001a480 */

/* Boundary evidence: original MIPS .pdata 0001a480..0001ac87. Semantic name remains unreviewed. */

undefined4 FUN_0001a480(int param_1,LPCWSTR param_2,undefined4 *param_3,DWORD *param_4)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  DWORD DStack_290;
  int local_28c;
  byte local_288;
  byte local_287 [4];
  undefined1 local_283;
  char acStack_282 [194];
  undefined1 local_1c0;
  char local_158;
  char local_157;
  char local_156;
  char local_155;
  undefined4 local_2c;
  
  local_2c = DAT_0002f964;
  uVar9 = 0;
  local_28c = param_1;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    FUN_000235a8(5,1,L"%S FileOpen error %s","CPlayControl::getCoverImage",param_2);
    goto LAB_0001ac4c;
  }
  memset(&local_288,0,300);
  BVar1 = ReadFile(hFile,&local_288,3,&DStack_290,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    FUN_000235a8(5,1,L"%S Mp3 Read id3tag %d","CPlayControl::getCoverImage",DVar2);
LAB_0001ac30:
    *param_3 = 0;
    *param_4 = 0;
    if (hFile == (HANDLE)0x0) goto LAB_0001ac4c;
  }
  else {
    iVar3 = strcmp((char *)&local_288,"ID3");
    if (iVar3 != 0) goto LAB_0001ac30;
    DVar2 = GetFileSize(hFile,(LPDWORD)0x0);
    memset(&local_288,0,300);
    BVar1 = ReadFile(hFile,&local_288,2,&DStack_290,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_000235a8(5,1,L"%S Mp3 Read id3tag : version check %d","CPlayControl::getCoverImage",DVar2)
      ;
      goto LAB_0001ac30;
    }
    memset(&local_288,0,300);
    BVar1 = ReadFile(hFile,&local_288,1,&DStack_290,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_000235a8(5,1,L"%S Mp3 Read id3tag : Flag check %d","CPlayControl::getCoverImage",DVar2);
      goto LAB_0001ac30;
    }
    memset(&local_288,0,300);
    BVar1 = ReadFile(hFile,&local_288,4,&DStack_290,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_000235a8(5,1,L"%S Mp3 Read id3tag : Flag check %d","CPlayControl::getCoverImage",DVar2);
      goto LAB_0001ac30;
    }
    uVar7 = (((uint)local_288 << 7 | (uint)local_287[0]) << 7 | (uint)local_287[1]) << 7 |
            (uint)local_287[2];
    if ((uVar7 < DVar2) && (uVar7 != 0)) {
      do {
        memset(&local_288,0,300);
        BVar1 = ReadFile(hFile,&local_288,4,&DStack_290,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          FUN_000235a8(5,1,L"%S mp3 read failed %d","CPlayControl::getCoverImage",DVar2);
          goto LAB_0001ac30;
        }
        iVar3 = FUN_00016e24(param_1 + 4,&local_288,3);
        memset(&local_158,0,300);
        BVar1 = ReadFile(hFile,&local_158,4,&DStack_290,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          FUN_000235a8(5,1,L"%S mp3 read failed %d","CPlayControl::getCoverImage",DVar2);
          goto LAB_0001ac30;
        }
        if (((((local_158 == '\0') && (local_157 == '\0')) && (local_156 == '\0')) &&
            (local_155 == '\0')) ||
           (uVar6 = CONCAT31(CONCAT21(CONCAT11(local_158,local_157),local_156),local_155),
           DVar2 <= uVar6)) goto LAB_0001ac30;
        uVar6 = uVar6 - 1;
        BVar1 = ReadFile(hFile,&local_288,3,&DStack_290,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          DVar2 = GetLastError();
          FUN_000235a8(5,1,L"%S mp3 read failed %d","CPlayControl::getCoverImage",DVar2);
          goto LAB_0001ac30;
        }
        memset(&local_288,0,300);
        if (iVar3 == 100) {
          FUN_000235a8(5,1,L"%S picture found","CPlayControl::getCoverImage");
          if (uVar6 < 0xc9) {
            DVar2 = GetLastError();
            FUN_000235a8(5,2,L"%S picture read failed %d","CPlayControl::getCoverImage",DVar2);
          }
          else {
            BVar1 = ReadFile(hFile,&local_288,200,&DStack_290,(LPOVERLAPPED)0x0);
            if (BVar1 == 0) {
              DVar2 = GetLastError();
              FUN_000235a8(5,1,L"%S PICTURE read failed %d","CPlayControl::getCoverImage",DVar2);
            }
            else {
              local_1c0 = 0;
              sVar4 = strlen((char *)&local_288);
              local_283 = 0;
              iVar3 = strcmp("image",(char *)&local_288);
              if (iVar3 == 0) {
                iVar3 = _stricmp("jpg",acStack_282);
                if ((iVar3 == 0) || (iVar3 = _stricmp("jpeg",acStack_282), iVar3 == 0)) {
                  uVar8 = 0x12;
                  pwVar5 = L"%S jpg found";
                }
                else {
                  iVar3 = _stricmp("png",acStack_282);
                  if (iVar3 == 0) {
                    uVar8 = 0x17;
                    pwVar5 = L"%S png found";
                  }
                  else {
                    iVar3 = _stricmp("bmp",acStack_282);
                    if (iVar3 != 0) {
                      pwVar5 = L"%S type illegal";
                      goto LAB_0001ab44;
                    }
                    uVar8 = 0x15;
                    pwVar5 = L"%S BMP found";
                  }
                }
                FUN_000235a8(5,0,pwVar5,"CPlayControl::getCoverImage");
                if (local_287[sVar4] != 3) {
                  FUN_000235a8(5,2,L"%S cover not foundl","CPlayControl::getCoverImage");
                }
                SetFilePointer(hFile,sVar4 - 0xc5,(PLONG)0x0,1);
                DVar2 = (uVar6 - sVar4) - 3;
                if ((int)DVar2 < 0x500000) {
                  *param_3 = &DAT_001b83ac;
                  *param_4 = 0;
                  BVar1 = ReadFile(hFile,(LPVOID)*param_3,DVar2,&DStack_290,(LPOVERLAPPED)0x0);
                  if (BVar1 != 0) {
                    *param_4 = DVar2;
                    FUN_000235a8(5,2,L"%S imglen[%d]imgType[%d]","CPlayControl::getCoverImage",DVar2
                                 ,uVar8);
                    CloseHandle(hFile);
                    FUN_00025660(local_2c);
                    return uVar8;
                  }
                  DVar2 = GetLastError();
                  FUN_000235a8(5,2,L"%S PICTURE read failed %d","CPlayControl::getCoverImage",DVar2)
                  ;
                  *param_3 = 0;
                }
                else {
                  FUN_000235a8(5,2,L"%S not supported imglen  [%d]","CPlayControl::getCoverImage",
                               DVar2);
                }
              }
              else {
                pwVar5 = L"%S picture type illegal";
LAB_0001ab44:
                FUN_000235a8(5,2,pwVar5,"CPlayControl::getCoverImage");
              }
            }
          }
          goto LAB_0001ac30;
        }
        SetFilePointer(hFile,uVar6,(PLONG)0x0,1);
        uVar9 = uVar6 + uVar9 + 0xb;
        param_1 = local_28c;
      } while (uVar9 < uVar7);
    }
  }
  CloseHandle(hFile);
LAB_0001ac4c:
  FUN_00025660(local_2c);
  return 0;
}



/* 0001ac88 FUN_0001ac88 */

/* Boundary evidence: original MIPS .pdata 0001ac88..0001afab. Semantic name remains unreviewed. */

void FUN_0001ac88(int param_1)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  ULARGE_INTEGER local_888;
  ULARGE_INTEGER local_880;
  ULARGE_INTEGER UStack_878;
  undefined1 auStack_870 [4];
  undefined4 local_86c;
  undefined4 local_868;
  WCHAR local_848;
  undefined1 auStack_846 [2078];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  uVar9 = *(undefined4 *)(param_1 + 0x1ad6);
  iVar3 = FUN_00023424();
  uVar4 = FUN_00012b18(*(undefined4 *)(iVar3 + 0x58),uVar9);
  *(undefined4 *)(param_1 + 0x28) = uVar4;
  *(undefined4 *)(param_1 + 0x30) = uVar9;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x1b00);
  iVar3 = FUN_00023424();
  uVar4 = FUN_00012bbc(*(undefined4 *)(iVar3 + 0x58),uVar9);
  *(undefined4 *)(param_1 + 0x34) = uVar4;
  iVar3 = FUN_00023424();
  uVar4 = FUN_000126f4(*(undefined4 *)(iVar3 + 0x58));
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  iVar3 = FUN_00023424();
  uVar5 = FUN_000126e0(*(undefined4 *)(iVar3 + 0x58));
  uVar7 = *(uint *)(param_1 + 0x1ada);
  uVar8 = *(uint *)(param_1 + 0x1ade);
  uVar1 = param_1 + 0x27U & 3;
  puVar2 = (uint *)((param_1 + 0x27U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar5 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0xc6fU & 3;
  puVar2 = (uint *)((param_1 + 0xc6fU) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar7 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0xc73U & 3;
  puVar2 = (uint *)((param_1 + 0xc73U) - uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar8 >> (3 - uVar1) * 8;
  uVar1 = param_1 + 0x24U & 3;
  puVar2 = (uint *)((param_1 + 0x24U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar5 << uVar1 * 8;
  uVar1 = param_1 + 0xc6cU & 3;
  puVar2 = (uint *)((param_1 + 0xc6cU) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar7 << uVar1 * 8;
  uVar1 = param_1 + 0xc70U & 3;
  puVar2 = (uint *)((param_1 + 0xc70U) - uVar1);
  *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar8 << uVar1 * 8;
  local_848 = L'\0';
  memset(auStack_846,0,0x81e);
  iVar3 = FUN_00023424();
  FUN_00012bd8(*(undefined4 *)(iVar3 + 0x58),uVar9,&local_848);
  memcpy((void *)(param_1 + 0x244),&local_848,0x207);
  GetFileAttributesExW(&local_848,GetFileExInfoStandard,auStack_870);
  *(undefined4 *)(param_1 + 0xc84) = local_86c;
  *(undefined4 *)(param_1 + 0xc88) = local_868;
  FUN_000235a8(5,0,L"%S  line %d Resume createTime %d:%d / %d:%d","CPlayControl::updateResumeData",
               0x9f6,local_868,*(undefined4 *)(param_1 + 0xc88),local_86c,
               *(undefined4 *)(param_1 + 0xc84));
  memcpy((void *)(param_1 + 0xa64),(void *)(param_1 + 0x16c6),0x208);
  memcpy((void *)(param_1 + 0x3c),(void *)(param_1 + 0x18ce),0x208);
  memcpy((void *)(param_1 + 0x654),(void *)(param_1 + 0x12b6),0x208);
  memcpy((void *)(param_1 + 0x44c),(void *)(param_1 + 0xea6),0x208);
  memcpy((void *)(param_1 + 0x85c),(void *)(param_1 + 0x10ae),0x208);
  FUN_000235a8(5,0,L"%S  line %d Resume Full Path : %s","CPlayControl::updateResumeData",0x9fe,
               (void *)(param_1 + 0x244));
  FUN_000235a8(5,0,L"%S  line %d Resume fName : %s","CPlayControl::updateResumeData",0x9ff,
               (void *)(param_1 + 0x3c));
  FUN_000235a8(5,0,L"%S  line %d Resume fFolderName : %s","CPlayControl::updateResumeData",0xa00,
               (void *)(param_1 + 0xa64));
  FUN_000235a8(5,0,L"%S  line %d Resume Time : %d","CPlayControl::updateResumeData",0xa01,
               *(undefined4 *)(param_1 + 0x38));
  BVar6 = GetDiskFreeSpaceExW(L"MD",&UStack_878,&local_880,&local_888);
  if (BVar6 == 0) {
    *(undefined4 *)(param_1 + 0xc74) = 0;
    *(undefined4 *)(param_1 + 0xc78) = 0;
    *(undefined4 *)(param_1 + 0xc7c) = 0;
    *(undefined4 *)(param_1 + 0xc80) = 0;
  }
  else {
    *(DWORD *)(param_1 + 0xc74) = local_888.s.LowPart;
    *(DWORD *)(param_1 + 0xc78) = local_888.s.HighPart;
    *(DWORD *)(param_1 + 0xc7c) = local_880.s.LowPart;
    *(DWORD *)(param_1 + 0xc80) = local_880.s.HighPart;
  }
  FUN_00025660(local_28);
  return;
}



/* 0001afac FUN_0001afac */

/* Boundary evidence: original MIPS .pdata 0001afac..0001b057. Semantic name remains unreviewed. */

void FUN_0001afac(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  FUN_00022fd8(iVar1 + 0x60);
  iVar1 = FUN_00023424();
  FUN_00023110(iVar1 + 0x60);
  iVar1 = FUN_00023424();
  FUN_00022ec0(iVar1 + 0x60);
  *(uint *)(param_1 + 0x1ade) = (uint)(*(int *)(param_1 + 0x1af8) == 1);
  iVar1 = FUN_00023424();
  FUN_000230ec(iVar1 + 0x60);
  FUN_00019ab8(param_1,*(undefined4 *)(param_1 + 0x1af4));
  FUN_000235a8(5,0,L"%S  shuffle Mode : %d, repeat Mode : %d",
               "CPlayControl::setResumeShuffleNRepeat",*(undefined4 *)(param_1 + 0x1af8),
               *(undefined4 *)(param_1 + 0x1af4));
  return;
}



/* 0001b058 FUN_0001b058 */

undefined4 FUN_0001b058(undefined4 param_1,byte *param_2,int param_3)

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



/* 0001b0b4 FUN_0001b0b4 */

void FUN_0001b0b4(int param_1)

{
  *(undefined4 *)(param_1 + 0x1ada) = *(undefined4 *)(param_1 + 0xc6c);
  *(undefined4 *)(param_1 + 0x1af4) = *(undefined4 *)(param_1 + 0xc6c);
  *(undefined4 *)(param_1 + 0x1ade) = *(undefined4 *)(param_1 + 0xc70);
  *(undefined4 *)(param_1 + 0x1af8) = *(undefined4 *)(param_1 + 0xc70);
  return;
}



/* 0001b0e8 FUN_0001b0e8 */

/* Boundary evidence: original MIPS .pdata 0001b0e8..0001b16f. Semantic name remains unreviewed. */

void FUN_0001b0e8(void)

{
  undefined4 local_10 [2];
  
  FUN_000235a8(5,0,
               L"%S  -------------------------------------requestMediaFadeIn--------------------------------------"
               ,"CPlayControl::requestMediaFadeIn");
  local_10[0] = 1;
  FUN_00023a50(5,3,0x8b,4,local_10);
  Sleep(200);
  FUN_000235a8(5,0,
               L"%S  -------------------------------------requestMediaFadeIn---END--------------------------------"
               ,"CPlayControl::requestMediaFadeIn");
  return;
}



/* 0001b170 FUN_0001b170 */

/* Boundary evidence: original MIPS .pdata 0001b170..0001b1f3. Semantic name remains unreviewed. */

void FUN_0001b170(void)

{
  undefined4 local_10 [2];
  
  FUN_000235a8(5,0,
               L"%S  -------------------------------------requestMediaFadeOUt--------------------------------------"
               ,"CPlayControl::requestMediaFadeOut");
  local_10[0] = 0;
  Sleep(200);
  FUN_00023a50(5,3,0x8b,4,local_10);
  FUN_000235a8(5,0,
               L"%S  -------------------------------------requestMediaFadeOUt---END--------------------------------"
               ,"CPlayControl::requestMediaFadeOut");
  return;
}



/* 0001b1f4 FUN_0001b1f4 */

/* Boundary evidence: original MIPS .pdata 0001b1f4..0001b247. Semantic name remains unreviewed. */

undefined4 * FUN_0001b1f4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00029314;
  FUN_00016b28(param_1 + 1);
  param_1[0x6bd] = 0;
  param_1[0x6be] = 0;
  FUN_0001947c(param_1);
  param_1[0x325] = 0;
  param_1[0x324] = 1;
  return param_1;
}



/* 0001b248 FUN_0001b248 */

/* Boundary evidence: original MIPS .pdata 0001b248..0001b293. Semantic name remains unreviewed. */

undefined4 FUN_0001b248(undefined4 param_1,uint param_2)

{
  FUN_00019434(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001b294 FUN_0001b294 */

/* Boundary evidence: original MIPS .pdata 0001b294..0001b32f. Semantic name remains unreviewed. */

undefined4 FUN_0001b294(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),2);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),3);
  FUN_0001950c(param_1,3);
  uVar2 = FUN_00011908();
  FUN_00011a24(uVar2,1);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  FUN_00019a38(param_1,0);
  return 0;
}



/* 0001b330 FUN_0001b330 */

/* Boundary evidence: original MIPS .pdata 0001b330..0001b373. Semantic name remains unreviewed. */

void FUN_0001b330(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),1,500,(TIMERPROC)0x0);
  return;
}



/* 0001b374 FUN_0001b374 */

/* Boundary evidence: original MIPS .pdata 0001b374..0001b3e7. Semantic name remains unreviewed. */

void FUN_0001b374(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),5);
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa0) = 0;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 1;
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),5,1000,(TIMERPROC)0x0);
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa0) = 1;
  return;
}



/* 0001b3e8 FUN_0001b3e8 */

/* Boundary evidence: original MIPS .pdata 0001b3e8..0001b43f. Semantic name remains unreviewed. */

void FUN_0001b3e8(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),6);
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 1;
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),6,1000,(TIMERPROC)0x0);
  return;
}



/* 0001b440 FUN_0001b440 */

/* Boundary evidence: original MIPS .pdata 0001b440..0001b483. Semantic name remains unreviewed. */

void FUN_0001b440(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),0xb);
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),0xb,3000,(TIMERPROC)0x0);
  return;
}



/* 0001b484 FUN_0001b484 */

/* Boundary evidence: original MIPS .pdata 0001b484..0001b4f7. Semantic name remains unreviewed. */

void FUN_0001b484(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),2);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),3);
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),2,300,(TIMERPROC)0x0);
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),3,5000,(TIMERPROC)0x0);
  return;
}



/* 0001b4f8 FUN_0001b4f8 */

/* Boundary evidence: original MIPS .pdata 0001b4f8..0001b517. Semantic name remains unreviewed. */

void FUN_0001b4f8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x1af0) = param_2;
  FUN_0001b484();
  return;
}



/* 0001b518 FUN_0001b518 */

/* Boundary evidence: original MIPS .pdata 0001b518..0001b5cf. Semantic name remains unreviewed. */

void FUN_0001b518(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*(int *)(param_1 + 0x1ae2) == 1) || (*(int *)(param_1 + 0x1ae2) == 2)) {
    uVar2 = FUN_00011908();
    uVar2 = FUN_000117b4(uVar2);
  }
  FUN_00019a38(param_1,uVar2);
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  FUN_0002381c(5,0x15,0x65,0,0);
  return;
}



/* 0001b5d0 FUN_0001b5d0 */

/* Boundary evidence: original MIPS .pdata 0001b5d0..0001b67b. Semantic name remains unreviewed. */

void FUN_0001b5d0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00019a38(param_1,param_2);
  *(undefined4 *)(param_1 + 0x38) = param_2;
  if (param_3 != 0) {
    uVar1 = FUN_00011908();
    FUN_000116a0(uVar1,param_2);
  }
  iVar2 = FUN_00023424();
  if (*(int *)(iVar2 + 0x50) != 0) {
    iVar2 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar2 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  FUN_0002381c(5,0x15,0x65,0,0);
  return;
}



/* 0001b67c FUN_0001b67c */

/* Boundary evidence: original MIPS .pdata 0001b67c..0001b73b. Semantic name remains unreviewed. */

void FUN_0001b67c(int param_1,int param_2)

{
  int iVar1;
  
  if (1 < param_2) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x1ade) = param_2;
  *(int *)(param_1 + 0x1af8) = param_2;
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x50) != 0) {
    iVar1 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  *(int *)(param_1 + 0xc70) = param_2;
  if (*(int *)(param_1 + 0x1ade) == 1) {
    FUN_00019d38(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  return;
}



/* 0001b73c FUN_0001b73c */

/* Boundary evidence: original MIPS .pdata 0001b73c..0001ba07. Semantic name remains unreviewed. */

undefined4 FUN_0001b73c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  wchar_t *_Src;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_20 [2];
  
  if (param_2 < 5000) {
    iVar1 = FUN_00023424();
    iVar5 = *(int *)(iVar1 + 0x58);
    iVar1 = FUN_000124e8(iVar5 + 8,0);
    FUN_000193a4(param_1 + 0xc98);
    iVar2 = FUN_00012bbc(iVar5,param_2);
    if (iVar2 == -1) {
      FUN_000235a8(5,0,L"%S not support ext","CPlayControl::makeSongInfo");
    }
    else {
      iVar2 = FUN_00012b40(iVar5,param_2);
      if (iVar2 != 0) {
        _Src = (wchar_t *)FUN_00012ba0(iVar5,param_2);
        wcscpy_s((wchar_t *)(param_1 + 0x18ce),0x104,_Src);
        FUN_00013634(iVar5,(int)*(short *)(param_2 * 0x210 + iVar1 + 0x208),param_1 + 0x16c6);
        uVar3 = FUN_00019f5c(param_1,param_2);
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x50) == 0) {
          FUN_000235a8(5,3,L"%S getGlobalVal()->m_ocsharedMemory NULL","CPlayControl::makeSongInfo")
          ;
          return uVar3;
        }
        iVar1 = FUN_00023424();
        FUN_000241e8(*(undefined4 *)(iVar1 + 0x50),param_1 + 0xc98,0,0xe56);
        iVar1 = FUN_00023424();
        FUN_0001f0ac(*(undefined4 *)(iVar1 + 0x5c),param_2);
        FUN_0002381c(5,0x15,100,0,0);
        iVar1 = *(int *)(param_1 + 0x1ad6);
        local_20[0] = 0;
        uVar4 = FUN_000144b8();
        iVar1 = FUN_00012b84(uVar4,iVar1);
        iVar2 = FUN_000144b8();
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        iVar2 = iVar1 * 0x220 + iVar2;
        if (((*(int *)(param_1 + 0x1ade) == 0) && (*(int *)(param_1 + 0x1ada) == 0)) &&
           (*(int *)(param_1 + 0x1ad6) ==
            (int)*(short *)(&DAT_00284cd0 + iVar2) + (int)*(short *)(&DAT_00284cce + iVar2) + -1)) {
          uVar4 = FUN_000144b8();
          iVar1 = FUN_00013d9c(uVar4);
          if (iVar1 == *(short *)(&DAT_00284cd6 + iVar2)) {
            local_20[0] = 1;
            FUN_0002381c(5,0x15,0x72,4,local_20);
            return uVar3;
          }
        }
        FUN_0002381c(5,0x15,0x72,4,local_20);
        return uVar3;
      }
    }
  }
  else {
    FUN_000235a8(5,0,L"%S over USB_MAX_FILE_NUM index : %d","CPlayControl::makeSongInfo",param_2);
  }
  return 0;
}



/* 0001ba08 FUN_0001ba08 */

/* Boundary evidence: original MIPS .pdata 0001ba08..0001bdeb. Semantic name remains unreviewed. */

undefined4 FUN_0001ba08(int param_1,undefined4 param_2)

{
  HDC hdc;
  HRESULT HVar1;
  int iVar2;
  HBITMAP h;
  HGDIOBJ h_00;
  wchar_t *pwVar3;
  uint uVar4;
  undefined4 uVar5;
  int local_c0;
  int *local_bc;
  int *local_b8;
  int local_b4;
  void *apvStack_b0 [2];
  BITMAPINFO local_a8;
  tagRECT tStack_78;
  undefined1 auStack_68 [64];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  local_b8 = (int *)0x0;
  local_bc = (int *)0x0;
  hdc = CreateCompatibleDC((HDC)0x0);
  if (*(HGDIOBJ *)(param_1 + 0xc94) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)(param_1 + 0xc94));
    *(undefined4 *)(param_1 + 0xc94) = 0;
  }
  HVar1 = CoCreateInstance((IID *)&DAT_00029144,(LPUNKNOWN)0x0,1,(IID *)&DAT_00029134,&local_b8);
  if (-1 < HVar1) {
    local_c0 = 0;
    iVar2 = FUN_0001a480(param_1,param_2,&local_c0,&local_b4);
    if (iVar2 == 0x10) {
      pwVar3 = L"%S Jpeg ";
    }
    else if (iVar2 == 0x12) {
      iVar2 = 0;
      if (0 < local_b4 >> 2) {
        uVar4 = 0;
        do {
          uVar4 = (uint)*(byte *)(iVar2 + local_c0) | (uVar4 & 0xff) << 8;
          if (uVar4 == 0xffd8) {
            local_c0 = iVar2 + local_c0 + -1;
            break;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < local_b4 >> 2);
      }
      pwVar3 = L"%S jpeg ";
    }
    else if (iVar2 == 0x15) {
      pwVar3 = L"%S bmp ";
    }
    else if (iVar2 == 0x16) {
      pwVar3 = L"%S gif ";
    }
    else {
      if (iVar2 != 0x17) {
        FUN_000235a8(5,1,L"%S Image type : %d ","CPlayControl::updatePicture",iVar2);
        (**(code **)(*local_b8 + 8))();
        if ((0 < local_b4) && (local_c0 != 0)) {
          __3_YAXPAX_Z();
        }
        DeleteDC(hdc);
        *(undefined4 *)(param_1 + 0x1ae6) = *(undefined4 *)(param_1 + 0xc94);
        iVar2 = FUN_00023424();
        if (*(int *)(iVar2 + 0x50) != 0) {
          iVar2 = FUN_00023424();
          FUN_000241e8(*(undefined4 *)(iVar2 + 0x50),param_1 + 0xc98,0,0xe56);
        }
        uVar5 = 0;
        goto LAB_0001bda4;
      }
      pwVar3 = L"%S png ";
    }
    FUN_000235a8(5,1,pwVar3,"CPlayControl::updatePicture");
    iVar2 = (**(code **)(*local_b8 + 0x14))(local_b8,&DAT_001b83ac,0x500000,0,&local_bc);
    if (-1 < iVar2) {
      (**(code **)(*local_bc + 0x10))(local_bc,auStack_68);
      memset(&local_a8,0,0x28);
      local_a8.bmiHeader.biSize = 0x28;
      local_a8.bmiHeader.biBitCount = 0x18;
      local_a8.bmiHeader.biWidth = 0x116;
      local_a8.bmiHeader.biHeight = 0x116;
      local_a8.bmiHeader.biPlanes = 1;
      h = CreateDIBSection(hdc,&local_a8,0,apvStack_b0,(HANDLE)0x0,0);
      *(HBITMAP *)(param_1 + 0xc94) = h;
      if (h != (HBITMAP)0x0) {
        h_00 = SelectObject(hdc,h);
        SetRect(&tStack_78,0,0,local_a8.bmiHeader.biWidth,local_a8.bmiHeader.biHeight);
        (**(code **)(*local_bc + 0x18))(local_bc,hdc,&tStack_78,0);
        SelectObject(hdc,h_00);
      }
      (**(code **)(*local_bc + 8))();
    }
    (**(code **)(*local_b8 + 8))();
    if ((0 < local_b4) && (local_c0 != 0)) {
      __3_YAXPAX_Z();
    }
  }
  DeleteDC(hdc);
  *(undefined4 *)(param_1 + 0x1ae6) = *(undefined4 *)(param_1 + 0xc94);
  iVar2 = FUN_00023424();
  if (*(int *)(iVar2 + 0x50) != 0) {
    iVar2 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar2 + 0x50),param_1 + 0xc98,0,0xe56);
  }
  uVar5 = 0xffffffff;
LAB_0001bda4:
  FUN_0002381c(5,0x15,0x67,0,0);
  FUN_00025660(local_28);
  return uVar5;
}



/* 0001bdec FUN_0001bdec */

/* Boundary evidence: original MIPS .pdata 0001bdec..0001c21b. Semantic name remains unreviewed. */

undefined4 FUN_0001bdec(int param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  LONG LVar3;
  BOOL BVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  FILETIME *lpFileTime;
  _SYSTEMTIME local_490;
  _SYSTEMTIME local_480;
  undefined1 auStack_470 [4];
  FILETIME local_46c [4];
  ULARGE_INTEGER UStack_448;
  ULARGE_INTEGER UStack_440;
  ULARGE_INTEGER UStack_438;
  wchar_t local_430 [260];
  wchar_t local_228;
  undefined1 auStack_226 [518];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  sVar1 = wcslen((wchar_t *)(param_1 + 0x244));
  if (sVar1 != 0) {
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),2);
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),3);
    memcpy(local_430,(wchar_t *)(param_1 + 0x244),0x208);
    if (local_430[0] != L'\\') {
      local_228 = L'\0';
      memset(auStack_226,0,0x206);
      swprintf(&local_228,0x2a028,local_430);
      memcpy(local_430,&local_228,0x208);
    }
    GetFileAttributesExW(local_430,GetFileExInfoStandard,auStack_470);
    lpFileTime = (FILETIME *)(param_1 + 0xc84);
    FUN_000235a8(5,0,L"%S  line %d %d:%d / %d:%d","CPlayControl::resumePlay",0xa36,
                 local_46c[0].dwHighDateTime,*(undefined4 *)(param_1 + 0xc88),
                 local_46c[0].dwLowDateTime,lpFileTime->dwLowDateTime);
    FileTimeToSystemTime(local_46c,&local_490);
    FileTimeToSystemTime(lpFileTime,&local_480);
    FUN_000235a8(5,0,L"%S  line %d  %d:%d:%d %d:%d:%d:%d","CPlayControl::resumePlay",0xa3f,
                 local_490.wYear,local_490.wMonth,local_490.wDay,local_490.wHour,local_490.wMinute,
                 local_490.wSecond);
    FUN_000235a8(5,0,L"%S  line %d  %d:%d:%d %d:%d:%d:%d","CPlayControl::resumePlay",0xa40,
                 local_480.wYear,local_480.wMonth,local_480.wDay,local_480.wHour,local_480.wMinute,
                 local_480.wSecond);
    if (((param_2 == 0) || (LVar3 = CompareFileTime(local_46c,lpFileTime), LVar3 == 0)) &&
       (BVar4 = GetDiskFreeSpaceExW(L"MD",&UStack_438,&UStack_448,&UStack_440), BVar4 != 0)) {
      FUN_0001b294(param_1);
      FUN_0001ba08(param_1,local_430);
      *(undefined4 *)(param_1 + 0x1ad6) = 0xffffffff;
      puVar6 = (undefined4 *)(param_1 + 0x34);
      uVar5 = FUN_00011908();
      iVar2 = FUN_000114d8(uVar5,local_430,*puVar6);
      if (iVar2 == 1) {
        memcpy((void *)(param_1 + 0x16c6),(void *)(param_1 + 0xa64),0x208);
        memcpy((void *)(param_1 + 0xea6),(void *)(param_1 + 0x44c),0x208);
        memcpy((void *)(param_1 + 0x10ae),(void *)(param_1 + 0x85c),0x208);
        memcpy((void *)(param_1 + 0x12b6),(void *)(param_1 + 0x654),0x208);
        memcpy((void *)(param_1 + 0x18ce),(void *)(param_1 + 0x3c),0x208);
        uVar5 = FUN_00011908();
        uVar5 = FUN_00011838(uVar5);
        FUN_000199b8(param_1,uVar5);
        FUN_0001a288(param_1,local_430,*puVar6);
        puVar6 = (undefined4 *)(param_1 + 0x38);
        uVar5 = FUN_00011908();
        FUN_000116a0(uVar5,*puVar6);
        *(undefined4 *)(param_1 + 0x1b00) = *puVar6;
        iVar2 = FUN_00023424();
        if (*(int *)(iVar2 + 0x50) != 0) {
          iVar2 = FUN_00023424();
          FUN_000241e8(*(undefined4 *)(iVar2 + 0x50),param_1 + 0xc98,0,0xe56);
        }
        FUN_000235a8(5,0,L"%S resumeTime : %d","CPlayControl::resumePlay",*puVar6);
        FUN_0001950c(param_1,1);
        *(undefined4 *)(param_1 + 0x1aea) = 1;
        iVar2 = FUN_00023424();
        FUN_0001d950(*(undefined4 *)(iVar2 + 0x5c));
        FUN_0002381c(5,0x15,0x6b,0,0);
        FUN_000235a8(5,1,L"%S Play success","CPlayControl::resumePlay");
        FUN_00025660(local_20);
        return 1;
      }
      FUN_00019ed4(param_1);
      FUN_000235a8(5,2,L"%S Line %d doesn\'t suppported file format %s / %d",
                   "CPlayControl::resumePlay",0xaa6,local_430,*puVar6);
    }
  }
  FUN_00025660(local_20);
  return 0;
}



/* 0001c21c FUN_0001c21c */

/* Boundary evidence: original MIPS .pdata 0001c21c..0001c537. Semantic name remains unreviewed. */

undefined4 FUN_0001c21c(int param_1,LPCWSTR param_2)

{
  HANDLE hFile;
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *pwVar5;
  int iVar6;
  void *lpBuffer;
  DWORD local_268 [2];
  uint local_260 [10];
  wchar_t awStack_238 [260];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  hFile = CreateFileW(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DVar1 = GetLastError();
    FUN_000235a8(5,1,L"%S resume file invalid handle error %d","CPlayControl::loadResumeData",DVar1)
    ;
  }
  else {
    lpBuffer = (void *)(param_1 + 0x20);
    BVar2 = ReadFile(hFile,lpBuffer,0xc6c,local_268,(LPOVERLAPPED)0x0);
    if (BVar2 == 1) {
      if (local_268[0] == 0xc6c) {
        iVar3 = FUN_0001b058(param_1,lpBuffer,0xc6c);
        if (iVar3 == 1) {
          FUN_000235a8(5,0,L"%S line: %d, Resume Data Verify Success","CPlayControl::loadResumeData"
                       ,0xac5);
          CloseHandle(hFile);
          *(undefined1 *)(param_1 + 0x44a) = 0;
          *(undefined1 *)(param_1 + 1099) = 0;
          sVar4 = wcslen((wchar_t *)(param_1 + 0x244));
          memcpy(awStack_238,(wchar_t *)(param_1 + 0x244),0x208);
          iVar3 = sVar4 - 1;
          if (-1 < iVar3) {
            pwVar5 = awStack_238 + iVar3;
            iVar6 = iVar3;
            do {
              if (((*pwVar5 == L'\\') || (iVar6 == iVar3)) &&
                 (sVar4 = wcslen(awStack_238), sVar4 != 0)) {
                if (iVar6 < iVar3) {
                  *pwVar5 = L'\0';
                }
                GetFileAttributesExW(awStack_238,GetFileExInfoStandard,local_260);
                if ((local_260[0] & 2) != 0) {
                  memset(lpBuffer,0,0xc6c);
                  FUN_000235a8(5,3,L"%S %s Resume Data Hidden property",
                               "CPlayControl::loadResumeData",awStack_238);
                  goto LAB_0001c4fc;
                }
              }
              iVar6 = iVar6 + -1;
              pwVar5 = pwVar5 + -1;
            } while (-1 < iVar6);
          }
          DVar1 = GetFileAttributesW((LPCWSTR)(param_1 + 0xa64));
          if (DVar1 != 0xffffffff) {
            FUN_00025660(local_30);
            return 1;
          }
          goto LAB_0001c4fc;
        }
        pwVar5 = L"%S Resume Data Verify Failed";
      }
      else {
        pwVar5 = L"%S Resume Data size is failed";
      }
      FUN_000235a8(5,1,pwVar5,"CPlayControl::loadResumeData");
    }
    else {
      DVar1 = GetLastError();
      FUN_000235a8(5,1,L"%S Resume Data Read Fail %d","CPlayControl::loadResumeData",DVar1);
    }
    memset(lpBuffer,0,0xc6c);
    CloseHandle(hFile);
  }
LAB_0001c4fc:
  FUN_00025660(local_30);
  return 0;
}



/* 0001c538 FUN_0001c538 */

/* Boundary evidence: original MIPS .pdata 0001c538..0001c66b. Semantic name remains unreviewed. */

BOOL FUN_0001c538(int param_1,LPCWSTR param_2)

{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  char *lpBuffer;
  char cVar3;
  int iVar4;
  DWORD aDStack_20 [2];
  
  iVar4 = 1;
  FUN_000235a8(5,1,L"%S Start","CPlayControl::saveResumeData");
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0x24) = 1;
  hFile = CreateFileW(param_2,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
  lpBuffer = (char *)(param_1 + 0x20);
  cVar3 = '\0';
  do {
    cVar3 = lpBuffer[iVar4] + cVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc6c);
  *lpBuffer = cVar3;
  BVar2 = WriteFile(hFile,lpBuffer,0xc6c,aDStack_20,(LPOVERLAPPED)0x0);
  FUN_000235a8(5,1,L"%S WRITE","CPlayControl::saveResumeData");
  CloseHandle(hFile);
  FUN_000235a8(5,1,L"%S End","CPlayControl::saveResumeData");
  return BVar2;
}



/* 0001c66c FUN_0001c66c */

/* Boundary evidence: original MIPS .pdata 0001c66c..0001c7c7. Semantic name remains unreviewed. */

BOOL FUN_0001c66c(int param_1,LPCWSTR param_2)

{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  char cVar3;
  char *lpBuffer;
  int iVar4;
  DWORD aDStack_20 [2];
  
  iVar4 = 1;
  FUN_000235a8(5,1,L"%S Start","CPlayControl::deletesaveResumeData");
  iVar1 = FUN_00023424();
  lpBuffer = (char *)(param_1 + 0x20);
  *(undefined4 *)(iVar1 + 0x24) = 1;
  FUN_000235a8(5,2,L"%S Line %d ucResume %d ++++++++++++++","CPlayControl::deletesaveResumeData",
               0xb32,lpBuffer);
  hFile = CreateFileW(param_2,0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  cVar3 = '\0';
  do {
    cVar3 = lpBuffer[iVar4] + cVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc6c);
  *lpBuffer = cVar3;
  BVar2 = WriteFile(hFile,lpBuffer,0xc6c,aDStack_20,(LPOVERLAPPED)0x0);
  FUN_000235a8(5,1,L"%S WRITE","CPlayControl::deletesaveResumeData");
  CloseHandle(hFile);
  FUN_000235a8(5,1,L"%S End","CPlayControl::deletesaveResumeData");
  return BVar2;
}



/* 0001c7c8 FUN_0001c7c8 */

/* Boundary evidence: original MIPS .pdata 0001c7c8..0001c877. Semantic name remains unreviewed. */

void FUN_0001c7c8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1ae2);
  if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 0)) {
    if (param_2 == 0) {
      FUN_0001950c(param_1,2);
    }
    uVar1 = FUN_00011908();
    iVar2 = FUN_000118a4(uVar1);
    if (iVar2 == 2) {
      FUN_0001b518(param_1);
    }
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),1);
    uVar1 = FUN_00011908();
    FUN_00011a24(uVar1,0);
  }
  return;
}



/* 0001c878 FUN_0001c878 */

/* Boundary evidence: original MIPS .pdata 0001c878..0001c967. Semantic name remains unreviewed. */

void FUN_0001c878(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_00023424();
  FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
  if (*(int *)(param_1 + 0x1ade) == 0) {
    piVar2 = (int *)(param_1 + 0x1ad6);
    iVar1 = FUN_000195dc(param_1,*piVar2,0);
    if (iVar1 == *piVar2) {
      iVar1 = FUN_000195dc(param_1,*piVar2,0);
    }
    *piVar2 = iVar1;
    iVar1 = *piVar2;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14) + 1;
    *(int *)(param_1 + 0x14) = iVar1;
    if (*(int *)(param_1 + 8) <= iVar1) {
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    piVar2 = (int *)(*(int *)(param_1 + 0x14) * 4 + *(int *)(param_1 + 0x18));
    *(int *)(param_1 + 0x1ad6) = *piVar2;
    iVar1 = *piVar2;
  }
  iVar1 = FUN_0001b73c(param_1,iVar1);
  if (iVar1 != 0) {
    iVar1 = FUN_00023424();
    *(undefined4 *)(iVar1 + 0x30) = 1;
  }
  return;
}



/* 0001c968 FUN_0001c968 */

/* Boundary evidence: original MIPS .pdata 0001c968..0001c9a7. Semantic name remains unreviewed. */

void FUN_0001c968(int param_1)

{
  if ((*(int *)(param_1 + 0xc8c) == 0) &&
     (*(int *)(param_1 + 0xc8c) = *(int *)(param_1 + 0x1ae2), *(int *)(param_1 + 0x1ae2) == 1)) {
    FUN_0001c7c8(param_1,1);
  }
  return;
}



/* 0001c9a8 FUN_0001c9a8 */

/* Boundary evidence: original MIPS .pdata 0001c9a8..0001ced7. Semantic name remains unreviewed. */

undefined4 FUN_0001c9a8(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 local_1078 [2];
  wchar_t local_1070;
  undefined1 auStack_106e [2078];
  wchar_t local_850;
  undefined1 auStack_84e [2078];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),2);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),3);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  FUN_0001b294(param_1);
  local_1070 = L'\0';
  memset(auStack_106e,0,0x81e);
  iVar1 = FUN_00023424();
  FUN_00012bd8(*(undefined4 *)(iVar1 + 0x58),param_2,&local_1070);
  if (local_1070 != L'\\') {
    local_850 = L'\0';
    memset(auStack_84e,0,0x81e);
    swprintf(&local_850,0x2a028,&local_1070);
    memcpy(&local_1070,&local_850,0x81f);
  }
  FUN_0001ba08(param_1,&local_1070);
  iVar1 = FUN_00023424();
  if ((*(int *)(iVar1 + 0x30) == 1) || (iVar1 = FUN_0001b73c(param_1,param_2), iVar1 != 0)) {
    iVar1 = FUN_00023424();
    uVar4 = FUN_00012bbc(*(undefined4 *)(iVar1 + 0x58),param_2);
    uVar2 = FUN_00011908();
    iVar1 = FUN_000114d8(uVar2,&local_1070,uVar4);
  }
  else {
    iVar1 = 2;
  }
  iVar3 = FUN_00023424();
  *(undefined4 *)(iVar3 + 0x30) = 0;
  if (iVar1 != 1) {
    FUN_000235a8(5,2,L"%S doesn\'t suppported file format %s","CPlayControl::play",&local_1070);
  }
  FUN_000235a8(5,1,L"%S index=%d path=%s / %d","CPlayControl::play",param_2,&local_1070,param_3);
  if (iVar1 == 1) {
    uVar4 = FUN_00011908();
    uVar4 = FUN_00011838(uVar4);
    FUN_000199b8(param_1,uVar4);
    FUN_0001b330(param_1);
    FUN_0001950c(param_1,1);
    if (((param_4 == 0) && (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0x40) == 0)) &&
       ((iVar1 = FUN_00023424(), *(int *)(iVar1 + 0x44) == 0 &&
        (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0x3c) == 1)))) {
      FUN_0002381c(5,0x15,0x66,0,0);
      uVar4 = FUN_00011908();
      FUN_0001195c(uVar4);
    }
    else {
      if (*(int *)(param_1 + 0xc8c) == 2) {
        uVar4 = 0;
      }
      else {
        if ((*(int *)(param_1 + 0xc8c) != 0) ||
           (*(int *)(param_1 + 0xc8c) = *(int *)(param_1 + 0x1ae2), *(int *)(param_1 + 0x1ae2) != 1)
           ) goto LAB_0001cc60;
        uVar4 = 1;
      }
      FUN_0001c7c8(param_1,uVar4);
    }
LAB_0001cc60:
    iVar1 = FUN_00023424();
    if (*(int *)(iVar1 + 0x24) == 0) {
      FUN_0002381c(5,0x15,0x6f,0,0);
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0x24) = 1;
    }
    *(int *)(param_1 + 0x1ad6) = param_2;
    *(undefined4 *)(param_1 + 0x1aea) = 0;
    iVar1 = FUN_00023424();
    *(int *)(iVar1 + 0xa4) = param_2;
    FUN_0001ac88(param_1);
    FUN_0002381c(0x15,5,0x84,0,0);
    *(undefined4 *)(param_1 + 0xc90) = 1;
    FUN_000235a8(5,1,L"%S Play success","CPlayControl::play");
    FUN_00025660(local_30);
    return 1;
  }
  FUN_0001950c(param_1,1);
  if (param_5 == 0) {
    iVar1 = FUN_00023424();
    *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc9c) = 2;
    FUN_0002381c(0x15,5,0x81,0,0);
    goto LAB_0001ce9c;
  }
  piVar5 = (int *)(param_1 + 0x1ad6);
  *piVar5 = param_2;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0x24) = 0;
  iVar1 = FUN_00023424();
  if ((*(int *)(iVar1 + 0x20) == 0) && (param_4 == 0)) {
    iVar1 = *piVar5;
    local_1078[0] = 0;
    uVar4 = FUN_000144b8();
    iVar1 = FUN_00012b84(uVar4,iVar1);
    iVar3 = FUN_000144b8();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    iVar3 = iVar1 * 0x220 + iVar3;
    if (((*(int *)(param_1 + 0x1ade) == 0) && (*(int *)(param_1 + 0x1ada) == 0)) &&
       (*piVar5 ==
        (int)*(short *)(&DAT_00284cd0 + iVar3) + (int)*(short *)(&DAT_00284cce + iVar3) + -1)) {
      uVar4 = FUN_000144b8();
      iVar1 = FUN_00013d9c(uVar4);
      if (iVar1 != *(short *)(&DAT_00284cd6 + iVar3)) goto LAB_0001ce48;
      local_1078[0] = 1;
      FUN_0002381c(5,0x15,0x71,4,local_1078);
    }
    else {
LAB_0001ce48:
      local_1078[0] = 0;
      FUN_0002381c(5,0x15,0x71,4,local_1078);
    }
    FUN_0002381c(5,0x15,0x6e,0,0);
  }
  *(undefined4 *)(param_1 + 0xc90) = 0;
  FUN_0002381c(0x15,5,0x84,0,0);
LAB_0001ce9c:
  FUN_00025660(local_30);
  return 0;
}



/* 0001ced8 FUN_0001ced8 */

/* Boundary evidence: original MIPS .pdata 0001ced8..0001d01f. Semantic name remains unreviewed. */

void FUN_0001ced8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  FUN_000235a8(5,1,L"%S Enter resume play","CPlayControl::remainPlay");
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),2);
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),3);
  if (param_2 == 0) {
    FUN_0001950c(param_1,1);
    FUN_0002381c(5,0x15,0x66,0,0);
  }
  uVar2 = FUN_00011908();
  iVar1 = FUN_0001195c(uVar2);
  if (iVar1 == 0) {
    FUN_0001c9a8(param_1,*(undefined4 *)(param_1 + 0x1ad6),1,0,1);
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),1);
  }
  else {
    FUN_0001b330();
  }
  iVar1 = FUN_00023424();
  DVar3 = GetTickCount();
  FUN_000235a8(5,1,L"%S ********************Process TIME : %d ms*********************",
               "CPlayControl::remainPlay",DVar3 - *(int *)(iVar1 + 4));
  return;
}



/* 0001d020 FUN_0001d020 */

/* Boundary evidence: original MIPS .pdata 0001d020..0001d07f. Semantic name remains unreviewed. */

void FUN_0001d020(int param_1)

{
  if (*(int *)(param_1 + 0xc8c) == 1) {
    FUN_000235a8(5,3,L"%S m_nBFVirtualStatus = %d","CPlayControl::virtualResume",1);
    FUN_0001ced8(param_1,1);
  }
  *(undefined4 *)(param_1 + 0xc8c) = 0;
  return;
}



/* 0001d080 FUN_0001d080 */

/* Boundary evidence: original MIPS .pdata 0001d080..0001d107. Semantic name remains unreviewed. */

void FUN_0001d080(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1af0) != 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x1af0) = 0;
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),2);
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),3);
    if ((*(int *)(param_1 + 0x1ae2) == 1) && (*(int *)(param_1 + 0xc8c) == 0)) {
      FUN_0001ced8(param_1,0);
    }
  }
  return;
}



/* 0001d108 FUN_0001d108 */

/* Boundary evidence: original MIPS .pdata 0001d108..0001d61f. Semantic name remains unreviewed. */

void FUN_0001d108(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  FUN_000235a8(5,0,L"%S dshowEndAutoNextPlay","CPlayControl::dshowEndAutoNextPlay");
  FUN_0001b0e8(param_1);
  if (*(int *)(param_1 + 0x1af0) != 0) {
    FUN_0001d080(param_1);
  }
  iVar1 = FUN_00023424();
  FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
  piVar5 = (int *)(param_1 + 0x1ad6);
  iVar1 = *(int *)(param_1 + 0x1ada);
  iVar4 = *piVar5;
  if (iVar1 == 3) {
    FUN_0001c878(param_1);
    FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
  }
  else if (iVar1 == 1) {
    FUN_0001c9a8(param_1,iVar4,3,0,1);
  }
  else if (iVar1 == 2) {
    if (*(int *)(param_1 + 0x1ade) == 0) {
      uVar2 = FUN_000144b8();
      iVar1 = FUN_00012b84(uVar2,iVar4);
      iVar3 = FUN_000144b8();
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      iVar3 = iVar1 * 0x220 + iVar3;
      iVar1 = (int)*(short *)(&DAT_00284cce + iVar3);
      if ((iVar4 < iVar1) || (*(short *)(&DAT_00284cd0 + iVar3) + iVar1 + -1 <= iVar4)) {
        FUN_0001c9a8(param_1,iVar1,3,0,1);
      }
      else {
        FUN_0001c878(param_1);
        FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14);
      iVar4 = *(int *)(param_1 + 0x18);
      uVar2 = FUN_000144b8();
      iVar1 = FUN_00012b84(uVar2,*(undefined4 *)(iVar1 * 4 + iVar4));
      iVar4 = FUN_000144b8();
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      iVar3 = *(int *)(param_1 + 0x14);
      iVar4 = iVar1 * 0x220 + iVar4;
      if (iVar3 + 1 < *(int *)(param_1 + 8)) {
        iVar1 = *(int *)(param_1 + 0x18);
        uVar2 = FUN_000144b8();
        iVar1 = FUN_00012b84(uVar2,*(undefined4 *)((iVar3 + 1) * 4 + iVar1));
        iVar3 = FUN_000144b8();
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        if (*(short *)(&DAT_00284cd6 + iVar4) == *(short *)(&DAT_00284cd6 + iVar1 * 0x220 + iVar3))
        {
          FUN_0001c878(param_1);
          FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
          return;
        }
        iVar1 = (*(int *)(param_1 + 0x14) - (int)*(short *)(&DAT_00284cd0 + iVar4)) + 1;
        *(int *)(param_1 + 0x14) = iVar1;
      }
      else {
        iVar1 = (iVar3 - *(short *)(&DAT_00284cd0 + iVar4)) + 1;
        *(int *)(param_1 + 0x14) = iVar1;
      }
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      FUN_0001c9a8(param_1,*(undefined4 *)(*(int *)(param_1 + 0x14) * 4 + *(int *)(param_1 + 0x18)),
                   3,0,1);
    }
  }
  else if (*(int *)(param_1 + 0x1ade) == 0) {
    uVar2 = FUN_000144b8();
    iVar1 = FUN_00012b84(uVar2,iVar4);
    iVar3 = FUN_000144b8();
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    iVar3 = iVar1 * 0x220 + iVar3;
    if ((iVar4 < *(short *)(&DAT_00284cce + iVar3)) ||
       ((int)*(short *)(&DAT_00284cd0 + iVar3) + (int)*(short *)(&DAT_00284cce + iVar3) + -1 <=
        iVar4)) {
      uVar2 = FUN_000144b8();
      iVar1 = FUN_00013d9c(uVar2);
      if (iVar1 == *(short *)(&DAT_00284cd6 + iVar3)) {
        FUN_0001b294(param_1);
        FUN_0002381c(5,0x15,0x66,0,0);
        memset((void *)(param_1 + 0x20),0,0xc6c);
      }
      else {
        FUN_0001c878(param_1);
        FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
      }
    }
    else {
      FUN_0001c878(param_1);
      FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
    }
  }
  else if (*(int *)(param_1 + 0x14) < *(int *)(param_1 + 8) + -1) {
    FUN_0001c878(param_1);
    FUN_0001c9a8(param_1,*piVar5,3,*(int *)(param_1 + 0xc8c) != 0,1);
  }
  else {
    FUN_0001b294();
    FUN_0002381c(5,0x15,0x66,0,0);
  }
  return;
}



/* 0001d620 FUN_0001d620 */

/* Boundary evidence: original MIPS .pdata 0001d620..0001d72b. Semantic name remains unreviewed. */

void FUN_0001d620(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_00023424();
  FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
  if (*(int *)(param_1 + 0x1af0) == 2) {
    FUN_0001d080(param_1);
  }
  else {
    if (*(int *)(param_1 + 0x1ade) == 0) {
      piVar2 = (int *)(param_1 + 0x1ad6);
      iVar1 = FUN_00019794(param_1,*piVar2,0);
      if (iVar1 == *piVar2) {
        iVar1 = FUN_00019794(param_1,*piVar2,0);
      }
      *piVar2 = iVar1;
      iVar1 = *piVar2;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 0x14) = iVar1;
      if (iVar1 < 0) {
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 8) + -1;
      }
      piVar2 = (int *)(*(int *)(param_1 + 0x14) * 4 + *(int *)(param_1 + 0x18));
      *(int *)(param_1 + 0x1ad6) = *piVar2;
      iVar1 = *piVar2;
    }
    iVar1 = FUN_0001b73c(param_1,iVar1);
    if (iVar1 != 0) {
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0x30) = 1;
    }
  }
  return;
}



/* 0001d72c FUN_0001d72c */

/* Boundary evidence: original MIPS .pdata 0001d72c..0001d8cf. Semantic name remains unreviewed. */

void FUN_0001d72c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x1af0) == 1) {
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),1);
    uVar2 = FUN_00011908();
    FUN_00011cac(uVar2);
    uVar2 = FUN_00011908();
    iVar3 = FUN_00011838(uVar2);
    uVar2 = FUN_00011908();
    iVar1 = FUN_000117b4(uVar2);
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar1 = iVar1 + 3;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x1c) * 3 + iVar1;
    }
    if (iVar3 < iVar1) {
      uVar2 = FUN_00011908();
      FUN_000116a0(uVar2,iVar3);
      FUN_00019a38(param_1,iVar3);
      FUN_0001b518(param_1);
      FUN_0001d080(param_1);
      *(undefined4 *)(param_1 + 0x1c) = 0;
      FUN_0001d108(param_1);
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x1af0) != 2) {
      FUN_0001d080(param_1);
      return;
    }
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),1);
    uVar2 = FUN_00011908();
    FUN_00011cac(uVar2);
    uVar2 = FUN_00011908();
    iVar1 = FUN_000117b4(uVar2);
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar1 = iVar1 + -3;
    }
    else {
      iVar1 = iVar1 + *(int *)(param_1 + 0x1c) * -3;
    }
    if (iVar1 < 0) {
      iVar1 = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  uVar2 = FUN_00011908();
  FUN_000116a0(uVar2,iVar1);
  FUN_00019a38(param_1,iVar1);
  FUN_0001b518(param_1);
  return;
}



/* 0001d8d0 FUN_0001d8d0 */

/* Boundary evidence: original MIPS .pdata 0001d8d0..0001d94f. Semantic name remains unreviewed. */

void FUN_0001d8d0(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(&DAT_00099520 + param_1) = 0;
  memset((void *)(param_1 + 0x1b14),0,0x977fc);
  memset(&DAT_00099310 + param_1,0,4);
  memset(&DAT_00099314 + param_1,0,0x20a);
  FUN_0001947c(param_1 + 0x10);
  return;
}



/* 0001d950 FUN_0001d950 */

/* Boundary evidence: original MIPS .pdata 0001d950..0001d96b. Semantic name remains unreviewed. */

void FUN_0001d950(int param_1)

{
  FUN_0001c968(param_1 + 0x10);
  return;
}



/* 0001d96c FUN_0001d96c */

/* Boundary evidence: original MIPS .pdata 0001d96c..0001d987. Semantic name remains unreviewed. */

void FUN_0001d96c(int param_1)

{
  FUN_0001d020(param_1 + 0x10);
  return;
}



/* 0001d988 FUN_0001d988 */

/* Boundary evidence: original MIPS .pdata 0001d988..0001d9a3. Semantic name remains unreviewed. */

void FUN_0001d988(int param_1)

{
  FUN_0001950c(param_1 + 0x10);
  return;
}



/* 0001d9a4 FUN_0001d9a4 */

undefined4 FUN_0001d9a4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1af2);
}



/* 0001d9b4 FUN_0001d9b4 */

undefined4 FUN_0001d9b4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1b00);
}



/* 0001d9bc FUN_0001d9bc */

undefined4 FUN_0001d9bc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1ae6);
}



/* 0001d9cc FUN_0001d9cc */

/* Boundary evidence: original MIPS .pdata 0001d9cc..0001d9ef. Semantic name remains unreviewed. */

void FUN_0001d9cc(int param_1)

{
  FUN_0001c9a8(param_1 + 0x10);
  return;
}



/* 0001d9f0 FUN_0001d9f0 */

/* Boundary evidence: original MIPS .pdata 0001d9f0..0001da0b. Semantic name remains unreviewed. */

void FUN_0001d9f0(int param_1)

{
  FUN_0001c878(param_1 + 0x10);
  return;
}



/* 0001da0c FUN_0001da0c */

/* Boundary evidence: original MIPS .pdata 0001da0c..0001da27. Semantic name remains unreviewed. */

void FUN_0001da0c(int param_1)

{
  FUN_0001d620(param_1 + 0x10);
  return;
}



/* 0001da28 FUN_0001da28 */

/* Boundary evidence: original MIPS .pdata 0001da28..0001da43. Semantic name remains unreviewed. */

void FUN_0001da28(int param_1)

{
  FUN_0001b294(param_1 + 0x10);
  return;
}



/* 0001da44 FUN_0001da44 */

/* Boundary evidence: original MIPS .pdata 0001da44..0001da5f. Semantic name remains unreviewed. */

void FUN_0001da44(int param_1)

{
  FUN_0001c7c8(param_1 + 0x10);
  return;
}



/* 0001da60 FUN_0001da60 */

/* Boundary evidence: original MIPS .pdata 0001da60..0001da7b. Semantic name remains unreviewed. */

void FUN_0001da60(int param_1)

{
  FUN_0001ced8(param_1 + 0x10);
  return;
}



/* 0001da7c FUN_0001da7c */

/* Boundary evidence: original MIPS .pdata 0001da7c..0001da97. Semantic name remains unreviewed. */

void FUN_0001da7c(int param_1)

{
  FUN_00019a38(param_1 + 0x10);
  return;
}



/* 0001da98 FUN_0001da98 */

/* Boundary evidence: original MIPS .pdata 0001da98..0001dab3. Semantic name remains unreviewed. */

void FUN_0001da98(int param_1)

{
  FUN_0001b67c(param_1 + 0x10);
  return;
}



/* 0001dab4 FUN_0001dab4 */

/* Boundary evidence: original MIPS .pdata 0001dab4..0001dacf. Semantic name remains unreviewed. */

void FUN_0001dab4(int param_1)

{
  FUN_00019d20(param_1 + 0x10);
  return;
}



/* 0001dad0 FUN_0001dad0 */

/* Boundary evidence: original MIPS .pdata 0001dad0..0001daeb. Semantic name remains unreviewed. */

void FUN_0001dad0(int param_1)

{
  FUN_00019ab8(param_1 + 0x10);
  return;
}



/* 0001daec FUN_0001daec */

/* Boundary evidence: original MIPS .pdata 0001daec..0001db07. Semantic name remains unreviewed. */

void FUN_0001daec(int param_1)

{
  FUN_00019990(param_1 + 0x10);
  return;
}



/* 0001db08 FUN_0001db08 */

/* Boundary evidence: original MIPS .pdata 0001db08..0001db23. Semantic name remains unreviewed. */

void FUN_0001db08(int param_1)

{
  FUN_0001d108(param_1 + 0x10);
  return;
}



/* 0001db24 FUN_0001db24 */

/* Boundary evidence: original MIPS .pdata 0001db24..0001db3f. Semantic name remains unreviewed. */

void FUN_0001db24(int param_1)

{
  FUN_0001b4f8(param_1 + 0x10);
  return;
}



/* 0001db40 FUN_0001db40 */

/* Boundary evidence: original MIPS .pdata 0001db40..0001db5b. Semantic name remains unreviewed. */

void FUN_0001db40(int param_1)

{
  FUN_0001d080(param_1 + 0x10);
  return;
}



/* 0001db5c FUN_0001db5c */

/* Boundary evidence: original MIPS .pdata 0001db5c..0001e0cf. Semantic name remains unreviewed. */

undefined4 FUN_0001db5c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  wchar_t *_Str;
  int iVar9;
  size_t _Count;
  wchar_t *_Dest;
  int *piVar10;
  int local_258;
  int local_254;
  wchar_t local_238;
  undefined1 auStack_236 [518];
  undefined4 local_30;
  
  local_30 = DAT_0002f964;
  iVar2 = FUN_00023424();
  iVar8 = param_2;
  if (param_2 < 0) {
    iVar8 = 0;
  }
  iVar8 = iVar8 * 0x220 + *(int *)(iVar2 + 0x58);
  if (iVar8 != -0x284abc) {
    iVar6 = (int)*(short *)(&DAT_00284cd0 + iVar8);
    local_254 = (int)*(short *)(&DAT_00284cce + iVar8);
    memset((void *)(param_1 + 0x1b14),0,0x977fc);
    FUN_000235a8(5,1,L"%S Line %d nRootIdx : %d","CUSBMgr::getUSBFile",0x203,param_2);
    iVar2 = FUN_00023424();
    iVar2 = FUN_000124e8(*(int *)(iVar2 + 0x58) + 8,0);
    if (iVar2 != 0) {
      *(int *)(&DAT_0009930c + param_1) = param_2;
      iVar3 = FUN_00023424();
      *(bool *)(param_1 + 0x1b18) = *(int *)(&DAT_0028489c + *(int *)(iVar3 + 0x58)) == 0;
      iVar3 = FUN_00023424();
      FUN_00013634(*(undefined4 *)(iVar3 + 0x58),param_2,param_1 + 0x1b24);
      if (0 < *(short *)(&DAT_00284ccc + iVar8)) {
        sVar1 = *(short *)(&DAT_00284cd6 + iVar8);
        iVar3 = FUN_00023424();
        iVar3 = FUN_000140fc(*(undefined4 *)(iVar3 + 0x58),(int)sVar1);
        if (iVar3 < 3) {
          iVar3 = (int)*(short *)(&DAT_00284cd6 + iVar8);
          iVar8 = FUN_00023424();
          if (iVar3 < 0) {
            iVar3 = 0;
          }
          iVar8 = iVar3 * 0x220 + *(int *)(iVar8 + 0x58);
          if (iVar8 == -0x284abc) goto LAB_0001dbd8;
          iVar3 = 0;
          if (0 < *(short *)(&DAT_00284ccc + iVar8)) {
            do {
              iVar9 = *(short *)(&DAT_00284cca + iVar8) + iVar3;
              iVar4 = FUN_00023424();
              if (iVar9 < 0) {
                iVar9 = 0;
              }
              iVar4 = iVar9 * 0x220 + *(int *)(iVar4 + 0x58);
              if ((iVar4 != -0x284abc) && (0 < *(int *)(&DAT_00284cd8 + iVar4))) {
                *(undefined1 *)(param_1 + 0x1b19) = 1;
                break;
              }
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(short *)(&DAT_00284ccc + iVar8));
          }
        }
      }
      iVar8 = 0;
      if (0 < iVar6) {
        iVar3 = local_254 * 0x108;
        _Dest = (wchar_t *)(param_1 + 0x1d2c);
        _Str = (wchar_t *)(local_254 * 0x210 + iVar2);
        piVar10 = (int *)(&DAT_000944ec + param_1);
        local_258 = iVar6;
        do {
          if (*_Str == L'\\') {
            local_238 = L'\0';
            memset(auStack_236,0,0x206);
            _Count = 0;
            sVar5 = wcslen(_Str);
            if (0 < (int)sVar5) {
              psVar7 = (short *)((iVar3 + sVar5) * 2 + iVar2);
              do {
                if (*psVar7 == 0x5c) {
                  wcsncpy(&local_238,(wchar_t *)((iVar3 + sVar5 + 1) * 2 + iVar2),_Count);
                  break;
                }
                _Count = _Count + 1;
                sVar5 = sVar5 - 1;
                psVar7 = psVar7 + -1;
              } while (0 < (int)sVar5);
            }
            FUN_000235a8(5,0,L"%S %d setFile Name : %s === 22 ====","CUSBMgr::getUSBFile",599,
                         &local_238);
            wcsncpy(_Dest,&local_238,0x3b);
            *(undefined1 *)(_Dest + 0x3b) = 0;
            *(undefined1 *)((int)_Dest + 0x77) = 0;
            FUN_000235a8(5,0,L"%S %d tchTitle Name : %s === 33 ===","CUSBMgr::getUSBFile",0x25b,
                         _Dest);
          }
          else {
            memcpy(_Dest,_Str,0x78);
            *(undefined1 *)(_Dest + 0x3b) = 0;
            *(undefined1 *)((int)_Dest + 0x77) = 0;
          }
          *piVar10 = local_254;
          if (*(int *)(_Str + 0x105) == 0) {
            *(undefined4 *)(param_1 + 0x1b20) = 1;
          }
          else {
            *(undefined4 *)(param_1 + 0x1b20) = 2;
          }
          local_258 = local_258 + -1;
          local_254 = local_254 + 1;
          iVar3 = iVar3 + 0x108;
          _Str = _Str + 0x108;
          piVar10 = piVar10 + 1;
          _Dest = _Dest + 0x3c;
          iVar8 = iVar6;
        } while (local_258 != 0);
      }
      iVar2 = 0;
      *(int *)(param_1 + 0x1b14) = iVar8;
      if (0 < iVar8) {
        piVar10 = (int *)(&DAT_000944ec + param_1);
        do {
          if (*piVar10 == *(int *)(param_1 + 0x1ae6)) {
            *(char *)(param_1 + 0x1b1e) = (char)iVar2;
            *(char *)(param_1 + 0x1b1f) = (char)((uint)iVar2 >> 8);
            goto LAB_0001e00c;
          }
          iVar2 = iVar2 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar2 < iVar8);
      }
      *(undefined1 *)(param_1 + 0x1b1e) = 0xff;
      *(undefined1 *)(param_1 + 0x1b1f) = 0xff;
LAB_0001e00c:
      iVar8 = FUN_00023424();
      if (*(int *)(iVar8 + 0x54) != 0) {
        iVar8 = FUN_00023424();
        FUN_000241e8(*(undefined4 *)(iVar8 + 0x54),(int *)(param_1 + 0x1b14),0,&DAT_000977fc);
      }
      FUN_000235a8(5,0,L"%S  line %d  nRootIdx : %d","CUSBMgr::getUSBFile",0x288,param_2);
      FUN_0002381c(5,0x15,0x69,0,0);
      FUN_00025660(local_30);
      return 1;
    }
  }
LAB_0001dbd8:
  FUN_00025660(local_30);
  return 0;
}



/* 0001e0d0 FUN_0001e0d0 */

/* Boundary evidence: original MIPS .pdata 0001e0d0..0001e32f. Semantic name remains unreviewed. */

undefined4 FUN_0001e0d0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  int iVar5;
  int iVar6;
  undefined *_Dst;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  
  iVar2 = FUN_00023424();
  iVar5 = param_2;
  if (param_2 < 0) {
    iVar5 = 0;
  }
  iVar5 = iVar5 * 0x220 + *(int *)(iVar2 + 0x58);
  if (iVar5 != -0x284abc) {
    _Dst = &DAT_00099314 + param_1;
    memset(_Dst,0,0x20a);
    iVar2 = FUN_00023424();
    iVar2 = FUN_000124e8(*(int *)(iVar2 + 0x58) + 8,0);
    if (iVar2 != 0) {
      iVar2 = FUN_00023424();
      *_Dst = *(int *)(&DAT_0028489c + *(int *)(iVar2 + 0x58)) == 0;
      iVar2 = FUN_00023424();
      FUN_00013634(*(undefined4 *)(iVar2 + 0x58),param_2,param_1 + 0x99316);
      if (0 < *(short *)(&DAT_00284ccc + iVar5)) {
        sVar1 = *(short *)(&DAT_00284cd6 + iVar5);
        iVar2 = FUN_00023424();
        iVar2 = FUN_000140fc(*(undefined4 *)(iVar2 + 0x58),(int)sVar1);
        if (iVar2 < 3) {
          iVar2 = (int)*(short *)(&DAT_00284cd6 + iVar5);
          iVar5 = FUN_00023424();
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          iVar5 = iVar2 * 0x220 + *(int *)(iVar5 + 0x58);
          if (iVar5 == -0x284abc) {
            return 0;
          }
          iVar2 = 0;
          if (0 < *(short *)(&DAT_00284ccc + iVar5)) {
            do {
              iVar6 = *(short *)(&DAT_00284cca + iVar5) + iVar2;
              iVar3 = FUN_00023424();
              if (iVar6 < 0) {
                iVar6 = 0;
              }
              iVar3 = iVar6 * 0x220 + *(int *)(iVar3 + 0x58);
              if ((iVar3 != -0x284abc) && (0 < *(int *)(&DAT_00284cd8 + iVar3))) {
                (&DAT_00099315)[param_1] = 1;
                break;
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(short *)(&DAT_00284ccc + iVar5));
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



/* 0001e330 FUN_0001e330 */

/* Boundary evidence: original MIPS .pdata 0001e330..0001e417. Semantic name remains unreviewed. */

undefined4 FUN_0001e330(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_1 + 0x1ae6);
  uVar1 = FUN_000144b8();
  iVar2 = FUN_00012b84(uVar1,uVar4);
  iVar3 = FUN_000144b8();
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar2 = iVar2 * 0x220 + iVar3 + 0x284abc;
  if (iVar2 != 0) {
    do {
      if (param_2 == *(short *)(iVar2 + 0x21a)) {
        return 1;
      }
      iVar2 = (int)*(short *)(iVar2 + 0x20c);
      iVar3 = FUN_000144b8();
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      iVar3 = iVar2 * 0x220 + iVar3;
      iVar2 = iVar3 + 0x284abc;
    } while ((iVar2 != 0) && (-1 < *(short *)(&DAT_00284cc8 + iVar3)));
  }
  return 0;
}



/* 0001e418 FUN_0001e418 */

/* Boundary evidence: original MIPS .pdata 0001e418..0001e47b. Semantic name remains unreviewed. */

int FUN_0001e418(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (4999 < param_2)) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_00023424();
    iVar1 = param_2 * 0x220 + *(int *)(iVar1 + 0x58) + 0x284abc;
  }
  return iVar1;
}



/* 0001e47c FUN_0001e47c */

/* Boundary evidence: original MIPS .pdata 0001e47c..0001e53b. Semantic name remains unreviewed. */

void FUN_0001e47c(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar2 = FUN_00023424();
    uVar3 = FUN_00012b84(*(undefined4 *)(iVar2 + 0x58),param_2);
    iVar2 = FUN_0001e418(param_1,uVar3);
    if (iVar2 != 0) {
      sVar1 = *(short *)(iVar2 + 0x210);
      iVar4 = 0;
      if (0 < sVar1) {
        do {
          FUN_0001e418(param_1,*(short *)(iVar2 + 0x20e) + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < sVar1);
      }
    }
    FUN_0001db5c(param_1,uVar3);
  }
  return;
}



/* 0001e53c FUN_0001e53c */

/* Boundary evidence: original MIPS .pdata 0001e53c..0001e5fb. Semantic name remains unreviewed. */

void FUN_0001e53c(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < 5000)) {
    iVar2 = FUN_00023424();
    uVar3 = FUN_00012b84(*(undefined4 *)(iVar2 + 0x58),param_2);
    iVar2 = FUN_0001e418(param_1,uVar3);
    if (iVar2 != 0) {
      sVar1 = *(short *)(iVar2 + 0x210);
      iVar4 = 0;
      if (0 < sVar1) {
        do {
          FUN_0001e418(param_1,*(short *)(iVar2 + 0x20e) + iVar4);
          iVar4 = iVar4 + 1;
        } while (iVar4 < sVar1);
      }
    }
    FUN_0001e0d0(param_1,uVar3);
  }
  return;
}



/* 0001e5fc FUN_0001e5fc */

/* Boundary evidence: original MIPS .pdata 0001e5fc..0001e72b. Semantic name remains unreviewed. */

int FUN_0001e5fc(undefined4 param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  wchar_t *_Str2;
  undefined4 uVar3;
  int iVar4;
  wchar_t local_228;
  undefined1 auStack_226 [518];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    iVar1 = FUN_00023424();
    iVar1 = FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = FUN_00023424();
        _Str2 = (wchar_t *)FUN_00012ba0(*(undefined4 *)(iVar2 + 0x58),iVar4);
        if ((_Str2 != (wchar_t *)0x0) && (iVar2 = wcscmp(param_2,_Str2), iVar2 == 0)) {
          local_228 = L'\0';
          memset(auStack_226,0,0x206);
          iVar2 = FUN_00023424();
          uVar3 = FUN_00012b84(*(undefined4 *)(iVar2 + 0x58),iVar4);
          iVar2 = FUN_00023424();
          FUN_00013634(*(undefined4 *)(iVar2 + 0x58),uVar3,&local_228);
          iVar2 = wcscmp(param_3,&local_228);
          if (iVar2 == 0) {
            FUN_00025660(local_20);
            return iVar4;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  FUN_00025660(local_20);
  return -1;
}



/* 0001e72c FUN_0001e72c */

/* Boundary evidence: original MIPS .pdata 0001e72c..0001e7f7. Semantic name remains unreviewed. */

void FUN_0001e72c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  FUN_000235a8(5,2,
               L"%S  getGlobalVal()->m_nAttachedUSBNum %d saveResumeData USB_RESUME_MUSIC_ACC_OFF_FILE"
               ,"CUSBMgr::factorySetting",*(undefined4 *)(iVar1 + 0x48));
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x48) == 0) {
    param_1 = param_1 + 0x10;
    FUN_0001c21c(param_1,L"\\Storage Card2\\USBMusicResume.dat");
    FUN_0001b67c(param_1,0,0);
    FUN_00019ab8(param_1,0);
    FUN_0001c538(param_1,L"\\Storage Card2\\USBMusicResume.dat");
  }
  else {
    FUN_0001b67c(param_1 + 0x10,0,0);
    FUN_00019ab8(param_1 + 0x10,0);
  }
  return;
}



/* 0001e7f8 FUN_0001e7f8 */

/* Boundary evidence: original MIPS .pdata 0001e7f8..0001e81f. Semantic name remains unreviewed. */

void FUN_0001e7f8(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),4);
  return;
}



/* 0001e820 FUN_0001e820 */

/* Boundary evidence: original MIPS .pdata 0001e820..0001ea0f. Semantic name remains unreviewed. */

void FUN_0001e820(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_18 [2];
  
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x20) == 0) {
    iVar1 = FUN_00023424();
    KillTimer(*(HWND *)(iVar1 + 0x4c),4);
    FUN_000235a8(5,0,L"%S  line %d resume play Start","CUSBMgr::procAttachTimer",0x4f7);
    param_1 = param_1 + 0x10;
    iVar1 = FUN_0001c21c(param_1,L"\\Storage Card2\\USBMusicResume.dat");
    if (iVar1 != 0) {
      FUN_0001b0b4(param_1);
      uVar2 = FUN_0001bdec(param_1,1);
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 8) = 1;
      iVar1 = FUN_00023424();
      if (*(int *)(iVar1 + 0xc) != 0) {
        memset(local_18,0,4);
        local_18[0] = local_18[0] & 0xfff01f13 | 0x101013;
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x20) == 0) {
          FUN_0002381c(5,1,9,4,local_18);
        }
        FUN_000235a8(5,0,L"%S  line %d resume play!!!!!!!!","CUSBMgr::procAttachTimer",0x50c);
      }
    }
    iVar1 = FUN_00023424();
    if (*(int *)(iVar1 + 0x20) == 0) {
      iVar1 = FUN_00023424();
      FUN_00022e58(iVar1 + 0x60);
      iVar1 = FUN_00023424();
      FUN_00022ec0(iVar1 + 0x60);
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0x48) = 1;
      iVar1 = FUN_00023424();
      FUN_0001264c(*(undefined4 *)(iVar1 + 0x58));
      iVar1 = FUN_00023424();
      uVar2 = FUN_000126e0(*(undefined4 *)(iVar1 + 0x58));
      iVar1 = FUN_00023424();
      uVar3 = FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
      FUN_000235a8(5,0,L"%S  line %d, media: %d, Dir: %d","CUSBMgr::procAttachTimer",0x51a,uVar3,
                   uVar2);
      iVar1 = FUN_00023424();
      FUN_00023134(iVar1 + 0x60);
    }
  }
  return;
}



/* 0001ea10 FUN_0001ea10 */

/* Boundary evidence: original MIPS .pdata 0001ea10..0001ea3f. Semantic name remains unreviewed. */

void FUN_0001ea10(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),7);
  return;
}



/* 0001ea40 FUN_0001ea40 */

void FUN_0001ea40(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(&DAT_00099310 + param_1) = *param_2;
  }
  return;
}



/* 0001ea64 FUN_0001ea64 */

undefined * FUN_0001ea64(int param_1)

{
  return &DAT_00099310 + param_1;
}



/* 0001ea74 FUN_0001ea74 */

/* Boundary evidence: original MIPS .pdata 0001ea74..0001ea9b. Semantic name remains unreviewed. */

void FUN_0001ea74(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),8);
  return;
}



/* 0001ea9c FUN_0001ea9c */

/* Boundary evidence: original MIPS .pdata 0001ea9c..0001eab7. Semantic name remains unreviewed. */

void FUN_0001ea9c(int param_1)

{
  FUN_0001b518(param_1 + 0x10);
  return;
}



/* 0001eab8 FUN_0001eab8 */

/* Boundary evidence: original MIPS .pdata 0001eab8..0001ead3. Semantic name remains unreviewed. */

void FUN_0001eab8(int param_1)

{
  FUN_0001b5d0(param_1 + 0x10);
  return;
}



/* 0001ead4 FUN_0001ead4 */

/* Boundary evidence: original MIPS .pdata 0001ead4..0001eaff. Semantic name remains unreviewed. */

void FUN_0001ead4(int param_1)

{
  memset(&DAT_00099310 + param_1,0,4);
  return;
}



/* 0001eb00 FUN_0001eb00 */

/* Boundary evidence: original MIPS .pdata 0001eb00..0001eb43. Semantic name remains unreviewed. */

void FUN_0001eb00(int param_1)

{
  FUN_0001c9a8(param_1 + 0x10,*(undefined4 *)(param_1 + 0x1ae6),3,*(int *)(param_1 + 0xc9c) != 0,1);
  return;
}



/* 0001eb44 FUN_0001eb44 */

/* Boundary evidence: original MIPS .pdata 0001eb44..0001eba3. Semantic name remains unreviewed. */

void FUN_0001eb44(int param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 8) = DVar1;
  *(undefined4 *)(&DAT_00099524 + param_1) = 0;
  *(undefined4 *)(&DAT_00099528 + param_1) = 0;
  *(undefined4 *)(&DAT_0009952c + param_1) = 0;
  return;
}



/* 0001eba4 FUN_0001eba4 */

/* Boundary evidence: original MIPS .pdata 0001eba4..0001ebbf. Semantic name remains unreviewed. */

void FUN_0001eba4(int param_1)

{
  FUN_0001b170(param_1 + 0x10);
  return;
}



/* 0001ebc0 FUN_0001ebc0 */

/* Boundary evidence: original MIPS .pdata 0001ebc0..0001ebdb. Semantic name remains unreviewed. */

void FUN_0001ebc0(int param_1)

{
  FUN_0001b0e8(param_1 + 0x10);
  return;
}



/* 0001ebdc FUN_0001ebdc */

/* Boundary evidence: original MIPS .pdata 0001ebdc..0001ec3f. Semantic name remains unreviewed. */

undefined4 * FUN_0001ebdc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002a4b4;
  FUN_0001b1f4(param_1 + 4);
  param_1[3] = 0;
  FUN_0001eb44(param_1);
  FUN_0001d8d0(param_1);
  return param_1;
}



/* 0001ec40 Unwind@0001ec40 */

/* Boundary evidence: original MIPS .pdata 0001ec40..0001ec73. Semantic name remains unreviewed. */

void Unwind_0001ec40(void)

{
  int *in_v0;
  
  FUN_00019434(*in_v0 + 0x10);
  return;
}



/* 0001ec74 FUN_0001ec74 */

/* Boundary evidence: original MIPS .pdata 0001ec74..0001eccb. Semantic name remains unreviewed. */

undefined4 * FUN_0001ec74(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002a4b4;
  FUN_00019434(param_1 + 4);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001eccc FUN_0001eccc */

/* Boundary evidence: original MIPS .pdata 0001eccc..0001ed3f. Semantic name remains unreviewed. */

void FUN_0001eccc(void)

{
  int iVar1;
  
  if (DAT_006b83ac == 0) {
    iVar1 = __2_YAPAXI_Z(&DAT_00099530);
    if (iVar1 == 0) {
      DAT_006b83ac = 0;
    }
    else {
      DAT_006b83ac = FUN_0001ebdc(iVar1);
    }
  }
  return;
}



/* 0001ed40 Unwind@0001ed40 */

/* Boundary evidence: original MIPS .pdata 0001ed40..0001ed6f. Semantic name remains unreviewed. */

void Unwind_0001ed40(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001ed70 FUN_0001ed70 */

/* Boundary evidence: original MIPS .pdata 0001ed70..0001f0ab. Semantic name remains unreviewed. */

void FUN_0001ed70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint local_440 [2];
  wchar_t local_438;
  undefined1 auStack_436 [1038];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  FUN_000235a8(5,1,L"%S ----------------------Search Start---------------------------",
               "CUSBMgr::searchThreadFunc");
  *(undefined4 *)(param_1 + 4) = 1;
  local_438 = L'\0';
  memset(auStack_436,0,0x40e);
  wcscpy(&local_438,L"MD");
  iVar1 = FUN_00023424();
  uVar4 = 0xffffffff;
  FUN_00012a24(*(undefined4 *)(iVar1 + 0x58),0,0,0xffffffff,&local_438,0);
  iVar1 = FUN_00023424();
  FUN_00014240(*(undefined4 *)(iVar1 + 0x58));
  iVar1 = FUN_00023424();
  *(undefined4 *)(&DAT_002848a0 + *(int *)(iVar1 + 0x58)) = 0;
  iVar1 = FUN_00023424();
  FUN_00014d68(*(undefined4 *)(iVar1 + 0x58),&local_438,0,0);
  iVar1 = FUN_00023424();
  FUN_00014284(*(undefined4 *)(iVar1 + 0x58));
  iVar1 = FUN_00023424();
  FUN_00015190(*(undefined4 *)(iVar1 + 0x58));
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x48) == 0) goto LAB_0001f080;
  iVar1 = FUN_00023424();
  iVar1 = FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
  if (iVar1 < 1) {
LAB_0001eec4:
    if (param_2 != 0) {
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0x48) = 0;
      memset(local_440,0,4);
      local_440[0] = local_440[0] & 0xffe01f13 | 0x1013;
      iVar1 = FUN_00023424();
      if (*(int *)(iVar1 + 0x20) == 0) {
        FUN_0002381c(5,1,9,4,local_440);
      }
      FUN_000235a8(5,1,L"%S empty media file","CUSBMgr::searchThreadFunc");
      goto LAB_0001f080;
    }
  }
  else {
    iVar1 = FUN_00023424();
    if (*(int *)(iVar1 + 0xc) == 0) goto LAB_0001eec4;
  }
  iVar1 = FUN_00023424();
  iVar1 = FUN_000126e0(*(undefined4 *)(iVar1 + 0x58));
  iVar2 = FUN_00023424();
  uVar3 = FUN_000126f4(*(undefined4 *)(iVar2 + 0x58));
  FUN_000235a8(5,0,L"%S  line %d, media: %d, Dir: %d","CUSBMgr::searchThreadFunc",0xf0,uVar3,iVar1);
  iVar5 = param_1 + 0x18de;
  iVar2 = param_1 + 0x16d6;
  if ((iVar5 != 0) && (iVar2 != 0)) {
    iVar1 = iVar2;
    FUN_000235a8(5,0,L"%S  line %d %s / %s","CUSBMgr::searchThreadFunc",0xfe,iVar5,iVar2);
    uVar4 = FUN_0001e5fc(param_1,iVar5,iVar2);
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa4) = uVar4;
  }
  *(undefined4 *)(param_1 + 0x1ae6) = uVar4;
  FUN_000235a8(5,0,L"%S  line %d / ResumePlay match index : %d","CUSBMgr::searchThreadFunc",0x105,
               uVar4,iVar1);
  FUN_0001afac(param_1 + 0x10);
  if (param_2 != 0) {
    iVar1 = FUN_00023424();
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  FUN_00023a50(0x15,5,0x7d,0,0);
  FUN_0002381c(5,0x15,0x6a,0,0);
  FUN_000235a8(5,1,L"%S ----------------------------IDM_MUSB_INDEXING_COMPLETE--------------------",
               "CUSBMgr::searchThreadFunc");
  *(undefined4 *)(param_1 + 4) = 0;
LAB_0001f080:
  FUN_00025660(local_28);
  return;
}



/* 0001f0ac FUN_0001f0ac */

/* Boundary evidence: original MIPS .pdata 0001f0ac..0001f207. Semantic name remains unreviewed. */

void FUN_0001f0ac(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar3 = (int *)(param_1 + 0x1b14);
  if (*(int *)(param_1 + 0x1b20) == 0) {
    iVar4 = *piVar3 + -1;
    if (-1 < iVar4) {
      puVar5 = (undefined4 *)((*piVar3 + 0x2513a) * 4 + param_1);
      do {
        iVar1 = FUN_0001e330(param_1,*puVar5);
        if (iVar1 != 0) {
          *(char *)(param_1 + 0x1b1e) = (char)iVar4;
          *(char *)(param_1 + 0x1b1f) = (char)((uint)iVar4 >> 8);
LAB_0001f188:
          iVar4 = FUN_00023424();
          if (*(int *)(iVar4 + 0x54) == 0) {
            return;
          }
          goto LAB_0001f138;
        }
        iVar4 = iVar4 + -1;
        puVar5 = puVar5 + -1;
      } while (-1 < iVar4);
    }
  }
  else {
    iVar4 = 0;
    if (0 < *piVar3) {
      piVar2 = (int *)(&DAT_000944ec + param_1);
      do {
        if (*piVar2 == param_2) {
          *(char *)(param_1 + 0x1b1e) = (char)iVar4;
          *(char *)(param_1 + 0x1b1f) = (char)((uint)iVar4 >> 8);
          goto LAB_0001f188;
        }
        iVar4 = iVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar4 < *piVar3);
    }
  }
  *(undefined1 *)(param_1 + 0x1b1e) = 0xff;
  *(undefined1 *)(param_1 + 0x1b1f) = 0xff;
LAB_0001f138:
  iVar4 = FUN_00023424();
  FUN_000241e8(*(undefined4 *)(iVar4 + 0x54),piVar3,0,&DAT_000977fc);
  return;
}



/* 0001f208 FUN_0001f208 */

/* Boundary evidence: original MIPS .pdata 0001f208..0001f53f. Semantic name remains unreviewed. */

undefined4 FUN_0001f208(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  wchar_t *_Dest;
  int iVar11;
  int *piVar12;
  
  iVar4 = FUN_00023424();
  iVar9 = param_2;
  if (param_2 < 0) {
    iVar9 = 0;
  }
  piVar12 = (int *)(param_1 + 0x1b14);
  sVar1 = *(short *)(&DAT_00284cd0 + iVar9 * 0x220 + *(int *)(iVar4 + 0x58));
  memset(piVar12,0,0x977fc);
  FUN_000235a8(5,1,L"%S nRootIdx : %d","CUSBMgr::getUSBFolder",param_2);
  iVar9 = FUN_00023424();
  iVar9 = FUN_00014f9c(*(undefined4 *)(iVar9 + 0x58),param_2,piVar12);
  *(int *)(&DAT_0009930c + param_1) = param_2;
  *(undefined4 *)(param_1 + 0x1b20) = 0;
  *(bool *)(param_1 + 0x1b18) = param_2 == 0;
  iVar4 = FUN_00023424();
  FUN_00013634(*(undefined4 *)(iVar4 + 0x58),param_2,param_1 + 0x1b24);
  if ((0 < sVar1) && (0 < iVar9)) {
    _Dest = (wchar_t *)(param_1 + 0x1d2c);
    FUN_000235a8(5,0,L"%S %s","CUSBMgr::getUSBFolder",_Dest);
    memmove((void *)(param_1 + 0x1da4),_Dest,0x92748);
    memmove(&DAT_000944f0 + param_1,&DAT_000944ec + param_1,0x4e1c);
    wcscpy(_Dest,L"Root");
    *(int *)(&DAT_000944ec + param_1) = param_2;
    *(undefined1 *)(param_1 + 0x1b1a) = 1;
    iVar9 = iVar9 + 1;
  }
  FUN_000235a8(5,0,L"%S nValideListCount : %d","CUSBMgr::getUSBFolder",iVar9);
  uVar10 = *(undefined4 *)(param_1 + 0x1ae6);
  bVar3 = false;
  *piVar12 = iVar9;
  uVar5 = FUN_000144b8();
  iVar6 = FUN_00012b84(uVar5,uVar10);
  iVar4 = FUN_00023424();
  iVar7 = FUN_000140fc(*(undefined4 *)(iVar4 + 0x58),iVar6);
  bVar2 = false;
  iVar4 = 0;
  iVar11 = 0;
  if (0 < iVar9) {
    piVar12 = (int *)(&DAT_000944ec + param_1);
    do {
      iVar8 = FUN_0001e330(param_1,*piVar12);
      if (iVar8 != 0) {
        if (iVar6 == *piVar12) {
          bVar2 = true;
          iVar4 = iVar11;
        }
        if (bVar2) {
          *(char *)(param_1 + 0x1b1e) = (char)iVar4;
          *(char *)(param_1 + 0x1b1f) = (char)((uint)iVar4 >> 8);
        }
        else {
          *(char *)(param_1 + 0x1b1e) = (char)iVar11;
          *(char *)(param_1 + 0x1b1f) = (char)((uint)iVar11 >> 8);
        }
        bVar3 = true;
        if ((iVar7 < 3) && ((*(char *)(param_1 + 0x1b1a) == '\0' || (0 < iVar11))))
        goto LAB_0001f4c4;
      }
      iVar11 = iVar11 + 1;
      piVar12 = piVar12 + 1;
    } while (iVar11 < iVar9);
    if (bVar3) goto LAB_0001f4c4;
  }
  *(undefined1 *)(param_1 + 0x1b1e) = 0xff;
  *(undefined1 *)(param_1 + 0x1b1f) = 0xff;
LAB_0001f4c4:
  iVar9 = FUN_00023424();
  if (*(int *)(iVar9 + 0x50) != 0) {
    iVar9 = FUN_00023424();
    FUN_000241e8(*(undefined4 *)(iVar9 + 0x54),param_1 + 0x1b14,0,&DAT_000977fc);
  }
  FUN_0002381c(5,0x15,0x69,0,0);
  return 1;
}



/* 0001f540 FUN_0001f540 */

/* Boundary evidence: original MIPS .pdata 0001f540..0001f88b. Semantic name remains unreviewed. */

undefined4 FUN_0001f540(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x1b14) == 0) {
    pwVar4 = L"%S error there is any item in previous list";
  }
  else {
    if (-1 < param_2) {
      if (*(int *)(param_1 + 0x1b20) < 1) {
        if (4999 < param_2) {
          param_2 = 0;
        }
        iVar5 = *(int *)((param_2 + 0x2513b) * 4 + param_1);
        iVar1 = FUN_00023424();
        iVar1 = FUN_000140fc(*(undefined4 *)(iVar1 + 0x58),iVar5);
        if (((*(char *)(param_1 + 0x1b1a) == '\0') || (param_2 != 0)) && (iVar1 < 3)) {
          iVar2 = FUN_00023424();
          iVar1 = iVar5;
          if (iVar5 < 0) {
            iVar1 = 0;
          }
          if (0 < *(short *)(&DAT_00284ccc + iVar1 * 0x220 + *(int *)(iVar2 + 0x58))) {
            iVar2 = FUN_00023424();
            iVar1 = iVar5;
            if (iVar5 < 0) {
              iVar1 = 0;
            }
            iVar1 = iVar1 * 0x220 + *(int *)(iVar2 + 0x58);
            if (iVar1 == -0x284abc) {
              return 1;
            }
            iVar2 = 0;
            if (0 < *(short *)(&DAT_00284ccc + iVar1)) {
              do {
                iVar6 = *(short *)(&DAT_00284cca + iVar1) + iVar2;
                iVar3 = FUN_00023424();
                if (iVar6 < 0) {
                  iVar6 = 0;
                }
                iVar3 = iVar6 * 0x220 + *(int *)(iVar3 + 0x58);
                if ((iVar3 != -0x284abc) && (0 < *(int *)(&DAT_00284cd8 + iVar3))) {
                  FUN_0001f208(param_1,iVar5);
                  return 1;
                }
                iVar2 = iVar2 + 1;
              } while (iVar2 < *(short *)(&DAT_00284ccc + iVar1));
            }
          }
        }
        FUN_0001db5c(param_1,iVar5);
        return 0;
      }
      iVar5 = *(int *)(&DAT_0009930c + param_1);
      iVar1 = FUN_00023424();
      if (iVar5 < 0) {
        iVar5 = 0;
      }
      param_2 = *(short *)(&DAT_00284cce + iVar5 * 0x220 + *(int *)(iVar1 + 0x58)) + param_2;
      FUN_000235a8(5,3,L"%S Play index:%d","CUSBMgr::getUSBMediaItem",param_2);
      if (((*(int *)(param_1 + 0x1ae6) == param_2) && (*(int *)(param_1 + 0x1b10) < 1)) &&
         (*(int *)(param_1 + 0xca0) != 0)) {
        return 0;
      }
      FUN_0001c9a8(param_1 + 0x10,param_2,1,*(int *)(param_1 + 0xc9c) != 0,1);
      if (*(int *)(param_1 + 0x1aea) == 1) {
        return 0;
      }
      if (*(int *)(param_1 + 0x1aee) != 1) {
        return 0;
      }
      iVar1 = FUN_00023424();
      FUN_00022fd8(iVar1 + 0x60);
      iVar1 = FUN_00023424();
      FUN_00023110(iVar1 + 0x60);
      iVar1 = FUN_00023424();
      FUN_00022ec0(iVar1 + 0x60);
      FUN_00019d20(param_1 + 0x10,1);
      iVar1 = FUN_00023424();
      FUN_000230ec(iVar1 + 0x60);
      return 0;
    }
    pwVar4 = L"%S error iFileOffInList is less than zero";
  }
  FUN_000235a8(5,3,pwVar4,"CUSBMgr::getUSBMediaItem");
  return 0;
}



/* 0001f88c FUN_0001f88c */

/* Boundary evidence: original MIPS .pdata 0001f88c..0001fa27. Semantic name remains unreviewed. */

void FUN_0001f88c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char local_res4;
  
  FUN_000235a8(5,1,L"%S stCategory.nSelIdx:%d ","CUSBMgr::selectListItem",(param_2 << 8) >> 0x10);
  local_res4 = (char)param_2;
  FUN_000235a8(5,1,L"%S stCategory.nCat:%d ","CUSBMgr::selectListItem",(int)local_res4);
  memset((void *)(param_1 + 0x1b24),0,0x104);
  if (-1 < (param_2 << 8) >> 0x10) {
    FUN_0001f540(param_1);
    return;
  }
  if (*(int *)(param_1 + 0x1b20) == 0) {
LAB_0001f990:
    iVar1 = *(int *)(&DAT_0009930c + param_1);
  }
  else {
    iVar1 = FUN_00023424();
    iVar1 = FUN_000140fc(*(undefined4 *)(iVar1 + 0x58),*(int *)(&DAT_0009930c + param_1));
    if (2 < iVar1) goto LAB_0001f990;
    iVar1 = *(int *)(&DAT_0009930c + param_1);
    if (*(char *)(param_1 + 0x1b19) != '\0') goto LAB_0001f9d0;
  }
  iVar2 = FUN_000144b8();
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  iVar1 = (int)*(short *)(&DAT_00284cd2 + iVar1 * 0x220 + iVar2);
LAB_0001f9d0:
  FUN_000235a8(5,0,L"%S  line %d  iParentFolder : %d / m_stUsbList.nPID : %d",
               "CUSBMgr::selectListItem",0x455,iVar1,*(undefined4 *)(&DAT_0009930c + param_1));
  FUN_0001f208(param_1,iVar1);
  return;
}



/* 0001fa28 FUN_0001fa28 */

/* Boundary evidence: original MIPS .pdata 0001fa28..0001fa7f. Semantic name remains unreviewed. */

void FUN_0001fa28(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),7);
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xa8) = 1;
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),7,500,(TIMERPROC)0x0);
  return;
}



/* 0001fa80 FUN_0001fa80 */

/* Boundary evidence: original MIPS .pdata 0001fa80..0001fac3. Semantic name remains unreviewed. */

void FUN_0001fa80(void)

{
  int iVar1;
  
  iVar1 = FUN_00023424();
  KillTimer(*(HWND *)(iVar1 + 0x4c),8);
  iVar1 = FUN_00023424();
  SetTimer(*(HWND *)(iVar1 + 0x4c),8,300,(TIMERPROC)0x0);
  return;
}



/* 0001fac4 FUN_0001fac4 */

/* Boundary evidence: original MIPS .pdata 0001fac4..0002008b. Semantic name remains unreviewed. */

void FUN_0001fac4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_40 [2];
  undefined1 auStack_38 [24];
  
  iVar3 = 1;
  *(undefined4 *)(&DAT_00099520 + param_1) = 1;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0x48) = 1;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0xc) = 0;
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar1 = FUN_00023424();
  FUN_0001d8d0(*(undefined4 *)(iVar1 + 0x5c));
  iVar1 = FUN_00023424();
  FUN_0001264c(*(undefined4 *)(iVar1 + 0x58));
  Sleep(3000);
  iVar1 = FUN_00023424();
  iVar1 = FUN_00012efc(*(undefined4 *)(iVar1 + 0x58),&DAT_00027b78,auStack_38,0);
  if (iVar1 != 0) {
    if (param_2 == 0) {
      iVar1 = FUN_0001c21c(param_1 + 0x10,L"\\Storage Card2\\USBMusicResume.dat");
      if (iVar1 != 0) {
        iVar1 = FUN_00023424();
        FUN_0001b0b4(*(int *)(iVar1 + 0x5c) + 0x10);
        iVar1 = FUN_00023424();
        uVar2 = FUN_0001bdec(*(int *)(iVar1 + 0x5c) + 0x10,0);
        iVar1 = FUN_00023424();
        *(undefined4 *)(iVar1 + 0xc) = uVar2;
        iVar1 = FUN_00023424();
        *(undefined4 *)(iVar1 + 8) = 1;
        memset(local_40,0,4);
        iVar1 = FUN_00023424();
        if ((*(int *)(iVar1 + 0xc) != 0) && (iVar1 = FUN_00023424(), 0 < *(int *)(iVar1 + 0x48))) {
          local_40[0] = local_40[0] & 0xfff01133 | 0x101133;
          FUN_0002381c(5,1,9,4,local_40);
        }
      }
      FUN_000235a8(5,0,L"%S  line %d -----------Search start","CUSBMgr::bootResumeThreadFunc",0x6a);
      FUN_0001ed70(param_1,0);
      FUN_000235a8(5,0,L"%S  line %d -----------Search end","CUSBMgr::bootResumeThreadFunc",0x6c);
      iVar1 = FUN_00023424();
      if (0 < *(int *)(iVar1 + 0x48)) {
        memset(local_40,0,4);
        local_40[0] = local_40[0] & 0xfff01f33 | 0x1033;
        iVar1 = FUN_00023424();
        iVar1 = FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
        if ((iVar1 < 1) || (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0xc) == 0)) {
          iVar3 = 0;
        }
        local_40[0] = (iVar3 << 0x14 ^ local_40[0]) & 0x100000 ^ local_40[0];
        if ((local_40[0] & 0x100000) == 0x100000) {
          local_40[0] = local_40[0] & 0xfffff1ff | 0x100;
        }
        else {
          local_40[0] = local_40[0] & 0xfffff6ff | 0x600;
        }
        FUN_000235a8(5,0,L"%S  line %d usbDev.bAudio %d ++++++++++++++++++++",
                     "CUSBMgr::bootResumeThreadFunc",0x7d,local_40[0] >> 0x14 & 1);
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x20) == 0) {
          FUN_0002381c(5,1,9,4,local_40);
        }
      }
      FUN_000235a8(5,0,L"%S  line %d Boot not cmd resume play!!!!!!!!",
                   "CUSBMgr::bootResumeThreadFunc",0x83);
    }
    else {
      iVar1 = FUN_0001c21c(param_1 + 0x10,L"\\Storage Card2\\USBMusicResume.dat");
      if (iVar1 != 0) {
        iVar1 = FUN_00023424();
        FUN_0001b0b4(*(int *)(iVar1 + 0x5c) + 0x10);
        iVar1 = FUN_00023424();
        uVar2 = FUN_0001bdec(*(int *)(iVar1 + 0x5c) + 0x10,0);
        iVar1 = FUN_00023424();
        *(undefined4 *)(iVar1 + 0xc) = uVar2;
        iVar1 = FUN_00023424();
        *(undefined4 *)(iVar1 + 8) = 1;
        iVar1 = FUN_00023424();
        if ((*(int *)(iVar1 + 0xc) != 0) && (iVar1 = FUN_00023424(), 0 < *(int *)(iVar1 + 0x48))) {
          memset(local_40,0,4);
          local_40[0] = local_40[0] & 0xfff01f13 | 0x101013;
          Sleep(2000);
          iVar1 = FUN_00023424();
          if (*(int *)(iVar1 + 0x20) == 0) {
            FUN_0002381c(5,1,9,4,local_40);
          }
        }
        FUN_000235a8(5,0,L"%S  line %d Boot cmd resume play!!!!!!!!","CUSBMgr::bootResumeThreadFunc"
                     ,0xa0);
      }
      FUN_0001ed70(param_1,0);
      iVar1 = FUN_00023424();
      if (0 < *(int *)(iVar1 + 0x48)) {
        memset(local_40,0,4);
        local_40[0] = local_40[0] & 0xfff01133 | 0x1133;
        iVar1 = FUN_00023424();
        iVar1 = FUN_000126f4(*(undefined4 *)(iVar1 + 0x58));
        if ((iVar1 < 1) || (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0xc) == 0)) {
          iVar3 = 0;
        }
        local_40[0] = (iVar3 << 0x14 ^ local_40[0]) & 0x100000 ^ local_40[0];
        if ((local_40[0] & 0x100000) == 0) {
          local_40[0] = local_40[0] & 0xfffff6ff | 0x600;
        }
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x20) == 0) {
          FUN_0002381c(5,1,9,4,local_40);
        }
      }
      FUN_000235a8(5,0,L"%S  line %d Boot cmd resume Status update!!!!!!!!",
                   "CUSBMgr::bootResumeThreadFunc",0xb7);
    }
    iVar1 = FUN_00023424();
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(&DAT_00099520 + param_1) = 0;
    return;
  }
  iVar1 = FUN_00023424();
  *(undefined4 *)(iVar1 + 0x48) = 0;
  memset(local_40,0,4);
  local_40[0] = local_40[0] & 0xffe01733 | 0x1733;
  FUN_000235a8(5,0,L"%S  line %d BOOT Resume Fail","CUSBMgr::bootResumeThreadFunc",0x45);
  iVar1 = FUN_00023424();
  if (*(int *)(iVar1 + 0x20) != 0) {
    return;
  }
  FUN_0002381c(5,1,9,4,local_40);
  return;
}



/* 0002008c FUN_0002008c */

/* Boundary evidence: original MIPS .pdata 0002008c..00020363. Semantic name remains unreviewed. */

void FUN_0002008c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  UINT_PTR uIDEvent;
  undefined4 local_18 [2];
  
  switch(param_2) {
  case 1:
    FUN_0001b518(param_1 + 0x10);
    break;
  case 2:
    FUN_0001d72c(param_1 + 0x10);
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x2c) = 4;
    iVar2 = FUN_00023424();
    uIDEvent = 3;
    goto LAB_00020118;
  case 4:
    FUN_0001e820(param_1);
    break;
  case 5:
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),5);
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa0) = 0;
    FUN_0001c9a8(param_1 + 0x10,*(undefined4 *)(param_1 + 0x1ae6),3,*(int *)(param_1 + 0xc9c) != 0,1
                );
    break;
  case 6:
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),6);
    FUN_0001c9a8(param_1 + 0x10,*(undefined4 *)(param_1 + 0x1ae6),2,*(int *)(param_1 + 0xc9c) != 0,1
                );
    break;
  case 7:
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),7);
    iVar2 = FUN_00023424();
    if (*(int *)(iVar2 + 0x3c) != 0) {
      FUN_0001f88c(param_1,*(undefined4 *)(&DAT_00099310 + param_1));
    }
    memset(&DAT_00099310 + param_1,0,4);
    break;
  case 8:
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),8);
    if (*(int *)(param_1 + 0xc9c) == 0) {
      uVar1 = FUN_00011908();
      FUN_0001195c(uVar1);
    }
    break;
  case 9:
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),9);
    *(undefined4 *)(param_1 + 0xc) = 0;
    FUN_0001eb44(param_1);
    break;
  case 0xb:
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x44) = 0;
    iVar2 = FUN_00023424();
    uIDEvent = 0xb;
LAB_00020118:
    KillTimer(*(HWND *)(iVar2 + 0x4c),uIDEvent);
    break;
  case 0xc:
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),0xc);
    local_18[0] = 0x1023;
    FUN_0002381c(5,1,9,4,local_18);
    break;
  case 0xd:
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x10) = 0;
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),0xd);
    local_18[0] = 0x1733;
    FUN_0002381c(5,1,9,4,local_18);
  }
  return;
}



/* 00020364 FUN_00020364 */

undefined4 * FUN_00020364(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 00020388 FUN_00020388 */

/* Boundary evidence: original MIPS .pdata 00020388..000203af. Semantic name remains unreviewed. */

void FUN_00020388(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  EventModify(*(undefined4 *)(param_1 + 8),3);
  return;
}



/* 000203b0 FUN_000203b0 */

/* Boundary evidence: original MIPS .pdata 000203b0..000204db. Semantic name remains unreviewed. */

void FUN_000203b0(int param_1,void *param_2)

{
  int iVar1;
  LPARAM lParam;
  wchar_t *_Str2;
  
  _Str2 = (wchar_t *)((int)param_2 + 0x1c);
  iVar1 = wcscmp(L"MD",_Str2);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,&DAT_0002aef8,0x10);
    if (iVar1 != 0) {
      return;
    }
    lParam = 0;
  }
  else {
    iVar1 = wcscmp(L"MD2",_Str2);
    if (iVar1 == 0) {
      lParam = 1;
    }
    else {
      iVar1 = wcscmp(L"MD3",_Str2);
      if (iVar1 == 0) {
        lParam = 2;
      }
      else {
        iVar1 = wcscmp(L"RMD0:",_Str2);
        if (iVar1 != 0) {
          return;
        }
        iVar1 = memcmp(param_2,&DAT_0002aed8,0x10);
        if (iVar1 == 0) {
          PostMessageW(*(HWND *)(param_1 + 4),*(UINT *)(param_1 + 0xc),
                       *(WPARAM *)((int)param_2 + 0x14),0x103);
        }
        iVar1 = memcmp(param_2,&DAT_0002aee8,0x10);
        if (iVar1 != 0) {
          return;
        }
        lParam = 0x203;
      }
    }
  }
  PostMessageW(*(HWND *)(param_1 + 4),*(UINT *)(param_1 + 0xc),*(WPARAM *)((int)param_2 + 0x14),
               lParam);
  return;
}



/* 000204dc FUN_000204dc */

/* Boundary evidence: original MIPS .pdata 000204dc..000206b7. Semantic name remains unreviewed. */

undefined4 FUN_000204dc(int param_1)

{
  HANDLE hHandle;
  DWORD DVar1;
  int iVar2;
  int iVar3;
  wchar_t *pwVar4;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined1 auStack_f4 [4];
  undefined1 auStack_f0 [8];
  undefined1 auStack_e8 [192];
  undefined4 local_28;
  
  local_28 = DAT_0002f964;
  local_108 = 0x14;
  local_104 = 1;
  local_100 = 0;
  local_fc = 0xc0;
  local_f8 = 1;
  hHandle = (HANDLE)CreateMsgQueue(0,&local_108);
  if (hHandle == (HANDLE)0x0) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Create Msg Q.\n",DVar1);
  }
  else {
    iVar2 = RequestDeviceNotifications(0,hHandle,1);
    if (iVar2 != 0) {
      *(HANDLE *)(param_1 + 8) = hHandle;
      if (*(int *)(param_1 + 0x10) == 0) {
        do {
          DVar1 = WaitForSingleObject(hHandle,0xffffffff);
          if (DVar1 == 0) {
            iVar3 = ReadMsgQueue(hHandle,auStack_e8,0xc0,auStack_f4,0,auStack_f0);
            if (iVar3 == 0) {
              DVar1 = GetLastError();
              pwVar4 = L"ERROR(%d): Fail to Read Q\n";
              goto LAB_00020658;
            }
            FUN_000203b0(param_1,auStack_e8);
          }
          else {
            DVar1 = GetLastError();
            pwVar4 = L"ERROR(%d): Invalid result from \'hBlockQueue\'\n";
LAB_00020658:
            NKDbgPrintfW(pwVar4,DVar1);
          }
        } while (*(int *)(param_1 + 0x10) == 0);
      }
      StopDeviceNotifications(iVar2);
      CloseMsgQueue(hHandle);
                    /* WARNING: Subroutine does not return */
      ExitThread(0);
    }
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t Request Device Notifications\n",DVar1);
    CloseMsgQueue(hHandle);
  }
  FUN_00025660(local_28);
  return 0;
}



/* 000206b8 FUN_000206b8 */

/* Boundary evidence: original MIPS .pdata 000206b8..00020733. Semantic name remains unreviewed. */

void FUN_000206b8(LPVOID param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE hObject;
  DWORD DVar1;
  
  *(undefined4 *)((int)param_1 + 4) = param_2;
  *(undefined4 *)((int)param_1 + 0xc) = param_3;
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000204dc,param_1,0,(LPDWORD)0x0);
  if (hObject == (HANDLE)0x0) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"ERROR(%d): Can\'t create ThreadProcDevNotify\n",DVar1);
  }
  else {
    CloseHandle(hObject);
  }
  return;
}



/* 00020734 FUN_00020734 */

/* Boundary evidence: original MIPS .pdata 00020734..000207e3. Semantic name remains unreviewed. */

bool FUN_00020734(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_00023424();
  FUN_00023090(iVar2 + 0x60);
  iVar2 = FUN_00023424();
  FUN_00023034(iVar2 + 0x60);
  iVar2 = FUN_00023424();
  FUN_00022fd8(iVar2 + 0x60);
  iVar2 = FUN_00023424();
  *(undefined4 *)(iVar2 + 0x14) = 0;
  iVar2 = FUN_00023424();
  FUN_0001d8d0(*(undefined4 *)(iVar2 + 0x5c));
  iVar2 = FUN_00023424();
  bVar1 = *(int *)(iVar2 + 0xc) == 0;
  if (bVar1) {
    iVar2 = FUN_00023424();
    FUN_0001da28(*(undefined4 *)(iVar2 + 0x5c));
    FUN_000235a8(5,0,L"%S  line %d","detachStop",0x17);
  }
  return bVar1;
}



/* 000207e4 FUN_000207e4 */

void FUN_000207e4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  return;
}



/* 000207f4 FUN_000207f4 */

undefined4 * FUN_000207f4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  *(undefined2 *)(param_1 + 1) = 0;
  *(undefined2 *)(param_1 + 0x83) = 0;
  return param_1;
}



/* 00020810 FUN_00020810 */

/* Boundary evidence: original MIPS .pdata 00020810..00020853. Semantic name remains unreviewed. */

undefined4 * FUN_00020810(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002b0c0;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00020854 FUN_00020854 */

/* Boundary evidence: original MIPS .pdata 00020854..00020f77. Semantic name remains unreviewed. */

undefined4
FUN_00020854(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  UINT_PTR nIDEvent;
  int iVar5;
  uint local_20;
  DWORD DStack_1c;
  
  iVar5 = (int)param_5 >> 8;
  param_5 = param_5 & 0xff;
  FUN_000235a8(5,3,L"%S Line %d message %d wParam %d lParam %d, seqGUID %d +++",
               "CDeviceMsgHandler::deviceChangeHandler",0x38,param_3,param_4,param_5,iVar5);
  if ((param_4 == 0) || (param_5 == 0)) {
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),0xc);
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),0xd);
    if (param_5 == 0) {
      if (param_4 == 0) {
        DAT_006b83b0 = 0;
        iVar5 = FUN_00023424();
        if ((*(int *)(iVar5 + 0x20) == 0) &&
           (iVar5 = FUN_00023424(), *(int *)(*(int *)(iVar5 + 0x5c) + 0xc) == 0)) {
          FUN_0002381c(5,5,0x69,0,0);
        }
        else {
          memset(&local_20,0,4);
          local_20 = local_20 & 0xffe01333 | 0x1333;
          FUN_0002381c(5,1,9,4,&local_20);
        }
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x20) = 1;
        iVar5 = FUN_00023424();
        FUN_00014284(*(undefined4 *)(iVar5 + 0x58));
        FUN_000235a8(5,1,L"%S DBT_DEVICEREMOVECOMPLETE_Notify",
                     "CDeviceMsgHandler::deviceChangeHandler");
        iVar5 = FUN_00023424();
        FUN_0001e7f8(*(undefined4 *)(iVar5 + 0x5c));
        iVar5 = FUN_00023424();
        FUN_0001daec(*(undefined4 *)(iVar5 + 0x5c));
        iVar5 = FUN_00023424();
        FUN_0001ea10(*(undefined4 *)(iVar5 + 0x5c));
        iVar5 = FUN_00023424();
        FUN_0001ea74(*(undefined4 *)(iVar5 + 0x5c));
        iVar5 = FUN_00023424();
        if ((*(int *)(iVar5 + 0x48) != 0) && (iVar5 = FUN_00023424(), *(int *)(iVar5 + 8) != 0)) {
          iVar5 = FUN_00023424();
          FUN_0001c538(*(int *)(iVar5 + 0x5c) + 0x10,L"\\Storage Card2\\USBMusicResume.dat");
          uVar4 = FUN_00011908();
          FUN_00011c18(uVar4);
          iVar5 = FUN_00023424();
          *(undefined4 *)(iVar5 + 0x48) = 0;
          iVar5 = FUN_00023424();
          *(undefined4 *)(iVar5 + 0xc) = 0;
          iVar5 = FUN_00023424();
          *(undefined4 *)(iVar5 + 0x1c) = 0;
          CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00020734,(LPVOID)0x0,0,&DStack_1c);
          return 1;
        }
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x48) = 0;
        return 0;
      }
      iVar5 = FUN_00023424();
      KillTimer(*(HWND *)(iVar5 + 0x4c),10);
      FUN_000235a8(5,1,L"%S DBT_DEVICER_Incert_notify","CDeviceMsgHandler::deviceChangeHandler");
      iVar5 = FUN_00023424();
      if (*(int *)(iVar5 + 0x18) == 0) {
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x48) = 1;
        iVar5 = FUN_00023424();
        FUN_0002317c(iVar5 + 0x60);
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x18) = 1;
        return 1;
      }
      iVar5 = FUN_00023424();
      if (*(int *)(&DAT_00099520 + *(int *)(iVar5 + 0x5c)) != 0) {
        iVar5 = FUN_00023424();
        FUN_00023090(iVar5 + 0x60);
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x48) = 0;
      }
      iVar5 = FUN_00023424();
      if (*(int *)(iVar5 + 0x48) == 0) {
        iVar5 = FUN_00023424();
        if (*(int *)(*(int *)(iVar5 + 0x5c) + 0xc) != 0) {
          return 0;
        }
        iVar5 = FUN_00023424();
        if (*(int *)(iVar5 + 0x20) != 0) {
          return 0;
        }
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0x1c) = 1;
        iVar5 = FUN_00023424();
        FUN_00023034(iVar5 + 0x60);
        iVar5 = FUN_00023424();
        FUN_00023158(iVar5 + 0x60);
        iVar5 = FUN_00023424();
        DVar3 = GetTickCount();
        FUN_000235a8(5,1,L"%S ********************Process TIME : %d ms*********************",
                     "CDeviceMsgHandler::deviceChangeHandler",DVar3 - *(int *)(iVar5 + 4));
        iVar5 = FUN_00023424();
        if (*(int *)(iVar5 + 0x20) != 0) {
          return 0;
        }
        iVar5 = FUN_00023424();
        FUN_0001d8d0(*(undefined4 *)(iVar5 + 0x5c));
        iVar5 = FUN_00023424();
        FUN_0001264c(*(undefined4 *)(iVar5 + 0x58));
        iVar5 = FUN_00023424();
        *(undefined4 *)(iVar5 + 0xc) = 0;
        iVar5 = FUN_00023424();
        FUN_0001e820(*(undefined4 *)(iVar5 + 0x5c));
        return 1;
      }
      FUN_000235a8(5,3,L"%S Support only one usb!!","CDeviceMsgHandler::deviceChangeHandler");
      return 1;
    }
  }
  if (param_5 != 3) {
    return 0;
  }
  if (param_4 == 0) {
    iVar5 = FUN_00023424();
    *(undefined4 *)(iVar5 + 0x20) = 1;
    uVar4 = FUN_00011908();
    FUN_00011c18(uVar4);
    FUN_000235a8(5,1,L"%S DBT_DEVICEREMOVECOMPLETE_DeviceChange",
                 "CDeviceMsgHandler::deviceChangeHandler");
    iVar5 = FUN_00023424();
    FUN_0001e7f8(*(undefined4 *)(iVar5 + 0x5c));
    iVar5 = FUN_00023424();
    FUN_0001daec(*(undefined4 *)(iVar5 + 0x5c));
    iVar5 = FUN_00023424();
    FUN_0001ea10(*(undefined4 *)(iVar5 + 0x5c));
    iVar5 = FUN_00023424();
    FUN_0001ea74(*(undefined4 *)(iVar5 + 0x5c));
    iVar5 = FUN_00023424();
    FUN_0001da28(*(undefined4 *)(iVar5 + 0x5c));
    if (DAT_006b83b0 == 0) {
      iVar5 = FUN_00023424();
      *(undefined4 *)(iVar5 + 0x48) = 0;
    }
    FUN_0002381c(5,5,0x69,0,0);
    return 1;
  }
  memset(&local_20,0,4);
  iVar2 = FUN_00023424();
  if (*(int *)(iVar2 + 0x10) == 0) {
    iVar2 = FUN_00023424();
    if (*(int *)(iVar2 + 0x48) != 0) {
      return 0;
    }
    iVar2 = FUN_00023424();
    FUN_000235a8(5,3,L"%S Line %d m_nAttachedUSBNum %d","CDeviceMsgHandler::deviceChangeHandler",
                 0x6d,*(undefined4 *)(iVar2 + 0x48));
    iVar2 = FUN_00023424();
    KillTimer(*(HWND *)(iVar2 + 0x4c),10);
    FUN_000235a8(5,0,L"%S  m_bSkipFirstDetectRMD0 == FALSE","CDeviceMsgHandler::deviceChangeHandler"
                );
    DAT_006b83b0 = 1;
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 8) = 0;
    DVar3 = GetTickCount();
    iVar2 = FUN_00023424();
    *(DWORD *)(*(int *)(iVar2 + 0x5c) + 8) = DVar3;
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x20) = 0;
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x18) = 1;
    DVar3 = GetTickCount();
    iVar2 = FUN_00023424();
    *(DWORD *)(iVar2 + 4) = DVar3;
    if (iVar5 == 2) {
      iVar5 = FUN_00023424();
      KillTimer(*(HWND *)(iVar5 + 0x4c),0xc);
      iVar5 = FUN_00023424();
      nIDEvent = 0xd;
    }
    else {
      iVar5 = FUN_00023424();
      KillTimer(*(HWND *)(iVar5 + 0x4c),0xd);
      iVar5 = FUN_00023424();
      nIDEvent = 0xc;
    }
    SetTimer(*(HWND *)(iVar5 + 0x4c),nIDEvent,5000,(TIMERPROC)0x0);
    local_20 = local_20 & 0xffe01f23 | 0x1023;
    FUN_0002381c(5,1,9,4,&local_20);
    return 1;
  }
  if (iVar5 == 2) {
    DAT_006b83b4 = 1;
  }
  else {
    iVar2 = FUN_00023424();
    bVar1 = DAT_006b83b4 != 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    if (bVar1) goto LAB_00020980;
  }
  iVar2 = FUN_00023424();
  SetTimer(*(HWND *)(iVar2 + 0x4c),0xd,5000,(TIMERPROC)0x0);
LAB_00020980:
  iVar2 = FUN_00023424();
  FUN_000235a8(5,0,L"%S Line %d getGlobalVal()->m_bSkipFirstDetectRMD0 %d nSequenceGUID %d",
               "CDeviceMsgHandler::deviceChangeHandler",99,*(undefined4 *)(iVar2 + 0x10),iVar5);
  return 0;
}



/* 00020f78 FUN_00020f78 */

/* Boundary evidence: original MIPS .pdata 00020f78..000218e7. Semantic name remains unreviewed. */

undefined4
FUN_00020f78(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint local_18;
  uint local_14;
  
  uVar5 = 1;
  switch(param_3) {
  case 100:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_NEXT_TRACK ","CIPCMsgHandler::msgFromMe");
    iVar3 = FUN_00023424();
    FUN_00019960(*(int *)(iVar3 + 0x5c) + 0x10);
    iVar3 = FUN_00023424();
    FUN_00019924(*(int *)(iVar3 + 0x5c) + 0x10);
    iVar3 = FUN_00023424();
    FUN_0001d988(*(undefined4 *)(iVar3 + 0x5c),1);
    iVar1 = *param_5;
    iVar3 = FUN_0001216c(0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    if ((iVar3 != 0) && (iVar3 = FUN_00023424(), *(int *)(iVar3 + 0x3c) != 0)) {
      iVar3 = FUN_00023424();
      if (*(int *)(iVar3 + 0x44) != 1) {
        if (iVar1 == 0) {
          iVar3 = FUN_00023424();
          FUN_0001ebc0(*(undefined4 *)(iVar3 + 0x5c));
        }
        iVar3 = FUN_00023424();
        FUN_0001da44(*(undefined4 *)(iVar3 + 0x5c),1);
        FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x19c);
        iVar3 = FUN_00023424();
        FUN_0001d9f0(*(undefined4 *)(iVar3 + 0x5c));
        iVar3 = FUN_00023424();
        FUN_0001eab8(*(undefined4 *)(iVar3 + 0x5c),0,0);
        FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x19f);
        iVar3 = FUN_00023424();
        FUN_0001b374(*(int *)(iVar3 + 0x5c) + 0x10);
        FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x1a1);
LAB_00021194:
        iVar3 = FUN_00023424();
        uVar5 = FUN_0001d9bc(*(undefined4 *)(iVar3 + 0x5c));
        iVar3 = FUN_00023424();
        FUN_0001e53c(*(undefined4 *)(iVar3 + 0x5c),uVar5);
        return 1;
      }
LAB_0002109c:
      iVar3 = FUN_00023424();
      FUN_0001b440(*(int *)(iVar3 + 0x5c) + 0x10);
    }
  default:
switchD_00020fc8_default:
    uVar5 = 0;
    break;
  case 0x65:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_PREV_TRACK ","CIPCMsgHandler::msgFromMe");
    iVar3 = FUN_00023424();
    FUN_00019924(*(int *)(iVar3 + 0x5c) + 0x10);
    iVar3 = FUN_00023424();
    FUN_00019960(*(int *)(iVar3 + 0x5c) + 0x10);
    iVar1 = *param_5;
    iVar3 = FUN_0001216c(0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    if ((iVar3 != 0) && (iVar3 = FUN_00023424(), *(int *)(iVar3 + 0x3c) != 0)) {
      iVar3 = FUN_00023424();
      if (*(int *)(iVar3 + 0x44) != 1) {
        if (iVar1 == 0) {
          iVar3 = FUN_00023424();
          FUN_0001ebc0(*(undefined4 *)(iVar3 + 0x5c));
        }
        iVar3 = FUN_00023424();
        FUN_0001da44(*(undefined4 *)(iVar3 + 0x5c),1);
        uVar5 = FUN_00011908();
        iVar3 = FUN_000117b4(uVar5);
        if (iVar3 < 4) {
          iVar3 = FUN_00023424();
          FUN_0001da0c(*(undefined4 *)(iVar3 + 0x5c));
          iVar3 = FUN_00023424();
          FUN_0001eab8(*(undefined4 *)(iVar3 + 0x5c),0,0);
          iVar3 = FUN_00023424();
          FUN_0001b3e8(*(int *)(iVar3 + 0x5c) + 0x10);
        }
        else {
          uVar5 = FUN_00011908();
          FUN_000116a0(uVar5,0);
          iVar3 = FUN_00023424();
          FUN_0001da7c(*(undefined4 *)(iVar3 + 0x5c),0);
          iVar3 = FUN_00023424();
          iVar1 = *(int *)(*(int *)(iVar3 + 0x5c) + 0xc9c);
          iVar3 = FUN_00023424();
          uVar5 = FUN_0001d9bc(*(undefined4 *)(iVar3 + 0x5c));
          iVar3 = FUN_00023424();
          FUN_0001d9cc(*(undefined4 *)(iVar3 + 0x5c),uVar5,1,iVar1 != 0,1);
          iVar3 = FUN_00023424();
          FUN_0001eba4(*(undefined4 *)(iVar3 + 0x5c));
        }
        goto LAB_00021194;
      }
      goto LAB_0002109c;
    }
    goto switchD_00020fc8_default;
  case 0x66:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_SHUFFLE ","CIPCMsgHandler::msgFromMe");
    iVar3 = FUN_00023424();
    FUN_00022fd8(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_00023110(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_00022ec0(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_0001dab4(*(undefined4 *)(iVar3 + 0x5c),*param_5);
    iVar3 = FUN_00023424();
    FUN_000230ec(iVar3 + 0x60);
    break;
  case 0x67:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_REPEAT ","CIPCMsgHandler::msgFromMe");
    iVar3 = FUN_00023424();
    FUN_0001dad0(*(undefined4 *)(iVar3 + 0x5c),*param_5);
    break;
  case 0x68:
    iVar3 = FUN_00023424();
    if (*(int *)(iVar3 + 0x48) != 0) {
      memset(&local_18,0,4);
      iVar3 = FUN_00023424();
      if (*(int *)(&DAT_00099520 + *(int *)(iVar3 + 0x5c)) != 0) {
        iVar3 = FUN_00023424();
        if (*(int *)(iVar3 + 0x14) == 0) {
          local_18 = local_18 & 0xfff01133 | 0x101133;
          FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x20b);
        }
        else {
          local_18 = local_18 & 0xfff01113 | 0x101113;
          FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x214);
        }
        iVar3 = FUN_00023424();
        if (*(int *)(iVar3 + 0x20) != 0) {
          return 1;
        }
        FUN_0002381c(5,1,9,4,&local_18);
        return 1;
      }
      iVar3 = FUN_00023424();
      if ((*(int *)(iVar3 + 0x14) == 0) && (iVar3 = FUN_00023424(), *(int *)(iVar3 + 0x1c) == 0)) {
        local_18 = local_18 & 0xfff01133 | 0x101133;
        FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x1f0);
      }
      else {
        local_18 = local_18 & 0xfff01f13 | 0x101013;
        FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x1f8);
      }
      iVar3 = FUN_00023424();
      if (*(int *)(iVar3 + 0x20) != 0) {
        return 1;
      }
      FUN_0002381c(5,1,9,4,&local_18);
      return 1;
    }
    goto switchD_00020fc8_default;
  case 0x69:
    memset(&local_14,0,4);
    local_14 = local_14 & 0xfff01f03 | 0x1003;
    FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x226);
    FUN_0002381c(5,1,9,4,&local_14);
    memset(&local_14,0,4);
    local_14 = local_14 & 0xfff01f43 | 0x1043;
    FUN_000235a8(5,0,L"%S  line %d","CIPCMsgHandler::msgFromMe",0x231);
    FUN_00023a50(5,1,9,4,&local_14);
    break;
  case 0x6a:
    iVar3 = *param_5;
    uVar4 = FUN_00011908();
    iVar1 = FUN_00011838(uVar4);
    uVar4 = FUN_00011908();
    iVar2 = FUN_000117b4(uVar4);
    if ((-1 < iVar1) && (iVar3 != iVar2)) {
      if (iVar1 < iVar3) {
        iVar3 = iVar1;
      }
      iVar1 = FUN_00023424();
      FUN_0001da7c(*(undefined4 *)(iVar1 + 0x5c),iVar3);
      uVar4 = FUN_00011908();
      FUN_00011cac(uVar4);
      uVar4 = FUN_00011908();
      FUN_000116a0(uVar4,iVar3);
    }
    break;
  case 0x6b:
    iVar3 = FUN_00023424();
    FUN_0001ea40(*(undefined4 *)(iVar3 + 0x5c),param_5);
    iVar3 = FUN_00023424();
    FUN_0001fa28(*(undefined4 *)(iVar3 + 0x5c));
    break;
  case 0x6c:
    iVar3 = FUN_00023424();
    FUN_0001db08(*(undefined4 *)(iVar3 + 0x5c));
    break;
  case 0x6d:
    FUN_000235a8(5,0,L"%S Line %d IDM_AMAIN_MUSB_VIRTUAL_PAUSE ","CIPCMsgHandler::msgFromMe",599);
    *(undefined4 *)(param_1 + 4) = 0;
    iVar3 = FUN_00023424();
    FUN_0001d950(*(undefined4 *)(iVar3 + 0x5c));
    iVar3 = FUN_00023424();
    if (*(int *)(iVar3 + 0xa0) == 1) {
      iVar3 = FUN_00023424();
      FUN_00019960(*(int *)(iVar3 + 0x5c) + 0x10);
      iVar3 = FUN_00023424();
      FUN_00019924(*(int *)(iVar3 + 0x5c) + 0x10);
      iVar3 = FUN_00023424();
      FUN_0001eb00(*(undefined4 *)(iVar3 + 0x5c));
    }
    break;
  case 0x6e:
    FUN_000235a8(5,0,L"%S Line %d IDM_AMAIN_MUSB_VIRTUAL_RESUME ","CIPCMsgHandler::msgFromMe",0x263)
    ;
    iVar3 = FUN_00023424();
    uVar4 = FUN_0001d9b4(*(undefined4 *)(iVar3 + 0x5c));
    FUN_000235a8(5,0,L"%S Line %d IDM_MUSB_MUSB_VIRTUAL_RESUME PlayFast = %d ",
                 "CIPCMsgHandler::msgFromMe",0x265,uVar4);
    iVar3 = FUN_00023424();
    iVar3 = FUN_0001d9b4(*(undefined4 *)(iVar3 + 0x5c));
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      iVar3 = FUN_00023424();
      FUN_0001d96c(*(undefined4 *)(iVar3 + 0x5c));
    }
    else {
      *(undefined4 *)(param_1 + 4) = 1;
    }
  }
  return uVar5;
}



/* 000218e8 FUN_000218e8 */

/* Boundary evidence: original MIPS .pdata 000218e8..00021953. Semantic name remains unreviewed. */

bool FUN_000218e8(undefined4 param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  
  if (param_3 == 10) {
    iVar1 = FUN_00023424();
    FUN_0001da28(*(undefined4 *)(iVar1 + 0x5c));
    FUN_0002381c(5,1,0xb,0,0);
  }
  return param_3 == 10;
}



/* 00021954 FUN_00021954 */

/* Boundary evidence: original MIPS .pdata 00021954..000219e3. Semantic name remains unreviewed. */

void FUN_00021954(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00023424();
  puVar2 = (undefined4 *)FUN_0001ea64(*(undefined4 *)(iVar1 + 0x5c));
  uVar3 = *puVar2;
  iVar1 = FUN_00023424();
  FUN_0001ea10(*(undefined4 *)(iVar1 + 0x5c));
  if ((char)uVar3 == '\0') {
    FUN_0002381c(5,0x15,0x66,0,0);
  }
  else {
    iVar1 = FUN_00023424();
    FUN_0001f88c(*(undefined4 *)(iVar1 + 0x5c),uVar3);
    iVar1 = FUN_00023424();
    FUN_0001ead4(*(undefined4 *)(iVar1 + 0x5c));
  }
  return;
}



/* 000219e4 FUN_000219e4 */

undefined4 * FUN_000219e4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  param_1[1] = 0;
  return param_1;
}



/* 000219fc FUN_000219fc */

/* Boundary evidence: original MIPS .pdata 000219fc..00022537. Semantic name remains unreviewed. */

undefined4
FUN_000219fc(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  local_a64 = 0;
  local_a68 = 0;
  local_a58 = param_2;
  local_a54 = param_3;
  local_a50 = param_4;
  iVar1 = FUN_00023424();
  uVar8 = local_a54 & 0xffff;
  if ((((*(int *)(iVar1 + 0x20) != 0) || (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0x48) == 0)) &&
      (uVar8 != 0x7c)) && ((uVar8 != 0x7e && (uVar8 != 0x7f)))) {
LAB_0002250c:
    FUN_00025660(local_20);
    return 0;
  }
  switch(uVar8) {
  case 100:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_PREV_TRACK ","CIPCMsgHandler::msgFromAppMain");
    local_a64 = *param_5;
    FUN_0002381c(5,5,0x65,4,&local_a64);
    break;
  case 0x66:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_FAST_FORWARD_START ","CIPCMsgHandler::msgFromAppMain");
    iVar1 = FUN_00023424();
    uVar7 = 1;
    goto LAB_00022080;
  case 0x67:
    FUN_000235a8(5,1,L"%S IDM_AMAIN_MUSB_FAST_FORWARD_END","CIPCMsgHandler::msgFromAppMain");
    iVar1 = FUN_00023424();
    FUN_0001db40(*(undefined4 *)(iVar1 + 0x5c));
    if (*(int *)(param_1 + 4) == 1) {
      FUN_0002381c(5,5,0x6e,0,0);
    }
    break;
  case 0x68:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_FAST_REWIND_START ","CIPCMsgHandler::msgFromAppMain");
    iVar1 = FUN_00023424();
    uVar7 = 2;
LAB_00022080:
    FUN_0001db24(*(undefined4 *)(iVar1 + 0x5c),uVar7);
    break;
  case 0x69:
    FUN_000235a8(5,1,L"%S IDM_AMAIN_MUSB_FAST_REWIND_END","CIPCMsgHandler::msgFromAppMain");
    iVar1 = FUN_00023424();
    FUN_0001db40(*(undefined4 *)(iVar1 + 0x5c));
    if (*(int *)(param_1 + 4) == 1) {
      FUN_0002381c(5,5,0x6e,0,0);
    }
    break;
  case 0x6a:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_SHUFFLE ","CIPCMsgHandler::msgFromAppMain");
    local_a5c = *param_5;
    FUN_0002381c(5,5,0x66,4,&local_a5c);
    break;
  case 0x6b:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_REPEAT ","CIPCMsgHandler::msgFromAppMain");
    local_a60 = *param_5;
    FUN_0002381c(5,5,0x67,4,&local_a60);
    break;
  case 0x6c:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_CHANGE_PLAY_STATUS ","CIPCMsgHandler::msgFromAppMain");
    FUN_000235a8(5,0,L"%S %d","CIPCMsgHandler::msgFromAppMain",*param_5);
    uVar8 = *param_5;
    iVar1 = FUN_00023424();
    iVar5 = FUN_0001d9a4(*(undefined4 *)(iVar1 + 0x5c));
    FUN_000235a8(5,0,L"%S stTemp %d","CIPCMsgHandler::msgFromAppMain",uVar8);
    iVar1 = iVar5;
    FUN_000235a8(5,0,L"%S current %d","CIPCMsgHandler::msgFromAppMain",iVar5);
    iVar2 = FUN_00023424();
    FUN_0001ea74(*(undefined4 *)(iVar2 + 0x5c));
    if ((iVar5 == 1) || (uVar8 != 1)) {
      if (uVar8 == 2) {
        FUN_000235a8(5,0,L"%S ST_PAUSE","CIPCMsgHandler::msgFromAppMain",iVar1);
        iVar1 = FUN_00023424();
        FUN_0001da44(*(undefined4 *)(iVar1 + 0x5c),0);
        iVar1 = FUN_00023424();
        if (*(int *)(*(int *)(iVar1 + 0x5c) + 0xc9c) != 0) {
          iVar1 = FUN_00023424();
          *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc9c) = 2;
        }
      }
    }
    else {
      FUN_000235a8(5,0,L"%S ST_PLAY","CIPCMsgHandler::msgFromAppMain",iVar1);
      iVar1 = FUN_00023424();
      FUN_000235a8(5,0,L"%S ST_PLAY getVirtualStatus %d","CIPCMsgHandler::msgFromAppMain",
                   *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc9c));
      iVar1 = FUN_00023424();
      if ((*(int *)(*(int *)(iVar1 + 0x5c) + 0xc9c) == 0) ||
         (iVar1 = FUN_00023424(), *(int *)(*(int *)(iVar1 + 0x5c) + 0xc9c) == 1)) {
        iVar1 = FUN_00023424();
        if (*(int *)(iVar1 + 0x24) == 0) {
          iVar1 = FUN_00023424();
          iVar5 = *(int *)(*(int *)(iVar1 + 0x5c) + 0xc9c);
          iVar1 = FUN_00023424();
          uVar7 = FUN_0001d9bc(*(undefined4 *)(iVar1 + 0x5c));
          iVar1 = FUN_00023424();
          FUN_0001d9cc(*(undefined4 *)(iVar1 + 0x5c),uVar7,1,iVar5 != 0,1);
        }
        else {
          iVar1 = FUN_00023424();
          FUN_0001da60(*(undefined4 *)(iVar1 + 0x5c),0);
        }
      }
      else {
        iVar1 = FUN_00023424();
        FUN_0001d988(*(undefined4 *)(iVar1 + 0x5c),1);
        iVar1 = FUN_00023424();
        *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc9c) = 1;
      }
    }
    break;
  case 0x6d:
    uVar8 = *param_5;
    uVar7 = FUN_00011908();
    uVar3 = FUN_00011838(uVar7);
    uVar7 = FUN_00011908();
    uVar4 = FUN_000117b4(uVar7);
    if ((-1 < (int)uVar3) && (uVar8 != uVar4)) {
      if ((int)uVar3 < (int)uVar8) {
        uVar8 = uVar3;
      }
      uVar7 = FUN_00011908();
      FUN_00011cac(uVar7);
      uVar7 = FUN_00011908();
      FUN_000116a0(uVar7,uVar8);
      iVar1 = FUN_00023424();
      FUN_0001ea9c(*(undefined4 *)(iVar1 + 0x5c));
      iVar1 = FUN_00023424();
      iVar1 = FUN_0001d9a4(*(undefined4 *)(iVar1 + 0x5c));
      if (iVar1 == 1) {
        iVar1 = FUN_00023424();
        FUN_0001fa80(*(undefined4 *)(iVar1 + 0x5c));
      }
    }
    break;
  default:
    FUN_000235a8(5,0,L"%S unsupported mssage ","CIPCMsgHandler::msgFromAppMain");
    goto LAB_0002250c;
  case 0x72:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_REQUEST_TRACK_INFO ","CIPCMsgHandler::msgFromAppMain");
    iVar1 = FUN_00023424();
    uVar7 = *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x1ae6);
    iVar1 = FUN_00023424();
    FUN_0001b73c(*(int *)(iVar1 + 0x5c) + 0x10,uVar7);
    break;
  case 0x73:
    FUN_0002381c(5,5,0x6d,0,0);
    break;
  case 0x74:
    FUN_0002381c(5,5,0x6e,0,0);
    break;
  case 0x76:
    local_a68 = *param_5;
    if (((int)((local_a68 & 0xffffff00) << 8) < 0) || ((char)local_a68 == '\0')) {
      FUN_00021954(param_1);
      iVar1 = FUN_00023424();
      FUN_0001f88c(*(undefined4 *)(iVar1 + 0x5c),local_a68);
    }
    else {
      FUN_0002381c(5,5,0x6b,4,&local_a68);
    }
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_SELECT_CATEGORY nCat:%d nSelIdx:%d",
                 "CIPCMsgHandler::msgFromAppMain",(int)(char)local_a68,(int)(local_a68 << 8) >> 0x10
                );
    break;
  case 0x77:
    local_a68 = *param_5;
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_BACK_DB_RECORD nCat:%d nSelIdx:%d",
                 "CIPCMsgHandler::msgFromAppMain",(int)(char)local_a68,(int)(local_a68 << 8) >> 0x10
                );
    break;
  case 0x7c:
    iVar1 = FUN_00023424();
    FUN_0001e72c(*(undefined4 *)(iVar1 + 0x5c));
    break;
  case 0x7d:
    FUN_00021954(param_1);
    iVar1 = FUN_00023424();
    uVar7 = FUN_0001d9bc(*(undefined4 *)(iVar1 + 0x5c));
    iVar1 = FUN_00023424();
    FUN_0001e47c(*(undefined4 *)(iVar1 + 0x5c),uVar7);
    break;
  case 0x7e:
    iVar1 = FUN_00023424();
    if ((*(int *)(iVar1 + 0x48) == 0) || (iVar1 = FUN_00023424(), *(int *)(iVar1 + 8) == 0)) break;
    goto LAB_0002228c;
  case 0x7f:
    break;
  case 0x80:
    FUN_00021954(param_1);
    iVar1 = FUN_00023424();
    FUN_0001f208(*(undefined4 *)(iVar1 + 0x5c),0);
    break;
  case 0x81:
    iVar1 = FUN_00023424();
    if (*(int *)(*(int *)(iVar1 + 0x5c) + 0xc9c) == 2) {
      iVar1 = FUN_00023424();
      *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc9c) = 1;
    }
  case 0x65:
    FUN_000235a8(5,0,L"%S IDM_AMAIN_MUSB_NEXT_TRACK ","CIPCMsgHandler::msgFromAppMain");
    local_a64 = *param_5;
    FUN_0002381c(5,5,100,4,&local_a64);
    break;
  case 0x82:
    iVar1 = FUN_00023424();
    FUN_0001da44(*(undefined4 *)(iVar1 + 0x5c),0);
    break;
  case 0x83:
    iVar1 = FUN_00023424();
    if (*(int *)(iVar1 + 0x48) < 1) break;
LAB_0002228c:
    iVar1 = FUN_00023424();
    FUN_0001c538(*(int *)(iVar1 + 0x5c) + 0x10,L"\\Storage Card2\\USBMusicResume.dat");
    break;
  case 0x84:
    iVar1 = FUN_00023424();
    uVar7 = FUN_0001d9bc(*(undefined4 *)(iVar1 + 0x5c));
    iVar1 = FUN_00023424();
    FUN_0001e53c(*(undefined4 *)(iVar1 + 0x5c),uVar7);
    break;
  case 0x85:
    uVar8 = *param_5;
    iVar1 = FUN_00023424();
    *(uint *)(iVar1 + 0x3c) = uVar8;
    if ((uVar8 == 0) &&
       ((iVar1 = FUN_00023424(), *(int *)(iVar1 + 0x24) == 0 ||
        (iVar1 = FUN_00023424(), *(int *)(iVar1 + 0xa8) != 0)))) {
      FUN_0002381c(5,0x15,0x6f,0,0);
      iVar1 = FUN_00023424();
      *(undefined4 *)(iVar1 + 0x24) = 1;
      iVar1 = FUN_00023424();
      uVar7 = *(undefined4 *)(iVar1 + 0xa4);
      iVar1 = FUN_00023424();
      *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x1ae6) = uVar7;
      iVar1 = FUN_00023424();
      iVar5 = FUN_00023424();
      FUN_0001b73c(*(int *)(iVar5 + 0x5c) + 0x10,*(undefined4 *)(iVar1 + 0xa4));
      local_840 = L'\0';
      memset(auStack_83e,0,0x81e);
      iVar1 = FUN_00023424();
      iVar5 = FUN_00023424();
      FUN_00012bd8(*(undefined4 *)(iVar5 + 0x58),*(undefined4 *)(iVar1 + 0xa4),&local_840);
      if (local_840 != L'\\') {
        local_a48 = L'\0';
        memset(auStack_a46,0,0x206);
        swprintf(&local_a48,0x2a028,&local_840);
        memcpy(&local_840,&local_a48,0x208);
      }
      iVar1 = FUN_00023424();
      FUN_0001ba08(*(int *)(iVar1 + 0x5c) + 0x10,&local_840);
      iVar1 = FUN_00023424();
      iVar5 = FUN_00023424();
      uVar7 = FUN_00012bbc(*(undefined4 *)(iVar5 + 0x58),*(undefined4 *)(iVar1 + 0xa4));
      uVar6 = FUN_00011908();
      FUN_000114d8(uVar6,&local_840,uVar7);
      iVar1 = FUN_00023424();
      FUN_0001ac88(*(int *)(iVar1 + 0x5c) + 0x10);
    }
    break;
  case 0x86:
    uVar8 = *param_5;
    iVar1 = FUN_00023424();
    *(uint *)(iVar1 + 0x40) = uVar8;
    break;
  case 0x87:
    uVar8 = *param_5;
    if (uVar8 != 0) {
      iVar1 = FUN_00023424();
      FUN_00019960(*(int *)(iVar1 + 0x5c) + 0x10);
      iVar1 = FUN_00023424();
      FUN_00019924(*(int *)(iVar1 + 0x5c) + 0x10);
    }
    iVar1 = FUN_00023424();
    *(uint *)(iVar1 + 0x44) = uVar8;
    break;
  case 0x88:
    iVar1 = FUN_00023424();
    if (0 < *(int *)(iVar1 + 0x48)) {
      iVar1 = FUN_00023424();
      FUN_0001c66c(*(int *)(iVar1 + 0x5c) + 0x10,L"\\Storage Card2\\USBMusicResume.dat");
    }
  }
  FUN_00025660(local_20);
  return 1;
}



/* 00022538 FUN_00022538 */

/* Boundary evidence: original MIPS .pdata 00022538..00022623. Semantic name remains unreviewed. */

undefined4 FUN_00022538(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_18 [16];
  
  puVar1 = (uint *)FUN_000234dc(auStack_18,param_3,param_4,&stack0x00000010);
  uVar3 = *puVar1 & 0xffff;
  uVar2 = 1;
  if (uVar3 == 1) {
    uVar2 = FUN_000218e8(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  }
  else if (uVar3 == 5) {
    uVar2 = FUN_00020f78(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  }
  else if (uVar3 == 0x15) {
    uVar2 = FUN_000219fc(param_1,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
  }
  return uVar2;
}



/* 00022624 FUN_00022624 */

/* Boundary evidence: original MIPS .pdata 00022624..0002267b. Semantic name remains unreviewed. */

undefined4 * FUN_00022624(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b9a0;
  FUN_000207f4(param_1 + 1);
  FUN_000219e4(param_1 + 0x106);
  return param_1;
}



/* 0002267c Unwind@0002267c */

/* Boundary evidence: original MIPS .pdata 0002267c..000226af. Semantic name remains unreviewed. */

void Unwind_0002267c(void)

{
  int *in_v0;
  
  FUN_000207e4(*in_v0 + 4);
  return;
}



/* 000226b0 FUN_000226b0 */

/* Boundary evidence: original MIPS .pdata 000226b0..00022707. Semantic name remains unreviewed. */

void FUN_000226b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b9a0;
  FUN_000207e4(param_1 + 0x106);
  FUN_000207e4(param_1 + 1);
  return;
}



/* 00022708 Unwind@00022708 */

/* Boundary evidence: original MIPS .pdata 00022708..0002273b. Semantic name remains unreviewed. */

void Unwind_00022708(void)

{
  int *in_v0;
  
  FUN_000207e4(*in_v0 + 4);
  return;
}



/* 0002273c FUN_0002273c */

/* Boundary evidence: original MIPS .pdata 0002273c..000227a7. Semantic name remains unreviewed. */

void FUN_0002273c(void)

{
  int iVar1;
  
  if (DAT_006b83b8 == 0) {
    iVar1 = __2_YAPAXI_Z(0x420);
    if (iVar1 == 0) {
      DAT_006b83b8 = 0;
    }
    else {
      DAT_006b83b8 = FUN_00022624(iVar1);
    }
  }
  return;
}



/* 000227a8 Unwind@000227a8 */

/* Boundary evidence: original MIPS .pdata 000227a8..000227d7. Semantic name remains unreviewed. */

void Unwind_000227a8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 000227d8 FUN_000227d8 */

/* Boundary evidence: original MIPS .pdata 000227d8..000228b7. Semantic name remains unreviewed. */

undefined4
FUN_000227d8(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_3 == 0x113) || (param_3 == 0x8001)) {
    uVar1 = FUN_00011908();
    FUN_00011d40(uVar1,param_5);
  }
  else if (param_3 == 0x8002) {
    FUN_00020854(param_1 + 4,param_2,0x8002,param_4,param_5);
    FUN_000235a8(5,2,L"%S Receive WM_DEVICE_NOTYFY Msg message = %d , wParam = %d , lParam = %d ",
                 "CMsgHandler::msgHandler",0x8002,param_4,param_5);
  }
  else if (param_3 == 0x8064) {
    FUN_00022538(param_1 + 0x418,param_2,0x8064,param_4,param_5);
  }
  return 1;
}



/* 000228b8 FUN_000228b8 */

/* Boundary evidence: original MIPS .pdata 000228b8..00022903. Semantic name remains unreviewed. */

undefined4 FUN_000228b8(undefined4 param_1,uint param_2)

{
  FUN_000226b0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00022904 FUN_00022904 */

undefined4 * FUN_00022904(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0xb] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  return param_1;
}



/* 00022944 FUN_00022944 */

/* Boundary evidence: original MIPS .pdata 00022944..00022ae7. Semantic name remains unreviewed. */

void FUN_00022944(int param_1)

{
  DAT_006b83c8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  EventModify(DAT_006b83c4,3);
  WaitForSingleObject(DAT_006b83c8,1000);
  EventModify(DAT_006b83bc,3);
  EventModify(DAT_006b83c0,3);
  EventModify(DAT_006b83d8,3);
  EventModify(DAT_006b83e4,3);
  CloseHandle(*(HANDLE *)(param_1 + 0x10));
  CloseHandle(*(HANDLE *)(param_1 + 0x14));
  CloseHandle(DAT_006b83c4);
  CloseHandle(*(HANDLE *)(param_1 + 0xc));
  CloseHandle(*(HANDLE *)(param_1 + 0x2c));
  CloseHandle(DAT_006b83c8);
  CloseHandle(DAT_006b83bc);
  CloseHandle(DAT_006b83c0);
  CloseHandle(*(HANDLE *)(param_1 + 0x18));
  CloseHandle(*(HANDLE *)(param_1 + 0x1c));
  CloseHandle(DAT_006b83dc);
  CloseHandle(DAT_006b83e0);
  CloseHandle(*(HANDLE *)(param_1 + 0x28));
  CloseHandle(DAT_006b83d8);
  CloseHandle(DAT_006b83e4);
  return;
}



/* 00022ae8 FUN_00022ae8 */

/* Boundary evidence: original MIPS .pdata 00022ae8..00022bb3. Semantic name remains unreviewed. */

void FUN_00022ae8(void)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)&DAT_006b83c0,100,8,0);
    if (DVar1 == 0) break;
    DVar1 = WaitForSingleObject(DAT_006b83d0,500);
    if (DVar1 == 0) {
      iVar2 = FUN_00023424();
      uVar3 = *(undefined4 *)(*(int *)(iVar2 + 0x5c) + 0x1aee);
      iVar2 = FUN_00023424();
      FUN_0001da98(*(undefined4 *)(iVar2 + 0x5c),uVar3,0);
      EventModify(DAT_006b83d0,2);
    }
    else {
      Sleep(100);
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022bb4 FUN_00022bb4 */

/* Boundary evidence: original MIPS .pdata 00022bb4..00022c77. Semantic name remains unreviewed. */

void FUN_00022bb4(void)

{
  DWORD DVar1;
  int iVar2;
  
  while( true ) {
    DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)&DAT_006b83bc,100,8,0);
    if (DVar1 == 0) break;
    DVar1 = WaitForSingleObject(DAT_006b83cc,500);
    if (DVar1 == 0) {
      iVar2 = FUN_00023424();
      FUN_0001ed70(*(undefined4 *)(iVar2 + 0x5c),1);
      EventModify(DAT_006b83cc,2);
    }
    else {
      Sleep(100);
    }
  }
  EventModify(DAT_006b83c8,3);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022c78 FUN_00022c78 */

/* Boundary evidence: original MIPS .pdata 00022c78..00022d47. Semantic name remains unreviewed. */

void FUN_00022c78(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  while( true ) {
    DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)&DAT_006b83d8,100,8,0);
    if (DVar1 == 0) break;
    DVar1 = WaitForSingleObject(DAT_006b83dc,500);
    if (DVar1 == 0) {
      iVar2 = FUN_00023424();
      iVar3 = FUN_00023424();
      FUN_0001fac4(*(undefined4 *)(iVar3 + 0x5c),*(undefined4 *)(iVar2 + 0x14));
      EventModify(DAT_006b83dc,2);
    }
    else {
      Sleep(100);
    }
  }
  EventModify(DAT_006b83c8,3);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022d48 FUN_00022d48 */

/* Boundary evidence: original MIPS .pdata 00022d48..00022dfb. Semantic name remains unreviewed. */

void FUN_00022d48(void)

{
  DWORD DVar1;
  
  while( true ) {
    DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)&DAT_006b83e4,100,8,0);
    if (DVar1 == 0) break;
    DVar1 = WaitForSingleObject(DAT_006b83e0,500);
    if (DVar1 == 0) {
      Sleep(500);
      EventModify(DAT_006b83e0,2);
    }
    else {
      Sleep(100);
    }
  }
  EventModify(DAT_006b83c8,3);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00022dfc FUN_00022dfc */

/* Boundary evidence: original MIPS .pdata 00022dfc..00022e57. Semantic name remains unreviewed. */

void FUN_00022dfc(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 == 2000) {
    pwVar1 = L"%S USB_EVENT_SEARCH_START";
  }
  else {
    if (param_1 != 0x7d1) {
      return;
    }
    pwVar1 = L"%S USB_EVENT_ATTACHED";
  }
  FUN_000235a8(5,1,pwVar1,"CUSBThreadHandler::ProcessUSBEvent");
  return;
}



/* 00022e58 FUN_00022e58 */

/* Boundary evidence: original MIPS .pdata 00022e58..00022ebf. Semantic name remains unreviewed. */

bool FUN_00022e58(int param_1)

{
  HANDLE pvVar1;
  
  EventModify(DAT_006b83bc,2);
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022bb4,(LPVOID)0x0,0,
                        (LPDWORD)(param_1 + 4));
  *(HANDLE *)(param_1 + 0x18) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 00022ec0 FUN_00022ec0 */

/* Boundary evidence: original MIPS .pdata 00022ec0..00022f27. Semantic name remains unreviewed. */

bool FUN_00022ec0(int param_1)

{
  HANDLE pvVar1;
  
  EventModify(DAT_006b83c0,2);
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022ae8,(LPVOID)0x0,0,
                        (LPDWORD)(param_1 + 8));
  *(HANDLE *)(param_1 + 0x1c) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 00022f28 FUN_00022f28 */

/* Boundary evidence: original MIPS .pdata 00022f28..00022f7f. Semantic name remains unreviewed. */

bool FUN_00022f28(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022c78,(LPVOID)0x0,0,
                        (LPDWORD)(param_1 + 0x20));
  *(HANDLE *)(param_1 + 0x28) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 00022f80 FUN_00022f80 */

/* Boundary evidence: original MIPS .pdata 00022f80..00022fd7. Semantic name remains unreviewed. */

bool FUN_00022f80(int param_1)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00022d48,(LPVOID)0x0,0,
                        (LPDWORD)(param_1 + 0x24));
  *(HANDLE *)(param_1 + 0x2c) = pvVar1;
  return pvVar1 != (HANDLE)0x0;
}



/* 00022fd8 FUN_00022fd8 */

/* Boundary evidence: original MIPS .pdata 00022fd8..00023033. Semantic name remains unreviewed. */

void FUN_00022fd8(int param_1)

{
  EventModify(DAT_006b83c0,3);
  Sleep(1);
  TerminateThread(*(HANDLE *)(param_1 + 0x1c),0);
  CloseHandle(*(HANDLE *)(param_1 + 0x1c));
  return;
}



/* 00023034 FUN_00023034 */

/* Boundary evidence: original MIPS .pdata 00023034..0002308f. Semantic name remains unreviewed. */

void FUN_00023034(int param_1)

{
  EventModify(DAT_006b83bc,3);
  Sleep(1);
  TerminateThread(*(HANDLE *)(param_1 + 0x18),0);
  CloseHandle(*(HANDLE *)(param_1 + 0x18));
  return;
}



/* 00023090 FUN_00023090 */

/* Boundary evidence: original MIPS .pdata 00023090..000230eb. Semantic name remains unreviewed. */

void FUN_00023090(int param_1)

{
  EventModify(DAT_006b83d8,3);
  Sleep(1);
  TerminateThread(*(HANDLE *)(param_1 + 0x28),0);
  CloseHandle(*(HANDLE *)(param_1 + 0x28));
  return;
}



/* 000230ec FUN_000230ec */

/* Boundary evidence: original MIPS .pdata 000230ec..0002310f. Semantic name remains unreviewed. */

void FUN_000230ec(void)

{
  EventModify(DAT_006b83d0,3);
  return;
}



/* 00023110 FUN_00023110 */

/* Boundary evidence: original MIPS .pdata 00023110..00023133. Semantic name remains unreviewed. */

void FUN_00023110(void)

{
  EventModify(DAT_006b83d0,2);
  return;
}



/* 00023134 FUN_00023134 */

/* Boundary evidence: original MIPS .pdata 00023134..00023157. Semantic name remains unreviewed. */

void FUN_00023134(void)

{
  EventModify(DAT_006b83cc,3);
  return;
}



/* 00023158 FUN_00023158 */

/* Boundary evidence: original MIPS .pdata 00023158..0002317b. Semantic name remains unreviewed. */

void FUN_00023158(void)

{
  EventModify(DAT_006b83cc,2);
  return;
}



/* 0002317c FUN_0002317c */

/* Boundary evidence: original MIPS .pdata 0002317c..0002319f. Semantic name remains unreviewed. */

void FUN_0002317c(void)

{
  EventModify(DAT_006b83dc,3);
  return;
}



/* 000231a0 FUN_000231a0 */

/* Boundary evidence: original MIPS .pdata 000231a0..00023273. Semantic name remains unreviewed. */

void FUN_000231a0(void)

{
  DWORD DVar1;
  int iVar2;
  tagMSG tStack_30;
  
  while (DVar1 = MsgWaitForMultipleObjectsEx(1,(HANDLE *)&DAT_006b83c4,100,8,0), DVar1 != 0) {
    if ((DVar1 == 1) || (DVar1 == 0x102)) {
      iVar2 = PeekMessageW(&tStack_30,(HWND)0xffffffff,0,0,1);
      while (iVar2 != 0) {
        if (tStack_30.message == 0x8018) {
          FUN_00022dfc(tStack_30.lParam);
        }
        iVar2 = PeekMessageW(&tStack_30,(HWND)0xffffffff,0,0,1);
      }
    }
  }
  EventModify(DAT_006b83c8,3);
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}



/* 00023274 FUN_00023274 */

/* Boundary evidence: original MIPS .pdata 00023274..00023423. Semantic name remains unreviewed. */

void FUN_00023274(int param_1)

{
  HANDLE pvVar1;
  
  DAT_006b83dc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83d8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83e0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83e4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 0x10) = pvVar1;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)(param_1 + 0x14) = pvVar1;
  DAT_006b83c4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83bc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83c0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83cc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_006b83d0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000231a0,(LPVOID)0x0,0,
                        (LPDWORD)&DAT_006b83d4);
  *(HANDLE *)(param_1 + 0xc) = pvVar1;
  return;
}



/* 00023424 FUN_00023424 */

undefined4 FUN_00023424(void)

{
  return DAT_006b85d8;
}



/* 00023430 FUN_00023430 */

/* Boundary evidence: original MIPS .pdata 00023430..000234db. Semantic name remains unreviewed. */

void FUN_00023430(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 1;
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 1;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  uVar1 = FUN_000144b8();
  *(undefined4 *)(param_1 + 0x58) = uVar1;
  uVar1 = FUN_0001eccc();
  *(undefined4 *)(param_1 + 0x94) = 1;
  *(undefined4 *)(param_1 + 0x9c) = 1;
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return;
}



/* 000234dc FUN_000234dc */

/* Boundary evidence: original MIPS .pdata 000234dc..000235a7. Semantic name remains unreviewed. */

ushort * FUN_000234dc(ushort *param_1,int param_2,uint param_3,undefined4 *param_4)

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



/* 000235a8 FUN_000235a8 */

/* Boundary evidence: original MIPS .pdata 000235a8..0002370f. Semantic name remains unreviewed. */

void FUN_000235a8(int param_1,int param_2,wchar_t *param_3,undefined4 param_4)

{
  LPSYSTEMTIME lpSystemTime;
  DWORD DVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  undefined4 local_resc;
  wchar_t awStack_1020 [1024];
  WCHAR aWStack_820 [1024];
  undefined4 local_20;
  
  local_20 = DAT_0002f964;
  local_resc = param_4;
  if ((param_2 == 3) ||
     ((*(int *)(&DAT_006b83e8 + param_1 * 4) != 0 &&
      (*(int *)(&DAT_006b848c + param_1 * 4) <= param_2)))) {
    vswprintf_s(awStack_1020,0x400,param_3,(va_list)&local_resc);
    lpSystemTime = (LPSYSTEMTIME)__2_YAPAXI_Z(0x10);
    GetLocalTime(lpSystemTime);
    if (param_1 < 0x29) {
      pwVar3 = u_MgrDbg_0002f444 + param_1 * 0x10;
    }
    else {
      pwVar3 = u_MgrDbg_0002f444;
    }
    DVar1 = GetTickCount();
    DVar2 = GetTickCount();
    wsprintfW(aWStack_820,L"[%02d:%02d:%02d:%d,%05d][%s] %s\r\n",(uint)lpSystemTime->wHour,
              (uint)lpSystemTime->wMinute,(uint)lpSystemTime->wSecond,DVar2 % 1000,DVar1 / 10,pwVar3
              ,awStack_1020);
    __3_YAXPAX_Z(lpSystemTime);
    OutputDebugStringW(aWStack_820);
  }
  FUN_00025660(local_20);
  return;
}



/* 00023710 FUN_00023710 */

/* Boundary evidence: original MIPS .pdata 00023710..0002376b. Semantic name remains unreviewed. */

wchar_t * FUN_00023710(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x29) {
    pwVar1 = u_MgrDbg_0002f444 + param_1 * 0x10;
  }
  else {
    FUN_000235a8(0x25,3,L"%S fail iPid=%d","IntGetProcessName",param_1);
    pwVar1 = u_MgrDbg_0002f444;
  }
  return pwVar1;
}



/* 0002376c FUN_0002376c */

/* Boundary evidence: original MIPS .pdata 0002376c..0002381b. Semantic name remains unreviewed. */

int * FUN_0002376c(int param_1)

{
  LPCWSTR lpClassName;
  HWND pHVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = (int *)(&DAT_006b8534 + param_1 * 4);
  if (*piVar4 == 0) {
    lpClassName = (LPCWSTR)FUN_00023710(param_1);
    pHVar1 = FindWindowW(lpClassName,(LPCWSTR)0x0);
    *piVar4 = (int)pHVar1;
    if (pHVar1 == (HWND)0x0) {
      DVar2 = GetLastError();
      uVar3 = FUN_00023710(param_1);
      FUN_000235a8(0x25,3,L"%S FindWindow fail, %s(%d), errCode=%d","IntGetProcessHandle",uVar3,
                   param_1,DVar2);
    }
  }
  return piVar4;
}



/* 0002381c FUN_0002381c */

/* Boundary evidence: original MIPS .pdata 0002381c..00023a4f. Semantic name remains unreviewed. */

undefined4 FUN_0002381c(uint param_1,undefined4 param_2,int param_3,uint param_4,LPARAM *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  LPARAM lParam;
  HWND hWnd;
  LPARAM local_30 [2];
  
  local_30[0] = 0;
  puVar1 = (undefined4 *)FUN_0002376c(param_2);
  hWnd = (HWND)*puVar1;
  if (hWnd == (HWND)0x0) {
    uVar2 = FUN_00023710(param_2);
    FUN_000235a8(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcPostMsg"
                 ,uVar2,param_1,param_2,param_3);
  }
  else {
    if (param_4 < 5) {
      memcpy(local_30,param_5,param_4);
      lParam = local_30[0];
    }
    else {
      FUN_000235a8(0x25,3,L"%S extra data overflow, size=%d","IpcPostMsg",param_4);
      lParam = *param_5;
    }
    BVar3 = PostMessageW(hWnd,0x8064,(param_3 << 8 | param_1) << 8 | param_4,lParam);
    if (BVar3 != 0) {
      if (param_3 != 0x65) {
        uVar2 = FUN_00023710(param_2);
        uVar5 = FUN_00023710(param_1);
        FUN_000235a8(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcPostMsg",uVar5,uVar2,param_3,param_4
                    );
      }
      return 1;
    }
    DVar4 = GetLastError();
    if (DVar4 == 6) {
      pwVar6 = L"%S invalid handle";
    }
    else if (DVar4 == 0x578) {
      pwVar6 = L"%S invalid window handle";
    }
    else if (DVar4 == 0x583) {
      pwVar6 = L"%S class does not exist";
    }
    else {
      if (DVar4 != 0x5b4) {
        FUN_000235a8(0x25,3,L"%S PostMessage fail, src=%d, dst=%d, cmd=%d, errCode=%d","IpcPostMsg",
                     param_1,param_2,param_3,DVar4);
        return 0;
      }
      pwVar6 = L"%S timed out";
    }
    FUN_000235a8(0x25,3,pwVar6,"IpcPostMsg");
  }
  return 0;
}



/* 00023a50 FUN_00023a50 */

/* Boundary evidence: original MIPS .pdata 00023a50..00023cf3. Semantic name remains unreviewed. */

undefined4 FUN_00023a50(uint param_1,int param_2,int param_3,uint param_4,void *param_5)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  DWORD local_38;
  undefined4 local_34;
  uint local_30;
  uint local_2c;
  void *local_28;
  
  local_38 = 0;
  local_34 = 0;
  piVar1 = (int *)FUN_0002376c(param_2);
  iVar4 = *piVar1;
  if (iVar4 == 0) {
    uVar2 = FUN_00023710(param_2);
    FUN_000235a8(0x25,3,L"%S IntGetProcessHandle fail, proc=%s, src=%d, dst=%d, cmd=%d","IpcSendMsg"
                 ,uVar2,param_1,param_2,param_3);
  }
  else {
    if (param_4 < 5) {
      memcpy(&local_34,param_5,param_4);
      iVar4 = SendMessageTimeout(iVar4,0x8064,(param_3 << 8 | param_1) << 8 | param_4 & 0xff,
                                 local_34,0,0x5dc,&local_38);
    }
    else {
      FUN_000235a8(0x25,3,L"%S extra data send using wm_copydata, size=%d","IpcSendMsg",param_4);
      memset(&local_30,0,0xc);
      local_28 = param_5;
      local_30 = param_1 * 100 + param_2 + 0x8000 | param_3 << 0x10;
      local_2c = param_4;
      iVar4 = SendMessageTimeout(iVar4,0x4a,0,&local_30,0,0x5dc,&local_38);
    }
    if (iVar4 != 0) {
      uVar2 = FUN_00023710(param_2);
      uVar3 = FUN_00023710(param_1);
      FUN_000235a8(0x25,0,L"%S %s -> %s, cmd=%d, size=%d","IpcSendMsg",uVar3,uVar2,param_3,param_4);
      return 1;
    }
    local_38 = GetLastError();
    if (local_38 == 0) {
      FUN_000235a8(0x25,3,L"%S timeout, src=%d, dst=%d, cmd=%d","IpcSendMsg",param_1,param_2,param_3
                  );
    }
    else if (local_38 == 6) {
      FUN_000235a8(0x25,3,L"%S invalid handle, src=%d, dst=%d, cmd=%d","IpcSendMsg",param_1,param_2,
                   param_3);
    }
    else if (local_38 == 0x578) {
      FUN_000235a8(0x25,3,L"%S invalid window handle, src=%d, dst=%d, cmd=%d","IpcSendMsg",param_1,
                   param_2,param_3);
    }
    else {
      FUN_000235a8(0x25,3,L"%S SendMessageTimeout fail, src=%d, dst=%d, cmd=%d, errCode=%d",
                   "IpcSendMsg",param_1,param_2,param_3,local_38);
    }
  }
  return 0;
}



/* 00023cf4 FUN_00023cf4 */

/* Boundary evidence: original MIPS .pdata 00023cf4..00023d47. Semantic name remains unreviewed. */

wchar_t * FUN_00023cf4(int param_1)

{
  wchar_t *pwVar1;
  
  if (param_1 < 0x29) {
    pwVar1 = (wchar_t *)FUN_00023710();
  }
  else {
    FUN_000235a8(0x25,3,L"%S overflow, pid=%d","IpcGetProcessName",param_1);
    pwVar1 = u_MgrDbg_0002f444;
  }
  return pwVar1;
}



/* 00023d48 FUN_00023d48 */

void FUN_00023d48(int param_1,undefined4 param_2)

{
  if (param_1 < 0x29) {
    *(undefined4 *)(&DAT_006b83e8 + param_1 * 4) = param_2;
  }
  return;
}



/* 00023d70 FUN_00023d70 */

void FUN_00023d70(int param_1,undefined4 param_2)

{
  if (param_1 < 0x29) {
    *(undefined4 *)(&DAT_006b848c + param_1 * 4) = param_2;
  }
  return;
}



/* 00023d98 FUN_00023d98 */

/* Boundary evidence: original MIPS .pdata 00023d98..00023e2b. Semantic name remains unreviewed. */

void FUN_00023d98(int param_1,void *param_2,int param_3,size_t param_4)

{
  if (*(int *)(param_1 + 8) == 0) {
    FUN_000235a8(0x26,3,L"%S m_lpvMapView=NULL","CSharedMem::write");
  }
  else {
    memcpy((void *)(*(int *)(param_1 + 8) + param_3),param_2,param_4);
  }
  return;
}



/* 00023e2c FUN_00023e2c */

/* Boundary evidence: original MIPS .pdata 00023e2c..00023e37. Semantic name remains unreviewed. */

undefined4 FUN_00023e2c(void)

{
  return 1;
}



/* 00023e38 FUN_00023e38 */

/* Boundary evidence: original MIPS .pdata 00023e38..00023ecf. Semantic name remains unreviewed. */

undefined4 FUN_00023e38(undefined4 param_1,HANDLE param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
  FUN_000235a8(0x26,3,L"%S invoked","CSharedMem::releaseShmMutex");
  if ((param_2 != (HANDLE)0x0) && (BVar1 = ReleaseMutex(param_2), BVar1 == 0)) {
    DVar2 = GetLastError();
    FUN_000235a8(0x26,3,L"%S ReleaseMutex fail, error=%d","CSharedMem::releaseShmMutex",DVar2);
  }
  return 1;
}



/* 00023ed0 FUN_00023ed0 */

/* Boundary evidence: original MIPS .pdata 00023ed0..00023fa7. Semantic name remains unreviewed. */

undefined4 FUN_00023ed0(int *param_1,LPCWSTR param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,1,param_2);
  *param_1 = (int)pvVar1;
  DVar2 = GetLastError();
  if (*param_1 == 0) {
    FUN_000235a8(0x26,3,L"%S CreateMutex(%s) error = %d","CSharedMem::createShmMutex",param_2,DVar2)
    ;
    uVar3 = 0;
  }
  else if (DVar2 == 0xb7) {
    FUN_000235a8(0x26,3,L"%S CreateMutex(%s) already exist","CSharedMem::createShmMutex",param_2);
  }
  else {
    FUN_00023e38(param_1);
  }
  return uVar3;
}



/* 00023fa8 FUN_00023fa8 */

/* Boundary evidence: original MIPS .pdata 00023fa8..000241b7. Semantic name remains unreviewed. */

bool FUN_00023fa8(undefined4 *param_1,LPCWSTR param_2,DWORD param_3,HANDLE param_4)

{
  DWORD DVar1;
  HANDLE hFileMappingObject;
  DWORD DVar2;
  LPVOID pvVar3;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_000235a8(0x26,3,L"%S lpName=%s, m_hxMutex=NULL","CSharedMem::createShmMappingReadWrite",
                 param_2);
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,2000);
    if (DVar1 == 0) {
      hFileMappingObject =
           CreateFileMappingW(param_4,(LPSECURITY_ATTRIBUTES)0x0,4,0,param_3,param_2);
      param_1[1] = hFileMappingObject;
      if (hFileMappingObject != (HANDLE)0x0) {
        pvVar3 = MapViewOfFile(hFileMappingObject,0xf001f,0,0,0);
        param_1[2] = pvVar3;
        if (pvVar3 != (LPVOID)0x0) {
          FUN_000235a8(0x26,3,L"%S lpName=%s success","CSharedMem::createShmMappingReadWrite",
                       param_2);
        }
        else {
          DVar1 = GetLastError();
          FUN_000235a8(0x26,3,L"%S lpName=%s, MapViewOfFile fail, error=%d",
                       "CSharedMem::createShmMappingReadWrite",param_2,DVar1);
          CloseHandle((HANDLE)param_1[1]);
          param_1[1] = 0;
        }
        FUN_00023e38(param_1,*param_1);
        return pvVar3 != (LPVOID)0x0;
      }
      DVar2 = GetLastError();
      DVar1 = DVar2;
      FUN_000235a8(0x26,3,L"%S lpName=%s, CreateFileMapping fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite",param_2,DVar2);
      if (DVar2 == 0xb7) {
        FUN_000235a8(0x26,3,L"%S has already been made","CSharedMem::createShmMappingReadWrite",
                     param_2,DVar1);
      }
      FUN_00023e38(param_1,*param_1);
    }
    else {
      DVar1 = GetLastError();
      FUN_000235a8(0x26,3,L"%S lpName=%s, WaitForSingleObject fail, error=%d",
                   "CSharedMem::createShmMappingReadWrite",param_2,DVar1);
    }
  }
  return false;
}



/* 000241b8 FUN_000241b8 */

/* Boundary evidence: original MIPS .pdata 000241b8..000241e7. Semantic name remains unreviewed. */

bool FUN_000241b8(void)

{
  int iVar1;
  
  iVar1 = FUN_00023fa8();
  return iVar1 != 0;
}



/* 000241e8 FUN_000241e8 */

/* Boundary evidence: original MIPS .pdata 000241e8..00024203. Semantic name remains unreviewed. */

void FUN_000241e8(void)

{
  FUN_00023d98();
  return;
}



/* 00024204 FUN_00024204 */

/* Boundary evidence: original MIPS .pdata 00024204..0002425b. Semantic name remains unreviewed. */

undefined4 * FUN_00024204(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002bb88;
  FUN_00022904(param_1 + 0x18);
  FUN_00023430(param_1);
  return param_1;
}



/* 0002425c Unwind@0002425c */

/* Boundary evidence: original MIPS .pdata 0002425c..0002428f. Semantic name remains unreviewed. */

void Unwind_0002425c(void)

{
  int *in_v0;
  
  FUN_000207e4(*in_v0 + 0x60);
  return;
}



/* 00024290 FUN_00024290 */

/* Boundary evidence: original MIPS .pdata 00024290..000242e7. Semantic name remains unreviewed. */

undefined4 * FUN_00024290(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0002bb88;
  FUN_000207e4(param_1 + 0x18);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000242e8 FUN_000242e8 */

/* Boundary evidence: original MIPS .pdata 000242e8..00024353. Semantic name remains unreviewed. */

void FUN_000242e8(void)

{
  int iVar1;
  
  if (DAT_006b8530 == 0) {
    iVar1 = __2_YAPAXI_Z(0xac);
    if (iVar1 == 0) {
      DAT_006b8530 = 0;
    }
    else {
      DAT_006b8530 = FUN_00024204(iVar1);
    }
  }
  return;
}



/* 00024354 Unwind@00024354 */

/* Boundary evidence: original MIPS .pdata 00024354..00024383. Semantic name remains unreviewed. */

void Unwind_00024354(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00024384 FUN_00024384 */

/* Boundary evidence: original MIPS .pdata 00024384..000244b3. Semantic name remains unreviewed. */

void FUN_00024384(undefined4 *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
  if ((HANDLE)*param_1 == (HANDLE)0x0) {
    FUN_000235a8(0x26,3,L"%S already mutex=NULL","CSharedMem::closeShmMapping");
  }
  else {
    DVar1 = WaitForSingleObject((HANDLE)*param_1,2000);
    if (DVar1 == 0) {
      FUN_00023e38(param_1,*param_1);
    }
    else {
      DVar1 = GetLastError();
      FUN_000235a8(0x26,3,L"%S WaitForSingleObject fail, error=%d","CSharedMem::closeShmMapping",
                   DVar1);
    }
    CloseHandle((HANDLE)*param_1);
  }
  if (((LPCVOID)param_1[2] != (LPCVOID)0x0) &&
     (BVar2 = UnmapViewOfFile((LPCVOID)param_1[2]), BVar2 == 0)) {
    DVar1 = GetLastError();
    FUN_000235a8(0x26,3,L"%S UnmapViewOfFile fail, error=%d","CSharedMem::closeShmMapping",DVar1);
  }
  if ((HANDLE)param_1[1] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[1]);
  }
  return;
}



/* 000244b4 FUN_000244b4 */

/* Boundary evidence: original MIPS .pdata 000244b4..0002455b. Semantic name remains unreviewed. */

undefined4 * FUN_000244b4(undefined4 param_1)

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
    FUN_000235a8(0x26,3,L"%S not created","MSHM_Dll_CreateShmClassObj");
  }
  else {
    iVar2 = FUN_00023ed0(puVar1,param_1);
    if (iVar2 == 0) {
      FUN_00024384(puVar1);
      __3_YAXPAX_Z(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}



/* 0002455c FUN_0002455c */

/* Boundary evidence: original MIPS .pdata 0002455c..000245cb. Semantic name remains unreviewed. */

bool FUN_0002455c(LPCWSTR param_1)

{
  DWORD DVar1;
  
  DAT_006b85dc = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_1);
  DVar1 = GetLastError();
  if (DVar1 == 0xb7) {
    CloseHandle(DAT_006b85dc);
  }
  return DVar1 != 0xb7;
}



/* 000245cc FUN_000245cc */

/* Boundary evidence: original MIPS .pdata 000245cc..0002466f. Semantic name remains unreviewed. */

bool FUN_000245cc(HINSTANCE param_1)

{
  LPCWSTR lpWindowName;
  LPCWSTR lpClassName;
  HWND hWnd;
  
  lpWindowName = (LPCWSTR)FUN_00023cf4(5);
  lpClassName = (LPCWSTR)FUN_00023cf4(5);
  hWnd = CreateWindowExW(0x4000000,lpClassName,lpWindowName,0x2000000,0,0,800,0x1e0,(HWND)0x0,
                         (HMENU)0x0,param_1,(LPVOID)0x0);
  if (hWnd != (HWND)0x0) {
    ShowWindow(hWnd,0);
    UpdateWindow(hWnd);
  }
  return hWnd != (HWND)0x0;
}



/* 00024670 FUN_00024670 */

/* Boundary evidence: original MIPS .pdata 00024670..00024abb. Semantic name remains unreviewed. */

LRESULT FUN_00024670(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_60 [2];
  undefined1 auStack_58 [24];
  undefined1 auStack_40 [40];
  
  FUN_00024cc4(auStack_40);
  if (param_2 == 1) {
    FUN_00023d48(5,1);
    FUN_00023d70(5,2);
    FUN_000235a8(5,0,L"%S MgrUSB Create","WndProc");
    FUN_000235a8(5,3,L"*******************MgrUsb ver:%S %S******************","May  1 2015",
                 "15:12:09");
    iVar3 = FUN_00023424();
    *(HWND *)(iVar3 + 0x4c) = param_1;
    uVar2 = FUN_000244b4(L"ShmMxMgrUsbAppMain");
    iVar3 = FUN_00023424();
    *(undefined4 *)(iVar3 + 0x50) = uVar2;
    iVar3 = FUN_00023424();
    FUN_000241b8(*(undefined4 *)(iVar3 + 0x50),L"ShmFmMgrUsbAppMain",0xe56,0xffffffff);
    uVar2 = FUN_000244b4(L"ShmMxMgrUsbAppMainList");
    iVar3 = FUN_00023424();
    *(undefined4 *)(iVar3 + 0x54) = uVar2;
    iVar3 = FUN_00023424();
    FUN_000241b8(*(undefined4 *)(iVar3 + 0x54),L"ShmFmMgrUsbAppMainList",&DAT_000977fc,0xffffffff);
    iVar3 = FUN_00023424();
    FUN_00023274(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_00022f80(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_00022f28(iVar3 + 0x60);
    iVar3 = FUN_00023424();
    FUN_00022ec0(iVar3 + 0x60);
    FUN_00024dbc(auStack_40,0xf5,0xf6,0xf7,0xf8,0xf7);
    uVar2 = FUN_00011908();
    FUN_00011000(uVar2);
    uVar2 = FUN_00011908();
    FUN_0001189c(uVar2,param_1);
    iVar3 = FUN_00023424();
    if (*(int *)(iVar3 + 0x14) != 0) {
      SetTimer(param_1,10,5000,(TIMERPROC)0x0);
    }
    FUN_000206b8(&DAT_006b85e0,param_1,0x8002);
    iVar3 = FUN_00023424();
    uVar2 = FUN_000120a0();
    FUN_000235a8(5,3,L"%S  Memory Use : %s m_bBootResumeCmd : %d ","WndProc",uVar2,
                 *(undefined4 *)(iVar3 + 0x14));
  }
  else if (param_2 == 2) {
    FUN_00020388(&DAT_006b85e0);
    iVar3 = FUN_00023424();
    FUN_00022944(iVar3 + 0x60);
    PostQuitMessage(0);
    if (DAT_006b85dc != 0) {
      CloseHandle((HANDLE)DAT_006b85dc);
    }
  }
  else if (param_2 == 0x113) {
    if (param_3 == 10) {
      KillTimer(param_1,10);
      iVar3 = FUN_00023424();
      iVar3 = FUN_00012efc(*(undefined4 *)(iVar3 + 0x58),&DAT_00027b78,auStack_58,0);
      if (iVar3 == 0) {
        iVar3 = FUN_00023424();
        *(undefined4 *)(iVar3 + 0x14) = 0;
        iVar3 = FUN_00023424();
        *(undefined4 *)(iVar3 + 0x18) = 1;
        iVar3 = FUN_00023424();
        FUN_00023090(iVar3 + 0x60);
        iVar3 = FUN_00023424();
        *(undefined4 *)(iVar3 + 0x48) = 0;
        memset(local_60,0,4);
        local_60[0] = local_60[0] & 0xffe01033 | 0x1033;
        FUN_000235a8(5,0,L"%S  line %d BOOT Resume Fail","WndProc",0xd5);
        iVar3 = FUN_00023424();
        if (*(int *)(iVar3 + 0x20) == 0) {
          FUN_0002381c(5,1,9,4,local_60);
        }
      }
    }
    else {
      uVar2 = FUN_0001eccc();
      FUN_0002008c(uVar2,param_3);
    }
  }
  else {
    if (param_2 != 0x219) {
      if (param_2 == 0x8001) {
        uVar2 = FUN_00011908();
        FUN_00011d40(uVar2,param_4);
        goto LAB_00024a84;
      }
      if ((param_2 != 0x8002) && (param_2 != 0x8064)) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        goto LAB_00024a88;
      }
    }
    uVar2 = FUN_0002273c();
    FUN_000227d8(uVar2,param_1,param_2,param_3,param_4);
  }
LAB_00024a84:
  LVar1 = 0;
LAB_00024a88:
  FUN_000207e4(auStack_40);
  return LVar1;
}



/* 00024abc Unwind@00024abc */

/* Boundary evidence: original MIPS .pdata 00024abc..00024aeb. Semantic name remains unreviewed. */

void Unwind_00024abc(void)

{
  int in_v0;
  
  FUN_000207e4(in_v0 + -0x40);
  return;
}



/* 00024aec FUN_00024aec */

/* Boundary evidence: original MIPS .pdata 00024aec..00024b43. Semantic name remains unreviewed. */

void FUN_00024aec(HINSTANCE param_1)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00024670;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hbrBackground = (HBRUSH)0x0;
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.hInstance = param_1;
  local_30.lpszClassName = (LPCWSTR)FUN_00023cf4(5);
  RegisterClassW(&local_30);
  return;
}



/* 00024b44 FUN_00024b44 */

/* Boundary evidence: original MIPS .pdata 00024b44..00024cc3. Semantic name remains unreviewed. */

undefined4 FUN_00024b44(undefined4 param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  BOOL BVar4;
  int iVar5;
  MSG MStack_38;
  
  uVar1 = FUN_00023cf4(5);
  iVar2 = FUN_0002455c(uVar1);
  if (iVar2 == 0) {
    FUN_000235a8(5,0,L"%S process is already running. Execution is ignored!","WinMain");
  }
  else {
    FUN_00024aec(param_1);
    sVar3 = wcslen(param_3);
    if (sVar3 == 0) {
      FUN_000235a8(5,0,L"%S No Boot resume cmd","WinMain");
      iVar2 = FUN_00023424();
      *(undefined4 *)(iVar2 + 0x14) = 0;
    }
    else {
      FUN_000235a8(5,0,L"%S Boot resume cmd","WinMain");
      iVar2 = FUN_00023424();
      *(undefined4 *)(iVar2 + 0x14) = 1;
    }
    uVar1 = FUN_0001216c(0x80000002,L"LGE\\SystemStatus\\USB\\MassStorage",L"Inserted",0);
    iVar2 = FUN_00023424();
    *(undefined4 *)(iVar2 + 0x48) = uVar1;
    iVar2 = FUN_00023424();
    iVar5 = *(int *)(iVar2 + 0x48);
    iVar2 = FUN_00023424();
    *(uint *)(iVar2 + 0x10) = (uint)(iVar5 != 0);
    iVar2 = FUN_000245cc(param_1,param_4);
    if (iVar2 != 0) {
      FUN_0002273c();
      while (BVar4 = GetMessageW(&MStack_38,(HWND)0x0,0,0), BVar4 != 0) {
        TranslateMessage(&MStack_38);
        DispatchMessageW(&MStack_38);
      }
      return MStack_38.wParam;
    }
  }
  return 0;
}



/* 00024cc4 FUN_00024cc4 */

/* Boundary evidence: original MIPS .pdata 00024cc4..00024d07. Semantic name remains unreviewed. */

undefined4 * FUN_00024cc4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0002b0c0;
  param_1[3] = 0;
  memset(param_1 + 4,0,0x14);
  return param_1;
}



/* 00024d08 FUN_00024d08 */

/* Boundary evidence: original MIPS .pdata 00024d08..00024dbb. Semantic name remains unreviewed. */

bool FUN_00024d08(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  HANDLE hFindFile;
  DWORD local_240;
  undefined1 auStack_23c [556];
  WCHAR local_10 [4];
  
  local_10._0_4_ = DAT_0002f964;
  local_240 = 0;
  memset(auStack_23c,0,0x22c);
  sVar1 = wcslen(param_2);
  if (param_2[sVar1 - 1] == L'\n') {
    param_2[sVar1 - 1] = L'\0';
  }
  hFindFile = FindFirstFileW(param_2,(LPWIN32_FIND_DATAW)&local_240);
  if (hFindFile == (HANDLE)0xffffffff) {
    FUN_00025660(local_10._0_4_);
  }
  else {
    FindClose(hFindFile);
    FUN_00025660(local_10._0_4_);
  }
  return hFindFile != (HANDLE)0xffffffff;
}



/* 00024dbc FUN_00024dbc */

/* Boundary evidence: original MIPS .pdata 00024dbc..00024f1b. Semantic name remains unreviewed. */

void FUN_00024dbc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  HKEY local_18 [2];
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,
                        0xf003f,local_18);
  if (LVar1 == 0) {
    LVar1 = RegSetValueExW(local_18[0],L"Highest",0,4,(BYTE *)&local_res4,4);
    if (LVar1 == 0) {
      LVar1 = RegSetValueExW(local_18[0],L"AboveNormal",0,4,(BYTE *)&local_res8,4);
      if (LVar1 == 0) {
        LVar1 = RegSetValueExW(local_18[0],L"Normal",0,4,(BYTE *)&local_resc,4);
        if (LVar1 == 0) {
          LVar1 = RegSetValueExW(local_18[0],L"BelowNormal",0,4,&stack0x00000010,4);
          if (LVar1 == 0) {
            RegSetValueExW(local_18[0],L"Video",0,4,&stack0x00000014,4);
          }
        }
      }
    }
  }
  if (local_18[0] != (HKEY)0x0) {
    RegCloseKey(local_18[0]);
  }
  return;
}



/* 00024f1c FUN_00024f1c */

undefined4 FUN_00024f1c(undefined4 param_1,short *param_2,int param_3)

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



/* 00024f7c FUN_00024f7c */

/* Boundary evidence: original MIPS .pdata 00024f7c..0002502b. Semantic name remains unreviewed. */

undefined4 FUN_00024f7c(int param_1)

{
  FILE *_File;
  size_t sVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  _File = _wfopen(L"/Storage Card2/Lang.cfg",L"rb");
  if (_File == (FILE *)0x0) {
    *(undefined4 *)(param_1 + 4) = 2;
  }
  else {
    uVar2 = 1;
    sVar1 = fread((undefined4 *)(param_1 + 4),1,8,_File);
    fclose(_File);
    if (sVar1 != 8) {
      *(undefined4 *)(param_1 + 4) = 2;
    }
  }
  return uVar2;
}



/* 0002502c FUN_0002502c */

/* Boundary evidence: original MIPS .pdata 0002502c..00025143. Semantic name remains unreviewed. */

UINT FUN_0002502c(int param_1,LPCSTR param_2,LPWSTR param_3,int param_4,int param_5,int param_6)

{
  UINT CodePage;
  
  CodePage = 0x4e4;
  FUN_00024f7c(param_1);
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    CodePage = 0x4e8;
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
    break;
  case 0x1f:
    CodePage = 0x3b5;
  }
  MultiByteToWideChar(CodePage,8,param_2,param_6,param_3,param_4);
  param_3[param_5] = L'\0';
  return CodePage;
}



/* 00025144 FUN_00025144 */

/* Boundary evidence: original MIPS .pdata 00025144..0002529b. Semantic name remains unreviewed. */

wchar_t * FUN_00025144(undefined4 param_1,LPCSTR param_2,wchar_t *param_3,rsize_t param_4)

{
  rsize_t _MaxCount;
  undefined8 uVar1;
  
  if ((*param_2 == -1) || (*param_2 == -0x11)) {
    _MaxCount = 200;
    if ((int)param_4 < 0xc9) {
      uVar1 = __litodp(param_4 - 2);
      uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x3fe00000);
      _MaxCount = __dptoli((int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
    }
    wcsncpy_s(param_3,200,(wchar_t *)(param_2 + 2),_MaxCount);
  }
  else {
    _MaxCount = MultiByteToWideChar(0xfde9,8,param_2,param_4,(LPWSTR)0x0,0);
    if ((int)_MaxCount < 1) {
      FUN_0002502c(param_1,param_2,param_3,param_4,param_4,param_4);
      return param_3;
    }
    if ((int)_MaxCount < (int)param_4) {
      _MaxCount = param_4;
    }
    MultiByteToWideChar(0xfde9,8,param_2,param_4,param_3,_MaxCount);
  }
  param_3[_MaxCount] = L'\0';
  return param_3;
}



/* 0002556c FUN_0002556c */

/* Boundary evidence: original MIPS .pdata 0002556c..000255df. Semantic name remains unreviewed. */

void FUN_0002556c(void)

{
  uint uVar1;
  
  if ((DAT_0002f964 == 0) || (DAT_0002f964 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0002f964 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0002f964 == 0) {
      DAT_0002f964 = 0xb064;
    }
  }
  DAT_0002f968 = ~DAT_0002f964;
  return;
}



/* 000255e0 FUN_000255e0 */

/* Boundary evidence: original MIPS .pdata 000255e0..00025633. Semantic name remains unreviewed. */

void FUN_000255e0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00025660(*(undefined4 *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00025634 FUN_00025634 */

/* Boundary evidence: original MIPS .pdata 00025634..0002565f. Semantic name remains unreviewed. */

undefined4 FUN_00025634(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_000255e0(param_2,param_4,*(undefined4 *)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00025660 FUN_00025660 */

/* Boundary evidence: original MIPS .pdata 00025660..000256a7. Semantic name remains unreviewed. */

void FUN_00025660(uint param_1)

{
  if ((param_1 == DAT_0002f964) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00025788 FUN_00025788 */

/* Boundary evidence: original MIPS .pdata 00025788..000257f7. Semantic name remains unreviewed. */

void FUN_00025788(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_000255e0(param_2,param_4,*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24);
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 00025828 FUN_00025828 */

/* Boundary evidence: original MIPS .pdata 00025828..00025933. Semantic name remains unreviewed. */

undefined4 FUN_00025828(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_006b85fc;
  puVar3 = DAT_006b85f8;
  iVar4 = (int)DAT_006b85f8 - (int)DAT_006b85fc;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0002586c:
    param_1 = 0;
  }
  else {
    if (DAT_006b85fc != (void *)0x0) {
      uVar1 = _msize(DAT_006b85fc);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000258e0:
        if (pvVar2 == (void *)0x0) goto LAB_0002586c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000258e0;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_006b85f8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_006b85fc = pvVar2;
  }
  return param_1;
}



/* 00025934 FUN_00025934 */

/* Boundary evidence: original MIPS .pdata 00025934..00025a1f. Semantic name remains unreviewed. */

undefined4 FUN_00025934(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_006b8600 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_006b8600,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_006b8600 == (LPCRITICAL_SECTION)0x0) goto LAB_000259d8;
  }
  EnterCriticalSection(DAT_006b8600);
LAB_000259d8:
  uVar2 = FUN_00025828(param_1);
  FUN_00025a20(0);
  return uVar2;
}



/* 00025a20 FUN_00025a20 */

/* Boundary evidence: original MIPS .pdata 00025a20..00025a6b. Semantic name remains unreviewed. */

void FUN_00025a20(void)

{
  if (DAT_006b8600 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_006b8600);
  }
  return;
}



/* 00025a6c FUN_00025a6c */

/* Boundary evidence: original MIPS .pdata 00025a6c..00025a9b. Semantic name remains unreviewed. */

undefined4 FUN_00025a6c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00025934();
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00025bac FUN_00025bac */

/* Boundary evidence: original MIPS .pdata 00025bac..00025c3f. Semantic name remains unreviewed. */

void FUN_00025bac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_00025f2c();
  uVar1 = FUN_00024b44(param_1,param_2,param_3,param_4);
  FUN_00025e6c(uVar1);
  FUN_00025e8c(uVar1);
  return;
}



/* 00025c40 FUN_00025c40 */

/* Boundary evidence: original MIPS .pdata 00025c40..00025c7f. Semantic name remains unreviewed. */

void FUN_00025c40(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00025c80 entry */

/* Boundary evidence: original MIPS .pdata 00025c80..00025cdb. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0002556c();
  FUN_00025bac(param_1,param_2,param_3,param_4);
  return;
}



/* 00025d4c FUN_00025d4c */

/* Boundary evidence: original MIPS .pdata 00025d4c..00025e6b. Semantic name remains unreviewed. */

void FUN_00025d4c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_006b85f4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_006b85fc;
    if (DAT_006b85fc != (undefined4 *)0x0) {
      while (DAT_006b85f8 = DAT_006b85f8 + -1, _Memory <= DAT_006b85f8) {
        if ((code *)*DAT_006b85f8 != (code *)0x0) {
          (*(code *)*DAT_006b85f8)();
          _Memory = DAT_006b85fc;
        }
      }
      free(_Memory);
      DAT_006b85f8 = (undefined4 *)0x0;
      DAT_006b85fc = (undefined4 *)0x0;
    }
    FUN_00025ed8(&DAT_00027018,&DAT_0002701c);
  }
  FUN_00025ed8(&DAT_00027020,&DAT_00027024);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_006b8600,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00025e6c FUN_00025e6c */

/* Boundary evidence: original MIPS .pdata 00025e6c..00025e8b. Semantic name remains unreviewed. */

void FUN_00025e6c(undefined4 param_1)

{
  FUN_00025d4c(param_1,0,0);
  return;
}



/* 00025e8c FUN_00025e8c */

/* Boundary evidence: original MIPS .pdata 00025e8c..00025ed7. Semantic name remains unreviewed. */

void FUN_00025e8c(UINT param_1)

{
  DAT_006b85f4 = 0;
  FUN_00025ed8(&DAT_00027020,&DAT_00027024);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00025ed8 FUN_00025ed8 */

/* Boundary evidence: original MIPS .pdata 00025ed8..00025f2b. Semantic name remains unreviewed. */

void FUN_00025ed8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00025f2c FUN_00025f2c */

/* Boundary evidence: original MIPS .pdata 00025f2c..00025f67. Semantic name remains unreviewed. */

void FUN_00025f2c(void)

{
  FUN_00025ed8(&DAT_00027010,&DAT_00027014);
  FUN_00025ed8(&DAT_00027000,&DAT_0002700c);
  return;
}



/* 00025fd8 FUN_00025fd8 */

/* Boundary evidence: original MIPS .pdata 00025fd8..00025ffb. Semantic name remains unreviewed. */

void FUN_00025fd8(void)

{
  DAT_006b85d8 = FUN_000242e8();
  return;
}



/* 00025ffc FUN_00025ffc */

/* Boundary evidence: original MIPS .pdata 00025ffc..00026027. Semantic name remains unreviewed. */

void FUN_00025ffc(void)

{
  FUN_00020364(&DAT_006b85e0);
  FUN_00025a6c(FUN_00026088);
  return;
}



/* 00026028 FUN_00026028 */

/* Boundary evidence: original MIPS .pdata 00026028..00026047. Semantic name remains unreviewed. */

void FUN_00026028(void)

{
  FUN_000152bc(&DAT_000307b8);
  return;
}



/* 00026048 FUN_00026048 */

/* Boundary evidence: original MIPS .pdata 00026048..00026067. Semantic name remains unreviewed. */

void FUN_00026048(void)

{
  FUN_00015ccc(&DAT_000b1650);
  return;
}



/* 00026068 FUN_00026068 */

/* Boundary evidence: original MIPS .pdata 00026068..00026087. Semantic name remains unreviewed. */

void FUN_00026068(void)

{
  FUN_00016054(&DAT_001324e8);
  return;
}



/* 00026088 FUN_00026088 */

/* Boundary evidence: original MIPS .pdata 00026088..000260a7. Semantic name remains unreviewed. */

void FUN_00026088(void)

{
  FUN_000207e4(&DAT_006b85e0);
  return;
}


