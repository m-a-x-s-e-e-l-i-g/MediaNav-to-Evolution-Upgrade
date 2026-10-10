; ceddk.dll 9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731
4023326c  addiu     $sp, $sp, -0x18
40233270  sw        $ra, 0x14($sp)
40233274  sw        $s0, 0x10($sp)
40233278  lui       $t0, 0x4024
4023327c  addiu     $t3, $t0, -0x7f0c
40233280  move      $t4, $zero
40233284  move      $t2, $t3
40233288  addiu     $t2, $t2, 4
4023328c  addiu     $t0, $t3, 0x40
40233290  slt       $t1, $t2, $t0
40233294  bnez      $t1, 0x40233288
40233298  addiu     $t4, $t4, 1
4023329c  lui       $t0, 0x4024
402332a0  addiu     $s0, $t0, -0x7ec4
402332a4  lui       $t1, 0x4023
402332a8  addiu     $t7, $zero, 1
402332ac  sw        $t7, 0x80($s0)
402332b0  addiu     $t0, $t1, 0x16e4 ; string candidate 'AC97 TX'
402332b4  sw        $t0, 0x9c($s0)
402332b8  addiu     $t6, $zero, 8
402332bc  sw        $t6, 0x84($s0)
402332c0  sw        $zero, 0x8c($s0)
402332c4  lui       $t3, 0xe000
402332c8  sw        $t3, 0x90($s0)
402332cc  sw        $zero, 0x98($s0)
402332d0  sw        $t7, 0xa0($s0)
402332d4  lui       $t0, 0x4023
402332d8  addiu     $t0, $t0, 0x16d4 ; string candidate 'AC97 RX'
402332dc  sw        $t0, 0xbc($s0)
402332e0  sw        $t6, 0xa4($s0)
402332e4  sw        $t3, 0xac($s0)
402332e8  sw        $zero, 0xb0($s0)
402332ec  sw        $t7, 0xb8($s0)
402332f0  lui       $t1, 0x3f05
402332f4  lui       $t2, 0x10a0
402332f8  lui       $t0, 0x23f5
402332fc  ori       $t1, $t1, 0x1800
40233300  sw        $t1, 0x88($s0)
40233304  ori       $t2, $t2, 0x101c
40233308  sw        $t2, 0x94($s0)
4023330c  ori       $t0, $t0, 0x1800
40233310  sw        $t0, 0xa8($s0)
40233314  sw        $t2, 0xb4($s0)
40233318  sw        $t7, 0x180($s0)
4023331c  lui       $t0, 0x4023
40233320  addiu     $t0, $t0, 0x16c4 ; string candidate 'I2S TX'
40233324  sw        $t0, 0x19c($s0)
40233328  sw        $t6, 0x184($s0)
4023332c  sw        $zero, 0x18c($s0)
40233330  sw        $t3, 0x190($s0)
40233334  sw        $zero, 0x198($s0)
40233338  lui       $t2, 0x4023
4023333c  sw        $t7, 0x1a0($s0)
40233340  addiu     $t0, $t2, 0x16b4 ; string candidate 'I2S RX'
40233344  sw        $t0, 0x1bc($s0)
40233348  sw        $t6, 0x1a4($s0)
4023334c  sw        $t3, 0x1ac($s0)
40233350  lui       $t1, 0x3f25
40233354  sw        $zero, 0x1b0($s0)
40233358  lui       $t2, 0x10a0
4023335c  sw        $t7, 0x1b8($s0)
40233360  lui       $t0, 0x27f5
40233364  ori       $t1, $t1, 0x1800
40233368  sw        $t1, 0x188($s0)
4023336c  ori       $t2, $t2, 0x201c
40233370  sw        $t2, 0x194($s0)
40233374  ori       $t0, $t0, 0x1800
40233378  sw        $t0, 0x1a8($s0)
4023337c  sw        $t2, 0x1b4($s0)
40233380  lui       $t0, 0x4023
40233384  sw        $t7, 0x240($s0)
40233388  addiu     $t0, $t0, 0x16a4 ; string candidate 'I2S2 TX'
4023338c  sw        $t0, 0x25c($s0)
40233390  sw        $t6, 0x244($s0)
40233394  sw        $zero, 0x24c($s0)
40233398  lui       $t2, 0x4023
4023339c  sw        $t3, 0x250($s0)
402333a0  sw        $zero, 0x258($s0)
402333a4  addiu     $t0, $t2, 0x1694 ; string candidate 'I2S2 RX'
402333a8  sw        $t7, 0x260($s0)
402333ac  sw        $t0, 0x27c($s0)
402333b0  lui       $t1, 0x3ee5
402333b4  sw        $t6, 0x264($s0)
402333b8  lui       $t2, 0x10a0
402333bc  sw        $t3, 0x26c($s0)
402333c0  sw        $zero, 0x270($s0)
402333c4  ori       $t1, $t1, 0x1800
402333c8  lui       $a0, 0x1400
402333cc  sw        $t7, 0x278($s0)
402333d0  ori       $t2, $t2, 0x1c
402333d4  sw        $t1, 0x248($s0)
402333d8  ori       $a0, $a0, 0x2000
402333dc  sw        $t2, 0x254($s0)
402333e0  lui       $t0, 0x1ff5
402333e4  lui       $t1, 0x3e8a
402333e8  ori       $t0, $t0, 0x1800
402333ec  sw        $t0, 0x268($s0)
402333f0  sw        $t2, 0x274($s0)
402333f4  sw        $t7, 0x1c0($s0)
402333f8  lui       $t0, 0x4023
402333fc  addiu     $t0, $t0, 0x1680 ; string candidate 'SDIO0 TX'
40233400  sw        $t0, 0x1dc($s0)
40233404  sw        $t6, 0x1c4($s0)
40233408  ori       $t1, $t1, 0x1800
4023340c  sw        $t1, 0x1c8($s0)
40233410  lui       $t5, 0xc000
40233414  sw        $t5, 0x1cc($s0)
40233418  sw        $t3, 0x1d0($s0)
4023341c  lui       $t0, 0x1060
40233420  sw        $t0, 0x1d4($s0)
40233424  sw        $zero, 0x1d8($s0)
40233428  sw        $t7, 0x1e0($s0)
4023342c  lui       $t1, 0x4023
40233430  addiu     $t1, $t1, 0x166c ; string candidate 'SDIO0 RX'
40233434  sw        $t1, 0x1fc($s0)
40233438  sw        $t6, 0x1e4($s0)
4023343c  lui       $t0, 0x13fa
40233440  lui       $t1, 0x1060
40233444  ori       $t0, $t0, 0x1800
40233448  sw        $t0, 0x1e8($s0)
4023344c  sw        $t3, 0x1ec($s0)
40233450  sw        $t5, 0x1f0($s0)
40233454  ori       $t1, $t1, 4
40233458  sw        $t1, 0x1f4($s0)
4023345c  sw        $t7, 0x1f8($s0)
40233460  sw        $t7, 0x280($s0)
40233464  lui       $t0, 0x4023
40233468  addiu     $t0, $t0, 0x165c ; string candidate 'IDE TX'
4023346c  sw        $t0, 0x29c($s0)
40233470  lui       $t1, 0x3fda
40233474  addiu     $t3, $zero, 0x28
40233478  sw        $t3, 0x284($s0)
4023347c  ori       $t1, $t1, 0x1800
40233480  sw        $t1, 0x288($s0)
40233484  sw        $t5, 0x28c($s0)
40233488  lui       $t4, 0xf000
4023348c  sw        $t4, 0x290($s0)
40233490  lui       $t2, 0x1880
40233494  sw        $t2, 0x294($s0)
40233498  sw        $zero, 0x298($s0)
4023349c  lui       $t1, 0x4023
402334a0  sw        $t7, 0x2a0($s0)
402334a4  lui       $t0, 0x3bfa
402334a8  addiu     $t1, $t1, 0x164c ; string candidate 'IDE RX'
402334ac  sw        $t1, 0x2bc($s0)
402334b0  sw        $t3, 0x2a4($s0)
402334b4  ori       $t0, $t0, 0x1800
402334b8  sw        $t0, 0x2a8($s0)
402334bc  sw        $t4, 0x2ac($s0)
402334c0  sw        $t5, 0x2b0($s0)
402334c4  sw        $t2, 0x2b4($s0)
402334c8  lui       $t0, 0x4023
402334cc  sw        $t7, 0x2b8($s0)
402334d0  addiu     $t0, $t0, 0x163c ; string candidate 'NAND TX'
402334d4  sw        $t7, 0x2e0($s0)
402334d8  lui       $t1, 0x3f7a
402334dc  sw        $t0, 0x2fc($s0)
402334e0  ori       $t1, $t1, 0x1800
402334e4  sw        $t6, 0x2e4($s0)
402334e8  lui       $t0, 0x2000
402334ec  sw        $t1, 0x2e8($s0)
402334f0  sw        $t5, 0x2ec($s0)
402334f4  ori       $t0, $t0, 0x20
402334f8  sw        $t4, 0x2f0($s0)
402334fc  sw        $t0, 0x2f4($s0)
40233500  lui       $t1, 0x4023
40233504  lui       $t0, 0x2ffa
40233508  sw        $zero, 0x2f8($s0)
4023350c  addiu     $t1, $t1, 0x162c ; string candidate 'NAND RX'
40233510  sw        $t7, 0x300($s0)
40233514  sw        $t1, 0x31c($s0)
40233518  ori       $t0, $t0, 0x1800
4023351c  sw        $t6, 0x304($s0)
40233520  sw        $t0, 0x308($s0)
40233524  sw        $t4, 0x30c($s0)
40233528  sw        $t5, 0x310($s0)
4023352c  lui       $t4, 0x2000
40233530  addiu     $a3, $zero, 0
40233534  sw        $t4, 0x314($s0)
40233538  sw        $t7, 0x318($s0)
4023353c  lui       $t0, 0x4023
40233540  lui       $t1, 0x3e00
40233544  sw        $t7, ($s0)
40233548  addiu     $t0, $t0, 0x1618 ; string candidate 'UART0 TX'
4023354c  sw        $t0, 0x1c($s0)
40233550  sw        $t6, 4($s0)
40233554  ori       $t1, $t1, 0x1800
40233558  lui       $t2, 0x8000
4023355c  lui       $t3, 0x1010
40233560  sw        $t1, 8($s0)
40233564  lui       $t0, 0xa000
40233568  sw        $t2, 0xc($s0)
4023356c  sw        $t0, 0x10($s0)
40233570  ori       $t3, $t3, 4
40233574  sw        $t3, 0x14($s0)
40233578  lui       $t1, 0x4023
4023357c  sw        $zero, 0x18($s0)
40233580  lui       $t0, 0x3f0
40233584  addiu     $t1, $t1, 0x1604 ; string candidate 'UART0 RX'
40233588  sw        $t7, 0x20($s0)
4023358c  sw        $t1, 0x3c($s0)
40233590  ori       $t0, $t0, 0x1800
40233594  sw        $t6, 0x24($s0)
40233598  sw        $t0, 0x28($s0)
4023359c  lui       $t1, 0x1010
402335a0  sw        $t4, 0x2c($s0)
402335a4  sw        $zero, 0x30($s0)
402335a8  sw        $t1, 0x34($s0)
402335ac  addiu     $a2, $zero, 0x1010
402335b0  addiu     $a1, $zero, 0
402335b4  jal       0x40232360
402335b8  sw        $t7, 0x38($s0)
402335bc  addiu     $t0, $zero, 7
402335c0  sw        $v0, 0x320($s0)
402335c4  lw        $s0, 0x10($sp)
402335c8  lw        $ra, 0x14($sp)
402335cc  addiu     $sp, $sp, 0x18
402335d0  jr        $ra
402335d4  sw        $t0, 0x1000($v0)
402335d8  addiu     $sp, $sp, -0x30
402335dc  sw        $ra, 0x2c($sp)
402335e0  sw        $s6, 0x10($sp)
402335e4  sw        $s5, 0x14($sp)
402335e8  sw        $s4, 0x18($sp)
402335ec  sw        $s3, 0x1c($sp)
402335f0  sw        $s2, 0x20($sp)
402335f4  sw        $s1, 0x24($sp)
402335f8  sw        $s0, 0x28($sp)
402335fc  jal       0x4023326c
40233600  nop       
40233604  addiu     $a1, $zero, 0x88
40233608  jal       0x402369b8 ; import thunk COREDLL.dll!LocalAlloc@33
4023360c  addiu     $a0, $zero, 0x40
40233610  move      $s0, $v0
40233614  beqz      $s0, 0x402336b8
40233618  nop       
4023361c  lui       $t0, 0x4024
40233620  addiu     $s3, $t0, -0x7f0c
40233624  move      $s1, $zero
40233628  lui       $s6, 0x4024
4023362c  move      $s2, $s3
40233630  lui       $s4, 0x4024
40233634  lui       $s5, 0x4024
40233638  lw        $a2, ($s2)
4023363c  lw        $t0, -0x7fa4($s5) ; IAT COREDLL.dll!CreateMutexW@555
40233640  addiu     $a1, $zero, 0
40233644  jalr      $t0 ; call candidate COREDLL.dll!CreateMutexW@555
40233648  addiu     $a0, $zero, 0
4023364c  beqz      $v0, 0x402336b0
40233650  sw        $v0, 0x14($s0)
40233654  lw        $t0, -0x7fd8($s4)
40233658  jalr      $t0
4023365c  nop       
40233660  addiu     $a0, $zero, 0xb7
40233664  bne       $v0, $a0, 0x40233694
40233668  nop       
4023366c  lw        $t0, -0x7fa0($s6)
40233670  jalr      $t0
40233674  lw        $a0, 0x14($s0)
40233678  addiu     $s2, $s2, 4
4023367c  addiu     $t0, $s3, 0x40
40233680  slt       $t1, $s2, $t0
40233684  bnez      $t1, 0x40233638
40233688  addiu     $s1, $s1, 1
4023368c  b         0x40233698
40233690  nop       
40233694  sw        $s1, 0xc($s0)
40233698  addiu     $t0, $zero, 0x10
4023369c  bne       $s1, $t0, 0x402336e8
402336a0  nop       
402336a4  lui       $t1, 0x4023
402336a8  jal       0x40236978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
402336ac  addiu     $a0, $t1, 0x16f4
402336b0  jal       0x40236998 ; import thunk COREDLL.dll!LocalFree@36
402336b4  move      $a0, $s0
402336b8  move      $s0, $zero
402336bc  move      $v0, $s0
402336c0  lw        $s6, 0x10($sp)
402336c4  lw        $s5, 0x14($sp)
402336c8  lw        $s4, 0x18($sp)
402336cc  lw        $s3, 0x1c($sp)
402336d0  lw        $s2, 0x20($sp)
402336d4  lw        $s1, 0x24($sp)
402336d8  lw        $s0, 0x28($sp)
402336dc  lw        $ra, 0x2c($sp)
402336e0  jr        $ra
402336e4  addiu     $sp, $sp, 0x30
402336e8  lui       $t0, 0x4024
402336ec  lw        $a0, 0x14($s0)
402336f0  lw        $t0, -0x7fa8($t0) ; IAT COREDLL.dll!WaitForSingleObject@497
402336f4  jalr      $t0 ; call candidate COREDLL.dll!WaitForSingleObject@497
402336f8  addiu     $a1, $zero, -1
402336fc  lui       $t0, 0x4b
40233700  lw        $a0, 0xc($s0)
40233704  ori       $t0, $t0, 0xffe0
40233708  subu      $t0, $a0, $t0
4023370c  sll       $a0, $t0, 8
40233710  addiu     $a1, $zero, 0
40233714  jal       0x40232be8
40233718  sw        $a0, 0x24($s0)
4023371c  b         0x402336bc
40233720  nop       
40233778  addiu     $sp, $sp, -0x18
4023377c  sw        $ra, 0x14($sp)
40233780  sw        $s0, 0x10($sp)
40233784  move      $s0, $a0
40233788  beqz      $s0, 0x40233808
4023378c  nop       
40233790  lui       $t0, 0x4024
40233794  lw        $a0, 0x14($s0)
40233798  lw        $t0, -0x7fa8($t0) ; IAT COREDLL.dll!WaitForSingleObject@497
4023379c  jalr      $t0 ; call candidate COREDLL.dll!WaitForSingleObject@497
402337a0  addiu     $a1, $zero, 0
402337a4  bnez      $v0, 0x40233808
402337a8  nop       
402337ac  lw        $a0, 0x24($s0)
402337b0  jal       0x40232be8
402337b4  addiu     $a1, $zero, 0
402337b8  lw        $a0, 0x28($s0)
402337bc  beqz      $a0, 0x402337cc
402337c0  nop       
402337c4  jal       0x40236a38 ; import thunk COREDLL.dll!FreePhysMem@1487
402337c8  nop       
402337cc  lw        $a0, 0x2c($s0)
402337d0  beqz      $a0, 0x402337e0
402337d4  nop       
402337d8  jal       0x40236a38 ; import thunk COREDLL.dll!FreePhysMem@1487
402337dc  nop       
402337e0  lui       $t0, 0x4024
402337e4  lw        $t0, -0x7f98($t0) ; IAT COREDLL.dll!ReleaseMutex@556
402337e8  jalr      $t0 ; call candidate COREDLL.dll!ReleaseMutex@556
402337ec  lw        $a0, 0x14($s0)
402337f0  lui       $t0, 0x4024
402337f4  lw        $t0, -0x7fa0($t0) ; IAT COREDLL.dll!CloseHandle@553
402337f8  jalr      $t0 ; call candidate COREDLL.dll!CloseHandle@553
402337fc  lw        $a0, 0x14($s0)
40233800  jal       0x40236998 ; import thunk COREDLL.dll!LocalFree@36
40233804  move      $a0, $s0
40233808  lw        $s0, 0x10($sp)
4023380c  lw        $ra, 0x14($sp)
40233810  jr        $ra
40233814  addiu     $sp, $sp, 0x18
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
40234058  addiu     $sp, $sp, -0x28
4023405c  sw        $ra, 0x20($sp)
40234060  sw        $s3, 0x10($sp)
40234064  sw        $s2, 0x14($sp)
40234068  sw        $s1, 0x18($sp)
4023406c  sw        $s0, 0x1c($sp)
40234070  move      $s1, $a0
40234074  lw        $t0, 0x24($s1)
40234078  addiu     $a0, $t0, 0x14
4023407c  jal       0x40232bbc
40234080  move      $s0, $zero
40234084  andi      $a1, $v0, 1
40234088  bnez      $a1, 0x402340dc
4023408c  nop       
40234090  lw        $t0, 0x58($s1)
40234094  addiu     $s2, $zero, 1
40234098  bne       $t0, $s2, 0x402340b8
4023409c  lui       $s3, 0x8000
402340a0  jal       0x40232bbc
402340a4  lw        $a0, 0x40($s1)
402340a8  and       $a1, $v0, $s3
402340ac  bnez      $a1, 0x402340b8
402340b0  nop       
402340b4  move      $s0, $s2
402340b8  lw        $t0, 0x5c($s1)
402340bc  bne       $t0, $s2, 0x402340dc
402340c0  nop       
402340c4  jal       0x40232bbc
402340c8  lw        $a0, 0x44($s1)
402340cc  and       $a0, $v0, $s3
402340d0  bnez      $a0, 0x402340dc
402340d4  nop       
402340d8  ori       $s0, $s0, 2
402340dc  move      $v0, $s0
402340e0  lw        $s3, 0x10($sp)
402340e4  lw        $s2, 0x14($sp)
402340e8  lw        $s1, 0x18($sp)
402340ec  lw        $s0, 0x1c($sp)
402340f0  lw        $ra, 0x20($sp)
402340f4  jr        $ra
402340f8  addiu     $sp, $sp, 0x28
402340fc  addiu     $t0, $zero, 1
40234100  bne       $a1, $t0, 0x40234114
40234104  nop       
40234108  addiu     $t0, $zero, 2
4023410c  b         0x4023413c
40234110  sw        $t0, 0x58($a0)
40234114  addiu     $t1, $zero, 2
40234118  bne       $a1, $t1, 0x4023412c
4023411c  nop       
40234120  lw        $t0, 0x48($a0)
40234124  b         0x40234140
40234128  sw        $t1, 0x5c($a0)
4023412c  lw        $t2, 0x48($a0)
40234130  lw        $t1, 0x84($a0)
40234134  bne       $t1, $t2, 0x40234148
40234138  nop       
4023413c  lw        $t0, 0x50($a0)
40234140  b         0x4023414c
40234144  sw        $t0, 0x84($a0)
40234148  sw        $t2, 0x84($a0)
4023414c  jr        $ra
40234150  addiu     $v0, $zero, 1
; k.ceddk.dll ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff
c042326c  addiu     $sp, $sp, -0x18
c0423270  sw        $ra, 0x14($sp)
c0423274  sw        $s0, 0x10($sp)
c0423278  lui       $t0, 0xc043
c042327c  addiu     $t3, $t0, -0x7f0c
c0423280  move      $t4, $zero
c0423284  move      $t2, $t3
c0423288  addiu     $t2, $t2, 4
c042328c  addiu     $t0, $t3, 0x40
c0423290  slt       $t1, $t2, $t0
c0423294  bnez      $t1, 0xc0423288
c0423298  addiu     $t4, $t4, 1
c042329c  lui       $t0, 0xc043
c04232a0  addiu     $s0, $t0, -0x7ec4
c04232a4  lui       $t1, 0xc042
c04232a8  addiu     $t7, $zero, 1
c04232ac  sw        $t7, 0x80($s0)
c04232b0  addiu     $t0, $t1, 0x16e4 ; string candidate 'AC97 TX'
c04232b4  sw        $t0, 0x9c($s0)
c04232b8  addiu     $t6, $zero, 8
c04232bc  sw        $t6, 0x84($s0)
c04232c0  sw        $zero, 0x8c($s0)
c04232c4  lui       $t3, 0xe000
c04232c8  sw        $t3, 0x90($s0)
c04232cc  sw        $zero, 0x98($s0)
c04232d0  sw        $t7, 0xa0($s0)
c04232d4  lui       $t0, 0xc042
c04232d8  addiu     $t0, $t0, 0x16d4 ; string candidate 'AC97 RX'
c04232dc  sw        $t0, 0xbc($s0)
c04232e0  sw        $t6, 0xa4($s0)
c04232e4  sw        $t3, 0xac($s0)
c04232e8  sw        $zero, 0xb0($s0)
c04232ec  sw        $t7, 0xb8($s0)
c04232f0  lui       $t1, 0x3f05
c04232f4  lui       $t2, 0x10a0
c04232f8  lui       $t0, 0x23f5
c04232fc  ori       $t1, $t1, 0x1800
c0423300  sw        $t1, 0x88($s0)
c0423304  ori       $t2, $t2, 0x101c
c0423308  sw        $t2, 0x94($s0)
c042330c  ori       $t0, $t0, 0x1800
c0423310  sw        $t0, 0xa8($s0)
c0423314  sw        $t2, 0xb4($s0)
c0423318  sw        $t7, 0x180($s0)
c042331c  lui       $t0, 0xc042
c0423320  addiu     $t0, $t0, 0x16c4 ; string candidate 'I2S TX'
c0423324  sw        $t0, 0x19c($s0)
c0423328  sw        $t6, 0x184($s0)
c042332c  sw        $zero, 0x18c($s0)
c0423330  sw        $t3, 0x190($s0)
c0423334  sw        $zero, 0x198($s0)
c0423338  lui       $t2, 0xc042
c042333c  sw        $t7, 0x1a0($s0)
c0423340  addiu     $t0, $t2, 0x16b4 ; string candidate 'I2S RX'
c0423344  sw        $t0, 0x1bc($s0)
c0423348  sw        $t6, 0x1a4($s0)
c042334c  sw        $t3, 0x1ac($s0)
c0423350  lui       $t1, 0x3f25
c0423354  sw        $zero, 0x1b0($s0)
c0423358  lui       $t2, 0x10a0
c042335c  sw        $t7, 0x1b8($s0)
c0423360  lui       $t0, 0x27f5
c0423364  ori       $t1, $t1, 0x1800
c0423368  sw        $t1, 0x188($s0)
c042336c  ori       $t2, $t2, 0x201c
c0423370  sw        $t2, 0x194($s0)
c0423374  ori       $t0, $t0, 0x1800
c0423378  sw        $t0, 0x1a8($s0)
c042337c  sw        $t2, 0x1b4($s0)
c0423380  lui       $t0, 0xc042
c0423384  sw        $t7, 0x240($s0)
c0423388  addiu     $t0, $t0, 0x16a4 ; string candidate 'I2S2 TX'
c042338c  sw        $t0, 0x25c($s0)
c0423390  sw        $t6, 0x244($s0)
c0423394  sw        $zero, 0x24c($s0)
c0423398  lui       $t2, 0xc042
c042339c  sw        $t3, 0x250($s0)
c04233a0  sw        $zero, 0x258($s0)
c04233a4  addiu     $t0, $t2, 0x1694 ; string candidate 'I2S2 RX'
c04233a8  sw        $t7, 0x260($s0)
c04233ac  sw        $t0, 0x27c($s0)
c04233b0  lui       $t1, 0x3ee5
c04233b4  sw        $t6, 0x264($s0)
c04233b8  lui       $t2, 0x10a0
c04233bc  sw        $t3, 0x26c($s0)
c04233c0  sw        $zero, 0x270($s0)
c04233c4  ori       $t1, $t1, 0x1800
c04233c8  lui       $a0, 0x1400
c04233cc  sw        $t7, 0x278($s0)
c04233d0  ori       $t2, $t2, 0x1c
c04233d4  sw        $t1, 0x248($s0)
c04233d8  ori       $a0, $a0, 0x2000
c04233dc  sw        $t2, 0x254($s0)
c04233e0  lui       $t0, 0x1ff5
c04233e4  lui       $t1, 0x3e8a
c04233e8  ori       $t0, $t0, 0x1800
c04233ec  sw        $t0, 0x268($s0)
c04233f0  sw        $t2, 0x274($s0)
c04233f4  sw        $t7, 0x1c0($s0)
c04233f8  lui       $t0, 0xc042
c04233fc  addiu     $t0, $t0, 0x1680 ; string candidate 'SDIO0 TX'
c0423400  sw        $t0, 0x1dc($s0)
c0423404  sw        $t6, 0x1c4($s0)
c0423408  ori       $t1, $t1, 0x1800
c042340c  sw        $t1, 0x1c8($s0)
c0423410  lui       $t5, 0xc000
c0423414  sw        $t5, 0x1cc($s0)
c0423418  sw        $t3, 0x1d0($s0)
c042341c  lui       $t0, 0x1060
c0423420  sw        $t0, 0x1d4($s0)
c0423424  sw        $zero, 0x1d8($s0)
c0423428  sw        $t7, 0x1e0($s0)
c042342c  lui       $t1, 0xc042
c0423430  addiu     $t1, $t1, 0x166c ; string candidate 'SDIO0 RX'
c0423434  sw        $t1, 0x1fc($s0)
c0423438  sw        $t6, 0x1e4($s0)
c042343c  lui       $t0, 0x13fa
c0423440  lui       $t1, 0x1060
c0423444  ori       $t0, $t0, 0x1800
c0423448  sw        $t0, 0x1e8($s0)
c042344c  sw        $t3, 0x1ec($s0)
c0423450  sw        $t5, 0x1f0($s0)
c0423454  ori       $t1, $t1, 4
c0423458  sw        $t1, 0x1f4($s0)
c042345c  sw        $t7, 0x1f8($s0)
c0423460  sw        $t7, 0x280($s0)
c0423464  lui       $t0, 0xc042
c0423468  addiu     $t0, $t0, 0x165c ; string candidate 'IDE TX'
c042346c  sw        $t0, 0x29c($s0)
c0423470  lui       $t1, 0x3fda
c0423474  addiu     $t3, $zero, 0x28
c0423478  sw        $t3, 0x284($s0)
c042347c  ori       $t1, $t1, 0x1800
c0423480  sw        $t1, 0x288($s0)
c0423484  sw        $t5, 0x28c($s0)
c0423488  lui       $t4, 0xf000
c042348c  sw        $t4, 0x290($s0)
c0423490  lui       $t2, 0x1880
c0423494  sw        $t2, 0x294($s0)
c0423498  sw        $zero, 0x298($s0)
c042349c  lui       $t1, 0xc042
c04234a0  sw        $t7, 0x2a0($s0)
c04234a4  lui       $t0, 0x3bfa
c04234a8  addiu     $t1, $t1, 0x164c ; string candidate 'IDE RX'
c04234ac  sw        $t1, 0x2bc($s0)
c04234b0  sw        $t3, 0x2a4($s0)
c04234b4  ori       $t0, $t0, 0x1800
c04234b8  sw        $t0, 0x2a8($s0)
c04234bc  sw        $t4, 0x2ac($s0)
c04234c0  sw        $t5, 0x2b0($s0)
c04234c4  sw        $t2, 0x2b4($s0)
c04234c8  lui       $t0, 0xc042
c04234cc  sw        $t7, 0x2b8($s0)
c04234d0  addiu     $t0, $t0, 0x163c ; string candidate 'NAND TX'
c04234d4  sw        $t7, 0x2e0($s0)
c04234d8  lui       $t1, 0x3f7a
c04234dc  sw        $t0, 0x2fc($s0)
c04234e0  ori       $t1, $t1, 0x1800
c04234e4  sw        $t6, 0x2e4($s0)
c04234e8  lui       $t0, 0x2000
c04234ec  sw        $t1, 0x2e8($s0)
c04234f0  sw        $t5, 0x2ec($s0)
c04234f4  ori       $t0, $t0, 0x20
c04234f8  sw        $t4, 0x2f0($s0)
c04234fc  sw        $t0, 0x2f4($s0)
c0423500  lui       $t1, 0xc042
c0423504  lui       $t0, 0x2ffa
c0423508  sw        $zero, 0x2f8($s0)
c042350c  addiu     $t1, $t1, 0x162c ; string candidate 'NAND RX'
c0423510  sw        $t7, 0x300($s0)
c0423514  sw        $t1, 0x31c($s0)
c0423518  ori       $t0, $t0, 0x1800
c042351c  sw        $t6, 0x304($s0)
c0423520  sw        $t0, 0x308($s0)
c0423524  sw        $t4, 0x30c($s0)
c0423528  sw        $t5, 0x310($s0)
c042352c  lui       $t4, 0x2000
c0423530  addiu     $a3, $zero, 0
c0423534  sw        $t4, 0x314($s0)
c0423538  sw        $t7, 0x318($s0)
c042353c  lui       $t0, 0xc042
c0423540  lui       $t1, 0x3e00
c0423544  sw        $t7, ($s0)
c0423548  addiu     $t0, $t0, 0x1618 ; string candidate 'UART0 TX'
c042354c  sw        $t0, 0x1c($s0)
c0423550  sw        $t6, 4($s0)
c0423554  ori       $t1, $t1, 0x1800
c0423558  lui       $t2, 0x8000
c042355c  lui       $t3, 0x1010
c0423560  sw        $t1, 8($s0)
c0423564  lui       $t0, 0xa000
c0423568  sw        $t2, 0xc($s0)
c042356c  sw        $t0, 0x10($s0)
c0423570  ori       $t3, $t3, 4
c0423574  sw        $t3, 0x14($s0)
c0423578  lui       $t1, 0xc042
c042357c  sw        $zero, 0x18($s0)
c0423580  lui       $t0, 0x3f0
c0423584  addiu     $t1, $t1, 0x1604 ; string candidate 'UART0 RX'
c0423588  sw        $t7, 0x20($s0)
c042358c  sw        $t1, 0x3c($s0)
c0423590  ori       $t0, $t0, 0x1800
c0423594  sw        $t6, 0x24($s0)
c0423598  sw        $t0, 0x28($s0)
c042359c  lui       $t1, 0x1010
c04235a0  sw        $t4, 0x2c($s0)
c04235a4  sw        $zero, 0x30($s0)
c04235a8  sw        $t1, 0x34($s0)
c04235ac  addiu     $a2, $zero, 0x1010
c04235b0  addiu     $a1, $zero, 0
c04235b4  jal       0xc0422360
c04235b8  sw        $t7, 0x38($s0)
c04235bc  addiu     $t0, $zero, 7
c04235c0  sw        $v0, 0x320($s0)
c04235c4  lw        $s0, 0x10($sp)
c04235c8  lw        $ra, 0x14($sp)
c04235cc  addiu     $sp, $sp, 0x18
c04235d0  jr        $ra
c04235d4  sw        $t0, 0x1000($v0)
c04235d8  addiu     $sp, $sp, -0x30
c04235dc  sw        $ra, 0x2c($sp)
c04235e0  sw        $s6, 0x10($sp)
c04235e4  sw        $s5, 0x14($sp)
c04235e8  sw        $s4, 0x18($sp)
c04235ec  sw        $s3, 0x1c($sp)
c04235f0  sw        $s2, 0x20($sp)
c04235f4  sw        $s1, 0x24($sp)
c04235f8  sw        $s0, 0x28($sp)
c04235fc  jal       0xc042326c
c0423600  nop       
c0423604  addiu     $a1, $zero, 0x88
c0423608  jal       0xc04269b8 ; import thunk COREDLL.dll!LocalAlloc@33
c042360c  addiu     $a0, $zero, 0x40
c0423610  move      $s0, $v0
c0423614  beqz      $s0, 0xc04236b8
c0423618  nop       
c042361c  lui       $t0, 0xc043
c0423620  addiu     $s3, $t0, -0x7f0c
c0423624  move      $s1, $zero
c0423628  lui       $s6, 0xc043
c042362c  move      $s2, $s3
c0423630  lui       $s4, 0xc043
c0423634  lui       $s5, 0xc043
c0423638  lw        $a2, ($s2)
c042363c  lw        $t0, -0x7fa4($s5) ; IAT COREDLL.dll!CreateMutexW@555
c0423640  addiu     $a1, $zero, 0
c0423644  jalr      $t0 ; call candidate COREDLL.dll!CreateMutexW@555
c0423648  addiu     $a0, $zero, 0
c042364c  beqz      $v0, 0xc04236b0
c0423650  sw        $v0, 0x14($s0)
c0423654  lw        $t0, -0x7fd8($s4)
c0423658  jalr      $t0
c042365c  nop       
c0423660  addiu     $a0, $zero, 0xb7
c0423664  bne       $v0, $a0, 0xc0423694
c0423668  nop       
c042366c  lw        $t0, -0x7fa0($s6)
c0423670  jalr      $t0
c0423674  lw        $a0, 0x14($s0)
c0423678  addiu     $s2, $s2, 4
c042367c  addiu     $t0, $s3, 0x40
c0423680  slt       $t1, $s2, $t0
c0423684  bnez      $t1, 0xc0423638
c0423688  addiu     $s1, $s1, 1
c042368c  b         0xc0423698
c0423690  nop       
c0423694  sw        $s1, 0xc($s0)
c0423698  addiu     $t0, $zero, 0x10
c042369c  bne       $s1, $t0, 0xc04236e8
c04236a0  nop       
c04236a4  lui       $t1, 0xc042
c04236a8  jal       0xc0426978 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c04236ac  addiu     $a0, $t1, 0x16f4
c04236b0  jal       0xc0426998 ; import thunk COREDLL.dll!LocalFree@36
c04236b4  move      $a0, $s0
c04236b8  move      $s0, $zero
c04236bc  move      $v0, $s0
c04236c0  lw        $s6, 0x10($sp)
c04236c4  lw        $s5, 0x14($sp)
c04236c8  lw        $s4, 0x18($sp)
c04236cc  lw        $s3, 0x1c($sp)
c04236d0  lw        $s2, 0x20($sp)
c04236d4  lw        $s1, 0x24($sp)
c04236d8  lw        $s0, 0x28($sp)
c04236dc  lw        $ra, 0x2c($sp)
c04236e0  jr        $ra
c04236e4  addiu     $sp, $sp, 0x30
c04236e8  lui       $t0, 0xc043
c04236ec  lw        $a0, 0x14($s0)
c04236f0  lw        $t0, -0x7fa8($t0) ; IAT COREDLL.dll!WaitForSingleObject@497
c04236f4  jalr      $t0 ; call candidate COREDLL.dll!WaitForSingleObject@497
c04236f8  addiu     $a1, $zero, -1
c04236fc  lui       $t0, 0x4b
c0423700  lw        $a0, 0xc($s0)
c0423704  ori       $t0, $t0, 0xffe0
c0423708  subu      $t0, $a0, $t0
c042370c  sll       $a0, $t0, 8
c0423710  addiu     $a1, $zero, 0
c0423714  jal       0xc0422be8
c0423718  sw        $a0, 0x24($s0)
c042371c  b         0xc04236bc
c0423720  nop       
c0423778  addiu     $sp, $sp, -0x18
c042377c  sw        $ra, 0x14($sp)
c0423780  sw        $s0, 0x10($sp)
c0423784  move      $s0, $a0
c0423788  beqz      $s0, 0xc0423808
c042378c  nop       
c0423790  lui       $t0, 0xc043
c0423794  lw        $a0, 0x14($s0)
c0423798  lw        $t0, -0x7fa8($t0) ; IAT COREDLL.dll!WaitForSingleObject@497
c042379c  jalr      $t0 ; call candidate COREDLL.dll!WaitForSingleObject@497
c04237a0  addiu     $a1, $zero, 0
c04237a4  bnez      $v0, 0xc0423808
c04237a8  nop       
c04237ac  lw        $a0, 0x24($s0)
c04237b0  jal       0xc0422be8
c04237b4  addiu     $a1, $zero, 0
c04237b8  lw        $a0, 0x28($s0)
c04237bc  beqz      $a0, 0xc04237cc
c04237c0  nop       
c04237c4  jal       0xc0426a38 ; import thunk COREDLL.dll!FreePhysMem@1487
c04237c8  nop       
c04237cc  lw        $a0, 0x2c($s0)
c04237d0  beqz      $a0, 0xc04237e0
c04237d4  nop       
c04237d8  jal       0xc0426a38 ; import thunk COREDLL.dll!FreePhysMem@1487
c04237dc  nop       
c04237e0  lui       $t0, 0xc043
c04237e4  lw        $t0, -0x7f98($t0) ; IAT COREDLL.dll!ReleaseMutex@556
c04237e8  jalr      $t0 ; call candidate COREDLL.dll!ReleaseMutex@556
c04237ec  lw        $a0, 0x14($s0)
c04237f0  lui       $t0, 0xc043
c04237f4  lw        $t0, -0x7fa0($t0) ; IAT COREDLL.dll!CloseHandle@553
c04237f8  jalr      $t0 ; call candidate COREDLL.dll!CloseHandle@553
c04237fc  lw        $a0, 0x14($s0)
c0423800  jal       0xc0426998 ; import thunk COREDLL.dll!LocalFree@36
c0423804  move      $a0, $s0
c0423808  lw        $s0, 0x10($sp)
c042380c  lw        $ra, 0x14($sp)
c0423810  jr        $ra
c0423814  addiu     $sp, $sp, 0x18
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
c0424058  addiu     $sp, $sp, -0x28
c042405c  sw        $ra, 0x20($sp)
c0424060  sw        $s3, 0x10($sp)
c0424064  sw        $s2, 0x14($sp)
c0424068  sw        $s1, 0x18($sp)
c042406c  sw        $s0, 0x1c($sp)
c0424070  move      $s1, $a0
c0424074  lw        $t0, 0x24($s1)
c0424078  addiu     $a0, $t0, 0x14
c042407c  jal       0xc0422bbc
c0424080  move      $s0, $zero
c0424084  andi      $a1, $v0, 1
c0424088  bnez      $a1, 0xc04240dc
c042408c  nop       
c0424090  lw        $t0, 0x58($s1)
c0424094  addiu     $s2, $zero, 1
c0424098  bne       $t0, $s2, 0xc04240b8
c042409c  lui       $s3, 0x8000
c04240a0  jal       0xc0422bbc
c04240a4  lw        $a0, 0x40($s1)
c04240a8  and       $a1, $v0, $s3
c04240ac  bnez      $a1, 0xc04240b8
c04240b0  nop       
c04240b4  move      $s0, $s2
c04240b8  lw        $t0, 0x5c($s1)
c04240bc  bne       $t0, $s2, 0xc04240dc
c04240c0  nop       
c04240c4  jal       0xc0422bbc
c04240c8  lw        $a0, 0x44($s1)
c04240cc  and       $a0, $v0, $s3
c04240d0  bnez      $a0, 0xc04240dc
c04240d4  nop       
c04240d8  ori       $s0, $s0, 2
c04240dc  move      $v0, $s0
c04240e0  lw        $s3, 0x10($sp)
c04240e4  lw        $s2, 0x14($sp)
c04240e8  lw        $s1, 0x18($sp)
c04240ec  lw        $s0, 0x1c($sp)
c04240f0  lw        $ra, 0x20($sp)
c04240f4  jr        $ra
c04240f8  addiu     $sp, $sp, 0x28
c04240fc  addiu     $t0, $zero, 1
c0424100  bne       $a1, $t0, 0xc0424114
c0424104  nop       
c0424108  addiu     $t0, $zero, 2
c042410c  b         0xc042413c
c0424110  sw        $t0, 0x58($a0)
c0424114  addiu     $t1, $zero, 2
c0424118  bne       $a1, $t1, 0xc042412c
c042411c  nop       
c0424120  lw        $t0, 0x48($a0)
c0424124  b         0xc0424140
c0424128  sw        $t1, 0x5c($a0)
c042412c  lw        $t2, 0x48($a0)
c0424130  lw        $t1, 0x84($a0)
c0424134  bne       $t1, $t2, 0xc0424148
c0424138  nop       
c042413c  lw        $t0, 0x50($a0)
c0424140  b         0xc042414c
c0424144  sw        $t0, 0x84($a0)
c0424148  sw        $t2, 0x84($a0)
c042414c  jr        $ra
c0424150  addiu     $v0, $zero, 1
; coredll.dll 1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c
4002ae6c  addiu     $sp, $sp, -0x18
4002ae70  sw        $ra, 0x10($sp)
4002ae74  move      $a3, $a2
4002ae78  move      $a2, $a1
4002ae7c  move      $a1, $a0
4002ae80  addiu     $t0, $zero, -0x4c2a
4002ae84  jalr      $t0
4002ae88  addiu     $a0, $zero, 0x42
4002ae8c  lw        $ra, 0x10($sp)
4002ae90  jr        $ra
4002ae94  addiu     $sp, $sp, 0x18
4002af98  addiu     $sp, $sp, -0x20
4002af9c  sw        $ra, 0x18($sp)
4002afa0  sw        $a3, 0x10($sp)
4002afa4  move      $a3, $a2
4002afa8  lw        $t0, 0x30($sp)
4002afac  move      $a2, $a1
4002afb0  move      $a1, $a0
4002afb4  addiu     $a0, $zero, 0x42
4002afb8  addiu     $t1, $zero, -0x4c62
4002afbc  jalr      $t1
4002afc0  sw        $t0, 0x14($sp)
4002afc4  lw        $ra, 0x18($sp)
4002afc8  jr        $ra
4002afcc  addiu     $sp, $sp, 0x20
4002afd0  addiu     $sp, $sp, -0x18
4002afd4  sw        $ra, 0x10($sp)
4002afd8  move      $a1, $a0
4002afdc  ori       $a3, $zero, 0x8000
4002afe0  addiu     $a2, $zero, 0
4002afe4  addiu     $t0, $zero, -0x4c2a
4002afe8  jalr      $t0
4002afec  addiu     $a0, $zero, 0x42
4002aff0  lw        $ra, 0x10($sp)
4002aff4  jr        $ra
4002aff8  addiu     $sp, $sp, 0x18
; wavedev2_i2s.dll fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c
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
; wavedev2_i2s2.dll eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009
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
