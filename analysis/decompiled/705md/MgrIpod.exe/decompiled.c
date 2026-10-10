/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..0001108b. Semantic name remains unreviewed. */

void FUN_00011000(void)

{
  if (((DAT_0002e148 != (HANDLE)0xffffffff) ||
      (DAT_0002e148 = CreateFileW(L"MGR1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
      DAT_0002e148 != (HANDLE)0xffffffff)) && (DAT_0002e148 != (HANDLE)0x0)) {
    return;
  }
  NKDbgPrintfW(L"****[ExtMemory Alloc] failed, Driver handle create failed\r\n");
  return;
}



/* 0001108c FUN_0001108c */

/* Boundary evidence: original MIPS .pdata 0001108c..000110db. Semantic name remains unreviewed. */

void FUN_0001108c(void)

{
  if (DAT_0002e148 != -1) {
    CloseHandle((HANDLE)DAT_0002e148);
  }
  DAT_0002e148 = -1;
  return;
}



/* 000110dc FUN_000110dc */

/* Boundary evidence: original MIPS .pdata 000110dc..00011273. Semantic name remains unreviewed. */

void * FUN_000110dc(uint param_1)

{
  HANDLE hDevice;
  wchar_t *pwVar1;
  void *_Dst;
  uint local_res0 [4];
  DWORD local_28 [2];
  int local_20;
  void *local_1c [3];
  
  local_res0[0] = param_1;
  if (DAT_0002e148 == (HANDLE)0xffffffff) {
    FUN_00011000();
  }
  hDevice = DAT_0002e148;
  if (local_res0[0] < 0x200001) {
    local_20 = 0;
    memset(local_1c,0,0xc);
    local_28[0] = 0;
    DeviceIoControl(hDevice,0x15,local_res0,4,&local_20,0x10,local_28,(LPOVERLAPPED)0x0);
    if (local_20 == 0) {
      (&DAT_0002e29c)[DAT_0002e5b8 * 2] = 0;
      _Dst = (void *)__2_YAPAXI_Z(local_res0[0]);
      pwVar1 = L"****[ExtMemory Alloc] successed, Window MemAlloc size:%d, addredd:%X\r\n";
      (&DAT_0002e298)[DAT_0002e5b8 * 2] = _Dst;
    }
    else {
      (&DAT_0002e29c)[DAT_0002e5b8 * 2] = 1;
      (&DAT_0002e298)[DAT_0002e5b8 * 2] = local_20;
      pwVar1 = L"****[ExtMemory Alloc] successed, Extended MemAlloc size:%d, addredd:%X\r\n";
      _Dst = local_1c[0];
    }
    DAT_0002e5b8 = DAT_0002e5b8 + 1;
    NKDbgPrintfW(pwVar1,local_res0[0],_Dst);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,local_res0[0]);
    }
  }
  else {
    NKDbgPrintfW(L"****[ExtMemory Alloc] failed, alloc size over, size: %d\r\n",local_res0[0],
                 local_res0[0]);
    _Dst = (void *)0x0;
  }
  return _Dst;
}



/* 00011274 FUN_00011274 */

/* Boundary evidence: original MIPS .pdata 00011274..0001134f. Semantic name remains unreviewed. */

