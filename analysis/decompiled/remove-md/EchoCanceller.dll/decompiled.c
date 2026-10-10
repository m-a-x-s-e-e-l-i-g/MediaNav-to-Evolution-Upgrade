/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

/* Boundary evidence: original MIPS .pdata 10001000..100011bb. Semantic name remains unreviewed. */

undefined4 FUN_10001000(void)

{
  MMRESULT MVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(DAT_1000d550 + 0x1c) = 1;
  NKDbgPrintfW(L"[EC] [INFO] BT waveInStart \r\n");
  MVar1 = waveInStart(*(HWAVEIN *)(DAT_1000d550 + 8));
  if (MVar1 == 0) {
    DVar2 = WaitForSingleObject(*(HANDLE *)(DAT_1000d550 + 0x20),0xffffffff);
    iVar5 = DAT_1000d550;
    if (DVar2 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] (BTIN)INIT Timeout waiting for capture to complete ==> %08x Index = %d\r\n"
                   ,*(undefined4 *)(DAT_1000d550 + 0x6c4),3);
      iVar5 = DAT_1000d550;
      *(undefined4 *)(DAT_1000d550 + 0x18) = 0;
    }
    memcpy(&DAT_1000cde4,(void *)(iVar5 + 0x6d4),0x200);
    waveInAddBuffer(*(HWAVEIN *)(iVar5 + 8),(LPWAVEHDR)(iVar5 + 0x6b4),0x20);
    iVar5 = 0;
    iVar4 = *(int *)(DAT_1000d550 + 0x18);
    iVar3 = DAT_1000d550;
    while (DAT_1000d550 = iVar3, iVar4 != 0) {
      DVar2 = WaitForSingleObject(*(HANDLE *)(iVar3 + 0x20),0x280);
      iVar3 = DAT_1000d550;
      if (DVar2 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] (BTIN)Timeout waiting for capture to complete ==> %08x Index = %d\r\n"
                     ,*(undefined4 *)(iVar5 * 0x220 + DAT_1000d550 + 100),iVar5);
        iVar3 = DAT_1000d550;
        *(undefined4 *)(DAT_1000d550 + 0x18) = 0;
      }
      if (*(int *)(iVar3 + 0x18) == 0) break;
      waveInAddBuffer(*(HWAVEIN *)(iVar3 + 8),(LPWAVEHDR)(iVar5 * 0x220 + iVar3 + 0x54),0x20);
      iVar5 = iVar5 + 1;
      if (iVar5 == 4) {
        iVar5 = 0;
      }
      iVar3 = DAT_1000d550;
      iVar4 = *(int *)(DAT_1000d550 + 0x18);
    }
  }
  else {
    NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveInStart fail \r\n");
    iVar3 = DAT_1000d550;
  }
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  CloseHandle(*(HANDLE *)(iVar3 + 0x20));
  return 0;
}



/* 100011bc FUN_100011bc */

/* Boundary evidence: original MIPS .pdata 100011bc..10001767. Semantic name remains unreviewed. */

undefined4 FUN_100011bc(void)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  BOOL BVar4;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  
  DAT_10009124 = 0;
  if (DAT_1000c6b8 == 0) {
    DAT_1000c678 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c6a0 = 0x46464952;
    local_33 = 0;
    DAT_1000c6a8 = 0x45564157;
    DAT_1000c6a4 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c690 = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c69c = 0x12;
    DAT_1000c694 = 0;
    DAT_1000c688 = CreateFileW(L"Storage Card3\\MicInSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c688 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\MicInSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009124 != 0) goto LAB_1000152c;
  }
  do {
    WaitForSingleObject(DAT_1000d018,0xffffffff);
    if (DAT_1000c6c8 == 0) break;
    BVar4 = WriteFile(DAT_1000c688,DAT_1000c7d4,0x200,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing MicIn PCM data.2 [0x%08X][%d]\r\n",DAT_1000c688,DVar3
                  );
      CloseHandle(DAT_1000c688);
      DAT_1000c688 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c678 = DAT_1000c678 + 1;
    }
  } while (DAT_10009124 == 0);
LAB_1000152c:
  DAT_10009124 = 1;
  if (DAT_1000d018 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d018);
  }
  DAT_1000d018 = (HANDLE)0x0;
  if (DAT_1000c6b8 == 1) {
    SetFilePointer(DAT_1000c688,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c69c = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c694 = DAT_1000c678 * 0x200;
    DAT_1000c690 = 0x61746164;
    DAT_1000c6a0 = 0x46464952;
    DAT_1000c6a4 = DAT_1000c694 + 0x26;
    DAT_1000c6a8 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c688,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c688);
    DAT_1000c688 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nMicInRecordedBufferNum = %d\r\n",DAT_1000c678);
    DAT_1000c6b8 = 0;
  }
  return 0;
}



/* 10001768 FUN_10001768 */

/* Boundary evidence: original MIPS .pdata 10001768..10001d13. Semantic name remains unreviewed. */

undefined4 FUN_10001768(void)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  BOOL BVar4;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  
  DAT_10009128 = 0;
  if (DAT_1000c6b4 == 0) {
    DAT_1000c674 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c6a0 = 0x46464952;
    local_33 = 0;
    DAT_1000c6a8 = 0x45564157;
    DAT_1000c6a4 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c690 = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c69c = 0x12;
    DAT_1000c694 = 0;
    DAT_1000c684 = CreateFileW(L"Storage Card3\\MicOutSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c684 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\MicOutSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009128 != 0) goto LAB_10001ad8;
  }
  do {
    WaitForSingleObject(DAT_1000d01c,0xffffffff);
    if (DAT_1000c6c4 == 0) break;
    BVar4 = WriteFile(DAT_1000c684,DAT_1000c7a4,0x200,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing MicOut PCM data.2 [0x%08X][%d]\r\n",DAT_1000c684,
                   DVar3);
      CloseHandle(DAT_1000c684);
      DAT_1000c684 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c674 = DAT_1000c674 + 1;
    }
  } while (DAT_10009128 == 0);
LAB_10001ad8:
  DAT_10009128 = 1;
  if (DAT_1000d01c != (HANDLE)0x0) {
    CloseHandle(DAT_1000d01c);
  }
  DAT_1000d01c = (HANDLE)0x0;
  if (DAT_1000c6b4 == 1) {
    SetFilePointer(DAT_1000c684,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c69c = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c694 = DAT_1000c674 * 0x200;
    DAT_1000c690 = 0x61746164;
    DAT_1000c6a0 = 0x46464952;
    DAT_1000c6a4 = DAT_1000c694 + 0x26;
    DAT_1000c6a8 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c684,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c684);
    DAT_1000c684 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nMicOutRecordedBufferNum = %d\r\n",DAT_1000c674);
    DAT_1000c6b4 = 0;
  }
  return 0;
}



/* 10001d14 FUN_10001d14 */

/* Boundary evidence: original MIPS .pdata 10001d14..100022bf. Semantic name remains unreviewed. */

undefined4 FUN_10001d14(void)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  BOOL BVar4;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  
  DAT_1000912c = 0;
  if (DAT_1000c6b0 == 0) {
    DAT_1000c670 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c6a0 = 0x46464952;
    local_33 = 0;
    DAT_1000c6a8 = 0x45564157;
    DAT_1000c6a4 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c690 = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c69c = 0x12;
    DAT_1000c694 = 0;
    DAT_1000c680 = CreateFileW(L"Storage Card3\\RecvInSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c680 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\RecvInSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_1000912c != 0) goto LAB_10002084;
  }
  do {
    WaitForSingleObject(DAT_1000d020,0xffffffff);
    if (DAT_1000c6c0 == 0) break;
    BVar4 = WriteFile(DAT_1000c680,DAT_1000c7c4,0x200,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing RecvIn PCM data.2 [0x%08X][%d]\r\n",DAT_1000c680,
                   DVar3);
      CloseHandle(DAT_1000c680);
      DAT_1000c680 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c670 = DAT_1000c670 + 1;
    }
  } while (DAT_1000912c == 0);
