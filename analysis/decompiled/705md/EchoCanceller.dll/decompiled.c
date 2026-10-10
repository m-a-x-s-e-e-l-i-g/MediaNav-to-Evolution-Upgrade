/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 10001000 FUN_10001000 */

/* Boundary evidence: original MIPS .pdata 10001000..100011c3. Semantic name remains unreviewed. */

undefined4 FUN_10001000(void)

{
  MMRESULT MVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(DAT_1000d4a4 + 0x1c) = 1;
  NKDbgPrintfW(L"[EC] [INFO] BT waveInStart \r\n");
  MVar1 = waveInStart(*(HWAVEIN *)(DAT_1000d4a4 + 8));
  if (MVar1 == 0) {
    DVar2 = WaitForSingleObject(*(HANDLE *)(DAT_1000d4a4 + 0x20),0xffffffff);
    iVar5 = DAT_1000d4a4;
    if (DVar2 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] (BTIN)INIT Timeout waiting for capture to complete ==> %08x Index = %d\r\n"
                   ,*(undefined4 *)(DAT_1000d4a4 + 0xcbc),3);
      iVar5 = DAT_1000d4a4;
      *(undefined4 *)(DAT_1000d4a4 + 0x18) = 0;
    }
    memcpy(&DAT_1000d058,(void *)(iVar5 + 0xccc),0x400);
    waveInAddBuffer(*(HWAVEIN *)(iVar5 + 8),(LPWAVEHDR)(iVar5 + 0xcac),0x20);
    iVar5 = 0;
    iVar4 = *(int *)(DAT_1000d4a4 + 0x18);
    iVar3 = DAT_1000d4a4;
    while (DAT_1000d4a4 = iVar3, iVar4 != 0) {
      DVar2 = WaitForSingleObject(*(HANDLE *)(iVar3 + 0x20),0x500);
      iVar3 = DAT_1000d4a4;
      if (DVar2 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] (BTIN)Timeout waiting for capture to complete ==> %08x Index = %d\r\n"
                     ,*(undefined4 *)(iVar5 * 0x420 + DAT_1000d4a4 + 0x5c),iVar5);
        iVar3 = DAT_1000d4a4;
        *(undefined4 *)(DAT_1000d4a4 + 0x18) = 0;
      }
      if (*(int *)(iVar3 + 0x18) == 0) break;
      waveInAddBuffer(*(HWAVEIN *)(iVar3 + 8),(LPWAVEHDR)(iVar5 * 0x420 + iVar3 + 0x4c),0x20);
      iVar5 = iVar5 + 1;
      if (iVar5 == 4) {
        iVar5 = 0;
      }
      iVar3 = DAT_1000d4a4;
      iVar4 = *(int *)(DAT_1000d4a4 + 0x18);
    }
  }
  else {
    NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveInStart fail \r\n");
    iVar3 = DAT_1000d4a4;
  }
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  CloseHandle(*(HANDLE *)(iVar3 + 0x20));
  *(undefined4 *)(DAT_1000d4a4 + 0x20) = 0;
  return 0;
}



/* 100011c4 FUN_100011c4 */

/* Boundary evidence: original MIPS .pdata 100011c4..1000176f. Semantic name remains unreviewed. */

undefined4 FUN_100011c4(void)

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
  if (DAT_1000c3f4 == 0) {
    DAT_1000c3b4 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c3dc = 0x46464952;
    local_33 = 0;
    DAT_1000c3e4 = 0x45564157;
    DAT_1000c3e0 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3cc = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c3d8 = 0x12;
    DAT_1000c3d0 = 0;
    DAT_1000c3c4 = CreateFileW(L"Storage Card3\\MicInSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c3c4 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\MicInSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009130 != 0) goto LAB_10001534;
  }
  do {
    WaitForSingleObject(DAT_1000d47c,0xffffffff);
    if (DAT_1000c404 == 0) break;
    BVar4 = WriteFile(DAT_1000c3c4,DAT_1000c448,0x400,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing MicIn PCM data.2 [0x%08X][%d]\r\n",DAT_1000c3c4,DVar3
                  );
      CloseHandle(DAT_1000c3c4);
      DAT_1000c3c4 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c3b4 = DAT_1000c3b4 + 1;
    }
  } while (DAT_10009130 == 0);
LAB_10001534:
  DAT_10009130 = 1;
  if (DAT_1000d47c != (HANDLE)0x0) {
    CloseHandle(DAT_1000d47c);
  }
  DAT_1000d47c = (HANDLE)0x0;
  if (DAT_1000c3f4 == 1) {
    SetFilePointer(DAT_1000c3c4,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3d8 = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c3d0 = DAT_1000c3b4 * 0x400;
    DAT_1000c3cc = 0x61746164;
    DAT_1000c3dc = 0x46464952;
    DAT_1000c3e0 = DAT_1000c3d0 + 0x26;
    DAT_1000c3e4 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c4,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c3c4);
    DAT_1000c3c4 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nMicInRecordedBufferNum = %d\r\n",DAT_1000c3b4);
    DAT_1000c3f4 = 0;
  }
  return 0;
}



/* 10001770 FUN_10001770 */

/* Boundary evidence: original MIPS .pdata 10001770..10001d1b. Semantic name remains unreviewed. */

undefined4 FUN_10001770(void)

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
  
  DAT_10009134 = 0;
  if (DAT_1000c3f0 == 0) {
    DAT_1000c3b0 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c3dc = 0x46464952;
    local_33 = 0;
    DAT_1000c3e4 = 0x45564157;
    DAT_1000c3e0 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3cc = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c3d8 = 0x12;
    DAT_1000c3d0 = 0;
    DAT_1000c3c0 = CreateFileW(L"Storage Card3\\MicOutSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c3c0 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\MicOutSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009134 != 0) goto LAB_10001ae0;
  }
  do {
    WaitForSingleObject(DAT_1000d480,0xffffffff);
    if (DAT_1000c400 == 0) break;
    BVar4 = WriteFile(DAT_1000c3c0,DAT_1000c418,0x400,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing MicOut PCM data.2 [0x%08X][%d]\r\n",DAT_1000c3c0,
                   DVar3);
      CloseHandle(DAT_1000c3c0);
      DAT_1000c3c0 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c3b0 = DAT_1000c3b0 + 1;
    }
  } while (DAT_10009134 == 0);
LAB_10001ae0:
  DAT_10009134 = 1;
  if (DAT_1000d480 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d480);
  }
  DAT_1000d480 = (HANDLE)0x0;
  if (DAT_1000c3f0 == 1) {
    SetFilePointer(DAT_1000c3c0,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3d8 = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c3d0 = DAT_1000c3b0 * 0x400;
    DAT_1000c3cc = 0x61746164;
    DAT_1000c3dc = 0x46464952;
    DAT_1000c3e0 = DAT_1000c3d0 + 0x26;
    DAT_1000c3e4 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3c0,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c3c0);
    DAT_1000c3c0 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nMicOutRecordedBufferNum = %d\r\n",DAT_1000c3b0);
    DAT_1000c3f0 = 0;
  }
  return 0;
}



/* 10001d1c FUN_10001d1c */

/* Boundary evidence: original MIPS .pdata 10001d1c..100022c7. Semantic name remains unreviewed. */

undefined4 FUN_10001d1c(void)

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
  
  DAT_10009138 = 0;
  if (DAT_1000c3ec == 0) {
    DAT_1000c3ac = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c3dc = 0x46464952;
    local_33 = 0;
    DAT_1000c3e4 = 0x45564157;
    DAT_1000c3e0 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3cc = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c3d8 = 0x12;
    DAT_1000c3d0 = 0;
    DAT_1000c3bc = CreateFileW(L"Storage Card3\\RecvInSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c3bc == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\RecvInSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_10009138 != 0) goto LAB_1000208c;
  }
  do {
    WaitForSingleObject(DAT_1000d484,0xffffffff);
    if (DAT_1000c3fc == 0) break;
    BVar4 = WriteFile(DAT_1000c3bc,DAT_1000c438,0x400,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing RecvIn PCM data.2 [0x%08X][%d]\r\n",DAT_1000c3bc,
                   DVar3);
      CloseHandle(DAT_1000c3bc);
      DAT_1000c3bc = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c3ac = DAT_1000c3ac + 1;
    }
  } while (DAT_10009138 == 0);