void FUN_00011274(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20 [2];
  
  if (DAT_0002e5b8 != 0) {
    local_20[0] = 0;
    iVar3 = 0;
    if (0 < DAT_0002e5b8) {
      piVar2 = &DAT_0002e298;
      iVar1 = DAT_0002e5b8;
      do {
        if (piVar2[1] == 0) {
          if (*piVar2 != 0) {
            __3_YAXPAX_Z();
            iVar1 = DAT_0002e5b8;
          }
        }
        else {
          local_20[0] = *piVar2;
          DeviceIoControl(DAT_0002e148,0x16,local_20,4,(LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0)
          ;
          iVar1 = DAT_0002e5b8;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar3 < iVar1);
    }
    DAT_0002e5b8 = 0;
    FUN_0001108c();
  }
  return;
}



/* 00011350 FUN_00011350 */

/* Boundary evidence: original MIPS .pdata 00011350..0001136b. Semantic name remains unreviewed. */

void FUN_00011350(undefined4 param_1)

{
  EventModify(param_1,3);
  return;
}



/* 0001136c FUN_0001136c */

/* Boundary evidence: original MIPS .pdata 0001136c..0001140b. Semantic name remains unreviewed. */

void FUN_0001136c(undefined4 *param_1)

{
  *(undefined2 *)((int)param_1 + 0x26) = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  *(undefined2 *)(param_1 + 0x316) = 0;
  *(undefined2 *)((int)param_1 + 0xc5a) = 0;
  param_1[0x315] = 0;
  param_1[10] = 0;
  memset(param_1 + 0xd,0,0x20);
  memset(param_1 + 0x15,0,0x400);
  memset(param_1 + 0x115,0,0x400);
  memset(param_1 + 0x215,0,0x400);
  return;
}



/* 0001140c FUN_0001140c */

/* Boundary evidence: original MIPS .pdata 0001140c..000114ab. Semantic name remains unreviewed. */

void FUN_0001140c(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S g_bRemoteUIMode %d track index %d","app_play_current_selected_track",
                DAT_0016d0d4,param_1);
  if (DAT_0016d0d4 == 1) {
    FUN_0001e768(DAT_0016ddac,0x16b54,param_1,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  return;
}



/* 000114ac FUN_000114ac */

/* Boundary evidence: original MIPS .pdata 000114ac..00011533. Semantic name remains unreviewed. */

void FUN_000114ac(undefined4 param_1)

{
  if (DAT_0016d0d4 == 1) {
    FUN_0001e048(DAT_0016ddac,0x16b54,param_1,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_current_play_track");
  }
  return;
}



/* 00011534 FUN_00011534 */

/* Boundary evidence: original MIPS .pdata 00011534..000115b7. Semantic name remains unreviewed. */

void FUN_00011534(void)

{
  if (DAT_0016d0d4 == 1) {
    FUN_0001e0d4(DAT_0016ddac,0x16344,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_current_playing_track_index");
  }
  return;
}



/* 000115b8 FUN_000115b8 */

/* Boundary evidence: original MIPS .pdata 000115b8..0001168b. Semantic name remains unreviewed. */

void FUN_000115b8(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_num_playing_tracks");
  if (DAT_0016d0d4 == 1) {
    FUN_0001e154(DAT_0016ddac,0x164c0,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    if (DAT_0016ddc8 == 2) {
      DAT_0016d0d8 = 0;
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_num_playing_tracks");
  }
  return;
}



/* 0001168c FUN_0001168c */

uint * FUN_0001168c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  param_1[3] = param_2 % 1000;
  param_1[2] = param_2 / 1000;
  if (400 < param_2 % 1000) {
    param_1[2] = param_2 / 1000 + 1;
    param_1[3] = 0;
  }
  uVar1 = param_1[2] / 0x3c;
  param_1[1] = uVar1;
  param_1[2] = param_1[2] % 0x3c;
  *param_1 = uVar1 / 0x3c;
  if (0x3b < uVar1) {
    param_1[1] = uVar1 % 0x3c;
  }
  return param_1;
}



/* 00011720 FUN_00011720 */

/* Boundary evidence: original MIPS .pdata 00011720..000117d3. Semantic name remains unreviewed. */

void FUN_00011720(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_repeat");
  if (DAT_0016d0d4 == 1) {
    FUN_0001e268(DAT_0016ddac,0x16610,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_repeat");
  }
  return;
}



/* 000117d4 FUN_000117d4 */

/* Boundary evidence: original MIPS .pdata 000117d4..0001183f. Semantic name remains unreviewed. */

void FUN_000117d4(void)

{
  undefined4 *in_stack_00000010;
  
  DbgDebugPrint(6,0,L"%S track pos %d ms info type %d","app_get_track_pos_cb",*in_stack_00000010);
  DAT_0016de40 = *in_stack_00000010;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00011840 FUN_00011840 */

/* Boundary evidence: original MIPS .pdata 00011840..00011907. Semantic name remains unreviewed. */

void FUN_00011840(undefined4 param_1,int param_2,int param_3)

{
  DWORD DVar1;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    DVar1 = GetTickCount();
    DbgDebugPrint(6,0,L"%S %d","set_track_pos_cb",DVar1);
  }
  else {
    DVar1 = GetTickCount();
    DbgDebugPrint(6,0,L"%S ipod_status %d uw_status %d tickCount %d","set_track_pos_cb",param_2,
                  param_3,DVar1);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00011908 FUN_00011908 */

/* Boundary evidence: original MIPS .pdata 00011908..000119d3. Semantic name remains unreviewed. */

void FUN_00011908(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S shuffle mode %d","app_set_shuffle",param_1);
  if (DAT_0016d0d4 == 1) {
    FUN_0001e2e8(DAT_0016ddac,0x166a8,(char)param_1,0,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_shuffle");
  }
  return;
}



/* 000119d4 FUN_000119d4 */

/* Boundary evidence: original MIPS .pdata 000119d4..00011a87. Semantic name remains unreviewed. */

void FUN_000119d4(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_shuffle");
  if (DAT_0016d0d4 == 1) {
    FUN_0001e37c(DAT_0016ddac,0x16708,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_shuffle");
  }
  return;
}



/* 00011a88 FUN_00011a88 */

/* Boundary evidence: original MIPS .pdata 00011a88..00011b3f. Semantic name remains unreviewed. */

void FUN_00011a88(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_next_track");
  if (DAT_0016d0d4 == 1) {
    FUN_0001df3c(DAT_0016ddac,0x15de8,3,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,0,L"%S g_bRemoteUIMode == FALSE","app_next_track");
  }
  return;
}



/* 00011b40 FUN_00011b40 */

/* Boundary evidence: original MIPS .pdata 00011b40..00011bc7. Semantic name remains unreviewed. */

void FUN_00011b40(undefined4 param_1)

{
  if (DAT_0016d0d4 == 1) {
    FUN_0001e3fc(DAT_0016ddac,0x1679c,param_1,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_track_title");
  }
  return;
}



/* 00011bc8 FUN_00011bc8 */

/* Boundary evidence: original MIPS .pdata 00011bc8..00011c4f. Semantic name remains unreviewed. */

void FUN_00011bc8(undefined4 param_1)

{
  if (DAT_0016d0d4 == 1) {
    FUN_0001e488(DAT_0016ddac,0x16904,param_1,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_track_album2");
  }
  return;
}



/* 00011c50 FUN_00011c50 */

/* Boundary evidence: original MIPS .pdata 00011c50..00011d07. Semantic name remains unreviewed. */

void FUN_00011c50(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_prev_track");
  if (DAT_0016d0d4 == 1) {
    FUN_0001df3c(DAT_0016ddac,0x15de8,4,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_prev_track");
  }
  return;
}



/* 00011d08 FUN_00011d08 */

/* Boundary evidence: original MIPS .pdata 00011d08..00011dcf. Semantic name remains unreviewed. */

void FUN_00011d08(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_fast_forward");
  if (DAT_0016d0d4 == 1) {
    FUN_0001df3c(DAT_0016ddac,0x15de8,5,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    DAT_0016d0e0 = 1;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_fast_forward");
  }
  return;
}



/* 00011dd0 FUN_00011dd0 */

/* Boundary evidence: original MIPS .pdata 00011dd0..00011e97. Semantic name remains unreviewed. */

void FUN_00011dd0(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_fast_rewind");
  if (DAT_0016d0d4 == 1) {
    FUN_0001df3c(DAT_0016ddac,0x15de8,6,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    DAT_0016d0e4 = 1;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_fast_rewind");
  }
  return;
}



/* 00011e98 FUN_00011e98 */

/* Boundary evidence: original MIPS .pdata 00011e98..00011fcb. Semantic name remains unreviewed. */

void FUN_00011e98(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_stop_ff_frw");
  if (DAT_0016d0d4 == 1) {
    DAT_0016d0e0 = 0;
    DAT_0016d0e4 = 0;
    FUN_0001df3c(DAT_0016ddac,0x15de8,7,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    if (DAT_0016dde8 == 1) {
      Sleep(0x96);
      NKDbgPrintfW(L"~~~ Oh~~ My God.... Fuck you!!!! Apple !!!!!! \r\n");
      FUN_0001df3c(DAT_0016ddac,0x15de8,7,0);
      WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_stop_ff_frw");
  }
  return;
}



/* 00011fcc FUN_00011fcc */

/* Boundary evidence: original MIPS .pdata 00011fcc..000120f7. Semantic name remains unreviewed. */

undefined4 FUN_00011fcc(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  uint dwMilliseconds;
  
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_play_status");
  if (DAT_0016d0d4 == 1) {
    DVar1 = GetTickCount();
    dwMilliseconds = DVar1 - DAT_0016d0f0;
    if ((dwMilliseconds < 1000) && (dwMilliseconds != 0)) {
      NKDbgPrintfW(L"_-_ == app_get_play_status() Interval Time %d\r\n",dwMilliseconds);
      WaitForSingleObject(DAT_0016ddd8,dwMilliseconds);
    }
    FUN_0001dfc8(DAT_0016ddac,0x15f14,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    DAT_0016d0f0 = GetTickCount();
    uVar2 = DAT_0016d0ec;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_play_status");
    uVar2 = 0;
  }
  return uVar2;
}



/* 000120f8 FUN_000120f8 */

/* Boundary evidence: original MIPS .pdata 000120f8..000121b7. Semantic name remains unreviewed. */

bool FUN_000120f8(void)

{
  bool bVar1;
  
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_play_status2");
  bVar1 = DAT_0016d0d4 == 1;
  if (bVar1) {
    FUN_0001dfc8(DAT_0016ddac,0x16288,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_play_status2");
  }
  return bVar1;
}



/* 000121b8 FUN_000121b8 */

/* Boundary evidence: original MIPS .pdata 000121b8..00012293. Semantic name remains unreviewed. */

void FUN_000121b8(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_enter_remote_ui_mode");
  EventModify(DAT_0016ddd0,2);
  FUN_0001d010(DAT_0016ddac,0x15ae8,1,0);
  WaitForSingleObject(DAT_0016ddd0,0xffffffff);
  if (DAT_0016ddf4 == '\x04') {
    EventModify(DAT_0016ddd0,2);
    FUN_0001d2c0(DAT_0016ddac,0x15ae8,0);
    WaitForSingleObject(DAT_0016ddd0,0xffffffff);
  }
  return;
}



/* 00012294 FUN_00012294 */

/* Boundary evidence: original MIPS .pdata 00012294..0001230f. Semantic name remains unreviewed. */

void FUN_00012294(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_exit_remote_ui_mode");
  EventModify(DAT_0016ddd0,2);
  FUN_0001d4cc(DAT_0016ddac,0x15bd4,0);
  WaitForSingleObject(DAT_0016ddd0,0xffffffff);
  return;
}



/* 00012310 FUN_00012310 */

/* Boundary evidence: original MIPS .pdata 00012310..0001235b. Semantic name remains unreviewed. */

void FUN_00012310(uint param_1)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_start_audio_read");
  FUN_00014050(param_1);
  return;
}



/* 0001235c FUN_0001235c */

/* Boundary evidence: original MIPS .pdata 0001235c..000123a7. Semantic name remains unreviewed. */

void FUN_0001235c(uint param_1)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_stop_audio_read");
  FUN_000142a4(param_1);
  return;
}



/* 000123a8 FUN_000123a8 */

/* Boundary evidence: original MIPS .pdata 000123a8..000123eb. Semantic name remains unreviewed. */

void FUN_000123a8(void)

{
  FUN_0001debc(DAT_0016ddac,0x15d88,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 000123ec FUN_000123ec */

/* Boundary evidence: original MIPS .pdata 000123ec..0001247b. Semantic name remains unreviewed. */

void FUN_000123ec(undefined4 param_1,undefined4 param_2)

{
  DbgDebugPrint(0x15,0,L"%S db type %d db_record_idx %d","app_select_db_record",param_1,param_2);
  FUN_0001e5a0(DAT_0016ddac,0x14ca0,(char)param_1,param_2,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 0001247c FUN_0001247c */

/* Boundary evidence: original MIPS .pdata 0001247c..000124cb. Semantic name remains unreviewed. */

void FUN_0001247c(undefined4 param_1)

{
  DAT_0002e164 = param_1;
  FUN_0001e634(DAT_0016ddac,0x14d00,(char)param_1,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 000124cc FUN_000124cc */

/* Boundary evidence: original MIPS .pdata 000124cc..000127eb. Semantic name remains unreviewed. */

void FUN_000124cc(uint param_1,int param_2)

{
  bool bVar1;
  DWORD DVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_0016d0d0 == 0) {
    DbgDebugPrint(0x14,2,L"%S g_ocListDataShrMem == NULL","app_request_categorized_db_records");
    return;
  }
  if ((param_1 == 0) || (7 < param_1)) {
    DbgDebugPrint(6,2,L"%S category:%d invalid value","app_request_categorized_db_records",param_1);
    return;
  }
  DAT_0002e164 = param_1;
  FUN_0001247c(param_1);
  DbgDebugPrint(6,0,L"%S category:%d, request_start_index:%d","app_request_categorized_db_records",
                param_1,param_2);
  memset(&DAT_0002e5d4,0,1300000);
  DVar2 = GetTickCount();
  DbgDebugPrint(6,0,L"%S tickcount %d","app_request_categorized_db_records",DVar2);
  DAT_0016d0f8 = 0;
  DAT_0016d0f4 = '\0';
  DAT_0002e5c0 = (char)param_1;
  DAT_0016d084 = param_2;
  KillTimer(DAT_0016de00,0x3ec);
  if (DAT_0016ddc4 == 0) {
    if (DAT_0016d0d0 == 0) goto LAB_0001276c;
    MSHM_Dll_Write(DAT_0016d0d0,&DAT_0002e5cc,0,&DAT_0013d628);
  }
  else {
    uVar3 = DAT_0016ddc4 - DAT_0016d0f8;
    uVar4 = 0;
    if (200 < uVar3) {
      uVar3 = 200;
    }
    Sleep(10);
    NKDbgPrintfW(L":===> [%d/%d]\r\n",param_2,DAT_0016ddc4);
    while( true ) {
      FUN_0001e6c0(DAT_0016ddac,0x14d9c,(char)param_1,DAT_0016d0f8 + param_2,uVar3,(void *)0x0,0);
      WaitForSingleObject(DAT_0016ddcc,0xffffffff);
      if (DAT_0016d0f4 != '\x01') break;
      NKDbgPrintfW(L"[ERROR] app_request_categorized_db_records() ~!@#$ Retry %d\r\n",uVar4);
      Sleep(0x50);
      if ((DAT_0016d0f4 != '\x01') || (bVar1 = 4 < uVar4, uVar4 = uVar4 + 1, bVar1)) break;
    }
    DAT_0016d0f8 = DAT_0016d0f8 + uVar3;
  }
  if (DAT_0016d0f8 < DAT_0016ddc4) {
    SetTimer(DAT_0016de00,0x3ec,0x14,(TIMERPROC)0x0);
    return;
  }
LAB_0001276c:
  IpcPostMsg(6,0x15,0x75,0,0);
  return;
}



/* 000127ec FUN_000127ec */

/* Boundary evidence: original MIPS .pdata 000127ec..000129d7. Semantic name remains unreviewed. */

void FUN_000127ec(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = DAT_0016ddc4 - DAT_0016d0f8;
  uVar3 = 0;
  if (200 < uVar2) {
    uVar2 = 200;
  }
  NKDbgPrintfW(L"===> [%d/%d]-%d\r\n",DAT_0016d084 + DAT_0016d0f8,DAT_0016ddc4,uVar2);
  while( true ) {
    FUN_0001e6c0(DAT_0016ddac,0x14d9c,DAT_0002e5c0,DAT_0016d084 + DAT_0016d0f8,uVar2,(void *)0x0,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    if (DAT_0016d0f4 != '\x01') break;
    NKDbgPrintfW(L"[ERROR] app_request_categorized_db_records() ~!@#$ Retry %d\r\n",uVar3);
    Sleep(0x50);
    if ((DAT_0016d0f4 != '\x01') || (bVar1 = 4 < uVar3, uVar3 = uVar3 + 1, bVar1)) break;
  }
  DAT_0016d0f8 = DAT_0016d0f8 + uVar2;
  if (DAT_0016d0f8 < DAT_0016ddc4) {
    if (DAT_0016d0f8 < 5000) {
      SetTimer(DAT_0016de00,0x3ec,0x14,(TIMERPROC)0x0);
      return;
    }
  }
  else if (DAT_0016d0f8 < 5000) goto LAB_00012988;
  if (DAT_0016d0d0 != 0) {
    MSHM_Dll_Write(DAT_0016d0d0,&DAT_0002e5cc,0,&DAT_0013d628);
  }
LAB_00012988:
  IpcPostMsg(6,0x15,0x75,0,0);
  return;
}



/* 000129d8 FUN_000129d8 */

/* Boundary evidence: original MIPS .pdata 000129d8..00012a47. Semantic name remains unreviewed. */

void FUN_000129d8(uint param_1,undefined4 param_2)

{
  if (param_1 == 4) {
    FUN_000123a8();
  }
  else {
    FUN_0001247c(param_1 & 0xff);
    FUN_000123ec(param_1 & 0xff,param_2);
  }
  FUN_000124cc(param_1 & 0xff,0);
  return;
}



/* 00012a48 FUN_00012a48 */

/* Boundary evidence: original MIPS .pdata 00012a48..00012e2b. Semantic name remains unreviewed. */

void FUN_00012a48(void)

{
  memset(&DAT_0016ddec,0,8);
  FUN_00013fac();
  if (DAT_0016ddc8 == 2) {
    DbgDebugPrint(6,3,L"%S prepare_digital_audio ==> FAIL!!!\n","init_ipod_connection");
    DAT_0016d0d8 = 0;
  }
  else {
    DbgDebugPrint(6,0,L"%S before enter ui mode","init_ipod_connection");
    FUN_00014638(0);
    FUN_00014648(0);
    FUN_000145b8(0);
    FUN_000145d8(0);
    if (DAT_0016d0d8 != 0) {
      FUN_0001dab4(0,0x17498,0);
      WaitForSingleObject(DAT_0016ddcc,0xffffffff);
      if (DAT_0016ddc8 == 2) {
        DbgDebugPrint(6,3,L"%S get_supported_event_notification_cb ==> FAIL!!!\n",
                      "init_ipod_connection");
        DAT_0016d0d8 = 0;
      }
      else {
        if ((DAT_0016ddf4 == '\0') && ((DAT_0016ddec & 0x200) != 0)) {
          NKDbgPrintfW(L">> UWH_IPOD_ACK_SUCCESS .... \r\n ");
          FUN_0001db34(0,0x17584,0x204,0,0);
          WaitForSingleObject(DAT_0016ddcc,0xffffffff);
        }
        FUN_000145f8();
        if (DAT_0016d0d8 != 0) {
          FUN_000121b8();
          if (DAT_0016d0d4 == 0) {
            if (DAT_0016d0d8 == 0) {
              return;
            }
            Sleep(500);
            NKDbgPrintfW(L"~~!@#$ Oh~~ My god~~!!!! g_bRemoteUIMode[%d]\r\n",DAT_0016d0d4);
            if (DAT_0016d0d8 == 0) {
              return;
            }
            FUN_00012294();
            Sleep(1000);
            if (DAT_0016d0d8 == 0) {
              return;
            }
            FUN_000121b8();
            if (DAT_0016d0d4 == 0) {
              NKDbgPrintfW(L"~~!@#$ Oh~~ My god~~ Force change....!!!! g_bRemoteUIMode[%d]\r\n",0);
            }
          }
          FUN_0001d874(DAT_0016ddac,4,0x17358,0);
          WaitForSingleObject(DAT_0016ddcc,0xffffffff);
          if (DAT_0016ddf4 == '\x04') {
            FUN_0001d440(DAT_0016ddac,0x17160,4,0);
          }
          else {
            FUN_0001d874(0,0,0x17358,0);
          }
          WaitForSingleObject(DAT_0016ddcc,0xffffffff);
          if (DAT_0016d0d4 == 1) {
            FUN_00011fcc();
            DbgDebugPrint(6,0,L"%S before uwhu_ipod_ext_set_play_status_change_notify",
                          "init_ipod_connection");
            FUN_0001de30(DAT_0016ddac,0x15d14,0xf,0);
            WaitForSingleObject(DAT_0016ddcc,0xffffffff);
            if ((DAT_0016ddf4 == '\x04') || (DAT_0016ddf4 == '\v')) {
              FUN_0001dda4(DAT_0016ddac,0x15cb4,1,0);
              WaitForSingleObject(DAT_0016ddcc,0xffffffff);
            }
            FUN_000123a8();
            FUN_0001f5c8(0,0x17278,0x188,0);
            WaitForSingleObject(DAT_0016ddcc,0xffffffff);
          }
          DbgDebugPrint(6,0,L"%S after app_enter_remote_ui_mode","init_ipod_connection");
          FUN_00014434(1);
        }
      }
    }
  }
  return;
}



/* 00012e2c FUN_00012e2c */

/* Boundary evidence: original MIPS .pdata 00012e2c..00013077. Semantic name remains unreviewed. */

void FUN_00012e2c(void)

{
  if (DAT_0016d0cc == 0) {
    DbgDebugPrint(6,1,L"%S shared memory is null","app_fetch_album_artwork_app");
  }
  else {
    DbgDebugPrint(6,0,&DAT_0002834c,"app_fetch_album_artwork_app");
    DAT_0002e5c4 = 0;
    EventModify(DAT_0016ddd4,2);
    FUN_0001e8f4(DAT_0016ddac,0x16ea4,0);
    WaitForSingleObject(DAT_0016ddd4,0xffffffff);
    EventModify(DAT_0016ddd4,2);
    FUN_0001ea1c(DAT_0016ddac,0x16dd4,DAT_0016d128,DAT_0002e5c4,0,1,0);
    WaitForSingleObject(DAT_0016ddd4,0xffffffff);
    DbgDebugPrint(6,0,L"%S artwork data is %d","app_fetch_album_artwork_app",DAT_0016ddb8);
    if (DAT_0016ddb8 == 0) {
      DAT_0016dddc = 0;
      if (DAT_0016dd50 != (HGDIOBJ)0x0) {
        DeleteObject(DAT_0016dd50);
        DAT_0016dd50 = (HGDIOBJ)0x0;
      }
      MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x71,0,0);
    }
    else {
      FUN_0001e974(DAT_0016ddac,0x16bb4,DAT_0016d128,DAT_0002e5c4,DAT_0016ddbc,(void *)0x0,0);
      if (DAT_0016ddc8 == 2) {
        DbgDebugPrint(6,3,L"%S   <==== iPod connection is failed!","app_fetch_album_artwork_app");
        DAT_0016d0d8 = 0;
      }
    }
  }
  return;
}



/* 00013078 FUN_00013078 */

/* Boundary evidence: original MIPS .pdata 00013078..000132ab. Semantic name remains unreviewed. */

void FUN_00013078(char *param_1,DWORD param_2,int param_3,int param_4)

{
  HDC hdc;
  HBITMAP pHVar1;
  BOOL BVar2;
  DWORD DVar3;
  char *_Dst;
  int iVar4;
  void *local_68 [2];
  BITMAPINFO local_60;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_68[0] = (void *)0x0;
  memset(&local_60,0,0x38);
  local_60.bmiHeader.biHeight = -param_4;
  local_60.bmiHeader.biPlanes = 1;
  local_60.bmiHeader.biBitCount = 0x10;
  local_60.bmiHeader.biCompression = 3;
  local_60.bmiHeader.biXPelsPerMeter = 0xb12;
  local_60.bmiHeader.biYPelsPerMeter = 0xb12;
  local_60.bmiHeader.biSize = 0x28;
  local_60.bmiColors[0].rgbBlue = '\0';
  local_60.bmiColors[0].rgbGreen = 0xf8;
  local_60.bmiColors[0].rgbRed = '\0';
  local_60.bmiColors[0].rgbReserved = '\0';
  local_34 = 0x7e0;
  local_30 = 0x1f;
  local_2c = 0;
  local_60.bmiHeader.biWidth = param_3;
  local_60.bmiHeader.biSizeImage = param_2;
  hdc = CreateCompatibleDC((HDC)0x0);
  pHVar1 = CreateDIBSection(hdc,&local_60,0,local_68,(HANDLE)0x0,0);
  if (pHVar1 == (HBITMAP)0x0) {
    DVar3 = GetLastError();
    DbgDebugPrint(6,2,L"%S CreateDIB section fails! error code %d","WriteArtworkDIB",DVar3);
  }
  else {
    _Dst = param_1;
    if (0 < param_4) {
      do {
        iVar4 = param_3;
        if (0 < param_3) {
          do {
            if ((*_Dst == '\x01') && (_Dst[1] == '\0')) {
              memset(_Dst,0,2);
            }
            iVar4 = iVar4 + -1;
            _Dst = _Dst + 2;
          } while (iVar4 != 0);
        }
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
    memcpy(local_68[0],param_1,param_2 - 2);
    DbgDebugPrint(6,0,L"%S DIB created","WriteArtworkDIB");
  }
  if (DAT_0016dd50 != (HGDIOBJ)0x0) {
    BVar2 = DeleteObject(DAT_0016dd50);
    DVar3 = GetLastError();
    NKDbgPrintfW(L"~!@#$ [%S] %d, %x \r\n","WriteArtworkDIB",BVar2,DVar3);
  }
  DAT_0016dd50 = pHVar1;
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  return;
}



/* 000132ac FUN_000132ac */

/* Boundary evidence: original MIPS .pdata 000132ac..00013377. Semantic name remains unreviewed. */

undefined4 FUN_000132ac(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00014510();
  uVar2 = 2;
  if (iVar1 == 0x130300) {
    uVar2 = 0;
    goto LAB_0001333c;
  }
  if (((iVar1 != 0x17000b) && (iVar1 != 0x1c0005)) && (iVar1 != 0x1e0006)) {
    if (iVar1 == 0x210000) goto LAB_0001333c;
    if (iVar1 != 0x250015) {
      if (iVar1 != 0x260000) {
        uVar2 = 4;
      }
      goto LAB_0001333c;
    }
  }
  uVar2 = 1;
LAB_0001333c:
  DbgDebugPrint(6,2,L"%S uiPod_type: %d \n","app_get_ipod_type",uVar2);
  return uVar2;
}



/* 00013378 FUN_00013378 */

/* Boundary evidence: original MIPS .pdata 00013378..0001344b. Semantic name remains unreviewed. */

void FUN_00013378(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S repeat mode %d","app_set_repeat",param_1);
  if (DAT_0016d0d4 == 1) {
    FUN_0001e1d4(DAT_0016ddac,0x165b0,(char)param_1,0,0);
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    FUN_00011720();
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_repeat");
  }
  return;
}



/* 0001344c FUN_0001344c */

/* Boundary evidence: original MIPS .pdata 0001344c..000134b7. Semantic name remains unreviewed. */

void FUN_0001344c(void)

{
  DbgDebugPrint(6,0,&DAT_0002834c,"app_get_track_pos");
  FUN_0001f774(DAT_0016ddac,0x117d4,0,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 000134b8 FUN_000134b8 */

/* Boundary evidence: original MIPS .pdata 000134b8..00013583. Semantic name remains unreviewed. */

void FUN_000134b8(int param_1)

{
  DWORD DVar1;
  int local_18 [2];
  
  local_18[0] = param_1 * 1000;
  DbgDebugPrint(6,0,L"%S set pos %d ms","app_set_track_pos",local_18[0]);
  DVar1 = GetTickCount();
  DbgDebugPrint(6,0,L"%S %d","app_set_track_pos",DVar1);
  FUN_0001f6d4(DAT_0016ddac,0x11840,0,local_18,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 00013584 FUN_00013584 */

/* Boundary evidence: original MIPS .pdata 00013584..000135fb. Semantic name remains unreviewed. */

void FUN_00013584(undefined4 param_1)

{
  undefined4 local_10 [2];
  
  local_10[0] = param_1;
  DbgDebugPrint(6,0,L"%S set pos %d ms","app_set_track_pos_msec",param_1);
  FUN_0001f6d4(DAT_0016ddac,0x11840,0,local_10,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 000135fc FUN_000135fc */

/* Boundary evidence: original MIPS .pdata 000135fc..0001364b. Semantic name remains unreviewed. */

void FUN_000135fc(void)

{
  FUN_0001df3c(DAT_0016ddac,0x15de8,10,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  FUN_00012310(0xf0);
  return;
}



/* 0001364c FUN_0001364c */

/* Boundary evidence: original MIPS .pdata 0001364c..000136bf. Semantic name remains unreviewed. */

void FUN_0001364c(int param_1)

{
  FUN_0001df3c(DAT_0016ddac,0x15de8,1,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  if (param_1 == 0) {
    FUN_0001235c(0xf0);
  }
  else {
    FUN_00012310(0xf0);
  }
  return;
}



/* 000136c0 FUN_000136c0 */

/* Boundary evidence: original MIPS .pdata 000136c0..0001379b. Semantic name remains unreviewed. */

void FUN_000136c0(void)

{
  if (DAT_0016d0d4 == 1) {
    if (DAT_0016d11c == 1) {
      FUN_0001df3c(DAT_0016ddac,0x15de8,1,0);
      WaitForSingleObject(DAT_0016ddcc,0xffffffff);
      FUN_0001235c(0xf0);
      FUN_00011fcc();
    }
    else {
      DbgDebugPrint(6,1,L"%S g_stPlayInfo.ucPlayerStatus is not playing status %d","app_ipod_pause",
                    DAT_0016d11c);
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_ipod_pause");
  }
  return;
}



/* 0001379c FUN_0001379c */

/* Boundary evidence: original MIPS .pdata 0001379c..0001384f. Semantic name remains unreviewed. */

void FUN_0001379c(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 1;
  puVar1 = &DAT_0016d134;
  do {
    if (DAT_0016ddc8 == 2) {
      DAT_0016d0d8 = 0;
      return;
    }
    FUN_0001247c(uVar2 & 0xff);
    *puVar1 = DAT_0002e5cc;
    Sleep(10);
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while ((int)puVar1 < 0x16d150);
  return;
}



/* 00013850 FUN_00013850 */

/* Boundary evidence: original MIPS .pdata 00013850..0001386f. Semantic name remains unreviewed. */

undefined4 FUN_00013850(void)

{
  FUN_00012e2c();
  return 0;
}



/* 00013870 FUN_00013870 */

/* Boundary evidence: original MIPS .pdata 00013870..000138f7. Semantic name remains unreviewed. */

void FUN_00013870(void)

{
  HANDLE hObject;
  
  if (DAT_0016dddc == 1) {
    DbgDebugPrint(6,1,L"%S current is artwork locking status","app_fetch_album_artwork");
  }
  else {
    DAT_0016dddc = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00013850,(LPVOID)0x0,0,(LPDWORD)0x0);
    CloseHandle(hObject);
  }
  return;
}



/* 000138f8 FUN_000138f8 */

/* Boundary evidence: original MIPS .pdata 000138f8..000139f7. Semantic name remains unreviewed. */

void FUN_000138f8(void)

{
  if (DAT_0016d0d4 == 1) {
    FUN_00011534();
    if (DAT_0016ddc8 == 2) {
      DAT_0016d0d8 = 0;
    }
    else {
      DbgDebugPrint(6,3,L"%S curPlay idx %d","app_request_track_info",DAT_0016d128);
      if (-1 < DAT_0016d128) {
        if (DAT_0002e168 == DAT_0016d128) {
          FUN_00011bc8(DAT_0016d128);
        }
        else {
          DAT_0002e168 = DAT_0016d128;
          FUN_00011b40(DAT_0016d128);
          FUN_00011bc8(DAT_0016d128);
          FUN_00013870();
        }
      }
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_request_track_info");
  }
  return;
}



/* 000139f8 FUN_000139f8 */

/* Boundary evidence: original MIPS .pdata 000139f8..00013c47. Semantic name remains unreviewed. */

void FUN_000139f8(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 5) {
    DAT_0002e168 = 0xffffffff;
  }
  else {
    FUN_0001247c(param_1 & 0xff);
    FUN_000123ec(param_1 & 0xff,param_2);
    if (param_1 == 7) {
      if (param_2 != 0) goto LAB_00013ae0;
      FUN_0001247c(7);
      FUN_000123ec(7,0);
      DAT_0016de44 = DAT_0002e5cc;
      FUN_00011b40(0);
      FUN_000138f8();
      FUN_00013870();
    }
  }
  if (param_1 == 1) {
LAB_00013c18:
    uVar1 = 5;
  }
  else {
    uVar1 = 2;
    if (param_1 != 2) {
      if (param_1 == 3) goto LAB_00013c18;
      if (param_1 == 4) goto LAB_00013c1c;
      if (param_1 == 5) {
        FUN_0001140c(param_2);
        FUN_000115b8();
        FUN_00011534();
        if (((DAT_0016d950 != '\0') || (DAT_0016d951 != '\0')) || (DAT_0016d952 != '\0')) {
          memset(&DAT_0016d950,0,0x400);
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x70,0,0);
        }
        if (DAT_0016de18 == 0) {
          DAT_0016de38 = 0;
          FUN_00012310(0xf0);
          FUN_00011fcc();
        }
        else {
          FUN_000120f8();
          if (DAT_0016d11c == 1) {
            FUN_0001364c(0);
          }
        }
        SetTimer(DAT_0016de00,0x3ed,2000,(TIMERPROC)0x0);
        return;
      }
      if (param_1 != 6) {
LAB_00013ae0:
        DbgDebugPrint(0x15,3,L"%S check current ipod category %d","app_enter_category_db",param_1);
        return;
      }
    }
    uVar1 = 3;
  }
LAB_00013c1c:
  FUN_000124cc(uVar1,0);
  return;
}



/* 00013c48 FUN_00013c48 */

/* Boundary evidence: original MIPS .pdata 00013c48..00013dc7. Semantic name remains unreviewed. */

void FUN_00013c48(void)

{
  undefined4 uVar1;
  
  if (DAT_0016d128 != -1) {
    FUN_000120f8();
    if (DAT_0016d0dc != 0) {
      return;
    }
    DAT_0016d0dc = 1;
    if (DAT_0016ddf4 == '\x04') {
      NKDbgPrintfW(L">> [ERROR] IPOD_ACK_BAD! ipod_rebuildlist\r\n");
      uVar1 = DAT_0016de40;
      FUN_000123ec(5,DAT_0016d128);
      FUN_00013584(uVar1);
      FUN_00011b40(DAT_0016d128);
      FUN_00013870();
      return;
    }
    if (DAT_0016ddf4 == '\0') {
      DAT_0016d0dc = 1;
      return;
    }
    NKDbgPrintfW(L">> [error] g_ipod_staus %d\r\n",DAT_0016ddf4);
    return;
  }
  DbgDebugPrint(6,3,L"%S g_stPlayInfo.nCurPlayIdx %d","app_ipod_rebuildlist",0xffffffff);
  FUN_00011534();
  if (DAT_0016d128 == -1) {
    FUN_000114ac(0);
    FUN_00011534();
    if (DAT_0016d128 == -1) {
      if (DAT_0016d144 == 0) {
        if (DAT_0016d14c == 0) goto LAB_00013d14;
        FUN_0001247c(7);
        uVar1 = 7;
      }
      else {
        FUN_0001247c(5);
        uVar1 = 5;
      }
      FUN_000123ec(uVar1,0);
    }
  }
  else {
    FUN_000115b8();
  }
LAB_00013d14:
  FUN_000138f8();
  return;
}



/* 00013dc8 FUN_00013dc8 */

/* Boundary evidence: original MIPS .pdata 00013dc8..00013f43. Semantic name remains unreviewed. */

void FUN_00013dc8(void)

{
  DbgDebugPrint(6,1,&DAT_0002834c,"app_ipod_resume");
  if (DAT_0016d0d4 == 1) {
    if (DAT_0016d11c == 1) {
      DbgDebugPrint(6,3,L"%S g_stPlayInfo.ucPlayerStatus is playing","app_ipod_resume");
    }
    else {
      FUN_0001df3c(0,0x15e74,0xe,0);
      WaitForSingleObject(DAT_0016ddcc,0xffffffff);
      if (DAT_0002e5bc == 0) {
        FUN_0001df3c(DAT_0016ddac,0x15de8,1,0);
        WaitForSingleObject(DAT_0016ddcc,0xffffffff);
      }
    }
    DbgDebugPrint(6,3,L"%S g_stPlayInfo.nCurPlayIdx %d","app_ipod_resume",DAT_0016d128);
    FUN_00013c48();
    FUN_00012310(0xf0);
    FUN_00011fcc();
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_ipod_resume");
  }
  return;
}



/* 00013f44 FUN_00013f44 */

void FUN_00013f44(undefined4 param_1)

{
  DAT_0016dda0 = param_1;
  return;
}



/* 00013f54 FUN_00013f54 */

void FUN_00013f54(undefined2 param_1,undefined1 param_2)

{
  DAT_0016dda4 = param_1;
  DAT_0016dda6 = param_2;
  return;
}



/* 00013f68 FUN_00013f68 */

undefined2 * FUN_00013f68(void)

{
  return &DAT_0016dda4;
}



/* 00013f78 FUN_00013f78 */

void FUN_00013f78(undefined1 param_1)

{
  DAT_0016dda8 = param_1;
  return;
}



/* 00013f84 FUN_00013f84 */

/* Boundary evidence: original MIPS .pdata 00013f84..00013fab. Semantic name remains unreviewed. */

void FUN_00013f84(void)

{
  DAT_0016ddb4 = 0;
  FUN_0001d1e0(DAT_0016ddac);
  return;
}



/* 00013fac FUN_00013fac */

/* Boundary evidence: original MIPS .pdata 00013fac..0001404f. Semantic name remains unreviewed. */

void FUN_00013fac(void)

{
  int iVar1;
  
  DAT_0016ddb4 = 0;
  iVar1 = FUN_0001cf0c(DAT_0016ddac);
  if (iVar1 == 0) {
    DAT_0016ddc8 = 1;
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S uwhu_ipod_da_prepare_audio_read %d %d\n","prepare_digital_audio",
                  iVar1);
    if ((iVar1 != 0xb) && (iVar1 != 0x12)) {
      DAT_0016ddc8 = 2;
      NKDbgPrintfW(L">> iPod connect_failed!!!\r\n");
    }
  }
  return;
}



/* 00014050 FUN_00014050 */

/* Boundary evidence: original MIPS .pdata 00014050..000142a3. Semantic name remains unreviewed. */

void FUN_00014050(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_0016dda8;
  if (uVar2 == 0xf) goto LAB_00014134;
  if (DAT_0016ddb4 == 0) {
    iVar1 = FUN_0001cf84(DAT_0016ddac,100,0x16ad8,0);
    if (iVar1 == 0) {
      DAT_0016ddb4 = 1;
    }
    else {
      if (iVar1 == 8) {
        NKDbgPrintfW(L">> [ERROR]UWE_BUSY!!!! STARTING IPOD RESUME!! \r\n");
        if (DAT_0016de2c == 0) {
          return;
        }
        SetTimer(DAT_0016de00,0xc90,10,(TIMERPROC)0x0);
        return;
      }
      DAT_0016ddb4 = 0;
      DbgDebugPrint(6,3,L"[ERROR] %S ipod_da_START_audio_read g_bAudioStartFlag %d %d\n",
                    "request_digital_audio",0,0xd1);
    }
    WaitForSingleObject(DAT_0016ddcc,0xffffffff);
    if (DAT_0016ddb0 == 0) {
      iVar1 = FUN_0001ce1c(DAT_0016ddac);
      if ((iVar1 != 0) && (iVar1 != 10)) goto LAB_00014128;
      DAT_0016ddb0 = 1;
    }
    else {
      if (DAT_0016ddb4 != 0) {
        uVar2 = (uint)DAT_0016dda8;
        goto LAB_00014134;
      }
      FUN_0001ce94(DAT_0016ddac);
LAB_000140f0:
      DAT_0016ddb0 = 0;
    }
  }
  else {
    if (DAT_0016ddb0 != 0) {
      DbgDebugPrint(6,3,L"[ERROR]%S uwhu_audio_dev_open !!! g_bWaveOpenFlag %d\n",
                    "request_digital_audio",DAT_0016ddb0);
LAB_00014128:
      uVar2 = (uint)DAT_0016dda8;
      goto LAB_00014134;
    }
    iVar1 = FUN_0001ce1c(DAT_0016ddac);
    if (iVar1 != 0) {
      if (iVar1 != 10) {
        iVar1 = FUN_0001ce1c(DAT_0016ddac);
      }
      if ((iVar1 != 0) && (iVar1 != 10)) goto LAB_000140f0;
    }
    DAT_0016ddb0 = 1;
  }
  uVar2 = (uint)DAT_0016dda8;
LAB_00014134:
  DAT_0016dda8 = (byte)(uVar2 | param_1);
  DbgDebugPrint(6,2,
                L"%S request_digital_audio_g_fDigitalAudio_0x%02x %d [g_bWaveOpenFlag %d, g_bAudioStartFlag %d]\n"
                ,"request_digital_audio",uVar2 | param_1,0xeb,DAT_0016ddb0,DAT_0016ddb4);
  return;
}



/* 000142a4 FUN_000142a4 */

/* Boundary evidence: original MIPS .pdata 000142a4..00014433. Semantic name remains unreviewed. */

void FUN_000142a4(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 == 0) || ((uVar2 = (uint)DAT_0016dda8, param_1 == 0xf0 && (uVar2 == 0)))) ||
     ((param_1 == 0xf && (uVar2 == 0)))) {
    if (DAT_0016ddb0 != 0) {
      iVar1 = FUN_0001ce94(DAT_0016ddac);
      DAT_0016ddb0 = 0;
      if (iVar1 != 0) {
        DbgDebugPrint(6,3,L"[*ERROR*] 111 %S ! (ret_%d | %d)","release_digital_audio",iVar1,0);
      }
    }
    DAT_0016dda8 = 0;
  }
  else {
    if ((uVar2 == param_1) && (DAT_0016ddb0 != 0)) {
      iVar1 = FUN_0001ce94(DAT_0016ddac);
      if (iVar1 != 0) {
        iVar1 = FUN_0001ce94(DAT_0016ddac);
        DbgDebugPrint(6,3,L"[*ERROR*] 222 %S ! (ret_%d | %d)","release_digital_audio",iVar1,
                      DAT_0016ddb0);
      }
      uVar2 = (uint)DAT_0016dda8;
      DAT_0016ddb0 = 0;
    }
    DAT_0016dda8 = (byte)(uVar2 ^ param_1);
    DbgDebugPrint(6,2,
                  L"%S release_digital_audio_g_fDigitalAudio_0x%02x %d [g_bWaveOpenFlag %d, g_bAudioStartFlag %d]"
                  ,"release_digital_audio",(uVar2 ^ param_1) & 0xff,0x111,DAT_0016ddb0,DAT_0016ddb4)
    ;
  }
  return;
}



/* 00014434 FUN_00014434 */

void FUN_00014434(undefined4 param_1)

{
  DAT_0016dd88 = param_1;
  return;
}



/* 00014444 FUN_00014444 */

undefined4 FUN_00014444(void)

{
  return DAT_0016dd88;
}



/* 00014454 FUN_00014454 */

/* Boundary evidence: original MIPS .pdata 00014454..0001449f. Semantic name remains unreviewed. */

void FUN_00014454(undefined4 param_1,undefined2 param_2,undefined4 *param_3)

{
  DAT_0016dd94 = param_1;
  DAT_0016dd98 = param_2;
  if (param_3 == (undefined4 *)0x0) {
    memset(&DAT_0016dd9a,0,4);
  }
  else {
    DAT_0016dd9a = *param_3;
  }
  return;
}



/* 000144a0 FUN_000144a0 */

/* Boundary evidence: original MIPS .pdata 000144a0..000144ff. Semantic name remains unreviewed. */

void FUN_000144a0(void)

{
  DbgDebugPrint(6,0,L"%S(%d): keepMsg_%d, AppLink_%d, InitFlag_%d\n","send_ip2c_keeping_msg",0x151,
                DAT_0016dd94,DAT_0016dd84,DAT_0016dd88);
  return;
}



/* 00014500 FUN_00014500 */

undefined4 FUN_00014500(void)

{
  return DAT_0016dd84;
}



/* 00014510 FUN_00014510 */

undefined4 FUN_00014510(void)

{
  return DAT_0016dd58;
}



/* 0001451c FUN_0001451c */

/* Boundary evidence: original MIPS .pdata 0001451c..000145b7. Semantic name remains unreviewed. */

void FUN_0001451c(undefined4 param_1,void *param_2,uint param_3)

{
  size_t _Size;
  
  DAT_0016dd58 = param_1;
  memset(&DAT_0016dd5c,0,0xc);
  _Size = 0xb;
  if (param_3 < 0xc) {
    _Size = param_3;
  }
  memcpy(&DAT_0016dd5c,param_2,_Size);
  DbgDebugPrint(6,2,L"%S ModelNum_%S, ModelID_%d\n","set_model_info",param_2,DAT_0016dd58);
  return;
}



/* 000145b8 FUN_000145b8 */

void FUN_000145b8(undefined4 param_1)

{
  DAT_0016dd68 = param_1;
  return;
}



/* 000145c8 FUN_000145c8 */

undefined4 FUN_000145c8(void)

{
  return DAT_0016dd68;
}



/* 000145d8 FUN_000145d8 */

void FUN_000145d8(undefined4 param_1)

{
  DAT_0016dd6c = param_1;
  return;
}



/* 000145e8 FUN_000145e8 */

undefined4 FUN_000145e8(void)

{
  return DAT_0016dd6c;
}



/* 000145f8 FUN_000145f8 */

/* Boundary evidence: original MIPS .pdata 000145f8..00014637. Semantic name remains unreviewed. */

void FUN_000145f8(void)

{
  FUN_0001d64c(0,0x172c8,0);
  WaitForSingleObject(DAT_0016ddcc,0xffffffff);
  return;
}



/* 00014638 FUN_00014638 */

void FUN_00014638(undefined4 param_1)

{
  DAT_0016dd70 = param_1;
  return;
}



/* 00014648 FUN_00014648 */

void FUN_00014648(undefined4 param_1)

{
  DAT_0016dd7c = param_1;
  return;
}



/* 00014658 FUN_00014658 */

undefined4 FUN_00014658(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 < *param_1) {
LAB_0001466c:
    uVar1 = 1;
  }
  else {
    if (*param_1 == *param_2) {
      if (param_2[1] < param_1[1]) goto LAB_0001466c;
      if ((param_1[1] == param_2[1]) && (param_2[2] <= param_1[2])) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 000146b8 FUN_000146b8 */

/* Boundary evidence: original MIPS .pdata 000146b8..000147fb. Semantic name remains unreviewed. */

void FUN_000146b8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint local_18 [2];
  
  DAT_0016ddc8 = 0;
  DAT_0016d0d4 = 0;
  DAT_0016d0d8 = 0;
  DAT_0002e168 = 0xffffffff;
  DAT_0016d0dc = 0;
  DAT_0016ddb0 = 0;
  DAT_0016ddb4 = 0;
  DAT_0016de3c = 0;
  DAT_0016ddac = param_1;
  if ((DAT_0016de10 == 0) && (DAT_0016de0c == 0)) {
    memset(local_18,0,4);
    if (param_2 == 0) {
      uVar1 = local_18[0] & 0xffffe124 | 0x124;
    }
    else {
      uVar1 = local_18[0] & 0xffffe024 | 0x24;
    }
    local_18[0] = uVar1 & 0xffe03fff | 0x2000;
    IpcPostMsg(6,1,9,4,local_18);
    DAT_0016de0c = 0;
  }
  DbgDebugPrint(6,1,L"%S uw_status 0x%x","hw_attach_notif",param_2);
  return;
}



/* 000147fc FUN_000147fc */

/* Boundary evidence: original MIPS .pdata 000147fc..00014943. Semantic name remains unreviewed. */

void FUN_000147fc(undefined4 param_1,int param_2,char *param_3)

{
  DbgDebugPrint(6,0,L"%S event_type %d","remote_event_notification",param_2);
  if (param_2 == 7) {
    if (*param_3 != DAT_0002e222) {
      DbgDebugPrint(6,3,L"%S shuffle changed %d","remote_event_notification",*param_3);
      DAT_0002e222 = *param_3;
      IpcPostMsg(6,0x15,0x6b,1,&DAT_0002e222);
    }
  }
  else if ((param_2 == 8) && (*param_3 != DAT_0002e221)) {
    DbgDebugPrint(6,3,L"%S repeat changed %d","remote_event_notification",*param_3);
    DAT_0002e221 = *param_3;
    IpcPostMsg(6,0x15,0x6c,1,&DAT_0002e221);
  }
  return;
}



/* 00014944 FUN_00014944 */

/* Boundary evidence: original MIPS .pdata 00014944..000149fb. Semantic name remains unreviewed. */

void FUN_00014944(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint local_10 [2];
  
  DAT_0016ddac = param_1;
  DbgDebugPrint(6,1,L"%S result code 0x%02X, inoperable_lingoes_0x%02x","soft_attach_notif",param_3,
                param_2);
  if (param_3 == 0xb) {
    NKDbgPrintfW(L">> NOT supported Device !! \r\n");
    memset(local_10,0,4);
    local_10[0] = local_10[0] & 0xffe03f74 | 0x2074;
    IpcPostMsg(6,1,9,4,local_10);
  }
  return;
}



/* 000149fc FUN_000149fc */

/* Boundary evidence: original MIPS .pdata 000149fc..00014b7b. Semantic name remains unreviewed. */

void FUN_000149fc(undefined4 param_1,undefined4 param_2)

{
  uint local_10 [2];
  
  DAT_0016de18 = 0;
  DAT_0016d0d8 = 0;
  DAT_0016de1c = 0;
  DAT_0016de20 = 0;
  DAT_0016de24 = 0;
  FUN_00013f78(0);
  FUN_0001235c(0);
  FUN_00013f84();
  DAT_0016de0c = 0;
  DAT_0002e161 = 2;
  DAT_0016d0e0 = 0;
  DAT_0016de48 = 0;
  DAT_0016ddb0 = 0;
  DAT_0016d0e4 = 0;
  DAT_0016de4c = 0;
  DAT_0016d0d4 = 0;
  DAT_0016ddb4 = 0;
  DAT_0016de3c = 0;
  DbgDebugPrint(6,1,L"%S uw_status %d","detach_notif",param_2);
  local_10[0] = local_10[0] & 0xffe03f04 | 0x2004;
  IpcPostMsg(6,1,9,4,local_10);
  DAT_0016ddc8 = 0;
  FUN_00014434(0);
  DAT_0002e168 = 0xffffffff;
  if (DAT_0016dd50 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0016dd50);
  }
  memset(&DAT_0016d0fc,0,0xc5c);
  MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
  return;
}



/* 00014b7c FUN_00014b7c */

/* Boundary evidence: original MIPS .pdata 00014b7c..00014c9f. Semantic name remains unreviewed. */

void FUN_00014b7c(undefined4 param_1,int param_2,int param_3)

{
  uint local_18 [2];
  
  KillTimer(DAT_0016de00,0xc8e);
  DAT_0016de38 = 0;
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,1,L"%S auth_notif success","auth_notif");
    DAT_0016d0d8 = 1;
    IpcPostMsg(6,6,1000,0,0);
  }
  else {
    memset(local_18,0,4);
    local_18[0] = local_18[0] & 0xffe03f04 | 0x2004;
    IpcPostMsg(6,1,9,4,local_18);
    DbgDebugPrint(6,1,L"%S auth_notif fail ipod_status 0x%x error code 0x%x","auth_notif",param_2,
                  param_3);
  }
  return;
}



/* 00014ca0 FUN_00014ca0 */

/* Boundary evidence: original MIPS .pdata 00014ca0..00014cff. Semantic name remains unreviewed. */

void FUN_00014ca0(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x error code 0x%x","select_db_record_cb",param_2,
                  param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00014d00 FUN_00014d00 */

/* Boundary evidence: original MIPS .pdata 00014d00..00014d9b. Semantic name remains unreviewed. */

void FUN_00014d00(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002e5cc = param_4;
    DAT_0016bc0c = param_4;
    DAT_0016ddc4 = param_4;
    if (5000 < param_4) {
      DAT_0002e5cc = 5000;
    }
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S g_stReqCat %d record count %d ipod_status 0x%x error code 0x%x",
                  "get_num_categorized_db_records_cb",DAT_0002e164,param_4,param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00014d9c FUN_00014d9c */

/* Boundary evidence: original MIPS .pdata 00014d9c..00014ed3. Semantic name remains unreviewed. */

void FUN_00014d9c(undefined4 param_1,int param_2,int param_3,uint param_4,void *param_5,
                 ushort param_6,int param_7)

{
  size_t _Size;
  
  if ((param_3 == 0) && (param_2 == 0)) {
    DAT_0016d0f4 = 0;
    if (param_4 < 5000) {
      _Size = (size_t)param_6;
      if (0x103 < _Size) {
        _Size = 0x103;
      }
      memcpy(&DAT_0002e5d4 + param_4 * 0x104,param_5,_Size);
    }
  }
  else {
    DAT_0016d0f4 = 1;
    DbgDebugPrint(6,1,L"%S ipod_status 0x%x error code 0x%x, record_len %d, more_to_follow %d",
                  "categorized_records_cb",param_2,param_3,param_6,param_7);
  }
  if ((param_4 == DAT_0016ddc4 - 1U) || (param_7 != 1)) {
    MSHM_Dll_Write(DAT_0016d0d0,&DAT_0002e5cc,0,&DAT_0013d628);
    EventModify(DAT_0016ddcc,3);
  }
  return;
}



/* 00014ed4 FUN_00014ed4 */

/* Boundary evidence: original MIPS .pdata 00014ed4..00015943. Semantic name remains unreviewed. */

void FUN_00014ed4(undefined4 param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  uint local_b0 [2];
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint auStack_98 [4];
  uint auStack_88 [4];
  uint auStack_78 [4];
  uint auStack_68 [4];
  uint auStack_58 [4];
  uint auStack_48 [4];
  uint auStack_38 [4];
  
  if (param_2 == 0) {
    DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_STOPPED  g_iReadInfoTrack %d",
                  "play_state_changed_notif",DAT_0002e168);
    if (DAT_0002e5c0 == '\a') {
      if (DAT_0002e221 == '\x02') {
        if ((DAT_0016de44 - 1U <= DAT_0016d128) || (DAT_0016d128 != 0)) {
          local_b0[0] = local_b0[0] & 0xff000007 | 7;
          IpcPostMsg(0x15,6,0x75,4,local_b0);
          return;
        }
      }
      else if (DAT_0002e221 == '\x01') {
        local_b0[0] = (DAT_0016d128 & 0xffff) << 8 | local_b0[0] & 0xff000007 | 7;
        IpcPostMsg(0x15,6,0x75,4,local_b0);
        return;
      }
    }
    DAT_0002e168 = 0xffffffff;
    DAT_0016dde4 = 1;
    if (DAT_0016d0cc == 0) {
      DAT_0002e168 = 0xffffffff;
      DAT_0016dde4 = 1;
      return;
    }
    DAT_0016d11c = 0;
    puVar1 = FUN_0001168c(auStack_38,*param_3);
    local_a8 = *puVar1;
    local_a4 = puVar1[1];
    local_a0 = puVar1[2];
    local_9c = puVar1[3];
    iVar2 = FUN_00014658(&DAT_0016d0fc,&local_a8);
    if (iVar2 != 0) {
      DAT_0016d10c = DAT_0016d0fc;
      DAT_0016d110 = DAT_0016d100;
      DAT_0016d114 = DAT_0016d104;
      DAT_0016d118 = DAT_0016d108;
    }
    DAT_0016de40 = *param_3;
    MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
    DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_STOPPED play_state %d cur playing idx %d",
                  "play_state_changed_notif",0,DAT_0016d128);
    IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
    if (iVar2 == 0) {
      return;
    }
    IpcPostMsg(6,0x15,0x72,0,0);
    return;
  }
  if (param_2 == 1) {
    DbgDebugPrint(6,1,L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_CHANGED  g_iReadInfoTrack %d g_bStoped %d",
                  "play_state_changed_notif",*param_3,DAT_0016dde4);
    DAT_0002e168 = 0xffffffff;
    if (DAT_0016dde4 != 0) {
      DAT_0016dde4 = 0;
    }
    if (DAT_0016d0e0 != 0) {
      IpcPostMsg(6,6,0x3ef,0,0);
    }
    if (DAT_0016de48 == 1) {
      NKDbgPrintfW(L"~!@# UWH_IPOD_EXT_PLAYBACK_TRACK_CHANGED g_bTrackJumpStart [%d]\r\n",1);
      return;
    }
    if (DAT_0016d0cc == 0) {
      return;
    }
    DAT_0016d128 = *param_3;
    if (DAT_0016de28 == 0) {
      DAT_0016de58 = *param_3;
    }
    else {
      NKDbgPrintfW(L"~!@# 1111 Opss!!!! [%d]->[%d]\r\n",DAT_0016de58,*param_3);
    }
    KillTimer(DAT_0016de00,0x3ed);
    IpcPostMsg(6,6,0x3f0,0,0);
    return;
  }
  if (param_2 < 2) {
LAB_00015558:
    DbgDebugPrint(6,3,L"%S Not definced  play_state %d","play_state_changed_notif",param_2);
  }
  else {
    if (param_2 < 4) {
      if ((param_2 == 2) && (DAT_0016d0e0 != 0)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      else if ((param_2 == 3) && (DAT_0016d0e4 != 0)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      if (DAT_0016d0cc == 0) {
        return;
      }
      puVar1 = FUN_0001168c(auStack_78,*param_3);
      local_a8 = *puVar1;
      local_a4 = puVar1[1];
      local_a0 = puVar1[2];
      local_9c = puVar1[3];
      iVar2 = FUN_00014658(&DAT_0016d0fc,&local_a8);
      if (iVar2 != 0) {
        puVar1 = FUN_0001168c(auStack_58,*param_3);
        DAT_0016d10c = *puVar1;
        DAT_0016d110 = puVar1[1];
        DAT_0016d114 = puVar1[2];
        DAT_0016d118 = puVar1[3];
      }
      DAT_0016de40 = *param_3;
      MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
      DbgDebugPrint(6,0,L"%S play_state %d cur playing idx %d","play_state_changed_notif",
                    DAT_0016d128);
      DbgDebugPrint(6,0,L"%S %d, set pos %d ms","play_state_changed_notif",0x254,*param_3);
      IpcPostMsg(6,0x15,0x72,0,0);
      return;
    }
    if (param_2 == 4) {
      if ((DAT_0016d0e4 != 0) && (*param_3 < 500)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      if (DAT_0016d0cc != 0) {
        puVar1 = FUN_0001168c(auStack_68,*param_3);
        local_a8 = *puVar1;
        local_a4 = puVar1[1];
        local_a0 = puVar1[2];
        local_9c = puVar1[3];
        iVar2 = FUN_00014658(&DAT_0016d0fc,&local_a8);
        if (iVar2 == 0) {
          return;
        }
        puVar1 = FUN_0001168c(auStack_48,*param_3);
        local_9c = puVar1[3];
        if (((DAT_0016d10c == *puVar1) && (DAT_0016d110 == puVar1[1])) &&
           (DAT_0016d114 == puVar1[2])) {
          return;
        }
        if (DAT_0016de4c != 0) {
          *param_3 = 0;
          DAT_0016de40 = 0;
          puVar1 = FUN_0001168c(auStack_98,0);
          DAT_0016d10c = *puVar1;
          DAT_0016d110 = puVar1[1];
          DAT_0016d114 = puVar1[2];
          DAT_0016d118 = puVar1[3];
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x72,0,0);
        }
        puVar1 = FUN_0001168c(auStack_88,*param_3);
        DAT_0016d10c = *puVar1;
        DAT_0016d110 = puVar1[1];
        DAT_0016d114 = puVar1[2];
        DAT_0016d118 = puVar1[3];
        DAT_0016de40 = *param_3;
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_POS play_state %d/%d cur playing idx %d",
                      "play_state_changed_notif",DAT_0016d11c,4,DAT_0016d128);
        DbgDebugPrint(6,0,L"%S %d set pos %d ms","play_state_changed_notif",700,*param_3);
        IpcPostMsg(6,0x15,0x72,0,0);
        return;
      }
      pwVar4 = L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_POS g_ocsharedMemory == NULL";
      uVar3 = 0;
    }
    else {
      if (param_2 != 5) {
        if (param_2 == 6) {
          DbgDebugPrint(6,3,
                        L"%S UWH_IPOD_EXT_PLAYBACK_EXT_STATUS_CHANGED g_ucExtPlayStatus %d, play_state %d, g_bStoped %d, g_stPlayInfo.ucPlayerStatus %d, ext_play_state [%d]"
                        ,"play_state_changed_notif",DAT_0002e161,6,DAT_0016dde4,DAT_0016d11c,
                        (char)*param_3);
          if (DAT_0016dde4 == 1) {
            if (DAT_0016d11c == 0) {
              if (DAT_0002e161 == '\v') {
                DAT_0016d11c = 2;
              }
              else if (DAT_0002e161 == '\x02') {
                DAT_0016d11c = 0;
              }
              if ((char)*param_3 == '\x02') {
                DAT_0016d11c = 0;
                FUN_0001235c(0xf0);
              }
              MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
              IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
            }
            else {
              IpcPostMsg(6,6,0x3f0,0,0);
              DAT_0016dde4 = 0;
            }
          }
          DAT_0002e161 = (char)*param_3;
          IpcPostMsg(6,0x15,0x78,1,&DAT_0002e161);
          IpcPostMsg(6,6,0x3ee,0,0);
          return;
        }
        goto LAB_00015558;
      }
      uVar3 = 3;
      if (DAT_0016d0cc != 0) {
        DAT_0016d12c = *param_3;
        DbgDebugPrint(6,3,L"%S UWH_IPOD_EXT_PLAYBACK_CHAPTER_CHANGED chapter %d, record idx %d",
                      "play_state_changed_notif",DAT_0016d12c,DAT_0016d128);
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x6a,0,0);
        return;
      }
      pwVar4 = L"%S UWH_IPOD_EXT_PLAYBACK_CHAPTER_CHANGED g_ocsharedMemory == NULL";
    }
    DbgDebugPrint(6,uVar3,pwVar4,"play_state_changed_notif");
  }
  return;
}



/* 00015944 FUN_00015944 */

/* Boundary evidence: original MIPS .pdata 00015944..0001597b. Semantic name remains unreviewed. */

void FUN_00015944(undefined4 param_1,undefined1 *param_2)

{
  DbgDebugPrint(6,3,L"general_evnet_notification: event type 0x%x\r\n",*param_2);
  return;
}



/* 0001597c FUN_0001597c */

/* Boundary evidence: original MIPS .pdata 0001597c..000159b3. Semantic name remains unreviewed. */

void FUN_0001597c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DbgDebugPrint(6,3,L"===> general_set_accessory_status_notifitcation: mask 0x%x, tid 0x%x\r\n",
                param_2,param_3);
  return;
}



/* 000159b4 FUN_000159b4 */

/* Boundary evidence: original MIPS .pdata 000159b4..00015ae7. Semantic name remains unreviewed. */

void FUN_000159b4(undefined4 param_1,int param_2,undefined4 param_3)

{
  wchar_t *pwVar1;
  int local_res4 [3];
  
  local_res4[0] = param_2;
  IpcPostMsg(6,1,0x49,4,local_res4);
  if (local_res4[0] == 2) {
    pwVar1 = L"notify_handler: No driver for device 0x%x\n";
  }
  else if (local_res4[0] == 5) {
    pwVar1 = L"notify_handler: mass storage 0x%x attached\n";
  }
  else if (local_res4[0] == 6) {
    pwVar1 = L"notify_handler: ncm device 0x%x attached\n";
  }
  else if (local_res4[0] == 0xf) {
    pwVar1 = L"notify_handler: mass storage 0x%x detached\n";
  }
  else if (local_res4[0] == 0x10) {
    pwVar1 = L"notify_handler: ncm device 0x%x detached\n";
  }
  else if (local_res4[0] == 0x21) {
    pwVar1 = L"notify_handler: over current occurred dev 0x%x\n";
  }
  else {
    if (local_res4[0] != 0x22) {
      DbgDebugPrint(6,3,L"notify_handler: msg %ld dev 0x%x Unknown\n",local_res4[0],param_3);
      return;
    }
    pwVar1 = L"notify_handler: New hub is too deep 0x%x\n";
  }
  DbgDebugPrint(6,3,pwVar1,param_3);
  return;
}



/* 00015ae8 FUN_00015ae8 */

/* Boundary evidence: original MIPS .pdata 00015ae8..00015bd3. Semantic name remains unreviewed. */

void FUN_00015ae8(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,0,L"%S enter_remote_ui_cb ipod status 0x%x result 0x%x","enter_remote_ui_cb",
                param_2,param_3);
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016d0d4 = 1;
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode %d","enter_remote_ui_cb",1);
  }
  else {
    DbgDebugPrint(6,1,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","enter_remote_ui_cb",param_2,
                  param_3);
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddd0,3);
  return;
}



/* 00015bd4 FUN_00015bd4 */

/* Boundary evidence: original MIPS .pdata 00015bd4..00015cb3. Semantic name remains unreviewed. */

void FUN_00015bd4(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,0,L"%S exit_remote_ui_cb ipod status 0x%x result 0x%x","exit_remote_ui_cb",param_2
                ,param_3);
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016d0d4 = 0;
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode %d","exit_remote_ui_cb",0);
  }
  else {
    DbgDebugPrint(6,1,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","exit_remote_ui_cb",param_2,
                  param_3);
  }
  EventModify(DAT_0016ddd0,3);
  return;
}



/* 00015cb4 FUN_00015cb4 */

/* Boundary evidence: original MIPS .pdata 00015cb4..00015d13. Semantic name remains unreviewed. */

void FUN_00015cb4(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","set_notify_cb",param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00015d14 FUN_00015d14 */

/* Boundary evidence: original MIPS .pdata 00015d14..00015d87. Semantic name remains unreviewed. */

void FUN_00015d14(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","set_notify_mask_cb",param_2,
                  param_3);
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00015d88 FUN_00015d88 */

/* Boundary evidence: original MIPS .pdata 00015d88..00015de7. Semantic name remains unreviewed. */

void FUN_00015d88(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","reset_db_cb",param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00015de8 FUN_00015de8 */

/* Boundary evidence: original MIPS .pdata 00015de8..00015e73. Semantic name remains unreviewed. */

void FUN_00015de8(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016dde8 = 0;
  }
  else {
    DAT_0016dde8 = 1;
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","play_control_cb",param_2,param_3);
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00015e74 FUN_00015e74 */

/* Boundary evidence: original MIPS .pdata 00015e74..00015f13. Semantic name remains unreviewed. */

void FUN_00015e74(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,3,L"%S ipod status 0x%x result 0x%x","play_control_enforce_ipod_music_cb",param_2,
                param_3);
  if ((param_2 == 4) || (param_3 != 0)) {
    DAT_0002e5bc = 0;
  }
  else {
    DAT_0002e5bc = 1;
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00015f14 FUN_00015f14 */

/* Boundary evidence: original MIPS .pdata 00015f14..00016287. Semantic name remains unreviewed. */

void FUN_00015f14(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  uint *puVar1;
  uint auStack_38 [4];
  
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,3,L"%S ipod status 0x%x uw_status 0x%x play_state 0x%x","get_play_status_cb",0,0
                  ,param_6);
    if (DAT_0016d0cc == 0) {
      DbgDebugPrint(6,3,L"%S g_ocsharedMemory NULL","get_play_status_cb");
    }
    else {
      if ((DAT_0016ddb4 == 1) && (DAT_0016ddb0 == 1)) {
        DAT_0016d11c = 1;
      }
      else {
        DAT_0016d11c = (ushort)param_6;
      }
      MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
      if (DAT_0016de4c != 0) {
        DAT_0016de40 = 0;
        param_5 = 0;
        puVar1 = FUN_0001168c(auStack_38,0);
        DAT_0016d10c = *puVar1;
        DAT_0016d110 = puVar1[1];
        DAT_0016d114 = puVar1[2];
        DAT_0016d118 = puVar1[3];
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x72,0,0);
      }
      if (param_4 == 0xffffffff) {
        DAT_0016de40 = 0;
        puVar1 = FUN_0001168c(auStack_38,0);
        DAT_0016d10c = *puVar1;
        DAT_0016d110 = puVar1[1];
        DAT_0016d114 = puVar1[2];
        DAT_0016d118 = puVar1[3];
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x72,0,0);
      }
      else if (param_5 <= param_4) {
        puVar1 = FUN_0001168c(auStack_38,param_4);
        DAT_0016d0fc = *puVar1;
        DAT_0016d100 = puVar1[1];
        DAT_0016d104 = puVar1[2];
        DAT_0016d108 = puVar1[3];
        puVar1 = FUN_0001168c(auStack_38,param_5);
        DAT_0016d10c = *puVar1;
        DAT_0016d110 = puVar1[1];
        DAT_0016d114 = puVar1[2];
        DAT_0016d118 = puVar1[3];
        DAT_0016de40 = param_5;
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        DbgDebugPrint(6,0,L"%S %d, set pos %d ms","get_play_status_cb",0x42c,param_5);
        IpcPostMsg(6,0x15,0x72,0,0);
      }
    }
    DAT_0016d0ec = 1;
  }
  else {
    DAT_0016d0ec = 0;
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x previous play_state 0x%x",
                  "get_play_status_cb",param_2,param_3,DAT_0016d11c);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016288 FUN_00016288 */

/* Boundary evidence: original MIPS .pdata 00016288..00016343. Semantic name remains unreviewed. */

void FUN_00016288(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 byte param_6)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,0,L"%S ipod status 0x%x uw_status 0x%x play_state 0x%x","get_play_status_cb2",0,
                  0,param_6);
    DAT_0016d11c = (ushort)param_6;
  }
  else {
    DbgDebugPrint(6,0,L"[ERROR] %S ipod status 0x%x uw_status 0x%x previous play_state 0x%x",
                  "get_play_status_cb2",param_2,param_3,DAT_0016d11c);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016344 FUN_00016344 */

/* Boundary evidence: original MIPS .pdata 00016344..000164bf. Semantic name remains unreviewed. */

void FUN_00016344(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    if (DAT_0016de28 == 0) {
      NKDbgPrintfW(L">> [%d]->[%d]\r\n",DAT_0016de58,param_4);
      DAT_0016de58 = param_4;
    }
    else {
      NKDbgPrintfW(L"~!@# 2222 Opss!!!! [%d]->[%d]\r\n",DAT_0016de58,param_4);
    }
    iVar1 = DAT_0016d128;
    DAT_0016d128 = param_4;
    if ((DAT_0016d0cc != 0) &&
       (MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c), iVar1 != param_4)) {
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x","get_cur_play_track_idx_cb",
                  param_2,param_3);
    if ((param_3 != 0xb) && ((param_3 != 0x12 && (param_2 != 4)))) {
      DAT_0016ddc8 = 2;
    }
    DbgDebugPrint(6,3,L"%S ipod connect is fail! ","get_cur_play_track_idx_cb");
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 000164c0 FUN_000164c0 */

/* Boundary evidence: original MIPS .pdata 000164c0..000165af. Semantic name remains unreviewed. */

void FUN_000164c0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016ddc8 = 1;
    DAT_0016de44 = param_4;
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x num_of_tracks %d",
                  "get_num_play_tracks_cb",param_2,param_3,param_4);
    if ((param_3 != 0xb) && ((param_3 != 0x12 && (param_2 != 4)))) {
      DAT_0016ddc8 = 2;
      DbgDebugPrint(6,3,L"%S ipod connect is fail! ","get_num_play_tracks_cb");
    }
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 000165b0 FUN_000165b0 */

/* Boundary evidence: original MIPS .pdata 000165b0..0001660f. Semantic name remains unreviewed. */

void FUN_000165b0(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S set_repeat_cb ipod_status 0x%x uw_status 0x%x","set_repeat_cb",
                  param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016610 FUN_00016610 */

/* Boundary evidence: original MIPS .pdata 00016610..000166a7. Semantic name remains unreviewed. */

void FUN_00016610(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002e221 = (undefined1)param_4;
    IpcPostMsg(6,0x15,0x6c,1,&DAT_0002e221);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S get_repeat_cb repeat mode %d, ipod_status 0x%x uw_status 0x%x",
                  "get_repeat_cb",param_4,param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 000166a8 FUN_000166a8 */

/* Boundary evidence: original MIPS .pdata 000166a8..00016707. Semantic name remains unreviewed. */

void FUN_000166a8(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S set_shuffle_cb ipod_status 0x%x uw_status 0x%x","set_shuffle_cb",
                  param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016708 FUN_00016708 */

/* Boundary evidence: original MIPS .pdata 00016708..0001679b. Semantic name remains unreviewed. */

void FUN_00016708(undefined4 param_1,int param_2,int param_3,undefined1 param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002e222 = param_4;
    IpcPostMsg(6,0x15,0x6b,1,&DAT_0002e222);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","get_shuffle_cb",param_2,param_3
                 );
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 0001679c FUN_0001679c */

/* Boundary evidence: original MIPS .pdata 0001679c..00016903. Semantic name remains unreviewed. */

void FUN_0001679c(void)

{
  int iVar1;
  int iVar2;
  char *in_a3;
  ushort in_stack_00000010;
  
  iVar1 = DAT_0016d0cc;
  if (DAT_0016d0cc == 0) {
    DbgDebugPrint(6,2,L"%S g_ocsharedMemory NULL","idx_play_track_title_cb");
  }
  else {
    iVar2 = strcmp(&DAT_0016d150,in_a3);
    if (iVar2 == 0) {
      DbgDebugPrint(6,1,L"%S same title","idx_play_track_title_cb");
      MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
    else {
      DAT_0016d11e = in_stack_00000010;
      memset(&DAT_0016d150,0,0x400);
      memcpy(&DAT_0016d150,in_a3,(uint)in_stack_00000010);
      MSHM_Dll_Write(iVar1,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016904 FUN_00016904 */

/* Boundary evidence: original MIPS .pdata 00016904..00016ad7. Semantic name remains unreviewed. */

void FUN_00016904(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  char *in_a3;
  ushort in_stack_00000010;
  
  iVar1 = DAT_0016d0cc;
  if (DAT_0016d0cc == 0) {
    pwVar4 = L"%S g_ocsharedMemory NULL";
    uVar3 = 2;
  }
  else {
    if ((in_stack_00000010 == 0) || (*in_a3 == '\0')) {
      memset(&DAT_0016d950,0,0x400);
      memcpy(&DAT_0016d950,&DAT_0016d150,(uint)DAT_0016d11e);
      DAT_0016d122 = DAT_0016d11e;
      MSHM_Dll_Write(iVar1,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x70,0,0);
      DbgDebugPrint(6,3,L"%S %d empty artist name","idx_play_track_artist2_name_cb",0x57a);
      goto LAB_00016aa8;
    }
    iVar2 = strcmp(&DAT_0016d950,in_a3);
    if (iVar2 != 0) {
      DAT_0016d122 = in_stack_00000010;
      memset(&DAT_0016d950,0,0x400);
      memcpy(&DAT_0016d950,in_a3,(uint)in_stack_00000010);
      MSHM_Dll_Write(iVar1,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x70,0,0);
      goto LAB_00016aa8;
    }
    pwVar4 = L"%S same artist name";
    uVar3 = 1;
  }
  DbgDebugPrint(6,uVar3,pwVar4,"idx_play_track_artist2_name_cb");
LAB_00016aa8:
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016ad8 FUN_00016ad8 */

/* Boundary evidence: original MIPS .pdata 00016ad8..00016b53. Semantic name remains unreviewed. */

void FUN_00016ad8(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DbgDebugPrint(6,0,L"%S uw_status 0x%x","start_audio_read_cb",0);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] : %S uw_status 0x%x","start_audio_read_cb",param_2);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016b54 FUN_00016b54 */

/* Boundary evidence: original MIPS .pdata 00016b54..00016bb3. Semantic name remains unreviewed. */

void FUN_00016b54(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status %d, uw_status%d","play_cur_select_cb",param_2,param_3
                 );
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00016bb4 FUN_00016bb4 */

/* Boundary evidence: original MIPS .pdata 00016bb4..00016dd3. Semantic name remains unreviewed. */

void FUN_00016bb4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,void *param_6,
                 ushort param_7,int param_8)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  uint uVar3;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016ddc8 = 1;
    if (DAT_0016d0cc != 0) {
      if (param_5 != 0) {
        if (param_4 == 0) {
          DAT_0016dd56 = *(ushort *)(param_5 + 2);
          DAT_0016dd54 = *(ushort *)(param_5 + 4);
          DAT_0016ddc0 = 0;
        }
        if (DAT_0016ddf8 == (char *)0x0) {
          NKDbgPrintfW(L">>[FAIL] g_pucImageBuffer is NULL!!!!!!!!!!!!!!!!!!!! \r\n");
          return;
        }
        memcpy(DAT_0016ddf8 + DAT_0016ddc0,param_6,(uint)param_7);
        DAT_0016ddc0 = param_7 + DAT_0016ddc0;
        if (param_8 != 0) {
          return;
        }
        uVar3 = DAT_0016ddc0 - 2 & 3;
        if (uVar3 != 0) {
          DAT_0016ddc0 = DAT_0016ddc0 + uVar3;
        }
        FUN_00013078(DAT_0016ddf8,DAT_0016ddc0,(uint)DAT_0016dd56,(uint)DAT_0016dd54);
        DAT_0016dddc = 0;
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x71,0,0);
        return;
      }
      DAT_0016dddc = 0;
      pwVar2 = L"%S art_data is Null";
      uVar1 = 1;
      goto LAB_00016dac;
    }
    pwVar2 = L"%S shared memory is null";
  }
  else {
    if ((param_3 != 0xb) && ((param_3 != 0x12 && (param_2 != 4)))) {
      DAT_0016ddc8 = 2;
    }
    DAT_0016dddc = 0;
    EventModify(DAT_0016ddcc,3);
    pwVar2 = L"%S ipod connect is fail! ";
  }
  uVar1 = 3;
LAB_00016dac:
  DbgDebugPrint(6,uVar1,pwVar2,"track_artwork_data_cb");
  return;
}



/* 00016dd4 FUN_00016dd4 */

/* Boundary evidence: original MIPS .pdata 00016dd4..00016ea3. Semantic name remains unreviewed. */

void FUN_00016dd4(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,short param_5)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016ddb8 = param_5;
    if (param_5 == 0) {
      DbgDebugPrint(6,0,L"%S artwork data is 0","track_artwork_times_cb",0);
    }
    else {
      DAT_0016ddbc = *param_4;
      DbgDebugPrint(6,0,L"%S artwork data is %d","track_artwork_times_cb",param_5);
    }
  }
  else {
    NKDbgPrintfW(L"ERROR %S ipod_status %d, uw_status %d\n","track_artwork_times_cb",param_2,param_3
                );
    DAT_0016ddb8 = 0;
  }
  EventModify(DAT_0016ddd4,3);
  return;
}



/* 00016ea4 FUN_00016ea4 */

/* Boundary evidence: original MIPS .pdata 00016ea4..00016f4f. Semantic name remains unreviewed. */

void FUN_00016ea4(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  if (((param_2 == 0) && (param_3 == 0)) && (1 < param_4)) {
    uVar2 = 0;
    if (param_4 != 0) {
      uVar4 = 0;
      do {
        puVar3 = (undefined2 *)(uVar4 * 8 + param_5);
        uVar1 = puVar3[2];
        if (uVar2 < uVar1) {
          DAT_0002e5c4 = *puVar3;
          uVar2 = uVar1;
        }
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < param_4);
    }
  }
  else {
    NKDbgPrintfW(
                L"~!@#$ ERROR artwork_formats_cb ipod_status %d, uw_status %d, num_of_formats %d\r\n"
                );
  }
  EventModify(DAT_0016ddd4,3);
  return;
}



/* 00016f50 FUN_00016f50 */

/* Boundary evidence: original MIPS .pdata 00016f50..0001705b. Semantic name remains unreviewed. */

undefined4 FUN_00016f50(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  DAT_0016ddcc = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_0016ddd0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_0016ddd4 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0;
  DAT_0016ddd8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  FUN_0001a730(&PTR_FUN_0002e1a8);
  iVar1 = FUN_00020744(0,uVar2,uVar3,uVar4);
  if (iVar1 != 0) {
    DbgDebugPrint(6,3,L"%S wince_usbware_entry error %d","init_ipod_driver",iVar1);
  }
  DbgDebugPrint(6,3,L"%S init ipod driver done","init_ipod_driver");
  return 1;
}



/* 0001705c FUN_0001705c */

/* Boundary evidence: original MIPS .pdata 0001705c..0001715f. Semantic name remains unreviewed. */

undefined4 FUN_0001705c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EventModify(DAT_0016ddcc,3);
  EventModify(DAT_0016ddd0,3);
  uVar1 = 3;
  EventModify(DAT_0016ddd4);
  FUN_000136c0();
  FUN_00013f84();
  FUN_00020788(0,uVar1,param_3,param_4);
  if (DAT_0016ddcc != 0) {
    CloseHandle((HANDLE)DAT_0016ddcc);
    DAT_0016ddcc = 0;
  }
  if (DAT_0016ddd0 != 0) {
    CloseHandle((HANDLE)DAT_0016ddd0);
    DAT_0016ddd0 = 0;
  }
  if (DAT_0016ddd4 != 0) {
    CloseHandle((HANDLE)DAT_0016ddd4);
    DAT_0016ddd4 = 0;
  }
  if (DAT_0016ddd8 != 0) {
    CloseHandle((HANDLE)DAT_0016ddd8);
    DAT_0016ddd8 = 0;
  }
  return 1;
}



/* 00017160 FUN_00017160 */

/* Boundary evidence: original MIPS .pdata 00017160..00017277. Semantic name remains unreviewed. */

void FUN_00017160(undefined4 param_1,int param_2,int param_3,undefined4 param_4,byte param_5,
                 byte param_6)

{
  DAT_0002e5c8 = (uint)CONCAT11(param_5,param_6);
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,3,L"%S xtended lingo vesion - maj_ver:%x  min_ver:%x","ret_lingo_ver_cb",
                  (uint)param_5,(uint)param_6);
    DAT_0002e5c8 = (uint)param_5 * 100 + (uint)param_6;
    if (DAT_0002e5c8 < 0x71) {
      FUN_00014638(0);
    }
    else {
      FUN_00014638(1);
      if (0x71 < (int)DAT_0002e5c8) {
        FUN_00014648(1);
      }
    }
  }
  else {
    DbgDebugPrint(6,3,L"%S ipod_status 0x%x  uw_status 0x%x","ret_lingo_ver_cb",param_2,param_3);
  }
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00017278 FUN_00017278 */

/* Boundary evidence: original MIPS .pdata 00017278..000172c7. Semantic name remains unreviewed. */

void FUN_00017278(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DbgDebugPrint(6,3,L"%S ipod status %d uw_status %d ","set_remote_event_nofit_cb",param_2,param_3);
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 000172c8 FUN_000172c8 */

/* Boundary evidence: original MIPS .pdata 000172c8..00017357. Semantic name remains unreviewed. */

void FUN_000172c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 void *param_5,uint param_6)

{
  DbgDebugPrint(6,3,L"%S ipod status %d uw_status %d model_id %x model_num %S model_len %d",
                "get_ipod_model_cb",param_2,param_3,param_4,param_5,param_6);
  FUN_0001451c(param_4,param_5,param_6);
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00017358 FUN_00017358 */

/* Boundary evidence: original MIPS .pdata 00017358..00017497. Semantic name remains unreviewed. */

void FUN_00017358(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte local_10;
  uint local_c;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    if (param_4 == 0) {
      local_c = (uint)*(byte *)(param_5 + 6);
      local_10 = *(byte *)(param_5 + 4);
      if ((*(byte *)(param_5 + 6) & 0x20) != 0) {
        FUN_000145b8(1);
      }
      if ((local_10 & 1) != 0) {
        FUN_000145d8(1);
      }
    }
    else if ((param_4 == 4) && ((*(byte *)(param_5 + 7) & 2) != 0)) {
      FUN_00014638(1);
    }
    DbgDebugPrint(6,0,L"%S ipod_status 0x%x  uw_status 0x%x app_comm_%d autolaunch_%d\n",
                  "get_options_for_lingo_cb",0,0,local_c >> 5 & 1,local_10 & 1);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x  uw_status 0x%x","get_options_for_lingo_cb",
                  param_2,param_3);
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00017498 FUN_00017498 */

/* Boundary evidence: original MIPS .pdata 00017498..00017583. Semantic name remains unreviewed. */

void FUN_00017498(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016ddf0 = param_5;
    DAT_0016ddc8 = 1;
    DAT_0016ddec = param_4;
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %s: ipod_status [%d], uw_status [%d]\r\n",
                  "get_supported_event_notification_cb",param_2,param_3);
    if ((param_3 != 0xb) && ((param_3 != 0x12 && (param_2 != 4)))) {
      DAT_0016ddc8 = 2;
      NKDbgPrintfW(L">> iPod connect_failed!!!\r\n");
    }
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 00017584 FUN_00017584 */

/* Boundary evidence: original MIPS .pdata 00017584..000175f7. Semantic name remains unreviewed. */

void FUN_00017584(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %s : ipod_status [%d], uw_status [%d]\r\n",
                  "set_event_notification_cb",param_2,param_3);
  }
  DAT_0016ddf4 = (undefined1)param_2;
  EventModify(DAT_0016ddcc,3);
  return;
}



/* 000175f8 FUN_000175f8 */

/* Boundary evidence: original MIPS .pdata 000175f8..000176af. Semantic name remains unreviewed. */

undefined4
FUN_000175f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00013f44(param_2);
  FUN_00013f54((short)param_3,(char)param_4);
  puVar1 = FUN_00013f68();
  *param_5 = puVar1;
  DbgDebugPrint(6,3,L"%S Session Opened : ID_%d, Protocod Index : %d\n","mylink_iapp_open_cb",
                param_3,param_4);
  iVar2 = FUN_00014500();
  if ((iVar2 == 0) || (iVar2 = FUN_00014444(), iVar2 == 0)) {
    puVar3 = (undefined4 *)FUN_00013f68();
    FUN_00014454(1,0x66,puVar3);
  }
  return 0;
}



/* 000176b0 FUN_000176b0 */

/* Boundary evidence: original MIPS .pdata 000176b0..000176f7. Semantic name remains unreviewed. */

void FUN_000176b0(undefined2 *param_1)

{
  DbgDebugPrint(6,3,L"Session Closed...(SessionID_%d, ProtoID_%d)\n",*param_1,
                *(undefined1 *)(param_1 + 1));
  FUN_00013f44(0);
  return;
}



/* 00017700 FUN_00017700 */

/* Boundary evidence: original MIPS .pdata 00017700..00017907. Semantic name remains unreviewed. */

void FUN_00017700(void)

{
  wchar_t *lpText;
  
  DAT_0016ddf8 = FUN_000110dc(0x100000);
  if (DAT_0016ddf8 == (void *)0x0) {
    DbgDebugPrint(6,3,
                  L"***************[MgriPod] CExtMemUtil::getExtMemory(MAX_BIT_STREAM_LENGH); ExtMemory Alloc failed***************"
                 );
    DbgDebugPrint(6,3,L"***************[MgriPod] ExtMemory Alloc failed  %s, %d***************",
                  L"InitIpodManager",0x1a5);
  }
  else {
    DbgDebugPrint(6,3,L"***************[MgriPod] ExtMemory Alloc Successed  %s, %X***************",
                  L"InitIpodManager",DAT_0016ddf8);
  }
  DAT_0016d0cc = MSHM_Dll_CreateShmClassObj(L"ShmMxMgrIpodAppMain");
  MSHM_Dll_MakeMappingReadWrite(DAT_0016d0cc,L"ShmFmMgrIpodAppMain",0xc5c,0xffffffff);
  DAT_0016d0d0 = MSHM_Dll_CreateShmClassObj(L"ShmMxMgrIpodAppMainList");
  MSHM_Dll_MakeMappingReadWrite(DAT_0016d0d0,L"ShmFmMgrIpodAppMainList",&DAT_0013d628,0xffffffff);
  DAT_0016de04 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0x9c54,
                                    L"ShmFmMgrIpodAppMainListUID");
  if (DAT_0016de04 == (HANDLE)0x0) {
    GetLastError();
    lpText = L"IPOD Shared Memory CreateFileMapping FAIL";
  }
  else {
    DAT_0016de08 = MapViewOfFile(DAT_0016de04,6,0,0,0x9c54);
    if (DAT_0016de08 != (LPVOID)0x0) {
      memset(DAT_0016de08,0,0x9c54);
      FUN_0001136c(&DAT_0016d0fc);
      FUN_00016f50();
      SetTimer(DAT_0016de00,0xc8e,1000,(TIMERPROC)0x0);
      return;
    }
    CloseHandle(DAT_0016de04);
    lpText = L"IPOD Shared Memory MapViewOfFile FAIL";
    DAT_0016de04 = (HANDLE)0x0;
  }
  MessageBoxW((HWND)0x0,lpText,L"Warning",0);
  return;
}



/* 00017908 FUN_00017908 */

/* Boundary evidence: original MIPS .pdata 00017908..00017aeb. Semantic name remains unreviewed. */

void FUN_00017908(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  wchar_t *_Format;
  HANDLE hObject;
  HKEY local_430 [2];
  wchar_t local_428;
  undefined1 auStack_426 [518];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0002e28c;
  DbgSetDebugOnOff(6,1);
  DbgSetDebugLevel(6,1);
  FUN_00017700();
  DbgDebugPrint(6,0,L"%S MgrIpod Create [%s.%s]","OnInit",L"2015-08-13",L"16314");
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_430);
  if (LVar1 == 0) {
    _snwprintf_s(awStack_220,0x104,0xffffffff,L"%s [%s]",L"5.1.2",L"20140430");
    sVar2 = wcslen(awStack_220);
    RegSetValueExW(local_430[0],L"VerMgrIpod",0,1,(BYTE *)awStack_220,sVar2 << 1);
    RegCloseKey(local_430[0]);
  }
  local_428 = L'\0';
  memset(auStack_426,0,0x206);
  _Format = (wchar_t *)IpcGetProcessName(6);
  swprintf(&local_428,0x2b6f8,_Format,L"2015-08-13",L"16314");
  hObject = CreateFileW(&local_428,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  FUN_000279ec(local_18);
  return;
}



/* 00017aec FUN_00017aec */

/* Boundary evidence: original MIPS .pdata 00017aec..00017bcb. Semantic name remains unreviewed. */

void FUN_00017aec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0001705c(param_1,param_2,param_3,param_4);
  if (DAT_0016d0d0 != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016d0d0 = 0;
  }
  if (DAT_0016d0cc != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016d0cc = 0;
  }
  if (DAT_0016de54 != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016de54 = 0;
  }
  if (DAT_0016de08 != (LPCVOID)0x0) {
    UnmapViewOfFile(DAT_0016de08);
    DAT_0016de08 = (LPCVOID)0x0;
  }
  if (DAT_0016de04 != 0) {
    CloseHandle((HANDLE)DAT_0016de04);
    DAT_0016de04 = 0;
  }
  return;
}



/* 00017bcc FUN_00017bcc */

/* Boundary evidence: original MIPS .pdata 00017bcc..0001807f. Semantic name remains unreviewed. */

LRESULT FUN_00017bcc(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  LPARAM local_resc;
  uint local_40;
  HKEY local_3c;
  DWORD local_38 [2];
  uint local_30;
  uint local_2c;
  uint local_28;
  ushort *local_24;
  undefined1 auStack_20 [16];
  
  local_resc = param_4;
  if (param_2 == 1) {
    DAT_0016de00 = param_1;
    FUN_00017908();
    SetTimer(param_1,0x3e9,0x9c4,(TIMERPROC)0x0);
  }
  else if (param_2 == 2) {
    FUN_00017aec(param_1,2,param_3,param_4);
    KillTimer(param_1,0x3e9);
    PostQuitMessage(0);
  }
  else if (param_2 != 0xf) {
    if (param_2 != 0x4a) {
      if (param_2 == 0x113) {
        if (param_3 == 1000) {
          KillTimer(param_1,1000);
          IpcPostMsg(6,6,0x3ea,0,0);
          return 0;
        }
        if (param_3 == 0x3e9) {
          KillTimer(param_1,0x3e9);
          DAT_0016de0c = 0;
          DAT_0016de10 = 0;
          return 0;
        }
        if (param_3 == 0x3eb) {
          KillTimer(param_1,0x3eb);
          IpcPostMsg(6,6,0x3ec,0,0);
          return 0;
        }
        if (param_3 == 0x3ec) {
          KillTimer(param_1,0x3ec);
          IpcPostMsg(6,6,0x3ed,0,0);
          return 0;
        }
        if (param_3 == 0x3ed) {
          KillTimer(param_1,0x3ed);
          DbgDebugPrint(6,3,L"%S [TIMER_FORCE_REQINFO_ID] IDM_MIPOD_AMAIN_CHANGED_TRACK idx %d",
                        "WndProc",DAT_0016d128);
          FUN_00011534();
          FUN_00011bc8(DAT_0016d128);
          FUN_00011b40(DAT_0016d128);
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          local_3c = DAT_0016d128;
          IpcPostMsg(6,0x15,0x6d,4,&local_3c);
          return 0;
        }
        if (param_3 == 0xc8e) {
          KillTimer(param_1,0xc8e);
          memset(&local_40,0,4);
          local_40 = local_40 & 0xffe03f04 | 0x2004;
          LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\iPod",0,0x20019,&local_3c
                               );
          if (LVar2 == 0) {
            local_38[1] = 4;
            local_38[0] = 4;
            RegQueryValueExW(local_3c,L"Inserted",(LPDWORD)0x0,local_38 + 1,(LPBYTE)&DAT_0016de10,
                             local_38);
            RegCloseKey(local_3c);
          }
          if (DAT_0016de10 == 0) {
            IpcPostMsg(6,1,9,4,&local_40);
            uVar3 = IpcGetProcessName(6);
            NKDbgPrintfW(L"\r\n~!@#$ [%s] TIMER_INIT_DETACH... g_bHiddenState : 0 \r\n",uVar3);
            return 0;
          }
          DAT_0016de10 = 0;
          return 0;
        }
        if (param_3 != 0xc90) {
          return 0;
        }
        KillTimer(param_1,0xc90);
        if ((DAT_0016ddb0 != 0) && (DAT_0016ddb4 != 0)) {
          return 0;
        }
        FUN_00013dc8();
        return 0;
      }
      if (param_2 != 0x8064) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        return LVar1;
      }
    }
    if (DAT_0016d0d8 == 0) {
      NKDbgPrintfW(L"\r\n~!@#$ NOT Connected Ipod...\r\n");
    }
    else {
      puVar4 = (uint *)IpcGetMsg(auStack_20,param_2,param_3,&local_resc);
      local_30 = *puVar4;
      local_2c = puVar4[1];
      local_28 = puVar4[2];
      local_24 = (ushort *)puVar4[3];
      uVar5 = local_30 & 0xffff;
      if (uVar5 == 1) {
        LVar1 = FUN_000193d0(*puVar4,(short)puVar4[1],puVar4[2],(int *)puVar4[3]);
        return LVar1;
      }
      if (uVar5 == 6) {
        LVar1 = FUN_0001995c(*puVar4,(short)puVar4[1]);
        return LVar1;
      }
      if (uVar5 == 0x15) {
        LVar1 = FUN_0001842c(*puVar4,(ushort)puVar4[1],puVar4[2],local_24);
        return LVar1;
      }
    }
  }
  return 0;
}



/* 00018080 FUN_00018080 */

/* Boundary evidence: original MIPS .pdata 00018080..000180e3. Semantic name remains unreviewed. */

void FUN_00018080(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00017bcc;
  local_30.cbClsExtra = 0;
  local_30.cbWndExtra = 0;
  local_30.hIcon = (HICON)0x0;
  local_30.hCursor = (HCURSOR)0x0;
  local_30.hInstance = param_1;
  local_30.hbrBackground = GetStockObject(5);
  local_30.lpszMenuName = (LPCWSTR)0x0;
  local_30.lpszClassName = param_2;
  RegisterClassW(&local_30);
  return;
}



/* 000180e4 FUN_000180e4 */

/* Boundary evidence: original MIPS .pdata 000180e4..000181c7. Semantic name remains unreviewed. */

undefined4 FUN_000180e4(HINSTANCE param_1,int param_2)

{
  LPCWSTR pWVar1;
  int iVar2;
  LPCWSTR lpClassName;
  HWND hWnd;
  
  DAT_0016ddfc = param_1;
  pWVar1 = (LPCWSTR)IpcGetProcessName(6);
  iVar2 = FUN_00018080(param_1,pWVar1);
  if (iVar2 != 0) {
    pWVar1 = (LPCWSTR)IpcGetProcessName(6);
    lpClassName = (LPCWSTR)IpcGetProcessName(6);
    hWnd = CreateWindowExW(0x4000000,lpClassName,pWVar1,0x80000000,-0x80000000,-0x80000000,
                           -0x80000000,-0x80000000,(HWND)0x0,(HMENU)0x0,param_1,(LPVOID)0x0);
    if (hWnd != (HWND)0x0) {
      ShowWindow(hWnd,param_2);
      UpdateWindow(hWnd);
      return 1;
    }
  }
  return 0;
}



/* 000181c8 FUN_000181c8 */

/* Boundary evidence: original MIPS .pdata 000181c8..0001842b. Semantic name remains unreviewed. */

undefined4 FUN_000181c8(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  int iVar1;
  LPCWSTR lpName;
  HANDLE hMutex;
  DWORD DVar2;
  undefined4 uVar3;
  LSTATUS LVar4;
  BOOL BVar5;
  HKEY local_50;
  DWORD local_4c [3];
  MSG MStack_40;
  
  if (param_3 == (wchar_t *)0x0) {
LAB_000183f8:
    FUN_00011274();
  }
  else {
    iVar1 = wcsncmp(param_3,L"er10q4c$=4G2g-H2tq9X@mid",0x18);
    if (iVar1 != 0) {
      iVar1 = wcsncmp(param_3,L"Resume",6);
      if (iVar1 != 0) goto LAB_000183f8;
      DAT_0016de0c = 1;
    }
    lpName = (LPCWSTR)IpcGetProcessName(6);
    hMutex = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,lpName);
    DVar2 = GetLastError();
    if (hMutex != (HANDLE)0x0) {
      ReleaseMutex(hMutex);
    }
    if (DVar2 == 0xb7) {
      CloseHandle(hMutex);
      FUN_00011274();
      uVar3 = IpcGetProcessName(6);
      NKDbgPrintfW(L"\r\n~!@#$ [%s] Program is running...\r\n",uVar3);
    }
    else {
      if ((DAT_0016de0c == 0) &&
         (LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\iPod",0,0x20019,&local_50
                               ), LVar4 == 0)) {
        local_4c[1] = 4;
        local_4c[0] = 4;
        RegQueryValueExW(local_50,L"Inserted",(LPDWORD)0x0,local_4c + 1,(LPBYTE)&DAT_0016de10,
                         local_4c);
        RegCloseKey(local_50);
      }
      iVar1 = FUN_000180e4(param_1,param_4);
      if (iVar1 != 0) {
        while (BVar5 = GetMessageW(&MStack_40,(HWND)0x0,0,0), BVar5 != 0) {
          TranslateMessage(&MStack_40);
          DispatchMessageW(&MStack_40);
        }
        FUN_00011274();
        CloseHandle(hMutex);
        return MStack_40.wParam;
      }
      FUN_00011274();
      CloseHandle(hMutex);
    }
  }
  return 0;
}



/* 0001842c FUN_0001842c */

/* Boundary evidence: original MIPS .pdata 0001842c..000193cf. Semantic name remains unreviewed. */

undefined4 FUN_0001842c(undefined4 param_1,ushort param_2,undefined4 param_3,ushort *param_4)

{
  uint uVar1;
  int iVar2;
  UINT_PTR nIDEvent;
  uint uVar3;
  
  while (DAT_0016dddc != 0) {
    Sleep(100);
    NKDbgPrintfW(&PTR_DAT_0002c114);
  }
  if (param_2 < 0x70) {
    if (param_2 == 0x6f) {
      DAT_0016de4c = 0;
      DAT_0016de50 = 1;
      if (DAT_0016de30 == 1) {
        DAT_0016de4c = 0;
        DAT_0016de50 = 1;
        return 0;
      }
      if (DAT_0016d11c == 1) {
        FUN_0001235c(0xf0);
        DAT_0016de14 = 1;
      }
      FUN_00011d08();
      return 0;
    }
    if (param_2 < 0x6a) {
      if (param_2 == 0x69) {
        FUN_000119d4();
        if (DAT_0002e222 < 2) {
          return 0;
        }
        uVar1 = 1;
      }
      else {
        if (param_2 == 0x65) {
          if ((uint)DAT_0002e221 == (uint)(byte)*param_4) {
            return 0;
          }
          FUN_00013378((uint)(byte)*param_4);
          return 0;
        }
        if (param_2 != 0x66) {
          if (param_2 == 0x67) {
            if ((DAT_0016de30 == 0) || (DAT_0002e5c0 == '\a')) {
              DAT_0016de4c = 0;
              if (DAT_0016de40 / 1000 == (uint)*param_4) {
                DAT_0016de4c = 0;
                return 0;
              }
              DAT_0016de40 = (uint)*param_4 * 1000;
            }
            else {
              NKDbgPrintfW(L">> don\'t change track pos!!! [ %d ]\r\n",(uint)*param_4 * 1000);
              DAT_0016de40 = 0;
            }
            FUN_00013584(DAT_0016de40);
            return 0;
          }
          if (param_2 != 0x68) {
            return 0;
          }
          FUN_00011720();
          return 0;
        }
        uVar1 = (uint)(byte)*param_4;
        if (DAT_0002e222 == uVar1) {
          return 0;
        }
      }
      FUN_00011908(uVar1);
      FUN_000119d4();
      return 0;
    }
    if (param_2 != 0x6a) {
      if (param_2 == 0x6d) {
        DAT_0016de4c = 0;
        DAT_0016de50 = 1;
        if (DAT_0016de30 == 0) {
          FUN_00011fcc();
        }
        if (DAT_0016d11c != 0) {
          if (DAT_0016de44 < 2) {
            if (((DAT_0002e221 == 2) || (DAT_0016de44 == 0)) || (DAT_0016d128 != DAT_0016de44 - 1))
            {
              FUN_00011a88();
              goto LAB_00018c5c;
            }
            if (DAT_0016de44 == 1) {
              return 0;
            }
            iVar2 = 0;
            goto LAB_0001892c;
          }
          DAT_0016de28 = 1;
          KillTimer(DAT_0016de00,1000);
          DAT_0016de58 = DAT_0016de58 + 1;
          NKDbgPrintfW(L"~~~~~!!!! NEXT %d | %d, g_ucShuffle_mode %d ,g_ucRepeat_mode %d ((%d)) \r\n"
                       ,DAT_0016de58,DAT_0016de44,DAT_0002e222,DAT_0002e221,DAT_0016de30);
          if (DAT_0016de44 <= DAT_0016de58) {
            if (DAT_0016de30 == 0) {
              DAT_0016de30 = 1;
            }
            DAT_0016de58 = 0;
            DAT_0016de40 = 0;
            IpcPostMsg(6,6,0x3ea,0,0);
            return 0;
          }
          if (DAT_0016de30 == 0) {
            if (DAT_0016d11c == 1) {
              FUN_0001364c(0);
              DAT_0016de34 = 1;
            }
            DAT_0016de30 = 1;
          }
          DAT_0016de40 = 0;
          if ((DAT_0002e222 != 0) || (DAT_0002e5c0 == '\a')) {
            DAT_0016de48 = 1;
            FUN_00011a88();
            FUN_00011534();
          }
          if (((DAT_0002e221 != 1) || (DAT_0002e222 != 1)) &&
             ((FUN_00011b40(DAT_0016de58), DAT_0016d950 != '\0' ||
              ((DAT_0016d951 != '\0' || (DAT_0016d952 != '\0')))))) {
            memset(&DAT_0016d950,0,0x400);
            MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
            IpcPostMsg(6,0x15,0x70,0,0);
          }
          goto LAB_000188e8;
        }
        if (DAT_0002e5c0 == '\a') {
          FUN_000139f8(7,0);
          if ((DAT_0016d128 < DAT_0016de44 - 1) && (DAT_0016d128 != 0xffffffff)) {
            return 0;
          }
          if (DAT_0002e221 == 0) {
            return 0;
          }
          FUN_000123ec(7,0);
          DAT_0016de44 = DAT_0002e5cc;
          FUN_00011b40(0);
          FUN_000138f8();
          FUN_00013870();
          return 0;
        }
      }
      else {
        if (param_2 != 0x6e) {
          return 0;
        }
        DAT_0016de50 = 1;
        DAT_0016de4c = 0;
        uVar1 = DAT_0016d128;
        uVar3 = DAT_0016de58;
        NKDbgPrintfW(L"g_ucShuffle_mode %d, g_ucRepeat_mode %d, g_ulTotalTrack %d, g_stPlayInfo.nCurPlayIdx %d g_nextTrack %d \r\n"
                     ,DAT_0002e222,DAT_0002e221,DAT_0016de44,DAT_0016d128,DAT_0016de58);
        if (DAT_0016de30 == 0) {
          FUN_00011fcc();
        }
        if (DAT_0016d11c != 0) {
          if (((DAT_0016d11c == 1) || (DAT_0016d11c == 2)) && (2999 < DAT_0016de40)) {
            FUN_000134b8(0);
            DAT_0016de40 = 0;
            return 0;
          }
          if (DAT_0016de44 < 2) {
            if (((DAT_0002e221 == 2) || (DAT_0016de44 == 0)) || (DAT_0016d128 != 0)) {
              FUN_00011c50();
LAB_00018c5c:
              FUN_00011534();
              return 0;
            }
            if (DAT_0016de44 == 1) {
              return 0;
            }
            iVar2 = DAT_0016de44 - 1;
LAB_0001892c:
            FUN_000114ac(iVar2);
            if (DAT_0016d11c != 1) {
              FUN_0001364c(0);
            }
            FUN_000138f8();
            return 0;
          }
          DAT_0016de28 = 1;
          KillTimer(DAT_0016de00,1000);
          DAT_0016de58 = DAT_0016de58 - 1;
          NKDbgPrintfW(L"~~~~~!!!! prev %d | %d, g_ucShuffle_mode %d\r\n",DAT_0016de58,DAT_0016de44,
                       DAT_0002e222,uVar1,uVar3);
          if (DAT_0016de44 <= DAT_0016de58) {
            NKDbgPrintfW(L"~~~~~!!!! prev2 %d | %d, g_ucShuffle_mode %d\r\n",DAT_0016de58,
                         DAT_0016de44,DAT_0002e222,uVar1,uVar3);
            if (DAT_0016de30 == 0) {
              DAT_0016de30 = 1;
            }
            DAT_0016de40 = 0;
            DAT_0016de58 = DAT_0016de44 - 1;
            IpcPostMsg(6,6,0x3ea,0,0);
            return 0;
          }
          if (DAT_0016de30 == 0) {
            if (DAT_0016d11c == 1) {
              FUN_0001364c(0);
              DAT_0016de34 = 1;
            }
            DAT_0016de30 = 1;
          }
          if ((DAT_0002e222 != 0) || (DAT_0002e5c0 == '\a')) {
            DAT_0016de48 = 1;
            FUN_00011c50();
            FUN_00011534();
          }
          if (((DAT_0002e221 != 1) || (DAT_0002e222 != 1)) &&
             ((FUN_00011b40(DAT_0016de58), DAT_0016d950 != '\0' ||
              ((DAT_0016d951 != '\0' || (DAT_0016d952 != '\0')))))) {
            memset(&DAT_0016d950,0,0x400);
            MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
            IpcPostMsg(6,0x15,0x70,0,0);
          }
LAB_000188e8:
          nIDEvent = 1000;
LAB_000188ec:
          SetTimer(DAT_0016de00,nIDEvent,1000,(TIMERPROC)0x0);
          return 0;
        }
        iVar2 = 0;
        if (DAT_0002e5c0 == '\a') {
          uVar1 = 7;
          goto LAB_00018a38;
        }
      }
      iVar2 = 0;
      uVar1 = 5;
LAB_00018a38:
      FUN_000139f8(uVar1,iVar2);
      return 0;
    }
    FUN_000138f8();
    if ((DAT_0016de38 != 1) || (DAT_0016d11c != 1)) goto LAB_00018e90;
    DAT_0016de50 = 1;
    NKDbgPrintfW(L"~!@# Oops!!!! => NOT ALLOWED STREAMING START [%d]\r\n",DAT_0016de18);
LAB_00018e84:
    iVar2 = 0;
  }
  else {
    if (0x75 < param_2) {
      if (param_2 == 0x76) {
        DbgDebugPrint(6,0,L"%S IDM_AMAIN_MIPOD_BACK_DB_RECORD","MsgProcessFromAppMain");
        FUN_000129d8((int)(char)*(int *)param_4,(*(int *)param_4 << 8) >> 0x10);
        return 0;
      }
      if (param_2 == 0x78) {
        DAT_0016de38 = 0;
        DAT_0016de4c = 0;
        NKDbgPrintfW(L"~!@# IDM_AMAIN_MIPOD_USER_PLAY g_bStartSeek : %d, g_bStreamStop : %d\r\n",
                     DAT_0016de30,DAT_0016de18);
        if (DAT_0016de30 == 1) {
          return 0;
        }
        if (DAT_0016de18 == 1) {
          DAT_0016de38 = 0;
          if (DAT_0016d11c != 0) {
            DAT_0016d11c = 1;
          }
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
          return 0;
        }
        if (DAT_0016d11c == 0) {
          uVar1 = 7;
          if (DAT_0002e5c0 != '\a') {
            uVar1 = 5;
          }
          FUN_000139f8(uVar1,0);
        }
        else {
          if (DAT_0016de40 == 0) {
            FUN_000134b8(0);
          }
          FUN_00013dc8();
        }
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
        DAT_0016de38 = 0;
        return 0;
      }
      if (param_2 != 0x79) {
        return 0;
      }
      if (DAT_0016de30 == 1) {
        return 0;
      }
      DAT_0016de38 = 0;
      NKDbgPrintfW(L"IDM_AMAIN_MIPOD_USER_PAUSE() g_ucExtPlayStatus %d, g_stPlayInfo.ucPlayerStatus %d\r\n"
                   ,DAT_0002e161,DAT_0016d11c);
      if (DAT_0002e161 == '\v') {
        FUN_00011fcc();
        if (DAT_0016de18 != 1) {
          if (DAT_0016d11c != 1) {
            return 0;
          }
          iVar2 = 0;
LAB_00018e50:
          FUN_0001364c(iVar2);
          return 0;
        }
      }
      else if (DAT_0016de18 == 1) {
        if (DAT_0016d11c != 0) {
          DAT_0016d11c = 2;
        }
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
      }
      else {
        FUN_000136c0();
      }
      DAT_0016de38 = 1;
      return 0;
    }
    if (param_2 == 0x75) {
      NKDbgPrintfW(L"~!@# IDM_AMAIN_MIPOD_SET_DB_RECORD CAT : %d, INDEX : %d\r\n",
                   (int)(char)*(int *)param_4,(*(int *)param_4 << 8) >> 0x10);
      if ((char)*param_4 == '\x05') {
        DAT_0002e224 = 5;
        DAT_0002e228 = (*(int *)param_4 << 8) >> 0x10;
        if (DAT_0016de28 == 0) {
          DAT_0016de58 = DAT_0002e228;
        }
        nIDEvent = 0x3eb;
        goto LAB_000188ec;
      }
      KillTimer(DAT_0016de00,0x3eb);
      DAT_0002e224 = 0xffffffff;
      DAT_0002e228 = 0xffffffff;
      uVar1 = (uint)(char)*(int *)param_4;
      iVar2 = (*(int *)param_4 << 8) >> 0x10;
      goto LAB_00018a38;
    }
    if (param_2 == 0x70) {
      DAT_0016de4c = 0;
      DAT_0016de50 = 1;
      if (DAT_0016de30 == 1) {
        DAT_0016de4c = 0;
        DAT_0016de50 = 1;
        return 0;
      }
      if (DAT_0016d11c == 1) {
        FUN_0001235c(0xf0);
        DAT_0016de14 = 1;
      }
      FUN_00011dd0();
      return 0;
    }
    if (param_2 != 0x71) {
      if (param_2 == 0x73) {
        if ((byte)*param_4 == 0xf) {
          FUN_0001379c();
          return 0;
        }
        FUN_0001247c((uint)(byte)*param_4);
        return 0;
      }
      if (param_2 != 0x74) {
        return 0;
      }
      DbgDebugPrint(6,0,L"%S IDM_AMAIN_MIPOD_GET_LIST","MsgProcessFromAppMain");
      FUN_000123a8();
      FUN_000124cc((uint)(byte)*param_4,0);
      return 0;
    }
    DAT_0016de24 = 0;
    DAT_0016de50 = 1;
    if ((DAT_0016d0e0 == 0) && (DAT_0016d0e4 == 0)) {
      DAT_0016de24 = 0;
      DAT_0016de50 = 1;
      return 0;
    }
    FUN_00011e98();
    FUN_000120f8();
    if (DAT_0016de14 != 1) {
      if (DAT_0016de38 != 1) {
        return 0;
      }
      if (DAT_0016d11c == 1) {
        FUN_0001364c(0);
        FUN_00011fcc();
      }
      FUN_000136c0();
      NKDbgPrintfW(L"~!@# IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE STATE => NOT ALLOWED STREAMING START [%d]-[%d]\r\n"
                   ,DAT_0016de18,DAT_0016d11c);
      return 0;
    }
    DAT_0016de14 = 0;
    if (DAT_0016de18 != 0) {
      if (DAT_0016de1c == 0) {
        iVar2 = 1;
        goto LAB_00018e50;
      }
      if (DAT_0016d11c != 1) {
        DAT_0016de14 = 0;
        return 0;
      }
      NKDbgPrintfW(L"~~~~~!!!! IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE\r\n");
      DAT_0016de24 = 1;
      goto LAB_00018e84;
    }
    if (DAT_0016d11c != 2) {
      if (DAT_0016de20 == 1) {
        DAT_0016de20 = 0;
        NKDbgPrintfW(L"!DM_AMIAN_MIPOD_END_FAST_FRD_REWIND FORCED PLAY REQUEST");
        FUN_000135fc();
        DAT_0016d11c = 1;
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
      }
      else if (DAT_0016d11c != 0) {
        NKDbgPrintfW(L"!DM_AMIAN_MIPOD_END_FAST_FRD_REWIND app_start_audio_read \r\n");
        FUN_00012310(0xf0);
      }
      goto LAB_00018e90;
    }
    iVar2 = 1;
  }
  FUN_0001364c(iVar2);
LAB_00018e90:
  FUN_00011fcc();
  return 0;
}



/* 000193d0 FUN_000193d0 */

/* Boundary evidence: original MIPS .pdata 000193d0..0001995b. Semantic name remains unreviewed. */

undefined4 FUN_000193d0(undefined4 param_1,short param_2,undefined4 param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  if (param_2 == 10) {
    uVar2 = 1;
    DbgDebugPrint(6,1,L"%S player status %d","MgrProcessFromMgrSys",DAT_0016d11c);
    if (DAT_0016d11c == 1) {
      FUN_000136c0();
    }
    DbgDebugPrint(6,0,L"%S IDM_PREPARE_SHUTDOWN_CONFIRM","MgrProcessFromMgrSys");
    IpcPostMsg(6,1,0xb,0,0);
  }
  else if (param_2 == 0x67) {
    uVar2 = 1;
    DAT_0016de1c = 1;
    DAT_0016de50 = 0;
    if (*param_4 == 1) {
      NKDbgPrintfW(L">> ** [MUTE_ON] IDM_MSYS_MIPOD_AUDIO_STREAMING_STOP\r\n");
      DAT_0016de3c = 1;
    }
    if ((DAT_0016d11c == 0) && (DAT_0016d0dc == 1)) {
      DAT_0016de18 = 1;
    }
    else {
      bVar1 = FUN_000120f8();
      if (CONCAT31(extraout_var,bVar1) == 0) {
        NKDbgPrintfW(
                    L"~[ERROR]~ IDM_MSYS_MIPOD_AUDIO_STREAMING_STOP app_get_play_status error~~~ ==> one more retry\r\n"
                    );
        Sleep(0x96);
        FUN_00011fcc();
      }
      if (DAT_0016d11c == 1) {
        FUN_0001364c(0);
      }
      else if (DAT_0016de34 == 1) {
        DAT_0016de30 = 0;
        DAT_0016de34 = 0;
      }
      DAT_0016de18 = 1;
    }
  }
  else if (param_2 == 0x68) {
    DAT_0016de1c = 0;
    DAT_0016de50 = 0;
    uVar2 = 1;
    if ((*param_4 == 1) && (DAT_0016de3c == 1)) {
      NKDbgPrintfW(L">> ** [MUTE_OFF] IDM_MSYS_MIPOD_AUDIO_STREAMING_START\r\n");
      DAT_0016de3c = 0;
    }
    if ((DAT_0016d11c == 0) && (DAT_0016d0dc == 1)) {
      DAT_0016de18 = 0;
    }
    else if (DAT_0016de38 == 1) {
      FUN_00011fcc();
      NKDbgPrintfW(L"~!@# IDM_MSYS_MIPOD_AUDIO_STREAMING_START PAUSE STATE => NOT ALLOWED STREAMING START [%d], g_stPlayInfo.ucPlayerStatus %d, g_bDAStreamBlocked %d, g_bStatusSeek %d\r\n"
                   ,DAT_0016de18,DAT_0016d11c,DAT_0016de14,DAT_0016de34);
      DAT_0016de18 = 0;
    }
    else {
      NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3af);
      if (DAT_0016de18 == 1) {
        DAT_0016de18 = 0;
        if (DAT_0016de14 == 1) {
          DAT_0016de20 = 1;
          NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3b8);
        }
        else {
          DAT_0016de20 = 0;
        }
        if (DAT_0016de24 == 1) {
          DAT_0016de24 = 0;
          DAT_0016d11c = 1;
          FUN_000135fc();
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
          NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3c5);
        }
        else if ((DAT_0016de14 == 0) && (DAT_0016de34 == 0)) {
          if ((DAT_0016d11c == 0) || (DAT_0016de2c != 0)) {
            NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3d2);
            FUN_000138f8();
            if (DAT_0016de2c != 0) {
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3d8);
              FUN_000120f8();
              if ((DAT_0016ddb0 == 0) || (DAT_0016ddb4 == 0)) {
                if (DAT_0016d11c != 1) {
                  FUN_0001364c(1);
                }
                NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3de);
              }
              FUN_00011fcc();
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3e1);
              DAT_0016de2c = 0;
            }
          }
          else {
            NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3ea);
            FUN_000120f8();
            if (DAT_0016d11c == 1) {
              if (DAT_0016ddb0 == 0) {
                NKDbgPrintfW(L">> %S, %d \n\r","MgrProcessFromMgrSys",0x3f6);
                FUN_000135fc();
                MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
                IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
              }
            }
            else {
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3ee);
              FUN_0001364c(1);
              FUN_00011fcc();
            }
          }
        }
      }
      else if (DAT_0016de2c == 1) {
        NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x404);
        DAT_0016de2c = 0;
        FUN_00013dc8();
        FUN_000138f8();
      }
      NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x40b);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 0001995c FUN_0001995c */

/* Boundary evidence: original MIPS .pdata 0001995c..0001a72f. Semantic name remains unreviewed. */

undefined4 FUN_0001995c(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_40 [2];
  uint auStack_38 [4];
  
  uVar7 = 1;
  switch(param_2) {
  case 1000:
    if (DAT_0016ddc8 == 2) {
      uVar7 = 0;
    }
    else {
      memset(local_40,0,4);
      local_40[0] = local_40[0] & 0xffe03ff4 | 0x2004;
      DbgDebugPrint(6,3,L"%S init_ipod_connection","MgrProcessFromMgrIpod");
      FUN_00012a48();
      if ((DAT_0016d0d8 == 0) || (DAT_0016ddc8 == 2)) {
        local_40[0] = local_40[0] & 0xffffff0f;
        DbgDebugPrint(6,3,L"%S init_ipod_connection ===> FAIL!!!","MgrProcessFromMgrIpod");
        IpcPostMsg(6,1,9,4,local_40);
      }
      else {
        DAT_0016de2c = 0;
        FUN_000138f8();
        if (DAT_0016d0d8 == 0) {
          local_40[0] = local_40[0] & 0xffffff0f;
          DbgDebugPrint(6,3,L"%S app_request_track_info ===> FAIL!!!","MgrProcessFromMgrIpod");
          IpcPostMsg(6,1,9,4,local_40);
        }
        else {
          FUN_0001379c();
          if (DAT_0016d0d8 == 0) {
            local_40[0] = local_40[0] & 0xffffff0f;
            DbgDebugPrint(6,3,L"%S app_get_num_all_categorized_db_records ===> FAIL!!!",
                          "MgrProcessFromMgrIpod");
            IpcPostMsg(6,1,9,4,local_40);
          }
          else {
            if (DAT_0016de10 == 0) {
              local_40[0] = local_40[0] & 0xffffff1f | 0x10;
            }
            else {
              DAT_0016de10 = 0;
              local_40[0] = local_40[0] & 0xffffff3f | 0x30;
            }
            if (DAT_0016d0d4 == 1) {
              uVar5 = (uint)(0 < DAT_0016d144) << 0x15;
              uVar6 = uVar5 | local_40[0] & 0xff5fe1ff | 0x100;
              if (DAT_0016de0c != 0) {
                if (0 < DAT_0016d144 == 0) {
                  uVar6 = uVar6 | 0x30;
                }
                else {
                  uVar6 = uVar5 | local_40[0] & 0xff5fe11f | 0x100 | 0x10;
                }
              }
              local_40[0] = uVar6 & 0xffbfffff;
              iVar3 = FUN_000145c8();
              local_40[0] = (iVar3 << 0x18 ^ local_40[0]) & 0x1000000 ^ local_40[0];
              iVar3 = FUN_000145e8();
              local_40[0] = (iVar3 << 0x19 ^ local_40[0]) & 0x2000000 ^ local_40[0];
              if (DAT_0016d0d8 == 0) {
                return 1;
              }
              FUN_000144a0();
              FUN_000115b8();
              DAT_0016de2c = 1;
              DAT_0016de0c = 0;
            }
            if (DAT_0016d0d8 == 0) {
              local_40[0] = local_40[0] & 0xffffff0f;
              DbgDebugPrint(6,3,L"%S app_get_num_playing_tracks ===> FAIL!!!",
                            "MgrProcessFromMgrIpod");
              IpcPostMsg(6,1,9,4,local_40);
            }
            else {
              IpcPostMsg(6,1,9,4,local_40);
            }
          }
        }
      }
    }
    break;
  case 0x3e9:
    if (DAT_0016d11c == 0) {
      FUN_0001140c(0xffffffff);
LAB_00019da8:
      FUN_00012310(0xf0);
    }
    else {
      if ((DAT_0016d11c == 0) || (2 < DAT_0016d11c)) goto LAB_00019da8;
      NKDbgPrintfW(L">> [IDM_MIPOD_MIPOD_INDEXING] - PLAYER_PLAYING app_ipod_resume\r\n");
      FUN_00013dc8();
    }
    FUN_000138f8();
    FUN_0001379c();
    break;
  case 0x3ea:
    DAT_0016de50 = 0;
    NKDbgPrintfW(L"~!@# IDM_MIPOD_MIPOD_SETTRACK g_ulNextTrack %d ->%d [%d, %d], g_bTrackJumpStart %d\r\n"
                 ,DAT_0016d128,DAT_0016de58,DAT_0016de34,DAT_0016de18,DAT_0016de48);
    DAT_0016de28 = 0;
    FUN_000120f8();
    if (((DAT_0016de30 != 0) && (DAT_0002e5c0 != '\a')) && (FUN_0001344c(), 1000 < DAT_0016de40)) {
      NKDbgPrintfW(L">> Dont change pos! [ %d ]\r\n");
      FUN_000134b8(0);
      DAT_0016de40 = 0;
    }
    if (DAT_0016de48 == 1) {
      if (((DAT_0016de34 != 0) && (DAT_0016d11c != 1)) &&
         ((DAT_0016de18 == 0 && (DAT_0016de38 == 0)))) {
        FUN_0001364c(1);
      }
    }
    else {
      uVar1 = FUN_000132ac();
      if (((char)uVar1 == '\x01') || ((char)uVar1 == '\0')) {
        FUN_000114ac(DAT_0016de58);
      }
      else {
        FUN_0001140c(DAT_0016de58);
      }
    }
    if (DAT_0016de38 == 1) {
      NKDbgPrintfW(L"~!@# IDM_MIPOD_MIPOD_SETTRACK PAUSE STATE => NOT ALLOWED STREAMING START [%d]\r\n"
                   ,DAT_0016de18);
LAB_00019f7c:
      FUN_0001364c(0);
LAB_00019f84:
      if (DAT_0016de18 == 0) goto LAB_00019f98;
    }
    else {
      if (DAT_0016de18 != 0) {
        FUN_0001364c(0);
        FUN_000120f8();
        if (DAT_0016d11c == 1) goto LAB_00019f7c;
        goto LAB_00019f84;
      }
      if ((DAT_0016de34 == 0) && (DAT_0016d11c != 1)) goto LAB_00019f7c;
LAB_00019f98:
      if (((DAT_0016de30 != 0) && (DAT_0002e5c0 != '\a')) && (FUN_0001344c(), 1000 < DAT_0016de40))
      {
        NKDbgPrintfW(L">> [error] change the track pos [ %d ]\r\n");
        FUN_000134b8(0);
        DAT_0016de40 = 0;
      }
      FUN_00011fcc();
      if (DAT_0016d11c == 1) {
        FUN_00012310(0xf0);
      }
    }
    FUN_00011534();
    if (DAT_0002e168 == DAT_0016d128) {
      FUN_00011b40(DAT_0016d128);
      FUN_00011bc8(DAT_0016d128);
    }
    DAT_0016de30 = 0;
    DAT_0016de34 = 0;
    if (DAT_0016de48 == 1) {
      IpcPostMsg(6,6,0x3f0,0,0);
      DAT_0016de48 = 0;
    }
    NKDbgPrintfW(L"~!@# END - IDM_MIPOD_MIPOD_SETTRACK g_ulNextTrack %d\r\n",DAT_0016de58);
    break;
  case 0x3eb:
    goto switchD_000199c4_caseD_3eb;
  case 0x3ec:
    if ((DAT_0002e224 != 0xffffffff) && (DAT_0002e228 != -1)) {
      FUN_000139f8(DAT_0002e224,DAT_0002e228);
      if (DAT_0002e224 == 5) {
        FUN_00011534();
        FUN_00011bc8(DAT_0016d128);
        FUN_00011b40(DAT_0016d128);
      }
      DAT_0016de58 = DAT_0002e228;
    }
    IpcPostMsg(6,0x15,0x77,0,0);
    NKDbgPrintfW(L"~!@# END - IDM_MIPOD_MIPOD_SETCAT gIcatIdx[%d], g_selectIdx[%d]\r\n",DAT_0002e224
                 ,DAT_0002e228);
    break;
  case 0x3ed:
    FUN_000127ec();
    break;
  case 0x3ee:
    if (DAT_0016de50 != 0) {
      DAT_0016de50 = 0;
      return 1;
    }
    if (DAT_0002e161 == '\v') {
      if (DAT_0016de1c == 1) {
        NKDbgPrintfW(L">>IDM_MIPOD_MIPOD_PLAY_PAUSE g_bRecvStreamStop is TRUE break\r\n");
        FUN_000120f8();
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
        return 1;
      }
      if (DAT_0016de38 == 0) {
        if (DAT_0016de30 == 1) {
          return 1;
        }
        FUN_00011fcc();
        if ((DAT_0016de18 != 1) && (FUN_0001235c(0xf0), DAT_0016d11c != 2)) {
          DAT_0016d11c = 2;
        }
        DAT_0016de38 = 1;
        NKDbgPrintfW(L">> Pause from [ iPOD ]! g_bStreamStop %d \n",DAT_0016de18);
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
        return 1;
      }
      pwVar4 = L">> Pause from [ HU ]! \n";
    }
    else {
      if (DAT_0002e161 != '\n') {
        return 1;
      }
      if (DAT_0016de1c == 1) {
        DAT_0016de38 = 0;
        if (DAT_0016de3c == 1) {
          DAT_0016de3c = 0;
          FUN_000120f8();
          if (DAT_0016d11c != 1) {
            return 1;
          }
          local_40[0] = 0;
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x78,4,local_40);
          pwVar4 = L">> iPod mute is end \r\n \n";
LAB_0001a50c:
          NKDbgPrintfW(pwVar4);
          FUN_00012310(0xf0);
          return 1;
        }
        FUN_0001235c(0xf0);
        pwVar4 = L">> don\'t ipod streaming start!!!!!\n";
      }
      else if (DAT_0016de38 == 1) {
        DAT_0016de4c = 0;
        if (DAT_0016de30 == 1) {
          DAT_0016de4c = 0;
          return 1;
        }
        if (DAT_0016de18 == 1) {
          DAT_0016de38 = 0;
          if (DAT_0016d11c != 0) {
            DAT_0016d11c = 1;
          }
          MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
          return 1;
        }
        if (DAT_0016d11c == 0) {
          uVar5 = 7;
          if (DAT_0002e5c0 != '\a') {
            uVar5 = 5;
          }
          FUN_000139f8(uVar5,0);
        }
        else {
          if (DAT_0016de40 == 0) {
            FUN_000134b8(0);
          }
          FUN_00012310(0xf0);
          if (DAT_0016d11c != 1) {
            DAT_0016d11c = 1;
          }
        }
        MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016d11c);
        pwVar4 = L">> Play from [ IPOD ]!! \n";
        DAT_0016de38 = 0;
      }
      else {
        if (DAT_0016ddb0 == 0) {
          pwVar4 = L">> Play from [ HU ]!!22222 \n";
          goto LAB_0001a50c;
        }
        pwVar4 = L">> Play from [ HU ]!! \n";
      }
    }
    NKDbgPrintfW(pwVar4);
    break;
  case 0x3ef:
    FUN_000134b8(0);
switchD_000199c4_caseD_3eb:
    DAT_0016de50 = 1;
    if ((DAT_0016d0e0 == 0) && (DAT_0016d0e4 == 0)) {
      DAT_0016de50 = 1;
      return 1;
    }
    if (DAT_0016d11c != 1) {
      DAT_0016de4c = 1;
    }
    IpcPostMsg(6,0x15,0x76,0,0);
    FUN_00011e98();
    FUN_000120f8();
    if (DAT_0016de14 != 1) {
      if (DAT_0016de38 != 1) {
        return 1;
      }
      NKDbgPrintfW(L"~!@# 111 IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE STATE => NOT ALLOWED STREAMING START [%d]-[%d]\r\n"
                   ,DAT_0016de18,DAT_0016d11c);
      if (DAT_0016d11c == 1) {
        FUN_0001364c(0);
        FUN_00011fcc();
      }
      if (DAT_0016de18 != 0) {
        return 1;
      }
      DAT_0016de40 = 0;
      puVar2 = FUN_0001168c(auStack_38,0);
      DAT_0016d10c = *puVar2;
      DAT_0016d110 = puVar2[1];
      DAT_0016d114 = puVar2[2];
      DAT_0016d118 = puVar2[3];
      MSHM_Dll_Write(DAT_0016d0cc,&DAT_0016d0fc,0,0xc5c);
      IpcPostMsg(6,0x15,0x72,0,0);
      return 1;
    }
    DAT_0016de14 = 0;
    if (DAT_0016de18 == 0) {
      if (DAT_0016d11c == 2) {
        iVar3 = 1;
        goto LAB_0001a1f4;
      }
      FUN_00012310(0xf0);
    }
    else {
      if (DAT_0016d11c != 1) {
        DAT_0016de14 = 0;
        return 1;
      }
      NKDbgPrintfW(L"~~~~~!!!! IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE\r\n");
      iVar3 = 0;
LAB_0001a1f4:
      FUN_0001364c(iVar3);
    }
    FUN_00011fcc();
    break;
  case 0x3f0:
    KillTimer(DAT_0016de00,0x3ed);
    SetTimer(DAT_0016de00,0x3ed,500,(TIMERPROC)0x0);
  }
  return uVar7;
}



/* 0001a730 FUN_0001a730 */

/* Boundary evidence: original MIPS .pdata 0001a730..0001a763. Semantic name remains unreviewed. */

void FUN_0001a730(void *param_1)

{
  FUN_0002097c(&DAT_0016de60,param_1,0x28);
  return;
}



/* 0001a764 FUN_0001a764 */

/* Boundary evidence: original MIPS .pdata 0001a764..0001a92b. Semantic name remains unreviewed. */

void FUN_0001a764(void)

{
  undefined4 *local_68;
  undefined4 auStack_60 [18];
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  uint local_c;
  
  local_c = DAT_0002e28c;
  if (DAT_0016de5c != (int *)0x0) {
    local_14 = (undefined4 *)DAT_0016de5c[8];
    while (local_14 != (undefined4 *)0x0) {
      local_10 = (undefined4 *)local_14[3];
      (**(code **)(local_14[1] + 0xc))(local_14[2]);
      FUN_00021a94(local_14);
      local_14 = local_10;
    }
    if (*DAT_0016de5c != 0) {
      FUN_0001a92c(auStack_60,0x6d,0,0);
      FUN_0001c980(0,auStack_60,0);
      FUN_000216c0((undefined4 *)*DAT_0016de5c);
    }
    if (DAT_0016de5c[2] != 0) {
      FUN_00020df0((HANDLE)DAT_0016de5c[2]);
    }
    local_68 = (undefined4 *)DAT_0016de5c[6];
    while (local_68 != (undefined4 *)0x0) {
      local_18 = (undefined4 *)local_68[5];
      FUN_00021a94((undefined4 *)*local_68);
      FUN_00021a94(local_68);
      local_68 = local_18;
    }
    if (DAT_0016de5c[3] != 0) {
      FUN_00021a94((undefined4 *)DAT_0016de5c[3]);
    }
    FUN_00021a94(DAT_0016de5c);
    DAT_0016de5c = (int *)0x0;
  }
  FUN_000279ec(local_c);
  return;
}



/* 0001a92c FUN_0001a92c */

/* Boundary evidence: original MIPS .pdata 0001a92c..0001a9ef. Semantic name remains unreviewed. */

undefined4 FUN_0001a92c(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  
  *param_1 = param_2;
  param_1[5] = 0;
  if ((param_3 != 0) || (param_4 != 0)) {
    FUN_00023a34();
    piVar1 = FUN_00021974(8,0);
    FUN_00023a5c();
    if (piVar1 == (int *)0x0) {
      return 7;
    }
    *piVar1 = param_3;
    piVar1[1] = param_4;
    param_1[5] = piVar1;
  }
  return 0;
}



/* 0001a9f0 FUN_0001a9f0 */

/* Boundary evidence: original MIPS .pdata 0001a9f0..0001ab67. Semantic name remains unreviewed. */

int FUN_0001a9f0(void)

{
  int *piVar1;
  int local_60;
  undefined4 auStack_58 [18];
  uint local_10;
  int local_c;
  
  local_10 = DAT_0002e28c;
  piVar1 = FUN_00021974(0x28,1);
  if (piVar1 == (int *)0x0) {
    FUN_000279ec(local_10);
    local_c = 7;
  }
  else {
    DAT_0016de5c = piVar1;
    piVar1[6] = 0;
    piVar1[7] = (int)(piVar1 + 6);
    piVar1[8] = 0;
    piVar1[9] = (int)(piVar1 + 8);
    local_60 = FUN_00020d74(piVar1 + 2);
    if ((local_60 == 0) &&
       (local_60 = FUN_00021280((int)piVar1,0x1000,0x1ab68,piVar1), local_60 == 0)) {
      FUN_0001a92c(auStack_58,0x6c,0,0);
      local_60 = FUN_0001c980(0,auStack_58,0);
      if (local_60 == 0) {
        FUN_000279ec(local_10);
        return 0;
      }
    }
    FUN_0001a764();
    FUN_000279ec(local_10);
    local_c = local_60;
  }
  return local_c;
}



/* 0001ab68 FUN_0001ab68 */

/* Boundary evidence: original MIPS .pdata 0001ab68..0001c53b. Semantic name remains unreviewed. */

void FUN_0001ab68(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 in_stack_fffffe08;
  undefined2 uVar3;
  uint local_1ec;
  code *local_1e8;
  undefined4 *local_1e0;
  undefined4 local_1d8;
  undefined4 auStack_120 [3];
  undefined4 *local_114;
  undefined4 *local_110;
  undefined4 *local_10c;
  undefined4 *local_108;
  undefined4 *local_104;
  undefined4 *local_100;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar3 = (undefined2)((uint)in_stack_fffffe08 >> 0x10);
  local_1e0 = (undefined4 *)(param_2 + 4);
  puVar2 = *(undefined4 **)(param_2 + 8);
  local_1d8 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    local_1e8 = (code *)0x0;
  }
  else {
    local_1d8 = puVar2[1];
    local_1e8 = (code *)*puVar2;
  }
  local_1ec = (uint)(puVar2 != (undefined4 *)0x0);
  if (*(uint *)(param_2 + 0x1c) < *(uint *)(param_2 + 0x18)) {
    if (DAT_0016de5c[3] == 0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        return;
      }
      piVar1 = FUN_00021974(*(int *)(param_2 + 0x18) + 0x20,0);
      DAT_0016de5c[3] = piVar1;
      if (DAT_0016de5c[3] == 0) {
        return;
      }
      FUN_0002097c((void *)DAT_0016de5c[3],local_1e0,*(int *)(param_2 + 0x1c) + 0x20);
      DAT_0016de5c[4] = DAT_0016de5c[3] + 0x20 + *(int *)(DAT_0016de5c[3] + 0x18);
      DAT_0016de5c[5] = *(undefined4 *)(DAT_0016de5c[3] + 0x18);
      return;
    }
    if (*(int *)(param_2 + 0x14) == *(int *)(DAT_0016de5c[3] + 0x10)) {
      if (*(int *)(param_2 + 0x20) == *(int *)(DAT_0016de5c[3] + 0x1c) + 1) {
        if (*(int *)(param_2 + 0x18) == *(int *)(DAT_0016de5c[3] + 0x14)) {
          DAT_0016de5c[5] = DAT_0016de5c[5] + *(int *)(param_2 + 0x1c);
          if (*(uint *)(param_2 + 0x18) < (uint)DAT_0016de5c[5]) {
            local_1e0 = (undefined4 *)DAT_0016de5c[3];
            local_1e0[3] = 10;
          }
          else {
            *(int *)(DAT_0016de5c[3] + 0x1c) = *(int *)(DAT_0016de5c[3] + 0x1c) + 1;
            FUN_0002097c((void *)DAT_0016de5c[4],(void *)(param_2 + 0x24),
                         *(size_t *)(param_2 + 0x1c));
            DAT_0016de5c[4] = DAT_0016de5c[4] + *(int *)(param_2 + 0x1c);
            if (DAT_0016de5c[5] != *(int *)(DAT_0016de5c[3] + 0x14)) {
              return;
            }
            local_1e0 = (undefined4 *)DAT_0016de5c[3];
          }
        }
        else {
          local_1e0 = (undefined4 *)DAT_0016de5c[3];
          local_1e0[3] = 10;
        }
      }
      else {
        local_1e0 = (undefined4 *)DAT_0016de5c[3];
        local_1e0[3] = 10;
      }
    }
    else {
      local_1e0 = (undefined4 *)DAT_0016de5c[3];
      local_1e0[3] = 10;
    }
  }
  FUN_00023a5c();
  local_2c = *local_1e0;
  switch(local_2c) {
  case 0:
    if (DAT_0016de60 != (code *)0x0) {
      (*DAT_0016de60)(0,local_1e0[3]);
    }
    break;
  case 1:
    if (DAT_0016de64 != (code *)0x0) {
      (*DAT_0016de64)(0,local_1e0[8],local_1e0[3]);
    }
    break;
  case 2:
    if (DAT_0016de68 != (code *)0x0) {
      (*DAT_0016de68)(0,local_1e0[3]);
    }
    break;
  case 3:
    if (DAT_0016de6c != (code *)0x0) {
      (*DAT_0016de6c)(0,*(undefined1 *)(local_1e0 + 2),local_1e0[3]);
    }
    break;
  case 4:
    if (DAT_0016de78 != (code *)0x0) {
      (*DAT_0016de78)(0,local_1e0[3]);
    }
    break;
  case 6:
    if (DAT_0016de74 != (code *)0x0) {
      (*DAT_0016de74)(0,local_1e0[8],local_1e0[9],local_1e0[10]);
    }
    break;
  case 0xd:
    (*local_1e8)(local_1d8,local_1e0[3]);
    break;
  case 0xf:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x10:
  case 0x11:
  case 0x17:
  case 0x1c:
  case 0x20:
  case 0x24:
  case 0x26:
  case 0x27:
  case 0x2a:
  case 0x6e:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3]);
    break;
  case 0x12:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 9,local_1e0[8]);
    break;
  case 0x13:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),*(undefined1 *)((int)local_1e0 + 0x21),
                 *(undefined1 *)((int)local_1e0 + 0x22));
    break;
  case 0x14:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),*(undefined1 *)((int)local_1e0 + 0x21),
                 *(undefined1 *)((int)local_1e0 + 0x22));
    break;
  case 0x15:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 9,local_1e0[8]);
    break;
  case 0x16:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0 + 10,
                 local_1e0[9]);
    break;
  case 0x18:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8] & 0xff,
                 local_1e0[9] & 0xff);
    break;
  case 0x19:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x1a:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x1b:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),(int)local_1e0 + 0x21);
    break;
  case 0x1d:
    FUN_000204f8((int)DAT_0016de5c,(char *)((int)local_1e0 + 0x21),*(byte *)(local_1e0 + 8));
    break;
  case 0x1e:
    FUN_0002036c(DAT_0016de5c,*(undefined2 *)(local_1e0 + 8),*(byte *)((int)local_1e0 + 0x22));
    break;
  case 0x1f:
    FUN_00020690((int)DAT_0016de5c,*(short *)(local_1e0 + 8),local_1e0 + 9,
                 *(undefined2 *)((int)local_1e0 + 0x22));
    break;
  case 0x21:
    FUN_00020580((int)DAT_0016de5c,*(short *)(local_1e0 + 8));
    break;
  case 0x25:
    if (DAT_0016de84 != (code *)0x0) {
      (*DAT_0016de84)(0,local_1e0[8],*(undefined2 *)(local_1e0 + 9));
    }
    break;
  case 0x28:
  case 0x29:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9]);
    break;
  case 0x2b:
    if (DAT_0016de80 != (code *)0x0) {
      if ((*(char *)(local_1e0 + 8) == '\n') || (*(char *)(local_1e0 + 8) == '\x13')) {
        local_1e0[9] = local_1e0 + 0xd;
      }
      (*DAT_0016de80)(0,local_1e0 + 8);
    }
    break;
  case 0x2c:
    if (DAT_0016de70 != (code *)0x0) {
      (*DAT_0016de70)(0,*(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x33:
  case 0x35:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3f:
  case 0x40:
  case 0x44:
  case 0x48:
  case 0x4e:
  case 0x4f:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3]);
    break;
  case 0x2f:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9],
                 *(undefined1 *)(local_1e0 + 10));
    break;
  case 0x31:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x32:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x34:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8));
    break;
  case 0x36:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8));
    break;
  case 0x37:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x38:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x39:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x3d:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x3e:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0 + 0xb,
                 *(undefined2 *)(local_1e0 + 9),local_1e0[10]);
    local_28 = (uint)(local_1e0[10] == 0);
    local_1ec = local_28;
    break;
  case 0x41:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined2 *)(local_1e0 + 8),(int)local_1e0 + 0x22);
    break;
  case 0x42:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined2 *)(local_1e0 + 8),local_1e0 + 9,local_1e0 + 0x10,
                 CONCAT22(uVar3,*(undefined2 *)(local_1e0 + 0xe)),local_1e0[0xf]);
    local_24 = (uint)(local_1e0[0xf] == 0);
    local_1ec = local_24;
    break;
  case 0x43:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 9,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x45:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9]);
    break;
  case 0x46:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9]);
    break;
  case 0x47:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x49:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8));
    break;
  case 0x4a:
    FUN_0001c6b8(local_1e0 + 9,(uint)*(byte *)(local_1e0 + 8),local_1e0 + 0xd);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],*(byte *)(local_1e0 + 8),
                 local_1e0 + 9,local_1e0[0xc]);
    local_20 = (uint)(local_1e0[0xc] == 0);
    local_1ec = local_20;
    break;
  case 0x4b:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x4c:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined2 *)(local_1e0 + 8),*(undefined2 *)((int)local_1e0 + 0x22),
                 *(undefined1 *)(local_1e0 + 9));
    break;
  case 0x4d:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x50:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
    break;
  case 0x51:
    FUN_0001c53c(local_1e0 + 0xb,local_1e0[10],local_1e0 + 0xf);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 8,local_1e0[10],
                 local_1e0 + 0xb,local_1e0[0xe]);
    local_1c = (uint)(local_1e0[0xe] == 0);
    local_1ec = local_1c;
    break;
  case 0x52:
    FUN_0001c53c(local_1e0 + 10,local_1e0[9],local_1e0 + 0xe);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9],
                 local_1e0 + 10,local_1e0[0xd]);
    local_18 = (uint)(local_1e0[0xd] == 0);
    local_1ec = local_18;
    break;
  case 0x53:
    FUN_0001c53c(local_1e0 + 10,local_1e0[9],local_1e0 + 0xe);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9],
                 local_1e0 + 10,local_1e0[0xd]);
    local_14 = (uint)(local_1e0[0xd] == 0);
    local_1ec = local_14;
    break;
  case 0x54:
    if (DAT_0016de7c != (code *)0x0) {
      (*DAT_0016de7c)(0,*(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
    }
    break;
  case 0x55:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x56:
  case 0x59:
  case 0x5b:
  case 0x5e:
  case 100:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3]);
    break;
  case 0x57:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x58:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],(int)local_1e0 + 0x22,
                 *(undefined2 *)(local_1e0 + 8));
    break;
  case 0x5a:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8]);
    break;
  case 0x5c:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
    break;
  case 0x5d:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),local_1e0[9],local_1e0[10],local_1e0[0xb]);
    break;
  case 0x5f:
    FUN_0001c798(*(undefined1 *)(local_1e0 + 8),auStack_120,local_1e0 + 9);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8),auStack_120);
    break;
  case 0x60:
    local_114 = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],*local_114);
    break;
  case 0x61:
    local_110 = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 9,*local_110);
    break;
  case 0x62:
    local_10c = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],*(undefined2 *)local_10c,
                 local_1e0 + 9,local_1e0 + 0x10,CONCAT22(uVar3,*(undefined2 *)(local_1e0 + 0xe)),
                 local_1e0[0xf]);
    local_10 = (uint)(local_10c[7] == 0);
    local_1ec = local_10;
    break;
  case 99:
    local_108 = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],*(undefined1 *)local_108,
                 *(undefined1 *)((int)local_1e0 + 0x21));
    break;
  case 0x65:
    local_100 = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 9,*local_100);
    break;
  case 0x66:
    local_104 = local_1e0 + 8;
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],*(undefined1 *)local_104);
    break;
  case 0x67:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 8);
    break;
  case 0x68:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9]);
    break;
  case 0x69:
  case 0x6a:
  case 0x6b:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],
                 *(undefined1 *)(local_1e0 + 8));
  }
  FUN_00023a34();
  if (local_1ec != 0) {
    FUN_00021a94(puVar2);
  }
  if (DAT_0016de5c[3] != 0) {
    FUN_00021a94((undefined4 *)DAT_0016de5c[3]);
    DAT_0016de5c[3] = 0;
  }
  return;
}



