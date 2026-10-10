/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

undefined4 FUN_10001000(void)

{
  return 1;
}



/* 10001008 DrawRVD */

/* Boundary evidence: original MIPS .pdata 10001008..10001023. Semantic name remains unreviewed.
   void __cdecl DrawRVD(struct HWND__ *) */

void DrawRVD(HWND__ *param_1)

{
                    /* 0x1008  1  ?DrawRVD@@YAXPAUHWND__@@@Z */
  DrawRVC(param_1);
  return;
}



/* 10001024 GetRVDVersion */

/* Boundary evidence: original MIPS .pdata 10001024..1000103f. Semantic name remains unreviewed.
   void __cdecl GetRVDVersion(char *,unsigned int) */

void GetRVDVersion(char *param_1,uint param_2)

{
                    /* 0x1024  2  ?GetRVDVersion@@YAXPADI@Z */
  GetRVCVersion(param_1,param_2);
  return;
}



/* 10001040 SetRVDWnd */

/* Boundary evidence: original MIPS .pdata 10001040..1000106f. Semantic name remains unreviewed.
   void __cdecl SetRVDWnd(struct HINSTANCE__ *,struct HWND__ *) */

void SetRVDWnd(HINSTANCE__ *param_1,HWND__ *param_2)

{
                    /* 0x1040  3  ?SetRVDWnd@@YAXPAUHINSTANCE__@@PAUHWND__@@@Z */
  SetRVCWnd(param_1,param_2);
  DAT_1000304c = param_2;
  return;
}



/* 10001070 StartRVD */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10001070..100010cb. Semantic name remains unreviewed.
   void __cdecl StartRVD(void) */

void StartRVD(void)

{
                    /* 0x1070  4  ?StartRVD@@YAXXZ */
  SetWindowPos(DAT_1000304c,(HWND)0xffffffff,0,0,800,0x1e0,0);
  ShowWindow(DAT_1000304c,5);
  StartRVC();
  return;
}



/* 100010cc StopRVD */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 100010cc..100010f7. Semantic name remains unreviewed.
   void __cdecl StopRVD(void) */

void StopRVD(void)

{
                    /* 0x10cc  5  ?StopRVD@@YAXXZ */
  StopRVC();
  ShowWindow(DAT_1000304c,0);
  return;
}



/* 10001168 FUN_10001168 */

/* Boundary evidence: original MIPS .pdata 10001168..100012a3. Semantic name remains unreviewed. */

int FUN_10001168(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_10003060 != (code *)0x0) {
      iVar2 = (*DAT_10003060)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_10001218;
    FUN_100014d0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10001000();
  }
LAB_10001218:
  if (((param_2 == 0) && (FUN_10001458(), iVar1 != 0)) && (DAT_10003060 != (code *)0x0)) {
    iVar1 = (*DAT_10003060)(param_1,0,param_3);
  }
  return iVar1;
}



/* 100012a4 FUN_100012a4 */

/* Boundary evidence: original MIPS .pdata 100012a4..100012cf. Semantic name remains unreviewed. */

void FUN_100012a4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 100012d0 entry */

/* Boundary evidence: original MIPS .pdata 100012d0..10001327. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_1000151c();
  }
  FUN_10001168(param_1,param_2,param_3);
  return;
}



/* 10001338 FUN_10001338 */

/* Boundary evidence: original MIPS .pdata 10001338..10001457. Semantic name remains unreviewed. */

void FUN_10001338(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_10003050 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_10003058;
    if (DAT_10003058 != (undefined4 *)0x0) {
      while (DAT_10003054 = DAT_10003054 + -1, _Memory <= DAT_10003054) {
        if ((code *)*DAT_10003054 != (code *)0x0) {
          (*(code *)*DAT_10003054)();
          _Memory = DAT_10003058;
        }
      }
      free(_Memory);
      DAT_10003054 = (undefined4 *)0x0;
      DAT_10003058 = (undefined4 *)0x0;
    }
    FUN_1000147c((undefined4 *)&DAT_10002010,(undefined4 *)&DAT_10002014);
  }
  FUN_1000147c((undefined4 *)&DAT_10002018,(undefined4 *)&DAT_1000201c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_1000305c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 10001458 FUN_10001458 */

/* Boundary evidence: original MIPS .pdata 10001458..1000147b. Semantic name remains unreviewed. */

void FUN_10001458(void)

{
  FUN_10001338(0,0,1);
  return;
}



/* 1000147c FUN_1000147c */

/* Boundary evidence: original MIPS .pdata 1000147c..100014cf. Semantic name remains unreviewed. */

void FUN_1000147c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 100014d0 FUN_100014d0 */

/* Boundary evidence: original MIPS .pdata 100014d0..1000150b. Semantic name remains unreviewed. */

void FUN_100014d0(void)

{
  FUN_1000147c((undefined4 *)&DAT_10002008,(undefined4 *)&DAT_1000200c);
  FUN_1000147c((undefined4 *)&DAT_10002000,(undefined4 *)&DAT_10002004);
  return;
}



/* 1000151c FUN_1000151c */

/* Boundary evidence: original MIPS .pdata 1000151c..1000158f. Semantic name remains unreviewed. */

void FUN_1000151c(void)

{
  uint uVar1;
  
  if ((DAT_10003040 == 0) || (DAT_10003040 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_10003040 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_10003040 == 0) {
      DAT_10003040 = 0xb064;
    }
  }
  DAT_10003044 = ~DAT_10003040;
  return;
}