LAB_1000208c:
  DAT_10009138 = 1;
  if (DAT_1000d484 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d484);
  }
  DAT_1000d484 = (HANDLE)0x0;
  if (DAT_1000c3ec == 1) {
    SetFilePointer(DAT_1000c3bc,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3d8 = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c3d0 = DAT_1000c3ac * 0x400;
    DAT_1000c3cc = 0x61746164;
    DAT_1000c3dc = 0x46464952;
    DAT_1000c3e0 = DAT_1000c3d0 + 0x26;
    DAT_1000c3e4 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3bc,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c3bc);
    DAT_1000c3bc = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nRecvInRecordedBufferNum = %d\r\n",DAT_1000c3ac);
    DAT_1000c3ec = 0;
  }
  return 0;
}



/* 100022c8 FUN_100022c8 */

/* Boundary evidence: original MIPS .pdata 100022c8..10002873. Semantic name remains unreviewed. */

undefined4 FUN_100022c8(void)

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
  
  DAT_1000913c = 0;
  if (DAT_1000c3e8 == 0) {
    DAT_1000c3a8 = 0;
    local_30 = 0;
    local_2f = 0;
    local_31 = 0;
    local_3d = 0;
    DAT_1000c3dc = 0x46464952;
    local_33 = 0;
    DAT_1000c3e4 = 0x45564157;
    DAT_1000c3e0 = 0x26;
    puVar1 = local_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 8000U >> (3 - uVar2) * 8;
    puVar1 = local_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 16000U >> (3 - uVar2) * 8;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3cc = 0x61746164;
    local_40 = 1;
    local_3f = 0;
    local_32 = 0x10;
    local_3c = (undefined1  [4])0x1f40;
    local_3e = 1;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    DAT_1000c3d8 = 0x12;
    DAT_1000c3d0 = 0;
    DAT_1000c3b8 = CreateFileW(L"Storage Card3\\RecvOutSignal.wav",0x40000000,1,
                               (LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
    if (DAT_1000c3b8 == (HANDLE)0xffffffff) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"Error opening %s. Error code = 0x%08x\n",L"Storage Card3\\RecvOutSignal.wav",
                   DVar3);
    }
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    if (DAT_1000913c != 0) goto LAB_10002638;
  }
  do {
    WaitForSingleObject(DAT_1000d488,0xffffffff);
    if (DAT_1000c3f8 == 0) break;
    BVar4 = WriteFile(DAT_1000c3b8,DAT_1000c408,0x400,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[g_HFOutFh] Error writing RecvOut PCM data.2 [0x%08X][%d]\r\n",DAT_1000c3b8,
                   DVar3);
      CloseHandle(DAT_1000c3b8);
      DAT_1000c3b8 = (HANDLE)0xffffffff;
    }
    else {
      DAT_1000c3a8 = DAT_1000c3a8 + 1;
    }
  } while (DAT_1000913c == 0);
LAB_10002638:
  DAT_1000913c = 1;
  if (DAT_1000d488 != (HANDLE)0x0) {
    CloseHandle(DAT_1000d488);
  }
  DAT_1000d488 = (HANDLE)0x0;
  if (DAT_1000c3e8 == 1) {
    SetFilePointer(DAT_1000c3b8,0,(PLONG)0x0,0);
    local_2f = 0;
    local_3c = (undefined1  [4])0x1f40;
    local_40 = 1;
    local_3e = 1;
    local_32 = 0x10;
    local_3d = 0;
    local_3f = 0;
    local_31 = 0;
    DAT_1000c3d4 = 0x20746d66;
    DAT_1000c3d8 = 0x12;
    local_34 = 2;
    local_38 = (undefined1  [4])0x3e80;
    local_33 = 0;
    DAT_1000c3d0 = DAT_1000c3a8 * 0x400;
    DAT_1000c3cc = 0x61746164;
    DAT_1000c3dc = 0x46464952;
    DAT_1000c3e0 = DAT_1000c3d0 + 0x26;
    DAT_1000c3e4 = 0x45564157;
    local_30 = 0;
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3dc,0xc,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing file header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3d4,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave header\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&local_40,DAT_1000c3d8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing wave format\r\n");
    }
    BVar4 = WriteFile(DAT_1000c3b8,&DAT_1000c3cc,8,(LPDWORD)&DAT_1000c3c8,(LPOVERLAPPED)0x0);
    if (BVar4 == 0) {
      NKDbgPrintfW(L"Error writing PCM data header\r\n");
    }
    CloseHandle(DAT_1000c3b8);
    DAT_1000c3b8 = (HANDLE)0xffffffff;
    NKDbgPrintfW(L"g_nRecvOutRecordedBufferNum = %d\r\n",DAT_1000c3a8);
    DAT_1000c3e8 = 0;
  }
  return 0;
}



/* 10002874 FUN_10002874 */

/* Boundary evidence: original MIPS .pdata 10002874..1000325b. Semantic name remains unreviewed. */

undefined4 FUN_10002874(void)