/* 0001c53c FUN_0001c53c */

/* Boundary evidence: original MIPS .pdata 0001c53c..0001c6b7. Semantic name remains unreviewed. */

void FUN_0001c53c(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < 0x21) {
    if (param_2 == 0x20) {
      *param_1 = param_3;
    }
    else {
      switch(param_2) {
      case 2:
        *param_1 = param_3;
        break;
      case 4:
        *param_1 = param_3;
        break;
      case 8:
        *param_1 = param_3;
        break;
      case 0x10:
        *param_1 = param_3;
      }
    }
  }
  else if (param_2 == 0x800) {
    param_1[1] = param_3;
  }
  else if (param_2 == 0x1000) {
    *param_1 = param_3;
  }
  else if (param_2 == 0x200000) {
    *param_1 = param_3;
  }
  return;
}



/* 0001c6b8 FUN_0001c6b8 */

/* Boundary evidence: original MIPS .pdata 0001c6b8..0001c797. Semantic name remains unreviewed. */

void FUN_0001c6b8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_2) {
  case 1:
    *param_1 = param_3;
    break;
  case 3:
    param_1[1] = param_3;
    break;
  case 4:
    param_1[1] = param_3;
    break;
  case 5:
    *param_1 = param_3;
    break;
  case 6:
    *param_1 = param_3;
    break;
  case 7:
    *param_1 = param_3;
  }
  return;
}