LAB_10002084:
  DAT_1000912c = 1;
  if (DAT_1000d020 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d020);
  }
  DAT_1000d020 = (HANDLE)0x0;
  if (DAT_1000c6b0 == 1) {
    SetFilePointer(DAT_1000c680,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c69c = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c694 = DAT_1000c670 * 0x200;
    DAT_1000c690 = 0x61746164;
    DAT_1000c6a0 = 0x46464952;
    DAT_1000c6a4 = DAT_1000c694 + 0x26;
    DAT_1000c6a8 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c680,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c680);
    DAT_1000c680 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nRecvInRecordedBufferNum = %d\r\n",DAT_1000c670);
    DAT_1000c6b0 = 0;
  }
  return 0;
}



/* 100022c0 FUN_100022c0 */

/* Boundary evidence: original MIPS .pdata 100022c0..1000286b. Semantic name remains unreviewed. */

undefined4 FUN_100022c0(void)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  BOOL BVar4;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  
  DAT_10009130 = 0;
  if (DAT_1000c6ac == 0) {
    DAT_1000c66c = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c6a0 = 0x46464952;
    local_33 = 0;
    DAT_1000c6a8 = 0x45564157;
    DAT_1000c6a4 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c690 = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c69c = 0x12;
    DAT_1000c694 = 0;
    DAT_1000c67c = CreateFileW(L"Storage Card3\\RecvOutSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c67c == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\RecvOutSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009130 != 0) goto LAB_10002630;
  }
  do {
    WaitForSingleObject(DAT_1000d024,0xffffffff);
    if (DAT_1000c6bc == 0) break;
    BVar4 = WriteFile(DAT_1000c67c,DAT_1000c794,0x200,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing RecvOut PCM data.2 [0x%08X][%d]\r\n",DAT_1000c67c,
                   DVar3);
      CloseHandle(DAT_1000c67c);
      DAT_1000c67c = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c66c = DAT_1000c66c + 1;
    }
  } while (DAT_10009130 == 0);
LAB_10002630:
  DAT_10009130 = 1;
  if (DAT_1000d024 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d024);
  }
  DAT_1000d024 = (HANDLE)0x0;
  if (DAT_1000c6ac == 1) {
    SetFilePointer(DAT_1000c67c,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c698 = 0x20746d66;
    DAT_1000c69c = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c694 = DAT_1000c66c * 0x200;
    DAT_1000c690 = 0x61746164;
    DAT_1000c6a0 = 0x46464952;
    DAT_1000c6a4 = DAT_1000c694 + 0x26;
    DAT_1000c6a8 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c6a0,0xc,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c698,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&local_40,DAT_1000c69c,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c67c,&DAT_1000c690,8,(LPDWORD)&DAT_1000c68c,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c67c);
    DAT_1000c67c = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nRecvOutRecordedBufferNum = %d\r\n",DAT_1000c66c);
    DAT_1000c6ac = 0;
  }
  return 0;
}



/* 1000286c FUN_1000286c */

/* Boundary evidence: original MIPS .pdata 1000286c..1000321f. Semantic name remains unreviewed. */

undefined4 FUN_1000286c(void)

