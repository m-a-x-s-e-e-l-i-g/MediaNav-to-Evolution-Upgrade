; ceddk.dll 9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731
40232360  addiu     $sp, $sp, -0x30
40232364  sw        $ra, 0x28($sp)
40232368  sw        $s5, 0x10($sp)
4023236c  sw        $s4, 0x14($sp)
40232370  sw        $s3, 0x18($sp)
40232374  sw        $s2, 0x1c($sp)
40232378  sw        $s1, 0x20($sp)
4023237c  sw        $s0, 0x24($sp)
40232380  addiu     $t2, $zero, 0x5b04
40232384  lw        $t0, ($t2)
40232388  addiu     $t1, $t0, -1
4023238c  not       $t4, $t1
40232390  and       $s3, $t4, $a0
40232394  subu      $s1, $a0, $s3
40232398  move      $t2, $t0
4023239c  addu      $t0, $t2, $s1
402323a0  addu      $t1, $t0, $a2
402323a4  addiu     $t3, $t1, -1
402323a8  and       $s4, $t3, $t4
402323ac  move      $s2, $a3
402323b0  move      $s5, $a1
402323b4  addiu     $a3, $zero, 1
402323b8  addiu     $a2, $zero, 0x2000
402323bc  move      $a1, $s4
402323c0  jal       0x40236948 ; import thunk COREDLL.dll!VirtualAlloc@524
402323c4  addiu     $a0, $zero, 0
402323c8  move      $s0, $v0
402323cc  beqz      $s0, 0x4023241c
402323d0  nop       
402323d4  bnez      $s2, 0x402323e0
402323d8  addiu     $a3, $zero, 0x404
402323dc  addiu     $a3, $zero, 0x604
402323e0  srl       $t1, $s3, 8
402323e4  sll       $t0, $s5, 0x18
402323e8  or        $a1, $t0, $t1
402323ec  move      $a2, $s4
402323f0  jal       0x40236938 ; import thunk COREDLL.dll!VirtualCopy@560
402323f4  move      $a0, $s0
402323f8  bnez      $v0, 0x40232418
402323fc  nop       
40232400  ori       $a2, $zero, 0x8000
40232404  addiu     $a1, $zero, 0
40232408  jal       0x40236928 ; import thunk COREDLL.dll!VirtualFree@525
4023240c  move      $a0, $s0
40232410  b         0x4023241c
40232414  move      $s0, $zero
40232418  addu      $s0, $s1, $s0
4023241c  move      $v0, $s0
40232420  lw        $s5, 0x10($sp)
40232424  lw        $s4, 0x14($sp)
40232428  lw        $s3, 0x18($sp)
4023242c  lw        $s2, 0x1c($sp)
40232430  lw        $s1, 0x20($sp)
40232434  lw        $s0, 0x24($sp)
40232438  lw        $ra, 0x28($sp)
4023243c  jr        $ra
40232440  addiu     $sp, $sp, 0x30
40232444  addiu     $sp, $sp, -0x18
40232448  sw        $ra, 0x10($sp)
4023244c  addiu     $t0, $zero, 0x5b04
40232450  lw        $t0, ($t0)
40232454  addiu     $t1, $t0, -1
40232458  not       $t2, $t1
4023245c  and       $a0, $t2, $a0
40232460  ori       $a2, $zero, 0x8000
40232464  jal       0x40236928 ; import thunk COREDLL.dll!VirtualFree@525
40232468  addiu     $a1, $zero, 0
4023246c  lw        $ra, 0x10($sp)
40232470  jr        $ra
40232474  addiu     $sp, $sp, 0x18
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
; k.ceddk.dll ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff
c0422360  addiu     $sp, $sp, -0x30
c0422364  sw        $ra, 0x28($sp)
c0422368  sw        $s5, 0x10($sp)
c042236c  sw        $s4, 0x14($sp)
c0422370  sw        $s3, 0x18($sp)
c0422374  sw        $s2, 0x1c($sp)
c0422378  sw        $s1, 0x20($sp)
c042237c  sw        $s0, 0x24($sp)
c0422380  addiu     $t2, $zero, 0x5b04
c0422384  lw        $t0, ($t2)
c0422388  addiu     $t1, $t0, -1
c042238c  not       $t4, $t1
c0422390  and       $s3, $t4, $a0
c0422394  subu      $s1, $a0, $s3
c0422398  move      $t2, $t0
c042239c  addu      $t0, $t2, $s1
c04223a0  addu      $t1, $t0, $a2
c04223a4  addiu     $t3, $t1, -1
c04223a8  and       $s4, $t3, $t4
c04223ac  move      $s2, $a3
c04223b0  move      $s5, $a1
c04223b4  addiu     $a3, $zero, 1
c04223b8  addiu     $a2, $zero, 0x2000
c04223bc  move      $a1, $s4
c04223c0  jal       0xc0426948 ; import thunk COREDLL.dll!VirtualAlloc@524
c04223c4  addiu     $a0, $zero, 0
c04223c8  move      $s0, $v0
c04223cc  beqz      $s0, 0xc042241c
c04223d0  nop       
c04223d4  bnez      $s2, 0xc04223e0
c04223d8  addiu     $a3, $zero, 0x404
c04223dc  addiu     $a3, $zero, 0x604
c04223e0  srl       $t1, $s3, 8
c04223e4  sll       $t0, $s5, 0x18
c04223e8  or        $a1, $t0, $t1
c04223ec  move      $a2, $s4
c04223f0  jal       0xc0426938 ; import thunk COREDLL.dll!VirtualCopy@560
c04223f4  move      $a0, $s0
c04223f8  bnez      $v0, 0xc0422418
c04223fc  nop       
c0422400  ori       $a2, $zero, 0x8000
c0422404  addiu     $a1, $zero, 0
c0422408  jal       0xc0426928 ; import thunk COREDLL.dll!VirtualFree@525
c042240c  move      $a0, $s0
c0422410  b         0xc042241c
c0422414  move      $s0, $zero
c0422418  addu      $s0, $s1, $s0
c042241c  move      $v0, $s0
c0422420  lw        $s5, 0x10($sp)
c0422424  lw        $s4, 0x14($sp)
c0422428  lw        $s3, 0x18($sp)
c042242c  lw        $s2, 0x1c($sp)
c0422430  lw        $s1, 0x20($sp)
c0422434  lw        $s0, 0x24($sp)
c0422438  lw        $ra, 0x28($sp)
c042243c  jr        $ra
c0422440  addiu     $sp, $sp, 0x30
c0422444  addiu     $sp, $sp, -0x18
c0422448  sw        $ra, 0x10($sp)
c042244c  addiu     $t0, $zero, 0x5b04
c0422450  lw        $t0, ($t0)
c0422454  addiu     $t1, $t0, -1
c0422458  not       $t2, $t1
c042245c  and       $a0, $t2, $a0
c0422460  ori       $a2, $zero, 0x8000
c0422464  jal       0xc0426928 ; import thunk COREDLL.dll!VirtualFree@525
c0422468  addiu     $a1, $zero, 0
c042246c  lw        $ra, 0x10($sp)
c0422470  jr        $ra
c0422474  addiu     $sp, $sp, 0x18
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
; coredll.dll 1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c
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