/* 0001c798 FUN_0001c798 */

/* Boundary evidence: original MIPS .pdata 0001c798..0001c97f. Semantic name remains unreviewed. */

void FUN_0001c798(undefined1 param_1,undefined4 *param_2,undefined4 *param_3)

{
  switch(param_1) {
  case 0:
    FUN_0002097c(param_2,param_3,0xc);
    break;
  case 1:
    *param_2 = *param_3;
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(param_3 + 1);
    param_2[1] = (int)param_3 + 6;
    break;
  case 2:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
    break;
  case 3:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
    break;
  case 4:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
    break;
  case 5:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
    break;
  case 6:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
    break;
  case 7:
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)param_3 + 2);
    *(undefined1 *)param_2 = *(undefined1 *)param_3;
    param_2[1] = param_3 + 1;
    break;
  case 8:
    *(undefined2 *)(param_2 + 1) = *(undefined2 *)param_3;
    *param_2 = (int)param_3 + 2;
  }
  return;
}



/* 0001c980 FUN_0001c980 */

/* Boundary evidence: original MIPS .pdata 0001c980..0001c9cf. Semantic name remains unreviewed. */

int FUN_0001c980(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0001c9d0(param_1,param_2,param_3,(void *)0x0,0);
  return iVar1;
}



/* 0001c9d0 FUN_0001c9d0 */