{
  undefined2 uVar1;
  HANDLE hSemaphore;
  byte bVar2;
  MMRESULT MVar3;
  DWORD DVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  short *psVar17;
  short *psVar18;
  byte local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  *(undefined4 *)(DAT_1000d550 + 0x2c) = 1;
  local_44 = 0;
  NKDbgPrintfW(L"[EC] [INFO] HF waveInStart \r\n");
  MVar3 = waveInStart(*(HWAVEIN *)(DAT_1000d550 + 0xc));
  if (MVar3 == 0) {
    DVar4 = WaitForSingleObject(*(HANDLE *)(DAT_1000d550 + 0x30),0xffffffff);
    iVar13 = DAT_1000d550;
    if (DVar4 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] (HFIN)INTI Timeout waiting for capture to complete ==> %08x %d\r\n"
                   ,*(undefined4 *)(DAT_1000d550 + 0x35c4),3);
      iVar13 = DAT_1000d550;
      *(undefined4 *)(DAT_1000d550 + 0x18) = 0;
    }
    waveInAddBuffer(*(HWAVEIN *)(iVar13 + 0xc),(LPWAVEHDR)(iVar13 + 0x35b4),0x20);
    local_3c = 2;
    local_40 = 0;
    iVar13 = 2;
    iVar15 = 2;
    do {
      waveOutWrite(*(HWAVEOUT *)(DAT_1000d550 + 0x14),
                   (LPWAVEHDR)(iVar13 * 0x1820 + DAT_1000d550 + 0x41d4),0x20);
      iVar5 = DAT_1000d550;
      iVar13 = iVar13 + 1;
      if (iVar13 == 4) {
        iVar13 = 0;
      }
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    iVar15 = 2;
    *(int *)(DAT_1000d550 + 0x24) = iVar13;
    iVar13 = 2;
    do {
      waveOutWrite(*(HWAVEOUT *)(iVar5 + 0x10),(LPWAVEHDR)(iVar13 * 0x220 + iVar5 + 0x8d4),0x20);
      iVar5 = DAT_1000d550;
      iVar13 = iVar13 + 1;
      if (iVar13 == 4) {
        iVar13 = 0;
      }
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    *(int *)(DAT_1000d550 + 0x34) = iVar13;
    if (*(int *)(iVar5 + 0x18) != 0) {
      uVar16 = (uint)local_48;
      do {
        DVar4 = WaitForSingleObject(*(HANDLE *)(iVar5 + 0x30),0x280);
        iVar5 = DAT_1000d550;
        if (DVar4 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] (HFIN)Timeout waiting for capture to complete ==> %08x %d\r\n"
                       ,*(undefined4 *)(local_40 * 0xc20 + DAT_1000d550 + 0x1164),local_40);
          iVar5 = DAT_1000d550;
          *(undefined4 *)(DAT_1000d550 + 0x18) = 0;
        }
        if (*(int *)(iVar5 + 0x18) == 0) break;
        iVar13 = 0x100;
        puVar8 = (undefined2 *)(local_40 * 0xc20 + iVar5 + 0x1174);
        puVar7 = (undefined2 *)(iVar5 + 0xa25c);
        do {
          uVar1 = *puVar8;
          puVar8 = puVar8 + 6;
          *puVar7 = uVar1;
          iVar13 = iVar13 + -1;
          puVar7 = puVar7 + 1;
        } while (iVar13 != 0);
        if (DAT_1000cff4 == 0) {
          DAT_1000cff0 = 1;
        }
        if (DAT_1000cff0 == 1) {
          iVar14 = 2;
          iVar11 = local_40 * 0x220 + iVar5;
          iVar13 = iVar5 + 0xa45c;
          iVar15 = iVar11 + 0x8f4;
          iVar9 = local_3c * 0x220 + iVar5 + 0x74;
          iVar11 = iVar11 + 0x74;
          puVar7 = (undefined2 *)(iVar5 + 0xa25c);
          do {
            DAT_1000c7d4 = puVar7;
            DAT_1000c7c4 = iVar11;
            DAT_1000c7b4 = iVar9;
            DAT_1000c7a4 = iVar15;
            DAT_1000c794 = (void *)iVar13;
            if (DAT_1000d530 == 0) {
              DAT_1000cfec[1] = 0;
              DAT_1000cfec[2] = 0;
              if (DAT_1000d534 != 0) goto LAB_10002c8c;
            }
            else {
              bVar2 = DAT_1000d52d;
              if ((uint)DAT_1000d52c != (uint)DAT_1000d52d) {
                iVar13 = (uint)DAT_1000d52d * 0x104;
                *DAT_1000cfec = 0x100;
                DAT_1000cfec[1] = *(undefined4 *)(&DAT_1000ba8c + iVar13);
                DAT_1000cfec[2] = &DAT_1000b98c + iVar13;
                bVar2 = DAT_1000d52d + 1;
                if (9 < (byte)(DAT_1000d52d + 1)) {
                  bVar2 = DAT_1000d52d - 9;
                }
              }
              DAT_1000d52d = bVar2;
              DAT_1000d530 = 0;
              if (DAT_1000cfec[1] != 0) {
                uVar16 = 0;
                do {
                  uVar16 = uVar16 + 1 & 0xff;
                } while (uVar16 < (uint)DAT_1000cfec[1]);
              }
              DAT_1000d534 = 1;
LAB_10002c8c:
              uVar16 = DAT_1000d52e + 1 & 0xff;
              if (9 < uVar16) {
                uVar16 = uVar16 + 0xf6 & 0xff;
              }
              if (uVar16 != DAT_1000d52f) {
                DAT_1000cfec[5] = &DAT_10009164 + (uint)DAT_1000d52e * 0x404;
                DAT_1000cfec[3] = 0x400;
              }
            }
            DAT_1000cff4 = sseProcess(DAT_1000cfe4,&DAT_1000c7d4,&DAT_1000c7c4,&DAT_1000c7b4,
                                      &DAT_1000c7a4,&DAT_1000c794,DAT_1000cfec);
            if (DAT_1000cff4 != 0) {
              sseGetErrorMessage(DAT_1000cfe4,&DAT_1000c6cc);
              NKDbgPrintfW(&DAT_1000673c,DAT_1000cff4,&DAT_1000c6cc);
              DAT_1000cff0 = 0;
            }
            hSemaphore = DAT_10009160;
            if ((DAT_1000cfec[4] == 0) || (DAT_1000d534 != 1)) {
              DAT_1000d534 = 0;
            }
            else {
              uVar6 = (uint)DAT_1000d52e;
              DAT_1000d52e = (byte)uVar16;
              *(undefined4 *)(&DAT_10009564 + uVar6 * 0x404) = DAT_1000cfec[4];
              ReleaseSemaphore(hSemaphore,1,(LPLONG)0x0);
            }
            memset(DAT_1000cfec,0,0x18);
            iVar14 = iVar14 + -1;
            iVar13 = (int)DAT_1000c794 + 0x100;
            iVar15 = DAT_1000c7a4 + 0x100;
            iVar9 = DAT_1000c7b4 + 0x100;
            iVar11 = DAT_1000c7c4 + 0x100;
            puVar7 = DAT_1000c7d4 + 0x80;
          } while (iVar14 != 0);
          DAT_1000c7d4 = DAT_1000c7d4 + -0x80;
          DAT_1000c7a4 = DAT_1000c7a4 + -0x100;
          DAT_1000c7c4 = DAT_1000c7c4 + -0x100;
          DAT_1000c7b4 = DAT_1000c7b4 + -0x100;
          DAT_1000c794 = (void *)((int)DAT_1000c794 + -0x100);
          memcpy(&DAT_1000c7e4 + local_40 * 0x200,DAT_1000c794,0x200);
          iVar5 = DAT_1000d550;
          if (local_40 == 0) {
            local_44 = 3;
          }
          else if (local_40 != 0) {
            local_44 = local_40 + -1;
          }
          iVar13 = local_40 * 0x1820;
          iVar15 = 0xff;
          psVar18 = (short *)(iVar13 + DAT_1000d550 + 0x41f8);
          psVar12 = (short *)(&DAT_1000c7e4 + local_44 * 0x200);
          do {
            sVar10 = *psVar12;
            psVar17 = psVar12 + 1;
            psVar18[-2] = sVar10;
            iVar9 = (int)*psVar17 + (int)sVar10;
            if (iVar9 < 0) {
              iVar9 = iVar9 + 1;
            }
            sVar10 = (short)(iVar9 >> 1);
            psVar18[1] = sVar10;
            iVar9 = (int)sVar10 + (int)*psVar12;
            if (iVar9 < 0) {
              iVar9 = iVar9 + 1;
            }
            sVar10 = (short)(iVar9 >> 1);
            *psVar18 = sVar10;
            iVar9 = (int)sVar10 + (int)*psVar12;
            if (iVar9 < 0) {
              iVar9 = iVar9 + 1;
            }
            psVar18[-1] = (short)(iVar9 >> 1);
            iVar9 = (int)*psVar17 + (int)psVar18[1];
            if (iVar9 < 0) {
              iVar9 = iVar9 + 1;
            }
            sVar10 = (short)(iVar9 >> 1);
            iVar9 = (int)sVar10 + (int)psVar18[1];
            psVar18[3] = sVar10;
            sVar10 = (short)(iVar9 >> 1);
            if (iVar9 < 0) {
              sVar10 = (short)(iVar9 + 1 >> 1);
            }
            psVar18[2] = sVar10;
            iVar15 = iVar15 + -1;
            psVar18 = psVar18 + 6;
            psVar12 = psVar17;
          } while (iVar15 != 0);
          iVar9 = (int)*(short *)(&DAT_1000c7e4 + local_40 * 0x200);
          psVar12 = (short *)(local_44 * 0x200 + 0x1000c9e2);
          iVar15 = *psVar12 + iVar9;
          *(short *)(iVar13 + iVar5 + 0x4de8) = *psVar12;
          if (iVar15 < 0) {
            iVar15 = iVar15 + 1;
          }
          sVar10 = (short)(iVar15 >> 1);
          iVar13 = iVar13 + iVar5;
          *(short *)(iVar13 + 0x4dee) = sVar10;
          iVar15 = (int)sVar10 + (int)*psVar12;
          if (iVar15 < 0) {
            iVar15 = iVar15 + 1;
          }
          sVar10 = (short)(iVar15 >> 1);
          *(short *)(iVar13 + 0x4dec) = sVar10;
          iVar15 = (int)sVar10 + (int)*psVar12;
          if (iVar15 < 0) {
            iVar15 = iVar15 + 1;
          }
          *(short *)(iVar13 + 0x4dea) = (short)(iVar15 >> 1);
          iVar9 = iVar9 + *(short *)(iVar13 + 0x4dee);
          if (iVar9 < 0) {
            iVar9 = iVar9 + 1;
          }
          sVar10 = (short)(iVar9 >> 1);
          iVar15 = (int)sVar10 + (int)*(short *)(iVar13 + 0x4dee);
          *(short *)(iVar13 + 0x4df2) = sVar10;
          if (iVar15 < 0) {
            iVar15 = iVar15 + 1;
          }
          *(short *)(iVar13 + 0x4df0) = (short)(iVar15 >> 1);
          if (DAT_1000c6c8 == 1) {
            EventModify(DAT_1000d018,3);
            iVar5 = DAT_1000d550;
          }
          if (DAT_1000c6c0 == 1) {
            EventModify(DAT_1000d020,3);
            iVar5 = DAT_1000d550;
          }
          if (DAT_1000c6c4 == 1) {
            EventModify(DAT_1000d01c,3);
            iVar5 = DAT_1000d550;
          }
          if (DAT_1000c6bc == 1) {
            EventModify(DAT_1000d024,3);
            iVar5 = DAT_1000d550;
          }
        }
        waveOutWrite(*(HWAVEOUT *)(iVar5 + 0x14),
                     (LPWAVEHDR)(*(int *)(iVar5 + 0x24) * 0x1820 + iVar5 + 0x41d4),0x20);
        iVar13 = DAT_1000d550;
        iVar15 = *(int *)(DAT_1000d550 + 0x24) + 1;
        *(int *)(DAT_1000d550 + 0x24) = iVar15;
        if (iVar15 == 4) {
          *(undefined4 *)(iVar13 + 0x24) = 0;
        }
        waveOutWrite(*(HWAVEOUT *)(iVar13 + 0x10),
                     (LPWAVEHDR)(*(int *)(iVar13 + 0x34) * 0x220 + iVar13 + 0x8d4),0x20);
        iVar13 = DAT_1000d550;
        iVar15 = *(int *)(DAT_1000d550 + 0x34) + 1;
        *(int *)(DAT_1000d550 + 0x34) = iVar15;
        if (iVar15 == 4) {
          *(undefined4 *)(iVar13 + 0x34) = 0;
        }
        waveInAddBuffer(*(HWAVEIN *)(iVar13 + 0xc),(LPWAVEHDR)(local_40 * 0xc20 + iVar13 + 0x1154),
                        0x20);
        local_40 = local_40 + 1;
        if (local_40 == 4) {
          local_40 = 0;
        }
        local_3c = local_3c + 1;
        if (local_3c == 4) {
          local_3c = 0;
        }
        iVar5 = DAT_1000d550;
      } while (*(int *)(DAT_1000d550 + 0x18) != 0);
    }
  }
  else {
    NKDbgPrintfW(L"[EC] [ERROR] waveInStart fail \r\n");
    iVar5 = DAT_1000d550;
  }
  *(undefined4 *)(iVar5 + 0x2c) = 0;
  CloseHandle(*(HANDLE *)(iVar5 + 0x20));
  return 0;
}



