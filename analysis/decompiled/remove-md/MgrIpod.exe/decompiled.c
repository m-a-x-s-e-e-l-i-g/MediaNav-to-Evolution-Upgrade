/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..0001101b. Semantic name remains unreviewed. */

void FUN_00011000(undefined4 param_1)

{
  EventModify(param_1,3);
  return;
}



/* 0001101c FUN_0001101c */

/* Boundary evidence: original MIPS .pdata 0001101c..000110bb. Semantic name remains unreviewed. */

void FUN_0001101c(undefined4 *param_1)

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



/* 000110bc FUN_000110bc */

/* Boundary evidence: original MIPS .pdata 000110bc..0001115b. Semantic name remains unreviewed. */

void FUN_000110bc(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S g_bRemoteUIMode %d track index %d","app_play_current_selected_track",
                DAT_0016bda0,param_1);
  if (DAT_0016bda0 == 1) {
    FUN_0001db40(DAT_0016ca78,0x163c0,param_1,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  return;
}



/* 0001115c FUN_0001115c */

/* Boundary evidence: original MIPS .pdata 0001115c..000111e3. Semantic name remains unreviewed. */

void FUN_0001115c(undefined4 param_1)

{
  if (DAT_0016bda0 == 1) {
    FUN_0001d420(DAT_0016ca78,0x163c0,param_1,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_current_play_track");
  }
  return;
}



/* 000111e4 FUN_000111e4 */

/* Boundary evidence: original MIPS .pdata 000111e4..00011267. Semantic name remains unreviewed. */

void FUN_000111e4(void)

{
  if (DAT_0016bda0 == 1) {
    FUN_0001d4ac(DAT_0016ca78,0x15c98,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_current_playing_track_index");
  }
  return;
}



/* 00011268 FUN_00011268 */

/* Boundary evidence: original MIPS .pdata 00011268..0001131b. Semantic name remains unreviewed. */

void FUN_00011268(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_get_num_playing_tracks");
  if (DAT_0016bda0 == 1) {
    FUN_0001d52c(DAT_0016ca78,0x15dac,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_num_playing_tracks");
  }
  return;
}



/* 0001131c FUN_0001131c */

uint * FUN_0001131c(uint *param_1,uint param_2)

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



/* 000113b0 FUN_000113b0 */

/* Boundary evidence: original MIPS .pdata 000113b0..00011463. Semantic name remains unreviewed. */

void FUN_000113b0(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_get_repeat");
  if (DAT_0016bda0 == 1) {
    FUN_0001d640(DAT_0016ca78,0x15e7c,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_repeat");
  }
  return;
}



/* 00011464 FUN_00011464 */

/* Boundary evidence: original MIPS .pdata 00011464..0001152b. Semantic name remains unreviewed. */

void FUN_00011464(undefined4 param_1,int param_2,int param_3)

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
  EventModify(DAT_0016ca94,3);
  return;
}



/* 0001152c FUN_0001152c */

/* Boundary evidence: original MIPS .pdata 0001152c..000115f7. Semantic name remains unreviewed. */

void FUN_0001152c(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S shuffle mode %d","app_set_shuffle",param_1);
  if (DAT_0016bda0 == 1) {
    FUN_0001d6c0(DAT_0016ca78,0x15f14,(char)param_1,0,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_shuffle");
  }
  return;
}



/* 000115f8 FUN_000115f8 */

/* Boundary evidence: original MIPS .pdata 000115f8..000116ab. Semantic name remains unreviewed. */

void FUN_000115f8(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_get_shuffle");
  if (DAT_0016bda0 == 1) {
    FUN_0001d754(DAT_0016ca78,0x15f74,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_shuffle");
  }
  return;
}



/* 000116ac FUN_000116ac */

/* Boundary evidence: original MIPS .pdata 000116ac..00011763. Semantic name remains unreviewed. */

void FUN_000116ac(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_next_track");
  if (DAT_0016bda0 == 1) {
    FUN_0001d314(DAT_0016ca78,0x157bc,3,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_next_track");
  }
  return;
}



/* 00011764 FUN_00011764 */

/* Boundary evidence: original MIPS .pdata 00011764..000117eb. Semantic name remains unreviewed. */

void FUN_00011764(undefined4 param_1)

{
  if (DAT_0016bda0 == 1) {
    FUN_0001d7d4(DAT_0016ca78,0x16008,param_1,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_track_title");
  }
  return;
}



/* 000117ec FUN_000117ec */

/* Boundary evidence: original MIPS .pdata 000117ec..00011873. Semantic name remains unreviewed. */

void FUN_000117ec(undefined4 param_1)

{
  if (DAT_0016bda0 == 1) {
    FUN_0001d860(DAT_0016ca78,0x16170,param_1,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_track_album2");
  }
  return;
}



/* 00011874 FUN_00011874 */

/* Boundary evidence: original MIPS .pdata 00011874..0001192b. Semantic name remains unreviewed. */

void FUN_00011874(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_prev_track");
  if (DAT_0016bda0 == 1) {
    FUN_0001d314(DAT_0016ca78,0x157bc,4,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_prev_track");
  }
  return;
}



/* 0001192c FUN_0001192c */

/* Boundary evidence: original MIPS .pdata 0001192c..000119f3. Semantic name remains unreviewed. */

void FUN_0001192c(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_fast_forward");
  if (DAT_0016bda0 == 1) {
    FUN_0001d314(DAT_0016ca78,0x157bc,5,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    DAT_0016bdac = 1;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_fast_forward");
  }
  return;
}



/* 000119f4 FUN_000119f4 */

/* Boundary evidence: original MIPS .pdata 000119f4..00011abb. Semantic name remains unreviewed. */

void FUN_000119f4(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_fast_rewind");
  if (DAT_0016bda0 == 1) {
    FUN_0001d314(DAT_0016ca78,0x157bc,6,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    DAT_0016bdb0 = 1;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_fast_rewind");
  }
  return;
}



/* 00011abc FUN_00011abc */

/* Boundary evidence: original MIPS .pdata 00011abc..00011bef. Semantic name remains unreviewed. */

void FUN_00011abc(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_stop_ff_frw");
  if (DAT_0016bda0 == 1) {
    DAT_0016bdac = 0;
    DAT_0016bdb0 = 0;
    FUN_0001d314(DAT_0016ca78,0x157bc,7,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    if (DAT_0016cab0 == 1) {
      Sleep(0x96);
      NKDbgPrintfW(L"~~~ Oh~~ My God.... Fuck you!!!! Apple !!!!!! \r\n");
      FUN_0001d314(DAT_0016ca78,0x157bc,7,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_stop_ff_frw");
  }
  return;
}



/* 00011bf0 FUN_00011bf0 */

/* Boundary evidence: original MIPS .pdata 00011bf0..00011d1b. Semantic name remains unreviewed. */

undefined4 FUN_00011bf0(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  uint dwMilliseconds;
  
  DbgDebugPrint(6,0,&DAT_00028130,"app_get_play_status");
  if (DAT_0016bda0 == 1) {
    DVar1 = GetTickCount();
    dwMilliseconds = DVar1 - DAT_0016bdbc;
    if ((dwMilliseconds < 1000) && (dwMilliseconds != 0)) {
      NKDbgPrintfW(L"_-_ == app_get_play_status() Interval Time %d\r\n",dwMilliseconds);
      WaitForSingleObject(DAT_0016caa0,dwMilliseconds);
    }
    FUN_0001d3a0(DAT_0016ca78,0x158e0,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    DAT_0016bdbc = GetTickCount();
    uVar2 = DAT_0016bdb8;
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_play_status");
    uVar2 = 0;
  }
  return uVar2;
}



/* 00011d1c FUN_00011d1c */

/* Boundary evidence: original MIPS .pdata 00011d1c..00011ddb. Semantic name remains unreviewed. */

bool FUN_00011d1c(void)

{
  bool bVar1;
  
  DbgDebugPrint(6,0,&DAT_00028130,"app_get_play_status2");
  bVar1 = DAT_0016bda0 == 1;
  if (bVar1) {
    FUN_0001d3a0(DAT_0016ca78,0x15bdc,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_get_play_status2");
  }
  return bVar1;
}



/* 00011ddc FUN_00011ddc */

/* Boundary evidence: original MIPS .pdata 00011ddc..00011eb7. Semantic name remains unreviewed. */

void FUN_00011ddc(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_enter_remote_ui_mode");
  EventModify(DAT_0016ca98,2);
  FUN_0001c3e8(DAT_0016ca78,0x154bc,1,0);
  WaitForSingleObject(DAT_0016ca98,0xffffffff);
  if (DAT_0016cabc == '\x04') {
    EventModify(DAT_0016ca98,2);
    FUN_0001c698(DAT_0016ca78,0x154bc,0);
    WaitForSingleObject(DAT_0016ca98,0xffffffff);
  }
  return;
}



/* 00011eb8 FUN_00011eb8 */

/* Boundary evidence: original MIPS .pdata 00011eb8..00011f33. Semantic name remains unreviewed. */

void FUN_00011eb8(void)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_exit_remote_ui_mode");
  EventModify(DAT_0016ca98,2);
  FUN_0001c8a4(DAT_0016ca78,0x155a8,0);
  WaitForSingleObject(DAT_0016ca98,0xffffffff);
  return;
}



/* 00011f34 FUN_00011f34 */

/* Boundary evidence: original MIPS .pdata 00011f34..00011f7f. Semantic name remains unreviewed. */

void FUN_00011f34(uint param_1)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_start_audio_read");
  FUN_00013a54(param_1);
  return;
}



/* 00011f80 FUN_00011f80 */

/* Boundary evidence: original MIPS .pdata 00011f80..00011fcb. Semantic name remains unreviewed. */

void FUN_00011f80(uint param_1)

{
  DbgDebugPrint(6,0,&DAT_00028130,"app_stop_audio_read");
  FUN_00013c9c(param_1);
  return;
}



/* 00011fcc FUN_00011fcc */

/* Boundary evidence: original MIPS .pdata 00011fcc..0001200f. Semantic name remains unreviewed. */

void FUN_00011fcc(void)

{
  FUN_0001d294(DAT_0016ca78,0x1575c,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 00012010 FUN_00012010 */

/* Boundary evidence: original MIPS .pdata 00012010..0001209f. Semantic name remains unreviewed. */

void FUN_00012010(undefined4 param_1,undefined4 param_2)

{
  DbgDebugPrint(0x15,0,L"%S db type %d db_record_idx %d","app_select_db_record",param_1,param_2);
  FUN_0001d978(DAT_0016ca78,0x146b4,(char)param_1,param_2,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 000120a0 FUN_000120a0 */

/* Boundary evidence: original MIPS .pdata 000120a0..000120ef. Semantic name remains unreviewed. */

void FUN_000120a0(undefined4 param_1)

{
  DAT_0002d158 = param_1;
  FUN_0001da0c(DAT_0016ca78,0x14714,(char)param_1,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 000120f0 FUN_000120f0 */

/* Boundary evidence: original MIPS .pdata 000120f0..0001240f. Semantic name remains unreviewed. */

void FUN_000120f0(uint param_1,int param_2)

{
  bool bVar1;
  DWORD DVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_0016bd9c == 0) {
    DbgDebugPrint(0x14,2,L"%S g_ocListDataShrMem == NULL","app_request_categorized_db_records");
    return;
  }
  if ((param_1 == 0) || (7 < param_1)) {
    DbgDebugPrint(6,2,L"%S category:%d invalid value","app_request_categorized_db_records",param_1);
    return;
  }
  DAT_0002d158 = param_1;
  FUN_000120a0(param_1);
  DbgDebugPrint(6,0,L"%S category:%d, request_start_index:%d","app_request_categorized_db_records",
                param_1,param_2);
  memset(&DAT_0002d2a0,0,1300000);
  DVar2 = GetTickCount();
  DbgDebugPrint(6,0,L"%S tickcount %d","app_request_categorized_db_records",DVar2);
  DAT_0016bdc4 = 0;
  DAT_0016bdc0 = '\0';
  DAT_0002d28c = (char)param_1;
  DAT_0016bd50 = param_2;
  KillTimer(DAT_0016cac4,0x3ec);
  if (DAT_0016ca90 == 0) {
    if (DAT_0016bd9c == 0) goto LAB_00012390;
    MSHM_Dll_Write(DAT_0016bd9c,&DAT_0002d298,0,&DAT_0013d628);
  }
  else {
    uVar3 = DAT_0016ca90 - DAT_0016bdc4;
    uVar4 = 0;
    if (200 < uVar3) {
      uVar3 = 200;
    }
    Sleep(10);
    NKDbgPrintfW(L":===> [%d/%d]\r\n",param_2,DAT_0016ca90);
    while( true ) {
      FUN_0001da98(DAT_0016ca78,0x147b0,(char)param_1,DAT_0016bdc4 + param_2,uVar3,(void *)0x0,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
      if (DAT_0016bdc0 != '\x01') break;
      NKDbgPrintfW(L"[ERROR] app_request_categorized_db_records() ~!@#$ Retry %d\r\n",uVar4);
      Sleep(0x50);
      if ((DAT_0016bdc0 != '\x01') || (bVar1 = 4 < uVar4, uVar4 = uVar4 + 1, bVar1)) break;
    }
    DAT_0016bdc4 = DAT_0016bdc4 + uVar3;
  }
  if (DAT_0016bdc4 < DAT_0016ca90) {
    SetTimer(DAT_0016cac4,0x3ec,0x14,(TIMERPROC)0x0);
    return;
  }
LAB_00012390:
  IpcPostMsg(6,0x15,0x75,0,0);
  return;
}



/* 00012410 FUN_00012410 */

/* Boundary evidence: original MIPS .pdata 00012410..000125fb. Semantic name remains unreviewed. */

void FUN_00012410(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = DAT_0016ca90 - DAT_0016bdc4;
  uVar3 = 0;
  if (200 < uVar2) {
    uVar2 = 200;
  }
  NKDbgPrintfW(L"===> [%d/%d]-%d\r\n",DAT_0016bd50 + DAT_0016bdc4,DAT_0016ca90,uVar2);
  while( true ) {
    FUN_0001da98(DAT_0016ca78,0x147b0,DAT_0002d28c,DAT_0016bd50 + DAT_0016bdc4,uVar2,(void *)0x0,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    if (DAT_0016bdc0 != '\x01') break;
    NKDbgPrintfW(L"[ERROR] app_request_categorized_db_records() ~!@#$ Retry %d\r\n",uVar3);
    Sleep(0x50);
    if ((DAT_0016bdc0 != '\x01') || (bVar1 = 4 < uVar3, uVar3 = uVar3 + 1, bVar1)) break;
  }
  DAT_0016bdc4 = DAT_0016bdc4 + uVar2;
  if (DAT_0016bdc4 < DAT_0016ca90) {
    if (DAT_0016bdc4 < 5000) {
      SetTimer(DAT_0016cac4,0x3ec,0x14,(TIMERPROC)0x0);
      return;
    }
  }
  else if (DAT_0016bdc4 < 5000) goto LAB_000125ac;
  if (DAT_0016bd9c != 0) {
    MSHM_Dll_Write(DAT_0016bd9c,&DAT_0002d298,0,&DAT_0013d628);
  }
LAB_000125ac:
  IpcPostMsg(6,0x15,0x75,0,0);
  return;
}



/* 000125fc FUN_000125fc */

/* Boundary evidence: original MIPS .pdata 000125fc..0001266b. Semantic name remains unreviewed. */

void FUN_000125fc(uint param_1,undefined4 param_2)

{
  if (param_1 == 4) {
    FUN_00011fcc();
  }
  else {
    FUN_000120a0(param_1 & 0xff);
    FUN_00012010(param_1 & 0xff,param_2);
  }
  FUN_000120f0(param_1 & 0xff,0);
  return;
}



/* 0001266c FUN_0001266c */

/* Boundary evidence: original MIPS .pdata 0001266c..000129cf. Semantic name remains unreviewed. */

void FUN_0001266c(void)

{
  memset(&DAT_0016cab4,0,8);
  FUN_000139fc();
  DbgDebugPrint(6,0,L"%S before enter ui mode","init_ipod_connection");
  FUN_00014030(0);
  FUN_00014040(0);
  FUN_00013fb0(0);
  FUN_00013fd0(0);
  if (DAT_0016bda4 != 0) {
    FUN_0001ce8c(0,0x16d10,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    if ((DAT_0016cabc == '\0') && ((DAT_0016cab4 & 0x200) != 0)) {
      FUN_0001cf0c(0,0x16d9c,0x204,0,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
    }
    FUN_00013ff0();
    if (DAT_0016bda4 != 0) {
      FUN_00011ddc();
      if (DAT_0016bda0 == 0) {
        if (DAT_0016bda4 == 0) {
          return;
        }
        Sleep(500);
        NKDbgPrintfW(L"~~!@#$ Oh~~ My god~~!!!! g_bRemoteUIMode[%d]\r\n",DAT_0016bda0);
        if (DAT_0016bda4 == 0) {
          return;
        }
        FUN_00011eb8();
        Sleep(1000);
        if (DAT_0016bda4 == 0) {
          return;
        }
        FUN_00011ddc();
        if (DAT_0016bda0 == 0) {
          NKDbgPrintfW(L"~~!@#$ Oh~~ My god~~ Force change....!!!! g_bRemoteUIMode[%d]\r\n",0);
        }
      }
      FUN_0001cc4c(DAT_0016ca78,4,0x16bd0,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
      if (DAT_0016cabc == '\x04') {
        FUN_0001c818(DAT_0016ca78,0x169d8,4,0);
      }
      else {
        FUN_0001cc4c(0,0,0x16bd0,0);
      }
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
      if (DAT_0016bda0 == 1) {
        FUN_00011bf0();
        DbgDebugPrint(6,0,L"%S before uwhu_ipod_ext_set_play_status_change_notify",
                      "init_ipod_connection");
        FUN_0001d208(DAT_0016ca78,0x156e8,0xf,0);
        WaitForSingleObject(DAT_0016ca94,0xffffffff);
        if ((DAT_0016cabc == '\x04') || (DAT_0016cabc == '\v')) {
          FUN_0001d17c(DAT_0016ca78,0x15688,1,0);
          WaitForSingleObject(DAT_0016ca94,0xffffffff);
        }
        FUN_00011fcc();
        FUN_0001e9a0(0,0x16af0,0x188,0);
        WaitForSingleObject(DAT_0016ca94,0xffffffff);
      }
      DbgDebugPrint(6,0,L"%S after app_enter_remote_ui_mode","init_ipod_connection");
      FUN_00013e2c(1);
    }
  }
  return;
}



/* 000129d0 FUN_000129d0 */

/* Boundary evidence: original MIPS .pdata 000129d0..00012bfb. Semantic name remains unreviewed. */

void FUN_000129d0(void)

{
  if (DAT_0016bd98 == 0) {
    DbgDebugPrint(6,1,L"%S shared memory is null","app_fetch_album_artwork_app");
  }
  else {
    DbgDebugPrint(6,0,&DAT_00028130,"app_fetch_album_artwork_app");
    DAT_0002d290 = 0;
    EventModify(DAT_0016ca9c,2);
    FUN_0001dccc(DAT_0016ca78,0x1671c,0);
    WaitForSingleObject(DAT_0016ca9c,0xffffffff);
    EventModify(DAT_0016ca9c,2);
    FUN_0001ddf4(DAT_0016ca78,0x1664c,DAT_0016bdf4,DAT_0002d290,0,1,0);
    WaitForSingleObject(DAT_0016ca9c,0xffffffff);
    DbgDebugPrint(6,0,L"%S artwork data is %d","app_fetch_album_artwork_app",DAT_0016ca84);
    if (DAT_0016ca84 == 0) {
      DAT_0016caa4 = 0;
      if (DAT_0016ca1c != (HGDIOBJ)0x0) {
        DeleteObject(DAT_0016ca1c);
        DAT_0016ca1c = (HGDIOBJ)0x0;
      }
      if (DAT_0016caa8 != (void *)0x0) {
        free(DAT_0016caa8);
        DAT_0016caa8 = (void *)0x0;
      }
      MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x71,0,0);
    }
    else {
      FUN_0001dd4c(DAT_0016ca78,0x16420,DAT_0016bdf4,DAT_0002d290,DAT_0016ca88,(void *)0x0,0);
    }
  }
  return;
}



/* 00012bfc FUN_00012bfc */

/* Boundary evidence: original MIPS .pdata 00012bfc..00012dbb. Semantic name remains unreviewed. */

void FUN_00012bfc(void *param_1,DWORD param_2,LONG param_3,int param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  HDC hdc;
  HBITMAP pHVar3;
  void *local_60 [2];
  BITMAPINFO local_58;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  local_60[0] = (void *)0x0;
  memset(&local_58,0,0x38);
  local_58.bmiHeader.biHeight = -param_4;
  local_58.bmiHeader.biPlanes = 1;
  local_58.bmiHeader.biXPelsPerMeter = 0xb12;
  local_58.bmiHeader.biYPelsPerMeter = 0xb12;
  local_2c = 0x7e0;
  local_58.bmiHeader.biBitCount = 0x10;
  local_58.bmiColors[0].rgbBlue = '\0';
  local_58.bmiColors[0].rgbGreen = 0xf8;
  local_58.bmiColors[0].rgbRed = '\0';
  local_58.bmiColors[0].rgbReserved = '\0';
  local_58.bmiHeader.biSize = 0x28;
  local_58.bmiHeader.biCompression = 3;
  local_28 = 0x1f;
  local_24 = 0;
  local_58.bmiHeader.biWidth = param_3;
  local_58.bmiHeader.biSizeImage = param_2;
  if (DAT_0016ca1c != (HGDIOBJ)0x0) {
    BVar1 = DeleteObject(DAT_0016ca1c);
    DVar2 = GetLastError();
    NKDbgPrintfW(L"~!@#$ [%S] %d, %x \r\n","WriteArtworkDIB",BVar1,DVar2);
  }
  hdc = CreateCompatibleDC((HDC)0x0);
  pHVar3 = CreateDIBSection(hdc,&local_58,0,local_60,(HANDLE)0x0,0);
  if (pHVar3 == (HBITMAP)0x0) {
    DVar2 = GetLastError();
    DbgDebugPrint(6,2,L"%S CreateDIB section fails! error code %d","WriteArtworkDIB",DVar2);
  }
  else {
    memcpy(local_60[0],param_1,param_2 - 2);
    DbgDebugPrint(6,0,L"%S DIB created","WriteArtworkDIB");
  }
  if (hdc != (HDC)0x0) {
    DeleteDC(hdc);
  }
  DAT_0016ca1c = pHVar3;
  return;
}



/* 00012dbc FUN_00012dbc */

/* Boundary evidence: original MIPS .pdata 00012dbc..00012e87. Semantic name remains unreviewed. */

undefined4 FUN_00012dbc(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00013f08();
  uVar2 = 2;
  if (iVar1 == 0x130300) {
    uVar2 = 0;
    goto LAB_00012e4c;
  }
  if (((iVar1 != 0x17000b) && (iVar1 != 0x1c0005)) && (iVar1 != 0x1e0006)) {
    if (iVar1 == 0x210000) goto LAB_00012e4c;
    if (iVar1 != 0x250015) {
      if (iVar1 != 0x260000) {
        uVar2 = 4;
      }
      goto LAB_00012e4c;
    }
  }
  uVar2 = 1;
LAB_00012e4c:
  DbgDebugPrint(6,2,L"%S uiPod_type: %d \n","app_get_ipod_type",uVar2);
  return uVar2;
}



/* 00012e88 FUN_00012e88 */

/* Boundary evidence: original MIPS .pdata 00012e88..00012f5b. Semantic name remains unreviewed. */

void FUN_00012e88(undefined4 param_1)

{
  DbgDebugPrint(6,0,L"%S repeat mode %d","app_set_repeat",param_1);
  if (DAT_0016bda0 == 1) {
    FUN_0001d5ac(DAT_0016ca78,0x15e1c,(char)param_1,0,0);
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    FUN_000113b0();
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_set_repeat");
  }
  return;
}



/* 00012f5c FUN_00012f5c */

/* Boundary evidence: original MIPS .pdata 00012f5c..00013027. Semantic name remains unreviewed. */

void FUN_00012f5c(int param_1)

{
  DWORD DVar1;
  int local_18 [2];
  
  local_18[0] = param_1 * 1000;
  DbgDebugPrint(6,0,L"%S set pos %d ms","app_set_track_pos",local_18[0]);
  DVar1 = GetTickCount();
  DbgDebugPrint(6,0,L"%S %d","app_set_track_pos",DVar1);
  FUN_0001eaac(DAT_0016ca78,0x11464,0,local_18,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 00013028 FUN_00013028 */

/* Boundary evidence: original MIPS .pdata 00013028..0001309f. Semantic name remains unreviewed. */

void FUN_00013028(undefined4 param_1)

{
  undefined4 local_10 [2];
  
  local_10[0] = param_1;
  DbgDebugPrint(6,0,L"%S set pos %d ms","app_set_track_pos_msec",param_1);
  FUN_0001eaac(DAT_0016ca78,0x11464,0,local_10,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 000130a0 FUN_000130a0 */

/* Boundary evidence: original MIPS .pdata 000130a0..000130ef. Semantic name remains unreviewed. */

void FUN_000130a0(void)

{
  FUN_0001d314(DAT_0016ca78,0x157bc,10,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  FUN_00011f34(0xf0);
  return;
}



/* 000130f0 FUN_000130f0 */

/* Boundary evidence: original MIPS .pdata 000130f0..00013163. Semantic name remains unreviewed. */

void FUN_000130f0(int param_1)

{
  FUN_0001d314(DAT_0016ca78,0x157bc,1,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  if (param_1 == 0) {
    FUN_00011f80(0xf0);
  }
  else {
    FUN_00011f34(0xf0);
  }
  return;
}



/* 00013164 FUN_00013164 */

/* Boundary evidence: original MIPS .pdata 00013164..0001323f. Semantic name remains unreviewed. */

void FUN_00013164(void)

{
  if (DAT_0016bda0 == 1) {
    if (DAT_0016bde8 == 1) {
      FUN_0001d314(DAT_0016ca78,0x157bc,1,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
      FUN_00011f80(0xf0);
      FUN_00011bf0();
    }
    else {
      DbgDebugPrint(6,1,L"%S g_stPlayInfo.ucPlayerStatus is not playing status %d","app_ipod_pause",
                    DAT_0016bde8);
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_ipod_pause");
  }
  return;
}



/* 00013240 FUN_00013240 */

/* Boundary evidence: original MIPS .pdata 00013240..000132c3. Semantic name remains unreviewed. */

void FUN_00013240(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 1;
  puVar1 = &DAT_0016be00;
  do {
    FUN_000120a0(uVar2 & 0xff);
    *puVar1 = DAT_0002d298;
    Sleep(10);
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 + 1;
  } while ((int)puVar1 < 0x16be1c);
  return;
}



/* 000132c4 FUN_000132c4 */

/* Boundary evidence: original MIPS .pdata 000132c4..000132e3. Semantic name remains unreviewed. */

undefined4 FUN_000132c4(void)

{
  FUN_000129d0();
  return 0;
}



/* 000132e4 FUN_000132e4 */

/* Boundary evidence: original MIPS .pdata 000132e4..0001336b. Semantic name remains unreviewed. */

void FUN_000132e4(void)

{
  HANDLE hObject;
  
  if (DAT_0016caa4 == 1) {
    DbgDebugPrint(6,1,L"%S current is artwork locking status","app_fetch_album_artwork");
  }
  else {
    DAT_0016caa4 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000132c4,(LPVOID)0x0,0,(LPDWORD)0x0);
    CloseHandle(hObject);
  }
  return;
}



/* 0001336c FUN_0001336c */

/* Boundary evidence: original MIPS .pdata 0001336c..00013447. Semantic name remains unreviewed. */

void FUN_0001336c(void)

{
  if (DAT_0016bda0 == 1) {
    FUN_000111e4();
    DbgDebugPrint(6,0,L"%S curPlay idx %d","app_request_track_info",DAT_0016bdf4);
    if (-1 < DAT_0016bdf4) {
      if (DAT_0002d15c == DAT_0016bdf4) {
        FUN_000117ec(DAT_0016bdf4);
      }
      else {
        DAT_0002d15c = DAT_0016bdf4;
        FUN_00011764(DAT_0016bdf4);
        FUN_000117ec(DAT_0016bdf4);
        FUN_000132e4();
      }
    }
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_request_track_info");
  }
  return;
}



/* 00013448 FUN_00013448 */

/* Boundary evidence: original MIPS .pdata 00013448..00013697. Semantic name remains unreviewed. */

void FUN_00013448(uint param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 5) {
    DAT_0002d15c = 0xffffffff;
  }
  else {
    FUN_000120a0(param_1 & 0xff);
    FUN_00012010(param_1 & 0xff,param_2);
    if (param_1 == 7) {
      if (param_2 != 0) goto LAB_00013530;
      FUN_000120a0(7);
      FUN_00012010(7,0);
      DAT_0016cb08 = DAT_0002d298;
      FUN_00011764(0);
      FUN_0001336c();
      FUN_000132e4();
    }
  }
  if (param_1 == 1) {
LAB_00013668:
    uVar1 = 5;
  }
  else {
    uVar1 = 2;
    if (param_1 != 2) {
      if (param_1 == 3) goto LAB_00013668;
      if (param_1 == 4) goto LAB_0001366c;
      if (param_1 == 5) {
        FUN_000110bc(param_2);
        FUN_00011268();
        FUN_000111e4();
        if (((DAT_0016c61c != '\0') || (DAT_0016c61d != '\0')) || (DAT_0016c61e != '\0')) {
          memset(&DAT_0016c61c,0,0x400);
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x70,0,0);
        }
        if (DAT_0016cadc == 0) {
          DAT_0016cafc = 0;
          FUN_00011f34(0xf0);
          FUN_00011bf0();
        }
        else {
          FUN_00011d1c();
          if (DAT_0016bde8 == 1) {
            FUN_000130f0(0);
          }
        }
        SetTimer(DAT_0016cac4,0x3ed,2000,(TIMERPROC)0x0);
        return;
      }
      if (param_1 != 6) {
LAB_00013530:
        DbgDebugPrint(0x15,3,L"%S check current ipod category %d","app_enter_category_db",param_1);
        return;
      }
    }
    uVar1 = 3;
  }
LAB_0001366c:
  FUN_000120f0(uVar1,0);
  return;
}



/* 00013698 FUN_00013698 */

/* Boundary evidence: original MIPS .pdata 00013698..00013817. Semantic name remains unreviewed. */

void FUN_00013698(void)

{
  undefined4 uVar1;
  
  if (DAT_0016bdf4 != -1) {
    FUN_00011d1c();
    if (DAT_0016bda8 != 0) {
      return;
    }
    DAT_0016bda8 = 1;
    if (DAT_0016cabc == '\x04') {
      NKDbgPrintfW(L">> [ERROR] IPOD_ACK_BAD! ipod_rebuildlist\r\n");
      uVar1 = DAT_0016cb04;
      FUN_00012010(5,DAT_0016bdf4);
      FUN_00013028(uVar1);
      FUN_00011764(DAT_0016bdf4);
      FUN_000132e4();
      return;
    }
    if (DAT_0016cabc == '\0') {
      DAT_0016bda8 = 1;
      return;
    }
    NKDbgPrintfW(L">> [error] g_ipod_staus %d\r\n",DAT_0016cabc);
    return;
  }
  DbgDebugPrint(6,3,L"%S g_stPlayInfo.nCurPlayIdx %d","app_ipod_rebuildlist",0xffffffff);
  FUN_000111e4();
  if (DAT_0016bdf4 == -1) {
    FUN_0001115c(0);
    FUN_000111e4();
    if (DAT_0016bdf4 == -1) {
      if (DAT_0016be10 == 0) {
        if (DAT_0016be18 == 0) goto LAB_00013764;
        FUN_000120a0(7);
        uVar1 = 7;
      }
      else {
        FUN_000120a0(5);
        uVar1 = 5;
      }
      FUN_00012010(uVar1,0);
    }
  }
  else {
    FUN_00011268();
  }
LAB_00013764:
  FUN_0001336c();
  return;
}



/* 00013818 FUN_00013818 */

/* Boundary evidence: original MIPS .pdata 00013818..00013993. Semantic name remains unreviewed. */

void FUN_00013818(void)

{
  DbgDebugPrint(6,1,&DAT_00028130,"app_ipod_resume");
  if (DAT_0016bda0 == 1) {
    if (DAT_0016bde8 == 1) {
      DbgDebugPrint(6,3,L"%S g_stPlayInfo.ucPlayerStatus is playing","app_ipod_resume");
    }
    else {
      FUN_0001d314(0,0x15848,0xe,0);
      WaitForSingleObject(DAT_0016ca94,0xffffffff);
      if (DAT_0002d288 == 0) {
        FUN_0001d314(DAT_0016ca78,0x157bc,1,0);
        WaitForSingleObject(DAT_0016ca94,0xffffffff);
      }
    }
    DbgDebugPrint(6,3,L"%S g_stPlayInfo.nCurPlayIdx %d","app_ipod_resume",DAT_0016bdf4);
    FUN_00013698();
    FUN_00011f34(0xf0);
    FUN_00011bf0();
  }
  else {
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode == FALSE","app_ipod_resume");
  }
  return;
}



/* 00013994 FUN_00013994 */

void FUN_00013994(undefined4 param_1)

{
  DAT_0016ca6c = param_1;
  return;
}



/* 000139a4 FUN_000139a4 */

void FUN_000139a4(undefined2 param_1,undefined1 param_2)

{
  DAT_0016ca70 = param_1;
  DAT_0016ca72 = param_2;
  return;
}



/* 000139b8 FUN_000139b8 */

undefined2 * FUN_000139b8(void)

{
  return &DAT_0016ca70;
}



/* 000139c8 FUN_000139c8 */

void FUN_000139c8(undefined1 param_1)

{
  DAT_0016ca74 = param_1;
  return;
}



/* 000139d4 FUN_000139d4 */

/* Boundary evidence: original MIPS .pdata 000139d4..000139fb. Semantic name remains unreviewed. */

void FUN_000139d4(void)

{
  DAT_0016ca80 = 0;
  FUN_0001c5b8(DAT_0016ca78);
  return;
}



/* 000139fc FUN_000139fc */

/* Boundary evidence: original MIPS .pdata 000139fc..00013a53. Semantic name remains unreviewed. */

void FUN_000139fc(void)

{
  int iVar1;
  
  DAT_0016ca80 = 0;
  iVar1 = FUN_0001c2e4(DAT_0016ca78);
  if (iVar1 != 0) {
    DbgDebugPrint(6,3,L"[ERROR] %S uwhu_ipod_da_prepare_audio_read %d %d\n","prepare_digital_audio",
                  iVar1);
  }
  return;
}



/* 00013a54 FUN_00013a54 */

/* Boundary evidence: original MIPS .pdata 00013a54..00013c9b. Semantic name remains unreviewed. */

void FUN_00013a54(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_0016ca74;
  if (uVar2 == 0xf) goto LAB_00013b38;
  if (DAT_0016ca80 == 0) {
    iVar1 = FUN_0001c35c(DAT_0016ca78,100,0x16344,0);
    if (iVar1 == 0) {
      DAT_0016ca80 = 1;
    }
    else {
      if (iVar1 == 8) {
        if (DAT_0016caf0 == 0) {
          return;
        }
        SetTimer(DAT_0016cac4,0xc90,10,(TIMERPROC)0x0);
        return;
      }
      DAT_0016ca80 = 0;
      DbgDebugPrint(6,3,L"[ERROR] %S ipod_da_START_audio_read g_bAudioStartFlag %d %d\n",
                    "request_digital_audio",0,0xcb);
    }
    WaitForSingleObject(DAT_0016ca94,0xffffffff);
    if (DAT_0016ca7c == 0) {
      iVar1 = FUN_0001c1f4(DAT_0016ca78);
      if ((iVar1 != 0) && (iVar1 != 10)) goto LAB_00013b2c;
      DAT_0016ca7c = 1;
    }
    else {
      if (DAT_0016ca80 != 0) {
        uVar2 = (uint)DAT_0016ca74;
        goto LAB_00013b38;
      }
      FUN_0001c26c(DAT_0016ca78);
LAB_00013af4:
      DAT_0016ca7c = 0;
    }
  }
  else {
    if (DAT_0016ca7c != 0) {
      DbgDebugPrint(6,3,L"[ERROR]%S uwhu_audio_dev_open !!! g_bWaveOpenFlag %d\n",
                    "request_digital_audio",DAT_0016ca7c);
LAB_00013b2c:
      uVar2 = (uint)DAT_0016ca74;
      goto LAB_00013b38;
    }
    iVar1 = FUN_0001c1f4(DAT_0016ca78);
    if (iVar1 != 0) {
      if (iVar1 != 10) {
        iVar1 = FUN_0001c1f4(DAT_0016ca78);
      }
      if ((iVar1 != 0) && (iVar1 != 10)) goto LAB_00013af4;
    }
    DAT_0016ca7c = 1;
  }
  uVar2 = (uint)DAT_0016ca74;
LAB_00013b38:
  DAT_0016ca74 = (byte)(uVar2 | param_1);
  DbgDebugPrint(6,2,
                L"%S request_digital_audio_g_fDigitalAudio_0x%02x %d [g_bWaveOpenFlag %d, g_bAudioStartFlag %d]\n"
                ,"request_digital_audio",uVar2 | param_1,0xe5,DAT_0016ca7c,DAT_0016ca80);
  return;
}



/* 00013c9c FUN_00013c9c */

/* Boundary evidence: original MIPS .pdata 00013c9c..00013e2b. Semantic name remains unreviewed. */

void FUN_00013c9c(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 == 0) || ((uVar2 = (uint)DAT_0016ca74, param_1 == 0xf0 && (uVar2 == 0)))) ||
     ((param_1 == 0xf && (uVar2 == 0)))) {
    if (DAT_0016ca7c != 0) {
      iVar1 = FUN_0001c26c(DAT_0016ca78);
      DAT_0016ca7c = 0;
      if (iVar1 != 0) {
        DbgDebugPrint(6,3,L"[*ERROR*] 111 %S ! (ret_%d | %d)","release_digital_audio",iVar1,0);
      }
    }
    DAT_0016ca74 = 0;
  }
  else {
    if ((uVar2 == param_1) && (DAT_0016ca7c != 0)) {
      iVar1 = FUN_0001c26c(DAT_0016ca78);
      if (iVar1 != 0) {
        iVar1 = FUN_0001c26c(DAT_0016ca78);
        DbgDebugPrint(6,3,L"[*ERROR*] 222 %S ! (ret_%d | %d)","release_digital_audio",iVar1,
                      DAT_0016ca7c);
      }
      uVar2 = (uint)DAT_0016ca74;
      DAT_0016ca7c = 0;
    }
    DAT_0016ca74 = (byte)(uVar2 ^ param_1);
    DbgDebugPrint(6,2,
                  L"%S release_digital_audio_g_fDigitalAudio_0x%02x %d [g_bWaveOpenFlag %d, g_bAudioStartFlag %d]"
                  ,"release_digital_audio",(uVar2 ^ param_1) & 0xff,0x10b,DAT_0016ca7c,DAT_0016ca80)
    ;
  }
  return;
}



/* 00013e2c FUN_00013e2c */

void FUN_00013e2c(undefined4 param_1)

{
  DAT_0016ca54 = param_1;
  return;
}



/* 00013e3c FUN_00013e3c */

undefined4 FUN_00013e3c(void)

{
  return DAT_0016ca54;
}



/* 00013e4c FUN_00013e4c */

/* Boundary evidence: original MIPS .pdata 00013e4c..00013e97. Semantic name remains unreviewed. */

void FUN_00013e4c(undefined4 param_1,undefined2 param_2,undefined4 *param_3)

{
  DAT_0016ca60 = param_1;
  DAT_0016ca64 = param_2;
  if (param_3 == (undefined4 *)0x0) {
    memset(&DAT_0016ca66,0,4);
  }
  else {
    DAT_0016ca66 = *param_3;
  }
  return;
}



/* 00013e98 FUN_00013e98 */

/* Boundary evidence: original MIPS .pdata 00013e98..00013ef7. Semantic name remains unreviewed. */

void FUN_00013e98(void)

{
  DbgDebugPrint(6,0,L"%S(%d): keepMsg_%d, AppLink_%d, InitFlag_%d\n","send_ip2c_keeping_msg",0x14b,
                DAT_0016ca60,DAT_0016ca50,DAT_0016ca54);
  return;
}



/* 00013ef8 FUN_00013ef8 */

undefined4 FUN_00013ef8(void)

{
  return DAT_0016ca50;
}



/* 00013f08 FUN_00013f08 */

undefined4 FUN_00013f08(void)

{
  return DAT_0016ca24;
}



/* 00013f14 FUN_00013f14 */

/* Boundary evidence: original MIPS .pdata 00013f14..00013faf. Semantic name remains unreviewed. */

void FUN_00013f14(undefined4 param_1,void *param_2,uint param_3)

{
  size_t _Size;
  
  DAT_0016ca24 = param_1;
  memset(&DAT_0016ca28,0,0xc);
  _Size = 0xb;
  if (param_3 < 0xc) {
    _Size = param_3;
  }
  memcpy(&DAT_0016ca28,param_2,_Size);
  DbgDebugPrint(6,2,L"%S ModelNum_%S, ModelID_%d\n","set_model_info",param_2,DAT_0016ca24);
  return;
}



/* 00013fb0 FUN_00013fb0 */

void FUN_00013fb0(undefined4 param_1)

{
  DAT_0016ca34 = param_1;
  return;
}



/* 00013fc0 FUN_00013fc0 */

undefined4 FUN_00013fc0(void)

{
  return DAT_0016ca34;
}



/* 00013fd0 FUN_00013fd0 */

void FUN_00013fd0(undefined4 param_1)

{
  DAT_0016ca38 = param_1;
  return;
}



/* 00013fe0 FUN_00013fe0 */

undefined4 FUN_00013fe0(void)

{
  return DAT_0016ca38;
}



/* 00013ff0 FUN_00013ff0 */

/* Boundary evidence: original MIPS .pdata 00013ff0..0001402f. Semantic name remains unreviewed. */

void FUN_00013ff0(void)

{
  FUN_0001ca24(0,0x16b40,0);
  WaitForSingleObject(DAT_0016ca94,0xffffffff);
  return;
}



/* 00014030 FUN_00014030 */

void FUN_00014030(undefined4 param_1)

{
  DAT_0016ca3c = param_1;
  return;
}



/* 00014040 FUN_00014040 */

void FUN_00014040(undefined4 param_1)

{
  DAT_0016ca48 = param_1;
  return;
}



/* 00014050 FUN_00014050 */

undefined4 FUN_00014050(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*param_2 < *param_1) {
LAB_00014064:
    uVar1 = 1;
  }
  else {
    if (*param_1 == *param_2) {
      if (param_2[1] < param_1[1]) goto LAB_00014064;
      if ((param_1[1] == param_2[1]) && (param_2[2] <= param_1[2])) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 000140b0 FUN_000140b0 */

/* Boundary evidence: original MIPS .pdata 000140b0..000141eb. Semantic name remains unreviewed. */

void FUN_000140b0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint local_18 [2];
  
  DAT_0002d15c = 0xffffffff;
  DAT_0016bda4 = 0;
  DAT_0016bda0 = 0;
  DAT_0016bda8 = 0;
  DAT_0016ca7c = 0;
  DAT_0016ca80 = 0;
  DAT_0016cb00 = 0;
  DAT_0016ca78 = param_1;
  if ((DAT_0016cad4 == 0) && (DAT_0016cad0 == 0)) {
    memset(local_18,0,4);
    if (param_2 == 0) {
      uVar1 = local_18[0] & 0xfffff124 | 0x124;
    }
    else {
      uVar1 = local_18[0] & 0xfffff024 | 0x24;
    }
    local_18[0] = uVar1 & 0xfff01fff | 0x1000;
    IpcPostMsg(6,1,9,4,local_18);
    DAT_0016cad0 = 0;
  }
  DbgDebugPrint(6,1,L"%S uw_status 0x%x","hw_attach_notif",param_2);
  return;
}



/* 000141ec FUN_000141ec */

/* Boundary evidence: original MIPS .pdata 000141ec..00014333. Semantic name remains unreviewed. */

void FUN_000141ec(undefined4 param_1,int param_2,char *param_3)

{
  DbgDebugPrint(6,0,L"%S event_type %d","remote_event_notification",param_2);
  if (param_2 == 7) {
    if (*param_3 != DAT_0002d216) {
      DbgDebugPrint(6,3,L"%S shuffle changed %d","remote_event_notification",*param_3);
      DAT_0002d216 = *param_3;
      IpcPostMsg(6,0x15,0x6b,1,&DAT_0002d216);
    }
  }
  else if ((param_2 == 8) && (*param_3 != DAT_0002d215)) {
    DbgDebugPrint(6,3,L"%S repeat changed %d","remote_event_notification",*param_3);
    DAT_0002d215 = *param_3;
    IpcPostMsg(6,0x15,0x6c,1,&DAT_0002d215);
  }
  return;
}



/* 00014334 FUN_00014334 */

/* Boundary evidence: original MIPS .pdata 00014334..000143eb. Semantic name remains unreviewed. */

void FUN_00014334(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint local_10 [2];
  
  DAT_0016ca78 = param_1;
  DbgDebugPrint(6,1,L"%S result code 0x%02X, inoperable_lingoes_0x%02x","soft_attach_notif",param_3,
                param_2);
  if (param_3 == 0xb) {
    NKDbgPrintfW(L">> NOT supported Device !! \r\n");
    memset(local_10,0,4);
    local_10[0] = local_10[0] & 0xfff01f04 | 0x1004;
    IpcPostMsg(6,1,9,4,local_10);
  }
  return;
}



/* 000143ec FUN_000143ec */

/* Boundary evidence: original MIPS .pdata 000143ec..0001458f. Semantic name remains unreviewed. */

void FUN_000143ec(undefined4 param_1,undefined4 param_2)

{
  uint local_18 [2];
  
  DAT_0016cadc = 0;
  DAT_0016bda4 = 0;
  DAT_0016cae0 = 0;
  DAT_0016cae4 = 0;
  DAT_0016cae8 = 0;
  FUN_000139c8(0);
  FUN_00011f80(0);
  FUN_000139d4();
  DAT_0016cad0 = 0;
  DAT_0002d155 = 2;
  DAT_0016bdac = 0;
  DAT_0016cb0c = 0;
  DAT_0016ca7c = 0;
  DAT_0016bdb0 = 0;
  DAT_0016cb10 = 0;
  DAT_0016bda0 = 0;
  DAT_0016ca80 = 0;
  DAT_0016cb00 = 0;
  DbgDebugPrint(6,1,L"%S uw_status %d","detach_notif",param_2);
  local_18[0] = local_18[0] & 0xfff01f04 | 0x1004;
  IpcPostMsg(6,1,9,4,local_18);
  FUN_00013e2c(0);
  DAT_0002d15c = 0xffffffff;
  if (DAT_0016ca1c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0016ca1c);
  }
  DAT_0016ca1c = (HGDIOBJ)0x0;
  if (DAT_0016caa8 != (void *)0x0) {
    free(DAT_0016caa8);
    DAT_0016caa8 = (void *)0x0;
  }
  memset(&DAT_0016bdc8,0,0xc5c);
  MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
  return;
}



/* 00014590 FUN_00014590 */

/* Boundary evidence: original MIPS .pdata 00014590..000146b3. Semantic name remains unreviewed. */

void FUN_00014590(undefined4 param_1,int param_2,int param_3)

{
  uint local_18 [2];
  
  KillTimer(DAT_0016cac4,0xc8e);
  DAT_0016cafc = 0;
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,1,L"%S auth_notif success","auth_notif");
    DAT_0016bda4 = 1;
    IpcPostMsg(6,6,1000,0,0);
  }
  else {
    memset(local_18,0,4);
    local_18[0] = local_18[0] & 0xfff01f04 | 0x1004;
    IpcPostMsg(6,1,9,4,local_18);
    DbgDebugPrint(6,1,L"%S auth_notif fail ipod_status 0x%x error code 0x%x","auth_notif",param_2,
                  param_3);
  }
  return;
}



/* 000146b4 FUN_000146b4 */

/* Boundary evidence: original MIPS .pdata 000146b4..00014713. Semantic name remains unreviewed. */

void FUN_000146b4(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x error code 0x%x","select_db_record_cb",param_2,
                  param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00014714 FUN_00014714 */

/* Boundary evidence: original MIPS .pdata 00014714..000147af. Semantic name remains unreviewed. */

void FUN_00014714(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002d298 = param_4;
    DAT_0016a8d8 = param_4;
    DAT_0016ca90 = param_4;
    if (5000 < param_4) {
      DAT_0002d298 = 5000;
    }
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S g_stReqCat %d record count %d ipod_status 0x%x error code 0x%x",
                  "get_num_categorized_db_records_cb",DAT_0002d158,param_4,param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 000147b0 FUN_000147b0 */

/* Boundary evidence: original MIPS .pdata 000147b0..000148e7. Semantic name remains unreviewed. */

void FUN_000147b0(undefined4 param_1,int param_2,int param_3,uint param_4,void *param_5,
                 ushort param_6,int param_7)

{
  size_t _Size;
  
  if ((param_3 == 0) && (param_2 == 0)) {
    DAT_0016bdc0 = 0;
    if (param_4 < 5000) {
      _Size = (size_t)param_6;
      if (0x103 < _Size) {
        _Size = 0x103;
      }
      memcpy(&DAT_0002d2a0 + param_4 * 0x104,param_5,_Size);
    }
  }
  else {
    DAT_0016bdc0 = 1;
    DbgDebugPrint(6,1,L"%S ipod_status 0x%x error code 0x%x, record_len %d, more_to_follow %d",
                  "categorized_records_cb",param_2,param_3,param_6,param_7);
  }
  if ((param_4 == DAT_0016ca90 - 1U) || (param_7 != 1)) {
    MSHM_Dll_Write(DAT_0016bd9c,&DAT_0002d298,0,&DAT_0013d628);
    EventModify(DAT_0016ca94,3);
  }
  return;
}



/* 000148e8 FUN_000148e8 */

/* Boundary evidence: original MIPS .pdata 000148e8..00015317. Semantic name remains unreviewed. */

void FUN_000148e8(undefined4 param_1,int param_2,uint *param_3)

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
                  "play_state_changed_notif",DAT_0002d15c);
    if (DAT_0002d28c == '\a') {
      if (DAT_0002d215 == '\x02') {
        if ((DAT_0016cb08 - 1U <= DAT_0016bdf4) || (DAT_0016bdf4 != 0)) {
          local_b0[0] = local_b0[0] & 0xff000007 | 7;
          IpcPostMsg(0x15,6,0x75,4,local_b0);
          return;
        }
      }
      else if (DAT_0002d215 == '\x01') {
        local_b0[0] = (DAT_0016bdf4 & 0xffff) << 8 | local_b0[0] & 0xff000007 | 7;
        IpcPostMsg(0x15,6,0x75,4,local_b0);
        return;
      }
    }
    DAT_0002d15c = 0xffffffff;
    DAT_0016caac = 1;
    if (DAT_0016bd98 == 0) {
      DAT_0002d15c = 0xffffffff;
      DAT_0016caac = 1;
      return;
    }
    DAT_0016bde8 = 0;
    puVar1 = FUN_0001131c(auStack_38,*param_3);
    local_a8 = *puVar1;
    local_a4 = puVar1[1];
    local_a0 = puVar1[2];
    local_9c = puVar1[3];
    iVar2 = FUN_00014050(&DAT_0016bdc8,&local_a8);
    if (iVar2 != 0) {
      DAT_0016bdd8 = DAT_0016bdc8;
      DAT_0016bddc = DAT_0016bdcc;
      DAT_0016bde0 = DAT_0016bdd0;
      DAT_0016bde4 = DAT_0016bdd4;
    }
    DAT_0016cb04 = *param_3;
    MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
    DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_STOPPED play_state %d cur playing idx %d",
                  "play_state_changed_notif",0,DAT_0016bdf4);
    IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
    if (iVar2 == 0) {
      return;
    }
    IpcPostMsg(6,0x15,0x72,0,0);
    return;
  }
  if (param_2 == 1) {
    DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_CHANGED  g_iReadInfoTrack %d g_bStoped %d",
                  "play_state_changed_notif",DAT_0002d15c,DAT_0016caac);
    DAT_0002d15c = 0xffffffff;
    if (DAT_0016caac != 0) {
      DAT_0016caac = 0;
    }
    if (DAT_0016bdac != 0) {
      IpcPostMsg(6,6,0x3ef,0,0);
    }
    if (DAT_0016cb0c == 1) {
      NKDbgPrintfW(L"~!@# UWH_IPOD_EXT_PLAYBACK_TRACK_CHANGED g_bTrackJumpStart [%d]\r\n",1);
      return;
    }
    if (DAT_0016bd98 == 0) {
      return;
    }
    DAT_0016bdf4 = *param_3;
    if (DAT_0016caec == 0) {
      DAT_0016cb1c = *param_3;
    }
    else {
      NKDbgPrintfW(L"~!@# 1111 Opss!!!! [%d]->[%d]\r\n",DAT_0016cb1c,*param_3);
    }
    KillTimer(DAT_0016cac4,0x3ed);
    IpcPostMsg(6,6,0x3f0,0,0);
    return;
  }
  if (param_2 < 2) {
LAB_00014f30:
    DbgDebugPrint(6,3,L"%S Not definced  play_state %d","play_state_changed_notif",param_2);
  }
  else {
    if (param_2 < 4) {
      if ((param_2 == 2) && (DAT_0016bdac != 0)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      else if ((param_2 == 3) && (DAT_0016bdb0 != 0)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      if (DAT_0016bd98 == 0) {
        return;
      }
      puVar1 = FUN_0001131c(auStack_78,*param_3);
      local_a8 = *puVar1;
      local_a4 = puVar1[1];
      local_a0 = puVar1[2];
      local_9c = puVar1[3];
      iVar2 = FUN_00014050(&DAT_0016bdc8,&local_a8);
      if (iVar2 != 0) {
        puVar1 = FUN_0001131c(auStack_58,*param_3);
        DAT_0016bdd8 = *puVar1;
        DAT_0016bddc = puVar1[1];
        DAT_0016bde0 = puVar1[2];
        DAT_0016bde4 = puVar1[3];
      }
      DAT_0016cb04 = *param_3;
      MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
      DbgDebugPrint(6,0,L"%S play_state %d cur playing idx %d","play_state_changed_notif",
                    DAT_0016bdf4);
      DbgDebugPrint(6,0,L"%S %d, set pos %d ms","play_state_changed_notif",0x24c,*param_3);
      IpcPostMsg(6,0x15,0x72,0,0);
      return;
    }
    if (param_2 == 4) {
      if ((DAT_0016bdb0 != 0) && (*param_3 < 500)) {
        IpcPostMsg(6,6,0x3eb,0,0);
      }
      if (DAT_0016bd98 != 0) {
        puVar1 = FUN_0001131c(auStack_68,*param_3);
        local_a8 = *puVar1;
        local_a4 = puVar1[1];
        local_a0 = puVar1[2];
        local_9c = puVar1[3];
        iVar2 = FUN_00014050(&DAT_0016bdc8,&local_a8);
        if (iVar2 == 0) {
          return;
        }
        puVar1 = FUN_0001131c(auStack_48,*param_3);
        local_9c = puVar1[3];
        if (((DAT_0016bdd8 == *puVar1) && (DAT_0016bddc == puVar1[1])) &&
           (DAT_0016bde0 == puVar1[2])) {
          return;
        }
        if (DAT_0016cb10 != 0) {
          *param_3 = 0;
          DAT_0016cb04 = 0;
          puVar1 = FUN_0001131c(auStack_98,0);
          DAT_0016bdd8 = *puVar1;
          DAT_0016bddc = puVar1[1];
          DAT_0016bde0 = puVar1[2];
          DAT_0016bde4 = puVar1[3];
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x72,0,0);
        }
        puVar1 = FUN_0001131c(auStack_88,*param_3);
        DAT_0016bdd8 = *puVar1;
        DAT_0016bddc = puVar1[1];
        DAT_0016bde0 = puVar1[2];
        DAT_0016bde4 = puVar1[3];
        DAT_0016cb04 = *param_3;
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        DbgDebugPrint(6,0,L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_POS play_state %d/%d cur playing idx %d",
                      "play_state_changed_notif",DAT_0016bde8,4,DAT_0016bdf4);
        DbgDebugPrint(6,0,L"%S %d set pos %d ms","play_state_changed_notif",0x2b4,*param_3);
        IpcPostMsg(6,0x15,0x72,0,0);
        return;
      }
      pwVar4 = L"%S UWH_IPOD_EXT_PLAYBACK_TRACK_POS g_ocsharedMemory == NULL";
      uVar3 = 0;
    }
    else {
      if (param_2 != 5) {
        if (param_2 == 6) {
          DbgDebugPrint(6,0,
                        L"%S UWH_IPOD_EXT_PLAYBACK_EXT_STATUS_CHANGED g_ucExtPlayStatus %d, play_state %d, g_bStoped %d, g_stPlayInfo.ucPlayerStatus %d, ext_play_state [%d]"
                        ,"play_state_changed_notif",DAT_0002d155,6,DAT_0016caac,DAT_0016bde8,
                        (char)*param_3);
          if (DAT_0016caac == 1) {
            if (DAT_0016bde8 == 0) {
              if (DAT_0002d155 == '\v') {
                DAT_0016bde8 = 2;
              }
              else if (DAT_0002d155 == '\x02') {
                DAT_0016bde8 = 0;
              }
              MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
              IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
            }
            else {
              IpcPostMsg(6,6,0x3f0,0,0);
              DAT_0016caac = 0;
            }
          }
          DAT_0002d155 = (char)*param_3;
          IpcPostMsg(6,6,0x3ee,0,0);
          return;
        }
        goto LAB_00014f30;
      }
      uVar3 = 3;
      if (DAT_0016bd98 != 0) {
        DAT_0016bdf8 = *param_3;
        DbgDebugPrint(6,3,L"%S UWH_IPOD_EXT_PLAYBACK_CHAPTER_CHANGED chapter %d, record idx %d",
                      "play_state_changed_notif",DAT_0016bdf8,DAT_0016bdf4);
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x6a,0,0);
        return;
      }
      pwVar4 = L"%S UWH_IPOD_EXT_PLAYBACK_CHAPTER_CHANGED g_ocsharedMemory == NULL";
    }
    DbgDebugPrint(6,uVar3,pwVar4,"play_state_changed_notif");
  }
  return;
}



/* 00015318 FUN_00015318 */

/* Boundary evidence: original MIPS .pdata 00015318..0001534f. Semantic name remains unreviewed. */

void FUN_00015318(undefined4 param_1,undefined1 *param_2)

{
  DbgDebugPrint(6,3,L"general_evnet_notification: event type 0x%x\r\n",*param_2);
  return;
}



/* 00015350 FUN_00015350 */

/* Boundary evidence: original MIPS .pdata 00015350..00015387. Semantic name remains unreviewed. */

void FUN_00015350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DbgDebugPrint(6,3,L"===> general_set_accessory_status_notifitcation: mask 0x%x, tid 0x%x\r\n",
                param_2,param_3);
  return;
}



/* 00015388 FUN_00015388 */

/* Boundary evidence: original MIPS .pdata 00015388..000154bb. Semantic name remains unreviewed. */

void FUN_00015388(undefined4 param_1,int param_2,undefined4 param_3)

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



/* 000154bc FUN_000154bc */

/* Boundary evidence: original MIPS .pdata 000154bc..000155a7. Semantic name remains unreviewed. */

void FUN_000154bc(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,0,L"%S enter_remote_ui_cb ipod status 0x%x result 0x%x","enter_remote_ui_cb",
                param_2,param_3);
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016bda0 = 1;
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode %d","enter_remote_ui_cb",1);
  }
  else {
    DbgDebugPrint(6,1,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","enter_remote_ui_cb",param_2,
                  param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca98,3);
  return;
}



/* 000155a8 FUN_000155a8 */

/* Boundary evidence: original MIPS .pdata 000155a8..00015687. Semantic name remains unreviewed. */

void FUN_000155a8(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,0,L"%S exit_remote_ui_cb ipod status 0x%x result 0x%x","exit_remote_ui_cb",param_2
                ,param_3);
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016bda0 = 0;
    DbgDebugPrint(6,1,L"%S g_bRemoteUIMode %d","exit_remote_ui_cb",0);
  }
  else {
    DbgDebugPrint(6,1,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","exit_remote_ui_cb",param_2,
                  param_3);
  }
  EventModify(DAT_0016ca98,3);
  return;
}



/* 00015688 FUN_00015688 */

/* Boundary evidence: original MIPS .pdata 00015688..000156e7. Semantic name remains unreviewed. */

void FUN_00015688(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","set_notify_cb",param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 000156e8 FUN_000156e8 */

/* Boundary evidence: original MIPS .pdata 000156e8..0001575b. Semantic name remains unreviewed. */

void FUN_000156e8(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","set_notify_mask_cb",param_2,
                  param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 0001575c FUN_0001575c */

/* Boundary evidence: original MIPS .pdata 0001575c..000157bb. Semantic name remains unreviewed. */

void FUN_0001575c(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","reset_db_cb",param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 000157bc FUN_000157bc */

/* Boundary evidence: original MIPS .pdata 000157bc..00015847. Semantic name remains unreviewed. */

void FUN_000157bc(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016cab0 = 0;
  }
  else {
    DAT_0016cab0 = 1;
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x result 0x%x","play_control_cb",param_2,param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015848 FUN_00015848 */

/* Boundary evidence: original MIPS .pdata 00015848..000158df. Semantic name remains unreviewed. */

void FUN_00015848(undefined4 param_1,int param_2,int param_3)

{
  DbgDebugPrint(6,3,L"%S ipod status 0x%x result 0x%x","play_control_enforce_ipod_music_cb",param_2,
                param_3);
  if ((param_2 == 4) || (param_3 != 0)) {
    DAT_0002d288 = 0;
  }
  else {
    DAT_0002d288 = 1;
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 000158e0 FUN_000158e0 */

/* Boundary evidence: original MIPS .pdata 000158e0..00015bdb. Semantic name remains unreviewed. */

void FUN_000158e0(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5,byte param_6)

{
  uint *puVar1;
  uint auStack_38 [4];
  
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,0,L"%S ipod status 0x%x uw_status 0x%x play_state 0x%x","get_play_status_cb",0,0
                  ,param_6);
    if (DAT_0016bd98 == 0) {
      DbgDebugPrint(6,3,L"%S g_ocsharedMemory NULL","get_play_status_cb");
    }
    else {
      if ((DAT_0016ca80 == 1) && (DAT_0016ca7c == 1)) {
        DAT_0016bde8 = 1;
      }
      else {
        DAT_0016bde8 = (ushort)param_6;
      }
      MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
      if (DAT_0016cb10 != 0) {
        DAT_0016cb04 = 0;
        param_5 = 0;
        puVar1 = FUN_0001131c(auStack_38,0);
        DAT_0016bdd8 = *puVar1;
        DAT_0016bddc = puVar1[1];
        DAT_0016bde0 = puVar1[2];
        DAT_0016bde4 = puVar1[3];
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x72,0,0);
      }
      if (param_5 <= param_4) {
        puVar1 = FUN_0001131c(auStack_38,param_4);
        DAT_0016bdc8 = *puVar1;
        DAT_0016bdcc = puVar1[1];
        DAT_0016bdd0 = puVar1[2];
        DAT_0016bdd4 = puVar1[3];
        puVar1 = FUN_0001131c(auStack_38,param_5);
        DAT_0016bdd8 = *puVar1;
        DAT_0016bddc = puVar1[1];
        DAT_0016bde0 = puVar1[2];
        DAT_0016bde4 = puVar1[3];
        DAT_0016cb04 = param_5;
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        DbgDebugPrint(6,0,L"%S %d, set pos %d ms","get_play_status_cb",0x413,param_5);
        IpcPostMsg(6,0x15,0x72,0,0);
      }
    }
    DAT_0016bdb8 = 1;
  }
  else {
    DAT_0016bdb8 = 0;
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x previous play_state 0x%x",
                  "get_play_status_cb",param_2,param_3,DAT_0016bde8);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015bdc FUN_00015bdc */

/* Boundary evidence: original MIPS .pdata 00015bdc..00015c97. Semantic name remains unreviewed. */

void FUN_00015bdc(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 byte param_6)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,0,L"%S ipod status 0x%x uw_status 0x%x play_state 0x%x","get_play_status_cb2",0,
                  0,param_6);
    DAT_0016bde8 = (ushort)param_6;
  }
  else {
    DbgDebugPrint(6,0,L"[ERROR] %S ipod status 0x%x uw_status 0x%x previous play_state 0x%x",
                  "get_play_status_cb2",param_2,param_3,DAT_0016bde8);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015c98 FUN_00015c98 */

/* Boundary evidence: original MIPS .pdata 00015c98..00015dab. Semantic name remains unreviewed. */

void FUN_00015c98(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    if (DAT_0016caec == 0) {
      NKDbgPrintfW(L">> [%d]->[%d]\r\n",DAT_0016cb1c,param_4);
      DAT_0016cb1c = param_4;
    }
    else {
      NKDbgPrintfW(L"~!@# 2222 Opss!!!! [%d]->[%d]\r\n",DAT_0016cb1c,param_4);
    }
    iVar1 = DAT_0016bdf4;
    DAT_0016bdf4 = param_4;
    if ((DAT_0016bd98 != 0) &&
       (MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c), iVar1 != param_4)) {
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x","get_cur_play_track_idx_cb",
                  param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015dac FUN_00015dac */

/* Boundary evidence: original MIPS .pdata 00015dac..00015e1b. Semantic name remains unreviewed. */

void FUN_00015dac(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) || (uVar1 = param_4, param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod status 0x%x uw_status 0x%x num_of_tracks %d",
                  "get_num_play_tracks_cb",param_2,param_3,param_4);
    uVar1 = DAT_0016cb08;
  }
  DAT_0016cb08 = uVar1;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015e1c FUN_00015e1c */

/* Boundary evidence: original MIPS .pdata 00015e1c..00015e7b. Semantic name remains unreviewed. */

void FUN_00015e1c(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S set_repeat_cb ipod_status 0x%x uw_status 0x%x","set_repeat_cb",
                  param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015e7c FUN_00015e7c */

/* Boundary evidence: original MIPS .pdata 00015e7c..00015f13. Semantic name remains unreviewed. */

void FUN_00015e7c(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002d215 = (undefined1)param_4;
    IpcPostMsg(6,0x15,0x6c,1,&DAT_0002d215);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S get_repeat_cb repeat mode %d, ipod_status 0x%x uw_status 0x%x",
                  "get_repeat_cb",param_4,param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015f14 FUN_00015f14 */

/* Boundary evidence: original MIPS .pdata 00015f14..00015f73. Semantic name remains unreviewed. */

void FUN_00015f14(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S set_shuffle_cb ipod_status 0x%x uw_status 0x%x","set_shuffle_cb",
                  param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00015f74 FUN_00015f74 */

/* Boundary evidence: original MIPS .pdata 00015f74..00016007. Semantic name remains unreviewed. */

void FUN_00015f74(undefined4 param_1,int param_2,int param_3,undefined1 param_4)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0002d216 = param_4;
    IpcPostMsg(6,0x15,0x6b,1,&DAT_0002d216);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x uw_status 0x%x","get_shuffle_cb",param_2,param_3
                 );
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016008 FUN_00016008 */

/* Boundary evidence: original MIPS .pdata 00016008..0001616f. Semantic name remains unreviewed. */

void FUN_00016008(void)

{
  int iVar1;
  int iVar2;
  char *in_a3;
  ushort in_stack_00000010;
  
  iVar1 = DAT_0016bd98;
  if (DAT_0016bd98 == 0) {
    DbgDebugPrint(6,2,L"%S g_ocsharedMemory NULL","idx_play_track_title_cb");
  }
  else {
    iVar2 = strcmp(&DAT_0016be1c,in_a3);
    if (iVar2 == 0) {
      DbgDebugPrint(6,1,L"%S same title","idx_play_track_title_cb");
      MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
    else {
      DAT_0016bdea = in_stack_00000010;
      memset(&DAT_0016be1c,0,0x400);
      memcpy(&DAT_0016be1c,in_a3,(uint)in_stack_00000010);
      MSHM_Dll_Write(iVar1,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x6e,0,0);
    }
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016170 FUN_00016170 */

/* Boundary evidence: original MIPS .pdata 00016170..00016343. Semantic name remains unreviewed. */

void FUN_00016170(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  char *in_a3;
  ushort in_stack_00000010;
  
  iVar1 = DAT_0016bd98;
  if (DAT_0016bd98 == 0) {
    pwVar4 = L"%S g_ocsharedMemory NULL";
    uVar3 = 2;
  }
  else {
    if ((in_stack_00000010 == 0) || (*in_a3 == '\0')) {
      memset(&DAT_0016c61c,0,0x400);
      memcpy(&DAT_0016c61c,&DAT_0016be1c,(uint)DAT_0016bdea);
      DAT_0016bdee = DAT_0016bdea;
      MSHM_Dll_Write(iVar1,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x70,0,0);
      DbgDebugPrint(6,3,L"%S %d empty artist name","idx_play_track_artist2_name_cb",0x556);
      goto LAB_00016314;
    }
    iVar2 = strcmp(&DAT_0016c61c,in_a3);
    if (iVar2 != 0) {
      DAT_0016bdee = in_stack_00000010;
      memset(&DAT_0016c61c,0,0x400);
      memcpy(&DAT_0016c61c,in_a3,(uint)in_stack_00000010);
      MSHM_Dll_Write(iVar1,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x70,0,0);
      goto LAB_00016314;
    }
    pwVar4 = L"%S same artist name";
    uVar3 = 1;
  }
  DbgDebugPrint(6,uVar3,pwVar4,"idx_play_track_artist2_name_cb");
LAB_00016314:
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016344 FUN_00016344 */

/* Boundary evidence: original MIPS .pdata 00016344..000163bf. Semantic name remains unreviewed. */

void FUN_00016344(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DbgDebugPrint(6,0,L"%S uw_status 0x%x","start_audio_read_cb",0);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] : %S uw_status 0x%x","start_audio_read_cb",param_2);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 000163c0 FUN_000163c0 */

/* Boundary evidence: original MIPS .pdata 000163c0..0001641f. Semantic name remains unreviewed. */

void FUN_000163c0(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status %d, uw_status%d","play_cur_select_cb",param_2,param_3
                 );
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016420 FUN_00016420 */

/* Boundary evidence: original MIPS .pdata 00016420..0001664b. Semantic name remains unreviewed. */

void FUN_00016420(void)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  int in_a3;
  uint _Size;
  int in_stack_00000010;
  void *in_stack_00000014;
  ushort in_stack_00000018;
  int in_stack_0000001c;
  
  if (DAT_0016bd98 == 0) {
    pwVar2 = L"%S shared memory is null";
    uVar1 = 3;
LAB_0001648c:
    DbgDebugPrint(6,uVar1,pwVar2,"track_artwork_data_cb");
    return;
  }
  if (in_stack_00000010 == 0) {
    DAT_0016caa4 = 0;
    pwVar2 = L"%S art_data is Null";
    uVar1 = 1;
    goto LAB_0001648c;
  }
  if (in_a3 == 0) {
    DAT_0016ca22 = *(ushort *)(in_stack_00000010 + 2);
    DAT_0016ca20 = *(ushort *)(in_stack_00000010 + 4);
    DAT_0016ca8c = 0;
    if (DAT_0016caa8 != (void *)0x0) {
      free(DAT_0016caa8);
      DAT_0016caa8 = (void *)0x0;
      goto LAB_000164e8;
    }
  }
  else {
LAB_000164e8:
    if (DAT_0016caa8 != (void *)0x0) {
      DAT_0016caa8 = realloc(DAT_0016caa8,in_stack_00000018 + DAT_0016ca8c);
      goto LAB_0001651c;
    }
  }
  DAT_0016caa8 = malloc((uint)in_stack_00000018);
LAB_0001651c:
  memcpy((void *)((int)DAT_0016caa8 + DAT_0016ca8c),in_stack_00000014,(uint)in_stack_00000018);
  DAT_0016ca8c = in_stack_00000018 + DAT_0016ca8c;
  if (in_stack_0000001c != 0) {
    return;
  }
  DbgDebugPrint(6,0,L"%S last data","track_artwork_data_cb");
  _Size = DAT_0016ca8c - 2 & 3;
  if (_Size != 0) {
    DAT_0016caa8 = realloc(DAT_0016caa8,DAT_0016ca8c + _Size);
    memset((void *)((int)DAT_0016caa8 + DAT_0016ca8c),0,_Size);
    DAT_0016ca8c = DAT_0016ca8c + _Size;
  }
  FUN_00012bfc(DAT_0016caa8,DAT_0016ca8c,(uint)DAT_0016ca22,(uint)DAT_0016ca20);
  if (DAT_0016caa8 != (void *)0x0) {
    free(DAT_0016caa8);
    DAT_0016caa8 = (void *)0x0;
  }
  DAT_0016caa4 = 0;
  MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
  IpcPostMsg(6,0x15,0x71,0,0);
  return;
}



/* 0001664c FUN_0001664c */

/* Boundary evidence: original MIPS .pdata 0001664c..0001671b. Semantic name remains unreviewed. */

void FUN_0001664c(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,short param_5)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016ca84 = param_5;
    if (param_5 == 0) {
      DbgDebugPrint(6,0,L"%S artwork data is 0","track_artwork_times_cb",0);
    }
    else {
      DAT_0016ca88 = *param_4;
      DbgDebugPrint(6,0,L"%S artwork data is %d","track_artwork_times_cb",param_5);
    }
  }
  else {
    NKDbgPrintfW(L"ERROR %S ipod_status %d, uw_status %d","track_artwork_times_cb",param_2,param_3);
    DAT_0016ca84 = 0;
  }
  EventModify(DAT_0016ca9c,3);
  return;
}



/* 0001671c FUN_0001671c */

/* Boundary evidence: original MIPS .pdata 0001671c..000167c7. Semantic name remains unreviewed. */

void FUN_0001671c(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

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
          DAT_0002d290 = *puVar3;
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
  EventModify(DAT_0016ca9c,3);
  return;
}



/* 000167c8 FUN_000167c8 */

/* Boundary evidence: original MIPS .pdata 000167c8..000168d3. Semantic name remains unreviewed. */

undefined4 FUN_000167c8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  DAT_0016ca94 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_0016ca98 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  DAT_0016ca9c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0;
  DAT_0016caa0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  FUN_00019b08(&PTR_FUN_0002d19c);
  iVar1 = FUN_0001fb1c(0,uVar2,uVar3,uVar4);
  if (iVar1 != 0) {
    DbgDebugPrint(6,2,L"%S wince_usbware_entry error %d","init_ipod_driver",iVar1);
  }
  DbgDebugPrint(6,2,L"%S init ipod driver done","init_ipod_driver");
  return 1;
}



/* 000168d4 FUN_000168d4 */

/* Boundary evidence: original MIPS .pdata 000168d4..000169d7. Semantic name remains unreviewed. */

undefined4 FUN_000168d4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EventModify(DAT_0016ca94,3);
  EventModify(DAT_0016ca98,3);
  uVar1 = 3;
  EventModify(DAT_0016ca9c);
  FUN_00013164();
  FUN_000139d4();
  FUN_0001fb60(0,uVar1,param_3,param_4);
  if (DAT_0016ca94 != 0) {
    CloseHandle((HANDLE)DAT_0016ca94);
    DAT_0016ca94 = 0;
  }
  if (DAT_0016ca98 != 0) {
    CloseHandle((HANDLE)DAT_0016ca98);
    DAT_0016ca98 = 0;
  }
  if (DAT_0016ca9c != 0) {
    CloseHandle((HANDLE)DAT_0016ca9c);
    DAT_0016ca9c = 0;
  }
  if (DAT_0016caa0 != 0) {
    CloseHandle((HANDLE)DAT_0016caa0);
    DAT_0016caa0 = 0;
  }
  return 1;
}



/* 000169d8 FUN_000169d8 */

/* Boundary evidence: original MIPS .pdata 000169d8..00016aef. Semantic name remains unreviewed. */

void FUN_000169d8(undefined4 param_1,int param_2,int param_3,undefined4 param_4,byte param_5,
                 byte param_6)

{
  DAT_0002d294 = (uint)CONCAT11(param_5,param_6);
  if ((param_2 == 0) && (param_3 == 0)) {
    DbgDebugPrint(6,0,L"%S xtended lingo vesion - maj_ver:%x  min_ver:%x","ret_lingo_ver_cb",
                  (uint)param_5,(uint)param_6);
    DAT_0002d294 = (uint)param_5 * 100 + (uint)param_6;
    if (DAT_0002d294 < 0x71) {
      FUN_00014030(0);
    }
    else {
      FUN_00014030(1);
      if (0x71 < (int)DAT_0002d294) {
        FUN_00014040(1);
      }
    }
  }
  else {
    DbgDebugPrint(6,0,L"%S ipod_status 0x%x  uw_status 0x%x","ret_lingo_ver_cb",param_2,param_3);
  }
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016af0 FUN_00016af0 */

/* Boundary evidence: original MIPS .pdata 00016af0..00016b3f. Semantic name remains unreviewed. */

void FUN_00016af0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DbgDebugPrint(6,3,L"%S ipod status %d uw_status %d ","set_remote_event_nofit_cb",param_2,param_3);
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016b40 FUN_00016b40 */

/* Boundary evidence: original MIPS .pdata 00016b40..00016bcf. Semantic name remains unreviewed. */

void FUN_00016b40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 void *param_5,uint param_6)

{
  DbgDebugPrint(6,3,L"%S ipod status %d uw_status %d model_id %x model_num %S model_len %d",
                "get_ipod_model_cb",param_2,param_3,param_4,param_5,param_6);
  FUN_00013f14(param_4,param_5,param_6);
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016bd0 FUN_00016bd0 */

/* Boundary evidence: original MIPS .pdata 00016bd0..00016d0f. Semantic name remains unreviewed. */

void FUN_00016bd0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte local_10;
  uint local_c;
  
  if ((param_2 == 0) && (param_3 == 0)) {
    if (param_4 == 0) {
      local_c = (uint)*(byte *)(param_5 + 6);
      local_10 = *(byte *)(param_5 + 4);
      if ((*(byte *)(param_5 + 6) & 0x20) != 0) {
        FUN_00013fb0(1);
      }
      if ((local_10 & 1) != 0) {
        FUN_00013fd0(1);
      }
    }
    else if ((param_4 == 4) && ((*(byte *)(param_5 + 7) & 2) != 0)) {
      FUN_00014030(1);
    }
    DbgDebugPrint(6,0,L"%S ipod_status 0x%x  uw_status 0x%x app_comm_%d autolaunch_%d\n",
                  "get_options_for_lingo_cb",0,0,local_c >> 5 & 1,local_10 & 1);
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %S ipod_status 0x%x  uw_status 0x%x","get_options_for_lingo_cb",
                  param_2,param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016d10 FUN_00016d10 */

/* Boundary evidence: original MIPS .pdata 00016d10..00016d9b. Semantic name remains unreviewed. */

void FUN_00016d10(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  if ((param_2 == 0) && (param_3 == 0)) {
    DAT_0016cab8 = param_5;
    DAT_0016cab4 = param_4;
  }
  else {
    DbgDebugPrint(6,3,L"[ERROR] %s: ipod_status [%d], uw_status [%d]\r\n",
                  "get_supported_event_notification_cb",param_2,param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016d9c FUN_00016d9c */

/* Boundary evidence: original MIPS .pdata 00016d9c..00016e0f. Semantic name remains unreviewed. */

void FUN_00016d9c(undefined4 param_1,int param_2,int param_3)

{
  if ((param_2 != 0) || (param_3 != 0)) {
    DbgDebugPrint(6,3,L"[ERROR] %s : ipod_status [%d], uw_status [%d]\r\n",
                  "set_event_notification_cb",param_2,param_3);
  }
  DAT_0016cabc = (undefined1)param_2;
  EventModify(DAT_0016ca94,3);
  return;
}



/* 00016e10 FUN_00016e10 */

/* Boundary evidence: original MIPS .pdata 00016e10..00016ec7. Semantic name remains unreviewed. */

undefined4
FUN_00016e10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_00013994(param_2);
  FUN_000139a4((short)param_3,(char)param_4);
  puVar1 = FUN_000139b8();
  *param_5 = puVar1;
  DbgDebugPrint(6,2,L"%S Session Opened : ID_%d, Protocod Index : %d\n","mylink_iapp_open_cb",
                param_3,param_4);
  iVar2 = FUN_00013ef8();
  if ((iVar2 == 0) || (iVar2 = FUN_00013e3c(), iVar2 == 0)) {
    puVar3 = (undefined4 *)FUN_000139b8();
    FUN_00013e4c(1,0x66,puVar3);
  }
  return 0;
}



/* 00016ec8 FUN_00016ec8 */

/* Boundary evidence: original MIPS .pdata 00016ec8..00016f0f. Semantic name remains unreviewed. */

void FUN_00016ec8(undefined2 *param_1)

{
  DbgDebugPrint(6,2,L"Session Closed...(SessionID_%d, ProtoID_%d)\n",*param_1,
                *(undefined1 *)(param_1 + 1));
  FUN_00013994(0);
  return;
}



/* 00016f18 FUN_00016f18 */

/* Boundary evidence: original MIPS .pdata 00016f18..0001709b. Semantic name remains unreviewed. */

void FUN_00016f18(void)

{
  wchar_t *lpText;
  
  DAT_0016bd98 = MSHM_Dll_CreateShmClassObj(L"ShmMxMgrIpodAppMain");
  MSHM_Dll_MakeMappingReadWrite(DAT_0016bd98,L"ShmFmMgrIpodAppMain",0xc5c,0xffffffff);
  DAT_0016bd9c = MSHM_Dll_CreateShmClassObj(L"ShmMxMgrIpodAppMainList");
  MSHM_Dll_MakeMappingReadWrite(DAT_0016bd9c,L"ShmFmMgrIpodAppMainList",&DAT_0013d628,0xffffffff);
  DAT_0016cac8 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0x9c54,
                                    L"ShmFmMgrIpodAppMainListUID");
  if (DAT_0016cac8 == (HANDLE)0x0) {
    GetLastError();
    lpText = L"IPOD Shared Memory CreateFileMapping FAIL";
  }
  else {
    DAT_0016cacc = MapViewOfFile(DAT_0016cac8,6,0,0,0x9c54);
    if (DAT_0016cacc != (LPVOID)0x0) {
      memset(DAT_0016cacc,0,0x9c54);
      FUN_0001101c(&DAT_0016bdc8);
      FUN_000167c8();
      SetTimer(DAT_0016cac4,0xc8e,1000,(TIMERPROC)0x0);
      return;
    }
    CloseHandle(DAT_0016cac8);
    lpText = L"IPOD Shared Memory MapViewOfFile FAIL";
    DAT_0016cac8 = (HANDLE)0x0;
  }
  MessageBoxW((HWND)0x0,lpText,L"Warning",0);
  return;
}



/* 0001709c FUN_0001709c */

/* Boundary evidence: original MIPS .pdata 0001709c..000171c3. Semantic name remains unreviewed. */

void FUN_0001709c(void)

{
  LSTATUS LVar1;
  size_t sVar2;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_0002d280;
  DbgSetDebugOnOff(6,1);
  DbgSetDebugLevel(6,1);
  FUN_00016f18();
  DbgDebugPrint(6,0,L"%S MgrIpod Create","OnInit");
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_220);
  if (LVar1 == 0) {
    _snwprintf_s(awStack_218,0x104,0xffffffff,L"%s [%s]",L"0.9.0",L"20130527");
    sVar2 = wcslen(awStack_218);
    RegSetValueExW(local_220[0],L"VerMgrIpod",0,1,(BYTE *)awStack_218,sVar2 << 1);
    RegCloseKey(local_220[0]);
  }
  FUN_00026db4(local_10);
  return;
}



/* 000171c4 FUN_000171c4 */

/* Boundary evidence: original MIPS .pdata 000171c4..000172a3. Semantic name remains unreviewed. */

void FUN_000171c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_000168d4(param_1,param_2,param_3,param_4);
  if (DAT_0016bd9c != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016bd9c = 0;
  }
  if (DAT_0016bd98 != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016bd98 = 0;
  }
  if (DAT_0016cb18 != 0) {
    MSHM_Dll_DestoryShmClassObj();
    DAT_0016cb18 = 0;
  }
  if (DAT_0016cacc != (LPCVOID)0x0) {
    UnmapViewOfFile(DAT_0016cacc);
    DAT_0016cacc = (LPCVOID)0x0;
  }
  if (DAT_0016cac8 != 0) {
    CloseHandle((HANDLE)DAT_0016cac8);
    DAT_0016cac8 = 0;
  }
  return;
}



/* 000172a4 FUN_000172a4 */

/* Boundary evidence: original MIPS .pdata 000172a4..00017757. Semantic name remains unreviewed. */

LRESULT FUN_000172a4(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

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
    DAT_0016cac4 = param_1;
    FUN_0001709c();
    SetTimer(param_1,0x3e9,0x9c4,(TIMERPROC)0x0);
  }
  else if (param_2 == 2) {
    FUN_000171c4(param_1,2,param_3,param_4);
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
          DAT_0016cad0 = 0;
          DAT_0016cad4 = 0;
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
          FUN_000111e4();
          FUN_000117ec(DAT_0016bdf4);
          FUN_00011764(DAT_0016bdf4);
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          DbgDebugPrint(6,3,L"%S IDM_MIPOD_AMAIN_CHANGED_TRACK idx %d","WndProc",DAT_0016bdf4);
          local_3c = DAT_0016bdf4;
          IpcPostMsg(6,0x15,0x6d,4,&local_3c);
          return 0;
        }
        if (param_3 == 0xc8e) {
          KillTimer(param_1,0xc8e);
          memset(&local_40,0,4);
          local_40 = local_40 & 0xfff01f04 | 0x1004;
          LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\iPod",0,0x20019,&local_3c
                               );
          if (LVar2 == 0) {
            local_38[1] = 4;
            local_38[0] = 4;
            RegQueryValueExW(local_3c,L"Inserted",(LPDWORD)0x0,local_38 + 1,(LPBYTE)&DAT_0016cad4,
                             local_38);
            RegCloseKey(local_3c);
          }
          if (DAT_0016cad4 == 0) {
            IpcPostMsg(6,1,9,4,&local_40);
            uVar3 = IpcGetProcessName(6);
            NKDbgPrintfW(L"\r\n~!@#$ [%s] TIMER_INIT_DETACH... g_bHiddenState : 0 \r\n",uVar3);
            return 0;
          }
          DAT_0016cad4 = 0;
          return 0;
        }
        if (param_3 != 0xc90) {
          return 0;
        }
        KillTimer(param_1,0xc90);
        if ((DAT_0016ca7c != 0) && (DAT_0016ca80 != 0)) {
          return 0;
        }
        FUN_00013818();
        return 0;
      }
      if (param_2 != 0x8064) {
        LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
        return LVar1;
      }
    }
    if (DAT_0016bda4 == 0) {
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
        LVar1 = FUN_00018a24(*puVar4,(short)puVar4[1],puVar4[2],(int *)puVar4[3]);
        return LVar1;
      }
      if (uVar5 == 6) {
        LVar1 = FUN_00018fb0(*puVar4,(short)puVar4[1]);
        return LVar1;
      }
      if (uVar5 == 0x15) {
        LVar1 = FUN_00017ad4(*puVar4,(ushort)puVar4[1],puVar4[2],local_24);
        return LVar1;
      }
    }
  }
  return 0;
}



/* 00017758 FUN_00017758 */

/* Boundary evidence: original MIPS .pdata 00017758..000177bb. Semantic name remains unreviewed. */

void FUN_00017758(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_000172a4;
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



/* 000177bc FUN_000177bc */

/* Boundary evidence: original MIPS .pdata 000177bc..0001789f. Semantic name remains unreviewed. */

undefined4 FUN_000177bc(HINSTANCE param_1,int param_2)

{
  LPCWSTR pWVar1;
  int iVar2;
  LPCWSTR lpClassName;
  HWND hWnd;
  
  DAT_0016cac0 = param_1;
  pWVar1 = (LPCWSTR)IpcGetProcessName(6);
  iVar2 = FUN_00017758(param_1,pWVar1);
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



/* 000178a0 FUN_000178a0 */

/* Boundary evidence: original MIPS .pdata 000178a0..00017ad3. Semantic name remains unreviewed. */

undefined4 FUN_000178a0(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  LPCWSTR lpName;
  HANDLE hMutex;
  DWORD DVar1;
  undefined4 uVar2;
  size_t sVar3;
  LSTATUS LVar4;
  int iVar5;
  BOOL BVar6;
  HKEY local_58;
  DWORD local_54 [3];
  MSG MStack_48;
  
  lpName = (LPCWSTR)IpcGetProcessName(6);
  hMutex = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,lpName);
  DVar1 = GetLastError();
  if (hMutex != (HANDLE)0x0) {
    ReleaseMutex(hMutex);
  }
  if (DVar1 == 0xb7) {
    CloseHandle(hMutex);
    uVar2 = IpcGetProcessName(6);
    NKDbgPrintfW(L"\r\n~!@#$ [%s] Program is running...\r\n",uVar2);
  }
  else {
    sVar3 = wcslen(param_3);
    if (sVar3 == 0) {
      LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemStatus\\USB\\iPod",0,0x20019,&local_58);
      if (LVar4 == 0) {
        local_54[1] = 4;
        local_54[0] = 4;
        RegQueryValueExW(local_58,L"Inserted",(LPDWORD)0x0,local_54 + 1,(LPBYTE)&DAT_0016cad4,
                         local_54);
        RegCloseKey(local_58);
      }
    }
    else {
      DAT_0016cad0 = 1;
    }
    uVar2 = IpcGetProcessName(6);
    NKDbgPrintfW(L"\r\n~!@#$ [%s] [%d][%d], CmdLine[%s]\r\n",uVar2,DAT_0016cad0,DAT_0016cad4,param_3
                );
    iVar5 = FUN_000177bc(param_1,param_4);
    if (iVar5 != 0) {
      while (BVar6 = GetMessageW(&MStack_48,(HWND)0x0,0,0), BVar6 != 0) {
        TranslateMessage(&MStack_48);
        DispatchMessageW(&MStack_48);
      }
      CloseHandle(hMutex);
      return MStack_48.wParam;
    }
    CloseHandle(hMutex);
  }
  return 0;
}



/* 00017ad4 FUN_00017ad4 */

/* Boundary evidence: original MIPS .pdata 00017ad4..00018a23. Semantic name remains unreviewed. */

undefined4 FUN_00017ad4(undefined4 param_1,ushort param_2,undefined4 param_3,ushort *param_4)

{
  uint uVar1;
  int iVar2;
  UINT_PTR nIDEvent;
  uint uVar3;
  
  while (DAT_0016caa4 != 0) {
    Sleep(100);
    NKDbgPrintfW(&PTR_DAT_0002b938);
  }
  if (param_2 < 0x70) {
    if (param_2 == 0x6f) {
      DAT_0016cb10 = 0;
      DAT_0016cb14 = 1;
      if (DAT_0016caf4 == 1) {
        DAT_0016cb10 = 0;
        DAT_0016cb14 = 1;
        return 0;
      }
      if (DAT_0016bde8 == 1) {
        FUN_00011f80(0xf0);
        DAT_0016cad8 = 1;
      }
      FUN_0001192c();
      return 0;
    }
    if (param_2 < 0x6a) {
      if (param_2 == 0x69) {
        FUN_000115f8();
        if (DAT_0002d216 < 2) {
          return 0;
        }
        uVar1 = 1;
      }
      else {
        if (param_2 == 0x65) {
          if ((uint)DAT_0002d215 == (uint)(byte)*param_4) {
            return 0;
          }
          FUN_00012e88((uint)(byte)*param_4);
          return 0;
        }
        if (param_2 != 0x66) {
          if (param_2 == 0x67) {
            DAT_0016cb10 = 0;
            if (DAT_0016cb04 / 1000 == (uint)*param_4) {
              DAT_0016cb10 = 0;
              return 0;
            }
            DAT_0016cb04 = (uint)*param_4 * 1000;
            FUN_00013028(DAT_0016cb04);
            return 0;
          }
          if (param_2 != 0x68) {
            return 0;
          }
          FUN_000113b0();
          return 0;
        }
        uVar1 = (uint)(byte)*param_4;
        if (DAT_0002d216 == uVar1) {
          return 0;
        }
      }
      FUN_0001152c(uVar1);
      FUN_000115f8();
      return 0;
    }
    if (param_2 != 0x6a) {
      if (param_2 == 0x6d) {
        DAT_0016cb10 = 0;
        DAT_0016cb14 = 1;
        if (DAT_0016caf4 == 0) {
          FUN_00011bf0();
        }
        if (DAT_0016bde8 != 0) {
          if (DAT_0016cb08 < 2) {
            if (((DAT_0002d215 == 2) || (DAT_0016cb08 == 0)) || (DAT_0016bdf4 != DAT_0016cb08 - 1))
            {
              FUN_000116ac();
              goto LAB_000182b0;
            }
            if (DAT_0016cb08 == 1) {
              return 0;
            }
            iVar2 = 0;
            goto LAB_00017f80;
          }
          DAT_0016caec = 1;
          KillTimer(DAT_0016cac4,1000);
          DAT_0016cb1c = DAT_0016cb1c + 1;
          NKDbgPrintfW(L"~~~~~!!!! NEXT %d | %d, g_ucShuffle_mode %d ,g_ucRepeat_mode %d ((%d)) \r\n"
                       ,DAT_0016cb1c,DAT_0016cb08,DAT_0002d216,DAT_0002d215,DAT_0016caf4);
          if (DAT_0016cb08 <= DAT_0016cb1c) {
            if (DAT_0016caf4 == 0) {
              DAT_0016caf4 = 1;
            }
            DAT_0016cb1c = 0;
            DAT_0016cb04 = 0;
            IpcPostMsg(6,6,0x3ea,0,0);
            return 0;
          }
          if (DAT_0016caf4 == 0) {
            if (DAT_0016bde8 == 1) {
              FUN_000130f0(0);
              DAT_0016caf8 = 1;
            }
            DAT_0016caf4 = 1;
          }
          DAT_0016cb04 = 0;
          if ((DAT_0002d216 != 0) || (DAT_0002d28c == '\a')) {
            DAT_0016cb0c = 1;
            FUN_000116ac();
            FUN_000111e4();
          }
          if (((DAT_0002d215 != 1) || (DAT_0002d216 != 1)) &&
             ((FUN_00011764(DAT_0016cb1c), DAT_0016c61c != '\0' ||
              ((DAT_0016c61d != '\0' || (DAT_0016c61e != '\0')))))) {
            memset(&DAT_0016c61c,0,0x400);
            MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
            IpcPostMsg(6,0x15,0x70,0,0);
          }
          goto LAB_00017f3c;
        }
        if (DAT_0002d28c == '\a') {
          FUN_00013448(7,0);
          if ((DAT_0016bdf4 < DAT_0016cb08 - 1) && (DAT_0016bdf4 != 0xffffffff)) {
            return 0;
          }
          if (DAT_0002d215 == 0) {
            return 0;
          }
          FUN_00012010(7,0);
          DAT_0016cb08 = DAT_0002d298;
          FUN_00011764(0);
          FUN_0001336c();
          FUN_000132e4();
          return 0;
        }
      }
      else {
        if (param_2 != 0x6e) {
          return 0;
        }
        DAT_0016cb14 = 1;
        DAT_0016cb10 = 0;
        uVar1 = DAT_0016bdf4;
        uVar3 = DAT_0016cb1c;
        NKDbgPrintfW(L"g_ucShuffle_mode %d, g_ucRepeat_mode %d, g_ulTotalTrack %d, g_stPlayInfo.nCurPlayIdx %d g_nextTrack %d \r\n"
                     ,DAT_0002d216,DAT_0002d215,DAT_0016cb08,DAT_0016bdf4,DAT_0016cb1c);
        if (DAT_0016caf4 == 0) {
          FUN_00011bf0();
        }
        if (DAT_0016bde8 != 0) {
          if (((DAT_0016bde8 == 1) || (DAT_0016bde8 == 2)) && (2999 < DAT_0016cb04)) {
            FUN_00012f5c(0);
            DAT_0016cb04 = 0;
            return 0;
          }
          if (DAT_0016cb08 < 2) {
            if (((DAT_0002d215 == 2) || (DAT_0016cb08 == 0)) || (DAT_0016bdf4 != 0)) {
              FUN_00011874();
LAB_000182b0:
              FUN_000111e4();
              return 0;
            }
            if (DAT_0016cb08 == 1) {
              return 0;
            }
            iVar2 = DAT_0016cb08 - 1;
LAB_00017f80:
            FUN_0001115c(iVar2);
            if (DAT_0016bde8 != 1) {
              FUN_000130f0(0);
            }
            FUN_0001336c();
            return 0;
          }
          DAT_0016caec = 1;
          KillTimer(DAT_0016cac4,1000);
          DAT_0016cb1c = DAT_0016cb1c - 1;
          NKDbgPrintfW(L"~~~~~!!!! prev %d | %d, g_ucShuffle_mode %d\r\n",DAT_0016cb1c,DAT_0016cb08,
                       DAT_0002d216,uVar1,uVar3);
          if (DAT_0016cb08 <= DAT_0016cb1c) {
            NKDbgPrintfW(L"~~~~~!!!! prev2 %d | %d, g_ucShuffle_mode %d\r\n",DAT_0016cb1c,
                         DAT_0016cb08,DAT_0002d216,uVar1,uVar3);
            if (DAT_0016caf4 == 0) {
              DAT_0016caf4 = 1;
            }
            DAT_0016cb04 = 0;
            DAT_0016cb1c = DAT_0016cb08 - 1;
            IpcPostMsg(6,6,0x3ea,0,0);
            return 0;
          }
          if (DAT_0016caf4 == 0) {
            if (DAT_0016bde8 == 1) {
              FUN_000130f0(0);
              DAT_0016caf8 = 1;
            }
            DAT_0016caf4 = 1;
          }
          if ((DAT_0002d216 != 0) || (DAT_0002d28c == '\a')) {
            DAT_0016cb0c = 1;
            FUN_00011874();
            FUN_000111e4();
          }
          if (((DAT_0002d215 != 1) || (DAT_0002d216 != 1)) &&
             ((FUN_00011764(DAT_0016cb1c), DAT_0016c61c != '\0' ||
              ((DAT_0016c61d != '\0' || (DAT_0016c61e != '\0')))))) {
            memset(&DAT_0016c61c,0,0x400);
            MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
            IpcPostMsg(6,0x15,0x70,0,0);
          }
LAB_00017f3c:
          nIDEvent = 1000;
LAB_00017f40:
          SetTimer(DAT_0016cac4,nIDEvent,1000,(TIMERPROC)0x0);
          return 0;
        }
        iVar2 = 0;
        if (DAT_0002d28c == '\a') {
          uVar1 = 7;
          goto LAB_0001808c;
        }
      }
      iVar2 = 0;
      uVar1 = 5;
LAB_0001808c:
      FUN_00013448(uVar1,iVar2);
      return 0;
    }
    FUN_0001336c();
    if ((DAT_0016cafc != 1) || (DAT_0016bde8 != 1)) goto LAB_000184e4;
    DAT_0016cb14 = 1;
    NKDbgPrintfW(L"~!@# Oops!!!! => NOT ALLOWED STREAMING START [%d]\r\n",DAT_0016cadc);
LAB_000184d8:
    iVar2 = 0;
  }
  else {
    if (0x75 < param_2) {
      if (param_2 == 0x76) {
        DbgDebugPrint(6,0,L"%S IDM_AMAIN_MIPOD_BACK_DB_RECORD","MsgProcessFromAppMain");
        FUN_000125fc((int)(char)*(int *)param_4,(*(int *)param_4 << 8) >> 0x10);
        return 0;
      }
      if (param_2 == 0x78) {
        DAT_0016cafc = 0;
        DAT_0016cb10 = 0;
        NKDbgPrintfW(L"~!@# IDM_AMAIN_MIPOD_USER_PLAY g_bStartSeek : %d, g_bStreamStop : %d\r\n",
                     DAT_0016caf4,DAT_0016cadc);
        if (DAT_0016caf4 == 1) {
          return 0;
        }
        if (DAT_0016cadc == 1) {
          DAT_0016cafc = 0;
          if (DAT_0016bde8 != 0) {
            DAT_0016bde8 = 1;
          }
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
          return 0;
        }
        if (DAT_0016bde8 == 0) {
          uVar1 = 7;
          if (DAT_0002d28c != '\a') {
            uVar1 = 5;
          }
          FUN_00013448(uVar1,0);
        }
        else {
          if (DAT_0016cb04 == 0) {
            FUN_00012f5c(0);
          }
          FUN_00013818();
        }
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
        DAT_0016cafc = 0;
        return 0;
      }
      if (param_2 != 0x79) {
        return 0;
      }
      if (DAT_0016caf4 == 1) {
        return 0;
      }
      DAT_0016cafc = 0;
      NKDbgPrintfW(L"IDM_AMAIN_MIPOD_USER_PAUSE() g_ucExtPlayStatus %d, g_stPlayInfo.ucPlayerStatus %d\r\n"
                   ,DAT_0002d155,DAT_0016bde8);
      if (DAT_0002d155 == '\v') {
        FUN_00011bf0();
        if (DAT_0016cadc != 1) {
          if (DAT_0016bde8 != 1) {
            return 0;
          }
          iVar2 = 0;
LAB_000184a4:
          FUN_000130f0(iVar2);
          return 0;
        }
      }
      else if (DAT_0016cadc == 1) {
        if (DAT_0016bde8 != 0) {
          DAT_0016bde8 = 2;
        }
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
      }
      else {
        FUN_00013164();
      }
      DAT_0016cafc = 1;
      return 0;
    }
    if (param_2 == 0x75) {
      NKDbgPrintfW(L"~!@# IDM_AMAIN_MIPOD_SET_DB_RECORD CAT : %d, INDEX : %d\r\n",
                   (int)(char)*(int *)param_4,(*(int *)param_4 << 8) >> 0x10);
      if ((char)*param_4 == '\x05') {
        DAT_0002d218 = 5;
        DAT_0002d21c = (*(int *)param_4 << 8) >> 0x10;
        if (DAT_0016caec == 0) {
          DAT_0016cb1c = DAT_0002d21c;
        }
        nIDEvent = 0x3eb;
        goto LAB_00017f40;
      }
      KillTimer(DAT_0016cac4,0x3eb);
      DAT_0002d218 = 0xffffffff;
      DAT_0002d21c = 0xffffffff;
      uVar1 = (uint)(char)*(int *)param_4;
      iVar2 = (*(int *)param_4 << 8) >> 0x10;
      goto LAB_0001808c;
    }
    if (param_2 == 0x70) {
      DAT_0016cb10 = 0;
      DAT_0016cb14 = 1;
      if (DAT_0016caf4 == 1) {
        DAT_0016cb10 = 0;
        DAT_0016cb14 = 1;
        return 0;
      }
      if (DAT_0016bde8 == 1) {
        FUN_00011f80(0xf0);
        DAT_0016cad8 = 1;
      }
      FUN_000119f4();
      return 0;
    }
    if (param_2 != 0x71) {
      if (param_2 == 0x73) {
        if ((byte)*param_4 == 0xf) {
          FUN_00013240();
          return 0;
        }
        FUN_000120a0((uint)(byte)*param_4);
        return 0;
      }
      if (param_2 != 0x74) {
        return 0;
      }
      DbgDebugPrint(6,0,L"%S IDM_AMAIN_MIPOD_GET_LIST","MsgProcessFromAppMain");
      FUN_00011fcc();
      FUN_000120f0((uint)(byte)*param_4,0);
      return 0;
    }
    DAT_0016cae8 = 0;
    DAT_0016cb14 = 1;
    if ((DAT_0016bdac == 0) && (DAT_0016bdb0 == 0)) {
      DAT_0016cae8 = 0;
      DAT_0016cb14 = 1;
      return 0;
    }
    FUN_00011abc();
    FUN_00011d1c();
    if (DAT_0016cad8 != 1) {
      if (DAT_0016cafc != 1) {
        return 0;
      }
      if (DAT_0016bde8 == 1) {
        FUN_000130f0(0);
        FUN_00011bf0();
      }
      FUN_00013164();
      NKDbgPrintfW(L"~!@# IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE STATE => NOT ALLOWED STREAMING START [%d]-[%d]\r\n"
                   ,DAT_0016cadc,DAT_0016bde8);
      return 0;
    }
    DAT_0016cad8 = 0;
    if (DAT_0016cadc != 0) {
      if (DAT_0016cae0 == 0) {
        iVar2 = 1;
        goto LAB_000184a4;
      }
      if (DAT_0016bde8 != 1) {
        DAT_0016cad8 = 0;
        return 0;
      }
      NKDbgPrintfW(L"~~~~~!!!! IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE\r\n");
      DAT_0016cae8 = 1;
      goto LAB_000184d8;
    }
    if (DAT_0016bde8 != 2) {
      if (DAT_0016cae4 == 1) {
        DAT_0016cae4 = 0;
        NKDbgPrintfW(L"!DM_AMIAN_MIPOD_END_FAST_FRD_REWIND FORCED PLAY REQUEST");
        FUN_000130a0();
        DAT_0016bde8 = 1;
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
      }
      else if (DAT_0016bde8 != 0) {
        NKDbgPrintfW(L"!DM_AMIAN_MIPOD_END_FAST_FRD_REWIND app_start_audio_read \r\n");
        FUN_00011f34(0xf0);
      }
      goto LAB_000184e4;
    }
    iVar2 = 1;
  }
  FUN_000130f0(iVar2);
LAB_000184e4:
  FUN_00011bf0();
  return 0;
}



/* 00018a24 FUN_00018a24 */

/* Boundary evidence: original MIPS .pdata 00018a24..00018faf. Semantic name remains unreviewed. */

undefined4 FUN_00018a24(undefined4 param_1,short param_2,undefined4 param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  if (param_2 == 10) {
    uVar2 = 1;
    DbgDebugPrint(6,1,L"%S player status %d","MgrProcessFromMgrSys",DAT_0016bde8);
    if (DAT_0016bde8 == 1) {
      FUN_00013164();
    }
    DbgDebugPrint(6,0,L"%S IDM_PREPARE_SHUTDOWN_CONFIRM","MgrProcessFromMgrSys");
    IpcPostMsg(6,1,0xb,0,0);
  }
  else if (param_2 == 0x67) {
    uVar2 = 1;
    DAT_0016cae0 = 1;
    DAT_0016cb14 = 0;
    if (*param_4 == 1) {
      NKDbgPrintfW(L">> ** [MUTE_ON] IDM_MSYS_MIPOD_AUDIO_STREAMING_STOP\r\n");
      DAT_0016cb00 = 1;
    }
    if ((DAT_0016bde8 == 0) && (DAT_0016bda8 == 1)) {
      DAT_0016cadc = 1;
    }
    else {
      bVar1 = FUN_00011d1c();
      if (CONCAT31(extraout_var,bVar1) == 0) {
        NKDbgPrintfW(
                    L"~[ERROR]~ IDM_MSYS_MIPOD_AUDIO_STREAMING_STOP app_get_play_status error~~~ ==> one more retry\r\n"
                    );
        Sleep(0x96);
        FUN_00011bf0();
      }
      if (DAT_0016bde8 == 1) {
        FUN_000130f0(0);
      }
      else if (DAT_0016caf8 == 1) {
        DAT_0016caf4 = 0;
        DAT_0016caf8 = 0;
      }
      DAT_0016cadc = 1;
    }
  }
  else if (param_2 == 0x68) {
    DAT_0016cae0 = 0;
    DAT_0016cb14 = 0;
    uVar2 = 1;
    if ((*param_4 == 1) && (DAT_0016cb00 == 1)) {
      NKDbgPrintfW(L">> ** [MUTE_OFF] IDM_MSYS_MIPOD_AUDIO_STREAMING_START\r\n");
      DAT_0016cb00 = 0;
    }
    if ((DAT_0016bde8 == 0) && (DAT_0016bda8 == 1)) {
      DAT_0016cadc = 0;
    }
    else if (DAT_0016cafc == 1) {
      FUN_00011bf0();
      NKDbgPrintfW(L"~!@# IDM_MSYS_MIPOD_AUDIO_STREAMING_START PAUSE STATE => NOT ALLOWED STREAMING START [%d], g_stPlayInfo.ucPlayerStatus %d, g_bDAStreamBlocked %d, g_bStatusSeek %d\r\n"
                   ,DAT_0016cadc,DAT_0016bde8,DAT_0016cad8,DAT_0016caf8);
      DAT_0016cadc = 0;
    }
    else {
      NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3a4);
      if (DAT_0016cadc == 1) {
        DAT_0016cadc = 0;
        if (DAT_0016cad8 == 1) {
          DAT_0016cae4 = 1;
          NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3ad);
        }
        else {
          DAT_0016cae4 = 0;
        }
        if (DAT_0016cae8 == 1) {
          DAT_0016cae8 = 0;
          DAT_0016bde8 = 1;
          FUN_000130a0();
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
          NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3ba);
        }
        else if ((DAT_0016cad8 == 0) && (DAT_0016caf8 == 0)) {
          if ((DAT_0016bde8 == 0) || (DAT_0016caf0 != 0)) {
            NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3c7);
            FUN_0001336c();
            if (DAT_0016caf0 != 0) {
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3cd);
              FUN_00011d1c();
              if ((DAT_0016ca7c == 0) || (DAT_0016ca80 == 0)) {
                if (DAT_0016bde8 != 1) {
                  FUN_000130f0(1);
                }
                NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3d3);
              }
              FUN_00011bf0();
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3d6);
              DAT_0016caf0 = 0;
            }
          }
          else {
            NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3df);
            FUN_00011d1c();
            if (DAT_0016bde8 == 1) {
              if (DAT_0016ca7c == 0) {
                NKDbgPrintfW(L">> %S, %d \n\r","MgrProcessFromMgrSys",0x3eb);
                FUN_000130a0();
                MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
                IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
              }
            }
            else {
              NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3e3);
              FUN_000130f0(1);
              FUN_00011bf0();
            }
          }
        }
      }
      else if (DAT_0016caf0 == 1) {
        NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3f8);
        DAT_0016caf0 = 0;
        FUN_00013818();
        FUN_0001336c();
      }
      NKDbgPrintfW(L"%S, %d \n\r","MgrProcessFromMgrSys",0x3fe);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00018fb0 FUN_00018fb0 */

/* Boundary evidence: original MIPS .pdata 00018fb0..00019b07. Semantic name remains unreviewed. */

undefined4 FUN_00018fb0(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  wchar_t *pwVar4;
  uint uVar5;
  uint uVar6;
  uint local_38 [2];
  uint auStack_30 [4];
  
  switch(param_2) {
  case 1000:
    DbgDebugPrint(6,0,L"%S init_ipod_connection ","MgrProcessFromMgrIpod");
    FUN_0001266c();
    if (DAT_0016bda4 != 0) {
      DAT_0016caf0 = 0;
      FUN_0001336c();
      if ((DAT_0016bda4 != 0) && (FUN_00013240(), iVar3 = DAT_0016bda4, DAT_0016bda4 != 0)) {
        memset(local_38,0,4);
        if (DAT_0016cad4 == 0) {
          local_38[0] = local_38[0] & 0xfff01f14 | 0x1014;
        }
        else {
          DAT_0016cad4 = 0;
          local_38[0] = local_38[0] & 0xfff01f34 | 0x1034;
        }
        if (DAT_0016bda0 == 1) {
          uVar5 = (uint)(0 < DAT_0016be10) << 0x14;
          uVar6 = uVar5 | local_38[0] & 0xffaff1ff | 0x100;
          if (DAT_0016cad0 != 0) {
            if (0 < DAT_0016be10 == 0) {
              uVar6 = uVar6 | 0x30;
            }
            else {
              uVar6 = uVar5 | local_38[0] & 0xffaff11f | 0x100 | 0x10;
            }
          }
          local_38[0] = uVar6 & 0xffdfffff;
          iVar3 = FUN_00013fc0();
          local_38[0] = (iVar3 << 0x17 ^ local_38[0]) & 0x800000 ^ local_38[0];
          iVar3 = FUN_00013fe0();
          local_38[0] = (iVar3 << 0x18 ^ local_38[0]) & 0x1000000 ^ local_38[0];
          FUN_00013e98();
          FUN_00011268();
          DAT_0016caf0 = 1;
          DAT_0016cad0 = 0;
          iVar3 = DAT_0016bda4;
        }
        if (iVar3 != 0) {
          IpcPostMsg(6,1,9,4,local_38);
        }
      }
    }
    break;
  case 0x3e9:
    if (DAT_0016bde8 == 0) {
      FUN_000110bc(0xffffffff);
LAB_00019244:
      FUN_00011f34(0xf0);
    }
    else {
      if ((DAT_0016bde8 == 0) || (2 < DAT_0016bde8)) goto LAB_00019244;
      FUN_00013818();
    }
    FUN_0001336c();
    FUN_00013240();
    break;
  case 0x3ea:
    DAT_0016cb14 = 0;
    NKDbgPrintfW(L"~!@# IDM_MIPOD_MIPOD_SETTRACK g_ulNextTrack %d ->%d [%d, %d], g_bTrackJumpStart %d\r\n"
                 ,DAT_0016bdf4,DAT_0016cb1c,DAT_0016caf8,DAT_0016cadc,DAT_0016cb0c);
    DAT_0016caec = 0;
    FUN_00011d1c();
    if (DAT_0016cb0c == 1) {
      if ((((DAT_0016caf8 != 0) && (DAT_0016bde8 != 1)) && (DAT_0016cadc == 0)) &&
         (DAT_0016cafc == 0)) {
        FUN_000130f0(1);
      }
    }
    else {
      uVar1 = FUN_00012dbc();
      if (((char)uVar1 == '\x01') || ((char)uVar1 == '\0')) {
        FUN_0001115c(DAT_0016cb1c);
      }
      else {
        FUN_000110bc(DAT_0016cb1c);
      }
    }
    if (DAT_0016cafc == 1) {
      NKDbgPrintfW(L"~!@# IDM_MIPOD_MIPOD_SETTRACK PAUSE STATE => NOT ALLOWED STREAMING START [%d]\r\n"
                   ,DAT_0016cadc);
LAB_000193ac:
      FUN_000130f0(0);
LAB_000193b4:
      if (DAT_0016cadc == 0) goto LAB_000193c0;
    }
    else {
      if (DAT_0016cadc != 0) {
        FUN_000130f0(0);
        FUN_00011d1c();
        if (DAT_0016bde8 == 1) goto LAB_000193ac;
        goto LAB_000193b4;
      }
      if ((DAT_0016caf8 == 0) && (DAT_0016bde8 != 1)) goto LAB_000193ac;
LAB_000193c0:
      FUN_00011bf0();
      if (DAT_0016bde8 == 1) {
        FUN_00011f34(0xf0);
      }
    }
    FUN_000111e4();
    if (DAT_0002d15c == DAT_0016bdf4) {
      FUN_00011764(DAT_0016bdf4);
      FUN_000117ec(DAT_0016bdf4);
    }
    DAT_0016caf4 = 0;
    DAT_0016caf8 = 0;
    if (DAT_0016cb0c == 1) {
      IpcPostMsg(6,6,0x3f0,0,0);
      DAT_0016cb0c = 0;
    }
    NKDbgPrintfW(L"~!@# END - IDM_MIPOD_MIPOD_SETTRACK g_ulNextTrack %d\r\n",DAT_0016cb1c);
    break;
  case 0x3eb:
    goto switchD_00019010_caseD_3eb;
  case 0x3ec:
    if ((DAT_0002d218 != 0xffffffff) && (DAT_0002d21c != -1)) {
      FUN_00013448(DAT_0002d218,DAT_0002d21c);
      if (DAT_0002d218 == 5) {
        FUN_000111e4();
        FUN_000117ec(DAT_0016bdf4);
        FUN_00011764(DAT_0016bdf4);
      }
      DAT_0016cb1c = DAT_0002d21c;
    }
    IpcPostMsg(6,0x15,0x77,0,0);
    NKDbgPrintfW(L"~!@# END - IDM_MIPOD_MIPOD_SETCAT gIcatIdx[%d], g_selectIdx[%d]\r\n",DAT_0002d218
                 ,DAT_0002d21c);
    break;
  case 0x3ed:
    FUN_00012410();
    break;
  case 0x3ee:
    if (DAT_0016cb14 != 0) {
      DAT_0016cb14 = 0;
      return 1;
    }
    if (DAT_0002d155 == '\v') {
      if (DAT_0016cae0 == 1) {
        NKDbgPrintfW(L">>IDM_MIPOD_MIPOD_PLAY_PAUSE g_bRecvStreamStop is TRUE break\r\n");
        FUN_00011d1c();
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
        return 1;
      }
      if (DAT_0016cafc == 0) {
        if (DAT_0016caf4 == 1) {
          return 1;
        }
        FUN_00011bf0();
        if ((DAT_0016cadc != 1) && (FUN_00011f80(0xf0), DAT_0016bde8 != 2)) {
          DAT_0016bde8 = 2;
        }
        DAT_0016cafc = 1;
        NKDbgPrintfW(L">> Pause from [ iPOD ]! g_bStreamStop %d \n",DAT_0016cadc);
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
        return 1;
      }
      pwVar4 = L">> Pause from [ HU ]! \n";
    }
    else {
      if (DAT_0002d155 != '\n') {
        return 1;
      }
      if (DAT_0016cae0 == 1) {
        DAT_0016cafc = 0;
        if (DAT_0016cb00 == 1) {
          DAT_0016cb00 = 0;
          FUN_00011d1c();
          if (DAT_0016bde8 != 1) {
            return 1;
          }
          local_38[0] = 0;
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x78,4,local_38);
          pwVar4 = L">> iPod mute is end \r\n \n";
LAB_000198ec:
          NKDbgPrintfW(pwVar4);
          FUN_00011f34(0xf0);
          return 1;
        }
        FUN_00011f80(0xf0);
        pwVar4 = L">> don\'t ipod streaming start!!!!!\n";
      }
      else if (DAT_0016cafc == 1) {
        DAT_0016cb10 = 0;
        if (DAT_0016caf4 == 1) {
          DAT_0016cb10 = 0;
          return 1;
        }
        if (DAT_0016cadc == 1) {
          DAT_0016cafc = 0;
          if (DAT_0016bde8 != 0) {
            DAT_0016bde8 = 1;
          }
          MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
          IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
          return 1;
        }
        if (DAT_0016bde8 == 0) {
          uVar5 = 7;
          if (DAT_0002d28c != '\a') {
            uVar5 = 5;
          }
          FUN_00013448(uVar5,0);
        }
        else {
          if (DAT_0016cb04 == 0) {
            FUN_00012f5c(0);
          }
          FUN_00011f34(0xf0);
          if (DAT_0016bde8 != 1) {
            DAT_0016bde8 = 1;
          }
        }
        MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
        IpcPostMsg(6,0x15,0x69,2,&DAT_0016bde8);
        pwVar4 = L">> Play from [ IPOD ]!! \n";
        DAT_0016cafc = 0;
      }
      else {
        if (DAT_0016ca7c == 0) {
          pwVar4 = L">> Play from [ HU ]!!22222 \n";
          goto LAB_000198ec;
        }
        pwVar4 = L">> Play from [ HU ]!! \n";
      }
    }
    NKDbgPrintfW(pwVar4);
    break;
  case 0x3ef:
    FUN_00012f5c(0);
switchD_00019010_caseD_3eb:
    DAT_0016cb14 = 1;
    if ((DAT_0016bdac == 0) && (DAT_0016bdb0 == 0)) {
      DAT_0016cb14 = 1;
      return 1;
    }
    if (DAT_0016bde8 != 1) {
      DAT_0016cb10 = 1;
    }
    IpcPostMsg(6,0x15,0x76,0,0);
    FUN_00011abc();
    FUN_00011d1c();
    if (DAT_0016cad8 != 1) {
      if (DAT_0016cafc != 1) {
        return 1;
      }
      NKDbgPrintfW(L"~!@# 111 IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE STATE => NOT ALLOWED STREAMING START [%d]-[%d]\r\n"
                   ,DAT_0016cadc,DAT_0016bde8);
      if (DAT_0016bde8 == 1) {
        FUN_000130f0(0);
        FUN_00011bf0();
      }
      if (DAT_0016cadc != 0) {
        return 1;
      }
      DAT_0016cb04 = 0;
      puVar2 = FUN_0001131c(auStack_30,0);
      DAT_0016bdd8 = *puVar2;
      DAT_0016bddc = puVar2[1];
      DAT_0016bde0 = puVar2[2];
      DAT_0016bde4 = puVar2[3];
      MSHM_Dll_Write(DAT_0016bd98,&DAT_0016bdc8,0,0xc5c);
      IpcPostMsg(6,0x15,0x72,0,0);
      return 1;
    }
    DAT_0016cad8 = 0;
    if (DAT_0016cadc == 0) {
      if (DAT_0016bde8 == 2) {
        iVar3 = 1;
        goto LAB_000195d4;
      }
      FUN_00011f34(0xf0);
    }
    else {
      if (DAT_0016bde8 != 1) {
        DAT_0016cad8 = 0;
        return 1;
      }
      NKDbgPrintfW(L"~~~~~!!!! IDM_AMIAN_MIPOD_END_FAST_FRD_REWIND PAUSE\r\n");
      iVar3 = 0;
LAB_000195d4:
      FUN_000130f0(iVar3);
    }
    FUN_00011bf0();
    break;
  case 0x3f0:
    KillTimer(DAT_0016cac4,0x3ed);
    SetTimer(DAT_0016cac4,0x3ed,500,(TIMERPROC)0x0);
  }
  return 1;
}



/* 00019b08 FUN_00019b08 */

/* Boundary evidence: original MIPS .pdata 00019b08..00019b3b. Semantic name remains unreviewed. */

void FUN_00019b08(void *param_1)

{
  FUN_0001fd54(&DAT_0016cb24,param_1,0x28);
  return;
}



/* 00019b3c FUN_00019b3c */

/* Boundary evidence: original MIPS .pdata 00019b3c..00019d03. Semantic name remains unreviewed. */

void FUN_00019b3c(void)

{
  undefined4 *local_68;
  undefined4 auStack_60 [18];
  undefined4 *local_18;
  undefined4 *local_14;
  undefined4 *local_10;
  uint local_c;
  
  local_c = DAT_0002d280;
  if (DAT_0016cb20 != (int *)0x0) {
    local_14 = (undefined4 *)DAT_0016cb20[8];
    while (local_14 != (undefined4 *)0x0) {
      local_10 = (undefined4 *)local_14[3];
      (**(code **)(local_14[1] + 0xc))(local_14[2]);
      FUN_00020e6c(local_14);
      local_14 = local_10;
    }
    if (*DAT_0016cb20 != 0) {
      FUN_00019d04(auStack_60,0x6d,0,0);
      FUN_0001bd58(0,auStack_60,0);
      FUN_00020a98((undefined4 *)*DAT_0016cb20);
    }
    if (DAT_0016cb20[2] != 0) {
      FUN_000201c8((HANDLE)DAT_0016cb20[2]);
    }
    local_68 = (undefined4 *)DAT_0016cb20[6];
    while (local_68 != (undefined4 *)0x0) {
      local_18 = (undefined4 *)local_68[5];
      FUN_00020e6c((undefined4 *)*local_68);
      FUN_00020e6c(local_68);
      local_68 = local_18;
    }
    if (DAT_0016cb20[3] != 0) {
      FUN_00020e6c((undefined4 *)DAT_0016cb20[3]);
    }
    FUN_00020e6c(DAT_0016cb20);
    DAT_0016cb20 = (int *)0x0;
  }
  FUN_00026db4(local_c);
  return;
}



/* 00019d04 FUN_00019d04 */

/* Boundary evidence: original MIPS .pdata 00019d04..00019dc7. Semantic name remains unreviewed. */

undefined4 FUN_00019d04(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  
  *param_1 = param_2;
  param_1[5] = 0;
  if ((param_3 != 0) || (param_4 != 0)) {
    FUN_00022e0c();
    piVar1 = FUN_00020d4c(8,0);
    FUN_00022e34();
    if (piVar1 == (int *)0x0) {
      return 7;
    }
    *piVar1 = param_3;
    piVar1[1] = param_4;
    param_1[5] = piVar1;
  }
  return 0;
}



/* 00019dc8 FUN_00019dc8 */

/* Boundary evidence: original MIPS .pdata 00019dc8..00019f3f. Semantic name remains unreviewed. */

int FUN_00019dc8(void)

{
  int *piVar1;
  int local_60;
  undefined4 auStack_58 [18];
  uint local_10;
  int local_c;
  
  local_10 = DAT_0002d280;
  piVar1 = FUN_00020d4c(0x28,1);
  if (piVar1 == (int *)0x0) {
    FUN_00026db4(local_10);
    local_c = 7;
  }
  else {
    DAT_0016cb20 = piVar1;
    piVar1[6] = 0;
    piVar1[7] = (int)(piVar1 + 6);
    piVar1[8] = 0;
    piVar1[9] = (int)(piVar1 + 8);
    local_60 = FUN_0002014c(piVar1 + 2);
    if ((local_60 == 0) &&
       (local_60 = FUN_00020658((int)piVar1,0x1000,0x19f40,piVar1), local_60 == 0)) {
      FUN_00019d04(auStack_58,0x6c,0,0);
      local_60 = FUN_0001bd58(0,auStack_58,0);
      if (local_60 == 0) {
        FUN_00026db4(local_10);
        return 0;
      }
    }
    FUN_00019b3c();
    FUN_00026db4(local_10);
    local_c = local_60;
  }
  return local_c;
}



/* 00019f40 FUN_00019f40 */

/* Boundary evidence: original MIPS .pdata 00019f40..0001b913. Semantic name remains unreviewed. */

void FUN_00019f40(undefined4 param_1,int param_2)

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
    if (DAT_0016cb20[3] == 0) {
      if (*(int *)(param_2 + 0x20) != 0) {
        return;
      }
      piVar1 = FUN_00020d4c(*(int *)(param_2 + 0x18) + 0x20,0);
      DAT_0016cb20[3] = piVar1;
      if (DAT_0016cb20[3] == 0) {
        return;
      }
      FUN_0001fd54((void *)DAT_0016cb20[3],local_1e0,*(int *)(param_2 + 0x1c) + 0x20);
      DAT_0016cb20[4] = DAT_0016cb20[3] + 0x20 + *(int *)(DAT_0016cb20[3] + 0x18);
      DAT_0016cb20[5] = *(undefined4 *)(DAT_0016cb20[3] + 0x18);
      return;
    }
    if (*(int *)(param_2 + 0x14) == *(int *)(DAT_0016cb20[3] + 0x10)) {
      if (*(int *)(param_2 + 0x20) == *(int *)(DAT_0016cb20[3] + 0x1c) + 1) {
        if (*(int *)(param_2 + 0x18) == *(int *)(DAT_0016cb20[3] + 0x14)) {
          DAT_0016cb20[5] = DAT_0016cb20[5] + *(int *)(param_2 + 0x1c);
          if (*(uint *)(param_2 + 0x18) < (uint)DAT_0016cb20[5]) {
            local_1e0 = (undefined4 *)DAT_0016cb20[3];
            local_1e0[3] = 10;
          }
          else {
            *(int *)(DAT_0016cb20[3] + 0x1c) = *(int *)(DAT_0016cb20[3] + 0x1c) + 1;
            FUN_0001fd54((void *)DAT_0016cb20[4],(void *)(param_2 + 0x24),
                         *(size_t *)(param_2 + 0x1c));
            DAT_0016cb20[4] = DAT_0016cb20[4] + *(int *)(param_2 + 0x1c);
            if (DAT_0016cb20[5] != *(int *)(DAT_0016cb20[3] + 0x14)) {
              return;
            }
            local_1e0 = (undefined4 *)DAT_0016cb20[3];
          }
        }
        else {
          local_1e0 = (undefined4 *)DAT_0016cb20[3];
          local_1e0[3] = 10;
        }
      }
      else {
        local_1e0 = (undefined4 *)DAT_0016cb20[3];
        local_1e0[3] = 10;
      }
    }
    else {
      local_1e0 = (undefined4 *)DAT_0016cb20[3];
      local_1e0[3] = 10;
    }
  }
  FUN_00022e34();
  local_2c = *local_1e0;
  switch(local_2c) {
  case 0:
    if (DAT_0016cb24 != (code *)0x0) {
      (*DAT_0016cb24)(0,local_1e0[3]);
    }
    break;
  case 1:
    if (DAT_0016cb28 != (code *)0x0) {
      (*DAT_0016cb28)(0,local_1e0[8],local_1e0[3]);
    }
    break;
  case 2:
    if (DAT_0016cb2c != (code *)0x0) {
      (*DAT_0016cb2c)(0,local_1e0[3]);
    }
    break;
  case 3:
    if (DAT_0016cb30 != (code *)0x0) {
      (*DAT_0016cb30)(0,*(undefined1 *)(local_1e0 + 2),local_1e0[3]);
    }
    break;
  case 4:
    if (DAT_0016cb3c != (code *)0x0) {
      (*DAT_0016cb3c)(0,local_1e0[3]);
    }
    break;
  case 6:
    if (DAT_0016cb38 != (code *)0x0) {
      (*DAT_0016cb38)(0,local_1e0[8],local_1e0[9],local_1e0[10]);
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
    FUN_0001f8d0((int)DAT_0016cb20,(char *)((int)local_1e0 + 0x21),*(byte *)(local_1e0 + 8));
    break;
  case 0x1e:
    FUN_0001f744(DAT_0016cb20,*(undefined2 *)(local_1e0 + 8),*(byte *)((int)local_1e0 + 0x22));
    break;
  case 0x1f:
    FUN_0001fa68((int)DAT_0016cb20,*(short *)(local_1e0 + 8),local_1e0 + 9,
                 *(undefined2 *)((int)local_1e0 + 0x22));
    break;
  case 0x21:
    FUN_0001f958((int)DAT_0016cb20,*(short *)(local_1e0 + 8));
    break;
  case 0x25:
    if (DAT_0016cb48 != (code *)0x0) {
      (*DAT_0016cb48)(0,local_1e0[8],*(undefined2 *)(local_1e0 + 9));
    }
    break;
  case 0x28:
  case 0x29:
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9]);
    break;
  case 0x2b:
    if (DAT_0016cb44 != (code *)0x0) {
      if ((*(char *)(local_1e0 + 8) == '\n') || (*(char *)(local_1e0 + 8) == '\x13')) {
        local_1e0[9] = local_1e0 + 0xd;
      }
      (*DAT_0016cb44)(0,local_1e0 + 8);
    }
    break;
  case 0x2c:
    if (DAT_0016cb34 != (code *)0x0) {
      (*DAT_0016cb34)(0,*(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
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
    FUN_0001ba90(local_1e0 + 9,(uint)*(byte *)(local_1e0 + 8),local_1e0 + 0xd);
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
    FUN_0001b914(local_1e0 + 0xb,local_1e0[10],local_1e0 + 0xf);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0 + 8,local_1e0[10],
                 local_1e0 + 0xb,local_1e0[0xe]);
    local_1c = (uint)(local_1e0[0xe] == 0);
    local_1ec = local_1c;
    break;
  case 0x52:
    FUN_0001b914(local_1e0 + 10,local_1e0[9],local_1e0 + 0xe);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9],
                 local_1e0 + 10,local_1e0[0xd]);
    local_18 = (uint)(local_1e0[0xd] == 0);
    local_1ec = local_18;
    break;
  case 0x53:
    FUN_0001b914(local_1e0 + 10,local_1e0[9],local_1e0 + 0xe);
    (*local_1e8)(local_1d8,*(undefined1 *)(local_1e0 + 2),local_1e0[3],local_1e0[8],local_1e0[9],
                 local_1e0 + 10,local_1e0[0xd]);
    local_14 = (uint)(local_1e0[0xd] == 0);
    local_1ec = local_14;
    break;
  case 0x54:
    if (DAT_0016cb40 != (code *)0x0) {
      (*DAT_0016cb40)(0,*(undefined1 *)(local_1e0 + 8),local_1e0 + 9);
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
    FUN_0001bb70(*(undefined1 *)(local_1e0 + 8),auStack_120,local_1e0 + 9);
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
  FUN_00022e0c();
  if (local_1ec != 0) {
    FUN_00020e6c(puVar2);
  }
  if (DAT_0016cb20[3] != 0) {
    FUN_00020e6c((undefined4 *)DAT_0016cb20[3]);
    DAT_0016cb20[3] = 0;
  }
  return;
}



/* 0001b914 FUN_0001b914 */

/* Boundary evidence: original MIPS .pdata 0001b914..0001ba8f. Semantic name remains unreviewed. */

void FUN_0001b914(undefined4 *param_1,uint param_2,undefined4 param_3)

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



/* 0001ba90 FUN_0001ba90 */

/* Boundary evidence: original MIPS .pdata 0001ba90..0001bb6f. Semantic name remains unreviewed. */

void FUN_0001ba90(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

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



/* 0001bb70 FUN_0001bb70 */

/* Boundary evidence: original MIPS .pdata 0001bb70..0001bd57. Semantic name remains unreviewed. */

void FUN_0001bb70(undefined1 param_1,undefined4 *param_2,undefined4 *param_3)

{
  switch(param_1) {
  case 0:
    FUN_0001fd54(param_2,param_3,0xc);
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



/* 0001bd58 FUN_0001bd58 */

/* Boundary evidence: original MIPS .pdata 0001bd58..0001bda7. Semantic name remains unreviewed. */

int FUN_0001bd58(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_0001bda8(param_1,param_2,param_3,(void *)0x0,0);
  return iVar1;
}



/* 0001bda8 FUN_0001bda8 */

/* Boundary evidence: original MIPS .pdata 0001bda8..0001bffb. Semantic name remains unreviewed. */

int FUN_0001bda8(undefined4 param_1,undefined4 *param_2,int param_3,void *param_4,size_t param_5)

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
  
  local_18 = DAT_0002d280;
  local_2040 = 0;
  local_2038 = param_3 + 0x48;
  local_203c = param_2 + 6;
  FUN_0002020c((HANDLE)DAT_0016cb20[2]);
  FUN_0001fd98(auStack_2030,0,0x2014);
  local_1028 = 0x81002048;
  local_2028 = *param_2;
  local_2014 = param_2[5];
  local_2024 = param_3 + 0x30;
  local_201c = DAT_0016cb20[1];
  DAT_0016cb20[1] = DAT_0016cb20[1] + 1;
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
    FUN_0001fd54(auStack_2010,local_203c,local_1c);
    local_203c = (undefined4 *)((int)local_203c + local_1c);
    local_2020 = local_1c;
    local_2038 = local_2038 - local_1c;
    local_2040 = FUN_00020bac(*DAT_0016cb20,(int)auStack_2030);
    if (local_2040 != 0) break;
    if (param_4 != (void *)0x0) {
      if (param_5 == local_1024 - 4U) {
        FUN_0001fd54(param_4,auStack_101c,param_5);
      }
      else {
        local_2040 = 10;
      }
    }
    local_2018 = local_2018 + 1;
  }
  FUN_0002025c((HANDLE)DAT_0016cb20[2]);
  FUN_00026db4(local_18);
  return local_2040;
}



/* 0001bffc FUN_0001bffc */

/* Boundary evidence: original MIPS .pdata 0001bffc..0001c073. Semantic name remains unreviewed. */

int FUN_0001bffc(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,5,0,0);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c074 FUN_0001c074 */

/* Boundary evidence: original MIPS .pdata 0001c074..0001c0eb. Semantic name remains unreviewed. */

int FUN_0001c074(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,7,0,0);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c0ec FUN_0001c0ec */

/* Boundary evidence: original MIPS .pdata 0001c0ec..0001c16f. Semantic name remains unreviewed. */

int FUN_0001c0ec(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,9,0,0);
  local_40 = param_2;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c170 FUN_0001c170 */

/* Boundary evidence: original MIPS .pdata 0001c170..0001c1f3. Semantic name remains unreviewed. */

int FUN_0001c170(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,8,0,0);
  local_40 = param_2;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c1f4 FUN_0001c1f4 */

/* Boundary evidence: original MIPS .pdata 0001c1f4..0001c26b. Semantic name remains unreviewed. */

int FUN_0001c1f4(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,10,0,0);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c26c FUN_0001c26c */

/* Boundary evidence: original MIPS .pdata 0001c26c..0001c2e3. Semantic name remains unreviewed. */

int FUN_0001c26c(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0xb,0,0);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c2e4 FUN_0001c2e4 */

/* Boundary evidence: original MIPS .pdata 0001c2e4..0001c35b. Semantic name remains unreviewed. */

int FUN_0001c2e4(undefined4 param_1)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0xc,0,0);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c35c FUN_0001c35c */

/* Boundary evidence: original MIPS .pdata 0001c35c..0001c3e7. Semantic name remains unreviewed. */

int FUN_0001c35c(undefined4 param_1,undefined2 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0xd,param_3,param_4);
  local_40 = param_2;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c3e8 FUN_0001c3e8 */

/* Boundary evidence: original MIPS .pdata 0001c3e8..0001c473. Semantic name remains unreviewed. */

int FUN_0001c3e8(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x6e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c474 FUN_0001c474 */

/* Boundary evidence: original MIPS .pdata 0001c474..0001c577. Semantic name remains unreviewed. */

int FUN_0001c474(undefined2 *param_1,int param_2,void *param_3,ushort param_4,int param_5)

{
  int *piVar1;
  int local_10;
  
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(param_4 + 0x48,0);
  FUN_00022e34();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_00019d04(piVar1,0x20,param_2,param_5);
    FUN_0001fd54(piVar1 + 7,param_3,(uint)param_4);
    *(ushort *)((int)piVar1 + 0x1a) = param_4;
    *(undefined2 *)(piVar1 + 6) = *param_1;
    local_10 = FUN_0001bd58(0,piVar1,(uint)param_4);
    FUN_00022e0c();
    FUN_00020e6c(piVar1);
    FUN_00022e34();
  }
  return local_10;
}



/* 0001c578 FUN_0001c578 */

/* Boundary evidence: original MIPS .pdata 0001c578..0001c5b7. Semantic name remains unreviewed. */

int FUN_0001c578(undefined2 *param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0001f6b8(*param_1,param_2);
  return iVar1;
}



/* 0001c5b8 FUN_0001c5b8 */

/* Boundary evidence: original MIPS .pdata 0001c5b8..0001c617. Semantic name remains unreviewed. */

void FUN_0001c5b8(undefined4 param_1)

{
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0xe,0,0);
  FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return;
}



/* 0001c618 FUN_0001c618 */

/* Boundary evidence: original MIPS .pdata 0001c618..0001c697. Semantic name remains unreviewed. */

int FUN_0001c618(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0xf,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c698 FUN_0001c698 */

/* Boundary evidence: original MIPS .pdata 0001c698..0001c717. Semantic name remains unreviewed. */

int FUN_0001c698(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x10,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c718 FUN_0001c718 */

/* Boundary evidence: original MIPS .pdata 0001c718..0001c797. Semantic name remains unreviewed. */

int FUN_0001c718(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x12,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c798 FUN_0001c798 */

/* Boundary evidence: original MIPS .pdata 0001c798..0001c817. Semantic name remains unreviewed. */

int FUN_0001c798(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x19,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c818 FUN_0001c818 */

/* Boundary evidence: original MIPS .pdata 0001c818..0001c8a3. Semantic name remains unreviewed. */

int FUN_0001c818(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x13,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c8a4 FUN_0001c8a4 */

/* Boundary evidence: original MIPS .pdata 0001c8a4..0001c923. Semantic name remains unreviewed. */

int FUN_0001c8a4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x11,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c924 FUN_0001c924 */

/* Boundary evidence: original MIPS .pdata 0001c924..0001c9a3. Semantic name remains unreviewed. */

int FUN_0001c924(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x14,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001c9a4 FUN_0001c9a4 */

/* Boundary evidence: original MIPS .pdata 0001c9a4..0001ca23. Semantic name remains unreviewed. */

int FUN_0001c9a4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x15,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ca24 FUN_0001ca24 */

/* Boundary evidence: original MIPS .pdata 0001ca24..0001caa3. Semantic name remains unreviewed. */

int FUN_0001ca24(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x16,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001caa4 FUN_0001caa4 */

/* Boundary evidence: original MIPS .pdata 0001caa4..0001cb3f. Semantic name remains unreviewed. */

int FUN_0001caa4(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,
                undefined1 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x17,param_2,param_6);
  local_3e = param_5;
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cb40 FUN_0001cb40 */

/* Boundary evidence: original MIPS .pdata 0001cb40..0001cbcb. Semantic name remains unreviewed. */

int FUN_0001cb40(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x18,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cbcc FUN_0001cbcc */

/* Boundary evidence: original MIPS .pdata 0001cbcc..0001cc4b. Semantic name remains unreviewed. */

int FUN_0001cbcc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x1a,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cc4c FUN_0001cc4c */

/* Boundary evidence: original MIPS .pdata 0001cc4c..0001ccd7. Semantic name remains unreviewed. */

int FUN_0001cc4c(undefined4 param_1,undefined1 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x1b,param_3,param_4);
  local_40 = param_2;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ccd8 FUN_0001ccd8 */

/* Boundary evidence: original MIPS .pdata 0001ccd8..0001cd63. Semantic name remains unreviewed. */

int FUN_0001ccd8(undefined4 param_1,int param_2,undefined2 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x23,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cd64 FUN_0001cd64 */

/* Boundary evidence: original MIPS .pdata 0001cd64..0001ce0b. Semantic name remains unreviewed. */

int FUN_0001cd64(undefined4 param_1,int param_2,undefined1 param_3,undefined2 param_4,
                undefined2 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined1 local_48;
  undefined2 local_46;
  undefined2 local_44;
  uint local_18;
  
  local_18 = DAT_0002d280;
  FUN_00019d04(auStack_60,0x24,param_2,param_7);
  local_44 = param_5;
  local_48 = param_3;
  local_46 = param_4;
  iVar1 = FUN_0001bda8(param_1,auStack_60,0,param_6,4);
  FUN_00026db4(local_18);
  return iVar1;
}



/* 0001ce0c FUN_0001ce0c */

/* Boundary evidence: original MIPS .pdata 0001ce0c..0001ce8b. Semantic name remains unreviewed. */

int FUN_0001ce0c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x29,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ce8c FUN_0001ce8c */

/* Boundary evidence: original MIPS .pdata 0001ce8c..0001cf0b. Semantic name remains unreviewed. */

int FUN_0001ce8c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x28,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cf0c FUN_0001cf0c */

/* Boundary evidence: original MIPS .pdata 0001cf0c..0001cf9f. Semantic name remains unreviewed. */

int FUN_0001cf0c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x2a,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001cfa0 FUN_0001cfa0 */

/* Boundary evidence: original MIPS .pdata 0001cfa0..0001d033. Semantic name remains unreviewed. */

int FUN_0001cfa0(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x26,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d034 FUN_0001d034 */

/* Boundary evidence: original MIPS .pdata 0001d034..0001d17b. Semantic name remains unreviewed. */

int FUN_0001d034(undefined4 param_1,int param_2,char *param_3,int param_4)

{
  int *piVar1;
  size_t local_18;
  int local_c;
  
  local_18 = 0;
  if (*param_3 == '\x01') {
    local_18 = (uint)(byte)param_3[8] * 0x24;
  }
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(local_18 + 0x48,0);
  FUN_00022e34();
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    FUN_00019d04(piVar1,0x27,param_2,param_4);
    FUN_0001fd54(piVar1 + 6,param_3,0xc);
    if (*param_3 == '\x01') {
      FUN_0001fd54(piVar1 + 9,*(void **)(param_3 + 4),local_18);
    }
    local_c = FUN_0001bd58(param_1,piVar1,local_18);
    FUN_00022e0c();
    FUN_00020e6c(piVar1);
    FUN_00022e34();
  }
  return local_c;
}



/* 0001d17c FUN_0001d17c */

/* Boundary evidence: original MIPS .pdata 0001d17c..0001d207. Semantic name remains unreviewed. */

int FUN_0001d17c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x3a,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d208 FUN_0001d208 */

/* Boundary evidence: original MIPS .pdata 0001d208..0001d293. Semantic name remains unreviewed. */

int FUN_0001d208(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x3b,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d294 FUN_0001d294 */

/* Boundary evidence: original MIPS .pdata 0001d294..0001d313. Semantic name remains unreviewed. */

int FUN_0001d294(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x2d,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d314 FUN_0001d314 */

/* Boundary evidence: original MIPS .pdata 0001d314..0001d39f. Semantic name remains unreviewed. */

int FUN_0001d314(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x2e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d3a0 FUN_0001d3a0 */

/* Boundary evidence: original MIPS .pdata 0001d3a0..0001d41f. Semantic name remains unreviewed. */

int FUN_0001d3a0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x2f,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d420 FUN_0001d420 */

/* Boundary evidence: original MIPS .pdata 0001d420..0001d4ab. Semantic name remains unreviewed. */

int FUN_0001d420(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x30,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d4ac FUN_0001d4ac */

/* Boundary evidence: original MIPS .pdata 0001d4ac..0001d52b. Semantic name remains unreviewed. */

int FUN_0001d4ac(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x31,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d52c FUN_0001d52c */

/* Boundary evidence: original MIPS .pdata 0001d52c..0001d5ab. Semantic name remains unreviewed. */

int FUN_0001d52c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x32,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d5ac FUN_0001d5ac */

/* Boundary evidence: original MIPS .pdata 0001d5ac..0001d63f. Semantic name remains unreviewed. */

int FUN_0001d5ac(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x33,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d640 FUN_0001d640 */

/* Boundary evidence: original MIPS .pdata 0001d640..0001d6bf. Semantic name remains unreviewed. */

int FUN_0001d640(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x34,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d6c0 FUN_0001d6c0 */

/* Boundary evidence: original MIPS .pdata 0001d6c0..0001d753. Semantic name remains unreviewed. */

int FUN_0001d6c0(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x35,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d754 FUN_0001d754 */

/* Boundary evidence: original MIPS .pdata 0001d754..0001d7d3. Semantic name remains unreviewed. */

int FUN_0001d754(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x36,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d7d4 FUN_0001d7d4 */

/* Boundary evidence: original MIPS .pdata 0001d7d4..0001d85f. Semantic name remains unreviewed. */

int FUN_0001d7d4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x37,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d860 FUN_0001d860 */

/* Boundary evidence: original MIPS .pdata 0001d860..0001d8eb. Semantic name remains unreviewed. */

int FUN_0001d860(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x38,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d8ec FUN_0001d8ec */

/* Boundary evidence: original MIPS .pdata 0001d8ec..0001d977. Semantic name remains unreviewed. */

int FUN_0001d8ec(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x39,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001d978 FUN_0001d978 */

/* Boundary evidence: original MIPS .pdata 0001d978..0001da0b. Semantic name remains unreviewed. */

int FUN_0001d978(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x3c,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001da0c FUN_0001da0c */

/* Boundary evidence: original MIPS .pdata 0001da0c..0001da97. Semantic name remains unreviewed. */

int FUN_0001da0c(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x3d,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001da98 FUN_0001da98 */

/* Boundary evidence: original MIPS .pdata 0001da98..0001db3f. Semantic name remains unreviewed. */

int FUN_0001da98(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined1 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002d280;
  FUN_00019d04(auStack_60,0x3e,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001bda8(param_1,auStack_60,0,param_6,2);
  FUN_00026db4(local_18);
  return iVar1;
}



/* 0001db40 FUN_0001db40 */

/* Boundary evidence: original MIPS .pdata 0001db40..0001dbcb. Semantic name remains unreviewed. */

int FUN_0001db40(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x3f,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001dbcc FUN_0001dbcc */

/* Boundary evidence: original MIPS .pdata 0001dbcc..0001dccb. Semantic name remains unreviewed. */

int FUN_0001dbcc(undefined4 param_1,int param_2,void *param_3,void *param_4,size_t param_5,
                int param_6)

{
  int *piVar1;
  int local_10;
  
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(param_5 + 0x48,0);
  FUN_00022e34();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_00019d04(piVar1,0x40,param_2,param_6);
    FUN_0001fd54(piVar1 + 6,param_3,0xc);
    FUN_0001fd54(piVar1 + 10,param_4,param_5);
    piVar1[9] = param_5;
    local_10 = FUN_0001bd58(param_1,piVar1,param_5);
    FUN_00022e0c();
    FUN_00020e6c(piVar1);
    FUN_00022e34();
  }
  return local_10;
}



/* 0001dccc FUN_0001dccc */

/* Boundary evidence: original MIPS .pdata 0001dccc..0001dd4b. Semantic name remains unreviewed. */

int FUN_0001dccc(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x41,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001dd4c FUN_0001dd4c */

/* Boundary evidence: original MIPS .pdata 0001dd4c..0001ddf3. Semantic name remains unreviewed. */

int FUN_0001dd4c(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002d280;
  FUN_00019d04(auStack_60,0x42,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001bda8(param_1,auStack_60,0,param_6,2);
  FUN_00026db4(local_18);
  return iVar1;
}



/* 0001ddf4 FUN_0001ddf4 */

/* Boundary evidence: original MIPS .pdata 0001ddf4..0001de97. Semantic name remains unreviewed. */

int FUN_0001ddf4(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined2 param_5,undefined2 param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x43,param_2,param_7);
  local_3a = param_5;
  local_38 = param_6;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001de98 FUN_0001de98 */

/* Boundary evidence: original MIPS .pdata 0001de98..0001df23. Semantic name remains unreviewed. */

int FUN_0001de98(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x44,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001df24 FUN_0001df24 */

/* Boundary evidence: original MIPS .pdata 0001df24..0001dfa3. Semantic name remains unreviewed. */

int FUN_0001df24(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x45,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001dfa4 FUN_0001dfa4 */

/* Boundary evidence: original MIPS .pdata 0001dfa4..0001e02f. Semantic name remains unreviewed. */

int FUN_0001dfa4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x46,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e030 FUN_0001e030 */

/* Boundary evidence: original MIPS .pdata 0001e030..0001e0bb. Semantic name remains unreviewed. */

int FUN_0001e030(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x47,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e0bc FUN_0001e0bc */

/* Boundary evidence: original MIPS .pdata 0001e0bc..0001e157. Semantic name remains unreviewed. */

int FUN_0001e0bc(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  undefined4 local_3c;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x48,param_2,param_6);
  local_3c = param_5;
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e158 FUN_0001e158 */

/* Boundary evidence: original MIPS .pdata 0001e158..0001e1d7. Semantic name remains unreviewed. */

int FUN_0001e158(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x49,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e1d8 FUN_0001e1d8 */

/* Boundary evidence: original MIPS .pdata 0001e1d8..0001e273. Semantic name remains unreviewed. */

int FUN_0001e1d8(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined2 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4a,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e274 FUN_0001e274 */

/* Boundary evidence: original MIPS .pdata 0001e274..0001e2f3. Semantic name remains unreviewed. */

int FUN_0001e274(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4b,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e2f4 FUN_0001e2f4 */

/* Boundary evidence: original MIPS .pdata 0001e2f4..0001e373. Semantic name remains unreviewed. */

int FUN_0001e2f4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4c,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e374 FUN_0001e374 */

/* Boundary evidence: original MIPS .pdata 0001e374..0001e3f3. Semantic name remains unreviewed. */

int FUN_0001e374(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4d,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e3f4 FUN_0001e3f4 */

/* Boundary evidence: original MIPS .pdata 0001e3f4..0001e48f. Semantic name remains unreviewed. */

int FUN_0001e3f4(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined1 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4e,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e490 FUN_0001e490 */

/* Boundary evidence: original MIPS .pdata 0001e490..0001e51b. Semantic name remains unreviewed. */

int FUN_0001e490(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x4f,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e51c FUN_0001e51c */

/* Boundary evidence: original MIPS .pdata 0001e51c..0001e5a7. Semantic name remains unreviewed. */

int FUN_0001e51c(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x50,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e5a8 FUN_0001e5a8 */

/* Boundary evidence: original MIPS .pdata 0001e5a8..0001e647. Semantic name remains unreviewed. */

int FUN_0001e5a8(undefined4 param_1,int param_2,void *param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 auStack_40 [8];
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x51,param_2,param_5);
  FUN_0001fd54(auStack_40,param_3,8);
  local_38 = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e648 FUN_0001e648 */

/* Boundary evidence: original MIPS .pdata 0001e648..0001e6e3. Semantic name remains unreviewed. */

int FUN_0001e648(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x52,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e6e4 FUN_0001e6e4 */

/* Boundary evidence: original MIPS .pdata 0001e6e4..0001e77f. Semantic name remains unreviewed. */

int FUN_0001e6e4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x53,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e780 FUN_0001e780 */

/* Boundary evidence: original MIPS .pdata 0001e780..0001e7ff. Semantic name remains unreviewed. */

int FUN_0001e780(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x55,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e800 FUN_0001e800 */

/* Boundary evidence: original MIPS .pdata 0001e800..0001e893. Semantic name remains unreviewed. */

int FUN_0001e800(undefined4 param_1,int param_2,undefined4 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined1 local_3c;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x56,param_2,param_5);
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e894 FUN_0001e894 */

/* Boundary evidence: original MIPS .pdata 0001e894..0001e913. Semantic name remains unreviewed. */

int FUN_0001e894(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x57,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e914 FUN_0001e914 */

/* Boundary evidence: original MIPS .pdata 0001e914..0001e99f. Semantic name remains unreviewed. */

int FUN_0001e914(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x58,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001e9a0 FUN_0001e9a0 */

/* Boundary evidence: original MIPS .pdata 0001e9a0..0001ea2b. Semantic name remains unreviewed. */

int FUN_0001e9a0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x59,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ea2c FUN_0001ea2c */

/* Boundary evidence: original MIPS .pdata 0001ea2c..0001eaab. Semantic name remains unreviewed. */

int FUN_0001ea2c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5a,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001eaac FUN_0001eaac */

/* Boundary evidence: original MIPS .pdata 0001eaac..0001eb4b. Semantic name remains unreviewed. */

int FUN_0001eaac(undefined4 param_1,int param_2,undefined1 param_3,void *param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 auStack_3c [44];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5b,param_2,param_5);
  local_40 = param_3;
  FUN_0001fd54(auStack_3c,param_4,8);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001eb4c FUN_0001eb4c */

/* Boundary evidence: original MIPS .pdata 0001eb4c..0001ebd7. Semantic name remains unreviewed. */

int FUN_0001eb4c(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5c,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ebd8 FUN_0001ebd8 */

/* Boundary evidence: original MIPS .pdata 0001ebd8..0001ec57. Semantic name remains unreviewed. */

int FUN_0001ebd8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5d,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
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
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5e,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ece4 FUN_0001ece4 */

/* Boundary evidence: original MIPS .pdata 0001ece4..0001ed7f. Semantic name remains unreviewed. */

int FUN_0001ece4(undefined4 param_1,int param_2,undefined1 param_3,undefined4 param_4,
                undefined2 param_5,int param_6)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x5f,param_2,param_6);
  local_38 = param_5;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ed80 FUN_0001ed80 */

/* Boundary evidence: original MIPS .pdata 0001ed80..0001edff. Semantic name remains unreviewed. */

int FUN_0001ed80(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x60,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ee00 FUN_0001ee00 */

/* Boundary evidence: original MIPS .pdata 0001ee00..0001ee7f. Semantic name remains unreviewed. */

int FUN_0001ee00(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x61,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001ee80 FUN_0001ee80 */

/* Boundary evidence: original MIPS .pdata 0001ee80..0001ef27. Semantic name remains unreviewed. */

int FUN_0001ee80(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,void *param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_60 [6];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  uint local_18;
  
  local_18 = DAT_0002d280;
  FUN_00019d04(auStack_60,0x62,param_2,param_7);
  local_40 = param_5;
  local_48 = param_3;
  local_44 = param_4;
  iVar1 = FUN_0001bda8(param_1,auStack_60,0,param_6,2);
  FUN_00026db4(local_18);
  return iVar1;
}



/* 0001ef28 FUN_0001ef28 */

/* Boundary evidence: original MIPS .pdata 0001ef28..0001efa7. Semantic name remains unreviewed. */

int FUN_0001ef28(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,99,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001efa8 FUN_0001efa8 */

/* Boundary evidence: original MIPS .pdata 0001efa8..0001f03b. Semantic name remains unreviewed. */

int FUN_0001efa8(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,int param_5)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  undefined1 local_3f;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,100,param_2,param_5);
  local_40 = param_3;
  local_3f = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f03c FUN_0001f03c */

/* Boundary evidence: original MIPS .pdata 0001f03c..0001f0bb. Semantic name remains unreviewed. */

int FUN_0001f03c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x66,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f0bc FUN_0001f0bc */

/* Boundary evidence: original MIPS .pdata 0001f0bc..0001f15f. Semantic name remains unreviewed. */

int FUN_0001f0bc(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                undefined2 param_5,undefined2 param_6,int param_7)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined2 local_38;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x65,param_2,param_7);
  local_3a = param_5;
  local_38 = param_6;
  local_40 = param_3;
  local_3c = param_4;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f160 FUN_0001f160 */

/* Boundary evidence: original MIPS .pdata 0001f160..0001f1df. Semantic name remains unreviewed. */

int FUN_0001f160(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x67,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f1e0 FUN_0001f1e0 */

/* Boundary evidence: original MIPS .pdata 0001f1e0..0001f25f. Semantic name remains unreviewed. */

int FUN_0001f1e0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 auStack_58 [18];
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x68,param_2,param_3);
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f260 FUN_0001f260 */

/* Boundary evidence: original MIPS .pdata 0001f260..0001f2eb. Semantic name remains unreviewed. */

int FUN_0001f260(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x69,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f2ec FUN_0001f2ec */

/* Boundary evidence: original MIPS .pdata 0001f2ec..0001f3f7. Semantic name remains unreviewed. */

int FUN_0001f2ec(undefined4 param_1,int param_2,int param_3,void *param_4,ushort param_5,
                undefined1 param_6,int param_7)

{
  int *piVar1;
  int local_10;
  
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(param_5 + 0x48,0);
  FUN_00022e34();
  if (piVar1 == (int *)0x0) {
    local_10 = 7;
  }
  else {
    FUN_00019d04(piVar1,0x6a,param_2,param_7);
    FUN_0001fd54((void *)((int)piVar1 + 0x1f),param_4,(uint)param_5);
    piVar1[6] = param_3;
    *(ushort *)(piVar1 + 7) = param_5;
    *(undefined1 *)((int)piVar1 + 0x1e) = param_6;
    local_10 = FUN_0001bd58(param_1,piVar1,(uint)param_5);
    FUN_00022e0c();
    FUN_00020e6c(piVar1);
    FUN_00022e34();
  }
  return local_10;
}



/* 0001f3f8 FUN_0001f3f8 */

/* Boundary evidence: original MIPS .pdata 0001f3f8..0001f483. Semantic name remains unreviewed. */

int FUN_0001f3f8(undefined4 param_1,int param_2,undefined1 param_3,int param_4)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined1 local_40;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x6b,param_2,param_4);
  local_40 = param_3;
  iVar1 = FUN_0001bd58(param_1,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f484 FUN_0001f484 */

/* Boundary evidence: original MIPS .pdata 0001f484..0001f57f. Semantic name remains unreviewed. */

int FUN_0001f484(undefined4 param_1,char *param_2,undefined1 param_3,int param_4,int param_5)

{
  size_t sVar1;
  int *piVar2;
  int local_c;
  
  sVar1 = FUN_0001fddc(param_2);
  FUN_00022e0c();
  piVar2 = FUN_00020d4c(sVar1 + 0x49,0);
  FUN_00022e34();
  if (piVar2 == (int *)0x0) {
    local_c = 7;
  }
  else {
    FUN_00019d04(piVar2,0x1c,param_4,param_5);
    FUN_0001fd54((void *)((int)piVar2 + 0x19),param_2,sVar1 + 1);
    *(undefined1 *)(piVar2 + 6) = param_3;
    local_c = FUN_0001bd58(param_1,piVar2,sVar1 + 1);
    FUN_00022e0c();
    FUN_00020e6c(piVar2);
    FUN_00022e34();
  }
  return local_c;
}



/* 0001f580 FUN_0001f580 */

/* Boundary evidence: original MIPS .pdata 0001f580..0001f6b7. Semantic name remains unreviewed. */

undefined4 FUN_0001f580(undefined4 param_1,char *param_2,void *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 local_c;
  
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(0x1c,0);
  FUN_00022e34();
  if (piVar1 == (int *)0x0) {
    local_c = 7;
  }
  else {
    piVar1[1] = -1;
    FUN_00022e0c();
    piVar2 = FUN_0002337c(param_2);
    *piVar1 = (int)piVar2;
    FUN_00022e34();
    if (*piVar1 == 0) {
      FUN_00022e0c();
      FUN_00020e6c(piVar1);
      FUN_00022e34();
      local_c = 7;
    }
    else {
      FUN_0001fd54(piVar1 + 2,param_3,0xc);
      piVar1[5] = 0;
      piVar1[6] = *(int *)(DAT_0016cb20 + 0x1c);
      **(undefined4 **)(DAT_0016cb20 + 0x1c) = piVar1;
      *(int **)(DAT_0016cb20 + 0x1c) = piVar1 + 5;
      local_c = 0;
    }
  }
  return local_c;
}



/* 0001f6b8 FUN_0001f6b8 */

/* Boundary evidence: original MIPS .pdata 0001f6b8..0001f743. Semantic name remains unreviewed. */

int FUN_0001f6b8(undefined2 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 auStack_58 [6];
  undefined2 local_40;
  undefined1 local_3e;
  uint local_10;
  
  local_10 = DAT_0002d280;
  FUN_00019d04(auStack_58,0x22,0,0);
  local_40 = param_1;
  local_3e = param_2;
  iVar1 = FUN_0001bd58(0,auStack_58,0);
  FUN_00026db4(local_10);
  return iVar1;
}



/* 0001f744 FUN_0001f744 */

/* Boundary evidence: original MIPS .pdata 0001f744..0001f8cf. Semantic name remains unreviewed. */

void FUN_0001f744(undefined4 *param_1,undefined2 param_2,byte param_3)

{
  int *piVar1;
  int iVar2;
  int local_14;
  
  for (local_14 = param_1[6]; (local_14 != 0 && (*(uint *)(local_14 + 4) != (uint)param_3));
      local_14 = *(int *)(local_14 + 0x14)) {
  }
  if (local_14 == 0) {
    FUN_0001f6b8(param_2,4);
  }
  else {
    FUN_00022e0c();
    piVar1 = FUN_00020d4c(0x14,1);
    FUN_00022e34();
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
        FUN_00022e0c();
        FUN_00020e6c(piVar1);
        FUN_00022e34();
      }
    }
  }
  return;
}



/* 0001f8d0 FUN_0001f8d0 */

/* Boundary evidence: original MIPS .pdata 0001f8d0..0001f957. Semantic name remains unreviewed. */

void FUN_0001f8d0(int param_1,char *param_2,byte param_3)

{
  int iVar1;
  undefined4 *local_10;
  
  local_10 = *(undefined4 **)(param_1 + 0x18);
  while( true ) {
    if (local_10 == (undefined4 *)0x0) {
      return;
    }
    iVar1 = FUN_0001fe10(param_2,(char *)*local_10);
    if (iVar1 == 0) break;
    local_10 = (undefined4 *)local_10[5];
  }
  local_10[1] = (uint)param_3;
  return;
}



/* 0001f958 FUN_0001f958 */

/* Boundary evidence: original MIPS .pdata 0001f958..0001fa67. Semantic name remains unreviewed. */

void FUN_0001f958(int param_1,short param_2)

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
    FUN_00022e0c();
    FUN_00020e6c((undefined4 *)local_10);
    FUN_00022e34();
  }
  return;
}



/* 0001fa68 FUN_0001fa68 */

/* Boundary evidence: original MIPS .pdata 0001fa68..0001fb1b. Semantic name remains unreviewed. */

void FUN_0001fa68(int param_1,short param_2,undefined4 param_3,undefined2 param_4)

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



/* 0001fb1c FUN_0001fb1c */

/* Boundary evidence: original MIPS .pdata 0001fb1c..0001fb5f. Semantic name remains unreviewed. */

int FUN_0001fb1c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_00024218("wince_usbware_entry: USER MODE\n",param_2,param_3,param_4);
  iVar1 = FUN_0001fb94((undefined **)0x0,param_2,param_3,param_4);
  return iVar1;
}



/* 0001fb60 FUN_0001fb60 */

/* Boundary evidence: original MIPS .pdata 0001fb60..0001fb93. Semantic name remains unreviewed. */

void FUN_0001fb60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00024218("wince_usbware_exit: USER MODE\n",param_2,param_3,param_4);
  FUN_0001fc78();
  return;
}



/* 0001fb94 FUN_0001fb94 */

/* Boundary evidence: original MIPS .pdata 0001fb94..0001fc77. Semantic name remains unreviewed. */

int FUN_0001fb94(undefined **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined **local_res0;
  int local_c;
  
  local_c = FUN_000243ec();
  if (local_c == 0) {
    local_res0 = param_1;
    if (param_1 == (undefined **)0x0) {
      local_res0 = FUN_00024c38();
    }
    local_c = FUN_00024680((uint *)local_res0,param_2,param_3,param_4);
    if (local_c == 0) {
      local_c = 0;
    }
    else {
      pcVar1 = FUN_00023a74(local_c);
      FUN_00024218("%s: Error starting the usb stack %s\n","j_stack_init",pcVar1,param_4);
      FUN_0002444c();
    }
  }
  else {
    FUN_00024218("%s: Error initializing memory\n","j_stack_init",param_3,param_4);
  }
  return local_c;
}



/* 0001fc78 FUN_0001fc78 */

/* Boundary evidence: original MIPS .pdata 0001fc78..0001fc9f. Semantic name remains unreviewed. */

void FUN_0001fc78(void)

{
  FUN_000247dc();
  FUN_0002444c();
  return;
}



/* 0001fca0 FUN_0001fca0 */

/* Boundary evidence: original MIPS .pdata 0001fca0..0001fcef. Semantic name remains unreviewed. */

undefined4 FUN_0001fca0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0002056c();
  return uVar1;
}



/* 0001fcf0 FUN_0001fcf0 */

/* Boundary evidence: original MIPS .pdata 0001fcf0..0001fd0f. Semantic name remains unreviewed. */

void FUN_0001fcf0(void)

{
  FUN_00020620();
  return;
}



/* 0001fd10 FUN_0001fd10 */

/* Boundary evidence: original MIPS .pdata 0001fd10..0001fd53. Semantic name remains unreviewed. */

int FUN_0001fd10(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,param_3);
  return iVar1;
}



/* 0001fd54 FUN_0001fd54 */

/* Boundary evidence: original MIPS .pdata 0001fd54..0001fd97. Semantic name remains unreviewed. */

void * FUN_0001fd54(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memcpy(param_1,param_2,param_3);
  return pvVar1;
}



/* 0001fd98 FUN_0001fd98 */

/* Boundary evidence: original MIPS .pdata 0001fd98..0001fddb. Semantic name remains unreviewed. */

void * FUN_0001fd98(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memset(param_1,param_2,param_3);
  return pvVar1;
}



/* 0001fddc FUN_0001fddc */

/* Boundary evidence: original MIPS .pdata 0001fddc..0001fe0f. Semantic name remains unreviewed. */

size_t FUN_0001fddc(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  return sVar1;
}



/* 0001fe10 FUN_0001fe10 */

/* Boundary evidence: original MIPS .pdata 0001fe10..0001fe4b. Semantic name remains unreviewed. */

int FUN_0001fe10(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  return iVar1;
}



/* 0001fe4c FUN_0001fe4c */

/* Boundary evidence: original MIPS .pdata 0001fe4c..0001fe8f. Semantic name remains unreviewed. */

int FUN_0001fe4c(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = strncmp(param_1,param_2,param_3);
  return iVar1;
}



/* 0001fe90 FUN_0001fe90 */

/* Boundary evidence: original MIPS .pdata 0001fe90..0001ff3b. Semantic name remains unreviewed. */

int FUN_0001fe90(char *param_1,size_t param_2,char *param_3,undefined4 param_4)

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



/* 0001ff3c FUN_0001ff3c */

/* Boundary evidence: original MIPS .pdata 0001ff3c..00020063. Semantic name remains unreviewed. */

undefined4 FUN_0001ff3c(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *lpParameter;
  HANDLE pvVar1;
  int iVar2;
  undefined4 local_14;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  lpParameter = FUN_00020d4c(8,1);
  if (lpParameter == (int *)0x0) {
    local_14 = 7;
  }
  else {
    *lpParameter = param_1;
    lpParameter[1] = param_2;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00020064,lpParameter,0,(LPDWORD)0x0);
    if (pvVar1 == (HANDLE)0x0) {
      FUN_00020e6c(lpParameter);
      local_14 = 10;
    }
    else {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = pvVar1;
      }
      iVar2 = FUN_000200f4(param_3);
      CeSetThreadPriority(pvVar1,iVar2);
      local_14 = 0;
    }
  }
  return local_14;
}



/* 00020064 FUN_00020064 */

/* Boundary evidence: original MIPS .pdata 00020064..000200f3. Semantic name remains unreviewed. */

undefined4 FUN_00020064(int *param_1)

{
  undefined4 local_c;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    local_c = 0;
  }
  else {
    FUN_00022e0c();
    (*(code *)*param_1)(param_1[1]);
    FUN_00020e6c(param_1);
    FUN_00022e34();
    local_c = 1;
  }
  return local_c;
}



/* 000200f4 FUN_000200f4 */

/* Boundary evidence: original MIPS .pdata 000200f4..0002011f. Semantic name remains unreviewed. */

int FUN_000200f4(int param_1)

{
  return DAT_0016cb58 + param_1;
}



/* 00020120 FUN_00020120 */

/* Boundary evidence: original MIPS .pdata 00020120..0002014b. Semantic name remains unreviewed. */

undefined4 FUN_00020120(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00020628();
  return uVar1;
}



/* 0002014c FUN_0002014c */

/* Boundary evidence: original MIPS .pdata 0002014c..000201c7. Semantic name remains unreviewed. */

undefined4 FUN_0002014c(undefined4 *param_1)

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



/* 000201c8 FUN_000201c8 */

/* Boundary evidence: original MIPS .pdata 000201c8..0002020b. Semantic name remains unreviewed. */

void FUN_000201c8(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    CloseHandle(param_1);
  }
  return;
}



/* 0002020c FUN_0002020c */

/* Boundary evidence: original MIPS .pdata 0002020c..0002025b. Semantic name remains unreviewed. */

void FUN_0002020c(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    WaitForSingleObject(param_1,0xffffffff);
  }
  return;
}



/* 0002025c FUN_0002025c */

/* Boundary evidence: original MIPS .pdata 0002025c..0002029b. Semantic name remains unreviewed. */

void FUN_0002025c(HANDLE param_1)

{
  ReleaseSemaphore(param_1,1,(LPLONG)0x0);
  return;
}



/* 000202a8 FUN_000202a8 */

/* Boundary evidence: original MIPS .pdata 000202a8..000202cf. Semantic name remains unreviewed. */

void FUN_000202a8(int param_1)

{
  FUN_00026748(param_1);
  return;
}



/* 000202d0 FUN_000202d0 */

/* Boundary evidence: original MIPS .pdata 000202d0..0002030f. Semantic name remains unreviewed. */

void FUN_000202d0(DWORD param_1)

{
  FUN_00022e34();
  Sleep(param_1);
  FUN_00022e0c();
  return;
}



/* 00020310 FUN_00020310 */

/* Boundary evidence: original MIPS .pdata 00020310..0002038b. Semantic name remains unreviewed. */

undefined4 FUN_00020310(undefined4 *param_1)

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



/* 0002038c FUN_0002038c */

/* Boundary evidence: original MIPS .pdata 0002038c..000203bb. Semantic name remains unreviewed. */

void FUN_0002038c(HANDLE param_1)

{
  CloseHandle(param_1);
  return;
}



/* 000203bc FUN_000203bc */

/* Boundary evidence: original MIPS .pdata 000203bc..0002048f. Semantic name remains unreviewed. */

undefined4 FUN_000203bc(HANDLE param_1,DWORD param_2)

{
  DWORD DVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_00022e34();
  local_10 = param_2;
  if (param_2 == 0) {
    local_10 = 0xffffffff;
  }
  DVar1 = WaitForSingleObject(param_1,local_10);
  FUN_00022e0c();
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



/* 00020490 FUN_00020490 */

/* Boundary evidence: original MIPS .pdata 00020490..000204db. Semantic name remains unreviewed. */

undefined4 FUN_00020490(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  
  iVar1 = FUN_00011000(param_1);
  if (iVar1 == 0) {
    local_10 = 10;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* 000204dc FUN_000204dc */

/* Boundary evidence: original MIPS .pdata 000204dc..0002054b. Semantic name remains unreviewed. */

void FUN_000204dc(uint *param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *param_1 = DVar1 / 1000;
  param_1[1] = (DVar1 % 1000) * 1000;
  return;
}



/* 0002054c FUN_0002054c */

/* Boundary evidence: original MIPS .pdata 0002054c..0002056b. Semantic name remains unreviewed. */

undefined4 FUN_0002054c(void)

{
  return DAT_0016cb60;
}



/* 0002056c FUN_0002056c */

/* Boundary evidence: original MIPS .pdata 0002056c..0002061f. Semantic name remains unreviewed. */

undefined4 FUN_0002056c(void)

{
  BOOL BVar1;
  undefined8 uVar2;
  undefined4 local_10;
  
  BVar1 = QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_0016cb60);
  uVar2 = CONCAT44(DAT_0016cb54,DAT_0016cb50);
  if ((BVar1 == 0) || (DAT_0016cb60 == 0 && DAT_0016cb64 == 0)) {
    local_10 = 10;
  }
  else {
    uVar2 = __ll_div(DAT_0016cb60,DAT_0016cb64,&DAT_000f4240,0);
    DAT_0016cb58 = 100;
    local_10 = 0;
  }
  DAT_0016cb54 = (undefined4)((ulonglong)uVar2 >> 0x20);
  DAT_0016cb50 = (undefined4)uVar2;
  return local_10;
}



/* 00020620 FUN_00020620 */

void FUN_00020620(void)

{
  return;
}



/* 00020628 FUN_00020628 */

/* Boundary evidence: original MIPS .pdata 00020628..00020657. Semantic name remains unreviewed. */

undefined4 FUN_00020628(void)

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(8);
  return uVar1;
}



/* 00020658 FUN_00020658 */

/* Boundary evidence: original MIPS .pdata 00020658..000209a3. Semantic name remains unreviewed. */

int FUN_00020658(int param_1,int param_2,int param_3,undefined4 *param_4)

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
  
  local_34 = DAT_0002d280;
  local_3c = L"UWD1:";
  local_54 = 0;
  local_50 = FUN_00020d4c(0x1018,1);
  if (local_50 == (int *)0x0) {
    FUN_00026db4(local_34);
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
      FUN_00024218("os_user_create: get version ioctl failed\n",pcVar5,uVar6,uVar7);
      local_58 = 5;
    }
    else {
      if (local_54 == 10) {
        uVar6 = 10;
        pcVar5 = "3.5.14.82";
        iVar4 = FUN_0001fd10(abStack_49 + 1,"3.5.14.82",10);
        if (iVar4 == 0) {
          local_58 = FUN_0001ff3c(0x209a4,(int)local_50,3,"ioctl_recv_thread",local_50 + 0x405);
          if (local_58 == 0) {
            FUN_00026db4(local_34);
            return 0;
          }
          goto LAB_00020970;
        }
      }
      if (local_54 == 0) {
        FUN_00024218("os_user_create: get version ioctl returned empty string\n",pcVar5,uVar6,uVar7)
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
        FUN_00024218("os_user_create: get version ioctl returned unmatched  version \"%s\"\n",
                     abStack_49 + 1,uVar6,uVar7);
      }
      local_58 = 10;
    }
  }
LAB_00020970:
  FUN_00020a98(local_50);
  FUN_00026db4(local_34);
  return local_58;
}



/* 000209a4 FUN_000209a4 */

/* Boundary evidence: original MIPS .pdata 000209a4..00020a97. Semantic name remains unreviewed. */

undefined4 FUN_000209a4(undefined4 *param_1)

{
  char local_30 [4];
  int local_2c;
  undefined4 *local_28;
  DWORD local_24 [7];
  
  local_30[0] = '\0';
  local_28 = param_1;
  while( true ) {
    FUN_00022e34();
    local_2c = DeviceIoControl((HANDLE)local_28[1],0x81002040,local_30,1,local_28 + 3,0x1008,
                               local_24,(LPOVERLAPPED)0x0);
    FUN_00022e0c();
    if (local_2c == 0) {
      return 5;
    }
    if (local_30[0] != '\0') break;
    (*(code *)local_28[2])(*local_28,local_28 + 3,local_24[0]);
  }
  return 0;
}



/* 00020a98 FUN_00020a98 */

/* Boundary evidence: original MIPS .pdata 00020a98..00020bab. Semantic name remains unreviewed. */

void FUN_00020a98(undefined4 *param_1)

{
  DWORD aDStack_1c [5];
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[0x405] != 0) {
      FUN_00022e34();
      DeviceIoControl((HANDLE)param_1[1],0x81002044,(LPVOID)0x0,0,(LPVOID)0x0,0,aDStack_1c,
                      (LPOVERLAPPED)0x0);
      WaitForSingleObject((HANDLE)param_1[0x405],0xffffffff);
      CloseHandle((HANDLE)param_1[0x405]);
      FUN_00022e0c();
    }
    if (param_1[1] != -1) {
      CloseHandle((HANDLE)param_1[1]);
    }
    FUN_00020e6c(param_1);
  }
  return;
}



/* 00020bac FUN_00020bac */

/* Boundary evidence: original MIPS .pdata 00020bac..00020c8f. Semantic name remains unreviewed. */

undefined4 FUN_00020bac(int param_1,int param_2)

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



/* 00020c90 FUN_00020c90 */

void FUN_00020c90(void)

{
  return;
}



/* 00020c98 FUN_00020c98 */

/* Boundary evidence: original MIPS .pdata 00020c98..00020d43. Semantic name remains unreviewed. */

void FUN_00020c98(void)

{
  uint local_8;
  
  for (local_8 = 0; (int)local_8 < 6; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0016cb68 + local_8 * 4) = 0;
  }
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    *(int *)(&DAT_0016cb80 + local_8 * 4) = 0x10 << (local_8 & 0x1f);
  }
  return;
}



/* 00020d44 FUN_00020d44 */

void FUN_00020d44(void)

{
  return;
}



/* 00020d4c FUN_00020d4c */

/* Boundary evidence: original MIPS .pdata 00020d4c..00020e6b. Semantic name remains unreviewed. */

int * FUN_00020d4c(uint param_1,ushort param_2)

{
  int local_18;
  int *local_14;
  
  for (local_18 = 0; (local_18 < 5 && (*(uint *)(&DAT_0016cb80 + local_18 * 4) < param_1));
      local_18 = local_18 + 1) {
  }
  if (local_18 < 5) {
    local_14 = FUN_00020f20((int *)(&DAT_0016cb68 + local_18 * 4),
                            *(int *)(&DAT_0016cb80 + local_18 * 4));
  }
  else {
    local_14 = FUN_000211a0((int *)&DAT_0016cb7c,param_1);
  }
  if ((local_14 != (int *)0x0) && ((param_2 & 1) != 0)) {
    FUN_0001fd98(local_14,0,param_1);
  }
  return local_14;
}



/* 00020e6c FUN_00020e6c */

/* Boundary evidence: original MIPS .pdata 00020e6c..00020f1f. Semantic name remains unreviewed. */

void FUN_00020e6c(undefined4 *param_1)

{
  int local_8;
  
  for (local_8 = 0; (local_8 < 5 && (*(uint *)(&DAT_0016cb80 + local_8 * 4) < (uint)param_1[-1]));
      local_8 = local_8 + 1) {
  }
  *param_1 = *(undefined4 *)(&DAT_0016cb68 + local_8 * 4);
  *(undefined4 **)(&DAT_0016cb68 + local_8 * 4) = param_1;
  return;
}



/* 00020f20 FUN_00020f20 */

/* Boundary evidence: original MIPS .pdata 00020f20..00020fab. Semantic name remains unreviewed. */

int * FUN_00020f20(int *param_1,int param_2)

{
  int *local_10;
  
  if (*param_1 == 0) {
    local_10 = FUN_00020fac(param_2);
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



/* 00020fac FUN_00020fac */

/* Boundary evidence: original MIPS .pdata 00020fac..00021027. Semantic name remains unreviewed. */

int * FUN_00020fac(int param_1)

{
  int iVar1;
  int *local_18;
  uint local_14;
  int *local_c;
  
  local_14 = param_1 + 4;
  iVar1 = FUN_00021028(local_14,(int *)&local_18,(int *)0x0,0);
  if (iVar1 == 0) {
    *local_18 = param_1;
    local_c = local_18 + 1;
  }
  else {
    local_c = (int *)0x0;
  }
  return local_c;
}



/* 00021028 FUN_00021028 */

/* Boundary evidence: original MIPS .pdata 00021028..0002119f. Semantic name remains unreviewed. */

undefined4 FUN_00021028(uint param_1,int *param_2,int *param_3,int param_4)

{
  uint local_8;
  undefined4 local_4;
  
  local_8 = param_1;
  if ((param_1 & 3) != 0) {
    local_8 = (param_1 + 4) - (param_1 & 3);
  }
  if (*(int *)(&DAT_0016cb98 + param_4 * 4) + local_8 < *(uint *)(&DAT_0016cba0 + param_4 * 4)) {
    if (param_2 != (int *)0x0) {
      *param_2 = *(int *)(&DAT_0016cb94 + param_4 * 4) + *(int *)(&DAT_0016cb98 + param_4 * 4);
    }
    if (param_3 != (int *)0x0) {
      *param_3 = *(int *)(&DAT_0016cb9c + param_4 * 4) + *(int *)(&DAT_0016cb98 + param_4 * 4);
    }
    *(uint *)(&DAT_0016cb98 + param_4 * 4) = *(int *)(&DAT_0016cb98 + param_4 * 4) + local_8;
    local_4 = 0;
  }
  else {
    local_4 = 7;
  }
  return local_4;
}



/* 000211a0 FUN_000211a0 */

/* Boundary evidence: original MIPS .pdata 000211a0..00021273. Semantic name remains unreviewed. */

int * FUN_000211a0(int *param_1,uint param_2)

{
  int *local_18;
  int *local_14;
  
  local_14 = (int *)0x0;
  local_18 = param_1;
  do {
    if (*local_18 == 0) {
LAB_00021220:
      if ((local_14 == (int *)0x0) && (local_14 = FUN_00020fac(param_2), local_14 == (int *)0x0)) {
        return (int *)0x0;
      }
      return local_14;
    }
    if (param_2 <= *(uint *)(*local_18 + -4)) {
      local_14 = (int *)*local_18;
      *local_18 = *local_14;
      goto LAB_00021220;
    }
    local_18 = (int *)*local_18;
  } while( true );
}



/* 00021274 FUN_00021274 */

/* Boundary evidence: original MIPS .pdata 00021274..000212a3. Semantic name remains unreviewed. */

int FUN_00021274(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) + param_2;
}



/* 000212a4 FUN_000212a4 */

/* Boundary evidence: original MIPS .pdata 000212a4..000212d3. Semantic name remains unreviewed. */

int FUN_000212a4(int *param_1,int param_2)

{
  return *param_1 + param_2;
}



/* 000212d4 FUN_000212d4 */

/* Boundary evidence: original MIPS .pdata 000212d4..000212f3. Semantic name remains unreviewed. */

undefined4 FUN_000212d4(undefined4 param_1)

{
  return param_1;
}



/* 000212f4 FUN_000212f4 */

/* Boundary evidence: original MIPS .pdata 000212f4..000215b3. Semantic name remains unreviewed. */

int FUN_000212f4(uint param_1,ushort param_2,int *param_3,int *param_4,ushort param_5,
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
    piVar3 = FUN_00020d4c(0x20,1);
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
    local_18 = FUN_00021bd8(local_14,uVar1,param_5,(int *)&local_1c);
    if ((local_18 == 0) &&
       (((local_1c != (int *)0x0 || ((param_5 & 2) == 0)) ||
        (local_18 = FUN_00021bd8(uVar2,uVar1,param_5 & 0xfffd,(int *)&local_1c), local_18 == 0)))) {
      if (local_1c == (int *)0x0) {
        iVar4 = FUN_000215b4(uVar2,uVar1,param_5);
        piVar3 = DAT_0016cba4;
        if (iVar4 != 0) {
          return iVar4;
        }
        local_1c = DAT_0016cba4;
        if (DAT_0016cba4[6] != 0) {
          *(int *)(DAT_0016cba4[6] + 0x1c) = DAT_0016cba4[7];
        }
        *(int *)piVar3[7] = piVar3[6];
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = local_1c;
      }
      if (param_3 != (int *)0x0) {
        iVar4 = FUN_000212a4(local_1c,0);
        *param_3 = iVar4;
      }
      if (param_4 != (int *)0x0) {
        iVar4 = FUN_00021274((int)local_1c,0);
        *param_4 = iVar4;
      }
      if ((param_5 & 1) != 0) {
        pvVar5 = (void *)FUN_000212a4(local_1c,0);
        FUN_0001fd98(pvVar5,0,uVar2);
      }
      local_18 = 0;
    }
  }
  return local_18;
}



/* 000215b4 FUN_000215b4 */

/* Boundary evidence: original MIPS .pdata 000215b4..000215f7. Semantic name remains unreviewed. */

int FUN_000215b4(uint param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  
  iVar1 = FUN_000215f8(param_1,param_2,param_3);
  return iVar1;
}



/* 000215f8 FUN_000215f8 */

/* Boundary evidence: original MIPS .pdata 000215f8..00021873. Semantic name remains unreviewed. */

int FUN_000215f8(uint param_1,ushort param_2,ushort param_3)

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
    local_3c = FUN_00021a5c(local_2c,&local_34,(int *)&local_40,(uint)param_3,&local_24,&local_20);
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
      FUN_00021af4(local_28,local_24,local_34,local_40);
      FUN_00021af4((local_2c - param_1) - local_28,local_24,local_30 + local_28 + param_1,
                   local_38 + local_28 + param_1);
      local_1c = FUN_00021874(param_1,local_24,local_30 + local_28,local_38 + local_28,local_20);
    }
  }
  else {
    local_1c = 10;
  }
  return local_1c;
}



/* 00021874 FUN_00021874 */

/* Boundary evidence: original MIPS .pdata 00021874..000219ff. Semantic name remains unreviewed. */

undefined4 FUN_00021874(int param_1,int param_2,int param_3,uint param_4,int param_5)

{
  int *piVar1;
  ushort local_18;
  undefined4 local_c;
  
  piVar1 = FUN_00020d4c(0x20,1);
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
    FUN_00021a00((int)piVar1);
    local_c = 0;
  }
  return local_c;
}



/* 00021a00 FUN_00021a00 */

void FUN_00021a00(int param_1)

{
  *(int *)(param_1 + 0x18) = DAT_0016cba4;
  if (DAT_0016cba4 != 0) {
    *(int *)(DAT_0016cba4 + 0x1c) = param_1 + 0x18;
  }
  DAT_0016cba4 = param_1;
  *(int **)(param_1 + 0x1c) = &DAT_0016cba4;
  return;
}



/* 00021a5c FUN_00021a5c */

/* Boundary evidence: original MIPS .pdata 00021a5c..00021af3. Semantic name remains unreviewed. */

undefined4
FUN_00021a5c(uint param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5,
            int *param_6)

{
  int *piVar1;
  undefined4 local_10;
  
  local_10 = 0;
  piVar1 = FUN_00020d4c(param_1,0);
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



/* 00021af4 FUN_00021af4 */

/* Boundary evidence: original MIPS .pdata 00021af4..00021bd7. Semantic name remains unreviewed. */

void FUN_00021af4(uint param_1,int param_2,int param_3,uint param_4)

{
  uint local_18;
  
  local_18 = 0;
  if (0x1f < param_1) {
    if ((param_4 & 3) != 0) {
      local_18 = 4 - (param_4 & 3);
    }
    if ((local_18 < param_1) && (0x1f < param_1 - local_18)) {
      FUN_00021874(param_1 - local_18,param_2,param_3 + local_18,param_4 + local_18,0);
    }
  }
  return;
}



/* 00021bd8 FUN_00021bd8 */

/* Boundary evidence: original MIPS .pdata 00021bd8..00021d83. Semantic name remains unreviewed. */

undefined4 FUN_00021bd8(uint param_1,ushort param_2,ushort param_3,int *param_4)

{
  int local_8;
  
  *param_4 = 0;
  if (param_1 != 0) {
    for (local_8 = DAT_0016cba4; local_8 != 0; local_8 = *(int *)(local_8 + 0x18)) {
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



/* 00021d84 FUN_00021d84 */

/* Boundary evidence: original MIPS .pdata 00021d84..00021ddb. Semantic name remains unreviewed. */

void FUN_00021d84(undefined4 *param_1)

{
  if ((*(byte *)((int)param_1 + 0x12) & 8) == 0) {
    FUN_00021a00((int)param_1);
  }
  else {
    FUN_00020e6c(param_1);
  }
  return;
}



/* 00021ddc FUN_00021ddc */

/* Boundary evidence: original MIPS .pdata 00021ddc..00021ea3. Semantic name remains unreviewed. */

void FUN_00021ddc(void)

{
  undefined4 *puVar1;
  
  while (puVar1 = DAT_0016cba4, DAT_0016cba4 != (undefined4 *)0x0) {
    if (DAT_0016cba4[6] != 0) {
      *(undefined4 *)(DAT_0016cba4[6] + 0x1c) = DAT_0016cba4[7];
    }
    *(undefined4 *)puVar1[7] = puVar1[6];
    if ((*(byte *)((int)puVar1 + 0x12) & 4) == 0) {
      FUN_00020e6c(puVar1);
    }
    else {
      FUN_00020e6c((undefined4 *)puVar1[5]);
      FUN_00020e6c(puVar1);
    }
  }
  return;
}



/* 00021ea4 FUN_00021ea4 */

/* Boundary evidence: original MIPS .pdata 00021ea4..00021efb. Semantic name remains unreviewed. */

undefined4 FUN_00021ea4(uint *param_1)

{
  FUN_00020c98();
  FUN_00021efc(0,*param_1,*param_1,param_1[1]);
  return 0;
}



/* 00021efc FUN_00021efc */

/* Boundary evidence: original MIPS .pdata 00021efc..00021fb3. Semantic name remains unreviewed. */

void FUN_00021efc(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_8;
  
  local_8 = param_2 & 3;
  if (local_8 != 0) {
    local_8 = 4 - local_8;
  }
  *(uint *)(&DAT_0016cb98 + param_1 * 4) = local_8;
  *(undefined4 *)(&DAT_0016cba0 + param_1 * 4) = param_4;
  *(uint *)(&DAT_0016cb94 + param_1 * 4) = param_2;
  *(undefined4 *)(&DAT_0016cb9c + param_1 * 4) = param_3;
  return;
}



/* 00021fb4 FUN_00021fb4 */

/* Boundary evidence: original MIPS .pdata 00021fb4..00021fd3. Semantic name remains unreviewed. */

void FUN_00021fb4(void)

{
  FUN_00020d44();
  return;
}



/* 00021fd4 FUN_00021fd4 */

/* Boundary evidence: original MIPS .pdata 00021fd4..000220a7. Semantic name remains unreviewed. */

int FUN_00021fd4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    piVar1 = FUN_00020d4c(0x28,1);
    *param_1 = (int)piVar1;
    if (*param_1 == 0) {
      local_c = 7;
    }
    else {
      local_c = FUN_00020310((undefined4 *)(*param_1 + 0x24));
      if (local_c == 0) {
        *(undefined4 *)(*param_1 + 0xc) = param_2;
        local_c = 0;
      }
      else {
        FUN_00020e6c((undefined4 *)*param_1);
      }
    }
  }
  return local_c;
}



/* 000220a8 FUN_000220a8 */

/* Boundary evidence: original MIPS .pdata 000220a8..0002217b. Semantic name remains unreviewed. */

void FUN_000220a8(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if ((((*(char *)(param_1 + 6) == '\x01') || (*(char *)(param_1 + 6) == '\x03')) ||
        (*(char *)(param_1 + 6) == '\x04')) && (uVar1 = FUN_00023038(), param_1[7] == uVar1)) {
      param_1[8] = 1;
    }
    else {
      FUN_00022350((int)param_1);
      FUN_0002038c((HANDLE)param_1[9]);
      FUN_00020e6c(param_1);
    }
  }
  return;
}



/* 0002217c FUN_0002217c */

/* Boundary evidence: original MIPS .pdata 0002217c..000222b7. Semantic name remains unreviewed. */

undefined4 FUN_0002217c(int *param_1,int param_2,int param_3,int param_4)

{
  uint local_20;
  int local_1c;
  undefined4 local_18;
  uint local_c;
  
  if (param_1 == (int *)0x0) {
    local_18 = 10;
  }
  else {
    FUN_000204dc(&local_20);
    local_c = (uint)*(byte *)(param_1 + 6);
    switch(local_c) {
    case 0:
      *(undefined1 *)(param_1 + 6) = 2;
      break;
    case 1:
      *(undefined1 *)(param_1 + 6) = 3;
      break;
    case 2:
      FUN_000222b8((int)param_1);
      break;
    case 3:
      FUN_000222b8((int)param_1);
      break;
    case 4:
      return 0x10;
    }
    FUN_000224a4(param_1,local_20,local_1c,param_2,param_3,param_4);
    FUN_0002263c(param_1[3]);
    local_18 = 0;
  }
  return local_18;
}



/* 000222b8 FUN_000222b8 */

/* Boundary evidence: original MIPS .pdata 000222b8..0002234f. Semantic name remains unreviewed. */

void FUN_000222b8(int param_1)

{
  int *local_8;
  
  for (local_8 = (int *)(&DAT_0016cbb0 + *(int *)(param_1 + 0xc) * 0x34);
      (*local_8 != 0 && (*local_8 != param_1)); local_8 = (int *)*local_8) {
  }
  *local_8 = *(int *)*local_8;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* 00022350 FUN_00022350 */

/* Boundary evidence: original MIPS .pdata 00022350..00022433. Semantic name remains unreviewed. */

void FUN_00022350(int param_1)

{
  uint auStack_18 [2];
  uint local_10;
  
  if (param_1 != 0) {
    FUN_000204dc(auStack_18);
    local_10 = (uint)*(byte *)(param_1 + 0x18);
    switch(local_10) {
    case 0:
      break;
    case 1:
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_00022434(param_1);
      break;
    case 2:
      FUN_000222b8(param_1);
      *(undefined1 *)(param_1 + 0x18) = 0;
      break;
    case 3:
      FUN_000222b8(param_1);
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_00022434(param_1);
    }
  }
  return;
}



/* 00022434 FUN_00022434 */

/* Boundary evidence: original MIPS .pdata 00022434..000224a3. Semantic name remains unreviewed. */

void FUN_00022434(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00023038();
  if (*(uint *)(param_1 + 0x1c) != uVar1) {
    while (*(char *)(param_1 + 0x18) != '\0') {
      FUN_000203bc(*(HANDLE *)(param_1 + 0x24),0);
    }
  }
  return;
}



/* 000224a4 FUN_000224a4 */

/* Boundary evidence: original MIPS .pdata 000224a4..0002263b. Semantic name remains unreviewed. */

void FUN_000224a4(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

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
  FUN_0001fd54(param_1 + 1,&local_res4,8);
  for (local_10 = (int *)(&DAT_0016cbb0 + param_1[3] * 0x34); *local_10 != 0;
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



/* 0002263c FUN_0002263c */

/* Boundary evidence: original MIPS .pdata 0002263c..000226bb. Semantic name remains unreviewed. */

void FUN_0002263c(int param_1)

{
  if (*(int *)(&DAT_0016cbb0 + param_1 * 0x34) != 0) {
    FUN_00020490(*(undefined4 *)(&DAT_0016cbac + param_1 * 0x34));
  }
  return;
}



/* 000226bc FUN_000226bc */

/* Boundary evidence: original MIPS .pdata 000226bc..00022787. Semantic name remains unreviewed. */

int FUN_000226bc(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (0 < local_14) {
      return 0;
    }
    iVar1 = FUN_00022788(local_14);
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  while (local_14 = local_14 + -1, -1 < local_14) {
    FUN_00022bf8(local_14);
  }
  return iVar1;
}



/* 00022788 FUN_00022788 */

/* Boundary evidence: original MIPS .pdata 00022788..000228c3. Semantic name remains unreviewed. */

int FUN_00022788(int param_1)

{
  int iVar1;
  int local_18;
  
  iVar1 = param_1 * 0x34;
  FUN_0001fd98(&DAT_0016cbac + iVar1,0,0x34);
  local_18 = FUN_00020310((undefined4 *)(&DAT_0016cbac + iVar1));
  if (local_18 == 0) {
    (&DAT_0016cbdc)[iVar1] = (&DAT_0016cbdc)[iVar1] | 1;
    (&DAT_0016cbdc)[iVar1] = (&DAT_0016cbdc)[iVar1] | 4;
    local_18 = FUN_0001ff3c(0x228c4,param_1,param_1,(&PTR_s_uw_Controller_0002d23c)[param_1],
                            (undefined4 *)(iVar1 + 0x16cbd8));
    if (local_18 == 0) {
      (&DAT_0016cbdc)[iVar1] = (&DAT_0016cbdc)[iVar1] | 2;
      return 0;
    }
  }
  FUN_00022bf8(param_1);
  return local_18;
}



/* 000228c4 FUN_000228c4 */

/* Boundary evidence: original MIPS .pdata 000228c4..00022bf7. Semantic name remains unreviewed. */

void FUN_000228c4(int param_1)

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
  
  local_28 = (undefined4 *)(&DAT_0016cbac + param_1 * 0x34);
  while ((*(byte *)(local_28 + 0xc) & 4) != 0) {
    FUN_000204dc(&local_30);
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
      FUN_000203bc((HANDLE)*local_28,local_20);
    }
    *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) & 0xef;
    local_24 = (undefined4 *)local_28[1];
    if (local_24 != (undefined4 *)0x0) {
      FUN_000204dc(&local_30);
      local_14 = (uint)((int)((local_24[1] - local_30) * 1000 + (local_24[2] - local_2c) / 1000) < 1
                       );
      if (local_14 != 0) {
        local_1c = (code *)local_24[4];
        uVar2 = local_24[5];
        FUN_000222b8((int)local_24);
        *(undefined1 *)(local_24 + 6) = 1;
        uVar1 = FUN_00023038();
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
            FUN_00020490(local_24[9]);
          }
        }
        else {
          if (*(char *)(local_24 + 6) == '\x03') {
            FUN_000222b8((int)local_24);
          }
          FUN_0002038c((HANDLE)local_24[9]);
          FUN_00020e6c(local_24);
        }
      }
    }
  }
  *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) | 8;
  return;
}



/* 00022bf8 FUN_00022bf8 */

/* Boundary evidence: original MIPS .pdata 00022bf8..00022cfb. Semantic name remains unreviewed. */

void FUN_00022bf8(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x34;
  if (((&DAT_0016cbdc)[iVar1] & 2) != 0) {
    if (*(int *)(&DAT_0016cbb0 + iVar1) != 0) {
      *(undefined4 *)(&DAT_0016cbb0 + iVar1) = 0;
    }
    (&DAT_0016cbdc)[iVar1] = (&DAT_0016cbdc)[iVar1] & 0xfb;
    FUN_00020490(*(undefined4 *)(&DAT_0016cbac + iVar1));
    while (((&DAT_0016cbdc)[iVar1] & 8) == 0) {
      FUN_000202d0(0x37);
    }
  }
  if (((&DAT_0016cbdc)[iVar1] & 1) != 0) {
    (&DAT_0016cbdc)[iVar1] = (&DAT_0016cbdc)[iVar1] & 0xfe;
    FUN_0002038c(*(HANDLE *)(&DAT_0016cbac + iVar1));
  }
  return;
}



/* 00022cfc FUN_00022cfc */

/* Boundary evidence: original MIPS .pdata 00022cfc..00022d4f. Semantic name remains unreviewed. */

void FUN_00022cfc(void)

{
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
    FUN_00022bf8(local_10);
  }
  return;
}



/* 00022d50 FUN_00022d50 */

/* Boundary evidence: original MIPS .pdata 00022d50..00022d77. Semantic name remains unreviewed. */

void FUN_00022d50(void)

{
  FUN_00022e5c(DAT_0016cbe0);
  return;
}



/* 00022d78 FUN_00022d78 */

/* Boundary evidence: original MIPS .pdata 00022d78..00022d9f. Semantic name remains unreviewed. */

void FUN_00022d78(void)

{
  FUN_00022e94(DAT_0016cbe0);
  return;
}



/* 00022da0 FUN_00022da0 */

/* Boundary evidence: original MIPS .pdata 00022da0..00022dd3. Semantic name remains unreviewed. */

undefined4 FUN_00022da0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0002014c(&DAT_0016cbe4);
  return uVar1;
}



/* 00022dd4 FUN_00022dd4 */

/* Boundary evidence: original MIPS .pdata 00022dd4..00022e0b. Semantic name remains unreviewed. */

void FUN_00022dd4(void)

{
  HANDLE pvVar1;
  
  pvVar1 = DAT_0016cbe4;
  DAT_0016cbe4 = (HANDLE)0x0;
  FUN_000201c8(pvVar1);
  return;
}



/* 00022e0c FUN_00022e0c */

/* Boundary evidence: original MIPS .pdata 00022e0c..00022e33. Semantic name remains unreviewed. */

void FUN_00022e0c(void)

{
  FUN_0002020c(DAT_0016cbe4);
  return;
}



/* 00022e34 FUN_00022e34 */

/* Boundary evidence: original MIPS .pdata 00022e34..00022e5b. Semantic name remains unreviewed. */

void FUN_00022e34(void)

{
  FUN_0002025c(DAT_0016cbe4);
  return;
}



/* 00022e5c FUN_00022e5c */

/* Boundary evidence: original MIPS .pdata 00022e5c..00022e93. Semantic name remains unreviewed. */

void FUN_00022e5c(HANDLE param_1)

{
  FUN_00022e34();
  FUN_0002020c(param_1);
  FUN_00022e0c();
  return;
}



/* 00022e94 FUN_00022e94 */

/* Boundary evidence: original MIPS .pdata 00022e94..00022ebb. Semantic name remains unreviewed. */

void FUN_00022e94(HANDLE param_1)

{
  FUN_0002025c(param_1);
  return;
}



/* 00022ebc FUN_00022ebc */

/* Boundary evidence: original MIPS .pdata 00022ebc..00022f4f. Semantic name remains unreviewed. */

int FUN_00022ebc(void)

{
  int local_10;
  
  DAT_0002d238 = 4;
  FUN_0001fd98(&DAT_0016cba8,0,4);
  local_10 = FUN_000226bc();
  if ((local_10 == 0) && (local_10 = FUN_0002014c(&DAT_0016cbe0), local_10 != 0)) {
    FUN_00022cfc();
  }
  return local_10;
}



/* 00022f50 FUN_00022f50 */

/* Boundary evidence: original MIPS .pdata 00022f50..00022f8f. Semantic name remains unreviewed. */

void FUN_00022f50(void)

{
  FUN_00022cfc();
  FUN_000201c8(DAT_0016cbe0);
  DAT_0016cbe0 = (HANDLE)0x0;
  DAT_0016cba8 = 0;
  return;
}



/* 00022f90 FUN_00022f90 */

/* Boundary evidence: original MIPS .pdata 00022f90..00022fd3. Semantic name remains unreviewed. */

void FUN_00022f90(void)

{
  if (DAT_0016cba8 == 0) {
    FUN_00024d90();
  }
  DAT_0016cba8 = DAT_0016cba8 + 1;
  return;
}



/* 00022fd4 FUN_00022fd4 */

/* Boundary evidence: original MIPS .pdata 00022fd4..00023017. Semantic name remains unreviewed. */

void FUN_00022fd4(void)

{
  DAT_0016cba8 = DAT_0016cba8 + -1;
  if (DAT_0016cba8 == 0) {
    FUN_00024d98();
  }
  return;
}



/* 00023018 FUN_00023018 */

/* Boundary evidence: original MIPS .pdata 00023018..00023037. Semantic name remains unreviewed. */

undefined4 FUN_00023018(void)

{
  return DAT_0016cba8;
}



/* 00023038 FUN_00023038 */

/* Boundary evidence: original MIPS .pdata 00023038..000230af. Semantic name remains unreviewed. */

uint FUN_00023038(void)

{
  int iVar1;
  uint local_10;
  
  if ((DAT_0002d238 == 0) || (2 < DAT_0002d238)) {
    iVar1 = FUN_00020120();
    local_10 = iVar1 + 4;
  }
  else {
    local_10 = DAT_0002d238;
  }
  return local_10;
}



/* 000230b0 FUN_000230b0 */

/* Boundary evidence: original MIPS .pdata 000230b0..000230e7. Semantic name remains unreviewed. */

undefined4 FUN_000230b0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0002d238;
  DAT_0002d238 = param_1;
  return uVar1;
}



/* 000230e8 FUN_000230e8 */

/* Boundary evidence: original MIPS .pdata 000230e8..000231a7. Semantic name remains unreviewed. */

int FUN_000230e8(undefined4 *param_1)

{
  int *piVar1;
  int local_18;
  
  FUN_00022e0c();
  piVar1 = FUN_00020d4c(0xc,1);
  if (piVar1 == (int *)0x0) {
    local_18 = 7;
  }
  else {
    local_18 = FUN_0002014c(piVar1 + 2);
    if (local_18 == 0) {
      *param_1 = piVar1;
    }
  }
  if ((local_18 != 0) && (piVar1 != (int *)0x0)) {
    FUN_00020e6c(piVar1);
  }
  FUN_00022e34();
  return local_18;
}



/* 000231a8 FUN_000231a8 */

/* Boundary evidence: original MIPS .pdata 000231a8..000231ef. Semantic name remains unreviewed. */

void FUN_000231a8(undefined4 *param_1)

{
  FUN_00022e0c();
  FUN_000201c8((HANDLE)param_1[2]);
  FUN_00020e6c(param_1);
  FUN_00022e34();
  return;
}



/* 000231f0 FUN_000231f0 */

/* Boundary evidence: original MIPS .pdata 000231f0..0002326b. Semantic name remains unreviewed. */

void FUN_000231f0(uint *param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00023038();
  if ((param_1[1] == 0) || (*param_1 != uVar1)) {
    FUN_0002020c((HANDLE)param_1[2]);
  }
  *param_1 = uVar1;
  param_1[1] = param_1[1] + 1;
  return;
}



/* 0002326c FUN_0002326c */

/* Boundary evidence: original MIPS .pdata 0002326c..000232bb. Semantic name remains unreviewed. */

void FUN_0002326c(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (*(int *)(param_1 + 4) == 0) {
    FUN_0002025c(*(HANDLE *)(param_1 + 8));
  }
  return;
}



/* 000232bc FUN_000232bc */

/* Boundary evidence: original MIPS .pdata 000232bc..000232f3. Semantic name remains unreviewed. */

uint FUN_000232bc(void)

{
  uint local_18;
  uint local_14;
  
  FUN_000204dc(&local_18);
  return local_18 ^ local_14;
}



/* 000232f4 FUN_000232f4 */

/* Boundary evidence: original MIPS .pdata 000232f4..00023327. Semantic name remains unreviewed. */

ushort FUN_000232f4(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}



/* 00023328 FUN_00023328 */

/* Boundary evidence: original MIPS .pdata 00023328..0002337b. Semantic name remains unreviewed. */

uint FUN_00023328(uint param_1)

{
  return param_1 >> 0x18 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



/* 0002337c FUN_0002337c */

/* Boundary evidence: original MIPS .pdata 0002337c..000233fb. Semantic name remains unreviewed. */

int * FUN_0002337c(char *param_1)

{
  size_t sVar1;
  undefined4 local_10;
  
  sVar1 = FUN_0001fddc(param_1);
  local_10 = FUN_00020d4c(sVar1 + 1,0);
  if (local_10 == (int *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    FUN_0001fd54(local_10,param_1,sVar1 + 1);
  }
  return local_10;
}



/* 000233fc FUN_000233fc */

/* Boundary evidence: original MIPS .pdata 000233fc..00023513. Semantic name remains unreviewed. */

char * FUN_000233fc(char *param_1,char *param_2)

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



/* 00023514 FUN_00023514 */

/* Boundary evidence: original MIPS .pdata 00023514..0002371b. Semantic name remains unreviewed. */

int FUN_00023514(int param_1,byte param_2,uint param_3,int param_4,uint param_5)

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
  
  local_14 = DAT_0002d280;
  local_40 = 0;
  local_18 = 0;
  if (param_2 < 2) {
    FUN_00026db4(DAT_0002d280);
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
    FUN_00026db4(local_14);
    local_10 = param_1;
  }
  return local_10;
}



/* 0002371c FUN_0002371c */

/* Boundary evidence: original MIPS .pdata 0002371c..000237ef. Semantic name remains unreviewed. */

uint FUN_0002371c(char *param_1,char *param_2,uint param_3)

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
      sVar2 = FUN_0001fddc(local_res4);
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



/* 000237f0 FUN_000237f0 */

/* Boundary evidence: original MIPS .pdata 000237f0..000238ff. Semantic name remains unreviewed. */

int FUN_000237f0(char *param_1,byte param_2,undefined4 *param_3)

{
  int local_18;
  char *local_14;
  uint local_10;
  int local_c;
  
  local_18 = 0;
  local_10 = FUN_00023900(*param_1,(uint)param_2);
  local_14 = param_1;
  while ((*local_14 != '\0' && (local_10 != 0xffffffff))) {
    local_18 = local_18 * (uint)param_2 + local_10;
    local_14 = local_14 + 1;
    local_10 = FUN_00023900(*local_14,(uint)param_2);
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



/* 00023900 FUN_00023900 */

/* Boundary evidence: original MIPS .pdata 00023900..000239f3. Semantic name remains unreviewed. */

uint FUN_00023900(char param_1,uint param_2)

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



/* 000239f4 FUN_000239f4 */

/* Boundary evidence: original MIPS .pdata 000239f4..00023a73. Semantic name remains unreviewed. */

undefined4 FUN_000239f4(char param_1)

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



/* 00023a74 FUN_00023a74 */

/* Boundary evidence: original MIPS .pdata 00023a74..00023e83. Semantic name remains unreviewed. */

char * FUN_00023a74(undefined4 param_1)

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



/* 00023e84 FUN_00023e84 */

/* Boundary evidence: original MIPS .pdata 00023e84..00023fc3. Semantic name remains unreviewed. */

void FUN_00023e84(int param_1,int param_2,uint param_3)

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
    FUN_0001fd54(*(void **)(param_2 + (uint)local_18 * 0xc),(void *)(param_1 + local_14),local_c);
    uVar1 = (uint)local_18;
    local_18 = local_18 + 1;
  }
  return;
}



/* 00023fc4 FUN_00023fc4 */

/* Boundary evidence: original MIPS .pdata 00023fc4..00024103. Semantic name remains unreviewed. */

void FUN_00023fc4(int param_1,int param_2,uint param_3)

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
    FUN_0001fd54((void *)(param_2 + local_10),*(void **)(param_1 + (uint)local_14 * 0xc),local_c);
    uVar1 = (uint)local_14;
    local_14 = local_14 + 1;
  }
  return;
}



/* 00024104 FUN_00024104 */

/* Boundary evidence: original MIPS .pdata 00024104..0002417b. Semantic name remains unreviewed. */

int FUN_00024104(int param_1,int *param_2)

{
  int *local_8;
  
  for (local_8 = param_2; (*local_8 != -1 && (*local_8 != param_1)); local_8 = local_8 + 2) {
  }
  return local_8[1];
}



/* 0002417c FUN_0002417c */

/* Boundary evidence: original MIPS .pdata 0002417c..00024217. Semantic name remains unreviewed. */

int FUN_0002417c(uint param_1)

{
  return (uint)(byte)(&DAT_0002c3f0)[param_1 & 0xff] +
         (uint)(byte)(&DAT_0002c3f0)[param_1 >> 8 & 0xff] +
         (uint)(byte)(&DAT_0002c3f0)[param_1 >> 0x10 & 0xff] +
         (uint)(byte)(&DAT_0002c3f0)[param_1 >> 0x18];
}



/* 00024218 FUN_00024218 */

/* Boundary evidence: original MIPS .pdata 00024218..000242df. Semantic name remains unreviewed. */

int FUN_00024218(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  int local_120;
  char acStack_118 [126];
  undefined1 local_9a;
  undefined1 auStack_98 [128];
  uint local_18;
  
  local_18 = DAT_0002d280;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  local_120 = _vsnprintf_s(acStack_118,0x80,0xffffffff,param_1,(va_list)&local_res4);
  if (local_120 == -1) {
    local_9a = 10;
    local_120 = 0x7f;
  }
  FUN_000242e0(acStack_118,(int)auStack_98);
  NKDbgPrintfW(&DAT_00028130,auStack_98);
  FUN_00026db4(local_18);
  return local_120;
}



/* 000242e0 FUN_000242e0 */

/* Boundary evidence: original MIPS .pdata 000242e0..000243eb. Semantic name remains unreviewed. */

void FUN_000242e0(char *param_1,int param_2)

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



/* 000243ec FUN_000243ec */

/* Boundary evidence: original MIPS .pdata 000243ec..0002444b. Semantic name remains unreviewed. */

undefined4 FUN_000243ec(void)

{
  undefined4 local_10;
  
  DAT_0016cbe8 = HeapCreate(1,0x20000,0x40000);
  if (DAT_0016cbe8 == (HANDLE)0x0) {
    local_10 = 7;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* 0002444c FUN_0002444c */

/* Boundary evidence: original MIPS .pdata 0002444c..000244bf. Semantic name remains unreviewed. */

undefined4 FUN_0002444c(void)

{
  BOOL BVar1;
  undefined4 local_10;
  
  if (DAT_0016cbe8 == (HANDLE)0x0) {
    local_10 = 0;
  }
  else {
    BVar1 = HeapDestroy(DAT_0016cbe8);
    if (BVar1 == 0) {
      local_10 = 0xe;
    }
    else {
      DAT_0016cbe8 = (HANDLE)0x0;
      local_10 = 0;
    }
  }
  return local_10;
}



/* 000244c0 FUN_000244c0 */

/* WARNING: Removing unreachable block (ram,0x00024518) */
/* Boundary evidence: original MIPS .pdata 000244c0..00024553. Semantic name remains unreviewed. */

LPVOID FUN_000244c0(SIZE_T param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = HeapAlloc(DAT_0016cbe8,8,param_1);
  return pvVar1;
}



/* 00024554 FUN_00024554 */

/* Boundary evidence: original MIPS .pdata 00024554..00024587. Semantic name remains unreviewed. */

void FUN_00024554(LPVOID param_1)

{
  HeapFree(DAT_0016cbe8,1,param_1);
  return;
}



/* 00024588 FUN_00024588 */

/* Boundary evidence: original MIPS .pdata 00024588..00024637. Semantic name remains unreviewed. */

undefined4
FUN_00024588(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 param_4,int *param_5)

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



/* 00024638 FUN_00024638 */

/* Boundary evidence: original MIPS .pdata 00024638..0002465f. Semantic name remains unreviewed. */

void FUN_00024638(undefined4 param_1)

{
  FreePhysMem(param_1);
  return;
}



/* 00024680 FUN_00024680 */

/* WARNING: Removing unreachable block (ram,0x00024794) */
/* Boundary evidence: original MIPS .pdata 00024680..000247db. Semantic name remains unreviewed. */

int FUN_00024680(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int local_18;
  int local_c;
  
  bVar1 = false;
  FUN_00024218("USBware version 3.5.14.82\n",param_2,param_3,param_4);
  if (param_1 == (uint *)0x0) {
    local_c = 10;
  }
  else {
    DAT_0016cbec = param_1[2];
    local_c = FUN_00024e4c(param_1);
    if (local_c == 0) {
      local_18 = FUN_00025170();
      if ((local_18 == 0) && (local_18 = FUN_000253ec(), local_18 == 0)) {
        bVar1 = true;
        local_18 = FUN_00024d34();
        if (local_18 == 0) {
          FUN_00022e34();
          return 0;
        }
      }
      if (bVar1) {
        FUN_00025498();
      }
      FUN_00025080();
      FUN_00024fb0();
      local_c = local_18;
    }
  }
  return local_c;
}



/* 000247dc FUN_000247dc */

/* Boundary evidence: original MIPS .pdata 000247dc..00024837. Semantic name remains unreviewed. */

void FUN_000247dc(void)

{
  FUN_00022e0c();
  DAT_0016cbf0 = 1;
  FUN_00024d50();
  FUN_00025498();
  FUN_00025080();
  FUN_00024fb0();
  FUN_00020c90();
  DAT_0016cbf0 = 0;
  return;
}



/* 00024838 FUN_00024838 */

/* Boundary evidence: original MIPS .pdata 00024838..0002486b. Semantic name remains unreviewed. */

undefined4 FUN_00024838(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000260a4(param_1);
  return *puVar1;
}



/* 0002486c FUN_0002486c */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 0002486c..00024aab. Semantic name remains unreviewed. */

int FUN_0002486c(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int local_20;
  
  piVar1 = FUN_00020d4c(0xc,0);
  if (piVar1 == (int *)0x0) {
    return 7;
  }
  *piVar1 = param_1;
  piVar1[1] = param_2;
  piVar1[2] = param_4;
  piVar2 = FUN_000265e4(0,0,piVar1,0);
  if (piVar2 == (int *)0x0) {
    local_20 = 7;
    goto LAB_00024a6c;
  }
  local_20 = 10;
  uVar3 = param_2 >> 0xc;
  if (DAT_0016cbec == 1) {
    if ((uVar3 & 0xf) != 1) goto joined_r0x00024984;
  }
  else if (((DAT_0016cbec == 2) || ((DAT_0016cbec == 3 && ((uVar3 & 0xf) != 1)))) &&
          ((uVar3 & 0xf) != 2)) {
joined_r0x00024984:
    if ((uVar3 & 0xf) != 3) goto LAB_00024a6c;
  }
  local_20 = FUN_00026344(piVar2);
  if (local_20 == 0) {
    *param_3 = piVar2;
    return 0;
  }
LAB_00024a6c:
  if (piVar2 != (int *)0x0) {
    FUN_0002646c(piVar2);
  }
  FUN_00020e6c(piVar1);
  return local_20;
}



/* 00024aac FUN_00024aac */

/* Boundary evidence: original MIPS .pdata 00024aac..00024b07. Semantic name remains unreviewed. */

int FUN_00024aac(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_00022d50();
  iVar1 = FUN_0002486c(param_1,param_2,param_3,0);
  FUN_00022d78();
  return iVar1;
}



/* 00024b08 FUN_00024b08 */

/* Boundary evidence: original MIPS .pdata 00024b08..00024b4f. Semantic name remains unreviewed. */

undefined4 FUN_00024b08(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00022d50();
  uVar1 = FUN_00025cac(param_1);
  FUN_00022d78();
  return uVar1;
}



/* 00024b50 FUN_00024b50 */

/* Boundary evidence: original MIPS .pdata 00024b50..00024b97. Semantic name remains unreviewed. */

undefined4 FUN_00024b50(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00022d50();
  uVar1 = FUN_00025d20(param_1);
  FUN_00022d78();
  return uVar1;
}



/* 00024b98 FUN_00024b98 */

/* Boundary evidence: original MIPS .pdata 00024b98..00024bef. Semantic name remains unreviewed. */

undefined4 FUN_00024b98(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000260a4((int)param_1);
  FUN_0002646c(param_1);
  FUN_00020e6c(puVar1);
  return 0;
}



/* 00024bf0 FUN_00024bf0 */

/* Boundary evidence: original MIPS .pdata 00024bf0..00024c37. Semantic name remains unreviewed. */

undefined4 FUN_00024bf0(int *param_1)

{
  undefined4 uVar1;
  
  FUN_00022d50();
  uVar1 = FUN_00024b98(param_1);
  FUN_00022d78();
  return uVar1;
}



/* 00024c38 FUN_00024c38 */

/* Boundary evidence: original MIPS .pdata 00024c38..00024c57. Semantic name remains unreviewed. */

undefined ** FUN_00024c38(void)

{
  return &PTR_DAT_0002d24c;
}



/* 00024c7c FUN_00024c7c */

/* Boundary evidence: original MIPS .pdata 00024c7c..00024cc3. Semantic name remains unreviewed. */

undefined4 FUN_00024c7c(void)

{
  return 0;
}



/* 00024cc4 FUN_00024cc4 */

/* Boundary evidence: original MIPS .pdata 00024cc4..00024cef. Semantic name remains unreviewed. */

undefined4 FUN_00024cc4(void)

{
  return 0xb;
}



/* 00024cf0 FUN_00024cf0 */

/* Boundary evidence: original MIPS .pdata 00024cf0..00024d0f. Semantic name remains unreviewed. */

undefined4 FUN_00024cf0(void)

{
  return 0xb;
}



/* 00024d10 FUN_00024d10 */

/* Boundary evidence: original MIPS .pdata 00024d10..00024d33. Semantic name remains unreviewed. */

undefined4 FUN_00024d10(void)

{
  return 0;
}



/* 00024d34 FUN_00024d34 */

/* Boundary evidence: original MIPS .pdata 00024d34..00024d4f. Semantic name remains unreviewed. */

undefined4 FUN_00024d34(void)

{
  return 0;
}



/* 00024d50 FUN_00024d50 */

void FUN_00024d50(void)

{
  return;
}



/* 00024d58 FUN_00024d58 */

/* Boundary evidence: original MIPS .pdata 00024d58..00024d7f. Semantic name remains unreviewed. */

undefined4 FUN_00024d58(void)

{
  return 0;
}



/* 00024d90 FUN_00024d90 */

void FUN_00024d90(void)

{
  return;
}



/* 00024d98 FUN_00024d98 */

void FUN_00024d98(void)

{
  return;
}



/* 00024da0 FUN_00024da0 */

/* Boundary evidence: original MIPS .pdata 00024da0..00024dc3. Semantic name remains unreviewed. */

undefined1 FUN_00024da0(void)

{
  return 0xff;
}



/* 00024dc4 FUN_00024dc4 */

/* Boundary evidence: original MIPS .pdata 00024dc4..00024de7. Semantic name remains unreviewed. */

undefined2 FUN_00024dc4(void)

{
  return 0xffff;
}



/* 00024de8 FUN_00024de8 */

/* Boundary evidence: original MIPS .pdata 00024de8..00024e0f. Semantic name remains unreviewed. */

undefined4 FUN_00024de8(void)

{
  return 0xffffffff;
}



/* 00024e4c FUN_00024e4c */

/* Boundary evidence: original MIPS .pdata 00024e4c..00024faf. Semantic name remains unreviewed. */

int FUN_00024e4c(uint *param_1)

{
  int local_10;
  
  local_10 = FUN_00021ea4(param_1);
  if (local_10 == 0) {
    DAT_0019d934 = DAT_0019d934 | 1;
    local_10 = FUN_00022da0();
    if (local_10 == 0) {
      FUN_00022e0c();
      DAT_0019d934 = DAT_0019d934 | 2;
      local_10 = FUN_0001fca0();
      if (local_10 == 0) {
        DAT_0019d934 = DAT_0019d934 | 4;
        local_10 = FUN_00022ebc();
        if (local_10 == 0) {
          DAT_0019d934 = DAT_0019d934 | 8;
          local_10 = FUN_00025390();
          if (local_10 == 0) {
            DAT_0019d934 = DAT_0019d934 | 0x10;
            return 0;
          }
        }
      }
    }
  }
  FUN_00024fb0();
  return local_10;
}



/* 00024fb0 FUN_00024fb0 */

/* Boundary evidence: original MIPS .pdata 00024fb0..0002507f. Semantic name remains unreviewed. */

void FUN_00024fb0(void)

{
  if ((DAT_0019d934 & 0x10) != 0) {
    FUN_000253e4();
  }
  if ((DAT_0019d934 & 8) != 0) {
    FUN_00022f50();
  }
  if ((DAT_0019d934 & 1) != 0) {
    FUN_00021ddc();
  }
  if ((DAT_0019d934 & 4) != 0) {
    FUN_0001fcf0();
  }
  if ((DAT_0019d934 & 2) != 0) {
    FUN_00022e34();
    FUN_00022dd4();
  }
  if ((DAT_0019d934 & 1) != 0) {
    FUN_00021fb4();
  }
  DAT_0019d934 = 0;
  return;
}



/* 00025080 FUN_00025080 */

/* Boundary evidence: original MIPS .pdata 00025080..0002516f. Semantic name remains unreviewed. */

void FUN_00025080(void)

{
  int iVar1;
  int local_10;
  
  for (local_10 = 0; (&PTR_FUN_0002d260)[local_10 * 3] != (undefined *)0x0; local_10 = local_10 + 1)
  {
  }
  while (iVar1 = local_10 + -1, local_10 != 0) {
    if (*(int *)(&DAT_0002d268 + iVar1 * 0xc) != 0) {
      (*(code *)(&PTR_FUN_0002d264)[iVar1 * 3])();
    }
    *(undefined4 *)(&DAT_0002d268 + iVar1 * 0xc) = 0;
    local_10 = iVar1;
  }
  return;
}



/* 00025170 FUN_00025170 */

/* Boundary evidence: original MIPS .pdata 00025170..00025257. Semantic name remains unreviewed. */

int FUN_00025170(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((&PTR_FUN_0002d260)[local_14 * 3] == (undefined *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)(&PTR_FUN_0002d260)[local_14 * 3])();
    if (iVar1 != 0) break;
    *(undefined4 *)(&DAT_0002d268 + local_14 * 0xc) = 1;
    local_14 = local_14 + 1;
  }
  FUN_00025080();
  return iVar1;
}



/* 00025258 FUN_00025258 */

void FUN_00025258(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(int **)(param_1 + 0xc) = DAT_0019d944;
  *DAT_0019d944 = param_1;
  DAT_0019d944 = (int *)(param_1 + 8);
  return;
}



/* 000252a8 FUN_000252a8 */

/* Boundary evidence: original MIPS .pdata 000252a8..0002538f. Semantic name remains unreviewed. */

undefined4 FUN_000252a8(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_4;
  
  bVar1 = false;
  local_c = DAT_0019d940;
  iVar2 = local_c;
  while (local_c = iVar2, local_c != 0) {
    iVar2 = *(int *)(local_c + 8);
    if (local_c == param_1) {
      if (*(int *)(local_c + 8) == 0) {
        DAT_0019d944 = *(undefined4 *)(local_c + 0xc);
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



/* 00025390 FUN_00025390 */

/* Boundary evidence: original MIPS .pdata 00025390..000253e3. Semantic name remains unreviewed. */

undefined4 FUN_00025390(void)

{
  DAT_0019d938 = 0;
  DAT_0019d93c = &DAT_0019d938;
  DAT_0019d940 = 0;
  DAT_0019d944 = &DAT_0019d940;
  return 0;
}



/* 000253e4 FUN_000253e4 */

void FUN_000253e4(void)

{
  return;
}



/* 000253ec FUN_000253ec */

/* Boundary evidence: original MIPS .pdata 000253ec..00025497. Semantic name remains unreviewed. */

int FUN_000253ec(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if (*(int *)(&DAT_0019d948 + local_14 * 4) == 0) {
      return 0;
    }
    iVar1 = (**(code **)(&DAT_0019d948 + local_14 * 4))();
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  FUN_00025498();
  return iVar1;
}



/* 00025498 FUN_00025498 */

/* Boundary evidence: original MIPS .pdata 00025498..0002556f. Semantic name remains unreviewed. */

void FUN_00025498(void)

{
  int *piVar1;
  
  while (piVar1 = DAT_0019d938, DAT_0019d938 != (int *)0x0) {
    if (*(int *)(*DAT_0019d938 + 0x20) != 0) {
      (**(code **)(*DAT_0019d938 + 0x20))();
    }
    if (DAT_0019d938[4] == 0) {
      DAT_0019d93c = DAT_0019d938[5];
    }
    else {
      *(int *)(DAT_0019d938[4] + 0x14) = DAT_0019d938[5];
    }
    *(int *)DAT_0019d938[5] = DAT_0019d938[4];
    FUN_00020e6c(piVar1);
  }
  return;
}



/* 00025570 FUN_00025570 */

/* Boundary evidence: original MIPS .pdata 00025570..00025627. Semantic name remains unreviewed. */

void FUN_00025570(void)

{
  int iVar1;
  int *piVar2;
  int *local_c;
  
  local_c = DAT_0019d940;
  do {
    if (local_c == (int *)0x0) {
      return;
    }
    iVar1 = FUN_00026008((int)local_c);
    if (iVar1 == 0) {
LAB_00025604:
      FUN_000258dc(local_c);
    }
    else {
      piVar2 = (int *)FUN_00026278((int)local_c);
      iVar1 = FUN_00025c20(piVar2,2,local_c);
      if ((iVar1 == 0) || (iVar1 == 0x16)) goto LAB_00025604;
    }
    local_c = (int *)local_c[2];
  } while( true );
}



/* 00025628 FUN_00025628 */

/* Boundary evidence: original MIPS .pdata 00025628..000256e7. Semantic name remains unreviewed. */

void FUN_00025628(undefined4 *param_1)

{
  if (param_1[4] == 0) {
    DAT_0019d93c = param_1[5];
  }
  else {
    *(undefined4 *)(param_1[4] + 0x14) = param_1[5];
  }
  *(undefined4 *)param_1[5] = param_1[4];
  if (*(char *)(param_1 + 3) != '\0') {
    while ((int *)param_1[6] != (int *)0x0) {
      FUN_00026430((int *)param_1[6]);
    }
  }
  FUN_00020e6c(param_1);
  return;
}



/* 000256e8 FUN_000256e8 */

/* Boundary evidence: original MIPS .pdata 000256e8..0002582b. Semantic name remains unreviewed. */

undefined4 FUN_000256e8(int param_1,int param_2,int param_3,undefined2 param_4,undefined4 *param_5)

{
  int *piVar1;
  undefined4 local_c;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  piVar1 = FUN_00020d4c(0x20,0);
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
    piVar1[5] = (int)DAT_0019d93c;
    *DAT_0019d93c = (int)piVar1;
    DAT_0019d93c = piVar1 + 4;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = piVar1;
    }
    if (DAT_0019d940 != 0) {
      FUN_00025570();
    }
    local_c = 0;
  }
  return local_c;
}



/* 0002582c FUN_0002582c */

/* Boundary evidence: original MIPS .pdata 0002582c..000258db. Semantic name remains unreviewed. */

void FUN_0002582c(int *param_1)

{
  if (*param_1 != 0) {
    if (*(int *)(*(int *)*param_1 + 8) != 0) {
      (**(code **)(*(int *)*param_1 + 8))(param_1);
    }
    if (*param_1 != 0) {
      FUN_00025ec8(param_1);
    }
    if (param_1[5] != 0) {
      FUN_00020e6c((undefined4 *)param_1[5]);
      param_1[5] = 0;
    }
  }
  return;
}



/* 000258dc FUN_000258dc */

/* Boundary evidence: original MIPS .pdata 000258dc..00025baf. Semantic name remains unreviewed. */

int FUN_000258dc(int *param_1)

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
  iVar2 = FUN_00026008((int)param_1);
  for (local_2c = DAT_0019d938; local_2c != (int *)0x0; local_2c = (int *)local_2c[4]) {
    if (local_2c[1] == iVar2) {
      if (*(short *)((int)local_2c + 0xe) != 0) {
        piVar3 = FUN_00020d4c((uint)*(ushort *)((int)local_2c + 0xe),1);
        param_1[5] = (int)piVar3;
        if (param_1[5] == 0) goto LAB_00025914;
      }
      iVar4 = (**(code **)*local_2c)(param_1);
      if (*(short *)((int)local_2c + 0xe) != 0) {
        FUN_00020e6c((undefined4 *)param_1[5]);
      }
      param_1[5] = 0;
      if (local_20 < iVar4) {
        local_28 = local_2c;
        local_20 = iVar4;
      }
    }
LAB_00025914:
  }
  if (local_28 == (int *)0x0) {
    local_30 = 4;
  }
  else {
    if (*(short *)((int)local_28 + 0xe) != 0) {
      piVar3 = FUN_00020d4c((uint)*(ushort *)((int)local_28 + 0xe),1);
      param_1[5] = (int)piVar3;
      if (param_1[5] == 0) {
        local_30 = 7;
        goto LAB_00025b34;
      }
    }
    bVar1 = *(byte *)((int)local_28 + 0xd);
    *(char *)((int)local_28 + 0xd) = *(char *)((int)local_28 + 0xd) + '\x01';
    FUN_00026194((int)param_1,(char *)local_28[2],(uint)bVar1);
    local_30 = (**(code **)(*local_28 + 4))(param_1);
    if (local_30 == 0) {
      if ((*param_1 != 0) || (local_30 = FUN_00025d94(param_1,(int)local_28,0,0), local_30 == 0)) {
        return 0;
      }
      FUN_00026430(param_1);
    }
  }
LAB_00025b34:
  if (param_1[5] != 0) {
    FUN_00020e6c((undefined4 *)param_1[5]);
    param_1[5] = 0;
  }
  iVar2 = DAT_0019d954;
  DAT_0019d954 = DAT_0019d954 + 1;
  FUN_00026194((int)param_1,"unknown",iVar2);
  return local_30;
}



/* 00025bb0 FUN_00025bb0 */

/* Boundary evidence: original MIPS .pdata 00025bb0..00025c1f. Semantic name remains unreviewed. */

int FUN_00025bb0(int *param_1)

{
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    local_c = FUN_000258dc(param_1);
    if (local_c == 0) {
      local_c = 0;
    }
  }
  return local_c;
}



/* 00025c20 FUN_00025c20 */

/* Boundary evidence: original MIPS .pdata 00025c20..00025cab. Semantic name remains unreviewed. */

undefined4 FUN_00025c20(int *param_1,undefined4 param_2,undefined4 param_3)

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



/* 00025cac FUN_00025cac */

/* Boundary evidence: original MIPS .pdata 00025cac..00025d1f. Semantic name remains unreviewed. */

undefined4 FUN_00025cac(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0xc) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0xc))(param_1);
  }
  return local_10;
}



/* 00025d20 FUN_00025d20 */

/* Boundary evidence: original MIPS .pdata 00025d20..00025d93. Semantic name remains unreviewed. */

undefined4 FUN_00025d20(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0x10) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0x10))(param_1);
  }
  return local_10;
}



/* 00025d94 FUN_00025d94 */

/* Boundary evidence: original MIPS .pdata 00025d94..00025ec7. Semantic name remains unreviewed. */

int FUN_00025d94(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int local_10;
  
  piVar1 = (int *)FUN_00026708((int)param_1);
  if (((piVar1 == (int *)0x0) || (*(int *)(*piVar1 + 0x18) == 0)) ||
     (local_10 = (**(code **)(*piVar1 + 0x18))(param_1,param_3,param_4), local_10 == 0)) {
    *param_1 = param_2;
    *(char *)(*param_1 + 0xc) = *(char *)(*param_1 + 0xc) + '\x01';
    FUN_000252a8((int)param_1);
    param_1[2] = 0;
    param_1[3] = *(int *)(*param_1 + 0x1c);
    **(undefined4 **)(*param_1 + 0x1c) = param_1;
    *(int **)(*param_1 + 0x1c) = param_1 + 2;
    local_10 = 0;
  }
  return local_10;
}



/* 00025ec8 FUN_00025ec8 */

/* Boundary evidence: original MIPS .pdata 00025ec8..00025fbb. Semantic name remains unreviewed. */

void FUN_00025ec8(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_00026708((int)param_1);
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
  FUN_00025258((int)param_1);
  return;
}



/* 00025fbc FUN_00025fbc */

/* Boundary evidence: original MIPS .pdata 00025fbc..00025fdf. Semantic name remains unreviewed. */

undefined4 FUN_00025fbc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}



/* 00025fe0 FUN_00025fe0 */

/* Boundary evidence: original MIPS .pdata 00025fe0..00026007. Semantic name remains unreviewed. */

undefined4 FUN_00025fe0(undefined4 param_1,int param_2)

{
  return *(undefined4 *)(param_2 + 0x3c);
}



/* 00026008 FUN_00026008 */

/* Boundary evidence: original MIPS .pdata 00026008..00026047. Semantic name remains unreviewed. */

undefined4 FUN_00026008(int param_1)

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



/* 00026064 FUN_00026064 */

/* Boundary evidence: original MIPS .pdata 00026064..000260a3. Semantic name remains unreviewed. */

undefined4 FUN_00026064(int param_1)

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



/* 000260a4 FUN_000260a4 */

/* Boundary evidence: original MIPS .pdata 000260a4..000260e3. Semantic name remains unreviewed. */

undefined4 FUN_000260a4(int param_1)

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



/* 000260e4 FUN_000260e4 */

/* Boundary evidence: original MIPS .pdata 000260e4..00026107. Semantic name remains unreviewed. */

undefined4 FUN_000260e4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* 00026124 FUN_00026124 */

/* Boundary evidence: original MIPS .pdata 00026124..00026193. Semantic name remains unreviewed. */

undefined * FUN_00026124(int param_1)

{
  undefined *local_8;
  undefined *local_4;
  
  if (param_1 == 0) {
    local_8 = &DAT_0002c83c;
  }
  else {
    if (*(int *)(param_1 + 0x2c) == 0) {
      local_4 = &DAT_0002c83c;
    }
    else {
      local_4 = *(undefined **)(param_1 + 0x2c);
    }
    local_8 = local_4;
  }
  return local_8;
}



/* 00026194 FUN_00026194 */

/* Boundary evidence: original MIPS .pdata 00026194..00026277. Semantic name remains unreviewed. */

void FUN_00026194(int param_1,char *param_2,undefined4 param_3)

{
  size_t sVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_00020e6c(*(undefined4 **)(param_1 + 0x2c));
  }
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = param_3;
  }
  else {
    sVar1 = FUN_0001fddc(param_2);
    piVar2 = FUN_00020d4c(sVar1 + 10,1);
    *(int **)(param_1 + 0x2c) = piVar2;
    if (*(int *)(param_1 + 0x2c) != 0) {
      *(undefined4 *)(param_1 + 0x28) = param_3;
      FUN_0001fe90(*(char **)(param_1 + 0x2c),sVar1 + 10,"%s%ld",param_2);
    }
  }
  return;
}



/* 00026278 FUN_00026278 */

/* Boundary evidence: original MIPS .pdata 00026278..0002629b. Semantic name remains unreviewed. */

undefined4 FUN_00026278(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* 0002629c FUN_0002629c */

/* Boundary evidence: original MIPS .pdata 0002629c..000262db. Semantic name remains unreviewed. */

undefined4 FUN_0002629c(int param_1)

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



/* 000262dc FUN_000262dc */

/* Boundary evidence: original MIPS .pdata 000262dc..000262ff. Semantic name remains unreviewed. */

undefined4 FUN_000262dc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* 00026300 FUN_00026300 */

/* Boundary evidence: original MIPS .pdata 00026300..00026343. Semantic name remains unreviewed. */

bool FUN_00026300(int *param_1)

{
  return *param_1 != 0;
}



/* 00026344 FUN_00026344 */

/* Boundary evidence: original MIPS .pdata 00026344..0002637b. Semantic name remains unreviewed. */

int FUN_00026344(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00025bb0(param_1);
  return iVar1;
}



/* 0002637c FUN_0002637c */

/* Boundary evidence: original MIPS .pdata 0002637c..000263e3. Semantic name remains unreviewed. */

void FUN_0002637c(int param_1,char *param_2)

{
  int *piVar1;
  
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_00020e6c(*(undefined4 **)(param_1 + 0x30));
    }
    piVar1 = FUN_0002337c(param_2);
    *(int **)(param_1 + 0x30) = piVar1;
  }
  return;
}



/* 000263e4 FUN_000263e4 */

/* Boundary evidence: original MIPS .pdata 000263e4..0002642f. Semantic name remains unreviewed. */

undefined * FUN_000263e4(int param_1)

{
  undefined *local_4;
  
  if (param_1 == 0) {
    local_4 = &DAT_0002c83c;
  }
  else {
    local_4 = *(undefined **)(param_1 + 0x30);
  }
  return local_4;
}



/* 00026430 FUN_00026430 */

/* Boundary evidence: original MIPS .pdata 00026430..0002646b. Semantic name remains unreviewed. */

undefined4 FUN_00026430(int *param_1)

{
  FUN_0002582c(param_1);
  FUN_00025570();
  return 0;
}



/* 0002646c FUN_0002646c */

/* Boundary evidence: original MIPS .pdata 0002646c..000265e3. Semantic name remains unreviewed. */

void FUN_0002646c(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  int *local_14;
  
  if (param_1 != (int *)0x0) {
    bVar1 = FUN_00026300(param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_0002582c(param_1);
    }
    iVar2 = FUN_00026278((int)param_1);
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
    FUN_000252a8((int)param_1);
    if (param_1[0xb] != 0) {
      FUN_00020e6c((undefined4 *)param_1[0xb]);
    }
    if (param_1[0xc] != 0) {
      FUN_00020e6c((undefined4 *)param_1[0xc]);
    }
    FUN_00020e6c(param_1);
  }
  return;
}



/* 000265e4 FUN_000265e4 */

/* Boundary evidence: original MIPS .pdata 000265e4..000266eb. Semantic name remains unreviewed. */

int * FUN_000265e4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *local_c;
  
  local_c = FUN_00020d4c(0x44,1);
  if (local_c == (int *)0x0) {
    local_c = (int *)0x0;
  }
  else {
    local_c[4] = param_2;
    local_c[6] = param_1;
    local_c[1] = param_4;
    FUN_000266ec((int)local_c,param_3);
    local_c[0xd] = 0;
    local_c[0xe] = (int)(local_c + 0xd);
    if (param_2 != 0) {
      local_c[0xf] = 0;
      local_c[0x10] = *(int *)(param_2 + 0x38);
      **(undefined4 **)(param_2 + 0x38) = local_c;
      *(int **)(param_2 + 0x38) = local_c + 0xf;
    }
    FUN_00025258((int)local_c);
  }
  return local_c;
}



/* 000266ec FUN_000266ec */

void FUN_000266ec(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}



/* 00026708 FUN_00026708 */

/* Boundary evidence: original MIPS .pdata 00026708..00026747. Semantic name remains unreviewed. */

undefined4 FUN_00026708(int param_1)

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



/* 00026748 FUN_00026748 */

/* Boundary evidence: original MIPS .pdata 00026748..000267cf. Semantic name remains unreviewed. */

void FUN_00026748(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_000268ac();
  uVar2 = FUN_000267d0();
  uVar2 = (uVar2 / 1000000 + 1) * param_1 + uVar1;
  while (uVar2 < uVar1) {
    uVar1 = FUN_000268ac();
  }
  do {
    uVar1 = FUN_000268ac();
  } while (uVar1 < uVar2);
  return;
}



/* 000267d0 FUN_000267d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_000267d0(void)

{
  return (_DAT_b0900060 & 0x7f) * 12000000;
}



/* 000268ac FUN_000268ac */

undefined4 FUN_000268ac(void)

{
  return Count;
}



/* 00026cb0 FUN_00026cb0 */

/* Boundary evidence: original MIPS .pdata 00026cb0..00026d23. Semantic name remains unreviewed. */

void FUN_00026cb0(void)

{
  uint uVar1;
  
  if ((DAT_0002d280 == 0) || (DAT_0002d280 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0002d280 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0002d280 == 0) {
      DAT_0002d280 = 0xb064;
    }
  }
  DAT_0002d284 = ~DAT_0002d280;
  return;
}



/* 00026d24 FUN_00026d24 */

/* Boundary evidence: original MIPS .pdata 00026d24..00026d77. Semantic name remains unreviewed. */

void FUN_00026d24(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00026db4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00026d78 FUN_00026d78 */

/* Boundary evidence: original MIPS .pdata 00026d78..00026da3. Semantic name remains unreviewed. */

undefined4 FUN_00026d78(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00026d24(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00026db4 FUN_00026db4 */

/* Boundary evidence: original MIPS .pdata 00026db4..00026dfb. Semantic name remains unreviewed. */

void FUN_00026db4(uint param_1)

{
  if ((param_1 == DAT_0002d280) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00026dfc FUN_00026dfc */

/* Boundary evidence: original MIPS .pdata 00026dfc..00026e8f. Semantic name remains unreviewed. */

void FUN_00026dfc(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  UINT UVar1;
  
  FUN_0002718c();
  UVar1 = FUN_000178a0(param_1,param_2,param_3,param_4);
  FUN_000270cc(UVar1);
  FUN_000270ec(UVar1);
  return;
}



/* 00026e90 FUN_00026e90 */

/* Boundary evidence: original MIPS .pdata 00026e90..00026ecf. Semantic name remains unreviewed. */

void FUN_00026e90(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00026ed0 entry */

/* Boundary evidence: original MIPS .pdata 00026ed0..00026f2b. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3,int param_4)

{
  FUN_00026cb0();
  FUN_00026dfc(param_1,param_2,param_3,param_4);
  return;
}



/* 00026fac FUN_00026fac */

/* Boundary evidence: original MIPS .pdata 00026fac..000270cb. Semantic name remains unreviewed. */

void FUN_00026fac(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0019d958 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0019d960;
    if (DAT_0019d960 != (undefined4 *)0x0) {
      while (DAT_0019d95c = DAT_0019d95c + -1, _Memory <= DAT_0019d95c) {
        if ((code *)*DAT_0019d95c != (code *)0x0) {
          (*(code *)*DAT_0019d95c)();
          _Memory = DAT_0019d960;
        }
      }
      free(_Memory);
      DAT_0019d95c = (undefined4 *)0x0;
      DAT_0019d960 = (undefined4 *)0x0;
    }
    FUN_00027138((undefined4 *)&DAT_00028014,(undefined4 *)&DAT_00028018);
  }
  FUN_00027138((undefined4 *)&DAT_0002801c,(undefined4 *)&DAT_00028020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0019d964,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 000270cc FUN_000270cc */

/* Boundary evidence: original MIPS .pdata 000270cc..000270eb. Semantic name remains unreviewed. */

void FUN_000270cc(UINT param_1)

{
  FUN_00026fac(param_1,0,0);
  return;
}



/* 000270ec FUN_000270ec */

/* Boundary evidence: original MIPS .pdata 000270ec..00027137. Semantic name remains unreviewed. */

void FUN_000270ec(UINT param_1)

{
  DAT_0019d958 = 0;
  FUN_00027138((undefined4 *)&DAT_0002801c,(undefined4 *)&DAT_00028020);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00027138 FUN_00027138 */

/* Boundary evidence: original MIPS .pdata 00027138..0002718b. Semantic name remains unreviewed. */

void FUN_00027138(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 0002718c FUN_0002718c */

/* Boundary evidence: original MIPS .pdata 0002718c..000271c7. Semantic name remains unreviewed. */

void FUN_0002718c(void)

{
  FUN_00027138((undefined4 *)&DAT_0002800c,(undefined4 *)&DAT_00028010);
  FUN_00027138((undefined4 *)&DAT_00028000,(undefined4 *)&DAT_00028008);
  return;
}



/* 00027208 FUN_00027208 */

/* Boundary evidence: original MIPS .pdata 00027208..0002726b. Semantic name remains unreviewed. */

void FUN_00027208(void)

{
  memset(&DAT_0016bdfc,0,0x20);
  memset(&DAT_0016be1c,0,0x400);
  memset(&DAT_0016c21c,0,0x400);
  memset(&DAT_0016c61c,0,0x400);
  return;
}