/* Boundary evidence: original MIPS .pdata 0001c9d0..0001cc23. Semantic name remains unreviewed. */

int FUN_0001c9d0(undefined4 param_1,undefined4 *param_2,int param_3,void *param_4,size_t param_5)

{
  int local_2040;
  undefined4 *local_203c;
  uint local_2038;
  undefined1 auStack_2030 [4];
  uint local_202c;
  undefined4 local_2028;
  int local_2024;
  size_t local_2020;
  int local_201c;
  int local_2018;
  undefined4 local_2014;
  undefined1 auStack_2010 [4072];
  undefined4 local_1028;
  int local_1024;
  undefined1 auStack_101c [4096];
  size_t local_1c;
  uint local_18;
  uint local_10;
  
  local_18 = DAT_0002e28c;
  local_2040 = 0;
  local_2038 = param_3 + 0x48;
  local_203c = param_2 + 6;
  FUN_00020e34((HANDLE)DAT_0016de5c[2]);
  FUN_000209c0(auStack_2030,0,0x2014);
  local_1028 = 0x81002048;
  local_2028 = *param_2;
  local_2014 = param_2[5];
  local_2024 = param_3 + 0x30;
  local_201c = DAT_0016de5c[1];
  DAT_0016de5c[1] = DAT_0016de5c[1] + 1;
  local_2018 = 0;
  while (0x18 < local_2038) {
    local_1024 = 0x1000;
    if (local_2038 < 0x1001) {
      local_10 = local_2038;
    }
    else {
      local_10 = 0x1000;
    }
    local_202c = local_10;
    local_1c = local_10 - 0x18;
    FUN_0002097c(auStack_2010,local_203c,local_1c);
    local_203c = (undefined4 *)((int)local_203c + local_1c);
    local_2020 = local_1c;
    local_2038 = local_2038 - local_1c;
    local_2040 = FUN_000217d4(*DAT_0016de5c,(int)auStack_2030);
    if (local_2040 != 0) break;
    if (param_4 != (void *)0x0) {
      if (param_5 == local_1024 - 4U) {
        FUN_0002097c(param_4,auStack_101c,param_5);
      }
      else {
        local_2040 = 10;
      }
    }
    local_2018 = local_2018 + 1;
  }
  FUN_00020e84((HANDLE)DAT_0016de5c[2]);
  FUN_000279ec(local_18);
  return local_2040;
}



/* 0001cc24 FUN_0001cc24 */

/* Boundary evidence: original MIPS .pdata 0001cc24..0001cc9b. Semantic name remains unreviewed. */

int FUN_0001cc24(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,5,0,0);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001cc9c FUN_0001cc9c */

/* Boundary evidence: original MIPS .pdata 0001cc9c..0001cd13. Semantic name remains unreviewed. */

int FUN_0001cc9c(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,7,0,0);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001cd14 FUN_0001cd14 */

/* Boundary evidence: original MIPS .pdata 0001cd14..0001cd97. Semantic name remains unreviewed. */

int FUN_0001cd14(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,9,0,0);
  local_40 = param_2;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001cd98 FUN_0001cd98 */

/* Boundary evidence: original MIPS .pdata 0001cd98..0001ce1b. Semantic name remains unreviewed. */

int FUN_0001cd98(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,8,0,0);
  local_40 = param_2;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ce1c FUN_0001ce1c */

/* Boundary evidence: original MIPS .pdata 0001ce1c..0001ce93. Semantic name remains unreviewed. */

int FUN_0001ce1c(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,10,0,0);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ce94 FUN_0001ce94 */

/* Boundary evidence: original MIPS .pdata 0001ce94..0001cf0b. Semantic name remains unreviewed. */

int FUN_0001ce94(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0xb,0,0);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001cf0c FUN_0001cf0c */

/* Boundary evidence: original MIPS .pdata 0001cf0c..0001cf83. Semantic name remains unreviewed. */

int FUN_0001cf0c(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0xc,0,0);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001cf84 FUN_0001cf84 */

/* Boundary evidence: original MIPS .pdata 0001cf84..0001d00f. Semantic name remains unreviewed. */

int FUN_0001cf84(undefined4 param_1,undefined2 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0xd,param_3,param_4);
  local_40 = param_2;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d010 FUN_0001d010 */

/* Boundary evidence: original MIPS .pdata 0001d010..0001d09b. Semantic name remains unreviewed. */

int FUN_0001d010(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x6e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d09c FUN_0001d09c */

/* Boundary evidence: original MIPS .pdata 0001d09c..0001d19f. Semantic name remains unreviewed. */

int FUN_0001d09c(undefined2 *param_1,int param_2,void *param_3,ushort param_4,int param_5)

{
  int *piVar1;
  int local_10;
  
  FUN_00023a34();
  piVar1 = FUN_00021974(param_4 + 0x48,0);
  FUN_00023a5c();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_0001a92c(piVar1,0x20,param_2,param_5);
    FUN_0002097c(piVar1 + 7,param_3,(uint)param_4);
    *(ushort *)((int)piVar1 + 0x1a) = param_4;
    *(undefined2 *)(piVar1 + 6) = *param_1;
    local_10 = FUN_0001c980(0,piVar1,(uint)param_4);
    FUN_00023a34();
    FUN_00021a94(piVar1);
    FUN_00023a5c();
  }
  return local_10;
}



/* 0001d1a0 FUN_0001d1a0 */

/* Boundary evidence: original MIPS .pdata 0001d1a0..0001d1df. Semantic name remains unreviewed. */

int FUN_0001d1a0(undefined2 *param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_000202e0(*param_1,param_2);
  return iVar1;
}



/* 0001d1e0 FUN_0001d1e0 */

/* Boundary evidence: original MIPS .pdata 0001d1e0..0001d23f. Semantic name remains unreviewed. */

void FUN_0001d1e0(undefined4 param_1)

{
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0xe,0,0);
  FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return;
}



/* 0001d240 FUN_0001d240 */

/* Boundary evidence: original MIPS .pdata 0001d240..0001d2bf. Semantic name remains unreviewed. */