/* 10003220 FUN_10003220 */

/* Boundary evidence: original MIPS .pdata 10003220..10003253. Semantic name remains unreviewed. */

void FUN_10003220(undefined4 param_1,int param_2)

{
  if (param_2 == 0x3c0) {
    EventModify(*(undefined4 *)(DAT_1000d550 + 0x20),3);
  }
  return;
}



/* 10003254 FUN_10003254 */

/* Boundary evidence: original MIPS .pdata 10003254..10003287. Semantic name remains unreviewed. */

void FUN_10003254(undefined4 param_1,int param_2)

{
  if (param_2 == 0x3c0) {
    EventModify(*(undefined4 *)(DAT_1000d550 + 0x30),3);
  }
  return;
}



/* 10003288 FUN_10003288 */

/* Boundary evidence: original MIPS .pdata 10003288..1000347b. Semantic name remains unreviewed. */

undefined4 FUN_10003288(void)

{
  uint uVar1;
  uint *puVar2;
  undefined1 *puVar3;
  MMRESULT MVar4;
  wchar_t *pwVar5;
  WAVEFORMATEX local_30;
  
  local_30.wFormatTag._1_1_ = 0;
  puVar3 = (undefined1 *)((int)&local_30.nAvgBytesPerSec + 3);
  uVar1 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar1);
  *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 16000U >> (3 - uVar1) * 8;
  local_30.nSamplesPerSec = 8000;
  local_30.nAvgBytesPerSec = 16000;
  local_30.nChannels._1_1_ = 0;
  local_30.nBlockAlign._1_1_ = 0;
  local_30.wFormatTag._0_1_ = 1;
  local_30.nChannels._0_1_ = 1;
  local_30.nBlockAlign._0_1_ = 2;
  local_30.wBitsPerSample._0_1_ = 0x10;
  local_30.wBitsPerSample._1_1_ = 0;
  local_30.cbSize._0_1_ = 0;
  local_30.cbSize._1_1_ = 0;
  NKDbgPrintfW(L"[EC] [INTI] Device Open!\r\n");
  MVar4 = waveInOpen((LPHWAVEIN)(DAT_1000d550 + 8),1,&local_30,0x10003220,0,0x30000);
  if (MVar4 == 0) {
    MVar4 = waveOutOpen((LPHWAVEOUT)(DAT_1000d550 + 0x10),1,&local_30,0,0,0);
    if (MVar4 == 0) {
      local_30.wFormatTag._1_1_ = 0;
      local_30.nChannels._1_1_ = 0;
      local_30.nSamplesPerSec = 48000;
      local_30.nBlockAlign._1_1_ = 0;
      local_30.wBitsPerSample._1_1_ = 0;
      local_30.cbSize._0_1_ = 0;
      puVar3 = (undefined1 *)((int)&local_30.nAvgBytesPerSec + 3);
      uVar1 = (uint)puVar3 & 3;
      puVar2 = (uint *)(puVar3 + -uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | 96000U >> (3 - uVar1) * 8;
      local_30.wFormatTag._0_1_ = 1;
      local_30.nChannels._0_1_ = 1;
      local_30.nAvgBytesPerSec = 96000;
      local_30.nBlockAlign._0_1_ = 2;
      local_30.wBitsPerSample._0_1_ = 0x10;
      local_30.cbSize._1_1_ = 0;
      MVar4 = waveInOpen((LPHWAVEIN)(DAT_1000d550 + 0xc),0,&local_30,0x10003254,0,0x30000);
      if (MVar4 == 0) {
        MVar4 = waveOutOpen((LPHWAVEOUT)(DAT_1000d550 + 0x14),0,&local_30,0,0,0);
        if (MVar4 == 0) {
          return 1;
        }
        pwVar5 = L"[EC] [ERROR] HF waveOutOpen failed. mr=%08x\r\n";
      }
      else {
        pwVar5 = L"[EC] [ERROR] HF waveInOpen failed. mr=%08x\r\n";
      }
    }
    else {
      pwVar5 = L"[EC] [ERROR] BT waveOutOpen failed. mr=%08x\r\n";
    }
  }
  else {
    pwVar5 = L"[EC] [ERROR] BT waveInOpen failed. mr=%08x\r\n";
  }
  NKDbgPrintfW(pwVar5,MVar4);
  return 0;
}



/* 1000347c FUN_1000347c */

/* Boundary evidence: original MIPS .pdata 1000347c..1000357b. Semantic name remains unreviewed. */

void FUN_1000347c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)(DAT_1000d550 + 0x41d8);
  puVar3 = (undefined4 *)(DAT_1000d550 + 0x1158);
  puVar1 = (undefined4 *)(DAT_1000d550 + 0x58);
  iVar4 = 4;
  do {
    memset(puVar1 + -1,0,0x20);
    puVar1[-1] = puVar1 + 7;
    *puVar1 = 0x200;
    memset(puVar1 + 0x21f,0,0x20);
    puVar1[0x21f] = puVar1 + 0x227;
    puVar1[0x220] = 0x200;
    memset(puVar3 + -1,0,0x20);
    puVar3[-1] = puVar3 + 7;
    *puVar3 = 0xc00;
    memset(puVar2 + -1,0,0x20);
    *puVar2 = 0xc00;
    puVar2[-1] = puVar2 + 7;
    puVar1 = puVar1 + 0x88;
    puVar3 = puVar3 + 0x308;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 0x608;
  } while (iVar4 != 0);
  return;
}



/* 1000357c FUN_1000357c */

/* Boundary evidence: original MIPS .pdata 1000357c..10003767. Semantic name remains unreviewed. */

undefined4 FUN_1000357c(void)

{
  MMRESULT MVar1;
  int iVar2;
  uint uVar3;
  int local_30;
  
  iVar2 = 4;
  local_30 = 4;
  uVar3 = 3;
  do {
    MVar1 = waveInPrepareHeader(*(HWAVEIN *)(DAT_1000d550 + 8),
                                (LPWAVEHDR)(uVar3 * 0x220 + DAT_1000d550 + 0x54),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTIN init waveInPrepareHeader fail \r\n");
    }
    MVar1 = waveInAddBuffer(*(HWAVEIN *)(DAT_1000d550 + 8),
                            (LPWAVEHDR)(uVar3 * 0x220 + DAT_1000d550 + 0x54),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTIN init waveInAddBuffer fail \r\n");
    }
    MVar1 = waveInPrepareHeader(*(HWAVEIN *)(DAT_1000d550 + 0xc),
                                (LPWAVEHDR)(uVar3 * 0xc20 + DAT_1000d550 + 0x1154),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFIN init waveInPrepareHeader fail \r\n");
    }
    MVar1 = waveInAddBuffer(*(HWAVEIN *)(DAT_1000d550 + 0xc),
                            (LPWAVEHDR)(uVar3 * 0xc20 + DAT_1000d550 + 0x1154),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFIN init waveInAddBuffer fail \r\n");
    }
    iVar2 = iVar2 + -1;
    uVar3 = uVar3 + 1 & 3;
  } while (iVar2 != 0);
  uVar3 = 2;
  do {
    MVar1 = waveOutPrepareHeader
                      (*(HWAVEOUT *)(DAT_1000d550 + 0x14),
                       (LPWAVEHDR)(uVar3 * 0x1820 + DAT_1000d550 + 0x41d4),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFOUT init waveOutPrepareHeader fail \r\n");
    }
    MVar1 = waveOutPrepareHeader
                      (*(HWAVEOUT *)(DAT_1000d550 + 0x10),
                       (LPWAVEHDR)(uVar3 * 0x220 + DAT_1000d550 + 0x8d4),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTOUT init waveOutPrepareHeader fail \r\n");
    }
    local_30 = local_30 + -1;
    uVar3 = uVar3 + 1 & 3;
  } while (local_30 != 0);
  return 1;
}



/* 10003768 OnRecMicInBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003768..10003873. Semantic name remains unreviewed.
   void __cdecl OnRecMicInBNT(void) */

void OnRecMicInBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x3768  3  ?OnRecMicInBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecMicInBNT Button on!!!\r\n");
  if (DAT_1000c6c8 == 0) {
    if (DAT_1000d018 == (HANDLE)0x0) {
      DAT_1000d018 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c6c8 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100011bc,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003834:
    if (DAT_1000c6c8 != 0) {
      pwVar1 = L"START";
      goto LAB_10003854;
    }
  }
  else {
    DAT_1000c6b8 = 1;
    DAT_1000c6c8 = 0;
    if (DAT_1000d018 != (HANDLE)0x0) {
      EventModify(DAT_1000d018,3);
      goto LAB_10003834;
    }
  }
  pwVar1 = L"END";
LAB_10003854:
  NKDbgPrintfW(L"[EC] [INFO] MicIn Recording %s\r\n",pwVar1);
  return;
}



/* 10003874 OnRecRecvInBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003874..1000397f. Semantic name remains unreviewed.
   void __cdecl OnRecRecvInBNT(void) */

void OnRecRecvInBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x3874  5  ?OnRecRecvInBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecRecvInBNT Button on!!!\r\n");
  if (DAT_1000c6c0 == 0) {
    if (DAT_1000d020 == (HANDLE)0x0) {
      DAT_1000d020 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c6c0 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001d14,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003940:
    if (DAT_1000c6c0 != 0) {
      pwVar1 = L"START";
      goto LAB_10003960;
    }
  }
  else {
    DAT_1000c6b0 = 1;
    DAT_1000c6c0 = 0;
    if (DAT_1000d020 != (HANDLE)0x0) {
      EventModify(DAT_1000d020,3);
      goto LAB_10003940;
    }
  }
  pwVar1 = L"END";
LAB_10003960:
  NKDbgPrintfW(L"[EC] [INFO] RecvIn Recording %s\r\n",pwVar1);
  return;
}



/* 10003980 OnRecMicOutBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003980..10003a8b. Semantic name remains unreviewed.
   void __cdecl OnRecMicOutBNT(void) */

void OnRecMicOutBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x3980  4  ?OnRecMicOutBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecMicOutBNT Button on!!!\r\n");
  if (DAT_1000c6c4 == 0) {
    if (DAT_1000d01c == (HANDLE)0x0) {
      DAT_1000d01c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c6c4 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001768,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003a4c:
    if (DAT_1000c6c4 != 0) {
      pwVar1 = L"START";
      goto LAB_10003a6c;
    }
  }
  else {
    DAT_1000c6b4 = 1;
    DAT_1000c6c4 = 0;
    if (DAT_1000d01c != (HANDLE)0x0) {
      EventModify(DAT_1000d01c,3);
      goto LAB_10003a4c;
    }
  }
  pwVar1 = L"END";
LAB_10003a6c:
  NKDbgPrintfW(L"[EC] [INFO] MicOut Recording %s\r\n",pwVar1);
  return;
}



/* 10003a8c OnRecRecvOutBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003a8c..10003b97. Semantic name remains unreviewed.
   void __cdecl OnRecRecvOutBNT(void) */

void OnRecRecvOutBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x3a8c  6  ?OnRecRecvOutBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecRecvOutBNT Button on!!!\r\n");
  if (DAT_1000c6bc == 0) {
    if (DAT_1000d024 == (HANDLE)0x0) {
      DAT_1000d024 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c6bc = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100022c0,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003b58:
    if (DAT_1000c6bc != 0) {
      pwVar1 = L"START";
      goto LAB_10003b78;
    }
  }
  else {
    DAT_1000c6ac = 1;
    DAT_1000c6bc = 0;
    if (DAT_1000d024 != (HANDLE)0x0) {
      EventModify(DAT_1000d024,3);
      goto LAB_10003b58;
    }
  }
  pwVar1 = L"END";
LAB_10003b78:
  NKDbgPrintfW(L"[EC] [INFO] RecvOut Recording %s\r\n",pwVar1);
  return;
}



/* 10003b98 GetECVersion */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 10003b98..10003ccf. Semantic name remains unreviewed.
   void __cdecl GetECVersion(char *,unsigned int,char *,unsigned int) */

void GetECVersion(char *param_1,uint param_2,char *param_3,uint param_4)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  int local_38;
  int local_34 [3];
  
                    /* 0x3b98  2  ?GetECVersion@@YAXPADI0I@Z */
  local_38 = 0;
  local_34[2] = 0;
  local_34[1] = 0;
  sseGetVersion(local_34,&local_38,local_34 + 2,local_34 + 1);
  *param_3 = '\0';
  uVar4 = 0;
  if (local_34[0] != 1) {
    iVar3 = 0;
    do {
      sVar1 = strlen(param_3);
      sVar2 = strlen(param_3);
      sprintf_s(param_3 + sVar2,param_4 - sVar1,"%d.",*(undefined4 *)(iVar3 + local_38));
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < local_34[0] - 1U);
  }
  sVar1 = strlen(param_3);
  sVar2 = strlen(param_3);
  sprintf_s(param_3 + sVar2,param_4 - sVar1,"%d",*(undefined4 *)(uVar4 * 4 + local_38));
  sprintf_s(param_1,param_2,"1.0.0.2011");
  return;
}



/* 10003cd0 FUN_10003cd0 */

/* Boundary evidence: original MIPS .pdata 10003cd0..10003d5f. Semantic name remains unreviewed. */

void FUN_10003cd0(int *param_1)

