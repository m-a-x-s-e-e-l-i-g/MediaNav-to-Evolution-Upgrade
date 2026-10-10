/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40a81000 FUN_40a81000 */

/* Boundary evidence: original MIPS .pdata 40a81000..40a82a27. Semantic name remains unreviewed. */

void FUN_40a81000(int *param_1,int *param_2)

{
  longlong lVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  piVar2 = param_2;
  do {
    iVar4 = iVar4 + 1;
    *piVar2 = *piVar2 << 4;
    piVar2 = piVar2 + 1;
  } while (iVar4 != 0x20);
  iVar4 = *param_2;
  *param_2 = param_2[0x1f] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1f]) * 0x4013c2;
  iVar4 = param_2[1];
  param_2[0x1f] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[1] = param_2[0x1e] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1e]) * 0x40b345;
  iVar4 = param_2[2];
  param_2[0x1e] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[2] = param_2[0x1d] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1d]) * 0x41fa2d;
  iVar4 = param_2[3];
  param_2[0x1d] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[3] = param_2[0x1c] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1c]) * 0x43f934;
  iVar4 = param_2[4];
  param_2[0x1c] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[4] = param_2[0x1b] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1b]) * 0x46cc1b;
  iVar4 = param_2[5];
  param_2[0x1b] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[5] = param_2[0x1a] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1a]) * 0x4a9d9c;
  iVar4 = param_2[6];
  param_2[0x1a] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[6] = param_2[0x19] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x19]) * 0x4fae37;
  iVar4 = param_2[7];
  param_2[0x19] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[7] = param_2[0x18] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x18]) * 0x56601e;
  iVar4 = param_2[8];
  param_2[0x18] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[8] = param_2[0x17] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x17]) * 0x5f4cf6;
  iVar4 = param_2[9];
  param_2[0x17] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[9] = param_2[0x16] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x16]) * 0x6b6fcf;
  iVar4 = param_2[10];
  param_2[0x16] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[10] = param_2[0x15] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x15]) * 0x7c7d1d;
  iVar4 = param_2[0xb];
  param_2[0x15] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xb] = param_2[0x14] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x14]) * 0x95b035;
  iVar4 = param_2[0xc];
  param_2[0x14] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xc] = param_2[0x13] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x13]) * 0xbdf91b;
  iVar4 = param_2[0xd];
  param_2[0x13] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xd] = param_2[0x12] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x12]) * 0x107655e;
  iVar4 = param_2[0xe];
  param_2[0x12] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xe] = param_2[0x11] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x11]) * 0x1b42c83;
  iVar4 = param_2[0xf];
  param_2[0x11] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xf] = param_2[0x10] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x10]) * 0x518522f;
  iVar4 = *param_2;
  param_2[0x10] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  *param_2 = param_2[0xf] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xf]) * 0x404f46;
  iVar4 = param_2[1];
  param_2[0xf] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[1] = param_2[0xe] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xe]) * 0x42e13c;
  iVar4 = param_2[2];
  param_2[0xe] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[2] = param_2[0xd] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xd]) * 0x48919f;
  iVar4 = param_2[3];
  param_2[0xd] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[3] = param_2[0xc] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xc]) * 0x52cb0e;
  iVar4 = param_2[4];
  param_2[0xc] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[4] = param_2[0xb] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xb]) * 0x64e240;
  iVar4 = param_2[5];
  param_2[0xb] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[5] = param_2[10] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[10]) * 0x87c449;
  iVar4 = param_2[6];
  param_2[10] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[6] = param_2[9] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[9]) * 0xdc7925;
  iVar4 = param_2[7];
  param_2[9] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[7] = param_2[8] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[8]) * 0x28cf270;
  iVar4 = param_2[0x10];
  param_2[8] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x10] = param_2[0x1f] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1f]) * -0x404f46;
  iVar4 = param_2[0x11];
  param_2[0x1f] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x11] = param_2[0x1e] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1e]) * -0x42e13c;
  iVar4 = param_2[0x12];
  param_2[0x1e] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x12] = param_2[0x1d] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1d]) * -0x48919f;
  iVar4 = param_2[0x13];
  param_2[0x1d] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x13] = param_2[0x1c] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1c]) * -0x52cb0e;
  iVar4 = param_2[0x14];
  param_2[0x1c] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x14] = param_2[0x1b] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1b]) * -0x64e240;
  iVar4 = param_2[0x15];
  param_2[0x1b] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x15] = param_2[0x1a] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1a]) * -0x87c449;
  iVar4 = param_2[0x16];
  param_2[0x1a] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x16] = param_2[0x19] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x19]) * -0xdc7925;
  iVar4 = param_2[0x17];
  param_2[0x19] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x17] = param_2[0x18] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x18]) * -0x28cf270;
  iVar4 = *param_2;
  param_2[0x18] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  *param_2 = param_2[7] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[7]) * 0x4140fb;
  iVar4 = param_2[1];
  param_2[7] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[1] = param_2[6] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[6]) * 0x4cf8de;
  iVar4 = param_2[2];
  param_2[6] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[2] = param_2[5] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[5]) * 0x73326b;
  iVar4 = param_2[3];
  param_2[5] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[3] = param_2[4] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[4]) * 0x1480d9d;
  iVar4 = param_2[8];
  param_2[4] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[8] = param_2[0xf] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xf]) * -0x4140fb;
  iVar4 = param_2[9];
  param_2[0xf] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[9] = param_2[0xe] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xe]) * -0x4cf8de;
  iVar4 = param_2[10];
  param_2[0xe] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[10] = param_2[0xd] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xd]) * -0x73326b;
  iVar4 = param_2[0xb];
  param_2[0xd] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xb] = param_2[0xc] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xc]) * -0x1480d9d;
  iVar4 = param_2[0x10];
  param_2[0xc] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x10] = param_2[0x17] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x17]) * 0x4140fb;
  iVar4 = param_2[0x11];
  param_2[0x17] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x11] = param_2[0x16] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x16]) * 0x4cf8de;
  iVar4 = param_2[0x12];
  param_2[0x16] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x12] = param_2[0x15] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x15]) * 0x73326b;
  iVar4 = param_2[0x13];
  param_2[0x15] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x13] = param_2[0x14] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x14]) * 0x1480d9d;
  iVar4 = param_2[0x18];
  param_2[0x14] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x18] = param_2[0x1f] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1f]) * -0x4140fb;
  iVar4 = param_2[0x19];
  param_2[0x1f] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x19] = param_2[0x1e] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1e]) * -0x4cf8de;
  iVar4 = param_2[0x1a];
  param_2[0x1e] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1a] = param_2[0x1d] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1d]) * -0x73326b;
  iVar4 = param_2[0x1b];
  param_2[0x1d] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1b] = param_2[0x1c] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1c]) * -0x1480d9d;
  iVar4 = *param_2;
  param_2[0x1c] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  *param_2 = param_2[3] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[3]) * 0x4545e9;
  iVar4 = param_2[1];
  param_2[3] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[1] = param_2[2] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[2]) * 0xa73d74;
  iVar4 = param_2[4];
  param_2[2] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[4] = param_2[7] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[7]) * -0x4545e9;
  iVar4 = param_2[5];
  param_2[7] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[5] = param_2[6] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[6]) * -0xa73d74;
  iVar4 = param_2[8];
  param_2[6] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[8] = param_2[0xb] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xb]) * 0x4545e9;
  iVar4 = param_2[9];
  param_2[0xb] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[9] = param_2[10] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[10]) * 0xa73d74;
  iVar4 = param_2[0xc];
  param_2[10] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xc] = param_2[0xf] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xf]) * -0x4545e9;
  iVar4 = param_2[0xd];
  param_2[0xf] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xd] = param_2[0xe] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xe]) * -0xa73d74;
  iVar4 = param_2[0x10];
  param_2[0xe] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x10] = param_2[0x13] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x13]) * 0x4545e9;
  iVar4 = param_2[0x11];
  param_2[0x13] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x11] = param_2[0x12] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x12]) * 0xa73d74;
  iVar4 = param_2[0x14];
  param_2[0x12] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x14] = param_2[0x17] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x17]) * -0x4545e9;
  iVar4 = param_2[0x15];
  param_2[0x17] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x15] = param_2[0x16] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x16]) * -0xa73d74;
  iVar4 = param_2[0x18];
  param_2[0x16] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x18] = param_2[0x1b] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1b]) * 0x4545e9;
  iVar4 = param_2[0x19];
  param_2[0x1b] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x19] = param_2[0x1a] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1a]) * 0xa73d74;
  iVar4 = param_2[0x1c];
  param_2[0x1a] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1c] = param_2[0x1f] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1f]) * -0x4545e9;
  iVar4 = param_2[0x1d];
  param_2[0x1f] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1d] = param_2[0x1e] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1e]) * -0xa73d74;
  iVar4 = *param_2;
  param_2[0x1e] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  *param_2 = param_2[1] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[1]) * 0x5a8279;
  iVar4 = param_2[2];
  param_2[1] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[2] = param_2[3] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[3]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  iVar4 = param_2[4];
  param_2[2] = param_2[2] + uVar3;
  param_2[4] = param_2[5] + iVar4;
  param_2[3] = uVar3;
  lVar1 = (longlong)(iVar4 - param_2[5]) * 0x5a8279;
  iVar4 = param_2[6];
  param_2[5] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[6] = param_2[7] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[7]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[7] = uVar3;
  iVar5 = param_2[8];
  iVar4 = uVar3 + param_2[6];
  param_2[4] = param_2[4] + iVar4;
  param_2[6] = iVar4 + param_2[5];
  param_2[5] = param_2[5] + param_2[7];
  param_2[8] = param_2[9] + iVar5;
  lVar1 = (longlong)(iVar5 - param_2[9]) * 0x5a8279;
  iVar4 = param_2[10];
  param_2[9] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[10] = param_2[0xb] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xb]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  iVar4 = param_2[0xc];
  param_2[10] = param_2[10] + uVar3;
  param_2[0xc] = param_2[0xd] + iVar4;
  param_2[0xb] = uVar3;
  lVar1 = (longlong)(iVar4 - param_2[0xd]) * 0x5a8279;
  iVar4 = param_2[0xe];
  param_2[0xd] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xe] = param_2[0xf] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0xf]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0xf] = uVar3;
  iVar5 = param_2[0x10];
  iVar4 = uVar3 + param_2[0xe];
  param_2[0xc] = param_2[0xc] + iVar4;
  param_2[0xe] = iVar4 + param_2[0xd];
  param_2[0xd] = param_2[0xd] + param_2[0xf];
  param_2[0x10] = param_2[0x11] + iVar5;
  lVar1 = (longlong)(iVar5 - param_2[0x11]) * 0x5a8279;
  iVar4 = param_2[0x12];
  param_2[0x11] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x12] = param_2[0x13] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x13]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  iVar4 = param_2[0x14];
  param_2[0x12] = param_2[0x12] + uVar3;
  param_2[0x14] = param_2[0x15] + iVar4;
  param_2[0x13] = uVar3;
  lVar1 = (longlong)(iVar4 - param_2[0x15]) * 0x5a8279;
  iVar4 = param_2[0x16];
  param_2[0x15] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x16] = param_2[0x17] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x17]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x17] = uVar3;
  iVar5 = param_2[0x18];
  iVar4 = uVar3 + param_2[0x16];
  param_2[0x14] = param_2[0x14] + iVar4;
  param_2[0x16] = iVar4 + param_2[0x15];
  param_2[0x15] = param_2[0x15] + param_2[0x17];
  param_2[0x18] = param_2[0x19] + iVar5;
  lVar1 = (longlong)(iVar5 - param_2[0x19]) * 0x5a8279;
  iVar4 = param_2[0x1a];
  param_2[0x19] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1a] = param_2[0x1b] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1b]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  iVar4 = param_2[0x1c];
  param_2[0x1a] = param_2[0x1a] + uVar3;
  param_2[0x1c] = param_2[0x1d] + iVar4;
  param_2[0x1b] = uVar3;
  lVar1 = (longlong)(iVar4 - param_2[0x1d]) * 0x5a8279;
  iVar4 = param_2[0x1e];
  param_2[0x1d] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1e] = param_2[0x1f] + iVar4;
  lVar1 = (longlong)(iVar4 - param_2[0x1f]) * -0x5a8279;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_2[0x1f] = uVar3;
  iVar4 = uVar3 + param_2[0x1e];
  param_2[0x1c] = param_2[0x1c] + iVar4;
  param_2[0x1e] = iVar4 + param_2[0x1d];
  param_2[0x1d] = param_2[0x1d] + param_2[0x1f];
  param_2[8] = param_2[8] + param_2[0xc];
  param_2[0xc] = param_2[0xc] + param_2[10];
  param_2[10] = param_2[10] + param_2[0xe];
  param_2[0xe] = param_2[0xe] + param_2[9];
  param_2[9] = param_2[9] + param_2[0xd];
  param_2[0xd] = param_2[0xd] + param_2[0xb];
  param_2[0xb] = param_2[0xb] + param_2[0xf];
  *param_1 = *param_2;
  param_1[0x10] = param_2[1];
  iVar5 = 0;
  param_1[8] = param_2[2];
  param_1[0x18] = param_2[3];
  param_1[4] = param_2[4];
  param_1[0x14] = param_2[5];
  param_1[0xc] = param_2[6];
  param_1[0x1c] = param_2[7];
  param_1[2] = param_2[8];
  param_1[0x12] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0x1a] = param_2[0xb];
  param_1[6] = param_2[0xc];
  param_1[0x16] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  param_1[0x1e] = param_2[0xf];
  param_2[0x18] = param_2[0x18] + param_2[0x1c];
  iVar4 = param_2[0x1b];
  param_2[0x1c] = param_2[0x1c] + param_2[0x1a];
  param_2[0x1a] = param_2[0x1a] + param_2[0x1e];
  param_2[0x1e] = param_2[0x1e] + param_2[0x19];
  param_2[0x19] = param_2[0x19] + param_2[0x1d];
  param_2[0x1b] = iVar4 + param_2[0x1f];
  param_2[0x1d] = param_2[0x1d] + iVar4;
  param_1[1] = param_2[0x18] + param_2[0x10];
  param_1[0x11] = param_2[0x19] + param_2[0x11];
  param_1[9] = param_2[0x1a] + param_2[0x12];
  param_1[0x19] = param_2[0x1b] + param_2[0x13];
  param_1[5] = param_2[0x1c] + param_2[0x14];
  param_1[0x15] = param_2[0x1d] + param_2[0x15];
  param_1[0xd] = param_2[0x1e] + param_2[0x16];
  param_1[0x1d] = param_2[0x1f] + param_2[0x17];
  param_1[3] = param_2[0x14] + param_2[0x18];
  param_1[0x13] = param_2[0x15] + param_2[0x19];
  param_1[0xb] = param_2[0x16] + param_2[0x1a];
  param_1[0x1b] = param_2[0x17] + param_2[0x1b];
  param_1[7] = param_2[0x12] + param_2[0x1c];
  param_1[0x17] = param_2[0x13] + param_2[0x1d];
  param_1[0xf] = param_2[0x11] + param_2[0x1e];
  param_1[0x1f] = param_2[0x1f];
  do {
    iVar5 = iVar5 + 1;
    *param_1 = *param_1 >> 4;
    param_1 = param_1 + 1;
  } while (iVar5 != 0x20);
  return;
}



/* 40a82a28 FUN_40a82a28 */

/* Boundary evidence: original MIPS .pdata 40a82a28..40a82dcb. Semantic name remains unreviewed. */

void FUN_40a82a28(uint *param_1,int *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *param_2;
  param_2[6] = param_2[6] << 4;
  *param_2 = iVar3 << 4;
  param_2[1] = param_2[1] << 4;
  param_2[2] = param_2[2] << 4;
  param_2[3] = param_2[3] << 4;
  param_2[4] = param_2[4] << 4;
  param_2[5] = param_2[5] << 4;
  param_2[7] = param_2[7] << 4;
  param_2[8] = param_2[8] << 4;
  param_2[9] = param_2[9] << 4;
  param_2[10] = param_2[10] << 4;
  param_2[0xb] = param_2[0xb] << 4;
  uVar2 = (longlong)(iVar3 << 4) * 0x4debe4;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[1] * -0x7641af;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[2] * -0x10b515;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[3] * 0x7ee7aa;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * -0x30fbc5;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[5] * -0x658c9a;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_1[5] = -uVar4;
  *param_1 = uVar4;
  uVar2 = (longlong)(*param_2 - param_2[3]) * 0x30fbc5;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[1] * -0x7641af;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) +
          (longlong)(param_2[5] + param_2[2]) * 0x7641af;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * -0x30fbc5;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_1[4] = -uVar4;
  param_1[1] = uVar4;
  uVar2 = ((longlong)*param_2 * 0x10b515 & 0xffffffff00000000U) +
          ((longlong)*param_2 * 0x10b515 & 0xffffffffU) + (longlong)param_2[1] * -0x30fbc5;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[2] * 0x4debe4;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[3] * -0x658c9a;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * 0x7641af;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[5] * -0x7ee7aa;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_1[3] = -uVar4;
  param_1[2] = uVar4;
  uVar2 = ((longlong)*param_2 * -0x658c9a & 0xffffffff00000000U) +
          ((longlong)*param_2 * -0x658c9a & 0xffffffffU) + (longlong)param_2[1] * 0x30fbc5;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[2] * 0x7ee7aa;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[3] * 0x10b515;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * -0x7641af;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[5] * -0x4debe4;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_1[0xb] = uVar4;
  param_1[6] = uVar4;
  uVar2 = (longlong)(param_2[3] - *param_2) * 0x7641af;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[1] * -0x30fbc5;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) +
          (longlong)(param_2[5] + param_2[2]) * 0x30fbc5;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * 0x7641af;
  uVar4 = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  param_1[10] = uVar4;
  param_1[7] = uVar4;
  uVar2 = ((longlong)*param_2 * -0x7ee7aa & 0xffffffff00000000U) +
          ((longlong)*param_2 * -0x7ee7aa & 0xffffffffU) + (longlong)param_2[1] * -0x7641af;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[2] * -0x658c9a;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[3] * -0x4debe4;
  uVar2 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[4] * -0x30fbc5;
  lVar1 = (uVar2 & 0xffffffff00000000) + (uVar2 & 0xffffffff) + (longlong)param_2[5] * -0x10b515;
  param_1[8] = (int)((ulonglong)lVar1 >> 0x20) << 9 | (uint)lVar1 >> 0x17;
  uVar4 = param_1[8];
  param_1[0xb] = (int)param_1[0xb] >> 4;
  *param_1 = (int)*param_1 >> 4;
  param_1[1] = (int)param_1[1] >> 4;
  param_1[2] = (int)param_1[2] >> 4;
  param_1[3] = (int)param_1[3] >> 4;
  param_1[4] = (int)param_1[4] >> 4;
  param_1[5] = (int)param_1[5] >> 4;
  param_1[6] = (int)param_1[6] >> 4;
  param_1[7] = (int)param_1[7] >> 4;
  param_1[8] = (int)uVar4 >> 4;
  param_1[9] = (int)uVar4 >> 4;
  param_1[10] = (int)param_1[10] >> 4;
  return;
}



/* 40a82dcc FUN_40a82dcc */

/* Boundary evidence: original MIPS .pdata 40a82dcc..40a83b8f. Semantic name remains unreviewed. */

void FUN_40a82dcc(uint *param_1,int *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  
  iVar12 = 0;
  piVar3 = param_2;
  do {
    iVar12 = iVar12 + 1;
    *piVar3 = *piVar3 << 4;
    piVar3 = piVar3 + 1;
  } while (iVar12 != 0x12);
  iVar12 = param_2[0x10];
  iVar13 = param_2[0xf] + param_2[0xe];
  iVar17 = param_2[0xd] + param_2[0xc];
  iVar20 = param_2[0xb] + param_2[10];
  iVar23 = param_2[9] + param_2[8];
  iVar24 = param_2[7] + param_2[6];
  iVar25 = param_2[5] + param_2[4];
  iVar26 = param_2[3] + param_2[2];
  iVar27 = *param_2 + param_2[1];
  param_2[0x10] = iVar12 + param_2[0xf];
  param_2[0xe] = param_2[0xe] + param_2[0xd];
  param_2[0xc] = param_2[0xc] + param_2[0xb];
  param_2[8] = param_2[8] + param_2[7];
  param_2[6] = param_2[6] + param_2[5];
  param_2[4] = param_2[4] + param_2[3];
  param_2[10] = param_2[10] + param_2[9];
  param_2[2] = param_2[2] + param_2[1];
  param_2[1] = iVar27;
  param_2[0x11] = param_2[0x11] + iVar12 + iVar13;
  param_2[0xb] = iVar20 + iVar23;
  param_2[5] = iVar25 + iVar26;
  param_2[3] = iVar27 + iVar26;
  param_2[0xf] = iVar13 + iVar17;
  param_2[0xd] = iVar17 + iVar20;
  param_2[9] = iVar23 + iVar24;
  param_2[7] = iVar24 + iVar25;
  uVar1 = ((longlong)param_2[2] * 0x7e0e2e & 0xffffffff00000000U) +
          ((longlong)param_2[2] * 0x7e0e2e & 0xffffffffU) + (longlong)param_2[6] * 0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[10] * 0x5246dd;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xe] * 0x2bc750;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[4] * 0x7847d9 & 0xffffffff00000000U) +
          ((longlong)param_2[4] * 0x7847d9 & 0xffffffffU) + (longlong)param_2[8] * 0x620dbe;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xc] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x10] * 0x163a1a;
  iVar17 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + *param_2;
  lVar2 = (longlong)((param_2[2] - param_2[10]) - param_2[0xe]) * 0x6ed9eb;
  uVar14 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)((param_2[4] - param_2[8]) - param_2[0x10]) * 0x400000;
  iVar20 = (*param_2 + ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17)) - param_2[0xc];
  uVar1 = ((longlong)param_2[2] * 0x5246dd & 0xffffffff00000000U) +
          ((longlong)param_2[2] * 0x5246dd & 0xffffffffU) + (longlong)param_2[6] * -0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[10] * -0x2bc750;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xe] * 0x7e0e2e;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[4] * -0x163a1a & 0xffffffff00000000U) +
          ((longlong)param_2[4] * -0x163a1a & 0xffffffffU) + (longlong)param_2[8] * -0x7847d9;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xc] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x10] * 0x620dbe;
  iVar23 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + *param_2;
  uVar1 = ((longlong)param_2[2] * 0x2bc750 & 0xffffffff00000000U) +
          ((longlong)param_2[2] * 0x2bc750 & 0xffffffffU) + (longlong)param_2[6] * -0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[10] * 0x7e0e2e;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xe] * -0x5246dd;
  uVar6 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[4] * -0x620dbe & 0xffffffff00000000U) +
          ((longlong)param_2[4] * -0x620dbe & 0xffffffffU) + (longlong)param_2[8] * 0x163a1a;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xc] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x10] * -0x7847d9;
  iVar24 = ((param_2[8] + param_2[0x10] + *param_2) - param_2[4]) - param_2[0xc];
  iVar15 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + *param_2;
  uVar1 = ((longlong)param_2[3] * 0x7e0e2e & 0xffffffff00000000U) +
          ((longlong)param_2[3] * 0x7e0e2e & 0xffffffffU) + (longlong)param_2[7] * 0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xb] * 0x5246dd;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xf] * 0x2bc750;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[5] * 0x7847d9 & 0xffffffff00000000U) +
          ((longlong)param_2[5] * 0x7847d9 & 0xffffffffU) + (longlong)param_2[9] * 0x620dbe;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xd] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x11] * 0x163a1a;
  iVar25 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + param_2[1];
  lVar2 = (longlong)((param_2[3] - param_2[0xb]) - param_2[0xf]) * 0x6ed9eb;
  uVar8 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)((param_2[5] - param_2[9]) - param_2[0x11]) * 0x400000;
  iVar26 = (((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + param_2[1]) -
           param_2[0xd];
  uVar1 = ((longlong)param_2[3] * 0x5246dd & 0xffffffff00000000U) +
          ((longlong)param_2[3] * 0x5246dd & 0xffffffffU) + (longlong)param_2[7] * -0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xb] * -0x2bc750;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xf] * 0x7e0e2e;
  uVar9 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[5] * -0x163a1a & 0xffffffff00000000U) +
          ((longlong)param_2[5] * -0x163a1a & 0xffffffffU) + (longlong)param_2[9] * -0x7847d9;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xd] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x11] * 0x620dbe;
  iVar27 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + param_2[1];
  uVar1 = ((longlong)param_2[3] * 0x2bc750 & 0xffffffff00000000U) +
          ((longlong)param_2[3] * 0x2bc750 & 0xffffffffU) + (longlong)param_2[7] * -0x6ed9eb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xb] * 0x7e0e2e;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xf] * -0x5246dd;
  uVar10 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  uVar1 = ((longlong)param_2[5] * -0x620dbe & 0xffffffff00000000U) +
          ((longlong)param_2[5] * -0x620dbe & 0xffffffffU) + (longlong)param_2[9] * 0x163a1a;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0xd] * 0x400000;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_2[0x11] * -0x7847d9;
  iVar12 = param_2[0x11];
  iVar11 = param_2[9];
  iVar21 = param_2[1];
  iVar18 = param_2[0xd];
  iVar13 = param_2[5];
  iVar16 = ((int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17) + iVar21;
  iVar22 = iVar17 - uVar4;
  iVar17 = iVar17 + uVar4;
  lVar2 = (longlong)(int)(iVar25 + uVar7) * 0x403e95;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar25 - uVar7) * 0x2de5151;
  uVar19 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(uVar4 + iVar17) * -0x400f9b;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar17 - uVar4) * 0x5bb3ccb;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[8] = uVar4;
  param_1[0x1a] = uVar7;
  param_1[9] = -uVar4;
  param_1[0x1b] = uVar7;
  lVar2 = (longlong)(int)(uVar19 + iVar22) * -0x56ce4d;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar22 - uVar19) * 0x5ebb63;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[0x11] = -uVar4;
  *param_1 = uVar4;
  iVar17 = iVar20 - uVar14;
  param_1[0x12] = uVar7;
  param_1[0x23] = uVar7;
  iVar20 = iVar20 + uVar14;
  lVar2 = (longlong)(int)(iVar26 + uVar8) * 0x4241f7;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar26 - uVar8) * 0xf746ea;
  uVar8 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(uVar4 + iVar20) * -0x408d60;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar20 - uVar4) * 0x1ea52b3;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[7] = uVar4;
  param_1[0x19] = uVar7;
  param_1[10] = -uVar4;
  param_1[0x1c] = uVar7;
  lVar2 = (longlong)(int)(uVar8 + iVar17) * -0x50ab94;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar17 - uVar8) * 0x6921a9;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[0x10] = -uVar4;
  param_1[1] = uVar4;
  iVar17 = iVar23 - uVar5;
  param_1[0x13] = uVar7;
  param_1[0x22] = uVar7;
  iVar23 = iVar23 + uVar5;
  lVar2 = (longlong)(int)(iVar27 + uVar9) * 0x469dbe;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar27 - uVar9) * 0x976fd8;
  uVar7 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(uVar4 + iVar23) * -0x418dcb;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar23 - uVar4) * 0x127b1c9;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[6] = uVar4;
  param_1[0x18] = uVar5;
  param_1[0xb] = -uVar4;
  param_1[0x1d] = uVar5;
  lVar2 = (longlong)(int)(uVar7 + iVar17) * -0x4be254;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar17 - uVar7) * 0x771d3a;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[0xf] = -uVar4;
  param_1[2] = uVar4;
  iVar17 = iVar15 - uVar6;
  param_1[0x14] = uVar5;
  param_1[0x21] = uVar5;
  iVar15 = iVar15 + uVar6;
  lVar2 = (longlong)(int)(iVar16 + uVar10) * 0x4e212b;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar16 - uVar10) * 0x6f94a1;
  uVar6 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(uVar4 + iVar15) * -0x431b19;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar15 - uVar4) * 0xd4d525;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[5] = uVar4;
  param_1[0x17] = uVar5;
  param_1[0xc] = -uVar4;
  param_1[0x1e] = uVar5;
  lVar2 = (longlong)(int)(uVar6 + iVar17) * -0x482706;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar17 - uVar6) * 0x8a9a82;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[0xe] = -uVar4;
  param_1[0x15] = uVar5;
  param_1[3] = uVar4;
  param_1[0x20] = uVar5;
  lVar2 = (longlong)(((iVar11 + iVar12 + iVar21) - iVar18) - iVar13) * 0x5a8279;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(uVar4 + iVar24) * -0x4545e9;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  lVar2 = (longlong)(int)(iVar24 - uVar4) * 0xa73d74;
  uVar4 = (int)((ulonglong)lVar2 >> 0x20) << 9 | (uint)lVar2 >> 0x17;
  param_1[0x16] = uVar5;
  param_1[0xd] = -uVar4;
  param_1[4] = uVar4;
  param_1[0x1f] = uVar5;
  iVar12 = 0;
  do {
    iVar12 = iVar12 + 1;
    *param_1 = (int)*param_1 >> 4;
    param_1 = param_1 + 1;
  } while (iVar12 != 0x24);
  return;
}



/* 40a83b90 FUN_40a83b90 */

/* Boundary evidence: original MIPS .pdata 40a83b90..40a841fb. Semantic name remains unreviewed. */

void FUN_40a83b90(int param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  int *local_50;
  int *local_4c;
  uint local_44;
  
  piVar10 = (int *)(param_1 + 0x9f4);
  local_50 = (int *)(param_1 + 0xf4);
  if (piVar10 < (int *)(param_1 + 0x184)) {
LAB_40a83c60:
    iVar7 = (int)piVar10 - (int)local_50;
  }
  else {
    piVar11 = (int *)(param_1 + 0x9dc);
    iVar7 = (int)piVar11 - (int)local_50;
    if (((((*(int *)(param_1 + 0x9e0) == 0 && *(int *)(param_1 + 0x9f0) == 0) &&
          *(int *)(param_1 + 0x9dc) == 0) && *(int *)(param_1 + 0x9ec) == 0) &&
        *(int *)(param_1 + 0x9e8) == 0) && *(int *)(param_1 + 0x9e4) == 0) {
      do {
        iVar7 = (int)piVar11 - (int)local_50;
        if (piVar11 < (int *)(param_1 + 0x184)) goto LAB_40a83c64;
        piVar10 = piVar11 + -6;
        piVar8 = piVar11 + -5;
        piVar12 = piVar11 + -4;
        piVar1 = piVar11 + -3;
        piVar2 = piVar11 + -2;
        piVar3 = piVar11 + -1;
        piVar11 = piVar10;
      } while (((((*piVar8 == 0 && *piVar10 == 0) && *piVar12 == 0) && *piVar1 == 0) && *piVar2 == 0
               ) && *piVar3 == 0);
      goto LAB_40a83c60;
    }
  }
LAB_40a83c64:
  iVar7 = (iVar7 >> 2) / 0x12;
  uVar4 = iVar7 + 1;
  if (*(int *)(param_1 + 0x18) == 2) {
    if (*(int *)(param_1 + 0x14) != 0) {
      local_44 = 2;
      goto LAB_40a83cb4;
    }
    local_44 = 0;
  }
  else {
    local_44 = uVar4;
    if ((int)uVar4 < 1) goto LAB_40a84134;
LAB_40a83cb4:
    uVar14 = 0;
    piVar10 = param_2;
    do {
      FUN_40a82dcc((uint *)(param_4 + 0x68c0),local_50);
      if ((*(int *)(param_1 + 0x14) == 0) || (1 < (int)uVar14)) {
        puVar15 = &DAT_40a9ff1c + *(int *)(param_1 + 0x18) * 0x24;
      }
      else {
        puVar15 = &DAT_40a9ff1c;
      }
      piVar12 = puVar15 + (-(uVar14 & 1) & 0x90);
      iVar13 = 0;
      piVar11 = param_3;
      puVar9 = (uint *)(param_4 + 0x68c0);
      piVar8 = piVar10;
      do {
        iVar5 = (int)((ulonglong)((longlong)(int)*puVar9 * (longlong)(*piVar12 << 7)) >> 0x20) * 4;
        *piVar8 = iVar5;
        *piVar8 = iVar5 + *piVar11;
        iVar13 = iVar13 + 1;
        *piVar11 = (int)((ulonglong)((longlong)(int)puVar9[0x12] * (longlong)(piVar12[0x12] << 7))
                        >> 0x20) << 2;
        piVar8 = piVar8 + 0x20;
        piVar12 = piVar12 + 1;
        puVar9 = puVar9 + 1;
        piVar11 = piVar11 + 1;
      } while (iVar13 != 0x12);
      uVar14 = uVar14 + 1;
      local_50 = local_50 + 0x12;
      param_3 = param_3 + 0x12;
      piVar10 = piVar10 + 1;
    } while ((int)uVar14 < (int)local_44);
  }
  if ((int)local_44 < (int)uVar4) {
    local_4c = param_2 + local_44;
    iVar13 = 0;
    uVar14 = local_44;
    do {
      iVar5 = (-(uVar14 & 1) & 0x90) + 0x48;
      iVar6 = iVar5 * 4;
      *(undefined4 *)(param_4 + 0x68c0) = 0;
      *(undefined4 *)(param_4 + 0x68d8) = 0;
      *(undefined4 *)(param_4 + 0x6938) = 0;
      *(undefined4 *)(param_4 + 0x68c4) = 0;
      *(undefined4 *)(param_4 + 0x68dc) = 0;
      *(undefined4 *)(param_4 + 0x693c) = 0;
      *(undefined4 *)(param_4 + 0x68c8) = 0;
      *(undefined4 *)(param_4 + 0x68e0) = 0;
      *(undefined4 *)(param_4 + 0x6940) = 0;
      *(undefined4 *)(param_4 + 0x68cc) = 0;
      *(undefined4 *)(param_4 + 0x68e4) = 0;
      *(undefined4 *)(param_4 + 0x6944) = 0;
      *(undefined4 *)(param_4 + 0x68d0) = 0;
      *(undefined4 *)(param_4 + 0x68e8) = 0;
      *(undefined4 *)(param_4 + 0x6948) = 0;
      *(undefined4 *)(param_4 + 0x68d4) = 0;
      *(undefined4 *)(param_4 + 0x68ec) = 0;
      *(undefined4 *)(param_4 + 0x694c) = 0;
      puVar15 = (undefined4 *)((int)local_50 + iVar13);
      iVar16 = 0;
      piVar10 = (int *)(param_4 + 0x68d8);
      do {
        *(undefined4 *)(param_4 + 0x68a8) = *puVar15;
        *(undefined4 *)(param_4 + 0x68ac) = puVar15[3];
        *(undefined4 *)(param_4 + 0x68b0) = puVar15[6];
        *(undefined4 *)(param_4 + 0x68b4) = puVar15[9];
        *(undefined4 *)(param_4 + 0x68b8) = puVar15[0xc];
        *(undefined4 *)(param_4 + 0x68bc) = puVar15[0xf];
        FUN_40a82a28((uint *)(param_4 + 0x6950),(int *)(param_4 + 0x68a8));
        *piVar10 = (int)((ulonglong)
                         ((longlong)*(int *)(param_4 + 0x6950) *
                         (longlong)(int)((&DAT_40a9ff1c)[iVar5] << 7)) >> 0x20) * 4 + *piVar10;
        piVar10[6] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6968) *
                           (longlong)(*(int *)(&DAT_40a9ff34 + iVar6) << 7)) >> 0x20) << 2;
        piVar10[1] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6954) *
                           (longlong)(int)((&DAT_40a9ff20)[iVar5] << 7)) >> 0x20) * 4 + piVar10[1];
        piVar10[7] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x696c) *
                           (longlong)(*(int *)(&DAT_40a9ff38 + iVar6) << 7)) >> 0x20) << 2;
        piVar10[2] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6958) *
                           (longlong)(*(int *)(&DAT_40a9ff24 + iVar6) << 7)) >> 0x20) * 4 +
                     piVar10[2];
        piVar10[8] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6970) *
                           (longlong)(*(int *)(&DAT_40a9ff3c + iVar6) << 7)) >> 0x20) << 2;
        piVar10[3] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x695c) *
                           (longlong)(*(int *)(&DAT_40a9ff28 + iVar6) << 7)) >> 0x20) * 4 +
                     piVar10[3];
        piVar10[9] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6974) *
                           (longlong)(*(int *)(&DAT_40a9ff40 + iVar6) << 7)) >> 0x20) << 2;
        piVar10[4] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6960) *
                           (longlong)(*(int *)(&DAT_40a9ff2c + iVar6) << 7)) >> 0x20) * 4 +
                     piVar10[4];
        piVar10[10] = (int)((ulonglong)
                            ((longlong)*(int *)(param_4 + 27000) *
                            (longlong)(*(int *)(&DAT_40a9ff44 + iVar6) << 7)) >> 0x20) << 2;
        piVar10[5] = (int)((ulonglong)
                           ((longlong)*(int *)(param_4 + 0x6964) *
                           (longlong)(*(int *)(&DAT_40a9ff30 + iVar6) << 7)) >> 0x20) * 4 +
                     piVar10[5];
        iVar16 = iVar16 + 1;
        piVar10[0xb] = (int)((ulonglong)
                             ((longlong)*(int *)(param_4 + 0x697c) *
                             (longlong)(*(int *)(&DAT_40a9ff48 + iVar6) << 7)) >> 0x20) << 2;
        puVar15 = puVar15 + 1;
        piVar10 = piVar10 + 6;
      } while (iVar16 != 3);
      piVar8 = (int *)((int)param_3 + iVar13);
      iVar5 = 0;
      piVar10 = (int *)(param_4 + 0x68c0);
      piVar11 = local_4c;
      do {
        iVar5 = iVar5 + 1;
        *piVar11 = *piVar8 + *piVar10;
        piVar11 = piVar11 + 0x20;
        *piVar8 = piVar10[0x12];
        piVar10 = piVar10 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar5 != 0x12);
      uVar14 = uVar14 + 1;
      local_4c = local_4c + 1;
      iVar13 = iVar13 + 0x48;
    } while ((int)uVar14 < (int)uVar4);
    param_3 = param_3 + (~local_44 + iVar7) * 0x12 + 0x24;
  }
LAB_40a84134:
  if ((int)uVar4 < 0x20) {
    piVar10 = param_2 + uVar4;
    while( true ) {
      iVar7 = 0;
      piVar11 = param_3;
      piVar8 = piVar10;
      do {
        iVar7 = iVar7 + 1;
        *piVar8 = *piVar11;
        *piVar11 = 0;
        piVar8 = piVar8 + 0x20;
        piVar11 = piVar11 + 1;
      } while (iVar7 != 0x12);
      uVar4 = uVar4 + 1;
      piVar10 = piVar10 + 1;
      if (0x1f < (int)uVar4) break;
      param_3 = param_3 + 0x12;
    }
  }
  return;
}



/* 40a84268 FUN_40a84268 */

uint FUN_40a84268(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  
  uVar6 = param_1[1];
  pbVar5 = (byte *)(*param_1 + ((int)uVar6 >> 3));
  bVar1 = *pbVar5;
  bVar2 = pbVar5[3];
  bVar3 = pbVar5[2];
  bVar4 = pbVar5[1];
  param_1[1] = param_2 + uVar6;
  return (((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10) <<
         (uVar6 & 7)) >> (-param_2 & 0x1fU);
}



/* 40a846d0 FUN_40a846d0 */

void FUN_40a846d0(int *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  
  if (param_5 == 4) {
    param_1[3] = param_2 & 3;
    param_2 = (int)param_2 >> 2;
  }
  else {
    param_1[3] = 0;
  }
  if (param_4 == 6) {
    uVar1 = (int)param_2 / 6;
    param_1[2] = (int)param_2 % 6;
  }
  else if (param_4 == 4) {
    param_1[2] = param_2 & 3;
    uVar1 = (int)param_2 >> 2;
  }
  else {
    param_1[2] = 0;
    uVar1 = param_2;
  }
  if (param_3 == 4) {
    param_1[1] = uVar1 & 3;
    *param_1 = (int)uVar1 >> 2;
    return;
  }
  if (param_3 == 0) {
    trap(7);
  }
  param_1[1] = (int)uVar1 % param_3;
  *param_1 = (int)uVar1 / param_3;
  return;
}



/* 40a847ac FUN_40a847ac */

/* Boundary evidence: original MIPS .pdata 40a847ac..40a84cc7. Semantic name remains unreviewed. */

void FUN_40a847ac(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  undefined *puVar15;
  int *piVar16;
  int *piVar17;
  uint uStack_3c;
  uint local_38 [5];
  
  if ((*(uint *)(param_3 + 0x6984) & 1) == 0) {
    if ((*(uint *)(param_3 + 0x6984) & 2) != 0) {
      iVar14 = 0;
      do {
        iVar2 = *(int *)(param_1 + 0xf4);
        iVar13 = *(int *)(param_2 + 0xf4);
        iVar14 = iVar14 + 1;
        *(int *)(param_1 + 0xf4) = iVar13 + iVar2;
        *(int *)(param_2 + 0xf4) = iVar2 - iVar13;
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
      } while (iVar14 != 0x240);
      return;
    }
  }
  else {
    if (*(int *)(param_3 + 100) == 0) {
      iVar14 = 7;
      puVar15 = &DAT_40a9fd5c;
    }
    else {
      puVar15 = &UNK_40a9fddc + (*(uint *)(param_2 + 0x10) & 1) * 0x80;
      iVar14 = 0x10;
    }
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    piVar17 = (int *)(param_1 + 0x9f4);
    piVar16 = (int *)(param_2 + 0x9f4);
    iVar2 = *(int *)(param_2 + 0x20);
    if (*(int *)(param_2 + 0x1c) < 0xd) {
      iVar2 = iVar2 + -3 + (0xd - *(int *)(param_2 + 0x1c)) * 3;
      iVar13 = 0xc;
      do {
        if (iVar13 != 0xb) {
          iVar2 = iVar2 + -3;
        }
        iVar10 = *(int *)(&DAT_40aa0b64 + *(int *)(param_3 + 0x58) * 0x34 + iVar13 * 4);
        piVar12 = (int *)(param_2 + (iVar2 + 0x16) * 4 + 4);
        puVar11 = local_38 + 2;
        piVar5 = piVar16;
        piVar8 = piVar17;
        do {
          piVar8 = piVar8 + -iVar10;
          piVar5 = piVar5 + -iVar10;
          if (*puVar11 == 0) {
            if (0 < iVar10) {
              if (*piVar5 == 0) {
                iVar1 = 0;
                piVar3 = piVar5;
                do {
                  iVar1 = iVar1 + 1;
                  if (iVar10 <= iVar1) goto LAB_40a848f0;
                  piVar7 = piVar3 + 1;
                  piVar3 = piVar3 + 1;
                } while (*piVar7 == 0);
              }
              *puVar11 = 1;
              goto LAB_40a84ba8;
            }
LAB_40a848f0:
            if (iVar14 <= *piVar12) goto LAB_40a84ba8;
            iVar9 = *(int *)((int)(puVar15 + *piVar12 * 4) + 0x40);
            iVar1 = *(int *)(puVar15 + *piVar12 * 4);
            if (0 < iVar10) {
              iVar6 = 0;
              piVar3 = piVar8;
              piVar7 = piVar5;
              do {
                iVar4 = *piVar3;
                *piVar3 = (int)((ulonglong)((longlong)iVar4 * (longlong)(iVar1 << 6)) >> 0x20) << 3;
                iVar6 = iVar6 + 1;
                *piVar7 = (int)((ulonglong)((longlong)iVar4 * (longlong)(iVar9 << 6)) >> 0x20) << 3;
                piVar3 = piVar3 + 1;
                piVar7 = piVar7 + 1;
              } while (iVar6 < iVar10);
            }
          }
          else {
LAB_40a84ba8:
            if (((*(uint *)(param_3 + 0x6984) & 2) != 0) && (0 < iVar10)) {
              iVar1 = 0;
              piVar3 = piVar5;
              piVar7 = piVar8;
              do {
                iVar9 = *piVar7;
                iVar6 = *piVar3;
                *piVar7 = (int)((ulonglong)((longlong)(iVar6 + iVar9) * 0x16a09e40) >> 0x20) << 3;
                iVar1 = iVar1 + 1;
                *piVar3 = (int)((ulonglong)((longlong)(iVar9 - iVar6) * 0x16a09e40) >> 0x20) << 3;
                piVar7 = piVar7 + 1;
                piVar3 = piVar3 + 1;
              } while (iVar1 < iVar10);
            }
          }
          puVar11 = puVar11 + -1;
          piVar12 = piVar12 + -1;
        } while (&uStack_3c != puVar11);
        iVar13 = iVar13 + -1;
        piVar17 = piVar17 + iVar10 * -3;
        piVar16 = piVar16 + iVar10 * -3;
      } while (*(int *)(param_2 + 0x1c) <= iVar13);
      iVar2 = *(int *)(param_2 + 0x20);
    }
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      local_38[2] = local_38[1] | local_38[0] | local_38[2];
      do {
        while( true ) {
          iVar13 = *(int *)(&DAT_40aa084c + (*(int *)(param_3 + 0x58) * 0x16 + iVar2) * 4);
          piVar16 = piVar16 + -iVar13;
          piVar17 = piVar17 + -iVar13;
          if (local_38[2] != 0) break;
          if (0 < iVar13) {
            if (*piVar16 == 0) {
              iVar10 = 0;
              piVar5 = piVar16;
              do {
                iVar10 = iVar10 + 1;
                if (iVar13 <= iVar10) goto LAB_40a84a4c;
                piVar8 = piVar5 + 1;
                piVar5 = piVar5 + 1;
              } while (*piVar8 == 0);
            }
            local_38[2] = 1;
            break;
          }
LAB_40a84a4c:
          iVar10 = 0x14;
          if (iVar2 != 0x15) {
            iVar10 = iVar2;
          }
          iVar10 = *(int *)(param_2 + (iVar10 + 0x14) * 4 + 4);
          if (iVar14 <= iVar10) break;
          iVar1 = *(int *)((int)(puVar15 + iVar10 * 4) + 0x40);
          iVar10 = *(int *)(puVar15 + iVar10 * 4);
          if (0 < iVar13) {
            iVar9 = 0;
            piVar5 = piVar17;
            piVar8 = piVar16;
            do {
              iVar6 = *piVar5;
              *piVar5 = (int)((ulonglong)((longlong)iVar6 * (longlong)(iVar10 << 6)) >> 0x20) << 3;
              iVar9 = iVar9 + 1;
              *piVar8 = (int)((ulonglong)((longlong)iVar6 * (longlong)(iVar1 << 6)) >> 0x20) << 3;
              piVar5 = piVar5 + 1;
              piVar8 = piVar8 + 1;
            } while (iVar9 < iVar13);
          }
LAB_40a84adc:
          iVar2 = iVar2 + -1;
          if (iVar2 < 0) {
            return;
          }
        }
        if (((*(uint *)(param_3 + 0x6984) & 2) == 0) || (iVar13 < 1)) goto LAB_40a84adc;
        iVar10 = 0;
        piVar5 = piVar16;
        piVar8 = piVar17;
        do {
          iVar1 = *piVar8;
          iVar9 = *piVar5;
          *piVar8 = (int)((ulonglong)((longlong)(iVar9 + iVar1) * 0x16a09e40) >> 0x20) << 3;
          iVar10 = iVar10 + 1;
          *piVar5 = (int)((ulonglong)((longlong)(iVar1 - iVar9) * 0x16a09e40) >> 0x20) << 3;
          piVar8 = piVar8 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar10 < iVar13);
        iVar2 = iVar2 + -1;
      } while (-1 < iVar2);
    }
  }
  return;
}



/* 40a84cc8 FUN_40a84cc8 */

void FUN_40a84cc8(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_3 != 0) {
    *(int *)(param_5 + 4) = *(int *)(param_5 + 4) + param_3;
  }
  if (0 < param_4) {
    iVar1 = *(int *)(param_5 + 0x18);
    if (0 < iVar1) {
      iVar2 = param_1 / iVar1;
      if (iVar1 == 0) {
        trap(7);
      }
      *(undefined4 *)(param_5 + 0x10) = 0xfffefe;
      if (iVar2 < 0) {
        iVar2 = iVar2 + 7;
      }
      *(int *)(param_5 + 4) = iVar2 >> 3;
      return;
    }
    *(undefined4 *)(param_5 + 0x10) = 0xfffefe;
    if ((param_2 != 0) && (param_1 != 0)) {
      if (param_2 == 0) {
        trap(7);
      }
      if (param_1 == 0) {
        trap(7);
      }
      *(int *)(param_5 + 0x14) = -((0xfffefe / param_2) / param_1) * param_4;
      return;
    }
    *(undefined4 *)(param_5 + 0x14) = 0xff000102;
  }
  return;
}



/* 40a84d9c FUN_40a84d9c */

/* Boundary evidence: original MIPS .pdata 40a84d9c..40a850ef. Semantic name remains unreviewed. */

undefined4 FUN_40a84d9c(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if ((param_1 & 0x100000) == 0) {
    *(undefined4 *)(param_2 + 0x80) = 1;
    *(undefined4 *)(param_2 + 100) = 1;
    iVar8 = 1;
    uVar1 = 1;
  }
  else {
    *(undefined4 *)(param_2 + 0x80) = 0;
    uVar1 = (param_1 >> 0x13 ^ 1) & 1;
    iVar8 = *(int *)(param_2 + 0x80);
    *(uint *)(param_2 + 100) = uVar1;
  }
  uVar3 = param_1 >> 10 & 3;
  iVar6 = *(int *)(&DAT_40aa0504 + uVar3 * 4) >> (iVar8 + uVar1 & 0x1f);
  uVar5 = param_1 >> 6 & 3;
  iVar9 = *(int *)(param_2 + 0x90) + 1;
  *(uint *)(param_2 + 0x68) = param_1 & 3;
  *(uint *)(param_2 + 0x6984) = param_1 >> 4 & 3;
  *(uint *)(param_2 + 0x60) = 4 - (param_1 >> 0x11 & 3);
  *(uint *)(param_2 + 0x58) = uVar3 + (iVar8 + uVar1) * 3;
  *(uint *)(param_2 + 0x84) = (param_1 >> 0x10 ^ 1) & 1;
  *(uint *)(param_2 + 0x6c) = param_1 >> 8 & 1;
  *(uint *)(param_2 + 0x74) = param_1 >> 3 & 1;
  *(uint *)(param_2 + 0x70) = param_1 >> 2 & 1;
  *(int *)(param_2 + 0x88) = iVar6;
  *(undefined4 *)(param_2 + 0x98) = 1;
  uVar3 = param_1 >> 0xc & 0xf;
  *(uint *)(param_2 + 0x6980) = uVar5;
  *(int *)(param_2 + 0x90) = iVar9;
  if (uVar5 == 3) {
    *(undefined4 *)(param_2 + 0x8c) = 1;
  }
  else {
    *(undefined4 *)(param_2 + 0x8c) = 2;
  }
  if (uVar3 != 0) {
    iVar4 = *(int *)(param_2 + 0x60);
    iVar2 = *(int *)(&DAT_40aa039c + ((iVar4 + -1) * 0xf + uVar1 * 0x2d) * 4 + uVar3 * 4);
    iVar7 = iVar2 + *(int *)(param_2 + 0x6994);
    *(int *)(param_2 + 0x698c) = iVar2 * 1000;
    *(int *)(param_2 + 0x6994) = iVar7;
    if ((*(int *)(param_2 + 0x7c) == 0) || (iVar9 == 0)) {
      *(undefined4 *)(param_2 + 0x6990) = *(undefined4 *)(param_2 + 0x698c);
    }
    else if (iVar7 < 0xfffffff) {
      if (iVar9 == 0) {
        trap(7);
      }
      *(int *)(param_2 + 0x6990) = ((iVar7 * 8) / iVar9) * 0x7d;
    }
    else {
      if (iVar9 == 0) {
        trap(7);
      }
      *(int *)(param_2 + 0x6990) = (iVar7 / iVar9) * 1000;
    }
    uVar5 = param_1 >> 9 & 1;
    if (iVar4 == 1) {
      if (iVar6 == 0) {
        trap(7);
      }
      iVar6 = ((iVar2 * 12000) / iVar6 + uVar5) * 4;
    }
    else if (iVar4 == 2) {
      if (iVar6 == 0) {
        trap(7);
      }
      iVar6 = (iVar2 * 0x23280) / iVar6 + uVar5;
    }
    else {
      if (iVar6 << uVar1 == 0) {
        trap(7);
      }
      iVar6 = (iVar2 * 0x23280) / (iVar6 << uVar1) + uVar5;
    }
    *(int *)(param_2 + 0x48) = iVar6;
    if (*(int *)(param_2 + 0xc) != iVar8) {
      *(undefined4 *)(param_2 + 0x94) = 1;
    }
    if (*(uint *)(param_2 + 8) != uVar3) {
      iVar8 = *(int *)(param_2 + 0x6988);
      *(int *)(param_2 + 0x6988) = iVar8 + 1;
      if (iVar8 < 0xb) {
        *(undefined4 *)(param_2 + 0x7c) = 0;
        *(undefined4 *)(param_2 + 0x94) = 1;
      }
      else {
        *(undefined4 *)(param_2 + 0x7c) = 1;
        *(undefined4 *)(param_2 + 0x94) = 1;
      }
    }
    if (*(int *)(param_2 + 0x48) != 0) {
      *(int *)(param_2 + 0x69ac) = *(int *)(param_2 + 0x48);
    }
    *(uint *)(param_2 + 8) = uVar3;
    return 0;
  }
  return 1;
}



/* 40a85178 FUN_40a85178 */

undefined4 FUN_40a85178(undefined4 param_1,int param_2)

{
  *(undefined **)(param_2 + 0x8440) = &DAT_40aa6204;
  *(undefined4 *)(param_2 + 0x50) = param_1;
  *(undefined **)(param_2 + 0x8448) = &DAT_40aa6214;
  *(undefined **)(param_2 + 0x8444) = &DAT_40aa6208;
  *(undefined **)(param_2 + 0x8450) = &DAT_40aa6230;
  *(undefined **)(param_2 + 0x844c) = &DAT_40aa6220;
  *(char **)(param_2 + 0x8458) = s______012345_ABCDEPQRSTU_40aa624c + 0x18;
  *(undefined **)(param_2 + 0x8454) = &DAT_40aa6240;
  *(char **)(param_2 + 0x8460) = s______012345_ABCDEPQRSTU_40aa6294 + 0x18;
  *(char **)(param_2 + 0x845c) = s______012345_ABCDEPQRSTU_40aa6270 + 0x18;
  *(char **)(param_2 + 0x8468) = s________01234567_ABCDEFGPQRSTUVW__40aa62fc + 0x30;
  *(char **)(param_2 + 0x8464) = s________01234567_ABCDEFGPQRSTUVW__40aa62bc + 0x30;
  *(undefined **)(param_2 + 0x8470) = &DAT_40aa646c;
  *(char **)(param_2 + 0x846c) = s________01234567_ABCDEFGPQRSTUVW__40aa633c + 0x30;
  *(undefined **)(param_2 + 0x8478) = &DAT_40aa666c;
  *(undefined **)(param_2 + 0x8474) = &DAT_40aa656c;
  *(undefined **)(param_2 + 0x83c0) = &DAT_40aa6f74;
  *(undefined **)(param_2 + 0x83b8) = &DAT_40aa6774;
  *(undefined **)(param_2 + 0x83d0) = &DAT_40aa7f74;
  *(undefined **)(param_2 + 0x83c8) = &DAT_40aa7774;
  *(undefined **)(param_2 + 0x83e0) = &DAT_40aa8f74;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x90) = 0;
  *(undefined **)(param_2 + 0x83d8) = &DAT_40aa8774;
  *(undefined4 *)(param_2 + 0x83b4) = 8;
  *(undefined4 *)(param_2 + 0x83bc) = 8;
  *(undefined4 *)(param_2 + 0x83c4) = 8;
  *(undefined4 *)(param_2 + 0x83cc) = 8;
  *(undefined4 *)(param_2 + 0x83d4) = 8;
  *(undefined4 *)(param_2 + 0x83dc) = 8;
  *(int *)(param_2 + 0x6be4) = param_2 + 0x6fec;
  *(int *)(param_2 + 0x6be8) = param_2 + 0x6fec;
  *(undefined4 *)(param_2 + 0x843c) = 0;
  *(undefined **)(param_2 + 0x83e8) = &DAT_40aa97d4;
  *(undefined4 *)(param_2 + 0x8434) = 4;
  *(undefined **)(param_2 + 0x83f0) = &DAT_40aaa064;
  *(undefined **)(param_2 + 0x83f8) = &DAT_40aaa884;
  *(undefined **)(param_2 + 0x8400) = &DAT_40aab214;
  *(undefined **)(param_2 + 0x8408) = &DAT_40aabb04;
  *(undefined **)(param_2 + 0x8410) = &DAT_40aac384;
  *(undefined **)(param_2 + 0x8418) = &DAT_40aada64;
  *(undefined **)(param_2 + 0x8420) = &DAT_40aaeb14;
  *(undefined **)(param_2 + 0x8428) = &DAT_40ab0434;
  *(undefined **)(param_2 + 0x8430) = &DAT_40ab12e4;
  *(undefined4 *)(param_2 + 0x8424) = 8;
  *(undefined4 *)(param_2 + 0x842c) = 7;
  *(undefined **)(param_2 + 0x8438) = &DAT_40ab16e4;
  *(undefined4 *)(param_2 + 0x83e4) = 8;
  *(undefined4 *)(param_2 + 0x83ec) = 8;
  *(undefined4 *)(param_2 + 0x83f4) = 8;
  *(undefined4 *)(param_2 + 0x83fc) = 8;
  *(undefined4 *)(param_2 + 0x8404) = 8;
  *(undefined4 *)(param_2 + 0x840c) = 8;
  *(undefined4 *)(param_2 + 0x8414) = 8;
  *(undefined4 *)(param_2 + 0x841c) = 8;
  return 0;
}



/* 40a85374 FUN_40a85374 */

/* Boundary evidence: original MIPS .pdata 40a85374..40a8548b. Semantic name remains unreviewed. */

void FUN_40a85374(int *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *param_2 = *(undefined4 *)(param_4 + 0x90);
  *param_3 = *(undefined4 *)(param_4 + 0x6990);
  uVar3 = s_MPEG2_5_layer_3_40aa60e8._12_4_;
  uVar2 = s_MPEG2_5_layer_3_40aa60e8._8_4_;
  uVar1 = s_MPEG2_5_layer_3_40aa60e8._4_4_;
  if (*(int *)(param_4 + 0x80) != 0) {
    *(undefined4 *)(param_4 + 0x69b8) = s_MPEG2_5_layer_3_40aa60e8._0_4_;
    *(undefined4 *)(param_4 + 0x69c4) = uVar3;
    *(undefined4 *)(param_4 + 0x69bc) = uVar1;
    *(undefined4 *)(param_4 + 0x69c0) = uVar2;
    FUN_40a8a870(param_1,(int *)(param_4 + 0x6998),0x120);
    return;
  }
  if ((*(int *)(param_4 + 100) == 0) && (*(int *)(param_4 + 0x69a0) < 3)) {
    sprintf((char *)(param_4 + 0x69b8),s_MPEG_1_layer__d_40aa6108,*(undefined4 *)(param_4 + 0x1c));
    FUN_40a8a870(param_1,(int *)(param_4 + 0x6998),0x120);
    return;
  }
  sprintf((char *)(param_4 + 0x69b8),s_MPEG_2_layer__d_40aa60f8,*(undefined4 *)(param_4 + 0x1c));
  FUN_40a8a870(param_1,(int *)(param_4 + 0x6998),0x120);
  return;
}



/* 40a8548c FUN_40a8548c */

/* Boundary evidence: original MIPS .pdata 40a8548c..40a85a47. Semantic name remains unreviewed. */

void FUN_40a8548c(int *param_1,uint *param_2,undefined2 *param_3,int *param_4,int param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined2 *puVar9;
  undefined2 *puVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  
  iVar6 = *(int *)(param_5 + 0x8c);
  FUN_40a8a870(param_1,param_4,0x80);
  FUN_40a8a870(param_1 + 0x200,param_1,0x80);
  uVar1 = ((longlong)param_1[0x50] * 0xd5 & 0xffffffff00000000U) +
          ((longlong)param_1[0x50] * 0xd5 & 0xffffffffU) + (longlong)param_1[0x90] * 0x7f5;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0xd0] * 0x19ae;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x110] * 0x1251e;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x150] * 0x19ae;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[400] * 0x7f5;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x1d0] * 0xd5;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x30] * 0x1d;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x70] * 0x1cb;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0xb0] * 0x1421;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0xf0] * 0x9271;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x130] * -0x9271;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x170] * -0x1421;
  uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x1b0] * -0x1cb;
  lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x1f0] * -0x1d;
  uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 8 | (uint)lVar2 >> 0x18;
  if ((int)uVar5 < 0x8000) {
    uVar8 = 0xffff8000;
    if (-0x8001 < (int)uVar5) {
      uVar8 = uVar5;
    }
    uVar3 = (undefined2)uVar8;
  }
  else {
    uVar3 = 0x7fff;
  }
  *param_3 = uVar3;
  puVar10 = param_3 + iVar6 * 0x1f;
  piVar11 = &DAT_40a951d8;
  piVar12 = &DAT_40a95250;
  piVar7 = param_1;
  puVar9 = param_3 + iVar6;
  piVar13 = param_1;
  do {
    uVar1 = (longlong)*piVar11 * (longlong)piVar7[0x11];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x40] * (longlong)piVar7[0x51];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x80] * (longlong)piVar7[0x91];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0xc0] * (longlong)piVar7[0xd1];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x100] * (longlong)piVar7[0x111];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x140] * (longlong)piVar7[0x151];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x180] * (longlong)piVar7[0x191];
    uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
            (longlong)piVar11[0x1c0] * (longlong)piVar7[0x1d1];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x20] * (longlong)piVar13[0x2f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x60] * (longlong)piVar13[0x6f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0xa0] * (longlong)piVar13[0xaf];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0xe0] * (longlong)piVar13[0xef];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x120] * (longlong)piVar13[0x12f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x160] * (longlong)piVar13[0x16f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x1a0] * (longlong)piVar13[0x1af];
    lVar2 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar11[0x1e0] * (longlong)piVar13[0x1ef];
    uVar8 = (int)((ulonglong)lVar2 >> 0x20) << 8 | (uint)lVar2 >> 0x18;
    uVar1 = (longlong)*piVar12 * (longlong)-piVar7[0x11];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x40] * (longlong)piVar7[0x51];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x80] * (longlong)piVar7[0x91];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0xc0] * (longlong)piVar7[0xd1];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x100] * (longlong)piVar7[0x111];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x140] * (longlong)piVar7[0x151];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x180] * (longlong)piVar7[0x191];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x1c0] * (longlong)piVar7[0x1d1];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x20] * (longlong)piVar13[0x2f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x60] * (longlong)piVar13[0x6f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0xa0] * (longlong)piVar13[0xaf];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0xe0] * (longlong)piVar13[0xef];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x120] * (longlong)piVar13[0x12f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x160] * (longlong)piVar13[0x16f];
    uVar1 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x1a0] * (longlong)piVar13[0x1af];
    lVar2 = ((uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff)) -
            (longlong)piVar12[0x1e0] * (longlong)piVar13[0x1ef];
    uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 8 | (uint)lVar2 >> 0x18;
    if ((int)uVar8 < 0x8000) {
      uVar4 = 0xffff8000;
      if (-0x8001 < (int)uVar8) {
        uVar4 = uVar8;
      }
      *puVar9 = (short)uVar4;
      if (0x7fff < (int)uVar5) goto LAB_40a856cc;
LAB_40a858b8:
      uVar8 = 0xffff8000;
      if (-0x8001 < (int)uVar5) {
        uVar8 = uVar5;
      }
      *puVar10 = (short)uVar8;
    }
    else {
      *puVar9 = 0x7fff;
      if ((int)uVar5 < 0x8000) goto LAB_40a858b8;
LAB_40a856cc:
      *puVar10 = 0x7fff;
    }
    if (piVar11 == (int *)&UNK_40a95210) {
      uVar1 = ((longlong)-param_1[0x20] * -0x68 & 0xffffffff00000000U) +
              ((longlong)-param_1[0x20] * -0x68 & 0xffffffffU) + (longlong)param_1[0x60] * 0x61f;
      uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0xa0] * 0x25ff
      ;
      uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0xe0] * 0xfa13
      ;
      uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) +
              (longlong)param_1[0x120] * -0x26f7;
      uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x160] * -0x2d
      ;
      uVar1 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x1a0] * 0x92;
      lVar2 = (uVar1 & 0xffffffff00000000) + (uVar1 & 0xffffffff) + (longlong)param_1[0x1e0] * -5;
      uVar5 = (int)((ulonglong)lVar2 >> 0x20) << 8 | (uint)lVar2 >> 0x18;
      if ((int)uVar5 < 0x8000) {
        uVar8 = 0xffff8000;
        if (-0x8001 < (int)uVar5) {
          uVar8 = uVar5;
        }
        uVar3 = (undefined2)uVar8;
      }
      else {
        uVar3 = 0x7fff;
      }
      uVar5 = *param_2;
      (param_3 + iVar6)[iVar6 * 0xf] = uVar3;
      *param_2 = uVar5 - 0x20 & 0x1ff;
      return;
    }
    piVar13 = piVar13 + -1;
    puVar9 = puVar9 + iVar6;
    piVar7 = piVar7 + 1;
    piVar11 = piVar11 + 1;
    puVar10 = puVar10 + -iVar6;
    piVar12 = piVar12 + -1;
  } while( true );
}



/* 40a85a48 FUN_40a85a48 */

/* Boundary evidence: original MIPS .pdata 40a85a48..40a85cb3. Semantic name remains unreviewed. */

void FUN_40a85a48(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = param_1[0x14];
  memset(param_1,0,0x847c);
  param_1[0x2110] = &DAT_40aa6204;
  param_1[0x2112] = &DAT_40aa6214;
  param_1[0x2111] = &DAT_40aa6208;
  param_1[0x2114] = &DAT_40aa6230;
  param_1[0x2113] = &DAT_40aa6220;
  param_1[0x2116] = s______012345_ABCDEPQRSTU_40aa624c + 0x18;
  param_1[0x2115] = &DAT_40aa6240;
  param_1[0x2118] = s______012345_ABCDEPQRSTU_40aa6294 + 0x18;
  param_1[0x2117] = s______012345_ABCDEPQRSTU_40aa6270 + 0x18;
  param_1[0x211a] = s________01234567_ABCDEFGPQRSTUVW__40aa62fc + 0x30;
  param_1[0x2119] = s________01234567_ABCDEFGPQRSTUVW__40aa62bc + 0x30;
  param_1[0x211c] = &DAT_40aa646c;
  param_1[0x211b] = s________01234567_ABCDEFGPQRSTUVW__40aa633c + 0x30;
  param_1[0x211e] = &DAT_40aa666c;
  param_1[0x211d] = &DAT_40aa656c;
  param_1[0x20f0] = &DAT_40aa6f74;
  param_1[0x14] = uVar1;
  param_1[7] = 0xffffffc9;
  param_1[8] = 0xffffffc9;
  param_1[9] = 0xffffffc9;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0xffffffc9;
  param_1[0xe] = 0xffffffc9;
  param_1[0xf] = 0xffffffc9;
  param_1[0x17] = 0;
  param_1[0x24] = 0;
  param_1[0x1af9] = param_1 + 0x1bfb;
  param_1[0x20ee] = &DAT_40aa6774;
  param_1[0x1afa] = param_1 + 0x1bfb;
  param_1[0x210f] = 0;
  param_1[0x20ed] = 8;
  param_1[0x20ef] = 8;
  param_1[0x210b] = 7;
  param_1[0x20f2] = &DAT_40aa7774;
  param_1[0x20f6] = &DAT_40aa8774;
  param_1[0x20f4] = &DAT_40aa7f74;
  param_1[0x20fa] = &DAT_40aa97d4;
  param_1[0x20f8] = &DAT_40aa8f74;
  param_1[0x20fe] = &DAT_40aaa884;
  param_1[0x20fc] = &DAT_40aaa064;
  param_1[0x2102] = &DAT_40aabb04;
  param_1[0x2100] = &DAT_40aab214;
  param_1[0x2106] = &DAT_40aada64;
  param_1[0x2104] = &DAT_40aac384;
  param_1[0x210a] = &DAT_40ab0434;
  param_1[0x2108] = &DAT_40aaeb14;
  param_1[0x210e] = &DAT_40ab16e4;
  param_1[0x2109] = 8;
  param_1[0x210d] = 4;
  param_1[0x20f1] = 8;
  param_1[0x20f3] = 8;
  param_1[0x20f5] = 8;
  param_1[0x20f7] = 8;
  param_1[0x20f9] = 8;
  param_1[0x20fb] = 8;
  param_1[0x20fd] = 8;
  param_1[0x20ff] = 8;
  param_1[0x2101] = 8;
  param_1[0x2103] = 8;
  param_1[0x2105] = 8;
  param_1[0x2107] = 8;
  param_1[0x210c] = &DAT_40ab12e4;
  *param_1 = 4;
  param_1[0x27] = 5;
  param_1[0x1aae] = 0xffffffc9;
  param_1[0x1ab1] = 0xffffffc9;
  param_1[0x1ab5] = 0xffffffc9;
  return;
}



/* 40a85cb4 FUN_40a85cb4 */

/* Boundary evidence: original MIPS .pdata 40a85cb4..40a86393. Semantic name remains unreviewed. */

void FUN_40a85cb4(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  longlong lVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  byte *pbVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint *puVar20;
  int local_38;
  
  if (*(int *)(param_1 + 0x6980) == 1) {
    iVar19 = (*(int *)(param_1 + 0x6984) + 1) * 4;
    if (0 < iVar19) goto LAB_40a85cf0;
LAB_40a85d8c:
    uVar9 = *(uint *)(param_1 + 0x6bdc);
    iVar16 = *(int *)(param_1 + 0x6bd8);
    pbVar14 = (byte *)(param_1 + iVar19 + 0x81ec);
    do {
      pbVar7 = (byte *)(iVar16 + ((int)uVar9 >> 3));
      *pbVar14 = (byte)((((uint)*pbVar7 << 0x18 | (uint)pbVar7[3] | (uint)pbVar7[2] << 8 |
                         (uint)pbVar7[1] << 0x10) << (uVar9 & 7)) >> 0x1c);
      uVar9 = uVar9 + 4;
      pbVar14 = pbVar14 + 1;
      *(uint *)(param_1 + 0x6bdc) = uVar9;
    } while (pbVar14 != (byte *)(param_1 + 0x820c));
    bVar5 = iVar19 < 0x20;
    if (0 < iVar19) {
      iVar18 = *(int *)(param_1 + 0x8c);
      goto LAB_40a85e00;
    }
  }
  else {
    iVar19 = 0x20;
LAB_40a85cf0:
    iVar18 = *(int *)(param_1 + 0x8c);
    iVar16 = 0;
    do {
      if (0 < iVar18) {
        uVar9 = *(uint *)(param_1 + 0x6bdc);
        iVar17 = *(int *)(param_1 + 0x6bd8);
        pbVar14 = (byte *)(param_1 + iVar16 + 0x81ec);
        iVar11 = 0;
        do {
          pbVar7 = (byte *)(iVar17 + ((int)uVar9 >> 3));
          uVar8 = uVar9 & 7;
          iVar11 = iVar11 + 1;
          uVar9 = uVar9 + 4;
          *pbVar14 = (byte)((((uint)*pbVar7 << 0x18 | (uint)pbVar7[3] | (uint)pbVar7[2] << 8 |
                             (uint)pbVar7[1] << 0x10) << uVar8) >> 0x1c);
          *(uint *)(param_1 + 0x6bdc) = uVar9;
          pbVar14 = pbVar14 + 0x20;
        } while (iVar11 < iVar18);
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < iVar19);
    bVar5 = false;
    if (iVar19 < 0x20) goto LAB_40a85d8c;
LAB_40a85e00:
    iVar16 = 0;
    do {
      if (0 < iVar18) {
        pcVar12 = (char *)(param_1 + iVar16 + 0x81ec);
        iVar11 = 0;
        do {
          iVar11 = iVar11 + 1;
          if (*pcVar12 != '\0') {
            uVar9 = *(uint *)(param_1 + 0x6bdc);
            pbVar14 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar9 >> 3));
            pcVar12[0x40] =
                 (byte)((((uint)*pbVar14 << 0x18 | (uint)pbVar14[3] | (uint)pbVar14[2] << 8 |
                         (uint)pbVar14[1] << 0x10) << (uVar9 & 7)) >> 0x1a);
            *(uint *)(param_1 + 0x6bdc) = uVar9 + 6;
          }
          pcVar12 = pcVar12 + 0x20;
        } while (iVar11 < iVar18);
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < iVar19);
    if (!bVar5) goto LAB_40a85f24;
  }
  pcVar12 = (char *)(param_1 + iVar19 + 0x81ec);
  do {
    while (*pcVar12 == '\0') {
      pcVar12 = pcVar12 + 1;
      if (pcVar12 == (char *)(param_1 + 0x820c)) goto LAB_40a85f24;
    }
    uVar8 = *(uint *)(param_1 + 0x6bdc);
    iVar16 = *(int *)(param_1 + 0x6bd8);
    pbVar14 = (byte *)(iVar16 + ((int)uVar8 >> 3));
    bVar1 = *pbVar14;
    bVar2 = pbVar14[3];
    bVar3 = pbVar14[2];
    bVar4 = pbVar14[1];
    uVar9 = uVar8 + 6;
    *(uint *)(param_1 + 0x6bdc) = uVar9;
    pcVar12[0x40] =
         (byte)((((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10) <<
                (uVar8 & 7)) >> 0x1a);
    pbVar14 = (byte *)(iVar16 + ((int)uVar9 >> 3));
    pcVar12[0x60] =
         (byte)((((uint)*pbVar14 << 0x18 | (uint)pbVar14[3] | (uint)pbVar14[2] << 8 |
                 (uint)pbVar14[1] << 0x10) << (uVar9 & 7)) >> 0x1a);
    pcVar12 = pcVar12 + 1;
    *(uint *)(param_1 + 0x6bdc) = uVar8 + 0xc;
  } while (pcVar12 != (char *)(param_1 + 0x820c));
LAB_40a85f24:
  local_38 = 0;
  do {
    if (iVar19 < 1) {
LAB_40a85fd4:
      puVar20 = (uint *)(param_1 + (local_38 * 0x20 + iVar19 + 0x15aa) * 4);
      pbVar14 = (byte *)(param_1 + iVar19 + 0x81ec);
      do {
        while (uVar9 = (uint)*pbVar14, uVar9 != 0) {
          uVar10 = *(uint *)(param_1 + 0x6bdc);
          pbVar7 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar10 >> 3));
          uVar15 = *(uint *)(&DAT_40a95020 + (uint)pbVar14[0x40] * 4);
          uVar13 = ((int)uVar15 >> 2) + uVar9;
          uVar8 = (((uint)*pbVar7 << 0x18 | (uint)pbVar7[3] | (uint)pbVar7[2] << 8 |
                   (uint)pbVar7[1] << 0x10) << (uVar10 & 7)) >> (0x20 - (uVar9 + 1) & 0x1f);
          *(uint *)(param_1 + 0x6bdc) = uVar9 + 1 + uVar10;
          uVar15 = uVar15 & 3;
          if ((int)uVar13 < 0x20) {
            iVar16 = (-1 << (uVar9 & 0x1f)) + 1 + uVar8;
            uVar8 = (int)((ulonglong)
                          ((longlong)iVar16 *
                          (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar15) * 4)) >>
                         0x20) << (0x20 - uVar13 & 0x1f) |
                    (uint)((longlong)iVar16 *
                          (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar15) * 4)) >>
                    (uVar13 & 0x1f);
            bVar1 = pbVar14[0x60];
          }
          else {
            iVar16 = (-1 << (uVar9 & 0x1f)) + 1 + uVar8;
            uVar8 = (uint)((ulonglong)
                           ((longlong)iVar16 *
                           (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar15) * 4)) >>
                          0x20) >> (uVar13 - 0x20 & 0x1f);
            bVar1 = pbVar14[0x60];
          }
          puVar20[-0x480] = uVar8;
          uVar10 = ((int)*(uint *)(&DAT_40a95020 + (uint)bVar1 * 4) >> 2) + uVar9;
          uVar8 = *(uint *)(&DAT_40a95020 + (uint)bVar1 * 4) & 3;
          if ((int)uVar10 < 0x20) {
            *puVar20 = (int)((ulonglong)
                             ((longlong)iVar16 *
                             (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar8) * 4)) >>
                            0x20) << (0x20 - uVar10 & 0x1f) |
                       (uint)((longlong)iVar16 *
                             (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar8) * 4)) >>
                       (uVar10 & 0x1f);
          }
          else {
            *puVar20 = (uint)((ulonglong)
                              ((longlong)iVar16 *
                              (longlong)*(int *)(&DAT_40a95120 + ((uVar9 - 1) * 3 + uVar8) * 4)) >>
                             0x20) >> (uVar10 - 0x20 & 0x1f);
          }
          pbVar14 = pbVar14 + 1;
          puVar20 = puVar20 + 1;
          if (pbVar14 == (byte *)(param_1 + 0x820c)) goto LAB_40a86168;
        }
        pbVar14 = pbVar14 + 1;
        puVar20[-0x480] = 0;
        *puVar20 = 0;
        puVar20 = puVar20 + 1;
      } while (pbVar14 != (byte *)(param_1 + 0x820c));
    }
    else {
      iVar18 = *(int *)(param_1 + 0x8c);
      iVar16 = 0;
      do {
        if (0 < iVar18) {
          pbVar14 = (byte *)(param_1 + iVar16 + 0x81ec);
          puVar20 = (uint *)(param_1 + (local_38 * 0x20 + iVar16 + 0x112a) * 4);
          iVar11 = 0;
          do {
            uVar8 = (uint)*pbVar14;
            uVar9 = 0;
            if (uVar8 != 0) {
              uVar10 = *(uint *)(param_1 + 0x6bdc);
              pbVar7 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar10 >> 3));
              bVar1 = *pbVar7;
              bVar2 = pbVar7[3];
              bVar3 = pbVar7[2];
              bVar4 = pbVar7[1];
              uVar9 = *(uint *)(&DAT_40a95020 + (uint)pbVar14[0x40] * 4);
              uVar13 = ((int)uVar9 >> 2) + uVar8;
              *(uint *)(param_1 + 0x6bdc) = uVar8 + 1 + uVar10;
              iVar17 = (-1 << (uVar8 & 0x1f)) + 1 +
                       ((((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10
                         ) << (uVar10 & 7)) >> (0x20 - (uVar8 + 1) & 0x1f));
              if ((int)uVar13 < 0x20) {
                lVar6 = (longlong)iVar17 *
                        (longlong)*(int *)(&DAT_40a95120 + ((uVar8 - 1) * 3 + (uVar9 & 3)) * 4);
                uVar9 = (int)((ulonglong)lVar6 >> 0x20) << (0x20 - uVar13 & 0x1f) |
                        (uint)lVar6 >> (uVar13 & 0x1f);
              }
              else {
                uVar9 = (uint)((ulonglong)
                               ((longlong)iVar17 *
                               (longlong)
                               *(int *)(&DAT_40a95120 + ((uVar8 - 1) * 3 + (uVar9 & 3)) * 4)) >>
                              0x20) >> (uVar13 - 0x20 & 0x1f);
              }
            }
            iVar11 = iVar11 + 1;
            *puVar20 = uVar9;
            pbVar14 = pbVar14 + 0x20;
            puVar20 = puVar20 + 0x480;
          } while (iVar11 < iVar18);
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < iVar19);
      if (iVar19 < 0x20) goto LAB_40a85fd4;
    }
LAB_40a86168:
    local_38 = local_38 + 1;
    if (local_38 == 0xc) {
      return;
    }
  } while( true );
}



/* 40a86394 FUN_40a86394 */

/* Boundary evidence: original MIPS .pdata 40a86394..40a877a7. Semantic name remains unreviewed. */

undefined4 FUN_40a86394(int param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  longlong lVar5;
  undefined1 uVar6;
  bool bVar7;
  byte bVar8;
  byte bVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  undefined4 *puVar17;
  uint uVar18;
  undefined4 *puVar19;
  int iVar20;
  undefined1 *puVar21;
  char *pcVar22;
  byte *pbVar23;
  uint uVar24;
  uint uVar25;
  uint *puVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  int iVar32;
  byte *pbVar33;
  int iVar34;
  undefined *puVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_4c;
  
  iVar34 = *(int *)(param_1 + 0x8c);
  iVar16 = *(int *)(param_1 + 0x88);
  if (*(int *)(param_1 + 100) != 0) {
    iVar16 = 4;
    goto LAB_40a86448;
  }
  iVar39 = (*(int *)(param_1 + 0x698c) / 1000) / iVar34;
  if (iVar34 == 0) {
    trap(7);
  }
  if (((iVar16 == 48000) && (0x37 < iVar39)) || (iVar39 - 0x38U < 0x19)) {
    iVar16 = 0;
    goto LAB_40a86448;
  }
  if (iVar16 == 48000) {
LAB_40a87790:
    if (iVar39 < 0x31) {
      iVar16 = 2;
      goto LAB_40a86448;
    }
  }
  else {
    if (0x5f < iVar39) {
      iVar16 = 1;
      goto LAB_40a86448;
    }
    if (iVar16 != 32000) goto LAB_40a87790;
  }
  iVar16 = 3;
LAB_40a86448:
  iVar39 = (&DAT_40aa0510)[iVar16];
  puVar35 = (&PTR_DAT_40aa61f0)[iVar16];
  local_54 = iVar39;
  if (*(int *)(param_1 + 0x6980) == 1) {
    local_54 = (*(int *)(param_1 + 0x6984) + 1) * 4;
  }
  iVar16 = 0;
  if (0 < local_54) {
    iVar32 = 0;
    do {
      uVar25 = *(uint *)(puVar35 + iVar16 * 4);
      if (0 < iVar34) {
        uVar29 = *(uint *)(param_1 + 0x6bdc);
        iVar36 = *(int *)(param_1 + 0x6bd8);
        puVar21 = (undefined1 *)(param_1 + iVar32 + 0x826c);
        iVar20 = 0;
        do {
          pbVar10 = (byte *)(iVar36 + ((int)uVar29 >> 3));
          uVar11 = uVar29 & 7;
          iVar20 = iVar20 + 1;
          uVar29 = uVar25 + uVar29;
          *puVar21 = (char)((((uint)*pbVar10 << 0x18 | (uint)pbVar10[3] | (uint)pbVar10[2] << 8 |
                             (uint)pbVar10[1] << 0x10) << uVar11) >> (0x20 - uVar25 & 0x1f));
          *(uint *)(param_1 + 0x6bdc) = uVar29;
          puVar21 = puVar21 + 0x20;
        } while (iVar20 < iVar34);
      }
      iVar32 = iVar32 + 1;
      iVar16 = iVar16 + (1 << (uVar25 & 0x1f));
    } while (iVar32 < local_54);
  }
  if (local_54 < iVar39) {
    uVar25 = *(uint *)(param_1 + 0x6bdc);
    iVar32 = *(int *)(param_1 + 0x6bd8);
    puVar21 = (undefined1 *)(param_1 + local_54 + 0x826c);
    do {
      pbVar10 = (byte *)(iVar32 + ((int)uVar25 >> 3));
      uVar29 = *(uint *)(puVar35 + iVar16 * 4);
      uVar6 = (undefined1)
              ((((uint)*pbVar10 << 0x18 | (uint)pbVar10[3] | (uint)pbVar10[2] << 8 |
                (uint)pbVar10[1] << 0x10) << (uVar25 & 7)) >> (0x20 - uVar29 & 0x1f));
      uVar25 = uVar29 + uVar25;
      puVar21[0x20] = uVar6;
      *puVar21 = uVar6;
      puVar21 = puVar21 + 1;
      iVar16 = iVar16 + (1 << (uVar29 & 0x1f));
      *(uint *)(param_1 + 0x6bdc) = uVar25;
    } while (puVar21 != (undefined1 *)(param_1 + iVar39 + 0x826c));
  }
  if (0 < iVar39) {
    iVar16 = 0;
    do {
      if (0 < iVar34) {
        pcVar22 = (char *)(param_1 + iVar16 + 0x826c);
        iVar32 = 0;
        do {
          iVar32 = iVar32 + 1;
          if (*pcVar22 != '\0') {
            uVar25 = *(uint *)(param_1 + 0x6bdc);
            pbVar10 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
            pcVar22[0x40] =
                 (byte)((((uint)*pbVar10 << 0x18 | (uint)pbVar10[3] | (uint)pbVar10[2] << 8 |
                         (uint)pbVar10[1] << 0x10) << (uVar25 & 7)) >> 0x1e);
            *(uint *)(param_1 + 0x6bdc) = uVar25 + 2;
          }
          pcVar22 = pcVar22 + 0x20;
        } while (iVar32 < iVar34);
      }
      iVar16 = iVar16 + 1;
    } while (iVar16 < iVar39);
    pbVar10 = (byte *)(param_1 + 0x82ec);
    iVar16 = 0;
    do {
      if (0 < iVar34) {
        pcVar22 = (char *)(param_1 + iVar16 + 0x826c);
        iVar32 = 0;
        pbVar23 = pbVar10;
        do {
          if (*pcVar22 != '\0') {
            cVar1 = pcVar22[0x40];
            if (cVar1 == '\x02') {
              uVar25 = *(uint *)(param_1 + 0x6bdc);
              pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
              bVar9 = *pbVar12;
              bVar8 = pbVar12[3];
              bVar2 = pbVar12[2];
              bVar3 = pbVar12[1];
              *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
              bVar9 = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                              (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x18);
              bVar8 = bVar9 >> 2;
              pbVar23[2] = bVar8;
              *pbVar23 = bVar8;
              pbVar23[1] = bVar9 >> 2;
              iVar34 = *(int *)(param_1 + 0x8c);
            }
            else if (cVar1 == '\x03') {
              uVar25 = *(uint *)(param_1 + 0x6bdc);
              pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
              bVar9 = *pbVar12;
              bVar8 = pbVar12[3];
              bVar2 = pbVar12[2];
              bVar3 = pbVar12[1];
              *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
              *pbVar23 = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                 (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
              uVar25 = *(uint *)(param_1 + 0x6bdc);
              pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
              bVar9 = *pbVar12;
              bVar8 = pbVar12[3];
              bVar2 = pbVar12[2];
              bVar3 = pbVar12[1];
              *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
              bVar9 = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                              (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
              pbVar23[2] = bVar9;
              pbVar23[1] = bVar9;
              iVar34 = *(int *)(param_1 + 0x8c);
            }
            else {
              if (cVar1 == '\x01') {
                uVar25 = *(uint *)(param_1 + 0x6bdc);
                pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
                bVar9 = *pbVar12;
                bVar8 = pbVar12[3];
                bVar2 = pbVar12[2];
                bVar3 = pbVar12[1];
                *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
                bVar9 = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
                pbVar23[1] = bVar9;
                *pbVar23 = bVar9;
              }
              else {
                uVar25 = *(uint *)(param_1 + 0x6bdc);
                pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
                bVar9 = *pbVar12;
                bVar8 = pbVar12[3];
                bVar2 = pbVar12[2];
                bVar3 = pbVar12[1];
                *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
                *pbVar23 = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                   (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
                uVar25 = *(uint *)(param_1 + 0x6bdc);
                pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
                bVar9 = *pbVar12;
                bVar8 = pbVar12[3];
                bVar2 = pbVar12[2];
                bVar3 = pbVar12[1];
                *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
                pbVar23[1] = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                     (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
              }
              uVar25 = *(uint *)(param_1 + 0x6bdc);
              pbVar12 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar25 >> 3));
              bVar9 = *pbVar12;
              bVar8 = pbVar12[3];
              bVar2 = pbVar12[2];
              bVar3 = pbVar12[1];
              *(uint *)(param_1 + 0x6bdc) = uVar25 + 6;
              pbVar23[2] = (byte)((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                   (uint)bVar3 << 0x10) << (uVar25 & 7)) >> 0x1a);
              iVar34 = *(int *)(param_1 + 0x8c);
            }
          }
          iVar32 = iVar32 + 1;
          pcVar22 = pcVar22 + 0x20;
          pbVar23 = pbVar23 + 0x60;
        } while (iVar32 < iVar34);
      }
      iVar16 = iVar16 + 1;
      pbVar10 = pbVar10 + 3;
    } while (iVar16 < iVar39);
  }
  pbVar10 = (byte *)(param_1 + local_54 + 0x826c);
  local_4c = 0;
  local_60 = 2;
  do {
    pbVar23 = (byte *)(param_1 + local_54 * 3 + local_4c + 0x82ec);
    local_58 = local_60 + -2;
    iVar16 = local_60 + 0xc;
    local_5c = local_60;
    do {
      iVar32 = 0;
      if (0 < local_54) {
        iVar20 = 0;
        do {
          uVar25 = *(uint *)(puVar35 + iVar32 * 4);
          if (0 < iVar34) {
            pbVar12 = (byte *)(param_1 + iVar20 + 0x826c);
            puVar26 = (uint *)(param_1 + ((local_5c + -2) * 0x20 + iVar20 + 0x112a) * 4);
            pbVar33 = (byte *)(param_1 + iVar20 * 3 + local_4c + 0x82ec);
            iVar36 = 0;
            do {
              if (*pbVar12 == 0) {
                *puVar26 = 0;
                puVar26[0x20] = 0;
                puVar26[0x40] = 0;
              }
              else {
                iVar28 = *(int *)(&DAT_40aa0568 +
                                 *(int *)(puVar35 + (iVar32 + (uint)*pbVar12) * 4) * 4);
                if (iVar28 < 0) {
                  iVar38 = *(int *)(&DAT_40aa0524 +
                                   *(int *)(puVar35 + (iVar32 + (uint)*pbVar12) * 4) * 4);
                  uVar29 = *(uint *)(param_1 + 0x6bdc);
                  pbVar13 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar29 >> 3));
                  uVar11 = (int)*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) >> 2;
                  bVar9 = *pbVar13;
                  bVar8 = pbVar13[3];
                  bVar2 = pbVar13[2];
                  bVar3 = pbVar13[1];
                  iVar37 = *(int *)(&DAT_40aa0dec +
                                   ((iVar38 >> 2) * 3 +
                                   (*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) & 3)) * 4);
                  *(uint *)(param_1 + 0x6bdc) = uVar29 - iVar28;
                  if ((int)uVar11 < 0x20) {
                    uVar29 = (((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                              (uint)bVar3 << 0x10) << (uVar29 & 7)) >> (iVar28 + 0x20U & 0x1f);
                    iVar28 = (int)uVar29 / iVar38;
                    if (iVar38 == 0) {
                      trap(7);
                    }
                    iVar14 = iVar38 >> 1;
                    uVar29 = ((int)uVar29 % iVar38 - iVar14) * iVar37;
                    if ((int)uVar11 < 1) {
                      if (iVar38 == 0) {
                        trap(7);
                      }
                      *puVar26 = uVar29;
                      puVar26[0x20] = (iVar28 % iVar38 - iVar14) * iVar37;
                      iVar37 = (iVar28 / iVar38 - iVar14) * iVar37;
                    }
                    else {
                      if (iVar38 == 0) {
                        trap(7);
                      }
                      *puVar26 = (int)uVar29 >> (uVar11 & 0x1f);
                      puVar26[0x20] = (iVar28 % iVar38 - iVar14) * iVar37 >> (uVar11 & 0x1f);
                      iVar37 = (iVar28 / iVar38 - iVar14) * iVar37 >> (uVar11 & 0x1f);
                    }
                  }
                  else {
                    *puVar26 = 0;
                    puVar26[0x20] = 0;
                    iVar37 = 0;
                  }
                  *(int *)(param_1 + ((iVar36 * 0x24 + local_5c) * 0x20 + iVar20 + 0x112a) * 4) =
                       iVar37;
                }
                else {
                  uVar29 = (iVar28 - 1U) + ((int)*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) >> 2)
                  ;
                  iVar37 = (-1 << (iVar28 - 1U & 0x1f)) + 1;
                  iVar38 = *(int *)(&DAT_40a95120 +
                                   ((iVar28 + -2) * 3 +
                                   (*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) & 3)) * 4);
                  uVar11 = 0x20 - iVar28;
                  if ((int)uVar29 < 0x20) {
                    uVar18 = *(uint *)(param_1 + 0x6bdc);
                    pbVar13 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar18 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[2];
                    bVar3 = pbVar13[1];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar18;
                    uVar24 = 0x20 - uVar29;
                    lVar5 = (longlong)
                            (int)(((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                    (uint)bVar3 << 0x10) << (uVar18 & 7)) >> (uVar11 & 0x1f)) +
                                 iVar37) * (longlong)iVar38;
                    uVar18 = *(uint *)(param_1 + 0x6bdc);
                    iVar14 = *(int *)(param_1 + 0x6bd8);
                    *puVar26 = (int)((ulonglong)lVar5 >> 0x20) << (uVar24 & 0x1f) |
                               (uint)lVar5 >> (uVar29 & 0x1f);
                    pbVar13 = (byte *)(iVar14 + ((int)uVar18 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[2];
                    bVar3 = pbVar13[1];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar18;
                    lVar5 = (longlong)
                            (int)(((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                    (uint)bVar3 << 0x10) << (uVar18 & 7)) >> (uVar11 & 0x1f)) +
                                 iVar37) * (longlong)iVar38;
                    uVar18 = *(uint *)(param_1 + 0x6bdc);
                    iVar14 = *(int *)(param_1 + 0x6bd8);
                    puVar26[0x20] =
                         (int)((ulonglong)lVar5 >> 0x20) << (uVar24 & 0x1f) |
                         (uint)lVar5 >> (uVar29 & 0x1f);
                    pbVar13 = (byte *)(iVar14 + ((int)uVar18 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[1];
                    bVar3 = pbVar13[2];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar18;
                    lVar5 = (longlong)
                            (int)(iVar37 + ((((uint)bVar8 | (uint)bVar9 << 0x18 |
                                              (uint)bVar2 << 0x10 | (uint)bVar3 << 8) <<
                                            (uVar18 & 7)) >> (uVar11 & 0x1f))) * (longlong)iVar38;
                    puVar26[0x40] =
                         (int)((ulonglong)lVar5 >> 0x20) << (uVar24 & 0x1f) |
                         (uint)lVar5 >> (uVar29 & 0x1f);
                  }
                  else {
                    uVar18 = *(uint *)(param_1 + 0x6bdc);
                    pbVar13 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar18 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[2];
                    bVar3 = pbVar13[1];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar18;
                    uVar29 = uVar29 - 0x20;
                    uVar24 = *(uint *)(param_1 + 0x6bdc);
                    iVar14 = *(int *)(param_1 + 0x6bd8);
                    *puVar26 = (uint)((ulonglong)
                                      ((longlong)
                                       (int)(((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8
                                               | (uint)bVar3 << 0x10) << (uVar18 & 7)) >>
                                             (uVar11 & 0x1f)) + iVar37) * (longlong)iVar38) >> 0x20)
                               >> (uVar29 & 0x1f);
                    pbVar13 = (byte *)(iVar14 + ((int)uVar24 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[2];
                    bVar3 = pbVar13[1];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar24;
                    uVar18 = *(uint *)(param_1 + 0x6bdc);
                    iVar14 = *(int *)(param_1 + 0x6bd8);
                    puVar26[0x20] =
                         (uint)((ulonglong)
                                ((longlong)
                                 (int)(((((uint)bVar9 << 0x18 | (uint)bVar8 | (uint)bVar2 << 8 |
                                         (uint)bVar3 << 0x10) << (uVar24 & 7)) >> (uVar11 & 0x1f)) +
                                      iVar37) * (longlong)iVar38) >> 0x20) >> (uVar29 & 0x1f);
                    pbVar13 = (byte *)(iVar14 + ((int)uVar18 >> 3));
                    bVar9 = *pbVar13;
                    bVar8 = pbVar13[3];
                    bVar2 = pbVar13[2];
                    bVar3 = pbVar13[1];
                    *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar18;
                    puVar26[0x40] =
                         (uint)((ulonglong)
                                ((longlong)
                                 (int)(iVar37 + ((((uint)bVar9 << 0x18 | (uint)bVar8 |
                                                   (uint)bVar2 << 8 | (uint)bVar3 << 0x10) <<
                                                 (uVar18 & 7)) >> (uVar11 & 0x1f))) *
                                (longlong)iVar38) >> 0x20) >> (uVar29 & 0x1f);
                  }
                }
              }
              iVar36 = iVar36 + 1;
              pbVar12 = pbVar12 + 0x20;
              puVar26 = puVar26 + 0x480;
              pbVar33 = pbVar33 + 0x60;
            } while (iVar36 < iVar34);
          }
          iVar20 = iVar20 + 1;
          iVar32 = iVar32 + (1 << (uVar25 & 0x1f));
        } while (iVar20 < local_54);
      }
      if (local_54 < iVar39) {
        puVar26 = (uint *)(param_1 + (local_60 * 0x20 + local_54 + 0x15aa) * 4);
        uVar29 = (uint)*pbVar10;
        uVar25 = *(uint *)(puVar35 + iVar32 * 4);
        pbVar12 = pbVar10;
        pbVar33 = pbVar23;
        if (uVar29 == 0) goto LAB_40a86e3c;
        do {
          uVar11 = *(uint *)(&DAT_40aa0568 + *(int *)(puVar35 + (iVar32 + uVar29) * 4) * 4);
          bVar9 = pbVar33[0x60];
          if ((int)uVar11 < 0) {
            uVar18 = *(uint *)(param_1 + 0x6bdc);
            pbVar13 = (byte *)(*(int *)(param_1 + 0x6bd8) + ((int)uVar18 >> 3));
            iVar20 = *(int *)(&DAT_40aa0524 + *(int *)(puVar35 + (iVar32 + uVar29) * 4) * 4);
            uVar29 = (((uint)*pbVar13 << 0x18 | (uint)pbVar13[3] | (uint)pbVar13[2] << 8 |
                      (uint)pbVar13[1] << 0x10) << (uVar18 & 7)) >> (uVar11 & 0x1f);
            iVar36 = (int)uVar29 / iVar20;
            if (iVar20 == 0) {
              trap(7);
            }
            uVar24 = *(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4);
            uVar27 = (int)uVar24 >> 2;
            iVar28 = iVar20 >> 1;
            bVar4 = (int)uVar27 < 0x20;
            *(uint *)(param_1 + 0x6bdc) = uVar18 - uVar11;
            iVar38 = *(int *)(&DAT_40aa0dec + ((iVar20 >> 2) * 3 + (uVar24 & 3)) * 4);
            iVar37 = (int)uVar29 % iVar20 - iVar28;
            if (bVar4) {
              uVar29 = iVar37 * iVar38;
              if (0 < (int)uVar27) {
                uVar29 = (int)uVar29 >> (uVar27 & 0x1f);
              }
            }
            else {
              uVar29 = 0;
            }
            uVar11 = *(uint *)(&DAT_40a95020 + (uint)bVar9 * 4);
            uVar18 = (int)uVar11 >> 2;
            bVar7 = (int)uVar18 < 0x20;
            puVar26[-0x4c0] = uVar29;
            iVar14 = *(int *)(&DAT_40aa0dec + ((iVar20 >> 2) * 3 + (uVar11 & 3)) * 4);
            if (bVar7) {
              uVar29 = iVar37 * iVar14;
              if (iVar20 == 0) {
                trap(7);
              }
              if (0 < (int)uVar18) {
                uVar29 = (int)uVar29 >> (uVar18 & 0x1f);
              }
              puVar26[-0x40] = uVar29;
              iVar37 = iVar36 % iVar20 - iVar28;
              if (bVar4) goto LAB_40a874f8;
LAB_40a8740c:
              puVar26[-0x4a0] = 0;
              if (!bVar7) goto LAB_40a87418;
LAB_40a87510:
              if (iVar20 == 0) {
                trap(7);
              }
              uVar29 = iVar37 * iVar14;
              if (0 < (int)uVar18) {
                uVar29 = iVar37 * iVar14 >> (uVar18 & 0x1f);
              }
              puVar26[-0x20] = uVar29;
              iVar28 = iVar36 / iVar20 - iVar28;
              if (bVar4) goto LAB_40a87548;
LAB_40a87444:
              puVar26[-0x480] = 0;
              if (!bVar7) goto LAB_40a87450;
LAB_40a87560:
              uVar29 = iVar28 * iVar14;
              if (0 < (int)uVar18) {
                uVar29 = iVar28 * iVar14 >> (uVar18 & 0x1f);
              }
              *puVar26 = uVar29;
            }
            else {
              if (iVar20 == 0) {
                trap(7);
              }
              puVar26[-0x40] = 0;
              iVar37 = iVar36 % iVar20 - iVar28;
              if (!bVar4) goto LAB_40a8740c;
LAB_40a874f8:
              uVar29 = iVar37 * iVar38;
              if (0 < (int)uVar27) {
                uVar29 = iVar37 * iVar38 >> (uVar27 & 0x1f);
              }
              puVar26[-0x4a0] = uVar29;
              if (bVar7) goto LAB_40a87510;
LAB_40a87418:
              if (iVar20 == 0) {
                trap(7);
              }
              puVar26[-0x20] = 0;
              iVar28 = iVar36 / iVar20 - iVar28;
              if (!bVar4) goto LAB_40a87444;
LAB_40a87548:
              uVar29 = iVar28 * iVar38;
              if (0 < (int)uVar27) {
                uVar29 = iVar28 * iVar38 >> (uVar27 & 0x1f);
              }
              puVar26[-0x480] = uVar29;
              if (bVar7) goto LAB_40a87560;
LAB_40a87450:
              *puVar26 = 0;
            }
          }
          else {
            uVar30 = *(uint *)(param_1 + 0x6bdc);
            iVar37 = *(int *)(param_1 + 0x6bd8);
            pbVar13 = (byte *)(iVar37 + ((int)uVar30 >> 3));
            iVar20 = (uVar11 - 2) * 3;
            uVar29 = uVar11 - 1;
            uVar27 = uVar29 + ((int)*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) >> 2);
            uVar24 = uVar11 + uVar30;
            uVar31 = 0x20 - uVar11;
            bVar4 = 0x1f < (int)uVar27;
            uVar18 = uVar29 + ((int)*(uint *)(&DAT_40a95020 + (uint)bVar9 * 4) >> 2);
            iVar36 = (-1 << (uVar29 & 0x1f)) + 1;
            iVar28 = *(int *)(&DAT_40a95120 +
                             (iVar20 + (*(uint *)(&DAT_40a95020 + (uint)*pbVar33 * 4) & 3)) * 4);
            iVar20 = *(int *)(&DAT_40a95120 +
                             (iVar20 + (*(uint *)(&DAT_40a95020 + (uint)bVar9 * 4) & 3)) * 4);
            uVar29 = (((uint)*pbVar13 << 0x18 | (uint)pbVar13[3] | (uint)pbVar13[2] << 8 |
                      (uint)pbVar13[1] << 0x10) << (uVar30 & 7)) >> (uVar31 & 0x1f);
            *(uint *)(param_1 + 0x6bdc) = uVar24;
            if (bVar4) {
              uVar30 = (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar28) >>
                             0x20) >> (uVar27 - 0x20 & 0x1f);
            }
            else {
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar28;
              uVar30 = (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar27 & 0x1f) |
                       (uint)lVar5 >> (uVar27 & 0x1f);
            }
            bVar7 = 0x1f < (int)uVar18;
            puVar26[-0x4c0] = uVar30;
            if (bVar7) {
              uVar29 = (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar20) >>
                             0x20) >> (uVar18 - 0x20 & 0x1f);
            }
            else {
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar20;
              uVar29 = (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar18 & 0x1f) |
                       (uint)lVar5 >> (uVar18 & 0x1f);
            }
            pbVar13 = (byte *)(iVar37 + ((int)uVar24 >> 3));
            puVar26[-0x40] = uVar29;
            uVar30 = uVar11 + uVar24;
            uVar29 = (((uint)*pbVar13 << 0x18 | (uint)pbVar13[3] | (uint)pbVar13[2] << 8 |
                      (uint)pbVar13[1] << 0x10) << (uVar24 & 7)) >> (uVar31 & 0x1f);
            *(uint *)(param_1 + 0x6bdc) = uVar30;
            if (bVar4) {
              puVar26[-0x4a0] =
                   (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar28) >> 0x20)
                   >> (uVar27 - 0x20 & 0x1f);
              if (bVar7) goto LAB_40a870bc;
LAB_40a86d28:
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar20;
              uVar29 = (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar18 & 0x1f) |
                       (uint)lVar5 >> (uVar18 & 0x1f);
            }
            else {
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar28;
              puVar26[-0x4a0] =
                   (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar27 & 0x1f) |
                   (uint)lVar5 >> (uVar27 & 0x1f);
              if (!bVar7) goto LAB_40a86d28;
LAB_40a870bc:
              uVar29 = (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar20) >>
                             0x20) >> (uVar18 - 0x20 & 0x1f);
            }
            pbVar13 = (byte *)(iVar37 + ((int)uVar30 >> 3));
            puVar26[-0x20] = uVar29;
            uVar29 = (((uint)*pbVar13 << 0x18 | (uint)pbVar13[3] | (uint)pbVar13[2] << 8 |
                      (uint)pbVar13[1] << 0x10) << (uVar30 & 7)) >> (uVar31 & 0x1f);
            *(uint *)(param_1 + 0x6bdc) = uVar11 + uVar30;
            if (bVar4) {
              uVar11 = (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar28) >>
                             0x20) >> (uVar27 - 0x20 & 0x1f);
            }
            else {
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar28;
              uVar11 = (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar27 & 0x1f) |
                       (uint)lVar5 >> (uVar27 & 0x1f);
            }
            puVar26[-0x480] = uVar11;
            if (bVar7) {
              *puVar26 = (uint)((ulonglong)((longlong)(int)(uVar29 + iVar36) * (longlong)iVar20) >>
                               0x20) >> (uVar18 - 0x20 & 0x1f);
            }
            else {
              lVar5 = (longlong)(int)(uVar29 + iVar36) * (longlong)iVar20;
              *puVar26 = (int)((ulonglong)lVar5 >> 0x20) << (0x20 - uVar18 & 0x1f) |
                         (uint)lVar5 >> (uVar18 & 0x1f);
            }
          }
          while( true ) {
            pbVar12 = pbVar12 + 1;
            if (pbVar12 == (byte *)(param_1 + iVar39 + 0x826c)) goto LAB_40a86e68;
            pbVar33 = pbVar33 + 3;
            puVar26 = puVar26 + 1;
            iVar32 = iVar32 + (1 << (uVar25 & 0x1f));
            uVar29 = (uint)*pbVar12;
            uVar25 = *(uint *)(puVar35 + iVar32 * 4);
            if (uVar29 != 0) break;
LAB_40a86e3c:
            puVar26[-0x4c0] = 0;
            puVar26[-0x4a0] = 0;
            puVar26[-0x480] = 0;
            puVar26[-0x40] = 0;
            puVar26[-0x20] = 0;
            *puVar26 = 0;
          }
        } while( true );
      }
LAB_40a86e68:
      if (iVar39 < 0x20) {
        iVar32 = iVar39;
        do {
          if (0 < iVar34) {
            puVar17 = (undefined4 *)(param_1 + ((local_58 + 1) * 0x20 + iVar32 + 0x112a) * 4);
            puVar19 = (undefined4 *)(param_1 + (local_58 * 0x20 + iVar32 + 0x112a) * 4);
            puVar15 = (undefined4 *)(param_1 + ((local_58 + 2) * 0x20 + iVar32 + 0x112a) * 4);
            iVar20 = 0;
            do {
              iVar20 = iVar20 + 1;
              *puVar19 = 0;
              *puVar17 = 0;
              puVar19 = puVar19 + 0x480;
              *puVar15 = 0;
              puVar17 = puVar17 + 0x480;
              puVar15 = puVar15 + 0x480;
            } while (iVar20 < iVar34);
          }
          iVar32 = iVar32 + 1;
        } while (iVar32 < 0x20);
      }
      local_5c = local_5c + 3;
      local_60 = local_60 + 3;
      local_58 = local_58 + 3;
    } while (iVar16 != local_5c);
    local_4c = local_4c + 1;
    local_60 = iVar16;
    if (local_4c == 3) {
      return 0x24;
    }
  } while( true );
}



/* 40a87810 FUN_40a87810 */

/* Boundary evidence: original MIPS .pdata 40a87810..40a883b3. Semantic name remains unreviewed. */

undefined4 FUN_40a87810(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  longlong lVar7;
  uint *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  int iVar11;
  byte *pbVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint *puVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint *puVar28;
  int iVar29;
  uint *puVar30;
  int iVar31;
  undefined4 local_38;
  
  iVar18 = 0;
  iVar26 = param_1;
  do {
    iVar23 = *(int *)(iVar26 + 0x3c);
    if (iVar23 != 0) {
      iVar11 = param_4 + (*(int *)(&DAT_40aa074c + *(int *)(iVar26 + 0x24) * 8) + 0x1075) * 8;
      iVar27 = *(int *)(&DAT_40aa0750 + *(int *)(iVar26 + 0x24) * 8);
      iVar25 = *(int *)(param_4 + (*(int *)(&DAT_40aa074c + *(int *)(iVar26 + 0x24) * 8) + 0x210e) *
                                  4 + 4);
      if (0 < iVar23) {
        uVar19 = *(uint *)(param_4 + 0x6bdc);
        if ((int)uVar19 < param_3) {
          iVar20 = iVar18 + 1;
          puVar22 = (uint *)(param_1 + (iVar18 + 0x3c) * 4 + 4);
          puVar17 = (uint *)(param_2 + iVar20 * 4);
          puVar14 = (uint *)(param_2 + iVar18 * 4);
          do {
            if (iVar25 == 0) {
              *puVar22 = 0;
LAB_40a87918:
              uVar19 = 0;
            }
            else {
              iVar24 = *(int *)(param_4 + 0x6bd8);
              pbVar12 = (byte *)(iVar24 + ((int)uVar19 >> 3));
              iVar18 = *(int *)(iVar11 + 4);
              iVar31 = *(int *)(iVar11 + 8);
              piVar10 = (int *)(iVar31 + ((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                            (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10) <<
                                          (uVar19 & 7)) >> (0x20U - iVar18 & 0x1f)) * 8);
              uVar16 = piVar10[1];
              iVar29 = *piVar10;
              uVar21 = uVar16;
              if ((int)uVar16 < 0) {
                uVar19 = uVar19 + iVar18;
                pbVar12 = (byte *)(iVar24 + ((int)uVar19 >> 3));
                piVar10 = (int *)(iVar31 + (((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                               (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10) <<
                                             (uVar19 & 7)) >> (uVar16 & 0x1f)) + iVar29) * 8);
                uVar21 = piVar10[1];
                iVar29 = *piVar10;
                if ((int)uVar21 < 0) {
                  uVar19 = uVar19 - uVar16;
                  pbVar12 = (byte *)(iVar24 + ((int)uVar19 >> 3));
                  piVar10 = (int *)(iVar31 + (((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                                 (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10)
                                               << (uVar19 & 7)) >> (uVar21 & 0x1f)) + iVar29) * 8);
                  uVar21 = piVar10[1];
                  iVar29 = *piVar10;
                }
              }
              uVar21 = uVar21 + uVar19;
              *(uint *)(param_4 + 0x6bdc) = uVar21;
              if (iVar29 < 0) {
                return 0xfffffffd;
              }
              bVar1 = *(byte *)(iVar25 + iVar29);
              iVar18 = (int)(uint)bVar1 >> 4;
              uVar19 = bVar1 & 0xf;
              if (iVar18 == 0) {
                uVar21 = 0;
              }
              else {
                if ((iVar18 == 0xf) && (iVar27 != 0)) {
                  pbVar12 = (byte *)(iVar24 + ((int)uVar21 >> 3));
                  bVar2 = *pbVar12;
                  bVar3 = pbVar12[3];
                  bVar4 = pbVar12[2];
                  bVar5 = pbVar12[1];
                  *(uint *)(param_4 + 0x6bdc) = uVar21 + iVar27;
                  iVar18 = ((((uint)bVar2 << 0x18 | (uint)bVar3 | (uint)bVar4 << 8 |
                             (uint)bVar5 << 0x10) << (uVar21 & 7)) >> (0x20U - iVar27 & 0x1f)) + 0xf
                  ;
                }
                uVar21 = *puVar14;
                uVar16 = (0x17 - ((int)uVar21 >> 2)) - (int)(char)(&DAT_40a95d10)[iVar18];
                if ((int)uVar16 < 0x20) {
                  lVar7 = (longlong)*(int *)(&DAT_40a97d20 + iVar18 * 4) *
                          (longlong)*(int *)(&DAT_40aa0e10 + (uVar21 & 3) * 4);
                  uVar21 = (int)((ulonglong)lVar7 >> 0x20) << (0x20 - uVar16 & 0x1f) |
                           (uint)lVar7 >> (uVar16 & 0x1f);
                  uVar16 = *(uint *)(param_4 + 0x6bdc);
                }
                else if ((int)uVar16 < 0x40) {
                  uVar21 = (uint)((ulonglong)
                                  ((longlong)*(int *)(&DAT_40a97d20 + iVar18 * 4) *
                                  (longlong)*(int *)(&DAT_40aa0e10 + (uVar21 & 3) * 4)) >> 0x20) >>
                           (uVar16 - 0x20 & 0x1f);
                  uVar16 = *(uint *)(param_4 + 0x6bdc);
                }
                else {
                  uVar21 = 0;
                  uVar16 = *(uint *)(param_4 + 0x6bdc);
                }
                if (((uint)*(byte *)(iVar24 + ((int)uVar16 >> 3)) << (uVar16 & 7) & 0xff) >> 7 != 0)
                {
                  uVar21 = -uVar21;
                }
                *(uint *)(param_4 + 0x6bdc) = uVar16 + 1;
              }
              *puVar22 = uVar21;
              if ((bVar1 & 0xf) == 0) goto LAB_40a87918;
              if ((uVar19 == 0xf) && (iVar27 != 0)) {
                uVar19 = *(uint *)(param_4 + 0x6bdc);
                pbVar12 = (byte *)(iVar24 + ((int)uVar19 >> 3));
                uVar13 = uVar19 + iVar27;
                uVar19 = (((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] | (uint)pbVar12[2] << 8 |
                          (uint)pbVar12[1] << 0x10) << (uVar19 & 7)) >> (0x20U - iVar27 & 0x1f);
                *(uint *)(param_4 + 0x6bdc) = uVar13;
                uVar21 = *puVar17;
                uVar16 = (0x17 - ((int)uVar21 >> 2)) - (int)(char)(&DAT_40a95d1f)[uVar19];
                iVar18 = *(int *)(&DAT_40a97d20 + (uVar19 + 0xf) * 4);
                if (0x1f < (int)uVar16) goto LAB_40a87f6c;
LAB_40a8803c:
                uVar19 = (int)((ulonglong)
                               ((longlong)iVar18 *
                               (longlong)*(int *)(&DAT_40aa0e10 + (uVar21 & 3) * 4)) >> 0x20) <<
                         (0x20 - uVar16 & 0x1f) |
                         (uint)((longlong)iVar18 *
                               (longlong)*(int *)(&DAT_40aa0e10 + (uVar21 & 3) * 4)) >>
                         (uVar16 & 0x1f);
                iVar29 = (int)uVar13 >> 3;
              }
              else {
                uVar21 = *puVar17;
                uVar16 = (0x17 - ((int)uVar21 >> 2)) - (int)(char)(&DAT_40a95d10)[uVar19];
                uVar13 = *(uint *)(param_4 + 0x6bdc);
                iVar18 = *(int *)(&DAT_40a97d20 + uVar19 * 4);
                if ((int)uVar16 < 0x20) goto LAB_40a8803c;
LAB_40a87f6c:
                iVar29 = (int)uVar13 >> 3;
                if ((int)uVar16 < 0x40) {
                  uVar19 = (uint)((ulonglong)
                                  ((longlong)iVar18 *
                                  (longlong)*(int *)(&DAT_40aa0e10 + (uVar21 & 3) * 4)) >> 0x20) >>
                           (uVar16 - 0x20 & 0x1f);
                }
                else {
                  uVar19 = 0;
                }
              }
              if (((uint)*(byte *)(iVar24 + iVar29) << (uVar13 & 7) & 0xff) >> 7 != 0) {
                uVar19 = -uVar19;
              }
              *(uint *)(param_4 + 0x6bdc) = uVar13 + 1;
            }
            iVar23 = iVar23 + -1;
            *(uint *)(param_1 + (iVar20 + 0x3c) * 4 + 4) = uVar19;
            iVar18 = iVar20 + 1;
            if (iVar23 < 1) break;
            uVar19 = *(uint *)(param_4 + 0x6bdc);
            iVar20 = iVar20 + 2;
            puVar22 = puVar22 + 2;
            puVar17 = puVar17 + 2;
            puVar14 = puVar14 + 2;
          } while ((int)uVar19 < param_3);
        }
      }
    }
    iVar26 = iVar26 + 4;
  } while (iVar26 != param_1 + 0xc);
  iVar26 = param_4 + (*(int *)(param_1 + 0x50) + 0x1085) * 8;
  if (iVar18 < 0x23d) {
    uVar19 = *(uint *)(param_4 + 0x6bdc);
    if ((int)uVar19 < param_3) {
      iVar25 = *(int *)(iVar26 + 8);
      iVar11 = *(int *)(param_4 + 0x6bd8);
      puVar17 = (uint *)(param_2 + iVar18 * 4);
      puVar14 = (uint *)(param_1 + (iVar18 + 0x3f) * 4 + 4);
      puVar22 = (uint *)(param_2 + (iVar18 + 3) * 4);
      puVar30 = (uint *)(param_2 + (iVar18 + 2) * 4);
      puVar28 = (uint *)(param_2 + (iVar18 + 1) * 4);
      iVar23 = iVar18;
      do {
        uVar13 = uVar19;
        pbVar12 = (byte *)(iVar11 + ((int)uVar13 >> 3));
        iVar18 = *(int *)(iVar26 + 4);
        puVar8 = (uint *)(iVar25 + ((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                      (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10) <<
                                    (uVar13 & 7)) >> (0x20U - iVar18 & 0x1f)) * 8);
        local_38 = *(undefined4 *)(param_4 + 0x6be0);
        uVar15 = puVar8[1];
        uVar21 = *puVar8;
        uVar16 = uVar15;
        uVar19 = uVar13;
        if ((int)uVar15 < 0) {
          uVar19 = uVar13 + iVar18;
          pbVar12 = (byte *)(iVar11 + ((int)uVar19 >> 3));
          puVar8 = (uint *)(iVar25 + (((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                         (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10) <<
                                       (uVar19 & 7)) >> (uVar15 & 0x1f)) + uVar21) * 8);
          uVar16 = puVar8[1];
          uVar21 = *puVar8;
          if (-1 < (int)uVar16) goto LAB_40a87a0c;
          uVar19 = uVar19 - uVar15;
          pbVar12 = (byte *)(iVar11 + ((int)uVar19 >> 3));
          puVar8 = (uint *)(iVar25 + (((((uint)*pbVar12 << 0x18 | (uint)pbVar12[3] |
                                         (uint)pbVar12[2] << 8 | (uint)pbVar12[1] << 0x10) <<
                                       (uVar19 & 7)) >> (uVar16 & 0x1f)) + uVar21) * 8);
          uVar21 = *puVar8;
          uVar19 = puVar8[1] + uVar19;
          *(uint *)(param_4 + 0x6bdc) = uVar19;
        }
        else {
LAB_40a87a0c:
          uVar19 = uVar16 + uVar19;
          *(uint *)(param_4 + 0x6bdc) = uVar19;
        }
        if ((int)uVar21 < 0) {
          return 0xfffffffe;
        }
        uVar16 = 0;
        if ((uVar21 & 8) != 0) {
          uVar16 = *puVar17;
          uVar15 = -((int)uVar16 >> 2) + 0x18;
          if ((int)uVar15 < 0x20) {
            uVar16 = (int)((ulonglong)
                           ((longlong)*(int *)(&DAT_40aa0e10 + (uVar16 & 3) * 4) * 0xfffffa) >> 0x20
                          ) << (0x20 - uVar15 & 0x1f) |
                     (uint)((longlong)*(int *)(&DAT_40aa0e10 + (uVar16 & 3) * 4) * 0xfffffa) >>
                     (uVar15 & 0x1f);
          }
          else if ((int)uVar15 < 0x40) {
            uVar16 = (uint)((ulonglong)
                            ((longlong)*(int *)(&DAT_40aa0e10 + (uVar16 & 3) * 4) * 0xfffffa) >>
                           0x20) >> (-((int)uVar16 >> 2) - 8U & 0x1f);
          }
          else {
            uVar16 = 0;
          }
          if (((uint)*(byte *)(iVar11 + ((int)uVar19 >> 3)) << (uVar19 & 7) & 0xff) >> 7 != 0) {
            uVar16 = -uVar16;
          }
          *(uint *)(param_4 + 0x6bdc) = uVar19 + 1;
        }
        *(uint *)(param_1 + (iVar23 + 0x3c) * 4 + 4) = uVar16;
        if ((uVar21 & 4) == 0) {
          uVar19 = 0;
        }
        else {
          uVar19 = *puVar28;
          uVar16 = -((int)uVar19 >> 2) + 0x18;
          if ((int)uVar16 < 0x20) {
            uVar19 = (int)((ulonglong)
                           ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >> 0x20
                          ) << (0x20 - uVar16 & 0x1f) |
                     (uint)((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                     (uVar16 & 0x1f);
            uVar16 = *(uint *)(param_4 + 0x6bdc);
          }
          else {
            if ((int)uVar16 < 0x40) {
              uVar19 = (uint)((ulonglong)
                              ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                             0x20) >> (-((int)uVar19 >> 2) - 8U & 0x1f);
            }
            else {
              uVar19 = 0;
            }
            uVar16 = *(uint *)(param_4 + 0x6bdc);
          }
          if (((uint)*(byte *)(iVar11 + ((int)uVar16 >> 3)) << (uVar16 & 7) & 0xff) >> 7 != 0) {
            uVar19 = -uVar19;
          }
          *(uint *)(param_4 + 0x6bdc) = uVar16 + 1;
        }
        puVar14[-2] = uVar19;
        if ((uVar21 & 2) == 0) {
          uVar19 = 0;
        }
        else {
          uVar19 = *puVar30;
          uVar16 = -((int)uVar19 >> 2) + 0x18;
          if ((int)uVar16 < 0x20) {
            uVar19 = (int)((ulonglong)
                           ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >> 0x20
                          ) << (0x20 - uVar16 & 0x1f) |
                     (uint)((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                     (uVar16 & 0x1f);
            uVar16 = *(uint *)(param_4 + 0x6bdc);
          }
          else {
            if ((int)uVar16 < 0x40) {
              uVar19 = (uint)((ulonglong)
                              ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                             0x20) >> (-((int)uVar19 >> 2) - 8U & 0x1f);
            }
            else {
              uVar19 = 0;
            }
            uVar16 = *(uint *)(param_4 + 0x6bdc);
          }
          if (((uint)*(byte *)(iVar11 + ((int)uVar16 >> 3)) << (uVar16 & 7) & 0xff) >> 7 != 0) {
            uVar19 = -uVar19;
          }
          *(uint *)(param_4 + 0x6bdc) = uVar16 + 1;
        }
        puVar14[-1] = uVar19;
        if ((uVar21 & 1) == 0) {
          *puVar14 = 0;
        }
        else {
          uVar19 = *puVar22;
          uVar21 = -((int)uVar19 >> 2) + 0x18;
          if ((int)uVar21 < 0x20) {
            uVar19 = (int)((ulonglong)
                           ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >> 0x20
                          ) << (0x20 - uVar21 & 0x1f) |
                     (uint)((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                     (uVar21 & 0x1f);
            uVar21 = *(uint *)(param_4 + 0x6bdc);
          }
          else if ((int)uVar21 < 0x40) {
            uVar19 = (uint)((ulonglong)
                            ((longlong)*(int *)(&DAT_40aa0e10 + (uVar19 & 3) * 4) * 0xfffffa) >>
                           0x20) >> (-((int)uVar19 >> 2) - 8U & 0x1f);
            uVar21 = *(uint *)(param_4 + 0x6bdc);
          }
          else {
            uVar19 = 0;
            uVar21 = *(uint *)(param_4 + 0x6bdc);
          }
          if (((uint)*(byte *)(iVar11 + ((int)uVar21 >> 3)) << (uVar21 & 7) & 0xff) >> 7 != 0) {
            uVar19 = -uVar19;
          }
          *(uint *)(param_4 + 0x6bdc) = uVar21 + 1;
          *puVar14 = uVar19;
        }
        iVar18 = iVar23 + 4;
        if (0x23c < iVar18) goto LAB_40a87c50;
        iVar18 = iVar23 + 4;
        uVar19 = *(uint *)(param_4 + 0x6bdc);
        puVar14 = puVar14 + 4;
        puVar22 = puVar22 + 4;
        puVar30 = puVar30 + 4;
        puVar28 = puVar28 + 4;
        puVar17 = puVar17 + 4;
        iVar23 = iVar18;
      } while ((int)uVar19 < param_3);
    }
    else {
      iVar11 = 0;
      local_38 = 0;
      uVar13 = 0;
    }
    bVar6 = iVar18 < 0x240;
    if (((int)uVar19 <= param_3) || (iVar11 == 0)) goto LAB_40a87c54;
    *(int *)(param_4 + 0x6bd8) = iVar11;
    *(undefined4 *)(param_4 + 0x6be0) = local_38;
    *(uint *)(param_4 + 0x6bdc) = uVar13;
    iVar18 = iVar18 + -4;
  }
LAB_40a87c50:
  bVar6 = iVar18 < 0x240;
LAB_40a87c54:
  if (bVar6) {
    puVar9 = (undefined4 *)(param_1 + (iVar18 + 0x3c) * 4);
    do {
      puVar9 = puVar9 + 1;
      iVar18 = iVar18 + 1;
      *puVar9 = 0;
    } while (iVar18 < 0x240);
  }
  return 1;
}



/* 40a883b4 FUN_40a883b4 */

/* Boundary evidence: original MIPS .pdata 40a883b4..40a89b9b. Semantic name remains unreviewed. */

int FUN_40a883b4(va_list param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  size_t sVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  int iVar19;
  va_list pcVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  int *piVar24;
  va_list pcVar25;
  uint uVar26;
  int *piVar27;
  int iVar28;
  int *piVar29;
  int iVar30;
  uint *puVar31;
  uint *puVar32;
  int iVar33;
  uint *puVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int local_2840 [7];
  uint local_2824 [2549];
  int *local_50;
  int local_4c;
  int local_48;
  int *local_44;
  int *local_40;
  va_list local_3c;
  uint *local_38;
  int local_34;
  int *local_30;
  
  param_1[0x54] = '\0';
  param_1[0x55] = '\0';
  param_1[0x56] = '\0';
  param_1[0x57] = '\0';
  if (*(int *)(param_1 + 100) == 0) {
    piVar29 = (int *)(param_1 + 0x6bd8);
    uVar7 = FUN_40a84268(piVar29,9);
    if (*(int *)(param_1 + 0x8c) == 2) {
      FUN_40a84268(piVar29,3);
      iVar37 = *(int *)(param_1 + 0x8c);
    }
    else {
      FUN_40a84268(piVar29,5);
      iVar37 = *(int *)(param_1 + 0x8c);
    }
    puVar32 = local_2824;
    if (iVar37 < 1) {
      local_38 = local_2824;
    }
    else {
      iVar28 = 0;
      local_38 = puVar32;
      do {
        *puVar32 = 0;
        uVar26 = FUN_40a84268(piVar29,4);
        iVar37 = *(int *)(param_1 + 0x8c);
        iVar28 = iVar28 + 1;
        puVar32[0x27d] = uVar26;
        puVar32 = puVar32 + 0x4fa;
      } while (iVar28 < iVar37);
    }
    local_48 = 2;
  }
  else {
    piVar29 = (int *)(param_1 + 0x6bd8);
    uVar7 = FUN_40a84268(piVar29,8);
    if (*(int *)(param_1 + 0x8c) == 2) {
      FUN_40a84268(piVar29,2);
      local_38 = local_2824;
      local_48 = 1;
      iVar37 = *(int *)(param_1 + 0x8c);
    }
    else {
      FUN_40a84268(piVar29,1);
      local_38 = local_2824;
      iVar37 = *(int *)(param_1 + 0x8c);
      local_48 = 1;
    }
  }
  puVar32 = local_38;
  uVar26 = *(uint *)(param_1 + 0x6bdc);
  iVar28 = *(int *)(param_1 + 0x6bd8);
  iVar35 = 0;
  puVar34 = local_38;
  do {
    if (0 < iVar37) {
      iVar30 = *(int *)(param_1 + 0x58);
      uVar16 = *(uint *)(param_1 + 0x6984);
      iVar36 = *(int *)(param_1 + 100);
      iVar33 = 0;
      puVar15 = puVar34;
      do {
        pbVar8 = (byte *)(iVar28 + ((int)uVar26 >> 3));
        uVar21 = uVar26 + 0xc;
        puVar15[1] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                      (uint)pbVar8[1] << 0x10) << (uVar26 & 7)) >> 0x14;
        pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
        *(uint *)(param_1 + 0x6bdc) = uVar21;
        uVar23 = uVar26 + 0x15;
        puVar15[2] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                      (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x17;
        pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
        *(uint *)(param_1 + 0x6bdc) = uVar23;
        uVar21 = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                  (uint)pbVar8[1] << 0x10) << (uVar23 & 7)) >> 0x18;
        uVar23 = uVar26 + 0x1d;
        *(uint *)(param_1 + 0x6bdc) = uVar23;
        puVar15[3] = uVar21;
        if ((uVar16 & 3) == 2) {
          puVar15[3] = uVar21 - 2;
          if (iVar36 != 0) goto LAB_40a88560;
LAB_40a89214:
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          bVar1 = *pbVar8;
          bVar2 = pbVar8[3];
          bVar3 = pbVar8[2];
          bVar4 = pbVar8[1];
          *(uint *)(param_1 + 0x6bdc) = uVar26 + 0x21;
          puVar15[4] = (((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10)
                       << (uVar23 & 7)) >> 0x1c;
        }
        else {
          if (iVar36 == 0) goto LAB_40a89214;
LAB_40a88560:
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          bVar1 = *pbVar8;
          bVar2 = pbVar8[3];
          bVar3 = pbVar8[2];
          bVar4 = pbVar8[1];
          *(uint *)(param_1 + 0x6bdc) = uVar26 + 0x26;
          puVar15[4] = (((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10)
                       << (uVar23 & 7)) >> 0x17;
        }
        uVar26 = *(uint *)(param_1 + 0x6bdc);
        pbVar8 = (byte *)(iVar28 + ((int)uVar26 >> 3));
        bVar1 = *pbVar8;
        bVar2 = pbVar8[3];
        bVar3 = pbVar8[2];
        bVar4 = pbVar8[1];
        uVar21 = uVar26 + 1;
        *(uint *)(param_1 + 0x6bdc) = uVar21;
        if ((int)(((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10) <<
                 (uVar26 & 7)) < 0) {
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          uVar21 = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                    (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1e;
          *(uint *)(param_1 + 0x6bdc) = uVar26 + 3;
          puVar15[6] = uVar21;
          if (uVar21 == 0) {
            param_1[0x54] = '\x01';
            param_1[0x55] = '\0';
            param_1[0x56] = '\0';
            param_1[0x57] = '\0';
          }
          uVar26 = *(uint *)(param_1 + 0x6bdc);
          pbVar8 = (byte *)(iVar28 + ((int)uVar26 >> 3));
          uVar21 = uVar26 + 1;
          puVar15[5] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                        (uint)pbVar8[1] << 0x10) << (uVar26 & 7)) >> 0x1f;
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar21;
          uVar23 = uVar26 + 6;
          puVar15[9] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                        (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1b;
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar23;
          uVar21 = uVar26 + 0xb;
          puVar15[10] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                         (uint)pbVar8[1] << 0x10) << (uVar23 & 7)) >> 0x1b;
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar21;
          uVar23 = uVar26 + 0xe;
          puVar15[0xc] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                          (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1d;
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar23;
          uVar21 = uVar26 + 0x11;
          puVar15[0xd] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                          (uint)pbVar8[1] << 0x10) << (uVar23 & 7)) >> 0x1d;
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar21;
          bVar1 = *pbVar8;
          bVar2 = pbVar8[3];
          bVar3 = pbVar8[2];
          bVar4 = pbVar8[1];
          uVar26 = uVar26 + 0x14;
          *(uint *)(param_1 + 0x6bdc) = uVar26;
          uVar23 = puVar15[6];
          puVar15[0xe] = (((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 |
                          (uint)bVar4 << 0x10) << (uVar21 & 7)) >> 0x1d;
          if (uVar23 == 2) {
            uVar21 = 0x24;
            if (iVar30 != 8) {
              uVar21 = 0x12;
            }
            puVar15[0xf] = uVar21;
          }
          else if (2 < iVar30) {
            uVar21 = 0x1b;
            if (iVar30 == 8) {
              uVar21 = 0x36;
            }
            puVar15[0xf] = uVar21;
          }
          else {
            puVar15[0xf] = 0x12;
          }
          puVar15[0x10] = 0x120;
        }
        else {
          puVar15[6] = 0;
          puVar15[5] = 0;
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          uVar23 = uVar26 + 6;
          puVar15[9] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                        (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1b;
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar23;
          uVar21 = uVar26 + 0xb;
          puVar15[10] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                         (uint)pbVar8[1] << 0x10) << (uVar23 & 7)) >> 0x1b;
          pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar21;
          uVar23 = uVar26 + 0x10;
          uVar9 = uVar26 + 0x14;
          puVar15[0xb] = (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                          (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1b;
          pbVar8 = (byte *)(iVar28 + ((int)uVar23 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar23;
          bVar1 = pbVar8[1];
          bVar2 = *pbVar8;
          bVar3 = pbVar8[3];
          bVar4 = pbVar8[2];
          pbVar8 = (byte *)(iVar28 + ((int)uVar9 >> 3));
          *(uint *)(param_1 + 0x6bdc) = uVar9;
          uVar23 = (((uint)bVar2 << 0x18 | (uint)bVar3 | (uint)bVar4 << 8 | (uint)bVar1 << 0x10) <<
                   (uVar23 & 7)) >> 0x1c;
          uVar21 = uVar23 + 2 +
                   ((((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                     (uint)pbVar8[1] << 0x10) << (uVar9 & 7)) >> 0x1d);
          if (0x16 < uVar21) {
            uVar21 = 0x16;
          }
          uVar21 = *(uint *)(&DAT_40a959d4 + (iVar30 * 0x17 + uVar21) * 4);
          uVar26 = uVar26 + 0x17;
          puVar15[0xf] = *(uint *)(&DAT_40a959d4 + (iVar30 * 0x17 + uVar23 + 1) * 4) >> 1;
          *(uint *)(param_1 + 0x6bdc) = uVar26;
          uVar23 = 0;
          puVar15[0x10] = uVar21 >> 1;
        }
        uVar9 = puVar15[2];
        uVar21 = puVar15[0xf];
        if ((int)uVar9 <= (int)puVar15[0xf]) {
          uVar21 = uVar9;
        }
        uVar13 = puVar15[0x10];
        if ((int)uVar9 <= (int)puVar15[0x10]) {
          uVar13 = uVar9;
        }
        if (0x120 < (int)uVar9) {
          uVar9 = 0x120;
        }
        puVar15[0x11] = uVar9 - uVar13;
        puVar15[0x10] = uVar13 - uVar21;
        puVar15[0xf] = uVar21;
        if (uVar23 == 2) {
          if (puVar15[5] == 0) {
            puVar15[8] = 0;
            puVar15[7] = 0;
          }
          else {
            if (2 < iVar30) {
              uVar21 = 6;
              if (iVar30 == 8) {
                uVar21 = 4;
              }
              puVar15[8] = uVar21;
            }
            else {
              puVar15[8] = 8;
            }
            uVar21 = 3;
            if (iVar30 == 8) {
              uVar21 = 2;
            }
            puVar15[7] = uVar21;
          }
        }
        else {
          puVar15[7] = 0xd;
          puVar15[8] = 0x16;
        }
        puVar15[0x12] = 0;
        if (iVar36 == 0) {
          pbVar8 = (byte *)(iVar28 + ((int)uVar26 >> 3));
          uVar21 = uVar26 & 7;
          uVar26 = uVar26 + 1;
          puVar15[0x12] =
               (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
                (uint)pbVar8[1] << 0x10) << uVar21) >> 0x1f;
          *(uint *)(param_1 + 0x6bdc) = uVar26;
        }
        pbVar8 = (byte *)(iVar28 + ((int)uVar26 >> 3));
        uVar21 = uVar26 + 1;
        puVar15[0x13] =
             (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
              (uint)pbVar8[1] << 0x10) << (uVar26 & 7)) >> 0x1f;
        pbVar8 = (byte *)(iVar28 + ((int)uVar21 >> 3));
        *(uint *)(param_1 + 0x6bdc) = uVar21;
        iVar33 = iVar33 + 1;
        uVar26 = uVar26 + 2;
        puVar15[0x14] =
             (((uint)*pbVar8 << 0x18 | (uint)pbVar8[3] | (uint)pbVar8[2] << 8 |
              (uint)pbVar8[1] << 0x10) << (uVar21 & 7)) >> 0x1f;
        *(uint *)(param_1 + 0x6bdc) = uVar26;
        puVar15 = puVar15 + 0x4fa;
      } while (iVar33 < iVar37);
    }
    iVar35 = iVar35 + 1;
    puVar34 = puVar34 + 0x27d;
  } while (iVar35 < local_48);
  piVar29 = (int *)((iVar28 + ((int)uVar26 >> 3)) - uVar7);
  FUN_40a8a870(piVar29,(int *)(param_1 +
                              ((*(int *)(param_1 + 0x4c) + (*(uint *)(param_1 + 0x5c) ^ 1) * 0xb00)
                              - uVar7) + 0x6fec),uVar7);
  uVar26 = *(uint *)(param_1 + 0x5c);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x48);
  *(uint *)(param_1 + 0x5c) = uVar26 ^ 1;
  local_44 = (int *)(param_1 + 0x32a8);
  local_40 = (int *)(param_1 + 0x9a0);
  local_3c = param_1 + 0xa0;
  iVar28 = *(int *)(param_1 + 0x8c);
  *(int **)(param_1 + 0x6bd8) = piVar29;
  *(uint *)(param_1 + 0x6be0) = (uVar7 + *(int *)(param_1 + 0x48)) * 8;
  *(va_list *)(param_1 + 0x6be8) = param_1 + (uVar26 ^ 1) * 0xb00 + 0x6fec;
  param_1[0x6bdc] = '\0';
  param_1[0x6bdd] = '\0';
  param_1[0x6bde] = '\0';
  param_1[0x6bdf] = '\0';
  piVar29 = (int *)(param_1 + 0x44a8);
  iVar37 = 0;
  do {
    local_30 = local_2840 + 3;
    if (0 < iVar28) {
      local_4c = 0;
      puVar34 = puVar32;
      do {
        uVar7 = *(uint *)(param_1 + 0x6bdc);
        if (*(int *)(param_1 + 100) == 0) {
          iVar35 = *(int *)(&DAT_40aa05ac + puVar34[4] * 4);
          iVar28 = *(int *)(&DAT_40aa05ac + (puVar34[4] + 0x10) * 4);
          if (puVar34[6] == 2) {
            iVar30 = 0x12;
            if (puVar34[5] != 0) {
              iVar30 = 0x11;
            }
            if (iVar35 == 0) {
              iVar33 = 0;
              puVar15 = puVar34;
              do {
                iVar33 = iVar33 + 1;
                puVar15[0x15] = 0;
                puVar15 = puVar15 + 1;
              } while (iVar33 < iVar30);
            }
            else {
              iVar36 = *(int *)(param_1 + 0x6bd8);
              iVar33 = 0;
              puVar15 = puVar34;
              uVar26 = uVar7;
              while( true ) {
                pbVar8 = (byte *)(iVar36 + ((int)uVar26 >> 3));
                bVar1 = *pbVar8;
                bVar2 = pbVar8[3];
                bVar3 = pbVar8[2];
                bVar4 = pbVar8[1];
                iVar33 = iVar33 + 1;
                *(uint *)(param_1 + 0x6bdc) = iVar35 + uVar26;
                puVar15[0x15] =
                     (((uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 8 | (uint)bVar4 << 0x10)
                     << (uVar26 & 7)) >> (0x20U - iVar35 & 0x1f);
                puVar15 = puVar15 + 1;
                if (iVar30 <= iVar33) break;
                uVar26 = *(uint *)(param_1 + 0x6bdc);
              }
            }
            if (iVar28 == 0) {
              puVar15 = puVar34 + iVar33 + 0x14;
              iVar28 = 0;
              do {
                puVar15 = puVar15 + 1;
                iVar28 = iVar28 + 4;
                *puVar15 = 0;
              } while (iVar28 != 0x48);
            }
            else {
              puVar15 = puVar34 + iVar33 + 0x14;
              iVar30 = *(int *)(param_1 + 0x6bd8);
              iVar35 = 0;
              do {
                puVar15 = puVar15 + 1;
                uVar26 = *(uint *)(param_1 + 0x6bdc);
                iVar35 = iVar35 + 4;
                pbVar8 = (byte *)(iVar30 + ((int)uVar26 >> 3));
                bVar1 = *pbVar8;
                bVar2 = pbVar8[3];
                bVar3 = pbVar8[1];
                bVar4 = pbVar8[2];
                *(uint *)(param_1 + 0x6bdc) = iVar28 + uVar26;
                *puVar15 = (((uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 0x10 |
                            (uint)bVar4 << 8) << (uVar26 & 7)) >> (0x20U - iVar28 & 0x1f);
              } while (iVar35 != 0x48);
            }
            puVar34[iVar33 + 0x27] = 0;
            puVar34[iVar33 + 0x28] = 0;
            puVar34[iVar33 + 0x29] = 0;
          }
          else {
            local_34 = local_4c * 0x4fa;
            iVar30 = 0;
            uVar26 = 0;
            do {
              iVar33 = 5;
              if (uVar26 == 0) {
                iVar33 = 6;
              }
              if ((8 >> (uVar26 & 0x1f) & *puVar34) == 0) {
                iVar36 = iVar35;
                if (1 < (int)uVar26) {
                  iVar36 = iVar28;
                }
                if (iVar36 == 0) {
                  puVar15 = puVar34 + iVar30 + 0x14;
                  iVar36 = 0;
                  do {
                    puVar15 = puVar15 + 1;
                    iVar36 = iVar36 + 1;
                    *puVar15 = 0;
                    iVar30 = iVar30 + 1;
                  } while (iVar36 < iVar33);
                }
                else {
                  puVar15 = puVar34 + iVar30 + 0x14;
                  iVar14 = *(int *)(param_1 + 0x6bd8);
                  iVar10 = 0;
                  do {
                    puVar15 = puVar15 + 1;
                    uVar16 = *(uint *)(param_1 + 0x6bdc);
                    iVar10 = iVar10 + 1;
                    pbVar8 = (byte *)(iVar14 + ((int)uVar16 >> 3));
                    bVar1 = *pbVar8;
                    bVar2 = pbVar8[3];
                    bVar3 = pbVar8[1];
                    bVar4 = pbVar8[2];
                    *(uint *)(param_1 + 0x6bdc) = iVar36 + uVar16;
                    iVar30 = iVar30 + 1;
                    *puVar15 = (((uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 0x10 |
                                (uint)bVar4 << 8) << (uVar16 & 7)) >> (0x20U - iVar36 & 0x1f);
                  } while (iVar10 < iVar33);
                }
              }
              else {
                puVar31 = local_38 + local_34 + iVar30 + 0x14;
                puVar15 = puVar34 + iVar30 + 0x14;
                iVar36 = 0;
                do {
                  puVar31 = puVar31 + 1;
                  puVar15 = puVar15 + 1;
                  iVar36 = iVar36 + 1;
                  *puVar15 = *puVar31;
                  iVar30 = iVar30 + 1;
                } while (iVar36 < iVar33);
              }
              uVar26 = uVar26 + 1;
            } while (uVar26 != 4);
            puVar34[iVar30 + 0x15] = 0;
          }
LAB_40a88ae0:
          uVar26 = puVar34[0x12];
        }
        else {
          iVar28 = 1;
          if (puVar34[6] == 2) {
            if (puVar34[5] != 0) {
              iVar28 = 2;
            }
          }
          else {
            iVar28 = 0;
          }
          uVar26 = puVar34[4];
          if (((*(uint *)(param_1 + 0x6984) & 1) == 0) || (local_4c != 1)) {
            if ((int)uVar26 < 400) {
              FUN_40a846d0(local_2840 + 3,uVar26,5,4,4);
              iVar35 = 0;
            }
            else if ((int)uVar26 < 500) {
              FUN_40a846d0(local_2840 + 3,uVar26 - 400,5,4,0);
              iVar35 = 1;
            }
            else {
              FUN_40a846d0(local_2840 + 3,uVar26 - 500,3,0,0);
              puVar34[0x12] = 1;
              iVar35 = 2;
            }
          }
          else {
            uVar26 = (int)uVar26 >> 1;
            if ((int)uVar26 < 0xb4) {
              FUN_40a846d0(local_2840 + 3,uVar26,6,6,0);
              iVar35 = 3;
            }
            else if ((int)uVar26 < 0xf4) {
              FUN_40a846d0(local_2840 + 3,uVar26 - 0xb4,4,4,0);
              iVar35 = 4;
            }
            else {
              FUN_40a846d0(local_2840 + 3,uVar26 - 0xf4,3,0,0);
              iVar35 = 5;
            }
          }
          piVar17 = &DAT_40aa062c + (iVar28 * 6 + iVar35) * 4;
          puVar15 = (uint *)(local_2840 + 3);
          iVar28 = 0;
          do {
            iVar35 = *piVar17;
            uVar26 = *puVar15;
            if (0 < iVar35) {
              if (uVar26 == 0) {
                puVar31 = puVar34 + iVar28 + 0x14;
                iVar30 = 0;
                do {
                  puVar31 = puVar31 + 1;
                  iVar30 = iVar30 + 1;
                  *puVar31 = 0;
                } while (iVar30 < iVar35);
                iVar28 = iVar28 + iVar35;
              }
              else {
                puVar31 = puVar34 + iVar28 + 0x14;
                iVar33 = *(int *)(param_1 + 0x6bd8);
                iVar30 = 0;
                do {
                  puVar31 = puVar31 + 1;
                  uVar16 = *(uint *)(param_1 + 0x6bdc);
                  iVar30 = iVar30 + 1;
                  pbVar8 = (byte *)(iVar33 + ((int)uVar16 >> 3));
                  bVar1 = *pbVar8;
                  bVar2 = pbVar8[3];
                  bVar3 = pbVar8[2];
                  bVar4 = pbVar8[1];
                  *(uint *)(param_1 + 0x6bdc) = uVar16 + uVar26;
                  *puVar31 = (((uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar3 << 8 |
                              (uint)bVar4 << 0x10) << (uVar16 & 7)) >> (0x20 - uVar26 & 0x1f);
                } while (iVar30 < iVar35);
                iVar28 = iVar28 + iVar35;
              }
            }
            puVar15 = puVar15 + 1;
            piVar17 = piVar17 + 1;
          } while (local_38 != puVar15);
          if (0x27 < iVar28) goto LAB_40a88ae0;
          puVar15 = puVar34 + iVar28 + 0x14;
          do {
            puVar15 = puVar15 + 1;
            iVar28 = iVar28 + 1;
            *puVar15 = 0;
          } while (iVar28 < 0x28);
          uVar26 = puVar34[0x12];
        }
        iVar35 = *(int *)(param_1 + 0x58);
        uVar16 = puVar34[0x13];
        uVar21 = puVar34[8];
        iVar28 = puVar34[3] - 0xd2;
        if ((int)uVar21 < 1) {
          iVar30 = 0;
        }
        else {
          iVar36 = 0;
          iVar30 = 0;
          iVar33 = 0;
          do {
            iVar10 = *(int *)(&DAT_40aa0d38 + iVar33 + uVar26 * 0x58);
            iVar19 = *(int *)((int)puVar34 + iVar33 + 0x54);
            iVar14 = *(int *)(&DAT_40aa084c + iVar33 + iVar35 * 0x58);
            if (0 < iVar14) {
              piVar17 = (int *)(param_1 + (iVar30 + 0x28) * 4);
              iVar11 = iVar14;
              do {
                iVar11 = iVar11 + -1;
                *piVar17 = iVar28 - (iVar10 + iVar19 << (uVar16 + 1 & 0x1f));
                piVar17 = piVar17 + 1;
              } while (0 < iVar11);
              uVar21 = puVar34[8];
              iVar30 = iVar30 + iVar14;
            }
            iVar36 = iVar36 + 1;
            iVar33 = iVar33 + 4;
          } while (iVar36 < (int)uVar21);
        }
        uVar26 = puVar34[7];
        if ((int)uVar26 < 0xd) {
          local_2840[0] = iVar28 + puVar34[0xc] * -8;
          local_2840[1] = iVar28 + puVar34[0xd] * -8;
          local_2840[2] = iVar28 + puVar34[0xe] * -8;
          piVar17 = (int *)(&DAT_40aa0b64 + uVar26 * 4 + iVar35 * 0x34);
          uVar26 = uVar26 * -3 + 0x27 + uVar21;
          do {
            puVar15 = puVar34 + uVar21 + 0x14;
            iVar28 = *piVar17;
            piVar27 = local_2840;
            do {
              puVar15 = puVar15 + 1;
              uVar23 = *puVar15;
              iVar35 = *piVar27;
              if (0 < iVar28) {
                piVar24 = (int *)(param_1 + (iVar30 + 0x28) * 4);
                iVar33 = iVar28;
                do {
                  iVar33 = iVar33 + -1;
                  *piVar24 = iVar35 - (uVar23 << (uVar16 + 1 & 0x1f));
                  piVar24 = piVar24 + 1;
                } while (0 < iVar33);
                iVar30 = iVar30 + iVar28;
              }
              piVar27 = piVar27 + 1;
            } while (local_30 != piVar27);
            uVar21 = uVar21 + 3;
            piVar17 = piVar17 + 1;
          } while (uVar21 != uVar26);
        }
        iVar35 = uVar7 + puVar34[1];
        pcVar20 = local_3c;
        pcVar25 = param_1;
        iVar28 = FUN_40a87810((int)puVar34,(int)local_3c,iVar35,(int)param_1);
        if (iVar28 < 0) {
          sVar12 = FUN_40a8d174(s_decode_layer3_BQ_ERROR_reported_b_40aa6118);
          FUN_40a8d128(sVar12,pcVar20,iVar35,pcVar25);
          param_1[0x54] = '\x01';
          param_1[0x55] = '\0';
          param_1[0x56] = '\0';
          param_1[0x57] = '\0';
        }
        iVar35 = *(int *)(param_1 + 0x6bdc);
        iVar28 = (uVar7 + puVar34[1]) - iVar35;
        if (iVar28 < 0) {
          *(int *)(param_1 + 0x6bdc) = iVar35 + iVar28;
        }
        else {
          if (0xf < iVar28) {
            uVar7 = iVar28 - 0x10U & 0xfffffff0;
            *(uint *)(param_1 + 0x6bdc) = iVar35 + 0x10 + uVar7;
            iVar28 = (iVar28 - 0x10U) - uVar7;
          }
          if (iVar28 != 0) {
            *(int *)(param_1 + 0x6bdc) = iVar28 + *(int *)(param_1 + 0x6bdc);
          }
        }
        iVar28 = *(int *)(param_1 + 0x8c);
        local_4c = local_4c + 1;
        puVar34 = puVar34 + 0x4fa;
      } while (local_4c < iVar28);
      if (iVar28 == 2) {
        FUN_40a847ac((int)puVar32,(int)(puVar32 + 0x4fa),(int)param_1);
        iVar28 = *(int *)(param_1 + 0x8c);
      }
      if (0 < iVar28) {
        iVar35 = 0;
        puVar34 = puVar32;
        piVar17 = local_44;
        local_50 = piVar29;
        do {
          uVar7 = puVar34[6];
          if (uVar7 == 2) {
            uVar26 = puVar34[5];
            puVar15 = puVar34 + 0x3d;
            if ((uVar26 != 0) && (puVar15 = puVar34 + 0x6d, *(int *)(param_1 + 0x58) != 8)) {
              puVar15 = puVar34 + 0x61;
            }
            uVar16 = puVar34[7];
            if ((int)uVar16 < 0xd) {
              do {
                iVar28 = *(int *)(&DAT_40aa0b64 + *(int *)(param_1 + 0x58) * 0x34 + uVar16 * 4);
                iVar30 = 0;
                puVar31 = puVar15;
                do {
                  if (0 < iVar28) {
                    puVar22 = (uint *)(param_1 + (iVar30 + 0x268) * 4);
                    puVar18 = puVar31;
                    iVar33 = iVar28;
                    do {
                      iVar33 = iVar33 + -1;
                      *puVar22 = *puVar18;
                      puVar18 = puVar18 + 1;
                      puVar22 = puVar22 + 3;
                    } while (0 < iVar33);
                    puVar31 = puVar31 + iVar28;
                  }
                  iVar30 = iVar30 + 1;
                } while (iVar30 != 3);
                uVar16 = uVar16 + 1;
                FUN_40a8a870((int *)puVar15,local_40,iVar28 * 0xc);
                puVar15 = puVar31;
              } while ((int)uVar16 < 0xd);
              uVar26 = puVar34[5];
              uVar7 = puVar34[6];
            }
          }
          else {
            uVar26 = puVar34[5];
          }
          if (uVar26 == 0) {
            if (uVar7 != 2) {
LAB_40a88d58:
              iVar28 = 0x1f;
              goto LAB_40a88d5c;
            }
          }
          else {
            iVar28 = 1;
            if (uVar7 != 2) goto LAB_40a88d58;
LAB_40a88d5c:
            puVar15 = puVar34 + 0x4f;
            while( true ) {
              uVar7 = puVar15[-1];
              uVar6 = (longlong)(int)uVar7 * 0x6dc254;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)*puVar15 * 0x41daff;
              puVar15[-1] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x41daff;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)*puVar15 * 0x6dc254;
              *puVar15 = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-2];
              uVar6 = (longlong)(int)uVar7 * 0x70dcec;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[1] * 0x3c61b6;
              puVar15[-2] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x3c61b6;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[1] * 0x70dcec;
              puVar15[1] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-3];
              uVar6 = (longlong)(int)uVar7 * 0x798d6e;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[2] * 0x281cc0;
              puVar15[-3] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x281cc0;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[2] * 0x798d6e;
              puVar15[2] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-4];
              uVar6 = (longlong)(int)uVar7 * 0x7ddd40;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[3] * 0x1748ee;
              puVar15[-4] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x1748ee;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[3] * 0x7ddd40;
              puVar15[3] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-5];
              uVar6 = (longlong)(int)uVar7 * 0x7f6d20;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[4] * 0xc1b01;
              puVar15[-5] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0xc1b01;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[4] * 0x7f6d20;
              puVar15[4] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-6];
              uVar6 = (longlong)(int)uVar7 * 0x7fe47e;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[5] * 0x53e5c;
              puVar15[-6] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x53e5c;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[5] * 0x7fe47e;
              puVar15[5] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-7];
              uVar6 = (longlong)(int)uVar7 * 0x7ffcb2;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[6] * 0x1d142;
              puVar15[-7] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x1d142;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[6] * 0x7ffcb2;
              puVar15[6] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar7 = puVar15[-8];
              uVar6 = (longlong)(int)uVar7 * 0x7fffc6;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[7] * 0x793d;
              puVar15[-8] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              uVar6 = (longlong)(int)uVar7 * -0x793d;
              lVar5 = (uVar6 & 0xffffffff00000000) + (uVar6 & 0xffffffff) +
                      (longlong)(int)puVar15[7] * 0x7fffc6;
              iVar28 = iVar28 + -1;
              puVar15[7] = (int)((ulonglong)lVar5 >> 0x20) << 9 | (uint)lVar5 >> 0x17;
              if (iVar28 == 0) break;
              puVar15 = puVar15 + 0x12;
            }
          }
          FUN_40a83b90((int)puVar34,local_50,piVar17,(int)param_1);
          iVar28 = *(int *)(param_1 + 0x8c);
          iVar35 = iVar35 + 1;
          local_50 = local_50 + 0x480;
          puVar34 = puVar34 + 0x4fa;
          piVar17 = piVar17 + 0x240;
        } while (iVar35 < iVar28);
      }
    }
    iVar37 = iVar37 + 1;
    puVar32 = puVar32 + 0x27d;
    piVar29 = piVar29 + 0x240;
    if (local_48 <= iVar37) {
      return local_48 * 0x12;
    }
  } while( true );
}



/* 40a89b9c FUN_40a89b9c */

/* Boundary evidence: original MIPS .pdata 40a89b9c..40a8a45f. Semantic name remains unreviewed. */

int FUN_40a89b9c(byte *param_1,uint *param_2,int *param_3,uint param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint uVar16;
  int iVar17;
  byte *pbVar18;
  uint uVar19;
  int *piVar20;
  byte *pbVar21;
  int iVar22;
  int iVar23;
  byte abStack_c0 [128];
  byte *local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  
  *param_2 = 0;
  if ((int)param_4 < 1) {
    iVar22 = 0;
    iVar9 = param_5[0x23];
  }
  else {
    pbVar7 = (byte *)param_5[0x12];
    iVar22 = 0;
    local_34 = param_3;
    do {
      piVar5 = (int *)param_5[0x1af9];
      pbVar8 = (byte *)param_5[0x1afa];
      iVar9 = (int)piVar5 - (int)pbVar8;
      if (pbVar7 == (byte *)0x0) {
        uVar16 = 4 - iVar9;
        if ((int)param_4 < (int)uVar16) {
          uVar19 = 0;
          uVar16 = param_4;
LAB_40a89c34:
          FUN_40a8a870(piVar5,local_34,uVar16);
          iVar9 = param_5[0x1af9];
          local_34 = (int *)((int)local_34 + uVar16);
          param_5[0x1af9] = iVar9 + uVar16;
          iVar9 = (iVar9 + uVar16) - param_5[0x1afa];
          pbVar7 = (byte *)param_5[0x1afa];
          param_4 = uVar19;
        }
        else {
          pbVar7 = pbVar8;
          if (0 < (int)uVar16) {
            uVar19 = param_4 - uVar16;
            goto LAB_40a89c34;
          }
        }
        pbVar8 = pbVar7;
        if (iVar9 < 4) {
LAB_40a89c6c:
          pbVar7 = (byte *)param_5[0x12];
        }
        else {
          uVar19 = (uint)pbVar7[1] << 0x10;
          uVar6 = (uint)pbVar7[3] | (uint)*pbVar7 << 0x18 | uVar19;
          uVar2 = (uint)pbVar7[2] << 8;
          uVar16 = (uint)*pbVar7 << 0x18 | uVar19 | uVar2;
          if (uVar16 == 0x49443300) {
            return -3;
          }
          if ((((uVar16 == 0x54414700) || ((uVar6 & 0xffe00000) != 0xffe00000)) ||
              ((uVar2 & 0xc00) == 0xc00)) || (((uVar19 & 0x60000) == 0 || (pbVar7[2] >> 4 == 0xf))))
          {
            uVar16 = iVar9 - 1;
          }
          else {
            if (3 < iVar22) {
              param_5[1] = param_5[1] + 4;
              param_5[7] = param_5[0x18];
              param_5[8] = param_5[0x22];
              param_5[9] = param_5[0x23];
            }
            iVar9 = FUN_40a84d9c(uVar6 | uVar2,(int)param_5);
            if (iVar9 != 1) goto LAB_40a89c6c;
            pbVar7 = (byte *)param_5[0x1afa];
            uVar16 = (param_5[0x1af9] + -1) - (int)pbVar7;
          }
          FUN_40a8a870((int *)pbVar7,(int *)(pbVar7 + 1),uVar16);
          iVar22 = iVar22 + 1;
          param_5[0x1af9] = param_5[0x1af9] + -1;
          pbVar7 = (byte *)param_5[0x12];
        }
      }
      else if (iVar9 < (int)pbVar7) {
        uVar16 = (int)pbVar7 - iVar9;
        if (0x700 < (int)pbVar7) {
          param_5[0x12] = 0x700;
          uVar16 = 0x700 - iVar9;
        }
        if ((int)param_4 < (int)uVar16) {
          uVar16 = param_4;
        }
        FUN_40a8a870(piVar5,local_34,uVar16);
        local_34 = (int *)((int)local_34 + uVar16);
        pbVar7 = (byte *)param_5[0x12];
        param_5[0x1af9] = param_5[0x1af9] + uVar16;
        param_4 = param_4 - uVar16;
      }
      if (0 < (int)pbVar7) {
        iVar9 = param_5[0x1af9] - param_5[0x1afa];
        if ((int)pbVar7 <= iVar9) {
          param_5[0x1af6] = param_5[0x1afa] + 4;
          param_5[0x1af8] = (iVar9 + -4) * 8;
          param_5[0x1af7] = 0;
          if (param_5[0x21] != 0) {
            param_5[0x1af7] = 0x10;
          }
          if (param_5[0x18] == 1) {
            iVar22 = FUN_40a85cb4((int)param_5);
          }
          else if (param_5[0x18] == 2) {
            iVar22 = FUN_40a86394((int)param_5);
          }
          else {
            iVar22 = FUN_40a883b4((va_list)param_5);
          }
          if (iVar22 < 1) {
            sVar3 = FUN_40a8d174(s_find_header_and_decode_one_frame_40aa6150);
            FUN_40a8d128(sVar3,iVar22,pbVar7,(va_list)pbVar8);
            iVar9 = param_5[0x23];
          }
          else {
            iVar9 = param_5[0x23];
          }
          if (0 < iVar9) {
            local_30 = param_5 + 0x4a8;
            local_3c = param_5 + 0x112a;
            local_38 = 0;
            piVar5 = param_5;
            local_40 = param_1;
            do {
              if (0 < iVar22) {
                iVar1 = local_38 + 0xca8;
                iVar23 = local_38 * 0x400;
                iVar17 = 0;
                piVar20 = local_3c;
                pbVar21 = local_40;
                do {
                  FUN_40a81000((int *)abStack_c0,piVar20);
                  pbVar7 = pbVar21;
                  pbVar8 = abStack_c0;
                  FUN_40a8548c(local_30 + iVar23 + piVar5[0xca8],(uint *)(param_5 + iVar1),
                               (undefined2 *)pbVar21,(int *)abStack_c0,(int)param_5);
                  iVar9 = param_5[0x23];
                  iVar17 = iVar17 + 1;
                  pbVar21 = pbVar21 + iVar9 * 0x40;
                  piVar20 = piVar20 + 0x20;
                } while (iVar17 < iVar22);
              }
              local_38 = local_38 + 1;
              local_3c = local_3c + 0x480;
              local_40 = local_40 + 2;
              piVar5 = piVar5 + 1;
            } while (local_38 < iVar9);
          }
          uVar16 = iVar22 * 0x40 * iVar9;
          if (param_5[0x15] == 0) {
LAB_40a89f64:
            iVar22 = param_5[0x18];
          }
          else {
            iVar22 = (int)uVar16 >> 1;
            pbVar21 = (byte *)(int)*(short *)param_1;
            if (iVar22 < 2) goto LAB_40a89f64;
            pbVar4 = (byte *)(int)*(short *)(param_1 + 2);
            uVar19 = (int)pbVar21 - (int)pbVar4 >> 0x1f;
            pbVar8 = param_1;
            if ((int)(((int)pbVar21 - (int)pbVar4 ^ uVar19) - uVar19) < 0x3001) {
              iVar1 = 1;
              pbVar10 = pbVar4;
              do {
                iVar1 = iVar1 + 1;
                if (iVar22 <= iVar1) goto LAB_40a89f64;
                pbVar7 = (byte *)(int)*(short *)(pbVar8 + 4);
                uVar2 = (int)pbVar10 - (int)pbVar7;
                uVar19 = (int)uVar2 >> 0x1f;
                pbVar8 = pbVar8 + 2;
                pbVar10 = pbVar7;
              } while ((int)((uVar2 ^ uVar19) - uVar19) < 0x3001);
            }
            if (iVar22 == 2) goto LAB_40a89f64;
            iVar1 = 2;
            pbVar10 = param_1;
            pbVar7 = pbVar4;
            pbVar12 = pbVar21;
            pbVar8 = pbVar21;
            pbVar11 = pbVar4;
            pbVar15 = pbVar21;
            pbVar18 = pbVar4;
            do {
              pbVar14 = pbVar11;
              pbVar13 = pbVar8;
              pbVar11 = pbVar7;
              pbVar8 = (byte *)(int)*(short *)(pbVar10 + 4);
              pbVar7 = (byte *)(int)*(short *)(pbVar10 + 6);
              iVar1 = iVar1 + 2;
              *(short *)(pbVar10 + 4) =
                   (short)(((int)pbVar21 >> 2) + ((int)pbVar12 >> 2) + ((int)pbVar8 >> 2) +
                           ((int)pbVar15 >> 1) + ((int)pbVar13 >> 1) >> 1);
              *(short *)(pbVar10 + 6) =
                   (short)(((int)pbVar4 >> 2) + ((int)pbVar18 >> 2) + ((int)pbVar7 >> 2) +
                           ((int)pbVar14 >> 1) + ((int)pbVar11 >> 1) >> 1);
              pbVar10 = pbVar10 + 4;
              pbVar21 = pbVar12;
              pbVar4 = pbVar18;
              pbVar12 = pbVar15;
              pbVar15 = pbVar13;
              pbVar18 = pbVar14;
            } while (iVar1 < iVar22);
            iVar22 = param_5[0x18];
          }
          if (iVar22 == param_5[7]) {
            iVar1 = param_5[0x22];
            if ((iVar1 != param_5[8]) || (iVar9 != param_5[9])) goto LAB_40a89f78;
            iVar17 = param_5[1];
            if (0 < iVar17) {
              iVar17 = iVar17 + -1;
              param_5[1] = iVar17;
            }
          }
          else {
            iVar1 = param_5[0x22];
LAB_40a89f78:
            if (((param_5[7] == -0x37) && (param_5[8] == -0x37)) && (param_5[9] == -0x37)) {
              pbVar7 = (byte *)0x4;
              if (iVar22 != 3) {
                pbVar8 = (byte *)0x0;
                FUN_40a84cc8(iVar1,iVar9,4,0,(int)param_5);
                iVar22 = param_5[0x18];
                iVar1 = param_5[0x22];
                iVar9 = param_5[0x23];
              }
              param_5[1] = 0;
            }
            else {
              param_5[1] = 0xe;
            }
            param_5[0x1a67] = 0x10;
            iVar17 = param_5[1];
            param_5[0x1a6a] = param_5[0x1a63];
            param_5[0x1a6d] = iVar22;
            param_5[7] = iVar22;
            param_5[8] = iVar1;
            param_5[9] = iVar9;
            param_5[0x1a66] = iVar1;
            param_5[0x1a68] = iVar9;
            param_5[0x1a69] = iVar9;
          }
          if (*param_5 != 0) {
            iVar22 = param_5[6];
            param_5[1] = iVar17 + *param_5;
            if (iVar22 < 1) {
              param_5[4] = 0xfffefe;
              if ((iVar9 == 0) || (iVar1 == 0)) {
                param_5[5] = -0xfffefe;
                *param_5 = 0;
                iVar17 = param_5[1];
              }
              else {
                if (iVar9 == 0) {
                  trap(7);
                }
                *param_5 = 0;
                if (iVar1 == 0) {
                  trap(7);
                }
                param_5[5] = ((0xfffefe / iVar9) / iVar1) * -3;
                iVar17 = param_5[1];
              }
            }
            else {
              iVar1 = iVar1 / iVar22;
              if (iVar22 == 0) {
                trap(7);
              }
              param_5[4] = 0xfffefe;
              *param_5 = 0;
              if (iVar1 < 0) {
                iVar1 = iVar1 + 7;
              }
              iVar17 = iVar1 >> 3;
              param_5[1] = iVar17;
            }
          }
          if (iVar17 < 1) {
LAB_40a89fec:
            param_5[0x1af9] = param_5[0x1afa];
            param_5[0x12] = 0;
            if ((uVar16 & 1) != 0) {
              sVar3 = FUN_40a8d174(s_find_header_and_decode_one_frame_40aa6180);
              FUN_40a8d128(sVar3,uVar16,pbVar7,(va_list)pbVar8);
              uVar16 = uVar16 & 0xfffffffe;
            }
            *param_2 = uVar16;
            if ((int)uVar16 < 1) {
              iVar9 = param_5[0x23];
              iVar22 = (int)local_34 - (int)param_3;
              goto LAB_40a89ca4;
            }
            iVar1 = (int)uVar16 >> 1;
            if (((param_5[1] == 0) && (iVar22 = param_5[4], iVar22 != 0)) && (iVar1 != 0)) {
              iVar17 = param_5[5];
              iVar9 = 0;
              do {
                iVar23 = 0xfffefe - iVar22;
                iVar22 = iVar17 + iVar22;
                iVar9 = iVar9 + 1;
                if (iVar22 < 0) {
                  iVar22 = 0;
                }
                *(short *)param_1 = (short)((uint)((iVar23 >> 8) * (int)*(short *)param_1) >> 0x10);
                param_5[4] = iVar22;
                param_1 = param_1 + 2;
              } while (iVar9 < iVar1);
            }
            if (100 < (int)uVar16) {
              iVar9 = param_5[0x23];
              if (iVar9 == 0) {
                trap(7);
              }
              iVar22 = (int)local_34 - (int)param_3;
              param_5[6] = iVar1 / iVar9;
              goto LAB_40a89ca4;
            }
          }
          else {
            if (0 < (int)uVar16) {
              if ((int)((uint)param_5[0x14] >> 1) < (int)uVar16) {
                uVar16 = (uint)param_5[0x14] >> 1;
              }
              pbVar7 = (byte *)(uVar16 << 1);
              memset(param_1,0,(size_t)pbVar7);
              goto LAB_40a89fec;
            }
            param_5[0x12] = 0;
            param_5[0x1af9] = param_5[0x1afa];
            *param_2 = 0;
          }
          iVar9 = param_5[0x23];
          iVar22 = (int)local_34 - (int)param_3;
          goto LAB_40a89ca4;
        }
      }
    } while (0 < (int)param_4);
    iVar9 = param_5[0x23];
    iVar22 = (int)local_34 - (int)param_3;
  }
LAB_40a89ca4:
  if (param_5[0x22] < 2000) {
    param_5[0x22] = 0xac44;
  }
  if (0 < iVar9) {
    return iVar22;
  }
  param_5[0x23] = 2;
  return iVar22;
}



/* 40a8a460 FUN_40a8a460 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40a8a460..40a8a86f. Semantic name remains unreviewed. */

int FUN_40a8a460(byte *param_1,uint *param_2,void *param_3,int param_4,int *param_5,int *param_6)

{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  va_list pcVar7;
  int iVar8;
  uint uVar9;
  
  uVar9 = *param_2;
  if (param_6[0x22] < 2000) {
    param_6[0x22] = 0xac44;
  }
  if (param_6[0x23] < 1) {
    param_6[0x23] = 2;
  }
  *param_2 = 0;
  param_6[0x10] = 0;
  iVar2 = memcmp(param_3,&DAT_40aa61b8,3);
  if (iVar2 == 0) {
    uVar5 = ((uint)*(byte *)((int)param_3 + 6) << 0x15 | (uint)*(byte *)((int)param_3 + 7) << 0xe |
             (uint)*(byte *)((int)param_3 + 9) | (uint)*(byte *)((int)param_3 + 8) << 7) + 10;
    param_6[0x10] = uVar5;
    if (0x100000 < uVar5) {
      param_6[0x10] = 0;
      return param_4;
    }
    if (param_4 <= (int)uVar5) {
      param_6[0x11] = uVar5 - param_4;
      return param_4;
    }
  }
  iVar2 = param_6[0x11];
  if (iVar2 == 0) {
    iVar2 = param_6[0x10];
    piVar6 = (int *)((int)param_3 + iVar2);
    cVar1 = (char)*piVar6;
  }
  else {
    if (param_4 <= iVar2) {
      *param_2 = 0;
      param_6[0x11] = param_6[0x11] - param_4;
      return param_4;
    }
    param_6[0x10] = iVar2;
    iVar2 = param_6[0x10];
    param_6[0x11] = 0;
    piVar6 = (int *)((int)param_3 + iVar2);
    cVar1 = (char)*piVar6;
  }
  if (cVar1 == '\0') {
    pcVar7 = (va_list)(param_4 - iVar2);
    if (0 < (int)pcVar7) {
      for (iVar2 = 1; (iVar2 < (int)pcVar7 && (*(char *)((int)piVar6 + iVar2) == '\0'));
          iVar2 = iVar2 + 1) {
      }
      if (500 < iVar2) {
        *param_2 = 0x7fffff00;
        return iVar2 + param_6[0x10];
      }
    }
    iVar2 = FUN_40a89b9c(param_1,param_2,piVar6,(uint)pcVar7,param_6);
    uVar5 = *param_2;
  }
  else {
    pcVar7 = (va_list)(param_4 - iVar2);
    iVar2 = FUN_40a89b9c(param_1,param_2,piVar6,(uint)pcVar7,param_6);
    uVar5 = *param_2;
  }
  if ((int)uVar9 < (int)uVar5) {
    sVar3 = FUN_40a8d174(s_mp3_decode_final_output_size__d_>_40aa61bc);
    FUN_40a8d128(sVar3,*param_2,uVar9,pcVar7);
    *param_2 = uVar9;
  }
  if (iVar2 == -3) {
    *param_2 = 0;
    FUN_40a85a48(param_6);
    iVar8 = param_4;
    while (0 < iVar8) {
      iVar4 = memcmp(param_3,&DAT_40aa61b8,3);
      if (iVar4 == 0) {
        uVar9 = ((uint)*(byte *)((int)param_3 + 6) << 0x15 |
                 (uint)*(byte *)((int)param_3 + 7) << 0xe | (uint)*(byte *)((int)param_3 + 9) |
                (uint)*(byte *)((int)param_3 + 8) << 7) + 10;
        param_6[0x10] = uVar9;
        if (0x100000 < uVar9) {
          param_6[0x10] = 0;
          param_6[0x11] = 0;
          return param_4;
        }
        if (iVar8 <= (int)uVar9) {
          param_6[0x11] = uVar9 - iVar8;
          return param_4;
        }
        param_6[0x11] = 0;
        return (param_4 + uVar9) - iVar8;
      }
      param_3 = (void *)((int)param_3 + 1);
      iVar8 = iVar8 + -1;
    }
  }
  iVar8 = param_6[0x10];
  if (((param_6[0x1aae] == param_6[0x1a66]) && (param_6[0x1ab1] == param_6[0x1a69])) &&
     (param_6[0x1ab5] == param_6[0x1a6d])) {
    param_6[0x27] = 0;
  }
  else if (param_6[0x27] < 5) {
    param_6[0x27] = param_6[0x27] + 1;
  }
  else {
    param_6[0x1aae] = param_6[0x1a66];
    param_6[0x1aaf] = param_6[0x1a67];
    param_6[0x1ab2] = param_6[0x1a6a];
    param_6[0x1ab0] = param_6[0x1a68];
    param_6[0x1ab1] = param_6[0x1a69];
    param_6[0x1ab3] = param_6[0x1a6b];
    param_6[0x1ab5] = param_6[0x1a6d];
  }
  FUN_40a8a870(param_5,param_6 + 0x1aae,0x120);
  return iVar2 + iVar8;
}



/* 40a8a870 FUN_40a8a870 */

/* WARNING: Instruction at (ram,0x40a8a8a8) overlaps instruction at (ram,0x40a8a8a4)
    */

int * FUN_40a8a870(int *param_1,int *param_2,uint param_3)

{
  undefined1 *puVar1;
  bool bVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  prefetch(param_2,0);
  prefetch(param_1,1);
  uVar9 = (uint)param_1 & 3;
  prefetch(param_2 + 8,0);
  prefetch(param_1 + 8,1);
  uVar8 = (uint)param_2 & 3;
  piVar6 = param_1;
  if (param_3 < 4) {
LAB_40a8aa58:
    if (param_3 == 0) {
      return param_1;
    }
  }
  else {
    prefetch(param_2 + 0x10,0);
    prefetch(param_1 + 0x10,1);
    if (uVar9 == 0) {
      if (uVar8 != 0) {
LAB_40a8a9d0:
        prefetch(param_2 + 0x18,0);
        uVar8 = param_3 & 0xf;
        if (param_3 >> 4 != 0) {
          prefetch(piVar6 + 0x18,1);
          do {
            iVar10 = *param_2;
            iVar11 = param_2[1];
            param_3 = param_3 - 0x10;
            iVar12 = param_2[2];
            iVar14 = param_2[3];
            prefetch(param_2 + 0x48,0);
            param_2 = param_2 + 4;
            *piVar6 = iVar10;
            piVar6[1] = iVar11;
            piVar6[2] = iVar12;
            piVar6[3] = iVar14;
            prefetch(piVar6 + 0x48,1);
            piVar6 = piVar6 + 4;
          } while (param_3 != uVar8);
        }
        uVar8 = param_3 & 3;
        if (param_3 == 0) {
          return param_1;
        }
        if (uVar8 == param_3) goto LAB_40a8aa60;
        do {
          iVar10 = *param_2;
          param_2 = param_2 + 1;
          param_3 = param_3 - 4;
          *piVar6 = iVar10;
          piVar6 = piVar6 + 1;
        } while (param_3 != uVar8);
        goto LAB_40a8aa58;
      }
    }
    else {
      uVar13 = 4 - uVar9;
      uVar4 = (uint)param_1 & 3;
      *(uint *)((int)param_1 - uVar4) =
           *(uint *)((int)param_1 - uVar4) & 0xffffffffU >> (4 - uVar4) * 8 | *param_2 << uVar4 * 8;
      bVar2 = param_3 == uVar13;
      param_3 = param_3 - uVar13;
      if (bVar2) {
        return param_1;
      }
      piVar6 = (int *)((int)param_1 + uVar13);
      param_2 = (int *)((int)param_2 + uVar13);
      if (uVar8 != uVar9) goto LAB_40a8a9d0;
    }
    uVar8 = param_3 & 0x1f;
    if (param_3 >> 5 != 0) {
      prefetch(param_2 + 0x18,0);
      prefetch(piVar6 + 0x18,1);
      piVar5 = piVar6;
      piVar7 = param_2;
      do {
        iVar10 = piVar7[1];
        iVar12 = piVar7[2];
        iVar14 = piVar7[3];
        param_3 = param_3 - 0x20;
        iVar15 = piVar7[4];
        iVar16 = piVar7[5];
        *piVar5 = *piVar7;
        piVar5[1] = iVar10;
        iVar10 = piVar7[6];
        iVar11 = piVar7[7];
        param_2 = piVar7 + 8;
        piVar6 = piVar5 + 8;
        piVar5[2] = iVar12;
        piVar5[3] = iVar14;
        piVar5[4] = iVar15;
        piVar5[5] = iVar16;
        piVar5[6] = iVar10;
        piVar5[7] = iVar11;
        prefetch(piVar7 + 0x48,0);
        prefetch(piVar5 + 0x48,1);
        piVar5 = piVar6;
        piVar7 = param_2;
      } while (param_3 != uVar8);
    }
    if (param_3 == 0) {
      return param_1;
    }
    uVar8 = param_3 & 3;
    if (0xf < param_3) {
      iVar10 = *param_2;
      iVar11 = param_2[1];
      iVar12 = param_2[2];
      iVar14 = param_2[3];
      param_3 = param_3 - 0x10;
      param_2 = param_2 + 4;
      *piVar6 = iVar10;
      piVar6[1] = iVar11;
      piVar6[2] = iVar12;
      piVar6[3] = iVar14;
      piVar6 = piVar6 + 4;
      if (param_3 == 0) {
        return param_1;
      }
    }
    if (uVar8 != param_3) {
      do {
        uVar9 = param_3;
        iVar10 = *param_2;
        param_2 = param_2 + 1;
        param_3 = uVar9 - 4;
        *piVar6 = iVar10;
        piVar6 = piVar6 + 1;
      } while (uVar8 != param_3);
      if (param_3 == 0) {
        return param_1;
      }
      puVar1 = (undefined1 *)((int)piVar6 + (uVar9 - 5));
      uVar8 = (uint)puVar1 & 3;
      puVar3 = (uint *)(puVar1 + -uVar8);
      *puVar3 = *puVar3 & -1 << (uVar8 + 1) * 8 |
                (uint)(*param_2 << (param_3 * -8 + 0x20 & 0x1f)) >> (3 - uVar8) * 8;
      return param_1;
    }
  }
LAB_40a8aa60:
  *(char *)piVar6 = (char)*param_2;
  if ((param_3 != 1) &&
     (*(undefined1 *)((int)piVar6 + 1) = *(undefined1 *)((int)param_2 + 1), param_3 != 2)) {
    *(undefined1 *)((int)piVar6 + 2) = *(undefined1 *)((int)param_2 + 2);
    return param_1;
  }
  return param_1;
}



/* 40a8aa98 FUN_40a8aa98 */

/* Boundary evidence: original MIPS .pdata 40a8aa98..40a8aab3. Semantic name remains unreviewed. */

void FUN_40a8aa98(LPCRITICAL_SECTION param_1)

{
  DeleteCriticalSection(param_1);
  return;
}



/* 40a8aab4 FUN_40a8aab4 */

/* Boundary evidence: original MIPS .pdata 40a8aab4..40a8aacf. Semantic name remains unreviewed. */

void FUN_40a8aab4(undefined4 *param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
  return;
}



/* 40a8aad0 DllRegisterServer */

/* Boundary evidence: original MIPS .pdata 40a8aad0..40a8aaeb. Semantic name remains unreviewed. */

void DllRegisterServer(void)

{
                    /* 0xaad0  4  DllRegisterServer */
  FUN_40a8e8c4(1);
  return;
}



/* 40a8aaec DllUnregisterServer */

/* Boundary evidence: original MIPS .pdata 40a8aaec..40a8ab07. Semantic name remains unreviewed. */

void DllUnregisterServer(void)

{
                    /* 0xaaec  5  DllUnregisterServer */
  FUN_40a8e8c4(0);
  return;
}



/* 40a8ab08 DllMain */

/* Boundary evidence: original MIPS .pdata 40a8ab08..40a8ab23. Semantic name remains unreviewed. */

void DllMain(HMODULE param_1,int param_2)

{
                    /* 0xab08  3  DllMain */
  FUN_40a8e9bc(param_1,param_2);
  return;
}



/* 40a8ab24 FUN_40a8ab24 */

/* Boundary evidence: original MIPS .pdata 40a8ab24..40a8ab5f. Semantic name remains unreviewed. */

undefined4 FUN_40a8ab24(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40a8def0(param_1 + 0x50);
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40a8ab60 FUN_40a8ab60 */

/* Boundary evidence: original MIPS .pdata 40a8ab60..40a8ab9b. Semantic name remains unreviewed. */

undefined4 FUN_40a8ab60(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40a8df00((int *)(param_1 + 0x50));
  if (iVar1 == 0) {
    return 0;
  }
  return 0x80004005;
}



/* 40a8ab9c FUN_40a8ab9c */

/* Boundary evidence: original MIPS .pdata 40a8ab9c..40a8abf3. Semantic name remains unreviewed. */

undefined4 FUN_40a8ab9c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_40a8dfbc((int)(param_1 + 0x14));
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*param_1 + 0x24))(param_1,0);
  }
  return uVar2;
}



/* 40a8abf4 FUN_40a8abf4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40a8abf4..40a8adab. Semantic name remains unreviewed. */

undefined4 FUN_40a8abf4(int param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2d8) + 0x34))(*(int **)(param_1 + 0x2d8),0,0);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if ((((iVar1 != 0) ||
         (iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10), iVar1 != 0)) ||
        ((*(int *)((int)param_2 + 0x28) != _DAT_00000028 ||
         ((iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10), iVar1 != 0 ||
          (*(size_t *)((int)param_2 + 0x40) != _DAT_00000040)))))) ||
       (iVar1 = memcmp(*(void **)((int)param_2 + 0x44),_DAT_00000044,
                       *(size_t *)((int)param_2 + 0x40)), iVar1 != 0)) {
      return 0x80070057;
    }
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40aa31ec,0x10);
    if ((iVar1 != 0) ||
       (iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40aa412c,0x10), iVar1 != 0)) {
      _Buf1 = (void *)((int)param_2 + 0x10);
      iVar1 = memcmp(_Buf1,&DAT_40aa34ec,0x10);
      if ((iVar1 != 0) &&
         ((((iVar1 = memcmp(_Buf1,&DAT_40aa34dc,0x10), iVar1 != 0 &&
            (iVar1 = memcmp(_Buf1,&DAT_40aa34cc,0x10), iVar1 != 0)) &&
           (iVar1 = memcmp(_Buf1,&DAT_40aa2264,0x10), iVar1 != 0)) &&
          (iVar1 = memcmp(_Buf1,&DAT_40aa2274,0x10), iVar1 != 0)))) {
        return 0x80070057;
      }
    }
  }
  return 0;
}



/* 40a8adac FUN_40a8adac */

/* Boundary evidence: original MIPS .pdata 40a8adac..40a8ae3f. Semantic name remains unreviewed. */

undefined4 FUN_40a8adac(int param_1,int param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = memcmp((void *)(param_2 + 0x2c),&DAT_40aa3dac,0x10);
  if ((iVar1 == 0) &&
     (iVar1 = FUN_40a8d5c4(*(int **)(param_2 + 0x44),
                           *(ushort *)(*(int **)(param_2 + 0x44) + 4) + 0x12,(int *)(param_1 + 0x50)
                           ,param_4), iVar1 == 0)) {
    return 0;
  }
  return 0x80004005;
}



/* 40a8ae40 FUN_40a8ae40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40a8ae40..40a8af6b. Semantic name remains unreviewed. */

undefined4 FUN_40a8ae40(int param_1,void *param_2)

{
  int iVar1;
  void *_Buf1;
  undefined4 *_Buf2;
  size_t _Size;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x2dc) + 0x34))(*(int **)(param_1 + 0x2dc),0,0);
  if (iVar1 == 0) {
    iVar1 = memcmp(param_2,(void *)0x0,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x10),(void *)0x10,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    if (*(int *)((int)param_2 + 0x28) != _DAT_00000028) {
      return 0x80070057;
    }
    iVar1 = memcmp((void *)((int)param_2 + 0x2c),(void *)0x2c,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Size = *(size_t *)((int)param_2 + 0x40);
    if (_Size != _DAT_00000040) {
      return 0x80070057;
    }
    _Buf1 = *(void **)((int)param_2 + 0x44);
    _Buf2 = _DAT_00000044;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40aa31ec,0x10);
    if (iVar1 != 0) {
      return 0x80070057;
    }
    _Buf1 = (void *)((int)param_2 + 0x10);
    iVar1 = memcmp(_Buf1,&DAT_40aa21f4,0x10);
    if (iVar1 == 0) {
      return 0;
    }
    _Size = 0x10;
    _Buf2 = &DAT_40aa35cc;
  }
  iVar1 = memcmp(_Buf1,_Buf2,_Size);
  if (iVar1 != 0) {
    return 0x80070057;
  }
  return 0;
}



/* 40a8af6c FUN_40a8af6c */

/* Boundary evidence: original MIPS .pdata 40a8af6c..40a8b0b7. Semantic name remains unreviewed. */

undefined4 FUN_40a8af6c(int param_1,uint param_2,undefined4 *param_3,va_list param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 2) {
    if ((param_3 == (undefined4 *)0x0) || (FUN_40a8eeb4((int)param_3,0x12), param_3[0x10] == 0)) {
      uVar1 = 0x80004005;
    }
    else {
      iVar2 = FUN_40a8d694((undefined1 *)param_3[0x11],0x12,(int *)(param_1 + 0x50),param_4);
      if (iVar2 == 0) {
        *param_3 = 0x73647561;
        param_3[1] = 0x100000;
        param_3[2] = 0xaa000080;
        param_3[3] = 0x719b3800;
        if (param_2 == 0) {
          param_3[4] = 0x51412b85;
          param_3[5] = 0x42fddc4f;
          param_3[6] = 0x3af12187;
          uVar1 = 0x6ea80b35;
        }
        else {
          param_3[4] = 1;
          param_3[5] = 0x100000;
          param_3[6] = 0xaa000080;
          uVar1 = 0x719b3800;
        }
        param_3[7] = uVar1;
        param_3[8] = 0;
        param_3[0xb] = 0x5589f81;
        param_3[0xc] = 0x11cec356;
        param_3[0xd] = 0xaa0001bf;
        param_3[0xe] = 0x5a595500;
        param_3[0x10] = 0x12;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x40103;
  }
  return uVar1;
}



/* 40a8b0dc FUN_40a8b0dc */

/* Boundary evidence: original MIPS .pdata 40a8b0dc..40a8b12b. Semantic name remains unreviewed. */

void FUN_40a8b0dc(int param_1,int *param_2,undefined4 *param_3)

{
  undefined1 auStack_18 [16];
  
  *param_3 = *(undefined4 *)(param_1 + 0x328);
  param_3[1] = *(undefined4 *)(param_1 + 0x324);
  param_3[2] = 4;
  param_3[3] = 0;
  (**(code **)(*param_2 + 0xc))(param_2,param_3,auStack_18);
  return;
}



/* 40a8b12c FUN_40a8b12c */

/* Boundary evidence: original MIPS .pdata 40a8b12c..40a8b1db. Semantic name remains unreviewed. */

undefined4 FUN_40a8b12c(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_140 [2];
  int aiStack_138 [72];
  uint local_18;
  
  local_18 = DAT_40ab1828;
  local_140[0] = 0;
  iVar1 = FUN_40a8dfdc(0x500d,aiStack_138,local_140,(int *)(param_1 + -0x2c8));
  if ((iVar1 == 0) && (local_140[0] == 0x120)) {
    FUN_40a8a870(param_2,aiStack_138,0x120);
    *param_3 = local_140[0];
    FUN_40a93fe4(local_18);
    return 0;
  }
  FUN_40a93fe4(local_18);
  return 0x80004005;
}



/* 40a8b1dc FUN_40a8b1dc */

/* Boundary evidence: original MIPS .pdata 40a8b1dc..40a8b273. Semantic name remains unreviewed. */

undefined4 FUN_40a8b1dc(int param_1,int *param_2)

{
  int iVar1;
  int local_138 [2];
  int aiStack_130 [72];
  uint local_10;
  
  local_10 = DAT_40ab1828;
  local_138[0] = 0;
  iVar1 = FUN_40a8dfdc(0x500e,aiStack_130,local_138,(int *)(param_1 + -0x2c8));
  if ((iVar1 == 0) && (local_138[0] == 4)) {
    FUN_40a8a870(param_2,aiStack_130,4);
    FUN_40a93fe4(local_10);
    return 0;
  }
  FUN_40a93fe4(local_10);
  return 0x80004005;
}



/* 40a8b274 FUN_40a8b274 */

/* Boundary evidence: original MIPS .pdata 40a8b274..40a8b30b. Semantic name remains unreviewed. */

undefined4 *
FUN_40a8b274(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  FUN_40a925dc(param_1,param_2,(undefined4 *)0x0,(LPCRITICAL_SECTION)(param_1 + 0xbb),param_4);
  *param_1 = &PTR_FUN_40aa25d8;
  param_1[3] = &PTR_FUN_40aa259c;
  param_1[4] = &PTR_LAB_40aa2588;
  param_1[0xb6] = 0;
  param_1[0xb7] = 0;
  param_1[0xb8] = param_6;
  param_1[0xb9] = param_7;
  param_1[0xba] = param_8;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xbb));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc0));
  return param_1;
}



/* 40a8b30c FUN_40a8b30c */

/* Boundary evidence: original MIPS .pdata 40a8b30c..40a8b333. Semantic name remains unreviewed. */

void FUN_40a8b30c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40a8b334 FUN_40a8b334 */

/* Boundary evidence: original MIPS .pdata 40a8b334..40a8b35b. Semantic name remains unreviewed. */

void FUN_40a8b334(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40a8b35c FUN_40a8b35c */

/* Boundary evidence: original MIPS .pdata 40a8b35c..40a8b383. Semantic name remains unreviewed. */

void FUN_40a8b35c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40a8b384 FUN_40a8b384 */

undefined4 FUN_40a8b384(void)

{
  return 0;
}



/* 40a8b394 FUN_40a8b394 */

/* Boundary evidence: original MIPS .pdata 40a8b394..40a8b44b. Semantic name remains unreviewed. */

void FUN_40a8b394(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_40aa25d8;
  param_1[3] = &PTR_FUN_40aa259c;
  param_1[4] = &PTR_LAB_40aa2588;
  piVar1 = (int *)param_1[0xb6];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0xb6] = 0;
  }
  piVar1 = (int *)param_1[0xb7];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,1);
    param_1[0xb7] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc0));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xbb));
  FUN_40a90d20((int)param_1);
  return;
}



/* 40a8b44c FUN_40a8b44c */

/* Boundary evidence: original MIPS .pdata 40a8b44c..40a8b47b. Semantic name remains unreviewed. */

void FUN_40a8b44c(void)

{
  int *in_v0;
  
  FUN_40a90d20(*in_v0);
  return;
}



/* 40a8b47c FUN_40a8b47c */

/* Boundary evidence: original MIPS .pdata 40a8b47c..40a8b4af. Semantic name remains unreviewed. */

void FUN_40a8b47c(void)

{
  int *in_v0;
  
  FUN_40a8aa98((LPCRITICAL_SECTION)(*in_v0 + 0x2ec));
  return;
}



/* 40a8b4b0 FUN_40a8b4b0 */

/* Boundary evidence: original MIPS .pdata 40a8b4b0..40a8b4e3. Semantic name remains unreviewed. */

void FUN_40a8b4b0(void)

{
  int *in_v0;
  
  FUN_40a8aa98((LPCRITICAL_SECTION)(*in_v0 + 0x300));
  return;
}



/* 40a8b4e4 FUN_40a8b4e4 */

/* Boundary evidence: original MIPS .pdata 40a8b4e4..40a8b4ff. Semantic name remains unreviewed. */

void FUN_40a8b4e4(int *param_1,void *param_2,undefined4 *param_3)

{
  FUN_40a90c40(param_1,param_2,param_3);
  return;
}



/* 40a8b500 FUN_40a8b500 */

/* Boundary evidence: original MIPS .pdata 40a8b500..40a8b5b7. Semantic name remains unreviewed. */

int FUN_40a8b500(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc0);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[5] == 0) {
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = -0x7ffbfddd;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2);
    if (iVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return iVar1;
}



/* 40a8b5b8 FUN_40a8b5b8 */

/* Boundary evidence: original MIPS .pdata 40a8b5b8..40a8b5e7. Semantic name remains unreviewed. */

void FUN_40a8b5b8(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40a8b5e8 FUN_40a8b5e8 */

/* Boundary evidence: original MIPS .pdata 40a8b5e8..40a8b697. Semantic name remains unreviewed. */

int FUN_40a8b5e8(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc0);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*param_1 + 0x30))(param_1);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if ((int *)param_1[0xb7] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)param_1[0xb7] + 0x4c))();
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40a8b698 FUN_40a8b698 */

/* Boundary evidence: original MIPS .pdata 40a8b698..40a8b6c7. Semantic name remains unreviewed. */

void FUN_40a8b698(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40a8b6c8 FUN_40a8b6c8 */

/* Boundary evidence: original MIPS .pdata 40a8b6c8..40a8b833. Semantic name remains unreviewed. */

int FUN_40a8b6c8(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xb8);
  EnterCriticalSection(lpCriticalSection);
  param_1[5] = param_3;
  param_1[6] = param_4;
  iVar4 = 0;
  if ((param_1[2] == 0) && (iVar4 = (**(code **)(*param_1 + 0x14))(param_1), iVar4 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    if (param_1[2] != 2) {
      piVar5 = param_1 + -3;
      iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
      iVar3 = 0;
      if (0 < iVar1) {
        do {
          piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar3);
          if ((piVar2[6] != 0) && (iVar4 = (**(code **)(*piVar2 + 0x1c))(piVar2), iVar4 < 0)) {
            LeaveCriticalSection(lpCriticalSection);
            return iVar4;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
      }
    }
    param_1[2] = 2;
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar4;
}



/* 40a8b834 FUN_40a8b834 */

/* Boundary evidence: original MIPS .pdata 40a8b834..40a8b863. Semantic name remains unreviewed. */

void FUN_40a8b834(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x30));
  return;
}



/* 40a8b864 FUN_40a8b864 */

/* Boundary evidence: original MIPS .pdata 40a8b864..40a8b96b. Semantic name remains unreviewed. */

int FUN_40a8b864(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2e0);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    piVar5 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar5 + 0x18))(piVar5);
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*piVar5 + 0x1c))(piVar5,iVar4);
        if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0x14))(piVar2), iVar3 < 0)) {
          LeaveCriticalSection(lpCriticalSection);
          return iVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  *(undefined4 *)(param_1 + 8) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a8b96c FUN_40a8b96c */

/* Boundary evidence: original MIPS .pdata 40a8b96c..40a8b99b. Semantic name remains unreviewed. */

void FUN_40a8b96c(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x28));
  return;
}



/* 40a8b99c FUN_40a8b99c */

/* Boundary evidence: original MIPS .pdata 40a8b99c..40a8ba8b. Semantic name remains unreviewed. */

undefined4 FUN_40a8b99c(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2e0);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    piVar1 = (int *)(param_1 + -0xc);
    (**(code **)(*piVar1 + 0x28))(piVar1);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2f4));
    (**(code **)(*piVar1 + 0x2c))(piVar1);
    (**(code **)(**(int **)(param_1 + 0x2cc) + 0x18))();
    (**(code **)(**(int **)(param_1 + 0x2d0) + 0x18))();
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2f4));
    LeaveCriticalSection(lpCriticalSection);
  }
  return 0;
}



/* 40a8ba8c FUN_40a8ba8c */

/* Boundary evidence: original MIPS .pdata 40a8ba8c..40a8babb. Semantic name remains unreviewed. */

void FUN_40a8ba8c(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40a8babc FUN_40a8babc */

/* Boundary evidence: original MIPS .pdata 40a8babc..40a8baeb. Semantic name remains unreviewed. */

void FUN_40a8babc(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x1c));
  return;
}



/* 40a8baec FUN_40a8baec */

/* Boundary evidence: original MIPS .pdata 40a8baec..40a8bb07. Semantic name remains unreviewed. */

void FUN_40a8baec(int param_1)

{
  FUN_40a8f8bc(param_1);
  return;
}



/* 40a8bb08 FUN_40a8bb08 */

/* Boundary evidence: original MIPS .pdata 40a8bb08..40a8bbf7. Semantic name remains unreviewed. */

undefined4 FUN_40a8bb08(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[6] == 0) {
    (**(code **)(*param_2 + 8))();
    return 1;
  }
  iVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
  if (iVar1 == 0) {
    (**(code **)(*param_2 + 8))(param_2);
    return 0;
  }
  if ((LPCRITICAL_SECTION)param_1[0x2b] != (LPCRITICAL_SECTION)0x0) {
    uVar2 = FUN_40a933cc((LPCRITICAL_SECTION)param_1[0x2b],param_2);
    return uVar2;
  }
  uVar2 = (**(code **)(*param_1 + 0x44))(param_1);
  (**(code **)(*param_2 + 8))(param_2);
  return uVar2;
}



/* 40a8bbf8 FUN_40a8bbf8 */

/* Boundary evidence: original MIPS .pdata 40a8bbf8..40a8bc4f. Semantic name remains unreviewed. */

undefined4 FUN_40a8bbf8(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40a92980(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40a90118(param_1);
  return uVar1;
}



/* 40a8bc50 FUN_40a8bc50 */

/* Boundary evidence: original MIPS .pdata 40a8bc50..40a8bca7. Semantic name remains unreviewed. */

undefined4 FUN_40a8bc50(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40a93318(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40a90158(param_1);
  return uVar1;
}



/* 40a8bca8 FUN_40a8bca8 */

/* Boundary evidence: original MIPS .pdata 40a8bca8..40a8bcff. Semantic name remains unreviewed. */

undefined4 FUN_40a8bca8(int param_1)

{
  undefined4 uVar1;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 0xac) != (LPCRITICAL_SECTION)0x0) {
    FUN_40a93278(*(LPCRITICAL_SECTION *)(param_1 + 0xac));
    return 0;
  }
  uVar1 = FUN_40a8ffb4(param_1);
  return uVar1;
}



/* 40a8bd00 FUN_40a8bd00 */

/* Boundary evidence: original MIPS .pdata 40a8bd00..40a8bde3. Semantic name remains unreviewed. */

void FUN_40a8bd00(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  
  iVar1 = memcmp(param_2,&DAT_40aa310c,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40aa476c,0x10), iVar1 == 0)) {
    piVar3 = param_1 + 0x28;
    if (*piVar3 == 0) {
      iVar1 = *(int *)(param_1[0x1c] + 0x2d8) + 0xc;
      if (*(int *)(param_1[0x1c] + 0x2d8) == 0) {
        iVar1 = 0;
      }
      HVar2 = FUN_40a8f318((LPUNKNOWN)param_1[1],0,iVar1,piVar3);
      if (HVar2 < 0) {
        return;
      }
    }
    (*(code *)**(undefined4 **)*piVar3)((undefined4 *)*piVar3,param_2,param_3);
  }
  else {
    FUN_40a8f900(param_1,param_2,param_3);
  }
  return;
}



/* 40a8bde4 FUN_40a8bde4 */

/* Boundary evidence: original MIPS .pdata 40a8bde4..40a8be3f. Semantic name remains unreviewed. */

int FUN_40a8bde4(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION p_Var2;
  
  iVar1 = FUN_40a90034(param_1);
  if (-1 < iVar1) {
    p_Var2 = *(LPCRITICAL_SECTION *)(param_1 + 0xac);
    if (p_Var2 != (LPCRITICAL_SECTION)0x0) {
      FUN_40a92e34(p_Var2);
      operator_delete(p_Var2);
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40a8be40 FUN_40a8be40 */

/* Boundary evidence: original MIPS .pdata 40a8be40..40a8bf4b. Semantic name remains unreviewed. */

DWORD FUN_40a8be40(int param_1)

{
  DWORD DVar1;
  LPCRITICAL_SECTION p_Var2;
  DWORD local_18;
  LPCRITICAL_SECTION local_14;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    DVar1 = 0;
  }
  else {
    DVar1 = FUN_40a8fff4(param_1);
    if (-1 < (int)DVar1) {
      local_18 = 0;
      DVar1 = 0;
      if (*(int *)(param_1 + 0xa4) != 0) {
        local_14 = operator_new(0x54);
        if (local_14 == (LPCRITICAL_SECTION)0x0) {
          p_Var2 = (LPCRITICAL_SECTION)0x0;
        }
        else {
          p_Var2 = FUN_40a93448(local_14,*(undefined4 **)(param_1 + 0x18),&local_18,0,1,1,0,
                                *(undefined4 *)(param_1 + 0xa8),3);
        }
        *(LPCRITICAL_SECTION *)(param_1 + 0xac) = p_Var2;
        if (p_Var2 == (LPCRITICAL_SECTION)0x0) {
          DVar1 = 0x8007000e;
        }
        else {
          DVar1 = local_18;
          if ((int)local_18 < 0) {
            FUN_40a92e34(p_Var2);
            operator_delete(p_Var2);
            *(undefined4 *)(param_1 + 0xac) = 0;
            DVar1 = local_18;
          }
        }
      }
    }
  }
  return DVar1;
}



/* 40a8bf4c FUN_40a8bf4c */

/* Boundary evidence: original MIPS .pdata 40a8bf4c..40a8bf7b. Semantic name remains unreviewed. */

void FUN_40a8bf4c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x14));
  return;
}



/* 40a8bf7c FUN_40a8bf7c */

/* Boundary evidence: original MIPS .pdata 40a8bf7c..40a8bfa3. Semantic name remains unreviewed. */

void FUN_40a8bf7c(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x3c))();
  return;
}



/* 40a8bfa4 FUN_40a8bfa4 */

/* Boundary evidence: original MIPS .pdata 40a8bfa4..40a8bfbf. Semantic name remains unreviewed. */

void FUN_40a8bfa4(int param_1,void *param_2)

{
  FUN_40a8fa00(param_1,param_2);
  return;
}



/* 40a8bfc0 FUN_40a8bfc0 */

/* Boundary evidence: original MIPS .pdata 40a8bfc0..40a8c00b. Semantic name remains unreviewed. */

undefined4 FUN_40a8bfc0(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)((*(int **)(param_1 + 0x70))[0xb6] + 0x18) != 0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x70) + 0x40))();
    return uVar1;
  }
  return 0x40103;
}



/* 40a8c00c FUN_40a8c00c */

/* Boundary evidence: original MIPS .pdata 40a8c00c..40a8c04f. Semantic name remains unreviewed. */

void FUN_40a8c00c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_40a8fc70(param_1);
  if (-1 < iVar1) {
    (**(code **)(*(int *)param_1[0x1c] + 0x44))((int *)param_1[0x1c],param_1 + 7);
  }
  return;
}



/* 40a8c050 FUN_40a8c050 */

/* Boundary evidence: original MIPS .pdata 40a8c050..40a8c077. Semantic name remains unreviewed. */

void FUN_40a8c050(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x4c))();
  return;
}



/* 40a8c078 FUN_40a8c078 */

/* Boundary evidence: original MIPS .pdata 40a8c078..40a8c0f3. Semantic name remains unreviewed. */

undefined4 *
FUN_40a8c078(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5)

{
  FUN_40a92580(param_1,param_2,param_3,param_3 + 0x2ec,param_4,param_5);
  *param_1 = &PTR_FUN_40aa2870;
  param_1[3] = &PTR_FUN_40aa2828;
  param_1[4] = &PTR_LAB_40aa2814;
  param_1[0x26] = &PTR_LAB_40aa27f0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  param_1[0x3b] = 0;
  return param_1;
}



/* 40a8c100 FUN_40a8c100 */

/* Boundary evidence: original MIPS .pdata 40a8c100..40a8c127. Semantic name remains unreviewed. */

void FUN_40a8c100(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40a8c128 FUN_40a8c128 */

/* Boundary evidence: original MIPS .pdata 40a8c128..40a8c14f. Semantic name remains unreviewed. */

void FUN_40a8c128(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40a8c150 FUN_40a8c150 */

/* Boundary evidence: original MIPS .pdata 40a8c150..40a8c177. Semantic name remains unreviewed. */

void FUN_40a8c150(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40a8c178 FUN_40a8c178 */

/* Boundary evidence: original MIPS .pdata 40a8c178..40a8c19f. Semantic name remains unreviewed. */

void FUN_40a8c178(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x70) + 0x34))();
  return;
}



/* 40a8c1a0 FUN_40a8c1a0 */

/* Boundary evidence: original MIPS .pdata 40a8c1a0..40a8c1bb. Semantic name remains unreviewed. */

void FUN_40a8c1a0(int param_1,void *param_2)

{
  FUN_40a8fa00(param_1,param_2);
  return;
}



/* 40a8c1bc FUN_40a8c1bc */

/* Boundary evidence: original MIPS .pdata 40a8c1bc..40a8c207. Semantic name remains unreviewed. */

void FUN_40a8c1bc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40a8b384();
  if (-1 < iVar1) {
    (**(code **)(**(int **)(param_1 + 0x70) + 0x38))(*(int **)(param_1 + 0x70),param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0xec) = 1;
  }
  return;
}



/* 40a8c208 FUN_40a8c208 */

/* Boundary evidence: original MIPS .pdata 40a8c208..40a8c29b. Semantic name remains unreviewed. */

int FUN_40a8c208(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_40a90424(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40a8b500(*(int **)(param_1 + -0x28),param_2,param_3,param_4);
  }
  if (iVar1 == -0x7fffbffb) {
    pcVar2 = *(code **)(*(int *)(param_1 + -0x8c) + 0x38);
    *(undefined4 *)(param_1 + -0x2c) = 1;
    (*pcVar2)();
    FUN_40a8f510(*(int *)(param_1 + -0x28));
    iVar1 = -0x7ffbfe00;
  }
  return iVar1;
}



/* 40a8c29c FUN_40a8c29c */

/* Boundary evidence: original MIPS .pdata 40a8c29c..40a8c363. Semantic name remains unreviewed. */

int FUN_40a8c29c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40a908a8(param_1);
  if (iVar1 < 0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  else {
    piVar2 = *(int **)(param_1 + 100);
    iVar1 = (**(code **)(*piVar2 + 0x28))(piVar2);
    if ((-1 < iVar1) && ((int *)piVar2[0xb7] != (int *)0x0)) {
      iVar1 = (**(code **)(*(int *)piVar2[0xb7] + 0x50))();
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40a8c364 FUN_40a8c364 */

/* Boundary evidence: original MIPS .pdata 40a8c364..40a8c393. Semantic name remains unreviewed. */

void FUN_40a8c364(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40a8c394 FUN_40a8c394 */

/* Boundary evidence: original MIPS .pdata 40a8c394..40a8c463. Semantic name remains unreviewed. */

int FUN_40a8c394(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  piVar2 = *(int **)(param_1 + 100);
  iVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2);
  if (-1 < iVar1) {
    if ((int *)piVar2[0xb7] != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)piVar2[0xb7] + 0x54))();
    }
    if (-1 < iVar1) {
      iVar1 = FUN_40a908f0(param_1);
      LeaveCriticalSection(lpCriticalSection);
      return iVar1;
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40a8c464 FUN_40a8c464 */

/* Boundary evidence: original MIPS .pdata 40a8c464..40a8c493. Semantic name remains unreviewed. */

void FUN_40a8c464(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x20));
  return;
}



/* 40a8c494 FUN_40a8c494 */

/* Boundary evidence: original MIPS .pdata 40a8c494..40a8c4f7. Semantic name remains unreviewed. */

int FUN_40a8c494(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40a8b5e8(*(int **)(param_1 + 100));
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40a8c4f8 FUN_40a8c4f8 */

/* Boundary evidence: original MIPS .pdata 40a8c4f8..40a8c527. Semantic name remains unreviewed. */

void FUN_40a8c4f8(void)

{
  int in_v0;
  
  FUN_40a8aab4((undefined4 *)(in_v0 + -0x18));
  return;
}



/* 40a8c5dc FUN_40a8c5dc */

/* Boundary evidence: original MIPS .pdata 40a8c5dc..40a8c65b. Semantic name remains unreviewed. */

void FUN_40a8c5dc(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40aa2564,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0xc6;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40a92768(piVar2,param_3);
  }
  else {
    FUN_40a90c40(param_1,param_2,param_3);
  }
  return;
}



/* 40a8c65c FUN_40a8c65c */

/* Boundary evidence: original MIPS .pdata 40a8c65c..40a8c72b. Semantic name remains unreviewed. */

undefined4 * FUN_40a8c65c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  va_list pcVar3;
  
  pcVar3 = (va_list)&DAT_40aa1fc4;
  FUN_40a8b274(param_1,L"CMP3DecoderFilter",0,&DAT_40aa1fc4,param_3,0,0,5);
  param_1[0xc6] = &PTR_LAB_40aa2574;
  *param_1 = &PTR_FUN_40aa29bc;
  param_1[4] = &PTR_LAB_40aa29a8;
  param_1[0xca] = 5;
  param_1[3] = &PTR_FUN_40aa296c;
  uVar2 = 0x288;
  uVar1 = 0;
  param_1[0xc6] = &PTR_LAB_40aa2958;
  param_1[199] = 0x2000;
  param_1[200] = 1;
  param_1[0xc9] = 0x10000;
  memset(param_1 + 0x14,0,0x288);
  FUN_40a8d510(param_1 + 0x14,uVar1,uVar2,pcVar3);
  return param_1;
}



/* 40a8c72c FUN_40a8c72c */

/* Boundary evidence: original MIPS .pdata 40a8c72c..40a8c753. Semantic name remains unreviewed. */

void FUN_40a8c72c(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40a8c754 FUN_40a8c754 */

/* Boundary evidence: original MIPS .pdata 40a8c754..40a8c77b. Semantic name remains unreviewed. */

void FUN_40a8c754(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40a8c77c FUN_40a8c77c */

/* Boundary evidence: original MIPS .pdata 40a8c77c..40a8c7a3. Semantic name remains unreviewed. */

void FUN_40a8c77c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40a8c81c FUN_40a8c81c */

/* Boundary evidence: original MIPS .pdata 40a8c81c..40a8cb1b. Semantic name remains unreviewed. */

int FUN_40a8c81c(int param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *local_78 [2];
  uint local_70;
  int local_6c;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_68 = 0;
  local_64 = 0;
  local_78[0] = (int *)0x0;
  local_70 = 0;
  bVar1 = false;
  local_6c = 0;
  if (param_2 != (int *)0x0) {
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    iVar2 = (**(code **)(*param_2 + 0xc))(param_2,&local_60);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_58 = (**(code **)(*param_2 + 0x10))(param_2);
    local_5c = (**(code **)(*param_2 + 0x2c))(param_2);
    puVar4 = &local_68;
    iVar2 = (**(code **)(*param_2 + 0x14))(param_2,&local_50);
    if (-1 < iVar2) {
      local_54 = local_54 | 0x1000;
    }
    iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
    if (iVar2 == 0) {
      local_54 = local_54 | 0x200;
    }
    iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
    if (iVar2 == 0) {
      local_54 = local_54 | 0x2000;
    }
    iVar2 = FUN_40a8d7d0(&local_60,(int *)(param_1 + 0x50),puVar4,param_4);
    if (iVar2 != 0) {
      return -0x7fffbffb;
    }
  }
  while( true ) {
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    if (((*(int *)(*(int *)(param_1 + 0x2dc) + 0x18) != 0) &&
        (piVar3 = *(int **)(*(int *)(param_1 + 0x2dc) + 0x98),
        iVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,local_78,0,0,0), iVar2 < 0)) ||
       (local_78[0] == (int *)0x0)) {
      return 0;
    }
    iVar2 = (**(code **)(*local_78[0] + 0xc))(local_78[0],&local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    local_30 = (**(code **)(*local_78[0] + 0x10))();
    iVar2 = FUN_40a8d8b4(&local_38,(undefined4 *)(param_1 + 0x50));
    if (iVar2 == 0x20000) {
      bVar1 = true;
    }
    else if (iVar2 != 0) {
      (**(code **)(*local_78[0] + 8))();
      return -0x7fffbffb;
    }
    if (local_34 == 0) {
      iVar2 = (**(code **)(*local_78[0] + 8))();
    }
    else {
      (**(code **)(*local_78[0] + 0x30))();
      if ((local_2c & 0x1000) != 0) {
        local_70 = local_28 + 1;
        local_6c = local_24 + (uint)(local_70 < local_28);
        (**(code **)(*local_78[0] + 0x18))(local_78[0],&local_28,&local_70);
        if ((local_2c & 0x2000) != 0) {
          (**(code **)(*local_78[0] + 0x20))(local_78[0],1);
        }
      }
      iVar2 = FUN_40a8bb08(*(int **)(param_1 + 0x2dc),local_78[0]);
    }
    if (iVar2 != 0) break;
    if (bVar1) {
      return 0;
    }
  }
  return iVar2;
}



/* 40a8cb1c FUN_40a8cb1c */

/* Boundary evidence: original MIPS .pdata 40a8cb1c..40a8cb67. Semantic name remains unreviewed. */

undefined4 * FUN_40a8cb1c(undefined4 *param_1,uint param_2)

{
  FUN_40a8b394(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a8cb68 FUN_40a8cb68 */

/* Boundary evidence: original MIPS .pdata 40a8cb68..40a8cbe3. Semantic name remains unreviewed. */

undefined4 *
FUN_40a8cb68(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,wchar_t *param_5,
            undefined4 param_6,undefined4 param_7)

{
  FUN_40a92534(param_1,param_2,param_3,param_3 + 0x2ec,param_4,param_5);
  *param_1 = &PTR_FUN_40aa2a8c;
  param_1[3] = &PTR_FUN_40aa2a44;
  param_1[4] = &PTR_LAB_40aa2a30;
  param_1[0x28] = 0;
  param_1[0x29] = param_6;
  param_1[0x2a] = param_7;
  param_1[0x2b] = 0;
  return param_1;
}



/* 40a8cbe4 FUN_40a8cbe4 */

/* Boundary evidence: original MIPS .pdata 40a8cbe4..40a8cc0b. Semantic name remains unreviewed. */

void FUN_40a8cbe4(int param_1)

{
  (**(code **)**(undefined4 **)(param_1 + -8))();
  return;
}



/* 40a8cc0c FUN_40a8cc0c */

/* Boundary evidence: original MIPS .pdata 40a8cc0c..40a8cc33. Semantic name remains unreviewed. */

void FUN_40a8cc0c(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 4))();
  return;
}



/* 40a8cc34 FUN_40a8cc34 */

/* Boundary evidence: original MIPS .pdata 40a8cc34..40a8cc5b. Semantic name remains unreviewed. */

void FUN_40a8cc34(int param_1)

{
  (**(code **)(**(int **)(param_1 + -8) + 8))();
  return;
}



/* 40a8cc98 FUN_40a8cc98 */

/* Boundary evidence: original MIPS .pdata 40a8cc98..40a8cd47. Semantic name remains unreviewed. */

void FUN_40a8cc98(undefined4 *param_1)

{
  LPCRITICAL_SECTION p_Var1;
  
  *param_1 = &PTR_FUN_40aa2a8c;
  param_1[3] = &PTR_FUN_40aa2a44;
  param_1[4] = &PTR_LAB_40aa2a30;
  p_Var1 = (LPCRITICAL_SECTION)param_1[0x2b];
  if (p_Var1 != (LPCRITICAL_SECTION)0x0) {
    FUN_40a92e34(p_Var1);
    operator_delete(p_Var1);
    param_1[0x2b] = 0;
  }
  if ((int *)param_1[0x28] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x28] + 8))();
    param_1[0x28] = 0;
  }
  FUN_40a8f8bc((int)param_1);
  return;
}



/* 40a8cd48 FUN_40a8cd48 */

/* Boundary evidence: original MIPS .pdata 40a8cd48..40a8cd77. Semantic name remains unreviewed. */

void FUN_40a8cd48(void)

{
  int *in_v0;
  
  FUN_40a8baec(*in_v0);
  return;
}



/* 40a8cd78 FUN_40a8cd78 */

/* Boundary evidence: original MIPS .pdata 40a8cd78..40a8cdfb. Semantic name remains unreviewed. */

undefined4 * FUN_40a8cd78(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40aa2870;
  param_1[3] = &PTR_FUN_40aa2828;
  param_1[4] = &PTR_LAB_40aa2814;
  param_1[0x26] = &PTR_LAB_40aa27f0;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x36));
  FUN_40a901f4((int)param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a8cdfc FUN_40a8cdfc */

/* Boundary evidence: original MIPS .pdata 40a8cdfc..40a8ce6f. Semantic name remains unreviewed. */

undefined4 * FUN_40a8cdfc(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x330);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_40a8c65c(puVar1,param_1,param_2);
  }
  *param_2 = 0;
  return puVar1;
}



/* 40a8ce70 FUN_40a8ce70 */

/* Boundary evidence: original MIPS .pdata 40a8ce70..40a8ce9f. Semantic name remains unreviewed. */

void FUN_40a8ce70(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x18));
  return;
}



/* 40a8cea0 FUN_40a8cea0 */

/* Boundary evidence: original MIPS .pdata 40a8cea0..40a8cf23. Semantic name remains unreviewed. */

undefined4 * FUN_40a8cea0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40aa29bc;
  param_1[3] = &PTR_FUN_40aa296c;
  param_1[4] = &PTR_LAB_40aa29a8;
  param_1[0xc6] = &PTR_LAB_40aa2958;
  FUN_40a8d590(param_1 + 0x14);
  FUN_40a8b394(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a8cf24 FUN_40a8cf24 */

/* Boundary evidence: original MIPS .pdata 40a8cf24..40a8d07b. Semantic name remains unreviewed. */

undefined4 FUN_40a8cf24(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_20;
  undefined4 *local_1c;
  
  local_20 = 0;
  if (*(int *)(param_1 + 0x2d8) == 0) {
    local_1c = operator_new(0xf0);
    if (local_1c == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40a8c078(local_1c,0,param_1,&local_20,L"Input");
    }
    *(undefined4 **)(param_1 + 0x2d8) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    local_1c = operator_new(0xb0);
    if (local_1c == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_40a8cb68(local_1c,0,param_1,&local_20,L"Output",*(undefined4 *)(param_1 + 0x2e4),
                            *(undefined4 *)(param_1 + 0x2e8));
    }
    *(undefined4 **)(param_1 + 0x2dc) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      piVar3 = *(int **)(param_1 + 0x2d8);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0xc))(piVar3,1);
      }
      *(undefined4 *)(param_1 + 0x2d8) = 0;
    }
  }
  if (param_2 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x2d8);
  }
  else if (param_2 == 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x2dc);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40a8d07c FUN_40a8d07c */

/* Boundary evidence: original MIPS .pdata 40a8d07c..40a8d0ab. Semantic name remains unreviewed. */

void FUN_40a8d07c(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40a8d0ac FUN_40a8d0ac */

/* Boundary evidence: original MIPS .pdata 40a8d0ac..40a8d0db. Semantic name remains unreviewed. */

void FUN_40a8d0ac(void)

{
  int in_v0;
  
  operator_delete(*(void **)(in_v0 + -0x1c));
  return;
}



/* 40a8d0dc FUN_40a8d0dc */

/* Boundary evidence: original MIPS .pdata 40a8d0dc..40a8d127. Semantic name remains unreviewed. */

undefined4 * FUN_40a8d0dc(undefined4 *param_1,uint param_2)

{
  FUN_40a8cc98(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a8d128 FUN_40a8d128 */

/* Boundary evidence: original MIPS .pdata 40a8d128..40a8d173. Semantic name remains unreviewed. */

void FUN_40a8d128(size_t param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  va_list local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  vswprintf((wchar_t *)&DAT_40ab2230,param_1,(wchar_t *)&local_res4,param_4);
  OutputDebugStringW((LPCWSTR)&DAT_40ab2230);
  return;
}



/* 40a8d174 FUN_40a8d174 */

void FUN_40a8d174(char *param_1)

{
  char cVar1;
  short *psVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)0x200;
  pcVar3 = param_1;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar5 = param_1;
  if (pcVar3 + (-1 - (int)param_1) < (char *)0x200) {
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    pcVar4 = pcVar5 + (-1 - (int)param_1);
  }
  pcVar3 = (char *)0x0;
  psVar2 = &DAT_40ab1e30;
  if (pcVar4 != (char *)0x0) {
    do {
      pcVar5 = param_1 + (int)pcVar3;
      pcVar3 = pcVar3 + 1;
      *psVar2 = (short)*pcVar5;
      psVar2 = psVar2 + 1;
    } while (pcVar3 < pcVar4);
  }
  return;
}



/* 40a8d1f4 FUN_40a8d1f4 */

/* Boundary evidence: original MIPS .pdata 40a8d1f4..40a8d287. Semantic name remains unreviewed. */

undefined4 FUN_40a8d1f4(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    FUN_40a8d128(0x40aa2c28,param_2,param_3,param_4);
    return 0x80004005;
  }
  if (*param_1 == 0) {
    uVar2 = 0x847c;
    pvVar1 = calloc(1,0x847c);
    *param_1 = (int)pvVar1;
    if (pvVar1 == (void *)0x0) {
      FUN_40a8d128(0x40aa2bb8,uVar2,param_3,param_4);
      return 0x80004005;
    }
  }
  return 0;
}



/* 40a8d288 FUN_40a8d288 */

/* Boundary evidence: original MIPS .pdata 40a8d288..40a8d33f. Semantic name remains unreviewed. */

undefined4 FUN_40a8d288(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40a8d1f4(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    FUN_40a8d128(0x40aa2cd8,param_2,param_3,param_4);
    return 0x80004005;
  }
  FUN_40a85a48((undefined4 *)*param_1);
  iVar2 = *param_1;
  iVar1 = FUN_40a85178(0x20000,iVar2);
  if (iVar1 != 0) {
    FUN_40a8d128(0x40aa2c88,iVar2,param_3,param_4);
    return 0x80004005;
  }
  param_1[0x4d] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x4e] = 0;
  param_1[0x4c] = 0;
  param_1[0x51] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  return 0;
}



/* 40a8d340 FUN_40a8d340 */

/* Boundary evidence: original MIPS .pdata 40a8d340..40a8d50f. Semantic name remains unreviewed. */

void FUN_40a8d340(va_list param_1,va_list param_2,byte *param_3,int param_4,uint *param_5,
                 int *param_6,undefined4 *param_7)

{
  va_list pcVar1;
  va_list pcVar2;
  va_list pcVar3;
  int iVar4;
  va_list pcVar5;
  uint uVar6;
  uint local_30 [2];
  
  uVar6 = 0;
  if (param_7[0x4a] == 0) {
    param_7[0x9b] = param_4;
    *param_6 = 0;
    pcVar5 = param_2;
    while ((0 < (int)pcVar5 && (uVar6 <= param_4 - 0x2400U))) {
      local_30[0] = param_4 - uVar6;
      if (param_7[0x4a] != 0) {
        *param_5 = 0;
        *param_6 = (int)param_2;
        return;
      }
      pcVar2 = param_1;
      pcVar3 = pcVar5;
      pcVar1 = (va_list)FUN_40a8a460(param_3,local_30,param_1,(int)pcVar5,param_7 + 1,
                                     (int *)*param_7);
      *param_6 = (int)(pcVar1 + *param_6);
      if (local_30[0] == 0x7fffff00) {
        *param_5 = 0x7fffff00;
        *param_6 = (int)param_2;
        return;
      }
      if ((int)pcVar1 < 0) {
        FUN_40a8d128(0x40aa2d2c,pcVar1,pcVar2,pcVar3);
        *param_6 = (int)param_2;
        return;
      }
      iVar4 = param_7[1];
      if ((param_7[0x4f] != iVar4) && (4000 < iVar4)) {
        param_7[0x4f] = iVar4;
        param_7[0x4e] = 1;
      }
      iVar4 = param_7[4];
      if ((param_7[0x50] != iVar4) && (0 < iVar4)) {
        param_7[0x50] = iVar4;
        param_7[0x4e] = 1;
      }
      if (0 < (int)local_30[0]) {
        param_3 = param_3 + local_30[0];
        uVar6 = local_30[0] + uVar6;
      }
      if ((int)pcVar5 < (int)pcVar1) {
        FUN_40a8d128(0x40aa2dac,pcVar1,pcVar5,pcVar3);
        pcVar1 = pcVar5;
      }
      pcVar5 = pcVar5 + -(int)pcVar1;
      param_1 = pcVar1 + (int)param_1;
    }
    *param_5 = uVar6;
  }
  else {
    *param_5 = 0;
  }
  return;
}



/* 40a8d510 FUN_40a8d510 */

/* Boundary evidence: original MIPS .pdata 40a8d510..40a8d58f. Semantic name remains unreviewed. */

undefined4 FUN_40a8d510(int *param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  
  iVar1 = FUN_40a8d1f4(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    FUN_40a8d128(0x40aa2e44,param_2,param_3,param_4);
    return 0x80004005;
  }
  param_1[0x4c] = 1;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x4e] = 1;
  param_1[0x9a] = 0;
  param_1[0x4a] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x49] = 0;
  return 0;
}



/* 40a8d590 FUN_40a8d590 */

/* Boundary evidence: original MIPS .pdata 40a8d590..40a8d5c3. Semantic name remains unreviewed. */

undefined4 FUN_40a8d590(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && ((void *)*param_1 != (void *)0x0)) {
    free((void *)*param_1);
  }
  return 0;
}



/* 40a8d5c4 FUN_40a8d5c4 */

/* Boundary evidence: original MIPS .pdata 40a8d5c4..40a8d693. Semantic name remains unreviewed. */

undefined4 FUN_40a8d5c4(int *param_1,uint param_2,int *param_3,va_list param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = param_2;
  piVar4 = param_3;
  iVar1 = FUN_40a8d1f4(param_3,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (((param_3[0x9a] == 0) || (param_3[0x52] != param_2)) ||
       (iVar1 = memcmp(param_3 + 0x53,param_1,param_3[0x52]), iVar1 != 0)) {
      if (0x80 < param_2) {
        FUN_40a8d128(0x40aa2ea4,param_2,0x80,param_4);
        param_2 = 0x80;
      }
      param_3[0x52] = param_2;
      FUN_40a8a870(param_3 + 0x53,param_1,param_2);
      param_3[0x9a] = 1;
    }
    uVar2 = 0;
  }
  else {
    FUN_40a8d128(0x40aa2ef8,uVar3,piVar4,param_4);
    uVar2 = 0x80004005;
  }
  return uVar2;
}



/* 40a8d694 FUN_40a8d694 */

/* WARNING: Removing unreachable block (ram,0x40a8d75c) */
/* Boundary evidence: original MIPS .pdata 40a8d694..40a8d7cf. Semantic name remains unreviewed. */

undefined4 FUN_40a8d694(undefined1 *param_1,undefined4 param_2,int *param_3,va_list param_4)

{
  undefined1 uVar1;
  int iVar2;
  wchar_t *pwVar3;
  int *piVar4;
  uint uVar5;
  
  piVar4 = param_3;
  iVar2 = FUN_40a8d1f4(param_3,param_2,param_3,param_4);
  if (iVar2 == 0) {
    if (param_3[0x9a] != 0) {
      *param_1 = 1;
      param_1[0x11] = 0;
      param_1[1] = 0;
      param_1[0x10] = 0;
      uVar1 = *(undefined1 *)((int)param_3 + 0x14e);
      param_1[3] = *(undefined1 *)((int)param_3 + 0x14f);
      param_1[2] = uVar1;
      *(int *)(param_1 + 4) = param_3[0x54];
      param_1[0xe] = 0x10;
      param_1[0xf] = 0;
      uVar5 = (int)((uint)CONCAT11(param_1[3],uVar1) * 0x10) >> 3 & 0xffff;
      param_1[0xc] = (char)uVar5;
      param_1[0xd] = (char)(uVar5 >> 8);
      *(uint *)(param_1 + 8) = uVar5 * *(int *)(param_1 + 4);
      return 0;
    }
    pwVar3 = L"MP3DEC: MP3_GetOutput input not initialized\n";
  }
  else {
    pwVar3 = L"MP3DEC: MP3_SetInput check_mp3_structs fail\n";
  }
  FUN_40a8d128((size_t)pwVar3,param_2,piVar4,param_4);
  return 0x80004005;
}



/* 40a8d7d0 FUN_40a8d7d0 */

/* Boundary evidence: original MIPS .pdata 40a8d7d0..40a8d8b3. Semantic name remains unreviewed. */

undefined4 FUN_40a8d7d0(int *param_1,int *param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  int *piVar2;
  
  param_2[0x49] = 0;
  param_2[0x9d] = 0;
  param_2[0x9f] = 0;
  param_2[0x9e] = 0;
  param_2[0xa0] = 0;
  param_2[0xa1] = 0;
  if (param_2[0x4a] == 0) {
    if ((param_2[0x4c] == 0) ||
       (piVar2 = param_2, iVar1 = FUN_40a8d288(param_2,param_2,param_3,param_4), iVar1 == 0)) {
      param_2[0x9f] = param_1[3];
      if ((param_1[3] & 0x1000U) == 0) {
        param_2[0xa0] = 0;
        param_2[0xa1] = 0;
      }
      else {
        param_2[0xa0] = param_1[4];
        param_2[0xa1] = param_1[5];
        param_2[0x73] = 1;
      }
      param_2[0x9c] = *param_1;
      param_2[0x9e] = 0;
      param_2[0x9d] = param_1[1];
      param_2[0x4b] = 0;
    }
    else {
      FUN_40a8d128(0x40aa2fb0,piVar2,param_3,param_4);
      param_2[0x4c] = 1;
    }
  }
  else {
    param_2[0x9d] = 0;
    param_2[0x9f] = 0;
  }
  return 0;
}



/* 40a8d8b4 FUN_40a8d8b4 */

/* WARNING: Removing unreachable block (ram,0x40a8ddc0) */
/* Boundary evidence: original MIPS .pdata 40a8d8b4..40a8deef. Semantic name remains unreviewed. */

undefined4 FUN_40a8d8b4(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int local_28;
  uint local_24;
  
  uVar1 = param_1[2];
  iVar2 = param_2[0x49];
  if (0x8000 < uVar1) {
    uVar1 = 0x8000;
  }
  param_1[3] = 0;
  param_1[1] = 0;
  if (param_2[0x4a] == 0) {
    if ((param_2[0x9d] != 0) || (iVar2 != 0)) {
      param_1[4] = 0;
      param_1[5] = 0;
      if ((va_list)param_2[0x9d] != (va_list)0x0) {
        param_2[0x4b] = 0;
        FUN_40a8d340((va_list)(param_2[0x9c] + param_2[0x9e]),(va_list)param_2[0x9d],
                     (byte *)(param_1[1] + *param_1),uVar1,&local_24,&local_28,param_2);
        param_2[0x9e] = local_28 + param_2[0x9e];
        param_2[0x9d] = param_2[0x9d] - local_28;
        param_1[1] = local_24;
        uVar1 = param_2[0x9f];
        if ((uVar1 & 0x200) != 0) {
          param_2[0x51] = param_2[0x51] | 0x200;
        }
        if ((uVar1 & 0x1000) != 0) {
          param_2[0x7a] = param_2[0xa0];
          param_2[0x7b] = param_2[0xa1];
          param_2[0x51] = param_2[0x51] | 0x1000;
        }
        if ((uVar1 & 0x2000) != 0) {
          param_2[0x51] = param_2[0x51] | 0x2000;
        }
      }
    }
    if (param_2[0x4a] == 0) {
      if ((param_2[0x4b] != 0) || (param_1[1] == 0x7fffff00)) {
        param_2[0x4b] = 1;
        param_1[1] = param_1[2];
        memset((void *)*param_1,0,param_1[2]);
      }
      uVar1 = param_1[1];
      if (((int)uVar1 < 0) || ((uint)param_1[2] < uVar1)) {
        FUN_40a8d128(0x40aa3014,uVar1,uVar1,(va_list)param_1[2]);
        param_1[1] = 0;
      }
      if (param_1[1] != 0) {
        param_2[0x9f] = 0;
        param_2[0xa0] = 0;
        param_2[0xa1] = 0;
        lVar6 = 0;
        if ((param_2[0x50] != 0) && (lVar6 = 0, 1000 < (uint)param_2[0x4f])) {
          if ((int)param_2[0x76] < 0) {
            param_2[0x76] = 0;
          }
          uVar1 = param_2[0x50] << 1;
          uVar5 = (uint)param_2[0x76] / uVar1;
          if (uVar1 == 0) {
            trap(0x1c00);
          }
          uVar1 = uVar5 + param_2[0x74];
          iVar2 = param_2[0x75] + (uint)(uVar1 < uVar5);
          param_2[0x74] = uVar1;
          param_2[0x75] = iVar2;
          if ((iVar2 < 1) && (iVar2 != 0)) {
            param_2[0x74] = 0;
            param_2[0x75] = 0;
          }
          lVar6 = __ll_div((int)((ulonglong)(uint)param_2[0x74] * 10000000),
                           param_2[0x75] * 10000000 +
                           (int)((ulonglong)(uint)param_2[0x74] * 10000000 >> 0x20),param_2[0x4f],0)
          ;
        }
        param_2[0x76] = param_1[1];
        if ((param_2[0x51] & 0x1000) == 0) {
          if (param_2[0x73] != 0) {
            *(longlong *)(param_1 + 4) = lVar6 + *(longlong *)(param_2 + 0x78);
            param_1[3] = param_1[3] | 0x1000;
          }
        }
        else {
          param_1[3] = param_1[3] | 0x1000;
          param_1[4] = param_2[0x7a];
          param_1[5] = param_2[0x7b];
          param_2[0x78] = param_2[0x7a];
          param_2[0x79] = param_2[0x7b];
          param_2[0x74] = 0;
          param_2[0x75] = 0;
        }
        if ((param_2[0x51] & 0x200) != 0) {
          param_1[3] = param_1[3] | 0x200;
        }
        if ((param_2[0x51] & 0x2000) != 0) {
          param_1[3] = param_1[3] | 0x2000;
        }
        if (param_2[0x4e] != 0) {
          param_2[0x7c] = 0xf;
          param_2[0x81] = 0xfff3;
          param_2[0x7d] = 7;
          uVar1 = param_2[0x4f];
          param_2[0x7e] = 0xfffa;
          param_2[0x82] = 0xffff;
          param_2[0x84] = param_2[0x50];
          param_2[0x7f] = 3;
          param_2[0x80] = 0xfff4;
          param_2[0x83] = 8;
          param_2[0x85] = 8;
          uVar5 = param_2[0x9b];
          param_2[0x86] = uVar1 & 0xf;
          param_2[0x87] = uVar1 >> 4 & 0xf;
          param_2[0x88] = uVar1 >> 8 & 0xf;
          param_2[0x89] = uVar1 >> 0xc & 0xf;
          param_2[0x8a] = uVar1 >> 0x10 & 0xf;
          param_2[0x8b] = uVar1 >> 0x14 & 0xf;
          param_2[0x8c] = uVar5 & 0xf;
          param_2[0x8d] = uVar5 >> 4 & 0xf;
          param_2[0x8e] = uVar5 >> 8 & 0xf;
          param_2[0x8f] = uVar5 >> 0xc & 0xf;
          param_2[0x90] = uVar5 >> 0x10 & 0xf;
          param_2[0x91] = uVar5 >> 0x14 & 0xf;
          param_2[0x4e] = 0;
          FUN_40a8a870((int *)*param_1,param_2 + 0x7c,0x60);
        }
        if (param_2[0x4b] != 0) {
          iVar2 = param_2[0x50];
          if ((iVar2 == 0) || (uVar1 = param_2[0x4f], uVar1 < 0x3e9)) {
            param_2[0x4b] = 0;
            param_1[4] = 0;
            param_1[5] = 0;
            param_1[3] = 0;
            param_1[1] = 0;
            param_2[0x9d] = 0;
          }
          else {
            iVar4 = param_2[0x74];
            uVar5 = (uint)param_1[1] / (uint)(iVar2 << 1);
            if (iVar2 << 1 == 0) {
              trap(0x1c00);
            }
            uVar3 = uVar5 + iVar4;
            lVar6 = (ulonglong)uVar3 * 10000000;
            lVar6 = __ll_div((int)lVar6,
                             (((int)uVar5 >> 0x1f) + param_2[0x75] + (uint)(uVar3 < uVar5)) *
                             10000000 + (int)((ulonglong)lVar6 >> 0x20),uVar1,0);
            if (5000000 < lVar6) {
              param_2[0x4b] = 0;
              iVar2 = ((uVar1 * 500) / 1000 - iVar4) * iVar2 * 2;
              param_1[1] = iVar2;
              if (iVar2 < 1) {
                param_1[1] = (uint)param_1[2] >> 2;
                param_2[0x76] = (uint)param_1[2] >> 2;
                memset((void *)*param_1,0,param_1[1]);
              }
            }
          }
        }
        param_2[0x7a] = 0;
        param_2[0x7b] = 0;
        param_2[0x51] = 0;
        iVar2 = param_1[5];
        if ((iVar2 < 1) && (iVar2 != 0)) {
          if ((iVar2 < -1) || ((iVar2 == -1 && ((uint)param_1[4] < 0xfff0bdc1)))) {
            param_1[3] = 0;
            param_1[1] = 0;
          }
          else {
            param_1[3] = param_1[3] | 0x1000;
          }
          param_1[5] = 0;
          param_1[4] = 0;
        }
        if (((param_2[0x49] == 0) && (param_2[0x9d] == 0)) && (param_2[0x4b] == 0)) {
          return 0x20000;
        }
        return 0;
      }
    }
    else {
      param_2[0x9d] = 0;
      param_2[0x9f] = 0;
    }
    param_1[1] = 0;
  }
  else {
    param_1[1] = 0;
    param_2[0x9f] = 0;
    param_2[0x9d] = 0;
  }
  return 0x20000;
}



/* 40a8def0 FUN_40a8def0 */

undefined4 FUN_40a8def0(int param_1)

{
  *(undefined4 *)(param_1 + 0x128) = 1;
  return 0;
}



/* 40a8df00 FUN_40a8df00 */

/* Boundary evidence: original MIPS .pdata 40a8df00..40a8dfbb. Semantic name remains unreviewed. */

undefined4 FUN_40a8df00(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  va_list pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  pcVar3 = (va_list)*param_1;
  puVar2 = &uStack_18;
  puVar1 = &uStack_14;
  FUN_40a85374(param_1 + 1,puVar1,puVar2,(int)pcVar3);
  iVar5 = param_1[1];
  iVar4 = param_1[3];
  FUN_40a8d288(param_1,puVar1,puVar2,pcVar3);
  param_1[0x4e] = 0;
  param_1[0x51] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x78] = 0;
  param_1[0x79] = 0;
  param_1[0x76] = 0;
  param_1[0x74] = 0;
  param_1[0x75] = 0;
  param_1[0x73] = 0;
  param_1[0x49] = 0;
  param_1[0x9d] = 0;
  param_1[0x9f] = 0;
  param_1[0xa0] = 0;
  param_1[0xa1] = 0;
  param_1[0x9e] = 0;
  param_1[0x4a] = 0;
  FUN_40a84cc8(iVar5,iVar4,8,3,*param_1);
  return 0;
}



/* 40a8dfbc FUN_40a8dfbc */

undefined4 FUN_40a8dfbc(int param_1)

{
  *(undefined4 *)(param_1 + 0x124) = 1;
  *(undefined4 *)(param_1 + 0x1cc) = 0;
  *(undefined4 *)(param_1 + 0x1d0) = 0;
  *(undefined4 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  return 0;
}



/* 40a8dfdc FUN_40a8dfdc */

/* Boundary evidence: original MIPS .pdata 40a8dfdc..40a8e0b3. Semantic name remains unreviewed. */

undefined4 FUN_40a8dfdc(int param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  va_list pcVar4;
  int iStack_28;
  undefined4 uStack_24;
  
  piVar1 = param_4 + 1;
  *param_3 = 4;
  pcVar4 = (va_list)*param_4;
  piVar2 = &iStack_28;
  FUN_40a85374(piVar1,&uStack_24,piVar2,(int)pcVar4);
  if (param_1 == 0x500d) {
    *param_3 = 0x120;
    uVar3 = 0x120;
  }
  else {
    if (param_1 != 0x500e) {
      FUN_40a8d128(0x40aa3074,param_1,piVar2,pcVar4);
      *param_2 = 0;
      return 0x80004005;
    }
    *param_3 = 4;
    uVar3 = 4;
    piVar1 = &iStack_28;
  }
  FUN_40a8a870(param_2,piVar1,uVar3);
  return 0;
}



/* 40a8e0b4 FUN_40a8e0b4 */

/* Boundary evidence: original MIPS .pdata 40a8e0b4..40a8e1ff. Semantic name remains unreviewed. */

undefined4 FUN_40a8e0b4(HKEY param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  LSTATUS LVar3;
  int iVar4;
  HKEY local_238;
  DWORD local_234;
  _FILETIME _Stack_230;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_40ab1828;
  sVar1 = wcslen(param_2);
  if (sVar1 == 0) {
    FUN_40a93fe4(local_20);
    uVar2 = 0x80004005;
  }
  else {
    LVar3 = RegOpenKeyExW(param_1,param_2,0,0x2000000,&local_238);
    if (LVar3 == 0) {
      local_234 = 0x104;
      iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0
                            ,&_Stack_230);
      while (iVar4 == 0) {
        FUN_40a8e0b4(local_238,aWStack_228);
        local_234 = 0x104;
        iVar4 = RegEnumKeyExW(local_238,0,aWStack_228,&local_234,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,&_Stack_230);
      }
      RegCloseKey(local_238);
      RegDeleteKeyW(param_1,param_2);
    }
    FUN_40a93fe4(local_20);
    uVar2 = 0;
  }
  return uVar2;
}



/* 40a8e200 FUN_40a8e200 */

/* Boundary evidence: original MIPS .pdata 40a8e200..40a8e48f. Semantic name remains unreviewed. */

uint FUN_40a8e200(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  size_t sVar2;
  HKEY local_2a8;
  HKEY local_2a4;
  DWORD aDStack_2a0 [2];
  GUID local_298;
  OLECHAR aOStack_288 [40];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40ab1828;
  local_298.Data1 = param_1;
  local_298._4_4_ = param_2;
  local_298.Data4._0_4_ = param_3;
  local_298.Data4._4_4_ = param_4;
  StringFromGUID2(&local_298,aOStack_288,0x27);
  wsprintfW(aWStack_238,L"CLSID\\%ls",aOStack_288);
  uVar1 = RegCreateKeyExW((HKEY)0x80000000,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,
                          &local_2a8,aDStack_2a0);
  if (uVar1 == 0) {
    wsprintfW(aWStack_238,L"%ls",param_5);
    sVar2 = wcslen(aWStack_238);
    uVar1 = RegSetValueExW(local_2a8,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
    if (uVar1 == 0) {
      wsprintfW(aWStack_238,L"%ls",param_8);
      uVar1 = RegCreateKeyExW(local_2a8,aWStack_238,0,L"",0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_2a4,
                              aDStack_2a0);
      if (uVar1 == 0) {
        wsprintfW(aWStack_238,L"%ls",param_6);
        sVar2 = wcslen(aWStack_238);
        uVar1 = RegSetValueExW(local_2a4,L"",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2);
        if (uVar1 == 0) {
          wsprintfW(aWStack_238,L"%ls",param_7);
          sVar2 = wcslen(aWStack_238);
          uVar1 = RegSetValueExW(local_2a4,L"ThreadingModel",0,1,(BYTE *)aWStack_238,(sVar2 + 1) * 2
                                );
        }
        RegCloseKey(local_2a8);
        local_2a8 = local_2a4;
      }
    }
    RegCloseKey(local_2a8);
  }
  if (0 < (int)uVar1) {
    uVar1 = uVar1 & 0xffff | 0x80070000;
  }
  FUN_40a93fe4(local_30);
  return uVar1;
}



/* 40a8e490 FUN_40a8e490 */

/* Boundary evidence: original MIPS .pdata 40a8e490..40a8e503. Semantic name remains unreviewed. */

undefined4 FUN_40a8e490(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  GUID local_278;
  OLECHAR aOStack_268 [40];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_40ab1828;
  local_278.Data1 = param_1;
  local_278._4_4_ = param_2;
  local_278.Data4._0_4_ = param_3;
  local_278.Data4._4_4_ = param_4;
  StringFromGUID2(&local_278,aOStack_268,0x27);
  wsprintfW(aWStack_218,L"CLSID\\%ls",aOStack_268);
  FUN_40a8e0b4((HKEY)0x80000000,aWStack_218);
  FUN_40a93fe4(local_10);
  return 0;
}



/* 40a8e504 FUN_40a8e504 */

/* Boundary evidence: original MIPS .pdata 40a8e504..40a8e73b. Semantic name remains unreviewed. */

DWORD FUN_40a8e504(void)

{
  DWORD DVar1;
  ulong *puVar2;
  DWORD DVar3;
  int iVar4;
  undefined **ppuVar5;
  int *local_240 [2];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_40ab1828;
  DVar3 = 0;
  DVar1 = GetModuleFileNameW(DAT_40ab274c,aWStack_238,0x104);
  if (DVar1 == 0) {
    DVar3 = GetLastError();
    if (0 < (int)DVar3) {
      DVar3 = DVar3 & 0xffff | 0x80070000;
    }
  }
  else {
    iVar4 = 0;
    if (0 < DAT_40ab1814) {
      ppuVar5 = &PTR_u_Alchemy_MP3_Decoder_Filter_40ab1800;
      do {
        puVar2 = (ulong *)ppuVar5[1];
        DVar3 = FUN_40a8e200(*puVar2,puVar2[1],puVar2[2],puVar2[3],*ppuVar5,aWStack_238,L"Both",
                             L"InprocServer32");
        if ((int)DVar3 < 0) break;
        if (ppuVar5[2] != (undefined *)0x0) {
          CoInitializeEx((LPVOID)0x0,0);
          DVar3 = CoCreateInstance((IID *)ppuVar5[1],(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa475c,local_240
                                  );
          if ((int)DVar3 < 0) {
            if ((DVar3 == 0x80004002) || (DVar3 == 0x80040202)) {
              DVar3 = 0;
            }
          }
          else {
            DVar3 = (**(code **)(*local_240[0] + 0x10))();
            if (-1 < (int)DVar3) {
              DVar3 = (**(code **)(*local_240[0] + 0xc))();
            }
            (**(code **)(*local_240[0] + 8))();
          }
          CoFreeUnusedLibraries();
          CoUninitialize();
        }
        if ((int)DVar3 < 0) break;
        iVar4 = iVar4 + 1;
        ppuVar5 = ppuVar5 + 5;
      } while (iVar4 < DAT_40ab1814);
    }
  }
  FUN_40a93fe4(local_30);
  return DVar3;
}



/* 40a8e73c FUN_40a8e73c */

/* Boundary evidence: original MIPS .pdata 40a8e73c..40a8e8c3. Semantic name remains unreviewed. */

int FUN_40a8e73c(void)

{
  ulong *puVar1;
  HRESULT HVar2;
  int iVar3;
  undefined **ppuVar4;
  int *local_30 [2];
  undefined **ppuVar5;
  
  HVar2 = 0;
  if (DAT_40ab1814 != 0) {
    iVar3 = DAT_40ab1814;
    ppuVar4 = &PTR_DAT_40ab1804 + DAT_40ab1814 * 5;
    while( true ) {
      ppuVar5 = ppuVar4 + -5;
      iVar3 = iVar3 + -1;
      if (ppuVar4[-4] != (undefined *)0x0) {
        CoInitializeEx((LPVOID)0x0,0);
        HVar2 = CoCreateInstance((IID *)*ppuVar5,(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa475c,local_30);
        if (HVar2 < 0) {
          if ((HVar2 == -0x7fffbffe) || (HVar2 == -0x7ffbfdfe)) {
            HVar2 = 0;
          }
        }
        else {
          HVar2 = (**(code **)(*local_30[0] + 0x10))();
          (**(code **)(*local_30[0] + 8))();
        }
        CoFreeUnusedLibraries();
        CoUninitialize();
      }
      if (HVar2 < 0) break;
      puVar1 = (ulong *)*ppuVar5;
      HVar2 = FUN_40a8e490(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
      if (HVar2 < 0) {
        return HVar2;
      }
      ppuVar4 = ppuVar5;
      if (iVar3 == 0) {
        return HVar2;
      }
    }
  }
  return HVar2;
}



/* 40a8e8c4 FUN_40a8e8c4 */

/* Boundary evidence: original MIPS .pdata 40a8e8c4..40a8e8f7. Semantic name remains unreviewed. */

void FUN_40a8e8c4(int param_1)

{
  if (param_1 == 0) {
    FUN_40a8e73c();
  }
  else {
    FUN_40a8e504();
  }
  return;
}



/* 40a8e93c FUN_40a8e93c */

/* Boundary evidence: original MIPS .pdata 40a8e93c..40a8e9bb. Semantic name remains unreviewed. */

void FUN_40a8e93c(undefined4 param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_40ab1814) {
    ppuVar2 = &PTR_DAT_40ab1804;
    iVar1 = DAT_40ab1814;
    do {
      if ((code *)ppuVar2[2] != (code *)0x0) {
        (*(code *)ppuVar2[2])(param_1,*ppuVar2);
        iVar1 = DAT_40ab1814;
      }
      iVar3 = iVar3 + 1;
      ppuVar2 = ppuVar2 + 5;
    } while (iVar3 < iVar1);
  }
  return;
}



/* 40a8e9bc FUN_40a8e9bc */

/* Boundary evidence: original MIPS .pdata 40a8e9bc..40a8ea5b. Semantic name remains unreviewed. */

undefined4 FUN_40a8e9bc(HMODULE param_1,int param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    DisableThreadLibraryCalls(param_1);
    DAT_40ab2748 = 1;
    DAT_40ab2634 = 0x114;
    BVar1 = GetVersionExW((LPOSVERSIONINFOW)&DAT_40ab2634);
    if (BVar1 != 0) {
      DAT_40ab2748 = DAT_40ab2644;
    }
    uVar2 = 1;
    DAT_40ab274c = param_1;
  }
  FUN_40a8e93c(uVar2);
  return 1;
}



/* 40a8ea5c FUN_40a8ea5c */

undefined4 FUN_40a8ea5c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  if ((((*piVar2 != *param_2) || (piVar2[1] != param_2[1])) || (piVar2[2] != param_2[2])) ||
     (uVar1 = 1, piVar2[3] != param_2[3])) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a8eaac FUN_40a8eaac */

/* Boundary evidence: original MIPS .pdata 40a8eaac..40a8eb57. Semantic name remains unreviewed. */

undefined4 FUN_40a8eaac(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    iVar2 = memcmp(param_2,&DAT_40aa4f18,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40aa4f08,0x10), iVar2 == 0)) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40a8eb58 FUN_40a8eb58 */

/* Boundary evidence: original MIPS .pdata 40a8eb58..40a8ebaf. Semantic name remains unreviewed. */

void * FUN_40a8eb58(void *param_1,uint param_2)

{
  FUN_40a92710();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a8ebb0 FUN_40a8ebb0 */

/* Boundary evidence: original MIPS .pdata 40a8ebb0..40a8ecd3. Semantic name remains unreviewed. */

int FUN_40a8ebb0(int param_1,int param_2,void *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int local_20 [2];
  
  if (param_4 == 0) {
    local_20[0] = -0x7fffbffd;
  }
  else if ((param_2 == 0) || (iVar1 = memcmp(param_3,&DAT_40aa4f18,0x10), iVar1 == 0)) {
    local_20[0] = 0;
    piVar2 = (int *)(**(code **)(*(int *)(param_1 + 4) + 8))(param_2,local_20);
    if (piVar2 == (int *)0x0) {
      if (-1 < local_20[0]) {
        local_20[0] = -0x7ff8fff2;
      }
    }
    else if (local_20[0] < 0) {
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
    }
    else {
      (**(code **)(*piVar2 + 4))(piVar2);
      local_20[0] = (**(code **)*piVar2)(piVar2,param_3,param_4);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  else {
    local_20[0] = -0x7fffbffe;
  }
  return local_20[0];
}



/* 40a8ecd4 DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0xecd4  1  DllCanUnloadNow */
  if ((0 < DAT_40ab2750) || (HVar1 = 0, DAT_40ab2758 != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40a8ed00 FUN_40a8ed00 */

/* Boundary evidence: original MIPS .pdata 40a8ed00..40a8ed5b. Semantic name remains unreviewed. */

undefined4 * FUN_40a8ed00(undefined4 *param_1,undefined4 param_2)

{
  FUN_40a926e0(param_1 + 1);
  param_1[1] = param_2;
  *param_1 = &PTR_FUN_40aa4c48;
  param_1[2] = 0;
  return param_1;
}



/* 40a8ed5c FUN_40a8ed5c */

/* Boundary evidence: original MIPS .pdata 40a8ed5c..40a8ed8b. Semantic name remains unreviewed. */

int FUN_40a8ed5c(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8) + -1;
  *(int *)((int)param_1 + 8) = iVar1;
  if (iVar1 == 0) {
    FUN_40a8eb58(param_1,1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 40a8ed8c DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 40a8ed8c..40a8eeb3. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined **ppuVar6;
  int iVar7;
  
                    /* 0xed8c  2  DllGetClassObject */
  iVar1 = memcmp(riid,&DAT_40aa4f18,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(riid,&DAT_40aa4f08,0x10), iVar1 == 0)) {
    iVar1 = DAT_40ab1814;
    iVar7 = 0;
    if (0 < DAT_40ab1814) {
      ppuVar6 = &PTR_u_Alchemy_MP3_Decoder_Filter_40ab1800;
      do {
        iVar3 = FUN_40a8ea5c((int)ppuVar6,(int *)rclsid);
        if (iVar3 != 0) {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = FUN_40a8ed00(puVar4,ppuVar6);
          }
          *ppv = piVar5;
          if (piVar5 == (int *)0x0) {
            return -0x7ff8fff2;
          }
          (**(code **)(*piVar5 + 4))(piVar5);
          return 0;
        }
        iVar7 = iVar7 + 1;
        ppuVar6 = ppuVar6 + 5;
      } while (iVar7 < iVar1);
    }
    HVar2 = -0x7ffbfeef;
  }
  else {
    HVar2 = -0x7fffbffe;
  }
  return HVar2;
}



/* 40a8eeb4 FUN_40a8eeb4 */

/* Boundary evidence: original MIPS .pdata 40a8eeb4..40a8ef4f. Semantic name remains unreviewed. */

LPVOID FUN_40a8eeb4(int param_1,uint param_2)

{
  LPVOID pvVar1;
  
  if (*(uint *)(param_1 + 0x40) != param_2) {
    pvVar1 = CoTaskMemAlloc(param_2);
    if (pvVar1 != (LPVOID)0x0) {
      if (*(uint *)(param_1 + 0x40) != 0) {
        CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
      }
      *(uint *)(param_1 + 0x40) = param_2;
      *(LPVOID *)(param_1 + 0x44) = pvVar1;
      return pvVar1;
    }
    if (*(uint *)(param_1 + 0x40) < param_2) {
      return (LPVOID)0x0;
    }
  }
  return *(LPVOID *)(param_1 + 0x44);
}



/* 40a8ef50 FUN_40a8ef50 */

/* Boundary evidence: original MIPS .pdata 40a8ef50..40a8ef8b. Semantic name remains unreviewed. */

void FUN_40a8ef50(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return;
}



/* 40a8ef8c FUN_40a8ef8c */

/* Boundary evidence: original MIPS .pdata 40a8ef8c..40a8f01f. Semantic name remains unreviewed. */

void FUN_40a8ef8c(void *param_1,void *param_2)

{
  LPVOID _Dst;
  
  memcpy(param_1,param_2,0x48);
  if (*(SIZE_T *)((int)param_2 + 0x40) != 0) {
    _Dst = CoTaskMemAlloc(*(SIZE_T *)((int)param_2 + 0x40));
    *(LPVOID *)((int)param_1 + 0x44) = _Dst;
    if (_Dst == (LPVOID)0x0) {
      *(undefined4 *)((int)param_1 + 0x40) = 0;
    }
    else {
      memcpy(_Dst,*(void **)((int)param_2 + 0x44),*(size_t *)((int)param_1 + 0x40));
    }
  }
  if (*(int **)((int)param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)((int)param_1 + 0x3c) + 4))();
  }
  return;
}



/* 40a8f020 FUN_40a8f020 */

/* Boundary evidence: original MIPS .pdata 40a8f020..40a8f083. Semantic name remains unreviewed. */

void FUN_40a8f020(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40a8f084 FUN_40a8f084 */

/* Boundary evidence: original MIPS .pdata 40a8f084..40a8f09f. Semantic name remains unreviewed. */

void FUN_40a8f084(int param_1)

{
  FUN_40a8f020(param_1);
  return;
}



/* 40a8f0a0 FUN_40a8f0a0 */

/* Boundary evidence: original MIPS .pdata 40a8f0a0..40a8f0df. Semantic name remains unreviewed. */

void * FUN_40a8f0a0(void *param_1)

{
  memset(param_1,0,0x48);
  *(undefined4 *)((int)param_1 + 0x28) = 1;
  *(undefined4 *)((int)param_1 + 0x20) = 1;
  return param_1;
}



/* 40a8f0e0 FUN_40a8f0e0 */

/* Boundary evidence: original MIPS .pdata 40a8f0e0..40a8f12b. Semantic name remains unreviewed. */

void * FUN_40a8f0e0(void *param_1,void *param_2)

{
  if (param_2 != param_1) {
    FUN_40a8f020((int)param_1);
    FUN_40a8ef8c(param_1,param_2);
  }
  return param_1;
}



/* 40a8f12c FUN_40a8f12c */

/* Boundary evidence: original MIPS .pdata 40a8f12c..40a8f157. Semantic name remains unreviewed. */

void * FUN_40a8f12c(void *param_1,void *param_2)

{
  FUN_40a8f0e0(param_1,param_2);
  return param_1;
}



/* 40a8f158 FUN_40a8f158 */

/* Boundary evidence: original MIPS .pdata 40a8f158..40a8f1c3. Semantic name remains unreviewed. */

undefined4 FUN_40a8f158(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40aa4ef8,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)param_1 + 0x2c),&DAT_40aa4ef8,0x10), iVar1 == 0)
     ) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40a8f1c4 FUN_40a8f1c4 */

/* Boundary evidence: original MIPS .pdata 40a8f1c4..40a8f2d7. Semantic name remains unreviewed. */

undefined4 FUN_40a8f1c4(void *param_1,void *param_2)

{
  int iVar1;
  size_t _Size;
  
  iVar1 = memcmp(param_2,&DAT_40aa4ef8,0x10);
  if ((iVar1 == 0) || (iVar1 = memcmp(param_1,param_2,0x10), iVar1 == 0)) {
    iVar1 = memcmp((void *)((int)param_2 + 0x10),&DAT_40aa4ef8,0x10);
    if ((iVar1 == 0) ||
       (iVar1 = memcmp((void *)((int)param_1 + 0x10),(void *)((int)param_2 + 0x10),0x10), iVar1 == 0
       )) {
      iVar1 = memcmp((void *)((int)param_2 + 0x2c),&DAT_40aa4ef8,0x10);
      if ((iVar1 == 0) ||
         (((iVar1 = memcmp((void *)((int)param_1 + 0x2c),(void *)((int)param_2 + 0x2c),0x10),
           iVar1 == 0 &&
           (_Size = *(size_t *)((int)param_1 + 0x40), _Size == *(size_t *)((int)param_2 + 0x40))) &&
          ((_Size == 0 ||
           (iVar1 = memcmp(*(void **)((int)param_1 + 0x44),*(void **)((int)param_2 + 0x44),_Size),
           iVar1 == 0)))))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 40a8f2d8 FUN_40a8f2d8 */

/* Boundary evidence: original MIPS .pdata 40a8f2d8..40a8f317. Semantic name remains unreviewed. */

void FUN_40a8f2d8(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40a8f020((int)param_1);
    CoTaskMemFree(param_1);
  }
  return;
}



/* 40a8f318 FUN_40a8f318 */

/* Boundary evidence: original MIPS .pdata 40a8f318..40a8f41b. Semantic name remains unreviewed. */

HRESULT FUN_40a8f318(LPUNKNOWN param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  HRESULT HVar1;
  int *local_20;
  int *local_1c;
  
  *param_4 = 0;
  HVar1 = CoCreateInstance((IID *)&DAT_40aa3b5c,param_1,1,(IID *)&DAT_40aa4f18,&local_20);
  if (-1 < HVar1) {
    HVar1 = (**(code **)*local_20)(local_20,&UNK_40aa48fc,&local_1c);
    if (-1 < HVar1) {
      HVar1 = (**(code **)(*local_1c + 0xc))(local_1c,param_2,param_3);
      (**(code **)(*local_1c + 8))();
      if (-1 < HVar1) {
        *param_4 = local_20;
        return 0;
      }
    }
    (**(code **)(*local_20 + 8))();
  }
  return HVar1;
}



/* 40a8f484 FUN_40a8f484 */

/* Boundary evidence: original MIPS .pdata 40a8f484..40a8f50f. Semantic name remains unreviewed. */

undefined4 FUN_40a8f484(int param_1,short *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (short *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(short **)(param_1 + 0x30) == (short *)0x0) {
      *param_2 = 0;
    }
    else {
      FUN_40a93a30(param_2,*(short **)(param_1 + 0x30),0x80);
    }
    *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(param_1 + 0x34);
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x34) + 4))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a8f510 FUN_40a8f510 */

/* Boundary evidence: original MIPS .pdata 40a8f510..40a8f54f. Semantic name remains unreviewed. */

undefined4 FUN_40a8f510(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x44) == (int *)0x0) {
    uVar1 = 0x80004001;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x44) + 0xc))();
  }
  return uVar1;
}



/* 40a8f558 FUN_40a8f558 */

/* Boundary evidence: original MIPS .pdata 40a8f558..40a8f5a3. Semantic name remains unreviewed. */

void FUN_40a8f558(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40aa4c5c;
  (**(code **)(*(int *)(param_1[3] + 0xc) + 8))();
  FUN_40a93d8c(param_1 + 6);
  return;
}



/* 40a8f5a4 FUN_40a8f5a4 */

/* Boundary evidence: original MIPS .pdata 40a8f5a4..40a8f63b. Semantic name remains unreviewed. */

undefined4 FUN_40a8f5a4(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40aa468c,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40aa4f18,0x10), iVar2 == 0)) {
      uVar1 = FUN_40a92768(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40a8f63c FUN_40a8f63c */

/* Boundary evidence: original MIPS .pdata 40a8f63c..40a8f657. Semantic name remains unreviewed. */

void FUN_40a8f63c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x14));
  return;
}



/* 40a8f658 FUN_40a8f658 */

/* Boundary evidence: original MIPS .pdata 40a8f658..40a8f6b3. Semantic name remains unreviewed. */

LONG FUN_40a8f658(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 5);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40a8f6b4 FUN_40a8f6b4 */

/* Boundary evidence: original MIPS .pdata 40a8f6b4..40a8f713. Semantic name remains unreviewed. */

undefined4 FUN_40a8f6b4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  FUN_40a93b3c((undefined4 *)(param_1 + 0x18));
  return 0;
}



/* 40a8f714 FUN_40a8f714 */

/* Boundary evidence: original MIPS .pdata 40a8f714..40a8f76b. Semantic name remains unreviewed. */

undefined4 FUN_40a8f714(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x18))();
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 4) = 0;
  return 0;
}



/* 40a8f76c FUN_40a8f76c */

/* Boundary evidence: original MIPS .pdata 40a8f76c..40a8f803. Semantic name remains unreviewed. */

undefined4 FUN_40a8f76c(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40aa469c,0x10);
    if ((iVar2 == 0) || (iVar2 = memcmp(param_2,&DAT_40aa4f18,0x10), iVar2 == 0)) {
      uVar1 = FUN_40a92768(param_1,param_3);
    }
    else {
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40a8f804 FUN_40a8f804 */

/* Boundary evidence: original MIPS .pdata 40a8f804..40a8f81f. Semantic name remains unreviewed. */

void FUN_40a8f804(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x10));
  return;
}



/* 40a8f820 FUN_40a8f820 */

/* Boundary evidence: original MIPS .pdata 40a8f820..40a8f87b. Semantic name remains unreviewed. */

LONG FUN_40a8f820(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 4);
  if ((LVar1 == 0) && (param_1 != (int *)0x0)) {
    (**(code **)(*param_1 + 0x1c))(param_1,1);
  }
  return LVar1;
}



/* 40a8f87c FUN_40a8f87c */

/* Boundary evidence: original MIPS .pdata 40a8f87c..40a8f8bb. Semantic name remains unreviewed. */

undefined4 FUN_40a8f87c(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 4) = 0;
  uVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  return 0;
}



/* 40a8f8bc FUN_40a8f8bc */

/* Boundary evidence: original MIPS .pdata 40a8f8bc..40a8f8ff. Semantic name remains unreviewed. */

void FUN_40a8f8bc(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x14));
  }
  FUN_40a8f084(param_1 + 0x1c);
  FUN_40a92710();
  return;
}



/* 40a8f900 FUN_40a8f900 */

/* Boundary evidence: original MIPS .pdata 40a8f900..40a8f9a7. Semantic name remains unreviewed. */

void FUN_40a8f900(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40aa467c,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40aa47bc,0x10);
    if (iVar1 != 0) {
      FUN_40a92804(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40a92768(piVar2,param_3);
  return;
}



/* 40a8f9a8 FUN_40a8f9a8 */

/* Boundary evidence: original MIPS .pdata 40a8f9a8..40a8f9d3. Semantic name remains unreviewed. */

void FUN_40a8f9a8(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 4))();
  return;
}



/* 40a8f9d4 FUN_40a8f9d4 */

/* Boundary evidence: original MIPS .pdata 40a8f9d4..40a8f9ff. Semantic name remains unreviewed. */

void FUN_40a8f9d4(int param_1)

{
  (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + 0xc) + 8))();
  return;
}



/* 40a8fa00 FUN_40a8fa00 */

/* Boundary evidence: original MIPS .pdata 40a8fa00..40a8fa1f. Semantic name remains unreviewed. */

undefined4 FUN_40a8fa00(int param_1,void *param_2)

{
  FUN_40a8f12c((void *)(param_1 + 0x1c),param_2);
  return 0;
}



/* 40a8fa20 FUN_40a8fa20 */

/* Boundary evidence: original MIPS .pdata 40a8fa20..40a8fa77. Semantic name remains unreviewed. */

undefined4 FUN_40a8fa20(int param_1,int *param_2)

{
  undefined4 uVar1;
  int local_10 [2];
  
  (**(code **)(*param_2 + 0x24))(param_2,local_10);
  if (local_10[0] == *(int *)(param_1 + 100)) {
    uVar1 = 0x80040208;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a8fa78 FUN_40a8fa78 */

/* Boundary evidence: original MIPS .pdata 40a8fa78..40a8facb. Semantic name remains unreviewed. */

undefined4 FUN_40a8fa78(int param_1,int *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    piVar2 = *(int **)(param_1 + 0xc);
    *param_2 = (int)piVar2;
    if (piVar2 == (int *)0x0) {
      uVar1 = 0x80040209;
    }
    else {
      (**(code **)(*piVar2 + 4))();
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40a8facc FUN_40a8facc */

/* Boundary evidence: original MIPS .pdata 40a8facc..40a8fb77. Semantic name remains unreviewed. */

undefined4 FUN_40a8facc(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int *)(param_1 + 100) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 100) + 0xc;
    }
    *param_2 = iVar2;
    if (*(int *)(param_1 + 100) != 0) {
      (**(code **)(*(int *)(*(int *)(param_1 + 100) + 0xc) + 4))();
    }
    if (*(short **)(param_1 + 8) == (short *)0x0) {
      *(undefined2 *)(param_2 + 2) = 0;
    }
    else {
      FUN_40a93a30((short *)(param_2 + 2),*(short **)(param_1 + 8),0x80);
    }
    uVar1 = 0;
    param_2[1] = *(int *)(param_1 + 0x58);
  }
  return uVar1;
}



/* 40a8fba0 FUN_40a8fba0 */

/* Boundary evidence: original MIPS .pdata 40a8fba0..40a8fbe7. Semantic name remains unreviewed. */

int FUN_40a8fba0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + -0xc) + 0x20))();
    if (iVar1 < 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}



/* 40a8fbf0 FUN_40a8fbf0 */

/* Boundary evidence: original MIPS .pdata 40a8fbf0..40a8fc3f. Semantic name remains unreviewed. */

undefined4 FUN_40a8fbf0(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x58);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 100) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a8fc70 FUN_40a8fc70 */

/* Boundary evidence: original MIPS .pdata 40a8fc70..40a8fc97. Semantic name remains unreviewed. */

void FUN_40a8fc70(int *param_1)

{
  (**(code **)(*param_1 + 0x38))(param_1,param_1[0x27],param_1 + 0x26);
  return;
}



/* 40a8fc98 FUN_40a8fc98 */

/* Boundary evidence: original MIPS .pdata 40a8fc98..40a8fcff. Semantic name remains unreviewed. */

int FUN_40a8fc98(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40a8fa20(param_1,param_2);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)*param_2)(param_2,&DAT_40aa474c,param_1 + 0x9c), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40a8fd00 FUN_40a8fd00 */

/* Boundary evidence: original MIPS .pdata 40a8fd00..40a8fd63. Semantic name remains unreviewed. */

undefined4 FUN_40a8fd00(int param_1)

{
  if (*(int **)(param_1 + 0x98) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x98) + 8))();
    *(undefined4 *)(param_1 + 0x98) = 0;
  }
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  return 0;
}



/* 40a8fd64 FUN_40a8fd64 */

/* Boundary evidence: original MIPS .pdata 40a8fd64..40a8fd9f. Semantic name remains unreviewed. */

void FUN_40a8fd64(undefined4 param_1,LPVOID *param_2)

{
  CoCreateInstance((IID *)&DAT_40aa3cfc,(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa472c,param_2);
  return;
}



/* 40a8fda0 FUN_40a8fda0 */

/* Boundary evidence: original MIPS .pdata 40a8fda0..40a8ff2b. Semantic name remains unreviewed. */

int FUN_40a8fda0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined1 auStack_28 [8];
  int local_20;
  
  *param_3 = 0;
  memset(auStack_28,0,0x10);
  (**(code **)(*param_2 + 0x14))(param_2,auStack_28);
  if (local_20 == 0) {
    local_20 = 1;
  }
  iVar1 = (**(code **)(*param_2 + 0xc))(param_2,param_3);
  if (((iVar1 < 0) ||
      (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
     (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
    if ((int *)*param_3 != (int *)0x0) {
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x48))(param_1,param_3);
    if (((iVar1 < 0) ||
        (iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,*param_3,auStack_28), iVar1 < 0)) ||
       (iVar1 = (**(code **)(*param_2 + 0x10))(param_2,*param_3,0), iVar1 < 0)) {
      if ((int *)*param_3 == (int *)0x0) {
        return iVar1;
      }
      (**(code **)(*(int *)*param_3 + 8))();
      *param_3 = 0;
      return iVar1;
    }
  }
  return 0;
}



/* 40a8ff2c FUN_40a8ff2c */

/* Boundary evidence: original MIPS .pdata 40a8ff2c..40a8ff73. Semantic name remains unreviewed. */

undefined4 FUN_40a8ff2c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x80004002;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x1c))();
  }
  return uVar1;
}



/* 40a8ff74 FUN_40a8ff74 */

/* Boundary evidence: original MIPS .pdata 40a8ff74..40a8ffb3. Semantic name remains unreviewed. */

undefined4 FUN_40a8ff74(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x9c) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x9c) + 0x18))();
  }
  return uVar1;
}



/* 40a8ffb4 FUN_40a8ffb4 */

/* Boundary evidence: original MIPS .pdata 40a8ffb4..40a8fff3. Semantic name remains unreviewed. */

undefined4 FUN_40a8ffb4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x38))();
  }
  return uVar1;
}



/* 40a8fff4 FUN_40a8fff4 */

/* Boundary evidence: original MIPS .pdata 40a8fff4..40a90033. Semantic name remains unreviewed. */

undefined4 FUN_40a8fff4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x98) == 0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x14))();
  }
  return uVar1;
}



/* 40a90034 FUN_40a90034 */

/* Boundary evidence: original MIPS .pdata 40a90034..40a90073. Semantic name remains unreviewed. */

undefined4 FUN_40a90034(int param_1)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (*(int **)(param_1 + 0x98) == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x98) + 0x18))();
  }
  return uVar1;
}



/* 40a90080 FUN_40a90080 */

/* Boundary evidence: original MIPS .pdata 40a90080..40a900cb. Semantic name remains unreviewed. */

bool FUN_40a90080(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
  return iVar1 != *(int *)(param_1 + 0x10);
}



/* 40a900cc FUN_40a900cc */

/* Boundary evidence: original MIPS .pdata 40a900cc..40a90117. Semantic name remains unreviewed. */

bool FUN_40a900cc(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))();
  return iVar1 != *(int *)(param_1 + 0xc);
}



/* 40a90118 FUN_40a90118 */

/* Boundary evidence: original MIPS .pdata 40a90118..40a90157. Semantic name remains unreviewed. */

undefined4 FUN_40a90118(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x3c))();
  }
  return uVar1;
}



/* 40a90158 FUN_40a90158 */

/* Boundary evidence: original MIPS .pdata 40a90158..40a90197. Semantic name remains unreviewed. */

undefined4 FUN_40a90158(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x40))();
  }
  return uVar1;
}



/* 40a90198 FUN_40a90198 */

/* Boundary evidence: original MIPS .pdata 40a90198..40a901f3. Semantic name remains unreviewed. */

undefined4 FUN_40a90198(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0x80040209;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x44))();
  }
  return uVar1;
}



/* 40a901f4 FUN_40a901f4 */

/* Boundary evidence: original MIPS .pdata 40a901f4..40a9023b. Semantic name remains unreviewed. */

void FUN_40a901f4(int param_1)

{
  if (*(int **)(param_1 + 0x9c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 8))();
    *(undefined4 *)(param_1 + 0x9c) = 0;
  }
  FUN_40a8f8bc(param_1);
  return;
}



/* 40a9023c FUN_40a9023c */

/* Boundary evidence: original MIPS .pdata 40a9023c..40a902bb. Semantic name remains unreviewed. */

void FUN_40a9023c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40aa474c,0x10);
  if (iVar1 == 0) {
    piVar2 = param_1 + 0x26;
    if (param_1 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    FUN_40a92768(piVar2,param_3);
  }
  else {
    FUN_40a8f900(param_1,param_2,param_3);
  }
  return;
}



/* 40a902bc FUN_40a902bc */

/* Boundary evidence: original MIPS .pdata 40a902bc..40a90383. Semantic name remains unreviewed. */

HRESULT FUN_40a902bc(int param_1,undefined4 *param_2)

{
  HRESULT HVar1;
  LPVOID *ppv;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 != (undefined4 *)0x0) {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    ppv = (LPVOID *)(param_1 + 4);
    if ((*ppv != (LPVOID)0x0) ||
       (HVar1 = CoCreateInstance((IID *)&DAT_40aa3cfc,(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa472c,ppv),
       -1 < HVar1)) {
      *param_2 = *ppv;
      (**(code **)(*(int *)*ppv + 4))();
      HVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
    return HVar1;
  }
  return -0x7fffbffd;
}



/* 40a90384 FUN_40a90384 */

/* Boundary evidence: original MIPS .pdata 40a90384..40a90423. Semantic name remains unreviewed. */

undefined4 FUN_40a90384(int param_1,int *param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + -0x30);
    EnterCriticalSection(lpCriticalSection);
    piVar2 = *(int **)(param_1 + 4);
    (**(code **)(*param_2 + 4))(param_2);
    *(int **)(param_1 + 4) = param_2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    *(undefined1 *)(param_1 + 8) = param_3;
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a90424 FUN_40a90424 */

/* Boundary evidence: original MIPS .pdata 40a90424..40a906ab. Semantic name remains unreviewed. */

int FUN_40a90424(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *local_20 [2];
  
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    piVar3 = (int *)(param_1 + -0x98);
    iVar2 = (**(code **)(*piVar3 + 0x38))(piVar3);
    if (iVar2 == 0) {
      iVar2 = (**(code **)*param_2)(param_2,&UNK_40aa471c,local_20);
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x10) = 0x30;
        *(undefined4 *)(param_1 + 0x14) = 0;
        *(undefined4 *)(param_1 + 0x30) = 0;
        *(undefined4 *)(param_1 + 0x18) = 0;
        iVar2 = (**(code **)(*param_2 + 0x3c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 4;
        }
        iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 2;
        }
        iVar2 = (**(code **)(*param_2 + 0x1c))(param_2);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
        }
        iVar2 = (**(code **)(*param_2 + 0x14))
                          (param_2,(undefined4 *)(param_1 + 0x20),(undefined4 *)(param_1 + 0x28));
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x20) = 0;
          *(undefined4 *)(param_1 + 0x24) = 0;
          *(undefined4 *)(param_1 + 0x28) = 0;
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        else {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0x110;
        }
        iVar2 = (**(code **)(*param_2 + 0x34))(param_2,param_1 + 0x34);
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
        }
        (**(code **)(*param_2 + 0xc))(param_2,param_1 + 0x38);
        uVar1 = (**(code **)(*param_2 + 0x2c))(param_2);
        *(undefined4 *)(param_1 + 0x1c) = uVar1;
        uVar1 = (**(code **)(*param_2 + 0x10))(param_2);
        *(undefined4 *)(param_1 + 0x3c) = uVar1;
      }
      else {
        iVar2 = (**(code **)(*local_20[0] + 0x4c))(local_20[0],0x30,param_1 + 0x10);
        (**(code **)(*local_20[0] + 8))();
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      if (((*(uint *)(param_1 + 0x18) & 8) == 0) ||
         (iVar2 = (**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(param_1 + 0x34)), iVar2 == 0)
         ) {
        iVar2 = 0;
      }
      else {
        *(undefined4 *)(param_1 + -0x2c) = 1;
        (**(code **)(*(int *)(param_1 + -0x8c) + 0x38))();
        piVar3 = *(int **)(*(int *)(param_1 + -0x28) + 0x44);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0xc))(piVar3,3,0x8004022a,0);
        }
        iVar2 = -0x7ffbfe00;
      }
    }
  }
  return iVar2;
}



/* 40a906ac FUN_40a906ac */

/* Boundary evidence: original MIPS .pdata 40a906ac..40a90747. Semantic name remains unreviewed. */

int FUN_40a906ac(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    *param_4 = 0;
    while (iVar1 = 0, 0 < param_3) {
      param_3 = param_3 + -1;
      iVar1 = (**(code **)(*param_1 + 0x18))(param_1,*(undefined4 *)(*param_4 * 4 + param_2));
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = *param_4 + 1;
    }
  }
  return iVar1;
}



/* 40a90748 FUN_40a90748 */

/* Boundary evidence: original MIPS .pdata 40a90748..40a908a7. Semantic name remains unreviewed. */

int FUN_40a90748(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *local_30;
  int *local_2c;
  int local_28 [2];
  
  iVar1 = (**(code **)(**(int **)(param_1 + -0x28) + 0x18))();
  iVar5 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(**(int **)(param_1 + -0x28) + 0x1c))(*(int **)(param_1 + -0x28),iVar4);
      piVar3 = (int *)(iVar2 + 0xc);
      iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,local_28);
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((local_28[0] == 1) &&
         (iVar2 = (**(code **)(*piVar3 + 0x18))(piVar3,&local_30), -1 < iVar2)) {
        iVar5 = iVar5 + 1;
        iVar2 = (**(code **)*local_30)(local_30,&DAT_40aa474c,&local_2c);
        (**(code **)(*local_30 + 8))();
        if (iVar2 < 0) {
          return 0;
        }
        iVar2 = (**(code **)(*local_2c + 0x20))();
        (**(code **)(*local_2c + 8))();
        if (iVar2 != 1) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
    if (iVar5 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 40a908a8 FUN_40a908a8 */

/* Boundary evidence: original MIPS .pdata 40a908a8..40a908ef. Semantic name remains unreviewed. */

undefined4 FUN_40a908a8(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a908f0 FUN_40a908f0 */

/* Boundary evidence: original MIPS .pdata 40a908f0..40a90933. Semantic name remains unreviewed. */

undefined4 FUN_40a908f0(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x95) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a90954 FUN_40a90954 */

/* Boundary evidence: original MIPS .pdata 40a90954..40a90993. Semantic name remains unreviewed. */

undefined4 FUN_40a90954(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x9c);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x8004020a;
  }
  else {
    *(undefined1 *)(param_1 + 0xa1) = 0;
    uVar1 = (**(code **)(*piVar2 + 0x18))(piVar2);
  }
  return uVar1;
}



/* 40a909e8 FUN_40a909e8 */

/* Boundary evidence: original MIPS .pdata 40a909e8..40a90c3f. Semantic name remains unreviewed. */

int FUN_40a909e8(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar1 = 1;
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    iVar1 = (**(code **)(*param_2 + 0x1c))(param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    if (param_3 != 0) {
      puVar2 = (undefined4 *)*param_1;
      iVar1 = (**(code **)(*param_2 + 0xc))
                        (param_2,*puVar2,puVar2[1],puVar2[2],puVar2[3],param_1[1],param_1[2]);
      if ((-1 < iVar1) && (uVar7 = 0, param_1[3] != 0)) {
        iVar6 = 0;
        while( true ) {
          puVar5 = (undefined4 *)*param_1;
          iVar1 = param_1[4] + iVar6;
          puVar2 = *(undefined4 **)(iVar1 + 0x14);
          puVar4 = (undefined4 *)(param_1[4] + iVar6);
          iVar1 = (**(code **)(*param_2 + 0x14))
                            (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],*puVar4,puVar4[1],
                             puVar4[2],puVar4[3],puVar4[4],*puVar2,puVar2[1],puVar2[2],puVar2[3],
                             *(undefined4 *)(iVar1 + 0x18));
          if (iVar1 < 0) break;
          iVar3 = param_1[4];
          uVar8 = 0;
          if (*(int *)(iVar6 + iVar3 + 0x1c) != 0) {
            iVar9 = 0;
            do {
              puVar5 = (undefined4 *)*param_1;
              puVar2 = (undefined4 *)(((undefined4 *)(iVar6 + iVar3))[8] + iVar9);
              puVar4 = (undefined4 *)puVar2[1];
              puVar2 = (undefined4 *)*puVar2;
              iVar1 = (**(code **)(*param_2 + 0x18))
                                (param_2,*puVar5,puVar5[1],puVar5[2],puVar5[3],
                                 *(undefined4 *)(iVar6 + iVar3),*puVar2,puVar2[1],puVar2[2],
                                 puVar2[3],*puVar4,puVar4[1],puVar4[2],puVar4[3]);
              if (iVar1 < 0) goto LAB_40a90c08;
              iVar3 = param_1[4];
              uVar8 = uVar8 + 1;
              iVar9 = iVar9 + 8;
            } while (uVar8 < *(uint *)(iVar6 + iVar3 + 0x1c));
          }
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + 0x24;
          if ((uint)param_1[3] <= uVar7) break;
        }
      }
    }
LAB_40a90c08:
    if (iVar1 == -0x7ff8fffe) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40a90c40 FUN_40a90c40 */

/* Boundary evidence: original MIPS .pdata 40a90c40..40a90d1f. Semantic name remains unreviewed. */

void FUN_40a90c40(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = memcmp(param_2,&DAT_40aa46dc,0x10);
  if (((iVar1 == 0) || (iVar1 = memcmp(param_2,&DAT_40aa46cc,0x10), iVar1 == 0)) ||
     (iVar1 = memcmp(param_2,&DAT_40aa4f28,0x10), iVar1 == 0)) {
    piVar2 = param_1 + 3;
  }
  else {
    iVar1 = memcmp(param_2,&DAT_40aa475c,0x10);
    if (iVar1 != 0) {
      FUN_40a92804(param_1,param_2,param_3);
      return;
    }
    piVar2 = param_1 + 4;
  }
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  FUN_40a92768(piVar2,param_3);
  return;
}



/* 40a90d20 FUN_40a90d20 */

/* Boundary evidence: original MIPS .pdata 40a90d20..40a90d7b. Semantic name remains unreviewed. */

void FUN_40a90d20(int param_1)

{
  if (*(void **)(param_1 + 0x3c) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x3c));
  }
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  FUN_40a92710();
  return;
}



/* 40a90d7c FUN_40a90d7c */

/* Boundary evidence: original MIPS .pdata 40a90d7c..40a90dff. Semantic name remains unreviewed. */

undefined4 FUN_40a90d7c(int param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  if (*(int **)(param_1 + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  }
  *(int **)(param_1 + 0xc) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a90e00 FUN_40a90e00 */

/* Boundary evidence: original MIPS .pdata 40a90e00..40a90e83. Semantic name remains unreviewed. */

undefined4 FUN_40a90e00(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 4))();
    }
    *param_2 = *(undefined4 *)(param_1 + 0xc);
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a90e84 FUN_40a90e84 */

/* Boundary evidence: original MIPS .pdata 40a90e84..40a90f0b. Semantic name remains unreviewed. */

int FUN_40a90e84(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = -0x7ffbfded;
  }
  else {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0xc))(*(int **)(param_1 + 0x18),param_2);
    if (-1 < iVar1) {
      uVar2 = *(uint *)(param_1 + 0x20);
      uVar3 = *param_2;
      iVar4 = *(int *)(param_1 + 0x24);
      iVar1 = 0;
      *param_2 = uVar3 - uVar2;
      param_2[1] = (param_2[1] - iVar4) - (uint)(uVar3 < uVar2);
    }
  }
  return iVar1;
}



/* 40a90f0c FUN_40a90f0c */

/* Boundary evidence: original MIPS .pdata 40a90f0c..40a91023. Semantic name remains unreviewed. */

undefined4 FUN_40a90f0c(int param_1,LPCWSTR param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
    EnterCriticalSection(lpCriticalSection);
    piVar6 = (int *)(param_1 + -0xc);
    iVar1 = (**(code **)(*piVar6 + 0x18))(piVar6);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        iVar2 = (**(code **)(*piVar6 + 0x1c))(piVar6,iVar5);
        iVar3 = lstrcmpW(*(LPCWSTR *)(iVar2 + 0x14),param_2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar4 = 0;
          goto LAB_40a90fcc;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    *param_3 = 0;
    uVar4 = 0x80040216;
LAB_40a90fcc:
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar4;
}



/* 40a91024 FUN_40a91024 */

/* Boundary evidence: original MIPS .pdata 40a91024..40a9113f. Semantic name remains unreviewed. */

undefined4 FUN_40a91024(int param_1,undefined4 *param_2,wchar_t *param_3)

{
  int iVar1;
  size_t sVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 **)(param_1 + 0x34) = param_2;
  if (param_2 == (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  else {
    iVar1 = (**(code **)*param_2)(param_2,&DAT_40aa47ec,(undefined4 *)(param_1 + 0x38));
    if (-1 < iVar1) {
      (**(code **)(**(int **)(param_1 + 0x38) + 8))();
    }
  }
  if (*(void **)(param_1 + 0x30) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (param_3 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_3);
    uVar4 = sVar2 + 1;
    if (uVar4 < 0x80000000) {
      uVar3 = uVar4 * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Dst = operator_new(uVar3);
    *(void **)(param_1 + 0x30) = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_3,uVar4 * 2);
    }
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}



/* 40a91140 FUN_40a91140 */

/* Boundary evidence: original MIPS .pdata 40a91140..40a91213. Semantic name remains unreviewed. */

undefined4 FUN_40a91140(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  HRESULT HVar3;
  int *local_10 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar3 = CoCreateInstance((IID *)&DAT_40aa37bc,(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa47ac,local_10);
    if (-1 < HVar3) {
      FUN_40a909e8(puVar1,local_10[0],1);
      (**(code **)(*local_10[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40a91214 FUN_40a91214 */

/* Boundary evidence: original MIPS .pdata 40a91214..40a91307. Semantic name remains unreviewed. */

int FUN_40a91214(int param_1)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int *local_18 [2];
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(param_1 + -0x10) + 0x20))();
  if (puVar1 == (undefined4 *)0x0) {
    HVar2 = 1;
  }
  else {
    CoInitializeEx((LPVOID)0x0,0);
    HVar2 = CoCreateInstance((IID *)&DAT_40aa37bc,(LPUNKNOWN)0x0,1,(IID *)&DAT_40aa47ac,local_18);
    if (-1 < HVar2) {
      HVar2 = FUN_40a909e8(puVar1,local_18[0],0);
      (**(code **)(*local_18[0] + 8))();
    }
    CoFreeUnusedLibraries();
    CoUninitialize();
    if (HVar2 == -0x7ff8fffe) {
      HVar2 = 0;
    }
  }
  return HVar2;
}



/* 40a91308 FUN_40a91308 */

/* Boundary evidence: original MIPS .pdata 40a91308..40a91353. Semantic name remains unreviewed. */

undefined4 * FUN_40a91308(undefined4 *param_1,uint param_2)

{
  FUN_40a8f558(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a91354 FUN_40a91354 */

/* Boundary evidence: original MIPS .pdata 40a91354..40a914eb. Semantic name remains unreviewed. */

undefined4 FUN_40a91354(int param_1,uint param_2,int *param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_3 == (int *)0x0) {
    uVar4 = 0x80004003;
  }
  else {
    if (param_4 == (uint *)0x0) {
      if (1 < param_2) {
        return 0x80070057;
      }
    }
    else {
      *param_4 = 0;
    }
    uVar6 = 0;
    bVar1 = FUN_40a90080(param_1);
    uVar4 = 1;
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40a8f714(param_1);
    }
    uVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);
    if ((int)param_2 <= (int)uVar5) {
      uVar5 = param_2;
    }
    if (uVar5 != 0) {
      do {
        if (*(int *)(param_1 + 8) == *(int *)(param_1 + 4)) break;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x1c))();
        if (iVar2 == 0) {
          return 0x80040203;
        }
        iVar3 = FUN_40a93b90((int *)(param_1 + 0x18),iVar2);
        if (iVar3 == 0) {
          *param_3 = iVar2 + 0xc;
          (**(code **)(*(int *)(iVar2 + 0xc) + 4))();
          uVar6 = uVar6 + 1;
          param_3 = param_3 + 1;
          FUN_40a93c90((int *)(param_1 + 0x18),iVar2);
          uVar5 = uVar5 - 1;
        }
      } while (uVar5 != 0);
      if (param_4 != (uint *)0x0) {
        *param_4 = uVar6;
      }
      if (param_2 == uVar6) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}



/* 40a914ec FUN_40a914ec */

/* Boundary evidence: original MIPS .pdata 40a914ec..40a91567. Semantic name remains unreviewed. */

undefined4 FUN_40a914ec(int param_1,uint param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  
  bVar1 = FUN_40a90080(param_1);
  uVar2 = 1;
  if (CONCAT31(extraout_var,bVar1) == 1) {
    uVar2 = 0x80040203;
  }
  else if ((uint)(*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) < param_2) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    uVar2 = 0;
  }
  return uVar2;
}



/* 40a91568 FUN_40a91568 */

/* Boundary evidence: original MIPS .pdata 40a91568..40a915cb. Semantic name remains unreviewed. */

undefined4 * FUN_40a91568(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_40aa4c7c;
  (**(code **)(*(int *)(param_1[2] + 0xc) + 8))();
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 40a915cc FUN_40a915cc */

/* Boundary evidence: original MIPS .pdata 40a915cc..40a9175f. Semantic name remains unreviewed. */

uint FUN_40a915cc(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  LPVOID _Dst;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_70 [60];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  
  local_28 = DAT_40ab1828;
  if (param_3 == (undefined4 *)0x0) {
    FUN_40a93fe4(DAT_40ab1828);
    uVar3 = 0x80004003;
  }
  else {
    bVar1 = FUN_40a900cc(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      FUN_40a93fe4(local_28);
      uVar3 = 0x80040203;
    }
    else {
      if (param_4 == (int *)0x0) {
        if (1 < param_2) {
          FUN_40a93fe4(local_28);
          return 0x80070057;
        }
      }
      else {
        *param_4 = 0;
      }
      iVar4 = 0;
      for (; param_2 != 0; param_2 = param_2 - 1) {
        FUN_40a8f0a0(auStack_70);
        iVar2 = *(int *)(param_1 + 4);
        *(int *)(param_1 + 4) = iVar2 + 1;
        iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                          (*(int **)(param_1 + 8),iVar2,auStack_70);
        if (iVar2 != 0) {
LAB_40a9170c:
          FUN_40a8f084((int)auStack_70);
          break;
        }
        _Dst = CoTaskMemAlloc(0x48);
        *param_3 = _Dst;
        if (_Dst == (LPVOID)0x0) goto LAB_40a9170c;
        memcpy(_Dst,auStack_70,0x48);
        local_2c = 0;
        local_30 = 0;
        local_34 = 0;
        param_3 = param_3 + 1;
        iVar4 = iVar4 + 1;
        FUN_40a8f084((int)auStack_70);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      uVar3 = (uint)(param_2 != 0);
      FUN_40a93fe4(local_28);
    }
  }
  return uVar3;
}



/* 40a91760 FUN_40a91760 */

/* Boundary evidence: original MIPS .pdata 40a91760..40a91817. Semantic name remains unreviewed. */

uint FUN_40a91760(int param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_40ab1828;
  bVar1 = FUN_40a900cc(param_1);
  if (CONCAT31(extraout_var,bVar1) == 1) {
    FUN_40a93fe4(local_18);
    uVar3 = 0x80040203;
  }
  else {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + param_2;
    FUN_40a8f0a0(auStack_60);
    iVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x34))
                      (*(int **)(param_1 + 8),*(int *)(param_1 + 4) + -1,auStack_60);
    uVar3 = (uint)(iVar2 != 0);
    FUN_40a8f084((int)auStack_60);
    FUN_40a93fe4(local_18);
  }
  return uVar3;
}



/* 40a91818 FUN_40a91818 */

/* Boundary evidence: original MIPS .pdata 40a91818..40a9198f. Semantic name remains unreviewed. */

int FUN_40a91818(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0x2c))();
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_3);
    if (iVar1 == 0) {
      param_1[6] = (int)param_2;
      (**(code **)(*param_2 + 4))(param_2);
      (**(code **)(*param_1 + 0x24))(param_1,param_3);
      iVar1 = (**(code **)(*param_2 + 0x10))(param_2,param_1 + 3,param_3);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x30))(param_1,param_2);
        if (-1 < iVar1) {
          return iVar1;
        }
        (**(code **)(*param_2 + 0x14))(param_2);
      }
    }
    else if (((-1 < iVar1) || (iVar1 == -0x7fffbffb)) || (iVar1 == -0x7ff8ffa9)) {
      iVar1 = -0x7ffbfdd6;
    }
    (**(code **)(*param_1 + 0x2c))(param_1);
    if ((int *)param_1[6] != (int *)0x0) {
      (**(code **)(*(int *)param_1[6] + 8))();
      param_1[6] = 0;
    }
  }
  return iVar1;
}



/* 40a91990 FUN_40a91990 */

/* Boundary evidence: original MIPS .pdata 40a91990..40a91b03. Semantic name remains unreviewed. */

int FUN_40a91990(int *param_1,int *param_2,void *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*param_4 + 0x14))(param_4);
  if (-1 < iVar1) {
    iVar1 = 0;
    local_28 = (void *)0x0;
    local_24 = 0;
    iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
    if (iVar2 == 0) {
      do {
        if ((((param_3 == (void *)0x0) ||
             (iVar3 = FUN_40a8f1c4(local_28,param_3), iVar2 = -0x7ffbfdf9, iVar3 != 0)) &&
            (iVar2 = FUN_40a91818(param_1,param_2,local_28), iVar2 < 0)) &&
           (((-1 < iVar1 && (iVar2 != -0x7fffbffb)) &&
            ((iVar2 != -0x7ff8ffa9 && (iVar2 != -0x7ffbfdd6)))))) {
          iVar1 = iVar2;
        }
        FUN_40a8f2d8(local_28);
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = (**(code **)(*param_4 + 0xc))(param_4,1,&local_28,&local_24);
      } while (iVar2 == 0);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    iVar1 = -0x7ffbfdf9;
  }
  return iVar1;
}



/* 40a91b04 FUN_40a91b04 */

/* Boundary evidence: original MIPS .pdata 40a91b04..40a91c8b. Semantic name remains unreviewed. */

int FUN_40a91b04(int *param_1,int *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *local_30 [2];
  
  local_30[0] = (int *)0x0;
  if ((param_3 != (void *)0x0) && (iVar1 = FUN_40a8f158(param_3), iVar1 == 0)) {
    iVar1 = FUN_40a91818(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = -0x7ffbfdf9;
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,local_30);
  if (-1 < iVar2) {
    iVar2 = FUN_40a91990(param_1,param_2,param_3,local_30[0]);
    (**(code **)(*local_30[0] + 8))();
    if (-1 < iVar2) {
      return 0;
    }
    if (((iVar2 != -0x7fffbffb) && (iVar2 != -0x7ff8ffa9)) && (iVar2 != -0x7ffbfdd6)) {
      iVar1 = iVar2;
    }
  }
  iVar2 = (**(code **)(param_1[3] + 0x30))(param_1 + 3,local_30);
  if (iVar2 < 0) {
    return iVar1;
  }
  iVar2 = FUN_40a91990(param_1,param_2,param_3,local_30[0]);
  (**(code **)(*local_30[0] + 8))();
  if (-1 < iVar2) {
    return 0;
  }
  if (iVar2 == -0x7fffbffb) {
    return iVar1;
  }
  if (iVar2 == -0x7ff8ffa9) {
    return iVar1;
  }
  if (iVar2 != -0x7ffbfdd6) {
    return iVar2;
  }
  return iVar1;
}



/* 40a91c8c FUN_40a91c8c */

/* Boundary evidence: original MIPS .pdata 40a91c8c..40a91e53. Semantic name remains unreviewed. */

int FUN_40a91c8c(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if ((param_2 == (int *)0x0) || (param_3 == 0)) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0xc) == 0) {
    if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
      piVar3 = (int *)(param_1 + -0xc);
      iVar2 = (**(code **)(*piVar3 + 0x28))(piVar3,param_2);
      iVar1 = *piVar3;
      if (-1 < iVar2) {
        iVar2 = (**(code **)(iVar1 + 0x20))(piVar3,param_3);
        if (iVar2 != 0) {
          (**(code **)(*piVar3 + 0x2c))(piVar3);
          if (((-1 < iVar2) || (iVar2 == -0x7fffbffb)) || (iVar2 == -0x7ff8ffa9)) {
            iVar2 = -0x7ffbfdd6;
          }
          goto LAB_40a91e24;
        }
        *(int **)(param_1 + 0xc) = param_2;
        (**(code **)(*param_2 + 4))(param_2);
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,param_3);
        if ((-1 < iVar2) && (iVar2 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2), -1 < iVar2)) {
          iVar2 = 0;
          goto LAB_40a91e24;
        }
        (**(code **)(**(int **)(param_1 + 0xc) + 8))();
        iVar1 = *piVar3;
        *(undefined4 *)(param_1 + 0xc) = 0;
      }
      (**(code **)(iVar1 + 0x2c))(piVar3);
    }
    else {
      iVar2 = -0x7ffbfddc;
    }
  }
  else {
    iVar2 = -0x7ffbfdfc;
  }
LAB_40a91e24:
  LeaveCriticalSection(lpCriticalSection);
  return iVar2;
}



/* 40a91e54 FUN_40a91e54 */

/* Boundary evidence: original MIPS .pdata 40a91e54..40a91ef3. Semantic name remains unreviewed. */

undefined4 FUN_40a91e54(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
    if (*(int *)(param_1 + 0xc) == 0) {
      uVar1 = 1;
    }
    else {
      (**(code **)(*(int *)(param_1 + -0xc) + 0x2c))();
      (**(code **)(**(int **)(param_1 + 0xc) + 8))();
      *(undefined4 *)(param_1 + 0xc) = 0;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80040224;
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar1;
}



/* 40a91ef4 FUN_40a91ef4 */

/* Boundary evidence: original MIPS .pdata 40a91ef4..40a91f7f. Semantic name remains unreviewed. */

undefined4 FUN_40a91ef4(int param_1,void *param_2)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (void *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      FUN_40a8ef50(param_2);
      uVar1 = 0x80040209;
    }
    else {
      FUN_40a8ef8c(param_2,(void *)(param_1 + 0x10));
      uVar1 = 0;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return uVar1;
}



/* 40a91f80 FUN_40a91f80 */

/* Boundary evidence: original MIPS .pdata 40a91f80..40a91f9b. Semantic name remains unreviewed. */

void FUN_40a91f80(int param_1,undefined4 *param_2)

{
  FUN_40a93a6c(*(wchar_t **)(param_1 + 8),param_2);
  return;
}



/* 40a91f9c FUN_40a91f9c */

/* Boundary evidence: original MIPS .pdata 40a91f9c..40a92017. Semantic name remains unreviewed. */

int FUN_40a91f9c(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = FUN_40a91e54(param_1);
  if ((iVar1 == 0) && (*(int **)(param_1 + 0x90) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0x90) + 8))();
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}



/* 40a92018 FUN_40a92018 */

/* Boundary evidence: original MIPS .pdata 40a92018..40a920f7. Semantic name remains unreviewed. */

undefined4 * FUN_40a92018(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  param_1[3] = param_2;
  *param_1 = &PTR_FUN_40aa4c5c;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[5] = 1;
  FUN_40a93b18(param_1 + 6);
  (**(code **)(*(int *)(param_1[3] + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x14))();
    param_1[4] = uVar1;
    uVar1 = (**(code **)(*(int *)param_1[3] + 0x18))();
    param_1[2] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[2] = *(undefined4 *)(param_3 + 8);
    param_1[4] = *(undefined4 *)(param_3 + 0x10);
    FUN_40a93d2c(param_1 + 6,(int *)(param_3 + 0x18));
  }
  return param_1;
}



/* 40a920f8 FUN_40a920f8 */

/* Boundary evidence: original MIPS .pdata 40a920f8..40a921a3. Semantic name remains unreviewed. */

undefined4 FUN_40a920f8(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40a90080(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x30);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40a92018(puVar2,*(undefined4 *)(param_1 + 0xc),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40a921a4 FUN_40a921a4 */

/* Boundary evidence: original MIPS .pdata 40a921a4..40a92233. Semantic name remains unreviewed. */

undefined4 * FUN_40a921a4(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_FUN_40aa4c7c;
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[4] = 1;
  (**(code **)(*(int *)(param_2 + 0xc) + 4))();
  if (param_3 == 0) {
    uVar1 = (**(code **)(*(int *)param_1[2] + 0x10))();
    param_1[3] = uVar1;
  }
  else {
    param_1[1] = *(undefined4 *)(param_3 + 4);
    param_1[3] = *(undefined4 *)(param_3 + 0xc);
  }
  return param_1;
}



/* 40a92234 FUN_40a92234 */

/* Boundary evidence: original MIPS .pdata 40a92234..40a922df. Semantic name remains unreviewed. */

undefined4 FUN_40a92234(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    uVar3 = 0;
    bVar1 = FUN_40a900cc(param_1);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      uVar3 = 0x80040203;
      *param_2 = 0;
    }
    else {
      puVar2 = operator_new(0x14);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_40a921a4(puVar2,*(int *)(param_1 + 8),param_1);
      }
      *param_2 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        uVar3 = 0x8007000e;
      }
    }
  }
  return uVar3;
}



/* 40a922e0 FUN_40a922e0 */

/* Boundary evidence: original MIPS .pdata 40a922e0..40a923d3. Semantic name remains unreviewed. */

undefined4 *
FUN_40a922e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6,undefined4 param_7)

{
  size_t sVar1;
  void *_Dst;
  uint uVar2;
  uint uVar3;
  
  FUN_40a927a8(param_1,param_2,(undefined4 *)0x0);
  param_1[5] = 0;
  param_1[6] = 0;
  FUN_40a8f0a0(param_1 + 7);
  param_1[0x1c] = param_3;
  param_1[0x1e] = 1;
  param_1[0x19] = param_7;
  param_1[0x1a] = param_4;
  param_1[0x1b] = 0;
  param_1[0x1d] = 0;
  uVar3 = 0xffffffff;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0xffffffff;
  param_1[0x23] = 0x7fffffff;
  param_1[0x24] = 0;
  param_1[0x25] = 0x3ff00000;
  if (param_6 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_6);
    uVar2 = sVar1 + 1;
    if (uVar2 < 0x80000000) {
      uVar3 = uVar2 * 2;
    }
    _Dst = operator_new(uVar3);
    param_1[5] = _Dst;
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,param_6,uVar2 * 2);
    }
  }
  return param_1;
}



/* 40a923d4 FUN_40a923d4 */

/* Boundary evidence: original MIPS .pdata 40a923d4..40a924b3. Semantic name remains unreviewed. */

int FUN_40a923d4(int param_1,int *param_2,void *param_3)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar2;
  
  if (param_2 == (int *)0x0) {
    iVar1 = -0x7fffbffd;
  }
  else {
    lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x5c);
    EnterCriticalSection(lpCriticalSection);
    if (*(int *)(param_1 + 0xc) == 0) {
      if (*(int *)(*(int *)(param_1 + 100) + 0x14) == 0) {
        piVar2 = (int *)(param_1 + -0xc);
        iVar1 = FUN_40a91b04(piVar2,param_2,param_3);
        if (iVar1 < 0) {
          (**(code **)(*piVar2 + 0x2c))(piVar2);
        }
        else {
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -0x7ffbfddc;
      }
    }
    else {
      iVar1 = -0x7ffbfdfc;
    }
    LeaveCriticalSection(lpCriticalSection);
  }
  return iVar1;
}



/* 40a924b4 FUN_40a924b4 */

/* Boundary evidence: original MIPS .pdata 40a924b4..40a92533. Semantic name remains unreviewed. */

undefined4 FUN_40a924b4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40a921a4(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40a92534 FUN_40a92534 */

/* Boundary evidence: original MIPS .pdata 40a92534..40a9257f. Semantic name remains unreviewed. */

undefined4 *
FUN_40a92534(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40a922e0(param_1,param_2,param_3,param_4,param_5,param_6,1);
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  return param_1;
}



/* 40a92580 FUN_40a92580 */

/* Boundary evidence: original MIPS .pdata 40a92580..40a925db. Semantic name remains unreviewed. */

undefined4 *
FUN_40a92580(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,wchar_t *param_6)

{
  FUN_40a922e0(param_1,param_2,param_3,param_4,param_5,param_6,0);
  param_1[0x27] = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  *(undefined1 *)((int)param_1 + 0xa1) = 0;
  memset(param_1 + 0x2a,0,0x30);
  return param_1;
}



/* 40a925dc FUN_40a925dc */

/* Boundary evidence: original MIPS .pdata 40a925dc..40a9265f. Semantic name remains unreviewed. */

undefined4 *
FUN_40a925dc(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_40a927a8(param_1,param_2,param_3);
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = *param_5;
  param_1[0xb] = param_5[1];
  param_1[0xc] = param_5[2];
  uVar1 = param_5[3];
  param_1[0xe] = param_4;
  param_1[0xd] = uVar1;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 1;
  return param_1;
}



/* 40a92660 FUN_40a92660 */

/* Boundary evidence: original MIPS .pdata 40a92660..40a926df. Semantic name remains unreviewed. */

undefined4 FUN_40a92660(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar2 = operator_new(0x30);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_40a92018(puVar2,param_1 + -0xc,0);
    }
    *param_2 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40a926e0 FUN_40a926e0 */

/* Boundary evidence: original MIPS .pdata 40a926e0..40a9270f. Semantic name remains unreviewed. */

undefined4 FUN_40a926e0(undefined4 param_1)

{
  InterlockedIncrement(&DAT_40ab2758);
  return param_1;
}



/* 40a92710 FUN_40a92710 */

/* Boundary evidence: original MIPS .pdata 40a92710..40a92767. Semantic name remains unreviewed. */

void FUN_40a92710(void)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(&DAT_40ab2758);
  if ((LVar1 == 0) && (DAT_40ab2754 != 0)) {
    FreeLibrary((HMODULE)DAT_40ab2754);
    DAT_40ab2754 = 0;
  }
  return;
}



/* 40a92768 FUN_40a92768 */

/* Boundary evidence: original MIPS .pdata 40a92768..40a927a7. Semantic name remains unreviewed. */

undefined4 FUN_40a92768(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = param_1;
    (**(code **)(*param_1 + 4))();
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a927a8 FUN_40a927a8 */

/* Boundary evidence: original MIPS .pdata 40a927a8..40a92803. Semantic name remains unreviewed. */

undefined4 * FUN_40a927a8(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_1 = &PTR_LAB_40aa4cb8;
  InterlockedIncrement(&DAT_40ab2758);
  if (param_3 == (undefined4 *)0x0) {
    param_3 = param_1;
  }
  param_1[1] = param_3;
  param_1[2] = 0;
  return param_1;
}



/* 40a92804 FUN_40a92804 */

/* Boundary evidence: original MIPS .pdata 40a92804..40a92887. Semantic name remains unreviewed. */

undefined4 FUN_40a92804(int *param_1,void *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    iVar2 = memcmp(param_2,&DAT_40aa4f18,0x10);
    if (iVar2 == 0) {
      *param_3 = param_1;
      (**(code **)(*param_1 + 4))(param_1);
      uVar1 = 0;
    }
    else {
      *param_3 = 0;
      uVar1 = 0x80004002;
    }
  }
  return uVar1;
}



/* 40a92888 FUN_40a92888 */

/* Boundary evidence: original MIPS .pdata 40a92888..40a928c3. Semantic name remains unreviewed. */

uint FUN_40a92888(int param_1)

{
  uint uVar1;
  
  InterlockedIncrement((LONG *)(param_1 + 8));
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 < 2) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 40a928c4 FUN_40a928c4 */

/* Boundary evidence: original MIPS .pdata 40a928c4..40a9293b. Semantic name remains unreviewed. */

uint FUN_40a928c4(int *param_1)

{
  LONG LVar1;
  uint uVar2;
  uint *lpAddend;
  
  lpAddend = (uint *)(param_1 + 2);
  LVar1 = InterlockedDecrement((LONG *)lpAddend);
  if (LVar1 == 0) {
    *lpAddend = *lpAddend + 1;
    (**(code **)(*param_1 + 0xc))(param_1,1);
    uVar2 = 0;
  }
  else {
    uVar2 = *lpAddend;
    if (uVar2 < 2) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 40a9293c FUN_40a9293c */

/* Boundary evidence: original MIPS .pdata 40a9293c..40a9297f. Semantic name remains unreviewed. */

void FUN_40a9293c(int param_1)

{
  if (*(int *)(param_1 + 0x3c) != 0) {
    ReleaseSemaphore(*(HANDLE *)(param_1 + 0x28),*(int *)(param_1 + 0x3c),(LPLONG)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  return;
}



/* 40a92980 FUN_40a92980 */

/* Boundary evidence: original MIPS .pdata 40a92980..40a92a43. Semantic name remains unreviewed. */

void FUN_40a92980(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
  }
  else {
    EnterCriticalSection(param_1);
    iVar1 = param_1[3].RecursionCount;
    param_1[2].LockSemaphore = (HANDLE)0x1;
    if (iVar1 == 0) {
      param_1[3].RecursionCount = 1;
    }
    if (param_1[2].SpinCount == 0) {
      EventModify(param_1[1].SpinCount,2);
      FUN_40a9293c((int)param_1);
      LeaveCriticalSection(param_1);
      (**(code **)(*(int *)param_1->SpinCount + 0x3c))();
      return;
    }
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40a92a44 FUN_40a92a44 */

/* Boundary evidence: original MIPS .pdata 40a92a44..40a92a9b. Semantic name remains unreviewed. */

void FUN_40a92a44(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_40a93c90(*(undefined4 **)(param_1 + 0x24),param_2);
  if ((puVar1 == (undefined4 *)0x0) && (param_2 < (int *)0xfffffff1)) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



/* 40a92a9c FUN_40a92a9c */

/* Boundary evidence: original MIPS .pdata 40a92a9c..40a92d3b. Semantic name remains unreviewed. */

LONG FUN_40a92a9c(LPCRITICAL_SECTION param_1,undefined4 *param_2,int param_3,int *param_4)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_30 [2];
  
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar3 = 0;
      iVar2 = 0;
      do {
        if (iVar2 < param_3) {
          *(undefined4 *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = *param_2;
          param_2 = param_2 + 1;
          iVar2 = iVar2 + 1;
          param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
        }
        else if ((param_1[2].RecursionCount == 0) || (param_1[3].LockCount == 0)) goto LAB_40a92b5c;
        if ((param_1[2].RecursionCount == param_1[1].RecursionCount) ||
           ((param_3 == 0 && ((param_1[3].LockCount != 0 || (param_1[1].LockCount == 0)))))) {
          if (param_1[3].RecursionCount == 0) {
            LVar1 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                              (param_1[1].DebugInfo,param_1[2].LockCount,param_1[2].RecursionCount,
                               local_30);
            param_1[3].RecursionCount = LVar1;
          }
          else {
            local_30[0] = 0;
          }
          iVar3 = (param_1[2].RecursionCount - local_30[0]) + iVar3;
          iVar5 = 0;
          if (0 < param_1[2].RecursionCount) {
            iVar4 = 0;
            do {
              (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 4;
            } while (iVar5 < param_1[2].RecursionCount);
          }
          param_1[2].RecursionCount = 0;
        }
      } while( true );
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      iVar2 = param_3;
      if (0 < param_3) {
        do {
          FUN_40a92a44((int)param_1,(int *)*param_2);
          param_2 = param_2 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      *param_4 = param_3;
      if ((param_1[1].LockCount == 0) ||
         (param_1[1].RecursionCount <=
          param_1[2].RecursionCount + *(int *)((int)param_1[1].OwningThread + 8))) {
        FUN_40a9293c((int)param_1);
      }
      LVar1 = 0;
      goto LAB_40a92d04;
    }
    *param_4 = 0;
    if (0 < param_3) {
      do {
        (**(code **)(*(int *)*param_2 + 8))();
        param_2 = param_2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  goto LAB_40a92b6c;
LAB_40a92b5c:
  *param_4 = iVar2 - iVar3;
  if (iVar2 - iVar3 < 0) {
    *param_4 = 0;
  }
LAB_40a92b6c:
  LVar1 = param_1[3].RecursionCount;
LAB_40a92d04:
  LeaveCriticalSection(param_1);
  return LVar1;
}



/* 40a92d3c FUN_40a92d3c */

/* Boundary evidence: original MIPS .pdata 40a92d3c..40a92e33. Semantic name remains unreviewed. */

void FUN_40a92d3c(LPCRITICAL_SECTION param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  EnterCriticalSection(param_1);
  piVar2 = param_1[1].OwningThread;
  if (piVar2 != (int *)0x0) {
    while (piVar2 = (int *)FUN_40a93dd4(piVar2), piVar2 != (int *)0x0) {
      if (piVar2 < (int *)0xfffffff1) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      else if (piVar2 == (int *)0xfffffffb) {
        pvVar1 = (void *)FUN_40a93dd4(param_1[1].OwningThread);
        operator_delete(pvVar1);
      }
      piVar2 = param_1[1].OwningThread;
    }
  }
  iVar3 = 0;
  if (0 < param_1[2].RecursionCount) {
    iVar4 = 0;
    do {
      (**(code **)(**(int **)(iVar4 + param_1[2].LockCount) + 8))();
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 < param_1[2].RecursionCount);
  }
  param_1[2].RecursionCount = 0;
  LeaveCriticalSection(param_1);
  return;
}



/* 40a92e34 FUN_40a92e34 */

/* Boundary evidence: original MIPS .pdata 40a92e34..40a92f2f. Semantic name remains unreviewed. */

void FUN_40a92e34(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  
  if (param_1[1].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    (**(code **)(*(int *)param_1[1].DebugInfo + 8))();
  }
  if (param_1[2].DebugInfo == (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
    FUN_40a92d3c(param_1);
  }
  else {
    EnterCriticalSection(param_1);
    param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x1;
    param_1[3].RecursionCount = 1;
    FUN_40a9293c((int)param_1);
    LeaveCriticalSection(param_1);
    WaitForSingleObject(param_1[2].DebugInfo,0xffffffff);
    CloseHandle(param_1[2].DebugInfo);
    puVar1 = param_1[1].OwningThread;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40a93d8c(puVar1);
      operator_delete(puVar1);
    }
  }
  if (param_1[1].LockSemaphore != (HANDLE)0x0) {
    CloseHandle(param_1[1].LockSemaphore);
  }
  operator_delete((void *)param_1[2].LockCount);
  FUN_40a9398c(&param_1[1].SpinCount);
  DeleteCriticalSection(param_1);
  return;
}



/* 40a92f30 FUN_40a92f30 */

/* Boundary evidence: original MIPS .pdata 40a92f30..40a93207. Semantic name remains unreviewed. */

undefined4 FUN_40a92f30(LPCRITICAL_SECTION param_1)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  LONG LVar4;
  ULONG_PTR UVar5;
  void *pvVar6;
  int iVar7;
  void *local_28 [2];
  
  pvVar6 = local_28[0];
  pvVar3 = local_28[0];
LAB_40a92f6c:
  do {
    bVar1 = false;
    EnterCriticalSection(param_1);
    do {
      while( true ) {
        if (param_1[3].DebugInfo != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
          FUN_40a92d3c(param_1);
          LeaveCriticalSection(param_1);
          return 0;
        }
        if (param_1[2].LockSemaphore != (HANDLE)0x0) {
          FUN_40a92d3c(param_1);
          EventModify(param_1[1].SpinCount,3);
        }
        uVar2 = FUN_40a93dd4(param_1[1].OwningThread);
        if (uVar2 != 0) break;
        if ((param_1[1].LockCount != 0) || (param_1[2].RecursionCount == 0)) {
          param_1[2].OwningThread = (HANDLE)((int)param_1[2].OwningThread + 1);
          bVar1 = true;
          goto LAB_40a93080;
        }
LAB_40a9302c:
        if (uVar2 != 0xfffffffe) {
          if (uVar2 == 0xfffffffb) {
            pvVar3 = (void *)FUN_40a93dd4(param_1[1].OwningThread);
          }
          goto LAB_40a93064;
        }
        if (param_1[2].RecursionCount != 0) goto LAB_40a93064;
      }
      if (0xfffffff0 < uVar2) goto LAB_40a9302c;
      if (param_1[2].RecursionCount < param_1[1].RecursionCount) {
        *(uint *)(param_1[2].RecursionCount * 4 + param_1[2].LockCount) = uVar2;
        param_1[2].RecursionCount = param_1[2].RecursionCount + 1;
      }
    } while (param_1[2].RecursionCount != param_1[1].RecursionCount);
LAB_40a93064:
    pvVar6 = (void *)param_1[2].RecursionCount;
    param_1[2].RecursionCount = 0;
LAB_40a93080:
    LeaveCriticalSection(param_1);
    if (!bVar1) {
      if (pvVar6 != (void *)0x0) {
        if (param_1[3].RecursionCount == 0) {
          LVar4 = (**(code **)(*(int *)param_1[1].DebugInfo + 0x1c))
                            (param_1[1].DebugInfo,param_1[2].LockCount,pvVar6,local_28);
          EnterCriticalSection(param_1);
          if (param_1[3].RecursionCount == 0) {
            param_1[3].RecursionCount = LVar4;
          }
          LeaveCriticalSection(param_1);
        }
        iVar7 = (int)pvVar6 << 2;
        do {
          iVar7 = iVar7 + -4;
          pvVar6 = (void *)((int)pvVar6 + -1);
          (**(code **)(**(int **)(param_1[2].LockCount + iVar7) + 8))();
        } while (pvVar6 != (void *)0x0);
      }
      if (uVar2 == 0xfffffffd) {
        if (param_1[3].RecursionCount != 0) goto LAB_40a92f6c;
        (**(code **)(*(int *)param_1->SpinCount + 0x38))();
      }
      if (uVar2 == 0xfffffffc) {
        UVar5 = param_1[1].SpinCount;
        param_1[3].RecursionCount = 0;
        EventModify(UVar5,3);
      }
      if (uVar2 == 0xfffffffb) {
        (**(code **)(*(int *)param_1->SpinCount + 0x44))();
        operator_delete(pvVar3);
      }
      goto LAB_40a92f6c;
    }
    WaitForSingleObject(param_1[1].LockSemaphore,0xffffffff);
  } while( true );
}



/* 40a93208 FUN_40a93208 */

/* Boundary evidence: original MIPS .pdata 40a93208..40a93277. Semantic name remains unreviewed. */

void FUN_40a93208(LPCRITICAL_SECTION param_1)

{
  int aiStack_10 [2];
  
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    param_1[3].LockCount = 1;
    FUN_40a92a9c(param_1,(undefined4 *)0x0,0,aiStack_10);
    param_1[3].LockCount = 0;
  }
  else {
    EnterCriticalSection(param_1);
    FUN_40a92a44((int)param_1,(int *)0xfffffffe);
    FUN_40a9293c((int)param_1);
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40a93278 FUN_40a93278 */

/* Boundary evidence: original MIPS .pdata 40a93278..40a93317. Semantic name remains unreviewed. */

void FUN_40a93278(LPCRITICAL_SECTION param_1)

{
  EnterCriticalSection(param_1);
  if (param_1[1].OwningThread == (HANDLE)0x0) {
    if (param_1[1].LockCount != 0) {
      FUN_40a93208(param_1);
    }
    if (param_1[3].RecursionCount == 0) {
      param_1[2].SpinCount = 0;
      (**(code **)(*(int *)param_1->SpinCount + 0x38))();
    }
  }
  else if (param_1[3].RecursionCount == 0) {
    param_1[2].SpinCount = 0;
    FUN_40a92a44((int)param_1,(int *)0xfffffffd);
    FUN_40a9293c((int)param_1);
  }
  LeaveCriticalSection(param_1);
  return;
}



/* 40a93318 FUN_40a93318 */

/* Boundary evidence: original MIPS .pdata 40a93318..40a933cb. Semantic name remains unreviewed. */

void FUN_40a93318(LPCRITICAL_SECTION param_1)

{
  int *piVar1;
  
  EnterCriticalSection(param_1);
  if ((param_1[2].SpinCount == 0) || (param_1[1].OwningThread == (HANDLE)0x0)) {
    LeaveCriticalSection(param_1);
    if (param_1[1].OwningThread == (HANDLE)0x0) {
      FUN_40a92d3c(param_1);
    }
    else {
      WaitForSingleObject((HANDLE)param_1[1].SpinCount,0xffffffff);
    }
    piVar1 = (int *)param_1->SpinCount;
    param_1[2].SpinCount = 1;
    param_1[2].LockSemaphore = (HANDLE)0x0;
    (**(code **)(*piVar1 + 0x40))();
    param_1[3].RecursionCount = 0;
  }
  else {
    param_1[2].LockSemaphore = (HANDLE)0x0;
    param_1[3].RecursionCount = 0;
    LeaveCriticalSection(param_1);
  }
  return;
}



/* 40a933cc FUN_40a933cc */

/* Boundary evidence: original MIPS .pdata 40a933cc..40a933f3. Semantic name remains unreviewed. */

void FUN_40a933cc(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  int aiStack_10 [2];
  
  local_res4[0] = param_2;
  FUN_40a92a9c(param_1,local_res4,1,aiStack_10);
  return;
}



/* 40a933f4 FUN_40a933f4 */

/* Boundary evidence: original MIPS .pdata 40a933f4..40a93447. Semantic name remains unreviewed. */

undefined4 FUN_40a933f4(LPCRITICAL_SECTION param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40a939bc();
  uVar2 = FUN_40a92f30(param_1);
  if (-1 < iVar1) {
    CoUninitialize();
  }
  return uVar2;
}



/* 40a93448 FUN_40a93448 */

/* Boundary evidence: original MIPS .pdata 40a93448..40a9368b. Semantic name remains unreviewed. */

LPCRITICAL_SECTION
FUN_40a93448(LPCRITICAL_SECTION param_1,undefined4 *param_2,DWORD *param_3,int param_4,int param_5,
            int param_6,int param_7,undefined4 param_8,int param_9)

{
  DWORD DVar1;
  int iVar2;
  void *pvVar3;
  HANDLE pvVar4;
  undefined4 *puVar5;
  PRTL_CRITICAL_SECTION_DEBUG p_Var6;
  uint uVar7;
  LONG LVar8;
  LPCRITICAL_SECTION p_Var9;
  DWORD aDStack_28 [2];
  
  InitializeCriticalSection(param_1);
  p_Var9 = param_1 + 1;
  param_1->SpinCount = (ULONG_PTR)param_2;
  p_Var9->DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  if ((param_7 == 0) || (LVar8 = 1, param_6 < 2)) {
    LVar8 = 0;
  }
  param_1[1].LockCount = LVar8;
  param_1[1].RecursionCount = param_6;
  param_1[1].OwningThread = (HANDLE)0x0;
  param_1[1].LockSemaphore = (HANDLE)0x0;
  FUN_40a9394c(&param_1[1].SpinCount,0);
  param_1[2].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[2].LockCount = 0;
  param_1[2].RecursionCount = 0;
  param_1[2].OwningThread = (HANDLE)0x0;
  param_1[2].LockSemaphore = (HANDLE)0x0;
  param_1[2].SpinCount = 1;
  param_1[3].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  param_1[3].LockCount = 0;
  param_1[3].RecursionCount = 0;
  if ((int)*param_3 < 0) {
    return param_1;
  }
  DVar1 = (**(code **)*param_2)(param_2,&DAT_40aa474c,p_Var9);
  *param_3 = DVar1;
  if ((int)DVar1 < 0) {
    return param_1;
  }
  if (((param_4 != 0) && (iVar2 = (**(code **)(*(int *)p_Var9->DebugInfo + 0x20))(), -1 < iVar2)) &&
     (param_5 = 1, iVar2 != 0)) {
    param_5 = 0;
  }
  if ((uint)param_1[1].RecursionCount < 0x40000000) {
    uVar7 = param_1[1].RecursionCount << 2;
  }
  else {
    uVar7 = 0xffffffff;
  }
  pvVar3 = operator_new(uVar7);
  param_1[2].LockCount = (LONG)pvVar3;
  if (pvVar3 == (void *)0x0) {
LAB_40a93588:
    DVar1 = 0x8007000e;
  }
  else {
    if (param_5 == 0) {
      return param_1;
    }
    pvVar4 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,0,0x7fffffff,(LPCWSTR)0x0);
    param_1[1].LockSemaphore = pvVar4;
    if (pvVar4 != (HANDLE)0x0) {
      puVar5 = operator_new(0x18);
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        FUN_40a93af8(puVar5,0,param_8);
      }
      param_1[1].OwningThread = puVar5;
      if (puVar5 == (undefined4 *)0x0) goto LAB_40a93588;
      p_Var6 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_40a933f4,param_1,0,aDStack_28);
      param_1[2].DebugInfo = p_Var6;
      if (p_Var6 != (PRTL_CRITICAL_SECTION_DEBUG)0x0) {
        FUN_40a9368c(p_Var6,param_9);
        return param_1;
      }
    }
    DVar1 = GetLastError();
    if (0 < (int)DVar1) {
      DVar1 = DVar1 & 0xffff | 0x80070000;
    }
  }
  *param_3 = DVar1;
  return param_1;
}



/* 40a9368c FUN_40a9368c */

/* Boundary evidence: original MIPS .pdata 40a9368c..40a9394b. Semantic name remains unreviewed. */

void FUN_40a9368c(undefined4 param_1,int param_2)

{
  LSTATUS LVar1;
  uint uVar2;
  DWORD local_38;
  DWORD local_34;
  HKEY local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20 [2];
  
  if (DAT_40ab1818 == 0xffffffff) {
    DAT_40ab181c = 0xfa;
    DAT_40ab1818 = 0xf9;
    DAT_40ab1820 = 0xfb;
    DAT_40ab1824 = 0xfc;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"SOFTWARE\\Microsoft\\DirectShow\\ThreadPriority",0,0,
                          &local_30);
    if (LVar1 == 0) {
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Highest",(LPDWORD)0x0,&local_34,(LPBYTE)&local_28,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_28)) {
        local_28 = DAT_40ab1818;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"AboveNormal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_2c,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_2c)) {
        local_2c = DAT_40ab181c;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"Normal",(LPDWORD)0x0,&local_34,(LPBYTE)&local_24,&local_38
                              );
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_24)) {
        local_24 = DAT_40ab1820;
      }
      local_38 = 4;
      LVar1 = RegQueryValueExW(local_30,L"BelowNormal",(LPDWORD)0x0,&local_34,(LPBYTE)local_20,
                               &local_38);
      if (((LVar1 != 0) || (local_34 != 4)) || (0xff < local_20[0])) {
        local_20[0] = DAT_40ab1824;
      }
      if (((local_28 <= local_2c) && (local_2c <= local_24)) && (local_24 <= local_20[0])) {
        DAT_40ab1818 = local_28;
        DAT_40ab181c = local_2c;
        DAT_40ab1820 = local_24;
        DAT_40ab1824 = local_20[0];
      }
      RegCloseKey(local_30);
    }
  }
  uVar2 = DAT_40ab1818;
  if (((param_2 != 1) && (uVar2 = DAT_40ab181c, param_2 != 2)) &&
     (uVar2 = DAT_40ab1824, param_2 != 4)) {
    uVar2 = DAT_40ab1820;
  }
  CeSetThreadPriority(param_1,uVar2);
  return;
}



/* 40a9394c FUN_40a9394c */

/* Boundary evidence: original MIPS .pdata 40a9394c..40a9398b. Semantic name remains unreviewed. */

undefined4 * FUN_40a9394c(undefined4 *param_1,BOOL param_2)

{
  HANDLE pvVar1;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,param_2,0,(LPCWSTR)0x0);
  *param_1 = pvVar1;
  return param_1;
}



/* 40a9398c FUN_40a9398c */

/* Boundary evidence: original MIPS .pdata 40a9398c..40a939bb. Semantic name remains unreviewed. */

void FUN_40a9398c(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40a939bc FUN_40a939bc */

/* Boundary evidence: original MIPS .pdata 40a939bc..40a93a2f. Semantic name remains unreviewed. */

undefined4 FUN_40a939bc(void)

{
  HMODULE pHVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0x80004005;
  pHVar1 = GetModuleHandleW(L"ole32.dll");
  if ((pHVar1 != (HMODULE)0x0) &&
     (pcVar2 = (code *)GetProcAddressW(pHVar1,L"CoInitializeEx"), pcVar2 != (code *)0x0)) {
    uVar3 = (*pcVar2)(0,0);
  }
  return uVar3;
}



/* 40a93a30 FUN_40a93a30 */

short * FUN_40a93a30(short *param_1,short *param_2,int param_3)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  if (param_3 != 0) {
    do {
      param_3 = param_3 + -1;
      if (param_3 == 0) {
        *psVar2 = 0;
        return param_1;
      }
      sVar1 = *param_2;
      param_2 = param_2 + 1;
      *psVar2 = sVar1;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
  }
  return param_1;
}



/* 40a93a6c FUN_40a93a6c */

/* Boundary evidence: original MIPS .pdata 40a93a6c..40a93af7. Semantic name remains unreviewed. */

undefined4 FUN_40a93a6c(wchar_t *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  size_t sVar2;
  LPVOID _Dst;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    sVar2 = wcslen(param_1);
    sVar2 = (sVar2 + 1) * 2;
    _Dst = CoTaskMemAlloc(sVar2);
    *param_2 = _Dst;
    if (_Dst == (LPVOID)0x0) {
      uVar1 = 0x8007000e;
    }
    else {
      memcpy(_Dst,param_1,sVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 40a93af8 FUN_40a93af8 */

undefined4 * FUN_40a93af8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_3;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40a93b18 FUN_40a93b18 */

undefined4 * FUN_40a93b18(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 10;
  param_1[4] = 0;
  param_1[5] = 0;
  return param_1;
}



/* 40a93b3c FUN_40a93b3c */

/* Boundary evidence: original MIPS .pdata 40a93b3c..40a93b8f. Semantic name remains unreviewed. */

void FUN_40a93b3c(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = (void *)*param_1;
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* 40a93b90 FUN_40a93b90 */

int FUN_40a93b90(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar2 = *param_1;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  return iVar1;
}



/* 40a93bd4 FUN_40a93bd4 */

/* Boundary evidence: original MIPS .pdata 40a93bd4..40a93c8f. Semantic name remains unreviewed. */

int FUN_40a93bd4(int *param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    if (*param_2 == 0) {
      *param_1 = param_2[1];
    }
    else {
      *(int *)(*param_2 + 4) = param_2[1];
    }
    if ((int *)param_2[1] == (int *)0x0) {
      param_1[1] = *param_2;
    }
    else {
      *(int *)param_2[1] = *param_2;
    }
    iVar1 = param_2[2];
    if (param_1[4] < param_1[3]) {
      param_2[1] = param_1[5];
      param_1[5] = (int)param_2;
      param_1[4] = param_1[4] + 1;
    }
    else {
      operator_delete(param_2);
    }
    param_1[2] = param_1[2] + -1;
  }
  return iVar1;
}



/* 40a93c90 FUN_40a93c90 */

/* Boundary evidence: original MIPS .pdata 40a93c90..40a93d2b. Semantic name remains unreviewed. */

undefined4 * FUN_40a93c90(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[5] = puVar1[1];
    param_1[4] = param_1[4] + -1;
    if (puVar1 != (undefined4 *)0x0) goto LAB_40a93ce0;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
LAB_40a93ce0:
  puVar1[2] = param_2;
  puVar1[1] = 0;
  *puVar1 = param_1[1];
  if (param_1[1] == 0) {
    *param_1 = puVar1;
  }
  else {
    *(undefined4 **)(param_1[1] + 4) = puVar1;
  }
  param_1[1] = puVar1;
  param_1[2] = param_1[2] + 1;
  return puVar1;
}



/* 40a93d2c FUN_40a93d2c */

/* Boundary evidence: original MIPS .pdata 40a93d2c..40a93d8b. Semantic name remains unreviewed. */

undefined4 FUN_40a93d2c(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *param_2;
  do {
    if (iVar2 == 0) {
      return 1;
    }
    puVar1 = (undefined4 *)(iVar2 + 8);
    iVar2 = *(int *)(iVar2 + 4);
    puVar1 = FUN_40a93c90(param_1,*puVar1);
  } while (puVar1 != (undefined4 *)0x0);
  return 0;
}



/* 40a93d8c FUN_40a93d8c */

/* Boundary evidence: original MIPS .pdata 40a93d8c..40a93dd3. Semantic name remains unreviewed. */

void FUN_40a93d8c(undefined4 *param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  FUN_40a93b3c(param_1);
  pvVar1 = (void *)param_1[5];
  while (pvVar1 != (void *)0x0) {
    pvVar2 = *(void **)((int)pvVar1 + 4);
    operator_delete(pvVar1);
    pvVar1 = pvVar2;
  }
  return;
}



/* 40a93dd4 FUN_40a93dd4 */

/* Boundary evidence: original MIPS .pdata 40a93dd4..40a93def. Semantic name remains unreviewed. */

void FUN_40a93dd4(int *param_1)

{
  FUN_40a93bd4(param_1,(int *)*param_1);
  return;
}



/* 40a93ef0 FUN_40a93ef0 */

/* Boundary evidence: original MIPS .pdata 40a93ef0..40a93f63. Semantic name remains unreviewed. */

void FUN_40a93ef0(void)

{
  uint uVar1;
  
  if ((DAT_40ab1828 == 0) || (DAT_40ab1828 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40ab1828 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40ab1828 == 0) {
      DAT_40ab1828 = 0xb064;
    }
  }
  DAT_40ab182c = ~DAT_40ab1828;
  return;
}



/* 40a93f64 FUN_40a93f64 */

/* Boundary evidence: original MIPS .pdata 40a93f64..40a93fb7. Semantic name remains unreviewed. */

void FUN_40a93f64(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40a93fe4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40a93fb8 FUN_40a93fb8 */

/* Boundary evidence: original MIPS .pdata 40a93fb8..40a93fe3. Semantic name remains unreviewed. */

undefined4 FUN_40a93fb8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40a93f64(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40a93fe4 FUN_40a93fe4 */

/* Boundary evidence: original MIPS .pdata 40a93fe4..40a9402b. Semantic name remains unreviewed. */

void FUN_40a93fe4(uint param_1)

{
  if ((param_1 == DAT_40ab1828) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40a9408c FUN_40a9408c */

/* Boundary evidence: original MIPS .pdata 40a9408c..40a941c7. Semantic name remains unreviewed. */

int FUN_40a9408c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40ab2778 != (code *)0x0) {
      iVar2 = (*DAT_40ab2778)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40a9413c;
    FUN_40a94400();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_40a9413c:
  if (((param_2 == 0) && (FUN_40a94388(), iVar1 != 0)) && (DAT_40ab2778 != (code *)0x0)) {
    iVar1 = (*DAT_40ab2778)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40a941c8 FUN_40a941c8 */

/* Boundary evidence: original MIPS .pdata 40a941c8..40a941f3. Semantic name remains unreviewed. */

void FUN_40a941c8(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40a941f4 entry */

/* Boundary evidence: original MIPS .pdata 40a941f4..40a9424b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40a93ef0();
  }
  FUN_40a9408c(param_1,param_2,param_3);
  return;
}



/* 40a9429c FUN_40a9429c */

/* Boundary evidence: original MIPS .pdata 40a9429c..40a94387. Semantic name remains unreviewed. */

void FUN_40a9429c(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40ab276c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40ab2774;
    if (DAT_40ab2774 != (undefined4 *)0x0) {
      while (DAT_40ab2770 = DAT_40ab2770 + -1, _Memory <= DAT_40ab2770) {
        if ((code *)*DAT_40ab2770 != (code *)0x0) {
          (*(code *)*DAT_40ab2770)();
          _Memory = DAT_40ab2774;
        }
      }
      free(_Memory);
      DAT_40ab2770 = (undefined4 *)0x0;
      DAT_40ab2774 = (undefined4 *)0x0;
    }
    FUN_40a943ac((undefined4 *)&DAT_40a95010,(undefined4 *)&DAT_40a95014);
  }
  FUN_40a943ac((undefined4 *)&DAT_40a95018,(undefined4 *)&DAT_40a9501c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40a94388 FUN_40a94388 */

/* Boundary evidence: original MIPS .pdata 40a94388..40a943ab. Semantic name remains unreviewed. */

void FUN_40a94388(void)

{
  FUN_40a9429c(0,0,1);
  return;
}



/* 40a943ac FUN_40a943ac */

/* Boundary evidence: original MIPS .pdata 40a943ac..40a943ff. Semantic name remains unreviewed. */

void FUN_40a943ac(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40a94400 FUN_40a94400 */

/* Boundary evidence: original MIPS .pdata 40a94400..40a9443b. Semantic name remains unreviewed. */

void FUN_40a94400(void)

{
  FUN_40a943ac((undefined4 *)&DAT_40a95008,(undefined4 *)&DAT_40a9500c);
  FUN_40a943ac((undefined4 *)&DAT_40a95000,(undefined4 *)&DAT_40a95004);
  return;
}