{
  bool bVar1;
  undefined2 uVar2;
  HANDLE hSemaphore;
  byte bVar3;
  MMRESULT MVar4;
  DWORD DVar5;
  undefined4 *_Dst;
  int iVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  short *psVar18;
  short *psVar19;
  int local_118;
  int local_114;
  byte local_110;
  int local_10c;
  undefined1 auStack_f8 [200];
  uint local_30;
  
  local_30 = DAT_10009150;
  *(undefined4 *)(DAT_1000d4a4 + 0x28) = 1;
  local_118 = 0;
  NKDbgPrintfW(L"[EC] [INFO] HF waveInStart \r\n");
  MVar4 = waveInStart(*(HWAVEIN *)(DAT_1000d4a4 + 0xc));
  if (MVar4 == 0) {
    DVar5 = WaitForSingleObject(*(HANDLE *)(DAT_1000d4a4 + 0x2c),0xffffffff);
    iVar14 = DAT_1000d4a4;
    if (DVar5 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] (HFIN)INTI Timeout waiting for capture to complete ==> %08x %d\r\n"
                   ,*(undefined4 *)(DAT_1000d4a4 + 0x69bc),3);
      iVar14 = DAT_1000d4a4;
      *(undefined4 *)(DAT_1000d4a4 + 0x18) = 0;
    }
    waveInAddBuffer(*(HWAVEIN *)(iVar14 + 0xc),(LPWAVEHDR)(iVar14 + 0x69ac),0x20);
    local_10c = 2;
    iVar14 = 2;
    iVar16 = 2;
    local_114 = 0;
    do {
      waveOutWrite(*(HWAVEOUT *)(DAT_1000d4a4 + 0x14),
                   (LPWAVEHDR)(iVar14 * 0x3020 + DAT_1000d4a4 + 0x81cc),0x20);
      iVar6 = DAT_1000d4a4;
      iVar14 = iVar14 + 1;
      if (iVar14 == 4) {
        iVar14 = 0;
      }
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(int *)(DAT_1000d4a4 + 0x24) = iVar14;
    iVar14 = 2;
    iVar16 = 2;
    do {
      waveOutWrite(*(HWAVEOUT *)(iVar6 + 0x10),(LPWAVEHDR)(iVar14 * 0x420 + iVar6 + 0x10cc),0x20);
      iVar6 = DAT_1000d4a4;
      iVar14 = iVar14 + 1;
      if (iVar14 == 4) {
        iVar14 = 0;
      }
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(int *)(DAT_1000d4a4 + 0x30) = iVar14;
    if (*(int *)(iVar6 + 0x18) != 0) {
      uVar17 = (uint)local_110;
      do {
        DVar5 = WaitForSingleObject(*(HANDLE *)(iVar6 + 0x2c),0x500);
        iVar6 = DAT_1000d4a4;
        if (DVar5 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] (HFIN)Timeout waiting for capture to complete ==> %08x %d\r\n"
                       ,*(undefined4 *)(local_114 * 0x1820 + DAT_1000d4a4 + 0x215c),local_114);
          iVar6 = DAT_1000d4a4;
          *(undefined4 *)(DAT_1000d4a4 + 0x18) = 0;
        }
        if (*(int *)(iVar6 + 0x18) == 0) break;
        iVar14 = 0x200;
        puVar9 = (undefined2 *)(local_114 * 0x1820 + iVar6 + 0x216c);
        puVar8 = (undefined2 *)(iVar6 + 0x14254);
        do {
          uVar2 = *puVar9;
          puVar9 = puVar9 + 6;
          *puVar8 = uVar2;
          iVar14 = iVar14 + -1;
          puVar8 = puVar8 + 1;
        } while (iVar14 != 0);
        if (DAT_1000d468 == 0) {
          DAT_1000d464 = 1;
        }
        if (DAT_1000d464 == 1) {
          iVar15 = 4;
          iVar12 = local_114 * 0x420 + iVar6;
          iVar14 = iVar6 + 0x14654;
          iVar16 = iVar12 + 0x10ec;
          iVar10 = local_10c * 0x420 + iVar6 + 0x6c;
          iVar12 = iVar12 + 0x6c;
          puVar8 = (undefined2 *)(iVar6 + 0x14254);
          do {
            DAT_1000c448 = puVar8;
            DAT_1000c438 = iVar12;
            DAT_1000c428 = iVar10;
            DAT_1000c418 = iVar16;
            DAT_1000c408 = (void *)iVar14;
            if (DAT_1000d490 == 0) {
              DAT_1000d460[1] = 0;
              DAT_1000d460[2] = 0;
              if (DAT_1000d494 != 0) goto LAB_10002c74;
            }
            else {
              uVar17 = (uint)DAT_1000d48d;
              bVar3 = DAT_1000d48d;
              if (DAT_1000d48c != uVar17) {
                *DAT_1000d460 = 0x100;
                iVar14 = uVar17 * 0x104;
                DAT_1000d460[1] = *(undefined4 *)(&DAT_1000ba80 + iVar14);
                DAT_1000d460[2] = &DAT_1000b980 + iVar14;
                bVar3 = DAT_1000d48d + 1;
                if (9 < (byte)(DAT_1000d48d + 1)) {
                  bVar3 = DAT_1000d48d - 9;
                }
              }
              DAT_1000d48d = bVar3;
              DAT_1000d490 = 0;
              DAT_1000d494 = 1;
LAB_10002c74:
              uVar17 = DAT_1000d48e + 1 & 0xff;
              if (9 < uVar17) {
                uVar17 = uVar17 + 0xf6 & 0xff;
              }
              if (uVar17 != DAT_1000d48f) {
                DAT_1000d460[5] = &DAT_10009158 + (uint)DAT_1000d48e * 0x404;
                DAT_1000d460[3] = 0x400;
              }
            }
            DAT_1000d468 = sseProcess(DAT_1000d458,&DAT_1000c448,&DAT_1000c438,&DAT_1000c428,
                                      &DAT_1000c418,&DAT_1000c408,DAT_1000d460);
            if (DAT_1000d468 != 0) {
              sseGetErrorMessage(DAT_1000d458,auStack_f8);
              NKDbgPrintfW(&DAT_1000679c,DAT_1000d468,auStack_f8);
              DAT_1000d464 = 0;
            }
            hSemaphore = DAT_1000d498;
            _Dst = DAT_1000d460;
            if ((DAT_1000d460[4] == 0) || (DAT_1000d494 != 1)) {
              DAT_1000d494 = 0;
            }
            else {
              uVar7 = (uint)DAT_1000d48e;
              DAT_1000d48e = (byte)uVar17;
              bVar1 = DAT_1000d498 != (HANDLE)0x0;
              *(undefined4 *)(&DAT_10009558 + uVar7 * 0x404) = DAT_1000d460[4];
              if (bVar1) {
                ReleaseSemaphore(hSemaphore,1,(LPLONG)0x0);
                _Dst = DAT_1000d460;
              }
            }
            memset(_Dst,0,0x18);
            iVar15 = iVar15 + -1;
            iVar14 = (int)DAT_1000c408 + 0x100;
            iVar16 = DAT_1000c418 + 0x100;
            iVar10 = DAT_1000c428 + 0x100;
            iVar12 = DAT_1000c438 + 0x100;
            puVar8 = DAT_1000c448 + 0x80;
          } while (iVar15 != 0);
          DAT_1000c448 = DAT_1000c448 + -0x180;
          DAT_1000c418 = DAT_1000c418 + -0x300;
          DAT_1000c438 = DAT_1000c438 + -0x300;
          DAT_1000c428 = DAT_1000c428 + -0x300;
          DAT_1000c408 = (void *)((int)DAT_1000c408 + -0x300);
          memcpy(&DAT_1000c458 + local_114 * 0x400,DAT_1000c408,0x400);
          iVar6 = DAT_1000d4a4;
          if (local_114 == 0) {
            local_118 = 3;
          }
          else if (local_114 != 0) {
            local_118 = local_114 + -1;
          }
          iVar14 = local_114 * 0x3020;
          iVar16 = 0x1ff;
          psVar19 = (short *)(iVar14 + DAT_1000d4a4 + 0x81f0);
          psVar13 = (short *)(&DAT_1000c458 + local_118 * 0x400);
          do {
            sVar11 = *psVar13;
            psVar18 = psVar13 + 1;
            psVar19[-2] = sVar11;
            iVar10 = (int)sVar11 + (int)*psVar18;
            if (iVar10 < 0) {
              iVar10 = iVar10 + 1;
            }
            sVar11 = (short)(iVar10 >> 1);
            psVar19[1] = sVar11;
            iVar10 = (int)sVar11 + (int)*psVar13;
            if (iVar10 < 0) {
              iVar10 = iVar10 + 1;
            }
            sVar11 = (short)(iVar10 >> 1);
            *psVar19 = sVar11;
            iVar10 = (int)sVar11 + (int)*psVar13;
            if (iVar10 < 0) {
              iVar10 = iVar10 + 1;
            }
            psVar19[-1] = (short)(iVar10 >> 1);
            iVar10 = (int)*psVar18 + (int)psVar19[1];
            if (iVar10 < 0) {
              iVar10 = iVar10 + 1;
            }
            sVar11 = (short)(iVar10 >> 1);
            iVar10 = (int)sVar11 + (int)psVar19[1];
            psVar19[3] = sVar11;
            sVar11 = (short)(iVar10 >> 1);
            if (iVar10 < 0) {
              sVar11 = (short)(iVar10 + 1 >> 1);
            }
            psVar19[2] = sVar11;
            iVar16 = iVar16 + -1;
            psVar19 = psVar19 + 6;
            psVar13 = psVar18;
          } while (iVar16 != 0);
          psVar13 = (short *)(local_118 * 0x400 + 0x1000c856);
          iVar12 = iVar14 + iVar6;
          iVar10 = (int)*(short *)(&DAT_1000c458 + local_114 * 0x400);
          sVar11 = *psVar13;
          *(short *)(iVar12 + 0x99e0) = sVar11;
          iVar16 = sVar11 + iVar10;
          if (iVar16 < 0) {
            iVar16 = iVar16 + 1;
          }
          sVar11 = (short)(iVar16 >> 1);
          *(short *)(iVar12 + 0x99e6) = sVar11;
          iVar16 = (int)sVar11 + (int)*psVar13;
          if (iVar16 < 0) {
            iVar16 = iVar16 + 1;
          }
          sVar11 = (short)(iVar16 >> 1);
          *(short *)(iVar14 + iVar6 + 0x99e4) = sVar11;
          iVar14 = (int)sVar11 + (int)*psVar13;
          if (iVar14 < 0) {
            iVar14 = iVar14 + 1;
          }
          iVar16 = (int)*(short *)(iVar12 + 0x99e6);
          *(short *)(iVar12 + 0x99e2) = (short)(iVar14 >> 1);
          iVar10 = iVar10 + iVar16;
          if (iVar10 < 0) {
            iVar10 = iVar10 + 1;
          }
          sVar11 = (short)(iVar10 >> 1);
          *(short *)(iVar12 + 0x99ea) = sVar11;
          iVar16 = sVar11 + iVar16;
          if (iVar16 < 0) {
            iVar16 = iVar16 + 1;
          }
          *(short *)(iVar12 + 0x99e8) = (short)(iVar16 >> 1);
          if (DAT_1000c404 == 1) {
            EventModify(DAT_1000d47c,3);
            iVar6 = DAT_1000d4a4;
          }
          if (DAT_1000c3fc == 1) {
            EventModify(DAT_1000d484,3);
            iVar6 = DAT_1000d4a4;
          }
          if (DAT_1000c400 == 1) {
            EventModify(DAT_1000d480,3);
            iVar6 = DAT_1000d4a4;
          }
          if (DAT_1000c3f8 == 1) {
            EventModify(DAT_1000d488,3);
            iVar6 = DAT_1000d4a4;
          }
        }
        waveOutWrite(*(HWAVEOUT *)(iVar6 + 0x14),
                     (LPWAVEHDR)(*(int *)(iVar6 + 0x24) * 0x3020 + iVar6 + 0x81cc),0x20);
        iVar14 = DAT_1000d4a4;
        iVar16 = *(int *)(DAT_1000d4a4 + 0x24) + 1;
        *(int *)(DAT_1000d4a4 + 0x24) = iVar16;
        if (iVar16 == 4) {
          *(undefined4 *)(iVar14 + 0x24) = 0;
        }
        waveOutWrite(*(HWAVEOUT *)(iVar14 + 0x10),
                     (LPWAVEHDR)(*(int *)(iVar14 + 0x30) * 0x420 + iVar14 + 0x10cc),0x20);
        iVar14 = DAT_1000d4a4;
        iVar16 = *(int *)(DAT_1000d4a4 + 0x30) + 1;
        *(int *)(DAT_1000d4a4 + 0x30) = iVar16;
        if (iVar16 == 4) {
          *(undefined4 *)(iVar14 + 0x30) = 0;
        }
        waveInAddBuffer(*(HWAVEIN *)(iVar14 + 0xc),(LPWAVEHDR)(local_114 * 0x1820 + iVar14 + 0x214c)
                        ,0x20);
        local_114 = local_114 + 1;
        if (local_114 == 4) {
          local_114 = 0;
        }
        local_10c = local_10c + 1;
        if (local_10c == 4) {
          local_10c = 0;
        }
        iVar6 = DAT_1000d4a4;
      } while (*(int *)(DAT_1000d4a4 + 0x18) != 0);
    }
  }
  else {
    NKDbgPrintfW(L"[EC] [ERROR] waveInStart fail \r\n");
    iVar6 = DAT_1000d4a4;
  }
  *(undefined4 *)(iVar6 + 0x28) = 0;
  CloseHandle(*(HANDLE *)(iVar6 + 0x20));
  *(undefined4 *)(DAT_1000d4a4 + 0x20) = 0;
  FUN_10005804(local_30);
  return 0;
}