{
  ushort uVar1;
  
  if ((param_1 != (int *)0x0) && ((short *)*param_1 != (short *)0x0)) {
    if (*(short *)*param_1 != 0) {
      uVar1 = 0;
      do {
        if (*(void **)(*param_1 + 4) != (void *)0x0) {
          free(*(void **)(*param_1 + 4));
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(ushort *)*param_1);
    }
    free((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



/* 10003d60 FUN_10003d60 */

/* Boundary evidence: original MIPS .pdata 10003d60..10003dd3. Semantic name remains unreviewed. */

undefined4 FUN_10003d60(void)

{
  int iVar1;
  
  iVar1 = WSAStartup(0x202,(LPWSADATA)&DAT_1000c4d8);
  if ((iVar1 == 0) && (DAT_10009134 = socket(2,1,0), DAT_10009134 != 0xffffffff)) {
    return 1;
  }
  return 0;
}



/* 10003dd4 FUN_10003dd4 */

/* Boundary evidence: original MIPS .pdata 10003dd4..10003e93. Semantic name remains unreviewed. */

undefined4 FUN_10003dd4(u_short param_1)

{
  int iVar1;
  
  if (DAT_10009134 != 0xffffffff) {
    memset(&DAT_1000c4c8,0,0x10);
    DAT_1000c4c8 = 2;
    DAT_1000c4cc = htonl(0);
    DAT_1000c4ca = htons(param_1);
    iVar1 = bind(DAT_10009134,(sockaddr *)&DAT_1000c4c8,0x10);
    if (iVar1 != -1) {
      return 1;
    }
  }
  return 0;
}



/* 10003e94 FUN_10003e94 */

/* Boundary evidence: original MIPS .pdata 10003e94..10003f17. Semantic name remains unreviewed. */

void FUN_10003e94(void)

{
  CloseHandle(DAT_1000915c);
  CloseHandle(DAT_10009158);
  DAT_10009138 = 0xffffffff;
  closesocket(0xffffffff);
  closesocket(DAT_10009134);
  WSACleanup();
  return;
}



/* 10003f18 FUN_10003f18 */

/* Boundary evidence: original MIPS .pdata 10003f18..100040ab. Semantic name remains unreviewed. */

undefined4 FUN_10003f18(SOCKET param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  memset(&DAT_1000b98c,0,0xa28);
  memset(&DAT_1000d02c,0,0x100);
  while( true ) {
    if (DAT_10009138 == -1) {
      return 0;
    }
    if (*(int *)(DAT_1000d550 + 0x2c) == 0) break;
    iVar2 = recv(param_1,&DAT_1000d02c,0x100,0);
    if (iVar2 == -1) {
      return 0;
    }
    uVar3 = DAT_1000d52c + 1 & 0xff;
    if (9 < uVar3) {
      uVar3 = uVar3 + 0xf6 & 0xff;
    }
    if (uVar3 != DAT_1000d52d) {
      iVar1 = (uint)DAT_1000d52c * 0x104;
      memcpy(&DAT_1000b98c + iVar1,&DAT_1000d02c,0x100);
      *(int *)(&DAT_1000ba8c + iVar1) = iVar2;
      DAT_1000d52c = (byte)uVar3;
    }
    DAT_1000d530 = 1;
    memset(&DAT_1000d02c,0,0x100);
  }
  Sleep(0x20);
  return 0;
}



/* 100040ac FUN_100040ac */

/* Boundary evidence: original MIPS .pdata 100040ac..1000424f. Semantic name remains unreviewed. */

undefined4 FUN_100040ac(SOCKET param_1)

{
  byte bVar1;
  int iVar2;
  size_t _Size;
  
  memset(&DAT_10009164,0,0x2828);
  memset(&DAT_1000d12c,0,0x400);
  DAT_10009160 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,10,(LPCWSTR)0x0);
  while ((DAT_10009138 != -1 && (Sleep(1), *(int *)(DAT_1000d550 + 0x2c) != 0))) {
    WaitForSingleObject(DAT_10009160,0xffffffff);
    _Size = *(size_t *)(&DAT_10009564 + (uint)DAT_1000d52f * 0x404);
    memcpy(&DAT_1000d12c,&DAT_10009164 + (uint)DAT_1000d52f * 0x404,_Size);
    iVar2 = send(param_1,&DAT_1000d12c,_Size,0);
    bVar1 = DAT_1000d52f;
    if ((iVar2 != -1) && (bVar1 = DAT_1000d52f + 1, 9 < (byte)(DAT_1000d52f + 1))) {
      bVar1 = DAT_1000d52f - 9;
    }
    DAT_1000d52f = bVar1;
    memset(&DAT_1000d12c,0,0x400);
  }
  return 0;
}



/* 10004250 EndEC */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10004250..10004abb. Semantic name remains unreviewed.
   void __cdecl EndEC(void) */

void EndEC(void)

{
  MMRESULT MVar1;
  wchar_t *pwVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  wchar_t *pwVar6;
  
                    /* 0x4250  1  ?EndEC@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] EndEC!\r\n");
  pvVar4 = DAT_1000d550;
  if (DAT_1000d550 != (void *)0x0) {
    if (*(int *)((int)DAT_1000d550 + 0x18) == 1) {
      *(undefined4 *)((int)DAT_1000d550 + 0x18) = 0;
      iVar3 = *(int *)((int)pvVar4 + 0x1c);
      while (iVar3 == 1) {
        EventModify(*(undefined4 *)((int)pvVar4 + 0x20),3);
        Sleep(0x10);
        pvVar4 = DAT_1000d550;
        iVar3 = *(int *)((int)DAT_1000d550 + 0x1c);
      }
      iVar3 = *(int *)((int)pvVar4 + 0x2c);
      while (iVar3 == 1) {
        EventModify(*(undefined4 *)((int)pvVar4 + 0x30),3);
        Sleep(0x10);
        pvVar4 = DAT_1000d550;
        iVar3 = *(int *)((int)DAT_1000d550 + 0x2c);
      }
    }
    pwVar6 = L"[EC] [ERROR] MMSYSERR_INVALHANDLE\n";
    if (*(HWAVEOUT *)((int)pvVar4 + 0x10) != (HWAVEOUT)0x0) {
      MVar1 = waveOutPause(*(HWAVEOUT *)((int)pvVar4 + 0x10));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveOutPause ERROR\r\n");
      }
      MVar1 = waveOutReset(*(HWAVEOUT *)((int)DAT_1000d550 + 0x10));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveOutReset ERROR\r\n");
      }
      iVar3 = 0;
      uVar5 = 0;
      do {
        MVar1 = waveOutUnprepareHeader
                          (*(HWAVEOUT *)((int)DAT_1000d550 + 0x10),
                           (LPWAVEHDR)((int)DAT_1000d550 + uVar5 + 0x8d4),0x20);
        if (MVar1 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrBTOUT[%d] fail. \r\n",iVar3);
          pwVar2 = pwVar6;
          if (MVar1 != 5) {
            if (MVar1 == 6) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar1 == 7) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar1 == 0x21) {
              pwVar2 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar1 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar1);
                goto LAB_10004448;
              }
              pwVar2 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar2);
        }
LAB_10004448:
        uVar5 = uVar5 + 0x220;
        iVar3 = iVar3 + 1;
      } while (uVar5 < 0x880);
      MVar1 = waveOutClose(*(HWAVEOUT *)((int)DAT_1000d550 + 0x10));
      pvVar4 = DAT_1000d550;
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveOutClose ERROR\r\n");
        pvVar4 = DAT_1000d550;
      }
    }
    if (*(HWAVEIN *)((int)pvVar4 + 8) != (HWAVEIN)0x0) {
      MVar1 = waveInStop(*(HWAVEIN *)((int)pvVar4 + 8));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveInStop ERROR\r\n");
      }
      MVar1 = waveInReset(*(HWAVEIN *)((int)DAT_1000d550 + 8));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveInReset ERROR\r\n");
      }
      iVar3 = 0;
      uVar5 = 0;
      do {
        MVar1 = waveInUnprepareHeader
                          (*(HWAVEIN *)((int)DAT_1000d550 + 8),
                           (LPWAVEHDR)((int)DAT_1000d550 + uVar5 + 0x54),0x20);
        if (MVar1 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrBTIN[%d] fail. \r\n",iVar3);
          pwVar2 = pwVar6;
          if (MVar1 != 5) {
            if (MVar1 == 6) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar1 == 7) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar1 == 0x21) {
              pwVar2 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar1 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar1);
                goto LAB_10004590;
              }
              pwVar2 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar2);
        }
LAB_10004590:
        uVar5 = uVar5 + 0x220;
        iVar3 = iVar3 + 1;
      } while (uVar5 < 0x880);
      MVar1 = waveInClose(*(HWAVEIN *)((int)DAT_1000d550 + 8));
      pvVar4 = DAT_1000d550;
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_BT waveInClose ERROR\r\n");
        pvVar4 = DAT_1000d550;
      }
    }
    if (*(HWAVEOUT *)((int)pvVar4 + 0x14) != (HWAVEOUT)0x0) {
      MVar1 = waveOutPause(*(HWAVEOUT *)((int)pvVar4 + 0x14));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutPause ERROR\r\n");
      }
      MVar1 = waveOutReset(*(HWAVEOUT *)((int)DAT_1000d550 + 0x14));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutReset ERROR\r\n");
      }
      iVar3 = 0;
      uVar5 = 0;
      do {
        MVar1 = waveOutUnprepareHeader
                          (*(HWAVEOUT *)((int)DAT_1000d550 + 0x14),
                           (LPWAVEHDR)((int)DAT_1000d550 + uVar5 + 0x41d4),0x20);
        if (MVar1 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrHFOUT[%d] fail. \r\n",iVar3);
          pwVar2 = pwVar6;
          if (MVar1 != 5) {
            if (MVar1 == 6) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar1 == 7) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar1 == 0x21) {
              pwVar2 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar1 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar1);
                goto LAB_100046d8;
              }
              pwVar2 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar2);
        }
LAB_100046d8:
        uVar5 = uVar5 + 0x1820;
        iVar3 = iVar3 + 1;
      } while (uVar5 < 0x6080);
      MVar1 = waveOutClose(*(HWAVEOUT *)((int)DAT_1000d550 + 0x14));
      pvVar4 = DAT_1000d550;
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutClose ERROR\r\n");
        pvVar4 = DAT_1000d550;
      }
    }
    if (*(HWAVEIN *)((int)pvVar4 + 0xc) != (HWAVEIN)0x0) {
      MVar1 = waveInStop(*(HWAVEIN *)((int)pvVar4 + 0xc));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInStop ERROR\r\n");
      }
      MVar1 = waveInReset(*(HWAVEIN *)((int)DAT_1000d550 + 0xc));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInReset ERROR\r\n");
      }
      iVar3 = 0;
      uVar5 = 0;
      do {
        MVar1 = waveInUnprepareHeader
                          (*(HWAVEIN *)((int)DAT_1000d550 + 0xc),
                           (LPWAVEHDR)((int)DAT_1000d550 + uVar5 + 0x1154),0x20);
        if (MVar1 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrHFIN[%d] fail. \r\n",iVar3);
          pwVar2 = pwVar6;
          if (MVar1 != 5) {
            if (MVar1 == 6) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar1 == 7) {
              pwVar2 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar1 == 0x21) {
              pwVar2 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar1 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar1);
                goto LAB_10004820;
              }
              pwVar2 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar2);
        }
LAB_10004820:
        uVar5 = uVar5 + 0xc20;
        iVar3 = iVar3 + 1;
      } while (uVar5 < 0x3080);
      MVar1 = waveInClose(*(HWAVEIN *)((int)DAT_1000d550 + 0xc));
      if (MVar1 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInClose ERROR\r\n");
      }
    }
    NKDbgPrintfW(L"[EC] [INFO] Device Close!\r\n");
    free(DAT_1000cfec);
    DAT_1000cfec = (void *)0x0;
    if (DAT_1000cfe4 != 0) {
      iVar3 = sseDestroy(&DAT_1000cfe4);
      if (iVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] ERROR in sseDestroy()\n");
      }
      DAT_1000cfe4 = 0;
    }
    if (DAT_1000cfe8 != 0) {
      FUN_10003cd0(&DAT_1000cfe8);
      DAT_1000cfe8 = 0;
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x30) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x30));
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x20) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x20));
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x4c) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x4c));
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x40) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x40));
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x38) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x38));
    }
    if (*(HANDLE *)((int)DAT_1000d550 + 0x28) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d550 + 0x28));
    }
    if (DAT_1000d544 != (HANDLE)0x0) {
      CloseHandle(DAT_1000d544);
    }
    if (DAT_1000d548 != (HANDLE)0x0) {
      CloseHandle(DAT_1000d548);
    }
    if (DAT_1000d53c != (HANDLE)0x0) {
      CloseHandle(DAT_1000d53c);
    }
    if (DAT_1000d540 != (HANDLE)0x0) {
      CloseHandle(DAT_1000d540);
    }
    if (DAT_1000d54c != (HANDLE)0x0) {
      CloseHandle(DAT_1000d54c);
    }
    free(DAT_1000d550);
    DAT_1000d550 = (void *)0x0;
  }
  TerminateThread(DAT_10009158,0);
  CloseHandle(DAT_10009160);
  FUN_10003e94();
  return;
}



/* 10004abc FUN_10004abc */

/* Boundary evidence: original MIPS .pdata 10004abc..10004c4b. Semantic name remains unreviewed. */

void FUN_10004abc(char *param_1,int *param_2)

{
  errno_t eVar1;
  size_t _Size;
  void *pvVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  FILE *local_20 [2];
  
  local_20[0] = (FILE *)0x0;
  if (param_2 == (int *)0x0) {
    pwVar4 = L"[EC] [ERROR] Illegal NULL pointer. No config data has been loaded from file!\n";
  }
  else {
    *param_2 = 0;
    if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
      pwVar4 = L"[EC] [ERROR] No config file available. Continuing without ...\n";
    }
    else {
      eVar1 = fopen_s(local_20,param_1,"rb");
      if (local_20[0] == (FILE *)0x0) {
        NKDbgPrintfW(L"Error NUM fopen_s(&pFile, pFileName,) = %d \r\n",eVar1);
        pwVar4 = L"[EC] [ERROR] Error opening config data file. Continuing without ...\n";
      }
      else {
        fseek(local_20[0],0,2);
        _Size = ftell(local_20[0]);
        fseek(local_20[0],0,0);
        if ((int)_Size < 1) {
LAB_10004bec:
          pwVar4 = L"[EC] [ERROR] Error reading config data from file. Continuing without ...\n";
        }
        else {
          pvVar2 = calloc(1,0x1c);
          *param_2 = (int)pvVar2;
          if (pvVar2 != (void *)0x0) {
            pvVar2 = malloc(_Size);
            *(void **)(*param_2 + 4) = pvVar2;
            if (*(int *)(*param_2 + 4) != 0) {
              *(size_t *)(*param_2 + 0x10) = _Size;
              *(undefined2 *)*param_2 = 1;
              sVar3 = fread(*(void **)(*param_2 + 4),1,_Size,local_20[0]);
              if (_Size == sVar3) {
                NKDbgPrintfW(L"[EC] [INFO] Config data has been loaded from file ==> %s.\n",param_1)
                ;
                goto LAB_10004c1c;
              }
              goto LAB_10004bec;
            }
          }
          pwVar4 = L"[EC] [ERROR] Memory allocation for config data failed. Continuing without...\n"
          ;
        }
      }
    }
  }
  NKDbgPrintfW(pwVar4);
  FUN_10003cd0(param_2);
LAB_10004c1c:
  if (local_20[0] != (FILE *)0x0) {
    fclose(local_20[0]);
  }
  return;
}



/* 10004c4c FUN_10004c4c */

/* Boundary evidence: original MIPS .pdata 10004c4c..10004d2b. Semantic name remains unreviewed. */

void FUN_10004c4c(void)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = listen(DAT_10009134,5);
  if (iVar1 == -1) {
    MessageBoxW((HWND)0x0,L"failed to listen",L"EC Manager",0);
  }
  else {
    local_10[0] = 0x10;
    DAT_10009138 = (LPVOID)accept(DAT_10009134,(sockaddr *)&DAT_1000c4b8,local_10);
    DAT_1000915c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10003f18,DAT_10009138,0,
                                (LPDWORD)0x0);
    DAT_10009158 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100040ac,DAT_10009138,0,
                                (LPDWORD)0x0);
  }
  return;
}



/* 10004d2c FUN_10004d2c */

/* Boundary evidence: original MIPS .pdata 10004d2c..10004d4b. Semantic name remains unreviewed. */

undefined4 FUN_10004d2c(void)

{
  FUN_10004c4c();
  return 0;
}



/* 10004d4c FUN_10004d4c */

/* Boundary evidence: original MIPS .pdata 10004d4c..10005013. Semantic name remains unreviewed. */

void FUN_10004d4c(void)

{
  undefined2 local_60 [2];
  undefined4 local_5c;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 auStack_48 [8];
  char acStack_40 [36];
  uint local_1c;
  
  local_1c = DAT_10009150;
  local_60[0] = 1;
  local_56 = 0x80;
  local_58 = 8000;
  memcpy(acStack_40,"\\Storage Card\\system\\EC_config.bsd",0x23);
  local_50 = 0;
  local_4c = 0;
  local_54 = 0;
  DAT_1000cfec = malloc(0x18);
  memset(DAT_1000cfec,0,0x18);
  FUN_10004abc(acStack_40,&DAT_1000cfe8);
  sseGetVersion(auStack_48,&local_50,&local_4c,&local_54);
  DAT_1000cff4 = sseCreate(&DAT_1000cfe4,0,0);
  if (DAT_1000cff4 != 0) goto LAB_10004ff0;
  local_5c = 2;
  DAT_1000cff4 = sseSetData(DAT_1000cfe4,3,0,2,local_60);
  if (DAT_1000cff4 == 0) {
    DAT_1000cff4 = sseSetData(DAT_1000cfe4,0x1f,0,2,&local_58);
    if (DAT_1000cff4 != 0) goto LAB_10004e90;
    DAT_1000cff4 = sseSetData(DAT_1000cfe4,0x1e,0,2,&local_56);
    if (DAT_1000cff4 != 0) goto LAB_10004e90;
LAB_10004ebc:
    DAT_1000cff4 = sseSetData(DAT_1000cfe4,9,0,4,&local_5c);
    if (DAT_1000cff4 == 0) {
      DAT_1000cff4 = sseSetData(DAT_1000cfe4,10,0,4,&local_5c);
      if (DAT_1000cff4 == 0) {
        DAT_1000cff4 = sseSetData(DAT_1000cfe4,0xc,0,4,&local_5c);
        if (DAT_1000cff4 == 0) {
          DAT_1000cff4 = sseSetData(DAT_1000cfe4,4,0,2,local_60);
          if (DAT_1000cff4 == 0) {
            DAT_1000cff4 = sseSetData(DAT_1000cfe4,0x27,0,4,&local_5c);
          }
        }
      }
    }
  }
  else {
LAB_10004e90:
    sseGetErrorMessage(DAT_1000cfe4,&DAT_1000c6cc);
    NKDbgPrintfW(L"[EC] [ERROR] _FIRST__sseSetData failed with error number 0X0%X and error message\n %s\n"
                 ,DAT_1000cff4,&DAT_1000c6cc);
    if (DAT_1000cff4 == 0) goto LAB_10004ebc;
  }
  DAT_1000cff4 = sseSetData(DAT_1000cfe4,4,0,2,local_60);
  if (DAT_1000cff4 != 0) {
    sseGetErrorMessage(DAT_1000cfe4,&DAT_1000c6cc);
    NKDbgPrintfW(L"[EC] [ERROR] Set data failed with error number 0x%4x and error message\n \"%s\"\n"
                 ,DAT_1000cff4,&DAT_1000c6cc);
    if (DAT_1000cff4 != 0) goto LAB_10004ff0;
  }
  DAT_1000cff4 = sseInitialize(DAT_1000cfe4,DAT_1000cfe8);
  if (DAT_1000cff4 != 0) {
    sseGetErrorMessage(DAT_1000cfe4,&DAT_1000c6cc);
    NKDbgPrintfW(L"[EC] [ERROR] sseInitialize failed with error number 0X0%X and error message\n %s\n"
                 ,DAT_1000cff4,&DAT_1000c6cc);
  }
LAB_10004ff0:
  FUN_10005644(local_1c);
  return;
}



/* 10005014 FUN_10005014 */

/* Boundary evidence: original MIPS .pdata 10005014..1000506f. Semantic name remains unreviewed. */

undefined4 FUN_10005014(void)

{
  HANDLE hObject;
  DWORD aDStack_10 [2];
  
  FUN_10003d60();
  FUN_10003dd4(0x7dc);
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10004d2c,(LPVOID)0x0,0,aDStack_10);
  CloseHandle(hObject);
  return 1;
}



