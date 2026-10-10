; Blue.exe 5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b
00018220  lui       $t0, 0x21
00018224  lw        $t0, -0x1e18($t0)
00018228  lw        $t0, 0x268($t0)
0001822c  jr        $ra
00018230  lbu       $v0, 0x11c($t0)
00018260  lui       $t0, 0x21
00018264  lw        $t0, -0x1e18($t0)
00018268  lw        $t0, 0x268($t0)
0001826c  jr        $ra
00018270  lbu       $v0, 0x11d($t0)
000183a8  addiu     $sp, $sp, -0x30
000183ac  sw        $ra, 0x28($sp)
000183b0  sw        $s1, 0x20($sp)
000183b4  sw        $s0, 0x24($sp)
000183b8  lui       $t0, 0x11
000183bc  lw        $t0, 0xea4($t0)
000183c0  move      $s1, $a2
000183c4  move      $s0, $a1
000183c8  sw        $t0, 0x18($sp)
000183cc  addiu     $t0, $zero, 0x5c
000183d0  addiu     $t1, $zero, 0x2d
000183d4  sb        $t0, 0x13($sp)
000183d8  sb        $t0, 0x17($sp)
000183dc  lbu       $t0, 0xe($s0)
000183e0  sb        $t1, 0x12($sp)
000183e4  sb        $t1, 0x16($sp)
000183e8  addiu     $t1, $zero, 0x18
000183ec  mult      $t0, $t1
000183f0  addiu     $t3, $zero, 0x7c
000183f4  addiu     $t2, $zero, 0x2f
000183f8  sb        $t3, 0x10($sp)
000183fc  sb        $t2, 0x11($sp)
00018400  sb        $t3, 0x14($sp)
00018404  sb        $t2, 0x15($sp)
00018408  addiu     $t3, $zero, 3
0001840c  mflo      $t0
00018410  addu      $t1, $t0, $s0
00018414  lbu       $t2, 0x21($t1)
00018418  bne       $t2, $t3, 0x18460
0001841c  nop       
00018420  lui       $t4, 0xf
00018424  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00018428  addiu     $a0, $t4, 0x304c ; string candidate '[BLUE]'
0001842c  lui       $a0, 0xf
00018430  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00018434  addiu     $a0, $a0, 0x5cf8 ; string candidate 'BtAvAppHandler::HandleAvQosInd'
00018438  lbu       $a0, 0xd9($s0)
0001843c  lhu       $t2, 4($s1)
00018440  addiu     $t0, $sp, 0x10
00018444  addu      $t0, $a0, $t0
00018448  lb        $t1, ($t0)
0001844c  lui       $t3, 0xf
00018450  move      $a2, $t1
00018454  move      $a1, $t2
00018458  jal       0x34264
0001845c  addiu     $a0, $t3, 0x5cc0
00018460  lbu       $t0, 0xd9($s0)
00018464  addiu     $t1, $t0, 1
00018468  andi      $t2, $t1, 0xff
0001846c  move      $t3, $t2
00018470  addiu     $t4, $zero, 8
00018474  div       $zero, $t3, $t4
00018478  mfhi      $t3
0001847c  jal       0x259f8
00018480  sb        $t3, 0xd9($s0)
00018484  lhu       $a2, 4($s1)
00018488  move      $a1, $s0
0001848c  jal       0x25fc8
00018490  move      $a0, $v0
00018494  jal       0x8ac24
00018498  lw        $a0, 0x18($sp)
0001849c  lw        $s1, 0x20($sp)
000184a0  lw        $s0, 0x24($sp)
000184a4  lw        $ra, 0x28($sp)
000184a8  jr        $ra
000184ac  addiu     $sp, $sp, 0x30
0001ace4  addiu     $sp, $sp, -0x40
0001ace8  sw        $ra, 0x3c($sp)
0001acec  sw        $fp, 0x18($sp)
0001acf0  sw        $s7, 0x1c($sp)
0001acf4  sw        $s6, 0x20($sp)
0001acf8  sw        $s5, 0x24($sp)
0001acfc  sw        $s4, 0x28($sp)
0001ad00  sw        $s3, 0x2c($sp)
0001ad04  sw        $s2, 0x30($sp)
0001ad08  sw        $s1, 0x34($sp)
0001ad0c  sw        $s0, 0x38($sp)
0001ad10  move      $s0, $a2
0001ad14  lw        $t0, 4($s0)
0001ad18  lui       $t6, 0x21
0001ad1c  lw        $t4, -0x1e18($t6)
0001ad20  lbu       $t1, ($t0)
0001ad24  lw        $s7, 0x26c($t4)
0001ad28  move      $s5, $a1
0001ad2c  move      $s6, $zero
0001ad30  move      $fp, $zero
0001ad34  move      $s1, $zero
0001ad38  move      $t3, $t1
0001ad3c  addiu     $t5, $zero, 0x18
0001ad40  mult      $s1, $t5
0001ad44  mflo      $t0
0001ad48  addu      $t1, $t0, $s5
0001ad4c  lbu       $t2, 0x27($t1)
0001ad50  beq       $t2, $t3, 0x1ad70
0001ad54  addiu     $t1, $zero, 1
0001ad58  addiu     $t2, $s1, 1
0001ad5c  andi      $s1, $t2, 0xff
0001ad60  sltiu     $t0, $s1, 1
0001ad64  bnez      $t0, 0x1ad40
0001ad68  nop       
0001ad6c  move      $s1, $t1
0001ad70  sltiu     $t0, $s1, 1
0001ad74  lui       $t1, 0xf
0001ad78  lui       $t2, 0xf
0001ad7c  move      $s2, $zero
0001ad80  sw        $t0, 0x14($sp)
0001ad84  addiu     $s3, $t1, 0x7990 ; string candidate 'BtAvAppHandler::HandleAvStartInd'
0001ad88  addiu     $s4, $t2, 0x304c ; string candidate '[BLUE]'
0001ad8c  beqz      $t0, 0x1af30
0001ad90  addiu     $t6, $zero, 2
0001ad94  lbu       $t0, 3($s0)
0001ad98  beqz      $t0, 0x1af50
0001ad9c  move      $s6, $zero
0001ada0  mult      $s1, $t5
0001ada4  mflo      $t1
0001ada8  addu      $t3, $t1, $s5
0001adac  sw        $t3, 0x10($sp)
0001adb0  lw        $t0, 4($s0)
0001adb4  lbu       $t2, 0x27($t3)
0001adb8  addu      $t1, $s6, $t0
0001adbc  lbu       $fp, ($t1)
0001adc0  bne       $fp, $t2, 0x1af28
0001adc4  nop       
0001adc8  lbu       $t3, 0x21($t3)
0001adcc  bne       $t3, $t6, 0x1af20
0001add0  nop       
0001add4  lw        $t1, 0x268($t4)
0001add8  lbu       $t0, 0x11c($t1)
0001addc  beqz      $t0, 0x1af00
0001ade0  nop       
0001ade4  jal       0x259f8
0001ade8  sb        $zero, 0x11d($t1)
0001adec  addiu     $a2, $zero, 5
0001adf0  move      $a1, $s5
0001adf4  jal       0x25a5c
0001adf8  move      $a0, $v0
0001adfc  bnez      $v0, 0x1ae24
0001ae00  nop       
0001ae04  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae08  move      $a0, $s4
0001ae0c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae10  move      $a0, $s3
0001ae14  lui       $t1, 0xf
0001ae18  addiu     $t0, $t1, 0x7940
0001ae1c  jal       0x34264
0001ae20  move      $a0, $t0
0001ae24  jal       0x259f8
0001ae28  nop       
0001ae2c  addiu     $a2, $zero, 3
0001ae30  move      $a1, $s5
0001ae34  jal       0x25a5c
0001ae38  move      $a0, $v0
0001ae3c  bnez      $v0, 0x1ae64
0001ae40  nop       
0001ae44  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae48  move      $a0, $s4
0001ae4c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae50  move      $a0, $s3
0001ae54  lui       $t1, 0xf
0001ae58  addiu     $t0, $t1, 0x78f0
0001ae5c  jal       0x34264
0001ae60  move      $a0, $t0
0001ae64  jal       0x259f8
0001ae68  nop       
0001ae6c  addiu     $a2, $zero, 2
0001ae70  move      $a1, $s5
0001ae74  jal       0x25a5c
0001ae78  move      $a0, $v0
0001ae7c  bnez      $v0, 0x1aea4
0001ae80  nop       
0001ae84  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae88  move      $a0, $s4
0001ae8c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ae90  move      $a0, $s3
0001ae94  lui       $t1, 0xf
0001ae98  addiu     $t0, $t1, 0x78a4
0001ae9c  jal       0x34264
0001aea0  move      $a0, $t0
0001aea4  jal       0x259f8
0001aea8  nop       
0001aeac  addiu     $a2, $zero, 4
0001aeb0  move      $a1, $s5
0001aeb4  jal       0x25a5c
0001aeb8  move      $a0, $v0
0001aebc  bnez      $v0, 0x1aee4
0001aec0  nop       
0001aec4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001aec8  move      $a0, $s4
0001aecc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001aed0  move      $a0, $s3
0001aed4  lui       $t1, 0xf
0001aed8  addiu     $t0, $t1, 0x7854
0001aedc  jal       0x34264
0001aee0  move      $a0, $t0
0001aee4  lui       $t2, 0x21
0001aee8  lw        $t0, -0x1e18($t2)
0001aeec  addiu     $t1, $zero, 1
0001aef0  lw        $t0, 0x268($t0)
0001aef4  addiu     $t6, $zero, 2
0001aef8  sb        $t1, 0x11d($t0)
0001aefc  lw        $t4, -0x1e18($t2)
0001af00  addiu     $t1, $s6, 1
0001af04  lbu       $t0, 3($s0)
0001af08  andi      $s6, $t1, 0xff
0001af0c  sltu      $t2, $s6, $t0
0001af10  bnez      $t2, 0x1adb0
0001af14  lw        $t3, 0x10($sp)
0001af18  b         0x1af50
0001af1c  nop       
0001af20  b         0x1af50
0001af24  addiu     $s2, $zero, 0x31
0001af28  b         0x1af50
0001af2c  addiu     $s2, $zero, 0x12
0001af30  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001af34  move      $a0, $s4
0001af38  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001af3c  move      $a0, $s3
0001af40  lui       $t0, 0xf
0001af44  move      $a1, $s1
0001af48  jal       0x34264
0001af4c  addiu     $a0, $t0, 0x4bec
0001af50  bnez      $s2, 0x1b020
0001af54  nop       
0001af58  lbu       $t0, 3($s0)
0001af5c  bne       $s6, $t0, 0x1b020
0001af60  nop       
0001af64  jal       0x85b70
0001af68  addiu     $a0, $zero, 0x10
0001af6c  addiu     $t0, $zero, 0x1a
0001af70  sh        $t0, ($v0)
0001af74  sb        $zero, 3($v0)
0001af78  lbu       $t0, 2($s0)
0001af7c  move      $a0, $v0
0001af80  sb        $t0, 2($v0)
0001af84  sb        $zero, 0xc($v0)
0001af88  lbu       $t1, 3($s0)
0001af8c  sb        $t1, 4($v0)
0001af90  lw        $t2, 4($s0)
0001af94  jal       0x7815c
0001af98  sw        $t2, 8($v0)
0001af9c  lw        $a0, 0x14($sp)
0001afa0  beqz      $a0, 0x1afc0
0001afa4  nop       
0001afa8  addiu     $t0, $zero, 0x18
0001afac  mult      $s1, $t0
0001afb0  addiu     $t2, $zero, 3
0001afb4  mflo      $t0
0001afb8  addu      $t1, $t0, $s5
0001afbc  sb        $t2, 0x21($t1)
0001afc0  lbu       $t2, 0x20c($s7)
0001afc4  bnez      $t2, 0x1afe8
0001afc8  nop       
0001afcc  lui       $a1, 0x307
0001afd0  addiu     $t0, $zero, 1
0001afd4  addiu     $a2, $zero, 0
0001afd8  ori       $a1, $a1, 0x801
0001afdc  addiu     $a0, $zero, 2
0001afe0  jal       0x33538
0001afe4  sb        $t0, 0x218($s7)
0001afe8  lui       $a1, 0x307
0001afec  addiu     $a2, $zero, 1
0001aff0  ori       $a1, $a1, 0x1101
0001aff4  jal       0x33538
0001aff8  addiu     $a0, $zero, 2
0001affc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b000  move      $a0, $s4
0001b004  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b008  move      $a0, $s3
0001b00c  lui       $a0, 0xf
0001b010  jal       0x34264
0001b014  addiu     $a0, $a0, 0x782c
0001b018  b         0x1b058
0001b01c  nop       
0001b020  jal       0x85b70
0001b024  addiu     $a0, $zero, 0x10
0001b028  addiu     $t0, $zero, 0x1a
0001b02c  sh        $t0, ($v0)
0001b030  sb        $fp, 3($v0)
0001b034  lbu       $t0, 2($s0)
0001b038  move      $a0, $v0
0001b03c  sb        $t0, 2($v0)
0001b040  sb        $s2, 0xc($v0)
0001b044  lbu       $t1, 3($s0)
0001b048  sb        $t1, 4($v0)
0001b04c  lw        $t2, 4($s0)
0001b050  jal       0x7815c
0001b054  sw        $t2, 8($v0)
0001b058  lw        $fp, 0x18($sp)
0001b05c  lw        $s7, 0x1c($sp)
0001b060  lw        $s6, 0x20($sp)
0001b064  lw        $s5, 0x24($sp)
0001b068  lw        $s4, 0x28($sp)
0001b06c  lw        $s3, 0x2c($sp)
0001b070  lw        $s2, 0x30($sp)
0001b074  lw        $s1, 0x34($sp)
0001b078  lw        $s0, 0x38($sp)
0001b07c  lw        $ra, 0x3c($sp)
0001b080  jr        $ra
0001b084  addiu     $sp, $sp, 0x40
0001b1dc  addiu     $sp, $sp, -0x28
0001b1e0  sw        $ra, 0x24($sp)
0001b1e4  sw        $s4, 0x10($sp)
0001b1e8  sw        $s3, 0x14($sp)
0001b1ec  sw        $s2, 0x18($sp)
0001b1f0  sw        $s1, 0x1c($sp)
0001b1f4  sw        $s0, 0x20($sp)
0001b1f8  lui       $t0, 0x21
0001b1fc  lw        $t0, -0x1e18($t0)
0001b200  move      $s1, $a2
0001b204  lw        $s3, 0x26c($t0)
0001b208  lbu       $t0, 2($s1)
0001b20c  move      $s2, $a1
0001b210  move      $s0, $zero
0001b214  move      $t3, $t0
0001b218  addiu     $t4, $zero, 0x18
0001b21c  mult      $s0, $t4
0001b220  mflo      $t1
0001b224  addu      $t0, $t1, $s2
0001b228  lbu       $t2, 0x27($t0)
0001b22c  beq       $t2, $t3, 0x1b24c
0001b230  addiu     $s4, $zero, 1
0001b234  addiu     $t2, $s0, 1
0001b238  andi      $s0, $t2, 0xff
0001b23c  sltiu     $t0, $s0, 1
0001b240  bnez      $t0, 0x1b21c
0001b244  nop       
0001b248  move      $s0, $s4
0001b24c  sltiu     $t0, $s0, 1
0001b250  beqz      $t0, 0x1b338
0001b254  nop       
0001b258  mult      $s0, $t4
0001b25c  mflo      $t1
0001b260  addu      $s0, $t1, $s2
0001b264  lbu       $t2, 0x27($s0)
0001b268  bne       $t3, $t2, 0x1b300
0001b26c  addiu     $a0, $zero, 6
0001b270  lbu       $t0, 0x26($s0)
0001b274  sb        $zero, 0x22($s0)
0001b278  addu      $t3, $t0, $s2
0001b27c  sb        $zero, 0x3c($t3)
0001b280  lbu       $t1, 0x26($s0)
0001b284  addu      $t4, $t1, $s2
0001b288  jal       0x85b70
0001b28c  sb        $zero, 0x40($t4)
0001b290  addiu     $t0, $zero, 0x1b
0001b294  sh        $t0, ($v0)
0001b298  lbu       $t0, 2($s1)
0001b29c  move      $a0, $v0
0001b2a0  sb        $t0, 2($v0)
0001b2a4  lbu       $t1, 3($s1)
0001b2a8  sb        $t1, 3($v0)
0001b2ac  jal       0x7815c
0001b2b0  sb        $zero, 4($v0)
0001b2b4  jal       0x259f8
0001b2b8  sb        $s4, 0x21($s0)
0001b2bc  addiu     $a2, $zero, 3
0001b2c0  move      $a1, $s2
0001b2c4  jal       0x25a5c
0001b2c8  move      $a0, $v0
0001b2cc  bnez      $v0, 0x1b360
0001b2d0  nop       
0001b2d4  lui       $t0, 0xf
0001b2d8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b2dc  addiu     $a0, $t0, 0x304c ; string candidate '[BLUE]'
0001b2e0  lui       $a0, 0xf
0001b2e4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b2e8  addiu     $a0, $a0, 0x7aec ; string candidate 'BtAvAppHandler::HandleAvCloseInd'
0001b2ec  lui       $a0, 0xf
0001b2f0  jal       0x34264
0001b2f4  addiu     $a0, $a0, 0x7a90
0001b2f8  b         0x1b360
0001b2fc  nop       
0001b300  jal       0x85b70
0001b304  nop       
0001b308  addiu     $t0, $zero, 0x1b
0001b30c  sh        $t0, ($v0)
0001b310  lbu       $t0, 2($s1)
0001b314  addiu     $t2, $zero, 0x12
0001b318  sb        $t0, 2($v0)
0001b31c  lbu       $t1, 3($s1)
0001b320  move      $a0, $v0
0001b324  sb        $t1, 3($v0)
0001b328  jal       0x7815c
0001b32c  sb        $t2, 4($v0)
0001b330  b         0x1b360
0001b334  nop       
0001b338  lui       $t0, 0xf
0001b33c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b340  addiu     $a0, $t0, 0x304c ; string candidate '[BLUE]'
0001b344  lui       $a0, 0xf
0001b348  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b34c  addiu     $a0, $a0, 0x7aec ; string candidate 'BtAvAppHandler::HandleAvCloseInd'
0001b350  lui       $t0, 0xf
0001b354  move      $a1, $s0
0001b358  jal       0x34264
0001b35c  addiu     $a0, $t0, 0x4bec
0001b360  sb        $zero, 0x218($s3)
0001b364  lw        $s4, 0x10($sp)
0001b368  lw        $s3, 0x14($sp)
0001b36c  lw        $s2, 0x18($sp)
0001b370  lw        $s1, 0x1c($sp)
0001b374  lw        $s0, 0x20($sp)
0001b378  lw        $ra, 0x24($sp)
0001b37c  jr        $ra
0001b380  addiu     $sp, $sp, 0x28
0001b87c  addiu     $sp, $sp, -0x40
0001b880  sw        $ra, 0x3c($sp)
0001b884  sw        $fp, 0x18($sp)
0001b888  sw        $s7, 0x1c($sp)
0001b88c  sw        $s6, 0x20($sp)
0001b890  sw        $s5, 0x24($sp)
0001b894  sw        $s4, 0x28($sp)
0001b898  sw        $s3, 0x2c($sp)
0001b89c  sw        $s2, 0x30($sp)
0001b8a0  sw        $s1, 0x34($sp)
0001b8a4  sw        $s0, 0x38($sp)
0001b8a8  move      $s3, $a2
0001b8ac  lbu       $t0, 2($s3)
0001b8b0  move      $s2, $a1
0001b8b4  move      $s0, $zero
0001b8b8  move      $s1, $zero
0001b8bc  move      $t3, $t0
0001b8c0  addiu     $s7, $zero, 0x18
0001b8c4  mult      $s1, $s7
0001b8c8  mflo      $t1
0001b8cc  addu      $t0, $t1, $s2
0001b8d0  lbu       $t2, 0x27($t0)
0001b8d4  beq       $t2, $t3, 0x1b8f4
0001b8d8  addiu     $fp, $zero, 1
0001b8dc  addiu     $t2, $s1, 1
0001b8e0  andi      $s1, $t2, 0xff
0001b8e4  sltiu     $t0, $s1, 1
0001b8e8  bnez      $t0, 0x1b8c4
0001b8ec  nop       
0001b8f0  move      $s1, $fp
0001b8f4  lui       $t1, 0xf
0001b8f8  lui       $t2, 0xf
0001b8fc  lw        $s4, 8($s3)
0001b900  sltiu     $t0, $s1, 1
0001b904  addiu     $s5, $t1, 0x7f30 ; string candidate 'BtAvAppHandler::HandleAvReconfigureInd'
0001b908  beqz      $t0, 0x1bb7c
0001b90c  addiu     $s6, $t2, 0x304c ; string candidate '[BLUE]'
0001b910  mult      $s1, $s7
0001b914  mflo      $t0
0001b918  addu      $t1, $t0, $s2
0001b91c  lbu       $t2, 0x27($t1)
0001b920  bne       $t2, $t3, 0x1bb74
0001b924  nop       
0001b928  lbu       $t3, 0xe($s2)
0001b92c  mult      $t3, $s7
0001b930  mflo      $t4
0001b934  addu      $t0, $t4, $s2
0001b938  lbu       $t1, 0x26($t0)
0001b93c  addu      $t5, $t1, $s2
0001b940  lbu       $t2, 0x3c($t5)
0001b944  bne       $t2, $fp, 0x1ba00
0001b948  nop       
0001b94c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b950  move      $a0, $s6
0001b954  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001b958  move      $a0, $s5
0001b95c  lui       $a0, 0xf
0001b960  jal       0x34264
0001b964  addiu     $a0, $a0, 0x7edc
0001b968  sh        $zero, 0x10($sp)
0001b96c  beqz      $s4, 0x1ba04
0001b970  move      $s0, $zero
0001b974  lbu       $t0, ($s4)
0001b978  move      $t1, $t0
0001b97c  addiu     $t2, $zero, 7
0001b980  bne       $t1, $t2, 0x1b9b8
0001b984  nop       
0001b988  jal       0x259f8
0001b98c  nop       
0001b990  addiu     $a3, $zero, 0
0001b994  move      $a2, $s4
0001b998  move      $a1, $s2
0001b99c  jal       0x260c8
0001b9a0  move      $a0, $v0
0001b9a4  move      $s0, $v0
0001b9a8  beqz      $s0, 0x1ba0c
0001b9ac  nop       
0001b9b0  b         0x1b9d4
0001b9b4  nop       
0001b9b8  bne       $t1, $fp, 0x1b9c8
0001b9bc  nop       
0001b9c0  b         0x1b9d8
0001b9c4  addiu     $s0, $zero, 0x1a
0001b9c8  sltiu     $t0, $t1, 8
0001b9cc  beqz      $t0, 0x1b9d8
0001b9d0  addiu     $s0, $zero, 0x17
0001b9d4  addiu     $s0, $zero, 0x29
0001b9d8  lhu       $a2, 4($s3)
0001b9dc  lw        $a1, 8($s3)
0001b9e0  addiu     $a3, $sp, 0x10
0001b9e4  jal       0x78184
0001b9e8  ori       $a0, $zero, 0xffff
0001b9ec  move      $s4, $v0
0001b9f0  bnez      $s4, 0x1b974
0001b9f4  nop       
0001b9f8  b         0x1ba04
0001b9fc  nop       
0001ba00  addiu     $s0, $zero, 0x14
0001ba04  bnez      $s0, 0x1bb9c
0001ba08  nop       
0001ba0c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ba10  move      $a0, $s6
0001ba14  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ba18  move      $a0, $s5
0001ba1c  lui       $a0, 0xf
0001ba20  jal       0x34264
0001ba24  addiu     $a0, $a0, 0x7e64
0001ba28  lui       $s1, 0x21
0001ba2c  lw        $t0, -0x1e18($s1)
0001ba30  lw        $t1, 0x268($t0)
0001ba34  lbu       $t0, 0x11c($t1)
0001ba38  beqz      $t0, 0x1bac4
0001ba3c  nop       
0001ba40  jal       0x259f8
0001ba44  sb        $zero, 0x11d($t1)
0001ba48  addiu     $a2, $zero, 3
0001ba4c  move      $a1, $s2
0001ba50  jal       0x25a5c
0001ba54  move      $a0, $v0
0001ba58  bnez      $v0, 0x1ba7c
0001ba5c  nop       
0001ba60  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ba64  move      $a0, $s6
0001ba68  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001ba6c  move      $a0, $s5
0001ba70  lui       $a0, 0xf
0001ba74  jal       0x34264
0001ba78  addiu     $a0, $a0, 0x7940
0001ba7c  jal       0x259f8
0001ba80  nop       
0001ba84  addiu     $a2, $zero, 2
0001ba88  move      $a1, $s2
0001ba8c  jal       0x25a5c
0001ba90  move      $a0, $v0
0001ba94  bnez      $v0, 0x1bab8
0001ba98  nop       
0001ba9c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001baa0  move      $a0, $s6
0001baa4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001baa8  move      $a0, $s5
0001baac  lui       $a0, 0xf
0001bab0  jal       0x34264
0001bab4  addiu     $a0, $a0, 0x7e14
0001bab8  lw        $t0, -0x1e18($s1)
0001babc  lw        $t0, 0x268($t0)
0001bac0  sb        $fp, 0x11d($t0)
0001bac4  jal       0x85b70
0001bac8  addiu     $a0, $zero, 6
0001bacc  sh        $s7, ($v0)
0001bad0  lbu       $t0, 2($s3)
0001bad4  move      $a0, $v0
0001bad8  sb        $t0, 2($v0)
0001badc  lbu       $t1, 3($s3)
0001bae0  sb        $t1, 3($v0)
0001bae4  sb        $zero, 4($v0)
0001bae8  jal       0x7815c
0001baec  sb        $zero, 5($v0)
0001baf0  lbu       $a0, 0x1d($s2)
0001baf4  bnez      $a0, 0x1bb9c
0001baf8  nop       
0001bafc  lbu       $t0, 0xe($s2)
0001bb00  mult      $t0, $s7
0001bb04  mflo      $t1
0001bb08  addu      $t2, $t1, $s2
0001bb0c  lbu       $t3, 0x26($t2)
0001bb10  addu      $t4, $t3, $s2
0001bb14  lbu       $t5, 0x40($t4)
0001bb18  beqz      $t5, 0x1bb9c
0001bb1c  nop       
0001bb20  jal       0x85b70
0001bb24  addiu     $a0, $zero, 8
0001bb28  addiu     $t0, $zero, 0x21
0001bb2c  addiu     $t1, $zero, 0x190
0001bb30  sh        $t1, 4($v0)
0001bb34  sh        $t0, ($v0)
0001bb38  lbu       $t0, 2($s3)
0001bb3c  addiu     $t3, $zero, 0x10
0001bb40  sb        $t0, 6($v0)
0001bb44  lbu       $t1, 0x44($s2)
0001bb48  move      $t2, $t1
0001bb4c  div       $zero, $t2, $t3
0001bb50  move      $a0, $v0
0001bb54  mfhi      $t2
0001bb58  sb        $t2, 2($v0)
0001bb5c  lbu       $t0, 0x44($s2)
0001bb60  addiu     $t1, $t0, 1
0001bb64  jal       0x7815c
0001bb68  sb        $t1, 0x44($s2)
0001bb6c  b         0x1bb9c
0001bb70  nop       
0001bb74  b         0x1bb9c
0001bb78  addiu     $s0, $zero, 0x12
0001bb7c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001bb80  move      $a0, $s6
0001bb84  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001bb88  move      $a0, $s5
0001bb8c  lui       $t0, 0xf
0001bb90  move      $a1, $s1
0001bb94  jal       0x34264
0001bb98  addiu     $a0, $t0, 0x4bec
0001bb9c  beqz      $s0, 0x1bc00
0001bba0  lw        $s1, 8($s3)
0001bba4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001bba8  move      $a0, $s6
0001bbac  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001bbb0  move      $a0, $s5
0001bbb4  lui       $a0, 0xf
0001bbb8  jal       0x34264
0001bbbc  addiu     $a0, $a0, 0x7d88
0001bbc0  beqz      $s1, 0x1bc08
0001bbc4  nop       
0001bbc8  jal       0x85b70
0001bbcc  addiu     $a0, $zero, 6
0001bbd0  sh        $s7, ($v0)
0001bbd4  lbu       $t0, 2($s3)
0001bbd8  move      $a0, $v0
0001bbdc  sb        $t0, 2($v0)
0001bbe0  lbu       $t1, 3($s3)
0001bbe4  sb        $t1, 3($v0)
0001bbe8  lbu       $t2, ($s1)
0001bbec  sb        $t2, 4($v0)
0001bbf0  jal       0x7815c
0001bbf4  sb        $s0, 5($v0)
0001bbf8  b         0x1bc08
0001bbfc  nop       
0001bc00  jal       0x85bb8
0001bc04  move      $a0, $s1
0001bc08  lw        $fp, 0x18($sp)
0001bc0c  lw        $s7, 0x1c($sp)
0001bc10  lw        $s6, 0x20($sp)
0001bc14  lw        $s5, 0x24($sp)
0001bc18  lw        $s4, 0x28($sp)
0001bc1c  lw        $s3, 0x2c($sp)
0001bc20  lw        $s2, 0x30($sp)
0001bc24  lw        $s1, 0x34($sp)
0001bc28  lw        $s0, 0x38($sp)
0001bc2c  lw        $ra, 0x3c($sp)
0001bc30  jr        $ra
0001bc34  addiu     $sp, $sp, 0x40
0001cb6c  addiu     $sp, $sp, -0x28
0001cb70  sw        $ra, 0x24($sp)
0001cb74  sw        $s4, 0x10($sp)
0001cb78  sw        $s3, 0x14($sp)
0001cb7c  sw        $s2, 0x18($sp)
0001cb80  sw        $s1, 0x1c($sp)
0001cb84  sw        $s0, 0x20($sp)
0001cb88  lui       $t0, 0x21
0001cb8c  lw        $t0, -0x1e18($t0)
0001cb90  jal       0x259f8
0001cb94  lw        $s3, 0x268($t0)
0001cb98  jal       0x19410
0001cb9c  move      $s4, $v0
0001cba0  lui       $t0, 0xf
0001cba4  addiu     $s0, $t0, 0x304c ; string candidate '[BLUE]'
0001cba8  move      $a0, $s0
0001cbac  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cbb0  move      $s2, $v0
0001cbb4  lui       $a0, 0x10
0001cbb8  addiu     $s1, $a0, -0x7b58 ; string candidate 'BtAvrcpAppHandler::BLUE_AVRCP_Streaming_Navi_StartReq'
0001cbbc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cbc0  move      $a0, $s1
0001cbc4  lui       $a0, 0x10
0001cbc8  jal       0x34264
0001cbcc  addiu     $a0, $a0, -0x7b64
0001cbd0  lbu       $a1, 0xe($s3)
0001cbd4  addiu     $t0, $zero, 0x18
0001cbd8  mult      $a1, $t0
0001cbdc  mflo      $t0
0001cbe0  addu      $t1, $t0, $s3
0001cbe4  lbu       $t2, 0x21($t1)
0001cbe8  bnez      $t2, 0x1cc14
0001cbec  nop       
0001cbf0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cbf4  move      $a0, $s0
0001cbf8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cbfc  move      $a0, $s1
0001cc00  lui       $a0, 0x10
0001cc04  jal       0x34264
0001cc08  addiu     $a0, $a0, -0x7ba4
0001cc0c  b         0x1cc8c
0001cc10  nop       
0001cc14  jal       0x1816c
0001cc18  move      $a0, $s2
0001cc1c  addiu     $a2, $zero, 2
0001cc20  move      $a1, $s3
0001cc24  jal       0x25a5c
0001cc28  move      $a0, $s4
0001cc2c  bnez      $v0, 0x1cc50
0001cc30  nop       
0001cc34  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cc38  move      $a0, $s0
0001cc3c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cc40  move      $a0, $s1
0001cc44  lui       $a0, 0xf
0001cc48  jal       0x34264
0001cc4c  addiu     $a0, $a0, 0x78a4
0001cc50  addiu     $a2, $zero, 4
0001cc54  move      $a1, $s3
0001cc58  jal       0x25a5c
0001cc5c  move      $a0, $s4
0001cc60  bnez      $v0, 0x1cc84
0001cc64  nop       
0001cc68  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cc6c  move      $a0, $s0
0001cc70  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001cc74  move      $a0, $s1
0001cc78  lui       $a0, 0xf
0001cc7c  jal       0x34264
0001cc80  addiu     $a0, $a0, 0x7854
0001cc84  jal       0x18234
0001cc88  move      $a0, $s2
0001cc8c  lw        $s4, 0x10($sp)
0001cc90  lw        $s3, 0x14($sp)
0001cc94  lw        $s2, 0x18($sp)
0001cc98  lw        $s1, 0x1c($sp)
0001cc9c  lw        $s0, 0x20($sp)
0001cca0  lw        $ra, 0x24($sp)
0001cca4  jr        $ra
0001cca8  addiu     $sp, $sp, 0x28
0001ef64  addiu     $sp, $sp, -0x38
0001ef68  sw        $ra, 0x30($sp)
0001ef6c  sw        $s7, 0x10($sp)
0001ef70  sw        $s6, 0x14($sp)
0001ef74  sw        $s5, 0x18($sp)
0001ef78  sw        $s4, 0x1c($sp)
0001ef7c  sw        $s3, 0x20($sp)
0001ef80  sw        $s2, 0x24($sp)
0001ef84  sw        $s1, 0x28($sp)
0001ef88  sw        $s0, 0x2c($sp)
0001ef8c  lui       $t0, 0x21
0001ef90  lw        $t0, -0x1e18($t0)
0001ef94  lw        $s4, 0x268($t0)
0001ef98  lw        $s2, 0x26c($t0)
0001ef9c  jal       0x19410
0001efa0  move      $s6, $a0
0001efa4  jal       0x259f8
0001efa8  move      $s3, $v0
0001efac  lbu       $t0, 0xe($s4)
0001efb0  addiu     $t1, $zero, 0x18
0001efb4  mult      $t0, $t1
0001efb8  mflo      $t0
0001efbc  addu      $t1, $t0, $s4
0001efc0  lbu       $t2, 0x21($t1)
0001efc4  bnez      $t2, 0x1eff8
0001efc8  move      $s5, $v0
0001efcc  lui       $t3, 0xf
0001efd0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001efd4  addiu     $a0, $t3, 0x304c ; string candidate '[BLUE]'
0001efd8  lui       $a0, 0x10
0001efdc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001efe0  addiu     $a0, $a0, -0x6d40 ; string candidate 'BtAvrcpAppHandler::BLUE_AVRCP_PauseReq'
0001efe4  lui       $a0, 0x10
0001efe8  jal       0x34264
0001efec  addiu     $a0, $a0, -0x6d80
0001eff0  b         0x1f0f0
0001eff4  nop       
0001eff8  jal       0x18220
0001effc  move      $a0, $s3
0001f000  lui       $t0, 0x10
0001f004  lui       $t1, 0xf
0001f008  addiu     $s7, $zero, 2
0001f00c  addiu     $s0, $t0, -0x6d40 ; string candidate 'BtAvrcpAppHandler::BLUE_AVRCP_PauseReq'
0001f010  bnez      $v0, 0x1f090
0001f014  addiu     $s1, $t1, 0x304c ; string candidate '[BLUE]'
0001f018  jal       0x1816c
0001f01c  move      $a0, $s3
0001f020  addiu     $a2, $zero, 2
0001f024  move      $a1, $s4
0001f028  jal       0x25a5c
0001f02c  move      $a0, $s5
0001f030  bnez      $v0, 0x1f054
0001f034  nop       
0001f038  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f03c  move      $a0, $s1
0001f040  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f044  move      $a0, $s0
0001f048  lui       $a0, 0x10
0001f04c  jal       0x34264
0001f050  addiu     $a0, $a0, -0x6dc4
0001f054  addiu     $a2, $zero, 4
0001f058  move      $a1, $s4
0001f05c  jal       0x25a5c
0001f060  move      $a0, $s5
0001f064  bnez      $v0, 0x1f088
0001f068  nop       
0001f06c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f070  move      $a0, $s1
0001f074  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f078  move      $a0, $s0
0001f07c  lui       $a0, 0x10
0001f080  jal       0x34264
0001f084  addiu     $a0, $a0, -0x6e0c
0001f088  jal       0x18234
0001f08c  move      $a0, $s3
0001f090  lbu       $t0, 0x218($s2)
0001f094  addiu     $t1, $zero, 1
0001f098  beq       $t0, $t1, 0x1f0c4
0001f09c  move      $a0, $s1
0001f0a0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f0a4  sb        $t1, 0x218($s2)
0001f0a8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f0ac  move      $a0, $s0
0001f0b0  lui       $a0, 0x10
0001f0b4  jal       0x34264
0001f0b8  addiu     $a0, $a0, -0x6e34
0001f0bc  b         0x1f0e4
0001f0c0  addiu     $a2, $zero, 0x44
0001f0c4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f0c8  sb        $s7, 0x218($s2)
0001f0cc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0001f0d0  move      $a0, $s0
0001f0d4  lui       $a0, 0x10
0001f0d8  jal       0x34264
0001f0dc  addiu     $a0, $a0, -0x6e5c
0001f0e0  addiu     $a2, $zero, 0x46
0001f0e4  move      $a1, $s2
0001f0e8  jal       0x1eca8
0001f0ec  move      $a0, $s6
0001f0f0  lw        $s7, 0x10($sp)
0001f0f4  lw        $s6, 0x14($sp)
0001f0f8  lw        $s5, 0x18($sp)
0001f0fc  lw        $s4, 0x1c($sp)
0001f100  lw        $s3, 0x20($sp)
0001f104  lw        $s2, 0x24($sp)
0001f108  lw        $s1, 0x28($sp)
0001f10c  lw        $s0, 0x2c($sp)
0001f110  lw        $ra, 0x30($sp)
0001f114  jr        $ra
0001f118  addiu     $sp, $sp, 0x38
000207f4  addiu     $sp, $sp, -0x38
000207f8  sw        $ra, 0x30($sp)
000207fc  sw        $s7, 0x10($sp)
00020800  sw        $s6, 0x14($sp)
00020804  sw        $s5, 0x18($sp)
00020808  sw        $s4, 0x1c($sp)
0002080c  sw        $s3, 0x20($sp)
00020810  sw        $s2, 0x24($sp)
00020814  sw        $s1, 0x28($sp)
00020818  sw        $s0, 0x2c($sp)
0002081c  lui       $s7, 0x21
00020820  lw        $t0, -0x1e18($s7)
00020824  lw        $s4, 0x268($t0)
00020828  lw        $s0, 0x26c($t0)
0002082c  jal       0x259f8
00020830  move      $s3, $a0
00020834  lbu       $t1, 0xe($s4)
00020838  lw        $t0, -0x1e18($s7)
0002083c  addiu     $t2, $zero, 0x18
00020840  mult      $t1, $t2
00020844  addiu     $s6, $t0, 0x10
00020848  mflo      $t0
0002084c  addu      $t1, $t0, $s4
00020850  lbu       $t2, 0x21($t1)
00020854  bnez      $t2, 0x20888
00020858  move      $s5, $v0
0002085c  lui       $t3, 0xf
00020860  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020864  addiu     $a0, $t3, 0x304c ; string candidate '[BLUE]'
00020868  lui       $a0, 0x10
0002086c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020870  addiu     $a0, $a0, -0x6924 ; string candidate 'BtAvrcpAppHandler::BLUE_AVRCP_PlayReq'
00020874  lui       $a0, 0x10
00020878  jal       0x34264
0002087c  addiu     $a0, $a0, -0x7ba4
00020880  b         0x209dc
00020884  nop       
00020888  addiu     $a2, $zero, 2
0002088c  move      $a1, $s4
00020890  jal       0x25a5c
00020894  move      $a0, $s5
00020898  lui       $t0, 0x10
0002089c  lui       $t1, 0xf
000208a0  addiu     $s1, $t0, -0x6924 ; string candidate 'BtAvrcpAppHandler::BLUE_AVRCP_PlayReq'
000208a4  bnez      $v0, 0x208c8
000208a8  addiu     $s2, $t1, 0x304c ; string candidate '[BLUE]'
000208ac  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000208b0  move      $a0, $s2
000208b4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000208b8  move      $a0, $s1
000208bc  lui       $a0, 0x10
000208c0  jal       0x34264
000208c4  addiu     $a0, $a0, -0x6dc4
000208c8  addiu     $a2, $zero, 4
000208cc  move      $a1, $s4
000208d0  jal       0x25a5c
000208d4  move      $a0, $s5
000208d8  bnez      $v0, 0x208fc
000208dc  nop       
000208e0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000208e4  move      $a0, $s2
000208e8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000208ec  move      $a0, $s1
000208f0  lui       $a0, 0x10
000208f4  jal       0x34264
000208f8  addiu     $a0, $a0, -0x6e0c
000208fc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020900  move      $a0, $s2
00020904  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020908  move      $a0, $s1
0002090c  jal       0x31f40
00020910  move      $a0, $s6
00020914  lbu       $t0, 0x218($s0)
00020918  lui       $t1, 0x10
0002091c  move      $a2, $v0
00020920  move      $a1, $t0
00020924  jal       0x34264
00020928  addiu     $a0, $t1, -0x6f84
0002092c  jal       0x31dd4
00020930  move      $a0, $s6
00020934  beqz      $v0, 0x20974
00020938  nop       
0002093c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020940  move      $a0, $s2
00020944  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00020948  move      $a0, $s1
0002094c  lui       $a0, 0x10
00020950  jal       0x34264
00020954  addiu     $a0, $a0, -0x695c
00020958  addiu     $a2, $zero, 0x44
0002095c  move      $a1, $s0
00020960  jal       0x1eca8
00020964  move      $a0, $s3
00020968  addiu     $a0, $zero, 1
0002096c  b         0x209b4
00020970  sb        $a0, 0x218($s0)
00020974  lbu       $t0, 0x218($s0)
00020978  addiu     $s1, $zero, 1
0002097c  beq       $t0, $s1, 0x209b4
00020980  nop       
00020984  jal       0x31f40
00020988  move      $a0, $s6
0002098c  bne       $v0, $s1, 0x209b4
00020990  nop       
00020994  addiu     $a2, $zero, 0x44
00020998  move      $a1, $s0
0002099c  jal       0x1eca8
000209a0  move      $a0, $s3
000209a4  lbu       $a0, 0x20c($s0)
000209a8  bnez      $a0, 0x209b4
000209ac  nop       
000209b0  sb        $s1, 0x218($s0)
000209b4  lw        $t0, -0x1e18($s7)
000209b8  addiu     $a2, $zero, 2
000209bc  lw        $a1, 0x26c($t0)
000209c0  jal       0x1d68c
000209c4  move      $a0, $s3
000209c8  lw        $t0, -0x1e18($s7)
000209cc  lw        $a1, 0x26c($t0)
000209d0  addiu     $a2, $zero, 3
000209d4  jal       0x1d68c
000209d8  move      $a0, $s3
000209dc  lw        $s7, 0x10($sp)
000209e0  lw        $s6, 0x14($sp)
000209e4  lw        $s5, 0x18($sp)
000209e8  lw        $s4, 0x1c($sp)
000209ec  lw        $s3, 0x20($sp)
000209f0  lw        $s2, 0x24($sp)
000209f4  lw        $s1, 0x28($sp)
000209f8  lw        $s0, 0x2c($sp)
000209fc  lw        $ra, 0x30($sp)
00020a00  jr        $ra
00020a04  addiu     $sp, $sp, 0x38
0002574c  lw        $t4, ($a0)
00025750  lbu       $t0, 0x10($t4)
00025754  lbu       $t5, 0x12($t4)
00025758  subu      $t1, $t0, $a1
0002575c  addiu     $t2, $t1, 4
00025760  andi      $t6, $t2, 0xff
00025764  sltu      $t3, $t5, $t6
00025768  beqz      $t3, 0x25778
0002576c  sb        $t6, 0x10($t4)
00025770  b         0x2578c
00025774  sb        $t5, 0x10($t4)
00025778  lbu       $t1, 0x11($t4)
0002577c  sltu      $t0, $t6, $t1
00025780  beqz      $t0, 0x2578c
00025784  nop       
00025788  sb        $t1, 0x10($t4)
0002578c  jr        $ra
00025790  nop       
00025a30  lui       $t0, 0x11
00025a34  lui       $t1, 0x11
00025a38  addiu     $t0, $t0, 0x2e4
00025a3c  lui       $t2, 0x11
00025a40  addiu     $t1, $t1, 0x330
00025a44  sw        $t0, 0x9c($a1)
00025a48  addiu     $t2, $t2, 0x298
00025a4c  sw        $t1, 0xa0($a1)
00025a50  sw        $t2, 0xa4($a1)
00025a54  jr        $ra
00025a58  sw        $zero, 0xa8($a1)
00025a5c  addiu     $sp, $sp, -0x50
00025a60  sw        $ra, 0x4c($sp)
00025a64  sw        $fp, 0x28($sp)
00025a68  sw        $s7, 0x2c($sp)
00025a6c  sw        $s6, 0x30($sp)
00025a70  sw        $s5, 0x34($sp)
00025a74  sw        $s4, 0x38($sp)
00025a78  sw        $s3, 0x3c($sp)
00025a7c  sw        $s2, 0x40($sp)
00025a80  sw        $s1, 0x44($sp)
00025a84  sw        $s0, 0x48($sp)
00025a88  move      $s4, $a1
00025a8c  lbu       $t0, 0x1c($s4)
00025a90  addiu     $s1, $zero, 1
00025a94  bne       $t0, $s1, 0x25ad4
00025a98  move      $fp, $a2
00025a9c  lbu       $t0, 0xe($s4)
00025aa0  beqz      $t0, 0x25ad4
00025aa4  nop       
00025aa8  lui       $t1, 0xf
00025aac  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025ab0  addiu     $a0, $t1, 0x304c ; string candidate '[BLUE]'
00025ab4  lui       $a0, 0x10
00025ab8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025abc  addiu     $a0, $a0, -0x4958 ; string candidate 'BtAvFiltersHandler::FiltersRun'
00025ac0  lui       $a0, 0x10
00025ac4  jal       0x34264
00025ac8  addiu     $a0, $a0, -0x49b8
00025acc  b         0x25c54
00025ad0  nop       
00025ad4  lui       $t0, 0x10
00025ad8  lui       $t1, 0x10
00025adc  lui       $t2, 0xf
00025ae0  addiu     $s7, $t0, -0x49bc
00025ae4  addiu     $s6, $t1, -0x4958 ; string candidate 'BtAvFiltersHandler::FiltersRun'
00025ae8  addiu     $t4, $t2, 0x304c ; string candidate '[BLUE]'
00025aec  lbu       $t0, 0x98($s4)
00025af0  move      $s2, $zero
00025af4  move      $s5, $s1
00025af8  move      $s3, $s1
00025afc  sw        $s7, 0x1c($sp)
00025b00  move      $s0, $zero
00025b04  sw        $s6, 0x18($sp)
00025b08  beqz      $t0, 0x25c10
00025b0c  sw        $t4, 0x20($sp)
00025b10  addiu     $t5, $zero, 2
00025b14  addiu     $t6, $zero, 3
00025b18  beqz      $s5, 0x25c08
00025b1c  nop       
00025b20  beqz      $s3, 0x25c08
00025b24  nop       
00025b28  move      $s7, $s0
00025b2c  addiu     $t0, $s7, 0x12
00025b30  sll       $t1, $t0, 2
00025b34  addu      $s6, $t1, $s4
00025b38  lw        $t2, ($s6)
00025b3c  lw        $t3, ($t2)
00025b40  addiu     $s2, $t2, 7
00025b44  sw        $t3, 0x1c($sp)
00025b48  move      $t3, $fp
00025b4c  sltiu     $t0, $t3, 8
00025b50  beqz      $t0, 0x25e48
00025b54  move      $s3, $zero
00025b58  lui       $t2, 2
00025b5c  addiu     $t2, $t2, 0x5b78
00025b60  sll       $t1, $t3, 1
00025b64  addu      $t1, $t1, $t2
00025b68  lh        $t1, ($t1)
00025b6c  addu      $t2, $t2, $t1
00025b70  jr        $t2
00025b74  nop       
00025b78  .byte     0x10, 0x00, 0x10, 0x01
00025b7c  .byte     0x60, 0x01, 0xc4, 0x01
00025b80  .byte     0x40, 0x02, 0x8c, 0x02
00025b84  tge       $v1, $s0, 1
00025b88  lbu       $t2, ($s2)
00025b8c  move      $t3, $t2
00025b90  bne       $t3, $s1, 0x25b9c
00025b94  nop       
00025b98  move      $s3, $s1
00025b9c  bnez      $t3, 0x25be8
00025ba0  nop       
00025ba4  addiu     $t0, $s7, 0x1c
00025ba8  lw        $t2, ($s6)
00025bac  sll       $t1, $t0, 2
00025bb0  addu      $s0, $t1, $s4
00025bb4  move      $a1, $t2
00025bb8  lw        $t2, 0xc($t2)
00025bbc  move      $a2, $s4
00025bc0  move      $a0, $s0
00025bc4  jalr      $t2
00025bc8  move      $s3, $s1
00025bcc  lw        $t1, ($s6)
00025bd0  lw        $t0, ($s0)
00025bd4  sw        $t0, 8($t1)
00025bd8  sb        $s1, ($s2)
00025bdc  addiu     $t5, $zero, 2
00025be0  move      $s5, $v0
00025be4  addiu     $t6, $zero, 3
00025be8  lw        $s6, 0x18($sp)
00025bec  addiu     $t0, $s7, 1
00025bf0  sll       $s0, $t0, 0x18
00025bf4  lbu       $t1, 0x98($s4)
00025bf8  sra       $s0, $s0, 0x18
00025bfc  slt       $t2, $s0, $t1
00025c00  bnez      $t2, 0x25b18
00025c04  lw        $t4, 0x20($sp)
00025c08  bnez      $s2, 0x25c18
00025c0c  lw        $s7, 0x1c($sp)
00025c10  lui       $t0, 0x11
00025c14  addiu     $s2, $t0, 0x32c
00025c18  bnez      $s5, 0x25c50
00025c1c  nop       
00025c20  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025c24  move      $a0, $t4
00025c28  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025c2c  move      $a0, $s6
00025c30  lbu       $a0, ($s2)
00025c34  lui       $t0, 0x10
00025c38  move      $a3, $a0
00025c3c  move      $a2, $fp
00025c40  move      $a1, $s0
00025c44  addiu     $a0, $t0, -0x4a38
00025c48  jal       0x34264
00025c4c  sw        $s7, 0x10($sp)
00025c50  move      $s1, $s5
00025c54  move      $v0, $s1
00025c58  lw        $fp, 0x28($sp)
00025c5c  lw        $s7, 0x2c($sp)
00025c60  lw        $s6, 0x30($sp)
00025c64  lw        $s5, 0x34($sp)
00025c68  lw        $s4, 0x38($sp)
00025c6c  lw        $s3, 0x3c($sp)
00025c70  lw        $s2, 0x40($sp)
00025c74  lw        $s1, 0x44($sp)
00025c78  lw        $s0, 0x48($sp)
00025c7c  lw        $ra, 0x4c($sp)
00025c80  jr        $ra
00025c84  addiu     $sp, $sp, 0x50
00025c88  lbu       $t1, ($s2)
00025c8c  move      $t2, $t1
00025c90  bnez      $t2, 0x25c9c
00025c94  nop       
00025c98  move      $s3, $s1
00025c9c  bne       $t2, $s1, 0x25be8
00025ca0  nop       
00025ca4  addiu     $t0, $s7, 0x1c
00025ca8  lw        $t2, ($s6)
00025cac  sll       $t1, $t0, 2
00025cb0  addu      $s0, $t1, $s4
00025cb4  lw        $t2, 0x10($t2)
00025cb8  move      $a0, $s0
00025cbc  jalr      $t2
00025cc0  move      $s3, $s1
00025cc4  lw        $t1, ($s6)
00025cc8  lw        $t0, ($s0)
00025ccc  sw        $t0, 8($t1)
00025cd0  b         0x25bdc
00025cd4  sb        $zero, ($s2)
00025cd8  lbu       $t1, ($s2)
00025cdc  move      $t2, $t1
00025ce0  bne       $t2, $t5, 0x25cec
00025ce4  nop       
00025ce8  move      $s3, $s1
00025cec  beq       $t2, $s1, 0x25cfc
00025cf0  nop       
00025cf4  bne       $t2, $t5, 0x25be8
00025cf8  nop       
00025cfc  lbu       $t0, 0x11c($s4)
00025d00  beqz      $t0, 0x25d30
00025d04  move      $s3, $s1
00025d08  lw        $t3, ($s6)
00025d0c  addiu     $t1, $s7, 0x1c
00025d10  sll       $t2, $t1, 2
00025d14  lw        $t3, 0x14($t3)
00025d18  jalr      $t3
00025d1c  addu      $a0, $t2, $s4
00025d20  move      $s5, $v0
00025d24  addiu     $t5, $zero, 2
00025d28  b         0x25d34
00025d2c  addiu     $t6, $zero, 3
00025d30  move      $s5, $s1
00025d34  b         0x25be8
00025d38  sb        $t5, ($s2)
00025d3c  lbu       $t0, ($s2)
00025d40  move      $t1, $t0
00025d44  bne       $t1, $s1, 0x25d50
00025d48  nop       
00025d4c  move      $s3, $s1
00025d50  bne       $t1, $t6, 0x25d88
00025d54  nop       
00025d58  lbu       $t0, 0x11c($s4)
00025d5c  beqz      $t0, 0x25d84
00025d60  move      $s3, $s1
00025d64  lw        $t3, ($s6)
00025d68  addiu     $t1, $s7, 0x1c
00025d6c  sll       $t2, $t1, 2
00025d70  lw        $t3, 0x20($t3)
00025d74  jalr      $t3
00025d78  addu      $a0, $t2, $s4
00025d7c  addiu     $t5, $zero, 2
00025d80  addiu     $t6, $zero, 3
00025d84  sb        $t5, ($s2)
00025d88  lbu       $t0, ($s2)
00025d8c  bne       $t0, $t5, 0x25be8
00025d90  nop       
00025d94  lw        $t3, ($s6)
00025d98  addiu     $t1, $s7, 0x1c
00025d9c  sll       $t2, $t1, 2
00025da0  lw        $t3, 0x18($t3)
00025da4  addu      $a0, $t2, $s4
00025da8  jalr      $t3
00025dac  move      $s3, $s1
00025db0  b         0x25bd8
00025db4  nop       
00025db8  lbu       $t0, ($s2)
00025dbc  move      $t1, $t0
00025dc0  bne       $t1, $t6, 0x25dcc
00025dc4  nop       
00025dc8  move      $s3, $s1
00025dcc  bne       $t1, $t5, 0x25be8
00025dd0  nop       
00025dd4  lw        $t2, ($s6)
00025dd8  addiu     $t0, $s7, 0x1c
00025ddc  sll       $t1, $t0, 2
00025de0  lw        $t2, 0x1c($t2)
00025de4  addu      $a0, $t1, $s4
00025de8  jalr      $t2
00025dec  move      $s3, $s1
00025df0  addiu     $t6, $zero, 3
00025df4  sb        $t6, ($s2)
00025df8  move      $s5, $v0
00025dfc  b         0x25be8
00025e00  addiu     $t5, $zero, 2
00025e04  lbu       $t0, ($s2)
00025e08  move      $t1, $t0
00025e0c  bne       $t1, $t5, 0x25e18
00025e10  nop       
00025e14  move      $s3, $s1
00025e18  bne       $t1, $t6, 0x25be8
00025e1c  nop       
00025e20  lw        $t2, ($s6)
00025e24  addiu     $t0, $s7, 0x1c
00025e28  sll       $t1, $t0, 2
00025e2c  lw        $t2, 0x20($t2)
00025e30  addu      $a0, $t1, $s4
00025e34  jalr      $t2
00025e38  move      $s3, $s1
00025e3c  addiu     $t5, $zero, 2
00025e40  b         0x25be0
00025e44  sb        $t5, ($s2)
00025e48  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025e4c  move      $a0, $t4
00025e50  lw        $s6, 0x18($sp)
00025e54  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00025e58  move      $a0, $s6
00025e5c  lui       $t1, 0x10
00025e60  addiu     $t0, $t1, -0x4a84
00025e64  jal       0x34264
00025e68  move      $a0, $t0
00025e6c  move      $s5, $zero
00025e70  move      $s3, $s1
00025e74  move      $s2, $zero
00025e78  addiu     $t5, $zero, 2
00025e7c  b         0x25bec
00025e80  addiu     $t6, $zero, 3
00025fc8  addiu     $sp, $sp, -0x20
00025fcc  sw        $ra, 0x18($sp)
00025fd0  sw        $s1, 0x10($sp)
00025fd4  sw        $s0, 0x14($sp)
00025fd8  lw        $t0, 0x48($a1)
00025fdc  beqz      $t0, 0x26008
00025fe0  move      $s1, $a2
00025fe4  addiu     $s0, $a1, 0x70
00025fe8  lw        $t0, 0x38($t0)
00025fec  move      $a1, $s1
00025ff0  jalr      $t0
00025ff4  move      $a0, $s0
00025ff8  addiu     $s0, $s0, 4
00025ffc  lw        $t0, -0x28($s0)
00026000  bnez      $t0, 0x25fe8
00026004  nop       
00026008  lw        $s1, 0x10($sp)
0002600c  lw        $s0, 0x14($sp)
00026010  lw        $ra, 0x18($sp)
00026014  jr        $ra
00026018  addiu     $sp, $sp, 0x20
0002639c  addiu     $sp, $sp, -0x20
000263a0  sw        $ra, 0x18($sp)
000263a4  sw        $s1, 0x10($sp)
000263a8  sw        $s0, 0x14($sp)
000263ac  lui       $t0, 0x11
000263b0  addiu     $s1, $t0, 0xf84
000263b4  move      $s0, $a0
000263b8  jal       0x8a820 ; import thunk COREDLL.dll!EnterCriticalSection@4
000263bc  move      $a0, $s1
000263c0  lbu       $a1, 6($s0)
000263c4  sll       $t0, $a1, 5
000263c8  addu      $t2, $t0, $s0
000263cc  lw        $t1, 0x1c($t2)
000263d0  bnez      $t1, 0x263e4
000263d4  nop       
000263d8  lw        $t2, 0x10($t2)
000263dc  sw        $t2, 0x330($s0)
000263e0  sw        $zero, 0x334($s0)
000263e4  jal       0x8a810 ; import thunk COREDLL.dll!LeaveCriticalSection@5
000263e8  move      $a0, $s1
000263ec  lw        $s1, 0x10($sp)
000263f0  lw        $s0, 0x14($sp)
000263f4  lw        $ra, 0x18($sp)
000263f8  jr        $ra
000263fc  addiu     $sp, $sp, 0x20
00026400  addiu     $sp, $sp, -0x50
00026404  sw        $ra, 0x48($sp)
00026408  sw        $s5, 0x30($sp)
0002640c  sw        $s4, 0x34($sp)
00026410  sw        $s3, 0x38($sp)
00026414  sw        $s2, 0x3c($sp)
00026418  sw        $s1, 0x40($sp)
0002641c  sw        $s0, 0x44($sp)
00026420  addiu     $a3, $zero, 0
00026424  addiu     $a2, $zero, 0
00026428  addiu     $a1, $zero, 0
0002642c  jal       0x8a840 ; import thunk COREDLL.dll!GetMessageW@861
00026430  addiu     $a0, $sp, 0x10
00026434  lui       $t0, 0x10
00026438  lui       $t1, 0xf
0002643c  addiu     $s5, $zero, 1
00026440  addiu     $s1, $t0, -0x4394 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayProc'
00026444  bne       $v0, $s5, 0x2650c
00026448  addiu     $s2, $t1, 0x304c ; string candidate '[BLUE]'
0002644c  lui       $t0, 0x10
00026450  lui       $t1, 0x11
00026454  addiu     $s3, $t0, -0x43c8
00026458  addiu     $s0, $t1, 0xf84
0002645c  lui       $s4, 0x11
00026460  lw        $t0, 0x14($sp)
00026464  addiu     $t2, $zero, 0x3bc
00026468  beq       $t0, $t2, 0x26528
0002646c  nop       
00026470  addiu     $t1, $zero, 0x3bd
00026474  bne       $t0, $t1, 0x264f0
00026478  nop       
0002647c  jal       0x8a820 ; import thunk COREDLL.dll!EnterCriticalSection@4
00026480  move      $a0, $s0
00026484  lw        $a0, 0x1c($sp)
00026488  sw        $zero, 0xc($a0)
0002648c  lw        $t1, 0x1c($sp)
00026490  lui       $t2, 0xffff
00026494  lw        $t0, 0x10($t1)
00026498  ori       $t2, $t2, 0xfffe
0002649c  and       $t0, $t0, $t2
000264a0  lw        $t3, 0xf9c($s4)
000264a4  beqz      $t3, 0x264e8
000264a8  sw        $t0, 0x10($t1)
000264ac  lbu       $t1, 5($t3)
000264b0  addiu     $t2, $t1, 0xff
000264b4  andi      $t0, $t2, 0xff
000264b8  bnez      $t0, 0x264e8
000264bc  sb        $t0, 5($t3)
000264c0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000264c4  move      $a0, $s2
000264c8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000264cc  move      $a0, $s1
000264d0  jal       0x34264
000264d4  move      $a0, $s3
000264d8  lw        $a0, 0xf9c($s4)
000264dc  sb        $zero, 0x338($a0)
000264e0  jal       0x8a830 ; import thunk COREDLL.dll!waveOutPause@388
000264e4  lw        $a0, 8($a0)
000264e8  jal       0x8a810 ; import thunk COREDLL.dll!LeaveCriticalSection@5
000264ec  move      $a0, $s0
000264f0  addiu     $a3, $zero, 0
000264f4  addiu     $a2, $zero, 0
000264f8  addiu     $a1, $zero, 0
000264fc  jal       0x8a840 ; import thunk COREDLL.dll!GetMessageW@861
00026500  addiu     $a0, $sp, 0x10
00026504  beq       $v0, $s5, 0x26460
00026508  nop       
0002650c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026510  move      $a0, $s2
00026514  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026518  move      $a0, $s1
0002651c  lui       $a0, 0x10
00026520  jal       0x34264
00026524  addiu     $a0, $a0, -0x43f8
00026528  lw        $s5, 0x30($sp)
0002652c  lw        $s4, 0x34($sp)
00026530  lw        $s3, 0x38($sp)
00026534  lw        $s2, 0x3c($sp)
00026538  lw        $s1, 0x40($sp)
0002653c  lw        $s0, 0x44($sp)
00026540  lw        $ra, 0x48($sp)
00026544  addiu     $v0, $zero, 0
00026548  jr        $ra
0002654c  addiu     $sp, $sp, 0x50
00026550  addiu     $sp, $sp, -0x20
00026554  sw        $ra, 0x1c($sp)
00026558  sw        $s2, 0x10($sp)
0002655c  sw        $s1, 0x14($sp)
00026560  sw        $s0, 0x18($sp)
00026564  lui       $s2, 0x11
00026568  lw        $t0, 0xf9c($s2)
0002656c  move      $s1, $a1
00026570  bnez      $t0, 0x26598
00026574  move      $s0, $a0
00026578  jal       0x85b70
0002657c  addiu     $a0, $zero, 0x340
00026580  addiu     $a2, $zero, 0x340
00026584  addiu     $a1, $zero, 0
00026588  jal       0x3a750
0002658c  move      $a0, $v0
00026590  sw        $v0, ($s0)
00026594  sw        $v0, 0xf9c($s2)
00026598  lui       $t0, 0x11
0002659c  jal       0x8a850 ; import thunk COREDLL.dll!InitializeCriticalSection@2
000265a0  addiu     $a0, $t0, 0xf84
000265a4  lui       $t0, 0x11
000265a8  lw        $t0, 0x44($t0) ; IAT COREDLL.dll!CreateSemaphoreW@1238
000265ac  addiu     $a3, $zero, 0
000265b0  addiu     $a2, $zero, 1
000265b4  addiu     $a1, $zero, 1
000265b8  jalr      $t0 ; call candidate COREDLL.dll!CreateSemaphoreW@1238
000265bc  addiu     $a0, $zero, 0
000265c0  lui       $a0, 0x11
000265c4  sw        $v0, 0xf98($a0)
000265c8  lw        $s0, ($s0)
000265cc  addiu     $a2, $s0, 0x33c
000265d0  addiu     $a1, $s0, 0x33a
000265d4  addiu     $a0, $s0, 0x339
000265d8  sw        $s1, ($s0)
000265dc  sb        $zero, 4($s0)
000265e0  sw        $zero, 0x334($s0)
000265e4  sw        $zero, 8($s0)
000265e8  sw        $zero, 0xc($s0)
000265ec  sb        $zero, 5($s0)
000265f0  sb        $zero, 6($s0)
000265f4  jal       0x193b4
000265f8  sb        $zero, 0x338($s0)
000265fc  lui       $a0, 9
00026600  jal       0x85b70
00026604  ori       $a0, $a0, 0xc400
00026608  sw        $v0, 0x10($s0)
0002660c  lw        $s2, 0x10($sp)
00026610  lw        $s1, 0x14($sp)
00026614  lw        $s0, 0x18($sp)
00026618  lw        $ra, 0x1c($sp)
0002661c  addiu     $v0, $zero, 1
00026620  jr        $ra
00026624  addiu     $sp, $sp, 0x20
00026628  addiu     $sp, $sp, -0x20
0002662c  sw        $ra, 0x18($sp)
00026630  sw        $s1, 0x10($sp)
00026634  sw        $s0, 0x14($sp)
00026638  move      $s1, $a0
0002663c  lw        $s0, ($s1)
00026640  jal       0x85bb8
00026644  lw        $a0, 0x10($s0)
00026648  lui       $t0, 0x11
0002664c  addiu     $a0, $t0, 0xf84
00026650  jal       0x8a860 ; import thunk COREDLL.dll!DeleteCriticalSection@3
00026654  sw        $zero, 0x10($s0)
00026658  lui       $a0, 0x11
0002665c  lui       $t0, 0x11
00026660  lw        $t0, 0x20($t0) ; IAT COREDLL.dll!CloseHandle@553
00026664  jalr      $t0 ; call candidate COREDLL.dll!CloseHandle@553
00026668  lw        $a0, 0xf98($a0)
0002666c  lui       $a0, 0x11
00026670  addiu     $s0, $a0, 0xfa0
00026674  lw        $a0, ($s1)
00026678  jal       0x85bb8
0002667c  sw        $zero, ($s0)
00026680  move      $t0, $zero
00026684  sw        $zero, ($s1)
00026688  sw        $t0, -4($s0)
0002668c  lw        $s1, 0x10($sp)
00026690  lw        $s0, 0x14($sp)
00026694  lw        $ra, 0x18($sp)
00026698  addiu     $v0, $zero, 1
0002669c  jr        $ra
000266a0  addiu     $sp, $sp, 0x20
000266a4  addiu     $sp, $sp, -0x58
000266a8  sw        $ra, 0x50($sp)
000266ac  sw        $s5, 0x38($sp)
000266b0  sw        $s4, 0x3c($sp)
000266b4  sw        $s3, 0x40($sp)
000266b8  sw        $s2, 0x44($sp)
000266bc  sw        $s1, 0x48($sp)
000266c0  sw        $s0, 0x4c($sp)
000266c4  lw        $s0, ($a0)
000266c8  addiu     $s2, $s0, 0x33c
000266cc  addiu     $s3, $s0, 0x33a
000266d0  addiu     $s4, $s0, 0x339
000266d4  move      $a2, $s2
000266d8  move      $a1, $s3
000266dc  move      $a0, $s4
000266e0  jal       0x193b4
000266e4  sw        $zero, 0x18($sp)
000266e8  addiu     $s5, $s0, 8
000266ec  lw        $t0, ($s5)
000266f0  beqz      $t0, 0x26724
000266f4  nop       
000266f8  lui       $t1, 0xf
000266fc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026700  addiu     $a0, $t1, 0x304c ; string candidate '[BLUE]'
00026704  lui       $a0, 0x10
00026708  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
0002670c  addiu     $a0, $a0, -0x4060 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayOpen'
00026710  lui       $a0, 0x10
00026714  jal       0x34264
00026718  addiu     $a0, $a0, -0x409c
0002671c  b         0x26a60
00026720  nop       
00026724  addiu     $s1, $zero, 1
00026728  srl       $t0, $s1, 8
0002672c  sb        $t0, 0x21($sp)
00026730  sb        $s1, 0x20($sp)
00026734  lbu       $t1, ($s4)
00026738  sw        $zero, 0x10($sp)
0002673c  move      $t5, $t1
00026740  move      $t2, $t5
00026744  sb        $t2, 0x22($sp)
00026748  srl       $t3, $t2, 8
0002674c  sb        $t3, 0x23($sp)
00026750  lhu       $t0, ($s2)
00026754  move      $t6, $t0
00026758  swl       $t6, 0x27($sp)
0002675c  swr       $t6, 0x24($sp)
00026760  lbu       $t1, ($s3)
00026764  move      $t4, $t1
00026768  move      $t2, $t4
0002676c  sb        $t2, 0x2e($sp)
00026770  srl       $t0, $t4, 3
00026774  srl       $t3, $t2, 8
00026778  move      $t2, $t0
0002677c  multu     $t2, $t5
00026780  sb        $t3, 0x2f($sp)
00026784  addiu     $a3, $zero, 0
00026788  addiu     $a1, $zero, 0
0002678c  addiu     $a0, $zero, 0
00026790  mflo      $t1
00026794  andi      $t5, $t1, 0xffff
00026798  nop       
0002679c  multu     $t5, $t6
000267a0  move      $t1, $zero
000267a4  sb        $t1, 0x30($sp)
000267a8  move      $t4, $t5
000267ac  srl       $t1, $t1, 8
000267b0  sb        $t4, 0x2c($sp)
000267b4  sb        $t1, 0x31($sp)
000267b8  lui       $t1, 2
000267bc  srl       $t3, $t4, 8
000267c0  sb        $t3, 0x2d($sp)
000267c4  addiu     $a2, $t1, 0x6400
000267c8  mflo      $t0
000267cc  swl       $t0, 0x2b($sp)
000267d0  swr       $t0, 0x28($sp)
000267d4  addiu     $t0, $sp, 0x18
000267d8  sb        $s1, 4($s0)
000267dc  sb        $zero, 5($s0)
000267e0  jal       0x8a7f0 ; import thunk COREDLL.dll!CreateThread@492
000267e4  sw        $t0, 0x14($sp)
000267e8  bnez      $v0, 0x26834
000267ec  sw        $v0, 0xc($s0)
000267f0  lui       $t0, 0xf
000267f4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000267f8  addiu     $a0, $t0, 0x304c ; string candidate '[BLUE]'
000267fc  lui       $a0, 0x10
00026800  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026804  addiu     $a0, $a0, -0x4060 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayOpen'
00026808  lui       $a0, 0x11
0002680c  lw        $t0, 0x60($a0) ; IAT COREDLL.dll!GetLastError@516
00026810  jalr      $t0 ; call candidate COREDLL.dll!GetLastError@516
00026814  nop       
00026818  lui       $t0, 0x10
0002681c  move      $a1, $v0
00026820  addiu     $a0, $t0, -0x410c
00026824  jal       0x34264
00026828  nop       
0002682c  b         0x26a5c
00026830  nop       
00026834  lui       $t0, 0x11
00026838  lw        $t0, 0x5c($t0) ; IAT COREDLL.dll!CeSetThreadPriority@621
0002683c  addiu     $a1, $zero, 0
00026840  jalr      $t0 ; call candidate COREDLL.dll!CeSetThreadPriority@621
00026844  move      $a0, $v0
00026848  lui       $a0, 0x10
0002684c  lui       $t0, 0xf
00026850  addiu     $s3, $a0, -0x4060 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayOpen'
00026854  bnez      $v0, 0x26878
00026858  addiu     $s4, $t0, 0x304c ; string candidate '[BLUE]'
0002685c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026860  move      $a0, $s4
00026864  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026868  move      $a0, $s3
0002686c  lui       $a0, 0x10
00026870  jal       0x34264
00026874  addiu     $a0, $a0, -0x4178
00026878  lui       $s2, 0x11
0002687c  lui       $t0, 0x11
00026880  lw        $a0, 0xf98($s2)
00026884  lw        $t0, 0x24($t0) ; IAT COREDLL.dll!WaitForSingleObject@497
00026888  jalr      $t0 ; call candidate COREDLL.dll!WaitForSingleObject@497
0002688c  addiu     $a1, $zero, -1
00026890  lw        $a1, ($s5)
00026894  beqz      $a1, 0x268e4
00026898  move      $a0, $s4
0002689c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000268a0  nop       
000268a4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000268a8  move      $a0, $s3
000268ac  lui       $t0, 0x11
000268b0  lw        $a1, 0xfa0($t0)
000268b4  lui       $t0, 0x10
000268b8  lw        $a2, ($s5)
000268bc  jal       0x34264
000268c0  addiu     $a0, $t0, -0x41e8
000268c4  lui       $t0, 0x11
000268c8  lw        $a0, 0xf98($s2)
000268cc  lw        $t0, 0x58($t0) ; IAT COREDLL.dll!ReleaseSemaphore@1239
000268d0  addiu     $a2, $zero, 0
000268d4  jalr      $t0 ; call candidate COREDLL.dll!ReleaseSemaphore@1239
000268d8  addiu     $a1, $zero, 1
000268dc  b         0x26a64
000268e0  nop       
000268e4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000268e8  nop       
000268ec  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000268f0  move      $a0, $s3
000268f4  lui       $a0, 0x11
000268f8  lw        $t0, 0xfa0($a0)
000268fc  lui       $t1, 0x10
00026900  addiu     $a1, $t0, 1
00026904  sw        $a1, 0xfa0($a0)
00026908  lw        $a2, ($s5)
0002690c  jal       0x34264
00026910  addiu     $a0, $t1, -0x422c
00026914  lui       $a0, 2
00026918  sw        $a0, 0x14($sp)
0002691c  lw        $a3, 0x18($sp)
00026920  addiu     $a2, $sp, 0x20
00026924  addiu     $a1, $zero, -1
00026928  move      $a0, $s5
0002692c  jal       0x8a880 ; import thunk COREDLL.dll!waveOutOpen@399
00026930  sw        $zero, 0x10($sp)
00026934  lui       $t0, 0x11
00026938  lw        $a0, 0xf98($s2)
0002693c  lw        $t0, 0x58($t0) ; IAT COREDLL.dll!ReleaseSemaphore@1239
00026940  addiu     $a2, $zero, 0
00026944  addiu     $a1, $zero, 1
00026948  jalr      $t0 ; call candidate COREDLL.dll!ReleaseSemaphore@1239
0002694c  sw        $v0, 0x18($sp)
00026950  lw        $a0, 0x18($sp)
00026954  beqz      $a0, 0x2697c
00026958  nop       
0002695c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026960  move      $a0, $s4
00026964  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026968  move      $a0, $s3
0002696c  lui       $t0, 0x10
00026970  lw        $a1, 0x18($sp)
00026974  b         0x26824
00026978  addiu     $a0, $t0, -0x4288
0002697c  addiu     $s2, $zero, 0x6400
00026980  lw        $t0, 0x10($s0)
00026984  sw        $s2, 0x14($s0)
00026988  sw        $zero, 0x1c($s0)
0002698c  bnez      $t0, 0x269b8
00026990  sw        $zero, 0x20($s0)
00026994  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026998  move      $a0, $s4
0002699c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
000269a0  move      $a0, $s3
000269a4  lui       $a1, 9
000269a8  lui       $t0, 0x10
000269ac  ori       $a1, $a1, 0xc400
000269b0  jal       0x34264
000269b4  addiu     $a0, $t0, -0x42e4
000269b8  move      $t1, $s1
000269bc  move      $t4, $s1
000269c0  sll       $t0, $t1, 5
000269c4  addu      $t3, $t0, $s0
000269c8  lw        $t1, -0x10($t3)
000269cc  sw        $s2, 0x14($t3)
000269d0  addiu     $t2, $t1, 0x6400
000269d4  sw        $t2, 0x10($t3)
000269d8  sw        $zero, 0x1c($t3)
000269dc  sw        $zero, 0x20($t3)
000269e0  addiu     $t3, $t4, 1
000269e4  andi      $t1, $t3, 0xff
000269e8  move      $t4, $t1
000269ec  sltiu     $t0, $t4, 0x19
000269f0  bnez      $t0, 0x269c0
000269f4  nop       
000269f8  move      $s2, $zero
000269fc  sll       $t1, $s2, 5
00026a00  addu      $t2, $t1, $s0
00026a04  lw        $a0, ($s5)
00026a08  addiu     $a1, $t2, 0x10
00026a0c  jal       0x8a870 ; import thunk COREDLL.dll!waveOutPrepareHeader@385
00026a10  addiu     $a2, $zero, 0x20
00026a14  bnez      $v0, 0x26a38
00026a18  sw        $v0, 0x18($sp)
00026a1c  addiu     $t0, $s2, 1
00026a20  andi      $s2, $t0, 0xff
00026a24  sltiu     $t1, $s2, 0x19
00026a28  bnez      $t1, 0x269fc
00026a2c  nop       
00026a30  b         0x26a64
00026a34  nop       
00026a38  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026a3c  move      $a0, $s4
00026a40  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026a44  move      $a0, $s3
00026a48  lui       $t0, 0x10
00026a4c  lw        $a2, 0x18($sp)
00026a50  move      $a1, $s2
00026a54  jal       0x34264
00026a58  addiu     $a0, $t0, -0x4348
00026a5c  sb        $zero, 4($s0)
00026a60  move      $s1, $zero
00026a64  move      $v0, $s1
00026a68  lw        $s5, 0x38($sp)
00026a6c  lw        $s4, 0x3c($sp)
00026a70  lw        $s3, 0x40($sp)
00026a74  lw        $s2, 0x44($sp)
00026a78  lw        $s1, 0x48($sp)
00026a7c  lw        $s0, 0x4c($sp)
00026a80  lw        $ra, 0x50($sp)
00026a84  jr        $ra
00026a88  addiu     $sp, $sp, 0x58
00026a8c  addiu     $sp, $sp, -0x30
00026a90  sw        $ra, 0x28($sp)
00026a94  sw        $s3, 0x18($sp)
00026a98  sw        $s2, 0x1c($sp)
00026a9c  sw        $s1, 0x20($sp)
00026aa0  sw        $s0, 0x24($sp)
00026aa4  lw        $s1, ($a0)
00026aa8  addiu     $s0, $zero, 1
00026aac  lw        $a0, 8($s1)
00026ab0  sb        $zero, 0x338($s1)
00026ab4  beqz      $a0, 0x26bcc
00026ab8  sb        $zero, 4($s1)
00026abc  jal       0x8a830 ; import thunk COREDLL.dll!waveOutPause@388
00026ac0  nop       
00026ac4  jal       0x8a8c0 ; import thunk COREDLL.dll!waveOutReset@390
00026ac8  lw        $a0, 8($s1)
00026acc  move      $s2, $zero
00026ad0  sw        $s0, 0x10($sp)
00026ad4  beqz      $s0, 0x26b0c
00026ad8  nop       
00026adc  sll       $t0, $s2, 5
00026ae0  addu      $t1, $t0, $s1
00026ae4  lw        $a0, 8($s1)
00026ae8  addiu     $a1, $t1, 0x10
00026aec  jal       0x8a8b0 ; import thunk COREDLL.dll!waveOutUnprepareHeader@386
00026af0  addiu     $a2, $zero, 0x20
00026af4  addiu     $t0, $s2, 1
00026af8  move      $s0, $v0
00026afc  andi      $s2, $t0, 0xff
00026b00  sltiu     $t1, $s2, 0x19
00026b04  bnez      $t1, 0x26ad4
00026b08  sw        $s0, 0x10($sp)
00026b0c  lui       $t2, 0x11
00026b10  addiu     $s0, $t2, 0xf84
00026b14  jal       0x8a820 ; import thunk COREDLL.dll!EnterCriticalSection@4
00026b18  move      $a0, $s0
00026b1c  lui       $a0, 0xf
00026b20  addiu     $s2, $a0, 0x304c ; string candidate '[BLUE]'
00026b24  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026b28  move      $a0, $s2
00026b2c  lui       $a0, 0x10
00026b30  addiu     $s3, $a0, -0x3f60 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayClose'
00026b34  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026b38  move      $a0, $s3
00026b3c  lui       $a0, 0x11
00026b40  lw        $t0, 0xfa0($a0)
00026b44  lui       $t1, 0x10
00026b48  addiu     $a1, $t0, -1
00026b4c  sw        $a1, 0xfa0($a0)
00026b50  jal       0x34264
00026b54  addiu     $a0, $t1, -0x3f8c
00026b58  jal       0x8a8a0 ; import thunk COREDLL.dll!waveOutClose@384
00026b5c  lw        $a0, 8($s1)
00026b60  sw        $v0, 0x10($sp)
00026b64  move      $a0, $s0
00026b68  jal       0x8a810 ; import thunk COREDLL.dll!LeaveCriticalSection@5
00026b6c  sw        $zero, 8($s1)
00026b70  lui       $t0, 0x11
00026b74  lw        $t0, 0x10($t0) ; IAT COREDLL.dll!Sleep@496
00026b78  jalr      $t0 ; call candidate COREDLL.dll!Sleep@496
00026b7c  addiu     $a0, $zero, 0
00026b80  lw        $a1, 0x10($sp)
00026b84  beqz      $a1, 0x26bb4
00026b88  nop       
00026b8c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026b90  move      $a0, $s2
00026b94  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026b98  move      $a0, $s3
00026b9c  lui       $t0, 0x10
00026ba0  lw        $a1, 0x10($sp)
00026ba4  jal       0x34264
00026ba8  addiu     $a0, $t0, -0x3fec
00026bac  b         0x26bf0
00026bb0  nop       
00026bb4  sb        $zero, 5($s1)
00026bb8  sb        $zero, 6($s1)
00026bbc  sb        $zero, 0x338($s1)
00026bc0  sw        $zero, 0x334($s1)
00026bc4  b         0x26bf0
00026bc8  sw        $zero, 8($s1)
00026bcc  lui       $t0, 0xf
00026bd0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026bd4  addiu     $a0, $t0, 0x304c ; string candidate '[BLUE]'
00026bd8  lui       $a0, 0x10
00026bdc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026be0  addiu     $a0, $a0, -0x3f60 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayClose'
00026be4  lui       $a0, 0x10
00026be8  jal       0x34264
00026bec  addiu     $a0, $a0, -0x4014
00026bf0  lw        $a0, 0xc($s1)
00026bf4  beqz      $a0, 0x26c34
00026bf8  nop       
00026bfc  lui       $t0, 0x11
00026c00  lw        $t0, 0x68($t0) ; IAT COREDLL.dll!GetExitCodeThread@518
00026c04  jalr      $t0 ; call candidate COREDLL.dll!GetExitCodeThread@518
00026c08  addiu     $a1, $sp, 0x10
00026c0c  beqz      $v0, 0x26c20
00026c10  nop       
00026c14  lw        $a1, 0x10($sp)
00026c18  jal       0x8a890 ; import thunk COREDLL.dll!TerminateThread@491
00026c1c  lw        $a0, 0xc($s1)
00026c20  lui       $t0, 0x11
00026c24  lw        $t0, 0x20($t0) ; IAT COREDLL.dll!CloseHandle@553
00026c28  jalr      $t0 ; call candidate COREDLL.dll!CloseHandle@553
00026c2c  lw        $a0, 0xc($s1)
00026c30  sw        $zero, 0xc($s1)
00026c34  lui       $a2, 9
00026c38  lw        $a0, 0x10($s1)
00026c3c  ori       $a2, $a2, 0xc400
00026c40  jal       0x3a750
00026c44  addiu     $a1, $zero, 0
00026c48  lw        $s3, 0x18($sp)
00026c4c  lw        $s2, 0x1c($sp)
00026c50  lw        $s1, 0x20($sp)
00026c54  lw        $s0, 0x24($sp)
00026c58  lw        $ra, 0x28($sp)
00026c5c  addiu     $v0, $zero, 1
00026c60  jr        $ra
00026c64  addiu     $sp, $sp, 0x30
00026c68  addiu     $sp, $sp, -0x28
00026c6c  sw        $ra, 0x20($sp)
00026c70  sw        $s1, 0x18($sp)
00026c74  sw        $s0, 0x1c($sp)
00026c78  move      $s1, $a0
00026c7c  addiu     $a2, $sp, 0x12
00026c80  addiu     $a1, $sp, 0x11
00026c84  addiu     $a0, $sp, 0x10
00026c88  jal       0x193b4
00026c8c  lw        $s0, ($s1)
00026c90  lw        $t0, 8($s0)
00026c94  beqz      $t0, 0x26d14
00026c98  nop       
00026c9c  lbu       $t2, 0x339($s0)
00026ca0  lbu       $t1, 0x10($sp)
00026ca4  bne       $t1, $t2, 0x26ccc
00026ca8  nop       
00026cac  lbu       $t3, 0x33a($s0)
00026cb0  lbu       $t2, 0x11($sp)
00026cb4  bne       $t2, $t3, 0x26ccc
00026cb8  nop       
00026cbc  lhu       $t4, 0x33c($s0)
00026cc0  lhu       $t0, 0x12($sp)
00026cc4  beq       $t0, $t4, 0x26d00
00026cc8  nop       
00026ccc  lui       $t1, 0xf
00026cd0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026cd4  addiu     $a0, $t1, 0x304c ; string candidate '[BLUE]'
00026cd8  lui       $a0, 0x10
00026cdc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026ce0  addiu     $a0, $a0, -0x3e94 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayStart'
00026ce4  lui       $a0, 0x10
00026ce8  jal       0x34264
00026cec  addiu     $a0, $a0, -0x3f10
00026cf0  jal       0x26a8c
00026cf4  move      $a0, $s1
00026cf8  jal       0x266a4
00026cfc  move      $a0, $s1
00026d00  addiu     $t0, $zero, 2
00026d04  lw        $a0, 8($s0)
00026d08  sb        $t0, 4($s0)
00026d0c  jal       0x8a830 ; import thunk COREDLL.dll!waveOutPause@388
00026d10  sb        $zero, 0x338($s0)
00026d14  lw        $s1, 0x18($sp)
00026d18  lw        $s0, 0x1c($sp)
00026d1c  lw        $ra, 0x20($sp)
00026d20  addiu     $v0, $zero, 1
00026d24  jr        $ra
00026d28  addiu     $sp, $sp, 0x28
00026d2c  addiu     $sp, $sp, -0x28
00026d30  sw        $ra, 0x24($sp)
00026d34  sw        $s4, 0x10($sp)
00026d38  sw        $s3, 0x14($sp)
00026d3c  sw        $s2, 0x18($sp)
00026d40  sw        $s1, 0x1c($sp)
00026d44  sw        $s0, 0x20($sp)
00026d48  lw        $s0, ($a0)
00026d4c  addiu     $t0, $zero, 1
00026d50  lw        $a0, 8($s0)
00026d54  sb        $zero, 0x338($s0)
00026d58  beqz      $a0, 0x26df0
00026d5c  sb        $t0, 4($s0)
00026d60  jal       0x8a8c0 ; import thunk COREDLL.dll!waveOutReset@390
00026d64  nop       
00026d68  lui       $t0, 0x10
00026d6c  lui       $t1, 0xf
00026d70  move      $s1, $v0
00026d74  addiu     $s2, $t0, -0x3d6c ; string candidate 'BtAvFilterWinPlayHandler::WinPlayStop'
00026d78  lui       $s4, 0x11
00026d7c  beqz      $s1, 0x26db0
00026d80  addiu     $s3, $t1, 0x304c ; string candidate '[BLUE]'
00026d84  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026d88  move      $a0, $s3
00026d8c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026d90  move      $a0, $s2
00026d94  lw        $a1, 0xf9c($s4)
00026d98  lbu       $t0, 5($a1)
00026d9c  lui       $t1, 0x10
00026da0  move      $a2, $t0
00026da4  move      $a1, $s1
00026da8  jal       0x34264
00026dac  addiu     $a0, $t1, -0x3dd8
00026db0  jal       0x8a830 ; import thunk COREDLL.dll!waveOutPause@388
00026db4  lw        $a0, 8($s0)
00026db8  move      $s0, $v0
00026dbc  beqz      $s0, 0x26df0
00026dc0  nop       
00026dc4  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026dc8  move      $a0, $s3
00026dcc  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026dd0  move      $a0, $s2
00026dd4  lw        $a0, 0xf9c($s4)
00026dd8  lbu       $t0, 5($a0)
00026ddc  lui       $t1, 0x10
00026de0  move      $a2, $t0
00026de4  move      $a1, $s0
00026de8  jal       0x34264
00026dec  addiu     $a0, $t1, -0x3e44
00026df0  lw        $s4, 0x10($sp)
00026df4  lw        $s3, 0x14($sp)
00026df8  lw        $s2, 0x18($sp)
00026dfc  lw        $s1, 0x1c($sp)
00026e00  lw        $s0, 0x20($sp)
00026e04  lw        $ra, 0x24($sp)
00026e08  addiu     $v0, $zero, 1
00026e0c  jr        $ra
00026e10  addiu     $sp, $sp, 0x28
00026e14  addiu     $sp, $sp, -0x40
00026e18  sw        $ra, 0x3c($sp)
00026e1c  sw        $fp, 0x18($sp)
00026e20  sw        $s7, 0x1c($sp)
00026e24  sw        $s6, 0x20($sp)
00026e28  sw        $s5, 0x24($sp)
00026e2c  sw        $s4, 0x28($sp)
00026e30  sw        $s3, 0x2c($sp)
00026e34  sw        $s2, 0x30($sp)
00026e38  sw        $s1, 0x34($sp)
00026e3c  sw        $s0, 0x38($sp)
00026e40  move      $s6, $a0
00026e44  move      $s5, $a1
00026e48  sll       $t0, $s6, 2
00026e4c  addu      $s7, $t0, $s5
00026e50  lw        $t1, ($s7)
00026e54  move      $s2, $a3
00026e58  lw        $s0, 8($t1)
00026e5c  lw        $t2, 8($s0)
00026e60  beqz      $t2, 0x27088
00026e64  move      $fp, $a2
00026e68  jal       0x19410
00026e6c  nop       
00026e70  jal       0x18220
00026e74  move      $a0, $v0
00026e78  beqz      $v0, 0x27088
00026e7c  nop       
00026e80  jal       0x19410
00026e84  nop       
00026e88  jal       0x18260
00026e8c  move      $a0, $v0
00026e90  beqz      $v0, 0x27088
00026e94  nop       
00026e98  lw        $t0, 0x334($s0)
00026e9c  bnez      $t0, 0x26eac
00026ea0  nop       
00026ea4  jal       0x2639c
00026ea8  move      $a0, $s0
00026eac  lw        $t0, 0x334($s0)
00026eb0  lw        $s1, 0x50($sp)
00026eb4  addu      $t1, $s1, $t0
00026eb8  lw        $t0, 0x330($s0)
00026ebc  addu      $t3, $t1, $t0
00026ec0  lw        $t1, 0x310($s0)
00026ec4  addiu     $t2, $t1, 0x6400
00026ec8  move      $t4, $zero
00026ecc  sltu      $t2, $t2, $t3
00026ed0  bnez      $t2, 0x26edc
00026ed4  addiu     $t0, $zero, 1
00026ed8  move      $t4, $t0
00026edc  bnez      $t4, 0x26ef0
00026ee0  nop       
00026ee4  jal       0x2639c
00026ee8  move      $a0, $s0
00026eec  sw        $zero, 0x334($s0)
00026ef0  lw        $t1, 0x334($s0)
00026ef4  lw        $t0, 0x330($s0)
00026ef8  addu      $a0, $t1, $t0
00026efc  move      $a2, $s1
00026f00  jal       0x85758
00026f04  move      $a1, $s2
00026f08  lui       $a0, 0x10
00026f0c  lui       $t0, 0xf
00026f10  addiu     $s3, $a0, -0x3c44 ; string candidate 'BtAvFilterWinPlayHandler::WinPlayProcess'
00026f14  bnez      $v0, 0x26f4c
00026f18  addiu     $s4, $t0, 0x304c ; string candidate '[BLUE]'
00026f1c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026f20  move      $a0, $s4
00026f24  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026f28  move      $a0, $s3
00026f2c  lui       $a0, 0x10
00026f30  jal       0x34264
00026f34  addiu     $a0, $a0, -0x3c80
00026f38  jal       0x1ed70
00026f3c  move      $s1, $zero
00026f40  addiu     $a1, $zero, 0
00026f44  jal       0x1ef64
00026f48  move      $a0, $v0
00026f4c  lw        $t0, 0x334($s0)
00026f50  addu      $t1, $s1, $t0
00026f54  sw        $t1, 0x334($s0)
00026f58  sltiu     $t1, $t1, 0x5001
00026f5c  bnez      $t1, 0x27074
00026f60  nop       
00026f64  lbu       $t2, 5($s0)
00026f68  sltiu     $t3, $t2, 0x19
00026f6c  beqz      $t3, 0x27074
00026f70  nop       
00026f74  lui       $t0, 0x11
00026f78  addiu     $t0, $t0, 0xf84
00026f7c  jal       0x8a820 ; import thunk COREDLL.dll!EnterCriticalSection@4
00026f80  move      $a0, $t0
00026f84  lbu       $t0, 6($s0)
00026f88  sll       $t1, $t0, 5
00026f8c  addu      $t2, $t1, $s0
00026f90  addiu     $t3, $zero, 1
00026f94  sw        $t3, 0x1c($t2)
00026f98  lbu       $t3, 6($s0)
00026f9c  lw        $t5, 0x334($s0)
00026fa0  sll       $t4, $t3, 5
00026fa4  addu      $t6, $t4, $s0
00026fa8  sw        $t5, 0x14($t6)
00026fac  lbu       $t0, 5($s0)
00026fb0  lw        $a0, 8($s0)
00026fb4  addiu     $t1, $t0, 1
00026fb8  sb        $t1, 5($s0)
00026fbc  lbu       $t1, 6($s0)
00026fc0  sll       $t2, $t1, 5
00026fc4  addu      $t3, $t2, $s0
00026fc8  addiu     $a1, $t3, 0x10
00026fcc  jal       0x8a8e0 ; import thunk COREDLL.dll!waveOutWrite@387
00026fd0  addiu     $a2, $zero, 0x20
00026fd4  move      $s1, $v0
00026fd8  beqz      $s1, 0x27000
00026fdc  nop       
00026fe0  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026fe4  move      $a0, $s4
00026fe8  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00026fec  move      $a0, $s3
00026ff0  lui       $t0, 0x10
00026ff4  move      $a1, $s1
00026ff8  jal       0x34264
00026ffc  addiu     $a0, $t0, -0x3ce0
00027000  lbu       $t0, 0x338($s0)
00027004  bnez      $t0, 0x27048
00027008  nop       
0002700c  lbu       $t1, 5($s0)
00027010  sltiu     $t2, $t1, 0xb
00027014  bnez      $t2, 0x27048
00027018  nop       
0002701c  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00027020  move      $a0, $s4
00027024  jal       0x8a7c0 ; import thunk COREDLL.dll!NKDbgPrintfW@545
00027028  move      $a0, $s3
0002702c  lui       $a0, 0x10
00027030  jal       0x34264
00027034  addiu     $a0, $a0, -0x3d20
00027038  lw        $a0, 8($s0)
0002703c  addiu     $t0, $zero, 1
00027040  jal       0x8a8d0 ; import thunk COREDLL.dll!waveOutRestart@389
00027044  sb        $t0, 0x338($s0)
00027048  lui       $t0, 0x11
0002704c  jal       0x8a810 ; import thunk COREDLL.dll!LeaveCriticalSection@5
00027050  addiu     $a0, $t0, 0xf84
00027054  lbu       $a0, 6($s0)
00027058  addiu     $t0, $a0, 1
0002705c  addiu     $t1, $zero, 0x19
00027060  div       $zero, $t0, $t1
00027064  sw        $zero, 0x334($s0)
00027068  mfhi      $t0
0002706c  b         0x27088
00027070  sb        $t0, 6($s0)
00027074  lbu       $t0, 5($s0)
00027078  sltiu     $t1, $t0, 0x19
0002707c  bnez      $t1, 0x27088
00027080  nop       
00027084  sb        $zero, 5($s0)
00027088  beqz      $fp, 0x270a0
0002708c  nop       
00027090  beqz      $s2, 0x270a0
00027094  nop       
00027098  jal       0x85bb8
0002709c  move      $a0, $s2
000270a0  lw        $t1, 4($s7)
000270a4  addiu     $t0, $s6, 1
000270a8  lw        $t1, 0x24($t1)
000270ac  andi      $a0, $t0, 0xff
000270b0  addiu     $a3, $zero, 0
000270b4  addiu     $a2, $zero, 0
000270b8  move      $a1, $s5
000270bc  jalr      $t1
000270c0  sw        $zero, 0x10($sp)
000270c4  lw        $fp, 0x18($sp)
000270c8  lw        $s7, 0x1c($sp)
000270cc  lw        $s6, 0x20($sp)
000270d0  lw        $s5, 0x24($sp)
000270d4  lw        $s4, 0x28($sp)
000270d8  lw        $s3, 0x2c($sp)
000270dc  lw        $s2, 0x30($sp)
000270e0  lw        $s1, 0x34($sp)
000270e4  lw        $s0, 0x38($sp)
000270e8  lw        $ra, 0x3c($sp)
000270ec  jr        $ra
000270f0  addiu     $sp, $sp, 0x40
00037140  jr        $ra
00037144  nop       
0003a750  addiu     $sp, $sp, -0x18
0003a754  sw        $ra, 0x10($sp)
0003a758  jal       0x8ac14 ; import thunk COREDLL.dll!memset@1047
0003a75c  nop       
0003a760  lw        $ra, 0x10($sp)
0003a764  jr        $ra
0003a768  addiu     $sp, $sp, 0x18
00085758  addiu     $sp, $sp, -0x18
0008575c  sw        $ra, 0x10($sp)
00085760  bnez      $a1, 0x85770
00085764  nop       
00085768  b         0x85778
0008576c  move      $v0, $zero
00085770  jal       0x8ac04 ; import thunk COREDLL.dll!memcpy@1044
00085774  nop       
00085778  lw        $ra, 0x10($sp)
0008577c  jr        $ra
00085780  addiu     $sp, $sp, 0x18
; coredll.dll 1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c
4007f774  addiu     $sp, $sp, -0x40
4007f778  sw        $ra, 0x38($sp)
4007f77c  sw        $s3, 0x28($sp)
4007f780  sw        $s2, 0x2c($sp)
4007f784  sw        $s1, 0x30($sp)
4007f788  sw        $s0, 0x34($sp)
4007f78c  addiu     $t0, $zero, 6
4007f790  lui       $s3, 0x400b
4007f794  move      $s2, $a0
4007f798  lw        $a0, 0x351c($s3)
4007f79c  move      $s0, $a2
4007f7a0  move      $s1, $a1
4007f7a4  bnez      $a0, 0x4007f7b8
4007f7a8  sw        $t0, 0x20($sp)
4007f7ac  jal       0x4007f730
4007f7b0  nop       
4007f7b4  lw        $a0, 0x351c($s3)
4007f7b8  lui       $t0, 0xffff
4007f7bc  ori       $t0, $t0, 0xffff
4007f7c0  beq       $a0, $t0, 0x4007f7f4
4007f7c4  nop       
4007f7c8  addiu     $t1, $sp, 0x24
4007f7cc  addiu     $t2, $zero, 4
4007f7d0  addiu     $t3, $sp, 0x20
4007f7d4  sll       $a3, $s1, 2
4007f7d8  move      $a2, $s0
4007f7dc  move      $a1, $s2
4007f7e0  sw        $zero, 0x1c($sp)
4007f7e4  sw        $t1, 0x18($sp)
4007f7e8  sw        $t2, 0x14($sp)
4007f7ec  jal       0x400320e4
4007f7f0  sw        $t3, 0x10($sp)
4007f7f4  lw        $v0, 0x20($sp)
4007f7f8  lw        $s3, 0x28($sp)
4007f7fc  lw        $s2, 0x2c($sp)
4007f800  lw        $s1, 0x30($sp)
4007f804  lw        $s0, 0x34($sp)
4007f808  lw        $ra, 0x38($sp)
4007f80c  jr        $ra
4007f810  addiu     $sp, $sp, 0x40
4007fcfc  addiu     $sp, $sp, -0x30
4007fd00  sw        $ra, 0x28($sp)
4007fd04  sw        $s3, 0x18($sp)
4007fd08  sw        $s2, 0x1c($sp)
4007fd0c  sw        $s1, 0x20($sp)
4007fd10  sw        $s0, 0x24($sp)
4007fd14  move      $s2, $a0
4007fd18  sw        $s2, 0x10($sp)
4007fd1c  move      $s1, $a1
4007fd20  bnez      $s1, 0x4007fd2c
4007fd24  lui       $a0, 0x26
4007fd28  lui       $a0, 0x25
4007fd2c  ori       $a0, $a0, 8
4007fd30  addiu     $a2, $sp, 0x10
4007fd34  jal       0x4007f774
4007fd38  addiu     $a1, $zero, 1
4007fd3c  move      $s0, $v0
4007fd40  bnez      $s0, 0x4007fdcc
4007fd44  nop       
4007fd48  jal       0x4009ea44
4007fd4c  nop       
4007fd50  move      $s3, $v0
4007fd54  bnez      $s3, 0x4007fd64
4007fd58  nop       
4007fd5c  b         0x4007fdcc
4007fd60  addiu     $s0, $zero, 7
4007fd64  move      $a1, $s2
4007fd68  jal       0x4009ece8
4007fd6c  move      $a0, $s3
4007fd70  move      $s2, $v0
4007fd74  bnez      $s2, 0x4007fd84
4007fd78  nop       
4007fd7c  b         0x4007fdcc
4007fd80  addiu     $s0, $zero, 0xb
4007fd84  addiu     $a1, $zero, 0x64
4007fd88  jal       0x4009e7c4
4007fd8c  move      $a0, $s2
4007fd90  bnez      $v0, 0x4007fd9c
4007fd94  nop       
4007fd98  addiu     $s0, $zero, 1
4007fd9c  bnez      $s1, 0x4007fda8
4007fda0  addiu     $a1, $zero, 0x3bc
4007fda4  addiu     $a1, $zero, 0x3bf
4007fda8  addiu     $a3, $zero, 0
4007fdac  addiu     $a2, $zero, 0
4007fdb0  jal       0x4009e854
4007fdb4  move      $a0, $s2
4007fdb8  move      $a1, $s2
4007fdbc  jal       0x4009ec88
4007fdc0  move      $a0, $s3
4007fdc4  jal       0x4009e768
4007fdc8  move      $a0, $s2
4007fdcc  move      $v0, $s0
4007fdd0  lw        $s3, 0x18($sp)
4007fdd4  lw        $s2, 0x1c($sp)
4007fdd8  lw        $s1, 0x20($sp)
4007fddc  lw        $s0, 0x24($sp)
4007fde0  lw        $ra, 0x28($sp)
4007fde4  jr        $ra
4007fde8  addiu     $sp, $sp, 0x30
4007fdec  addiu     $sp, $sp, -0x18
4007fdf0  sw        $ra, 0x10($sp)
4007fdf4  jal       0x4007fcfc
4007fdf8  addiu     $a1, $zero, 1
4007fdfc  lw        $ra, 0x10($sp)
4007fe00  jr        $ra
4007fe04  addiu     $sp, $sp, 0x18
4007fe84  addiu     $sp, $sp, -0x28
4007fe88  sw        $ra, 0x20($sp)
4007fe8c  sw        $s1, 0x18($sp)
4007fe90  sw        $s0, 0x1c($sp)
4007fe94  move      $s1, $a0
4007fe98  beqz      $a1, 0x4007feac
4007fe9c  sw        $s1, 0x10($sp)
4007fea0  lui       $a0, 0x26
4007fea4  b         0x4007feb4
4007fea8  ori       $a0, $a0, 0x3c
4007feac  lui       $a0, 0x25
4007feb0  ori       $a0, $a0, 0x2c
4007feb4  addiu     $a2, $sp, 0x10
4007feb8  jal       0x4007f774
4007febc  addiu     $a1, $zero, 1
4007fec0  move      $s0, $v0
4007fec4  bnez      $s0, 0x4007ff24
4007fec8  nop       
4007fecc  jal       0x4009ea44
4007fed0  nop       
4007fed4  bnez      $v0, 0x4007fee4
4007fed8  nop       
4007fedc  b         0x4007ff24
4007fee0  addiu     $s0, $zero, 7
4007fee4  move      $a1, $s1
4007fee8  jal       0x4009ece8
4007feec  move      $a0, $v0
4007fef0  move      $s1, $v0
4007fef4  bnez      $s1, 0x4007ff04
4007fef8  nop       
4007fefc  b         0x4007ff24
4007ff00  addiu     $s0, $zero, 0xb
4007ff04  addiu     $a1, $zero, 0x64
4007ff08  jal       0x4009e7c4
4007ff0c  move      $a0, $s1
4007ff10  bnez      $v0, 0x4007ff1c
4007ff14  nop       
4007ff18  addiu     $s0, $zero, 1
4007ff1c  jal       0x4009e768
4007ff20  move      $a0, $s1
4007ff24  move      $v0, $s0
4007ff28  lw        $s1, 0x18($sp)
4007ff2c  lw        $s0, 0x1c($sp)
4007ff30  lw        $ra, 0x20($sp)
4007ff34  jr        $ra
4007ff38  addiu     $sp, $sp, 0x28
4007ff3c  addiu     $sp, $sp, -0x18
4007ff40  sw        $ra, 0x10($sp)
4007ff44  jal       0x4007fe84
4007ff48  addiu     $a1, $zero, 1
4007ff4c  lw        $ra, 0x10($sp)
4007ff50  jr        $ra
4007ff54  addiu     $sp, $sp, 0x18
40080030  addiu     $sp, $sp, -0x28
40080034  sw        $ra, 0x20($sp)
40080038  sw        $a0, 0x10($sp)
4008003c  lui       $a0, 0x26
40080040  sw        $a1, 0x14($sp)
40080044  sw        $a2, 0x18($sp)
40080048  addiu     $a2, $sp, 0x10
4008004c  addiu     $a1, $zero, 3
40080050  jal       0x4007f774
40080054  ori       $a0, $a0, 0x50
40080058  lw        $ra, 0x20($sp)
4008005c  jr        $ra
40080060  addiu     $sp, $sp, 0x28
40080064  addiu     $sp, $sp, -0x28
40080068  sw        $ra, 0x20($sp)
4008006c  sw        $a0, 0x10($sp)
40080070  lui       $a0, 0x26
40080074  sw        $a1, 0x14($sp)
40080078  sw        $a2, 0x18($sp)
4008007c  addiu     $a2, $sp, 0x10
40080080  addiu     $a1, $zero, 3
40080084  jal       0x4007f774
40080088  ori       $a0, $a0, 0x54
4008008c  lw        $ra, 0x20($sp)
40080090  jr        $ra
40080094  addiu     $sp, $sp, 0x28
4009e768  addiu     $sp, $sp, -0x20
4009e76c  sw        $ra, 0x18($sp)
4009e770  sw        $s1, 0x10($sp)
4009e774  sw        $s0, 0x14($sp)
4009e778  move      $s0, $a0
4009e77c  jal       0x4005c020
4009e780  addiu     $a0, $s0, 0xc
4009e784  move      $s1, $v0
4009e788  bnez      $s1, 0x4009e7ac
4009e78c  nop       
4009e790  beqz      $s0, 0x4009e7ac
4009e794  nop       
4009e798  lw        $t0, ($s0)
4009e79c  addiu     $a1, $zero, 1
4009e7a0  lw        $t0, ($t0)
4009e7a4  jalr      $t0
4009e7a8  move      $a0, $s0
4009e7ac  move      $v0, $s1
4009e7b0  lw        $s1, 0x10($sp)
4009e7b4  lw        $s0, 0x14($sp)
4009e7b8  lw        $ra, 0x18($sp)
4009e7bc  jr        $ra
4009e7c0  addiu     $sp, $sp, 0x20
4009e7c4  addiu     $sp, $sp, -0x38
4009e7c8  sw        $ra, 0x34($sp)
4009e7cc  sw        $s2, 0x28($sp)
4009e7d0  sw        $s1, 0x2c($sp)
4009e7d4  sw        $s0, 0x30($sp)
4009e7d8  move      $s1, $a0
4009e7dc  addiu     $a0, $zero, 8
4009e7e0  jal       0x40030a84
4009e7e4  move      $s2, $a1
4009e7e8  lw        $a0, 0x28($s1)
4009e7ec  lw        $t0, 0x28($a0)
4009e7f0  beq       $v0, $t0, 0x4009e834
4009e7f4  nop       
4009e7f8  lui       $t1, 0xffff
4009e7fc  sw        $s1, 0x14($sp)
4009e800  ori       $t1, $t1, 0xffff
4009e804  addiu     $a1, $sp, 0x10
4009e808  jal       0x4009ebf0
4009e80c  sw        $t1, 0x10($sp)
4009e810  move      $s0, $v0
4009e814  beqz      $s0, 0x4009e838
4009e818  nop       
4009e81c  lw        $a0, 0x10($s1)
4009e820  jal       0x4002abe0
4009e824  move      $a1, $s2
4009e828  addiu     $a0, $zero, 0x102
4009e82c  bne       $v0, $a0, 0x4009e838
4009e830  nop       
4009e834  move      $s0, $zero
4009e838  move      $v0, $s0
4009e83c  lw        $s2, 0x28($sp)
4009e840  lw        $s1, 0x2c($sp)
4009e844  lw        $s0, 0x30($sp)
4009e848  lw        $ra, 0x34($sp)
4009e84c  jr        $ra
4009e850  addiu     $sp, $sp, 0x38
4009e854  addiu     $sp, $sp, -0x38
4009e858  sw        $ra, 0x34($sp)
4009e85c  sw        $s0, 0x30($sp)
4009e860  lui       $t0, 0xffff
4009e864  move      $t2, $a0
4009e868  ori       $t0, $t0, 0xffff
4009e86c  bne       $a1, $t0, 0x4009e888
4009e870  addiu     $s0, $zero, 1
4009e874  lw        $a0, 0x10($t2)
4009e878  jal       0x4002aacc
4009e87c  addiu     $a1, $zero, 3
4009e880  b         0x4009e994
4009e884  nop       
4009e888  lw        $t0, 0x1c($t2)
4009e88c  lui       $t1, 7
4009e890  lui       $t3, 1
4009e894  and       $t1, $t0, $t1
4009e898  beq       $t1, $t3, 0x4009e984
4009e89c  nop       
4009e8a0  lui       $t4, 2
4009e8a4  beq       $t1, $t4, 0x4009e96c
4009e8a8  nop       
4009e8ac  lui       $t0, 3
4009e8b0  beq       $t1, $t0, 0x4009e94c
4009e8b4  nop       
4009e8b8  lui       $t5, 5
4009e8bc  beq       $t1, $t5, 0x4009e920
4009e8c0  nop       
4009e8c4  lui       $t3, 6
4009e8c8  bne       $t1, $t3, 0x4009e994
4009e8cc  nop       
4009e8d0  lw        $t0, 0x20($t2)
4009e8d4  lw        $t1, 0x18($t2)
4009e8d8  swl       $a1, 0x1b($sp)
4009e8dc  swl       $a2, 0x27($sp)
4009e8e0  swl       $a3, 0x2b($sp)
4009e8e4  swr       $a1, 0x18($sp)
4009e8e8  swr       $a2, 0x24($sp)
4009e8ec  swr       $a3, 0x28($sp)
4009e8f0  lw        $a0, 0x24($t2)
4009e8f4  swl       $t0, 0x1f($sp)
4009e8f8  swl       $t1, 0x23($sp)
4009e8fc  addiu     $a3, $zero, 0
4009e900  addiu     $a2, $zero, 0x14
4009e904  addiu     $a1, $sp, 0x18
4009e908  swr       $t0, 0x1c($sp)
4009e90c  swr       $t1, 0x20($sp)
4009e910  jal       0x4002cb1c
4009e914  sw        $zero, 0x10($sp)
4009e918  b         0x4009e944
4009e91c  nop       
4009e920  addiu     $t0, $zero, 0x3c0
4009e924  beq       $a1, $t0, 0x4009e938
4009e928  nop       
4009e92c  addiu     $t1, $zero, 0x3bd
4009e930  bne       $a1, $t1, 0x4009e994
4009e934  nop       
4009e938  lw        $a0, 0x14($t2)
4009e93c  jal       0x4002aacc
4009e940  addiu     $a1, $zero, 3
4009e944  b         0x4009e994
4009e948  move      $s0, $v0
4009e94c  sw        $a3, 0x10($sp)
4009e950  move      $a3, $a2
4009e954  lw        $a2, 0x18($t2)
4009e958  lw        $t0, 0x14($t2)
4009e95c  jalr      $t0
4009e960  lw        $a0, 0x20($t2)
4009e964  b         0x4009e994
4009e968  nop       
4009e96c  move      $a3, $a2
4009e970  lw        $a2, 0x20($t2)
4009e974  jal       0x4002837c
4009e978  lw        $a0, 0x14($t2)
4009e97c  b         0x4009e994
4009e980  nop       
4009e984  move      $a3, $a2
4009e988  lw        $a2, 0x20($t2)
4009e98c  jal       0x40028b84
4009e990  lw        $a0, 0x14($t2)
4009e994  move      $v0, $s0
4009e998  lw        $s0, 0x30($sp)
4009e99c  lw        $ra, 0x34($sp)
4009e9a0  jr        $ra
4009e9a4  addiu     $sp, $sp, 0x38