int FUN_0001d240(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0xf,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d2c0 FUN_0001d2c0 */

/* Boundary evidence: original MIPS .pdata 0001d2c0..0001d33f. Semantic name remains unreviewed. */

int FUN_0001d2c0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x10,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d340 FUN_0001d340 */

/* Boundary evidence: original MIPS .pdata 0001d340..0001d3bf. Semantic name remains unreviewed. */

int FUN_0001d340(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x12,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d3c0 FUN_0001d3c0 */

/* Boundary evidence: original MIPS .pdata 0001d3c0..0001d43f. Semantic name remains unreviewed. */

int FUN_0001d3c0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x19,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d440 FUN_0001d440 */

/* Boundary evidence: original MIPS .pdata 0001d440..0001d4cb. Semantic name remains unreviewed. */

int FUN_0001d440(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x13,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d4cc FUN_0001d4cc */

/* Boundary evidence: original MIPS .pdata 0001d4cc..0001d54b. Semantic name remains unreviewed. */

int FUN_0001d4cc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x11,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d54c FUN_0001d54c */

/* Boundary evidence: original MIPS .pdata 0001d54c..0001d5cb. Semantic name remains unreviewed. */

int FUN_0001d54c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x14,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d5cc FUN_0001d5cc */

/* Boundary evidence: original MIPS .pdata 0001d5cc..0001d64b. Semantic name remains unreviewed. */

int FUN_0001d5cc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x15,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d64c FUN_0001d64c */

/* Boundary evidence: original MIPS .pdata 0001d64c..0001d6cb. Semantic name remains unreviewed. */

int FUN_0001d64c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x16,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d6cc FUN_0001d6cc */

/* Boundary evidence: original MIPS .pdata 0001d6cc..0001d767. Semantic name remains unreviewed. */

int FUN_0001d6cc(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,
                undefined1 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x17,param_2,param_6);
  local_3e = param_5;
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d768 FUN_0001d768 */

/* Boundary evidence: original MIPS .pdata 0001d768..0001d7f3. Semantic name remains unreviewed. */

int FUN_0001d768(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x18,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d7f4 FUN_0001d7f4 */

/* Boundary evidence: original MIPS .pdata 0001d7f4..0001d873. Semantic name remains unreviewed. */

int FUN_0001d7f4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x1a,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d874 FUN_0001d874 */

/* Boundary evidence: original MIPS .pdata 0001d874..0001d8ff. Semantic name remains unreviewed. */

int FUN_0001d874(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x1b,param_3,param_4);
  local_40 = param_2;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d900 FUN_0001d900 */

/* Boundary evidence: original MIPS .pdata 0001d900..0001d98b. Semantic name remains unreviewed. */

int FUN_0001d900(undefined4 param_1,int param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x23,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001d98c FUN_0001d98c */

/* Boundary evidence: original MIPS .pdata 0001d98c..0001da33. Semantic name remains unreviewed. */

int FUN_0001d98c(undefined4 param_1,int param_2,undefined1 param_3,undefined2 param_4,
                undefined2 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined1 local_48;
  undefined2 local_46;
  undefined2 local_44;
  uint local_18;
  
  local_18 = DAT_0002e28c;
  FUN_0001a92c(auStack_60,0x24,param_2,param_7);
  local_44 = param_5;
  local_48 = param_3;
  local_46 = param_4;
  iVar1 = FUN_0001c9d0(param_1,auStack_60,0,param_6,4);
  FUN_000279ec(local_18);
  return iVar1;
}



/* 0001da34 FUN_0001da34 */

/* Boundary evidence: original MIPS .pdata 0001da34..0001dab3. Semantic name remains unreviewed. */

int FUN_0001da34(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x29,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001dab4 FUN_0001dab4 */

/* Boundary evidence: original MIPS .pdata 0001dab4..0001db33. Semantic name remains unreviewed. */

int FUN_0001dab4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x28,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001db34 FUN_0001db34 */

/* Boundary evidence: original MIPS .pdata 0001db34..0001dbc7. Semantic name remains unreviewed. */

int FUN_0001db34(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x2a,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001dbc8 FUN_0001dbc8 */

/* Boundary evidence: original MIPS .pdata 0001dbc8..0001dc5b. Semantic name remains unreviewed. */

int FUN_0001dbc8(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x26,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001dc5c FUN_0001dc5c */

/* Boundary evidence: original MIPS .pdata 0001dc5c..0001dda3. Semantic name remains unreviewed. */

int FUN_0001dc5c(undefined4 param_1,int param_2,char *param_3,int param_4)

{
  int *piVar1;
  size_t local_18;
  int local_c;
  
  local_18 = 0;
  if (*param_3 == '\x01') {
    local_18 = (uint)(byte)param_3[8] * 0x24;
  }
  FUN_00023a34();
  piVar1 = FUN_00021974(local_18 + 0x48,0);
  FUN_00023a5c();
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    FUN_0001a92c(piVar1,0x27,param_2,param_4);
    FUN_0002097c(piVar1 + 6,param_3,0xc);
    if (*param_3 == '\x01') {
      FUN_0002097c(piVar1 + 9,*(void **)(param_3 + 4),local_18);
    }
    local_c = FUN_0001c980(param_1,piVar1,local_18);
    FUN_00023a34();
    FUN_00021a94(piVar1);
    FUN_00023a5c();
  }
  return local_c;
}



/* 0001dda4 FUN_0001dda4 */

/* Boundary evidence: original MIPS .pdata 0001dda4..0001de2f. Semantic name remains unreviewed. */

int FUN_0001dda4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x3a,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001de30 FUN_0001de30 */

/* Boundary evidence: original MIPS .pdata 0001de30..0001debb. Semantic name remains unreviewed. */

int FUN_0001de30(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x3b,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001debc FUN_0001debc */

/* Boundary evidence: original MIPS .pdata 0001debc..0001df3b. Semantic name remains unreviewed. */

int FUN_0001debc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x2d,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001df3c FUN_0001df3c */

/* Boundary evidence: original MIPS .pdata 0001df3c..0001dfc7. Semantic name remains unreviewed. */

int FUN_0001df3c(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x2e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001dfc8 FUN_0001dfc8 */

/* Boundary evidence: original MIPS .pdata 0001dfc8..0001e047. Semantic name remains unreviewed. */

int FUN_0001dfc8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x2f,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e048 FUN_0001e048 */

/* Boundary evidence: original MIPS .pdata 0001e048..0001e0d3. Semantic name remains unreviewed. */

int FUN_0001e048(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x30,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e0d4 FUN_0001e0d4 */

/* Boundary evidence: original MIPS .pdata 0001e0d4..0001e153. Semantic name remains unreviewed. */

int FUN_0001e0d4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x31,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e154 FUN_0001e154 */

/* Boundary evidence: original MIPS .pdata 0001e154..0001e1d3. Semantic name remains unreviewed. */

int FUN_0001e154(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x32,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e1d4 FUN_0001e1d4 */

/* Boundary evidence: original MIPS .pdata 0001e1d4..0001e267. Semantic name remains unreviewed. */

int FUN_0001e1d4(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x33,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e268 FUN_0001e268 */

/* Boundary evidence: original MIPS .pdata 0001e268..0001e2e7. Semantic name remains unreviewed. */

int FUN_0001e268(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x34,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e2e8 FUN_0001e2e8 */

/* Boundary evidence: original MIPS .pdata 0001e2e8..0001e37b. Semantic name remains unreviewed. */

int FUN_0001e2e8(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x35,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e37c FUN_0001e37c */

/* Boundary evidence: original MIPS .pdata 0001e37c..0001e3fb. Semantic name remains unreviewed. */

int FUN_0001e37c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x36,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e3fc FUN_0001e3fc */

/* Boundary evidence: original MIPS .pdata 0001e3fc..0001e487. Semantic name remains unreviewed. */

int FUN_0001e3fc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x37,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e488 FUN_0001e488 */

/* Boundary evidence: original MIPS .pdata 0001e488..0001e513. Semantic name remains unreviewed. */

int FUN_0001e488(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x38,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e514 FUN_0001e514 */

/* Boundary evidence: original MIPS .pdata 0001e514..0001e59f. Semantic name remains unreviewed. */

int FUN_0001e514(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x39,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e5a0 FUN_0001e5a0 */

/* Boundary evidence: original MIPS .pdata 0001e5a0..0001e633. Semantic name remains unreviewed. */

int FUN_0001e5a0(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x3c,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e634 FUN_0001e634 */

/* Boundary evidence: original MIPS .pdata 0001e634..0001e6bf. Semantic name remains unreviewed. */

int FUN_0001e634(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x3d,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e6c0 FUN_0001e6c0 */

/* Boundary evidence: original MIPS .pdata 0001e6c0..0001e767. Semantic name remains unreviewed. */

int FUN_0001e6c0(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined1 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002e28c;
  FUN_0001a92c(auStack_60,0x3e,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001c9d0(param_1,auStack_60,0,param_6,2);
  FUN_000279ec(local_18);
  return iVar1;
}



/* 0001e768 FUN_0001e768 */

/* Boundary evidence: original MIPS .pdata 0001e768..0001e7f3. Semantic name remains unreviewed. */

int FUN_0001e768(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x3f,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e7f4 FUN_0001e7f4 */

/* Boundary evidence: original MIPS .pdata 0001e7f4..0001e8f3. Semantic name remains unreviewed. */

int FUN_0001e7f4(undefined4 param_1,int param_2,void *param_3,void *param_4,size_t param_5,
                int param_6)

{
  int *piVar1;
  int local_10;
  
  FUN_00023a34();
  piVar1 = FUN_00021974(param_5 + 0x48,0);
  FUN_00023a5c();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_0001a92c(piVar1,0x40,param_2,param_6);
    FUN_0002097c(piVar1 + 6,param_3,0xc);
    FUN_0002097c(piVar1 + 10,param_4,param_5);
    piVar1[9] = param_5;
    local_10 = FUN_0001c980(param_1,piVar1,param_5);
    FUN_00023a34();
    FUN_00021a94(piVar1);
    FUN_00023a5c();
  }
  return local_10;
}



/* 0001e8f4 FUN_0001e8f4 */

/* Boundary evidence: original MIPS .pdata 0001e8f4..0001e973. Semantic name remains unreviewed. */

int FUN_0001e8f4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x41,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001e974 FUN_0001e974 */

/* Boundary evidence: original MIPS .pdata 0001e974..0001ea1b. Semantic name remains unreviewed. */

int FUN_0001e974(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002e28c;
  FUN_0001a92c(auStack_60,0x42,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001c9d0(param_1,auStack_60,0,param_6,2);
  FUN_000279ec(local_18);
  return iVar1;
}



/* 0001ea1c FUN_0001ea1c */

/* Boundary evidence: original MIPS .pdata 0001ea1c..0001eabf. Semantic name remains unreviewed. */

int FUN_0001ea1c(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined2 param_5,undefined2 param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x43,param_2,param_7);
  local_3a = param_5;
  local_38 = param_6;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001eac0 FUN_0001eac0 */

/* Boundary evidence: original MIPS .pdata 0001eac0..0001eb4b. Semantic name remains unreviewed. */

int FUN_0001eac0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x44,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001eb4c FUN_0001eb4c */

/* Boundary evidence: original MIPS .pdata 0001eb4c..0001ebcb. Semantic name remains unreviewed. */

int FUN_0001eb4c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x45,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ebcc FUN_0001ebcc */

/* Boundary evidence: original MIPS .pdata 0001ebcc..0001ec57. Semantic name remains unreviewed. */

int FUN_0001ebcc(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x46,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ec58 FUN_0001ec58 */

/* Boundary evidence: original MIPS .pdata 0001ec58..0001ece3. Semantic name remains unreviewed. */

int FUN_0001ec58(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x47,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ece4 FUN_0001ece4 */

/* Boundary evidence: original MIPS .pdata 0001ece4..0001ed7f. Semantic name remains unreviewed. */

int FUN_0001ece4(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x48,param_2,param_6);
  local_3c = param_5;
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ed80 FUN_0001ed80 */

/* Boundary evidence: original MIPS .pdata 0001ed80..0001edff. Semantic name remains unreviewed. */

int FUN_0001ed80(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x49,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ee00 FUN_0001ee00 */

/* Boundary evidence: original MIPS .pdata 0001ee00..0001ee9b. Semantic name remains unreviewed. */

int FUN_0001ee00(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined2 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4a,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ee9c FUN_0001ee9c */

/* Boundary evidence: original MIPS .pdata 0001ee9c..0001ef1b. Semantic name remains unreviewed. */

int FUN_0001ee9c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4b,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ef1c FUN_0001ef1c */

/* Boundary evidence: original MIPS .pdata 0001ef1c..0001ef9b. Semantic name remains unreviewed. */

int FUN_0001ef1c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4c,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ef9c FUN_0001ef9c */

/* Boundary evidence: original MIPS .pdata 0001ef9c..0001f01b. Semantic name remains unreviewed. */

int FUN_0001ef9c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4d,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f01c FUN_0001f01c */

/* Boundary evidence: original MIPS .pdata 0001f01c..0001f0b7. Semantic name remains unreviewed. */

int FUN_0001f01c(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined1 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4e,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f0b8 FUN_0001f0b8 */

/* Boundary evidence: original MIPS .pdata 0001f0b8..0001f143. Semantic name remains unreviewed. */

int FUN_0001f0b8(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x4f,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f144 FUN_0001f144 */

/* Boundary evidence: original MIPS .pdata 0001f144..0001f1cf. Semantic name remains unreviewed. */

int FUN_0001f144(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x50,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f1d0 FUN_0001f1d0 */

/* Boundary evidence: original MIPS .pdata 0001f1d0..0001f26f. Semantic name remains unreviewed. */

int FUN_0001f1d0(undefined4 param_1,int param_2,void *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 auStack_40 [8];
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x51,param_2,param_5);
  FUN_0002097c(auStack_40,param_3,8);
  local_38 = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f270 FUN_0001f270 */

/* Boundary evidence: original MIPS .pdata 0001f270..0001f30b. Semantic name remains unreviewed. */

int FUN_0001f270(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x52,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f30c FUN_0001f30c */

/* Boundary evidence: original MIPS .pdata 0001f30c..0001f3a7. Semantic name remains unreviewed. */

int FUN_0001f30c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x53,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f3a8 FUN_0001f3a8 */

/* Boundary evidence: original MIPS .pdata 0001f3a8..0001f427. Semantic name remains unreviewed. */

int FUN_0001f3a8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x55,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f428 FUN_0001f428 */

/* Boundary evidence: original MIPS .pdata 0001f428..0001f4bb. Semantic name remains unreviewed. */

int FUN_0001f428(undefined4 param_1,int param_2,undefined4 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined1 local_3c;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x56,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f4bc FUN_0001f4bc */

/* Boundary evidence: original MIPS .pdata 0001f4bc..0001f53b. Semantic name remains unreviewed. */

int FUN_0001f4bc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x57,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f53c FUN_0001f53c */

/* Boundary evidence: original MIPS .pdata 0001f53c..0001f5c7. Semantic name remains unreviewed. */

int FUN_0001f53c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x58,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f5c8 FUN_0001f5c8 */

/* Boundary evidence: original MIPS .pdata 0001f5c8..0001f653. Semantic name remains unreviewed. */

int FUN_0001f5c8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x59,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f654 FUN_0001f654 */

/* Boundary evidence: original MIPS .pdata 0001f654..0001f6d3. Semantic name remains unreviewed. */

int FUN_0001f654(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5a,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f6d4 FUN_0001f6d4 */

/* Boundary evidence: original MIPS .pdata 0001f6d4..0001f773. Semantic name remains unreviewed. */

int FUN_0001f6d4(undefined4 param_1,int param_2,undefined1 param_3,void *param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 auStack_3c [44];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5b,param_2,param_5);
  local_40 = param_3;
  FUN_0002097c(auStack_3c,param_4,8);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f774 FUN_0001f774 */

/* Boundary evidence: original MIPS .pdata 0001f774..0001f7ff. Semantic name remains unreviewed. */

int FUN_0001f774(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5c,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f800 FUN_0001f800 */

/* Boundary evidence: original MIPS .pdata 0001f800..0001f87f. Semantic name remains unreviewed. */

int FUN_0001f800(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5d,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f880 FUN_0001f880 */

/* Boundary evidence: original MIPS .pdata 0001f880..0001f90b. Semantic name remains unreviewed. */

int FUN_0001f880(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f90c FUN_0001f90c */

/* Boundary evidence: original MIPS .pdata 0001f90c..0001f9a7. Semantic name remains unreviewed. */

int FUN_0001f90c(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined2 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x5f,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001f9a8 FUN_0001f9a8 */

/* Boundary evidence: original MIPS .pdata 0001f9a8..0001fa27. Semantic name remains unreviewed. */

int FUN_0001f9a8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x60,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fa28 FUN_0001fa28 */

/* Boundary evidence: original MIPS .pdata 0001fa28..0001faa7. Semantic name remains unreviewed. */

int FUN_0001fa28(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x61,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001faa8 FUN_0001faa8 */

/* Boundary evidence: original MIPS .pdata 0001faa8..0001fb4f. Semantic name remains unreviewed. */

int FUN_0001faa8(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002e28c;
  FUN_0001a92c(auStack_60,0x62,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001c9d0(param_1,auStack_60,0,param_6,2);
  FUN_000279ec(local_18);
  return iVar1;
}



/* 0001fb50 FUN_0001fb50 */

/* Boundary evidence: original MIPS .pdata 0001fb50..0001fbcf. Semantic name remains unreviewed. */

int FUN_0001fb50(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,99,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fbd0 FUN_0001fbd0 */

/* Boundary evidence: original MIPS .pdata 0001fbd0..0001fc63. Semantic name remains unreviewed. */

int FUN_0001fbd0(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,100,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fc64 FUN_0001fc64 */

/* Boundary evidence: original MIPS .pdata 0001fc64..0001fce3. Semantic name remains unreviewed. */

int FUN_0001fc64(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x66,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fce4 FUN_0001fce4 */

/* Boundary evidence: original MIPS .pdata 0001fce4..0001fd87. Semantic name remains unreviewed. */

int FUN_0001fce4(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined2 param_5,undefined2 param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x65,param_2,param_7);
  local_3a = param_5;
  local_38 = param_6;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fd88 FUN_0001fd88 */

/* Boundary evidence: original MIPS .pdata 0001fd88..0001fe07. Semantic name remains unreviewed. */

int FUN_0001fd88(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x67,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fe08 FUN_0001fe08 */

/* Boundary evidence: original MIPS .pdata 0001fe08..0001fe87. Semantic name remains unreviewed. */

int FUN_0001fe08(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x68,param_2,param_3);
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001fe88 FUN_0001fe88 */

/* Boundary evidence: original MIPS .pdata 0001fe88..0001ff13. Semantic name remains unreviewed. */

int FUN_0001fe88(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x69,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0001ff14 FUN_0001ff14 */

/* Boundary evidence: original MIPS .pdata 0001ff14..0002001f. Semantic name remains unreviewed. */

int FUN_0001ff14(undefined4 param_1,int param_2,int param_3,void *param_4,ushort param_5,
                undefined1 param_6,int param_7)

{
  int *piVar1;
  int local_10;
  
  FUN_00023a34();
  piVar1 = FUN_00021974(param_5 + 0x48,0);
  FUN_00023a5c();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_0001a92c(piVar1,0x6a,param_2,param_7);
    FUN_0002097c((void *)((int)piVar1 + 0x1f),param_4,(uint)param_5);
    piVar1[6] = param_3;
    *(ushort *)(piVar1 + 7) = param_5;
    *(undefined1 *)((int)piVar1 + 0x1e) = param_6;
    local_10 = FUN_0001c980(param_1,piVar1,(uint)param_5);
    FUN_00023a34();
    FUN_00021a94(piVar1);
    FUN_00023a5c();
  }
  return local_10;
}



/* 00020020 FUN_00020020 */

/* Boundary evidence: original MIPS .pdata 00020020..000200ab. Semantic name remains unreviewed. */

int FUN_00020020(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x6b,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001c980(param_1,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 000200ac FUN_000200ac */

/* Boundary evidence: original MIPS .pdata 000200ac..000201a7. Semantic name remains unreviewed. */

int FUN_000200ac(undefined4 param_1,char *param_2,undefined1 param_3,int param_4,int param_5)

{
  size_t sVar1;
  int *piVar2;
  int local_c;
  
  sVar1 = FUN_00020a04(param_2);
  FUN_00023a34();
  piVar2 = FUN_00021974(sVar1 + 0x49,0);
  FUN_00023a5c();
  if (piVar2 == (int *)0x0) {
    local_c = 7;
  }
  else {
    FUN_0001a92c(piVar2,0x1c,param_4,param_5);
    FUN_0002097c((void *)((int)piVar2 + 0x19),param_2,sVar1 + 1);
    *(undefined1 *)(piVar2 + 6) = param_3;
    local_c = FUN_0001c980(param_1,piVar2,sVar1 + 1);
    FUN_00023a34();
    FUN_00021a94(piVar2);
    FUN_00023a5c();
  }
  return local_c;
}



/* 000201a8 FUN_000201a8 */

/* Boundary evidence: original MIPS .pdata 000201a8..000202df. Semantic name remains unreviewed. */

undefined4 FUN_000201a8(undefined4 param_1,char *param_2,void *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_c;
  
  FUN_00023a34();
  piVar1 = FUN_00021974(0x1c,0);
  FUN_00023a5c();
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    piVar1[1] = -1;
    FUN_00023a34();
    piVar2 = FUN_00023fa4(param_2);
    *piVar1 = (int)piVar2;
    FUN_00023a5c();
    if (*piVar1 == 0) {
      FUN_00023a34();
      FUN_00021a94(piVar1);
      FUN_00023a5c();
      local_c = 7;
    }
    else {
      FUN_0002097c(piVar1 + 2,param_3,0xc);
      piVar1[5] = 0;
      piVar1[6] = *(int *)(DAT_0016de5c + 0x1c);
      **(undefined4 **)(DAT_0016de5c + 0x1c) = piVar1;
      *(int **)(DAT_0016de5c + 0x1c) = piVar1 + 5;
      local_c = 0;
    }
  }
  return local_c;
}



/* 000202e0 FUN_000202e0 */

/* Boundary evidence: original MIPS .pdata 000202e0..0002036b. Semantic name remains unreviewed. */

int FUN_000202e0(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  undefined1 local_3e;
  uint local_10;
  
  local_10 = DAT_0002e28c;
  FUN_0001a92c(auStack_58,0x22,0,0);
  local_40 = param_1;
  local_3e = param_2;
  iVar1 = FUN_0001c980(0,auStack_58,0);
  FUN_000279ec(local_10);
  return iVar1;
}



/* 0002036c FUN_0002036c */

/* Boundary evidence: original MIPS .pdata 0002036c..000204f7. Semantic name remains unreviewed. */

void FUN_0002036c(undefined4 *param_1,undefined2 param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  int local_14;
  
  for (local_14 = param_1[6]; (local_14 != 0 && (*(uint *)(local_14 + 4) != (uint)param_3));
      local_14 = *(int *)(local_14 + 0x14)) {
  }
  if (local_14 == 0) {
    FUN_000202e0(param_2,4);
  }
  else {
    FUN_00023a34();
    piVar1 = FUN_00021974(0x14,1);
    FUN_00023a5c();
    if (piVar1 != (int *)0x0) {
      *(undefined2 *)piVar1 = param_2;
      piVar1[1] = local_14;
      iVar2 = (**(code **)(local_14 + 8))(*param_1,piVar1,param_2,param_3,piVar1 + 2);
      if (iVar2 == 0) {
        piVar1[3] = 0;
        piVar1[4] = param_1[9];
        *(int **)param_1[9] = piVar1;
        param_1[9] = piVar1 + 3;
      }
      else {
        FUN_00023a34();
        FUN_00021a94(piVar1);
        FUN_00023a5c();
      }
    }
  }
  return;
}



/* 000204f8 FUN_000204f8 */

/* Boundary evidence: original MIPS .pdata 000204f8..0002057f. Semantic name remains unreviewed. */

void FUN_000204f8(int param_1,char *param_2,byte param_3)

{
  int iVar1;
  undefined4 *local_10;
  
  local_10 = *(undefined4 **)(param_1 + 0x18);
  while( true ) {
    if (local_10 == (undefined4 *)0x0) {
      return;
    }
    iVar1 = FUN_00020a38(param_2,(char *)*local_10);
    if (iVar1 == 0) break;
    local_10 = (undefined4 *)local_10[5];
  }
  local_10[1] = (uint)param_3;
  return;
}



/* 00020580 FUN_00020580 */

/* Boundary evidence: original MIPS .pdata 00020580..0002068f. Semantic name remains unreviewed. */

void FUN_00020580(int param_1,short param_2)

{
  short *local_10;
  
  for (local_10 = *(short **)(param_1 + 0x20); (local_10 != (short *)0x0 && (*local_10 != param_2));
      local_10 = *(short **)(local_10 + 6)) {
  }
  if (local_10 != (short *)0x0) {
    (**(code **)(*(int *)(local_10 + 2) + 0xc))(*(undefined4 *)(local_10 + 4));
    if (*(int *)(local_10 + 6) == 0) {
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(local_10 + 8);
    }
    else {
      *(undefined4 *)(*(int *)(local_10 + 6) + 0x10) = *(undefined4 *)(local_10 + 8);
    }
    **(undefined4 **)(local_10 + 8) = *(undefined4 *)(local_10 + 6);
    FUN_00023a34();
    FUN_00021a94((undefined4 *)local_10);
    FUN_00023a5c();
  }
  return;
}



/* 00020690 FUN_00020690 */

/* Boundary evidence: original MIPS .pdata 00020690..00020743. Semantic name remains unreviewed. */

void FUN_00020690(int param_1,short param_2,undefined4 param_3,undefined2 param_4)

{
  short *local_10;
  
  for (local_10 = *(short **)(param_1 + 0x20); (local_10 != (short *)0x0 && (*local_10 != param_2));
      local_10 = *(short **)(local_10 + 6)) {
  }
  if (local_10 != (short *)0x0) {
    (**(code **)(*(int *)(local_10 + 2) + 0x10))(*(undefined4 *)(local_10 + 4),param_3,param_4);
  }
  return;
}



/* 00020744 FUN_00020744 */

/* Boundary evidence: original MIPS .pdata 00020744..00020787. Semantic name remains unreviewed. */

int FUN_00020744(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_00024e40("wince_usbware_entry: USER MODE\n",param_2,param_3,param_4);
  iVar1 = FUN_000207bc((undefined **)0x0,param_2,param_3,param_4);
  return iVar1;
}



/* 00020788 FUN_00020788 */

/* Boundary evidence: original MIPS .pdata 00020788..000207bb. Semantic name remains unreviewed. */

void FUN_00020788(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00024e40("wince_usbware_exit: USER MODE\n",param_2,param_3,param_4);
  FUN_000208a0();
  return;
}



/* 000207bc FUN_000207bc */

/* Boundary evidence: original MIPS .pdata 000207bc..0002089f. Semantic name remains unreviewed. */

int FUN_000207bc(undefined **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined **local_res0;
  int local_c;
  
  local_c = FUN_00025014();
  if (local_c == 0) {
    local_res0 = param_1;
    if (param_1 == (undefined **)0x0) {
      local_res0 = FUN_00025860();
    }
    local_c = FUN_000252a8((uint *)local_res0,param_2,param_3,param_4);
    if (local_c == 0) {
      local_c = 0;
    }
    else {
      pcVar1 = FUN_0002469c(local_c);
      FUN_00024e40("%s: Error starting the usb stack %s\n","j_stack_init",pcVar1,param_4);
      FUN_00025074();
    }
  }
  else {
    FUN_00024e40("%s: Error initializing memory\n","j_stack_init",param_3,param_4);
  }
  return local_c;
}



/* 000208a0 FUN_000208a0 */

/* Boundary evidence: original MIPS .pdata 000208a0..000208c7. Semantic name remains unreviewed. */

void FUN_000208a0(void)

{
  FUN_00025404();
  FUN_00025074();
  return;
}



/* 000208c8 FUN_000208c8 */

/* Boundary evidence: original MIPS .pdata 000208c8..00020917. Semantic name remains unreviewed. */

undefined4 FUN_000208c8(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00021194();
  return uVar1;
}



/* 00020918 FUN_00020918 */

/* Boundary evidence: original MIPS .pdata 00020918..00020937. Semantic name remains unreviewed. */

void FUN_00020918(void)

{
  FUN_00021248();
  return;
}



/* 00020938 FUN_00020938 */

/* Boundary evidence: original MIPS .pdata 00020938..0002097b. Semantic name remains unreviewed. */

int FUN_00020938(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,param_3);
  return iVar1;
}



/* 0002097c FUN_0002097c */

/* Boundary evidence: original MIPS .pdata 0002097c..000209bf. Semantic name remains unreviewed. */

void * FUN_0002097c(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memcpy(param_1,param_2,param_3);
  return pvVar1;
}



/* 000209c0 FUN_000209c0 */

/* Boundary evidence: original MIPS .pdata 000209c0..00020a03. Semantic name remains unreviewed. */

void * FUN_000209c0(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memset(param_1,param_2,param_3);
  return pvVar1;
}



/* 00020a04 FUN_00020a04 */

/* Boundary evidence: original MIPS .pdata 00020a04..00020a37. Semantic name remains unreviewed. */

size_t FUN_00020a04(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  return sVar1;
}



/* 00020a38 FUN_00020a38 */

/* Boundary evidence: original MIPS .pdata 00020a38..00020a73. Semantic name remains unreviewed. */

int FUN_00020a38(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  return iVar1;
}



/* 00020a74 FUN_00020a74 */

/* Boundary evidence: original MIPS .pdata 00020a74..00020ab7. Semantic name remains unreviewed. */

int FUN_00020a74(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = strncmp(param_1,param_2,param_3);
  return iVar1;
}



/* 00020ab8 FUN_00020ab8 */

/* Boundary evidence: original MIPS .pdata 00020ab8..00020b63. Semantic name remains unreviewed. */

int FUN_00020ab8(char *param_1,size_t param_2,char *param_3,undefined4 param_4)

{
  undefined4 local_resc;
  int local_18;
  int local_10;
  
  if (param_2 == 0) {
    local_10 = -1;
  }
  else {
    local_resc = param_4;
    local_18 = _vsnprintf_s(param_1,param_2,0xffffffff,param_3,(va_list)&local_resc);
    if ((int)param_2 < local_18) {
      local_18 = param_2 - local_18;
    }
    local_10 = local_18;
  }
  return local_10;
}



/* 00020b64 FUN_00020b64 */

/* Boundary evidence: original MIPS .pdata 00020b64..00020c8b. Semantic name remains unreviewed. */

undefined4 FUN_00020b64(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *lpParameter;
  HANDLE pvVar1;
  int iVar2;
  undefined4 local_14;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  lpParameter = FUN_00021974(8,1);
  if (lpParameter == (int *)0x0) {
    local_14 = 7;
  }
  else {
    *lpParameter = param_1;
    lpParameter[1] = param_2;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00020c8c,lpParameter,0,(LPDWORD)0x0);
    if (pvVar1 == (HANDLE)0x0) {
      FUN_00021a94(lpParameter);
      local_14 = 10;
    }
    else {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = pvVar1;
      }
      iVar2 = FUN_00020d1c(param_3);
      CeSetThreadPriority(pvVar1,iVar2);
      local_14 = 0;
    }
  }
  return local_14;
}



/* 00020c8c FUN_00020c8c */

/* Boundary evidence: original MIPS .pdata 00020c8c..00020d1b. Semantic name remains unreviewed. */

undefined4 FUN_00020c8c(int *param_1)

{
  undefined4 local_c;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    local_c = 0;
  }
  else {
    FUN_00023a34();
    (*(code *)*param_1)(param_1[1]);
    FUN_00021a94(param_1);
    FUN_00023a5c();
    local_c = 1;
  }
  return local_c;
}



/* 00020d1c FUN_00020d1c */

/* Boundary evidence: original MIPS .pdata 00020d1c..00020d47. Semantic name remains unreviewed. */

int FUN_00020d1c(int param_1)

{
  return DAT_0016de90 + param_1;
}



/* 00020d48 FUN_00020d48 */

/* Boundary evidence: original MIPS .pdata 00020d48..00020d73. Semantic name remains unreviewed. */

undefined4 FUN_00020d48(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00021250();
  return uVar1;
}



/* 00020d74 FUN_00020d74 */

/* Boundary evidence: original MIPS .pdata 00020d74..00020def. Semantic name remains unreviewed. */

undefined4 FUN_00020d74(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 local_c;
  
  *param_1 = 0;
  pvVar1 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    local_c = 10;
  }
  else {
    *param_1 = pvVar1;
    local_c = 0;
  }
  return local_c;
}



/* 00020df0 FUN_00020df0 */

/* Boundary evidence: original MIPS .pdata 00020df0..00020e33. Semantic name remains unreviewed. */

void FUN_00020df0(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    CloseHandle(param_1);
  }
  return;
}



/* 00020e34 FUN_00020e34 */

/* Boundary evidence: original MIPS .pdata 00020e34..00020e83. Semantic name remains unreviewed. */

void FUN_00020e34(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    WaitForSingleObject(param_1,0xffffffff);
  }
  return;
}



/* 00020e84 FUN_00020e84 */

/* Boundary evidence: original MIPS .pdata 00020e84..00020ec3. Semantic name remains unreviewed. */

void FUN_00020e84(HANDLE param_1)

{
  ReleaseSemaphore(param_1,1,(LPLONG)0x0);
  return;
}



/* 00020ed0 FUN_00020ed0 */

/* Boundary evidence: original MIPS .pdata 00020ed0..00020ef7. Semantic name remains unreviewed. */

void FUN_00020ed0(int param_1)

{
  FUN_00027370(param_1);
  return;
}



/* 00020ef8 FUN_00020ef8 */

/* Boundary evidence: original MIPS .pdata 00020ef8..00020f37. Semantic name remains unreviewed. */

void FUN_00020ef8(DWORD param_1)

{
  FUN_00023a5c();
  Sleep(param_1);
  FUN_00023a34();
  return;
}



/* 00020f38 FUN_00020f38 */

/* Boundary evidence: original MIPS .pdata 00020f38..00020fb3. Semantic name remains unreviewed. */

undefined4 FUN_00020f38(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 local_c;
  
  *param_1 = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    local_c = 10;
  }
  else {
    *param_1 = pvVar1;
    local_c = 0;
  }
  return local_c;
}



/* 00020fb4 FUN_00020fb4 */

/* Boundary evidence: original MIPS .pdata 00020fb4..00020fe3. Semantic name remains unreviewed. */

void FUN_00020fb4(HANDLE param_1)

{
  CloseHandle(param_1);
  return;
}



/* 00020fe4 FUN_00020fe4 */

/* Boundary evidence: original MIPS .pdata 00020fe4..000210b7. Semantic name remains unreviewed. */

undefined4 FUN_00020fe4(HANDLE param_1,DWORD param_2)

{
  DWORD DVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_00023a5c();
  local_10 = param_2;
  if (param_2 == 0) {
    local_10 = 0xffffffff;
  }
  DVar1 = WaitForSingleObject(param_1,local_10);
  FUN_00023a34();
  if (DVar1 == 0) {
    local_14 = 0;
  }
  else if (DVar1 == 0x102) {
    local_14 = 0xc;
  }
  else {
    local_14 = 10;
  }
  return local_14;
}



/* 000210b8 FUN_000210b8 */

/* Boundary evidence: original MIPS .pdata 000210b8..00021103. Semantic name remains unreviewed. */

undefined4 FUN_000210b8(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  
  iVar1 = FUN_00011350(param_1);
  if (iVar1 == 0) {
    local_10 = 10;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* 00021104 FUN_00021104 */

/* Boundary evidence: original MIPS .pdata 00021104..00021173. Semantic name remains unreviewed. */

void FUN_00021104(uint *param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *param_1 = DVar1 / 1000;
  param_1[1] = (DVar1 % 1000) * 1000;
  return;
}



/* 00021174 FUN_00021174 */

/* Boundary evidence: original MIPS .pdata 00021174..00021193. Semantic name remains unreviewed. */

undefined4 FUN_00021174(void)

{
  return DAT_0016de98;
}



/* 00021194 FUN_00021194 */

/* Boundary evidence: original MIPS .pdata 00021194..00021247. Semantic name remains unreviewed. */

undefined4 FUN_00021194(void)

{
  BOOL BVar1;
  undefined8 uVar2;
  undefined4 local_10;
  
  BVar1 = QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_0016de98);
  uVar2 = CONCAT44(DAT_0016de8c,DAT_0016de88);
  if ((BVar1 == 0) || (DAT_0016de98 == 0 && DAT_0016de9c == 0)) {
    local_10 = 10;
  }
  else {
    uVar2 = __ll_div(DAT_0016de98,DAT_0016de9c,&DAT_000f4240,0);
    DAT_0016de90 = 100;
    local_10 = 0;
  }
  DAT_0016de8c = (undefined4)((ulonglong)uVar2 >> 0x20);
  DAT_0016de88 = (undefined4)uVar2;
  return local_10;
}



/* 00021248 FUN_00021248 */

void FUN_00021248(void)

{
  return;
}



/* 00021250 FUN_00021250 */

/* Boundary evidence: original MIPS .pdata 00021250..0002127f. Semantic name remains unreviewed. */

undefined4 FUN_00021250(void)

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(8);
  return uVar1;
}



/* 00021280 FUN_00021280 */

/* Boundary evidence: original MIPS .pdata 00021280..000215cb. Semantic name remains unreviewed. */

int FUN_00021280(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_58;
  DWORD local_54;
  int *local_50;
  byte abStack_49 [13];
  wchar_t *local_3c;
  uint local_38;
  uint local_34;
  uint local_c;
  
  local_34 = DAT_0002e28c;
  local_3c = L"UWD1:";
  local_54 = 0;
  local_50 = FUN_00021974(0x1018,1);
  if (local_50 == (int *)0x0) {
    FUN_000279ec(local_34);
    return 7;
  }
  *param_4 = local_50;
  *local_50 = param_1;
  local_50[2] = param_3;
  local_50[3] = param_2;
  pvVar2 = CreateFileW(local_3c,0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  local_50[1] = (int)pvVar2;
  if (local_50[1] == -1) {
    local_58 = 5;
  }
  else {
    uVar7 = 0;
    uVar6 = 0;
    pcVar5 = (char *)0x81002050;
    BVar3 = DeviceIoControl((HANDLE)local_50[1],0x81002050,(LPVOID)0x0,0,abStack_49 + 1,10,&local_54
                            ,(LPOVERLAPPED)0x0);
    if (BVar3 == 0) {
      FUN_00024e40("os_user_create: get version ioctl failed\n",pcVar5,uVar6,uVar7);
      local_58 = 5;
    }
    else {
      if (local_54 == 10) {
        uVar6 = 10;
        pcVar5 = "3.5.14.82";
        iVar4 = FUN_00020938(abStack_49 + 1,"3.5.14.82",10);
        if (iVar4 == 0) {
          local_58 = FUN_00020b64(0x215cc,(int)local_50,3,"ioctl_recv_thread",local_50 + 0x405);
          if (local_58 == 0) {
            FUN_000279ec(local_34);
            return 0;
          }
          goto LAB_00021598;
        }
      }
      if (local_54 == 0) {
        FUN_00024e40("os_user_create: get version ioctl returned empty string\n",pcVar5,uVar6,uVar7)
        ;
      }
      else {
        if (local_54 < 0xb) {
          local_c = local_54;
        }
        else {
          local_c = 10;
        }
        uVar1 = local_c;
        local_54 = local_c;
        abStack_49[local_c] = 0;
        for (local_38 = 0; local_38 < uVar1 - 1; local_38 = local_38 + 1) {
          if ((abStack_49[local_38 + 1] < 0x20) || (0x7e < abStack_49[local_38 + 1])) {
            abStack_49[local_38 + 1] = 0x3f;
          }
        }
        FUN_00024e40("os_user_create: get version ioctl returned unmatched  version \"%s\"\n",
                     abStack_49 + 1,uVar6,uVar7);
      }
      local_58 = 10;
    }
  }
LAB_00021598:
  FUN_000216c0(local_50);
  FUN_000279ec(local_34);
  return local_58;
}



/* 000215cc FUN_000215cc */

/* Boundary evidence: original MIPS .pdata 000215cc..000216bf. Semantic name remains unreviewed. */

undefined4 FUN_000215cc(undefined4 *param_1)

{
  char local_30 [4];
  int local_2c;
  undefined4 *local_28;
  DWORD local_24 [7];
  
  local_30[0] = '\0';
  local_28 = param_1;
  while( true ) {
    FUN_00023a5c();
    local_2c = DeviceIoControl((HANDLE)local_28[1],0x81002040,local_30,1,local_28 + 3,0x1008,
                               local_24,(LPOVERLAPPED)0x0);
    FUN_00023a34();
    if (local_2c == 0) {
      return 5;
    }
    if (local_30[0] != '\0') break;
    (*(code *)local_28[2])(*local_28,local_28 + 3,local_24[0]);
  }
  return 0;
}



/* 000216c0 FUN_000216c0 */

/* Boundary evidence: original MIPS .pdata 000216c0..000217d3. Semantic name remains unreviewed. */

void FUN_000216c0(undefined4 *param_1)

{
  DWORD aDStack_1c [5];
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[0x405] != 0) {
      FUN_00023a5c();
      DeviceIoControl((HANDLE)param_1[1],0x81002044,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_1c,
                      (LPOVERLAPPED)0x0);
      WaitForSingleObject((HANDLE)param_1[0x405],0xffffffff);
      CloseHandle((HANDLE)param_1[0x405]);
      FUN_00023a34();
    }
    if (param_1[1] != -1) {
      CloseHandle((HANDLE)param_1[1]);
    }
    FUN_00021a94(param_1);
  }
  return;
}



/* 000217d4 FUN_000217d4 */

/* Boundary evidence: original MIPS .pdata 000217d4..000218b7. Semantic name remains unreviewed. */

undefined4 FUN_000217d4(int param_1,int param_2)

{
  undefined4 local_30;
  uint local_2c;
  BOOL local_28;
  int local_24;
  undefined4 local_10;
  
  local_24 = param_1;
  local_28 = DeviceIoControl(*(HANDLE *)(param_1 + 4),*(DWORD *)(param_2 + 0x1008),
                             (LPVOID)(param_2 + 8),*(DWORD *)(param_2 + 4),
                             (LPVOID)(param_2 + 0x1010),*(DWORD *)(param_2 + 0x100c),&local_2c,
                             (LPOVERLAPPED)0x0);
  if ((local_28 == 0) || (local_2c < 4)) {
    local_10 = 5;
  }
  else {
    memcpy(&local_30,(void *)(param_2 + 0x1010),4);
    *(uint *)(param_2 + 0x100c) = local_2c;
    local_10 = local_30;
  }
  return local_10;
}



/* 000218b8 FUN_000218b8 */

void FUN_000218b8(void)

{
  return;
}



/* 000218c0 FUN_000218c0 */

/* Boundary evidence: original MIPS .pdata 000218c0..0002196b. Semantic name remains unreviewed. */

void FUN_000218c0(void)

{
  uint local_8;
  
  for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0016dea0 + local_8 * 4) = 0;
  }
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    *(int *)(&DAT_0016deb8 + local_8 * 4) = 0x10 << (local_8 & 0x1f);
  }
  return;
}



/* 0002196c FUN_0002196c */

void FUN_0002196c(void)

{
  return;
}



/* 00021974 FUN_00021974 */

/* Boundary evidence: original MIPS .pdata 00021974..00021a93. Semantic name remains unreviewed. */

int * FUN_00021974(uint param_1,ushort param_2)

{
  int local_18;
  int *local_14;
  
  for (local_18 = 0; (local_18 < 5 && (*(uint *)(&DAT_0016deb8 + local_18 * 4) < param_1));
      local_18 = local_18 + 1) {
  }
  if (local_18 < 5) {
    local_14 = FUN_00021b48((int *)(&DAT_0016dea0 + local_18 * 4),
                            *(int *)(&DAT_0016deb8 + local_18 * 4));
  }
  else {
    local_14 = FUN_00021dc8((int *)&DAT_0016deb4,param_1);
  }
  if ((local_14 != (int *)0x0) && ((param_2 & 1) != 0)) {
    FUN_000209c0(local_14,0,param_1);
  }
  return local_14;
}



/* 00021a94 FUN_00021a94 */

/* Boundary evidence: original MIPS .pdata 00021a94..00021b47. Semantic name remains unreviewed. */

void FUN_00021a94(undefined4 *param_1)

{
  int local_8;
  
  for (local_8 = 0; (local_8 < 5 && (*(uint *)(&DAT_0016deb8 + local_8 * 4) < (uint)param_1[-1]));
      local_8 = local_8 + 1) {
  }
  *param_1 = *(undefined4 *)(&DAT_0016dea0 + local_8 * 4);
  *(undefined4 **)(&DAT_0016dea0 + local_8 * 4) = param_1;
  return;
}



/* 00021b48 FUN_00021b48 */

/* Boundary evidence: original MIPS .pdata 00021b48..00021bd3. Semantic name remains unreviewed. */

int * FUN_00021b48(int *param_1,int param_2)

{
  int *local_10;
  
  if (*param_1 == 0) {
    local_10 = FUN_00021bd4(param_2);
    if (local_10 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  else {
    local_10 = (int *)*param_1;
    *param_1 = *local_10;
  }
  return local_10;
}



/* 00021bd4 FUN_00021bd4 */

/* Boundary evidence: original MIPS .pdata 00021bd4..00021c4f. Semantic name remains unreviewed. */

int * FUN_00021bd4(int param_1)

{
  int iVar1;
  int *local_18;
  uint local_14;
  int *local_c;
  
  local_14 = param_1 + 4;
  iVar1 = FUN_00021c50(local_14,(int *)&local_18,(int *)0x0,0);
  if (iVar1 == 0) {
    *local_18 = param_1;
    local_c = local_18 + 1;
  }
  else {
    local_c = (int *)0x0;
  }
  return local_c;
}



/* 00021c50 FUN_00021c50 */

/* Boundary evidence: original MIPS .pdata 00021c50..00021dc7. Semantic name remains unreviewed. */

undefined4 FUN_00021c50(uint param_1,int *param_2,int *param_3,int param_4)

{
  uint local_8;
  undefined4 local_4;
  
  local_8 = param_1;
  if ((param_1 & 3) != 0) {
    local_8 = (param_1 + 4) - (param_1 & 3);
  }
  if (*(int *)(&DAT_0016ded0 + param_4 * 4) + local_8 < *(uint *)(&DAT_0016ded8 + param_4 * 4)) {
    if (param_2 != (int *)0x0) {
      *param_2 = *(int *)(&DAT_0016decc + param_4 * 4) + *(int *)(&DAT_0016ded0 + param_4 * 4);
    }
    if (param_3 != (int *)0x0) {
      *param_3 = *(int *)(&DAT_0016ded4 + param_4 * 4) + *(int *)(&DAT_0016ded0 + param_4 * 4);
    }
    *(uint *)(&DAT_0016ded0 + param_4 * 4) = *(int *)(&DAT_0016ded0 + param_4 * 4) + local_8;
    local_4 = 0;
  }
  else {
    local_4 = 7;
  }
  return local_4;
}



/* 00021dc8 FUN_00021dc8 */

/* Boundary evidence: original MIPS .pdata 00021dc8..00021e9b. Semantic name remains unreviewed. */

int * FUN_00021dc8(int *param_1,uint param_2)

{
  int *local_18;
  int *local_14;
  
  local_14 = (int *)0x0;
  local_18 = param_1;
  do {
    if (*local_18 == 0) {
LAB_00021e48:
      if ((local_14 == (int *)0x0) && (local_14 = FUN_00021bd4(param_2), local_14 == (int *)0x0)) {
        return (int *)0x0;
      }
      return local_14;
    }
    if (param_2 <= *(uint *)(*local_18 + -4)) {
      local_14 = (int *)*local_18;
      *local_18 = *local_14;
      goto LAB_00021e48;
    }
    local_18 = (int *)*local_18;
  } while( true );
}



/* 00021e9c FUN_00021e9c */

/* Boundary evidence: original MIPS .pdata 00021e9c..00021ecb. Semantic name remains unreviewed. */

int FUN_00021e9c(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) + param_2;
}



/* 00021ecc FUN_00021ecc */

/* Boundary evidence: original MIPS .pdata 00021ecc..00021efb. Semantic name remains unreviewed. */

int FUN_00021ecc(int *param_1,int param_2)

{
  return *param_1 + param_2;
}



/* 00021efc FUN_00021efc */

/* Boundary evidence: original MIPS .pdata 00021efc..00021f1b. Semantic name remains unreviewed. */

undefined4 FUN_00021efc(undefined4 param_1)

{
  return param_1;
}



/* 00021f1c FUN_00021f1c */

/* Boundary evidence: original MIPS .pdata 00021f1c..000221db. Semantic name remains unreviewed. */

int FUN_00021f1c(uint param_1,ushort param_2,int *param_3,int *param_4,ushort param_5,
                undefined4 *param_6)

{
  ushort uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int *local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  
  local_1c = (int *)0x0;
  if (param_1 == 0) {
    piVar3 = FUN_00021974(0x20,1);
    if (piVar3 == (int *)0x0) {
      local_18 = 7;
    }
    else {
      *(byte *)((int)piVar3 + 0x12) = *(byte *)((int)piVar3 + 0x12) | 8;
      *param_6 = piVar3;
      local_18 = 0;
    }
  }
  else {
    local_14 = param_1;
    if (param_1 < 0x20) {
      local_14 = 0x20;
    }
    uVar2 = local_14;
    if (param_2 < 4) {
      local_10 = 4;
    }
    else {
      local_10 = (uint)param_2;
    }
    uVar1 = (ushort)local_10;
    local_18 = FUN_00022800(local_14,uVar1,param_5,(int *)&local_1c);
    if ((local_18 == 0) &&
       (((local_1c != (int *)0x0 || ((param_5 & 2) == 0)) ||
        (local_18 = FUN_00022800(uVar2,uVar1,param_5 & 0xfffd,(int *)&local_1c), local_18 == 0)))) {
      if (local_1c == (int *)0x0) {
        iVar4 = FUN_000221dc(uVar2,uVar1,param_5);
        piVar3 = DAT_0016dedc;
        if (iVar4 != 0) {
          return iVar4;
        }
        local_1c = DAT_0016dedc;
        if (DAT_0016dedc[6] != 0) {
          *(int *)(DAT_0016dedc[6] + 0x1c) = DAT_0016dedc[7];
        }
        *(int *)piVar3[7] = piVar3[6];
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = local_1c;
      }
      if (param_3 != (int *)0x0) {
        iVar4 = FUN_00021ecc(local_1c,0);
        *param_3 = iVar4;
      }
      if (param_4 != (int *)0x0) {
        iVar4 = FUN_00021e9c((int)local_1c,0);
        *param_4 = iVar4;
      }
      if ((param_5 & 1) != 0) {
        pvVar5 = (void *)FUN_00021ecc(local_1c,0);
        FUN_000209c0(pvVar5,0,uVar2);
      }
      local_18 = 0;
    }
  }
  return local_18;
}



/* 000221dc FUN_000221dc */

/* Boundary evidence: original MIPS .pdata 000221dc..0002221f. Semantic name remains unreviewed. */

int FUN_000221dc(uint param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  
  iVar1 = FUN_00022220(param_1,param_2,param_3);
  return iVar1;
}



/* 00022220 FUN_00022220 */

/* Boundary evidence: original MIPS .pdata 00022220..0002249b. Semantic name remains unreviewed. */

int FUN_00022220(uint param_1,ushort param_2,ushort param_3)

{
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_c;
  
  local_24 = 0;
  local_28 = 0;
  local_40 = 0;
  local_20 = 0;
  if (((param_3 & 4) == 0) || (param_1 < 0x1001)) {
    local_c = param_1;
    if (param_1 < 0x20) {
      local_c = 0x20;
    }
    local_2c = local_c + (param_2 - 1);
    if ((param_3 & 4) != 0) {
      local_2c = local_2c * 2;
    }
    local_3c = FUN_00022684(local_2c,&local_34,(int *)&local_40,(uint)param_3,&local_24,&local_20);
    local_1c = local_3c;
    if (local_3c == 0) {
      local_30 = local_34;
      local_38 = local_40;
      if (((param_3 & 4) != 0) && (0x1000 < (local_40 & 0xfff) + param_1 + param_2 + -1)) {
        local_28 = 0x1000 - (local_40 & 0xfff);
      }
      if (param_2 == 0) {
        trap(0x1c00);
      }
      if ((local_40 + local_28) % (uint)param_2 != 0) {
        if (param_2 == 0) {
          trap(0x1c00);
        }
        local_28 = (local_28 + param_2) - (local_40 + local_28) % (uint)param_2;
      }
      FUN_0002271c(local_28,local_24,local_34,local_40);
      FUN_0002271c((local_2c - param_1) - local_28,local_24,local_30 + local_28 + param_1,
                   local_38 + local_28 + param_1);
      local_1c = FUN_0002249c(param_1,local_24,local_30 + local_28,local_38 + local_28,local_20);
    }
  }
  else {
    local_1c = 10;
  }
  return local_1c;
}



/* 0002249c FUN_0002249c */

/* Boundary evidence: original MIPS .pdata 0002249c..00022627. Semantic name remains unreviewed. */

undefined4 FUN_0002249c(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int *piVar1;
  ushort local_18;
  undefined4 local_c;
  
  piVar1 = FUN_00021974(0x20,1);
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    *piVar1 = param_3;
    piVar1[1] = param_4;
    piVar1[2] = 0;
    piVar1[3] = param_1;
    for (local_18 = 1; ((param_4 & local_18) == 0 && (local_18 < 0x1001)); local_18 = local_18 << 1)
    {
    }
    *(ushort *)(piVar1 + 4) = local_18;
    if (param_2 != 0) {
      *(byte *)((int)piVar1 + 0x12) = *(byte *)((int)piVar1 + 0x12) | 1;
    }
    if (param_4 >> 0xc == param_4 + param_1 >> 0xc) {
      *(byte *)((int)piVar1 + 0x12) = *(byte *)((int)piVar1 + 0x12) | 2;
    }
    if (param_5 != 0) {
      *(byte *)((int)piVar1 + 0x12) = *(byte *)((int)piVar1 + 0x12) | 4;
      piVar1[5] = param_5;
    }
    FUN_00022628((int)piVar1);
    local_c = 0;
  }
  return local_c;
}



/* 00022628 FUN_00022628 */

void FUN_00022628(int param_1)

{
  *(int *)(param_1 + 0x18) = DAT_0016dedc;
  if (DAT_0016dedc != 0) {
    *(int *)(DAT_0016dedc + 0x1c) = param_1 + 0x18;
  }
  DAT_0016dedc = param_1;
  *(int **)(param_1 + 0x1c) = &DAT_0016dedc;
  return;
}



/* 00022684 FUN_00022684 */

/* Boundary evidence: original MIPS .pdata 00022684..0002271b. Semantic name remains unreviewed. */

undefined4
FUN_00022684(uint param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5,
            int *param_6)

{
  int *piVar1;
  undefined4 local_10;
  
  local_10 = 0;
  piVar1 = FUN_00021974(param_1,0);
  *param_2 = (int)piVar1;
  if (*param_2 == 0) {
    local_10 = 7;
  }
  else {
    *param_3 = *param_2;
    *param_6 = *param_3;
    *param_5 = 0;
  }
  return local_10;
}



/* 0002271c FUN_0002271c */

/* Boundary evidence: original MIPS .pdata 0002271c..000227ff. Semantic name remains unreviewed. */

void FUN_0002271c(uint param_1,int param_2,int param_3,uint param_4)

{
  uint local_18;
  
  local_18 = 0;
  if (0x1f < param_1) {
    if ((param_4 & 3) != 0) {
      local_18 = 4 - (param_4 & 3);
    }
    if ((local_18 < param_1) && (0x1f < param_1 - local_18)) {
      FUN_0002249c(param_1 - local_18,param_2,param_3 + local_18,param_4 + local_18,0);
    }
  }
  return;
}



/* 00022800 FUN_00022800 */

/* Boundary evidence: original MIPS .pdata 00022800..000229ab. Semantic name remains unreviewed. */

undefined4 FUN_00022800(uint param_1,ushort param_2,ushort param_3,int *param_4)

{
  int local_8;
  
  *param_4 = 0;
  if (param_1 != 0) {
    for (local_8 = DAT_0016dedc; local_8 != 0; local_8 = *(int *)(local_8 + 0x18)) {
      if (((((param_3 & 2) == 0) || ((*(byte *)(local_8 + 0x12) & 1) != 0)) &&
          (((param_3 & 2) != 0 || ((*(byte *)(local_8 + 0x12) & 1) == 0)))) &&
         (((((param_3 & 4) == 0 || ((*(byte *)(local_8 + 0x12) & 2) != 0)) &&
           (param_2 <= *(ushort *)(local_8 + 0x10))) &&
          ((param_1 <= *(uint *)(local_8 + 0xc) && (*(uint *)(local_8 + 0xc) < param_1 << 1)))))) {
        if (*(int *)(local_8 + 0x18) != 0) {
          *(undefined4 *)(*(int *)(local_8 + 0x18) + 0x1c) = *(undefined4 *)(local_8 + 0x1c);
        }
        **(undefined4 **)(local_8 + 0x1c) = *(undefined4 *)(local_8 + 0x18);
        *param_4 = local_8;
        return 0;
      }
    }
  }
  return 0;
}



/* 000229ac FUN_000229ac */

/* Boundary evidence: original MIPS .pdata 000229ac..00022a03. Semantic name remains unreviewed. */

void FUN_000229ac(undefined4 *param_1)

{
  if ((*(byte *)((int)param_1 + 0x12) & 8) == 0) {
    FUN_00022628((int)param_1);
  }
  else {
    FUN_00021a94(param_1);
  }
  return;
}



/* 00022a04 FUN_00022a04 */

/* Boundary evidence: original MIPS .pdata 00022a04..00022acb. Semantic name remains unreviewed. */

void FUN_00022a04(void)

{
  undefined4 *puVar1;
  
  while (puVar1 = DAT_0016dedc, DAT_0016dedc != (undefined4 *)0x0) {
    if (DAT_0016dedc[6] != 0) {
      *(undefined4 *)(DAT_0016dedc[6] + 0x1c) = DAT_0016dedc[7];
    }
    *(undefined4 *)puVar1[7] = puVar1[6];
    if ((*(byte *)((int)puVar1 + 0x12) & 4) == 0) {
      FUN_00021a94(puVar1);
    }
    else {
      FUN_00021a94((undefined4 *)puVar1[5]);
      FUN_00021a94(puVar1);
    }
  }
  return;
}



/* 00022acc FUN_00022acc */

/* Boundary evidence: original MIPS .pdata 00022acc..00022b23. Semantic name remains unreviewed. */

undefined4 FUN_00022acc(uint *param_1)

{
  FUN_000218c0();
  FUN_00022b24(0,*param_1,*param_1,param_1[1]);
  return 0;
}



/* 00022b24 FUN_00022b24 */

/* Boundary evidence: original MIPS .pdata 00022b24..00022bdb. Semantic name remains unreviewed. */

void FUN_00022b24(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_8;
  
  local_8 = param_2 & 3;
  if (local_8 != 0) {
    local_8 = 4 - local_8;
  }
  *(uint *)(&DAT_0016ded0 + param_1 * 4) = local_8;
  *(undefined4 *)(&DAT_0016ded8 + param_1 * 4) = param_4;
  *(uint *)(&DAT_0016decc + param_1 * 4) = param_2;
  *(undefined4 *)(&DAT_0016ded4 + param_1 * 4) = param_3;
  return;
}



/* 00022bdc FUN_00022bdc */

/* Boundary evidence: original MIPS .pdata 00022bdc..00022bfb. Semantic name remains unreviewed. */

void FUN_00022bdc(void)

{
  FUN_0002196c();
  return;
}



/* 00022bfc FUN_00022bfc */

/* Boundary evidence: original MIPS .pdata 00022bfc..00022ccf. Semantic name remains unreviewed. */

int FUN_00022bfc(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    piVar1 = FUN_00021974(0x28,1);
    *param_1 = (int)piVar1;
    if (*param_1 == 0) {
      local_c = 7;
    }
    else {
      local_c = FUN_00020f38((undefined4 *)(*param_1 + 0x24));
      if (local_c == 0) {
        *(undefined4 *)(*param_1 + 0xc) = param_2;
        local_c = 0;
      }
      else {
        FUN_00021a94((undefined4 *)*param_1);
      }
    }
  }
  return local_c;
}



/* 00022cd0 FUN_00022cd0 */

/* Boundary evidence: original MIPS .pdata 00022cd0..00022da3. Semantic name remains unreviewed. */

void FUN_00022cd0(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((((*(char *)(param_1 + 6) == '\x01') || (*(char *)(param_1 + 6) == '\x03')) ||
        (*(char *)(param_1 + 6) == '\x04')) && (uVar1 = FUN_00023c60(), param_1[7] == uVar1)) {
      param_1[8] = 1;
    }
    else {
      FUN_00022f78((int)param_1);
      FUN_00020fb4((HANDLE)param_1[9]);
      FUN_00021a94(param_1);
    }
  }
  return;
}



/* 00022da4 FUN_00022da4 */

/* Boundary evidence: original MIPS .pdata 00022da4..00022edf. Semantic name remains unreviewed. */

undefined4 FUN_00022da4(int *param_1,int param_2,int param_3,int param_4)

{
  uint local_20;
  int local_1c;
  undefined4 local_18;
  uint local_c;
  
  if (param_1 == (int *)0x0) {
    local_18 = 10;
  }
  else {
    FUN_00021104(&local_20);
    local_c = (uint)*(byte *)(param_1 + 6);
    switch(local_c) {
    case 0:
      *(undefined1 *)(param_1 + 6) = 2;
      break;
    case 1:
      *(undefined1 *)(param_1 + 6) = 3;
      break;
    case 2:
      FUN_00022ee0((int)param_1);
      break;
    case 3:
      FUN_00022ee0((int)param_1);
      break;
    case 4:
      return 0x10;
    }
    FUN_000230cc(param_1,local_20,local_1c,param_2,param_3,param_4);
    FUN_00023264(param_1[3]);
    local_18 = 0;
  }
  return local_18;
}



/* 00022ee0 FUN_00022ee0 */

/* Boundary evidence: original MIPS .pdata 00022ee0..00022f77. Semantic name remains unreviewed. */

void FUN_00022ee0(int param_1)

{
  int *local_8;
  
  for (local_8 = (int *)(&DAT_0016dee8 + *(int *)(param_1 + 0xc) * 0x34);
      (*local_8 != 0 && (*local_8 != param_1)); local_8 = (int *)*local_8) {
  }
  *local_8 = *(int *)*local_8;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* 00022f78 FUN_00022f78 */

/* Boundary evidence: original MIPS .pdata 00022f78..0002305b. Semantic name remains unreviewed. */

void FUN_00022f78(int param_1)

{
  uint auStack_18 [2];
  uint local_10;
  
  if (param_1 != 0) {
    FUN_00021104(auStack_18);
    local_10 = (uint)*(byte *)(param_1 + 0x18);
    switch(local_10) {
    case 0:
      break;
    case 1:
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_0002305c(param_1);
      break;
    case 2:
      FUN_00022ee0(param_1);
      *(undefined1 *)(param_1 + 0x18) = 0;
      break;
    case 3:
      FUN_00022ee0(param_1);
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_0002305c(param_1);
    }
  }
  return;
}



/* 0002305c FUN_0002305c */

/* Boundary evidence: original MIPS .pdata 0002305c..000230cb. Semantic name remains unreviewed. */

void FUN_0002305c(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00023c60();
  if (*(uint *)(param_1 + 0x1c) != uVar1) {
    while (*(char *)(param_1 + 0x18) != '\0') {
      FUN_00020fe4(*(HANDLE *)(param_1 + 0x24),0);
    }
  }
  return;
}



/* 000230cc FUN_000230cc */

/* Boundary evidence: original MIPS .pdata 000230cc..00023263. Semantic name remains unreviewed. */

void FUN_000230cc(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int local_res4;
  int local_res8;
  int local_resc;
  int *local_10;
  
  param_1[4] = param_5;
  param_1[5] = param_6;
  local_res8 = param_3 + param_4 * 1000;
  local_res4 = param_2 + local_res8 / 1000000;
  local_res8 = local_res8 % 1000000;
  local_resc = param_4;
  FUN_0002097c(param_1 + 1,&local_res4,8);
  for (local_10 = (int *)(&DAT_0016dee8 + param_1[3] * 0x34); *local_10 != 0;
      local_10 = (int *)*local_10) {
    if ((*(int *)(*local_10 + 4) < param_1[1]) ||
       ((param_1[1] == *(int *)(*local_10 + 4) && (*(int *)(*local_10 + 8) < param_1[2])))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
  }
  *param_1 = *local_10;
  *local_10 = (int)param_1;
  return;
}



/* 00023264 FUN_00023264 */

/* Boundary evidence: original MIPS .pdata 00023264..000232e3. Semantic name remains unreviewed. */

void FUN_00023264(int param_1)

{
  if (*(int *)(&DAT_0016dee8 + param_1 * 0x34) != 0) {
    FUN_000210b8(*(undefined4 *)(&DAT_0016dee4 + param_1 * 0x34));
  }
  return;
}



/* 000232e4 FUN_000232e4 */

/* Boundary evidence: original MIPS .pdata 000232e4..000233af. Semantic name remains unreviewed. */

int FUN_000232e4(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (0 < local_14) {
      return 0;
    }
    iVar1 = FUN_000233b0(local_14);
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  while (local_14 = local_14 + -1, -1 < local_14) {
    FUN_00023820(local_14);
  }
  return iVar1;
}



/* 000233b0 FUN_000233b0 */

/* Boundary evidence: original MIPS .pdata 000233b0..000234eb. Semantic name remains unreviewed. */

int FUN_000233b0(int param_1)

{
  int iVar1;
  int local_18;
  
  iVar1 = param_1 * 0x34;
  FUN_000209c0(&DAT_0016dee4 + iVar1,0,0x34);
  local_18 = FUN_00020f38((undefined4 *)(&DAT_0016dee4 + iVar1));
  if (local_18 == 0) {
    (&DAT_0016df14)[iVar1] = (&DAT_0016df14)[iVar1] | 1;
    (&DAT_0016df14)[iVar1] = (&DAT_0016df14)[iVar1] | 4;
    local_18 = FUN_00020b64(0x234ec,param_1,param_1,(&PTR_s_uw_Controller_0002e248)[param_1],
                            (undefined4 *)(iVar1 + 0x16df10));
    if (local_18 == 0) {
      (&DAT_0016df14)[iVar1] = (&DAT_0016df14)[iVar1] | 2;
      return 0;
    }
  }
  FUN_00023820(param_1);
  return local_18;
}



/* 000234ec FUN_000234ec */

/* Boundary evidence: original MIPS .pdata 000234ec..0002381f. Semantic name remains unreviewed. */

void FUN_000234ec(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_30;
  int local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  DWORD local_20;
  code *local_1c;
  DWORD local_18;
  uint local_14;
  uint local_10;
  
  local_28 = (undefined4 *)(&DAT_0016dee4 + param_1 * 0x34);
  while ((*(byte *)(local_28 + 0xc) & 4) != 0) {
    FUN_00021104(&local_30);
    local_24 = (undefined4 *)local_28[1];
    if (local_24 == (undefined4 *)0x0) {
      local_20 = 0;
    }
    else {
      local_20 = (*(int *)((int)local_24 + 4) - local_30) * 1000 +
                 (*(int *)((int)local_24 + 8) - local_2c) / 1000;
      if (*(int *)((int)local_24 + 0xc) != 0) {
        local_18 = local_20;
        if ((int)local_20 < 2) {
          local_18 = 2;
        }
        local_20 = local_18;
      }
    }
    if ((0 < (int)local_20) || (local_24 == (undefined4 *)0x0)) {
      FUN_00020fe4((HANDLE)*local_28,local_20);
    }
    *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) & 0xef;
    local_24 = (undefined4 *)local_28[1];
    if (local_24 != (undefined4 *)0x0) {
      FUN_00021104(&local_30);
      local_14 = (uint)((int)((local_24[1] - local_30) * 1000 + (local_24[2] - local_2c) / 1000) < 1
                       );
      if (local_14 != 0) {
        local_1c = (code *)local_24[4];
        uVar2 = local_24[5];
        FUN_00022ee0((int)local_24);
        *(undefined1 *)(local_24 + 6) = 1;
        uVar1 = FUN_00023c60();
        local_24[7] = uVar1;
        (*local_1c)(uVar2);
        if (local_24[8] == 0) {
          local_10 = (uint)*(byte *)(local_24 + 6);
          if (local_10 == 1) {
            *(undefined1 *)(local_24 + 6) = 0;
          }
          else if (local_10 == 3) {
            *(undefined1 *)(local_24 + 6) = 2;
          }
          else if (local_10 == 4) {
            *(undefined1 *)(local_24 + 6) = 0;
            FUN_000210b8(local_24[9]);
          }
        }
        else {
          if (*(char *)(local_24 + 6) == '\x03') {
            FUN_00022ee0((int)local_24);
          }
          FUN_00020fb4((HANDLE)local_24[9]);
          FUN_00021a94(local_24);
        }
      }
    }
  }
  *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) | 8;
  return;
}



/* 00023820 FUN_00023820 */

/* Boundary evidence: original MIPS .pdata 00023820..00023923. Semantic name remains unreviewed. */

void FUN_00023820(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x34;
  if (((&DAT_0016df14)[iVar1] & 2) != 0) {
    if (*(int *)(&DAT_0016dee8 + iVar1) != 0) {
      *(undefined4 *)(&DAT_0016dee8 + iVar1) = 0;
    }
    (&DAT_0016df14)[iVar1] = (&DAT_0016df14)[iVar1] & 0xfb;
    FUN_000210b8(*(undefined4 *)(&DAT_0016dee4 + iVar1));
    while (((&DAT_0016df14)[iVar1] & 8) == 0) {
      FUN_00020ef8(0x37);
    }
  }
  if (((&DAT_0016df14)[iVar1] & 1) != 0) {
    (&DAT_0016df14)[iVar1] = (&DAT_0016df14)[iVar1] & 0xfe;
    FUN_00020fb4(*(HANDLE *)(&DAT_0016dee4 + iVar1));
  }
  return;
}



/* 00023924 FUN_00023924 */

/* Boundary evidence: original MIPS .pdata 00023924..00023977. Semantic name remains unreviewed. */

void FUN_00023924(void)

{
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
    FUN_00023820(local_10);
  }
  return;
}



/* 00023978 FUN_00023978 */

/* Boundary evidence: original MIPS .pdata 00023978..0002399f. Semantic name remains unreviewed. */

void FUN_00023978(void)

{
  FUN_00023a84(DAT_0016df18);
  return;
}



/* 000239a0 FUN_000239a0 */

/* Boundary evidence: original MIPS .pdata 000239a0..000239c7. Semantic name remains unreviewed. */

void FUN_000239a0(void)

{
  FUN_00023abc(DAT_0016df18);
  return;
}



/* 000239c8 FUN_000239c8 */

/* Boundary evidence: original MIPS .pdata 000239c8..000239fb. Semantic name remains unreviewed. */

undefined4 FUN_000239c8(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00020d74(&DAT_0016df1c);
  return uVar1;
}



/* 000239fc FUN_000239fc */

/* Boundary evidence: original MIPS .pdata 000239fc..00023a33. Semantic name remains unreviewed. */

void FUN_000239fc(void)

{
  HANDLE pvVar1;
  
  pvVar1 = DAT_0016df1c;
  DAT_0016df1c = (HANDLE)0x0;
  FUN_00020df0(pvVar1);
  return;
}



/* 00023a34 FUN_00023a34 */

/* Boundary evidence: original MIPS .pdata 00023a34..00023a5b. Semantic name remains unreviewed. */

void FUN_00023a34(void)

{
  FUN_00020e34(DAT_0016df1c);
  return;
}



/* 00023a5c FUN_00023a5c */

/* Boundary evidence: original MIPS .pdata 00023a5c..00023a83. Semantic name remains unreviewed. */

void FUN_00023a5c(void)

{
  FUN_00020e84(DAT_0016df1c);
  return;
}



/* 00023a84 FUN_00023a84 */

/* Boundary evidence: original MIPS .pdata 00023a84..00023abb. Semantic name remains unreviewed. */

void FUN_00023a84(HANDLE param_1)

{
  FUN_00023a5c();
  FUN_00020e34(param_1);
  FUN_00023a34();
  return;
}



/* 00023abc FUN_00023abc */

/* Boundary evidence: original MIPS .pdata 00023abc..00023ae3. Semantic name remains unreviewed. */

void FUN_00023abc(HANDLE param_1)

{
  FUN_00020e84(param_1);
  return;
}



/* 00023ae4 FUN_00023ae4 */

/* Boundary evidence: original MIPS .pdata 00023ae4..00023b77. Semantic name remains unreviewed. */

int FUN_00023ae4(void)

{
  int local_10;
  
  DAT_0002e244 = 4;
  FUN_000209c0(&DAT_0016dee0,0,4);
  local_10 = FUN_000232e4();
  if ((local_10 == 0) && (local_10 = FUN_00020d74(&DAT_0016df18), local_10 != 0)) {
    FUN_00023924();
  }
  return local_10;
}



/* 00023b78 FUN_00023b78 */

/* Boundary evidence: original MIPS .pdata 00023b78..00023bb7. Semantic name remains unreviewed. */

void FUN_00023b78(void)

{
  FUN_00023924();
  FUN_00020df0(DAT_0016df18);
  DAT_0016df18 = (HANDLE)0x0;
  DAT_0016dee0 = 0;
  return;
}



/* 00023bb8 FUN_00023bb8 */

/* Boundary evidence: original MIPS .pdata 00023bb8..00023bfb. Semantic name remains unreviewed. */

void FUN_00023bb8(void)

{
  if (DAT_0016dee0 == 0) {
    FUN_000259b8();
  }
  DAT_0016dee0 = DAT_0016dee0 + 1;
  return;
}



/* 00023bfc FUN_00023bfc */

/* Boundary evidence: original MIPS .pdata 00023bfc..00023c3f. Semantic name remains unreviewed. */

void FUN_00023bfc(void)

{
  DAT_0016dee0 = DAT_0016dee0 + -1;
  if (DAT_0016dee0 == 0) {
    FUN_000259c0();
  }
  return;
}



/* 00023c40 FUN_00023c40 */

/* Boundary evidence: original MIPS .pdata 00023c40..00023c5f. Semantic name remains unreviewed. */

undefined4 FUN_00023c40(void)

{
  return DAT_0016dee0;
}



/* 00023c60 FUN_00023c60 */

/* Boundary evidence: original MIPS .pdata 00023c60..00023cd7. Semantic name remains unreviewed. */

uint FUN_00023c60(void)

{
  int iVar1;
  uint local_10;
  
  if ((DAT_0002e244 == 0) || (2 < DAT_0002e244)) {
    iVar1 = FUN_00020d48();
    local_10 = iVar1 + 4;
  }
  else {
    local_10 = DAT_0002e244;
  }
  return local_10;
}



/* 00023cd8 FUN_00023cd8 */

/* Boundary evidence: original MIPS .pdata 00023cd8..00023d0f. Semantic name remains unreviewed. */

undefined4 FUN_00023cd8(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0002e244;
  DAT_0002e244 = param_1;
  return uVar1;
}



/* 00023d10 FUN_00023d10 */

/* Boundary evidence: original MIPS .pdata 00023d10..00023dcf. Semantic name remains unreviewed. */

int FUN_00023d10(undefined4 *param_1)

{
  int *piVar1;
  int local_18;
  
  FUN_00023a34();
  piVar1 = FUN_00021974(0xc,1);
  if (piVar1 == (int *)0x0) {
    local_18 = 7;
  }
  else {
    local_18 = FUN_00020d74(piVar1 + 2);
    if (local_18 == 0) {
      *param_1 = piVar1;
    }
  }
  if ((local_18 != 0) && (piVar1 != (int *)0x0)) {
    FUN_00021a94(piVar1);
  }
  FUN_00023a5c();
  return local_18;
}



/* 00023dd0 FUN_00023dd0 */

/* Boundary evidence: original MIPS .pdata 00023dd0..00023e17. Semantic name remains unreviewed. */

void FUN_00023dd0(undefined4 *param_1)

{
  FUN_00023a34();
  FUN_00020df0((HANDLE)param_1[2]);
  FUN_00021a94(param_1);
  FUN_00023a5c();
  return;
}



/* 00023e18 FUN_00023e18 */

/* Boundary evidence: original MIPS .pdata 00023e18..00023e93. Semantic name remains unreviewed. */

void FUN_00023e18(uint *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00023c60();
  if ((param_1[1] == 0) || (*param_1 != uVar1)) {
    FUN_00020e34((HANDLE)param_1[2]);
  }
  *param_1 = uVar1;
  param_1[1] = param_1[1] + 1;
  return;
}



/* 00023e94 FUN_00023e94 */

/* Boundary evidence: original MIPS .pdata 00023e94..00023ee3. Semantic name remains unreviewed. */

void FUN_00023e94(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (*(int *)(param_1 + 4) == 0) {
    FUN_00020e84(*(HANDLE *)(param_1 + 8));
  }
  return;
}



/* 00023ee4 FUN_00023ee4 */

/* Boundary evidence: original MIPS .pdata 00023ee4..00023f1b. Semantic name remains unreviewed. */

uint FUN_00023ee4(void)

{
  uint local_18;
  uint local_14;
  
  FUN_00021104(&local_18);
  return local_18 ^ local_14;
}



/* 00023f1c FUN_00023f1c */

/* Boundary evidence: original MIPS .pdata 00023f1c..00023f4f. Semantic name remains unreviewed. */

ushort FUN_00023f1c(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}



/* 00023f50 FUN_00023f50 */

/* Boundary evidence: original MIPS .pdata 00023f50..00023fa3. Semantic name remains unreviewed. */

uint FUN_00023f50(uint param_1)

{
  return param_1 >> 0x18 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



/* 00023fa4 FUN_00023fa4 */

/* Boundary evidence: original MIPS .pdata 00023fa4..00024023. Semantic name remains unreviewed. */

int * FUN_00023fa4(char *param_1)

{
  size_t sVar1;
  undefined4 local_10;
  
  sVar1 = FUN_00020a04(param_1);
  local_10 = FUN_00021974(sVar1 + 1,0);
  if (local_10 == (int *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    FUN_0002097c(local_10,param_1,sVar1 + 1);
  }
  return local_10;
}



/* 00024024 FUN_00024024 */

/* Boundary evidence: original MIPS .pdata 00024024..0002413b. Semantic name remains unreviewed. */

char * FUN_00024024(char *param_1,char *param_2)

{
  char *local_res0;
  char *local_10;
  char *local_c;
  
  local_res0 = param_1;
  do {
    if (*local_res0 == '\0') {
      return (char *)0x0;
    }
    local_10 = local_res0;
    local_c = param_2;
    if (*local_res0 == *param_2) {
      do {
        local_c = local_c + 1;
        local_10 = local_10 + 1;
        if ((*local_10 == '\0') || (*local_c == '\0')) break;
      } while (*local_10 == *local_c);
      if (*local_c == '\0') {
        return local_res0;
      }
      if (*local_10 == '\0') {
        return (char *)0x0;
      }
    }
    local_res0 = local_res0 + 1;
  } while( true );
}



/* 0002413c FUN_0002413c */

/* Boundary evidence: original MIPS .pdata 0002413c..00024343. Semantic name remains unreviewed. */

int FUN_0002413c(int param_1,byte param_2,uint param_3,int param_4,uint param_5)

{
  bool bVar1;
  uint uVar2;
  uint local_res8;
  int local_resc;
  int local_40;
  undefined1 auStack_39 [33];
  uint local_18;
  uint local_14;
  int local_10;
  
  local_14 = DAT_0002e28c;
  local_40 = 0;
  local_18 = 0;
  if (param_2 < 2) {
    FUN_000279ec(DAT_0002e28c);
    local_10 = 0;
  }
  else {
    while (local_res8 = param_3, param_5 != 0) {
      uVar2 = param_5 % (uint)param_2;
      if (param_2 == 0) {
        trap(0x1c00);
      }
      param_5 = param_5 / param_2;
      if (param_2 == 0) {
        trap(0x1c00);
      }
      if ((byte)uVar2 < 10) {
        auStack_39[local_18 + 1] = (char)((uVar2 + 0x30) * 0x1000000 >> 0x18);
      }
      else {
        auStack_39[local_18 + 1] = (char)((uVar2 + 0x37) * 0x1000000 >> 0x18);
      }
      local_18 = local_18 + 1;
    }
    while (bVar1 = local_18 < local_res8, local_res8 = local_res8 - 1, local_resc = param_4, bVar1)
    {
      *(undefined1 *)(param_1 + local_40) = 0x30;
      local_40 = local_40 + 1;
    }
    while ((local_18 != 0 && (local_resc != 0))) {
      *(undefined1 *)(param_1 + local_40) = auStack_39[local_18];
      local_40 = local_40 + 1;
      local_18 = local_18 - 1;
      local_resc = local_resc + -1;
    }
    *(undefined1 *)(param_1 + local_40) = 0;
    FUN_000279ec(local_14);
    local_10 = param_1;
  }
  return local_10;
}



/* 00024344 FUN_00024344 */

/* Boundary evidence: original MIPS .pdata 00024344..00024417. Semantic name remains unreviewed. */

uint FUN_00024344(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  size_t sVar2;
  char *local_res0;
  char *local_res4;
  uint local_10;
  
  local_10 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  while( true ) {
    if (param_3 <= local_10) {
      if (param_3 != 0) {
        local_res0[-1] = '\0';
      }
      sVar2 = FUN_00020a04(local_res4);
      return param_3 + sVar2;
    }
    *local_res0 = *local_res4;
    cVar1 = *local_res0;
    local_res0 = local_res0 + 1;
    local_res4 = local_res4 + 1;
    if (cVar1 == '\0') break;
    local_10 = local_10 + 1;
  }
  return local_10;
}



/* 00024418 FUN_00024418 */

/* Boundary evidence: original MIPS .pdata 00024418..00024527. Semantic name remains unreviewed. */

int FUN_00024418(char *param_1,byte param_2,undefined4 *param_3)

{
  int local_18;
  char *local_14;
  uint local_10;
  int local_c;
  
  local_18 = 0;
  local_10 = FUN_00024528(*param_1,(uint)param_2);
  local_14 = param_1;
  while ((*local_14 != '\0' && (local_10 != 0xffffffff))) {
    local_18 = local_18 * (uint)param_2 + local_10;
    local_14 = local_14 + 1;
    local_10 = FUN_00024528(*local_14,(uint)param_2);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_14;
  }
  if (local_14 == param_1) {
    local_c = -1;
  }
  else {
    local_c = local_18;
  }
  return local_c;
}



/* 00024528 FUN_00024528 */

/* Boundary evidence: original MIPS .pdata 00024528..0002461b. Semantic name remains unreviewed. */

uint FUN_00024528(char param_1,uint param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0xffffffff;
  if ((param_1 < '0') || ('9' < param_1)) {
    if ((param_1 < 'A') || ('F' < param_1)) {
      if (('`' < param_1) && (param_1 < 'g')) {
        local_8 = (int)param_1 - 0x57;
      }
    }
    else {
      local_8 = (int)param_1 - 0x37;
    }
  }
  else {
    local_8 = (int)param_1 - 0x30;
  }
  if (local_8 < param_2) {
    local_4 = local_8;
  }
  else {
    local_4 = 0xffffffff;
  }
  return local_4;
}



/* 0002461c FUN_0002461c */

/* Boundary evidence: original MIPS .pdata 0002461c..0002469b. Semantic name remains unreviewed. */

undefined4 FUN_0002461c(char param_1)

{
  undefined4 local_8;
  
  if ((((param_1 == ' ') || (param_1 == '\t')) || (param_1 == '\r')) || (param_1 == '\n')) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



/* 0002469c FUN_0002469c */

/* Boundary evidence: original MIPS .pdata 0002469c..00024aab. Semantic name remains unreviewed. */

char * FUN_0002469c(undefined4 param_1)

{
  char *local_10;
  
  switch(param_1) {
  case 0:
    local_10 = "NORMAL COMPLETION";
    break;
  case 1:
    local_10 = "OPERATION NOT STARTED";
    break;
  case 2:
    local_10 = "OPERATION IN PROGRESS";
    break;
  case 3:
    local_10 = "OPERATION NOT PERMITTED";
    break;
  case 4:
    local_10 = "NO SUCH ENTRY";
    break;
  case 5:
    local_10 = "INPUT/OUTPUT ERROR";
    break;
  case 6:
    local_10 = "DEVICE NOT CONFIGURED";
    break;
  case 7:
    local_10 = "FAILED ALLOCATING MEMORY";
    break;
  case 8:
    local_10 = "RESOURCE IS BUSY";
    break;
  case 9:
    local_10 = "NO SUCH DEVICE";
    break;
  case 10:
    local_10 = "INVALID ARGUMENT";
    break;
  case 0xb:
    local_10 = "OPERATION NOT SUPPORTED";
    break;
  case 0xc:
    local_10 = "OPERATION TIMED OUT";
    break;
  case 0xd:
    local_10 = "DEVICE IS SUSPENDED";
    break;
  case 0xe:
    local_10 = "GENERAL-PURPOSE ERROR";
    break;
  case 0xf:
    local_10 = "LOGICAL TEST FAILURE";
    break;
  case 0x10:
    local_10 = "INCORRECT STATE";
    break;
  case 0x11:
    local_10 = "PIPE IS STALLED";
    break;
  case 0x12:
    local_10 = "INVALID PARAMETER";
    break;
  case 0x13:
    local_10 = "OPERATION ABORTED";
    break;
  case 0x14:
    local_10 = "SHORT TRANSFER";
    break;
  case 0x15:
    local_10 = "WOULD BLOCK";
    break;
  case 0x16:
    local_10 = "ALREADY";
    break;
  case 0x17:
    local_10 = "EVALUATION TIME EXPIRED";
    break;
  default:
    local_10 = "INVALID RESULT_T VALUE";
    break;
  case 0x29:
    local_10 = "DEST ADDR REQUIRED";
    break;
  case 0x2a:
    local_10 = "CAN\'T ASSIGN REQUESTED ADDRESS";
    break;
  case 0x2b:
    local_10 = "MESSAGE TOO LONG";
    break;
  case 0x2c:
    local_10 = "NET DOWN";
    break;
  case 0x2d:
    local_10 = "NET UNREACHABLE";
    break;
  case 0x2e:
    local_10 = "NET RESET";
    break;
  case 0x2f:
    local_10 = "CONNECTION ABORTED";
    break;
  case 0x30:
    local_10 = "CONNECTION RESET";
    break;
  case 0x31:
    local_10 = "ALREADY CONNECTED";
    break;
  case 0x32:
    local_10 = "NOT CONNECTED";
    break;
  case 0x33:
    local_10 = "CONNECTION REFUSED";
    break;
  case 0x34:
    local_10 = "HOST DOWN";
    break;
  case 0x35:
    local_10 = "HOST UNREACHABLE";
    break;
  case 0x36:
    local_10 = "NO LINK";
    break;
  case 0x37:
    local_10 = "PROTOCOL";
    break;
  case 0x38:
    local_10 = "NO PROTOCOL OPTION";
    break;
  case 0x39:
    local_10 = "OPERATION INTERRUPTED";
  }
  return local_10;
}



/* 00024aac FUN_00024aac */

/* Boundary evidence: original MIPS .pdata 00024aac..00024beb. Semantic name remains unreviewed. */

void FUN_00024aac(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined2 local_18;
  undefined4 local_14;
  undefined4 local_c;
  
  local_18 = 0;
  for (local_14 = 0; local_14 < param_3; local_14 = local_14 + *(int *)(param_2 + uVar1 * 0xc + 8))
  {
    if (param_3 - local_14 < *(uint *)(param_2 + (uint)local_18 * 0xc + 8)) {
      local_c = param_3 - local_14;
    }
    else {
      local_c = *(size_t *)(param_2 + (uint)local_18 * 0xc + 8);
    }
    FUN_0002097c(*(void **)(param_2 + (uint)local_18 * 0xc),(void *)(param_1 + local_14),local_c);
    uVar1 = (uint)local_18;
    local_18 = local_18 + 1;
  }
  return;
}



/* 00024bec FUN_00024bec */

/* Boundary evidence: original MIPS .pdata 00024bec..00024d2b. Semantic name remains unreviewed. */

void FUN_00024bec(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0;
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + *(int *)(param_1 + uVar1 * 0xc + 8))
  {
    if (param_3 - local_10 < *(uint *)(param_1 + (uint)local_14 * 0xc + 8)) {
      local_c = param_3 - local_10;
    }
    else {
      local_c = *(size_t *)(param_1 + (uint)local_14 * 0xc + 8);
    }
    FUN_0002097c((void *)(param_2 + local_10),*(void **)(param_1 + (uint)local_14 * 0xc),local_c);
    uVar1 = (uint)local_14;
    local_14 = local_14 + 1;
  }
  return;
}



/* 00024d2c FUN_00024d2c */

/* Boundary evidence: original MIPS .pdata 00024d2c..00024da3. Semantic name remains unreviewed. */

int FUN_00024d2c(int param_1,int *param_2)

{
  int *local_8;
  
  for (local_8 = param_2; (*local_8 != -1 && (*local_8 != param_1)); local_8 = local_8 + 2) {
  }
  return local_8[1];
}



/* 00024da4 FUN_00024da4 */

/* Boundary evidence: original MIPS .pdata 00024da4..00024e3f. Semantic name remains unreviewed. */

int FUN_00024da4(uint param_1)

{
  return (uint)(byte)(&DAT_0002ce40)[param_1 & 0xff] +
         (uint)(byte)(&DAT_0002ce40)[param_1 >> 8 & 0xff] +
         (uint)(byte)(&DAT_0002ce40)[param_1 >> 0x10 & 0xff] +
         (uint)(byte)(&DAT_0002ce40)[param_1 >> 0x18];
}



/* 00024e40 FUN_00024e40 */

/* Boundary evidence: original MIPS .pdata 00024e40..00024f07. Semantic name remains unreviewed. */

int FUN_00024e40(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  int local_120;
  char acStack_118 [126];
  undefined1 local_9a;
  undefined1 auStack_98 [128];
  uint local_18;
  
  local_18 = DAT_0002e28c;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_120 = _vsnprintf_s(acStack_118,0x80,0xffffffff,param_1,(va_list)&local_res4);
  if (local_120 == -1) {
    local_9a = 10;
    local_120 = 0x7f;
  }
  FUN_00024f08(acStack_118,(int)auStack_98);
  NKDbgPrintfW(&DAT_0002834c,auStack_98);
  FUN_000279ec(local_18);
  return local_120;
}



/* 00024f08 FUN_00024f08 */

/* Boundary evidence: original MIPS .pdata 00024f08..00025013. Semantic name remains unreviewed. */

void FUN_00024f08(char *param_1,int param_2)

{
  char *local_res0;
  int local_8;
  
  local_res0 = param_1;
  for (local_8 = 0; (*local_res0 != '\0' && (local_8 < 0x7f)); local_8 = local_8 + 1) {
    if ((*local_res0 == '\n') && (local_8 < 0x7e)) {
      *(undefined1 *)(param_2 + local_8) = 0xd;
      local_8 = local_8 + 1;
    }
    *(char *)(param_2 + local_8) = *local_res0;
    local_res0 = local_res0 + 1;
  }
  if (local_8 == 0x7f) {
    *(undefined1 *)(param_2 + 0x7e) = 10;
    *(undefined1 *)(param_2 + 0x7d) = 0xd;
  }
  *(undefined1 *)(param_2 + local_8) = 0;
  return;
}



/* 00025014 FUN_00025014 */

/* Boundary evidence: original MIPS .pdata 00025014..00025073. Semantic name remains unreviewed. */

undefined4 FUN_00025014(void)

{
  undefined4 local_10;
  
  DAT_0016df20 = HeapCreate(1,0x20000,0x40000);
  if (DAT_0016df20 == (HANDLE)0x0) {
    local_10 = 7;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* 00025074 FUN_00025074 */

/* Boundary evidence: original MIPS .pdata 00025074..000250e7. Semantic name remains unreviewed. */

undefined4 FUN_00025074(void)

{
  BOOL BVar1;
  undefined4 local_10;
  
  if (DAT_0016df20 == (HANDLE)0x0) {
    local_10 = 0;
  }
  else {
    BVar1 = HeapDestroy(DAT_0016df20);
    if (BVar1 == 0) {
      local_10 = 0xe;
    }
    else {
      DAT_0016df20 = (HANDLE)0x0;
      local_10 = 0;
    }
  }
  return local_10;
}



/* 000250e8 FUN_000250e8 */

/* WARNING: Removing unreachable block (ram,0x00025140) */
/* Boundary evidence: original MIPS .pdata 000250e8..0002517b. Semantic name remains unreviewed. */

LPVOID FUN_000250e8(SIZE_T param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = HeapAlloc(DAT_0016df20,8,param_1);
  return pvVar1;
}



/* 0002517c FUN_0002517c */

/* Boundary evidence: original MIPS .pdata 0002517c..000251af. Semantic name remains unreviewed. */

void FUN_0002517c(LPVOID param_1)

{
  HeapFree(DAT_0016df20,1,param_1);
  return;
}



/* 000251b0 FUN_000251b0 */

/* Boundary evidence: original MIPS .pdata 000251b0..0002525f. Semantic name remains unreviewed. */

undefined4
FUN_000251b0(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  *param_5 = 0;
  *param_3 = 0;
  *param_2 = 0;
  iVar1 = AllocPhysMem(param_1,0x204,0x20,0,local_18);
  *param_2 = iVar1;
  if (*param_2 == 0) {
    local_10 = 7;
  }
  else {
    *param_3 = local_18[0];
    *param_5 = *param_2;
    local_10 = 0;
  }
  return local_10;
}



/* 00025260 FUN_00025260 */

/* Boundary evidence: original MIPS .pdata 00025260..00025287. Semantic name remains unreviewed. */

void FUN_00025260(undefined4 param_1)

{
  FreePhysMem(param_1);
  return;
}



/* 000252a8 FUN_000252a8 */

/* WARNING: Removing unreachable block (ram,0x000253bc) */
/* Boundary evidence: original MIPS .pdata 000252a8..00025403. Semantic name remains unreviewed. */

int FUN_000252a8(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int local_18;
  int local_c;
  
  bVar1 = false;
  FUN_00024e40("USBware version 3.5.14.82\n",param_2,param_3,param_4);
  if (param_1 == (uint *)0x0) {
    local_c = 10;
  }
  else {
    DAT_0016df24 = param_1[2];
    local_c = FUN_00025a74(param_1);
    if (local_c == 0) {
      local_18 = FUN_00025d98();
      if ((local_18 == 0) && (local_18 = FUN_00026014(), local_18 == 0)) {
        bVar1 = true;
        local_18 = FUN_0002595c();
        if (local_18 == 0) {
          FUN_00023a5c();
          return 0;
        }
      }
      if (bVar1) {
        FUN_000260c0();
      }
      FUN_00025ca8();
      FUN_00025bd8();
      local_c = local_18;
    }
  }
  return local_c;
}



/* 00025404 FUN_00025404 */

/* Boundary evidence: original MIPS .pdata 00025404..0002545f. Semantic name remains unreviewed. */

void FUN_00025404(void)

{
  FUN_00023a34();
  DAT_0016df28 = 1;
  FUN_00025978();
  FUN_000260c0();
  FUN_00025ca8();
  FUN_00025bd8();
  FUN_000218b8();
  DAT_0016df28 = 0;
  return;
}



/* 00025460 FUN_00025460 */

/* Boundary evidence: original MIPS .pdata 00025460..00025493. Semantic name remains unreviewed. */

undefined4 FUN_00025460(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00026ccc(param_1);
  return *puVar1;
}



/* 00025494 FUN_00025494 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00025494..000256d3. Semantic name remains unreviewed. */

int FUN_00025494(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int local_20;
  
  piVar1 = FUN_00021974(0xc,0);
  if (piVar1 == (int *)0x0) {
    return 7;
  }
  *piVar1 = param_1;
  piVar1[1] = param_2;
  piVar1[2] = param_4;
  piVar2 = FUN_0002720c(0,0,piVar1,0);
  if (piVar2 == (int *)0x0) {
    local_20 = 7;
    goto LAB_00025694;
  }
  local_20 = 10;
  uVar3 = param_2 >> 0xc;
  if (DAT_0016df24 == 1) {
    if ((uVar3 & 0xf) != 1) goto joined_r0x000255ac;
  }
  else if (((DAT_0016df24 == 2) || ((DAT_0016df24 == 3 && ((uVar3 & 0xf) != 1)))) &&
          ((uVar3 & 0xf) != 2)) {
joined_r0x000255ac:
    if ((uVar3 & 0xf) != 3) goto LAB_00025694;
  }
  local_20 = FUN_00026f6c(piVar2);
  if (local_20 == 0) {
    *param_3 = piVar2;
    return 0;
  }
LAB_00025694:
  if (piVar2 != (int *)0x0) {
    FUN_00027094(piVar2);
  }
  FUN_00021a94(piVar1);
  return local_20;
}



/* 000256d4 FUN_000256d4 */

/* Boundary evidence: original MIPS .pdata 000256d4..0002572f. Semantic name remains unreviewed. */

int FUN_000256d4(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_00023978();
  iVar1 = FUN_00025494(param_1,param_2,param_3,0);
  FUN_000239a0();
  return iVar1;
}



/* 00025730 FUN_00025730 */

/* Boundary evidence: original MIPS .pdata 00025730..00025777. Semantic name remains unreviewed. */

undefined4 FUN_00025730(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00023978();
  uVar1 = FUN_000268d4(param_1);
  FUN_000239a0();
  return uVar1;
}



/* 00025778 FUN_00025778 */

/* Boundary evidence: original MIPS .pdata 00025778..000257bf. Semantic name remains unreviewed. */

undefined4 FUN_00025778(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00023978();
  uVar1 = FUN_00026948(param_1);
  FUN_000239a0();
  return uVar1;
}



/* 000257c0 FUN_000257c0 */

/* Boundary evidence: original MIPS .pdata 000257c0..00025817. Semantic name remains unreviewed. */

undefined4 FUN_000257c0(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00026ccc((int)param_1);
  FUN_00027094(param_1);
  FUN_00021a94(puVar1);
  return 0;
}



/* 00025818 FUN_00025818 */

/* Boundary evidence: original MIPS .pdata 00025818..0002585f. Semantic name remains unreviewed. */

undefined4 FUN_00025818(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00023978();
  uVar1 = FUN_000257c0(param_1);
  FUN_000239a0();
  return uVar1;
}



/* 00025860 FUN_00025860 */

/* Boundary evidence: original MIPS .pdata 00025860..0002587f. Semantic name remains unreviewed. */

undefined ** FUN_00025860(void)

{
  return &PTR_DAT_0002e258;
}



/* 000258a4 FUN_000258a4 */

/* Boundary evidence: original MIPS .pdata 000258a4..000258eb. Semantic name remains unreviewed. */

undefined4 FUN_000258a4(void)

{
  return 0;
}



/* 000258ec FUN_000258ec */

/* Boundary evidence: original MIPS .pdata 000258ec..00025917. Semantic name remains unreviewed. */

undefined4 FUN_000258ec(void)

{
  return 0xb;
}



/* 00025918 FUN_00025918 */

/* Boundary evidence: original MIPS .pdata 00025918..00025937. Semantic name remains unreviewed. */

undefined4 FUN_00025918(void)

{
  return 0xb;
}



/* 00025938 FUN_00025938 */

/* Boundary evidence: original MIPS .pdata 00025938..0002595b. Semantic name remains unreviewed. */

undefined4 FUN_00025938(void)

{
  return 0;
}



/* 0002595c FUN_0002595c */

/* Boundary evidence: original MIPS .pdata 0002595c..00025977. Semantic name remains unreviewed. */

undefined4 FUN_0002595c(void)

{
  return 0;
}



/* 00025978 FUN_00025978 */

void FUN_00025978(void)

{
  return;
}



/* 00025980 FUN_00025980 */

/* Boundary evidence: original MIPS .pdata 00025980..000259a7. Semantic name remains unreviewed. */

undefined4 FUN_00025980(void)

{
  return 0;
}



/* 000259b8 FUN_000259b8 */

void FUN_000259b8(void)

{
  return;
}



/* 000259c0 FUN_000259c0 */

void FUN_000259c0(void)

{
  return;
}



/* 000259c8 FUN_000259c8 */

/* Boundary evidence: original MIPS .pdata 000259c8..000259eb. Semantic name remains unreviewed. */

undefined1 FUN_000259c8(void)

{
  return 0xff;
}



/* 000259ec FUN_000259ec */

/* Boundary evidence: original MIPS .pdata 000259ec..00025a0f. Semantic name remains unreviewed. */

undefined2 FUN_000259ec(void)

{
  return 0xffff;
}



/* 00025a10 FUN_00025a10 */

/* Boundary evidence: original MIPS .pdata 00025a10..00025a37. Semantic name remains unreviewed. */

undefined4 FUN_00025a10(void)

{
  return 0xffffffff;
}



/* 00025a74 FUN_00025a74 */

/* Boundary evidence: original MIPS .pdata 00025a74..00025bd7. Semantic name remains unreviewed. */

int FUN_00025a74(uint *param_1)

{
  int local_10;
  
  local_10 = FUN_00022acc(param_1);
  if (local_10 == 0) {
    DAT_0019ec6c = DAT_0019ec6c | 1;
    local_10 = FUN_000239c8();
    if (local_10 == 0) {
      FUN_00023a34();
      DAT_0019ec6c = DAT_0019ec6c | 2;
      local_10 = FUN_000208c8();
      if (local_10 == 0) {
        DAT_0019ec6c = DAT_0019ec6c | 4;
        local_10 = FUN_00023ae4();
        if (local_10 == 0) {
          DAT_0019ec6c = DAT_0019ec6c | 8;
          local_10 = FUN_00025fb8();
          if (local_10 == 0) {
            DAT_0019ec6c = DAT_0019ec6c | 0x10;
            return 0;
          }
        }
      }
    }
  }
  FUN_00025bd8();
  return local_10;
}



/* 00025bd8 FUN_00025bd8 */

/* Boundary evidence: original MIPS .pdata 00025bd8..00025ca7. Semantic name remains unreviewed. */

void FUN_00025bd8(void)

{
  if ((DAT_0019ec6c & 0x10) != 0) {
    FUN_0002600c();
  }
  if ((DAT_0019ec6c & 8) != 0) {
    FUN_00023b78();
  }
  if ((DAT_0019ec6c & 1) != 0) {
    FUN_00022a04();
  }
  if ((DAT_0019ec6c & 4) != 0) {
    FUN_00020918();
  }
  if ((DAT_0019ec6c & 2) != 0) {
    FUN_00023a5c();
    FUN_000239fc();
  }
  if ((DAT_0019ec6c & 1) != 0) {
    FUN_00022bdc();
  }
  DAT_0019ec6c = 0;
  return;
}



/* 00025ca8 FUN_00025ca8 */

/* Boundary evidence: original MIPS .pdata 00025ca8..00025d97. Semantic name remains unreviewed. */

void FUN_00025ca8(void)

{
  int iVar1;
  int local_10;
  
  for (local_10 = 0; (&PTR_FUN_0002e26c)[local_10 * 3] != (undefined *)0x0; local_10 = local_10 + 1)
  {
  }
  while (iVar1 = local_10 + -1, local_10 != 0) {
    if (*(int *)(&DAT_0002e274 + iVar1 * 0xc) != 0) {
      (*(code *)(&PTR_FUN_0002e270)[iVar1 * 3])();
    }
    *(undefined4 *)(&DAT_0002e274 + iVar1 * 0xc) = 0;
    local_10 = iVar1;
  }
  return;
}



/* 00025d98 FUN_00025d98 */

/* Boundary evidence: original MIPS .pdata 00025d98..00025e7f. Semantic name remains unreviewed. */

int FUN_00025d98(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((&PTR_FUN_0002e26c)[local_14 * 3] == (undefined *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)(&PTR_FUN_0002e26c)[local_14 * 3])();
    if (iVar1 != 0) break;
    *(undefined4 *)(&DAT_0002e274 + local_14 * 0xc) = 1;
    local_14 = local_14 + 1;
  }
  FUN_00025ca8();
  return iVar1;
}



/* 00025e80 FUN_00025e80 */

void FUN_00025e80(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(int **)(param_1 + 0xc) = DAT_0019ec7c;
  *DAT_0019ec7c = param_1;
  DAT_0019ec7c = (int *)(param_1 + 8);
  return;
}



/* 00025ed0 FUN_00025ed0 */

/* Boundary evidence: original MIPS .pdata 00025ed0..00025fb7. Semantic name remains unreviewed. */

undefined4 FUN_00025ed0(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_4;
  
  bVar1 = false;
  local_c = DAT_0019ec78;
  iVar2 = local_c;
  while (local_c = iVar2, local_c != 0) {
    iVar2 = *(int *)(local_c + 8);
    if (local_c == param_1) {
      if (*(int *)(local_c + 8) == 0) {
        DAT_0019ec7c = *(undefined4 *)(local_c + 0xc);
      }
      else {
        *(undefined4 *)(*(int *)(local_c + 8) + 0xc) = *(undefined4 *)(local_c + 0xc);
      }
      **(undefined4 **)(local_c + 0xc) = *(undefined4 *)(local_c + 8);
      bVar1 = true;
    }
  }
  if (bVar1) {
    local_4 = 0;
  }
  else {
    local_4 = 10;
  }
  return local_4;
}



/* 00025fb8 FUN_00025fb8 */

/* Boundary evidence: original MIPS .pdata 00025fb8..0002600b. Semantic name remains unreviewed. */

undefined4 FUN_00025fb8(void)

{
  DAT_0019ec70 = 0;
  DAT_0019ec74 = &DAT_0019ec70;
  DAT_0019ec78 = 0;
  DAT_0019ec7c = &DAT_0019ec78;
  return 0;
}



/* 0002600c FUN_0002600c */

void FUN_0002600c(void)

{
  return;
}



/* 00026014 FUN_00026014 */

/* Boundary evidence: original MIPS .pdata 00026014..000260bf. Semantic name remains unreviewed. */

int FUN_00026014(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (*(int *)(&DAT_0019ec80 + local_14 * 4) == 0) {
      return 0;
    }
    iVar1 = (**(code **)(&DAT_0019ec80 + local_14 * 4))();
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  FUN_000260c0();
  return iVar1;
}



/* 000260c0 FUN_000260c0 */

/* Boundary evidence: original MIPS .pdata 000260c0..00026197. Semantic name remains unreviewed. */

void FUN_000260c0(void)

{
  int *piVar1;
  
  while (piVar1 = DAT_0019ec70, DAT_0019ec70 != (int *)0x0) {
    if (*(int *)(*DAT_0019ec70 + 0x20) != 0) {
      (**(code **)(*DAT_0019ec70 + 0x20))();
    }
    if (DAT_0019ec70[4] == 0) {
      DAT_0019ec74 = DAT_0019ec70[5];
    }
    else {
      *(int *)(DAT_0019ec70[4] + 0x14) = DAT_0019ec70[5];
    }
    *(int *)DAT_0019ec70[5] = DAT_0019ec70[4];
    FUN_00021a94(piVar1);
  }
  return;
}



/* 00026198 FUN_00026198 */

/* Boundary evidence: original MIPS .pdata 00026198..0002624f. Semantic name remains unreviewed. */

void FUN_00026198(void)

{
  int iVar1;
  int *piVar2;
  int *local_c;
  
  local_c = DAT_0019ec78;
  do {
    if (local_c == (int *)0x0) {
      return;
    }
    iVar1 = FUN_00026c30((int)local_c);
    if (iVar1 == 0) {
LAB_0002622c:
      FUN_00026504(local_c);
    }
    else {
      piVar2 = (int *)FUN_00026ea0((int)local_c);
      iVar1 = FUN_00026848(piVar2,2,local_c);
      if ((iVar1 == 0) || (iVar1 == 0x16)) goto LAB_0002622c;
    }
    local_c = (int *)local_c[2];
  } while( true );
}



/* 00026250 FUN_00026250 */

/* Boundary evidence: original MIPS .pdata 00026250..0002630f. Semantic name remains unreviewed. */

void FUN_00026250(undefined4 *param_1)

{
  if (param_1[4] == 0) {
    DAT_0019ec74 = param_1[5];
  }
  else {
    *(undefined4 *)(param_1[4] + 0x14) = param_1[5];
  }
  *(undefined4 *)param_1[5] = param_1[4];
  if (*(char *)(param_1 + 3) != '\0') {
    while ((int *)param_1[6] != (int *)0x0) {
      FUN_00027058((int *)param_1[6]);
    }
  }
  FUN_00021a94(param_1);
  return;
}



/* 00026310 FUN_00026310 */

/* Boundary evidence: original MIPS .pdata 00026310..00026453. Semantic name remains unreviewed. */

undefined4 FUN_00026310(int param_1,int param_2,int param_3,undefined2 param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined4 local_c;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  piVar1 = FUN_00021974(0x20,0);
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    piVar1[1] = param_1;
    *piVar1 = param_2;
    piVar1[2] = param_3;
    *(undefined1 *)(piVar1 + 3) = 0;
    *(undefined2 *)((int)piVar1 + 0xe) = param_4;
    *(undefined1 *)((int)piVar1 + 0xd) = 0;
    piVar1[6] = 0;
    piVar1[7] = (int)(piVar1 + 6);
    piVar1[4] = 0;
    piVar1[5] = (int)DAT_0019ec74;
    *DAT_0019ec74 = (int)piVar1;
    DAT_0019ec74 = piVar1 + 4;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = piVar1;
    }
    if (DAT_0019ec78 != 0) {
      FUN_00026198();
    }
    local_c = 0;
  }
  return local_c;
}



/* 00026454 FUN_00026454 */

/* Boundary evidence: original MIPS .pdata 00026454..00026503. Semantic name remains unreviewed. */

void FUN_00026454(int *param_1)

{
  if (*param_1 != 0) {
    if (*(int *)(*(int *)*param_1 + 8) != 0) {
      (**(code **)(*(int *)*param_1 + 8))(param_1);
    }
    if (*param_1 != 0) {
      FUN_00026af0(param_1);
    }
    if (param_1[5] != 0) {
      FUN_00021a94((undefined4 *)param_1[5]);
      param_1[5] = 0;
    }
  }
  return;
}



/* 00026504 FUN_00026504 */

/* Boundary evidence: original MIPS .pdata 00026504..000267d7. Semantic name remains unreviewed. */

int FUN_00026504(int *param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_30;
  int *local_2c;
  int *local_28;
  int local_20;
  
  local_28 = (int *)0x0;
  local_20 = 0;
  iVar2 = FUN_00026c30((int)param_1);
  for (local_2c = DAT_0019ec70; local_2c != (int *)0x0; local_2c = (int *)local_2c[4]) {
    if (local_2c[1] == iVar2) {
      if (*(short *)((int)local_2c + 0xe) != 0) {
        piVar3 = FUN_00021974((uint)*(ushort *)((int)local_2c + 0xe),1);
        param_1[5] = (int)piVar3;
        if (param_1[5] == 0) goto LAB_0002653c;
      }
      iVar4 = (**(code **)*local_2c)(param_1);
      if (*(short *)((int)local_2c + 0xe) != 0) {
        FUN_00021a94((undefined4 *)param_1[5]);
      }
      param_1[5] = 0;
      if (local_20 < iVar4) {
        local_28 = local_2c;
        local_20 = iVar4;
      }
    }
LAB_0002653c:
  }
  if (local_28 == (int *)0x0) {
    local_30 = 4;
  }
  else {
    if (*(short *)((int)local_28 + 0xe) != 0) {
      piVar3 = FUN_00021974((uint)*(ushort *)((int)local_28 + 0xe),1);
      param_1[5] = (int)piVar3;
      if (param_1[5] == 0) {
        local_30 = 7;
        goto LAB_0002675c;
      }
    }
    bVar1 = *(byte *)((int)local_28 + 0xd);
    *(char *)((int)local_28 + 0xd) = *(char *)((int)local_28 + 0xd) + '\x01';
    FUN_00026dbc((int)param_1,(char *)local_28[2],(uint)bVar1);
    local_30 = (**(code **)(*local_28 + 4))(param_1);
    if (local_30 == 0) {
      if ((*param_1 != 0) || (local_30 = FUN_000269bc(param_1,(int)local_28,0,0), local_30 == 0)) {
        return 0;
      }
      FUN_00027058(param_1);
    }
  }
LAB_0002675c:
  if (param_1[5] != 0) {
    FUN_00021a94((undefined4 *)param_1[5]);
    param_1[5] = 0;
  }
  iVar2 = DAT_0019ec8c;
  DAT_0019ec8c = DAT_0019ec8c + 1;
  FUN_00026dbc((int)param_1,"unknown",iVar2);
  return local_30;
}



/* 000267d8 FUN_000267d8 */

/* Boundary evidence: original MIPS .pdata 000267d8..00026847. Semantic name remains unreviewed. */

int FUN_000267d8(int *param_1)

{
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    local_c = FUN_00026504(param_1);
    if (local_c == 0) {
      local_c = 0;
    }
  }
  return local_c;
}



/* 00026848 FUN_00026848 */

/* Boundary evidence: original MIPS .pdata 00026848..000268d3. Semantic name remains unreviewed. */

undefined4 FUN_00026848(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  
  if ((*param_1 == 0) || (*(int *)(*(int *)*param_1 + 0x14) == 0)) {
    local_10 = 10;
  }
  else {
    local_10 = (**(code **)(*(int *)*param_1 + 0x14))(param_1,param_2,param_3);
  }
  return local_10;
}



/* 000268d4 FUN_000268d4 */

/* Boundary evidence: original MIPS .pdata 000268d4..00026947. Semantic name remains unreviewed. */

undefined4 FUN_000268d4(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0xc) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0xc))(param_1);
  }
  return local_10;
}



/* 00026948 FUN_00026948 */

/* Boundary evidence: original MIPS .pdata 00026948..000269bb. Semantic name remains unreviewed. */

undefined4 FUN_00026948(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0x10) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0x10))(param_1);
  }
  return local_10;
}



/* 000269bc FUN_000269bc */

/* Boundary evidence: original MIPS .pdata 000269bc..00026aef. Semantic name remains unreviewed. */

int FUN_000269bc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int local_10;
  
  piVar1 = (int *)FUN_00027330((int)param_1);
  if (((piVar1 == (int *)0x0) || (*(int *)(*piVar1 + 0x18) == 0)) ||
     (local_10 = (**(code **)(*piVar1 + 0x18))(param_1,param_3,param_4), local_10 == 0)) {
    *param_1 = param_2;
    *(char *)(*param_1 + 0xc) = *(char *)(*param_1 + 0xc) + '\x01';
    FUN_00025ed0((int)param_1);
    param_1[2] = 0;
    param_1[3] = *(int *)(*param_1 + 0x1c);
    **(undefined4 **)(*param_1 + 0x1c) = param_1;
    *(int **)(*param_1 + 0x1c) = param_1 + 2;
    local_10 = 0;
  }
  return local_10;
}



/* 00026af0 FUN_00026af0 */

/* Boundary evidence: original MIPS .pdata 00026af0..00026be3. Semantic name remains unreviewed. */

void FUN_00026af0(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00027330((int)param_1);
  if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 0x1c) != 0)) {
    (**(code **)(*piVar1 + 0x1c))(param_1);
  }
  if (param_1[2] == 0) {
    *(int *)(*param_1 + 0x1c) = param_1[3];
  }
  else {
    *(int *)(param_1[2] + 0xc) = param_1[3];
  }
  *(int *)param_1[3] = param_1[2];
  *(char *)(*param_1 + 0xc) = *(char *)(*param_1 + 0xc) + -1;
  *param_1 = 0;
  FUN_00025e80((int)param_1);
  return;
}



/* 00026be4 FUN_00026be4 */

/* Boundary evidence: original MIPS .pdata 00026be4..00026c07. Semantic name remains unreviewed. */

undefined4 FUN_00026be4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}



/* 00026c08 FUN_00026c08 */

/* Boundary evidence: original MIPS .pdata 00026c08..00026c2f. Semantic name remains unreviewed. */

undefined4 FUN_00026c08(undefined4 param_1,int param_2)

{
  return *(undefined4 *)(param_2 + 0x3c);
}



/* 00026c30 FUN_00026c30 */

/* Boundary evidence: original MIPS .pdata 00026c30..00026c6f. Semantic name remains unreviewed. */

undefined4 FUN_00026c30(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0xffffffff;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x18);
  }
  return local_8;
}



/* 00026c8c FUN_00026c8c */

/* Boundary evidence: original MIPS .pdata 00026c8c..00026ccb. Semantic name remains unreviewed. */

undefined4 FUN_00026c8c(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x1c);
  }
  return local_8;
}



/* 00026ccc FUN_00026ccc */

/* Boundary evidence: original MIPS .pdata 00026ccc..00026d0b. Semantic name remains unreviewed. */

undefined4 FUN_00026ccc(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x24);
  }
  return local_8;
}



/* 00026d0c FUN_00026d0c */

/* Boundary evidence: original MIPS .pdata 00026d0c..00026d2f. Semantic name remains unreviewed. */

undefined4 FUN_00026d0c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* 00026d4c FUN_00026d4c */

/* Boundary evidence: original MIPS .pdata 00026d4c..00026dbb. Semantic name remains unreviewed. */

undefined * FUN_00026d4c(int param_1)

{
  undefined *local_8;
  undefined *local_4;
  
  if (param_1 == 0) {
    local_8 = &DAT_0002d28c;
  }
  else {
    if (*(int *)(param_1 + 0x2c) == 0) {
      local_4 = &DAT_0002d28c;
    }
    else {
      local_4 = *(undefined **)(param_1 + 0x2c);
    }
    local_8 = local_4;
  }
  return local_8;
}



/* 00026dbc FUN_00026dbc */

/* Boundary evidence: original MIPS .pdata 00026dbc..00026e9f. Semantic name remains unreviewed. */

void FUN_00026dbc(int param_1,char *param_2,undefined4 param_3)

{
  size_t sVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00021a94(*(undefined4 **)(param_1 + 0x2c));
  }
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = param_3;
  }
  else {
    sVar1 = FUN_00020a04(param_2);
    piVar2 = FUN_00021974(sVar1 + 10,1);
    *(int **)(param_1 + 0x2c) = piVar2;
    if (*(int *)(param_1 + 0x2c) != 0) {
      *(undefined4 *)(param_1 + 0x28) = param_3;
      FUN_00020ab8(*(char **)(param_1 + 0x2c),sVar1 + 10,"%s%ld",param_2);
    }
  }
  return;
}



/* 00026ea0 FUN_00026ea0 */

/* Boundary evidence: original MIPS .pdata 00026ea0..00026ec3. Semantic name remains unreviewed. */

undefined4 FUN_00026ea0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* 00026ec4 FUN_00026ec4 */

/* Boundary evidence: original MIPS .pdata 00026ec4..00026f03. Semantic name remains unreviewed. */

undefined4 FUN_00026ec4(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x14);
  }
  return local_8;
}



/* 00026f04 FUN_00026f04 */

/* Boundary evidence: original MIPS .pdata 00026f04..00026f27. Semantic name remains unreviewed. */

undefined4 FUN_00026f04(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* 00026f28 FUN_00026f28 */

/* Boundary evidence: original MIPS .pdata 00026f28..00026f6b. Semantic name remains unreviewed. */

bool FUN_00026f28(int *param_1)

{
  return *param_1 != 0;
}



/* 00026f6c FUN_00026f6c */

/* Boundary evidence: original MIPS .pdata 00026f6c..00026fa3. Semantic name remains unreviewed. */

int FUN_00026f6c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_000267d8(param_1);
  return iVar1;
}



/* 00026fa4 FUN_00026fa4 */

/* Boundary evidence: original MIPS .pdata 00026fa4..0002700b. Semantic name remains unreviewed. */

void FUN_00026fa4(int param_1,char *param_2)

{
  int *piVar1;
  
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_00021a94(*(undefined4 **)(param_1 + 0x30));
    }
    piVar1 = FUN_00023fa4(param_2);
    *(int **)(param_1 + 0x30) = piVar1;
  }
  return;
}



/* 0002700c FUN_0002700c */

/* Boundary evidence: original MIPS .pdata 0002700c..00027057. Semantic name remains unreviewed. */

undefined * FUN_0002700c(int param_1)

{
  undefined *local_4;
  
  if (param_1 == 0) {
    local_4 = &DAT_0002d28c;
  }
  else {
    local_4 = *(undefined **)(param_1 + 0x30);
  }
  return local_4;
}



/* 00027058 FUN_00027058 */

/* Boundary evidence: original MIPS .pdata 00027058..00027093. Semantic name remains unreviewed. */

undefined4 FUN_00027058(int *param_1)

{
  FUN_00026454(param_1);
  FUN_00026198();
  return 0;
}



/* 00027094 FUN_00027094 */

/* Boundary evidence: original MIPS .pdata 00027094..0002720b. Semantic name remains unreviewed. */

void FUN_00027094(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  int *local_14;
  
  if (param_1 != (int *)0x0) {
    bVar1 = FUN_00026f28(param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_00026454(param_1);
    }
    iVar2 = FUN_00026ea0((int)param_1);
    if (iVar2 != 0) {
      piVar3 = *(int **)(iVar2 + 0x34);
      while (local_14 = piVar3, local_14 != (int *)0x0) {
        piVar3 = (int *)local_14[0xf];
        if (local_14 == param_1) {
          if (local_14[0xf] == 0) {
            *(int *)(iVar2 + 0x38) = local_14[0x10];
          }
          else {
            *(int *)(local_14[0xf] + 0x40) = local_14[0x10];
          }
          *(int *)local_14[0x10] = local_14[0xf];
        }
      }
    }
    FUN_00025ed0((int)param_1);
    if (param_1[0xb] != 0) {
      FUN_00021a94((undefined4 *)param_1[0xb]);
    }
    if (param_1[0xc] != 0) {
      FUN_00021a94((undefined4 *)param_1[0xc]);
    }
    FUN_00021a94(param_1);
  }
  return;
}



/* 0002720c FUN_0002720c */

/* Boundary evidence: original MIPS .pdata 0002720c..00027313. Semantic name remains unreviewed. */

int * FUN_0002720c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *local_c;
  
  local_c = FUN_00021974(0x44,1);
  if (local_c == (int *)0x0) {
    local_c = (int *)0x0;
  }
  else {
    local_c[4] = param_2;
    local_c[6] = param_1;
    local_c[1] = param_4;
    FUN_00027314((int)local_c,param_3);
    local_c[0xd] = 0;
    local_c[0xe] = (int)(local_c + 0xd);
    if (param_2 != 0) {
      local_c[0xf] = 0;
      local_c[0x10] = *(int *)(param_2 + 0x38);
      **(undefined4 **)(param_2 + 0x38) = local_c;
      *(int **)(param_2 + 0x38) = local_c + 0xf;
    }
    FUN_00025e80((int)local_c);
  }
  return local_c;
}



