; wavedev2_i2s.dll fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c
c0942ae0  addiu     $sp, $sp, -0x40
c0942ae4  sw        $ra, 0x3c($sp)
c0942ae8  sw        $fp, 0x18($sp)
c0942aec  sw        $s7, 0x1c($sp)
c0942af0  sw        $s6, 0x20($sp)
c0942af4  sw        $s5, 0x24($sp)
c0942af8  sw        $s4, 0x28($sp)
c0942afc  sw        $s3, 0x2c($sp)
c0942b00  sw        $s2, 0x30($sp)
c0942b04  sw        $s1, 0x34($sp)
c0942b08  sw        $s0, 0x38($sp)
c0942b0c  move      $s7, $a1
c0942b10  addiu     $s4, $a0, 4
c0942b14  lw        $s5, ($s4)
c0942b18  move      $s3, $a3
c0942b1c  move      $fp, $a2
c0942b20  move      $s1, $s7
c0942b24  beq       $s5, $s4, 0xc0942b90
c0942b28  move      $s2, $zero
c0942b2c  addiu     $s0, $s5, -4
c0942b30  move      $a0, $s0
c0942b34  jal       0xc0943878
c0942b38  lw        $s5, ($s5)
c0942b3c  lw        $v0, ($s0)
c0942b40  lw        $t0, 0x1c($v0)
c0942b44  move      $a3, $s1
c0942b48  move      $a2, $fp
c0942b4c  move      $a1, $s7
c0942b50  move      $a0, $s0
c0942b54  jalr      $t0
c0942b58  sw        $s3, 0x10($sp)
c0942b5c  move      $a0, $s0
c0942b60  jal       0xc0943888
c0942b64  move      $s6, $v0
c0942b68  sltu      $a0, $s7, $s6
c0942b6c  beqz      $a0, 0xc0942b78
c0942b70  nop       
c0942b74  addiu     $s2, $s2, 1
c0942b78  sltu      $t0, $s1, $s6
c0942b7c  beqz      $t0, 0xc0942b88
c0942b80  nop       
c0942b84  move      $s1, $s6
c0942b88  bne       $s5, $s4, 0xc0942b2c
c0942b8c  nop       
c0942b90  beqz      $s3, 0xc0942b9c
c0942b94  nop       
c0942b98  sw        $s2, ($s3)
c0942b9c  move      $v0, $s1
c0942ba0  lw        $fp, 0x18($sp)
c0942ba4  lw        $s7, 0x1c($sp)
c0942ba8  lw        $s6, 0x20($sp)
c0942bac  lw        $s5, 0x24($sp)
c0942bb0  lw        $s4, 0x28($sp)
c0942bb4  lw        $s3, 0x2c($sp)
c0942bb8  lw        $s2, 0x30($sp)
c0942bbc  lw        $s1, 0x34($sp)
c0942bc0  lw        $s0, 0x38($sp)
c0942bc4  lw        $ra, 0x3c($sp)
c0942bc8  jr        $ra
c0942bcc  addiu     $sp, $sp, 0x40
c094791c  addiu     $sp, $sp, -0x30
c0947920  sw        $ra, 0x2c($sp)
c0947924  sw        $s2, 0x20($sp)
c0947928  sw        $s1, 0x24($sp)
c094792c  sw        $s0, 0x28($sp)
c0947930  move      $s0, $a0
c0947934  addiu     $s2, $s0, 0xc8
c0947938  addiu     $a1, $zero, 2
c094793c  jal       0xc0948554
c0947940  move      $a0, $s2
c0947944  addiu     $a2, $zero, 8
c0947948  addiu     $a1, $zero, 0
c094794c  addiu     $a0, $sp, 0x14
c0947950  sw        $zero, 0x10($sp)
c0947954  jal       0xc09490f0 ; import thunk COREDLL.dll!memset@1047
c0947958  move      $s1, $v0
c094795c  addiu     $a2, $s1, 0x1000
c0947960  addiu     $a0, $s0, 0x50
c0947964  addiu     $a3, $sp, 0x10
c0947968  jal       0xc0942ae0
c094796c  move      $a1, $s1
c0947970  subu      $s0, $v0, $s1
c0947974  beqz      $s0, 0xc0947990
c0947978  nop       
c094797c  move      $a3, $s0
c0947980  move      $a2, $s1
c0947984  addiu     $a1, $zero, 2
c0947988  jal       0xc09485a0
c094798c  move      $a0, $s2
c0947990  move      $v0, $s0
c0947994  lw        $s2, 0x20($sp)
c0947998  lw        $s1, 0x24($sp)
c094799c  lw        $s0, 0x28($sp)
c09479a0  lw        $ra, 0x2c($sp)
c09479a4  jr        $ra
c09479a8  addiu     $sp, $sp, 0x30
c0947a28  addiu     $sp, $sp, -0x28
c0947a2c  sw        $ra, 0x24($sp)
c0947a30  sw        $s4, 0x10($sp)
c0947a34  sw        $s3, 0x14($sp)
c0947a38  sw        $s2, 0x18($sp)
c0947a3c  sw        $s1, 0x1c($sp)
c0947a40  sw        $s0, 0x20($sp)
c0947a44  move      $s0, $a0
c0947a48  lui       $s4, 0xc095
c0947a4c  addiu     $s1, $s0, 0xc8
c0947a50  addiu     $s2, $s0, 4
c0947a54  jal       0xc0948b38 ; import thunk COREDLL.dll!InterruptDone@628
c0947a58  lw        $a0, 0xac($s0)
c0947a5c  lw        $a0, 0xb4($s0)
c0947a60  lw        $t0, -0x5fac($s4)
c0947a64  jalr      $t0
c0947a68  addiu     $a1, $zero, -1
c0947a6c  jal       0xc0948a98 ; import thunk COREDLL.dll!EnterCriticalSection@4
c0947a70  move      $a0, $s2
c0947a74  jal       0xc09485f0
c0947a78  move      $a0, $s1
c0947a7c  move      $s3, $v0
c0947a80  andi      $t0, $s3, 2
c0947a84  beqz      $t0, 0xc0947ab8
c0947a88  nop       
c0947a8c  jal       0xc094791c
c0947a90  move      $a0, $s0
c0947a94  bnez      $v0, 0xc0947ab8
c0947a98  nop       
c0947a9c  lw        $t0, 0x84($s0)
c0947aa0  beqz      $t0, 0xc0947ab8
c0947aa4  nop       
c0947aa8  addiu     $a1, $zero, 2
c0947aac  jal       0xc09484c4
c0947ab0  move      $a0, $s1
c0947ab4  sw        $zero, 0x84($s0)
c0947ab8  andi      $t0, $s3, 1
c0947abc  beqz      $t0, 0xc0947af0
c0947ac0  nop       
c0947ac4  jal       0xc09479ac
c0947ac8  move      $a0, $s0
c0947acc  bnez      $v0, 0xc0947af0
c0947ad0  nop       
c0947ad4  lw        $t0, 0x80($s0)
c0947ad8  beqz      $t0, 0xc0947af0
c0947adc  nop       
c0947ae0  addiu     $a1, $zero, 1
c0947ae4  jal       0xc09484c4
c0947ae8  move      $a0, $s1
c0947aec  sw        $zero, 0x80($s0)
c0947af0  jal       0xc0948aa8 ; import thunk COREDLL.dll!LeaveCriticalSection@5
c0947af4  move      $a0, $s2
c0947af8  b         0xc0947a54
c0947afc  nop       
c0947e50  addiu     $sp, $sp, -0x20
c0947e54  sw        $ra, 0x18($sp)
c0947e58  sw        $s1, 0x10($sp)
c0947e5c  sw        $s0, 0x14($sp)
c0947e60  move      $s1, $a0
c0947e64  lw        $t0, 0x84($s1)
c0947e68  bnez      $t0, 0xc0947eac
c0947e6c  addiu     $t1, $zero, 1
c0947e70  move      $a0, $s1
c0947e74  jal       0xc094791c
c0947e78  sw        $t1, 0x84($s1)
c0947e7c  move      $a0, $s1
c0947e80  jal       0xc094791c
c0947e84  move      $s0, $v0
c0947e88  addu      $a1, $v0, $s0
c0947e8c  beqz      $a1, 0xc0947ea8
c0947e90  nop       
c0947e94  addiu     $a0, $s1, 0xc8
c0947e98  jal       0xc0948440
c0947e9c  addiu     $a1, $zero, 2
c0947ea0  b         0xc0947eac
c0947ea4  nop       
c0947ea8  sw        $zero, 0x84($s1)
c0947eac  lw        $s1, 0x10($sp)
c0947eb0  lw        $s0, 0x14($sp)
c0947eb4  lw        $ra, 0x18($sp)
c0947eb8  addiu     $v0, $zero, 1
c0947ebc  jr        $ra
c0947ec0  addiu     $sp, $sp, 0x20
c09483c0  addiu     $sp, $sp, -0x20
c09483c4  sw        $ra, 0x18($sp)
c09483c8  sw        $s1, 0x10($sp)
c09483cc  sw        $s0, 0x14($sp)
c09483d0  jal       0xc0948bf8 ; import thunk CEDDK.dll!HalAllocateDMAChannel
c09483d4  move      $s0, $a0
c09483d8  beqz      $v0, 0xc0948424
c09483dc  sw        $v0, 0x1c($s0)
c09483e0  lw        $a2, 0x20($s0)
c09483e4  addiu     $a3, $zero, 1
c09483e8  addiu     $a1, $zero, 0xc
c09483ec  move      $a0, $v0
c09483f0  jal       0xc0948be8 ; import thunk CEDDK.dll!HalInitDmaChannel
c09483f4  addiu     $s1, $zero, 1
c09483f8  jal       0xc0948bf8 ; import thunk CEDDK.dll!HalAllocateDMAChannel
c09483fc  nop       
c0948400  beqz      $v0, 0xc0948424
c0948404  sw        $v0, 0x18($s0)
c0948408  lw        $a2, 0x20($s0)
c094840c  addiu     $a3, $zero, 1
c0948410  addiu     $a1, $zero, 0xd
c0948414  jal       0xc0948be8 ; import thunk CEDDK.dll!HalInitDmaChannel
c0948418  move      $a0, $v0
c094841c  b         0xc0948428
c0948420  nop       
c0948424  move      $s1, $zero
c0948428  move      $v0, $s1
c094842c  lw        $s1, 0x10($sp)
c0948430  lw        $s0, 0x14($sp)
c0948434  lw        $ra, 0x18($sp)
c0948438  jr        $ra
c094843c  addiu     $sp, $sp, 0x20
c0948440  addiu     $sp, $sp, -0x18
c0948444  sw        $ra, 0x14($sp)
c0948448  sw        $s0, 0x10($sp)
c094844c  move      $t0, $a1
c0948450  addiu     $t1, $zero, 1
c0948454  beq       $t0, $t1, 0xc0948490
c0948458  move      $s0, $a0
c094845c  addiu     $t1, $zero, 2
c0948460  bne       $t0, $t1, 0xc09484b4
c0948464  nop       
c0948468  lw        $t0, 8($s0)
c094846c  addiu     $a0, $t0, 0x10
c0948470  jal       0xc0948b98 ; import thunk CEDDK.dll!WRITE_REGISTER_ULONG@35
c0948474  addiu     $a1, $zero, 1
c0948478  lui       $t0, 0xc095
c094847c  lw        $t0, -0x5fa4($t0) ; IAT COREDLL.dll!Sleep@496
c0948480  jalr      $t0 ; call candidate COREDLL.dll!Sleep@496
c0948484  addiu     $a0, $zero, 1
c0948488  b         0xc09484ac
c094848c  lw        $a0, 0x1c($s0)
c0948490  jal       0xc0948c18 ; import thunk CEDDK.dll!HalSetDMAForReceive
c0948494  lw        $a0, 0x18($s0)
c0948498  lw        $a0, 8($s0)
c094849c  addiu     $a0, $a0, 0x10
c09484a0  jal       0xc0948b98 ; import thunk CEDDK.dll!WRITE_REGISTER_ULONG@35
c09484a4  addiu     $a1, $zero, 0x10
c09484a8  lw        $a0, 0x18($s0)
c09484ac  jal       0xc0948c08 ; import thunk CEDDK.dll!HalStartDMA
c09484b0  nop       
c09484b4  lw        $s0, 0x10($sp)
c09484b8  lw        $ra, 0x14($sp)
c09484bc  jr        $ra
c09484c0  addiu     $sp, $sp, 0x18
c0948554  addiu     $sp, $sp, -0x18
c0948558  sw        $ra, 0x10($sp)
c094855c  move      $t0, $a1
c0948560  addiu     $t1, $zero, 1
c0948564  beq       $t0, $t1, 0xc0948588
c0948568  nop       
c094856c  addiu     $t2, $zero, 2
c0948570  beq       $t0, $t2, 0xc0948580
c0948574  nop       
c0948578  b         0xc0948594
c094857c  move      $v0, $zero
c0948580  b         0xc094858c
c0948584  lw        $a0, 0x1c($a0)
c0948588  lw        $a0, 0x18($a0)
c094858c  jal       0xc0948c38 ; import thunk CEDDK.dll!HalGetNextDMABuffer
c0948590  nop       
c0948594  lw        $ra, 0x10($sp)
c0948598  jr        $ra
c094859c  addiu     $sp, $sp, 0x18
c09485a0  addiu     $sp, $sp, -0x18
c09485a4  sw        $ra, 0x10($sp)
c09485a8  move      $t0, $a1
c09485ac  addiu     $t2, $zero, 1
c09485b0  beq       $t0, $t2, 0xc09485d4
c09485b4  move      $t1, $a2
c09485b8  addiu     $t3, $zero, 2
c09485bc  beq       $t0, $t3, 0xc09485cc
c09485c0  nop       
c09485c4  b         0xc09485e4
c09485c8  move      $v0, $zero
c09485cc  b         0xc09485d8
c09485d0  lw        $a0, 0x1c($a0)
c09485d4  lw        $a0, 0x18($a0)
c09485d8  move      $a2, $a3
c09485dc  jal       0xc0948c48 ; import thunk CEDDK.dll!HalActivateDMABuffer
c09485e0  move      $a1, $t1
c09485e4  lw        $ra, 0x10($sp)
c09485e8  jr        $ra
c09485ec  addiu     $sp, $sp, 0x18
; wavedev2_i2s2.dll eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009
c0952b48  addiu     $sp, $sp, -0x40
c0952b4c  sw        $ra, 0x3c($sp)
c0952b50  sw        $fp, 0x18($sp)
c0952b54  sw        $s7, 0x1c($sp)
c0952b58  sw        $s6, 0x20($sp)
c0952b5c  sw        $s5, 0x24($sp)
c0952b60  sw        $s4, 0x28($sp)
c0952b64  sw        $s3, 0x2c($sp)
c0952b68  sw        $s2, 0x30($sp)
c0952b6c  sw        $s1, 0x34($sp)
c0952b70  sw        $s0, 0x38($sp)
c0952b74  move      $s7, $a1
c0952b78  addiu     $s4, $a0, 4
c0952b7c  lw        $s5, ($s4)
c0952b80  move      $s3, $a3
c0952b84  move      $fp, $a2
c0952b88  move      $s1, $s7
c0952b8c  beq       $s5, $s4, 0xc0952bf8
c0952b90  move      $s2, $zero
c0952b94  addiu     $s0, $s5, -4
c0952b98  move      $a0, $s0
c0952b9c  jal       0xc0953984
c0952ba0  lw        $s5, ($s5)
c0952ba4  lw        $v0, ($s0)
c0952ba8  lw        $t0, 0x1c($v0)
c0952bac  move      $a3, $s1
c0952bb0  move      $a2, $fp
c0952bb4  move      $a1, $s7
c0952bb8  move      $a0, $s0
c0952bbc  jalr      $t0
c0952bc0  sw        $s3, 0x10($sp)
c0952bc4  move      $a0, $s0
c0952bc8  jal       0xc0953994
c0952bcc  move      $s6, $v0
c0952bd0  sltu      $a0, $s7, $s6
c0952bd4  beqz      $a0, 0xc0952be0
c0952bd8  nop       
c0952bdc  addiu     $s2, $s2, 1
c0952be0  sltu      $t0, $s1, $s6
c0952be4  beqz      $t0, 0xc0952bf0
c0952be8  nop       
c0952bec  move      $s1, $s6
c0952bf0  bne       $s5, $s4, 0xc0952b94
c0952bf4  nop       
c0952bf8  beqz      $s3, 0xc0952c04
c0952bfc  nop       
c0952c00  sw        $s2, ($s3)
c0952c04  move      $v0, $s1
c0952c08  lw        $fp, 0x18($sp)
c0952c0c  lw        $s7, 0x1c($sp)
c0952c10  lw        $s6, 0x20($sp)
c0952c14  lw        $s5, 0x24($sp)
c0952c18  lw        $s4, 0x28($sp)
c0952c1c  lw        $s3, 0x2c($sp)
c0952c20  lw        $s2, 0x30($sp)
c0952c24  lw        $s1, 0x34($sp)
c0952c28  lw        $s0, 0x38($sp)
c0952c2c  lw        $ra, 0x3c($sp)
c0952c30  jr        $ra
c0952c34  addiu     $sp, $sp, 0x40
c0957a18  addiu     $sp, $sp, -0x30
c0957a1c  sw        $ra, 0x2c($sp)
c0957a20  sw        $s2, 0x20($sp)
c0957a24  sw        $s1, 0x24($sp)
c0957a28  sw        $s0, 0x28($sp)
c0957a2c  move      $s0, $a0
c0957a30  addiu     $s2, $s0, 0xc8
c0957a34  addiu     $a1, $zero, 2
c0957a38  jal       0xc0958608
c0957a3c  move      $a0, $s2
c0957a40  addiu     $a2, $zero, 8
c0957a44  addiu     $a1, $zero, 0
c0957a48  addiu     $a0, $sp, 0x14
c0957a4c  sw        $zero, 0x10($sp)
c0957a50  jal       0xc0958e8c ; import thunk COREDLL.dll!memset@1047
c0957a54  move      $s1, $v0
c0957a58  addiu     $a2, $s1, 0x100
c0957a5c  addiu     $a0, $s0, 0x50
c0957a60  addiu     $a3, $sp, 0x10
c0957a64  jal       0xc0952b48
c0957a68  move      $a1, $s1
c0957a6c  subu      $s0, $v0, $s1
c0957a70  beqz      $s0, 0xc0957a8c
c0957a74  nop       
c0957a78  move      $a3, $s0
c0957a7c  move      $a2, $s1
c0957a80  addiu     $a1, $zero, 2
c0957a84  jal       0xc0958654
c0957a88  move      $a0, $s2
c0957a8c  move      $v0, $s0
c0957a90  lw        $s2, 0x20($sp)
c0957a94  lw        $s1, 0x24($sp)
c0957a98  lw        $s0, 0x28($sp)
c0957a9c  lw        $ra, 0x2c($sp)
c0957aa0  jr        $ra
c0957aa4  addiu     $sp, $sp, 0x30
c0957b24  addiu     $sp, $sp, -0x28
c0957b28  sw        $ra, 0x24($sp)
c0957b2c  sw        $s4, 0x10($sp)
c0957b30  sw        $s3, 0x14($sp)
c0957b34  sw        $s2, 0x18($sp)
c0957b38  sw        $s1, 0x1c($sp)
c0957b3c  sw        $s0, 0x20($sp)
c0957b40  move      $s0, $a0
c0957b44  lui       $s4, 0xc096
c0957b48  addiu     $s1, $s0, 0xc8
c0957b4c  addiu     $s2, $s0, 4
c0957b50  jal       0xc09588d4 ; import thunk COREDLL.dll!InterruptDone@628
c0957b54  lw        $a0, 0xac($s0)
c0957b58  lw        $a0, 0xb4($s0)
c0957b5c  lw        $t0, -0x5fb0($s4)
c0957b60  jalr      $t0
c0957b64  addiu     $a1, $zero, -1
c0957b68  jal       0xc0958834 ; import thunk COREDLL.dll!EnterCriticalSection@4
c0957b6c  move      $a0, $s2
c0957b70  jal       0xc09586a4
c0957b74  move      $a0, $s1
c0957b78  move      $s3, $v0
c0957b7c  andi      $t0, $s3, 2
c0957b80  beqz      $t0, 0xc0957bb4
c0957b84  nop       
c0957b88  jal       0xc0957a18
c0957b8c  move      $a0, $s0
c0957b90  bnez      $v0, 0xc0957bb4
c0957b94  nop       
c0957b98  lw        $t0, 0x84($s0)
c0957b9c  beqz      $t0, 0xc0957bb4
c0957ba0  nop       
c0957ba4  addiu     $a1, $zero, 2
c0957ba8  jal       0xc09585a0
c0957bac  move      $a0, $s1
c0957bb0  sw        $zero, 0x84($s0)
c0957bb4  andi      $t0, $s3, 1
c0957bb8  beqz      $t0, 0xc0957bec
c0957bbc  nop       
c0957bc0  jal       0xc0957aa8
c0957bc4  move      $a0, $s0
c0957bc8  bnez      $v0, 0xc0957bec
c0957bcc  nop       
c0957bd0  lw        $t0, 0x80($s0)
c0957bd4  beqz      $t0, 0xc0957bec
c0957bd8  nop       
c0957bdc  addiu     $a1, $zero, 1
c0957be0  jal       0xc09585a0
c0957be4  move      $a0, $s1
c0957be8  sw        $zero, 0x80($s0)
c0957bec  jal       0xc0958844 ; import thunk COREDLL.dll!LeaveCriticalSection@5
c0957bf0  move      $a0, $s2
c0957bf4  b         0xc0957b50
c0957bf8  nop       
c0957f4c  addiu     $sp, $sp, -0x20
c0957f50  sw        $ra, 0x18($sp)
c0957f54  sw        $s1, 0x10($sp)
c0957f58  sw        $s0, 0x14($sp)
c0957f5c  move      $s1, $a0
c0957f60  lw        $t0, 0x84($s1)
c0957f64  bnez      $t0, 0xc0957fa8
c0957f68  addiu     $t1, $zero, 1
c0957f6c  move      $a0, $s1
c0957f70  jal       0xc0957a18
c0957f74  sw        $t1, 0x84($s1)
c0957f78  move      $a0, $s1
c0957f7c  jal       0xc0957a18
c0957f80  move      $s0, $v0
c0957f84  addu      $a1, $v0, $s0
c0957f88  beqz      $a1, 0xc0957fa4
c0957f8c  nop       
c0957f90  addiu     $a0, $s1, 0xc8
c0957f94  jal       0xc095852c
c0957f98  addiu     $a1, $zero, 2
c0957f9c  b         0xc0957fa8
c0957fa0  nop       
c0957fa4  sw        $zero, 0x84($s1)
c0957fa8  lw        $s1, 0x10($sp)
c0957fac  lw        $s0, 0x14($sp)
c0957fb0  lw        $ra, 0x18($sp)
c0957fb4  addiu     $v0, $zero, 1
c0957fb8  jr        $ra
c0957fbc  addiu     $sp, $sp, 0x20
c09584ac  addiu     $sp, $sp, -0x20
c09584b0  sw        $ra, 0x18($sp)
c09584b4  sw        $s1, 0x10($sp)
c09584b8  sw        $s0, 0x14($sp)
c09584bc  jal       0xc0958994 ; import thunk CEDDK.dll!HalAllocateDMAChannel
c09584c0  move      $s0, $a0
c09584c4  beqz      $v0, 0xc0958510
c09584c8  sw        $v0, 0x18($s0)
c09584cc  lw        $a2, 0x1c($s0)
c09584d0  addiu     $a3, $zero, 1
c09584d4  addiu     $a1, $zero, 0x12
c09584d8  move      $a0, $v0
c09584dc  jal       0xc0958984 ; import thunk CEDDK.dll!HalInitDmaChannel
c09584e0  addiu     $s1, $zero, 1
c09584e4  jal       0xc0958994 ; import thunk CEDDK.dll!HalAllocateDMAChannel
c09584e8  nop       
c09584ec  beqz      $v0, 0xc0958510
c09584f0  sw        $v0, 0x14($s0)
c09584f4  lw        $a2, 0x1c($s0)
c09584f8  addiu     $a3, $zero, 1
c09584fc  addiu     $a1, $zero, 0x13
c0958500  jal       0xc0958984 ; import thunk CEDDK.dll!HalInitDmaChannel
c0958504  move      $a0, $v0
c0958508  b         0xc0958514
c095850c  nop       
c0958510  move      $s1, $zero
c0958514  move      $v0, $s1
c0958518  lw        $s1, 0x10($sp)
c095851c  lw        $s0, 0x14($sp)
c0958520  lw        $ra, 0x18($sp)
c0958524  jr        $ra
c0958528  addiu     $sp, $sp, 0x20
c095852c  addiu     $sp, $sp, -0x18
c0958530  sw        $ra, 0x14($sp)
c0958534  sw        $s0, 0x10($sp)
c0958538  move      $t0, $a1
c095853c  addiu     $t1, $zero, 1
c0958540  beq       $t0, $t1, 0xc095856c
c0958544  move      $s0, $a0
c0958548  addiu     $t1, $zero, 2
c095854c  bne       $t0, $t1, 0xc0958590
c0958550  nop       
c0958554  lw        $t0, 8($s0)
c0958558  addiu     $a0, $t0, 0x10
c095855c  jal       0xc0958934 ; import thunk CEDDK.dll!WRITE_REGISTER_ULONG@35
c0958560  addiu     $a1, $zero, 1
c0958564  b         0xc0958588
c0958568  lw        $a0, 0x18($s0)
c095856c  jal       0xc09589b4 ; import thunk CEDDK.dll!HalSetDMAForReceive
c0958570  lw        $a0, 0x14($s0)
c0958574  lw        $a0, 8($s0)
c0958578  addiu     $a0, $a0, 0x10
c095857c  jal       0xc0958934 ; import thunk CEDDK.dll!WRITE_REGISTER_ULONG@35
c0958580  addiu     $a1, $zero, 0x10
c0958584  lw        $a0, 0x14($s0)
c0958588  jal       0xc09589a4 ; import thunk CEDDK.dll!HalStartDMA
c095858c  nop       
c0958590  lw        $s0, 0x10($sp)
c0958594  lw        $ra, 0x14($sp)
c0958598  jr        $ra
c095859c  addiu     $sp, $sp, 0x18
c0958608  addiu     $sp, $sp, -0x18
c095860c  sw        $ra, 0x10($sp)
c0958610  move      $t0, $a1
c0958614  addiu     $t1, $zero, 1
c0958618  beq       $t0, $t1, 0xc095863c
c095861c  nop       
c0958620  addiu     $t2, $zero, 2
c0958624  beq       $t0, $t2, 0xc0958634
c0958628  nop       
c095862c  b         0xc0958648
c0958630  move      $v0, $zero
c0958634  b         0xc0958640
c0958638  lw        $a0, 0x18($a0)
c095863c  lw        $a0, 0x14($a0)
c0958640  jal       0xc09589d4 ; import thunk CEDDK.dll!HalGetNextDMABuffer
c0958644  nop       
c0958648  lw        $ra, 0x10($sp)
c095864c  jr        $ra
c0958650  addiu     $sp, $sp, 0x18
c0958654  addiu     $sp, $sp, -0x18
c0958658  sw        $ra, 0x10($sp)
c095865c  move      $t0, $a1
c0958660  addiu     $t2, $zero, 1
c0958664  beq       $t0, $t2, 0xc0958688
c0958668  move      $t1, $a2
c095866c  addiu     $t3, $zero, 2
c0958670  beq       $t0, $t3, 0xc0958680
c0958674  nop       
c0958678  b         0xc0958698
c095867c  move      $v0, $zero
c0958680  b         0xc095868c
c0958684  lw        $a0, 0x18($a0)
c0958688  lw        $a0, 0x14($a0)
c095868c  move      $a2, $a3
c0958690  jal       0xc09589e4 ; import thunk CEDDK.dll!HalActivateDMABuffer
c0958694  move      $a1, $t1
c0958698  lw        $ra, 0x10($sp)
c095869c  jr        $ra
c09586a0  addiu     $sp, $sp, 0x18
; ceddk.dll 9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731
40233994  addiu     $sp, $sp, -0x18
40233998  sw        $ra, 0x14($sp)
4023399c  sw        $s0, 0x10($sp)
402339a0  move      $s0, $a0
402339a4  lui       $t0, 0x4023
402339a8  lw        $a1, 0xc($s0)
402339ac  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
402339b0  addiu     $a0, $t0, 0x1aa8
402339b4  lui       $t0, 0x4023
402339b8  lw        $a2, 0x48($s0)
402339bc  lw        $a1, 0x40($s0)
402339c0  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
402339c4  addiu     $a0, $t0, 0x1a68
402339c8  lui       $t0, 0x4023
402339cc  lw        $a2, 0x50($s0)
402339d0  lw        $a1, 0x44($s0)
402339d4  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
402339d8  addiu     $a0, $t0, 0x1a28
402339dc  lui       $t0, 0x4023
402339e0  lw        $a2, 0x30($s0)
402339e4  lw        $a1, 0x28($s0)
402339e8  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
402339ec  addiu     $a0, $t0, 0x19e8
402339f0  lui       $t0, 0x4023
402339f4  lw        $a2, 0x38($s0)
402339f8  lw        $a1, 0x2c($s0)
402339fc  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
40233a00  addiu     $a0, $t0, 0x19a8
40233a04  jal       0x402338f8
40233a08  lw        $a0, 0x24($s0)
40233a0c  jal       0x40233834
40233a10  lw        $a0, 0x40($s0)
40233a14  jal       0x40233834
40233a18  lw        $a0, 0x44($s0)
40233a1c  lw        $s0, 0x10($sp)
40233a20  lw        $ra, 0x14($sp)
40233a24  jr        $ra
40233a28  addiu     $sp, $sp, 0x18
40233a2c  addiu     $sp, $sp, -0x38
40233a30  sw        $ra, 0x30($sp)
40233a34  sw        $s5, 0x18($sp)
40233a38  sw        $s4, 0x1c($sp)
40233a3c  sw        $s3, 0x20($sp)
40233a40  sw        $s2, 0x24($sp)
40233a44  sw        $s1, 0x28($sp)
40233a48  sw        $s0, 0x2c($sp)
40233a4c  move      $s5, $a3
40233a50  move      $s3, $a2
40233a54  slti      $t0, $a1, 0x19
40233a58  bnez      $t0, 0x40233a6c
40233a5c  move      $s0, $a0
40233a60  lui       $t1, 0x4023
40233a64  b         0x40233a90
40233a68  addiu     $a0, $t1, 0x1b7c
40233a6c  lui       $t0, 0x4024
40233a70  addiu     $t0, $t0, -0x7ec4
40233a74  sll       $t1, $a1, 5
40233a78  addu      $s1, $t1, $t0
40233a7c  lw        $t0, ($s1)
40233a80  bnez      $t0, 0x40233aa0
40233a84  nop       
40233a88  lui       $t2, 0x4023
40233a8c  addiu     $a0, $t2, 0x1af8
40233a90  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
40233a94  nop       
40233a98  b         0x40233c70
40233a9c  move      $s3, $zero
40233aa0  sw        $s1, 0x18($s0)
40233aa4  sw        $s3, 0x10($s0)
40233aa8  lw        $t0, 0x1c($s1)
40233aac  addiu     $s2, $s0, 0x30
40233ab0  sw        $a1, 0x20($s0)
40233ab4  sll       $a0, $s3, 1
40233ab8  addiu     $a3, $zero, 0
40233abc  addiu     $a2, $zero, 0x20
40233ac0  addiu     $a1, $zero, 0x204
40233ac4  sw        $t0, 0x60($s0)
40233ac8  sw        $zero, ($s2)
40233acc  sw        $zero, 4($s2)
40233ad0  sw        $zero, 0x38($s0)
40233ad4  sw        $zero, 0x3c($s0)
40233ad8  jal       0x40236a28 ; import thunk COREDLL.dll!AllocPhysMem@1486
40233adc  sw        $s2, 0x10($sp)
40233ae0  lw        $t1, ($s2)
40233ae4  addiu     $s4, $s0, 0x48
40233ae8  addu      $t0, $v0, $s3
40233aec  addu      $t2, $t1, $s3
40233af0  addiu     $a3, $zero, 0
40233af4  addiu     $a2, $zero, 0x20
40233af8  addiu     $a1, $zero, 0x204
40233afc  addiu     $a0, $zero, 0x80
40233b00  sw        $v0, 0x28($s0)
40233b04  sw        $t0, 0x2c($s0)
40233b08  sw        $t2, 0x38($s0)
40233b0c  sw        $zero, ($s4)
40233b10  sw        $zero, 4($s4)
40233b14  sw        $zero, 0x50($s0)
40233b18  sw        $zero, 0x54($s0)
40233b1c  jal       0x40236a28 ; import thunk COREDLL.dll!AllocPhysMem@1486
40233b20  sw        $s4, 0x10($sp)
40233b24  lw        $t1, ($s4)
40233b28  addiu     $t0, $v0, 0x40
40233b2c  addiu     $t2, $t1, 0x40
40233b30  sw        $v0, 0x40($s0)
40233b34  sw        $t0, 0x44($s0)
40233b38  sw        $t2, 0x50($s0)
40233b3c  lw        $t3, 8($s1)
40233b40  beqz      $s5, 0x40233b50
40233b44  addiu     $s3, $zero, 1
40233b48  sw        $s3, 0x1c($s0)
40233b4c  ori       $t3, $t3, 0x100
40233b50  lw        $t0, 0x18($s1)
40233b54  lw        $a1, 0x14($s1)
40233b58  beqz      $t0, 0x40233b94
40233b5c  ori       $s5, $t3, 4
40233b60  jal       0x40232be8
40233b64  addiu     $a0, $v0, 8
40233b68  lw        $a0, 0x44($s0)
40233b6c  lw        $a1, 0x14($s1)
40233b70  jal       0x40232be8
40233b74  addiu     $a0, $a0, 8
40233b78  lw        $a0, 0x40($s0)
40233b7c  lw        $a1, ($s2)
40233b80  jal       0x40232be8
40233b84  addiu     $a0, $a0, 0x10
40233b88  lw        $a0, 0x44($s0)
40233b8c  b         0x40233bc4
40233b90  addiu     $a0, $a0, 0x10
40233b94  jal       0x40232be8
40233b98  addiu     $a0, $v0, 0x10
40233b9c  lw        $a0, 0x44($s0)
40233ba0  lw        $a1, 0x14($s1)
40233ba4  jal       0x40232be8
40233ba8  addiu     $a0, $a0, 0x10
40233bac  lw        $a0, 0x40($s0)
40233bb0  lw        $a1, ($s2)
40233bb4  jal       0x40232be8
40233bb8  addiu     $a0, $a0, 8
40233bbc  lw        $a0, 0x44($s0)
40233bc0  addiu     $a0, $a0, 8
40233bc4  jal       0x40232be8
40233bc8  lw        $a1, 0x38($s0)
40233bcc  lw        $t0, 0x40($s0)
40233bd0  lw        $a1, 0xc($s1)
40233bd4  jal       0x40232be8
40233bd8  addiu     $a0, $t0, 0xc
40233bdc  lw        $a0, 0x44($s0)
40233be0  lw        $a1, 0xc($s1)
40233be4  jal       0x40232be8
40233be8  addiu     $a0, $a0, 0xc
40233bec  lw        $t0, 0x40($s0)
40233bf0  lw        $a1, 0x10($s1)
40233bf4  jal       0x40232be8
40233bf8  addiu     $a0, $t0, 0x14
40233bfc  lw        $a0, 0x44($s0)
40233c00  lw        $a1, 0x10($s1)
40233c04  jal       0x40232be8
40233c08  addiu     $a0, $a0, 0x14
40233c0c  lw        $a0, 0x40($s0)
40233c10  jal       0x40232be8
40233c14  move      $a1, $s5
40233c18  lw        $a0, 0x44($s0)
40233c1c  jal       0x40232be8
40233c20  move      $a1, $s5
40233c24  lw        $a0, 0x50($s0)
40233c28  lw        $t0, 0x40($s0)
40233c2c  srl       $a1, $a0, 5
40233c30  jal       0x40232be8
40233c34  addiu     $a0, $t0, 0x1c
40233c38  lw        $a0, ($s4)
40233c3c  lw        $t0, 0x44($s0)
40233c40  srl       $a1, $a0, 5
40233c44  jal       0x40232be8
40233c48  addiu     $a0, $t0, 0x1c
40233c4c  lw        $a1, 4($s1)
40233c50  jal       0x40232be8
40233c54  lw        $a0, 0x24($s0)
40233c58  lw        $a0, 0x24($s0)
40233c5c  lw        $a1, ($s4)
40233c60  jal       0x40232be8
40233c64  addiu     $a0, $a0, 4
40233c68  lw        $a0, ($s4)
40233c6c  sw        $a0, 0x84($s0)
40233c70  move      $v0, $s3
40233c74  lw        $s5, 0x18($sp)
40233c78  lw        $s4, 0x1c($sp)
40233c7c  lw        $s3, 0x20($sp)
40233c80  lw        $s2, 0x24($sp)
40233c84  lw        $s1, 0x28($sp)
40233c88  lw        $s0, 0x2c($sp)
40233c8c  lw        $ra, 0x30($sp)
40233c90  jr        $ra
40233c94  addiu     $sp, $sp, 0x38
40233c98  addiu     $sp, $sp, -0x20
40233c9c  sw        $ra, 0x18($sp)
40233ca0  sw        $s1, 0x10($sp)
40233ca4  sw        $s0, 0x14($sp)
40233ca8  move      $s0, $a0
40233cac  lui       $t0, 0x4023
40233cb0  lw        $t3, 0x60($s0)
40233cb4  addiu     $t0, $t0, 0x1618 ; string candidate 'UART0 TX'
40233cb8  beq       $t3, $t0, 0x40233cf8
40233cbc  nop       
40233cc0  lui       $t1, 0x4023
40233cc4  addiu     $t1, $t1, 0x1604 ; string candidate 'UART0 RX'
40233cc8  beq       $t3, $t1, 0x40233cf8
40233ccc  nop       
40233cd0  lui       $t2, 0x4023
40233cd4  addiu     $t2, $t2, 0x1c64 ; string candidate 'SPI TX'
40233cd8  beq       $t3, $t2, 0x40233cf8
40233cdc  nop       
40233ce0  lui       $t0, 0x4023
40233ce4  addiu     $t0, $t0, 0x1c54 ; string candidate 'SPI RX'
40233ce8  beq       $t3, $t0, 0x40233cf8
40233cec  nop       
40233cf0  b         0x40233d04
40233cf4  lw        $v0, 0x84($s0)
40233cf8  lw        $t0, 0x24($s0)
40233cfc  jal       0x40232bbc
40233d00  addiu     $a0, $t0, 4
40233d04  lw        $t0, 0x48($s0)
40233d08  bne       $v0, $t0, 0x40233d98
40233d0c  nop       
40233d10  lw        $t1, 0x24($s0)
40233d14  jal       0x40232bbc
40233d18  addiu     $a0, $t1, 0x14
40233d1c  andi      $a0, $v0, 1
40233d20  beqz      $a0, 0x40233d48
40233d24  nop       
40233d28  jal       0x40232bbc
40233d2c  lw        $a0, 0x40($s0)
40233d30  lui       $a0, 0x8000
40233d34  and       $t0, $v0, $a0
40233d38  bnez      $t0, 0x40233e24
40233d3c  nop       
40233d40  b         0x40233e4c
40233d44  nop       
40233d48  lw        $t1, 0x18($s0)
40233d4c  lw        $t0, 0x18($t1)
40233d50  beqz      $t0, 0x40233d6c
40233d54  lui       $s1, 0x8000
40233d58  jal       0x40232bbc
40233d5c  lw        $a0, 0x44($s0)
40233d60  and       $a0, $v0, $s1
40233d64  beqz      $a0, 0x40233e24
40233d68  nop       
40233d6c  lw        $t0, 0x18($s0)
40233d70  lw        $t1, 0x18($t0)
40233d74  bnez      $t1, 0x40233e4c
40233d78  nop       
40233d7c  jal       0x40232bbc
40233d80  lw        $a0, 0x40($s0)
40233d84  and       $a0, $v0, $s1
40233d88  bnez      $a0, 0x40233e24
40233d8c  nop       
40233d90  b         0x40233e4c
40233d94  nop       
40233d98  lw        $t0, 0x50($s0)
40233d9c  bne       $v0, $t0, 0x40233e30
40233da0  nop       
40233da4  lw        $t1, 0x24($s0)
40233da8  jal       0x40232bbc
40233dac  addiu     $a0, $t1, 0x14
40233db0  andi      $a0, $v0, 1
40233db4  beqz      $a0, 0x40233ddc
40233db8  nop       
40233dbc  jal       0x40232bbc
40233dc0  lw        $a0, 0x44($s0)
40233dc4  lui       $a0, 0x8000
40233dc8  and       $t0, $v0, $a0
40233dcc  bnez      $t0, 0x40233e4c
40233dd0  nop       
40233dd4  b         0x40233e24
40233dd8  nop       
40233ddc  lw        $t1, 0x18($s0)
40233de0  lw        $t0, 0x18($t1)
40233de4  beqz      $t0, 0x40233e00
40233de8  lui       $s1, 0x8000
40233dec  jal       0x40232bbc
40233df0  lw        $a0, 0x40($s0)
40233df4  and       $a0, $v0, $s1
40233df8  beqz      $a0, 0x40233e4c
40233dfc  nop       
40233e00  lw        $t0, 0x18($s0)
40233e04  lw        $t1, 0x18($t0)
40233e08  bnez      $t1, 0x40233e24
40233e0c  nop       
40233e10  jal       0x40232bbc
40233e14  lw        $a0, 0x44($s0)
40233e18  and       $a0, $v0, $s1
40233e1c  bnez      $a0, 0x40233e4c
40233e20  nop       
40233e24  lw        $v0, 0x2c($s0)
40233e28  b         0x40233e54
40233e2c  sw        $zero, 0x5c($s0)
40233e30  lui       $t0, 0x4023
40233e34  lw        $a1, 0x60($s0)
40233e38  move      $a2, $v0
40233e3c  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
40233e40  addiu     $a0, $t0, 0x1bdc
40233e44  jal       0x40233994
40233e48  move      $a0, $s0
40233e4c  lw        $v0, 0x28($s0)
40233e50  sw        $zero, 0x58($s0)
40233e54  lw        $s1, 0x10($sp)
40233e58  lw        $s0, 0x14($sp)
40233e5c  lw        $ra, 0x18($sp)
40233e60  jr        $ra
40233e64  addiu     $sp, $sp, 0x20
40233e68  addiu     $sp, $sp, -0x20
40233e6c  sw        $ra, 0x1c($sp)
40233e70  sw        $s2, 0x10($sp)
40233e74  sw        $s1, 0x14($sp)
40233e78  sw        $s0, 0x18($sp)
40233e7c  move      $s0, $a0
40233e80  lw        $t0, 0x28($s0)
40233e84  bne       $a1, $t0, 0x40233e9c
40233e88  nop       
40233e8c  addiu     $s1, $zero, 1
40233e90  lw        $s2, 0x40($s0)
40233e94  b         0x40233eb4
40233e98  sw        $s1, 0x58($s0)
40233e9c  lw        $t0, 0x2c($s0)
40233ea0  bne       $a1, $t0, 0x40233ef0
40233ea4  nop       
40233ea8  addiu     $s1, $zero, 1
40233eac  lw        $s2, 0x44($s0)
40233eb0  sw        $s1, 0x5c($s0)
40233eb4  addiu     $a0, $s2, 4
40233eb8  jal       0x40232be8
40233ebc  move      $a1, $a2
40233ec0  jal       0x40232bbc
40233ec4  move      $a0, $s2
40233ec8  lui       $a0, 0x8000
40233ecc  or        $a1, $v0, $a0
40233ed0  jal       0x40232be8
40233ed4  move      $a0, $s2
40233ed8  lw        $a0, 0x24($s0)
40233edc  addiu     $a0, $a0, 0xc
40233ee0  jal       0x40232be8
40233ee4  addiu     $a1, $zero, 1
40233ee8  b         0x40233f08
40233eec  nop       
40233ef0  move      $a2, $a1
40233ef4  lui       $t0, 0x4023
40233ef8  lw        $a1, 0x60($s0)
40233efc  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
40233f00  addiu     $a0, $t0, 0x1c74
40233f04  move      $s1, $zero
40233f08  move      $v0, $s1
40233f0c  lw        $s2, 0x10($sp)
40233f10  lw        $s1, 0x14($sp)
40233f14  lw        $s0, 0x18($sp)
40233f18  lw        $ra, 0x1c($sp)
40233f1c  jr        $ra
40233f20  addiu     $sp, $sp, 0x20
40233f24  addiu     $sp, $sp, -0x18
40233f28  sw        $ra, 0x14($sp)
40233f2c  sw        $s0, 0x10($sp)
40233f30  move      $s0, $a0
40233f34  lw        $t0, 0x24($s0)
40233f38  addiu     $a0, $t0, 0x10
40233f3c  jal       0x40232be8
40233f40  addiu     $a1, $zero, 0
40233f44  jal       0x40232bbc
40233f48  lw        $a0, 0x24($s0)
40233f4c  lw        $a0, 0x24($s0)
40233f50  jal       0x40232be8
40233f54  ori       $a1, $v0, 1
40233f58  jal       0x40236a48 ; import thunk COREDLL.dll!CacheSync@577
40233f5c  addiu     $a0, $zero, 4
40233f60  lw        $a0, 0x24($s0)
40233f64  addiu     $a0, $a0, 0xc
40233f68  jal       0x40232be8
40233f6c  addiu     $a1, $zero, 1
40233f70  lw        $s0, 0x10($sp)
40233f74  lw        $ra, 0x14($sp)
40233f78  addiu     $v0, $zero, 1
40233f7c  jr        $ra
40233f80  addiu     $sp, $sp, 0x18
40233f84  addiu     $sp, $sp, -0x20
40233f88  sw        $ra, 0x18($sp)
40233f8c  sw        $s1, 0x10($sp)
40233f90  sw        $s0, 0x14($sp)
40233f94  move      $s0, $a0
40233f98  jal       0x40232bbc
40233f9c  lw        $a0, 0x24($s0)
40233fa0  lui       $a0, 0xffff
40233fa4  ori       $a0, $a0, 0xfffe
40233fa8  and       $a1, $v0, $a0
40233fac  jal       0x40232be8
40233fb0  lw        $a0, 0x24($s0)
40233fb4  lw        $t0, 0x24($s0)
40233fb8  jal       0x40232bbc
40233fbc  addiu     $a0, $t0, 0x14
40233fc0  beqz      $v0, 0x40233fcc
40233fc4  addiu     $t0, $zero, 1
40233fc8  move      $t0, $zero
40233fcc  andi      $t0, $t0, 1
40233fd0  bnez      $t0, 0x40233fb4
40233fd4  nop       
40233fd8  jal       0x40232bbc
40233fdc  lw        $a0, 0x40($s0)
40233fe0  lui       $s1, 0x7fff
40233fe4  lw        $a0, 0x40($s0)
40233fe8  ori       $s1, $s1, 0xffff
40233fec  jal       0x40232be8
40233ff0  and       $a1, $v0, $s1
40233ff4  lw        $a0, 0x44($s0)
40233ff8  jal       0x40232bbc
40233ffc  sw        $zero, 0x58($s0)
40234000  lw        $a0, 0x44($s0)
40234004  jal       0x40232be8
40234008  and       $a1, $v0, $s1
4023400c  lw        $t0, 0x24($s0)
40234010  addiu     $a0, $t0, 0x14
40234014  addiu     $a1, $zero, 6
40234018  jal       0x40232be8
4023401c  sw        $zero, 0x5c($s0)
40234020  lw        $a0, 0x24($s0)
40234024  addiu     $a0, $a0, 0x10
40234028  jal       0x40232be8
4023402c  addiu     $a1, $zero, 0
40234030  lw        $a0, 0x24($s0)
40234034  jal       0x40232bbc
40234038  addiu     $a0, $a0, 4
4023403c  sw        $v0, 0x84($s0)
40234040  lw        $s1, 0x10($sp)
40234044  lw        $s0, 0x14($sp)
40234048  lw        $ra, 0x18($sp)
4023404c  addiu     $v0, $zero, 1
40234050  jr        $ra
40234054  addiu     $sp, $sp, 0x20
; k.ceddk.dll ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff
c0423994  addiu     $sp, $sp, -0x18
c0423998  sw        $ra, 0x14($sp)
c042399c  sw        $s0, 0x10($sp)
c04239a0  move      $s0, $a0
c04239a4  lui       $t0, 0xc042
c04239a8  lw        $a1, 0xc($s0)
c04239ac  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c04239b0  addiu     $a0, $t0, 0x1aa8
c04239b4  lui       $t0, 0xc042
c04239b8  lw        $a2, 0x48($s0)
c04239bc  lw        $a1, 0x40($s0)
c04239c0  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c04239c4  addiu     $a0, $t0, 0x1a68
c04239c8  lui       $t0, 0xc042
c04239cc  lw        $a2, 0x50($s0)
c04239d0  lw        $a1, 0x44($s0)
c04239d4  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c04239d8  addiu     $a0, $t0, 0x1a28
c04239dc  lui       $t0, 0xc042
c04239e0  lw        $a2, 0x30($s0)
c04239e4  lw        $a1, 0x28($s0)
c04239e8  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c04239ec  addiu     $a0, $t0, 0x19e8
c04239f0  lui       $t0, 0xc042
c04239f4  lw        $a2, 0x38($s0)
c04239f8  lw        $a1, 0x2c($s0)
c04239fc  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0423a00  addiu     $a0, $t0, 0x19a8
c0423a04  jal       0xc04238f8
c0423a08  lw        $a0, 0x24($s0)
c0423a0c  jal       0xc0423834
c0423a10  lw        $a0, 0x40($s0)
c0423a14  jal       0xc0423834
c0423a18  lw        $a0, 0x44($s0)
c0423a1c  lw        $s0, 0x10($sp)
c0423a20  lw        $ra, 0x14($sp)
c0423a24  jr        $ra
c0423a28  addiu     $sp, $sp, 0x18
c0423a2c  addiu     $sp, $sp, -0x38
c0423a30  sw        $ra, 0x30($sp)
c0423a34  sw        $s5, 0x18($sp)
c0423a38  sw        $s4, 0x1c($sp)
c0423a3c  sw        $s3, 0x20($sp)
c0423a40  sw        $s2, 0x24($sp)
c0423a44  sw        $s1, 0x28($sp)
c0423a48  sw        $s0, 0x2c($sp)
c0423a4c  move      $s5, $a3
c0423a50  move      $s3, $a2
c0423a54  slti      $t0, $a1, 0x19
c0423a58  bnez      $t0, 0xc0423a6c
c0423a5c  move      $s0, $a0
c0423a60  lui       $t1, 0xc042
c0423a64  b         0xc0423a90
c0423a68  addiu     $a0, $t1, 0x1b7c
c0423a6c  lui       $t0, 0xc043
c0423a70  addiu     $t0, $t0, -0x7ec4
c0423a74  sll       $t1, $a1, 5
c0423a78  addu      $s1, $t1, $t0
c0423a7c  lw        $t0, ($s1)
c0423a80  bnez      $t0, 0xc0423aa0
c0423a84  nop       
c0423a88  lui       $t2, 0xc042
c0423a8c  addiu     $a0, $t2, 0x1af8
c0423a90  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0423a94  nop       
c0423a98  b         0xc0423c70
c0423a9c  move      $s3, $zero
c0423aa0  sw        $s1, 0x18($s0)
c0423aa4  sw        $s3, 0x10($s0)
c0423aa8  lw        $t0, 0x1c($s1)
c0423aac  addiu     $s2, $s0, 0x30
c0423ab0  sw        $a1, 0x20($s0)
c0423ab4  sll       $a0, $s3, 1
c0423ab8  addiu     $a3, $zero, 0
c0423abc  addiu     $a2, $zero, 0x20
c0423ac0  addiu     $a1, $zero, 0x204
c0423ac4  sw        $t0, 0x60($s0)
c0423ac8  sw        $zero, ($s2)
c0423acc  sw        $zero, 4($s2)
c0423ad0  sw        $zero, 0x38($s0)
c0423ad4  sw        $zero, 0x3c($s0)
c0423ad8  jal       0xc0426a28 ; import thunk COREDLL.dll!AllocPhysMem@1486
c0423adc  sw        $s2, 0x10($sp)
c0423ae0  lw        $t1, ($s2)
c0423ae4  addiu     $s4, $s0, 0x48
c0423ae8  addu      $t0, $v0, $s3
c0423aec  addu      $t2, $t1, $s3
c0423af0  addiu     $a3, $zero, 0
c0423af4  addiu     $a2, $zero, 0x20
c0423af8  addiu     $a1, $zero, 0x204
c0423afc  addiu     $a0, $zero, 0x80
c0423b00  sw        $v0, 0x28($s0)
c0423b04  sw        $t0, 0x2c($s0)
c0423b08  sw        $t2, 0x38($s0)
c0423b0c  sw        $zero, ($s4)
c0423b10  sw        $zero, 4($s4)
c0423b14  sw        $zero, 0x50($s0)
c0423b18  sw        $zero, 0x54($s0)
c0423b1c  jal       0xc0426a28 ; import thunk COREDLL.dll!AllocPhysMem@1486
c0423b20  sw        $s4, 0x10($sp)
c0423b24  lw        $t1, ($s4)
c0423b28  addiu     $t0, $v0, 0x40
c0423b2c  addiu     $t2, $t1, 0x40
c0423b30  sw        $v0, 0x40($s0)
c0423b34  sw        $t0, 0x44($s0)
c0423b38  sw        $t2, 0x50($s0)
c0423b3c  lw        $t3, 8($s1)
c0423b40  beqz      $s5, 0xc0423b50
c0423b44  addiu     $s3, $zero, 1
c0423b48  sw        $s3, 0x1c($s0)
c0423b4c  ori       $t3, $t3, 0x100
c0423b50  lw        $t0, 0x18($s1)
c0423b54  lw        $a1, 0x14($s1)
c0423b58  beqz      $t0, 0xc0423b94
c0423b5c  ori       $s5, $t3, 4
c0423b60  jal       0xc0422be8
c0423b64  addiu     $a0, $v0, 8
c0423b68  lw        $a0, 0x44($s0)
c0423b6c  lw        $a1, 0x14($s1)
c0423b70  jal       0xc0422be8
c0423b74  addiu     $a0, $a0, 8
c0423b78  lw        $a0, 0x40($s0)
c0423b7c  lw        $a1, ($s2)
c0423b80  jal       0xc0422be8
c0423b84  addiu     $a0, $a0, 0x10
c0423b88  lw        $a0, 0x44($s0)
c0423b8c  b         0xc0423bc4
c0423b90  addiu     $a0, $a0, 0x10
c0423b94  jal       0xc0422be8
c0423b98  addiu     $a0, $v0, 0x10
c0423b9c  lw        $a0, 0x44($s0)
c0423ba0  lw        $a1, 0x14($s1)
c0423ba4  jal       0xc0422be8
c0423ba8  addiu     $a0, $a0, 0x10
c0423bac  lw        $a0, 0x40($s0)
c0423bb0  lw        $a1, ($s2)
c0423bb4  jal       0xc0422be8
c0423bb8  addiu     $a0, $a0, 8
c0423bbc  lw        $a0, 0x44($s0)
c0423bc0  addiu     $a0, $a0, 8
c0423bc4  jal       0xc0422be8
c0423bc8  lw        $a1, 0x38($s0)
c0423bcc  lw        $t0, 0x40($s0)
c0423bd0  lw        $a1, 0xc($s1)
c0423bd4  jal       0xc0422be8
c0423bd8  addiu     $a0, $t0, 0xc
c0423bdc  lw        $a0, 0x44($s0)
c0423be0  lw        $a1, 0xc($s1)
c0423be4  jal       0xc0422be8
c0423be8  addiu     $a0, $a0, 0xc
c0423bec  lw        $t0, 0x40($s0)
c0423bf0  lw        $a1, 0x10($s1)
c0423bf4  jal       0xc0422be8
c0423bf8  addiu     $a0, $t0, 0x14
c0423bfc  lw        $a0, 0x44($s0)
c0423c00  lw        $a1, 0x10($s1)
c0423c04  jal       0xc0422be8
c0423c08  addiu     $a0, $a0, 0x14
c0423c0c  lw        $a0, 0x40($s0)
c0423c10  jal       0xc0422be8
c0423c14  move      $a1, $s5
c0423c18  lw        $a0, 0x44($s0)
c0423c1c  jal       0xc0422be8
c0423c20  move      $a1, $s5
c0423c24  lw        $a0, 0x50($s0)
c0423c28  lw        $t0, 0x40($s0)
c0423c2c  srl       $a1, $a0, 5
c0423c30  jal       0xc0422be8
c0423c34  addiu     $a0, $t0, 0x1c
c0423c38  lw        $a0, ($s4)
c0423c3c  lw        $t0, 0x44($s0)
c0423c40  srl       $a1, $a0, 5
c0423c44  jal       0xc0422be8
c0423c48  addiu     $a0, $t0, 0x1c
c0423c4c  lw        $a1, 4($s1)
c0423c50  jal       0xc0422be8
c0423c54  lw        $a0, 0x24($s0)
c0423c58  lw        $a0, 0x24($s0)
c0423c5c  lw        $a1, ($s4)
c0423c60  jal       0xc0422be8
c0423c64  addiu     $a0, $a0, 4
c0423c68  lw        $a0, ($s4)
c0423c6c  sw        $a0, 0x84($s0)
c0423c70  move      $v0, $s3
c0423c74  lw        $s5, 0x18($sp)
c0423c78  lw        $s4, 0x1c($sp)
c0423c7c  lw        $s3, 0x20($sp)
c0423c80  lw        $s2, 0x24($sp)
c0423c84  lw        $s1, 0x28($sp)
c0423c88  lw        $s0, 0x2c($sp)
c0423c8c  lw        $ra, 0x30($sp)
c0423c90  jr        $ra
c0423c94  addiu     $sp, $sp, 0x38
c0423c98  addiu     $sp, $sp, -0x20
c0423c9c  sw        $ra, 0x18($sp)
c0423ca0  sw        $s1, 0x10($sp)
c0423ca4  sw        $s0, 0x14($sp)
c0423ca8  move      $s0, $a0
c0423cac  lui       $t0, 0xc042
c0423cb0  lw        $t3, 0x60($s0)
c0423cb4  addiu     $t0, $t0, 0x1618 ; string candidate 'UART0 TX'
c0423cb8  beq       $t3, $t0, 0xc0423cf8
c0423cbc  nop       
c0423cc0  lui       $t1, 0xc042
c0423cc4  addiu     $t1, $t1, 0x1604 ; string candidate 'UART0 RX'
c0423cc8  beq       $t3, $t1, 0xc0423cf8
c0423ccc  nop       
c0423cd0  lui       $t2, 0xc042
c0423cd4  addiu     $t2, $t2, 0x1c64 ; string candidate 'SPI TX'
c0423cd8  beq       $t3, $t2, 0xc0423cf8
c0423cdc  nop       
c0423ce0  lui       $t0, 0xc042
c0423ce4  addiu     $t0, $t0, 0x1c54 ; string candidate 'SPI RX'
c0423ce8  beq       $t3, $t0, 0xc0423cf8
c0423cec  nop       
c0423cf0  b         0xc0423d04
c0423cf4  lw        $v0, 0x84($s0)
c0423cf8  lw        $t0, 0x24($s0)
c0423cfc  jal       0xc0422bbc
c0423d00  addiu     $a0, $t0, 4
c0423d04  lw        $t0, 0x48($s0)
c0423d08  bne       $v0, $t0, 0xc0423d98
c0423d0c  nop       
c0423d10  lw        $t1, 0x24($s0)
c0423d14  jal       0xc0422bbc
c0423d18  addiu     $a0, $t1, 0x14
c0423d1c  andi      $a0, $v0, 1
c0423d20  beqz      $a0, 0xc0423d48
c0423d24  nop       
c0423d28  jal       0xc0422bbc
c0423d2c  lw        $a0, 0x40($s0)
c0423d30  lui       $a0, 0x8000
c0423d34  and       $t0, $v0, $a0
c0423d38  bnez      $t0, 0xc0423e24
c0423d3c  nop       
c0423d40  b         0xc0423e4c
c0423d44  nop       
c0423d48  lw        $t1, 0x18($s0)
c0423d4c  lw        $t0, 0x18($t1)
c0423d50  beqz      $t0, 0xc0423d6c
c0423d54  lui       $s1, 0x8000
c0423d58  jal       0xc0422bbc
c0423d5c  lw        $a0, 0x44($s0)
c0423d60  and       $a0, $v0, $s1
c0423d64  beqz      $a0, 0xc0423e24
c0423d68  nop       
c0423d6c  lw        $t0, 0x18($s0)
c0423d70  lw        $t1, 0x18($t0)
c0423d74  bnez      $t1, 0xc0423e4c
c0423d78  nop       
c0423d7c  jal       0xc0422bbc
c0423d80  lw        $a0, 0x40($s0)
c0423d84  and       $a0, $v0, $s1
c0423d88  bnez      $a0, 0xc0423e24
c0423d8c  nop       
c0423d90  b         0xc0423e4c
c0423d94  nop       
c0423d98  lw        $t0, 0x50($s0)
c0423d9c  bne       $v0, $t0, 0xc0423e30
c0423da0  nop       
c0423da4  lw        $t1, 0x24($s0)
c0423da8  jal       0xc0422bbc
c0423dac  addiu     $a0, $t1, 0x14
c0423db0  andi      $a0, $v0, 1
c0423db4  beqz      $a0, 0xc0423ddc
c0423db8  nop       
c0423dbc  jal       0xc0422bbc
c0423dc0  lw        $a0, 0x44($s0)
c0423dc4  lui       $a0, 0x8000
c0423dc8  and       $t0, $v0, $a0
c0423dcc  bnez      $t0, 0xc0423e4c
c0423dd0  nop       
c0423dd4  b         0xc0423e24
c0423dd8  nop       
c0423ddc  lw        $t1, 0x18($s0)
c0423de0  lw        $t0, 0x18($t1)
c0423de4  beqz      $t0, 0xc0423e00
c0423de8  lui       $s1, 0x8000
c0423dec  jal       0xc0422bbc
c0423df0  lw        $a0, 0x40($s0)
c0423df4  and       $a0, $v0, $s1
c0423df8  beqz      $a0, 0xc0423e4c
c0423dfc  nop       
c0423e00  lw        $t0, 0x18($s0)
c0423e04  lw        $t1, 0x18($t0)
c0423e08  bnez      $t1, 0xc0423e24
c0423e0c  nop       
c0423e10  jal       0xc0422bbc
c0423e14  lw        $a0, 0x44($s0)
c0423e18  and       $a0, $v0, $s1
c0423e1c  bnez      $a0, 0xc0423e4c
c0423e20  nop       
c0423e24  lw        $v0, 0x2c($s0)
c0423e28  b         0xc0423e54
c0423e2c  sw        $zero, 0x5c($s0)
c0423e30  lui       $t0, 0xc042
c0423e34  lw        $a1, 0x60($s0)
c0423e38  move      $a2, $v0
c0423e3c  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0423e40  addiu     $a0, $t0, 0x1bdc
c0423e44  jal       0xc0423994
c0423e48  move      $a0, $s0
c0423e4c  lw        $v0, 0x28($s0)
c0423e50  sw        $zero, 0x58($s0)
c0423e54  lw        $s1, 0x10($sp)
c0423e58  lw        $s0, 0x14($sp)
c0423e5c  lw        $ra, 0x18($sp)
c0423e60  jr        $ra
c0423e64  addiu     $sp, $sp, 0x20
c0423e68  addiu     $sp, $sp, -0x20
c0423e6c  sw        $ra, 0x1c($sp)
c0423e70  sw        $s2, 0x10($sp)
c0423e74  sw        $s1, 0x14($sp)
c0423e78  sw        $s0, 0x18($sp)
c0423e7c  move      $s0, $a0
c0423e80  lw        $t0, 0x28($s0)
c0423e84  bne       $a1, $t0, 0xc0423e9c
c0423e88  nop       
c0423e8c  addiu     $s1, $zero, 1
c0423e90  lw        $s2, 0x40($s0)
c0423e94  b         0xc0423eb4
c0423e98  sw        $s1, 0x58($s0)
c0423e9c  lw        $t0, 0x2c($s0)
c0423ea0  bne       $a1, $t0, 0xc0423ef0
c0423ea4  nop       
c0423ea8  addiu     $s1, $zero, 1
c0423eac  lw        $s2, 0x44($s0)
c0423eb0  sw        $s1, 0x5c($s0)
c0423eb4  addiu     $a0, $s2, 4
c0423eb8  jal       0xc0422be8
c0423ebc  move      $a1, $a2
c0423ec0  jal       0xc0422bbc
c0423ec4  move      $a0, $s2
c0423ec8  lui       $a0, 0x8000
c0423ecc  or        $a1, $v0, $a0
c0423ed0  jal       0xc0422be8
c0423ed4  move      $a0, $s2
c0423ed8  lw        $a0, 0x24($s0)
c0423edc  addiu     $a0, $a0, 0xc
c0423ee0  jal       0xc0422be8
c0423ee4  addiu     $a1, $zero, 1
c0423ee8  b         0xc0423f08
c0423eec  nop       
c0423ef0  move      $a2, $a1
c0423ef4  lui       $t0, 0xc042
c0423ef8  lw        $a1, 0x60($s0)
c0423efc  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0423f00  addiu     $a0, $t0, 0x1c74
c0423f04  move      $s1, $zero
c0423f08  move      $v0, $s1
c0423f0c  lw        $s2, 0x10($sp)
c0423f10  lw        $s1, 0x14($sp)
c0423f14  lw        $s0, 0x18($sp)
c0423f18  lw        $ra, 0x1c($sp)
c0423f1c  jr        $ra
c0423f20  addiu     $sp, $sp, 0x20
c0423f24  addiu     $sp, $sp, -0x18
c0423f28  sw        $ra, 0x14($sp)
c0423f2c  sw        $s0, 0x10($sp)
c0423f30  move      $s0, $a0
c0423f34  lw        $t0, 0x24($s0)
c0423f38  addiu     $a0, $t0, 0x10
c0423f3c  jal       0xc0422be8
c0423f40  addiu     $a1, $zero, 0
c0423f44  jal       0xc0422bbc
c0423f48  lw        $a0, 0x24($s0)
c0423f4c  lw        $a0, 0x24($s0)
c0423f50  jal       0xc0422be8
c0423f54  ori       $a1, $v0, 1
c0423f58  jal       0xc0426a48 ; import thunk COREDLL.dll!CacheSync@577
c0423f5c  addiu     $a0, $zero, 4
c0423f60  lw        $a0, 0x24($s0)
c0423f64  addiu     $a0, $a0, 0xc
c0423f68  jal       0xc0422be8
c0423f6c  addiu     $a1, $zero, 1
c0423f70  lw        $s0, 0x10($sp)
c0423f74  lw        $ra, 0x14($sp)
c0423f78  addiu     $v0, $zero, 1
c0423f7c  jr        $ra
c0423f80  addiu     $sp, $sp, 0x18
c0423f84  addiu     $sp, $sp, -0x20
c0423f88  sw        $ra, 0x18($sp)
c0423f8c  sw        $s1, 0x10($sp)
c0423f90  sw        $s0, 0x14($sp)
c0423f94  move      $s0, $a0
c0423f98  jal       0xc0422bbc
c0423f9c  lw        $a0, 0x24($s0)
c0423fa0  lui       $a0, 0xffff
c0423fa4  ori       $a0, $a0, 0xfffe
c0423fa8  and       $a1, $v0, $a0
c0423fac  jal       0xc0422be8
c0423fb0  lw        $a0, 0x24($s0)
c0423fb4  lw        $t0, 0x24($s0)
c0423fb8  jal       0xc0422bbc
c0423fbc  addiu     $a0, $t0, 0x14
c0423fc0  beqz      $v0, 0xc0423fcc
c0423fc4  addiu     $t0, $zero, 1
c0423fc8  move      $t0, $zero
c0423fcc  andi      $t0, $t0, 1
c0423fd0  bnez      $t0, 0xc0423fb4
c0423fd4  nop       
c0423fd8  jal       0xc0422bbc
c0423fdc  lw        $a0, 0x40($s0)
c0423fe0  lui       $s1, 0x7fff
c0423fe4  lw        $a0, 0x40($s0)
c0423fe8  ori       $s1, $s1, 0xffff
c0423fec  jal       0xc0422be8
c0423ff0  and       $a1, $v0, $s1
c0423ff4  lw        $a0, 0x44($s0)
c0423ff8  jal       0xc0422bbc
c0423ffc  sw        $zero, 0x58($s0)
c0424000  lw        $a0, 0x44($s0)
c0424004  jal       0xc0422be8
c0424008  and       $a1, $v0, $s1
c042400c  lw        $t0, 0x24($s0)
c0424010  addiu     $a0, $t0, 0x14
c0424014  addiu     $a1, $zero, 6
c0424018  jal       0xc0422be8
c042401c  sw        $zero, 0x5c($s0)
c0424020  lw        $a0, 0x24($s0)
c0424024  addiu     $a0, $a0, 0x10
c0424028  jal       0xc0422be8
c042402c  addiu     $a1, $zero, 0
c0424030  lw        $a0, 0x24($s0)
c0424034  jal       0xc0422bbc
c0424038  addiu     $a0, $a0, 4
c042403c  sw        $v0, 0x84($s0)
c0424040  lw        $s1, 0x10($sp)
c0424044  lw        $s0, 0x14($sp)
c0424048  lw        $ra, 0x18($sp)
c042404c  addiu     $v0, $zero, 1
c0424050  jr        $ra
c0424054  addiu     $sp, $sp, 0x20
