; bounded PCM split/ownership/write/restart
00026e98  sw         $s2, 0x14($sp)
00026e9c  lw         $s1, 0x50($sp)
00026ea0  beqz       $s2, 0x27074
00026ea4  nop        
00026ea8  beqz       $s1, 0x27074
00026eac  nop        
00026eb0  lui        $t0, 1
00026eb4  sltu       $t1, $t0, $s1
00026eb8  bnez       $t1, 0x27074
00026ebc  nop        
00026ec0  lui        $s4, 0x11
00026ec4  addiu      $s4, $s4, 0xf84
00026ec8  jal        0x8a820
00026ecc  move       $a0, $s4
00026ed0  lbu        $t0, 4($s0)
00026ed4  addiu      $t1, $zero, 2
00026ed8  subu       $t0, $t0, $t1
00026edc  bnez       $t0, 0x2706c
00026ee0  nop        
00026ee4  lbu        $t0, 0x338($s0)
00026ee8  bnez       $t0, 0x26f18
00026eec  nop        
00026ef0  lbu        $t0, 5($s0)
00026ef4  sltiu      $t1, $t0, 2
00026ef8  bnez       $t1, 0x26f18
00026efc  nop        
00026f00  jal        0x8a8d0
00026f04  lw         $a0, 8($s0)
00026f08  bnez       $v0, 0x2706c
00026f0c  nop        
00026f10  addiu      $t0, $zero, 1
00026f14  sb         $t0, 0x338($s0)
00026f18  beqz       $s1, 0x2706c
00026f1c  nop        
00026f20  lbu        $t0, 5($s0)
00026f24  sltiu      $t1, $t0, 4
00026f28  beqz       $t1, 0x2706c
00026f2c  nop        
00026f30  lbu        $t0, 6($s0)
00026f34  sltiu      $t1, $t0, 0x19
00026f38  beqz       $t1, 0x2706c
00026f3c  nop        
00026f40  sll        $t0, $t0, 5
00026f44  addu       $t0, $t0, $s0
00026f48  addiu      $t0, $t0, 0x10
00026f4c  sw         $t0, 0x10($sp)
00026f50  lw         $t1, 0xc($t0)
00026f54  bnez       $t1, 0x2706c
00026f58  nop        
00026f5c  lw         $t1, 0x10($t0)
00026f60  andi       $t1, $t1, 0x12
00026f64  addiu      $t1, $t1, -2
00026f68  bnez       $t1, 0x2706c
00026f6c  nop        
00026f70  lw         $t2, 0x334($s0)
00026f74  sltiu      $t1, $t2, 0x1000
00026f78  beqz       $t1, 0x2706c
00026f7c  nop        
00026f80  lw         $t1, ($t0)
00026f84  beqz       $t1, 0x2706c
00026f88  nop        
00026f8c  sw         $t1, 0x330($s0)
00026f90  addu       $a0, $t1, $t2
00026f94  addiu      $t1, $zero, 0x1000
00026f98  subu       $s3, $t1, $t2
00026f9c  sltu       $t0, $s1, $s3
00026fa0  beqz       $t0, 0x26fac
00026fa4  nop        
00026fa8  move       $s3, $s1
00026fac  move       $a1, $s2
00026fb0  jal        0x85758
00026fb4  move       $a2, $s3
00026fb8  beqz       $v0, 0x2706c
00026fbc  nop        
00026fc0  addu       $s2, $s2, $s3
00026fc4  subu       $s1, $s1, $s3
00026fc8  lw         $t0, 0x334($s0)
00026fcc  addu       $t0, $t0, $s3
00026fd0  sw         $t0, 0x334($s0)
00026fd4  sltiu      $t1, $t0, 0x1000
00026fd8  bnez       $t1, 0x2706c
00026fdc  nop        
00026fe0  lw         $a1, 0x10($sp)
00026fe4  sw         $t0, 4($a1)
00026fe8  addiu      $t0, $zero, 1
00026fec  sw         $t0, 0xc($a1)
00026ff0  lbu        $t0, 5($s0)
00026ff4  addiu      $t0, $t0, 1
00026ff8  sb         $t0, 5($s0)
00026ffc  lw         $a0, 8($s0)
00027000  jal        0x8a8e0
00027004  addiu      $a2, $zero, 0x20
00027008  sw         $zero, 0x334($s0)
0002700c  move       $s3, $v0
00027010  beqz       $v0, 0x27040
00027014  nop        
00027018  lw         $t0, 0x10($sp)
0002701c  lw         $t1, 0x10($t0)
00027020  andi       $t1, $t1, 0x10
00027024  bnez       $t1, 0x27040
00027028  nop        
0002702c  sw         $zero, 0xc($t0)
00027030  lbu        $t0, 5($s0)
00027034  addiu      $t0, $t0, -1
00027038  b          0x2706c
0002703c  sb         $t0, 5($s0)
00027040  lbu        $t0, 6($s0)
00027044  addiu      $t0, $t0, 1
00027048  sltiu      $t1, $t0, 0x19
0002704c  bnez       $t1, 0x27058
00027050  nop        
00027054  move       $t0, $zero
00027058  sb         $t0, 6($s0)
0002705c  bnez       $s3, 0x2706c
00027060  nop        
00027064  b          0x26ed0
00027068  nop        
0002706c  jal        0x8a810
00027070  move       $a0, $s4
00027074  lw         $s2, 0x14($sp)
00027078  b          0x27088
0002707c  nop        
00027080  nop        
00027084  nop        
; completion ownership and underflow guard
00026484  lw         $a0, 0x1c($sp)
00026488  lw         $t0, 0xc($a0)
0002648c  beqz       $t0, 0x264e8
00026490  nop        
00026494  sw         $zero, 0xc($a0)
00026498  lw         $t0, 0x10($a0)
0002649c  addiu      $t1, $zero, -2
000264a0  and        $t0, $t0, $t1
000264a4  sw         $t0, 0x10($a0)
000264a8  lw         $t3, 0xf9c($s4)
000264ac  beqz       $t3, 0x264e8
000264b0  nop        
000264b4  lbu        $t1, 5($t3)
000264b8  beqz       $t1, 0x264e8
000264bc  nop        
000264c0  addiu      $t1, $t1, -1
000264c4  sb         $t1, 5($t3)
000264c8  bnez       $t1, 0x264e8
000264cc  nop        
000264d0  sb         $zero, 0x338($t3)
000264d4  jal        0x8a830
000264d8  lw         $a0, 8($t3)
000264dc  nop        
000264e0  nop        
000264e4  nop        
; attempt all 25 unprepare calls
00026ad4  nop        
; discard partial PCM on stop/reset
00026d64  sw         $zero, 0x334($s0)