/* 10005070 StartEC */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10005070..1000534f. Semantic name remains unreviewed.
   void __cdecl StartEC(void) */

void StartEC(void)

{
  void *pvVar1;
  HANDLE pvVar2;
  int iVar3;
  HANDLE pvVar4;
  
                    /* 0x5070  7  ?StartEC@@YAXXZ */
  Sleep(100);
  NKDbgPrintfW(L"[EC] [INFO] StartEC!\r\n");
  DAT_1000d550 = malloc(0xa65c);
  memset(DAT_1000d550,0,0xa65c);
  DAT_1000c6c8 = 0;
  DAT_1000c6c4 = 0;
  DAT_1000c6c0 = 0;
  DAT_1000c6bc = 0;
  FUN_10004d4c();
  DAT_1000d544 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_1000d548 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x30) = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x20) = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x4c) = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x40) = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x38) = pvVar2;
  pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  *(HANDLE *)((int)DAT_1000d550 + 0x28) = pvVar2;
  DAT_1000d53c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_1000d540 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  DAT_1000d54c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  iVar3 = FUN_10003288();
  if (iVar3 == 0) {
    NKDbgPrintfW(L"[EC] [ERROR] Device Open Error!\r\n");
  }
  else {
    FUN_1000347c();
    FUN_1000357c();
    Sleep(0x80);
    pvVar1 = DAT_1000d550;
    *(undefined4 *)((int)DAT_1000d550 + 0x2c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x1c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x48) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3c) = 0;
    *(undefined4 *)((int)pvVar1 + 0x18) = 1;
    pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_1000286c,(LPVOID)0x0,0,(LPDWORD)0x0);
    pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001000,(LPVOID)0x0,0,(LPDWORD)0x0);
    CeSetThreadPriority(pvVar2,0x66);
    CeSetThreadQuantum(pvVar2,2);
    CeSetThreadPriority(pvVar4,0x66);
    CeSetThreadQuantum(pvVar4,2);
    FUN_10005014();
  }
  return;
}