/* 00027314 FUN_00027314 */

void FUN_00027314(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}



/* 00027330 FUN_00027330 */

/* Boundary evidence: original MIPS .pdata 00027330..0002736f. Semantic name remains unreviewed. */

undefined4 FUN_00027330(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 4);
  }
  return local_8;
}



/* 00027370 FUN_00027370 */

/* Boundary evidence: original MIPS .pdata 00027370..000273f7. Semantic name remains unreviewed. */

void FUN_00027370(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_000274d4();
  uVar2 = FUN_000273f8();
  uVar2 = (uVar2 / 1000000 + 1) * param_1 + uVar1;
  while (uVar2 < uVar1) {
    uVar1 = FUN_000274d4();
  }
  do {
    uVar1 = FUN_000274d4();
  } while (uVar1 < uVar2);
  return;
}



/* 000273f8 FUN_000273f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000273f8(void)

{
  return (_DAT_b0900060 & 0x7f) * 12000000;
}



/* 000274d4 FUN_000274d4 */

undefined4 FUN_000274d4(void)

{
  return Count;
}



/* 000278e8 FUN_000278e8 */

/* Boundary evidence: original MIPS .pdata 000278e8..0002795b. Semantic name remains unreviewed. */

void FUN_000278e8(void)

{
  uint uVar1;
  
  if ((DAT_0002e28c == 0) || (DAT_0002e28c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0002e28c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0002e28c == 0) {
      DAT_0002e28c = 0xb064;
    }
  }
  DAT_0002e290 = ~DAT_0002e28c;
  return;
}