/* 1000325c FUN_1000325c */

/* Boundary evidence: original MIPS .pdata 1000325c..1000328f. Semantic name remains unreviewed. */

void FUN_1000325c(undefined4 param_1,int param_2)

{
  if (param_2 == 0x3c0) {
    EventModify(*(undefined4 *)(DAT_1000d4a4 + 0x20),3);
  }
  return;
}



/* 10003290 FUN_10003290 */

/* Boundary evidence: original MIPS .pdata 10003290..100032c3. Semantic name remains unreviewed. */

void FUN_10003290(undefined4 param_1,int param_2)

{
  if (param_2 == 0x3c0) {
    EventModify(*(undefined4 *)(DAT_1000d4a4 + 0x2c),3);
  }
  return;
}



/* 100032c4 FUN_100032c4 */

/* Boundary evidence: original MIPS .pdata 100032c4..100034b7. Semantic name remains unreviewed. */

undefined4 FUN_100032c4(void)

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
  MVar4 = waveInOpen((LPHWAVEIN)(DAT_1000d4a4 + 8),1,&local_30,0x1000325c,0,0x30000);
  if (MVar4 == 0) {
    MVar4 = waveOutOpen((LPHWAVEOUT)(DAT_1000d4a4 + 0x10),1,&local_30,0,0,0);
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
      MVar4 = waveInOpen((LPHWAVEIN)(DAT_1000d4a4 + 0xc),0,&local_30,0x10003290,0,0x30000);
      if (MVar4 == 0) {
        MVar4 = waveOutOpen((LPHWAVEOUT)(DAT_1000d4a4 + 0x14),0,&local_30,0,0,0);
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



/* 100034b8 FUN_100034b8 */

/* Boundary evidence: original MIPS .pdata 100034b8..100035bb. Semantic name remains unreviewed. */

void FUN_100034b8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)(DAT_1000d4a4 + 0x81d0);
  puVar3 = (undefined4 *)(DAT_1000d4a4 + 0x2150);
  puVar1 = (undefined4 *)(DAT_1000d4a4 + 0x50);
  iVar4 = 4;
  do {
    memset(puVar1 + -1,0,0x20);
    puVar1[-1] = puVar1 + 7;
    *puVar1 = 0x400;
    memset(puVar1 + 0x41f,0,0x20);
    puVar1[0x41f] = puVar1 + 0x427;
    puVar1[0x420] = 0x400;
    memset(puVar3 + -1,0,0x20);
    puVar3[-1] = puVar3 + 7;
    *puVar3 = 0x1800;
    memset(puVar2 + -1,0,0x20);
    *puVar2 = 0x1800;
    puVar2[-1] = puVar2 + 7;
    puVar1 = puVar1 + 0x108;
    puVar3 = puVar3 + 0x608;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 0xc08;
  } while (iVar4 != 0);
  return;
}



/* 100035bc FUN_100035bc */

/* Boundary evidence: original MIPS .pdata 100035bc..100037c3. Semantic name remains unreviewed. */

undefined4 FUN_100035bc(void)

{
  MMRESULT MVar1;
  int iVar2;
  uint uVar3;
  int local_30;
  
  iVar2 = 4;
  local_30 = 4;
  uVar3 = 3;
  do {
    MVar1 = waveInPrepareHeader(*(HWAVEIN *)(DAT_1000d4a4 + 8),
                                (LPWAVEHDR)(uVar3 * 0x420 + DAT_1000d4a4 + 0x4c),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTIN init waveInPrepareHeader fail[0x%08X} \r\n",MVar1);
    }
    MVar1 = waveInAddBuffer(*(HWAVEIN *)(DAT_1000d4a4 + 8),
                            (LPWAVEHDR)(uVar3 * 0x420 + DAT_1000d4a4 + 0x4c),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTIN init waveInAddBuffer fail[0x%08X} \r\n",MVar1);
    }
    MVar1 = waveInPrepareHeader(*(HWAVEIN *)(DAT_1000d4a4 + 0xc),
                                (LPWAVEHDR)(uVar3 * 0x1820 + DAT_1000d4a4 + 0x214c),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFIN init waveInPrepareHeader fail[0x%08X} \r\n",MVar1);
    }
    MVar1 = waveInAddBuffer(*(HWAVEIN *)(DAT_1000d4a4 + 0xc),
                            (LPWAVEHDR)(uVar3 * 0x1820 + DAT_1000d4a4 + 0x214c),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFIN init waveInAddBuffer fail[0x%08X} \r\n",MVar1);
    }
    iVar2 = iVar2 + -1;
    uVar3 = uVar3 + 1 & 3;
  } while (iVar2 != 0);
  uVar3 = 2;
  do {
    MVar1 = waveOutPrepareHeader
                      (*(HWAVEOUT *)(DAT_1000d4a4 + 0x14),
                       (LPWAVEHDR)(uVar3 * 0x3020 + DAT_1000d4a4 + 0x81cc),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] HFOUT init waveOutPrepareHeader fail[0x%08X} \r\n",MVar1);
    }
    MVar1 = waveOutPrepareHeader
                      (*(HWAVEOUT *)(DAT_1000d4a4 + 0x10),
                       (LPWAVEHDR)(uVar3 * 0x420 + DAT_1000d4a4 + 0x10cc),0x20);
    if (MVar1 != 0) {
      NKDbgPrintfW(L"[EC] [ERROR] BTOUT init waveOutPrepareHeader fail[0x%08X} \r\n",MVar1);
    }
    local_30 = local_30 + -1;
    uVar3 = uVar3 + 1 & 3;
  } while (local_30 != 0);
  return 1;
}



/* 100037c4 OnRecMicInBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 100037c4..100038cf. Semantic name remains unreviewed.
   void __cdecl OnRecMicInBNT(void) */

void OnRecMicInBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x37c4  3  ?OnRecMicInBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecMicInBNT Button on!!!\r\n");
  if (DAT_1000c404 == 0) {
    if (DAT_1000d47c == (HANDLE)0x0) {
      DAT_1000d47c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c404 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100011c4,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003890:
    if (DAT_1000c404 != 0) {
      pwVar1 = L"START";
      goto LAB_100038b0;
    }
  }
  else {
    DAT_1000c3f4 = 1;
    DAT_1000c404 = 0;
    if (DAT_1000d47c != (HANDLE)0x0) {
      EventModify(DAT_1000d47c,3);
      goto LAB_10003890;
    }
  }
  pwVar1 = L"END";
LAB_100038b0:
  NKDbgPrintfW(L"[EC] [INFO] MicIn Recording %s\r\n",pwVar1);
  return;
}



/* 100038d0 OnRecRecvInBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 100038d0..100039db. Semantic name remains unreviewed.
   void __cdecl OnRecRecvInBNT(void) */

void OnRecRecvInBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x38d0  5  ?OnRecRecvInBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecRecvInBNT Button on!!!\r\n");
  if (DAT_1000c3fc == 0) {
    if (DAT_1000d484 == (HANDLE)0x0) {
      DAT_1000d484 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c3fc = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001d1c,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_1000399c:
    if (DAT_1000c3fc != 0) {
      pwVar1 = L"START";
      goto LAB_100039bc;
    }
  }
  else {
    DAT_1000c3ec = 1;
    DAT_1000c3fc = 0;
    if (DAT_1000d484 != (HANDLE)0x0) {
      EventModify(DAT_1000d484,3);
      goto LAB_1000399c;
    }
  }
  pwVar1 = L"END";
LAB_100039bc:
  NKDbgPrintfW(L"[EC] [INFO] RecvIn Recording %s\r\n",pwVar1);
  return;
}



