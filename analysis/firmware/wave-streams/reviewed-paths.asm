; wavedev2_i2s.dll fec5ab038cf274c4cf74a6553f9a81328bba7100c8ec9b17438658a7fae9d67c
c0942138  addiu     $sp, $sp, -0x40
c094213c  sw        $ra, 0x38($sp)
c0942140  sw        $fp, 0x18($sp)
c0942144  sw        $s6, 0x1c($sp)
c0942148  sw        $s5, 0x20($sp)
c094214c  sw        $s4, 0x24($sp)
c0942150  sw        $s3, 0x28($sp)
c0942154  sw        $s2, 0x2c($sp)
c0942158  sw        $s1, 0x30($sp)
c094215c  sw        $s0, 0x34($sp)
c0942160  move      $fp, $sp
c0942164  move      $s6, $a1
c0942168  sw        $s6, 0x44($fp)
c094216c  move      $s0, $a0
c0942170  addiu     $a0, $zero, 0
c0942174  lui       $t0, 0xc095
c0942178  lw        $t0, -0x5f70($t0) ; IAT COREDLL.dll!SetLastError@517
c094217c  jalr      $t0 ; call candidate COREDLL.dll!SetLastError@517
c0942180  nop       
c0942184  lw        $s4, 4($s0)
c0942188  lw        $s3, 0xc($s0)
c094218c  lw        $s5, 0x10($s0)
c0942190  lw        $s1, 8($s0)
c0942194  lui       $t0, 0xc095
c0942198  addiu     $s2, $t0, -0x5ec0
c094219c  lw        $t0, ($s2)
c09421a0  addiu     $a0, $t0, 4
c09421a4  jal       0xc0948a98 ; import thunk COREDLL.dll!EnterCriticalSection@4
c09421a8  nop       
c09421ac  sltiu     $t0, $s4, 0x401
c09421b0  beqz      $t0, 0xc09425e8
c09421b4  nop       
c09421b8  addiu     $t1, $zero, 0x400
c09421bc  beq       $s4, $t1, 0xc09425bc
c09421c0  nop       
c09421c4  addiu     $t3, $s4, -3
c09421c8  sltiu     $t1, $t3, 0x3c
c09421cc  beqz      $t1, 0xc0942600
c09421d0  nop       
c09421d4  lui       $t2, 0xc094
c09421d8  addiu     $t2, $t2, 0x21f4
c09421dc  sll       $t0, $t3, 1
c09421e0  addu      $t0, $t0, $t2
c09421e4  lh        $t0, ($t0)
c09421e8  addu      $t2, $t2, $t0
c09421ec  jr        $t2
c09421f0  nop       
c09421f4  .byte     0x78, 0x00, 0x88, 0x00
c09421f8  .byte     0x1c, 0x01, 0x50, 0x01
c09421fc  teqi      $zero, 0x40c
c0942200  .byte     0x6c, 0x02, 0x2c, 0x02
c0942204  .byte     0x10, 0x02, 0x5c, 0x02
c0942208  teqi      $zero, 0x23c
c094220c  syscall   0x9f010
c0942210  tge       $t8, $t0, 0xa
c0942214  .byte     0xf8, 0x02, 0xe4, 0x02
c0942218  syscall   0x3a010
c094221c  .byte     0x20, 0x03, 0x74, 0x03
c0942220  teqi      $zero, 0x40c
c0942224  teqi      $zero, 0x40c
c0942228  teqi      $zero, 0x40c
c094222c  teqi      $zero, 0x40c
c0942230  teqi      $zero, 0x40c
c0942234  teqi      $zero, 0x40c
c0942238  teqi      $zero, 0x40c
c094223c  teqi      $zero, 0x40c
c0942240  teqi      $zero, 0x40c
c0942244  teqi      $zero, 0x40c
c0942248  teqi      $zero, 0x40c
c094224c  teqi      $zero, 0x40c
c0942250  syscall   0x1e010
c0942254  .byte     0xd0, 0x00, 0x40, 0x01
c0942258  teqi      $zero, 0x150
c094225c  syscall   0x9b010
c0942260  .byte     0x10, 0x02, 0x2c, 0x02
c0942264  .byte     0x5c, 0x02, 0x3c, 0x02
c0942268  .byte     0x58, 0x03, 0xac, 0x03
c094226c  addiu     $s1, $zero, 1
c0942270  move      $s0, $s1
c0942274  b         0xc0942680
c0942278  nop       
c094227c  beqz      $s1, 0xc0942298
c0942280  nop       
c0942284  move      $a0, $s1
c0942288  jal       0xc09435f4
c094228c  nop       
c0942290  b         0xc09422a0
c0942294  nop       
c0942298  lw        $t0, ($s2)
c094229c  addiu     $v0, $t0, 0x50
c09422a0  lw        $t1, ($v0)
c09422a4  lw        $t0, 0xc($t1)
c09422a8  move      $a0, $v0
c09422ac  move      $a1, $s3
c09422b0  move      $a2, $s5
c09422b4  jalr      $t0
c09422b8  nop       
c09422bc  b         0xc0942678
c09422c0  nop       
c09422c4  bnez      $s1, 0xc0942284
c09422c8  nop       
c09422cc  lw        $t0, ($s2)
c09422d0  addiu     $v0, $t0, 0x20
c09422d4  b         0xc09422a0
c09422d8  nop       
c09422dc  beqz      $s1, 0xc09422f8
c09422e0  nop       
c09422e4  move      $a0, $s1
c09422e8  jal       0xc09435f4
c09422ec  nop       
c09422f0  b         0xc0942300
c09422f4  nop       
c09422f8  lw        $t0, ($s2)
c09422fc  addiu     $v0, $t0, 0x50
c0942300  lw        $t1, ($v0)
c0942304  lw        $t0, 8($t1)
c0942308  b         0xc09422a8
c094230c  nop       
c0942310  lw        $t0, ($s2)
c0942314  addiu     $a0, $t0, 0x50
c0942318  move      $a3, $s1
c094231c  move      $a2, $s5
c0942320  move      $a1, $s3
c0942324  jal       0xc0942d00
c0942328  nop       
c094232c  b         0xc0942678
c0942330  nop       
c0942334  lw        $t0, ($s2)
c0942338  addiu     $a0, $t0, 0x20
c094233c  b         0xc0942318
c0942340  nop       
c0942344  lui       $t0, 0xc094
c0942348  addiu     $a0, $t0, 0x1084
c094234c  jal       0xc0948ab8 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0942350  nop       
c0942354  lw        $a1, ($s1)
c0942358  move      $a0, $s1
c094235c  lw        $t0, 8($a1)
c0942360  jalr      $t0
c0942364  nop       
c0942368  move      $s0, $v0
c094236c  sw        $s0, 0x10($fp)
c0942370  bnez      $s0, 0xc0942384
c0942374  nop       
c0942378  move      $a0, $s1
c094237c  jal       0xc0943888
c0942380  nop       
c0942384  lw        $t3, ($s2)
c0942388  addiu     $t0, $t3, 0x50
c094238c  addiu     $t1, $t0, 4
c0942390  lw        $t0, ($t1)
c0942394  bne       $t0, $t1, 0xc09423bc
c0942398  nop       
c094239c  move      $a0, $t3
c09423a0  jal       0xc094776c
c09423a4  nop       
c09423a8  lui       $a0, 0xc094
c09423ac  addiu     $a0, $a0, 0x1060
c09423b0  jal       0xc0948ab8 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c09423b4  nop       
c09423b8  lw        $t3, ($s2)
c09423bc  addiu     $t0, $t3, 0x20
c09423c0  addiu     $t1, $t0, 4
c09423c4  lw        $t0, ($t1)
c09423c8  bne       $t0, $t1, 0xc09423f8
c09423cc  nop       
c09423d0  move      $a0, $t3
c09423d4  jal       0xc09477dc
c09423d8  nop       
c09423dc  lui       $a0, 0xc094
c09423e0  addiu     $a0, $a0, 0x103c
c09423e4  jal       0xc0948ab8 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c09423e8  nop       
c09423ec  addiu     $s1, $zero, 1
c09423f0  b         0xc0942684
c09423f4  nop       
c09423f8  addiu     $s1, $zero, 1
c09423fc  b         0xc0942688
c0942400  nop       
c0942404  lw        $t0, ($s1)
c0942408  lw        $t0, 0x10($t0)
c094240c  move      $a0, $s1
c0942410  jalr      $t0
c0942414  nop       
c0942418  b         0xc0942678
c094241c  nop       
c0942420  lw        $t0, ($s1)
c0942424  lw        $t0, 0x14($t0)
c0942428  b         0xc094240c
c094242c  nop       
c0942430  lw        $t0, ($s1)
c0942434  lw        $t0, 0xc($t0)
c0942438  move      $a1, $s3
c094243c  move      $a0, $s1
c0942440  jalr      $t0
c0942444  nop       
c0942448  b         0xc0942678
c094244c  nop       
c0942450  lw        $t0, ($s1)
c0942454  lw        $t0, 0x18($t0)
c0942458  b         0xc094240c
c094245c  nop       
c0942460  lw        $t0, ($s1)
c0942464  lw        $t0, 0x30($t0)
c0942468  b         0xc0942438
c094246c  nop       
c0942470  beqz      $s1, 0xc094248c
c0942474  nop       
c0942478  move      $a0, $s1
c094247c  jal       0xc09436cc
c0942480  nop       
c0942484  b         0xc0942494
c0942488  nop       
c094248c  jal       0xc09473e0
c0942490  nop       
c0942494  sw        $v0, ($s3)
c0942498  move      $s0, $zero
c094249c  b         0xc094267c
c09424a0  nop       
c09424a4  beqz      $s1, 0xc09424c4
c09424a8  nop       
c09424ac  move      $a1, $s3
c09424b0  move      $a0, $s1
c09424b4  jal       0xc09436d4
c09424b8  nop       
c09424bc  b         0xc0942678
c09424c0  nop       
c09424c4  move      $a0, $s3
c09424c8  jal       0xc0947390
c09424cc  nop       
c09424d0  b         0xc0942678
c09424d4  nop       
c09424d8  move      $a0, $s1
c09424dc  jal       0xc0943ab8
c09424e0  nop       
c09424e4  b         0xc0942678
c09424e8  nop       
c09424ec  lw        $t0, ($s1)
c09424f0  lw        $t0, 0x3c($t0)
c09424f4  b         0xc0942438
c09424f8  nop       
c09424fc  move      $a1, $s3
c0942500  move      $a0, $s1
c0942504  jal       0xc0943e34
c0942508  nop       
c094250c  b         0xc0942678
c0942510  nop       
c0942514  move      $a1, $s3
c0942518  beqz      $s1, 0xc0942534
c094251c  nop       
c0942520  move      $a0, $s1
c0942524  jal       0xc094415c
c0942528  nop       
c094252c  b         0xc0942678
c0942530  nop       
c0942534  lw        $t0, ($s2)
c0942538  addiu     $a0, $t0, 0x50
c094253c  jal       0xc0942fc4
c0942540  nop       
c0942544  b         0xc0942678
c0942548  nop       
c094254c  move      $a1, $s3
c0942550  bnez      $s1, 0xc0942520
c0942554  nop       
c0942558  lw        $t0, ($s2)
c094255c  addiu     $a0, $t0, 0x20
c0942560  b         0xc094253c
c0942564  nop       
c0942568  move      $a1, $s3
c094256c  beqz      $s1, 0xc0942588
c0942570  nop       
c0942574  move      $a0, $s1
c0942578  jal       0xc0944178
c094257c  nop       
c0942580  b         0xc0942678
c0942584  nop       
c0942588  lw        $t0, ($s2)
c094258c  addiu     $a0, $t0, 0x50
c0942590  jal       0xc0945ccc
c0942594  nop       
c0942598  b         0xc0942678
c094259c  nop       
c09425a0  move      $a1, $s3
c09425a4  bnez      $s1, 0xc0942574
c09425a8  nop       
c09425ac  lw        $t0, ($s2)
c09425b0  addiu     $a0, $t0, 0x20
c09425b4  b         0xc0942590
c09425b8  nop       
c09425bc  beqz      $s1, 0xc09425dc
c09425c0  nop       
c09425c4  move      $a1, $s3
c09425c8  move      $a0, $s1
c09425cc  jal       0xc09436fc
c09425d0  nop       
c09425d4  b         0xc0942678
c09425d8  nop       
c09425dc  addiu     $s0, $zero, 0xb
c09425e0  b         0xc094267c
c09425e4  nop       
c09425e8  addiu     $t0, $zero, 0x401
c09425ec  beq       $s4, $t0, 0xc0942640
c09425f0  nop       
c09425f4  addiu     $t1, $zero, 0x402
c09425f8  beq       $s4, $t1, 0xc094260c
c09425fc  nop       
c0942600  addiu     $s0, $zero, 8
c0942604  b         0xc094267c
c0942608  nop       
c094260c  move      $a1, $s3
c0942610  beqz      $s1, 0xc094262c
c0942614  nop       
c0942618  move      $a0, $s1
c094261c  jal       0xc0943f40
c0942620  nop       
c0942624  b         0xc0942678
c0942628  nop       
c094262c  lw        $a0, ($s2)
c0942630  jal       0xc0947b1c
c0942634  nop       
c0942638  b         0xc0942678
c094263c  nop       
c0942640  beqz      $s1, 0xc094265c
c0942644  nop       
c0942648  move      $a0, $s1
c094264c  jal       0xc09435f4
c0942650  nop       
c0942654  b         0xc0942664
c0942658  nop       
c094265c  lw        $t0, ($s2)
c0942660  addiu     $v0, $t0, 0x50
c0942664  move      $a2, $s5
c0942668  move      $a1, $s3
c094266c  move      $a0, $v0
c0942670  jal       0xc0943080
c0942674  nop       
c0942678  move      $s0, $v0
c094267c  addiu     $s1, $zero, 1
c0942680  sw        $s0, 0x10($fp)
c0942684  lw        $t3, ($s2)
c0942688  b         0xc09426ac
c094268c  nop       
c0942690  addiu     $s0, $zero, 0xb
c0942694  sw        $s0, 0x10($fp)
c0942698  lui       $t0, 0xc095
c094269c  addiu     $s2, $t0, -0x5ec0
c09426a0  addiu     $s1, $zero, 1
c09426a4  lw        $s6, 0x44($fp)
c09426a8  lw        $t3, ($s2)
c09426ac  addiu     $a0, $t3, 4
c09426b0  jal       0xc0948aa8 ; import thunk COREDLL.dll!LeaveCriticalSection@5
c09426b4  nop       
c09426b8  beqz      $s6, 0xc09426d0
c09426bc  nop       
c09426c0  sw        $s0, ($s6)
c09426c4  b         0xc09426d0
c09426c8  nop       
c09426cc  lw        $s1, 0x14($fp)
c09426d0  move      $v0, $s1
c09426d4  move      $sp, $fp
c09426d8  lw        $fp, 0x18($sp)
c09426dc  lw        $s6, 0x1c($sp)
c09426e0  lw        $s5, 0x20($sp)
c09426e4  lw        $s4, 0x24($sp)
c09426e8  lw        $s3, 0x28($sp)
c09426ec  lw        $s2, 0x2c($sp)
c09426f0  lw        $s1, 0x30($sp)
c09426f4  lw        $s0, 0x34($sp)
c09426f8  lw        $ra, 0x38($sp)
c09426fc  addiu     $sp, $sp, 0x40
c0942700  jr        $ra
c0942704  nop       
c09433d4  addiu     $sp, $sp, -0x18
c09433d8  sw        $ra, 0x14($sp)
c09433dc  sw        $s0, 0x10($sp)
c09433e0  addiu     $t0, $a1, 4
c09433e4  lwl       $t5, 3($t0)
c09433e8  lwr       $t5, ($t0)
c09433ec  addiu     $t6, $zero, 0x3000
c09433f0  lbu       $t0, 1($t5)
c09433f4  lbu       $t2, ($t5)
c09433f8  sll       $t1, $t0, 8
c09433fc  move      $t3, $t1
c0943400  or        $t3, $t2, $t3
c0943404  move      $t4, $t3
c0943408  bne       $t4, $t6, 0xc0943438
c094340c  nop       
c0943410  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0943414  addiu     $a0, $zero, 0x694
c0943418  move      $s0, $v0
c094341c  beqz      $s0, 0xc09435a0
c0943420  nop       
c0943424  jal       0xc09435b8
c0943428  move      $a0, $s0
c094342c  lui       $a0, 0xc094
c0943430  b         0xc0943598
c0943434  addiu     $t0, $a0, 0x1194
c0943438  addiu     $t0, $zero, 0x164
c094343c  bne       $t4, $t0, 0xc094346c
c0943440  nop       
c0943444  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0943448  addiu     $a0, $zero, 0x94
c094344c  move      $s0, $v0
c0943450  beqz      $s0, 0xc09435a0
c0943454  nop       
c0943458  jal       0xc09435b8
c094345c  move      $a0, $s0
c0943460  lui       $a0, 0xc094
c0943464  b         0xc0943598
c0943468  addiu     $t0, $a0, 0x1224
c094346c  lbu       $t0, 0xf($t5)
c0943470  lbu       $t2, 0xe($t5)
c0943474  sll       $t1, $t0, 8
c0943478  move      $t3, $t1
c094347c  or        $t3, $t2, $t3
c0943480  move      $t4, $t3
c0943484  addiu     $t6, $zero, 8
c0943488  bne       $t4, $t6, 0xc0943510
c094348c  nop       
c0943490  lbu       $t0, 3($t5)
c0943494  lbu       $t2, 2($t5)
c0943498  sll       $t1, $t0, 8
c094349c  move      $t4, $t1
c09434a0  or        $t3, $t2, $t4
c09434a4  move      $t6, $t3
c09434a8  addiu     $t7, $zero, 1
c09434ac  bne       $t6, $t7, 0xc09434dc
c09434b0  nop       
c09434b4  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c09434b8  addiu     $a0, $zero, 0x94
c09434bc  move      $s0, $v0
c09434c0  beqz      $s0, 0xc09435a0
c09434c4  nop       
c09434c8  jal       0xc09435b8
c09434cc  move      $a0, $s0
c09434d0  lui       $a0, 0xc094
c09434d4  b         0xc0943598
c09434d8  addiu     $t0, $a0, 0x1268
c09434dc  addiu     $t0, $zero, 2
c09434e0  bne       $t6, $t0, 0xc09435a0
c09434e4  nop       
c09434e8  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c09434ec  addiu     $a0, $zero, 0x94
c09434f0  move      $s0, $v0
c09434f4  beqz      $s0, 0xc09435a0
c09434f8  nop       
c09434fc  jal       0xc09435b8
c0943500  move      $a0, $s0
c0943504  lui       $a0, 0xc094
c0943508  b         0xc0943598
c094350c  addiu     $t0, $a0, 0x12ac
c0943510  addiu     $t0, $zero, 0x10
c0943514  bne       $t4, $t0, 0xc09435a0
c0943518  nop       
c094351c  lbu       $t0, 3($t5)
c0943520  lbu       $t2, 2($t5)
c0943524  sll       $t1, $t0, 8
c0943528  move      $t3, $t1
c094352c  or        $t3, $t2, $t3
c0943530  move      $t4, $t3
c0943534  addiu     $t6, $zero, 1
c0943538  bne       $t4, $t6, 0xc0943568
c094353c  nop       
c0943540  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0943544  addiu     $a0, $zero, 0x94
c0943548  move      $s0, $v0
c094354c  beqz      $s0, 0xc09435a0
c0943550  nop       
c0943554  jal       0xc09435b8
c0943558  move      $a0, $s0
c094355c  lui       $a0, 0xc094
c0943560  b         0xc0943598
c0943564  addiu     $t0, $a0, 0x12f0
c0943568  addiu     $t0, $zero, 2
c094356c  bne       $t4, $t0, 0xc09435a0
c0943570  nop       
c0943574  jal       0xc0949080 ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0943578  addiu     $a0, $zero, 0x94
c094357c  move      $s0, $v0
c0943580  beqz      $s0, 0xc09435a0
c0943584  nop       
c0943588  jal       0xc09435b8
c094358c  move      $a0, $s0
c0943590  lui       $a0, 0xc094
c0943594  addiu     $t0, $a0, 0x1334
c0943598  b         0xc09435a4
c094359c  sw        $t0, ($s0)
c09435a0  move      $s0, $zero
c09435a4  move      $v0, $s0
c09435a8  lw        $s0, 0x10($sp)
c09435ac  lw        $ra, 0x14($sp)
c09435b0  jr        $ra
c09435b4  addiu     $sp, $sp, 0x18
c09435b8  lui       $t0, 0xc094
c09435bc  addiu     $t0, $t0, 0x1508
c09435c0  sw        $t0, ($a0)
c09435c4  jr        $ra
c09435c8  move      $v0, $a0
c09435dc  lw        $t0, 0x38($a0)
c09435e0  bnez      $t0, 0xc09435ec
c09435e4  addiu     $v0, $zero, 1
c09435e8  move      $v0, $zero
c09435ec  jr        $ra
c09435f0  nop       
c09435fc  addiu     $sp, $sp, -0x20
c0943600  sw        $ra, 0x18($sp)
c0943604  move      $t0, $a0
c0943608  sw        $a3, 0x10($sp)
c094360c  move      $a3, $a2
c0943610  lw        $a2, 0x20($t0)
c0943614  lw        $a0, 0x18($t0)
c0943618  lw        $t0, 0x1c($t0)
c094361c  jalr      $t0
c0943620  nop       
c0943624  lw        $ra, 0x18($sp)
c0943628  jr        $ra
c094362c  addiu     $sp, $sp, 0x20
c0943630  addiu     $sp, $sp, -0x20
c0943634  sw        $ra, 0x18($sp)
c0943638  move      $t0, $a0
c094363c  lw        $a2, 0x20($t0)
c0943640  lw        $a0, 0x18($t0)
c0943644  move      $a3, $a1
c0943648  lw        $t0, 0x1c($t0)
c094364c  addiu     $a1, $zero, 0x3bd
c0943650  jalr      $t0
c0943654  sw        $zero, 0x10($sp)
c0943658  lw        $ra, 0x18($sp)
c094365c  jr        $ra
c0943660  addiu     $sp, $sp, 0x20
c0943698  addiu     $sp, $sp, -0x20
c094369c  sw        $ra, 0x18($sp)
c09436a0  move      $t0, $a0
c09436a4  lw        $a2, 0x20($t0)
c09436a8  lw        $a0, 0x18($t0)
c09436ac  lw        $t0, 0x1c($t0)
c09436b0  addiu     $a3, $zero, 0
c09436b4  addiu     $a1, $zero, 0x3bc
c09436b8  jalr      $t0
c09436bc  sw        $zero, 0x10($sp)
c09436c0  lw        $ra, 0x18($sp)
c09436c4  jr        $ra
c09436c8  addiu     $sp, $sp, 0x20
c0943740  addiu     $sp, $sp, -0x20
c0943744  sw        $ra, 0x18($sp)
c0943748  sw        $s1, 0x10($sp)
c094374c  sw        $s0, 0x14($sp)
c0943750  move      $s0, $a0
c0943754  move      $s1, $a1
c0943758  addiu     $t5, $zero, 1
c094375c  addiu     $t0, $a2, 8
c0943760  sw        $t5, 0xc($s0)
c0943764  sw        $s1, 0x50($s0)
c0943768  lwl       $t1, 3($t0)
c094376c  lwr       $t1, ($t0)
c0943770  addiu     $t2, $a2, 0xc
c0943774  sw        $t1, 0x1c($s0)
c0943778  lwl       $t3, 3($t2)
c094377c  lwr       $t3, ($t2)
c0943780  addiu     $t0, $a2, 4
c0943784  sw        $t3, 0x20($s0)
c0943788  lwl       $t4, 3($a2)
c094378c  lwr       $t4, ($a2)
c0943790  sw        $t4, 0x18($s0)
c0943794  sw        $a3, 0x14($s0)
c0943798  sw        $zero, 0x10($s0)
c094379c  sw        $zero, 0x68($s0)
c09437a0  lwl       $a1, 3($t0)
c09437a4  lwr       $a1, ($t0)
c09437a8  lbu       $t0, 1($a1)
c09437ac  lbu       $t2, ($a1)
c09437b0  sll       $t1, $t0, 8
c09437b4  move      $t3, $t1
c09437b8  or        $t3, $t2, $t3
c09437bc  bne       $t3, $t5, 0xc09437d8
c09437c0  nop       
c09437c4  srl       $t0, $zero, 8
c09437c8  sb        $zero, 0x34($s0)
c09437cc  addiu     $a2, $zero, 0x10
c09437d0  b         0xc09437dc
c09437d4  sb        $t0, 0x35($s0)
c09437d8  addiu     $a2, $zero, 0x12
c09437dc  jal       0xc09490d0 ; import thunk COREDLL.dll!memcpy@1044
c09437e0  addiu     $a0, $s0, 0x24
c09437e4  move      $a0, $s1
c09437e8  sw        $zero, 0x38($s0)
c09437ec  sw        $zero, 0x40($s0)
c09437f0  sw        $zero, 0x3c($s0)
c09437f4  sw        $zero, 0x44($s0)
c09437f8  sw        $zero, 0x48($s0)
c09437fc  sw        $zero, 0x4c($s0)
c0943800  sw        $zero, 0x54($s0)
c0943804  jal       0xc0942898
c0943808  sw        $zero, 0x5c($s0)
c094380c  lw        $t0, ($s0)
c0943810  lw        $t0, 0x34($t0)
c0943814  move      $a0, $s0
c0943818  jalr      $t0
c094381c  sw        $v0, 0x58($s0)
c0943820  lw        $a1, ($s0)
c0943824  lw        $t0, 0x20($a1)
c0943828  jalr      $t0
c094382c  move      $a0, $s0
c0943830  lw        $a2, ($s1)
c0943834  lw        $t0, 4($a2)
c0943838  move      $a1, $s0
c094383c  jalr      $t0
c0943840  move      $a0, $s1
c0943844  move      $s1, $v0
c0943848  bnez      $s1, 0xc0943860
c094384c  nop       
c0943850  lw        $t0, ($s0)
c0943854  lw        $t0, 0x28($t0)
c0943858  jalr      $t0
c094385c  move      $a0, $s0
c0943860  move      $v0, $s1
c0943864  lw        $s1, 0x10($sp)
c0943868  lw        $s0, 0x14($sp)
c094386c  lw        $ra, 0x18($sp)
c0943870  jr        $ra
c0943874  addiu     $sp, $sp, 0x20
c0943878  lw        $t0, 0xc($a0)
c094387c  addiu     $v0, $t0, 1
c0943880  jr        $ra
c0943884  sw        $v0, 0xc($a0)
c0943888  addiu     $sp, $sp, -0x20
c094388c  sw        $ra, 0x18($sp)
c0943890  sw        $s1, 0x10($sp)
c0943894  sw        $s0, 0x14($sp)
c0943898  move      $s1, $a0
c094389c  lw        $t0, 0xc($s1)
c09438a0  addiu     $s0, $t0, -1
c09438a4  bnez      $s0, 0xc09438cc
c09438a8  sw        $s0, 0xc($s1)
c09438ac  lw        $a0, 0x50($s1)
c09438b0  jal       0xc0942a80
c09438b4  move      $a1, $s1
c09438b8  lw        $a2, ($s1)
c09438bc  lw        $t0, ($a2)
c09438c0  addiu     $a1, $zero, 1
c09438c4  jalr      $t0
c09438c8  move      $a0, $s1
c09438cc  move      $v0, $s0
c09438d0  lw        $s1, 0x10($sp)
c09438d4  lw        $s0, 0x14($sp)
c09438d8  lw        $ra, 0x18($sp)
c09438dc  jr        $ra
c09438e0  addiu     $sp, $sp, 0x20
c09438e4  addiu     $sp, $sp, -0x18
c09438e8  sw        $ra, 0x10($sp)
c09438ec  move      $t5, $a1
c09438f0  lw        $t1, 0x10($t5)
c09438f4  andi      $t0, $t1, 2
c09438f8  bnez      $t0, 0xc0943908
c09438fc  move      $a1, $a0
c0943900  b         0xc09439a4
c0943904  addiu     $v0, $zero, 0x22
c0943908  lui       $t2, 0xffff
c094390c  sw        $zero, 0x18($t5)
c0943910  ori       $t2, $t2, 0xfffe
c0943914  and       $t1, $t1, $t2
c0943918  ori       $t0, $t1, 0x10
c094391c  sw        $t0, 0x10($t5)
c0943920  sw        $zero, 8($t5)
c0943924  lw        $t2, 0x38($a1)
c0943928  bnez      $t2, 0xc0943938
c094392c  nop       
c0943930  b         0xc0943940
c0943934  sw        $t5, 0x38($a1)
c0943938  lw        $t0, 0x40($a1)
c094393c  sw        $t5, 0x18($t0)
c0943940  lw        $t1, 0x3c($a1)
c0943944  bnez      $t1, 0xc0943980
c0943948  sw        $t5, 0x40($a1)
c094394c  sw        $t5, 0x3c($a1)
c0943950  lw        $t0, ($t5)
c0943954  sw        $t0, 0x44($a1)
c0943958  lw        $t3, 4($t5)
c094395c  lw        $t2, ($t5)
c0943960  addu      $t3, $t3, $t2
c0943964  sw        $t3, 0x48($a1)
c0943968  lw        $t1, 0x10($t5)
c094396c  andi      $t4, $t1, 4
c0943970  beqz      $t4, 0xc0943980
c0943974  nop       
c0943978  lw        $t0, 0x14($t5)
c094397c  sw        $t0, 0x54($a1)
c0943980  lw        $t2, 0x10($a1)
c0943984  beqz      $t2, 0xc09439a0
c0943988  nop       
c094398c  lw        $a0, 0x50($a1)
c0943990  lw        $t0, ($a0)
c0943994  lw        $t0, 0x10($t0)
c0943998  jalr      $t0
c094399c  nop       
c09439a0  move      $v0, $zero
c09439a4  lw        $ra, 0x10($sp)
c09439a8  jr        $ra
c09439ac  addiu     $sp, $sp, 0x18
c09439b0  addiu     $sp, $sp, -0x18
c09439b4  sw        $ra, 0x14($sp)
c09439b8  sw        $s0, 0x10($sp)
c09439bc  move      $s0, $a0
c09439c0  lw        $a1, 0x3c($s0)
c09439c4  bnez      $a1, 0xc09439d4
c09439c8  nop       
c09439cc  b         0xc0943aa8
c09439d0  move      $v0, $zero
c09439d4  lw        $t3, 0x54($s0)
c09439d8  sltiu     $t0, $t3, 2
c09439dc  bnez      $t0, 0xc0943a20
c09439e0  nop       
c09439e4  lw        $t1, 0x10($a1)
c09439e8  andi      $t2, $t1, 8
c09439ec  beqz      $t2, 0xc0943a14
c09439f0  nop       
c09439f4  lui       $t4, 0xffff
c09439f8  ori       $t4, $t4, 0xffff
c09439fc  beq       $t3, $t4, 0xc0943a0c
c0943a00  nop       
c0943a04  addiu     $t0, $t3, -1
c0943a08  sw        $t0, 0x54($s0)
c0943a0c  b         0xc0943a18
c0943a10  lw        $t3, 0x38($s0)
c0943a14  lw        $t3, 0x18($a1)
c0943a18  b         0xc0943a4c
c0943a1c  move      $a1, $zero
c0943a20  lw        $t3, 0x18($a1)
c0943a24  bnez      $t3, 0xc0943a34
c0943a28  sw        $t3, 0x38($s0)
c0943a2c  b         0xc0943a4c
c0943a30  sw        $zero, 0x40($s0)
c0943a34  lw        $t0, 0x10($t3)
c0943a38  andi      $t1, $t0, 4
c0943a3c  beqz      $t1, 0xc0943a4c
c0943a40  nop       
c0943a44  lw        $t2, 0x14($t3)
c0943a48  sw        $t2, 0x54($s0)
c0943a4c  beqz      $t3, 0xc0943a6c
c0943a50  sw        $t3, 0x3c($s0)
c0943a54  lw        $t1, ($t3)
c0943a58  sw        $t1, 0x44($s0)
c0943a5c  lw        $t0, 4($t3)
c0943a60  addu      $t1, $t0, $t1
c0943a64  b         0xc0943a74
c0943a68  sw        $t1, 0x48($s0)
c0943a6c  sw        $zero, 0x44($s0)
c0943a70  sw        $zero, 0x48($s0)
c0943a74  beqz      $a1, 0xc0943aa4
c0943a78  nop       
c0943a7c  lui       $t1, 0xffff
c0943a80  lw        $t0, 0x10($a1)
c0943a84  ori       $t1, $t1, 0xffef
c0943a88  and       $t0, $t0, $t1
c0943a8c  ori       $t1, $t0, 1
c0943a90  sw        $t1, 0x10($a1)
c0943a94  lw        $t2, ($s0)
c0943a98  lw        $t2, 0x24($t2)
c0943a9c  jalr      $t2
c0943aa0  move      $a0, $s0
c0943aa4  lw        $v0, 0x44($s0)
c0943aa8  lw        $s0, 0x10($sp)
c0943aac  lw        $ra, 0x14($sp)
c0943ab0  jr        $ra
c0943ab4  addiu     $sp, $sp, 0x18
c0943d40  addiu     $sp, $sp, -0x20
c0943d44  sw        $ra, 0x18($sp)
c0943d48  sw        $s1, 0x10($sp)
c0943d4c  sw        $s0, 0x14($sp)
c0943d50  addiu     $t0, $a2, 4
c0943d54  lwl       $t6, 3($t0)
c0943d58  lwr       $t6, ($t0)
c0943d5c  move      $s0, $a0
c0943d60  lbu       $t0, 0xf($t6)
c0943d64  lbu       $t2, 0xe($t6)
c0943d68  sll       $t1, $t0, 8
c0943d6c  lbu       $t0, 3($t6)
c0943d70  move      $t3, $t1
c0943d74  or        $t4, $t2, $t3
c0943d78  sll       $t1, $t0, 8
c0943d7c  lbu       $t2, 2($t6)
c0943d80  addiu     $t5, $zero, 2
c0943d84  addiu     $t7, $zero, 8
c0943d88  addiu     $t6, $zero, 1
c0943d8c  bne       $t4, $t7, 0xc0943db4
c0943d90  move      $t3, $t1
c0943d94  or        $t4, $t2, $t3
c0943d98  bne       $t4, $t6, 0xc0943dac
c0943d9c  nop       
c0943da0  sw        $zero, 0x6c($s0)
c0943da4  b         0xc0943ddc
c0943da8  sw        $t6, 0x70($s0)
c0943dac  b         0xc0943dc4
c0943db0  sw        $t5, 0x6c($s0)
c0943db4  or        $t4, $t2, $t3
c0943db8  bne       $t4, $t6, 0xc0943dcc
c0943dbc  nop       
c0943dc0  sw        $t6, 0x6c($s0)
c0943dc4  b         0xc0943ddc
c0943dc8  sw        $t5, 0x70($s0)
c0943dcc  addiu     $t0, $zero, 3
c0943dd0  addiu     $t1, $zero, 4
c0943dd4  sw        $t0, 0x6c($s0)
c0943dd8  sw        $t1, 0x70($s0)
c0943ddc  addiu     $t0, $s0, 0x80
c0943de0  sw        $zero, -8($t0)
c0943de4  sw        $zero, ($t0)
c0943de8  addiu     $t5, $t5, -1
c0943dec  bnez      $t5, 0xc0943de0
c0943df0  addiu     $t0, $t0, 4
c0943df4  jal       0xc0943740
c0943df8  move      $a0, $s0
c0943dfc  move      $s1, $v0
c0943e00  bnez      $s1, 0xc0943e1c
c0943e04  nop       
c0943e08  lw        $t0, ($s0)
c0943e0c  lw        $t0, 0x3c($t0)
c0943e10  lui       $a1, 1
c0943e14  jalr      $t0
c0943e18  move      $a0, $s0
c0943e1c  move      $v0, $s1
c0943e20  lw        $s1, 0x10($sp)
c0943e24  lw        $s0, 0x14($sp)
c0943e28  lw        $ra, 0x18($sp)
c0943e2c  jr        $ra
c0943e30  addiu     $sp, $sp, 0x20
c0943e44  addiu     $sp, $sp, -0x18
c0943e48  sw        $ra, 0x10($sp)
c0943e4c  move      $a1, $a0
c0943e50  addiu     $t0, $zero, 1
c0943e54  sw        $t0, 0x10($a1)
c0943e58  lw        $t0, 0x44($a1)
c0943e5c  beqz      $t0, 0xc0943e78
c0943e60  nop       
c0943e64  lw        $a0, 0x50($a1)
c0943e68  lw        $t1, ($a0)
c0943e6c  lw        $t1, 0x10($t1)
c0943e70  jalr      $t1
c0943e74  nop       
c0943e78  lw        $ra, 0x10($sp)
c0943e7c  addiu     $v0, $zero, 0
c0943e80  jr        $ra
c0943e84  addiu     $sp, $sp, 0x18
c0943e88  sw        $zero, 0x10($a0)
c0943e8c  jr        $ra
c0943e90  addiu     $v0, $zero, 0
c0943e94  addiu     $sp, $sp, -0x18
c0943e98  sw        $ra, 0x14($sp)
c0943e9c  sw        $s0, 0x10($sp)
c0943ea0  move      $s0, $a0
c0943ea4  lw        $t0, 0xc($s0)
c0943ea8  lw        $t2, ($s0)
c0943eac  addiu     $t1, $t0, 1
c0943eb0  lw        $t2, 0x14($t2)
c0943eb4  move      $a0, $s0
c0943eb8  jalr      $t2
c0943ebc  sw        $t1, 0xc($s0)
c0943ec0  lw        $t0, 0x38($s0)
c0943ec4  sw        $zero, 0x3c($s0)
c0943ec8  sw        $zero, 0x44($s0)
c0943ecc  sw        $zero, 0x48($s0)
c0943ed0  sw        $zero, 0x4c($s0)
c0943ed4  beqz      $t0, 0xc0943f24
c0943ed8  sw        $zero, 0x54($s0)
c0943edc  lw        $a1, 0x38($s0)
c0943ee0  lw        $t1, 0x18($a1)
c0943ee4  bnez      $t1, 0xc0943ef0
c0943ee8  sw        $t1, 0x38($s0)
c0943eec  sw        $zero, 0x40($s0)
c0943ef0  lui       $t2, 0xffff
c0943ef4  lw        $t0, 0x10($a1)
c0943ef8  ori       $t2, $t2, 0xffef
c0943efc  and       $t0, $t0, $t2
c0943f00  ori       $t1, $t0, 1
c0943f04  sw        $t1, 0x10($a1)
c0943f08  lw        $t2, ($s0)
c0943f0c  lw        $t2, 0x24($t2)
c0943f10  jalr      $t2
c0943f14  move      $a0, $s0
c0943f18  lw        $a0, 0x38($s0)
c0943f1c  bnez      $a0, 0xc0943edc
c0943f20  nop       
c0943f24  jal       0xc0943888
c0943f28  move      $a0, $s0
c0943f2c  lw        $s0, 0x10($sp)
c0943f30  lw        $ra, 0x14($sp)
c0943f34  addiu     $v0, $zero, 0
c0943f38  jr        $ra
c0943f3c  addiu     $sp, $sp, 0x18
c0943ff0  addiu     $sp, $sp, -0x38
c0943ff4  sw        $ra, 0x34($sp)
c0943ff8  sw        $fp, 0x20($sp)
c0943ffc  sw        $s3, 0x24($sp)
c0944000  sw        $s2, 0x28($sp)
c0944004  sw        $s1, 0x2c($sp)
c0944008  sw        $s0, 0x30($sp)
c094400c  move      $fp, $sp
c0944010  move      $s3, $a3
c0944014  sw        $s3, 0x44($fp)
c0944018  move      $s2, $a2
c094401c  sw        $s2, 0x40($fp)
c0944020  move      $s0, $a1
c0944024  sw        $s0, 0x3c($fp)
c0944028  move      $s1, $a0
c094402c  sw        $s1, 0x38($fp)
c0944030  lw        $t0, 0x10($s1)
c0944034  beqz      $t0, 0xc0944104
c0944038  nop       
c094403c  lw        $t1, 0x44($s1)
c0944040  beqz      $t1, 0xc0944104
c0944044  nop       
c0944048  sltu      $t2, $s0, $s2
c094404c  beqz      $t2, 0xc0944104
c0944050  nop       
c0944054  lw        $t3, 0x44($s1)
c0944058  lw        $t0, 0x48($s1)
c094405c  sltu      $t1, $t3, $t0
c0944060  bnez      $t1, 0xc0944090
c0944064  nop       
c0944068  move      $a0, $s1
c094406c  jal       0xc09439b0
c0944070  nop       
c0944074  beqz      $v0, 0xc0944104
c0944078  nop       
c094407c  lw        $t1, 0x44($s1)
c0944080  lw        $t0, 0x48($s1)
c0944084  sltu      $t1, $t1, $t0
c0944088  beqz      $t1, 0xc0944068
c094408c  nop       
c0944090  lw        $t1, ($s1)
c0944094  lw        $t0, 0x48($fp)
c0944098  sw        $t0, 0x10($sp)
c094409c  move      $a3, $s3
c09440a0  move      $a2, $s2
c09440a4  move      $a1, $s0
c09440a8  move      $a0, $s1
c09440ac  lw        $t1, 0x40($t1)
c09440b0  jalr      $t1
c09440b4  nop       
c09440b8  move      $s0, $v0
c09440bc  sw        $s0, 0x3c($fp)
c09440c0  b         0xc0944048
c09440c4  nop       
c09440c8  lw        $s1, 0x38($fp)
c09440cc  lw        $a2, 0x44($s1)
c09440d0  move      $a1, $s1
c09440d4  lui       $t0, 0xc094
c09440d8  addiu     $a0, $t0, 0x1544
c09440dc  jal       0xc0948ab8 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c09440e0  nop       
c09440e4  lw        $a0, 0x48($s1)
c09440e8  sw        $a0, 0x44($s1)
c09440ec  lw        $s3, 0x44($fp)
c09440f0  lw        $s2, 0x40($fp)
c09440f4  lw        $s0, 0x3c($fp)
c09440f8  b         0xc0944048
c09440fc  nop       
c0944100  lw        $s0, 0x18($fp)
c0944104  move      $v0, $s0
c0944108  move      $sp, $fp
c094410c  lw        $fp, 0x20($sp)
c0944110  lw        $s3, 0x24($sp)
c0944114  lw        $s2, 0x28($sp)
c0944118  lw        $s1, 0x2c($sp)
c094411c  lw        $s0, 0x30($sp)
c0944120  lw        $ra, 0x34($sp)
c0944124  addiu     $sp, $sp, 0x38
c0944128  jr        $ra
c094412c  nop       
c0944234  addiu     $sp, $sp, -0x18
c0944238  sw        $ra, 0x14($sp)
c094423c  sw        $s0, 0x10($sp)
c0944240  move      $s0, $a0
c0944244  lw        $t0, 0x38($s0)
c0944248  beqz      $t0, 0xc0944258
c094424c  nop       
c0944250  b         0xc094428c
c0944254  addiu     $v0, $zero, 0x21
c0944258  lw        $t1, 0x68($s0)
c094425c  beqz      $t1, 0xc0944278
c0944260  nop       
c0944264  lui       $t0, 0xc095
c0944268  sw        $zero, 0x68($s0)
c094426c  lw        $a0, -0x5ec0($t0)
c0944270  jal       0xc0947b1c
c0944274  addiu     $a1, $zero, 0
c0944278  lw        $t0, ($s0)
c094427c  lw        $t0, 0x2c($t0)
c0944280  jalr      $t0
c0944284  move      $a0, $s0
c0944288  move      $v0, $zero
c094428c  lw        $s0, 0x10($sp)
c0944290  lw        $ra, 0x14($sp)
c0944294  jr        $ra
c0944298  addiu     $sp, $sp, 0x18
c094457c  addiu     $sp, $sp, -0x20
c0944580  sw        $ra, 0x18($sp)
c0944584  sw        $s1, 0x10($sp)
c0944588  sw        $s0, 0x14($sp)
c094458c  move      $s0, $a0
c0944590  jal       0xc0943d40
c0944594  move      $a0, $s0
c0944598  lw        $a0, 0x50($s0)
c094459c  jal       0xc0942e7c
c09445a0  move      $s1, $v0
c09445a4  negu      $a1, $v0
c09445a8  bnez      $s1, 0xc09445c0
c09445ac  sw        $a1, 0x88($s0)
c09445b0  lw        $t0, ($s0)
c09445b4  lw        $t0, 0x10($t0)
c09445b8  jalr      $t0
c09445bc  move      $a0, $s0
c09445c0  move      $v0, $s1
c09445c4  lw        $s1, 0x10($sp)
c09445c8  lw        $s0, 0x14($sp)
c09445cc  lw        $ra, 0x18($sp)
c09445d0  jr        $ra
c09445d4  addiu     $sp, $sp, 0x20
c09445d8  addiu     $sp, $sp, -0x20
c09445dc  sw        $ra, 0x18($sp)
c09445e0  sw        $s1, 0x10($sp)
c09445e4  sw        $s0, 0x14($sp)
c09445e8  move      $s1, $a0
c09445ec  jal       0xc0943e94
c09445f0  move      $a0, $s1
c09445f4  move      $s0, $v0
c09445f8  bnez      $s0, 0xc0944610
c09445fc  nop       
c0944600  lw        $t0, ($s1)
c0944604  lw        $t0, 0x10($t0)
c0944608  jalr      $t0
c094460c  move      $a0, $s1
c0944610  move      $v0, $s0
c0944614  lw        $s1, 0x10($sp)
c0944618  lw        $s0, 0x14($sp)
c094461c  lw        $ra, 0x18($sp)
c0944620  jr        $ra
c0944624  addiu     $sp, $sp, 0x20
c0944be4  addiu     $sp, $sp, -0x38
c0944be8  sw        $ra, 0x34($sp)
c0944bec  sw        $fp, 0x10($sp)
c0944bf0  sw        $s7, 0x14($sp)
c0944bf4  sw        $s6, 0x18($sp)
c0944bf8  sw        $s5, 0x1c($sp)
c0944bfc  sw        $s4, 0x20($sp)
c0944c00  sw        $s3, 0x24($sp)
c0944c04  sw        $s2, 0x28($sp)
c0944c08  sw        $s1, 0x2c($sp)
c0944c0c  sw        $s0, 0x30($sp)
c0944c10  move      $s0, $a0
c0944c14  lw        $a0, 0x50($s0)
c0944c18  lw        $s2, 0x88($s0)
c0944c1c  lw        $s6, 0x8c($s0)
c0944c20  move      $s5, $a3
c0944c24  move      $s3, $a2
c0944c28  jal       0xc0942e7c
c0944c2c  move      $s1, $a1
c0944c30  lw        $a0, 0x50($s0)
c0944c34  jal       0xc0942e84
c0944c38  move      $s4, $v0
c0944c3c  lw        $t0, 0x48($sp)
c0944c40  move      $s7, $v0
c0944c44  lw        $t9, 0x80($s0)
c0944c48  lw        $v1, 0x84($s0)
c0944c4c  lw        $a1, 0x78($s0)
c0944c50  lw        $a0, 0x7c($s0)
c0944c54  lw        $t8, 0x44($s0)
c0944c58  lw        $t1, 4($t0)
c0944c5c  beqz      $t1, 0xc0944c70
c0944c60  lw        $v0, 0x48($s0)
c0944c64  move      $a3, $zero
c0944c68  b         0xc0944c78
c0944c6c  move      $a2, $zero
c0944c70  lw        $a3, 0x60($s0)
c0944c74  lw        $a2, 0x64($s0)
c0944c78  sltu      $t0, $s1, $s3
c0944c7c  beqz      $t0, 0xc0944d94
c0944c80  nop       
c0944c84  addiu     $fp, $zero, -0x8000
c0944c88  bgez      $s2, 0xc0944cc0
c0944c8c  nop       
c0944c90  sltu      $t0, $t8, $v0
c0944c94  beqz      $t0, 0xc0944d94
c0944c98  nop       
c0944c9c  lh        $t1, ($t8)
c0944ca0  lh        $t2, 2($t8)
c0944ca4  move      $a1, $t9
c0944ca8  move      $a0, $v1
c0944cac  addu      $s2, $s4, $s2
c0944cb0  move      $t9, $t1
c0944cb4  move      $v1, $t2
c0944cb8  bltz      $s2, 0xc0944c90
c0944cbc  addiu     $t8, $t8, 4
c0944cc0  multu     $s7, $s2
c0944cc4  subu      $t1, $a1, $t9
c0944cc8  subu      $s2, $s2, $s6
c0944ccc  mflo      $t0
c0944cd0  srl       $t5, $t0, 0x11
c0944cd4  nop       
c0944cd8  mult      $t1, $t5
c0944cdc  subu      $t1, $a0, $v1
c0944ce0  mflo      $t2
c0944ce4  sra       $t3, $t2, 0xf
c0944ce8  addu      $t0, $t3, $t9
c0944cec  mult      $t0, $a3
c0944cf0  mflo      $t4
c0944cf4  nop       
c0944cf8  nop       
c0944cfc  mult      $t1, $t5
c0944d00  sra       $t7, $t4, 0x10
c0944d04  sltu      $t1, $s1, $s5
c0944d08  mflo      $t2
c0944d0c  sra       $t3, $t2, 0xf
c0944d10  addu      $t0, $t3, $v1
c0944d14  mult      $t0, $a2
c0944d18  mflo      $t4
c0944d1c  beqz      $t1, 0xc0944d7c
c0944d20  sra       $t6, $t4, 0x10
c0944d24  lh        $t2, ($s1)
c0944d28  lh        $t0, 2($s1)
c0944d2c  addu      $t7, $t2, $t7
c0944d30  ori       $t2, $zero, 0x8000
c0944d34  slt       $t3, $t7, $t2
c0944d38  bnez      $t3, 0xc0944d48
c0944d3c  addu      $t6, $t0, $t6
c0944d40  b         0xc0944d58
c0944d44  addiu     $t7, $zero, 0x7fff
c0944d48  slti      $t0, $t7, -0x8000
c0944d4c  beqz      $t0, 0xc0944d58
c0944d50  nop       
c0944d54  move      $t7, $fp
c0944d58  slt       $t1, $t6, $t2
c0944d5c  bnez      $t1, 0xc0944d6c
c0944d60  nop       
c0944d64  b         0xc0944d7c
c0944d68  addiu     $t6, $zero, 0x7fff
c0944d6c  slti      $t0, $t6, -0x8000
c0944d70  beqz      $t0, 0xc0944d7c
c0944d74  nop       
c0944d78  move      $t6, $fp
c0944d7c  sh        $t7, ($s1)
c0944d80  sh        $t6, 2($s1)
c0944d84  addiu     $s1, $s1, 4
c0944d88  sltu      $t0, $s1, $s3
c0944d8c  bnez      $t0, 0xc0944c88
c0944d90  nop       
c0944d94  lw        $t2, 0x4c($s0)
c0944d98  lw        $t1, 0x44($s0)
c0944d9c  sw        $s2, 0x88($s0)
c0944da0  subu      $t2, $t2, $t1
c0944da4  addu      $t0, $t2, $t8
c0944da8  move      $v0, $s1
c0944dac  sw        $t0, 0x4c($s0)
c0944db0  sw        $t8, 0x44($s0)
c0944db4  sw        $a1, 0x78($s0)
c0944db8  sw        $a0, 0x7c($s0)
c0944dbc  sw        $t9, 0x80($s0)
c0944dc0  sw        $v1, 0x84($s0)
c0944dc4  lw        $fp, 0x10($sp)
c0944dc8  lw        $s7, 0x14($sp)
c0944dcc  lw        $s6, 0x18($sp)
c0944dd0  lw        $s5, 0x1c($sp)
c0944dd4  lw        $s4, 0x20($sp)
c0944dd8  lw        $s3, 0x24($sp)
c0944ddc  lw        $s2, 0x28($sp)
c0944de0  lw        $s1, 0x2c($sp)
c0944de4  lw        $s0, 0x30($sp)
c0944de8  lw        $ra, 0x34($sp)
c0944dec  jr        $ra
c0944df0  addiu     $sp, $sp, 0x38
; wavedev2_i2s2.dll eb9b1d5625e0be967f139a4fe1d3e67799bd71d0af1e5bdf7c55b6d1f347a009
c0952198  addiu     $sp, $sp, -0x40
c095219c  sw        $ra, 0x38($sp)
c09521a0  sw        $fp, 0x18($sp)
c09521a4  sw        $s6, 0x1c($sp)
c09521a8  sw        $s5, 0x20($sp)
c09521ac  sw        $s4, 0x24($sp)
c09521b0  sw        $s3, 0x28($sp)
c09521b4  sw        $s2, 0x2c($sp)
c09521b8  sw        $s1, 0x30($sp)
c09521bc  sw        $s0, 0x34($sp)
c09521c0  move      $fp, $sp
c09521c4  move      $s6, $a1
c09521c8  sw        $s6, 0x44($fp)
c09521cc  move      $s0, $a0
c09521d0  addiu     $a0, $zero, 0
c09521d4  lui       $t0, 0xc096
c09521d8  lw        $t0, -0x5f74($t0) ; IAT COREDLL.dll!SetLastError@517
c09521dc  jalr      $t0 ; call candidate COREDLL.dll!SetLastError@517
c09521e0  nop       
c09521e4  lw        $s4, 4($s0)
c09521e8  lw        $s3, 0xc($s0)
c09521ec  lw        $s5, 0x10($s0)
c09521f0  lw        $s1, 8($s0)
c09521f4  lui       $t0, 0xc096
c09521f8  addiu     $s2, $t0, -0x5ec4
c09521fc  lw        $t0, ($s2)
c0952200  addiu     $a0, $t0, 4
c0952204  jal       0xc0958834 ; import thunk COREDLL.dll!EnterCriticalSection@4
c0952208  nop       
c095220c  sltiu     $t0, $s4, 0x401
c0952210  beqz      $t0, 0xc0952648
c0952214  nop       
c0952218  addiu     $t1, $zero, 0x400
c095221c  beq       $s4, $t1, 0xc095261c
c0952220  nop       
c0952224  addiu     $t3, $s4, -3
c0952228  sltiu     $t1, $t3, 0x3c
c095222c  beqz      $t1, 0xc0952660
c0952230  nop       
c0952234  lui       $t2, 0xc095
c0952238  addiu     $t2, $t2, 0x2254
c095223c  sll       $t0, $t3, 1
c0952240  addu      $t0, $t0, $t2
c0952244  lh        $t0, ($t0)
c0952248  addu      $t2, $t2, $t0
c095224c  jr        $t2
c0952250  nop       
c0952254  .byte     0x78, 0x00, 0x88, 0x00
c0952258  .byte     0x1c, 0x01, 0x50, 0x01
c095225c  teqi      $zero, 0x40c
c0952260  .byte     0x6c, 0x02, 0x2c, 0x02
c0952264  .byte     0x10, 0x02, 0x5c, 0x02
c0952268  teqi      $zero, 0x23c
c095226c  syscall   0x9f010
c0952270  tge       $t8, $t0, 0xa
c0952274  .byte     0xf8, 0x02, 0xe4, 0x02
c0952278  syscall   0x3a010
c095227c  .byte     0x20, 0x03, 0x74, 0x03
c0952280  teqi      $zero, 0x40c
c0952284  teqi      $zero, 0x40c
c0952288  teqi      $zero, 0x40c
c095228c  teqi      $zero, 0x40c
c0952290  teqi      $zero, 0x40c
c0952294  teqi      $zero, 0x40c
c0952298  teqi      $zero, 0x40c
c095229c  teqi      $zero, 0x40c
c09522a0  teqi      $zero, 0x40c
c09522a4  teqi      $zero, 0x40c
c09522a8  teqi      $zero, 0x40c
c09522ac  teqi      $zero, 0x40c
c09522b0  syscall   0x1e010
c09522b4  .byte     0xd0, 0x00, 0x40, 0x01
c09522b8  teqi      $zero, 0x150
c09522bc  syscall   0x9b010
c09522c0  .byte     0x10, 0x02, 0x2c, 0x02
c09522c4  .byte     0x5c, 0x02, 0x3c, 0x02
c09522c8  .byte     0x58, 0x03, 0xac, 0x03
c09522cc  addiu     $s1, $zero, 1
c09522d0  move      $s0, $s1
c09522d4  b         0xc09526e0
c09522d8  nop       
c09522dc  beqz      $s1, 0xc09522f8
c09522e0  nop       
c09522e4  move      $a0, $s1
c09522e8  jal       0xc0953700
c09522ec  nop       
c09522f0  b         0xc0952300
c09522f4  nop       
c09522f8  lw        $t0, ($s2)
c09522fc  addiu     $v0, $t0, 0x50
c0952300  lw        $t1, ($v0)
c0952304  lw        $t0, 0xc($t1)
c0952308  move      $a0, $v0
c095230c  move      $a1, $s3
c0952310  move      $a2, $s5
c0952314  jalr      $t0
c0952318  nop       
c095231c  b         0xc09526d8
c0952320  nop       
c0952324  bnez      $s1, 0xc09522e4
c0952328  nop       
c095232c  lw        $t0, ($s2)
c0952330  addiu     $v0, $t0, 0x20
c0952334  b         0xc0952300
c0952338  nop       
c095233c  beqz      $s1, 0xc0952358
c0952340  nop       
c0952344  move      $a0, $s1
c0952348  jal       0xc0953700
c095234c  nop       
c0952350  b         0xc0952360
c0952354  nop       
c0952358  lw        $t0, ($s2)
c095235c  addiu     $v0, $t0, 0x50
c0952360  lw        $t1, ($v0)
c0952364  lw        $t0, 8($t1)
c0952368  b         0xc0952308
c095236c  nop       
c0952370  lw        $t0, ($s2)
c0952374  addiu     $a0, $t0, 0x50
c0952378  move      $a3, $s1
c095237c  move      $a2, $s5
c0952380  move      $a1, $s3
c0952384  jal       0xc0952d70
c0952388  nop       
c095238c  b         0xc09526d8
c0952390  nop       
c0952394  lw        $t0, ($s2)
c0952398  addiu     $a0, $t0, 0x20
c095239c  b         0xc0952378
c09523a0  nop       
c09523a4  lui       $t0, 0xc095
c09523a8  addiu     $a0, $t0, 0x1084
c09523ac  jal       0xc0958854 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c09523b0  nop       
c09523b4  lw        $a1, ($s1)
c09523b8  move      $a0, $s1
c09523bc  lw        $t0, 8($a1)
c09523c0  jalr      $t0
c09523c4  nop       
c09523c8  move      $s0, $v0
c09523cc  sw        $s0, 0x10($fp)
c09523d0  bnez      $s0, 0xc09523e4
c09523d4  nop       
c09523d8  move      $a0, $s1
c09523dc  jal       0xc0953994
c09523e0  nop       
c09523e4  lw        $t3, ($s2)
c09523e8  addiu     $t0, $t3, 0x50
c09523ec  addiu     $t1, $t0, 4
c09523f0  lw        $t0, ($t1)
c09523f4  bne       $t0, $t1, 0xc095241c
c09523f8  nop       
c09523fc  move      $a0, $t3
c0952400  jal       0xc0957868
c0952404  nop       
c0952408  lui       $a0, 0xc095
c095240c  addiu     $a0, $a0, 0x1060
c0952410  jal       0xc0958854 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0952414  nop       
c0952418  lw        $t3, ($s2)
c095241c  addiu     $t0, $t3, 0x20
c0952420  addiu     $t1, $t0, 4
c0952424  lw        $t0, ($t1)
c0952428  bne       $t0, $t1, 0xc0952458
c095242c  nop       
c0952430  move      $a0, $t3
c0952434  jal       0xc09578d8
c0952438  nop       
c095243c  lui       $a0, 0xc095
c0952440  addiu     $a0, $a0, 0x103c
c0952444  jal       0xc0958854 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c0952448  nop       
c095244c  addiu     $s1, $zero, 1
c0952450  b         0xc09526e4
c0952454  nop       
c0952458  addiu     $s1, $zero, 1
c095245c  b         0xc09526e8
c0952460  nop       
c0952464  lw        $t0, ($s1)
c0952468  lw        $t0, 0x10($t0)
c095246c  move      $a0, $s1
c0952470  jalr      $t0
c0952474  nop       
c0952478  b         0xc09526d8
c095247c  nop       
c0952480  lw        $t0, ($s1)
c0952484  lw        $t0, 0x14($t0)
c0952488  b         0xc095246c
c095248c  nop       
c0952490  lw        $t0, ($s1)
c0952494  lw        $t0, 0xc($t0)
c0952498  move      $a1, $s3
c095249c  move      $a0, $s1
c09524a0  jalr      $t0
c09524a4  nop       
c09524a8  b         0xc09526d8
c09524ac  nop       
c09524b0  lw        $t0, ($s1)
c09524b4  lw        $t0, 0x18($t0)
c09524b8  b         0xc095246c
c09524bc  nop       
c09524c0  lw        $t0, ($s1)
c09524c4  lw        $t0, 0x30($t0)
c09524c8  b         0xc0952498
c09524cc  nop       
c09524d0  beqz      $s1, 0xc09524ec
c09524d4  nop       
c09524d8  move      $a0, $s1
c09524dc  jal       0xc09537d8
c09524e0  nop       
c09524e4  b         0xc09524f4
c09524e8  nop       
c09524ec  jal       0xc09574dc
c09524f0  nop       
c09524f4  sw        $v0, ($s3)
c09524f8  move      $s0, $zero
c09524fc  b         0xc09526dc
c0952500  nop       
c0952504  beqz      $s1, 0xc0952524
c0952508  nop       
c095250c  move      $a1, $s3
c0952510  move      $a0, $s1
c0952514  jal       0xc09537e0
c0952518  nop       
c095251c  b         0xc09526d8
c0952520  nop       
c0952524  move      $a0, $s3
c0952528  jal       0xc095748c
c095252c  nop       
c0952530  b         0xc09526d8
c0952534  nop       
c0952538  move      $a0, $s1
c095253c  jal       0xc0953bc4
c0952540  nop       
c0952544  b         0xc09526d8
c0952548  nop       
c095254c  lw        $t0, ($s1)
c0952550  lw        $t0, 0x3c($t0)
c0952554  b         0xc0952498
c0952558  nop       
c095255c  move      $a1, $s3
c0952560  move      $a0, $s1
c0952564  jal       0xc0953f40
c0952568  nop       
c095256c  b         0xc09526d8
c0952570  nop       
c0952574  move      $a1, $s3
c0952578  beqz      $s1, 0xc0952594
c095257c  nop       
c0952580  move      $a0, $s1
c0952584  jal       0xc0954268
c0952588  nop       
c095258c  b         0xc09526d8
c0952590  nop       
c0952594  lw        $t0, ($s2)
c0952598  addiu     $a0, $t0, 0x50
c095259c  jal       0xc0953090
c09525a0  nop       
c09525a4  b         0xc09526d8
c09525a8  nop       
c09525ac  move      $a1, $s3
c09525b0  bnez      $s1, 0xc0952580
c09525b4  nop       
c09525b8  lw        $t0, ($s2)
c09525bc  addiu     $a0, $t0, 0x20
c09525c0  b         0xc095259c
c09525c4  nop       
c09525c8  move      $a1, $s3
c09525cc  beqz      $s1, 0xc09525e8
c09525d0  nop       
c09525d4  move      $a0, $s1
c09525d8  jal       0xc0954284
c09525dc  nop       
c09525e0  b         0xc09526d8
c09525e4  nop       
c09525e8  lw        $t0, ($s2)
c09525ec  addiu     $a0, $t0, 0x50
c09525f0  jal       0xc0952d68
c09525f4  nop       
c09525f8  b         0xc09526d8
c09525fc  nop       
c0952600  move      $a1, $s3
c0952604  bnez      $s1, 0xc09525d4
c0952608  nop       
c095260c  lw        $t0, ($s2)
c0952610  addiu     $a0, $t0, 0x20
c0952614  b         0xc09525f0
c0952618  nop       
c095261c  beqz      $s1, 0xc095263c
c0952620  nop       
c0952624  move      $a1, $s3
c0952628  move      $a0, $s1
c095262c  jal       0xc0953808
c0952630  nop       
c0952634  b         0xc09526d8
c0952638  nop       
c095263c  addiu     $s0, $zero, 0xb
c0952640  b         0xc09526dc
c0952644  nop       
c0952648  addiu     $t0, $zero, 0x401
c095264c  beq       $s4, $t0, 0xc09526a0
c0952650  nop       
c0952654  addiu     $t1, $zero, 0x402
c0952658  beq       $s4, $t1, 0xc095266c
c095265c  nop       
c0952660  addiu     $s0, $zero, 8
c0952664  b         0xc09526dc
c0952668  nop       
c095266c  move      $a1, $s3
c0952670  beqz      $s1, 0xc095268c
c0952674  nop       
c0952678  move      $a0, $s1
c095267c  jal       0xc095404c
c0952680  nop       
c0952684  b         0xc09526d8
c0952688  nop       
c095268c  lw        $a0, ($s2)
c0952690  jal       0xc0957c18
c0952694  nop       
c0952698  b         0xc09526d8
c095269c  nop       
c09526a0  beqz      $s1, 0xc09526bc
c09526a4  nop       
c09526a8  move      $a0, $s1
c09526ac  jal       0xc0953700
c09526b0  nop       
c09526b4  b         0xc09526c4
c09526b8  nop       
c09526bc  lw        $t0, ($s2)
c09526c0  addiu     $v0, $t0, 0x50
c09526c4  move      $a2, $s5
c09526c8  move      $a1, $s3
c09526cc  move      $a0, $v0
c09526d0  jal       0xc095314c
c09526d4  nop       
c09526d8  move      $s0, $v0
c09526dc  addiu     $s1, $zero, 1
c09526e0  sw        $s0, 0x10($fp)
c09526e4  lw        $t3, ($s2)
c09526e8  b         0xc095270c
c09526ec  nop       
c09526f0  addiu     $s0, $zero, 0xb
c09526f4  sw        $s0, 0x10($fp)
c09526f8  lui       $t0, 0xc096
c09526fc  addiu     $s2, $t0, -0x5ec4
c0952700  addiu     $s1, $zero, 1
c0952704  lw        $s6, 0x44($fp)
c0952708  lw        $t3, ($s2)
c095270c  addiu     $a0, $t3, 4
c0952710  jal       0xc0958844 ; import thunk COREDLL.dll!LeaveCriticalSection@5
c0952714  nop       
c0952718  beqz      $s6, 0xc0952730
c095271c  nop       
c0952720  sw        $s0, ($s6)
c0952724  b         0xc0952730
c0952728  nop       
c095272c  lw        $s1, 0x14($fp)
c0952730  move      $v0, $s1
c0952734  move      $sp, $fp
c0952738  lw        $fp, 0x18($sp)
c095273c  lw        $s6, 0x1c($sp)
c0952740  lw        $s5, 0x20($sp)
c0952744  lw        $s4, 0x24($sp)
c0952748  lw        $s3, 0x28($sp)
c095274c  lw        $s2, 0x2c($sp)
c0952750  lw        $s1, 0x30($sp)
c0952754  lw        $s0, 0x34($sp)
c0952758  lw        $ra, 0x38($sp)
c095275c  addiu     $sp, $sp, 0x40
c0952760  jr        $ra
c0952764  nop       
c09534e0  addiu     $sp, $sp, -0x18
c09534e4  sw        $ra, 0x14($sp)
c09534e8  sw        $s0, 0x10($sp)
c09534ec  addiu     $t0, $a1, 4
c09534f0  lwl       $t5, 3($t0)
c09534f4  lwr       $t5, ($t0)
c09534f8  addiu     $t6, $zero, 0x3000
c09534fc  lbu       $t0, 1($t5)
c0953500  lbu       $t2, ($t5)
c0953504  sll       $t1, $t0, 8
c0953508  move      $t3, $t1
c095350c  or        $t3, $t2, $t3
c0953510  move      $t4, $t3
c0953514  bne       $t4, $t6, 0xc0953544
c0953518  nop       
c095351c  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0953520  addiu     $a0, $zero, 0x694
c0953524  move      $s0, $v0
c0953528  beqz      $s0, 0xc09536ac
c095352c  nop       
c0953530  jal       0xc09536c4
c0953534  move      $a0, $s0
c0953538  lui       $a0, 0xc095
c095353c  b         0xc09536a4
c0953540  addiu     $t0, $a0, 0x1194
c0953544  addiu     $t0, $zero, 0x164
c0953548  bne       $t4, $t0, 0xc0953578
c095354c  nop       
c0953550  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0953554  addiu     $a0, $zero, 0x94
c0953558  move      $s0, $v0
c095355c  beqz      $s0, 0xc09536ac
c0953560  nop       
c0953564  jal       0xc09536c4
c0953568  move      $a0, $s0
c095356c  lui       $a0, 0xc095
c0953570  b         0xc09536a4
c0953574  addiu     $t0, $a0, 0x1318
c0953578  lbu       $t0, 0xf($t5)
c095357c  lbu       $t2, 0xe($t5)
c0953580  sll       $t1, $t0, 8
c0953584  move      $t3, $t1
c0953588  or        $t3, $t2, $t3
c095358c  move      $t4, $t3
c0953590  addiu     $t6, $zero, 8
c0953594  bne       $t4, $t6, 0xc095361c
c0953598  nop       
c095359c  lbu       $t0, 3($t5)
c09535a0  lbu       $t2, 2($t5)
c09535a4  sll       $t1, $t0, 8
c09535a8  move      $t4, $t1
c09535ac  or        $t3, $t2, $t4
c09535b0  move      $t6, $t3
c09535b4  addiu     $t7, $zero, 1
c09535b8  bne       $t6, $t7, 0xc09535e8
c09535bc  nop       
c09535c0  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c09535c4  addiu     $a0, $zero, 0x94
c09535c8  move      $s0, $v0
c09535cc  beqz      $s0, 0xc09536ac
c09535d0  nop       
c09535d4  jal       0xc09536c4
c09535d8  move      $a0, $s0
c09535dc  lui       $a0, 0xc095
c09535e0  b         0xc09536a4
c09535e4  addiu     $t0, $a0, 0x135c
c09535e8  addiu     $t0, $zero, 2
c09535ec  bne       $t6, $t0, 0xc09536ac
c09535f0  nop       
c09535f4  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c09535f8  addiu     $a0, $zero, 0x94
c09535fc  move      $s0, $v0
c0953600  beqz      $s0, 0xc09536ac
c0953604  nop       
c0953608  jal       0xc09536c4
c095360c  move      $a0, $s0
c0953610  lui       $a0, 0xc095
c0953614  b         0xc09536a4
c0953618  addiu     $t0, $a0, 0x13a0
c095361c  addiu     $t0, $zero, 0x10
c0953620  bne       $t4, $t0, 0xc09536ac
c0953624  nop       
c0953628  lbu       $t0, 3($t5)
c095362c  lbu       $t2, 2($t5)
c0953630  sll       $t1, $t0, 8
c0953634  move      $t3, $t1
c0953638  or        $t3, $t2, $t3
c095363c  move      $t4, $t3
c0953640  addiu     $t6, $zero, 1
c0953644  bne       $t4, $t6, 0xc0953674
c0953648  nop       
c095364c  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0953650  addiu     $a0, $zero, 0x94
c0953654  move      $s0, $v0
c0953658  beqz      $s0, 0xc09536ac
c095365c  nop       
c0953660  jal       0xc09536c4
c0953664  move      $a0, $s0
c0953668  lui       $a0, 0xc095
c095366c  b         0xc09536a4
c0953670  addiu     $t0, $a0, 0x13e4
c0953674  addiu     $t0, $zero, 2
c0953678  bne       $t4, $t0, 0xc09536ac
c095367c  nop       
c0953680  jal       0xc0958e1c ; import thunk COREDLL.dll!??2@YAPAXI@Z@1095
c0953684  addiu     $a0, $zero, 0x94
c0953688  move      $s0, $v0
c095368c  beqz      $s0, 0xc09536ac
c0953690  nop       
c0953694  jal       0xc09536c4
c0953698  move      $a0, $s0
c095369c  lui       $a0, 0xc095
c09536a0  addiu     $t0, $a0, 0x1428
c09536a4  b         0xc09536b0
c09536a8  sw        $t0, ($s0)
c09536ac  move      $s0, $zero
c09536b0  move      $v0, $s0
c09536b4  lw        $s0, 0x10($sp)
c09536b8  lw        $ra, 0x14($sp)
c09536bc  jr        $ra
c09536c0  addiu     $sp, $sp, 0x18
c09536c4  lui       $t0, 0xc095
c09536c8  addiu     $t0, $t0, 0x15fc
c09536cc  sw        $t0, ($a0)
c09536d0  jr        $ra
c09536d4  move      $v0, $a0
c09536e8  lw        $t0, 0x38($a0)
c09536ec  bnez      $t0, 0xc09536f8
c09536f0  addiu     $v0, $zero, 1
c09536f4  move      $v0, $zero
c09536f8  jr        $ra
c09536fc  nop       
c0953708  addiu     $sp, $sp, -0x20
c095370c  sw        $ra, 0x18($sp)
c0953710  move      $t0, $a0
c0953714  sw        $a3, 0x10($sp)
c0953718  move      $a3, $a2
c095371c  lw        $a2, 0x20($t0)
c0953720  lw        $a0, 0x18($t0)
c0953724  lw        $t0, 0x1c($t0)
c0953728  jalr      $t0
c095372c  nop       
c0953730  lw        $ra, 0x18($sp)
c0953734  jr        $ra
c0953738  addiu     $sp, $sp, 0x20
c095373c  addiu     $sp, $sp, -0x20
c0953740  sw        $ra, 0x18($sp)
c0953744  move      $t0, $a0
c0953748  lw        $a2, 0x20($t0)
c095374c  lw        $a0, 0x18($t0)
c0953750  move      $a3, $a1
c0953754  lw        $t0, 0x1c($t0)
c0953758  addiu     $a1, $zero, 0x3bd
c095375c  jalr      $t0
c0953760  sw        $zero, 0x10($sp)
c0953764  lw        $ra, 0x18($sp)
c0953768  jr        $ra
c095376c  addiu     $sp, $sp, 0x20
c09537a4  addiu     $sp, $sp, -0x20
c09537a8  sw        $ra, 0x18($sp)
c09537ac  move      $t0, $a0
c09537b0  lw        $a2, 0x20($t0)
c09537b4  lw        $a0, 0x18($t0)
c09537b8  lw        $t0, 0x1c($t0)
c09537bc  addiu     $a3, $zero, 0
c09537c0  addiu     $a1, $zero, 0x3bc
c09537c4  jalr      $t0
c09537c8  sw        $zero, 0x10($sp)
c09537cc  lw        $ra, 0x18($sp)
c09537d0  jr        $ra
c09537d4  addiu     $sp, $sp, 0x20
c095384c  addiu     $sp, $sp, -0x20
c0953850  sw        $ra, 0x18($sp)
c0953854  sw        $s1, 0x10($sp)
c0953858  sw        $s0, 0x14($sp)
c095385c  move      $s0, $a0
c0953860  move      $s1, $a1
c0953864  addiu     $t5, $zero, 1
c0953868  addiu     $t0, $a2, 8
c095386c  sw        $t5, 0xc($s0)
c0953870  sw        $s1, 0x50($s0)
c0953874  lwl       $t1, 3($t0)
c0953878  lwr       $t1, ($t0)
c095387c  addiu     $t2, $a2, 0xc
c0953880  sw        $t1, 0x1c($s0)
c0953884  lwl       $t3, 3($t2)
c0953888  lwr       $t3, ($t2)
c095388c  addiu     $t0, $a2, 4
c0953890  sw        $t3, 0x20($s0)
c0953894  lwl       $t4, 3($a2)
c0953898  lwr       $t4, ($a2)
c095389c  sw        $t4, 0x18($s0)
c09538a0  sw        $a3, 0x14($s0)
c09538a4  sw        $zero, 0x10($s0)
c09538a8  sw        $zero, 0x68($s0)
c09538ac  lwl       $a1, 3($t0)
c09538b0  lwr       $a1, ($t0)
c09538b4  lbu       $t0, 1($a1)
c09538b8  lbu       $t2, ($a1)
c09538bc  sll       $t1, $t0, 8
c09538c0  move      $t3, $t1
c09538c4  or        $t3, $t2, $t3
c09538c8  bne       $t3, $t5, 0xc09538e4
c09538cc  nop       
c09538d0  srl       $t0, $zero, 8
c09538d4  sb        $zero, 0x34($s0)
c09538d8  addiu     $a2, $zero, 0x10
c09538dc  b         0xc09538e8
c09538e0  sb        $t0, 0x35($s0)
c09538e4  addiu     $a2, $zero, 0x12
c09538e8  jal       0xc0958e6c ; import thunk COREDLL.dll!memcpy@1044
c09538ec  addiu     $a0, $s0, 0x24
c09538f0  move      $a0, $s1
c09538f4  sw        $zero, 0x38($s0)
c09538f8  sw        $zero, 0x40($s0)
c09538fc  sw        $zero, 0x3c($s0)
c0953900  sw        $zero, 0x44($s0)
c0953904  sw        $zero, 0x48($s0)
c0953908  sw        $zero, 0x4c($s0)
c095390c  sw        $zero, 0x54($s0)
c0953910  jal       0xc0952900
c0953914  sw        $zero, 0x5c($s0)
c0953918  lw        $t0, ($s0)
c095391c  lw        $t0, 0x34($t0)
c0953920  move      $a0, $s0
c0953924  jalr      $t0
c0953928  sw        $v0, 0x58($s0)
c095392c  lw        $a1, ($s0)
c0953930  lw        $t0, 0x20($a1)
c0953934  jalr      $t0
c0953938  move      $a0, $s0
c095393c  lw        $a2, ($s1)
c0953940  lw        $t0, 4($a2)
c0953944  move      $a1, $s0
c0953948  jalr      $t0
c095394c  move      $a0, $s1
c0953950  move      $s1, $v0
c0953954  bnez      $s1, 0xc095396c
c0953958  nop       
c095395c  lw        $t0, ($s0)
c0953960  lw        $t0, 0x28($t0)
c0953964  jalr      $t0
c0953968  move      $a0, $s0
c095396c  move      $v0, $s1
c0953970  lw        $s1, 0x10($sp)
c0953974  lw        $s0, 0x14($sp)
c0953978  lw        $ra, 0x18($sp)
c095397c  jr        $ra
c0953980  addiu     $sp, $sp, 0x20
c0953984  lw        $t0, 0xc($a0)
c0953988  addiu     $v0, $t0, 1
c095398c  jr        $ra
c0953990  sw        $v0, 0xc($a0)
c0953994  addiu     $sp, $sp, -0x20
c0953998  sw        $ra, 0x18($sp)
c095399c  sw        $s1, 0x10($sp)
c09539a0  sw        $s0, 0x14($sp)
c09539a4  move      $s1, $a0
c09539a8  lw        $t0, 0xc($s1)
c09539ac  addiu     $s0, $t0, -1
c09539b0  bnez      $s0, 0xc09539d8
c09539b4  sw        $s0, 0xc($s1)
c09539b8  lw        $a0, 0x50($s1)
c09539bc  jal       0xc0952ae8
c09539c0  move      $a1, $s1
c09539c4  lw        $a2, ($s1)
c09539c8  lw        $t0, ($a2)
c09539cc  addiu     $a1, $zero, 1
c09539d0  jalr      $t0
c09539d4  move      $a0, $s1
c09539d8  move      $v0, $s0
c09539dc  lw        $s1, 0x10($sp)
c09539e0  lw        $s0, 0x14($sp)
c09539e4  lw        $ra, 0x18($sp)
c09539e8  jr        $ra
c09539ec  addiu     $sp, $sp, 0x20
c09539f0  addiu     $sp, $sp, -0x18
c09539f4  sw        $ra, 0x10($sp)
c09539f8  move      $t5, $a1
c09539fc  lw        $t1, 0x10($t5)
c0953a00  andi      $t0, $t1, 2
c0953a04  bnez      $t0, 0xc0953a14
c0953a08  move      $a1, $a0
c0953a0c  b         0xc0953ab0
c0953a10  addiu     $v0, $zero, 0x22
c0953a14  lui       $t2, 0xffff
c0953a18  sw        $zero, 0x18($t5)
c0953a1c  ori       $t2, $t2, 0xfffe
c0953a20  and       $t1, $t1, $t2
c0953a24  ori       $t0, $t1, 0x10
c0953a28  sw        $t0, 0x10($t5)
c0953a2c  sw        $zero, 8($t5)
c0953a30  lw        $t2, 0x38($a1)
c0953a34  bnez      $t2, 0xc0953a44
c0953a38  nop       
c0953a3c  b         0xc0953a4c
c0953a40  sw        $t5, 0x38($a1)
c0953a44  lw        $t0, 0x40($a1)
c0953a48  sw        $t5, 0x18($t0)
c0953a4c  lw        $t1, 0x3c($a1)
c0953a50  bnez      $t1, 0xc0953a8c
c0953a54  sw        $t5, 0x40($a1)
c0953a58  sw        $t5, 0x3c($a1)
c0953a5c  lw        $t0, ($t5)
c0953a60  sw        $t0, 0x44($a1)
c0953a64  lw        $t3, 4($t5)
c0953a68  lw        $t2, ($t5)
c0953a6c  addu      $t3, $t3, $t2
c0953a70  sw        $t3, 0x48($a1)
c0953a74  lw        $t1, 0x10($t5)
c0953a78  andi      $t4, $t1, 4
c0953a7c  beqz      $t4, 0xc0953a8c
c0953a80  nop       
c0953a84  lw        $t0, 0x14($t5)
c0953a88  sw        $t0, 0x54($a1)
c0953a8c  lw        $t2, 0x10($a1)
c0953a90  beqz      $t2, 0xc0953aac
c0953a94  nop       
c0953a98  lw        $a0, 0x50($a1)
c0953a9c  lw        $t0, ($a0)
c0953aa0  lw        $t0, 0x10($t0)
c0953aa4  jalr      $t0
c0953aa8  nop       
c0953aac  move      $v0, $zero
c0953ab0  lw        $ra, 0x10($sp)
c0953ab4  jr        $ra
c0953ab8  addiu     $sp, $sp, 0x18
c0953abc  addiu     $sp, $sp, -0x18
c0953ac0  sw        $ra, 0x14($sp)
c0953ac4  sw        $s0, 0x10($sp)
c0953ac8  move      $s0, $a0
c0953acc  lw        $a1, 0x3c($s0)
c0953ad0  bnez      $a1, 0xc0953ae0
c0953ad4  nop       
c0953ad8  b         0xc0953bb4
c0953adc  move      $v0, $zero
c0953ae0  lw        $t3, 0x54($s0)
c0953ae4  sltiu     $t0, $t3, 2
c0953ae8  bnez      $t0, 0xc0953b2c
c0953aec  nop       
c0953af0  lw        $t1, 0x10($a1)
c0953af4  andi      $t2, $t1, 8
c0953af8  beqz      $t2, 0xc0953b20
c0953afc  nop       
c0953b00  lui       $t4, 0xffff
c0953b04  ori       $t4, $t4, 0xffff
c0953b08  beq       $t3, $t4, 0xc0953b18
c0953b0c  nop       
c0953b10  addiu     $t0, $t3, -1
c0953b14  sw        $t0, 0x54($s0)
c0953b18  b         0xc0953b24
c0953b1c  lw        $t3, 0x38($s0)
c0953b20  lw        $t3, 0x18($a1)
c0953b24  b         0xc0953b58
c0953b28  move      $a1, $zero
c0953b2c  lw        $t3, 0x18($a1)
c0953b30  bnez      $t3, 0xc0953b40
c0953b34  sw        $t3, 0x38($s0)
c0953b38  b         0xc0953b58
c0953b3c  sw        $zero, 0x40($s0)
c0953b40  lw        $t0, 0x10($t3)
c0953b44  andi      $t1, $t0, 4
c0953b48  beqz      $t1, 0xc0953b58
c0953b4c  nop       
c0953b50  lw        $t2, 0x14($t3)
c0953b54  sw        $t2, 0x54($s0)
c0953b58  beqz      $t3, 0xc0953b78
c0953b5c  sw        $t3, 0x3c($s0)
c0953b60  lw        $t1, ($t3)
c0953b64  sw        $t1, 0x44($s0)
c0953b68  lw        $t0, 4($t3)
c0953b6c  addu      $t1, $t0, $t1
c0953b70  b         0xc0953b80
c0953b74  sw        $t1, 0x48($s0)
c0953b78  sw        $zero, 0x44($s0)
c0953b7c  sw        $zero, 0x48($s0)
c0953b80  beqz      $a1, 0xc0953bb0
c0953b84  nop       
c0953b88  lui       $t1, 0xffff
c0953b8c  lw        $t0, 0x10($a1)
c0953b90  ori       $t1, $t1, 0xffef
c0953b94  and       $t0, $t0, $t1
c0953b98  ori       $t1, $t0, 1
c0953b9c  sw        $t1, 0x10($a1)
c0953ba0  lw        $t2, ($s0)
c0953ba4  lw        $t2, 0x24($t2)
c0953ba8  jalr      $t2
c0953bac  move      $a0, $s0
c0953bb0  lw        $v0, 0x44($s0)
c0953bb4  lw        $s0, 0x10($sp)
c0953bb8  lw        $ra, 0x14($sp)
c0953bbc  jr        $ra
c0953bc0  addiu     $sp, $sp, 0x18
c0953e4c  addiu     $sp, $sp, -0x20
c0953e50  sw        $ra, 0x18($sp)
c0953e54  sw        $s1, 0x10($sp)
c0953e58  sw        $s0, 0x14($sp)
c0953e5c  addiu     $t0, $a2, 4
c0953e60  lwl       $t6, 3($t0)
c0953e64  lwr       $t6, ($t0)
c0953e68  move      $s0, $a0
c0953e6c  lbu       $t0, 0xf($t6)
c0953e70  lbu       $t2, 0xe($t6)
c0953e74  sll       $t1, $t0, 8
c0953e78  lbu       $t0, 3($t6)
c0953e7c  move      $t3, $t1
c0953e80  or        $t4, $t2, $t3
c0953e84  sll       $t1, $t0, 8
c0953e88  lbu       $t2, 2($t6)
c0953e8c  addiu     $t5, $zero, 2
c0953e90  addiu     $t7, $zero, 8
c0953e94  addiu     $t6, $zero, 1
c0953e98  bne       $t4, $t7, 0xc0953ec0
c0953e9c  move      $t3, $t1
c0953ea0  or        $t4, $t2, $t3
c0953ea4  bne       $t4, $t6, 0xc0953eb8
c0953ea8  nop       
c0953eac  sw        $zero, 0x6c($s0)
c0953eb0  b         0xc0953ee8
c0953eb4  sw        $t6, 0x70($s0)
c0953eb8  b         0xc0953ed0
c0953ebc  sw        $t5, 0x6c($s0)
c0953ec0  or        $t4, $t2, $t3
c0953ec4  bne       $t4, $t6, 0xc0953ed8
c0953ec8  nop       
c0953ecc  sw        $t6, 0x6c($s0)
c0953ed0  b         0xc0953ee8
c0953ed4  sw        $t5, 0x70($s0)
c0953ed8  addiu     $t0, $zero, 3
c0953edc  addiu     $t1, $zero, 4
c0953ee0  sw        $t0, 0x6c($s0)
c0953ee4  sw        $t1, 0x70($s0)
c0953ee8  addiu     $t0, $s0, 0x80
c0953eec  sw        $zero, -8($t0)
c0953ef0  sw        $zero, ($t0)
c0953ef4  addiu     $t5, $t5, -1
c0953ef8  bnez      $t5, 0xc0953eec
c0953efc  addiu     $t0, $t0, 4
c0953f00  jal       0xc095384c
c0953f04  move      $a0, $s0
c0953f08  move      $s1, $v0
c0953f0c  bnez      $s1, 0xc0953f28
c0953f10  nop       
c0953f14  lw        $t0, ($s0)
c0953f18  lw        $t0, 0x3c($t0)
c0953f1c  lui       $a1, 1
c0953f20  jalr      $t0
c0953f24  move      $a0, $s0
c0953f28  move      $v0, $s1
c0953f2c  lw        $s1, 0x10($sp)
c0953f30  lw        $s0, 0x14($sp)
c0953f34  lw        $ra, 0x18($sp)
c0953f38  jr        $ra
c0953f3c  addiu     $sp, $sp, 0x20
c0953f50  addiu     $sp, $sp, -0x18
c0953f54  sw        $ra, 0x10($sp)
c0953f58  move      $a1, $a0
c0953f5c  addiu     $t0, $zero, 1
c0953f60  sw        $t0, 0x10($a1)
c0953f64  lw        $t0, 0x44($a1)
c0953f68  beqz      $t0, 0xc0953f84
c0953f6c  nop       
c0953f70  lw        $a0, 0x50($a1)
c0953f74  lw        $t1, ($a0)
c0953f78  lw        $t1, 0x10($t1)
c0953f7c  jalr      $t1
c0953f80  nop       
c0953f84  lw        $ra, 0x10($sp)
c0953f88  addiu     $v0, $zero, 0
c0953f8c  jr        $ra
c0953f90  addiu     $sp, $sp, 0x18
c0953f94  sw        $zero, 0x10($a0)
c0953f98  jr        $ra
c0953f9c  addiu     $v0, $zero, 0
c0953fa0  addiu     $sp, $sp, -0x18
c0953fa4  sw        $ra, 0x14($sp)
c0953fa8  sw        $s0, 0x10($sp)
c0953fac  move      $s0, $a0
c0953fb0  lw        $t0, 0xc($s0)
c0953fb4  lw        $t2, ($s0)
c0953fb8  addiu     $t1, $t0, 1
c0953fbc  lw        $t2, 0x14($t2)
c0953fc0  move      $a0, $s0
c0953fc4  jalr      $t2
c0953fc8  sw        $t1, 0xc($s0)
c0953fcc  lw        $t0, 0x38($s0)
c0953fd0  sw        $zero, 0x3c($s0)
c0953fd4  sw        $zero, 0x44($s0)
c0953fd8  sw        $zero, 0x48($s0)
c0953fdc  sw        $zero, 0x4c($s0)
c0953fe0  beqz      $t0, 0xc0954030
c0953fe4  sw        $zero, 0x54($s0)
c0953fe8  lw        $a1, 0x38($s0)
c0953fec  lw        $t1, 0x18($a1)
c0953ff0  bnez      $t1, 0xc0953ffc
c0953ff4  sw        $t1, 0x38($s0)
c0953ff8  sw        $zero, 0x40($s0)
c0953ffc  lui       $t2, 0xffff
c0954000  lw        $t0, 0x10($a1)
c0954004  ori       $t2, $t2, 0xffef
c0954008  and       $t0, $t0, $t2
c095400c  ori       $t1, $t0, 1
c0954010  sw        $t1, 0x10($a1)
c0954014  lw        $t2, ($s0)
c0954018  lw        $t2, 0x24($t2)
c095401c  jalr      $t2
c0954020  move      $a0, $s0
c0954024  lw        $a0, 0x38($s0)
c0954028  bnez      $a0, 0xc0953fe8
c095402c  nop       
c0954030  jal       0xc0953994
c0954034  move      $a0, $s0
c0954038  lw        $s0, 0x10($sp)
c095403c  lw        $ra, 0x14($sp)
c0954040  addiu     $v0, $zero, 0
c0954044  jr        $ra
c0954048  addiu     $sp, $sp, 0x18
c09540fc  addiu     $sp, $sp, -0x38
c0954100  sw        $ra, 0x34($sp)
c0954104  sw        $fp, 0x20($sp)
c0954108  sw        $s3, 0x24($sp)
c095410c  sw        $s2, 0x28($sp)
c0954110  sw        $s1, 0x2c($sp)
c0954114  sw        $s0, 0x30($sp)
c0954118  move      $fp, $sp
c095411c  move      $s3, $a3
c0954120  sw        $s3, 0x44($fp)
c0954124  move      $s2, $a2
c0954128  sw        $s2, 0x40($fp)
c095412c  move      $s0, $a1
c0954130  sw        $s0, 0x3c($fp)
c0954134  move      $s1, $a0
c0954138  sw        $s1, 0x38($fp)
c095413c  lw        $t0, 0x10($s1)
c0954140  beqz      $t0, 0xc0954210
c0954144  nop       
c0954148  lw        $t1, 0x44($s1)
c095414c  beqz      $t1, 0xc0954210
c0954150  nop       
c0954154  sltu      $t2, $s0, $s2
c0954158  beqz      $t2, 0xc0954210
c095415c  nop       
c0954160  lw        $t3, 0x44($s1)
c0954164  lw        $t0, 0x48($s1)
c0954168  sltu      $t1, $t3, $t0
c095416c  bnez      $t1, 0xc095419c
c0954170  nop       
c0954174  move      $a0, $s1
c0954178  jal       0xc0953abc
c095417c  nop       
c0954180  beqz      $v0, 0xc0954210
c0954184  nop       
c0954188  lw        $t1, 0x44($s1)
c095418c  lw        $t0, 0x48($s1)
c0954190  sltu      $t1, $t1, $t0
c0954194  beqz      $t1, 0xc0954174
c0954198  nop       
c095419c  lw        $t1, ($s1)
c09541a0  lw        $t0, 0x48($fp)
c09541a4  sw        $t0, 0x10($sp)
c09541a8  move      $a3, $s3
c09541ac  move      $a2, $s2
c09541b0  move      $a1, $s0
c09541b4  move      $a0, $s1
c09541b8  lw        $t1, 0x40($t1)
c09541bc  jalr      $t1
c09541c0  nop       
c09541c4  move      $s0, $v0
c09541c8  sw        $s0, 0x3c($fp)
c09541cc  b         0xc0954154
c09541d0  nop       
c09541d4  lw        $s1, 0x38($fp)
c09541d8  lw        $a2, 0x44($s1)
c09541dc  move      $a1, $s1
c09541e0  lui       $t0, 0xc095
c09541e4  addiu     $a0, $t0, 0x1638
c09541e8  jal       0xc0958854 ; import thunk COREDLL.dll!NKDbgPrintfW@545
c09541ec  nop       
c09541f0  lw        $a0, 0x48($s1)
c09541f4  sw        $a0, 0x44($s1)
c09541f8  lw        $s3, 0x44($fp)
c09541fc  lw        $s2, 0x40($fp)
c0954200  lw        $s0, 0x3c($fp)
c0954204  b         0xc0954154
c0954208  nop       
c095420c  lw        $s0, 0x18($fp)
c0954210  move      $v0, $s0
c0954214  move      $sp, $fp
c0954218  lw        $fp, 0x20($sp)
c095421c  lw        $s3, 0x24($sp)
c0954220  lw        $s2, 0x28($sp)
c0954224  lw        $s1, 0x2c($sp)
c0954228  lw        $s0, 0x30($sp)
c095422c  lw        $ra, 0x34($sp)
c0954230  addiu     $sp, $sp, 0x38
c0954234  jr        $ra
c0954238  nop       
c0954340  addiu     $sp, $sp, -0x18
c0954344  sw        $ra, 0x14($sp)
c0954348  sw        $s0, 0x10($sp)
c095434c  move      $s0, $a0
c0954350  lw        $t0, 0x38($s0)
c0954354  beqz      $t0, 0xc0954364
c0954358  nop       
c095435c  b         0xc0954398
c0954360  addiu     $v0, $zero, 0x21
c0954364  lw        $t1, 0x68($s0)
c0954368  beqz      $t1, 0xc0954384
c095436c  nop       
c0954370  lui       $t0, 0xc096
c0954374  sw        $zero, 0x68($s0)
c0954378  lw        $a0, -0x5ec4($t0)
c095437c  jal       0xc0957c18
c0954380  addiu     $a1, $zero, 0
c0954384  lw        $t0, ($s0)
c0954388  lw        $t0, 0x2c($t0)
c095438c  jalr      $t0
c0954390  move      $a0, $s0
c0954394  move      $v0, $zero
c0954398  lw        $s0, 0x10($sp)
c095439c  lw        $ra, 0x14($sp)
c09543a0  jr        $ra
c09543a4  addiu     $sp, $sp, 0x18
c0954688  addiu     $sp, $sp, -0x20
c095468c  sw        $ra, 0x18($sp)
c0954690  sw        $s1, 0x10($sp)
c0954694  sw        $s0, 0x14($sp)
c0954698  move      $s0, $a0
c095469c  jal       0xc0953e4c
c09546a0  move      $a0, $s0
c09546a4  lw        $a0, 0x50($s0)
c09546a8  jal       0xc0952f48
c09546ac  move      $s1, $v0
c09546b0  negu      $a1, $v0
c09546b4  bnez      $s1, 0xc09546cc
c09546b8  sw        $a1, 0x88($s0)
c09546bc  lw        $t0, ($s0)
c09546c0  lw        $t0, 0x10($t0)
c09546c4  jalr      $t0
c09546c8  move      $a0, $s0
c09546cc  move      $v0, $s1
c09546d0  lw        $s1, 0x10($sp)
c09546d4  lw        $s0, 0x14($sp)
c09546d8  lw        $ra, 0x18($sp)
c09546dc  jr        $ra
c09546e0  addiu     $sp, $sp, 0x20
c09546e4  addiu     $sp, $sp, -0x20
c09546e8  sw        $ra, 0x18($sp)
c09546ec  sw        $s1, 0x10($sp)
c09546f0  sw        $s0, 0x14($sp)
c09546f4  move      $s1, $a0
c09546f8  jal       0xc0953fa0
c09546fc  move      $a0, $s1
c0954700  move      $s0, $v0
c0954704  bnez      $s0, 0xc095471c
c0954708  nop       
c095470c  lw        $t0, ($s1)
c0954710  lw        $t0, 0x10($t0)
c0954714  jalr      $t0
c0954718  move      $a0, $s1
c095471c  move      $v0, $s0
c0954720  lw        $s1, 0x10($sp)
c0954724  lw        $s0, 0x14($sp)
c0954728  lw        $ra, 0x18($sp)
c095472c  jr        $ra
c0954730  addiu     $sp, $sp, 0x20
c0954cf0  addiu     $sp, $sp, -0x38
c0954cf4  sw        $ra, 0x34($sp)
c0954cf8  sw        $fp, 0x10($sp)
c0954cfc  sw        $s7, 0x14($sp)
c0954d00  sw        $s6, 0x18($sp)
c0954d04  sw        $s5, 0x1c($sp)
c0954d08  sw        $s4, 0x20($sp)
c0954d0c  sw        $s3, 0x24($sp)
c0954d10  sw        $s2, 0x28($sp)
c0954d14  sw        $s1, 0x2c($sp)
c0954d18  sw        $s0, 0x30($sp)
c0954d1c  move      $s0, $a0
c0954d20  lw        $a0, 0x50($s0)
c0954d24  lw        $s2, 0x88($s0)
c0954d28  lw        $s6, 0x8c($s0)
c0954d2c  move      $s5, $a3
c0954d30  move      $s3, $a2
c0954d34  jal       0xc0952f48
c0954d38  move      $s1, $a1
c0954d3c  lw        $a0, 0x50($s0)
c0954d40  jal       0xc0952f50
c0954d44  move      $s4, $v0
c0954d48  lw        $t0, 0x48($sp)
c0954d4c  move      $s7, $v0
c0954d50  lw        $t9, 0x80($s0)
c0954d54  lw        $v1, 0x84($s0)
c0954d58  lw        $a1, 0x78($s0)
c0954d5c  lw        $a0, 0x7c($s0)
c0954d60  lw        $t8, 0x44($s0)
c0954d64  lw        $t1, 4($t0)
c0954d68  beqz      $t1, 0xc0954d7c
c0954d6c  lw        $v0, 0x48($s0)
c0954d70  move      $a3, $zero
c0954d74  b         0xc0954d84
c0954d78  move      $a2, $zero
c0954d7c  lw        $a3, 0x60($s0)
c0954d80  lw        $a2, 0x64($s0)
c0954d84  sltu      $t0, $s1, $s3
c0954d88  beqz      $t0, 0xc0954ea0
c0954d8c  nop       
c0954d90  addiu     $fp, $zero, -0x8000
c0954d94  bgez      $s2, 0xc0954dcc
c0954d98  nop       
c0954d9c  sltu      $t0, $t8, $v0
c0954da0  beqz      $t0, 0xc0954ea0
c0954da4  nop       
c0954da8  lh        $t1, ($t8)
c0954dac  lh        $t2, 2($t8)
c0954db0  move      $a1, $t9
c0954db4  move      $a0, $v1
c0954db8  addu      $s2, $s4, $s2
c0954dbc  move      $t9, $t1
c0954dc0  move      $v1, $t2
c0954dc4  bltz      $s2, 0xc0954d9c
c0954dc8  addiu     $t8, $t8, 4
c0954dcc  multu     $s7, $s2
c0954dd0  subu      $t1, $a1, $t9
c0954dd4  subu      $s2, $s2, $s6
c0954dd8  mflo      $t0
c0954ddc  srl       $t5, $t0, 0x11
c0954de0  nop       
c0954de4  mult      $t1, $t5
c0954de8  subu      $t1, $a0, $v1
c0954dec  mflo      $t2
c0954df0  sra       $t3, $t2, 0xf
c0954df4  addu      $t0, $t3, $t9
c0954df8  mult      $t0, $a3
c0954dfc  mflo      $t4
c0954e00  nop       
c0954e04  nop       
c0954e08  mult      $t1, $t5
c0954e0c  sra       $t7, $t4, 0x10
c0954e10  sltu      $t1, $s1, $s5
c0954e14  mflo      $t2
c0954e18  sra       $t3, $t2, 0xf
c0954e1c  addu      $t0, $t3, $v1
c0954e20  mult      $t0, $a2
c0954e24  mflo      $t4
c0954e28  beqz      $t1, 0xc0954e88
c0954e2c  sra       $t6, $t4, 0x10
c0954e30  lh        $t2, ($s1)
c0954e34  lh        $t0, 2($s1)
c0954e38  addu      $t7, $t2, $t7
c0954e3c  ori       $t2, $zero, 0x8000
c0954e40  slt       $t3, $t7, $t2
c0954e44  bnez      $t3, 0xc0954e54
c0954e48  addu      $t6, $t0, $t6
c0954e4c  b         0xc0954e64
c0954e50  addiu     $t7, $zero, 0x7fff
c0954e54  slti      $t0, $t7, -0x8000
c0954e58  beqz      $t0, 0xc0954e64
c0954e5c  nop       
c0954e60  move      $t7, $fp
c0954e64  slt       $t1, $t6, $t2
c0954e68  bnez      $t1, 0xc0954e78
c0954e6c  nop       
c0954e70  b         0xc0954e88
c0954e74  addiu     $t6, $zero, 0x7fff
c0954e78  slti      $t0, $t6, -0x8000
c0954e7c  beqz      $t0, 0xc0954e88
c0954e80  nop       
c0954e84  move      $t6, $fp
c0954e88  sh        $t7, ($s1)
c0954e8c  sh        $t6, 2($s1)
c0954e90  addiu     $s1, $s1, 4
c0954e94  sltu      $t0, $s1, $s3
c0954e98  bnez      $t0, 0xc0954d94
c0954e9c  nop       
c0954ea0  lw        $t2, 0x4c($s0)
c0954ea4  lw        $t1, 0x44($s0)
c0954ea8  sw        $s2, 0x88($s0)
c0954eac  subu      $t2, $t2, $t1
c0954eb0  addu      $t0, $t2, $t8
c0954eb4  move      $v0, $s1
c0954eb8  sw        $t0, 0x4c($s0)
c0954ebc  sw        $t8, 0x44($s0)
c0954ec0  sw        $a1, 0x78($s0)
c0954ec4  sw        $a0, 0x7c($s0)
c0954ec8  sw        $t9, 0x80($s0)
c0954ecc  sw        $v1, 0x84($s0)
c0954ed0  lw        $fp, 0x10($sp)
c0954ed4  lw        $s7, 0x14($sp)
c0954ed8  lw        $s6, 0x18($sp)
c0954edc  lw        $s5, 0x1c($sp)
c0954ee0  lw        $s4, 0x20($sp)
c0954ee4  lw        $s3, 0x24($sp)
c0954ee8  lw        $s2, 0x28($sp)
c0954eec  lw        $s1, 0x2c($sp)
c0954ef0  lw        $s0, 0x30($sp)
c0954ef4  lw        $ra, 0x34($sp)
c0954ef8  jr        $ra
c0954efc  addiu     $sp, $sp, 0x38
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
; coredll.dll 1197e2aad1a47ddb477673badc45cb5ba7226a724c8d90099713aaee577da32c
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