/* 0002795c FUN_0002795c */

/* Boundary evidence: original MIPS .pdata 0002795c..000279af. Semantic name remains unreviewed. */

void FUN_0002795c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000279ec(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000279b0 FUN_000279b0 */

/* Boundary evidence: original MIPS .pdata 000279b0..000279db. Semantic name remains unreviewed. */

undefined4 FUN_000279b0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0002795c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000279ec FUN_000279ec */

/* Boundary evidence: original MIPS .pdata 000279ec..00027a33. Semantic name remains unreviewed. */

void FUN_000279ec(uint param_1)

{
  if ((param_1 == DAT_0002e28c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00027a44 FUN_00027a44 */

/* Boundary evidence: original MIPS .pdata 00027a44..00027ad7. Semantic name remains unreviewed. */

void FUN_00027a44(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  UINT UVar1;
  
  FUN_00027dd4();
  UVar1 = FUN_000181c8(param_1,param_2,param_3,param_4);
  FUN_00027d14(UVar1);
  FUN_00027d34(UVar1);
  return;
}



/* 00027ad8 FUN_00027ad8 */

/* Boundary evidence: original MIPS .pdata 00027ad8..00027b17. Semantic name remains unreviewed. */

void FUN_00027ad8(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00027b18 entry */

/* Boundary evidence: original MIPS .pdata 00027b18..00027b73. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  FUN_000278e8();
  FUN_00027a44(param_1,param_2,param_3,param_4);
  return;
}



/* 00027bf4 FUN_00027bf4 */

/* Boundary evidence: original MIPS .pdata 00027bf4..00027d13. Semantic name remains unreviewed. */

void FUN_00027bf4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0019ec90 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0019ec98;
    if (DAT_0019ec98 != (undefined4 *)0x0) {
      while (DAT_0019ec94 = DAT_0019ec94 + -1, _Memory <= DAT_0019ec94) {
        if ((code *)*DAT_0019ec94 != (code *)0x0) {
          (*(code *)*DAT_0019ec94)();
          _Memory = DAT_0019ec98;
        }
      }
      free(_Memory);
      DAT_0019ec94 = (undefined4 *)0x0;
      DAT_0019ec98 = (undefined4 *)0x0;
    }
    FUN_00027d80((undefined4 *)&DAT_00028014,(undefined4 *)&DAT_00028018);
  }
  FUN_00027d80((undefined4 *)&DAT_0002801c,(undefined4 *)&DAT_00028020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0019ec9c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00027d14 FUN_00027d14 */

/* Boundary evidence: original MIPS .pdata 00027d14..00027d33. Semantic name remains unreviewed. */

void FUN_00027d14(UINT param_1)

{
  FUN_00027bf4(param_1,0,0);
  return;
}



/* 00027d34 FUN_00027d34 */

/* Boundary evidence: original MIPS .pdata 00027d34..00027d7f. Semantic name remains unreviewed. */

void FUN_00027d34(UINT param_1)

{
  DAT_0019ec90 = 0;
  FUN_00027d80((undefined4 *)&DAT_0002801c,(undefined4 *)&DAT_00028020);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00027d80 FUN_00027d80 */

/* Boundary evidence: original MIPS .pdata 00027d80..00027dd3. Semantic name remains unreviewed. */

void FUN_00027d80(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00027dd4 FUN_00027dd4 */

/* Boundary evidence: original MIPS .pdata 00027dd4..00027e0f. Semantic name remains unreviewed. */

void FUN_00027dd4(void)

{
  FUN_00027d80((undefined4 *)&DAT_0002800c,(undefined4 *)&DAT_00028010);
  FUN_00027d80((undefined4 *)&DAT_00028000,(undefined4 *)&DAT_00028008);
  return;
}



/* 00027e50 FUN_00027e50 */

/* Boundary evidence: original MIPS .pdata 00027e50..00027eb3. Semantic name remains unreviewed. */

void FUN_00027e50(void)

{
  memset(&DAT_0016d130,0,0x20);
  memset(&DAT_0016d150,0,0x400);
  memset(&DAT_0016d550,0,0x400);
  memset(&DAT_0016d950,0,0x400);
  return;
}