/* 100039dc OnRecMicOutBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 100039dc..10003ae7. Semantic name remains unreviewed.
   void __cdecl OnRecMicOutBNT(void) */

void OnRecMicOutBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x39dc  4  ?OnRecMicOutBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecMicOutBNT Button on!!!\r\n");
  if (DAT_1000c400 == 0) {
    if (DAT_1000d480 == (HANDLE)0x0) {
      DAT_1000d480 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c400 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001770,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003aa8:
    if (DAT_1000c400 != 0) {
      pwVar1 = L"START";
      goto LAB_10003ac8;
    }
  }
  else {
    DAT_1000c3f0 = 1;
    DAT_1000c400 = 0;
    if (DAT_1000d480 != (HANDLE)0x0) {
      EventModify(DAT_1000d480,3);
      goto LAB_10003aa8;
    }
  }
  pwVar1 = L"END";
LAB_10003ac8:
  NKDbgPrintfW(L"[EC] [INFO] MicOut Recording %s\r\n",pwVar1);
  return;
}



/* 10003ae8 OnRecRecvOutBNT */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10003ae8..10003bf3. Semantic name remains unreviewed.
   void __cdecl OnRecRecvOutBNT(void) */

void OnRecRecvOutBNT(void)

{
  HANDLE hObject;
  wchar_t *pwVar1;
  
                    /* 0x3ae8  6  ?OnRecRecvOutBNT@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] OnRecRecvOutBNT Button on!!!\r\n");
  if (DAT_1000c3f8 == 0) {
    if (DAT_1000d488 == (HANDLE)0x0) {
      DAT_1000d488 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    }
    DAT_1000c3f8 = 1;
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100022c8,(LPVOID)0x0,0,(LPDWORD)0x0);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
    }
LAB_10003bb4:
    if (DAT_1000c3f8 != 0) {
      pwVar1 = L"START";
      goto LAB_10003bd4;
    }
  }
  else {
    DAT_1000c3e8 = 1;
    DAT_1000c3f8 = 0;
    if (DAT_1000d488 != (HANDLE)0x0) {
      EventModify(DAT_1000d488,3);
      goto LAB_10003bb4;
    }
  }
  pwVar1 = L"END";
LAB_10003bd4:
  NKDbgPrintfW(L"[EC] [INFO] RecvOut Recording %s\r\n",pwVar1);
  return;
}



/* 10003bf4 GetECVersion */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 10003bf4..10003ddf. Semantic name remains unreviewed.
   void __cdecl GetECVersion(char *,unsigned int,char *,unsigned int) */

void GetECVersion(char *param_1,uint param_2,char *param_3,uint param_4)

{
  size_t sVar1;
  size_t sVar2;
  HANDLE hObject;
  int iVar3;
  uint uVar4;
  int local_248;
  int local_244 [3];
  wchar_t local_238;
  undefined1 auStack_236 [518];
  uint local_30;
  
                    /* 0x3bf4  2  ?GetECVersion@@YAXPADI0I@Z */
  local_30 = DAT_10009150;
  local_248 = 0;
  local_244[2] = 0;
  local_244[1] = 0;
  sseGetVersion(local_244,&local_248,local_244 + 2,local_244 + 1);
  uVar4 = 0;
  *param_3 = '\0';
  if (local_244[0] != 1) {
    iVar3 = 0;
    do {
      sVar1 = strlen(param_3);
      sVar2 = strlen(param_3);
      sprintf_s(param_3 + sVar2,param_4 - sVar1,"%d.",*(undefined4 *)(iVar3 + local_248));
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < local_244[0] - 1U);
  }
  sVar1 = strlen(param_3);
  sVar2 = strlen(param_3);
  sprintf_s(param_3 + sVar2,param_4 - sVar1,"%d",*(undefined4 *)(uVar4 * 4 + local_248));
  sprintf_s(param_1,param_2,"5.1.6.2014");
  local_238 = L'\0';
  memset(auStack_236,0,0x206);
  _snwprintf_s(&local_238,0x103,0x103,L"\\%s_%s_%s",L"EchoCanceller",L"2015-12-24",L"17022");
  hObject = CreateFileW(&local_238,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  FUN_10005804(local_30);
  return;
}



/* 10003de0 FUN_10003de0 */

/* Boundary evidence: original MIPS .pdata 10003de0..10003e6f. Semantic name remains unreviewed. */

void FUN_10003de0(int *param_1)

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



/* 10003e70 FUN_10003e70 */

/* Boundary evidence: original MIPS .pdata 10003e70..10003f2f. Semantic name remains unreviewed. */

undefined4 FUN_10003e70(void)

{
  int iVar1;
  WSADATA WStack_1a0;
  uint local_10;
  
  local_10 = DAT_10009150;
  iVar1 = WSAStartup(0x202,&WStack_1a0);
  if (iVar1 == 0) {
    DAT_10009140 = socket(2,1,0);
    if (DAT_10009140 != 0xffffffff) {
      FUN_10005804(local_10);
      return 1;
    }
    iVar1 = WSAGetLastError();
    NKDbgPrintfW(L"[DEBUG TOOL][ERROR] %s, error code %d\n","SocketCreate",iVar1);
  }
  FUN_10005804(local_10);
  return 0;
}



/* 10003f30 FUN_10003f30 */

/* Boundary evidence: original MIPS .pdata 10003f30..10004043. Semantic name remains unreviewed. */

undefined4 FUN_10003f30(u_short param_1)

{
  int iVar1;
  sockaddr local_28;
  uint local_18;
  
  local_18 = DAT_10009150;
  if (DAT_10009140 == 0xffffffff) {
    NKDbgPrintfW(L"[DEBUG TOOL][ERROR] %s, s_hSock is invalid value!!!\n","SocketBind");
  }
  else {
    memset(&local_28,0,0x10);
    local_28.sa_family = 2;
    local_28.sa_data._2_4_ = htonl(0);
    local_28.sa_data._0_2_ = htons(param_1);
    iVar1 = bind(DAT_10009140,&local_28,0x10);
    if (iVar1 != -1) {
      FUN_10005804(local_18);
      return 1;
    }
    iVar1 = WSAGetLastError();
    NKDbgPrintfW(L"[DEBUG TOOL][ERROR] %s, error code %d\n","SocketBind",iVar1);
  }
  FUN_10005804(local_18);
  return 0;
}



/* 10004044 FUN_10004044 */

/* Boundary evidence: original MIPS .pdata 10004044..1000410f. Semantic name remains unreviewed. */

void FUN_10004044(void)

{
  if (DAT_1000d49c != 0) {
    CloseHandle((HANDLE)DAT_1000d49c);
    DAT_1000d49c = 0;
  }
  if (DAT_1000d4a0 != 0) {
    CloseHandle((HANDLE)DAT_1000d4a0);
    DAT_1000d4a0 = 0;
  }
  if (DAT_10009144 != -1) {
    closesocket(DAT_10009144);
    DAT_10009144 = -1;
  }
  if (DAT_10009140 != -1) {
    closesocket(DAT_10009140);
    DAT_10009140 = -1;
  }
  WSACleanup();
  return;
}



/* 10004110 FUN_10004110 */

/* Boundary evidence: original MIPS .pdata 10004110..100042bb. Semantic name remains unreviewed. */

undefined4 FUN_10004110(SOCKET param_1)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  char acStack_130 [256];
  uint local_30;
  
  local_30 = DAT_10009150;
  memset(acStack_130,0,0x100);
  while( true ) {
    if ((DAT_10009144 == -1) || (*(int *)(DAT_1000d4a4 + 0x28) == 0)) goto LAB_10004280;
    _Size = recv(param_1,acStack_130,0x100,0);
    if (_Size == 0xffffffff) break;
    uVar2 = DAT_1000d48c + 1 & 0xff;
    if (9 < uVar2) {
      uVar2 = uVar2 + 0xf6 & 0xff;
    }
    if (uVar2 != DAT_1000d48d) {
      if (0xff < (int)_Size) {
        _Size = 0x100;
      }
      iVar1 = (uint)DAT_1000d48c * 0x104;
      memcpy(&DAT_1000b980 + iVar1,acStack_130,_Size);
      *(size_t *)(&DAT_1000ba80 + iVar1) = _Size;
      DAT_1000d48c = (byte)uVar2;
    }
    DAT_1000d490 = 1;
    Sleep(0);
  }
  iVar1 = WSAGetLastError();
  NKDbgPrintfW(L"[DEBUG TOOL][ERROR] WorkerThreadRx:: recv() FAIL [%d]!!!!\n",iVar1);
LAB_10004280:
  FUN_10005804(local_30);
  return 0;
}



/* 100042bc FUN_100042bc */

/* Boundary evidence: original MIPS .pdata 100042bc..1000445f. Semantic name remains unreviewed. */

undefined4 FUN_100042bc(SOCKET param_1)

{
  byte bVar1;
  int iVar2;
  
  DAT_1000d498 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,10,(LPCWSTR)0x0);
  if (DAT_1000d498 == (HANDLE)0x0) {
    NKDbgPrintfW(L"[DEBUG TOOL] WorkerThreadTx::CreateSemaphore error!\n");
  }
  while( true ) {
    if (DAT_10009144 == -1) {
      return 0;
    }
    if (*(int *)(DAT_1000d4a4 + 0x28) == 0) break;
    WaitForSingleObject(DAT_1000d498,0xffffffff);
    iVar2 = send(param_1,&DAT_10009158 + (uint)DAT_1000d48f * 0x404,
                 *(int *)(&DAT_10009558 + (uint)DAT_1000d48f * 0x404),0);
    if (iVar2 == -1) {
      iVar2 = WSAGetLastError();
      NKDbgPrintfW(L"[DEBUG TOOL][ERROR] WorkerThreadTx:: send FAIL[%d]!!!!\n",iVar2);
      bVar1 = DAT_1000d48f;
    }
    else {
      bVar1 = DAT_1000d48f + 1;
      if (9 < (byte)(DAT_1000d48f + 1)) {
        bVar1 = DAT_1000d48f - 9;
      }
    }
    DAT_1000d48f = bVar1;
    Sleep(0);
  }
  NKDbgPrintfW(L"[DEBUG TOOL] WorkerThreadTx Going Terminate!!!!!\n");
  return 0;
}