/* 10005550 FUN_10005550 */

/* Boundary evidence: original MIPS .pdata 10005550..100055c3. Semantic name remains unreviewed. */

void FUN_10005550(void)

{
  uint uVar1;
  
  if ((DAT_10009150 == 0) || (DAT_10009150 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_10009150 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_10009150 == 0) {
      DAT_10009150 = 0xb064;
    }
  }
  DAT_10009154 = ~DAT_10009150;
  return;
}



/* 100055c4 FUN_100055c4 */

/* Boundary evidence: original MIPS .pdata 100055c4..10005617. Semantic name remains unreviewed. */

void FUN_100055c4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10005644(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 10005618 FUN_10005618 */

/* Boundary evidence: original MIPS .pdata 10005618..10005643. Semantic name remains unreviewed. */

undefined4 FUN_10005618(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_100055c4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10005644 FUN_10005644 */

/* Boundary evidence: original MIPS .pdata 10005644..1000568b. Semantic name remains unreviewed. */

void FUN_10005644(uint param_1)

{
  if ((param_1 == DAT_10009150) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 1000568c FUN_1000568c */

/* Boundary evidence: original MIPS .pdata 1000568c..100057c7. Semantic name remains unreviewed. */

int FUN_1000568c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_1000d568 != (code *)0x0) {
      iVar2 = (*DAT_1000d568)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1000573c;
    FUN_10005a40();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_100059c0(param_1,param_2);
  }
LAB_1000573c:
  if (((param_2 == 0) && (FUN_1000599c(), iVar1 != 0)) && (DAT_1000d568 != (code *)0x0)) {
    iVar1 = (*DAT_1000d568)(param_1,0,param_3);
  }
  return iVar1;
}



/* 100057c8 FUN_100057c8 */

/* Boundary evidence: original MIPS .pdata 100057c8..100057f3. Semantic name remains unreviewed. */

void FUN_100057c8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 100057f4 entry */

/* Boundary evidence: original MIPS .pdata 100057f4..1000584b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_10005550();
  }
  FUN_1000568c(param_1,param_2,param_3);
  return;
}



/* 1000587c FUN_1000587c */

/* Boundary evidence: original MIPS .pdata 1000587c..1000599b. Semantic name remains unreviewed. */

void FUN_1000587c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_1000d558 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_1000d560;
    if (DAT_1000d560 != (undefined4 *)0x0) {
      while (DAT_1000d55c = DAT_1000d55c + -1, _Memory <= DAT_1000d55c) {
        if ((code *)*DAT_1000d55c != (code *)0x0) {
          (*(code *)*DAT_1000d55c)();
          _Memory = DAT_1000d560;
        }
      }
      free(_Memory);
      DAT_1000d55c = (undefined4 *)0x0;
      DAT_1000d560 = (undefined4 *)0x0;
    }
    FUN_100059ec((undefined4 *)&DAT_10006010,(undefined4 *)&DAT_10006014);
  }
  FUN_100059ec((undefined4 *)&DAT_10006018,(undefined4 *)&DAT_1000601c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_1000d564,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 1000599c FUN_1000599c */

/* Boundary evidence: original MIPS .pdata 1000599c..100059bf. Semantic name remains unreviewed. */

void FUN_1000599c(void)

{
  FUN_1000587c(0,0,1);
  return;
}



/* 100059c0 FUN_100059c0 */

/* Boundary evidence: original MIPS .pdata 100059c0..100059eb. Semantic name remains unreviewed. */

undefined4 FUN_100059c0(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 100059ec FUN_100059ec */

/* Boundary evidence: original MIPS .pdata 100059ec..10005a3f. Semantic name remains unreviewed. */

void FUN_100059ec(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 10005a40 FUN_10005a40 */

/* Boundary evidence: original MIPS .pdata 10005a40..10005a7b. Semantic name remains unreviewed. */

void FUN_10005a40(void)

{
  FUN_100059ec((undefined4 *)&DAT_10006008,(undefined4 *)&DAT_1000600c);
  FUN_100059ec((undefined4 *)&DAT_10006000,(undefined4 *)&DAT_10006004);
  return;
}


