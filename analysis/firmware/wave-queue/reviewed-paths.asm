; waveapi.dll 75dda3a4642c385b50c71e262c0676e61d7ee28e736d2093270dbabcf8fbc975
c03f1000  addiu     $sp, $sp, -0x38
c03f1004  sw        $ra, 0x34($sp)
c03f1008  sw        $s0, 0x30($sp)
c03f100c  lw        $t0, 0x24($a0)
c03f1010  lw        $t1, 0x48($sp)
c03f1014  sw        $a1, 0x18($sp)
c03f1018  sw        $a2, 0x20($sp)
c03f101c  sw        $a3, 0x24($sp)
c03f1020  lw        $a0, 0x20($a0)
c03f1024  addiu     $a3, $zero, 0
c03f1028  addiu     $a2, $zero, 0x14
c03f102c  addiu     $a1, $sp, 0x18
c03f1030  sw        $t0, 0x1c($sp)
c03f1034  sw        $t1, 0x28($sp)
c03f1038  jal       0xc03ff93c ; import thunk COREDLL.dll!WriteMsgQueue@1531
c03f103c  sw        $zero, 0x10($sp)
c03f1040  move      $s0, $v0
c03f1044  bnez      $s0, 0xc03f105c
c03f1048  nop       
c03f104c  lui       $t0, 0xc040
c03f1050  lw        $t0, 0x1150($t0) ; IAT COREDLL.dll!GetLastError@516
c03f1054  jalr      $t0 ; call candidate COREDLL.dll!GetLastError@516
c03f1058  nop       
c03f105c  move      $v0, $s0
c03f1060  lw        $s0, 0x30($sp)
c03f1064  lw        $ra, 0x34($sp)
c03f1068  jr        $ra
c03f106c  addiu     $sp, $sp, 0x38
c03f10b0  addiu     $sp, $sp, -0x30
c03f10b4  sw        $ra, 0x28($sp)
c03f10b8  sw        $s3, 0x18($sp)
c03f10bc  sw        $s2, 0x1c($sp)
c03f10c0  sw        $s1, 0x20($sp)
c03f10c4  sw        $s0, 0x24($sp)
c03f10c8  move      $s2, $a3
c03f10cc  move      $s1, $a1
c03f10d0  move      $s0, $a0
c03f10d4  addiu     $s3, $zero, 1
c03f10d8  addiu     $t0, $zero, 0x3bd
c03f10dc  beq       $s1, $t0, 0xc03f10f8
c03f10e0  addiu     $t2, $zero, 2
c03f10e4  addiu     $t1, $zero, 0x3c0
c03f10e8  bne       $s1, $t1, 0xc03f1158
c03f10ec  nop       
c03f10f0  b         0xc03f10fc
c03f10f4  move      $t0, $s3
c03f10f8  move      $t0, $t2
c03f10fc  bne       $t0, $s3, 0xc03f1110
c03f1100  lw        $t1, 0x34($s0)
c03f1104  lui       $t2, 0xc040
c03f1108  b         0xc03f1120
c03f110c  lw        $t0, 0x1214($t2)
c03f1110  bne       $t0, $t2, 0xc03f1128
c03f1114  nop       
c03f1118  lui       $t2, 0xc040
c03f111c  lw        $t0, 0x11f0($t2)
c03f1120  beq       $t1, $t0, 0xc03f113c
c03f1124  nop       
c03f1128  jal       0xc03ff92c ; import thunk COREDLL.dll!InterlockedDecrement@11
c03f112c  addiu     $a0, $s0, 0x58
c03f1130  bnez      $v0, 0xc03f113c
c03f1134  nop       
c03f1138  sw        $s3, 0x60($s0)
c03f113c  lw        $t0, 8($s2)
c03f1140  lw        $a3, 0x40($sp)
c03f1144  lw        $a2, 0x24($s2)
c03f1148  move      $a1, $s1
c03f114c  move      $a0, $s0
c03f1150  jal       0xc03f1000
c03f1154  sw        $t0, 0x10($sp)
c03f1158  lw        $s3, 0x18($sp)
c03f115c  lw        $s2, 0x1c($sp)
c03f1160  lw        $s1, 0x20($sp)
c03f1164  lw        $s0, 0x24($sp)
c03f1168  lw        $ra, 0x28($sp)
c03f116c  jr        $ra
c03f1170  addiu     $sp, $sp, 0x30
c03f2aa4  addiu     $sp, $sp, -0x28
c03f2aa8  sw        $ra, 0x20($sp)
c03f2aac  sw        $s1, 0x18($sp)
c03f2ab0  sw        $s0, 0x1c($sp)
c03f2ab4  move      $s0, $a1
c03f2ab8  addiu     $t0, $s0, 0x1c
c03f2abc  lwl       $a1, 3($t0)
c03f2ac0  move      $s1, $a2
c03f2ac4  lui       $t1, 0xc040
c03f2ac8  move      $a2, $a0
c03f2acc  lwr       $a1, ($t0)
c03f2ad0  addiu     $a3, $zero, 5
c03f2ad4  addiu     $a0, $t1, 0x136c
c03f2ad8  jal       0xc03f8000
c03f2adc  sw        $zero, 0x10($sp)
c03f2ae0  beqz      $v0, 0xc03f2b24
c03f2ae4  nop       
c03f2ae8  lw        $t0, 0x24($v0)
c03f2aec  bne       $t0, $s1, 0xc03f2b24
c03f2af0  nop       
c03f2af4  addiu     $t2, $s0, 4
c03f2af8  lwl       $t1, 3($t2)
c03f2afc  lw        $t3, 0x2c($v0)
c03f2b00  lwr       $t1, ($t2)
c03f2b04  sltu      $t0, $t3, $t1
c03f2b08  bnez      $t0, 0xc03f2b24
c03f2b0c  nop       
c03f2b10  lwl       $t1, 3($s0)
c03f2b14  lw        $t2, 0x28($v0)
c03f2b18  lwr       $t1, ($s0)
c03f2b1c  beq       $t2, $t1, 0xc03f2b28
c03f2b20  nop       
c03f2b24  move      $v0, $zero
c03f2b28  lw        $s1, 0x18($sp)
c03f2b2c  lw        $s0, 0x1c($sp)
c03f2b30  lw        $ra, 0x20($sp)
c03f2b34  jr        $ra
c03f2b38  addiu     $sp, $sp, 0x28
c03f3410  addiu     $sp, $sp, -0x88
c03f3414  sw        $ra, 0x80($sp)
c03f3418  sw        $fp, 0x70($sp)
c03f341c  sw        $s2, 0x74($sp)
c03f3420  sw        $s1, 0x78($sp)
c03f3424  sw        $s0, 0x7c($sp)
c03f3428  move      $fp, $sp
c03f342c  move      $t1, $a2
c03f3430  move      $s0, $a1
c03f3434  move      $s1, $a0
c03f3438  addiu     $s2, $zero, 1
c03f343c  sltiu     $t0, $a3, 0x21
c03f3440  bnez      $t0, 0xc03f3468
c03f3444  nop       
c03f3448  addiu     $a0, $zero, 0x57
c03f344c  lui       $t2, 0xc040
c03f3450  lw        $t1, 0x103c($t2) ; IAT COREDLL.dll!SetLastError@517
c03f3454  jalr      $t1 ; call candidate COREDLL.dll!SetLastError@517
c03f3458  nop       
c03f345c  move      $s2, $zero
c03f3460  b         0xc03f456c
c03f3464  nop       
c03f3468  beqz      $t1, 0xc03f348c
c03f346c  nop       
c03f3470  beqz      $a3, 0xc03f348c
c03f3474  nop       
c03f3478  move      $a2, $a3
c03f347c  move      $a1, $t1
c03f3480  addiu     $a0, $fp, 0x50
c03f3484  jal       0xc0400564 ; import thunk COREDLL.dll!memcpy@1044
c03f3488  nop       
c03f348c  lui       $t0, 0x1d
c03f3490  ori       $t0, $t0, 0x341
c03f3494  sltu      $t0, $s0, $t0
c03f3498  beqz      $t0, 0xc03f3d04
c03f349c  nop       
c03f34a0  lui       $t1, 0x1d
c03f34a4  ori       $t1, $t1, 0x340
c03f34a8  beq       $s0, $t1, 0xc03f3ce4
c03f34ac  nop       
c03f34b0  lui       $t2, 0x1d
c03f34b4  ori       $t2, $t2, 0x215
c03f34b8  sltu      $t1, $s0, $t2
c03f34bc  beqz      $t1, 0xc03f38f4
c03f34c0  nop       
c03f34c4  lui       $t0, 0x1d
c03f34c8  ori       $t0, $t0, 0x214
c03f34cc  beq       $s0, $t0, 0xc03f38cc
c03f34d0  nop       
c03f34d4  lui       $t3, 0x1d
c03f34d8  ori       $t3, $t3, 0x1d5
c03f34dc  sltu      $t0, $s0, $t3
c03f34e0  lui       $t1, 0x1d
c03f34e4  beqz      $t0, 0xc03f3718
c03f34e8  nop       
c03f34ec  ori       $t1, $t1, 0x1d4
c03f34f0  beq       $s0, $t1, 0xc03f36fc
c03f34f4  nop       
c03f34f8  lui       $t2, 0x1d
c03f34fc  ori       $t2, $t2, 0x1c1
c03f3500  sltu      $t1, $s0, $t2
c03f3504  beqz      $t1, 0xc03f3650
c03f3508  nop       
c03f350c  lui       $t0, 0x1d
c03f3510  ori       $t0, $t0, 0x1c0
c03f3514  beq       $s0, $t0, 0xc03f3634
c03f3518  nop       
c03f351c  lui       $t3, 0x1d
c03f3520  ori       $t3, $t3, 4
c03f3524  subu      $t0, $s0, $t3
c03f3528  beqz      $t0, 0xc03f361c
c03f352c  nop       
c03f3530  addiu     $t0, $t0, -4
c03f3534  beqz      $t0, 0xc03f3600
c03f3538  nop       
c03f353c  addiu     $t0, $t0, -8
c03f3540  beqz      $t0, 0xc03f35a0
c03f3544  nop       
c03f3548  addiu     $t0, $t0, -0x1a8
c03f354c  beqz      $t0, 0xc03f3578
c03f3550  nop       
c03f3554  addiu     $t0, $t0, -4
c03f3558  bnez      $t0, 0xc03f4534
c03f355c  nop       
c03f3560  lw        $a1, 0x54($fp)
c03f3564  lw        $a0, 0x50($fp)
c03f3568  jal       0xc03ffd4c
c03f356c  nop       
c03f3570  b         0xc03f4108
c03f3574  nop       
c03f3578  lw        $t1, 0x60($fp)
c03f357c  sw        $t1, 0x10($sp)
c03f3580  lw        $a3, 0x5c($fp)
c03f3584  lw        $a2, 0x58($fp)
c03f3588  lw        $a1, 0x54($fp)
c03f358c  lw        $a0, 0x50($fp)
c03f3590  jal       0xc03ffd4c
c03f3594  nop       
c03f3598  b         0xc03f4108
c03f359c  nop       
c03f35a0  addiu     $t1, $zero, 0x14
c03f35a4  sw        $t1, 0x38($fp)
c03f35a8  sw        $zero, 0x48($fp)
c03f35ac  jal       0xc03ff96c ; import thunk COREDLL.dll!GetDirectCallerProcessId@2604
c03f35b0  nop       
c03f35b4  addiu     $a2, $fp, 0x38
c03f35b8  lw        $a1, 0x50($fp)
c03f35bc  move      $a0, $v0
c03f35c0  jal       0xc03ff95c ; import thunk COREDLL.dll!OpenMsgQueue@1536
c03f35c4  nop       
c03f35c8  bnez      $v0, 0xc03f35f4
c03f35cc  nop       
c03f35d0  move      $s2, $zero
c03f35d4  sw        $s2, 0x30($fp)
c03f35d8  addiu     $a0, $zero, 0x57
c03f35dc  lui       $t0, 0xc040
c03f35e0  lw        $t0, 0x103c($t0) ; IAT COREDLL.dll!SetLastError@517
c03f35e4  jalr      $t0 ; call candidate COREDLL.dll!SetLastError@517
c03f35e8  nop       
c03f35ec  b         0xc03f453c
c03f35f0  nop       
c03f35f4  sw        $v0, 4($s1)
c03f35f8  b         0xc03f453c
c03f35fc  nop       
c03f3600  lw        $a2, 0x58($fp)
c03f3604  lw        $a1, 0x54($fp)
c03f3608  lw        $a0, 0x50($fp)
c03f360c  jal       0xc03f6ee4
c03f3610  nop       
c03f3614  b         0xc03f4108
c03f3618  nop       
c03f361c  lw        $a1, 0x54($fp)
c03f3620  lw        $a0, 0x50($fp)
c03f3624  jal       0xc03f721c
c03f3628  nop       
c03f362c  b         0xc03f4108
c03f3630  nop       
c03f3634  lw        $a2, 0x58($fp)
c03f3638  lw        $a1, 0x54($fp)
c03f363c  lw        $a0, 0x50($fp)
c03f3640  jal       0xc03ffd4c
c03f3644  nop       
c03f3648  b         0xc03f4108
c03f364c  nop       
c03f3650  lui       $t1, 0x1d
c03f3654  ori       $t1, $t1, 0x1c4
c03f3658  subu      $t1, $s0, $t1
c03f365c  beqz      $t1, 0xc03f36e0
c03f3660  nop       
c03f3664  addiu     $t0, $t1, -4
c03f3668  beqz      $t0, 0xc03f36c4
c03f366c  nop       
c03f3670  addiu     $t1, $t0, -4
c03f3674  beqz      $t1, 0xc03f36a4
c03f3678  nop       
c03f367c  addiu     $t0, $t1, -4
c03f3680  bnez      $t0, 0xc03f4534
c03f3684  nop       
c03f3688  lw        $a2, 0x58($fp)
c03f368c  lw        $a1, 0x54($fp)
c03f3690  lw        $a0, 0x50($fp)
c03f3694  jal       0xc03ffd4c
c03f3698  nop       
c03f369c  b         0xc03f4108
c03f36a0  nop       
c03f36a4  lw        $a3, 0x5c($fp)
c03f36a8  lw        $a2, 0x58($fp)
c03f36ac  lw        $a1, 0x54($fp)
c03f36b0  lw        $a0, 0x50($fp)
c03f36b4  jal       0xc03ffd4c
c03f36b8  nop       
c03f36bc  b         0xc03f4108
c03f36c0  nop       
c03f36c4  lw        $a2, 0x58($fp)
c03f36c8  lw        $a1, 0x54($fp)
c03f36cc  lw        $a0, 0x50($fp)
c03f36d0  jal       0xc03ffd4c
c03f36d4  nop       
c03f36d8  b         0xc03f4108
c03f36dc  nop       
c03f36e0  lw        $a2, 0x58($fp)
c03f36e4  lw        $a1, 0x54($fp)
c03f36e8  lw        $a0, 0x50($fp)
c03f36ec  jal       0xc03ffd4c
c03f36f0  nop       
c03f36f4  b         0xc03f4108
c03f36f8  nop       
c03f36fc  lw        $a2, 0x58($fp)
c03f3700  lw        $a1, 0x54($fp)
c03f3704  lw        $a0, 0x50($fp)
c03f3708  jal       0xc03ffd4c
c03f370c  nop       
c03f3710  b         0xc03f4108
c03f3714  nop       
c03f3718  ori       $t1, $t1, 0x1d8
c03f371c  subu      $t3, $s0, $t1
c03f3720  sltiu     $t1, $t3, 0x39
c03f3724  beqz      $t1, 0xc03f4534
c03f3728  nop       
c03f372c  lui       $t2, 0xc03f
c03f3730  addiu     $t2, $t2, 0x374c
c03f3734  sll       $t0, $t3, 1
c03f3738  addu      $t0, $t0, $t2
c03f373c  lh        $t0, ($t0)
c03f3740  addu      $t2, $t2, $t0
c03f3744  jr        $t2
c03f3748  nop       
c03f374c  jal       0xc7a001d0
c03f3750  jal       0xc7a037a0
c03f3754  jal       0xc7a037a0
c03f3758  jal       0xc7a037a0
c03f375c  jal       0xc7a00230
c03f3760  jal       0xc7a037a0
c03f3764  jal       0xc7a00280
c03f3768  jal       0xc7a037a0
c03f376c  jal       0xc7a002f0
c03f3770  jal       0xc7a037a0
c03f3774  jal       0xc7a00390
c03f3778  jal       0xc7a037a0
c03f377c  jal       0xc7a00400
c03f3780  jal       0xc7a037a0
c03f3784  jal       0xc7a037a0
c03f3788  jal       0xc7a037a0
c03f378c  jal       0xc7a037a0
c03f3790  jal       0xc7a037a0
c03f3794  jal       0xc7a037a0
c03f3798  jal       0xc7a037a0
c03f379c  jal       0xc7a037a0
c03f37a0  jal       0xc7a037a0
c03f37a4  jal       0xc7a037a0
c03f37a8  jal       0xc7a037a0
c03f37ac  jal       0xc7a004a0
c03f37b0  jal       0xc7a037a0
c03f37b4  jal       0xc7a004f0
c03f37b8  jal       0xc7a037a0
c03f37bc  .byte     0x58, 0x01, 0x00, 0x00
c03f37c0  lw        $a1, 0x54($fp)
c03f37c4  lw        $a0, 0x50($fp)
c03f37c8  jal       0xc03ffd4c
c03f37cc  nop       
c03f37d0  b         0xc03f4108
c03f37d4  nop       
c03f37d8  lw        $a0, 0x50($fp)
c03f37dc  jal       0xc03ffd4c
c03f37e0  nop       
c03f37e4  b         0xc03f4108
c03f37e8  nop       
c03f37ec  lw        $a2, 0x58($fp)
c03f37f0  lw        $a1, 0x54($fp)
c03f37f4  lw        $a0, 0x50($fp)
c03f37f8  jal       0xc03ffd4c
c03f37fc  nop       
c03f3800  b         0xc03f4108
c03f3804  nop       
c03f3808  lw        $t1, 0x60($fp)
c03f380c  sw        $t1, 0x10($sp)
c03f3810  lw        $a3, 0x5c($fp)
c03f3814  lw        $a2, 0x58($fp)
c03f3818  lw        $a1, 0x54($fp)
c03f381c  lw        $a0, 0x50($fp)
c03f3820  jal       0xc03ffd4c
c03f3824  nop       
c03f3828  b         0xc03f4108
c03f382c  nop       
c03f3830  lw        $a2, 0x58($fp)
c03f3834  lw        $a1, 0x54($fp)
c03f3838  lw        $a0, 0x50($fp)
c03f383c  jal       0xc03ffd4c
c03f3840  nop       
c03f3844  b         0xc03f4108
c03f3848  nop       
c03f384c  lw        $t1, 0x60($fp)
c03f3850  sw        $t1, 0x10($sp)
c03f3854  lw        $a3, 0x5c($fp)
c03f3858  lw        $a2, 0x58($fp)
c03f385c  lw        $a1, 0x54($fp)
c03f3860  lw        $a0, 0x50($fp)
c03f3864  jal       0xc03ffd4c
c03f3868  nop       
c03f386c  b         0xc03f4108
c03f3870  nop       
c03f3874  lw        $a0, 0x50($fp)
c03f3878  jal       0xc03ffd4c
c03f387c  nop       
c03f3880  b         0xc03f4108
c03f3884  nop       
c03f3888  lw        $a2, 0x58($fp)
c03f388c  lw        $a1, 0x54($fp)
c03f3890  lw        $a0, 0x50($fp)
c03f3894  jal       0xc03ffd4c
c03f3898  nop       
c03f389c  b         0xc03f4108
c03f38a0  nop       
c03f38a4  lw        $t1, 0x60($fp)
c03f38a8  sw        $t1, 0x10($sp)
c03f38ac  lw        $a3, 0x5c($fp)
c03f38b0  lw        $a2, 0x58($fp)
c03f38b4  lw        $a1, 0x54($fp)
c03f38b8  lw        $a0, 0x50($fp)
c03f38bc  jal       0xc03ffd4c
c03f38c0  nop       
c03f38c4  b         0xc03f4108
c03f38c8  nop       
c03f38cc  lw        $t1, 0x60($fp)
c03f38d0  sw        $t1, 0x10($sp)
c03f38d4  lw        $a3, 0x5c($fp)
c03f38d8  lw        $a2, 0x58($fp)
c03f38dc  lw        $a1, 0x54($fp)
c03f38e0  lw        $a0, 0x50($fp)
c03f38e4  jal       0xc03ffd4c
c03f38e8  nop       
c03f38ec  b         0xc03f4108
c03f38f0  nop       
c03f38f4  lui       $t1, 0x1d
c03f38f8  ori       $t1, $t1, 0x259
c03f38fc  sltu      $t1, $s0, $t1
c03f3900  beqz      $t1, 0xc03f3b14
c03f3904  nop       
c03f3908  lui       $t0, 0x1d
c03f390c  ori       $t0, $t0, 0x258
c03f3910  beq       $s0, $t0, 0xc03f3b04
c03f3914  nop       
c03f3918  lui       $t2, 0x1d
c03f391c  ori       $t2, $t2, 0x218
c03f3920  subu      $t3, $s0, $t2
c03f3924  sltiu     $t0, $t3, 0x35
c03f3928  beqz      $t0, 0xc03f4534
c03f392c  nop       
c03f3930  lui       $t2, 0xc03f
c03f3934  addiu     $t2, $t2, 0x3950
c03f3938  sll       $t1, $t3, 1
c03f393c  addu      $t1, $t1, $t2
c03f3940  lh        $t1, ($t1)
c03f3944  addu      $t2, $t2, $t1
c03f3948  jr        $t2
c03f394c  nop       
c03f3950  j         0xcf9005c0
c03f3954  j         0xcf902f90
c03f3958  j         0xcf900630
c03f395c  j         0xcf902f90
c03f3960  j         0xcf902f90
c03f3964  j         0xcf902f90
c03f3968  j         0xcf902f90
c03f396c  j         0xcf902f90
c03f3970  j         0xcf902f90
c03f3974  j         0xcf902f90
c03f3978  j         0xcf902f90
c03f397c  j         0xcf902f90
c03f3980  j         0xcf9001b0
c03f3984  j         0xcf902f90
c03f3988  j         0xcf900210
c03f398c  j         0xcf902f90
c03f3990  j         0xcf900280
c03f3994  j         0xcf902f90
c03f3998  j         0xcf900300
c03f399c  j         0xcf902f90
c03f39a0  j         0xcf900400
c03f39a4  j         0xcf902f90
c03f39a8  j         0xcf900470
c03f39ac  j         0xcf902f90
c03f39b0  j         0xcf9004d0
c03f39b4  j         0xcf902f90
c03f39b8  .byte     0x54, 0x01, 0x00, 0x00
c03f39bc  lw        $a1, 0x54($fp)
c03f39c0  lw        $a0, 0x50($fp)
c03f39c4  jal       0xc03ffd4c
c03f39c8  nop       
c03f39cc  b         0xc03f4108
c03f39d0  nop       
c03f39d4  lw        $a2, 0x58($fp)
c03f39d8  lw        $a1, 0x54($fp)
c03f39dc  lw        $a0, 0x50($fp)
c03f39e0  jal       0xc03ffd4c
c03f39e4  nop       
c03f39e8  b         0xc03f4108
c03f39ec  nop       
c03f39f0  lw        $a3, 0x5c($fp)
c03f39f4  lw        $a2, 0x58($fp)
c03f39f8  lw        $a1, 0x54($fp)
c03f39fc  lw        $a0, 0x50($fp)
c03f3a00  jal       0xc03ffd4c
c03f3a04  nop       
c03f3a08  b         0xc03f4108
c03f3a0c  nop       
c03f3a10  lw        $t1, 0x6c($fp)
c03f3a14  sw        $t1, 0x1c($sp)
c03f3a18  lw        $t2, 0x68($fp)
c03f3a1c  sw        $t2, 0x18($sp)
c03f3a20  lw        $t0, 0x64($fp)
c03f3a24  sw        $t0, 0x14($sp)
c03f3a28  lw        $t3, 0x60($fp)
c03f3a2c  sw        $t3, 0x10($sp)
c03f3a30  lw        $a3, 0x5c($fp)
c03f3a34  lw        $a2, 0x58($fp)
c03f3a38  lw        $a1, 0x54($fp)
c03f3a3c  lw        $a0, 0x50($fp)
c03f3a40  jal       0xc03ffd4c
c03f3a44  nop       
c03f3a48  b         0xc03f4108
c03f3a4c  nop       
c03f3a50  lw        $a2, 0x58($fp)
c03f3a54  lw        $a1, 0x54($fp)
c03f3a58  lw        $a0, 0x50($fp)
c03f3a5c  jal       0xc03ffd4c
c03f3a60  nop       
c03f3a64  b         0xc03f4108
c03f3a68  nop       
c03f3a6c  lw        $a1, 0x54($fp)
c03f3a70  lw        $a0, 0x50($fp)
c03f3a74  jal       0xc03ffd4c
c03f3a78  nop       
c03f3a7c  b         0xc03f4108
c03f3a80  nop       
c03f3a84  lw        $a3, 0x5c($fp)
c03f3a88  lw        $a2, 0x58($fp)
c03f3a8c  lw        $a1, 0x54($fp)
c03f3a90  lw        $a0, 0x50($fp)
c03f3a94  jal       0xc03ffd4c
c03f3a98  nop       
c03f3a9c  b         0xc03f4108
c03f3aa0  nop       
c03f3aa4  lw        $a2, 0x58($fp)
c03f3aa8  lw        $a1, 0x54($fp)
c03f3aac  lw        $a0, 0x50($fp)
c03f3ab0  jal       0xc03ffd4c
c03f3ab4  nop       
c03f3ab8  b         0xc03f4108
c03f3abc  nop       
c03f3ac0  lw        $a2, 0x58($fp)
c03f3ac4  lw        $a1, 0x54($fp)
c03f3ac8  lw        $a0, 0x50($fp)
c03f3acc  jal       0xc03ffd4c
c03f3ad0  nop       
c03f3ad4  b         0xc03f4108
c03f3ad8  nop       
c03f3adc  lw        $t1, 0x60($fp)
c03f3ae0  sw        $t1, 0x10($sp)
c03f3ae4  lw        $a3, 0x5c($fp)
c03f3ae8  lw        $a2, 0x58($fp)
c03f3aec  lw        $a1, 0x54($fp)
c03f3af0  lw        $a0, 0x50($fp)
c03f3af4  jal       0xc03ffd4c
c03f3af8  nop       
c03f3afc  b         0xc03f4108
c03f3b00  nop       
c03f3b04  jal       0xc03ffd4c
c03f3b08  nop       
c03f3b0c  b         0xc03f4108
c03f3b10  nop       
c03f3b14  lui       $t1, 0x1d
c03f3b18  ori       $t1, $t1, 0x32d
c03f3b1c  sltu      $t1, $s0, $t1
c03f3b20  beqz      $t1, 0xc03f3c1c
c03f3b24  nop       
c03f3b28  lui       $t0, 0x1d
c03f3b2c  ori       $t0, $t0, 0x32c
c03f3b30  beq       $s0, $t0, 0xc03f3bfc
c03f3b34  nop       
c03f3b38  lui       $t2, 0x1d
c03f3b3c  ori       $t2, $t2, 0x25c
c03f3b40  subu      $t0, $s0, $t2
c03f3b44  beqz      $t0, 0xc03f3be0
c03f3b48  nop       
c03f3b4c  addiu     $t0, $t0, -0xc4
c03f3b50  beqz      $t0, 0xc03f3bc0
c03f3b54  nop       
c03f3b58  addiu     $t1, $t0, -4
c03f3b5c  beqz      $t1, 0xc03f3b90
c03f3b60  nop       
c03f3b64  addiu     $t0, $t1, -4
c03f3b68  bnez      $t0, 0xc03f4534
c03f3b6c  nop       
c03f3b70  lw        $a3, 0x58($fp)
c03f3b74  lw        $a2, 0x54($fp)
c03f3b78  lw        $a1, 0x50($fp)
c03f3b7c  move      $a0, $s1
c03f3b80  jal       0xc03fbe10
c03f3b84  nop       
c03f3b88  b         0xc03f4108
c03f3b8c  nop       
c03f3b90  addiu     $t1, $zero, 2
c03f3b94  sw        $t1, 0x14($sp)
c03f3b98  lw        $t1, 0x58($fp)
c03f3b9c  sw        $t1, 0x10($sp)
c03f3ba0  lw        $a3, 0x54($fp)
c03f3ba4  lw        $a2, 0x50($fp)
c03f3ba8  addiu     $a1, $zero, 3
c03f3bac  move      $a0, $s1
c03f3bb0  jal       0xc03f8c8c
c03f3bb4  nop       
c03f3bb8  b         0xc03f4108
c03f3bbc  nop       
c03f3bc0  lw        $a3, 0x58($fp)
c03f3bc4  lw        $a2, 0x54($fp)
c03f3bc8  lw        $a1, 0x50($fp)
c03f3bcc  move      $a0, $s1
c03f3bd0  jal       0xc03fc584
c03f3bd4  nop       
c03f3bd8  b         0xc03f4108
c03f3bdc  nop       
c03f3be0  lw        $a2, 0x58($fp)
c03f3be4  lw        $a1, 0x54($fp)
c03f3be8  lw        $a0, 0x50($fp)
c03f3bec  jal       0xc03ffd4c
c03f3bf0  nop       
c03f3bf4  b         0xc03f4108
c03f3bf8  nop       
c03f3bfc  lw        $a3, 0x58($fp)
c03f3c00  lw        $a2, 0x54($fp)
c03f3c04  lw        $a1, 0x50($fp)
c03f3c08  move      $a0, $s1
c03f3c0c  jal       0xc03fc664
c03f3c10  nop       
c03f3c14  b         0xc03f4108
c03f3c18  nop       
c03f3c1c  lui       $t1, 0x1d
c03f3c20  ori       $t1, $t1, 0x330
c03f3c24  subu      $t1, $s0, $t1
c03f3c28  beqz      $t1, 0xc03f3cc4
c03f3c2c  nop       
c03f3c30  addiu     $t0, $t1, -4
c03f3c34  beqz      $t0, 0xc03f3cb4
c03f3c38  nop       
c03f3c3c  addiu     $t1, $t0, -4
c03f3c40  beqz      $t1, 0xc03f3c84
c03f3c44  nop       
c03f3c48  addiu     $t0, $t1, -4
c03f3c4c  bnez      $t0, 0xc03f4534
c03f3c50  nop       
c03f3c54  lw        $t1, 0x60($fp)
c03f3c58  sw        $t1, 0x14($sp)
c03f3c5c  lw        $t2, 0x5c($fp)
c03f3c60  sw        $t2, 0x10($sp)
c03f3c64  lw        $a3, 0x58($fp)
c03f3c68  lw        $a2, 0x54($fp)
c03f3c6c  lw        $a1, 0x50($fp)
c03f3c70  move      $a0, $s1
c03f3c74  jal       0xc03fc0c8
c03f3c78  nop       
c03f3c7c  b         0xc03f4108
c03f3c80  nop       
c03f3c84  lw        $t1, 0x5c($fp)
c03f3c88  sw        $t1, 0x14($sp)
c03f3c8c  lw        $t2, 0x58($fp)
c03f3c90  sw        $t2, 0x10($sp)
c03f3c94  lw        $a3, 0x54($fp)
c03f3c98  lw        $a2, 0x50($fp)
c03f3c9c  addiu     $a1, $zero, 3
c03f3ca0  move      $a0, $s1
c03f3ca4  jal       0xc03f8a58
c03f3ca8  nop       
c03f3cac  b         0xc03f4108
c03f3cb0  nop       
c03f3cb4  jal       0xc03ffcdc ; import thunk AUDEVMAN.dll!audmGetNumMixerDevices
c03f3cb8  nop       
c03f3cbc  b         0xc03f4108
c03f3cc0  nop       
c03f3cc4  lw        $a3, 0x58($fp)
c03f3cc8  lw        $a2, 0x54($fp)
c03f3ccc  lw        $a1, 0x50($fp)
c03f3cd0  move      $a0, $s1
c03f3cd4  jal       0xc03fbf30
c03f3cd8  nop       
c03f3cdc  b         0xc03f4108
c03f3ce0  nop       
c03f3ce4  lw        $a3, 0x58($fp)
c03f3ce8  lw        $a2, 0x54($fp)
c03f3cec  lw        $a1, 0x50($fp)
c03f3cf0  move      $a0, $s1
c03f3cf4  jal       0xc03fc9bc
c03f3cf8  nop       
c03f3cfc  b         0xc03f4108
c03f3d00  nop       
c03f3d04  lui       $t1, 0x26
c03f3d08  ori       $t1, $t1, 0x11
c03f3d0c  sltu      $t1, $s0, $t1
c03f3d10  beqz      $t1, 0xc03f4194
c03f3d14  nop       
c03f3d18  lui       $t0, 0x26
c03f3d1c  ori       $t0, $t0, 0x10
c03f3d20  beq       $s0, $t0, 0xc03f416c
c03f3d24  nop       
c03f3d28  lui       $t2, 0x25
c03f3d2c  ori       $t2, $t2, 0x29
c03f3d30  sltu      $t0, $s0, $t2
c03f3d34  lui       $t1, 0x25
c03f3d38  beqz      $t0, 0xc03f3f60
c03f3d3c  nop       
c03f3d40  ori       $t1, $t1, 0x28
c03f3d44  beq       $s0, $t1, 0xc03f3f38
c03f3d48  nop       
c03f3d4c  lui       $t3, 0x25
c03f3d50  ori       $t3, $t3, 0x15
c03f3d54  sltu      $t1, $s0, $t3
c03f3d58  beqz      $t1, 0xc03f3e60
c03f3d5c  nop       
c03f3d60  lui       $t0, 0x25
c03f3d64  ori       $t0, $t0, 0x14
c03f3d68  beq       $s0, $t0, 0xc03f3e54
c03f3d6c  nop       
c03f3d70  lui       $t2, 0x1d
c03f3d74  ori       $t2, $t2, 0x344
c03f3d78  subu      $t0, $s0, $t2
c03f3d7c  beqz      $t0, 0xc03f3e48
c03f3d80  nop       
c03f3d84  lui       $t1, 7
c03f3d88  ori       $t1, $t1, 0xfcc0
c03f3d8c  subu      $t0, $t0, $t1
c03f3d90  beqz      $t0, 0xc03f3e20
c03f3d94  nop       
c03f3d98  addiu     $t0, $t0, -4
c03f3d9c  beqz      $t0, 0xc03f3e14
c03f3da0  nop       
c03f3da4  addiu     $t1, $t0, -4
c03f3da8  beqz      $t1, 0xc03f3de4
c03f3dac  nop       
c03f3db0  addiu     $t0, $t1, -4
c03f3db4  bnez      $t0, 0xc03f4534
c03f3db8  nop       
c03f3dbc  lw        $t1, 0x58($fp)
c03f3dc0  sw        $t1, 0x10($sp)
c03f3dc4  lw        $a3, 0x54($fp)
c03f3dc8  lw        $a2, 0x50($fp)
c03f3dcc  addiu     $a1, $zero, 1
c03f3dd0  move      $a0, $s1
c03f3dd4  jal       0xc03f8ef8
c03f3dd8  nop       
c03f3ddc  b         0xc03f4108
c03f3de0  nop       
c03f3de4  addiu     $t1, $zero, 0x33
c03f3de8  sw        $t1, 0x14($sp)
c03f3dec  lw        $t1, 0x58($fp)
c03f3df0  sw        $t1, 0x10($sp)
c03f3df4  lw        $a3, 0x54($fp)
c03f3df8  lw        $a2, 0x50($fp)
c03f3dfc  addiu     $a1, $zero, 1
c03f3e00  move      $a0, $s1
c03f3e04  jal       0xc03f8c8c
c03f3e08  nop       
c03f3e0c  b         0xc03f4108
c03f3e10  nop       
c03f3e14  addiu     $a1, $zero, 1
c03f3e18  b         0xc03f40dc
c03f3e1c  nop       
c03f3e20  lw        $t1, 0x58($fp)
c03f3e24  sw        $t1, 0x10($sp)
c03f3e28  lw        $a3, 0x54($fp)
c03f3e2c  lw        $a2, 0x50($fp)
c03f3e30  addiu     $a1, $zero, 1
c03f3e34  move      $a0, $s1
c03f3e38  jal       0xc03fa2f0
c03f3e3c  nop       
c03f3e40  b         0xc03f4108
c03f3e44  nop       
c03f3e48  addiu     $a1, $zero, 3
c03f3e4c  b         0xc03f40dc
c03f3e50  nop       
c03f3e54  addiu     $a1, $zero, 1
c03f3e58  b         0xc03f4264
c03f3e5c  nop       
c03f3e60  lui       $t1, 0x25
c03f3e64  ori       $t1, $t1, 0x18
c03f3e68  subu      $t1, $s0, $t1
c03f3e6c  beqz      $t1, 0xc03f3f28
c03f3e70  nop       
c03f3e74  addiu     $t0, $t1, -4
c03f3e78  beqz      $t0, 0xc03f3f00
c03f3e7c  nop       
c03f3e80  addiu     $t1, $t0, -4
c03f3e84  beqz      $t1, 0xc03f3ed0
c03f3e88  nop       
c03f3e8c  addiu     $t0, $t1, -4
c03f3e90  bnez      $t0, 0xc03f4534
c03f3e94  nop       
c03f3e98  lw        $t1, 0x60($fp)
c03f3e9c  sw        $t1, 0x18($sp)
c03f3ea0  lw        $t2, 0x5c($fp)
c03f3ea4  sw        $t2, 0x14($sp)
c03f3ea8  lw        $t3, 0x58($fp)
c03f3eac  sw        $t3, 0x10($sp)
c03f3eb0  lw        $a3, 0x54($fp)
c03f3eb4  lw        $a2, 0x50($fp)
c03f3eb8  addiu     $a1, $zero, 1
c03f3ebc  move      $a0, $s1
c03f3ec0  jal       0xc03f9428
c03f3ec4  nop       
c03f3ec8  b         0xc03f4108
c03f3ecc  nop       
c03f3ed0  lw        $t1, 0x5c($fp)
c03f3ed4  sw        $t1, 0x14($sp)
c03f3ed8  lw        $t2, 0x58($fp)
c03f3edc  sw        $t2, 0x10($sp)
c03f3ee0  lw        $a3, 0x54($fp)
c03f3ee4  lw        $a2, 0x50($fp)
c03f3ee8  addiu     $a1, $zero, 1
c03f3eec  move      $a0, $s1
c03f3ef0  jal       0xc03f8a58
c03f3ef4  nop       
c03f3ef8  b         0xc03f4108
c03f3efc  nop       
c03f3f00  lw        $t1, 0x58($fp)
c03f3f04  sw        $t1, 0x10($sp)
c03f3f08  lw        $a3, 0x54($fp)
c03f3f0c  lw        $a2, 0x50($fp)
c03f3f10  addiu     $a1, $zero, 1
c03f3f14  move      $a0, $s1
c03f3f18  jal       0xc03f91c4
c03f3f1c  nop       
c03f3f20  b         0xc03f4108
c03f3f24  nop       
c03f3f28  jal       0xc03ffccc ; import thunk AUDEVMAN.dll!audmGetNumInputDevices
c03f3f2c  nop       
c03f3f30  b         0xc03f4108
c03f3f34  nop       
c03f3f38  lw        $t1, 0x58($fp)
c03f3f3c  sw        $t1, 0x10($sp)
c03f3f40  lw        $a3, 0x54($fp)
c03f3f44  lw        $a2, 0x50($fp)
c03f3f48  addiu     $a1, $zero, 1
c03f3f4c  move      $a0, $s1
c03f3f50  jal       0xc03f97f0
c03f3f54  nop       
c03f3f58  b         0xc03f4108
c03f3f5c  nop       
c03f3f60  ori       $t1, $t1, 0x3d
c03f3f64  sltu      $t1, $s0, $t1
c03f3f68  beqz      $t1, 0xc03f406c
c03f3f6c  nop       
c03f3f70  lui       $t0, 0x25
c03f3f74  ori       $t0, $t0, 0x3c
c03f3f78  beq       $s0, $t0, 0xc03f401c
c03f3f7c  nop       
c03f3f80  lui       $t2, 0x25
c03f3f84  ori       $t2, $t2, 0x2c
c03f3f88  subu      $t0, $s0, $t2
c03f3f8c  beqz      $t0, 0xc03f4010
c03f3f90  nop       
c03f3f94  addiu     $t0, $t0, -4
c03f3f98  beqz      $t0, 0xc03f3ff8
c03f3f9c  nop       
c03f3fa0  addiu     $t1, $t0, -4
c03f3fa4  beqz      $t1, 0xc03f3fe0
c03f3fa8  nop       
c03f3fac  addiu     $t0, $t1, -4
c03f3fb0  bnez      $t0, 0xc03f4534
c03f3fb4  nop       
c03f3fb8  lw        $t1, 0x58($fp)
c03f3fbc  sw        $t1, 0x10($sp)
c03f3fc0  lw        $a3, 0x54($fp)
c03f3fc4  lw        $a2, 0x50($fp)
c03f3fc8  addiu     $a1, $zero, 1
c03f3fcc  move      $a0, $s1
c03f3fd0  jal       0xc03fa128
c03f3fd4  nop       
c03f3fd8  b         0xc03f4108
c03f3fdc  nop       
c03f3fe0  lw        $a1, 0x50($fp)
c03f3fe4  move      $a0, $s1
c03f3fe8  jal       0xc03fbaa4
c03f3fec  nop       
c03f3ff0  b         0xc03f4108
c03f3ff4  nop       
c03f3ff8  lw        $a1, 0x50($fp)
c03f3ffc  move      $a0, $s1
c03f4000  jal       0xc03fba30
c03f4004  nop       
c03f4008  b         0xc03f4108
c03f400c  nop       
c03f4010  addiu     $a1, $zero, 1
c03f4014  b         0xc03f43b8
c03f4018  nop       
c03f401c  sw        $zero, 0x28($sp)
c03f4020  sw        $zero, 0x24($sp)
c03f4024  lw        $t1, 0x68($fp)
c03f4028  sw        $t1, 0x20($sp)
c03f402c  lw        $t0, 0x64($fp)
c03f4030  sw        $t0, 0x1c($sp)
c03f4034  lw        $t2, 0x60($fp)
c03f4038  sw        $t2, 0x18($sp)
c03f403c  lw        $t3, 0x5c($fp)
c03f4040  sw        $t3, 0x14($sp)
c03f4044  lw        $t4, 0x58($fp)
c03f4048  sw        $t4, 0x10($sp)
c03f404c  lw        $a3, 0x54($fp)
c03f4050  lw        $a2, 0x50($fp)
c03f4054  addiu     $a1, $zero, 1
c03f4058  move      $a0, $s1
c03f405c  jal       0xc03f9ca8
c03f4060  nop       
c03f4064  b         0xc03f4108
c03f4068  nop       
c03f406c  lui       $t1, 0x25
c03f4070  ori       $t1, $t1, 0x40
c03f4074  subu      $t1, $s0, $t1
c03f4078  beqz      $t1, 0xc03f4118
c03f407c  nop       
c03f4080  ori       $t0, $zero, 0xffc4
c03f4084  subu      $t0, $t1, $t0
c03f4088  beqz      $t0, 0xc03f40f8
c03f408c  nop       
c03f4090  addiu     $t0, $t0, -4
c03f4094  beqz      $t0, 0xc03f40d8
c03f4098  nop       
c03f409c  addiu     $t0, $t0, -4
c03f40a0  bnez      $t0, 0xc03f4534
c03f40a4  nop       
c03f40a8  addiu     $t1, $zero, 4
c03f40ac  sw        $t1, 0x14($sp)
c03f40b0  lw        $t1, 0x58($fp)
c03f40b4  sw        $t1, 0x10($sp)
c03f40b8  lw        $a3, 0x54($fp)
c03f40bc  lw        $a2, 0x50($fp)
c03f40c0  addiu     $a1, $zero, 2
c03f40c4  move      $a0, $s1
c03f40c8  jal       0xc03f8c8c
c03f40cc  nop       
c03f40d0  b         0xc03f4108
c03f40d4  nop       
c03f40d8  addiu     $a1, $zero, 2
c03f40dc  addiu     $a3, $zero, 1
c03f40e0  lw        $a2, 0x50($fp)
c03f40e4  move      $a0, $s1
c03f40e8  jal       0xc03f88d4
c03f40ec  nop       
c03f40f0  b         0xc03f4108
c03f40f4  nop       
c03f40f8  lw        $a1, 0x50($fp)
c03f40fc  move      $a0, $s1
c03f4100  jal       0xc03fac9c
c03f4104  nop       
c03f4108  lw        $t0, 0x98($fp)
c03f410c  sw        $v0, ($t0)
c03f4110  b         0xc03f453c
c03f4114  nop       
c03f4118  sw        $s2, 0x28($sp)
c03f411c  lw        $t1, 0x6c($fp)
c03f4120  sw        $t1, 0x24($sp)
c03f4124  lw        $t2, 0x68($fp)
c03f4128  sw        $t2, 0x20($sp)
c03f412c  lw        $t0, 0x64($fp)
c03f4130  sw        $t0, 0x1c($sp)
c03f4134  lw        $t3, 0x60($fp)
c03f4138  sw        $t3, 0x18($sp)
c03f413c  lw        $t4, 0x5c($fp)
c03f4140  sw        $t4, 0x14($sp)
c03f4144  lw        $t1, 0x58($fp)
c03f4148  sw        $t1, 0x10($sp)
c03f414c  lw        $a3, 0x54($fp)
c03f4150  lw        $a2, 0x50($fp)
c03f4154  addiu     $a1, $zero, 1
c03f4158  move      $a0, $s1
c03f415c  jal       0xc03f9ca8
c03f4160  nop       
c03f4164  b         0xc03f4108
c03f4168  nop       
c03f416c  lw        $t1, 0x58($fp)
c03f4170  sw        $t1, 0x10($sp)
c03f4174  lw        $a3, 0x54($fp)
c03f4178  lw        $a2, 0x50($fp)
c03f417c  addiu     $a1, $zero, 2
c03f4180  move      $a0, $s1
c03f4184  jal       0xc03f8ef8
c03f4188  nop       
c03f418c  b         0xc03f4108
c03f4190  nop       
c03f4194  lui       $t1, 0x26
c03f4198  ori       $t1, $t1, 0x14
c03f419c  subu      $t3, $s0, $t1
c03f41a0  sltiu     $t1, $t3, 0x49
c03f41a4  beqz      $t1, 0xc03f4534
c03f41a8  nop       
c03f41ac  lui       $t2, 0xc03f
c03f41b0  addiu     $t2, $t2, 0x41cc
c03f41b4  sll       $t0, $t3, 1
c03f41b8  addu      $t0, $t0, $t2
c03f41bc  lh        $t0, ($t0)
c03f41c0  addu      $t2, $t2, $t0
c03f41c4  jr        $t2
c03f41c8  nop       
c03f41cc  .byte     0x94, 0x00, 0x68, 0x03
c03f41d0  .byte     0x68, 0x03, 0x68, 0x03
c03f41d4  teq       $k1, $t0, 2
c03f41d8  .byte     0x68, 0x03, 0x68, 0x03
c03f41dc  .byte     0xc4, 0x00, 0x68, 0x03
c03f41e0  .byte     0x68, 0x03, 0x68, 0x03
c03f41e4  .byte     0xe0, 0x00, 0x68, 0x03
c03f41e8  .byte     0x68, 0x03, 0x68, 0x03
c03f41ec  .byte     0xfc, 0x00, 0x68, 0x03
c03f41f0  .byte     0x68, 0x03, 0x68, 0x03
c03f41f4  .byte     0x24, 0x01, 0x68, 0x03
c03f41f8  .byte     0x68, 0x03, 0x68, 0x03
c03f41fc  .byte     0x40, 0x01, 0x68, 0x03
c03f4200  .byte     0x68, 0x03, 0x68, 0x03
c03f4204  tge       $k1, $t0, 5
c03f4208  .byte     0x68, 0x03, 0x68, 0x03
c03f420c  .byte     0xa8, 0x01, 0x68, 0x03
c03f4210  .byte     0x68, 0x03, 0x68, 0x03
c03f4214  .byte     0xc0, 0x01, 0x68, 0x03
c03f4218  .byte     0x68, 0x03, 0x68, 0x03
c03f421c  .byte     0xe8, 0x01, 0x68, 0x03
c03f4220  .byte     0x68, 0x03, 0x68, 0x03
c03f4224  .byte     0x08, 0x02, 0x68, 0x03
c03f4228  .byte     0x68, 0x03, 0x68, 0x03
c03f422c  .byte     0x20, 0x02, 0x68, 0x03
c03f4230  .byte     0x68, 0x03, 0x68, 0x03
c03f4234  .byte     0x3c, 0x02, 0x68, 0x03
c03f4238  .byte     0x68, 0x03, 0x68, 0x03
c03f423c  .byte     0x58, 0x02, 0x68, 0x03
c03f4240  .byte     0x68, 0x03, 0x68, 0x03
c03f4244  teq       $k1, $t0, 9
c03f4248  .byte     0x68, 0x03, 0x68, 0x03
c03f424c  .byte     0x9c, 0x02, 0x68, 0x03
c03f4250  .byte     0x68, 0x03, 0x68, 0x03
c03f4254  .byte     0xc4, 0x02, 0x68, 0x03
c03f4258  .byte     0x68, 0x03, 0x68, 0x03
c03f425c  .byte     0x14, 0x03, 0x00, 0x00
c03f4260  addiu     $a1, $zero, 2
c03f4264  lw        $a2, 0x50($fp)
c03f4268  lw        $a3, 0x54($fp)
c03f426c  move      $a0, $s1
c03f4270  jal       0xc03f9064
c03f4274  nop       
c03f4278  b         0xc03f4108
c03f427c  nop       
c03f4280  jal       0xc03ffcbc ; import thunk AUDEVMAN.dll!audmGetNumOutputDevices
c03f4284  nop       
c03f4288  b         0xc03f4108
c03f428c  nop       
c03f4290  lw        $a2, 0x54($fp)
c03f4294  lw        $a1, 0x50($fp)
c03f4298  move      $a0, $s1
c03f429c  jal       0xc03fb314
c03f42a0  nop       
c03f42a4  b         0xc03f4108
c03f42a8  nop       
c03f42ac  lw        $a2, 0x54($fp)
c03f42b0  lw        $a1, 0x50($fp)
c03f42b4  move      $a0, $s1
c03f42b8  jal       0xc03fb460
c03f42bc  nop       
c03f42c0  b         0xc03f4108
c03f42c4  nop       
c03f42c8  lw        $t1, 0x58($fp)
c03f42cc  sw        $t1, 0x10($sp)
c03f42d0  lw        $a3, 0x54($fp)
c03f42d4  lw        $a2, 0x50($fp)
c03f42d8  addiu     $a1, $zero, 2
c03f42dc  move      $a0, $s1
c03f42e0  jal       0xc03f91c4
c03f42e4  nop       
c03f42e8  b         0xc03f4108
c03f42ec  nop       
c03f42f0  lw        $a2, 0x54($fp)
c03f42f4  lw        $a1, 0x50($fp)
c03f42f8  move      $a0, $s1
c03f42fc  jal       0xc03fb5ac
c03f4300  nop       
c03f4304  b         0xc03f4108
c03f4308  nop       
c03f430c  lw        $t1, 0x5c($fp)
c03f4310  sw        $t1, 0x14($sp)
c03f4314  lw        $t2, 0x58($fp)
c03f4318  sw        $t2, 0x10($sp)
c03f431c  lw        $a3, 0x54($fp)
c03f4320  lw        $a2, 0x50($fp)
c03f4324  addiu     $a1, $zero, 2
c03f4328  move      $a0, $s1
c03f432c  jal       0xc03f8a58
c03f4330  nop       
c03f4334  b         0xc03f4108
c03f4338  nop       
c03f433c  lw        $t1, 0x60($fp)
c03f4340  sw        $t1, 0x18($sp)
c03f4344  lw        $t2, 0x5c($fp)
c03f4348  sw        $t2, 0x14($sp)
c03f434c  lw        $t0, 0x58($fp)
c03f4350  sw        $t0, 0x10($sp)
c03f4354  lw        $a3, 0x54($fp)
c03f4358  lw        $a2, 0x50($fp)
c03f435c  addiu     $a1, $zero, 2
c03f4360  move      $a0, $s1
c03f4364  jal       0xc03f9428
c03f4368  nop       
c03f436c  b         0xc03f4108
c03f4370  nop       
c03f4374  lw        $a1, 0x50($fp)
c03f4378  move      $a0, $s1
c03f437c  jal       0xc03fad10
c03f4380  nop       
c03f4384  b         0xc03f4108
c03f4388  nop       
c03f438c  lw        $t1, 0x58($fp)
c03f4390  sw        $t1, 0x10($sp)
c03f4394  lw        $a3, 0x54($fp)
c03f4398  lw        $a2, 0x50($fp)
c03f439c  addiu     $a1, $zero, 2
c03f43a0  move      $a0, $s1
c03f43a4  jal       0xc03f97f0
c03f43a8  nop       
c03f43ac  b         0xc03f4108
c03f43b0  nop       
c03f43b4  addiu     $a1, $zero, 2
c03f43b8  lw        $a2, 0x50($fp)
c03f43bc  addiu     $a3, $zero, 1
c03f43c0  move      $a0, $s1
c03f43c4  jal       0xc03f8c0c
c03f43c8  nop       
c03f43cc  b         0xc03f4108
c03f43d0  nop       
c03f43d4  lw        $a1, 0x50($fp)
c03f43d8  move      $a0, $s1
c03f43dc  jal       0xc03fad84
c03f43e0  nop       
c03f43e4  b         0xc03f4108
c03f43e8  nop       
c03f43ec  lw        $a2, 0x54($fp)
c03f43f0  lw        $a1, 0x50($fp)
c03f43f4  move      $a0, $s1
c03f43f8  jal       0xc03fadf8
c03f43fc  nop       
c03f4400  b         0xc03f4108
c03f4404  nop       
c03f4408  lw        $a2, 0x54($fp)
c03f440c  lw        $a1, 0x50($fp)
c03f4410  move      $a0, $s1
c03f4414  jal       0xc03fae70
c03f4418  nop       
c03f441c  b         0xc03f4108
c03f4420  nop       
c03f4424  lw        $a2, 0x54($fp)
c03f4428  lw        $a1, 0x50($fp)
c03f442c  move      $a0, $s1
c03f4430  jal       0xc03fb764
c03f4434  nop       
c03f4438  b         0xc03f4108
c03f443c  nop       
c03f4440  lw        $t1, 0x58($fp)
c03f4444  sw        $t1, 0x10($sp)
c03f4448  lw        $a3, 0x54($fp)
c03f444c  lw        $a2, 0x50($fp)
c03f4450  addiu     $a1, $zero, 2
c03f4454  move      $a0, $s1
c03f4458  jal       0xc03fa128
c03f445c  nop       
c03f4460  b         0xc03f4108
c03f4464  nop       
c03f4468  lw        $t1, 0x58($fp)
c03f446c  sw        $t1, 0x10($sp)
c03f4470  lw        $a3, 0x54($fp)
c03f4474  lw        $a2, 0x50($fp)
c03f4478  addiu     $a1, $zero, 2
c03f447c  move      $a0, $s1
c03f4480  jal       0xc03fa2f0
c03f4484  nop       
c03f4488  b         0xc03f4108
c03f448c  nop       
c03f4490  sw        $zero, 0x28($sp)
c03f4494  sw        $zero, 0x24($sp)
c03f4498  lw        $t1, 0x68($fp)
c03f449c  sw        $t1, 0x20($sp)
c03f44a0  lw        $t0, 0x64($fp)
c03f44a4  sw        $t0, 0x1c($sp)
c03f44a8  lw        $t2, 0x60($fp)
c03f44ac  sw        $t2, 0x18($sp)
c03f44b0  lw        $t3, 0x5c($fp)
c03f44b4  sw        $t3, 0x14($sp)
c03f44b8  lw        $t4, 0x58($fp)
c03f44bc  sw        $t4, 0x10($sp)
c03f44c0  lw        $a3, 0x54($fp)
c03f44c4  lw        $a2, 0x50($fp)
c03f44c8  addiu     $a1, $zero, 2
c03f44cc  move      $a0, $s1
c03f44d0  jal       0xc03f9ca8
c03f44d4  nop       
c03f44d8  b         0xc03f4108
c03f44dc  nop       
c03f44e0  sw        $s2, 0x28($sp)
c03f44e4  lw        $t1, 0x6c($fp)
c03f44e8  sw        $t1, 0x24($sp)
c03f44ec  lw        $t2, 0x68($fp)
c03f44f0  sw        $t2, 0x20($sp)
c03f44f4  lw        $t0, 0x64($fp)
c03f44f8  sw        $t0, 0x1c($sp)
c03f44fc  lw        $t3, 0x60($fp)
c03f4500  sw        $t3, 0x18($sp)
c03f4504  lw        $t4, 0x5c($fp)
c03f4508  sw        $t4, 0x14($sp)
c03f450c  lw        $t1, 0x58($fp)
c03f4510  sw        $t1, 0x10($sp)
c03f4514  lw        $a3, 0x54($fp)
c03f4518  lw        $a2, 0x50($fp)
c03f451c  addiu     $a1, $zero, 2
c03f4520  move      $a0, $s1
c03f4524  jal       0xc03f9ca8
c03f4528  nop       
c03f452c  b         0xc03f4108
c03f4530  nop       
c03f4534  move      $s2, $zero
c03f4538  sw        $s2, 0x30($fp)
c03f453c  b         0xc03f456c
c03f4540  nop       
c03f4544  move      $s2, $zero
c03f4548  sw        $s2, 0x30($fp)
c03f454c  addiu     $a0, $zero, 0x57
c03f4550  lui       $t0, 0xc040
c03f4554  lw        $t0, 0x103c($t0) ; IAT COREDLL.dll!SetLastError@517
c03f4558  jalr      $t0 ; call candidate COREDLL.dll!SetLastError@517
c03f455c  nop       
c03f4560  b         0xc03f456c
c03f4564  nop       
c03f4568  lw        $s2, 0x34($fp)
c03f456c  move      $v0, $s2
c03f4570  move      $sp, $fp
c03f4574  lw        $fp, 0x70($sp)
c03f4578  lw        $s2, 0x74($sp)
c03f457c  lw        $s1, 0x78($sp)
c03f4580  lw        $s0, 0x7c($sp)
c03f4584  lw        $ra, 0x80($sp)
c03f4588  addiu     $sp, $sp, 0x88
c03f458c  jr        $ra
c03f4590  nop       
c03f8000  addiu     $sp, $sp, -0x28
c03f8004  sw        $ra, 0x24($sp)
c03f8008  sw        $s4, 0x10($sp)
c03f800c  sw        $s3, 0x14($sp)
c03f8010  sw        $s2, 0x18($sp)
c03f8014  sw        $s1, 0x1c($sp)
c03f8018  sw        $s0, 0x20($sp)
c03f801c  move      $s3, $a0
c03f8020  addiu     $s4, $s3, 0x1c
c03f8024  move      $a0, $s4
c03f8028  move      $s0, $a3
c03f802c  move      $s1, $a2
c03f8030  jal       0xc03ffb3c ; import thunk COREDLL.dll!EnterCriticalSection@4
c03f8034  move      $s2, $a1
c03f8038  move      $a3, $s0
c03f803c  move      $a2, $s1
c03f8040  move      $a1, $s2
c03f8044  jal       0xc03f7e34
c03f8048  move      $a0, $s3
c03f804c  beqz      $v0, 0xc03f805c
c03f8050  nop       
c03f8054  b         0xc03f8060
c03f8058  lw        $s0, ($v0)
c03f805c  move      $s0, $zero
c03f8060  beqz      $s0, 0xc03f8088
c03f8064  nop       
c03f8068  lw        $t0, 0x38($sp)
c03f806c  beqz      $t0, 0xc03f8088
c03f8070  nop       
c03f8074  lwl       $t1, 3($s0)
c03f8078  lwr       $t1, ($s0)
c03f807c  lw        $t1, 4($t1)
c03f8080  jalr      $t1
c03f8084  move      $a0, $s0
c03f8088  jal       0xc03ffb0c ; import thunk COREDLL.dll!LeaveCriticalSection@5
c03f808c  move      $a0, $s4
c03f8090  move      $v0, $s0
c03f8094  lw        $s4, 0x10($sp)
c03f8098  lw        $s3, 0x14($sp)
c03f809c  lw        $s2, 0x18($sp)
c03f80a0  lw        $s1, 0x1c($sp)
c03f80a4  lw        $s0, 0x20($sp)
c03f80a8  lw        $ra, 0x24($sp)
c03f80ac  jr        $ra
c03f80b0  addiu     $sp, $sp, 0x28
c03f81cc  addiu     $sp, $sp, -0x18
c03f81d0  sw        $ra, 0x14($sp)
c03f81d4  sw        $s0, 0x10($sp)
c03f81d8  lui       $t0, 0xc03f
c03f81dc  move      $s0, $a0
c03f81e0  addiu     $t0, $t0, 0x27cc
c03f81e4  sw        $t0, ($s0)
c03f81e8  lw        $t0, 8($s0)
c03f81ec  beqz      $t0, 0xc03f8230
c03f81f0  nop       
c03f81f4  lw        $t1, 4($s0)
c03f81f8  jal       0xc03ffb3c ; import thunk COREDLL.dll!EnterCriticalSection@4
c03f81fc  addiu     $a0, $t1, 0x1c
c03f8200  lw        $a1, 8($s0)
c03f8204  lw        $t1, 4($a1)
c03f8208  lw        $t0, ($a1)
c03f820c  sw        $t0, ($t1)
c03f8210  lw        $t2, ($a1)
c03f8214  lw        $t1, 4($a1)
c03f8218  sw        $t1, 4($t2)
c03f821c  lw        $t2, 4($s0)
c03f8220  jal       0xc03ffb0c ; import thunk COREDLL.dll!LeaveCriticalSection@5
c03f8224  addiu     $a0, $t2, 0x1c
c03f8228  jal       0xc0400544 ; import thunk COREDLL.dll!??3@YAXPAX@Z@1094
c03f822c  lw        $a0, 8($s0)
c03f8230  lw        $s0, 0x10($sp)
c03f8234  lw        $ra, 0x14($sp)
c03f8238  jr        $ra
c03f823c  addiu     $sp, $sp, 0x18
c03f8450  addiu     $sp, $sp, -0x18
c03f8454  sw        $ra, 0x14($sp)
c03f8458  sw        $s0, 0x10($sp)
c03f845c  lui       $t0, 0xc03f
c03f8460  move      $s0, $a0
c03f8464  addiu     $t0, $t0, 0x27cc
c03f8468  addiu     $a0, $zero, 0xc
c03f846c  sw        $t0, ($s0)
c03f8470  jal       0xc0400534 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c03f8474  sw        $a1, 4($s0)
c03f8478  beqz      $v0, 0xc03f84cc
c03f847c  sw        $v0, 8($s0)
c03f8480  lw        $t0, 4($s0)
c03f8484  jal       0xc03ffb3c ; import thunk COREDLL.dll!EnterCriticalSection@4
c03f8488  addiu     $a0, $t0, 0x1c
c03f848c  jal       0xc03f8240
c03f8490  move      $a0, $s0
c03f8494  lw        $a0, 4($s0)
c03f8498  lw        $t0, 8($s0)
c03f849c  addiu     $t4, $a0, 0x14
c03f84a0  lw        $t3, 4($t4)
c03f84a4  sw        $t4, ($t0)
c03f84a8  lw        $t1, 8($s0)
c03f84ac  sw        $t3, 4($t1)
c03f84b0  lw        $t2, 8($s0)
c03f84b4  sw        $t2, ($t3)
c03f84b8  lw        $t3, 8($s0)
c03f84bc  sw        $t3, 4($t4)
c03f84c0  lw        $t4, 4($s0)
c03f84c4  jal       0xc03ffb0c ; import thunk COREDLL.dll!LeaveCriticalSection@5
c03f84c8  addiu     $a0, $t4, 0x1c
c03f84cc  move      $v0, $s0
c03f84d0  lw        $s0, 0x10($sp)
c03f84d4  lw        $ra, 0x14($sp)
c03f84d8  jr        $ra
c03f84dc  addiu     $sp, $sp, 0x18
c03f852c  addiu     $sp, $sp, -0x28
c03f8530  sw        $ra, 0x20($sp)
c03f8534  sw        $s1, 0x18($sp)
c03f8538  sw        $s0, 0x1c($sp)
c03f853c  move      $s1, $a3
c03f8540  beqz      $a1, 0xc03f8560
c03f8544  move      $s0, $a2
c03f8548  lui       $t0, 0xc040
c03f854c  move      $a2, $a0
c03f8550  addiu     $a3, $zero, 5
c03f8554  addiu     $a0, $t0, 0x136c
c03f8558  jal       0xc03f80b4
c03f855c  sw        $zero, 0x10($sp)
c03f8560  beqz      $s0, 0xc03f85a8
c03f8564  nop       
c03f8568  lw        $a0, ($s0)
c03f856c  beqz      $a0, 0xc03f85a0
c03f8570  nop       
c03f8574  addiu     $t0, $zero, 2
c03f8578  bne       $s1, $t0, 0xc03f8588
c03f857c  nop       
c03f8580  b         0xc03f858c
c03f8584  addiu     $t0, $zero, 4
c03f8588  addiu     $t0, $zero, 8
c03f858c  lui       $t1, 0x8000
c03f8590  lw        $a2, 0x2c($s0)
c03f8594  lw        $a1, 0x28($s0)
c03f8598  jal       0xc03ff8fc ; import thunk COREDLL.dll!CeFreeAsynchronousBuffer@2572
c03f859c  or        $a3, $t0, $t1
c03f85a0  jal       0xc0400544 ; import thunk COREDLL.dll!??3@YAXPAX@Z@1094
c03f85a4  move      $a0, $s0
c03f85a8  lw        $s1, 0x18($sp)
c03f85ac  lw        $s0, 0x1c($sp)
c03f85b0  lw        $ra, 0x20($sp)
c03f85b4  jr        $ra
c03f85b8  addiu     $sp, $sp, 0x28
c03f85bc  addiu     $sp, $sp, -0x30
c03f85c0  sw        $ra, 0x2c($sp)
c03f85c4  sw        $s4, 0x18($sp)
c03f85c8  sw        $s3, 0x1c($sp)
c03f85cc  sw        $s2, 0x20($sp)
c03f85d0  sw        $s1, 0x24($sp)
c03f85d4  sw        $s0, 0x28($sp)
c03f85d8  move      $s1, $a1
c03f85dc  lw        $t2, 0x10($s1)
c03f85e0  move      $s2, $a3
c03f85e4  andi      $t0, $t2, 0x10
c03f85e8  beqz      $t0, 0xc03f860c
c03f85ec  move      $s3, $a0
c03f85f0  lw        $t1, 0x44($sp)
c03f85f4  beqz      $t1, 0xc03f8624
c03f85f8  nop       
c03f85fc  lui       $t3, 0xffff
c03f8600  ori       $t3, $t3, 0xffef
c03f8604  and       $t2, $t2, $t3
c03f8608  sw        $t2, 0x10($s1)
c03f860c  lw        $t0, 0x10($s1)
c03f8610  andi      $t1, $t0, 2
c03f8614  bnez      $t1, 0xc03f862c
c03f8618  nop       
c03f861c  b         0xc03f8698
c03f8620  addiu     $s0, $zero, 0xb
c03f8624  b         0xc03f8698
c03f8628  addiu     $s0, $zero, 0x21
c03f862c  addiu     $s4, $zero, 8
c03f8630  addiu     $t0, $zero, 2
c03f8634  beq       $s2, $t0, 0xc03f8640
c03f8638  move      $a1, $s4
c03f863c  addiu     $a1, $zero, 0x37
c03f8640  lw        $a0, 0x34($a2)
c03f8644  addiu     $t1, $zero, 0x20
c03f8648  lw        $t0, ($a0)
c03f864c  lw        $a2, 0x2c($a2)
c03f8650  lw        $t0, 4($t0)
c03f8654  move      $a3, $s1
c03f8658  jalr      $t0
c03f865c  sw        $t1, 0x10($sp)
c03f8660  move      $s0, $v0
c03f8664  bne       $s0, $s4, 0xc03f8670
c03f8668  nop       
c03f866c  move      $s0, $zero
c03f8670  lui       $t1, 0xffff
c03f8674  lw        $t0, 0x10($s1)
c03f8678  ori       $t1, $t1, 0xfffd
c03f867c  and       $t0, $t0, $t1
c03f8680  lw        $a0, 0x40($sp)
c03f8684  move      $a3, $s2
c03f8688  move      $a2, $s1
c03f868c  move      $a1, $s3
c03f8690  jal       0xc03f852c
c03f8694  sw        $t0, 0x10($s1)
c03f8698  move      $v0, $s0
c03f869c  lw        $s4, 0x18($sp)
c03f86a0  lw        $s3, 0x1c($sp)
c03f86a4  lw        $s2, 0x20($sp)
c03f86a8  lw        $s1, 0x24($sp)
c03f86ac  lw        $s0, 0x28($sp)
c03f86b0  lw        $ra, 0x2c($sp)
c03f86b4  jr        $ra
c03f86b8  addiu     $sp, $sp, 0x30
c03f86bc  addiu     $sp, $sp, -0x58
c03f86c0  sw        $ra, 0x54($sp)
c03f86c4  sw        $s4, 0x40($sp)
c03f86c8  sw        $s3, 0x44($sp)
c03f86cc  sw        $s2, 0x48($sp)
c03f86d0  sw        $s1, 0x4c($sp)
c03f86d4  sw        $s0, 0x50($sp)
c03f86d8  lui       $t0, 0xc040
c03f86dc  move      $s4, $a1
c03f86e0  move      $s1, $a0
c03f86e4  addiu     $a1, $t0, 0x136c
c03f86e8  addiu     $a0, $sp, 0x30
c03f86ec  move      $s3, $a3
c03f86f0  jal       0xc03f8450
c03f86f4  move      $s0, $a2
c03f86f8  addiu     $a3, $sp, 0x20
c03f86fc  addiu     $a2, $zero, 5
c03f8700  move      $a1, $s0
c03f8704  addiu     $a0, $sp, 0x30
c03f8708  sw        $zero, 0x1c($sp)
c03f870c  sw        $zero, 0x18($sp)
c03f8710  sw        $zero, 0x14($sp)
c03f8714  sw        $zero, 0x10($sp)
c03f8718  jal       0xc03f82a0
c03f871c  move      $s2, $zero
c03f8720  beqz      $v0, 0xc03f8780
c03f8724  nop       
c03f8728  lw        $t5, 0x20($sp)
c03f872c  lw        $t0, 0x20($t5)
c03f8730  bne       $t0, $s1, 0xc03f8754
c03f8734  nop       
c03f8738  lw        $t1, 0x10($t5)
c03f873c  andi      $t2, $t1, 0x10
c03f8740  bnez      $t2, 0xc03f883c
c03f8744  nop       
c03f8748  move      $t3, $t1
c03f874c  ori       $t4, $t3, 0x10
c03f8750  sw        $t4, 0x10($t5)
c03f8754  addiu     $a3, $sp, 0x20
c03f8758  addiu     $a2, $zero, 5
c03f875c  move      $a1, $s0
c03f8760  addiu     $a0, $sp, 0x30
c03f8764  sw        $zero, 0x1c($sp)
c03f8768  sw        $zero, 0x18($sp)
c03f876c  sw        $zero, 0x14($sp)
c03f8770  jal       0xc03f82a0
c03f8774  sw        $zero, 0x10($sp)
c03f8778  bnez      $v0, 0xc03f8728
c03f877c  nop       
c03f8780  jal       0xc03f8240
c03f8784  addiu     $a0, $sp, 0x30
c03f8788  addiu     $t0, $sp, 0x28
c03f878c  addiu     $a3, $sp, 0x20
c03f8790  addiu     $a2, $zero, 5
c03f8794  move      $a1, $s0
c03f8798  addiu     $a0, $sp, 0x30
c03f879c  sw        $zero, 0x1c($sp)
c03f87a0  sw        $zero, 0x18($sp)
c03f87a4  sw        $zero, 0x14($sp)
c03f87a8  jal       0xc03f82a0
c03f87ac  sw        $t0, 0x10($sp)
c03f87b0  beqz      $v0, 0xc03f8810
c03f87b4  addiu     $s2, $zero, 1
c03f87b8  lw        $a1, 0x20($sp)
c03f87bc  lw        $t0, 0x20($a1)
c03f87c0  bne       $t0, $s1, 0xc03f87e0
c03f87c4  nop       
c03f87c8  lw        $a0, 0x28($sp)
c03f87cc  move      $a3, $s3
c03f87d0  move      $a2, $s4
c03f87d4  sw        $s2, 0x14($sp)
c03f87d8  jal       0xc03f85bc
c03f87dc  sw        $s0, 0x10($sp)
c03f87e0  addiu     $t0, $sp, 0x28
c03f87e4  addiu     $a3, $sp, 0x20
c03f87e8  addiu     $a2, $zero, 5
c03f87ec  move      $a1, $s0
c03f87f0  addiu     $a0, $sp, 0x30
c03f87f4  sw        $zero, 0x1c($sp)
c03f87f8  sw        $zero, 0x18($sp)
c03f87fc  sw        $zero, 0x14($sp)
c03f8800  jal       0xc03f82a0
c03f8804  sw        $t0, 0x10($sp)
c03f8808  bnez      $v0, 0xc03f87b8
c03f880c  nop       
c03f8810  jal       0xc03f81cc
c03f8814  addiu     $a0, $sp, 0x30
c03f8818  move      $v0, $s2
c03f881c  lw        $s4, 0x40($sp)
c03f8820  lw        $s3, 0x44($sp)
c03f8824  lw        $s2, 0x48($sp)
c03f8828  lw        $s1, 0x4c($sp)
c03f882c  lw        $s0, 0x50($sp)
c03f8830  lw        $ra, 0x54($sp)
c03f8834  jr        $ra
c03f8838  addiu     $sp, $sp, 0x58
c03f883c  jal       0xc03f8240
c03f8840  addiu     $a0, $sp, 0x30
c03f8844  addiu     $a3, $sp, 0x24
c03f8848  addiu     $a2, $zero, 5
c03f884c  move      $a1, $s0
c03f8850  addiu     $a0, $sp, 0x30
c03f8854  sw        $zero, 0x1c($sp)
c03f8858  sw        $zero, 0x18($sp)
c03f885c  sw        $zero, 0x14($sp)
c03f8860  jal       0xc03f82a0
c03f8864  sw        $zero, 0x10($sp)
c03f8868  beqz      $v0, 0xc03f8810
c03f886c  nop       
c03f8870  lw        $t0, 0x20($sp)
c03f8874  lw        $t2, 0x24($sp)
c03f8878  beq       $t2, $t0, 0xc03f8810
c03f887c  nop       
c03f8880  lw        $t0, 0x20($t2)
c03f8884  bne       $t0, $s1, 0xc03f88a0
c03f8888  nop       
c03f888c  lui       $t3, 0xffff
c03f8890  lw        $t1, 0x10($t2)
c03f8894  ori       $t3, $t3, 0xffef
c03f8898  and       $t1, $t1, $t3
c03f889c  sw        $t1, 0x10($t2)
c03f88a0  addiu     $a3, $sp, 0x24
c03f88a4  addiu     $a2, $zero, 5
c03f88a8  move      $a1, $s0
c03f88ac  addiu     $a0, $sp, 0x30
c03f88b0  sw        $zero, 0x1c($sp)
c03f88b4  sw        $zero, 0x18($sp)
c03f88b8  sw        $zero, 0x14($sp)
c03f88bc  jal       0xc03f82a0
c03f88c0  sw        $zero, 0x10($sp)
c03f88c4  bnez      $v0, 0xc03f8870
c03f88c8  nop       
c03f88cc  b         0xc03f8810
c03f88d0  nop       
c03f88d4  addiu     $sp, $sp, -0x40
c03f88d8  sw        $ra, 0x38($sp)
c03f88dc  sw        $s5, 0x20($sp)
c03f88e0  sw        $s4, 0x24($sp)
c03f88e4  sw        $s3, 0x28($sp)
c03f88e8  sw        $s2, 0x2c($sp)
c03f88ec  sw        $s1, 0x30($sp)
c03f88f0  sw        $s0, 0x34($sp)
c03f88f4  move      $s2, $a2
c03f88f8  move      $s1, $a1
c03f88fc  move      $s3, $a0
c03f8900  move      $a2, $s2
c03f8904  move      $a1, $s1
c03f8908  jal       0xc03fa760
c03f890c  move      $a0, $s3
c03f8910  move      $s0, $v0
c03f8914  bnez      $s0, 0xc03f8924
c03f8918  nop       
c03f891c  b         0xc03f8a30
c03f8920  addiu     $s1, $zero, 5
c03f8924  addiu     $s4, $zero, 3
c03f8928  beq       $s1, $s4, 0xc03f8954
c03f892c  lui       $s5, 0xc040
c03f8930  move      $a3, $s1
c03f8934  move      $a2, $s3
c03f8938  move      $a1, $s0
c03f893c  jal       0xc03f86bc
c03f8940  move      $a0, $s2
c03f8944  bnez      $v0, 0xc03f8954
c03f8948  nop       
c03f894c  b         0xc03f8a18
c03f8950  addiu     $s1, $zero, 0x21
c03f8954  addiu     $t4, $zero, 1
c03f8958  beq       $s1, $t4, 0xc03f89cc
c03f895c  nop       
c03f8960  addiu     $t0, $zero, 2
c03f8964  beq       $s1, $t0, 0xc03f89a4
c03f8968  nop       
c03f896c  bne       $s1, $s4, 0xc03f899c
c03f8970  nop       
c03f8974  lw        $a0, 0x34($s0)
c03f8978  addiu     $a3, $zero, 0
c03f897c  lw        $t0, ($a0)
c03f8980  lw        $a2, 0x2c($s0)
c03f8984  lw        $t0, 8($t0)
c03f8988  addiu     $a1, $zero, 4
c03f898c  jalr      $t0
c03f8990  sw        $zero, 0x10($sp)
c03f8994  b         0xc03f89f0
c03f8998  nop       
c03f899c  b         0xc03f89d0
c03f89a0  lw        $a1, 0x18($sp)
c03f89a4  lw        $t2, 0x44($s0)
c03f89a8  lbu       $t0, 1($t2)
c03f89ac  lbu       $t2, ($t2)
c03f89b0  sll       $t1, $t0, 8
c03f89b4  move      $t3, $t1
c03f89b8  or        $t3, $t2, $t3
c03f89bc  bne       $t3, $t4, 0xc03f89d0
c03f89c0  addiu     $a1, $zero, 6
c03f89c4  b         0xc03f89d4
c03f89c8  lui       $t4, 0x4000
c03f89cc  addiu     $a1, $zero, 0x35
c03f89d0  move      $t4, $zero
c03f89d4  lw        $a0, 0x34($s0)
c03f89d8  addiu     $a3, $zero, 0
c03f89dc  lw        $t0, ($a0)
c03f89e0  lw        $a2, 0x2c($s0)
c03f89e4  lw        $t0, 4($t0)
c03f89e8  jalr      $t0
c03f89ec  sw        $t4, 0x10($sp)
c03f89f0  move      $s1, $v0
c03f89f4  bnez      $s1, 0xc03f8a18
c03f89f8  nop       
c03f89fc  lw        $a0, 0x11f8($s5)
c03f8a00  jal       0xc03fb9c0
c03f8a04  move      $a1, $s0
c03f8a08  move      $a1, $s0
c03f8a0c  jal       0xc03fa7c0
c03f8a10  move      $a0, $s3
c03f8a14  move      $s0, $zero
c03f8a18  beqz      $s0, 0xc03f8a28
c03f8a1c  nop       
c03f8a20  jal       0xc03fa830
c03f8a24  move      $a0, $s0
c03f8a28  jal       0xc03fb204
c03f8a2c  lw        $a0, 0x11f8($s5)
c03f8a30  move      $v0, $s1
c03f8a34  lw        $s5, 0x20($sp)
c03f8a38  lw        $s4, 0x24($sp)
c03f8a3c  lw        $s3, 0x28($sp)
c03f8a40  lw        $s2, 0x2c($sp)
c03f8a44  lw        $s1, 0x30($sp)
c03f8a48  lw        $s0, 0x34($sp)
c03f8a4c  lw        $ra, 0x38($sp)
c03f8a50  jr        $ra
c03f8a54  addiu     $sp, $sp, 0x40
c03f8c0c  addiu     $sp, $sp, -0x28
c03f8c10  sw        $ra, 0x20($sp)
c03f8c14  sw        $s1, 0x18($sp)
c03f8c18  sw        $s0, 0x1c($sp)
c03f8c1c  addiu     $t0, $zero, 2
c03f8c20  beq       $a1, $t0, 0xc03f8c2c
c03f8c24  addiu     $s0, $zero, 0xc
c03f8c28  addiu     $s0, $zero, 0x3b
c03f8c2c  jal       0xc03fa760
c03f8c30  nop       
c03f8c34  move      $s1, $v0
c03f8c38  bnez      $s1, 0xc03f8c48
c03f8c3c  nop       
c03f8c40  b         0xc03f8c74
c03f8c44  addiu     $s0, $zero, 5
c03f8c48  lw        $a0, 0x34($s1)
c03f8c4c  addiu     $a3, $zero, 0
c03f8c50  lw        $t0, ($a0)
c03f8c54  lw        $a2, 0x2c($s1)
c03f8c58  lw        $t0, 4($t0)
c03f8c5c  move      $a1, $s0
c03f8c60  jalr      $t0
c03f8c64  sw        $zero, 0x10($sp)
c03f8c68  move      $a0, $s1
c03f8c6c  jal       0xc03fa830
c03f8c70  move      $s0, $v0
c03f8c74  move      $v0, $s0
c03f8c78  lw        $s1, 0x18($sp)
c03f8c7c  lw        $s0, 0x1c($sp)
c03f8c80  lw        $ra, 0x20($sp)
c03f8c84  jr        $ra
c03f8c88  addiu     $sp, $sp, 0x28
c03f9428  addiu     $sp, $sp, -0x88
c03f942c  sw        $ra, 0x80($sp)
c03f9430  sw        $s7, 0x60($sp)
c03f9434  sw        $s6, 0x64($sp)
c03f9438  sw        $s5, 0x68($sp)
c03f943c  sw        $s4, 0x6c($sp)
c03f9440  sw        $s3, 0x70($sp)
c03f9444  sw        $s2, 0x74($sp)
c03f9448  sw        $s1, 0x78($sp)
c03f944c  sw        $s0, 0x7c($sp)
c03f9450  move      $t0, $a2
c03f9454  sw        $t0, 0x24($sp)
c03f9458  move      $s3, $a3
c03f945c  move      $s6, $a1
c03f9460  move      $s7, $a0
c03f9464  addiu     $s2, $zero, 2
c03f9468  beq       $s6, $s2, 0xc03f9474
c03f946c  addiu     $s1, $zero, 5
c03f9470  addiu     $s1, $zero, 0x34
c03f9474  lui       $t1, 0xffff
c03f9478  lw        $t0, 0xa0($sp)
c03f947c  ori       $t1, $t1, 0xff7f
c03f9480  lui       $t2, 0xc03f
c03f9484  and       $s4, $t0, $t1
c03f9488  addiu     $t1, $t2, 0x10b0
c03f948c  swl       $t1, 0x3b($sp)
c03f9490  swr       $t1, 0x38($sp)
c03f9494  lui       $t1, 0xffff
c03f9498  swl       $s3, 0x43($sp)
c03f949c  swl       $zero, 0x3f($sp)
c03f94a0  move      $s0, $zero
c03f94a4  ori       $t1, $t1, 0xffff
c03f94a8  andi      $t0, $s4, 4
c03f94ac  sw        $s1, 0x20($sp)
c03f94b0  swr       $s3, 0x40($sp)
c03f94b4  beqz      $t0, 0xc03f94d0
c03f94b8  swr       $zero, 0x3c($sp)
c03f94bc  bne       $s3, $t1, 0xc03f94cc
c03f94c0  nop       
c03f94c4  b         0xc03f97c0
c03f94c8  addiu     $s2, $zero, 0xa
c03f94cc  move      $s3, $t1
c03f94d0  move      $a1, $s3
c03f94d4  jal       0xc03f45a0
c03f94d8  move      $a0, $s6
c03f94dc  beqz      $v0, 0xc03f97c0
c03f94e0  sw        $v0, 0x18($sp)
c03f94e4  jal       0xc03f4ce4
c03f94e8  lw        $a0, 0x98($sp)
c03f94ec  move      $s5, $v0
c03f94f0  bnez      $s5, 0xc03f9500
c03f94f4  nop       
c03f94f8  b         0xc03f97c0
c03f94fc  addiu     $s2, $zero, 0xb
c03f9500  andi      $t0, $s4, 1
c03f9504  beqz      $t0, 0xc03f9528
c03f9508  sw        $t0, 0x28($sp)
c03f950c  addiu     $t0, $sp, 0x2c
c03f9510  swl       $zero, 0x33($sp)
c03f9514  swl       $s5, 0x37($sp)
c03f9518  swr       $zero, 0x30($sp)
c03f951c  swr       $s5, 0x34($sp)
c03f9520  b         0xc03f95d8
c03f9524  sw        $t0, 0x1c($sp)
c03f9528  lw        $t1, 0x24($sp)
c03f952c  bnez      $t1, 0xc03f953c
c03f9530  nop       
c03f9534  b         0xc03f9798
c03f9538  addiu     $s1, $zero, 0xb
c03f953c  jal       0xc03f2988
c03f9540  move      $a0, $s7
c03f9544  beqz      $v0, 0xc03f94f8
c03f9548  nop       
c03f954c  lw        $t0, 0x9c($sp)
c03f9550  lw        $a1, 0x18($sp)
c03f9554  move      $a3, $v0
c03f9558  move      $a2, $s6
c03f955c  move      $a0, $s7
c03f9560  sw        $s4, 0x14($sp)
c03f9564  jal       0xc03fab64
c03f9568  sw        $t0, 0x10($sp)
c03f956c  move      $s0, $v0
c03f9570  bnez      $s0, 0xc03f9580
c03f9574  nop       
c03f9578  b         0xc03f9784
c03f957c  addiu     $s1, $zero, 7
c03f9580  lui       $t1, 0xfffb
c03f9584  addiu     $t0, $s0, 0x2c
c03f9588  ori       $t1, $t1, 0xffff
c03f958c  sw        $t0, 0x1c($sp)
c03f9590  lui       $t2, 3
c03f9594  sw        $s5, 0x44($s0)
c03f9598  and       $t0, $s4, $t1
c03f959c  swl       $s5, 0x37($sp)
c03f95a0  swl       $s0, 0x33($sp)
c03f95a4  or        $s4, $t0, $t2
c03f95a8  swr       $s5, 0x34($sp)
c03f95ac  swr       $s0, 0x30($sp)
c03f95b0  lbu       $t0, 1($s5)
c03f95b4  lbu       $t2, ($s5)
c03f95b8  sll       $t1, $t0, 8
c03f95bc  move      $t3, $t1
c03f95c0  or        $t3, $t2, $t3
c03f95c4  addiu     $t4, $zero, 1
c03f95c8  bne       $t3, $t4, 0xc03f95d8
c03f95cc  nop       
c03f95d0  lui       $t4, 0x4000
c03f95d4  or        $s4, $s4, $t4
c03f95d8  lw        $a0, 0x18($sp)
c03f95dc  addiu     $a3, $sp, 0x30
c03f95e0  lw        $t0, ($a0)
c03f95e4  lw        $a2, 0x1c($sp)
c03f95e8  lw        $t0, 4($t0)
c03f95ec  move      $a1, $s1
c03f95f0  jalr      $t0
c03f95f4  sw        $s4, 0x10($sp)
c03f95f8  move      $s1, $v0
c03f95fc  addiu     $t0, $zero, 1
c03f9600  bne       $s6, $t0, 0xc03f9654
c03f9604  addiu     $t1, $zero, 4
c03f9608  addiu     $t0, $zero, 0x21
c03f960c  beq       $s1, $t0, 0xc03f961c
c03f9610  nop       
c03f9614  bne       $s1, $t1, 0xc03f96a4
c03f9618  nop       
c03f961c  addiu     $a1, $zero, 0
c03f9620  jal       0xc03ffbbc ; import thunk COREDLL.dll!sndPlaySoundW@377
c03f9624  addiu     $a0, $zero, 0
c03f9628  lw        $a0, 0x18($sp)
c03f962c  addiu     $a3, $sp, 0x30
c03f9630  lw        $t0, ($a0)
c03f9634  lw        $t1, 0x1c($sp)
c03f9638  lw        $a1, 0x20($sp)
c03f963c  lw        $t0, 4($t0)
c03f9640  move      $a2, $t1
c03f9644  jalr      $t0
c03f9648  sw        $s4, 0x10($sp)
c03f964c  b         0xc03f96a0
c03f9650  nop       
c03f9654  beqz      $s1, 0xc03f96a4
c03f9658  nop       
c03f965c  lui       $t0, 0xffff
c03f9660  ori       $t0, $t0, 0xffff
c03f9664  beq       $s3, $t0, 0xc03f96a4
c03f9668  nop       
c03f966c  bnez      $s0, 0xc03f9678
c03f9670  addiu     $a0, $s0, 0x34
c03f9674  addiu     $a0, $sp, 0x18
c03f9678  lw        $t0, 0x1c($sp)
c03f967c  move      $a3, $s4
c03f9680  addiu     $a2, $sp, 0x30
c03f9684  jal       0xc03ff468
c03f9688  move      $a1, $t0
c03f968c  beqz      $v0, 0xc03f96a0
c03f9690  nop       
c03f9694  addiu     $t0, $zero, 0x20
c03f9698  bne       $v0, $t0, 0xc03f96a4
c03f969c  nop       
c03f96a0  move      $s1, $v0
c03f96a4  lw        $t0, 0x28($sp)
c03f96a8  beqz      $t0, 0xc03f96c0
c03f96ac  nop       
c03f96b0  jal       0xc03ff99c ; import thunk COREDLL.dll!LocalFree@36
c03f96b4  move      $a0, $s5
c03f96b8  b         0xc03f9798
c03f96bc  nop       
c03f96c0  bnez      $s1, 0xc03f9784
c03f96c4  nop       
c03f96c8  lw        $t0, 0x24($sp)
c03f96cc  addiu     $a3, $zero, 8
c03f96d0  addiu     $a2, $zero, 4
c03f96d4  move      $a1, $t0
c03f96d8  addiu     $a0, $sp, 0x48
c03f96dc  sw        $zero, 0x4c($sp)
c03f96e0  sw        $zero, 0x48($sp)
c03f96e4  sw        $zero, 0x54($sp)
c03f96e8  sw        $zero, 0x14($sp)
c03f96ec  jal       0xc03f48c0
c03f96f0  sw        $zero, 0x10($sp)
c03f96f4  lw        $a0, 0x48($sp)
c03f96f8  bnez      $a0, 0xc03f970c
c03f96fc  nop       
c03f9700  lw        $a0, 0x4c($sp)
c03f9704  beqz      $a0, 0xc03f9760
c03f9708  nop       
c03f970c  addiu     $a1, $s0, 0x1c
c03f9710  jal       0xc03ffafc ; import thunk COREDLL.dll!CeSafeCopyMemory@2508
c03f9714  addiu     $a2, $zero, 4
c03f9718  beqz      $v0, 0xc03f9760
c03f971c  nop       
c03f9720  jal       0xc03f28a8
c03f9724  addiu     $a0, $sp, 0x48
c03f9728  bltz      $v0, 0xc03f9760
c03f972c  nop       
c03f9730  jal       0xc03f28a8
c03f9734  addiu     $a0, $sp, 0x48
c03f9738  bne       $s6, $s2, 0xc03f9750
c03f973c  nop       
c03f9740  lui       $t0, 0xc040
c03f9744  lw        $a0, 0x11f8($t0)
c03f9748  jal       0xc03fb068
c03f974c  move      $a1, $s0
c03f9750  jal       0xc03fa830
c03f9754  move      $a0, $s0
c03f9758  b         0xc03f9798
c03f975c  nop       
c03f9760  lw        $a2, 0x1c($s0)
c03f9764  addiu     $a3, $zero, 0
c03f9768  move      $a1, $s6
c03f976c  jal       0xc03f88d4
c03f9770  move      $a0, $s7
c03f9774  addiu     $a0, $sp, 0x48
c03f9778  move      $s0, $zero
c03f977c  jal       0xc03f28a8
c03f9780  addiu     $s1, $zero, 0xb
c03f9784  beqz      $s0, 0xc03f9798
c03f9788  nop       
c03f978c  move      $a1, $s0
c03f9790  jal       0xc03fa7c0
c03f9794  move      $a0, $s7
c03f9798  lw        $t2, 0x18($sp)
c03f979c  lw        $t0, 4($t2)
c03f97a0  lw        $t1, 4($t0)
c03f97a4  addu      $t2, $t1, $t2
c03f97a8  addiu     $a0, $t2, 4
c03f97ac  lw        $t3, ($a0)
c03f97b0  lw        $t3, 8($t3)
c03f97b4  jalr      $t3
c03f97b8  nop       
c03f97bc  move      $s2, $s1
c03f97c0  move      $v0, $s2
c03f97c4  lw        $s7, 0x60($sp)
c03f97c8  lw        $s6, 0x64($sp)
c03f97cc  lw        $s5, 0x68($sp)
c03f97d0  lw        $s4, 0x6c($sp)
c03f97d4  lw        $s3, 0x70($sp)
c03f97d8  lw        $s2, 0x74($sp)
c03f97dc  lw        $s1, 0x78($sp)
c03f97e0  lw        $s0, 0x7c($sp)
c03f97e4  lw        $ra, 0x80($sp)
c03f97e8  jr        $ra
c03f97ec  addiu     $sp, $sp, 0x88
c03f97f0  addiu     $sp, $sp, -0x70
c03f97f4  sw        $ra, 0x6c($sp)
c03f97f8  sw        $fp, 0x48($sp)
c03f97fc  sw        $s7, 0x4c($sp)
c03f9800  sw        $s6, 0x50($sp)
c03f9804  sw        $s5, 0x54($sp)
c03f9808  sw        $s4, 0x58($sp)
c03f980c  sw        $s3, 0x5c($sp)
c03f9810  sw        $s2, 0x60($sp)
c03f9814  sw        $s1, 0x64($sp)
c03f9818  sw        $s0, 0x68($sp)
c03f981c  move      $fp, $sp
c03f9820  move      $s5, $a3
c03f9824  move      $s6, $a2
c03f9828  move      $s7, $a1
c03f982c  sw        $s7, 0x74($fp)
c03f9830  move      $s4, $a0
c03f9834  sw        $s4, 0x18($fp)
c03f9838  sw        $s4, 0x70($fp)
c03f983c  move      $s1, $zero
c03f9840  sw        $s1, 0x20($fp)
c03f9844  move      $s2, $zero
c03f9848  sw        $s2, 0x24($fp)
c03f984c  move      $a2, $s6
c03f9850  move      $a1, $s7
c03f9854  move      $a0, $s4
c03f9858  jal       0xc03fa760
c03f985c  nop       
c03f9860  move      $s3, $v0
c03f9864  sw        $s3, 0x28($fp)
c03f9868  bnez      $s3, 0xc03f987c
c03f986c  nop       
c03f9870  addiu     $s0, $zero, 5
c03f9874  b         0xc03f9c60
c03f9878  nop       
c03f987c  sw        $zero, 0x34($fp)
c03f9880  sw        $zero, 0x30($fp)
c03f9884  sw        $zero, 0x3c($fp)
c03f9888  sw        $zero, 0x14($sp)
c03f988c  sw        $zero, 0x10($sp)
c03f9890  addiu     $a3, $zero, 0xc
c03f9894  addiu     $a2, $zero, 0x20
c03f9898  move      $a1, $s5
c03f989c  addiu     $a0, $fp, 0x30
c03f98a0  jal       0xc03f48c0
c03f98a4  nop       
c03f98a8  lw        $s0, 0x30($fp)
c03f98ac  bnez      $s0, 0xc03f98b8
c03f98b0  nop       
c03f98b4  lw        $s0, 0x34($fp)
c03f98b8  beqz      $s0, 0xc03f98d0
c03f98bc  nop       
c03f98c0  lw        $t0, 0x80($fp)
c03f98c4  sltiu     $t1, $t0, 0x20
c03f98c8  beqz      $t1, 0xc03f98e0
c03f98cc  nop       
c03f98d0  addiu     $s0, $zero, 0xb
c03f98d4  sw        $s0, 0x1c($fp)
c03f98d8  b         0xc03f9c1c
c03f98dc  nop       
c03f98e0  addiu     $s4, $s0, 0x10
c03f98e4  lwl       $t1, 3($s4)
c03f98e8  lwr       $t1, ($s4)
c03f98ec  andi      $t0, $t1, 0x10
c03f98f0  beqz      $t0, 0xc03f990c
c03f98f4  nop       
c03f98f8  addiu     $s0, $zero, 0xb
c03f98fc  sw        $s0, 0x1c($fp)
c03f9900  lw        $s4, 0x18($fp)
c03f9904  b         0xc03f9c1c
c03f9908  nop       
c03f990c  andi      $t0, $t1, 2
c03f9910  beqz      $t0, 0xc03f992c
c03f9914  nop       
c03f9918  addiu     $s0, $zero, 0xb
c03f991c  sw        $s0, 0x1c($fp)
c03f9920  lw        $s4, 0x18($fp)
c03f9924  b         0xc03f9c1c
c03f9928  nop       
c03f992c  addiu     $a0, $zero, 0x30
c03f9930  jal       0xc0400534 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c03f9934  nop       
c03f9938  move      $s1, $v0
c03f993c  sw        $s1, 0x20($fp)
c03f9940  bnez      $s1, 0xc03f995c
c03f9944  nop       
c03f9948  addiu     $s0, $zero, 7
c03f994c  sw        $s0, 0x1c($fp)
c03f9950  lw        $s4, 0x18($fp)
c03f9954  b         0xc03f9c1c
c03f9958  nop       
c03f995c  sw        $s5, 0x24($s1)
c03f9960  sw        $s6, 0x20($s1)
c03f9964  sw        $zero, ($s1)
c03f9968  addiu     $t3, $s0, 4
c03f996c  lwl       $t0, 3($t3)
c03f9970  lwr       $t0, ($t3)
c03f9974  sw        $t0, 4($s1)
c03f9978  sw        $zero, 8($s1)
c03f997c  addiu     $t0, $s0, 0xc
c03f9980  lwl       $t1, 3($t0)
c03f9984  lwr       $t1, ($t0)
c03f9988  sw        $t1, 0xc($s1)
c03f998c  lwl       $t2, 3($s4)
c03f9990  lwr       $t2, ($s4)
c03f9994  sw        $t2, 0x10($s1)
c03f9998  addiu     $t2, $s0, 0x14
c03f999c  lwl       $t0, 3($t2)
c03f99a0  lwr       $t0, ($t2)
c03f99a4  sw        $t0, 0x14($s1)
c03f99a8  lwl       $t1, 3($s0)
c03f99ac  lwr       $t1, ($s0)
c03f99b0  sw        $t1, 0x28($s1)
c03f99b4  lwl       $t9, 3($t3)
c03f99b8  lwr       $t9, ($t3)
c03f99bc  sw        $t9, 0x2c($s1)
c03f99c0  lw        $t7, 0x44($s3)
c03f99c4  lbu       $t0, 0xd($t7)
c03f99c8  sll       $t1, $t0, 8
c03f99cc  move      $t3, $t1
c03f99d0  lbu       $t2, 0xc($t7)
c03f99d4  or        $t3, $t2, $t3
c03f99d8  not       $t4, $t3
c03f99dc  andi      $t8, $t4, 3
c03f99e0  lbu       $t5, 1($t7)
c03f99e4  sll       $t0, $t5, 8
c03f99e8  move      $t6, $t0
c03f99ec  lbu       $t1, ($t7)
c03f99f0  or        $t2, $t1, $t6
c03f99f4  addiu     $t3, $zero, 1
c03f99f8  addiu     $s5, $zero, 2
c03f99fc  bne       $t2, $t3, 0xc03f9a30
c03f9a00  nop       
c03f9a04  beq       $t8, $s5, 0xc03f9a30
c03f9a08  nop       
c03f9a0c  lw        $t0, 0x28($s1)
c03f9a10  and       $t1, $t0, $t8
c03f9a14  beqz      $t1, 0xc03f9a30
c03f9a18  nop       
c03f9a1c  addiu     $s0, $zero, 0xb
c03f9a20  sw        $s0, 0x1c($fp)
c03f9a24  lw        $s4, 0x18($fp)
c03f9a28  b         0xc03f9c1c
c03f9a2c  nop       
c03f9a30  lw        $t2, 0x44($s3)
c03f9a34  lbu       $t0, 0xd($t2)
c03f9a38  sll       $t1, $t0, 8
c03f9a3c  move      $t3, $t1
c03f9a40  lbu       $t2, 0xc($t2)
c03f9a44  or        $t3, $t2, $t3
c03f9a48  move      $t4, $t3
c03f9a4c  bnez      $t4, 0xc03f9a68
c03f9a50  nop       
c03f9a54  addiu     $s0, $zero, 0xb
c03f9a58  sw        $s0, 0x1c($fp)
c03f9a5c  lw        $s4, 0x18($fp)
c03f9a60  b         0xc03f9c1c
c03f9a64  nop       
c03f9a68  divu      $zero, $t9, $t4
c03f9a6c  bnez      $t4, 0xc03f9a78
c03f9a70  nop       
c03f9a74  break     7
c03f9a78  mfhi      $t0
c03f9a7c  beqz      $t0, 0xc03f9a98
c03f9a80  nop       
c03f9a84  addiu     $s0, $zero, 0xb
c03f9a88  sw        $s0, 0x1c($fp)
c03f9a8c  lw        $s4, 0x18($fp)
c03f9a90  b         0xc03f9c1c
c03f9a94  nop       
c03f9a98  lw        $t0, 0x10($s1)
c03f9a9c  andi      $t1, $t0, 0xc
c03f9aa0  addiu     $t3, $zero, 4
c03f9aa4  addiu     $s6, $zero, 8
c03f9aa8  beq       $t1, $t3, 0xc03f9ad0
c03f9aac  nop       
c03f9ab0  bne       $t1, $s6, 0xc03f9adc
c03f9ab4  nop       
c03f9ab8  lui       $t2, 0xffff
c03f9abc  ori       $t2, $t2, 0xfff7
c03f9ac0  and       $t0, $t0, $t2
c03f9ac4  sw        $t0, 0x10($s1)
c03f9ac8  b         0xc03f9adc
c03f9acc  nop       
c03f9ad0  lw        $t1, 0x10($s1)
c03f9ad4  ori       $t2, $t1, 8
c03f9ad8  sw        $t2, 0x10($s1)
c03f9adc  beq       $s7, $s5, 0xc03f9ae8
c03f9ae0  nop       
c03f9ae4  move      $t3, $s6
c03f9ae8  lui       $t0, 0x8000
c03f9aec  or        $a3, $t3, $t0
c03f9af0  lw        $a2, 0x2c($s1)
c03f9af4  lw        $a1, 0x28($s1)
c03f9af8  move      $a0, $s1
c03f9afc  jal       0xc03ff97c ; import thunk COREDLL.dll!CeAllocAsynchronousBuffer@2571
c03f9b00  nop       
c03f9b04  bgez      $v0, 0xc03f9b20
c03f9b08  nop       
c03f9b0c  addiu     $s0, $zero, 0xb
c03f9b10  sw        $s0, 0x1c($fp)
c03f9b14  lw        $s4, 0x18($fp)
c03f9b18  b         0xc03f9c1c
c03f9b1c  nop       
c03f9b20  sw        $zero, 0x10($sp)
c03f9b24  addiu     $a3, $zero, 5
c03f9b28  lw        $a2, 0x18($fp)
c03f9b2c  move      $a1, $s1
c03f9b30  lui       $t0, 0xc040
c03f9b34  addiu     $a0, $t0, 0x136c
c03f9b38  jal       0xc03f7eb8
c03f9b3c  nop       
c03f9b40  move      $s2, $v0
c03f9b44  sw        $s2, 0x24($fp)
c03f9b48  bnez      $s2, 0xc03f9b64
c03f9b4c  nop       
c03f9b50  addiu     $s0, $zero, 7
c03f9b54  sw        $s0, 0x1c($fp)
c03f9b58  lw        $s4, 0x18($fp)
c03f9b5c  b         0xc03f9c1c
c03f9b60  nop       
c03f9b64  swl       $s2, 0x1f($s0)
c03f9b68  swr       $s2, 0x1c($s0)
c03f9b6c  addiu     $a1, $zero, 7
c03f9b70  beq       $s7, $s5, 0xc03f9b7c
c03f9b74  nop       
c03f9b78  addiu     $a1, $zero, 0x36
c03f9b7c  lw        $a0, 0x34($s3)
c03f9b80  lw        $t0, ($a0)
c03f9b84  sw        $zero, 0x10($sp)
c03f9b88  move      $a3, $s1
c03f9b8c  lw        $a2, 0x2c($s3)
c03f9b90  lw        $t0, 4($t0)
c03f9b94  jalr      $t0
c03f9b98  nop       
c03f9b9c  move      $s0, $v0
c03f9ba0  sw        $s0, 0x1c($fp)
c03f9ba4  beq       $s0, $s6, 0xc03f9bc0
c03f9ba8  nop       
c03f9bac  beqz      $s0, 0xc03f9bc0
c03f9bb0  nop       
c03f9bb4  lw        $s4, 0x18($fp)
c03f9bb8  b         0xc03f9c1c
c03f9bbc  nop       
c03f9bc0  lw        $t0, 0x10($s1)
c03f9bc4  ori       $t1, $t0, 2
c03f9bc8  sw        $t1, 0x10($s1)
c03f9bcc  swl       $t1, 3($s4)
c03f9bd0  swr       $t1, ($s4)
c03f9bd4  move      $s0, $zero
c03f9bd8  sw        $s0, 0x1c($fp)
c03f9bdc  lw        $s4, 0x18($fp)
c03f9be0  b         0xc03f9c04
c03f9be4  nop       
c03f9be8  addiu     $s0, $zero, 0xb
c03f9bec  sw        $s0, 0x1c($fp)
c03f9bf0  lw        $s7, 0x74($fp)
c03f9bf4  lw        $s4, 0x70($fp)
c03f9bf8  lw        $s1, 0x20($fp)
c03f9bfc  lw        $s2, 0x24($fp)
c03f9c00  lw        $s3, 0x28($fp)
c03f9c04  addiu     $a0, $fp, 0x30
c03f9c08  jal       0xc03f28a8
c03f9c0c  nop       
c03f9c10  bgez      $v0, 0xc03f9c1c
c03f9c14  nop       
c03f9c18  addiu     $s0, $zero, 0xb
c03f9c1c  beqz      $s0, 0xc03f9c3c
c03f9c20  nop       
c03f9c24  move      $a3, $s7
c03f9c28  move      $a2, $s1
c03f9c2c  move      $a1, $s2
c03f9c30  move      $a0, $s4
c03f9c34  jal       0xc03f852c
c03f9c38  nop       
c03f9c3c  move      $a0, $s3
c03f9c40  jal       0xc03fa830
c03f9c44  nop       
c03f9c48  addiu     $a0, $fp, 0x30
c03f9c4c  jal       0xc03f28a8
c03f9c50  nop       
c03f9c54  b         0xc03f9c60
c03f9c58  nop       
c03f9c5c  lw        $s0, 0x28($fp)
c03f9c60  move      $v0, $s0
c03f9c64  move      $sp, $fp
c03f9c68  lw        $fp, 0x48($sp)
c03f9c6c  lw        $s7, 0x4c($sp)
c03f9c70  lw        $s6, 0x50($sp)
c03f9c74  lw        $s5, 0x54($sp)
c03f9c78  lw        $s4, 0x58($sp)
c03f9c7c  lw        $s3, 0x5c($sp)
c03f9c80  lw        $s2, 0x60($sp)
c03f9c84  lw        $s1, 0x64($sp)
c03f9c88  lw        $s0, 0x68($sp)
c03f9c8c  lw        $ra, 0x6c($sp)
c03f9c90  addiu     $sp, $sp, 0x70
c03f9c94  jr        $ra
c03f9c98  nop       
c03fa128  addiu     $sp, $sp, -0x58
c03fa12c  sw        $ra, 0x54($sp)
c03fa130  sw        $fp, 0x38($sp)
c03fa134  sw        $s5, 0x3c($sp)
c03fa138  sw        $s4, 0x40($sp)
c03fa13c  sw        $s3, 0x44($sp)
c03fa140  sw        $s2, 0x48($sp)
c03fa144  sw        $s1, 0x4c($sp)
c03fa148  sw        $s0, 0x50($sp)
c03fa14c  move      $fp, $sp
c03fa150  move      $s0, $a3
c03fa154  move      $s5, $a1
c03fa158  move      $s4, $a0
c03fa15c  move      $a1, $s5
c03fa160  move      $a0, $s4
c03fa164  jal       0xc03fa760
c03fa168  nop       
c03fa16c  move      $s2, $v0
c03fa170  sw        $s2, 0x1c($fp)
c03fa174  bnez      $s2, 0xc03fa188
c03fa178  nop       
c03fa17c  addiu     $s0, $zero, 5
c03fa180  b         0xc03fa2b0
c03fa184  nop       
c03fa188  sw        $zero, 0x24($fp)
c03fa18c  sw        $zero, 0x20($fp)
c03fa190  sw        $zero, 0x2c($fp)
c03fa194  sw        $zero, 0x14($sp)
c03fa198  sw        $zero, 0x10($sp)
c03fa19c  addiu     $a3, $zero, 0xc
c03fa1a0  addiu     $a2, $zero, 0x20
c03fa1a4  move      $a1, $s0
c03fa1a8  addiu     $a0, $fp, 0x20
c03fa1ac  jal       0xc03f48c0
c03fa1b0  nop       
c03fa1b4  lw        $s1, 0x20($fp)
c03fa1b8  bnez      $s1, 0xc03fa1c4
c03fa1bc  nop       
c03fa1c0  lw        $s1, 0x24($fp)
c03fa1c4  beqz      $s1, 0xc03fa1dc
c03fa1c8  nop       
c03fa1cc  lw        $t0, 0x68($fp)
c03fa1d0  sltiu     $t1, $t0, 0x20
c03fa1d4  beqz      $t1, 0xc03fa1ec
c03fa1d8  nop       
c03fa1dc  addiu     $s0, $zero, 0xb
c03fa1e0  sw        $s0, 0x18($fp)
c03fa1e4  b         0xc03fa28c
c03fa1e8  nop       
c03fa1ec  move      $a2, $s0
c03fa1f0  move      $a1, $s1
c03fa1f4  move      $a0, $s4
c03fa1f8  jal       0xc03f2aa4
c03fa1fc  nop       
c03fa200  bnez      $v0, 0xc03fa218
c03fa204  nop       
c03fa208  addiu     $s0, $zero, 0xb
c03fa20c  sw        $s0, 0x18($fp)
c03fa210  b         0xc03fa28c
c03fa214  nop       
c03fa218  addiu     $s3, $s1, 0x1c
c03fa21c  lwl       $a0, 3($s3)
c03fa220  lwr       $a0, ($s3)
c03fa224  sw        $zero, 0x14($sp)
c03fa228  sw        $s4, 0x10($sp)
c03fa22c  move      $a3, $s5
c03fa230  move      $a2, $s2
c03fa234  move      $a1, $v0
c03fa238  jal       0xc03f85bc
c03fa23c  nop       
c03fa240  move      $s0, $v0
c03fa244  sw        $s0, 0x18($fp)
c03fa248  bnez      $s0, 0xc03fa278
c03fa24c  nop       
c03fa250  addiu     $t1, $s1, 0x10
c03fa254  lwl       $t0, 3($t1)
c03fa258  lwr       $t0, ($t1)
c03fa25c  lui       $t2, 0xffff
c03fa260  ori       $t2, $t2, 0xfffd
c03fa264  and       $t0, $t0, $t2
c03fa268  swl       $t0, 3($t1)
c03fa26c  swr       $t0, ($t1)
c03fa270  swl       $zero, 3($s3)
c03fa274  swr       $zero, ($s3)
c03fa278  b         0xc03fa28c
c03fa27c  nop       
c03fa280  addiu     $s0, $zero, 0xb
c03fa284  sw        $s0, 0x18($fp)
c03fa288  lw        $s2, 0x1c($fp)
c03fa28c  move      $a0, $s2
c03fa290  jal       0xc03fa830
c03fa294  nop       
c03fa298  addiu     $a0, $fp, 0x20
c03fa29c  jal       0xc03f28a8
c03fa2a0  nop       
c03fa2a4  b         0xc03fa2b0
c03fa2a8  nop       
c03fa2ac  lw        $s0, 0x1c($fp)
c03fa2b0  move      $v0, $s0
c03fa2b4  move      $sp, $fp
c03fa2b8  lw        $fp, 0x38($sp)
c03fa2bc  lw        $s5, 0x3c($sp)
c03fa2c0  lw        $s4, 0x40($sp)
c03fa2c4  lw        $s3, 0x44($sp)
c03fa2c8  lw        $s2, 0x48($sp)
c03fa2cc  lw        $s1, 0x4c($sp)
c03fa2d0  lw        $s0, 0x50($sp)
c03fa2d4  lw        $ra, 0x54($sp)
c03fa2d8  addiu     $sp, $sp, 0x58
c03fa2dc  jr        $ra
c03fa2e0  nop       
c03fa2f0  addiu     $sp, $sp, -0x60
c03fa2f4  sw        $ra, 0x5c($sp)
c03fa2f8  sw        $fp, 0x38($sp)
c03fa2fc  sw        $s7, 0x3c($sp)
c03fa300  sw        $s6, 0x40($sp)
c03fa304  sw        $s5, 0x44($sp)
c03fa308  sw        $s4, 0x48($sp)
c03fa30c  sw        $s3, 0x4c($sp)
c03fa310  sw        $s2, 0x50($sp)
c03fa314  sw        $s1, 0x54($sp)
c03fa318  sw        $s0, 0x58($sp)
c03fa31c  move      $fp, $sp
c03fa320  move      $s5, $a3
c03fa324  move      $s7, $a2
c03fa328  move      $s3, $a1
c03fa32c  move      $s4, $a0
c03fa330  addiu     $t0, $zero, 2
c03fa334  addiu     $s6, $zero, 9
c03fa338  beq       $s3, $t0, 0xc03fa344
c03fa33c  nop       
c03fa340  addiu     $s6, $zero, 0x38
c03fa344  move      $a2, $s7
c03fa348  move      $a1, $s3
c03fa34c  move      $a0, $s4
c03fa350  jal       0xc03fa760
c03fa354  nop       
c03fa358  move      $s2, $v0
c03fa35c  sw        $s2, 0x1c($fp)
c03fa360  bnez      $s2, 0xc03fa374
c03fa364  nop       
c03fa368  addiu     $s0, $zero, 5
c03fa36c  b         0xc03fa5b4
c03fa370  nop       
c03fa374  sw        $zero, 0x24($fp)
c03fa378  sw        $zero, 0x20($fp)
c03fa37c  sw        $zero, 0x2c($fp)
c03fa380  sw        $zero, 0x14($sp)
c03fa384  sw        $zero, 0x10($sp)
c03fa388  addiu     $a3, $zero, 0xc
c03fa38c  addiu     $a2, $zero, 0x20
c03fa390  move      $a1, $s5
c03fa394  addiu     $a0, $fp, 0x20
c03fa398  jal       0xc03f48c0
c03fa39c  nop       
c03fa3a0  lw        $s0, 0x20($fp)
c03fa3a4  bnez      $s0, 0xc03fa3b0
c03fa3a8  nop       
c03fa3ac  lw        $s0, 0x24($fp)
c03fa3b0  beqz      $s0, 0xc03fa574
c03fa3b4  nop       
c03fa3b8  lw        $t0, 0x70($fp)
c03fa3bc  sltiu     $t1, $t0, 0x20
c03fa3c0  bnez      $t1, 0xc03fa574
c03fa3c4  nop       
c03fa3c8  addiu     $s1, $s0, 0x10
c03fa3cc  lwl       $t2, 3($s1)
c03fa3d0  lwr       $t2, ($s1)
c03fa3d4  andi      $t0, $t2, 2
c03fa3d8  bnez      $t0, 0xc03fa3ec
c03fa3dc  nop       
c03fa3e0  addiu     $s0, $zero, 0x22
c03fa3e4  b         0xc03fa578
c03fa3e8  nop       
c03fa3ec  andi      $t0, $t2, 0x10
c03fa3f0  beqz      $t0, 0xc03fa404
c03fa3f4  nop       
c03fa3f8  addiu     $s0, $zero, 0x21
c03fa3fc  b         0xc03fa578
c03fa400  nop       
c03fa404  ori       $t0, $t2, 0x10
c03fa408  swl       $t0, 3($s1)
c03fa40c  swr       $t0, ($s1)
c03fa410  move      $a2, $s5
c03fa414  move      $a1, $s0
c03fa418  move      $a0, $s4
c03fa41c  jal       0xc03f2aa4
c03fa420  nop       
c03fa424  move      $s4, $v0
c03fa428  bnez      $s4, 0xc03fa45c
c03fa42c  nop       
c03fa430  addiu     $s0, $zero, 0xb
c03fa434  sw        $s0, 0x18($fp)
c03fa438  lwl       $t0, 3($s1)
c03fa43c  lwr       $t0, ($s1)
c03fa440  lui       $t1, 0xffff
c03fa444  ori       $t1, $t1, 0xffef
c03fa448  and       $t0, $t0, $t1
c03fa44c  swl       $t0, 3($s1)
c03fa450  swr       $t0, ($s1)
c03fa454  b         0xc03fa57c
c03fa458  nop       
c03fa45c  sw        $s7, 0x20($s4)
c03fa460  addiu     $t1, $s0, 0x14
c03fa464  lwl       $t2, 3($t1)
c03fa468  lwr       $t2, ($t1)
c03fa46c  sw        $t2, 0x14($s4)
c03fa470  lw        $t3, 0x10($s4)
c03fa474  lwl       $t0, 3($s1)
c03fa478  lwr       $t0, ($s1)
c03fa47c  xor       $t0, $t3, $t0
c03fa480  andi      $t3, $t0, 0xc
c03fa484  lw        $t1, 0x10($s4)
c03fa488  xor       $t2, $t3, $t1
c03fa48c  sw        $t2, 0x10($s4)
c03fa490  lwl       $t4, 3($s1)
c03fa494  lwr       $t4, ($s1)
c03fa498  lui       $t5, 0xffff
c03fa49c  ori       $t5, $t5, 0xfffe
c03fa4a0  and       $t0, $t4, $t5
c03fa4a4  swl       $t0, 3($s1)
c03fa4a8  swr       $t0, ($s1)
c03fa4ac  lw        $t1, 0x10($s4)
c03fa4b0  and       $t2, $t1, $t5
c03fa4b4  sw        $t2, 0x10($s4)
c03fa4b8  addiu     $t3, $s0, 4
c03fa4bc  lwl       $t4, 3($t3)
c03fa4c0  lwr       $t4, ($t3)
c03fa4c4  sw        $t4, 4($s4)
c03fa4c8  move      $a1, $s3
c03fa4cc  lw        $a0, 0x34($s2)
c03fa4d0  jal       0xc03f1070
c03fa4d4  nop       
c03fa4d8  bnez      $v0, 0xc03fa514
c03fa4dc  nop       
c03fa4e0  addiu     $a0, $s2, 0x58
c03fa4e4  addiu     $a1, $zero, 1
c03fa4e8  jal       0xc03ffbcc ; import thunk COREDLL.dll!InterlockedExchangeAdd@1491
c03fa4ec  nop       
c03fa4f0  bnez      $v0, 0xc03fa514
c03fa4f4  nop       
c03fa4f8  lw        $t0, 0x60($s2)
c03fa4fc  beqz      $t0, 0xc03fa514
c03fa500  nop       
c03fa504  sw        $zero, 0x60($s2)
c03fa508  lw        $t1, 0x5c($s2)
c03fa50c  addiu     $t2, $t1, 1
c03fa510  sw        $t2, 0x5c($s2)
c03fa514  lw        $a0, 0x34($s2)
c03fa518  lw        $t0, ($a0)
c03fa51c  sw        $zero, 0x10($sp)
c03fa520  move      $a3, $s4
c03fa524  lw        $a2, 0x2c($s2)
c03fa528  move      $a1, $s6
c03fa52c  lw        $t0, 4($t0)
c03fa530  jalr      $t0
c03fa534  nop       
c03fa538  move      $s0, $v0
c03fa53c  sw        $s0, 0x18($fp)
c03fa540  beqz      $s0, 0xc03fa57c
c03fa544  nop       
c03fa548  move      $a1, $s3
c03fa54c  lw        $a0, 0x34($s2)
c03fa550  jal       0xc03f1070
c03fa554  nop       
c03fa558  bnez      $v0, 0xc03fa438
c03fa55c  nop       
c03fa560  addiu     $a0, $s2, 0x58
c03fa564  jal       0xc03ff92c ; import thunk COREDLL.dll!InterlockedDecrement@11
c03fa568  nop       
c03fa56c  b         0xc03fa438
c03fa570  nop       
c03fa574  addiu     $s0, $zero, 0xb
c03fa578  sw        $s0, 0x18($fp)
c03fa57c  b         0xc03fa590
c03fa580  nop       
c03fa584  addiu     $s0, $zero, 0xb
c03fa588  sw        $s0, 0x18($fp)
c03fa58c  lw        $s2, 0x1c($fp)
c03fa590  move      $a0, $s2
c03fa594  jal       0xc03fa830
c03fa598  nop       
c03fa59c  addiu     $a0, $fp, 0x20
c03fa5a0  jal       0xc03f28a8
c03fa5a4  nop       
c03fa5a8  b         0xc03fa5b4
c03fa5ac  nop       
c03fa5b0  lw        $s0, 0x1c($fp)
c03fa5b4  move      $v0, $s0
c03fa5b8  move      $sp, $fp
c03fa5bc  lw        $fp, 0x38($sp)
c03fa5c0  lw        $s7, 0x3c($sp)
c03fa5c4  lw        $s6, 0x40($sp)
c03fa5c8  lw        $s5, 0x44($sp)
c03fa5cc  lw        $s4, 0x48($sp)
c03fa5d0  lw        $s3, 0x4c($sp)
c03fa5d4  lw        $s2, 0x50($sp)
c03fa5d8  lw        $s1, 0x54($sp)
c03fa5dc  lw        $s0, 0x58($sp)
c03fa5e0  lw        $ra, 0x5c($sp)
c03fa5e4  addiu     $sp, $sp, 0x60
c03fa5e8  jr        $ra
c03fa5ec  nop       
c03fa760  addiu     $sp, $sp, -0x20
c03fa764  sw        $ra, 0x1c($sp)
c03fa768  sw        $s0, 0x18($sp)
c03fa76c  move      $t0, $a2
c03fa770  lui       $t2, 0xc040
c03fa774  andi      $a3, $a1, 0xff
c03fa778  addiu     $t1, $zero, 1
c03fa77c  move      $a2, $a0
c03fa780  move      $a1, $t0
c03fa784  addiu     $a0, $t2, 0x139c
c03fa788  jal       0xc03f8000
c03fa78c  sw        $t1, 0x10($sp)
c03fa790  move      $s0, $v0
c03fa794  beqz      $s0, 0xc03fa7ac
c03fa798  nop       
c03fa79c  lw        $t0, ($s0)
c03fa7a0  lw        $t0, 0x10($t0)
c03fa7a4  jalr      $t0
c03fa7a8  move      $a0, $s0
c03fa7ac  move      $v0, $s0
c03fa7b0  lw        $s0, 0x18($sp)
c03fa7b4  lw        $ra, 0x1c($sp)
c03fa7b8  jr        $ra
c03fa7bc  addiu     $sp, $sp, 0x20
; coredll.dll 1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c
40031960  addiu     $sp, $sp, -0x20
40031964  sw        $ra, 0x1c($sp)
40031968  sw        $fp, 0x18($sp)
4003196c  move      $fp, $sp
40031970  lui       $t5, 0x7fff
40031974  ori       $t5, $t5, 0xffff
40031978  and       $t0, $a2, $t5
4003197c  addiu     $t4, $t0, -4
40031980  sltiu     $t1, $t4, 0xb
40031984  beqz      $t1, 0x40031af0
40031988  nop       
4003198c  lui       $t3, 0x4003
40031990  addiu     $t3, $t3, 0x19ac
40031994  sll       $t2, $t4, 1
40031998  addu      $t2, $t2, $t3
4003199c  lh        $t2, ($t2)
400319a0  addu      $t3, $t3, $t2
400319a4  jr        $t3
400319a8  nop       
400319ac  .byte     0x48, 0x01, 0x3c, 0x00
400319b0  .byte     0xbc, 0x00, 0x44, 0x01
400319b4  .byte     0x48, 0x01, 0x18, 0x00
400319b8  tge       $t2, $a0
400319bc  .byte     0x48, 0x01, 0x18, 0x00
400319c0  tge       $zero, $zero
400319c4  addiu     $t0, $zero, 4
400319c8  bne       $a1, $t0, 0x40031af0
400319cc  nop       
400319d0  move      $a1, $t0
400319d4  b         0x40031af4
400319d8  nop       
400319dc  addiu     $t0, $zero, 8
400319e0  b         0x400319c8
400319e4  nop       
400319e8  bnez      $a1, 0x40031af4
400319ec  nop       
400319f0  beqz      $a3, 0x40031af0
400319f4  nop       
400319f8  lui       $t0, 1
400319fc  slt       $t0, $a0, $t0
40031a00  bnez      $t0, 0x40031af0
40031a04  nop       
40031a08  addiu     $t1, $a0, 1
40031a0c  lui       $t2, 0x8000
40031a10  sltu      $t1, $t1, $t2
40031a14  beqz      $t1, 0x40031af0
40031a18  nop       
40031a1c  sw        $zero, 0x10($fp)
40031a20  addiu     $a2, $fp, 0x10
40031a24  move      $a1, $t5
40031a28  jal       0x40061fec
40031a2c  nop       
40031a30  bltz      $v0, 0x40031a48
40031a34  nop       
40031a38  lw        $t0, 0x10($fp)
40031a3c  addiu     $t1, $t0, 1
40031a40  b         0x40031a4c
40031a44  nop       
40031a48  move      $t1, $zero
40031a4c  sw        $t1, 0x10($fp)
40031a50  b         0x40031a5c
40031a54  nop       
40031a58  move      $t1, $zero
40031a5c  sll       $a1, $t1, 1
40031a60  b         0x40031af4
40031a64  nop       
40031a68  bnez      $a1, 0x40031af4
40031a6c  nop       
40031a70  beqz      $a3, 0x40031af0
40031a74  nop       
40031a78  lui       $t0, 1
40031a7c  slt       $t0, $a0, $t0
40031a80  bnez      $t0, 0x40031af0
40031a84  nop       
40031a88  addiu     $t1, $a0, 1
40031a8c  lui       $t2, 0x8000
40031a90  sltu      $t1, $t1, $t2
40031a94  beqz      $t1, 0x40031af0
40031a98  nop       
40031a9c  sw        $zero, 0x10($fp)
40031aa0  addiu     $a2, $fp, 0x10
40031aa4  move      $a1, $t5
40031aa8  jal       0x400607ec
40031aac  nop       
40031ab0  bltz      $v0, 0x40031ac8
40031ab4  nop       
40031ab8  lw        $t0, 0x10($fp)
40031abc  addiu     $a1, $t0, 1
40031ac0  b         0x40031acc
40031ac4  nop       
40031ac8  move      $a1, $zero
40031acc  sw        $a1, 0x10($fp)
40031ad0  b         0x40031af4
40031ad4  nop       
40031ad8  move      $a1, $zero
40031adc  b         0x40031af4
40031ae0  nop       
40031ae4  lw        $a1, 0x10($fp)
40031ae8  b         0x40031af4
40031aec  nop       
40031af0  move      $a1, $zero
40031af4  move      $v0, $a1
40031af8  move      $sp, $fp
40031afc  lw        $fp, 0x18($sp)
40031b00  lw        $ra, 0x1c($sp)
40031b04  addiu     $sp, $sp, 0x20
40031b08  jr        $ra
40031b0c  nop       
40031e5c  addiu     $sp, $sp, -0x20
40031e60  sw        $ra, 0x18($sp)
40031e64  sw        $s1, 0x10($sp)
40031e68  sw        $s0, 0x14($sp)
40031e6c  move      $t0, $a3
40031e70  move      $t1, $a2
40031e74  move      $s1, $a0
40031e78  beqz      $s1, 0x40031eb0
40031e7c  move      $s0, $a1
40031e80  beqz      $s0, 0x40031eb0
40031e84  nop       
40031e88  addiu     $a3, $zero, 1
40031e8c  move      $a2, $t0
40031e90  move      $a1, $t1
40031e94  jal       0x40031960
40031e98  move      $a0, $s0
40031e9c  beqz      $v0, 0x40031eb0
40031ea0  nop       
40031ea4  sw        $s0, ($s1)
40031ea8  b         0x40031eb8
40031eac  move      $v0, $zero
40031eb0  lui       $v0, 0x8007
40031eb4  ori       $v0, $v0, 0x57
40031eb8  lw        $s1, 0x10($sp)
40031ebc  lw        $s0, 0x14($sp)
40031ec0  lw        $ra, 0x18($sp)
40031ec4  jr        $ra
40031ec8  addiu     $sp, $sp, 0x20
40031ecc  beqz      $a0, 0x40031ee4
40031ed0  nop       
40031ed4  beqz      $a1, 0x40031ee4
40031ed8  nop       
40031edc  b         0x40031eec
40031ee0  move      $v0, $zero
40031ee4  lui       $v0, 0x8007
40031ee8  ori       $v0, $v0, 0x57
40031eec  jr        $ra
40031ef0  nop       
4007fb08  addiu     $sp, $sp, -0x58
4007fb0c  sw        $ra, 0x54($sp)
4007fb10  sw        $s6, 0x38($sp)
4007fb14  sw        $s5, 0x3c($sp)
4007fb18  sw        $s4, 0x40($sp)
4007fb1c  sw        $s3, 0x44($sp)
4007fb20  sw        $s2, 0x48($sp)
4007fb24  sw        $s1, 0x4c($sp)
4007fb28  sw        $s0, 0x50($sp)
4007fb2c  move      $s0, $a3
4007fb30  move      $s4, $a2
4007fb34  move      $s5, $a1
4007fb38  jal       0x4009ea44
4007fb3c  move      $s6, $a0
4007fb40  move      $s2, $v0
4007fb44  bnez      $s2, 0x4007fb54
4007fb48  nop       
4007fb4c  b         0x4007fc74
4007fb50  addiu     $s1, $zero, 7
4007fb54  lw        $s1, 0x6c($sp)
4007fb58  andi      $s3, $s1, 1
4007fb5c  beqz      $s3, 0x4007fba8
4007fb60  nop       
4007fb64  move      $s0, $zero
4007fb68  lui       $t1, 0xfffe
4007fb6c  addiu     $t0, $sp, 0x18
4007fb70  ori       $t1, $t1, 0xffff
4007fb74  sw        $t0, 0x20($sp)
4007fb78  lui       $t2, 6
4007fb7c  and       $t0, $s1, $t1
4007fb80  or        $t0, $t0, $t2
4007fb84  sw        $s4, 0x28($sp)
4007fb88  lw        $s4, 0x70($sp)
4007fb8c  sw        $s5, 0x24($sp)
4007fb90  sw        $s0, 0x2c($sp)
4007fb94  beqz      $s4, 0x4007fc14
4007fb98  sw        $t0, 0x30($sp)
4007fb9c  lui       $a0, 0x26
4007fba0  b         0x4007fc1c
4007fba4  ori       $a0, $a0, 0x30
4007fba8  jal       0x4009edf4
4007fbac  move      $a0, $s2
4007fbb0  beqz      $v0, 0x4007fb4c
4007fbb4  nop       
4007fbb8  jal       0x40019304
4007fbbc  addiu     $a0, $zero, 0x2c
4007fbc0  beqz      $v0, 0x4007fbe8
4007fbc4  nop       
4007fbc8  lw        $a2, 0x68($sp)
4007fbcc  move      $a3, $s1
4007fbd0  move      $a1, $s0
4007fbd4  move      $a0, $v0
4007fbd8  jal       0x4009e630
4007fbdc  sw        $s2, 0x10($sp)
4007fbe0  b         0x4007fbec
4007fbe4  move      $s0, $v0
4007fbe8  move      $s0, $zero
4007fbec  beqz      $s0, 0x4007fb4c
4007fbf0  nop       
4007fbf4  jal       0x4009e6c0
4007fbf8  move      $a0, $s0
4007fbfc  bnez      $v0, 0x4007fb68
4007fc00  nop       
4007fc04  jal       0x4009e768
4007fc08  move      $a0, $s0
4007fc0c  b         0x4007fb4c
4007fc10  nop       
4007fc14  lui       $a0, 0x25
4007fc18  ori       $a0, $a0, 0x24
4007fc1c  addiu     $a2, $sp, 0x20
4007fc20  jal       0x4007f774
4007fc24  addiu     $a1, $zero, 5
4007fc28  bnez      $s3, 0x4007fc74
4007fc2c  move      $s1, $v0
4007fc30  bnez      $s1, 0x4007fc6c
4007fc34  nop       
4007fc38  lw        $t0, 0x18($sp)
4007fc3c  move      $a1, $s0
4007fc40  move      $a0, $s2
4007fc44  jal       0x4009ec18
4007fc48  sw        $t0, 0x20($s0)
4007fc4c  addiu     $a1, $zero, 0x3bb
4007fc50  bnez      $s4, 0x4007fc5c
4007fc54  sw        $v0, ($s6)
4007fc58  addiu     $a1, $zero, 0x3be
4007fc5c  addiu     $a3, $zero, 0
4007fc60  addiu     $a2, $zero, 0
4007fc64  jal       0x4009e854
4007fc68  move      $a0, $s0
4007fc6c  jal       0x4009e768
4007fc70  move      $a0, $s0
4007fc74  move      $v0, $s1
4007fc78  lw        $s6, 0x38($sp)
4007fc7c  lw        $s5, 0x3c($sp)
4007fc80  lw        $s4, 0x40($sp)
4007fc84  lw        $s3, 0x44($sp)
4007fc88  lw        $s2, 0x48($sp)
4007fc8c  lw        $s1, 0x4c($sp)
4007fc90  lw        $s0, 0x50($sp)
4007fc94  lw        $ra, 0x54($sp)
4007fc98  jr        $ra
4007fc9c  addiu     $sp, $sp, 0x58
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
4009e630  lui       $t0, 0x4001
4009e634  addiu     $t0, $t0, 0x7e70
4009e638  sw        $t0, ($a0)
4009e63c  lw        $t0, 0x10($sp)
4009e640  addiu     $t1, $zero, 1
4009e644  move      $v0, $a0
4009e648  sw        $t1, 0xc($a0)
4009e64c  sw        $zero, 0x10($a0)
4009e650  sw        $a1, 0x14($a0)
4009e654  sw        $a2, 0x18($a0)
4009e658  sw        $a3, 0x1c($a0)
4009e65c  sw        $zero, 0x24($a0)
4009e660  jr        $ra
4009e664  sw        $t0, 0x28($a0)
4009e668  addiu     $sp, $sp, -0x18
4009e66c  sw        $ra, 0x14($sp)
4009e670  sw        $s0, 0x10($sp)
4009e674  lui       $t0, 0x4001
4009e678  move      $s0, $a0
4009e67c  addiu     $t0, $t0, 0x7e70
4009e680  lw        $a0, 0x10($s0)
4009e684  beqz      $a0, 0x4009e698
4009e688  sw        $t0, ($s0)
4009e68c  jal       0x4002ce78
4009e690  nop       
4009e694  sw        $zero, 0x10($s0)
4009e698  lw        $a0, 0x24($s0)
4009e69c  beqz      $a0, 0x4009e6b0
4009e6a0  nop       
4009e6a4  jal       0x4002ce78
4009e6a8  nop       
4009e6ac  sw        $zero, 0x24($s0)
4009e6b0  lw        $s0, 0x10($sp)
4009e6b4  lw        $ra, 0x14($sp)
4009e6b8  jr        $ra
4009e6bc  addiu     $sp, $sp, 0x18
4009e6c0  addiu     $sp, $sp, -0x30
4009e6c4  sw        $ra, 0x2c($sp)
4009e6c8  sw        $s0, 0x28($sp)
4009e6cc  move      $s0, $a0
4009e6d0  lw        $t0, 0x1c($s0)
4009e6d4  lui       $t1, 7
4009e6d8  lui       $t2, 6
4009e6dc  and       $t1, $t0, $t1
4009e6e0  bne       $t1, $t2, 0x4009e714
4009e6e4  nop       
4009e6e8  addiu     $t3, $zero, 0x14
4009e6ec  addiu     $a0, $zero, 0xc
4009e6f0  sw        $t3, 0x10($sp)
4009e6f4  jal       0x40030a84
4009e6f8  sw        $zero, 0x20($sp)
4009e6fc  lw        $a1, 0x14($s0)
4009e700  addiu     $a2, $sp, 0x10
4009e704  jal       0x4002df18
4009e708  move      $a0, $v0
4009e70c  beqz      $v0, 0x4009e738
4009e710  sw        $v0, 0x24($s0)
4009e714  addiu     $a3, $zero, 0
4009e718  addiu     $a2, $zero, 0
4009e71c  addiu     $a1, $zero, 0
4009e720  jal       0x4002ab0c
4009e724  addiu     $a0, $zero, 0
4009e728  beqz      $v0, 0x4009e738
4009e72c  sw        $v0, 0x10($s0)
4009e730  b         0x4009e73c
4009e734  addiu     $v0, $zero, 1
4009e738  move      $v0, $zero
4009e73c  lw        $s0, 0x28($sp)
4009e740  lw        $ra, 0x2c($sp)
4009e744  jr        $ra
4009e748  addiu     $sp, $sp, 0x30
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
4009e9a8  addiu     $sp, $sp, -0x20
4009e9ac  sw        $ra, 0x18($sp)
4009e9b0  sw        $s1, 0x10($sp)
4009e9b4  sw        $s0, 0x14($sp)
4009e9b8  move      $s1, $a0
4009e9bc  move      $a0, $s1
4009e9c0  jal       0x4009e668
4009e9c4  move      $s0, $a1
4009e9c8  andi      $a0, $s0, 1
4009e9cc  beqz      $a0, 0x4009e9dc
4009e9d0  nop       
4009e9d4  jal       0x40019380
4009e9d8  move      $a0, $s1
4009e9dc  move      $v0, $s1
4009e9e0  lw        $s1, 0x10($sp)
4009e9e4  lw        $s0, 0x14($sp)
4009e9e8  lw        $ra, 0x18($sp)
4009e9ec  jr        $ra
4009e9f0  addiu     $sp, $sp, 0x20
4009ea98  addiu     $sp, $sp, -0x50
4009ea9c  sw        $ra, 0x48($sp)
4009eaa0  sw        $fp, 0x38($sp)
4009eaa4  sw        $s2, 0x3c($sp)
4009eaa8  sw        $s1, 0x40($sp)
4009eaac  sw        $s0, 0x44($sp)
4009eab0  move      $fp, $sp
4009eab4  move      $s0, $a0
4009eab8  sw        $s0, 0x50($fp)
4009eabc  addiu     $s1, $zero, 0x14
4009eac0  lui       $s2, 0xffff
4009eac4  ori       $s2, $s2, 0xffef
4009eac8  addiu     $t0, $fp, 0x1c
4009eacc  sw        $t0, 0x14($sp)
4009ead0  lui       $t1, 0xffff
4009ead4  ori       $t1, $t1, 0xffff
4009ead8  sw        $t1, 0x10($sp)
4009eadc  addiu     $a3, $fp, 0x18
4009eae0  addiu     $a2, $zero, 0x14
4009eae4  addiu     $a1, $fp, 0x20
4009eae8  lw        $a0, 0x18($s0)
4009eaec  jal       0x4002cab8
4009eaf0  nop       
4009eaf4  bnez      $v0, 0x4009eb08
4009eaf8  nop       
4009eafc  move      $v0, $zero
4009eb00  b         0x4009ebc0
4009eb04  nop       
4009eb08  lw        $t0, 0x18($fp)
4009eb0c  bne       $t0, $s1, 0x4009eac8
4009eb10  nop       
4009eb14  addiu     $t1, $zero, 0x3bd
4009eb18  lw        $a1, 0x20($fp)
4009eb1c  beq       $a1, $t1, 0x4009eb64
4009eb20  nop       
4009eb24  addiu     $t0, $zero, 0x3c0
4009eb28  bne       $a1, $t0, 0x4009eb88
4009eb2c  nop       
4009eb30  lw        $t3, 0x28($fp)
4009eb34  addiu     $t2, $t3, 0x10
4009eb38  lwl       $t0, 3($t2)
4009eb3c  lwr       $t0, ($t2)
4009eb40  and       $t0, $t0, $s2
4009eb44  ori       $t1, $t0, 1
4009eb48  swl       $t1, 3($t2)
4009eb4c  swr       $t1, ($t2)
4009eb50  lw        $t2, 0x30($fp)
4009eb54  swl       $t2, 0xb($t3)
4009eb58  swr       $t2, 8($t3)
4009eb5c  b         0x4009eb84
4009eb60  nop       
4009eb64  lw        $t0, 0x28($fp)
4009eb68  addiu     $t3, $t0, 0x10
4009eb6c  lwl       $t1, 3($t3)
4009eb70  lwr       $t1, ($t3)
4009eb74  and       $t1, $t1, $s2
4009eb78  ori       $t2, $t1, 1
4009eb7c  swl       $t2, 3($t3)
4009eb80  swr       $t2, ($t3)
4009eb84  lw        $a1, 0x20($fp)
4009eb88  lw        $a3, 0x2c($fp)
4009eb8c  lw        $a2, 0x28($fp)
4009eb90  lw        $a0, 0x24($fp)
4009eb94  jal       0x4009e854
4009eb98  nop       
4009eb9c  b         0x4009eac8
4009eba0  nop       
4009eba4  addiu     $s1, $zero, 0x14
4009eba8  lui       $s2, 0xffff
4009ebac  ori       $s2, $s2, 0xffef
4009ebb0  lw        $s0, 0x50($fp)
4009ebb4  b         0x4009eac8
4009ebb8  nop       
4009ebbc  lw        $v0, 0x1c($fp)
4009ebc0  move      $sp, $fp
4009ebc4  lw        $fp, 0x38($sp)
4009ebc8  lw        $s2, 0x3c($sp)
4009ebcc  lw        $s1, 0x40($sp)
4009ebd0  lw        $s0, 0x44($sp)
4009ebd4  lw        $ra, 0x48($sp)
4009ebd8  addiu     $sp, $sp, 0x50
4009ebdc  jr        $ra
4009ebe0  nop       
4009ebf0  addiu     $sp, $sp, -0x20
4009ebf4  sw        $ra, 0x18($sp)
4009ebf8  lw        $a0, 0x1c($a0)
4009ebfc  addiu     $a3, $zero, 0
4009ec00  addiu     $a2, $zero, 0x14
4009ec04  jal       0x4002cb1c
4009ec08  sw        $zero, 0x10($sp)
4009ec0c  lw        $ra, 0x18($sp)
4009ec10  jr        $ra
4009ec14  addiu     $sp, $sp, 0x20
4009ec18  addiu     $sp, $sp, -0x20
4009ec1c  sw        $ra, 0x1c($sp)
4009ec20  sw        $s2, 0x10($sp)
4009ec24  sw        $s1, 0x14($sp)
4009ec28  sw        $s0, 0x18($sp)
4009ec2c  move      $s0, $a0
4009ec30  addiu     $s1, $s0, 4
4009ec34  move      $a0, $s1
4009ec38  jal       0x40030a8c
4009ec3c  move      $s2, $a1
4009ec40  jal       0x4009e74c
4009ec44  move      $a0, $s2
4009ec48  addiu     $a2, $s0, 0x20
4009ec4c  lw        $t1, ($a2)
4009ec50  addiu     $t0, $s2, 4
4009ec54  sw        $t1, ($t0)
4009ec58  sw        $a2, 8($s2)
4009ec5c  sw        $t0, 4($t1)
4009ec60  move      $a0, $s1
4009ec64  jal       0x40030b78
4009ec68  sw        $t0, ($a2)
4009ec6c  lw        $v0, 0x20($s2)
4009ec70  lw        $s2, 0x10($sp)
4009ec74  lw        $s1, 0x14($sp)
4009ec78  lw        $s0, 0x18($sp)
4009ec7c  lw        $ra, 0x1c($sp)
4009ec80  jr        $ra
4009ec84  addiu     $sp, $sp, 0x20
4009ec88  addiu     $sp, $sp, -0x20
4009ec8c  sw        $ra, 0x18($sp)
4009ec90  sw        $s1, 0x10($sp)
4009ec94  sw        $s0, 0x14($sp)
4009ec98  addiu     $s1, $a0, 4
4009ec9c  move      $a0, $s1
4009eca0  jal       0x40030a8c
4009eca4  move      $s0, $a1
4009eca8  lw        $t1, 8($s0)
4009ecac  lw        $t0, 4($s0)
4009ecb0  move      $a0, $s0
4009ecb4  sw        $t0, ($t1)
4009ecb8  lw        $t2, 4($s0)
4009ecbc  lw        $t1, 8($s0)
4009ecc0  jal       0x4009e768
4009ecc4  sw        $t1, 4($t2)
4009ecc8  jal       0x40030b78
4009eccc  move      $a0, $s1
4009ecd0  lw        $s1, 0x10($sp)
4009ecd4  lw        $s0, 0x14($sp)
4009ecd8  lw        $ra, 0x18($sp)
4009ecdc  addiu     $v0, $zero, 1
4009ece0  jr        $ra
4009ece4  addiu     $sp, $sp, 0x20
4009ece8  addiu     $sp, $sp, -0x28
4009ecec  sw        $ra, 0x20($sp)
4009ecf0  sw        $s3, 0x10($sp)
4009ecf4  sw        $s2, 0x14($sp)
4009ecf8  sw        $s1, 0x18($sp)
4009ecfc  sw        $s0, 0x1c($sp)
4009ed00  move      $s0, $a0
4009ed04  addiu     $s2, $s0, 4
4009ed08  move      $a0, $s2
4009ed0c  move      $s3, $a1
4009ed10  jal       0x40030a8c
4009ed14  move      $s1, $zero
4009ed18  addiu     $a2, $s0, 0x20
4009ed1c  lw        $t1, ($a2)
4009ed20  beq       $t1, $a2, 0x4009ed54
4009ed24  nop       
4009ed28  addiu     $a0, $t1, -4
4009ed2c  lw        $t0, 0x20($a0)
4009ed30  beq       $t0, $s3, 0x4009ed4c
4009ed34  nop       
4009ed38  lw        $t1, ($t1)
4009ed3c  bne       $t1, $a2, 0x4009ed28
4009ed40  nop       
4009ed44  b         0x4009ed54
4009ed48  nop       
4009ed4c  jal       0x4009e74c
4009ed50  move      $s1, $a0
4009ed54  jal       0x40030b78
4009ed58  move      $a0, $s2
4009ed5c  move      $v0, $s1
4009ed60  lw        $s3, 0x10($sp)
4009ed64  lw        $s2, 0x14($sp)
4009ed68  lw        $s1, 0x18($sp)
4009ed6c  lw        $s0, 0x1c($sp)
4009ed70  lw        $ra, 0x20($sp)
4009ed74  jr        $ra
4009ed78  addiu     $sp, $sp, 0x28
4009edf4  addiu     $sp, $sp, -0x68
4009edf8  sw        $ra, 0x60($sp)
4009edfc  sw        $s5, 0x48($sp)
4009ee00  sw        $s4, 0x4c($sp)
4009ee04  sw        $s3, 0x50($sp)
4009ee08  sw        $s2, 0x54($sp)
4009ee0c  sw        $s1, 0x58($sp)
4009ee10  sw        $s0, 0x5c($sp)
4009ee14  move      $s1, $a0
4009ee18  lw        $t0, 0x18($s1)
4009ee1c  beqz      $t0, 0x4009ee2c
4009ee20  nop       
4009ee24  b         0x4009f060
4009ee28  addiu     $s0, $zero, 1
4009ee2c  addiu     $s3, $s1, 4
4009ee30  jal       0x40030a8c
4009ee34  move      $a0, $s3
4009ee38  lw        $a0, 0x18($s1)
4009ee3c  beqz      $a0, 0x4009ee4c
4009ee40  nop       
4009ee44  b         0x4009f058
4009ee48  addiu     $s0, $zero, 1
4009ee4c  addiu     $t1, $zero, 0x14
4009ee50  addiu     $t0, $zero, 3
4009ee54  addiu     $s5, $zero, 1
4009ee58  addiu     $a1, $sp, 0x30
4009ee5c  addiu     $a0, $zero, 0
4009ee60  sw        $t1, 0x30($sp)
4009ee64  sw        $t0, 0x34($sp)
4009ee68  sw        $s5, 0x40($sp)
4009ee6c  sw        $t1, 0x3c($sp)
4009ee70  jal       0x4002ca98
4009ee74  sw        $zero, 0x38($sp)
4009ee78  bnez      $v0, 0x4009ee88
4009ee7c  sw        $v0, 0x18($s1)
4009ee80  b         0x4009f028
4009ee84  move      $s0, $zero
4009ee88  addiu     $a0, $zero, 0xc
4009ee8c  jal       0x40030a84
4009ee90  sw        $zero, 0x40($sp)
4009ee94  lw        $a1, 0x18($s1)
4009ee98  addiu     $a2, $sp, 0x30
4009ee9c  jal       0x4002df18
4009eea0  move      $a0, $v0
4009eea4  beqz      $v0, 0x4009ee80
4009eea8  sw        $v0, 0x1c($s1)
4009eeac  lui       $a0, 0x1d
4009eeb0  addiu     $a2, $sp, 0x24
4009eeb4  addiu     $a1, $zero, 1
4009eeb8  ori       $a0, $a0, 0x10
4009eebc  jal       0x4007f774
4009eec0  sw        $v0, 0x24($sp)
4009eec4  move      $s0, $v0
4009eec8  beqz      $s0, 0x4009f028
4009eecc  nop       
4009eed0  lui       $t1, 0x400a
4009eed4  addiu     $t0, $s1, 0x28
4009eed8  move      $a3, $s1
4009eedc  addiu     $a2, $t1, -0x122c
4009eee0  addiu     $a1, $zero, 0
4009eee4  addiu     $a0, $zero, 0
4009eee8  sw        $t0, 0x14($sp)
4009eeec  jal       0x4002c86c
4009eef0  sw        $zero, 0x10($sp)
4009eef4  move      $s2, $v0
4009eef8  beqz      $s2, 0x4009efc8
4009eefc  nop       
4009ef00  lui       $s4, 0x7fff
4009ef04  lui       $a0, 0x8000
4009ef08  lui       $t1, 0x4001
4009ef0c  addiu     $t0, $sp, 0x20
4009ef10  ori       $s4, $s4, 0xffff
4009ef14  addiu     $a3, $zero, 0
4009ef18  addiu     $a2, $zero, 0
4009ef1c  addiu     $a1, $t1, 0x7e9c ; string candidate 'Audio'
4009ef20  ori       $a0, $a0, 2
4009ef24  sw        $s4, 0x18($sp)
4009ef28  jal       0x400340d0
4009ef2c  sw        $t0, 0x10($sp)
4009ef30  bnez      $v0, 0x4009efa4
4009ef34  nop       
4009ef38  lui       $t2, 0x4001
4009ef3c  addiu     $s0, $zero, 4
4009ef40  addiu     $t0, $sp, 0x1c
4009ef44  lw        $a0, 0x20($sp)
4009ef48  addiu     $t1, $sp, 0x2c
4009ef4c  addiu     $a3, $sp, 0x28
4009ef50  addiu     $a2, $zero, 0
4009ef54  addiu     $a1, $t2, 0x7e78 ; string candidate 'ProxyPriority256'
4009ef58  sw        $s0, 0x1c($sp)
4009ef5c  sw        $t0, 0x14($sp)
4009ef60  jal       0x40034198
4009ef64  sw        $t1, 0x10($sp)
4009ef68  bnez      $v0, 0x4009ef9c
4009ef6c  nop       
4009ef70  lw        $t0, 0x28($sp)
4009ef74  bne       $t0, $s0, 0x4009ef9c
4009ef78  nop       
4009ef7c  lw        $t1, 0x1c($sp)
4009ef80  bne       $t1, $s0, 0x4009ef9c
4009ef84  nop       
4009ef88  lw        $t3, 0x2c($sp)
4009ef8c  sltiu     $t2, $t3, 0x100
4009ef90  beqz      $t2, 0x4009ef9c
4009ef94  nop       
4009ef98  sw        $t3, 0x18($sp)
4009ef9c  jal       0x40033eb4
4009efa0  lw        $a0, 0x20($sp)
4009efa4  lw        $a1, 0x18($sp)
4009efa8  bne       $a1, $s4, 0x4009eff8
4009efac  nop       
4009efb0  addiu     $a1, $sp, 0x18
4009efb4  addiu     $t0, $zero, -0x4826
4009efb8  jalr      $t0
4009efbc  addiu     $a0, $zero, 0x41
4009efc0  bne       $v0, $s4, 0x4009efd0
4009efc4  nop       
4009efc8  b         0x4009f010
4009efcc  move      $s0, $zero
4009efd0  lw        $a1, 0x18($sp)
4009efd4  beqz      $a1, 0x4009efe4
4009efd8  nop       
4009efdc  addiu     $a1, $a1, -1
4009efe0  sw        $a1, 0x18($sp)
4009efe4  sltiu     $t0, $a1, 0xfa
4009efe8  bnez      $t0, 0x4009eff8
4009efec  nop       
4009eff0  addiu     $a1, $zero, 0xf9
4009eff4  sw        $a1, 0x18($sp)
4009eff8  addiu     $t0, $zero, -0x482a
4009effc  jalr      $t0
4009f000  move      $a0, $s2
4009f004  beqz      $v0, 0x4009f010
4009f008  move      $s0, $zero
4009f00c  move      $s0, $s5
4009f010  beqz      $s2, 0x4009f020
4009f014  nop       
4009f018  jal       0x4002ce78
4009f01c  move      $a0, $s2
4009f020  bnez      $s0, 0x4009f058
4009f024  nop       
4009f028  lw        $a0, 0x18($s1)
4009f02c  beqz      $a0, 0x4009f040
4009f030  nop       
4009f034  jal       0x4002cb60
4009f038  nop       
4009f03c  sw        $zero, 0x18($s1)
4009f040  lw        $a0, 0x1c($s1)
4009f044  beqz      $a0, 0x4009f058
4009f048  nop       
4009f04c  jal       0x4002cb60
4009f050  nop       
4009f054  sw        $zero, 0x1c($s1)
4009f058  jal       0x40030b78
4009f05c  move      $a0, $s3
4009f060  move      $v0, $s0
4009f064  lw        $s5, 0x48($sp)
4009f068  lw        $s4, 0x4c($sp)
4009f06c  lw        $s3, 0x50($sp)
4009f070  lw        $s2, 0x54($sp)
4009f074  lw        $s1, 0x58($sp)
4009f078  lw        $s0, 0x5c($sp)
4009f07c  lw        $ra, 0x60($sp)
4009f080  jr        $ra
4009f084  addiu     $sp, $sp, 0x68
; audevman.dll 9991a8b5f195c29aff63fee1c5fd034e1295b84cef43a37463f93863dfdd3d65
c0412900  addiu     $sp, $sp, -0x60
c0412904  sw        $ra, 0x5c($sp)
c0412908  sw        $s6, 0x40($sp)
c041290c  sw        $s5, 0x44($sp)
c0412910  sw        $s4, 0x48($sp)
c0412914  sw        $s3, 0x4c($sp)
c0412918  sw        $s2, 0x50($sp)
c041291c  sw        $s1, 0x54($sp)
c0412920  sw        $s0, 0x58($sp)
c0412924  move      $s0, $a0
c0412928  lw        $t5, -0x18($s0)
c041292c  move      $s3, $a3
c0412930  move      $s1, $a1
c0412934  bnez      $t5, 0xc0412944
c0412938  move      $s2, $zero
c041293c  b         0xc0412af0
c0412940  addiu     $v0, $zero, 6
c0412944  lw        $t0, -0x1c($s0)
c0412948  addiu     $s4, $zero, 6
c041294c  addiu     $s5, $zero, 5
c0412950  beqz      $t0, 0xc04129fc
c0412954  addiu     $t6, $zero, 1
c0412958  beq       $s1, $s5, 0xc04129a0
c041295c  nop       
c0412960  bne       $s1, $s4, 0xc04129fc
c0412964  nop       
c0412968  lw        $t2, 0x70($sp)
c041296c  lui       $t1, 0x8000
c0412970  and       $t0, $t2, $t1
c0412974  bnez      $t0, 0xc0412990
c0412978  nop       
c041297c  lui       $t3, 0x4000
c0412980  and       $t1, $t2, $t3
c0412984  beqz      $t1, 0xc0412990
c0412988  nop       
c041298c  move      $s2, $t6
c0412990  lui       $t0, 0x3fff
c0412994  ori       $t0, $t0, 0xffff
c0412998  b         0xc0412a00
c041299c  and       $t3, $t2, $t0
c04129a0  lw        $t4, 0x70($sp)
c04129a4  andi      $t0, $t4, 1
c04129a8  bnez      $t0, 0xc04129ec
c04129ac  nop       
c04129b0  lui       $t1, 0x8000
c04129b4  and       $t1, $t4, $t1
c04129b8  bnez      $t1, 0xc04129ec
c04129bc  nop       
c04129c0  lui       $t2, 0x4000
c04129c4  and       $t2, $t4, $t2
c04129c8  beqz      $t2, 0xc04129ec
c04129cc  nop       
c04129d0  lw        $t0, -0x14($s0)
c04129d4  slti      $t3, $t0, 2
c04129d8  beqz      $t3, 0xc04129e8
c04129dc  nop       
c04129e0  b         0xc0412af0
c04129e4  addiu     $v0, $zero, 4
c04129e8  move      $s2, $t6
c04129ec  lui       $t0, 0x3fff
c04129f0  ori       $t0, $t0, 0xffff
c04129f4  b         0xc0412a00
c04129f8  and       $t3, $t4, $t0
c04129fc  lw        $t3, 0x70($sp)
c0412a00  lw        $t0, -0x20($s0)
c0412a04  addiu     $t1, $sp, 0x24
c0412a08  sw        $t0, 0x28($sp)
c0412a0c  addiu     $t0, $sp, 0x20
c0412a10  sw        $t0, 0x10($sp)
c0412a14  lui       $a1, 0x1d
c0412a18  lui       $t0, 0xc042
c0412a1c  sw        $a2, 0x30($sp)
c0412a20  sw        $s1, 0x2c($sp)
c0412a24  sw        $s3, 0x34($sp)
c0412a28  sw        $t3, 0x38($sp)
c0412a2c  sw        $t6, 0x20($sp)
c0412a30  addiu     $s6, $zero, 4
c0412a34  lw        $a0, ($t5)
c0412a38  lw        $t0, -0x7fe4($t0) ; IAT COREDLL.dll!DeviceIoControl@179
c0412a3c  addiu     $a3, $zero, 0x14
c0412a40  addiu     $a2, $sp, 0x28
c0412a44  ori       $a1, $a1, 0xc
c0412a48  sw        $zero, 0x1c($sp)
c0412a4c  sw        $t1, 0x18($sp)
c0412a50  jalr      $t0 ; call candidate COREDLL.dll!DeviceIoControl@179
c0412a54  sw        $s6, 0x14($sp)
c0412a58  bnez      $v0, 0xc0412a68
c0412a5c  nop       
c0412a60  b         0xc0412a6c
c0412a64  move      $v0, $s4
c0412a68  lw        $v0, 0x20($sp)
c0412a6c  beqz      $s2, 0xc0412aa4
c0412a70  nop       
c0412a74  bnez      $v0, 0xc0412aa4
c0412a78  nop       
c0412a7c  bne       $s1, $s5, 0xc0412a90
c0412a80  nop       
c0412a84  lw        $t0, -0x14($s0)
c0412a88  b         0xc0412aa0
c0412a8c  addiu     $t1, $t0, -1
c0412a90  bne       $s1, $s4, 0xc0412aa4
c0412a94  nop       
c0412a98  lw        $t0, -0x14($s0)
c0412a9c  addiu     $t1, $t0, 1
c0412aa0  sw        $t1, -0x14($s0)
c0412aa4  lw        $t2, -0x1c($s0)
c0412aa8  beqz      $t2, 0xc0412af0
c0412aac  nop       
c0412ab0  bnez      $v0, 0xc0412af0
c0412ab4  nop       
c0412ab8  bne       $s1, $s6, 0xc0412af0
c0412abc  nop       
c0412ac0  addiu     $t1, $s3, 0x50
c0412ac4  lwl       $t0, 3($t1)
c0412ac8  lwr       $t0, ($t1)
c0412acc  ori       $t0, $t0, 0xe
c0412ad0  addiu     $t2, $s3, 0x48
c0412ad4  swl       $t0, 3($t1)
c0412ad8  swr       $t0, ($t1)
c0412adc  lwl       $t1, 3($t2)
c0412ae0  lwr       $t1, ($t2)
c0412ae4  ori       $t1, $t1, 0xfff
c0412ae8  swl       $t1, 3($t2)
c0412aec  swr       $t1, ($t2)
c0412af0  lw        $s6, 0x40($sp)
c0412af4  lw        $s5, 0x44($sp)
c0412af8  lw        $s4, 0x48($sp)
c0412afc  lw        $s3, 0x4c($sp)
c0412b00  lw        $s2, 0x50($sp)
c0412b04  lw        $s1, 0x54($sp)
c0412b08  lw        $s0, 0x58($sp)
c0412b0c  lw        $ra, 0x5c($sp)
c0412b10  jr        $ra
c0412b14  addiu     $sp, $sp, 0x60
; Blue.exe 5e659f513327c84964a929ea9b9e3192384b3031fa6e6ffb6ad76b02af1b7c7b
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
