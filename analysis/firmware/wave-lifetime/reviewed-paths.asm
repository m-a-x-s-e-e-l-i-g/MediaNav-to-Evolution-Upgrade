; ceddk.dll 9db6404163f5280080d8bfe50b1f7d413de189de0536e7dd79b403f1cab50731
40234198  lw        $t0, 0xc($a0)
4023419c  addiu     $t1, $t0, 0xa0
402341a0  jr        $ra
402341a4  andi      $v0, $t1, 0xff
; k.ceddk.dll ccbbe9983bca33cb3d2b548fda266168fb6c3164039a5f9a82417aa9398b2aff
c0424198  lw        $t0, 0xc($a0)
c042419c  addiu     $t1, $t0, 0xa0
c04241a0  jr        $ra
c04241a4  andi      $v0, $t1, 0xff
; wavedev2_i2s.dll fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c
c09420ac  addiu     $sp, $sp, -0x18
c09420b0  sw        $ra, 0x10($sp)
c09420b4  jal       0xc0948128
c09420b8  nop       
c09420bc  lw        $ra, 0x10($sp)
c09420c0  jr        $ra
c09420c4  addiu     $sp, $sp, 0x18
c09420c8  addiu     $sp, $sp, -0x18
c09420cc  sw        $ra, 0x10($sp)
c09420d0  lui       $t0, 0xc095
c09420d4  jal       0xc0947630
c09420d8  lw        $a0, -0x5ec0($t0)
c09420dc  lw        $ra, 0x10($sp)
c09420e0  jr        $ra
c09420e4  addiu     $sp, $sp, 0x18
c0947630  addiu     $sp, $sp, -0x18
c0947634  sw        $ra, 0x14($sp)
c0947638  sw        $s0, 0x10($sp)
c094763c  move      $s0, $a0
c0947640  lw        $a0, 0xb0($s0)
c0947644  beqz      $a0, 0xc0947658
c0947648  nop       
c094764c  jal       0xc0948b18 ; import thunk COREDLL.dll!FreeIntChainHandler@1476
c0947650  nop       
c0947654  sw        $zero, 0xb0($s0)
c0947658  jal       0xc09481a4
c094765c  addiu     $a0, $s0, 0xc8
c0947660  bnez      $v0, 0xc0947670
c0947664  nop       
c0947668  b         0xc0947674
c094766c  move      $v0, $zero
c0947670  addiu     $v0, $zero, 1
c0947674  lw        $s0, 0x10($sp)
c0947678  lw        $ra, 0x14($sp)
c094767c  jr        $ra
c0947680  addiu     $sp, $sp, 0x18
c0947ec4  addiu     $sp, $sp, -0x20
c0947ec8  sw        $ra, 0x1c($sp)
c0947ecc  sw        $s0, 0x18($sp)
c0947ed0  lui       $t0, 0xc095
c0947ed4  move      $s0, $a0
c0947ed8  lw        $t0, -0x5fa8($t0) ; IAT COREDLL.dll!CreateEventW@495
c0947edc  addiu     $a3, $zero, 0
c0947ee0  addiu     $a2, $zero, 0
c0947ee4  addiu     $a1, $zero, 0
c0947ee8  jalr      $t0 ; call candidate COREDLL.dll!CreateEventW@495
c0947eec  addiu     $a0, $zero, 0
c0947ef0  bnez      $v0, 0xc0947f00
c0947ef4  sw        $v0, 0xb4($s0)
c0947ef8  b         0xc0947f68
c0947efc  move      $v0, $zero
c0947f00  lw        $a0, 0xac($s0)
c0947f04  addiu     $a3, $zero, 0
c0947f08  addiu     $a2, $zero, 0
c0947f0c  jal       0xc0948b68 ; import thunk COREDLL.dll!InterruptInitialize@627
c0947f10  move      $a1, $v0
c0947f14  lui       $t0, 0xc094
c0947f18  move      $a3, $s0
c0947f1c  addiu     $a2, $t0, 0x7b00
c0947f20  addiu     $a1, $zero, 0
c0947f24  addiu     $a0, $zero, 0
c0947f28  sw        $zero, 0x14($sp)
c0947f2c  jal       0xc0948b58 ; import thunk COREDLL.dll!CreateThread@492
c0947f30  sw        $zero, 0x10($sp)
c0947f34  beqz      $v0, 0xc0947ef8
c0947f38  sw        $v0, 0xb8($s0)
c0947f3c  lui       $t0, 0xc094
c0947f40  addiu     $a2, $zero, 0x96
c0947f44  addiu     $a1, $t0, 0x1dd4 ; string candidate 'Priority256'
c0947f48  jal       0xc0947818
c0947f4c  move      $a0, $s0
c0947f50  lui       $t0, 0xc095
c0947f54  lw        $a0, 0xb8($s0)
c0947f58  lw        $t0, -0x5fb4($t0) ; IAT COREDLL.dll!CeSetThreadPriority@621
c0947f5c  jalr      $t0 ; call candidate COREDLL.dll!CeSetThreadPriority@621
c0947f60  move      $a1, $v0
c0947f64  addiu     $v0, $zero, 1
c0947f68  lw        $s0, 0x18($sp)
c0947f6c  lw        $ra, 0x1c($sp)
c0947f70  jr        $ra
c0947f74  addiu     $sp, $sp, 0x20
c0947f78  addiu     $sp, $sp, -0x20
c0947f7c  sw        $ra, 0x18($sp)
c0947f80  sw        $s1, 0x10($sp)
c0947f84  sw        $s0, 0x14($sp)
c0947f88  move      $s1, $a0
c0947f8c  lw        $t0, 0x18($s1)
c0947f90  beqz      $t0, 0xc0947fa0
c0947f94  nop       
c0947f98  b         0xc0948114
c0947f9c  move      $v0, $zero
c0947fa0  lui       $t0, 0xffff
c0947fa4  sw        $a1, ($s1)
c0947fa8  ori       $t0, $t0, 0xffff
c0947fac  sw        $t0, 0x9c($s1)
c0947fb0  sw        $t0, 0xa0($s1)
c0947fb4  addiu     $s0, $s1, 0xc8
c0947fb8  addiu     $t0, $zero, 5
c0947fbc  move      $a0, $s0
c0947fc0  sw        $zero, 0x1c($s1)
c0947fc4  sw        $zero, 0x80($s1)
c0947fc8  sw        $zero, 0x84($s1)
c0947fcc  sw        $zero, 0x88($s1)
c0947fd0  sw        $zero, 0xa4($s1)
c0947fd4  sw        $zero, 0xa8($s1)
c0947fd8  sw        $zero, 0xbc($s1)
c0947fdc  jal       0xc0948940
c0947fe0  sw        $t0, 0xc0($s1)
c0947fe4  beqz      $v0, 0xc0947f98
c0947fe8  nop       
c0947fec  jal       0xc09481a4
c0947ff0  move      $a0, $s0
c0947ff4  beqz      $v0, 0xc0947f98
c0947ff8  nop       
c0947ffc  lui       $t0, 0xc094
c0948000  addiu     $a2, $zero, 0
c0948004  addiu     $a1, $t0, 0x1e10 ; string candidate 'MinDACSampleRate'
c0948008  jal       0xc0947d14
c094800c  move      $a0, $s1
c0948010  lui       $t0, 0xc094
c0948014  addiu     $a2, $zero, 0
c0948018  addiu     $a1, $t0, 0x1dec ; string candidate 'MinADCSampleRate'
c094801c  move      $a0, $s1
c0948020  jal       0xc0947d14
c0948024  sw        $v0, ($s0)
c0948028  lw        $t0, ($s0)
c094802c  sw        $v0, 0xcc($s1)
c0948030  bnez      $t0, 0xc094803c
c0948034  addiu     $t1, $zero, 0x1f40
c0948038  sw        $t1, ($s0)
c094803c  bnez      $v0, 0xc0948048
c0948040  nop       
c0948044  sw        $t1, 0xcc($s1)
c0948048  addiu     $a0, $s1, 0x20
c094804c  lw        $t0, ($a0)
c0948050  lw        $t0, 0x18($t0)
c0948054  jalr      $t0
c0948058  ori       $a1, $zero, 0xbb80
c094805c  addiu     $a0, $s1, 0x50
c0948060  lw        $t0, ($a0)
c0948064  lw        $t0, 0x18($t0)
c0948068  jalr      $t0
c094806c  ori       $a1, $zero, 0xbb80
c0948070  addiu     $a0, $zero, 0x1000
c0948074  sw        $a0, 0xe8($s1)
c0948078  jal       0xc09483c0
c094807c  move      $a0, $s0
c0948080  addiu     $a1, $s1, 0xac
c0948084  jal       0xc0948340
c0948088  move      $a0, $s0
c094808c  jal       0xc0947ec4
c0948090  move      $a0, $s1
c0948094  beqz      $v0, 0xc0948110
c0948098  nop       
c094809c  lui       $t0, 0xc094
c09480a0  addiu     $s0, $t0, 0x1b40 ; string candidate 'EnableSpdif'
c09480a4  addiu     $a2, $zero, 0
c09480a8  move      $a1, $s0
c09480ac  jal       0xc0947818
c09480b0  move      $a0, $s1
c09480b4  lw        $t0, 0x90($s1)
c09480b8  beq       $v0, $t0, 0xc09480d4
c09480bc  nop       
c09480c0  move      $a2, $v0
c09480c4  move      $a1, $s0
c09480c8  move      $a0, $s1
c09480cc  jal       0xc09478a0
c09480d0  sw        $v0, 0x90($s1)
c09480d4  lui       $t0, 0xc094
c09480d8  addiu     $s0, $t0, 0x1b8c ; string candidate 'EnableSpdifWmaPro'
c09480dc  addiu     $a2, $zero, 0
c09480e0  move      $a1, $s0
c09480e4  jal       0xc0947818
c09480e8  move      $a0, $s1
c09480ec  move      $a2, $v0
c09480f0  move      $a1, $s0
c09480f4  move      $a0, $s1
c09480f8  jal       0xc09478a0
c09480fc  sw        $v0, 0x94($s1)
c0948100  jal       0xc09471c0
c0948104  nop       
c0948108  addiu     $a0, $zero, 1
c094810c  sw        $a0, 0x18($s1)
c0948110  lw        $v0, 0x18($s1)
c0948114  lw        $s1, 0x10($sp)
c0948118  lw        $s0, 0x14($sp)
c094811c  lw        $ra, 0x18($sp)
c0948120  jr        $ra
c0948124  addiu     $sp, $sp, 0x20
c0948128  addiu     $sp, $sp, -0x20
c094812c  sw        $ra, 0x18($sp)
c0948130  sw        $s1, 0x10($sp)
c0948134  sw        $s0, 0x14($sp)
c0948138  lui       $s1, 0xc095
c094813c  lw        $t0, -0x5ec0($s1)
c0948140  beqz      $t0, 0xc0948150
c0948144  move      $s0, $a0
c0948148  b         0xc0948190
c094814c  addiu     $v0, $zero, 1
c0948150  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0948154  addiu     $a0, $zero, 0xec
c0948158  beqz      $v0, 0xc0948170
c094815c  nop       
c0948160  jal       0xc0947ddc
c0948164  move      $a0, $v0
c0948168  b         0xc0948174
c094816c  nop       
c0948170  move      $v0, $zero
c0948174  bnez      $v0, 0xc0948184
c0948178  sw        $v0, -0x5ec0($s1)
c094817c  b         0xc0948190
c0948180  move      $v0, $zero
c0948184  move      $a1, $s0
c0948188  jal       0xc0947f78
c094818c  move      $a0, $v0
c0948190  lw        $s1, 0x10($sp)
c0948194  lw        $s0, 0x14($sp)
c0948198  lw        $ra, 0x18($sp)
c094819c  jr        $ra
c09481a0  addiu     $sp, $sp, 0x20
c09481a4  jr        $ra
c09481a8  addiu     $v0, $zero, 1
c0948340  addiu     $sp, $sp, -0x20
c0948344  sw        $ra, 0x1c($sp)
c0948348  sw        $s2, 0x10($sp)
c094834c  sw        $s1, 0x14($sp)
c0948350  sw        $s0, 0x18($sp)
c0948354  move      $s0, $a0
c0948358  lw        $a0, 0x1c($s0)
c094835c  jal       0xc0948bd8 ; import thunk CEDDK.dll!HalGetDMAHwIntr
c0948360  move      $s2, $a1
c0948364  lw        $a0, 0x18($s0)
c0948368  jal       0xc0948bd8 ; import thunk CEDDK.dll!HalGetDMAHwIntr
c094836c  move      $s1, $v0
c0948370  sll       $t0, $v0, 8
c0948374  or        $a2, $t0, $s1
c0948378  addiu     $a3, $zero, 0
c094837c  addiu     $a1, $zero, 0
c0948380  jal       0xc0948bc8 ; import thunk CEDDK.dll!InterruptConnect
c0948384  addiu     $a0, $zero, 0
c0948388  bnez      $v0, 0xc09483a4
c094838c  sw        $v0, ($s2)
c0948390  lui       $t0, 0xc094
c0948394  jal       0xc0948ab8 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0948398  addiu     $a0, $t0, 0x1ee4
c094839c  b         0xc09483a8
c09483a0  move      $v0, $zero
c09483a4  addiu     $v0, $zero, 1
c09483a8  lw        $s2, 0x10($sp)
c09483ac  lw        $s1, 0x14($sp)
c09483b0  lw        $s0, 0x18($sp)
c09483b4  lw        $ra, 0x1c($sp)
c09483b8  jr        $ra
c09483bc  addiu     $sp, $sp, 0x20
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
c095210c  addiu     $sp, $sp, -0x18
c0952110  sw        $ra, 0x10($sp)
c0952114  jal       0xc0958224
c0952118  nop       
c095211c  lw        $ra, 0x10($sp)
c0952120  jr        $ra
c0952124  addiu     $sp, $sp, 0x18
c0952128  addiu     $sp, $sp, -0x18
c095212c  sw        $ra, 0x10($sp)
c0952130  lui       $t0, 0xc096
c0952134  jal       0xc095772c
c0952138  lw        $a0, -0x5ec4($t0)
c095213c  lw        $ra, 0x10($sp)
c0952140  jr        $ra
c0952144  addiu     $sp, $sp, 0x18
c095772c  addiu     $sp, $sp, -0x18
c0957730  sw        $ra, 0x14($sp)
c0957734  sw        $s0, 0x10($sp)
c0957738  move      $s0, $a0
c095773c  lw        $a0, 0xb0($s0)
c0957740  beqz      $a0, 0xc0957754
c0957744  nop       
c0957748  jal       0xc09588b4 ; import thunk COREDLL.dll!FreeIntChainHandler@1476
c095774c  nop       
c0957750  sw        $zero, 0xb0($s0)
c0957754  jal       0xc0958600
c0957758  addiu     $a0, $s0, 0xc8
c095775c  bnez      $v0, 0xc095776c
c0957760  nop       
c0957764  b         0xc0957770
c0957768  move      $v0, $zero
c095776c  addiu     $v0, $zero, 1
c0957770  lw        $s0, 0x10($sp)
c0957774  lw        $ra, 0x14($sp)
c0957778  jr        $ra
c095777c  addiu     $sp, $sp, 0x18
c0957fc0  addiu     $sp, $sp, -0x20
c0957fc4  sw        $ra, 0x1c($sp)
c0957fc8  sw        $s0, 0x18($sp)
c0957fcc  lui       $t0, 0xc096
c0957fd0  move      $s0, $a0
c0957fd4  lw        $t0, -0x5fa8($t0) ; IAT COREDLL.dll!CreateEventW@495
c0957fd8  addiu     $a3, $zero, 0
c0957fdc  addiu     $a2, $zero, 0
c0957fe0  addiu     $a1, $zero, 0
c0957fe4  jalr      $t0 ; call candidate COREDLL.dll!CreateEventW@495
c0957fe8  addiu     $a0, $zero, 0
c0957fec  bnez      $v0, 0xc0957ffc
c0957ff0  sw        $v0, 0xb4($s0)
c0957ff4  b         0xc0958064
c0957ff8  move      $v0, $zero
c0957ffc  lw        $a0, 0xac($s0)
c0958000  addiu     $a3, $zero, 0
c0958004  addiu     $a2, $zero, 0
c0958008  jal       0xc0958904 ; import thunk COREDLL.dll!InterruptInitialize@627
c095800c  move      $a1, $v0
c0958010  lui       $t0, 0xc095
c0958014  move      $a3, $s0
c0958018  addiu     $a2, $t0, 0x7bfc
c095801c  addiu     $a1, $zero, 0
c0958020  addiu     $a0, $zero, 0
c0958024  sw        $zero, 0x14($sp)
c0958028  jal       0xc09588f4 ; import thunk COREDLL.dll!CreateThread@492
c095802c  sw        $zero, 0x10($sp)
c0958030  beqz      $v0, 0xc0957ff4
c0958034  sw        $v0, 0xb8($s0)
c0958038  lui       $t0, 0xc095
c095803c  addiu     $a2, $zero, 0x96
c0958040  addiu     $a1, $t0, 0x1ec8 ; string candidate 'Priority256'
c0958044  jal       0xc0957914
c0958048  move      $a0, $s0
c095804c  lui       $t0, 0xc096
c0958050  lw        $a0, 0xb8($s0)
c0958054  lw        $t0, -0x5fb4($t0) ; IAT COREDLL.dll!CeSetThreadPriority@621
c0958058  jalr      $t0 ; call candidate COREDLL.dll!CeSetThreadPriority@621
c095805c  move      $a1, $v0
c0958060  addiu     $v0, $zero, 1
c0958064  lw        $s0, 0x18($sp)
c0958068  lw        $ra, 0x1c($sp)
c095806c  jr        $ra
c0958070  addiu     $sp, $sp, 0x20
c0958074  addiu     $sp, $sp, -0x20
c0958078  sw        $ra, 0x18($sp)
c095807c  sw        $s1, 0x10($sp)
c0958080  sw        $s0, 0x14($sp)
c0958084  move      $s1, $a0
c0958088  lw        $t0, 0x18($s1)
c095808c  beqz      $t0, 0xc095809c
c0958090  nop       
c0958094  b         0xc0958210
c0958098  move      $v0, $zero
c095809c  lui       $t0, 0xffff
c09580a0  sw        $a1, ($s1)
c09580a4  ori       $t0, $t0, 0xffff
c09580a8  sw        $t0, 0x9c($s1)
c09580ac  sw        $t0, 0xa0($s1)
c09580b0  addiu     $s0, $s1, 0xc8
c09580b4  addiu     $t0, $zero, 5
c09580b8  move      $a0, $s0
c09580bc  sw        $zero, 0x1c($s1)
c09580c0  sw        $zero, 0x80($s1)
c09580c4  sw        $zero, 0x84($s1)
c09580c8  sw        $zero, 0x88($s1)
c09580cc  sw        $zero, 0xa4($s1)
c09580d0  sw        $zero, 0xa8($s1)
c09580d4  sw        $zero, 0xbc($s1)
c09580d8  jal       0xc095878c
c09580dc  sw        $t0, 0xc0($s1)
c09580e0  beqz      $v0, 0xc0958094
c09580e4  nop       
c09580e8  jal       0xc0958600
c09580ec  move      $a0, $s0
c09580f0  beqz      $v0, 0xc0958094
c09580f4  nop       
c09580f8  lui       $t0, 0xc095
c09580fc  addiu     $a2, $zero, 0
c0958100  addiu     $a1, $t0, 0x1f04 ; string candidate 'MinDACSampleRate'
c0958104  jal       0xc0957e10
c0958108  move      $a0, $s1
c095810c  lui       $t0, 0xc095
c0958110  addiu     $a2, $zero, 0
c0958114  addiu     $a1, $t0, 0x1ee0 ; string candidate 'MinADCSampleRate'
c0958118  move      $a0, $s1
c095811c  jal       0xc0957e10
c0958120  sw        $v0, ($s0)
c0958124  lw        $t0, ($s0)
c0958128  sw        $v0, 0xcc($s1)
c095812c  bnez      $t0, 0xc0958138
c0958130  addiu     $t1, $zero, 0x1f40
c0958134  sw        $t1, ($s0)
c0958138  bnez      $v0, 0xc0958144
c095813c  nop       
c0958140  sw        $t1, 0xcc($s1)
c0958144  addiu     $a0, $s1, 0x20
c0958148  lw        $t0, ($a0)
c095814c  lw        $t0, 0x18($t0)
c0958150  jalr      $t0
c0958154  ori       $a1, $zero, 0xbb80
c0958158  addiu     $a0, $s1, 0x50
c095815c  lw        $t0, ($a0)
c0958160  lw        $t0, 0x18($t0)
c0958164  jalr      $t0
c0958168  ori       $a1, $zero, 0xbb80
c095816c  addiu     $a0, $zero, 0x100
c0958170  sw        $a0, 0xe4($s1)
c0958174  jal       0xc09584ac
c0958178  move      $a0, $s0
c095817c  addiu     $a1, $s1, 0xac
c0958180  jal       0xc095842c
c0958184  move      $a0, $s0
c0958188  jal       0xc0957fc0
c095818c  move      $a0, $s1
c0958190  beqz      $v0, 0xc095820c
c0958194  nop       
c0958198  lui       $t0, 0xc095
c095819c  addiu     $s0, $t0, 0x1c34 ; string candidate 'EnableSpdif'
c09581a0  addiu     $a2, $zero, 0
c09581a4  move      $a1, $s0
c09581a8  jal       0xc0957914
c09581ac  move      $a0, $s1
c09581b0  lw        $t0, 0x90($s1)
c09581b4  beq       $v0, $t0, 0xc09581d0
c09581b8  nop       
c09581bc  move      $a2, $v0
c09581c0  move      $a1, $s0
c09581c4  move      $a0, $s1
c09581c8  jal       0xc095799c
c09581cc  sw        $v0, 0x90($s1)
c09581d0  lui       $t0, 0xc095
c09581d4  addiu     $s0, $t0, 0x1c80 ; string candidate 'EnableSpdifWmaPro'
c09581d8  addiu     $a2, $zero, 0
c09581dc  move      $a1, $s0
c09581e0  jal       0xc0957914
c09581e4  move      $a0, $s1
c09581e8  move      $a2, $v0
c09581ec  move      $a1, $s0
c09581f0  move      $a0, $s1
c09581f4  jal       0xc095799c
c09581f8  sw        $v0, 0x94($s1)
c09581fc  jal       0xc09572bc
c0958200  nop       
c0958204  addiu     $a0, $zero, 1
c0958208  sw        $a0, 0x18($s1)
c095820c  lw        $v0, 0x18($s1)
c0958210  lw        $s1, 0x10($sp)
c0958214  lw        $s0, 0x14($sp)
c0958218  lw        $ra, 0x18($sp)
c095821c  jr        $ra
c0958220  addiu     $sp, $sp, 0x20
c0958224  addiu     $sp, $sp, -0x20
c0958228  sw        $ra, 0x18($sp)
c095822c  sw        $s1, 0x10($sp)
c0958230  sw        $s0, 0x14($sp)
c0958234  lui       $s1, 0xc096
c0958238  lw        $t0, -0x5ec4($s1)
c095823c  beqz      $t0, 0xc095824c
c0958240  move      $s0, $a0
c0958244  b         0xc095828c
c0958248  addiu     $v0, $zero, 1
c095824c  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0958250  addiu     $a0, $zero, 0xe8
c0958254  beqz      $v0, 0xc095826c
c0958258  nop       
c095825c  jal       0xc0957ed8
c0958260  move      $a0, $v0
c0958264  b         0xc0958270
c0958268  nop       
c095826c  move      $v0, $zero
c0958270  bnez      $v0, 0xc0958280
c0958274  sw        $v0, -0x5ec4($s1)
c0958278  b         0xc095828c
c095827c  move      $v0, $zero
c0958280  move      $a1, $s0
c0958284  jal       0xc0958074
c0958288  move      $a0, $v0
c095828c  lw        $s1, 0x10($sp)
c0958290  lw        $s0, 0x14($sp)
c0958294  lw        $ra, 0x18($sp)
c0958298  jr        $ra
c095829c  addiu     $sp, $sp, 0x20
c095842c  addiu     $sp, $sp, -0x20
c0958430  sw        $ra, 0x1c($sp)
c0958434  sw        $s2, 0x10($sp)
c0958438  sw        $s1, 0x14($sp)
c095843c  sw        $s0, 0x18($sp)
c0958440  move      $s0, $a0
c0958444  lw        $a0, 0x18($s0)
c0958448  jal       0xc0958974 ; import thunk CEDDK.dll!HalGetDMAHwIntr
c095844c  move      $s2, $a1
c0958450  lw        $a0, 0x14($s0)
c0958454  jal       0xc0958974 ; import thunk CEDDK.dll!HalGetDMAHwIntr
c0958458  move      $s1, $v0
c095845c  sll       $t0, $v0, 8
c0958460  or        $a2, $t0, $s1
c0958464  addiu     $a3, $zero, 0
c0958468  addiu     $a1, $zero, 0
c095846c  jal       0xc0958964 ; import thunk CEDDK.dll!InterruptConnect
c0958470  addiu     $a0, $zero, 0
c0958474  bnez      $v0, 0xc0958490
c0958478  sw        $v0, ($s2)
c095847c  lui       $t0, 0xc095
c0958480  jal       0xc0958854 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0958484  addiu     $a0, $t0, 0x1fd8
c0958488  b         0xc0958494
c095848c  move      $v0, $zero
c0958490  addiu     $v0, $zero, 1
c0958494  lw        $s2, 0x10($sp)
c0958498  lw        $s1, 0x14($sp)
c095849c  lw        $s0, 0x18($sp)
c09584a0  lw        $ra, 0x1c($sp)
c09584a4  jr        $ra
c09584a8  addiu     $sp, $sp, 0x20
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
c0958600  jr        $ra
c0958604  addiu     $v0, $zero, 1