/* 10004460 EndEC */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* Boundary evidence: original MIPS .pdata 10004460..10004c6f. Semantic name remains unreviewed.
   void __cdecl EndEC(void) */

void EndEC(void)

{
  BOOL BVar1;
  DWORD DVar2;
  MMRESULT MVar3;
  wchar_t *pwVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  wchar_t *pwVar8;
  
                    /* 0x4460  1  ?EndEC@@YAXXZ */
  NKDbgPrintfW(L"[EC] [INFO] EndEC![0x%08X]\r\n",DAT_1000d4a4);
  pvVar5 = DAT_1000d4a4;
  if (DAT_1000d4a4 != (void *)0x0) {
    if (*(int *)((int)DAT_1000d4a4 + 0x18) == 1) {
      *(undefined4 *)((int)DAT_1000d4a4 + 0x18) = 0;
      iVar6 = *(int *)((int)pvVar5 + 0x1c);
      while (iVar6 == 1) {
        EventModify(*(undefined4 *)((int)pvVar5 + 0x20),3);
        Sleep(0x10);
        pvVar5 = DAT_1000d4a4;
        iVar6 = *(int *)((int)DAT_1000d4a4 + 0x1c);
      }
      iVar6 = *(int *)((int)pvVar5 + 0x28);
      while (iVar6 == 1) {
        EventModify(*(undefined4 *)((int)pvVar5 + 0x2c),3);
        Sleep(0x10);
        pvVar5 = DAT_1000d4a4;
        iVar6 = *(int *)((int)DAT_1000d4a4 + 0x28);
      }
    }
    BVar1 = TerminateThread(DAT_1000d4a0,0);
    if (BVar1 != 1) {
      DVar2 = GetLastError();
      NKDbgPrintfW(L"WorkerThreadRx::TerminateThread(hWorkerThreadTx, 0) fail  code = %0x\n",DVar2);
    }
    if (DAT_1000d498 != 0) {
      CloseHandle((HANDLE)DAT_1000d498);
      DAT_1000d498 = 0;
    }
    FUN_10004044();
    pwVar8 = L"[EC] [ERROR] MMSYSERR_INVALHANDLE\n";
    if (*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x10) != (HWAVEOUT)0x0) {
      MVar3 = waveOutPause(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x10));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveOutPause ERROR[%08X]\r\n",MVar3);
      }
      MVar3 = waveOutReset(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x10));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveOutReset ERROR[%08X]\r\n",MVar3);
      }
      iVar6 = 0;
      uVar7 = 0;
      do {
        MVar3 = waveOutUnprepareHeader
                          (*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x10),
                           (LPWAVEHDR)((int)DAT_1000d4a4 + uVar7 + 0x10cc),0x20);
        if (MVar3 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrBTOUT[%d] fail. \r\n",iVar6);
          pwVar4 = pwVar8;
          if (MVar3 != 5) {
            if (MVar3 == 6) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar3 == 7) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar3 == 0x21) {
              pwVar4 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar3 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar3);
                goto LAB_100046cc;
              }
              pwVar4 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar4);
        }
LAB_100046cc:
        uVar7 = uVar7 + 0x420;
        iVar6 = iVar6 + 1;
      } while (uVar7 < 0x1080);
      MVar3 = waveOutClose(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x10));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveOutClose ERROR[%08X]\r\n",MVar3);
      }
    }
    if (*(HWAVEIN *)((int)DAT_1000d4a4 + 8) != (HWAVEIN)0x0) {
      MVar3 = waveInStop(*(HWAVEIN *)((int)DAT_1000d4a4 + 8));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveInStop ERROR[%08X]\r\n",MVar3);
      }
      MVar3 = waveInReset(*(HWAVEIN *)((int)DAT_1000d4a4 + 8));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveInReset ERROR[%08X]\r\n",MVar3);
      }
      iVar6 = 0;
      uVar7 = 0;
      do {
        MVar3 = waveInUnprepareHeader
                          (*(HWAVEIN *)((int)DAT_1000d4a4 + 8),
                           (LPWAVEHDR)((int)DAT_1000d4a4 + uVar7 + 0x4c),0x20);
        if (MVar3 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrBTIN[%d] fail. \r\n",iVar6);
          pwVar4 = pwVar8;
          if (MVar3 != 5) {
            if (MVar3 == 6) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar3 == 7) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar3 == 0x21) {
              pwVar4 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar3 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar3);
                goto LAB_10004820;
              }
              pwVar4 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar4);
        }
LAB_10004820:
        uVar7 = uVar7 + 0x420;
        iVar6 = iVar6 + 1;
      } while (uVar7 < 0x1080);
      MVar3 = waveInClose(*(HWAVEIN *)((int)DAT_1000d4a4 + 8));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] WAVE_DEVICE_BT waveInClose ERROR[%08X]\r\n",MVar3);
      }
    }
    if (*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x14) != (HWAVEOUT)0x0) {
      MVar3 = waveOutPause(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x14));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutPause ERROR[%08X]\r\n",MVar3);
      }
      MVar3 = waveOutReset(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x14));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutReset ERROR[%08X]\r\n",MVar3);
      }
      iVar6 = 0;
      uVar7 = 0;
      do {
        MVar3 = waveOutUnprepareHeader
                          (*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x14),
                           (LPWAVEHDR)((int)DAT_1000d4a4 + uVar7 + 0x81cc),0x20);
        if (MVar3 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrHFOUT[%d] fail. \r\n",iVar6);
          pwVar4 = pwVar8;
          if (MVar3 != 5) {
            if (MVar3 == 6) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar3 == 7) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar3 == 0x21) {
              pwVar4 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar3 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar3);
                goto LAB_10004978;
              }
              pwVar4 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar4);
        }
LAB_10004978:
        uVar7 = uVar7 + 0x3020;
        iVar6 = iVar6 + 1;
      } while (uVar7 < 0xc080);
      MVar3 = waveOutClose(*(HWAVEOUT *)((int)DAT_1000d4a4 + 0x14));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveOutClose ERROR[%08X]\r\n",MVar3);
      }
    }
    if (*(HWAVEIN *)((int)DAT_1000d4a4 + 0xc) != (HWAVEIN)0x0) {
      MVar3 = waveInStop(*(HWAVEIN *)((int)DAT_1000d4a4 + 0xc));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInStop ERROR[%08X]\r\n",MVar3);
      }
      MVar3 = waveInReset(*(HWAVEIN *)((int)DAT_1000d4a4 + 0xc));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInReset ERROR[%08X]\r\n",MVar3);
      }
      iVar6 = 0;
      uVar7 = 0;
      do {
        MVar3 = waveInUnprepareHeader
                          (*(HWAVEIN *)((int)DAT_1000d4a4 + 0xc),
                           (LPWAVEHDR)((int)DAT_1000d4a4 + uVar7 + 0x214c),0x20);
        if (MVar3 != 0) {
          NKDbgPrintfW(L"[EC] [ERROR] hdrHFIN[%d] fail. \r\n",iVar6);
          pwVar4 = pwVar8;
          if (MVar3 != 5) {
            if (MVar3 == 6) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NODRIVER\n";
            }
            else if (MVar3 == 7) {
              pwVar4 = L"[EC] [ERROR] MMSYSERR_NOMEM\n";
            }
            else if (MVar3 == 0x21) {
              pwVar4 = L"[EC] [ERROR] WAVERR_STILLPLAYING\n";
            }
            else {
              if (MVar3 != 0xb) {
                NKDbgPrintfW(L"[EC] [ERROR] mr = %d\n",MVar3);
                goto LAB_10004ad0;
              }
              pwVar4 = L"[EC] [ERROR] MMSYSERR_INVALPARAM\n";
            }
          }
          NKDbgPrintfW(pwVar4);
        }
