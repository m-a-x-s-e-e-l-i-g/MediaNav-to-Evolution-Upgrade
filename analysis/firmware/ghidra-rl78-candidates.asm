ram:0001dd c1 push AX
ram:0001de 511d mov ,0x1d
ram:0001e0 fe0200 call $! 0x1e5
ram:0001e5 61dd push PSW
ram:0001e7 717bfa DI
ram:0001ea 70 mov ,A
ram:0001eb cec0a5 mov 0xfffc0,0xa5
ram:0001ee 9ec4 mov 0xfffc4,A
ram:0001f0 7cff xor A,#0xff
ram:0001f2 9ec4 mov 0xfffc4,A
ram:0001f4 60 mov A,
ram:0001f5 9ec4 mov 0xfffc4,A
ram:0001f7 61cd pop PSW
ram:0001f9 d7 ret
ram:000351 c5 push DE
ram:000352 5404 mov ,0x4
ram:000354 ef03 br $ 0x359
ram:000359 fe81fe call $! 0x1dd
ram:0003c7 61cf SEL RB0
ram:0003c9 5100 mov ,0x0
ram:0003cb 718c mov1 CY,A.0x0
ram:0003cd 7109fe mov1 0xffffe.0x0,CY
ram:0003d0 cbf8d2fe movw SP,0xfed2
ram:0003d4 fc687d02 call !!0x27d68
ram:0003d8 f6 clrw AX
ram:0003d9 bf96bf movw !0xfbf96,AX
ram:0003dc bf80bf movw !0xfbf80,AX
ram:0003df bf84bf movw !0xfbf84,AX
ram:0003e2 e6 onew AX
ram:0003e3 bf82bf movw !0xfbf82,AX
ram:0003e6 309abf movw AX,0xbf9a
ram:0003e9 bf98bf movw !0xfbf98,AX
ram:0003ec 53c0 mov ,0xc0
ram:0003ee f6 clrw AX
ram:0003ef 93 dec 
ram:0003f0 93 dec 
ram:0003f1 5820fe movw !0xffe20[B],AX
ram:0003f4 dff9 bnz $ 0x3ef
ram:0003f6 4100 mov ES,0x0
ram:0003f8 36c26e movw HL,0x6ec2
ram:0003fb 34d2e3 movw DE,0xe3d2
ram:0003fe ef05 br $ 0x405
ram:000400 118b mov A,ES:[HL]
ram:000402 99 mov [DE],A
ram:000403 a7 incw HL
ram:000404 a5 incw DE
ram:000405 17 movw AX,HL
ram:000406 448e75 cmpw AX,0x758e
ram:000409 dff5 bnz $ 0x400
ram:00040b 368e75 movw HL,0x758e
ram:00040e 34b1ea movw DE,0xeab1
ram:000411 ef0a br $ 0x41d
ram:000413 4100 mov ES,0x0
ram:000415 118b mov A,ES:[HL]
ram:000417 410f mov ES,0xf
ram:000419 1199 mov ES:[DE],A
ram:00041b a7 incw HL
ram:00041c a5 incw DE
ram:00041d 17 movw AX,HL
ram:00041e 448e75 cmpw AX,0x758e
ram:000421 dff0 bnz $ 0x413
ram:000423 36babf movw HL,0xbfba
ram:000426 30d2e3 movw AX,0xe3d2
ram:000429 ef04 br $ 0x42f
ram:00042b cc0000 mov [HL + 0x0],0x0
ram:00042e a7 incw HL
ram:00042f 47 cmpw AX,HL
ram:000430 dff9 bnz $ 0x42b
ram:000432 410f mov ES,0xf
ram:000434 36b1ea movw HL,0xeab1
ram:000437 30b1ea movw AX,0xeab1
ram:00043a ef05 br $ 0x441
ram:00043c 11cc0000 mov ES:[HL + 0x0],0x0
ram:000440 a7 incw HL
ram:000441 47 cmpw AX,HL
ram:000442 dff8 bnz $ 0x43c
ram:000444 4100 mov ES,0x0
ram:000446 368e75 movw HL,0x758e
ram:000449 34b1ea movw DE,0xeab1
ram:00044c ef05 br $ 0x453
ram:00044e 118b mov A,ES:[HL]
ram:000450 99 mov [DE],A
ram:000451 a7 incw HL
ram:000452 a5 incw DE
ram:000453 17 movw AX,HL
ram:000454 448e75 cmpw AX,0x758e
ram:000457 dff5 bnz $ 0x44e
ram:000459 36b1ea movw HL,0xeab1
ram:00045c 30b1ea movw AX,0xeab1
ram:00045f ef04 br $ 0x465
ram:000461 cc0000 mov [HL + 0x0],0x0
ram:000464 a7 incw HL
ram:000465 47 cmpw AX,HL
ram:000466 dff9 bnz $ 0x461
ram:000468 fc347f00 call !!0x7f34
ram:00046c f6 clrw AX
ram:00046d fc697d02 call !!0x27d69
ram:000471 effe br $ 0x471
ram:000473 61dd push PSW
ram:000475 717bfa DI
ram:000478 bef0 movw 0xffff0,AX
ram:00047a add8 movw AX,0xffdf8
ram:00047c bef2 movw 0xffff2,AX
ram:00047e 00 nop
ram:00047f aef6 movw AX,0xffff6
ram:000481 61cd pop PSW
ram:000483 d7 ret
ram:000650 06da addw AX,0xffdfa
ram:000652 bdda movw 0xffdfa,AX
ram:000654 addc movw AX,0xffdfc
ram:000656 06d8 addw AX,0xffdf8
ram:000658 bdd8 movw 0xffdf8,AX
ram:00065a 61d8 sknc
ram:00065c a6da _incw 0xffdfa
ram:00065e d7 ret
ram:000671 d1 cmp0 A
ram:000672 dd17 bz $ 0x68b
ram:000674 c1 push AX
ram:000675 c3 push BC
ram:000676 dad8 movw BC,0xffdf8
ram:000678 9dd8 mov 0xffdf8,A
ram:00067a adda movw AX,0xffdfa
ram:00067c 311c shlw BC,0x1
ram:00067e 61ee rolwc AX,1
ram:000680 b4d8 dec 0xffdf8
ram:000682 dff8 bnz $ 0x67c
ram:000684 bdda movw 0xffdfa,AX
ram:000686 13 movw AX,BC
ram:000687 bdd8 movw 0xffdf8,AX
ram:000689 c2 pop BC
ram:00068a c0 pop AX
ram:00068b d7 ret
ram:00068c d1 cmp0 A
ram:00068d dd1b bz $ 0x6aa
ram:00068f c1 push AX
ram:000690 c3 push BC
ram:000691 dada movw BC,0xffdfa
ram:000693 9dda mov 0xffdfa,A
ram:000695 add8 movw AX,0xffdf8
ram:000697 311e shrw AX,0x1
ram:000699 33 xchw AX,BC
ram:00069a 311e shrw AX,0x1
ram:00069c 33 xchw AX,BC
ram:00069d 71f9 mov1 A.0x7,CY
ram:00069f b4da dec 0xffdfa
ram:0006a1 dff4 bnz $ 0x697
ram:0006a3 bdd8 movw 0xffdf8,AX
ram:0006a5 13 movw AX,BC
ram:0006a6 bdda movw 0xffdfa,AX
ram:0006a8 c2 pop BC
ram:0006a9 c0 pop AX
ram:0006aa d7 ret
ram:000d3e a2d2e3 incw !0xfe3d2
ram:000d41 61fc reti
ram:000d43 c1 push AX
ram:000d44 c3 push BC
ram:000d45 c7 push HL
ram:000d46 adde movw AX,0xffdfe
ram:000d48 c1 push AX
ram:000d49 addc movw AX,0xffdfc
ram:000d4b c1 push AX
ram:000d4c adda movw AX,0xffdfa
ram:000d4e c1 push AX
ram:000d4f add8 movw AX,0xffdf8
ram:000d51 c1 push AX
ram:000d52 afee01 movw AX,!0xf01ee
ram:000d55 f1 clrb A
ram:000d56 08 xch A,X
ram:000d57 5c01 and A,#0x1
ram:000d59 08 xch A,X
ram:000d5a 6168 or A,
ram:000d5c dd09 bz $ 0xd67
ram:000d5e f6 clrw AX
ram:000d5f bfdae3 movw !0xfe3da,AX
ram:000d62 bfdce3 movw !0xfe3dc,AX
ram:000d65 ef36 br $ 0xd9d
ram:000d67 fb7eff movw HL,!0xfff7e
ram:000d6a 17 movw AX,HL
ram:000d6b 311e shrw AX,0x1
ram:000d6d 12 movw BC,AX
ram:000d6e 17 movw AX,HL
ram:000d6f 312e shrw AX,0x2
ram:000d71 03 addw AX,BC
ram:000d72 bdd8 movw 0xffdf8,AX
ram:000d74 f6 clrw AX
ram:000d75 bdda movw 0xffdfa,AX
ram:000d77 add8 movw AX,0xffdf8
ram:000d79 bddc movw 0xffdfc,AX
ram:000d7b adda movw AX,0xffdfa
ram:000d7d bdde movw 0xffdfe,AX
ram:000d7f afdae3 movw AX,!0xfe3da
ram:000d82 bdd8 movw 0xffdf8,AX
ram:000d84 afdce3 movw AX,!0xfe3dc
ram:000d87 bdda movw 0xffdfa,AX
ram:000d89 5102 mov ,0x2
ram:000d8b fd8c06 call !0xf068c
ram:000d8e adde movw AX,0xffdfe
ram:000d90 fd5006 call !0xf0650
ram:000d93 adda movw AX,0xffdfa
ram:000d95 bfdce3 movw !0xfe3dc,AX
ram:000d98 add8 movw AX,0xffdf8
ram:000d9a bfdae3 movw !0xfe3da,AX
ram:000d9d a2dee3 incw !0xfe3de
ram:000da0 afd2e3 movw AX,!0xfe3d2
ram:000da3 bfe0e3 movw !0xfe3e0,AX
ram:000da6 c0 pop AX
ram:000da7 bdd8 movw 0xffdf8,AX
ram:000da9 c0 pop AX
ram:000daa bdda movw 0xffdfa,AX
ram:000dac c0 pop AX
ram:000dad bddc movw 0xffdfc,AX
ram:000daf c0 pop AX
ram:000db0 bdde movw 0xffdfe,AX
ram:000db2 c6 pop HL
ram:000db3 c2 pop BC
ram:000db4 c0 pop AX
ram:000db5 61fc reti
ram:000db7 61fc reti
ram:000db9 e5d5e3 oneb !0xfe3d5
ram:000dbc 61fc reti
ram:000dbe e5e2e3 oneb !0xfe3e2
ram:000dc1 710be3 clr1 0xfffe3.0x0
ram:000dc4 710ae7 set1 0xfffe7.0x0
ram:000dc7 717b30 clr1 0xfff30.0x7
ram:000dca 61fc reti
ram:000dcc c1 push AX
ram:000dcd c3 push BC
ram:000dce c5 push DE
ram:000dcf c7 push HL
ram:000dd0 520c mov ,0xc
ram:000dd2 92 dec 
ram:000dd3 92 dec 
ram:000dd4 69d4fe movw AX,!0xffed4[C]
ram:000dd7 c1 push AX
ram:000dd8 dff8 bnz $ 0xdd2
ram:000dda 8efd mov A,ES
ram:000ddc 70 mov ,A
ram:000ddd 8efc mov A,CS
ram:000ddf c1 push AX
ram:000de0 fc9c8100 call !!0x819c
ram:000de4 c0 pop AX
ram:000de5 9efc mov CS,A
ram:000de7 60 mov A,
ram:000de8 9efd mov ES,A
ram:000dea 34d4fe movw DE,0xfed4
ram:000ded 5206 mov ,0x6
ram:000def c0 pop AX
ram:000df0 b9 movw [DE],AX
ram:000df1 a5 incw DE
ram:000df2 a5 incw DE
ram:000df3 92 dec 
ram:000df4 dff9 bnz $ 0xdef
ram:000df6 c6 pop HL
ram:000df7 c4 pop DE
ram:000df8 c2 pop BC
ram:000df9 c0 pop AX
ram:000dfa 61fc reti
ram:000dfc c1 push AX
ram:000dfd c3 push BC
ram:000dfe c5 push DE
ram:000dff c7 push HL
ram:000e00 520c mov ,0xc
ram:000e02 92 dec 
ram:000e03 92 dec 
ram:000e04 69d4fe movw AX,!0xffed4[C]
ram:000e07 c1 push AX
ram:000e08 dff8 bnz $ 0xe02
ram:000e0a 8efd mov A,ES
ram:000e0c 70 mov ,A
ram:000e0d 8efc mov A,CS
ram:000e0f c1 push AX
ram:000e10 fccd8100 call !!0x81cd
ram:000e14 c0 pop AX
ram:000e15 9efc mov CS,A
ram:000e17 60 mov A,
ram:000e18 9efd mov ES,A
ram:000e1a 34d4fe movw DE,0xfed4
ram:000e1d 5206 mov ,0x6
ram:000e1f c0 pop AX
ram:000e20 b9 movw [DE],AX
ram:000e21 a5 incw DE
ram:000e22 a5 incw DE
ram:000e23 92 dec 
ram:000e24 dff9 bnz $ 0xe1f
ram:000e26 c6 pop HL
ram:000e27 c4 pop DE
ram:000e28 c2 pop BC
ram:000e29 c0 pop AX
ram:000e2a 61fc reti
ram:000e2c c1 push AX
ram:000e2d c3 push BC
ram:000e2e c5 push DE
ram:000e2f c7 push HL
ram:000e30 520c mov ,0xc
ram:000e32 92 dec 
ram:000e33 92 dec 
ram:000e34 69d4fe movw AX,!0xffed4[C]
ram:000e37 c1 push AX
ram:000e38 dff8 bnz $ 0xe32
ram:000e3a 8efd mov A,ES
ram:000e3c 70 mov ,A
ram:000e3d 8efc mov A,CS
ram:000e3f c1 push AX
ram:000e40 fcb58200 call !!0x82b5
ram:000e44 c0 pop AX
ram:000e45 9efc mov CS,A
ram:000e47 60 mov A,
ram:000e48 9efd mov ES,A
ram:000e4a 34d4fe movw DE,0xfed4
ram:000e4d 5206 mov ,0x6
ram:000e4f c0 pop AX
ram:000e50 b9 movw [DE],AX
ram:000e51 a5 incw DE
ram:000e52 a5 incw DE
ram:000e53 92 dec 
ram:000e54 dff9 bnz $ 0xe4f
ram:000e56 c6 pop HL
ram:000e57 c4 pop DE
ram:000e58 c2 pop BC
ram:000e59 c0 pop AX
ram:000e5a 61fc reti
ram:000e8c c1 push AX
ram:000e8d c3 push BC
ram:000e8e c5 push DE
ram:000e8f c7 push HL
ram:000e90 520c mov ,0xc
ram:000e92 92 dec 
ram:000e93 92 dec 
ram:000e94 69d4fe movw AX,!0xffed4[C]
ram:000e97 c1 push AX
ram:000e98 dff8 bnz $ 0xe92
ram:000e9a 8efd mov A,ES
ram:000e9c 70 mov ,A
ram:000e9d 8efc mov A,CS
ram:000e9f c1 push AX
ram:000ea0 af6201 movw AX,!0xf0162
ram:000ea3 f1 clrb A
ram:000ea4 08 xch A,X
ram:000ea5 5c07 and A,#0x7
ram:000ea7 76 mov ,A
ram:000ea8 17 movw AX,HL
ram:000ea9 f1 clrb A
ram:000eaa bf6601 movw !0xf0166,AX
ram:000ead 17 movw AX,HL
ram:000eae f1 clrb A
ram:000eaf c1 push AX
ram:000eb0 8e46 mov A,0xfff46
ram:000eb2 318e shrw AX,0x8
ram:000eb4 c1 push AX
ram:000eb5 f6 clrw AX
ram:000eb6 fcb64d01 call !!0x14db6
ram:000eba 1004 addw SP,0x4
ram:000ebc c0 pop AX
ram:000ebd 9efc mov CS,A
ram:000ebf 60 mov A,
ram:000ec0 9efd mov ES,A
ram:000ec2 34d4fe movw DE,0xfed4
ram:000ec5 5206 mov ,0x6
ram:000ec7 c0 pop AX
ram:000ec8 b9 movw [DE],AX
ram:000ec9 a5 incw DE
ram:000eca a5 incw DE
ram:000ecb 92 dec 
ram:000ecc dff9 bnz $ 0xec7
ram:000ece c6 pop HL
ram:000ecf c4 pop DE
ram:000ed0 c2 pop BC
ram:000ed1 c0 pop AX
ram:000ed2 61fc reti
ram:000ed4 c1 push AX
ram:000ed5 c3 push BC
ram:000ed6 c5 push DE
ram:000ed7 c7 push HL
ram:000ed8 520c mov ,0xc
ram:000eda 92 dec 
ram:000edb 92 dec 
ram:000edc 69d4fe movw AX,!0xffed4[C]
ram:000edf c1 push AX
ram:000ee0 dff8 bnz $ 0xeda
ram:000ee2 8efd mov A,ES
ram:000ee4 70 mov ,A
ram:000ee5 8efc mov A,CS
ram:000ee7 c1 push AX
ram:000ee8 f6 clrw AX
ram:000ee9 c1 push AX
ram:000eea 8e4a mov A,0xfff4a
ram:000eec 318e shrw AX,0x8
ram:000eee c1 push AX
ram:000eef e6 onew AX
ram:000ef0 fcb64d01 call !!0x14db6
ram:000ef4 1004 addw SP,0x4
ram:000ef6 c0 pop AX
ram:000ef7 9efc mov CS,A
ram:000ef9 60 mov A,
ram:000efa 9efd mov ES,A
ram:000efc 34d4fe movw DE,0xfed4
ram:000eff 5206 mov ,0x6
ram:000f01 c0 pop AX
ram:000f02 b9 movw [DE],AX
ram:000f03 a5 incw DE
ram:000f04 a5 incw DE
ram:000f05 92 dec 
ram:000f06 dff9 bnz $ 0xf01
ram:000f08 c6 pop HL
ram:000f09 c4 pop DE
ram:000f0a c2 pop BC
ram:000f0b c0 pop AX
ram:000f0c 61fc reti
ram:000f0e c1 push AX
ram:000f0f c5 push DE
ram:000f10 f6 clrw AX
ram:000f11 42d8c8 cmpw AX,!0xfc8d8
ram:000f14 dd0f bz $ 0xf25
ram:000f16 afd6c8 movw AX,!0xfc8d6
ram:000f19 a2d6c8 incw !0xfc8d6
ram:000f1c 14 movw DE,AX
ram:000f1d 89 mov A,[DE]
ram:000f1e 9e44 mov 0xfff44,A
ram:000f20 b2d8c8 decw !0xfc8d8
ram:000f23 ef03 br $ 0xf28
ram:000f25 f5dac8 clrb !0xfc8da
ram:000f28 c4 pop DE
ram:000f29 c0 pop AX
ram:000f2a 61fc reti
ram:000f2c c1 push AX
ram:000f2d c5 push DE
ram:000f2e f6 clrw AX
ram:000f2f 421ec9 cmpw AX,!0xfc91e
ram:000f32 dd15 bz $ 0xf49
ram:000f34 717ae5 set1 0xfffe5.0x7
ram:000f37 af1cc9 movw AX,!0xfc91c
ram:000f3a a21cc9 incw !0xfc91c
ram:000f3d 14 movw DE,AX
ram:000f3e 89 mov A,[DE]
ram:000f3f 9e48 mov 0xfff48,A
ram:000f41 b21ec9 decw !0xfc91e
ram:000f44 717be5 clr1 0xfffe5.0x7
ram:000f47 ef03 br $ 0xf4c
ram:000f49 f520c9 clrb !0xfc920
ram:000f4c c4 pop DE
ram:000f4d c0 pop AX
ram:000f4e 61fc reti
ram:000f50 c1 push AX
ram:000f51 c7 push HL
ram:000f52 2004 subw SP,0x4
ram:000f54 fbf8ff movw HL,!0xffff8
ram:000f57 ae4a movw AX,0xfff4a
ram:000f59 bc02 movw [HL + 0x2],AX
ram:000f5b af4602 movw AX,!0xf0246
ram:000f5e f1 clrb A
ram:000f5f 08 xch A,X
ram:000f60 5c07 and A,#0x7
ram:000f62 9c01 mov [HL + 0x1],A
ram:000f64 af4802 movw AX,!0xf0248
ram:000f67 08 xch A,X
ram:000f68 6c07 or A,#0x7
ram:000f6a 08 xch A,X
ram:000f6b bf4802 movw !0xf0248,AX
ram:000f6e 1004 addw SP,0x4
ram:000f70 c6 pop HL
ram:000f71 c0 pop AX
ram:000f72 61fc reti
ram:000f74 c1 push AX
ram:000f75 c3 push BC
ram:000f76 c5 push DE
ram:000f77 c7 push HL
ram:000f78 520c mov ,0xc
ram:000f7a 92 dec 
ram:000f7b 92 dec 
ram:000f7c 69d4fe movw AX,!0xffed4[C]
ram:000f7f c1 push AX
ram:000f80 dff8 bnz $ 0xf7a
ram:000f82 8efd mov A,ES
ram:000f84 70 mov ,A
ram:000f85 8efc mov A,CS
ram:000f87 c1 push AX
ram:000f88 200e subw SP,0xe
ram:000f8a fbf8ff movw HL,!0xffff8
ram:000f8d aff6e8 movw AX,!0xfe8f6
ram:000f90 08 xch A,X
ram:000f91 5cf8 and A,#0xf8
ram:000f93 08 xch A,X
ram:000f94 bc0c movw [HL + 0xc],AX
ram:000f96 cc0a01 mov [HL + 0xa],0x1
ram:000f99 717afa EI
ram:000f9c 8ffce8 mov A,!0xfe8fc
ram:000f9f d1 cmp0 A
ram:000fa0 dd36 bz $ 0xfd8
ram:000fa2 51c0 mov ,0xc0
ram:000fa4 5b09 and A,0xffe29
ram:000fa6 72 mov ,A
ram:000fa7 e1 oneb A
ram:000fa8 5b0a and A,0xffe2a
ram:000faa 616a or A,
ram:000fac 318e shrw AX,0x8
ram:000fae bc08 movw [HL + 0x8],AX
ram:000fb0 9c0b mov [HL + 0xb],A
ram:000fb2 8c0b mov A,[HL + 0xb]
ram:000fb4 4c0d cmp A,#0xd
ram:000fb6 de20 bnc $ 0xfd8
ram:000fb8 51c0 mov ,0xc0
ram:000fba 5b09 and A,0xffe29
ram:000fbc 72 mov ,A
ram:000fbd e1 oneb A
ram:000fbe 5b0a and A,0xffe2a
ram:000fc0 616a or A,
ram:000fc2 318e shrw AX,0x8
ram:000fc4 bc06 movw [HL + 0x6],AX
ram:000fc6 ac08 movw AX,[HL + 0x8]
ram:000fc8 614906 cmpw AX,[HL + 0x6]
ram:000fcb dd06 bz $ 0xfd3
ram:000fcd cc0a00 mov [HL + 0xa],0x0
ram:000fd0 cc0b14 mov [HL + 0xb],0x14
ram:000fd3 61590b inc [HL + 0xb]
ram:000fd6 efda br $ 0xfb2
ram:000fd8 ac08 movw AX,[HL + 0x8]
ram:000fda bf06e9 movw !0xfe906,AX
ram:000fdd 8c0a mov A,[HL + 0xa]
ram:000fdf d1 cmp0 A
ram:000fe0 61f8 sknz
ram:000fe2 edc511 _br !0xf11c5
ram:000fe5 8ffce8 mov A,!0xfe8fc
ram:000fe8 320002 movw BC,0x200
ram:000feb f0 clrb X
ram:000fec d1 cmp0 A
ram:000fed dd53 bz $ 0x1042
ram:000fef 91 dec 
ram:000ff0 dd60 bz $ 0x1052
ram:000ff2 91 dec 
ram:000ff3 61f8 sknz
ram:000ff5 ed8710 _br !0xf1087
ram:000ff8 91 dec 
ram:000ff9 61f8 sknz
ram:000ffb ed0311 _br !0xf1103
ram:000ffe 91 dec 
ram:000fff 23 subw AX,BC
ram:001000 61d8 sknc
ram:001002 edbe11 _br !0xf11be
ram:001005 d1 cmp0 A
ram:001006 61f8 sknz
ram:001008 ed0311 _br !0xf1103
ram:00100b 91 dec 
ram:00100c 23 subw AX,BC
ram:00100d 61d8 sknc
ram:00100f edbe11 _br !0xf11be
ram:001012 d1 cmp0 A
ram:001013 61f8 sknz
ram:001015 ed0311 _br !0xf1103
ram:001018 91 dec 
ram:001019 23 subw AX,BC
ram:00101a 61d8 sknc
ram:00101c edbe11 _br !0xf11be
ram:00101f d1 cmp0 A
ram:001020 61f8 sknz
ram:001022 ed0311 _br !0xf1103
ram:001025 91 dec 
ram:001026 23 subw AX,BC
ram:001027 61d8 sknc
ram:001029 edbe11 _br !0xf11be
ram:00102c d1 cmp0 A
ram:00102d 61f8 sknz
ram:00102f ed0311 _br !0xf1103
ram:001032 91 dec 
ram:001033 23 subw AX,BC
ram:001034 61d8 sknc
ram:001036 edbe11 _br !0xf11be
ram:001039 d1 cmp0 A
ram:00103a 61f8 sknz
ram:00103c ed0311 _br !0xf1103
ram:00103f edc511 br !0xf11c5
ram:001042 711b2a clr1 0xfff2a.0x1
ram:001045 71120a set1 0xffe2a.0x1
ram:001048 8ffce8 mov A,!0xfe8fc
ram:00104b 81 inc 
ram:00104c 9ffce8 mov !0xfe8fc,A
ram:00104f edc511 br !0xf11c5
ram:001052 51c0 mov ,0xc0
ram:001054 5f06e9 and A,!0xfe906
ram:001057 318e shrw AX,0x8
ram:001059 313e shrw AX,0x3
ram:00105b bffee8 movw !0xfe8fe,AX
ram:00105e e1 oneb A
ram:00105f 5f06e9 and A,!0xfe906
ram:001062 318e shrw AX,0x8
ram:001064 315d shlw AX,0x5
ram:001066 6fffe8 or A,!0xfe8ff
ram:001069 08 xch A,X
ram:00106a 6ffee8 or A,!0xfe8fe
ram:00106d 08 xch A,X
ram:00106e bffee8 movw !0xfe8fe,AX
ram:001071 71130a clr1 0xffe2a.0x1
ram:001074 711a2a set1 0xfff2a.0x1
ram:001077 712b2a clr1 0xfff2a.0x2
ram:00107a 71220a set1 0xffe2a.0x2
ram:00107d 8ffce8 mov A,!0xfe8fc
ram:001080 81 inc 
ram:001081 9ffce8 mov !0xfe8fc,A
ram:001084 edc511 br !0xf11c5
ram:0011c5 cc0100 mov [HL + 0x1],0x0
ram:0011c8 eb00e4 movw DE,!0xfe400
ram:0011cb 8a0a mov A,[DE + 0xa]
ram:0011cd 9efc mov CS,A
ram:0011cf aa08 movw AX,[DE + 0x8]
ram:0011d1 61ca call AX
ram:0011d3 62 mov A,
ram:0011d4 4c03 cmp A,#0x3
ram:0011d6 61e8 skz
ram:0011d8 ed8512 _br !0xf1285
ram:0011db af12e4 movw AX,!0xfe412
ram:0011de e7 onew BC
ram:0011df c3 push BC
ram:0011e0 12 movw BC,AX
ram:0011e1 17 movw AX,HL
ram:0011e2 a1 incw AX
ram:0011e3 c1 push AX
ram:0011e4 491600 mov A,!0xf0016[BC]
ram:0011e7 9dd4 mov 0xffdf4,A
ram:0011e9 791400 movw AX,!0xf0014[BC]
ram:0011ec c1 push AX
ram:0011ed 8dd4 mov A,0xffdf4
ram:0011ef 9dd6 mov 0xffdf6,A
ram:0011f1 c0 pop AX
ram:0011f2 14 movw DE,AX
ram:0011f3 304100 movw AX,0x41
ram:0011f6 f7 clrw BC
ram:0011f7 c1 push AX
ram:0011f8 8dd6 mov A,0xffdf6
ram:0011fa 9efc mov CS,A
ram:0011fc c0 pop AX
ram:0011fd 61ea call DE
ram:001201 8c01 mov A,[HL + 0x1]
ram:001203 d1 cmp0 A
ram:001204 df20 bnz $ 0x1226
ram:001206 8d07 mov A,0xffe27
ram:001208 7cff xor A,#0xff
ram:00120a 5c60 and A,#0x60
ram:00120c 315a shr A,0x5
ram:00120e 72 mov ,A
ram:00120f 8d03 mov A,0xffe23
ram:001211 7cff xor A,#0xff
ram:001213 5c04 and A,#0x4
ram:001215 6162 or ,A
ram:001217 62 mov A,
ram:001218 5c07 and A,#0x7
ram:00121a 72 mov ,A
ram:00121b 8c0c mov A,[HL + 0xc]
ram:00121d 616a or A,
ram:00121f 70 mov ,A
ram:001220 8c0d mov A,[HL + 0xd]
ram:001222 bc0c movw [HL + 0xc],AX
ram:001224 ef5f br $ 0x1285
ram:001226 f1 clrb A
ram:001227 716407 mov1 CY,0xffe27.0x6
ram:00122a 61dc rolc A,1
ram:00122c 9c05 mov [HL + 0x5],A
ram:00122e f1 clrb A
ram:00122f 715407 mov1 CY,0xffe27.0x5
ram:001232 61dc rolc A,1
ram:001234 9c04 mov [HL + 0x4],A
ram:001236 3119 shl A,0x1
ram:001238 6e05 or A,[HL + 0x5]
ram:00123a 9c03 mov [HL + 0x3],A
ram:00123c 8c04 mov A,[HL + 0x4]
ram:00123e d1 cmp0 A
ram:00123f df06 bnz $ 0x1247
ram:001241 8c03 mov A,[HL + 0x3]
ram:001243 7c01 xor A,#0x1
ram:001245 9c03 mov [HL + 0x3],A
ram:001247 8c03 mov A,[HL + 0x3]
ram:001249 2f08e9 sub A,!0xfe908
ram:00124c 5c03 and A,#0x3
ram:00124e 9c02 mov [HL + 0x2],A
ram:001250 91 dec 
ram:001251 df0b bnz $ 0x125e
ram:001253 8c0c mov A,[HL + 0xc]
ram:001255 6c01 or A,#0x1
ram:001257 70 mov ,A
ram:001258 8c0d mov A,[HL + 0xd]
ram:00125a bc0c movw [HL + 0xc],AX
ram:00125c ef0f br $ 0x126d
ram:00125e 8c02 mov A,[HL + 0x2]
ram:001260 4c03 cmp A,#0x3
ram:001262 df09 bnz $ 0x126d
ram:001264 8c0c mov A,[HL + 0xc]
ram:001266 6c02 or A,#0x2
ram:001268 70 mov ,A
ram:001269 8c0d mov A,[HL + 0xd]
ram:00126b bc0c movw [HL + 0xc],AX
ram:00126d 8c03 mov A,[HL + 0x3]
ram:00126f 9f08e9 mov !0xfe908,A
ram:001272 31240303 bf 0xffe23.0x2,$ 0x1277
ram:001276 f1 clrb A
ram:001277 ef02 br $ 0x127b
ram:00127b 318f sarw AX,0x8
ram:00127d 6e0d or A,[HL + 0xd]
ram:00127f 08 xch A,X
ram:001280 6e0c or A,[HL + 0xc]
ram:001282 08 xch A,X
ram:001283 bc0c movw [HL + 0xc],AX
ram:001285 aff8e8 movw AX,!0xfe8f8
ram:001288 61490c cmpw AX,[HL + 0xc]
ram:00128b dd53 bz $ 0x12e0
ram:00128d ac0c movw AX,[HL + 0xc]
ram:00128f 42f6e8 cmpw AX,!0xfe8f6
ram:001292 df47 bnz $ 0x12db
ram:001294 aff8e8 movw AX,!0xfe8f8
ram:001297 7e0d xor A,[HL + 0xd]
ram:001299 08 xch A,X
ram:00129a 7e0c xor A,[HL + 0xc]
ram:00129c 08 xch A,X
ram:00129d bffae8 movw !0xfe8fa,AX
ram:0012a0 aff8e8 movw AX,!0xfe8f8
ram:0012a3 f1 clrb A
ram:0012a4 08 xch A,X
ram:0012a5 5c10 and A,#0x10
ram:0012a7 08 xch A,X
ram:0012a8 6168 or A,
ram:0012aa df0c bnz $ 0x12b8
ram:0012ac aff8e8 movw AX,!0xfe8f8
ram:0012af f1 clrb A
ram:0012b0 08 xch A,X
ram:0012b1 5c08 and A,#0x8
ram:0012b3 08 xch A,X
ram:0012b4 6168 or A,
ram:0012b6 dd1c bz $ 0x12d4
ram:0012b8 5118 mov ,0x18
ram:0012ba 5e0c and A,[HL + 0xc]
ram:0012bc 318e shrw AX,0x8
ram:0012be 441800 cmpw AX,0x18
ram:0012c1 df11 bnz $ 0x12d4
ram:0012c3 5018 mov ,0x18
ram:0012c5 42f8e8 cmpw AX,!0xfe8f8
ram:0012c8 dd0a bz $ 0x12d4
ram:0012ca affae8 movw AX,!0xfe8fa
ram:0012cd 08 xch A,X
ram:0012ce 6c18 or A,#0x18
ram:0012d0 08 xch A,X
ram:0012d1 bffae8 movw !0xfe8fa,AX
ram:0012d4 ac0c movw AX,[HL + 0xc]
ram:0012d6 bff8e8 movw !0xfe8f8,AX
ram:0012d9 ef05 br $ 0x12e0
ram:0012db ac0c movw AX,[HL + 0xc]
ram:0012dd bff6e8 movw !0xfe8f6,AX
ram:0012e0 100e addw SP,0xe
ram:0012e2 c0 pop AX
ram:0012e3 9efc mov CS,A
ram:0012e5 60 mov A,
ram:0012e6 9efd mov ES,A
ram:0012e8 34d4fe movw DE,0xfed4
ram:0012eb 5206 mov ,0x6
ram:0012ed c0 pop AX
ram:0012ee b9 movw [DE],AX
ram:0012ef a5 incw DE
ram:0012f0 a5 incw DE
ram:0012f1 92 dec 
ram:0012f2 dff9 bnz $ 0x12ed
ram:0012f4 c6 pop HL
ram:0012f5 c4 pop DE
ram:0012f6 c2 pop BC
ram:0012f7 c0 pop AX
ram:0012f8 61fc reti
ram:0012fa c1 push AX
ram:0012fb af3201 movw AX,!0xf0132
ram:0012fe f1 clrb A
ram:0012ff 08 xch A,X
ram:001300 5c02 and A,#0x2
ram:001302 08 xch A,X
ram:001303 440200 cmpw AX,0x2
ram:001306 df08 bnz $ 0x1310
ram:001308 e6 onew AX
ram:001309 a1 incw AX
ram:00130a bf3601 movw !0xf0136,AX
ram:00130d e576e9 oneb !0xfe976
ram:001310 e577e9 oneb !0xfe977
ram:001313 c0 pop AX
ram:001314 61fc reti
ram:00131a 717bbe clr1 0xfffbe.0x7
ram:00131d d7 ret
ram:001405 87 inc 
ram:001406 ac08 movw AX,[HL + 0x8]
ram:001408 97 dec 
ram:001409 6168 or A,
ram:00140b 61f8 sknz
ram:00140d eed400 _br $! 0x14e4
ram:001410 87 inc 
ram:001411 ac08 movw AX,[HL + 0x8]
ram:001413 97 dec 
ram:001414 440101 cmpw AX,0x101
ram:001417 dc08 bc $ 0x1421
ram:001419 f0 clrb X
ram:00141a e1 oneb A
ram:00141b 87 inc 
ram:00141c bc0a movw [HL + 0xa],AX
ram:00141e 97 dec 
ram:00141f ef08 br $ 0x1429
ram:001421 87 inc 
ram:001422 ac08 movw AX,[HL + 0x8]
ram:001424 97 dec 
ram:001425 87 inc 
ram:001426 bc0a movw [HL + 0xa],AX
ram:001428 97 dec 
ram:001429 87 inc 
ram:00142a ac08 movw AX,[HL + 0x8]
ram:00142c 97 dec 
ram:00142d 12 movw BC,AX
ram:00142e 87 inc 
ram:00142f ac0a movw AX,[HL + 0xa]
ram:001431 97 dec 
ram:001432 33 xchw AX,BC
ram:001433 23 subw AX,BC
ram:001434 33 xchw AX,BC
ram:001435 13 movw AX,BC
ram:001436 87 inc 
ram:001437 bc08 movw [HL + 0x8],AX
ram:001439 97 dec 
ram:00143a f6 clrw AX
ram:00143b bb movw [HL],AX
ram:00143c bc02 movw [HL + 0x2],AX
ram:00143e 87 inc 
ram:00143f ac0a movw AX,[HL + 0xa]
ram:001441 97 dec 
ram:001442 bddc movw 0xffdfc,AX
ram:001444 f6 clrw AX
ram:001445 bdde movw 0xffdfe,AX
ram:001447 ac02 movw AX,[HL + 0x2]
ram:001449 46de cmpw AX,0xffdfe
ram:00144b ab movw AX,[HL]
ram:00144c 61f8 sknz
ram:00144e 46dc _cmpw AX,0xffdfc
ram:001450 de1f bnc $ 0x1471
ram:001452 ac04 movw AX,[HL + 0x4]
ram:001454 a1 incw AX
ram:001455 bc04 movw [HL + 0x4],AX
ram:001457 b1 decw AX
ram:001458 14 movw DE,AX
ram:001459 89 mov A,[DE]
ram:00145a 72 mov ,A
ram:00145b ab movw AX,[HL]
ram:00145c 07 addw AX,HL
ram:00145d 040700 addw AX,0x7
ram:001460 14 movw DE,AX
ram:001461 62 mov A,
ram:001462 99 mov [DE],A
ram:001463 617900 incw [HL + 0x0]
ram:001466 f6 clrw AX
ram:001467 614900 cmpw AX,[HL + 0x0]
ram:00146a dfd2 bnz $ 0x143e
ram:00146c 617902 incw [HL + 0x2]
ram:00146f efcd br $ 0x143e
ram:001471 f6 clrw AX
ram:001472 614902 cmpw AX,[HL + 0x2]
ram:001475 df04 bnz $ 0x147b
ram:001477 90 dec 
ram:00147b dc17 bc $ 0x1494
ram:00147d ab movw AX,[HL]
ram:00147e 07 addw AX,HL
ram:00147f 040700 addw AX,0x7
ram:001482 14 movw DE,AX
ram:001483 ca0000 mov [DE + 0x0],0x0
ram:001486 617900 incw [HL + 0x0]
ram:001489 f6 clrw AX
ram:00148a 614900 cmpw AX,[HL + 0x0]
ram:00148d dfe2 bnz $ 0x1471
ram:00148f 617902 incw [HL + 0x2]
ram:001492 efdd br $ 0x1471
ram:001494 87 inc 
ram:001495 ac0a movw AX,[HL + 0xa]
ram:001497 97 dec 
ram:001498 040400 addw AX,0x4
ram:00149b b1 decw AX
ram:00149c 312e shrw AX,0x2
ram:00149e f1 clrb A
ram:00149f c1 push AX
ram:0014a0 87 inc 
ram:0014a1 ac0e movw AX,[HL + 0xe]
ram:0014a3 97 dec 
ram:0014a4 12 movw BC,AX
ram:0014a5 87 inc 
ram:0014a6 ac0c movw AX,[HL + 0xc]
ram:0014a8 97 dec 
ram:0014a9 fc510300 call !!0x351
ram:0014e4 fc1a1300 call !!0x131a
ram:0075d0 ceabac mov 0xfffab,0xac
ram:0075d3 d7 ret
ram:0075d4 c7 push HL
ram:0075d5 2004 subw SP,0x4
ram:0075d7 fbf8ff movw HL,!0xffff8
ram:0075da f400 clrb 0xffe20
ram:0075dc f401 clrb 0xffe21
ram:0075de f403 clrb 0xffe23
ram:0075e0 f404 clrb 0xffe24
ram:0075e2 f405 clrb 0xffe25
ram:0075e4 f406 clrb 0xffe26
ram:0075e6 f407 clrb 0xffe27
ram:0075e8 f408 clrb 0xffe28
ram:0075ea f409 clrb 0xffe29
ram:0075ec f40a clrb 0xffe2a
ram:0075ee f40c clrb 0xffe2c
ram:0075f0 f40d clrb 0xffe2d
ram:0075f2 f40e clrb 0xffe2e
ram:0075f4 f40f clrb 0xffe2f
ram:0075f6 ce20ff mov 0xfff20,0xff
ram:0075f9 ce21ff mov 0xfff21,0xff
ram:0075fc ce23ff mov 0xfff23,0xff
ram:0075ff ce24ff mov 0xfff24,0xff
ram:007602 ce25fd mov 0xfff25,0xfd
ram:007605 ce26ff mov 0xfff26,0xff
ram:007608 ce27ff mov 0xfff27,0xff
ram:00760b ce28ff mov 0xfff28,0xff
ram:00760e ce29ff mov 0xfff29,0xff
ram:007611 ce2aff mov 0xfff2a,0xff
ram:007614 ce2cff mov 0xfff2c,0xff
ram:007617 ce2eff mov 0xfff2e,0xff
ram:00761a ce2fff mov 0xfff2f,0xff
ram:00761d 71403f00 set1 !0xf003f.0x4
ram:007621 714a2f set1 0xfff2f.0x4
ram:007624 717306 clr1 0xffe26.0x7
ram:007627 717b26 clr1 0xfff26.0x7
ram:00762a 71003e00 set1 !0xf003e.0x0
ram:00762e 710a2e set1 0xfff2e.0x0
ram:007631 71603f00 set1 !0xf003f.0x6
ram:007635 716a2f set1 0xfff2f.0x6
ram:007638 717b2f clr1 0xfff2f.0x7
ram:00763b 71730f clr1 0xffe2f.0x7
ram:00763e 710b20 clr1 0xfff20.0x0
ram:007641 710300 clr1 0xffe20.0x0
ram:007644 00 nop
ram:007645 00 nop
ram:007646 00 nop
ram:007647 00 nop
ram:007648 00 nop
ram:007649 31440f03 bf 0xffe2f.0x4,$ 0x764e
ram:00764d ee8900 br $! 0x76d9
ram:007650 cea040 mov 0xfffa0,0x40
ram:007653 cea307 mov 0xfffa3,0x7
ram:007656 8f7000 mov A,!0xf0070
ram:007659 6c01 or A,#0x1
ram:00765b 9f7000 mov !0xf0070,A
ram:00765e 717ba1 clr1 0xfffa1.0x7
ram:007661 cc01ff mov [HL + 0x1],0xff
ram:007664 8ea2 mov A,0xfffa2
ram:007666 9b mov [HL],A
ram:007667 5e01 and A,[HL + 0x1]
ram:007669 9b mov [HL],A
ram:00766a 8b mov A,[HL]
ram:00766b 4e01 cmp A,[HL + 0x1]
ram:00766d dff5 bnz $ 0x7664
ram:00766f 717bfa DI
ram:007672 cff30005 mov !0xf00f3,0x5
ram:007676 00 nop
ram:007677 00 nop
ram:007678 717afa EI
ram:00767b 714aa4 set1 0xfffa4.0x4
ram:00767e 8f7000 mov A,!0xf0070
ram:007681 6c02 or A,#0x2
ram:007683 9f7000 mov !0xf0070,A
ram:007686 cff70090 mov !0xf00f7,0x90
ram:00768a 7100f700 set1 !0xf00f7.0x0
ram:00768e f6 clrw AX
ram:00768f bc02 movw [HL + 0x2],AX
ram:007691 ac02 movw AX,[HL + 0x2]
ram:007693 446109 cmpw AX,0x961
ram:007696 de06 bnc $ 0x769e
ram:007698 00 nop
ram:007699 617902 incw [HL + 0x2]
ram:00769c eff3 br $ 0x7691
ram:00769e c7 push HL
ram:00769f 36f600 movw HL,0xf6
ram:0076a2 71f4 mov1 CY,[HL].0x7
ram:0076a4 c6 pop HL
ram:0076a5 def7 bnc $ 0x769e
ram:0076a7 7120f700 set1 !0xf00f7.0x2
ram:0076ab c7 push HL
ram:0076ac 36f600 movw HL,0xf6
ram:0076af 71b4 mov1 CY,[HL].0x3
ram:0076b1 c6 pop HL
ram:0076b2 def7 bnc $ 0x76ab
ram:0076b4 8f7000 mov A,!0xf0070
ram:0076b7 5cfd and A,#0xfd
ram:0076b9 9f7000 mov !0xf0070,A
ram:0076bc 716aa1 set1 0xfffa1.0x6
ram:0076bf 716ba4 clr1 0xfffa4.0x6
ram:0076c2 8ea4 mov A,0xfffa4
ram:0076c4 5cf8 and A,#0xf8
ram:0076c6 9ea4 mov 0xfffa4,A
ram:0076c8 8ea4 mov A,0xfffa4
ram:0076ca 9ea4 mov 0xfffa4,A
ram:0076cc 710ba1 clr1 0xfffa1.0x0
ram:0076cf 8f7000 mov A,!0xf0070
ram:0076d2 5cfe and A,#0xfe
ram:0076d4 9f7000 mov !0xf0070,A
ram:0076d7 ef75 br $ 0x774e
ram:0076d9 f5a0ff clrb !0xfffa0
ram:0076dc 8f7000 mov A,!0xf0070
ram:0076df 6c01 or A,#0x1
ram:0076e1 9f7000 mov !0xf0070,A
ram:0076e4 717aa1 set1 0xfffa1.0x7
ram:0076e7 717bfa DI
ram:0076ea e5f300 oneb !0xf00f3
ram:0076ed 00 nop
ram:0076ee 00 nop
ram:0076ef 717afa EI
ram:0076f2 714ba4 clr1 0xfffa4.0x4
ram:0076f5 8f7000 mov A,!0xf0070
ram:0076f8 6c02 or A,#0x2
ram:0076fa 9f7000 mov !0xf0070,A
ram:0076fd cff70050 mov !0xf00f7,0x50
ram:007701 7100f700 set1 !0xf00f7.0x0
ram:007705 f6 clrw AX
ram:007706 bc02 movw [HL + 0x2],AX
ram:007708 ac02 movw AX,[HL + 0x2]
ram:00770a 446109 cmpw AX,0x961
ram:00770d de06 bnc $ 0x7715
ram:00770f 00 nop
ram:007710 617902 incw [HL + 0x2]
ram:007713 eff3 br $ 0x7708
ram:007715 c7 push HL
ram:007716 36f600 movw HL,0xf6
ram:007719 71f4 mov1 CY,[HL].0x7
ram:00771b c6 pop HL
ram:00771c def7 bnc $ 0x7715
ram:00771e 7120f700 set1 !0xf00f7.0x2
ram:007722 c7 push HL
ram:007723 36f600 movw HL,0xf6
ram:007726 71b4 mov1 CY,[HL].0x3
ram:007728 c6 pop HL
ram:007729 def7 bnc $ 0x7722
ram:00772b 8f7000 mov A,!0xf0070
ram:00772e 5cfd and A,#0xfd
ram:007730 9f7000 mov !0xf0070,A
ram:007733 716aa1 set1 0xfffa1.0x6
ram:007736 716ba4 clr1 0xfffa4.0x6
ram:007739 8ea4 mov A,0xfffa4
ram:00773b 5cf8 and A,#0xf8
ram:00773d 9ea4 mov 0xfffa4,A
ram:00773f 8ea4 mov A,0xfffa4
ram:007741 9ea4 mov 0xfffa4,A
ram:007743 710ba1 clr1 0xfffa1.0x0
ram:007746 8f7000 mov A,!0xf0070
ram:007749 5cfe and A,#0xfe
ram:00774b 9f7000 mov !0xf0070,A
ram:00774e 71483f00 clr1 !0xf003f.0x4
ram:007752 717a26 set1 0xfff26.0x7
ram:007755 f5d4e3 clrb !0xfe3d4
ram:007758 31020e04 bt 0xffe2e.0x0,$ 0x775e
ram:00775c 7140d4e3 set1 !0xfe3d4.0x4
ram:007760 31620f04 bt 0xffe2f.0x6,$ 0x7766
ram:007764 7100d4e3 set1 !0xfe3d4.0x0
ram:007768 71083e00 clr1 !0xf003e.0x0
ram:00776c 71683f00 clr1 !0xf003f.0x6
ram:007770 717a2f set1 0xfff2f.0x7
ram:007773 710a20 set1 0xfff20.0x0
ram:007776 7120f000 set1 !0xf00f0.0x2
ram:00777a 3010f8 movw AX,0xf810
ram:00777d bf3602 movw !0xf0236,AX
ram:007780 f6 clrw AX
ram:007781 90 dec 
ram:007782 bf3402 movw !0xf0234,AX
ram:007785 715ad6 set1 0xfffd6.0x5
ram:007788 715bd2 clr1 0xfffd2.0x5
ram:00778b 715bde clr1 0xfffde.0x5
ram:00778e 715bda clr1 0xfffda.0x5
ram:007791 e6 onew AX
ram:007792 bf1002 movw !0xf0210,AX
ram:007795 cb90bf5d movw 0xfff90,0x5dbf
ram:007799 af3e02 movw AX,!0xf023e
ram:00779c 08 xch A,X
ram:00779d 5cfe and A,#0xfe
ram:00779f 08 xch A,X
ram:0077a0 bf3e02 movw !0xf023e,AX
ram:0077a3 af3c02 movw AX,!0xf023c
ram:0077a6 08 xch A,X
ram:0077a7 5cfe and A,#0xfe
ram:0077a9 08 xch A,X
ram:0077aa bf3c02 movw !0xf023c,AX
ram:0077ad af3a02 movw AX,!0xf023a
ram:0077b0 08 xch A,X
ram:0077b1 5cfe and A,#0xfe
ram:0077b3 08 xch A,X
ram:0077b4 bf3a02 movw !0xf023a,AX
ram:0077b7 715bd2 clr1 0xfffd2.0x5
ram:0077ba 715bd6 clr1 0xfffd6.0x5
ram:0077bd af3202 movw AX,!0xf0232
ram:0077c0 08 xch A,X
ram:0077c1 6c01 or A,#0x1
ram:0077c3 08 xch A,X
ram:0077c4 bf3202 movw !0xf0232,AX
ram:0077c7 1004 addw SP,0x4
ram:0077c9 c6 pop HL
ram:0077ca 717afa EI
ram:0077cd d7 ret
ram:0077ce 717bfa DI
ram:0077d1 ce20ff mov 0xfff20,0xff
ram:0077d4 ce21ff mov 0xfff21,0xff
ram:0077d7 ce23ff mov 0xfff23,0xff
ram:0077da ce24ff mov 0xfff24,0xff
ram:0077dd ce25fd mov 0xfff25,0xfd
ram:0077e0 ce26ff mov 0xfff26,0xff
ram:0077e3 ce27ff mov 0xfff27,0xff
ram:0077e6 ce28ff mov 0xfff28,0xff
ram:0077e9 ce29ff mov 0xfff29,0xff
ram:0077ec ce2aff mov 0xfff2a,0xff
ram:0077ef ce2cff mov 0xfff2c,0xff
ram:0077f2 ce2eff mov 0xfff2e,0xff
ram:0077f5 ce2ffb mov 0xfff2f,0xfb
ram:0077f8 710b2e clr1 0xfff2e.0x0
ram:0077fb 717b2f clr1 0xfff2f.0x7
ram:0077fe 716b2f clr1 0xfff2f.0x6
ram:007801 710b20 clr1 0xfff20.0x0
ram:007804 714b2f clr1 0xfff2f.0x4
ram:007807 717b26 clr1 0xfff26.0x7
ram:00780a 712b21 clr1 0xfff21.0x2
ram:00780d 717b2a clr1 0xfff2a.0x7
ram:007810 716b2a clr1 0xfff2a.0x6
ram:007813 710b28 clr1 0xfff28.0x0
ram:007816 711b29 clr1 0xfff29.0x1
ram:007819 717b24 clr1 0xfff24.0x7
ram:00781c 714b24 clr1 0xfff24.0x4
ram:00781f f400 clrb 0xffe20
ram:007821 f401 clrb 0xffe21
ram:007823 f403 clrb 0xffe23
ram:007825 f404 clrb 0xffe24
ram:007827 f405 clrb 0xffe25
ram:007829 f406 clrb 0xffe26
ram:00782b f407 clrb 0xffe27
ram:00782d f408 clrb 0xffe28
ram:00782f f409 clrb 0xffe29
ram:007831 f40a clrb 0xffe2a
ram:007833 f40c clrb 0xffe2c
ram:007835 f40d clrb 0xffe2d
ram:007837 f40e clrb 0xffe2e
ram:007839 f40f clrb 0xffe2f
ram:00783b af3402 movw AX,!0xf0234
ram:00783e 08 xch A,X
ram:00783f 6c01 or A,#0x1
ram:007841 08 xch A,X
ram:007842 bf3402 movw !0xf0234,AX
ram:007845 715ad6 set1 0xfffd6.0x5
ram:007848 715bd2 clr1 0xfffd2.0x5
ram:00784b af4401 movw AX,!0xf0144
ram:00784e 08 xch A,X
ram:00784f 6c02 or A,#0x2
ram:007851 08 xch A,X
ram:007852 bf4401 movw !0xf0144,AX
ram:007855 716ae7 set1 0xfffe7.0x6
ram:007858 7148f000 clr1 !0xf00f0.0x4
ram:00785c af7401 movw AX,!0xf0174
ram:00785f 08 xch A,X
ram:007860 6c03 or A,#0x3
ram:007862 08 xch A,X
ram:007863 bf7401 movw !0xf0174,AX
ram:007866 af7a01 movw AX,!0xf017a
ram:007869 08 xch A,X
ram:00786a 5cfe and A,#0xfe
ram:00786c 08 xch A,X
ram:00786d bf7a01 movw !0xf017a,AX
ram:007870 717ad5 set1 0xfffd5.0x7
ram:007873 717bd1 clr1 0xfffd1.0x7
ram:007876 716ad5 set1 0xfffd5.0x6
ram:007879 716bd1 clr1 0xfffd1.0x6
ram:00787c 7138f100 clr1 !0xf00f1.0x3
ram:007880 f6 clrw AX
ram:007881 90 dec 
ram:007882 bff401 movw !0xf01f4,AX
ram:007885 f6 clrw AX
ram:007886 bffa01 movw !0xf01fa,AX
ram:007889 7118f000 clr1 !0xf00f0.0x1
ram:00788d 717b30 clr1 0xfff30.0x7
ram:007890 710ae7 set1 0xfffe7.0x0
ram:007893 710be3 clr1 0xfffe3.0x0
ram:007896 7178f000 clr1 !0xf00f0.0x7
ram:00789a f538ff clrb !0xfff38
ram:00789d f539ff clrb !0xfff39
ram:0078a0 f53aff clrb !0xfff3a
ram:0078a3 f53bff clrb !0xfff3b
ram:0078a6 714ae4 set1 0xfffe4.0x4
ram:0078a9 714be0 clr1 0xfffe0.0x4
ram:0078ac 716ae4 set1 0xfffe4.0x6
ram:0078af 716be0 clr1 0xfffe0.0x6
ram:0078b2 714aec set1 0xfffec.0x4
ram:0078b5 714ae8 set1 0xfffe8.0x4
ram:0078b8 716aec set1 0xfffec.0x6
ram:0078bb 716ae8 set1 0xfffe8.0x6
ram:0078be ce3914 mov 0xfff39,0x14
ram:0078c1 8e36 mov A,0xfff36
ram:0078c3 5cfb and A,#0xfb
ram:0078c5 9e36 mov 0xfff36,A
ram:0078c7 714be0 clr1 0xfffe0.0x4
ram:0078ca 714be4 clr1 0xfffe4.0x4
ram:0078cd 716be0 clr1 0xfffe0.0x6
ram:0078d0 716be4 clr1 0xfffe4.0x6
ram:0078d3 714b26 clr1 0xfff26.0x4
ram:0078d6 715b26 clr1 0xfff26.0x5
ram:0078d9 714306 clr1 0xffe26.0x4
ram:0078dc 715306 clr1 0xffe26.0x5
ram:0078df f5d5e3 clrb !0xfe3d5
ram:0078e2 717afa EI
ram:0078e5 31020302 bt 0xffe23.0x0,$ 0x78e9
ram:0078e9 ef12 br $ 0x78fd
ram:0078eb 61fd stop
ram:0078ed 00 nop
ram:0078ee 00 nop
ram:0078ef 00 nop
ram:0078f0 00 nop
ram:0078f1 00 nop
ram:0078f2 d5d5e3 cmp0 !0xfe3d5
ram:0078f5 df06 bnz $ 0x78fd
ram:0078f7 fcd07500 call !!0x75d0
ram:0078fd 717bfa DI
ram:007900 714ae4 set1 0xfffe4.0x4
ram:007903 714be0 clr1 0xfffe0.0x4
ram:007906 716ae4 set1 0xfffe4.0x6
ram:007909 716be0 clr1 0xfffe0.0x6
ram:00790c 715bd2 clr1 0xfffd2.0x5
ram:00790f 715bd6 clr1 0xfffd6.0x5
ram:007912 af3202 movw AX,!0xf0232
ram:007915 08 xch A,X
ram:007916 6c01 or A,#0x1
ram:007918 08 xch A,X
ram:007919 bf3202 movw !0xf0232,AX
ram:00791c 717afa EI
ram:00791f d7 ret
ram:007920 717bfa DI
ram:007923 6a0404 or 0xffe24,#0x4
ram:007926 6a0603 or 0xffe26,#0x3
ram:007929 6a0f04 or 0xffe2f,#0x4
ram:00792c 8e20 mov A,0xfff20
ram:00792e 5cf5 and A,#0xf5
ram:007930 9e20 mov 0xfff20,A
ram:007932 8e21 mov A,0xfff21
ram:007934 5c1c and A,#0x1c
ram:007936 9e21 mov 0xfff21,A
ram:007938 8e23 mov A,0xfff23
ram:00793a 5cfd and A,#0xfd
ram:00793c 9e23 mov 0xfff23,A
ram:00793e 8e24 mov A,0xfff24
ram:007940 5cfb and A,#0xfb
ram:007942 9e24 mov 0xfff24,A
ram:007944 8e25 mov A,0xfff25
ram:007946 5cec and A,#0xec
ram:007948 9e25 mov 0xfff25,A
ram:00794a 8e26 mov A,0xfff26
ram:00794c 5c88 and A,#0x88
ram:00794e 9e26 mov 0xfff26,A
ram:007950 8e27 mov A,0xfff27
ram:007952 5cee and A,#0xee
ram:007954 9e27 mov 0xfff27,A
ram:007956 8e2a mov A,0xfff2a
ram:007958 5cef and A,#0xef
ram:00795a 9e2a mov 0xfff2a,A
ram:00795c 8e2c mov A,0xfff2c
ram:00795e 5cbf and A,#0xbf
ram:007960 9e2c mov 0xfff2c,A
ram:007962 8e2f mov A,0xfff2f
ram:007964 5cdb and A,#0xdb
ram:007966 9e2f mov 0xfff2f,A
ram:007968 7140f000 set1 !0xf00f0.0x4
ram:00796c 00 nop
ram:00796d 00 nop
ram:00796e 00 nop
ram:00796f 00 nop
ram:007970 f6 clrw AX
ram:007971 bf4601 movw !0xf0146,AX
ram:007974 af4401 movw AX,!0xf0144
ram:007977 08 xch A,X
ram:007978 6c02 or A,#0x2
ram:00797a 08 xch A,X
ram:00797b bf4401 movw !0xf0144,AX
ram:00797e 716ae7 set1 0xfffe7.0x6
ram:007981 716be3 clr1 0xfffe3.0x6
ram:007984 716aef set1 0xfffef.0x6
ram:007987 716aeb set1 0xfffeb.0x6
ram:00798a 300700 movw AX,0x7
ram:00798d bf3601 movw !0xf0136,AX
ram:007990 5024 mov ,0x24
ram:007992 bf3a01 movw !0xf013a,AX
ram:007995 5017 mov ,0x17
ram:007997 bf3e01 movw !0xf013e,AX
ram:00799a c916003a movw 0xffe36,0x3a00
ram:00799e af4801 movw AX,!0xf0148
ram:0079a1 6c02 or A,#0x2
ram:0079a3 08 xch A,X
ram:0079a4 6c02 or A,#0x2
ram:0079a6 08 xch A,X
ram:0079a7 bf4801 movw !0xf0148,AX
ram:0079aa 8e3c mov A,0xfff3c
ram:0079ac 6c20 or A,#0x20
ram:0079ae 9e3c mov 0xfff3c,A
ram:0079b0 7110f000 set1 !0xf00f0.0x1
ram:0079b4 3040f5 movw AX,0xf540
ram:0079b7 bff601 movw !0xf01f6,AX
ram:0079ba f6 clrw AX
ram:0079bb 90 dec 
ram:0079bc bff401 movw !0xf01f4,AX
ram:0079bf 711ad5 set1 0xfffd5.0x1
ram:0079c2 711bd1 clr1 0xfffd1.0x1
ram:0079c5 712ad6 set1 0xfffd6.0x2
ram:0079c8 712bd2 clr1 0xfffd2.0x2
ram:0079cb 300108 movw AX,0x801
ram:0079ce bfd001 movw !0xf01d0,AX
ram:0079d1 cb700004 movw 0xfff70,0x400
ram:0079d5 300904 movw AX,0x409
ram:0079d8 bfda01 movw !0xf01da,AX
ram:0079db f6 clrw AX
ram:0079dc be7a movw 0xfff7a,AX
ram:0079de affe01 movw AX,!0xf01fe
ram:0079e1 08 xch A,X
ram:0079e2 6c20 or A,#0x20
ram:0079e4 08 xch A,X
ram:0079e5 bffe01 movw !0xf01fe,AX
ram:0079e8 affc01 movw AX,!0xf01fc
ram:0079eb 08 xch A,X
ram:0079ec 5cdf and A,#0xdf
ram:0079ee 08 xch A,X
ram:0079ef bffc01 movw !0xf01fc,AX
ram:0079f2 aff801 movw AX,!0xf01f8
ram:0079f5 08 xch A,X
ram:0079f6 5cdf and A,#0xdf
ram:0079f8 08 xch A,X
ram:0079f9 bff801 movw !0xf01f8,AX
ram:0079fc affa01 movw AX,!0xf01fa
ram:0079ff 08 xch A,X
ram:007a00 6c20 or A,#0x20
ram:007a02 08 xch A,X
ram:007a03 bffa01 movw !0xf01fa,AX
ram:007a06 714ad6 set1 0xfffd6.0x4
ram:007a09 714bd2 clr1 0xfffd2.0x4
ram:007a0c 714ade set1 0xfffde.0x4
ram:007a0f 714ada set1 0xfffda.0x4
ram:007a12 304481 movw AX,0x8144
ram:007a15 bfde01 movw !0xf01de,AX
ram:007a18 8e3f mov A,0xfff3f
ram:007a1a 6c80 or A,#0x80
ram:007a1c 9e3f mov 0xfff3f,A
ram:007a1e affe01 movw AX,!0xf01fe
ram:007a21 08 xch A,X
ram:007a22 5c7e and A,#0x7e
ram:007a24 08 xch A,X
ram:007a25 bffe01 movw !0xf01fe,AX
ram:007a28 affc01 movw AX,!0xf01fc
ram:007a2b 08 xch A,X
ram:007a2c 5c7e and A,#0x7e
ram:007a2e 08 xch A,X
ram:007a2f bffc01 movw !0xf01fc,AX
ram:007a32 affa01 movw AX,!0xf01fa
ram:007a35 08 xch A,X
ram:007a36 5c7e and A,#0x7e
ram:007a38 08 xch A,X
ram:007a39 bffa01 movw !0xf01fa,AX
ram:007a3c 8e61 mov A,0xfff61
ram:007a3e 5cdf and A,#0xdf
ram:007a40 9e61 mov 0xfff61,A
ram:007a42 714bd2 clr1 0xfffd2.0x4
ram:007a45 714bd6 clr1 0xfffd6.0x4
ram:007a48 aff201 movw AX,!0xf01f2
ram:007a4b 08 xch A,X
ram:007a4c 6ca1 or A,#0xa1
ram:007a4e 08 xch A,X
ram:007a4f bff201 movw !0xf01f2,AX
ram:007a52 7170f000 set1 !0xf00f0.0x7
ram:007a56 f530ff clrb !0xfff30
ram:007a59 710ae7 set1 0xfffe7.0x0
ram:007a5c 710be3 clr1 0xfffe3.0x0
ram:007a5f 710aef set1 0xfffef.0x0
ram:007a62 710aeb set1 0xfffeb.0x0
ram:007a65 cf17000e mov !0xf0017,0xe
ram:007a69 ce3002 mov 0xfff30,0x2
ram:007a6c f542ff clrb !0xfff42
ram:007a6f ce310d mov 0xfff31,0xd
ram:007a72 ce330b mov 0xfff33,0xb
ram:007a75 8e30 mov A,0xfff30
ram:007a77 6c70 or A,#0x70
ram:007a79 9e30 mov 0xfff30,A
ram:007a7b 710be3 clr1 0xfffe3.0x0
ram:007a7e 710ae7 set1 0xfffe7.0x0
ram:007a81 717b30 clr1 0xfff30.0x7
ram:007a84 717afa EI
ram:007a87 d7 ret
ram:007c2e af6201 movw AX,!0xf0162
ram:007c31 f1 clrb A
ram:007c32 08 xch A,X
ram:007c33 5c07 and A,#0x7
ram:007c35 08 xch A,X
ram:007c36 e7 onew BC
ram:007c37 43 cmpw AX,BC
ram:007c38 61f8 sknz
ram:007c3a 717ad1 _set1 0xfffd1.0x7
ram:007c3d d7 ret
ram:007c76 c7 push HL
ram:007c77 fcd47500 call !!0x75d4
ram:007c7b fc49e300 call !!0xe349
ram:007c7f fcde7e00 call !!0x7ede
ram:007c83 fcce7700 call !!0x77ce
ram:007c87 fc207900 call !!0x7920
ram:007c8b eb00e4 movw DE,!0xfe400
ram:007c8e 8a02 mov A,[DE + 0x2]
ram:007c90 9efc mov CS,A
ram:007c92 a9 movw AX,[DE]
ram:007c93 16 movw HL,AX
ram:007c94 e6 onew AX
ram:007c95 61fa call HL
ram:007c97 eb00e4 movw DE,!0xfe400
ram:007c9a 8a0a mov A,[DE + 0xa]
ram:007c9c 9efc mov CS,A
ram:007c9e aa08 movw AX,[DE + 0x8]
ram:007ca0 61ca call AX
ram:007ca2 d2 cmp0 C
ram:007ca3 ddd6 bz $ 0x7c7b
ram:007ca5 fcd07500 call !!0x75d0
ram:007ca9 fcf37e00 call !!0x7ef3
ram:007cad fc2e7c00 call !!0x7c2e
ram:007cb1 efe4 br $ 0x7c97
ram:007cb5 c7 push HL
ram:007cb6 16 movw HL,AX
ram:007cb7 5700 mov ,0x0
ram:007cb9 67 mov A,
ram:007cba 4c20 cmp A,#0x20
ram:007cbc de18 bnc $ 0x7cd6
ram:007cbe 500e mov ,0xe
ram:007cc0 d6 mulu X
ram:007cc1 12 movw BC,AX
ram:007cc2 4920e4 mov A,!0xfe420[BC]
ram:007cc5 614e cmp A,
ram:007cc7 df0a bnz $ 0x7cd3
ram:007cc9 67 mov A,
ram:007cca 500e mov ,0xe
ram:007ccc d6 mulu X
ram:007ccd 0420e4 addw AX,0xe420
ram:007cd0 12 movw BC,AX
ram:007cd1 ef04 br $ 0x7cd7
ram:007cd3 87 inc 
ram:007cd4 efe3 br $ 0x7cb9
ram:007cd6 f7 clrw BC
ram:007cd7 c6 pop HL
ram:007cd8 d7 ret
ram:007e1f c7 push HL
ram:007e20 c1 push AX
ram:007e21 c1 push AX
ram:007e22 fbf8ff movw HL,!0xffff8
ram:007e25 ac02 movw AX,[HL + 0x2]
ram:007e27 14 movw DE,AX
ram:007e28 8a02 mov A,[DE + 0x2]
ram:007e2a d1 cmp0 A
ram:007e2b dd24 bz $ 0x7e51
ram:007e2d 8a02 mov A,[DE + 0x2]
ram:007e2f 318e shrw AX,0x8
ram:007e31 fcb57c00 call !!0x7cb5
ram:007e35 13 movw AX,BC
ram:007e36 bb movw [HL],AX
ram:007e37 f6 clrw AX
ram:007e38 614900 cmpw AX,[HL + 0x0]
ram:007e3b dd0e bz $ 0x7e4b
ram:007e3d ab movw AX,[HL]
ram:007e3e 14 movw DE,AX
ram:007e3f ca0100 mov [DE + 0x1],0x0
ram:007e42 ac0a movw AX,[HL + 0xa]
ram:007e44 c1 push AX
ram:007e45 ab movw AX,[HL]
ram:007e46 fc1f7e00 call !!0x7e1f
ram:007e4a c0 pop AX
ram:007e4b ac02 movw AX,[HL + 0x2]
ram:007e4d 14 movw DE,AX
ram:007e4e ca0200 mov [DE + 0x2],0x0
ram:007e51 ac02 movw AX,[HL + 0x2]
ram:007e53 14 movw DE,AX
ram:007e54 8a01 mov A,[DE + 0x1]
ram:007e56 d1 cmp0 A
ram:007e57 dd29 bz $ 0x7e82
ram:007e59 8a01 mov A,[DE + 0x1]
ram:007e5b 318e shrw AX,0x8
ram:007e5d fcb57c00 call !!0x7cb5
ram:007e61 13 movw AX,BC
ram:007e62 bb movw [HL],AX
ram:007e63 f6 clrw AX
ram:007e64 614900 cmpw AX,[HL + 0x0]
ram:007e67 dd13 bz $ 0x7e7c
ram:007e69 ab movw AX,[HL]
ram:007e6a 14 movw DE,AX
ram:007e6b ca0200 mov [DE + 0x2],0x0
ram:007e6e ab movw AX,[HL]
ram:007e6f 14 movw DE,AX
ram:007e70 ca0300 mov [DE + 0x3],0x0
ram:007e73 ac0a movw AX,[HL + 0xa]
ram:007e75 c1 push AX
ram:007e76 ab movw AX,[HL]
ram:007e77 fcb67e00 call !!0x7eb6
ram:007e7b c0 pop AX
ram:007e7c ac02 movw AX,[HL + 0x2]
ram:007e7e 14 movw DE,AX
ram:007e7f ca0100 mov [DE + 0x1],0x0
ram:007e82 ac02 movw AX,[HL + 0x2]
ram:007e84 14 movw DE,AX
ram:007e85 ca0000 mov [DE + 0x0],0x0
ram:007e88 ac02 movw AX,[HL + 0x2]
ram:007e8a 14 movw DE,AX
ram:007e8b ca0300 mov [DE + 0x3],0x0
ram:007e8e 1004 addw SP,0x4
ram:007e90 c6 pop HL
ram:007e91 d7 ret
ram:007eb6 c7 push HL
ram:007eb7 c1 push AX
ram:007eb8 fbf8ff movw HL,!0xffff8
ram:007ebb ab movw AX,[HL]
ram:007ebc 14 movw DE,AX
ram:007ebd 8a0c mov A,[DE + 0xc]
ram:007ebf 9efc mov CS,A
ram:007ec1 aa0a movw AX,[DE + 0xa]
ram:007ec3 14 movw DE,AX
ram:007ec4 ab movw AX,[HL]
ram:007ec5 61ea call DE
ram:007ec7 d2 cmp0 C
ram:007ec8 df0b bnz $ 0x7ed5
ram:007eca ac08 movw AX,[HL + 0x8]
ram:007ecc c1 push AX
ram:007ecd ab movw AX,[HL]
ram:007ece fc1f7e00 call !!0x7e1f
ram:007ed2 c0 pop AX
ram:007ed3 ef06 br $ 0x7edb
ram:007ed5 ab movw AX,[HL]
ram:007ed6 14 movw DE,AX
ram:007ed7 ac08 movw AX,[HL + 0x8]
ram:007ed9 ba08 movw [DE + 0x8],AX
ram:007edb c0 pop AX
ram:007edc c6 pop HL
ram:007edd d7 ret
ram:007ede c7 push HL
ram:007edf 5600 mov ,0x0
ram:007ee1 66 mov A,
ram:007ee2 4c20 cmp A,#0x20
ram:007ee4 de0b bnc $ 0x7ef1
ram:007ee6 500e mov ,0xe
ram:007ee8 d6 mulu X
ram:007ee9 12 movw BC,AX
ram:007eea 3920e400 mov !0xfe420[BC],0x0
ram:007eee 86 inc 
ram:007eef eff0 br $ 0x7ee1
ram:007ef1 c6 pop HL
ram:007ef2 d7 ret
ram:007ef3 c7 push HL
ram:007ef4 afd2e3 movw AX,!0xfe3d2
ram:007ef7 bfe2e5 movw !0xfe5e2,AX
ram:007efa 5600 mov ,0x0
ram:007efc 66 mov A,
ram:007efd 4c20 cmp A,#0x20
ram:007eff de31 bnc $ 0x7f32
ram:007f01 500e mov ,0xe
ram:007f03 d6 mulu X
ram:007f04 0420e4 addw AX,0xe420
ram:007f07 14 movw DE,AX
ram:007f08 89 mov A,[DE]
ram:007f09 d1 cmp0 A
ram:007f0a dd23 bz $ 0x7f2f
ram:007f0c 8a03 mov A,[DE + 0x3]
ram:007f0e d1 cmp0 A
ram:007f0f df1e bnz $ 0x7f2f
ram:007f11 aa08 movw AX,[DE + 0x8]
ram:007f13 12 movw BC,AX
ram:007f14 afe2e5 movw AX,!0xfe5e2
ram:007f17 23 subw AX,BC
ram:007f18 12 movw BC,AX
ram:007f19 aa06 movw AX,[DE + 0x6]
ram:007f1b 33 xchw AX,BC
ram:007f1c 43 cmpw AX,BC
ram:007f1d dc10 bc $ 0x7f2f
ram:007f1f afe2e5 movw AX,!0xfe5e2
ram:007f22 c1 push AX
ram:007f23 66 mov A,
ram:007f24 500e mov ,0xe
ram:007f26 d6 mulu X
ram:007f27 0420e4 addw AX,0xe420
ram:007f2a fcb67e00 call !!0x7eb6
ram:007f2e c0 pop AX
ram:007f2f 86 inc 
ram:007f30 efca br $ 0x7efc
ram:007f32 c6 pop HL
ram:007f33 d7 ret
ram:007f34 ec767c00 br !!0x7c76
ram:00804f c7 push HL
ram:008050 c1 push AX
ram:008051 c1 push AX
ram:008052 fbf8ff movw HL,!0xffff8
ram:008055 ac02 movw AX,[HL + 0x2]
ram:008057 14 movw DE,AX
ram:008058 aa04 movw AX,[DE + 0x4]
ram:00805a 14 movw DE,AX
ram:00805b aa0c movw AX,[DE + 0xc]
ram:00805d 312e shrw AX,0x2
ram:00805f bb movw [HL],AX
ram:008060 301207 movw AX,0x712
ram:008063 614900 cmpw AX,[HL + 0x0]
ram:008066 df0a bnz $ 0x8072
ram:008068 f5e6e5 clrb !0xfe5e6
ram:00806b e6 onew AX
ram:00806c fc7cb900 call !!0xb97c
ram:008070 ef2a br $ 0x809c
ram:008072 304805 movw AX,0x548
ram:008075 614900 cmpw AX,[HL + 0x0]
ram:008078 dd1c bz $ 0x8096
ram:00807a 5058 mov ,0x58
ram:00807c 614900 cmpw AX,[HL + 0x0]
ram:00807f dd15 bz $ 0x8096
ram:008081 301403 movw AX,0x314
ram:008084 614900 cmpw AX,[HL + 0x0]
ram:008087 dd0d bz $ 0x8096
ram:008089 a1 incw AX
ram:00808a 614900 cmpw AX,[HL + 0x0]
ram:00808d dd07 bz $ 0x8096
ram:00808f 501b mov ,0x1b
ram:008091 614900 cmpw AX,[HL + 0x0]
ram:008094 df06 bnz $ 0x809c
ram:008096 f5e7e5 clrb !0xfe5e7
ram:008099 e5e8e5 oneb !0xfe5e8
ram:00809c e7 onew BC
ram:00809d 1004 addw SP,0x4
ram:00809f c6 pop HL
ram:0080a0 d7 ret
ram:0080be f6 clrw AX
ram:0080bf 12 movw BC,AX
ram:0080c0 ecca8200 br !!0x82ca
ram:0080d3 c7 push HL
ram:0080d4 c1 push AX
ram:0080d5 2008 subw SP,0x8
ram:0080d7 fbf8ff movw HL,!0xffff8
ram:0080da f6 clrw AX
ram:0080db bb movw [HL],AX
ram:0080dc bc02 movw [HL + 0x2],AX
ram:0080de ac08 movw AX,[HL + 0x8]
ram:0080e0 314d shlw AX,0x4
ram:0080e2 320006 movw BC,0x600
ram:0080e5 03 addw AX,BC
ram:0080e6 bc06 movw [HL + 0x6],AX
ram:0080e8 3076c0 movw AX,0xc076
ram:0080eb bc04 movw [HL + 0x4],AX
ram:0080ed ac06 movw AX,[HL + 0x6]
ram:0080ef 14 movw DE,AX
ram:0080f0 300400 movw AX,0x4
ram:0080f3 ba0e movw [DE + 0xe],AX
ram:0080f5 ac06 movw AX,[HL + 0x6]
ram:0080f7 14 movw DE,AX
ram:0080f8 8a08 mov A,[DE + 0x8]
ram:0080fa 72 mov ,A
ram:0080fb ac04 movw AX,[HL + 0x4]
ram:0080fd 14 movw DE,AX
ram:0080fe 62 mov A,
ram:0080ff 9a08 mov [DE + 0x8],A
ram:008101 ac04 movw AX,[HL + 0x4]
ram:008103 14 movw DE,AX
ram:008104 8a08 mov A,[DE + 0x8]
ram:008106 81 inc 
ram:008107 311a shr A,0x1
ram:008109 91 dec 
ram:00810a dd2d bz $ 0x8139
ram:00810c 91 dec 
ram:00810d dd1e bz $ 0x812d
ram:00810f 91 dec 
ram:008110 dd0f bz $ 0x8121
ram:008112 91 dec 
ram:008113 df2e bnz $ 0x8143
ram:008115 ac06 movw AX,[HL + 0x6]
ram:008117 14 movw DE,AX
ram:008118 aa06 movw AX,[DE + 0x6]
ram:00811a 12 movw BC,AX
ram:00811b ac04 movw AX,[HL + 0x4]
ram:00811d 14 movw DE,AX
ram:00811e 13 movw AX,BC
ram:00811f ba06 movw [DE + 0x6],AX
ram:008121 ac06 movw AX,[HL + 0x6]
ram:008123 14 movw DE,AX
ram:008124 aa04 movw AX,[DE + 0x4]
ram:008126 12 movw BC,AX
ram:008127 ac04 movw AX,[HL + 0x4]
ram:008129 14 movw DE,AX
ram:00812a 13 movw AX,BC
ram:00812b ba04 movw [DE + 0x4],AX
ram:00812d ac06 movw AX,[HL + 0x6]
ram:00812f 14 movw DE,AX
ram:008130 aa02 movw AX,[DE + 0x2]
ram:008132 12 movw BC,AX
ram:008133 ac04 movw AX,[HL + 0x4]
ram:008135 14 movw DE,AX
ram:008136 13 movw AX,BC
ram:008137 ba02 movw [DE + 0x2],AX
ram:008139 ac06 movw AX,[HL + 0x6]
ram:00813b 14 movw DE,AX
ram:00813c a9 movw AX,[DE]
ram:00813d 12 movw BC,AX
ram:00813e ac04 movw AX,[HL + 0x4]
ram:008140 14 movw DE,AX
ram:008141 13 movw AX,BC
ram:008142 b9 movw [DE],AX
ram:008143 ac06 movw AX,[HL + 0x6]
ram:008145 14 movw DE,AX
ram:008146 aa0c movw AX,[DE + 0xc]
ram:008148 12 movw BC,AX
ram:008149 ac04 movw AX,[HL + 0x4]
ram:00814b 14 movw DE,AX
ram:00814c 13 movw AX,BC
ram:00814d ba0c movw [DE + 0xc],AX
ram:00814f ac06 movw AX,[HL + 0x6]
ram:008151 14 movw DE,AX
ram:008152 aa0e movw AX,[DE + 0xe]
ram:008154 12 movw BC,AX
ram:008155 ac04 movw AX,[HL + 0x4]
ram:008157 14 movw DE,AX
ram:008158 13 movw AX,BC
ram:008159 ba0e movw [DE + 0xe],AX
ram:00815b 617900 incw [HL + 0x0]
ram:00815e f6 clrw AX
ram:00815f 614900 cmpw AX,[HL + 0x0]
ram:008162 61f8 sknz
ram:008164 617902 _incw [HL + 0x2]
ram:008167 ac06 movw AX,[HL + 0x6]
ram:008169 14 movw DE,AX
ram:00816a aa0e movw AX,[DE + 0xe]
ram:00816c 5c20 and A,#0x20
ram:00816e 08 xch A,X
ram:00816f 5c04 and A,#0x4
ram:008171 08 xch A,X
ram:008172 6168 or A,
ram:008174 61e8 skz
ram:008176 ee74ff _br $! 0x80ed
ram:008179 ac06 movw AX,[HL + 0x6]
ram:00817b 14 movw DE,AX
ram:00817c 301000 movw AX,0x10
ram:00817f ba0e movw [DE + 0xe],AX
ram:008181 f6 clrw AX
ram:008182 614902 cmpw AX,[HL + 0x2]
ram:008185 df04 bnz $ 0x818b
ram:008187 e6 onew AX
ram:008188 614900 cmpw AX,[HL + 0x0]
ram:00818b de0b bnc $ 0x8198
ram:00818d ac04 movw AX,[HL + 0x4]
ram:00818f 14 movw DE,AX
ram:008190 aa0e movw AX,[DE + 0xe]
ram:008192 08 xch A,X
ram:008193 6c10 or A,#0x10
ram:008195 08 xch A,X
ram:008196 ba0e movw [DE + 0xe],AX
ram:008198 100a addw SP,0xa
ram:00819a c6 pop HL
ram:00819b d7 ret
ram:00819c c7 push HL
ram:00819d 2004 subw SP,0x4
ram:00819f fbf8ff movw HL,!0xffff8
ram:0081a2 e6 onew AX
ram:0081a3 bfe805 movw !0xf05e8,AX
ram:0081a6 aff405 movw AX,!0xf05f4
ram:0081a9 bc02 movw [HL + 0x2],AX
ram:0081ab 5102 mov ,0x2
ram:0081ad 5e02 and A,[HL + 0x2]
ram:0081af 318e shrw AX,0x8
ram:0081b1 6168 or A,
ram:0081b3 df14 bnz $ 0x81c9
ram:0081b5 8c02 mov A,[HL + 0x2]
ram:0081b7 5c00 and A,#0x0
ram:0081b9 8c03 mov A,[HL + 0x3]
ram:0081bb 318e shrw AX,0x8
ram:0081bd bb movw [HL],AX
ram:0081be fc2a8e00 call !!0x8e2a
ram:0081c2 aff405 movw AX,!0xf05f4
ram:0081c5 bc02 movw [HL + 0x2],AX
ram:0081c7 efe2 br $ 0x81ab
ram:0081c9 1004 addw SP,0x4
ram:0081cb c6 pop HL
ram:0081cc d7 ret
ram:0081cd c7 push HL
ram:0081ce 2008 subw SP,0x8
ram:0081d0 fbf8ff movw HL,!0xffff8
ram:0081d3 e6 onew AX
ram:0081d4 a1 incw AX
ram:0081d5 bfe805 movw !0xf05e8,AX
ram:0081d8 5010 mov ,0x10
ram:0081da bc04 movw [HL + 0x4],AX
ram:0081dc b1 decw AX
ram:0081dd b1 decw AX
ram:0081de bc02 movw [HL + 0x2],AX
ram:0081e0 aff005 movw AX,!0xf05f0
ram:0081e3 bb movw [HL],AX
ram:0081e4 5102 mov ,0x2
ram:0081e6 5d and A,[HL]
ram:0081e7 318e shrw AX,0x8
ram:0081e9 6168 or A,
ram:0081eb df61 bnz $ 0x824e
ram:0081ed 8b mov A,[HL]
ram:0081ee 5c00 and A,#0x0
ram:0081f0 8c01 mov A,[HL + 0x1]
ram:0081f2 318e shrw AX,0x8
ram:0081f4 bc06 movw [HL + 0x6],AX
ram:0081f6 440e00 cmpw AX,0xe
ram:0081f9 dc24 bc $ 0x821f
ram:0081fb ac06 movw AX,[HL + 0x6]
ram:0081fd 614904 cmpw AX,[HL + 0x4]
ram:008200 de1d bnc $ 0x821f
ram:008202 ac06 movw AX,[HL + 0x6]
ram:008204 314d shlw AX,0x4
ram:008206 320006 movw BC,0x600
ram:008209 03 addw AX,BC
ram:00820a 14 movw DE,AX
ram:00820b aa0e movw AX,[DE + 0xe]
ram:00820d f1 clrb A
ram:00820e 08 xch A,X
ram:00820f 5c04 and A,#0x4
ram:008211 08 xch A,X
ram:008212 440400 cmpw AX,0x4
ram:008215 df08 bnz $ 0x821f
ram:008217 ac06 movw AX,[HL + 0x6]
ram:008219 fc0e8c00 call !!0x8c0e
ram:00821d ef29 br $ 0x8248
ram:00821f ac06 movw AX,[HL + 0x6]
ram:008221 440900 cmpw AX,0x9
ram:008224 dc22 bc $ 0x8248
ram:008226 ac06 movw AX,[HL + 0x6]
ram:008228 614902 cmpw AX,[HL + 0x2]
ram:00822b de1b bnc $ 0x8248
ram:00822d ac06 movw AX,[HL + 0x6]
ram:00822f 314d shlw AX,0x4
ram:008231 320006 movw BC,0x600
ram:008234 03 addw AX,BC
ram:008235 14 movw DE,AX
ram:008236 aa0e movw AX,[DE + 0xe]
ram:008238 f1 clrb A
ram:008239 08 xch A,X
ram:00823a 5c04 and A,#0x4
ram:00823c 08 xch A,X
ram:00823d 440400 cmpw AX,0x4
ram:008240 df06 bnz $ 0x8248
ram:008242 ac06 movw AX,[HL + 0x6]
ram:008244 fcb68c00 call !!0x8cb6
ram:008248 aff005 movw AX,!0xf05f0
ram:00824b bb movw [HL],AX
ram:00824c ef96 br $ 0x81e4
ram:00824e e1 oneb A
ram:00824f 5d and A,[HL]
ram:008250 318e shrw AX,0x8
ram:008252 6168 or A,
ram:008254 dd5b bz $ 0x82b1
ram:008256 e6 onew AX
ram:008257 bff005 movw !0xf05f0,AX
ram:00825a 500e mov ,0xe
ram:00825c bc06 movw [HL + 0x6],AX
ram:00825e ac06 movw AX,[HL + 0x6]
ram:008260 614904 cmpw AX,[HL + 0x4]
ram:008263 de20 bnc $ 0x8285
ram:008265 ac06 movw AX,[HL + 0x6]
ram:008267 314d shlw AX,0x4
ram:008269 320006 movw BC,0x600
ram:00826c 03 addw AX,BC
ram:00826d 14 movw DE,AX
ram:00826e aa0e movw AX,[DE + 0xe]
ram:008270 f1 clrb A
ram:008271 08 xch A,X
ram:008272 5c04 and A,#0x4
ram:008274 08 xch A,X
ram:008275 440400 cmpw AX,0x4
ram:008278 df06 bnz $ 0x8280
ram:00827a ac06 movw AX,[HL + 0x6]
ram:00827c fc0e8c00 call !!0x8c0e
ram:008280 617906 incw [HL + 0x6]
ram:008283 efd9 br $ 0x825e
ram:008285 300900 movw AX,0x9
ram:008288 bc06 movw [HL + 0x6],AX
ram:00828a ac06 movw AX,[HL + 0x6]
ram:00828c 614902 cmpw AX,[HL + 0x2]
ram:00828f de20 bnc $ 0x82b1
ram:008291 ac06 movw AX,[HL + 0x6]
ram:008293 314d shlw AX,0x4
ram:008295 320006 movw BC,0x600
ram:008298 03 addw AX,BC
ram:008299 14 movw DE,AX
ram:00829a aa0e movw AX,[DE + 0xe]
ram:00829c f1 clrb A
ram:00829d 08 xch A,X
ram:00829e 5c04 and A,#0x4
ram:0082a0 08 xch A,X
ram:0082a1 440400 cmpw AX,0x4
ram:0082a4 df06 bnz $ 0x82ac
ram:0082a6 ac06 movw AX,[HL + 0x6]
ram:0082a8 fcb68c00 call !!0x8cb6
ram:0082ac 617906 incw [HL + 0x6]
ram:0082af efd9 br $ 0x828a
ram:0082b1 1008 addw SP,0x8
ram:0082b3 c6 pop HL
ram:0082b4 d7 ret
ram:0082b5 ecd18b00 br !!0x8bd1
ram:0082ca c7 push HL
ram:0082cb c3 push BC
ram:0082cc c1 push AX
ram:0082cd 2018 subw SP,0x18
ram:0082cf fbf8ff movw HL,!0xffff8
ram:0082d2 f6 clrw AX
ram:0082d3 bc0c movw [HL + 0xc],AX
ram:0082d5 bc0e movw [HL + 0xe],AX
ram:0082d7 bc08 movw [HL + 0x8],AX
ram:0082d9 bc0a movw [HL + 0xa],AX
ram:0082db 30d005 movw AX,0x5d0
ram:0082de bc02 movw [HL + 0x2],AX
ram:0082e0 50c0 mov ,0xc0
ram:0082e2 bb movw [HL],AX
ram:0082e3 ac1a movw AX,[HL + 0x1a]
ram:0082e5 12 movw BC,AX
ram:0082e6 ac18 movw AX,[HL + 0x18]
ram:0082e8 bf64c0 movw !0xfc064,AX
ram:0082eb 33 xchw AX,BC
ram:0082ec bf66c0 movw !0xfc066,AX
ram:0082ef ab movw AX,[HL]
ram:0082f0 14 movw DE,AX
ram:0082f1 a9 movw AX,[DE]
ram:0082f2 f1 clrb A
ram:0082f3 08 xch A,X
ram:0082f4 5c01 and A,#0x1
ram:0082f6 08 xch A,X
ram:0082f7 e7 onew BC
ram:0082f8 43 cmpw AX,BC
ram:0082f9 dd0d bz $ 0x8308
ram:0082fb 4100 mov ES,0x0
ram:0082fd 118f0865 mov A,ES:!0xf6508
ram:008301 9a0e mov [DE + 0xe],A
ram:008303 ab movw AX,[HL]
ram:008304 14 movw DE,AX
ram:008305 f0 clrb X
ram:008306 e1 oneb A
ram:008307 b9 movw [DE],AX
ram:008308 ac02 movw AX,[HL + 0x2]
ram:00830a 14 movw DE,AX
ram:00830b aa10 movw AX,[DE + 0x10]
ram:00830d f1 clrb A
ram:00830e 08 xch A,X
ram:00830f 5c18 and A,#0x18
ram:008311 08 xch A,X
ram:008312 6168 or A,
ram:008314 dd2f bz $ 0x8345
ram:008316 aa10 movw AX,[DE + 0x10]
ram:008318 f1 clrb A
ram:008319 08 xch A,X
ram:00831a 5c18 and A,#0x18
ram:00831c 08 xch A,X
ram:00831d 441800 cmpw AX,0x18
ram:008320 df04 bnz $ 0x8326
ram:008322 5010 mov ,0x10
ram:008324 ba10 movw [DE + 0x10],AX
ram:008326 ac02 movw AX,[HL + 0x2]
ram:008328 14 movw DE,AX
ram:008329 aa10 movw AX,[DE + 0x10]
ram:00832b f1 clrb A
ram:00832c 08 xch A,X
ram:00832d 5c08 and A,#0x8
ram:00832f 08 xch A,X
ram:008330 440800 cmpw AX,0x8
ram:008333 df04 bnz $ 0x8339
ram:008335 5008 mov ,0x8
ram:008337 ba10 movw [DE + 0x10],AX
ram:008339 ac02 movw AX,[HL + 0x2]
ram:00833b 14 movw DE,AX
ram:00833c aa10 movw AX,[DE + 0x10]
ram:00833e f1 clrb A
ram:00833f 08 xch A,X
ram:008340 5c18 and A,#0x18
ram:008342 08 xch A,X
ram:008343 ba10 movw [DE + 0x10],AX
ram:008345 cc0600 mov [HL + 0x6],0x0
ram:008348 cc0701 mov [HL + 0x7],0x1
ram:00834b 8c06 mov A,[HL + 0x6]
ram:00834d f0 clrb X
ram:00834e 314e shrw AX,0x4
ram:008350 320006 movw BC,0x600
ram:008353 03 addw AX,BC
ram:008354 bc04 movw [HL + 0x4],AX
ram:008356 8c06 mov A,[HL + 0x6]
ram:008358 318e shrw AX,0x8
ram:00835a bc16 movw [HL + 0x16],AX
ram:00835c 8c07 mov A,[HL + 0x7]
ram:00835e 318e shrw AX,0x8
ram:008360 12 movw BC,AX
ram:008361 ac16 movw AX,[HL + 0x16]
ram:008363 43 cmpw AX,BC
ram:008364 de13 bnc $ 0x8379
ram:008366 ac04 movw AX,[HL + 0x4]
ram:008368 14 movw DE,AX
ram:008369 e6 onew AX
ram:00836a a1 incw AX
ram:00836b ba0e movw [DE + 0xe],AX
ram:00836d ac04 movw AX,[HL + 0x4]
ram:00836f 041000 addw AX,0x10
ram:008372 bc04 movw [HL + 0x4],AX
ram:008374 617916 incw [HL + 0x16]
ram:008377 efe3 br $ 0x835c
ram:008379 ac02 movw AX,[HL + 0x2]
ram:00837b 14 movw DE,AX
ram:00837c aa10 movw AX,[DE + 0x10]
ram:00837e f1 clrb A
ram:00837f 08 xch A,X
ram:008380 5c07 and A,#0x7
ram:008382 08 xch A,X
ram:008383 6168 or A,
ram:008385 dd13 bz $ 0x839a
ram:008387 300700 movw AX,0x7
ram:00838a ba10 movw [DE + 0x10],AX
ram:00838c ac02 movw AX,[HL + 0x2]
ram:00838e 14 movw DE,AX
ram:00838f aa10 movw AX,[DE + 0x10]
ram:008391 f1 clrb A
ram:008392 08 xch A,X
ram:008393 5c07 and A,#0x7
ram:008395 08 xch A,X
ram:008396 6168 or A,
ram:008398 dff2 bnz $ 0x838c
ram:00839a ac18 movw AX,[HL + 0x18]
ram:00839c 01 addw AX,AX
ram:00839d 12 movw BC,AX
ram:00839e 4100 mov ES,0x0
ram:0083a0 11490c65 mov A,ES:!0xf650c[BC]
ram:0083a4 72 mov ,A
ram:0083a5 ac02 movw AX,[HL + 0x2]
ram:0083a7 14 movw DE,AX
ram:0083a8 62 mov A,
ram:0083a9 9a1a mov [DE + 0x1a],A
ram:0083ab ac18 movw AX,[HL + 0x18]
ram:0083ad 01 addw AX,AX
ram:0083ae 12 movw BC,AX
ram:0083af 4100 mov ES,0x0
ram:0083b1 11790e65 movw AX,ES:!0xf650e[BC]
ram:0083b5 12 movw BC,AX
ram:0083b6 ac02 movw AX,[HL + 0x2]
ram:0083b8 14 movw DE,AX
ram:0083b9 13 movw AX,BC
ram:0083ba ba1c movw [DE + 0x1c],AX
ram:0083bc ac18 movw AX,[HL + 0x18]
ram:0083be 01 addw AX,AX
ram:0083bf 12 movw BC,AX
ram:0083c0 4100 mov ES,0x0
ram:0083c2 11790a65 movw AX,ES:!0xf650a[BC]
ram:0083c6 12 movw BC,AX
ram:0083c7 ac02 movw AX,[HL + 0x2]
ram:0083c9 14 movw DE,AX
ram:0083ca 13 movw AX,BC
ram:0083cb ba16 movw [DE + 0x16],AX
ram:0083cd 3076c0 movw AX,0xc076
ram:0083d0 bf50c0 movw !0xfc050,AX
ram:0083d3 f6 clrw AX
ram:0083d4 bc16 movw [HL + 0x16],AX
ram:0083d6 f6 clrw AX
ram:0083d7 614916 cmpw AX,[HL + 0x16]
ram:0083da df63 bnz $ 0x843f
ram:0083dc ac16 movw AX,[HL + 0x16]
ram:0083de bc10 movw [HL + 0x10],AX
ram:0083e0 8f54c0 mov A,!0xfc054
ram:0083e3 5c04 and A,#0x4
ram:0083e5 4c04 cmp A,#0x4
ram:0083e7 df15 bnz $ 0x83fe
ram:0083e9 ac10 movw AX,[HL + 0x10]
ram:0083eb 01 addw AX,AX
ram:0083ec 0452c0 addw AX,0xc052
ram:0083ef 14 movw DE,AX
ram:0083f0 a9 movw AX,[DE]
ram:0083f1 bc14 movw [HL + 0x14],AX
ram:0083f3 440200 cmpw AX,0x2
ram:0083f6 de06 bnc $ 0x83fe
ram:0083f8 ac14 movw AX,[HL + 0x14]
ram:0083fa fc507302 call !!0x27350
ram:0083fe ac10 movw AX,[HL + 0x10]
ram:008400 01 addw AX,AX
ram:008401 12 movw BC,AX
ram:008402 f6 clrw AX
ram:008403 b1 decw AX
ram:008404 7852c0 movw !0xfc052[BC],AX
ram:008407 ac16 movw AX,[HL + 0x16]
ram:008409 314d shlw AX,0x4
ram:00840b 320006 movw BC,0x600
ram:00840e 03 addw AX,BC
ram:00840f bc04 movw [HL + 0x4],AX
ram:008411 ac04 movw AX,[HL + 0x4]
ram:008413 14 movw DE,AX
ram:008414 aa0e movw AX,[DE + 0xe]
ram:008416 f1 clrb A
ram:008417 08 xch A,X
ram:008418 5c01 and A,#0x1
ram:00841a 08 xch A,X
ram:00841b 6168 or A,
ram:00841d dd05 bz $ 0x8424
ram:00841f e6 onew AX
ram:008420 ba0e movw [DE + 0xe],AX
ram:008422 efed br $ 0x8411
ram:008424 ac04 movw AX,[HL + 0x4]
ram:008426 14 movw DE,AX
ram:008427 301c00 movw AX,0x1c
ram:00842a ba0e movw [DE + 0xe],AX
ram:00842c ac04 movw AX,[HL + 0x4]
ram:00842e 14 movw DE,AX
ram:00842f ca0901 mov [DE + 0x9],0x1
ram:008432 ac04 movw AX,[HL + 0x4]
ram:008434 14 movw DE,AX
ram:008435 300008 movw AX,0x800
ram:008438 ba0e movw [DE + 0xe],AX
ram:00843a 617916 incw [HL + 0x16]
ram:00843d ef97 br $ 0x83d6
ram:00843f e6 onew AX
ram:008440 bc16 movw [HL + 0x16],AX
ram:008442 ac16 movw AX,[HL + 0x16]
ram:008444 440900 cmpw AX,0x9
ram:008447 de30 bnc $ 0x8479
ram:008449 ac16 movw AX,[HL + 0x16]
ram:00844b 314d shlw AX,0x4
ram:00844d 320006 movw BC,0x600
ram:008450 03 addw AX,BC
ram:008451 bc04 movw [HL + 0x4],AX
ram:008453 ac04 movw AX,[HL + 0x4]
ram:008455 14 movw DE,AX
ram:008456 aa0e movw AX,[DE + 0xe]
ram:008458 f1 clrb A
ram:008459 08 xch A,X
ram:00845a 5c01 and A,#0x1
ram:00845c 08 xch A,X
ram:00845d 6168 or A,
ram:00845f dd05 bz $ 0x8466
ram:008461 e6 onew AX
ram:008462 ba0e movw [DE + 0xe],AX
ram:008464 efed br $ 0x8453
ram:008466 ac04 movw AX,[HL + 0x4]
ram:008468 14 movw DE,AX
ram:008469 301e00 movw AX,0x1e
ram:00846c ba0e movw [DE + 0xe],AX
ram:00846e ac04 movw AX,[HL + 0x4]
ram:008470 14 movw DE,AX
ram:008471 ca0900 mov [DE + 0x9],0x0
ram:008474 617916 incw [HL + 0x16]
ram:008477 efc9 br $ 0x8442
ram:008479 300900 movw AX,0x9
ram:00847c bc16 movw [HL + 0x16],AX
ram:00847e ac16 movw AX,[HL + 0x16]
ram:008480 440e00 cmpw AX,0xe
ram:008483 de58 bnc $ 0x84dd
ram:008485 ac16 movw AX,[HL + 0x16]
ram:008487 240900 subw AX,0x9
ram:00848a a1 incw AX
ram:00848b bc12 movw [HL + 0x12],AX
ram:00848d ac16 movw AX,[HL + 0x16]
ram:00848f 314d shlw AX,0x4
ram:008491 320006 movw BC,0x600
ram:008494 03 addw AX,BC
ram:008495 bc04 movw [HL + 0x4],AX
ram:008497 ac04 movw AX,[HL + 0x4]
ram:008499 14 movw DE,AX
ram:00849a aa0e movw AX,[DE + 0xe]
ram:00849c f1 clrb A
ram:00849d 08 xch A,X
ram:00849e 5c01 and A,#0x1
ram:0084a0 08 xch A,X
ram:0084a1 6168 or A,
ram:0084a3 dd05 bz $ 0x84aa
ram:0084a5 e6 onew AX
ram:0084a6 ba0e movw [DE + 0xe],AX
ram:0084a8 efed br $ 0x8497
ram:0084aa ac04 movw AX,[HL + 0x4]
ram:0084ac 14 movw DE,AX
ram:0084ad 301e00 movw AX,0x1e
ram:0084b0 ba0e movw [DE + 0xe],AX
ram:0084b2 ac04 movw AX,[HL + 0x4]
ram:0084b4 14 movw DE,AX
ram:0084b5 ca0989 mov [DE + 0x9],0x89
ram:0084b8 ac12 movw AX,[HL + 0x12]
ram:0084ba 01 addw AX,AX
ram:0084bb 12 movw BC,AX
ram:0084bc 4100 mov ES,0x0
ram:0084be 1179c464 movw AX,ES:!0xf64c4[BC]
ram:0084c2 12 movw BC,AX
ram:0084c3 ac04 movw AX,[HL + 0x4]
ram:0084c5 14 movw DE,AX
ram:0084c6 13 movw AX,BC
ram:0084c7 ba0c movw [DE + 0xc],AX
ram:0084c9 ac04 movw AX,[HL + 0x4]
ram:0084cb 14 movw DE,AX
ram:0084cc 300008 movw AX,0x800
ram:0084cf ba0e movw [DE + 0xe],AX
ram:0084d1 ac04 movw AX,[HL + 0x4]
ram:0084d3 14 movw DE,AX
ram:0084d4 f0 clrb X
ram:0084d5 e1 oneb A
ram:0084d6 ba0e movw [DE + 0xe],AX
ram:0084d8 617916 incw [HL + 0x16]
ram:0084db efa1 br $ 0x847e
ram:0084dd 300e00 movw AX,0xe
ram:0084e0 bc16 movw [HL + 0x16],AX
ram:0084e2 ac16 movw AX,[HL + 0x16]
ram:0084e4 441000 cmpw AX,0x10
ram:0084e7 61c8 skc
ram:0084e9 eebf00 _br $! 0x85ab
ram:0084ec ac16 movw AX,[HL + 0x16]
ram:0084ee 314d shlw AX,0x4
ram:0084f0 320006 movw BC,0x600
ram:0084f3 03 addw AX,BC
ram:0084f4 bc04 movw [HL + 0x4],AX
ram:0084f6 ac04 movw AX,[HL + 0x4]
ram:0084f8 14 movw DE,AX
ram:0084f9 aa0e movw AX,[DE + 0xe]
ram:0084fb f1 clrb A
ram:0084fc 08 xch A,X
ram:0084fd 5c01 and A,#0x1
ram:0084ff 08 xch A,X
ram:008500 6168 or A,
ram:008502 dd05 bz $ 0x8509
ram:008504 e6 onew AX
ram:008505 ba0e movw [DE + 0xe],AX
ram:008507 efed br $ 0x84f6
ram:008509 f6 clrw AX
ram:00850a 61490a cmpw AX,[HL + 0xa]
ram:00850d 61f8 sknz
ram:00850f 614908 _cmpw AX,[HL + 0x8]
ram:008512 df07 bnz $ 0x851b
ram:008514 e6 onew AX
ram:008515 a1 incw AX
ram:008516 bc08 movw [HL + 0x8],AX
ram:008518 f6 clrw AX
ram:008519 bc0a movw [HL + 0xa],AX
ram:00851b ac04 movw AX,[HL + 0x4]
ram:00851d 14 movw DE,AX
ram:00851e 301e00 movw AX,0x1e
ram:008521 ba0e movw [DE + 0xe],AX
ram:008523 ac0e movw AX,[HL + 0xe]
ram:008525 12 movw BC,AX
ram:008526 ac0c movw AX,[HL + 0xc]
ram:008528 040200 addw AX,0x2
ram:00852b 61d8 sknc
ram:00852d a3 _incw BC
ram:00852e bdd8 movw 0xffdf8,AX
ram:008530 13 movw AX,BC
ram:008531 bdda movw 0xffdfa,AX
ram:008533 5103 mov ,0x3
ram:008535 fd7106 call !0xf0671
ram:0085ab db66c0 movw BC,!0xfc066
ram:0085ae af64c0 movw AX,!0xfc064
ram:0085b1 33 xchw AX,BC
ram:0085b2 bf66c0 movw !0xfc066,AX
ram:0085b5 ac18 movw AX,[HL + 0x18]
ram:0085b7 313d shlw AX,0x3
ram:0085b9 12 movw BC,AX
ram:0085ba 4100 mov ES,0x0
ram:0085bc 11791865 movw AX,ES:!0xf6518[BC]
ram:0085c0 12 movw BC,AX
ram:0085c1 ac02 movw AX,[HL + 0x2]
ram:0085c3 14 movw DE,AX
ram:0085c4 13 movw AX,BC
ram:0085c5 b9 movw [DE],AX
ram:0085c6 ac18 movw AX,[HL + 0x18]
ram:0085c8 313d shlw AX,0x3
ram:0085ca 12 movw BC,AX
ram:0085cb 4100 mov ES,0x0
ram:0085cd 11791065 movw AX,ES:!0xf6510[BC]
ram:0085d1 12 movw BC,AX
ram:0085d2 ac02 movw AX,[HL + 0x2]
ram:0085d4 14 movw DE,AX
ram:0085d5 13 movw AX,BC
ram:0085d6 ba02 movw [DE + 0x2],AX
ram:0085d8 ac18 movw AX,[HL + 0x18]
ram:0085da 313d shlw AX,0x3
ram:0085dc 041865 addw AX,0x6518
ram:0085df 14 movw DE,AX
ram:0085e0 a5 incw DE
ram:0085e1 a5 incw DE
ram:0085e2 4100 mov ES,0x0
ram:0085e4 11a9 movw AX,ES:[DE]
ram:0085e6 12 movw BC,AX
ram:0085e7 ac02 movw AX,[HL + 0x2]
ram:0085e9 14 movw DE,AX
ram:0085ea 13 movw AX,BC
ram:0085eb ba04 movw [DE + 0x4],AX
ram:0085ed ac18 movw AX,[HL + 0x18]
ram:0085ef 313d shlw AX,0x3
ram:0085f1 041065 addw AX,0x6510
ram:0085f4 14 movw DE,AX
ram:0085f5 a5 incw DE
ram:0085f6 a5 incw DE
ram:0085f7 4100 mov ES,0x0
ram:0085f9 11a9 movw AX,ES:[DE]
ram:0085fb 12 movw BC,AX
ram:0085fc ac02 movw AX,[HL + 0x2]
ram:0085fe 14 movw DE,AX
ram:0085ff 13 movw AX,BC
ram:008600 ba06 movw [DE + 0x6],AX
ram:008602 ac18 movw AX,[HL + 0x18]
ram:008604 313d shlw AX,0x3
ram:008606 12 movw BC,AX
ram:008607 4100 mov ES,0x0
ram:008609 11791c65 movw AX,ES:!0xf651c[BC]
ram:00860d 12 movw BC,AX
ram:00860e ac02 movw AX,[HL + 0x2]
ram:008610 14 movw DE,AX
ram:008611 13 movw AX,BC
ram:008612 ba08 movw [DE + 0x8],AX
ram:008614 ac18 movw AX,[HL + 0x18]
ram:008616 313d shlw AX,0x3
ram:008618 12 movw BC,AX
ram:008619 4100 mov ES,0x0
ram:00861b 11791465 movw AX,ES:!0xf6514[BC]
ram:00861f 12 movw BC,AX
ram:008620 ac02 movw AX,[HL + 0x2]
ram:008622 14 movw DE,AX
ram:008623 13 movw AX,BC
ram:008624 ba0a movw [DE + 0xa],AX
ram:008626 ac18 movw AX,[HL + 0x18]
ram:008628 313d shlw AX,0x3
ram:00862a 12 movw BC,AX
ram:00862b 4100 mov ES,0x0
ram:00862d 11791e65 movw AX,ES:!0xf651e[BC]
ram:008631 12 movw BC,AX
ram:008632 ac02 movw AX,[HL + 0x2]
ram:008634 14 movw DE,AX
ram:008635 13 movw AX,BC
ram:008636 ba0c movw [DE + 0xc],AX
ram:008638 ac18 movw AX,[HL + 0x18]
ram:00863a 313d shlw AX,0x3
ram:00863c 12 movw BC,AX
ram:00863d 4100 mov ES,0x0
ram:00863f 11791665 movw AX,ES:!0xf6516[BC]
ram:008643 12 movw BC,AX
ram:008644 ac02 movw AX,[HL + 0x2]
ram:008646 14 movw DE,AX
ram:008647 13 movw AX,BC
ram:008648 ba0e movw [DE + 0xe],AX
ram:00864a ac02 movw AX,[HL + 0x2]
ram:00864c 14 movw DE,AX
ram:00864d aa18 movw AX,[DE + 0x18]
ram:00864f e586c0 oneb !0xfc086
ram:008652 302000 movw AX,0x20
ram:008655 ba10 movw [DE + 0x10],AX
ram:008657 ac02 movw AX,[HL + 0x2]
ram:008659 14 movw DE,AX
ram:00865a 300601 movw AX,0x106
ram:00865d ba10 movw [DE + 0x10],AX
ram:00865f 101c addw SP,0x1c
ram:008661 c6 pop HL
ram:008662 d7 ret
ram:0088f3 c7 push HL
ram:0088f4 c1 push AX
ram:0088f5 200c subw SP,0xc
ram:0088f7 fbf8ff movw HL,!0xffff8
ram:0088fa ac0c movw AX,[HL + 0xc]
ram:0088fc bc08 movw [HL + 0x8],AX
ram:0088fe 314d shlw AX,0x4
ram:008900 320006 movw BC,0x600
ram:008903 03 addw AX,BC
ram:008904 bb movw [HL],AX
ram:008905 8fe305 mov A,!0xf05e3
ram:008908 5c10 and A,#0x10
ram:00890a 4c01 cmp A,#0x1
ram:00890c e6 onew AX
ram:00890d 6130 subc ,A
ram:00890f e7 onew BC
ram:008910 43 cmpw AX,BC
ram:008911 df0e bnz $ 0x8921
ram:008913 ac0c movw AX,[HL + 0xc]
ram:008915 01 addw AX,AX
ram:008916 12 movw BC,AX
ram:008917 f6 clrw AX
ram:008918 b1 decw AX
ram:008919 7852c0 movw !0xfc052[BC],AX
ram:00891c f7 clrw BC
ram:00891d ecf28900 br !!0x89f2
ram:008921 ac14 movw AX,[HL + 0x14]
ram:008923 01 addw AX,AX
ram:008924 12 movw BC,AX
ram:008925 4100 mov ES,0x0
ram:008927 1179ac64 movw AX,ES:!0xf64ac[BC]
ram:00892b 12 movw BC,AX
ram:00892c ab movw AX,[HL]
ram:00892d 14 movw DE,AX
ram:00892e 13 movw AX,BC
ram:00892f ba0c movw [DE + 0xc],AX
ram:008931 ac14 movw AX,[HL + 0x14]
ram:008933 12 movw BC,AX
ram:008934 4100 mov ES,0x0
ram:008936 1149b064 mov A,ES:!0xf64b0[BC]
ram:00893a 72 mov ,A
ram:00893b ab movw AX,[HL]
ram:00893c 14 movw DE,AX
ram:00893d 62 mov A,
ram:00893e 9a08 mov [DE + 0x8],A
ram:008940 ac14 movw AX,[HL + 0x14]
ram:008942 01 addw AX,AX
ram:008943 12 movw BC,AX
ram:008944 4100 mov ES,0x0
ram:008946 1179b264 movw AX,ES:!0xf64b2[BC]
ram:00894a bc06 movw [HL + 0x6],AX
ram:00894c f6 clrw AX
ram:00894d 614906 cmpw AX,[HL + 0x6]
ram:008950 61f8 sknz
ram:008952 ec988900 _br !!0x8998
ram:008956 fc80e000 call !!0xe080
ram:008998 fc80e000 call !!0xe080
ram:0089f2 100e addw SP,0xe
ram:0089f4 c6 pop HL
ram:0089f5 d7 ret
ram:008bd1 afe805 movw AX,!0xf05e8
ram:008bd4 f1 clrb A
ram:008bd5 08 xch A,X
ram:008bd6 5c1c and A,#0x1c
ram:008bd8 08 xch A,X
ram:008bd9 6168 or A,
ram:008bdb dd30 bz $ 0x8c0d
ram:008bdd afe805 movw AX,!0xf05e8
ram:008be0 f1 clrb A
ram:008be1 08 xch A,X
ram:008be2 5c18 and A,#0x18
ram:008be4 08 xch A,X
ram:008be5 6168 or A,
ram:008be7 dd06 bz $ 0x8bef
ram:008be9 301800 movw AX,0x18
ram:008bec bfe805 movw !0xf05e8,AX
ram:008bef afe805 movw AX,!0xf05e8
ram:008bf2 f1 clrb A
ram:008bf3 08 xch A,X
ram:008bf4 5c04 and A,#0x4
ram:008bf6 08 xch A,X
ram:008bf7 6168 or A,
ram:008bf9 dd06 bz $ 0x8c01
ram:008bfb 300400 movw AX,0x4
ram:008bfe bfe805 movw !0xf05e8,AX
ram:008c01 8fe305 mov A,!0xf05e3
ram:008c04 5c10 and A,#0x10
ram:008c06 d1 cmp0 A
ram:008c07 61e8 skz
ram:008c09 fcbe8000 _call !!0x80be
ram:008c0d d7 ret
ram:008c0e c7 push HL
ram:008c0f c1 push AX
ram:008c10 2006 subw SP,0x6
ram:008c12 fbf8ff movw HL,!0xffff8
ram:008c15 f6 clrw AX
ram:008c16 b1 decw AX
ram:008c17 bb movw [HL],AX
ram:008c18 ac06 movw AX,[HL + 0x6]
ram:008c1a fcd38000 call !!0x80d3
ram:008c1e 306ac0 movw AX,0xc06a
ram:008c21 bc04 movw [HL + 0x4],AX
ram:008c23 14 movw DE,AX
ram:008c24 3076c0 movw AX,0xc076
ram:008c27 ba04 movw [DE + 0x4],AX
ram:008c29 ac04 movw AX,[HL + 0x4]
ram:008c2b 14 movw DE,AX
ram:008c2c 3076c0 movw AX,0xc076
ram:008c2f ba06 movw [DE + 0x6],AX
ram:008c31 ac04 movw AX,[HL + 0x4]
ram:008c33 14 movw DE,AX
ram:008c34 f6 clrw AX
ram:008c35 b1 decw AX
ram:008c36 ba08 movw [DE + 0x8],AX
ram:008c38 ac04 movw AX,[HL + 0x4]
ram:008c3a 14 movw DE,AX
ram:008c3b aa04 movw AX,[DE + 0x4]
ram:008c3d 040c00 addw AX,0xc
ram:008c40 14 movw DE,AX
ram:008c41 89 mov A,[DE]
ram:008c42 5c00 and A,#0x0
ram:008c44 08 xch A,X
ram:008c45 8a01 mov A,[DE + 0x1]
ram:008c47 5c80 and A,#0x80
ram:008c49 bdd8 movw 0xffdf8,AX
ram:008c4b f6 clrw AX
ram:008c4c bdda movw 0xffdfa,AX
ram:008c4e 5110 mov ,0x10
ram:008c50 fd7106 call !0xf0671
ram:008c53 f6 clrw AX
ram:008c54 46da cmpw AX,0xffdfa
ram:008c56 61f8 sknz
ram:008c58 46d8 _cmpw AX,0xffdf8
ram:008c5a df56 bnz $ 0x8cb2
ram:008c5c ac04 movw AX,[HL + 0x4]
ram:008c5e fc4f8000 call !!0x804f
ram:008c62 d2 cmp0 C
ram:008c63 dd4d bz $ 0x8cb2
ram:008c65 ac04 movw AX,[HL + 0x4]
ram:008c67 14 movw DE,AX
ram:008c68 aa04 movw AX,[DE + 0x4]
ram:008c6a 040c00 addw AX,0xc
ram:008c6d 14 movw DE,AX
ram:008c6e 89 mov A,[DE]
ram:008c6f 5cfc and A,#0xfc
ram:008c71 08 xch A,X
ram:008c72 8a01 mov A,[DE + 0x1]
ram:008c74 5c1f and A,#0x1f
ram:008c76 08 xch A,X
ram:008c77 5cfc and A,#0xfc
ram:008c79 08 xch A,X
ram:008c7a bc02 movw [HL + 0x2],AX
ram:008c7c f6 clrw AX
ram:008c7d bb movw [HL],AX
ram:008c7e f6 clrw AX
ram:008c7f 614900 cmpw AX,[HL + 0x0]
ram:008c82 df13 bnz $ 0x8c97
ram:008c84 ab movw AX,[HL]
ram:008c85 01 addw AX,AX
ram:008c86 12 movw BC,AX
ram:008c87 4100 mov ES,0x0
ram:008c89 1179c464 movw AX,ES:!0xf64c4[BC]
ram:008c8d 614902 cmpw AX,[HL + 0x2]
ram:008c90 dd05 bz $ 0x8c97
ram:008c92 617900 incw [HL + 0x0]
ram:008c95 efe7 br $ 0x8c7e
ram:008c97 f6 clrw AX
ram:008c98 614900 cmpw AX,[HL + 0x0]
ram:008c9b df15 bnz $ 0x8cb2
ram:008c9d ab movw AX,[HL]
ram:008c9e 01 addw AX,AX
ram:008c9f 12 movw BC,AX
ram:008ca0 4100 mov ES,0x0
ram:008ca2 1179d064 movw AX,ES:!0xf64d0[BC]
ram:008ca6 bb movw [HL],AX
ram:008ca7 ac04 movw AX,[HL + 0x4]
ram:008ca9 14 movw DE,AX
ram:008caa ab movw AX,[HL]
ram:008cab ba08 movw [DE + 0x8],AX
ram:008cad fc208d00 call !!0x8d20
ram:008cb1 92 dec 
ram:008cb2 1008 addw SP,0x8
ram:008cb4 c6 pop HL
ram:008cb5 d7 ret
ram:008cb6 c7 push HL
ram:008cb7 c1 push AX
ram:008cb8 2004 subw SP,0x4
ram:008cba fbf8ff movw HL,!0xffff8
ram:008cbd ac04 movw AX,[HL + 0x4]
ram:008cbf fcd38000 call !!0x80d3
ram:008cc3 306ac0 movw AX,0xc06a
ram:008cc6 bb movw [HL],AX
ram:008cc7 14 movw DE,AX
ram:008cc8 3076c0 movw AX,0xc076
ram:008ccb ba04 movw [DE + 0x4],AX
ram:008ccd ab movw AX,[HL]
ram:008cce 14 movw DE,AX
ram:008ccf 3076c0 movw AX,0xc076
ram:008cd2 ba06 movw [DE + 0x6],AX
ram:008cd4 ab movw AX,[HL]
ram:008cd5 14 movw DE,AX
ram:008cd6 aa04 movw AX,[DE + 0x4]
ram:008cd8 040c00 addw AX,0xc
ram:008cdb 14 movw DE,AX
ram:008cdc 89 mov A,[DE]
ram:008cdd 5c00 and A,#0x0
ram:008cdf 08 xch A,X
ram:008ce0 8a01 mov A,[DE + 0x1]
ram:008ce2 5c80 and A,#0x80
ram:008ce4 bdd8 movw 0xffdf8,AX
ram:008ce6 f6 clrw AX
ram:008ce7 bdda movw 0xffdfa,AX
ram:008ce9 5110 mov ,0x10
ram:008ceb fd7106 call !0xf0671
ram:008cee f6 clrw AX
ram:008cef 46da cmpw AX,0xffdfa
ram:008cf1 61f8 sknz
ram:008cf3 46d8 _cmpw AX,0xffdf8
ram:008cf5 df25 bnz $ 0x8d1c
ram:008cf7 ab movw AX,[HL]
ram:008cf8 fc4f8000 call !!0x804f
ram:008cfc d2 cmp0 C
ram:008cfd dd1d bz $ 0x8d1c
ram:008cff ac04 movw AX,[HL + 0x4]
ram:008d01 240900 subw AX,0x9
ram:008d04 a1 incw AX
ram:008d05 bc02 movw [HL + 0x2],AX
ram:008d07 01 addw AX,AX
ram:008d08 12 movw BC,AX
ram:008d09 4100 mov ES,0x0
ram:008d0b 1179d064 movw AX,ES:!0xf64d0[BC]
ram:008d0f bc02 movw [HL + 0x2],AX
ram:008d11 ab movw AX,[HL]
ram:008d12 14 movw DE,AX
ram:008d13 ac02 movw AX,[HL + 0x2]
ram:008d15 ba08 movw [DE + 0x8],AX
ram:008d17 fc208d00 call !!0x8d20
ram:008d1b 92 dec 
ram:008d1c 1006 addw SP,0x6
ram:008d1e c6 pop HL
ram:008d1f d7 ret
ram:008d20 c7 push HL
ram:008d21 2008 subw SP,0x8
ram:008d23 fbf8ff movw HL,!0xffff8
ram:008d26 306ac0 movw AX,0xc06a
ram:008d29 bc06 movw [HL + 0x6],AX
ram:008d2b 14 movw DE,AX
ram:008d2c aa08 movw AX,[DE + 0x8]
ram:008d2e 12 movw BC,AX
ram:008d2f 4100 mov ES,0x0
ram:008d31 11493065 mov A,ES:!0xf6530[BC]
ram:008d35 72 mov ,A
ram:008d36 ac06 movw AX,[HL + 0x6]
ram:008d38 14 movw DE,AX
ram:008d39 aa04 movw AX,[DE + 0x4]
ram:008d3b 14 movw DE,AX
ram:008d3c 8a08 mov A,[DE + 0x8]
ram:008d3e 614a cmp A,
ram:008d40 de05 bnc $ 0x8d47
ram:008d42 f7 clrw BC
ram:008d43 ec268e00 br !!0x8e26
ram:008d47 ac06 movw AX,[HL + 0x6]
ram:008d49 14 movw DE,AX
ram:008d4a aa04 movw AX,[DE + 0x4]
ram:008d4c 14 movw DE,AX
ram:008d4d 8a08 mov A,[DE + 0x8]
ram:008d4f 318e shrw AX,0x8
ram:008d51 c1 push AX
ram:008d52 ac06 movw AX,[HL + 0x6]
ram:008d54 14 movw DE,AX
ram:008d55 aa08 movw AX,[DE + 0x8]
ram:008d57 fc549200 call !!0x9254
ram:008d5b c0 pop AX
ram:008d5c ac06 movw AX,[HL + 0x6]
ram:008d5e fc7f7302 call !!0x2737f
ram:008d62 92 dec 
ram:008d63 dd05 bz $ 0x8d6a
ram:008d65 f7 clrw BC
ram:008d66 ec268e00 br !!0x8e26
ram:008d6a ac06 movw AX,[HL + 0x6]
ram:008d6c 14 movw DE,AX
ram:008d6d aa08 movw AX,[DE + 0x8]
ram:008d6f 312d shlw AX,0x2
ram:008d71 04ee64 addw AX,0x64ee
ram:008d74 14 movw DE,AX
ram:008d75 4100 mov ES,0x0
ram:008d77 118a02 mov A,ES:[DE + 0x2]
ram:008d7a 9dd4 mov 0xffdf4,A
ram:008d7c 11a9 movw AX,ES:[DE]
ram:008d7e d4d4 cmp0 0xffdf4
ram:008d80 df02 bnz $ 0x8d84
ram:008d82 f7 clrw BC
ram:008d83 43 cmpw AX,BC
ram:008d84 dd26 bz $ 0x8dac
ram:008d86 ac06 movw AX,[HL + 0x6]
ram:008d88 14 movw DE,AX
ram:008d89 aa08 movw AX,[DE + 0x8]
ram:008d8b bf46c0 movw !0xfc046,AX
ram:008d8e aa08 movw AX,[DE + 0x8]
ram:008d90 312d shlw AX,0x2
ram:008d92 04ee64 addw AX,0x64ee
ram:008d95 14 movw DE,AX
ram:008d96 4100 mov ES,0x0
ram:008d98 118a02 mov A,ES:[DE + 0x2]
ram:008d9b 9efc mov CS,A
ram:008d9d 11a9 movw AX,ES:[DE]
ram:008d9f 14 movw DE,AX
ram:008da0 ac06 movw AX,[HL + 0x6]
ram:008da2 61ea call DE
ram:008da4 d2 cmp0 C
ram:008da5 df05 bnz $ 0x8dac
ram:008da7 f7 clrw BC
ram:008da8 ec268e00 br !!0x8e26
ram:008dac ac06 movw AX,[HL + 0x6]
ram:008dae 14 movw DE,AX
ram:008daf aa08 movw AX,[DE + 0x8]
ram:008db1 01 addw AX,AX
ram:008db2 04e264 addw AX,0x64e2
ram:008db5 14 movw DE,AX
ram:008db6 4100 mov ES,0x0
ram:008db8 11a9 movw AX,ES:[DE]
ram:008dba 6168 or A,
ram:008dbc 61f8 sknz
ram:008dbe ec258e00 _br !!0x8e25
ram:008dc2 fc80e000 call !!0xe080
ram:008e25 e7 onew BC
ram:008e26 1008 addw SP,0x8
ram:008e28 c6 pop HL
ram:008e29 d7 ret
ram:008e2a c7 push HL
ram:008e2b c1 push AX
ram:008e2c 200e subw SP,0xe
ram:008e2e fbf8ff movw HL,!0xffff8
ram:008e31 ac0e movw AX,[HL + 0xe]
ram:008e33 bc0c movw [HL + 0xc],AX
ram:008e35 01 addw AX,AX
ram:008e36 0452c0 addw AX,0xc052
ram:008e39 14 movw DE,AX
ram:008e3a a9 movw AX,[DE]
ram:008e3b bc0a movw [HL + 0xa],AX
ram:008e3d ac0e movw AX,[HL + 0xe]
ram:008e3f 314d shlw AX,0x4
ram:008e41 320006 movw BC,0x600
ram:008e44 03 addw AX,BC
ram:008e45 bb movw [HL],AX
ram:008e46 ab movw AX,[HL]
ram:008e47 14 movw DE,AX
ram:008e48 e6 onew AX
ram:008e49 ba0e movw [DE + 0xe],AX
ram:008e4b ab movw AX,[HL]
ram:008e4c 14 movw DE,AX
ram:008e4d aa0e movw AX,[DE + 0xe]
ram:008e4f f1 clrb A
ram:008e50 08 xch A,X
ram:008e51 5c01 and A,#0x1
ram:008e53 08 xch A,X
ram:008e54 6168 or A,
ram:008e56 dfee bnz $ 0x8e46
ram:008e58 f6 clrw AX
ram:008e59 b1 decw AX
ram:008e5a 61490a cmpw AX,[HL + 0xa]
ram:008e5d 61f8 sknz
ram:008e5f ec0c9000 _br !!0x900c
ram:008e63 30feff movw AX,0xfffe
ram:008e66 61490a cmpw AX,[HL + 0xa]
ram:008e69 61f8 sknz
ram:008e6b ecce8e00 _br !!0x8ece
ram:008e6f fc80e000 call !!0xe080
ram:008ece fc80e000 call !!0xe080
ram:008fc7 7852c0 movw !0xfc052[BC],AX
ram:008fca c1 push AX
ram:008fcb ac0e movw AX,[HL + 0xe]
ram:008fcd fcf38800 call !!0x88f3
ram:00900c 1010 addw SP,0x10
ram:00900e c6 pop HL
ram:00900f d7 ret
ram:009254 c7 push HL
ram:009255 c1 push AX
ram:009256 fbf8ff movw HL,!0xffff8
ram:009259 ab movw AX,[HL]
ram:00925a 12 movw BC,AX
ram:00925b 4100 mov ES,0x0
ram:00925d 1149dc64 mov A,ES:!0xf64dc[BC]
ram:009261 4e08 cmp A,[HL + 0x8]
ram:009263 61d307 bnh $ 0x926c
ram:009266 8c08 mov A,[HL + 0x8]
ram:009268 4849c0 mov !0xfc049[BC],A
ram:00926b ef0e br $ 0x927b
ram:00926d ab movw AX,[HL]
ram:00926e 12 movw BC,AX
ram:00926f 4100 mov ES,0x0
ram:009271 1149dc64 mov A,ES:!0xf64dc[BC]
ram:009275 73 mov ,A
ram:009276 ab movw AX,[HL]
ram:009277 33 xchw AX,BC
ram:009278 4849c0 mov !0xfc049[BC],A
ram:00927b c0 pop AX
ram:00927c c6 pop HL
ram:00927d d7 ret
ram:00b97c c7 push HL
ram:00b97d c1 push AX
ram:00b97e c1 push AX
ram:00b97f fbf8ff movw HL,!0xffff8
ram:00b982 cc0103 mov [HL + 0x1],0x3
ram:00b985 8c02 mov A,[HL + 0x2]
ram:00b987 d1 cmp0 A
ram:00b988 dd15 bz $ 0xb99f
ram:00b98a db1ae4 movw BC,!0xfe41a
ram:00b98d 17 movw AX,HL
ram:00b98e a1 incw AX
ram:00b98f c1 push AX
ram:00b990 490e00 mov A,!0xf000e[BC]
ram:00b993 9efc mov CS,A
ram:00b995 790c00 movw AX,!0xf000c[BC]
ram:00b998 14 movw DE,AX
ram:00b999 303e00 movw AX,0x3e
ram:00b99c 61ea call DE
ram:00b99e c0 pop AX
ram:00b99f 1004 addw SP,0x4
ram:00b9a1 c6 pop HL
ram:00b9a2 d7 ret
ram:00c000 04cc02 addw AX,0x2cc
ram:00c003 13 movw AX,BC
ram:00c004 ac04 movw AX,[HL + 0x4]
ram:00c006 14 movw DE,AX
ram:00c007 89 mov A,[DE]
ram:00c008 9c03 mov [HL + 0x3],A
ram:00c00a e6 onew AX
ram:00c00b a1 incw AX
ram:00c00c c1 push AX
ram:00c00d 17 movw AX,HL
ram:00c00e 040200 addw AX,0x2
ram:00c011 c1 push AX
ram:00c012 306100 movw AX,0x61
ram:00c015 c1 push AX
ram:00c016 e6 onew AX
ram:00c017 a1 incw AX
ram:00c018 c1 push AX
ram:00c019 e6 onew AX
ram:00c01a fcb75401 call !!0x154b7
ram:00e080 8efa mov A,PSW
ram:00e082 72 mov ,A
ram:00e083 f3 clrb B
ram:00e084 d7 ret
ram:00e349 c7 push HL
ram:00e34a f6 clrw AX
ram:00e34b 16 movw HL,AX
ram:00e34c 17 movw AX,HL
ram:00e34d 444000 cmpw AX,0x40
ram:00e350 de08 bnc $ 0xe35a
ram:00e352 12 movw BC,AX
ram:00e353 3922c900 mov !0xfc922[BC],0x0
ram:00e357 a7 incw HL
ram:00e358 eff2 br $ 0xe34c
ram:00e35a e561c9 oneb !0xfc961
ram:00e35d f562d9 clrb !0xfd962
ram:00e360 cf63d93f mov !0xfd963,0x3f
ram:00e364 c6 pop HL
ram:00e365 d7 ret
ram:00f703 5c01 and A,#0x1
ram:00f705 318e shrw AX,0x8
ram:00f707 312d shlw AX,0x2
ram:00f709 12 movw BC,AX
ram:00f70a 313d shlw AX,0x3
ram:00f70c 03 addw AX,BC
ram:00f70d 0472d9 addw AX,0xd972
ram:00f710 bb movw [HL],AX
ram:00f711 cc0300 mov [HL + 0x3],0x0
ram:00f714 ab movw AX,[HL]
ram:00f715 14 movw DE,AX
ram:00f716 8a02 mov A,[DE + 0x2]
ram:00f718 4e03 cmp A,[HL + 0x3]
ram:00f71a 61d313 bnh $ 0xf72f
ram:00f71d 8c03 mov A,[HL + 0x3]
ram:00f71f 318e shrw AX,0x8
ram:00f721 a5 incw DE
ram:00f722 a5 incw DE
ram:00f723 a5 incw DE
ram:00f724 05 addw AX,DE
ram:00f725 14 movw DE,AX
ram:00f726 89 mov A,[DE]
ram:00f727 4e04 cmp A,[HL + 0x4]
ram:00f729 dd05 bz $ 0xf730
ram:00f72b 615903 inc [HL + 0x3]
ram:00f72e efe4 br $ 0xf714
ram:00f730 ab movw AX,[HL]
ram:00f731 14 movw DE,AX
ram:00f732 8a02 mov A,[DE + 0x2]
ram:00f734 4e03 cmp A,[HL + 0x3]
ram:00f736 df12 bnz $ 0xf74a
ram:00f738 8a02 mov A,[DE + 0x2]
ram:00f73a 4c20 cmp A,#0x20
ram:00f73c dc05 bc $ 0xf743
ram:00f73e cc031f mov [HL + 0x3],0x1f
ram:00f741 ef07 br $ 0xf74a
ram:00f743 ab movw AX,[HL]
ram:00f744 14 movw DE,AX
ram:00f745 8a02 mov A,[DE + 0x2]
ram:00f747 81 inc 
ram:00f748 9a02 mov [DE + 0x2],A
ram:00f74a 8c03 mov A,[HL + 0x3]
ram:00f74c d1 cmp0 A
ram:00f74d dd20 bz $ 0xf76f
ram:00f74f ab movw AX,[HL]
ram:00f750 14 movw DE,AX
ram:00f751 8c03 mov A,[HL + 0x3]
ram:00f753 91 dec 
ram:00f754 318e shrw AX,0x8
ram:00f756 a5 incw DE
ram:00f757 a5 incw DE
ram:00f758 a5 incw DE
ram:00f759 05 addw AX,DE
ram:00f75a 14 movw DE,AX
ram:00f75b 89 mov A,[DE]
ram:00f75c 72 mov ,A
ram:00f75d ab movw AX,[HL]
ram:00f75e 14 movw DE,AX
ram:00f75f 8c03 mov A,[HL + 0x3]
ram:00f761 318e shrw AX,0x8
ram:00f763 a5 incw DE
ram:00f764 a5 incw DE
ram:00f765 a5 incw DE
ram:00f766 05 addw AX,DE
ram:00f767 14 movw DE,AX
ram:00f768 62 mov A,
ram:00f769 99 mov [DE],A
ram:00f76a 616903 dec [HL + 0x3]
ram:00f76d efdb br $ 0xf74a
ram:00f76f ab movw AX,[HL]
ram:00f770 14 movw DE,AX
ram:00f771 a5 incw DE
ram:00f772 a5 incw DE
ram:00f773 a5 incw DE
ram:00f774 8c04 mov A,[HL + 0x4]
ram:00f776 99 mov [DE],A
ram:00f777 1006 addw SP,0x6
ram:00f779 c6 pop HL
ram:00f77a d7 ret
ram:00fbc1 791000 movw AX,!0xf0010[BC]
ram:00fbc4 c1 push AX
ram:00fbc5 8dd4 mov A,0xffdf4
ram:00fbc7 9dd6 mov 0xffdf6,A
ram:00fbc9 c0 pop AX
ram:00fbca 14 movw DE,AX
ram:00fbcb 305d12 movw AX,0x125d
ram:00fbce 320300 movw BC,0x3
ram:00fbd1 c1 push AX
ram:00fbd2 8dd6 mov A,0xffdf6
ram:00fbd4 9efc mov CS,A
ram:00fbd6 c0 pop AX
ram:00fbd7 61ea call DE
ram:00fff0 bdd8 movw 0xffdf8,AX
ram:00fff2 13 movw AX,BC
ram:00fff3 fd7304 call !0xf0473
ram:00ffff 19051230 mov !0xf1205[B],0x30
ram:010003 64 mov A,
ram:010004 00 nop
ram:010005 23 subw AX,BC
ram:010006 bc08 movw [HL + 0x8],AX
ram:010008 ac04 movw AX,[HL + 0x4]
ram:01000a bdd8 movw 0xffdf8,AX
ram:01000c 31ff sarw AX,0xf
ram:01000e bdda movw 0xffdfa,AX
ram:010010 add8 movw AX,0xffdf8
ram:010012 bddc movw 0xffdfc,AX
ram:010014 adda movw AX,0xffdfa
ram:010016 bdde movw 0xffdfe,AX
ram:010018 ac06 movw AX,[HL + 0x6]
ram:01001a bdd8 movw 0xffdf8,AX
ram:01001c 31ff sarw AX,0xf
ram:01001e bdda movw 0xffdfa,AX
ram:010020 adde movw AX,0xffdfe
ram:010022 fd8404 call !0xf0484
ram:014db6 c7 push HL
ram:014db7 c1 push AX
ram:014db8 2008 subw SP,0x8
ram:014dba fbf8ff movw HL,!0xffff8
ram:014dbd afd2e3 movw AX,!0xfe3d2
ram:014dc0 bc06 movw [HL + 0x6],AX
ram:014dc2 8c12 mov A,[HL + 0x12]
ram:014dc4 d1 cmp0 A
ram:014dc5 dd10 bz $ 0x14dd7
ram:014dc7 8c08 mov A,[HL + 0x8]
ram:014dc9 318e shrw AX,0x8
ram:014dcb c9d84402 movw 0xffdf8,0x244
ram:014dcf fd7304 call !0xf0473
ram:014dd2 12 movw BC,AX
ram:014dd3 3962dd00 mov !0xfdd62[BC],0x0
ram:014dd7 8c08 mov A,[HL + 0x8]
ram:014dd9 318e shrw AX,0x8
ram:014ddb c9d84402 movw 0xffdf8,0x244
ram:014ddf fd7304 call !0xf0473
ram:014de2 0462dd addw AX,0xdd62
ram:014de5 12 movw BC,AX
ram:014de6 490000 mov A,!0xf0000[BC]
ram:014de9 d1 cmp0 A
ram:014dea dd2b bz $ 0x14e17
ram:014dec 8c08 mov A,[HL + 0x8]
ram:014dee 318e shrw AX,0x8
ram:014df0 c9d84402 movw 0xffdf8,0x244
ram:014df4 fd7304 call !0xf0473
ram:014df7 0462dd addw AX,0xdd62
ram:014dfa 12 movw BC,AX
ram:014dfb 790200 movw AX,!0xf0002[BC]
ram:014dfe 12 movw BC,AX
ram:014dff ac06 movw AX,[HL + 0x6]
ram:014e01 23 subw AX,BC
ram:014e02 446500 cmpw AX,0x65
ram:014e05 dc10 bc $ 0x14e17
ram:014e07 8c08 mov A,[HL + 0x8]
ram:014e09 318e shrw AX,0x8
ram:014e0b c9d84402 movw 0xffdf8,0x244
ram:014e0f fd7304 call !0xf0473
ram:014e12 12 movw BC,AX
ram:014e13 3962dd00 mov !0xfdd62[BC],0x0
ram:014e17 8c08 mov A,[HL + 0x8]
ram:014e19 318e shrw AX,0x8
ram:014e1b c9d84402 movw 0xffdf8,0x244
ram:014e1f fd7304 call !0xf0473
ram:014e22 0462dd addw AX,0xdd62
ram:014e25 12 movw BC,AX
ram:014e26 490000 mov A,!0xf0000[BC]
ram:014e29 d1 cmp0 A
ram:014e2a dd24 bz $ 0x14e50
ram:014e2c 91 dec 
ram:014e2d dd6c bz $ 0x14e9b
ram:014e2f 91 dec 
ram:014e30 61f8 sknz
ram:014e32 ee8f00 _br $! 0x14ec4
ram:014e35 91 dec 
ram:014e36 61f8 sknz
ram:014e38 eeb300 _br $! 0x14eee
ram:014e3b 91 dec 
ram:014e3c 61f8 sknz
ram:014e3e ee2601 _br $! 0x14f67
ram:014e41 91 dec 
ram:014e42 61f8 sknz
ram:014e44 eef101 _br $! 0x15038
ram:014e47 91 dec 
ram:014e48 61f8 sknz
ram:014e4a ee0804 _br $! 0x15255
ram:014e4d ee1504 br $! 0x15265
ram:014e50 8c10 mov A,[HL + 0x10]
ram:014e52 4caa cmp A,#0xaa
ram:014e54 df3f bnz $ 0x14e95
ram:014e56 8c08 mov A,[HL + 0x8]
ram:014e58 d1 cmp0 A
ram:014e59 df12 bnz $ 0x14e6d
ram:014e5b 8c08 mov A,[HL + 0x8]
ram:014e5d 318e shrw AX,0x8
ram:014e5f c9d84402 movw 0xffdf8,0x244
ram:014e63 fd7304 call !0xf0473
ram:014e66 12 movw BC,AX
ram:014e67 3962dd01 mov !0xfdd62[BC],0x1
ram:014e6b ef2b br $ 0x14e98
ram:014e6d 8c08 mov A,[HL + 0x8]
ram:014e6f 318e shrw AX,0x8
ram:014e71 c9d84402 movw 0xffdf8,0x244
ram:014e75 fd7304 call !0xf0473
ram:014e78 12 movw BC,AX
ram:014e79 3962dd02 mov !0xfdd62[BC],0x2
ram:014e7d 8c08 mov A,[HL + 0x8]
ram:014e7f 318e shrw AX,0x8
ram:014e81 c9d84402 movw 0xffdf8,0x244
ram:014e85 fd7304 call !0xf0473
ram:014e88 0462dd addw AX,0xdd62
ram:014e8b 12 movw BC,AX
ram:014e8c 793c00 movw AX,!0xf003c[BC]
ram:014e8f 14 movw DE,AX
ram:014e90 ca0000 mov [DE + 0x0],0x0
ram:014e93 ef03 br $ 0x14e98
ram:014e95 cc10aa mov [HL + 0x10],0xaa
ram:014e98 eeca03 br $! 0x15265
ram:014e9b 8c08 mov A,[HL + 0x8]
ram:014e9d 318e shrw AX,0x8
ram:014e9f c9d84402 movw 0xffdf8,0x244
ram:014ea3 fd7304 call !0xf0473
ram:014ea6 0462dd addw AX,0xdd62
ram:014ea9 12 movw BC,AX
ram:014eaa 793c00 movw AX,!0xf003c[BC]
ram:014ead 14 movw DE,AX
ram:014eae 8c10 mov A,[HL + 0x10]
ram:014eb0 99 mov [DE],A
ram:014eb1 8c08 mov A,[HL + 0x8]
ram:014eb3 318e shrw AX,0x8
ram:014eb5 c9d84402 movw 0xffdf8,0x244
ram:014eb9 fd7304 call !0xf0473
ram:014ebc 12 movw BC,AX
ram:014ebd 3962dd02 mov !0xfdd62[BC],0x2
ram:014ec1 eea103 br $! 0x15265
ram:014ec4 8c08 mov A,[HL + 0x8]
ram:014ec6 318e shrw AX,0x8
ram:014ec8 c9d84402 movw 0xffdf8,0x244
ram:014ecc fd7304 call !0xf0473
ram:014ecf 0462dd addw AX,0xdd62
ram:014ed2 12 movw BC,AX
ram:014ed3 793c00 movw AX,!0xf003c[BC]
ram:014ed6 14 movw DE,AX
ram:014ed7 8c10 mov A,[HL + 0x10]
ram:014ed9 9a01 mov [DE + 0x1],A
ram:014edb 8c08 mov A,[HL + 0x8]
ram:014edd 318e shrw AX,0x8
ram:014edf c9d84402 movw 0xffdf8,0x244
ram:014ee3 fd7304 call !0xf0473
ram:014ee6 12 movw BC,AX
ram:014ee7 3962dd03 mov !0xfdd62[BC],0x3
ram:014eeb ee7703 br $! 0x15265
ram:014eee 8c08 mov A,[HL + 0x8]
ram:014ef0 318e shrw AX,0x8
ram:014ef2 c9d84402 movw 0xffdf8,0x244
ram:014ef6 fd7304 call !0xf0473
ram:014f67 8c08 mov A,[HL + 0x8]
ram:014f69 318e shrw AX,0x8
ram:014f6b c9d84402 movw 0xffdf8,0x244
ram:014f6f fd7304 call !0xf0473
ram:015038 8c08 mov A,[HL + 0x8]
ram:01503a 318e shrw AX,0x8
ram:01503c c9d84402 movw 0xffdf8,0x244
ram:015040 fd7304 call !0xf0473
ram:015255 8c08 mov A,[HL + 0x8]
ram:015257 318e shrw AX,0x8
ram:015259 c9d84402 movw 0xffdf8,0x244
ram:01525d fd7304 call !0xf0473
ram:015265 8c08 mov A,[HL + 0x8]
ram:015267 318e shrw AX,0x8
ram:015269 c9d84402 movw 0xffdf8,0x244
ram:01526d fd7304 call !0xf0473
ram:015270 0462dd addw AX,0xdd62
ram:015273 14 movw DE,AX
ram:015274 ac06 movw AX,[HL + 0x6]
ram:015276 ba02 movw [DE + 0x2],AX
ram:015278 100a addw SP,0xa
ram:01527a c6 pop HL
ram:01527b d7 ret
ram:0154b7 c7 push HL
ram:0154b8 c1 push AX
ram:0154b9 204a subw SP,0x4a
ram:0154bb fbf8ff movw HL,!0xffff8
ram:0154be cc05aa mov [HL + 0x5],0xaa
ram:0154c1 17 movw AX,HL
ram:0154c2 040600 addw AX,0x6
ram:0154c5 bc02 movw [HL + 0x2],AX
ram:0154c7 cc06aa mov [HL + 0x6],0xaa
ram:0154ca 8c52 mov A,[HL + 0x52]
ram:0154cc 5c0f and A,#0xf
ram:0154ce 70 mov ,A
ram:0154cf 8c07 mov A,[HL + 0x7]
ram:0154d1 5cf0 and A,#0xf0
ram:0154d3 6168 or A,
ram:0154d5 9c07 mov [HL + 0x7],A
ram:0154d7 8c4a mov A,[HL + 0x4a]
ram:0154d9 3149 shl A,0x4
ram:0154db 70 mov ,A
ram:0154dc 8c07 mov A,[HL + 0x7]
ram:0154de 5c0f and A,#0xf
ram:0154e0 6168 or A,
ram:0154e2 9c07 mov [HL + 0x7],A
ram:0154e4 8c54 mov A,[HL + 0x54]
ram:0154e6 9c08 mov [HL + 0x8],A
ram:0154e8 8c58 mov A,[HL + 0x58]
ram:0154ea 9c09 mov [HL + 0x9],A
ram:0154ec cc0100 mov [HL + 0x1],0x0
ram:0154ef 8c01 mov A,[HL + 0x1]
ram:0154f1 4e09 cmp A,[HL + 0x9]
ram:0154f3 de1a bnc $ 0x1550f
ram:0154f5 8c01 mov A,[HL + 0x1]
ram:0154f7 318e shrw AX,0x8
ram:0154f9 610956 addw AX,[HL + 0x56]
ram:0154fc 14 movw DE,AX
ram:0154fd 89 mov A,[DE]
ram:0154fe 72 mov ,A
ram:0154ff 8c01 mov A,[HL + 0x1]
ram:015501 318e shrw AX,0x8
ram:015503 07 addw AX,HL
ram:015504 040a00 addw AX,0xa
ram:015507 14 movw DE,AX
ram:015508 62 mov A,
ram:015509 99 mov [DE],A
ram:01550a 615901 inc [HL + 0x1]
ram:01550d efe0 br $ 0x154ef
ram:01550f cc0101 mov [HL + 0x1],0x1
ram:015512 8c09 mov A,[HL + 0x9]
ram:015514 0c04 add A,#0x4
ram:015516 4e01 cmp A,[HL + 0x1]
ram:015518 61d312 bnh $ 0x1552c
ram:01551b 8c01 mov A,[HL + 0x1]
ram:01551d 318e shrw AX,0x8
ram:01551f 610902 addw AX,[HL + 0x2]
ram:015522 14 movw DE,AX
ram:015523 89 mov A,[DE]
ram:015524 7e05 xor A,[HL + 0x5]
ram:015526 9c05 mov [HL + 0x5],A
ram:015528 615901 inc [HL + 0x1]
ram:01552b efe5 br $ 0x15512
ram:027350 c7 push HL
ram:027351 c1 push AX
ram:027352 c1 push AX
ram:027353 fbf8ff movw HL,!0xffff8
ram:027356 cc0100 mov [HL + 0x1],0x0
ram:027359 8c01 mov A,[HL + 0x1]
ram:02735b d1 cmp0 A
ram:02735c df1d bnz $ 0x2737b
ram:02735e 8c01 mov A,[HL + 0x1]
ram:027360 f0 clrb X
ram:027361 317e shrw AX,0x7
ram:027363 12 movw BC,AX
ram:027364 4100 mov ES,0x0
ram:027366 1179f06d movw AX,ES:!0xf6df0[BC]
ram:02736a 614902 cmpw AX,[HL + 0x2]
ram:02736d df07 bnz $ 0x27376
ram:02736f 8c01 mov A,[HL + 0x1]
ram:027371 72 mov ,A
ram:027372 38d1e300 mov !0xfe3d1[C],0x0
ram:027376 615901 inc [HL + 0x1]
ram:027379 efde br $ 0x27359
ram:02737b 1004 addw SP,0x4
ram:02737d c6 pop HL
ram:02737e d7 ret
ram:02737f c7 push HL
ram:027380 16 movw HL,AX
ram:027381 ac08 movw AX,[HL + 0x8]
ram:027383 440500 cmpw AX,0x5
ram:027386 dc03 bc $ 0x2738b
ram:027388 e7 onew BC
ram:027389 ef0c br $ 0x27397
ram:02738b 8fcbe3 mov A,!0xfe3cb
ram:02738e 5c0c and A,#0xc
ram:027390 d1 cmp0 A
ram:027391 df03 bnz $ 0x27396
ram:027393 f7 clrw BC
ram:027394 ef01 br $ 0x27397
ram:027396 e7 onew BC
ram:027397 c6 pop HL
ram:027398 d7 ret
ram:027d68 d7 ret
ram:027d69 fb80bf movw HL,!0xfbf80
ram:027d6c f6 clrw AX
ram:027d6d 47 cmpw AX,HL
ram:027d6e dd13 bz $ 0x27d83
ram:027d70 b7 decw HL
ram:027d71 c7 push HL
ram:027d72 17 movw AX,HL
ram:027d73 312d shlw AX,0x2
ram:027d75 0400bf addw AX,0xbf00
ram:027d78 16 movw HL,AX
ram:027d79 8c02 mov A,[HL + 0x2]
ram:027d7b 9efc mov CS,A
ram:027d7d ab movw AX,[HL]
ram:027d7e c6 pop HL
ram:027d7f 61ca call AX
ram:027d81 efe9 br $ 0x27d6c
ram:027d83 effe br $ 0x27d83
