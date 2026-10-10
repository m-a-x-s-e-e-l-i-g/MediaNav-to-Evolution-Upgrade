/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 405169e4 FUN_405169e4 */

/* Boundary evidence: original MIPS .pdata 405169e4..40516a3b. Semantic name remains unreviewed. */

void FUN_405169e4(undefined4 param_1,LPCWSTR param_2)

{
  if (DAT_4054435c == 0) {
    StrCpyNW((LPWSTR)&DAT_40544364,param_2,0x104);
    DAT_4054456c = 2;
    DAT_40544360 = param_1;
  }
  return;
}



/* 40516a3c FUN_40516a3c */

/* Boundary evidence: original MIPS .pdata 40516a3c..40516aab. Semantic name remains unreviewed. */

void FUN_40516a3c(UINT param_1,LPWSTR param_2,int param_3)

{
  if (DAT_4054435c == (HINSTANCE)0x0) {
    DAT_4054435c = LoadLibraryW((LPCWSTR)&DAT_40544364);
  }
  LoadStringW(DAT_4054435c,param_1,param_2,param_3);
  return;
}



/* 40516aac FUN_40516aac */

/* Boundary evidence: original MIPS .pdata 40516aac..40516adb. Semantic name remains unreviewed. */

void FUN_40516aac(void)

{
  MLBuildResURLW();
  return;
}



/* 40516adc DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
                    /* 0x6adc  1  DllCanUnloadNow */
  return (uint)(DAT_40544570 != 0);
}



/* 40516af8 FUN_40516af8 */

/* Boundary evidence: original MIPS .pdata 40516af8..40516bb7. Semantic name remains unreviewed. */

undefined4 FUN_40516af8(void)

{
  HRESULT HVar1;
  HMODULE hLibModule;
  
  if (DAT_4054432c == -1) {
    HVar1 = CoInitializeEx((LPVOID)0x0,2);
    if ((HVar1 != 1) && (HVar1 != 0)) {
      DAT_4054432c = 0;
      return 0;
    }
    CoUninitialize();
    hLibModule = LoadLibraryW(L"rpcrt4.dll");
    if (hLibModule == (HMODULE)0x0) {
      DAT_4054432c = 0;
    }
    else {
      DAT_4054432c = 1;
      FreeLibrary(hLibModule);
    }
  }
  if (DAT_4054432c != 1) {
    return 0;
  }
  return 1;
}



/* 40516bb8 FUN_40516bb8 */

/* Boundary evidence: original MIPS .pdata 40516bb8..40516d53. Semantic name remains unreviewed. */

undefined4 FUN_40516bb8(HMODULE param_1,int param_2,int param_3)

{
  int *piVar1;
  LSTATUS LVar2;
  int local_20 [4];
  
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_40544588 = param_1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40544574);
    FUN_405169e4(DAT_40544588,L"shdoclc.dll");
    DAT_40544590 = GetACP();
    local_20[1] = 4;
    local_20[0] = 0;
    local_20[2] = 0;
    LVar2 = SHGetValueW((HKEY)0x80000001,L"SOFTWARE\\Microsoft\\Internet Explorer\\Main",
                        L"NoNewWindows",(DWORD *)(local_20 + 2),local_20,(DWORD *)(local_20 + 1));
    if ((LVar2 == 0) && (local_20[0] != 0)) {
      DAT_4054458c = 1;
    }
  }
  else if (param_2 == 0) {
    if ((DAT_4054435c != (HMODULE)0x0) && (DAT_4054435c != DAT_40544588)) {
      DAT_4054435c = (HMODULE)0x0;
    }
    if (DAT_40544704 != 0) {
      CloseHandle((HANDLE)DAT_40544704);
    }
    if (param_3 == 0) {
      FUN_40541d6c();
      piVar1 = DAT_405445a4;
      if (DAT_405445a4 != (int *)0x0) {
        DAT_405445a4 = (int *)0x0;
        (**(code **)(*piVar1 + 8))();
      }
      SHUnregisterClassesW(DAT_40544588,&PTR_u_Shell_DocObject_View_40511188,4);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40544574);
  }
  return 1;
}



/* 40516d54 FUN_40516d54 */

/* Boundary evidence: original MIPS .pdata 40516d54..40516d73. Semantic name remains unreviewed. */

void FUN_40516d54(void)

{
  InterlockedIncrement(&DAT_40544570);
  return;
}



/* 40516d74 FUN_40516d74 */

/* Boundary evidence: original MIPS .pdata 40516d74..40516d93. Semantic name remains unreviewed. */

void FUN_40516d74(void)

{
  InterlockedDecrement(&DAT_40544570);
  return;
}



/* 40516d94 FUN_40516d94 */

/* Boundary evidence: original MIPS .pdata 40516d94..40516e13. Semantic name remains unreviewed. */

void FUN_40516d94(IID *param_1,LPUNKNOWN param_2,DWORD param_3,IID *param_4,LPVOID *param_5)

{
  int *piVar1;
  
  piVar1 = (int *)PTR_PTR_40544328;
  if (param_3 == 1) {
    for (; (IID *)piVar1[1] != (IID *)0x0; piVar1 = piVar1 + 8) {
      if (param_1 == (IID *)piVar1[1]) {
        (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_4,param_5);
        return;
      }
    }
  }
  CoCreateInstance(param_1,param_2,param_3,param_4,param_5);
  return;
}



/* 40516e14 FUN_40516e14 */

/* Boundary evidence: original MIPS .pdata 40516e14..40516e93. Semantic name remains unreviewed. */

int FUN_40516e14(UINT param_1,LPWSTR param_2,int param_3)

{
  HMODULE hInstance;
  int iVar1;
  
  hInstance = LoadLibraryW((LPCWSTR)&DAT_40544364);
  iVar1 = LoadStringW(hInstance,param_1,param_2,param_3);
  FreeLibrary(hInstance);
  return iVar1;
}



/* 40516e94 FUN_40516e94 */

/* Boundary evidence: original MIPS .pdata 40516e94..40517007. Semantic name remains unreviewed. */

int FUN_40516e94(HWND param_1,WCHAR *param_2,LPCWSTR param_3,uint param_4)

{
  int iVar1;
  LPCWSTR local_a28;
  va_list local_a24;
  WCHAR aWStack_a20 [256];
  WCHAR aWStack_820 [1024];
  uint local_20;
  
  local_20 = DAT_40544354;
  local_a28 = (LPCWSTR)0x0;
  if ((((uint)param_2 & 0xffff0000) == 0) &&
     (iVar1 = FUN_40516e14((uint)param_2 & 0xffff,aWStack_820,0x400), iVar1 != 0)) {
    param_2 = aWStack_820;
  }
  if ((((uint)param_2 & 0xffff0000) != 0) && (param_2 != (WCHAR *)0x0)) {
    local_a24 = &stack0x00000010;
    FormatMessageW(0x500,param_2,0,0,(LPWSTR)&local_a28,0,&local_a24);
    local_a24 = (va_list)0x0;
  }
  if ((((uint)param_3 & 0xffff0000) == 0) || (param_3 == (LPCWSTR)0x0)) {
    if (((param_3 == (LPCWSTR)0x0) ||
        (iVar1 = FUN_40516e14((uint)param_3 & 0xffff,aWStack_a20,0x100), iVar1 == 0)) &&
       ((param_1 == (HWND)0x0 || (iVar1 = GetWindowTextW(param_1,aWStack_a20,0x100), iVar1 == 0))))
    {
      param_3 = L"";
    }
    else {
      param_3 = aWStack_a20;
    }
  }
  iVar1 = MessageBoxW(param_1,local_a28,param_3,param_4 | 0x10000);
  if (local_a28 != (LPCWSTR)0x0) {
    LocalFree(local_a28);
  }
  FUN_40542538(local_20);
  return iVar1;
}



/* 40517008 FUN_40517008 */

/* Boundary evidence: original MIPS .pdata 40517008..4051709b. Semantic name remains unreviewed. */

undefined4 FUN_40517008(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_4051630c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405162fc,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    InterlockedIncrement(&DAT_40544570);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 4051709c FUN_4051709c */

/* Boundary evidence: original MIPS .pdata 4051709c..405170bf. Semantic name remains unreviewed. */

undefined4 FUN_4051709c(void)

{
  InterlockedIncrement(&DAT_40544570);
  return 2;
}



/* 405170c0 FUN_405170c0 */

/* Boundary evidence: original MIPS .pdata 405170c0..405170e3. Semantic name remains unreviewed. */

undefined4 FUN_405170c0(void)

{
  InterlockedDecrement(&DAT_40544570);
  return 1;
}



/* 405170e4 FUN_405170e4 */

/* Boundary evidence: original MIPS .pdata 405170e4..405171b7. Semantic name remains unreviewed. */

int FUN_405170e4(int param_1,int param_2,void *param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_20 [2];
  
  *param_4 = 0;
  if ((param_2 == 0) ||
     ((iVar1 = memcmp(param_3,&DAT_405162fc,0x10), iVar1 == 0 &&
      ((*(uint *)(param_1 + 0x1c) & 1) != 0)))) {
    iVar1 = (**(code **)(param_1 + 8))(param_2,local_20,param_1);
    if (-1 < iVar1) {
      iVar1 = (**(code **)*local_20[0])(local_20[0],param_3,param_4);
      (**(code **)(*local_20[0] + 8))();
    }
  }
  else {
    iVar1 = -0x7ffbfef0;
  }
  return iVar1;
}



/* 405171b8 FUN_405171b8 */

/* Boundary evidence: original MIPS .pdata 405171b8..405171f7. Semantic name remains unreviewed. */

undefined4 FUN_405171b8(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    InterlockedDecrement(&DAT_40544570);
  }
  else {
    InterlockedIncrement(&DAT_40544570);
  }
  return 0;
}



/* 405171f8 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 405171f8..405172bf. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  undefined *puVar2;
  
                    /* 0x71f8  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_4051630c,0x10);
  puVar2 = PTR_PTR_40544328;
  if ((iVar1 == 0) ||
     (iVar1 = memcmp(riid,&DAT_405162fc,0x10), puVar2 = PTR_PTR_40544328, iVar1 == 0)) {
    for (; *(void **)(puVar2 + 4) != (void *)0x0; puVar2 = puVar2 + 0x20) {
      iVar1 = memcmp(rclsid,*(void **)(puVar2 + 4),0x10);
      if (iVar1 == 0) {
        *ppv = puVar2;
        InterlockedIncrement(&DAT_40544570);
        return 0;
      }
    }
  }
  *ppv = (LPVOID)0x0;
  return -0x7ffbfeef;
}



/* 405172c0 FUN_405172c0 */

/* Boundary evidence: original MIPS .pdata 405172c0..40517323. Semantic name remains unreviewed. */

void FUN_405172c0(void)

{
  HDC hdc;
  
  hdc = GetDC((HWND)0x0);
  if (hdc != (HDC)0x0) {
    DAT_4054459c = GetDeviceCaps(hdc,0x58);
    DAT_405445a0 = GetDeviceCaps(hdc,0x5a);
    ReleaseDC((HWND)0x0,hdc);
  }
  return;
}



/* 40517324 FUN_40517324 */

/* Boundary evidence: original MIPS .pdata 40517324..40517387. Semantic name remains unreviewed. */

void FUN_40517324(int *param_1)

{
  int iVar1;
  
  iVar1 = MulDiv(*param_1,0x9ec,DAT_4054459c);
  *param_1 = iVar1;
  iVar1 = MulDiv(param_1[1],0x9ec,DAT_405445a0);
  param_1[1] = iVar1;
  return;
}



/* 40517388 FUN_40517388 */

/* Boundary evidence: original MIPS .pdata 40517388..405173b3. Semantic name remains unreviewed. */

void FUN_40517388(int param_1,IID *param_2,void **param_3)

{
  QISearch((void *)(param_1 + -0x1c),(LPCQITAB)&PTR_DAT_40511260,param_2,param_3);
  return;
}



/* 405173b4 FUN_405173b4 */

/* Boundary evidence: original MIPS .pdata 405173b4..405174f3. Semantic name remains unreviewed. */

void FUN_405173b4(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40511468;
  param_1[1] = &PTR_LAB_40511408;
  param_1[2] = &PTR_LAB_405113e0;
  param_1[3] = &PTR_LAB_405113b0;
  param_1[4] = &PTR_LAB_4051138c;
  param_1[5] = &PTR_LAB_40511364;
  param_1[6] = &PTR_LAB_40511350;
  param_1[7] = &PTR_LAB_4051133c;
  param_1[0xb] = &PTR_LAB_40511330;
  if ((HWND)param_1[0xc] != (HWND)0x0) {
    DestroyWindow((HWND)param_1[0xc]);
    param_1[0xc] = 0;
  }
  piVar1 = (int *)param_1[0xf];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))();
    if (param_1[0xd] == 0) {
      IUnknown_AtomicRelease((void **)(param_1 + 0xf));
    }
  }
  if (param_1[0xd] == 0) {
    IUnknown_AtomicRelease((void **)(param_1 + 0x19));
    IUnknown_AtomicRelease((void **)(param_1 + 0x18));
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0x12));
  IUnknown_AtomicRelease((void **)(param_1 + 0xe));
  FUN_40516d74();
  FUN_4052f040(param_1 + 7);
  return;
}



/* 405174f4 FUN_405174f4 */

/* Boundary evidence: original MIPS .pdata 405174f4..4051750f. Semantic name remains unreviewed. */

void FUN_405174f4(int param_1)

{
  FUN_4052efbc(param_1 + 0x1c);
  return;
}



/* 40517510 FUN_40517510 */

/* Boundary evidence: original MIPS .pdata 40517510..4051752b. Semantic name remains unreviewed. */

void FUN_40517510(int param_1)

{
  FUN_4052ef6c(param_1 + 0x1c);
  return;
}



/* 4051752c FUN_4051752c */

/* Boundary evidence: original MIPS .pdata 4051752c..40517547. Semantic name remains unreviewed. */

void FUN_4051752c(int param_1)

{
  FUN_4052ef94(param_1 + 0x1c);
  return;
}



/* 40517548 FUN_40517548 */

undefined4 FUN_40517548(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x5c) + 4);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  param_2[3] = puVar1[3];
  return 0;
}



/* 40517578 FUN_40517578 */

undefined4 FUN_40517578(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x80) == 0) || (param_3 == 0x3039)) {
    uVar1 = 0x80040007;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 405175b8 FUN_405175b8 */

/* Boundary evidence: original MIPS .pdata 405175b8..4051761f. Semantic name remains unreviewed. */

undefined4 FUN_405175b8(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x3c);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(param_1 + 0x38);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
  }
  return 0;
}



/* 40517620 FUN_40517620 */

/* Boundary evidence: original MIPS .pdata 40517620..40517653. Semantic name remains unreviewed. */

undefined4 FUN_40517620(int param_1)

{
  int *in_stack_00000010;
  
  *in_stack_00000010 = *(int *)(param_1 + 0x44);
  in_stack_00000010[1] = *(int *)(param_1 + 0x48);
  FUN_40517324(in_stack_00000010);
  return 0;
}



/* 40517654 FUN_40517654 */

/* Boundary evidence: original MIPS .pdata 40517654..4051770f. Semantic name remains unreviewed. */

undefined4 FUN_40517654(int param_1,int *param_2)

{
  void **ppunk;
  
  IUnknown_AtomicRelease((void **)(param_1 + 0x34));
  ppunk = (void **)(param_1 + 0x30);
  if (*ppunk != param_2) {
    IUnknown_AtomicRelease(ppunk);
    IUnknown_AtomicRelease((void **)(param_1 + 0x84));
    IUnknown_AtomicRelease((void **)(param_1 + 0x88));
    IUnknown_AtomicRelease((void **)(param_1 + 0x8c));
    *ppunk = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    (**(code **)(*(int *)(param_1 + -4) + 0x10))();
  }
  return 0;
}



/* 40517710 FUN_40517710 */

/* Boundary evidence: original MIPS .pdata 40517710..405177ff. Semantic name remains unreviewed. */

undefined4 FUN_40517710(int param_1,int *param_2)

{
  HWND pHVar1;
  DWORD dwStyle;
  undefined4 uVar2;
  HWND local_18 [2];
  
  local_18[0] = (HWND)0x0;
  uVar2 = 0;
  (**(code **)(*param_2 + 0xc))(param_2,local_18);
  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 2;
  if (*(int *)(param_1 + 0x30) == 0) {
    dwStyle = 0x46010000;
    if (local_18[0] == (HWND)0x0) {
      dwStyle = 0x86010000;
    }
    pHVar1 = CreateWindowExW(0,L"Shell Embedding",(LPCWSTR)0x0,dwStyle,0,0,
                             *(int *)(param_1 + 0x70) - *(int *)(param_1 + 0x68),
                             *(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x6c),local_18[0],
                             (HMENU)0x0,DAT_40544588,(LPVOID)(param_1 + 0x2c));
    *(HWND *)(param_1 + 0x30) = pHVar1;
    if (pHVar1 == (HWND)0x0) {
      uVar2 = 0x80004005;
    }
  }
  else {
    SHSetParentHwnd(*(int *)(param_1 + 0x30),local_18[0]);
  }
  return uVar2;
}



/* 40517800 FUN_40517800 */

/* Boundary evidence: original MIPS .pdata 40517800..4051783f. Semantic name remains unreviewed. */

undefined4 FUN_40517800(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x30);
  if (*(int **)(param_1 + 0x30) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x30) + 4))();
  }
  return 0;
}



/* 40517840 FUN_40517840 */

/* Boundary evidence: original MIPS .pdata 40517840..4051788b. Semantic name remains unreviewed. */

undefined4 FUN_40517840(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == param_1[0x2d]) && ((param_3 != 2 || (param_4 == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 0x14))();
  }
  return uVar1;
}



/* 4051788c FUN_4051788c */

/* Boundary evidence: original MIPS .pdata 4051788c..405179b7. Semantic name remains unreviewed. */

int FUN_4051788c(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  void **ppunk;
  
  iVar1 = param_1[0x2d];
  if (param_3 == iVar1) {
    return 0;
  }
  param_1[0x2d] = param_3;
  if (iVar1 == 0) {
    if (param_2 == (undefined4 *)0x0) {
      iVar1 = -0x7ff8ffa9;
      goto LAB_40517940;
    }
    ppunk = (void **)(param_1 + 0x22);
    if (*ppunk != (void *)0x0) goto LAB_4051796c;
    iVar1 = (**(code **)*param_2)(param_2,&DAT_405163ac,ppunk);
    if (iVar1 < 0) {
LAB_40517940:
      param_1[0x2d] = 0;
      return iVar1;
    }
    iVar1 = (**(code **)(*(int *)*ppunk + 0x14))();
    if (iVar1 != 0) {
      IUnknown_AtomicRelease(ppunk);
      iVar1 = -0x7fffbffb;
      goto LAB_40517940;
    }
    pcVar2 = *(code **)(*param_1 + 0x18);
  }
  else {
    if (iVar1 != 2) goto LAB_4051796c;
    pcVar2 = *(code **)(*param_1 + 0x20);
  }
  (*pcVar2)(param_1);
LAB_4051796c:
  if (param_3 == 2) {
    pcVar2 = *(code **)(*param_1 + 0x1c);
  }
  else {
    if (param_3 != 0) {
      return 0;
    }
    pcVar2 = *(code **)(*param_1 + 0x24);
  }
  (*pcVar2)(param_1);
  return 0;
}



/* 405179b8 FUN_405179b8 */

/* Boundary evidence: original MIPS .pdata 405179b8..40517ac3. Semantic name remains unreviewed. */

void FUN_405179b8(int param_1)

{
  HWND hWnd;
  int *piVar1;
  
  if (*(int **)(param_1 + 0x88) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x88) + 0x1c))();
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,param_1 + 0x14,L"item");
  }
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,param_1 + 0x14,L"item");
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1,0,0,*(undefined4 *)(param_1 + 0x30));
  }
  hWnd = GetFocus();
  if (hWnd != (HWND)0x0) {
    do {
      if (hWnd == *(HWND *)(param_1 + 0x30)) break;
      hWnd = GetParent(hWnd);
    } while (hWnd != (HWND)0x0);
    if (hWnd != (HWND)0x0) goto LAB_40517a9c;
  }
  SetFocus(*(HWND *)(param_1 + 0x30));
LAB_40517a9c:
  IUnknown_OnFocusOCS(*(undefined4 *)(param_1 + 0x34),1);
  return;
}



/* 40517ac4 FUN_40517ac4 */

/* Boundary evidence: original MIPS .pdata 40517ac4..40517b5f. Semantic name remains unreviewed. */

void FUN_40517ac4(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,0,0);
  }
  piVar1 = *(int **)(param_1 + 0x90);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(piVar1,0,0);
  }
  piVar1 = *(int **)(param_1 + 0x88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1,0);
  }
  IUnknown_OnFocusOCS(*(undefined4 *)(param_1 + 0x34),0);
  return;
}



/* 40517b60 FUN_40517b60 */

/* Boundary evidence: original MIPS .pdata 40517b60..40517b87. Semantic name remains unreviewed. */

void FUN_40517b60(int param_1)

{
  (**(code **)(*(int *)(param_1 + -4) + 0xc))();
  return;
}



/* 40517b88 FUN_40517b88 */

undefined4 FUN_40517b88(int param_1,undefined4 param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 0x50) = *param_3;
  *(undefined4 *)(param_1 + 0x54) = param_3[1];
  return 0;
}



/* 40517bb8 FUN_40517bb8 */

/* Boundary evidence: original MIPS .pdata 40517bb8..40517c4b. Semantic name remains unreviewed. */

int FUN_40517bb8(int param_1,IAdviseSink *param_2,DWORD *param_3)

{
  int iVar1;
  LPOLEADVISEHOLDER *ppOAHolder;
  
  if (param_3 == (DWORD *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    ppOAHolder = (LPOLEADVISEHOLDER *)(param_1 + 0x5c);
    *param_3 = 0;
    if (*ppOAHolder == (LPOLEADVISEHOLDER)0x0) {
      iVar1 = CreateOleAdviseHolder(ppOAHolder);
    }
    else {
      iVar1 = 0;
    }
    if (-1 < iVar1) {
      iVar1 = (*(*ppOAHolder)->lpVtbl->Advise)(*ppOAHolder,param_2,param_3);
    }
  }
  return iVar1;
}



/* 40517c4c FUN_40517c4c */

/* Boundary evidence: original MIPS .pdata 40517c4c..40517c8b. Semantic name remains unreviewed. */

undefined4 FUN_40517c4c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x5c) == 0) {
    uVar1 = 0x80040004;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x10))();
  }
  return uVar1;
}



/* 40517c8c FUN_40517c8c */

/* Boundary evidence: original MIPS .pdata 40517c8c..40517cdf. Semantic name remains unreviewed. */

undefined4 FUN_40517c8c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x5c) == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x14))();
  }
  return uVar1;
}



/* 40517d28 FUN_40517d28 */

/* Boundary evidence: original MIPS .pdata 40517d28..40517d67. Semantic name remains unreviewed. */

undefined4 FUN_40517d28(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x58) == 0) {
    uVar1 = 0x80040004;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0x10))();
  }
  return uVar1;
}



/* 40517d68 FUN_40517d68 */

/* Boundary evidence: original MIPS .pdata 40517d68..40517dbb. Semantic name remains unreviewed. */

undefined4 FUN_40517d68(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x58) == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0x14))();
  }
  return uVar1;
}



/* 40517dcc FUN_40517dcc */

/* Boundary evidence: original MIPS .pdata 40517dcc..40517e0b. Semantic name remains unreviewed. */

undefined4 FUN_40517dcc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + -0x10) + 0x14))((int *)(param_1 + -0x10),0,0);
  }
  return uVar1;
}



/* 40517e0c FUN_40517e0c */

/* Boundary evidence: original MIPS .pdata 40517e0c..40517e4f. Semantic name remains unreviewed. */

undefined4 FUN_40517e0c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*(int *)(param_1 + -0x10) + 0x14))((int *)(param_1 + -0x10),0,1);
  }
  return uVar1;
}



/* 40517e50 FUN_40517e50 */

/* Boundary evidence: original MIPS .pdata 40517e50..40517fd3. Semantic name remains unreviewed. */

undefined4 FUN_40517e50(int param_1,LONG *param_2,LONG *param_3)

{
  BOOL BVar1;
  HRGN hRgn;
  RECT *lprcSrc2;
  int iVar2;
  int iVar3;
  LONG LVar4;
  int iVar5;
  RECT *lprcSrc1;
  tagRECT tStack_20;
  
  lprcSrc1 = (RECT *)(param_1 + 0x58);
  lprcSrc1->left = *param_2;
  *(LONG *)(param_1 + 0x5c) = param_2[1];
  lprcSrc2 = (RECT *)(param_1 + 0x68);
  *(LONG *)(param_1 + 0x60) = param_2[2];
  *(LONG *)(param_1 + 100) = param_2[3];
  if (param_3 == (LONG *)0x0) {
    lprcSrc2->left = *param_2;
    *(LONG *)(param_1 + 0x6c) = param_2[1];
    *(LONG *)(param_1 + 0x70) = param_2[2];
    LVar4 = param_2[3];
  }
  else {
    lprcSrc2->left = *param_3;
    *(LONG *)(param_1 + 0x6c) = param_3[1];
    *(LONG *)(param_1 + 0x70) = param_3[2];
    LVar4 = param_3[3];
  }
  *(LONG *)(param_1 + 0x74) = LVar4;
  IntersectRect(&tStack_20,lprcSrc1,lprcSrc2);
  BVar1 = EqualRect(&tStack_20,lprcSrc1);
  if (BVar1 == 0) {
    iVar2 = lprcSrc1->left;
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) | 4;
    OffsetRect(&tStack_20,-iVar2,-*(int *)(param_1 + 0x5c));
    hRgn = CreateRectRgnIndirect(&tStack_20);
    SetWindowRgn(*(HWND *)(param_1 + 0x20),hRgn,1);
  }
  else if ((*(uint *)(param_1 + 0xa0) & 4) != 0) {
    SetWindowRgn(*(HWND *)(param_1 + 0x20),(HRGN)0x0,1);
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffffb;
  }
  iVar2 = lprcSrc1->left;
  iVar5 = *(int *)(param_1 + 0x60) - iVar2;
  iVar3 = *(int *)(param_1 + 100) - *(int *)(param_1 + 0x5c);
  if ((-1 < iVar5) && (-1 < iVar3)) {
    *(int *)(param_1 + 0x3c) = iVar5;
    *(int *)(param_1 + 0x40) = iVar3;
  }
  if (*(HWND *)(param_1 + 0x20) != (HWND)0x0) {
    SetWindowPos(*(HWND *)(param_1 + 0x20),(HWND)0x0,iVar2,*(int *)(param_1 + 0x5c),
                 *(int *)(param_1 + 0x3c),*(int *)(param_1 + 0x40),0x14);
  }
  return 0;
}



/* 40517fe0 FUN_40517fe0 */

/* Boundary evidence: original MIPS .pdata 40517fe0..40518047. Semantic name remains unreviewed. */

undefined4 FUN_40517fe0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  iVar1 = FUN_4052e3e4(param_2);
  if (iVar1 != 0) {
    uVar2 = IUnknown_TranslateAcceleratorOCS(*(undefined4 *)(param_1 + 0x20),param_2,0);
  }
  return uVar2;
}



/* 40518048 FUN_40518048 */

/* Boundary evidence: original MIPS .pdata 40518048..4051806f. Semantic name remains unreviewed. */

undefined4 FUN_40518048(int param_1,int param_2)

{
  if (param_2 != 0) {
    SetFocus(*(HWND *)(param_1 + 0x1c));
  }
  return 0;
}



/* 40518070 FUN_40518070 */

/* Boundary evidence: original MIPS .pdata 40518070..405180ef. Semantic name remains unreviewed. */

void FUN_40518070(void)

{
  undefined4 local_30;
  code *local_2c [2];
  undefined4 local_24;
  undefined4 local_20;
  HCURSOR local_18;
  undefined4 local_14;
  wchar_t *local_c;
  
  memset(local_2c,0,0x24);
  local_30 = 8;
  local_24 = 8;
  local_2c[0] = FUN_4052f1e4;
  local_20 = DAT_40544588;
  local_18 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  local_14 = 0x40000006;
  local_c = L"Shell Embedding";
  SHRegisterClassW(&local_30);
  return;
}



/* 405180f0 FUN_405180f0 */

/* Boundary evidence: original MIPS .pdata 405180f0..40518207. Semantic name remains unreviewed. */

LRESULT FUN_405180f0(int param_1,HWND param_2,UINT param_3,WPARAM param_4,int param_5)

{
  LRESULT LVar1;
  undefined4 uVar2;
  
  if (param_3 == 1) {
    GetWindowLongW(param_2,-0x14);
LAB_405181d8:
    LVar1 = DefWindowProcW(*(HWND *)(param_1 + 4),param_3,param_4,param_5);
  }
  else {
    if (param_3 == 7) {
      if (*(HWND *)(param_1 + 0x7c) != (HWND)0x0) {
        SetFocus(*(HWND *)(param_1 + 0x7c));
      }
      uVar2 = 1;
    }
    else {
      if (param_3 != 8) {
        if (((param_3 == 0x47) && (*(HWND *)(param_1 + 0x7c) != (HWND)0x0)) &&
           ((*(uint *)(param_5 + 0x18) & 1) == 0)) {
          SetWindowPos(*(HWND *)(param_1 + 0x7c),(HWND)0x0,0,0,*(int *)(param_5 + 0x10),
                       *(int *)(param_5 + 0x14),0x16);
        }
        goto LAB_405181d8;
      }
      uVar2 = 0;
    }
    IUnknown_OnFocusOCS(*(undefined4 *)(param_1 + 8),uVar2);
    LVar1 = 0;
  }
  return LVar1;
}



/* 40518208 FUN_40518208 */

/* Boundary evidence: original MIPS .pdata 40518208..4051828b. Semantic name remains unreviewed. */

void FUN_40518208(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (((*(uint *)(param_1 + 0x44) & param_2) != 0) &&
     (piVar1 = *(int **)(param_1 + 0x3c), piVar1 != (int *)0x0)) {
    if ((*(uint *)(param_1 + 0x40) & 4) == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      *(undefined4 *)(param_1 + 0x3c) = 0;
      piVar2 = piVar1;
    }
    (**(code **)(*piVar1 + 0x10))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  return;
}



/* 4051828c FUN_4051828c */

/* Boundary evidence: original MIPS .pdata 4051828c..405183bb. Semantic name remains unreviewed. */

void FUN_4051828c(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  
  if (param_2 == 0) {
    if (*(int **)(param_1 + 0x60) == (int *)0x0) {
      return;
    }
    pcVar2 = *(code **)(**(int **)(param_1 + 0x60) + 0x1c);
  }
  else {
    if (param_2 != 1) {
      if (param_2 == 3) {
        if (((*(uint *)(param_1 + 0xb0) & 1) != 0) && (*(int **)(param_1 + 0x34) != (int *)0x0)) {
          (**(code **)(**(int **)(param_1 + 0x34) + 0xc))();
        }
        *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) & 0xfffffffe;
        return;
      }
      if (param_2 == 4) {
        piVar1 = *(int **)(param_1 + 100);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x18))(piVar1,param_1 + 0xc,0,0);
        }
      }
      else {
        if (param_2 == 7) {
          if (*(int **)(param_1 + 0x34) == (int *)0x0) {
            return;
          }
          pcVar2 = *(code **)(**(int **)(param_1 + 0x34) + 0x18);
          goto LAB_405183a4;
        }
        if (param_2 != 8) {
          return;
        }
      }
      FUN_40518208(param_1,3);
      return;
    }
    if (*(int **)(param_1 + 0x60) == (int *)0x0) {
      return;
    }
    pcVar2 = *(code **)(**(int **)(param_1 + 0x60) + 0x20);
  }
LAB_405183a4:
  (*pcVar2)();
  return;
}



/* 405183bc FUN_405183bc */

/* Boundary evidence: original MIPS .pdata 405183bc..4051844f. Semantic name remains unreviewed. */

undefined4 FUN_405183bc(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_405163bc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405162fc,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    uVar2 = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 40518450 FUN_40518450 */

/* Boundary evidence: original MIPS .pdata 40518450..4051847f. Semantic name remains unreviewed. */

int FUN_40518450(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 4) + -1;
  *(int *)((int)param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40518480 FUN_40518480 */

/* Boundary evidence: original MIPS .pdata 40518480..405185df. Semantic name remains unreviewed. */

undefined4 FUN_40518480(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  LPWSTR pWVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar5 = 1;
  uVar6 = 0;
  if (uVar2 < 5) {
    iVar3 = uVar2 * 0x10;
    *param_3 = *(undefined4 *)(&DAT_4051149c + iVar3);
    param_3[1] = *(undefined4 *)(&DAT_405114a0 + iVar3);
    param_3[2] = *(undefined4 *)(&DAT_405114a4 + iVar3);
    param_3[3] = *(undefined4 *)(&DAT_405114a8 + iVar3);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
    if ((iVar3 == 0) || (iVar7 = (uVar2 - 5) * 0x10, *(int *)(iVar7 + iVar3 + 4) == 0))
    goto LAB_405185a8;
    puVar4 = (undefined4 *)(uVar2 * 0x10 + iVar3);
    *param_3 = *puVar4;
    param_3[1] = puVar4[1];
    param_3[2] = puVar4[2];
    param_3[3] = puVar4[3];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    pWVar1 = CoTaskMemAlloc(0x100);
    if (pWVar1 == (LPWSTR)0x0) {
      uVar5 = 0x8007000e;
      goto LAB_405185a8;
    }
    FUN_40516a3c(*(UINT *)(*(int *)(param_1 + 0xc) + iVar7 + 4),pWVar1,0x80);
    param_3[1] = pWVar1;
    uVar6 = 1;
  }
  uVar5 = 0;
LAB_405185a8:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = uVar6;
  }
  return uVar5;
}



/* 40518808 FUN_40518808 */

/* Boundary evidence: original MIPS .pdata 40518808..40518853. Semantic name remains unreviewed. */

undefined4 * FUN_40518808(undefined4 *param_1,uint param_2)

{
  FUN_405173b4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40518854 FUN_40518854 */

/* Boundary evidence: original MIPS .pdata 40518854..4051891b. Semantic name remains unreviewed. */

undefined4 FUN_40518854(int param_1,undefined4 param_2,uint param_3,int *param_4)

{
  undefined4 uVar1;
  void **ppunk;
  
  if ((param_3 & 0xfffffff9) == 0) {
    ppunk = (void **)(param_1 + 0x34);
    if ((param_4 != *ppunk) && (IUnknown_AtomicRelease(ppunk), param_4 != (int *)0x0)) {
      *ppunk = param_4;
      (**(code **)(*param_4 + 4))(param_4);
    }
    *(undefined4 *)(param_1 + 0x3c) = param_2;
    *(uint *)(param_1 + 0x38) = param_3;
    if ((param_3 & 2) != 0) {
      FUN_40518208(param_1 + -8,3);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 4051891c FUN_4051891c */

/* Boundary evidence: original MIPS .pdata 4051891c..405189a7. Semantic name remains unreviewed. */

void FUN_4051891c(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_10 [2];
  
  puVar2 = *(undefined4 **)(param_1 + 0x34);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
      DestroyWindow(*(HWND *)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  else {
    iVar1 = (**(code **)*puVar2)(puVar2,&DAT_405163ac,local_10);
    if (-1 < iVar1) {
      FUN_40517710(param_1,local_10[0]);
      (**(code **)(*local_10[0] + 8))();
    }
  }
  return;
}



/* 405189a8 FUN_405189a8 */

/* Boundary evidence: original MIPS .pdata 405189a8..40518ac7. Semantic name remains unreviewed. */

undefined4 FUN_405189a8(int *param_1,int param_2)

{
  int *piVar1;
  
  if (((param_1[0x2b] & 1U) != 0) && ((param_2 == 0 || (param_2 == 2)))) {
    FUN_4051828c((int)(param_1 + -1),3);
    if ((int *)param_1[0x17] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x17] + 0x1c))();
    }
  }
  if ((int *)param_1[0x17] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x17] + 0x20))();
  }
  param_1[0x2b] = param_1[0x2b] & 0xfffffffd;
  if (param_1[0x2c] != 0) {
    (**(code **)(param_1[-1] + 0x14))(param_1 + -1,0,0);
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0xd));
  piVar1 = (int *)param_1[0xc];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  (**(code **)(*param_1 + 0xc))(param_1,0);
  param_1[0xd] = (int)piVar1;
  return 0;
}



/* 40518ac8 FUN_40518ac8 */

/* Boundary evidence: original MIPS .pdata 40518ac8..40518c07. Semantic name remains unreviewed. */

undefined4 FUN_40518ac8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  
  if ((param_1[0xc] == 0) && (piVar3 = (int *)param_1[0xd], piVar3 != (int *)0x0)) {
    pcVar2 = *(code **)(*param_1 + 0xc);
    param_1[0xd] = 0;
    (*pcVar2)(param_1,piVar3);
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  if (param_2 == -5) {
    if (param_1[0x2c] == 1) {
      return 0;
    }
    uVar1 = 1;
LAB_40518bdc:
    pcVar2 = *(code **)(param_1[-1] + 0x14);
  }
  else {
    if (param_2 != -4) {
      if (param_2 == -3) {
        if (param_1[0x2c] == 0) {
          return 0;
        }
        uVar1 = 0;
        param_4 = 0;
        goto LAB_40518bdc;
      }
      if (((param_2 == -2) || (param_2 < -1)) || (0 < param_2)) {
        return 0x80004005;
      }
      if (param_1[0x21] != 0) {
        return 0;
      }
    }
    uVar1 = 2;
    pcVar2 = *(code **)(param_1[-1] + 0x14);
  }
  uVar1 = (*pcVar2)(param_1 + -1,param_4,uVar1);
  return uVar1;
}



/* 40518c08 FUN_40518c08 */

/* Boundary evidence: original MIPS .pdata 40518c08..40518cd7. Semantic name remains unreviewed. */

void FUN_40518c08(int param_1)

{
  int X;
  
  FUN_40517710(param_1,*(int **)(param_1 + 0x88));
  (**(code **)(**(int **)(param_1 + 0x88) + 0x18))();
  *(undefined4 *)(param_1 + 0x94) = 0x14;
  (**(code **)(**(int **)(param_1 + 0x88) + 0x20))
            (*(int **)(param_1 + 0x88),param_1 + 0x8c,param_1 + 0x90,(int *)(param_1 + 0x68),
             param_1 + 0x78,(undefined4 *)(param_1 + 0x94));
  X = *(int *)(param_1 + 0x68);
  SetWindowPos(*(HWND *)(param_1 + 0x30),(HWND)0x0,X,*(int *)(param_1 + 0x6c),
               *(int *)(param_1 + 0x70) - X,*(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x6c),0x44
              );
  if (*(int **)(param_1 + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x34) + 0x18))();
  }
  return;
}



/* 40518cd8 FUN_40518cd8 */

/* Boundary evidence: original MIPS .pdata 40518cd8..40518d6f. Semantic name remains unreviewed. */

void FUN_40518cd8(int param_1)

{
  int *piVar1;
  
  if (*(HWND *)(param_1 + 0x30) != (HWND)0x0) {
    ShowWindow(*(HWND *)(param_1 + 0x30),0);
  }
  piVar1 = *(void **)(param_1 + 0x88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))();
    IUnknown_AtomicRelease((void **)(param_1 + 0x88));
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0x8c));
  IUnknown_AtomicRelease((void **)(param_1 + 0x90));
  FUN_4051828c(param_1,4);
  return;
}



/* 40518d70 FUN_40518d70 */

/* Boundary evidence: original MIPS .pdata 40518d70..40518deb. Semantic name remains unreviewed. */

undefined4 FUN_40518d70(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xa8);
    *puVar1 = &PTR_FUN_405114ec;
    puVar1[1] = 1;
    puVar1[2] = 0;
    puVar1[3] = uVar2;
  }
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40518dec FUN_40518dec */

/* Boundary evidence: original MIPS .pdata 40518dec..40518e67. Semantic name remains unreviewed. */

undefined4 FUN_40518dec(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
    *puVar1 = &PTR_FUN_405114ec;
    puVar1[1] = 1;
    puVar1[2] = 0;
    puVar1[3] = uVar2;
  }
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40518e68 FUN_40518e68 */

/* Boundary evidence: original MIPS .pdata 40518e68..40518fa3. Semantic name remains unreviewed. */

undefined4 *
FUN_40518e68(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[1] = &PTR_LAB_405112b0;
  param_1[2] = &PTR_LAB_40511508;
  param_1[4] = &PTR_LAB_40511530;
  param_1[5] = &PTR_LAB_40511554;
  FUN_4052f168(param_1 + 7,param_2);
  param_1[0xb] = &PTR_LAB_40511310;
  *param_1 = &PTR_FUN_40511468;
  param_1[1] = &PTR_LAB_40511408;
  param_1[2] = &PTR_LAB_405113e0;
  param_1[3] = &PTR_LAB_405113b0;
  param_1[4] = &PTR_LAB_4051138c;
  param_1[5] = &PTR_LAB_40511364;
  param_1[6] = &PTR_LAB_40511350;
  param_1[7] = &PTR_LAB_4051133c;
  param_1[0xb] = &PTR_LAB_40511330;
  param_1[0x2b] = param_4;
  param_1[0x2d] = 0;
  FUN_40516d54();
  FUN_40518070();
  param_1[0x17] = param_3;
  param_1[0x13] = 0x32;
  param_1[0x14] = 0x14;
  FUN_405172c0();
  param_1[0x15] = param_1[0x13];
  param_1[0x16] = param_1[0x14];
  FUN_40517324(param_1 + 0x15);
  return param_1;
}



/* 40518fa4 FUN_40518fa4 */

/* Boundary evidence: original MIPS .pdata 40518fa4..40518fe7. Semantic name remains unreviewed. */

void FUN_40518fa4(int param_1,MEMBERID param_2,void *param_3,uint param_4,WORD param_5,
                 DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  FUN_4052f890((undefined4 *)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6,param_7,param_8
               ,param_9);
  return;
}



/* 40518fe8 FUN_40518fe8 */

/* Boundary evidence: original MIPS .pdata 40518fe8..40519003. Semantic name remains unreviewed. */

void FUN_40518fe8(int param_1)

{
  FUN_4052efbc(param_1);
  return;
}



/* 40519004 FUN_40519004 */

/* Boundary evidence: original MIPS .pdata 40519004..405191bf. Semantic name remains unreviewed. */

void FUN_40519004(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40511b5c;
  param_1[1] = &PTR_LAB_40511afc;
  param_1[2] = &PTR_LAB_40511ad4;
  param_1[3] = &PTR_LAB_40511aa4;
  param_1[4] = &PTR_LAB_40511a80;
  param_1[5] = &PTR_LAB_40511a58;
  param_1[6] = &PTR_LAB_40511a44;
  param_1[7] = &PTR_LAB_40511a30;
  param_1[0xb] = &PTR_LAB_40511a24;
  param_1[0x2e] = &PTR_LAB_40511a00;
  param_1[0x2f] = &PTR_LAB_405119e4;
  param_1[0x30] = &PTR_LAB_405119c8;
  param_1[0x31] = &PTR_LAB_405119ac;
  param_1[0x32] = &PTR_LAB_40511998;
  param_1[0x33] = &PTR_LAB_40511980;
  param_1[0x34] = &PTR_LAB_40511978;
  param_1[0x4a] = &PTR_LAB_4051185c;
  param_1[0x4b] = &PTR_LAB_40511840;
  param_1[0x4c] = &PTR_LAB_4051182c;
  param_1[0x4d] = &PTR_LAB_40511818;
  param_1[0x4e] = &PTR_LAB_40511804;
  param_1[0x4f] = &PTR_LAB_405117f0;
  piVar1 = (int *)param_1[0x5c];
  param_1[0x51] = &PTR_LAB_405117e0;
  param_1[0x52] = &PTR_LAB_405117ac;
  param_1[0x53] = &PTR_LAB_4051178c;
  if (piVar1 != (int *)0x0) {
    param_1[0x5c] = 0;
    (**(code **)(*piVar1 + 8))();
  }
  param_1[10] = param_1 + 8;
  IUnknown_AtomicRelease((void **)(param_1 + 0x55));
  IUnknown_AtomicRelease((void **)(param_1 + 0x56));
  IUnknown_AtomicRelease((void **)(param_1 + 0x54));
  FUN_40530f9c(param_1 + 0x5f);
  param_1[0x4b] = &PTR_LAB_40511748;
  FUN_4052fad4(param_1);
  return;
}



/* 405191c0 FUN_405191c0 */

/* Boundary evidence: original MIPS .pdata 405191c0..405191db. Semantic name remains unreviewed. */

void FUN_405191c0(int param_1)

{
  FUN_4052efbc(param_1 + 0x1c);
  return;
}



/* 405191dc FUN_405191dc */

/* Boundary evidence: original MIPS .pdata 405191dc..405191f7. Semantic name remains unreviewed. */

void FUN_405191dc(int param_1)

{
  FUN_4052ef6c(param_1 + 0x1c);
  return;
}



/* 405191f8 FUN_405191f8 */

/* Boundary evidence: original MIPS .pdata 405191f8..40519213. Semantic name remains unreviewed. */

void FUN_405191f8(int param_1)

{
  FUN_4052ef94(param_1 + 0x1c);
  return;
}



/* 40519214 FUN_40519214 */

/* Boundary evidence: original MIPS .pdata 40519214..4051922f. Semantic name remains unreviewed. */

void FUN_40519214(int param_1,undefined4 *param_2)

{
  FUN_40517548(param_1,param_2);
  return;
}



/* 40519230 FUN_40519230 */

/* Boundary evidence: original MIPS .pdata 40519230..4051924b. Semantic name remains unreviewed. */

void FUN_40519230(int param_1,undefined4 *param_2)

{
  FUN_4052f478(param_1 + 0xc,param_2);
  return;
}



/* 4051924c FUN_4051924c */

/* Boundary evidence: original MIPS .pdata 4051924c..40519267. Semantic name remains unreviewed. */

void FUN_4051924c(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  FUN_4052f628(param_1 + 0xc,param_2,param_3,param_4);
  return;
}



/* 40519268 FUN_40519268 */

/* Boundary evidence: original MIPS .pdata 40519268..40519283. Semantic name remains unreviewed. */

void FUN_40519268(int param_1)

{
  FUN_4052efbc(param_1 + 0x1c);
  return;
}



/* 40519284 FUN_40519284 */

/* Boundary evidence: original MIPS .pdata 40519284..4051929f. Semantic name remains unreviewed. */

void FUN_40519284(int param_1)

{
  FUN_4052ef6c(param_1 + 0x1c);
  return;
}



/* 405192a0 FUN_405192a0 */

/* Boundary evidence: original MIPS .pdata 405192a0..405192bb. Semantic name remains unreviewed. */

void FUN_405192a0(int param_1)

{
  FUN_4052ef94(param_1 + 0x1c);
  return;
}



/* 405192bc FUN_405192bc */

/* Boundary evidence: original MIPS .pdata 405192bc..405192d7. Semantic name remains unreviewed. */

void FUN_405192bc(int param_1,undefined4 *param_2)

{
  FUN_4052f478(param_1 + 0xc,param_2);
  return;
}



/* 405192d8 FUN_405192d8 */

/* Boundary evidence: original MIPS .pdata 405192d8..405192f3. Semantic name remains unreviewed. */

void FUN_405192d8(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  FUN_4052f628(param_1 + 0xc,param_2,param_3,param_4);
  return;
}



/* 405192f4 FUN_405192f4 */

/* Boundary evidence: original MIPS .pdata 405192f4..4051931b. Semantic name remains unreviewed. */

void FUN_405192f4(int param_1,void *param_2,LPOLESTR *param_3,UINT param_4,uint param_5,
                 MEMBERID *param_6)

{
  FUN_4052fd68(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* 40519338 FUN_40519338 */

/* Boundary evidence: original MIPS .pdata 40519338..40519353. Semantic name remains unreviewed. */

void FUN_40519338(int param_1,undefined4 *param_2)

{
  FUN_40517548(param_1,param_2);
  return;
}



/* 40519354 FUN_40519354 */

/* Boundary evidence: original MIPS .pdata 40519354..405193cb. Semantic name remains unreviewed. */

void FUN_40519354(int param_1)

{
  if ((*(uint *)(param_1 + 0x15c) & 1) == 0) {
    *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 1;
    *(undefined4 *)(param_1 + 0x4c) = 300;
    *(undefined4 *)(param_1 + 0x50) = 0x96;
    *(int *)(param_1 + 0x54) = 300;
    *(undefined4 *)(param_1 + 0x58) = 0x96;
    FUN_40517324((int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x164) = 1;
    *(undefined4 *)(param_1 + 0x168) = 0x201;
  }
  return;
}



/* 405193cc FUN_405193cc */

/* Boundary evidence: original MIPS .pdata 405193cc..40519533. Semantic name remains unreviewed. */

int FUN_405193cc(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_30 [2];
  
  if ((*(uint *)(param_1 + 0x154) & 1) == 0) {
    FUN_40519354(param_1 + -8);
  }
  if (((*(int *)(param_1 + 0x168) != 0) &&
      (puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x168) + 0xa0), puVar2 != (undefined4 *)0x0)) &&
     (iVar1 = (**(code **)*puVar2)(puVar2,&UNK_4051634c,local_30), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_30[0] + 0xc))
                      (local_30[0],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11);
    (**(code **)(*local_30[0] + 8))();
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  iVar1 = FUN_4052fcc0(param_1,param_2,param_3);
  return iVar1;
}



/* 40519534 FUN_40519534 */

/* Boundary evidence: original MIPS .pdata 40519534..40519643. Semantic name remains unreviewed. */

int FUN_40519534(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_30 [2];
  
  if (((*(int *)(param_1 + 0x168) != 0) &&
      (puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x168) + 0xa0), puVar2 != (undefined4 *)0x0)) &&
     (iVar1 = (**(code **)*puVar2)(puVar2,&UNK_4051634c,local_30), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_30[0] + 0x10))
                      (local_30[0],param_2,param_3,param_4,param_5,param_6,param_7);
    (**(code **)(*local_30[0] + 8))();
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  iVar1 = FUN_405233d0();
  return iVar1;
}



/* 40519644 FUN_40519644 */

/* Boundary evidence: original MIPS .pdata 40519644..4051971b. Semantic name remains unreviewed. */

int FUN_40519644(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *local_20 [2];
  
  iVar1 = FUN_40517b88(param_1,param_2,param_3);
  if ((-1 < iVar1) && (*(int *)(param_1 + 0xb0) == 0)) {
    local_20[0] = (int *)0x0;
    if ((*(int *)(param_1 + 0x16c) != 0) &&
       ((puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x16c) + 0xa0), puVar3 != (undefined4 *)0x0 &&
        (iVar2 = (**(code **)*puVar3)(puVar3,&UNK_40512ee4,local_20), -1 < iVar2)))) {
      iVar1 = (**(code **)(*local_20[0] + 0xc))(local_20[0],param_2,param_3);
      (**(code **)(*local_20[0] + 8))();
    }
    *(undefined4 *)(param_1 + 0x168) = param_2;
  }
  return iVar1;
}



/* 4051971c FUN_4051971c */

/* Boundary evidence: original MIPS .pdata 4051971c..4051976b. Semantic name remains unreviewed. */

undefined4 FUN_4051971c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x170) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x170) + 0x70) = *(undefined4 *)(param_1 + 0x30);
    piVar2 = (int *)(*(int *)(param_1 + 0x170) + 0x14);
    uVar1 = (**(code **)(*piVar2 + 0x94))(piVar2,0);
  }
  return uVar1;
}



/* 4051976c FUN_4051976c */

/* Boundary evidence: original MIPS .pdata 4051976c..40519abf. Semantic name remains unreviewed. */

LRESULT FUN_4051976c(int param_1,HWND param_2,uint param_3,WPARAM param_4,int *param_5)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  LRESULT LVar5;
  int *local_30;
  int *local_2c;
  
  LVar5 = 0;
  if (param_3 == 1) {
    LVar5 = FUN_4051971c(param_1 + -0x2c);
    return LVar5;
  }
  if (param_3 == 0x440) {
    if (param_4 == 0x100) {
      if (param_5 == (int *)0x0) {
        return -0x7fffbfff;
      }
      if (*param_5 != 1) {
        return -0x7fffbfff;
      }
      puVar3 = (undefined4 *)param_5[2];
      if (puVar3 == (undefined4 *)0x0) {
        return -0x7fffbfff;
      }
      iVar2 = (**(code **)*puVar3)(puVar3,&DAT_405163fc,&local_2c);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*local_2c + 0x1c))
                        (local_2c,param_5[3],param_5[4],param_5[5],param_5[6],param_5[7],param_5[8])
      ;
    }
    else {
      if (param_4 != 0x101) {
        return -0x7fffbfff;
      }
      if (param_5 == (int *)0x0) {
        return -0x7fffbfff;
      }
      if (*param_5 != 2) {
        return -0x7fffbfff;
      }
      puVar3 = (undefined4 *)param_5[2];
      if (puVar3 == (undefined4 *)0x0) {
        return -0x7fffbfff;
      }
      iVar2 = (**(code **)*puVar3)(puVar3,&DAT_4051642c,&local_2c);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = (**(code **)(*local_2c + 0xc))(local_2c,&DAT_4051640c,&UNK_4051641c,&local_30);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*local_30 + 0x20))
                          (local_30,param_5[3],param_5[4],(short)param_5[5],param_5[6],param_5[7],
                           param_5[8],param_5[9]);
        (**(code **)(*local_30 + 8))();
      }
    }
    (**(code **)(*local_2c + 8))();
    return iVar2;
  }
  if (param_3 - 0x4c8 < 100) goto LAB_40519a48;
  bVar1 = false;
  if (param_3 == 2) {
    FUN_40536e3c(*(undefined4 **)(param_1 + 300));
LAB_4051999c:
    FUN_405180f0(param_1,param_2,param_3,param_4,(int)param_5);
    bVar1 = true;
  }
  else if (param_3 == 0x10) goto LAB_4051999c;
  if ((*(int *)(param_1 + 0x144) == 0) ||
     (piVar4 = (int *)(*(int *)(param_1 + 0x144) + 0x14),
     LVar5 = (**(code **)(*piVar4 + 0x84))(piVar4,param_2,param_3,param_4,param_5), param_3 != 2)) {
LAB_40519a34:
    if (0x3ff < param_3) {
      return LVar5;
    }
  }
  else if (*(int *)(param_1 + 0x144) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x144) + 0x14) + 0xac))();
    *(undefined4 *)(*(int *)(param_1 + 0x144) + 0x13cc) = 0;
    piVar4 = *(int **)(param_1 + 0x144);
    if (piVar4 != (int *)0x0) {
      *(undefined4 *)(param_1 + 0x144) = 0;
      (**(code **)(*piVar4 + 8))();
      goto LAB_40519a34;
    }
  }
  if (bVar1) {
    return LVar5;
  }
LAB_40519a48:
  if (param_3 == 0x20) {
    if (LVar5 != 0) {
      return LVar5;
    }
  }
  else if (param_3 == 0x4e) {
    return LVar5;
  }
  LVar5 = FUN_405180f0(param_1,param_2,param_3,param_4,(int)param_5);
  return LVar5;
}



/* 40519ac0 FUN_40519ac0 */

/* Boundary evidence: original MIPS .pdata 40519ac0..40519b5f. Semantic name remains unreviewed. */

void FUN_40519ac0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_18 [2];
  
  if (param_1[0x5b] != 0) {
    FUN_40529eec(param_1[0x5b],0);
  }
  puVar2 = (undefined4 *)param_1[0x53];
  if ((puVar2 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*puVar2)(puVar2,&DAT_405135c4,local_18), -1 < iVar1)) {
    (**(code **)(*local_18[0] + 0x10))();
    (**(code **)(*local_18[0] + 8))();
  }
  FUN_405189a8(param_1,param_2);
  return;
}



/* 40519b60 FUN_40519b60 */

/* Boundary evidence: original MIPS .pdata 40519b60..40519bef. Semantic name remains unreviewed. */

void FUN_40519b60(int param_1,LPCWSTR param_2)

{
  int iVar1;
  
  if ((((*(uint *)(param_1 + 0x158) & 4) != 0) && (param_2 != (LPCWSTR)0x0)) &&
     (iVar1 = StrCmpW(param_2,L"DevIV Package"), iVar1 == 0)) {
    (**(code **)(*(int *)(param_1 + -4) + 4))();
  }
  FUN_40522fa8();
  return;
}



/* 40519bf0 FUN_40519bf0 */

/* Boundary evidence: original MIPS .pdata 40519bf0..40519c7b. Semantic name remains unreviewed. */

void FUN_40519bf0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_1[0x56] & 1U) == 0) {
    FUN_40519354((int)(param_1 + -1));
  }
  param_1[0x57] = param_3;
  FUN_40518ac8(param_1,param_2,param_3,param_4);
  param_1[0x57] = 0;
  return;
}



/* 40519c7c FUN_40519c7c */

/* Boundary evidence: original MIPS .pdata 40519c7c..40519ce7. Semantic name remains unreviewed. */

void FUN_40519c7c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x170);
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 0xa0);
    if (piVar2 == (int *)0x0) {
      *(undefined4 *)(param_1 + 0x164) = *(undefined4 *)(iVar1 + 0x368);
      *(undefined4 *)(param_1 + 0x168) = *(undefined4 *)(iVar1 + 0x36c);
    }
    else {
      (**(code **)(*piVar2 + 0x2c))(piVar2,param_1 + 0x164);
    }
  }
  return;
}



/* 40519ce8 FUN_40519ce8 */

/* Boundary evidence: original MIPS .pdata 40519ce8..40519d57. Semantic name remains unreviewed. */

void FUN_40519ce8(int param_1,undefined4 param_2)

{
  int iVar1;
  int *local_10 [2];
  
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x150))
                    (*(undefined4 **)(param_1 + 0x150),&DAT_40512e84,local_10);
  if (-1 < iVar1) {
    (**(code **)(*local_10[0] + 0x10))(local_10[0],4,param_2);
    (**(code **)(*local_10[0] + 8))();
  }
  return;
}



/* 40519d58 FUN_40519d58 */

/* Boundary evidence: original MIPS .pdata 40519d58..40519d8f. Semantic name remains unreviewed. */

undefined4 FUN_40519d58(int param_1)

{
  FUN_40519354(param_1 + -0xb8);
  FUN_40519ce8(param_1 + -0xb8,1);
  return 0;
}



/* 40519d90 FUN_40519d90 */

/* Boundary evidence: original MIPS .pdata 40519d90..40519e17. Semantic name remains unreviewed. */

void FUN_40519d90(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined2 local_28 [4];
  undefined4 local_20;
  
  memset(local_28,0,0x10);
  local_28[0] = 0x13;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_3,local_28,param_2);
  if (-1 < iVar1) {
    *param_4 = local_20;
  }
  return;
}



/* 40519e18 FUN_40519e18 */

/* Boundary evidence: original MIPS .pdata 40519e18..40519eab. Semantic name remains unreviewed. */

void FUN_40519e18(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined2 local_28 [4];
  short local_20;
  
  memset(local_28,0,0x10);
  local_28[0] = 0xb;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_3,local_28,param_2);
  if (-1 < iVar1) {
    *param_4 = (uint)(local_20 != 0);
  }
  return;
}



/* 40519eac FUN_40519eac */

/* Boundary evidence: original MIPS .pdata 40519eac..40519f53. Semantic name remains unreviewed. */

int FUN_40519eac(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined2 local_28 [4];
  BSTR local_20;
  
  memset(local_28,0,0x10);
  local_28[0] = 8;
  local_20 = SysAllocStringLen((OLECHAR *)0x0,1);
  if (local_20 == (BSTR)0x0) {
    iVar1 = -0x7ff8fff2;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_3,local_28,param_2);
    if (-1 < iVar1) {
      *param_4 = local_20;
    }
  }
  return iVar1;
}



/* 40519f54 FUN_40519f54 */

/* Boundary evidence: original MIPS .pdata 40519f54..4051a34f. Semantic name remains unreviewed. */

int FUN_40519f54(int param_1,int *param_2,undefined4 param_3)

{
  wchar_t **ppwVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  short local_78 [2];
  BSTR local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  wchar_t *local_60 [3];
  int *local_54;
  wchar_t *local_50;
  undefined4 *local_4c;
  wchar_t *local_48;
  int *local_44;
  wchar_t *local_40;
  int *local_3c;
  wchar_t *local_38;
  int *local_34;
  wchar_t *local_30;
  int *local_2c;
  
  local_70 = 0;
  local_6c = 0;
  uVar7 = 1;
  local_64 = 0;
  local_68 = 0;
  if ((*(uint *)(param_1 + 0xa0) & 1) != 0) {
    return -0x7fffbffb;
  }
  iVar6 = param_1 + -0xbc;
  FUN_40519354(iVar6);
  local_60[0] = L"Height";
  local_60[1] = (wchar_t *)(param_1 + -0x6c);
  local_60[2] = L"Width";
  local_50 = L"ViewMode";
  local_48 = L"Offline";
  local_40 = L"Silent";
  local_44 = &local_70;
  local_3c = &local_6c;
  local_54 = (int *)(param_1 + -0x70);
  local_4c = (undefined4 *)(param_1 + 0xa8);
  ppwVar1 = local_60;
  local_38 = L"RegisterAsBrowser";
  iVar3 = 7;
  local_34 = &local_64;
  local_30 = L"RegisterAsDropTarget";
  local_2c = &local_68;
  do {
    FUN_40519d90(param_2,param_3,*ppwVar1,(undefined4 *)ppwVar1[1]);
    iVar3 = iVar3 + -1;
    ppwVar1 = ppwVar1 + 2;
  } while (iVar3 != 0);
  iVar3 = FUN_40530058(iVar6,0xffffea83,0xb,local_78);
  uVar4 = 0xffffffff;
  if (iVar3 == 0) {
    iVar3 = -1;
    if (local_70 == 0) {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = (int)local_78[0];
  }
  piVar2 = (int *)(param_1 + 0x6c);
  (**(code **)(*piVar2 + 0xe8))(piVar2,iVar3);
  iVar3 = FUN_40530058(iVar6,0xffffea82,0xb,local_78);
  if (iVar3 == 0) {
    iVar3 = -1;
    if (local_6c == 0) {
      iVar3 = 0;
    }
  }
  else {
    iVar3 = (int)local_78[0];
  }
  (**(code **)(*piVar2 + 0xf0))(piVar2,iVar3);
  if (local_68 == 0) {
    uVar4 = 0;
  }
  (**(code **)(*piVar2 + 0x100))(piVar2,uVar4);
  *(uint *)(param_1 + 0xa0) =
       ((uint)(local_64 != 0) << 1 ^ *(uint *)(param_1 + 0xa0)) & 2 ^ *(uint *)(param_1 + 0xa0);
  iVar3 = FUN_40519d90(param_2,param_3,L"ExtentX",&local_74);
  if (-1 < iVar3) {
    *(BSTR *)(param_1 + -0x68) = local_74;
    iVar3 = FUN_40519d90(param_2,param_3,L"ExtentY",&local_74);
    if (-1 < iVar3) {
      *(BSTR *)(param_1 + -100) = local_74;
      goto LAB_4051a1c0;
    }
  }
  *(int *)(param_1 + -0x68) = *(int *)(param_1 + -0x70);
  *(undefined4 *)(param_1 + -100) = *(undefined4 *)(param_1 + -0x6c);
  FUN_40517324((int *)(param_1 + -0x68));
LAB_4051a1c0:
  iVar3 = 0;
  uVar5 = 0;
  do {
    iVar6 = FUN_40519e18(param_2,param_3,*(undefined4 *)((int)&PTR_u_AutoArrange_40511688 + uVar5),
                         (uint *)&local_74);
    if (-1 < iVar6) {
      if (local_74 == (BSTR)0x0) {
        *(uint *)(param_1 + 0xac) =
             ~*(uint *)((int)&DAT_4051168c + uVar5) & *(uint *)(param_1 + 0xac);
      }
      else {
        *(uint *)(param_1 + 0xac) =
             *(uint *)((int)&DAT_4051168c + uVar5) | *(uint *)(param_1 + 0xac);
      }
    }
    uVar5 = uVar5 + 8;
  } while (uVar5 < 0x48);
  iVar6 = *(int *)(param_1 + 0xb4);
  if (iVar6 != 0) {
    *(undefined4 *)(iVar6 + 0x368) = *(undefined4 *)(param_1 + 0xa8);
    *(undefined4 *)(iVar6 + 0x36c) = *(undefined4 *)(param_1 + 0xac);
    iVar6 = FUN_40519eac(param_2,param_3,L"Location",&local_74);
    if (-1 < iVar6) {
      iVar3 = FUN_4052e8b0(&local_74);
      if (-1 < iVar3) {
        *(uint *)(*(int *)(param_1 + 0xb4) + 0x13c) =
             *(uint *)(*(int *)(param_1 + 0xb4) + 0x13c) | 0x20;
        iVar6 = (**(code **)(*piVar2 + 0x2c))(piVar2,local_74,0,0,0,0);
        uVar7 = (uint)(iVar6 < 0);
        *(uint *)(*(int *)(param_1 + 0xb4) + 0x13c) =
             *(uint *)(*(int *)(param_1 + 0xb4) + 0x13c) & 0xffffffdf;
      }
      SysFreeString(local_74);
    }
  }
  FUN_40519ce8(param_1 + -0xbc,uVar7);
  return iVar3;
}



/* 4051a350 FUN_4051a350 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4051a350..4051a643. Semantic name remains unreviewed. */

int FUN_4051a350(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  wchar_t **ppwVar4;
  int iVar5;
  int iVar6;
  short local_90 [2];
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80 [2];
  undefined1 local_78 [16];
  wchar_t *local_68 [3];
  int local_5c;
  wchar_t *local_58;
  int local_54;
  wchar_t *local_50;
  uint *local_4c;
  wchar_t *local_48;
  uint *local_44;
  wchar_t *local_40;
  uint *local_3c;
  wchar_t *local_38;
  uint *local_34;
  wchar_t *local_30;
  int local_2c;
  wchar_t *local_28;
  int local_24;
  
  if ((*(uint *)(param_1 + 0xa0) & 1) == 0) {
    FUN_40519354(param_1 + -0xbc);
  }
  piVar2 = (int *)(param_1 + 0x6c);
  (**(code **)(*piVar2 + 0xe4))(piVar2,local_90);
  local_8c = (uint)(local_90[0] != 0);
  (**(code **)(*piVar2 + 0xec))(piVar2,local_90);
  local_88 = (uint)(local_90[0] != 0);
  (**(code **)(*piVar2 + 0xfc))(piVar2,local_90);
  local_80[0] = (uint)(local_90[0] != 0);
  local_84 = (uint)((*(uint *)(param_1 + 0xa0) & 2) != 0);
  FUN_40519c7c(param_1 + -0xbc);
  local_68[0] = L"ExtentX";
  local_68[2] = L"ExtentY";
  local_68[1] = (wchar_t *)(param_1 + -0x68);
  local_5c = param_1 + -100;
  local_58 = L"ViewMode";
  local_50 = L"Offline";
  local_54 = param_1 + 0xa8;
  local_4c = &local_8c;
  local_48 = L"Silent";
  local_40 = L"RegisterAsBrowser";
  local_3c = &local_84;
  local_44 = &local_88;
  local_38 = L"RegisterAsDropTarget";
  local_30 = L"Height";
  local_34 = local_80;
  local_2c = param_1 + -0x6c;
  local_24 = param_1 + -0x70;
  local_28 = L"Width";
  memset((_union_2683 *)local_78,0,0x10);
  local_78._0_2_ = 3;
  iVar6 = 9;
  if (*(int *)(*(int *)(param_1 + -0x60) + 0x14) != 1) {
    iVar6 = 7;
  }
  iVar5 = 0;
  if (iVar6 != 0) {
    ppwVar4 = local_68;
    do {
      local_78._8_4_ = *(undefined4 *)ppwVar4[1];
      iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*ppwVar4,(_union_2683 *)local_78);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar5 = iVar5 + 1;
      ppwVar4 = ppwVar4 + 2;
    } while (iVar5 < iVar6);
  }
  local_78._0_2_ = 0xb;
  uVar3 = 0;
  do {
    if ((*(uint *)((int)&DAT_4051168c + uVar3) & *(uint *)(param_1 + 0xac)) == 0) {
      local_78._8_4_ = (uint)(ushort)local_78._10_2_ << 0x10;
    }
    else {
      local_78._8_2_ = 0xffff;
    }
    (**(code **)(*param_2 + 0x10))
              (param_2,*(undefined4 *)((int)&PTR_u_AutoArrange_40511688 + uVar3),
               (_union_2683 *)local_78);
    uVar3 = uVar3 + 8;
  } while (uVar3 < 0x48);
  local_78._0_2_ = 8;
  iVar6 = (**(code **)(*piVar2 + 0x78))(piVar2,&(((_union_2683 *)local_78)->n2).n3);
  if (-1 < iVar6) {
    iVar6 = (**(code **)(*param_2 + 0x10))(param_2,L"Location",(_union_2683 *)local_78);
    FUN_4052eac4((VARIANTARG *)&((_union_2683 *)local_78)->n2);
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  return 0;
}



/* 4051a644 FUN_4051a644 */

/* Boundary evidence: original MIPS .pdata 4051a644..4051a6c3. Semantic name remains unreviewed. */

undefined4 FUN_4051a644(int param_1,OLECHAR *param_2)

{
  BSTR bstrString;
  undefined4 uVar1;
  
  uVar1 = 0x8007000e;
  bstrString = SysAllocString(param_2);
  if (bstrString != (BSTR)0x0) {
    uVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x2c))
                      ((int *)(param_1 + -0xc),bstrString,0,0,0,0);
    SysFreeString(bstrString);
  }
  return uVar1;
}



/* 4051a6c4 FUN_4051a6c4 */

/* Boundary evidence: original MIPS .pdata 4051a6c4..4051a74b. Semantic name remains unreviewed. */

void FUN_4051a6c4(int param_1,IID *param_2,void **param_3)

{
  HRESULT HVar1;
  int iVar2;
  
  HVar1 = QISearch((void *)(param_1 + -0x1c),(LPCQITAB)&PTR_DAT_40511c74,param_2,param_3);
  if ((HVar1 < 0) && (iVar2 = FUN_4052fc04(param_1,param_2,param_3), iVar2 < 0)) {
    (**(code **)**(undefined4 **)(param_1 + 0x134))
              (*(undefined4 **)(param_1 + 0x134),param_2,param_3);
  }
  return;
}



/* 4051a74c FUN_4051a74c */

/* Boundary evidence: original MIPS .pdata 4051a74c..4051a787. Semantic name remains unreviewed. */

undefined4 FUN_4051a74c(int param_1)

{
  if (*(int *)(param_1 + 0x15c) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x15c) + 0x14) + 0xa8))();
  }
  return 0;
}



/* 4051a788 FUN_4051a788 */

/* Boundary evidence: original MIPS .pdata 4051a788..4051a833. Semantic name remains unreviewed. */

int FUN_4051a788(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4051788c(param_1,param_2,param_3);
  if (-1 < iVar1) {
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else if (param_3 == 1) {
      uVar3 = 3;
    }
    else {
      uVar3 = 2;
      if (param_3 != 2) {
        return -0x7ff8ffa9;
      }
    }
    if (param_1[0x5c] != 0) {
      piVar2 = (int *)(param_1[0x5c] + 0x14);
      (**(code **)(*piVar2 + 0x128))(piVar2,uVar3);
    }
  }
  return iVar1;
}



/* 4051a834 FUN_4051a834 */

/* Boundary evidence: original MIPS .pdata 4051a834..4051a937. Semantic name remains unreviewed. */

void FUN_4051a834(int param_1)

{
  HRESULT HVar1;
  int iVar2;
  int *piVar3;
  int *local_18 [2];
  
  FUN_40518c08(param_1);
  if (*(IUnknown **)(param_1 + 0x88) != (IUnknown *)0x0) {
    HVar1 = IUnknown_QueryService
                      (*(IUnknown **)(param_1 + 0x88),(GUID *)&DAT_405164bc,(IID *)&DAT_405163fc,
                       (void **)(param_1 + 0x174));
    if (-1 < HVar1) {
      piVar3 = *(void **)(param_1 + 0x174);
      (**(code **)(*piVar3 + 0x14))(piVar3,param_1 + 0xcc);
    }
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x88))
                      (*(undefined4 **)(param_1 + 0x88),&DAT_4051646c,param_1 + 0x178);
    if (((iVar2 < 0) && (piVar3 = *(int **)(param_1 + 0x34), piVar3 != (int *)0x0)) &&
       (iVar2 = (**(code **)(*piVar3 + 0x14))(piVar3,local_18), -1 < iVar2)) {
      (**(code **)*local_18[0])(local_18[0],&DAT_4051646c,param_1 + 0x178);
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return;
}



/* 4051a938 FUN_4051a938 */

/* Boundary evidence: original MIPS .pdata 4051a938..4051a9ab. Semantic name remains unreviewed. */

void FUN_4051a938(int param_1)

{
  int *piVar1;
  
  piVar1 = *(void **)(param_1 + 0x174);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,param_1 + 0xcc);
    IUnknown_AtomicRelease((void **)(param_1 + 0x174));
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0x178));
  FUN_40518cd8(param_1);
  return;
}



/* 4051a9ac FUN_4051a9ac */

/* Boundary evidence: original MIPS .pdata 4051a9ac..4051aa0f. Semantic name remains unreviewed. */

undefined4 FUN_4051a9ac(int *param_1)

{
  int iVar1;
  int *local_10;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = (**(code **)(*param_1 + 0x48))(param_1,&local_10);
  if (-1 < iVar1) {
    (**(code **)*local_10)(local_10,&UNK_405164cc,&local_c);
    (**(code **)(*local_10 + 8))();
  }
  return local_c;
}



/* 4051aa10 FUN_4051aa10 */

/* Boundary evidence: original MIPS .pdata 4051aa10..4051aa87. Semantic name remains unreviewed. */

undefined4 FUN_4051aa10(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004001;
  piVar1 = (int *)FUN_4051a9ac(*(int **)(param_1 + 0x94));
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



/* 4051aa88 FUN_4051aa88 */

/* Boundary evidence: original MIPS .pdata 4051aa88..4051aaff. Semantic name remains unreviewed. */

undefined4 FUN_4051aa88(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80004001;
  piVar1 = (int *)FUN_4051a9ac(*(int **)(param_1 + 0x94));
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



/* 4051ab00 FUN_4051ab00 */

/* Boundary evidence: original MIPS .pdata 4051ab00..4051abfb. Semantic name remains unreviewed. */

undefined4 FUN_4051ab00(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  short local_20 [4];
  
  if ((*(uint *)(param_1 + 0x9c) & 1) == 0) {
    FUN_40519354(param_1 + -0xc0);
  }
  FUN_4052fd28(param_1,param_2);
  if (((param_2 == -0x157d) || (param_2 == -0x157e)) &&
     (iVar1 = FUN_40530058(param_1 + -0xc0,param_2,0xb,local_20), iVar1 != 0)) {
    if (param_2 == -0x157d) {
      pcVar3 = *(code **)(*(int *)(param_1 + 0x68) + 0xe8);
    }
    else {
      if (param_2 != -0x157e) goto LAB_4051aba4;
      pcVar3 = *(code **)(*(int *)(param_1 + 0x68) + 0xf0);
    }
    (*pcVar3)(param_1 + 0x68,(int)local_20[0]);
  }
LAB_4051aba4:
  piVar2 = (int *)FUN_4051a9ac(*(int **)(param_1 + 0x94));
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x14))(piVar2,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return 0;
}



/* 4051abfc FUN_4051abfc */

/* Boundary evidence: original MIPS .pdata 4051abfc..4051acc7. Semantic name remains unreviewed. */

undefined4 FUN_4051abfc(int param_1,uint param_2)

{
  int *piVar1;
  
  FUN_4052fd48(param_1,param_2);
  piVar1 = (int *)FUN_4051a9ac(*(int **)(param_1 + 0x94));
  if (piVar1 == (int *)0x0) {
    if (param_2 != 0) {
      *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
      return 0;
    }
  }
  else if ((param_2 != 0) || (*(int *)(param_1 + 0xd4) == 0)) {
    (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
    goto LAB_4051ac94;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + -1;
  }
LAB_4051ac94:
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



/* 4051acc8 FUN_4051acc8 */

/* Boundary evidence: original MIPS .pdata 4051acc8..4051ad6b. Semantic name remains unreviewed. */

void FUN_4051acc8(int param_1)

{
  int *piVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 1;
  FUN_4051828c(param_1,4);
  if ((*(int *)(param_1 + 0x194) != 0) &&
     (piVar1 = (int *)FUN_4051a9ac(*(int **)(param_1 + 0x154)), piVar1 != (int *)0x0)) {
    iVar2 = *(int *)(param_1 + 0x194);
    while (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x18))(piVar1,1);
      iVar2 = *(int *)(param_1 + 0x194) + -1;
      *(int *)(param_1 + 0x194) = iVar2;
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 4051ad6c FUN_4051ad6c */

/* Boundary evidence: original MIPS .pdata 4051ad6c..4051adc3. Semantic name remains unreviewed. */

undefined4 FUN_4051ad6c(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x38) == 0) || (*(int *)(*(int *)(param_1 + 0x38) + 0x98) == 0)) {
    uVar1 = 0x80040104;
  }
  else {
    uVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x38) + 0x98) + 0xc))();
  }
  return uVar1;
}



/* 4051adc4 FUN_4051adc4 */

/* Boundary evidence: original MIPS .pdata 4051adc4..4051b03b. Semantic name remains unreviewed. */

int FUN_4051adc4(int param_1,void *param_2,int param_3,undefined4 param_4,short *param_5,
                undefined4 param_6)

{
  void *pvVar1;
  int iVar2;
  ushort *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_1070 [4168];
  uint local_28;
  
  local_28 = DAT_40544354;
  iVar6 = -0x7ffbfefc;
  if (*(int *)(param_1 + 0x38) != 0) {
    if (param_2 == (void *)0x0) {
      if (param_3 == 0x17) {
        puVar3 = *(ushort **)(*(int *)(param_1 + 0x38) + 0xb0);
        if (puVar3 == (ushort *)0x0) {
          pvVar1 = (void *)0x0;
        }
        else {
          pvVar1 = FUN_4052d908(puVar3);
        }
        FUN_40529eec(*(int *)(param_1 + 0x38),0);
        if (((*(int *)(*(int *)(param_1 + 0x38) + 0x9c) == 0) &&
            (((param_5 == (short *)0x0 || (*param_5 != 0xb)) || (param_5[4] == -1)))) &&
           (iVar6 = FUN_40516aac(), -1 < iVar6)) {
          (**(code **)(**(int **)(param_1 + 0x38) + 0x30))
                    (*(int **)(param_1 + 0x38),auStack_1070,pvVar1);
        }
        if (pvVar1 != (void *)0x0) {
          FUN_40537f64((int)pvVar1);
        }
      }
      else if (((param_3 == 0x24) && (param_5 != (short *)0x0)) && (*param_5 == 3)) {
        uVar5 = *(uint *)(*(int *)(param_1 + 0x38) + 0x13c);
        *(uint *)(*(int *)(param_1 + 0x38) + 0x13c) =
             ((uint)(*(int *)(param_5 + 4) != 0) << 6 ^ uVar5) & 0x40 ^ uVar5;
      }
      iVar6 = 0;
    }
    if ((*(int *)(param_1 + 0x38) != 0) && (*(int *)(*(int *)(param_1 + 0x38) + 0x98) != 0)) {
      piVar4 = *(int **)(*(int *)(param_1 + 0x38) + 0x98);
      iVar6 = (**(code **)(*piVar4 + 0x10))(piVar4,param_2,param_3,param_4,param_5,param_6);
    }
    if ((((iVar6 < 0) && (param_2 != (void *)0x0)) &&
        (iVar2 = memcmp(&DAT_405163ec,param_2,0x10), iVar2 == 0)) &&
       ((param_3 == 0x5b && (*(int *)(param_1 + 0x18) != 0)))) {
      iVar6 = IUnknown_Exec(*(int *)(param_1 + 0x18),param_2,0x5b,param_4,param_5,param_6);
    }
  }
  FUN_40542538(local_28);
  return iVar6;
}



/* 4051b03c FUN_4051b03c */

/* Boundary evidence: original MIPS .pdata 4051b03c..4051b08b. Semantic name remains unreviewed. */

int * FUN_4051b03c(int param_1,undefined4 *param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    *param_2 = 0;
    piVar1 = (int *)0x80004005;
  }
  else {
    piVar1 = FUN_40526854((int *)(*(int *)(param_1 + 0x2c) + 0x18),&DAT_405164bc,&DAT_405164dc,
                          param_2);
  }
  return piVar1;
}



/* 4051b08c FUN_4051b08c */

/* Boundary evidence: original MIPS .pdata 4051b08c..4051b163. Semantic name remains unreviewed. */

int FUN_4051b08c(int param_1,int param_2,void *param_3)

{
  int iVar1;
  
  if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_4051643c,0x10), iVar1 != 0)) {
    iVar1 = memcmp(param_3,&DAT_405162bc,0x10);
    if (iVar1 == 0) goto LAB_4051b0fc;
    iVar1 = memcmp(param_3,&DAT_405164fc,0x10);
    if (iVar1 != 0) {
      iVar1 = memcmp(param_3,&DAT_405164ec,0x10);
      if (iVar1 == 0) {
        return param_1 + 0x44;
      }
      return 0;
    }
  }
  else if (*(int *)(*(int *)(param_1 + -0x70) + 0x14) != 1) {
LAB_4051b0fc:
    return param_1 + 0x2c;
  }
  return param_1 + 0xb0;
}



/* 4051b164 FUN_4051b164 */

/* Boundary evidence: original MIPS .pdata 4051b164..4051b197. Semantic name remains unreviewed. */

void FUN_4051b164(int param_1,undefined4 *param_2)

{
  FUN_40538514(param_2,3,param_1 + 0x2c,param_1 + 0xb0);
  return;
}



/* 4051b198 FUN_4051b198 */

/* Boundary evidence: original MIPS .pdata 4051b198..4051b32f. Semantic name remains unreviewed. */

HRESULT FUN_4051b198(int param_1,int param_2,void *param_3,uint param_4,ushort param_5,
                    DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  HRESULT HVar1;
  int iVar2;
  int *local_28 [2];
  
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) | 0x800;
  if ((param_2 == -0x158a) || (param_2 == -0x1587)) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x90) + 0x48))(*(int **)(param_1 + 0x90),local_28);
    if (-1 < iVar2) {
      HVar1 = (**(code **)(*local_28[0] + 0x18))
                        (local_28[0],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9
                        );
      (**(code **)(*local_28[0] + 8))();
      goto LAB_4051b2f8;
    }
  }
  else if (((param_2 == -0x20d) && (param_7 != (VARIANT *)0x0)) && ((param_5 & 2) != 0)) {
    memset(param_7,0,0x10);
    (param_7->n1).n2.vt = 3;
    HVar1 = (**(code **)(*(int *)(param_1 + 100) + 0xe0))
                      ((int *)(param_1 + 100),(undefined1 *)((int)&param_7->n1 + 8));
    goto LAB_4051b2f8;
  }
  HVar1 = FUN_4052f890((undefined4 *)(param_1 + 0xc),param_2,param_3,param_4,param_5,param_6,param_7
                       ,param_8,param_9);
LAB_4051b2f8:
  *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) & 0xfffff7ff;
  return HVar1;
}



/* 4051b330 FUN_4051b330 */

/* Boundary evidence: original MIPS .pdata 4051b330..4051b413. Semantic name remains unreviewed. */

undefined4 FUN_4051b330(int param_1,void *param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint local_20;
  BSTR local_1c;
  int *local_18;
  undefined4 local_14;
  
  uVar1 = FUN_40531580(param_1,param_2,param_3,param_4);
  iVar2 = FUN_40538640(*(IUnknown **)(param_1 + -0x108),&local_18);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_18 + 0xa0))(local_18,&local_1c);
    if (-1 < iVar2) {
      local_20 = 3;
      local_14 = 0;
      iVar2 = ZoneCheckUrlExW(local_1c,&local_20,4,&local_14,4,0x1206,0,0);
      if ((iVar2 < 0) || ((local_20 & 0xf) != 0)) {
        uVar1 = 0x80070005;
      }
      SysFreeString(local_1c);
    }
    (**(code **)(*local_18 + 8))();
  }
  return uVar1;
}



/* 4051b414 FUN_4051b414 */

/* Boundary evidence: original MIPS .pdata 4051b414..4051b463. Semantic name remains unreviewed. */

undefined4 FUN_4051b414(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x1c))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b464 FUN_4051b464 */

/* Boundary evidence: original MIPS .pdata 4051b464..4051b4b3. Semantic name remains unreviewed. */

undefined4 FUN_4051b464(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x20))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b4b4 FUN_4051b4b4 */

/* Boundary evidence: original MIPS .pdata 4051b4b4..4051b503. Semantic name remains unreviewed. */

undefined4 FUN_4051b4b4(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x24))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b504 FUN_4051b504 */

/* Boundary evidence: original MIPS .pdata 4051b504..4051b553. Semantic name remains unreviewed. */

undefined4 FUN_4051b504(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x28))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b554 FUN_4051b554 */

/* Boundary evidence: original MIPS .pdata 4051b554..4051b5a3. Semantic name remains unreviewed. */

undefined4 FUN_4051b554(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x30))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b5a4 FUN_4051b5a4 */

/* Boundary evidence: original MIPS .pdata 4051b5a4..4051b5ff. Semantic name remains unreviewed. */

undefined4 FUN_4051b5a4(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x34))(*(int **)(param_1 + 0x2c),param_2);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b600 FUN_4051b600 */

/* Boundary evidence: original MIPS .pdata 4051b600..4051b64f. Semantic name remains unreviewed. */

undefined4 FUN_4051b600(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x38))();
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051b650 FUN_4051b650 */

/* Boundary evidence: original MIPS .pdata 4051b650..4051b677. Semantic name remains unreviewed. */

void FUN_4051b650(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x50))();
  return;
}



/* 4051b678 FUN_4051b678 */

/* Boundary evidence: original MIPS .pdata 4051b678..4051b69f. Semantic name remains unreviewed. */

void FUN_4051b678(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x74))();
  return;
}



/* 4051b6a0 FUN_4051b6a0 */

/* Boundary evidence: original MIPS .pdata 4051b6a0..4051b6c7. Semantic name remains unreviewed. */

void FUN_4051b6a0(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x78))();
  return;
}



/* 4051b6c8 FUN_4051b6c8 */

/* Boundary evidence: original MIPS .pdata 4051b6c8..4051b6ef. Semantic name remains unreviewed. */

void FUN_4051b6c8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x7c))();
  return;
}



/* 4051b6f0 FUN_4051b6f0 */

/* Boundary evidence: original MIPS .pdata 4051b6f0..4051b71f. Semantic name remains unreviewed. */

void FUN_4051b6f0(int param_1,undefined4 param_2)

{
  (*(code *)**(undefined4 **)(param_1 + -0x128))
            ((undefined4 *)(param_1 + -0x128),&DAT_4051643c,param_2);
  return;
}



/* 4051b720 FUN_4051b720 */

/* Boundary evidence: original MIPS .pdata 4051b720..4051b7cb. Semantic name remains unreviewed. */

undefined4 FUN_4051b720(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *local_18 [2];
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  piVar2 = *(int **)(param_1 + -0xf4);
  if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,local_18), -1 < iVar1)
     ) {
    iVar1 = (**(code **)*local_18[0])(local_18[0],&DAT_4051643c,param_2);
    if ((-1 < iVar1) && (*(int *)(param_1 + 0x18) != 0)) {
      FUN_40531484(param_2);
    }
    (**(code **)(*local_18[0] + 8))();
  }
  return 0;
}



/* 4051b7cc FUN_4051b7cc */

/* Boundary evidence: original MIPS .pdata 4051b7cc..4051b7ef. Semantic name remains unreviewed. */

void FUN_4051b7cc(int *param_1)

{
  (**(code **)(*param_1 + 0x40))();
  return;
}



/* 4051b7f0 FUN_4051b7f0 */

/* Boundary evidence: original MIPS .pdata 4051b7f0..4051b85f. Semantic name remains unreviewed. */

undefined4 FUN_4051b7f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x48))(*(int **)(param_1 + 0x2c),param_2);
  if (iVar1 < 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
  }
  else if (*(int *)(param_1 + 0x18) != 0) {
    FUN_40531484(param_2);
  }
  return 0;
}



/* 4051b894 FUN_4051b894 */

/* Boundary evidence: original MIPS .pdata 4051b894..4051b947. Semantic name remains unreviewed. */

undefined4 FUN_4051b894(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  IUnknown_CPContainerInvokeParam
            (*(undefined4 *)(param_1 + 0x30),&DAT_405162bc,0x108,&local_20,1,3,param_2);
  if (*(int *)(param_1 + -0xa0) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    local_14 = *(undefined4 *)(param_1 + -0xb4);
    local_1c = *(undefined4 *)(param_1 + -0xbc);
    local_18 = *(undefined4 *)(param_1 + -0xb8);
    local_20 = param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + -0xa0) + 0x38))(*(int **)(param_1 + -0xa0),&local_20);
  }
  return uVar1;
}



/* 4051b958 FUN_4051b958 */

/* Boundary evidence: original MIPS .pdata 4051b958..4051ba0b. Semantic name remains unreviewed. */

undefined4 FUN_4051b958(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  IUnknown_CPContainerInvokeParam
            (*(undefined4 *)(param_1 + 0x30),&DAT_405162bc,0x109,&local_20,1,3,param_2);
  if (*(int *)(param_1 + -0xa0) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    local_20 = *(undefined4 *)(param_1 + -0xc0);
    local_14 = *(undefined4 *)(param_1 + -0xb4);
    local_18 = *(undefined4 *)(param_1 + -0xb8);
    local_1c = param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + -0xa0) + 0x38))(*(int **)(param_1 + -0xa0),&local_20);
  }
  return uVar1;
}



/* 4051ba24 FUN_4051ba24 */

/* Boundary evidence: original MIPS .pdata 4051ba24..4051badb. Semantic name remains unreviewed. */

undefined4 FUN_4051ba24(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  IUnknown_CPContainerInvokeParam
            (*(undefined4 *)(param_1 + 0x30),&DAT_405162bc,0x10a,&local_20,1,3,param_2);
  if (*(int *)(param_1 + -0xa0) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    local_20 = *(int *)(param_1 + -0xc0);
    local_1c = *(undefined4 *)(param_1 + -0xbc);
    local_14 = *(undefined4 *)(param_1 + -0xb4);
    local_18 = local_20 + param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + -0xa0) + 0x38))(*(int **)(param_1 + -0xa0),&local_20);
  }
  return uVar1;
}



/* 4051baf4 FUN_4051baf4 */

/* Boundary evidence: original MIPS .pdata 4051baf4..4051bbab. Semantic name remains unreviewed. */

undefined4 FUN_4051baf4(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  
  IUnknown_CPContainerInvokeParam
            (*(undefined4 *)(param_1 + 0x30),&DAT_405162bc,0x10b,&local_20,1,3,param_2);
  if (*(int *)(param_1 + -0xa0) == 0) {
    uVar1 = 0x8000ffff;
  }
  else {
    local_20 = *(undefined4 *)(param_1 + -0xc0);
    local_1c = *(int *)(param_1 + -0xbc);
    local_18 = *(undefined4 *)(param_1 + -0xb8);
    local_14 = local_1c + param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + -0xa0) + 0x38))(*(int **)(param_1 + -0xa0),&local_20);
  }
  return uVar1;
}



/* 4051bbac FUN_4051bbac */

/* Boundary evidence: original MIPS .pdata 4051bbac..4051bc37. Semantic name remains unreviewed. */

undefined4
FUN_4051bbac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x88))
                      (*(int **)(param_1 + 0x2c),param_2,param_3,param_4,param_5,param_6);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051bc38 FUN_4051bc38 */

/* Boundary evidence: original MIPS .pdata 4051bc38..4051bca3. Semantic name remains unreviewed. */

undefined4 FUN_4051bc38(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x8c))
                      (*(int **)(param_1 + 0x2c),param_2,param_3);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051bca4 FUN_4051bca4 */

/* Boundary evidence: original MIPS .pdata 4051bca4..4051bccb. Semantic name remains unreviewed. */

void FUN_4051bca4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x98))();
  return;
}



/* 4051bccc FUN_4051bccc */

/* Boundary evidence: original MIPS .pdata 4051bccc..4051bcf3. Semantic name remains unreviewed. */

void FUN_4051bccc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x9c))();
  return;
}



/* 4051bcf4 FUN_4051bcf4 */

/* Boundary evidence: original MIPS .pdata 4051bcf4..4051bd87. Semantic name remains unreviewed. */

undefined4 FUN_4051bcf4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [32];
  
  local_38 = *param_2;
  local_34 = *param_3;
  IUnknown_CPContainerInvokeParam
            (*(undefined4 *)(param_1 + 0x30),&DAT_405162bc,0x10c,auStack_30,2,0x4003,&local_38,
             0x4003,&local_34);
  *param_2 = local_38;
  *param_3 = local_34;
  return 0;
}



/* 4051bd88 FUN_4051bd88 */

/* Boundary evidence: original MIPS .pdata 4051bd88..4051bdc7. Semantic name remains unreviewed. */

undefined4 FUN_4051bd88(undefined4 param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  undefined4 uVar2;
  
  pOVar1 = FUN_4052d808(0x4f1);
  *param_2 = pOVar1;
  if (pOVar1 == (BSTR)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4051bde8 FUN_4051bde8 */

/* Boundary evidence: original MIPS .pdata 4051bde8..4051be37. Semantic name remains unreviewed. */

undefined4 FUN_4051bde8(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 != 0) << 7 ^ *(uint *)(param_1 + 0x34)) & 0x80 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x102,param_2);
  return 0;
}



/* 4051be58 FUN_4051be58 */

/* Boundary evidence: original MIPS .pdata 4051be58..4051bea7. Semantic name remains unreviewed. */

undefined4 FUN_4051be58(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 != 0) << 3 ^ *(uint *)(param_1 + 0x34)) & 8 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0xfe,param_2);
  return 0;
}



/* 4051bec8 FUN_4051bec8 */

/* Boundary evidence: original MIPS .pdata 4051bec8..4051bf17. Semantic name remains unreviewed. */

undefined4 FUN_4051bec8(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 == 0) << 6 ^ *(uint *)(param_1 + 0x34)) & 0x40 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x101,param_2);
  return 0;
}



/* 4051bf48 FUN_4051bf48 */

/* Boundary evidence: original MIPS .pdata 4051bf48..4051bf9b. Semantic name remains unreviewed. */

undefined4 FUN_4051bf48(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 == 0) << 5 ^ *(uint *)(param_1 + 0x34)) & 0x20 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0xff,(int)(short)param_2);
  return 0;
}



/* 4051bfbc FUN_4051bfbc */

/* Boundary evidence: original MIPS .pdata 4051bfbc..4051c00b. Semantic name remains unreviewed. */

undefined4 FUN_4051bfbc(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 == 0) << 4 ^ *(uint *)(param_1 + 0x34)) & 0x10 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x100,param_2);
  return 0;
}



/* 4051c02c FUN_4051c02c */

/* Boundary evidence: original MIPS .pdata 4051c02c..4051c07b. Semantic name remains unreviewed. */

undefined4 FUN_4051c02c(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 == 0) << 9 ^ *(uint *)(param_1 + 0x34)) & 0x200 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x105,param_2);
  return 0;
}



/* 4051c07c FUN_4051c07c */

/* Boundary evidence: original MIPS .pdata 4051c07c..4051c0a3. Semantic name remains unreviewed. */

undefined4 FUN_4051c07c(int param_1,undefined4 param_2)

{
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x106,param_2);
  return 0;
}



/* 4051c0a4 FUN_4051c0a4 */

/* Boundary evidence: original MIPS .pdata 4051c0a4..4051c10f. Semantic name remains unreviewed. */

undefined4 FUN_4051c0a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xd4))
                      (*(int **)(param_1 + 0x2c),param_2,param_3);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051c110 FUN_4051c110 */

/* Boundary evidence: original MIPS .pdata 4051c110..4051c18b. Semantic name remains unreviewed. */

undefined4 FUN_4051c110(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_405305c8(param_1 + -0x128);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar2 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xdc))
                      (*(int **)(param_1 + 0x2c),param_2,param_3,param_4);
  }
  else {
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4051c18c FUN_4051c18c */

/* Boundary evidence: original MIPS .pdata 4051c18c..4051c1b3. Semantic name remains unreviewed. */

void FUN_4051c18c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xe0))();
  return;
}



/* 4051c1b4 FUN_4051c1b4 */

/* Boundary evidence: original MIPS .pdata 4051c1b4..4051c1db. Semantic name remains unreviewed. */

void FUN_4051c1b4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xfc))();
  return;
}



/* 4051c1dc FUN_4051c1dc */

/* Boundary evidence: original MIPS .pdata 4051c1dc..4051c203. Semantic name remains unreviewed. */

void FUN_4051c1dc(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0x100))();
  return;
}



/* 4051c204 FUN_4051c204 */

/* Boundary evidence: original MIPS .pdata 4051c204..4051c22b. Semantic name remains unreviewed. */

void FUN_4051c204(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xe4))();
  return;
}



/* 4051c22c FUN_4051c22c */

/* Boundary evidence: original MIPS .pdata 4051c22c..4051c253. Semantic name remains unreviewed. */

void FUN_4051c22c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xe8))();
  return;
}



/* 4051c254 FUN_4051c254 */

/* Boundary evidence: original MIPS .pdata 4051c254..4051c27b. Semantic name remains unreviewed. */

void FUN_4051c254(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xec))();
  return;
}



/* 4051c27c FUN_4051c27c */

/* Boundary evidence: original MIPS .pdata 4051c27c..4051c2a3. Semantic name remains unreviewed. */

void FUN_4051c27c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x2c) + 0xf0))();
  return;
}



/* 4051c2a4 FUN_4051c2a4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4051c2a4..4051c4c3. Semantic name remains unreviewed. */

undefined4 FUN_4051c2a4(int *param_1,int param_2,int param_3,short *param_4,short *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  BSTR local_30;
  uint local_2c [3];
  
  bVar1 = FUN_405305c8((int)(param_1 + -0x4a));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0x80004005;
  }
  if ((param_1[0xd] & 0x800U) != 0) {
    if ((param_2 != 7) && (param_2 != 6)) goto LAB_4051c368;
    if ((param_4 != (short *)0x0) && ((*param_4 == 8 || (*param_4 == 0x2000)))) {
      return 0x80070005;
    }
  }
  if (((param_2 == 6) && (param_1[6] != 0)) && (param_3 != 3)) {
    param_3 = 1;
  }
LAB_4051c368:
  if (((param_4 != (short *)0x0) && (*param_4 == 10)) && (*(int *)(param_4 + 4) == -0x7ffdfffc)) {
    *param_4 = 0;
    param_4[4] = 0;
    param_4[5] = 0;
  }
  if (((param_5 != (short *)0x0) && (*param_5 == 10)) && (*(int *)(param_5 + 4) == -0x7ffdfffc)) {
    *param_5 = 0;
    param_5[4] = 0;
    param_5[5] = 0;
  }
  if (((param_2 == 0xd) || (param_2 == 0xc)) || (param_2 == 0xb)) {
    if (param_1[6] != 0) {
      return 0;
    }
    iVar2 = (**(code **)(*param_1 + 0x78))(param_1,&local_30);
    if (-1 < iVar2) {
      local_2c[0] = 3;
      local_2c[1] = 0;
      iVar2 = ZoneCheckUrlExW(local_30,local_2c,4,local_2c + 1,4,0x1407,0,0);
      SysFreeString(local_30);
      if (iVar2 < 0) {
        return 0;
      }
      if ((local_2c[0] & 0xf) != 0) {
        return 0;
      }
    }
  }
  uVar3 = (**(code **)(*(int *)param_1[0xb] + 0xd8))
                    ((int *)param_1[0xb],param_2,param_3,param_4,param_5);
  return uVar3;
}



/* 4051c534 FUN_4051c534 */

/* Boundary evidence: original MIPS .pdata 4051c534..4051c583. Semantic name remains unreviewed. */

undefined4 FUN_4051c534(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x34) =
       ((uint)(param_2 != 0) << 8 ^ *(uint *)(param_1 + 0x34)) & 0x100 ^ *(uint *)(param_1 + 0x34);
  FUN_40533910(*(undefined4 *)(param_1 + 0x30),0x104,param_2);
  return 0;
}



/* 4051c584 FUN_4051c584 */

/* Boundary evidence: original MIPS .pdata 4051c584..4051c5a7. Semantic name remains unreviewed. */

void FUN_4051c584(int param_1)

{
  IUnknown_TranslateAcceleratorOCS(*(undefined4 *)(param_1 + -0xf8));
  return;
}



/* 4051c5a8 FUN_4051c5a8 */

/* Boundary evidence: original MIPS .pdata 4051c5a8..4051c6e7. Semantic name remains unreviewed. */

int FUN_4051c5a8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x14))
                    (*(int **)(param_1 + 0x2c),param_2,param_3,param_4,param_5,param_6,param_7,
                     param_8,param_9);
  if (iVar1 < 0) {
    piVar3 = (int *)(param_1 + -0x40);
    if ((*piVar3 == 0) && (puVar2 = *(undefined4 **)(param_1 + -0xf8), puVar2 != (undefined4 *)0x0))
    {
      (**(code **)*puVar2)(puVar2,&DAT_4051643c,piVar3);
    }
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar3 + 0x18))
                        (piVar3,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    }
  }
  return iVar1;
}



/* 4051c6e8 FUN_4051c6e8 */

/* Boundary evidence: original MIPS .pdata 4051c6e8..4051c763. Semantic name remains unreviewed. */

undefined4 FUN_4051c6e8(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *local_10 [2];
  
  puVar2 = *(undefined4 **)(param_1 + -0xfc);
  uVar3 = 0x80004001;
  if ((puVar2 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*puVar2)(puVar2,&UNK_4051650c,local_10), -1 < iVar1)) {
    uVar3 = (**(code **)(*local_10[0] + 0xc))();
    (**(code **)(*local_10[0] + 8))();
  }
  return uVar3;
}



/* 4051c764 FUN_4051c764 */

/* Boundary evidence: original MIPS .pdata 4051c764..4051c7a3. Semantic name remains unreviewed. */

undefined4 FUN_4051c764(int param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (*(void **)(param_1 + 0x30) == (void *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    memcpy(param_2,*(void **)(param_1 + 0x30),0x1c);
    uVar1 = 0;
  }
  return uVar1;
}



/* 4051c7a4 FUN_4051c7a4 */

/* Boundary evidence: original MIPS .pdata 4051c7a4..4051c83f. Semantic name remains unreviewed. */

int FUN_4051c7a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  FUN_40519354(param_1 + -0x14c);
  iVar2 = -0x7fffbffb;
  if (*(int *)(param_1 + 0x24) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x24) + 0x30);
    iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_3);
    FUN_40519ce8(param_1 + -0x14c,(uint)(iVar2 < 0));
  }
  return iVar2;
}



/* 4051c840 FUN_4051c840 */

/* Boundary evidence: original MIPS .pdata 4051c840..4051c887. Semantic name remains unreviewed. */

undefined4 FUN_4051c840(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x24) + 0x30) + 0x14))();
  }
  return uVar1;
}



/* 4051c888 FUN_4051c888 */

/* Boundary evidence: original MIPS .pdata 4051c888..4051c8cf. Semantic name remains unreviewed. */

undefined4 FUN_4051c888(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x24) + 0x30) + 0x18))();
  }
  return uVar1;
}



/* 4051c8d0 FUN_4051c8d0 */

/* Boundary evidence: original MIPS .pdata 4051c8d0..4051c917. Semantic name remains unreviewed. */

undefined4 FUN_4051c8d0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x24) + 0x30) + 0x1c))();
  }
  return uVar1;
}



/* 4051c918 FUN_4051c918 */

/* Boundary evidence: original MIPS .pdata 4051c918..4051cac7. Semantic name remains unreviewed. */

undefined4 FUN_4051c918(int param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  BSTR local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  IUnknown *local_14;
  
  local_18 = (int *)0x0;
  local_1c = (int *)0x0;
  uVar2 = 1;
  local_20 = (int *)0x0;
  local_24 = (BSTR)0x0;
  local_28 = (BSTR)0x0;
  if (((param_2 != (short *)0x0) && (*param_2 == 8)) && (*(int *)(param_2 + 4) != 0)) {
    local_14 = (IUnknown *)0x0;
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x150))
                      (*(undefined4 **)(param_1 + 0x150),&DAT_40512e84,&local_14);
    if (-1 < iVar1) {
      iVar1 = FUN_40538a84(local_14,(IID *)&DAT_405164bc,&local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18 + 0x34))(local_18,*(undefined4 *)(param_2 + 4),1,&local_1c);
        if ((-1 < iVar1) && (local_1c != (int *)0x0)) {
          iVar1 = (**(code **)*local_1c)(local_1c,&DAT_405162cc,&local_20);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_20 + 0x78))(local_20,&local_24);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(**(int **)(param_1 + 0x154) + 0x78))
                                (*(int **)(param_1 + 0x154),&local_28);
              if (-1 < iVar1) {
                uVar2 = FUN_4052e548(*(IUnknown **)(param_1 + 0x34),(int)local_28,(int)local_24);
                SysFreeString(local_28);
              }
              SysFreeString(local_24);
            }
            (**(code **)(*local_20 + 8))();
          }
          (**(code **)(*local_1c + 8))();
        }
        (**(code **)(*local_18 + 8))();
      }
      (*local_14->lpVtbl->Release)(local_14);
    }
  }
  return uVar2;
}



/* 4051cac8 FUN_4051cac8 */

undefined4 FUN_4051cac8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    *param_2 = 0;
    return 1;
  }
  if (param_1 == 1) {
    *param_2 = 1;
    return 1;
  }
  uVar1 = 2;
  if (param_1 == 2) {
LAB_4051cb2c:
    *param_2 = uVar1;
  }
  else {
    uVar1 = 3;
    if (param_1 != 3) {
      if (param_1 == 4) {
        *param_2 = 4;
        return 1;
      }
      uVar1 = 5;
      if (param_1 == 5) goto LAB_4051cb2c;
      uVar1 = 6;
      if (param_1 != 6) {
        return 0;
      }
    }
    *param_2 = uVar1;
  }
  return 1;
}



/* 4051cb48 FUN_4051cb48 */

/* Boundary evidence: original MIPS .pdata 4051cb48..4051cbb7. Semantic name remains unreviewed. */

void FUN_4051cb48(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_20 [2];
  undefined1 auStack_18 [16];
  
  iVar1 = FUN_4051cac8(param_2,local_20);
  if (iVar1 != 0) {
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x158),&DAT_405162bc,0x10d,auStack_18,1,3,local_20[0]);
  }
  return;
}



/* 4051cbb8 FUN_4051cbb8 */

/* Boundary evidence: original MIPS .pdata 4051cbb8..4051cd07. Semantic name remains unreviewed. */

undefined4 * FUN_4051cbb8(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  FUN_4052bc50(param_1,(undefined4 *)0x0);
  *param_1 = &PTR_FUN_40512090;
  param_1[4] = &PTR_LAB_40512048;
  param_1[5] = &PTR_LAB_40511ec4;
  param_1[6] = &PTR_LAB_40511eb4;
  param_1[7] = &PTR_LAB_40511ea0;
  param_1[8] = &PTR_LAB_40511e88;
  param_1[9] = &PTR_LAB_40511e64;
  param_1[10] = &PTR_LAB_40511e54;
  param_1[0xb] = &PTR_LAB_40511e40;
  param_1[0xc] = &PTR_LAB_40511e20;
  param_1[0xd] = &PTR_LAB_40511e0c;
  param_1[0xe] = &PTR_LAB_40511df8;
  param_1[0xf] = &PTR_LAB_40511de4;
  param_1[0x12] = &PTR_LAB_40511dcc;
  param_1[0x13] = &PTR_LAB_40511dbc;
  param_1[0x14] = &PTR_LAB_40511d60;
  param_1[0x15] = &PTR_LAB_40511d50;
  param_1[0x16] = &PTR_LAB_40511d30;
  param_1[0x17] = &PTR_LAB_40511d10;
  param_1[0x4f3] = param_3;
  FUN_40522e80((int)(param_1 + 5),0,param_2);
  param_1[0x4f] = param_1[0x4f] | 0x200000;
  return param_1;
}



/* 4051cd08 FUN_4051cd08 */

/* Boundary evidence: original MIPS .pdata 4051cd08..4051cd23. Semantic name remains unreviewed. */

void FUN_4051cd08(int param_1)

{
  FUN_4052ef6c(param_1);
  return;
}



/* 4051cd24 FUN_4051cd24 */

/* Boundary evidence: original MIPS .pdata 4051cd24..4051cd3f. Semantic name remains unreviewed. */

void FUN_4051cd24(int param_1)

{
  FUN_4052ef94(param_1);
  return;
}



/* 4051cda4 FUN_4051cda4 */

/* Boundary evidence: original MIPS .pdata 4051cda4..4051cdcb. Semantic name remains unreviewed. */

void FUN_4051cda4(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x24) + 0x24))();
  return;
}



/* 4051cde8 FUN_4051cde8 */

/* Boundary evidence: original MIPS .pdata 4051cde8..4051ce5f. Semantic name remains unreviewed. */

void FUN_4051cde8(int param_1,IUnknown *param_2)

{
  HRESULT HVar1;
  
  IUnknown_AtomicRelease((void **)(param_1 + 800));
  HVar1 = IUnknown_QueryService
                    (param_2,(GUID *)&DAT_4051645c,(IID *)&DAT_405162cc,(void **)(param_1 + 800));
  if (HVar1 < 0) {
    *(undefined4 *)(param_1 + 0x31c) = 0;
  }
  return;
}



/* 4051ce60 FUN_4051ce60 */

/* Boundary evidence: original MIPS .pdata 4051ce60..4051ce93. Semantic name remains unreviewed. */

undefined4 FUN_4051ce60(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 800);
  (**(code **)(**(int **)(param_1 + 800) + 4))();
  return 0;
}



/* 4051ce94 FUN_4051ce94 */

/* Boundary evidence: original MIPS .pdata 4051ce94..4051ceaf. Semantic name remains unreviewed. */

void FUN_4051ce94(int param_1)

{
  FUN_4052ef6c(param_1);
  return;
}



/* 4051ceb0 FUN_4051ceb0 */

/* Boundary evidence: original MIPS .pdata 4051ceb0..4051cecb. Semantic name remains unreviewed. */

void FUN_4051ceb0(int param_1)

{
  FUN_4052ef94(param_1);
  return;
}



/* 4051cecc FUN_4051cecc */

/* Boundary evidence: original MIPS .pdata 4051cecc..4051cfc7. Semantic name remains unreviewed. */

void FUN_4051cecc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40512090;
  param_1[4] = &PTR_LAB_40512048;
  param_1[5] = &PTR_LAB_40511ec4;
  param_1[6] = &PTR_LAB_40511eb4;
  param_1[7] = &PTR_LAB_40511ea0;
  param_1[8] = &PTR_LAB_40511e88;
  param_1[9] = &PTR_LAB_40511e64;
  param_1[10] = &PTR_LAB_40511e54;
  param_1[0xb] = &PTR_LAB_40511e40;
  param_1[0xc] = &PTR_LAB_40511e20;
  param_1[0xd] = &PTR_LAB_40511e0c;
  param_1[0xe] = &PTR_LAB_40511df8;
  param_1[0xf] = &PTR_LAB_40511de4;
  param_1[0x12] = &PTR_LAB_40511dcc;
  param_1[0x13] = &PTR_LAB_40511dbc;
  param_1[0x14] = &PTR_LAB_40511d60;
  param_1[0x15] = &PTR_LAB_40511d50;
  param_1[0x16] = &PTR_LAB_40511d30;
  param_1[0x17] = &PTR_LAB_40511d10;
  FUN_40522fb0(param_1);
  return;
}



/* 4051cfc8 FUN_4051cfc8 */

/* Boundary evidence: original MIPS .pdata 4051cfc8..4051d05b. Semantic name remains unreviewed. */

int FUN_4051cfc8(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4052efbc(param_1);
  if ((iVar1 < 0) && (iVar2 = memcmp(param_2,&DAT_40513764,0x10), iVar2 == 0)) {
    iVar1 = FUN_4052efbc(param_1);
  }
  return iVar1;
}



/* 4051d05c FUN_4051d05c */

/* Boundary evidence: original MIPS .pdata 4051d05c..4051d0e3. Semantic name remains unreviewed. */

bool FUN_4051d05c(int *param_1)

{
  int iVar1;
  bool bVar2;
  int *local_10;
  int *local_c;
  
  bVar2 = false;
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)*local_10)(local_10,&DAT_4051651c,&local_c);
    bVar2 = -1 < iVar1;
    if (bVar2) {
      (**(code **)(*local_c + 8))();
    }
    (**(code **)(*local_10 + 8))();
  }
  return bVar2;
}



/* 4051d0e4 FUN_4051d0e4 */

/* Boundary evidence: original MIPS .pdata 4051d0e4..4051d157. Semantic name remains unreviewed. */

undefined4 FUN_4051d0e4(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_40527010(param_1);
  if (((*(uint *)(param_1 + 0x144) & 1) != 0) && (*(int *)(param_1 + 0x13b8) != 0)) {
    bVar1 = FUN_4051d05c(*(int **)(*(int *)(param_1 + 0x13b8) + 0x34));
    *(uint *)(param_1 + 0x144) =
         ((uint)bVar1 << 1 ^ *(uint *)(param_1 + 0x144)) & 2 ^ *(uint *)(param_1 + 0x144);
  }
  return uVar2;
}



/* 4051d158 FUN_4051d158 */

/* Boundary evidence: original MIPS .pdata 4051d158..4051d1a7. Semantic name remains unreviewed. */

void FUN_4051d158(int param_1,undefined4 param_2,uint param_3,WPARAM param_4,LPARAM param_5)

{
  FUN_4052a578(param_1,param_2,param_3,param_4,param_5);
  if (param_3 == 2) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  return;
}



/* 4051d1a8 FUN_4051d1a8 */

/* Boundary evidence: original MIPS .pdata 4051d1a8..4051d30f. Semantic name remains unreviewed. */

undefined4 FUN_4051d1a8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  HRESULT HVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *local_20 [2];
  
  uVar5 = 0;
  FUN_40529514(param_1 + 0x10,param_2);
  if (param_3 == 1) {
    iVar4 = *(int *)(param_1 + 0x13cc);
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 0x8c) == 0) {
        if (((iVar4 != 0) && (*(IUnknown **)(iVar4 + 0x34) != (IUnknown *)0x0)) &&
           (HVar2 = IUnknown_QueryService
                              (*(IUnknown **)(iVar4 + 0x34),(GUID *)&DAT_4051652c,
                               (IID *)&DAT_4051652c,local_20), -1 < HVar2)) {
          (**(code **)(*local_20[0] + 0x24))(local_20[0],param_2);
          (**(code **)(*local_20[0] + 8))();
        }
      }
      else {
        uVar5 = (**(code **)(**(int **)(iVar4 + 0x8c) + 0x34))(*(int **)(iVar4 + 0x8c),param_2);
        if ((((*(uint *)(param_1 + 0x158) & 1) == 0) && (*(int *)(param_1 + 0x128) == 0)) &&
           (uVar1 = GetWindowLongW(*(HWND *)(param_1 + 0x70),-0x10), (uVar1 & 0x8000000) != 0)) {
          EnableWindow(*(HWND *)(param_1 + 0x70),1);
        }
      }
    }
  }
  else {
    piVar3 = *(int **)(param_1 + 0xa0);
    if (piVar3 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar3 + 0x18))(piVar3,param_2);
    }
  }
  return uVar5;
}



/* 4051d310 FUN_4051d310 */

/* Boundary evidence: original MIPS .pdata 4051d310..4051d32f. Semantic name remains unreviewed. */

void FUN_4051d310(int param_1,int param_2)

{
  FUN_4051d1a8(param_1 + -0x10,param_2,1);
  return;
}



/* 4051d330 FUN_4051d330 */

/* Boundary evidence: original MIPS .pdata 4051d330..4051d3f3. Semantic name remains unreviewed. */

void FUN_4051d330(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_405233d0();
  if (iVar1 != 0) {
    if (param_4 == 1) {
      if ((*(int *)(param_1 + 0x13cc) != 0) && (*(int *)(*(int *)(param_1 + 0x13cc) + 0x8c) != 0)) {
        piVar2 = *(int **)(*(int *)(param_1 + 0x13cc) + 0x8c);
        (**(code **)(*piVar2 + 0x38))(piVar2,param_2,param_3);
      }
    }
    else {
      piVar2 = *(int **)(param_1 + 0xa0);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x14))(piVar2,param_2);
      }
    }
  }
  return;
}



/* 4051d3f4 FUN_4051d3f4 */

/* Boundary evidence: original MIPS .pdata 4051d3f4..4051d413. Semantic name remains unreviewed. */

void FUN_4051d3f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_4051d330(param_1 + -0x10,param_2,param_3,1);
  return;
}



/* 4051d414 FUN_4051d414 */

/* Boundary evidence: original MIPS .pdata 4051d414..4051d563. Semantic name remains unreviewed. */

int FUN_4051d414(int param_1,int param_2,UINT param_3,uint param_4,wchar_t *param_5,LRESULT *param_6
                )

{
  int iVar1;
  int *piVar2;
  WCHAR local_228 [256];
  uint local_28;
  
  local_28 = DAT_40544354;
  iVar1 = FUN_40524d90(param_1,param_2,param_3,param_4,param_5,param_6);
  if ((((iVar1 < 0) && (*(int *)(param_1 + 0x13bc) != 0)) && (param_2 == 1)) &&
     (((param_3 == 0x40b && ((param_4 & 0x1000) == 0)) &&
      (((param_4 & 0xff) == 0xff || ((param_4 & 0xff) == 0)))))) {
    if (param_5 == (wchar_t *)0x0) {
      local_228[0] = L'\0';
    }
    else {
      SHUnicodeToUnicode(param_5,local_228,0x100);
    }
    if (*(int *)(*(int *)(param_1 + 0x13bc) + 0x8c) != 0) {
      if (param_6 != (LRESULT *)0x0) {
        *param_6 = 0;
      }
      piVar2 = *(int **)(*(int *)(param_1 + 0x13bc) + 0x8c);
      iVar1 = (**(code **)(*piVar2 + 0x30))(piVar2,local_228);
    }
  }
  FUN_40542538(local_28);
  return iVar1;
}



/* 4051d564 FUN_4051d564 */

/* Boundary evidence: original MIPS .pdata 4051d564..4051d5b3. Semantic name remains unreviewed. */

void FUN_4051d564(int param_1)

{
  if (*(int **)(param_1 + 0x13bc) != (int *)0x0) {
    FUN_40517840(*(int **)(param_1 + 0x13bc),0,2,0);
  }
  FUN_40524ec4(param_1);
  return;
}



/* 4051d5b4 FUN_4051d5b4 */

/* Boundary evidence: original MIPS .pdata 4051d5b4..4051d633. Semantic name remains unreviewed. */

int FUN_4051d5b4(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + -5;
  (**(code **)(*piVar2 + 4))(piVar2);
  iVar1 = FUN_40524268(param_1);
  if ((-1 < iVar1) && (param_1[0x4ee] != 0)) {
    FUN_4051acc8(param_1[0x4ee]);
  }
  (**(code **)(*piVar2 + 8))(piVar2);
  return iVar1;
}



/* 4051d634 FUN_4051d634 */

/* Boundary evidence: original MIPS .pdata 4051d634..4051d64f. Semantic name remains unreviewed. */

void FUN_4051d634(int param_1)

{
  FUN_40529d38(param_1);
  return;
}



/* 4051d650 FUN_4051d650 */

/* Boundary evidence: original MIPS .pdata 4051d650..4051d6d7. Semantic name remains unreviewed. */

undefined4 FUN_4051d650(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_2 = 0;
  iVar3 = *(int *)(param_1 + 0x13b8);
  uVar1 = 0x80004005;
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x88) == 0) {
      if (*(int *)(iVar3 + 0x34) != 0) {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x13b8) + 0x34);
        uVar1 = (**(code **)*puVar2)(puVar2,&DAT_405163ac,param_2);
      }
    }
    else {
      *param_2 = *(undefined4 *)(iVar3 + 0x88);
      (**(code **)(**(int **)(*(int *)(param_1 + 0x13b8) + 0x88) + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4051d6d8 FUN_4051d6d8 */

/* Boundary evidence: original MIPS .pdata 4051d6d8..4051d723. Semantic name remains unreviewed. */

undefined4 FUN_4051d6d8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x13b8) == 0) {
    uVar1 = 0x80004005;
    *param_2 = 0;
  }
  else {
    uVar1 = (**(code **)**(undefined4 **)(param_1 + 0x13b8))
                      (*(undefined4 **)(param_1 + 0x13b8),&DAT_4051632c,param_2);
  }
  return uVar1;
}



/* 4051d724 FUN_4051d724 */

/* Boundary evidence: original MIPS .pdata 4051d724..4051d79b. Semantic name remains unreviewed. */

undefined4 FUN_4051d724(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined2 local_20 [4];
  uint local_18;
  
  uVar1 = FUN_40526698(param_1,param_2);
  local_20[0] = 3;
  local_18 = *(uint *)(param_1 + 0x128) >> 1 & 1;
  (**(code **)(*(int *)(param_1 + 8) + 0x10))((int *)(param_1 + 8),0,0x1d,0,local_20,0);
  return uVar1;
}



/* 4051d79c FUN_4051d79c */

/* Boundary evidence: original MIPS .pdata 4051d79c..4051d7b7. Semantic name remains unreviewed. */

void FUN_4051d79c(int param_1,int param_2)

{
  FUN_40524150(param_1,param_2);
  return;
}



/* 4051d7b8 FUN_4051d7b8 */

/* Boundary evidence: original MIPS .pdata 4051d7b8..4051db27. Semantic name remains unreviewed. */

int * FUN_4051d7b8(int *param_1,GUID *param_2,IID *param_3,void **param_4)

{
  int iVar1;
  int *piVar2;
  HRESULT HVar3;
  undefined4 *puVar4;
  IUnknown *pIVar5;
  int *local_30 [2];
  
  *param_4 = (void *)0x0;
  if (((param_1[0x4ed] == 0) || (*(int *)(param_1[0x4ed] + 0x34) == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_405133d4,0x10), iVar1 != 0)) {
    iVar1 = memcmp(param_2,&DAT_4051658c,0x10);
    if (((iVar1 != 0) && (iVar1 = memcmp(param_2,&DAT_4051656c,0x10), iVar1 != 0)) &&
       (iVar1 = memcmp(param_2,&DAT_4051657c,0x10), iVar1 != 0)) {
      iVar1 = memcmp(param_2,&DAT_40512c24,0x10);
      if (iVar1 == 0) {
        iVar1 = memcmp(param_3,&DAT_4051655c,0x10);
        if (((iVar1 != 0) && (piVar2 = (int *)param_1[0x4e], piVar2 != (int *)0x0)) &&
           (iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,local_30), -1 < iVar1)) {
          if (local_30[0] == (int *)0x0) goto LAB_4051d934;
          (**(code **)(*local_30[0] + 8))();
        }
      }
      else {
LAB_4051d934:
        iVar1 = memcmp(param_2,&DAT_4051654c,0x10);
        if (iVar1 == 0) {
          puVar4 = (undefined4 *)param_1[0x4ed];
          if (puVar4 == (undefined4 *)0x0) {
            return (int *)0x8000ffff;
          }
          goto LAB_4051d830;
        }
        iVar1 = memcmp(param_2,&DAT_4051653c,0x10);
        if (iVar1 == 0) {
          *param_4 = (void *)0x0;
          if (((param_1[0x4ed] != 0) &&
              (pIVar5 = *(IUnknown **)(param_1[0x4ed] + 0x34), pIVar5 != (IUnknown *)0x0)) &&
             (HVar3 = IUnknown_QueryService(pIVar5,param_2,param_3,param_4), HVar3 == 0)) {
            return (int *)0x0;
          }
        }
        piVar2 = FUN_40526854(param_1,param_2,param_3,param_4);
        if (-1 < (int)piVar2) {
          return piVar2;
        }
        if (piVar2 == (int *)0x80004002) {
          return (int *)0x80004002;
        }
        iVar1 = memcmp(param_2,&DAT_4051652c,0x10);
        if (iVar1 == 0) {
          return piVar2;
        }
        iVar1 = memcmp(param_2,&DAT_40512764,0x10);
        if (iVar1 == 0) {
          return piVar2;
        }
      }
    }
    *param_4 = (void *)0x0;
    piVar2 = (int *)0x80004005;
    if ((param_1[0x4ed] != 0) &&
       (pIVar5 = *(IUnknown **)(param_1[0x4ed] + 0x34), pIVar5 != (IUnknown *)0x0)) {
      piVar2 = (int *)IUnknown_QueryService(pIVar5,param_2,param_3,param_4);
    }
    if (((int)piVar2 < 0) &&
       (((iVar1 = memcmp(param_2,&DAT_4051658c,0x10), iVar1 == 0 ||
         (iVar1 = memcmp(param_2,&DAT_40512c24,0x10), iVar1 == 0)) ||
        ((iVar1 = memcmp(param_2,&DAT_4051656c,0x10), iVar1 == 0 ||
         (iVar1 = memcmp(param_2,&DAT_4051657c,0x10), iVar1 == 0)))))) {
      piVar2 = FUN_40526854(param_1,param_2,param_3,param_4);
    }
  }
  else {
    puVar4 = *(undefined4 **)(param_1[0x4ed] + 0x34);
LAB_4051d830:
    piVar2 = (int *)(**(code **)*puVar4)(puVar4,param_3,param_4);
  }
  return piVar2;
}



/* 4051db28 FUN_4051db28 */

/* Boundary evidence: original MIPS .pdata 4051db28..4051dd9b. Semantic name remains unreviewed. */

int FUN_4051db28(int param_1,void *param_2,int param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  int *piVar4;
  IUnknown *punk;
  int iVar5;
  int iVar6;
  int *local_30 [2];
  
  if ((param_2 == (void *)0x0) || (iVar1 = memcmp(param_2,&DAT_405163ec,0x10), iVar1 != 0)) {
    if ((*(int *)(param_1 + 0x13b0) == 0) ||
       (((*(int *)(*(int *)(param_1 + 0x13b0) + 0x178) == 0 ||
         (piVar4 = *(int **)(*(int *)(param_1 + 0x13b0) + 0x178),
         iVar1 = (**(code **)(*piVar4 + 0xc))(piVar4,param_2,param_3,param_4,param_5),
         iVar1 == -0x7ffbfefc)) || (iVar1 == -0x7ffbff00)))) {
      iVar1 = FUN_40525010(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    iVar1 = 0;
    if (param_3 == 0) {
      return 0;
    }
    piVar4 = param_4;
    iVar6 = param_3;
    do {
      if ((*piVar4 == 7) || (*piVar4 == 8)) {
        iVar2 = FUN_40525010(param_1,param_2,1,piVar4,param_5);
LAB_4051dc4c:
        if (iVar2 != 0) goto LAB_4051dc54;
      }
      else {
        iVar5 = *(int *)(param_1 + 0x13b0);
        iVar2 = -0x7ffbff00;
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0x178) != 0)) {
          iVar2 = (**(code **)(**(int **)(iVar5 + 0x178) + 0xc))
                            (*(int **)(iVar5 + 0x178),param_2,1,piVar4,param_5);
          if ((iVar2 == -0x7ffbfefc) || (iVar2 == -0x7ffbff00)) {
            iVar2 = FUN_40525010(param_1,param_2,param_3,param_4,param_5);
          }
          goto LAB_4051dc4c;
        }
LAB_4051dc54:
        iVar1 = iVar2;
      }
      iVar6 = iVar6 + -1;
      piVar4 = piVar4 + 2;
    } while (iVar6 != 0);
  }
  if (((iVar1 != 0) && (*(int *)(param_1 + 0x13b0) != 0)) &&
     (punk = *(IUnknown **)(*(int *)(param_1 + 0x13b0) + 0x34), punk != (IUnknown *)0x0)) {
    local_30[0] = (int *)0x0;
    HVar3 = IUnknown_QueryService(punk,(GUID *)&DAT_4051646c,(IID *)&DAT_4051646c,local_30);
    if (-1 < HVar3) {
      iVar1 = (**(code **)(*local_30[0] + 0xc))(local_30[0],param_2,param_3,param_4,param_5);
      (**(code **)(*local_30[0] + 8))();
    }
  }
  return iVar1;
}



/* 4051dd9c FUN_4051dd9c */

/* Boundary evidence: original MIPS .pdata 4051dd9c..4051de4f. Semantic name remains unreviewed. */

undefined4 FUN_4051dd9c(int param_1)

{
  int iVar1;
  int *local_10 [2];
  
  FUN_40528e78(param_1);
  if ((((*(int *)(param_1 + 0x8c) != 0) && (iVar1 = *(int *)(param_1 + 0x13b8), iVar1 != 0)) &&
      (*(int *)(iVar1 + 0xb4) == 0)) &&
     ((*(int *)(iVar1 + 0x16c) != 0 &&
      (iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x8c))
                         (*(undefined4 **)(param_1 + 0x8c),&UNK_40512ee4,local_10), -1 < iVar1)))) {
    (**(code **)(*local_10[0] + 0xc))
              (local_10[0],*(undefined4 *)(*(int *)(param_1 + 0x13b8) + 0x16c),
               *(int *)(param_1 + 0x13b8) + 0x54);
    (**(code **)(*local_10[0] + 8))();
  }
  return 0;
}



/* 4051de50 FUN_4051de50 */

/* Boundary evidence: original MIPS .pdata 4051de50..4051de7b. Semantic name remains unreviewed. */

void FUN_4051de50(int param_1,ushort *param_2,uint param_3)

{
  if ((param_3 & 3) == 0) {
    param_3 = param_3 | 1;
  }
  FUN_4052ab24(param_1,param_2,param_3);
  return;
}



/* 4051e994 FUN_4051e994 */

/* Boundary evidence: original MIPS .pdata 4051e994..4051e9df. Semantic name remains unreviewed. */

undefined4 * FUN_4051e994(undefined4 *param_1,uint param_2)

{
  FUN_40519004(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4051e9e0 FUN_4051e9e0 */

/* Boundary evidence: original MIPS .pdata 4051e9e0..4051eabf. Semantic name remains unreviewed. */

bool FUN_4051e9e0(int *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = param_1 + 0x54;
  param_1[0x57] = param_1[0x57] | 8;
  param_1[99] = (int)(param_1 + 8);
  param_1[100] = (int)&DAT_405164fc;
  FUN_405379a8(param_1 + 0x30,piVar2);
  puVar1 = (undefined4 *)*piVar2;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(puVar1,&DAT_405162cc,param_1 + 0x55);
    (**(code **)(*param_1 + 8))(param_1);
    (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_40512b14,param_1 + 0x56);
    (**(code **)(*param_1 + 8))(param_1);
  }
  if (param_2 != 0) {
    param_1[10] = param_2;
  }
  return *piVar2 != 0;
}



/* 4051eac0 FUN_4051eac0 */

/* Boundary evidence: original MIPS .pdata 4051eac0..4051ed03. Semantic name remains unreviewed. */

void FUN_4051eac0(int param_1)

{
  HRESULT HVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_10;
  
  if (*(IUnknown **)(param_1 + 0x34) == (IUnknown *)0x0) {
    iVar3 = (**(code **)**(undefined4 **)(param_1 + 0x150))
                      (*(undefined4 **)(param_1 + 0x150),&DAT_40512e84,&local_10);
    if (-1 < iVar3) {
      (**(code **)(*local_10 + 0xc))(local_10,0);
      (**(code **)(*local_10 + 8))();
    }
    if ((*(uint *)(param_1 + 0x15c) & 0x400) != 0) {
      FUN_4052e0b8(2);
      *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffffbff;
    }
  }
  else {
    HVar1 = IUnknown_QueryService
                      (*(IUnknown **)(param_1 + 0x34),(GUID *)&DAT_4051658c,(IID *)&DAT_40513564,
                       (void **)&local_10);
    if (HVar1 < 0) {
      *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 4;
    }
    else {
      (**(code **)(*local_10 + 8))();
    }
    if (*(int *)(param_1 + 0x170) == 0) {
      puVar2 = (undefined4 *)FUN_4052d4e8(0x13d4);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_4051cbb8(puVar2,(int *)(param_1 + 0x20),param_1);
      }
      *(undefined4 **)(param_1 + 0x170) = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
      puVar2[0xda] = *(undefined4 *)(param_1 + 0x164);
      puVar2[0xdb] = *(undefined4 *)(param_1 + 0x168);
      if ((*(uint *)(param_1 + 0x15c) & 4) != 0) {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x170) + 0x14) + 0xcc))();
      }
      piVar4 = (int *)(*(int *)(param_1 + 0x170) + 0x14);
      (**(code **)(*piVar4 + 0x128))(piVar4,0);
    }
  }
  FUN_4051891c(param_1);
  if (*(int *)(param_1 + 0x34) != 0) {
    local_10 = (int *)((uint)local_10._2_2_ << 0x10);
    iVar3 = FUN_40530058(param_1,0xffffea83,0xb,&local_10);
    if (iVar3 != 0) {
      (**(code **)(*(int *)(param_1 + 0x128) + 0xe8))((int *)(param_1 + 0x128),(int)(short)local_10)
      ;
    }
    if (((*(uint *)(param_1 + 0x15c) & 4) != 0) && ((short)local_10 == 0)) {
      FUN_4052e0b8(3);
      *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) | 0x400;
    }
    iVar3 = FUN_40530058(param_1,0xffffea82,0xb,&local_10);
    if (iVar3 != 0) {
      (**(code **)(*(int *)(param_1 + 0x128) + 0xf0))((int *)(param_1 + 0x128),(int)(short)local_10)
      ;
    }
  }
  return;
}



/* 4051ed04 FUN_4051ed04 */

/* Boundary evidence: original MIPS .pdata 4051ed04..4051ed43. Semantic name remains unreviewed. */

undefined4 FUN_4051ed04(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x15c) == 0) ||
     (iVar1 = FUN_4051d330(*(int *)(param_1 + 0x15c),param_2,0,0), iVar1 != 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4051ed44 FUN_4051ed44 */

/* Boundary evidence: original MIPS .pdata 4051ed44..4051ed9f. Semantic name remains unreviewed. */

undefined4 FUN_4051ed44(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_40522fa8();
  if (*(int *)(param_1 + 0x15c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_4051d1a8(*(int *)(param_1 + 0x15c),param_2,0);
  }
  return uVar1;
}



/* 4051eda0 FUN_4051eda0 */

/* Boundary evidence: original MIPS .pdata 4051eda0..4051eeaf. Semantic name remains unreviewed. */

undefined4 FUN_4051eda0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  HRESULT HVar1;
  IUnknown *punk;
  int iVar2;
  int *local_30 [2];
  undefined2 local_28 [4];
  int local_20;
  
  if (*(int *)(param_1 + 0x170) != 0) {
    local_30[0] = (int *)0x0;
    iVar2 = *(int *)(*(int *)(param_1 + 0x170) + 0x13cc);
    if (((iVar2 != 0) && (punk = *(IUnknown **)(iVar2 + 0x34), punk != (IUnknown *)0x0)) &&
       (HVar1 = IUnknown_QueryService(punk,(GUID *)&DAT_4051658c,(IID *)&DAT_4051646c,local_30),
       -1 < HVar1)) {
      if ((param_4 == 0) || (*(int *)(param_4 + 8) == 0)) {
        local_28[0] = 0xb;
        local_20 = 0;
      }
      else {
        local_28[0] = 0xd;
        local_20 = param_1 + 0x138;
      }
      iVar2 = (**(code **)(*local_30[0] + 0x10))(local_30[0],0,0x1d,param_3,local_28,0);
      if (-1 < iVar2) {
        param_2 = 0;
      }
      (**(code **)(*local_30[0] + 8))();
    }
  }
  return param_2;
}



/* 4051eeb0 FUN_4051eeb0 */

/* Boundary evidence: original MIPS .pdata 4051eeb0..4051ef93. Semantic name remains unreviewed. */

int FUN_4051eeb0(int param_1,undefined4 param_2,undefined4 param_3,short *param_4,undefined4 param_5
                ,undefined4 param_6)

{
  int iVar1;
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x2c))
                      (*(int **)(param_1 + 0x2c),param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = FUN_4052e8b0(local_res4);
    if (-1 < iVar1) {
      iVar1 = FUN_4053a5ec(*(IUnknown **)(param_1 + -0xf4),local_res4[0]);
      if ((iVar1 == 0) || (iVar1 = FUN_4051c918(param_1 + -0x128,param_4), iVar1 == 0)) {
        iVar1 = -0x7ff8fffb;
      }
      else {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x2c))
                          (*(int **)(param_1 + 0x2c),local_res4[0],param_3,param_4,param_5,param_6);
      }
    }
  }
  return iVar1;
}



/* 4051ef94 FUN_4051ef94 */

/* Boundary evidence: original MIPS .pdata 4051ef94..4051f0ab. Semantic name remains unreviewed. */

int FUN_4051ef94(int param_1,short *param_2,undefined4 param_3,short *param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  
  if (((*(int *)(param_1 + 0x18) == 0) || (*param_2 != 8)) ||
     (piVar2 = (int *)(param_2 + 4), *piVar2 == 0)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xd0))
                      (*(int **)(param_1 + 0x2c),param_2,param_3,param_4,param_5,param_6);
  }
  else {
    iVar1 = FUN_4052e8b0(piVar2);
    if (-1 < iVar1) {
      iVar1 = FUN_4053a5ec(*(IUnknown **)(param_1 + -0xf4),*piVar2);
      if ((iVar1 == 0) || (iVar1 = FUN_4051c918(param_1 + -0x128,param_4), iVar1 == 0)) {
        iVar1 = -0x7ff8fffb;
      }
      else {
        iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xd0))
                          (*(int **)(param_1 + 0x2c),param_2,param_3,param_4,param_5,param_6);
      }
    }
  }
  return iVar1;
}



/* 4051f0ac FUN_4051f0ac */

/* Boundary evidence: original MIPS .pdata 4051f0ac..4051f0f7. Semantic name remains unreviewed. */

undefined4 * FUN_4051f0ac(undefined4 *param_1,uint param_2)

{
  FUN_4051cecc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4051f0f8 FUN_4051f0f8 */

/* Boundary evidence: original MIPS .pdata 4051f0f8..4051f56b. Semantic name remains unreviewed. */

int FUN_4051f0f8(int param_1,void *param_2,uint param_3,undefined4 param_4,short *param_5,
                VARIANTARG *param_6)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  int *piVar4;
  IUnknown *punk;
  int iVar5;
  uint uVar6;
  int *local_30 [2];
  
  iVar5 = -0x7ffbfefc;
  uVar6 = 0;
  do {
    if (param_3 == *(uint *)((int)&DAT_405116d4 + uVar6)) {
      if ((param_2 == (void *)0x0) || (*(void **)((int)&DAT_405116d0 + uVar6) == (void *)0x0)) {
        if (param_2 == *(void **)((int)&DAT_405116d0 + uVar6)) {
          iVar5 = FUN_4052bf98(param_1,param_2,param_3,param_4,param_5,param_6);
          return iVar5;
        }
      }
      else {
        iVar1 = memcmp(param_2,*(void **)((int)&DAT_405116d0 + uVar6),0x10);
        if (iVar1 == 0) {
          iVar5 = FUN_4052bf98(param_1,param_2,param_3,param_4,param_5,param_6);
          return iVar5;
        }
      }
    }
    uVar6 = uVar6 + 8;
  } while (uVar6 < 0x78);
  iVar1 = -0x7ffbfefc;
  if (param_2 == (void *)0x0) {
    if ((param_3 == 0x1d) && (iVar1 = iVar5, param_5 != (short *)0x0)) {
      FUN_40525568(param_1 + -0x1c,param_5);
    }
  }
  else {
    iVar2 = memcmp(param_2,&DAT_405163ec,0x10);
    if (iVar2 == 0) {
      if (param_3 == 0xf) {
        if (0 < *(int *)(param_1 + 0x13b4)) {
          *(int *)(param_1 + 0x13b4) = *(int *)(param_1 + 0x13b4) + -1;
        }
        iVar1 = FUN_4052bf98(param_1,param_2,0xf,param_4,param_5,param_6);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (0 < *(int *)(param_1 + 0x13b4)) {
          return iVar1;
        }
      }
      else if (param_3 == 0x10) {
        iVar2 = *(int *)(param_1 + 0x13b4) + 1;
        *(int *)(param_1 + 0x13b4) = iVar2;
        iVar1 = iVar5;
        if (1 < iVar2) {
          return 0;
        }
      }
      else if (((param_3 == 0x3a) && (iVar1 = iVar5, *(int *)(param_1 + 0x13b0) != 0)) &&
              (iVar2 = *(int *)(*(int *)(param_1 + 0x13b0) + 0x150), iVar2 != 0)) {
        iVar5 = IUnknown_Exec(iVar2,&DAT_405163ec,0x3a,0,param_5,0);
        return iVar5;
      }
    }
    else {
      iVar1 = memcmp(param_2,&DAT_405163dc,0x10);
      if (iVar1 == 0) {
        if (param_3 == 0x19) {
          FUN_4052bf98(param_1,param_2,0x19,param_4,param_5,param_6);
          if (*(int *)(param_1 + 0x13b0) != 0) {
            FUN_4051cb48(*(int *)(param_1 + 0x13b0),*(int *)(param_1 + 0x6c));
          }
          return 0;
        }
        if ((param_3 == 0x26) || (iVar1 = iVar5, param_3 == 0x28)) {
          iVar5 = FUN_4052bf98(param_1,param_2,param_3,param_4,param_5,param_6);
          return iVar5;
        }
      }
      else {
        iVar2 = memcmp(&DAT_4051659c,param_2,0x10);
        iVar1 = iVar5;
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
  }
  if ((*(int *)(param_1 + 0x13b0) != 0) &&
     (piVar4 = *(int **)(*(int *)(param_1 + 0x13b0) + 0x178), piVar4 != (int *)0x0)) {
    iVar1 = (**(code **)(*piVar4 + 0x10))(piVar4,param_2,param_3,param_4,param_5,param_6);
  }
  if ((iVar1 == -0x7ffbfefc) || (iVar1 == -0x7ffbff00)) {
    if ((param_2 == (void *)0x0) && ((param_3 == 0x1d && (*(int *)(param_1 + 0x13b0) != 0)))) {
      iVar1 = FUN_4051eda0(*(int *)(param_1 + 0x13b0),iVar1,param_4,(int)param_5);
    }
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_4052bf98(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  if (((iVar1 != 0) && (*(int *)(param_1 + 0x13b0) != 0)) &&
     (punk = *(IUnknown **)(*(int *)(param_1 + 0x13b0) + 0x34), punk != (IUnknown *)0x0)) {
    local_30[0] = (int *)0x0;
    HVar3 = IUnknown_QueryService(punk,(GUID *)&DAT_4051646c,(IID *)&DAT_4051646c,local_30);
    if (-1 < HVar3) {
      iVar1 = (**(code **)(*local_30[0] + 0x10))
                        (local_30[0],param_2,param_3,param_4,param_5,param_6);
      (**(code **)(*local_30[0] + 8))();
    }
  }
  return iVar1;
}



/* 4051f580 FUN_4051f580 */

/* Boundary evidence: original MIPS .pdata 4051f580..4051f5a7. Semantic name remains unreviewed. */

void FUN_4051f580(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 4))();
  return;
}



/* 4051f5a8 FUN_4051f5a8 */

/* Boundary evidence: original MIPS .pdata 4051f5a8..4051f5cf. Semantic name remains unreviewed. */

void FUN_4051f5a8(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x10) + 8))();
  return;
}



/* 4051f5d0 FUN_4051f5d0 */

/* Boundary evidence: original MIPS .pdata 4051f5d0..4051f783. Semantic name remains unreviewed. */

undefined4 * FUN_4051f5d0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  FUN_405306dc(param_1,param_2,param_3,&DAT_40511658,&DAT_40511678);
  param_1[0x4b] = &PTR_LAB_40511748;
  param_1[0x4c] = &PTR_LAB_40511764;
  param_1[0x4d] = &PTR_LAB_40511778;
  param_1[0x4f] = &PTR_LAB_405120c4;
  param_1[0x50] = 0;
  param_1[0x52] = &PTR_LAB_405120d8;
  *param_1 = &PTR_FUN_40511b5c;
  param_1[1] = &PTR_LAB_40511afc;
  param_1[2] = &PTR_LAB_40511ad4;
  param_1[3] = &PTR_LAB_40511aa4;
  param_1[4] = &PTR_LAB_40511a80;
  param_1[5] = &PTR_LAB_40511a58;
  param_1[6] = &PTR_LAB_40511a44;
  param_1[7] = &PTR_LAB_40511a30;
  param_1[0xb] = &PTR_LAB_40511a24;
  param_1[0x2e] = &PTR_LAB_40511a00;
  param_1[0x2f] = &PTR_LAB_405119e4;
  param_1[0x30] = &PTR_LAB_405119c8;
  param_1[0x31] = &PTR_LAB_405119ac;
  param_1[0x32] = &PTR_LAB_40511998;
  param_1[0x33] = &PTR_LAB_40511980;
  param_1[0x34] = &PTR_LAB_40511978;
  param_1[0x4a] = &PTR_LAB_4051185c;
  param_1[0x4b] = &PTR_LAB_40511840;
  param_1[0x4c] = &PTR_LAB_4051182c;
  param_1[0x4d] = &PTR_LAB_40511818;
  param_1[0x4e] = &PTR_LAB_40511804;
  param_1[0x4f] = &PTR_LAB_405117f0;
  param_1[0x51] = &PTR_LAB_405117e0;
  param_1[0x52] = &PTR_LAB_405117ac;
  param_1[0x53] = &PTR_LAB_4051178c;
  param_1[0x5f] = &PTR_FUN_4051210c;
  return param_1;
}



/* 4051f784 FUN_4051f784 */

/* Boundary evidence: original MIPS .pdata 4051f784..4051f83f. Semantic name remains unreviewed. */

undefined4 FUN_4051f784(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined4 uVar4;
  
  uVar4 = 0x8007000e;
  puVar2 = LocalAlloc(0x40,0x198);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_4051f5d0(puVar2,(undefined4 *)0x0,param_3);
  }
  if (piVar3 != (int *)0x0) {
    bVar1 = FUN_4051e9e0(piVar3,param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    else {
      *param_2 = (int)(piVar3 + 8);
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* 4051f840 FUN_4051f840 */

/* Boundary evidence: original MIPS .pdata 4051f840..4051f893. Semantic name remains unreviewed. */

void FUN_4051f840(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4051217c;
  param_1[1] = &PTR_LAB_40512168;
  param_1[2] = &PTR_LAB_40512158;
  if (param_1[4] != 0) {
    FUN_40537f64(param_1[4]);
  }
  FUN_40516d74();
  return;
}



/* 4051f894 FUN_4051f894 */

/* Boundary evidence: original MIPS .pdata 4051f894..4051f8bb. Semantic name remains unreviewed. */

void FUN_4051f894(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_405121cc,param_2,param_3);
  return;
}



/* 4051f8bc FUN_4051f8bc */

/* Boundary evidence: original MIPS .pdata 4051f8bc..4051f8d7. Semantic name remains unreviewed. */

void FUN_4051f8bc(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



/* 4051f910 FUN_4051f910 */

/* Boundary evidence: original MIPS .pdata 4051f910..4051f97f. Semantic name remains unreviewed. */

undefined4 FUN_4051f910(undefined4 param_1,undefined4 param_2,void *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_3,&DAT_405165ec,0x10);
  if (iVar1 == 0) {
    uVar2 = FUN_40539448();
  }
  else {
    *param_4 = 0;
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 4051f994 FUN_4051f994 */

/* Boundary evidence: original MIPS .pdata 4051f994..4051f9eb. Semantic name remains unreviewed. */

int FUN_4051f994(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (*param_4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_4053ac08(*(ushort **)(param_1 + 0x10),0,(undefined2 *)0x0,0,(int)param_4);
    }
  }
  else {
    iVar1 = -0x7fff0001;
  }
  return iVar1;
}



/* 4051fa68 FUN_4051fa68 */

/* Boundary evidence: original MIPS .pdata 4051fa68..4051fabf. Semantic name remains unreviewed. */

undefined4 FUN_4051fa68(int param_1,ushort *param_2)

{
  void *pvVar1;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_40537f64(*(int *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (param_2 != (ushort *)0x0) {
    pvVar1 = FUN_4052d908(param_2);
    *(void **)(param_1 + 0xc) = pvVar1;
  }
  return 0;
}



/* 4051fac0 FUN_4051fac0 */

/* Boundary evidence: original MIPS .pdata 4051fac0..4051fb1b. Semantic name remains unreviewed. */

void FUN_4051fac0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40512218;
  param_1[1] = &PTR_LAB_40512204;
  param_1[2] = &PTR_LAB_405121f4;
  IUnknown_AtomicRelease((void **)(param_1 + 5));
  FUN_4051f840(param_1);
  return;
}



/* 4051fb1c FUN_4051fb1c */

/* Boundary evidence: original MIPS .pdata 4051fb1c..4051fb43. Semantic name remains unreviewed. */

void FUN_4051fb1c(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40512268,param_2,param_3);
  return;
}



/* 4051fb44 FUN_4051fb44 */

/* Boundary evidence: original MIPS .pdata 4051fb44..4051fb5f. Semantic name remains unreviewed. */

void FUN_4051fb44(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



/* 4051fb60 FUN_4051fb60 */

ushort * FUN_4051fb60(ushort *param_1)

{
  if ((*param_1 < 3) || (param_1[1] != 0x361)) {
    param_1 = (ushort *)0x0;
  }
  return param_1;
}



/* 4051fbac FUN_4051fbac */

/* Boundary evidence: original MIPS .pdata 4051fbac..4051fbf3. Semantic name remains unreviewed. */

int FUN_4051fbac(ushort *param_1)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = FUN_4051fb60(param_1);
  if (puVar1 == (ushort *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)puVar1 + puVar1[2] + 6;
  }
  return iVar2;
}



/* 4051fbf4 FUN_4051fbf4 */

/* Boundary evidence: original MIPS .pdata 4051fbf4..4051fc6b. Semantic name remains unreviewed. */

ushort * FUN_4051fbf4(ushort *param_1)

{
  ushort *puVar1;
  
  if (((*param_1 < 0xc) || ((char)param_1[1] != 'a')) ||
     ((*(char *)((int)param_1 + 3) != -0x80 &&
      (puVar1 = FUN_4051fb60(param_1), puVar1 == (ushort *)0x0)))) {
    param_1 = (ushort *)0x0;
  }
  return param_1;
}



/* 4051fc6c FUN_4051fc6c */

/* Boundary evidence: original MIPS .pdata 4051fc6c..4051fce3. Semantic name remains unreviewed. */

undefined4 FUN_4051fc6c(wchar_t *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_4053abd8(param_1,param_2,param_1,(undefined4 *)0x0,(uint *)0x0);
  iVar2 = FUN_4053ad2c(param_1);
  if (((iVar1 < 0) || (iVar2 == -1)) || (iVar2 == 0xc)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 4051fce4 FUN_4051fce4 */

/* Boundary evidence: original MIPS .pdata 4051fce4..4051fd07. Semantic name remains unreviewed. */

void FUN_4051fce4(ushort *param_1,wchar_t *param_2)

{
  FUN_4052d308(param_1,0xbeef0001,param_2);
  return;
}



/* 4051fd08 FUN_4051fd08 */

/* Boundary evidence: original MIPS .pdata 4051fd08..4051fdcb. Semantic name remains unreviewed. */

ushort * FUN_4051fd08(short *param_1,int param_2)

{
  int iVar1;
  ushort *puVar2;
  
  if ((((param_1 == (short *)0x0) || (*param_1 != 0x14)) || ((char)param_1[1] != '\x1f')) ||
     (iVar1 = memcmp(param_1 + 2,&DAT_405162ec,0x10), iVar1 != 0)) {
    puVar2 = (ushort *)0x0;
  }
  else {
    puVar2 = (ushort *)(param_1 + 10);
    if ((param_2 == 0) ||
       ((puVar2 != (ushort *)0x0 &&
        ((char)*puVar2 != '\0' || *(char *)((int)param_1 + 0x15) != '\0')))) {
      puVar2 = FUN_4051fbf4(puVar2);
    }
  }
  return puVar2;
}



/* 4051fdcc FUN_4051fdcc */

/* Boundary evidence: original MIPS .pdata 4051fdcc..4051fdfb. Semantic name remains unreviewed. */

bool FUN_4051fdcc(short *param_1,int param_2)

{
  ushort *puVar1;
  
  puVar1 = FUN_4051fd08(param_1,param_2);
  return puVar1 != (ushort *)0x0;
}



/* 4051fdfc FUN_4051fdfc */

/* Boundary evidence: original MIPS .pdata 4051fdfc..4051fec7. Semantic name remains unreviewed. */

undefined1 * FUN_4051fdfc(uint param_1,wchar_t *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  size_t sVar3;
  undefined1 *puVar4;
  uint cchMax;
  uint uVar5;
  
  sVar3 = wcslen(param_2);
  cchMax = sVar3 + 1 & 0xffff;
  if (0x823 < cchMax) {
    cchMax = 0x824;
  }
  uVar5 = (cchMax + 5) * 2 & 0xffff;
  puVar4 = FUN_4052db6c(uVar5 + 2);
  if (puVar4 != (undefined1 *)0x0) {
    puVar4[1] = (char)(uVar5 >> 8);
    puVar1 = puVar4 + 7;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
    *puVar4 = (char)uVar5;
    puVar4[2] = 0x61;
    puVar4[3] = 0x80;
    puVar1 = puVar4 + 4;
    uVar5 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar5) =
         *(uint *)(puVar1 + -uVar5) & 0xffffffffU >> (4 - uVar5) * 8 | param_1 << uVar5 * 8;
    StrCpyNW((LPWSTR)(puVar4 + 8),param_2,cchMax);
  }
  return puVar4;
}



/* 4051fec8 FUN_4051fec8 */

/* Boundary evidence: original MIPS .pdata 4051fec8..4051ffa7. Semantic name remains unreviewed. */

ushort * FUN_4051fec8(uint param_1,LPCWSTR param_2)

{
  LPCWSTR pWVar1;
  ushort *puVar2;
  uint cchMax;
  WCHAR aWStack_1060 [2084];
  uint local_18;
  
  local_18 = DAT_40544354;
  pWVar1 = UrlGetLocationW(param_2);
  if (pWVar1 != (LPCWSTR)0x0) {
    cchMax = ((int)pWVar1 - (int)param_2 >> 1) + 1;
    if (0x823 < cchMax) {
      cchMax = 0x824;
    }
    StrCpyNW(aWStack_1060,param_2,cchMax);
    param_2 = aWStack_1060;
  }
  puVar2 = (ushort *)FUN_4051fdfc(param_1,param_2);
  if (((puVar2 != (ushort *)0x0) && (pWVar1 != (LPCWSTR)0x0)) && (*pWVar1 != L'\0')) {
    puVar2 = FUN_4052d308(puVar2,0xbeef0001,pWVar1);
  }
  FUN_40542538(local_18);
  return puVar2;
}



/* 4051ffa8 FUN_4051ffa8 */

/* Boundary evidence: original MIPS .pdata 4051ffa8..40520167. Semantic name remains unreviewed. */

undefined4 FUN_4051ffa8(undefined4 param_1,char *param_2,LPCWSTR param_3,IUnknown *param_4)

{
  BOOL BVar1;
  HWND local_68 [2];
  undefined4 local_60;
  undefined1 auStack_5c [28];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_1c;
  
  local_1c = DAT_40544354;
  if (param_2 != (char *)0x0) {
    if (((((*param_2 == 'f') || (*param_2 == 'F')) && ((param_2[1] == 't' || (param_2[1] == 'T'))))
        && (((param_2[2] == 'p' || (param_2[2] == 'P')) && (param_2[3] == '\0')))) &&
       (BVar1 = UrlIsW(param_3,URLIS_DIRECTORY), BVar1 != 0)) {
      local_60 = 0;
      memset(auStack_5c,0,0x1c);
      local_68[0] = (HWND)0x0;
      local_40 = 0;
      local_3c = 0x4b3813b;
      local_38 = 0x11d20a23;
      local_34 = 0x6000acb5;
      local_30 = 0xd45bdf97;
      IUnknown_GetWindow(param_4,local_68);
      if (local_68[0] != (HWND)0x0) {
        IUnknown_EnableModless(param_4,0);
        FUN_4053b3b4(local_68[0],&local_40,&local_60,0);
        IUnknown_EnableModless(param_4,1);
      }
    }
  }
  FUN_40542538(local_1c);
  return 0;
}



/* 40520168 FUN_40520168 */

/* Boundary evidence: original MIPS .pdata 40520168..405201cb. Semantic name remains unreviewed. */

int * FUN_40520168(int *param_1,uint param_2)

{
  int iVar1;
  SIZE_T SVar2;
  
  if (param_2 < 0x80000000) {
    SVar2 = param_2 << 1;
  }
  else {
    SVar2 = 0xffffffff;
  }
  iVar1 = FUN_4052d4e8(SVar2);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    param_2 = 0;
  }
  param_1[1] = param_2;
  return param_1;
}



/* 405201cc FUN_405201cc */

/* Boundary evidence: original MIPS .pdata 405201cc..4052025b. Semantic name remains unreviewed. */

undefined4 FUN_405201cc(undefined4 param_1,char *param_2,LPCWSTR param_3,int *param_4)

{
  IUnknown *local_18 [2];
  
  if (param_4 != (int *)0x0) {
    local_18[0] = (IUnknown *)0x0;
    (**(code **)(*param_4 + 0x28))(param_4,L"UI During Binding",local_18);
    if (local_18[0] != (IUnknown *)0x0) {
      FUN_4051ffa8(param_1,param_2,param_3,local_18[0]);
      (*local_18[0]->lpVtbl->Release)(local_18[0]);
    }
  }
  return 0;
}



/* 4052025c FUN_4052025c */

/* Boundary evidence: original MIPS .pdata 4052025c..4052047b. Semantic name remains unreviewed. */

int FUN_4052025c(int param_1,char *param_2,IBindCtx *param_3,undefined4 *param_4)

{
  LSTATUS LVar1;
  BOOL BVar2;
  int iVar3;
  size_t sVar4;
  int *local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  DWORD local_60 [2];
  CLSID CStack_58;
  undefined1 auStack_48 [40];
  uint local_20;
  
  local_20 = DAT_40544354;
  local_60[0] = 0x27;
  *param_4 = 0;
  if (param_2 != (char *)0x0) {
    LVar1 = SHGetValueA((HKEY)0x80000000,param_2,"ShellFolder",(DWORD *)0x0,auStack_48,local_60);
    if (LVar1 == 0) {
      GUIDFromStringA(auStack_48,&CStack_58);
      BVar2 = SHSkipJunction(param_3,&CStack_58);
      if (BVar2 == 0) {
        iVar3 = FUN_40516d94(&CStack_58,(LPUNKNOWN)0x0,1,(IID *)&DAT_405165ac,&local_70);
        if (-1 < iVar3) {
          iVar3 = (**(code **)*local_70)(local_70,&UNK_405165cc,&local_64);
          if (-1 < iVar3) {
            (**(code **)(*local_64 + 0x10))(local_64,*(undefined4 *)(param_1 + 0x10));
            (**(code **)(*local_64 + 8))();
          }
          iVar3 = (**(code **)*local_70)(local_70,&DAT_405165fc,&local_6c);
          if (-1 < iVar3) {
            sVar4 = strlen(param_2);
            iVar3 = FUN_4052ee84(param_2,sVar4 + 1,0x361,&local_68);
            if (-1 < iVar3) {
              iVar3 = (**(code **)(*local_6c + 0xc))(local_6c,local_68);
              (**(code **)(*local_68 + 8))();
            }
            (**(code **)(*local_6c + 8))();
            if (-1 < iVar3) {
              iVar3 = 0;
              *param_4 = local_70;
              goto LAB_40520454;
            }
          }
          (**(code **)(*local_70 + 8))();
        }
      }
      else {
        iVar3 = -0x7ff8fb39;
      }
      goto LAB_40520454;
    }
  }
  iVar3 = -0x7fffbffb;
LAB_40520454:
  FUN_40542538(local_20);
  return iVar3;
}



/* 4052047c FUN_4052047c */

/* Boundary evidence: original MIPS .pdata 4052047c..405204e7. Semantic name remains unreviewed. */

int FUN_4052047c(int param_1,ushort *param_2,IBindCtx *param_3,undefined4 *param_4)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = (char *)FUN_4051fbac(param_2);
  if (pcVar1 == (char *)0x0) {
    *param_4 = 0;
    iVar2 = 1;
  }
  else {
    iVar2 = FUN_4052025c(param_1,pcVar1,param_3,param_4);
  }
  return iVar2;
}



/* 405204e8 FUN_405204e8 */

/* Boundary evidence: original MIPS .pdata 405204e8..4052058f. Semantic name remains unreviewed. */

bool FUN_405204e8(LPCWSTR param_1,LPSTR param_2,int param_3)

{
  HRESULT HVar1;
  DWORD local_228 [2];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_40544354;
  local_228[0] = 0x104;
  HVar1 = UrlGetPartW(param_1,aWStack_220,local_228,1,0);
  if (HVar1 < 0) {
    FUN_40542538(local_18);
  }
  else {
    SHUnicodeToAnsi(aWStack_220,param_2,param_3);
    FUN_40542538(local_18);
  }
  return HVar1 >= 0;
}



/* 40520590 FUN_40520590 */

/* Boundary evidence: original MIPS .pdata 40520590..405205ff. Semantic name remains unreviewed. */

undefined4 FUN_40520590(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *local_10 [2];
  
  uVar2 = 0;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_40512fe4,local_10), -1 < iVar1)) {
    uVar2 = (**(code **)(*local_10[0] + 0xc))();
    (**(code **)(*local_10[0] + 8))();
  }
  return uVar2;
}



/* 40520600 FUN_40520600 */

undefined4 FUN_40520600(void)

{
  return 0x80004001;
}



/* 4052060c FUN_4052060c */

/* Boundary evidence: original MIPS .pdata 4052060c..40520633. Semantic name remains unreviewed. */

void FUN_4052060c(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_405122dc,param_2,param_3);
  return;
}



/* 40520634 FUN_40520634 */

/* Boundary evidence: original MIPS .pdata 40520634..4052064f. Semantic name remains unreviewed. */

void FUN_40520634(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40520650 FUN_40520650 */

/* Boundary evidence: original MIPS .pdata 40520650..40520743. Semantic name remains unreviewed. */

int FUN_40520650(int param_1,ushort *param_2,IBindCtx *param_3,undefined4 param_4,
                undefined4 *param_5)

{
  ushort *puVar1;
  int iVar2;
  int *local_28 [2];
  
  *param_5 = 0;
  puVar1 = FUN_4051fbf4(param_2);
  if (puVar1 == (ushort *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_4052047c(param_1,param_2,param_3,local_28);
    if (iVar2 == 1) {
      *param_5 = 0;
      iVar2 = -0x7fffbffe;
    }
    else if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],param_2,param_3,param_4,param_5);
      (**(code **)(*local_28[0] + 8))(local_28[0]);
    }
  }
  return iVar2;
}



/* 40520744 FUN_40520744 */

/* Boundary evidence: original MIPS .pdata 40520744..405207d3. Semantic name remains unreviewed. */

undefined4 FUN_40520744(ushort *param_1,ushort *param_2,undefined4 *param_3)

{
  char *_Str1;
  char *_Str2;
  int iVar1;
  
  _Str1 = (char *)FUN_4051fbac(param_1);
  _Str2 = (char *)FUN_4051fbac(param_2);
  if (_Str1 == (char *)0x0) {
    if (_Str2 != (char *)0x0) {
      return 0xffffffff;
    }
  }
  else {
    if (_Str2 == (char *)0x0) {
      return 1;
    }
    iVar1 = strcmp(_Str1,_Str2);
    if ((iVar1 == 0) && (param_3 != (undefined4 *)0x0)) {
      *param_3 = _Str1;
    }
  }
  return 0;
}



/* 405207d4 FUN_405207d4 */

/* Boundary evidence: original MIPS .pdata 405207d4..40520903. Semantic name remains unreviewed. */

uint FUN_405207d4(int param_1,undefined4 param_2,ushort *param_3,ushort *param_4)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  char *local_20;
  int *local_1c;
  
  local_20 = (char *)0x0;
  uVar1 = FUN_40520744(param_3,param_4,&local_20);
  if (uVar1 == 0) {
    if ((local_20 == (char *)0x0) ||
       (iVar2 = FUN_4052025c(param_1,local_20,(IBindCtx *)0x0,&local_1c), iVar2 != 0)) {
      puVar3 = FUN_4051fbf4(param_3);
      if (puVar3 == (ushort *)0x0) {
        uVar1 = 1;
      }
      else {
        puVar4 = FUN_4051fbf4(param_4);
        if (puVar4 == (ushort *)0x0) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = 1;
          if ((*(char *)((int)puVar3 + 3) == -0x80) && (*(char *)((int)puVar4 + 3) == -0x80)) {
            uVar1 = wcscmp((wchar_t *)(puVar3 + 4),(wchar_t *)(puVar4 + 4));
          }
        }
      }
    }
    else {
      uVar1 = (**(code **)(*local_1c + 0x1c))(local_1c,param_2,param_3,param_4);
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  return uVar1 & 0xffff;
}



/* 40520904 FUN_40520904 */

/* Boundary evidence: original MIPS .pdata 40520904..405209d3. Semantic name remains unreviewed. */

int FUN_40520904(int param_1,char *param_2,undefined4 *param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  ushort *puVar2;
  int *local_20 [2];
  
  if (param_2 == (char *)0x0) {
    puVar2 = FUN_4051fbf4((ushort *)*param_3);
    if (puVar2 == (ushort *)0x0) {
      iVar1 = -0x7ff8ffa9;
    }
    else {
      iVar1 = 0;
      *param_5 = *param_5 & 0x8400004;
    }
  }
  else {
    iVar1 = FUN_4052025c(param_1,param_2,(IBindCtx *)0x0,local_20);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_20[0] + 0x24))(local_20[0],param_4,param_3,param_5);
      (**(code **)(*local_20[0] + 8))(local_20[0]);
    }
  }
  return iVar1;
}



/* 405209d4 FUN_405209d4 */

/* Boundary evidence: original MIPS .pdata 405209d4..40520bd7. Semantic name remains unreviewed. */

undefined4 FUN_405209d4(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  char *pcVar1;
  HDPA hdpa;
  char *_Str2;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort *local_30;
  ushort *local_2c;
  
  if (*param_4 != 0) {
    if (param_2 == 0) {
      *param_4 = *param_4 & 0x20400004;
    }
    else if (param_2 == 1) {
      pcVar1 = (char *)FUN_4051fbac((ushort *)*param_3);
      FUN_40520904(param_1,pcVar1,param_3,1,param_4);
    }
    else {
      hdpa = DPA_Create(100);
      uVar5 = param_2;
      if (hdpa == (HDPA)0x0) {
        return 0x8007000e;
      }
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        DPA_InsertPtr(hdpa,0x7fffffff,(void *)*param_3);
        param_3 = param_3 + 1;
      }
      DPA_Sort(hdpa,FUN_40520744,0);
      local_30 = (ushort *)**(undefined4 **)(hdpa + 4);
      pcVar1 = (char *)0x0;
      iVar4 = 0;
      uVar5 = 0;
      if (*param_4 != 0) {
        iVar3 = 0;
        do {
          if (param_2 <= uVar5) break;
          local_2c = *(ushort **)(*(int *)(hdpa + 4) + iVar3);
          _Str2 = (char *)FUN_4051fbac(local_2c);
          if ((_Str2 != (char *)0x0) &&
             ((pcVar1 == (char *)0x0 || (iVar2 = strcmp(pcVar1,_Str2), iVar2 != 0)))) {
            FUN_40520904(param_1,pcVar1,&local_30,iVar4,param_4);
            local_30 = local_2c;
            iVar4 = 0;
            pcVar1 = _Str2;
          }
          iVar4 = iVar4 + 1;
          uVar5 = uVar5 + 1;
          iVar3 = iVar3 + 4;
        } while (*param_4 != 0);
        if (*param_4 != 0) {
          FUN_40520904(param_1,pcVar1,&local_30,iVar4,param_4);
        }
      }
      DPA_Destroy(hdpa);
    }
  }
  return 0;
}



/* 40520bd8 FUN_40520bd8 */

/* Boundary evidence: original MIPS .pdata 40520bd8..40520cab. Semantic name remains unreviewed. */

undefined4 FUN_40520bd8(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  char *_Str1;
  char *_Str2;
  int iVar1;
  uint uVar2;
  
  *param_3 = 0;
  if (param_2 != 0) {
    _Str1 = (char *)FUN_4051fbac((ushort *)*param_1);
    uVar2 = 1;
    if (1 < param_2) {
      do {
        param_1 = param_1 + 1;
        _Str2 = (char *)FUN_4051fbac((ushort *)*param_1);
        if ((_Str1 != _Str2) &&
           (((_Str1 == (char *)0x0 || (_Str2 == (char *)0x0)) ||
            (iVar1 = strcmp(_Str1,_Str2), iVar1 != 0)))) {
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2);
    }
    *param_3 = _Str1;
  }
  return 1;
}



/* 40520cac FUN_40520cac */

/* Boundary evidence: original MIPS .pdata 40520cac..40520dbf. Semantic name remains unreviewed. */

HRESULT FUN_40520cac(char *param_1,uint param_2,LPCWSTR param_3,DWORD param_4)

{
  int iVar1;
  HRESULT HVar2;
  DWORD local_resc;
  DWORD local_30 [2];
  wchar_t *local_28;
  size_t local_24;
  
  HVar2 = 0;
  local_resc = param_4;
  FUN_40520168((int *)&local_28,0x824);
  local_30[0] = local_resc;
  iVar1 = FUN_4052d3dc(param_1,-0x4110fffe,local_28,local_24);
  if (iVar1 != 0) {
    HVar2 = UrlCombineW(param_3,local_28,param_3,local_30,0);
  }
  if (((param_2 & 1) == 0) &&
     (iVar1 = FUN_4052d3dc(param_1,-0x4110ffff,local_28,local_24), iVar1 != 0)) {
    HVar2 = UrlCombineW(param_3,local_28,param_3,&local_resc,0);
  }
  operator_delete(local_28);
  return HVar2;
}



/* 40520dc0 FUN_40520dc0 */

/* Boundary evidence: original MIPS .pdata 40520dc0..40520ec7. Semantic name remains unreviewed. */

int FUN_40520dc0(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4,undefined4 param_5,
                undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  int *local_28 [2];
  
  *param_7 = 0;
  puVar2 = (ushort *)*param_4;
  iVar3 = -0x7fffbffe;
  if ((((puVar2 != (ushort *)0x0) && (iVar1 = FUN_40520bd8(param_4,param_3,local_28), iVar1 != 0))
      && (local_28[0] != (int *)0x0)) &&
     ((iVar3 = FUN_4052047c(param_1,puVar2,(IBindCtx *)0x0,local_28), iVar3 != 1 && (-1 < iVar3))))
  {
    iVar3 = (**(code **)(*local_28[0] + 0x28))
                      (local_28[0],param_2,1,param_4,param_5,param_6,param_7);
    (**(code **)(*local_28[0] + 8))(local_28[0]);
  }
  return iVar3;
}



/* 40520ec8 FUN_40520ec8 */

/* Boundary evidence: original MIPS .pdata 40520ec8..40520f53. Semantic name remains unreviewed. */

undefined4 FUN_40520ec8(int param_1,int *param_2)

{
  LPVOID *ppvVar1;
  undefined4 local_18;
  
  ppvVar1 = (LPVOID *)(param_1 + 0x14);
  if (*ppvVar1 == (LPVOID)0x0) {
    local_18 = FUN_40516d94((IID *)&DAT_405162ac,(LPUNKNOWN)0x0,1,(IID *)&DAT_4051661c,ppvVar1);
  }
  if (*ppvVar1 != (LPVOID)0x0) {
    *param_2 = (int)*ppvVar1;
    (**(code **)(*(int *)*ppvVar1 + 4))();
    local_18 = 0;
  }
  return local_18;
}



/* 40520f54 FUN_40520f54 */

/* Boundary evidence: original MIPS .pdata 40520f54..4052102b. Semantic name remains unreviewed. */

int FUN_40520f54(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_48 [2];
  undefined4 local_40;
  undefined1 auStack_3c [4];
  LPCWSTR local_38;
  
  iVar1 = FUN_40520ec8(param_1,(int *)local_48);
  if (-1 < iVar1) {
    local_40 = 0;
    memset(auStack_3c,0,0x24);
    iVar1 = (**(code **)(*local_48[0] + 0x14))(local_48[0],param_2,0x20000,&local_40);
    if ((iVar1 < 0) || (local_38 == (LPCWSTR)0x0)) {
      iVar1 = -0x7fffbffb;
    }
    else {
      iVar1 = FUN_4052e508(local_38,param_3);
      CoTaskMemFree(local_38);
    }
    (**(code **)(*local_48[0] + 8))(local_48[0]);
  }
  return iVar1;
}



/* 4052102c FUN_4052102c */

/* Boundary evidence: original MIPS .pdata 4052102c..40521167. Semantic name remains unreviewed. */

int FUN_4052102c(int param_1,ushort *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  ushort *puVar2;
  int *local_1070 [2];
  wchar_t awStack_1068 [2084];
  uint local_20;
  
  local_20 = DAT_40544354;
  iVar1 = FUN_4052047c(param_1,param_2,(IBindCtx *)0x0,local_1070);
  if (iVar1 == 1) {
    puVar2 = FUN_4051fbf4(param_2);
    if (puVar2 == (ushort *)0x0) {
      iVar1 = -0x7ff8ffa9;
    }
    else {
      if (*(char *)((int)puVar2 + 3) == -0x80) {
        StringCchCopyW(awStack_1068,0x824,(STRSAFE_LPCWSTR)(puVar2 + 4));
      }
      if ((param_3 != 0) || (iVar1 = FUN_40520f54(param_1,awStack_1068,param_4), iVar1 < 0)) {
        iVar1 = FUN_4052e508(awStack_1068,param_4);
      }
    }
  }
  else if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_1070[0] + 0x2c))(local_1070[0],param_2,param_3,param_4);
    (**(code **)(*local_1070[0] + 8))(local_1070[0]);
  }
  FUN_40542538(local_20);
  return iVar1;
}



/* 40521168 FUN_40521168 */

/* Boundary evidence: original MIPS .pdata 40521168..4052122f. Semantic name remains unreviewed. */

int FUN_40521168(int param_1,undefined4 param_2,ushort *param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *local_20 [2];
  
  iVar1 = FUN_4052047c(param_1,param_3,(IBindCtx *)0x0,local_20);
  if (iVar1 == 1) {
    iVar1 = -0x7fffbffb;
  }
  else if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_20[0] + 0x30))(local_20[0],param_2,param_3,param_4,param_5,param_6);
    (**(code **)(*local_20[0] + 8))(local_20[0]);
  }
  return iVar1;
}



/* 40521290 FUN_40521290 */

/* Boundary evidence: original MIPS .pdata 40521290..405213a3. Semantic name remains unreviewed. */

int FUN_40521290(void)

{
  LONG LVar1;
  int iVar2;
  int *local_18;
  int *local_14;
  
  if (DAT_405445a4 == 0) {
    iVar2 = FUN_40516d94((IID *)&DAT_405133e4,(LPUNKNOWN)0x0,1,(IID *)&DAT_405165ac,&local_18);
    if (-1 < iVar2) {
      iVar2 = (**(code **)*local_18)(local_18,&UNK_405165cc,&local_14);
      if (-1 < iVar2) {
        iVar2 = (**(code **)(*local_14 + 0x10))(local_14,PTR_DAT_40544330);
        if ((-1 < iVar2) &&
           (LVar1 = InterlockedCompareExchange(&DAT_405445a4,(LONG)local_18,0), LVar1 == 0)) {
          (**(code **)(*local_18 + 4))();
        }
        (**(code **)(*local_14 + 8))();
      }
      (**(code **)(*local_18 + 8))();
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* 405213a4 FUN_405213a4 */

/* Boundary evidence: original MIPS .pdata 405213a4..40521407. Semantic name remains unreviewed. */

int FUN_405213a4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_40521290();
  *param_1 = 0;
  if (-1 < iVar1) {
    (**(code **)(*DAT_405445a4 + 4))();
    *param_1 = DAT_405445a4;
  }
  return iVar1;
}



/* 40521408 FUN_40521408 */

/* Boundary evidence: original MIPS .pdata 40521408..40521483. Semantic name remains unreviewed. */

undefined4 FUN_40521408(ushort *param_1,ushort *param_2)

{
  size_t _Size;
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  _Size = FUN_40537d04(param_1);
  uVar3 = 1;
  sVar1 = FUN_40537d04(param_2);
  if ((_Size != sVar1) || (iVar2 = memcmp(param_1,param_2,_Size), iVar2 != 0)) {
    uVar3 = 0;
  }
  return uVar3;
}



/* 40521484 FUN_40521484 */

/* Boundary evidence: original MIPS .pdata 40521484..4052160b. Semantic name remains unreviewed. */

int FUN_40521484(ushort *param_1,uint *param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  ushort *local_20;
  int *local_1c;
  uint local_18 [2];
  
  local_18[0] = *param_2;
  if ((param_3 != 0) && ((local_18[0] & 0x8000000) != 0)) {
    local_18[0] = local_18[0] | 0x60000000;
  }
  if ((param_1 == (ushort *)0x0) || ((char)*param_1 == '\0' && *(char *)((int)param_1 + 1) == '\0'))
  {
    iVar2 = FUN_4053adec(&local_1c);
    local_20 = param_1;
  }
  else {
    bVar1 = FUN_4052d4b8(param_1);
    if ((CONCAT31(extraout_var,bVar1) != 0) &&
       (((uint)*param_1 + (int)param_1 == 0 ||
        (pcVar4 = (char *)((uint)*param_1 + (int)param_1), *pcVar4 == '\0' && pcVar4[1] == '\0'))))
    {
      *param_2 = *param_2 & 0x20000000;
      return 0;
    }
    iVar2 = FUN_4052ec70(param_1,&DAT_405165ac,(int *)&local_1c,&local_20);
  }
  if (-1 < iVar2) {
    if ((local_20 == (ushort *)0x0) ||
       (uVar3 = 1, (char)*local_20 == '\0' && *(char *)((int)local_20 + 1) == '\0')) {
      uVar3 = 0;
    }
    iVar2 = (**(code **)(*local_1c + 0x24))(local_1c,uVar3,&local_20,local_18);
    (**(code **)(*local_1c + 8))();
  }
  *param_2 = *param_2 & local_18[0];
  return iVar2;
}



/* 4052160c FUN_4052160c */

/* Boundary evidence: original MIPS .pdata 4052160c..40521627. Semantic name remains unreviewed. */

void FUN_4052160c(ushort *param_1,uint *param_2)

{
  FUN_40521484(param_1,param_2,1);
  return;
}



/* 40521628 FUN_40521628 */

undefined4 FUN_40521628(uint param_1,int param_2)

{
  if (param_2 == 0) {
    if ((param_1 & 0x28000000) == 0) {
      if ((param_1 & 0x40000000) != 0) {
        return 0;
      }
      return 2;
    }
  }
  else if ((param_1 & 0x68000000) == 0x48000000) {
    return 0;
  }
  return 1;
}



/* 40521680 FUN_40521680 */

/* Boundary evidence: original MIPS .pdata 40521680..405216c3. Semantic name remains unreviewed. */

undefined4 FUN_40521680(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0xc))();
  }
  return uVar1;
}



/* 405216c4 FUN_405216c4 */

/* Boundary evidence: original MIPS .pdata 405216c4..40521707. Semantic name remains unreviewed. */

undefined4 FUN_405216c4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x10))();
  }
  return uVar1;
}



/* 40521708 FUN_40521708 */

/* Boundary evidence: original MIPS .pdata 40521708..4052174b. Semantic name remains unreviewed. */

undefined4 FUN_40521708(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x14))();
  }
  return uVar1;
}



/* 4052174c FUN_4052174c */

/* Boundary evidence: original MIPS .pdata 4052174c..4052178f. Semantic name remains unreviewed. */

undefined4 FUN_4052174c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x18))();
  }
  return uVar1;
}



/* 40521790 FUN_40521790 */

/* Boundary evidence: original MIPS .pdata 40521790..405217d3. Semantic name remains unreviewed. */

undefined4 FUN_40521790(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x1c))();
  }
  return uVar1;
}



/* 405217d4 FUN_405217d4 */

/* Boundary evidence: original MIPS .pdata 405217d4..4052181b. Semantic name remains unreviewed. */

undefined4 FUN_405217d4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0;
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x20))();
  }
  return uVar1;
}



/* 4052181c FUN_4052181c */

/* Boundary evidence: original MIPS .pdata 4052181c..4052185f. Semantic name remains unreviewed. */

undefined4 FUN_4052181c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x24))();
  }
  return uVar1;
}



/* 40521860 FUN_40521860 */

/* Boundary evidence: original MIPS .pdata 40521860..405218a7. Semantic name remains unreviewed. */

undefined4 FUN_40521860(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0;
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x28))();
  }
  return uVar1;
}



/* 405218a8 FUN_405218a8 */

/* Boundary evidence: original MIPS .pdata 405218a8..405218ef. Semantic name remains unreviewed. */

undefined4 FUN_405218a8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0;
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))();
  }
  return uVar1;
}



/* 405218f0 FUN_405218f0 */

/* Boundary evidence: original MIPS .pdata 405218f0..40521933. Semantic name remains unreviewed. */

undefined4 FUN_405218f0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x10) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x10) + 0x30))();
  }
  return uVar1;
}



/* 40521948 FUN_40521948 */

/* Boundary evidence: original MIPS .pdata 40521948..4052196f. Semantic name remains unreviewed. */

void FUN_40521948(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40512348,param_2,param_3);
  return;
}



/* 40521980 FUN_40521980 */

/* Boundary evidence: original MIPS .pdata 40521980..405219eb. Semantic name remains unreviewed. */

undefined4 * FUN_40521980(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40512300;
  param_1[1] = &PTR_LAB_405122ec;
  IUnknown_AtomicRelease((void **)(param_1 + 4));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40521ab4 FUN_40521ab4 */

/* Boundary evidence: original MIPS .pdata 40521ab4..40521b0b. Semantic name remains unreviewed. */

LONG FUN_40521ab4(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4051f840(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 40521b0c FUN_40521b0c */

/* Boundary evidence: original MIPS .pdata 40521b0c..40521b7f. Semantic name remains unreviewed. */

undefined4 FUN_40521b0c(int param_1,uint param_2,uint *param_3)

{
  ushort *puVar1;
  
  puVar1 = FUN_4051fd08(*(short **)(param_1 + 8),1);
  *param_3 = param_2 & 0x3fb23;
  if (puVar1 != (ushort *)0x0) {
    *param_3 = param_2 & 0x3ff63;
  }
  return 0;
}



/* 40521b80 FUN_40521b80 */

/* Boundary evidence: original MIPS .pdata 40521b80..40521bd7. Semantic name remains unreviewed. */

LONG FUN_40521b80(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4051fac0(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 40521bd8 FUN_40521bd8 */

/* Boundary evidence: original MIPS .pdata 40521bd8..40521e23. Semantic name remains unreviewed. */

undefined4
FUN_40521bd8(int param_1,undefined4 param_2,IBindCtx *param_3,STRSAFE_LPCWSTR param_4,
            undefined4 param_5,undefined4 *param_6,uint *param_7)

{
  STRSAFE_LPWSTR pszUrl;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  ushort *puVar4;
  undefined4 uVar5;
  STRSAFE_LPWSTR local_140;
  size_t local_13c;
  undefined4 local_138;
  size_t local_134;
  CHAR aCStack_130 [260];
  uint local_2c;
  
  local_2c = DAT_40544354;
  uVar5 = 0x80004005;
  local_138 = param_5;
  FUN_40520168((int *)&local_140,0x824);
  FUN_40520590(param_3);
  pszUrl = local_140;
  StringCchCopyW(local_140,local_13c,param_4);
  iVar2 = FUN_4052d700(pszUrl);
  if ((iVar2 == 0) &&
     ((iVar2 = FUN_4051fc6c(pszUrl,0), iVar2 != 0 || (iVar2 = FUN_40522fa8(), iVar2 != 0)))) {
    local_134 = local_13c;
    iVar2 = FUN_4052d610((int *)param_3,L"Parse Internet Dont Escape Spaces");
    if (iVar2 == 0) {
      UrlEscapeW(pszUrl,pszUrl,&local_134,0x4000000);
    }
    bVar1 = FUN_405204e8(pszUrl,aCStack_130,0x104);
    FUN_405201cc(param_1,aCStack_130,pszUrl,(int *)param_3);
    if (((iVar2 != 0) || (CONCAT31(extraout_var,bVar1) == 0)) ||
       (iVar2 = FUN_4052025c(param_1,aCStack_130,param_3,&local_140), iVar2 != 0)) {
      uVar3 = FUN_40520590(param_3);
      puVar4 = FUN_4051fec8(uVar3,pszUrl);
      *param_6 = puVar4;
      if (puVar4 == (ushort *)0x0) {
        uVar5 = 0x8007000e;
      }
      else {
        if (param_7 != (uint *)0x0) {
          puVar4 = FUN_4051fbf4(puVar4);
          if (puVar4 == (ushort *)0x0) {
            uVar5 = 0x80070057;
            goto LAB_40521de0;
          }
          *param_7 = *param_7 & 0x8400004;
        }
        uVar5 = 0;
      }
    }
    else {
      uVar5 = (**(code **)(*(int *)local_140 + 0xc))
                        (local_140,param_2,param_3,param_4,local_138,param_6,param_7);
      (**(code **)(*(int *)local_140 + 8))(local_140);
    }
  }
LAB_40521de0:
  operator_delete(pszUrl);
  FUN_40542538(local_2c);
  return uVar5;
}



/* 40521e24 FUN_40521e24 */

/* Boundary evidence: original MIPS .pdata 40521e24..40521e7f. Semantic name remains unreviewed. */

LONG FUN_40521e24(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    *param_1 = &PTR_FUN_405122c0;
    operator_delete(param_1);
  }
  return LVar1;
}



/* 40521e80 FUN_40521e80 */

/* Boundary evidence: original MIPS .pdata 40521e80..40521ee7. Semantic name remains unreviewed. */

undefined4 FUN_40521e80(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_a3;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_405122c0;
    puVar1[1] = 1;
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *in_a3 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40521ee8 FUN_40521ee8 */

/* Boundary evidence: original MIPS .pdata 40521ee8..405220f7. Semantic name remains unreviewed. */

HRESULT FUN_40521ee8(LPCITEMIDLIST param_1,uint param_2,uint param_3,LPCWSTR param_4,DWORD param_5,
                    uint *param_6)

{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  undefined3 extraout_var;
  int *local_130;
  LPCITEMIDLIST local_12c;
  STRRET SStack_128;
  
  if (param_4 != (LPCWSTR)0x0) {
    *param_4 = L'\0';
  }
  puVar2 = FUN_4051fd08((short *)param_1,0);
  if (puVar2 != (ushort *)0x0) {
    iVar3 = FUN_40521290();
    if (iVar3 < 0) {
      return iVar3;
    }
    if ((param_4 != (LPCWSTR)0x0) &&
       (iVar3 = (**(code **)(*DAT_405445a4 + 0x2c))
                          (DAT_405445a4,(param_1->mkid).abID + ((param_1->mkid).cb - 2),param_2,
                           &SStack_128), -1 < iVar3)) {
      StrRetToBufW(&SStack_128,param_1,param_4,param_5);
    }
    if (param_6 != (uint *)0x0) {
      iVar3 = FUN_40521484((ushort *)param_1,param_6,1);
    }
    goto LAB_4052209c;
  }
  bVar1 = FUN_4052d4b8((ushort *)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return -0x7fffbffb;
  }
  iVar3 = FUN_4052ec70((ushort *)param_1,&DAT_405165ac,(int *)&local_130,&local_12c);
  if (iVar3 < 0) {
    return iVar3;
  }
  if (param_4 == (LPCWSTR)0x0) {
LAB_40522058:
    if ((-1 < iVar3) && (param_6 != (uint *)0x0)) {
      iVar3 = (**(code **)(*local_130 + 0x24))(local_130,1,&local_12c);
    }
  }
  else {
    iVar3 = (**(code **)(*local_130 + 0x2c))(local_130,local_12c,param_2,&SStack_128);
    if (-1 < iVar3) {
      iVar3 = StrRetToBufW(&SStack_128,local_12c,param_4,param_5);
      goto LAB_40522058;
    }
  }
  (**(code **)(*local_130 + 8))();
LAB_4052209c:
  if (((-1 < iVar3) && (param_4 != (LPCWSTR)0x0)) && ((param_2 & 0x8000) != 0)) {
    iVar3 = FUN_40520cac((char *)param_1,param_3,param_4,param_5);
  }
  return iVar3;
}



/* 405220f8 FUN_405220f8 */

/* Boundary evidence: original MIPS .pdata 405220f8..40522123. Semantic name remains unreviewed. */

void FUN_405220f8(LPCITEMIDLIST param_1,uint param_2,LPCWSTR param_3,DWORD param_4,uint *param_5)

{
  FUN_40521ee8(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



/* 40522124 FUN_40522124 */

/* Boundary evidence: original MIPS .pdata 40522124..4052218b. Semantic name remains unreviewed. */

undefined4 * FUN_40522124(undefined4 *param_1,IUnknown *param_2,undefined4 param_3)

{
  param_1[1] = &PTR_LAB_40512334;
  *param_1 = &PTR_FUN_40512300;
  param_1[2] = 1;
  param_1[1] = &PTR_LAB_405122ec;
  param_1[3] = param_3;
  param_1[4] = (IUnknown *)0x0;
  IUnknown_Set((IUnknown **)(param_1 + 4),param_2);
  return param_1;
}



/* 4052218c FUN_4052218c */

/* Boundary evidence: original MIPS .pdata 4052218c..405221bb. Semantic name remains unreviewed. */

int FUN_4052218c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2] + -1;
  param_1[2] = iVar1;
  if (iVar1 < 1) {
    FUN_40521980(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 405221bc FUN_405221bc */

/* Boundary evidence: original MIPS .pdata 405221bc..40522457. Semantic name remains unreviewed. */

int FUN_405221bc(undefined4 param_1,LPCWSTR param_2,IUnknown *param_3,undefined4 *param_4)

{
  STRSAFE_LPWSTR pszDest;
  STRSAFE_LPWSTR pwVar1;
  bool bVar2;
  size_t sVar3;
  undefined3 extraout_var;
  int iVar4;
  void *pvVar5;
  LPWSTR pWVar6;
  int iVar7;
  STRSAFE_LPWSTR local_50;
  size_t local_4c;
  DWORD local_48 [2];
  LPWSTR local_40;
  DWORD local_3c;
  undefined **local_38;
  undefined **local_34;
  void *apvStack_28 [2];
  
  iVar7 = 0;
  FUN_40520168((int *)&local_50,0x824);
  FUN_40520168((int *)&local_40,0x104);
  local_48[0] = local_3c;
  FUN_40522124(&local_38,param_3,param_1);
  *param_4 = 0;
  sVar3 = wcslen(param_2);
  if ((sVar3 == 0) || (0x823 < sVar3)) {
    local_38 = &PTR_FUN_40512300;
    local_34 = &PTR_LAB_405122ec;
    IUnknown_AtomicRelease(apvStack_28);
    operator_delete(local_40);
    operator_delete(local_50);
    return -0x7fffbffb;
  }
  bVar2 = FUN_4052d6cc(param_2);
  if ((CONCAT31(extraout_var,bVar2) != 0) &&
     (iVar7 = PathCreateFromUrlW(param_2,local_40,local_48,0), -1 < iVar7)) {
    param_2 = local_40;
  }
  iVar4 = FUN_4052d700(param_2);
  pszDest = local_50;
  if (iVar4 == 0) {
    iVar4 = FUN_4053ad2c(param_2);
    if (iVar4 != 0xc) {
      StringCchCopyW(pszDest,local_4c,param_2);
      iVar7 = FUN_405213a4(&local_50);
      pwVar1 = local_50;
      if (-1 < iVar7) {
        iVar7 = (**(code **)(*(int *)local_50 + 0xc))(local_50,0,&local_38,pszDest,0,&local_50,0);
        if (-1 < iVar7) {
          pvVar5 = FUN_40537e34((ushort *)PTR_DAT_40544330,(ushort *)local_50);
          *param_4 = pvVar5;
          if (pvVar5 == (void *)0x0) {
            iVar7 = -0x7ff8fff2;
          }
          FUN_40537f64((int)local_50);
        }
        (**(code **)(*(int *)pwVar1 + 8))(pwVar1);
      }
      goto LAB_405223b0;
    }
  }
  else {
    PathCanonicalizeW(local_50,param_2);
    pWVar6 = StrChrW(local_50,L'*');
    param_2 = local_50;
    if ((pWVar6 != (LPWSTR)0x0) || (pWVar6 = StrChrW(local_50,L'?'), pWVar6 != (LPWSTR)0x0)) {
      iVar7 = -0x7fffbffb;
    }
  }
  if (-1 < iVar7) {
    iVar7 = FUN_40537f88(param_2,param_4,0);
  }
LAB_405223b0:
  local_38 = &PTR_FUN_40512300;
  local_34 = &PTR_LAB_405122ec;
  IUnknown_AtomicRelease(apvStack_28);
  operator_delete(local_40);
  operator_delete(pszDest);
  return iVar7;
}



/* 40522458 FUN_40522458 */

/* Boundary evidence: original MIPS .pdata 40522458..40522693. Semantic name remains unreviewed. */

int FUN_40522458(undefined4 param_1,LPCWSTR param_2,IUnknown *param_3,undefined4 *param_4)

{
  wchar_t *pwVar1;
  bool bVar2;
  undefined3 extraout_var;
  HRESULT HVar3;
  BOOL BVar4;
  int iVar5;
  ushort *puVar6;
  STRSAFE_LPWSTR pwVar7;
  LPCWSTR pWVar8;
  DWORD local_40 [2];
  wchar_t *local_38;
  int local_34;
  STRSAFE_LPWSTR local_30;
  wchar_t *local_2c;
  
  pWVar8 = (LPCWSTR)0x0;
  FUN_40520168((int *)&local_30,0x824);
  FUN_40520168((int *)&local_38,0x824);
  pwVar1 = local_38;
  *local_38 = L'\0';
  bVar2 = FUN_4052d6cc(param_2);
  if (CONCAT31(extraout_var,bVar2) == 0) {
LAB_405225b8:
    StringCchCopyW(local_30,(size_t)local_2c,param_2);
    pwVar7 = local_30;
  }
  else {
    local_40[0] = local_34 - 1;
    pWVar8 = UrlGetLocationW(param_2);
    HVar3 = UrlGetPartW(param_2,pwVar1 + 1,local_40,6,0);
    if ((-1 < HVar3) && (local_40[0] != 0)) {
      *pwVar1 = L'?';
    }
    local_38 = local_2c;
    HVar3 = PathCreateFromUrlW(param_2,local_30,(LPDWORD)&local_38,0);
    if (HVar3 < 0) goto LAB_405225b8;
    pwVar7 = local_30;
    if (local_38 == (wchar_t *)0x0) {
      *local_30 = L'\\';
      local_30[1] = L'\0';
    }
    else {
      iVar5 = FUN_4053ad2c(local_30);
      if ((iVar5 != -1) && (BVar4 = PathIsUNCW(local_30), BVar4 == 0)) {
        iVar5 = -0x7fffbffb;
        goto LAB_40522650;
      }
    }
  }
  iVar5 = FUN_405221bc(param_1,pwVar7,param_3,param_4);
  local_30 = pwVar7;
  if (iVar5 < 0) goto LAB_40522650;
  if (pWVar8 == (wchar_t *)0x0) {
LAB_40522618:
    if (iVar5 < 0) goto LAB_40522650;
  }
  else {
    puVar6 = FUN_4052d308((ushort *)*param_4,0xbeef0001,pWVar8);
    *param_4 = puVar6;
    if (puVar6 == (ushort *)0x0) {
      iVar5 = -0x7ff8fff2;
      goto LAB_40522618;
    }
    iVar5 = 0;
  }
  if (*pwVar1 == L'?') {
    puVar6 = FUN_4052d308((ushort *)*param_4,0xbeef0002,pwVar1);
    iVar5 = 0;
    *param_4 = puVar6;
    if (puVar6 == (ushort *)0x0) {
      iVar5 = -0x7ff8fff2;
    }
  }
LAB_40522650:
  operator_delete(pwVar1);
  operator_delete(local_30);
  return iVar5;
}



/* 405226f8 FUN_405226f8 */

/* Boundary evidence: original MIPS .pdata 405226f8..4052276f. Semantic name remains unreviewed. */

undefined4 * FUN_405226f8(undefined4 *param_1,ushort *param_2)

{
  void *pvVar1;
  
  *param_1 = &PTR_FUN_4051217c;
  param_1[1] = &PTR_LAB_40512168;
  param_1[2] = &PTR_LAB_40512158;
  param_1[3] = 1;
  param_1[4] = 0;
  FUN_40516d54();
  if (param_2 != (ushort *)0x0) {
    pvVar1 = FUN_4052d908(param_2);
    param_1[4] = pvVar1;
  }
  return param_1;
}



/* 40522770 FUN_40522770 */

/* Boundary evidence: original MIPS .pdata 40522770..405227d3. Semantic name remains unreviewed. */

undefined4 FUN_40522770(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_405226f8(puVar1,(ushort *)0x0);
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    *param_2 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 405227d4 FUN_405227d4 */

/* Boundary evidence: original MIPS .pdata 405227d4..40522823. Semantic name remains unreviewed. */

undefined4 * FUN_405227d4(undefined4 *param_1,ushort *param_2)

{
  FUN_405226f8(param_1,param_2);
  *param_1 = &PTR_FUN_40512218;
  param_1[1] = &PTR_LAB_40512204;
  param_1[2] = &PTR_LAB_405121f4;
  return param_1;
}



/* 40522824 FUN_40522824 */

/* Boundary evidence: original MIPS .pdata 40522824..40522a77. Semantic name remains unreviewed. */

int FUN_40522824(LPCWSTR param_1,LPCITEMIDLIST param_2,IBindCtx *param_3,void *param_4,
                undefined4 *param_5)

{
  LPCWSTR pWVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  LPCWSTR pWVar6;
  LPCITEMIDLIST pIVar7;
  LPCWSTR local_138;
  UINT local_134;
  STRRET SStack_130;
  
  local_138 = (LPCWSTR)0x0;
  *param_5 = 0;
  puVar2 = FUN_4051fbf4((ushort *)param_2);
  if (puVar2 != (ushort *)0x0) {
    iVar3 = FUN_4052047c((int)param_1,(ushort *)param_2,param_3,&local_138);
    pWVar1 = local_138;
    if ((iVar3 != 0) ||
       (iVar3 = (**(code **)(*(int *)local_138 + 0x14))(local_138,param_2,param_3,param_4,param_5),
       iVar3 == -0x7ff8fb39)) {
      if (pWVar1 == (LPCWSTR)0x0) {
        iVar3 = *(int *)param_1;
        pWVar6 = param_1;
      }
      else {
        iVar3 = *(int *)pWVar1;
        pWVar6 = pWVar1;
      }
      iVar3 = (**(code **)(iVar3 + 0x2c))(pWVar6,param_2,0x8000,&SStack_130);
      FUN_40520168((int *)&local_138,0x824);
      pWVar6 = local_138;
      if ((-1 < iVar3) &&
         (iVar3 = StrRetToBufW(&SStack_130,param_2,local_138,local_134), -1 < iVar3)) {
        iVar3 = memcmp(&DAT_4051663c,param_4,0x10);
        if (iVar3 == 0) {
          iVar3 = FUN_4053b0e4(0,pWVar6,param_5);
        }
        else {
          iVar3 = -0x7ff8fff2;
          pIVar7 = (LPCITEMIDLIST)0x0;
          if (pWVar1 != (LPCWSTR)0x0) {
            param_2 = (LPCITEMIDLIST)FUN_4051fec8(0,pWVar6);
            pIVar7 = param_2;
          }
          if (param_2 != (LPCITEMIDLIST)0x0) {
            puVar2 = FUN_40537e34(*(ushort **)(param_1 + 8),(ushort *)param_2);
            if (puVar2 != (ushort *)0x0) {
              puVar4 = (undefined4 *)FUN_4052d4e8(0x14);
              if (puVar4 == (undefined4 *)0x0) {
                piVar5 = (int *)0x0;
              }
              else {
                piVar5 = FUN_405226f8(puVar4,puVar2);
              }
              if (piVar5 != (int *)0x0) {
                iVar3 = (**(code **)*piVar5)(piVar5,param_4,param_5);
                (**(code **)(*piVar5 + 8))(piVar5);
              }
              FUN_40537f64((int)puVar2);
            }
            FUN_40537f64((int)pIVar7);
          }
        }
      }
      operator_delete(pWVar6);
    }
    if (pWVar1 != (LPCWSTR)0x0) {
      (**(code **)(*(int *)pWVar1 + 8))(pWVar1);
    }
    return iVar3;
  }
  return -0x7ff8ffa9;
}



/* 40522a78 FUN_40522a78 */

/* Boundary evidence: original MIPS .pdata 40522a78..40522b13. Semantic name remains unreviewed. */

undefined4 FUN_40522a78(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_405227d4(puVar1,(ushort *)0x0);
  }
  if (piVar2 == (int *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,&DAT_405162fc,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 40522b14 FUN_40522b14 */

/* Boundary evidence: original MIPS .pdata 40522b14..40522b47. Semantic name remains unreviewed. */

void FUN_40522b14(LPCITEMIDLIST param_1,LPCWSTR param_2,uint param_3)

{
  FUN_40521ee8(param_1,param_3,0,param_2,0x824,(uint *)0x0);
  return;
}



/* 40522b48 FUN_40522b48 */

/* Boundary evidence: original MIPS .pdata 40522b48..40522e03. Semantic name remains unreviewed. */

int FUN_40522b48(int param_1,ushort *param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  bool bVar1;
  bool bVar2;
  ushort *puVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int *local_30;
  uint local_2c;
  
  *param_5 = 0;
  if ((param_2 == (ushort *)0x0) || ((char)*param_2 == '\0' && *(char *)((int)param_2 + 1) == '\0'))
  {
    iVar4 = FUN_4053adec(&local_30);
    if (iVar4 < 0) {
      return iVar4;
    }
LAB_40522d8c:
    iVar4 = (**(code **)*local_30)(local_30,param_4,param_5);
LAB_40522da0:
    iVar8 = *local_30;
    piVar6 = local_30;
  }
  else {
    puVar3 = FUN_4051fd08((short *)param_2,1);
    if (puVar3 != (ushort *)0x0) {
      bVar1 = true;
LAB_40522bd0:
      local_30 = (int *)0x0;
      iVar4 = -0x7fffbffb;
      if (bVar1) {
        iVar4 = FUN_405213a4(&local_30);
      }
      if (iVar4 < 0) {
        return iVar4;
      }
      pcVar7 = (char *)((uint)*param_2 + (int)param_2);
      if ((pcVar7 == (char *)0x0) || (*pcVar7 == '\0' && pcVar7[1] == '\0')) goto LAB_40522d8c;
      iVar4 = (**(code **)(*local_30 + 0x14))(local_30,pcVar7,param_3,param_4,param_5);
      goto LAB_40522da0;
    }
    bVar1 = false;
    bVar2 = FUN_4052d4b8(param_2);
    if (CONCAT31(extraout_var,bVar2) != 0) goto LAB_40522bd0;
    local_2c = 0x68000000;
    iVar4 = FUN_40521484(param_2,&local_2c,param_1);
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = FUN_40521628(local_2c,param_1);
    if (iVar4 != 0) {
      if (iVar4 != 1) {
        return -0x7fffbffb;
      }
      iVar4 = FUN_4053adec(&local_30);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar4 = (**(code **)(*local_30 + 0x14))(local_30,param_2,param_3,param_4,param_5);
      goto LAB_40522da0;
    }
    puVar5 = (undefined4 *)FUN_4052d4e8(0x14);
    if (puVar5 == (undefined4 *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = FUN_405226f8(puVar5,(ushort *)0x0);
    }
    if (piVar6 == (int *)0x0) {
      iVar4 = -0x7ff8fff2;
      goto LAB_40522db8;
    }
    iVar4 = (**(code **)(piVar6[1] + 0x10))(piVar6 + 1,param_2);
    if (-1 < iVar4) {
      iVar4 = (**(code **)*piVar6)(piVar6,param_4,param_5);
    }
    iVar8 = *piVar6;
  }
  (**(code **)(iVar8 + 8))(piVar6);
LAB_40522db8:
  if ((-1 < iVar4) && (*param_5 == 0)) {
    iVar4 = -0x7fffbffb;
  }
  return iVar4;
}



/* 40522e04 FUN_40522e04 */

/* Boundary evidence: original MIPS .pdata 40522e04..40522e2f. Semantic name remains unreviewed. */

void FUN_40522e04(ushort *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  FUN_40522b48(1,param_1,param_2,param_3,param_4);
  return;
}



/* 40522e30 FUN_40522e30 */

/* Boundary evidence: original MIPS .pdata 40522e30..40522e5f. Semantic name remains unreviewed. */

void FUN_40522e30(ushort *param_1,undefined4 param_2,int *param_3)

{
  FUN_40522b48(0,param_1,param_2,&DAT_405165ac,param_3);
  return;
}



/* 40522e60 FUN_40522e60 */

/* Boundary evidence: original MIPS .pdata 40522e60..40522e7f. Semantic name remains unreviewed. */

void FUN_40522e60(undefined4 param_1,LPCWSTR param_2,undefined4 *param_3)

{
  FUN_40522458(param_1,param_2,(IUnknown *)0x0,param_3);
  return;
}



/* 40522e80 FUN_40522e80 */

/* Boundary evidence: original MIPS .pdata 40522e80..40522fa7. Semantic name remains unreviewed. */

undefined4 FUN_40522e80(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int *local_res8 [2];
  
  local_res8[0] = param_3;
  if (param_3 == (int *)0x0) {
    FUN_405379a8((undefined4 *)0x0,local_res8);
  }
  else {
    (**(code **)(*param_3 + 4))(param_3);
  }
  if (local_res8[0] != (int *)0x0) {
    (**(code **)*local_res8[0])(local_res8[0],&DAT_405162cc,param_1 + 0x68);
    (**(code **)*local_res8[0])(local_res8[0],&DAT_40512b14,param_1 + 0x6c);
    (**(code **)*local_res8[0])(local_res8[0],&UNK_405135d4,param_1 + 0x70);
    (**(code **)*local_res8[0])(local_res8[0],&DAT_405164bc,param_1 + 0x13c);
    (**(code **)*local_res8[0])(local_res8[0],&DAT_4051664c,param_1 + 100);
    *(int **)(param_1 + 0xbc) = local_res8[0];
  }
  if (*(int *)(param_1 + 100) == 0) {
    (**(code **)(*(int *)(param_1 + -0x14) + 8))();
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0x5c) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40522fa8 FUN_40522fa8 */

undefined4 FUN_40522fa8(void)

{
  return 0;
}



/* 40522fb0 FUN_40522fb0 */

/* Boundary evidence: original MIPS .pdata 40522fb0..405231e3. Semantic name remains unreviewed. */

void FUN_40522fb0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40513c3c;
  param_1[4] = &PTR_LAB_40513bf4;
  param_1[5] = &PTR_LAB_40513a70;
  param_1[6] = &PTR_LAB_40513a60;
  param_1[7] = &PTR_LAB_40513a4c;
  param_1[8] = &PTR_LAB_40513a34;
  param_1[9] = &PTR_LAB_40513a10;
  param_1[10] = &PTR_LAB_40513a00;
  param_1[0xb] = &PTR_LAB_405139ec;
  param_1[0xc] = &PTR_LAB_405139cc;
  param_1[0xd] = &PTR_LAB_405139b8;
  param_1[0xe] = &PTR_LAB_405139a4;
  param_1[0xf] = &PTR_LAB_40513990;
  param_1[0x12] = &PTR_LAB_40513978;
  param_1[0x13] = &PTR_LAB_40513968;
  param_1[0x14] = &PTR_LAB_4051390c;
  param_1[0x15] = &PTR_LAB_405138fc;
  param_1[0x16] = &PTR_LAB_405138dc;
  param_1[0x17] = &PTR_LAB_405138bc;
  FUN_4052f050((int)param_1,(void **)(param_1 + 0x18));
  FUN_4052f050((int)param_1,(void **)(param_1 + 0x19));
  FUN_4052f050((int)param_1,(void **)(param_1 + 0x1a));
  FUN_4052f050((int)param_1,(void **)(param_1 + 0x1b));
  IUnknown_AtomicRelease((void **)(param_1 + 0x1f));
  IUnknown_AtomicRelease((void **)(param_1 + 0x20));
  IUnknown_AtomicRelease((void **)(param_1 + 0x21));
  IUnknown_AtomicRelease((void **)(param_1 + 0x1e));
  IUnknown_AtomicRelease((void **)(param_1 + 0x54));
  IUnknown_AtomicRelease((void **)(param_1 + 0x34));
  IUnknown_AtomicRelease((void **)(param_1 + 0x40));
  IUnknown_AtomicRelease((void **)(param_1 + 0x52));
  IUnknown_AtomicRelease((void **)(param_1 + 0x53));
  IUnknown_AtomicRelease((void **)(param_1 + 0x3b));
  IUnknown_AtomicRelease((void **)(param_1 + 0x3c));
  IUnknown_AtomicRelease((void **)(param_1 + 0x1d));
  IUnknown_AtomicRelease((void **)(param_1 + 0x3e));
  IUnknown_AtomicRelease((void **)(param_1 + 0x3f));
  piVar1 = (int *)param_1[0x41];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,0);
    (**(code **)(*(int *)param_1[0x41] + 8))();
  }
  FUN_4053a234(param_1 + 0xf);
  FUN_4052f040(param_1);
  return;
}



/* 405231e4 FUN_405231e4 */

/* Boundary evidence: original MIPS .pdata 405231e4..4052320b. Semantic name remains unreviewed. */

void FUN_405231e4(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40513c70,param_2,param_3);
  return;
}



/* 4052320c FUN_4052320c */

/* WARNING: Removing unreachable block (ram,0x4052325c) */
/* WARNING: Removing unreachable block (ram,0x40523274) */
/* WARNING: Removing unreachable block (ram,0x40523290) */
/* WARNING: Removing unreachable block (ram,0x405232ac) */
/* WARNING: Removing unreachable block (ram,0x405232b0) */
/* Boundary evidence: original MIPS .pdata 4052320c..405232df. Semantic name remains unreviewed. */

undefined4 FUN_4052320c(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = DAT_40544354;
  if (param_2 != (int *)0x0) {
    FUN_4052d52c(param_2);
  }
  FUN_40542538(uVar1);
  return 0;
}



/* 405232e0 FUN_405232e0 */

/* Boundary evidence: original MIPS .pdata 405232e0..4052338b. Semantic name remains unreviewed. */

bool FUN_405232e0(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  
  local_10 = DAT_40544354;
  local_20 = 0x3f8a62f;
  local_1c = 0x12d;
  local_1a = 0x46d8;
  local_18 = 0x95;
  local_17 = 0x41;
  local_16 = 0xf0;
  local_15 = 0x4d;
  local_14 = 0x12;
  local_13 = 3;
  local_12 = 0xac;
  local_11 = 0xd8;
  iVar1 = memcmp(param_2,&local_20,0x10);
  FUN_40542538(local_10);
  return iVar1 == 0;
}



/* 4052338c FUN_4052338c */

/* Boundary evidence: original MIPS .pdata 4052338c..405233cf. Semantic name remains unreviewed. */

void FUN_4052338c(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x98);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,0,0x17,2,0,0);
  }
  return;
}



/* 405233d0 FUN_405233d0 */

undefined4 FUN_405233d0(void)

{
  return 1;
}



/* 405233d8 FUN_405233d8 */

/* Boundary evidence: original MIPS .pdata 405233d8..405235ab. Semantic name remains unreviewed. */

void FUN_405233d8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *local_20;
  int *local_1c;
  
  piVar4 = (int *)(param_1 + 0x14);
  (**(code **)(*piVar4 + 0x1c))(piVar4,&local_20);
  iVar1 = FUN_4052d788((int *)(param_1 + 0x18),param_1 + 0x10);
  if (local_20 == (int *)0x0) goto LAB_4052357c;
  local_1c = (int *)0x0;
  iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,piVar4,0,0);
  if ((((iVar2 < 0) && (iVar1 != 0)) && (piVar3 = *(int **)(param_1 + 0x78), piVar3 != (int *)0x0))
     && (iVar2 = (**(code **)(*piVar3 + 0x10))(piVar3,&local_1c), -1 < iVar2)) {
    (**(code **)(*local_20 + 0xc))(local_20,piVar4,0);
    (**(code **)(*local_20 + 0x14))(local_20,piVar4,local_1c);
    (**(code **)(*local_1c + 8))();
LAB_40523528:
    if (((*(uint *)(param_1 + 0x13c) & 0x80) == 0) &&
       ((*(int *)(param_1 + 0xa0) != 0 || (iVar1 != 0)))) {
      (**(code **)(*local_20 + 0xc))(local_20,piVar4,*(uint *)(param_1 + 0x13c) >> 8 & 1);
    }
  }
  else if ((*(int *)(param_1 + 0xa0) == 0) ||
          ((((param_2 == 0 && ((*(uint *)(param_1 + 0x13c) & 0x100) != 0)) &&
            ((*(uint *)(param_1 + 0x140) & 1) == 0)) ||
           (iVar2 = (**(code **)(*local_20 + 0x10))
                              (local_20,piVar4,*(uint *)(param_1 + 0x13c) >> 8 & 1),
           iVar2 != -0x7ff3fff2)))) goto LAB_40523528;
  (**(code **)(*local_20 + 8))();
LAB_4052357c:
  *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfffffe7f;
  return;
}



/* 405235ac FUN_405235ac */

/* Boundary evidence: original MIPS .pdata 405235ac..405235d3. Semantic name remains unreviewed. */

void FUN_405235ac(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x60) + 0x48))();
  return;
}



/* 405235d4 FUN_405235d4 */

/* Boundary evidence: original MIPS .pdata 405235d4..40523643. Semantic name remains unreviewed. */

undefined4 FUN_405235d4(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_1 + -4;
  if (param_1 == 0x14) {
    iVar2 = 0;
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(param_1 + 4);
  }
  iVar2 = FUN_4052d788(piVar1,iVar2);
  if ((iVar2 != 0) && (param_2 != -1)) {
    *(int *)(param_1 + 0x74) = param_2;
  }
  return 0;
}



/* 40523644 FUN_40523644 */

/* Boundary evidence: original MIPS .pdata 40523644..40523857. Semantic name remains unreviewed. */

undefined4 FUN_40523644(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  code *pcVar5;
  int *local_20 [2];
  
  puVar3 = (undefined4 *)param_1[0x23];
  if (puVar3 != (undefined4 *)0x0) {
    iVar2 = (**(code **)*puVar3)(puVar3,&UNK_405166ec,local_20);
    bVar1 = iVar2 < 0;
    if (!bVar1) {
      (**(code **)(*local_20[0] + 8))();
    }
    if ((param_2 == 3) && (bVar1)) {
      param_2 = 1;
    }
    if (param_1[0x31] != 0) {
      if (param_2 == 0) {
        param_1[0x4a] = param_1[0x4a] | 0x1000;
        return 0;
      }
      piVar4 = (int *)param_1[0x23];
      if (piVar4 == (int *)0x0) {
        return 0;
      }
      (**(code **)(*piVar4 + 0x1c))(piVar4,3);
      return 0;
    }
    param_1[0x31] = 1;
    (**(code **)(*(int *)param_1[0x23] + 0x1c))((int *)param_1[0x23],param_2);
    if (((param_2 == 2) && (bVar1)) && ((HWND)param_1[0x25] != (HWND)0x0)) {
      SetFocus((HWND)param_1[0x25]);
    }
    pcVar5 = *(code **)(*param_1 + 0xdc);
    param_1[0x31] = param_1[0x31] + -1;
    (*pcVar5)(param_1,0xffffffff);
  }
  param_1[0x1f] = param_2;
  if (((param_2 == 2) && (param_1[0x23] == 0)) &&
     ((param_1[0x25] == 0 && ((param_1[0x28] != 0 && ((HWND)param_1[0x2a] != (HWND)0x0)))))) {
    SetFocus((HWND)param_1[0x2a]);
  }
  if ((param_1[0x4a] & 0x1000U) != 0) {
    piVar4 = (int *)param_1[0x23];
    param_1[0x4a] = param_1[0x4a] & 0xffffefff;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x1c))(piVar4,0);
    }
    (**(code **)(*param_1 + 0xdc))(param_1,0xffffffff);
    param_1[0x1f] = 0;
  }
  if ((param_1[0x4a] & 0x2000U) != 0) {
    param_1[0x4a] = param_1[0x4a] & 0xffffdfff;
    (**(code **)(*(int *)param_1[0x13] + 0x9c))();
  }
  return 0;
}



/* 40523858 FUN_40523858 */

/* Boundary evidence: original MIPS .pdata 40523858..405238c3. Semantic name remains unreviewed. */

bool FUN_40523858(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = FUN_4052dc64();
  bVar1 = iVar3 == 0;
  bVar2 = bVar1;
  if (param_2 == 2) {
    bVar2 = !bVar1;
    FUN_4052dcd8((uint)bVar1);
  }
  return bVar2;
}



/* 405238c4 FUN_405238c4 */

/* Boundary evidence: original MIPS .pdata 405238c4..4052390b. Semantic name remains unreviewed. */

undefined4 FUN_405238c4(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x84);
  uVar1 = 0;
  if (piVar2 != (int *)0x0) {
    uVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,&DAT_405163dc,3,1,0,0);
  }
  return uVar1;
}



/* 4052390c FUN_4052390c */

/* Boundary evidence: original MIPS .pdata 4052390c..40523993. Semantic name remains unreviewed. */

undefined4 FUN_4052390c(int param_1)

{
  int iVar1;
  undefined4 local_10;
  uint local_c;
  
  if (*(int *)(param_1 + 0x114) == 0) {
    local_10 = 0xe;
    local_c = 0;
    iVar1 = IUnknown_QueryStatus(*(undefined4 *)(param_1 + 0xa0),&DAT_405163ec,1,&local_10,0);
    if (iVar1 < 0) {
      return 1;
    }
    if ((local_c & 1) == 0) {
      return 1;
    }
    if ((local_c & 2) != 0) {
      return 1;
    }
  }
  return 0;
}



/* 40523994 FUN_40523994 */

/* Boundary evidence: original MIPS .pdata 40523994..405239d7. Semantic name remains unreviewed. */

undefined4 FUN_40523994(int param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (((*(uint *)(param_1 + 0x13c) & 0x200000) == 0) &&
     (BVar1 = IsWindowEnabled(*(HWND *)(param_1 + 0x70)), BVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 405239d8 FUN_405239d8 */

/* Boundary evidence: original MIPS .pdata 405239d8..40523a07. Semantic name remains unreviewed. */

bool FUN_405239d8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40523994(param_1 + -0x14);
  return iVar1 == 0;
}



/* 40523a08 FUN_40523a08 */

/* Boundary evidence: original MIPS .pdata 40523a08..40523a9f. Semantic name remains unreviewed. */

undefined4 FUN_40523a08(int param_1,int param_2)

{
  undefined2 local_20;
  undefined1 auStack_1e [6];
  undefined4 local_18;
  
  if (*(int *)(param_1 + 0x84) != 0) {
    memset(auStack_1e,0,0xe);
    local_20 = 3;
    if ((*(int *)(param_1 + 0xa0) == 0) && (param_2 == 0)) {
      local_18 = 1;
    }
    else {
      local_18 = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x84) + 0x10))(*(int **)(param_1 + 0x84),0,0x24,2,&local_20,0)
    ;
  }
  return 0;
}



/* 40523aa0 FUN_40523aa0 */

/* Boundary evidence: original MIPS .pdata 40523aa0..40523b53. Semantic name remains unreviewed. */

undefined4 FUN_40523aa0(int param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | 0x400;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 0x2c))(param_3,param_1 + 0x354);
    }
    uVar1 = (**(code **)(*param_2 + 0x24))
                      (param_2,param_3,param_1 + 0x354,*(undefined4 *)(param_1 + 0x54),param_4,
                       param_5);
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & 0xfffffbff;
  }
  return uVar1;
}



/* 40523b54 FUN_40523b54 */

/* Boundary evidence: original MIPS .pdata 40523b54..40523b7f. Semantic name remains unreviewed. */

undefined4 FUN_40523b54(int param_1,undefined4 param_2)

{
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x13c))(*(int **)(param_1 + 0x4c),param_2,0);
  return 0;
}



/* 40523b80 FUN_40523b80 */

/* Boundary evidence: original MIPS .pdata 40523b80..40523c03. Semantic name remains unreviewed. */

undefined4 FUN_40523b80(int param_1,int *param_2)

{
  (**(code **)(**(int **)(param_1 + 0x4c) + 300))(*(int **)(param_1 + 0x4c),param_2);
  *param_2 = *(int *)(param_1 + 0x118) + *param_2;
  param_2[1] = *(int *)(param_1 + 0x11c) + param_2[1];
  param_2[2] = param_2[2] - *(int *)(param_1 + 0x120);
  param_2[3] = param_2[3] - *(int *)(param_1 + 0x124);
  return 0;
}



/* 40523c04 FUN_40523c04 */

/* Boundary evidence: original MIPS .pdata 40523c04..40523c53. Semantic name remains unreviewed. */

undefined4 FUN_40523c04(undefined4 param_1,HWND param_2,int *param_3)

{
  SetWindowPos(param_2,(HWND)0x0,*param_3,param_3[1],param_3[2] - *param_3,param_3[3] - param_3[1],
               0x14);
  return 0;
}



/* 40523c54 FUN_40523c54 */

/* Boundary evidence: original MIPS .pdata 40523c54..40523ca3. Semantic name remains unreviewed. */

void FUN_40523c54(int param_1)

{
  if (*(int **)(param_1 + 100) == (int *)0x0) {
    (**(code **)(*(int *)(param_1 + 0x14) + 0x17c))();
  }
  else {
    (**(code **)(**(int **)(param_1 + 100) + 0x17c))();
  }
  return;
}



/* 40523ca4 FUN_40523ca4 */

/* Boundary evidence: original MIPS .pdata 40523ca4..40523d1b. Semantic name remains unreviewed. */

undefined4 FUN_40523ca4(int param_1)

{
  undefined1 auStack_18 [16];
  
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x8c))(*(int **)(param_1 + 0x4c),auStack_18);
  if ((*(int *)(param_1 + 0x94) != 0) && ((*(uint *)(param_1 + 0x128) & 1) == 0)) {
    FUN_40523c54(param_1 + -0x14);
  }
  if (*(int *)(param_1 + 0xa8) != 0) {
    FUN_40523c54(param_1 + -0x14);
  }
  return 0;
}



/* 40523d1c FUN_40523d1c */

/* Boundary evidence: original MIPS .pdata 40523d1c..40523da3. Semantic name remains unreviewed. */

undefined4 FUN_40523d1c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_405445a8 == 0) {
    DAT_405445a8 = RegisterWindowMessageW(L"GetAutomationObject");
  }
  iVar1 = FUN_40521290();
  if (iVar1 < 0) {
    uVar2 = 0x80004005;
  }
  else {
    iVar1 = param_1 + -4;
    if (param_1 == 0x14) {
      iVar1 = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x70) + 0xc))(*(int **)(param_1 + 0x70),iVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40523da4 FUN_40523da4 */

/* Boundary evidence: original MIPS .pdata 40523da4..40523eab. Semantic name remains unreviewed. */

undefined4 FUN_40523da4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18 [2];
  
  uVar2 = 0x80004005;
  local_1c = 0;
  local_18[0] = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&DAT_40512b14,&local_20), -1 < iVar1)) {
    if ((param_2 != (undefined4 *)0x0) &&
       (iVar1 = (**(code **)(*local_20 + 0xc))(local_20,&DAT_405164fc,&local_1c), -1 < iVar1)) {
      uVar2 = 0;
      *param_2 = local_1c;
    }
    if ((param_3 != (undefined4 *)0x0) &&
       (iVar1 = (**(code **)(*local_20 + 0xc))(local_20,&DAT_405162bc,local_18), -1 < iVar1)) {
      uVar2 = 0;
      *param_3 = local_18[0];
    }
    (**(code **)(*local_20 + 8))();
  }
  return uVar2;
}



/* 40523eac FUN_40523eac */

/* Boundary evidence: original MIPS .pdata 40523eac..4052403f. Semantic name remains unreviewed. */

void FUN_40523eac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  int *local_58;
  void *local_54;
  void *local_50 [2];
  undefined1 auStack_48 [16];
  undefined1 auStack_38 [8];
  undefined2 local_30;
  undefined4 local_20;
  
  if ((*(uint *)(param_1 + 0x158) & 1) == 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x158) & 2) != 0) {
    return;
  }
  iVar1 = FUN_40523da4(*(undefined4 **)(param_1 + 0x80),&local_54,local_50);
  if (iVar1 != 0) {
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x14) + 0x1c))((int *)(param_1 + 0x14),&local_58);
  uVar3 = 0xffff;
  if (local_58 != (int *)0x0) {
    iVar1 = (**(code **)(*local_58 + 0x1c))(local_58,param_1 + 0x10,0xffffffff,0);
    uVar2 = 0xffffffff;
    if (iVar1 == 0) goto LAB_40523f40;
  }
  uVar2 = 0;
LAB_40523f40:
  SHPackDispParams(auStack_48,auStack_38,2,3,2,0xb,uVar2);
  IConnectionPoint_SimpleInvoke(local_54,0x69,auStack_48);
  IConnectionPoint_SimpleInvoke(local_50[0],0x69,auStack_48);
  if ((local_58 == (int *)0x0) ||
     (iVar1 = (**(code **)(*local_58 + 0x1c))(local_58,param_1 + 0x10,1,0), iVar1 != 0)) {
    uVar3 = 0;
  }
  IUnknown_AtomicRelease(&local_58);
  local_20 = 1;
  local_30 = uVar3;
  IConnectionPoint_SimpleInvoke(local_54,0x69,auStack_48);
  IConnectionPoint_SimpleInvoke(local_50[0],0x69,auStack_48);
  IUnknown_AtomicRelease(&local_54);
  IUnknown_AtomicRelease(local_50);
  return;
}



/* 40524040 FUN_40524040 */

/* Boundary evidence: original MIPS .pdata 40524040..40524107. Semantic name remains unreviewed. */

void FUN_40524040(int param_1)

{
  int iVar1;
  void *local_40;
  void *local_3c;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [32];
  
  if ((((*(uint *)(param_1 + 0x158) & 1) != 0) && ((*(uint *)(param_1 + 0x158) & 2) == 0)) &&
     (iVar1 = FUN_40523da4(*(undefined4 **)(param_1 + 0x80),&local_40,&local_3c), iVar1 == 0)) {
    SHPackDispParams(auStack_38,auStack_28,2,3,0xffffffff,0xb,0);
    IConnectionPoint_SimpleInvoke(local_40,0x69,auStack_38);
    IConnectionPoint_SimpleInvoke(local_3c,0x69,auStack_38);
    IUnknown_AtomicRelease(&local_40);
    IUnknown_AtomicRelease(&local_3c);
  }
  return;
}



/* 40524108 FUN_40524108 */

/* Boundary evidence: original MIPS .pdata 40524108..4052414f. Semantic name remains unreviewed. */

undefined4 FUN_40524108(int param_1,uint param_2,LPARAM param_3)

{
  if (((param_2 & 0xffff) < 0x8000) && (*(HWND *)(param_1 + 0x94) != (HWND)0x0)) {
    SendMessageW(*(HWND *)(param_1 + 0x94),0x111,param_2,param_3);
  }
  return 0;
}



/* 40524150 FUN_40524150 */

/* Boundary evidence: original MIPS .pdata 40524150..40524193. Semantic name remains unreviewed. */

undefined4 FUN_40524150(int param_1,int param_2)

{
  if ((*(uint *)(param_2 + 4) < 0x8000) && (*(HWND *)(param_1 + 0x94) != (HWND)0x0)) {
    SendMessageW(*(HWND *)(param_1 + 0x94),0x4e,*(uint *)(param_2 + 4),param_2);
  }
  return 0;
}



/* 40524194 FUN_40524194 */

/* Boundary evidence: original MIPS .pdata 40524194..405241bf. Semantic name remains unreviewed. */

undefined4 FUN_40524194(int param_1)

{
  if (*(HWND *)(param_1 + 0x94) != (HWND)0x0) {
    SetFocus(*(HWND *)(param_1 + 0x94));
  }
  return 0;
}



/* 405241c0 FUN_405241c0 */

/* Boundary evidence: original MIPS .pdata 405241c0..40524267. Semantic name remains unreviewed. */

undefined4 FUN_405241c0(LPCITEMIDLIST param_1)

{
  int iVar1;
  undefined4 uVar2;
  LPCWSTR local_18 [2];
  
  uVar2 = 1;
  FUN_40520168((int *)local_18,0x824);
  if ((((param_1 != (LPCITEMIDLIST)0x0) &&
       (iVar1 = FUN_40522b14(param_1,local_18[0],0x8000), -1 < iVar1)) &&
      (iVar1 = StrCmpNICW(L"about:home",local_18[0],10), iVar1 != 0)) &&
     (iVar1 = FUN_4053ad2c(local_18[0]), iVar1 == 0x11)) {
    uVar2 = 0;
  }
  operator_delete(local_18[0]);
  return uVar2;
}



/* 40524268 FUN_40524268 */

/* Boundary evidence: original MIPS .pdata 40524268..4052474f. Semantic name remains unreviewed. */

undefined4 FUN_40524268(int *param_1)

{
  bool bVar1;
  LPCWSTR pWVar2;
  int iVar3;
  BOOL BVar4;
  HWND pHVar5;
  int *piVar6;
  int *piVar7;
  wchar_t *psz;
  undefined4 uVar8;
  LPCWSTR local_40;
  DWORD local_3c;
  undefined4 local_38;
  uint local_34;
  _union_2683 local_30;
  
  uVar8 = 0x80004005;
  if (((param_1[0x28] == 0) || (param_1[0x29] == 0)) ||
     (IUnknown_Exec(param_1[0x28],&DAT_405163ec,0x47,0,0,0), param_1[0x45] != 0)) goto LAB_40524710;
  piVar6 = (int *)param_1[0x21];
  bVar1 = true;
  local_38 = 0xe;
  local_34 = 0;
  if (((piVar6 != (int *)0x0) &&
      (iVar3 = (**(code **)(*piVar6 + 0xc))(piVar6,&DAT_405163ec,1,&local_38,0), -1 < iVar3)) &&
     (((local_34 & 1) != 0 && ((local_34 & 2) == 0)))) goto LAB_40524710;
  (**(code **)(*(int *)param_1[0x15] + 0x24))((int *)param_1[0x15],0);
  if (((param_1[0x23] != 0) && (BVar4 = IsWindowVisible((HWND)param_1[0x17]), BVar4 != 0)) &&
     ((param_1[0x44] & 0x8000000U) == 0)) {
    FUN_4052da64(L"ActivatingDocument",0);
  }
  if (((param_1[0x3f] & 0x20U) == 0) &&
     (((param_1[0x23] == 0 || (iVar3 = FUN_405241c0((LPCITEMIDLIST)param_1[0x22]), iVar3 != 0)) &&
      ((param_1[0x4a] & 0x40000U) == 0)))) {
    FUN_40520168((int *)&local_40,0x824);
    pWVar2 = local_40;
    if (local_40 != (LPCWSTR)0x0) {
      *local_40 = L'\0';
      (**(code **)(*param_1 + 0x28))(param_1,param_1[0x22],local_40,0x8000);
      FUN_405233d8((int)(param_1 + -5),0);
    }
    operator_delete(pWVar2);
  }
  if (param_1[0x25] == 0) {
LAB_40524440:
    if (param_1[0x2a] != 0) {
      pHVar5 = GetFocus();
      iVar3 = SHIsChildOrSelf(param_1[0x2a],pHVar5);
      if (iVar3 == 0) goto LAB_40524470;
    }
    bVar1 = false;
  }
  else {
    pHVar5 = GetFocus();
    iVar3 = SHIsChildOrSelf(param_1[0x25],pHVar5);
    if (iVar3 != 0) goto LAB_40524440;
  }
LAB_40524470:
  (**(code **)(*(int *)param_1[0x13] + 0x108))();
  (**(code **)(*(int *)param_1[0x15] + 0x24))((int *)param_1[0x15],1);
  if (((param_1[0x1f] == 2) && ((param_1[0x4a] & 0x4000U) == 0)) && (!bVar1)) {
    param_1[0x1f] = 3;
    param_1[0x4a] = param_1[0x4a] | 0x8000;
  }
  (**(code **)(*param_1 + 0x128))(param_1,param_1[0x1f]);
  (**(code **)(*param_1 + 0x38))(param_1,0);
  (**(code **)(*(int *)param_1[0x13] + 0x48))();
  FUN_40524040((int)(param_1 + -5));
  psz = (wchar_t *)param_1[0x26];
  if (psz == (wchar_t *)0x0) {
    if (param_1[0x22] != 0) {
      FUN_40520168((int *)&local_40,0x824);
      pWVar2 = local_40;
      iVar3 = FUN_405220f8((LPCITEMIDLIST)param_1[0x22],0,local_40,local_3c,(uint *)0x0);
      if (-1 < iVar3) {
        FUN_40536b68((undefined4 *)param_1[0x1b],0x71,pWVar2);
      }
      operator_delete(pWVar2);
    }
  }
  else if ((param_1[0x4b] & 1U) == 0) {
    FUN_40536b68((undefined4 *)param_1[0x1b],0x71,psz);
  }
  else {
    local_30.n2.vt = 8;
    local_30._8_4_ = SysAllocString(psz);
    IUnknown_Exec(param_1[0x15],0,0x1c,0,&local_30,0);
    FUN_4052eac4((VARIANTARG *)&local_30.n2);
  }
  FUN_405355d4((IUnknown *)param_1[0x1b],param_1[0x1a],(LPCITEMIDLIST)param_1[0x22]);
  iVar3 = IUnknown_Exec(param_1[0x23],&DAT_405163ec,0x4c,0,0,0);
  if (iVar3 != 0) {
    memset(&local_30.n2.wReserved1,0,0xe);
    local_30.n2.vt = 3;
    local_30._8_4_ = (BSTR)0x0;
    piVar6 = param_1 + -1;
    if (param_1 == (int *)0x14) {
      piVar6 = (int *)0x0;
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = param_1 + 1;
    }
    iVar3 = FUN_4052d788(piVar7,piVar6);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_1[1] + 0xc))(param_1 + 1,&DAT_40512c24,&DAT_4051646c,&local_40);
      if (-1 < iVar3) {
        local_30._8_4_ = local_30._8_4_ + 7;
        (**(code **)(*(int *)local_40 + 0x10))(local_40,&DAT_405163dc,0x19,0,&local_30,0);
        (**(code **)(*(int *)local_40 + 8))();
      }
    }
    else {
      (**(code **)(param_1[2] + 0x10))(param_1 + 2,&DAT_405163dc,0x19,0,&local_30,0);
    }
  }
  uVar8 = 0;
LAB_40524710:
  (**(code **)(param_1[6] + 0xc))(param_1 + 6,0,4);
  return uVar8;
}



/* 40524750 FUN_40524750 */

/* Boundary evidence: original MIPS .pdata 40524750..40524787. Semantic name remains unreviewed. */

void FUN_40524750(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  SHDefWindowProc(param_2,param_3,param_4,param_5);
  return;
}



/* 40524788 FUN_40524788 */

/* Boundary evidence: original MIPS .pdata 40524788..40524833. Semantic name remains unreviewed. */

void FUN_40524788(int param_1,UINT param_2,WPARAM param_3,LPARAM param_4,int param_5)

{
  HWND hWnd;
  
  if (*(HWND *)(param_1 + 0x70) != (HWND)0x0) {
    for (hWnd = GetWindow(*(HWND *)(param_1 + 0x70),5); hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2))
    {
      if (param_5 == 0) {
        PostMessageW(hWnd,param_2,param_3,param_4);
      }
      else {
        SendMessageW(hWnd,param_2,param_3,param_4);
      }
    }
  }
  return;
}



/* 40524834 FUN_40524834 */

/* Boundary evidence: original MIPS .pdata 40524834..4052498f. Semantic name remains unreviewed. */

int FUN_40524834(int param_1,undefined4 *param_2,ushort *param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *local_28 [2];
  LPCWSTR local_20;
  DWORD local_1c;
  
  iVar3 = -0x7fffbffb;
  if ((param_2 != (undefined4 *)0x0) &&
     (iVar3 = (**(code **)*param_2)(param_2,&UNK_405165cc,local_28), -1 < iVar3)) {
    iVar3 = (**(code **)(*local_28[0] + 0x10))(local_28[0],param_3);
    if ((-1 < iVar3) && (pvVar1 = FUN_4052d908(param_3), pvVar1 != (void *)0x0)) {
      iVar2 = SHIsSameObject(param_2,*(undefined4 *)(param_1 + 0x8c));
      if (iVar2 == 0) {
        iVar2 = SHIsSameObject(param_2,*(undefined4 *)(param_1 + 0xa0));
        if (iVar2 != 0) {
          FUN_40537f64(*(int *)(param_1 + 0x9c));
          *(void **)(param_1 + 0x9c) = pvVar1;
        }
      }
      else {
        FUN_40537f64(*(int *)(param_1 + 0x88));
        *(void **)(param_1 + 0x88) = pvVar1;
        FUN_40520168((int *)&local_20,0x824);
        FUN_405220f8(*(LPCITEMIDLIST *)(param_1 + 0x88),0,local_20,local_1c,(uint *)0x0);
        FUN_40536b68(*(undefined4 **)(param_1 + 0x6c),0x71,local_20);
        operator_delete(local_20);
      }
    }
    (**(code **)(*local_28[0] + 8))();
  }
  return iVar3;
}



/* 40524990 FUN_40524990 */

/* Boundary evidence: original MIPS .pdata 40524990..405249c7. Semantic name remains unreviewed. */

undefined4 FUN_40524990(int param_1,int param_2)

{
  if (param_2 != 1) {
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x11c))(*(int **)(param_1 + 0x4c),0);
  }
  return 0;
}



/* 405249c8 FUN_405249c8 */

/* Boundary evidence: original MIPS .pdata 405249c8..40524a37. Semantic name remains unreviewed. */

undefined4 FUN_405249c8(int param_1,ushort param_2)

{
  undefined4 uVar1;
  HCURSOR hCursor;
  
  if ((((*(uint *)(param_1 + 0x13c) & 2) == 0) && ((*(uint *)(param_1 + 0x13c) & 4) == 0)) ||
     ((9 < param_2 && (param_2 < 0x12)))) {
    uVar1 = 0;
  }
  else {
    hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f8a);
    SetCursor(hCursor);
    uVar1 = 1;
  }
  return uVar1;
}



/* 40524a38 FUN_40524a38 */

/* Boundary evidence: original MIPS .pdata 40524a38..40524a7f. Semantic name remains unreviewed. */

void FUN_40524a38(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((iVar1 != 0) && (iVar1 != -2)) {
    FUN_40537f64(iVar1);
  }
  *param_2 = 0;
  return;
}



/* 40524a80 FUN_40524a80 */

/* Boundary evidence: original MIPS .pdata 40524a80..40524b33. Semantic name remains unreviewed. */

undefined4 FUN_40524a80(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  
  uVar2 = param_1[0x4a];
  piVar1 = (int *)param_1[0x3b];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
  }
  uVar4 = (param_2 << 0xe ^ param_1[0x4a]) & 0x4000U ^ param_1[0x4a];
  param_1[0x4a] = uVar4;
  if (((param_2 != 0) && ((uVar2 >> 0xe & 1) == 0)) && ((uVar4 & 0x8000) != 0)) {
    pcVar3 = *(code **)(*param_1 + 0x128);
    param_1[0x4a] = uVar4 & 0xffff7fff;
    (*pcVar3)(param_1,2);
  }
  return 0;
}



/* 40524b54 FUN_40524b54 */

/* Boundary evidence: original MIPS .pdata 40524b54..40524d8f. Semantic name remains unreviewed. */

undefined4 FUN_40524b54(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_28;
  ushort local_24 [2];
  undefined4 local_20;
  uint local_1c;
  int local_18;
  
  if (param_2 == 0) {
    if ((*(uint *)(param_1 + 0x148) & 4) != 0) {
      local_20 = (STRSAFE_LPCWSTR)((uint)local_20 & 0xffff0000);
      memset((void *)((int)&local_20 + 2),0,0xe);
      piVar2 = *(int **)(param_1 + 0x88);
      if (((piVar2 == (int *)0x0) ||
          (iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,&DAT_405163dc,0x29,5,0,&local_20), iVar1 < 0
          )) || (local_18 == -1)) {
        uVar3 = 0x80004005;
      }
      else {
        uVar3 = (**(code **)(**(int **)(param_1 + 0x58) + 0x38))
                          (*(int **)(param_1 + 0x58),1,0x40b,local_18,param_1 + 0x150,0);
      }
      *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) & 0xfffffffb;
      return uVar3;
    }
    uVar3 = (**(code **)(**(int **)(param_1 + 0x58) + 0x38))
                      (*(int **)(param_1 + 0x58),1,0x40b,0,0,0);
    return uVar3;
  }
  local_28 = 0;
  (**(code **)(**(int **)(param_1 + 0x58) + 0x38))(*(int **)(param_1 + 0x58),1,0x40e,0,0,&local_28);
  if ((*(uint *)(param_1 + 0x148) & 4) == 0) {
    if (local_28 == 0) {
      FUN_40520168(&local_20,0x824);
      iVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0x38))
                        (*(int **)(param_1 + 0x58),1,0x40c,0,0,local_24);
      if ((-1 < iVar1) && (local_24[0] < local_1c)) {
        (**(code **)(**(int **)(param_1 + 0x58) + 0x38))
                  (*(int **)(param_1 + 0x58),1,0x40d,0,local_20,0);
        StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x150),0x104,local_20);
        *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) | 4;
      }
      operator_delete(local_20);
      goto LAB_40524c58;
    }
  }
  else {
LAB_40524c58:
    if (local_28 == 0) {
      uVar3 = 0;
      goto LAB_40524c70;
    }
  }
  uVar3 = 0x1ff;
LAB_40524c70:
  uVar3 = (**(code **)(**(int **)(param_1 + 0x58) + 0x38))
                    (*(int **)(param_1 + 0x58),1,0x40b,uVar3,param_2,0);
  return uVar3;
}



/* 40524d90 FUN_40524d90 */

/* Boundary evidence: original MIPS .pdata 40524d90..40524e6f. Semantic name remains unreviewed. */

int FUN_40524d90(int param_1,int param_2,UINT param_3,uint param_4,wchar_t *param_5,LRESULT *param_6
                )

{
  int iVar1;
  LRESULT LVar2;
  HWND local_28 [2];
  
  local_28[0] = (HWND)0x0;
  if (param_6 != (LRESULT *)0x0) {
    *param_6 = 0;
  }
  if (((param_2 == 1) && (param_3 == 0x40b)) && ((param_4 & 0x1000) == 0)) {
    FUN_40536b68(*(undefined4 **)(param_1 + 0x70),0x66,param_5);
  }
  iVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0x34))
                    (*(int **)(param_1 + 0x58),param_2,local_28);
  if ((-1 < iVar1) &&
     (LVar2 = SendMessageW(local_28[0],param_3,param_4,(LPARAM)param_5), param_6 != (LRESULT *)0x0))
  {
    *param_6 = LVar2;
  }
  return iVar1;
}



/* 40524e70 FUN_40524e70 */

/* Boundary evidence: original MIPS .pdata 40524e70..40524ec3. Semantic name remains unreviewed. */

undefined4 FUN_40524e70(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x90);
  if ((*(uint *)(param_1 + 300) & 0x400) != 0) {
    piVar2 = *(int **)(param_1 + 0xa4);
  }
  *param_2 = (int)piVar2;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(*piVar2 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40524ec4 FUN_40524ec4 */

/* Boundary evidence: original MIPS .pdata 40524ec4..40524eef. Semantic name remains unreviewed. */

undefined4 FUN_40524ec4(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x50) + 0x118))(*(int **)(param_1 + 0x50),0xffffffff);
  return 0;
}



/* 40524ef0 FUN_40524ef0 */

/* Boundary evidence: original MIPS .pdata 40524ef0..40524f0f. Semantic name remains unreviewed. */

undefined4 FUN_40524ef0(int param_1,LPRECT param_2)

{
  GetClientRect(*(HWND *)(param_1 + 0x5c),param_2);
  return 0;
}



/* 40524f10 FUN_40524f10 */

/* Boundary evidence: original MIPS .pdata 40524f10..40524f3b. Semantic name remains unreviewed. */

undefined4 FUN_40524f10(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x3c) + 300))();
  return 0;
}



/* 40524f3c FUN_40524f3c */

/* Boundary evidence: original MIPS .pdata 40524f3c..40524fb3. Semantic name remains unreviewed. */

undefined4 FUN_40524f3c(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    SetRect((LPRECT)(param_1 + 0x108),0,0,0,0);
  }
  else {
    *(undefined4 *)(param_1 + 0x108) = *param_2;
    *(undefined4 *)(param_1 + 0x10c) = param_2[1];
    *(undefined4 *)(param_1 + 0x110) = param_2[2];
    *(undefined4 *)(param_1 + 0x114) = param_2[3];
  }
  (**(code **)(**(int **)(param_1 + 0x3c) + 0x130))();
  return 0;
}



/* 40524fb4 FUN_40524fb4 */

/* Boundary evidence: original MIPS .pdata 40524fb4..4052500f. Semantic name remains unreviewed. */

undefined4 FUN_40524fb4(int param_1,int *param_2)

{
  IUnknown_AtomicRelease((void **)(param_1 + 0xdc));
  if (param_2 != (int *)0x0) {
    *(void **)(param_1 + 0xdc) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
  }
  return 0;
}



/* 40525010 FUN_40525010 */

/* Boundary evidence: original MIPS .pdata 40525010..40525373. Semantic name remains unreviewed. */

undefined4 FUN_40525010(int param_1,void *param_2,int param_3,int *param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *local_28 [2];
  
  if (param_4 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    if (param_2 == (void *)0x0) {
      for (; param_3 != 0; param_3 = param_3 + -1) {
        iVar4 = *param_4;
        param_4[1] = 0;
        if (iVar4 == 0x15) {
LAB_40525138:
          param_4[1] = 2;
        }
        else if (iVar4 == 0x17) {
LAB_405250fc:
          if (*(int *)(param_1 + 0x98) != 0) goto LAB_40525138;
          piVar2 = *(int **)(param_1 + 0x7c);
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 0xc))(piVar2,0,1,param_4,param_5);
          }
        }
        else {
          if (iVar4 == 0x1d) goto LAB_40525138;
          if (iVar4 == 0x1e) goto LAB_405250fc;
          piVar2 = *(int **)(param_1 + 0x7c);
          if ((piVar2 != (int *)0x0) && ((*(uint *)(param_1 + 0x120) & 0x10000) == 0)) {
            *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 0x10000;
            (**(code **)(*piVar2 + 0xc))(piVar2,0,1,param_4,param_5);
            *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xfffeffff;
          }
        }
        param_4 = param_4 + 2;
      }
    }
    else {
      iVar4 = memcmp(&DAT_405163dc,param_2,0x10);
      if (iVar4 == 0) {
        if (param_3 != 0) {
          piVar2 = param_4 + 1;
          do {
            iVar4 = piVar2[-1];
            if (iVar4 == 2) {
              iVar4 = 2;
              if (*(int *)(param_1 + 0x98) == 0) {
                iVar4 = 0;
              }
              *piVar2 = iVar4;
            }
            else if ((iVar4 == 8) || (iVar4 == 0x11)) {
              *piVar2 = 2;
            }
            else {
              *piVar2 = 0;
            }
            param_3 = param_3 + -1;
            piVar2 = piVar2 + 2;
          } while (param_3 != 0);
        }
      }
      else {
        iVar4 = memcmp(&DAT_405163ec,param_2,0x10);
        if (iVar4 != 0) {
          return 0x80040104;
        }
        if (param_3 != 0) {
          piVar2 = param_4 + 1;
          do {
            uVar5 = piVar2[-1];
            if (uVar5 == 0) {
LAB_40525254:
              *piVar2 = 0;
            }
            else if (uVar5 < 3) {
LAB_40525318:
              piVar3 = *(int **)(param_1 + 0x7c);
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 0xc))(piVar3,param_2,1,piVar2 + -1,param_5);
              }
            }
            else if (uVar5 == 7) {
              *piVar2 = 0;
              iVar4 = (**(code **)(*(int *)(param_1 + -8) + 0x1c))((int *)(param_1 + -8),local_28);
              if (-1 < iVar4) {
                iVar4 = param_1 + -0xc;
                if (param_1 == 0x1c) {
                  iVar4 = 0;
                }
                uVar1 = 0xffffffff;
LAB_405252dc:
                iVar4 = (**(code **)(*local_28[0] + 0x1c))(local_28[0],iVar4,uVar1,0);
                if (iVar4 == 0) {
                  *piVar2 = 1;
                }
                (**(code **)(*local_28[0] + 8))();
              }
            }
            else {
              if (uVar5 != 8) {
                if (uVar5 != 0x32) goto LAB_40525254;
                goto LAB_40525318;
              }
              *piVar2 = 0;
              iVar4 = (**(code **)(*(int *)(param_1 + -8) + 0x1c))((int *)(param_1 + -8),local_28);
              if (-1 < iVar4) {
                iVar4 = param_1 + -0xc;
                if (param_1 == 0x1c) {
                  iVar4 = 0;
                }
                uVar1 = 1;
                goto LAB_405252dc;
              }
            }
            param_3 = param_3 + -1;
            piVar2 = piVar2 + 2;
          } while (param_3 != 0);
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40525374 FUN_40525374 */

/* Boundary evidence: original MIPS .pdata 40525374..4052539b. Semantic name remains unreviewed. */

undefined4 FUN_40525374(int *param_1)

{
  (**(code **)(*param_1 + 8))();
  return 1;
}



/* 4052539c FUN_4052539c */

/* Boundary evidence: original MIPS .pdata 4052539c..405253cb. Semantic name remains unreviewed. */

undefined4 FUN_4052539c(int param_1)

{
  HDPA p_Var1;
  
  p_Var1 = DPA_Create(4);
  *(HDPA *)(param_1 + 0x100) = p_Var1;
  return 0;
}



/* 405253cc FUN_405253cc */

/* Boundary evidence: original MIPS .pdata 405253cc..40525483. Semantic name remains unreviewed. */

void FUN_405253cc(int param_1,int param_2)

{
  int *piVar1;
  int i;
  
  i = **(int **)(param_1 + 0x114);
  while( true ) {
    i = i + -1;
    if (i < 0) {
      return;
    }
    piVar1 = DPA_GetPtr(*(HDPA *)(param_1 + 0x114),i);
    *(undefined4 *)(param_2 + 4) = 0;
    (**(code **)(*piVar1 + 0xc))(piVar1,0,1,param_2,0);
    if ((*(uint *)(param_2 + 4) & 2) != 0) break;
    Ordinal_1841(*(undefined4 *)(param_1 + 0x114),i);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



/* 40525484 FUN_40525484 */

/* Boundary evidence: original MIPS .pdata 40525484..40525567. Semantic name remains unreviewed. */

void FUN_40525484(int param_1,undefined4 *param_2)

{
  PVOID pvVar1;
  int iVar2;
  HDPA hdpa;
  int iVar3;
  int *local_20 [2];
  
  hdpa = *(HDPA *)(param_1 + 0x114);
  iVar3 = 0;
  if (0 < *(int *)hdpa) {
    do {
      pvVar1 = DPA_GetPtr(hdpa,iVar3);
      iVar2 = SHIsSameObject(pvVar1,param_2);
      if (iVar2 != 0) {
        return;
      }
      hdpa = *(HDPA *)(param_1 + 0x114);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)hdpa);
  }
  iVar3 = (**(code **)*param_2)(param_2,&DAT_4051646c,local_20);
  if ((-1 < iVar3) &&
     (iVar3 = DPA_InsertPtr(*(HDPA *)(param_1 + 0x114),0x7fffffff,local_20[0]), iVar3 == -1)) {
    (**(code **)(*local_20[0] + 8))();
  }
  return;
}



/* 40525568 FUN_40525568 */

/* Boundary evidence: original MIPS .pdata 40525568..4052566b. Semantic name remains unreviewed. */

undefined4 FUN_40525568(int param_1,short *param_2)

{
  int *piVar1;
  undefined4 local_18;
  uint local_14;
  
  if ((param_2 == (short *)0x0) || (*(undefined4 **)(param_2 + 4) == (undefined4 *)0x0)) {
    local_18 = 0x1e;
    piVar1 = *(int **)(param_1 + 0x98);
    local_14 = 0;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,0,1,&local_18,0);
    }
    if ((*(int *)(param_1 + 0x114) != 0) && ((local_14 & 2) == 0)) {
      FUN_405253cc(param_1,(int)&local_18);
    }
    *(uint *)(param_1 + 0x13c) =
         ((uint)((local_14 & 2) != 0) << 2 ^ *(uint *)(param_1 + 0x13c)) & 4 ^
         *(uint *)(param_1 + 0x13c);
  }
  else {
    if ((*(int *)(param_1 + 0x114) != 0) && (*param_2 == 0xd)) {
      FUN_40525484(param_1,*(undefined4 **)(param_2 + 4));
    }
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 4;
  }
  return 0;
}



/* 4052566c FUN_4052566c */

/* Boundary evidence: original MIPS .pdata 4052566c..40525757. Semantic name remains unreviewed. */

int FUN_4052566c(int param_1,undefined2 *param_2)

{
  HRESULT HVar1;
  int iVar2;
  LPVOID *ppv;
  
  ppv = (LPVOID *)(param_1 + 0x104);
  if (*ppv == (LPVOID)0x0) {
    HVar1 = CoGetClassObject((IID *)&DAT_405166dc,5,(LPVOID)0x0,(IID *)&DAT_4051630c,ppv);
    if (HVar1 < 0) {
      return HVar1;
    }
    iVar2 = (**(code **)(*(int *)*ppv + 0x10))(*ppv,1);
    if (iVar2 < 0) {
      (**(code **)(*(int *)*ppv + 8))();
      *ppv = (LPVOID)0x0;
      return iVar2;
    }
  }
  iVar2 = (**(code **)(*(int *)*ppv + 0xc))(*ppv,0,&DAT_405162fc,param_2 + 4);
  if (iVar2 < 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = 0xd;
  }
  return iVar2;
}



/* 40525758 FUN_40525758 */

/* Boundary evidence: original MIPS .pdata 40525758..405257bf. Semantic name remains unreviewed. */

STRSAFE_LPWSTR FUN_40525758(short *param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  *param_2 = L'\0';
  if ((((param_1 == (short *)0x0) || (*param_1 != 8)) ||
      (*(STRSAFE_LPCWSTR *)(param_1 + 4) == (STRSAFE_LPCWSTR)0x0)) ||
     (StringCchCopyW(param_2,param_3,*(STRSAFE_LPCWSTR *)(param_1 + 4)), *param_2 == L'\0')) {
    param_2 = (STRSAFE_LPWSTR)0x0;
  }
  return param_2;
}



/* 405257c0 FUN_405257c0 */

/* Boundary evidence: original MIPS .pdata 405257c0..40525887. Semantic name remains unreviewed. */

int FUN_405257c0(LPCWSTR param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  HRESULT HVar3;
  int local_1068 [2];
  WCHAR aWStack_1060 [2086];
  uint local_14;
  
  local_14 = DAT_40544354;
  local_1068[0] = 0;
  FUN_40522458(0,param_1,(IUnknown *)0x0,local_1068);
  if (local_1068[0] == 0) {
    local_1068[1] = 0x825;
    bVar2 = FUN_4052d6cc(param_1);
    if ((CONCAT31(extraout_var,bVar2) == 0) ||
       (HVar3 = PathCreateFromUrlW(param_1,aWStack_1060,(LPDWORD)(local_1068 + 1),0), HVar3 < 0)) {
      StringCchCopyW(aWStack_1060,0x825,param_1);
    }
    FUN_40522458(0,param_1,(IUnknown *)0x0,local_1068);
  }
  iVar1 = local_1068[0];
  FUN_40542538(local_14);
  return iVar1;
}



/* 40525888 FUN_40525888 */

/* Boundary evidence: original MIPS .pdata 40525888..405258eb. Semantic name remains unreviewed. */

undefined4 FUN_40525888(undefined4 *param_1)

{
  int iVar1;
  int *local_10;
  undefined4 local_c;
  
  local_c = 0;
  iVar1 = (**(code **)*param_1)(param_1,&UNK_405166fc,&local_10);
  if (-1 < iVar1) {
    (**(code **)(*local_10 + 0x20))(local_10,&local_c);
    (**(code **)(*local_10 + 8))();
  }
  return local_c;
}



/* 405258ec FUN_405258ec */

/* Boundary evidence: original MIPS .pdata 405258ec..405259e7. Semantic name remains unreviewed. */

int FUN_405258ec(undefined4 param_1,LPCWSTR param_2,int *param_3)

{
  int iVar1;
  LPWSTR _Str;
  size_t sVar2;
  BSTR bstrString;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  if (param_2 != (LPCWSTR)0x0) {
    iVar3 = FUN_40522fa8();
    if (iVar3 == 0) {
      iVar4 = FUN_405257c0(param_2);
    }
    else {
      iVar1 = FUN_4053ad2c(param_2);
      if ((((iVar1 != 0xf) && (iVar1 != 0x10)) &&
          (_Str = StrChrW(param_2,L'#'), _Str != (LPWSTR)0x0)) &&
         ((sVar2 = wcslen(_Str), 1 < sVar2 &&
          (bstrString = SysAllocString(_Str + 1), bstrString != (BSTR)0x0)))) {
        iVar4 = FUN_405257c0(bstrString);
        SysFreeString(bstrString);
      }
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar3;
  }
  return iVar4;
}



/* 405259f8 FUN_405259f8 */

/* Boundary evidence: original MIPS .pdata 405259f8..40525b57. Semantic name remains unreviewed. */

undefined4 FUN_405259f8(int param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  SIZE_T SVar4;
  HLOCAL pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uBytes;
  
  bVar1 = false;
  iVar2 = SHIsSameObject(*(undefined4 *)(param_1 + 0x8c),param_2);
  if (iVar2 == 0) {
    iVar2 = SHIsSameObject(*(undefined4 *)(param_1 + 0xa0),param_2);
    if ((iVar2 == 0) && (*(int *)(param_1 + 0xa0) != 0)) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = (undefined4 *)(param_1 + 0xac);
      bVar1 = true;
      if (*(int *)(param_1 + 0x8c) != 0) {
        bVar1 = false;
      }
    }
  }
  else {
    puVar7 = (undefined4 *)(param_1 + 0x98);
    bVar1 = true;
  }
  if (puVar7 == (undefined4 *)0x0) {
    return 0;
  }
  sVar3 = wcslen(param_3);
  uVar6 = sVar3 + 1;
  if (0x104 < uVar6) {
    uVar6 = 0x104;
  }
  uBytes = 0x80;
  if (0x3f < uVar6) {
    uBytes = uVar6 << 1;
  }
  if ((HLOCAL)*puVar7 != (HLOCAL)0x0) {
    SVar4 = LocalSize((HLOCAL)*puVar7);
    if (uBytes <= SVar4) goto LAB_40525b04;
    if ((HLOCAL)*puVar7 != (HLOCAL)0x0) {
      LocalFree((HLOCAL)*puVar7);
    }
  }
  pvVar5 = LocalAlloc(0x40,uBytes);
  *puVar7 = pvVar5;
LAB_40525b04:
  if (((STRSAFE_LPWSTR)*puVar7 != (STRSAFE_LPWSTR)0x0) &&
     (StringCchCopyW((STRSAFE_LPWSTR)*puVar7,uBytes >> 1,param_3), bVar1)) {
    FUN_40536b68(*(undefined4 **)(param_1 + 0x6c),0x71,(wchar_t *)*puVar7);
  }
  return 0;
}



/* 40525b58 FUN_40525b58 */

/* Boundary evidence: original MIPS .pdata 40525b58..40525c1b. Semantic name remains unreviewed. */

undefined4 FUN_40525b58(int param_1,int param_2,STRSAFE_LPWSTR param_3,size_t param_4)

{
  int iVar1;
  STRSAFE_LPCWSTR pszSrc;
  
  if ((param_2 == 0) ||
     (iVar1 = SHIsSameObject(*(undefined4 *)(param_1 + 0x8c),param_2), iVar1 != 0)) {
    pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0x98);
  }
  else {
    iVar1 = SHIsSameObject(*(undefined4 *)(param_1 + 0xa0),param_2);
    if ((iVar1 == 0) && (*(int *)(param_1 + 0xa0) != 0)) goto LAB_40525bf0;
    pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0xac);
  }
  if (pszSrc != (STRSAFE_LPCWSTR)0x0) {
    StringCchCopyW(param_3,param_4,pszSrc);
    return 0;
  }
LAB_40525bf0:
  *param_3 = L'\0';
  return 0x80004005;
}



/* 40525c1c FUN_40525c1c */

/* Boundary evidence: original MIPS .pdata 40525c1c..40525d07. Semantic name remains unreviewed. */

int FUN_40525c1c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -0x7fffbffb;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  iVar1 = SHIsSameObject(param_2,*(undefined4 *)(param_1 + 0x8c));
  if ((((iVar1 != 0) ||
       (iVar1 = SHIsSameObject(param_2,*(undefined4 *)(param_1 + 0xa0)), iVar1 != 0)) &&
      (iVar2 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x104))
                         (*(int **)(param_1 + 0x4c),param_2,param_3), iVar2 < 0)) &&
     (iVar2 = (**(code **)(**(int **)(param_1 + 0x54) + 0x2c))
                        (*(int **)(param_1 + 0x54),param_3,0x8000001), param_4 != (undefined4 *)0x0)
     ) {
    *param_4 = 1;
  }
  return iVar2;
}



/* 40525e44 FUN_40525e44 */

/* Boundary evidence: original MIPS .pdata 40525e44..40525e6b. Semantic name remains unreviewed. */

void FUN_40525e44(undefined4 param_1,LPCITEMIDLIST param_2,LPCWSTR param_3,uint param_4)

{
  FUN_40522b14(param_2,param_3,param_4);
  return;
}



/* 40525e6c FUN_40525e6c */

/* Boundary evidence: original MIPS .pdata 40525e6c..40525e93. Semantic name remains unreviewed. */

void FUN_40525e6c(int *param_1)

{
  (**(code **)(*param_1 + 0x180))();
  return;
}



/* 40525e94 FUN_40525e94 */

/* Boundary evidence: original MIPS .pdata 40525e94..40525feb. Semantic name remains unreviewed. */

int FUN_40525e94(int param_1,undefined4 param_2,wchar_t *param_3,uint param_4,undefined4 *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  IUnknown *pIVar3;
  IBindCtx *local_1078;
  int *local_1074;
  DWORD local_1070 [2];
  wchar_t awStack_1068 [2084];
  uint local_20;
  
  local_20 = DAT_40544354;
  local_1078 = (IBindCtx *)0x0;
  local_1074 = (int *)0x0;
  (**(code **)(*(int *)(param_1 + 4) + 0xc))
            ((int *)(param_1 + 4),&DAT_4051656c,&UNK_4051670c,&local_1074);
  local_1070[0] = 0x824;
  bVar1 = FUN_4052d870(param_3,awStack_1068,local_1070,(undefined4 *)0x0);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    StringCchCopyW(awStack_1068,0x824,param_3);
  }
  if (local_1074 != (int *)0x0) {
    (**(code **)(*local_1074 + 8))();
  }
  iVar2 = FUN_4053ad2c(awStack_1068);
  if ((iVar2 == 1) || ((param_4 & 1) != 0)) {
    pIVar3 = (IUnknown *)(param_1 + 0xc);
    if (param_1 == 0x14) {
      pIVar3 = (IUnknown *)0x0;
    }
    local_1078 = FUN_4052e450(pIVar3);
  }
  iVar2 = FUN_40522458(param_2,awStack_1068,(IUnknown *)local_1078,param_5);
  IUnknown_AtomicRelease(&local_1078);
  FUN_40542538(local_20);
  return iVar2;
}



/* 40525fec FUN_40525fec */

/* Boundary evidence: original MIPS .pdata 40525fec..405261bf. Semantic name remains unreviewed. */

undefined4 FUN_40525fec(int param_1,undefined4 param_2,OLECHAR *param_3)

{
  void *local_60;
  void *local_5c;
  undefined4 local_58;
  undefined2 local_50;
  undefined1 auStack_4e [6];
  BSTR local_48;
  undefined2 local_40;
  undefined1 auStack_3e [6];
  undefined4 local_38;
  undefined2 local_30;
  undefined1 auStack_2e [6];
  undefined4 local_28;
  
  local_5c = (void *)0x0;
  local_60 = (void *)0x0;
  local_58 = 0;
  FUN_4053379c(*(IUnknown **)(param_1 + 0x6c),(undefined4 *)0x0,&local_5c);
  FUN_40523da4(*(undefined4 **)(param_1 + 0x6c),(undefined4 *)0x0,&local_60);
  memset(auStack_4e,0,0xe);
  local_50 = 8;
  local_48 = SysAllocString(param_3);
  memset(auStack_3e,0,0xe);
  local_40 = 3;
  local_38 = param_2;
  memset(auStack_2e,0,0xe);
  local_30 = 8;
  local_28 = 0;
  if (local_60 != (void *)0x0) {
    FUN_40533d14(*(undefined4 **)(param_1 + 0x6c),local_60,0,0,0x10f,5);
    IUnknown_AtomicRelease(&local_60);
  }
  if (local_5c != (void *)0x0) {
    FUN_40533d14(*(undefined4 **)(param_1 + 0x6c),local_5c,0,0,0x10f,5);
    IUnknown_AtomicRelease(&local_5c);
  }
  SysFreeString(local_48);
  return 0;
}



/* 405261c0 FUN_405261c0 */

/* Boundary evidence: original MIPS .pdata 405261c0..40526203. Semantic name remains unreviewed. */

undefined4 FUN_405261c0(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 0x140) & 2) == 0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x60) + 0x178))();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40526204 FUN_40526204 */

/* Boundary evidence: original MIPS .pdata 40526204..4052638f. Semantic name remains unreviewed. */

uint FUN_40526204(int *param_1,LPCITEMIDLIST param_2)

{
  LPCWSTR pWVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar3;
  LPCITEMIDLIST pIVar4;
  WCHAR *pWVar5;
  int iVar6;
  uint uVar7;
  WCHAR *pWVar8;
  LPCWSTR local_48 [2];
  WCHAR aWStack_40 [10];
  uint local_2c;
  
  local_2c = DAT_40544354;
  pIVar4 = (LPCITEMIDLIST)param_1[0x30];
  uVar7 = 0;
  if ((pIVar4 != (LPCITEMIDLIST)0x0) ||
     (pIVar4 = (LPCITEMIDLIST)param_1[0x22], pIVar4 != (LPCITEMIDLIST)0x0)) {
    iVar6 = 0;
    FUN_40520168((int *)local_48,0x824);
    memcpy(aWStack_40,L"file:///",0x12);
    bVar2 = FUN_4051fdcc((short *)pIVar4,0);
    pWVar1 = local_48[0];
    pWVar8 = aWStack_40;
    if ((CONCAT31(extraout_var,bVar2) == 0) ||
       (iVar6 = FUN_40522b14(pIVar4,local_48[0],0x8000), pWVar8 = pWVar1, -1 < iVar6)) {
      FUN_40520168((int *)local_48,0x824);
      bVar2 = FUN_4051fdcc((short *)param_2,0);
      pWVar5 = aWStack_40;
      if (CONCAT31(extraout_var_00,bVar2) != 0) {
        iVar6 = FUN_40522b14(param_2,local_48[0],0x8000);
        pWVar5 = local_48[0];
      }
      if ((((pWVar8 != pWVar5) && (-1 < iVar6)) &&
          (uVar3 = FUN_4053af9c(param_1[0x17],pWVar8,pWVar5,0), uVar3 != 0)) &&
         (uVar7 = uVar3, 0 < (int)uVar3)) {
        uVar7 = uVar3 & 0xffff | 0x80070000;
      }
      operator_delete(local_48[0]);
    }
    operator_delete(pWVar1);
  }
  (**(code **)(*param_1 + 0x5c))(param_1,0);
  FUN_40542538(local_2c);
  return uVar7;
}



/* 40526390 FUN_40526390 */

/* Boundary evidence: original MIPS .pdata 40526390..40526587. Semantic name remains unreviewed. */

undefined4 FUN_40526390(int param_1,LPCITEMIDLIST param_2,int param_3)

{
  LPCWSTR pWVar1;
  int iVar2;
  undefined4 uVar3;
  short local_28;
  short local_26;
  undefined4 local_24;
  LPCWSTR local_20;
  DWORD local_1c;
  
  uVar3 = 0;
  (**(code **)(**(int **)(param_1 + 0x7c) + 0xec))(*(int **)(param_1 + 0x7c),&local_26);
  (**(code **)(**(int **)(param_1 + 0x7c) + 0xe4))(*(int **)(param_1 + 0x7c),&local_28);
  if (local_28 != 0) {
    return 0;
  }
  if (local_26 != 0) {
    return 0;
  }
  if (param_2 == (LPCITEMIDLIST)0x0) {
    return 0;
  }
  if (param_2 == (LPCITEMIDLIST)0xfffffffe) {
    return 0;
  }
  if (param_2 == (LPCITEMIDLIST)0xffffffff) {
    return 0;
  }
  iVar2 = FUN_4052e80c((ushort *)param_2,0x40);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = FUN_4052dc64();
  if (iVar2 == 0) {
    return 0;
  }
  FUN_40520168((int *)&local_20,0x824);
  pWVar1 = local_20;
  FUN_405220f8(param_2,0x8000,local_20,local_1c,(uint *)0x0);
  iVar2 = FUN_4052d550(pWVar1);
  if ((iVar2 == 0) || ((iVar2 = FUN_4052d6b0(pWVar1), iVar2 != 0 && (param_3 == 0))))
  goto LAB_4052655c;
  local_24 = 0;
  if ((*(uint *)(param_1 + 0x158) & 1) == 0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x6c) + 0xc))
                      (*(int **)(param_1 + 0x6c),&DAT_4051658c,&UNK_4051637c,&local_20);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*(int *)local_20 + 0xc))(local_20,&local_24);
      (**(code **)(*(int *)local_20 + 8))();
    }
    if (iVar2 != 0) goto LAB_40526508;
  }
  else {
LAB_40526508:
    local_24 = *(undefined4 *)(param_1 + 0x70);
  }
  uVar3 = 0;
  (**(code **)(**(int **)(param_1 + 0x68) + 0x24))(*(int **)(param_1 + 0x68),0);
  iVar2 = FUN_4053ae64(pWVar1,local_24,0);
  if (iVar2 == 0) {
    uVar3 = 0x80004004;
  }
  (**(code **)(**(int **)(param_1 + 0x68) + 0x24))(*(int **)(param_1 + 0x68),1);
LAB_4052655c:
  operator_delete(pWVar1);
  return uVar3;
}



/* 405265d4 FUN_405265d4 */

/* Boundary evidence: original MIPS .pdata 405265d4..40526697. Semantic name remains unreviewed. */

undefined4 FUN_405265d4(int param_1)

{
  HCURSOR pHVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x13c);
  if (((uVar2 & 2) == 0) && ((uVar2 & 4) == 0)) {
    if ((uVar2 & 8) != 0) {
      FUN_40536d88(*(undefined4 **)(param_1 + 0x80),0x68);
      *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfffffff7;
    }
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    SetCursor(pHVar1);
  }
  else {
    pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f8a);
    SetCursor(pHVar1);
    if ((*(uint *)(param_1 + 0x13c) & 8) == 0) {
      FUN_40536d88(*(undefined4 **)(param_1 + 0x80),0x6a);
      *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 8;
    }
  }
  return 0;
}



/* 40526698 FUN_40526698 */

/* Boundary evidence: original MIPS .pdata 40526698..405266f7. Semantic name remains unreviewed. */

undefined4 FUN_40526698(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & 0xfffffffd;
  }
  else {
    if (param_2 < 1) {
      return 0;
    }
    if (2 < param_2) {
      return 0;
    }
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | 2;
  }
  FUN_405265d4(param_1 + -0x14);
  return 0;
}



/* 405266f8 FUN_405266f8 */

/* Boundary evidence: original MIPS .pdata 405266f8..40526773. Semantic name remains unreviewed. */

undefined4 FUN_405266f8(int *param_1,undefined4 *param_2)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
  if ((((param_1[0x4a] & 2U) == 0) && (iVar1 = (**(code **)(*param_1 + 0xfc))(param_1), iVar1 != 0))
     && ((param_1[0x4a] & 4U) == 0)) {
    BVar2 = IsWindowEnabled((HWND)param_1[0x17]);
    uVar3 = 0;
    if (BVar2 != 0) goto LAB_40526758;
  }
  uVar3 = 2;
LAB_40526758:
  *param_2 = uVar3;
  return 0;
}



/* 40526774 FUN_40526774 */

/* Boundary evidence: original MIPS .pdata 40526774..40526853. Semantic name remains unreviewed. */

undefined4 FUN_40526774(int param_1)

{
  int iVar1;
  code *pcVar2;
  int *local_10 [2];
  
  if ((*(uint *)(param_1 + 0x144) & 1) == 0) {
    local_10[0] = (int *)0x0;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0xc))
                      (*(int **)(param_1 + 0x58),&DAT_40512c24,&DAT_40513564,local_10);
    if (-1 < iVar1) {
      iVar1 = param_1 + -4;
      if (param_1 == 0x14) {
        iVar1 = 0;
      }
      iVar1 = SHIsSameObject(local_10[0],iVar1);
      if (iVar1 == 0) {
        pcVar2 = *(code **)(*local_10[0] + 0x48);
      }
      else {
        pcVar2 = *(code **)(*(int *)(param_1 + -0x14) + 0x24);
      }
      (*pcVar2)();
      (**(code **)(*local_10[0] + 8))();
    }
  }
  else {
    (**(code **)(*(int *)(param_1 + -0x14) + 0x24))();
  }
  return 0;
}



/* 40526854 FUN_40526854 */

/* Boundary evidence: original MIPS .pdata 40526854..40526dc3. Semantic name remains unreviewed. */

int * FUN_40526854(int *param_1,void *param_2,void *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  LPVOID *ppvVar4;
  undefined *puVar5;
  int *piVar6;
  int *local_28;
  int *local_24;
  
  *param_4 = 0;
  iVar1 = memcmp(param_2,&DAT_4051645c,0x10);
  if ((((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_4051654c,0x10), iVar1 == 0)) ||
      (iVar1 = memcmp(param_2,&DAT_40512b14,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_4051657c,0x10), iVar1 == 0)) {
    piVar2 = (int *)param_1[0x1b];
    goto LAB_40526d84;
  }
  puVar5 = &DAT_4051664c;
  iVar1 = memcmp(param_2,&DAT_4051664c,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405164bc,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_405164dc,0x10), iVar1 == 0)) {
    piVar2 = (int *)param_1[0x4e];
    goto LAB_40526d84;
  }
  iVar1 = memcmp(param_2,&DAT_4051658c,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40512c24,0x10), iVar1 == 0)) ||
     ((iVar1 = memcmp(param_2,&DAT_4051656c,0x10), iVar1 == 0 ||
      (iVar1 = memcmp(param_2,&DAT_4051669c,0x10), iVar1 == 0)))) {
    iVar1 = memcmp(param_3,&DAT_4051661c,0x10);
    if (iVar1 != 0) goto LAB_40526d1c;
    ppvVar4 = (LPVOID *)(param_1 + 0x4c);
    if (*ppvVar4 == (LPVOID)0x0) {
      FUN_40516d94((IID *)&DAT_405162ac,(LPUNKNOWN)0x0,1,(IID *)&DAT_4051661c,ppvVar4);
    }
    piVar2 = *ppvVar4;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_405162ac,0x10);
    if (iVar1 != 0) {
      iVar1 = memcmp(param_2,&DAT_4051652c,0x10);
      if ((iVar1 != 0) && (iVar1 = memcmp(param_2,&DAT_4051653c,0x10), iVar1 != 0)) {
        puVar5 = &DAT_4051640c;
        iVar1 = memcmp(param_2,&DAT_4051640c,0x10);
        if (iVar1 == 0) {
          piVar2 = (int *)param_1[0x4e];
          pcVar3 = IUnknown_QueryService_exref;
        }
        else {
          puVar5 = &DAT_4051673c;
          iVar1 = memcmp(param_2,&DAT_4051673c,0x10);
          if ((iVar1 != 0) ||
             (piVar2 = (int *)param_1[0x22], pcVar3 = IUnknown_QueryService_exref,
             piVar2 == (int *)0x0)) {
            iVar1 = memcmp(param_2,&DAT_4051672c,0x10);
            if (iVar1 != 0) {
              iVar1 = memcmp(param_3,&DAT_4051671c,0x10);
              if (iVar1 != 0) {
                piVar2 = (int *)FUN_4053a4e4((int)(param_1 + 9),param_2,param_3,param_4);
                return piVar2;
              }
              local_24 = (int *)0x0;
              local_28 = (int *)0x0;
              piVar2 = (int *)(**(code **)(*param_1 + 0xc))
                                        (param_1,&DAT_4051640c,&DAT_4051640c,&local_24);
              if ((int)piVar2 < 0) {
                return piVar2;
              }
              piVar2 = (int *)(**(code **)*local_24)(local_24,&DAT_4051642c,&local_28);
              if (-1 < (int)piVar2) {
                piVar2 = (int *)(**(code **)(*local_28 + 0xc))
                                          (local_28,&DAT_4051671c,&DAT_4051671c,param_4);
                (**(code **)(*local_28 + 8))();
              }
              (**(code **)(*local_24 + 8))();
              return piVar2;
            }
            piVar2 = param_1 + 0x4d;
            if (*piVar2 == 0) {
              piVar6 = param_1 + -1;
              (**(code **)(*piVar6 + 0x1c))(piVar6,&local_28);
              if ((local_28 != (int *)0x0) &&
                 (iVar1 = (**(code **)*local_28)(local_28,&DAT_405136a4,&local_24), -1 < iVar1)) {
                if (param_1 == (int *)0x18) {
                  piVar6 = (int *)0x0;
                }
                piVar6 = (int *)FUN_4053eaa8(piVar6,local_24,piVar2);
                (**(code **)(*local_24 + 8))();
                local_24 = piVar6;
              }
              IUnknown_AtomicRelease(&local_28);
            }
            piVar2 = (int *)*piVar2;
            if (piVar2 == (int *)0x0) {
              return local_24;
            }
            goto LAB_40526d84;
          }
        }
LAB_40526ac0:
        piVar2 = (int *)(*pcVar3)(piVar2,puVar5,param_3,param_4);
        return piVar2;
      }
      iVar1 = memcmp(param_3,&DAT_4051664c,0x10);
      if (iVar1 == 0) {
        piVar2 = (int *)param_1[0x15];
        pcVar3 = *(code **)(*piVar2 + 0xc);
        goto LAB_40526ac0;
      }
      iVar1 = memcmp(param_3,&DAT_4051662c,0x10);
      if ((iVar1 == 0) &&
         (piVar2 = (int *)param_1[0x18], pcVar3 = IUnknown_QueryService_exref, piVar2 != (int *)0x0)
         ) goto LAB_40526ac0;
LAB_40526d1c:
      piVar2 = param_1 + -6;
      goto LAB_40526d84;
    }
    if ((param_1[0x4c] == 0) &&
       (iVar1 = (**(code **)(*(int *)param_1[0x15] + 0xc))
                          ((int *)param_1[0x15],&DAT_4051658c,&DAT_4051661c,&local_24), -1 < iVar1))
    {
      if (param_1[0x4c] == 0) {
        param_1[0x4c] = (int)local_24;
      }
      else {
        (**(code **)(*local_24 + 8))();
      }
    }
    piVar2 = (int *)param_1[0x4c];
  }
  if (piVar2 == (int *)0x0) {
    return (int *)0x80004002;
  }
LAB_40526d84:
  piVar2 = (int *)(**(code **)*piVar2)(piVar2,param_3,param_4);
  return piVar2;
}



/* 40526dc4 FUN_40526dc4 */

/* WARNING: Removing unreachable block (ram,0x40526f98) */
/* Boundary evidence: original MIPS .pdata 40526dc4..4052700f. Semantic name remains unreviewed. */

int FUN_40526dc4(int param_1,LPCITEMIDLIST param_2,undefined4 *param_3)

{
  bool bVar1;
  uint uVar2;
  LPWSTR pWVar3;
  int iVar4;
  _union_2260 _Var5;
  LPCWSTR local_dc;
  ULONG local_d8;
  int local_d4;
  int *local_d0;
  int *local_cc;
  LPWSTR local_c8;
  int local_c4;
  STGMEDIUM local_c0;
  wchar_t awStack_b0 [66];
  OLECHAR *local_2c;
  uint local_24;
  
  uVar2 = DAT_40544354;
  local_24 = DAT_40544354;
  *param_3 = 0;
  bVar1 = false;
  local_d8 = 0;
  local_d4 = 0;
  if ((*(int *)(param_1 + 0x374) == 0) || (*(int *)(param_1 + 0x37c) != 0)) {
    iVar4 = FUN_40541d60();
    _Var5.hBitmap = (HBITMAP)0x0;
    if (-1 < iVar4) {
      FUN_40539448();
      (**(code **)(*local_d0 + 8))();
      bVar1 = true;
      if (local_c0.tymed == 1) {
        _Var5 = local_c0.u;
      }
    }
    FUN_40520168((int *)&local_c8,0x824);
    FUN_4053b45c(awStack_b0);
    *local_c8 = L'\0';
    iVar4 = FUN_40538a84((IUnknown *)(param_1 + 0x10),(IID *)&DAT_405164bc,&local_cc);
    if (-1 < iVar4) {
      local_dc = (LPCWSTR)0x0;
      (**(code **)(*local_cc + 0x10))(local_cc,&local_dc);
      (**(code **)(*local_cc + 8))();
      if (local_dc != (LPCWSTR)0x0) {
        SHUnicodeToUnicode(local_dc,local_c8,local_c4);
        CoTaskMemFree(local_dc);
      }
    }
    FUN_4053b670(awStack_b0,(wchar_t *)0x0,0xffffffff);
    *(LPCITEMIDLIST *)(param_1 + 0x370) = param_2;
    pWVar3 = local_c8;
    if (*local_c8 == L'\0') {
      pWVar3 = (OLECHAR *)0x0;
    }
    FUN_40535b0c(*(IUnknown **)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x70),
                 *(undefined4 *)(param_1 + 0x7c),param_2,0,0,pWVar3,_Var5.hMetaFilePict,local_d8,
                 local_2c,&local_d4);
    *(undefined4 *)(param_1 + 0x370) = 0;
    if (local_d4 != 0) {
      iVar4 = -0x7fffbffc;
    }
    FUN_4053b474(awStack_b0);
    operator_delete(local_c8);
    if (bVar1) {
      ReleaseStgMedium(&local_c0);
    }
    FUN_40542538(local_24);
  }
  else {
    *(undefined4 *)(param_1 + 0x37c) = 1;
    FUN_40542538(uVar2);
    iVar4 = 0;
  }
  return iVar4;
}



/* 40527010 FUN_40527010 */

undefined4 FUN_40527010(int param_1)

{
  *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 1;
  return 0;
}



/* 40527024 FUN_40527024 */

/* Boundary evidence: original MIPS .pdata 40527024..405270b3. Semantic name remains unreviewed. */

undefined4 FUN_40527024(int param_1)

{
  int *piVar1;
  undefined1 auStack_20 [16];
  
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x130))();
  if (*(int *)(param_1 + 0xec) != 0) {
    piVar1 = (int *)(param_1 + 0x10);
    (**(code **)(*piVar1 + 0x14))(piVar1,auStack_20);
    if (param_1 == 0x14) {
      piVar1 = (int *)0x0;
    }
    (**(code **)(**(int **)(param_1 + 0xec) + 0x20))(*(int **)(param_1 + 0xec),auStack_20,piVar1,1);
  }
  return 0;
}



/* 405270b4 FUN_405270b4 */

/* Boundary evidence: original MIPS .pdata 405270b4..405270d7. Semantic name remains unreviewed. */

void FUN_405270b4(int *param_1)

{
  (**(code **)(*param_1 + 0x138))();
  return;
}



/* 405270d8 FUN_405270d8 */

/* Boundary evidence: original MIPS .pdata 405270d8..4052710b. Semantic name remains unreviewed. */

undefined4 FUN_405270d8(int param_1,int param_2)

{
  if (param_2 == 0) {
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x134))(*(int **)(param_1 + 0x4c),0);
  }
  return 0;
}



/* 4052710c FUN_4052710c */

/* Boundary evidence: original MIPS .pdata 4052710c..40527157. Semantic name remains unreviewed. */

undefined4
FUN_4052710c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (param_2 != 0) {
    IUnknown_Exec(param_2,param_4,param_5,param_6,param_7,param_8);
  }
  return 0;
}



/* 40527158 FUN_40527158 */

/* Boundary evidence: original MIPS .pdata 40527158..4052718b. Semantic name remains unreviewed. */

undefined4
FUN_40527158(undefined4 param_1,HWND param_2,undefined4 param_3,UINT param_4,WPARAM param_5,
            LPARAM param_6)

{
  if (param_2 != (HWND)0x0) {
    SendMessageW(param_2,param_4,param_5,param_6);
  }
  return 0;
}



/* 40527198 FUN_40527198 */

/* Boundary evidence: original MIPS .pdata 40527198..405272a3. Semantic name remains unreviewed. */

HRESULT FUN_40527198(IStream *param_1,int *param_2,int *param_3)

{
  HRESULT HVar1;
  int iVar2;
  
  *param_3 = 0;
  HVar1 = IStream_Read(param_1,param_2,0x24);
  if (-1 < HVar1) {
    if ((*param_2 == 0x24) && ((param_2[1] == 2 || (param_2[1] == 1)))) {
      if (param_2[8] != 0) {
        iVar2 = FUN_4053f298(param_2[8]);
        *param_3 = iVar2;
      }
      if ((void *)*param_3 == (void *)0x0) {
        HVar1 = -0x7ff8fff2;
      }
      else {
        HVar1 = IStream_Read(param_1,(void *)*param_3,param_2[8]);
        if (HVar1 < 0) {
          FUN_40537f64(*param_3);
          *param_3 = 0;
        }
      }
    }
    else {
      HVar1 = -0x7fff0001;
    }
  }
  return HVar1;
}



/* 405272a4 FUN_405272a4 */

/* Boundary evidence: original MIPS .pdata 405272a4..4052746b. Semantic name remains unreviewed. */

HRESULT FUN_405272a4(int param_1,IStream *param_2)

{
  int iVar1;
  HRESULT HVar2;
  void **ppunk;
  void *apvStack_50 [2];
  ULONG local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [16];
  ULONG local_28;
  uint local_24;
  
  local_24 = DAT_40544354;
  HVar2 = -0x7fff0001;
  if (*(int *)(param_1 + 0x6c) != 0) {
    memset(&local_44,0,0x20);
    local_48 = 0x24;
    local_3c = (**(code **)(*(int *)(param_1 + -0x1c) + 0x60))();
    local_28 = FUN_40537d04(*(ushort **)(param_1 + 0x6c));
    local_44 = 1;
    local_40 = *(undefined4 *)(param_1 + 0x58);
    ppunk = (void **)(param_1 + 0xcc);
    if ((*ppunk == (void *)0x0) && (*(int **)(param_1 + 0x70) != (int *)0x0)) {
      FUN_4052d52c(*(int **)(param_1 + 0x70));
    }
    if (*ppunk != (void *)0x0) {
      iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x70))
                        (*(undefined4 **)(param_1 + 0x70),&DAT_405137e4,apvStack_50);
      if ((-1 < iVar1) &&
         (iVar1 = (**(code **)(*(int *)*ppunk + 0xc))(*ppunk,auStack_38), -1 < iVar1)) {
        local_44 = 2;
      }
      IUnknown_AtomicRelease(apvStack_50);
    }
    HVar2 = IStream_Write(param_2,&local_48,local_48);
    if (((-1 < HVar2) &&
        (HVar2 = IStream_Write(param_2,*(void **)(param_1 + 0x6c),local_28), -1 < HVar2)) &&
       (local_44 == 2)) {
      HVar2 = (**(code **)(*(int *)*ppunk + 0x14))(*ppunk,param_2);
    }
    IUnknown_AtomicRelease(ppunk);
  }
  FUN_40542538(local_24);
  return HVar2;
}



/* 4052746c FUN_4052746c */

/* Boundary evidence: original MIPS .pdata 4052746c..40527633. Semantic name remains unreviewed. */

int FUN_4052746c(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  LPCITEMIDLIST local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  undefined4 uStack_1c;
  
  piVar3 = (int *)(param_1 + -0x1c);
  iVar2 = -0x7fffbffb;
  (**(code **)(*piVar3 + 0x1c))(piVar3,&local_2c);
  if (local_2c != (int *)0x0) {
    iVar1 = param_1 + -0x20;
    if (param_1 == 0x30) {
      iVar1 = 0;
    }
    iVar1 = (**(code **)(*local_2c + 0x1c))(local_2c,iVar1,0,&local_24);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_24 + 0x14))(local_24,&local_30);
      if (-1 < iVar1) {
        iVar2 = FUN_40526dc4(param_1 + -0x30,local_30,&uStack_1c);
        if (((-1 < iVar2) && (*(int **)(param_1 + 0x70) != (int *)0x0)) &&
           (iVar2 = FUN_4052d52c(*(int **)(param_1 + 0x70)), -1 < iVar2)) {
          iVar2 = param_1 + -0x20;
          if (param_1 == 0x30) {
            iVar2 = 0;
          }
          (**(code **)(*local_2c + 0x10))(local_2c,iVar2,1);
          iVar2 = (**(code **)(*local_28 + 0x18))(local_28,param_2);
          (**(code **)(*local_28 + 8))();
          (**(code **)(*piVar3 + 0x40))(piVar3,*(undefined4 *)(param_1 + 0x70),local_30,&local_20);
          if (local_20 == 0) {
            FUN_405355d4(*(IUnknown **)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x4c),
                         *(LPCITEMIDLIST *)(param_1 + 0x6c));
            FUN_40535834(*(IUnknown **)(param_1 + 0x50),*(undefined4 **)(param_1 + 0x4c),
                         *(LPCITEMIDLIST *)(param_1 + 0x6c));
          }
        }
        FUN_40537f64((int)local_30);
      }
      (**(code **)(*local_24 + 8))();
    }
    (**(code **)(*local_2c + 8))();
  }
  return iVar2;
}



/* 40527634 FUN_40527634 */

/* Boundary evidence: original MIPS .pdata 40527634..405276bf. Semantic name remains unreviewed. */

int FUN_40527634(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_18;
  
  iVar1 = -0x7fffbffb;
  if (((param_2 != 0) && (*(int **)(param_1 + 0x70) != (int *)0x0)) &&
     (iVar1 = FUN_4052d52c(*(int **)(param_1 + 0x70)), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_18 + 0x1c))(local_18,param_2);
    (**(code **)(*local_18 + 8))();
  }
  return iVar1;
}



/* 405276c0 FUN_405276c0 */

/* Boundary evidence: original MIPS .pdata 405276c0..40527757. Semantic name remains unreviewed. */

undefined4 FUN_405276c0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 200) == 0) {
    iVar2 = param_1 + -4;
    if (param_1 == 0x14) {
      iVar2 = 0;
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(param_1 + 4);
    }
    iVar2 = FUN_4052d788(piVar1,iVar2);
    if (iVar2 == 0) {
      do {
        do {
          iVar2 = FUN_4052d760();
          *(int *)(param_1 + 200) = iVar2;
        } while (iVar2 == 0);
      } while (iVar2 == -1);
    }
    else {
      *(undefined4 *)(param_1 + 200) = 0xffffffff;
    }
  }
  return *(undefined4 *)(param_1 + 200);
}



/* 405277a0 FUN_405277a0 */

/* Boundary evidence: original MIPS .pdata 405277a0..4052780b. Semantic name remains unreviewed. */

undefined4 FUN_405277a0(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((*(int *)(param_1 + 0xd8) == 0) && (uVar2 = *(uint *)(param_1 + 0x128), (uVar2 & 0x200) == 0)
      ) && (*(uint *)(param_1 + 0x128) = (param_3 << 8 ^ uVar2) & 0x100 ^ uVar2,
           param_2 != (int *)0x0)) {
    *(int **)(param_1 + 0xd8) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80004005;
  }
  return uVar1;
}



/* 4052780c FUN_4052780c */

/* Boundary evidence: original MIPS .pdata 4052780c..4052799b. Semantic name remains unreviewed. */

int FUN_4052780c(int param_1,undefined4 *param_2)

{
  int iVar1;
  size_t sVar2;
  int *local_90 [2];
  _union_2683 local_88;
  GUID local_78;
  int local_68;
  OLECHAR aOStack_64 [40];
  uint local_14;
  
  local_14 = DAT_40544354;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_4051631c,local_90);
  if (-1 < iVar1) {
    local_78.Data1 = 0;
    local_78.Data2 = 0;
    local_78.Data3 = 0;
    local_78.Data4[0] = '\0';
    local_78.Data4[1] = '\0';
    local_78.Data4[2] = '\0';
    local_78.Data4[3] = '\0';
    local_78.Data4[4] = '\0';
    local_78.Data4[5] = '\0';
    local_78.Data4[6] = '\0';
    local_78.Data4[7] = '\0';
    iVar1 = (**(code **)(*local_90[0] + 0xc))(local_90[0],&local_78);
    (**(code **)(*local_90[0] + 8))();
    if (-1 < iVar1) {
      StringFromGUID2(&local_78,aOStack_64,0x27);
      sVar2 = wcslen(aOStack_64);
      local_68 = sVar2 << 1;
      memset(&local_88,0,0x10);
      iVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x8c))
                        (*(int **)(param_1 + 0x68),aOStack_64,&local_88);
      if ((iVar1 < 0) || (local_88.n2.vt == 0)) {
        local_88.n2.vt = 0xd;
        local_88._8_4_ = FUN_4053f44c(&local_78);
        if ((int *)local_88._8_4_ != (int *)0x0) {
          iVar1 = (**(code **)(**(int **)(param_1 + 0x68) + 0x88))
                            (*(int **)(param_1 + 0x68),aOStack_64,local_88._0_4_,
                             local_88.decVal.Hi32,local_88._8_4_,local_88._12_4_);
          (**(code **)(*(int *)local_88._8_4_ + 8))();
        }
      }
      else {
        FUN_4052eac4((VARIANTARG *)&local_88.n2);
      }
    }
  }
  FUN_40542538(local_14);
  return iVar1;
}



/* 405279d4 FUN_405279d4 */

/* Boundary evidence: original MIPS .pdata 405279d4..40527a13. Semantic name remains unreviewed. */

undefined4 FUN_405279d4(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = FUN_4052d908(*(ushort **)(param_1 + 0x88));
  *param_2 = pvVar1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40527a14 FUN_40527a14 */

/* Boundary evidence: original MIPS .pdata 40527a14..40527a6f. Semantic name remains unreviewed. */

undefined4 FUN_40527a14(int param_1,ushort *param_2)

{
  undefined4 uVar1;
  
  FUN_4052d97c((int *)(param_1 + 0xc0),param_2);
  if ((*(int *)(param_1 + 0xc0) == 0) && (param_2 != (ushort *)0x0)) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40527a70 FUN_40527a70 */

/* Boundary evidence: original MIPS .pdata 40527a70..40527b03. Semantic name remains unreviewed. */

undefined4 FUN_40527a70(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18 [2];
  
  *param_3 = 0;
  uVar2 = 0x80004005;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x13c))
                    (*(undefined4 **)(param_1 + 0x13c),&DAT_405163fc,local_18);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(*local_18[0] + 0x20))(local_18[0],param_2,param_3);
    (**(code **)(*local_18[0] + 8))();
  }
  return uVar2;
}



/* 40527b04 FUN_40527b04 */

/* Boundary evidence: original MIPS .pdata 40527b04..40527c13. Semantic name remains unreviewed. */

undefined4 FUN_40527b04(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *local_18 [2];
  
  piVar4 = (int *)(param_1 + 0x60);
  *param_2 = 0;
  if ((*piVar4 == 0) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0x58) + 0xc))
                        (*(int **)(param_1 + 0x58),&DAT_40512c24,&DAT_40513564,local_18), -1 < iVar1
     )) {
    if (param_1 == 0x14) {
      param_1 = 0;
    }
    iVar1 = SHIsSameObject(param_1,local_18[0]);
    if (iVar1 == 0) {
      (**(code **)(*local_18[0] + 0x1c))(local_18[0],piVar4);
    }
    else {
      FUN_4053e7a8(piVar4);
    }
    (**(code **)(*local_18[0] + 8))();
  }
  puVar3 = (undefined4 *)*piVar4;
  if (puVar3 == (undefined4 *)0x0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = (**(code **)*puVar3)(puVar3,&DAT_40513694,param_2);
  }
  return uVar2;
}



/* 40527c14 FUN_40527c14 */

/* Boundary evidence: original MIPS .pdata 40527c14..40527c67. Semantic name remains unreviewed. */

undefined4 FUN_40527c14(int param_1,undefined4 *param_2,undefined4 param_3)

{
  (**(code **)*param_2)(param_2,&DAT_40513694,param_1 + 0x60);
  *(undefined4 *)(param_1 + 200) = param_3;
  return 0;
}



/* 40527c68 FUN_40527c68 */

/* Boundary evidence: original MIPS .pdata 40527c68..40527ce3. Semantic name remains unreviewed. */

void FUN_40527c68(int param_1)

{
  int iVar1;
  int *local_10 [2];
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x6c) + 0xc))
                    (*(int **)(param_1 + 0x6c),&DAT_4051658c,&DAT_4051652c,local_10);
  if (-1 < iVar1) {
    IUnknown_Exec(local_10[0],&DAT_405163dc,0x27,0,0,0);
    (**(code **)(*local_10[0] + 8))();
  }
  return;
}



/* 40527cf0 FUN_40527cf0 */

/* Boundary evidence: original MIPS .pdata 40527cf0..40527d67. Semantic name remains unreviewed. */

void FUN_40527cf0(undefined4 param_1,int *param_2)

{
  int local_18 [2];
  
  local_18[0] = 0;
  (**(code **)(*param_2 + 0x10))(param_2,&UNK_40513dac,0,local_18);
  if (local_18[0] == 0) {
    (**(code **)(*param_2 + 0xc))(param_2,&UNK_40513dac,&UNK_40513d9c);
  }
  return;
}



/* 40527d68 FUN_40527d68 */

/* Boundary evidence: original MIPS .pdata 40527d68..40527d8f. Semantic name remains unreviewed. */

void FUN_40527d68(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x34) + 100))();
  return;
}



/* 40527d90 FUN_40527d90 */

/* Boundary evidence: original MIPS .pdata 40527d90..40527e33. Semantic name remains unreviewed. */

HRESULT FUN_40527d90(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  HRESULT HVar3;
  
  HVar3 = 0;
  memset(param_2,0,0x1c);
  uVar1 = (**(code **)(*(int *)(param_1 + -0x34) + 0x60))();
  *param_2 = uVar1;
  param_2[1] = *(undefined4 *)(param_1 + 0xd0);
  pvVar2 = FUN_4052d908(*(ushort **)(param_1 + 0x54));
  param_2[2] = pvVar2;
  if (*(LPCWSTR *)(param_1 + 100) != (LPCWSTR)0x0) {
    HVar3 = SHStrDupW(*(LPCWSTR *)(param_1 + 100),(LPWSTR *)(param_2 + 5));
  }
  return HVar3;
}



/* 40527e34 FUN_40527e34 */

/* Boundary evidence: original MIPS .pdata 40527e34..40527e83. Semantic name remains unreviewed. */

void FUN_40527e34(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_4052da64(L"Navigating",0);
  (**(code **)(*(int *)(param_1 + -0x18) + 0x18))((int *)(param_1 + -0x18),param_3);
  return;
}



/* 40527e84 FUN_40527e84 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40527e84..40528023. Semantic name remains unreviewed. */

undefined4 FUN_40527e84(int param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  HRESULT HVar2;
  ushort *pv;
  LPSTREAM *ppstm;
  int *piVar3;
  ULONG local_40 [8];
  ULONG local_20;
  uint local_1c;
  
  local_1c = DAT_40544354;
  local_40[0] = 0;
  memset(local_40 + 1,0,0x20);
  piVar3 = (int *)(param_1 + -0x38);
  uVar1 = (**(code **)(*piVar3 + 0x60))(piVar3);
  *param_4 = uVar1;
  param_4[1] = 0;
  SHStrDupW(param_2,(LPWSTR *)(param_4 + 3));
  SHStrDupW(param_3,(LPWSTR *)(param_4 + 5));
  ppstm = (LPSTREAM *)(param_4 + 6);
  if ((*ppstm != (LPSTREAM)0x0) || (HVar2 = CreateStreamOnHGlobal((HGLOBAL)0x0,0,ppstm), HVar2 == 0)
     ) {
    pv = (ushort *)FUN_405257c0(param_2);
    local_40[0] = 0x24;
    local_40[3] = (**(code **)(*piVar3 + 0x60))(piVar3);
    local_20 = FUN_40537d04(pv);
    local_40[1] = 1;
    local_40[2] = 0;
    HVar2 = IStream_Write(*ppstm,local_40,local_40[0]);
    if (-1 < HVar2) {
      HVar2 = IStream_Write(*ppstm,pv,local_20);
    }
    FUN_40537f64((int)pv);
  }
  if (HVar2 < 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = 0;
  }
  FUN_40542538(local_1c);
  return uVar1;
}



/* 40528024 FUN_40528024 */

/* Boundary evidence: original MIPS .pdata 40528024..4052814b. Semantic name remains unreviewed. */

int FUN_40528024(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
  local_20 = (int *)0x0;
  iVar1 = (**(code **)(*param_2 + 0x48))(param_2,&local_20);
  if ((iVar1 == 0) && (local_20 != (int *)0x0)) {
    iVar1 = (**(code **)*local_20)(local_20,&DAT_4051675c,&local_1c);
    (**(code **)(*local_20 + 8))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_1c + 0x1b0))(local_1c,local_18);
      (**(code **)(*local_1c + 8))();
      if (iVar1 == 0) {
        iVar2 = FUN_4052e694(local_18[0]);
        (**(code **)(*local_18[0] + 8))();
        if ((iVar2 == 0) && (piVar3 = *(int **)(param_1 + 0x98), piVar3 != (int *)0x0)) {
          iVar1 = (**(code **)(*piVar3 + 0x10))(piVar3,&DAT_405163ec,0x48,0,0,0);
        }
      }
    }
  }
  return iVar1;
}



/* 4052814c FUN_4052814c */

/* Boundary evidence: original MIPS .pdata 4052814c..40528173. Semantic name remains unreviewed. */

void FUN_4052814c(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0xc) + 0x14))();
  return;
}



/* 40528174 FUN_40528174 */

/* Boundary evidence: original MIPS .pdata 40528174..4052819b. Semantic name remains unreviewed. */

void FUN_40528174(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0xc) + 0x18))();
  return;
}



/* 4052819c FUN_4052819c */

/* Boundary evidence: original MIPS .pdata 4052819c..4052826f. Semantic name remains unreviewed. */

undefined4 FUN_4052819c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18;
  int *local_14;
  
  local_14 = (int *)0x0;
  local_18 = (int *)0x0;
  uVar2 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xb4) + 0x3c))
                    (*(int **)(param_1 + 0xb4),0,&DAT_4051675c,&local_14);
  if (((iVar1 == 0) && (iVar1 = (**(code **)(*local_14 + 0x1b0))(local_14,&local_18), iVar1 == 0))
     && (iVar1 = SHIsSameObject(param_2,local_18), iVar1 != 0)) {
    uVar2 = 1;
  }
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))();
  }
  return uVar2;
}



/* 40528270 FUN_40528270 */

/* Boundary evidence: original MIPS .pdata 40528270..405282d3. Semantic name remains unreviewed. */

void FUN_40528270(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  (**(code **)(*(int *)(param_1 + 4) + 0xc))
            ((int *)(param_1 + 4),0,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
             param_10);
  return;
}



/* 405282d4 FUN_405282d4 */

/* Boundary evidence: original MIPS .pdata 405282d4..4052838f. Semantic name remains unreviewed. */

HRESULT FUN_405282d4(int param_1,IUnknown *param_2,void **param_3)

{
  HRESULT HVar1;
  int *piVar2;
  
  if (((*(int *)(param_1 + 0x374) == 0) || (*(void **)(param_1 + 0x378) == (void *)0x0)) ||
     (*(int *)(param_1 + 0x37c) == 0)) {
    if (param_2 != (IUnknown *)0x0) {
      HVar1 = IUnknown_QueryService(param_2,(GUID *)&DAT_4051645c,(IID *)&DAT_405162cc,param_3);
      return HVar1;
    }
    piVar2 = *(int **)(param_1 + 0x7c);
    *param_3 = piVar2;
    if (piVar2 == (int *)0x0) {
      return -0x7fffbffb;
    }
    (**(code **)(*piVar2 + 4))();
  }
  else {
    *param_3 = *(void **)(param_1 + 0x378);
    (**(code **)(**(int **)(param_1 + 0x378) + 4))();
  }
  return 0;
}



/* 40528390 FUN_40528390 */

/* Boundary evidence: original MIPS .pdata 40528390..4052841f. Semantic name remains unreviewed. */

undefined4 FUN_40528390(int param_1,int *param_2)

{
  int iVar1;
  BSTR pOVar2;
  char *pcVar3;
  undefined4 uVar4;
  wchar_t awStack_1058 [2084];
  uint local_10;
  
  local_10 = DAT_40544354;
  pcVar3 = *(char **)(param_1 + 0x60);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = *(char **)(param_1 + 0x4c);
  }
  iVar1 = FUN_4052d3dc(pcVar3,-0x4110fffe,awStack_1058,0x824);
  if (iVar1 != 0) {
    pOVar2 = SysAllocString(awStack_1058);
    *param_2 = (int)pOVar2;
  }
  if (*param_2 == 0) {
    uVar4 = 0x80004005;
  }
  else {
    uVar4 = 0;
  }
  FUN_40542538(local_10);
  return uVar4;
}



/* 40528420 FUN_40528420 */

/* Boundary evidence: original MIPS .pdata 40528420..40528473. Semantic name remains unreviewed. */

undefined4 FUN_40528420(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == 0) || (param_3 == (undefined4 *)0x0)) {
    uVar2 = 0x80070057;
  }
  else {
    uVar1 = FUN_40522fa8();
    *param_3 = uVar1;
  }
  return uVar2;
}



/* 40528474 FUN_40528474 */

/* Boundary evidence: original MIPS .pdata 40528474..405284db. Semantic name remains unreviewed. */

void FUN_40528474(int param_1,ushort *param_2)

{
  void *pvVar1;
  
  FUN_40537f64(*(int *)(param_1 + 0x9c));
  pvVar1 = FUN_4052d908(param_2);
  *(void **)(param_1 + 0x9c) = pvVar1;
  (**(code **)(**(int **)(param_1 + 0x60) + 0x44))();
  *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfffffdff;
  return;
}



/* 405284dc FUN_405284dc */

/* Boundary evidence: original MIPS .pdata 405284dc..4052854b. Semantic name remains unreviewed. */

void FUN_405284dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18 [4];
  undefined4 *local_10;
  
  iVar1 = *(int *)(param_1 + 0xb4);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xa0);
  }
  local_10 = &local_20;
  local_18[0] = 0x1a;
  local_20 = param_2;
  local_1c = param_3;
  IUnknown_Exec(iVar1,&DAT_405163ec,0x45,0,local_18,0);
  return;
}



/* 4052854c FUN_4052854c */

/* Boundary evidence: original MIPS .pdata 4052854c..40528647. Semantic name remains unreviewed. */

HRESULT FUN_4052854c(int param_1,IUnknown *param_2,uint param_3)

{
  BSTR bstrString;
  LPCITEMIDLIST pIVar1;
  HRESULT HVar2;
  IUnknown *local_28 [2];
  
  if (param_2 == (IUnknown *)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else {
    HVar2 = -0x7fffbffb;
    bstrString = (BSTR)FUN_40525888(param_2);
    if (bstrString != (BSTR)0x0) {
      pIVar1 = (LPCITEMIDLIST)FUN_405258ec(param_1 + -0x50,bstrString,(int *)0x0);
      if (pIVar1 != (LPCITEMIDLIST)0x0) {
        if ((param_3 & 2) == 0) {
          param_2 = (IUnknown *)0x0;
        }
        HVar2 = FUN_405282d4(param_1 + -0x50,param_2,local_28);
        if (HVar2 == 0) {
          FUN_40535834(local_28[0],local_28[0],pIVar1);
          (*local_28[0]->lpVtbl->Release)(local_28[0]);
        }
        FUN_40537f64((int)pIVar1);
      }
      SysFreeString(bstrString);
    }
  }
  return HVar2;
}



/* 40528648 FUN_40528648 */

/* Boundary evidence: original MIPS .pdata 40528648..40528663. Semantic name remains unreviewed. */

void FUN_40528648(int param_1)

{
  FUN_405265d4(param_1 + -0x50);
  return;
}



/* 40528664 FUN_40528664 */

/* Boundary evidence: original MIPS .pdata 40528664..4052867f. Semantic name remains unreviewed. */

void FUN_40528664(int param_1)

{
  FUN_405265d4(param_1 + -0x50);
  return;
}



/* 40528680 FUN_40528680 */

/* Boundary evidence: original MIPS .pdata 40528680..40528763. Semantic name remains unreviewed. */

undefined4 FUN_40528680(int param_1,int *param_2)

{
  BSTR pOVar1;
  undefined4 uVar2;
  int iVar3;
  OLECHAR *local_20 [2];
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80004003;
  }
  else {
    *param_2 = 0;
    iVar3 = *(int *)(param_1 + 0x60);
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x4c);
    }
    FUN_40520168((int *)local_20,0x825);
    if (local_20[0] == (OLECHAR *)0x0) {
      operator_delete((void *)0x0);
      uVar2 = 0x8007000e;
    }
    else {
      iVar3 = (**(code **)(*(int *)(param_1 + -0x3c) + 0x28))
                        ((int *)(param_1 + -0x3c),iVar3,local_20[0],0x8000);
      if (iVar3 == 0) {
        pOVar1 = SysAllocString(local_20[0]);
        *param_2 = (int)pOVar1;
      }
      if (*param_2 == 0) {
        uVar2 = 0x80004005;
      }
      else {
        uVar2 = 0;
      }
      operator_delete(local_20[0]);
    }
  }
  return uVar2;
}



/* 40528764 FUN_40528764 */

/* Boundary evidence: original MIPS .pdata 40528764..40528787. Semantic name remains unreviewed. */

void FUN_40528764(int param_1,STRSAFE_LPCWSTR param_2)

{
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x328),0x825,param_2);
  return;
}



/* 40528bc0 FUN_40528bc0 */

/* Boundary evidence: original MIPS .pdata 40528bc0..40528c0b. Semantic name remains unreviewed. */

undefined4 * FUN_40528bc0(undefined4 *param_1,uint param_2)

{
  FUN_40522fb0(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40528c0c FUN_40528c0c */

/* WARNING: Removing unreachable block (ram,0x40528c68) */
/* WARNING: Removing unreachable block (ram,0x40528c80) */
/* WARNING: Removing unreachable block (ram,0x40528c90) */
/* Boundary evidence: original MIPS .pdata 40528c0c..40528cc3. Semantic name remains unreviewed. */

bool FUN_40528c0c(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = DAT_40544354;
  if (param_2 != (int *)0x0) {
    FUN_4052d52c(param_2);
  }
  FUN_40542538(uVar1);
  return false;
}



/* 40528cc4 FUN_40528cc4 */

/* Boundary evidence: original MIPS .pdata 40528cc4..40528d13. Semantic name remains unreviewed. */

void FUN_40528cc4(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x11c) != 0) && (iVar1 = FUN_40523994(param_1), iVar1 != 0)) {
    PostMessageW(*(HWND *)(param_1 + 0x70),0x700,0,0);
  }
  return;
}



/* 40528d14 FUN_40528d14 */

/* Boundary evidence: original MIPS .pdata 40528d14..40528d63. Semantic name remains unreviewed. */

undefined4 FUN_40528d14(int param_1)

{
  *(undefined4 *)(param_1 + 0x108) = 0;
  FUN_40524a38(param_1 + -0x14,(int *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0x108) = 3;
  PostMessageW(*(HWND *)(param_1 + 0x5c),0x700,0,0);
  return 0;
}



/* 40528d64 FUN_40528d64 */

/* Boundary evidence: original MIPS .pdata 40528d64..40528e77. Semantic name remains unreviewed. */

undefined4 FUN_40528d64(int *param_1)

{
  void **ppunk;
  
  ppunk = (void **)(param_1 + 0x28);
  if (*ppunk != (int *)0x0) {
    (**(code **)(*(int *)*ppunk + 0x28))();
    (**(code **)(param_1[6] + 0xc))(param_1 + 6,*ppunk,4);
    IUnknown_AtomicRelease(ppunk);
    IUnknown_AtomicRelease((void **)(param_1 + 0x29));
    param_1[0x2a] = 0;
    FUN_40525568((int)(param_1 + -5),(short *)0x0);
    (**(code **)(*param_1 + 0x38))(param_1,0);
    if (param_1[0x27] != 0) {
      FUN_40537f64(param_1[0x27]);
      param_1[0x27] = 0;
    }
    if ((HLOCAL)param_1[0x2b] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_1[0x2b]);
      param_1[0x2b] = 0;
    }
    (**(code **)(*(int *)param_1[0x13] + 0x48))();
    FUN_40524040((int)(param_1 + -5));
    (**(code **)(*param_1 + 0xf8))(param_1,(uint)param_1[0x4a] >> 6 & 1);
  }
  return 0;
}



/* 40528e78 FUN_40528e78 */

/* Boundary evidence: original MIPS .pdata 40528e78..4052901b. Semantic name remains unreviewed. */

undefined4 FUN_40528e78(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar5 = *(int **)(param_1 + 0xa0);
  piVar3 = (int *)(param_1 + -0x14);
  uVar6 = *(undefined4 *)(param_1 + 0xa4);
  uVar7 = *(undefined4 *)(param_1 + 0xa8);
  uVar4 = *(undefined4 *)(param_1 + 0x9c);
  uVar1 = FUN_4052320c(piVar3,piVar5);
  *(undefined4 *)(param_1 + 0xb0) = uVar1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  (**(code **)(**(int **)(param_1 + 0x4c) + 0xac))();
  if (*(int *)(param_1 + 0xfc) != -1) {
    (**(code **)(*piVar3 + 0x18))(piVar3,uVar4);
  }
  *(undefined4 *)(param_1 + 0x90) = uVar6;
  *(int **)(param_1 + 0x8c) = piVar5;
  FUN_40537f64(*(int *)(param_1 + 0x88));
  *(undefined4 *)(param_1 + 0x88) = uVar4;
  *(undefined4 *)(param_1 + 0x94) = uVar7;
  *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xf4);
  if (*(HLOCAL *)(param_1 + 0x98) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x98));
  }
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (*(int *)(param_1 + 0x140) != -1) {
    *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x140);
    *(undefined4 *)(param_1 + 0x140) = 0xffffffff;
  }
  (**(code **)(**(int **)(param_1 + 0x4c) + 0x130))();
  SetWindowPos(*(HWND *)(param_1 + 0x94),(HWND)0x1,0,0,0,0,0x13);
  puVar2 = *(undefined4 **)(param_1 + 0x8c);
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(puVar2,&DAT_4051646c,param_1 + 0x84);
  }
  FUN_40527c68((int)piVar3);
  piVar3 = *(int **)(param_1 + 0x84);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x10))(piVar3,&DAT_405163ec,0x37,0,0,0);
  }
  return 0;
}



/* 4052901c FUN_4052901c */

/* Boundary evidence: original MIPS .pdata 4052901c..4052914f. Semantic name remains unreviewed. */

undefined4 FUN_4052901c(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *local_18 [2];
  
  uVar3 = param_1[0x4a];
  if ((uVar3 & 0x20000) == 0) {
    param_1[0x4a] = uVar3 | 0x20000;
    if (param_1[0x31] == 0) {
      (**(code **)(*param_1 + 0xf0))(param_1);
      (**(code **)(*(int *)param_1[0x13] + 0xac))();
      IUnknown_AtomicRelease((void **)(param_1 + 0x18));
      (**(code **)(*(int *)param_1[0x1c] + 0xc))((int *)param_1[0x1c],0);
      param_1[0x17] = 0;
      if ((HDPA)param_1[0x40] != (HDPA)0x0) {
        DPA_DestroyCallback((HDPA)param_1[0x40],FUN_40525374,(void *)0x0);
        param_1[0x40] = 0;
      }
      puVar2 = (undefined4 *)param_1[0x2f];
      if ((puVar2 != (undefined4 *)0x0) &&
         (iVar1 = (**(code **)*puVar2)(puVar2,&DAT_405135c4,local_18), -1 < iVar1)) {
        (**(code **)(*local_18[0] + 0x10))();
        (**(code **)(*local_18[0] + 8))();
      }
      IUnknown_AtomicRelease((void **)(param_1 + 0x39));
      IUnknown_AtomicRelease((void **)(param_1 + 0x3a));
    }
    else {
      param_1[0x4a] = uVar3 | 0x22000;
    }
  }
  return 0;
}



/* 40529150 FUN_40529150 */

/* Boundary evidence: original MIPS .pdata 40529150..40529513. Semantic name remains unreviewed. */

undefined4 FUN_40529150(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  BOOL BVar5;
  BSTR bstrString;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int *local_250;
  int local_24c;
  _union_2683 local_248;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40544354;
  iVar3 = FUN_40523994(param_1);
  if (iVar3 == 0) {
    uVar8 = 1;
    *(undefined4 *)(param_1 + 0x11c) = 1;
    FUN_40542538(local_30);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x120);
    uVar9 = *(uint *)(param_1 + 0x124);
    *(undefined4 *)(param_1 + 0x124) = 0;
    *(undefined4 *)(param_1 + 0x120) = 0;
    local_24c = iVar3;
    if ((iVar3 == 0) || (iVar3 == -2)) {
      (**(code **)(*(int *)(param_1 + 0x14) + 0xf0))();
      if (iVar3 == -2) {
        (**(code **)(**(int **)(param_1 + 0x60) + 0xac))();
      }
      else if (*(int *)(param_1 + 0x9c) == 0) {
        iVar3 = FUN_40520600();
        if ((iVar3 < 0) || (BVar5 = PathFileExistsW(aWStack_238), BVar5 == 0)) {
          StringCchCopyW(aWStack_238,0x104,L"shell:Desktop");
        }
        bstrString = SysAllocString(aWStack_238);
        if (bstrString != (BSTR)0x0) {
          (**(code **)(**(int **)(param_1 + 0x7c) + 0x2c))
                    (*(int **)(param_1 + 0x7c),bstrString,0,0,0,0);
          SysFreeString(bstrString);
        }
      }
    }
    else {
      uVar7 = 0;
      if ((uVar9 & 0x8000000) != 0) {
        uVar7 = 0x8000000;
      }
      if ((uVar9 & 0x4000000) != 0) {
        uVar7 = uVar7 | 0x4000000;
      }
      if ((uVar9 & 0x2000000) != 0) {
        uVar7 = uVar7 | 0x2000000;
      }
      if ((uVar9 & 0x800000) != 0) {
        uVar7 = uVar7 | 0x200000;
      }
      if ((uVar9 & 0x1000000) != 0) {
        uVar7 = uVar7 | 0x1000000;
      }
      if ((uVar9 & 0x10000000) != 0) {
        uVar7 = uVar7 | 0x400000;
      }
      if ((uVar9 & 0x20000) != 0) {
        uVar7 = uVar7 | 0x100000;
      }
      uVar6 = 0xffffffff;
      if (iVar3 == -1) {
        iVar3 = 0;
        local_24c = 0;
        if ((uVar9 & 0x4000) == 0) {
          uVar6 = uVar7;
          if ((uVar9 & 0x8000) != 0) {
            uVar6 = 8;
          }
        }
        else {
          uVar6 = 4;
        }
      }
      else if (uVar9 != 0xffffffff) {
        uVar6 = uVar7;
        if ((uVar9 & 0x40000000) != 0) {
          uVar6 = uVar7 | 0x20;
        }
        bVar1 = (uVar9 & 0x10000) != 0;
        uVar7 = 1;
        if (bVar1) {
          uVar6 = uVar6 | 0x20000000;
        }
        iVar4 = (**(code **)(**(int **)(param_1 + 0x6c) + 0xc))
                          (*(int **)(param_1 + 0x6c),&DAT_4051664c,&DAT_405162cc,&local_250);
        piVar2 = local_250;
        if ((-1 < iVar4) && (local_250 != (int *)0x0)) {
          memset(&local_248,0,0x10);
          (**(code **)(*piVar2 + 0x8c))(piVar2,L"{265b75c1-4158-11d0-90f6-00c04fd497ea}",&local_248)
          ;
          if (local_248.n2.vt == 3) {
            uVar7 = (uint)bVar1 | local_248._8_4_ & 0xfffffffe;
          }
          else {
            FUN_4052eac4((VARIANTARG *)&local_248.n2);
            local_248.n2.vt = 3;
            if (!bVar1) {
              uVar7 = 0;
            }
          }
          local_248._8_4_ = uVar7;
          (**(code **)(*local_250 + 0x88))
                    (local_250,L"{265b75c1-4158-11d0-90f6-00c04fd497ea}",local_248._0_4_,
                     local_248.decVal.Hi32,uVar7,local_248._12_4_);
          (**(code **)(*local_250 + 8))();
        }
      }
      (**(code **)(**(int **)(param_1 + 0x60) + 0x100))(*(int **)(param_1 + 0x60),iVar3,uVar6,uVar9)
      ;
    }
    FUN_40524a38(param_1,&local_24c);
    FUN_40542538(local_30);
    uVar8 = 0;
  }
  return uVar8;
}



/* 40529514 FUN_40529514 */

/* Boundary evidence: original MIPS .pdata 40529514..4052955f. Semantic name remains unreviewed. */

undefined4 FUN_40529514(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + 1;
  }
  else if (*(int *)(param_1 + 0x118) != 0) {
    *(int *)(param_1 + 0x118) = *(int *)(param_1 + 0x118) + -1;
  }
  FUN_40528cc4(param_1 + -0x10);
  return 0;
}



/* 40529560 FUN_40529560 */

/* Boundary evidence: original MIPS .pdata 40529560..4052960f. Semantic name remains unreviewed. */

undefined4 FUN_40529560(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *local_18 [2];
  
  piVar2 = *(int **)(param_1 + 0xb4);
  uVar3 = 0x80004005;
  local_18[0] = (int *)0x0;
  if ((((piVar2 != (int *)0x0) || (piVar2 = *(int **)(param_1 + 0xa0), piVar2 != (int *)0x0)) &&
      (iVar1 = (**(code **)(*piVar2 + 0x3c))(piVar2,0,&UNK_40513e94,local_18), -1 < iVar1)) &&
     (local_18[0] != (int *)0x0)) {
    uVar3 = (**(code **)(*local_18[0] + 0xc))(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return uVar3;
}



/* 40529610 FUN_40529610 */

/* Boundary evidence: original MIPS .pdata 40529610..4052976f. Semantic name remains unreviewed. */

int FUN_40529610(int param_1,undefined2 *param_2)

{
  bool bVar1;
  LPCITEMIDLIST pIVar2;
  undefined2 uVar3;
  OLECHAR *pOVar4;
  int iVar5;
  LPCWSTR local_30;
  IUnknown *local_2c;
  int local_28 [2];
  
  if (param_2 == (undefined2 *)0x0) {
    iVar5 = -0x7fffbffd;
  }
  else {
    local_30 = (LPCWSTR)0x0;
    local_2c = (IUnknown *)0x0;
    local_28[0] = 0;
    bVar1 = false;
    iVar5 = FUN_40529560(param_1 + -0x5c,&local_30);
    if ((-1 < iVar5) && (local_30 != (LPCWSTR)0x0)) {
      pIVar2 = (LPCITEMIDLIST)FUN_405257c0(local_30);
      if (pIVar2 != (LPCITEMIDLIST)0x0) {
        iVar5 = FUN_405282d4(param_1 + -0x5c,(IUnknown *)0x0,&local_2c);
        if (iVar5 == 0) {
          pOVar4 = (OLECHAR *)(param_1 + 0x324);
          if (*(int *)(param_1 + 0x318) == 0) {
            pOVar4 = (OLECHAR *)0x0;
          }
          FUN_40535b0c(local_2c,*(undefined4 *)(param_1 + 0x14),local_2c,pIVar2,0,0x80,pOVar4,
                       (void *)0x0,0,(OLECHAR *)0x0,local_28);
          uVar3 = 0xffff;
          if (local_28[0] == 0) {
            uVar3 = 0;
          }
          *param_2 = uVar3;
          bVar1 = true;
        }
        FUN_40537f64((int)pIVar2);
      }
      SysFreeString(local_30);
    }
    IUnknown_AtomicRelease(&local_2c);
    if ((!bVar1) && (-1 < iVar5)) {
      iVar5 = -0x7fffbffb;
    }
  }
  return iVar5;
}



/* 40529770 FUN_40529770 */

/* Boundary evidence: original MIPS .pdata 40529770..405297fb. Semantic name remains unreviewed. */

HRESULT FUN_40529770(int param_1,undefined4 param_2,LPCITEMIDLIST param_3,IUnknown *param_4,
                    uint param_5)

{
  HRESULT HVar1;
  IUnknown *local_18 [2];
  
  local_18[0] = (IUnknown *)0x0;
  if ((param_5 & 2) == 0) {
    param_4 = (IUnknown *)0x0;
  }
  HVar1 = FUN_405282d4(param_1,param_4,local_18);
  if (HVar1 == 0) {
    FUN_405355d4(local_18[0],local_18[0],param_3);
  }
  IUnknown_AtomicRelease(local_18);
  return HVar1;
}



/* 405297fc FUN_405297fc */

/* Boundary evidence: original MIPS .pdata 405297fc..405298eb. Semantic name remains unreviewed. */

int FUN_405297fc(int param_1)

{
  bool bVar1;
  int iVar2;
  LPCITEMIDLIST pIVar3;
  int iVar4;
  IUnknown *local_20;
  LPCWSTR local_1c;
  
  iVar4 = param_1 + -0x5c;
  local_1c = (LPCWSTR)0x0;
  local_20 = (IUnknown *)0x0;
  bVar1 = false;
  iVar2 = FUN_40529560(iVar4,&local_1c);
  if (-1 < iVar2) {
    if (local_1c != (LPCWSTR)0x0) {
      pIVar3 = (LPCITEMIDLIST)FUN_405258ec(iVar4,local_1c,(int *)0x0);
      if (pIVar3 != (LPCITEMIDLIST)0x0) {
        iVar2 = FUN_405282d4(iVar4,(IUnknown *)0x0,&local_20);
        bVar1 = iVar2 == 0;
        if (bVar1) {
          FUN_40535834(local_20,local_20,pIVar3);
          (*local_20->lpVtbl->Release)(local_20);
        }
        FUN_40537f64((int)pIVar3);
      }
      SysFreeString(local_1c);
      if (bVar1) {
        return iVar2;
      }
    }
    if (-1 < iVar2) {
      iVar2 = -0x7fffbffb;
    }
  }
  return iVar2;
}



/* 405298ec FUN_405298ec */

/* Boundary evidence: original MIPS .pdata 405298ec..405299ff. Semantic name remains unreviewed. */

HRESULT FUN_405298ec(int param_1,IUnknown *param_2,STRSAFE_LPCWSTR param_3,OLECHAR *param_4,
                    undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  HRESULT HVar2;
  LPCITEMIDLIST pIVar3;
  IUnknown *local_1070 [2];
  wchar_t awStack_1068 [2084];
  uint local_20;
  
  local_20 = DAT_40544354;
  local_1070[0] = (IUnknown *)0x0;
  *param_6 = 0;
  if ((param_2 == (IUnknown *)0x0) || (iVar1 = FUN_4052e694((int *)param_2), iVar1 == 0)) {
    param_2 = (IUnknown *)0x0;
  }
  HVar2 = FUN_405282d4(param_1 + -0x50,param_2,local_1070);
  if (HVar2 == 0) {
    if (param_3 == (STRSAFE_LPCWSTR)0x0) {
      param_3 = L"";
    }
    StringCchCopyW(awStack_1068,0x824,param_3);
    pIVar3 = (LPCITEMIDLIST)FUN_405257c0(awStack_1068);
    if (pIVar3 != (LPCITEMIDLIST)0x0) {
      FUN_40535f68(local_1070[0],local_1070[0],pIVar3,param_4,param_5,param_6);
      FUN_40537f64((int)pIVar3);
    }
  }
  IUnknown_AtomicRelease(local_1070);
  FUN_40542538(local_20);
  return HVar2;
}



/* 40529a00 FUN_40529a00 */

/* Boundary evidence: original MIPS .pdata 40529a00..40529a8f. Semantic name remains unreviewed. */

HRESULT FUN_40529a00(int param_1,IUnknown *param_2,undefined4 param_3)

{
  int iVar1;
  HRESULT HVar2;
  IUnknown *local_18 [2];
  
  local_18[0] = (IUnknown *)0x0;
  if ((param_2 == (IUnknown *)0x0) || (iVar1 = FUN_4052e694((int *)param_2), iVar1 == 0)) {
    param_2 = (IUnknown *)0x0;
  }
  HVar2 = FUN_405282d4(param_1 + -0x50,param_2,local_18);
  if (HVar2 == 0) {
    FUN_405361d0(local_18[0],local_18[0],param_3);
  }
  IUnknown_AtomicRelease(local_18);
  return HVar2;
}



/* 40529a90 FUN_40529a90 */

/* Boundary evidence: original MIPS .pdata 40529a90..40529b2f. Semantic name remains unreviewed. */

HRESULT FUN_40529a90(int param_1,IUnknown *param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  HRESULT HVar2;
  IUnknown *local_20 [2];
  
  local_20[0] = (IUnknown *)0x0;
  if ((param_2 == (IUnknown *)0x0) || (iVar1 = FUN_4052e694((int *)param_2), iVar1 == 0)) {
    param_2 = (IUnknown *)0x0;
  }
  HVar2 = FUN_405282d4(param_1 + -0x50,param_2,local_20);
  if (HVar2 == 0) {
    FUN_405362c0(local_20[0],local_20[0],param_3,param_4);
  }
  IUnknown_AtomicRelease(local_20);
  return HVar2;
}



/* 40529b30 FUN_40529b30 */

/* Boundary evidence: original MIPS .pdata 40529b30..40529b97. Semantic name remains unreviewed. */

HRESULT FUN_40529b30(int param_1)

{
  HRESULT HVar1;
  undefined4 *local_18 [2];
  
  local_18[0] = (undefined4 *)0x0;
  HVar1 = FUN_405282d4(param_1 + -0x50,(IUnknown *)0x0,local_18);
  if (HVar1 == 0) {
    FUN_40536428(local_18[0]);
  }
  IUnknown_AtomicRelease(local_18);
  return HVar1;
}



/* 40529b98 FUN_40529b98 */

/* Boundary evidence: original MIPS .pdata 40529b98..40529d37. Semantic name remains unreviewed. */

undefined4 FUN_40529b98(int param_1,LPCWSTR param_2,ushort *param_3,uint param_4,int param_5)

{
  void *pvVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (*(int *)(param_1 + 0xb4) == 0) {
    iVar3 = FUN_4053ad2c(param_2);
    if ((iVar3 != 0xf) && (iVar3 != 0x10)) {
      FUN_40528474(param_1,param_3);
    }
    BVar2 = IsWindowVisible(*(HWND *)(param_1 + 0x70));
    if ((BVar2 != 0) && ((*(uint *)(param_1 + 0x124) & 0x8000000) == 0)) {
      FUN_4052da64(L"ActivatingDocument",0);
    }
  }
  else {
    FUN_40537f64(*(int *)(param_1 + 0xb0));
    pvVar1 = FUN_4052d908(param_3);
    *(void **)(param_1 + 0xb0) = pvVar1;
    *(uint *)(param_1 + 0x13c) =
         ((uint)((param_4 & 1) != 0) << 0x12 ^ *(uint *)(param_1 + 0x13c)) & 0x40000 ^
         *(uint *)(param_1 + 0x13c);
    (**(code **)(**(int **)(param_1 + 0x60) + 0xb0))();
    uVar5 = 1;
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfffbffff;
  }
  if (param_5 == 0) {
    FUN_405284dc(param_1,param_3,0);
  }
  else {
    iVar3 = FUN_405257c0(param_2);
    if (iVar3 != 0) {
      FUN_405284dc(param_1,iVar3,param_5);
      FUN_40537f64(iVar3);
    }
  }
  piVar4 = *(int **)(param_1 + 0x60);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x118))(piVar4,0xffffffff);
  }
  return uVar5;
}



/* 40529d38 FUN_40529d38 */

/* Boundary evidence: original MIPS .pdata 40529d38..40529eeb. Semantic name remains unreviewed. */

undefined4 FUN_40529d38(int param_1)

{
  HWND pHVar1;
  uint uVar2;
  code *pcVar3;
  int *piVar4;
  
  if (*(int *)(param_1 + 0xc4) == 0) {
    if (*(int *)(param_1 + 0x8c) != 0) {
      (**(code **)(**(int **)(param_1 + 0x54) + 0x24))(*(int **)(param_1 + 0x54),0);
      pHVar1 = GetCapture();
      if ((pHVar1 != (HWND)0x0) && (pHVar1 == *(HWND *)(param_1 + 0x5c))) {
        SendMessageW(*(HWND *)(param_1 + 0x5c),0x1f,0,0);
      }
      uVar2 = *(uint *)(param_1 + 0x128);
      *(uint *)(param_1 + 0x128) = uVar2 | 1;
      if (*(int *)(param_1 + 0xb0) == 0) {
        pcVar3 = *(code **)(*(int *)(param_1 + 0x18) + 0xc);
        *(uint *)(param_1 + 0x128) = uVar2 | 0x801;
        (*pcVar3)((int *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x8c),4);
        *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & 0xfffff7ff;
      }
      piVar4 = *(int **)(param_1 + 0x8c);
      *(undefined4 *)(param_1 + 0x8c) = 0;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x1c))(piVar4,0);
        IUnknown_AtomicRelease((void **)(param_1 + 0x84));
        (**(code **)(*piVar4 + 0x34))(piVar4);
        (**(code **)(*piVar4 + 0x28))(piVar4);
        (**(code **)(*piVar4 + 8))(piVar4);
        *(undefined4 *)(param_1 + 0x94) = 0;
        *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & 0xfffffffe;
        if (*(int *)(param_1 + 0x88) != 0) {
          FUN_40537f64(*(int *)(param_1 + 0x88));
          *(undefined4 *)(param_1 + 0x88) = 0;
        }
      }
      (**(code **)(**(int **)(param_1 + 0x54) + 0x24))(*(int **)(param_1 + 0x54),1);
      FUN_40528cc4(param_1 + -0x14);
    }
    IUnknown_AtomicRelease((void **)(param_1 + 0x90));
    if (*(HLOCAL *)(param_1 + 0x98) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x98));
      *(undefined4 *)(param_1 + 0x98) = 0;
    }
    SetRect((LPRECT)(param_1 + 0x118),0,0,0,0);
  }
  return 0;
}



/* 40529eec FUN_40529eec */

/* Boundary evidence: original MIPS .pdata 40529eec..4052a03b. Semantic name remains unreviewed. */

undefined4 FUN_40529eec(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined2 local_20;
  undefined1 auStack_1e [6];
  short local_18;
  
  *(undefined4 *)(param_1 + 0x11c) = 0;
  FUN_40524a38(param_1,(int *)(param_1 + 0x120));
  uVar1 = 1;
  if (*(int **)(param_1 + 0xb4) == (int *)0x0) goto LAB_4052a020;
  if ((*(int *)(param_1 + 0xcc) == 0) &&
     (iVar2 = FUN_4052320c(param_1,*(int **)(param_1 + 0xb4)), iVar2 != 0)) {
    local_20 = 0;
    memset(auStack_1e,0,0xe);
    if (*(int *)(param_1 + 0x15c) != 0) {
      iVar2 = IUnknown_Exec(*(undefined4 *)(param_1 + 0xb4),&DAT_405163ec,0x58,0,0,&local_20);
      if ((-1 < iVar2) && (local_18 != 0)) goto LAB_40529fd8;
    }
    local_20 = 0xb;
    local_18 = 0xffff;
    IUnknown_Exec(*(undefined4 *)(param_1 + 0xb4),0,0x17,0,&local_20,0);
  }
  else {
LAB_40529fd8:
    piVar3 = *(int **)(param_1 + 0x78);
    if ((piVar3 != (int *)0x0) && (param_2 == 0)) {
      (**(code **)(*piVar3 + 0x14))(piVar3,0,0,0,0);
    }
    (**(code **)(*(int *)(param_1 + 0x14) + 0xf0))();
  }
  uVar1 = 0;
LAB_4052a020:
  *(undefined4 *)(param_1 + 0xcc) = 0;
  return uVar1;
}



/* 4052a03c FUN_4052a03c */

/* Boundary evidence: original MIPS .pdata 4052a03c..4052a46f. Semantic name remains unreviewed. */

int FUN_4052a03c(int param_1,int *param_2,ushort *param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  IUnknown *local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [16];
  
  local_40 = (IUnknown *)0x0;
  bVar1 = false;
  iVar2 = FUN_40523994(param_1);
  if (iVar2 == 0) {
    iVar2 = -0x7ff8ff56;
  }
  else {
    piVar6 = (int *)(param_1 + 0x14);
    iVar2 = (**(code **)(*piVar6 + 0xf4))(piVar6);
    if (iVar2 == 1) {
      iVar2 = -0x7ff8fb39;
    }
    else {
      if (((*(int *)(param_1 + 0xa0) != 0) && (*(int **)(param_1 + 0xb4) != (int *)0x0)) &&
         (iVar2 = FUN_4052320c(param_1,*(int **)(param_1 + 0xb4)), iVar2 != 0)) {
        *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 0x80000;
      }
      (**(code **)(*piVar6 + 0xf0))(piVar6);
      if ((*(int **)(param_1 + 0xa0) != (int *)0x0) &&
         (iVar2 = FUN_4052320c(param_1,*(int **)(param_1 + 0xa0)), iVar2 != 0)) {
        IUnknown_AtomicRelease((void **)(param_1 + 0xfc));
        FUN_4052d52c(*(int **)(param_1 + 0xa0));
      }
      iVar2 = (**(code **)(*param_2 + 0x20))
                        (param_2,*(undefined4 *)(param_1 + 0x70),&DAT_405165ec,&local_40);
      if (-1 < iVar2) {
        *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 1;
        IUnknown_SetSite(local_40,*(IUnknown **)(param_1 + 0x68));
        (**(code **)(**(int **)(param_1 + 0x68) + 0x24))(*(int **)(param_1 + 0x68),0);
        local_3c = 0;
        (**(code **)(**(int **)(param_1 + 0x60) + 300))(*(int **)(param_1 + 0x60),auStack_38);
        *(IUnknown **)(param_1 + 0xb4) = local_40;
        (*local_40->lpVtbl->AddRef)(local_40);
        *(int **)(param_1 + 0xb8) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        pvVar3 = FUN_4052d908(param_3);
        *(undefined4 *)(param_1 + 0x108) = 4;
        uVar5 = *(uint *)(param_1 + 0x140);
        *(ushort **)(param_1 + 0x94) = param_3;
        *(void **)(param_1 + 0xb0) = pvVar3;
        *(uint *)(param_1 + 0x110) = param_4;
        if (((param_4 & 0x2000000) != 0) || ((param_4 & 0x200000) != 0)) {
          IUnknown_Exec(local_40,&DAT_405163ec,0x50,param_4,0,0);
        }
        iVar2 = (**(code **)(**(int **)(param_1 + 0x60) + 0xb4))
                          (*(int **)(param_1 + 0x60),local_40,*(undefined4 *)(param_1 + 0xa0),
                           auStack_38,&local_3c);
        IUnknown_SetSite(local_40,(IUnknown *)0x0);
        if ((param_4 & 0x1000000) != 0) {
          IUnknown_Exec(local_40,&DAT_405163ec,0x56,0,0,0);
        }
        *(undefined4 *)(param_1 + 0x94) = 0;
        if (iVar2 < 0) {
          if (((*(int **)(param_1 + 0xb4) == (int *)0x0) || ((*(uint *)(param_1 + 0x140) & 2) != 0))
             || (iVar4 = FUN_4052320c(param_1,*(int **)(param_1 + 0xb4)), iVar4 == 0)) {
            *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfff7ffff;
          }
          else {
            *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 0x80000;
          }
          (**(code **)(*piVar6 + 0xf0))(piVar6);
        }
        else {
          if ((uVar5 & 1) == 0) {
            FUN_4052338c(param_1);
          }
          *(undefined4 *)(param_1 + 0xbc) = local_3c;
          if (iVar2 != 0) {
            (**(code **)(**(int **)(param_1 + 0x60) + 0x48))();
          }
          bVar1 = iVar2 == 0;
        }
        (*local_40->lpVtbl->Release)(local_40);
        piVar6 = *(int **)(param_1 + 0x68);
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 0x24))(piVar6,1);
        }
      }
      *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) & 0xfff7ffff;
      FUN_40528cc4(param_1);
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xfffffffe;
      if (((bVar1) && (iVar4 = FUN_4052320c(param_1,*(int **)(param_1 + 0xb4)), iVar4 == 0)) &&
         (*(int *)(param_1 + 0xb4) != 0)) {
        *(undefined4 *)(param_1 + 0x11c) = 0;
        FUN_40524a38(param_1,(int *)(param_1 + 0x120));
        iVar2 = (**(code **)(**(int **)(param_1 + 0x60) + 0xb0))();
      }
    }
  }
  return iVar2;
}



/* 4052a470 FUN_4052a470 */

/* Boundary evidence: original MIPS .pdata 4052a470..4052a577. Semantic name remains unreviewed. */

int FUN_4052a470(int param_1,LPCITEMIDLIST param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int *local_28;
  IBindCtx *local_24;
  undefined4 local_20 [2];
  
  piVar2 = (int *)(param_1 + 0x14);
  (**(code **)(*piVar2 + 0x38))(piVar2,1);
  local_24 = (IBindCtx *)0x0;
  local_24 = FUN_4052e450((IUnknown *)(param_1 + 0x10));
  iVar1 = FUN_40522e30((ushort *)param_2,local_24,(int *)&local_28);
  if (iVar1 < 0) {
    local_20[0] = 0;
    FUN_40535f68(*(IUnknown **)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x7c),param_2,
                 (OLECHAR *)0x0,iVar1,local_20);
  }
  else {
    iVar1 = FUN_4052a03c(param_1,local_28,(ushort *)param_2,param_3);
    (**(code **)(*local_28 + 8))();
  }
  if (iVar1 < 0) {
    (**(code **)(*piVar2 + 0x38))(piVar2,0);
  }
  IUnknown_AtomicRelease(&local_24);
  return iVar1;
}



/* 4052a578 FUN_4052a578 */

/* Boundary evidence: original MIPS .pdata 4052a578..4052a9a7. Semantic name remains unreviewed. */

undefined4 FUN_4052a578(int param_1,undefined4 param_2,uint param_3,WPARAM param_4,LPARAM param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_28 [2];
  
  if (param_3 < 0x1e) {
    if (param_3 == 0x1d) {
LAB_4052a70c:
      (**(code **)(*(int *)(param_1 + -0x14) + 0x2c))
                ((int *)(param_1 + -0x14),param_3,param_4,param_5,1);
      return 0;
    }
    if (param_3 < 0xb) {
      if (param_3 == 10) {
        if (param_4 == 0) {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x128) & 0x200000) != 0) {
          return 0;
        }
        piVar4 = *(int **)(param_1 + 0x84);
        if (piVar4 == (int *)0x0) {
          return 0;
        }
        (**(code **)(*piVar4 + 0x10))(piVar4,&DAT_405163ec,0x4e,0,0,0);
        return 0;
      }
      if (param_3 == 1) {
        iVar2 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x94))(*(int **)(param_1 + 0x4c),param_5);
        if (iVar2 == 0) {
          return 0;
        }
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x9c))();
        return 0xffffffff;
      }
      if (param_3 == 2) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x9c))();
        return 0;
      }
      if (param_3 == 5) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x90))(*(int **)(param_1 + 0x4c),param_4);
        return 0;
      }
      if (param_3 == 7) {
        uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0xa4))();
        return uVar1;
      }
    }
    else {
      if (param_3 == 0x14) goto LAB_4052a8a8;
      if ((param_3 == 0x15) || (param_3 == 0x1a)) goto LAB_4052a70c;
    }
  }
  else if (param_3 < 0x312) {
    if (param_3 == 0x311) {
      if (*(int *)(param_1 + 0x94) == 0) {
        return 0;
      }
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x110))
                (*(int **)(param_1 + 0x4c),*(int *)(param_1 + 0x94),1,0x311,param_4,param_5);
      return 0;
    }
    if (param_3 == 0x20) {
      iVar2 = (**(code **)(*(int *)(param_1 + -0x14) + 0x28))((int *)(param_1 + -0x14),param_5);
      if (iVar2 != 0) {
        return 1;
      }
      goto LAB_4052a8a8;
    }
    if (param_3 == 0x4a) {
      return 0;
    }
    if (param_3 == 0x4e) {
      uVar1 = (**(code **)(**(int **)(param_1 + 0x4c) + 0xa0))(*(int **)(param_1 + 0x4c),param_5);
      return uVar1;
    }
    if (param_3 == 0x111) {
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x98))(*(int **)(param_1 + 0x4c),param_4,param_5);
      return 0;
    }
  }
  else {
    if (param_3 == 0x317) {
      if (*(HWND *)(param_1 + 0x94) == (HWND)0x0) {
        return 0;
      }
      SendMessageW(*(HWND *)(param_1 + 0x94),0x317,param_4,param_5);
      return 0;
    }
    if (param_3 == 0x407) {
      return *(undefined4 *)(param_1 + 0x54);
    }
    if (param_3 == 0x700) {
      iVar2 = *(int *)(param_1 + 0x108);
      *(undefined4 *)(param_1 + 0x108) = 0;
      if (iVar2 == 1) {
        FUN_40529150(param_1 + -0x14);
        return 0;
      }
      if (iVar2 != 2) {
        if (iVar2 != 3) {
          return 0;
        }
        FUN_40529eec(param_1 + -0x14,0);
        return 0;
      }
      if (*(int *)(param_1 + 0xa0) == 0) {
        return 0;
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0x4c) + 0xb0))();
      if (-1 < iVar2) {
        return 0;
      }
      if (*(int *)(param_1 + 0x114) == 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x108) = 2;
      return 0;
    }
  }
  if (param_3 == DAT_405445a8) {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 0x70))
                      (*(undefined4 **)(param_1 + 0x70),param_4,local_28);
    if (iVar2 < 0) {
      return 0;
    }
    return local_28[0];
  }
  uVar3 = FUN_4052e4cc();
  if ((param_3 == uVar3) && (*(HWND *)(param_1 + 0x94) != (HWND)0x0)) {
    PostMessageW(*(HWND *)(param_1 + 0x94),param_3,param_4,param_5);
    return 1;
  }
LAB_4052a8a8:
  uVar1 = (**(code **)(*(int *)(param_1 + -0x14) + 0x20))
                    ((int *)(param_1 + -0x14),param_2,param_3,param_4,param_5);
  return uVar1;
}



/* 4052a9a8 FUN_4052a9a8 */

/* Boundary evidence: original MIPS .pdata 4052a9a8..4052aad7. Semantic name remains unreviewed. */

void FUN_4052a9a8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  BOOL BVar2;
  
  bVar1 = false;
  if (param_4 == 0) {
    FUN_40529eec(param_1,0);
  }
  *(undefined4 *)(param_1 + 0x120) = param_2;
  *(undefined4 *)(param_1 + 0x124) = param_3;
  if (((*(int *)(param_1 + 0xa0) == 0) && (*(int *)(param_1 + 0xb4) == 0)) &&
     ((*(uint *)(param_1 + 0x13c) & 0x20) == 0)) {
    bVar1 = true;
  }
  else {
    *(undefined4 *)(param_1 + 0x11c) = 1;
    PostMessageW(*(HWND *)(param_1 + 0x70),0x700,0,0);
  }
  (**(code **)(*(int *)(param_1 + 0x2c) + 0xc))((int *)(param_1 + 0x2c),0,1);
  if (((*(int *)(param_1 + 0xa0) != 0) &&
      (BVar2 = IsWindowVisible(*(HWND *)(param_1 + 0x70)), BVar2 != 0)) &&
     (((*(uint *)(param_1 + 0x124) & 0x8000000) == 0 && ((*(uint *)(param_1 + 0x140) & 2) == 0)))) {
    FUN_4052da64(L"Navigating",0);
  }
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x11c) = 1;
    SendMessageW(*(HWND *)(param_1 + 0x70),0x700,0,0);
  }
  return;
}



/* 4052aad8 FUN_4052aad8 */

/* Boundary evidence: original MIPS .pdata 4052aad8..4052ab23. Semantic name remains unreviewed. */

void FUN_4052aad8(int param_1)

{
  *(undefined4 *)(param_1 + 0x11c) = 0;
  FUN_40524a38(param_1,(int *)(param_1 + 0x120));
  *(undefined4 *)(param_1 + 0x11c) = 2;
  PostMessageW(*(HWND *)(param_1 + 0x70),0x700,0,0);
  return;
}



/* 4052ab24 FUN_4052ab24 */

/* Boundary evidence: original MIPS .pdata 4052ab24..4052ad77. Semantic name remains unreviewed. */

int FUN_4052ab24(int param_1,ushort *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  int *local_28 [2];
  
  bVar1 = false;
  if (param_2 == (ushort *)0xfffffffe) {
    iVar2 = FUN_40523994(param_1 + -0x10);
    if (iVar2 == 0) {
      return -0x7ff8ff56;
    }
    pcVar3 = (char *)0xfffffffe;
    goto LAB_4052ad3c;
  }
  iVar2 = FUN_40523994(param_1 + -0x10);
  if (iVar2 == 0) {
    return -0x7ff8ff56;
  }
  pcVar3 = (char *)0x0;
  uVar4 = param_3 & 0xf000;
  if (uVar4 == 0) {
LAB_4052acc8:
    pcVar3 = FUN_4052d908(param_2);
  }
  else if (uVar4 == 0x1000) {
    if (((param_2 == (ushort *)0x0) ||
        ((char)*param_2 == '\0' && *(char *)((int)param_2 + 1) == '\0')) && ((param_3 & 2) != 0)) {
      bVar1 = true;
    }
    else if (*(ushort **)(param_1 + 0x8c) != (ushort *)0x0) {
      pcVar3 = FUN_40537e34(*(ushort **)(param_1 + 0x8c),param_2);
    }
  }
  else {
    if (uVar4 != 0x2000) {
      if (uVar4 == 0x4000) {
        uVar5 = 0xffffffff;
LAB_4052abf0:
        iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x1c))((int *)(param_1 + 4),local_28);
        if (-1 < iVar2) {
          iVar2 = param_1;
          if (param_1 == 0x10) {
            iVar2 = 0;
          }
          iVar2 = (**(code **)(*local_28[0] + 0x18))(local_28[0],iVar2,uVar5);
          (**(code **)(*local_28[0] + 8))();
        }
        (**(code **)(**(int **)(param_1 + 0x50) + 0x48))();
        return iVar2;
      }
      if (uVar4 == 0x8000) {
        uVar5 = 1;
        goto LAB_4052abf0;
      }
      goto LAB_4052acc8;
    }
    pcVar3 = FUN_4052eb80(*(ushort **)(param_1 + 0x8c));
  }
  if ((((param_3 & 1) != 0) && ((param_3 & 0x30) != 0)) &&
     ((iVar2 = FUN_40523994(param_1 + -0x10), iVar2 == 0 || (*(int *)(param_1 + 0x10c) == 1)))) {
    return -0x7ff8ff56;
  }
  if ((pcVar3 == (char *)0x0) && (!bVar1)) {
    return -0x7ff8fff2;
  }
  if ((param_3 & 3) == 2) {
    return 0;
  }
LAB_4052ad3c:
  FUN_4052a9a8(param_1 + -0x10,pcVar3,param_3,0);
  return 0;
}



/* 4052ad78 FUN_4052ad78 */

/* Boundary evidence: original MIPS .pdata 4052ad78..4052ae8b. Semantic name remains unreviewed. */

int FUN_4052ad78(int param_1,wchar_t *param_2,LPCITEMIDLIST param_3)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *pwVar3;
  LPCWSTR local_28 [2];
  wchar_t *local_20;
  int local_1c;
  
  if ((*(uint *)(param_1 + 0x13c) & 0x10) == 0) {
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 0x10;
    FUN_40520168((int *)&local_20,0x825);
    pwVar1 = local_20;
    *local_20 = L'#';
    pwVar3 = (wchar_t *)0x0;
    if (param_3 != (LPCITEMIDLIST)0x0) {
      iVar2 = FUN_405220f8(param_3,0x8000,local_20 + 1,local_1c - 1,(uint *)0x0);
      if (iVar2 == 0) {
        pwVar3 = pwVar1;
      }
    }
    iVar2 = FUN_40533c50(local_28,param_2,pwVar3);
    if (-1 < iVar2) {
      iVar2 = FUN_405221bc(0,local_28[0],(IUnknown *)0x0,&local_20);
      if (-1 < iVar2) {
        FUN_4052a9a8(param_1,local_20,0,1);
      }
      SysFreeString(local_28[0]);
    }
    operator_delete(pwVar1);
  }
  else {
    iVar2 = -0x7fffbffb;
  }
  return iVar2;
}



/* 4052ae8c FUN_4052ae8c */

/* Boundary evidence: original MIPS .pdata 4052ae8c..4052b1f7. Semantic name remains unreviewed. */

int FUN_4052ae8c(int *param_1,LPCITEMIDLIST param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_38 [2];
  int *local_30 [2];
  
  bVar1 = false;
  local_38[0] = 0;
  iVar2 = (**(code **)(*param_1 + 0xfc))(param_1);
  if ((iVar2 == 0) || (BVar3 = IsWindowEnabled((HWND)param_1[0x17]), BVar3 == 0)) {
    iVar2 = -0x7ff8ff56;
LAB_4052b064:
    if (-1 < iVar2) goto LAB_4052b1c0;
  }
  else {
    if (((param_1[0x4b] & 2U) == 0) &&
       (iVar2 = FUN_40526dc4((int)(param_1 + -5),param_2,local_38), iVar2 == -0x7fffbffc))
    goto LAB_4052b064;
    piVar6 = param_1 + -5;
    iVar2 = (**(code **)(*piVar6 + 0x1c))(piVar6,param_2);
    if (iVar2 != 0) goto LAB_4052b064;
    piVar5 = (int *)param_1[0x19];
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x14))(piVar5,param_3 & 0xfe00000,0,0,0);
    }
    iVar2 = FUN_40526390((int)piVar6,param_2,local_38[0]);
    if (iVar2 != 0) {
      bVar1 = true;
      goto LAB_4052b064;
    }
    if ((((((param_1[0x4a] & 0x80U) == 0) && (local_38[0] == 0)) && ((param_1[0x4a] & 0x200U) == 0))
        && (((param_3 & 0x20) == 0 && (param_2 != (LPCITEMIDLIST)0x0)))) &&
       (((ushort *)param_1[0x22] != (ushort *)0x0 &&
        (iVar2 = FUN_40521408((ushort *)param_2,(ushort *)param_1[0x22]), iVar2 != 0)))) {
      param_1[0x4a] = param_1[0x4a] | 0x80;
    }
    param_1[0x4a] = param_1[0x4a] & 0xfffffdff;
    iVar2 = FUN_4052a470((int)piVar6,param_2,param_3);
    param_1[0x4b] = param_1[0x4b] & 0xfffffff9;
    if (-1 < iVar2) {
      IUnknown_AtomicRelease((void **)(param_1 + 0x39));
      goto LAB_4052b064;
    }
  }
  (**(code **)(param_1[6] + 0xc))(param_1 + 6,0,4);
  if ((param_1[0x4a] & 0x80U) != 0) {
    iVar4 = (**(code **)(*param_1 + 0x1c))(param_1,local_30);
    if (-1 < iVar4) {
      (**(code **)(*local_30[0] + 0x34))();
      (**(code **)(*local_30[0] + 8))();
    }
    param_1[0x4a] = param_1[0x4a] & 0xffffff7f;
    IUnknown_AtomicRelease((void **)(param_1 + 0x36));
    IUnknown_AtomicRelease((void **)(param_1 + 0x38));
    IUnknown_AtomicRelease((void **)(param_1 + 0x37));
  }
  if ((int *)param_1[0x13] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x13] + 0x48))();
  }
  if ((param_1[0x22] != 0) || ((param_1[0x4a] & 0x10U) != 0)) goto LAB_4052b1c0;
  FUN_40520168((int *)local_30,0x824);
  if (bVar1) {
    iVar2 = FUN_40516aac();
    if (-1 < iVar2) goto LAB_4052b1a0;
  }
  else {
LAB_4052b1a0:
    (**(code **)(param_1[-5] + 0x30))(param_1 + -5,local_30[0],param_2);
  }
  operator_delete(local_30[0]);
LAB_4052b1c0:
  FUN_40537f64(0);
  return iVar2;
}



/* 4052b1f8 FUN_4052b1f8 */

/* Boundary evidence: original MIPS .pdata 4052b1f8..4052b397. Semantic name remains unreviewed. */

undefined4 FUN_4052b1f8(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int local_28 [2];
  
  bVar1 = false;
  if (param_2 == 0) {
    bVar1 = param_1[0x2d] != param_3;
    param_1[0x2d] = param_3;
  }
  else {
    iVar2 = SHIsSameObject(param_2,param_1[0x1d]);
    if (iVar2 == 0) {
      iVar2 = SHIsSameObject(param_2,param_1[0x22]);
      if (iVar2 == 0) {
        if (param_1[0x22] != 0) {
          return 0;
        }
      }
      else {
        bVar1 = true;
        if (param_1[0x37] == param_3) {
          bVar1 = false;
        }
      }
      param_1[0x37] = param_3;
    }
    else {
      bVar1 = param_1[0x2e] != param_3;
      param_1[0x2e] = param_3;
      if ((param_3 == 4) && ((param_1[0x44] & 0x800U) == 0)) {
        FUN_40527c68((int)(param_1 + -0xb));
      }
    }
  }
  if ((bVar1) && (param_1[0x15] != 0)) {
    IUnknown_CPContainerOnChanged(param_1[0x29],0xfffffdf3);
    (**(code **)(*param_1 + 0x10))(param_1,local_28);
    if (local_28[0] == 4) {
      if ((((param_1[0x45] & 1U) == 0) || (param_1[0x26] == 0)) &&
         (bVar1 = FUN_40528c0c(param_1 + -0xb,(int *)param_1[0x1d]),
         CONCAT31(extraout_var,bVar1) == 0)) {
        FUN_40535834((IUnknown *)param_1[0x15],(undefined4 *)param_1[0x14],
                     (LPCITEMIDLIST)param_1[0x1c]);
      }
      IUnknown_AtomicRelease((void **)(param_1 + 0x34));
    }
  }
  return 0;
}



/* 4052b398 FUN_4052b398 */

/* Boundary evidence: original MIPS .pdata 4052b398..4052b787. Semantic name remains unreviewed. */

HRESULT FUN_4052b398(int param_1,IStream *param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  code *pcVar3;
  HRESULT HVar4;
  int iVar5;
  undefined4 *puVar6;
  LPVOID *ppunk;
  void **ppunk_00;
  int *local_60;
  int local_5c;
  int *local_58;
  uint local_54;
  int iStack_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  IID IStack_40;
  uint local_2c;
  
  local_2c = DAT_40544354;
  ppunk = (LPVOID *)(param_1 + 0xbc);
  HVar4 = -0x7ff8ffa9;
  IUnknown_AtomicRelease(ppunk);
  ppunk_00 = (void **)(param_1 + 0xc0);
  IUnknown_AtomicRelease(ppunk_00);
  IUnknown_AtomicRelease((void **)(param_1 + 0xc4));
  if ((param_2 == (IStream *)0x0) || (HVar4 = FUN_40527198(param_2,&iStack_50,&local_5c), HVar4 < 0)
     ) {
LAB_4052b738:
    pcVar3 = *(code **)(**(int **)(param_1 + 0x30) + 0x48);
  }
  else {
    *(undefined4 *)(param_1 + 0xac) = local_44;
    *(undefined4 *)(param_1 + 0x124) = local_48;
    if (local_4c != 2) goto LAB_4052b6ec;
    puVar6 = *(void **)(param_1 + 200);
    iVar5 = -0x7fffbffb;
    if (puVar6 == (undefined4 *)0x0) {
LAB_4052b530:
      bVar1 = FUN_40528c0c(param_1 + -0x30,*(int **)(param_1 + 0x70));
      if ((CONCAT31(extraout_var,bVar1) == 0) ||
         (bVar1 = FUN_405232e0(param_1 + -0x30,&IStack_40), CONCAT31(extraout_var_00,bVar1) == 0)) {
        iVar2 = FUN_40516d94(&IStack_40,(LPUNKNOWN)0x0,5,(IID *)&DAT_40514044,ppunk);
LAB_4052b5ec:
        if ((-1 < iVar2) &&
           (iVar5 = (**(code **)(*(int *)*ppunk + 0x58))(*ppunk,1,&local_54), -1 < iVar5)) {
          if ((local_54 & 0x20000) == 0) {
            iVar5 = (*(code *)**(undefined4 **)*ppunk)(*ppunk,&DAT_4051649c,&local_60);
            if (-1 < iVar5) {
              iVar5 = (**(code **)(*local_60 + 0x10))(local_60,param_2,param_3);
              (**(code **)(*local_60 + 8))();
              goto LAB_4052b6b4;
            }
          }
          else {
            (*param_2->lpVtbl->AddRef)(param_2);
            if (param_3 != (int *)0x0) {
              (**(code **)(*param_3 + 4))(param_3);
            }
            *ppunk_00 = param_2;
            *(int **)(param_1 + 0xc4) = param_3;
LAB_4052b6b4:
            if (-1 < iVar5) goto LAB_4052b6ec;
          }
          IUnknown_AtomicRelease(ppunk);
          IUnknown_AtomicRelease(ppunk_00);
          IUnknown_AtomicRelease((void **)(param_1 + 0xc4));
        }
      }
      else {
        iVar5 = (**(code **)(**(int **)(param_1 + 0x70) + 0x3c))
                          (*(int **)(param_1 + 0x70),0,&UNK_40514054,&local_58);
        if (-1 < iVar5) {
          *(uint *)(param_1 + 0x10c) = *(uint *)(param_1 + 0x10c) | 0x80;
          HVar4 = (**(code **)(*local_58 + 0x10))(local_58,param_2,param_3);
          (**(code **)(*local_58 + 8))();
          FUN_40537f64(local_5c);
          goto LAB_4052b74c;
        }
      }
LAB_4052b6ec:
      if (local_5c == 0) {
        HVar4 = -0x7ff8fff2;
      }
      else {
        *(uint *)(param_1 + 0x10c) = *(uint *)(param_1 + 0x10c) | 0x80;
        HVar4 = (**(code **)(**(int **)(param_1 + 0x38) + 0x2c))
                          (*(int **)(param_1 + 0x38),local_5c,1);
        FUN_40537f64(local_5c);
      }
      goto LAB_4052b738;
    }
    if (((*(uint *)(param_1 + 0x110) & 1) == 0) ||
       (iVar2 = memcmp(&IStack_40,&DAT_405166dc,0x10), iVar2 != 0)) {
      IUnknown_AtomicRelease((void **)(param_1 + 200));
LAB_4052b51c:
      iVar2 = 0;
      if (iVar5 != 0) goto LAB_4052b530;
      goto LAB_4052b5ec;
    }
    iVar5 = (**(code **)*puVar6)(puVar6,&DAT_4051649c,&local_60);
    if (iVar5 < 0) goto LAB_4052b51c;
    *(uint *)(param_1 + 0x10c) = *(uint *)(param_1 + 0x10c) | 0x80;
    HVar4 = (**(code **)(*local_60 + 0x10))(local_60,param_2,param_3);
    pcVar3 = *(code **)(*local_60 + 8);
  }
  (*pcVar3)();
LAB_4052b74c:
  FUN_40542538(local_2c);
  return HVar4;
}



/* 4052b788 FUN_4052b788 */

/* Boundary evidence: original MIPS .pdata 4052b788..4052b85b. Semantic name remains unreviewed. */

int FUN_4052b788(int param_1)

{
  int iVar1;
  LPCITEMIDLIST pIVar2;
  int iVar3;
  LPCWSTR local_20;
  int local_1c;
  
  iVar3 = param_1 + -0x5c;
  local_20 = (LPCWSTR)0x0;
  local_1c = 0;
  iVar1 = FUN_40529560(iVar3,&local_20);
  if (-1 < iVar1) {
    if (local_20 != (LPCWSTR)0x0) {
      pIVar2 = (LPCITEMIDLIST)FUN_405258ec(iVar3,local_20,&local_1c);
      if (pIVar2 != (LPCITEMIDLIST)0x0) {
        iVar1 = FUN_40529770(iVar3,local_20,pIVar2,(IUnknown *)0x0,0);
        FUN_40537f64((int)pIVar2);
      }
      SysFreeString(local_20);
      if (pIVar2 != (LPCITEMIDLIST)0x0) {
        return iVar1;
      }
    }
    if (-1 < iVar1) {
      iVar1 = -0x7fffbffb;
    }
  }
  return iVar1;
}



/* 4052b85c FUN_4052b85c */

/* Boundary evidence: original MIPS .pdata 4052b85c..4052ba5b. Semantic name remains unreviewed. */

HRESULT FUN_4052b85c(int param_1,int param_2,IUnknown *param_3,OLECHAR *param_4,uint param_5,
                    OLECHAR *param_6,void *param_7,ULONG param_8,OLECHAR *param_9,int param_10,
                    int *param_11)

{
  BSTR bstrString;
  LPCITEMIDLIST pIVar1;
  int iVar2;
  int iVar3;
  HRESULT HVar4;
  IUnknown *local_30 [2];
  
  local_30[0] = (IUnknown *)0x0;
  HVar4 = 0;
  *param_11 = 0;
  if (param_4 == (OLECHAR *)0x0) {
    param_4 = L"";
  }
  bstrString = SysAllocString(param_4);
  pIVar1 = (LPCITEMIDLIST)FUN_405257c0(bstrString);
  if (pIVar1 != (LPCITEMIDLIST)0x0) {
    iVar3 = param_1 + -0x54;
    HVar4 = FUN_405282d4(iVar3,param_3,local_30);
    if (HVar4 == 0) {
      *(LPCITEMIDLIST *)(param_1 + 0x31c) = pIVar1;
      if ((*(int *)(param_1 + 800) != 0) && ((param_6 == (OLECHAR *)0x0 || (*param_6 == L'\0')))) {
        param_6 = (OLECHAR *)(param_1 + 0x32c);
      }
      FUN_40535b0c(local_30[0],*(undefined4 *)(param_1 + 0x1c),local_30[0],pIVar1,0,param_5,param_6,
                   param_7,param_8,param_9,param_11);
      if ((((*param_11 == 0) && (param_2 != 0)) && ((param_5 & 0x40) != 0)) &&
         ((*(int *)(param_1 + 0x60) != 0 && (iVar2 = FUN_4052819c(iVar3,param_2), iVar2 == 0)))) {
        iVar2 = FUN_40523994(iVar3);
        if (iVar2 == 0) {
          *param_11 = 1;
        }
        else {
          FUN_40529eec(iVar3,0);
        }
      }
      FUN_40528024(iVar3,(int *)local_30[0]);
      IUnknown_AtomicRelease(local_30);
      *(undefined4 *)(param_1 + 0x31c) = 0;
      FUN_40537f64((int)pIVar1);
      if ((*param_11 == 0) && (param_10 != 0)) {
        FUN_4052da64(L"Navigating",0);
      }
    }
  }
  SysFreeString(bstrString);
  return HVar4;
}



/* 4052ba5c FUN_4052ba5c */

/* Boundary evidence: original MIPS .pdata 4052ba5c..4052bc4f. Semantic name remains unreviewed. */

HRESULT FUN_4052ba5c(int param_1,IUnknown *param_2,uint param_3)

{
  BSTR bstrString;
  LPCITEMIDLIST pIVar1;
  BOOL BVar2;
  HRESULT HVar3;
  int iVar4;
  int iVar5;
  IUnknown *local_30;
  int local_2c;
  
  if (param_2 == (IUnknown *)0x0) {
    HVar3 = -0x7fffbffd;
  }
  else {
    local_2c = 0;
    HVar3 = -0x7fffbffb;
    bstrString = (BSTR)FUN_40525888(param_2);
    if (bstrString != (BSTR)0x0) {
      iVar5 = param_1 + -0x50;
      pIVar1 = (LPCITEMIDLIST)FUN_405258ec(iVar5,bstrString,&local_2c);
      if (pIVar1 != (LPCITEMIDLIST)0x0) {
        iVar4 = 0;
        local_30 = (IUnknown *)0x0;
        if ((param_3 & 2) == 0) {
          iVar4 = FUN_40529b98(iVar5,bstrString,(ushort *)pIVar1,param_3,local_2c);
          if ((*(uint *)(param_1 + 0xf0) & 1) != 0) {
            IUnknown_AtomicRelease((void **)(param_1 + 0xa8));
            (*param_2->lpVtbl[0x11].AddRef)(param_2);
          }
        }
        else {
          BVar2 = IsWindowVisible(*(HWND *)(param_1 + 0x20));
          if ((((BVar2 != 0) && ((*(uint *)(param_1 + 0xd4) & 0x8000000) == 0)) &&
              ((param_3 & 4) == 0)) && ((param_3 & 8) == 0)) {
            FUN_4052da64(L"ActivatingDocument",0);
          }
          if (*(int **)(param_1 + 0x10) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x10) + 0x48))();
          }
        }
        if ((param_3 & 2) == 0) {
          param_2 = (IUnknown *)0x0;
        }
        HVar3 = FUN_405282d4(iVar5,param_2,&local_30);
        if ((HVar3 == 0) && (iVar4 == 0)) {
          FUN_405355d4(local_30,local_30,pIVar1);
        }
        IUnknown_AtomicRelease(&local_30);
        FUN_40537f64((int)pIVar1);
      }
      SysFreeString(bstrString);
    }
  }
  return HVar3;
}



/* 4052bc50 FUN_4052bc50 */

/* Boundary evidence: original MIPS .pdata 4052bc50..4052be23. Semantic name remains unreviewed. */

undefined4 * FUN_4052bc50(undefined4 *param_1,undefined4 *param_2)

{
  FUN_4052f168(param_1,param_2);
  param_1[4] = &PTR_LAB_4051131c;
  param_1[5] = &PTR_LAB_40513ea4;
  param_1[8] = &PTR_LAB_40513dcc;
  param_1[9] = &PTR_LAB_40513de4;
  param_1[10] = &PTR_LAB_40513888;
  param_1[0xb] = &PTR_LAB_40513898;
  param_1[0xf] = &PTR_LAB_40513e08;
  param_1[0x14] = &PTR_LAB_40513e1c;
  param_1[0x15] = &PTR_LAB_405138ac;
  *param_1 = &PTR_FUN_40513c3c;
  param_1[4] = &PTR_LAB_40513bf4;
  param_1[5] = &PTR_LAB_40513a70;
  param_1[6] = &PTR_LAB_40513a60;
  param_1[7] = &PTR_LAB_40513a4c;
  param_1[8] = &PTR_LAB_40513a34;
  param_1[9] = &PTR_LAB_40513a10;
  param_1[10] = &PTR_LAB_40513a00;
  param_1[0xb] = &PTR_LAB_405139ec;
  param_1[0xc] = &PTR_LAB_405139cc;
  param_1[0xd] = &PTR_LAB_405139b8;
  param_1[0xe] = &PTR_LAB_405139a4;
  param_1[0xf] = &PTR_LAB_40513990;
  param_1[0x12] = &PTR_LAB_40513978;
  param_1[0x13] = &PTR_LAB_40513968;
  param_1[0x14] = &PTR_LAB_4051390c;
  param_1[0x15] = &PTR_LAB_405138fc;
  param_1[0x16] = &PTR_LAB_405138dc;
  param_1[0x17] = &PTR_LAB_405138bc;
  param_1[0x24] = 2;
  FUN_4052f090((int)param_1);
  FUN_4052f090((int)param_1);
  FUN_4052f090((int)param_1);
  FUN_4052f090((int)param_1);
  return param_1;
}



/* 4052be24 FUN_4052be24 */

/* Boundary evidence: original MIPS .pdata 4052be24..4052be83. Semantic name remains unreviewed. */

void FUN_4052be24(int param_1,short *param_2)

{
  LPCWSTR pWVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  pWVar1 = (LPCWSTR)FUN_4053f620(param_2);
  if ((pWVar1 != (LPCWSTR)0x0) &&
     (iVar2 = FUN_405221bc(0,pWVar1,(IUnknown *)0x0,local_10), -1 < iVar2)) {
    FUN_4052a9a8(param_1,local_10[0],0,0);
  }
  return;
}



/* 4052be84 FUN_4052be84 */

/* Boundary evidence: original MIPS .pdata 4052be84..4052bf97. Semantic name remains unreviewed. */

undefined4 FUN_4052be84(int param_1,ushort *param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_2 != (ushort *)0x0) && (param_2 != (ushort *)0xffffffff)) {
    param_2 = FUN_4052d908(param_2);
  }
  uVar1 = 0;
  if (param_3 != 0xffffffff) {
    if ((param_3 & 0x8000000) != 0) {
      uVar1 = 0x8000000;
    }
    if ((param_3 & 0x4000000) != 0) {
      uVar1 = uVar1 | 0x4000000;
    }
  }
  if ((param_3 & 4) == 0) {
    if ((param_3 & 8) != 0) {
      uVar1 = 0x8000;
    }
    if (uVar1 == 0) {
      FUN_4052a9a8(param_1 + -0x14,param_2,0,0);
      return 0;
    }
  }
  else {
    uVar1 = 0x4000;
  }
  piVar2 = *(int **)(param_1 + 0x54);
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 0x2c))(piVar2,param_2,uVar1);
  }
  FUN_40537f64((int)param_2);
  return uVar3;
}



/* 4052bf98 FUN_4052bf98 */

/* Boundary evidence: original MIPS .pdata 4052bf98..4052cd43. Semantic name remains unreviewed. */

int FUN_4052bf98(int param_1,void *param_2,uint param_3,undefined4 param_4,short *param_5,
                VARIANTARG *param_6)

{
  LPCWSTR pWVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 uVar4;
  LPCITEMIDLIST pIVar5;
  int *piVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  wchar_t *pszSrc;
  HWND local_1188 [2];
  LPCWSTR local_1180 [2];
  wchar_t awStack_1178 [128];
  wchar_t awStack_1078 [2084];
  uint local_30;
  
  local_30 = DAT_40544354;
  iVar9 = -0x7ffbff00;
  if (param_2 == (void *)0x0) {
    if (0x1d < param_3) {
      if (param_3 == 0x20) goto LAB_4052cd0c;
      if (0x21 < param_3) {
        if (param_3 < 0x24) {
          iVar9 = (**(code **)(*(int *)(param_1 + -8) + 0x78))
                            ((int *)(param_1 + -8),*(undefined4 *)(param_1 + 0x84),param_3 == 0x23,
                             param_5,param_6);
          goto LAB_4052cd0c;
        }
        if (param_3 == 0x2d) {
          (**(code **)(*(int *)(param_1 + -0xc) + 0xc))((int *)(param_1 + -0xc),local_1188);
          PostMessageW(local_1188[0],0x10,0,0);
          goto LAB_4052ccfc;
        }
      }
LAB_4052c260:
      piVar6 = *(int **)(param_1 + 0x7c);
      if (piVar6 != (int *)0x0) {
        iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,0,param_3,param_4,param_5,param_6);
      }
      goto LAB_4052cd0c;
    }
    if (param_3 == 0x1d) {
      if (param_5 != (short *)0x0) {
        FUN_40525568(param_1 + -0x1c,param_5);
        iVar9 = FUN_405265d4(param_1 + -0x1c);
        goto LAB_4052cd0c;
      }
LAB_4052c1c0:
      iVar9 = -0x7ff8ffa9;
      goto LAB_4052cd0c;
    }
    if (param_3 == 0x15) {
      FUN_40524040(param_1 + -0x1c);
    }
    else if (param_3 == 0x16) {
      piVar6 = *(int **)(param_1 + 0x7c);
      if (piVar6 != (int *)0x0) {
        iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,0,0x16,param_4,param_5,param_6);
        goto LAB_4052cd0c;
      }
      if (*(int **)(param_1 + 0x84) == (int *)0x0) goto LAB_4052cd0c;
      (**(code **)(**(int **)(param_1 + 0x84) + 0x20))();
    }
    else {
      if (param_3 != 0x17) goto LAB_4052c260;
      iVar9 = (**(code **)(*(int *)(param_1 + -8) + 0xfc))();
      if (iVar9 == 1) {
        if (*(ushort **)(param_1 + 0x94) == (ushort *)0x0) {
          pHVar2 = (HWND)0x0;
        }
        else {
          pHVar2 = FUN_4052d908(*(ushort **)(param_1 + 0x94));
        }
        FUN_40529eec(param_1 + -0x1c,0);
        (**(code **)(**(int **)(param_1 + 0x44) + 0x10c))
                  (*(int **)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x7c),1,0,0x17,2,0,0);
        if ((*(int *)(param_1 + 0x80) == 0) && (iVar9 = FUN_40516aac(), -1 < iVar9)) {
          iVar9 = *(int *)(param_1 + -0x1c);
LAB_4052c104:
          (**(code **)(iVar9 + 0x30))(param_1 + -0x1c,awStack_1078,pHVar2);
        }
        goto joined_r0x4052c3d8;
      }
    }
    goto LAB_4052ccfc;
  }
  iVar3 = memcmp(&DAT_4051677c,param_2,0x10);
  if (iVar3 == 0) {
    piVar6 = *(int **)(param_1 + 0x7c);
    if (piVar6 != (int *)0x0) {
      iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,&DAT_4051677c,param_3,param_4,param_5,param_6);
    }
    goto LAB_4052cd0c;
  }
  iVar3 = memcmp(&DAT_405163dc,param_2,0x10);
  if (iVar3 == 0) {
    if (param_3 < 0x1a) {
      if (param_3 == 0x19) {
        iVar3 = *(int *)(param_5 + 4);
        iVar9 = iVar3;
        if (6 < iVar3) {
          if ((iVar3 == 7) && (*(int *)(param_1 + 0x6c) != 0)) {
            iVar9 = 1;
          }
          else {
            iVar9 = iVar3 + -7;
            if (*(int *)(param_1 + 0x6c) <= iVar3 + -7) {
              iVar9 = *(int *)(param_1 + 0x6c);
            }
          }
        }
        (**(code **)(*(int *)(param_1 + -8) + 0xdc))((int *)(param_1 + -8),iVar9);
      }
      else if (param_3 == 2) {
        if (((param_5 == (short *)0x0) || (*param_5 != 3)) || ((*(uint *)(param_5 + 4) & 2) == 0)) {
          if (*(ushort **)(param_1 + 0x94) == (ushort *)0x0) {
            pHVar2 = (HWND)0x0;
          }
          else {
            pHVar2 = FUN_4052d908(*(ushort **)(param_1 + 0x94));
          }
          (**(code **)(*(int *)(param_1 + -8) + 0xec))();
          if (*(int *)(param_1 + 0x80) == 0) {
            if ((*(uint *)(param_1 + 0x120) & 0x100000) == 0) {
              iVar9 = FUN_4052dc64();
              if (iVar9 == 0) {
                iVar9 = FUN_40516aac();
              }
              else {
                iVar9 = FUN_40516aac();
              }
              if (-1 < iVar9) {
                iVar9 = *(int *)(param_1 + -0x1c);
                goto LAB_4052c104;
              }
            }
            else {
              *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) & 0xffefffff;
            }
          }
          goto joined_r0x4052c3d8;
        }
        FUN_40529eec(param_1 + -0x1c,0);
      }
      else if (param_3 == 8) {
        local_1188[0] = (HWND)0x0;
        if ((param_5 != (short *)0x0) && (*param_5 == 8)) {
          FUN_405221bc(0,*(LPCWSTR *)(param_5 + 4),(IUnknown *)0x0,local_1188);
        }
        if (param_6 == (VARIANTARG *)0x0) {
          pHVar2 = local_1188[0];
          if (*(STRSAFE_LPCWSTR *)(param_1 + 0x90) != (STRSAFE_LPCWSTR)0x0) {
            StringCchCopyW(awStack_1178,0x80,*(STRSAFE_LPCWSTR *)(param_1 + 0x90));
            pHVar2 = local_1188[0];
          }
        }
        else {
          FUN_40525758((short *)param_6,awStack_1178,0x80);
          pHVar2 = local_1188[0];
        }
joined_r0x4052c3d8:
        if (pHVar2 != (HWND)0x0) {
          FUN_40537f64((int)pHVar2);
        }
      }
      else {
        if (param_3 != 0xe) {
          if (param_3 == 0x18) {
            iVar9 = FUN_4052566c(param_1 + -0x1c,(undefined2 *)param_6);
          }
          goto LAB_4052cd0c;
        }
        FUN_4052be24(param_1 + -0x1c,param_5);
      }
    }
    else {
      if (param_3 == 0x26) {
        iVar9 = 0;
        if ((param_5 != (short *)0x0) && (*param_5 == 3)) {
          iVar9 = 1;
          *(uint *)(param_1 + 0x120) =
               ((uint)((*(uint *)(param_5 + 4) & 1) != 0) << 8 ^ *(uint *)(param_1 + 0x120)) & 0x100
               ^ *(uint *)(param_1 + 0x120);
          if ((*(uint *)(param_5 + 4) & 2) == 0) {
            iVar9 = 0;
          }
        }
        FUN_40520168((int *)local_1180,0x824);
        pWVar1 = local_1180[0];
        if (local_1180[0] != (LPCWSTR)0x0) {
          *local_1180[0] = L'\0';
          (**(code **)(*(int *)(param_1 + -8) + 0x28))
                    ((int *)(param_1 + -8),*(undefined4 *)(param_1 + 0x80),local_1180[0],0x8000);
          iVar3 = FUN_4052e864(pWVar1);
          if (iVar3 == 0) {
            FUN_405233d8(param_1 + -0x1c,iVar9);
          }
        }
        operator_delete(pWVar1);
      }
      else if (param_3 != 0x28) {
        if (param_3 == 0x3d) {
          piVar6 = *(int **)(param_1 + 0x7c);
          iVar9 = 0;
          if (piVar6 != (int *)0x0) {
            iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,param_2,0x3d,0,0,0);
          }
          goto LAB_4052cd0c;
        }
        if ((param_3 != 0x40) || (param_6 == (VARIANTARG *)0x0)) goto LAB_4052cd0c;
        (param_6->n1).n2.vt = 0xb;
        uVar4 = FUN_40523994(param_1 + -0x1c);
        *(short *)((int)&param_6->n1 + 8) = (short)uVar4;
        goto LAB_4052ccfc;
      }
      if ((param_5 != (short *)0x0) && (*param_5 == 8)) {
        pszSrc = *(wchar_t **)(param_5 + 4);
        if (pszSrc == (wchar_t *)0x0) {
          pszSrc = L"";
        }
        local_1180[0] = (LPCWSTR)0x824;
        iVar9 = FUN_4052d8ec(pszSrc,awStack_1078,(LPDWORD)local_1180,(undefined4 *)0x0);
        if (iVar9 == 0) {
          StringCchCopyW(awStack_1078,0x824,pszSrc);
        }
        piVar6 = (int *)(param_1 + -8);
        (**(code **)(*piVar6 + 0x2c))(piVar6,0,awStack_1078,local_1188);
        if (local_1188[0] != (HWND)0x0) {
          (**(code **)(*piVar6 + 0x40))(piVar6,*(undefined4 *)(param_1 + 0x84),local_1188[0],0);
          FUN_40537f64((int)local_1188[0]);
        }
      }
      *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | 0x200;
      (**(code **)(**(int **)(param_1 + 0x44) + 0x48))();
    }
    goto LAB_4052ccfc;
  }
  iVar3 = memcmp(&DAT_405163ec,param_2,0x10);
  if (iVar3 != 0) {
    iVar3 = memcmp(&DAT_4051676c,param_2,0x10);
    if (iVar3 == 0) {
      piVar6 = *(int **)(param_1 + 0x7c);
      if (piVar6 != (int *)0x0) {
        iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,&DAT_4051676c,param_3,param_4,param_5,param_6);
      }
      goto LAB_4052cd0c;
    }
    iVar3 = memcmp(&DAT_405123a4,param_2,0x10);
    if (iVar3 == 0) {
      if (param_3 != 0) {
        if (param_3 == 6) {
          if ((param_5 == (short *)0x0) || (*param_5 != 3)) {
            FUN_40542538(local_30);
            return -0x7ff8ffa9;
          }
          *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_5 + 4);
          goto LAB_4052cb28;
        }
LAB_4052cd04:
        iVar9 = -0x7ffbfefc;
        goto LAB_4052cd0c;
      }
      if (((param_5 == (short *)0x0) || (*param_5 != 0xd)) || (*(int *)(param_5 + 4) == 0)) {
        *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & 0xfffffffe;
      }
      else {
        *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | 1;
      }
    }
    else {
      iVar3 = memcmp(&DAT_405163cc,param_2,0x10);
      if (iVar3 != 0) goto LAB_4052cd04;
      if (param_3 != 2) {
        if ((param_3 != 3) || (iVar3 = *(int *)(param_1 + 0x354), iVar3 == 0)) goto LAB_4052cd0c;
        uVar4 = 2;
LAB_4052c830:
        iVar9 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x2c))
                          (*(int **)(param_1 + 0x4c),iVar3,uVar4);
        goto LAB_4052cd0c;
      }
      if ((param_6 == (VARIANTARG *)0x0) || (*(ushort **)(param_1 + 0x354) == (ushort *)0x0))
      goto LAB_4052cd0c;
      local_1188[0] = (HWND)0x20000000;
      iVar9 = FUN_4052160c(*(ushort **)(param_1 + 0x354),(uint *)local_1188);
      (param_6->n1).n2.vt = 0xb;
      if (-1 < iVar9) {
        uVar8 = (uint)local_1188[0] & 0x20000000;
        goto LAB_4052ccec;
      }
LAB_4052ccf4:
      uVar7 = 0;
LAB_4052ccf8:
      *(undefined2 *)((int)&param_6->n1 + 8) = uVar7;
    }
    goto LAB_4052ccfc;
  }
  if (0x1d < param_3) {
    if (param_3 != 0x32) {
      if (param_3 == 0x3c) {
        iVar9 = (**(code **)(**(int **)(param_1 + 0x7c) + 0x10))
                          (*(int **)(param_1 + 0x7c),param_2,0x3c,param_4,param_5,param_6);
        goto LAB_4052cd0c;
      }
      if (param_3 == 0x3e) {
        uVar8 = *(uint *)(param_1 + 0x124) | 2;
      }
      else {
        if (param_3 == 0x43) {
          if (((param_5 == (short *)0x0) || (*param_5 != 8)) ||
             ((*(LPCWSTR *)(param_5 + 4) == (LPCWSTR)0x0 ||
              (((param_6 == (VARIANTARG *)0x0 || ((param_6->n1).n2.vt != 0xb)) ||
               (pIVar5 = (LPCITEMIDLIST)FUN_405257c0(*(LPCWSTR *)(param_5 + 4)),
               pIVar5 == (LPCITEMIDLIST)0x0)))))) {
            FUN_40542538(local_30);
            return -0x7fffbffb;
          }
          iVar9 = FUN_40526390(param_1 + -0x1c,pIVar5,0);
          *(ushort *)((int)&param_6->n1 + 8) = (ushort)(iVar9 == 0);
          FUN_40537f64((int)pIVar5);
          goto LAB_4052cb28;
        }
        if (param_3 == 0x44) {
          if (param_6 == (VARIANTARG *)0x0) goto LAB_4052cd0c;
          (param_6->n1).n2.vt = 0xb;
          uVar8 = *(uint *)(param_1 + 0x120) & 0x80;
LAB_4052ccec:
          uVar7 = 0xffff;
          if (uVar8 == 0) goto LAB_4052ccf4;
          goto LAB_4052ccf8;
        }
        if (param_3 == 0x46) {
          if (param_6 == (VARIANTARG *)0x0) goto LAB_4052cd0c;
          local_1188[0] = (HWND)0x0;
          (param_6->n1).n2.vt = 0xb;
          FUN_40536a48(*(IUnknown **)(param_1 + 100),(int *)local_1188);
          uVar7 = 0xffff;
          if (local_1188[0] == (HWND)0x0) {
            uVar7 = 0;
          }
          *(undefined2 *)((int)&param_6->n1 + 8) = uVar7;
          goto LAB_4052ccfc;
        }
        if (param_3 != 0x49) goto LAB_4052cd0c;
        uVar8 = *(uint *)(param_1 + 0x124) | 4;
      }
      *(uint *)(param_1 + 0x124) = uVar8;
LAB_4052cb28:
      FUN_40542538(local_30);
      return 0;
    }
    goto LAB_4052c8dc;
  }
  if (param_3 == 0x1d) {
    if ((param_5 == (short *)0x0) || (*param_5 != 0xb)) goto LAB_4052c1c0;
  }
  else {
    if (0xf < param_3) {
      if (param_3 == 0x11) {
LAB_4052c8dc:
        piVar6 = *(int **)(param_1 + 0x7c);
        if (piVar6 != (int *)0x0) {
          iVar9 = (**(code **)(*piVar6 + 0x10))(piVar6,param_2,param_3,param_4,param_5,param_6);
          goto LAB_4052cd0c;
        }
      }
      else {
        if (param_3 != 0x13) {
          if (param_3 != 0x17) goto LAB_4052cd0c;
          goto LAB_4052c8dc;
        }
        if ((*(int *)(param_1 + 0x98) != 0) &&
           ((((param_5 != (short *)0x0 && (*param_5 == 0xb)) && (param_5[4] != 0)) ||
            (*(int *)(param_1 + 0x84) == 0)))) {
          FUN_4052eac4(param_6);
          piVar6 = (int *)((int)&param_6->n1 + 8);
          (**(code **)**(undefined4 **)(param_1 + 0x98))
                    (*(undefined4 **)(param_1 + 0x98),&DAT_405162fc,piVar6);
          if (*piVar6 != 0) {
            (param_6->n1).n2.vt = 0xd;
          }
        }
        if (*(int *)((int)&param_6->n1 + 8) != 0) goto LAB_4052ccfc;
      }
      iVar9 = -0x7fffbffb;
      goto LAB_4052cd0c;
    }
    if (param_3 != 0xf) {
      if (param_3 == 0) goto LAB_4052cd0c;
      if (2 < param_3) {
        if (param_3 == 5) {
          uVar4 = 0x4000;
        }
        else {
          if (param_3 != 6) {
            if (param_3 != 10) goto LAB_4052cd0c;
            goto LAB_4052c858;
          }
          uVar4 = 0x8000;
        }
        iVar3 = 0;
        goto LAB_4052c830;
      }
      goto LAB_4052c8dc;
    }
    if (*(int *)(param_1 + 0x98) != 0) {
LAB_4052c858:
      if (((param_5 == (short *)0x0) || (*param_5 != 0xb)) || (param_5[4] != -1)) {
        FUN_4052aad8(param_1 + -0x1c);
      }
      else if (*(int *)(param_1 + 0x98) != 0) {
        (**(code **)(**(int **)(param_1 + 0x44) + 0xb0))();
      }
    }
  }
LAB_4052ccfc:
  iVar9 = 0;
LAB_4052cd0c:
  FUN_40542538(local_30);
  return iVar9;
}



/* 4052cd44 FUN_4052cd44 */

/* Boundary evidence: original MIPS .pdata 4052cd44..4052cdbb. Semantic name remains unreviewed. */

undefined4 FUN_4052cd44(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x13cc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_4052bc50(puVar1,param_1);
  }
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = 0;
    uVar2 = 0x8007000e;
  }
  else {
    *param_2 = puVar1 + 1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 4052cdbc FUN_4052cdbc */

/* Boundary evidence: original MIPS .pdata 4052cdbc..4052cec3. Semantic name remains unreviewed. */

int FUN_4052cdbc(int *param_1,undefined4 param_2,char *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *local_res0 [4];
  
  local_res0[0] = param_1;
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_4053adec(local_res0);
    piVar2 = local_res0[0];
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    piVar2 = (int *)0x0;
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0' && param_3[1] == '\0')) {
    iVar1 = (**(code **)*local_res0[0])(local_res0[0],param_2,param_4);
  }
  else {
    iVar1 = (**(code **)(*local_res0[0] + 0x14))(local_res0[0],param_3,0,param_2,param_4);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  if ((-1 < iVar1) && (*param_4 == 0)) {
    iVar1 = -0x7fffbffb;
  }
  return iVar1;
}



/* 4052cec4 FUN_4052cec4 */

/* Boundary evidence: original MIPS .pdata 4052cec4..4052cf47. Semantic name remains unreviewed. */

undefined4 FUN_4052cec4(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18 [2];
  
  uVar2 = 0x80004002;
  *param_2 = 0;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_4051678c,local_18), -1 < iVar1)) {
    uVar2 = (**(code **)(*local_18[0] + 0x14))(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return uVar2;
}



/* 4052cf48 FUN_4052cf48 */

/* Boundary evidence: original MIPS .pdata 4052cf48..4052cfa7. Semantic name remains unreviewed. */

void * FUN_4052cf48(ushort *param_1,undefined4 param_2)

{
  void *_Dst;
  size_t _Size;
  
  _Dst = (void *)FUN_4053f298(param_2);
  if (_Dst != (void *)0x0) {
    _Size = FUN_40537d04(param_1);
    memmove(_Dst,param_1,_Size);
  }
  FUN_4053f2d4(param_1);
  return _Dst;
}



/* 4052cfa8 FUN_4052cfa8 */

uint FUN_4052cfa8(ushort *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1 + (int)param_1;
  if ((param_2 <= uVar1) || (*(short *)(uVar1 + 6) != -0x4111)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4052cff8 FUN_4052cff8 */

ushort * FUN_4052cff8(ushort *param_1)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)*param_1;
  uVar3 = (uint)*(ushort *)((int)param_1 + (uVar2 - 2));
  if ((((uVar3 == 0) || (uVar2 <= uVar3 + 0xc)) ||
      (puVar1 = (ushort *)(uVar3 + (int)param_1), puVar1[3] != 0xbeef)) || (uVar2 < *puVar1 + uVar3)
     ) {
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}



/* 4052d09c FUN_4052d09c */

/* Boundary evidence: original MIPS .pdata 4052d09c..4052d25b. Semantic name remains unreviewed. */

ushort * FUN_4052d09c(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  
  if ((param_1 != (ushort *)0x0) && ((char)*param_1 != '\0' || *(char *)((int)param_1 + 1) != '\0'))
  {
    iVar3 = FUN_40537d04(param_1);
    iVar6 = (uint)*param_2 + iVar3;
    param_1 = FUN_4052cf48(param_1,iVar6 + 2);
    if (param_1 != (ushort *)0x0) {
      puVar4 = (ushort *)FUN_40537d94((undefined1 *)param_1);
      puVar5 = FUN_4052cff8(puVar4);
      if (puVar5 == (ushort *)0x0) {
        uVar1 = *puVar4;
      }
      else {
        uVar1 = *(ushort *)((int)puVar4 + (*puVar4 - 2));
      }
      puVar5 = (ushort *)((int)param_1 + iVar3 + -2);
      memmove(puVar5,param_2,(uint)*param_2);
      uVar7 = *puVar5 + 2 & 0xffff;
      *(char *)((int)param_1 + iVar3 + -1) = (char)(uVar7 >> 8);
      *(char *)puVar5 = (char)uVar7;
      uVar7 = *puVar4 + uVar7 & 0xffff;
      *(char *)((int)puVar4 + 1) = (char)(uVar7 >> 8);
      *(char *)puVar4 = (char)uVar7;
      uVar2 = *puVar5;
      *(char *)((int)puVar5 + (uVar2 - 2)) = (char)uVar1;
      *(char *)((int)puVar5 + (uVar2 - 1)) = (char)(uVar1 >> 8);
      *(undefined1 *)((int)param_1 + iVar6) = 0;
      *(undefined1 *)((int)param_1 + iVar6 + 1) = 0;
    }
  }
  return param_1;
}



/* 4052d25c FUN_4052d25c */

/* Boundary evidence: original MIPS .pdata 4052d25c..4052d307. Semantic name remains unreviewed. */

ushort * FUN_4052d25c(char *param_1,int param_2)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  if ((param_1 == (char *)0x0) || (*param_1 == '\0' && param_1[1] == '\0')) {
    puVar3 = (ushort *)0x0;
  }
  else {
    puVar2 = (ushort *)FUN_40537d94(param_1);
    puVar3 = FUN_4052cff8(puVar2);
    uVar1 = *puVar2;
    for (; (puVar3 != (ushort *)0x0 && (*(int *)(puVar3 + 2) != param_2));
        puVar3 = (ushort *)FUN_4052cfa8(puVar3,(uint)uVar1 + (int)puVar2)) {
    }
  }
  return puVar3;
}



/* 4052d308 FUN_4052d308 */

/* Boundary evidence: original MIPS .pdata 4052d308..4052d3db. Semantic name remains unreviewed. */

ushort * FUN_4052d308(ushort *param_1,undefined4 param_2,wchar_t *param_3)

{
  size_t sVar1;
  ushort *hMem;
  ushort *puVar2;
  uint uBytes;
  
  sVar1 = wcslen(param_3);
  uBytes = (sVar1 + 6) * 2 & 0xffff;
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem == (ushort *)0x0) {
    puVar2 = (ushort *)0x0;
  }
  else {
    *(char *)((int)hMem + 1) = (char)(uBytes >> 8);
    *(undefined1 *)(hMem + 4) = 2;
    *(char *)hMem = (char)uBytes;
    *(undefined4 *)(hMem + 2) = param_2;
    *(undefined1 *)((int)hMem + 9) = 0;
    StrCpyW((LPWSTR)(hMem + 5),param_3);
    puVar2 = FUN_4052d09c(param_1,hMem);
    LocalFree(hMem);
  }
  return puVar2;
}



/* 4052d3dc FUN_4052d3dc */

/* Boundary evidence: original MIPS .pdata 4052d3dc..4052d467. Semantic name remains unreviewed. */

undefined4 FUN_4052d3dc(char *param_1,int param_2,wchar_t *param_3,size_t param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_4052d25c(param_1,param_2);
  if (puVar1 == (ushort *)0x0) {
    uVar2 = 0;
  }
  else {
    if (puVar1[4] == 2) {
      wcsncpy(param_3,(wchar_t *)(puVar1 + 5),param_4);
    }
    else {
      SHAnsiToUnicode((LPCSTR)(puVar1 + 5),param_3,param_4);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 4052d468 FUN_4052d468 */

ushort * FUN_4052d468(ushort *param_1)

{
  if ((((param_1 == (ushort *)0x0) || (*param_1 == 0)) || (*param_1 < 0x15)) ||
     ((char)param_1[1] != '\x1e')) {
    param_1 = (ushort *)0x0;
  }
  return param_1;
}



/* 4052d4b8 FUN_4052d4b8 */

/* Boundary evidence: original MIPS .pdata 4052d4b8..4052d4e7. Semantic name remains unreviewed. */

bool FUN_4052d4b8(ushort *param_1)

{
  ushort *puVar1;
  
  puVar1 = FUN_4052d468(param_1);
  return puVar1 != (ushort *)0x0;
}



/* 4052d4e8 FUN_4052d4e8 */

/* Boundary evidence: original MIPS .pdata 4052d4e8..4052d507. Semantic name remains unreviewed. */

void FUN_4052d4e8(SIZE_T param_1)

{
  LocalAlloc(0x40,param_1);
  return;
}



/* 4052d508 FUN_4052d508 */

int FUN_4052d508(int param_1)

{
  if ((param_1 == 0x4b0) || (param_1 == 0x4b1)) {
    param_1 = 0xfde9;
  }
  return param_1;
}



/* 4052d52c FUN_4052d52c */

/* Boundary evidence: original MIPS .pdata 4052d52c..4052d54f. Semantic name remains unreviewed. */

void FUN_4052d52c(int *param_1)

{
  (**(code **)(*param_1 + 0x3c))();
  return;
}



/* 4052d550 FUN_4052d550 */

/* Boundary evidence: original MIPS .pdata 4052d550..4052d60f. Semantic name remains unreviewed. */

undefined4 FUN_4052d550(LPCWSTR param_1)

{
  uint uVar1;
  int iVar2;
  int local_10;
  undefined1 auStack_c [4];
  
  uVar1 = FUN_4053ad2c(param_1);
  if (uVar1 != 0) {
    if (uVar1 < 4) {
      return 1;
    }
    if (6 < uVar1) {
      if (uVar1 < 9) {
        return 1;
      }
      if (uVar1 == 9) {
        return 0;
      }
      if (uVar1 == 0xb) {
        return 1;
      }
      if (uVar1 == 0x12) {
        return 0;
      }
    }
  }
  iVar2 = FUN_4053b234(param_1,8,0,&local_10,4,auStack_c,0);
  if ((-1 < iVar2) && (local_10 != 0)) {
    return 1;
  }
  return 0;
}



/* 4052d610 FUN_4052d610 */

/* Boundary evidence: original MIPS .pdata 4052d610..4052d663. Semantic name remains unreviewed. */

undefined4 FUN_4052d610(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_10 [2];
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2,local_10), -1 < iVar1)) {
    uVar2 = 1;
    (**(code **)(*local_10[0] + 8))();
  }
  return uVar2;
}



/* 4052d664 FUN_4052d664 */

/* Boundary evidence: original MIPS .pdata 4052d664..4052d6af. Semantic name remains unreviewed. */

undefined4 FUN_4052d664(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined1 auStack_c [4];
  
  iVar1 = FUN_4053b234(param_1,param_2,0,&local_10,4,auStack_c,0);
  if ((iVar1 < 0) || (uVar2 = 1, local_10 == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4052d6b0 FUN_4052d6b0 */

/* Boundary evidence: original MIPS .pdata 4052d6b0..4052d6cb. Semantic name remains unreviewed. */

void FUN_4052d6b0(undefined4 param_1)

{
  FUN_4052d664(param_1,0xb);
  return;
}



/* 4052d6cc FUN_4052d6cc */

/* Boundary evidence: original MIPS .pdata 4052d6cc..4052d6ff. Semantic name remains unreviewed. */

bool FUN_4052d6cc(LPCWSTR param_1)

{
  int iVar1;
  
  iVar1 = FUN_4053ad2c(param_1);
  return iVar1 == 9;
}



/* 4052d700 FUN_4052d700 */

/* Boundary evidence: original MIPS .pdata 4052d700..4052d75f. Semantic name remains unreviewed. */

undefined4 FUN_4052d700(LPCWSTR param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_1 == L'\\') ||
     (((*param_1 != L'\0' && (param_1[1] == L':')) || (iVar1 = FUN_4053ad2c(param_1), iVar1 == 9))))
  {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4052d760 FUN_4052d760 */

void FUN_4052d760(void)

{
  if (DAT_40544708 == -1) {
    DAT_40544708 = 0;
  }
  DAT_40544708 = DAT_40544708 + 1;
  return;
}



/* 4052d788 FUN_4052d788 */

/* Boundary evidence: original MIPS .pdata 4052d788..4052d807. Semantic name remains unreviewed. */

undefined4 FUN_4052d788(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18 [2];
  
  uVar2 = 0;
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,&DAT_40512c24,&DAT_4051652c,local_18);
  if (-1 < iVar1) {
    uVar2 = SHIsSameObject(local_18[0],param_2);
    (**(code **)(*local_18[0] + 8))();
  }
  return uVar2;
}



/* 4052d808 FUN_4052d808 */

/* Boundary evidence: original MIPS .pdata 4052d808..4052d86f. Semantic name remains unreviewed. */

BSTR FUN_4052d808(UINT param_1)

{
  int iVar1;
  BSTR pOVar2;
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40544354;
  iVar1 = FUN_40516a3c(param_1,aWStack_218,0x104);
  if (iVar1 == 0) {
    FUN_40542538(local_10);
    pOVar2 = (BSTR)0x0;
  }
  else {
    pOVar2 = SysAllocString(aWStack_218);
    FUN_40542538(local_10);
  }
  return pOVar2;
}



/* 4052d870 FUN_4052d870 */

/* Boundary evidence: original MIPS .pdata 4052d870..4052d8eb. Semantic name remains unreviewed. */

bool FUN_4052d870(wchar_t *param_1,STRSAFE_LPWSTR param_2,LPDWORD param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  
  FUN_4053a818(param_1,3,*param_3,param_2,param_4,(uint *)0x0);
  HVar1 = UrlCanonicalizeW(param_2,param_2,param_3,0x4000000);
  return -1 < HVar1;
}



/* 4052d8ec FUN_4052d8ec */

/* Boundary evidence: original MIPS .pdata 4052d8ec..4052d907. Semantic name remains unreviewed. */

void FUN_4052d8ec(wchar_t *param_1,STRSAFE_LPWSTR param_2,LPDWORD param_3,undefined4 *param_4)

{
  FUN_4052d870(param_1,param_2,param_3,param_4);
  return;
}



/* 4052d908 FUN_4052d908 */

/* Boundary evidence: original MIPS .pdata 4052d908..4052d97b. Semantic name remains unreviewed. */

void * FUN_4052d908(ushort *param_1)

{
  size_t _Size;
  void *_Dst;
  
  if (param_1 == (ushort *)0x0) {
    _Dst = (void *)0x0;
  }
  else {
    _Size = FUN_40537d04(param_1);
    _Dst = (void *)FUN_4053f298(_Size);
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_1,_Size);
    }
  }
  return _Dst;
}



/* 4052d97c FUN_4052d97c */

/* Boundary evidence: original MIPS .pdata 4052d97c..4052d9df. Semantic name remains unreviewed. */

undefined4 FUN_4052d97c(int *param_1,ushort *param_2)

{
  void *pvVar1;
  
  if (*param_1 != 0) {
    FUN_40537f64(*param_1);
    *param_1 = 0;
  }
  if (param_2 != (ushort *)0x0) {
    pvVar1 = FUN_4052d908(param_2);
    *param_1 = (int)pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
  }
  return 1;
}



/* 4052d9e0 FUN_4052d9e0 */

/* Boundary evidence: original MIPS .pdata 4052d9e0..4052da63. Semantic name remains unreviewed. */

void FUN_4052d9e0(void)

{
  HMODULE pHVar1;
  
  if ((DAT_40544710 == 0) && (DAT_4054470c == 0)) {
    pHVar1 = GetModuleHandleW(L"coredll.dll");
    DAT_40544710 = GetProcAddressW(pHVar1,L"PlaySoundW");
    DAT_4054470c = (uint)(DAT_40544710 == 0);
  }
  return;
}



/* 4052da64 FUN_4052da64 */

/* Boundary evidence: original MIPS .pdata 4052da64..4052db6b. Semantic name remains unreviewed. */

void FUN_4052da64(undefined4 param_1,int param_2)

{
  code *pcVar1;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  DWORD local_428 [2];
  short local_420 [260];
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_40544354;
  pcVar1 = (code *)FUN_4052d9e0();
  if (pcVar1 != (code *)0x0) {
    if (param_2 == 0) {
      pwVar3 = L"Explorer";
    }
    else {
      pwVar3 = L".Default";
    }
    wnsprintfW(aWStack_218,0x100,L"AppEvents\\Schemes\\Apps\\%s\\%s\\.current",pwVar3,param_1);
    local_428[0] = 0x208;
    local_420[0] = 0;
    LVar2 = SHGetValueW((HKEY)0x80000001,aWStack_218,(LPCWSTR)0x0,(DWORD *)0x0,local_420,local_428);
    if (((LVar2 == 0) && (local_428[0] != 0)) && (local_420[0] != 0)) {
      (*pcVar1)(local_420,0,0x20013);
    }
  }
  FUN_40542538(local_18);
  return;
}



/* 4052db6c FUN_4052db6c */

/* Boundary evidence: original MIPS .pdata 4052db6c..4052dbbb. Semantic name remains unreviewed. */

void * FUN_4052db6c(size_t param_1)

{
  void *_Dst;
  
  _Dst = (void *)FUN_4053f298(param_1);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



/* 4052dbbc FUN_4052dbbc */

/* Boundary evidence: original MIPS .pdata 4052dbbc..4052dc63. Semantic name remains unreviewed. */

bool FUN_4052dbbc(void)

{
  HANDLE hObject;
  DWORD DVar1;
  bool bVar2;
  
  if (DAT_40544700 == 0) {
    hObject = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"WininetStartupMutex");
    DVar1 = GetLastError();
    bVar2 = DVar1 == 0xb7;
    if (bVar2) {
      DAT_40544700 = 1;
    }
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}



/* 4052dc64 FUN_4052dc64 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4052dc64..4052dcd7. Semantic name remains unreviewed. */

undefined4 FUN_4052dc64(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  uint local_10 [2];
  
  local_10[0] = 0;
  local_10[1] = 4;
  uVar3 = 0;
  bVar1 = FUN_4052dbbc();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_4053aef8(0,0x32,local_10,local_10 + 1);
    if ((iVar2 != 0) && ((local_10[0] & 0x10) != 0)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* 4052dcd8 FUN_4052dcd8 */

/* Boundary evidence: original MIPS .pdata 4052dcd8..4052dd3f. Semantic name remains unreviewed. */

void FUN_4052dcd8(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  memset(&local_10,0,8);
  if (param_1 == 0) {
    local_10 = 1;
  }
  else {
    local_10 = 0x10;
    local_c = 1;
  }
  FUN_4053b040(0,0x32,&local_10,8);
  return;
}



/* 4052dd40 FUN_4052dd40 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4052dd40..4052df0f. Semantic name remains unreviewed. */

undefined4 FUN_4052dd40(uint param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  int *local_30;
  uint local_2c [3];
  
  if ((param_3 == 0) &&
     (((param_1 < 0x1f || (param_1 + 0xafffffff < 0x1c)) || (param_1 + 0x9fffffff < 0xa0000020)))) {
    pwVar3 = L"Software\\Microsoft\\Windows\\CurrentVersion\\Policies";
    if ((param_2 != 0) && (param_1 + 0xaffffffe < 7)) {
      local_30 = (int *)0x0;
      iVar1 = FUN_40516d94((IID *)&DAT_4051679c,(LPUNKNOWN)0x0,1,(IID *)&DAT_405167ac,&local_30);
      if ((-1 < iVar1) && (local_30 != (int *)0x0)) {
        local_2c[0] = 0;
        local_2c[1] = 0;
        iVar1 = (**(code **)(*local_30 + 0x1c))
                          (local_30,param_2,*(undefined4 *)(param_1 * 8 + -0x3faeae7c),local_2c,4,
                           local_2c + 1,4,1,0);
        (**(code **)(*local_30 + 8))();
        if (-1 < iVar1) {
          if ((local_2c[0] & 0xf) != 0) {
            return 1;
          }
          goto LAB_4052dd6c;
        }
      }
    }
    if ((0x1e < param_1) &&
       (pwVar3 = L"Software\\Policies\\Microsoft\\Internet Explorer",
       0xa000001f < param_1 + 0x9fffffff)) {
      pwVar3 = L"Software\\Policies\\Microsoft\\Internet Explorer\\Infodelivery";
    }
    uVar2 = SHRestrictionLookup(param_1,pwVar3,&DAT_40514d94,&DAT_405445ac);
  }
  else {
LAB_4052dd6c:
    uVar2 = 0;
  }
  return uVar2;
}



/* 4052df10 FUN_4052df10 */

/* Boundary evidence: original MIPS .pdata 4052df10..4052df63. Semantic name remains unreviewed. */

void FUN_4052df10(void)

{
  if (DAT_40544704 == (HANDLE)0x0) {
    DAT_40544704 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,0x7fffffff,L"_ie_sessioncount");
  }
  return;
}



/* 4052df64 FUN_4052df64 */

/* Boundary evidence: original MIPS .pdata 4052df64..4052dfcb. Semantic name remains unreviewed. */

long FUN_4052df64(void)

{
  HANDLE hSemaphore;
  long local_10 [2];
  
  local_10[0] = 0x7fffffff;
  hSemaphore = (HANDLE)FUN_4052df10();
  if (hSemaphore != (HANDLE)0x0) {
    ReleaseSemaphore(hSemaphore,1,local_10);
    WaitForSingleObject(hSemaphore,0);
  }
  return local_10[0];
}



/* 4052dfcc FUN_4052dfcc */

/* Boundary evidence: original MIPS .pdata 4052dfcc..4052e013. Semantic name remains unreviewed. */

long FUN_4052dfcc(void)

{
  HANDLE hSemaphore;
  long local_10 [2];
  
  local_10[0] = 0x7fffffff;
  hSemaphore = (HANDLE)FUN_4052df10();
  if (hSemaphore != (HANDLE)0x0) {
    ReleaseSemaphore(hSemaphore,1,local_10);
  }
  return local_10[0];
}



/* 4052e014 FUN_4052e014 */

/* Boundary evidence: original MIPS .pdata 4052e014..4052e0b7. Semantic name remains unreviewed. */

int FUN_4052e014(void)

{
  HANDLE hSemaphore;
  long local_18 [2];
  
  local_18[0] = 0x7fffffff;
  hSemaphore = (HANDLE)FUN_4052df10();
  if (hSemaphore != (HANDLE)0x0) {
    ReleaseSemaphore(hSemaphore,1,local_18);
    if (local_18[0] < 1) {
      WaitForSingleObject(hSemaphore,0);
    }
    else {
      WaitForSingleObject(hSemaphore,0);
      WaitForSingleObject(hSemaphore,0);
      local_18[0] = local_18[0] + -1;
    }
  }
  return local_18[0];
}



/* 4052e0b8 FUN_4052e0b8 */

/* Boundary evidence: original MIPS .pdata 4052e0b8..4052e26b. Semantic name remains unreviewed. */

long FUN_4052e0b8(int param_1)

{
  long lVar1;
  UINT UVar2;
  int iVar3;
  HMODULE pHVar4;
  code *pcVar5;
  HWND pHVar6;
  
  if (param_1 == 0) {
    lVar1 = FUN_4052df64();
    return lVar1;
  }
  if (param_1 != 1) {
    if (param_1 == 2) {
      iVar3 = FUN_4052e014();
      if (iVar3 != 0) {
        return iVar3;
      }
      if ((DAT_4054477c != 0) || (DAT_4054472c != 0)) {
        FUN_4053b040(0,0x2a,0,0);
        FUN_4053b040(0,0x3c,0,0);
      }
      UVar2 = WhichPlatform();
      if (((UVar2 == 2) && (pHVar4 = GetModuleHandleW(L"msjava.dll"), pHVar4 != (HMODULE)0x0)) &&
         (pcVar5 = (code *)GetProcAddressW(pHVar4,L"NotifyBrowserShutdown"), pcVar5 != (code *)0x0))
      {
        (*pcVar5)(0);
      }
      pHVar6 = FindWindowW(L"MS_AutodialMonitor",(LPCWSTR)0x0);
      if (pHVar6 != (HWND)0x0) {
        PostMessageW(pHVar6,0x467,0,0);
      }
      pHVar6 = FindWindowW(L"MS_WebcheckMonitor",(LPCWSTR)0x0);
      if (pHVar6 == (HWND)0x0) {
        return 0;
      }
      PostMessageW(pHVar6,0x467,0,0);
      return 0;
    }
    if (param_1 != 3) {
      return 0;
    }
  }
  lVar1 = FUN_4052dfcc();
  UVar2 = WhichPlatform();
  if (UVar2 == 2) {
    FUN_4053b040(0,0x3c,0,0);
  }
  return lVar1;
}



/* 4052e26c FUN_4052e26c */

/* Boundary evidence: original MIPS .pdata 4052e26c..4052e2cf. Semantic name remains unreviewed. */

bool FUN_4052e26c(HWND param_1,LPCWSTR param_2)

{
  int iVar1;
  WCHAR aWStack_50 [32];
  uint local_10;
  
  local_10 = DAT_40544354;
  GetClassNameW(param_1,aWStack_50,0x20);
  iVar1 = StrCmpW(aWStack_50,param_2);
  FUN_40542538(local_10);
  return iVar1 == 0;
}



/* 4052e2d0 FUN_4052e2d0 */

/* Boundary evidence: original MIPS .pdata 4052e2d0..4052e2f7. Semantic name remains unreviewed. */

void FUN_4052e2d0(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40515400,param_2,param_3);
  return;
}



/* 4052e2f8 FUN_4052e2f8 */

/* Boundary evidence: original MIPS .pdata 4052e2f8..4052e313. Semantic name remains unreviewed. */

void FUN_4052e2f8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 4052e314 FUN_4052e314 */

/* Boundary evidence: original MIPS .pdata 4052e314..4052e3c7. Semantic name remains unreviewed. */

undefined1 * FUN_4052e314(int param_1,uint param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = param_2 + *(int *)(param_1 + 0xc) + 6 & 0xffff;
  puVar2 = (undefined1 *)FUN_4053f298(uVar3 + 2);
  if (puVar2 != (undefined1 *)0x0) {
    puVar2[1] = (char)(uVar3 >> 8);
    *puVar2 = (char)uVar3;
    uVar1 = *(undefined2 *)(param_1 + 8);
    puVar2[2] = (char)uVar1;
    puVar2[4] = (char)(param_2 & 0xffff);
    puVar2[3] = (char)((ushort)uVar1 >> 8);
    puVar2[5] = (char)((param_2 & 0xffff) >> 8);
    memcpy(puVar2 + param_2 + 6,(void *)(param_1 + 0x10),*(size_t *)(param_1 + 0xc));
    puVar2[uVar3] = 0;
    (puVar2 + uVar3)[1] = 0;
  }
  return puVar2;
}



/* 4052e3c8 FUN_4052e3c8 */

/* Boundary evidence: original MIPS .pdata 4052e3c8..4052e3e3. Semantic name remains unreviewed. */

void FUN_4052e3c8(undefined4 param_1,undefined4 param_2)

{
  FUN_4053f2d4(param_2);
  return;
}



/* 4052e3e4 FUN_4052e3e4 */

/* Boundary evidence: original MIPS .pdata 4052e3e4..4052e44f. Semantic name remains unreviewed. */

undefined4 FUN_4052e3e4(int param_1)

{
  undefined4 uVar1;
  short extraout_var;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 4) != 0x100)) ||
     ((*(int *)(param_1 + 8) != 9 && (*(int *)(param_1 + 8) != 0x75)))) {
    uVar1 = 0;
  }
  else {
    GetKeyState(0x10);
    if (extraout_var < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}



/* 4052e450 FUN_4052e450 */

/* Boundary evidence: original MIPS .pdata 4052e450..4052e4cb. Semantic name remains unreviewed. */

IBindCtx * FUN_4052e450(IUnknown *param_1)

{
  HRESULT HVar1;
  LPBC local_10 [2];
  
  local_10[0] = (IBindCtx *)0x0;
  if (((param_1 != (IUnknown *)0x0) && (HVar1 = CreateBindCtx(0,local_10), -1 < HVar1)) &&
     (HVar1 = (*local_10[0]->lpVtbl->RegisterObjectParam)(local_10[0],L"UI During Binding",param_1),
     HVar1 < 0)) {
    IUnknown_AtomicRelease(local_10);
  }
  return local_10[0];
}



/* 4052e4cc FUN_4052e4cc */

/* Boundary evidence: original MIPS .pdata 4052e4cc..4052e507. Semantic name remains unreviewed. */

void FUN_4052e4cc(void)

{
  if (DAT_40544714 == 0) {
    DAT_40544714 = RegisterWindowMessageW(L"MSWHEEL_ROLLMSG");
  }
  return;
}



/* 4052e508 FUN_4052e508 */

/* Boundary evidence: original MIPS .pdata 4052e508..4052e547. Semantic name remains unreviewed. */

void FUN_4052e508(LPCWSTR param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  
  HVar1 = SHStrDupW(param_1,(LPWSTR *)(param_2 + 1));
  if (-1 < HVar1) {
    *param_2 = 0;
  }
  return;
}



/* 4052e548 FUN_4052e548 */

/* Boundary evidence: original MIPS .pdata 4052e548..4052e693. Semantic name remains unreviewed. */

undefined4 FUN_4052e548(IUnknown *param_1,int param_2,int param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_430;
  size_t local_42c;
  size_t local_428 [2];
  undefined1 auStack_420 [512];
  undefined1 auStack_220 [512];
  uint local_20;
  
  local_20 = DAT_40544354;
  uVar3 = 0;
  if ((param_2 != 0) && (param_3 != 0)) {
    HVar1 = IUnknown_QueryService(param_1,(GUID *)&DAT_405167ac,(IID *)&DAT_405167ac,&local_430);
    if (HVar1 < 0) {
      iVar2 = FUN_40516d94((IID *)&DAT_4051679c,(LPUNKNOWN)0x0,1,(IID *)&DAT_405167ac,&local_430);
      if (iVar2 < 0) goto LAB_4052e66c;
    }
    local_42c = 0x200;
    local_428[0] = 0x200;
    iVar2 = (**(code **)(*local_430 + 0x18))(local_430,param_2,auStack_220,&local_42c,0);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_430 + 0x18))(local_430,param_3,auStack_420,local_428,0);
      if (((-1 < iVar2) && (local_42c == local_428[0])) &&
         (iVar2 = memcmp(auStack_220,auStack_420,local_42c), iVar2 == 0)) {
        uVar3 = 1;
      }
    }
    (**(code **)(*local_430 + 8))();
  }
LAB_4052e66c:
  FUN_40542538(local_20);
  return uVar3;
}



/* 4052e694 FUN_4052e694 */

/* Boundary evidence: original MIPS .pdata 4052e694..4052e777. Semantic name remains unreviewed. */

undefined4 FUN_4052e694(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18;
  int *local_14;
  
  uVar2 = 0;
  local_18 = (int *)0x0;
  local_14 = (int *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x78))(param_1,&local_14);
  if (-1 < iVar1) {
    if (local_14 == (int *)0x0) goto LAB_4052e748;
    iVar1 = (**(code **)(*param_1 + 0x70))(param_1,&local_18);
    if (((-1 < iVar1) && (local_18 != (int *)0x0)) &&
       (iVar1 = SHIsSameObject(local_14,local_18), iVar1 == 0)) {
      uVar2 = 1;
    }
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_4052e748:
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  return uVar2;
}



/* 4052e778 FUN_4052e778 */

/* Boundary evidence: original MIPS .pdata 4052e778..4052e80b. Semantic name remains unreviewed. */

int FUN_4052e778(ushort *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_18 [2];
  
  iVar1 = -0x7ff8ffa9;
  *param_3 = 0;
  if ((param_1 != (ushort *)0x0) &&
     (iVar1 = FUN_40522e04(param_1,0,&DAT_405165dc,(int *)local_18), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_18[0] + 0xc))(local_18[0],param_2,param_3);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 4052e80c FUN_4052e80c */

/* Boundary evidence: original MIPS .pdata 4052e80c..4052e863. Semantic name remains unreviewed. */

undefined4 FUN_4052e80c(ushort *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  local_18[0] = 0;
  uVar2 = 0;
  iVar1 = FUN_4052e778(param_1,param_2,local_18);
  if ((-1 < iVar1) && (local_18[0] == param_2)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4052e864 FUN_4052e864 */

/* Boundary evidence: original MIPS .pdata 4052e864..4052e8af. Semantic name remains unreviewed. */

undefined4 FUN_4052e864(LPCWSTR param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4053ad2c(param_1);
  if (((iVar1 == 0xf) || (iVar1 == 0x10)) || (iVar1 == 0x11)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4052e8b0 FUN_4052e8b0 */

/* Boundary evidence: original MIPS .pdata 4052e8b0..4052eac3. Semantic name remains unreviewed. */

undefined4 FUN_4052e8b0(undefined4 *param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  UINT UVar3;
  size_t sVar4;
  size_t sVar5;
  BSTR pOVar6;
  wchar_t *lpStart;
  SIZE_T uBytes;
  wchar_t *psz1;
  undefined4 uVar7;
  LPCWSTR lpFirst;
  int iVar8;
  uint cchMax;
  undefined1 auStack_2038 [8];
  WCHAR aWStack_2030 [4096];
  uint local_30;
  
  local_30 = DAT_40544354;
  lpFirst = (LPCWSTR)*param_1;
  uVar7 = 0;
  psz1 = (wchar_t *)0x0;
  iVar1 = FUN_4052e864(lpFirst);
  if (iVar1 == 0) goto LAB_4052ea80;
  pWVar2 = StrStrW(lpFirst,L"%00");
  if (pWVar2 == (LPWSTR)0x0) {
    UVar3 = SysStringLen(lpFirst);
    cchMax = UVar3 + 1;
    if (cchMax < 0x80000000) {
      uBytes = cchMax * 2;
    }
    else {
      uBytes = 0xffffffff;
    }
    psz1 = LocalAlloc(0x40,uBytes);
    if (psz1 != (wchar_t *)0x0) {
      StrCpyNW(psz1,lpFirst,cchMax);
      sVar4 = wcslen(psz1);
      if (sVar4 != 0) {
        do {
          pWVar2 = StrChrW(psz1,L'%');
          if (pWVar2 == (LPWSTR)0x0) break;
          sVar4 = wcslen(psz1);
          iVar1 = 0;
          while( true ) {
            iVar8 = 0;
            lpStart = psz1;
            while (pWVar2 = StrChrW(lpStart,L'%'), pWVar2 != (LPWSTR)0x0) {
              iVar8 = iVar8 + 1;
              lpStart = pWVar2 + 1;
            }
            if (iVar8 == iVar1) break;
            uVar7 = FUN_4053b2f4(psz1,7,0,aWStack_2030,0x1000,auStack_2038,0);
            StrCpyNW(psz1,aWStack_2030,cchMax);
            iVar1 = iVar8;
          }
          sVar5 = wcslen(psz1);
        } while (sVar4 != sVar5);
      }
      pWVar2 = StrChrW(psz1,L'\x01');
      if (pWVar2 != (LPWSTR)0x0) goto LAB_4052ea54;
      SysFreeString((BSTR)*param_1);
      pOVar6 = SysAllocString(psz1);
      *param_1 = pOVar6;
      if (pOVar6 != (BSTR)0x0) goto LAB_4052ea80;
    }
    uVar7 = 0x8007000e;
  }
  else {
LAB_4052ea54:
    uVar7 = 0x80070005;
  }
LAB_4052ea80:
  operator_delete(psz1);
  FUN_40542538(local_30);
  return uVar7;
}



/* 4052eac4 FUN_4052eac4 */

/* Boundary evidence: original MIPS .pdata 4052eac4..4052eb7f. Semantic name remains unreviewed. */

HRESULT FUN_4052eac4(VARIANTARG *param_1)

{
  VARTYPE VVar1;
  HRESULT HVar2;
  int *piVar3;
  
  VVar1 = (param_1->n1).n2.vt;
  if ((VVar1 == 0) || (VVar1 == 3)) goto LAB_4052eb68;
  if (VVar1 != 9) {
    if (VVar1 == 0xb) goto LAB_4052eb68;
    if (VVar1 != 0xd) {
      if (VVar1 != 0x13) {
        if (VVar1 != 0x1b) {
          HVar2 = VariantClear(param_1);
          return HVar2;
        }
        SafeArrayDestroy(*(SAFEARRAY **)((int)&param_1->n1 + 8));
      }
      goto LAB_4052eb68;
    }
  }
  piVar3 = *(int **)((int)&param_1->n1 + 8);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
LAB_4052eb68:
  (param_1->n1).n2.vt = 0;
  return 0;
}



/* 4052eb80 FUN_4052eb80 */

/* Boundary evidence: original MIPS .pdata 4052eb80..4052ebbb. Semantic name remains unreviewed. */

char * FUN_4052eb80(ushort *param_1)

{
  char *pcVar1;
  
  pcVar1 = FUN_4052d908(param_1);
  if (pcVar1 != (char *)0x0) {
    FUN_40537ddc(pcVar1);
  }
  return pcVar1;
}



/* 4052ebbc FUN_4052ebbc */

/* Boundary evidence: original MIPS .pdata 4052ebbc..4052ec6f. Semantic name remains unreviewed. */

int FUN_4052ebbc(int *param_1,ushort *param_2,undefined4 param_3,int *param_4,undefined4 *param_5)

{
  char *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  
  pcVar1 = FUN_4052d908(param_2);
  if (pcVar1 == (char *)0x0) {
    iVar2 = -0x7ff8fff2;
  }
  else {
    FUN_40537ddc(pcVar1);
    iVar2 = FUN_4052cdbc(param_1,param_3,pcVar1,param_4);
    FUN_40537f64((int)pcVar1);
  }
  if (param_5 != (undefined4 *)0x0) {
    puVar3 = FUN_40537d94((undefined1 *)param_2);
    *param_5 = puVar3;
  }
  return iVar2;
}



/* 4052ec70 FUN_4052ec70 */

/* Boundary evidence: original MIPS .pdata 4052ec70..4052ec9b. Semantic name remains unreviewed. */

void FUN_4052ec70(ushort *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  FUN_4052ebbc((int *)0x0,param_1,param_2,param_3,param_4);
  return;
}



/* 4052ec9c FUN_4052ec9c */

/* Boundary evidence: original MIPS .pdata 4052ec9c..4052eccb. Semantic name remains unreviewed. */

void * FUN_4052ec9c(ushort *param_1)

{
  void *pvVar1;
  
  if (param_1 == (ushort *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_4052d908(param_1);
  }
  return pvVar1;
}



/* 4052eccc FUN_4052eccc */

/* Boundary evidence: original MIPS .pdata 4052eccc..4052ed27. Semantic name remains unreviewed. */

bool FUN_4052eccc(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_4052dd40(param_2,param_3,param_4);
  if (iVar1 != 0) {
    SHRestrictedMessageBox(param_1);
  }
  return iVar1 != 0;
}



/* 4052ed28 FUN_4052ed28 */

/* Boundary evidence: original MIPS .pdata 4052ed28..4052ed8b. Semantic name remains unreviewed. */

LONG FUN_4052ed28(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = &PTR_FUN_405153dc;
      operator_delete(param_1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[1];
  }
  return LVar1;
}



/* 4052ed8c FUN_4052ed8c */

/* Boundary evidence: original MIPS .pdata 4052ed8c..4052ee83. Semantic name remains unreviewed. */

HRESULT FUN_4052ed8c(VARIANTARG *param_1,VARIANTARG *param_2)

{
  VARTYPE VVar1;
  HRESULT HVar2;
  int *piVar3;
  
  FUN_4052eac4(param_1);
  VVar1 = (param_2->n1).n2.vt;
  if ((VVar1 != 3) && (VVar1 != 0xb)) {
    if (VVar1 == 0xd) {
      if (param_1 == (VARIANTARG *)0x0) {
        return -0x7ff8ffa9;
      }
      *(undefined4 *)&param_1->n1 = *(undefined4 *)&param_2->n1;
      (param_1->n1).decVal.Hi32 = (param_2->n1).decVal.Hi32;
      piVar3 = *(int **)((int)&param_2->n1 + 8);
      *(int **)((int)&param_1->n1 + 8) = piVar3;
      *(undefined4 *)((int)&param_1->n1 + 0xc) = *(undefined4 *)((int)&param_2->n1 + 0xc);
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      (**(code **)(*piVar3 + 4))();
      return 0;
    }
    if (VVar1 != 0x13) {
      HVar2 = VariantCopy(param_1,param_2);
      return HVar2;
    }
  }
  *(undefined4 *)&param_1->n1 = *(undefined4 *)&param_2->n1;
  (param_1->n1).decVal.Hi32 = (param_2->n1).decVal.Hi32;
  *(undefined4 *)((int)&param_1->n1 + 8) = *(undefined4 *)((int)&param_2->n1 + 8);
  *(undefined4 *)((int)&param_1->n1 + 0xc) = *(undefined4 *)((int)&param_2->n1 + 0xc);
  return 0;
}



/* 4052ee84 FUN_4052ee84 */

/* Boundary evidence: original MIPS .pdata 4052ee84..4052ef6b. Semantic name remains unreviewed. */

undefined4 FUN_4052ee84(void *param_1,size_t param_2,undefined2 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = LocalAlloc(0x40,param_2 + 0x10);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)&PTR_FUN_405153dc;
    piVar1[1] = 1;
    *(undefined2 *)(piVar1 + 2) = param_3;
    piVar1[3] = param_2;
    memcpy(piVar1 + 4,param_1,param_2);
  }
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = (**(code **)*piVar1)(piVar1,&DAT_405167bc,param_4);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



/* 4052ef6c FUN_4052ef6c */

/* Boundary evidence: original MIPS .pdata 4052ef6c..4052ef93. Semantic name remains unreviewed. */

void FUN_4052ef6c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  return;
}



/* 4052ef94 FUN_4052ef94 */

/* Boundary evidence: original MIPS .pdata 4052ef94..4052efbb. Semantic name remains unreviewed. */

void FUN_4052ef94(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return;
}



/* 4052efbc FUN_4052efbc */

/* Boundary evidence: original MIPS .pdata 4052efbc..4052efe3. Semantic name remains unreviewed. */

void FUN_4052efbc(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + 0xc))();
  return;
}



/* 4052eff4 FUN_4052eff4 */

/* Boundary evidence: original MIPS .pdata 4052eff4..4052f03f. Semantic name remains unreviewed. */

int FUN_4052eff4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 4) + -1;
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 4) = 1000;
    piVar2 = (int *)(param_1 + -4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4052f040 FUN_4052f040 */

void FUN_4052f040(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4051548c;
  return;
}



/* 4052f050 FUN_4052f050 */

/* Boundary evidence: original MIPS .pdata 4052f050..4052f08f. Semantic name remains unreviewed. */

void FUN_4052f050(int param_1,void **param_2)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  IUnknown_AtomicRelease(param_2);
  return;
}



/* 4052f090 FUN_4052f090 */

/* Boundary evidence: original MIPS .pdata 4052f090..4052f0e3. Semantic name remains unreviewed. */

undefined4 FUN_4052f090(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)**(undefined4 **)(param_1 + 0xc))();
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  return uVar1;
}



/* 4052f0e4 FUN_4052f0e4 */

/* Boundary evidence: original MIPS .pdata 4052f0e4..4052f167. Semantic name remains unreviewed. */

undefined4 FUN_4052f0e4(int param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_405162fc,0x10);
  if (iVar1 == 0) {
    *param_3 = param_1;
    uVar2 = 0;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_1 + -4) + 0x10))((int *)(param_1 + -4),param_2,param_3);
  }
  return uVar2;
}



/* 4052f168 FUN_4052f168 */

undefined4 * FUN_4052f168(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = &PTR_FUN_4051548c;
  param_1[1] = &PTR_FUN_405154a0;
  param_1[2] = 1;
  if (param_2 == (undefined4 *)0x0) {
    param_2 = param_1 + 1;
  }
  param_1[3] = param_2;
  return param_1;
}



/* 4052f1a0 FUN_4052f1a0 */

/* Boundary evidence: original MIPS .pdata 4052f1a0..4052f1e3. Semantic name remains unreviewed. */

undefined4 * FUN_4052f1a0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4051548c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4052f1e4 FUN_4052f1e4 */

/* Boundary evidence: original MIPS .pdata 4052f1e4..4052f32b. Semantic name remains unreviewed. */

undefined4 FUN_4052f1e4(HWND param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 1) {
    piVar2 = (int *)*param_4;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      piVar2[1] = (int)param_1;
      SetWindowLongW(param_1,0,(LONG)piVar2);
      uVar1 = (**(code **)(*piVar2 + 8))(piVar2,param_1,1,param_3,param_4);
    }
  }
  else {
    piVar2 = (int *)GetWindowLongW(param_1,0);
    if (piVar2 == (int *)0x0) {
      uVar1 = SHDefWindowProc(param_1,param_2,param_3,param_4);
    }
    else {
      (**(code **)*piVar2)(piVar2);
      uVar1 = (**(code **)(*piVar2 + 8))(piVar2,param_1,param_2,param_3,param_4);
      if (param_2 == 2) {
        SetWindowLongW(param_1,0,0);
        piVar2[1] = 0;
      }
      (**(code **)(*piVar2 + 4))(piVar2);
    }
  }
  return uVar1;
}



/* 4052f32c FUN_4052f32c */

/* Boundary evidence: original MIPS .pdata 4052f32c..4052f39b. Semantic name remains unreviewed. */

undefined4 FUN_4052f32c(int *param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))(param_1,0,param_2);
  if (piVar1 == (int *)0x0) {
    *param_3 = 0;
    uVar2 = 0x80004002;
  }
  else {
    (**(code **)(*piVar1 + 4))(piVar1);
    uVar2 = 0;
    *param_3 = (int)piVar1;
  }
  return uVar2;
}



/* 4052f39c FUN_4052f39c */

/* Boundary evidence: original MIPS .pdata 4052f39c..4052f41f. Semantic name remains unreviewed. */

undefined4 FUN_4052f39c(int *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = (int *)(**(code **)(*param_1 + 0x14))(param_1,1,param_2);
    if (piVar2 == (int *)0x0) {
      *param_3 = 0;
      uVar1 = 0x80004002;
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
      uVar1 = 0;
      *param_3 = (int)piVar2;
    }
  }
  return uVar1;
}



/* 4052f420 FUN_4052f420 */

undefined4 *
FUN_4052f420(undefined4 *param_1,undefined4 param_2,undefined2 param_3,undefined2 param_4,
            undefined4 param_5)

{
  *param_1 = &PTR_LAB_405154ac;
  param_1[1] = param_5;
  param_1[2] = param_2;
  *(undefined2 *)(param_1 + 3) = param_3;
  *(undefined2 *)((int)param_1 + 0xe) = param_4;
  return param_1;
}



/* 4052f448 FUN_4052f448 */

/* Boundary evidence: original MIPS .pdata 4052f448..4052f477. Semantic name remains unreviewed. */

void FUN_4052f448(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_405154ac;
  IUnknown_AtomicRelease((void **)(param_1 + 4));
  return;
}



/* 4052f478 FUN_4052f478 */

undefined4 FUN_4052f478(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}



/* 4052f488 FUN_4052f488 */

/* Boundary evidence: original MIPS .pdata 4052f488..4052f627. Semantic name remains unreviewed. */

HRESULT FUN_4052f488(uint param_1,GUID *param_2,int param_3,WORD param_4,GUID *param_5,
                    ITypeInfo **param_6)

{
  int iVar1;
  HRESULT HVar2;
  DWORD DVar3;
  ITypeLib *local_250 [2];
  wchar_t awStack_248 [12];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_40544354;
  *param_6 = (ITypeInfo *)0x0;
  iVar1 = memcmp(param_2,&DAT_4051674c,0x10);
  if (iVar1 == 0) {
    local_250[0] = (ITypeLib *)0x0;
    HVar2 = -0x7fffbffb;
  }
  else {
    HVar2 = LoadRegTypeLib(param_2,(WORD)param_3,param_4,param_1 & 0x3ff,local_250);
    param_3 = 0;
  }
  if (HVar2 < 0) {
    if (DAT_40544588 != (HMODULE)0x0) {
      DVar3 = GetModuleFileNameW(DAT_40544588,aWStack_230,0x104);
      if (DVar3 != 0) {
        if (param_3 != 0) {
          StringCchPrintfW(awStack_248,10,L"\\%d",param_3);
          StringCchCatW(aWStack_230,0x104,awStack_248);
        }
        if (((param_1 & 0x3ff) == 0) || ((param_1 & 0x3ff) == 9)) {
          HVar2 = LoadTypeLib(aWStack_230,local_250);
        }
      }
    }
    if (HVar2 < 0) goto LAB_4052f5f8;
  }
  HVar2 = (*local_250[0]->lpVtbl->GetTypeInfoOfGuid)(local_250[0],param_5,param_6);
  (*local_250[0]->lpVtbl->Release)(local_250[0]);
LAB_4052f5f8:
  FUN_40542538(local_28);
  return HVar2;
}



/* 4052f628 FUN_4052f628 */

/* Boundary evidence: original MIPS .pdata 4052f628..4052f727. Semantic name remains unreviewed. */

HRESULT FUN_4052f628(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  ITypeInfo **ppTInfo;
  ITypeInfo *local_18;
  HREFTYPE local_14;
  
  *param_4 = 0;
  if (param_2 == 0) {
    ppTInfo = (ITypeInfo **)(param_1 + 0x10);
    if (*ppTInfo == (ITypeInfo *)0x0) {
      HVar1 = FUN_4052f488(param_3,*(GUID **)(param_1 + 8),(uint)*(ushort *)(param_1 + 0xc),
                           *(WORD *)(param_1 + 0xe),*(GUID **)(param_1 + 4),&local_18);
      if (HVar1 < 0) {
        return HVar1;
      }
      HVar1 = (*local_18->lpVtbl->GetRefTypeOfImplType)(local_18,0xffffffff,&local_14);
      if ((HVar1 < 0) ||
         (HVar1 = (*local_18->lpVtbl->GetRefTypeInfo)(local_18,local_14,ppTInfo), HVar1 < 0)) {
        *ppTInfo = local_18;
      }
      else {
        (*local_18->lpVtbl->Release)(local_18);
      }
    }
    (*(*ppTInfo)->lpVtbl->AddRef)(*ppTInfo);
    HVar1 = 0;
    *param_4 = *ppTInfo;
  }
  else {
    HVar1 = -0x7ffd7fd5;
  }
  return HVar1;
}



/* 4052f728 FUN_4052f728 */

/* Boundary evidence: original MIPS .pdata 4052f728..4052f88f. Semantic name remains unreviewed. */

HRESULT FUN_4052f728(int param_1,void *param_2,LPOLESTR *param_3,UINT param_4,uint param_5,
                    MEMBERID *param_6)

{
  int iVar1;
  HRESULT HVar2;
  ITypeInfo **ppTInfo;
  ITypeInfo *This;
  ITypeInfo *local_20;
  HREFTYPE local_1c;
  
  iVar1 = memcmp(&DAT_4051674c,param_2,0x10);
  if (iVar1 != 0) {
    return -0x7ffdffff;
  }
  ppTInfo = (ITypeInfo **)(param_1 + 0x10);
  This = (ITypeInfo *)0x0;
  if (*ppTInfo == (ITypeInfo *)0x0) {
    HVar2 = FUN_4052f488(param_5,*(GUID **)(param_1 + 8),(uint)*(ushort *)(param_1 + 0xc),
                         *(WORD *)(param_1 + 0xe),*(GUID **)(param_1 + 4),&local_20);
    if (HVar2 < 0) goto LAB_4052f834;
    HVar2 = (*local_20->lpVtbl->GetRefTypeOfImplType)(local_20,0xffffffff,&local_1c);
    if ((HVar2 < 0) ||
       (HVar2 = (*local_20->lpVtbl->GetRefTypeInfo)(local_20,local_1c,ppTInfo), HVar2 < 0)) {
      *ppTInfo = local_20;
    }
    else {
      (*local_20->lpVtbl->Release)(local_20);
    }
  }
  (*(*ppTInfo)->lpVtbl->AddRef)(*ppTInfo);
  This = *ppTInfo;
  HVar2 = 0;
LAB_4052f834:
  if (-1 < HVar2) {
    HVar2 = (*This->lpVtbl->GetIDsOfNames)(This,param_3,param_4,param_6);
    (*This->lpVtbl->Release)(This);
  }
  return HVar2;
}



/* 4052f890 FUN_4052f890 */

/* Boundary evidence: original MIPS .pdata 4052f890..4052fa73. Semantic name remains unreviewed. */

HRESULT FUN_4052f890(undefined4 *param_1,MEMBERID param_2,void *param_3,uint param_4,WORD param_5,
                    DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  int iVar1;
  HRESULT HVar2;
  ITypeInfo **ppTInfo;
  ITypeInfo *This;
  ITypeInfo *local_30;
  int *local_2c;
  HREFTYPE local_28 [2];
  
  iVar1 = memcmp(&DAT_4051674c,param_3,0x10);
  if (iVar1 != 0) {
    return -0x7ffdffff;
  }
  iVar1 = (**(code **)*param_1)(param_1,param_1[1],&local_2c);
  if (iVar1 < 0) {
    return iVar1;
  }
  ppTInfo = (ITypeInfo **)(param_1 + 4);
  This = (ITypeInfo *)0x0;
  if (*ppTInfo == (ITypeInfo *)0x0) {
    HVar2 = FUN_4052f488(param_4,(GUID *)param_1[2],(uint)*(ushort *)(param_1 + 3),
                         *(WORD *)((int)param_1 + 0xe),(GUID *)param_1[1],&local_30);
    if (HVar2 < 0) goto LAB_4052f9cc;
    HVar2 = (*local_30->lpVtbl->GetRefTypeOfImplType)(local_30,0xffffffff,local_28);
    if ((HVar2 < 0) ||
       (HVar2 = (*local_30->lpVtbl->GetRefTypeInfo)(local_30,local_28[0],ppTInfo), HVar2 < 0)) {
      *ppTInfo = local_30;
    }
    else {
      (*local_30->lpVtbl->Release)(local_30);
    }
  }
  (*(*ppTInfo)->lpVtbl->AddRef)(*ppTInfo);
  This = *ppTInfo;
  HVar2 = 0;
LAB_4052f9cc:
  if (-1 < HVar2) {
    SetErrorInfo(0,(IErrorInfo *)0x0);
    HVar2 = (*This->lpVtbl->Invoke)(This,local_2c,param_2,param_5,param_6,param_7,param_8,param_9);
    (*This->lpVtbl->Release)(This);
  }
  (**(code **)(*local_2c + 8))();
  return HVar2;
}



/* 4052fa74 FUN_4052fa74 */

/* Boundary evidence: original MIPS .pdata 4052fa74..4052fad3. Semantic name remains unreviewed. */

undefined4 * FUN_4052fa74(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_405154ac;
  IUnknown_AtomicRelease((void **)(param_1 + 4));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4052fad4 FUN_4052fad4 */

/* Boundary evidence: original MIPS .pdata 4052fad4..4052fc03. Semantic name remains unreviewed. */

void FUN_4052fad4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_405156e4;
  param_1[1] = &PTR_LAB_40515684;
  param_1[2] = &PTR_LAB_4051565c;
  param_1[3] = &PTR_LAB_4051562c;
  param_1[4] = &PTR_LAB_40515608;
  param_1[5] = &PTR_LAB_405155e0;
  param_1[6] = &PTR_LAB_405155cc;
  param_1[7] = &PTR_LAB_405155b8;
  param_1[0xb] = &PTR_LAB_405155ac;
  param_1[0x2e] = &PTR_LAB_40515588;
  param_1[0x2f] = &PTR_LAB_4051556c;
  param_1[0x30] = &PTR_LAB_40515550;
  param_1[0x31] = &PTR_LAB_40515534;
  param_1[0x32] = &PTR_LAB_40515520;
  param_1[0x33] = &PTR_LAB_40515508;
  param_1[0x34] = &PTR_LAB_40515500;
  if ((int *)param_1[0x39] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x39] + 8))();
  }
  FUN_40530f9c(param_1 + 0x44);
  FUN_40530f9c(param_1 + 0x3e);
  FUN_4052f448(param_1 + 0x34);
  param_1[0x33] = &PTR_LAB_405154cc;
  FUN_405173b4(param_1);
  return;
}



/* 4052fc04 FUN_4052fc04 */

/* Boundary evidence: original MIPS .pdata 4052fc04..4052fc6b. Semantic name remains unreviewed. */

void FUN_4052fc04(int param_1,IID *param_2,void **param_3)

{
  HRESULT HVar1;
  
  HVar1 = QISearch((void *)(param_1 + -0x1c),(LPCQITAB)&PTR_DAT_4051570c,param_2,param_3);
  if (HVar1 < 0) {
    FUN_40517388(param_1,param_2,param_3);
  }
  return;
}



/* 4052fc6c FUN_4052fc6c */

/* Boundary evidence: original MIPS .pdata 4052fc6c..4052fcbf. Semantic name remains unreviewed. */

void FUN_4052fc6c(int param_1,int *param_2)

{
  if (*(int **)(param_1 + 0xe8) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xe8) + 8))();
    *(undefined4 *)(param_1 + 0xe8) = 0;
  }
  FUN_40517654(param_1,param_2);
  return;
}



/* 4052fcc0 FUN_4052fcc0 */

/* Boundary evidence: original MIPS .pdata 4052fcc0..4052fd0f. Semantic name remains unreviewed. */

void FUN_4052fcc0(int param_1,undefined4 param_2,int param_3)

{
  FUN_40517578(param_1,param_2,param_3);
  return;
}



/* 4052fd28 FUN_4052fd28 */

undefined4 FUN_4052fd28(int param_1,int param_2)

{
  if ((param_2 == -0x2c5) || (param_2 == -1)) {
    *(undefined4 *)(param_1 + 0x30) = 0xffffffff;
  }
  return 0;
}



/* 4052fd48 FUN_4052fd48 */

undefined4 FUN_4052fd48(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x34) = (param_2 ^ *(uint *)(param_1 + 0x34)) & 1 ^ *(uint *)(param_1 + 0x34);
  return 0;
}



/* 4052fd68 FUN_4052fd68 */

/* Boundary evidence: original MIPS .pdata 4052fd68..4052fe57. Semantic name remains unreviewed. */

HRESULT FUN_4052fd68(int param_1,void *param_2,LPOLESTR *param_3,UINT param_4,uint param_5,
                    MEMBERID *param_6)

{
  HRESULT HVar1;
  int iVar2;
  wchar_t *local_28 [2];
  
  HVar1 = FUN_4052f728(param_1 + 0xc,param_2,param_3,param_4,param_5,param_6);
  if (((HVar1 < 0) && (param_4 == 1)) && (param_3 != (LPOLESTR *)0x0)) {
    local_28[0] = L"Document";
    iVar2 = StrCmpIW(*param_3,L"Doc");
    if (iVar2 == 0) {
      HVar1 = FUN_4052f728(param_1 + 0xc,param_2,local_28,1,param_5,param_6);
    }
  }
  return HVar1;
}



/* 4052fe58 FUN_4052fe58 */

/* Boundary evidence: original MIPS .pdata 4052fe58..4052feff. Semantic name remains unreviewed. */

int FUN_4052fe58(int param_1,int param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,*(void **)(*(int *)(param_1 + -0x70) + 0x10),0x10);
  if ((iVar1 == 0) || ((param_2 != 0 && (iVar1 = memcmp(param_3,&DAT_4051643c,0x10), iVar1 == 0))))
  {
    iVar1 = param_1 + 0x2c;
  }
  else {
    iVar1 = memcmp(param_3,&DAT_405164ec,0x10);
    if (iVar1 == 0) {
      iVar1 = param_1 + 0x44;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4052ff00 FUN_4052ff00 */

/* Boundary evidence: original MIPS .pdata 4052ff00..4052ff2b. Semantic name remains unreviewed. */

void FUN_4052ff00(int param_1,undefined4 *param_2)

{
  FUN_40538514(param_2,2,param_1 + 0x2c,param_1 + 0x44);
  return;
}



/* 4052ff2c FUN_4052ff2c */

/* Boundary evidence: original MIPS .pdata 4052ff2c..4052ffcb. Semantic name remains unreviewed. */

undefined4 FUN_4052ff2c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ITypeInfo *This;
  ITypeInfo **ppIVar2;
  
  ppIVar2 = (ITypeInfo **)(param_1 + 0x1c);
  if (*ppIVar2 == (ITypeInfo *)0x0) {
    FUN_4052f488((uint)DAT_40544334,(GUID *)&DAT_4051685c,1,1,
                 *(GUID **)(*(int *)(param_1 + -0x6c) + 4),ppIVar2);
  }
  This = *ppIVar2;
  if (This == (ITypeInfo *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    (*This->lpVtbl->AddRef)(This);
    uVar1 = 0;
    *param_2 = *ppIVar2;
  }
  return uVar1;
}



/* 40530058 FUN_40530058 */

/* Boundary evidence: original MIPS .pdata 40530058..405301e3. Semantic name remains unreviewed. */

undefined4 FUN_40530058(int param_1,undefined4 param_2,uint param_3,void *param_4)

{
  int iVar1;
  HRESULT HVar2;
  undefined4 *puVar3;
  int *piVar4;
  VARIANTARG VStack_48;
  VARIANTARG VStack_38;
  undefined4 local_28;
  undefined1 auStack_24 [12];
  
  if (*(undefined **)(*(int *)(param_1 + 0x5c) + 4) != &UNK_405133f4) {
    piVar4 = (int *)(param_1 + 0xec);
    if ((*piVar4 == 0) && (puVar3 = *(undefined4 **)(param_1 + 0x34), puVar3 != (undefined4 *)0x0))
    {
      (**(code **)*puVar3)(puVar3,&DAT_4051643c,piVar4);
    }
    if (*piVar4 != 0) {
      local_28 = 0;
      memset(auStack_24,0,0xc);
      memset(&VStack_38,0,0x10);
      iVar1 = (**(code **)(*(int *)*piVar4 + 0x18))
                        ((int *)*piVar4,param_2,&DAT_4051674c,0,2,&local_28,&VStack_38,0,0);
      if (-1 < iVar1) {
        memset(&VStack_48,0,0x10);
        HVar2 = VariantChangeType(&VStack_48,&VStack_38,0,(VARTYPE)param_3);
        if (-1 < HVar2) {
          if (param_3 < 0xe) {
            memcpy(param_4,(void *)((int)&VStack_48.n1 + 8),(uint)(byte)(&DAT_405154bc)[param_3]);
          }
          else {
            HVar2 = -0x7fffbffb;
          }
          FUN_4052eac4(&VStack_48);
        }
        FUN_4052eac4(&VStack_38);
        if (-1 < HVar2) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 4053057c FUN_4053057c */

/* Boundary evidence: original MIPS .pdata 4053057c..405305c7. Semantic name remains unreviewed. */

undefined4 * FUN_4053057c(undefined4 *param_1,uint param_2)

{
  FUN_4052fad4(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405305c8 FUN_405305c8 */

/* Boundary evidence: original MIPS .pdata 405305c8..4053064b. Semantic name remains unreviewed. */

bool FUN_405305c8(int param_1)

{
  int iVar1;
  short local_18 [4];
  
  if (*(int *)(param_1 + 0xf0) == -1) {
    iVar1 = FUN_40530058(param_1,0xfffffd3b,0xb,local_18);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
    else {
      *(uint *)(param_1 + 0xf0) = (uint)(local_18[0] == 0);
    }
  }
  return *(int *)(param_1 + 0xf0) == 1;
}



/* 4053064c FUN_4053064c */

/* Boundary evidence: original MIPS .pdata 4053064c..405306db. Semantic name remains unreviewed. */

undefined4 FUN_4053064c(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  bVar1 = FUN_405305c8(param_1 + -4);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    puVar2 = (undefined4 *)FUN_4052d4e8(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0xe4);
      *puVar2 = &PTR_FUN_405114ec;
      puVar2[1] = 1;
      puVar2[2] = 0;
      puVar2[3] = uVar3;
    }
    *param_2 = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      return 0;
    }
  }
  uVar3 = FUN_40518d70(param_1,param_2);
  return uVar3;
}



/* 405306dc FUN_405306dc */

/* Boundary evidence: original MIPS .pdata 405306dc..4053087f. Semantic name remains unreviewed. */

undefined4 *
FUN_405306dc(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  FUN_40518e68(param_1,param_2,param_3,param_4);
  param_1[0x2e] = &PTR_LAB_40515770;
  param_1[0x2f] = &PTR_LAB_40515794;
  param_1[0x30] = &PTR_LAB_405154e4;
  param_1[0x32] = &PTR_LAB_405157b0;
  param_1[0x33] = &PTR_LAB_405154cc;
  FUN_4052f420(param_1 + 0x34,&DAT_4051685c,1,1,*(undefined4 *)(param_3 + 0xc));
  *param_1 = &PTR_FUN_405156e4;
  param_1[3] = &PTR_LAB_4051562c;
  param_1[1] = &PTR_LAB_40515684;
  param_1[2] = &PTR_LAB_4051565c;
  param_1[6] = &PTR_LAB_405155cc;
  param_1[4] = &PTR_LAB_40515608;
  param_1[5] = &PTR_LAB_405155e0;
  param_1[0x2e] = &PTR_LAB_40515588;
  param_1[7] = &PTR_LAB_405155b8;
  param_1[0xb] = &PTR_LAB_405155ac;
  param_1[0x31] = &PTR_LAB_40515534;
  param_1[0x2f] = &PTR_LAB_4051556c;
  param_1[0x30] = &PTR_LAB_40515550;
  param_1[0x34] = &PTR_LAB_40515500;
  param_1[0x32] = &PTR_LAB_40515520;
  param_1[0x33] = &PTR_LAB_40515508;
  param_1[0x3a] = param_5;
  param_1[0x3e] = &PTR_FUN_4051210c;
  param_1[0x44] = &PTR_FUN_4051210c;
  uVar1 = *(undefined4 *)(param_3 + 0x10);
  param_1[0x42] = param_1 + 8;
  param_1[0x43] = uVar1;
  param_1[0x48] = param_1 + 8;
  param_1[0x49] = &DAT_405164ec;
  param_1[0x3c] = 0xffffffff;
  return param_1;
}



/* 40530880 FUN_40530880 */

/* Boundary evidence: original MIPS .pdata 40530880..405308a7. Semantic name remains unreviewed. */

void FUN_40530880(int *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0xc))(param_1,param_2,0,0);
  return;
}



/* 405308b4 FUN_405308b4 */

/* Boundary evidence: original MIPS .pdata 405308b4..40530907. Semantic name remains unreviewed. */

HLOCAL FUN_405308b4(HLOCAL param_1,SIZE_T param_2)

{
  HLOCAL pvVar1;
  
  if (param_2 == 0) {
    if (param_1 != (HLOCAL)0x0) {
      LocalFree(param_1);
    }
    pvVar1 = (HLOCAL)0x0;
  }
  else if (param_1 == (HLOCAL)0x0) {
    pvVar1 = LocalAlloc(0x40,param_2);
  }
  else {
    pvVar1 = LocalReAlloc(param_1,param_2,0x42);
  }
  return pvVar1;
}



/* 40530908 FUN_40530908 */

/* Boundary evidence: original MIPS .pdata 40530908..40530987. Semantic name remains unreviewed. */

undefined4 FUN_40530908(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 4) != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 0xc))) {
    iVar2 = 0;
    do {
      IUnknown_AtomicRelease((void **)(iVar2 + *(int *)(param_1 + 4)));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar1 < *(int *)(param_1 + 0xc));
  }
  return 0;
}



/* 40530988 FUN_40530988 */

/* Boundary evidence: original MIPS .pdata 40530988..40530a1f. Semantic name remains unreviewed. */

undefined4 FUN_40530988(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_4051686c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405162fc,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 40530a4c FUN_40530a4c */

/* Boundary evidence: original MIPS .pdata 40530a4c..40530a7b. Semantic name remains unreviewed. */

void FUN_40530a4c(int param_1,undefined4 param_2)

{
  (**(code **)**(undefined4 **)(param_1 + 0x10))
            (*(undefined4 **)(param_1 + 0x10),&DAT_405167fc,param_2);
  return;
}



/* 40530a7c FUN_40530a7c */

/* Boundary evidence: original MIPS .pdata 40530a7c..40530c4f. Semantic name remains unreviewed. */

int FUN_40530a7c(int param_1,undefined4 *param_2,int *param_3)

{
  HLOCAL pvVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *local_20;
  int *local_1c;
  
  if (param_3 == (int *)0x0) {
    iVar6 = -0x7fffbffd;
  }
  else {
    *param_3 = 0;
    iVar6 = (**(code **)*param_2)(param_2,*(undefined4 *)(param_1 + 0x14),&local_20);
    if (iVar6 < 0) {
      if (*(undefined **)(param_1 + 0x14) != &DAT_405164ec) {
        iVar6 = (**(code **)*param_2)(param_2,&DAT_4051643c,&local_20);
      }
      if (iVar6 < 0) {
        return -0x7ffbfdfe;
      }
    }
    if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 8)) {
      pvVar1 = FUN_405308b4(*(HLOCAL *)(param_1 + 4),(*(int *)(param_1 + 0xc) + 8) * 4);
      if (pvVar1 == (HLOCAL)0x0) {
        (**(code **)(*local_20 + 8))();
        return -0x7ff8fff2;
      }
      *(HLOCAL *)(param_1 + 4) = pvVar1;
      memset((void *)(*(int *)(param_1 + 0xc) * 4 + (int)pvVar1),0,0x20);
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 8;
    }
    piVar4 = *(int **)(param_1 + 4);
    iVar5 = 0;
    iVar2 = *piVar4;
    piVar3 = piVar4;
    while (iVar2 != 0) {
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + 1;
      iVar2 = *piVar3;
    }
    piVar4[iVar5] = (int)local_20;
    *param_3 = iVar5 + 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    iVar5 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                      (*(undefined4 **)(param_1 + 0x10),&DAT_40512c44,&local_1c);
    if (-1 < iVar5) {
      (**(code **)(*local_1c + 0xc))
                (local_1c,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 8),*param_3);
      (**(code **)(*local_1c + 8))();
    }
  }
  return iVar6;
}



/* 40530c50 FUN_40530c50 */

/* Boundary evidence: original MIPS .pdata 40530c50..40530d3f. Semantic name remains unreviewed. */

undefined4 FUN_40530c50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *local_18 [2];
  
  if (param_2 != 0) {
    if ((*(int *)(param_1 + 0xc) <= param_2 + -1) ||
       (iVar2 = (param_2 + -1) * 4, *(int *)(iVar2 + *(int *)(param_1 + 4)) == 0)) {
      return 0x80040200;
    }
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x10))
                      (*(undefined4 **)(param_1 + 0x10),&DAT_40512c44,local_18);
    if (-1 < iVar1) {
      (**(code **)(*local_18[0] + 0x10))
                (local_18[0],*(undefined4 *)(param_1 + 0x14),*(int *)(param_1 + 8) + -1,param_2);
      (**(code **)(*local_18[0] + 8))();
    }
    IUnknown_AtomicRelease((void **)(iVar2 + *(int *)(param_1 + 4)));
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  return 0;
}



/* 40530d40 FUN_40530d40 */

/* Boundary evidence: original MIPS .pdata 40530d40..40530d73. Semantic name remains unreviewed. */

void FUN_40530d40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  IConnectionPoint_InvokeWithCancel(param_1,param_4,param_5,param_2,param_3);
  return;
}



/* 40530d74 FUN_40530d74 */

/* Boundary evidence: original MIPS .pdata 40530d74..40530e0b. Semantic name remains unreviewed. */

undefined4 FUN_40530d74(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_4051687c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405162fc,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 40530e0c FUN_40530e0c */

/* Boundary evidence: original MIPS .pdata 40530e0c..40530e6b. Semantic name remains unreviewed. */

undefined4 * FUN_40530e0c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_405157c4;
  (**(code **)(*(int *)param_1[2] + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40530e6c FUN_40530e6c */

/* Boundary evidence: original MIPS .pdata 40530e6c..40530f9b. Semantic name remains unreviewed. */

bool FUN_40530e6c(int param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(param_1 + 0xc) < *(int *)(iVar3 + 0xc)) {
        do {
          if (*(int *)(*(int *)(param_1 + 0xc) * 4 + *(int *)(iVar3 + 4)) != 0) break;
          iVar2 = *(int *)(param_1 + 0xc) + 1;
          *(int *)(param_1 + 0xc) = iVar2;
        } while (iVar2 < *(int *)(*(int *)(param_1 + 8) + 0xc));
      }
      if (*(int *)(iVar3 + 0xc) <= *(int *)(param_1 + 0xc)) break;
      if (param_3 != (undefined4 *)0x0) {
        piVar1 = *(int **)(*(int *)(param_1 + 0xc) * 4 + *(int *)(iVar3 + 4));
        *param_3 = piVar1;
        param_3[1] = *(int *)(param_1 + 0xc) + 1;
        (**(code **)(*piVar1 + 4))();
        param_3 = param_3 + 2;
      }
      uVar4 = uVar4 + 1;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    } while (uVar4 < param_2);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar4;
  }
  return uVar4 < param_2;
}



/* 40530f9c FUN_40530f9c */

/* Boundary evidence: original MIPS .pdata 40530f9c..40530fe3. Semantic name remains unreviewed. */

void FUN_40530f9c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_4051210c;
  FUN_40530908((int)param_1);
  if ((HLOCAL)param_1[1] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[1]);
  }
  return;
}



/* 40530fe4 FUN_40530fe4 */

/* Boundary evidence: original MIPS .pdata 40530fe4..4053101b. Semantic name remains unreviewed. */

int FUN_40530fe4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_40530e0c(param_1,1);
  }
  return iVar1;
}



/* 4053101c FUN_4053101c */

/* Boundary evidence: original MIPS .pdata 4053101c..405310bf. Semantic name remains unreviewed. */

undefined4 FUN_4053101c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_405157c4;
    puVar1[1] = 1;
    puVar1[2] = param_1;
    puVar1[3] = param_2;
    (**(code **)(*param_1 + 4))(param_1);
  }
  *param_3 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 405310c0 FUN_405310c0 */

/* Boundary evidence: original MIPS .pdata 405310c0..405310e3. Semantic name remains unreviewed. */

void FUN_405310c0(int param_1,undefined4 *param_2)

{
  FUN_4053101c(*(int **)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2);
  return;
}



/* 405310e4 FUN_405310e4 */

/* Boundary evidence: original MIPS .pdata 405310e4..40531103. Semantic name remains unreviewed. */

void FUN_405310e4(int *param_1,undefined4 *param_2)

{
  FUN_4053101c(param_1,0,param_2);
  return;
}



/* 40531104 FUN_40531104 */

/* Boundary evidence: original MIPS .pdata 40531104..405311df. Semantic name remains unreviewed. */

undefined4 FUN_40531104(void *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_2 = 0;
  *param_3 = 0;
  iVar1 = memcmp(param_1,&DAT_4051643c,0x10);
  if ((((iVar1 == 0) || (iVar1 = memcmp(param_1,&DAT_4051681c,0x10), iVar1 == 0)) ||
      (iVar1 = memcmp(param_1,&DAT_4051680c,0x10), iVar1 == 0)) ||
     ((iVar1 = memcmp(param_1,&DAT_4051682c,0x10), iVar1 == 0 ||
      (iVar1 = memcmp(param_1,&DAT_4051649c,0x10), iVar1 == 0)))) {
    *param_2 = 3;
    *param_3 = 3;
  }
  return 0;
}



/* 405311e0 FUN_405311e0 */

/* Boundary evidence: original MIPS .pdata 405311e0..405312b7. Semantic name remains unreviewed. */

undefined4 FUN_405311e0(void *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 & 0xfffffffc) == 0) {
    iVar2 = memcmp(param_1,&DAT_4051643c,0x10);
    if ((((iVar2 == 0) || (iVar2 = memcmp(param_1,&DAT_4051681c,0x10), iVar2 == 0)) ||
        (iVar2 = memcmp(param_1,&DAT_4051680c,0x10), iVar2 == 0)) ||
       ((iVar2 = memcmp(param_1,&DAT_4051649c,0x10), iVar2 == 0 ||
        (iVar2 = memcmp(param_1,&DAT_4051682c,0x10), iVar2 == 0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004005;
    }
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 405312b8 FUN_405312b8 */

/* Boundary evidence: original MIPS .pdata 405312b8..40531483. Semantic name remains unreviewed. */

bool FUN_405312b8(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  HRESULT HVar2;
  int *local_50;
  int *local_4c;
  int *local_48 [2];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [16];
  uint local_20;
  
  local_20 = DAT_40544354;
  iVar1 = (**(code **)*param_1)(param_1,&UNK_4051647c,&local_4c);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_4c + 0x10))(local_4c,param_3,param_4,param_5);
    (**(code **)(*local_4c + 8))();
    if (-1 < iVar1) {
      FUN_40542538(local_20);
      return true;
    }
  }
  iVar1 = (**(code **)*param_1)(param_1,&DAT_4051631c,local_48);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_48[0] + 0xc))(local_48[0],auStack_30);
    (**(code **)(*local_48[0] + 8))();
    if ((-1 < iVar1) &&
       (HVar2 = CoCreateInstance((IID *)&DAT_4051688c,(LPUNKNOWN)0x0,1,(IID *)&DAT_4051689c,
                                 &local_50), -1 < HVar2)) {
      local_40 = *param_2;
      local_3c = param_2[1];
      local_38 = param_2[2];
      local_34 = param_2[3];
      iVar1 = (**(code **)(*local_50 + 0x18))(local_50,auStack_30,1,&local_40,0,0);
      (**(code **)(*local_50 + 8))();
      FUN_40542538(local_20);
      return iVar1 == 0;
    }
  }
  FUN_40542538(local_20);
  return false;
}



/* 40531484 FUN_40531484 */

/* Boundary evidence: original MIPS .pdata 40531484..405314ff. Semantic name remains unreviewed. */

undefined4 FUN_40531484(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = FUN_405312b8((undefined4 *)*param_1,(undefined4 *)&DAT_405168ac,&DAT_4051643c,1,1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    (**(code **)(*(int *)*param_1 + 8))();
    uVar2 = 0x80004005;
    *param_1 = 0;
  }
  return uVar2;
}



/* 40531500 FUN_40531500 */

/* Boundary evidence: original MIPS .pdata 40531500..4053157f. Semantic name remains unreviewed. */

undefined4 FUN_40531500(int param_1,void *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = memcmp(param_2,&DAT_4051643c,0x10);
  if (iVar1 == 0) {
    *param_4 = *(undefined4 *)(param_1 + 4);
  }
  else {
    FUN_40531104(param_2,param_3,param_4);
  }
  return 0;
}



/* 40531580 FUN_40531580 */

/* Boundary evidence: original MIPS .pdata 40531580..4053162b. Semantic name remains unreviewed. */

undefined4 FUN_40531580(int param_1,void *param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_3 & 0xfffffffc) == 0) {
    iVar2 = memcmp(param_2,&DAT_4051643c,0x10);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 4) = ~param_3 & *(uint *)(param_1 + 4) | param_3 & param_4;
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_405311e0(param_2,param_3);
    }
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



/* 4053162c FUN_4053162c */

/* Boundary evidence: original MIPS .pdata 4053162c..4053164f. Semantic name remains unreviewed. */

void FUN_4053162c(int *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}



/* 40531650 FUN_40531650 */

/* Boundary evidence: original MIPS .pdata 40531650..40531727. Semantic name remains unreviewed. */

int FUN_40531650(int *param_1,int *param_2)

{
  int iVar1;
  int *local_18 [2];
  
  iVar1 = -0x7ff8ffa9;
  if (param_2 != (int *)0x0) {
    local_18[0] = (int *)0x0;
    iVar1 = (**(code **)(*param_2 + 0x10))(param_2,L"CONTENTS",0,0x10,0,local_18);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_18[0] + 0x14))();
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,local_18[0]);
      }
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return iVar1;
}



/* 40531728 FUN_40531728 */

/* Boundary evidence: original MIPS .pdata 40531728..40531803. Semantic name remains unreviewed. */

int FUN_40531728(int *param_1,int *param_2)

{
  int iVar1;
  int *local_18 [2];
  
  iVar1 = -0x7ff8ffa9;
  if (param_2 != (int *)0x0) {
    local_18[0] = (int *)0x0;
    iVar1 = (**(code **)(*param_2 + 0xc))(param_2,L"CONTENTS",0x1011,0,0,local_18);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_18[0] + 0x14))();
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,local_18[0],1);
      }
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return iVar1;
}



/* 40531804 FUN_40531804 */

/* Boundary evidence: original MIPS .pdata 40531804..4053189b. Semantic name remains unreviewed. */

undefined4 FUN_40531804(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 0) {
    *param_1 = PTR_DAT_40544350;
  }
  else {
    puVar1 = (undefined4 *)FUN_4052d4e8((param_2 + 9) * 2);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      *puVar1 = 1;
      *(undefined2 *)((param_2 + 8) * 2 + (int)puVar1) = 0;
      puVar1[1] = param_2;
      puVar1[3] = param_2 << 1;
      puVar1[2] = param_2;
      *param_1 = puVar1 + 4;
    }
  }
  return uVar2;
}



/* 4053189c FUN_4053189c */

/* Boundary evidence: original MIPS .pdata 4053189c..405318fb. Semantic name remains unreviewed. */

void FUN_4053189c(int *param_1)

{
  LONG LVar1;
  
  if ((undefined *)(*param_1 + -0x10) != PTR_DAT_4054434c) {
    LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0x10));
    if (LVar1 == 0) {
      operator_delete((void *)(*param_1 + -0x10));
    }
    *param_1 = (int)PTR_DAT_40544350;
  }
  return;
}



/* 405318fc FUN_405318fc */

/* Boundary evidence: original MIPS .pdata 405318fc..4053196f. Semantic name remains unreviewed. */

void FUN_405318fc(int *param_1)

{
  int iVar1;
  void *_Src;
  
  _Src = (void *)*param_1;
  if (1 < *(int *)((int)_Src + -0x10)) {
    FUN_4053189c(param_1);
    iVar1 = FUN_40531804(param_1,*(int *)((int)_Src + -0xc));
    if (iVar1 != 0) {
      memcpy((void *)*param_1,_Src,(*(int *)((int)_Src + -0xc) + 1) * 2);
    }
  }
  return;
}



/* 40531970 FUN_40531970 */

/* Boundary evidence: original MIPS .pdata 40531970..405319d3. Semantic name remains unreviewed. */

undefined4 FUN_40531970(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((1 < *(int *)(*param_1 + -0x10)) || (*(int *)(*param_1 + -8) < param_2)) {
    FUN_4053189c(param_1);
    uVar1 = FUN_40531804(param_1,param_2);
  }
  return uVar1;
}



/* 405319d4 FUN_405319d4 */

/* Boundary evidence: original MIPS .pdata 405319d4..40531a27. Semantic name remains unreviewed. */

void FUN_405319d4(int *param_1)

{
  LONG LVar1;
  
  if (((undefined *)(*param_1 + -0x10) != PTR_DAT_4054434c) &&
     (LVar1 = InterlockedDecrement((LONG *)(*param_1 + -0x10)), LVar1 == 0)) {
    operator_delete((void *)(*param_1 + -0x10));
  }
  return;
}



/* 40531a28 FUN_40531a28 */

/* Boundary evidence: original MIPS .pdata 40531a28..40531aa7. Semantic name remains unreviewed. */

void FUN_40531a28(int *param_1,int param_2,void *param_3)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = FUN_40531970(param_1,param_2);
  if (iVar1 != 0) {
    _Size = param_2 * 2;
    memcpy((void *)*param_1,param_3,_Size);
    iVar1 = *param_1;
    *(int *)(iVar1 + -0xc) = param_2;
    *(size_t *)(iVar1 + -4) = _Size;
    *(undefined2 *)(_Size + *param_1) = 0;
  }
  return;
}



/* 40531aa8 FUN_40531aa8 */

/* Boundary evidence: original MIPS .pdata 40531aa8..40531afb. Semantic name remains unreviewed. */

int * FUN_40531aa8(int *param_1,wchar_t *param_2)

{
  size_t sVar1;
  
  if (param_2 == (wchar_t *)0x0) {
    sVar1 = 0;
  }
  else {
    sVar1 = wcslen(param_2);
  }
  FUN_40531a28(param_1,sVar1,param_2);
  return param_1;
}



/* 40531afc FUN_40531afc */

/* Boundary evidence: original MIPS .pdata 40531afc..40531bcb. Semantic name remains unreviewed. */

int FUN_40531afc(int *param_1,int param_2)

{
  int iVar1;
  LONG LVar2;
  void *_Src;
  LONG *lpAddend;
  int iVar3;
  
  _Src = (void *)*param_1;
  lpAddend = (LONG *)((int)_Src + -0x10);
  if ((1 < *lpAddend) || (*(int *)((int)_Src + -8) < param_2)) {
    iVar3 = *(int *)((int)_Src + -0xc);
    if (param_2 < iVar3) {
      param_2 = iVar3;
    }
    iVar1 = FUN_40531804(param_1,param_2);
    if (iVar1 != 0) {
      memcpy((void *)*param_1,_Src,iVar3 * 2 + 2);
      iVar1 = *param_1;
      *(int *)(iVar1 + -0xc) = iVar3;
      *(int *)(iVar1 + -4) = iVar3 * 2;
      if ((lpAddend != (LONG *)PTR_DAT_4054434c) &&
         (LVar2 = InterlockedDecrement(lpAddend), LVar2 == 0)) {
        operator_delete(lpAddend);
      }
    }
  }
  return *param_1;
}



/* 40531bcc FUN_40531bcc */

/* Boundary evidence: original MIPS .pdata 40531bcc..40531c33. Semantic name remains unreviewed. */

void FUN_40531bcc(int *param_1,size_t param_2)

{
  int iVar1;
  
  FUN_405318fc(param_1);
  if (param_2 == 0xffffffff) {
    param_2 = wcslen((wchar_t *)*param_1);
  }
  iVar1 = *param_1;
  *(size_t *)(iVar1 + -0xc) = param_2;
  *(size_t *)(iVar1 + -4) = param_2 * 2;
  *(undefined2 *)(param_2 * 2 + *param_1) = 0;
  return;
}



/* 40531c34 FUN_40531c34 */

/* Boundary evidence: original MIPS .pdata 40531c34..40531cc7. Semantic name remains unreviewed. */

undefined4 FUN_40531c34(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  BSTR pOVar2;
  
  sVar1 = wcslen(param_2);
  if (sVar1 < 0x27) {
    StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 0x1c),0x27,param_2);
    *(size_t *)(param_1 + 0x18) = sVar1 << 1;
    *(STRSAFE_LPWSTR *)(param_1 + 4) = (STRSAFE_LPWSTR)(param_1 + 0x1c);
  }
  else {
    pOVar2 = SysAllocString(param_2);
    *(BSTR *)(param_1 + 4) = pOVar2;
    if (pOVar2 == (BSTR)0x0) {
      return 0x8007000e;
    }
  }
  return 0;
}



/* 40531cc8 FUN_40531cc8 */

/* Boundary evidence: original MIPS .pdata 40531cc8..40531d2f. Semantic name remains unreviewed. */

void FUN_40531cc8(int param_1)

{
  if (((((VARIANTARG *)(param_1 + 8))->n1).n2.vt == 0xd) && ((*(uint *)(param_1 + 0x6c) & 2) != 0))
  {
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & 0xfffffffd;
    IUnknown_SetSite(*(IUnknown **)(param_1 + 0x10),(IUnknown *)0x0);
  }
  FUN_4052eac4((VARIANTARG *)(param_1 + 8));
  return;
}



/* 40531d30 FUN_40531d30 */

/* Boundary evidence: original MIPS .pdata 40531d30..40531eb3. Semantic name remains unreviewed. */

void FUN_40531d30(int param_1,VARIANTARG *param_2,undefined4 param_3)

{
  DWORD DVar1;
  int iVar2;
  undefined4 *puVar3;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 0x70) = DVar1;
  FUN_40531cc8(param_1);
  if (((param_2->n1).n2.vt == 0xd) &&
     (puVar3 = *(undefined4 **)((int)&param_2->n1 + 8), puVar3 != (undefined4 *)0x0)) {
    iVar2 = (**(code **)*puVar3)(puVar3,&DAT_405168cc,local_18);
    if (-1 < iVar2) {
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) | 1;
      (**(code **)(*local_18[0] + 8))();
    }
    puVar3 = *(undefined4 **)((int)&param_2->n1 + 8);
    iVar2 = (**(code **)*puVar3)(puVar3,&UNK_405168bc,&local_1c);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_1c + 0x10))(local_1c,&DAT_405162fc,&local_20);
      if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
        iVar2 = SHIsSameObject(local_20,param_3);
        *(uint *)(param_1 + 0x6c) =
             (iVar2 << 1 ^ *(uint *)(param_1 + 0x6c)) & 2 ^ *(uint *)(param_1 + 0x6c);
        (**(code **)(*local_20 + 8))();
      }
      (**(code **)(*local_1c + 8))();
    }
  }
  if (((param_2->n1).n2.vt & 0x4000) == 0) {
    FUN_4052ed8c((VARIANTARG *)(param_1 + 8),param_2);
  }
  else {
    VariantCopyInd((VARIANTARG *)(param_1 + 8),param_2);
  }
  return;
}



/* 40531eb4 FUN_40531eb4 */

/* Boundary evidence: original MIPS .pdata 40531eb4..40531efb. Semantic name remains unreviewed. */

void FUN_40531eb4(int param_1,VARIANTARG *param_2)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 0x70) = DVar1;
  FUN_4052ed8c(param_2,(VARIANTARG *)(param_1 + 8));
  return;
}



/* 40531efc FUN_40531efc */

/* Boundary evidence: original MIPS .pdata 40531efc..40531f9f. Semantic name remains unreviewed. */

HRESULT FUN_40531efc(int param_1,IID *param_2,void **param_3)

{
  HRESULT HVar1;
  int iVar2;
  
  HVar1 = QISearch((void *)(param_1 + -0x40),(LPCQITAB)&PTR_DAT_40515800,param_2,param_3);
  if ((HVar1 < 0) && (iVar2 = memcmp(param_2,&DAT_405164dc,0x10), iVar2 == 0)) {
    *param_3 = (void *)(param_1 + 100);
    (**(code **)(*(int *)(param_1 + -0x2c) + 4))();
    HVar1 = 0;
  }
  return HVar1;
}



/* 40531fa0 FUN_40531fa0 */

/* Boundary evidence: original MIPS .pdata 40531fa0..40531fdf. Semantic name remains unreviewed. */

undefined4 FUN_40531fa0(undefined4 param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  undefined4 uVar2;
  
  pOVar1 = FUN_4052d808(0x2d6);
  *param_2 = pOVar1;
  if (pOVar1 == (BSTR)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40531fe0 FUN_40531fe0 */

/* Boundary evidence: original MIPS .pdata 40531fe0..40532093. Semantic name remains unreviewed. */

undefined4 FUN_40531fe0(int param_1,undefined4 *param_2)

{
  DWORD DVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40544354;
  if (*(int **)(param_1 + 0x94) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x44))();
  }
  DVar1 = GetModuleFileNameW((HMODULE)0x0,aWStack_218,0x104);
  if (DVar1 == 0) {
    *param_2 = 0;
    FUN_40542538(local_10);
    uVar3 = 0x80004005;
  }
  else {
    pOVar2 = SysAllocString(aWStack_218);
    *param_2 = pOVar2;
    if (pOVar2 == (BSTR)0x0) {
      uVar3 = 0x8007000e;
    }
    else {
      uVar3 = 0;
    }
    FUN_40542538(local_10);
  }
  return uVar3;
}



/* 40532094 FUN_40532094 */

/* Boundary evidence: original MIPS .pdata 40532094..4053213b. Semantic name remains unreviewed. */

undefined4 FUN_40532094(undefined4 param_1,undefined4 *param_2)

{
  DWORD DVar1;
  LPWSTR pWVar2;
  BSTR pOVar3;
  undefined4 uVar4;
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40544354;
  DVar1 = GetModuleFileNameW((HMODULE)0x0,aWStack_218,0x104);
  if (DVar1 == 0) {
    *param_2 = 0;
    FUN_40542538(local_10);
    uVar4 = 0x80004005;
  }
  else {
    pWVar2 = PathFindFileNameW(aWStack_218);
    *pWVar2 = L'\0';
    pOVar3 = SysAllocString(aWStack_218);
    *param_2 = pOVar3;
    if (pOVar3 == (BSTR)0x0) {
      uVar4 = 0x8007000e;
    }
    else {
      uVar4 = 0;
    }
    FUN_40542538(local_10);
  }
  return uVar4;
}



/* 4053213c FUN_4053213c */

/* Boundary evidence: original MIPS .pdata 4053213c..4053216b. Semantic name remains unreviewed. */

void FUN_4053213c(int param_1,undefined4 param_2)

{
  (*(code *)**(undefined4 **)(param_1 + -0x14))
            ((undefined4 *)(param_1 + -0x14),&DAT_4051643c,param_2);
  return;
}



/* 4053216c FUN_4053216c */

/* Boundary evidence: original MIPS .pdata 4053216c..4053219b. Semantic name remains unreviewed. */

void FUN_4053216c(int param_1,undefined4 param_2)

{
  (*(code *)**(undefined4 **)(param_1 + -0x14))
            ((undefined4 *)(param_1 + -0x14),&DAT_4051643c,param_2);
  return;
}



/* 4053219c FUN_4053219c */

/* Boundary evidence: original MIPS .pdata 4053219c..4053232b. Semantic name remains unreviewed. */

int FUN_4053219c(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *local_38;
  int *local_34;
  undefined4 local_30 [2];
  _union_2683 local_28;
  
  iVar3 = -0x7fffbffb;
  *param_2 = 0;
  piVar2 = *(int **)(param_1 + 0xc4);
  local_38 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2,&local_38);
    if (iVar3 < 0) {
      local_28.n2.vt = 0;
      iVar3 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x10))
                        (*(int **)(param_1 + 0xd8),&DAT_405163ec,0x13,0,0,&local_28);
      if (-1 < iVar3) {
        if ((local_28.n2.vt == 0xd) && ((undefined4 *)local_28._8_4_ != (undefined4 *)0x0)) {
          iVar3 = (*(code *)**(undefined4 **)local_28._8_4_)(local_28._8_4_,&DAT_405165ec,&local_38)
          ;
        }
        else {
          iVar3 = -0x7fffbffb;
        }
      }
      FUN_4052eac4((VARIANTARG *)&local_28.n2);
    }
    if (local_38 != (int *)0x0) {
      iVar3 = FUN_4052d52c(local_38);
      if (-1 < iVar3) {
        iVar1 = (**(code **)*local_34)(local_34,&DAT_4051675c,local_30);
        if (iVar1 < 0) {
          *param_2 = local_34;
        }
        else {
          *param_2 = local_30[0];
          (**(code **)(*local_34 + 8))();
        }
      }
      (**(code **)(*local_38 + 8))();
    }
  }
  return iVar3;
}



/* 4053232c FUN_4053232c */

/* Boundary evidence: original MIPS .pdata 4053232c..40532393. Semantic name remains unreviewed. */

int FUN_4053232c(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 uVar2;
  int local_10 [2];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x3c))(*(int **)(param_1 + 0x94),local_10);
    if (-1 < iVar1) {
      uVar2 = 0xffff;
      if (local_10[0] == 0) {
        uVar2 = 0;
      }
      *param_2 = uVar2;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40532394 FUN_40532394 */

/* Boundary evidence: original MIPS .pdata 40532394..40532503. Semantic name remains unreviewed. */

int FUN_40532394(int param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  BSTR pOVar5;
  int *piVar6;
  int local_1080 [2];
  wchar_t *local_1078;
  size_t local_1074;
  wchar_t awStack_1070 [2084];
  uint local_28;
  
  local_28 = DAT_40544354;
  FUN_40520168((int *)&local_1078,0x824);
  piVar6 = *(int **)(param_1 + 0xa8);
  if (piVar6 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar6 + 0x58))(piVar6,local_1080);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x28))
                        (*(int **)(param_1 + 0xa8),local_1080[0],local_1078,param_3);
      FUN_40537f64(local_1080[0]);
      if (-1 < iVar2) {
        iVar2 = 0;
        if (((param_3 & 0x8000) == 0) || (BVar3 = PathIsURLW(local_1078), BVar3 != 0))
        goto LAB_405324b4;
        local_1080[1] = 0x824;
        iVar4 = FUN_4052d8ec(local_1078,awStack_1070,(LPDWORD)(local_1080 + 1),(undefined4 *)0x0);
        if (iVar4 != 0) {
          StringCchCopyW(local_1078,local_1074,awStack_1070);
        }
        iVar4 = FUN_4053ad2c(local_1078);
        if (iVar4 == 9) goto LAB_405324b4;
        *local_1078 = L'\0';
      }
    }
    bVar1 = iVar2 == 0;
    iVar2 = 0;
    if (bVar1) goto LAB_405324b4;
  }
  *local_1078 = L'\0';
  iVar2 = 1;
LAB_405324b4:
  pOVar5 = SysAllocString(local_1078);
  *param_2 = pOVar5;
  if (pOVar5 == (BSTR)0x0) {
    iVar2 = -0x7ff8fff2;
  }
  operator_delete(local_1078);
  FUN_40542538(local_28);
  return iVar2;
}



/* 40532504 FUN_40532504 */

/* Boundary evidence: original MIPS .pdata 40532504..40532523. Semantic name remains unreviewed. */

void FUN_40532504(int param_1,undefined4 *param_2)

{
  FUN_40532394(param_1 + -0x14,param_2,0);
  return;
}



/* 40532524 FUN_40532524 */

/* Boundary evidence: original MIPS .pdata 40532524..40532543. Semantic name remains unreviewed. */

void FUN_40532524(int param_1,undefined4 *param_2)

{
  FUN_40532394(param_1 + -0x14,param_2,0x8000);
  return;
}



/* 40532544 FUN_40532544 */

/* Boundary evidence: original MIPS .pdata 40532544..405325b7. Semantic name remains unreviewed. */

undefined4 FUN_40532544(int param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    iVar2 = GetSystemMetrics(0x2e);
    *param_3 = iVar2 * 2 + *param_3;
    iVar2 = GetSystemMetrics(0x2d);
    *param_2 = iVar2 * 2 + *param_2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 405325b8 FUN_405325b8 */

/* Boundary evidence: original MIPS .pdata 405325b8..40532673. Semantic name remains unreviewed. */

undefined4 FUN_405325b8(int param_1,LPCWSTR param_2,VARIANTARG *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if ((param_2 == (LPCWSTR)0x0) || (param_3 == (VARIANTARG *)0x0)) {
    uVar2 = 0x80070057;
  }
  else {
    memset(param_3,0,0x10);
    for (piVar3 = *(int **)(param_1 + 0xa0); piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      iVar1 = StrCmpW(param_2,(LPCWSTR)piVar3[1]);
      if (iVar1 == 0) {
        if (piVar3 != (int *)0x0) {
          uVar2 = FUN_40531eb4((int)piVar3,param_3);
          return uVar2;
        }
        break;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40532674 FUN_40532674 */

/* Boundary evidence: original MIPS .pdata 40532674..405326af. Semantic name remains unreviewed. */

undefined4 FUN_40532674(int param_1)

{
  FUN_4053f730(param_1 + -0x54,(int *)0x0,(int *)0x0);
  FUN_4053f8cc(param_1 + -0x54);
  return 0;
}



/* 405326b0 FUN_405326b0 */

/* Boundary evidence: original MIPS .pdata 405326b0..405327b7. Semantic name remains unreviewed. */

undefined4 FUN_405326b0(int param_1,short *param_2,short *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 != (short *)0x0) {
    if (*param_3 == 0) {
      param_3 = (short *)0x0;
    }
    if ((param_3 != (short *)0x0) && (*param_3 != 0xb)) {
      return 0x80020005;
    }
  }
  if ((*param_2 == 2) && (((uVar1 = param_2[4], uVar1 == 9 || (uVar1 == 10)) || (uVar1 == 0xb)))) {
    iVar3 = 1;
    if (param_3 != (short *)0x0) {
      iVar3 = (int)param_3[4];
    }
    uVar2 = IUnknown_Exec(*(undefined4 *)(param_1 + 0x94),&DAT_405163dc,1,
                          iVar3 << 0x10 | (uint)uVar1,0,0);
  }
  else {
    if (param_3 == (short *)0x0) {
      iVar3 = 1;
    }
    else {
      iVar3 = (int)param_3[4];
    }
    uVar2 = IUnknown_Exec(*(undefined4 *)(param_1 + 0x94),&DAT_405163ec,0x26,iVar3,param_2,0);
  }
  return uVar2;
}



/* 405327b8 FUN_405327b8 */

/* Boundary evidence: original MIPS .pdata 405327b8..4053280b. Semantic name remains unreviewed. */

undefined4 FUN_405327b8(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xd8);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8000ffff;
  }
  else {
    uVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,0,0x17,0,0,0);
  }
  return uVar1;
}



/* 4053280c FUN_4053280c */

/* Boundary evidence: original MIPS .pdata 4053280c..4053285f. Semantic name remains unreviewed. */

void FUN_4053280c(int *param_1)

{
  undefined2 local_18;
  undefined1 auStack_16 [6];
  undefined4 local_10;
  
  memset(auStack_16,0,0xe);
  local_10 = 4;
  local_18 = 3;
  (**(code **)(*param_1 + 0x34))(param_1,&local_18);
  return;
}



/* 40532860 FUN_40532860 */

/* Boundary evidence: original MIPS .pdata 40532860..405328fb. Semantic name remains unreviewed. */

int FUN_40532860(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *local_18 [2];
  
  piVar1 = *(int **)(param_1 + 0xc4);
  iVar2 = -0x7fffbffb;
  if (((piVar1 != (int *)0x0) &&
      (iVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,local_18), -1 < iVar2)) &&
     (local_18[0] != (int *)0x0)) {
    iVar2 = IUnknown_Exec(local_18[0],0,0x16,1,param_2,0);
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar2;
}



/* 405328fc FUN_405328fc */

/* Boundary evidence: original MIPS .pdata 405328fc..40532973. Semantic name remains unreviewed. */

undefined4 FUN_405328fc(int param_1,short *param_2)

{
  undefined4 uVar1;
  short sVar2;
  int local_18 [2];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_18[0] = (int)*param_2;
    sVar2 = -1;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))
                      (*(int **)(param_1 + 0x94),0xffffffff,local_18);
    if (local_18[0] == 0) {
      sVar2 = 0;
    }
    *param_2 = sVar2;
  }
  return uVar1;
}



/* 40532974 FUN_40532974 */

/* Boundary evidence: original MIPS .pdata 40532974..405329f3. Semantic name remains unreviewed. */

undefined4 FUN_40532974(int param_1,short *param_2)

{
  undefined4 uVar1;
  short sVar2;
  int local_10 [2];
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_10[0] = (int)*param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(*(int **)(param_1 + 0x94),1,local_10);
    sVar2 = -1;
    if (local_10[0] == 0) {
      sVar2 = 0;
    }
    *param_2 = sVar2;
  }
  return uVar1;
}



/* 405329f4 FUN_405329f4 */

/* Boundary evidence: original MIPS .pdata 405329f4..40532b13. Semantic name remains unreviewed. */

int FUN_405329f4(int param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  undefined4 *puVar2;
  int iVar3;
  uint local_18;
  int *local_14;
  
  *param_2 = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x94);
  iVar3 = -0x7fffbffb;
  if ((puVar2 != (undefined4 *)0x0) &&
     (iVar3 = (**(code **)*puVar2)(puVar2,&DAT_4051652c,&local_14), -1 < iVar3)) {
    iVar3 = (**(code **)(*local_14 + 0x38))(local_14,1,0x40c,0,0,&local_18);
    if (-1 < iVar3) {
      local_18 = local_18 + 1;
      pOVar1 = SysAllocStringLen((OLECHAR *)0x0,(local_18 & 0xffff) + 1);
      *param_2 = pOVar1;
      if (pOVar1 == (BSTR)0x0) {
        iVar3 = -0x7ff8fff2;
      }
      else {
        iVar3 = (**(code **)(*local_14 + 0x38))(local_14,1,0x40d,0,pOVar1,&local_18);
        if (iVar3 < 0) {
          SysFreeString((BSTR)*param_2);
          *param_2 = 0;
        }
      }
    }
    (**(code **)(*local_14 + 8))();
  }
  return iVar3;
}



/* 40532b14 FUN_40532b14 */

/* Boundary evidence: original MIPS .pdata 40532b14..40532bb3. Semantic name remains unreviewed. */

int FUN_40532b14(int param_1,undefined4 param_2)

{
  int iVar1;
  int *local_18 [2];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x94))
                      (*(undefined4 **)(param_1 + 0x94),&DAT_4051652c,local_18);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_18[0] + 0x38))(local_18[0],1,0x40b,0,param_2,0);
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return iVar1;
}



/* 40532bb4 FUN_40532bb4 */

/* Boundary evidence: original MIPS .pdata 40532bb4..40532c73. Semantic name remains unreviewed. */

int FUN_40532bb4(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int local_18 [2];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    iVar2 = -0x7fffbffb;
  }
  else {
    *param_2 = 0;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(*(int **)(param_1 + 0x94),6,local_18);
    if ((iVar2 < 0) || (local_18[0] == 0)) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(*(int **)(param_1 + 0x94),2,local_18)
      ;
      if ((-1 < iVar1) && (local_18[0] != 0)) {
        *param_2 = 2;
      }
    }
    else {
      *param_2 = 1;
    }
  }
  return iVar2;
}



/* 40532c74 FUN_40532c74 */

/* Boundary evidence: original MIPS .pdata 40532c74..40532cef. Semantic name remains unreviewed. */

undefined4 FUN_40532c74(int param_1,short *param_2)

{
  undefined4 uVar1;
  short sVar2;
  int local_10 [2];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else if (param_2 == (short *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    local_10[0] = (int)*param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(*(int **)(param_1 + 0x94),7,local_10);
    sVar2 = -1;
    if (local_10[0] == 0) {
      sVar2 = 0;
    }
    *param_2 = sVar2;
  }
  return uVar1;
}



/* 40532cf0 FUN_40532cf0 */

/* Boundary evidence: original MIPS .pdata 40532cf0..40532d57. Semantic name remains unreviewed. */

undefined4 FUN_40532cf0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  piVar2 = *(int **)(param_1 + 0xd8);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8000ffff;
  }
  else {
    local_c = *param_3;
    local_10 = param_2;
    uVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,0,1,&local_10,0);
    *param_3 = local_c;
  }
  return uVar1;
}



/* 40532d58 FUN_40532d58 */

/* Boundary evidence: original MIPS .pdata 40532d58..40532daf. Semantic name remains unreviewed. */

undefined4
FUN_40532d58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0xd8);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8000ffff;
  }
  else {
    uVar1 = (**(code **)(*piVar2 + 0x10))(piVar2,0,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}



/* 40532de8 FUN_40532de8 */

/* Boundary evidence: original MIPS .pdata 40532de8..40532e37. Semantic name remains unreviewed. */

void FUN_40532de8(int *param_1,undefined4 param_2)

{
  undefined2 local_18 [4];
  undefined4 local_10;
  
  if (param_1 != (int *)0x0) {
    local_18[0] = 3;
    local_10 = param_2;
    (**(code **)(*param_1 + 0x10))(param_1,&DAT_405163ec,0x11,0,local_18,0);
  }
  return;
}



/* 40532e38 FUN_40532e38 */

/* Boundary evidence: original MIPS .pdata 40532e38..40532eb3. Semantic name remains unreviewed. */

undefined4 FUN_40532e38(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xa8);
  if ((int)(uVar2 << 0x1f) < 0) {
    if (param_2 != 0) {
      return 0;
    }
    if ((int)(uVar2 << 0x1f) < 0) {
      uVar1 = 0;
      goto LAB_40532e88;
    }
  }
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = 1;
LAB_40532e88:
  *(uint *)(param_1 + 0xa8) = (uVar2 ^ uVar1) & 1 ^ uVar2;
  FUN_40532de8(*(int **)(param_1 + 0xd8),0xffffea83);
  return 0;
}



/* 40532eec FUN_40532eec */

/* Boundary evidence: original MIPS .pdata 40532eec..40532f6b. Semantic name remains unreviewed. */

undefined4 FUN_40532eec(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xa8);
  if ((int)(uVar2 << 0x1e) < 0) {
    if (param_2 != 0) {
      return 0;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      iVar1 = 0;
      goto LAB_40532f3c;
    }
  }
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = 1;
LAB_40532f3c:
  *(uint *)(param_1 + 0xa8) = (iVar1 << 1 ^ uVar2) & 2 ^ uVar2;
  FUN_40532de8(*(int **)(param_1 + 0xd8),0xffffea82);
  return 0;
}



/* 40532fa4 FUN_40532fa4 */

/* Boundary evidence: original MIPS .pdata 40532fa4..40533003. Semantic name remains unreviewed. */

undefined4 FUN_40532fa4(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    uVar1 = 0x80004005;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x94);
    if (piVar2 == (int *)0x0) {
      uVar1 = 1;
    }
    else {
      *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x10;
      (**(code **)(*piVar2 + 0x80))(piVar2,1,2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40533004 FUN_40533004 */

/* Boundary evidence: original MIPS .pdata 40533004..4053307f. Semantic name remains unreviewed. */

undefined4 FUN_40533004(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined2 uVar3;
  uint local_10 [2];
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x94);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80004005;
    }
    else {
      (**(code **)(*piVar2 + 0x50))(piVar2,local_10);
      uVar3 = 0xffff;
      if ((local_10[0] & 2) == 0) {
        uVar3 = 0;
      }
      *param_2 = uVar3;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40533080 FUN_40533080 */

/* Boundary evidence: original MIPS .pdata 40533080..405330cb. Semantic name remains unreviewed. */

undefined4 FUN_40533080(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
    if (param_2 == 0) {
      uVar1 = 0;
    }
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),uVar1,2);
    uVar1 = 0;
  }
  return uVar1;
}



/* 405330cc FUN_405330cc */

/* Boundary evidence: original MIPS .pdata 405330cc..40533147. Semantic name remains unreviewed. */

undefined4 FUN_405330cc(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint local_10 [2];
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x50))(*(int **)(param_1 + 0x94),local_10);
    uVar2 = 0xffff;
    if ((local_10[0] & 1) == 0) {
      uVar2 = 0;
    }
    *param_2 = uVar2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40533148 FUN_40533148 */

/* Boundary evidence: original MIPS .pdata 40533148..40533197. Semantic name remains unreviewed. */

undefined4 FUN_40533148(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),param_2 != 0,1);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40533198 FUN_40533198 */

/* Boundary evidence: original MIPS .pdata 40533198..40533217. Semantic name remains unreviewed. */

undefined4 FUN_40533198(int param_1,short *param_2)

{
  undefined4 uVar1;
  short sVar2;
  int local_10 [2];
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    local_10[0] = (int)*param_2;
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x24))(*(int **)(param_1 + 0x94),9,local_10);
    sVar2 = -1;
    if (local_10[0] == 0) {
      sVar2 = 0;
    }
    *param_2 = sVar2;
  }
  return uVar1;
}



/* 40533218 FUN_40533218 */

/* Boundary evidence: original MIPS .pdata 40533218..4053328f. Semantic name remains unreviewed. */

undefined4 FUN_40533218(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint local_10 [2];
  
  if (param_2 == (undefined2 *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x50))(*(int **)(param_1 + 0x94),local_10);
    uVar2 = 0xffff;
    if ((local_10[0] & 0x200) == 0) {
      uVar2 = 0;
    }
    *param_2 = uVar2;
  }
  return uVar1;
}



/* 40533290 FUN_40533290 */

/* Boundary evidence: original MIPS .pdata 40533290..405332db. Semantic name remains unreviewed. */

undefined4 FUN_40533290(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = 0x600;
    if (param_2 == 0) {
      uVar1 = 0;
    }
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),uVar1,0x600);
  }
  return uVar1;
}



/* 405332dc FUN_405332dc */

/* Boundary evidence: original MIPS .pdata 405332dc..4053334b. Semantic name remains unreviewed. */

void FUN_405332dc(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_10 [2];
  
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&UNK_40512e34,local_10), -1 < iVar1)) {
    (**(code **)(*local_10[0] + 0xc))(local_10[0],0,param_2);
    (**(code **)(*local_10[0] + 8))();
  }
  return;
}



/* 4053334c FUN_4053334c */

/* Boundary evidence: original MIPS .pdata 4053334c..40533373. Semantic name remains unreviewed. */

undefined4 FUN_4053334c(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_1 + 0x68) = param_2;
  if (param_3 != 0) {
    FUN_405332dc(*(undefined4 **)(param_1 + 0x88),param_2);
  }
  return 0;
}



/* 40533374 FUN_40533374 */

/* Boundary evidence: original MIPS .pdata 40533374..40533443. Semantic name remains unreviewed. */

undefined4 FUN_40533374(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  _union_2683 local_20;
  
  DVar2 = GetTickCount();
  local_20.n2.vt = 0;
  memset(&local_20.n2.wReserved1,0,0xe);
  if (300000 < DVar2 - *(int *)(param_1 + 0xb4)) {
    piVar4 = (int *)*(int *)(param_1 + 100);
    while (piVar1 = piVar4, piVar1 != (int *)0x0) {
      piVar4 = (int *)*piVar1;
      if (((piVar1[0x1b] & 1U) != 0) && (600000 < DVar2 - piVar1[0x1c])) {
        iVar3 = param_1 + -0x3c;
        if (param_1 == 0x50) {
          iVar3 = 0;
        }
        FUN_40531d30((int)piVar1,(VARIANTARG *)&local_20.n2,iVar3);
      }
    }
    *(DWORD *)(param_1 + 0xb4) = DVar2;
  }
  return 0;
}



/* 40533464 FUN_40533464 */

/* Boundary evidence: original MIPS .pdata 40533464..405334eb. Semantic name remains unreviewed. */

undefined4 FUN_40533464(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_10;
  undefined4 local_c;
  
  local_c = *(undefined4 *)(param_1 + 0xa4);
  puVar2 = *(undefined4 **)(param_1 + 0xc4);
  if ((puVar2 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*puVar2)(puVar2,&UNK_40512e34,&local_10), -1 < iVar1)) {
    (**(code **)(*local_10 + 0x10))(local_10,&local_c);
    (**(code **)(*local_10 + 8))();
  }
  *param_2 = local_c;
  return 0;
}



/* 405334fc FUN_405334fc */

/* Boundary evidence: original MIPS .pdata 405334fc..40533607. Semantic name remains unreviewed. */

int FUN_405334fc(int param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  int *piVar2;
  int iVar3;
  OLECHAR *local_20;
  int *local_1c;
  int *local_18 [2];
  
  *param_2 = 0;
  piVar2 = *(int **)(param_1 + 0xc4);
  iVar3 = -0x7fffbffb;
  if (((piVar2 != (int *)0x0) &&
      (iVar3 = (**(code **)(*piVar2 + 0x3c))(piVar2,local_18), -1 < iVar3)) &&
     (local_18[0] != (int *)0x0)) {
    iVar3 = FUN_4052d52c(local_18[0]);
    if (-1 < iVar3) {
      iVar3 = (**(code **)(*local_1c + 0x40))(local_1c,1,&local_20);
      if ((-1 < iVar3) && (local_20 != (OLECHAR *)0x0)) {
        pOVar1 = SysAllocString(local_20);
        *param_2 = pOVar1;
        if (pOVar1 == (BSTR)0x0) {
          iVar3 = -0x7ff8fff2;
        }
        CoTaskMemFree(local_20);
      }
      (**(code **)(*local_1c + 8))();
    }
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar3;
}



/* 40533614 FUN_40533614 */

/* Boundary evidence: original MIPS .pdata 40533614..4053369b. Semantic name remains unreviewed. */

int FUN_40533614(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *local_10 [2];
  
  piVar3 = (int *)(param_1 + 0xac);
  if (((*piVar3 == 0) && (puVar2 = *(undefined4 **)(param_1 + 0xa8), puVar2 != (undefined4 *)0x0))
     && (iVar1 = (**(code **)*puVar2)(puVar2,&UNK_4051637c,local_10), -1 < iVar1)) {
    (**(code **)(*local_10[0] + 0xc))(local_10[0],piVar3);
    (**(code **)(*local_10[0] + 8))();
  }
  return *piVar3;
}



/* 4053369c FUN_4053369c */

/* Boundary evidence: original MIPS .pdata 4053369c..40533767. Semantic name remains unreviewed. */

int FUN_4053369c(int param_1,int param_2,void *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_3,&DAT_405162bc,0x10);
  if ((iVar1 == 0) || ((param_2 != 0 && (iVar1 = memcmp(param_3,&DAT_4051643c,0x10), iVar1 == 0))))
  {
    iVar1 = param_1 + 0x5c;
  }
  else {
    iVar1 = memcmp(param_3,&DAT_405164fc,0x10);
    if (iVar1 == 0) {
      iVar1 = param_1 + 0x44;
    }
    else {
      iVar1 = memcmp(param_3,&DAT_405164ec,0x10);
      if (iVar1 == 0) {
        iVar1 = param_1 + 0x74;
      }
      else {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 40533768 FUN_40533768 */

/* Boundary evidence: original MIPS .pdata 40533768..4053379b. Semantic name remains unreviewed. */

void FUN_40533768(int param_1,undefined4 *param_2)

{
  FUN_40538514(param_2,3,param_1 + 0x5c,param_1 + 0x44);
  return;
}



/* 4053379c FUN_4053379c */

/* Boundary evidence: original MIPS .pdata 4053379c..405338b3. Semantic name remains unreviewed. */

undefined4 FUN_4053379c(IUnknown *param_1,undefined4 *param_2,undefined4 *param_3)

{
  HRESULT HVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_20;
  int *local_1c;
  
  uVar3 = 0x80004005;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if ((param_1 != (IUnknown *)0x0) &&
     (HVar1 = IUnknown_QueryService(param_1,(GUID *)&DAT_40512c24,(IID *)&DAT_4051642c,&local_1c),
     -1 < HVar1)) {
    iVar2 = (**(code **)(*local_1c + 0xc))(local_1c,&DAT_4051645c,&DAT_405162cc,&local_20);
    if (-1 < iVar2) {
      iVar2 = SHIsSameObject(param_1,local_20);
      if (iVar2 == 0) {
        uVar3 = FUN_40523da4(local_20,param_2,param_3);
      }
      (**(code **)(*local_20 + 8))();
    }
    (**(code **)(*local_1c + 8))();
  }
  return uVar3;
}



/* 405338b4 FUN_405338b4 */

/* Boundary evidence: original MIPS .pdata 405338b4..4053390f. Semantic name remains unreviewed. */

void FUN_405338b4(BSTR param_1,BSTR param_2,VARIANTARG *param_3)

{
  if (param_1 != (BSTR)0x0) {
    SysFreeString(param_1);
  }
  if (param_2 != (BSTR)0x0) {
    SysFreeString(param_2);
  }
  if (*(int *)((int)&param_3->n1 + 8) != 0) {
    FUN_4052eac4(param_3);
  }
  return;
}



/* 40533910 FUN_40533910 */

/* Boundary evidence: original MIPS .pdata 40533910..40533953. Semantic name remains unreviewed. */

void FUN_40533910(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_18 [16];
  
  IUnknown_CPContainerInvokeParam(param_1,&DAT_405162bc,param_2,auStack_18,1,0xb,param_3);
  return;
}



/* 40533954 FUN_40533954 */

/* Boundary evidence: original MIPS .pdata 40533954..40533a87. Semantic name remains unreviewed. */

int FUN_40533954(int param_1,int param_2,void *param_3,undefined4 param_4,ushort param_5,
                undefined4 param_6,undefined2 *param_7)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  short local_18 [2];
  undefined4 local_14;
  
  local_18[0] = 0;
  iVar4 = 0;
  iVar1 = memcmp(&DAT_4051674c,param_3,0x10);
  if (iVar1 != 0) {
    return -0x7ffdffff;
  }
  if ((param_5 & 2) == 0) {
LAB_405339b4:
    iVar4 = -0x7fffbffb;
  }
  else {
    if (param_2 == -0x157e) {
      pcVar3 = *(code **)(*(int *)(param_1 + -8) + 0xec);
    }
    else {
      if (param_2 != -0x157d) {
        if ((param_2 == -0x2d6) && (piVar2 = *(int **)(param_1 + 0x8c), piVar2 != (int *)0x0)) {
          iVar1 = (**(code **)(*piVar2 + 0x7c))(piVar2,&local_14);
          if (iVar1 < 0) {
            return iVar1;
          }
          *param_7 = 3;
          *(undefined4 *)(param_7 + 4) = local_14;
          return iVar1;
        }
        goto LAB_405339b4;
      }
      pcVar3 = *(code **)(*(int *)(param_1 + -8) + 0xe4);
    }
    (*pcVar3)(param_1 + -8,local_18);
    *param_7 = 0xb;
    param_7[4] = (ushort)(local_18[0] != 0);
  }
  return iVar4;
}



/* 40533ab0 FUN_40533ab0 */

/* Boundary evidence: original MIPS .pdata 40533ab0..40533b8f. Semantic name remains unreviewed. */

undefined4 FUN_40533ab0(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  HWND hWnd;
  undefined3 extraout_var;
  int iVar3;
  short local_18 [4];
  
  if ((param_2 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x90) + -1;
    *(int *)(param_1 + 0x90) = iVar3;
    if (((iVar3 == 0) || ((iVar3 == 1 && ((*(uint *)(param_1 + 0xe0) & 8) != 0)))) &&
       ((param_4 != 0 &&
        (((((**(code **)(*(int *)(param_1 + -0xc) + 0xa0))((int *)(param_1 + -0xc),local_18),
           local_18[0] == 0 && (hWnd = (HWND)FUN_40533614(param_1 + -0x20), hWnd != (HWND)0x0)) &&
          (*(int *)(param_1 + 0xbc) == *(int *)(param_1 + 0xb8))) &&
         (bVar1 = FUN_4052e26c(hWnd,L"Shell Embedding"), CONCAT31(extraout_var,bVar1) == 0)))))) {
      PostMessageW(hWnd,0x10,0,0);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x90);
  }
  return uVar2;
}



/* 40533b90 FUN_40533b90 */

/* Boundary evidence: original MIPS .pdata 40533b90..40533bd3. Semantic name remains unreviewed. */

undefined4 FUN_40533b90(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0xd8) == (int *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x2c))();
  }
  return uVar1;
}



/* 40533bd4 FUN_40533bd4 */

/* Boundary evidence: original MIPS .pdata 40533bd4..40533c4f. Semantic name remains unreviewed. */

SAFEARRAY * FUN_40533bd4(void *param_1,ULONG param_2)

{
  SAFEARRAY *pSVar1;
  
  if ((param_1 == (void *)0x0) || (param_2 == 0)) {
    pSVar1 = (SAFEARRAY *)0x0;
  }
  else {
    pSVar1 = SafeArrayCreateVector(0x11,0,param_2);
    if (pSVar1 != (SAFEARRAY *)0x0) {
      memcpy(pSVar1->pvData,param_1,param_2);
    }
  }
  return pSVar1;
}



/* 40533c50 FUN_40533c50 */

/* Boundary evidence: original MIPS .pdata 40533c50..40533d13. Semantic name remains unreviewed. */

undefined4 FUN_40533c50(undefined4 *param_1,wchar_t *param_2,wchar_t *param_3)

{
  size_t sVar1;
  BSTR pszDest;
  size_t sVar2;
  
  sVar2 = 0;
  if (param_2 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_2);
  }
  if (param_3 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_3);
    sVar2 = sVar1 + sVar2;
  }
  if (sVar2 != 0) {
    pszDest = SysAllocStringByteLen((LPCSTR)0x0,(sVar2 + 1) * 2);
    *param_1 = pszDest;
    if (pszDest != (BSTR)0x0) {
      StringCchCopyW(pszDest,sVar2 + 1,param_2);
      if (param_3 != (wchar_t *)0x0) {
        StringCchCatW((STRSAFE_LPWSTR)*param_1,sVar2 + 1,param_3);
      }
      return 0;
    }
  }
  return 0x80004005;
}



/* 40533d14 FUN_40533d14 */

/* Boundary evidence: original MIPS .pdata 40533d14..40533e5f. Semantic name remains unreviewed. */

undefined4
FUN_40533d14(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *local_d0 [2];
  undefined4 local_c8;
  undefined1 auStack_c4 [12];
  undefined1 auStack_b8 [160];
  
  local_d0[0] = (int *)0x0;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&DAT_4051652c,local_d0), iVar1 == 0)) {
    (**(code **)(*local_d0[0] + 0x24))(local_d0[0],0);
  }
  if (param_6 == 0) {
    IConnectionPoint_SimpleInvoke(param_2,param_5,0);
  }
  else {
    if (9 < param_6) {
      uVar2 = 0x8000ffff;
      goto LAB_40533e14;
    }
    local_c8 = 0;
    memset(auStack_c4,0,0xc);
    iVar1 = SHPackDispParamsV(&local_c8,auStack_b8,param_6,&stack0x00000018);
    if (iVar1 == 0) {
      IConnectionPoint_InvokeWithCancel(param_2,param_5,&local_c8,param_3,param_4);
    }
  }
  uVar2 = 0;
LAB_40533e14:
  if (local_d0[0] != (int *)0x0) {
    (**(code **)(*local_d0[0] + 0x24))(local_d0[0],1);
    IUnknown_AtomicRelease(local_d0);
  }
  return uVar2;
}



/* 40533e60 FUN_40533e60 */

/* Boundary evidence: original MIPS .pdata 40533e60..40533eab. Semantic name remains unreviewed. */

void FUN_40533e60(int *param_1)

{
  if (*(int *)(*param_1 + -0xc) != 0) {
    if (*(int *)(*param_1 + -0x10) < 0) {
      FUN_40531aa8(param_1,L"");
    }
    else {
      FUN_4053189c(param_1);
    }
  }
  return;
}



/* 40533eac FUN_40533eac */

/* Boundary evidence: original MIPS .pdata 40533eac..40533eeb. Semantic name remains unreviewed. */

undefined4 FUN_40533eac(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40533614(param_1 + -0x14);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40533eec FUN_40533eec */

/* Boundary evidence: original MIPS .pdata 40533eec..40533f3f. Semantic name remains unreviewed. */

bool FUN_40533eec(int param_1,LONG *param_2)

{
  HWND hWnd;
  tagRECT local_18;
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd == (HWND)0x0) {
    *param_2 = 0;
  }
  else {
    GetWindowRect(hWnd,&local_18);
    *param_2 = local_18.left;
  }
  return hWnd == (HWND)0x0;
}



/* 40533f40 FUN_40533f40 */

/* Boundary evidence: original MIPS .pdata 40533f40..40533fd3. Semantic name remains unreviewed. */

undefined4 FUN_40533f40(int param_1,int param_2)

{
  HWND hWnd;
  int *piVar1;
  tagRECT tStack_20;
  
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1,0x100,0x100);
  }
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    GetWindowRect(hWnd,&tStack_20);
    SetWindowPos(hWnd,(HWND)0x0,param_2,tStack_20.top,0,0,0x15);
  }
  return 0;
}



/* 40533fd4 FUN_40533fd4 */

/* Boundary evidence: original MIPS .pdata 40533fd4..40534027. Semantic name remains unreviewed. */

bool FUN_40533fd4(int param_1,LONG *param_2)

{
  HWND hWnd;
  tagRECT tStack_18;
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd == (HWND)0x0) {
    *param_2 = 0;
  }
  else {
    GetWindowRect(hWnd,&tStack_18);
    *param_2 = tStack_18.top;
  }
  return hWnd == (HWND)0x0;
}



/* 40534028 FUN_40534028 */

/* Boundary evidence: original MIPS .pdata 40534028..405340bb. Semantic name remains unreviewed. */

undefined4 FUN_40534028(int param_1,int param_2)

{
  HWND hWnd;
  int *piVar1;
  tagRECT local_20;
  
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1,0x100,0x100);
  }
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    GetWindowRect(hWnd,&local_20);
    SetWindowPos(hWnd,(HWND)0x0,local_20.left,param_2,0,0,0x15);
  }
  return 0;
}



/* 405340bc FUN_405340bc */

/* Boundary evidence: original MIPS .pdata 405340bc..40534117. Semantic name remains unreviewed. */

bool FUN_405340bc(int param_1,int *param_2)

{
  HWND hWnd;
  tagRECT local_18;
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd == (HWND)0x0) {
    *param_2 = 0;
  }
  else {
    GetWindowRect(hWnd,&local_18);
    *param_2 = local_18.right - local_18.left;
  }
  return hWnd == (HWND)0x0;
}



/* 40534118 FUN_40534118 */

/* Boundary evidence: original MIPS .pdata 40534118..405341b7. Semantic name remains unreviewed. */

undefined4 FUN_40534118(int param_1,int param_2)

{
  HWND hWnd;
  int *piVar1;
  tagRECT tStack_20;
  
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1,0x100,0x100);
  }
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    GetWindowRect(hWnd,&tStack_20);
    SetWindowPos(hWnd,(HWND)0x0,0,0,param_2,tStack_20.bottom - tStack_20.top,0x16);
  }
  return 0;
}



/* 405341b8 FUN_405341b8 */

/* Boundary evidence: original MIPS .pdata 405341b8..40534213. Semantic name remains unreviewed. */

bool FUN_405341b8(int param_1,int *param_2)

{
  HWND hWnd;
  tagRECT tStack_18;
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd == (HWND)0x0) {
    *param_2 = 0;
  }
  else {
    GetWindowRect(hWnd,&tStack_18);
    *param_2 = tStack_18.bottom - tStack_18.top;
  }
  return hWnd == (HWND)0x0;
}



/* 40534214 FUN_40534214 */

/* Boundary evidence: original MIPS .pdata 40534214..405342b3. Semantic name remains unreviewed. */

undefined4 FUN_40534214(int param_1,int param_2)

{
  HWND hWnd;
  int *piVar1;
  tagRECT local_20;
  
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x4c))(piVar1,0x100,0x100);
  }
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    GetWindowRect(hWnd,&local_20);
    SetWindowPos(hWnd,(HWND)0x0,0,0,local_20.right - local_20.left,param_2,0x16);
  }
  return 0;
}



/* 405342b4 FUN_405342b4 */

/* Boundary evidence: original MIPS .pdata 405342b4..405342ff. Semantic name remains unreviewed. */

undefined4 FUN_405342b4(int param_1,undefined2 *param_2)

{
  HWND hWnd;
  BOOL BVar1;
  undefined2 uVar2;
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    BVar1 = IsWindowVisible(hWnd);
    uVar2 = 0xffff;
    if (BVar1 != 0) goto LAB_405342e8;
  }
  uVar2 = 0;
LAB_405342e8:
  *param_2 = uVar2;
  return 0;
}



/* 40534300 FUN_40534300 */

/* Boundary evidence: original MIPS .pdata 40534300..405343a3. Semantic name remains unreviewed. */

undefined4 FUN_40534300(int param_1,int param_2)

{
  HWND hWnd;
  int nCmdShow;
  undefined1 auStack_20 [16];
  
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    nCmdShow = 5;
    if (param_2 == 0) {
      nCmdShow = 0;
    }
    ShowWindow(hWnd,nCmdShow);
    if (param_2 != 0) {
      SetForegroundWindow(hWnd);
    }
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0xfe,auStack_20,1,0xb,param_2);
  }
  return 0;
}



/* 405343a4 FUN_405343a4 */

/* Boundary evidence: original MIPS .pdata 405343a4..405343c3. Semantic name remains unreviewed. */

undefined4 FUN_405343a4(int param_1)

{
  FUN_40533614(param_1 + -0x58);
  return 0;
}



/* 405343c4 FUN_405343c4 */

/* Boundary evidence: original MIPS .pdata 405343c4..405343e3. Semantic name remains unreviewed. */

undefined4 FUN_405343c4(int param_1)

{
  FUN_40533614(param_1 + -0x58);
  return 0;
}



/* 405343e4 FUN_405343e4 */

/* Boundary evidence: original MIPS .pdata 405343e4..40534403. Semantic name remains unreviewed. */

undefined4 FUN_405343e4(int param_1)

{
  FUN_40533614(param_1 + -0x58);
  return 0;
}



/* 40534404 FUN_40534404 */

/* Boundary evidence: original MIPS .pdata 40534404..40534423. Semantic name remains unreviewed. */

undefined4 FUN_40534404(int param_1)

{
  FUN_40533614(param_1 + -0x58);
  return 0;
}



/* 40534424 FUN_40534424 */

/* Boundary evidence: original MIPS .pdata 40534424..4053446b. Semantic name remains unreviewed. */

undefined4 FUN_40534424(int param_1)

{
  HWND hWnd;
  
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) | 0x20;
  hWnd = (HWND)FUN_40533614(param_1 + -0x14);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x10,0,0);
  }
  return 0;
}



/* 4053446c FUN_4053446c */

/* Boundary evidence: original MIPS .pdata 4053446c..405344d3. Semantic name remains unreviewed. */

void * FUN_4053446c(void *param_1,uint param_2)

{
  BSTR bstrString;
  
  bstrString = *(BSTR *)((int)param_1 + 4);
  if ((bstrString != (BSTR)0x0) && (bstrString != (BSTR)((int)param_1 + 0x1c))) {
    SysFreeString(bstrString);
  }
  FUN_40531cc8((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405344d4 FUN_405344d4 */

/* Boundary evidence: original MIPS .pdata 405344d4..40534d2f. Semantic name remains unreviewed. */

ULONG FUN_405344d4(IUnknown *param_1,LPCWSTR param_2,short *param_3,short *param_4,ushort *param_5,
                  short *param_6,IBindCtx *param_7,wchar_t *param_8)

{
  bool bVar1;
  bool bVar2;
  undefined *puVar3;
  bool bVar4;
  ULONG UVar5;
  int iVar6;
  HRESULT HVar7;
  UINT UVar8;
  undefined3 extraout_var;
  LPCWSTR _Str;
  size_t sVar9;
  IUnknownVtbl *pIVar10;
  ushort uVar11;
  uint uVar12;
  wchar_t *lpStr1;
  uint uVar13;
  uint uVar14;
  SAFEARRAY *psa;
  undefined4 uVar15;
  void **ppvVar16;
  LONG local_10d8;
  short *local_10d4;
  void *local_10d0;
  LPBC local_10cc;
  int *local_10c8;
  LPWSTR local_10c4;
  void *local_10c0;
  LPCWSTR local_10bc;
  wchar_t *local_10b8;
  int *local_10b4;
  undefined4 local_10b0;
  int local_10ac;
  IBindCtx *local_10a8;
  int local_10a4;
  int *local_10a0;
  short *local_109c;
  undefined *local_1098 [2];
  _union_2683 local_1090;
  WCHAR local_1080;
  short local_107e;
  undefined1 auStack_107c [4172];
  uint local_30;
  
  local_30 = DAT_40544354;
  local_10a8 = param_7;
  local_10b8 = param_8;
  local_10bc = param_2;
  local_109c = param_3;
  if (param_1[0x2a].lpVtbl == (IUnknownVtbl *)0x0) {
    FUN_40542538(DAT_40544354);
    return 0x80004005;
  }
  if (param_2 == (LPCWSTR)0x0) {
    pIVar10 = param_1[0x36].lpVtbl;
    if (pIVar10 == (IUnknownVtbl *)0x0) {
      UVar5 = 0x80004005;
    }
    else {
      UVar5 = (**(code **)(pIVar10->QueryInterface + 0x2c))(pIVar10,0xfffffffe,0);
    }
    goto LAB_40534cf4;
  }
  iVar6 = StrCmpIW(param_2,L"x-$home$://null");
  if (iVar6 == 0) {
    FUN_40542538(local_30);
    return 1;
  }
  local_10d4 = (short *)0x0;
  local_10cc = (IBindCtx *)0x0;
  uVar13 = 0;
  local_10d8 = 0;
  uVar12 = 0;
  local_10a4 = 0;
  uVar14 = 0;
  local_10d0 = (void *)0x0;
  psa = (SAFEARRAY *)0x0;
  local_10b0 = 0;
  lpStr1 = (BSTR)0x0;
  local_10c0 = (void *)0x0;
  local_10c4 = (LPWSTR)0x0;
  if (param_4 == (short *)0x0) {
LAB_4053481c:
    UVar5 = FUN_40540274((int)param_1,0,local_10bc,local_10b8,(int *)&local_10d4);
    if (-1 < (int)UVar5) {
LAB_40534848:
      bVar2 = false;
      bVar1 = false;
      iVar6 = local_10a4;
      if (param_6 != (short *)0x0) {
        if (*param_6 == 0x4008) {
          iVar6 = **(int **)(param_6 + 4);
        }
        else if (*param_6 == 8) {
          iVar6 = *(int *)(param_6 + 4);
        }
      }
      if ((param_5 != (ushort *)0x0) && ((*param_5 & 0x2000) != 0)) {
        if ((*param_5 & 0x4000) == 0) {
          psa = *(SAFEARRAY **)(param_5 + 4);
        }
        else {
          psa = (SAFEARRAY *)**(undefined4 **)(param_5 + 4);
        }
        if ((psa != (SAFEARRAY *)0x0) && (HVar7 = SafeArrayAccessData(psa,&local_10d0), -1 < HVar7))
        {
          local_10d8 = 0;
          SafeArrayGetUBound(psa,1,&local_10d8);
          local_10d8 = local_10d8 + 1;
          UVar8 = SafeArrayGetElemsize(psa);
          if (UVar8 * local_10d8 == 0) {
            local_10d0 = (void *)0x0;
          }
        }
      }
      if (local_109c != (short *)0x0) {
        if (*local_109c == 3) {
          uVar13 = *(uint *)(local_109c + 4);
        }
        else if (*local_109c == 2) {
          uVar13 = (uint)local_109c[4];
        }
        bVar1 = (uVar13 & 0x200) != 0;
        bVar2 = (uVar13 & 0x400) != 0;
        if ((uVar13 & 1) != 0) {
          uVar12 = 2;
        }
        if ((uVar13 & 2) != 0) {
          uVar12 = uVar12 | 0x20;
        }
        if ((uVar13 & 4) != 0) {
          uVar14 = 0x2200;
        }
        if ((uVar13 & 8) != 0) {
          uVar14 = uVar14 | 0x20;
        }
        if ((uVar13 & 0x40) != 0) {
          uVar14 = uVar14 | 0x400;
        }
        if ((uVar13 & 0x80) != 0) {
          uVar14 = uVar14 | 0x800000;
        }
        bVar4 = FUN_4051fdcc(local_10d4,1);
        if ((CONCAT31(extraout_var,bVar4) != 0) && ((uVar13 & 0x10) != 0)) {
          uVar12 = uVar12 | 0x20000000;
        }
      }
      if ((((iVar6 == 0) && (local_10d0 == (void *)0x0)) && (uVar12 == 0)) && (uVar14 == 0)) {
        if (bVar1) {
          uVar13 = 0x2000001;
        }
        else {
          uVar13 = 1;
        }
        if (bVar2) {
          uVar13 = uVar13 | 0x10000000;
        }
        if (local_10a8 != (IBindCtx *)0x0) {
          FUN_4053f730((int)param_1,(int *)local_10a8,(int *)0x0);
        }
        pIVar10 = param_1[0x36].lpVtbl;
        if (pIVar10 == (IUnknownVtbl *)0x0) {
          UVar5 = 0x80004005;
        }
        else {
          UVar5 = (**(code **)(pIVar10->QueryInterface + 0x2c))(pIVar10,local_10d4,uVar13);
        }
      }
      else {
        uVar11 = 0xffff;
        if (((uint)param_1[0x2f].lpVtbl & 2) == 0) {
          uVar11 = 0;
        }
        ppvVar16 = &local_10c0;
        uVar15 = 1;
        uVar13 = (uint)uVar11;
        UVar5 = FUN_40539448();
        if (-1 < (int)UVar5) {
          UVar5 = (**(code **)((param_1[0x2a].lpVtbl)->QueryInterface + 0x28))
                            (param_1[0x2a].lpVtbl,local_10d4,&local_1080,0x8000,uVar13,uVar15,uVar14
                             ,ppvVar16);
          if ((int)UVar5 < 0) {
            local_10b8 = (wchar_t *)0x827;
            HVar7 = PathCreateFromUrlW(local_10bc,&local_1080,(LPDWORD)&local_10b8,0);
            if (((-1 < HVar7) && (local_1080 == L'\\')) && (local_107e == 0x5c)) {
              UVar5 = (**(code **)((param_1[0x2a].lpVtbl)->QueryInterface + 0x28))
                                (param_1[0x2a].lpVtbl,local_10d4,auStack_107c,0x4000);
            }
            if ((int)UVar5 < 0) goto LAB_40534ca0;
          }
          _Str = UrlGetLocationW(&local_1080);
          if (_Str != (LPCWSTR)0x0) {
            sVar9 = wcslen(_Str);
            memmove(_Str + 1,_Str,(sVar9 + 1) * 2);
            *_Str = L'\0';
          }
          if (local_10a8 == (IBindCtx *)0x0) {
            UVar5 = CreateBindCtx(0,&local_10cc);
            if ((int)UVar5 < 0) goto LAB_40534ca0;
          }
          else {
            local_10cc = local_10a8;
            (*local_10a8->lpVtbl->AddRef)(local_10a8);
          }
          UVar5 = (*param_1[0xf].lpVtbl[2].AddRef)(param_1 + 0xf);
        }
      }
LAB_40534ca0:
      if (psa != (SAFEARRAY *)0x0) {
        SafeArrayUnaccessData(psa);
      }
    }
  }
  else {
    if (*param_4 == 0x4008) {
      lpStr1 = (wchar_t *)**(undefined4 **)(param_4 + 4);
    }
    else {
      if (*param_4 != 8) goto LAB_4053481c;
      lpStr1 = *(wchar_t **)(param_4 + 4);
    }
    if ((lpStr1 == (LPCWSTR)0x0) || (*lpStr1 == L'\0')) goto LAB_4053481c;
    local_10c8 = (int *)0x0;
    local_10ac = 0;
    iVar6 = FUN_40538a84(param_1,(IID *)&DAT_405164bc,&local_10c8);
    if (iVar6 < 0) goto LAB_4053481c;
    iVar6 = StrCmpNW(lpStr1,L"_[",2);
    if ((iVar6 != 0) || (local_10c4 = StrChrW(lpStr1,L']'), local_10c4 == (LPWSTR)0x0)) {
LAB_405346d4:
      UVar5 = (**(code **)(*local_10c8 + 0x34))(local_10c8,lpStr1,1,&local_10a0);
      if (-1 < (int)UVar5) {
        if (local_10a0 == (int *)0x0) {
          if ((lpStr1 == (BSTR)0x0) || (*lpStr1 == L'\0')) {
            lpStr1 = L"_desktop";
          }
          uVar12 = 2;
          local_10b0 = 1;
          UVar5 = 0x80004005;
        }
        else {
          UVar5 = (**(code **)*local_10a0)(local_10a0,&DAT_4051645c,&local_10b4);
          (**(code **)(*local_10a0 + 8))();
          puVar3 = PTR_DAT_40544350;
          if (-1 < (int)UVar5) {
            local_1098[0] = PTR_DAT_40544350;
            memset(&local_1090,0,0x10);
            local_1090.n2.vt = 8;
            local_1090._8_4_ = puVar3;
            UVar5 = (**(code **)(*local_10b4 + 0x2c))
                              (local_10b4,local_10bc,local_109c,&local_1090,param_5,param_6);
            local_1090._8_4_ = 0;
            FUN_4052eac4((VARIANTARG *)&local_1090.n2);
            (**(code **)(*local_10b4 + 8))();
            local_10ac = 1;
            FUN_405319d4((int *)local_1098);
          }
        }
      }
      (**(code **)(*local_10c8 + 8))();
      if (local_10ac != 0) goto LAB_40534cb0;
      if ((int)UVar5 < 0) goto LAB_4053481c;
      goto LAB_40534848;
    }
    local_10c4 = local_10c4 + 1;
    lpStr1 = SysAllocString(local_10c4);
    if (lpStr1 != (BSTR)0x0) goto LAB_405346d4;
    UVar5 = 0x8007000e;
  }
LAB_40534cb0:
  if ((local_10c4 != (LPWSTR)0x0) && (lpStr1 != (BSTR)0x0)) {
    SysFreeString(lpStr1);
  }
  IUnknown_AtomicRelease(&local_10c0);
  IUnknown_AtomicRelease(&local_10cc);
  FUN_4052d97c((int *)&local_10d4,(ushort *)0x0);
LAB_40534cf4:
  FUN_40542538(local_30);
  return UVar5;
}



/* 40534d30 FUN_40534d30 */

/* Boundary evidence: original MIPS .pdata 40534d30..40534edb. Semantic name remains unreviewed. */

undefined4
FUN_40534d30(int *param_1,short *param_2,short *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar4 = 0x80070057;
  uVar5 = 0;
  if (param_3 != (short *)0x0) {
    if (*param_3 == 3) {
      uVar5 = *(uint *)(param_3 + 4);
    }
    else {
      if (*param_3 != 2) goto LAB_40534ddc;
      uVar5 = (uint)param_3[4];
    }
    if (uVar5 == 0x20) {
      uVar4 = IUnknown_Exec(param_1[0x25],&DAT_405163ec,0x27,0,param_2,0);
      return uVar4;
    }
  }
LAB_40534ddc:
  if (param_2 == (short *)0x0) {
    uVar4 = (**(code **)(*param_1 + 0x2c))(param_1,0,0,0,0,0);
  }
  else {
    iVar1 = FUN_4053f620(param_2);
    if (iVar1 == 0) {
      pvVar2 = FUN_4053f538(param_2);
      if (pvVar2 != (void *)0x0) {
        uVar4 = 1;
        if ((uVar5 & 0x200) != 0) {
          uVar4 = 0x2000001;
        }
        piVar3 = (int *)param_1[0x31];
        if (piVar3 == (int *)0x0) {
          uVar4 = 0x80004005;
        }
        else {
          uVar4 = (**(code **)(*piVar3 + 0x2c))(piVar3,pvVar2,uVar4);
        }
        FUN_40537f64((int)pvVar2);
      }
    }
    else {
      uVar4 = (**(code **)(*param_1 + 0x2c))(param_1,iVar1,param_3,param_4,param_5,param_6);
    }
  }
  return uVar4;
}



/* 40534edc FUN_40534edc */

/* Boundary evidence: original MIPS .pdata 40534edc..40534fb3. Semantic name remains unreviewed. */

undefined4 FUN_40534edc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *local_10 [2];
  
  iVar1 = SHIsSameObject(*(undefined4 *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 0xcc));
  if ((iVar1 == 0) && (*(IUnknown **)(param_1 + 0xcc) != (IUnknown *)0x0)) {
    IUnknown_QueryService
              (*(IUnknown **)(param_1 + 0xcc),(GUID *)&DAT_405164bc,(IID *)&DAT_4051644c,local_10);
    if (local_10[0] != (int *)0x0) {
      uVar2 = (**(code **)(*local_10[0] + 0x1c))();
      (**(code **)(*local_10[0] + 8))();
      return uVar2;
    }
  }
  else {
    piVar3 = *(int **)(param_1 + 0xc4);
    if (piVar3 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3,0,0x4001);
      return uVar2;
    }
  }
  return 0x80004005;
}



/* 40534fb4 FUN_40534fb4 */

/* Boundary evidence: original MIPS .pdata 40534fb4..4053508b. Semantic name remains unreviewed. */

undefined4 FUN_40534fb4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *local_10 [2];
  
  iVar1 = SHIsSameObject(*(undefined4 *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 0xcc));
  if ((iVar1 == 0) && (*(IUnknown **)(param_1 + 0xcc) != (IUnknown *)0x0)) {
    IUnknown_QueryService
              (*(IUnknown **)(param_1 + 0xcc),(GUID *)&DAT_405164bc,(IID *)&DAT_4051644c,local_10);
    if (local_10[0] != (int *)0x0) {
      uVar2 = (**(code **)(*local_10[0] + 0x20))();
      (**(code **)(*local_10[0] + 8))();
      return uVar2;
    }
  }
  else {
    piVar3 = *(int **)(param_1 + 0xc4);
    if (piVar3 != (int *)0x0) {
      uVar2 = (**(code **)(*piVar3 + 0x2c))(piVar3,0,0x8001);
      return uVar2;
    }
  }
  return 0x80004005;
}



/* 4053508c FUN_4053508c */

/* Boundary evidence: original MIPS .pdata 4053508c..4053513f. Semantic name remains unreviewed. */

int FUN_4053508c(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_40533614(param_1);
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = FUN_40541d40();
    if (-1 < iVar1) {
      piVar2 = *(int **)(param_1 + 0xd8);
      if (piVar2 == (int *)0x0) {
        iVar1 = -0x7fffbffb;
      }
      else {
        iVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2,0,1);
      }
      FUN_40537f64(0);
    }
  }
  return iVar1;
}



/* 40535140 FUN_40535140 */

/* Boundary evidence: original MIPS .pdata 40535140..4053515f. Semantic name remains unreviewed. */

void FUN_40535140(int param_1)

{
  FUN_4053508c(param_1 + -0x14);
  return;
}



/* 40535160 FUN_40535160 */

/* Boundary evidence: original MIPS .pdata 40535160..4053517f. Semantic name remains unreviewed. */

void FUN_40535160(int param_1)

{
  FUN_4053508c(param_1 + -0x14);
  return;
}



/* 40535180 FUN_40535180 */

/* Boundary evidence: original MIPS .pdata 40535180..40535233. Semantic name remains unreviewed. */

undefined4 FUN_40535180(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_20 [16];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),0x100,0x100);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x20))
                      (*(int **)(param_1 + 0x94),0xffffffff,param_2);
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0x102,auStack_20,1,0xb,param_2);
  }
  return uVar1;
}



/* 40535234 FUN_40535234 */

/* Boundary evidence: original MIPS .pdata 40535234..405352ef. Semantic name remains unreviewed. */

undefined4 FUN_40535234(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [16];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),0x100,0x100);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x20))(*(int **)(param_1 + 0x94),1,param_2);
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0x101,auStack_28,1,0xb,param_2);
  }
  return uVar1;
}



/* 405352f0 FUN_405352f0 */

/* Boundary evidence: original MIPS .pdata 405352f0..405353eb. Semantic name remains unreviewed. */

undefined4 FUN_405352f0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_28 [16];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),0x100,0x100);
    (**(code **)(**(int **)(param_1 + 0x94) + 0x20))(*(int **)(param_1 + 0x94),2,param_2 == 2);
    if ((param_2 == 1) || (uVar1 = 0, param_2 == -1)) {
      uVar1 = 1;
    }
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x20))(*(int **)(param_1 + 0x94),6,uVar1);
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0xff,auStack_28,1,0xb,
               (int)(short)param_2);
  }
  return uVar1;
}



/* 405353ec FUN_405353ec */

/* Boundary evidence: original MIPS .pdata 405353ec..4053549f. Semantic name remains unreviewed. */

undefined4 FUN_405353ec(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_20 [16];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),0x100,0x100);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x20))(*(int **)(param_1 + 0x94),7,param_2);
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0x100,auStack_20,1,0xb,param_2);
  }
  return uVar1;
}



/* 405354a0 FUN_405354a0 */

/* Boundary evidence: original MIPS .pdata 405354a0..40535553. Semantic name remains unreviewed. */

undefined4 FUN_405354a0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_20 [16];
  
  if (*(int *)(param_1 + 0x94) == 0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x94) + 0x4c))(*(int **)(param_1 + 0x94),0x100,0x100);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x94) + 0x20))(*(int **)(param_1 + 0x94),9,param_2);
    IUnknown_CPContainerInvokeParam
              (*(undefined4 *)(param_1 + 0x38),&DAT_405162bc,0x105,auStack_20,1,0xb,param_2);
  }
  return uVar1;
}



/* 40535554 FUN_40535554 */

/* Boundary evidence: original MIPS .pdata 40535554..405355d3. Semantic name remains unreviewed. */

void FUN_40535554(LPCITEMIDLIST param_1,int *param_2)

{
  LPCWSTR pWVar1;
  int iVar2;
  
  if ((param_1 != (LPCITEMIDLIST)0x0) &&
     (pWVar1 = (LPCWSTR)FUN_40531afc(param_2,0x824), 0x823 < *(uint *)(*param_2 + -8))) {
    iVar2 = FUN_40522b14(param_1,pWVar1,0x8000);
    FUN_40531bcc(param_2,0xffffffff);
    if (-1 < iVar2) {
      return;
    }
  }
  FUN_40533e60(param_2);
  return;
}



/* 405355d4 FUN_405355d4 */

/* Boundary evidence: original MIPS .pdata 405355d4..40535833. Semantic name remains unreviewed. */

void FUN_405355d4(IUnknown *param_1,undefined4 param_2,LPCITEMIDLIST param_3)

{
  OLECHAR *psz;
  HMODULE pHVar1;
  int iVar2;
  void **ppvVar3;
  undefined4 uVar4;
  void *local_48;
  void *local_44;
  void *local_40;
  OLECHAR *local_3c;
  undefined2 local_38;
  undefined1 auStack_36 [6];
  BSTR local_30;
  
  local_48 = (void *)0x0;
  local_40 = (void *)0x0;
  local_44 = (void *)0x0;
  local_3c = (OLECHAR *)PTR_DAT_40544350;
  FUN_40535554(param_3,(int *)&local_3c);
  FUN_4053379c(param_1,&local_48,&local_40);
  if (local_48 == (void *)0x0) {
    uVar4 = 0x65;
    ppvVar3 = &local_48;
  }
  else {
    uVar4 = 0xc9;
    ppvVar3 = (void **)0x0;
  }
  FUN_40523da4(param_1,ppvVar3,&local_44);
  psz = local_3c;
  if ((local_40 != (void *)0x0) || (local_44 != (void *)0x0)) {
    memset(auStack_36,0,0xe);
    local_38 = 8;
    pHVar1 = GetModuleHandleW(L"OLEAUT32.DLL");
    if (pHVar1 == (HMODULE)0x0) {
      local_30 = psz;
    }
    else {
      local_30 = SysAllocString(psz);
    }
    if (local_44 != (void *)0x0) {
      FUN_40533d14(param_1,local_44,0,0,0xfc,2);
      IUnknown_AtomicRelease(&local_44);
    }
    if (local_40 != (void *)0x0) {
      FUN_40533d14(param_1,local_40,0,0,0xfc,2);
      IUnknown_AtomicRelease(&local_40);
    }
    if (pHVar1 != (HMODULE)0x0) {
      SysFreeString(local_30);
    }
  }
  if (local_48 != (void *)0x0) {
    iVar2 = FUN_4053ad2c(psz);
    if (((iVar2 != 0xf) && (iVar2 = FUN_4053ad2c(psz), iVar2 != 0x10)) &&
       (param_3 != (LPCITEMIDLIST)0x0)) {
      FUN_40533d14(param_1,local_48,0,0,uVar4,1);
    }
    IUnknown_AtomicRelease(&local_48);
  }
  FUN_405319d4((int *)&local_3c);
  return;
}



/* 40535834 FUN_40535834 */

/* Boundary evidence: original MIPS .pdata 40535834..40535a3b. Semantic name remains unreviewed. */

void FUN_40535834(IUnknown *param_1,undefined4 *param_2,LPCITEMIDLIST param_3)

{
  HMODULE pHVar1;
  int iVar2;
  void *local_48;
  void *local_44;
  OLECHAR *local_40;
  int *local_3c;
  undefined2 local_38;
  undefined1 auStack_36 [6];
  BSTR local_30;
  
  local_44 = (void *)0x0;
  local_48 = (void *)0x0;
  if (param_1 != (IUnknown *)0x0) {
    local_40 = (OLECHAR *)PTR_DAT_40544350;
    FUN_40535554(param_3,(int *)&local_40);
    FUN_4053379c(param_1,(undefined4 *)0x0,&local_44);
    FUN_40523da4(param_1,(undefined4 *)0x0,&local_48);
    if ((local_44 != (void *)0x0) || (local_48 != (void *)0x0)) {
      memset(auStack_36,0,0xe);
      local_38 = 8;
      pHVar1 = GetModuleHandleW(L"OLEAUT32.DLL");
      if (pHVar1 == (HMODULE)0x0) {
        local_30 = local_40;
      }
      else {
        local_30 = SysAllocString(local_40);
      }
      if (local_48 != (void *)0x0) {
        FUN_40533d14(param_1,local_48,0,0,0x103,2);
        IUnknown_AtomicRelease(&local_48);
      }
      if (local_44 != (void *)0x0) {
        FUN_40533d14(param_1,local_44,0,0,0x103,2);
        IUnknown_AtomicRelease(&local_44);
      }
      if (pHVar1 != (HMODULE)0x0) {
        SysFreeString(local_30);
      }
    }
    iVar2 = (**(code **)*param_2)(param_2,&DAT_40512e84,&local_3c);
    if (-1 < iVar2) {
      (**(code **)(*local_3c + 0x14))();
      (**(code **)(*local_3c + 8))();
    }
    FUN_405319d4((int *)&local_40);
  }
  return;
}



/* 40535a3c FUN_40535a3c */

/* Boundary evidence: original MIPS .pdata 40535a3c..40535b0b. Semantic name remains unreviewed. */

void FUN_40535a3c(OLECHAR *param_1,undefined4 *param_2,OLECHAR *param_3,undefined4 *param_4,
                 void *param_5,ULONG param_6,undefined2 *param_7)

{
  BSTR pOVar1;
  SAFEARRAY *pSVar2;
  
  *param_2 = 0;
  pSVar2 = (SAFEARRAY *)0x0;
  if ((param_1 != (OLECHAR *)0x0) && (*param_1 != L'\0')) {
    pOVar1 = SysAllocString(param_1);
    *param_2 = pOVar1;
  }
  *param_4 = 0;
  if ((param_3 != (OLECHAR *)0x0) && (*param_3 != L'\0')) {
    pOVar1 = SysAllocString(param_3);
    *param_4 = pOVar1;
  }
  if ((param_5 != (void *)0x0) && (param_6 != 0)) {
    pSVar2 = FUN_40533bd4(param_5,param_6);
  }
  memset(param_7,0,0x10);
  if (pSVar2 != (SAFEARRAY *)0x0) {
    *param_7 = 0x2011;
    *(SAFEARRAY **)(param_7 + 4) = pSVar2;
  }
  return;
}



/* 40535b0c FUN_40535b0c */

/* Boundary evidence: original MIPS .pdata 40535b0c..40535f67. Semantic name remains unreviewed. */

void FUN_40535b0c(IUnknown *param_1,undefined4 param_2,undefined4 param_3,LPCITEMIDLIST param_4,
                 undefined4 param_5,undefined4 param_6,OLECHAR *param_7,void *param_8,ULONG param_9,
                 OLECHAR *param_10,int *param_11)

{
  OLECHAR *psz;
  HMODULE pHVar1;
  int iVar2;
  void **ppvVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  undefined4 uVar6;
  void *local_b0;
  void *local_ac;
  void *local_a8;
  BSTR local_a4;
  BSTR local_a0;
  OLECHAR *local_9c;
  int local_98;
  undefined1 auStack_94 [12];
  undefined2 local_88;
  undefined1 auStack_86 [6];
  BSTR local_80;
  undefined2 local_78;
  undefined1 auStack_76 [6];
  BSTR local_70;
  undefined2 local_68;
  undefined1 auStack_66 [6];
  BSTR local_60;
  undefined2 local_58;
  undefined1 auStack_56 [6];
  VARIANTARG *local_50;
  undefined2 local_48;
  undefined1 auStack_46 [6];
  undefined4 local_40;
  VARIANTARG VStack_38;
  
  local_b0 = (void *)0x0;
  local_a8 = (void *)0x0;
  local_ac = (void *)0x0;
  local_a4 = (BSTR)0x0;
  local_a0 = (BSTR)0x0;
  local_98 = 0;
  memset(auStack_94,0,0xc);
  local_9c = (OLECHAR *)PTR_DAT_40544350;
  FUN_40535554(param_4,(int *)&local_9c);
  FUN_4053379c(param_1,&local_b0,&local_a8);
  if (local_b0 == (void *)0x0) {
    uVar6 = 100;
    ppvVar3 = &local_b0;
  }
  else {
    uVar6 = 200;
    ppvVar3 = (void **)0x0;
  }
  FUN_40523da4(param_1,ppvVar3,&local_ac);
  psz = local_9c;
  if ((((local_b0 != (void *)0x0) || (local_a8 != (void *)0x0)) ||
      (pOVar4 = (BSTR)0x0, pOVar5 = (BSTR)0x0, local_ac != (void *)0x0)) &&
     ((FUN_40535a3c(param_7,&local_a4,param_10,&local_a0,param_8,param_9,(undefined2 *)&VStack_38),
      local_a8 != (void *)0x0 || (pOVar4 = local_a4, pOVar5 = local_a0, local_ac != (void *)0x0))))
  {
    memset(auStack_86,0,0xe);
    local_88 = 8;
    pHVar1 = GetModuleHandleW(L"OLEAUT32.DLL");
    if (pHVar1 == (HMODULE)0x0) {
      local_80 = psz;
    }
    else {
      local_80 = SysAllocString(psz);
    }
    memset(auStack_46,0,0xe);
    local_48 = 3;
    local_40 = param_6;
    memset(auStack_66,0,0xe);
    local_68 = 8;
    local_60 = local_a4;
    memset(auStack_56,0,0xe);
    local_50 = &VStack_38;
    local_58 = 0x400c;
    memset(auStack_76,0,0xe);
    local_78 = 8;
    local_70 = local_a0;
    if (local_ac != (void *)0x0) {
      FUN_40533d14(param_1,local_ac,&local_98,0,0xfa,7);
    }
    if ((local_a8 != (void *)0x0) && (local_98 == 0)) {
      FUN_40533d14(param_1,local_a8,&local_98,0,0xfa,7);
    }
    pOVar4 = local_60;
    pOVar5 = local_70;
    if (pHVar1 != (HMODULE)0x0) {
      SysFreeString(local_80);
      pOVar4 = local_60;
      pOVar5 = local_70;
    }
  }
  if ((((local_98 == 0) && (local_b0 != (void *)0x0)) && (iVar2 = FUN_4053ad2c(psz), iVar2 != 0xf))
     && (iVar2 = FUN_4053ad2c(psz), iVar2 != 0x10)) {
    FUN_40533d14(param_1,local_b0,&local_98,0,uVar6,6);
  }
  *param_11 = local_98;
  if (((local_b0 != (void *)0x0) || (local_a8 != (void *)0x0)) || (local_ac != (void *)0x0)) {
    FUN_405338b4(pOVar4,pOVar5,&VStack_38);
    IUnknown_AtomicRelease(&local_b0);
    IUnknown_AtomicRelease(&local_a8);
    IUnknown_AtomicRelease(&local_ac);
  }
  FUN_405319d4((int *)&local_9c);
  return;
}



/* 40535f68 FUN_40535f68 */

/* Boundary evidence: original MIPS .pdata 40535f68..405361cf. Semantic name remains unreviewed. */

void FUN_40535f68(IUnknown *param_1,undefined4 param_2,LPCITEMIDLIST param_3,OLECHAR *param_4,
                 undefined4 param_5,undefined4 *param_6)

{
  HMODULE pHVar1;
  BSTR pOVar2;
  OLECHAR *local_68;
  void *local_64;
  void *local_60 [2];
  undefined2 local_58;
  undefined1 auStack_56 [6];
  BSTR local_50;
  undefined2 local_48;
  undefined1 auStack_46 [6];
  BSTR local_40;
  undefined2 local_38;
  undefined1 auStack_36 [6];
  undefined4 local_30;
  
  pOVar2 = (BSTR)0x0;
  if ((param_4 != (OLECHAR *)0x0) && (*param_4 != L'\0')) {
    pOVar2 = SysAllocString(param_4);
  }
  local_60[0] = (void *)0x0;
  local_64 = (void *)0x0;
  *param_6 = 0;
  FUN_4053379c(param_1,(undefined4 *)0x0,local_60);
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_64);
  local_68 = (OLECHAR *)PTR_DAT_40544350;
  FUN_40535554(param_3,(int *)&local_68);
  memset(auStack_56,0,0xe);
  local_58 = 8;
  pHVar1 = GetModuleHandleW(L"OLEAUT32.DLL");
  if (pHVar1 == (HMODULE)0x0) {
    local_50 = local_68;
  }
  else {
    local_50 = SysAllocString(local_68);
  }
  memset(auStack_36,0,0xe);
  local_38 = 3;
  local_30 = param_5;
  memset(auStack_46,0,0xe);
  local_48 = 8;
  local_40 = pOVar2;
  if (local_64 != (void *)0x0) {
    FUN_40533d14(param_1,local_64,0,0,0x10f,5);
    IUnknown_AtomicRelease(&local_64);
  }
  if (local_60[0] != (void *)0x0) {
    FUN_40533d14(param_1,local_60[0],0,0,0x10f,5);
    IUnknown_AtomicRelease(local_60);
  }
  if (pHVar1 != (HMODULE)0x0) {
    SysFreeString(local_50);
  }
  if (local_40 != (BSTR)0x0) {
    SysFreeString(local_40);
  }
  FUN_405319d4((int *)&local_68);
  return;
}



/* 405361d0 FUN_405361d0 */

/* Boundary evidence: original MIPS .pdata 405361d0..405362bf. Semantic name remains unreviewed. */

void FUN_405361d0(IUnknown *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_28;
  void *local_24;
  
  local_24 = (void *)0x0;
  local_28 = (void *)0x0;
  FUN_4053379c(param_1,(undefined4 *)0x0,&local_24);
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_28);
  if (local_28 != (void *)0x0) {
    FUN_40533d14(param_1,local_28,0,0,param_3,1);
    IUnknown_AtomicRelease(&local_28);
  }
  if (local_24 != (void *)0x0) {
    FUN_40533d14(param_1,local_24,0,0,param_3,1);
    IUnknown_AtomicRelease(&local_24);
  }
  return;
}



/* 405362c0 FUN_405362c0 */

/* Boundary evidence: original MIPS .pdata 405362c0..40536427. Semantic name remains unreviewed. */

void FUN_405362c0(IUnknown *param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  void *local_48;
  void *local_44;
  undefined2 local_40;
  undefined1 auStack_3e [6];
  undefined2 local_38;
  undefined2 local_30;
  undefined1 auStack_2e [6];
  undefined4 local_28;
  
  local_44 = (void *)0x0;
  local_48 = (void *)0x0;
  FUN_4053379c(param_1,(undefined4 *)0x0,&local_44);
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_48);
  memset(auStack_2e,0,0xe);
  local_30 = 3;
  local_28 = param_3;
  memset(auStack_3e,0,0xe);
  local_40 = 0xb;
  local_38 = param_4;
  if (local_48 != (void *)0x0) {
    FUN_40533d14(param_1,local_48,0,0,0xe3,3);
    IUnknown_AtomicRelease(&local_48);
  }
  if (local_44 != (void *)0x0) {
    FUN_40533d14(param_1,local_44,0,0,0xe3,3);
    IUnknown_AtomicRelease(&local_44);
  }
  return;
}



/* 40536428 FUN_40536428 */

/* Boundary evidence: original MIPS .pdata 40536428..405364af. Semantic name remains unreviewed. */

void FUN_40536428(undefined4 *param_1)

{
  void *local_18 [2];
  
  local_18[0] = (void *)0x0;
  FUN_40523da4(param_1,(undefined4 *)0x0,local_18);
  if (local_18[0] != (void *)0x0) {
    FUN_40533d14(param_1,local_18[0],0,0,0x110,1);
    IUnknown_AtomicRelease(local_18);
  }
  return;
}



/* 405364b0 FUN_405364b0 */

/* Boundary evidence: original MIPS .pdata 405364b0..40536637. Semantic name remains unreviewed. */

void FUN_405364b0(IUnknown *param_1,undefined4 param_2,LPCITEMIDLIST param_3,undefined4 param_4,
                 undefined4 param_5,OLECHAR *param_6,void *param_7,ULONG param_8,OLECHAR *param_9,
                 undefined4 *param_10)

{
  int iVar1;
  undefined4 uVar2;
  int *local_40;
  undefined *local_3c;
  BSTR local_38;
  BSTR local_34;
  VARIANTARG VStack_30;
  
  local_3c = PTR_DAT_40544350;
  FUN_40535554(param_3,(int *)&local_3c);
  uVar2 = 0;
  *param_10 = 0;
  iVar1 = FUN_4053379c(param_1,&local_40,(undefined4 *)0x0);
  if (iVar1 == 0) {
    uVar2 = 0xcc;
  }
  else {
    iVar1 = FUN_40523da4(param_1,&local_40,(undefined4 *)0x0);
    if (iVar1 == 0) {
      uVar2 = 0x6b;
    }
  }
  if (local_40 != (int *)0x0) {
    FUN_40535a3c(param_6,&local_34,param_9,&local_38,param_7,param_8,(undefined2 *)&VStack_30);
    if (param_3 != (LPCITEMIDLIST)0x0) {
      FUN_40533d14(param_1,local_40,param_10,0,uVar2,6);
    }
    FUN_405338b4(local_34,local_38,&VStack_30);
    (**(code **)(*local_40 + 8))();
  }
  FUN_405319d4((int *)&local_3c);
  return;
}



/* 40536638 FUN_40536638 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40536638..40536903. Semantic name remains unreviewed. */

void FUN_40536638(IUnknown *param_1,int *param_2,OLECHAR *param_3,int *param_4,int *param_5)

{
  int iVar1;
  BSTR bstrString;
  BSTR bstrString_00;
  int *local_1098;
  void *local_1094;
  undefined4 local_1090;
  int *local_108c;
  void *local_1088;
  int local_1084 [3];
  OLECHAR aOStack_1078 [2084];
  uint local_30;
  
  local_30 = DAT_40544354;
  bstrString = (BSTR)0x0;
  *param_5 = 0;
  bstrString_00 = (BSTR)0x0;
  local_1094 = (void *)0x0;
  local_1088 = (void *)0x0;
  *param_4 = 0;
  local_1090 = 0;
  if (param_2 != (int *)0x0) {
    local_108c = (int *)0x0;
    iVar1 = (**(code **)(*param_2 + 0x28))(param_2,L"__HTMLLOADOPTIONS",&local_108c);
    if (-1 < iVar1) {
      local_1098 = (int *)0x0;
      iVar1 = (**(code **)*local_108c)(local_108c,&UNK_4051690c,&local_1098);
      if (-1 < iVar1) {
        local_1084[1] = 4;
        local_1084[0] = 0x1048;
        (**(code **)(*local_1098 + 0xc))(local_1098,4,&local_1090,local_1084 + 1);
        iVar1 = (**(code **)(*local_1098 + 0xc))(local_1098,5,aOStack_1078,local_1084);
        if ((-1 < iVar1) && (local_1084[0] != 0)) {
          bstrString_00 = SysAllocString(aOStack_1078);
        }
        (**(code **)(*local_1098 + 8))();
      }
      (**(code **)(*local_108c + 8))();
    }
  }
  if (param_3 != (OLECHAR *)0x0) {
    bstrString = SysAllocString(param_3);
  }
  FUN_4053379c(param_1,(undefined4 *)0x0,&local_1094);
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_1088);
  if ((local_1094 != (void *)0x0) || (local_1088 != (void *)0x0)) {
    if (local_1088 != (void *)0x0) {
      FUN_40533d14(param_1,local_1088,param_5,param_4,0x111,5);
    }
    if (((local_1094 != (void *)0x0) && (*param_5 == 0)) && (*param_4 == 0)) {
      FUN_40533d14(param_1,local_1094,param_5,param_4,0x111,5);
    }
    IUnknown_AtomicRelease(&local_1088);
    IUnknown_AtomicRelease(&local_1094);
  }
  SysFreeString(bstrString);
  SysFreeString(bstrString_00);
  FUN_40542538(local_30);
  return;
}



/* 40536904 FUN_40536904 */

/* Boundary evidence: original MIPS .pdata 40536904..40536a47. Semantic name remains unreviewed. */

void FUN_40536904(IUnknown *param_1,int *param_2,int *param_3)

{
  void *local_28;
  void *local_24;
  
  *param_3 = 0;
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  *param_2 = 0;
  FUN_4053379c(param_1,(undefined4 *)0x0,&local_28);
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_24);
  if ((local_28 != (void *)0x0) || (local_24 != (void *)0x0)) {
    if (local_24 != (void *)0x0) {
      FUN_40533d14(param_1,local_24,param_3,param_2,0xfb,2);
    }
    if (((local_28 != (void *)0x0) && (*param_3 == 0)) && (*param_2 == 0)) {
      FUN_40533d14(param_1,local_28,param_3,param_2,0xfb,2);
    }
    IUnknown_AtomicRelease(&local_24);
    IUnknown_AtomicRelease(&local_28);
  }
  return;
}



/* 40536a48 FUN_40536a48 */

/* Boundary evidence: original MIPS .pdata 40536a48..40536b67. Semantic name remains unreviewed. */

void FUN_40536a48(IUnknown *param_1,int *param_2)

{
  void *local_28;
  void *local_24;
  
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  *param_2 = 0;
  FUN_40523da4(param_1,(undefined4 *)0x0,&local_28);
  FUN_4053379c(param_1,(undefined4 *)0x0,&local_24);
  if (local_28 != (void *)0x0) {
    FUN_40533d14(param_1,local_28,param_2,0,0x10e,2);
  }
  if ((local_24 != (void *)0x0) && (*param_2 == 0)) {
    FUN_40533d14(param_1,local_24,param_2,0,0x10e,2);
  }
  IUnknown_AtomicRelease(&local_28);
  IUnknown_AtomicRelease(&local_24);
  return;
}



/* 40536b68 FUN_40536b68 */

/* Boundary evidence: original MIPS .pdata 40536b68..40536ca3. Semantic name remains unreviewed. */

void FUN_40536b68(undefined4 *param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  undefined *local_28;
  int *local_24;
  int *local_20 [2];
  
  iVar1 = FUN_40523da4(param_1,local_20,&local_24);
  if (iVar1 == 0) {
    local_28 = PTR_DAT_40544350;
    if (param_3 == (wchar_t *)0x0) {
      FUN_40533e60((int *)&local_28);
    }
    else {
      FUN_40531aa8((int *)&local_28,param_3);
    }
    if (local_24 != (int *)0x0) {
      FUN_40533d14(param_1,local_24,0,0,param_2,1);
    }
    if (local_20[0] != (int *)0x0) {
      FUN_40533d14(param_1,local_20[0],0,0,param_2,1);
    }
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    if (local_20[0] != (int *)0x0) {
      (**(code **)(*local_20[0] + 8))();
    }
    FUN_405319d4((int *)&local_28);
  }
  return;
}



/* 40536ca4 FUN_40536ca4 */

/* Boundary evidence: original MIPS .pdata 40536ca4..40536d87. Semantic name remains unreviewed. */

void FUN_40536ca4(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_20;
  int *local_1c;
  
  iVar1 = FUN_40523da4(param_1,&local_1c,&local_20);
  if (iVar1 == 0) {
    if (local_20 != (int *)0x0) {
      FUN_40533d14(param_1,local_20,0,0,param_2,1);
      (**(code **)(*local_20 + 8))();
    }
    if (local_1c != (int *)0x0) {
      FUN_40533d14(param_1,local_1c,0,0,param_2,1);
      (**(code **)(*local_1c + 8))();
    }
  }
  return;
}



/* 40536d88 FUN_40536d88 */

/* Boundary evidence: original MIPS .pdata 40536d88..40536e3b. Semantic name remains unreviewed. */

void FUN_40536d88(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_18;
  int *local_14;
  
  iVar1 = FUN_40523da4(param_1,&local_14,&local_18);
  if (iVar1 == 0) {
    if (local_18 != (int *)0x0) {
      FUN_40533d14(param_1,local_18,0,0,param_2,0);
      (**(code **)(*local_18 + 8))();
    }
    if (local_14 != (int *)0x0) {
      FUN_40533d14(param_1,local_14,0,0,param_2,0);
      (**(code **)(*local_14 + 8))();
    }
  }
  return;
}



/* 40536e3c FUN_40536e3c */

/* Boundary evidence: original MIPS .pdata 40536e3c..40536efb. Semantic name remains unreviewed. */

void FUN_40536e3c(undefined4 *param_1)

{
  int iVar1;
  int *local_10;
  int *local_c;
  
  iVar1 = FUN_40523da4(param_1,&local_c,&local_10);
  if (iVar1 == 0) {
    if (local_10 != (int *)0x0) {
      FUN_40533d14(param_1,local_10,0,0,0xfd,0);
      (**(code **)(*local_10 + 8))();
    }
    if (local_c != (int *)0x0) {
      FUN_40533d14(param_1,local_c,0,0,0x67,1);
      (**(code **)(*local_c + 8))();
    }
  }
  return;
}



/* 40536efc FUN_40536efc */

/* Boundary evidence: original MIPS .pdata 40536efc..40537043. Semantic name remains unreviewed. */

int FUN_40536efc(int param_1,wchar_t *param_2,undefined4 param_3,ULONG param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_res8;
  undefined4 local_resc;
  
  if (param_2 == (wchar_t *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    local_res8 = param_3;
    local_resc = param_4;
    for (piVar1 = *(int **)(param_1 + 0xa0); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      iVar2 = StrCmpW(param_2,(LPCWSTR)piVar1[1]);
      if (iVar2 == 0) {
        if (piVar1 != (int *)0x0) goto LAB_40536ff4;
        break;
      }
    }
    piVar1 = (int *)FUN_4052d4e8(0x78);
    if (piVar1 == (undefined4 *)0x0) {
      piVar1 = (undefined4 *)0x0;
    }
    else {
      memset(piVar1 + 2,0,0x10);
    }
    if (piVar1 == (undefined4 *)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      iVar2 = FUN_40531c34((int)piVar1,param_2);
      if (iVar2 < 0) {
        FUN_4053446c(piVar1,1);
      }
      else {
        *piVar1 = *(undefined4 *)(param_1 + 0xa0);
        *(int **)(param_1 + 0xa0) = piVar1;
LAB_40536ff4:
        iVar2 = param_1;
        if (param_1 == 0x14) {
          iVar2 = 0;
        }
        iVar2 = FUN_40531d30((int)piVar1,(VARIANTARG *)&stack0x00000008,iVar2);
        FUN_40536ca4(*(undefined4 **)(param_1 + 0x38),0x70);
      }
    }
  }
  return iVar2;
}



/* 40537044 FUN_40537044 */

/* Boundary evidence: original MIPS .pdata 40537044..40537077. Semantic name remains unreviewed. */

void FUN_40537044(int param_1,LPCWSTR param_2,short *param_3,short *param_4,ushort *param_5,
                 short *param_6)

{
  FUN_405344d4((IUnknown *)(param_1 + -0x14),param_2,param_3,param_4,param_5,param_6,(IBindCtx *)0x0
               ,(wchar_t *)0x0);
  return;
}



/* 40537078 FUN_40537078 */

/* Boundary evidence: original MIPS .pdata 40537078..405370b7. Semantic name remains unreviewed. */

void FUN_40537078(int param_1,int param_2,short *param_3,short *param_4,ushort *param_5,
                 short *param_6,IBindCtx *param_7,wchar_t *param_8)

{
  FUN_405344d4((IUnknown *)(param_1 + -0x54),*(LPCWSTR *)(param_2 + 8),param_3,param_4,param_5,
               param_6,param_7,param_8);
  return;
}



/* 405370b8 FUN_405370b8 */

/* Boundary evidence: original MIPS .pdata 405370b8..4053732b. Semantic name remains unreviewed. */

undefined4 FUN_405370b8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  void **ppunk;
  void **ppunk_00;
  void **ppunk_01;
  void **ppunk_02;
  
  IUnknown_AtomicRelease((void **)(param_1 + 0x84));
  ppunk_02 = (void **)(param_1 + 0xa0);
  IUnknown_AtomicRelease(ppunk_02);
  ppunk = (void **)(param_1 + 0xb4);
  IUnknown_AtomicRelease(ppunk);
  ppunk_00 = (void **)(param_1 + 0xc4);
  IUnknown_AtomicRelease(ppunk_00);
  IUnknown_AtomicRelease((void **)(param_1 + 0xc0));
  ppunk_01 = (void **)(param_1 + 0xbc);
  IUnknown_AtomicRelease(ppunk_01);
  IUnknown_AtomicRelease((void **)(param_1 + 0xb8));
  IUnknown_AtomicRelease((void **)(param_1 + 200));
  if (param_2 == (undefined4 *)0x0) {
    FUN_40522fa8();
    puVar2 = *(undefined4 **)(param_1 + 0x90);
    *(undefined4 *)(param_1 + 0x90) = 0;
    while (puVar2 != (void *)0x0) {
      pvVar3 = (void *)*puVar2;
      FUN_4053446c(puVar2,1);
      puVar2 = pvVar3;
    }
  }
  else {
    (**(code **)*param_2)(param_2,&DAT_40513564,(void **)(param_1 + 0x84));
    (**(code **)*param_2)(param_2,&DAT_4051652c,ppunk);
    FUN_405332dc(*ppunk,*(undefined4 *)(param_1 + 0x94));
    iVar1 = (**(code **)*param_2)(param_2,&DAT_4051642c,ppunk_02);
    if (-1 < iVar1) {
      (**(code **)(*(int *)*ppunk_02 + 0xc))(*ppunk_02,&DAT_4051652c,&DAT_4051646c,param_1 + 200);
      (**(code **)(*(int *)*ppunk_02 + 0xc))
                (*ppunk_02,&DAT_4051658c,&DAT_4051652c,(void **)(param_1 + 0xb8));
      (**(code **)(*(int *)*ppunk_02 + 0xc))(*ppunk_02,&DAT_40512c24,&DAT_4051652c,ppunk_01);
      (**(code **)(*(int *)*ppunk_02 + 0xc))(*ppunk_02,&UNK_40512c14,&DAT_4051652c,ppunk_00);
      if (*ppunk_00 == (void *)0x0) {
        *ppunk_00 = *ppunk;
        (**(code **)(*(int *)*ppunk + 4))();
      }
      puVar2 = *ppunk_01;
      if ((puVar2 != (undefined4 *)0x0) && (*ppunk_00 == *ppunk)) {
        (**(code **)*puVar2)(puVar2,&DAT_4051646c,(void **)(param_1 + 0xc0));
      }
    }
  }
  return 0;
}



/* 4053732c FUN_4053732c */

/* Boundary evidence: original MIPS .pdata 4053732c..40537527. Semantic name remains unreviewed. */

undefined4 * FUN_4053732c(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  FUN_4052f420(param_1,&DAT_4051685c,1,1,&DAT_405162cc);
  param_1[6] = &PTR_LAB_405154cc;
  param_1[7] = &PTR_LAB_40511748;
  param_1[9] = &PTR_LAB_40515898;
  FUN_4052f168(param_1 + 0x10,param_2);
  param_1[0x14] = &PTR_LAB_405158a8;
  param_1[0x15] = &PTR_LAB_405158c8;
  *param_1 = &PTR_FUN_40515c2c;
  param_1[5] = &PTR_LAB_40515b10;
  param_1[6] = &PTR_LAB_40515af8;
  param_1[7] = &PTR_LAB_40515adc;
  param_1[8] = &PTR_LAB_40515ac8;
  param_1[9] = &PTR_LAB_40515ab8;
  param_1[10] = &PTR_LAB_40515a98;
  param_1[0xb] = &PTR_LAB_40515a88;
  param_1[0xc] = &PTR_LAB_40515a74;
  param_1[0xd] = &PTR_LAB_40515a38;
  param_1[0xe] = &PTR_LAB_40515a24;
  param_1[0xf] = &PTR_LAB_40515a00;
  param_1[0x10] = &PTR_LAB_405159ec;
  param_1[0x14] = &PTR_LAB_405159cc;
  param_1[0x15] = &PTR_LAB_405159b8;
  param_1[0x16] = &PTR_LAB_4051599c;
  param_1[0x17] = &PTR_FUN_4051210c;
  param_1[0x1d] = &PTR_FUN_4051210c;
  param_1[0x23] = &PTR_FUN_4051210c;
  param_1[0x29] = &PTR_FUN_405158dc;
  param_1[0x45] = 0xffffffff;
  param_1[0x46] = 0xffffffff;
  param_1[0x49] = &PTR_FUN_405157f4;
  param_1[0x4a] = 0;
  FUN_40516d54();
  InterlockedIncrement((LONG *)&DAT_4054471c);
  param_1[0x1c] = &DAT_405164fc;
  puVar1 = param_1 + 0x11;
  param_1[0x1b] = puVar1;
  param_1[0x21] = puVar1;
  param_1[0x22] = &DAT_405162bc;
  param_1[0x27] = puVar1;
  param_1[0x28] = &DAT_405164ec;
  FUN_40539448();
  return param_1;
}



/* 40537528 FUN_40537528 */

/* Boundary evidence: original MIPS .pdata 40537528..40537543. Semantic name remains unreviewed. */

void FUN_40537528(int param_1)

{
  FUN_4052efbc(param_1 + 0x40);
  return;
}



/* 40537544 FUN_40537544 */

/* Boundary evidence: original MIPS .pdata 40537544..4053755f. Semantic name remains unreviewed. */

void FUN_40537544(int param_1)

{
  FUN_4052ef6c(param_1 + 0x2c);
  return;
}



/* 40537560 FUN_40537560 */

/* Boundary evidence: original MIPS .pdata 40537560..4053757b. Semantic name remains unreviewed. */

void FUN_40537560(int param_1)

{
  FUN_4052ef94(param_1 + 0x2c);
  return;
}



/* 4053757c FUN_4053757c */

/* Boundary evidence: original MIPS .pdata 4053757c..40537597. Semantic name remains unreviewed. */

void FUN_4053757c(int param_1,undefined4 *param_2)

{
  FUN_4052f478(param_1 + -0x14,param_2);
  return;
}



/* 40537598 FUN_40537598 */

/* Boundary evidence: original MIPS .pdata 40537598..405375b3. Semantic name remains unreviewed. */

void FUN_40537598(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  FUN_4052f628(param_1 + -0x14,param_2,param_3,param_4);
  return;
}



/* 405375b4 FUN_405375b4 */

/* Boundary evidence: original MIPS .pdata 405375b4..405375df. Semantic name remains unreviewed. */

void FUN_405375b4(int param_1,void *param_2,LPOLESTR *param_3,UINT param_4,uint param_5,
                 MEMBERID *param_6)

{
  FUN_4052f728(param_1 + -0x14,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* 405375e0 FUN_405375e0 */

/* Boundary evidence: original MIPS .pdata 405375e0..40537623. Semantic name remains unreviewed. */

void FUN_405375e0(int param_1,MEMBERID param_2,void *param_3,uint param_4,WORD param_5,
                 DISPPARAMS *param_6,VARIANT *param_7,EXCEPINFO *param_8,UINT *param_9)

{
  FUN_4052f890((undefined4 *)(param_1 + -0x14),param_2,param_3,param_4,param_5,param_6,param_7,
               param_8,param_9);
  return;
}



/* 405379a8 FUN_405379a8 */

/* Boundary evidence: original MIPS .pdata 405379a8..40537a1f. Semantic name remains unreviewed. */

undefined4 FUN_405379a8(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(300);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_4053732c(puVar1,param_1);
  }
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = 0;
    uVar2 = 0x8007000e;
  }
  else {
    *param_2 = puVar1 + 0x11;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40537a20 FUN_40537a20 */

/* Boundary evidence: original MIPS .pdata 40537a20..40537cb7. Semantic name remains unreviewed. */

void FUN_40537a20(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  void *pvVar3;
  
  *param_1 = &PTR_FUN_40515c2c;
  param_1[5] = &PTR_LAB_40515b10;
  param_1[6] = &PTR_LAB_40515af8;
  param_1[7] = &PTR_LAB_40515adc;
  param_1[8] = &PTR_LAB_40515ac8;
  param_1[9] = &PTR_LAB_40515ab8;
  param_1[10] = &PTR_LAB_40515a98;
  param_1[0xb] = &PTR_LAB_40515a88;
  param_1[0xc] = &PTR_LAB_40515a74;
  param_1[0xd] = &PTR_LAB_40515a38;
  param_1[0xe] = &PTR_LAB_40515a24;
  param_1[0xf] = &PTR_LAB_40515a00;
  param_1[0x10] = &PTR_LAB_405159ec;
  param_1[0x14] = &PTR_LAB_405159cc;
  param_1[0x15] = &PTR_LAB_405159b8;
  param_1[0x16] = &PTR_LAB_4051599c;
  if ((HMODULE)param_1[0x47] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)param_1[0x47]);
  }
  FUN_4053f730((int)param_1,(int *)0x0,(int *)0x0);
  FUN_4053f8cc((int)param_1);
  piVar2 = (int *)param_1[0x3c];
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
    FUN_4053f65c((int)(param_1 + 10),(int *)0x0);
    (**(code **)(*piVar2 + 0x40))(piVar2,0);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_405370b8((int)(param_1 + 9),(undefined4 *)0x0);
  if ((HLOCAL)param_1[0x42] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x42]);
    param_1[0x42] = 0;
  }
  if ((HLOCAL)param_1[0x43] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x43]);
    param_1[0x43] = 0;
  }
  if ((int *)param_1[0x2a] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x2a] + 8))();
  }
  if ((HLOCAL)param_1[0x3d] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x3d]);
    param_1[0x3d] = 0;
  }
  if ((HLOCAL)param_1[0x3e] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x3e]);
    param_1[0x3e] = 0;
  }
  puVar1 = (undefined4 *)param_1[0x2d];
  param_1[0x2d] = 0;
  while (puVar1 != (void *)0x0) {
    pvVar3 = (void *)*puVar1;
    FUN_4053446c(puVar1,1);
    puVar1 = pvVar3;
  }
  InterlockedDecrement((LONG *)&DAT_4054471c);
  FUN_40516d74();
  param_1[0x49] = &PTR_FUN_405157f4;
  FUN_40541d6c();
  FUN_40530f9c(param_1 + 0x23);
  FUN_40530f9c(param_1 + 0x1d);
  FUN_40530f9c(param_1 + 0x17);
  FUN_4052f040(param_1 + 0x10);
  param_1[7] = &PTR_LAB_40511748;
  param_1[6] = &PTR_LAB_405154cc;
  FUN_4052f448(param_1);
  return;
}



/* 40537cb8 FUN_40537cb8 */

/* Boundary evidence: original MIPS .pdata 40537cb8..40537d03. Semantic name remains unreviewed. */

undefined4 * FUN_40537cb8(undefined4 *param_1,uint param_2)

{
  FUN_40537a20(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40537d04 FUN_40537d04 */

int FUN_40537d04(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (param_1 != (ushort *)0x0) {
    iVar1 = 2;
    for (; uVar2 = (uint)*param_1, uVar2 != 0; param_1 = (ushort *)(uVar2 + (int)param_1)) {
      iVar1 = uVar2 + iVar1;
    }
  }
  return iVar1;
}



/* 40537d44 FUN_40537d44 */

/* Boundary evidence: original MIPS .pdata 40537d44..40537d93. Semantic name remains unreviewed. */

void * FUN_40537d44(size_t param_1)

{
  void *_Dst;
  
  _Dst = (void *)FUN_4053f298(param_1);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,param_1);
  }
  return _Dst;
}



/* 40537d94 FUN_40537d94 */

undefined1 * FUN_40537d94(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = (undefined1 *)0x0;
  }
  else {
    uVar2 = *param_1;
    uVar1 = param_1[1];
    puVar4 = param_1;
    while (CONCAT11(uVar1,uVar2) != 0) {
      puVar3 = puVar4 + CONCAT11(uVar1,uVar2);
      uVar2 = *puVar3;
      param_1 = puVar4;
      puVar4 = puVar3;
      uVar1 = puVar3[1];
    }
  }
  return param_1;
}



/* 40537ddc FUN_40537ddc */

/* Boundary evidence: original MIPS .pdata 40537ddc..40537e33. Semantic name remains unreviewed. */

undefined4 FUN_40537ddc(char *param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0;
  if (param_1 == (char *)0x0) {
    uVar1 = 0;
  }
  else if (*param_1 != '\0' || param_1[1] != '\0') {
    puVar2 = FUN_40537d94(param_1);
    *puVar2 = 0;
    puVar2[1] = 0;
    uVar1 = 1;
  }
  return uVar1;
}



/* 40537e34 FUN_40537e34 */

/* Boundary evidence: original MIPS .pdata 40537e34..40537f63. Semantic name remains unreviewed. */

void * FUN_40537e34(ushort *param_1,ushort *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  size_t _Size;
  size_t _Size_00;
  ushort *puVar6;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = param_2;
    if (param_2 == (ushort *)0x0) {
      return (void *)0x0;
    }
  }
  else if (param_2 != (ushort *)0x0) {
    _Size_00 = 2;
    uVar2 = (undefined1)*param_1;
    iVar5 = 2;
    uVar1 = *(undefined1 *)((int)param_1 + 1);
    puVar6 = param_1;
    while (uVar4 = (uint)CONCAT11(uVar1,uVar2), uVar4 != 0) {
      puVar6 = (ushort *)(uVar4 + (int)puVar6);
      uVar2 = (undefined1)*puVar6;
      iVar5 = uVar4 + iVar5;
      uVar1 = *(undefined1 *)((int)puVar6 + 1);
    }
    uVar2 = (undefined1)*param_2;
    _Size = iVar5 - 2;
    uVar1 = *(undefined1 *)((int)param_2 + 1);
    puVar6 = param_2;
    while (uVar4 = (uint)CONCAT11(uVar1,uVar2), uVar4 != 0) {
      puVar6 = (ushort *)(uVar4 + (int)puVar6);
      uVar2 = (undefined1)*puVar6;
      _Size_00 = uVar4 + _Size_00;
      uVar1 = *(undefined1 *)((int)puVar6 + 1);
    }
    pvVar3 = FUN_40537d44(_Size_00 + _Size);
    if (pvVar3 == (void *)0x0) {
      return (void *)0x0;
    }
    memmove(pvVar3,param_1,_Size);
    memmove((void *)((int)pvVar3 + _Size),param_2,_Size_00);
    return pvVar3;
  }
  pvVar3 = FUN_4052d908(param_1);
  return pvVar3;
}



/* 40537f64 FUN_40537f64 */

/* Boundary evidence: original MIPS .pdata 40537f64..40537f87. Semantic name remains unreviewed. */

void FUN_40537f64(int param_1)

{
  if (param_1 != 0) {
    FUN_4053f2d4(param_1);
  }
  return;
}



/* 40537f88 FUN_40537f88 */

/* Boundary evidence: original MIPS .pdata 40537f88..4053804b. Semantic name remains unreviewed. */

undefined4 FUN_40537f88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *local_20;
  undefined1 auStack_1c [4];
  
  local_20 = (int *)0x0;
  uVar2 = 0x80004005;
  iVar1 = FUN_4053adec(&local_20);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*local_20 + 0xc))(local_20,0,0,param_1,auStack_1c,param_2,param_3);
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  return uVar2;
}



/* 4053804c FUN_4053804c */

/* Boundary evidence: original MIPS .pdata 4053804c..40538077. Semantic name remains unreviewed. */

void FUN_4053804c(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_2;
  *param_1 = piVar1;
  (**(code **)(*piVar1 + 4))(piVar1);
  return;
}



/* 40538078 FUN_40538078 */

/* Boundary evidence: original MIPS .pdata 40538078..40538133. Semantic name remains unreviewed. */

void FUN_40538078(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_40515c34;
  if ((int *)param_1[0xb] == (int *)0x0) {
    if (param_1[10] != 0) {
      if ((param_1[9] != 0) && (iVar1 = 0, 0 < (int)param_1[6])) {
        do {
          (**(code **)(**(int **)(param_1[7] * iVar1 + param_1[10]) + 8))();
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)param_1[6]);
      }
      LocalFree((HLOCAL)param_1[10]);
    }
  }
  else {
    (**(code **)(*(int *)param_1[0xb] + 8))();
  }
  return;
}



/* 40538134 FUN_40538134 */

/* Boundary evidence: original MIPS .pdata 40538134..405381cb. Semantic name remains unreviewed. */

undefined4 FUN_40538134(int *param_1,void *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  iVar1 = memcmp(param_2,param_1 + 2,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405162fc,0x10), iVar1 == 0)) &&
     (*param_3 = (int)param_1, param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 4))(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
  }
  return uVar2;
}



/* 405381cc FUN_405381cc */

/* Boundary evidence: original MIPS .pdata 405381cc..4053820b. Semantic name remains unreviewed. */

int FUN_405381cc(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return iVar1;
}



/* 4053820c FUN_4053820c */

/* Boundary evidence: original MIPS .pdata 4053820c..405382e7. Semantic name remains unreviewed. */

bool FUN_4053820c(int param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar2 = 0;
  iVar3 = iVar1 * *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28);
  if (param_2 != 0) {
    do {
      if (*(int *)(param_1 + 0x18) <= *(int *)(param_1 + 0x20)) break;
      (**(code **)(param_1 + 0x30))(param_3,iVar3,iVar1);
      iVar1 = *(int *)(param_1 + 0x1c);
      uVar2 = uVar2 + 1;
      param_3 = iVar1 + param_3;
      iVar3 = iVar1 + iVar3;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    } while (uVar2 < param_2);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar2;
  }
  return uVar2 < param_2;
}



/* 40538328 FUN_40538328 */

/* Boundary evidence: original MIPS .pdata 40538328..40538373. Semantic name remains unreviewed. */

undefined4 * FUN_40538328(undefined4 *param_1,uint param_2)

{
  FUN_40538078(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40538374 FUN_40538374 */

/* Boundary evidence: original MIPS .pdata 40538374..4053844b. Semantic name remains unreviewed. */

undefined4 *
FUN_40538374(undefined4 *param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5,
            int param_6,undefined4 param_7)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_40515c34;
  param_1[1] = 1;
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  param_1[6] = param_4;
  param_1[7] = param_5;
  param_1[8] = 0;
  param_1[9] = param_3;
  param_1[10] = param_6;
  param_1[0xc] = param_7;
  param_1[0xb] = 0;
  if (((param_3 != 0) && (param_6 != 0)) && (iVar1 = 0, 0 < param_4)) {
    do {
      (**(code **)(**(int **)(param_1[7] * iVar1 + param_1[10]) + 4))();
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)param_1[6]);
  }
  return param_1;
}



/* 4053844c FUN_4053844c */

/* Boundary evidence: original MIPS .pdata 4053844c..40538513. Semantic name remains unreviewed. */

undefined4 FUN_4053844c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_2 = 0;
    puVar2 = (undefined4 *)FUN_4052d4e8(0x34);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40538374(puVar2,param_1 + 2,param_1[9],param_1[6],param_1[7],param_1[10],
                            param_1[0xc]);
    }
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      puVar2[8] = param_1[8];
      puVar2[0xb] = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      *param_2 = puVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40538514 FUN_40538514 */

/* Boundary evidence: original MIPS .pdata 40538514..4053863f. Semantic name remains unreviewed. */

undefined4 FUN_40538514(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *hMem;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if ((param_2 <= param_2 << 2) &&
       (local_res8 = param_3, local_resc = param_4, hMem = LocalAlloc(0x40,param_2 << 2),
       hMem != (undefined4 *)0x0)) {
      puVar2 = &local_res8;
      puVar3 = hMem;
      for (uVar4 = param_2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar3 = *puVar2;
        puVar3 = puVar3 + 1;
        puVar2 = puVar2 + 1;
      }
      puVar2 = (undefined4 *)FUN_4052d4e8(0x34);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40538374(puVar2,(undefined4 *)&DAT_4051691c,1,param_2,4,(int)hMem,FUN_4053804c)
        ;
      }
      *param_1 = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        return 0;
      }
      LocalFree(hMem);
    }
    uVar1 = 0x8007000e;
  }
  return uVar1;
}



/* 40538640 FUN_40538640 */

/* Boundary evidence: original MIPS .pdata 40538640..405387db. Semantic name remains unreviewed. */

int FUN_40538640(IUnknown *param_1,void **param_2)

{
  HRESULT HVar1;
  ULONG UVar2;
  int iVar3;
  IUnknown *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  
  *param_2 = (void *)0x0;
  if (param_1 == (IUnknown *)0x0) {
    return -0x7fffbffb;
  }
  *param_2 = (void *)0x0;
  HVar1 = (*param_1->lpVtbl->QueryInterface)(param_1,(IID *)&UNK_4051692c,&local_20);
  if (HVar1 < 0) {
    HVar1 = IUnknown_QueryService(param_1,(GUID *)&DAT_4051654c,(IID *)&DAT_4051675c,param_2);
    return HVar1;
  }
  UVar2 = (*local_20->lpVtbl[1].Release)(local_20);
  if (-1 < (int)UVar2) {
    iVar3 = (**(code **)*local_1c)(local_1c,&DAT_4051675c,param_2);
    (**(code **)(*local_1c + 8))();
    if (-1 < iVar3) goto LAB_4053877c;
  }
  iVar3 = IUnknown_QueryService(local_20,(GUID *)&DAT_4051645c,(IID *)&DAT_405162cc,&local_14);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*local_14 + 0x48))(local_14,&local_18);
    if (-1 < iVar3) {
      iVar3 = (**(code **)*local_18)(local_18,&DAT_4051675c,param_2);
      (**(code **)(*local_18 + 8))();
    }
    (**(code **)(*local_14 + 8))();
  }
LAB_4053877c:
  (*local_20->lpVtbl->Release)(local_20);
  return iVar3;
}



/* 405387dc FUN_405387dc */

/* Boundary evidence: original MIPS .pdata 405387dc..4053884f. Semantic name remains unreviewed. */

undefined4 FUN_405387dc(undefined4 *param_1,LPCWSTR param_2)

{
  LPWSTR pWVar1;
  
  if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
    LocalFree((HLOCAL)*param_1);
    *param_1 = 0;
  }
  if (param_2 == (LPCWSTR)0x0) {
    *param_1 = 0;
  }
  else {
    pWVar1 = StrDupW(param_2);
    *param_1 = pWVar1;
    if (pWVar1 == (LPWSTR)0x0) {
      return 0x8007000e;
    }
  }
  return 0;
}



/* 40538850 FUN_40538850 */

/* Boundary evidence: original MIPS .pdata 40538850..405389b7. Semantic name remains unreviewed. */

undefined4 FUN_40538850(int param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  bool bVar2;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  wchar_t local_48 [26];
  uint local_14;
  
  local_14 = DAT_40544354;
  if ((((param_2 != (wchar_t *)0x0) && (sVar3 = wcslen(param_2), 1 < sVar3)) && (*param_2 == L'_'))
     && (param_2[1] == L'[')) {
    bVar2 = false;
    iVar5 = 2;
    do {
      wVar1 = param_2[iVar5];
      if ((wVar1 == L'\0') || (wVar1 == L']')) break;
      local_48[iVar5 + -2] = wVar1;
      if ((iVar5 != 2) || (param_2[2] != L'-')) {
        if ((!bVar2) && (0x2f < (ushort)wVar1)) {
          bVar2 = false;
          if ((ushort)wVar1 < 0x3a) goto LAB_4053892c;
        }
        bVar2 = true;
      }
LAB_4053892c:
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x18);
    local_48[iVar5 + -2] = L'\0';
    if ((((2 < iVar5) && (param_2[iVar5] == L']')) && (!bVar2)) &&
       (param_2 = param_2 + iVar5 + 1, *param_2 == L'\0')) {
      param_2 = (LPCWSTR)0x0;
    }
  }
  uVar4 = FUN_405387dc((undefined4 *)(param_1 + 0xd4),param_2);
  FUN_40542538(local_14);
  return uVar4;
}



/* 405389b8 FUN_405389b8 */

/* Boundary evidence: original MIPS .pdata 405389b8..405389f7. Semantic name remains unreviewed. */

HRESULT FUN_405389b8(int param_1,LPWSTR *param_2)

{
  HRESULT HVar1;
  
  if (*(LPCWSTR *)(param_1 + 0xd4) == (LPCWSTR)0x0) {
    HVar1 = 0;
    *param_2 = (LPWSTR)0x0;
  }
  else {
    HVar1 = SHStrDupW(*(LPCWSTR *)(param_1 + 0xd4),param_2);
  }
  return HVar1;
}



/* 405389f8 FUN_405389f8 */

/* Boundary evidence: original MIPS .pdata 405389f8..40538a83. Semantic name remains unreviewed. */

undefined4 FUN_405389f8(LPCWSTR param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_40515ca8;
  if (*param_1 == L'_') {
    do {
      iVar2 = StrCmpW(param_1,(LPCWSTR)puVar3[1]);
      if (iVar2 == 0) {
        return *puVar3;
      }
      piVar1 = puVar3 + 3;
      puVar3 = puVar3 + 2;
    } while (*piVar1 != 0);
  }
  return 0;
}



/* 40538a84 FUN_40538a84 */

/* Boundary evidence: original MIPS .pdata 40538a84..40538ab7. Semantic name remains unreviewed. */

void FUN_40538a84(IUnknown *param_1,IID *param_2,void **param_3)

{
  IUnknown_QueryService(param_1,(GUID *)&DAT_405164bc,param_2,param_3);
  return;
}



/* 40538ab8 FUN_40538ab8 */

/* Boundary evidence: original MIPS .pdata 40538ab8..40538b5f. Semantic name remains unreviewed. */

undefined4 FUN_40538ab8(LPCWSTR param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *local_18 [2];
  
  if (*param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    if (((param_1 != (LPCWSTR)0x0) && (iVar2 = FUN_405389f8(param_1), iVar2 == 0)) &&
       (iVar2 = (*(code *)**(undefined4 **)*param_2)((undefined4 *)*param_2,&DAT_405164bc,local_18),
       -1 < iVar2)) {
      (**(code **)(*local_18[0] + 0xc))(local_18[0],param_1);
      (**(code **)(*local_18[0] + 8))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40538b60 FUN_40538b60 */

/* Boundary evidence: original MIPS .pdata 40538b60..40538d1f. Semantic name remains unreviewed. */

int FUN_40538b60(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
  iVar1 = (**(code **)*param_2)(param_2,&DAT_4051675c,local_18);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_18[0] + 0x1b0))(local_18[0],&local_28);
    if (-1 < iVar1) {
      iVar1 = (**(code **)*local_28)(local_28,&UNK_405166fc,&local_1c);
      (**(code **)(*local_28 + 8))();
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_1c + 0x1c))(local_1c,param_3,&local_28);
        if (iVar1 == 0) {
          iVar1 = (**(code **)*local_28)(local_28,&DAT_4051642c,&local_20);
          if (iVar1 == 0) {
            iVar1 = (**(code **)(*local_20 + 0xc))(local_20,&DAT_4051645c,&DAT_4051645c,&local_24);
            if (iVar1 == 0) {
              *param_4 = local_24;
              (**(code **)(*local_24 + 4))();
              (**(code **)(*local_24 + 8))();
            }
            (**(code **)(*local_20 + 8))();
          }
          (**(code **)(*local_28 + 8))();
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 1;
        }
        (**(code **)(*local_1c + 8))();
      }
    }
    (**(code **)(*local_18[0] + 8))();
  }
  return iVar1;
}



/* 40538d20 FUN_40538d20 */

/* Boundary evidence: original MIPS .pdata 40538d20..40538d3b. Semantic name remains unreviewed. */

void FUN_40538d20(int param_1,LPCWSTR param_2)

{
  FUN_405387dc((undefined4 *)(param_1 + 0xd8),param_2);
  return;
}



/* 40538d3c FUN_40538d3c */

/* Boundary evidence: original MIPS .pdata 40538d3c..40538ecb. Semantic name remains unreviewed. */

int FUN_40538d3c(int *param_1,LPWSTR *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  code *pcVar5;
  void *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  
  *param_2 = (LPWSTR)0x0;
  local_20 = (void *)0x0;
  local_1c = (int *)0x0;
  local_18 = (int *)0x0;
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,&local_20);
  if (iVar1 != 0) goto LAB_40538e88;
  if ((local_20 != (void *)0x0) || (param_1[0x36] != 0)) {
    if ((LPCWSTR)param_1[0x36] == (LPCWSTR)0x0) {
      iVar1 = 0;
      *param_2 = (LPWSTR)0x0;
    }
    else {
      iVar1 = SHStrDupW((LPCWSTR)param_1[0x36],param_2);
    }
    goto LAB_40538e88;
  }
  *param_2 = (LPWSTR)0x0;
  piVar4 = (int *)param_1[0x29];
  iVar1 = 0;
  local_14 = (int *)0x0;
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x3c))(piVar4,&local_14);
  }
  piVar4 = local_14;
  if (local_14 == (int *)0x0) goto LAB_40538e88;
  iVar2 = FUN_4052d52c(local_14);
  if (iVar2 < 0) {
    iVar2 = FUN_4052d52c(piVar4);
    if (-1 < iVar2) {
      pcVar5 = *(code **)(*local_1c + 0x20);
      piVar3 = local_1c;
      goto LAB_40538e38;
    }
  }
  else {
    pcVar5 = *(code **)(*local_18 + 0xc);
    piVar3 = local_18;
LAB_40538e38:
    iVar1 = (*pcVar5)(piVar3,param_2);
  }
  (**(code **)(*piVar4 + 8))(piVar4);
LAB_40538e88:
  IUnknown_AtomicRelease(&local_20);
  IUnknown_AtomicRelease(&local_1c);
  IUnknown_AtomicRelease(&local_18);
  return iVar1;
}



/* 40538ecc FUN_40538ecc */

/* Boundary evidence: original MIPS .pdata 40538ecc..40538fd7. Semantic name remains unreviewed. */

undefined4 FUN_40538ecc(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  undefined4 uVar5;
  int *local_20;
  int *local_1c;
  int *local_18 [2];
  
  *param_2 = 0;
  piVar3 = *(int **)(param_1 + 0xa4);
  uVar5 = 0x80004005;
  local_1c = (int *)0x0;
  local_20 = (int *)0x0;
  local_18[0] = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x3c))(piVar3,local_18);
  }
  piVar3 = local_18[0];
  if (local_18[0] == (int *)0x0) goto LAB_40538fa0;
  iVar1 = FUN_4052d52c(local_18[0]);
  if (iVar1 < 0) {
    iVar1 = FUN_4052d52c(piVar3);
    if (-1 < iVar1) {
      pcVar4 = *(code **)(*local_1c + 0x24);
      piVar2 = local_1c;
      goto LAB_40538f84;
    }
  }
  else {
    pcVar4 = *(code **)(*local_20 + 0x10);
    piVar2 = local_20;
LAB_40538f84:
    uVar5 = (*pcVar4)(piVar2,param_2);
  }
  (**(code **)(*piVar3 + 8))(piVar3);
LAB_40538fa0:
  IUnknown_AtomicRelease(&local_20);
  IUnknown_AtomicRelease(&local_1c);
  return uVar5;
}



/* 40538fe4 FUN_40538fe4 */

/* Boundary evidence: original MIPS .pdata 40538fe4..405390b3. Semantic name remains unreviewed. */

undefined4 FUN_40538fe4(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  short local_20 [4];
  
  piVar3 = (int *)(param_1 + -0x20);
  *param_2 = *(uint *)(param_1 + 0xdc);
  iVar1 = (**(code **)(*piVar3 + 200))(piVar3,local_20);
  if (((iVar1 < 0) || (local_20[0] != -1)) &&
     ((iVar1 = (**(code **)(*piVar3 + 0x104))(piVar3,local_20), iVar1 < 0 || (local_20[0] != -1))))
  {
    if (*(int *)(param_1 + 0xb4) == *(int *)(param_1 + 0xa4)) goto LAB_40539088;
    uVar2 = *param_2 | 0x10;
  }
  else {
    uVar2 = *param_2 | 0x14;
  }
  *param_2 = uVar2;
LAB_40539088:
  *param_2 = *param_2 | 0x10;
  return 0;
}



/* 405390dc FUN_405390dc */

/* Boundary evidence: original MIPS .pdata 405390dc..405392df. Semantic name remains unreviewed. */

int FUN_405390dc(int *param_1,wchar_t *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *local_28;
  void *local_24;
  
  local_28 = (int *)0x0;
  local_24 = (void *)0x0;
  if ((param_2 == (wchar_t *)0x0) || (*param_2 == L'\0')) {
    param_2 = L"_self";
  }
  iVar1 = FUN_405389f8(param_2);
  if (iVar1 == 5) {
    param_2 = L"_self";
  }
  *param_4 = 0;
  if (((IUnknown *)param_1[0x29] == (IUnknown *)param_1[0x2d]) || (iVar1 != 5)) {
    iVar1 = (**(code **)param_1[-0xd])(param_1 + -0xd,&DAT_405163fc,&local_28);
  }
  else {
    iVar1 = IUnknown_QueryService
                      ((IUnknown *)param_1[0x2d],(GUID *)&DAT_405164bc,(IID *)&DAT_405163fc,
                       &local_28);
  }
  if (((-1 < iVar1) && (local_28 != (int *)0x0)) &&
     (iVar1 = (**(code **)*local_28)(local_28,&DAT_405162fc,&local_24), -1 < iVar1)) {
    iVar1 = (**(code **)(*local_28 + 0x10))(local_28,param_2,local_24,param_3,param_4);
  }
  IUnknown_AtomicRelease(&local_24);
  IUnknown_AtomicRelease(&local_28);
  if (((-1 < iVar1) && (*param_4 == 0)) && ((param_3 & 0x80000000) == 0)) {
    iVar1 = 1;
  }
  if (((DAT_4054458c == 1) && (iVar1 != 0)) && (iVar2 = StrCmpW(param_2,L"_top"), iVar2 != 0)) {
    iVar1 = (**(code **)(*param_1 + 0x34))(param_1,L"_top",param_3,param_4);
  }
  return iVar1;
}



/* 405392e0 FUN_405392e0 */

/* Boundary evidence: original MIPS .pdata 405392e0..4053930f. Semantic name remains unreviewed. */

void FUN_405392e0(int *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 0x10))(param_1,param_2,0,param_3 | 1,param_4);
  return;
}



/* 40539310 FUN_40539310 */

/* Boundary evidence: original MIPS .pdata 40539310..40539337. Semantic name remains unreviewed. */

void FUN_40539310(int param_1)

{
  (*(code *)**(undefined4 **)(param_1 + -0xa4))();
  return;
}



/* 40539338 FUN_40539338 */

/* Boundary evidence: original MIPS .pdata 40539338..40539363. Semantic name remains unreviewed. */

void FUN_40539338(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x90) + 4))();
  return;
}



/* 40539364 FUN_40539364 */

/* Boundary evidence: original MIPS .pdata 40539364..4053938f. Semantic name remains unreviewed. */

void FUN_40539364(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x90) + 8))();
  return;
}



/* 40539390 FUN_40539390 */

/* Boundary evidence: original MIPS .pdata 40539390..405393bb. Semantic name remains unreviewed. */

void FUN_40539390(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0xc))();
  return;
}



/* 405393bc FUN_405393bc */

/* Boundary evidence: original MIPS .pdata 405393bc..405393e7. Semantic name remains unreviewed. */

void FUN_405393bc(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x10))();
  return;
}



/* 405393e8 FUN_405393e8 */

/* Boundary evidence: original MIPS .pdata 405393e8..40539413. Semantic name remains unreviewed. */

void FUN_405393e8(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x14))();
  return;
}



/* 40539414 FUN_40539414 */

/* Boundary evidence: original MIPS .pdata 40539414..40539447. Semantic name remains unreviewed. */

void FUN_40539414(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x34))
            ((int *)(param_1 + -0x70),param_2,param_4 | 0x80000000,param_5);
  return;
}



/* 40539448 FUN_40539448 */

undefined4 FUN_40539448(void)

{
  return 0x80004005;
}



/* 40539454 FUN_40539454 */

/* Boundary evidence: original MIPS .pdata 40539454..4053947f. Semantic name remains unreviewed. */

void FUN_40539454(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x18))();
  return;
}



/* 40539480 FUN_40539480 */

/* Boundary evidence: original MIPS .pdata 40539480..405394ab. Semantic name remains unreviewed. */

void FUN_40539480(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x1c))();
  return;
}



/* 405394ac FUN_405394ac */

/* Boundary evidence: original MIPS .pdata 405394ac..405394d7. Semantic name remains unreviewed. */

void FUN_405394ac(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x20))();
  return;
}



/* 405394d8 FUN_405394d8 */

/* Boundary evidence: original MIPS .pdata 405394d8..40539503. Semantic name remains unreviewed. */

void FUN_405394d8(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x24))();
  return;
}



/* 40539504 FUN_40539504 */

/* Boundary evidence: original MIPS .pdata 40539504..4053952f. Semantic name remains unreviewed. */

void FUN_40539504(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x28))();
  return;
}



/* 40539530 FUN_40539530 */

/* Boundary evidence: original MIPS .pdata 40539530..4053955b. Semantic name remains unreviewed. */

void FUN_40539530(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x2c))();
  return;
}



/* 4053955c FUN_4053955c */

/* Boundary evidence: original MIPS .pdata 4053955c..40539587. Semantic name remains unreviewed. */

void FUN_4053955c(int param_1)

{
  (**(code **)(*(int *)(param_1 + -0x70) + 0x30))();
  return;
}



/* 40539588 FUN_40539588 */

/* Boundary evidence: original MIPS .pdata 40539588..405398a7. Semantic name remains unreviewed. */

int FUN_40539588(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int **ppunk;
  undefined4 *puVar2;
  int iVar3;
  int *local_38;
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  
  *param_3 = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x9c);
  local_38 = (int *)0x0;
  if (puVar2 == (undefined4 *)0x0) {
    return -0x7fffbffb;
  }
  iVar1 = (**(code **)*puVar2)(puVar2,&DAT_40513564,&local_30);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_30 + 0x60))();
    if (param_2 == iVar1) {
      *param_3 = local_30;
      return 0;
    }
    IUnknown_AtomicRelease(&local_30);
  }
  iVar1 = (**(code **)(*(int *)(param_1 + -8) + 0x20))((int *)(param_1 + -8),&local_38);
  if (iVar1 < 0) {
    return -0x7fffbffb;
  }
  if (local_38 == (int *)0x0) {
    return -0x7fffbffb;
  }
  local_34 = (int *)0x0;
  iVar3 = -0x7fffbffb;
  iVar1 = (**(code **)(*local_38 + 0x10))(local_38,1,&local_34);
  if ((iVar1 == 0) && (local_34 != (int *)0x0)) {
    iVar1 = (**(code **)(*local_34 + 0xc))(local_34,1,&local_2c,0);
    if (iVar1 == 0) {
      do {
        if (local_2c == (undefined4 *)0x0) break;
        iVar1 = (**(code **)*local_2c)(local_2c,&DAT_405163fc,&local_1c);
        if (-1 < iVar1) {
          iVar3 = (**(code **)(*local_1c + 0x20))(local_1c,param_2,param_3);
          IUnknown_AtomicRelease(&local_1c);
        }
        IUnknown_AtomicRelease(&local_2c);
        if (-1 < iVar3) goto LAB_4053980c;
        iVar1 = (**(code **)(*local_34 + 0xc))(local_34,1,&local_2c,0);
      } while (iVar1 == 0);
      if (iVar3 < 0) goto LAB_40539730;
    }
    else {
LAB_40539730:
      local_28 = (int *)0x0;
      local_24 = (int *)0x0;
      local_20 = (undefined4 *)0x0;
      local_1c = (int *)0x0;
      iVar1 = (**(code **)*local_38)(local_38,&DAT_4051675c,&local_28);
      if ((((-1 < iVar1) &&
           (iVar1 = (**(code **)(*local_28 + 0x1b0))(local_28,&local_24), -1 < iVar1)) &&
          (iVar1 = (**(code **)(*local_24 + 0x7c))(local_24,&local_20), -1 < iVar1)) &&
         (iVar1 = (**(code **)*local_20)(local_20,&DAT_405136b4,&local_1c), -1 < iVar1)) {
        iVar3 = (**(code **)(*local_1c + 0xc))(local_1c,param_2,param_3);
      }
      IUnknown_AtomicRelease(&local_28);
      IUnknown_AtomicRelease(&local_24);
      IUnknown_AtomicRelease(&local_20);
      IUnknown_AtomicRelease(&local_1c);
    }
LAB_4053980c:
    ppunk = &local_34;
  }
  else {
    local_1c = (int *)0x0;
    iVar1 = (**(code **)*local_38)(local_38,&DAT_405136b4,&local_1c);
    if (iVar1 < 0) goto LAB_40539868;
    iVar3 = (**(code **)(*local_1c + 0xc))(local_1c,param_2,param_3);
    ppunk = &local_1c;
  }
  IUnknown_AtomicRelease(ppunk);
LAB_40539868:
  IUnknown_AtomicRelease(&local_38);
  return iVar3;
}



/* 405398a8 FUN_405398a8 */

/* Boundary evidence: original MIPS .pdata 405398a8..405399b7. Semantic name remains unreviewed. */

int FUN_405398a8(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int *local_20;
  IUnknown *local_1c;
  void *local_18 [2];
  
  piVar1 = *(int **)(param_1 + 0xa8);
  iVar2 = 0;
  local_20 = (int *)0x0;
  local_1c = (IUnknown *)0x0;
  local_18[0] = (void *)0x0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,&local_20);
    if ((local_20 != (int *)0x0) &&
       (iVar2 = (**(code **)(*local_20 + 0x10))(local_20,&local_1c), -1 < iVar2)) {
      (**(code **)(*local_20 + 8))();
      local_20 = (int *)0x0;
      if (local_1c == (IUnknown *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = IUnknown_QueryService(local_1c,(GUID *)&DAT_405164bc,(IID *)&DAT_405162fc,local_18);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        IUnknown_AtomicRelease(&local_1c);
      }
    }
  }
  IUnknown_AtomicRelease(&local_20);
  IUnknown_AtomicRelease(&local_1c);
  *param_2 = local_18[0];
  return iVar2;
}



/* 405399b8 FUN_405399b8 */

/* Boundary evidence: original MIPS .pdata 405399b8..40539a77. Semantic name remains unreviewed. */

int FUN_405399b8(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *local_18;
  uint local_14;
  
  iVar1 = FUN_405398a8(param_1 + -0x34,param_2);
  if (((-1 < iVar1) && (puVar3 = (undefined4 *)*param_2, puVar3 != (undefined4 *)0x0)) &&
     (iVar2 = (**(code **)*puVar3)(puVar3,&DAT_405164bc,&local_18), -1 < iVar2)) {
    (**(code **)(*local_18 + 0x28))(local_18,&local_14);
    if ((local_14 & 0x20) != 0) {
      (**(code **)(*(int *)*param_2 + 8))();
      *param_2 = 0;
    }
    (**(code **)(*local_18 + 8))();
  }
  return iVar1;
}



/* 40539a78 FUN_40539a78 */

/* Boundary evidence: original MIPS .pdata 40539a78..40539efb. Semantic name remains unreviewed. */

int FUN_40539a78(undefined4 *param_1,LPCWSTR param_2,void *param_3,uint param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  int *piVar4;
  int *local_58;
  void *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  void *local_44;
  int *local_40;
  void *local_3c;
  int *local_38;
  undefined4 *local_34;
  int local_30;
  void *local_2c;
  
  *param_5 = 0;
  local_34 = (undefined4 *)0x0;
  local_2c = (void *)0x0;
  local_38 = (int *)0x0;
  local_54 = (void *)0x0;
  local_58 = (int *)0x0;
  local_44 = (void *)0x0;
  local_50 = (int *)0x0;
  local_4c = (int *)0x0;
  local_40 = (int *)0x0;
  local_3c = (void *)0x0;
  local_48 = (int *)0x0;
  iVar1 = (**(code **)*param_1)(param_1,&DAT_405162fc,&local_54);
  if (iVar1 < 0) goto LAB_40539e40;
  if (((LPCWSTR)param_1[0x42] != (LPCWSTR)0x0) &&
     (iVar2 = StrCmpW(param_2,(LPCWSTR)param_1[0x42]), iVar2 == 0)) {
    *param_5 = (int)local_54;
    local_54 = (void *)0x0;
    goto LAB_40539e40;
  }
  piVar4 = param_1 + 0xd;
  iVar2 = (**(code **)(*piVar4 + 0x20))(piVar4,&local_4c);
  if ((-1 < iVar2) && (local_4c != (int *)0x0)) {
    iVar1 = (**(code **)(*local_4c + 0x10))(local_4c,1,&local_40);
    if ((iVar1 != 0) || (local_40 == (int *)0x0)) goto LAB_40539e40;
    (**(code **)(*local_40 + 0xc))(local_40,1,&local_58,0);
    while (local_58 != (int *)0x0) {
      iVar1 = (**(code **)*local_58)(local_58,&DAT_405163fc,&local_50);
      if ((-1 < iVar1) &&
         ((iVar1 = (**(code **)*local_50)(local_50,&DAT_405162fc,&local_44), iVar1 < 0 ||
          ((local_44 != param_3 &&
           ((iVar1 = (**(code **)(*local_50 + 0xc))(local_50,param_2,param_4,param_5), iVar1 != 0 ||
            (*param_5 != 0)))))))) goto LAB_40539e40;
      (**(code **)(*local_58 + 8))();
      local_58 = (int *)0x0;
      IUnknown_AtomicRelease(&local_44);
      IUnknown_AtomicRelease(&local_50);
      (**(code **)(*local_40 + 0xc))(local_40,1,&local_58,0);
    }
    iVar1 = 0;
  }
  local_30 = 0;
  if ((((*param_5 == 0) && (local_4c != (int *)0x0)) &&
      (iVar1 = FUN_40538b60(param_1,local_4c,param_2,param_5,&local_30), iVar1 == 0)) ||
     ((iVar2 = local_30, param_3 == (void *)0x0 ||
      (iVar1 = (**(code **)(*piVar4 + 0x14))(piVar4,&local_34), iVar1 != 0)))) goto LAB_40539e40;
  if (local_34 != (undefined4 *)0x0) {
    iVar1 = (**(code **)*local_34)(local_34,&DAT_405163fc,&local_38);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_38 + 0x10))(local_38,param_2,local_54,param_4,param_5);
    }
    goto LAB_40539e40;
  }
  *param_5 = 0;
  if ((IUnknown *)param_1[0x36] == (IUnknown *)param_1[0x3a]) {
    if (((param_4 & 0x80000000) != 0) || (iVar2 != 0)) goto LAB_40539e24;
  }
  else {
    HVar3 = IUnknown_QueryService
                      ((IUnknown *)param_1[0x3a],(GUID *)&DAT_405164bc,(IID *)&DAT_405163fc,
                       &local_48);
    if ((-1 < HVar3) &&
       (((local_48 != (int *)0x0 &&
         (iVar1 = (**(code **)*local_48)(local_48,&DAT_405162fc,&local_3c), -1 < iVar1)) &&
        (iVar1 = (**(code **)(*local_48 + 0x10))(local_48,param_2,local_3c,param_4,param_5),
        *param_5 != 0)))) goto LAB_40539e40;
LAB_40539e24:
    if ((param_4 & 1) != 0) {
      iVar1 = 0;
      goto LAB_40539e40;
    }
  }
  iVar1 = -0x7fffbffb;
LAB_40539e40:
  IUnknown_AtomicRelease(&local_3c);
  IUnknown_AtomicRelease(&local_48);
  IUnknown_AtomicRelease(&local_54);
  IUnknown_AtomicRelease(&local_2c);
  IUnknown_AtomicRelease(&local_38);
  IUnknown_AtomicRelease(&local_34);
  IUnknown_AtomicRelease(&local_44);
  IUnknown_AtomicRelease(&local_50);
  IUnknown_AtomicRelease(&local_40);
  IUnknown_AtomicRelease(&local_4c);
  IUnknown_AtomicRelease(&local_58);
  return iVar1;
}



/* 40539efc FUN_40539efc */

/* Boundary evidence: original MIPS .pdata 40539efc..40539ff7. Semantic name remains unreviewed. */

undefined4 FUN_40539efc(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_18;
  uint local_14;
  
  uVar3 = 0;
  iVar2 = FUN_405398a8(param_1,&local_18);
  piVar1 = local_18;
  if ((iVar2 < 0) || (local_18 == (int *)0x0)) {
    if (((*(uint *)(param_1 + 0x110) & 0x40) != 0) &&
       (uVar3 = 1, *(int *)(param_1 + 0xd8) != *(int *)(param_1 + 0xe8))) {
      uVar3 = 0;
    }
  }
  else {
    iVar2 = (**(code **)*local_18)(local_18,&DAT_405164bc,&local_18);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_18 + 0x28))(local_18,&local_14);
      if ((-1 < iVar2) && (uVar3 = 1, (local_14 & 0x20) == 0)) {
        uVar3 = 0;
      }
      (**(code **)(*local_18 + 8))();
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar3;
}



/* 40539ff8 FUN_40539ff8 */

/* Boundary evidence: original MIPS .pdata 40539ff8..4053a057. Semantic name remains unreviewed. */

HRESULT FUN_40539ff8(int param_1,int param_2,LPWSTR *param_3)

{
  int iVar1;
  HRESULT HVar2;
  
  if ((param_2 == 0) && (iVar1 = FUN_40539efc(param_1 + -0x34), iVar1 != 0)) {
    HVar2 = SHStrDupW(L"_desktop",param_3);
  }
  else {
    *param_3 = (LPWSTR)0x0;
    HVar2 = -0x7fffbffb;
  }
  return HVar2;
}



/* 4053a058 FUN_4053a058 */

/* Boundary evidence: original MIPS .pdata 4053a058..4053a233. Semantic name remains unreviewed. */

int FUN_4053a058(int param_1,LPCWSTR param_2,void *param_3,uint param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_28;
  undefined4 *local_24;
  int *local_20;
  void *local_1c;
  
  local_24 = (undefined4 *)0x0;
  local_1c = (void *)0x0;
  local_20 = (int *)0x0;
  local_28 = (void *)0x0;
  iVar1 = FUN_405389f8(param_2);
  puVar3 = (undefined4 *)(param_1 + -0x3c);
  if (iVar1 == 0) {
    iVar2 = FUN_40539a78(puVar3,param_2,param_3,param_4,param_5);
    goto LAB_4053a1dc;
  }
  iVar2 = (**(code **)*puVar3)(puVar3,&DAT_405162fc,&local_28);
  if (iVar1 == 1) {
    *param_5 = (int)local_28;
  }
  else {
    iVar2 = (**(code **)(*(int *)(param_1 + -8) + 0x14))((int *)(param_1 + -8),&local_24);
    if (iVar2 != 0) goto LAB_4053a1dc;
    if (local_24 != (undefined4 *)0x0) {
      if (iVar1 == 2) {
        *param_5 = (int)local_24;
        local_24 = (undefined4 *)0x0;
      }
      else {
        iVar2 = (**(code **)*local_24)(local_24,&DAT_405163fc,&local_20);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(*local_20 + 0x10))(local_20,param_2,local_28,param_4,param_5);
        }
      }
      goto LAB_4053a1dc;
    }
    if ((iVar1 != 2) && (iVar1 != 4)) {
      if ((param_4 & 1) == 0) {
        iVar2 = -0x7fffbffb;
      }
      else {
        iVar2 = 0;
      }
      *param_5 = 0;
      goto LAB_4053a1dc;
    }
    *param_5 = (int)local_28;
  }
  local_28 = (void *)0x0;
LAB_4053a1dc:
  IUnknown_AtomicRelease(&local_28);
  IUnknown_AtomicRelease(&local_1c);
  IUnknown_AtomicRelease(&local_20);
  IUnknown_AtomicRelease(&local_24);
  return iVar2;
}



/* 4053a234 FUN_4053a234 */

/* Boundary evidence: original MIPS .pdata 4053a234..4053a2f7. Semantic name remains unreviewed. */

void FUN_4053a234(undefined4 *param_1)

{
  IUnknown **ppunk;
  HDSA hdsa;
  int iVar1;
  int i;
  
  *param_1 = &PTR_LAB_40513e08;
  i = 0;
  while( true ) {
    hdsa = (HDSA)param_1[1];
    if (hdsa == (HDSA)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)hdsa;
    }
    if (iVar1 <= i) break;
    if (hdsa == (HDSA)0x0) {
      ppunk = (IUnknown **)0x0;
    }
    else {
      ppunk = DSA_GetItemPtr(hdsa,i);
    }
    if (ppunk != (IUnknown **)0x0) {
      IUnknown_Set(ppunk,(IUnknown *)0x0);
    }
    i = i + 1;
  }
  DSA_Destroy((HDSA)param_1[1]);
  return;
}



/* 4053a2f8 FUN_4053a2f8 */

/* Boundary evidence: original MIPS .pdata 4053a2f8..4053a3ff. Semantic name remains unreviewed. */

undefined4 FUN_4053a2f8(int param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  HDSA p_Var1;
  int iVar2;
  undefined4 uVar3;
  int *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  uint local_20;
  
  local_20 = DAT_40544354;
  if (*(int *)(param_1 + 4) == 0) {
    p_Var1 = DSA_Create(0x18,4);
    *(HDSA *)(param_1 + 4) = p_Var1;
  }
  local_34 = *param_2;
  local_30 = param_2[1];
  local_2c = param_2[2];
  local_28 = param_2[3];
  local_24 = *(int *)(param_1 + 8) + 1;
  *(int *)(param_1 + 8) = local_24;
  local_38 = param_3;
  if ((*(HDSA *)(param_1 + 4) == (HDSA)0x0) ||
     (iVar2 = DSA_InsertItem(*(HDSA *)(param_1 + 4),0x7fffffff,&local_38), iVar2 == -1)) {
    uVar3 = 0x8007000e;
  }
  else {
    (**(code **)(*param_3 + 4))(param_3);
    uVar3 = 0;
    *param_4 = local_24;
  }
  FUN_40542538(local_20);
  return uVar3;
}



/* 4053a400 FUN_4053a400 */

/* Boundary evidence: original MIPS .pdata 4053a400..4053a4e3. Semantic name remains unreviewed. */

undefined4 FUN_4053a400(int param_1,IUnknown *param_2)

{
  IUnknown **ppunk;
  HDSA hdsa;
  int iVar1;
  int i;
  
  i = 0;
  while( true ) {
    hdsa = *(HDSA *)(param_1 + 4);
    if (hdsa == (HDSA)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)hdsa;
    }
    if (iVar1 <= i) {
      return 0x80070057;
    }
    if (hdsa == (HDSA)0x0) {
      ppunk = (IUnknown **)0x0;
    }
    else {
      ppunk = DSA_GetItemPtr(hdsa,i);
    }
    if ((ppunk != (IUnknown **)0x0) && (ppunk[5] == param_2)) break;
    i = i + 1;
  }
  IUnknown_Set(ppunk,(IUnknown *)0x0);
  DSA_DeleteItem(*(HDSA *)(param_1 + 4),i);
  return 0;
}



/* 4053a4e4 FUN_4053a4e4 */

/* Boundary evidence: original MIPS .pdata 4053a4e4..4053a5eb. Semantic name remains unreviewed. */

undefined4 FUN_4053a4e4(int param_1,void *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HDSA hdsa;
  int iVar3;
  int i;
  
  *param_4 = 0;
  i = 0;
  while( true ) {
    hdsa = *(HDSA *)(param_1 + 4);
    if (hdsa == (HDSA)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)hdsa;
    }
    if (iVar3 <= i) {
      return 0x80004005;
    }
    if (hdsa == (HDSA)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = DSA_GetItemPtr(hdsa,i);
    }
    if ((puVar1 != (undefined4 *)0x0) && (iVar3 = memcmp(puVar1 + 1,param_2,0x10), iVar3 == 0))
    break;
    i = i + 1;
  }
  uVar2 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,param_2,param_3,param_4);
  return uVar2;
}



/* 4053a5ec FUN_4053a5ec */

/* Boundary evidence: original MIPS .pdata 4053a5ec..4053a817. Semantic name remains unreviewed. */

int FUN_4053a5ec(IUnknown *param_1,undefined4 param_2)

{
  HRESULT HVar1;
  int iVar2;
  int iVar3;
  int local_48;
  int *local_44;
  LPCWSTR local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  undefined1 auStack_30 [4];
  uint local_2c;
  
  iVar3 = 0;
  local_40 = (LPCWSTR)0x0;
  HVar1 = (*param_1->lpVtbl->QueryInterface)(param_1,(IID *)&UNK_4051693c,&local_3c);
  if (-1 < HVar1) {
    iVar2 = (**(code **)(*local_3c + 0x10))(local_3c,auStack_30);
    if ((-1 < iVar2) && ((local_2c & 0x800000) == 0)) {
      iVar3 = 1;
    }
    (**(code **)(*local_3c + 8))();
    if (iVar3 != 0) goto LAB_4053a7c4;
  }
  iVar2 = FUN_40538640(param_1,&local_34);
  if (iVar2 < 0) goto LAB_4053a7c4;
  iVar2 = (**(code **)(*local_34 + 0xa0))(local_34,&local_40);
  if (-1 < iVar2) {
    HVar1 = IUnknown_QueryService(param_1,(GUID *)&DAT_405167ac,(IID *)&DAT_405167ac,&local_44);
    if (HVar1 < 0) {
      iVar2 = FUN_40516d94((IID *)&DAT_4051679c,(LPUNKNOWN)0x0,1,(IID *)&DAT_405167ac,&local_44);
      if (iVar2 < 0) goto LAB_4053a7b0;
    }
    local_48 = 4;
    local_38 = 0;
    if (((local_40 == (LPCWSTR)0x0) || (iVar3 = FUN_4052e864(local_40), iVar3 != 0)) ||
       (iVar3 = (**(code **)(*local_44 + 0x14))(local_44,local_40,&local_48,0), iVar3 < 0)) {
      local_48 = 4;
    }
    iVar2 = (**(code **)(*local_44 + 0x14))(local_44,param_2,&local_38,0);
    iVar3 = 0;
    if (-1 < iVar2) {
      iVar3 = local_38;
    }
    if (((iVar3 != 0) || (local_48 == 0)) || ((local_48 == 1 || (iVar3 = 0, local_48 == 2)))) {
      iVar3 = 1;
    }
  }
LAB_4053a7b0:
  (**(code **)(*local_34 + 8))();
LAB_4053a7c4:
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  if (local_40 != (BSTR)0x0) {
    SysFreeString(local_40);
  }
  return iVar3;
}



/* 4053a818 FUN_4053a818 */

/* Boundary evidence: original MIPS .pdata 4053a818..4053abd7. Semantic name remains unreviewed. */

int FUN_4053a818(wchar_t *param_1,uint param_2,size_t param_3,STRSAFE_LPWSTR param_4,
                undefined4 *param_5,uint *param_6)

{
  BOOL BVar1;
  HRESULT HVar2;
  DWORD *pDVar3;
  code *pcVar4;
  DWORD cchOut;
  int iVar5;
  uint uVar6;
  DWORD local_c0;
  DWORD local_bc;
  wchar_t awStack_b8 [66];
  LPCWSTR local_34;
  DWORD local_30;
  uint local_2c;
  
  local_2c = DAT_40544354;
  FUN_4053b45c(awStack_b8);
  uVar6 = 0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  BVar1 = PathIsURLW(param_1);
  if (BVar1 != 0) {
    local_bc = 0x824;
    if (((param_2 & 0x10) == 0x10) && (HVar2 = UrlFixupW(param_1,param_4,0x824), HVar2 == 0)) {
      uVar6 = 1;
      param_1 = param_4;
    }
    if ((param_2 & 8) == 0) {
      if (param_4 != param_1) {
        StringCchCopyW(param_4,param_3,param_1);
      }
    }
    else {
      UrlCanonicalizeW(param_1,param_4,&local_bc,0);
    }
    iVar5 = 0;
    goto LAB_4053ab7c;
  }
  if (((param_2 & 4) == 4) ||
     (((*param_1 != L'\\' && (param_1[1] != L':')) && (param_1[1] != L'|')))) {
    iVar5 = FUN_4053b4c8(awStack_b8,0x824);
    if (iVar5 < 0) goto LAB_4053ab7c;
    local_c0 = local_30;
    if (local_34 == (LPWSTR)0x0) {
      local_c0 = 0;
    }
    if ((param_2 & 1) == 1) {
      iVar5 = UrlApplySchemeW(param_1,local_34,&local_c0,2);
    }
    if (iVar5 == 1) {
      if ((param_2 & 0x10) == 0x10) {
        cchOut = local_30;
        if (local_34 == (LPWSTR)0x0) {
          cchOut = 0;
        }
        iVar5 = UrlFixupW(param_1,local_34,cchOut);
        uVar6 = (uint)(iVar5 == 0);
        if (iVar5 != 1) goto LAB_4053ab28;
      }
      if ((param_2 & 2) == 2) {
        local_c0 = local_30;
        if (local_34 == (LPWSTR)0x0) {
          local_c0 = 0;
        }
        iVar5 = UrlApplySchemeW(param_1,local_34,&local_c0,1);
        if (iVar5 != 1) goto LAB_4053ab28;
      }
      iVar5 = -0x7ffbefff;
      goto LAB_4053ab7c;
    }
LAB_4053ab28:
    if ((param_2 & 8) != 0) {
      local_bc = local_30;
      if (local_34 == (STRSAFE_LPCWSTR)0x0) {
        local_bc = 0;
      }
      pDVar3 = &local_bc;
      pcVar4 = UrlCanonicalizeW_exref;
      goto LAB_4053ab54;
    }
  }
  else {
    iVar5 = FUN_4053b670(awStack_b8,param_1,0xffffffff);
    if ((iVar5 < 0) || (iVar5 = FUN_4053b4c8(awStack_b8,0x104), iVar5 < 0)) goto LAB_4053ab7c;
    if (local_34 == (LPCWSTR)0x0) {
      local_c0 = 0;
    }
    else {
      local_c0 = local_30;
    }
    iVar5 = UrlCreateFromPathW(local_34,local_34,&local_c0,0);
    if (iVar5 == -0x7fffbffd) {
      iVar5 = FUN_4053b4c8(awStack_b8,local_c0);
      if (iVar5 < 0) goto LAB_4053ab7c;
      if (local_34 == (STRSAFE_LPCWSTR)0x0) {
        local_c0 = 0;
      }
      else {
        local_c0 = local_30;
      }
      pDVar3 = &local_c0;
      pcVar4 = UrlCreateFromPathW_exref;
LAB_4053ab54:
      iVar5 = (*pcVar4)(local_34,local_34,pDVar3,0);
    }
  }
  if (-1 < iVar5) {
    StringCchCopyW(param_4,param_3,local_34);
  }
LAB_4053ab7c:
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar6;
  }
  FUN_4053b474(awStack_b8);
  FUN_40542538(local_2c);
  return iVar5;
}



/* 4053abd8 FUN_4053abd8 */

/* Boundary evidence: original MIPS .pdata 4053abd8..4053ac07. Semantic name remains unreviewed. */

void FUN_4053abd8(wchar_t *param_1,uint param_2,STRSAFE_LPWSTR param_3,undefined4 *param_4,
                 uint *param_5)

{
  FUN_4053a818(param_1,param_2,0x824,param_3,param_4,param_5);
  return;
}



/* 4053ac08 FUN_4053ac08 */

/* Boundary evidence: original MIPS .pdata 4053ac08..4053ad2b. Semantic name remains unreviewed. */

int FUN_4053ac08(ushort *param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  int iVar2;
  int *local_130;
  undefined4 local_12c;
  undefined1 auStack_128 [264];
  uint local_20;
  
  local_20 = DAT_40544354;
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 0;
  }
  iVar1 = FUN_40541718();
  iVar2 = FUN_4052ec70(param_1,&DAT_405165ac,(int *)&local_130,&local_12c);
  if (-1 < iVar2) {
    if (param_3 != (undefined2 *)0x0) {
      (**(code **)(*local_130 + 0x2c))(local_130,local_12c,param_2,auStack_128);
      iVar2 = -0x7fffbfff;
    }
    if ((-1 < iVar2) && (param_5 != 0)) {
      iVar2 = (**(code **)(*local_130 + 0x24))(local_130,1,&local_12c,param_5);
    }
    (**(code **)(*local_130 + 8))();
  }
  if (-1 < iVar1) {
    CoUninitialize();
  }
  FUN_40542538(local_20);
  return iVar2;
}



/* 4053ad2c FUN_4053ad2c */

/* Boundary evidence: original MIPS .pdata 4053ad2c..4053ad77. Semantic name remains unreviewed. */

undefined4 FUN_4053ad2c(LPCWSTR param_1)

{
  HRESULT HVar1;
  PARSEDURLW local_20;
  
  if (param_1 != (LPCWSTR)0x0) {
    local_20.cbSize = 0x18;
    HVar1 = ParseURLW(param_1,&local_20);
    if (-1 < HVar1) {
      return local_20.nScheme;
    }
  }
  return 0xffffffff;
}



/* 4053ad78 FUN_4053ad78 */

/* Boundary evidence: original MIPS .pdata 4053ad78..4053adeb. Semantic name remains unreviewed. */

void FUN_4053ad78(int *param_1,LPCWSTR param_2,int *param_3,undefined4 param_4)

{
  HMODULE pHVar1;
  int iVar2;
  
  if (*param_3 == 0) {
    if (*param_1 == 0) {
      pHVar1 = LoadLibraryW(param_2);
      *param_1 = (int)pHVar1;
      if (pHVar1 == (HMODULE)0x0) {
        return;
      }
    }
    iVar2 = GetProcAddressW(*param_1,param_4);
    *param_3 = iVar2;
  }
  return;
}



/* 4053adec FUN_4053adec */

/* Boundary evidence: original MIPS .pdata 4053adec..4053ae63. Semantic name remains unreviewed. */

undefined4 FUN_4053adec(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_4053ad78((int *)&DAT_40544720,L"ceshell.dll",(int *)&DAT_40544724,L"SHGetDesktopFolder");
  if (DAT_40544724 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_40544724)(param_1);
  }
  return uVar1;
}



/* 4053ae64 FUN_4053ae64 */

/* Boundary evidence: original MIPS .pdata 4053ae64..4053aef7. Semantic name remains unreviewed. */

undefined4 FUN_4053ae64(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054472c,L"wininet.dll",(int *)&DAT_4054473c,L"InternetGoOnlineW");
  if (DAT_4054473c == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_4054473c)(param_1,param_2,param_3);
  }
  return uVar1;
}



/* 4053aef8 FUN_4053aef8 */

/* Boundary evidence: original MIPS .pdata 4053aef8..4053af9b. Semantic name remains unreviewed. */

undefined4 FUN_4053aef8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054472c,L"wininet.dll",(int *)&DAT_40544740,L"InternetQueryOptionA");
  if (DAT_40544740 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_40544740)(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 4053af9c FUN_4053af9c */

/* Boundary evidence: original MIPS .pdata 4053af9c..4053b03f. Semantic name remains unreviewed. */

undefined4 FUN_4053af9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054472c,L"wininet.dll",(int *)&DAT_40544744,L"InternetConfirmZoneCrossingW");
  if (DAT_40544744 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_40544744)(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 4053b040 FUN_4053b040 */

/* Boundary evidence: original MIPS .pdata 4053b040..4053b0e3. Semantic name remains unreviewed. */

undefined4 FUN_4053b040(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054472c,L"wininet.dll",(int *)&DAT_40544770,L"InternetSetOptionW");
  if (DAT_40544770 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*DAT_40544770)(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 4053b0e4 FUN_4053b0e4 */

/* Boundary evidence: original MIPS .pdata 4053b0e4..4053b17b. Semantic name remains unreviewed. */

undefined4 FUN_4053b0e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054477c,L"urlmon.dll",(int *)&DAT_40544780,L"CreateURLMoniker");
  if (DAT_40544780 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_40544780)(param_1,param_2,param_3);
  }
  return uVar1;
}



/* 4053b17c FUN_4053b17c */

/* Boundary evidence: original MIPS .pdata 4053b17c..4053b233. Semantic name remains unreviewed. */

undefined4
FUN_4053b17c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054477c,L"urlmon.dll",(int *)&DAT_40544784,L"CreateAsyncBindCtxEx");
  if (DAT_40544784 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_40544784)(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar1;
}



/* 4053b234 FUN_4053b234 */

/* Boundary evidence: original MIPS .pdata 4053b234..4053b2f3. Semantic name remains unreviewed. */

undefined4
FUN_4053b234(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054477c,L"urlmon.dll",(int *)&DAT_40544798,L"CoInternetQueryInfo");
  if (DAT_40544798 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_40544798)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}



/* 4053b2f4 FUN_4053b2f4 */

/* Boundary evidence: original MIPS .pdata 4053b2f4..4053b3b3. Semantic name remains unreviewed. */

undefined4
FUN_4053b2f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054477c,L"urlmon.dll",(int *)&DAT_405447a4,L"CoInternetParseUrl");
  if (DAT_405447a4 == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_405447a4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}



/* 4053b3b4 FUN_4053b3b4 */

/* Boundary evidence: original MIPS .pdata 4053b3b4..4053b45b. Semantic name remains unreviewed. */

undefined4 FUN_4053b3b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_4053ad78(&DAT_4054477c,L"urlmon.dll",(int *)&DAT_405447ac,L"FaultInIEFeature");
  if (DAT_405447ac == (code *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (*DAT_405447ac)(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 4053b45c FUN_4053b45c */

undefined2 * FUN_4053b45c(undefined2 *param_1)

{
  *param_1 = 0;
  *(undefined2 **)(param_1 + 0x42) = param_1;
  *(undefined4 *)(param_1 + 0x44) = 0x41;
  return param_1;
}



/* 4053b474 FUN_4053b474 */

/* Boundary evidence: original MIPS .pdata 4053b474..4053b4c7. Semantic name remains unreviewed. */

void FUN_4053b474(undefined2 *param_1)

{
  if ((*(HLOCAL *)(param_1 + 0x42) != (HLOCAL)0x0) && (*(int *)(param_1 + 0x44) != 0x41)) {
    LocalFree(*(HLOCAL *)(param_1 + 0x42));
  }
  *(undefined4 *)(param_1 + 0x44) = 0x41;
  *param_1 = 0;
  *(undefined2 **)(param_1 + 0x42) = param_1;
  return;
}



/* 4053b4c8 FUN_4053b4c8 */

/* Boundary evidence: original MIPS .pdata 4053b4c8..4053b5bb. Semantic name remains unreviewed. */

undefined4 FUN_4053b4c8(wchar_t *param_1,uint param_2)

{
  wchar_t *_Dest;
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0x44);
  for (uVar2 = uVar1; uVar2 < param_2; uVar2 = uVar2 << 2) {
  }
  if (uVar2 != uVar1) {
    if (uVar2 < 0x42) {
      if ((*(wchar_t **)(param_1 + 0x42) != (wchar_t *)0x0) && (uVar1 != 0)) {
        wcsncpy(param_1,*(wchar_t **)(param_1 + 0x42),0x41);
      }
      FUN_4053b474(param_1);
      *(wchar_t **)(param_1 + 0x42) = param_1;
    }
    else {
      _Dest = LocalAlloc(0x40,uVar2 << 1);
      if (_Dest == (wchar_t *)0x0) {
        uVar3 = 0x8007000e;
      }
      else {
        wcsncpy(_Dest,*(wchar_t **)(param_1 + 0x42),param_2);
        FUN_4053b474(param_1);
        *(uint *)(param_1 + 0x44) = uVar2;
        *(wchar_t **)(param_1 + 0x42) = _Dest;
      }
    }
  }
  return uVar3;
}



/* 4053b5bc FUN_4053b5bc */

/* Boundary evidence: original MIPS .pdata 4053b5bc..4053b66f. Semantic name remains unreviewed. */

int FUN_4053b5bc(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  uint _Count;
  int iVar1;
  
  iVar1 = 1;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != 0)) {
    if (param_3 == 0xffffffff) {
      param_3 = wcslen(param_2);
    }
    if (param_3 != 0) {
      _Count = param_3 + 1;
      iVar1 = FUN_4053b4c8(param_1,_Count);
      if (-1 < iVar1) {
        if (*(uint *)(param_1 + 0x44) <= _Count) {
          _Count = *(uint *)(param_1 + 0x44);
        }
        wcsncpy(*(wchar_t **)(param_1 + 0x42),param_2,_Count);
      }
    }
  }
  return iVar1;
}



/* 4053b670 FUN_4053b670 */

/* Boundary evidence: original MIPS .pdata 4053b670..4053b6bf. Semantic name remains unreviewed. */

void FUN_4053b670(wchar_t *param_1,wchar_t *param_2,size_t param_3)

{
  FUN_4053b474(param_1);
  FUN_4053b5bc(param_1,param_2,param_3);
  return;
}



/* 4053b6c0 FUN_4053b6c0 */

/* Boundary evidence: original MIPS .pdata 4053b6c0..4053b743. Semantic name remains unreviewed. */

HLOCAL FUN_4053b6c0(HLOCAL param_1)

{
  SIZE_T uBytes;
  HLOCAL hMem;
  HLOCAL pvVar1;
  
  uBytes = LocalSize(param_1);
  hMem = LocalAlloc(0,uBytes);
  pvVar1 = (HLOCAL)0x0;
  if (hMem != (HLOCAL)0x0) {
    if (param_1 == (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    else {
      memcpy(hMem,param_1,uBytes);
      pvVar1 = hMem;
    }
  }
  return pvVar1;
}



/* 4053b744 FUN_4053b744 */

/* Boundary evidence: original MIPS .pdata 4053b744..4053b823. Semantic name remains unreviewed. */

void FUN_4053b744(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40515ef0;
  param_1[1] = &PTR_LAB_40515edc;
  param_1[2] = &PTR_LAB_40515ec8;
  FUN_40537f64(param_1[5]);
  if ((HLOCAL)param_1[6] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[6]);
    param_1[6] = 0;
  }
  if ((HLOCAL)param_1[9] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[9]);
    param_1[9] = 0;
  }
  if ((HLOCAL)param_1[10] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[10]);
    param_1[10] = 0;
  }
  if ((int *)param_1[0xf] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0xf] + 8))();
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0xd));
  IUnknown_AtomicRelease((void **)(param_1 + 0xb));
  IUnknown_AtomicRelease((void **)(param_1 + 0xc));
  return;
}



/* 4053b824 FUN_4053b824 */

/* Boundary evidence: original MIPS .pdata 4053b824..4053b84b. Semantic name remains unreviewed. */

void FUN_4053b824(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40515f08,param_2,param_3);
  return;
}



/* 4053b84c FUN_4053b84c */

/* Boundary evidence: original MIPS .pdata 4053b84c..4053b867. Semantic name remains unreviewed. */

void FUN_4053b84c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



/* 4053b868 FUN_4053b868 */

/* Boundary evidence: original MIPS .pdata 4053b868..4053b8fb. Semantic name remains unreviewed. */

int FUN_4053b868(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int *local_18 [2];
  
  local_18[0] = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_405136b4,local_18);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_18[0] + 0xc))(local_18[0],*(undefined4 *)(param_1 + 0x1c),param_3);
  }
  IUnknown_AtomicRelease(local_18);
  return iVar1;
}



/* 4053b8fc FUN_4053b8fc */

/* Boundary evidence: original MIPS .pdata 4053b8fc..4053b95f. Semantic name remains unreviewed. */

undefined4 FUN_4053b8fc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10 [2];
  
  uVar2 = 1;
  local_10[0] = (void *)0x0;
  if (*(int *)(param_1 + 0x10) != 2) {
    param_3 = 1;
  }
  if ((param_3 == 0) || (iVar1 = FUN_4053b868(param_1,param_2,local_10), iVar1 < 0)) {
    uVar2 = 0;
  }
  IUnknown_AtomicRelease(local_10);
  return uVar2;
}



/* 4053b960 FUN_4053b960 */

/* Boundary evidence: original MIPS .pdata 4053b960..4053b9eb. Semantic name remains unreviewed. */

int FUN_4053b960(int param_1)

{
  SIZE_T SVar1;
  int iVar2;
  
  iVar2 = 0x40;
  if (*(ushort **)(param_1 + 0x14) != (ushort *)0x0) {
    iVar2 = FUN_40537d04(*(ushort **)(param_1 + 0x14));
    iVar2 = iVar2 + 0x40;
  }
  if (*(HLOCAL *)(param_1 + 0x18) != (HLOCAL)0x0) {
    SVar1 = LocalSize(*(HLOCAL *)(param_1 + 0x18));
    iVar2 = SVar1 + iVar2;
  }
  if (*(HLOCAL *)(param_1 + 0x24) != (HLOCAL)0x0) {
    SVar1 = LocalSize(*(HLOCAL *)(param_1 + 0x24));
    iVar2 = SVar1 + iVar2;
  }
  if (*(HLOCAL *)(param_1 + 0x28) != (HLOCAL)0x0) {
    SVar1 = LocalSize(*(HLOCAL *)(param_1 + 0x28));
    iVar2 = SVar1 + iVar2;
  }
  return iVar2;
}



/* 4053b9ec FUN_4053b9ec */

/* Boundary evidence: original MIPS .pdata 4053b9ec..4053ba37. Semantic name remains unreviewed. */

int FUN_4053b9ec(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x3c);
  iVar1 = FUN_4053b960(param_1);
  for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x3c)) {
    iVar2 = FUN_4053b960(iVar3);
    iVar1 = iVar2 + iVar1;
  }
  return iVar1;
}



/* 4053ba38 FUN_4053ba38 */

/* Boundary evidence: original MIPS .pdata 4053ba38..4053bad7. Semantic name remains unreviewed. */

void FUN_4053ba38(int param_1)

{
  FUN_4052d97c((int *)(param_1 + 0x14),(ushort *)0x0);
  if (*(HLOCAL *)(param_1 + 0x18) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  IUnknown_AtomicRelease((void **)(param_1 + 0x2c));
  IUnknown_AtomicRelease((void **)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  if (*(HLOCAL *)(param_1 + 0x24) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(HLOCAL *)(param_1 + 0x28) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0x28));
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}



/* 4053bad8 FUN_4053bad8 */

/* Boundary evidence: original MIPS .pdata 4053bad8..4053bb97. Semantic name remains unreviewed. */

undefined4 FUN_4053bad8(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18;
  int *local_14;
  
  uVar2 = 0x80004005;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_40513564,&local_14);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_14 + 0x1c))(local_14,&local_18);
    if (-1 < iVar1) {
      uVar2 = (**(code **)(*local_18 + 0x10))(local_18,param_2,param_3);
      (**(code **)(*local_18 + 8))();
    }
    (**(code **)(*local_14 + 8))();
  }
  return uVar2;
}



/* 4053bb98 FUN_4053bb98 */

/* Boundary evidence: original MIPS .pdata 4053bb98..4053bc93. Semantic name remains unreviewed. */

undefined4 FUN_4053bb98(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *local_18;
  int *local_14;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0x38))
                    (*(int **)(param_1 + 0x2c),4,0,0,*(undefined4 *)(param_1 + 0x30));
  iVar2 = (**(code **)*param_2)(param_2,&DAT_4051642c,&local_14);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*local_14 + 0xc))(local_14,&DAT_4051645c,&DAT_405162cc,&local_18);
    if (-1 < iVar2) {
      (**(code **)(*local_18 + 0xa4))(local_18,0);
      (**(code **)(*local_18 + 8))();
    }
    (**(code **)(*local_14 + 8))();
  }
  FUN_4053bad8(param_1,param_2,0);
  return uVar1;
}



/* 4053bc94 FUN_4053bc94 */

/* Boundary evidence: original MIPS .pdata 4053bc94..4053be7b. Semantic name remains unreviewed. */

int FUN_4053bc94(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  HRESULT HVar2;
  HLOCAL hGlobal;
  IStream **ppvObject;
  undefined4 uVar3;
  _func_5237 *p_Var4;
  LARGE_INTEGER dlibMove;
  ULARGE_INTEGER libNewSize;
  IStream *This;
  IStream *This_00;
  ULARGE_INTEGER *pUVar5;
  ULARGE_INTEGER *plibNewPosition;
  ULARGE_INTEGER *local_18;
  IStream *local_14;
  
  This = (IStream *)0x0;
  pUVar5 = (ULARGE_INTEGER *)0x0;
  local_18 = (ULARGE_INTEGER *)0x0;
  if (*(int *)(param_1 + 0x10) == 3) {
    iVar1 = FUN_4053bb98(param_1,param_2);
    goto LAB_4053be48;
  }
  iVar1 = FUN_4053b868(param_1,param_2,&stack0xffffffe4);
  plibNewPosition = pUVar5;
  if (((iVar1 < 0) &&
      (iVar1 = (**(code **)*param_2)(param_2,&DAT_4051640c,&local_18), pUVar5 = local_18, iVar1 < 0)
      ) || (iVar1 = (*(code *)**(undefined4 **)pUVar5)(pUVar5,&DAT_4051649c,&stack0xffffffe0),
           iVar1 < 0)) goto LAB_4053be48;
  if (*(int *)(param_1 + 0x10) == 2) {
    ppvObject = &local_14;
    This_00 = This;
    HVar2 = (*This->lpVtbl->QueryInterface)(This,(IID *)&DAT_405136b4,ppvObject);
    if (HVar2 < 0) {
      libNewSize.s.HighPart = param_4;
      libNewSize.s.LowPart = (DWORD)ppvObject;
      iVar1 = (*This_00->lpVtbl->SetSize)(This_00,libNewSize);
      This = This_00;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x20);
      p_Var4 = local_14->lpVtbl->Seek;
      This = local_14;
LAB_4053bd8c:
      dlibMove.s.HighPart = param_4;
      dlibMove.s.LowPart = uVar3;
      iVar1 = (*p_Var4)(This,dlibMove,(DWORD)This_00,plibNewPosition);
      (*local_14->lpVtbl->Release)(local_14);
      This = This_00;
    }
  }
  else {
    hGlobal = FUN_4053b6c0(*(HLOCAL *)(param_1 + 0x18));
    if (hGlobal == (HLOCAL)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = CreateStreamOnHGlobal(hGlobal,1,&local_14);
      if (-1 < iVar1) {
        p_Var4 = (_func_5237 *)This->lpVtbl->Write;
        uVar3 = 0;
        This_00 = This;
        goto LAB_4053bd8c;
      }
      LocalFree(hGlobal);
    }
  }
  (*This->lpVtbl->Release)(This);
LAB_4053be48:
  IUnknown_AtomicRelease((void **)&stack0xffffffe4);
  IUnknown_AtomicRelease(&local_18);
  return iVar1;
}



/* 4053be7c FUN_4053be7c */

/* Boundary evidence: original MIPS .pdata 4053be7c..4053bfdf. Semantic name remains unreviewed. */

int FUN_4053be7c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *local_1070;
  STRSAFE_LPCWSTR local_106c;
  wchar_t awStack_1068 [2084];
  uint local_20;
  
  local_20 = DAT_40544354;
  FUN_4053ba38(param_1);
  (**(code **)*param_3)(param_3,&UNK_4051696c,(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(param_1 + 0x10) = 3;
  piVar2 = *(int **)(param_1 + 0x30);
  piVar3 = (int *)(param_1 + 0x2c);
  iVar4 = -0x7fffbffb;
  (**(code **)(*piVar2 + 0x34))(piVar2,0xffffffff,piVar3);
  (**(code **)*param_2)(param_2,&DAT_40513564,&local_1070);
  if ((local_1070 != (int *)0x0) && (*piVar3 != 0)) {
    uVar1 = (**(code **)(*local_1070 + 0x60))();
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    iVar4 = (**(code **)(*(int *)*piVar3 + 0x20))((int *)*piVar3,1,&local_106c,0);
    if (-1 < iVar4) {
      StringCchCopyW(awStack_1068,0x824,local_106c);
      CoTaskMemFree(local_106c);
      iVar4 = FUN_405221bc(0,awStack_1068,(IUnknown *)0x0,(undefined4 *)(param_1 + 0x14));
    }
  }
  IUnknown_AtomicRelease(&local_1070);
  FUN_40542538(local_20);
  return iVar4;
}



/* 4053bfe0 FUN_4053bfe0 */

/* Boundary evidence: original MIPS .pdata 4053bfe0..4053c22b. Semantic name remains unreviewed. */

int FUN_4053bfe0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  LPCITEMIDLIST pIVar2;
  int iVar3;
  LPWSTR pWVar4;
  LPCWSTR pWVar5;
  int *piVar6;
  int *local_1090 [2];
  undefined4 local_1088;
  undefined4 local_1084;
  ushort *local_1080;
  LPCWSTR local_107c;
  LPCWSTR local_1078;
  LPCWSTR local_1074;
  undefined4 local_1070;
  WCHAR local_1068;
  undefined1 auStack_1066 [4166];
  uint local_20;
  
  local_20 = DAT_40544354;
  local_1088 = 0;
  memset(&local_1084,0,0x18);
  local_1090[0] = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_405136b4,local_1090);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(*local_1090[0] + 0x10))(local_1090[0],&local_1088), iVar1 == 0)) {
    piVar6 = (int *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x1c) = local_1088;
    FUN_40537f64(*piVar6);
    if (local_1080 == (ushort *)0x0) {
      iVar1 = FUN_40522458(local_1084,local_107c,(IUnknown *)0x0,piVar6);
      pWVar5 = local_107c;
      if (iVar1 != 0) goto LAB_4053c1b0;
    }
    else {
      pIVar2 = FUN_4052d908(local_1080);
      *piVar6 = (int)pIVar2;
      local_1068 = L'\0';
      memset(auStack_1066,0,0x1046);
      FUN_40522b14(pIVar2,&local_1068,0x8000);
      pWVar5 = &local_1068;
    }
    iVar3 = FUN_4052e864(pWVar5);
    if (iVar3 == 0) {
      if (*(HLOCAL *)(param_1 + 0x28) != (HLOCAL)0x0) {
        LocalFree(*(HLOCAL *)(param_1 + 0x28));
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      if ((local_1078 != (LPCWSTR)0x0) && (*local_1078 != L'\0')) {
        pWVar4 = StrDupW(local_1078);
        *(LPWSTR *)(param_1 + 0x28) = pWVar4;
      }
      if (*(HLOCAL *)(param_1 + 0x24) != (HLOCAL)0x0) {
        LocalFree(*(HLOCAL *)(param_1 + 0x24));
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      if (local_1074 != (LPCWSTR)0x0) {
        pWVar4 = StrDupW(local_1074);
        *(LPWSTR *)(param_1 + 0x24) = pWVar4;
      }
      *param_3 = local_1070;
    }
    else {
      iVar1 = -0x7ff3fff2;
    }
  }
LAB_4053c1b0:
  FUN_40537f64((int)local_1080);
  CoTaskMemFree(local_107c);
  CoTaskMemFree(local_1078);
  CoTaskMemFree(local_1074);
  IUnknown_AtomicRelease(local_1090);
  FUN_40542538(local_20);
  return iVar1;
}



/* 4053c22c FUN_4053c22c */

/* Boundary evidence: original MIPS .pdata 4053c22c..4053c273. Semantic name remains unreviewed. */

undefined4 FUN_4053c22c(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    pvVar1 = FUN_4052d908(*(ushort **)(param_1 + 0x14));
    *param_2 = pvVar1;
    if (pvVar1 != (void *)0x0) {
      return 0;
    }
  }
  return 0x80004005;
}



/* 4053c274 FUN_4053c274 */

/* Boundary evidence: original MIPS .pdata 4053c274..4053c2c3. Semantic name remains unreviewed. */

void FUN_4053c274(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
  }
  *(int *)(param_1 + 0x3c) = param_2;
  if (param_2 != 0) {
    *(int *)(param_2 + 0x38) = param_1;
  }
  return;
}



/* 4053c2c4 FUN_4053c2c4 */

/* Boundary evidence: original MIPS .pdata 4053c2c4..4053c313. Semantic name remains unreviewed. */

void FUN_4053c2c4(int *param_1)

{
  code *pcVar1;
  
  if (param_1[0xf] != 0) {
    *(int *)(param_1[0xf] + 0x38) = param_1[0xe];
  }
  if (param_1[0xe] != 0) {
    *(int *)(param_1[0xe] + 0x3c) = param_1[0xf];
  }
  pcVar1 = *(code **)(*param_1 + 8);
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  (*pcVar1)();
  return;
}



/* 4053c314 FUN_4053c314 */

/* Boundary evidence: original MIPS .pdata 4053c314..4053c3eb. Semantic name remains unreviewed. */

undefined4 FUN_4053c314(LPCITEMIDLIST param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  int iVar1;
  BOOL BVar2;
  CHAR aCStack_1888 [2088];
  WCHAR aWStack_1060 [2084];
  uint local_18;
  
  local_18 = DAT_40544354;
  iVar1 = FUN_40522b14(param_1,aWStack_1060,0);
  if ((iVar1 < 0) || (BVar2 = UrlIsW(aWStack_1060,URLIS_URL), BVar2 == 0)) {
    StringCchCopyW(param_2,param_3,aWStack_1060);
  }
  else {
    SHUnicodeToAnsi(aWStack_1060,aCStack_1888,0x824);
    UrlUnescapeA(aCStack_1888,(LPSTR)0x0,(LPDWORD)0x0,0x500000);
    SHAnsiToUnicode(aCStack_1888,param_2,param_3);
  }
  FUN_40542538(local_18);
  return 0;
}



/* 4053c3ec FUN_4053c3ec */

/* Boundary evidence: original MIPS .pdata 4053c3ec..4053c48b. Semantic name remains unreviewed. */

undefined4 FUN_4053c3ec(int param_1,STRSAFE_LPWSTR param_2,size_t param_3)

{
  undefined4 uVar1;
  STRSAFE_LPCWSTR pszSrc;
  
  if ((param_2 == (STRSAFE_LPWSTR)0x0) || (param_3 == 0)) {
    uVar1 = 0x80070057;
  }
  else {
    *param_2 = L'\0';
    pszSrc = *(STRSAFE_LPCWSTR *)(param_1 + 0x24);
    if ((pszSrc == (STRSAFE_LPCWSTR)0x0) || (*pszSrc == L'\0')) {
      if (*(LPCITEMIDLIST *)(param_1 + 0x14) != (LPCITEMIDLIST)0x0) {
        FUN_4053c314(*(LPCITEMIDLIST *)(param_1 + 0x14),param_2,param_3);
      }
    }
    else {
      StringCchCopyW(param_2,param_3,pszSrc);
    }
    if (*param_2 == L'\0') {
      uVar1 = 0x80004005;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 4053c48c FUN_4053c48c */

/* Boundary evidence: original MIPS .pdata 4053c48c..4053c503. Semantic name remains unreviewed. */

int FUN_4053c48c(int param_1,LPWSTR *param_2)

{
  int iVar1;
  wchar_t awStack_118 [128];
  uint local_18;
  
  local_18 = DAT_40544354;
  iVar1 = FUN_4053c3ec(param_1 + -4,awStack_118,0x80);
  if (-1 < iVar1) {
    iVar1 = SHStrDupW(awStack_118,param_2);
  }
  FUN_40542538(local_18);
  return iVar1;
}



/* 4053c504 FUN_4053c504 */

/* Boundary evidence: original MIPS .pdata 4053c504..4053c583. Semantic name remains unreviewed. */

int FUN_4053c504(int param_1,LPWSTR *param_2)

{
  int iVar1;
  WCHAR aWStack_1060 [2084];
  uint local_18;
  
  local_18 = DAT_40544354;
  iVar1 = -0x7fffbffb;
  if ((*(LPCITEMIDLIST *)(param_1 + 0x10) != (LPCITEMIDLIST)0x0) &&
     (iVar1 = FUN_40522b14(*(LPCITEMIDLIST *)(param_1 + 0x10),aWStack_1060,0x8000), -1 < iVar1)) {
    iVar1 = SHStrDupW(aWStack_1060,param_2);
  }
  FUN_40542538(local_18);
  return iVar1;
}



/* 4053c584 FUN_4053c584 */

/* Boundary evidence: original MIPS .pdata 4053c584..4053c5c3. Semantic name remains unreviewed. */

undefined4 FUN_4053c584(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))();
  }
  return uVar1;
}



/* 4053c5c4 FUN_4053c5c4 */

/* Boundary evidence: original MIPS .pdata 4053c5c4..4053c637. Semantic name remains unreviewed. */

void FUN_4053c5c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x2c);
  if ((*piVar2 != 0) || (iVar1 = FUN_40541bb4(2,&DAT_4051695c,piVar2), -1 < iVar1)) {
    (**(code **)(*(int *)*piVar2 + 0x10))((int *)*piVar2,param_2,param_3);
  }
  return;
}



/* 4053c638 FUN_4053c638 */

/* Boundary evidence: original MIPS .pdata 4053c638..4053c67f. Semantic name remains unreviewed. */

void FUN_4053c638(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40515f80;
  param_1[1] = &PTR_LAB_40515f50;
  param_1[2] = &PTR_LAB_40515f28;
  IUnknown_AtomicRelease((void **)(param_1 + 8));
  return;
}



/* 4053c680 FUN_4053c680 */

/* Boundary evidence: original MIPS .pdata 4053c680..4053c6a7. Semantic name remains unreviewed. */

void FUN_4053c680(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40515fb8,param_2,param_3);
  return;
}



/* 4053c6a8 FUN_4053c6a8 */

/* Boundary evidence: original MIPS .pdata 4053c6a8..4053c6c3. Semantic name remains unreviewed. */

void FUN_4053c6a8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0xc));
  return;
}



/* 4053c6c4 FUN_4053c6c4 */

/* Boundary evidence: original MIPS .pdata 4053c6c4..4053c747. Semantic name remains unreviewed. */

void FUN_4053c6c4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 0x14)) {
    do {
      piVar2 = *(int **)(param_1 + 0x20);
      if (piVar2 == *(int **)(param_1 + 0x18)) {
        return;
      }
      *(int *)(param_1 + 0x20) = piVar2[0xf];
      iVar1 = FUN_4053b960((int)piVar2);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
      FUN_4053c2c4(piVar2);
    } while (*(uint *)(param_1 + 0x10) < *(uint *)(param_1 + 0x14));
  }
  return;
}



/* 4053c748 FUN_4053c748 */

/* Boundary evidence: original MIPS .pdata 4053c748..4053c83f. Semantic name remains unreviewed. */

undefined4 FUN_4053c748(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    for (iVar1 = *(int *)(param_1 + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
      if (iVar1 == *(int *)(param_1 + 0x1c)) goto LAB_4053c798;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
LAB_4053c798:
  piVar2 = *(int **)(param_1 + 0x1c);
  if ((piVar2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0x18), piVar2 == (int *)0x0)) {
    uVar3 = 0x80004005;
  }
  else {
    iVar1 = FUN_4053b960((int)piVar2);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
    uVar3 = (**(code **)(*piVar2 + 0x10))(piVar2,param_2,param_3);
    iVar1 = FUN_4053b960((int)piVar2);
    *(int *)(param_1 + 0x14) = iVar1 + *(int *)(param_1 + 0x14);
    FUN_4053c6c4(param_1);
    if (*(int *)(param_1 + 0x1c) == 0) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
  }
  return uVar3;
}



/* 4053c840 FUN_4053c840 */

/* Boundary evidence: original MIPS .pdata 4053c840..4053c8b7. Semantic name remains unreviewed. */

int FUN_4053c840(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    for (iVar1 = *(int *)(param_1 + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
      if (iVar1 == *(int *)(param_1 + 0x1c)) goto LAB_4053c87c;
    }
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
LAB_4053c87c:
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((iVar1 == 0) && (iVar1 = *(int *)(param_1 + 0x18), iVar1 == 0)) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = FUN_4053be7c(iVar1,param_2,param_3);
  }
  return iVar1;
}



/* 4053c8b8 FUN_4053c8b8 */

/* Boundary evidence: original MIPS .pdata 4053c8b8..4053c9df. Semantic name remains unreviewed. */

undefined4 FUN_4053c8b8(int param_1,undefined4 *param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = 1;
  if (param_3 < 0) {
    do {
      if (iVar3 == 0) goto LAB_4053c9b4;
      iVar3 = *(int *)(iVar3 + 0x38);
      if (((iVar3 != 0) && (iVar1 = FUN_4053b8fc(iVar3,param_2,iVar4), iVar1 != 0)) &&
         ((param_3 = param_3 + 1, iVar4 == 0 || (iVar4 = 1, *(int *)(iVar3 + 0x10) != 2)))) {
        iVar4 = 0;
      }
    } while (param_3 != 0);
  }
  else if (0 < param_3) {
    do {
      if (iVar3 == 0) goto LAB_4053c9b4;
      iVar3 = *(int *)(iVar3 + 0x3c);
      if (((iVar3 != 0) && (iVar1 = FUN_4053b8fc(iVar3,param_2,iVar4), iVar1 != 0)) &&
         ((param_3 = param_3 + -1, iVar4 == 0 || (iVar4 = 1, *(int *)(iVar3 + 0x10) != 2)))) {
        iVar4 = 0;
      }
    } while (param_3 != 0);
  }
  if (iVar3 == 0) {
LAB_4053c9b4:
    uVar2 = 0x80004005;
  }
  else {
    *param_4 = iVar3;
    uVar2 = 0;
  }
  return uVar2;
}



/* 4053c9e0 FUN_4053c9e0 */

/* Boundary evidence: original MIPS .pdata 4053c9e0..4053caa7. Semantic name remains unreviewed. */

int FUN_4053c9e0(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *local_18 [2];
  
  bVar1 = param_3 == -0x7fffffff;
  if (bVar1) {
    param_3 = -1;
  }
  if (((param_3 == 0) && (*(int *)(param_1 + 0x18) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x18) + 0x10) == 3)) {
    iVar2 = -0x7fffbffb;
  }
  else {
    iVar2 = FUN_4053c8b8(param_1,param_2,param_3,(int *)local_18);
    if (((bVar1) && (-1 < iVar2)) && (local_18[0][4] != 3)) {
      iVar2 = -0x7fffbffb;
    }
    if ((param_4 != 0) && (-1 < iVar2)) {
      iVar2 = (**(code **)*local_18[0])(local_18[0],&DAT_40513684,param_4);
    }
  }
  return iVar2;
}



/* 4053caa8 FUN_4053caa8 */

/* Boundary evidence: original MIPS .pdata 4053caa8..4053cb6b. Semantic name remains unreviewed. */

undefined4 FUN_4053caa8(int param_1,undefined4 *param_2,ushort *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x20);
  iVar3 = 1;
  while( true ) {
    if (iVar2 == 0) {
      *param_4 = 0;
      return 0x80004005;
    }
    iVar1 = FUN_4053b8fc(iVar2,param_2,iVar3);
    if ((iVar1 != 0) && (iVar1 = FUN_40521408(param_3,*(ushort **)(iVar2 + 0x14)), iVar1 != 0))
    break;
    if ((iVar3 == 0) || (iVar3 = 1, *(int *)(iVar2 + 0x10) != 2)) {
      iVar3 = 0;
    }
    iVar2 = *(int *)(iVar2 + 0x3c);
  }
  *param_4 = iVar2;
  return 0;
}



/* 4053cb6c FUN_4053cb6c */

/* Boundary evidence: original MIPS .pdata 4053cb6c..4053cc6f. Semantic name remains unreviewed. */

undefined4 FUN_4053cb6c(int param_1,undefined4 *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x20);
  iVar4 = 1;
  iVar1 = SHIsSameObject(param_3,*(undefined4 *)(param_1 + 0x18));
  if (iVar1 == 0) {
    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x3c)) {
      iVar1 = FUN_4053b8fc(iVar3,param_2,iVar4);
      if ((iVar1 != 0) && (iVar1 = SHIsSameObject(iVar3,param_3), iVar1 != 0)) {
        *param_4 = iVar3;
        goto LAB_4053cbcc;
      }
      if ((iVar4 == 0) || (iVar4 = 1, *(int *)(iVar3 + 0x10) != 2)) {
        iVar4 = 0;
      }
    }
    *param_4 = 0;
    uVar2 = 0x80004005;
  }
  else {
    *param_4 = *(int *)(param_1 + 0x18);
LAB_4053cbcc:
    uVar2 = 0;
  }
  return uVar2;
}



/* 4053cc70 FUN_4053cc70 */

/* Boundary evidence: original MIPS .pdata 4053cc70..4053ccfb. Semantic name remains unreviewed. */

undefined4
FUN_4053cc70(int param_1,undefined4 param_2,undefined4 param_3,LPCWSTR param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int local_18 [2];
  
  uVar2 = 0x80004005;
  iVar1 = FUN_40522458(param_3,param_4,(IUnknown *)0x0,local_18);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(*(int *)(param_1 + -4) + 0x20))
                      ((int *)(param_1 + -4),param_2,local_18[0],param_5);
    FUN_40537f64(local_18[0]);
  }
  return uVar2;
}



/* 4053ccfc FUN_4053ccfc */

/* Boundary evidence: original MIPS .pdata 4053ccfc..4053cd8b. Semantic name remains unreviewed. */

int FUN_4053ccfc(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 1;
  for (iVar3 = *(int *)(param_1 + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x3c)) {
    iVar1 = FUN_4053b8fc(iVar3,param_2,iVar2);
    if (iVar1 != 0) {
      iVar4 = iVar4 + 1;
    }
    if ((iVar2 == 0) || (iVar2 = 1, *(int *)(iVar3 + 0x10) != 2)) {
      iVar2 = 0;
    }
  }
  return iVar4;
}



/* 4053cdec FUN_4053cdec */

/* Boundary evidence: original MIPS .pdata 4053cdec..4053cf33. Semantic name remains unreviewed. */

void FUN_4053cdec(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 1;
  if (param_3 != (int *)0x0) {
    piVar2 = param_3;
    do {
      if (piVar2 == *(int **)(param_1 + 0x18)) break;
      piVar2 = (int *)piVar2[0xf];
    } while (piVar2 != (int *)0x0);
    if (piVar2 == (int *)0x0) {
      do {
        piVar2 = (int *)param_3[0xf];
        if ((iVar3 == 0) || (iVar3 = 1, param_3[4] != 2)) {
          iVar3 = 0;
        }
        iVar1 = FUN_4053b960((int)param_3);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
        FUN_4053c2c4(param_3);
      } while ((piVar2 != (int *)0x0) &&
              (iVar1 = FUN_4053b8fc((int)piVar2,param_2,iVar3), param_3 = piVar2, iVar1 == 0));
    }
    else {
      do {
        if (param_3 == *(int **)(param_1 + 0x20)) {
          *(int *)(param_1 + 0x20) = param_3[0xf];
        }
        piVar2 = (int *)param_3[0xe];
        if ((iVar3 == 0) || (iVar3 = 1, param_3[4] != 2)) {
          iVar3 = 0;
        }
        iVar1 = FUN_4053b960((int)param_3);
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
        FUN_4053c2c4(param_3);
      } while ((piVar2 != (int *)0x0) &&
              (iVar1 = FUN_4053b8fc((int)piVar2,param_2,iVar3), param_3 = piVar2, iVar1 == 0));
    }
  }
  return;
}



/* 4053cf34 FUN_4053cf34 */

/* Boundary evidence: original MIPS .pdata 4053cf34..4053cff3. Semantic name remains unreviewed. */

int FUN_4053cf34(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *local_18;
  int *local_14;
  
  if (param_3 == 0) {
    iVar2 = -0x7fffbffb;
  }
  else {
    iVar2 = FUN_4053c8b8(param_1 + -4,param_2,param_3,(int *)&local_14);
    if (-1 < iVar2) {
      FUN_4053cdec(param_1 + -4,param_2,local_14);
      iVar1 = (**(code **)*param_2)(param_2,&DAT_40513564,&local_18);
      if (-1 < iVar1) {
        (**(code **)(*local_18 + 0x48))();
        (**(code **)(*local_18 + 8))();
      }
    }
  }
  return iVar2;
}



/* 4053cff4 FUN_4053cff4 */

/* Boundary evidence: original MIPS .pdata 4053cff4..4053d12f. Semantic name remains unreviewed. */

undefined4 FUN_4053cff4(int param_1,undefined4 *param_2,undefined4 param_3,LPCWSTR param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  ushort *local_28;
  int *local_24;
  int *local_20 [2];
  
  uVar2 = 0x80004005;
  iVar4 = 0;
  iVar1 = FUN_40522458(param_3,param_4,(IUnknown *)0x0,&local_28);
  if (-1 < iVar1) {
    iVar1 = FUN_40521408(local_28,*(ushort **)(*(int *)(param_1 + 0x14) + 0x14));
    if (iVar1 == 0) {
      iVar3 = param_1 + -4;
      uVar2 = 0;
      iVar1 = FUN_4053caa8(iVar3,param_2,local_28,(int *)&local_24);
      while (-1 < iVar1) {
        FUN_4053cdec(iVar3,param_2,local_24);
        iVar4 = iVar4 + 1;
        iVar1 = FUN_4053caa8(iVar3,param_2,local_28,(int *)&local_24);
      }
    }
    FUN_40537f64((int)local_28);
    if ((iVar4 != 0) && (iVar4 = (**(code **)*param_2)(param_2,&DAT_40513564,local_20), -1 < iVar4))
    {
      (**(code **)(*local_20[0] + 0x48))();
      (**(code **)(*local_20[0] + 8))();
    }
  }
  return uVar2;
}



/* 4053d130 FUN_4053d130 */

/* Boundary evidence: original MIPS .pdata 4053d130..4053d207. Semantic name remains unreviewed. */

int FUN_4053d130(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *local_20;
  int *local_1c;
  
  iVar1 = FUN_4053cb6c(param_1 + -4,param_2,param_3,(int *)&local_1c);
  if ((iVar1 < 0) || (local_1c == *(int **)(param_1 + 0x14))) {
    iVar1 = -0x7fffbffb;
  }
  else {
    FUN_4053cdec(param_1 + -4,param_2,local_1c);
    iVar2 = (**(code **)*param_2)(param_2,&DAT_40513564,&local_20);
    if (-1 < iVar2) {
      (**(code **)(*local_20 + 0x48))();
      (**(code **)(*local_20 + 8))();
    }
  }
  return iVar1;
}



/* 4053d208 FUN_4053d208 */

/* Boundary evidence: original MIPS .pdata 4053d208..4053d38f. Semantic name remains unreviewed. */

undefined4 FUN_4053d208(int param_1,undefined4 *param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 1;
  iVar4 = 0;
  if (*(int *)(param_1 + 0x14) == 0) {
    *param_4 = 0;
  }
  else {
    if (((param_3 & 0x10) == 0x10) &&
       (iVar3 = *(int *)(param_1 + 0x1c), iVar3 != *(int *)(param_1 + 0x14))) {
      do {
        iVar1 = FUN_4053b8fc(iVar3,param_2,iVar2);
        if ((iVar1 != 0) &&
           ((iVar4 = iVar4 + 1, iVar2 == 0 || (iVar2 = 1, *(int *)(iVar3 + 0x10) != 2)))) {
          iVar2 = 0;
        }
        iVar3 = *(int *)(iVar3 + 0x3c);
      } while (iVar3 != *(int *)(param_1 + 0x14));
    }
    if ((((param_3 & 1) == 1) &&
        (iVar3 = FUN_4053b8fc(*(int *)(param_1 + 0x14),param_2,iVar2), iVar3 != 0)) &&
       ((iVar4 = iVar4 + 1, iVar2 == 0 ||
        (iVar2 = 1, *(int *)(*(int *)(param_1 + 0x14) + 0x10) != 2)))) {
      iVar2 = 0;
    }
    if ((param_3 & 0x20) == 0x20) {
      for (iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0x3c); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0x3c)) {
        iVar1 = FUN_4053b8fc(iVar3,param_2,iVar2);
        if ((iVar1 != 0) &&
           ((iVar4 = iVar4 + 1, iVar2 == 0 || (iVar2 = 1, *(int *)(iVar3 + 0x10) != 2)))) {
          iVar2 = 0;
        }
      }
    }
    *param_4 = iVar4;
  }
  return 0;
}



/* 4053d390 FUN_4053d390 */

int FUN_4053d390(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_1 != param_2) {
    iVar2 = param_1;
    if (param_1 != 0) {
      do {
        if (iVar2 == param_2) break;
        iVar2 = *(int *)(iVar2 + 0x38);
        iVar1 = iVar1 + -1;
      } while (iVar2 != 0);
      if (iVar2 != 0) {
        return iVar1;
      }
    }
    iVar1 = 0;
    if (param_1 != 0) {
      do {
        if (param_1 == param_2) break;
        param_1 = *(int *)(param_1 + 0x3c);
        iVar1 = iVar1 + 1;
      } while (param_1 != 0);
      if (param_1 != 0) {
        return iVar1;
      }
    }
  }
  return 0;
}



/* 4053d3ec FUN_4053d3ec */

/* Boundary evidence: original MIPS .pdata 4053d3ec..4053d4b7. Semantic name remains unreviewed. */

int FUN_4053d3ec(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  if (param_1[7] != 0) {
    for (iVar1 = param_1[8]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
      if (iVar1 == param_1[7]) goto LAB_4053d438;
    }
    param_1[7] = 0;
  }
LAB_4053d438:
  iVar1 = param_1[6];
  if ((*(int *)(iVar1 + 0x10) != 3) && (param_1[7] == 0)) {
    param_1[7] = iVar1;
  }
  iVar1 = FUN_4053d390(iVar1,(int)param_3);
  param_1[9] = iVar1;
  param_1[6] = (int)param_3;
  iVar1 = (**(code **)(*param_3 + 0xc))(param_3,param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0x34))(param_1);
  }
  return iVar1;
}



/* 4053d4b8 FUN_4053d4b8 */

/* Boundary evidence: original MIPS .pdata 4053d4b8..4053d527. Semantic name remains unreviewed. */

int FUN_4053d4b8(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int *local_18 [2];
  
  local_18[0] = (int *)0x0;
  iVar1 = -0x7fffbffb;
  FUN_4053cb6c(param_1 + -4,param_2,param_3,(int *)local_18);
  if (local_18[0] != (int *)0x0) {
    iVar1 = FUN_4053d3ec((int *)(param_1 + -4),param_2,local_18[0]);
  }
  return iVar1;
}



/* 4053d538 FUN_4053d538 */

/* Boundary evidence: original MIPS .pdata 4053d538..4053d587. Semantic name remains unreviewed. */

void FUN_4053d538(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40515fd8;
  IUnknown_AtomicRelease((void **)(param_1 + 5));
  IUnknown_AtomicRelease((void **)(param_1 + 6));
  return;
}



/* 4053d588 FUN_4053d588 */

/* Boundary evidence: original MIPS .pdata 4053d588..4053d5af. Semantic name remains unreviewed. */

void FUN_4053d588(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40515ff4,param_2,param_3);
  return;
}



/* 4053d5b0 FUN_4053d5b0 */

/* Boundary evidence: original MIPS .pdata 4053d5b0..4053d5cb. Semantic name remains unreviewed. */

void FUN_4053d5b0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 4053d5cc FUN_4053d5cc */

/* Boundary evidence: original MIPS .pdata 4053d5cc..4053d6a7. Semantic name remains unreviewed. */

void FUN_4053d5cc(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *local_10 [2];
  
  uVar2 = *(uint *)(param_1 + 8);
  if ((uVar2 & 0x30) == 0x30) {
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 0x1c))
                      (*(int **)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),0xffffffff,local_10
                      );
    while (-1 < iVar1) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      (**(code **)(*local_10[0] + 8))();
      iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 0x1c))
                        (*(int **)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                         *(undefined4 *)(param_1 + 0x10),local_10);
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  }
  else {
    uVar3 = 1;
    if ((uVar2 & 1) != 1) {
      if ((uVar2 & 0x10) == 0x10) {
        uVar3 = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
  }
  return;
}



/* 4053d6a8 FUN_4053d6a8 */

/* Boundary evidence: original MIPS .pdata 4053d6a8..4053d6c7. Semantic name remains unreviewed. */

undefined4 FUN_4053d6a8(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  FUN_4053d5cc(param_1);
  return 0;
}



/* 4053d6c8 FUN_4053d6c8 */

/* Boundary evidence: original MIPS .pdata 4053d6c8..4053d7eb. Semantic name remains unreviewed. */

int * FUN_4053d6c8(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *local_28 [2];
  
  uVar2 = *(uint *)(param_1 + 8);
  uVar4 = 0;
  piVar5 = local_28[0];
  if (param_2 != 0) {
    do {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar1 = iVar3;
      if ((uVar2 & 0x20) != 0x20) {
        iVar1 = -iVar3;
      }
      iVar1 = *(int *)(param_1 + 0x10) + iVar1;
      if ((iVar1 == 0) && ((uVar2 & 1) != 1)) {
        *(int *)(param_1 + 0xc) = iVar3 + 1;
        uVar4 = uVar4 - 1;
      }
      else {
        piVar5 = (int *)(**(code **)(**(int **)(param_1 + 0x14) + 0x1c))
                                  (*(int **)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),iVar1,
                                   local_28);
        if ((int)piVar5 < 0) break;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        (**(code **)(*local_28[0] + 8))();
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  if (uVar4 != param_2) {
    piVar5 = (int *)0x1;
  }
  return piVar5;
}



/* 4053d7ec FUN_4053d7ec */

/* Boundary evidence: original MIPS .pdata 4053d7ec..4053d9af. Semantic name remains unreviewed. */

int FUN_4053d7ec(int param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int *local_30;
  int local_2c;
  
  uVar2 = *(uint *)(param_1 + 8);
  iVar7 = 0;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  uVar6 = 0;
  local_2c = param_3;
  if (param_2 != 0) {
    local_30 = &DAT_4051694c;
    do {
      iVar3 = *(int *)(param_1 + 0xc);
      iVar1 = iVar3;
      if ((uVar2 & 0x20) != 0x20) {
        iVar1 = -iVar3;
      }
      iVar1 = *(int *)(param_1 + 0x10) + iVar1;
      if ((iVar1 == 0) && ((uVar2 & 1) != 1)) {
        *(int *)(param_1 + 0xc) = iVar3 + 1;
        uVar6 = uVar6 - 1;
        param_3 = param_3 + -4;
      }
      else {
        iVar7 = (**(code **)(**(int **)(param_1 + 0x14) + 0x1c))
                          (*(int **)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),iVar1,&local_30
                          );
        if (iVar7 < 0) break;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        (**(code **)*local_30)(local_30,&DAT_4051694c,param_3);
        (**(code **)(*local_30 + 8))();
      }
      uVar6 = uVar6 + 1;
      param_3 = param_3 + 4;
    } while (uVar6 < param_2);
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar6;
  }
  if ((uVar6 != param_2) && (iVar7 = 1, uVar6 < param_2)) {
    puVar5 = (undefined4 *)(uVar6 * 4 + local_2c);
    if (param_2 - uVar6 != 0) {
      puVar4 = puVar5 + (param_2 - uVar6);
      do {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      } while (puVar5 != puVar4);
    }
  }
  return iVar7;
}



/* 4053d9b0 FUN_4053d9b0 */

/* Boundary evidence: original MIPS .pdata 4053d9b0..4053da1b. Semantic name remains unreviewed. */

void FUN_4053d9b0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40516024;
  param_1[1] = &PTR_LAB_40516004;
  IUnknown_AtomicRelease((void **)(param_1 + 3));
  CoTaskMemFree((LPVOID)param_1[4]);
  CoTaskMemFree((LPVOID)param_1[5]);
  return;
}



/* 4053da1c FUN_4053da1c */

/* Boundary evidence: original MIPS .pdata 4053da1c..4053da43. Semantic name remains unreviewed. */

void FUN_4053da1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*(int *)(param_1 + 4) + 0x18))((int *)(param_1 + 4),param_3);
  return;
}



/* 4053da44 FUN_4053da44 */

/* Boundary evidence: original MIPS .pdata 4053da44..4053da6b. Semantic name remains unreviewed. */

void FUN_4053da44(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_4051603c,param_2,param_3);
  return;
}



/* 4053da6c FUN_4053da6c */

/* Boundary evidence: original MIPS .pdata 4053da6c..4053da87. Semantic name remains unreviewed. */

void FUN_4053da6c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



/* 4053da88 FUN_4053da88 */

/* Boundary evidence: original MIPS .pdata 4053da88..4053db37. Semantic name remains unreviewed. */

undefined4 FUN_4053da88(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_18 [2];
  
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                    (*(undefined4 **)(param_1 + 0xc),&UNK_405166ac,local_18);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_18[0] + 0xc))
                      (local_18[0],*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                       param_2);
  }
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))();
  }
  if (iVar1 < 0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4053db38 FUN_4053db38 */

/* Boundary evidence: original MIPS .pdata 4053db38..4053db5f. Semantic name remains unreviewed. */

void FUN_4053db38(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40516084,param_2,param_3);
  return;
}



/* 4053db60 FUN_4053db60 */

/* Boundary evidence: original MIPS .pdata 4053db60..4053db7b. Semantic name remains unreviewed. */

void FUN_4053db60(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 4053db7c FUN_4053db7c */

/* Boundary evidence: original MIPS .pdata 4053db7c..4053dbdb. Semantic name remains unreviewed. */

undefined4 * FUN_4053db7c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_4051605c;
  IUnknown_AtomicRelease((void **)(param_1 + 3));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4053dbdc FUN_4053dbdc */

/* Boundary evidence: original MIPS .pdata 4053dbdc..4053dc1f. Semantic name remains unreviewed. */

undefined4 FUN_4053dbdc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x2c))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),param_2);
  }
  return uVar1;
}



/* 4053dc20 FUN_4053dc20 */

/* Boundary evidence: original MIPS .pdata 4053dc20..4053dc4f. Semantic name remains unreviewed. */

void FUN_4053dc20(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x20))
            (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),param_3,param_2);
  return;
}



/* 4053dc50 FUN_4053dc50 */

/* Boundary evidence: original MIPS .pdata 4053dc50..4053dc83. Semantic name remains unreviewed. */

void FUN_4053dc50(int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))
            (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),param_2,param_3);
  return;
}



/* 4053dc84 FUN_4053dc84 */

/* Boundary evidence: original MIPS .pdata 4053dc84..4053dcbf. Semantic name remains unreviewed. */

undefined4 FUN_4053dc84(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004005;
  if (param_2 != 0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),param_2);
  }
  return uVar1;
}



/* 4053dcc0 FUN_4053dcc0 */

/* Boundary evidence: original MIPS .pdata 4053dcc0..4053dda3. Semantic name remains unreviewed. */

int FUN_4053dcc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *local_20;
  int *local_1c;
  
  iVar2 = -0x7fffbffb;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                    (*(undefined4 **)(param_1 + 0xc),&DAT_40513694,&local_1c);
  if (-1 < iVar1) {
    iVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,*(undefined4 *)(param_1 + 8),param_2,&local_20)
    ;
    if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
      iVar2 = (**(code **)*local_20)(local_20,&DAT_4051694c,param_3);
      (**(code **)(*local_20 + 8))();
    }
    (**(code **)(*local_1c + 8))();
  }
  return iVar2;
}



/* 4053de6c FUN_4053de6c */

/* Boundary evidence: original MIPS .pdata 4053de6c..4053e017. Semantic name remains unreviewed. */

int FUN_4053de6c(int param_1,undefined4 *param_2)

{
  int *piVar1;
  LPWSTR pWVar2;
  void *pvVar3;
  HLOCAL pvVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x10) == 3) {
    iVar5 = -0x7fffbffb;
  }
  else {
    piVar1 = (int *)FUN_4052d4e8(0x40);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1[2] = (int)&PTR_LAB_40516094;
      *piVar1 = (int)&PTR_FUN_40515ef0;
      piVar1[1] = (int)&PTR_LAB_40515edc;
      piVar1[2] = (int)&PTR_LAB_40515ec8;
      piVar1[3] = 1;
    }
    if (piVar1 == (int *)0x0) {
      iVar5 = -0x7ff8fff2;
    }
    else {
      piVar1[4] = *(int *)(param_1 + 0x10);
      piVar1[7] = *(int *)(param_1 + 0x1c);
      piVar1[8] = *(int *)(param_1 + 0x20);
      iVar6 = -0x7ff8fff2;
      iVar5 = 0;
      if (*(LPCWSTR *)(param_1 + 0x24) != (LPCWSTR)0x0) {
        pWVar2 = StrDupW(*(LPCWSTR *)(param_1 + 0x24));
        piVar1[9] = (int)pWVar2;
        if (pWVar2 == (LPWSTR)0x0) {
          iVar5 = iVar6;
        }
      }
      if (*(LPCWSTR *)(param_1 + 0x28) != (LPCWSTR)0x0) {
        pWVar2 = StrDupW(*(LPCWSTR *)(param_1 + 0x28));
        piVar1[10] = (int)pWVar2;
        if (pWVar2 == (LPWSTR)0x0) {
          iVar5 = iVar6;
        }
      }
      if (*(ushort **)(param_1 + 0x14) == (ushort *)0x0) {
        piVar1[5] = 0;
      }
      else {
        pvVar3 = FUN_4052d908(*(ushort **)(param_1 + 0x14));
        piVar1[5] = (int)pvVar3;
        if (pvVar3 == (void *)0x0) {
          iVar5 = iVar6;
        }
      }
      if (*(HLOCAL *)(param_1 + 0x18) != (HLOCAL)0x0) {
        pvVar4 = FUN_4053b6c0(*(HLOCAL *)(param_1 + 0x18));
        piVar1[6] = (int)pvVar4;
        if (pvVar4 == (HLOCAL)0x0) {
          iVar5 = iVar6;
        }
      }
    }
    if ((iVar5 < 0) && (piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *param_2 = 0;
    }
    else {
      *param_2 = piVar1;
    }
  }
  return iVar5;
}



/* 4053e018 FUN_4053e018 */

/* Boundary evidence: original MIPS .pdata 4053e018..4053e06f. Semantic name remains unreviewed. */

LONG FUN_4053e018(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4053b744(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 4053e070 FUN_4053e070 */

/* Boundary evidence: original MIPS .pdata 4053e070..4053e24f. Semantic name remains unreviewed. */

int FUN_4053e070(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  HRESULT HVar3;
  HLOCAL pvVar4;
  HGLOBAL *phglobal;
  LPSTREAM local_70;
  int *local_6c;
  STATSTG SStack_68;
  uint local_20;
  
  local_20 = DAT_40544354;
  local_70 = (IStream *)0x0;
  local_6c = (int *)0x0;
  if (*(int *)(param_1 + 0x10) == 3) {
    FUN_40542538(DAT_40544354);
    return 0;
  }
  FUN_4053ba38(param_1);
  iVar1 = FUN_4053bfe0(param_1,param_2,&local_70);
  if ((iVar1 == 0) && (iVar1 = (**(code **)*param_2)(param_2,&DAT_4051649c,&local_6c), iVar1 == 0))
  {
    if (param_3 != 0) {
      *(undefined4 *)(param_1 + 0x10) = 2;
      iVar1 = (**(code **)(*local_6c + 0x1c))(local_6c,param_1 + 0x20);
      goto LAB_4053e1fc;
    }
    *(undefined4 *)(param_1 + 0x10) = 1;
    if (local_70 != (IStream *)0x0) {
LAB_4053e1a8:
      HVar3 = (*local_70->lpVtbl->Stat)(local_70,&SStack_68,1);
      phglobal = (HGLOBAL *)(param_1 + 0x18);
      iVar1 = GetHGlobalFromStream(local_70,phglobal);
      if ((HVar3 == 0) &&
         (pvVar4 = LocalReAlloc(*phglobal,SStack_68.cbSize.s.LowPart,2), pvVar4 != (HLOCAL)0x0)) {
        *phglobal = pvVar4;
      }
      goto LAB_4053e1fc;
    }
    iVar1 = CreateStreamOnHGlobal((HGLOBAL)0x0,0,&local_70);
    if (iVar1 != 0) goto LAB_4053e1fc;
    iVar2 = (**(code **)(*local_6c + 0x14))(local_6c,local_70);
    iVar1 = FUN_405233d0();
    if ((iVar1 == 0) || (iVar1 = -0x7ff3fff2, iVar2 != -0x7ff3fff2)) goto LAB_4053e1a8;
  }
  else {
LAB_4053e1fc:
    if (-1 < iVar1) goto LAB_4053e20c;
  }
  FUN_4053ba38(param_1);
LAB_4053e20c:
  IUnknown_AtomicRelease(&local_70);
  IUnknown_AtomicRelease(&local_6c);
  FUN_40542538(local_20);
  return iVar1;
}



/* 4053e250 FUN_4053e250 */

/* Boundary evidence: original MIPS .pdata 4053e250..4053e2eb. Semantic name remains unreviewed. */

undefined4 * FUN_4053e250(undefined4 *param_1)

{
  undefined4 local_18;
  DWORD local_14;
  DWORD aDStack_10 [2];
  
  *param_1 = &PTR_FUN_40515f80;
  param_1[3] = 1;
  param_1[1] = &PTR_LAB_40515f50;
  param_1[2] = &PTR_LAB_40515f28;
  local_18 = 0x10000;
  local_14 = 4;
  SHRegGetUSValueW(L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\TravelLog",L"MaxSize",
                   aDStack_10,param_1 + 4,&local_14,0,&local_18,4);
  return param_1;
}



/* 4053e2ec FUN_4053e2ec */

/* Boundary evidence: original MIPS .pdata 4053e2ec..4053e343. Semantic name remains unreviewed. */

LONG FUN_4053e2ec(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 3);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4053c638(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 4053e344 FUN_4053e344 */

/* Boundary evidence: original MIPS .pdata 4053e344..4053e433. Semantic name remains unreviewed. */

int FUN_4053e344(int *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *local_20 [2];
  
  iVar2 = -0x7fffbffb;
  iVar1 = FUN_4053c8b8((int)param_1,param_2,param_3,(int *)local_20);
  if (-1 < iVar1) {
    param_1[9] = param_3;
    if (param_1[7] != 0) {
      for (iVar1 = param_1[8]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x3c)) {
        if (iVar1 == param_1[7]) goto LAB_4053e3bc;
      }
      param_1[7] = 0;
    }
LAB_4053e3bc:
    if ((*(int *)(param_1[6] + 0x10) != 3) && (param_1[7] == 0)) {
      param_1[7] = param_1[6];
    }
    param_1[6] = (int)local_20[0];
    iVar2 = (**(code **)(*local_20[0] + 0xc))(local_20[0],param_2);
    if (iVar2 < 0) {
      (**(code **)(*param_1 + 0x34))(param_1);
    }
  }
  return iVar2;
}



/* 4053e434 FUN_4053e434 */

/* Boundary evidence: original MIPS .pdata 4053e434..4053e5a7. Semantic name remains unreviewed. */

HRESULT FUN_4053e434(int param_1,undefined4 *param_2,undefined4 param_3,LPCWSTR param_4)

{
  HRESULT HVar1;
  int iVar2;
  int *piVar3;
  ushort *local_38;
  int *local_34;
  DWORD local_30 [2];
  LPCWSTR local_28;
  DWORD local_24;
  
  local_34 = (int *)0x0;
  FUN_40520168((int *)&local_28,0x824);
  local_30[0] = local_24;
  HVar1 = UrlCanonicalizeW(param_4,local_28,local_30,0x4000000);
  if ((-1 < HVar1) && (HVar1 = FUN_40522e60(param_3,local_28,&local_38), -1 < HVar1)) {
    piVar3 = (int *)(param_1 + -4);
    HVar1 = FUN_4053caa8((int)piVar3,param_2,local_38,(int *)&local_34);
    FUN_40537f64((int)local_38);
    if (-1 < HVar1) {
      if (*(int *)(param_1 + 0x18) != 0) {
        for (iVar2 = *(int *)(param_1 + 0x1c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x3c)) {
          if (iVar2 == *(int *)(param_1 + 0x18)) goto LAB_4053e520;
        }
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
LAB_4053e520:
      if ((*(int *)(*(int *)(param_1 + 0x14) + 0x10) != 3) && (*(int *)(param_1 + 0x18) == 0)) {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x14);
      }
      *(int **)(param_1 + 0x14) = local_34;
      HVar1 = (**(code **)(*local_34 + 0xc))(local_34,param_2);
      if (HVar1 < 0) {
        (**(code **)(*piVar3 + 0x34))(piVar3);
      }
    }
  }
  operator_delete(local_28);
  return HVar1;
}



/* 4053e5a8 FUN_4053e5a8 */

/* Boundary evidence: original MIPS .pdata 4053e5a8..4053e60f. Semantic name remains unreviewed. */

undefined4 FUN_4053e5a8(int param_1,undefined4 *param_2,ushort *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *local_10 [2];
  
  local_10[0] = *(undefined4 **)(param_1 + 0x20);
  FUN_4053caa8(param_1,param_2,param_3,(int *)local_10);
  if (local_10[0] == (undefined4 *)0x0) {
    *param_4 = 0;
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = (**(code **)*local_10[0])(local_10[0],&DAT_40513684,param_4);
  }
  return uVar1;
}



/* 4053e610 FUN_4053e610 */

/* Boundary evidence: original MIPS .pdata 4053e610..4053e7a7. Semantic name remains unreviewed. */

int FUN_4053e610(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_30 [2];
  
  puVar3 = (undefined4 *)FUN_4052d4e8(0x28);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_4053e250(puVar3);
  }
  if ((piVar4 == (int *)0x0) || (*(int *)(param_1 + 0x18) == 0)) {
    iVar5 = -0x7ff8fff2;
LAB_4053e730:
    if (-1 < iVar5) {
      (**(code **)*piVar4)(piVar4,&DAT_40513694,param_2);
      goto LAB_4053e760;
    }
  }
  else {
    piVar8 = piVar4 + 6;
    iVar5 = FUN_4053de6c(*(int *)(param_1 + 0x18),piVar8);
    if (-1 < iVar5) {
      piVar4[5] = *(int *)(param_1 + 0x14);
      iVar7 = *(int *)(*(int *)(param_1 + 0x18) + 0x3c);
      iVar1 = *piVar8;
      while ((iVar7 != 0 && (iVar6 = FUN_4053de6c(iVar7,local_30), iVar2 = local_30[0], -1 < iVar6))
            ) {
        FUN_4053c274(iVar1,local_30[0]);
        iVar7 = *(int *)(iVar7 + 0x3c);
        iVar1 = iVar2;
      }
      iVar7 = *(int *)(*(int *)(param_1 + 0x18) + 0x38);
      iVar1 = *piVar8;
      while ((iVar7 != 0 && (iVar6 = FUN_4053de6c(iVar7,local_30), iVar2 = local_30[0], -1 < iVar6))
            ) {
        *(int *)(iVar1 + 0x38) = local_30[0];
        if (local_30[0] != 0) {
          FUN_4053c274(local_30[0],iVar1);
        }
        iVar7 = *(int *)(iVar7 + 0x38);
        iVar1 = iVar2;
      }
      piVar4[8] = iVar1;
      goto LAB_4053e730;
    }
  }
  *param_2 = 0;
LAB_4053e760:
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return iVar5;
}



/* 4053e7a8 FUN_4053e7a8 */

/* Boundary evidence: original MIPS .pdata 4053e7a8..4053e843. Semantic name remains unreviewed. */

undefined4 FUN_4053e7a8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4053e250(puVar1);
  }
  if (piVar2 == (int *)0x0) {
    *param_1 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,&DAT_40513694,param_1);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 4053e844 FUN_4053e844 */

/* Boundary evidence: original MIPS .pdata 4053e844..4053e89b. Semantic name remains unreviewed. */

LONG FUN_4053e844(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4053d538(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 4053e89c FUN_4053e89c */

/* Boundary evidence: original MIPS .pdata 4053e89c..4053e8ff. Semantic name remains unreviewed. */

void FUN_4053e89c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  *(int **)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 8) = param_5;
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = 0;
  (**(code **)(*param_2 + 4))(param_2);
  (**(code **)(**(int **)(param_1 + 0x18) + 4))();
  FUN_4053d5cc(param_1);
  return;
}



/* 4053e900 FUN_4053e900 */

/* Boundary evidence: original MIPS .pdata 4053e900..4053e9a7. Semantic name remains unreviewed. */

undefined4 FUN_4053e900(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_2 = 0;
  uVar2 = 0x8007000e;
  puVar1 = (undefined4 *)FUN_4052d4e8(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_40515fd8;
    puVar1[1] = 1;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_4053e89c((int)puVar1,*(int **)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                 *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8));
    *param_2 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 4053e9a8 FUN_4053e9a8 */

/* Boundary evidence: original MIPS .pdata 4053e9a8..4053e9ff. Semantic name remains unreviewed. */

LONG FUN_4053e9a8(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4053d9b0(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 4053ea00 FUN_4053ea00 */

/* Boundary evidence: original MIPS .pdata 4053ea00..4053ea53. Semantic name remains unreviewed. */

undefined4 * FUN_4053ea00(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  *param_1 = &PTR_FUN_4051605c;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 4053ea54 FUN_4053ea54 */

/* Boundary evidence: original MIPS .pdata 4053ea54..4053eaa7. Semantic name remains unreviewed. */

LONG FUN_4053ea54(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_4053db7c(param_1,1);
  }
  return LVar1;
}



/* 4053eaa8 FUN_4053eaa8 */

/* Boundary evidence: original MIPS .pdata 4053eaa8..4053eb5b. Semantic name remains unreviewed. */

undefined4 FUN_4053eaa8(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4053ea00(puVar1,param_1,param_2);
  }
  if (piVar2 == (int *)0x0) {
    *param_3 = 0;
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)*piVar2)(piVar2,&DAT_4051672c,param_3);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 4053ebc0 FUN_4053ebc0 */

undefined4 * FUN_4053ebc0(undefined4 *param_1,int param_2)

{
  param_1[2] = &PTR_LAB_40516094;
  *param_1 = &PTR_FUN_40515ef0;
  param_1[1] = &PTR_LAB_40515edc;
  param_1[2] = &PTR_LAB_40515ec8;
  param_1[3] = 1;
  if (param_2 != 0) {
    param_1[4] = 2;
  }
  return param_1;
}



/* 4053ec0c FUN_4053ec0c */

/* Boundary evidence: original MIPS .pdata 4053ec0c..4053ecfb. Semantic name remains unreviewed. */

undefined4 FUN_4053ec0c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = FUN_4052dd40(0x60000014,0,0);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)FUN_4052d4e8(0x40);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_4053ebc0(puVar3,param_3);
    }
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x8007000e;
    }
    else {
      if (*(int *)(param_1 + 0x18) == 0) {
        *(undefined4 **)(param_1 + 0x20) = puVar3;
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0x18) + 0x3c);
        if (iVar1 != 0) {
          iVar1 = FUN_4053b9ec(iVar1);
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
        }
        FUN_4053c274(*(int *)(param_1 + 0x18),(int)puVar3);
      }
      iVar1 = FUN_4053b960((int)puVar3);
      *(undefined4 **)(param_1 + 0x18) = puVar3;
      *(int *)(param_1 + 0x14) = iVar1 + *(int *)(param_1 + 0x14);
      uVar2 = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4053ecfc FUN_4053ecfc */

/* Boundary evidence: original MIPS .pdata 4053ecfc..4053edb7. Semantic name remains unreviewed. */

undefined4 FUN_4053ecfc(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  uVar2 = 0x8007000e;
  puVar1 = (undefined4 *)FUN_4052d4e8(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_40515fd8;
    puVar1[1] = 1;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_4053e89c((int)puVar1,(int *)(param_1 + -4),param_2,0,param_4);
    *param_3 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* 4053edb8 FUN_4053edb8 */

/* Boundary evidence: original MIPS .pdata 4053edb8..4053efbf. Semantic name remains unreviewed. */

int FUN_4053edb8(int param_1,undefined4 *param_2,undefined4 param_3,int param_4,undefined4 param_5,
                int param_6)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *local_20;
  int *local_1c;
  
  FUN_4053cb6c(param_1 + -4,param_2,param_3,(int *)&local_1c);
  piVar3 = local_1c;
  if (local_1c == (int *)0x0) {
    piVar3 = *(int **)(param_1 + 0x14);
  }
  piVar1 = (int *)FUN_4052d4e8(0x40);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[2] = (int)&PTR_LAB_40516094;
    *piVar1 = (int)&PTR_FUN_40515ef0;
    piVar1[1] = (int)&PTR_LAB_40515edc;
    piVar1[2] = (int)&PTR_LAB_40515ec8;
    piVar1[3] = 1;
  }
  if (piVar1 == (int *)0x0) {
    iVar4 = -0x7ff8fff2;
  }
  else {
    if (param_4 == 0) {
      piVar5 = (int *)piVar3[0xf];
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 4))(piVar5);
      }
      FUN_4053c274((int)piVar1,(int)piVar5);
      FUN_4053c274((int)piVar3,(int)piVar1);
    }
    else {
      (**(code **)(*piVar3 + 4))(piVar3);
      iVar2 = piVar3[0xe];
      piVar1[0xe] = iVar2;
      if (iVar2 != 0) {
        FUN_4053c274(iVar2,(int)piVar1);
      }
      piVar3[0xe] = (int)piVar1;
      FUN_4053c274((int)piVar1,(int)piVar3);
      if (piVar3 == *(int **)(param_1 + 0x1c)) {
        *(int **)(param_1 + 0x1c) = piVar1;
      }
    }
    iVar4 = (**(code **)(*piVar1 + 0x10))(piVar1,param_5,0);
    iVar2 = FUN_4053b960((int)piVar1);
    *(int *)(param_1 + 0x10) = iVar2 + *(int *)(param_1 + 0x10);
    iVar2 = (**(code **)*param_2)(param_2,&DAT_40513564,&local_20);
    if (-1 < iVar2) {
      (**(code **)(*local_20 + 0x48))();
      (**(code **)(*local_20 + 8))();
      iVar4 = 0;
    }
    if ((-1 < iVar4) && (param_6 != 0)) {
      iVar4 = (**(code **)*piVar1)(piVar1,&DAT_4051694c);
    }
  }
  return iVar4;
}



/* 4053efc0 FUN_4053efc0 */

/* Boundary evidence: original MIPS .pdata 4053efc0..4053f06b. Semantic name remains unreviewed. */

undefined4 * FUN_4053efc0(undefined4 *param_1,int *param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  *param_1 = &PTR_FUN_40516024;
  param_1[1] = &PTR_LAB_40516004;
  param_1[2] = 1;
  param_1[3] = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  if (param_3 != (LPCWSTR)0x0) {
    SHStrDupW(param_3,(LPWSTR *)(param_1 + 4));
  }
  if (param_4 != (LPCWSTR)0x0) {
    SHStrDupW(param_4,(LPWSTR *)(param_1 + 5));
  }
  return param_1;
}



/* 4053f06c FUN_4053f06c */

/* Boundary evidence: original MIPS .pdata 4053f06c..4053f133. Semantic name remains unreviewed. */

undefined4
FUN_4053f06c(int param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_4052d4e8(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_4053efc0(puVar1,*(int **)(param_1 + 8),param_2,param_3);
  }
  if (piVar2 == (int *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    uVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x28))
                      (*(int **)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),param_4,param_5,piVar2,
                       param_6);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return uVar3;
}



/* 4053f134 FUN_4053f134 */

/* Boundary evidence: original MIPS .pdata 4053f134..4053f1bb. Semantic name remains unreviewed. */

undefined4 FUN_4053f134(undefined4 param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_2,&DAT_405162fc,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_405167bc,0x10), iVar1 == 0)) {
    *param_3 = param_1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80004002;
    *param_3 = 0;
  }
  return uVar2;
}



/* 4053f1bc FUN_4053f1bc */

/* Boundary evidence: original MIPS .pdata 4053f1bc..4053f1d7. Semantic name remains unreviewed. */

void FUN_4053f1bc(undefined4 param_1,SIZE_T param_2)

{
  LocalAlloc(0x40,param_2);
  return;
}



/* 4053f1d8 FUN_4053f1d8 */

/* Boundary evidence: original MIPS .pdata 4053f1d8..4053f1ff. Semantic name remains unreviewed. */

void FUN_4053f1d8(undefined4 param_1,HLOCAL param_2,SIZE_T param_3)

{
  LocalReAlloc(param_2,param_3,0x42);
  return;
}



/* 4053f200 FUN_4053f200 */

/* Boundary evidence: original MIPS .pdata 4053f200..4053f21b. Semantic name remains unreviewed. */

void FUN_4053f200(undefined4 param_1,HLOCAL param_2)

{
  LocalFree(param_2);
  return;
}



/* 4053f21c FUN_4053f21c */

/* Boundary evidence: original MIPS .pdata 4053f21c..4053f237. Semantic name remains unreviewed. */

void FUN_4053f21c(undefined4 param_1,HLOCAL param_2)

{
  LocalSize(param_2);
  return;
}



/* 4053f238 FUN_4053f238 */

/* Boundary evidence: original MIPS .pdata 4053f238..4053f297. Semantic name remains unreviewed. */

void FUN_4053f238(int *param_1)

{
  if (DAT_4054a000 == (undefined **)0x0) {
    DAT_4054a000 = &PTR_PTR_40516158;
  }
  else {
    (**(code **)(*DAT_4054a000 + 4))();
  }
  *param_1 = (int)DAT_4054a000;
  return;
}



/* 4053f298 FUN_4053f298 */

/* Boundary evidence: original MIPS .pdata 4053f298..4053f2d3. Semantic name remains unreviewed. */

void FUN_4053f298(undefined4 param_1)

{
  int *local_10 [2];
  
  FUN_4053f238((int *)local_10);
  (**(code **)(*local_10[0] + 0xc))(local_10[0],param_1);
  return;
}



/* 4053f2d4 FUN_4053f2d4 */

/* Boundary evidence: original MIPS .pdata 4053f2d4..4053f30f. Semantic name remains unreviewed. */

void FUN_4053f2d4(undefined4 param_1)

{
  int *local_10 [2];
  
  FUN_4053f238((int *)local_10);
  (**(code **)(*local_10[0] + 0x14))(local_10[0],param_1);
  return;
}



/* 4053f310 FUN_4053f310 */

/* Boundary evidence: original MIPS .pdata 4053f310..4053f337. Semantic name remains unreviewed. */

void FUN_4053f310(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_4051615c,param_2,param_3);
  return;
}



/* 4053f338 FUN_4053f338 */

/* Boundary evidence: original MIPS .pdata 4053f338..4053f3f3. Semantic name remains unreviewed. */

HRESULT FUN_4053f338(int param_1,IID *param_2)

{
  HRESULT HVar1;
  int *piVar2;
  undefined4 local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  HVar1 = CoGetClassObject(param_2,5,(LPVOID)0x0,(IID *)&DAT_4051630c,(LPVOID *)(param_1 + 8));
  if (-1 < HVar1) {
    piVar2 = *(LPVOID *)(param_1 + 8);
    (**(code **)(*piVar2 + 0x10))(piVar2,1);
    local_1c = 4;
    local_20 = 0;
    SHRegGetUSValueW(L"Software\\Microsoft\\Internet Explorer\\Main",L"DisableExcelCompat",
                     aDStack_18,&local_20,&local_1c,0,(void *)0x0,0);
  }
  return HVar1;
}



/* 4053f3f4 FUN_4053f3f4 */

/* Boundary evidence: original MIPS .pdata 4053f3f4..4053f44b. Semantic name remains unreviewed. */

void FUN_4053f3f4(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_4051616c;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,0);
    IUnknown_AtomicRelease((void **)(param_1 + 2));
  }
  return;
}



/* 4053f44c FUN_4053f44c */

/* Boundary evidence: original MIPS .pdata 4053f44c..4053f4f3. Semantic name remains unreviewed. */

undefined4 FUN_4053f44c(IID *param_1)

{
  int *piVar1;
  HRESULT HVar2;
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  piVar1 = (int *)FUN_4052d4e8(0x10);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)&PTR_FUN_4051616c;
    piVar1[1] = 1;
  }
  if (piVar1 != (int *)0x0) {
    HVar2 = FUN_4053f338((int)piVar1,param_1);
    if (-1 < HVar2) {
      (**(code **)*piVar1)(piVar1,&DAT_405162fc,local_18);
    }
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return local_18[0];
}



/* 4053f4f4 FUN_4053f4f4 */

/* Boundary evidence: original MIPS .pdata 4053f4f4..4053f537. Semantic name remains unreviewed. */

int FUN_4053f4f4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1] + -1;
  param_1[1] = iVar1;
  if (iVar1 == 0) {
    FUN_4053f3f4(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 4053f538 FUN_4053f538 */

/* Boundary evidence: original MIPS .pdata 4053f538..4053f61f. Semantic name remains unreviewed. */

void * FUN_4053f538(short *param_1)

{
  short sVar1;
  void *pvVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  void *local_10 [2];
  
  local_10[0] = (void *)0x0;
  if (param_1 == (short *)0x0) {
    return (void *)0x0;
  }
  if ((*param_1 == 0x400c) && (*(short **)(param_1 + 4) != (short *)0x0)) {
    param_1 = *(short **)(param_1 + 4);
  }
  sVar1 = *param_1;
  if (sVar1 != 3) {
    if (sVar1 == 8) {
      return (void *)0x0;
    }
    if (sVar1 == 9) {
      puVar3 = *(undefined4 **)(param_1 + 4);
LAB_4053f5cc:
      FUN_4052cec4(puVar3,local_10);
      return local_10[0];
    }
    if (sVar1 != 0x13) {
      if (sVar1 != 0x2011) {
        if (sVar1 != 0x4009) {
          return (void *)0x0;
        }
        if (*(undefined4 **)(param_1 + 4) == (undefined4 *)0x0) {
          return (void *)0x0;
        }
        puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 4);
        goto LAB_4053f5cc;
      }
      puVar4 = *(ushort **)(*(int *)(param_1 + 4) + 0xc);
      goto LAB_4053f60c;
    }
  }
  puVar4 = *(ushort **)(param_1 + 4);
  if ((int)puVar4 < 0xffff) {
    return (void *)0x0;
  }
LAB_4053f60c:
  pvVar2 = FUN_4052ec9c(puVar4);
  return pvVar2;
}



/* 4053f620 FUN_4053f620 */

undefined4 FUN_4053f620(short *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*param_1 == 0x400c) && (*(short **)(param_1 + 4) != (short *)0x0)) {
    param_1 = *(short **)(param_1 + 4);
  }
  if (*param_1 == 8) {
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}



/* 4053f65c FUN_4053f65c */

/* Boundary evidence: original MIPS .pdata 4053f65c..4053f6e3. Semantic name remains unreviewed. */

undefined4 FUN_4053f65c(int param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  if (*(int **)(param_1 + 200) != (int *)0x0) {
    if (*(int *)(param_1 + 0xd4) != 0) {
      (**(code **)(**(int **)(param_1 + 200) + 0x14))();
      *(undefined4 *)(param_1 + 0xd4) = 0;
    }
    (**(code **)(**(int **)(param_1 + 200) + 8))();
  }
  *(int **)(param_1 + 200) = param_2;
  return 0;
}



/* 4053f6e4 FUN_4053f6e4 */

/* Boundary evidence: original MIPS .pdata 4053f6e4..4053f72f. Semantic name remains unreviewed. */

undefined4 FUN_4053f6e4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = *(undefined4 *)(param_1 + 200);
  if (*(int **)(param_1 + 200) == (int *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    (**(code **)(**(int **)(param_1 + 200) + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 4053f730 FUN_4053f730 */

/* Boundary evidence: original MIPS .pdata 4053f730..4053f8cb. Semantic name remains unreviewed. */

void FUN_4053f730(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  LPWSTR pWVar2;
  int *local_230;
  int *local_22c;
  undefined4 local_228 [2];
  WCHAR aWStack_220 [262];
  uint local_14;
  
  local_14 = DAT_40544354;
  if (*(int **)(param_1 + 0xd4) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xd4) + 8))();
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  if (*(int **)(param_1 + 0xd0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xd0) + 8))();
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (param_3 != (int *)0x0) {
    *(int **)(param_1 + 0xd4) = param_3;
    (**(code **)(*param_3 + 4))(param_3);
  }
  if (param_2 != (int *)0x0) {
    local_230 = (int *)0x0;
    local_22c = (int *)0x0;
    *(int **)(param_1 + 0xd0) = param_2;
    (**(code **)(*param_2 + 4))(param_2);
    (**(code **)(*param_2 + 0x28))(param_2,L"__HTMLLOADOPTIONS",&local_230);
    if (local_230 != (int *)0x0) {
      (**(code **)*local_230)(local_230,&UNK_4051690c,&local_22c);
      piVar1 = local_22c;
      if (local_22c != (int *)0x0) {
        local_228[0] = 0x104;
        memset(aWStack_220,0,0x20a);
        (**(code **)(*piVar1 + 0xc))(piVar1,1,aWStack_220,local_228);
        if (*(HLOCAL *)(param_1 + 0xf8) != (HLOCAL)0x0) {
          LocalFree(*(HLOCAL *)(param_1 + 0xf8));
        }
        pWVar2 = StrDupW(aWStack_220);
        *(LPWSTR *)(param_1 + 0xf8) = pWVar2;
        (**(code **)(*local_22c + 8))();
      }
      (**(code **)(*local_230 + 8))();
    }
  }
  FUN_40542538(local_14);
  return;
}



/* 4053f8cc FUN_4053f8cc */

/* Boundary evidence: original MIPS .pdata 4053f8cc..4053f97f. Semantic name remains unreviewed. */

void FUN_4053f8cc(int param_1)

{
  if (*(int **)(param_1 + 0xcc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xcc) + 8))();
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  if (*(int **)(param_1 + 200) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 200) + 8))();
    *(undefined4 *)(param_1 + 200) = 0;
  }
  if (*(HLOCAL *)(param_1 + 0xf4) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0xf4));
    *(undefined4 *)(param_1 + 0xf4) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xd4);
    *(undefined4 *)(param_1 + 0xd4) = 0;
  }
  if (*(int *)(param_1 + 0xd0) != 0) {
    *(int *)(param_1 + 200) = *(int *)(param_1 + 0xd0);
    *(undefined4 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xf8) != 0) {
    *(int *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf8);
    *(undefined4 *)(param_1 + 0xf8) = 0;
  }
  return;
}



/* 4053f980 FUN_4053f980 */

/* Boundary evidence: original MIPS .pdata 4053f980..4053f9eb. Semantic name remains unreviewed. */

int FUN_4053f980(undefined4 *param_1)

{
  int iVar1;
  int *local_10 [2];
  
  iVar1 = (**(code **)*param_1)(param_1,&DAT_4051645c,local_10);
  if (-1 < iVar1) {
    (**(code **)(*local_10[0] + 0xa4))(local_10[0],1);
    (**(code **)(*local_10[0] + 8))();
  }
  return iVar1;
}



/* 4053f9ec FUN_4053f9ec */

/* Boundary evidence: original MIPS .pdata 4053f9ec..4053fa63. Semantic name remains unreviewed. */

undefined4 FUN_4053f9ec(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_10 [2];
  
  if (*(int *)(param_1 + 0xa8) == 0) {
    uVar1 = 1;
  }
  else {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x2c))
                      (*(int **)(param_1 + 0xa8),0,param_2,local_10);
    if (-1 < iVar2) {
      (**(code **)(**(int **)(param_1 + 0xa8) + 0x5c))(*(int **)(param_1 + 0xa8),local_10[0]);
      FUN_40537f64(local_10[0]);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 4053fa64 FUN_4053fa64 */

/* Boundary evidence: original MIPS .pdata 4053fa64..4053faab. Semantic name remains unreviewed. */

void FUN_4053fa64(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xec);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,&DAT_405163dc,2,0,param_2,0);
  }
  return;
}



/* 4053faac FUN_4053faac */

/* Boundary evidence: original MIPS .pdata 4053faac..4053fc03. Semantic name remains unreviewed. */

void FUN_4053faac(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_20;
  BSTR local_1c;
  int *local_18 [2];
  
  local_20 = (int *)0x0;
  if (((param_2 != (undefined4 *)0x0) && (param_3 != (undefined4 *)0x0)) &&
     (iVar1 = (**(code **)*param_3)(param_3,&UNK_4051699c,&local_20), -1 < iVar1)) {
    local_1c = (BSTR)0x0;
    iVar1 = (**(code **)(*local_20 + 0x14))(local_20,&local_1c);
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x128);
      *(undefined4 *)(iVar1 + 0x74) = 1;
      *(undefined4 *)(iVar1 + 100) = 1;
      *(undefined4 *)(iVar1 + 0x70) = 1;
      *(undefined4 *)(iVar1 + 0x78) = 1;
      *(undefined4 *)(iVar1 + 0x7c) = 1;
      *(undefined4 *)(iVar1 + 0x6c) = 1;
      *(undefined4 *)(iVar1 + 0x88) = 1;
      *(undefined4 *)(iVar1 + 0x80) = 2;
      *(undefined4 *)(iVar1 + 0x84) = 2;
      *(undefined4 *)(iVar1 + 0x68) = 2;
      *(undefined4 *)(iVar1 + 0x8c) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x90) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x94) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x98) = 0xffffffff;
      if (local_1c != (BSTR)0x0) {
        FUN_40539448();
        SysFreeString(local_1c);
      }
      iVar1 = (**(code **)*param_2)(param_2,&DAT_405162cc,local_18);
      if (-1 < iVar1) {
        FUN_40539448();
        (**(code **)(*local_18[0] + 8))();
      }
    }
    (**(code **)(*local_20 + 8))();
  }
  return;
}



/* 4053fc04 FUN_4053fc04 */

/* Boundary evidence: original MIPS .pdata 4053fc04..4053fcc3. Semantic name remains unreviewed. */

void FUN_4053fc04(int param_1,int *param_2)

{
  int iVar1;
  int local_1068 [2];
  undefined1 auStack_1060 [4168];
  uint local_18;
  
  local_18 = DAT_40544354;
  if ((*(int *)(param_1 + 0xd8) != 0) &&
     (iVar1 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x58))(*(int **)(param_1 + 0xa8),local_1068)
     , -1 < iVar1)) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x28))
                      (*(int **)(param_1 + 0xa8),local_1068[0],auStack_1060,0x8000);
    if (-1 < iVar1) {
      (**(code **)(*param_2 + 0x1c))(param_2,0x40000000,0,0,0,auStack_1060,0);
    }
    FUN_40537f64(local_1068[0]);
  }
  FUN_40542538(local_18);
  return;
}



/* 4053fcc4 FUN_4053fcc4 */

/* Boundary evidence: original MIPS .pdata 4053fcc4..4053fe7f. Semantic name remains unreviewed. */

undefined4 FUN_4053fcc4(int param_1,void *param_2,void *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  *param_4 = 0;
  iVar1 = memcmp(param_2,&DAT_4051640c,0x10);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)(param_1 + 0xf8);
LAB_4053fd10:
    uVar2 = (**(code **)*puVar3)(puVar3,param_3,param_4);
  }
  else {
    iVar1 = memcmp(param_2,&DAT_4051664c,0x10);
    if (iVar1 == 0) {
      iVar1 = memcmp(param_3,&DAT_4051662c,0x10);
      if ((iVar1 == 0) && (*(int *)(param_1 + 0x9c) != 0)) {
        *param_4 = *(int *)(param_1 + 0x9c);
        piVar4 = *(int **)(param_1 + 0x9c);
      }
      else {
        iVar1 = memcmp(param_3,&DAT_405169ac,0x10);
        if ((iVar1 != 0) || (*(int *)(param_1 + 0xa0) == 0)) {
          puVar3 = (undefined4 *)(param_1 + -0x2c);
          goto LAB_4053fd10;
        }
        *param_4 = *(int *)(param_1 + 0xa0);
        piVar4 = *(int **)(param_1 + 0xa0);
      }
LAB_4053fe08:
      (**(code **)(*piVar4 + 4))();
      if (*param_4 != 0) {
        return 0;
      }
    }
    else {
      iVar1 = memcmp(param_2,&DAT_40512c34,0x10);
      if (iVar1 == 0) {
        iVar1 = memcmp(param_3,&DAT_405169ac,0x10);
        if ((iVar1 == 0) && (*(int *)(param_1 + 0xa8) != 0)) {
          *param_4 = *(int *)(param_1 + 0xa8);
          piVar4 = *(int **)(param_1 + 0xa8);
          goto LAB_4053fe08;
        }
      }
      else {
        piVar4 = *(int **)(param_1 + 0x98);
        if (piVar4 != (int *)0x0) {
          uVar2 = (**(code **)(*piVar4 + 0xc))(piVar4,param_2,param_3,param_4);
          return uVar2;
        }
      }
    }
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 4053fe80 FUN_4053fe80 */

/* Boundary evidence: original MIPS .pdata 4053fe80..405400eb. Semantic name remains unreviewed. */

undefined4
FUN_4053fe80(int param_1,void *param_2,int param_3,undefined4 param_4,short *param_5,
            undefined2 *param_6)

{
  int iVar1;
  BSTR pOVar2;
  int *piVar3;
  undefined4 uVar4;
  
  if (param_2 == (void *)0x0) {
LAB_405400bc:
    uVar4 = 0x80040104;
  }
  else {
    iVar1 = memcmp(&DAT_405163dc,param_2,0x10);
    if (iVar1 == 0) {
      if (param_3 == 2) {
        FUN_4053fa64(param_1 + -0x30,0);
        return 0;
      }
      if ((param_3 == 0x14) || (param_3 == 0x25)) {
        piVar3 = *(int **)(param_1 + 0xb4);
        if (piVar3 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar3 + 0x10))(piVar3,param_2,param_3,param_4,param_5,param_6);
          return uVar4;
        }
        return 0;
      }
      if ((param_3 != 0x2d) && (param_3 == 0x2e)) {
        if (*(OLECHAR **)(param_1 + 0xc4) == (OLECHAR *)0x0) {
          if (param_6 != (undefined2 *)0x0) {
            *param_6 = 0;
          }
        }
        else if (param_6 != (undefined2 *)0x0) {
          pOVar2 = SysAllocString(*(OLECHAR **)(param_1 + 0xc4));
          *(BSTR *)(param_6 + 4) = pOVar2;
          if (pOVar2 != (BSTR)0x0) {
            *param_6 = 8;
            return 0;
          }
          return 0x8007000e;
        }
        return 0x80004005;
      }
    }
    else {
      iVar1 = memcmp(&DAT_4051676c,param_2,0x10);
      if (iVar1 == 0) {
        piVar3 = *(int **)(param_1 + 0xb4);
        if (piVar3 != (int *)0x0) {
          uVar4 = (**(code **)(*piVar3 + 0x10))
                            (piVar3,&DAT_4051676c,param_3,param_4,param_5,param_6);
          return uVar4;
        }
      }
      else {
        iVar1 = memcmp(&DAT_405163ec,param_2,0x10);
        if (iVar1 == 0) {
          if (param_3 == 0x3a) {
            FUN_40541d6c();
            return 0;
          }
        }
        else {
          iVar1 = memcmp(&DAT_405163cc,param_2,0x10);
          if (iVar1 != 0) goto LAB_405400bc;
          if ((param_3 == 0) && (*param_5 != 3)) {
            return 0x80070057;
          }
        }
      }
    }
    uVar4 = 0x80040100;
  }
  return uVar4;
}



/* 405400ec FUN_405400ec */

/* Boundary evidence: original MIPS .pdata 405400ec..4054014b. Semantic name remains unreviewed. */

uint FUN_405400ec(int param_1)

{
  int *piVar1;
  undefined4 local_10;
  uint local_c;
  
  piVar1 = *(int **)(param_1 + 0xec);
  if (piVar1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    local_10 = 2;
    local_c = 0;
    (**(code **)(*piVar1 + 0xc))(piVar1,&DAT_405163dc,1,&local_10,0);
    local_c = local_c & 2;
  }
  return local_c;
}



/* 4054014c FUN_4054014c */

/* Boundary evidence: original MIPS .pdata 4054014c..40540273. Semantic name remains unreviewed. */

undefined4 FUN_4054014c(int param_1,void *param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if ((param_2 == (void *)0x0) || (iVar1 = memcmp(&DAT_405163dc,param_2,0x10), iVar1 != 0)) {
    uVar3 = 0x80040104;
  }
  else {
    if (param_3 != 0) {
      puVar4 = (undefined4 *)(param_4 + 4);
      do {
        iVar1 = puVar4[-1];
        if (iVar1 == 2) {
          uVar2 = FUN_405400ec(param_1 + -0x30);
          uVar3 = 2;
          if (uVar2 == 0) {
            uVar3 = 0;
          }
          *puVar4 = uVar3;
        }
        else if (iVar1 == 0x14) {
          if (((*(uint *)(param_1 + 0xd0) & 4) != 0) || (uVar3 = 2, *(int *)(param_1 + 0xb4) == 0))
          {
            uVar3 = 0;
          }
          *puVar4 = uVar3;
        }
        else if (iVar1 == 0x15) {
          uVar3 = 0;
          if ((*(uint *)(param_1 + 0xd0) & 2) == 0) {
            uVar3 = 2;
          }
          *puVar4 = uVar3;
        }
        else {
          *puVar4 = 0;
        }
        param_3 = param_3 + -1;
        puVar4 = puVar4 + 2;
      } while (param_3 != 0);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 0;
      param_5[1] = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 40540274 FUN_40540274 */

/* Boundary evidence: original MIPS .pdata 40540274..405403a3. Semantic name remains unreviewed. */

int FUN_40540274(int param_1,undefined4 param_2,undefined4 param_3,wchar_t *param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *local_28 [2];
  
  *param_5 = 0;
  puVar1 = *(undefined4 **)(param_1 + 0xa8);
  iVar2 = -0x7fffbffb;
  if ((puVar1 != (undefined4 *)0x0) &&
     (iVar2 = (**(code **)*puVar1)(puVar1,&DAT_40513584,local_28), -1 < iVar2)) {
    iVar2 = (**(code **)(*local_28[0] + 0x180))(local_28[0],param_2,param_3,1,param_5);
    if (iVar2 < 0) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0xa8) + 0x30))
                        (*(int **)(param_1 + 0xa8),iVar2,param_3);
    }
    else if ((param_4 != (wchar_t *)0x0) && (*param_4 != L'\0')) {
      iVar2 = FUN_4051fce4((ushort *)*param_5,param_4);
      *param_5 = iVar2;
      if (iVar2 == 0) {
        iVar2 = -0x7ff8fff2;
      }
      else {
        iVar2 = 0;
      }
    }
    (**(code **)(*local_28[0] + 8))();
  }
  return iVar2;
}



/* 405403a4 FUN_405403a4 */

/* Boundary evidence: original MIPS .pdata 405403a4..40540b9f. Semantic name remains unreviewed. */

int FUN_405403a4(undefined4 *param_1,int *param_2,wchar_t *param_3,uint param_4,int param_5,
                int param_6,LPCWSTR param_7,OLECHAR *param_8)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  OLECHAR *pOVar14;
  _union_2260 _Var15;
  wchar_t *pwVar16;
  int iVar17;
  int *local_10d0;
  int *local_10cc;
  OLECHAR *local_10c8;
  wchar_t *local_10c4;
  int local_10c0;
  LPCITEMIDLIST local_10bc;
  LPCWSTR local_10b8;
  void *local_10b4;
  OLECHAR *local_10b0;
  wchar_t *local_10ac;
  int *local_10a8;
  int local_10a4;
  STGMEDIUM local_10a0;
  ULONG local_1090;
  undefined2 local_1088;
  undefined1 auStack_1086 [6];
  int local_1080;
  WCHAR local_1078 [2086];
  uint local_2c;
  
  local_2c = DAT_40544354;
  iVar17 = 0;
  local_10b8 = param_7;
  local_10c8 = param_8;
  local_10bc = (LPCITEMIDLIST)0x0;
  local_10cc = (int *)0x0;
  local_10a8 = (int *)0x0;
  local_10b4 = (void *)0x0;
  local_10c4 = param_3;
  if (((param_4 & 0x20000000) == 0) && (param_1[0x3b] != 0)) {
    local_1088 = 0;
    memset(auStack_1086,0,0xe);
    memset((void *)((int)&local_10a0.tymed + 2),0,0xe);
    local_10a0.tymed = CONCAT22(local_10a0.tymed._2_2_,3);
    local_10a0.pUnkForRelease = (IUnknown *)0x1;
    iVar2 = (**(code **)(*(int *)param_1[0x3b] + 0x10))
                      ((int *)param_1[0x3b],&DAT_405163ec,0x17,0,&local_10a0,&local_1088);
    if (-1 < iVar2) {
      iVar17 = FUN_4052d508(local_1080);
    }
  }
  if ((DAT_4054458c == 1) || ((param_4 & 2) == 0)) {
    uVar5 = 0x80000001;
  }
  else {
    uVar5 = 0x80000002;
  }
  uVar6 = 0x10000;
  if ((param_4 & 0x20000000) == 0) {
    uVar6 = 0;
  }
  uVar7 = 0x8000000;
  if ((param_4 & 0x8000000) == 0) {
    uVar7 = 0;
  }
  uVar11 = 0x4000000;
  if ((param_4 & 0x4000000) == 0) {
    uVar11 = 0;
  }
  uVar8 = 0x2000000;
  if ((param_4 & 0x2000000) == 0) {
    uVar8 = 0;
  }
  uVar9 = 0x1000000;
  if ((param_4 & 0x1000000) == 0) {
    uVar9 = 0;
  }
  uVar12 = 0x10000000;
  if ((param_4 & 0x400000) == 0) {
    uVar12 = 0;
  }
  uVar10 = 0x800000;
  if ((param_4 & 0x200000) == 0) {
    uVar10 = 0;
  }
  uVar13 = 0x20000;
  if ((param_4 & 0x100000) == 0) {
    uVar13 = 0;
  }
  uVar13 = uVar13 | uVar10 | uVar12 | uVar9 | uVar8 | uVar11 | uVar7 | uVar6 | uVar5;
  local_10ac = L"863a99a0-21bc-11d0-82b4-00a0c90c29c5";
  if ((param_2 != (int *)0x0) &&
     (iVar2 = (**(code **)(*param_2 + 0x28))
                        (param_2,L"863a99a0-21bc-11d0-82b4-00a0c90c29c5",&local_10a8), -1 < iVar2))
  {
    iVar2 = (**(code **)*local_10a8)(local_10a8,&UNK_405168fc,&local_10cc);
    if (iVar2 < 0) {
      local_10cc = (int *)0x0;
    }
    (**(code **)(*local_10a8 + 8))();
    (**(code **)*param_1)(param_1,&DAT_405162fc,&local_10b4);
  }
  if ((param_4 & 0x20) != 0) {
    uVar13 = uVar13 | 0x40000000;
  }
  if (((uVar13 & 2) == 0) || (DAT_4054458c != 0)) {
    if (local_10cc != (int *)0x0) {
      (**(code **)(*local_10cc + 0x10))(local_10cc,local_10b4);
    }
    iVar17 = FUN_40540274((int)param_1,iVar17,local_10c8,local_10c4,(int *)&local_10bc);
    pwVar16 = L"863a99a0-21bc-11d0-82b4-00a0c90c29c5";
    if (-1 < iVar17) {
      iVar17 = (**(code **)(*(int *)param_1[0x36] + 0x2c))((int *)param_1[0x36],local_10bc,uVar13);
    }
  }
  else {
    local_10b0 = (OLECHAR *)0x0;
    local_1090 = 0;
    local_10a0.tymed = 0;
    local_10a0.u.hBitmap = (HBITMAP)0x0;
    local_10a0.pUnkForRelease = (IUnknown *)0x0;
    if (((param_4 & 2) != 0) &&
       (bVar1 = FUN_4052eccc(param_1[0x2b],0x60000009,0,0), CONCAT31(extraout_var,bVar1) != 0)) {
      iVar17 = -0x7ff8fffb;
      goto LAB_40540aec;
    }
    local_1078[0] = L'\0';
    if (local_10b8 != (LPCWSTR)0x0) {
      SHUnicodeToUnicode(local_10b8,local_1078,0x825);
    }
    _Var15.hBitmap = (HBITMAP)0x0;
    if ((param_5 != 0) && (FUN_40539448(), local_10a0.tymed == 1)) {
      _Var15 = local_10a0.u;
    }
    pOVar14 = local_10c8;
    iVar17 = FUN_40540274((int)param_1,iVar17,local_10c8,local_10c4,(int *)&local_10bc);
    if (-1 < iVar17) {
      local_10d0 = (int *)0x0;
      local_10c0 = 0;
      local_10a4 = 0;
      FUN_40536638((IUnknown *)param_1[0x13],param_2,pOVar14,(int *)&local_10d0,&local_10c0);
      if (local_10d0 == (int *)0x0) {
        if (local_10c0 != 0) goto LAB_40540a70;
        FUN_40536904((IUnknown *)param_1[0x13],(int *)&local_10d0,&local_10c0);
        if (local_10c0 == 0) {
          if (local_10d0 == (int *)0x0) {
            iVar2 = FUN_40533614((int)param_1);
            pOVar14 = local_10c8;
            if (iVar2 != 0) {
              iVar3 = StrCmpIW(local_1078,L"_blank");
              if (iVar3 == 0) {
                pOVar14 = L"";
              }
              else {
                pOVar14 = local_1078;
              }
              FUN_405364b0((IUnknown *)param_1[0x13],iVar2,local_10bc,local_10c4,0,pOVar14,
                           _Var15.hMetaFilePict,local_1090,local_10b0,&local_10a4);
              pOVar14 = local_10c8;
            }
            goto LAB_40540804;
          }
          goto LAB_40540810;
        }
      }
      else {
LAB_40540804:
        if (local_10c0 == 0) {
LAB_40540810:
          if (local_10a4 == 0) {
            iVar17 = FUN_40538ab8(local_10b8,(int *)&local_10d0);
            if (-1 < iVar17) {
              if (local_10cc != (int *)0x0) {
                FUN_4053faac((int)param_1,local_10d0,local_10cc);
                iVar17 = *local_10cc;
                DVar4 = GetTickCount();
                (**(code **)(iVar17 + 0xc))(local_10cc,local_10d0,DVar4);
                (**(code **)(*local_10cc + 8))();
                local_10cc = (int *)0x0;
                (**(code **)(*param_2 + 0x30))(param_2,local_10ac);
              }
              iVar17 = (**(code **)*local_10d0)(local_10d0,&DAT_4051664c,&local_10b8);
              if (-1 < iVar17) {
                if (param_6 == 0) {
                  iVar17 = (**(code **)*local_10d0)(local_10d0,&DAT_405163fc,&local_10c8);
                }
                if (-1 < iVar17) {
                  if (param_6 == 0) {
                    FUN_4053fc04((int)param_1,(int *)local_10c8);
                    iVar17 = (**(code **)(*(int *)local_10c8 + 0x1c))
                                       (local_10c8,param_4 & 0xfffffffd,param_2,param_5,0,pOVar14,
                                        local_10c4);
                  }
                  else {
                    iVar17 = (**(code **)(*(int *)local_10b8 + 0x14))
                                       (local_10b8,param_4 & 0xfffffffd,param_2,param_5,param_6);
                  }
                  FUN_4053f980(local_10d0);
                  if (param_6 == 0) {
                    (**(code **)(*(int *)local_10c8 + 8))();
                  }
                  if ((-1 < iVar17) && (param_5 != 0)) {
                    FUN_4053f730((int)param_1,(int *)0x0,(int *)0x0);
                  }
                }
                (**(code **)(*(int *)local_10b8 + 8))();
              }
            }
          }
          else {
            if (local_10cc != (int *)0x0) {
              (**(code **)(*local_10cc + 0x10))(local_10cc,local_10b4);
            }
            if (param_6 == 0) {
              iVar17 = FUN_40520600();
            }
            else {
              iVar17 = FUN_40520600();
            }
          }
        }
      }
      if (local_10d0 != (int *)0x0) {
        (**(code **)(*local_10d0 + 8))();
      }
    }
LAB_40540a70:
    if (local_10b0 != (OLECHAR *)0x0) {
      LocalFree(local_10b0);
      local_10b0 = (OLECHAR *)0x0;
    }
    pwVar16 = local_10ac;
    if (local_10a0.tymed != 0) {
      ReleaseStgMedium(&local_10a0);
      pwVar16 = local_10ac;
    }
  }
  if (local_10bc != (LPCITEMIDLIST)0x0) {
    FUN_40537f64((int)local_10bc);
  }
  if (local_10cc != (int *)0x0) {
    (**(code **)(*local_10cc + 8))();
    (**(code **)(*param_2 + 0x30))(param_2,pwVar16);
  }
LAB_40540aec:
  IUnknown_AtomicRelease(&local_10b4);
  FUN_40542538(local_2c);
  return iVar17;
}



/* 40540ba0 FUN_40540ba0 */

/* Boundary evidence: original MIPS .pdata 40540ba0..40541193. Semantic name remains unreviewed. */

int FUN_40540ba0(undefined4 *param_1,uint param_2,int *param_3,int *param_4,HWND param_5,
                LPCWSTR param_6,wchar_t *param_7,int *param_8,undefined4 param_9)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  wchar_t *pwVar8;
  wchar_t *local_1090;
  HWND local_108c;
  undefined2 local_1088;
  undefined1 auStack_1086 [6];
  undefined4 local_1080;
  WCHAR aWStack_1078 [2084];
  uint local_30;
  
  uVar4 = DAT_40544354;
  local_30 = DAT_40544354;
  iVar7 = 0;
  local_108c = param_5;
  local_1090 = param_7;
  if ((param_6 == (LPCWSTR)0x0) && ((param_8 == (int *)0x0 || (param_8 == (int *)0xffffffff)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  uVar6 = ((uint)(param_1[0x3a] != param_1[0x36]) << 1 ^ param_1[0x40]) & 2 ^ param_1[0x40];
  param_1[0x40] = uVar6;
  uVar6 = ((uint)(param_1[0x3a] != param_1[0x36]) << 2 ^ uVar6) & 4 ^ uVar6;
  param_1[0x40] = uVar6;
  if (param_2 != 0xffffffff) {
    if ((param_2 & 0x8000000) != 0) {
      param_1[0x40] = uVar6 | 2;
    }
    if ((param_2 & 0x4000000) != 0) {
      param_1[0x40] = param_1[0x40] | 4;
    }
  }
  if ((((param_3 == (int *)0x0) && (param_4 == (int *)0x0)) && (param_8 == (int *)0x0)) &&
     (param_6 == (LPCWSTR)0x0)) {
    uVar4 = param_2 & 0xf01fffff;
    if (uVar4 == 0) {
      FUN_4053f8cc((int)param_1);
    }
    else if ((uVar4 == 4) || (uVar4 == 8)) {
      iVar7 = FUN_40533b90((int)param_1);
    }
    else {
      iVar7 = -0x7ff8ffa9;
    }
    goto LAB_405410f4;
  }
  if (DAT_4054458c == 1) {
    param_2 = param_2 & 0xfffffffd;
  }
  if ((bVar1) && ((param_2 & 2) == 0)) {
    if ((int *)param_1[0x2a] == (int *)0x0) {
      if ((param_1[0x40] & 0x20) != 0) {
        FUN_40542538(uVar4);
        return 0;
      }
      goto LAB_40540de4;
    }
    iVar7 = (**(code **)(*(int *)param_1[0x2a] + 0x54))();
    if (iVar7 != 0) {
      FUN_40542538(local_30);
      return 1;
    }
  }
  if ((param_1[0x40] & 1) != 0) {
LAB_40540de4:
    FUN_40542538(local_30);
    return -0x7fffbffb;
  }
  param_1[0x40] = param_1[0x40] | 1;
  if ((bVar1) && ((param_2 & 2) == 0)) {
    memset(auStack_1086,0,0xe);
    local_1088 = 3;
    local_1080 = 1;
    FUN_4053fa64((int)param_1,&local_1088);
  }
  if (((param_6 != (LPCWSTR)0x0) && (iVar7 = FUN_4052dd40(0x1d,0,0), iVar7 != 0)) &&
     (bVar1 = FUN_4052d6cc(param_6), CONCAT31(extraout_var,bVar1) != 0)) {
    SHUnicodeToUnicode(param_6,aWStack_1078,0x824);
    FUN_40516e94((HWND)0x0,(WCHAR *)0x4bd,aWStack_1078,0x10);
    param_1[0x40] = param_1[0x40] & 0xfffffffe;
    FUN_40542538(local_30);
    return -0x7ff8fffb;
  }
  FUN_4053f730((int)param_1,param_3,param_4);
  pwVar8 = local_1090;
  if ((param_8 == (int *)0xffffffff) || ((param_8 == (int *)0x0 && (param_6 == (LPCWSTR)0x0)))) {
LAB_40540f2c:
    iVar7 = 0;
    pwVar8 = local_1090;
  }
  else {
    if ((param_2 & 0x10000000) != 0) {
      if ((param_2 & 4) == 0) {
        if (((param_2 & 0x10000000) == 0) || ((param_2 & 8) == 0)) goto LAB_40541154;
        pcVar5 = *(code **)(param_1[5] + 0x20);
      }
      else {
        pcVar5 = *(code **)(param_1[5] + 0x1c);
      }
      (*pcVar5)();
      goto LAB_40540f2c;
    }
LAB_40541154:
    iVar7 = FUN_405403a4(param_1,param_3,local_1090,param_2,(int)param_4,(int)param_8,
                         (LPCWSTR)local_108c,param_6);
  }
  param_1[0x40] = param_1[0x40] & 0xfffffffe;
  if ((-1 < iVar7) && (param_8 != (int *)0xffffffff)) {
    if ((param_2 & 0x10000000) != 0) {
      (**(code **)(*(int *)param_1[0x36] + 0xc))((int *)param_1[0x36],&local_108c);
      piVar3 = (int *)param_1[0x3c];
      if (piVar3 != (int *)0x0) {
        if (param_1[0x3f] == 0) {
          (**(code **)(*piVar3 + 0xc))(piVar3,0,param_1 + 10,param_9,param_1 + 0x3f);
        }
        (**(code **)(*(int *)param_1[0x3c] + 0x24))((int *)param_1[0x3c],param_2,param_9,pwVar8,0,0)
        ;
      }
      (**(code **)(param_1[5] + 0xa4))(param_1 + 5,1);
      SetForegroundWindow(local_108c);
    }
    if (param_8 != (int *)0x0) {
      bVar1 = false;
      if (((param_1[0x3c] != 0) && (piVar3 = (int *)param_1[0x2a], piVar3 != (int *)0x0)) &&
         (iVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,&local_1090), -1 < iVar2)) {
        iVar2 = (**(code **)(*(int *)local_1090 + 0x1c))(local_1090,param_1[0x2a],0,0);
        if ((iVar2 < 0) ||
           (iVar2 = (**(code **)(*(int *)local_1090 + 0x1c))(local_1090,param_1[0x2a],0x80000001,0),
           -1 < iVar2)) {
          bVar1 = true;
        }
        (**(code **)(*(int *)local_1090 + 8))();
        if (bVar1) goto LAB_405410f4;
      }
      local_1090 = (wchar_t *)0x0;
      iVar2 = (**(code **)(*param_8 + 0x10))(param_8,&local_1090,&local_108c);
      if ((-1 < iVar2) && (local_1090 != (wchar_t *)0x0)) {
        (**(code **)(*(int *)local_1090 + 0x18))(local_1090,local_108c,0,0,&DAT_40511238);
        (**(code **)(*(int *)local_1090 + 8))();
      }
    }
  }
LAB_405410f4:
  FUN_40542538(local_30);
  return iVar7;
}



/* 40541194 FUN_40541194 */

/* Boundary evidence: original MIPS .pdata 40541194..4054152f. Semantic name remains unreviewed. */

int FUN_40541194(int param_1,uint param_2,int *param_3,int *param_4,HWND param_5,LPCWSTR param_6,
                wchar_t *param_7)

{
  bool bVar1;
  int iVar2;
  HWND hWnd;
  DWORD DVar3;
  DWORD DVar4;
  LRESULT LVar5;
  int *local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  uint local_44;
  int *local_40;
  int *local_3c;
  HWND local_38;
  LPCWSTR local_34;
  wchar_t *local_30;
  
  iVar2 = FUN_40516af8();
  if (iVar2 == 0) {
    hWnd = (HWND)FUN_40533614(param_1 + -0x3c);
    DVar3 = __GetUserKData(8);
    DVar4 = GetWindowThreadProcessId(hWnd,(LPDWORD)0x0);
    if (DVar3 != DVar4) {
      local_50 = 1;
      local_48 = param_1 + -0x3c;
      local_4c = 0x24;
      local_38 = param_5;
      local_34 = param_6;
      local_30 = param_7;
      if (hWnd != (HWND)0x0) {
        local_44 = param_2;
        local_40 = param_3;
        local_3c = param_4;
        LVar5 = SendMessageW(hWnd,0x440,0x100,(LPARAM)&local_50);
        return LVar5;
      }
      return -0x7ff8fffb;
    }
  }
  bVar1 = false;
  local_58 = (int *)0x0;
  local_54 = (int *)0x0;
  local_60 = param_3;
  if (((param_3 != (int *)0x0) &&
      (iVar2 = (**(code **)(*param_3 + 0x28))(param_3,L"BIND_CONTEXT_PARAM",&local_54), -1 < iVar2))
     && (local_54 != (int *)0x0)) {
    iVar2 = (**(code **)(*param_3 + 0x28))
                      (param_3,L"863a99a0-21bc-11d0-82b4-00a0c90c29c5",&local_58);
    if ((-1 < iVar2) && (local_58 != (int *)0x0)) {
      iVar2 = FUN_4053b17c(0,0,0,0,&local_60,0);
      if (iVar2 < 0) goto LAB_40541494;
      bVar1 = true;
      iVar2 = (**(code **)(*local_60 + 0x24))
                        (local_60,L"863a99a0-21bc-11d0-82b4-00a0c90c29c5",local_58);
      if (iVar2 < 0) goto LAB_40541494;
      (**(code **)(*local_58 + 8))();
      local_58 = (int *)0x0;
      iVar2 = (**(code **)(*local_60 + 0x24))(local_60,L"BIND_CONTEXT_PARAM",local_54);
      if (iVar2 < 0) goto LAB_40541494;
      local_5c = (int *)0x0;
      iVar2 = (**(code **)(*param_3 + 0x28))(param_3,L"__DWNBINDINFO",&local_5c);
      if (-1 < iVar2) {
        (**(code **)(*local_60 + 0x24))(local_60,L"__DWNBINDINFO",local_5c);
        (**(code **)(*local_5c + 8))();
        local_5c = (int *)0x0;
      }
      iVar2 = (**(code **)(*param_3 + 0x28))(param_3,L"__HTMLLOADOPTIONS",&local_5c);
      if (-1 < iVar2) {
        (**(code **)(*local_60 + 0x24))(local_60,L"__HTMLLOADOPTIONS",local_5c);
        (**(code **)(*local_5c + 8))();
      }
    }
    (**(code **)(*local_54 + 8))();
    local_54 = (int *)0x0;
  }
  if ((param_2 & 0x40000000) == 0x40000000) {
    iVar2 = FUN_4053f9ec(param_1 + -0x3c,param_6);
  }
  else {
    iVar2 = FUN_40540ba0((undefined4 *)(param_1 + -0x3c),param_2,local_60,param_4,param_5,param_6,
                         param_7,(int *)0x0,0);
  }
LAB_40541494:
  IUnknown_AtomicRelease(&local_58);
  IUnknown_AtomicRelease(&local_54);
  if ((iVar2 < 0) && (local_60 != (int *)0x0)) {
    (**(code **)(*local_60 + 0x30))(local_60,L"BIND_CONTEXT_PARAM");
    (**(code **)(*local_60 + 0x30))(local_60,L"863a99a0-21bc-11d0-82b4-00a0c90c29c5");
  }
  if (bVar1) {
    (**(code **)(*local_60 + 8))();
  }
  return iVar2;
}



/* 40541530 FUN_40541530 */

/* Boundary evidence: original MIPS .pdata 40541530..40541717. Semantic name remains unreviewed. */

int FUN_40541530(int param_1,uint param_2,IBindCtx *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *local_38;
  IBindCtx *local_34;
  HWND local_30;
  LPCWSTR local_2c;
  wchar_t *local_28 [2];
  
  local_38 = (int *)0x0;
  local_2c = (LPCWSTR)0x0;
  local_28[0] = (wchar_t *)0x0;
  local_30 = (HWND)0x0;
  if ((param_5 != (int *)0x0) && (param_5 != (int *)0xffffffff)) {
    (**(code **)(*param_5 + 0x30))(param_5,&local_30);
    iVar1 = (**(code **)(*param_5 + 0x18))(param_5,1,&local_38,local_28);
    if (iVar1 < 0) goto LAB_4054168c;
    if (param_3 == (IBindCtx *)0x0) {
      iVar1 = CreateBindCtx(0,&local_34);
    }
    else {
      local_34 = param_3;
      (*param_3->lpVtbl->AddRef)(param_3);
    }
    if (iVar1 < 0) goto LAB_4054168c;
    iVar1 = (**(code **)(*local_38 + 0x50))(local_38,local_34,0,&local_2c);
    (*local_34->lpVtbl->Release)(local_34);
    if (iVar1 < 0) goto LAB_4054168c;
  }
  iVar1 = FUN_40540ba0((undefined4 *)(param_1 + -0x28),param_2,(int *)param_3,param_4,local_30,
                       local_2c,local_28[0],param_5,local_38);
LAB_4054168c:
  if (local_30 != (HWND)0x0) {
    CoTaskMemFree(local_30);
  }
  if (local_2c != (LPCWSTR)0x0) {
    CoTaskMemFree(local_2c);
  }
  if (local_28[0] != (wchar_t *)0x0) {
    CoTaskMemFree(local_28[0]);
  }
  if (local_38 != (int *)0x0) {
    (**(code **)(*local_38 + 8))();
  }
  return iVar1;
}



/* 40541718 FUN_40541718 */

/* Boundary evidence: original MIPS .pdata 40541718..4054175f. Semantic name remains unreviewed. */

void FUN_40541718(void)

{
  HRESULT HVar1;
  
  HVar1 = CoInitializeEx((LPVOID)0x0,6);
  if (HVar1 < 0) {
    CoInitializeEx((LPVOID)0x0,4);
  }
  return;
}



/* 40541760 FUN_40541760 */

/* Boundary evidence: original MIPS .pdata 40541760..40541787. Semantic name remains unreviewed. */

void FUN_40541760(void *param_1,IID *param_2,void **param_3)

{
  QISearch(param_1,(LPCQITAB)&PTR_DAT_40516248,param_2,param_3);
  return;
}



/* 40541788 FUN_40541788 */

/* Boundary evidence: original MIPS .pdata 40541788..405417a3. Semantic name remains unreviewed. */

void FUN_40541788(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 405417a4 FUN_405417a4 */

/* Boundary evidence: original MIPS .pdata 405417a4..40541807. Semantic name remains unreviewed. */

LONG FUN_405417a4(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 0x14))(param_1,1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[1];
  }
  return LVar1;
}



/* 40541808 FUN_40541808 */

/* Boundary evidence: original MIPS .pdata 40541808..4054184b. Semantic name remains unreviewed. */

undefined4 * FUN_40541808(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40516230;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 4054184c FUN_4054184c */

/* Boundary evidence: original MIPS .pdata 4054184c..40541883. Semantic name remains unreviewed. */

undefined4 FUN_4054184c(undefined4 *param_1)

{
  FUN_40541c6c(param_1,(wchar_t *)0x0);
  FUN_4052eac4((VARIANTARG *)(param_1 + 2));
  return 1;
}



/* 40541884 FUN_40541884 */

/* Boundary evidence: original MIPS .pdata 40541884..405418d3. Semantic name remains unreviewed. */

void FUN_40541884(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40516258;
  if ((HDSA)param_1[3] != (HDSA)0x0) {
    DSA_DestroyCallback((HDSA)param_1[3],FUN_4054184c,(void *)0x0);
  }
  *param_1 = &PTR_FUN_40516230;
  return;
}



/* 405418d4 FUN_405418d4 */

/* Boundary evidence: original MIPS .pdata 405418d4..40541a57. Semantic name remains unreviewed. */

undefined4 FUN_405418d4(int param_1,wchar_t *param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HDSA p_Var3;
  PVOID pvVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38 [2];
  undefined1 auStack_30 [16];
  
  local_38[0] = 0;
  memset(auStack_30,0,0x10);
  *param_3 = 0;
  iVar5 = *(int *)(param_1 + 0xc);
  for (iVar6 = 0; (iVar5 != 0 && (iVar6 < *(int *)*(HDSA *)(param_1 + 0xc))); iVar6 = iVar6 + 1) {
    puVar1 = DSA_GetItemPtr(*(HDSA *)(param_1 + 0xc),iVar6);
    iVar5 = StrCmpIW(param_2,(LPCWSTR)*puVar1);
    if (iVar5 == 0) {
      *param_3 = puVar1;
      return 0;
    }
    iVar5 = *(int *)(param_1 + 0xc);
  }
  if (param_4 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    if (*(int *)(param_1 + 0xc) == 0) {
      p_Var3 = DSA_Create(0x18,4);
      *(HDSA *)(param_1 + 0xc) = p_Var3;
    }
    if ((*(int *)(param_1 + 0xc) != 0) && (iVar6 = FUN_40541c6c(local_38,param_2), iVar6 != 0)) {
      memset(auStack_30,0,0x10);
      iVar6 = DSA_InsertItem(*(HDSA *)(param_1 + 0xc),0x7fffffff,local_38);
      if (iVar6 != -1) {
        pvVar4 = DSA_GetItemPtr(*(HDSA *)(param_1 + 0xc),iVar6);
        *param_3 = pvVar4;
        return 0;
      }
      FUN_40541c6c(local_38,(wchar_t *)0x0);
    }
    uVar2 = 0x8007000e;
  }
  return uVar2;
}



/* 40541a58 FUN_40541a58 */

/* Boundary evidence: original MIPS .pdata 40541a58..40541ad7. Semantic name remains unreviewed. */

int FUN_40541a58(int param_1,wchar_t *param_2,VARIANTARG *param_3)

{
  int iVar1;
  int local_10 [2];
  
  if ((*(uint *)(param_1 + 8) & 3) == 1) {
    iVar1 = -0x7ff8fffb;
  }
  else if ((param_2 == (wchar_t *)0x0) || (param_3 == (VARIANTARG *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_405418d4(param_1,param_2,local_10,0);
    if (-1 < iVar1) {
      iVar1 = FUN_4052ed8c(param_3,(VARIANTARG *)(local_10[0] + 8));
    }
  }
  return iVar1;
}



/* 40541ad8 FUN_40541ad8 */

/* Boundary evidence: original MIPS .pdata 40541ad8..40541b67. Semantic name remains unreviewed. */

int FUN_40541ad8(int param_1,wchar_t *param_2,VARIANTARG *param_3)

{
  int iVar1;
  int local_18 [2];
  
  if ((*(uint *)(param_1 + 8) & 3) == 0) {
    iVar1 = -0x7ff8fffb;
  }
  else if ((param_2 == (wchar_t *)0x0) || (param_3 == (VARIANTARG *)0x0)) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_405418d4(param_1,param_2,local_18,1);
    if (-1 < iVar1) {
      FUN_4052eac4((VARIANTARG *)(local_18[0] + 8));
      iVar1 = FUN_4052ed8c((VARIANTARG *)(local_18[0] + 8),param_3);
    }
  }
  return iVar1;
}



/* 40541b68 FUN_40541b68 */

/* Boundary evidence: original MIPS .pdata 40541b68..40541bb3. Semantic name remains unreviewed. */

undefined4 * FUN_40541b68(undefined4 *param_1,uint param_2)

{
  FUN_40541884(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40541bb4 FUN_40541bb4 */

/* Boundary evidence: original MIPS .pdata 40541bb4..40541c6b. Semantic name remains unreviewed. */

undefined4 FUN_40541bb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_4052d4e8(0x10);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1[1] = 1;
    piVar1[2] = param_1;
    *piVar1 = (int)&PTR_FUN_40516258;
  }
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = (**(code **)*piVar1)(piVar1,param_2,param_3);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



/* 40541c6c FUN_40541c6c */

/* Boundary evidence: original MIPS .pdata 40541c6c..40541d3f. Semantic name remains unreviewed. */

undefined4 FUN_40541c6c(undefined4 *param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  HLOCAL hMem;
  
  if (param_2 == (wchar_t *)0x0) {
    if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
      LocalFree((HLOCAL)*param_1);
      *param_1 = 0;
    }
  }
  else {
    hMem = (HLOCAL)*param_1;
    if (hMem == (HLOCAL)0x0) {
      sVar1 = wcslen(param_2);
      _Dest = LocalAlloc(0x40,(sVar1 + 1) * 2);
    }
    else {
      sVar1 = wcslen(param_2);
      _Dest = LocalReAlloc(hMem,(sVar1 + 1) * 2,0x42);
    }
    if (_Dest == (wchar_t *)0x0) {
      return 0;
    }
    wcscpy(_Dest,param_2);
    *param_1 = _Dest;
  }
  return 1;
}



/* 40541d40 FUN_40541d40 */

undefined4 FUN_40541d40(void)

{
  undefined4 *in_stack_00000010;
  
  *in_stack_00000010 = 0;
  return 0x80004001;
}



/* 40541d60 FUN_40541d60 */

undefined4 FUN_40541d60(void)

{
  return 0x80004002;
}



/* 40541d6c FUN_40541d6c */

void FUN_40541d6c(void)

{
  return;
}



/* 40542284 FUN_40542284 */

/* Boundary evidence: original MIPS .pdata 40542284..405423bf. Semantic name remains unreviewed. */

int FUN_40542284(HMODULE param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_405447e4 != (code *)0x0) {
      iVar2 = (*DAT_405447e4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40542334;
    FUN_40542718();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40516bb8(param_1,param_2,param_3);
  }
LAB_40542334:
  if (((param_2 == 0) && (FUN_405426a0(), iVar1 != 0)) && (DAT_405447e4 != (code *)0x0)) {
    iVar1 = (*DAT_405447e4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 405423c0 FUN_405423c0 */

/* Boundary evidence: original MIPS .pdata 405423c0..405423eb. Semantic name remains unreviewed. */

void FUN_405423c0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 405423ec entry */

/* Boundary evidence: original MIPS .pdata 405423ec..40542443. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    FUN_40542444();
  }
  FUN_40542284(param_1,param_2,param_3);
  return;
}



/* 40542444 FUN_40542444 */

/* Boundary evidence: original MIPS .pdata 40542444..405424b7. Semantic name remains unreviewed. */

void FUN_40542444(void)

{
  uint uVar1;
  
  if ((DAT_40544354 == 0) || (DAT_40544354 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40544354 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40544354 == 0) {
      DAT_40544354 = 0xb064;
    }
  }
  DAT_40544358 = ~DAT_40544354;
  return;
}



/* 405424b8 FUN_405424b8 */

/* Boundary evidence: original MIPS .pdata 405424b8..4054250b. Semantic name remains unreviewed. */

void FUN_405424b8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40542538(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4054250c FUN_4054250c */

/* Boundary evidence: original MIPS .pdata 4054250c..40542537. Semantic name remains unreviewed. */

undefined4 FUN_4054250c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_405424b8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40542538 FUN_40542538 */

/* Boundary evidence: original MIPS .pdata 40542538..4054257f. Semantic name remains unreviewed. */

void FUN_40542538(uint param_1)

{
  if ((param_1 == DAT_40544354) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40542580 FUN_40542580 */

/* Boundary evidence: original MIPS .pdata 40542580..4054269f. Semantic name remains unreviewed. */

void FUN_40542580(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_405447d4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_405447dc;
    if (DAT_405447dc != (undefined4 *)0x0) {
      while (DAT_405447d8 = DAT_405447d8 + -1, _Memory <= DAT_405447d8) {
        if ((code *)*DAT_405447d8 != (code *)0x0) {
          (*(code *)*DAT_405447d8)();
          _Memory = DAT_405447dc;
        }
      }
      free(_Memory);
      DAT_405447d8 = (undefined4 *)0x0;
      DAT_405447dc = (undefined4 *)0x0;
    }
    FUN_405426c4((undefined4 *)&DAT_40511010,(undefined4 *)&DAT_40511014);
  }
  FUN_405426c4((undefined4 *)&DAT_40511018,(undefined4 *)&DAT_4051101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_405447e0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 405426a0 FUN_405426a0 */

/* Boundary evidence: original MIPS .pdata 405426a0..405426c3. Semantic name remains unreviewed. */

void FUN_405426a0(void)

{
  FUN_40542580(0,0,1);
  return;
}



/* 405426c4 FUN_405426c4 */

/* Boundary evidence: original MIPS .pdata 405426c4..40542717. Semantic name remains unreviewed. */

void FUN_405426c4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40542718 FUN_40542718 */

/* Boundary evidence: original MIPS .pdata 40542718..40542753. Semantic name remains unreviewed. */

void FUN_40542718(void)

{
  FUN_405426c4((undefined4 *)&DAT_40511008,(undefined4 *)&DAT_4051100c);
  FUN_405426c4((undefined4 *)&DAT_40511000,(undefined4 *)&DAT_40511004);
  return;
}