LAB_10004ad0:
        uVar7 = uVar7 + 0x1820;
        iVar6 = iVar6 + 1;
      } while (uVar7 < 0x6080);
      MVar3 = waveInClose(*(HWAVEIN *)((int)DAT_1000d4a4 + 0xc));
      if (MVar3 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] DEV_HF waveInClose ERROR[%08X]\r\n",MVar3);
      }
    }
    NKDbgPrintfW(L"[EC] [INFO] Device Close!\r\n");
    if (DAT_1000d460 != (void *)0x0) {
      free(DAT_1000d460);
      DAT_1000d460 = (void *)0x0;
    }
    if (DAT_1000d458 != 0) {
      iVar6 = sseDestroy(&DAT_1000d458);
      if (iVar6 != 0) {
        NKDbgPrintfW(L"[EC] [ERROR] ERROR in sseDestroy()\n");
      }
      DAT_1000d458 = 0;
    }
    if (DAT_1000d45c != 0) {
      FUN_10003de0(&DAT_1000d45c);
      DAT_1000d45c = 0;
    }
    pvVar5 = DAT_1000d4a4;
    if (*(HANDLE *)((int)DAT_1000d4a4 + 0x2c) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)DAT_1000d4a4 + 0x2c));
      pvVar5 = DAT_1000d4a4;
      *(undefined4 *)((int)DAT_1000d4a4 + 0x2c) = 0;
    }
    if (*(HANDLE *)((int)pvVar5 + 0x20) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)pvVar5 + 0x20));
      pvVar5 = DAT_1000d4a4;
      *(undefined4 *)((int)DAT_1000d4a4 + 0x20) = 0;
    }
    if (*(HANDLE *)((int)pvVar5 + 0x44) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)pvVar5 + 0x44));
      pvVar5 = DAT_1000d4a4;
      *(undefined4 *)((int)DAT_1000d4a4 + 0x44) = 0;
    }
    if (*(HANDLE *)((int)pvVar5 + 0x38) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)((int)pvVar5 + 0x38));
      pvVar5 = DAT_1000d4a4;
      *(undefined4 *)((int)DAT_1000d4a4 + 0x38) = 0;
    }
    free(pvVar5);
    DAT_1000d4a4 = (void *)0x0;
  }
  return;
}



/* 10004c70 FUN_10004c70 */

/* Boundary evidence: original MIPS .pdata 10004c70..10004dff. Semantic name remains unreviewed. */

void FUN_10004c70(char *param_1,int *param_2)

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
LAB_10004da0:
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
                printf("[EC] [INFO] Config data has been loaded from file ==> %s.\n",param_1);
                goto LAB_10004dd0;
              }
              goto LAB_10004da0;
            }
          }
          pwVar4 = L"[EC] [ERROR] Memory allocation for config data failed. Continuing without...\n"
          ;
        }
      }
    }
  }
  NKDbgPrintfW(pwVar4);
  FUN_10003de0(param_2);
LAB_10004dd0:
  if (local_20[0] != (FILE *)0x0) {
    fclose(local_20[0]);
  }
  return;
}



/* 10004e00 FUN_10004e00 */

/* Boundary evidence: original MIPS .pdata 10004e00..10004fdf. Semantic name remains unreviewed. */

void FUN_10004e00(void)

{
  int iVar1;
  LPVOID lpParameter;
  wchar_t *pwVar2;
  int local_40 [2];
  sockaddr sStack_38;
  uint local_28;
  
  local_28 = DAT_10009150;
  iVar1 = listen(DAT_10009140,5);
  if (iVar1 == -1) {
    iVar1 = WSAGetLastError();
    pwVar2 = L"[DEBUG TOOL][ERROR] %s Listen error!!!!!!!!! \n";
  }
  else {
    local_40[0] = 0x10;
    lpParameter = (LPVOID)accept(DAT_10009140,&sStack_38,local_40);
    DAT_10009144 = lpParameter;
    if (lpParameter != (LPVOID)0xffffffff) {
      memset(&DAT_1000b980,0,0xa28);
      memset(&DAT_10009158,0,0x2828);
      DAT_1000d49c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10004110,lpParameter,4,
                                  (LPDWORD)0x0);
      if (DAT_1000d49c != (HANDLE)0x0) {
        CeSetThreadPriority(DAT_1000d49c,0x66);
        CeSetThreadQuantum(DAT_1000d49c,2);
        ResumeThread(DAT_1000d49c);
      }
      DAT_1000d4a0 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_100042bc,DAT_10009144,4,
                                  (LPDWORD)0x0);
      if (DAT_1000d4a0 != (HANDLE)0x0) {
        CeSetThreadPriority(DAT_1000d4a0,0x66);
        CeSetThreadQuantum(DAT_1000d4a0,2);
        ResumeThread(DAT_1000d4a0);
      }
      goto LAB_10004fb4;
    }
    iVar1 = WSAGetLastError();
    pwVar2 = L"[DEBUG TOOL][ERROR] %s, error code %d\n";
  }
  NKDbgPrintfW(pwVar2,"SocketListen_Accept",iVar1);
LAB_10004fb4:
  FUN_10005804(local_28);
  return;
}



/* 10004fe0 FUN_10004fe0 */

/* Boundary evidence: original MIPS .pdata 10004fe0..10004fff. Semantic name remains unreviewed. */

undefined4 FUN_10004fe0(void)

{
  FUN_10004e00();
  return 0;
}



/* 10005000 FUN_10005000 */

/* Boundary evidence: original MIPS .pdata 10005000..100052c3. Semantic name remains unreviewed. */

void FUN_10005000(int param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined2 local_100 [2];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 auStack_ec [4];
  undefined1 auStack_e8 [200];
  uint local_20;
  
  local_20 = DAT_10009150;
  local_100[0] = (undefined2)param_2;
  local_f4 = 0;
  local_f8 = 0;
  local_f0 = 0;
  if (1 < param_1) {
    param_1 = 0;
  }
  pcVar1 = (&PTR_s__Storage_Card_system_EC_config_b_10009148)[param_1];
  printf("[EC] [%s] nSiriOn %d, config_name[%s], CHANNEL_CNT[%d][%d]\r\n","PrepareProcessingSSE",
         param_1,pcVar1,param_2,param_2);
  DAT_1000d460 = malloc(0x18);
  if (DAT_1000d460 != (void *)0x0) {
    memset(DAT_1000d460,0,0x18);
  }
  FUN_10004c70(pcVar1,&DAT_1000d45c);
  sseGetVersion(auStack_ec,&local_f4,&local_f8,&local_f0);
  DAT_1000d468 = sseCreate(&DAT_1000d458,0,0);
  if (DAT_1000d468 != 0) goto LAB_100052a0;
  local_fc = 2;
  DAT_1000d468 = sseSetData(DAT_1000d458,3,0,2,local_100);
  if (DAT_1000d468 == 0) {
    DAT_1000d468 = sseSetData(DAT_1000d458,0x1f,0,2,&DAT_10006088);
    if (DAT_1000d468 != 0) goto LAB_10005160;
    DAT_1000d468 = sseSetData(DAT_1000d458,0x1e,0,2,&DAT_10006084);
    if (DAT_1000d468 != 0) goto LAB_10005160;
LAB_1000518c:
    DAT_1000d468 = sseSetData(DAT_1000d458,9,0,4,&local_fc);
    if (DAT_1000d468 != 0) goto LAB_10005240;
    DAT_1000d468 = sseSetData(DAT_1000d458,10,0,4,&local_fc);
    if (DAT_1000d468 != 0) goto LAB_10005240;
    DAT_1000d468 = sseSetData(DAT_1000d458,0xc,0,4,&local_fc);
    if (DAT_1000d468 != 0) goto LAB_10005240;
    DAT_1000d468 = sseSetData(DAT_1000d458,4,0,2,local_100);
    if (DAT_1000d468 != 0) goto LAB_10005240;
    DAT_1000d468 = sseSetData(DAT_1000d458,0x27,0,4,&local_fc);
    if (DAT_1000d468 != 0) goto LAB_10005240;
  }
  else {
LAB_10005160:
    sseGetErrorMessage(DAT_1000d458,auStack_e8);
    NKDbgPrintfW(L"[EC] [ERROR] _FIRST__sseSetData failed with error number 0X0%X and error message\n %s\n"
                 ,DAT_1000d468,auStack_e8);
    if (DAT_1000d468 == 0) goto LAB_1000518c;
LAB_10005240:
    sseGetErrorMessage(DAT_1000d458,auStack_e8);
    NKDbgPrintfW(L"[EC] [ERROR] Set data failed with error number 0x%4x and error message\n \"%s\"\n"
                 ,DAT_1000d468,auStack_e8);
    if (DAT_1000d468 != 0) goto LAB_100052a0;
  }
  DAT_1000d468 = sseInitialize(DAT_1000d458,DAT_1000d45c);
  if (DAT_1000d468 != 0) {
    sseGetErrorMessage(DAT_1000d458,auStack_e8);
    NKDbgPrintfW(L"[EC] [ERROR] sseInitialize failed with error number 0X0%X and error message\n %s\n"
                 ,DAT_1000d468,auStack_e8);
  }
LAB_100052a0:
  FUN_10005804(local_20);
  return;
}



/* 100052c4 FUN_100052c4 */

/* Boundary evidence: original MIPS .pdata 100052c4..1000531f. Semantic name remains unreviewed. */

undefined4 FUN_100052c4(void)

{
  HANDLE hObject;
  DWORD aDStack_10 [2];
  
  FUN_10003e70();
  FUN_10003f30(0x7dc);
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10004fe0,(LPVOID)0x0,0,aDStack_10);
  CloseHandle(hObject);
  return 1;
}



/* 10005320 StartEC */

/* Boundary evidence: original MIPS .pdata 10005320..100055bf. Semantic name remains unreviewed.
   void __cdecl StartEC(int,unsigned int) */

void StartEC(int param_1,uint param_2)

{
  void *pvVar1;
  HANDLE pvVar2;
  int iVar3;
  wchar_t *pwVar4;
  
                    /* 0x5320  7  ?StartEC@@YAXHI@Z */
  Sleep(100);
  NKDbgPrintfW(L"[EC] [INFO] StartEC! SiriOn[%d][%d]\r\n",param_1,0x14a54);
  if (DAT_1000d4a4 == (void *)0x0) {
    DAT_1000d4a4 = malloc(0x14a54);
    memset(DAT_1000d4a4,0,0x14a54);
    DAT_1000c404 = 0;
    DAT_1000c400 = 0;
    DAT_1000c3fc = 0;
    DAT_1000c3f8 = 0;
    FUN_10005000(param_1,(int)(short)param_2);
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)DAT_1000d4a4 + 0x2c) = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)DAT_1000d4a4 + 0x20) = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)DAT_1000d4a4 + 0x44) = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)DAT_1000d4a4 + 0x38) = pvVar2;
    iVar3 = FUN_100032c4();
    if (iVar3 != 0) {
      FUN_100034b8();
      FUN_100035bc();
      Sleep(0x80);
      pvVar1 = DAT_1000d4a4;
      *(undefined4 *)((int)DAT_1000d4a4 + 0x28) = 0;
      *(undefined4 *)((int)pvVar1 + 0x1c) = 0;
      *(undefined4 *)((int)pvVar1 + 0x40) = 0;
      *(undefined4 *)((int)pvVar1 + 0x34) = 0;
      *(undefined4 *)((int)pvVar1 + 0x18) = 1;
      pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10002874,(LPVOID)0x0,4,(LPDWORD)0x0);
      if (pvVar2 != (HANDLE)0x0) {
        CeSetThreadPriority(pvVar2,0x66);
        CeSetThreadQuantum(pvVar2,2);
        ResumeThread(pvVar2);
        CloseHandle(pvVar2);
      }
      pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_10001000,(LPVOID)0x0,4,(LPDWORD)0x0);
      if (pvVar2 != (HANDLE)0x0) {
        CeSetThreadPriority(pvVar2,0x66);
        CeSetThreadQuantum(pvVar2,2);
        ResumeThread(pvVar2);
        CloseHandle(pvVar2);
      }
      FUN_100052c4();
      return;
    }
    pwVar4 = L"[EC] [ERROR] Device Open Error!\r\n";
  }
  else {
    pwVar4 = L"[EC] [ERROR] g_pEC already allocated !!!!\r\n";
  }
  NKDbgPrintfW(pwVar4);
  return;
}



/* 10005700 FUN_10005700 */

/* Boundary evidence: original MIPS .pdata 10005700..10005773. Semantic name remains unreviewed. */

void FUN_10005700(void)

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



/* 10005774 FUN_10005774 */

/* Boundary evidence: original MIPS .pdata 10005774..100057c7. Semantic name remains unreviewed. */

void FUN_10005774(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_10005804(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 100057c8 FUN_100057c8 */

/* Boundary evidence: original MIPS .pdata 100057c8..100057f3. Semantic name remains unreviewed. */

undefined4 FUN_100057c8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_10005774(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 10005804 FUN_10005804 */

/* Boundary evidence: original MIPS .pdata 10005804..1000584b. Semantic name remains unreviewed. */

void FUN_10005804(uint param_1)

{
  if ((param_1 == DAT_10009150) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 1000590c FUN_1000590c */

/* Boundary evidence: original MIPS .pdata 1000590c..10005a47. Semantic name remains unreviewed. */

int FUN_1000590c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_1000d4b8 != (code *)0x0) {
      iVar2 = (*DAT_1000d4b8)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_100059bc;
    FUN_10005cc0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_10005c40(param_1,param_2);
  }
LAB_100059bc:
  if (((param_2 == 0) && (FUN_10005c1c(), iVar1 != 0)) && (DAT_1000d4b8 != (code *)0x0)) {
    iVar1 = (*DAT_1000d4b8)(param_1,0,param_3);
  }
  return iVar1;
}



/* 10005a48 FUN_10005a48 */

/* Boundary evidence: original MIPS .pdata 10005a48..10005a73. Semantic name remains unreviewed. */

void FUN_10005a48(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 10005a74 entry */

/* Boundary evidence: original MIPS .pdata 10005a74..10005acb. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_10005700();
  }
  FUN_1000590c(param_1,param_2,param_3);
  return;
}



/* 10005afc FUN_10005afc */

/* Boundary evidence: original MIPS .pdata 10005afc..10005c1b. Semantic name remains unreviewed. */

void FUN_10005afc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_1000d4a8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_1000d4b0;
    if (DAT_1000d4b0 != (undefined4 *)0x0) {
      while (DAT_1000d4ac = DAT_1000d4ac + -1, _Memory <= DAT_1000d4ac) {
        if ((code *)*DAT_1000d4ac != (code *)0x0) {
          (*(code *)*DAT_1000d4ac)();
          _Memory = DAT_1000d4b0;
        }
      }
      free(_Memory);
      DAT_1000d4ac = (undefined4 *)0x0;
      DAT_1000d4b0 = (undefined4 *)0x0;
    }
    FUN_10005c6c((undefined4 *)&DAT_10006010,(undefined4 *)&DAT_10006014);
  }
  FUN_10005c6c((undefined4 *)&DAT_10006018,(undefined4 *)&DAT_1000601c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_1000d4b4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 10005c1c FUN_10005c1c */

/* Boundary evidence: original MIPS .pdata 10005c1c..10005c3f. Semantic name remains unreviewed. */

void FUN_10005c1c(void)

{
  FUN_10005afc(0,0,1);
  return;
}



/* 10005c40 FUN_10005c40 */

/* Boundary evidence: original MIPS .pdata 10005c40..10005c6b. Semantic name remains unreviewed. */

undefined4 FUN_10005c40(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 10005c6c FUN_10005c6c */

/* Boundary evidence: original MIPS .pdata 10005c6c..10005cbf. Semantic name remains unreviewed. */

void FUN_10005c6c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 10005cc0 FUN_10005cc0 */

/* Boundary evidence: original MIPS .pdata 10005cc0..10005cfb. Semantic name remains unreviewed. */

void FUN_10005cc0(void)

{
  FUN_10005c6c((undefined4 *)&DAT_10006008,(undefined4 *)&DAT_1000600c);
  FUN_10005c6c((undefined4 *)&DAT_10006000,(undefined4 *)&DAT_10006004);
  return;
}


