ram:0000da 5208 mov ,0x8
ram:0000dc ef06 br $ 0xe4
ram:0000de 5203 mov ,0x3
ram:0000e0 ef02 br $ 0xe4
ram:0000e2 5206 mov ,0x6
ram:0000e4 fef600 call $! 0x1dd
ram:0000e7 fe1b00 call $! 0x105
ram:0000ea dc16 bc $ 0x102
ram:0000ec 08 xch A,X
ram:0000ed 9f0308 mov !0xf0803,A
ram:0000f0 8f0408 mov A,!0xf0804
ram:0000f3 08 xch A,X
ram:0000f4 9f0408 mov !0xf0804,A
ram:0000f7 62 mov A,
ram:0000f8 fe2000 call $! 0x11b
ram:0000fb 08 xch A,X
ram:0000fc 9f0408 mov !0xf0804,A
ram:0000ff eecf00 br $! 0x1d1
ram:000102 eeca00 br $! 0x1cf
ram:000105 c1 push AX
ram:000106 c5 push DE
ram:000107 14 movw DE,AX
ram:000108 410e mov ES,0xe
ram:00010a 11afe4ff movw AX,ES:!0xfffe4
ram:00010e 5c03 and A,#0x3
ram:000110 45 cmpw AX,DE
ram:000111 c4 pop DE
ram:000112 c0 pop AX
ram:000113 d7 ret
ram:000114 f2 clrb C
ram:000115 31a2c401 bt 0xfffc4.0x2,$ 0x118
ram:000119 e2 oneb C
ram:00011a d7 ret
ram:00011b 9de2 mov 0xffe02,A
ram:00011d 61dd push PSW
ram:00011f 4c09 cmp A,#0x9
ram:000121 df12 bnz $ 0x135
ram:000123 717bfa DI
ram:000126 c1 push AX
ram:000127 8f0608 mov A,!0xf0806
ram:00012a 9fafea mov !0xfeaaf,A
ram:00012d c0 pop AX
ram:00012e cf060800 mov !0xf0806,0x0
ram:000132 ee2700 br $! 0x15c
ram:000135 31f2fa04 bt PSW.0x7,$ 0x13b
ram:000139 cf060800 mov !0xf0806,0x0
ram:00013d 4c00 cmp A,#0x0
ram:00013f df05 bnz $ 0x146
ram:000141 d50008 cmp0 !0xf0800
ram:000144 dd16 bz $ 0x15c
ram:000146 61dd push PSW
ram:000148 717bfa DI
ram:00014b d50608 cmp0 !0xf0806
ram:00014e dd0a bz $ 0x15a
ram:000150 cde31f mov 0xffe03,0x1f
ram:000153 61cd pop PSW
ram:000155 61cd pop PSW
ram:000157 ee1600 br $! 0x170
ram:00015a 61cd pop PSW
ram:00015c fef400 call $! 0x253
ram:00015f 61ff SEL RB3
ram:000161 feae00 call $! 0x212
ram:000164 fcf8ff0e call !!0xefff8
ram:000168 fecd00 call $! 0x238
ram:00016b 61cd pop PSW
ram:00016d fef500 call $! 0x265
ram:000170 4c09 cmp A,#0x9
ram:000172 df0e bnz $ 0x182
ram:000174 c1 push AX
ram:000175 8f0608 mov A,!0xf0806
ram:000178 6fafea or A,!0xfeaaf
ram:00017b 9f0608 mov !0xf0806,A
ram:00017e c0 pop AX
ram:00017f ee0400 br $! 0x186
ram:000182 cf060800 mov !0xf0806,0x0
ram:000186 f8e3 mov C,0xffe03
ram:000188 d7 ret
ram:000189 5200 mov ,0x0
ram:00018b ef02 br $ 0x18f
ram:00018d 5202 mov ,0x2
ram:00018f fe4b00 call $! 0x1dd
ram:000192 cfaeea00 mov !0xfeaae,0x0
ram:000196 cfb0ea00 mov !0xfeab0,0x0
ram:00019a cf060800 mov !0xf0806,0x0
ram:00019e bf0408 movw !0xf0804,AX
ram:0001a1 c7 push HL
ram:0001a2 16 movw HL,AX
ram:0001a3 62 mov A,
ram:0001a4 9f0008 mov !0xf0800,A
ram:0001a7 4100 mov ES,0x0
ram:0001a9 118fd800 mov A,ES:!0xf00d8
ram:0001ad 9b mov [HL],A
ram:0001ae c6 pop HL
ram:0001af 410e mov ES,0xe
ram:0001b1 114fe2ff cmp A,ES:!0xfffe2
ram:0001b5 dc18 bc $ 0x1cf
ram:0001b7 11f9e3ff mov C,ES:!0xfffe3
ram:0001bb 6142 cmp ,A
ram:0001bd dc10 bc $ 0x1cf
ram:0001bf 4100 mov ES,0x0
ram:0001c1 118fd900 mov A,ES:!0xf00d9
ram:0001c5 9f0108 mov !0xf0801,A
ram:0001c8 5100 mov ,0x0
ram:0001ca fe4eff call $! 0x11b
ram:0001cd ef02 br $ 0x1d1
ram:0001cf 5205 mov ,0x5
ram:0001d1 cf060800 mov !0xf0806,0x0
ram:0001d5 c1 push AX
ram:0001d6 510c mov ,0xc
ram:0001d8 fe0a00 call $! 0x1e5
ram:0001db c0 pop AX
ram:0001dc d7 ret
ram:0001dd c1 push AX
ram:0001de 511d mov ,0x1d
ram:0001e0 fe0200 call $! 0x1e5
ram:0001e3 c0 pop AX
ram:0001e4 d7 ret
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
ram:000212 31f2fa21 bt PSW.0x7,$ 0x235
ram:000216 c1 push AX
ram:000217 aee4 movw AX,0xfffe4
ram:000219 bf9eea movw !0xfea9e,AX
ram:00021c aee6 movw AX,0xfffe6
ram:00021e bfa0ea movw !0xfeaa0,AX
ram:000221 aed4 movw AX,0xfffd4
ram:000223 bfa2ea movw !0xfeaa2,AX
ram:000226 aed6 movw AX,0xfffd6
ram:000228 bfa4ea movw !0xfeaa4,AX
ram:00022b 30ffff movw AX,0xffff
ram:00022e bee4 movw 0xfffe4,AX
ram:000230 bee6 movw 0xfffe6,AX
ram:000232 bed4 movw 0xfffd4,AX
ram:000234 bed6 movw 0xfffd6,AX
ram:000236 c0 pop AX
ram:000237 d7 ret
ram:000238 31f2fa16 bt PSW.0x7,$ 0x250
ram:00023c c1 push AX
ram:00023d af9eea movw AX,!0xfea9e
ram:000240 bee4 movw 0xfffe4,AX
ram:000242 afa0ea movw AX,!0xfeaa0
ram:000245 bee6 movw 0xfffe6,AX
ram:000247 afa2ea movw AX,!0xfeaa2
ram:00024a bed4 movw 0xfffd4,AX
ram:00024c afa4ea movw AX,!0xfeaa4
ram:00024f bed6 movw 0xfffd6,AX
ram:000251 c0 pop AX
ram:000252 d7 ret
ram:000253 c1 push AX
ram:000254 bfa6ea movw !0xfeaa6,AX
ram:000257 13 movw AX,BC
ram:000258 bfa8ea movw !0xfeaa8,AX
ram:00025b 15 movw AX,DE
ram:00025c bfaaea movw !0xfeaaa,AX
ram:00025f 17 movw AX,HL
ram:000260 bfacea movw !0xfeaac,AX
ram:000263 c0 pop AX
ram:000264 d7 ret
ram:000265 afa6ea movw AX,!0xfeaa6
ram:000268 dba8ea movw BC,!0xfeaa8
ram:00026b ebaaea movw DE,!0xfeaaa
ram:00026e fbacea movw HL,!0xfeaac
ram:000271 d7 ret
ram:000284 c1 push AX
ram:000285 50fe mov ,0xfe
ram:000287 ee0000 br $! 0x28a
ram:00028a fe50ff call $! 0x1dd
ram:00028d d5aeea cmp0 !0xfeaae
ram:000290 df23 bnz $ 0x2b5
ram:000292 c1 push AX
ram:000293 cf030803 mov !0xf0803,0x3
ram:000297 5109 mov ,0x9
ram:000299 fe7ffe call $! 0x11b
ram:00029c c0 pop AX
ram:00029d d2 cmp0 C
ram:00029e df2d bnz $ 0x2cd
ram:0002a0 fe2e00 call $! 0x2d1
ram:0002a3 a20408 incw !0xf0804
ram:0002a6 cf030807 mov !0xf0803,0x7
ram:0002aa 5109 mov ,0x9
ram:0002ac fe6cfe call $! 0x11b
ram:0002af d2 cmp0 C
ram:0002b0 b20408 decw !0xf0804
ram:0002b3 df18 bnz $ 0x2cd
ram:0002b5 510a mov ,0xa
ram:0002b7 fe61fe call $! 0x11b
ram:0002ba 62 mov A,
ram:0002bb 4c1f cmp A,#0x1f
ram:0002bd df06 bnz $ 0x2c5
ram:0002bf cfaeea01 mov !0xfeaae,0x1
ram:0002c3 ef04 br $ 0x2c9
ram:0002c5 cfaeea00 mov !0xfeaae,0x0
ram:0002c9 c0 pop AX
ram:0002ca ee04ff br $! 0x1d1
ram:0002cd c0 pop AX
ram:0002ce eefefe br $! 0x1cf
ram:0002d1 c7 push HL
ram:0002d2 c1 push AX
ram:0002d3 fb0408 movw HL,!0xf0804
ram:0002d6 8b mov A,[HL]
ram:0002d7 3119 shl A,0x1
ram:0002d9 6c01 or A,#0x1
ram:0002db 6158 and A,
ram:0002dd 9b mov [HL],A
ram:0002de c0 pop AX
ram:0002df c6 pop HL
ram:0002e0 d7 ret
ram:0002e1 fef9fe call $! 0x1dd
ram:0002e4 c1 push AX
ram:0002e5 c3 push BC
ram:0002e6 c7 push HL
ram:0002e7 c5 push DE
ram:0002e8 eb0408 movw DE,!0xf0804
ram:0002eb 361403 movw HL,0x314
ram:0002ee 300000 movw AX,0x0
ram:0002f1 523d mov ,0x3d
ram:0002f3 f3 clrb B
ram:0002f4 fe0f00 call $! 0x306
ram:0002f7 c4 pop DE
ram:0002f8 c6 pop HL
ram:0002f9 c2 pop BC
ram:0002fa cefc0f mov CS,0xf
ram:0002fd af0408 movw AX,!0xf0804
ram:000300 61ca call AX
ram:000302 c0 pop AX
ram:000303 eecbfe br $! 0x1d1
ram:000306 08 xch A,X
ram:000307 9efd mov ES,A
ram:000309 f3 clrb B
ram:00030a 1161c9 mov A,ES:[HL + B]
ram:00030d 99 mov [DE],A
ram:00030e a5 incw DE
ram:00030f 83 inc 
ram:000310 92 dec 
ram:000311 dff7 bnz $ 0x30a
ram:000313 d7 ret
ram:000351 c5 push DE
ram:000352 5404 mov ,0x4
ram:000354 ef03 br $ 0x359
ram:000359 fe81fe call $! 0x1dd
ram:00035c c7 push HL
ram:00035d 360008 movw HL,0x800
ram:000360 bb movw [HL],AX
ram:000361 62 mov A,
ram:000362 9c02 mov [HL + 0x2],A
ram:000364 8808 mov A,[SP + 0x8]
ram:000366 9c03 mov [HL + 0x3],A
ram:000368 d1 cmp0 A
ram:000369 dd33 bz $ 0x39e
ram:00036b 4c41 cmp A,#0x41
ram:00036d de2f bnc $ 0x39e
ram:00036f 70 mov ,A
ram:000370 f1 clrb A
ram:000371 312d shlw AX,0x2
ram:000373 b1 decw AX
ram:000374 610900 addw AX,[HL + 0x0]
ram:000377 33 xchw AX,BC
ram:000378 08 xch A,X
ram:000379 1c00 addc A,#0x0
ram:00037b 08 xch A,X
ram:00037c 51ff mov ,0xff
ram:00037e 612a sub A,
ram:000380 410e mov ES,0xe
ram:000382 118fd0ff mov A,ES:!0xfffd0
ram:000386 613b subc A,
ram:000388 118fd1ff mov A,ES:!0xfffd1
ram:00038c 6138 subc A,
ram:00038e dc0e bc $ 0x39e
ram:000390 8b mov A,[HL]
ram:000391 5c03 and A,#0x3
ram:000393 df09 bnz $ 0x39e
ram:000395 64 mov A,
ram:000396 c6 pop HL
ram:000397 c4 pop DE
ram:000398 fe80fd call $! 0x11b
ram:00039b ee33fe br $! 0x1d1
ram:00039e c6 pop HL
ram:00039f c4 pop DE
ram:0003a0 ee2cfe br $! 0x1cf
ram:0003a3 c1 push AX
ram:0003a4 d5b0ea cmp0 !0xfeab0
ram:0003a7 df09 bnz $ 0x3b2
ram:0003a9 fed8fe call $! 0x284
ram:0003ac d2 cmp0 C
ram:0003ad df11 bnz $ 0x3c0
ram:0003af e5b0ea oneb !0xfeab0
ram:0003b2 fe28fe call $! 0x1dd
ram:0003b5 510c mov ,0xc
ram:0003b7 fe61fd call $! 0x11b
ram:0003ba d2 cmp0 C
ram:0003bb df03 bnz $ 0x3c0
ram:0003bd f5b0ea clrb !0xfeab0
ram:0003c0 c0 pop AX
ram:0003c1 fe19fe call $! 0x1dd
ram:0003c4 ee0afe br $! 0x1d1
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
ram:000484 c3 push BC
ram:000485 61dd push PSW
ram:000487 717bfa DI
ram:00048a bef0 movw 0xffff0,AX
ram:00048c add8 movw AX,0xffdf8
ram:00048e bef2 movw 0xffff2,AX
ram:000490 00 nop
ram:000491 dbf6ff movw BC,!0xffff6
ram:000494 addc movw AX,0xffdfc
ram:000496 bef0 movw 0xffff0,AX
ram:000498 00 nop
ram:000499 aef6 movw AX,0xffff6
ram:00049b bdd8 movw 0xffdf8,AX
ram:00049d aef4 movw AX,0xffff4
ram:00049f 03 addw AX,BC
ram:0004a0 12 movw BC,AX
ram:0004a1 adda movw AX,0xffdfa
ram:0004a3 bef2 movw 0xffff2,AX
ram:0004a5 00 nop
ram:0004a6 aef6 movw AX,0xffff6
ram:0004a8 61cd pop PSW
ram:0004aa 03 addw AX,BC
ram:0004ab bdda movw 0xffdfa,AX
ram:0004ad c2 pop BC
ram:0004ae d7 ret
ram:000519 c3 push BC
ram:00051a f3 clrb B
ram:00051b 3174d908 bf 0xffdf9.0x7,$ 0x525
ram:00051f 83 inc 
ram:000520 c1 push AX
ram:000521 f6 clrw AX
ram:000522 26d8 subw AX,0xffdf8
ram:000524 bdd8 movw 0xffdf8,AX
ram:000526 c0 pop AX
ram:000527 317506 bf A.0x7,$ 0x52f
ram:00052a 83 inc 
ram:00052b c3 push BC
ram:00052c 12 movw BC,AX
ram:00052d f6 clrw AX
ram:00052e 23 subw AX,BC
ram:00052f c2 pop BC
ram:000530 fd3b05 call !0xf053b
ram:000533 93 dec 
ram:000534 df03 bnz $ 0x539
ram:000536 12 movw BC,AX
ram:000537 f6 clrw AX
ram:000538 23 subw AX,BC
ram:000539 c2 pop BC
ram:00053a d7 ret
ram:00053b 440000 cmpw AX,0x0
ram:00053e dd26 bz $ 0x566
ram:000540 61dd push PSW
ram:000542 717bfa DI
ram:000545 cfe80080 mov !0xf00e8,0x80
ram:000549 bef6 movw 0xffff6,AX
ram:00054b f6 clrw AX
ram:00054c bef4 movw 0xffff4,AX
ram:00054e bef2 movw 0xffff2,AX
ram:000550 add8 movw AX,0xffdf8
ram:000552 bef0 movw 0xffff0,AX
ram:000554 cfe80081 mov !0xf00e8,0x81
ram:000558 8fe800 mov A,!0xf00e8
ram:00055b 3103fa bt A.0x0,$ 0x557
ram:00055e aef0 movw AX,0xffff0
ram:000560 f5e800 clrb !0xf00e8
ram:000563 61cd pop PSW
ram:000565 d7 ret
ram:000566 b1 decw AX
ram:000567 d7 ret
ram:000568 c3 push BC
ram:000569 f3 clrb B
ram:00056a 3174db0f bf 0xffdfb.0x7,$ 0x57b
ram:00056e 83 inc 
ram:00056f c1 push AX
ram:000570 f6 clrw AX
ram:000571 26d8 subw AX,0xffdf8
ram:000573 bdd8 movw 0xffdf8,AX
ram:000575 6131 subc ,A
ram:000577 70 mov ,A
ram:000578 26da subw AX,0xffdfa
ram:00057a bdda movw 0xffdfa,AX
ram:00057c c0 pop AX
ram:00057d 31750d bf A.0x7,$ 0x58c
ram:000580 83 inc 
ram:000581 c3 push BC
ram:000582 12 movw BC,AX
ram:000583 f6 clrw AX
ram:000584 26dc subw AX,0xffdfc
ram:000586 bddc movw 0xffdfc,AX
ram:000588 6131 subc ,A
ram:00058a 70 mov ,A
ram:00058b 23 subw AX,BC
ram:00058c c2 pop BC
ram:00058d fda105 call !0xf05a1
ram:000590 93 dec 
ram:000591 df0c bnz $ 0x59f
ram:000593 f6 clrw AX
ram:000594 26d8 subw AX,0xffdf8
ram:000596 bdd8 movw 0xffdf8,AX
ram:000598 6131 subc ,A
ram:00059a 70 mov ,A
ram:00059b 26da subw AX,0xffdfa
ram:00059d bdda movw 0xffdfa,AX
ram:00059f c2 pop BC
ram:0005a0 d7 ret
ram:0005a1 c1 push AX
ram:0005a2 6168 or A,
ram:0005a4 6bdc or A,0xffdfc
ram:0005a6 6bdd or A,0xffdfd
ram:0005a8 c0 pop AX
ram:0005a9 dd2f bz $ 0x5da
ram:0005ab 61dd push PSW
ram:0005ad 717bfa DI
ram:0005b0 cfe80080 mov !0xf00e8,0x80
ram:0005b4 bef4 movw 0xffff4,AX
ram:0005b6 addc movw AX,0xffdfc
ram:0005b8 bef6 movw 0xffff6,AX
ram:0005ba add8 movw AX,0xffdf8
ram:0005bc bef0 movw 0xffff0,AX
ram:0005be adda movw AX,0xffdfa
ram:0005c0 bef2 movw 0xffff2,AX
ram:0005c2 cfe80081 mov !0xf00e8,0x81
ram:0005c6 8fe800 mov A,!0xf00e8
ram:0005c9 3103fa bt A.0x0,$ 0x5c5
ram:0005cc aef0 movw AX,0xffff0
ram:0005ce bdd8 movw 0xffdf8,AX
ram:0005d0 aef2 movw AX,0xffff2
ram:0005d2 bdda movw 0xffdfa,AX
ram:0005d4 f5e800 clrb !0xf00e8
ram:0005d7 61cd pop PSW
ram:0005d9 d7 ret
ram:0005da f6 clrw AX
ram:0005db bdd8 movw 0xffdf8,AX
ram:0005dd bdda movw 0xffdfa,AX
ram:0005df d7 ret
ram:0005e0 c1 push AX
ram:0005e1 6168 or A,
ram:0005e3 6bdc or A,0xffdfc
ram:0005e5 6bdd or A,0xffdfd
ram:0005e7 c0 pop AX
ram:0005e8 61f8 sknz
ram:0005ea d7 _ret
ram:0005eb 61dd push PSW
ram:0005ed 717bfa DI
ram:0005f0 cfe80080 mov !0xf00e8,0x80
ram:0005f4 bef4 movw 0xffff4,AX
ram:0005f6 addc movw AX,0xffdfc
ram:0005f8 bef6 movw 0xffff6,AX
ram:0005fa add8 movw AX,0xffdf8
ram:0005fc bef0 movw 0xffff0,AX
ram:0005fe adda movw AX,0xffdfa
ram:000600 bef2 movw 0xffff2,AX
ram:000602 cfe80081 mov !0xf00e8,0x81
ram:000606 8fe800 mov A,!0xf00e8
ram:000609 3103fa bt A.0x0,$ 0x605
ram:00060c afe000 movw AX,!0xf00e0
ram:00060f bdd8 movw 0xffdf8,AX
ram:000611 afe200 movw AX,!0xf00e2
ram:000614 bdda movw 0xffdfa,AX
ram:000616 f5e800 clrb !0xf00e8
ram:000619 61cd pop PSW
ram:00061b d7 ret
ram:00061c 82 inc 
ram:00061d 92 dec 
ram:00061e dd2b bz $ 0x64b
ram:000620 61dd push PSW
ram:000622 717bfa DI
ram:000625 cfe80080 mov !0xf00e8,0x80
ram:000629 bef0 movw 0xffff0,AX
ram:00062b f6 clrw AX
ram:00062c bef2 movw 0xffff2,AX
ram:00062e bef4 movw 0xffff4,AX
ram:000630 62 mov A,
ram:000631 08 xch A,X
ram:000632 bef6 movw 0xffff6,AX
ram:000634 cfe80081 mov !0xf00e8,0x81
ram:000638 8fe800 mov A,!0xf00e8
ram:00063b 3103fa bt A.0x0,$ 0x637
ram:00063e afe000 movw AX,!0xf00e0
ram:000641 60 mov A,
ram:000642 72 mov ,A
ram:000643 aef0 movw AX,0xffff0
ram:000645 f5e800 clrb !0xf00e8
ram:000648 61cd pop PSW
ram:00064a d7 ret
ram:00064b 60 mov A,
ram:00064c 72 mov ,A
ram:00064d f6 clrw AX
ram:00064e b1 decw AX
ram:00064f d7 ret
ram:000650 06da addw AX,0xffdfa
ram:000652 bdda movw 0xffdfa,AX
ram:000654 addc movw AX,0xffdfc
ram:000656 06d8 addw AX,0xffdf8
ram:000658 bdd8 movw 0xffdf8,AX
ram:00065a 61d8 sknc
ram:00065c a6da _incw 0xffdfa
ram:00065e d7 ret
ram:00065f c3 push BC
ram:000660 12 movw BC,AX
ram:000661 add8 movw AX,0xffdf8
ram:000663 26dc subw AX,0xffdfc
ram:000665 bdd8 movw 0xffdf8,AX
ram:000667 6131 subc ,A
ram:000669 70 mov ,A
ram:00066a 06da addw AX,0xffdfa
ram:00066c 23 subw AX,BC
ram:00066d bdda movw 0xffdfa,AX
ram:00066f c2 pop BC
ram:000670 d7 ret
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
ram:0006ab 46d8 cmpw AX,0xffdf8
ram:0006ad dd07 bz $ 0x6b6
ram:0006af 71ff xor1 CY,A.0x7
ram:0006b1 7177d9 xor1 CY,0xffdf9.0x7
ram:0006b4 71c0 not1 CY
ram:0006b6 d7 ret
ram:0006b7 5bdb and A,0xffdfb
ram:0006b9 9ddb mov 0xffdfb,A
ram:0006bb 60 mov A,
ram:0006bc 5bda and A,0xffdfa
ram:0006be 9dda mov 0xffdfa,A
ram:0006c0 addc movw AX,0xffdfc
ram:0006c2 5bd9 and A,0xffdf9
ram:0006c4 08 xch A,X
ram:0006c5 5bd8 and A,0xffdf8
ram:0006c7 08 xch A,X
ram:0006c8 bdd8 movw 0xffdf8,AX
ram:0006ca d7 ret
ram:0006cb 6bdb or A,0xffdfb
ram:0006cd 9ddb mov 0xffdfb,A
ram:0006cf 60 mov A,
ram:0006d0 6bda or A,0xffdfa
ram:0006d2 9dda mov 0xffdfa,A
ram:0006d4 addc movw AX,0xffdfc
ram:0006d6 6bd9 or A,0xffdf9
ram:0006d8 08 xch A,X
ram:0006d9 6bd8 or A,0xffdf8
ram:0006db 08 xch A,X
ram:0006dc bdd8 movw 0xffdf8,AX
ram:0006de d7 ret
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
ram:001087 51c0 mov ,0xc0
ram:001089 5f06e9 and A,!0xfe906
ram:00108c 318e shrw AX,0x8
ram:00108e 6fffe8 or A,!0xfe8ff
ram:001091 08 xch A,X
ram:001092 6ffee8 or A,!0xfe8fe
ram:001095 08 xch A,X
ram:001096 bffee8 movw !0xfe8fe,AX
ram:001099 e1 oneb A
ram:00109a 5f06e9 and A,!0xfe906
ram:00109d 318e shrw AX,0x8
ram:00109f 318d shlw AX,0x8
ram:0010a1 6fffe8 or A,!0xfe8ff
ram:0010a4 08 xch A,X
ram:0010a5 6ffee8 or A,!0xfe8fe
ram:0010a8 08 xch A,X
ram:0010a9 bffee8 movw !0xfe8fe,AX
ram:0010ac 71230a clr1 0xffe2a.0x2
ram:0010af 712a2a set1 0xfff2a.0x2
ram:0010b2 713b2a clr1 0xfff2a.0x3
ram:0010b5 71320a set1 0xffe2a.0x3
ram:0010b8 affee8 movw AX,!0xfe8fe
ram:0010bb 4200e9 cmpw AX,!0xfe900
ram:0010be df15 bnz $ 0x10d5
ram:0010c0 aff6e8 movw AX,!0xfe8f6
ram:0010c3 5cfe and A,#0xfe
ram:0010c5 f0 clrb X
ram:0010c6 bc0c movw [HL + 0xc],AX
ram:0010c8 affee8 movw AX,!0xfe8fe
ram:0010cb 6e0d or A,[HL + 0xd]
ram:0010cd 08 xch A,X
ram:0010ce 6e0c or A,[HL + 0xc]
ram:0010d0 08 xch A,X
ram:0010d1 bc0c movw [HL + 0xc],AX
ram:0010d3 ef24 br $ 0x10f9
ram:0010d5 f6 clrw AX
ram:0010d6 42fee8 cmpw AX,!0xfe8fe
ram:0010d9 df18 bnz $ 0x10f3
ram:0010db 4200e9 cmpw AX,!0xfe900
ram:0010de dd13 bz $ 0x10f3
ram:0010e0 aff6e8 movw AX,!0xfe8f6
ram:0010e3 5cfe and A,#0xfe
ram:0010e5 f0 clrb X
ram:0010e6 bc0c movw [HL + 0xc],AX
ram:0010e8 affee8 movw AX,!0xfe8fe
ram:0010eb 6e0d or A,[HL + 0xd]
ram:0010ed 08 xch A,X
ram:0010ee 6e0c or A,[HL + 0xc]
ram:0010f0 08 xch A,X
ram:0010f1 bc0c movw [HL + 0xc],AX
ram:0010f3 affee8 movw AX,!0xfe8fe
ram:0010f6 bf00e9 movw !0xfe900,AX
ram:0010f9 8ffce8 mov A,!0xfe8fc
ram:0010fc 81 inc 
ram:0010fd 9ffce8 mov !0xfe8fc,A
ram:001100 edc511 br !0xf11c5
ram:001103 51c0 mov ,0xc0
ram:001105 5b09 and A,0xffe29
ram:001107 318e shrw AX,0x8
ram:001109 316e shrw AX,0x6
ram:00110b 12 movw BC,AX
ram:00110c e1 oneb A
ram:00110d 5b0a and A,0xffe2a
ram:00110f 318e shrw AX,0x8
ram:001111 312d shlw AX,0x2
ram:001113 616b or A,
ram:001115 08 xch A,X
ram:001116 616a or A,
ram:001118 08 xch A,X
ram:001119 bc04 movw [HL + 0x4],AX
ram:00111b 8c0c mov A,[HL + 0xc]
ram:00111d 70 mov ,A
ram:00111e 8c0d mov A,[HL + 0xd]
ram:001120 5cf9 and A,#0xf9
ram:001122 bc0c movw [HL + 0xc],AX
ram:001124 8ffde8 mov A,!0xfe8fd
ram:001127 5c07 and A,#0x7
ram:001129 318e shrw AX,0x8
ram:00112b 614904 cmpw AX,[HL + 0x4]
ram:00112e dd6d bz $ 0x119d
ram:001130 e6 onew AX
ram:001131 614904 cmpw AX,[HL + 0x4]
ram:001134 dd0d bz $ 0x1143
ram:001136 a1 incw AX
ram:001137 614904 cmpw AX,[HL + 0x4]
ram:00113a dd07 bz $ 0x1143
ram:00113c a1 incw AX
ram:00113d a1 incw AX
ram:00113e 614904 cmpw AX,[HL + 0x4]
ram:001141 df5a bnz $ 0x119d
ram:001143 8ffde8 mov A,!0xfe8fd
ram:001146 5c07 and A,#0x7
ram:001148 d1 cmp0 A
ram:001149 dd43 bz $ 0x118e
ram:00114b 8ffde8 mov A,!0xfe8fd
ram:00114e 5c07 and A,#0x7
ram:001150 91 dec 
ram:001151 df07 bnz $ 0x115a
ram:001153 e6 onew AX
ram:001154 a1 incw AX
ram:001155 614904 cmpw AX,[HL + 0x4]
ram:001158 dd20 bz $ 0x117a
ram:00115a 8ffde8 mov A,!0xfe8fd
ram:00115d 5c07 and A,#0x7
ram:00115f 4c02 cmp A,#0x2
ram:001161 df08 bnz $ 0x116b
ram:001163 300400 movw AX,0x4
ram:001166 614904 cmpw AX,[HL + 0x4]
ram:001169 dd0f bz $ 0x117a
ram:00116b 8ffde8 mov A,!0xfe8fd
ram:00116e 5c07 and A,#0x7
ram:001170 4c04 cmp A,#0x4
ram:001172 df11 bnz $ 0x1185
ram:001174 e6 onew AX
ram:001175 614904 cmpw AX,[HL + 0x4]
ram:001178 df0b bnz $ 0x1185
ram:00117a 8c0c mov A,[HL + 0xc]
ram:00117c 70 mov ,A
ram:00117d 8c0d mov A,[HL + 0xd]
ram:00117f 6c02 or A,#0x2
ram:001181 bc0c movw [HL + 0xc],AX
ram:001183 ef09 br $ 0x118e
ram:001185 8c0c mov A,[HL + 0xc]
ram:001187 70 mov ,A
ram:001188 8c0d mov A,[HL + 0xd]
ram:00118a 6c04 or A,#0x4
ram:00118c bc0c movw [HL + 0xc],AX
ram:00118e 8c04 mov A,[HL + 0x4]
ram:001190 5c07 and A,#0x7
ram:001192 70 mov ,A
ram:001193 8ffde8 mov A,!0xfe8fd
ram:001196 5cf8 and A,#0xf8
ram:001198 6168 or A,
ram:00119a 9ffde8 mov !0xfe8fd,A
ram:00119d 8ffce8 mov A,!0xfe8fc
ram:0011a0 4c12 cmp A,#0x12
ram:0011a2 df11 bnz $ 0x11b5
ram:0011a4 e5fce8 oneb !0xfe8fc
ram:0011a7 71330a clr1 0xffe2a.0x3
ram:0011aa 713a2a set1 0xfff2a.0x3
ram:0011ad 711b2a clr1 0xfff2a.0x1
ram:0011b0 71120a set1 0xffe2a.0x1
ram:0011b3 ef10 br $ 0x11c5
ram:0011b5 8ffce8 mov A,!0xfe8fc
ram:0011b8 81 inc 
ram:0011b9 9ffce8 mov !0xfe8fc,A
ram:0011bc ef07 br $ 0x11c5
ram:0011be 8ffce8 mov A,!0xfe8fc
ram:0011c1 81 inc 
ram:0011c2 9ffce8 mov !0xfe8fc,A
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
ram:0011ff 1004 addw SP,0x4
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
ram:001279 5104 mov ,0x4
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
ram:001316 717abe set1 0xfffbe.0x7
ram:001319 d7 ret
ram:00131a 717bbe clr1 0xfffbe.0x7
ram:00131d d7 ret
ram:00131e c7 push HL
ram:00131f c1 push AX
ram:001320 c1 push AX
ram:001321 fbf8ff movw HL,!0xffff8
ram:001324 fc161300 call !!0x1316
ram:001328 ac02 movw AX,[HL + 0x2]
ram:00132a fc890100 call !!0x189
ram:00132e 62 mov A,
ram:00132f 9c01 mov [HL + 0x1],A
ram:001331 8c01 mov A,[HL + 0x1]
ram:001333 4c1f cmp A,#0x1f
ram:001335 df0b bnz $ 0x1342
ram:001337 ac02 movw AX,[HL + 0x2]
ram:001339 fc8d0100 call !!0x18d
ram:00133d 62 mov A,
ram:00133e 9c01 mov [HL + 0x1],A
ram:001340 efef br $ 0x1331
ram:001342 8c01 mov A,[HL + 0x1]
ram:001344 d1 cmp0 A
ram:001345 df07 bnz $ 0x134e
ram:001347 fc140100 call !!0x114
ram:00134b 62 mov A,
ram:00134c 9c01 mov [HL + 0x1],A
ram:00134e 8c01 mov A,[HL + 0x1]
ram:001350 318e shrw AX,0x8
ram:001352 12 movw BC,AX
ram:001353 1004 addw SP,0x4
ram:001355 c6 pop HL
ram:001356 d7 ret
ram:001357 ec1a1300 br !!0x131a
ram:00135b c7 push HL
ram:00135c c3 push BC
ram:00135d c1 push AX
ram:00135e 20fe subw SP,0xfe
ram:001360 2004 subw SP,0x4
ram:001362 fbf8ff movw HL,!0xffff8
ram:001365 17 movw AX,HL
ram:001366 a1 incw AX
ram:001367 fc1e1300 call !!0x131e
ram:00136b 62 mov A,
ram:00136c 87 inc 
ram:00136d 9c01 mov [HL + 0x1],A
ram:00136f 97 dec 
ram:001370 87 inc 
ram:001371 8c01 mov A,[HL + 0x1]
ram:001373 97 dec 
ram:001374 d1 cmp0 A
ram:001375 dd09 bz $ 0x1380
ram:001377 87 inc 
ram:001378 8c01 mov A,[HL + 0x1]
ram:00137a 97 dec 
ram:00137b 318e shrw AX,0x8
ram:00137d 12 movw BC,AX
ram:00137e ef31 br $ 0x13b1
ram:001380 17 movw AX,HL
ram:001381 12 movw BC,AX
ram:001382 790201 movw AX,!0xf0102[BC]
ram:001385 bdd8 movw 0xffdf8,AX
ram:001387 790401 movw AX,!0xf0104[BC]
ram:00138a bdda movw 0xffdfa,AX
ram:00138c 510a mov ,0xa
ram:00138e fd8c06 call !0xf068c
ram:001391 8dd8 mov A,0xffdf8
ram:001393 318e shrw AX,0x8
ram:001395 fcde0000 call !!0xde
ram:001399 62 mov A,
ram:00139a 87 inc 
ram:00139b 9c01 mov [HL + 0x1],A
ram:00139d 97 dec 
ram:00139e 87 inc 
ram:00139f 8c01 mov A,[HL + 0x1]
ram:0013a1 97 dec 
ram:0013a2 4c1f cmp A,#0x1f
ram:0013a4 ddda bz $ 0x1380
ram:0013a6 fc1a1300 call !!0x131a
ram:0013aa 87 inc 
ram:0013ab 8c01 mov A,[HL + 0x1]
ram:0013ad 97 dec 
ram:0013ae 318e shrw AX,0x8
ram:0013b0 12 movw BC,AX
ram:0013b1 10fe addw SP,0xfe
ram:0013b3 1008 addw SP,0x8
ram:0013b5 c6 pop HL
ram:0013b6 d7 ret
ram:0014f5 c7 push HL
ram:0014f6 c1 push AX
ram:0014f7 20fe subw SP,0xfe
ram:0014f9 201e subw SP,0x1e
ram:0014fb fbf8ff movw HL,!0xffff8
ram:0014fe 17 movw AX,HL
ram:0014ff 12 movw BC,AX
ram:001500 791c01 movw AX,!0xf011c[BC]
ram:001503 14 movw DE,AX
ram:001504 aa06 movw AX,[DE + 0x6]
ram:001506 12 movw BC,AX
ram:001507 aa04 movw AX,[DE + 0x4]
ram:001509 6168 or A,
ram:00150b 616b or A,
ram:00150d 616a or A,
ram:00150f df08 bnz $ 0x1519
ram:001511 517f mov ,0x7f
ram:001513 87 inc 
ram:001514 9c1b mov [HL + 0x1b],A
ram:001516 97 dec 
ram:001517 ef13 br $ 0x152c
ram:001519 f0 clrb X
ram:00151a e1 oneb A
ram:00151b 87 inc 
ram:00151c bc14 movw [HL + 0x14],AX
ram:00151e 97 dec 
ram:00151f 17 movw AX,HL
ram:001520 041400 addw AX,0x14
ram:001523 fc1e1300 call !!0x131e
ram:001527 62 mov A,
ram:001528 87 inc 
ram:001529 9c1b mov [HL + 0x1b],A
ram:00152b 97 dec 
ram:00152c 17 movw AX,HL
ram:00152d 12 movw BC,AX
ram:00152e 791c01 movw AX,!0xf011c[BC]
ram:001531 14 movw DE,AX
ram:001532 aa06 movw AX,[DE + 0x6]
ram:001534 12 movw BC,AX
ram:001535 aa04 movw AX,[DE + 0x4]
ram:001537 240100 subw AX,0x1
ram:00153a 61d8 sknc
ram:00153c b3 _decw BC
ram:00153d bdd8 movw 0xffdf8,AX
ram:00153f 13 movw AX,BC
ram:001540 bdda movw 0xffdfa,AX
ram:001542 510a mov ,0xa
ram:001544 fd8c06 call !0xf068c
ram:001547 c9dc0100 movw 0xffdfc,0x1
ram:00154b f6 clrw AX
ram:00154c fd5006 call !0xf0650
ram:00154f adda movw AX,0xffdfa
ram:001551 87 inc 
ram:001552 bc18 movw [HL + 0x18],AX
ram:001554 97 dec 
ram:001555 add8 movw AX,0xffdf8
ram:001557 87 inc 
ram:001558 bc16 movw [HL + 0x16],AX
ram:00155a 97 dec 
ram:00155b 87 inc 
ram:00155c ac18 movw AX,[HL + 0x18]
ram:00155e 97 dec 
ram:00155f 12 movw BC,AX
ram:001560 87 inc 
ram:001561 ac16 movw AX,[HL + 0x16]
ram:001563 97 dec 
ram:001564 6168 or A,
ram:001566 616b or A,
ram:001568 616a or A,
ram:00156a 61f8 sknz
ram:00156c ee1a02 _br $! 0x1789
ram:00156f 87 inc 
ram:001570 8c1b mov A,[HL + 0x1b]
ram:001572 97 dec 
ram:001573 d1 cmp0 A
ram:001574 61e8 skz
ram:001576 ee1002 _br $! 0x1789
ram:001579 17 movw AX,HL
ram:00157a 12 movw BC,AX
ram:00157b 791c01 movw AX,!0xf011c[BC]
ram:00157e 14 movw DE,AX
ram:00157f 89 mov A,[DE]
ram:001580 318e shrw AX,0x8
ram:001582 fcda0000 call !!0xda
ram:001586 62 mov A,
ram:001587 87 inc 
ram:001588 9c1b mov [HL + 0x1b],A
ram:00158a 97 dec 
ram:00158b 87 inc 
ram:00158c 8c1b mov A,[HL + 0x1b]
ram:00158e 97 dec 
ram:00158f 4c1f cmp A,#0x1f
ram:001591 dde6 bz $ 0x1579
ram:001593 87 inc 
ram:001594 8c1b mov A,[HL + 0x1b]
ram:001596 97 dec 
ram:001597 4c1b cmp A,#0x1b
ram:001599 df1a bnz $ 0x15b5
ram:00159b 17 movw AX,HL
ram:00159c 12 movw BC,AX
ram:00159d 791c01 movw AX,!0xf011c[BC]
ram:0015a0 14 movw DE,AX
ram:0015a1 89 mov A,[DE]
ram:0015a2 318e shrw AX,0x8
ram:0015a4 fcde0000 call !!0xde
ram:0015a8 62 mov A,
ram:0015a9 87 inc 
ram:0015aa 9c1b mov [HL + 0x1b],A
ram:0015ac 97 dec 
ram:0015ad 87 inc 
ram:0015ae 8c1b mov A,[HL + 0x1b]
ram:0015b0 97 dec 
ram:0015b1 4c1f cmp A,#0x1f
ram:0015b3 dde6 bz $ 0x159b
ram:0015b5 87 inc 
ram:0015b6 8c1b mov A,[HL + 0x1b]
ram:0015b8 97 dec 
ram:0015b9 d1 cmp0 A
ram:0015ba 61e8 skz
ram:0015bc ee8501 _br $! 0x1744
ram:0015bf 17 movw AX,HL
ram:0015c0 12 movw BC,AX
ram:0015c1 791c01 movw AX,!0xf011c[BC]
ram:0015c4 14 movw DE,AX
ram:0015c5 89 mov A,[DE]
ram:0015c6 9dd8 mov 0xffdf8,A
ram:0015c8 f4d9 clrb 0xffdf9
ram:0015ca f6 clrw AX
ram:0015cb bdda movw 0xffdfa,AX
ram:0015cd 510a mov ,0xa
ram:0015cf fd7106 call !0xf0671
ram:0015d2 adda movw AX,0xffdfa
ram:0015d4 bc0a movw [HL + 0xa],AX
ram:0015d6 add8 movw AX,0xffdf8
ram:0015d8 bc08 movw [HL + 0x8],AX
ram:0015da 87 inc 
ram:0015db ac18 movw AX,[HL + 0x18]
ram:0015dd 97 dec 
ram:0015de f7 clrw BC
ram:0015df 43 cmpw AX,BC
ram:0015e0 df07 bnz $ 0x15e9
ram:0015e2 87 inc 
ram:0015e3 ac16 movw AX,[HL + 0x16]
ram:0015e5 97 dec 
ram:0015e6 440200 cmpw AX,0x2
ram:0015e9 dc0a bc $ 0x15f5
ram:0015eb 300004 movw AX,0x400
ram:0015ee bc0c movw [HL + 0xc],AX
ram:0015f0 f6 clrw AX
ram:0015f1 bc0e movw [HL + 0xe],AX
ram:0015f3 ef10 br $ 0x1605
ram:0015f5 17 movw AX,HL
ram:0015f6 12 movw BC,AX
ram:0015f7 791c01 movw AX,!0xf011c[BC]
ram:0015fa 14 movw DE,AX
ram:0015fb aa06 movw AX,[DE + 0x6]
ram:0015fd 12 movw BC,AX
ram:0015fe aa04 movw AX,[DE + 0x4]
ram:001600 bc0c movw [HL + 0xc],AX
ram:001602 33 xchw AX,BC
ram:001603 bc0e movw [HL + 0xe],AX
ram:001605 f6 clrw AX
ram:001606 61490e cmpw AX,[HL + 0xe]
ram:001609 61f8 sknz
ram:00160b 61490c _cmpw AX,[HL + 0xc]
ram:00160e 61f8 sknz
ram:001610 ee3101 _br $! 0x1744
ram:001613 87 inc 
ram:001614 8c1b mov A,[HL + 0x1b]
ram:001616 97 dec 
ram:001617 d1 cmp0 A
ram:001618 61e8 skz
ram:00161a ee2701 _br $! 0x1744
ram:00161d 87 inc 
ram:00161e ac14 movw AX,[HL + 0x14]
ram:001620 97 dec 
ram:001621 bddc movw 0xffdfc,AX
ram:001623 f6 clrw AX
ram:001624 bdde movw 0xffdfe,AX
ram:001626 ac0e movw AX,[HL + 0xe]
ram:001628 46de cmpw AX,0xffdfe
ram:00162a ac0c movw AX,[HL + 0xc]
ram:00162c 61f8 sknz
ram:00162e 46dc _cmpw AX,0xffdfc
ram:001630 dc0c bc $ 0x163e
ram:001632 87 inc 
ram:001633 ac14 movw AX,[HL + 0x14]
ram:001635 97 dec 
ram:001636 f7 clrw BC
ram:001637 bc04 movw [HL + 0x4],AX
ram:001639 33 xchw AX,BC
ram:00163a bc06 movw [HL + 0x6],AX
ram:00163c ef10 br $ 0x164e
ram:00163e 17 movw AX,HL
ram:00163f 12 movw BC,AX
ram:001640 791c01 movw AX,!0xf011c[BC]
ram:001643 14 movw DE,AX
ram:001644 aa06 movw AX,[DE + 0x6]
ram:001646 12 movw BC,AX
ram:001647 aa04 movw AX,[DE + 0x4]
ram:001649 bc04 movw [HL + 0x4],AX
ram:00164b 33 xchw AX,BC
ram:00164c bc06 movw [HL + 0x6],AX
ram:00164e f6 clrw AX
ram:00164f bb movw [HL],AX
ram:001650 bc02 movw [HL + 0x2],AX
ram:001652 ac02 movw AX,[HL + 0x2]
ram:001654 614906 cmpw AX,[HL + 0x6]
ram:001657 ab movw AX,[HL]
ram:001658 61f8 sknz
ram:00165a 614904 _cmpw AX,[HL + 0x4]
ram:00165d de24 bnc $ 0x1683
ram:00165f 17 movw AX,HL
ram:001660 12 movw BC,AX
ram:001661 791c01 movw AX,!0xf011c[BC]
ram:001664 14 movw DE,AX
ram:001665 ab movw AX,[HL]
ram:001666 12 movw BC,AX
ram:001667 aa02 movw AX,[DE + 0x2]
ram:001669 03 addw AX,BC
ram:00166a 14 movw DE,AX
ram:00166b 89 mov A,[DE]
ram:00166c 72 mov ,A
ram:00166d ab movw AX,[HL]
ram:00166e 07 addw AX,HL
ram:00166f 041400 addw AX,0x14
ram:001672 14 movw DE,AX
ram:001673 62 mov A,
ram:001674 99 mov [DE],A
ram:001675 617900 incw [HL + 0x0]
ram:001678 f6 clrw AX
ram:001679 614900 cmpw AX,[HL + 0x0]
ram:00167c dfd4 bnz $ 0x1652
ram:00167e 617902 incw [HL + 0x2]
ram:001681 efcf br $ 0x1652
ram:001683 ac0c movw AX,[HL + 0xc]
ram:001685 bdd8 movw 0xffdf8,AX
ram:001687 ac0e movw AX,[HL + 0xe]
ram:001689 bdda movw 0xffdfa,AX
ram:00168b ac04 movw AX,[HL + 0x4]
ram:00168d bddc movw 0xffdfc,AX
ram:00168f ac06 movw AX,[HL + 0x6]
ram:001691 fd5f06 call !0xf065f
ram:001694 adda movw AX,0xffdfa
ram:001696 bc0e movw [HL + 0xe],AX
ram:001698 add8 movw AX,0xffdf8
ram:00169a bc0c movw [HL + 0xc],AX
ram:00169c 17 movw AX,HL
ram:00169d 12 movw BC,AX
ram:00169e 791c01 movw AX,!0xf011c[BC]
ram:0016a1 14 movw DE,AX
ram:0016a2 aa04 movw AX,[DE + 0x4]
ram:0016a4 bdd8 movw 0xffdf8,AX
ram:0016a6 aa06 movw AX,[DE + 0x6]
ram:0016a8 bdda movw 0xffdfa,AX
ram:0016aa ac04 movw AX,[HL + 0x4]
ram:0016ac bddc movw 0xffdfc,AX
ram:0016ae ac06 movw AX,[HL + 0x6]
ram:0016b0 fd5f06 call !0xf065f
ram:0016b3 add8 movw AX,0xffdf8
ram:0016b5 ba04 movw [DE + 0x4],AX
ram:0016b7 adda movw AX,0xffdfa
ram:0016b9 ba06 movw [DE + 0x6],AX
ram:0016bb 17 movw AX,HL
ram:0016bc 12 movw BC,AX
ram:0016bd 791c01 movw AX,!0xf011c[BC]
ram:0016c0 14 movw DE,AX
ram:0016c1 aa02 movw AX,[DE + 0x2]
ram:0016c3 12 movw BC,AX
ram:0016c4 ac04 movw AX,[HL + 0x4]
ram:0016c6 03 addw AX,BC
ram:0016c7 ba02 movw [DE + 0x2],AX
ram:0016c9 ac04 movw AX,[HL + 0x4]
ram:0016cb bdd8 movw 0xffdf8,AX
ram:0016cd ac06 movw AX,[HL + 0x6]
ram:0016cf bdda movw 0xffdfa,AX
ram:0016d1 c9dc0400 movw 0xffdfc,0x4
ram:0016d5 f6 clrw AX
ram:0016d6 fde005 call !0xf05e0
ram:0016d9 f6 clrw AX
ram:0016da 46da cmpw AX,0xffdfa
ram:0016dc 61f8 sknz
ram:0016de 46d8 _cmpw AX,0xffdf8
ram:0016e0 dd18 bz $ 0x16fa
ram:0016e2 ac04 movw AX,[HL + 0x4]
ram:0016e4 07 addw AX,HL
ram:0016e5 041400 addw AX,0x14
ram:0016e8 14 movw DE,AX
ram:0016e9 ca00ff mov [DE + 0x0],0xff
ram:0016ec 617904 incw [HL + 0x4]
ram:0016ef f6 clrw AX
ram:0016f0 614904 cmpw AX,[HL + 0x4]
ram:0016f3 dfd4 bnz $ 0x16c9
ram:0016f5 617906 incw [HL + 0x6]
ram:0016f8 efcf br $ 0x16c9
ram:0016fa ac04 movw AX,[HL + 0x4]
ram:0016fc bdd8 movw 0xffdf8,AX
ram:0016fe ac06 movw AX,[HL + 0x6]
ram:001700 bdda movw 0xffdfa,AX
ram:001702 5102 mov ,0x2
ram:001704 fd8c06 call !0xf068c
ram:001707 8dd8 mov A,0xffdf8
ram:001709 318e shrw AX,0x8
ram:00170b c1 push AX
ram:00170c ac0a movw AX,[HL + 0xa]
ram:00170e 12 movw BC,AX
ram:00170f ac08 movw AX,[HL + 0x8]
ram:001711 fc510300 call !!0x351
ram:001715 c0 pop AX
ram:001716 62 mov A,
ram:001717 87 inc 
ram:001718 9c1b mov [HL + 0x1b],A
ram:00171a 97 dec 
ram:00171b 87 inc 
ram:00171c 8c1b mov A,[HL + 0x1b]
ram:00171e 97 dec 
ram:00171f 4c1f cmp A,#0x1f
ram:001721 ddd7 bz $ 0x16fa
ram:001723 87 inc 
ram:001724 ac14 movw AX,[HL + 0x14]
ram:001726 97 dec 
ram:001727 bddc movw 0xffdfc,AX
ram:001729 f6 clrw AX
ram:00172a bdde movw 0xffdfe,AX
ram:00172c ac08 movw AX,[HL + 0x8]
ram:00172e bdd8 movw 0xffdf8,AX
ram:001730 ac0a movw AX,[HL + 0xa]
ram:001732 bdda movw 0xffdfa,AX
ram:001734 adde movw AX,0xffdfe
ram:001736 fd5006 call !0xf0650
ram:001739 adda movw AX,0xffdfa
ram:00173b bc0a movw [HL + 0xa],AX
ram:00173d add8 movw AX,0xffdf8
ram:00173f bc08 movw [HL + 0x8],AX
ram:001741 eec1fe br $! 0x1605
ram:001744 87 inc 
ram:001745 8c1b mov A,[HL + 0x1b]
ram:001747 97 dec 
ram:001748 d1 cmp0 A
ram:001749 df1a bnz $ 0x1765
ram:00174b 17 movw AX,HL
ram:00174c 12 movw BC,AX
ram:00174d 791c01 movw AX,!0xf011c[BC]
ram:001750 14 movw DE,AX
ram:001751 89 mov A,[DE]
ram:001752 318e shrw AX,0x8
ram:001754 fce20000 call !!0xe2
ram:001758 62 mov A,
ram:001759 87 inc 
ram:00175a 9c1b mov [HL + 0x1b],A
ram:00175c 97 dec 
ram:00175d 87 inc 
ram:00175e 8c1b mov A,[HL + 0x1b]
ram:001760 97 dec 
ram:001761 4c1f cmp A,#0x1f
ram:001763 dde6 bz $ 0x174b
ram:001765 87 inc 
ram:001766 ac18 movw AX,[HL + 0x18]
ram:001768 97 dec 
ram:001769 12 movw BC,AX
ram:00176a 87 inc 
ram:00176b ac16 movw AX,[HL + 0x16]
ram:00176d 97 dec 
ram:00176e 240100 subw AX,0x1
ram:001771 61d8 sknc
ram:001773 b3 _decw BC
ram:001774 87 inc 
ram:001775 bc16 movw [HL + 0x16],AX
ram:001777 97 dec 
ram:001778 33 xchw AX,BC
ram:001779 87 inc 
ram:00177a bc18 movw [HL + 0x18],AX
ram:00177c 97 dec 
ram:00177d 17 movw AX,HL
ram:00177e 12 movw BC,AX
ram:00177f 791c01 movw AX,!0xf011c[BC]
ram:001782 14 movw DE,AX
ram:001783 89 mov A,[DE]
ram:001784 81 inc 
ram:001785 99 mov [DE],A
ram:001786 eed2fd br $! 0x155b
ram:001789 87 inc 
ram:00178a 8c1b mov A,[HL + 0x1b]
ram:00178c 97 dec 
ram:00178d 4c7f cmp A,#0x7f
ram:00178f 61f8 sknz
ram:001791 ee9900 _br $! 0x182d
ram:001794 87 inc 
ram:001795 8c1b mov A,[HL + 0x1b]
ram:001797 97 dec 
ram:001798 d1 cmp0 A
ram:001799 61e8 skz
ram:00179b ee8b00 _br $! 0x1829
ram:00179e 17 movw AX,HL
ram:00179f 12 movw BC,AX
ram:0017a0 791c01 movw AX,!0xf011c[BC]
ram:0017a3 14 movw DE,AX
ram:0017a4 8a08 mov A,[DE + 0x8]
ram:0017a6 91 dec 
ram:0017a7 dd11 bz $ 0x17ba
ram:0017a9 91 dec 
ram:0017aa dd14 bz $ 0x17c0
ram:0017ac 91 dec 
ram:0017ad dd1c bz $ 0x17cb
ram:0017af 91 dec 
ram:0017b0 dd2c bz $ 0x17de
ram:0017b2 91 dec 
ram:0017b3 dd3f bz $ 0x17f4
ram:0017b5 91 dec 
ram:0017b6 dd57 bz $ 0x180f
ram:0017b8 ef5e br $ 0x1818
ram:0017ba fc830200 call !!0x283
ram:0017be ef58 br $ 0x1818
ram:0017c0 fc840200 call !!0x284
ram:0017c4 62 mov A,
ram:0017c5 87 inc 
ram:0017c6 9c1b mov [HL + 0x1b],A
ram:0017c8 97 dec 
ram:0017c9 ef4d br $ 0x1818
ram:0017cb fca30300 call !!0x3a3
ram:0017cf 62 mov A,
ram:0017d0 87 inc 
ram:0017d1 9c1b mov [HL + 0x1b],A
ram:0017d3 97 dec 
ram:0017d4 87 inc 
ram:0017d5 8c1b mov A,[HL + 0x1b]
ram:0017d7 97 dec 
ram:0017d8 4c1f cmp A,#0x1f
ram:0017da ddef bz $ 0x17cb
ram:0017dc ef3a br $ 0x1818
ram:0017de fc840200 call !!0x284
ram:0017e2 62 mov A,
ram:0017e3 87 inc 
ram:0017e4 9c1b mov [HL + 0x1b],A
ram:0017e6 97 dec 
ram:0017e7 87 inc 
ram:0017e8 8c1b mov A,[HL + 0x1b]
ram:0017ea 97 dec 
ram:0017eb d1 cmp0 A
ram:0017ec df2a bnz $ 0x1818
ram:0017ee fc830200 call !!0x283
ram:0017f2 ef24 br $ 0x1818
ram:0017f4 fc840200 call !!0x284
ram:0017f8 62 mov A,
ram:0017f9 87 inc 
ram:0017fa 9c1b mov [HL + 0x1b],A
ram:0017fc 97 dec 
ram:0017fd 87 inc 
ram:0017fe 8c1b mov A,[HL + 0x1b]
ram:001800 97 dec 
ram:001801 d1 cmp0 A
ram:001802 df14 bnz $ 0x1818
ram:001804 fce10200 call !!0x2e1
ram:001808 62 mov A,
ram:001809 87 inc 
ram:00180a 9c1b mov [HL + 0x1b],A
ram:00180c 97 dec 
ram:00180d ef09 br $ 0x1818
ram:00180f fce10200 call !!0x2e1
ram:001813 62 mov A,
ram:001814 87 inc 
ram:001815 9c1b mov [HL + 0x1b],A
ram:001817 97 dec 
ram:001818 87 inc 
ram:001819 8c1b mov A,[HL + 0x1b]
ram:00181b 97 dec 
ram:00181c d1 cmp0 A
ram:00181d dd0a bz $ 0x1829
ram:00181f 87 inc 
ram:001820 8c1b mov A,[HL + 0x1b]
ram:001822 97 dec 
ram:001823 6c80 or A,#0x80
ram:001825 87 inc 
ram:001826 9c1b mov [HL + 0x1b],A
ram:001828 97 dec 
ram:001829 fc571300 call !!0x1357
ram:00182d 87 inc 
ram:00182e 8c1b mov A,[HL + 0x1b]
ram:001830 97 dec 
ram:001831 318e shrw AX,0x8
ram:001833 12 movw BC,AX
ram:001834 10fe addw SP,0xfe
ram:001836 1020 addw SP,0x20
ram:001838 c6 pop HL
ram:001839 d7 ret
ram:00183a ce44ab mov 0xfff44,0xab
ram:00183d af6201 movw AX,!0xf0162
ram:001840 f1 clrb A
ram:001841 08 xch A,X
ram:001842 5c20 and A,#0x20
ram:001844 08 xch A,X
ram:001845 e7 onew BC
ram:001846 43 cmpw AX,BC
ram:001847 ddf4 bz $ 0x183d
ram:001849 ce4420 mov 0xfff44,0x20
ram:00184c d7 ret
ram:00184d ce44ab mov 0xfff44,0xab
ram:001850 af6201 movw AX,!0xf0162
ram:001853 f1 clrb A
ram:001854 08 xch A,X
ram:001855 5c20 and A,#0x20
ram:001857 08 xch A,X
ram:001858 e7 onew BC
ram:001859 43 cmpw AX,BC
ram:00185a ddf4 bz $ 0x1850
ram:00185c ce4421 mov 0xfff44,0x21
ram:00185f d7 ret
ram:001860 ce44ab mov 0xfff44,0xab
ram:001863 af6201 movw AX,!0xf0162
ram:001866 f1 clrb A
ram:001867 08 xch A,X
ram:001868 5c20 and A,#0x20
ram:00186a 08 xch A,X
ram:00186b e7 onew BC
ram:00186c 43 cmpw AX,BC
ram:00186d ddf4 bz $ 0x1863
ram:00186f ce4422 mov 0xfff44,0x22
ram:001872 d7 ret
ram:001873 af3402 movw AX,!0xf0234
ram:001876 08 xch A,X
ram:001877 6c01 or A,#0x1
ram:001879 08 xch A,X
ram:00187a bf3402 movw !0xf0234,AX
ram:00187d 715ad6 set1 0xfffd6.0x5
ram:001880 715bd2 clr1 0xfffd2.0x5
ram:001883 717ad5 set1 0xfffd5.0x7
ram:001886 716ad5 set1 0xfffd5.0x6
ram:001889 717bfa DI
ram:00188c ec3a1800 br !!0x183a
ram:001890 c7 push HL
ram:001891 c1 push AX
ram:001892 c1 push AX
ram:001893 fbf8ff movw HL,!0xffff8
ram:001896 300300 movw AX,0x3
ram:001899 bb movw [HL],AX
ram:00189a f6 clrw AX
ram:00189b 614900 cmpw AX,[HL + 0x0]
ram:00189e dd55 bz $ 0x18f5
ram:0018a0 af6201 movw AX,!0xf0162
ram:0018a3 f1 clrb A
ram:0018a4 08 xch A,X
ram:0018a5 5c20 and A,#0x20
ram:0018a7 08 xch A,X
ram:0018a8 6168 or A,
ram:0018aa df05 bnz $ 0x18b1
ram:0018ac ceabac mov 0xfffab,0xac
ram:0018af efef br $ 0x18a0
ram:0018b1 ac02 movw AX,[HL + 0x2]
ram:0018b3 14 movw DE,AX
ram:0018b4 8e46 mov A,0xfff46
ram:0018b6 99 mov [DE],A
ram:0018b7 ab movw AX,[HL]
ram:0018b8 e7 onew BC
ram:0018b9 23 subw AX,BC
ram:0018ba dd26 bz $ 0x18e2
ram:0018bc 23 subw AX,BC
ram:0018bd dd10 bz $ 0x18cf
ram:0018bf 23 subw AX,BC
ram:0018c0 dfd8 bnz $ 0x189a
ram:0018c2 ac02 movw AX,[HL + 0x2]
ram:0018c4 14 movw DE,AX
ram:0018c5 89 mov A,[DE]
ram:0018c6 4c55 cmp A,#0x55
ram:0018c8 dfd0 bnz $ 0x189a
ram:0018ca 618900 decw [HL + 0x0]
ram:0018cd efcb br $ 0x189a
ram:0018cf ac02 movw AX,[HL + 0x2]
ram:0018d1 14 movw DE,AX
ram:0018d2 89 mov A,[DE]
ram:0018d3 4c4c cmp A,#0x4c
ram:0018d5 df05 bnz $ 0x18dc
ram:0018d7 618900 decw [HL + 0x0]
ram:0018da efbe br $ 0x189a
ram:0018dc 300300 movw AX,0x3
ram:0018df bb movw [HL],AX
ram:0018e0 efb8 br $ 0x189a
ram:0018e2 ac02 movw AX,[HL + 0x2]
ram:0018e4 14 movw DE,AX
ram:0018e5 89 mov A,[DE]
ram:0018e6 4c43 cmp A,#0x43
ram:0018e8 df05 bnz $ 0x18ef
ram:0018ea 618900 decw [HL + 0x0]
ram:0018ed efab br $ 0x189a
ram:0018ef 300300 movw AX,0x3
ram:0018f2 bb movw [HL],AX
ram:0018f3 efa5 br $ 0x189a
ram:0018f5 f6 clrw AX
ram:0018f6 bb movw [HL],AX
ram:0018f7 ab movw AX,[HL]
ram:0018f8 61490a cmpw AX,[HL + 0xa]
ram:0018fb de1e bnc $ 0x191b
ram:0018fd af6201 movw AX,!0xf0162
ram:001900 f1 clrb A
ram:001901 08 xch A,X
ram:001902 5c20 and A,#0x20
ram:001904 08 xch A,X
ram:001905 6168 or A,
ram:001907 df05 bnz $ 0x190e
ram:001909 ceabac mov 0xfffab,0xac
ram:00190c efef br $ 0x18fd
ram:00190e ab movw AX,[HL]
ram:00190f 610902 addw AX,[HL + 0x2]
ram:001912 14 movw DE,AX
ram:001913 8e46 mov A,0xfff46
ram:001915 99 mov [DE],A
ram:001916 617900 incw [HL + 0x0]
ram:001919 efdc br $ 0x18f7
ram:00191b 1004 addw SP,0x4
ram:00191d c6 pop HL
ram:00191e d7 ret
ram:00191f c7 push HL
ram:001920 c1 push AX
ram:001921 200c subw SP,0xc
ram:001923 fbf8ff movw HL,!0xffff8
ram:001926 8c0c mov A,[HL + 0xc]
ram:001928 9b mov [HL],A
ram:001929 ac14 movw AX,[HL + 0x14]
ram:00192b bc02 movw [HL + 0x2],AX
ram:00192d ac18 movw AX,[HL + 0x18]
ram:00192f bc06 movw [HL + 0x6],AX
ram:001931 ac16 movw AX,[HL + 0x16]
ram:001933 bc04 movw [HL + 0x4],AX
ram:001935 8c1a mov A,[HL + 0x1a]
ram:001937 9c08 mov [HL + 0x8],A
ram:001939 17 movw AX,HL
ram:00193a fcf51400 call !!0x14f5
ram:00193e 62 mov A,
ram:00193f 9c0a mov [HL + 0xa],A
ram:001941 d1 cmp0 A
ram:001942 df05 bnz $ 0x1949
ram:001944 cc0b01 mov [HL + 0xb],0x1
ram:001947 ef34 br $ 0x197d
ram:001949 8c0a mov A,[HL + 0xa]
ram:00194b 5c80 and A,#0x80
ram:00194d 4c80 cmp A,#0x80
ram:00194f dd17 bz $ 0x1968
ram:001951 8c0a mov A,[HL + 0xa]
ram:001953 91 dec 
ram:001954 dd24 bz $ 0x197a
ram:001956 2c04 sub A,#0x4
ram:001958 dd20 bz $ 0x197a
ram:00195a 2c0b sub A,#0xb
ram:00195c dd1c bz $ 0x197a
ram:00195e 2c0a sub A,#0xa
ram:001960 2c03 sub A,#0x3
ram:001962 dc16 bc $ 0x197a
ram:001964 2c62 sub A,#0x62
ram:001966 ef12 br $ 0x197a
ram:001968 8c0a mov A,[HL + 0xa]
ram:00196a 5c7f and A,#0x7f
ram:00196c 9c0a mov [HL + 0xa],A
ram:00196e 2c05 sub A,#0x5
ram:001970 dd08 bz $ 0x197a
ram:001972 2c0b sub A,#0xb
ram:001974 dd04 bz $ 0x197a
ram:001976 2c0a sub A,#0xa
ram:001978 2c03 sub A,#0x3
ram:00197a cc0b00 mov [HL + 0xb],0x0
ram:00197d 8c1a mov A,[HL + 0x1a]
ram:00197f 4c04 cmp A,#0x4
ram:001981 dd05 bz $ 0x1988
ram:001983 8c1a mov A,[HL + 0x1a]
ram:001985 91 dec 
ram:001986 61f8 sknz
ram:001988 effe _br $ 0x1988
ram:00198a 8c0b mov A,[HL + 0xb]
ram:00198c 318e shrw AX,0x8
ram:00198e 12 movw BC,AX
ram:00198f 100e addw SP,0xe
ram:001991 c6 pop HL
ram:001992 d7 ret
ram:001993 c7 push HL
ram:001994 aef8 movw AX,SP
ram:001996 240804 subw AX,0x408
ram:001999 bef8 movw SP,AX
ram:00199b 16 movw HL,AX
ram:00199c 4103 mov ES,0x3
ram:00199e 118f00f4 mov A,ES:!0xff400
ram:0019a2 c7 push HL
ram:0019a3 c2 pop BC
ram:0019a4 480704 mov !0xf0407[BC],A
ram:0019a7 17 movw AX,HL
ram:0019a8 12 movw BC,AX
ram:0019a9 490704 mov A,!0xf0407[BC]
ram:0019ac 81 inc 
ram:0019ad dd0a bz $ 0x19b9
ram:0019af 3000f4 movw AX,0xf400
ram:0019b2 320300 movw BC,0x3
ram:0019b5 fc5b1300 call !!0x135b
ram:0019b9 fc731800 call !!0x1873
ram:0019bd cc0300 mov [HL + 0x3],0x0
ram:0019c0 300304 movw AX,0x403
ram:0019c3 c1 push AX
ram:0019c4 17 movw AX,HL
ram:0019c5 040400 addw AX,0x4
ram:0019c8 fc901800 call !!0x1890
ram:0019cc c0 pop AX
ram:0019cd f6 clrw AX
ram:0019ce bb movw [HL],AX
ram:0019cf ab movw AX,[HL]
ram:0019d0 440204 cmpw AX,0x402
ram:0019d3 de10 bnc $ 0x19e5
ram:0019d5 ab movw AX,[HL]
ram:0019d6 07 addw AX,HL
ram:0019d7 040400 addw AX,0x4
ram:0019da 14 movw DE,AX
ram:0019db 89 mov A,[DE]
ram:0019dc 0e03 add A,[HL + 0x3]
ram:0019de 9c03 mov [HL + 0x3],A
ram:0019e0 617900 incw [HL + 0x0]
ram:0019e3 efea br $ 0x19cf
ram:0019e5 17 movw AX,HL
ram:0019e6 12 movw BC,AX
ram:0019e7 490604 mov A,!0xf0406[BC]
ram:0019ea 70 mov ,A
ram:0019eb 8c03 mov A,[HL + 0x3]
ram:0019ed 6148 cmp A,
ram:0019ef dd06 bz $ 0x19f7
ram:0019f1 fc4d1800 call !!0x184d
ram:0019f5 efc6 br $ 0x19bd
ram:0019f7 ceabac mov 0xfffab,0xac
ram:0019fa 8c04 mov A,[HL + 0x4]
ram:0019fc 5c0f and A,#0xf
ram:0019fe 318e shrw AX,0x8
ram:001a00 c1 push AX
ram:001a01 f6 clrw AX
ram:001a02 c1 push AX
ram:001a03 5104 mov ,0x4
ram:001a05 c1 push AX
ram:001a06 17 movw AX,HL
ram:001a07 040600 addw AX,0x6
ram:001a0a c1 push AX
ram:001a0b 8c05 mov A,[HL + 0x5]
ram:001a0d 318e shrw AX,0x8
ram:001a0f fc1f1900 call !!0x191f
ram:001a13 1008 addw SP,0x8
ram:001a15 92 dec 
ram:001a16 df06 bnz $ 0x1a1e
ram:001a18 fc3a1800 call !!0x183a
ram:001a1c ef9f br $ 0x19bd
ram:001a1e fc601800 call !!0x1860
ram:001a22 ef99 br $ 0x19bd
ram:006168 07 addw AX,HL
ram:006169 fa06 movw HL,0xffe26
ram:00616b 72 mov ,A
ram:00616c 00 nop
ram:00616d 01 addw AX,AX
ram:00616e 07 addw AX,HL
ram:00616f f804 mov C,0xffe24
ram:006171 2c00 sub A,#0x0
ram:006173 01 addw AX,AX
ram:006174 07 addw AX,HL
ram:006175 f50695 clrb !0xf9506
ram:006178 00 nop
ram:006179 01 addw AX,AX
ram:00617a 07 addw AX,HL
ram:00617b f2 clrb C
ram:00617c 05 addw AX,DE
ram:00617d b00001 dec !0xf0100
ram:006180 07 addw AX,HL
ram:006181 ef01 br $ 0x6184
ram:006184 00 nop
ram:006185 01 addw AX,AX
ram:006186 07 addw AX,HL
ram:006187 eb01fd movw DE,!0xffd01
ram:00618a 00 nop
ram:00618b 01 addw AX,AX
ram:00618c 07 addw AX,HL
ram:00618d e6 onew AX
ram:00618e 07 addw AX,HL
ram:00618f 320001 movw BC,0x100
ram:006192 07 addw AX,HL
ram:006193 e2 oneb C
ram:006194 01 addw AX,AX
ram:006195 1f0001 addc A,!0xf0100
ram:006198 07 addw AX,HL
ram:006199 dc07 bc $ 0x61a2
ram:00619b c4 pop DE
ram:00619c 00 nop
ram:00619d 01 addw AX,AX
ram:00619e 07 addw AX,HL
ram:00619f d7 ret
ram:0061a2 00 nop
ram:0061a3 01 addw AX,AX
ram:0061a4 07 addw AX,HL
ram:0061a5 d1 cmp0 A
ram:0061a6 03 addw AX,BC
ram:0061a7 43 cmpw AX,BC
ram:0061a8 00 nop
ram:0061a9 01 addw AX,AX
ram:0061aa 07 addw AX,HL
ram:0061ab cb002100 movw 0xfff00,0x21
ram:0061af 01 addw AX,AX
ram:0061b0 07 addw AX,HL
ram:0061b1 c4 pop DE
ram:0061b2 01 addw AX,AX
ram:0061b3 c2 pop BC
ram:0061b4 00 nop
ram:0061b5 01 addw AX,AX
ram:0061b6 07 addw AX,HL
ram:0061b7 bd00 movw 0xffe20,AX
ram:0061b9 280001 mov !0xf0100[C],A
ram:0061bc 07 addw AX,HL
ram:0061bd b5 decw DE
ram:0061be 03 addw AX,BC
ram:0061bf 5700 mov ,0x0
ram:0061c1 01 addw AX,AX
ram:0061c2 07 addw AX,HL
ram:00711e 020400 addw AX,!0xf0004
ram:007121 00 nop
ram:007122 00 nop
ram:007123 01 addw AX,AX
ram:007124 07 addw AX,HL
ram:007125 03 addw AX,BC
ram:007126 13 movw AX,BC
ram:007127 aa05 movw AX,[DE + 0x5]
ram:007129 fc07ff01 call !!0x1ff07
ram:00758e afd2e3 movw AX,!0xfe3d2
ram:007591 22e0e3 subw AX,!0xfe3e0
ram:007594 44e903 cmpw AX,0x3e9
ram:007597 dc0d bc $ 0x75a6
ram:007599 f6 clrw AX
ram:00759a bfdae3 movw !0xfe3da,AX
ram:00759d bfdce3 movw !0xfe3dc,AX
ram:0075a0 afd2e3 movw AX,!0xfe3d2
ram:0075a3 bfe0e3 movw !0xfe3e0,AX
ram:0075a6 f6 clrw AX
ram:0075a7 42dce3 cmpw AX,!0xfe3dc
ram:0075aa df06 bnz $ 0x75b2
ram:0075ac 300707 movw AX,0x707
ram:0075af 42dae3 cmpw AX,!0xfe3da
ram:0075b2 dc02 bc $ 0x75b6
ram:0075b4 f7 clrw BC
ram:0075b5 d7 ret
ram:0075b6 c9d8c0e1 movw 0xffdf8,0xe1c0
ram:0075ba c9dae400 movw 0xffdfa,0xe4
ram:0075be afdae3 movw AX,!0xfe3da
ram:0075c1 bddc movw 0xffdfc,AX
ram:0075c3 afdce3 movw AX,!0xfe3dc
ram:0075c6 fda105 call !0xf05a1
ram:0075c9 dad8 movw BC,0xffdf8
ram:0075cb d7 ret
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
ram:007a88 c7 push HL
ram:007a89 16 movw HL,AX
ram:007a8a 66 mov A,
ram:007a8b 91 dec 
ram:007a8c df03 bnz $ 0x7a91
ram:007a8e e1 oneb A
ram:007a8f ef01 br $ 0x7a92
ram:007a91 f1 clrb A
ram:007a92 77 mov ,A
ram:007a93 61fb rorc A,1
ram:007a95 711105 mov1 0xffe25.0x1,CY
ram:007a98 67 mov A,
ram:007a99 61fb rorc A,1
ram:007a9b 714106 mov1 0xffe26.0x4,CY
ram:007a9e 67 mov A,
ram:007a9f 61fb rorc A,1
ram:007aa1 715106 mov1 0xffe26.0x5,CY
ram:007aa4 67 mov A,
ram:007aa5 61fb rorc A,1
ram:007aa7 717101 mov1 0xffe21.0x7,CY
ram:007aaa 67 mov A,
ram:007aab 61fb rorc A,1
ram:007aad 71410a mov1 0xffe2a.0x4,CY
ram:007ab0 c6 pop HL
ram:007ab1 d7 ret
ram:007ab2 f5e2e3 clrb !0xfe3e2
ram:007ab5 710be3 clr1 0xfffe3.0x0
ram:007ab8 710be7 clr1 0xfffe7.0x0
ram:007abb 717a30 set1 0xfff30.0x7
ram:007abe d7 ret
ram:007abf c7 push HL
ram:007ac0 c1 push AX
ram:007ac1 201a subw SP,0x1a
ram:007ac3 fbf8ff movw HL,!0xffff8
ram:007ac6 40e2e301 cmp !0xfe3e2,0x1
ram:007aca 61e8 skz
ram:007acc ee5a01 _br $! 0x7c29
ram:007acf 308002 movw AX,0x280
ram:007ad2 bc18 movw [HL + 0x18],AX
ram:007ad4 cc160d mov [HL + 0x16],0xd
ram:007ad7 cc1700 mov [HL + 0x17],0x0
ram:007ada 8c17 mov A,[HL + 0x17]
ram:007adc 4c0e cmp A,#0xe
ram:007ade 61c8 skc
ram:007ae0 ee1501 _br $! 0x7bf8
ram:007ae3 8c17 mov A,[HL + 0x17]
ram:007ae5 f0 clrb X
ram:007ae6 317e shrw AX,0x7
ram:007ae8 610918 addw AX,[HL + 0x18]
ram:007aeb 14 movw DE,AX
ram:007aec a9 movw AX,[DE]
ram:007aed 316e shrw AX,0x6
ram:007aef 12 movw BC,AX
ram:007af0 8c17 mov A,[HL + 0x17]
ram:007af2 500a mov ,0xa
ram:007af4 d6 mulu X
ram:007af5 04babf addw AX,0xbfba
ram:007af8 14 movw DE,AX
ram:007af9 afd6e3 movw AX,!0xfe3d6
ram:007afc 01 addw AX,AX
ram:007afd 05 addw AX,DE
ram:007afe 14 movw DE,AX
ram:007aff 13 movw AX,BC
ram:007b00 b9 movw [DE],AX
ram:007b01 f6 clrw AX
ram:007b02 bc14 movw [HL + 0x14],AX
ram:007b04 ac14 movw AX,[HL + 0x14]
ram:007b06 440500 cmpw AX,0x5
ram:007b09 de1c bnc $ 0x7b27
ram:007b0b 8c17 mov A,[HL + 0x17]
ram:007b0d 500a mov ,0xa
ram:007b0f d6 mulu X
ram:007b10 04babf addw AX,0xbfba
ram:007b13 14 movw DE,AX
ram:007b14 ac14 movw AX,[HL + 0x14]
ram:007b16 01 addw AX,AX
ram:007b17 05 addw AX,DE
ram:007b18 14 movw DE,AX
ram:007b19 a9 movw AX,[DE]
ram:007b1a 12 movw BC,AX
ram:007b1b ac14 movw AX,[HL + 0x14]
ram:007b1d 01 addw AX,AX
ram:007b1e 07 addw AX,HL
ram:007b1f 14 movw DE,AX
ram:007b20 13 movw AX,BC
ram:007b21 b9 movw [DE],AX
ram:007b22 617914 incw [HL + 0x14]
ram:007b25 efdd br $ 0x7b04
ram:007b27 40d8e301 cmp !0xfe3d8,0x1
ram:007b2b 61e8 skz
ram:007b2d eea400 _br $! 0x7bd4
ram:007b30 f6 clrw AX
ram:007b31 bc14 movw [HL + 0x14],AX
ram:007b33 ac14 movw AX,[HL + 0x14]
ram:007b35 440500 cmpw AX,0x5
ram:007b38 de44 bnc $ 0x7b7e
ram:007b3a ac14 movw AX,[HL + 0x14]
ram:007b3c a1 incw AX
ram:007b3d bc12 movw [HL + 0x12],AX
ram:007b3f ac12 movw AX,[HL + 0x12]
ram:007b41 440500 cmpw AX,0x5
ram:007b44 de33 bnc $ 0x7b79
ram:007b46 ac14 movw AX,[HL + 0x14]
ram:007b48 01 addw AX,AX
ram:007b49 07 addw AX,HL
ram:007b4a 14 movw DE,AX
ram:007b4b a9 movw AX,[DE]
ram:007b4c 12 movw BC,AX
ram:007b4d ac12 movw AX,[HL + 0x12]
ram:007b4f 01 addw AX,AX
ram:007b50 07 addw AX,HL
ram:007b51 14 movw DE,AX
ram:007b52 a9 movw AX,[DE]
ram:007b53 43 cmpw AX,BC
ram:007b54 de1e bnc $ 0x7b74
ram:007b56 ac14 movw AX,[HL + 0x14]
ram:007b58 01 addw AX,AX
ram:007b59 07 addw AX,HL
ram:007b5a 14 movw DE,AX
ram:007b5b a9 movw AX,[DE]
ram:007b5c bc0e movw [HL + 0xe],AX
ram:007b5e ac12 movw AX,[HL + 0x12]
ram:007b60 01 addw AX,AX
ram:007b61 07 addw AX,HL
ram:007b62 14 movw DE,AX
ram:007b63 a9 movw AX,[DE]
ram:007b64 12 movw BC,AX
ram:007b65 ac14 movw AX,[HL + 0x14]
ram:007b67 01 addw AX,AX
ram:007b68 07 addw AX,HL
ram:007b69 14 movw DE,AX
ram:007b6a 13 movw AX,BC
ram:007b6b b9 movw [DE],AX
ram:007b6c ac12 movw AX,[HL + 0x12]
ram:007b6e 01 addw AX,AX
ram:007b6f 07 addw AX,HL
ram:007b70 14 movw DE,AX
ram:007b71 ac0e movw AX,[HL + 0xe]
ram:007b73 b9 movw [DE],AX
ram:007b74 617912 incw [HL + 0x12]
ram:007b77 efc6 br $ 0x7b3f
ram:007b79 617914 incw [HL + 0x14]
ram:007b7c efb5 br $ 0x7b33
ram:007b7e f6 clrw AX
ram:007b7f bc0a movw [HL + 0xa],AX
ram:007b81 bc0c movw [HL + 0xc],AX
ram:007b83 e6 onew AX
ram:007b84 bc14 movw [HL + 0x14],AX
ram:007b86 ac14 movw AX,[HL + 0x14]
ram:007b88 440400 cmpw AX,0x4
ram:007b8b de21 bnc $ 0x7bae
ram:007b8d ac14 movw AX,[HL + 0x14]
ram:007b8f 01 addw AX,AX
ram:007b90 07 addw AX,HL
ram:007b91 14 movw DE,AX
ram:007b92 a9 movw AX,[DE]
ram:007b93 bdd8 movw 0xffdf8,AX
ram:007b95 f6 clrw AX
ram:007b96 bdda movw 0xffdfa,AX
ram:007b98 ac0a movw AX,[HL + 0xa]
ram:007b9a bddc movw 0xffdfc,AX
ram:007b9c ac0c movw AX,[HL + 0xc]
ram:007b9e fd5006 call !0xf0650
ram:007ba1 adda movw AX,0xffdfa
ram:007ba3 bc0c movw [HL + 0xc],AX
ram:007ba5 add8 movw AX,0xffdf8
ram:007ba7 bc0a movw [HL + 0xa],AX
ram:007ba9 617914 incw [HL + 0x14]
ram:007bac efd8 br $ 0x7b86
ram:007bae ac0a movw AX,[HL + 0xa]
ram:007bb0 bdd8 movw 0xffdf8,AX
ram:007bb2 ac0c movw AX,[HL + 0xc]
ram:007bb4 bdda movw 0xffdfa,AX
ram:007bb6 c9dc0300 movw 0xffdfc,0x3
ram:007bba f6 clrw AX
ram:007bbb fda105 call !0xf05a1
ram:007bbe adda movw AX,0xffdfa
ram:007bc0 bc0c movw [HL + 0xc],AX
ram:007bc2 add8 movw AX,0xffdf8
ram:007bc4 bc0a movw [HL + 0xa],AX
ram:007bc6 8c17 mov A,[HL + 0x17]
ram:007bc8 f0 clrb X
ram:007bc9 317e shrw AX,0x7
ram:007bcb 61091a addw AX,[HL + 0x1a]
ram:007bce 14 movw DE,AX
ram:007bcf ac0a movw AX,[HL + 0xa]
ram:007bd1 b9 movw [DE],AX
ram:007bd2 ef1e br $ 0x7bf2
ram:007bd4 8c17 mov A,[HL + 0x17]
ram:007bd6 500a mov ,0xa
ram:007bd8 d6 mulu X
ram:007bd9 04babf addw AX,0xbfba
ram:007bdc 14 movw DE,AX
ram:007bdd afd6e3 movw AX,!0xfe3d6
ram:007be0 01 addw AX,AX
ram:007be1 05 addw AX,DE
ram:007be2 14 movw DE,AX
ram:007be3 a9 movw AX,[DE]
ram:007be4 bc0e movw [HL + 0xe],AX
ram:007be6 8c17 mov A,[HL + 0x17]
ram:007be8 f0 clrb X
ram:007be9 317e shrw AX,0x7
ram:007beb 61091a addw AX,[HL + 0x1a]
ram:007bee 14 movw DE,AX
ram:007bef ac0e movw AX,[HL + 0xe]
ram:007bf1 b9 movw [DE],AX
ram:007bf2 615917 inc [HL + 0x17]
ram:007bf5 eee2fe br $! 0x7ada
ram:007bf8 a2d6e3 incw !0xfe3d6
ram:007bfb afd6e3 movw AX,!0xfe3d6
ram:007bfe 440500 cmpw AX,0x5
ram:007c01 dc0e bc $ 0x7c11
ram:007c03 d5d8e3 cmp0 !0xfe3d8
ram:007c06 df09 bnz $ 0x7c11
ram:007c08 e5d8e3 oneb !0xfe3d8
ram:007c0b f6 clrw AX
ram:007c0c bfd6e3 movw !0xfe3d6,AX
ram:007c0f ef12 br $ 0x7c23
ram:007c11 afd6e3 movw AX,!0xfe3d6
ram:007c14 440500 cmpw AX,0x5
ram:007c17 dc0a bc $ 0x7c23
ram:007c19 40d8e301 cmp !0xfe3d8,0x1
ram:007c1d df04 bnz $ 0x7c23
ram:007c1f f6 clrw AX
ram:007c20 bfd6e3 movw !0xfe3d6,AX
ram:007c23 f5e2e3 clrb !0xfe3e2
ram:007c26 e7 onew BC
ram:007c27 ef01 br $ 0x7c2a
ram:007c29 f7 clrw BC
ram:007c2a 101c addw SP,0x1c
ram:007c2c c6 pop HL
ram:007c2d d7 ret
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
ram:007c3e d9d4e3 mov X,!0xfe3d4
ram:007c41 f1 clrb A
ram:007c42 12 movw BC,AX
ram:007c43 d7 ret
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
ram:007cd9 c7 push HL
ram:007cda c1 push AX
ram:007cdb 2004 subw SP,0x4
ram:007cdd fbf8ff movw HL,!0xffff8
ram:007ce0 a0e0e5 inc !0xfe5e0
ram:007ce3 d5e0e5 cmp0 !0xfe5e0
ram:007ce6 61f8 sknz
ram:007ce8 e5e0e5 _oneb !0xfe5e0
ram:007ceb cc0300 mov [HL + 0x3],0x0
ram:007cee 8c03 mov A,[HL + 0x3]
ram:007cf0 4c20 cmp A,#0x20
ram:007cf2 de13 bnc $ 0x7d07
ram:007cf4 8c03 mov A,[HL + 0x3]
ram:007cf6 500e mov ,0xe
ram:007cf8 d6 mulu X
ram:007cf9 12 movw BC,AX
ram:007cfa 4920e4 mov A,!0xfe420[BC]
ram:007cfd 4fe0e5 cmp A,!0xfe5e0
ram:007d00 dd05 bz $ 0x7d07
ram:007d02 615903 inc [HL + 0x3]
ram:007d05 efe7 br $ 0x7cee
ram:007d07 8c03 mov A,[HL + 0x3]
ram:007d09 4c20 cmp A,#0x20
ram:007d0b dcd3 bc $ 0x7ce0
ram:007d0d cc0200 mov [HL + 0x2],0x0
ram:007d10 8c02 mov A,[HL + 0x2]
ram:007d12 4c20 cmp A,#0x20
ram:007d14 de11 bnc $ 0x7d27
ram:007d16 8c02 mov A,[HL + 0x2]
ram:007d18 500e mov ,0xe
ram:007d1a d6 mulu X
ram:007d1b 12 movw BC,AX
ram:007d1c 4920e4 mov A,!0xfe420[BC]
ram:007d1f d1 cmp0 A
ram:007d20 dd05 bz $ 0x7d27
ram:007d22 615902 inc [HL + 0x2]
ram:007d25 efe9 br $ 0x7d10
ram:007d27 8c02 mov A,[HL + 0x2]
ram:007d29 4c20 cmp A,#0x20
ram:007d2b df15 bnz $ 0x7d42
ram:007d2d af00e4 movw AX,!0xfe400
ram:007d30 f7 clrw BC
ram:007d31 c3 push BC
ram:007d32 14 movw DE,AX
ram:007d33 8a0e mov A,[DE + 0xe]
ram:007d35 9efc mov CS,A
ram:007d37 aa0c movw AX,[DE + 0xc]
ram:007d39 14 movw DE,AX
ram:007d3a e6 onew AX
ram:007d3b 61ea call DE
ram:007d3d c0 pop AX
ram:007d3e f7 clrw BC
ram:007d3f eea400 br $! 0x7de6
ram:007d42 8c02 mov A,[HL + 0x2]
ram:007d44 500e mov ,0xe
ram:007d46 d6 mulu X
ram:007d47 12 movw BC,AX
ram:007d48 8fe0e5 mov A,!0xfe5e0
ram:007d4b 4820e4 mov !0xfe420[BC],A
ram:007d4e 8c02 mov A,[HL + 0x2]
ram:007d50 500e mov ,0xe
ram:007d52 d6 mulu X
ram:007d53 0420e4 addw AX,0xe420
ram:007d56 14 movw DE,AX
ram:007d57 ca0300 mov [DE + 0x3],0x0
ram:007d5a 8c02 mov A,[HL + 0x2]
ram:007d5c 500e mov ,0xe
ram:007d5e d6 mulu X
ram:007d5f 0420e4 addw AX,0xe420
ram:007d62 14 movw DE,AX
ram:007d63 f6 clrw AX
ram:007d64 ba04 movw [DE + 0x4],AX
ram:007d66 8c02 mov A,[HL + 0x2]
ram:007d68 500e mov ,0xe
ram:007d6a d6 mulu X
ram:007d6b 0420e4 addw AX,0xe420
ram:007d6e 14 movw DE,AX
ram:007d6f 8c0e mov A,[HL + 0xe]
ram:007d71 9dd4 mov 0xffdf4,A
ram:007d73 ac0c movw AX,[HL + 0xc]
ram:007d75 ba0a movw [DE + 0xa],AX
ram:007d77 8dd4 mov A,0xffdf4
ram:007d79 9a0c mov [DE + 0xc],A
ram:007d7b 8c02 mov A,[HL + 0x2]
ram:007d7d 500e mov ,0xe
ram:007d7f d6 mulu X
ram:007d80 0420e4 addw AX,0xe420
ram:007d83 14 movw DE,AX
ram:007d84 8c04 mov A,[HL + 0x4]
ram:007d86 9a01 mov [DE + 0x1],A
ram:007d88 8c02 mov A,[HL + 0x2]
ram:007d8a 500e mov ,0xe
ram:007d8c d6 mulu X
ram:007d8d 0420e4 addw AX,0xe420
ram:007d90 14 movw DE,AX
ram:007d91 afe2e5 movw AX,!0xfe5e2
ram:007d94 ba08 movw [DE + 0x8],AX
ram:007d96 8c02 mov A,[HL + 0x2]
ram:007d98 500e mov ,0xe
ram:007d9a d6 mulu X
ram:007d9b 0420e4 addw AX,0xe420
ram:007d9e 14 movw DE,AX
ram:007d9f ac10 movw AX,[HL + 0x10]
ram:007da1 ba06 movw [DE + 0x6],AX
ram:007da3 8c02 mov A,[HL + 0x2]
ram:007da5 500e mov ,0xe
ram:007da7 d6 mulu X
ram:007da8 0420e4 addw AX,0xe420
ram:007dab 14 movw DE,AX
ram:007dac ca0200 mov [DE + 0x2],0x0
ram:007daf 8c02 mov A,[HL + 0x2]
ram:007db1 500e mov ,0xe
ram:007db3 d6 mulu X
ram:007db4 0420e4 addw AX,0xe420
ram:007db7 14 movw DE,AX
ram:007db8 8a01 mov A,[DE + 0x1]
ram:007dba d1 cmp0 A
ram:007dbb dd1d bz $ 0x7dda
ram:007dbd 8a01 mov A,[DE + 0x1]
ram:007dbf 318e shrw AX,0x8
ram:007dc1 fcb57c00 call !!0x7cb5
ram:007dc5 13 movw AX,BC
ram:007dc6 bb movw [HL],AX
ram:007dc7 14 movw DE,AX
ram:007dc8 ca0301 mov [DE + 0x3],0x1
ram:007dcb 8c02 mov A,[HL + 0x2]
ram:007dcd 500e mov ,0xe
ram:007dcf d6 mulu X
ram:007dd0 12 movw BC,AX
ram:007dd1 4920e4 mov A,!0xfe420[BC]
ram:007dd4 72 mov ,A
ram:007dd5 ab movw AX,[HL]
ram:007dd6 14 movw DE,AX
ram:007dd7 62 mov A,
ram:007dd8 9a02 mov [DE + 0x2],A
ram:007dda 8c02 mov A,[HL + 0x2]
ram:007ddc 500e mov ,0xe
ram:007dde d6 mulu X
ram:007ddf 12 movw BC,AX
ram:007de0 4920e4 mov A,!0xfe420[BC]
ram:007de3 318e shrw AX,0x8
ram:007de5 12 movw BC,AX
ram:007de6 1006 addw SP,0x6
ram:007de8 c6 pop HL
ram:007de9 d7 ret
ram:007dea c7 push HL
ram:007deb c3 push BC
ram:007dec c1 push AX
ram:007ded fbf8ff movw HL,!0xffff8
ram:007df0 ac0a movw AX,[HL + 0xa]
ram:007df2 c1 push AX
ram:007df3 8c02 mov A,[HL + 0x2]
ram:007df5 70 mov ,A
ram:007df6 c1 push AX
ram:007df7 ab movw AX,[HL]
ram:007df8 c1 push AX
ram:007df9 f6 clrw AX
ram:007dfa fcd97c00 call !!0x7cd9
ram:007dfe 1006 addw SP,0x6
ram:007e00 f3 clrb B
ram:007e01 1004 addw SP,0x4
ram:007e03 c6 pop HL
ram:007e04 d7 ret
ram:007e05 c7 push HL
ram:007e06 c3 push BC
ram:007e07 c1 push AX
ram:007e08 fbf8ff movw HL,!0xffff8
ram:007e0b f6 clrw AX
ram:007e0c c1 push AX
ram:007e0d 8c02 mov A,[HL + 0x2]
ram:007e0f 70 mov ,A
ram:007e10 c1 push AX
ram:007e11 ab movw AX,[HL]
ram:007e12 c1 push AX
ram:007e13 f6 clrw AX
ram:007e14 fcd97c00 call !!0x7cd9
ram:007e18 1006 addw SP,0x6
ram:007e1a f3 clrb B
ram:007e1b 1004 addw SP,0x4
ram:007e1d c6 pop HL
ram:007e1e d7 ret
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
ram:007e92 c7 push HL
ram:007e93 c1 push AX
ram:007e94 c1 push AX
ram:007e95 fbf8ff movw HL,!0xffff8
ram:007e98 8c02 mov A,[HL + 0x2]
ram:007e9a 318e shrw AX,0x8
ram:007e9c fcb57c00 call !!0x7cb5
ram:007ea0 13 movw AX,BC
ram:007ea1 bb movw [HL],AX
ram:007ea2 f6 clrw AX
ram:007ea3 614900 cmpw AX,[HL + 0x0]
ram:007ea6 dd0a bz $ 0x7eb2
ram:007ea8 afe2e5 movw AX,!0xfe5e2
ram:007eab c1 push AX
ram:007eac ab movw AX,[HL]
ram:007ead fc1f7e00 call !!0x7e1f
ram:007eb1 c0 pop AX
ram:007eb2 1004 addw SP,0x4
ram:007eb4 c6 pop HL
ram:007eb5 d7 ret
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
ram:007f38 c7 push HL
ram:007f39 16 movw HL,AX
ram:007f3a 300500 movw AX,0x5
ram:007f3d bc06 movw [HL + 0x6],AX
ram:007f3f a0ebe5 inc !0xfe5eb
ram:007f42 fc94dd00 call !!0xdd94
ram:007f46 fcffdd00 call !!0xddff
ram:007f4a 8febe5 mov A,!0xfe5eb
ram:007f4d 91 dec 
ram:007f4e dd0b bz $ 0x7f5b
ram:007f50 91 dec 
ram:007f51 dd0a bz $ 0x7f5d
ram:007f53 91 dec 
ram:007f54 dd19 bz $ 0x7f6f
ram:007f56 91 dec 
ram:007f57 dd18 bz $ 0x7f71
ram:007f59 ef5b br $ 0x7fb6
ram:007f5b ef59 br $ 0x7fb6
ram:007f5d fc57b400 call !!0xb457
ram:007f61 fc127202 call !!0x27212
ram:007f65 fc027202 call !!0x27202
ram:007f69 fc127602 call !!0x27612
ram:007f6d ef47 br $ 0x7fb6
ram:007f6f ef45 br $ 0x7fb6
ram:007f71 fc57b400 call !!0xb457
ram:007f75 fc127202 call !!0x27212
ram:007f79 fc027202 call !!0x27202
ram:007f7d fc127602 call !!0x27612
ram:007f81 40e6e597 cmp !0xfe5e6,0x97
ram:007f85 dc0a bc $ 0x7f91
ram:007f87 f6 clrw AX
ram:007f88 fc7cb900 call !!0xb97c
ram:007f8c f5e6e5 clrb !0xfe5e6
ram:007f8f ef03 br $ 0x7f94
ram:007f91 a0e6e5 inc !0xfe5e6
ram:007f94 d5e9e5 cmp0 !0xfe5e9
ram:007f97 dd1a bz $ 0x7fb3
ram:007f99 d5e8e5 cmp0 !0xfe5e8
ram:007f9c dd15 bz $ 0x7fb3
ram:007f9e 40e7e5fb cmp !0xfe5e7,0xfb
ram:007fa2 dc0c bc $ 0x7fb0
ram:007fa4 fc347602 call !!0x27634
ram:007fa8 f5e7e5 clrb !0xfe5e7
ram:007fab f5e8e5 clrb !0xfe5e8
ram:007fae ef03 br $ 0x7fb3
ram:007fb0 a0e7e5 inc !0xfe5e7
ram:007fb3 f5ebe5 clrb !0xfe5eb
ram:007fb6 d5e4e5 cmp0 !0xfe5e4
ram:007fb9 df03 bnz $ 0x7fbe
ram:007fbb f7 clrw BC
ram:007fbc ef01 br $ 0x7fbf
ram:007fbe e7 onew BC
ram:007fbf c6 pop HL
ram:007fc0 d7 ret
ram:007fc1 c7 push HL
ram:007fc2 e5e4e5 oneb !0xfe5e4
ram:007fc5 eb1ae4 movw DE,!0xfe41a
ram:007fc8 8a02 mov A,[DE + 0x2]
ram:007fca 9efc mov CS,A
ram:007fcc a9 movw AX,[DE]
ram:007fcd 16 movw HL,AX
ram:007fce e6 onew AX
ram:007fcf 61fa call HL
ram:007fd1 f5e8e5 clrb !0xfe5e8
ram:007fd4 f5ebe5 clrb !0xfe5eb
ram:007fd7 e5eae5 oneb !0xfe5ea
ram:007fda eb18e4 movw DE,!0xfe418
ram:007fdd 8a02 mov A,[DE + 0x2]
ram:007fdf 9efc mov CS,A
ram:007fe1 a9 movw AX,[DE]
ram:007fe2 16 movw HL,AX
ram:007fe3 e6 onew AX
ram:007fe4 61fa call HL
ram:007fe6 300a00 movw AX,0xa
ram:007fe9 c1 push AX
ram:007fea 30387f movw AX,0x7f38
ram:007fed 5200 mov ,0x0
ram:007fef f3 clrb B
ram:007ff0 fcea7d00 call !!0x7dea
ram:007ff4 c0 pop AX
ram:007ff5 62 mov A,
ram:007ff6 9fe5e5 mov !0xfe5e5,A
ram:007ff9 717bfa DI
ram:007ffc 717b26 clr1 0xfff26.0x7
ram:007fff 717206 set1 0xffe26.0x7
ram:008002 71530f clr1 0xffe2f.0x5
ram:008005 714b2f clr1 0xfff2f.0x4
ram:008008 71420f set1 0xffe2f.0x4
ram:00800b 7140f200 set1 !0xf00f2.0x4
ram:00800f 8e3c mov A,0xfff3c
ram:008011 5c7f and A,#0x7f
ram:008013 9e3c mov 0xfff3c,A
ram:008015 712b27 clr1 0xfff27.0x2
ram:008018 712207 set1 0xffe27.0x2
ram:00801b 713a27 set1 0xfff27.0x3
ram:00801e fc638600 call !!0x8663
ram:008022 fc907002 call !!0x27090
ram:008026 fc21d500 call !!0xd521
ram:00802a f6 clrw AX
ram:00802b fc9fb300 call !!0xb39f
ram:00802f 710bd9 clr1 0xfffd9.0x0
ram:008032 710bdd clr1 0xfffdd.0x0
ram:008035 710bd5 clr1 0xfffd5.0x0
ram:008038 717bd4 clr1 0xfffd4.0x7
ram:00803b 715bd4 clr1 0xfffd4.0x5
ram:00803e 716bd4 clr1 0xfffd4.0x6
ram:008041 fc577102 call !!0x27157
ram:008045 fc347102 call !!0x27134
ram:008049 717afa EI
ram:00804c f7 clrw BC
ram:00804d c6 pop HL
ram:00804e d7 ret
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
ram:0080a1 d5e5e5 cmp0 !0xfe5e5
ram:0080a4 df0b bnz $ 0x80b1
ram:0080a6 d9e5e5 mov X,!0xfe5e5
ram:0080a9 f1 clrb A
ram:0080aa fc927e00 call !!0x7e92
ram:0080ae f5e5e5 clrb !0xfe5e5
ram:0080b1 71520f set1 0xffe2f.0x5
ram:0080b4 f5e4e5 clrb !0xfe5e4
ram:0080b7 d7 ret
ram:0080b8 f6 clrw AX
ram:0080b9 12 movw BC,AX
ram:0080ba ecca8200 br !!0x82ca
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
ram:008538 8dd8 mov A,0xffdf8
ram:00853a 6c81 or A,#0x81
ram:00853c 72 mov ,A
ram:00853d ac04 movw AX,[HL + 0x4]
ram:00853f 14 movw DE,AX
ram:008540 62 mov A,
ram:008541 9a09 mov [DE + 0x9],A
ram:008543 ac18 movw AX,[HL + 0x18]
ram:008545 313d shlw AX,0x3
ram:008547 042865 addw AX,0x6528
ram:00854a 14 movw DE,AX
ram:00854b ac0c movw AX,[HL + 0xc]
ram:00854d 01 addw AX,AX
ram:00854e 05 addw AX,DE
ram:00854f 14 movw DE,AX
ram:008550 4100 mov ES,0x0
ram:008552 11a9 movw AX,ES:[DE]
ram:008554 12 movw BC,AX
ram:008555 ac04 movw AX,[HL + 0x4]
ram:008557 14 movw DE,AX
ram:008558 13 movw AX,BC
ram:008559 ba0a movw [DE + 0xa],AX
ram:00855b ac18 movw AX,[HL + 0x18]
ram:00855d 313d shlw AX,0x3
ram:00855f 042065 addw AX,0x6520
ram:008562 14 movw DE,AX
ram:008563 ac0c movw AX,[HL + 0xc]
ram:008565 01 addw AX,AX
ram:008566 05 addw AX,DE
ram:008567 14 movw DE,AX
ram:008568 4100 mov ES,0x0
ram:00856a 11a9 movw AX,ES:[DE]
ram:00856c 12 movw BC,AX
ram:00856d ac04 movw AX,[HL + 0x4]
ram:00856f 14 movw DE,AX
ram:008570 13 movw AX,BC
ram:008571 ba0c movw [DE + 0xc],AX
ram:008573 ac04 movw AX,[HL + 0x4]
ram:008575 14 movw DE,AX
ram:008576 300008 movw AX,0x800
ram:008579 ba0e movw [DE + 0xe],AX
ram:00857b ac04 movw AX,[HL + 0x4]
ram:00857d 14 movw DE,AX
ram:00857e f0 clrb X
ram:00857f e1 oneb A
ram:008580 ba0e movw [DE + 0xe],AX
ram:008582 f6 clrw AX
ram:008583 614908 cmpw AX,[HL + 0x8]
ram:008586 618908 decw [HL + 0x8]
ram:008589 61f8 sknz
ram:00858b 61890a _decw [HL + 0xa]
ram:00858e f6 clrw AX
ram:00858f 61490a cmpw AX,[HL + 0xa]
ram:008592 61f8 sknz
ram:008594 614908 _cmpw AX,[HL + 0x8]
ram:008597 df0c bnz $ 0x85a5
ram:008599 61790c incw [HL + 0xc]
ram:00859c f6 clrw AX
ram:00859d 61490c cmpw AX,[HL + 0xc]
ram:0085a0 61f8 sknz
ram:0085a2 61790e _incw [HL + 0xe]
ram:0085a5 617916 incw [HL + 0x16]
ram:0085a8 ee37ff br $! 0x84e2
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
ram:008663 c7 push HL
ram:008664 2004 subw SP,0x4
ram:008666 fbf8ff movw HL,!0xffff8
ram:008669 fc8ede00 call !!0xde8e
ram:00866d f6 clrw AX
ram:00866e bb movw [HL],AX
ram:00866f ab movw AX,[HL]
ram:008670 440600 cmpw AX,0x6
ram:008673 de13 bnc $ 0x8688
ram:008675 ab movw AX,[HL]
ram:008676 12 movw BC,AX
ram:008677 4100 mov ES,0x0
ram:008679 1149dc64 mov A,ES:!0xf64dc[BC]
ram:00867d 73 mov ,A
ram:00867e ab movw AX,[HL]
ram:00867f 33 xchw AX,BC
ram:008680 4849c0 mov !0xfc049[BC],A
ram:008683 617900 incw [HL + 0x0]
ram:008686 efe7 br $ 0x866f
ram:008688 f6 clrw AX
ram:008689 bc02 movw [HL + 0x2],AX
ram:00868b f6 clrw AX
ram:00868c 614902 cmpw AX,[HL + 0x2]
ram:00868f df0c bnz $ 0x869d
ram:008691 ac02 movw AX,[HL + 0x2]
ram:008693 12 movw BC,AX
ram:008694 3948c000 mov !0xfc048[BC],0x0
ram:008698 617902 incw [HL + 0x2]
ram:00869b efee br $ 0x868b
ram:00869d f554c0 clrb !0xfc054
ram:0086a0 f6 clrw AX
ram:0086a1 bf6ac0 movw !0xfc06a,AX
ram:0086a4 bf6cc0 movw !0xfc06c,AX
ram:0086a7 bf56c0 movw !0xfc056,AX
ram:0086aa f568c0 clrb !0xfc068
ram:0086ad f555c0 clrb !0xfc055
ram:0086b0 b1 decw AX
ram:0086b1 bf46c0 movw !0xfc046,AX
ram:0086b4 fcca8600 call !!0x86ca
ram:0086b8 f6 clrw AX
ram:0086b9 12 movw BC,AX
ram:0086ba fcca8200 call !!0x82ca
ram:0086be 8f54c0 mov A,!0xfc054
ram:0086c1 6c05 or A,#0x5
ram:0086c3 9f54c0 mov !0xfc054,A
ram:0086c6 1004 addw SP,0x4
ram:0086c8 c6 pop HL
ram:0086c9 d7 ret
ram:0086ca c7 push HL
ram:0086cb 2008 subw SP,0x8
ram:0086cd fbf8ff movw HL,!0xffff8
ram:0086d0 8f54c0 mov A,!0xfc054
ram:0086d3 5c04 and A,#0x4
ram:0086d5 4c04 cmp A,#0x4
ram:0086d7 df61 bnz $ 0x873a
ram:0086d9 fcd79100 call !!0x91d7
ram:0086dd f6 clrw AX
ram:0086de bc06 movw [HL + 0x6],AX
ram:0086e0 ac06 movw AX,[HL + 0x6]
ram:0086e2 01 addw AX,AX
ram:0086e3 61c34e bh $ 0x8733
ram:0086e6 ac06 movw AX,[HL + 0x6]
ram:0086e8 01 addw AX,AX
ram:0086e9 0474c0 addw AX,0xc074
ram:0086ec 14 movw DE,AX
ram:0086ed a9 movw AX,[DE]
ram:0086ee bb movw [HL],AX
ram:0086ef f6 clrw AX
ram:0086f0 614900 cmpw AX,[HL + 0x0]
ram:0086f3 dd3a bz $ 0x872f
ram:0086f5 500f mov ,0xf
ram:0086f7 bc04 movw [HL + 0x4],AX
ram:0086f9 8c05 mov A,[HL + 0x5]
ram:0086fb 01 addw AX,AX
ram:0086fc dc28 bc $ 0x8726
ram:0086fe ac04 movw AX,[HL + 0x4]
ram:008700 01 addw AX,AX
ram:008701 046c64 addw AX,0x646c
ram:008704 14 movw DE,AX
ram:008705 4100 mov ES,0x0
ram:008707 1189 mov A,ES:[DE]
ram:008709 5d and A,[HL]
ram:00870a 08 xch A,X
ram:00870b 118a01 mov A,ES:[DE + 0x1]
ram:00870e 5e01 and A,[HL + 0x1]
ram:008710 6168 or A,
ram:008712 dd0d bz $ 0x8721
ram:008714 ac06 movw AX,[HL + 0x6]
ram:008716 314d shlw AX,0x4
ram:008718 610904 addw AX,[HL + 0x4]
ram:00871b bc02 movw [HL + 0x2],AX
ram:00871d fc507302 call !!0x27350
ram:008721 618904 decw [HL + 0x4]
ram:008724 efd3 br $ 0x86f9
ram:008726 ac06 movw AX,[HL + 0x6]
ram:008728 01 addw AX,AX
ram:008729 0474c0 addw AX,0xc074
ram:00872c 14 movw DE,AX
ram:00872d f6 clrw AX
ram:00872e b9 movw [DE],AX
ram:00872f 617906 incw [HL + 0x6]
ram:008732 efac br $ 0x86e0
ram:008734 fc199200 call !!0x9219
ram:008738 ef17 br $ 0x8751
ram:00873a f6 clrw AX
ram:00873b bc06 movw [HL + 0x6],AX
ram:00873d ac06 movw AX,[HL + 0x6]
ram:00873f 01 addw AX,AX
ram:008740 61c30e bh $ 0x8750
ram:008743 ac06 movw AX,[HL + 0x6]
ram:008745 01 addw AX,AX
ram:008746 0474c0 addw AX,0xc074
ram:008749 14 movw DE,AX
ram:00874a f6 clrw AX
ram:00874b b9 movw [DE],AX
ram:00874c 617906 incw [HL + 0x6]
ram:00874f efec br $ 0x873d
ram:008751 1008 addw SP,0x8
ram:008753 c6 pop HL
ram:008754 d7 ret
ram:008755 c7 push HL
ram:008756 c1 push AX
ram:008757 200c subw SP,0xc
ram:008759 fbf8ff movw HL,!0xffff8
ram:00875c ac0c movw AX,[HL + 0xc]
ram:00875e 440200 cmpw AX,0x2
ram:008761 61c8 skc
ram:008763 ecf78700 _br !!0x87f7
ram:008767 fc80e000 call !!0xe080
ram:00876b 62 mov A,
ram:00876c 9c0b mov [HL + 0xb],A
ram:00876e 717bfa DI
ram:008771 ac0c movw AX,[HL + 0xc]
ram:008773 bb movw [HL],AX
ram:008774 314e shrw AX,0x4
ram:008776 bc04 movw [HL + 0x4],AX
ram:008778 510f mov ,0xf
ram:00877a 5d and A,[HL]
ram:00877b 318e shrw AX,0x8
ram:00877d bc02 movw [HL + 0x2],AX
ram:00877f ac04 movw AX,[HL + 0x4]
ram:008781 01 addw AX,AX
ram:008782 0474c0 addw AX,0xc074
ram:008785 14 movw DE,AX
ram:008786 a9 movw AX,[DE]
ram:008787 12 movw BC,AX
ram:008788 ac02 movw AX,[HL + 0x2]
ram:00878a 01 addw AX,AX
ram:00878b 046c64 addw AX,0x646c
ram:00878e 14 movw DE,AX
ram:00878f 4100 mov ES,0x0
ram:008791 1189 mov A,ES:[DE]
ram:008793 615a and A,
ram:008795 08 xch A,X
ram:008796 118a01 mov A,ES:[DE + 0x1]
ram:008799 615b and A,
ram:00879b 6168 or A,
ram:00879d dd23 bz $ 0x87c2
ram:00879f ac02 movw AX,[HL + 0x2]
ram:0087a1 01 addw AX,AX
ram:0087a2 046c64 addw AX,0x646c
ram:0087a5 14 movw DE,AX
ram:0087a6 11a9 movw AX,ES:[DE]
ram:0087a8 12 movw BC,AX
ram:0087a9 f6 clrw AX
ram:0087aa b1 decw AX
ram:0087ab 23 subw AX,BC
ram:0087ac 12 movw BC,AX
ram:0087ad ac04 movw AX,[HL + 0x4]
ram:0087af 01 addw AX,AX
ram:0087b0 0474c0 addw AX,0xc074
ram:0087b3 14 movw DE,AX
ram:0087b4 a9 movw AX,[DE]
ram:0087b5 615b and A,
ram:0087b7 08 xch A,X
ram:0087b8 615a and A,
ram:0087ba 08 xch A,X
ram:0087bb b9 movw [DE],AX
ram:0087bc ac0c movw AX,[HL + 0xc]
ram:0087be fc507302 call !!0x27350
ram:0087c2 f6 clrw AX
ram:0087c3 bc08 movw [HL + 0x8],AX
ram:0087c5 01 addw AX,AX
ram:0087c6 0452c0 addw AX,0xc052
ram:0087c9 14 movw DE,AX
ram:0087ca a9 movw AX,[DE]
ram:0087cb 61490c cmpw AX,[HL + 0xc]
ram:0087ce df1f bnz $ 0x87ef
ram:0087d0 30feff movw AX,0xfffe
ram:0087d3 b9 movw [DE],AX
ram:0087d4 f6 clrw AX
ram:0087d5 bc06 movw [HL + 0x6],AX
ram:0087d7 314d shlw AX,0x4
ram:0087d9 320006 movw BC,0x600
ram:0087dc 03 addw AX,BC
ram:0087dd 14 movw DE,AX
ram:0087de e6 onew AX
ram:0087df a1 incw AX
ram:0087e0 ba0e movw [DE + 0xe],AX
ram:0087e2 fcb88000 call !!0x80b8
ram:0087e6 e586c0 oneb !0xfc086
ram:0087e9 ac0c movw AX,[HL + 0xc]
ram:0087eb fc507302 call !!0x27350
ram:0087ef 8c0b mov A,[HL + 0xb]
ram:0087f1 318e shrw AX,0x8
ram:0087f3 fc85e000 call !!0xe085
ram:0087f7 100e addw SP,0xe
ram:0087f9 c6 pop HL
ram:0087fa d7 ret
ram:0087fb c7 push HL
ram:0087fc c1 push AX
ram:0087fd 200e subw SP,0xe
ram:0087ff fbf8ff movw HL,!0xffff8
ram:008802 8f54c0 mov A,!0xfc054
ram:008805 5c01 and A,#0x1
ram:008807 91 dec 
ram:008808 dd05 bz $ 0x880f
ram:00880a f7 clrw BC
ram:00880b ecef8800 br !!0x88ef
ram:00880f ac0e movw AX,[HL + 0xe]
ram:008811 12 movw BC,AX
ram:008812 4100 mov ES,0x0
ram:008814 1149be64 mov A,ES:!0xf64be[BC]
ram:008818 5f55c0 and A,!0xfc055
ram:00881b d1 cmp0 A
ram:00881c dd06 bz $ 0x8824
ram:00881e e7 onew BC
ram:00881f a3 incw BC
ram:008820 ecef8800 br !!0x88ef
ram:008824 8fe305 mov A,!0xf05e3
ram:008827 5c10 and A,#0x10
ram:008829 4c01 cmp A,#0x1
ram:00882b e6 onew AX
ram:00882c 6130 subc ,A
ram:00882e e7 onew BC
ram:00882f 43 cmpw AX,BC
ram:008830 df05 bnz $ 0x8837
ram:008832 f7 clrw BC
ram:008833 ecef8800 br !!0x88ef
ram:008837 f6 clrw AX
ram:008838 bc0a movw [HL + 0xa],AX
ram:00883a bc08 movw [HL + 0x8],AX
ram:00883c fc80e000 call !!0xe080
ram:008840 62 mov A,
ram:008841 9c0d mov [HL + 0xd],A
ram:008843 717bfa DI
ram:008846 8f54c0 mov A,!0xfc054
ram:008849 5c01 and A,#0x1
ram:00884b 91 dec 
ram:00884c dd0c bz $ 0x885a
ram:00884e 8c0d mov A,[HL + 0xd]
ram:008850 318e shrw AX,0x8
ram:008852 fc85e000 call !!0xe085
ram:008856 f7 clrw BC
ram:008857 ee9500 br $! 0x88ef
ram:00885a ac08 movw AX,[HL + 0x8]
ram:00885c 01 addw AX,AX
ram:00885d 12 movw BC,AX
ram:00885e 7952c0 movw AX,!0xfc052[BC]
ram:008861 44ffff cmpw AX,0xffff
ram:008864 dd34 bz $ 0x889a
ram:008866 ac0e movw AX,[HL + 0xe]
ram:008868 bb movw [HL],AX
ram:008869 314e shrw AX,0x4
ram:00886b bc04 movw [HL + 0x4],AX
ram:00886d 510f mov ,0xf
ram:00886f 5d and A,[HL]
ram:008870 318e shrw AX,0x8
ram:008872 bc02 movw [HL + 0x2],AX
ram:008874 01 addw AX,AX
ram:008875 046c64 addw AX,0x646c
ram:008878 14 movw DE,AX
ram:008879 4100 mov ES,0x0
ram:00887b 11a9 movw AX,ES:[DE]
ram:00887d 12 movw BC,AX
ram:00887e ac04 movw AX,[HL + 0x4]
ram:008880 01 addw AX,AX
ram:008881 0474c0 addw AX,0xc074
ram:008884 14 movw DE,AX
ram:008885 a9 movw AX,[DE]
ram:008886 616b or A,
ram:008888 08 xch A,X
ram:008889 616a or A,
ram:00888b 08 xch A,X
ram:00888c b9 movw [DE],AX
ram:00888d 8c0d mov A,[HL + 0xd]
ram:00888f 318e shrw AX,0x8
ram:008891 fc85e000 call !!0xe085
ram:008895 e7 onew BC
ram:008896 ef57 br $ 0x88ef
ram:00889a ac08 movw AX,[HL + 0x8]
ram:00889c 01 addw AX,AX
ram:00889d 12 movw BC,AX
ram:00889e 7952c0 movw AX,!0xfc052[BC]
ram:0088a1 44ffff cmpw AX,0xffff
ram:0088a4 df14 bnz $ 0x88ba
ram:0088a6 ac0a movw AX,[HL + 0xa]
ram:0088a8 314d shlw AX,0x4
ram:0088aa 320006 movw BC,0x600
ram:0088ad 03 addw AX,BC
ram:0088ae 14 movw DE,AX
ram:0088af aa0e movw AX,[DE + 0xe]
ram:0088b1 f1 clrb A
ram:0088b2 08 xch A,X
ram:0088b3 5c03 and A,#0x3
ram:0088b5 08 xch A,X
ram:0088b6 6168 or A,
ram:0088b8 dd0b bz $ 0x88c5
ram:0088ba 8c0d mov A,[HL + 0xd]
ram:0088bc 318e shrw AX,0x8
ram:0088be fc85e000 call !!0xe085
ram:0088c2 f7 clrw BC
ram:0088c3 ef2a br $ 0x88ef
ram:0088c5 ac08 movw AX,[HL + 0x8]
ram:0088c7 01 addw AX,AX
ram:0088c8 12 movw BC,AX
ram:0088c9 ac0e movw AX,[HL + 0xe]
ram:0088cb 7852c0 movw !0xfc052[BC],AX
ram:0088ce 8c0d mov A,[HL + 0xd]
ram:0088d0 318e shrw AX,0x8
ram:0088d2 fc85e000 call !!0xe085
ram:0088d6 ac0e movw AX,[HL + 0xe]
ram:0088d8 c1 push AX
ram:0088d9 ac0a movw AX,[HL + 0xa]
ram:0088db fcf38800 call !!0x88f3
ram:0088df c0 pop AX
ram:0088e0 62 mov A,
ram:0088e1 9c07 mov [HL + 0x7],A
ram:0088e3 4c05 cmp A,#0x5
ram:0088e5 61f8 sknz
ram:0088e7 cc0700 _mov [HL + 0x7],0x0
ram:0088ea 8c07 mov A,[HL + 0x7]
ram:0088ec 318e shrw AX,0x8
ram:0088ee 12 movw BC,AX
ram:0088ef 1010 addw SP,0x10
ram:0088f1 c6 pop HL
ram:0088f2 d7 ret
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
ram:00895a 62 mov A,
ram:00895b 9c0b mov [HL + 0xb],A
ram:00895d 717bfa DI
ram:008960 f6 clrw AX
ram:008961 bc02 movw [HL + 0x2],AX
ram:008963 bc04 movw [HL + 0x4],AX
ram:008965 f6 clrw AX
ram:008966 614904 cmpw AX,[HL + 0x4]
ram:008969 df05 bnz $ 0x8970
ram:00896b 5007 mov ,0x7
ram:00896d 614902 cmpw AX,[HL + 0x2]
ram:008970 dc1e bc $ 0x8990
ram:008972 ac02 movw AX,[HL + 0x2]
ram:008974 610906 addw AX,[HL + 0x6]
ram:008977 14 movw DE,AX
ram:008978 89 mov A,[DE]
ram:008979 72 mov ,A
ram:00897a ab movw AX,[HL]
ram:00897b 14 movw DE,AX
ram:00897c ac02 movw AX,[HL + 0x2]
ram:00897e 05 addw AX,DE
ram:00897f 14 movw DE,AX
ram:008980 62 mov A,
ram:008981 99 mov [DE],A
ram:008982 617902 incw [HL + 0x2]
ram:008985 f6 clrw AX
ram:008986 614902 cmpw AX,[HL + 0x2]
ram:008989 61f8 sknz
ram:00898b 617904 _incw [HL + 0x4]
ram:00898e efd5 br $ 0x8965
ram:008990 8c0b mov A,[HL + 0xb]
ram:008992 318e shrw AX,0x8
ram:008994 fc85e000 call !!0xe085
ram:008998 fc80e000 call !!0xe080
ram:00899c 62 mov A,
ram:00899d 9c0b mov [HL + 0xb],A
ram:00899f 717bfa DI
ram:0089a2 ac08 movw AX,[HL + 0x8]
ram:0089a4 01 addw AX,AX
ram:0089a5 12 movw BC,AX
ram:0089a6 7952c0 movw AX,!0xfc052[BC]
ram:0089a9 614914 cmpw AX,[HL + 0x14]
ram:0089ac df1a bnz $ 0x89c8
ram:0089ae 8f54c0 mov A,!0xfc054
ram:0089b1 5c01 and A,#0x1
ram:0089b3 91 dec 
ram:0089b4 df12 bnz $ 0x89c8
ram:0089b6 ab movw AX,[HL]
ram:0089b7 14 movw DE,AX
ram:0089b8 f0 clrb X
ram:0089b9 e1 oneb A
ram:0089ba ba0e movw [DE + 0xe],AX
ram:0089bc ab movw AX,[HL]
ram:0089bd 14 movw DE,AX
ram:0089be 300002 movw AX,0x200
ram:0089c1 ba0e movw [DE + 0xe],AX
ram:0089c3 cc0a01 mov [HL + 0xa],0x1
ram:0089c6 ef1d br $ 0x89e5
ram:0089c8 ac08 movw AX,[HL + 0x8]
ram:0089ca 01 addw AX,AX
ram:0089cb 12 movw BC,AX
ram:0089cc 7952c0 movw AX,!0xfc052[BC]
ram:0089cf 614914 cmpw AX,[HL + 0x14]
ram:0089d2 df05 bnz $ 0x89d9
ram:0089d4 cc0a05 mov [HL + 0xa],0x5
ram:0089d7 ef03 br $ 0x89dc
ram:0089d9 cc0a00 mov [HL + 0xa],0x0
ram:0089dc ac08 movw AX,[HL + 0x8]
ram:0089de 01 addw AX,AX
ram:0089df 12 movw BC,AX
ram:0089e0 f6 clrw AX
ram:0089e1 b1 decw AX
ram:0089e2 7852c0 movw !0xfc052[BC],AX
ram:0089e5 8c0b mov A,[HL + 0xb]
ram:0089e7 318e shrw AX,0x8
ram:0089e9 fc85e000 call !!0xe085
ram:0089ed 8c0a mov A,[HL + 0xa]
ram:0089ef 318e shrw AX,0x8
ram:0089f1 12 movw BC,AX
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
ram:008dc6 62 mov A,
ram:008dc7 9c05 mov [HL + 0x5],A
ram:008dc9 717bfa DI
ram:008dcc f6 clrw AX
ram:008dcd bb movw [HL],AX
ram:008dce bc02 movw [HL + 0x2],AX
ram:008dd0 ac06 movw AX,[HL + 0x6]
ram:008dd2 14 movw DE,AX
ram:008dd3 aa08 movw AX,[DE + 0x8]
ram:008dd5 12 movw BC,AX
ram:008dd6 4100 mov ES,0x0
ram:008dd8 1149dc64 mov A,ES:!0xf64dc[BC]
ram:008ddc 9dd8 mov 0xffdf8,A
ram:008dde f4d9 clrb 0xffdf9
ram:008de0 f6 clrw AX
ram:008de1 bdda movw 0xffdfa,AX
ram:008de3 ac02 movw AX,[HL + 0x2]
ram:008de5 46da cmpw AX,0xffdfa
ram:008de7 ab movw AX,[HL]
ram:008de8 61f8 sknz
ram:008dea 46d8 _cmpw AX,0xffdf8
ram:008dec de2f bnc $ 0x8e1d
ram:008dee ac06 movw AX,[HL + 0x6]
ram:008df0 14 movw DE,AX
ram:008df1 ab movw AX,[HL]
ram:008df2 12 movw BC,AX
ram:008df3 aa06 movw AX,[DE + 0x6]
ram:008df5 03 addw AX,BC
ram:008df6 14 movw DE,AX
ram:008df7 89 mov A,[DE]
ram:008df8 72 mov ,A
ram:008df9 ac06 movw AX,[HL + 0x6]
ram:008dfb 14 movw DE,AX
ram:008dfc aa08 movw AX,[DE + 0x8]
ram:008dfe 01 addw AX,AX
ram:008dff 04e264 addw AX,0x64e2
ram:008e02 14 movw DE,AX
ram:008e03 ab movw AX,[HL]
ram:008e04 4100 mov ES,0x0
ram:008e06 c3 push BC
ram:008e07 12 movw BC,AX
ram:008e08 11a9 movw AX,ES:[DE]
ram:008e0a 03 addw AX,BC
ram:008e0b c2 pop BC
ram:008e0c 14 movw DE,AX
ram:008e0d 62 mov A,
ram:008e0e 99 mov [DE],A
ram:008e0f 617900 incw [HL + 0x0]
ram:008e12 f6 clrw AX
ram:008e13 614900 cmpw AX,[HL + 0x0]
ram:008e16 61f8 sknz
ram:008e18 617902 _incw [HL + 0x2]
ram:008e1b efb3 br $ 0x8dd0
ram:008e1d 8c05 mov A,[HL + 0x5]
ram:008e1f 318e shrw AX,0x8
ram:008e21 fc85e000 call !!0xe085
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
ram:008e73 62 mov A,
ram:008e74 9c03 mov [HL + 0x3],A
ram:008e76 717bfa DI
ram:008e79 ac0a movw AX,[HL + 0xa]
ram:008e7b 12 movw BC,AX
ram:008e7c 4100 mov ES,0x0
ram:008e7e 1149c264 mov A,ES:!0xf64c2[BC]
ram:008e82 72 mov ,A
ram:008e83 ac0a movw AX,[HL + 0xa]
ram:008e85 04c064 addw AX,0x64c0
ram:008e88 14 movw DE,AX
ram:008e89 4100 mov ES,0x0
ram:008e8b 1189 mov A,ES:[DE]
ram:008e8d 318e shrw AX,0x8
ram:008e8f 0448c0 addw AX,0xc048
ram:008e92 14 movw DE,AX
ram:008e93 89 mov A,[DE]
ram:008e94 616a or A,
ram:008e96 99 mov [DE],A
ram:008e97 8c03 mov A,[HL + 0x3]
ram:008e99 318e shrw AX,0x8
ram:008e9b fc85e000 call !!0xe085
ram:008e9f ac0a movw AX,[HL + 0xa]
ram:008ea1 312d shlw AX,0x2
ram:008ea3 04b664 addw AX,0x64b6
ram:008ea6 14 movw DE,AX
ram:008ea7 4100 mov ES,0x0
ram:008ea9 118a02 mov A,ES:[DE + 0x2]
ram:008eac 9dd4 mov 0xffdf4,A
ram:008eae 11a9 movw AX,ES:[DE]
ram:008eb0 d4d4 cmp0 0xffdf4
ram:008eb2 df02 bnz $ 0x8eb6
ram:008eb4 f7 clrw BC
ram:008eb5 43 cmpw AX,BC
ram:008eb6 dd16 bz $ 0x8ece
ram:008eb8 ac0a movw AX,[HL + 0xa]
ram:008eba 312d shlw AX,0x2
ram:008ebc 04b664 addw AX,0x64b6
ram:008ebf 14 movw DE,AX
ram:008ec0 4100 mov ES,0x0
ram:008ec2 118a02 mov A,ES:[DE + 0x2]
ram:008ec5 9efc mov CS,A
ram:008ec7 11a9 movw AX,ES:[DE]
ram:008ec9 14 movw DE,AX
ram:008eca ac0a movw AX,[HL + 0xa]
ram:008ecc 61ea call DE
ram:008ece fc80e000 call !!0xe080
ram:008ed2 62 mov A,
ram:008ed3 9c03 mov [HL + 0x3],A
ram:008ed5 717bfa DI
ram:008ed8 f6 clrw AX
ram:008ed9 bc08 movw [HL + 0x8],AX
ram:008edb 8c09 mov A,[HL + 0x9]
ram:008edd 01 addw AX,AX
ram:008ede 61d8 sknc
ram:008ee0 ecfb8f00 _br !!0x8ffb
ram:008ee4 ac08 movw AX,[HL + 0x8]
ram:008ee6 01 addw AX,AX
ram:008ee7 0474c0 addw AX,0xc074
ram:008eea 14 movw DE,AX
ram:008eeb a9 movw AX,[DE]
ram:008eec bc04 movw [HL + 0x4],AX
ram:008eee f6 clrw AX
ram:008eef 614904 cmpw AX,[HL + 0x4]
ram:008ef2 61f8 sknz
ram:008ef4 ecf48f00 _br !!0x8ff4
ram:008ef8 8c03 mov A,[HL + 0x3]
ram:008efa 318e shrw AX,0x8
ram:008efc fc85e000 call !!0xe085
ram:008f00 8c04 mov A,[HL + 0x4]
ram:008f02 5c00 and A,#0x0
ram:008f04 70 mov ,A
ram:008f05 8c05 mov A,[HL + 0x5]
ram:008f07 6168 or A,
ram:008f09 dd33 bz $ 0x8f3e
ram:008f0b 8c04 mov A,[HL + 0x4]
ram:008f0d 5c00 and A,#0x0
ram:008f0f 70 mov ,A
ram:008f10 8c05 mov A,[HL + 0x5]
ram:008f12 5cf0 and A,#0xf0
ram:008f14 6168 or A,
ram:008f16 dd14 bz $ 0x8f2c
ram:008f18 ac04 movw AX,[HL + 0x4]
ram:008f1a 31ce shrw AX,0xc
ram:008f1c 12 movw BC,AX
ram:008f1d 4100 mov ES,0x0
ram:008f1f 11498c64 mov A,ES:!0xf648c[BC]
ram:008f23 318f sarw AX,0x8
ram:008f25 040c00 addw AX,0xc
ram:008f28 bc06 movw [HL + 0x6],AX
ram:008f2a ef10 br $ 0x8f3c
ram:008f2c ac04 movw AX,[HL + 0x4]
ram:008f2e 73 mov ,A
ram:008f2f 4100 mov ES,0x0
ram:008f31 11098c64 mov A,ES:!0xf648c[B]
ram:008f35 318f sarw AX,0x8
ram:008f37 040800 addw AX,0x8
ram:008f3a bc06 movw [HL + 0x6],AX
ram:008f3c ef2b br $ 0x8f69
ram:008f3e 51f0 mov ,0xf0
ram:008f40 5e04 and A,[HL + 0x4]
ram:008f42 318e shrw AX,0x8
ram:008f44 6168 or A,
ram:008f46 dd14 bz $ 0x8f5c
ram:008f48 ac04 movw AX,[HL + 0x4]
ram:008f4a 314e shrw AX,0x4
ram:008f4c 12 movw BC,AX
ram:008f4d 4100 mov ES,0x0
ram:008f4f 11498c64 mov A,ES:!0xf648c[BC]
ram:008f53 318f sarw AX,0x8
ram:008f55 040400 addw AX,0x4
ram:008f58 bc06 movw [HL + 0x6],AX
ram:008f5a ef0d br $ 0x8f69
ram:008f5c ac04 movw AX,[HL + 0x4]
ram:008f5e 12 movw BC,AX
ram:008f5f 4100 mov ES,0x0
ram:008f61 11498c64 mov A,ES:!0xf648c[BC]
ram:008f65 318f sarw AX,0x8
ram:008f67 bc06 movw [HL + 0x6],AX
ram:008f69 ac08 movw AX,[HL + 0x8]
ram:008f6b 314d shlw AX,0x4
ram:008f6d 610906 addw AX,[HL + 0x6]
ram:008f70 bc0a movw [HL + 0xa],AX
ram:008f72 fc80e000 call !!0xe080
ram:008f76 62 mov A,
ram:008f77 9c03 mov [HL + 0x3],A
ram:008f79 717bfa DI
ram:008f7c ac08 movw AX,[HL + 0x8]
ram:008f7e 01 addw AX,AX
ram:008f7f 0474c0 addw AX,0xc074
ram:008f82 14 movw DE,AX
ram:008f83 a9 movw AX,[DE]
ram:008f84 12 movw BC,AX
ram:008f85 ac06 movw AX,[HL + 0x6]
ram:008f87 01 addw AX,AX
ram:008f88 046c64 addw AX,0x646c
ram:008f8b 14 movw DE,AX
ram:008f8c 4100 mov ES,0x0
ram:008f8e 1189 mov A,ES:[DE]
ram:008f90 615a and A,
ram:008f92 08 xch A,X
ram:008f93 118a01 mov A,ES:[DE + 0x1]
ram:008f96 615b and A,
ram:008f98 6168 or A,
ram:008f9a dd45 bz $ 0x8fe1
ram:008f9c ac06 movw AX,[HL + 0x6]
ram:008f9e 01 addw AX,AX
ram:008f9f 046c64 addw AX,0x646c
ram:008fa2 14 movw DE,AX
ram:008fa3 11a9 movw AX,ES:[DE]
ram:008fa5 12 movw BC,AX
ram:008fa6 f6 clrw AX
ram:008fa7 b1 decw AX
ram:008fa8 23 subw AX,BC
ram:008fa9 12 movw BC,AX
ram:008faa ac08 movw AX,[HL + 0x8]
ram:008fac 01 addw AX,AX
ram:008fad 0474c0 addw AX,0xc074
ram:008fb0 14 movw DE,AX
ram:008fb1 a9 movw AX,[DE]
ram:008fb2 615b and A,
ram:008fb4 08 xch A,X
ram:008fb5 615a and A,
ram:008fb7 08 xch A,X
ram:008fb8 b9 movw [DE],AX
ram:008fb9 8c03 mov A,[HL + 0x3]
ram:008fbb 318e shrw AX,0x8
ram:008fbd fc85e000 call !!0xe085
ram:008fc1 ac0c movw AX,[HL + 0xc]
ram:008fc3 01 addw AX,AX
ram:008fc4 12 movw BC,AX
ram:008fc5 ac0a movw AX,[HL + 0xa]
ram:008fc7 7852c0 movw !0xfc052[BC],AX
ram:008fca c1 push AX
ram:008fcb ac0e movw AX,[HL + 0xe]
ram:008fcd fcf38800 call !!0x88f3
ram:008fd1 c0 pop AX
ram:008fd2 62 mov A,
ram:008fd3 9c02 mov [HL + 0x2],A
ram:008fd5 4c05 cmp A,#0x5
ram:008fd7 df06 bnz $ 0x8fdf
ram:008fd9 ac0a movw AX,[HL + 0xa]
ram:008fdb fc507302 call !!0x27350
ram:008fdf ef2b br $ 0x900c
ram:008fe1 ac0c movw AX,[HL + 0xc]
ram:008fe3 01 addw AX,AX
ram:008fe4 12 movw BC,AX
ram:008fe5 f6 clrw AX
ram:008fe6 b1 decw AX
ram:008fe7 7852c0 movw !0xfc052[BC],AX
ram:008fea 8c03 mov A,[HL + 0x3]
ram:008fec 318e shrw AX,0x8
ram:008fee fc85e000 call !!0xe085
ram:008ff2 ef18 br $ 0x900c
ram:008ff4 618908 decw [HL + 0x8]
ram:008ff7 ecdb8e00 br !!0x8edb
ram:008ffb ac0c movw AX,[HL + 0xc]
ram:008ffd 01 addw AX,AX
ram:008ffe 12 movw BC,AX
ram:008fff f6 clrw AX
ram:009000 b1 decw AX
ram:009001 7852c0 movw !0xfc052[BC],AX
ram:009004 8c03 mov A,[HL + 0x3]
ram:009006 318e shrw AX,0x8
ram:009008 fc85e000 call !!0xe085
ram:00900c 1010 addw SP,0x10
ram:00900e c6 pop HL
ram:00900f d7 ret
ram:0091d7 c7 push HL
ram:0091d8 c1 push AX
ram:0091d9 fbf8ff movw HL,!0xffff8
ram:0091dc fc80e000 call !!0xe080
ram:0091e0 62 mov A,
ram:0091e1 9c01 mov [HL + 0x1],A
ram:0091e3 717bfa DI
ram:0091e6 f6 clrw AX
ram:0091e7 4256c0 cmpw AX,!0xfc056
ram:0091ea df1f bnz $ 0x920b
ram:0091ec aed4 movw AX,0xfffd4
ram:0091ee 4100 mov ES,0x0
ram:0091f0 115fa164 and A,ES:!0xf64a1
ram:0091f4 08 xch A,X
ram:0091f5 115fa064 and A,ES:!0xf64a0
ram:0091f9 08 xch A,X
ram:0091fa bf58c0 movw !0xfc058,AX
ram:0091fd aed4 movw AX,0xfffd4
ram:0091ff 116fa164 or A,ES:!0xf64a1
ram:009203 08 xch A,X
ram:009204 116fa064 or A,ES:!0xf64a0
ram:009208 08 xch A,X
ram:009209 bed4 movw 0xfffd4,AX
ram:00920b a256c0 incw !0xfc056
ram:00920e 8c01 mov A,[HL + 0x1]
ram:009210 318e shrw AX,0x8
ram:009212 fc85e000 call !!0xe085
ram:009216 c0 pop AX
ram:009217 c6 pop HL
ram:009218 d7 ret
ram:009219 c7 push HL
ram:00921a c1 push AX
ram:00921b fbf8ff movw HL,!0xffff8
ram:00921e fc80e000 call !!0xe080
ram:009222 62 mov A,
ram:009223 9c01 mov [HL + 0x1],A
ram:009225 717bfa DI
ram:009228 b256c0 decw !0xfc056
ram:00922b f6 clrw AX
ram:00922c 4256c0 cmpw AX,!0xfc056
ram:00922f df18 bnz $ 0x9249
ram:009231 b1 decw AX
ram:009232 4100 mov ES,0x0
ram:009234 1122a064 subw AX,ES:!0xf64a0
ram:009238 12 movw BC,AX
ram:009239 aed4 movw AX,0xfffd4
ram:00923b 615b and A,
ram:00923d 08 xch A,X
ram:00923e 615a and A,
ram:009240 6f58c0 or A,!0xfc058
ram:009243 08 xch A,X
ram:009244 6f59c0 or A,!0xfc059
ram:009247 bed4 movw 0xfffd4,AX
ram:009249 8c01 mov A,[HL + 0x1]
ram:00924b 318e shrw AX,0x8
ram:00924d fc85e000 call !!0xe085
ram:009251 c0 pop AX
ram:009252 c6 pop HL
ram:009253 d7 ret
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
ram:00927e c7 push HL
ram:00927f c1 push AX
ram:009280 fbf8ff movw HL,!0xffff8
ram:009283 effe br $ 0x9283
ram:009288 c7 push HL
ram:009289 c1 push AX
ram:00928a fbf8ff movw HL,!0xffff8
ram:00928d e6 onew AX
ram:00928e 614900 cmpw AX,[HL + 0x0]
ram:009291 61f8 sknz
ram:009293 fc10b900 _call !!0xb910
ram:009297 300800 movw AX,0x8
ram:00929a 614900 cmpw AX,[HL + 0x0]
ram:00929d 61f8 sknz
ram:00929f fc46b900 _call !!0xb946
ram:0092a3 c0 pop AX
ram:0092a4 c6 pop HL
ram:0092a5 d7 ret
ram:0092a6 c7 push HL
ram:0092a7 c1 push AX
ram:0092a8 fbf8ff movw HL,!0xffff8
ram:0092ab c0 pop AX
ram:0092ac c6 pop HL
ram:0092ad d7 ret
ram:0092ae c7 push HL
ram:0092af c1 push AX
ram:0092b0 fbf8ff movw HL,!0xffff8
ram:0092b3 c0 pop AX
ram:0092b4 c6 pop HL
ram:0092b5 d7 ret
ram:00a1e6 1004 addw SP,0x4
ram:00a1e8 c6 pop HL
ram:00a1e9 d7 ret
ram:00a27d c7 push HL
ram:00a27e 2004 subw SP,0x4
ram:00a280 fbf8ff movw HL,!0xffff8
ram:00a283 cc0300 mov [HL + 0x3],0x0
ram:00a286 f6 clrw AX
ram:00a287 bb movw [HL],AX
ram:00a288 ab movw AX,[HL]
ram:00a289 443f00 cmpw AX,0x3f
ram:00a28c de28 bnc $ 0xa2b6
ram:00a28e ab movw AX,[HL]
ram:00a28f 12 movw BC,AX
ram:00a290 4100 mov ES,0x0
ram:00a292 11494265 mov A,ES:!0xf6542[BC]
ram:00a296 81 inc 
ram:00a297 dd18 bz $ 0xa2b1
ram:00a299 615903 inc [HL + 0x3]
ram:00a29c ab movw AX,[HL]
ram:00a29d 12 movw BC,AX
ram:00a29e 11494265 mov A,ES:!0xf6542[BC]
ram:00a2a2 4c0a cmp A,#0xa
ram:00a2a4 dc0b bc $ 0xa2b1
ram:00a2a6 304807 movw AX,0x748
ram:00a2a9 c1 push AX
ram:00a2aa e6 onew AX
ram:00a2ab a1 incw AX
ram:00a2ac fc7e9200 call !!0x927e
ram:00a2b0 c0 pop AX
ram:00a2b1 617900 incw [HL + 0x0]
ram:00a2b4 efd2 br $ 0xa288
ram:00a2b6 8c03 mov A,[HL + 0x3]
ram:00a2b8 4c0a cmp A,#0xa
ram:00a2ba dd0c bz $ 0xa2c8
ram:00a2bc 304d07 movw AX,0x74d
ram:00a2bf c1 push AX
ram:00a2c0 300300 movw AX,0x3
ram:00a2c3 fc7e9200 call !!0x927e
ram:00a2c7 c0 pop AX
ram:00a2c8 f6 clrw AX
ram:00a2c9 bb movw [HL],AX
ram:00a2ca ab movw AX,[HL]
ram:00a2cb 440a00 cmpw AX,0xa
ram:00a2ce de22 bnc $ 0xa2f2
ram:00a2d0 ab movw AX,[HL]
ram:00a2d1 01 addw AX,AX
ram:00a2d2 12 movw BC,AX
ram:00a2d3 312d shlw AX,0x2
ram:00a2d5 03 addw AX,BC
ram:00a2d6 12 movw BC,AX
ram:00a2d7 4100 mov ES,0x0
ram:00a2d9 11498a65 mov A,ES:!0xf658a[BC]
ram:00a2dd 4c2c cmp A,#0x2c
ram:00a2df dc0c bc $ 0xa2ed
ram:00a2e1 305507 movw AX,0x755
ram:00a2e4 c1 push AX
ram:00a2e5 300400 movw AX,0x4
ram:00a2e8 fc7e9200 call !!0x927e
ram:00a2ec c0 pop AX
ram:00a2ed 617900 incw [HL + 0x0]
ram:00a2f0 efd8 br $ 0xa2ca
ram:00a2f2 ab movw AX,[HL]
ram:00a2f3 01 addw AX,AX
ram:00a2f4 12 movw BC,AX
ram:00a2f5 312d shlw AX,0x2
ram:00a2f7 03 addw AX,BC
ram:00a2f8 12 movw BC,AX
ram:00a2f9 4100 mov ES,0x0
ram:00a2fb 11498a65 mov A,ES:!0xf658a[BC]
ram:00a2ff 4c2c cmp A,#0x2c
ram:00a301 dd0c bz $ 0xa30f
ram:00a303 306007 movw AX,0x760
ram:00a306 c1 push AX
ram:00a307 300400 movw AX,0x4
ram:00a30a fc7e9200 call !!0x927e
ram:00a30e c0 pop AX
ram:00a30f f6 clrw AX
ram:00a310 bb movw [HL],AX
ram:00a311 ab movw AX,[HL]
ram:00a312 442c00 cmpw AX,0x2c
ram:00a315 de2d bnc $ 0xa344
ram:00a317 ab movw AX,[HL]
ram:00a318 312d shlw AX,0x2
ram:00a31a 12 movw BC,AX
ram:00a31b 01 addw AX,AX
ram:00a31c 03 addw AX,BC
ram:00a31d 04fc65 addw AX,0x65fc
ram:00a320 14 movw DE,AX
ram:00a321 4100 mov ES,0x0
ram:00a323 118a0a mov A,ES:[DE + 0xa]
ram:00a326 9dd4 mov 0xffdf4,A
ram:00a328 11aa08 movw AX,ES:[DE + 0x8]
ram:00a32b d4d4 cmp0 0xffdf4
ram:00a32d df02 bnz $ 0xa331
ram:00a32f f7 clrw BC
ram:00a330 43 cmpw AX,BC
ram:00a331 df0c bnz $ 0xa33f
ram:00a333 306707 movw AX,0x767
ram:00a336 c1 push AX
ram:00a337 300600 movw AX,0x6
ram:00a33a fc7e9200 call !!0x927e
ram:00a33e c0 pop AX
ram:00a33f 617900 incw [HL + 0x0]
ram:00a342 efcd br $ 0xa311
ram:00a344 1004 addw SP,0x4
ram:00a346 c6 pop HL
ram:00a347 d7 ret
ram:00a348 d7 ret
ram:00a349 ec5ea300 br !!0xa35e
ram:00a34d cf8fc0ff mov !0xfc08f,0xff
ram:00a351 3098c0 movw AX,0xc098
ram:00a354 bf92c0 movw !0xfc092,AX
ram:00a357 bf94c0 movw !0xfc094,AX
ram:00a35a f58dc0 clrb !0xfc08d
ram:00a35d d7 ret
ram:00a35e c7 push HL
ram:00a35f e6 onew AX
ram:00a360 16 movw HL,AX
ram:00a361 f6 clrw AX
ram:00a362 47 cmpw AX,HL
ram:00a363 dd0a bz $ 0xa36f
ram:00a365 b7 decw HL
ram:00a366 17 movw AX,HL
ram:00a367 01 addw AX,AX
ram:00a368 12 movw BC,AX
ram:00a369 f6 clrw AX
ram:00a36a 7896c0 movw !0xfc096[BC],AX
ram:00a36d eff2 br $ 0xa361
ram:00a36f fc4da300 call !!0xa34d
ram:00a373 c6 pop HL
ram:00a374 d7 ret
ram:00a375 d7 ret
ram:00a376 c7 push HL
ram:00a377 c1 push AX
ram:00a378 2004 subw SP,0x4
ram:00a37a fbf8ff movw HL,!0xffff8
ram:00a37d f6 clrw AX
ram:00a37e bc02 movw [HL + 0x2],AX
ram:00a380 408fc0ff cmp !0xfc08f,0xff
ram:00a384 df36 bnz $ 0xa3bc
ram:00a386 ac04 movw AX,[HL + 0x4]
ram:00a388 449903 cmpw AX,0x399
ram:00a38b dc09 bc $ 0xa396
ram:00a38d 300300 movw AX,0x3
ram:00a390 fc6dde00 call !!0xde6d
ram:00a394 ef26 br $ 0xa3bc
ram:00a396 e58ac0 oneb !0xfc08a
ram:00a399 f58cc0 clrb !0xfc08c
ram:00a39c ac04 movw AX,[HL + 0x4]
ram:00a39e bf90c0 movw !0xfc090,AX
ram:00a3a1 f58fc0 clrb !0xfc08f
ram:00a3a4 3088c0 movw AX,0xc088
ram:00a3a7 fc25a700 call !!0xa725
ram:00a3ab 62 mov A,
ram:00a3ac 9c01 mov [HL + 0x1],A
ram:00a3ae d1 cmp0 A
ram:00a3af df07 bnz $ 0xa3b8
ram:00a3b1 af92c0 movw AX,!0xfc092
ram:00a3b4 bc02 movw [HL + 0x2],AX
ram:00a3b6 ef04 br $ 0xa3bc
ram:00a3b8 cf8fc0ff mov !0xfc08f,0xff
ram:00a3bc ac02 movw AX,[HL + 0x2]
ram:00a3be 12 movw BC,AX
ram:00a3bf 1006 addw SP,0x6
ram:00a3c1 c6 pop HL
ram:00a3c2 d7 ret
ram:00a3c3 c7 push HL
ram:00a3c4 16 movw HL,AX
ram:00a3c5 f6 clrw AX
ram:00a3c6 c1 push AX
ram:00a3c7 3088c0 movw AX,0xc088
ram:00a3ca fc9ca700 call !!0xa79c
ram:00a3ce c0 pop AX
ram:00a3cf fc62de00 call !!0xde62
ram:00a3d3 c6 pop HL
ram:00a3d4 d7 ret
ram:00a3d5 c7 push HL
ram:00a3d6 16 movw HL,AX
ram:00a3d7 300300 movw AX,0x3
ram:00a3da c1 push AX
ram:00a3db 3088c0 movw AX,0xc088
ram:00a3de fc9ca700 call !!0xa79c
ram:00a3e2 c0 pop AX
ram:00a3e3 c6 pop HL
ram:00a3e4 d7 ret
ram:00a3e5 c7 push HL
ram:00a3e6 16 movw HL,AX
ram:00a3e7 c6 pop HL
ram:00a3e8 d7 ret
ram:00a3e9 c7 push HL
ram:00a3ea c1 push AX
ram:00a3eb 2006 subw SP,0x6
ram:00a3ed fbf8ff movw HL,!0xffff8
ram:00a3f0 ac06 movw AX,[HL + 0x6]
ram:00a3f2 14 movw DE,AX
ram:00a3f3 8a02 mov A,[DE + 0x2]
ram:00a3f5 91 dec 
ram:00a3f6 dd0c bz $ 0xa404
ram:00a3f8 30b609 movw AX,0x9b6
ram:00a3fb c1 push AX
ram:00a3fc 304200 movw AX,0x42
ram:00a3ff fc7e9200 call !!0x927e
ram:00a403 c0 pop AX
ram:00a404 3096c0 movw AX,0xc096
ram:00a407 bc02 movw [HL + 0x2],AX
ram:00a409 14 movw DE,AX
ram:00a40a a9 movw AX,[DE]
ram:00a40b 6168 or A,
ram:00a40d dd2a bz $ 0xa439
ram:00a40f fc3ee000 call !!0xe03e
ram:00a413 ac02 movw AX,[HL + 0x2]
ram:00a415 14 movw DE,AX
ram:00a416 a9 movw AX,[DE]
ram:00a417 6168 or A,
ram:00a419 dd1a bz $ 0xa435
ram:00a41b af96c0 movw AX,!0xfc096
ram:00a41e bb movw [HL],AX
ram:00a41f ac06 movw AX,[HL + 0x6]
ram:00a421 bf96c0 movw !0xfc096,AX
ram:00a424 300300 movw AX,0x3
ram:00a427 fc97a400 call !!0xa497
ram:00a42b ab movw AX,[HL]
ram:00a42c bf96c0 movw !0xfc096,AX
ram:00a42f fc62e000 call !!0xe062
ram:00a433 ef22 br $ 0xa457
ram:00a435 fc62e000 call !!0xe062
ram:00a439 ac06 movw AX,[HL + 0x6]
ram:00a43b bf96c0 movw !0xfc096,AX
ram:00a43e 14 movw DE,AX
ram:00a43f aa08 movw AX,[DE + 0x8]
ram:00a441 c1 push AX
ram:00a442 aa0c movw AX,[DE + 0xc]
ram:00a444 fc4cda00 call !!0xda4c
ram:00a448 c0 pop AX
ram:00a449 62 mov A,
ram:00a44a 9c05 mov [HL + 0x5],A
ram:00a44c d1 cmp0 A
ram:00a44d dd08 bz $ 0xa457
ram:00a44f 8c05 mov A,[HL + 0x5]
ram:00a451 318e shrw AX,0x8
ram:00a453 fc97a400 call !!0xa497
ram:00a457 1008 addw SP,0x8
ram:00a459 c6 pop HL
ram:00a45a d7 ret
ram:00a45b c7 push HL
ram:00a45c c1 push AX
ram:00a45d c1 push AX
ram:00a45e fbf8ff movw HL,!0xffff8
ram:00a461 ac02 movw AX,[HL + 0x2]
ram:00a463 14 movw DE,AX
ram:00a464 aa06 movw AX,[DE + 0x6]
ram:00a466 bb movw [HL],AX
ram:00a467 ab movw AX,[HL]
ram:00a468 b1 decw AX
ram:00a469 bb movw [HL],AX
ram:00a46a a1 incw AX
ram:00a46b 6168 or A,
ram:00a46d dd1a bz $ 0xa489
ram:00a46f ac02 movw AX,[HL + 0x2]
ram:00a471 14 movw DE,AX
ram:00a472 ab movw AX,[HL]
ram:00a473 12 movw BC,AX
ram:00a474 aa04 movw AX,[DE + 0x4]
ram:00a476 03 addw AX,BC
ram:00a477 14 movw DE,AX
ram:00a478 89 mov A,[DE]
ram:00a479 72 mov ,A
ram:00a47a ac02 movw AX,[HL + 0x2]
ram:00a47c 14 movw DE,AX
ram:00a47d ab movw AX,[HL]
ram:00a47e c3 push BC
ram:00a47f 12 movw BC,AX
ram:00a480 aa02 movw AX,[DE + 0x2]
ram:00a482 03 addw AX,BC
ram:00a483 c2 pop BC
ram:00a484 14 movw DE,AX
ram:00a485 62 mov A,
ram:00a486 99 mov [DE],A
ram:00a487 efde br $ 0xa467
ram:00a489 1004 addw SP,0x4
ram:00a48b c6 pop HL
ram:00a48c d7 ret
ram:00a48d c7 push HL
ram:00a48e 16 movw HL,AX
ram:00a48f 17 movw AX,HL
ram:00a490 fc5ba400 call !!0xa45b
ram:00a494 f7 clrw BC
ram:00a495 c6 pop HL
ram:00a496 d7 ret
ram:00a497 c7 push HL
ram:00a498 16 movw HL,AX
ram:00a499 66 mov A,
ram:00a49a d1 cmp0 A
ram:00a49b dd04 bz $ 0xa4a1
ram:00a49d 5103 mov ,0x3
ram:00a49f ef01 br $ 0xa4a2
ram:00a4a1 f1 clrb A
ram:00a4a2 318f sarw AX,0x8
ram:00a4a4 c1 push AX
ram:00a4a5 af96c0 movw AX,!0xfc096
ram:00a4a8 fcd6a700 call !!0xa7d6
ram:00a4ac c0 pop AX
ram:00a4ad f6 clrw AX
ram:00a4ae bf96c0 movw !0xfc096,AX
ram:00a4b1 c6 pop HL
ram:00a4b2 d7 ret
ram:00a4b3 c7 push HL
ram:00a4b4 16 movw HL,AX
ram:00a4b5 17 movw AX,HL
ram:00a4b6 f1 clrb A
ram:00a4b7 fc97a400 call !!0xa497
ram:00a4bb f7 clrw BC
ram:00a4bc c6 pop HL
ram:00a4bd d7 ret
ram:00a4be c7 push HL
ram:00a4bf 16 movw HL,AX
ram:00a4c0 8c02 mov A,[HL + 0x2]
ram:00a4c2 91 dec 
ram:00a4c3 dd0c bz $ 0xa4d1
ram:00a4c5 30f80a movw AX,0xaf8
ram:00a4c8 c1 push AX
ram:00a4c9 304200 movw AX,0x42
ram:00a4cc fc7e9200 call !!0x927e
ram:00a4d0 c0 pop AX
ram:00a4d1 17 movw AX,HL
ram:00a4d2 14 movw DE,AX
ram:00a4d3 ca07ff mov [DE + 0x7],0xff
ram:00a4d6 c6 pop HL
ram:00a4d7 d7 ret
ram:00a4d8 f508c8 clrb !0xfc808
ram:00a4db 713809c8 clr1 !0xfc809.0x3
ram:00a4df 3409c8 movw DE,0xc809
ram:00a4e2 89 mov A,[DE]
ram:00a4e3 5cf8 and A,#0xf8
ram:00a4e5 99 mov [DE],A
ram:00a4e6 f50cc8 clrb !0xfc80c
ram:00a4e9 71080dc8 clr1 !0xfc80d.0x0
ram:00a4ed cf30c47f mov !0xfc430,0x7f
ram:00a4f1 cf32c478 mov !0xfc432,0x78
ram:00a4f5 d7 ret
ram:00a4f6 e6 onew AX
ram:00a4f7 bf12c8 movw !0xfc812,AX
ram:00a4fa 71080dc8 clr1 !0xfc80d.0x0
ram:00a4fe af0ac8 movw AX,!0xfc80a
ram:00a501 ec1da700 br !!0xa71d
ram:00a505 fc49a300 call !!0xa349
ram:00a509 ec0da500 br !!0xa50d
ram:00a50d 34f0c7 movw DE,0xc7f0
ram:00a510 f1 clrb A
ram:00a511 99 mov [DE],A
ram:00a512 a5 incw DE
ram:00a513 89 mov A,[DE]
ram:00a514 5cf0 and A,#0xf0
ram:00a516 99 mov [DE],A
ram:00a517 f6 clrw AX
ram:00a518 bf02c8 movw !0xfc802,AX
ram:00a51b bf04c8 movw !0xfc804,AX
ram:00a51e bf06c8 movw !0xfc806,AX
ram:00a521 cff9c7ff mov !0xfc7f9,0xff
ram:00a525 f5f7c7 clrb !0xfc7f7
ram:00a528 3033c4 movw AX,0xc433
ram:00a52b bffcc7 movw !0xfc7fc,AX
ram:00a52e bffec7 movw !0xfc7fe,AX
ram:00a531 cfebc77f mov !0xfc7eb,0x7f
ram:00a535 ec5ea300 br !!0xa35e
ram:00a539 c7 push HL
ram:00a53a f6 clrw AX
ram:00a53b 4202c8 cmpw AX,!0xfc802
ram:00a53e dd0e bz $ 0xa54e
ram:00a540 b202c8 decw !0xfc802
ram:00a543 4202c8 cmpw AX,!0xfc802
ram:00a546 df06 bnz $ 0xa54e
ram:00a548 5004 mov ,0x4
ram:00a54a fc25a800 call !!0xa825
ram:00a54e f6 clrw AX
ram:00a54f 4204c8 cmpw AX,!0xfc804
ram:00a552 dd45 bz $ 0xa599
ram:00a554 3004c8 movw AX,0xc804
ram:00a557 16 movw HL,AX
ram:00a558 fc3ee000 call !!0xe03e
ram:00a55c ab movw AX,[HL]
ram:00a55d 6168 or A,
ram:00a55f dd34 bz $ 0xa595
ram:00a561 b204c8 decw !0xfc804
ram:00a564 f6 clrw AX
ram:00a565 4204c8 cmpw AX,!0xfc804
ram:00a568 df2b bnz $ 0xa595
ram:00a56a 8ff0c7 mov A,!0xfc7f0
ram:00a56d 5c0f and A,#0xf
ram:00a56f 4c03 cmp A,#0x3
ram:00a571 dd0a bz $ 0xa57d
ram:00a573 30380d movw AX,0xd38
ram:00a576 c1 push AX
ram:00a577 f6 clrw AX
ram:00a578 fc7e9200 call !!0x927e
ram:00a57c c0 pop AX
ram:00a57d fcf7aa00 call !!0xaaf7
ram:00a581 e6 onew AX
ram:00a582 43 cmpw AX,BC
ram:00a583 dd05 bz $ 0xa58a
ram:00a585 f6 clrw AX
ram:00a586 fc08ac00 call !!0xac08
ram:00a58a fc9ea900 call !!0xa99e
ram:00a58e 34f0c7 movw DE,0xc7f0
ram:00a591 89 mov A,[DE]
ram:00a592 5cf0 and A,#0xf0
ram:00a594 99 mov [DE],A
ram:00a595 fc62e000 call !!0xe062
ram:00a599 c6 pop HL
ram:00a59a d7 ret
ram:00a59b c7 push HL
ram:00a59c 2004 subw SP,0x4
ram:00a59e fbf8ff movw HL,!0xffff8
ram:00a5a1 fc5aa800 call !!0xa85a
ram:00a5a5 13 movw AX,BC
ram:00a5a6 bc02 movw [HL + 0x2],AX
ram:00a5a8 fc75a300 call !!0xa375
ram:00a5ac f6 clrw AX
ram:00a5ad 614902 cmpw AX,[HL + 0x2]
ram:00a5b0 61f8 sknz
ram:00a5b2 ee3f01 _br $! 0xa6f4
ram:00a5b5 8c02 mov A,[HL + 0x2]
ram:00a5b7 5c00 and A,#0x0
ram:00a5b9 8c03 mov A,[HL + 0x3]
ram:00a5bb 5cf0 and A,#0xf0
ram:00a5bd 31ce shrw AX,0xc
ram:00a5bf 60 mov A,
ram:00a5c0 9c01 mov [HL + 0x1],A
ram:00a5c2 ac02 movw AX,[HL + 0x2]
ram:00a5c4 314d shlw AX,0x4
ram:00a5c6 bc02 movw [HL + 0x2],AX
ram:00a5c8 8c01 mov A,[HL + 0x1]
ram:00a5ca d1 cmp0 A
ram:00a5cb dddf bz $ 0xa5ac
ram:00a5cd 8ff0c7 mov A,!0xfc7f0
ram:00a5d0 5c0f and A,#0xf
ram:00a5d2 d1 cmp0 A
ram:00a5d3 dd0f bz $ 0xa5e4
ram:00a5d5 91 dec 
ram:00a5d6 dd35 bz $ 0xa60d
ram:00a5d8 91 dec 
ram:00a5d9 dd6a bz $ 0xa645
ram:00a5db 91 dec 
ram:00a5dc 61f8 sknz
ram:00a5de eeae00 _br $! 0xa68f
ram:00a5e1 ee0301 br $! 0xa6e7
ram:00a5e4 8c01 mov A,[HL + 0x1]
ram:00a5e6 91 dec 
ram:00a5e7 df18 bnz $ 0xa601
ram:00a5e9 305900 movw AX,0x59
ram:00a5ec bf02c8 movw !0xfc802,AX
ram:00a5ef fc74a900 call !!0xa974
ram:00a5f3 34f0c7 movw DE,0xc7f0
ram:00a5f6 89 mov A,[DE]
ram:00a5f7 5cf0 and A,#0xf0
ram:00a5f9 81 inc 
ram:00a5fa 99 mov [DE],A
ram:00a5fb 89 mov A,[DE]
ram:00a5fc 5c0f and A,#0xf
ram:00a5fe 99 mov [DE],A
ram:00a5ff efab br $ 0xa5ac
ram:00a601 307b0d movw AX,0xd7b
ram:00a604 c1 push AX
ram:00a605 e6 onew AX
ram:00a606 fc7e9200 call !!0x927e
ram:00a60a c0 pop AX
ram:00a60b ef9f br $ 0xa5ac
ram:00a60d 8c01 mov A,[HL + 0x1]
ram:00a60f 2c03 sub A,#0x3
ram:00a611 dd05 bz $ 0xa618
ram:00a613 91 dec 
ram:00a614 dd13 bz $ 0xa629
ram:00a616 ef20 br $ 0xa638
ram:00a618 f6 clrw AX
ram:00a619 bf02c8 movw !0xfc802,AX
ram:00a61c fcafa900 call !!0xa9af
ram:00a620 34f0c7 movw DE,0xc7f0
ram:00a623 89 mov A,[DE]
ram:00a624 5cf0 and A,#0xf0
ram:00a626 99 mov [DE],A
ram:00a627 ef19 br $ 0xa642
ram:00a629 fce4a900 call !!0xa9e4
ram:00a62d 34f0c7 movw DE,0xc7f0
ram:00a630 89 mov A,[DE]
ram:00a631 5cf0 and A,#0xf0
ram:00a633 6c02 or A,#0x2
ram:00a635 99 mov [DE],A
ram:00a636 ef0a br $ 0xa642
ram:00a638 308e0d movw AX,0xd8e
ram:00a63b c1 push AX
ram:00a63c e6 onew AX
ram:00a63d fc7e9200 call !!0x927e
ram:00a641 c0 pop AX
ram:00a642 eeac00 br $! 0xa6f1
ram:00a645 8c01 mov A,[HL + 0x1]
ram:00a647 91 dec 
ram:00a648 dd2c bz $ 0xa676
ram:00a64a 91 dec 
ram:00a64b dd1c bz $ 0xa669
ram:00a64d 91 dec 
ram:00a64e df33 bnz $ 0xa683
ram:00a650 fc3ee000 call !!0xe03e
ram:00a654 30f501 movw AX,0x1f5
ram:00a657 bf04c8 movw !0xfc804,AX
ram:00a65a fc62e000 call !!0xe062
ram:00a65e 34f0c7 movw DE,0xc7f0
ram:00a661 89 mov A,[DE]
ram:00a662 5cf0 and A,#0xf0
ram:00a664 6c03 or A,#0x3
ram:00a666 99 mov [DE],A
ram:00a667 ef24 br $ 0xa68d
ram:00a669 305900 movw AX,0x59
ram:00a66c bf02c8 movw !0xfc802,AX
ram:00a66f 34f0c7 movw DE,0xc7f0
ram:00a672 e1 oneb A
ram:00a673 99 mov [DE],A
ram:00a674 ef17 br $ 0xa68d
ram:00a676 fce4a900 call !!0xa9e4
ram:00a67a 34f0c7 movw DE,0xc7f0
ram:00a67d 89 mov A,[DE]
ram:00a67e 5c0f and A,#0xf
ram:00a680 99 mov [DE],A
ram:00a681 ef0a br $ 0xa68d
ram:00a683 30aa0d movw AX,0xdaa
ram:00a686 c1 push AX
ram:00a687 e6 onew AX
ram:00a688 fc7e9200 call !!0x927e
ram:00a68c c0 pop AX
ram:00a68d ef62 br $ 0xa6f1
ram:00a68f 8c01 mov A,[HL + 0x1]
ram:00a691 91 dec 
ram:00a692 dd12 bz $ 0xa6a6
ram:00a694 91 dec 
ram:00a695 df44 bnz $ 0xa6db
ram:00a697 f6 clrw AX
ram:00a698 bf04c8 movw !0xfc804,AX
ram:00a69b fcafa900 call !!0xa9af
ram:00a69f 34f0c7 movw DE,0xc7f0
ram:00a6a2 f1 clrb A
ram:00a6a3 99 mov [DE],A
ram:00a6a4 ef4b br $ 0xa6f1
ram:00a6a6 f6 clrw AX
ram:00a6a7 bf04c8 movw !0xfc804,AX
ram:00a6aa 5059 mov ,0x59
ram:00a6ac bf02c8 movw !0xfc802,AX
ram:00a6af fc9ea900 call !!0xa99e
ram:00a6b3 fc33a900 call !!0xa933
ram:00a6b7 40f9c7ff cmp !0xfc7f9,0xff
ram:00a6bb df0c bnz $ 0xa6c9
ram:00a6bd 30bf0d movw AX,0xdbf
ram:00a6c0 c1 push AX
ram:00a6c1 300300 movw AX,0x3
ram:00a6c4 fc7e9200 call !!0x927e
ram:00a6c8 c0 pop AX
ram:00a6c9 fc74a900 call !!0xa974
ram:00a6cd 34f0c7 movw DE,0xc7f0
ram:00a6d0 89 mov A,[DE]
ram:00a6d1 5cf0 and A,#0xf0
ram:00a6d3 81 inc 
ram:00a6d4 99 mov [DE],A
ram:00a6d5 89 mov A,[DE]
ram:00a6d6 5c0f and A,#0xf
ram:00a6d8 99 mov [DE],A
ram:00a6d9 ef16 br $ 0xa6f1
ram:00a6db 30d10d movw AX,0xdd1
ram:00a6de c1 push AX
ram:00a6df e6 onew AX
ram:00a6e0 fc7e9200 call !!0x927e
ram:00a6e4 c0 pop AX
ram:00a6e5 ef0a br $ 0xa6f1
ram:00a6e7 30d60d movw AX,0xdd6
ram:00a6ea c1 push AX
ram:00a6eb f6 clrw AX
ram:00a6ec fc7e9200 call !!0x927e
ram:00a6f0 c0 pop AX
ram:00a6f1 eeb8fe br $! 0xa5ac
ram:00a6f4 1004 addw SP,0x4
ram:00a6f6 c6 pop HL
ram:00a6f7 d7 ret
ram:00a6f8 c7 push HL
ram:00a6f9 16 movw HL,AX
ram:00a6fa c6 pop HL
ram:00a6fb d7 ret
ram:00a6fc c7 push HL
ram:00a6fd 16 movw HL,AX
ram:00a6fe 40f7c704 cmp !0xfc7f7,0x4
ram:00a702 dd0f bz $ 0xa713
ram:00a704 40f7c705 cmp !0xfc7f7,0x5
ram:00a708 dd09 bz $ 0xa713
ram:00a70a 300300 movw AX,0x3
ram:00a70d fc25a800 call !!0xa825
ram:00a711 ef08 br $ 0xa71b
ram:00a713 f6 clrw AX
ram:00a714 c1 push AX
ram:00a715 17 movw AX,HL
ram:00a716 fc99aa00 call !!0xaa99
ram:00a71a c0 pop AX
ram:00a71b c6 pop HL
ram:00a71c d7 ret
ram:00a71d c7 push HL
ram:00a71e 16 movw HL,AX
ram:00a71f cff9c7ff mov !0xfc7f9,0xff
ram:00a723 c6 pop HL
ram:00a724 d7 ret
ram:00a725 c7 push HL
ram:00a726 c1 push AX
ram:00a727 c1 push AX
ram:00a728 fbf8ff movw HL,!0xffff8
ram:00a72b cc0101 mov [HL + 0x1],0x1
ram:00a72e 8ff0c7 mov A,!0xfc7f0
ram:00a731 5cf0 and A,#0xf0
ram:00a733 df5e bnz $ 0xa793
ram:00a735 8ff1c7 mov A,!0xfc7f1
ram:00a738 5c0f and A,#0xf
ram:00a73a df57 bnz $ 0xa793
ram:00a73c ac02 movw AX,[HL + 0x2]
ram:00a73e 14 movw DE,AX
ram:00a73f aa08 movw AX,[DE + 0x8]
ram:00a741 449903 cmpw AX,0x399
ram:00a744 de4d bnc $ 0xa793
ram:00a746 f6 clrw AX
ram:00a747 bf04c8 movw !0xfc804,AX
ram:00a74a 8ff0c7 mov A,!0xfc7f0
ram:00a74d 5c0f and A,#0xf
ram:00a74f d1 cmp0 A
ram:00a750 dd0a bz $ 0xa75c
ram:00a752 91 dec 
ram:00a753 dd3e bz $ 0xa793
ram:00a755 91 dec 
ram:00a756 2c02 sub A,#0x2
ram:00a758 dc1c bc $ 0xa776
ram:00a75a ef2d br $ 0xa789
ram:00a75c ac02 movw AX,[HL + 0x2]
ram:00a75e bf00c8 movw !0xfc800,AX
ram:00a761 fc33a900 call !!0xa933
ram:00a765 62 mov A,
ram:00a766 9c01 mov [HL + 0x1],A
ram:00a768 d1 cmp0 A
ram:00a769 df28 bnz $ 0xa793
ram:00a76b 34f0c7 movw DE,0xc7f0
ram:00a76e 89 mov A,[DE]
ram:00a76f 5c0f and A,#0xf
ram:00a771 6c10 or A,#0x10
ram:00a773 99 mov [DE],A
ram:00a774 ef1d br $ 0xa793
ram:00a776 cc0100 mov [HL + 0x1],0x0
ram:00a779 ac02 movw AX,[HL + 0x2]
ram:00a77b bf00c8 movw !0xfc800,AX
ram:00a77e 34f0c7 movw DE,0xc7f0
ram:00a781 89 mov A,[DE]
ram:00a782 5c0f and A,#0xf
ram:00a784 6c20 or A,#0x20
ram:00a786 99 mov [DE],A
ram:00a787 ef0a br $ 0xa793
ram:00a789 30700e movw AX,0xe70
ram:00a78c c1 push AX
ram:00a78d f6 clrw AX
ram:00a78e fc7e9200 call !!0x927e
ram:00a792 c0 pop AX
ram:00a793 8c01 mov A,[HL + 0x1]
ram:00a795 318f sarw AX,0x8
ram:00a797 12 movw BC,AX
ram:00a798 1004 addw SP,0x4
ram:00a79a c6 pop HL
ram:00a79b d7 ret
ram:00a79c c7 push HL
ram:00a79d c1 push AX
ram:00a79e c1 push AX
ram:00a79f fbf8ff movw HL,!0xffff8
ram:00a7a2 8c0a mov A,[HL + 0xa]
ram:00a7a4 d1 cmp0 A
ram:00a7a5 df21 bnz $ 0xa7c8
ram:00a7a7 af00c8 movw AX,!0xfc800
ram:00a7aa 614902 cmpw AX,[HL + 0x2]
ram:00a7ad df19 bnz $ 0xa7c8
ram:00a7af fc9fa800 call !!0xa89f
ram:00a7b3 62 mov A,
ram:00a7b4 9c01 mov [HL + 0x1],A
ram:00a7b6 d1 cmp0 A
ram:00a7b7 df07 bnz $ 0xa7c0
ram:00a7b9 e6 onew AX
ram:00a7ba fc25a800 call !!0xa825
ram:00a7be ef0c br $ 0xa7cc
ram:00a7c0 e6 onew AX
ram:00a7c1 a1 incw AX
ram:00a7c2 fc25a800 call !!0xa825
ram:00a7c6 ef04 br $ 0xa7cc
ram:00a7c8 fc83a900 call !!0xa983
ram:00a7cc ac02 movw AX,[HL + 0x2]
ram:00a7ce fcbea400 call !!0xa4be
ram:00a7d2 1004 addw SP,0x4
ram:00a7d4 c6 pop HL
ram:00a7d5 d7 ret
ram:00a7d6 c7 push HL
ram:00a7d7 c1 push AX
ram:00a7d8 fbf8ff movw HL,!0xffff8
ram:00a7db 8ff1c7 mov A,!0xfc7f1
ram:00a7de 5c0f and A,#0xf
ram:00a7e0 df0c bnz $ 0xa7ee
ram:00a7e2 30e20e movw AX,0xee2
ram:00a7e5 c1 push AX
ram:00a7e6 300500 movw AX,0x5
ram:00a7e9 fc7e9200 call !!0x927e
ram:00a7ed c0 pop AX
ram:00a7ee 8ff1c7 mov A,!0xfc7f1
ram:00a7f1 5c0f and A,#0xf
ram:00a7f3 4c01 cmp A,#0x1
ram:00a7f5 df1f bnz $ 0xa816
ram:00a7f7 40f9c7ff cmp !0xfc7f9,0xff
ram:00a7fb df0c bnz $ 0xa809
ram:00a7fd 30e60e movw AX,0xee6
ram:00a800 c1 push AX
ram:00a801 300400 movw AX,0x4
ram:00a804 fc7e9200 call !!0x927e
ram:00a808 c0 pop AX
ram:00a809 8c08 mov A,[HL + 0x8]
ram:00a80b 318f sarw AX,0x8
ram:00a80d c1 push AX
ram:00a80e 30f2c7 movw AX,0xc7f2
ram:00a811 fc99aa00 call !!0xaa99
ram:00a815 c0 pop AX
ram:00a816 ab movw AX,[HL]
ram:00a817 fcbea400 call !!0xa4be
ram:00a81b 34f1c7 movw DE,0xc7f1
ram:00a81e 89 mov A,[DE]
ram:00a81f 5cf0 and A,#0xf0
ram:00a821 99 mov [DE],A
ram:00a822 c0 pop AX
ram:00a823 c6 pop HL
ram:00a824 d7 ret
ram:00a825 c7 push HL
ram:00a826 16 movw HL,AX
ram:00a827 fc3ee000 call !!0xe03e
ram:00a82b af06c8 movw AX,!0xfc806
ram:00a82e 5cf0 and A,#0xf0
ram:00a830 f0 clrb X
ram:00a831 6168 or A,
ram:00a833 dd0b bz $ 0xa840
ram:00a835 30fe0e movw AX,0xefe
ram:00a838 c1 push AX
ram:00a839 e6 onew AX
ram:00a83a a1 incw AX
ram:00a83b fc7e9200 call !!0x927e
ram:00a83f c0 pop AX
ram:00a840 af06c8 movw AX,!0xfc806
ram:00a843 314d shlw AX,0x4
ram:00a845 bf06c8 movw !0xfc806,AX
ram:00a848 17 movw AX,HL
ram:00a849 6f07c8 or A,!0xfc807
ram:00a84c 08 xch A,X
ram:00a84d 6f06c8 or A,!0xfc806
ram:00a850 08 xch A,X
ram:00a851 bf06c8 movw !0xfc806,AX
ram:00a854 fc62e000 call !!0xe062
ram:00a858 c6 pop HL
ram:00a859 d7 ret
ram:00a85a c7 push HL
ram:00a85b fc3ee000 call !!0xe03e
ram:00a85f fb06c8 movw HL,!0xfc806
ram:00a862 f6 clrw AX
ram:00a863 bf06c8 movw !0xfc806,AX
ram:00a866 fc62e000 call !!0xe062
ram:00a86a 17 movw AX,HL
ram:00a86b 12 movw BC,AX
ram:00a86c c6 pop HL
ram:00a86d d7 ret
ram:00a86e c7 push HL
ram:00a86f c1 push AX
ram:00a870 c1 push AX
ram:00a871 fbf8ff movw HL,!0xffff8
ram:00a874 ac0a movw AX,[HL + 0xa]
ram:00a876 bb movw [HL],AX
ram:00a877 f6 clrw AX
ram:00a878 614900 cmpw AX,[HL + 0x0]
ram:00a87b dd1e bz $ 0xa89b
ram:00a87d 618900 decw [HL + 0x0]
ram:00a880 ab movw AX,[HL]
ram:00a881 610902 addw AX,[HL + 0x2]
ram:00a884 14 movw DE,AX
ram:00a885 89 mov A,[DE]
ram:00a886 73 mov ,A
ram:00a887 ab movw AX,[HL]
ram:00a888 33 xchw AX,BC
ram:00a889 4833c4 mov !0xfc433[BC],A
ram:00a88c ab movw AX,[HL]
ram:00a88d 442000 cmpw AX,0x20
ram:00a890 dee5 bnc $ 0xa877
ram:00a892 89 mov A,[DE]
ram:00a893 73 mov ,A
ram:00a894 ab movw AX,[HL]
ram:00a895 33 xchw AX,BC
ram:00a896 48cbc7 mov !0xfc7cb[BC],A
ram:00a899 efdc br $ 0xa877
ram:00a89b 1004 addw SP,0x4
ram:00a89d c6 pop HL
ram:00a89e d7 ret
ram:00a89f c7 push HL
ram:00a8a0 2008 subw SP,0x8
ram:00a8a2 fbf8ff movw HL,!0xffff8
ram:00a8a5 cc0701 mov [HL + 0x7],0x1
ram:00a8a8 eb00c8 movw DE,!0xfc800
ram:00a8ab aa0a movw AX,[DE + 0xa]
ram:00a8ad bc04 movw [HL + 0x4],AX
ram:00a8af aa08 movw AX,[DE + 0x8]
ram:00a8b1 bc02 movw [HL + 0x2],AX
ram:00a8b3 ac04 movw AX,[HL + 0x4]
ram:00a8b5 14 movw DE,AX
ram:00a8b6 89 mov A,[DE]
ram:00a8b7 9feec7 mov !0xfc7ee,A
ram:00a8ba 8ff0c7 mov A,!0xfc7f0
ram:00a8bd 314a shr A,0x4
ram:00a8bf 91 dec 
ram:00a8c0 dd05 bz $ 0xa8c7
ram:00a8c2 91 dec 
ram:00a8c3 dd11 bz $ 0xa8d6
ram:00a8c5 ef59 br $ 0xa920
ram:00a8c7 ac02 movw AX,[HL + 0x2]
ram:00a8c9 c1 push AX
ram:00a8ca ac04 movw AX,[HL + 0x4]
ram:00a8cc fc6ea800 call !!0xa86e
ram:00a8d0 c0 pop AX
ram:00a8d1 cc0700 mov [HL + 0x7],0x0
ram:00a8d4 ef54 br $ 0xa92a
ram:00a8d6 ac02 movw AX,[HL + 0x2]
ram:00a8d8 442100 cmpw AX,0x21
ram:00a8db dc05 bc $ 0xa8e2
ram:00a8dd 302000 movw AX,0x20
ram:00a8e0 ef02 br $ 0xa8e4
ram:00a8e2 ac02 movw AX,[HL + 0x2]
ram:00a8e4 60 mov A,
ram:00a8e5 9c01 mov [HL + 0x1],A
ram:00a8e7 8c01 mov A,[HL + 0x1]
ram:00a8e9 d1 cmp0 A
ram:00a8ea dd1a bz $ 0xa906
ram:00a8ec 616901 dec [HL + 0x1]
ram:00a8ef 8c01 mov A,[HL + 0x1]
ram:00a8f1 73 mov ,A
ram:00a8f2 09cbc7 mov A,!0xfc7cb[B]
ram:00a8f5 72 mov ,A
ram:00a8f6 8c01 mov A,[HL + 0x1]
ram:00a8f8 318e shrw AX,0x8
ram:00a8fa 610904 addw AX,[HL + 0x4]
ram:00a8fd 14 movw DE,AX
ram:00a8fe 89 mov A,[DE]
ram:00a8ff 6142 cmp ,A
ram:00a901 dde4 bz $ 0xa8e7
ram:00a903 cc0700 mov [HL + 0x7],0x0
ram:00a906 8c07 mov A,[HL + 0x7]
ram:00a908 d1 cmp0 A
ram:00a909 df1f bnz $ 0xa92a
ram:00a90b 8ff0c7 mov A,!0xfc7f0
ram:00a90e 5c0f and A,#0xf
ram:00a910 4c03 cmp A,#0x3
ram:00a912 df16 bnz $ 0xa92a
ram:00a914 ac02 movw AX,[HL + 0x2]
ram:00a916 c1 push AX
ram:00a917 ac04 movw AX,[HL + 0x4]
ram:00a919 fc6ea800 call !!0xa86e
ram:00a91d c0 pop AX
ram:00a91e ef0a br $ 0xa92a
ram:00a920 30590f movw AX,0xf59
ram:00a923 c1 push AX
ram:00a924 f6 clrw AX
ram:00a925 fc7e9200 call !!0x927e
ram:00a929 c0 pop AX
ram:00a92a 8c07 mov A,[HL + 0x7]
ram:00a92c 318e shrw AX,0x8
ram:00a92e 12 movw BC,AX
ram:00a92f 1008 addw SP,0x8
ram:00a931 c6 pop HL
ram:00a932 d7 ret
ram:00a933 c7 push HL
ram:00a934 5601 mov ,0x1
ram:00a936 40f9c7ff cmp !0xfc7f9,0xff
ram:00a93a df32 bnz $ 0xa96e
ram:00a93c eb00c8 movw DE,!0xfc800
ram:00a93f 8a02 mov A,[DE + 0x2]
ram:00a941 9ff4c7 mov !0xfc7f4,A
ram:00a944 eb00c8 movw DE,!0xfc800
ram:00a947 8a04 mov A,[DE + 0x4]
ram:00a949 9ff6c7 mov !0xfc7f6,A
ram:00a94c eb00c8 movw DE,!0xfc800
ram:00a94f aa08 movw AX,[DE + 0x8]
ram:00a951 bffac7 movw !0xfc7fa,AX
ram:00a954 eb00c8 movw DE,!0xfc800
ram:00a957 89 mov A,[DE]
ram:00a958 9ff2c7 mov !0xfc7f2,A
ram:00a95b f5f9c7 clrb !0xfc7f9
ram:00a95e 30f2c7 movw AX,0xc7f2
ram:00a961 fc30aa00 call !!0xaa30
ram:00a965 62 mov A,
ram:00a966 76 mov ,A
ram:00a967 d1 cmp0 A
ram:00a968 61e8 skz
ram:00a96a cff9c7ff _mov !0xfc7f9,0xff
ram:00a96e 66 mov A,
ram:00a96f 318f sarw AX,0x8
ram:00a971 12 movw BC,AX
ram:00a972 c6 pop HL
ram:00a973 d7 ret
ram:00a974 f6 clrw AX
ram:00a975 c1 push AX
ram:00a976 30f2c7 movw AX,0xc7f2
ram:00a979 fc58aa00 call !!0xaa58
ram:00a97d c0 pop AX
ram:00a97e cfefc723 mov !0xfc7ef,0x23
ram:00a982 d7 ret
ram:00a983 8ff0c7 mov A,!0xfc7f0
ram:00a986 5c0f and A,#0xf
ram:00a988 df13 bnz $ 0xa99d
ram:00a98a 300300 movw AX,0x3
ram:00a98d c1 push AX
ram:00a98e 30f2c7 movw AX,0xc7f2
ram:00a991 fc58aa00 call !!0xaa58
ram:00a995 c0 pop AX
ram:00a996 34f0c7 movw DE,0xc7f0
ram:00a999 89 mov A,[DE]
ram:00a99a 5c0f and A,#0xf
ram:00a99c 99 mov [DE],A
ram:00a99d d7 ret
ram:00a99e 300300 movw AX,0x3
ram:00a9a1 c1 push AX
ram:00a9a2 30f2c7 movw AX,0xc7f2
ram:00a9a5 fc99aa00 call !!0xaa99
ram:00a9a9 c0 pop AX
ram:00a9aa cff9c7ff mov !0xfc7f9,0xff
ram:00a9ae d7 ret
ram:00a9af 40f9c7ff cmp !0xfc7f9,0xff
ram:00a9b3 dd2e bz $ 0xa9e3
ram:00a9b5 eb00c8 movw DE,!0xfc800
ram:00a9b8 8ff7c7 mov A,!0xfc7f7
ram:00a9bb 9a05 mov [DE + 0x5],A
ram:00a9bd eb00c8 movw DE,!0xfc800
ram:00a9c0 affec7 movw AX,!0xfc7fe
ram:00a9c3 ba0c movw [DE + 0xc],AX
ram:00a9c5 eb00c8 movw DE,!0xfc800
ram:00a9c8 affac7 movw AX,!0xfc7fa
ram:00a9cb ba08 movw [DE + 0x8],AX
ram:00a9cd af00c8 movw AX,!0xfc800
ram:00a9d0 fce5a300 call !!0xa3e5
ram:00a9d4 af00c8 movw AX,!0xfc800
ram:00a9d7 fce9a300 call !!0xa3e9
ram:00a9db 34f1c7 movw DE,0xc7f1
ram:00a9de 89 mov A,[DE]
ram:00a9df 5cf0 and A,#0xf0
ram:00a9e1 81 inc 
ram:00a9e2 99 mov [DE],A
ram:00a9e3 d7 ret
ram:00a9e4 8feec7 mov A,!0xfc7ee
ram:00a9e7 9fecc7 mov !0xfc7ec,A
ram:00a9ea 8fefc7 mov A,!0xfc7ef
ram:00a9ed 9fedc7 mov !0xfc7ed,A
ram:00a9f0 cfefc721 mov !0xfc7ef,0x21
ram:00a9f4 eb00c8 movw DE,!0xfc800
ram:00a9f7 ca0504 mov [DE + 0x5],0x4
ram:00a9fa eb00c8 movw DE,!0xfc800
ram:00a9fd 30ebc7 movw AX,0xc7eb
ram:00aa00 ba0c movw [DE + 0xc],AX
ram:00aa02 eb00c8 movw DE,!0xfc800
ram:00aa05 300300 movw AX,0x3
ram:00aa08 ba08 movw [DE + 0x8],AX
ram:00aa0a af00c8 movw AX,!0xfc800
ram:00aa0d fce5a300 call !!0xa3e5
ram:00aa11 af00c8 movw AX,!0xfc800
ram:00aa14 fce9a300 call !!0xa3e9
ram:00aa18 34f1c7 movw DE,0xc7f1
ram:00aa1b 89 mov A,[DE]
ram:00aa1c 5cf0 and A,#0xf0
ram:00aa1e 6c02 or A,#0x2
ram:00aa20 99 mov [DE],A
ram:00aa21 d7 ret
ram:00aa22 ec05a500 br !!0xa505
ram:00aa26 ec0da500 br !!0xa50d
ram:00aa30 c7 push HL
ram:00aa31 c1 push AX
ram:00aa32 c1 push AX
ram:00aa33 fbf8ff movw HL,!0xffff8
ram:00aa36 cc0101 mov [HL + 0x1],0x1
ram:00aa39 8f0dc8 mov A,!0xfc80d
ram:00aa3c 310310 bt A.0x0,$ 0xaa4e
ram:00aa3f 71000dc8 set1 !0xfc80d.0x0
ram:00aa43 71000cc8 set1 !0xfc80c.0x0
ram:00aa47 ac02 movw AX,[HL + 0x2]
ram:00aa49 bf0ac8 movw !0xfc80a,AX
ram:00aa4c cc0100 mov [HL + 0x1],0x0
ram:00aa4f 8c01 mov A,[HL + 0x1]
ram:00aa51 318f sarw AX,0x8
ram:00aa53 12 movw BC,AX
ram:00aa54 1004 addw SP,0x4
ram:00aa56 c6 pop HL
ram:00aa57 d7 ret
ram:00aa58 c7 push HL
ram:00aa59 c1 push AX
ram:00aa5a c1 push AX
ram:00aa5b fbf8ff movw HL,!0xffff8
ram:00aa5e 71080cc8 clr1 !0xfc80c.0x0
ram:00aa62 8c0a mov A,[HL + 0xa]
ram:00aa64 d1 cmp0 A
ram:00aa65 df2a bnz $ 0xaa91
ram:00aa67 af0ac8 movw AX,!0xfc80a
ram:00aa6a 614902 cmpw AX,[HL + 0x2]
ram:00aa6d df22 bnz $ 0xaa91
ram:00aa6f f6 clrw AX
ram:00aa70 bb movw [HL],AX
ram:00aa71 614900 cmpw AX,[HL + 0x0]
ram:00aa74 df1b bnz $ 0xaa91
ram:00aa76 ac02 movw AX,[HL + 0x2]
ram:00aa78 14 movw DE,AX
ram:00aa79 f7 clrw BC
ram:00aa7a 5004 mov ,0x4
ram:00aa7c 89 mov A,[DE]
ram:00aa7d a5 incw DE
ram:00aa7e 4824c8 mov !0xfc824[BC],A
ram:00aa81 a3 incw BC
ram:00aa82 90 dec 
ram:00aa83 dff7 bnz $ 0xaa7c
ram:00aa85 ac02 movw AX,[HL + 0x2]
ram:00aa87 fcf8a600 call !!0xa6f8
ram:00aa8b 71100cc8 set1 !0xfc80c.0x1
ram:00aa8f ef04 br $ 0xaa95
ram:00aa91 fcf6a400 call !!0xa4f6
ram:00aa95 1004 addw SP,0x4
ram:00aa97 c6 pop HL
ram:00aa98 d7 ret
ram:00aa99 c7 push HL
ram:00aa9a c1 push AX
ram:00aa9b fbf8ff movw HL,!0xffff8
ram:00aa9e 8c08 mov A,[HL + 0x8]
ram:00aaa0 d1 cmp0 A
ram:00aaa1 ab movw AX,[HL]
ram:00aaa2 14 movw DE,AX
ram:00aaa3 8a05 mov A,[DE + 0x5]
ram:00aaa5 91 dec 
ram:00aaa6 2c03 sub A,#0x3
ram:00aaa8 dc03 bc $ 0xaaad
ram:00aaaa d1 cmp0 A
ram:00aaab ef08 br $ 0xaab5
ram:00aaad 8c08 mov A,[HL + 0x8]
ram:00aaaf 318f sarw AX,0x8
ram:00aab1 fc86b300 call !!0xb386
ram:00aab5 ab movw AX,[HL]
ram:00aab6 14 movw DE,AX
ram:00aab7 ca0500 mov [DE + 0x5],0x0
ram:00aaba c0 pop AX
ram:00aabb c6 pop HL
ram:00aabc d7 ret
ram:00aabd eb0ac8 movw DE,!0xfc80a
ram:00aac0 3030c4 movw AX,0xc430
ram:00aac3 ba0c movw [DE + 0xc],AX
ram:00aac5 eb0ac8 movw DE,!0xfc80a
ram:00aac8 300300 movw AX,0x3
ram:00aacb ba08 movw [DE + 0x8],AX
ram:00aacd af0ac8 movw AX,!0xfc80a
ram:00aad0 fcfca600 call !!0xa6fc
ram:00aad4 305900 movw AX,0x59
ram:00aad7 bf0ec8 movw !0xfc80e,AX
ram:00aada d7 ret
ram:00aadf f6 clrw AX
ram:00aae0 bf0ec8 movw !0xfc80e,AX
ram:00aae3 d7 ret
ram:00aae4 f6 clrw AX
ram:00aae5 bf12c8 movw !0xfc812,AX
ram:00aae8 bf10c8 movw !0xfc810,AX
ram:00aaeb d7 ret
ram:00aaec ecf0aa00 br !!0xaaf0
ram:00aaf0 3414c8 movw DE,0xc814
ram:00aaf3 5151 mov ,0x51
ram:00aaf5 99 mov [DE],A
ram:00aaf6 d7 ret
ram:00aaf7 8f14c8 mov A,!0xfc814
ram:00aafa 5c0f and A,#0xf
ram:00aafc 318e shrw AX,0x8
ram:00aafe 12 movw BC,AX
ram:00aaff d7 ret
ram:00ab00 c7 push HL
ram:00ab01 16 movw HL,AX
ram:00ab02 f6 clrw AX
ram:00ab03 47 cmpw AX,HL
ram:00ab04 df0c bnz $ 0xab12
ram:00ab06 30ee11 movw AX,0x11ee
ram:00ab09 c1 push AX
ram:00ab0a 301300 movw AX,0x13
ram:00ab0d fc7e9200 call !!0x927e
ram:00ab11 c0 pop AX
ram:00ab12 8f14c8 mov A,!0xfc814
ram:00ab15 5c0f and A,#0xf
ram:00ab17 318e shrw AX,0x8
ram:00ab19 c1 push AX
ram:00ab1a 17 movw AX,HL
ram:00ab1b fcc5ac00 call !!0xacc5
ram:00ab1f c0 pop AX
ram:00ab20 8f14c8 mov A,!0xfc814
ram:00ab23 5c0f and A,#0xf
ram:00ab25 318e shrw AX,0x8
ram:00ab27 c1 push AX
ram:00ab28 17 movw AX,HL
ram:00ab29 fc889200 call !!0x9288
ram:00ab2d c0 pop AX
ram:00ab2e 66 mov A,
ram:00ab2f 5c0f and A,#0xf
ram:00ab31 3414c8 movw DE,0xc814
ram:00ab34 70 mov ,A
ram:00ab35 89 mov A,[DE]
ram:00ab36 5cf0 and A,#0xf0
ram:00ab38 6168 or A,
ram:00ab3a 99 mov [DE],A
ram:00ab3b c6 pop HL
ram:00ab3c d7 ret
ram:00ab44 c7 push HL
ram:00ab45 16 movw HL,AX
ram:00ab46 f6 clrw AX
ram:00ab47 47 cmpw AX,HL
ram:00ab48 df0c bnz $ 0xab56
ram:00ab4a 30fe11 movw AX,0x11fe
ram:00ab4d c1 push AX
ram:00ab4e 301300 movw AX,0x13
ram:00ab51 fc7e9200 call !!0x927e
ram:00ab55 c0 pop AX
ram:00ab56 8f14c8 mov A,!0xfc814
ram:00ab59 31ee shrw AX,0xe
ram:00ab5b c1 push AX
ram:00ab5c 17 movw AX,HL
ram:00ab5d fca69200 call !!0x92a6
ram:00ab61 c0 pop AX
ram:00ab62 66 mov A,
ram:00ab63 3169 shl A,0x6
ram:00ab65 3414c8 movw DE,0xc814
ram:00ab68 70 mov ,A
ram:00ab69 89 mov A,[DE]
ram:00ab6a 5c3f and A,#0x3f
ram:00ab6c 6168 or A,
ram:00ab6e 99 mov [DE],A
ram:00ab6f c6 pop HL
ram:00ab70 d7 ret
ram:00ab7a c7 push HL
ram:00ab7b 16 movw HL,AX
ram:00ab7c f6 clrw AX
ram:00ab7d 47 cmpw AX,HL
ram:00ab7e df0c bnz $ 0xab8c
ram:00ab80 300e12 movw AX,0x120e
ram:00ab83 c1 push AX
ram:00ab84 301300 movw AX,0x13
ram:00ab87 fc7e9200 call !!0x927e
ram:00ab8b c0 pop AX
ram:00ab8c 8f14c8 mov A,!0xfc814
ram:00ab8f 3129 shl A,0x2
ram:00ab91 31ee shrw AX,0xe
ram:00ab93 c1 push AX
ram:00ab94 17 movw AX,HL
ram:00ab95 fcae9200 call !!0x92ae
ram:00ab99 c0 pop AX
ram:00ab9a 66 mov A,
ram:00ab9b 3149 shl A,0x4
ram:00ab9d 5c30 and A,#0x30
ram:00ab9f 3414c8 movw DE,0xc814
ram:00aba2 70 mov ,A
ram:00aba3 89 mov A,[DE]
ram:00aba4 5ccf and A,#0xcf
ram:00aba6 6168 or A,
ram:00aba8 99 mov [DE],A
ram:00aba9 c6 pop HL
ram:00abaa d7 ret
ram:00abab c7 push HL
ram:00abac c3 push BC
ram:00abad c1 push AX
ram:00abae fbf8ff movw HL,!0xffff8
ram:00abb1 ab movw AX,[HL]
ram:00abb2 14 movw DE,AX
ram:00abb3 8c02 mov A,[HL + 0x2]
ram:00abb5 9efd mov ES,A
ram:00abb7 1189 mov A,ES:[DE]
ram:00abb9 5c0f and A,#0xf
ram:00abbb 70 mov ,A
ram:00abbc 8f14c8 mov A,!0xfc814
ram:00abbf 5c0f and A,#0xf
ram:00abc1 6150 and ,A
ram:00abc3 d0 cmp0 X
ram:00abc4 df05 bnz $ 0xabcb
ram:00abc6 327e00 movw BC,0x7e
ram:00abc9 ef39 br $ 0xac04
ram:00abcb ab movw AX,[HL]
ram:00abcc 14 movw DE,AX
ram:00abcd 8c02 mov A,[HL + 0x2]
ram:00abcf 9efd mov ES,A
ram:00abd1 1189 mov A,ES:[DE]
ram:00abd3 316a shr A,0x6
ram:00abd5 70 mov ,A
ram:00abd6 8f14c8 mov A,!0xfc814
ram:00abd9 316a shr A,0x6
ram:00abdb 6150 and ,A
ram:00abdd d0 cmp0 X
ram:00abde df05 bnz $ 0xabe5
ram:00abe0 323300 movw BC,0x33
ram:00abe3 ef1f br $ 0xac04
ram:00abe5 ab movw AX,[HL]
ram:00abe6 14 movw DE,AX
ram:00abe7 8c02 mov A,[HL + 0x2]
ram:00abe9 9efd mov ES,A
ram:00abeb 1189 mov A,ES:[DE]
ram:00abed 3129 shl A,0x2
ram:00abef 316a shr A,0x6
ram:00abf1 70 mov ,A
ram:00abf2 8f14c8 mov A,!0xfc814
ram:00abf5 3129 shl A,0x2
ram:00abf7 316a shr A,0x6
ram:00abf9 6150 and ,A
ram:00abfb d0 cmp0 X
ram:00abfc df05 bnz $ 0xac03
ram:00abfe 322200 movw BC,0x22
ram:00ac01 ef01 br $ 0xac04
ram:00ac03 f7 clrw BC
ram:00ac04 1004 addw SP,0x4
ram:00ac06 c6 pop HL
ram:00ac07 d7 ret
ram:00ac08 c7 push HL
ram:00ac09 c1 push AX
ram:00ac0a 2004 subw SP,0x4
ram:00ac0c fbf8ff movw HL,!0xffff8
ram:00ac0f ac04 movw AX,[HL + 0x4]
ram:00ac11 312d shlw AX,0x2
ram:00ac13 12 movw BC,AX
ram:00ac14 01 addw AX,AX
ram:00ac15 03 addw AX,BC
ram:00ac16 04fc65 addw AX,0x65fc
ram:00ac19 14 movw DE,AX
ram:00ac1a 4100 mov ES,0x0
ram:00ac1c 118a06 mov A,ES:[DE + 0x6]
ram:00ac1f 4c02 cmp A,#0x2
ram:00ac21 61f8 sknz
ram:00ac23 ee9b00 _br $! 0xacc1
ram:00ac26 13 movw AX,BC
ram:00ac27 01 addw AX,AX
ram:00ac28 03 addw AX,BC
ram:00ac29 12 movw BC,AX
ram:00ac2a 11490266 mov A,ES:!0xf6602[BC]
ram:00ac2e f0 clrb X
ram:00ac2f 316e shrw AX,0x6
ram:00ac31 043a65 addw AX,0x653a
ram:00ac34 bb movw [HL],AX
ram:00ac35 5100 mov ,0x0
ram:00ac37 9c02 mov [HL + 0x2],A
ram:00ac39 fc3ee000 call !!0xe03e
ram:00ac3d ab movw AX,[HL]
ram:00ac3e 14 movw DE,AX
ram:00ac3f 8c02 mov A,[HL + 0x2]
ram:00ac41 9efd mov ES,A
ram:00ac43 1189 mov A,ES:[DE]
ram:00ac45 5c0f and A,#0xf
ram:00ac47 70 mov ,A
ram:00ac48 8f14c8 mov A,!0xfc814
ram:00ac4b 5c0f and A,#0xf
ram:00ac4d 6158 and A,
ram:00ac4f d1 cmp0 A
ram:00ac50 dd15 bz $ 0xac67
ram:00ac52 8c02 mov A,[HL + 0x2]
ram:00ac54 9dd4 mov 0xffdf4,A
ram:00ac56 ab movw AX,[HL]
ram:00ac57 a1 incw AX
ram:00ac58 a1 incw AX
ram:00ac59 14 movw DE,AX
ram:00ac5a 61b8d4 mov ES,0xffdf4
ram:00ac5d 1189 mov A,ES:[DE]
ram:00ac5f 5c0f and A,#0xf
ram:00ac61 318e shrw AX,0x8
ram:00ac63 fc00ab00 call !!0xab00
ram:00ac67 ab movw AX,[HL]
ram:00ac68 14 movw DE,AX
ram:00ac69 8c02 mov A,[HL + 0x2]
ram:00ac6b 9efd mov ES,A
ram:00ac6d 1189 mov A,ES:[DE]
ram:00ac6f 316a shr A,0x6
ram:00ac71 70 mov ,A
ram:00ac72 8f14c8 mov A,!0xfc814
ram:00ac75 316a shr A,0x6
ram:00ac77 6158 and A,
ram:00ac79 d1 cmp0 A
ram:00ac7a dd13 bz $ 0xac8f
ram:00ac7c 8c02 mov A,[HL + 0x2]
ram:00ac7e 9dd4 mov 0xffdf4,A
ram:00ac80 ab movw AX,[HL]
ram:00ac81 a1 incw AX
ram:00ac82 a1 incw AX
ram:00ac83 14 movw DE,AX
ram:00ac84 61b8d4 mov ES,0xffdf4
ram:00ac87 1189 mov A,ES:[DE]
ram:00ac89 31ee shrw AX,0xe
ram:00ac8b fc44ab00 call !!0xab44
ram:00ac8f ab movw AX,[HL]
ram:00ac90 14 movw DE,AX
ram:00ac91 8c02 mov A,[HL + 0x2]
ram:00ac93 9efd mov ES,A
ram:00ac95 1189 mov A,ES:[DE]
ram:00ac97 3129 shl A,0x2
ram:00ac99 316a shr A,0x6
ram:00ac9b 70 mov ,A
ram:00ac9c 8f14c8 mov A,!0xfc814
ram:00ac9f 3129 shl A,0x2
ram:00aca1 316a shr A,0x6
ram:00aca3 6158 and A,
ram:00aca5 d1 cmp0 A
ram:00aca6 dd15 bz $ 0xacbd
ram:00aca8 8c02 mov A,[HL + 0x2]
ram:00acaa 9dd4 mov 0xffdf4,A
ram:00acac ab movw AX,[HL]
ram:00acad a1 incw AX
ram:00acae a1 incw AX
ram:00acaf 14 movw DE,AX
ram:00acb0 61b8d4 mov ES,0xffdf4
ram:00acb3 1189 mov A,ES:[DE]
ram:00acb5 3129 shl A,0x2
ram:00acb7 31ee shrw AX,0xe
ram:00acb9 fc7aab00 call !!0xab7a
ram:00acbd fc62e000 call !!0xe062
ram:00acc1 1006 addw SP,0x6
ram:00acc3 c6 pop HL
ram:00acc4 d7 ret
ram:00acc5 c7 push HL
ram:00acc6 c1 push AX
ram:00acc7 fbf8ff movw HL,!0xffff8
ram:00acca e6 onew AX
ram:00accb 614908 cmpw AX,[HL + 0x8]
ram:00acce df0d bnz $ 0xacdd
ram:00acd0 614900 cmpw AX,[HL + 0x0]
ram:00acd3 dd12 bz $ 0xace7
ram:00acd5 30f401 movw AX,0x1f4
ram:00acd8 bf10c8 movw !0xfc810,AX
ram:00acdb ef0a br $ 0xace7
ram:00acdd e6 onew AX
ram:00acde 614900 cmpw AX,[HL + 0x0]
ram:00ace1 df04 bnz $ 0xace7
ram:00ace3 f6 clrw AX
ram:00ace4 bf10c8 movw !0xfc810,AX
ram:00ace7 c0 pop AX
ram:00ace8 c6 pop HL
ram:00ace9 d7 ret
ram:00ae16 c7 push HL
ram:00ae17 c3 push BC
ram:00ae18 c1 push AX
ram:00ae19 fbf8ff movw HL,!0xffff8
ram:00ae1c ab movw AX,[HL]
ram:00ae1d bf2ac8 movw !0xfc82a,AX
ram:00ae20 8c02 mov A,[HL + 0x2]
ram:00ae22 9f2cc8 mov !0xfc82c,A
ram:00ae25 1004 addw SP,0x4
ram:00ae27 c6 pop HL
ram:00ae28 d7 ret
ram:00ae36 c7 push HL
ram:00ae37 c3 push BC
ram:00ae38 c1 push AX
ram:00ae39 fbf8ff movw HL,!0xffff8
ram:00ae3c ab movw AX,[HL]
ram:00ae3d 14 movw DE,AX
ram:00ae3e 8c02 mov A,[HL + 0x2]
ram:00ae40 9efd mov ES,A
ram:00ae42 118a02 mov A,ES:[DE + 0x2]
ram:00ae45 31550b bf A.0x5,$ 0xae52
ram:00ae48 8c02 mov A,[HL + 0x2]
ram:00ae4a 9efd mov ES,A
ram:00ae4c 118a01 mov A,ES:[DE + 0x1]
ram:00ae4f 5c0f and A,#0xf
ram:00ae51 ef18 br $ 0xae6b
ram:00ae53 ab movw AX,[HL]
ram:00ae54 14 movw DE,AX
ram:00ae55 8c02 mov A,[HL + 0x2]
ram:00ae57 9efd mov ES,A
ram:00ae59 118a01 mov A,ES:[DE + 0x1]
ram:00ae5c 5c0f and A,#0xf
ram:00ae5e 72 mov ,A
ram:00ae5f 8c02 mov A,[HL + 0x2]
ram:00ae61 9efd mov ES,A
ram:00ae63 118a01 mov A,ES:[DE + 0x1]
ram:00ae66 314a shr A,0x4
ram:00ae68 6102 add ,A
ram:00ae6a 62 mov A,
ram:00ae6b 318e shrw AX,0x8
ram:00ae6d 12 movw BC,AX
ram:00ae6e 1004 addw SP,0x4
ram:00ae70 c6 pop HL
ram:00ae71 d7 ret
ram:00ae72 c7 push HL
ram:00ae73 c3 push BC
ram:00ae74 c1 push AX
ram:00ae75 c1 push AX
ram:00ae76 fbf8ff movw HL,!0xffff8
ram:00ae79 f6 clrw AX
ram:00ae7a bb movw [HL],AX
ram:00ae7b ac02 movw AX,[HL + 0x2]
ram:00ae7d 14 movw DE,AX
ram:00ae7e 8c04 mov A,[HL + 0x4]
ram:00ae80 9efd mov ES,A
ram:00ae82 118a02 mov A,ES:[DE + 0x2]
ram:00ae85 31530c bt A.0x5,$ 0xae93
ram:00ae88 8c04 mov A,[HL + 0x4]
ram:00ae8a 9efd mov ES,A
ram:00ae8c 118a01 mov A,ES:[DE + 0x1]
ram:00ae8f 5c0f and A,#0xf
ram:00ae91 318e shrw AX,0x8
ram:00ae93 bb movw [HL],AX
ram:00ae94 ac0c movw AX,[HL + 0xc]
ram:00ae96 c1 push AX
ram:00ae97 8c04 mov A,[HL + 0x4]
ram:00ae99 72 mov ,A
ram:00ae9a f3 clrb B
ram:00ae9b ac02 movw AX,[HL + 0x2]
ram:00ae9d fcb6ae00 call !!0xaeb6
ram:00aea1 c0 pop AX
ram:00aea2 64 mov A,
ram:00aea3 9dd5 mov 0xffdf5,A
ram:00aea5 ab movw AX,[HL]
ram:00aea6 03 addw AX,BC
ram:00aea7 12 movw BC,AX
ram:00aea8 8dd5 mov A,0xffdf5
ram:00aeaa 9dd4 mov 0xffdf4,A
ram:00aeac 13 movw AX,BC
ram:00aead f8d4 mov C,0xffdf4
ram:00aeaf f3 clrb B
ram:00aeb0 33 xchw AX,BC
ram:00aeb1 35 xchw AX,DE
ram:00aeb2 1006 addw SP,0x6
ram:00aeb4 c6 pop HL
ram:00aeb5 d7 ret
ram:00aeb6 c7 push HL
ram:00aeb7 c3 push BC
ram:00aeb8 c1 push AX
ram:00aeb9 c1 push AX
ram:00aeba fbf8ff movw HL,!0xffff8
ram:00aebd 8c04 mov A,[HL + 0x4]
ram:00aebf 72 mov ,A
ram:00aec0 f3 clrb B
ram:00aec1 ac02 movw AX,[HL + 0x2]
ram:00aec3 fc36ae00 call !!0xae36
ram:00aec7 13 movw AX,BC
ram:00aec8 bb movw [HL],AX
ram:00aec9 ac02 movw AX,[HL + 0x2]
ram:00aecb 14 movw DE,AX
ram:00aecc 8c04 mov A,[HL + 0x4]
ram:00aece 9efd mov ES,A
ram:00aed0 118a08 mov A,ES:[DE + 0x8]
ram:00aed3 72 mov ,A
ram:00aed4 8c0c mov A,[HL + 0xc]
ram:00aed6 612a sub A,
ram:00aed8 70 mov ,A
ram:00aed9 8c0d mov A,[HL + 0xd]
ram:00aedb 3c00 subc A,#0x0
ram:00aedd bdd8 movw 0xffdf8,AX
ram:00aedf ab movw AX,[HL]
ram:00aee0 fd7304 call !0xf0473
ram:00aee3 bb movw [HL],AX
ram:00aee4 ac02 movw AX,[HL + 0x2]
ram:00aee6 14 movw DE,AX
ram:00aee7 8c04 mov A,[HL + 0x4]
ram:00aee9 9efd mov ES,A
ram:00aeeb 118a09 mov A,ES:[DE + 0x9]
ram:00aeee 72 mov ,A
ram:00aeef 8b mov A,[HL]
ram:00aef0 610a add A,
ram:00aef2 70 mov ,A
ram:00aef3 8c01 mov A,[HL + 0x1]
ram:00aef5 1c00 addc A,#0x0
ram:00aef7 040c68 addw AX,0x680c
ram:00aefa 5200 mov ,0x0
ram:00aefc f3 clrb B
ram:00aefd 33 xchw AX,BC
ram:00aefe 35 xchw AX,DE
ram:00aeff 1006 addw SP,0x6
ram:00af01 c6 pop HL
ram:00af02 d7 ret
ram:00af03 c7 push HL
ram:00af04 c1 push AX
ram:00af05 200c subw SP,0xc
ram:00af07 fbf8ff movw HL,!0xffff8
ram:00af0a 8c16 mov A,[HL + 0x16]
ram:00af0c 72 mov ,A
ram:00af0d f3 clrb B
ram:00af0e ac14 movw AX,[HL + 0x14]
ram:00af10 fc36ae00 call !!0xae36
ram:00af14 13 movw AX,BC
ram:00af15 bc02 movw [HL + 0x2],AX
ram:00af17 302c00 movw AX,0x2c
ram:00af1a bc08 movw [HL + 0x8],AX
ram:00af1c ac18 movw AX,[HL + 0x18]
ram:00af1e 14 movw DE,AX
ram:00af1f f6 clrw AX
ram:00af20 b9 movw [DE],AX
ram:00af21 bc06 movw [HL + 0x6],AX
ram:00af23 ac14 movw AX,[HL + 0x14]
ram:00af25 14 movw DE,AX
ram:00af26 8c16 mov A,[HL + 0x16]
ram:00af28 9efd mov ES,A
ram:00af2a 118a09 mov A,ES:[DE + 0x9]
ram:00af2d 318e shrw AX,0x8
ram:00af2f bc0a movw [HL + 0xa],AX
ram:00af31 8c16 mov A,[HL + 0x16]
ram:00af33 9dd4 mov 0xffdf4,A
ram:00af35 ac14 movw AX,[HL + 0x14]
ram:00af37 040a00 addw AX,0xa
ram:00af3a 14 movw DE,AX
ram:00af3b 61b8d4 mov ES,0xffdf4
ram:00af3e 118a09 mov A,ES:[DE + 0x9]
ram:00af41 318e shrw AX,0x8
ram:00af43 12 movw BC,AX
ram:00af44 ac0a movw AX,[HL + 0xa]
ram:00af46 43 cmpw AX,BC
ram:00af47 61c8 skc
ram:00af49 ee9100 _br $! 0xafdd
ram:00af4c f6 clrw AX
ram:00af4d bc04 movw [HL + 0x4],AX
ram:00af4f ac04 movw AX,[HL + 0x4]
ram:00af51 61090c addw AX,[HL + 0xc]
ram:00af54 14 movw DE,AX
ram:00af55 89 mov A,[DE]
ram:00af56 72 mov ,A
ram:00af57 ac0a movw AX,[HL + 0xa]
ram:00af59 610904 addw AX,[HL + 0x4]
ram:00af5c 040c68 addw AX,0x680c
ram:00af5f 14 movw DE,AX
ram:00af60 4100 mov ES,0x0
ram:00af62 1189 mov A,ES:[DE]
ram:00af64 6142 cmp ,A
ram:00af66 df03 bnz $ 0xaf6b
ram:00af68 e6 onew AX
ram:00af69 ef01 br $ 0xaf6c
ram:00af6b f6 clrw AX
ram:00af6c bb movw [HL],AX
ram:00af6d 617904 incw [HL + 0x4]
ram:00af70 ac14 movw AX,[HL + 0x14]
ram:00af72 14 movw DE,AX
ram:00af73 8c16 mov A,[HL + 0x16]
ram:00af75 9efd mov ES,A
ram:00af77 118a01 mov A,ES:[DE + 0x1]
ram:00af7a 5c0f and A,#0xf
ram:00af7c 318e shrw AX,0x8
ram:00af7e 12 movw BC,AX
ram:00af7f ac04 movw AX,[HL + 0x4]
ram:00af81 43 cmpw AX,BC
ram:00af82 de06 bnc $ 0xaf8a
ram:00af84 f6 clrw AX
ram:00af85 614900 cmpw AX,[HL + 0x0]
ram:00af88 dfc5 bnz $ 0xaf4f
ram:00af8a f6 clrw AX
ram:00af8b 614900 cmpw AX,[HL + 0x0]
ram:00af8e dd18 bz $ 0xafa8
ram:00af90 ac14 movw AX,[HL + 0x14]
ram:00af92 14 movw DE,AX
ram:00af93 8c16 mov A,[HL + 0x16]
ram:00af95 9efd mov ES,A
ram:00af97 118a08 mov A,ES:[DE + 0x8]
ram:00af9a 72 mov ,A
ram:00af9b 8c06 mov A,[HL + 0x6]
ram:00af9d 610a add A,
ram:00af9f 70 mov ,A
ram:00afa0 8c07 mov A,[HL + 0x7]
ram:00afa2 1c00 addc A,#0x0
ram:00afa4 bc08 movw [HL + 0x8],AX
ram:00afa6 ef35 br $ 0xafdd
ram:00afa8 618904 decw [HL + 0x4]
ram:00afab ac18 movw AX,[HL + 0x18]
ram:00afad 14 movw DE,AX
ram:00afae a9 movw AX,[DE]
ram:00afaf 614904 cmpw AX,[HL + 0x4]
ram:00afb2 de03 bnc $ 0xafb7
ram:00afb4 ac04 movw AX,[HL + 0x4]
ram:00afb6 b9 movw [DE],AX
ram:00afb7 ac04 movw AX,[HL + 0x4]
ram:00afb9 61090c addw AX,[HL + 0xc]
ram:00afbc 14 movw DE,AX
ram:00afbd 89 mov A,[DE]
ram:00afbe 72 mov ,A
ram:00afbf ac0a movw AX,[HL + 0xa]
ram:00afc1 610904 addw AX,[HL + 0x4]
ram:00afc4 040c68 addw AX,0x680c
ram:00afc7 14 movw DE,AX
ram:00afc8 4100 mov ES,0x0
ram:00afca 1189 mov A,ES:[DE]
ram:00afcc 6142 cmp ,A
ram:00afce dc0d bc $ 0xafdd
ram:00afd0 617906 incw [HL + 0x6]
ram:00afd3 ac0a movw AX,[HL + 0xa]
ram:00afd5 610902 addw AX,[HL + 0x2]
ram:00afd8 bc0a movw [HL + 0xa],AX
ram:00afda ee54ff br $! 0xaf31
ram:00afdd ac18 movw AX,[HL + 0x18]
ram:00afdf 14 movw DE,AX
ram:00afe0 89 mov A,[DE]
ram:00afe1 72 mov ,A
ram:00afe2 e6 onew AX
ram:00afe3 a1 incw AX
ram:00afe4 d2 cmp0 C
ram:00afe5 dd04 bz $ 0xafeb
ram:00afe7 01 addw AX,AX
ram:00afe8 92 dec 
ram:00afe9 dffc bnz $ 0xafe7
ram:00afeb 08 xch A,X
ram:00afec 72 mov ,A
ram:00afed 08 xch A,X
ram:00afee ac18 movw AX,[HL + 0x18]
ram:00aff0 14 movw DE,AX
ram:00aff1 f3 clrb B
ram:00aff2 13 movw AX,BC
ram:00aff3 b9 movw [DE],AX
ram:00aff4 ac08 movw AX,[HL + 0x8]
ram:00aff6 12 movw BC,AX
ram:00aff7 100e addw SP,0xe
ram:00aff9 c6 pop HL
ram:00affa d7 ret
ram:00affb c7 push HL
ram:00affc c1 push AX
ram:00affd 2004 subw SP,0x4
ram:00afff fbf8ff movw HL,!0xffff8
ram:00b002 cc030b mov [HL + 0x3],0xb
ram:00b005 f6 clrw AX
ram:00b006 bb movw [HL],AX
ram:00b007 8c04 mov A,[HL + 0x4]
ram:00b009 5c40 and A,#0x40
ram:00b00b d1 cmp0 A
ram:00b00c df22 bnz $ 0xb030
ram:00b00e 8c04 mov A,[HL + 0x4]
ram:00b010 4c3f cmp A,#0x3f
ram:00b012 de1c bnc $ 0xb030
ram:00b014 8c04 mov A,[HL + 0x4]
ram:00b016 5c80 and A,#0x80
ram:00b018 d1 cmp0 A
ram:00b019 dd04 bz $ 0xb01f
ram:00b01b 304000 movw AX,0x40
ram:00b01e bb movw [HL],AX
ram:00b01f 8c04 mov A,[HL + 0x4]
ram:00b021 318e shrw AX,0x8
ram:00b023 612900 subw AX,[HL + 0x0]
ram:00b026 044265 addw AX,0x6542
ram:00b029 14 movw DE,AX
ram:00b02a 4100 mov ES,0x0
ram:00b02c 1189 mov A,ES:[DE]
ram:00b02e 9c03 mov [HL + 0x3],A
ram:00b030 8c03 mov A,[HL + 0x3]
ram:00b032 318e shrw AX,0x8
ram:00b034 12 movw BC,AX
ram:00b035 1006 addw SP,0x6
ram:00b037 c6 pop HL
ram:00b038 d7 ret
ram:00b039 f6 clrw AX
ram:00b03a bf2ac8 movw !0xfc82a,AX
ram:00b03d f52cc8 clrb !0xfc82c
ram:00b040 d7 ret
ram:00b041 c7 push HL
ram:00b042 200e subw SP,0xe
ram:00b044 fbf8ff movw HL,!0xffff8
ram:00b047 eb0ac8 movw DE,!0xfc80a
ram:00b04a aa0a movw AX,[DE + 0xa]
ram:00b04c bc0c movw [HL + 0xc],AX
ram:00b04e 713809c8 clr1 !0xfc809.0x3
ram:00b052 3422c8 movw DE,0xc822
ram:00b055 89 mov A,[DE]
ram:00b056 5cf3 and A,#0xf3
ram:00b058 6c04 or A,#0x4
ram:00b05a 99 mov [DE],A
ram:00b05b cf0cc804 mov !0xfc80c,0x4
ram:00b05f ac0c movw AX,[HL + 0xc]
ram:00b061 14 movw DE,AX
ram:00b062 89 mov A,[DE]
ram:00b063 318e shrw AX,0x8
ram:00b065 fcfbaf00 call !!0xaffb
ram:00b069 62 mov A,
ram:00b06a 9f18c8 mov !0xfc818,A
ram:00b06d 4018c80b cmp !0xfc818,0xb
ram:00b071 61c8 skc
ram:00b073 eef101 _br $! 0xb267
ram:00b076 8f18c8 mov A,!0xfc818
ram:00b079 500a mov ,0xa
ram:00b07b d6 mulu X
ram:00b07c 048265 addw AX,0x6582
ram:00b07f bc08 movw [HL + 0x8],AX
ram:00b081 5100 mov ,0x0
ram:00b083 9c0a mov [HL + 0xa],A
ram:00b085 9dd4 mov 0xffdf4,A
ram:00b087 ac08 movw AX,[HL + 0x8]
ram:00b089 14 movw DE,AX
ram:00b08a 61b8d4 mov ES,0xffdf4
ram:00b08d 118a02 mov A,ES:[DE + 0x2]
ram:00b090 5c0c and A,#0xc
ram:00b092 3422c8 movw DE,0xc822
ram:00b095 70 mov ,A
ram:00b096 89 mov A,[DE]
ram:00b097 5cf3 and A,#0xf3
ram:00b099 6168 or A,
ram:00b09b 99 mov [DE],A
ram:00b09c ac08 movw AX,[HL + 0x8]
ram:00b09e 14 movw DE,AX
ram:00b09f 8c0a mov A,[HL + 0xa]
ram:00b0a1 9efd mov ES,A
ram:00b0a3 118a04 mov A,ES:[DE + 0x4]
ram:00b0a6 5c0f and A,#0xf
ram:00b0a8 70 mov ,A
ram:00b0a9 8f14c8 mov A,!0xfc814
ram:00b0ac 5c0f and A,#0xf
ram:00b0ae 6150 and ,A
ram:00b0b0 d0 cmp0 X
ram:00b0b1 61f8 sknz
ram:00b0b3 eeab01 _br $! 0xb261
ram:00b0b6 8c0a mov A,[HL + 0xa]
ram:00b0b8 9efd mov ES,A
ram:00b0ba 118a07 mov A,ES:[DE + 0x7]
ram:00b0bd 318e shrw AX,0x8
ram:00b0bf 12 movw BC,AX
ram:00b0c0 af1cc8 movw AX,!0xfc81c
ram:00b0c3 43 cmpw AX,BC
ram:00b0c4 61d8 sknc
ram:00b0c6 ee9201 _br $! 0xb25b
ram:00b0c9 f6 clrw AX
ram:00b0ca bc04 movw [HL + 0x4],AX
ram:00b0cc 61790c incw [HL + 0xc]
ram:00b0cf ac08 movw AX,[HL + 0x8]
ram:00b0d1 14 movw DE,AX
ram:00b0d2 8c0a mov A,[HL + 0xa]
ram:00b0d4 9efd mov ES,A
ram:00b0d6 118a02 mov A,ES:[DE + 0x2]
ram:00b0d9 3139 shl A,0x3
ram:00b0db 31fe shrw AX,0xf
ram:00b0dd bc06 movw [HL + 0x6],AX
ram:00b0df 317d shlw AX,0x7
ram:00b0e1 bc06 movw [HL + 0x6],AX
ram:00b0e3 ac0c movw AX,[HL + 0xc]
ram:00b0e5 14 movw DE,AX
ram:00b0e6 89 mov A,[DE]
ram:00b0e7 5e06 and A,[HL + 0x6]
ram:00b0e9 318e shrw AX,0x8
ram:00b0eb 6168 or A,
ram:00b0ed dd03 bz $ 0xb0f2
ram:00b0ef e1 oneb A
ram:00b0f0 ef01 br $ 0xb0f3
ram:00b0f2 f1 clrb A
ram:00b0f3 3422c8 movw DE,0xc822
ram:00b0f6 718c mov1 CY,A.0x0
ram:00b0f8 89 mov A,[DE]
ram:00b0f9 71c9 mov1 A.0x4,CY
ram:00b0fb 99 mov [DE],A
ram:00b0fc f6 clrw AX
ram:00b0fd b1 decw AX
ram:00b0fe 612906 subw AX,[HL + 0x6]
ram:00b101 08 xch A,X
ram:00b102 72 mov ,A
ram:00b103 08 xch A,X
ram:00b104 ac0c movw AX,[HL + 0xc]
ram:00b106 14 movw DE,AX
ram:00b107 89 mov A,[DE]
ram:00b108 615a and A,
ram:00b10a 99 mov [DE],A
ram:00b10b ac08 movw AX,[HL + 0x8]
ram:00b10d 14 movw DE,AX
ram:00b10e 8c0a mov A,[HL + 0xa]
ram:00b110 9efd mov ES,A
ram:00b112 118a01 mov A,ES:[DE + 0x1]
ram:00b115 5c0f and A,#0xf
ram:00b117 d1 cmp0 A
ram:00b118 dd1a bz $ 0xb134
ram:00b11a 17 movw AX,HL
ram:00b11b 040400 addw AX,0x4
ram:00b11e c1 push AX
ram:00b11f 8c0a mov A,[HL + 0xa]
ram:00b121 70 mov ,A
ram:00b122 c1 push AX
ram:00b123 ac08 movw AX,[HL + 0x8]
ram:00b125 c1 push AX
ram:00b126 ac0c movw AX,[HL + 0xc]
ram:00b128 fc03af00 call !!0xaf03
ram:00b12c 1006 addw SP,0x6
ram:00b12e 62 mov A,
ram:00b12f 9f19c8 mov !0xfc819,A
ram:00b132 ef0d br $ 0xb141
ram:00b134 ac08 movw AX,[HL + 0x8]
ram:00b136 14 movw DE,AX
ram:00b137 8c0a mov A,[HL + 0xa]
ram:00b139 9efd mov ES,A
ram:00b13b 118a08 mov A,ES:[DE + 0x8]
ram:00b13e 9f19c8 mov !0xfc819,A
ram:00b141 4019c82c cmp !0xfc819,0x2c
ram:00b145 61c8 skc
ram:00b147 ee0b01 _br $! 0xb255
ram:00b14a 8f19c8 mov A,!0xfc819
ram:00b14d 500c mov ,0xc
ram:00b14f d6 mulu X
ram:00b150 04fc65 addw AX,0x65fc
ram:00b153 bb movw [HL],AX
ram:00b154 5100 mov ,0x0
ram:00b156 9c02 mov [HL + 0x2],A
ram:00b158 9dd4 mov 0xffdf4,A
ram:00b15a ab movw AX,[HL]
ram:00b15b 14 movw DE,AX
ram:00b15c 61b8d4 mov ES,0xffdf4
ram:00b15f 118a02 mov A,ES:[DE + 0x2]
ram:00b162 5c0c and A,#0xc
ram:00b164 3422c8 movw DE,0xc822
ram:00b167 70 mov ,A
ram:00b168 89 mov A,[DE]
ram:00b169 5cf3 and A,#0xf3
ram:00b16b 6168 or A,
ram:00b16d 99 mov [DE],A
ram:00b16e ab movw AX,[HL]
ram:00b16f 14 movw DE,AX
ram:00b170 8c02 mov A,[HL + 0x2]
ram:00b172 9efd mov ES,A
ram:00b174 118a02 mov A,ES:[DE + 0x2]
ram:00b177 5c03 and A,#0x3
ram:00b179 72 mov ,A
ram:00b17a 8f22c8 mov A,!0xfc822
ram:00b17d 5c03 and A,#0x3
ram:00b17f 6152 and ,A
ram:00b181 d2 cmp0 C
ram:00b182 61f8 sknz
ram:00b184 eec800 _br $! 0xb24f
ram:00b187 8c02 mov A,[HL + 0x2]
ram:00b189 9efd mov ES,A
ram:00b18b 11a9 movw AX,ES:[DE]
ram:00b18d 6168 or A,
ram:00b18f dd0e bz $ 0xb19f
ram:00b191 8c02 mov A,[HL + 0x2]
ram:00b193 9efd mov ES,A
ram:00b195 11a9 movw AX,ES:[DE]
ram:00b197 421cc8 cmpw AX,!0xfc81c
ram:00b19a 61e8 skz
ram:00b19c eeaa00 _br $! 0xb249
ram:00b19f 8c02 mov A,[HL + 0x2]
ram:00b1a1 9dd4 mov 0xffdf4,A
ram:00b1a3 ab movw AX,[HL]
ram:00b1a4 040400 addw AX,0x4
ram:00b1a7 f8d4 mov C,0xffdf4
ram:00b1a9 f3 clrb B
ram:00b1aa fcabab00 call !!0xabab
ram:00b1ae 62 mov A,
ram:00b1af 9f28c8 mov !0xfc828,A
ram:00b1b2 d528c8 cmp0 !0xfc828
ram:00b1b5 df79 bnz $ 0xb230
ram:00b1b7 713009c8 set1 !0xfc809.0x3
ram:00b1bb d528c8 cmp0 !0xfc828
ram:00b1be df6e bnz $ 0xb22e
ram:00b1c0 ac08 movw AX,[HL + 0x8]
ram:00b1c2 14 movw DE,AX
ram:00b1c3 8c0a mov A,[HL + 0xa]
ram:00b1c5 9efd mov ES,A
ram:00b1c7 118a01 mov A,ES:[DE + 0x1]
ram:00b1ca 5c0f and A,#0xf
ram:00b1cc 318e shrw AX,0x8
ram:00b1ce 61090c addw AX,[HL + 0xc]
ram:00b1d1 bf1ac8 movw !0xfc81a,AX
ram:00b1d4 8c0a mov A,[HL + 0xa]
ram:00b1d6 9efd mov ES,A
ram:00b1d8 118a01 mov A,ES:[DE + 0x1]
ram:00b1db 31ce shrw AX,0xc
ram:00b1dd 61090c addw AX,[HL + 0xc]
ram:00b1e0 bf1ec8 movw !0xfc81e,AX
ram:00b1e3 8c0a mov A,[HL + 0xa]
ram:00b1e5 9efd mov ES,A
ram:00b1e7 118a01 mov A,ES:[DE + 0x1]
ram:00b1ea 5c0f and A,#0xf
ram:00b1ec 81 inc 
ram:00b1ed 318e shrw AX,0x8
ram:00b1ef 12 movw BC,AX
ram:00b1f0 af1cc8 movw AX,!0xfc81c
ram:00b1f3 23 subw AX,BC
ram:00b1f4 bf1cc8 movw !0xfc81c,AX
ram:00b1f7 f6 clrw AX
ram:00b1f8 bf20c8 movw !0xfc820,AX
ram:00b1fb ab movw AX,[HL]
ram:00b1fc 14 movw DE,AX
ram:00b1fd 8c02 mov A,[HL + 0x2]
ram:00b1ff 9efd mov ES,A
ram:00b201 118a0a mov A,ES:[DE + 0xa]
ram:00b204 72 mov ,A
ram:00b205 11aa08 movw AX,ES:[DE + 0x8]
ram:00b208 fc16ae00 call !!0xae16
ram:00b20c ab movw AX,[HL]
ram:00b20d 14 movw DE,AX
ram:00b20e 8c02 mov A,[HL + 0x2]
ram:00b210 9efd mov ES,A
ram:00b212 118a0a mov A,ES:[DE + 0xa]
ram:00b215 9dd4 mov 0xffdf4,A
ram:00b217 11aa08 movw AX,ES:[DE + 0x8]
ram:00b21a c1 push AX
ram:00b21b 8dd4 mov A,0xffdf4
ram:00b21d 9dd6 mov 0xffdf6,A
ram:00b21f c0 pop AX
ram:00b220 14 movw DE,AX
ram:00b221 301ac8 movw AX,0xc81a
ram:00b224 c1 push AX
ram:00b225 8dd6 mov A,0xffdf6
ram:00b227 9efc mov CS,A
ram:00b229 c0 pop AX
ram:00b22a 61ea call DE
ram:00b22c ef41 br $ 0xb26f
ram:00b22e ef3b br $ 0xb26b
ram:00b230 4028c87e cmp !0xfc828,0x7e
ram:00b234 df35 bnz $ 0xb26b
ram:00b236 ac08 movw AX,[HL + 0x8]
ram:00b238 14 movw DE,AX
ram:00b239 8c0a mov A,[HL + 0xa]
ram:00b23b 9efd mov ES,A
ram:00b23d 118a02 mov A,ES:[DE + 0x2]
ram:00b240 316328 bt A.0x6,$ 0xb26a
ram:00b243 cf28c822 mov !0xfc828,0x22
ram:00b247 ef22 br $ 0xb26b
ram:00b249 cf28c812 mov !0xfc828,0x12
ram:00b24d ef1c br $ 0xb26b
ram:00b24f cf28c822 mov !0xfc828,0x22
ram:00b253 ef16 br $ 0xb26b
ram:00b255 cf28c812 mov !0xfc828,0x12
ram:00b259 ef10 br $ 0xb26b
ram:00b25b cf28c812 mov !0xfc828,0x12
ram:00b25f ef0a br $ 0xb26b
ram:00b261 cf28c87f mov !0xfc828,0x7f
ram:00b265 ef04 br $ 0xb26b
ram:00b267 cf28c811 mov !0xfc828,0x11
ram:00b26b fc73b200 call !!0xb273
ram:00b26f 100e addw SP,0xe
ram:00b271 c6 pop HL
ram:00b272 d7 ret
ram:00b273 8f09c8 mov A,!0xfc809
ram:00b276 5c07 and A,#0x7
ram:00b278 d1 cmp0 A
ram:00b279 dd05 bz $ 0xb280
ram:00b27b 91 dec 
ram:00b27c dd07 bz $ 0xb285
ram:00b27e ef0a br $ 0xb28a
ram:00b280 fc97b200 call !!0xb297
ram:00b284 d7 ret
ram:00b285 fcdeb600 call !!0xb6de
ram:00b289 d7 ret
ram:00b28a 30dd15 movw AX,0x15dd
ram:00b28d c1 push AX
ram:00b28e 301600 movw AX,0x16
ram:00b291 fc7e9200 call !!0x927e
ram:00b295 c0 pop AX
ram:00b296 d7 ret
ram:00b297 c7 push HL
ram:00b298 2004 subw SP,0x4
ram:00b29a fbf8ff movw HL,!0xffff8
ram:00b29d 400cc804 cmp !0xfc80c,0x4
ram:00b2a1 dd0c bz $ 0xb2af
ram:00b2a3 30fa15 movw AX,0x15fa
ram:00b2a6 c1 push AX
ram:00b2a7 300e00 movw AX,0xe
ram:00b2aa fc7e9200 call !!0x927e
ram:00b2ae c0 pop AX
ram:00b2af 8f0cc8 mov A,!0xfc80c
ram:00b2b2 5c04 and A,#0x4
ram:00b2b4 d1 cmp0 A
ram:00b2b5 61f8 sknz
ram:00b2b7 eec800 _br $! 0xb382
ram:00b2ba 3409c8 movw DE,0xc809
ram:00b2bd 89 mov A,[DE]
ram:00b2be 5cf8 and A,#0xf8
ram:00b2c0 99 mov [DE],A
ram:00b2c1 f6 clrw AX
ram:00b2c2 12 movw BC,AX
ram:00b2c3 fc16ae00 call !!0xae16
ram:00b2c7 8f22c8 mov A,!0xfc822
ram:00b2ca 5c03 and A,#0x3
ram:00b2cc 70 mov ,A
ram:00b2cd 8f22c8 mov A,!0xfc822
ram:00b2d0 3149 shl A,0x4
ram:00b2d2 316a shr A,0x6
ram:00b2d4 6158 and A,
ram:00b2d6 d1 cmp0 A
ram:00b2d7 61f8 sknz
ram:00b2d9 eea100 _br $! 0xb37d
ram:00b2dc eb0ac8 movw DE,!0xfc80a
ram:00b2df aa0a movw AX,[DE + 0xa]
ram:00b2e1 bc02 movw [HL + 0x2],AX
ram:00b2e3 d528c8 cmp0 !0xfc828
ram:00b2e6 dd39 bz $ 0xb321
ram:00b2e8 8f22c8 mov A,!0xfc822
ram:00b2eb 5c02 and A,#0x2
ram:00b2ed d1 cmp0 A
ram:00b2ee dd14 bz $ 0xb304
ram:00b2f0 8f28c8 mov A,!0xfc828
ram:00b2f3 2c11 sub A,#0x11
ram:00b2f5 2c02 sub A,#0x2
ram:00b2f7 dc04 bc $ 0xb2fd
ram:00b2f9 2c1e sub A,#0x1e
ram:00b2fb df07 bnz $ 0xb304
ram:00b2fd f6 clrw AX
ram:00b2fe fc86b300 call !!0xb386
ram:00b302 ef7e br $ 0xb382
ram:00b304 ac02 movw AX,[HL + 0x2]
ram:00b306 14 movw DE,AX
ram:00b307 89 mov A,[DE]
ram:00b308 72 mov ,A
ram:00b309 9a01 mov [DE + 0x1],A
ram:00b30b ac02 movw AX,[HL + 0x2]
ram:00b30d 14 movw DE,AX
ram:00b30e ca007f mov [DE + 0x0],0x7f
ram:00b311 ac02 movw AX,[HL + 0x2]
ram:00b313 14 movw DE,AX
ram:00b314 8f28c8 mov A,!0xfc828
ram:00b317 9a02 mov [DE + 0x2],A
ram:00b319 300300 movw AX,0x3
ram:00b31c bf20c8 movw !0xfc820,AX
ram:00b31f ef56 br $ 0xb377
ram:00b321 ac02 movw AX,[HL + 0x2]
ram:00b323 14 movw DE,AX
ram:00b324 89 mov A,[DE]
ram:00b325 0c40 add A,#0x40
ram:00b327 99 mov [DE],A
ram:00b328 617902 incw [HL + 0x2]
ram:00b32b 4018c80b cmp !0xfc818,0xb
ram:00b32f dc0c bc $ 0xb33d
ram:00b331 305c16 movw AX,0x165c
ram:00b334 c1 push AX
ram:00b335 300900 movw AX,0x9
ram:00b338 fc7e9200 call !!0x927e
ram:00b33c c0 pop AX
ram:00b33d 8f18c8 mov A,!0xfc818
ram:00b340 500a mov ,0xa
ram:00b342 d6 mulu X
ram:00b343 12 movw BC,AX
ram:00b344 4100 mov ES,0x0
ram:00b346 11498365 mov A,ES:!0xf6583[BC]
ram:00b34a 31ce shrw AX,0xc
ram:00b34c bb movw [HL],AX
ram:00b34d c1 push AX
ram:00b34e d919c8 mov X,!0xfc819
ram:00b351 c1 push AX
ram:00b352 8f18c8 mov A,!0xfc818
ram:00b355 500a mov ,0xa
ram:00b357 d6 mulu X
ram:00b358 048265 addw AX,0x6582
ram:00b35b 5200 mov ,0x0
ram:00b35d f3 clrb B
ram:00b35e fc72ae00 call !!0xae72
ram:00b362 c0 pop AX
ram:00b363 c5 push DE
ram:00b364 c3 push BC
ram:00b365 ac02 movw AX,[HL + 0x2]
ram:00b367 fcf1de00 call !!0xdef1
ram:00b36b 1006 addw SP,0x6
ram:00b36d 617900 incw [HL + 0x0]
ram:00b370 ab movw AX,[HL]
ram:00b371 0220c8 addw AX,!0xfc820
ram:00b374 bf20c8 movw !0xfc820,AX
ram:00b377 cf0cc810 mov !0xfc80c,0x10
ram:00b37b ef05 br $ 0xb382
ram:00b37d f6 clrw AX
ram:00b37e fc86b300 call !!0xb386
ram:00b382 1004 addw SP,0x4
ram:00b384 c6 pop HL
ram:00b385 d7 ret
ram:00b386 c7 push HL
ram:00b387 16 movw HL,AX
ram:00b388 66 mov A,
ram:00b389 9f08c8 mov !0xfc808,A
ram:00b38c f6 clrw AX
ram:00b38d bf0ec8 movw !0xfc80e,AX
ram:00b390 cf0cc840 mov !0xfc80c,0x40
ram:00b394 12 movw BC,AX
ram:00b395 fc16ae00 call !!0xae16
ram:00b399 fcf6a400 call !!0xa4f6
ram:00b39d c6 pop HL
ram:00b39e d7 ret
ram:00b39f c7 push HL
ram:00b3a0 16 movw HL,AX
ram:00b3a1 fc7da200 call !!0xa27d
ram:00b3a5 fc22aa00 call !!0xaa22
ram:00b3a9 17 movw AX,HL
ram:00b3aa f1 clrb A
ram:00b3ab fcb1b300 call !!0xb3b1
ram:00b3af c6 pop HL
ram:00b3b0 d7 ret
ram:00b3b1 c7 push HL
ram:00b3b2 16 movw HL,AX
ram:00b3b3 fc26aa00 call !!0xaa26
ram:00b3b7 fce4aa00 call !!0xaae4
ram:00b3bb fcecaa00 call !!0xaaec
ram:00b3bf f6 clrw AX
ram:00b3c0 bf16c8 movw !0xfc816,AX
ram:00b3c3 fc48a300 call !!0xa348
ram:00b3c7 fcd8a400 call !!0xa4d8
ram:00b3cb fcdfaa00 call !!0xaadf
ram:00b3cf fc39b000 call !!0xb039
ram:00b3d3 fcd9b600 call !!0xb6d9
ram:00b3d7 c6 pop HL
ram:00b3d8 d7 ret
ram:00b3d9 8f0cc8 mov A,!0xfc80c
ram:00b3dc 5c0c and A,#0xc
ram:00b3de d1 cmp0 A
ram:00b3df 61e8 skz
ram:00b3e1 fc12b400 _call !!0xb412
ram:00b3e5 8f0dc8 mov A,!0xfc80d
ram:00b3e8 310323 bt A.0x0,$ 0xb40d
ram:00b3eb f6 clrw AX
ram:00b3ec 4210c8 cmpw AX,!0xfc810
ram:00b3ef dd1d bz $ 0xb40e
ram:00b3f1 e6 onew AX
ram:00b3f2 4212c8 cmpw AX,!0xfc812
ram:00b3f5 df0a bnz $ 0xb401
ram:00b3f7 f6 clrw AX
ram:00b3f8 bf12c8 movw !0xfc812,AX
ram:00b3fb 30f401 movw AX,0x1f4
ram:00b3fe bf10c8 movw !0xfc810,AX
ram:00b401 b210c8 decw !0xfc810
ram:00b404 f6 clrw AX
ram:00b405 4210c8 cmpw AX,!0xfc810
ram:00b408 61f8 sknz
ram:00b40a fc08ac00 _call !!0xac08
ram:00b40e ec39a500 br !!0xa539
ram:00b412 f6 clrw AX
ram:00b413 420ec8 cmpw AX,!0xfc80e
ram:00b416 dd3e bz $ 0xb456
ram:00b418 b20ec8 decw !0xfc80e
ram:00b41b 420ec8 cmpw AX,!0xfc80e
ram:00b41e df36 bnz $ 0xb456
ram:00b420 8f22c8 mov A,!0xfc822
ram:00b423 5c03 and A,#0x3
ram:00b425 70 mov ,A
ram:00b426 8f22c8 mov A,!0xfc822
ram:00b429 3149 shl A,0x4
ram:00b42b 316a shr A,0x6
ram:00b42d 6158 and A,
ram:00b42f d1 cmp0 A
ram:00b430 dd18 bz $ 0xb44a
ram:00b432 714822c8 clr1 !0xfc822.0x4
ram:00b436 eb0ac8 movw DE,!0xfc80a
ram:00b439 8a05 mov A,[DE + 0x5]
ram:00b43b d1 cmp0 A
ram:00b43c df08 bnz $ 0xb446
ram:00b43e ca0504 mov [DE + 0x5],0x4
ram:00b441 fcbdaa00 call !!0xaabd
ram:00b445 d7 ret
ram:00b446 a20ec8 incw !0xfc80e
ram:00b449 d7 ret
ram:00b44a 300718 movw AX,0x1807
ram:00b44d c1 push AX
ram:00b44e 301100 movw AX,0x11
ram:00b451 fc7e9200 call !!0x927e
ram:00b455 c0 pop AX
ram:00b456 d7 ret
ram:00b457 fc5fb400 call !!0xb45f
ram:00b45b ecd9b300 br !!0xb3d9
ram:00b45f d50cc8 cmp0 !0xfc80c
ram:00b462 61e8 skz
ram:00b464 fc6cb400 _call !!0xb46c
ram:00b468 ec9ba500 br !!0xa59b
ram:00b46c c7 push HL
ram:00b46d 8f0cc8 mov A,!0xfc80c
ram:00b470 5c40 and A,#0x40
ram:00b472 d1 cmp0 A
ram:00b473 dd58 bz $ 0xb4cd
ram:00b475 fc3ee000 call !!0xe03e
ram:00b479 71680cc8 clr1 !0xfc80c.0x6
ram:00b47d fc62e000 call !!0xe062
ram:00b481 5601 mov ,0x1
ram:00b483 d508c8 cmp0 !0xfc808
ram:00b486 61e8 skz
ram:00b488 5604 _mov ,0x4
ram:00b48a d528c8 cmp0 !0xfc828
ram:00b48d dd08 bz $ 0xb497
ram:00b48f 51fe mov ,0xfe
ram:00b491 6156 and ,A
ram:00b493 5102 mov ,0x2
ram:00b495 6166 or ,A
ram:00b497 8f09c8 mov A,!0xfc809
ram:00b49a 313522 bf A.0x3,$ 0xb4be
ram:00b49d 8f19c8 mov A,!0xfc819
ram:00b4a0 500c mov ,0xc
ram:00b4a2 d6 mulu X
ram:00b4a3 12 movw BC,AX
ram:00b4a4 4100 mov ES,0x0
ram:00b4a6 11490366 mov A,ES:!0xf6603[BC]
ram:00b4aa f0 clrb X
ram:00b4ab 316e shrw AX,0x6
ram:00b4ad 04f065 addw AX,0x65f0
ram:00b4b0 14 movw DE,AX
ram:00b4b1 4100 mov ES,0x0
ram:00b4b3 118a02 mov A,ES:[DE + 0x2]
ram:00b4b6 9efc mov CS,A
ram:00b4b8 11a9 movw AX,ES:[DE]
ram:00b4ba 14 movw DE,AX
ram:00b4bb 17 movw AX,HL
ram:00b4bc f1 clrb A
ram:00b4bd 61ea call DE
ram:00b4bf 66 mov A,
ram:00b4c0 5c01 and A,#0x1
ram:00b4c2 d1 cmp0 A
ram:00b4c3 dd08 bz $ 0xb4cd
ram:00b4c5 d919c8 mov X,!0xfc819
ram:00b4c8 f1 clrb A
ram:00b4c9 fc08ac00 call !!0xac08
ram:00b4cd 400cc802 cmp !0xfc80c,0x2
ram:00b4d1 df3e bnz $ 0xb511
ram:00b4d3 cf0cc804 mov !0xfc80c,0x4
ram:00b4d7 eb0ac8 movw DE,!0xfc80a
ram:00b4da 8a04 mov A,[DE + 0x4]
ram:00b4dc 91 dec 
ram:00b4dd df0b bnz $ 0xb4ea
ram:00b4df 3422c8 movw DE,0xc822
ram:00b4e2 89 mov A,[DE]
ram:00b4e3 5cfc and A,#0xfc
ram:00b4e5 6c02 or A,#0x2
ram:00b4e7 99 mov [DE],A
ram:00b4e8 ef08 br $ 0xb4f2
ram:00b4ea 3422c8 movw DE,0xc822
ram:00b4ed 89 mov A,[DE]
ram:00b4ee 5cfc and A,#0xfc
ram:00b4f0 81 inc 
ram:00b4f1 99 mov [DE],A
ram:00b4f2 eb0ac8 movw DE,!0xfc80a
ram:00b4f5 aa0a movw AX,[DE + 0xa]
ram:00b4f7 14 movw DE,AX
ram:00b4f8 89 mov A,[DE]
ram:00b4f9 9f31c4 mov !0xfc431,A
ram:00b4fc 305900 movw AX,0x59
ram:00b4ff bf0ec8 movw !0xfc80e,AX
ram:00b502 eb0ac8 movw DE,!0xfc80a
ram:00b505 aa08 movw AX,[DE + 0x8]
ram:00b507 bf1cc8 movw !0xfc81c,AX
ram:00b50a f528c8 clrb !0xfc828
ram:00b50d fc41b000 call !!0xb041
ram:00b511 8f0cc8 mov A,!0xfc80c
ram:00b514 5c3c and A,#0x3c
ram:00b516 d1 cmp0 A
ram:00b517 dd4d bz $ 0xb566
ram:00b519 af2ac8 movw AX,!0xfc82a
ram:00b51c 6168 or A,
ram:00b51e 6f2cc8 or A,!0xfc82c
ram:00b521 dd3f bz $ 0xb562
ram:00b523 8f09c8 mov A,!0xfc809
ram:00b526 5c07 and A,#0x7
ram:00b528 4c01 cmp A,#0x1
ram:00b52a df1c bnz $ 0xb548
ram:00b52c 8f2cc8 mov A,!0xfc82c
ram:00b52f 9dd4 mov 0xffdf4,A
ram:00b531 af2ac8 movw AX,!0xfc82a
ram:00b534 c1 push AX
ram:00b535 8dd4 mov A,0xffdf4
ram:00b537 9dd6 mov 0xffdf6,A
ram:00b539 c0 pop AX
ram:00b53a 14 movw DE,AX
ram:00b53b 302ec8 movw AX,0xc82e
ram:00b53e c1 push AX
ram:00b53f 8dd6 mov A,0xffdf6
ram:00b541 9efc mov CS,A
ram:00b543 c0 pop AX
ram:00b544 61ea call DE
ram:00b546 ef1a br $ 0xb562
ram:00b548 8f2cc8 mov A,!0xfc82c
ram:00b54b 9dd4 mov 0xffdf4,A
ram:00b54d af2ac8 movw AX,!0xfc82a
ram:00b550 c1 push AX
ram:00b551 8dd4 mov A,0xffdf4
ram:00b553 9dd6 mov 0xffdf6,A
ram:00b555 c0 pop AX
ram:00b556 14 movw DE,AX
ram:00b557 301ac8 movw AX,0xc81a
ram:00b55a c1 push AX
ram:00b55b 8dd6 mov A,0xffdf6
ram:00b55d 9efc mov CS,A
ram:00b55f c0 pop AX
ram:00b560 61ea call DE
ram:00b562 fc23b700 call !!0xb723
ram:00b566 400cc810 cmp !0xfc80c,0x10
ram:00b56a df35 bnz $ 0xb5a1
ram:00b56c eb0ac8 movw DE,!0xfc80a
ram:00b56f 8a05 mov A,[DE + 0x5]
ram:00b571 d1 cmp0 A
ram:00b572 df2d bnz $ 0xb5a1
ram:00b574 f6 clrw AX
ram:00b575 bf0ec8 movw !0xfc80e,AX
ram:00b578 cf0cc820 mov !0xfc80c,0x20
ram:00b57c eb0ac8 movw DE,!0xfc80a
ram:00b57f af20c8 movw AX,!0xfc820
ram:00b582 ba08 movw [DE + 0x8],AX
ram:00b584 d528c8 cmp0 !0xfc828
ram:00b587 df03 bnz $ 0xb58c
ram:00b589 e1 oneb A
ram:00b58a ef02 br $ 0xb58e
ram:00b58c 5103 mov ,0x3
ram:00b58e eb0ac8 movw DE,!0xfc80a
ram:00b591 9a05 mov [DE + 0x5],A
ram:00b593 eb0ac8 movw DE,!0xfc80a
ram:00b596 aa0a movw AX,[DE + 0xa]
ram:00b598 ba0c movw [DE + 0xc],AX
ram:00b59a af0ac8 movw AX,!0xfc80a
ram:00b59d fcfca600 call !!0xa6fc
ram:00b5a1 c6 pop HL
ram:00b5a2 d7 ret
ram:00b6d9 71083ec8 clr1 !0xfc83e.0x0
ram:00b6dd d7 ret
ram:00b6de f6 clrw AX
ram:00b6df 12 movw BC,AX
ram:00b6e0 fc16ae00 call !!0xae16
ram:00b6e4 d528c8 cmp0 !0xfc828
ram:00b6e7 df35 bnz $ 0xb71e
ram:00b6e9 af34c8 movw AX,!0xfc834
ram:00b6ec a1 incw AX
ram:00b6ed a1 incw AX
ram:00b6ee 12 movw BC,AX
ram:00b6ef af20c8 movw AX,!0xfc820
ram:00b6f2 03 addw AX,BC
ram:00b6f3 bf20c8 movw !0xfc820,AX
ram:00b6f6 44ff0f cmpw AX,0xfff
ram:00b6f9 dc06 bc $ 0xb701
ram:00b6fb cf28c812 mov !0xfc828,0x12
ram:00b6ff ef1d br $ 0xb71e
ram:00b701 af34c8 movw AX,!0xfc834
ram:00b704 0232c8 addw AX,!0xfc832
ram:00b707 bf32c8 movw !0xfc832,AX
ram:00b70a 343dc8 movw DE,0xc83d
ram:00b70d 89 mov A,[DE]
ram:00b70e 81 inc 
ram:00b70f 99 mov [DE],A
ram:00b710 8f3cc8 mov A,!0xfc83c
ram:00b713 70 mov ,A
ram:00b714 89 mov A,[DE]
ram:00b715 6148 cmp A,
ram:00b717 de05 bnc $ 0xb71e
ram:00b719 71003ec8 set1 !0xfc83e.0x0
ram:00b71d d7 ret
ram:00b71e fc97b200 call !!0xb297
ram:00b722 d7 ret
ram:00b723 c7 push HL
ram:00b724 8f09c8 mov A,!0xfc809
ram:00b727 5c07 and A,#0x7
ram:00b729 4c01 cmp A,#0x1
ram:00b72b 61e8 skz
ram:00b72d ee9f00 _br $! 0xb7cf
ram:00b730 8f3ec8 mov A,!0xfc83e
ram:00b733 310303 bt A.0x0,$ 0xb738
ram:00b736 ee9600 br $! 0xb7cf
ram:00b739 71083ec8 clr1 !0xfc83e.0x0
ram:00b73d 8f3dc8 mov A,!0xfc83d
ram:00b740 73 mov ,A
ram:00b741 0940c8 mov A,!0xfc840[B]
ram:00b744 318e shrw AX,0x8
ram:00b746 16 movw HL,AX
ram:00b747 312d shlw AX,0x2
ram:00b749 12 movw BC,AX
ram:00b74a 01 addw AX,AX
ram:00b74b 03 addw AX,BC
ram:00b74c 12 movw BC,AX
ram:00b74d 4100 mov ES,0x0
ram:00b74f 11495268 mov A,ES:!0xf6852[BC]
ram:00b753 5c0c and A,#0xc
ram:00b755 3436c8 movw DE,0xc836
ram:00b758 70 mov ,A
ram:00b759 89 mov A,[DE]
ram:00b75a 5cf3 and A,#0xf3
ram:00b75c 6168 or A,
ram:00b75e 99 mov [DE],A
ram:00b75f 17 movw AX,HL
ram:00b760 312d shlw AX,0x2
ram:00b762 12 movw BC,AX
ram:00b763 01 addw AX,AX
ram:00b764 03 addw AX,BC
ram:00b765 12 movw BC,AX
ram:00b766 11794c68 movw AX,ES:!0xf684c[BC]
ram:00b76a 318e shrw AX,0x8
ram:00b76c 08 xch A,X
ram:00b76d 72 mov ,A
ram:00b76e 08 xch A,X
ram:00b76f eb32c8 movw DE,!0xfc832
ram:00b772 62 mov A,
ram:00b773 99 mov [DE],A
ram:00b774 17 movw AX,HL
ram:00b775 312d shlw AX,0x2
ram:00b777 12 movw BC,AX
ram:00b778 01 addw AX,AX
ram:00b779 03 addw AX,BC
ram:00b77a 12 movw BC,AX
ram:00b77b 11494c68 mov A,ES:!0xf684c[BC]
ram:00b77f eb32c8 movw DE,!0xfc832
ram:00b782 9a01 mov [DE + 0x1],A
ram:00b784 af32c8 movw AX,!0xfc832
ram:00b787 a1 incw AX
ram:00b788 a1 incw AX
ram:00b789 bf32c8 movw !0xfc832,AX
ram:00b78c bf1ec8 movw !0xfc81e,AX
ram:00b78f f6 clrw AX
ram:00b790 bf34c8 movw !0xfc834,AX
ram:00b793 17 movw AX,HL
ram:00b794 312d shlw AX,0x2
ram:00b796 12 movw BC,AX
ram:00b797 01 addw AX,AX
ram:00b798 03 addw AX,BC
ram:00b799 044c68 addw AX,0x684c
ram:00b79c 14 movw DE,AX
ram:00b79d 118a0a mov A,ES:[DE + 0xa]
ram:00b7a0 72 mov ,A
ram:00b7a1 f3 clrb B
ram:00b7a2 11aa08 movw AX,ES:[DE + 0x8]
ram:00b7a5 fc16ae00 call !!0xae16
ram:00b7a9 17 movw AX,HL
ram:00b7aa 312d shlw AX,0x2
ram:00b7ac 12 movw BC,AX
ram:00b7ad 01 addw AX,AX
ram:00b7ae 03 addw AX,BC
ram:00b7af 044c68 addw AX,0x684c
ram:00b7b2 14 movw DE,AX
ram:00b7b3 4100 mov ES,0x0
ram:00b7b5 118a0a mov A,ES:[DE + 0xa]
ram:00b7b8 9dd4 mov 0xffdf4,A
ram:00b7ba 11aa08 movw AX,ES:[DE + 0x8]
ram:00b7bd c1 push AX
ram:00b7be 8dd4 mov A,0xffdf4
ram:00b7c0 9dd6 mov 0xffdf6,A
ram:00b7c2 c0 pop AX
ram:00b7c3 14 movw DE,AX
ram:00b7c4 302ec8 movw AX,0xc82e
ram:00b7c7 c1 push AX
ram:00b7c8 8dd6 mov A,0xffdf6
ram:00b7ca 9efc mov CS,A
ram:00b7cc c0 pop AX
ram:00b7cd 61ea call DE
ram:00b7cf c6 pop HL
ram:00b7d0 d7 ret
ram:00b910 c7 push HL
ram:00b911 c1 push AX
ram:00b912 fbf8ff movw HL,!0xffff8
ram:00b915 cc0181 mov [HL + 0x1],0x81
ram:00b918 db1ae4 movw BC,!0xfe41a
ram:00b91b 17 movw AX,HL
ram:00b91c a1 incw AX
ram:00b91d c1 push AX
ram:00b91e 490e00 mov A,!0xf000e[BC]
ram:00b921 9efc mov CS,A
ram:00b923 790c00 movw AX,!0xf000c[BC]
ram:00b926 14 movw DE,AX
ram:00b927 301000 movw AX,0x10
ram:00b92a 61ea call DE
ram:00b92c c0 pop AX
ram:00b92d cc0101 mov [HL + 0x1],0x1
ram:00b930 e6 onew AX
ram:00b931 c1 push AX
ram:00b932 17 movw AX,HL
ram:00b933 a1 incw AX
ram:00b934 c1 push AX
ram:00b935 306100 movw AX,0x61
ram:00b938 c1 push AX
ram:00b939 e6 onew AX
ram:00b93a a1 incw AX
ram:00b93b c1 push AX
ram:00b93c e6 onew AX
ram:00b93d fcb75401 call !!0x154b7
ram:00b941 1008 addw SP,0x8
ram:00b943 c0 pop AX
ram:00b944 c6 pop HL
ram:00b945 d7 ret
ram:00b946 c7 push HL
ram:00b947 c1 push AX
ram:00b948 fbf8ff movw HL,!0xffff8
ram:00b94b cc01c0 mov [HL + 0x1],0xc0
ram:00b94e db1ae4 movw BC,!0xfe41a
ram:00b951 17 movw AX,HL
ram:00b952 a1 incw AX
ram:00b953 c1 push AX
ram:00b954 490e00 mov A,!0xf000e[BC]
ram:00b957 9efc mov CS,A
ram:00b959 790c00 movw AX,!0xf000c[BC]
ram:00b95c 14 movw DE,AX
ram:00b95d 301000 movw AX,0x10
ram:00b960 61ea call DE
ram:00b962 c0 pop AX
ram:00b963 cc0102 mov [HL + 0x1],0x2
ram:00b966 e6 onew AX
ram:00b967 c1 push AX
ram:00b968 17 movw AX,HL
ram:00b969 a1 incw AX
ram:00b96a c1 push AX
ram:00b96b 306100 movw AX,0x61
ram:00b96e c1 push AX
ram:00b96f e6 onew AX
ram:00b970 a1 incw AX
ram:00b971 c1 push AX
ram:00b972 e6 onew AX
ram:00b973 fcb75401 call !!0x154b7
ram:00b977 1008 addw SP,0x8
ram:00b979 c0 pop AX
ram:00b97a c6 pop HL
ram:00b97b d7 ret
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
ram:00ccff d49d cmp0 0xffdbd
ram:00cd01 d6 mulu X
ram:00cd02 c0 pop AX
ram:00cd03 14 movw DE,AX
ram:00cd04 301900 movw AX,0x19
ram:00cd07 f7 clrw BC
ram:00cd08 c1 push AX
ram:00cd09 8dd6 mov A,0xffdf6
ram:00cd0b 9efc mov CS,A
ram:00cd0d c0 pop AX
ram:00cd0e 61ea call DE
ram:00d521 f583c8 clrb !0xfc883
ram:00d524 f573c8 clrb !0xfc873
ram:00d527 cf91c8ff mov !0xfc891,0xff
ram:00d52b ec2fd500 br !!0xd52f
ram:00d52f f590c8 clrb !0xfc890
ram:00d532 300800 movw AX,0x8
ram:00d535 fc9ed500 call !!0xd59e
ram:00d539 302800 movw AX,0x28
ram:00d53c ec40d500 br !!0xd540
ram:00d540 c7 push HL
ram:00d541 16 movw HL,AX
ram:00d542 fc3ee000 call !!0xe03e
ram:00d546 5701 mov ,0x1
ram:00d548 8f73c8 mov A,!0xfc873
ram:00d54b 7c80 xor A,#0x80
ram:00d54d 4c82 cmp A,#0x82
ram:00d54f dc18 bc $ 0xd569
ram:00d551 4073c809 cmp !0xfc873,0x9
ram:00d555 dd12 bz $ 0xd569
ram:00d557 cf73c809 mov !0xfc873,0x9
ram:00d55b 17 movw AX,HL
ram:00d55c f1 clrb A
ram:00d55d fcb3a400 call !!0xa4b3
ram:00d561 62 mov A,
ram:00d562 77 mov ,A
ram:00d563 d1 cmp0 A
ram:00d564 61f8 sknz
ram:00d566 f573c8 _clrb !0xfc873
ram:00d569 f6 clrw AX
ram:00d56a bf70c8 movw !0xfc870,AX
ram:00d56d 710874c8 clr1 !0xfc874.0x0
ram:00d571 712874c8 clr1 !0xfc874.0x2
ram:00d575 67 mov A,
ram:00d576 d1 cmp0 A
ram:00d577 dd11 bz $ 0xd58a
ram:00d579 f573c8 clrb !0xfc873
ram:00d57c 711874c8 clr1 !0xfc874.0x1
ram:00d580 f57cc8 clrb !0xfc87c
ram:00d583 347ec8 movw DE,0xc87e
ram:00d586 89 mov A,[DE]
ram:00d587 5cf0 and A,#0xf0
ram:00d589 99 mov [DE],A
ram:00d58a d591c8 cmp0 !0xfc891
ram:00d58d df09 bnz $ 0xd598
ram:00d58f f6 clrw AX
ram:00d590 fc558700 call !!0x8755
ram:00d594 cf91c8ff mov !0xfc891,0xff
ram:00d598 fc62e000 call !!0xe062
ram:00d59c c6 pop HL
ram:00d59d d7 ret
ram:00d59e c7 push HL
ram:00d59f 16 movw HL,AX
ram:00d5a0 fc3ee000 call !!0xe03e
ram:00d5a4 8f83c8 mov A,!0xfc883
ram:00d5a7 7c80 xor A,#0x80
ram:00d5a9 4c82 cmp A,#0x82
ram:00d5ab dc10 bc $ 0xd5bd
ram:00d5ad 4083c807 cmp !0xfc883,0x7
ram:00d5b1 dd0a bz $ 0xd5bd
ram:00d5b3 cf83c807 mov !0xfc883,0x7
ram:00d5b7 17 movw AX,HL
ram:00d5b8 f1 clrb A
ram:00d5b9 fcd5a300 call !!0xa3d5
ram:00d5bd f6 clrw AX
ram:00d5be bf80c8 movw !0xfc880,AX
ram:00d5c1 f583c8 clrb !0xfc883
ram:00d5c4 710884c8 clr1 !0xfc884.0x0
ram:00d5c8 711884c8 clr1 !0xfc884.0x1
ram:00d5cc 348ec8 movw DE,0xc88e
ram:00d5cf 89 mov A,[DE]
ram:00d5d0 5cf0 and A,#0xf0
ram:00d5d2 99 mov [DE],A
ram:00d5d3 a5 incw DE
ram:00d5d4 89 mov A,[DE]
ram:00d5d5 5cfc and A,#0xfc
ram:00d5d7 99 mov [DE],A
ram:00d5d8 4091c880 cmp !0xfc891,0x80
ram:00d5dc df09 bnz $ 0xd5e7
ram:00d5de f6 clrw AX
ram:00d5df fc558700 call !!0x8755
ram:00d5e3 cf91c8ff mov !0xfc891,0xff
ram:00d5e7 fc62e000 call !!0xe062
ram:00d5eb c6 pop HL
ram:00d5ec d7 ret
ram:00d5ed c7 push HL
ram:00d5ee c1 push AX
ram:00d5ef 2004 subw SP,0x4
ram:00d5f1 fbf8ff movw HL,!0xffff8
ram:00d5f4 ac04 movw AX,[HL + 0x4]
ram:00d5f6 14 movw DE,AX
ram:00d5f7 aa06 movw AX,[DE + 0x6]
ram:00d5f9 14 movw DE,AX
ram:00d5fa 89 mov A,[DE]
ram:00d5fb 5cf0 and A,#0xf0
ram:00d5fd d1 cmp0 A
ram:00d5fe dd15 bz $ 0xd615
ram:00d600 2c10 sub A,#0x10
ram:00d602 dd11 bz $ 0xd615
ram:00d604 2c10 sub A,#0x10
ram:00d606 61f8 sknz
ram:00d608 eecf01 _br $! 0xd7da
ram:00d60b 2c10 sub A,#0x10
ram:00d60d 61f8 sknz
ram:00d60f ee5803 _br $! 0xd96a
ram:00d612 ee3204 br $! 0xda47
ram:00d615 d583c8 cmp0 !0xfc883
ram:00d618 dd11 bz $ 0xd62b
ram:00d61a 4083c801 cmp !0xfc883,0x1
ram:00d61e df04 bnz $ 0xd624
ram:00d620 f7 clrw BC
ram:00d621 ee2404 br $! 0xda48
ram:00d624 300600 movw AX,0x6
ram:00d627 fc9ed500 call !!0xd59e
ram:00d62b cf83c802 mov !0xfc883,0x2
ram:00d62f f6 clrw AX
ram:00d630 bf8ac8 movw !0xfc88a,AX
ram:00d633 ac04 movw AX,[HL + 0x4]
ram:00d635 14 movw DE,AX
ram:00d636 aa06 movw AX,[DE + 0x6]
ram:00d638 14 movw DE,AX
ram:00d639 89 mov A,[DE]
ram:00d63a 5cf0 and A,#0xf0
ram:00d63c d1 cmp0 A
ram:00d63d 61f8 sknz
ram:00d63f ee0a01 _br $! 0xd74c
ram:00d642 2c10 sub A,#0x10
ram:00d644 61e8 skz
ram:00d646 ee8701 _br $! 0xd7d0
ram:00d649 ac04 movw AX,[HL + 0x4]
ram:00d64b 14 movw DE,AX
ram:00d64c aa06 movw AX,[DE + 0x6]
ram:00d64e 14 movw DE,AX
ram:00d64f 89 mov A,[DE]
ram:00d650 5c0f and A,#0xf
ram:00d652 318e shrw AX,0x8
ram:00d654 318d shlw AX,0x8
ram:00d656 bf8cc8 movw !0xfc88c,AX
ram:00d659 ac04 movw AX,[HL + 0x4]
ram:00d65b 14 movw DE,AX
ram:00d65c aa06 movw AX,[DE + 0x6]
ram:00d65e 14 movw DE,AX
ram:00d65f 8a01 mov A,[DE + 0x1]
ram:00d661 318e shrw AX,0x8
ram:00d663 6f8dc8 or A,!0xfc88d
ram:00d666 08 xch A,X
ram:00d667 6f8cc8 or A,!0xfc88c
ram:00d66a 08 xch A,X
ram:00d66b bf8cc8 movw !0xfc88c,AX
ram:00d66e 440800 cmpw AX,0x8
ram:00d671 61d8 sknc
ram:00d673 eecb00 _br $! 0xd741
ram:00d676 348fc8 movw DE,0xc88f
ram:00d679 89 mov A,[DE]
ram:00d67a 5cfc and A,#0xfc
ram:00d67c 99 mov [DE],A
ram:00d67d ac04 movw AX,[HL + 0x4]
ram:00d67f 14 movw DE,AX
ram:00d680 aa06 movw AX,[DE + 0x6]
ram:00d682 a1 incw AX
ram:00d683 a1 incw AX
ram:00d684 bf86c8 movw !0xfc886,AX
ram:00d687 af8cc8 movw AX,!0xfc88c
ram:00d68a fc76a300 call !!0xa376
ram:00d68e 13 movw AX,BC
ram:00d68f bf88c8 movw !0xfc888,AX
ram:00d692 8f8fc8 mov A,!0xfc88f
ram:00d695 5c03 and A,#0x3
ram:00d697 d1 cmp0 A
ram:00d698 dd24 bz $ 0xd6be
ram:00d69a 2c02 sub A,#0x2
ram:00d69c dd05 bz $ 0xd6a3
ram:00d69e 91 dec 
ram:00d69f dd08 bz $ 0xd6a9
ram:00d6a1 ef1b br $ 0xd6be
ram:00d6a3 f583c8 clrb !0xfc883
ram:00d6a6 ee9600 br $! 0xd73f
ram:00d6a9 30c900 movw AX,0xc9
ram:00d6ac bf80c8 movw !0xfc880,AX
ram:00d6af cf83c806 mov !0xfc883,0x6
ram:00d6b3 710084c8 set1 !0xfc884.0x0
ram:00d6b7 fc7edb00 call !!0xdb7e
ram:00d6bb ee8100 br $! 0xd73f
ram:00d6be f6 clrw AX
ram:00d6bf 4288c8 cmpw AX,!0xfc888
ram:00d6c2 dd78 bz $ 0xd73c
ram:00d6c4 ac04 movw AX,[HL + 0x4]
ram:00d6c6 14 movw DE,AX
ram:00d6c7 aa06 movw AX,[DE + 0x6]
ram:00d6c9 14 movw DE,AX
ram:00d6ca 8a02 mov A,[DE + 0x2]
ram:00d6cc eb88c8 movw DE,!0xfc888
ram:00d6cf 99 mov [DE],A
ram:00d6d0 ac04 movw AX,[HL + 0x4]
ram:00d6d2 14 movw DE,AX
ram:00d6d3 aa06 movw AX,[DE + 0x6]
ram:00d6d5 a1 incw AX
ram:00d6d6 14 movw DE,AX
ram:00d6d7 8a02 mov A,[DE + 0x2]
ram:00d6d9 eb88c8 movw DE,!0xfc888
ram:00d6dc 9a01 mov [DE + 0x1],A
ram:00d6de ac04 movw AX,[HL + 0x4]
ram:00d6e0 14 movw DE,AX
ram:00d6e1 aa06 movw AX,[DE + 0x6]
ram:00d6e3 a1 incw AX
ram:00d6e4 a1 incw AX
ram:00d6e5 14 movw DE,AX
ram:00d6e6 8a02 mov A,[DE + 0x2]
ram:00d6e8 eb88c8 movw DE,!0xfc888
ram:00d6eb 9a02 mov [DE + 0x2],A
ram:00d6ed ac04 movw AX,[HL + 0x4]
ram:00d6ef 14 movw DE,AX
ram:00d6f0 aa06 movw AX,[DE + 0x6]
ram:00d6f2 a1 incw AX
ram:00d6f3 a1 incw AX
ram:00d6f4 14 movw DE,AX
ram:00d6f5 8a03 mov A,[DE + 0x3]
ram:00d6f7 eb88c8 movw DE,!0xfc888
ram:00d6fa 9a03 mov [DE + 0x3],A
ram:00d6fc ac04 movw AX,[HL + 0x4]
ram:00d6fe 14 movw DE,AX
ram:00d6ff aa06 movw AX,[DE + 0x6]
ram:00d701 a1 incw AX
ram:00d702 a1 incw AX
ram:00d703 14 movw DE,AX
ram:00d704 8a04 mov A,[DE + 0x4]
ram:00d706 eb88c8 movw DE,!0xfc888
ram:00d709 9a04 mov [DE + 0x4],A
ram:00d70b ac04 movw AX,[HL + 0x4]
ram:00d70d 14 movw DE,AX
ram:00d70e aa06 movw AX,[DE + 0x6]
ram:00d710 a1 incw AX
ram:00d711 a1 incw AX
ram:00d712 14 movw DE,AX
ram:00d713 8a05 mov A,[DE + 0x5]
ram:00d715 eb88c8 movw DE,!0xfc888
ram:00d718 9a05 mov [DE + 0x5],A
ram:00d71a 300600 movw AX,0x6
ram:00d71d bf8ac8 movw !0xfc88a,AX
ram:00d720 348ec8 movw DE,0xc88e
ram:00d723 89 mov A,[DE]
ram:00d724 5cf0 and A,#0xf0
ram:00d726 81 inc 
ram:00d727 99 mov [DE],A
ram:00d728 30c900 movw AX,0xc9
ram:00d72b bf80c8 movw !0xfc880,AX
ram:00d72e cf83c805 mov !0xfc883,0x5
ram:00d732 710084c8 set1 !0xfc884.0x0
ram:00d736 fc7edb00 call !!0xdb7e
ram:00d73a ef0c br $ 0xd748
ram:00d73c f583c8 clrb !0xfc883
ram:00d73f ef07 br $ 0xd748
ram:00d741 e583c8 oneb !0xfc883
ram:00d744 fc62de00 call !!0xde62
ram:00d748 f7 clrw BC
ram:00d749 eefc02 br $! 0xda48
ram:00d74c ac04 movw AX,[HL + 0x4]
ram:00d74e 14 movw DE,AX
ram:00d74f aa06 movw AX,[DE + 0x6]
ram:00d751 14 movw DE,AX
ram:00d752 89 mov A,[DE]
ram:00d753 318e shrw AX,0x8
ram:00d755 bf8cc8 movw !0xfc88c,AX
ram:00d758 440800 cmpw AX,0x8
ram:00d75b de68 bnc $ 0xd7c5
ram:00d75d f6 clrw AX
ram:00d75e 428cc8 cmpw AX,!0xfc88c
ram:00d761 dd62 bz $ 0xd7c5
ram:00d763 348fc8 movw DE,0xc88f
ram:00d766 89 mov A,[DE]
ram:00d767 5cfc and A,#0xfc
ram:00d769 99 mov [DE],A
ram:00d76a ac04 movw AX,[HL + 0x4]
ram:00d76c 14 movw DE,AX
ram:00d76d aa06 movw AX,[DE + 0x6]
ram:00d76f a1 incw AX
ram:00d770 bf86c8 movw !0xfc886,AX
ram:00d773 af8cc8 movw AX,!0xfc88c
ram:00d776 fc76a300 call !!0xa376
ram:00d77a 13 movw AX,BC
ram:00d77b bf88c8 movw !0xfc888,AX
ram:00d77e f6 clrw AX
ram:00d77f 4288c8 cmpw AX,!0xfc888
ram:00d782 dd38 bz $ 0xd7bc
ram:00d784 8f8fc8 mov A,!0xfc88f
ram:00d787 5c03 and A,#0x3
ram:00d789 df31 bnz $ 0xd7bc
ram:00d78b af8cc8 movw AX,!0xfc88c
ram:00d78e b1 decw AX
ram:00d78f bc02 movw [HL + 0x2],AX
ram:00d791 8c03 mov A,[HL + 0x3]
ram:00d793 01 addw AX,AX
ram:00d794 dc1a bc $ 0xd7b0
ram:00d796 ac04 movw AX,[HL + 0x4]
ram:00d798 14 movw DE,AX
ram:00d799 aa06 movw AX,[DE + 0x6]
ram:00d79b a1 incw AX
ram:00d79c 12 movw BC,AX
ram:00d79d ac02 movw AX,[HL + 0x2]
ram:00d79f 03 addw AX,BC
ram:00d7a0 14 movw DE,AX
ram:00d7a1 89 mov A,[DE]
ram:00d7a2 72 mov ,A
ram:00d7a3 ac02 movw AX,[HL + 0x2]
ram:00d7a5 0288c8 addw AX,!0xfc888
ram:00d7a8 14 movw DE,AX
ram:00d7a9 62 mov A,
ram:00d7aa 99 mov [DE],A
ram:00d7ab 618902 decw [HL + 0x2]
ram:00d7ae efe1 br $ 0xd791
ram:00d7b0 e583c8 oneb !0xfc883
ram:00d7b3 af8cc8 movw AX,!0xfc88c
ram:00d7b6 fcc3a300 call !!0xa3c3
ram:00d7ba ef10 br $ 0xd7cc
ram:00d7bc e583c8 oneb !0xfc883
ram:00d7bf fc62de00 call !!0xde62
ram:00d7c3 ef07 br $ 0xd7cc
ram:00d7c5 e583c8 oneb !0xfc883
ram:00d7c8 fc62de00 call !!0xde62
ram:00d7cc f7 clrw BC
ram:00d7cd ee7802 br $! 0xda48
ram:00d7d0 e583c8 oneb !0xfc883
ram:00d7d3 fc62de00 call !!0xde62
ram:00d7d7 ee6d02 br $! 0xda47
ram:00d7da 4083c803 cmp !0xfc883,0x3
ram:00d7de dd09 bz $ 0xd7e9
ram:00d7e0 4083c805 cmp !0xfc883,0x5
ram:00d7e4 61e8 skz
ram:00d7e6 ee7e01 _br $! 0xd967
ram:00d7e9 4083c805 cmp !0xfc883,0x5
ram:00d7ed df16 bnz $ 0xd805
ram:00d7ef 8f84c8 mov A,!0xfc884
ram:00d7f2 31030c bt A.0x0,$ 0xd800
ram:00d7f5 f6 clrw AX
ram:00d7f6 fc558700 call !!0x8755
ram:00d7fa f6 clrw AX
ram:00d7fb fcd7dc00 call !!0xdcd7
ram:00d7ff ef04 br $ 0xd805
ram:00d801 f7 clrw BC
ram:00d802 ee4302 br $! 0xda48
ram:00d805 af8ac8 movw AX,!0xfc88a
ram:00d808 040700 addw AX,0x7
ram:00d80b 428cc8 cmpw AX,!0xfc88c
ram:00d80e dc63 bc $ 0xd873
ram:00d810 ac04 movw AX,[HL + 0x4]
ram:00d812 14 movw DE,AX
ram:00d813 aa06 movw AX,[DE + 0x6]
ram:00d815 14 movw DE,AX
ram:00d816 89 mov A,[DE]
ram:00d817 5c0f and A,#0xf
ram:00d819 72 mov ,A
ram:00d81a 8f8ec8 mov A,!0xfc88e
ram:00d81d 5c0f and A,#0xf
ram:00d81f 6142 cmp ,A
ram:00d821 dd07 bz $ 0xd82a
ram:00d823 e6 onew AX
ram:00d824 fc9ed500 call !!0xd59e
ram:00d828 ef46 br $ 0xd870
ram:00d82a ac04 movw AX,[HL + 0x4]
ram:00d82c 14 movw DE,AX
ram:00d82d aa06 movw AX,[DE + 0x6]
ram:00d82f a1 incw AX
ram:00d830 bf86c8 movw !0xfc886,AX
ram:00d833 af8ac8 movw AX,!0xfc88a
ram:00d836 a1 incw AX
ram:00d837 12 movw BC,AX
ram:00d838 af8cc8 movw AX,!0xfc88c
ram:00d83b 23 subw AX,BC
ram:00d83c bc02 movw [HL + 0x2],AX
ram:00d83e 8c03 mov A,[HL + 0x3]
ram:00d840 01 addw AX,AX
ram:00d841 dc1f bc $ 0xd862
ram:00d843 ac04 movw AX,[HL + 0x4]
ram:00d845 14 movw DE,AX
ram:00d846 aa06 movw AX,[DE + 0x6]
ram:00d848 a1 incw AX
ram:00d849 12 movw BC,AX
ram:00d84a ac02 movw AX,[HL + 0x2]
ram:00d84c 03 addw AX,BC
ram:00d84d 14 movw DE,AX
ram:00d84e 89 mov A,[DE]
ram:00d84f 72 mov ,A
ram:00d850 af8ac8 movw AX,!0xfc88a
ram:00d853 0288c8 addw AX,!0xfc888
ram:00d856 14 movw DE,AX
ram:00d857 ac02 movw AX,[HL + 0x2]
ram:00d859 05 addw AX,DE
ram:00d85a 14 movw DE,AX
ram:00d85b 62 mov A,
ram:00d85c 99 mov [DE],A
ram:00d85d 618902 decw [HL + 0x2]
ram:00d860 efdc br $ 0xd83e
ram:00d862 e583c8 oneb !0xfc883
ram:00d865 f6 clrw AX
ram:00d866 bf80c8 movw !0xfc880,AX
ram:00d869 af8cc8 movw AX,!0xfc88c
ram:00d86c fcc3a300 call !!0xa3c3
ram:00d870 eef000 br $! 0xd963
ram:00d873 ac04 movw AX,[HL + 0x4]
ram:00d875 14 movw DE,AX
ram:00d876 aa06 movw AX,[DE + 0x6]
ram:00d878 14 movw DE,AX
ram:00d879 89 mov A,[DE]
ram:00d87a 5c0f and A,#0xf
ram:00d87c 72 mov ,A
ram:00d87d 8f8ec8 mov A,!0xfc88e
ram:00d880 5c0f and A,#0xf
ram:00d882 6142 cmp ,A
ram:00d884 dd08 bz $ 0xd88e
ram:00d886 e6 onew AX
ram:00d887 fc9ed500 call !!0xd59e
ram:00d88b eed500 br $! 0xd963
ram:00d88e ac04 movw AX,[HL + 0x4]
ram:00d890 14 movw DE,AX
ram:00d891 aa06 movw AX,[DE + 0x6]
ram:00d893 a1 incw AX
ram:00d894 bf86c8 movw !0xfc886,AX
ram:00d897 aa06 movw AX,[DE + 0x6]
ram:00d899 14 movw DE,AX
ram:00d89a 8a01 mov A,[DE + 0x1]
ram:00d89c 72 mov ,A
ram:00d89d af8ac8 movw AX,!0xfc88a
ram:00d8a0 0288c8 addw AX,!0xfc888
ram:00d8a3 14 movw DE,AX
ram:00d8a4 62 mov A,
ram:00d8a5 99 mov [DE],A
ram:00d8a6 ac04 movw AX,[HL + 0x4]
ram:00d8a8 14 movw DE,AX
ram:00d8a9 aa06 movw AX,[DE + 0x6]
ram:00d8ab 14 movw DE,AX
ram:00d8ac 8a02 mov A,[DE + 0x2]
ram:00d8ae 72 mov ,A
ram:00d8af af8ac8 movw AX,!0xfc88a
ram:00d8b2 0288c8 addw AX,!0xfc888
ram:00d8b5 14 movw DE,AX
ram:00d8b6 62 mov A,
ram:00d8b7 9a01 mov [DE + 0x1],A
ram:00d8b9 ac04 movw AX,[HL + 0x4]
ram:00d8bb 14 movw DE,AX
ram:00d8bc aa06 movw AX,[DE + 0x6]
ram:00d8be a1 incw AX
ram:00d8bf 14 movw DE,AX
ram:00d8c0 8a02 mov A,[DE + 0x2]
ram:00d8c2 72 mov ,A
ram:00d8c3 af8ac8 movw AX,!0xfc88a
ram:00d8c6 0288c8 addw AX,!0xfc888
ram:00d8c9 14 movw DE,AX
ram:00d8ca 62 mov A,
ram:00d8cb 9a02 mov [DE + 0x2],A
ram:00d8cd ac04 movw AX,[HL + 0x4]
ram:00d8cf 14 movw DE,AX
ram:00d8d0 aa06 movw AX,[DE + 0x6]
ram:00d8d2 a1 incw AX
ram:00d8d3 14 movw DE,AX
ram:00d8d4 8a03 mov A,[DE + 0x3]
ram:00d8d6 72 mov ,A
ram:00d8d7 af8ac8 movw AX,!0xfc88a
ram:00d8da 0288c8 addw AX,!0xfc888
ram:00d8dd 14 movw DE,AX
ram:00d8de 62 mov A,
ram:00d8df 9a03 mov [DE + 0x3],A
ram:00d8e1 ac04 movw AX,[HL + 0x4]
ram:00d8e3 14 movw DE,AX
ram:00d8e4 aa06 movw AX,[DE + 0x6]
ram:00d8e6 a1 incw AX
ram:00d8e7 14 movw DE,AX
ram:00d8e8 8a04 mov A,[DE + 0x4]
ram:00d8ea 72 mov ,A
ram:00d8eb af8ac8 movw AX,!0xfc88a
ram:00d8ee 0288c8 addw AX,!0xfc888
ram:00d8f1 14 movw DE,AX
ram:00d8f2 62 mov A,
ram:00d8f3 9a04 mov [DE + 0x4],A
ram:00d8f5 ac04 movw AX,[HL + 0x4]
ram:00d8f7 14 movw DE,AX
ram:00d8f8 aa06 movw AX,[DE + 0x6]
ram:00d8fa a1 incw AX
ram:00d8fb 14 movw DE,AX
ram:00d8fc 8a05 mov A,[DE + 0x5]
ram:00d8fe 72 mov ,A
ram:00d8ff af8ac8 movw AX,!0xfc88a
ram:00d902 0288c8 addw AX,!0xfc888
ram:00d905 14 movw DE,AX
ram:00d906 62 mov A,
ram:00d907 9a05 mov [DE + 0x5],A
ram:00d909 ac04 movw AX,[HL + 0x4]
ram:00d90b 14 movw DE,AX
ram:00d90c aa06 movw AX,[DE + 0x6]
ram:00d90e a1 incw AX
ram:00d90f 14 movw DE,AX
ram:00d910 8a06 mov A,[DE + 0x6]
ram:00d912 72 mov ,A
ram:00d913 af8ac8 movw AX,!0xfc88a
ram:00d916 0288c8 addw AX,!0xfc888
ram:00d919 14 movw DE,AX
ram:00d91a 62 mov A,
ram:00d91b 9a06 mov [DE + 0x6],A
ram:00d91d af8ac8 movw AX,!0xfc88a
ram:00d920 040700 addw AX,0x7
ram:00d923 bf8ac8 movw !0xfc88a,AX
ram:00d926 8f8ec8 mov A,!0xfc88e
ram:00d929 81 inc 
ram:00d92a 5c0f and A,#0xf
ram:00d92c 348ec8 movw DE,0xc88e
ram:00d92f 70 mov ,A
ram:00d930 89 mov A,[DE]
ram:00d931 5cf0 and A,#0xf0
ram:00d933 6168 or A,
ram:00d935 99 mov [DE],A
ram:00d936 d582c8 cmp0 !0xfc882
ram:00d939 dd1e bz $ 0xd959
ram:00d93b b082c8 dec !0xfc882
ram:00d93e d582c8 cmp0 !0xfc882
ram:00d941 df16 bnz $ 0xd959
ram:00d943 cf83c805 mov !0xfc883,0x5
ram:00d947 30c900 movw AX,0xc9
ram:00d94a bf80c8 movw !0xfc880,AX
ram:00d94d 710084c8 set1 !0xfc884.0x0
ram:00d951 fc7edb00 call !!0xdb7e
ram:00d955 f7 clrw BC
ram:00d956 eeef00 br $! 0xda48
ram:00d959 30c900 movw AX,0xc9
ram:00d95c bf80c8 movw !0xfc880,AX
ram:00d95f cf83c803 mov !0xfc883,0x3
ram:00d963 f7 clrw BC
ram:00d964 eee100 br $! 0xda48
ram:00d967 eedd00 br $! 0xda47
ram:00d96a 4073c802 cmp !0xfc873,0x2
ram:00d96e dd0f bz $ 0xd97f
ram:00d970 4073c806 cmp !0xfc873,0x6
ram:00d974 dd09 bz $ 0xd97f
ram:00d976 4073c807 cmp !0xfc873,0x7
ram:00d97a 61e8 skz
ram:00d97c eec800 _br $! 0xda47
ram:00d97f 8f74c8 mov A,!0xfc874
ram:00d982 31031e bt A.0x0,$ 0xd9a2
ram:00d985 4073c806 cmp !0xfc873,0x6
ram:00d989 dd0c bz $ 0xd997
ram:00d98b 4073c807 cmp !0xfc873,0x7
ram:00d98f df16 bnz $ 0xd9a7
ram:00d991 4072c801 cmp !0xfc872,0x1
ram:00d995 df10 bnz $ 0xd9a7
ram:00d997 f6 clrw AX
ram:00d998 fc558700 call !!0x8755
ram:00d99c f6 clrw AX
ram:00d99d fcd7dc00 call !!0xdcd7
ram:00d9a1 ef04 br $ 0xd9a7
ram:00d9a3 f7 clrw BC
ram:00d9a4 eea100 br $! 0xda48
ram:00d9a7 4073c802 cmp !0xfc873,0x2
ram:00d9ab 61e8 skz
ram:00d9ad ee9400 _br $! 0xda44
ram:00d9b0 ac04 movw AX,[HL + 0x4]
ram:00d9b2 14 movw DE,AX
ram:00d9b3 aa06 movw AX,[DE + 0x6]
ram:00d9b5 14 movw DE,AX
ram:00d9b6 89 mov A,[DE]
ram:00d9b7 2c30 sub A,#0x30
ram:00d9b9 dd08 bz $ 0xd9c3
ram:00d9bb 91 dec 
ram:00d9bc dd6e bz $ 0xda2c
ram:00d9be 91 dec 
ram:00d9bf dd73 bz $ 0xda34
ram:00d9c1 ef7a br $ 0xda3d
ram:00d9c3 8f74c8 mov A,!0xfc874
ram:00d9c6 313353 bt A.0x3,$ 0xda1b
ram:00d9c9 713074c8 set1 !0xfc874.0x3
ram:00d9cd ac04 movw AX,[HL + 0x4]
ram:00d9cf 14 movw DE,AX
ram:00d9d0 aa06 movw AX,[DE + 0x6]
ram:00d9d2 14 movw DE,AX
ram:00d9d3 8a01 mov A,[DE + 0x1]
ram:00d9d5 9f7cc8 mov !0xfc87c,A
ram:00d9d8 ac04 movw AX,[HL + 0x4]
ram:00d9da 14 movw DE,AX
ram:00d9db aa06 movw AX,[DE + 0x6]
ram:00d9dd a1 incw AX
ram:00d9de a1 incw AX
ram:00d9df 14 movw DE,AX
ram:00d9e0 89 mov A,[DE]
ram:00d9e1 318e shrw AX,0x8
ram:00d9e3 bb movw [HL],AX
ram:00d9e4 440500 cmpw AX,0x5
ram:00d9e7 de05 bnc $ 0xd9ee
ram:00d9e9 e57dc8 oneb !0xfc87d
ram:00d9ec ef2e br $ 0xda1c
ram:00d9ee 5180 mov ,0x80
ram:00d9f0 5d and A,[HL]
ram:00d9f1 318e shrw AX,0x8
ram:00d9f3 6168 or A,
ram:00d9f5 dd17 bz $ 0xda0e
ram:00d9f7 ab movw AX,[HL]
ram:00d9f8 44f100 cmpw AX,0xf1
ram:00d9fb dc0b bc $ 0xda08
ram:00d9fd ab movw AX,[HL]
ram:00d9fe 44fa00 cmpw AX,0xfa
ram:00da01 de05 bnc $ 0xda08
ram:00da03 e57dc8 oneb !0xfc87d
ram:00da06 ef14 br $ 0xda1c
ram:00da08 cf7dc81b mov !0xfc87d,0x1b
ram:00da0c ef0e br $ 0xda1c
ram:00da0e ab movw AX,[HL]
ram:00da0f 040400 addw AX,0x4
ram:00da12 5205 mov ,0x5
ram:00da14 fd1c06 call !0xf061c
ram:00da17 a1 incw AX
ram:00da18 60 mov A,
ram:00da19 9f7dc8 mov !0xfc87d,A
ram:00da1c 8f7cc8 mov A,!0xfc87c
ram:00da1f 9f72c8 mov !0xfc872,A
ram:00da22 e6 onew AX
ram:00da23 bf70c8 movw !0xfc870,AX
ram:00da26 cf73c803 mov !0xfc873,0x3
ram:00da2a ef18 br $ 0xda44
ram:00da2c 30c900 movw AX,0xc9
ram:00da2f bf70c8 movw !0xfc870,AX
ram:00da32 ef10 br $ 0xda44
ram:00da34 303200 movw AX,0x32
ram:00da37 fc40d500 call !!0xd540
ram:00da3b ef07 br $ 0xda44
ram:00da3d 302600 movw AX,0x26
ram:00da40 fc40d500 call !!0xd540
ram:00da44 f7 clrw BC
ram:00da45 ef01 br $ 0xda48
ram:00da47 f7 clrw BC
ram:00da48 1006 addw SP,0x6
ram:00da4a c6 pop HL
ram:00da4b d7 ret
ram:00da4c c7 push HL
ram:00da4d c1 push AX
ram:00da4e fbf8ff movw HL,!0xffff8
ram:00da51 f6 clrw AX
ram:00da52 614908 cmpw AX,[HL + 0x8]
ram:00da55 df03 bnz $ 0xda5a
ram:00da57 e7 onew BC
ram:00da58 ef3f br $ 0xda99
ram:00da5a fc3ee000 call !!0xe03e
ram:00da5e d573c8 cmp0 !0xfc873
ram:00da61 dd09 bz $ 0xda6c
ram:00da63 fc62e000 call !!0xe062
ram:00da67 320300 movw BC,0x3
ram:00da6a ef2d br $ 0xda99
ram:00da6c ac08 movw AX,[HL + 0x8]
ram:00da6e 440800 cmpw AX,0x8
ram:00da71 de06 bnc $ 0xda79
ram:00da73 cf73c805 mov !0xfc873,0x5
ram:00da77 ef04 br $ 0xda7d
ram:00da79 cf73c806 mov !0xfc873,0x6
ram:00da7d 30c900 movw AX,0xc9
ram:00da80 bf70c8 movw !0xfc870,AX
ram:00da83 ab movw AX,[HL]
ram:00da84 bf76c8 movw !0xfc876,AX
ram:00da87 f6 clrw AX
ram:00da88 bf78c8 movw !0xfc878,AX
ram:00da8b ac08 movw AX,[HL + 0x8]
ram:00da8d bf7ac8 movw !0xfc87a,AX
ram:00da90 710074c8 set1 !0xfc874.0x0
ram:00da94 fc62e000 call !!0xe062
ram:00da98 f7 clrw BC
ram:00da99 c0 pop AX
ram:00da9a c6 pop HL
ram:00da9b d7 ret
ram:00daa4 c7 push HL
ram:00daa5 2006 subw SP,0x6
ram:00daa7 fbf8ff movw HL,!0xffff8
ram:00daaa d590c8 cmp0 !0xfc890
ram:00daad 61e8 skz
ram:00daaf eec800 _br $! 0xdb7a
ram:00dab2 e590c8 oneb !0xfc890
ram:00dab5 8f74c8 mov A,!0xfc874
ram:00dab8 312533 bf A.0x2,$ 0xdaed
ram:00dabb fc3ee000 call !!0xe03e
ram:00dabf 3070c8 movw AX,0xc870
ram:00dac2 bc04 movw [HL + 0x4],AX
ram:00dac4 14 movw DE,AX
ram:00dac5 8a04 mov A,[DE + 0x4]
ram:00dac7 3159 shl A,0x5
ram:00dac9 317a shr A,0x7
ram:00dacb d1 cmp0 A
ram:00dacc dd19 bz $ 0xdae7
ram:00dace 712874c8 clr1 !0xfc874.0x2
ram:00dad2 fc62e000 call !!0xe062
ram:00dad6 f6 clrw AX
ram:00dad7 fcfb8700 call !!0x87fb
ram:00dadb 62 mov A,
ram:00dadc 9c01 mov [HL + 0x1],A
ram:00dade 91 dec 
ram:00dadf dd0a bz $ 0xdaeb
ram:00dae1 712074c8 set1 !0xfc874.0x2
ram:00dae5 ef04 br $ 0xdaeb
ram:00dae7 fc62e000 call !!0xe062
ram:00daeb ee8900 br $! 0xdb77
ram:00daee 8f74c8 mov A,!0xfc874
ram:00daf1 310303 bt A.0x0,$ 0xdaf6
ram:00daf4 ee8000 br $! 0xdb77
ram:00daf7 fc3ee000 call !!0xe03e
ram:00dafb 3070c8 movw AX,0xc870
ram:00dafe bc04 movw [HL + 0x4],AX
ram:00db00 14 movw DE,AX
ram:00db01 8a04 mov A,[DE + 0x4]
ram:00db03 5c01 and A,#0x1
ram:00db05 d1 cmp0 A
ram:00db06 dd6b bz $ 0xdb73
ram:00db08 4091c8ff cmp !0xfc891,0xff
ram:00db0c df5f bnz $ 0xdb6d
ram:00db0e f591c8 clrb !0xfc891
ram:00db11 710874c8 clr1 !0xfc874.0x0
ram:00db15 fc2bdc00 call !!0xdc2b
ram:00db19 13 movw AX,BC
ram:00db1a bc02 movw [HL + 0x2],AX
ram:00db1c f6 clrw AX
ram:00db1d 614902 cmpw AX,[HL + 0x2]
ram:00db20 df16 bnz $ 0xdb38
ram:00db22 fcfb8700 call !!0x87fb
ram:00db26 62 mov A,
ram:00db27 9c01 mov [HL + 0x1],A
ram:00db29 fc62e000 call !!0xe062
ram:00db2d 8c01 mov A,[HL + 0x1]
ram:00db2f 91 dec 
ram:00db30 dd45 bz $ 0xdb77
ram:00db32 712074c8 set1 !0xfc874.0x2
ram:00db36 ef3f br $ 0xdb77
ram:00db38 4073c807 cmp !0xfc873,0x7
ram:00db3c dd0c bz $ 0xdb4a
ram:00db3e 4073c808 cmp !0xfc873,0x8
ram:00db42 dd06 bz $ 0xdb4a
ram:00db44 4073c806 cmp !0xfc873,0x6
ram:00db48 df15 bnz $ 0xdb5f
ram:00db4a 4073c806 cmp !0xfc873,0x6
ram:00db4e df06 bnz $ 0xdb56
ram:00db50 f6 clrw AX
ram:00db51 bf78c8 movw !0xfc878,AX
ram:00db54 ef09 br $ 0xdb5f
ram:00db56 af78c8 movw AX,!0xfc878
ram:00db59 240700 subw AX,0x7
ram:00db5c bf78c8 movw !0xfc878,AX
ram:00db5f cf91c8ff mov !0xfc891,0xff
ram:00db63 710074c8 set1 !0xfc874.0x0
ram:00db67 fc62e000 call !!0xe062
ram:00db6b ef0a br $ 0xdb77
ram:00db6d fc62e000 call !!0xe062
ram:00db71 ef04 br $ 0xdb77
ram:00db73 fc62e000 call !!0xe062
ram:00db77 f590c8 clrb !0xfc890
ram:00db7a 1006 addw SP,0x6
ram:00db7c c6 pop HL
ram:00db7d d7 ret
ram:00db7e c7 push HL
ram:00db7f 2004 subw SP,0x4
ram:00db81 fbf8ff movw HL,!0xffff8
ram:00db84 d590c8 cmp0 !0xfc890
ram:00db87 61e8 skz
ram:00db89 ee9b00 _br $! 0xdc27
ram:00db8c e590c8 oneb !0xfc890
ram:00db8f 8f84c8 mov A,!0xfc884
ram:00db92 311532 bf A.0x1,$ 0xdbc6
ram:00db95 fc3ee000 call !!0xe03e
ram:00db99 3080c8 movw AX,0xc880
ram:00db9c bc02 movw [HL + 0x2],AX
ram:00db9e 14 movw DE,AX
ram:00db9f 8a04 mov A,[DE + 0x4]
ram:00dba1 3169 shl A,0x6
ram:00dba3 317a shr A,0x7
ram:00dba5 d1 cmp0 A
ram:00dba6 dd19 bz $ 0xdbc1
ram:00dba8 711884c8 clr1 !0xfc884.0x1
ram:00dbac fc62e000 call !!0xe062
ram:00dbb0 f6 clrw AX
ram:00dbb1 fcfb8700 call !!0x87fb
ram:00dbb5 62 mov A,
ram:00dbb6 9c01 mov [HL + 0x1],A
ram:00dbb8 91 dec 
ram:00dbb9 dd0a bz $ 0xdbc5
ram:00dbbb 711084c8 set1 !0xfc884.0x1
ram:00dbbf ef63 br $ 0xdc24
ram:00dbc1 fc62e000 call !!0xe062
ram:00dbc5 ef5d br $ 0xdc24
ram:00dbc7 8f84c8 mov A,!0xfc884
ram:00dbca 310557 bf A.0x0,$ 0xdc23
ram:00dbcd fc3ee000 call !!0xe03e
ram:00dbd1 3080c8 movw AX,0xc880
ram:00dbd4 bc02 movw [HL + 0x2],AX
ram:00dbd6 14 movw DE,AX
ram:00dbd7 8a04 mov A,[DE + 0x4]
ram:00dbd9 5c01 and A,#0x1
ram:00dbdb d1 cmp0 A
ram:00dbdc dd42 bz $ 0xdc20
ram:00dbde 4091c8ff cmp !0xfc891,0xff
ram:00dbe2 df36 bnz $ 0xdc1a
ram:00dbe4 cf91c880 mov !0xfc891,0x80
ram:00dbe8 710884c8 clr1 !0xfc884.0x0
ram:00dbec 4083c806 cmp !0xfc883,0x6
ram:00dbf0 df06 bnz $ 0xdbf8
ram:00dbf2 cf4ac832 mov !0xfc84a,0x32
ram:00dbf6 ef04 br $ 0xdbfc
ram:00dbf8 cf4ac830 mov !0xfc84a,0x30
ram:00dbfc e54bc8 oneb !0xfc84b
ram:00dbff f54cc8 clrb !0xfc84c
ram:00dc02 e582c8 oneb !0xfc882
ram:00dc05 f6 clrw AX
ram:00dc06 fcfb8700 call !!0x87fb
ram:00dc0a 62 mov A,
ram:00dc0b 9c01 mov [HL + 0x1],A
ram:00dc0d 91 dec 
ram:00dc0e 61e8 skz
ram:00dc10 711084c8 _set1 !0xfc884.0x1
ram:00dc14 fc62e000 call !!0xe062
ram:00dc18 ef0a br $ 0xdc24
ram:00dc1a fc62e000 call !!0xe062
ram:00dc1e ef04 br $ 0xdc24
ram:00dc20 fc62e000 call !!0xe062
ram:00dc24 f590c8 clrb !0xfc890
ram:00dc27 1004 addw SP,0x4
ram:00dc29 c6 pop HL
ram:00dc2a d7 ret
ram:00dc2b c7 push HL
ram:00dc2c 200a subw SP,0xa
ram:00dc2e fbf8ff movw HL,!0xffff8
ram:00dc31 af78c8 movw AX,!0xfc878
ram:00dc34 0276c8 addw AX,!0xfc876
ram:00dc37 bc06 movw [HL + 0x6],AX
ram:00dc39 8f73c8 mov A,!0xfc873
ram:00dc3c 2c05 sub A,#0x5
ram:00dc3e dd0a bz $ 0xdc4a
ram:00dc40 91 dec 
ram:00dc41 dd19 bz $ 0xdc5c
ram:00dc43 91 dec 
ram:00dc44 2c02 sub A,#0x2
ram:00dc46 dc47 bc $ 0xdc8f
ram:00dc48 ef7b br $ 0xdcc5
ram:00dc4a 8f7ac8 mov A,!0xfc87a
ram:00dc4d 9f4ac8 mov !0xfc84a,A
ram:00dc50 304bc8 movw AX,0xc84b
ram:00dc53 bc04 movw [HL + 0x4],AX
ram:00dc55 af7ac8 movw AX,!0xfc87a
ram:00dc58 bc08 movw [HL + 0x8],AX
ram:00dc5a ef6c br $ 0xdcc8
ram:00dc5c cf4ac810 mov !0xfc84a,0x10
ram:00dc60 af7ac8 movw AX,!0xfc87a
ram:00dc63 5c0f and A,#0xf
ram:00dc65 f0 clrb X
ram:00dc66 318e shrw AX,0x8
ram:00dc68 344ac8 movw DE,0xc84a
ram:00dc6b 89 mov A,[DE]
ram:00dc6c 6168 or A,
ram:00dc6e 99 mov [DE],A
ram:00dc6f 51ff mov ,0xff
ram:00dc71 5f7ac8 and A,!0xfc87a
ram:00dc74 9a01 mov [DE + 0x1],A
ram:00dc76 304cc8 movw AX,0xc84c
ram:00dc79 bc04 movw [HL + 0x4],AX
ram:00dc7b 300600 movw AX,0x6
ram:00dc7e bc08 movw [HL + 0x8],AX
ram:00dc80 bf78c8 movw !0xfc878,AX
ram:00dc83 347ec8 movw DE,0xc87e
ram:00dc86 89 mov A,[DE]
ram:00dc87 5cf0 and A,#0xf0
ram:00dc89 99 mov [DE],A
ram:00dc8a f572c8 clrb !0xfc872
ram:00dc8d ef39 br $ 0xdcc8
ram:00dc8f cf4ac820 mov !0xfc84a,0x20
ram:00dc93 8f7ec8 mov A,!0xfc87e
ram:00dc96 5c0f and A,#0xf
ram:00dc98 72 mov ,A
ram:00dc99 344ac8 movw DE,0xc84a
ram:00dc9c 89 mov A,[DE]
ram:00dc9d 616a or A,
ram:00dc9f 99 mov [DE],A
ram:00dca0 304bc8 movw AX,0xc84b
ram:00dca3 bc04 movw [HL + 0x4],AX
ram:00dca5 4073c808 cmp !0xfc873,0x8
ram:00dca9 df0a bnz $ 0xdcb5
ram:00dcab af7ac8 movw AX,!0xfc87a
ram:00dcae 2278c8 subw AX,!0xfc878
ram:00dcb1 bc08 movw [HL + 0x8],AX
ram:00dcb3 ef05 br $ 0xdcba
ram:00dcb5 300700 movw AX,0x7
ram:00dcb8 bc08 movw [HL + 0x8],AX
ram:00dcba af78c8 movw AX,!0xfc878
ram:00dcbd 040700 addw AX,0x7
ram:00dcc0 bf78c8 movw !0xfc878,AX
ram:00dcc3 ef03 br $ 0xdcc8
ram:00dcc5 e7 onew BC
ram:00dcc6 ef0b br $ 0xdcd3
ram:00dcc8 17 movw AX,HL
ram:00dcc9 040200 addw AX,0x2
ram:00dccc fc8da400 call !!0xa48d
ram:00dcd0 f3 clrb B
ram:00dcd1 13 movw AX,BC
ram:00dcd2 bb movw [HL],AX
ram:00dcd3 100a addw SP,0xa
ram:00dcd5 c6 pop HL
ram:00dcd6 d7 ret
ram:00dcd7 c7 push HL
ram:00dcd8 16 movw HL,AX
ram:00dcd9 d591c8 cmp0 !0xfc891
ram:00dcdc df06 bnz $ 0xdce4
ram:00dcde fceadc00 call !!0xdcea
ram:00dce2 ef04 br $ 0xdce8
ram:00dce4 fc41dd00 call !!0xdd41
ram:00dce8 c6 pop HL
ram:00dce9 d7 ret
ram:00dcea 8f73c8 mov A,!0xfc873
ram:00dced 2c05 sub A,#0x5
ram:00dcef dd09 bz $ 0xdcfa
ram:00dcf1 91 dec 
ram:00dcf2 dd14 bz $ 0xdd08
ram:00dcf4 91 dec 
ram:00dcf5 dd21 bz $ 0xdd18
ram:00dcf7 91 dec 
ram:00dcf8 df46 bnz $ 0xdd40
ram:00dcfa f6 clrw AX
ram:00dcfb fc97a400 call !!0xa497
ram:00dcff f6 clrw AX
ram:00dd00 bf70c8 movw !0xfc870,AX
ram:00dd03 f573c8 clrb !0xfc873
ram:00dd06 ef34 br $ 0xdd3c
ram:00dd08 30c900 movw AX,0xc9
ram:00dd0b bf70c8 movw !0xfc870,AX
ram:00dd0e cf73c802 mov !0xfc873,0x2
ram:00dd12 713874c8 clr1 !0xfc874.0x3
ram:00dd16 ef24 br $ 0xdd3c
ram:00dd18 d572c8 cmp0 !0xfc872
ram:00dd1b dd14 bz $ 0xdd31
ram:00dd1d b072c8 dec !0xfc872
ram:00dd20 d572c8 cmp0 !0xfc872
ram:00dd23 df0c bnz $ 0xdd31
ram:00dd25 30c900 movw AX,0xc9
ram:00dd28 bf70c8 movw !0xfc870,AX
ram:00dd2b cf73c802 mov !0xfc873,0x2
ram:00dd2f ef0b br $ 0xdd3c
ram:00dd31 d97dc8 mov X,!0xfc87d
ram:00dd34 f1 clrb A
ram:00dd35 bf70c8 movw !0xfc870,AX
ram:00dd38 cf73c803 mov !0xfc873,0x3
ram:00dd3c cf91c8ff mov !0xfc891,0xff
ram:00dd40 d7 ret
ram:00dd41 8f83c8 mov A,!0xfc883
ram:00dd44 2c05 sub A,#0x5
ram:00dd46 dd04 bz $ 0xdd4c
ram:00dd48 91 dec 
ram:00dd49 dd0d bz $ 0xdd58
ram:00dd4b d7 ret
ram:00dd4c 30c900 movw AX,0xc9
ram:00dd4f bf80c8 movw !0xfc880,AX
ram:00dd52 cf83c803 mov !0xfc883,0x3
ram:00dd56 ef07 br $ 0xdd5f
ram:00dd58 f6 clrw AX
ram:00dd59 bf80c8 movw !0xfc880,AX
ram:00dd5c f583c8 clrb !0xfc883
ram:00dd5f cf91c8ff mov !0xfc891,0xff
ram:00dd63 d7 ret
ram:00dd64 8f7ec8 mov A,!0xfc87e
ram:00dd67 81 inc 
ram:00dd68 5c0f and A,#0xf
ram:00dd6a 347ec8 movw DE,0xc87e
ram:00dd6d 70 mov ,A
ram:00dd6e 89 mov A,[DE]
ram:00dd6f 5cf0 and A,#0xf0
ram:00dd71 6168 or A,
ram:00dd73 99 mov [DE],A
ram:00dd74 af78c8 movw AX,!0xfc878
ram:00dd77 040700 addw AX,0x7
ram:00dd7a 427ac8 cmpw AX,!0xfc87a
ram:00dd7d dc06 bc $ 0xdd85
ram:00dd7f cf73c808 mov !0xfc873,0x8
ram:00dd83 ef04 br $ 0xdd89
ram:00dd85 cf73c807 mov !0xfc873,0x7
ram:00dd89 30c900 movw AX,0xc9
ram:00dd8c bf70c8 movw !0xfc870,AX
ram:00dd8f 710074c8 set1 !0xfc874.0x0
ram:00dd93 d7 ret
ram:00dd94 c7 push HL
ram:00dd95 f6 clrw AX
ram:00dd96 4270c8 cmpw AX,!0xfc870
ram:00dd99 dd62 bz $ 0xddfd
ram:00dd9b fc3ee000 call !!0xe03e
ram:00dd9f 3670c8 movw HL,0xc870
ram:00dda2 ab movw AX,[HL]
ram:00dda3 6168 or A,
ram:00dda5 dd52 bz $ 0xddf9
ram:00dda7 b270c8 decw !0xfc870
ram:00ddaa f6 clrw AX
ram:00ddab 4270c8 cmpw AX,!0xfc870
ram:00ddae df3f bnz $ 0xddef
ram:00ddb0 8c03 mov A,[HL + 0x3]
ram:00ddb2 2c02 sub A,#0x2
ram:00ddb4 dd0b bz $ 0xddc1
ram:00ddb6 91 dec 
ram:00ddb7 dd15 bz $ 0xddce
ram:00ddb9 2c02 sub A,#0x2
ram:00ddbb 2c04 sub A,#0x4
ram:00ddbd dc1d bc $ 0xdddc
ram:00ddbf ef28 br $ 0xdde9
ram:00ddc1 302300 movw AX,0x23
ram:00ddc4 fc40d500 call !!0xd540
ram:00ddc8 fc62e000 call !!0xe062
ram:00ddcc ef2f br $ 0xddfd
ram:00ddce fc64dd00 call !!0xdd64
ram:00ddd2 fc62e000 call !!0xe062
ram:00ddd6 fca4da00 call !!0xdaa4
ram:00ddda ef21 br $ 0xddfd
ram:00dddc 302200 movw AX,0x22
ram:00dddf fc40d500 call !!0xd540
ram:00dde3 fc62e000 call !!0xe062
ram:00dde7 ef14 br $ 0xddfd
ram:00dde9 fc62e000 call !!0xe062
ram:00dded ef0e br $ 0xddfd
ram:00ddef fc62e000 call !!0xe062
ram:00ddf3 fca4da00 call !!0xdaa4
ram:00ddf7 ef04 br $ 0xddfd
ram:00ddf9 fc62e000 call !!0xe062
ram:00ddfd c6 pop HL
ram:00ddfe d7 ret
ram:00ddff c7 push HL
ram:00de00 f6 clrw AX
ram:00de01 4280c8 cmpw AX,!0xfc880
ram:00de04 dd51 bz $ 0xde57
ram:00de06 fc3ee000 call !!0xe03e
ram:00de0a 3680c8 movw HL,0xc880
ram:00de0d ab movw AX,[HL]
ram:00de0e 6168 or A,
ram:00de10 dd41 bz $ 0xde53
ram:00de12 b280c8 decw !0xfc880
ram:00de15 f6 clrw AX
ram:00de16 4280c8 cmpw AX,!0xfc880
ram:00de19 df2e bnz $ 0xde49
ram:00de1b 8c03 mov A,[HL + 0x3]
ram:00de1d 2c03 sub A,#0x3
ram:00de1f dd08 bz $ 0xde29
ram:00de21 2c02 sub A,#0x2
ram:00de23 2c02 sub A,#0x2
ram:00de25 dc0f bc $ 0xde36
ram:00de27 ef1a br $ 0xde43
ram:00de29 300300 movw AX,0x3
ram:00de2c fc9ed500 call !!0xd59e
ram:00de30 fc62e000 call !!0xe062
ram:00de34 ef21 br $ 0xde57
ram:00de36 300400 movw AX,0x4
ram:00de39 fc9ed500 call !!0xd59e
ram:00de3d fc62e000 call !!0xe062
ram:00de41 ef14 br $ 0xde57
ram:00de43 fc62e000 call !!0xe062
ram:00de47 ef0e br $ 0xde57
ram:00de49 fc62e000 call !!0xe062
ram:00de4d fc7edb00 call !!0xdb7e
ram:00de51 ef04 br $ 0xde57
ram:00de53 fc62e000 call !!0xe062
ram:00de57 c6 pop HL
ram:00de58 d7 ret
ram:00de62 300700 movw AX,0x7
ram:00de65 ec9ed500 br !!0xd59e
ram:00de6d c7 push HL
ram:00de6e 16 movw HL,AX
ram:00de6f 66 mov A,
ram:00de70 5c03 and A,#0x3
ram:00de72 348fc8 movw DE,0xc88f
ram:00de75 70 mov ,A
ram:00de76 89 mov A,[DE]
ram:00de77 5cfc and A,#0xfc
ram:00de79 6168 or A,
ram:00de7b 99 mov [DE],A
ram:00de7c c6 pop HL
ram:00de7d d7 ret
ram:00de8e f592c8 clrb !0xfc892
ram:00de91 f6 clrw AX
ram:00de92 bf94c8 movw !0xfc894,AX
ram:00de95 d7 ret
ram:00deb2 c7 push HL
ram:00deb3 c1 push AX
ram:00deb4 fbf8ff movw HL,!0xffff8
ram:00deb7 f6 clrw AX
ram:00deb8 614908 cmpw AX,[HL + 0x8]
ram:00debb dd0e bz $ 0xdecb
ram:00debd 618908 decw [HL + 0x8]
ram:00dec0 ac08 movw AX,[HL + 0x8]
ram:00dec2 610900 addw AX,[HL + 0x0]
ram:00dec5 14 movw DE,AX
ram:00dec6 ca0000 mov [DE + 0x0],0x0
ram:00dec9 efec br $ 0xdeb7
ram:00decb c0 pop AX
ram:00decc c6 pop HL
ram:00decd d7 ret
ram:00def1 c7 push HL
ram:00def2 c1 push AX
ram:00def3 fbf8ff movw HL,!0xffff8
ram:00def6 f6 clrw AX
ram:00def7 61490c cmpw AX,[HL + 0xc]
ram:00defa dd1a bz $ 0xdf16
ram:00defc 61890c decw [HL + 0xc]
ram:00deff ac0c movw AX,[HL + 0xc]
ram:00df01 610908 addw AX,[HL + 0x8]
ram:00df04 14 movw DE,AX
ram:00df05 8c0a mov A,[HL + 0xa]
ram:00df07 9efd mov ES,A
ram:00df09 1189 mov A,ES:[DE]
ram:00df0b 72 mov ,A
ram:00df0c ac0c movw AX,[HL + 0xc]
ram:00df0e 610900 addw AX,[HL + 0x0]
ram:00df11 14 movw DE,AX
ram:00df12 62 mov A,
ram:00df13 99 mov [DE],A
ram:00df14 efe0 br $ 0xdef6
ram:00df16 c0 pop AX
ram:00df17 c6 pop HL
ram:00df18 d7 ret
ram:00e03e c7 push HL
ram:00e03f c1 push AX
ram:00e040 fbf8ff movw HL,!0xffff8
ram:00e043 f6 clrw AX
ram:00e044 4294c8 cmpw AX,!0xfc894
ram:00e047 61e8 skz
ram:00e049 ec5ce000 _br !!0xe05c
ram:00e04d fc80e000 call !!0xe080
ram:00e051 62 mov A,
ram:00e052 9c01 mov [HL + 0x1],A
ram:00e054 717bfa DI
ram:00e057 8c01 mov A,[HL + 0x1]
ram:00e059 9f92c8 mov !0xfc892,A
ram:00e05c a294c8 incw !0xfc894
ram:00e05f c0 pop AX
ram:00e060 c6 pop HL
ram:00e061 d7 ret
ram:00e062 c7 push HL
ram:00e063 c1 push AX
ram:00e064 fbf8ff movw HL,!0xffff8
ram:00e067 b294c8 decw !0xfc894
ram:00e06a f6 clrw AX
ram:00e06b 4294c8 cmpw AX,!0xfc894
ram:00e06e df0d bnz $ 0xe07d
ram:00e070 8f92c8 mov A,!0xfc892
ram:00e073 9c01 mov [HL + 0x1],A
ram:00e075 8c01 mov A,[HL + 0x1]
ram:00e077 318e shrw AX,0x8
ram:00e079 fc85e000 call !!0xe085
ram:00e07d c0 pop AX
ram:00e07e c6 pop HL
ram:00e07f d7 ret
ram:00e080 8efa mov A,PSW
ram:00e082 72 mov ,A
ram:00e083 f3 clrb B
ram:00e084 d7 ret
ram:00e085 c7 push HL
ram:00e086 16 movw HL,AX
ram:00e087 60 mov A,
ram:00e088 9efa mov PSW,A
ram:00e08a c6 pop HL
ram:00e08b d7 ret
ram:00e08c 7150f000 set1 !0xf00f0.0x5
ram:00e090 8f4002 mov A,!0xf0240
ram:00e093 5c9f and A,#0x9f
ram:00e095 9f4002 mov !0xf0240,A
ram:00e098 717ae5 set1 0xfffe5.0x7
ram:00e09b 717be1 clr1 0xfffe1.0x7
ram:00e09e 710ae6 set1 0xfffe6.0x0
ram:00e0a1 710be2 clr1 0xfffe2.0x0
ram:00e0a4 711ae6 set1 0xfffe6.0x1
ram:00e0a7 711be2 clr1 0xfffe2.0x1
ram:00e0aa 717aed set1 0xfffed.0x7
ram:00e0ad 717ae9 set1 0xfffe9.0x7
ram:00e0b0 710aee set1 0xfffee.0x0
ram:00e0b3 710aea set1 0xfffea.0x0
ram:00e0b6 711aee set1 0xfffee.0x1
ram:00e0b9 711aea set1 0xfffea.0x1
ram:00e0bc 303901 movw AX,0x139
ram:00e0bf bf4202 movw !0xf0242,AX
ram:00e0c2 cf410214 mov !0xf0241,0x14
ram:00e0c6 f54402 clrb !0xf0244
ram:00e0c9 cf450202 mov !0xf0245,0x2
ram:00e0cd cf400212 mov !0xf0240,0x12
ram:00e0d1 6a0108 or 0xffe21,#0x8
ram:00e0d4 8e21 mov A,0xfff21
ram:00e0d6 5cf7 and A,#0xf7
ram:00e0d8 9e21 mov 0xfff21,A
ram:00e0da 8e21 mov A,0xfff21
ram:00e0dc 6c10 or A,#0x10
ram:00e0de 9e21 mov 0xfff21,A
ram:00e0e0 717be1 clr1 0xfffe1.0x7
ram:00e0e3 717be5 clr1 0xfffe5.0x7
ram:00e0e6 710be2 clr1 0xfffe2.0x0
ram:00e0e9 710be6 clr1 0xfffe6.0x0
ram:00e0ec 711be2 clr1 0xfffe2.0x1
ram:00e0ef 711be6 clr1 0xfffe6.0x1
ram:00e0f2 8f4002 mov A,!0xf0240
ram:00e0f5 6c60 or A,#0x60
ram:00e0f7 9f4002 mov !0xf0240,A
ram:00e0fa e5ede5 oneb !0xfe5ed
ram:00e0fd d7 ret
ram:00e0fe f5ede5 clrb !0xfe5ed
ram:00e101 8f4002 mov A,!0xf0240
ram:00e104 5c9f and A,#0x9f
ram:00e106 9f4002 mov !0xf0240,A
ram:00e109 717ae5 set1 0xfffe5.0x7
ram:00e10c 717be1 clr1 0xfffe1.0x7
ram:00e10f 710ae6 set1 0xfffe6.0x0
ram:00e112 710be2 clr1 0xfffe2.0x0
ram:00e115 711ae6 set1 0xfffe6.0x1
ram:00e118 711be2 clr1 0xfffe2.0x1
ram:00e11b 7158f000 clr1 !0xf00f0.0x5
ram:00e11f d7 ret
ram:00e120 7130f100 set1 !0xf00f1.0x3
ram:00e124 00 nop
ram:00e125 00 nop
ram:00e126 00 nop
ram:00e127 00 nop
ram:00e128 f6 clrw AX
ram:00e129 bf7601 movw !0xf0176,AX
ram:00e12c af7401 movw AX,!0xf0174
ram:00e12f 08 xch A,X
ram:00e130 6c03 or A,#0x3
ram:00e132 08 xch A,X
ram:00e133 bf7401 movw !0xf0174,AX
ram:00e136 717ad5 set1 0xfffd5.0x7
ram:00e139 717bd1 clr1 0xfffd1.0x7
ram:00e13c 716ad5 set1 0xfffd5.0x6
ram:00e13f 716bd1 clr1 0xfffd1.0x6
ram:00e142 717bdd clr1 0xfffdd.0x7
ram:00e145 717bd9 clr1 0xfffd9.0x7
ram:00e148 716add set1 0xfffdd.0x6
ram:00e14b 716ad9 set1 0xfffd9.0x6
ram:00e14e 300700 movw AX,0x7
ram:00e151 bf6601 movw !0xf0166,AX
ram:00e154 8f6000 mov A,!0xf0060
ram:00e157 6c10 or A,#0x10
ram:00e159 9f6000 mov !0xf0060,A
ram:00e15c 302201 movw AX,0x122
ram:00e15f bf6a01 movw !0xf016a,AX
ram:00e162 309744 movw AX,0x4497
ram:00e165 bf6e01 movw !0xf016e,AX
ram:00e168 cb46004e movw 0xfff46,0x4e00
ram:00e16c 302200 movw AX,0x22
ram:00e16f bf6801 movw !0xf0168,AX
ram:00e172 309780 movw AX,0x8097
ram:00e175 bf6c01 movw !0xf016c,AX
ram:00e178 cb44004e movw 0xfff44,0x4e00
ram:00e17c f6 clrw AX
ram:00e17d bf5801 movw !0xf0158,AX
ram:00e180 af7801 movw AX,!0xf0178
ram:00e183 08 xch A,X
ram:00e184 6c01 or A,#0x1
ram:00e186 08 xch A,X
ram:00e187 bf7801 movw !0xf0178,AX
ram:00e18a af7a01 movw AX,!0xf017a
ram:00e18d 08 xch A,X
ram:00e18e 6c01 or A,#0x1
ram:00e190 08 xch A,X
ram:00e191 bf7a01 movw !0xf017a,AX
ram:00e194 717bd1 clr1 0xfffd1.0x7
ram:00e197 717bd5 clr1 0xfffd5.0x7
ram:00e19a 716bd1 clr1 0xfffd1.0x6
ram:00e19d 716bd5 clr1 0xfffd5.0x6
ram:00e1a0 af7a01 movw AX,!0xf017a
ram:00e1a3 08 xch A,X
ram:00e1a4 6c01 or A,#0x1
ram:00e1a6 08 xch A,X
ram:00e1a7 bf7a01 movw !0xf017a,AX
ram:00e1aa af7201 movw AX,!0xf0172
ram:00e1ad 08 xch A,X
ram:00e1ae 6c03 or A,#0x3
ram:00e1b0 08 xch A,X
ram:00e1b1 bf7201 movw !0xf0172,AX
ram:00e1b4 e5ece5 oneb !0xfe5ec
ram:00e1b7 d7 ret
ram:00e1b8 af7401 movw AX,!0xf0174
ram:00e1bb 08 xch A,X
ram:00e1bc 6c03 or A,#0x3
ram:00e1be 08 xch A,X
ram:00e1bf bf7401 movw !0xf0174,AX
ram:00e1c2 af7a01 movw AX,!0xf017a
ram:00e1c5 08 xch A,X
ram:00e1c6 5cfe and A,#0xfe
ram:00e1c8 08 xch A,X
ram:00e1c9 bf7a01 movw !0xf017a,AX
ram:00e1cc 717ad5 set1 0xfffd5.0x7
ram:00e1cf 717bd1 clr1 0xfffd1.0x7
ram:00e1d2 716ad5 set1 0xfffd5.0x6
ram:00e1d5 716bd1 clr1 0xfffd1.0x6
ram:00e1d8 7138f100 clr1 !0xf00f1.0x3
ram:00e1dc f5ece5 clrb !0xfe5ec
ram:00e1df d7 ret
ram:00e1e0 c7 push HL
ram:00e1e1 c1 push AX
ram:00e1e2 2008 subw SP,0x8
ram:00e1e4 fbf8ff movw HL,!0xffff8
ram:00e1e7 ac12 movw AX,[HL + 0x12]
ram:00e1e9 bc04 movw [HL + 0x4],AX
ram:00e1eb ac10 movw AX,[HL + 0x10]
ram:00e1ed bb movw [HL],AX
ram:00e1ee 8c08 mov A,[HL + 0x8]
ram:00e1f0 73 mov ,A
ram:00e1f1 09ece5 mov A,!0xfe5ec[B]
ram:00e1f4 d1 cmp0 A
ram:00e1f5 61f8 sknz
ram:00e1f7 ee1c01 _br $! 0xe316
ram:00e1fa 3060ea movw AX,0xea60
ram:00e1fd bc06 movw [HL + 0x6],AX
ram:00e1ff f6 clrw AX
ram:00e200 614906 cmpw AX,[HL + 0x6]
ram:00e203 dd1e bz $ 0xe223
ram:00e205 00 nop
ram:00e206 00 nop
ram:00e207 00 nop
ram:00e208 00 nop
ram:00e209 00 nop
ram:00e20a 00 nop
ram:00e20b 00 nop
ram:00e20c 00 nop
ram:00e20d 00 nop
ram:00e20e 00 nop
ram:00e20f ceabac mov 0xfffab,0xac
ram:00e212 8c08 mov A,[HL + 0x8]
ram:00e214 5046 mov ,0x46
ram:00e216 d6 mulu X
ram:00e217 12 movw BC,AX
ram:00e218 49dac8 mov A,!0xfc8da[BC]
ram:00e21b d1 cmp0 A
ram:00e21c dd05 bz $ 0xe223
ram:00e21e 618906 decw [HL + 0x6]
ram:00e221 efdc br $ 0xe1ff
ram:00e223 f6 clrw AX
ram:00e224 614906 cmpw AX,[HL + 0x6]
ram:00e227 df0c bnz $ 0xe235
ram:00e229 8c08 mov A,[HL + 0x8]
ram:00e22b 5046 mov ,0x46
ram:00e22d d6 mulu X
ram:00e22e 0496c8 addw AX,0xc896
ram:00e231 14 movw DE,AX
ram:00e232 ca4400 mov [DE + 0x44],0x0
ram:00e235 ac04 movw AX,[HL + 0x4]
ram:00e237 444100 cmpw AX,0x41
ram:00e23a dc07 bc $ 0xe243
ram:00e23c 304000 movw AX,0x40
ram:00e23f bc02 movw [HL + 0x2],AX
ram:00e241 ef04 br $ 0xe247
ram:00e243 ac04 movw AX,[HL + 0x4]
ram:00e245 bc02 movw [HL + 0x2],AX
ram:00e247 8c08 mov A,[HL + 0x8]
ram:00e249 d1 cmp0 A
ram:00e24a df05 bnz $ 0xe251
ram:00e24c 716ad5 set1 0xfffd5.0x6
ram:00e24f ef03 br $ 0xe254
ram:00e251 717ae5 set1 0xfffe5.0x7
ram:00e254 f6 clrw AX
ram:00e255 bc06 movw [HL + 0x6],AX
ram:00e257 ac06 movw AX,[HL + 0x6]
ram:00e259 614902 cmpw AX,[HL + 0x2]
ram:00e25c de1b bnc $ 0xe279
ram:00e25e ab movw AX,[HL]
ram:00e25f a1 incw AX
ram:00e260 bb movw [HL],AX
ram:00e261 b1 decw AX
ram:00e262 14 movw DE,AX
ram:00e263 89 mov A,[DE]
ram:00e264 72 mov ,A
ram:00e265 8c08 mov A,[HL + 0x8]
ram:00e267 5046 mov ,0x46
ram:00e269 d6 mulu X
ram:00e26a 0496c8 addw AX,0xc896
ram:00e26d 14 movw DE,AX
ram:00e26e ac06 movw AX,[HL + 0x6]
ram:00e270 05 addw AX,DE
ram:00e271 14 movw DE,AX
ram:00e272 62 mov A,
ram:00e273 99 mov [DE],A
ram:00e274 617906 incw [HL + 0x6]
ram:00e277 efde br $ 0xe257
ram:00e279 8c08 mov A,[HL + 0x8]
ram:00e27b 5046 mov ,0x46
ram:00e27d d6 mulu X
ram:00e27e 0496c8 addw AX,0xc896
ram:00e281 14 movw DE,AX
ram:00e282 8c08 mov A,[HL + 0x8]
ram:00e284 5046 mov ,0x46
ram:00e286 d6 mulu X
ram:00e287 0496c8 addw AX,0xc896
ram:00e28a 12 movw BC,AX
ram:00e28b 15 movw AX,DE
ram:00e28c c3 push BC
ram:00e28d c4 pop DE
ram:00e28e ba40 movw [DE + 0x40],AX
ram:00e290 8c08 mov A,[HL + 0x8]
ram:00e292 5046 mov ,0x46
ram:00e294 d6 mulu X
ram:00e295 0496c8 addw AX,0xc896
ram:00e298 14 movw DE,AX
ram:00e299 ac02 movw AX,[HL + 0x2]
ram:00e29b ba42 movw [DE + 0x42],AX
ram:00e29d 8c08 mov A,[HL + 0x8]
ram:00e29f 5046 mov ,0x46
ram:00e2a1 d6 mulu X
ram:00e2a2 0496c8 addw AX,0xc896
ram:00e2a5 14 movw DE,AX
ram:00e2a6 ca4401 mov [DE + 0x44],0x1
ram:00e2a9 8c08 mov A,[HL + 0x8]
ram:00e2ab d1 cmp0 A
ram:00e2ac df15 bnz $ 0xe2c3
ram:00e2ae 8c08 mov A,[HL + 0x8]
ram:00e2b0 5046 mov ,0x46
ram:00e2b2 d6 mulu X
ram:00e2b3 0496c8 addw AX,0xc896
ram:00e2b6 14 movw DE,AX
ram:00e2b7 aa40 movw AX,[DE + 0x40]
ram:00e2b9 a1 incw AX
ram:00e2ba ba40 movw [DE + 0x40],AX
ram:00e2bc b1 decw AX
ram:00e2bd 14 movw DE,AX
ram:00e2be 89 mov A,[DE]
ram:00e2bf 9e44 mov 0xfff44,A
ram:00e2c1 ef13 br $ 0xe2d6
ram:00e2c3 8c08 mov A,[HL + 0x8]
ram:00e2c5 5046 mov ,0x46
ram:00e2c7 d6 mulu X
ram:00e2c8 0496c8 addw AX,0xc896
ram:00e2cb 14 movw DE,AX
ram:00e2cc aa40 movw AX,[DE + 0x40]
ram:00e2ce a1 incw AX
ram:00e2cf ba40 movw [DE + 0x40],AX
ram:00e2d1 b1 decw AX
ram:00e2d2 14 movw DE,AX
ram:00e2d3 89 mov A,[DE]
ram:00e2d4 9e48 mov 0xfff48,A
ram:00e2d6 8c08 mov A,[HL + 0x8]
ram:00e2d8 5046 mov ,0x46
ram:00e2da d6 mulu X
ram:00e2db 0496c8 addw AX,0xc896
ram:00e2de 14 movw DE,AX
ram:00e2df aa42 movw AX,[DE + 0x42]
ram:00e2e1 b1 decw AX
ram:00e2e2 ba42 movw [DE + 0x42],AX
ram:00e2e4 8c08 mov A,[HL + 0x8]
ram:00e2e6 d1 cmp0 A
ram:00e2e7 df05 bnz $ 0xe2ee
ram:00e2e9 716bd5 clr1 0xfffd5.0x6
ram:00e2ec ef03 br $ 0xe2f1
ram:00e2ee 717be5 clr1 0xfffe5.0x7
ram:00e2f1 ac04 movw AX,[HL + 0x4]
ram:00e2f3 612902 subw AX,[HL + 0x2]
ram:00e2f6 bc04 movw [HL + 0x4],AX
ram:00e2f8 f6 clrw AX
ram:00e2f9 614904 cmpw AX,[HL + 0x4]
ram:00e2fc dd0f bz $ 0xe30d
ram:00e2fe 8c08 mov A,[HL + 0x8]
ram:00e300 5046 mov ,0x46
ram:00e302 d6 mulu X
ram:00e303 12 movw BC,AX
ram:00e304 49dac8 mov A,!0xfc8da[BC]
ram:00e307 91 dec 
ram:00e308 df03 bnz $ 0xe30d
ram:00e30a 00 nop
ram:00e30b efeb br $ 0xe2f8
ram:00e30d f6 clrw AX
ram:00e30e 614904 cmpw AX,[HL + 0x4]
ram:00e311 61e8 skz
ram:00e313 ee1fff _br $! 0xe235
ram:00e316 100a addw SP,0xa
ram:00e318 c6 pop HL
ram:00e319 d7 ret
ram:00e31a c7 push HL
ram:00e31b 16 movw HL,AX
ram:00e31c 66 mov A,
ram:00e31d d1 cmp0 A
ram:00e31e df06 bnz $ 0xe326
ram:00e320 fc20e100 call !!0xe120
ram:00e324 ef04 br $ 0xe32a
ram:00e326 fc8ce000 call !!0xe08c
ram:00e32a 66 mov A,
ram:00e32b 5046 mov ,0x46
ram:00e32d d6 mulu X
ram:00e32e 0496c8 addw AX,0xc896
ram:00e331 14 movw DE,AX
ram:00e332 ca4400 mov [DE + 0x44],0x0
ram:00e335 c6 pop HL
ram:00e336 d7 ret
ram:00e337 c7 push HL
ram:00e338 16 movw HL,AX
ram:00e339 66 mov A,
ram:00e33a d1 cmp0 A
ram:00e33b df06 bnz $ 0xe343
ram:00e33d fcb8e100 call !!0xe1b8
ram:00e341 ef04 br $ 0xe347
ram:00e343 fcfee000 call !!0xe0fe
ram:00e347 c6 pop HL
ram:00e348 d7 ret
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
ram:00e366 c7 push HL
ram:00e367 8f62d9 mov A,!0xfd962
ram:00e36a 76 mov ,A
ram:00e36b f563d9 clrb !0xfd963
ram:00e36e 66 mov A,
ram:00e36f 4c40 cmp A,#0x40
ram:00e371 de0d bnc $ 0xe380
ram:00e373 73 mov ,A
ram:00e374 0922c9 mov A,!0xfc922[B]
ram:00e377 d1 cmp0 A
ram:00e378 df06 bnz $ 0xe380
ram:00e37a 86 inc 
ram:00e37b a063d9 inc !0xfd963
ram:00e37e efee br $ 0xe36e
ram:00e380 c6 pop HL
ram:00e381 d7 ret
ram:00e382 c7 push HL
ram:00e383 c1 push AX
ram:00e384 2006 subw SP,0x6
ram:00e386 fbf8ff movw HL,!0xffff8
ram:00e389 f6 clrw AX
ram:00e38a bc04 movw [HL + 0x4],AX
ram:00e38c ac06 movw AX,[HL + 0x6]
ram:00e38e 044000 addw AX,0x40
ram:00e391 b1 decw AX
ram:00e392 316e shrw AX,0x6
ram:00e394 60 mov A,
ram:00e395 9c02 mov [HL + 0x2],A
ram:00e397 f6 clrw AX
ram:00e398 614906 cmpw AX,[HL + 0x6]
ram:00e39b dd07 bz $ 0xe3a4
ram:00e39d ac06 movw AX,[HL + 0x6]
ram:00e39f 440110 cmpw AX,0x1001
ram:00e3a2 dc04 bc $ 0xe3a8
ram:00e3a4 f7 clrw BC
ram:00e3a5 ee1e01 br $! 0xe4c6
ram:00e3a8 4062d9ff cmp !0xfd962,0xff
ram:00e3ac df04 bnz $ 0xe3b2
ram:00e3ae f7 clrw BC
ram:00e3af ee1401 br $! 0xe4c6
ram:00e3b2 8f63d9 mov A,!0xfd963
ram:00e3b5 4e02 cmp A,[HL + 0x2]
ram:00e3b7 61c8 skc
ram:00e3b9 ee9300 _br $! 0xe44f
ram:00e3bc 8f62d9 mov A,!0xfd962
ram:00e3bf 9c01 mov [HL + 0x1],A
ram:00e3c1 8f63d9 mov A,!0xfd963
ram:00e3c4 9b mov [HL],A
ram:00e3c5 cc0300 mov [HL + 0x3],0x0
ram:00e3c8 8c03 mov A,[HL + 0x3]
ram:00e3ca 4c40 cmp A,#0x40
ram:00e3cc de6f bnc $ 0xe43d
ram:00e3ce 8c03 mov A,[HL + 0x3]
ram:00e3d0 4c40 cmp A,#0x40
ram:00e3d2 de17 bnc $ 0xe3eb
ram:00e3d4 e962d9 mov B,!0xfd962
ram:00e3d7 0922c9 mov A,!0xfc922[B]
ram:00e3da d1 cmp0 A
ram:00e3db df0e bnz $ 0xe3eb
ram:00e3dd 8f62d9 mov A,!0xfd962
ram:00e3e0 81 inc 
ram:00e3e1 5c3f and A,#0x3f
ram:00e3e3 9f62d9 mov !0xfd962,A
ram:00e3e6 615903 inc [HL + 0x3]
ram:00e3e9 efe3 br $ 0xe3ce
ram:00e3eb 8c03 mov A,[HL + 0x3]
ram:00e3ed 4c40 cmp A,#0x40
ram:00e3ef df0c bnz $ 0xe3fd
ram:00e3f1 cc0300 mov [HL + 0x3],0x0
ram:00e3f4 f562d9 clrb !0xfd962
ram:00e3f7 cf63d940 mov !0xfd963,0x40
ram:00e3fb ef40 br $ 0xe43d
ram:00e3fd 8c03 mov A,[HL + 0x3]
ram:00e3ff 4c40 cmp A,#0x40
ram:00e401 de17 bnc $ 0xe41a
ram:00e403 e962d9 mov B,!0xfd962
ram:00e406 0922c9 mov A,!0xfc922[B]
ram:00e409 d1 cmp0 A
ram:00e40a dd0e bz $ 0xe41a
ram:00e40c 8f62d9 mov A,!0xfd962
ram:00e40f 81 inc 
ram:00e410 5c3f and A,#0x3f
ram:00e412 9f62d9 mov !0xfd962,A
ram:00e415 615903 inc [HL + 0x3]
ram:00e418 efe3 br $ 0xe3fd
ram:00e41a 8c03 mov A,[HL + 0x3]
ram:00e41c 4c40 cmp A,#0x40
ram:00e41e df0d bnz $ 0xe42d
ram:00e420 8c01 mov A,[HL + 0x1]
ram:00e422 9f62d9 mov !0xfd962,A
ram:00e425 8b mov A,[HL]
ram:00e426 9f63d9 mov !0xfd963,A
ram:00e429 f7 clrw BC
ram:00e42a ee9900 br $! 0xe4c6
ram:00e42d fc66e300 call !!0xe366
ram:00e431 8f63d9 mov A,!0xfd963
ram:00e434 4e02 cmp A,[HL + 0x2]
ram:00e436 de05 bnc $ 0xe43d
ram:00e438 615903 inc [HL + 0x3]
ram:00e43b ef8b br $ 0xe3c8
ram:00e43d 8c03 mov A,[HL + 0x3]
ram:00e43f 4c40 cmp A,#0x40
ram:00e441 df0c bnz $ 0xe44f
ram:00e443 8c01 mov A,[HL + 0x1]
ram:00e445 9f62d9 mov !0xfd962,A
ram:00e448 8b mov A,[HL]
ram:00e449 9f63d9 mov !0xfd963,A
ram:00e44c f7 clrw BC
ram:00e44d ef77 br $ 0xe4c6
ram:00e44f 8f62d9 mov A,!0xfd962
ram:00e452 f0 clrb X
ram:00e453 312e shrw AX,0x2
ram:00e455 0462c9 addw AX,0xc962
ram:00e458 bc04 movw [HL + 0x4],AX
ram:00e45a e962d9 mov B,!0xfd962
ram:00e45d 8c02 mov A,[HL + 0x2]
ram:00e45f 1822c9 mov !0xfc922[B],A
ram:00e462 cc0301 mov [HL + 0x3],0x1
ram:00e465 8c03 mov A,[HL + 0x3]
ram:00e467 4e02 cmp A,[HL + 0x2]
ram:00e469 de0f bnc $ 0xe47a
ram:00e46b 8f62d9 mov A,!0xfd962
ram:00e46e 0e03 add A,[HL + 0x3]
ram:00e470 72 mov ,A
ram:00e471 3822c9ff mov !0xfc922[C],0xff
ram:00e475 615903 inc [HL + 0x3]
ram:00e478 efeb br $ 0xe465
ram:00e47a 8f63d9 mov A,!0xfd963
ram:00e47d 4e02 cmp A,[HL + 0x2]
ram:00e47f df32 bnz $ 0xe4b3
ram:00e481 cc0300 mov [HL + 0x3],0x0
ram:00e484 8c03 mov A,[HL + 0x3]
ram:00e486 4c40 cmp A,#0x40
ram:00e488 de17 bnc $ 0xe4a1
ram:00e48a e962d9 mov B,!0xfd962
ram:00e48d 0922c9 mov A,!0xfc922[B]
ram:00e490 d1 cmp0 A
ram:00e491 dd0e bz $ 0xe4a1
ram:00e493 8f62d9 mov A,!0xfd962
ram:00e496 81 inc 
ram:00e497 5c3f and A,#0x3f
ram:00e499 9f62d9 mov !0xfd962,A
ram:00e49c 615903 inc [HL + 0x3]
ram:00e49f efe3 br $ 0xe484
ram:00e4a1 8c03 mov A,[HL + 0x3]
ram:00e4a3 4c40 cmp A,#0x40
ram:00e4a5 df06 bnz $ 0xe4ad
ram:00e4a7 cf62d9ff mov !0xfd962,0xff
ram:00e4ab ef12 br $ 0xe4bf
ram:00e4ad fc66e300 call !!0xe366
ram:00e4b1 ef0c br $ 0xe4bf
ram:00e4b3 3463d9 movw DE,0xd963
ram:00e4b6 89 mov A,[DE]
ram:00e4b7 2e02 sub A,[HL + 0x2]
ram:00e4b9 99 mov [DE],A
ram:00e4ba b5 decw DE
ram:00e4bb 89 mov A,[DE]
ram:00e4bc 0e02 add A,[HL + 0x2]
ram:00e4be 99 mov [DE],A
ram:00e4bf f6 clrw AX
ram:00e4c0 614904 cmpw AX,[HL + 0x4]
ram:00e4c3 ac04 movw AX,[HL + 0x4]
ram:00e4c5 12 movw BC,AX
ram:00e4c6 1008 addw SP,0x8
ram:00e4c8 c6 pop HL
ram:00e4c9 d7 ret
ram:00e4ca c7 push HL
ram:00e4cb c1 push AX
ram:00e4cc 2004 subw SP,0x4
ram:00e4ce fbf8ff movw HL,!0xffff8
ram:00e4d1 f6 clrw AX
ram:00e4d2 614904 cmpw AX,[HL + 0x4]
ram:00e4d5 dd65 bz $ 0xe53c
ram:00e4d7 cc0300 mov [HL + 0x3],0x0
ram:00e4da 8c03 mov A,[HL + 0x3]
ram:00e4dc 4c40 cmp A,#0x40
ram:00e4de de5c bnc $ 0xe53c
ram:00e4e0 8c03 mov A,[HL + 0x3]
ram:00e4e2 f0 clrb X
ram:00e4e3 312e shrw AX,0x2
ram:00e4e5 0462c9 addw AX,0xc962
ram:00e4e8 614904 cmpw AX,[HL + 0x4]
ram:00e4eb df4a bnz $ 0xe537
ram:00e4ed 8c03 mov A,[HL + 0x3]
ram:00e4ef 73 mov ,A
ram:00e4f0 0922c9 mov A,!0xfc922[B]
ram:00e4f3 81 inc 
ram:00e4f4 df0e bnz $ 0xe504
ram:00e4f6 8c03 mov A,[HL + 0x3]
ram:00e4f8 73 mov ,A
ram:00e4f9 0922c9 mov A,!0xfc922[B]
ram:00e4fc 81 inc 
ram:00e4fd df05 bnz $ 0xe504
ram:00e4ff 616903 dec [HL + 0x3]
ram:00e502 eff2 br $ 0xe4f6
ram:00e504 8c03 mov A,[HL + 0x3]
ram:00e506 73 mov ,A
ram:00e507 0922c9 mov A,!0xfc922[B]
ram:00e50a 9c01 mov [HL + 0x1],A
ram:00e50c d1 cmp0 A
ram:00e50d dd2d bz $ 0xe53c
ram:00e50f cc0200 mov [HL + 0x2],0x0
ram:00e512 8c02 mov A,[HL + 0x2]
ram:00e514 4e01 cmp A,[HL + 0x1]
ram:00e516 de0e bnc $ 0xe526
ram:00e518 8c03 mov A,[HL + 0x3]
ram:00e51a 0e02 add A,[HL + 0x2]
ram:00e51c 72 mov ,A
ram:00e51d 3822c900 mov !0xfc922[C],0x0
ram:00e521 615902 inc [HL + 0x2]
ram:00e524 efec br $ 0xe512
ram:00e526 4062d9ff cmp !0xfd962,0xff
ram:00e52a df10 bnz $ 0xe53c
ram:00e52c 8c03 mov A,[HL + 0x3]
ram:00e52e 9f62d9 mov !0xfd962,A
ram:00e531 fc66e300 call !!0xe366
ram:00e535 ef05 br $ 0xe53c
ram:00e537 615903 inc [HL + 0x3]
ram:00e53a ef9e br $ 0xe4da
ram:00e53c 1006 addw SP,0x6
ram:00e53e c6 pop HL
ram:00e53f d7 ret
ram:00e540 c7 push HL
ram:00e541 c1 push AX
ram:00e542 2004 subw SP,0x4
ram:00e544 fbf8ff movw HL,!0xffff8
ram:00e547 ac04 movw AX,[HL + 0x4]
ram:00e549 bb movw [HL],AX
ram:00e54a f6 clrw AX
ram:00e54b bc02 movw [HL + 0x2],AX
ram:00e54d ac02 movw AX,[HL + 0x2]
ram:00e54f 61490e cmpw AX,[HL + 0xe]
ram:00e552 de0e bnc $ 0xe562
ram:00e554 ac02 movw AX,[HL + 0x2]
ram:00e556 610900 addw AX,[HL + 0x0]
ram:00e559 14 movw DE,AX
ram:00e55a 8c0c mov A,[HL + 0xc]
ram:00e55c 99 mov [DE],A
ram:00e55d 617902 incw [HL + 0x2]
ram:00e560 efeb br $ 0xe54d
ram:00e562 1006 addw SP,0x6
ram:00e564 c6 pop HL
ram:00e565 d7 ret
ram:00e566 c7 push HL
ram:00e567 c1 push AX
ram:00e568 2006 subw SP,0x6
ram:00e56a fbf8ff movw HL,!0xffff8
ram:00e56d ac06 movw AX,[HL + 0x6]
ram:00e56f bc02 movw [HL + 0x2],AX
ram:00e571 ac0e movw AX,[HL + 0xe]
ram:00e573 bb movw [HL],AX
ram:00e574 f6 clrw AX
ram:00e575 bc04 movw [HL + 0x4],AX
ram:00e577 ac04 movw AX,[HL + 0x4]
ram:00e579 614910 cmpw AX,[HL + 0x10]
ram:00e57c de15 bnc $ 0xe593
ram:00e57e ac04 movw AX,[HL + 0x4]
ram:00e580 610900 addw AX,[HL + 0x0]
ram:00e583 14 movw DE,AX
ram:00e584 89 mov A,[DE]
ram:00e585 72 mov ,A
ram:00e586 ac04 movw AX,[HL + 0x4]
ram:00e588 610902 addw AX,[HL + 0x2]
ram:00e58b 14 movw DE,AX
ram:00e58c 62 mov A,
ram:00e58d 99 mov [DE],A
ram:00e58e 617904 incw [HL + 0x4]
ram:00e591 efe4 br $ 0xe577
ram:00e593 1008 addw SP,0x8
ram:00e595 c6 pop HL
ram:00e596 d7 ret
ram:00e5d9 c7 push HL
ram:00e5da 16 movw HL,AX
ram:00e5db 66 mov A,
ram:00e5dc 91 dec 
ram:00e5dd df30 bnz $ 0xe60f
ram:00e5df e6 onew AX
ram:00e5e0 fc9a1b01 call !!0x11b9a
ram:00e5e4 cf64d903 mov !0xfd964,0x3
ram:00e5e8 f565d9 clrb !0xfd965
ram:00e5eb f566d9 clrb !0xfd966
ram:00e5ee 710870d9 clr1 !0xfd970.0x0
ram:00e5f2 711870d9 clr1 !0xfd970.0x1
ram:00e5f6 f6 clrw AX
ram:00e5f7 bff6d9 movw !0xfd9f6,AX
ram:00e5fa bff8d9 movw !0xfd9f8,AX
ram:00e5fd 713871d9 clr1 !0xfd971.0x3
ram:00e601 716070d9 set1 !0xfd970.0x6
ram:00e605 717870d9 clr1 !0xfd970.0x7
ram:00e609 fc1ff301 call !!0x1f31f
ram:00e60d ef2d br $ 0xe63c
ram:00e60f fc37f301 call !!0x1f337
ram:00e613 f6 clrw AX
ram:00e614 42f6d9 cmpw AX,!0xfd9f6
ram:00e617 dd0b bz $ 0xe624
ram:00e619 aff6d9 movw AX,!0xfd9f6
ram:00e61c fccae400 call !!0xe4ca
ram:00e620 f6 clrw AX
ram:00e621 bff6d9 movw !0xfd9f6,AX
ram:00e624 f6 clrw AX
ram:00e625 42f8d9 cmpw AX,!0xfd9f8
ram:00e628 dd0b bz $ 0xe635
ram:00e62a aff8d9 movw AX,!0xfd9f8
ram:00e62d fccae400 call !!0xe4ca
ram:00e631 f6 clrw AX
ram:00e632 bff8d9 movw !0xfd9f8,AX
ram:00e635 fc98f600 call !!0xf698
ram:00e639 f564d9 clrb !0xfd964
ram:00e63c c6 pop HL
ram:00e63d d7 ret
ram:00e6a2 c7 push HL
ram:00e6a3 16 movw HL,AX
ram:00e6a4 8f67d9 mov A,!0xfd967
ram:00e6a7 614e cmp A,
ram:00e6a9 dd0a bz $ 0xe6b5
ram:00e6ab 17 movw AX,HL
ram:00e6ac f1 clrb A
ram:00e6ad fc3e2201 call !!0x1223e
ram:00e6b1 66 mov A,
ram:00e6b2 9f67d9 mov !0xfd967,A
ram:00e6b5 c6 pop HL
ram:00e6b6 d7 ret
ram:00e6b7 c7 push HL
ram:00e6b8 c1 push AX
ram:00e6b9 c1 push AX
ram:00e6ba fbf8ff movw HL,!0xffff8
ram:00e6bd 8c02 mov A,[HL + 0x2]
ram:00e6bf 91 dec 
ram:00e6c0 61f8 sknz
ram:00e6c2 eecb02 _br $! 0xe990
ram:00e6c5 91 dec 
ram:00e6c6 61f8 sknz
ram:00e6c8 eed202 _br $! 0xe99d
ram:00e6cb 91 dec 
ram:00e6cc 61f8 sknz
ram:00e6ce eed902 _br $! 0xe9aa
ram:00e6d1 2c02 sub A,#0x2
ram:00e6d3 61f8 sknz
ram:00e6d5 eed502 _br $! 0xe9ad
ram:00e6d8 91 dec 
ram:00e6d9 61f8 sknz
ram:00e6db eedc02 _br $! 0xe9ba
ram:00e6de 91 dec 
ram:00e6df 61f8 sknz
ram:00e6e1 eee302 _br $! 0xe9c7
ram:00e6e4 2c19 sub A,#0x19
ram:00e6e6 61f8 sknz
ram:00e6e8 eef402 _br $! 0xe9df
ram:00e6eb 91 dec 
ram:00e6ec 61f8 sknz
ram:00e6ee eef602 _br $! 0xe9e7
ram:00e6f1 2c0f sub A,#0xf
ram:00e6f3 61f8 sknz
ram:00e6f5 eeda00 _br $! 0xe7d2
ram:00e6f8 91 dec 
ram:00e6f9 dd63 bz $ 0xe75e
ram:00e6fb 91 dec 
ram:00e6fc 61f8 sknz
ram:00e6fe eec301 _br $! 0xe8c4
ram:00e701 91 dec 
ram:00e702 61f8 sknz
ram:00e704 ee2602 _br $! 0xe92d
ram:00e707 91 dec 
ram:00e708 61f8 sknz
ram:00e70a ee4b02 _br $! 0xe958
ram:00e70d 91 dec 
ram:00e70e 61f8 sknz
ram:00e710 ee7002 _br $! 0xe983
ram:00e713 91 dec 
ram:00e714 61f8 sknz
ram:00e716 ee2303 _br $! 0xea3c
ram:00e719 91 dec 
ram:00e71a 61f8 sknz
ram:00e71c ee2c01 _br $! 0xe84b
ram:00e71f 2c49 sub A,#0x49
ram:00e721 61f8 sknz
ram:00e723 eea402 _br $! 0xe9ca
ram:00e726 91 dec 
ram:00e727 61f8 sknz
ram:00e729 eea502 _br $! 0xe9d1
ram:00e72c 2c02 sub A,#0x2
ram:00e72e 61f8 sknz
ram:00e730 eea502 _br $! 0xe9d8
ram:00e733 2c5d sub A,#0x5d
ram:00e735 61f8 sknz
ram:00e737 eeb502 _br $! 0xe9ef
ram:00e73a 91 dec 
ram:00e73b 61f8 sknz
ram:00e73d eeb802 _br $! 0xe9f8
ram:00e740 91 dec 
ram:00e741 61f8 sknz
ram:00e743 eee302 _br $! 0xea29
ram:00e746 2c0e sub A,#0xe
ram:00e748 61f8 sknz
ram:00e74a ee0003 _br $! 0xea4d
ram:00e74d 91 dec 
ram:00e74e 61f8 sknz
ram:00e750 eefc02 _br $! 0xea4f
ram:00e753 2c02 sub A,#0x2
ram:00e755 61f8 sknz
ram:00e757 ee1503 _br $! 0xea6f
ram:00e75a 91 dec 
ram:00e75b ee1103 br $! 0xea6f
ram:00e75e 8f71d9 mov A,!0xfd971
ram:00e761 81 inc 
ram:00e762 718c mov1 CY,A.0x0
ram:00e764 8f71d9 mov A,!0xfd971
ram:00e767 7189 mov1 A.0x0,CY
ram:00e769 9f71d9 mov !0xfd971,A
ram:00e76c 5c01 and A,#0x1
ram:00e76e 318e shrw AX,0x8
ram:00e770 312d shlw AX,0x2
ram:00e772 12 movw BC,AX
ram:00e773 313d shlw AX,0x3
ram:00e775 03 addw AX,BC
ram:00e776 0472d9 addw AX,0xd972
ram:00e779 bb movw [HL],AX
ram:00e77a 302400 movw AX,0x24
ram:00e77d c1 push AX
ram:00e77e ac0a movw AX,[HL + 0xa]
ram:00e780 c1 push AX
ram:00e781 ab movw AX,[HL]
ram:00e782 fc66e500 call !!0xe566
ram:00e786 1004 addw SP,0x4
ram:00e788 ab movw AX,[HL]
ram:00e789 14 movw DE,AX
ram:00e78a 8a03 mov A,[DE + 0x3]
ram:00e78c 9dd8 mov 0xffdf8,A
ram:00e78e f4d9 clrb 0xffdf9
ram:00e790 f6 clrw AX
ram:00e791 bdda movw 0xffdfa,AX
ram:00e793 c9dc6b03 movw 0xffdfc,0x36b
ram:00e797 fd5006 call !0xf0650
ram:00e79a c9dc6400 movw 0xffdfc,0x64
ram:00e79e f6 clrw AX
ram:00e79f fd8404 call !0xf0484
ram:00e7a2 adda movw AX,0xffdfa
ram:00e7a4 bf6cd9 movw !0xfd96c,AX
ram:00e7a7 12 movw BC,AX
ram:00e7a8 add8 movw AX,0xffdf8
ram:00e7aa bf6ad9 movw !0xfd96a,AX
ram:00e7ad bfe6d9 movw !0xfd9e6,AX
ram:00e7b0 33 xchw AX,BC
ram:00e7b1 bfe8d9 movw !0xfd9e8,AX
ram:00e7b4 a9 movw AX,[DE]
ram:00e7b5 bf68d9 movw !0xfd968,AX
ram:00e7b8 302000 movw AX,0x20
ram:00e7bb c1 push AX
ram:00e7bc 501e mov ,0x1e
ram:00e7be c1 push AX
ram:00e7bf 30c4d9 movw AX,0xd9c4
ram:00e7c2 fc40e500 call !!0xe540
ram:00e7c6 1004 addw SP,0x4
ram:00e7c8 300400 movw AX,0x4
ram:00e7cb fcc46e02 call !!0x26ec4
ram:00e7cf ee9d02 br $! 0xea6f
ram:00e7d2 8f71d9 mov A,!0xfd971
ram:00e7d5 81 inc 
ram:00e7d6 718c mov1 CY,A.0x0
ram:00e7d8 8f71d9 mov A,!0xfd971
ram:00e7db 7189 mov1 A.0x0,CY
ram:00e7dd 9f71d9 mov !0xfd971,A
ram:00e7e0 5c01 and A,#0x1
ram:00e7e2 318e shrw AX,0x8
ram:00e7e4 312d shlw AX,0x2
ram:00e7e6 12 movw BC,AX
ram:00e7e7 313d shlw AX,0x3
ram:00e7e9 03 addw AX,BC
ram:00e7ea 0472d9 addw AX,0xd972
ram:00e7ed bb movw [HL],AX
ram:00e7ee 302400 movw AX,0x24
ram:00e7f1 c1 push AX
ram:00e7f2 ac0a movw AX,[HL + 0xa]
ram:00e7f4 c1 push AX
ram:00e7f5 ab movw AX,[HL]
ram:00e7f6 fc66e500 call !!0xe566
ram:00e7fa 1004 addw SP,0x4
ram:00e7fc ab movw AX,[HL]
ram:00e7fd 14 movw DE,AX
ram:00e7fe 8a03 mov A,[DE + 0x3]
ram:00e800 9dd8 mov 0xffdf8,A
ram:00e802 f4d9 clrb 0xffdf9
ram:00e804 f6 clrw AX
ram:00e805 bdda movw 0xffdfa,AX
ram:00e807 c9dc6b03 movw 0xffdfc,0x36b
ram:00e80b fd5006 call !0xf0650
ram:00e80e c9dc6400 movw 0xffdfc,0x64
ram:00e812 f6 clrw AX
ram:00e813 fd8404 call !0xf0484
ram:00e816 adda movw AX,0xffdfa
ram:00e818 bf6cd9 movw !0xfd96c,AX
ram:00e81b 12 movw BC,AX
ram:00e81c add8 movw AX,0xffdf8
ram:00e81e bf6ad9 movw !0xfd96a,AX
ram:00e821 bfe6d9 movw !0xfd9e6,AX
ram:00e824 33 xchw AX,BC
ram:00e825 bfe8d9 movw !0xfd9e8,AX
ram:00e828 a9 movw AX,[DE]
ram:00e829 bf68d9 movw !0xfd968,AX
ram:00e82c 302000 movw AX,0x20
ram:00e82f c1 push AX
ram:00e830 501e mov ,0x1e
ram:00e832 c1 push AX
ram:00e833 30c4d9 movw AX,0xd9c4
ram:00e836 fc40e500 call !!0xe540
ram:00e83a 1004 addw SP,0x4
ram:00e83c e6 onew AX
ram:00e83d c1 push AX
ram:00e83e 5004 mov ,0x4
ram:00e840 c1 push AX
ram:00e841 e6 onew AX
ram:00e842 fc020401 call !!0x10402
ram:00e846 1004 addw SP,0x4
ram:00e848 ee2402 br $! 0xea6f
ram:00e84b 8f71d9 mov A,!0xfd971
ram:00e84e 81 inc 
ram:00e84f 718c mov1 CY,A.0x0
ram:00e851 8f71d9 mov A,!0xfd971
ram:00e854 7189 mov1 A.0x0,CY
ram:00e856 9f71d9 mov !0xfd971,A
ram:00e859 5c01 and A,#0x1
ram:00e85b 318e shrw AX,0x8
ram:00e85d 312d shlw AX,0x2
ram:00e85f 12 movw BC,AX
ram:00e860 313d shlw AX,0x3
ram:00e862 03 addw AX,BC
ram:00e863 0472d9 addw AX,0xd972
ram:00e866 bb movw [HL],AX
ram:00e867 302400 movw AX,0x24
ram:00e86a c1 push AX
ram:00e86b ac0a movw AX,[HL + 0xa]
ram:00e86d c1 push AX
ram:00e86e ab movw AX,[HL]
ram:00e86f fc66e500 call !!0xe566
ram:00e873 1004 addw SP,0x4
ram:00e875 ab movw AX,[HL]
ram:00e876 14 movw DE,AX
ram:00e877 8a03 mov A,[DE + 0x3]
ram:00e879 9dd8 mov 0xffdf8,A
ram:00e87b f4d9 clrb 0xffdf9
ram:00e87d f6 clrw AX
ram:00e87e bdda movw 0xffdfa,AX
ram:00e880 c9dc6b03 movw 0xffdfc,0x36b
ram:00e884 fd5006 call !0xf0650
ram:00e887 c9dc6400 movw 0xffdfc,0x64
ram:00e88b f6 clrw AX
ram:00e88c fd8404 call !0xf0484
ram:00e88f adda movw AX,0xffdfa
ram:00e891 bf6cd9 movw !0xfd96c,AX
ram:00e894 12 movw BC,AX
ram:00e895 add8 movw AX,0xffdf8
ram:00e897 bf6ad9 movw !0xfd96a,AX
ram:00e89a bfe6d9 movw !0xfd9e6,AX
ram:00e89d 33 xchw AX,BC
ram:00e89e bfe8d9 movw !0xfd9e8,AX
ram:00e8a1 a9 movw AX,[DE]
ram:00e8a2 bf68d9 movw !0xfd968,AX
ram:00e8a5 302000 movw AX,0x20
ram:00e8a8 c1 push AX
ram:00e8a9 501e mov ,0x1e
ram:00e8ab c1 push AX
ram:00e8ac 30c4d9 movw AX,0xd9c4
ram:00e8af fc40e500 call !!0xe540
ram:00e8b3 1004 addw SP,0x4
ram:00e8b5 f6 clrw AX
ram:00e8b6 c1 push AX
ram:00e8b7 5004 mov ,0x4
ram:00e8b9 c1 push AX
ram:00e8ba e6 onew AX
ram:00e8bb fc020401 call !!0x10402
ram:00e8bf 1004 addw SP,0x4
ram:00e8c1 eeab01 br $! 0xea6f
ram:00e8c4 afe8d9 movw AX,!0xfd9e8
ram:00e8c7 426cd9 cmpw AX,!0xfd96c
ram:00e8ca afe6d9 movw AX,!0xfd9e6
ram:00e8cd 61f8 sknz
ram:00e8cf 426ad9 _cmpw AX,!0xfd96a
ram:00e8d2 df2c bnz $ 0xe900
ram:00e8d4 ac0a movw AX,[HL + 0xa]
ram:00e8d6 14 movw DE,AX
ram:00e8d7 aa02 movw AX,[DE + 0x2]
ram:00e8d9 12 movw BC,AX
ram:00e8da a9 movw AX,[DE]
ram:00e8db bf6ad9 movw !0xfd96a,AX
ram:00e8de 33 xchw AX,BC
ram:00e8df bf6cd9 movw !0xfd96c,AX
ram:00e8e2 33 xchw AX,BC
ram:00e8e3 bfe6d9 movw !0xfd9e6,AX
ram:00e8e6 33 xchw AX,BC
ram:00e8e7 bfe8d9 movw !0xfd9e8,AX
ram:00e8ea f6 clrw AX
ram:00e8eb bf68d9 movw !0xfd968,AX
ram:00e8ee fc5b0101 call !!0x1015b
ram:00e8f2 e6 onew AX
ram:00e8f3 c1 push AX
ram:00e8f4 5004 mov ,0x4
ram:00e8f6 c1 push AX
ram:00e8f7 e6 onew AX
ram:00e8f8 fc4d0401 call !!0x1044d
ram:00e8fc 1004 addw SP,0x4
ram:00e8fe ef2a br $ 0xe92a
ram:00e900 ac0a movw AX,[HL + 0xa]
ram:00e902 14 movw DE,AX
ram:00e903 aa02 movw AX,[DE + 0x2]
ram:00e905 12 movw BC,AX
ram:00e906 a9 movw AX,[DE]
ram:00e907 bf6ad9 movw !0xfd96a,AX
ram:00e90a 33 xchw AX,BC
ram:00e90b bf6cd9 movw !0xfd96c,AX
ram:00e90e 33 xchw AX,BC
ram:00e90f bfe6d9 movw !0xfd9e6,AX
ram:00e912 33 xchw AX,BC
ram:00e913 bfe8d9 movw !0xfd9e8,AX
ram:00e916 f6 clrw AX
ram:00e917 bf68d9 movw !0xfd968,AX
ram:00e91a fc5b0101 call !!0x1015b
ram:00e91e e6 onew AX
ram:00e91f c1 push AX
ram:00e920 5004 mov ,0x4
ram:00e922 c1 push AX
ram:00e923 e6 onew AX
ram:00e924 fc020401 call !!0x10402
ram:00e928 1004 addw SP,0x4
ram:00e92a ee4201 br $! 0xea6f
ram:00e92d ac0a movw AX,[HL + 0xa]
ram:00e92f 14 movw DE,AX
ram:00e930 aa02 movw AX,[DE + 0x2]
ram:00e932 12 movw BC,AX
ram:00e933 a9 movw AX,[DE]
ram:00e934 bf6ad9 movw !0xfd96a,AX
ram:00e937 33 xchw AX,BC
ram:00e938 bf6cd9 movw !0xfd96c,AX
ram:00e93b 33 xchw AX,BC
ram:00e93c bfe6d9 movw !0xfd9e6,AX
ram:00e93f 33 xchw AX,BC
ram:00e940 bfe8d9 movw !0xfd9e8,AX
ram:00e943 f6 clrw AX
ram:00e944 bf68d9 movw !0xfd968,AX
ram:00e947 fc5b0101 call !!0x1015b
ram:00e94b f6 clrw AX
ram:00e94c c1 push AX
ram:00e94d c1 push AX
ram:00e94e e6 onew AX
ram:00e94f fc020401 call !!0x10402
ram:00e953 1004 addw SP,0x4
ram:00e955 ee1701 br $! 0xea6f
ram:00e958 ac0a movw AX,[HL + 0xa]
ram:00e95a 14 movw DE,AX
ram:00e95b aa02 movw AX,[DE + 0x2]
ram:00e95d 12 movw BC,AX
ram:00e95e a9 movw AX,[DE]
ram:00e95f bf6ad9 movw !0xfd96a,AX
ram:00e962 33 xchw AX,BC
ram:00e963 bf6cd9 movw !0xfd96c,AX
ram:00e966 33 xchw AX,BC
ram:00e967 bfe6d9 movw !0xfd9e6,AX
ram:00e96a 33 xchw AX,BC
ram:00e96b bfe8d9 movw !0xfd9e8,AX
ram:00e96e f6 clrw AX
ram:00e96f bf68d9 movw !0xfd968,AX
ram:00e972 fc5b0101 call !!0x1015b
ram:00e976 f6 clrw AX
ram:00e977 c1 push AX
ram:00e978 e6 onew AX
ram:00e979 c1 push AX
ram:00e97a fc020401 call !!0x10402
ram:00e97e 1004 addw SP,0x4
ram:00e980 eeec00 br $! 0xea6f
ram:00e983 fc5b0101 call !!0x1015b
ram:00e987 ac0a movw AX,[HL + 0xa]
ram:00e989 fc2e2b02 call !!0x22b2e
ram:00e98d eedf00 br $! 0xea6f
ram:00e990 fc5b0101 call !!0x1015b
ram:00e994 ac0a movw AX,[HL + 0xa]
ram:00e996 fc761402 call !!0x21476
ram:00e99a eed200 br $! 0xea6f
ram:00e99d fc5b0101 call !!0x1015b
ram:00e9a1 ac0a movw AX,[HL + 0xa]
ram:00e9a3 fc271502 call !!0x21527
ram:00e9a7 eec500 br $! 0xea6f
ram:00e9aa eec200 br $! 0xea6f
ram:00e9ad fc5b0101 call !!0x1015b
ram:00e9b1 ac0a movw AX,[HL + 0xa]
ram:00e9b3 fc7f2402 call !!0x2247f
ram:00e9b7 eeb500 br $! 0xea6f
ram:00e9ba fc5b0101 call !!0x1015b
ram:00e9be ac0a movw AX,[HL + 0xa]
ram:00e9c0 fc552502 call !!0x22555
ram:00e9c4 eea800 br $! 0xea6f
ram:00e9c7 eea500 br $! 0xea6f
ram:00e9ca fc4e1601 call !!0x1164e
ram:00e9ce ee9e00 br $! 0xea6f
ram:00e9d1 fc7d1601 call !!0x1167d
ram:00e9d5 ee9700 br $! 0xea6f
ram:00e9d8 fc811601 call !!0x11681
ram:00e9dc ee9000 br $! 0xea6f
ram:00e9df e6 onew AX
ram:00e9e0 fccf0201 call !!0x102cf
ram:00e9e4 ee8800 br $! 0xea6f
ram:00e9e7 f6 clrw AX
ram:00e9e8 fccf0201 call !!0x102cf
ram:00e9ec ee8000 br $! 0xea6f
ram:00e9ef aff8d9 movw AX,!0xfd9f8
ram:00e9f2 fc431801 call !!0x11843
ram:00e9f6 ef77 br $ 0xea6f
ram:00e9f8 f6 clrw AX
ram:00e9f9 42f8d9 cmpw AX,!0xfd9f8
ram:00e9fc dd71 bz $ 0xea6f
ram:00e9fe af1ee4 movw AX,!0xfe41e
ram:00ea01 320004 movw BC,0x400
ram:00ea04 c3 push BC
ram:00ea05 12 movw BC,AX
ram:00ea06 aff8d9 movw AX,!0xfd9f8
ram:00ea09 c1 push AX
ram:00ea0a 491200 mov A,!0xf0012[BC]
ram:00ea0d 9dd4 mov 0xffdf4,A
ram:00ea0f 791000 movw AX,!0xf0010[BC]
ram:00ea12 c1 push AX
ram:00ea13 8dd4 mov A,0xffdf4
ram:00ea15 9dd6 mov 0xffdf6,A
ram:00ea17 c0 pop AX
ram:00ea18 14 movw DE,AX
ram:00ea19 301000 movw AX,0x10
ram:00ea1c f7 clrw BC
ram:00ea1d c1 push AX
ram:00ea1e 8dd6 mov A,0xffdf6
ram:00ea20 9efc mov CS,A
ram:00ea22 c0 pop AX
ram:00ea23 61ea call DE
ram:00ea25 1004 addw SP,0x4
ram:00ea27 ef46 br $ 0xea6f
ram:00ea29 f6 clrw AX
ram:00ea2a 42f8d9 cmpw AX,!0xfd9f8
ram:00ea2d dd40 bz $ 0xea6f
ram:00ea2f aff8d9 movw AX,!0xfd9f8
ram:00ea32 fccae400 call !!0xe4ca
ram:00ea36 f6 clrw AX
ram:00ea37 bff8d9 movw !0xfd9f8,AX
ram:00ea3a ef33 br $ 0xea6f
ram:00ea3c fc5b0101 call !!0x1015b
ram:00ea40 300400 movw AX,0x4
ram:00ea43 fca2e600 call !!0xe6a2
ram:00ea47 fc6a2802 call !!0x2286a
ram:00ea4b ef22 br $ 0xea6f
ram:00ea4d ef20 br $ 0xea6f
ram:00ea4f ac0a movw AX,[HL + 0xa]
ram:00ea51 14 movw DE,AX
ram:00ea52 aa02 movw AX,[DE + 0x2]
ram:00ea54 12 movw BC,AX
ram:00ea55 a9 movw AX,[DE]
ram:00ea56 bf6ad9 movw !0xfd96a,AX
ram:00ea59 33 xchw AX,BC
ram:00ea5a bf6cd9 movw !0xfd96c,AX
ram:00ea5d 33 xchw AX,BC
ram:00ea5e bfe6d9 movw !0xfd9e6,AX
ram:00ea61 33 xchw AX,BC
ram:00ea62 bfe8d9 movw !0xfd9e8,AX
ram:00ea65 3049e6 movw AX,0xe649
ram:00ea68 5200 mov ,0x0
ram:00ea6a f3 clrb B
ram:00ea6b fc057e00 call !!0x7e05
ram:00ea6f e7 onew BC
ram:00ea70 1004 addw SP,0x4
ram:00ea72 c6 pop HL
ram:00ea73 d7 ret
ram:00f288 c7 push HL
ram:00f289 c1 push AX
ram:00f28a fbf8ff movw HL,!0xffff8
ram:00f28d af08e4 movw AX,!0xfe408
ram:00f290 f7 clrw BC
ram:00f291 c3 push BC
ram:00f292 14 movw DE,AX
ram:00f293 8a0e mov A,[DE + 0xe]
ram:00f295 9efc mov CS,A
ram:00f297 aa0c movw AX,[DE + 0xc]
ram:00f299 14 movw DE,AX
ram:00f29a f6 clrw AX
ram:00f29b 61ea call DE
ram:00f29d c0 pop AX
ram:00f29e f5fbd9 clrb !0xfd9fb
ram:00f2a1 ac08 movw AX,[HL + 0x8]
ram:00f2a3 bffcd9 movw !0xfd9fc,AX
ram:00f2a6 f6 clrw AX
ram:00f2a7 bffed9 movw !0xfd9fe,AX
ram:00f2aa ac0a movw AX,[HL + 0xa]
ram:00f2ac 243200 subw AX,0x32
ram:00f2af 520a mov ,0xa
ram:00f2b1 fd1c06 call !0xf061c
ram:00f2b4 60 mov A,
ram:00f2b5 81 inc 
ram:00f2b6 9f02da mov !0xfda02,A
ram:00f2b9 4002da33 cmp !0xfda02,0x33
ram:00f2bd 61c8 skc
ram:00f2bf cf02da31 _mov !0xfda02,0x31
ram:00f2c3 ac0c movw AX,[HL + 0xc]
ram:00f2c5 5214 mov ,0x14
ram:00f2c7 fd1c06 call !0xf061c
ram:00f2ca 60 mov A,
ram:00f2cb 0c32 add A,#0x32
ram:00f2cd 81 inc 
ram:00f2ce 9f03da mov !0xfda03,A
ram:00f2d1 f6 clrw AX
ram:00f2d2 614908 cmpw AX,[HL + 0x8]
ram:00f2d5 dd05 bz $ 0xf2dc
ram:00f2d7 e5fad9 oneb !0xfd9fa
ram:00f2da ef03 br $ 0xf2df
ram:00f2dc f5fad9 clrb !0xfd9fa
ram:00f2df 306400 movw AX,0x64
ram:00f2e2 c1 push AX
ram:00f2e3 3493f1 movw DE,0xf193
ram:00f2e6 5200 mov ,0x0
ram:00f2e8 c3 push BC
ram:00f2e9 c5 push DE
ram:00f2ea ab movw AX,[HL]
ram:00f2eb 14 movw DE,AX
ram:00f2ec 89 mov A,[DE]
ram:00f2ed 318e shrw AX,0x8
ram:00f2ef fcd97c00 call !!0x7cd9
ram:00f2f3 1006 addw SP,0x6
ram:00f2f5 c0 pop AX
ram:00f2f6 c6 pop HL
ram:00f2f7 d7 ret
ram:00f2f8 c7 push HL
ram:00f2f9 16 movw HL,AX
ram:00f2fa 8ffbd9 mov A,!0xfd9fb
ram:00f2fd 9b mov [HL],A
ram:00f2fe dbfcd9 movw BC,!0xfd9fc
ram:00f301 c6 pop HL
ram:00f302 d7 ret
ram:00f456 c7 push HL
ram:00f457 c1 push AX
ram:00f458 fbf8ff movw HL,!0xffff8
ram:00f45b ac0c movw AX,[HL + 0xc]
ram:00f45d c1 push AX
ram:00f45e ac0a movw AX,[HL + 0xa]
ram:00f460 c1 push AX
ram:00f461 8c08 mov A,[HL + 0x8]
ram:00f463 318e shrw AX,0x8
ram:00f465 c1 push AX
ram:00f466 f6 clrw AX
ram:00f467 fc5c1501 call !!0x1155c
ram:00f46b 1006 addw SP,0x6
ram:00f46d e6 onew AX
ram:00f46e c1 push AX
ram:00f46f 3439f4 movw DE,0xf439
ram:00f472 5200 mov ,0x0
ram:00f474 c3 push BC
ram:00f475 c5 push DE
ram:00f476 ab movw AX,[HL]
ram:00f477 14 movw DE,AX
ram:00f478 89 mov A,[DE]
ram:00f479 318e shrw AX,0x8
ram:00f47b fcd97c00 call !!0x7cd9
ram:00f47f 1006 addw SP,0x6
ram:00f481 c0 pop AX
ram:00f482 c6 pop HL
ram:00f483 d7 ret
ram:00f4c5 c7 push HL
ram:00f4c6 c1 push AX
ram:00f4c7 fbf8ff movw HL,!0xffff8
ram:00f4ca ac0c movw AX,[HL + 0xc]
ram:00f4cc c1 push AX
ram:00f4cd ac0a movw AX,[HL + 0xa]
ram:00f4cf c1 push AX
ram:00f4d0 8c08 mov A,[HL + 0x8]
ram:00f4d2 318e shrw AX,0x8
ram:00f4d4 c1 push AX
ram:00f4d5 f6 clrw AX
ram:00f4d6 fcfd1401 call !!0x114fd
ram:00f4da 1006 addw SP,0x6
ram:00f4dc 300500 movw AX,0x5
ram:00f4df c1 push AX
ram:00f4e0 3484f4 movw DE,0xf484
ram:00f4e3 5200 mov ,0x0
ram:00f4e5 c3 push BC
ram:00f4e6 c5 push DE
ram:00f4e7 ab movw AX,[HL]
ram:00f4e8 14 movw DE,AX
ram:00f4e9 89 mov A,[DE]
ram:00f4ea 318e shrw AX,0x8
ram:00f4ec fcd97c00 call !!0x7cd9
ram:00f4f0 1006 addw SP,0x6
ram:00f4f2 c0 pop AX
ram:00f4f3 c6 pop HL
ram:00f4f4 d7 ret
ram:00f4f5 c7 push HL
ram:00f4f6 16 movw HL,AX
ram:00f4f7 af04da movw AX,!0xfda04
ram:00f4fa bb movw [HL],AX
ram:00f4fb af06da movw AX,!0xfda06
ram:00f4fe bc02 movw [HL + 0x2],AX
ram:00f500 af08da movw AX,!0xfda08
ram:00f503 bc04 movw [HL + 0x4],AX
ram:00f505 af0ada movw AX,!0xfda0a
ram:00f508 bc06 movw [HL + 0x6],AX
ram:00f50a c6 pop HL
ram:00f50b d7 ret
ram:00f5fd c7 push HL
ram:00f5fe c1 push AX
ram:00f5ff fbf8ff movw HL,!0xffff8
ram:00f602 8c08 mov A,[HL + 0x8]
ram:00f604 5c3f and A,#0x3f
ram:00f606 340cda movw DE,0xda0c
ram:00f609 70 mov ,A
ram:00f60a 89 mov A,[DE]
ram:00f60b 5cc0 and A,#0xc0
ram:00f60d 6168 or A,
ram:00f60f 99 mov [DE],A
ram:00f610 ac0c movw AX,[HL + 0xc]
ram:00f612 12 movw BC,AX
ram:00f613 ac0a movw AX,[HL + 0xa]
ram:00f615 bf10da movw !0xfda10,AX
ram:00f618 33 xchw AX,BC
ram:00f619 bf12da movw !0xfda12,AX
ram:00f61c ac0e movw AX,[HL + 0xe]
ram:00f61e bf0eda movw !0xfda0e,AX
ram:00f621 71780cda clr1 !0xfda0c.0x7
ram:00f625 71680cda clr1 !0xfda0c.0x6
ram:00f629 f6 clrw AX
ram:00f62a c1 push AX
ram:00f62b 340cf5 movw DE,0xf50c
ram:00f62e 5200 mov ,0x0
ram:00f630 c3 push BC
ram:00f631 c5 push DE
ram:00f632 ab movw AX,[HL]
ram:00f633 14 movw DE,AX
ram:00f634 89 mov A,[DE]
ram:00f635 318e shrw AX,0x8
ram:00f637 fcd97c00 call !!0x7cd9
ram:00f63b 1006 addw SP,0x6
ram:00f63d c0 pop AX
ram:00f63e c6 pop HL
ram:00f63f d7 ret
ram:00f640 c7 push HL
ram:00f641 c1 push AX
ram:00f642 fbf8ff movw HL,!0xffff8
ram:00f645 8c08 mov A,[HL + 0x8]
ram:00f647 5c3f and A,#0x3f
ram:00f649 340cda movw DE,0xda0c
ram:00f64c 70 mov ,A
ram:00f64d 89 mov A,[DE]
ram:00f64e 5cc0 and A,#0xc0
ram:00f650 6168 or A,
ram:00f652 99 mov [DE],A
ram:00f653 ac0c movw AX,[HL + 0xc]
ram:00f655 12 movw BC,AX
ram:00f656 ac0a movw AX,[HL + 0xa]
ram:00f658 bf10da movw !0xfda10,AX
ram:00f65b 33 xchw AX,BC
ram:00f65c bf12da movw !0xfda12,AX
ram:00f65f ac0e movw AX,[HL + 0xe]
ram:00f661 bf0eda movw !0xfda0e,AX
ram:00f664 71780cda clr1 !0xfda0c.0x7
ram:00f668 71600cda set1 !0xfda0c.0x6
ram:00f66c f6 clrw AX
ram:00f66d c1 push AX
ram:00f66e 340cf5 movw DE,0xf50c
ram:00f671 5200 mov ,0x0
ram:00f673 c3 push BC
ram:00f674 c5 push DE
ram:00f675 ab movw AX,[HL]
ram:00f676 14 movw DE,AX
ram:00f677 89 mov A,[DE]
ram:00f678 318e shrw AX,0x8
ram:00f67a fcd97c00 call !!0x7cd9
ram:00f67e 1006 addw SP,0x6
ram:00f680 c0 pop AX
ram:00f681 c6 pop HL
ram:00f682 d7 ret
ram:00f683 8f0cda mov A,!0xfda0c
ram:00f686 31fe shrw AX,0xf
ram:00f688 12 movw BC,AX
ram:00f689 d7 ret
ram:00f68a c7 push HL
ram:00f68b 16 movw HL,AX
ram:00f68c af0eda movw AX,!0xfda0e
ram:00f68f bb movw [HL],AX
ram:00f690 8f0cda mov A,!0xfda0c
ram:00f693 31fe shrw AX,0xf
ram:00f695 12 movw BC,AX
ram:00f696 c6 pop HL
ram:00f697 d7 ret
ram:00f698 d56ed9 cmp0 !0xfd96e
ram:00f69b dd0b bz $ 0xf6a8
ram:00f69d d96ed9 mov X,!0xfd96e
ram:00f6a0 f1 clrb A
ram:00f6a1 fc927e00 call !!0x7e92
ram:00f6a5 f56ed9 clrb !0xfd96e
ram:00f6a8 8f65d9 mov A,!0xfd965
ram:00f6ab 91 dec 
ram:00f6ac dd19 bz $ 0xf6c7
ram:00f6ae 91 dec 
ram:00f6af dd1c bz $ 0xf6cd
ram:00f6b1 91 dec 
ram:00f6b2 dd25 bz $ 0xf6d9
ram:00f6b4 91 dec 
ram:00f6b5 dd1c bz $ 0xf6d3
ram:00f6b7 2c02 sub A,#0x2
ram:00f6b9 dd36 bz $ 0xf6f1
ram:00f6bb 2c05 sub A,#0x5
ram:00f6bd dd20 bz $ 0xf6df
ram:00f6bf 91 dec 
ram:00f6c0 dd23 bz $ 0xf6e5
ram:00f6c2 91 dec 
ram:00f6c3 dd26 bz $ 0xf6eb
ram:00f6c5 ef2e br $ 0xf6f5
ram:00f6c7 fc980401 call !!0x10498
ram:00f6cb ef28 br $ 0xf6f5
ram:00f6cd fc066f02 call !!0x26f06
ram:00f6d1 ef22 br $ 0xf6f5
ram:00f6d3 fcf70902 call !!0x209f7
ram:00f6d7 ef1c br $ 0xf6f5
ram:00f6d9 fc497002 call !!0x27049
ram:00f6dd ef16 br $ 0xf6f5
ram:00f6df fc941602 call !!0x21694
ram:00f6e3 ef10 br $ 0xf6f5
ram:00f6e5 fc8a2b02 call !!0x22b8a
ram:00f6e9 ef0a br $ 0xf6f5
ram:00f6eb fc172702 call !!0x22717
ram:00f6ef ef04 br $ 0xf6f5
ram:00f6f1 fca02802 call !!0x228a0
ram:00f6f5 f565d9 clrb !0xfd965
ram:00f6f8 d7 ret
ram:00f6f9 c7 push HL
ram:00f6fa c1 push AX
ram:00f6fb 2004 subw SP,0x4
ram:00f6fd fbf8ff movw HL,!0xffff8
ram:00f700 8f71d9 mov A,!0xfd971
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
ram:00f77b c7 push HL
ram:00f77c c1 push AX
ram:00f77d 2004 subw SP,0x4
ram:00f77f fbf8ff movw HL,!0xffff8
ram:00f782 8f71d9 mov A,!0xfd971
ram:00f785 5c01 and A,#0x1
ram:00f787 318e shrw AX,0x8
ram:00f789 312d shlw AX,0x2
ram:00f78b 12 movw BC,AX
ram:00f78c 313d shlw AX,0x3
ram:00f78e 03 addw AX,BC
ram:00f78f 0472d9 addw AX,0xd972
ram:00f792 bb movw [HL],AX
ram:00f793 cc0300 mov [HL + 0x3],0x0
ram:00f796 ab movw AX,[HL]
ram:00f797 14 movw DE,AX
ram:00f798 8a02 mov A,[DE + 0x2]
ram:00f79a 4e03 cmp A,[HL + 0x3]
ram:00f79c 61d313 bnh $ 0xf7b1
ram:00f79f 8c03 mov A,[HL + 0x3]
ram:00f7a1 318e shrw AX,0x8
ram:00f7a3 a5 incw DE
ram:00f7a4 a5 incw DE
ram:00f7a5 a5 incw DE
ram:00f7a6 05 addw AX,DE
ram:00f7a7 14 movw DE,AX
ram:00f7a8 89 mov A,[DE]
ram:00f7a9 4e04 cmp A,[HL + 0x4]
ram:00f7ab dd05 bz $ 0xf7b2
ram:00f7ad 615903 inc [HL + 0x3]
ram:00f7b0 efe4 br $ 0xf796
ram:00f7b2 ab movw AX,[HL]
ram:00f7b3 14 movw DE,AX
ram:00f7b4 8a02 mov A,[DE + 0x2]
ram:00f7b6 4e03 cmp A,[HL + 0x3]
ram:00f7b8 dd2f bz $ 0xf7e9
ram:00f7ba ab movw AX,[HL]
ram:00f7bb 14 movw DE,AX
ram:00f7bc 8a02 mov A,[DE + 0x2]
ram:00f7be 91 dec 
ram:00f7bf 4e03 cmp A,[HL + 0x3]
ram:00f7c1 61d31e bnh $ 0xf7e1
ram:00f7c4 8c03 mov A,[HL + 0x3]
ram:00f7c6 81 inc 
ram:00f7c7 318e shrw AX,0x8
ram:00f7c9 a5 incw DE
ram:00f7ca a5 incw DE
ram:00f7cb a5 incw DE
ram:00f7cc 05 addw AX,DE
ram:00f7cd 14 movw DE,AX
ram:00f7ce 89 mov A,[DE]
ram:00f7cf 72 mov ,A
ram:00f7d0 ab movw AX,[HL]
ram:00f7d1 14 movw DE,AX
ram:00f7d2 8c03 mov A,[HL + 0x3]
ram:00f7d4 318e shrw AX,0x8
ram:00f7d6 a5 incw DE
ram:00f7d7 a5 incw DE
ram:00f7d8 a5 incw DE
ram:00f7d9 05 addw AX,DE
ram:00f7da 14 movw DE,AX
ram:00f7db 62 mov A,
ram:00f7dc 99 mov [DE],A
ram:00f7dd 615903 inc [HL + 0x3]
ram:00f7e0 efd8 br $ 0xf7ba
ram:00f7e2 ab movw AX,[HL]
ram:00f7e3 14 movw DE,AX
ram:00f7e4 8a02 mov A,[DE + 0x2]
ram:00f7e6 91 dec 
ram:00f7e7 9a02 mov [DE + 0x2],A
ram:00f7e9 1006 addw SP,0x6
ram:00f7eb c6 pop HL
ram:00f7ec d7 ret
ram:00f7ed c7 push HL
ram:00f7ee c1 push AX
ram:00f7ef 2012 subw SP,0x12
ram:00f7f1 fbf8ff movw HL,!0xffff8
ram:00f7f4 ac12 movw AX,[HL + 0x12]
ram:00f7f6 14 movw DE,AX
ram:00f7f7 a9 movw AX,[DE]
ram:00f7f8 bc0a movw [HL + 0xa],AX
ram:00f7fa ac12 movw AX,[HL + 0x12]
ram:00f7fc 14 movw DE,AX
ram:00f7fd aa02 movw AX,[DE + 0x2]
ram:00f7ff bc0c movw [HL + 0xc],AX
ram:00f801 ac12 movw AX,[HL + 0x12]
ram:00f803 14 movw DE,AX
ram:00f804 aa04 movw AX,[DE + 0x4]
ram:00f806 bc0e movw [HL + 0xe],AX
ram:00f808 ac12 movw AX,[HL + 0x12]
ram:00f80a 14 movw DE,AX
ram:00f80b aa06 movw AX,[DE + 0x6]
ram:00f80d bc10 movw [HL + 0x10],AX
ram:00f80f ac0a movw AX,[HL + 0xa]
ram:00f811 bdd8 movw 0xffdf8,AX
ram:00f813 302100 movw AX,0x21
ram:00f816 fd1905 call !0xf0519
ram:00f819 bc0a movw [HL + 0xa],AX
ram:00f81b 8c0b mov A,[HL + 0xb]
ram:00f81d 01 addw AX,AX
ram:00f81e de05 bnc $ 0xf825
ram:00f820 f6 clrw AX
ram:00f821 bc0a movw [HL + 0xa],AX
ram:00f823 ef68 br $ 0xf88d
ram:00f825 ac0a movw AX,[HL + 0xa]
ram:00f827 44c800 cmpw AX,0xc8
ram:00f82a 71fe or1 CY,A.0x7
ram:00f82c de16 bnc $ 0xf844
ram:00f82e ac0a movw AX,[HL + 0xa]
ram:00f830 bdd8 movw 0xffdf8,AX
ram:00f832 303200 movw AX,0x32
ram:00f835 fd7304 call !0xf0473
ram:00f838 bdd8 movw 0xffdf8,AX
ram:00f83a 30c800 movw AX,0xc8
ram:00f83d fd1905 call !0xf0519
ram:00f840 bc0a movw [HL + 0xa],AX
ram:00f842 ef49 br $ 0xf88d
ram:00f844 ac0a movw AX,[HL + 0xa]
ram:00f846 441801 cmpw AX,0x118
ram:00f849 71fe or1 CY,A.0x7
ram:00f84b de1a bnc $ 0xf867
ram:00f84d ac0a movw AX,[HL + 0xa]
ram:00f84f 24c800 subw AX,0xc8
ram:00f852 12 movw BC,AX
ram:00f853 315d shlw AX,0x5
ram:00f855 03 addw AX,BC
ram:00f856 03 addw AX,BC
ram:00f857 03 addw AX,BC
ram:00f858 bdd8 movw 0xffdf8,AX
ram:00f85a 305000 movw AX,0x50
ram:00f85d fd1905 call !0xf0519
ram:00f860 043200 addw AX,0x32
ram:00f863 bc0a movw [HL + 0xa],AX
ram:00f865 ef26 br $ 0xf88d
ram:00f867 ac0a movw AX,[HL + 0xa]
ram:00f869 445802 cmpw AX,0x258
ram:00f86c 71fe or1 CY,A.0x7
ram:00f86e de18 bnc $ 0xf888
ram:00f870 ac0a movw AX,[HL + 0xa]
ram:00f872 241801 subw AX,0x118
ram:00f875 12 movw BC,AX
ram:00f876 314d shlw AX,0x4
ram:00f878 23 subw AX,BC
ram:00f879 bdd8 movw 0xffdf8,AX
ram:00f87b 304001 movw AX,0x140
ram:00f87e fd1905 call !0xf0519
ram:00f881 045500 addw AX,0x55
ram:00f884 bc0a movw [HL + 0xa],AX
ram:00f886 ef05 br $ 0xf88d
ram:00f888 306400 movw AX,0x64
ram:00f88b bc0a movw [HL + 0xa],AX
ram:00f88d 8c0d mov A,[HL + 0xd]
ram:00f88f 01 addw AX,AX
ram:00f890 de0e bnc $ 0xf8a0
ram:00f892 ac0c movw AX,[HL + 0xc]
ram:00f894 bdd8 movw 0xffdf8,AX
ram:00f896 30ecff movw AX,0xffec
ram:00f899 fd1905 call !0xf0519
ram:00f89c bc0c movw [HL + 0xc],AX
ram:00f89e ef0c br $ 0xf8ac
ram:00f8a0 ac0c movw AX,[HL + 0xc]
ram:00f8a2 bdd8 movw 0xffdf8,AX
ram:00f8a4 301400 movw AX,0x14
ram:00f8a7 fd1905 call !0xf0519
ram:00f8aa bc0c movw [HL + 0xc],AX
ram:00f8ac ac0c movw AX,[HL + 0xc]
ram:00f8ae 442d01 cmpw AX,0x12d
ram:00f8b1 71fe or1 CY,A.0x7
ram:00f8b3 dc05 bc $ 0xf8ba
ram:00f8b5 f6 clrw AX
ram:00f8b6 bc0c movw [HL + 0xc],AX
ram:00f8b8 ef5a br $ 0xf914
ram:00f8ba ac0c movw AX,[HL + 0xc]
ram:00f8bc 446500 cmpw AX,0x65
ram:00f8bf 71fe or1 CY,A.0x7
ram:00f8c1 dc18 bc $ 0xf8db
ram:00f8c3 302c01 movw AX,0x12c
ram:00f8c6 61290c subw AX,[HL + 0xc]
ram:00f8c9 313d shlw AX,0x3
ram:00f8cb 12 movw BC,AX
ram:00f8cc 312d shlw AX,0x2
ram:00f8ce 03 addw AX,BC
ram:00f8cf bdd8 movw 0xffdf8,AX
ram:00f8d1 30c800 movw AX,0xc8
ram:00f8d4 fd1905 call !0xf0519
ram:00f8d7 bc0c movw [HL + 0xc],AX
ram:00f8d9 ef39 br $ 0xf914
ram:00f8db ac0c movw AX,[HL + 0xc]
ram:00f8dd 441500 cmpw AX,0x15
ram:00f8e0 71fe or1 CY,A.0x7
ram:00f8e2 dc1d bc $ 0xf901
ram:00f8e4 306400 movw AX,0x64
ram:00f8e7 61290c subw AX,[HL + 0xc]
ram:00f8ea bdd8 movw 0xffdf8,AX
ram:00f8ec 303b00 movw AX,0x3b
ram:00f8ef fd7304 call !0xf0473
ram:00f8f2 bdd8 movw 0xffdf8,AX
ram:00f8f4 305000 movw AX,0x50
ram:00f8f7 fd1905 call !0xf0519
ram:00f8fa 042800 addw AX,0x28
ram:00f8fd bc0c movw [HL + 0xc],AX
ram:00f8ff ef13 br $ 0xf914
ram:00f901 301400 movw AX,0x14
ram:00f904 61290c subw AX,[HL + 0xc]
ram:00f907 bdd8 movw 0xffdf8,AX
ram:00f909 301400 movw AX,0x14
ram:00f90c fd1905 call !0xf0519
ram:00f90f 046300 addw AX,0x63
ram:00f912 bc0c movw [HL + 0xc],AX
ram:00f914 ac0e movw AX,[HL + 0xe]
ram:00f916 bdd8 movw 0xffdf8,AX
ram:00f918 302100 movw AX,0x21
ram:00f91b fd1905 call !0xf0519
ram:00f91e bc0e movw [HL + 0xe],AX
ram:00f920 445902 cmpw AX,0x259
ram:00f923 71fe or1 CY,A.0x7
ram:00f925 dc05 bc $ 0xf92c
ram:00f927 f6 clrw AX
ram:00f928 bc0e movw [HL + 0xe],AX
ram:00f92a ef60 br $ 0xf98c
ram:00f92c ac0e movw AX,[HL + 0xe]
ram:00f92e 442d01 cmpw AX,0x12d
ram:00f931 71fe or1 CY,A.0x7
ram:00f933 dc1a bc $ 0xf94f
ram:00f935 305802 movw AX,0x258
ram:00f938 61290e subw AX,[HL + 0xe]
ram:00f93b bdd8 movw 0xffdf8,AX
ram:00f93d 304600 movw AX,0x46
ram:00f940 fd7304 call !0xf0473
ram:00f943 bdd8 movw 0xffdf8,AX
ram:00f945 302c01 movw AX,0x12c
ram:00f948 fd1905 call !0xf0519
ram:00f94b bc0e movw [HL + 0xe],AX
ram:00f94d ef3d br $ 0xf98c
ram:00f94f ac0c movw AX,[HL + 0xc]
ram:00f951 446500 cmpw AX,0x65
ram:00f954 71fe or1 CY,A.0x7
ram:00f956 dc1d bc $ 0xf975
ram:00f958 302c01 movw AX,0x12c
ram:00f95b 61290e subw AX,[HL + 0xe]
ram:00f95e bdd8 movw 0xffdf8,AX
ram:00f960 301900 movw AX,0x19
ram:00f963 fd7304 call !0xf0473
ram:00f966 bdd8 movw 0xffdf8,AX
ram:00f968 30c800 movw AX,0xc8
ram:00f96b fd1905 call !0xf0519
ram:00f96e 044600 addw AX,0x46
ram:00f971 bc0e movw [HL + 0xe],AX
ram:00f973 ef17 br $ 0xf98c
ram:00f975 306400 movw AX,0x64
ram:00f978 61290e subw AX,[HL + 0xe]
ram:00f97b 12 movw BC,AX
ram:00f97c 312d shlw AX,0x2
ram:00f97e 03 addw AX,BC
ram:00f97f bdd8 movw 0xffdf8,AX
ram:00f981 306400 movw AX,0x64
ram:00f984 fd1905 call !0xf0519
ram:00f987 045f00 addw AX,0x5f
ram:00f98a bc0e movw [HL + 0xe],AX
ram:00f98c ac10 movw AX,[HL + 0x10]
ram:00f98e bdd8 movw 0xffdf8,AX
ram:00f990 302100 movw AX,0x21
ram:00f993 fd1905 call !0xf0519
ram:00f996 bc10 movw [HL + 0x10],AX
ram:00f998 449101 cmpw AX,0x191
ram:00f99b 71fe or1 CY,A.0x7
ram:00f99d dc05 bc $ 0xf9a4
ram:00f99f f6 clrw AX
ram:00f9a0 bc10 movw [HL + 0x10],AX
ram:00f9a2 ef5e br $ 0xfa02
ram:00f9a4 ac10 movw AX,[HL + 0x10]
ram:00f9a6 44c900 cmpw AX,0xc9
ram:00f9a9 71fe or1 CY,A.0x7
ram:00f9ab dc1a bc $ 0xf9c7
ram:00f9ad 309001 movw AX,0x190
ram:00f9b0 612910 subw AX,[HL + 0x10]
ram:00f9b3 bdd8 movw 0xffdf8,AX
ram:00f9b5 303c00 movw AX,0x3c
ram:00f9b8 fd7304 call !0xf0473
ram:00f9bb bdd8 movw 0xffdf8,AX
ram:00f9bd 30c800 movw AX,0xc8
ram:00f9c0 fd1905 call !0xf0519
ram:00f9c3 bc10 movw [HL + 0x10],AX
ram:00f9c5 ef3b br $ 0xfa02
ram:00f9c7 ac10 movw AX,[HL + 0x10]
ram:00f9c9 444700 cmpw AX,0x47
ram:00f9cc 71fe or1 CY,A.0x7
ram:00f9ce dc1a bc $ 0xf9ea
ram:00f9d0 30c800 movw AX,0xc8
ram:00f9d3 612910 subw AX,[HL + 0x10]
ram:00f9d6 12 movw BC,AX
ram:00f9d7 315d shlw AX,0x5
ram:00f9d9 23 subw AX,BC
ram:00f9da 23 subw AX,BC
ram:00f9db bdd8 movw 0xffdf8,AX
ram:00f9dd 308200 movw AX,0x82
ram:00f9e0 fd1905 call !0xf0519
ram:00f9e3 043c00 addw AX,0x3c
ram:00f9e6 bc10 movw [HL + 0x10],AX
ram:00f9e8 ef18 br $ 0xfa02
ram:00f9ea 304600 movw AX,0x46
ram:00f9ed 612910 subw AX,[HL + 0x10]
ram:00f9f0 01 addw AX,AX
ram:00f9f1 12 movw BC,AX
ram:00f9f2 312d shlw AX,0x2
ram:00f9f4 03 addw AX,BC
ram:00f9f5 bdd8 movw 0xffdf8,AX
ram:00f9f7 304600 movw AX,0x46
ram:00f9fa fd1905 call !0xf0519
ram:00f9fd 045a00 addw AX,0x5a
ram:00fa00 bc10 movw [HL + 0x10],AX
ram:00fa02 306400 movw AX,0x64
ram:00fa05 61290a subw AX,[HL + 0xa]
ram:00fa08 12 movw BC,AX
ram:00fa09 d9ead9 mov X,!0xfd9ea
ram:00fa0c f1 clrb A
ram:00fa0d bdd8 movw 0xffdf8,AX
ram:00fa0f 13 movw AX,BC
ram:00fa10 fd7304 call !0xf0473
ram:00fa13 043200 addw AX,0x32
ram:00fa16 bdd8 movw 0xffdf8,AX
ram:00fa18 306400 movw AX,0x64
ram:00fa1b fd1905 call !0xf0519
ram:00fa1e 12 movw BC,AX
ram:00fa1f 306400 movw AX,0x64
ram:00fa22 23 subw AX,BC
ram:00fa23 bc0a movw [HL + 0xa],AX
ram:00fa25 306400 movw AX,0x64
ram:00fa28 61290c subw AX,[HL + 0xc]
ram:00fa2b 12 movw BC,AX
ram:00fa2c d9ebd9 mov X,!0xfd9eb
ram:00fa2f f1 clrb A
ram:00fa30 bdd8 movw 0xffdf8,AX
ram:00fa32 13 movw AX,BC
ram:00fa33 fd7304 call !0xf0473
ram:00fa36 043200 addw AX,0x32
ram:00fa39 bdd8 movw 0xffdf8,AX
ram:00fa3b 306400 movw AX,0x64
ram:00fa3e fd1905 call !0xf0519
ram:00fa41 12 movw BC,AX
ram:00fa42 306400 movw AX,0x64
ram:00fa45 23 subw AX,BC
ram:00fa46 bc0c movw [HL + 0xc],AX
ram:00fa48 306400 movw AX,0x64
ram:00fa4b 61290e subw AX,[HL + 0xe]
ram:00fa4e 12 movw BC,AX
ram:00fa4f d9ecd9 mov X,!0xfd9ec
ram:00fa52 f1 clrb A
ram:00fa53 bdd8 movw 0xffdf8,AX
ram:00fa55 13 movw AX,BC
ram:00fa56 fd7304 call !0xf0473
ram:00fa59 043200 addw AX,0x32
ram:00fa5c bdd8 movw 0xffdf8,AX
ram:00fa5e 306400 movw AX,0x64
ram:00fa61 fd1905 call !0xf0519
ram:00fa64 12 movw BC,AX
ram:00fa65 306400 movw AX,0x64
ram:00fa68 23 subw AX,BC
ram:00fa69 bc0e movw [HL + 0xe],AX
ram:00fa6b 306400 movw AX,0x64
ram:00fa6e 612910 subw AX,[HL + 0x10]
ram:00fa71 12 movw BC,AX
ram:00fa72 d9edd9 mov X,!0xfd9ed
ram:00fa75 f1 clrb A
ram:00fa76 bdd8 movw 0xffdf8,AX
ram:00fa78 13 movw AX,BC
ram:00fa79 fd7304 call !0xf0473
ram:00fa7c 043200 addw AX,0x32
ram:00fa7f bdd8 movw 0xffdf8,AX
ram:00fa81 306400 movw AX,0x64
ram:00fa84 fd1905 call !0xf0519
ram:00fa87 12 movw BC,AX
ram:00fa88 306400 movw AX,0x64
ram:00fa8b 23 subw AX,BC
ram:00fa8c bc10 movw [HL + 0x10],AX
ram:00fa8e ac0a movw AX,[HL + 0xa]
ram:00fa90 441500 cmpw AX,0x15
ram:00fa93 71fe or1 CY,A.0x7
ram:00fa95 61d8 sknc
ram:00fa97 eec100 _br $! 0xfb5b
ram:00fa9a c7 push HL
ram:00fa9b 17 movw AX,HL
ram:00fa9c 040400 addw AX,0x4
ram:00fa9f 16 movw HL,AX
ram:00faa0 f7 clrw BC
ram:00faa1 491640 mov A,!0xf4016[BC]
ram:00faa4 9b mov [HL],A
ram:00faa5 a3 incw BC
ram:00faa6 a7 incw HL
ram:00faa7 5102 mov ,0x2
ram:00faa9 614a cmp A,
ram:00faab dff4 bnz $ 0xfaa1
ram:00faad c6 pop HL
ram:00faae c7 push HL
ram:00faaf 17 movw AX,HL
ram:00fab0 040200 addw AX,0x2
ram:00fab3 16 movw HL,AX
ram:00fab4 f7 clrw BC
ram:00fab5 491840 mov A,!0xf4018[BC]
ram:00fab8 9b mov [HL],A
ram:00fab9 a3 incw BC
ram:00faba a7 incw HL
ram:00fabb 5102 mov ,0x2
ram:00fabd 614a cmp A,
ram:00fabf dff4 bnz $ 0xfab5
ram:00fac1 c6 pop HL
ram:00fac2 c7 push HL
ram:00fac3 17 movw AX,HL
ram:00fac4 16 movw HL,AX
ram:00fac5 f7 clrw BC
ram:00fac6 491a40 mov A,!0xf401a[BC]
ram:00fac9 9b mov [HL],A
ram:00faca a3 incw BC
ram:00facb a7 incw HL
ram:00facc 5102 mov ,0x2
ram:00face 614a cmp A,
ram:00fad0 dff4 bnz $ 0xfac6
ram:00fad2 c6 pop HL
ram:00fad3 af04e4 movw AX,!0xfe404
ram:00fad6 e7 onew BC
ram:00fad7 a3 incw BC
ram:00fad8 c3 push BC
ram:00fad9 12 movw BC,AX
ram:00fada 17 movw AX,HL
ram:00fadb 040400 addw AX,0x4
ram:00fade c1 push AX
ram:00fadf 491200 mov A,!0xf0012[BC]
ram:00fae2 9dd4 mov 0xffdf4,A
ram:00fae4 791000 movw AX,!0xf0010[BC]
ram:00fae7 c1 push AX
ram:00fae8 8dd4 mov A,0xffdf4
ram:00faea 9dd6 mov 0xffdf6,A
ram:00faec c0 pop AX
ram:00faed 14 movw DE,AX
ram:00faee 305d12 movw AX,0x125d
ram:00faf1 320300 movw BC,0x3
ram:00faf4 c1 push AX
ram:00faf5 8dd6 mov A,0xffdf6
ram:00faf7 9efc mov CS,A
ram:00faf9 c0 pop AX
ram:00fafa 61ea call DE
ram:00fafc 1004 addw SP,0x4
ram:00fafe af04e4 movw AX,!0xfe404
ram:00fb01 e7 onew BC
ram:00fb02 a3 incw BC
ram:00fb03 c3 push BC
ram:00fb04 12 movw BC,AX
ram:00fb05 17 movw AX,HL
ram:00fb06 040200 addw AX,0x2
ram:00fb09 c1 push AX
ram:00fb0a 491200 mov A,!0xf0012[BC]
ram:00fb0d 9dd4 mov 0xffdf4,A
ram:00fb0f 791000 movw AX,!0xf0010[BC]
ram:00fb12 c1 push AX
ram:00fb13 8dd4 mov A,0xffdf4
ram:00fb15 9dd6 mov 0xffdf6,A
ram:00fb17 c0 pop AX
ram:00fb18 14 movw DE,AX
ram:00fb19 30fc11 movw AX,0x11fc
ram:00fb1c 320300 movw BC,0x3
ram:00fb1f c1 push AX
ram:00fb20 8dd6 mov A,0xffdf6
ram:00fb22 9efc mov CS,A
ram:00fb24 c0 pop AX
ram:00fb25 61ea call DE
ram:00fb27 1004 addw SP,0x4
ram:00fb29 af04e4 movw AX,!0xfe404
ram:00fb2c e7 onew BC
ram:00fb2d a3 incw BC
ram:00fb2e c3 push BC
ram:00fb2f 12 movw BC,AX
ram:00fb30 17 movw AX,HL
ram:00fb31 c1 push AX
ram:00fb32 491200 mov A,!0xf0012[BC]
ram:00fb35 9dd4 mov 0xffdf4,A
ram:00fb37 791000 movw AX,!0xf0010[BC]
ram:00fb3a c1 push AX
ram:00fb3b 8dd4 mov A,0xffdf4
ram:00fb3d 9dd6 mov 0xffdf6,A
ram:00fb3f c0 pop AX
ram:00fb40 14 movw DE,AX
ram:00fb41 300812 movw AX,0x1208
ram:00fb44 320300 movw BC,0x3
ram:00fb47 c1 push AX
ram:00fb48 8dd6 mov A,0xffdf6
ram:00fb4a 9efc mov CS,A
ram:00fb4c c0 pop AX
ram:00fb4d 61ea call DE
ram:00fb4f 1004 addw SP,0x4
ram:00fb51 f6 clrw AX
ram:00fb52 bf0ae6 movw !0xfe60a,AX
ram:00fb55 bf0ce6 movw !0xfe60c,AX
ram:00fb58 eed300 br $! 0xfc2e
ram:00fb5b a20ae6 incw !0xfe60a
ram:00fb5e f6 clrw AX
ram:00fb5f 420ae6 cmpw AX,!0xfe60a
ram:00fb62 61f8 sknz
ram:00fb64 a20ce6 _incw !0xfe60c
ram:00fb67 f6 clrw AX
ram:00fb68 420ce6 cmpw AX,!0xfe60c
ram:00fb6b df05 bnz $ 0xfb72
ram:00fb6d 500f mov ,0xf
ram:00fb6f 420ae6 cmpw AX,!0xfe60a
ram:00fb72 61e8 skz
ram:00fb74 eeb700 _br $! 0xfc2e
ram:00fb77 c7 push HL
ram:00fb78 17 movw AX,HL
ram:00fb79 040400 addw AX,0x4
ram:00fb7c 16 movw HL,AX
ram:00fb7d f7 clrw BC
ram:00fb7e 491c40 mov A,!0xf401c[BC]
ram:00fb81 9b mov [HL],A
ram:00fb82 a3 incw BC
ram:00fb83 a7 incw HL
ram:00fb84 5102 mov ,0x2
ram:00fb86 614a cmp A,
ram:00fb88 dff4 bnz $ 0xfb7e
ram:00fb8a c6 pop HL
ram:00fb8b c7 push HL
ram:00fb8c 17 movw AX,HL
ram:00fb8d 040200 addw AX,0x2
ram:00fb90 16 movw HL,AX
ram:00fb91 f7 clrw BC
ram:00fb92 491e40 mov A,!0xf401e[BC]
ram:00fb95 9b mov [HL],A
ram:00fb96 a3 incw BC
ram:00fb97 a7 incw HL
ram:00fb98 5102 mov ,0x2
ram:00fb9a 614a cmp A,
ram:00fb9c dff4 bnz $ 0xfb92
ram:00fb9e c6 pop HL
ram:00fb9f c7 push HL
ram:00fba0 17 movw AX,HL
ram:00fba1 16 movw HL,AX
ram:00fba2 f7 clrw BC
ram:00fba3 492040 mov A,!0xf4020[BC]
ram:00fba6 9b mov [HL],A
ram:00fba7 a3 incw BC
ram:00fba8 a7 incw HL
ram:00fba9 5102 mov ,0x2
ram:00fbab 614a cmp A,
ram:00fbad dff4 bnz $ 0xfba3
ram:00fbaf c6 pop HL
ram:00fbb0 af04e4 movw AX,!0xfe404
ram:00fbb3 e7 onew BC
ram:00fbb4 a3 incw BC
ram:00fbb5 c3 push BC
ram:00fbb6 12 movw BC,AX
ram:00fbb7 17 movw AX,HL
ram:00fbb8 040400 addw AX,0x4
ram:00fbbb c1 push AX
ram:00fbbc 491200 mov A,!0xf0012[BC]
ram:00fbbf 9dd4 mov 0xffdf4,A
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
ram:00fbd9 1004 addw SP,0x4
ram:00fbdb af04e4 movw AX,!0xfe404
ram:00fbde e7 onew BC
ram:00fbdf a3 incw BC
ram:00fbe0 c3 push BC
ram:00fbe1 12 movw BC,AX
ram:00fbe2 17 movw AX,HL
ram:00fbe3 040200 addw AX,0x2
ram:00fbe6 c1 push AX
ram:00fbe7 491200 mov A,!0xf0012[BC]
ram:00fbea 9dd4 mov 0xffdf4,A
ram:00fbec 791000 movw AX,!0xf0010[BC]
ram:00fbef c1 push AX
ram:00fbf0 8dd4 mov A,0xffdf4
ram:00fbf2 9dd6 mov 0xffdf6,A
ram:00fbf4 c0 pop AX
ram:00fbf5 14 movw DE,AX
ram:00fbf6 30fc11 movw AX,0x11fc
ram:00fbf9 320300 movw BC,0x3
ram:00fbfc c1 push AX
ram:00fbfd 8dd6 mov A,0xffdf6
ram:00fbff 9efc mov CS,A
ram:00fc01 c0 pop AX
ram:00fc02 61ea call DE
ram:00fc04 1004 addw SP,0x4
ram:00fc06 af04e4 movw AX,!0xfe404
ram:00fc09 e7 onew BC
ram:00fc0a a3 incw BC
ram:00fc0b c3 push BC
ram:00fc0c 12 movw BC,AX
ram:00fc0d 17 movw AX,HL
ram:00fc0e c1 push AX
ram:00fc0f 491200 mov A,!0xf0012[BC]
ram:00fc12 9dd4 mov 0xffdf4,A
ram:00fc14 791000 movw AX,!0xf0010[BC]
ram:00fc17 c1 push AX
ram:00fc18 8dd4 mov A,0xffdf4
ram:00fc1a 9dd6 mov 0xffdf6,A
ram:00fc1c c0 pop AX
ram:00fc1d 14 movw DE,AX
ram:00fc1e 300812 movw AX,0x1208
ram:00fc21 320300 movw BC,0x3
ram:00fc24 c1 push AX
ram:00fc25 8dd6 mov A,0xffdf6
ram:00fc27 9efc mov CS,A
ram:00fc29 c0 pop AX
ram:00fc2a 61ea call DE
ram:00fc2c 1004 addw SP,0x4
ram:00fc2e ac0a movw AX,[HL + 0xa]
ram:00fc30 bdd8 movw 0xffdf8,AX
ram:00fc32 31ff sarw AX,0xf
ram:00fc34 bdda movw 0xffdfa,AX
ram:00fc36 add8 movw AX,0xffdf8
ram:00fc38 bddc movw 0xffdfc,AX
ram:00fc3a adda movw AX,0xffdfa
ram:00fc3c bdde movw 0xffdfe,AX
ram:00fc3e ac0c movw AX,[HL + 0xc]
ram:00fc40 bdd8 movw 0xffdf8,AX
ram:00fc42 31ff sarw AX,0xf
ram:00fc44 bdda movw 0xffdfa,AX
ram:00fc46 adde movw AX,0xffdfe
ram:00fc48 fd8404 call !0xf0484
ram:00fc4b add8 movw AX,0xffdf8
ram:00fc4d bddc movw 0xffdfc,AX
ram:00fc4f adda movw AX,0xffdfa
ram:00fc51 bdde movw 0xffdfe,AX
ram:00fc53 ac0e movw AX,[HL + 0xe]
ram:00fc55 bdd8 movw 0xffdf8,AX
ram:00fc57 31ff sarw AX,0xf
ram:00fc59 bdda movw 0xffdfa,AX
ram:00fc5b adde movw AX,0xffdfe
ram:00fc5d fd8404 call !0xf0484
ram:00fc60 add8 movw AX,0xffdf8
ram:00fc62 bddc movw 0xffdfc,AX
ram:00fc64 adda movw AX,0xffdfa
ram:00fc66 bdde movw 0xffdfe,AX
ram:00fc68 ac10 movw AX,[HL + 0x10]
ram:00fc6a bdd8 movw 0xffdf8,AX
ram:00fc6c 31ff sarw AX,0xf
ram:00fc6e bdda movw 0xffdfa,AX
ram:00fc70 adde movw AX,0xffdfe
ram:00fc72 fd8404 call !0xf0484
ram:00fc75 c9dc4042 movw 0xffdfc,0x4240
ram:00fc79 300f00 movw AX,0xf
ram:00fc7c fd6805 call !0xf0568
ram:00fc7f adda movw AX,0xffdfa
ram:00fc81 bc08 movw [HL + 0x8],AX
ram:00fc83 add8 movw AX,0xffdf8
ram:00fc85 bc06 movw [HL + 0x6],AX
ram:00fc87 12 movw BC,AX
ram:00fc88 1014 addw SP,0x14
ram:00fc8a c6 pop HL
ram:00fc8b d7 ret
ram:00fc8c c7 push HL
ram:00fc8d c1 push AX
ram:00fc8e 200c subw SP,0xc
ram:00fc90 fbf8ff movw HL,!0xffff8
ram:00fc93 afd2e3 movw AX,!0xfe3d2
ram:00fc96 bc08 movw [HL + 0x8],AX
ram:00fc98 8c0c mov A,[HL + 0xc]
ram:00fc9a 91 dec 
ram:00fc9b df32 bnz $ 0xfccf
ram:00fc9d ac08 movw AX,[HL + 0x8]
ram:00fc9f bf14da movw !0xfda14,AX
ram:00fca2 8c14 mov A,[HL + 0x14]
ram:00fca4 91 dec 
ram:00fca5 df14 bnz $ 0xfcbb
ram:00fca7 30bad9 movw AX,0xd9ba
ram:00fcaa fc0e1f01 call !!0x11f0e
ram:00fcae 30bad9 movw AX,0xd9ba
ram:00fcb1 fcedf700 call !!0xf7ed
ram:00fcb5 13 movw AX,BC
ram:00fcb6 bfc2d9 movw !0xfd9c2,AX
ram:00fcb9 ef10 br $ 0xfccb
ram:00fcbb f6 clrw AX
ram:00fcbc bfbad9 movw !0xfd9ba,AX
ram:00fcbf bfbcd9 movw !0xfd9bc,AX
ram:00fcc2 bfbed9 movw !0xfd9be,AX
ram:00fcc5 bfc0d9 movw !0xfd9c0,AX
ram:00fcc8 bfc2d9 movw !0xfd9c2,AX
ram:00fccb f7 clrw BC
ram:00fccc ee2401 br $! 0xfdf3
ram:00fccf 8c14 mov A,[HL + 0x14]
ram:00fcd1 91 dec 
ram:00fcd2 df15 bnz $ 0xfce9
ram:00fcd4 30bad9 movw AX,0xd9ba
ram:00fcd7 fc0e1f01 call !!0x11f0e
ram:00fcdb 30bad9 movw AX,0xd9ba
ram:00fcde fcedf700 call !!0xf7ed
ram:00fce2 13 movw AX,BC
ram:00fce3 bfc2d9 movw !0xfd9c2,AX
ram:00fce6 eedc00 br $! 0xfdc5
ram:00fce9 17 movw AX,HL
ram:00fcea fc0e1f01 call !!0x11f0e
ram:00fcee afbad9 movw AX,!0xfd9ba
ram:00fcf1 bdd8 movw 0xffdf8,AX
ram:00fcf3 31ff sarw AX,0xf
ram:00fcf5 bdda movw 0xffdfa,AX
ram:00fcf7 add8 movw AX,0xffdf8
ram:00fcf9 bddc movw 0xffdfc,AX
ram:00fcfb adda movw AX,0xffdfa
ram:00fcfd bdde movw 0xffdfe,AX
ram:00fcff ab movw AX,[HL]
ram:00fd00 bdd8 movw 0xffdf8,AX
ram:00fd02 31ff sarw AX,0xf
ram:00fd04 bdda movw 0xffdfa,AX
ram:00fd06 adde movw AX,0xffdfe
ram:00fd08 fd5006 call !0xf0650
ram:00fd0b c9dc0200 movw 0xffdfc,0x2
ram:00fd0f f6 clrw AX
ram:00fd10 fd6805 call !0xf0568
ram:00fd13 add8 movw AX,0xffdf8
ram:00fd15 bfbad9 movw !0xfd9ba,AX
ram:00fd18 afbcd9 movw AX,!0xfd9bc
ram:00fd1b bdd8 movw 0xffdf8,AX
ram:00fd1d 31ff sarw AX,0xf
ram:00fd1f bdda movw 0xffdfa,AX
ram:00fd21 add8 movw AX,0xffdf8
ram:00fd23 bddc movw 0xffdfc,AX
ram:00fd25 adda movw AX,0xffdfa
ram:00fd27 bdde movw 0xffdfe,AX
ram:00fd29 afbcd9 movw AX,!0xfd9bc
ram:00fd2c bdd8 movw 0xffdf8,AX
ram:00fd2e 31ff sarw AX,0xf
ram:00fd30 bdda movw 0xffdfa,AX
ram:00fd32 adde movw AX,0xffdfe
ram:00fd34 fd5006 call !0xf0650
ram:00fd37 add8 movw AX,0xffdf8
ram:00fd39 bddc movw 0xffdfc,AX
ram:00fd3b adda movw AX,0xffdfa
ram:00fd3d bdde movw 0xffdfe,AX
ram:00fd3f ac02 movw AX,[HL + 0x2]
ram:00fd41 bdd8 movw 0xffdf8,AX
ram:00fd43 31ff sarw AX,0xf
ram:00fd45 bdda movw 0xffdfa,AX
ram:00fd47 adde movw AX,0xffdfe
ram:00fd49 fd5006 call !0xf0650
ram:00fd4c c9dc0300 movw 0xffdfc,0x3
ram:00fd50 f6 clrw AX
ram:00fd51 fd6805 call !0xf0568
ram:00fd54 add8 movw AX,0xffdf8
ram:00fd56 bfbcd9 movw !0xfd9bc,AX
ram:00fd59 afbed9 movw AX,!0xfd9be
ram:00fd5c bdd8 movw 0xffdf8,AX
ram:00fd5e 31ff sarw AX,0xf
ram:00fd60 bdda movw 0xffdfa,AX
ram:00fd62 add8 movw AX,0xffdf8
ram:00fd64 bddc movw 0xffdfc,AX
ram:00fd66 adda movw AX,0xffdfa
ram:00fd68 bdde movw 0xffdfe,AX
ram:00fd6a ac04 movw AX,[HL + 0x4]
ram:00fd6c bdd8 movw 0xffdf8,AX
ram:00fd6e 31ff sarw AX,0xf
ram:00fd70 bdda movw 0xffdfa,AX
ram:00fd72 adde movw AX,0xffdfe
ram:00fd74 fd5006 call !0xf0650
ram:00fd77 c9dc0200 movw 0xffdfc,0x2
ram:00fd7b f6 clrw AX
ram:00fd7c fd6805 call !0xf0568
ram:00fd7f add8 movw AX,0xffdf8
ram:00fd81 bfbed9 movw !0xfd9be,AX
ram:00fd84 afc0d9 movw AX,!0xfd9c0
ram:00fd87 bdd8 movw 0xffdf8,AX
ram:00fd89 31ff sarw AX,0xf
ram:00fd8b bdda movw 0xffdfa,AX
ram:00fd8d add8 movw AX,0xffdf8
ram:00fd8f bddc movw 0xffdfc,AX
ram:00fd91 adda movw AX,0xffdfa
ram:00fd93 bdde movw 0xffdfe,AX
ram:00fd95 afc0d9 movw AX,!0xfd9c0
ram:00fd98 bdd8 movw 0xffdf8,AX
ram:00fd9a 31ff sarw AX,0xf
ram:00fd9c bdda movw 0xffdfa,AX
ram:00fd9e adde movw AX,0xffdfe
ram:00fda0 fd5006 call !0xf0650
ram:00fda3 add8 movw AX,0xffdf8
ram:00fda5 bddc movw 0xffdfc,AX
ram:00fda7 adda movw AX,0xffdfa
ram:00fda9 bdde movw 0xffdfe,AX
ram:00fdab ac06 movw AX,[HL + 0x6]
ram:00fdad bdd8 movw 0xffdf8,AX
ram:00fdaf 31ff sarw AX,0xf
ram:00fdb1 bdda movw 0xffdfa,AX
ram:00fdb3 adde movw AX,0xffdfe
ram:00fdb5 fd5006 call !0xf0650
ram:00fdb8 c9dc0300 movw 0xffdfc,0x3
ram:00fdbc f6 clrw AX
ram:00fdbd fd6805 call !0xf0568
ram:00fdc0 add8 movw AX,0xffdf8
ram:00fdc2 bfc0d9 movw !0xfd9c0,AX
ram:00fdc5 30bad9 movw AX,0xd9ba
ram:00fdc8 fcedf700 call !!0xf7ed
ram:00fdcc 13 movw AX,BC
ram:00fdcd bc0a movw [HL + 0xa],AX
ram:00fdcf bfc2d9 movw !0xfd9c2,AX
ram:00fdd2 ac0a movw AX,[HL + 0xa]
ram:00fdd4 440d00 cmpw AX,0xd
ram:00fdd7 71fe or1 CY,A.0x7
ram:00fdd9 dc07 bc $ 0xfde2
ram:00fddb ac08 movw AX,[HL + 0x8]
ram:00fddd bf14da movw !0xfda14,AX
ram:00fde0 ef0e br $ 0xfdf0
ram:00fde2 ac08 movw AX,[HL + 0x8]
ram:00fde4 2214da subw AX,!0xfda14
ram:00fde7 44e903 cmpw AX,0x3e9
ram:00fdea dc04 bc $ 0xfdf0
ram:00fdec f6 clrw AX
ram:00fded b1 decw AX
ram:00fdee bc0a movw [HL + 0xa],AX
ram:00fdf0 ac0a movw AX,[HL + 0xa]
ram:00fdf2 12 movw BC,AX
ram:00fdf3 100e addw SP,0xe
ram:00fdf5 c6 pop HL
ram:00fdf6 d7 ret
ram:00fdf7 c7 push HL
ram:00fdf8 c1 push AX
ram:00fdf9 200c subw SP,0xc
ram:00fdfb fbf8ff movw HL,!0xffff8
ram:00fdfe ac0c movw AX,[HL + 0xc]
ram:00fe00 14 movw DE,AX
ram:00fe01 a9 movw AX,[DE]
ram:00fe02 bc04 movw [HL + 0x4],AX
ram:00fe04 ac0c movw AX,[HL + 0xc]
ram:00fe06 14 movw DE,AX
ram:00fe07 aa02 movw AX,[DE + 0x2]
ram:00fe09 bc06 movw [HL + 0x6],AX
ram:00fe0b ac0c movw AX,[HL + 0xc]
ram:00fe0d 14 movw DE,AX
ram:00fe0e aa04 movw AX,[DE + 0x4]
ram:00fe10 bc08 movw [HL + 0x8],AX
ram:00fe12 ac04 movw AX,[HL + 0x4]
ram:00fe14 bdd8 movw 0xffdf8,AX
ram:00fe16 302100 movw AX,0x21
ram:00fe19 fd1905 call !0xf0519
ram:00fe1c bc04 movw [HL + 0x4],AX
ram:00fe1e 8c05 mov A,[HL + 0x5]
ram:00fe20 01 addw AX,AX
ram:00fe21 de05 bnc $ 0xfe28
ram:00fe23 f6 clrw AX
ram:00fe24 bc04 movw [HL + 0x4],AX
ram:00fe26 ef6a br $ 0xfe92
ram:00fe28 ac04 movw AX,[HL + 0x4]
ram:00fe2a 442c01 cmpw AX,0x12c
ram:00fe2d 71fe or1 CY,A.0x7
ram:00fe2f de16 bnc $ 0xfe47
ram:00fe31 ac04 movw AX,[HL + 0x4]
ram:00fe33 bdd8 movw 0xffdf8,AX
ram:00fe35 302c00 movw AX,0x2c
ram:00fe38 fd7304 call !0xf0473
ram:00fe3b bdd8 movw 0xffdf8,AX
ram:00fe3d 302c01 movw AX,0x12c
ram:00fe40 fd1905 call !0xf0519
ram:00fe43 bc04 movw [HL + 0x4],AX
ram:00fe45 ef4b br $ 0xfe92
ram:00fe47 ac04 movw AX,[HL + 0x4]
ram:00fe49 447c01 cmpw AX,0x17c
ram:00fe4c 71fe or1 CY,A.0x7
ram:00fe4e de1a bnc $ 0xfe6a
ram:00fe50 ac04 movw AX,[HL + 0x4]
ram:00fe52 242c01 subw AX,0x12c
ram:00fe55 312d shlw AX,0x2
ram:00fe57 12 movw BC,AX
ram:00fe58 313d shlw AX,0x3
ram:00fe5a 03 addw AX,BC
ram:00fe5b bdd8 movw 0xffdf8,AX
ram:00fe5d 305000 movw AX,0x50
ram:00fe60 fd1905 call !0xf0519
ram:00fe63 042c00 addw AX,0x2c
ram:00fe66 bc04 movw [HL + 0x4],AX
ram:00fe68 ef28 br $ 0xfe92
ram:00fe6a ac04 movw AX,[HL + 0x4]
ram:00fe6c 44f401 cmpw AX,0x1f4
ram:00fe6f 71fe or1 CY,A.0x7
ram:00fe71 de1a bnc $ 0xfe8d
ram:00fe73 ac04 movw AX,[HL + 0x4]
ram:00fe75 247c01 subw AX,0x17c
ram:00fe78 312d shlw AX,0x2
ram:00fe7a 12 movw BC,AX
ram:00fe7b 312d shlw AX,0x2
ram:00fe7d 03 addw AX,BC
ram:00fe7e bdd8 movw 0xffdf8,AX
ram:00fe80 307800 movw AX,0x78
ram:00fe83 fd1905 call !0xf0519
ram:00fe86 045000 addw AX,0x50
ram:00fe89 bc04 movw [HL + 0x4],AX
ram:00fe8b ef05 br $ 0xfe92
ram:00fe8d 306400 movw AX,0x64
ram:00fe90 bc04 movw [HL + 0x4],AX
ram:00fe92 8c07 mov A,[HL + 0x7]
ram:00fe94 01 addw AX,AX
ram:00fe95 de0e bnc $ 0xfea5
ram:00fe97 ac06 movw AX,[HL + 0x6]
ram:00fe99 bdd8 movw 0xffdf8,AX
ram:00fe9b 30f0ff movw AX,0xfff0
ram:00fe9e fd1905 call !0xf0519
ram:00fea1 bc06 movw [HL + 0x6],AX
ram:00fea3 ef0c br $ 0xfeb1
ram:00fea5 ac06 movw AX,[HL + 0x6]
ram:00fea7 12 movw BC,AX
ram:00fea8 31ff sarw AX,0xf
ram:00feaa 31ce shrw AX,0xc
ram:00feac 03 addw AX,BC
ram:00fead 314f sarw AX,0x4
ram:00feaf bc06 movw [HL + 0x6],AX
ram:00feb1 ac06 movw AX,[HL + 0x6]
ram:00feb3 449101 cmpw AX,0x191
ram:00feb6 71fe or1 CY,A.0x7
ram:00feb8 dc05 bc $ 0xfebf
ram:00feba f6 clrw AX
ram:00febb bc06 movw [HL + 0x6],AX
ram:00febd ef5e br $ 0xff1d
ram:00febf ac06 movw AX,[HL + 0x6]
ram:00fec1 443300 cmpw AX,0x33
ram:00fec4 71fe or1 CY,A.0x7
ram:00fec6 dc17 bc $ 0xfedf
ram:00fec8 309001 movw AX,0x190
ram:00fecb 612906 subw AX,[HL + 0x6]
ram:00fece 01 addw AX,AX
ram:00fecf 12 movw BC,AX
ram:00fed0 312d shlw AX,0x2
ram:00fed2 03 addw AX,BC
ram:00fed3 bdd8 movw 0xffdf8,AX
ram:00fed5 305e01 movw AX,0x15e
ram:00fed8 fd1905 call !0xf0519
ram:00fedb bc06 movw [HL + 0x6],AX
ram:00fedd ef3e br $ 0xff1d
ram:00fedf ac06 movw AX,[HL + 0x6]
ram:00fee1 441500 cmpw AX,0x15
ram:00fee4 71fe or1 CY,A.0x7
ram:00fee6 dc1a bc $ 0xff02
ram:00fee8 303200 movw AX,0x32
ram:00feeb 612906 subw AX,[HL + 0x6]
ram:00feee 12 movw BC,AX
ram:00feef 315d shlw AX,0x5
ram:00fef1 23 subw AX,BC
ram:00fef2 23 subw AX,BC
ram:00fef3 bdd8 movw 0xffdf8,AX
ram:00fef5 301e00 movw AX,0x1e
ram:00fef8 fd1905 call !0xf0519
ram:00fefb 040a00 addw AX,0xa
ram:00fefe bc06 movw [HL + 0x6],AX
ram:00ff00 ef1b br $ 0xff1d
ram:00ff02 301400 movw AX,0x14
ram:00ff05 612906 subw AX,[HL + 0x6]
ram:00ff08 bdd8 movw 0xffdf8,AX
ram:00ff0a 303c00 movw AX,0x3c
ram:00ff0d fd7304 call !0xf0473
ram:00ff10 bdd8 movw 0xffdf8,AX
ram:00ff12 301400 movw AX,0x14
ram:00ff15 fd1905 call !0xf0519
ram:00ff18 042800 addw AX,0x28
ram:00ff1b bc06 movw [HL + 0x6],AX
ram:00ff1d 8c09 mov A,[HL + 0x9]
ram:00ff1f 01 addw AX,AX
ram:00ff20 de0b bnc $ 0xff2d
ram:00ff22 ac08 movw AX,[HL + 0x8]
ram:00ff24 bdd8 movw 0xffdf8,AX
ram:00ff26 f6 clrw AX
ram:00ff27 b1 decw AX
ram:00ff28 fd1905 call !0xf0519
ram:00ff2b bc08 movw [HL + 0x8],AX
ram:00ff2d 8c09 mov A,[HL + 0x9]
ram:00ff2f 01 addw AX,AX
ram:00ff30 de05 bnc $ 0xff37
ram:00ff32 f6 clrw AX
ram:00ff33 bc08 movw [HL + 0x8],AX
ram:00ff35 ef68 br $ 0xff9f
ram:00ff37 ac08 movw AX,[HL + 0x8]
ram:00ff39 440a00 cmpw AX,0xa
ram:00ff3c 71fe or1 CY,A.0x7
ram:00ff3e de13 bnc $ 0xff53
ram:00ff40 ac08 movw AX,[HL + 0x8]
ram:00ff42 12 movw BC,AX
ram:00ff43 315d shlw AX,0x5
ram:00ff45 23 subw AX,BC
ram:00ff46 23 subw AX,BC
ram:00ff47 bdd8 movw 0xffdf8,AX
ram:00ff49 300a00 movw AX,0xa
ram:00ff4c fd1905 call !0xf0519
ram:00ff4f bc08 movw [HL + 0x8],AX
ram:00ff51 ef4c br $ 0xff9f
ram:00ff53 ac08 movw AX,[HL + 0x8]
ram:00ff55 444600 cmpw AX,0x46
ram:00ff58 71fe or1 CY,A.0x7
ram:00ff5a de1c bnc $ 0xff78
ram:00ff5c ac08 movw AX,[HL + 0x8]
ram:00ff5e 240a00 subw AX,0xa
ram:00ff61 bdd8 movw 0xffdf8,AX
ram:00ff63 303c00 movw AX,0x3c
ram:00ff66 fd7304 call !0xf0473
ram:00ff69 bdd8 movw 0xffdf8,AX
ram:00ff6b 303c00 movw AX,0x3c
ram:00ff6e fd1905 call !0xf0519
ram:00ff71 041e00 addw AX,0x1e
ram:00ff74 bc08 movw [HL + 0x8],AX
ram:00ff76 ef27 br $ 0xff9f
ram:00ff78 ac08 movw AX,[HL + 0x8]
ram:00ff7a 446400 cmpw AX,0x64
ram:00ff7d 71fe or1 CY,A.0x7
ram:00ff7f de19 bnc $ 0xff9a
ram:00ff81 ac08 movw AX,[HL + 0x8]
ram:00ff83 244600 subw AX,0x46
ram:00ff86 01 addw AX,AX
ram:00ff87 12 movw BC,AX
ram:00ff88 312d shlw AX,0x2
ram:00ff8a 03 addw AX,BC
ram:00ff8b bdd8 movw 0xffdf8,AX
ram:00ff8d 301e00 movw AX,0x1e
ram:00ff90 fd1905 call !0xf0519
ram:00ff93 045a00 addw AX,0x5a
ram:00ff96 bc08 movw [HL + 0x8],AX
ram:00ff98 ef05 br $ 0xff9f
ram:00ff9a 306400 movw AX,0x64
ram:00ff9d bc08 movw [HL + 0x8],AX
ram:00ff9f 306400 movw AX,0x64
ram:00ffa2 612904 subw AX,[HL + 0x4]
ram:00ffa5 12 movw BC,AX
ram:00ffa6 d9ead9 mov X,!0xfd9ea
ram:00ffa9 f1 clrb A
ram:00ffaa bdd8 movw 0xffdf8,AX
ram:00ffac 13 movw AX,BC
ram:00ffad fd7304 call !0xf0473
ram:00ffb0 043200 addw AX,0x32
ram:00ffb3 bdd8 movw 0xffdf8,AX
ram:00ffb5 306400 movw AX,0x64
ram:00ffb8 fd1905 call !0xf0519
ram:00ffbb 12 movw BC,AX
ram:00ffbc 306400 movw AX,0x64
ram:00ffbf 23 subw AX,BC
ram:00ffc0 bc04 movw [HL + 0x4],AX
ram:00ffc2 306400 movw AX,0x64
ram:00ffc5 612906 subw AX,[HL + 0x6]
ram:00ffc8 12 movw BC,AX
ram:00ffc9 d9ebd9 mov X,!0xfd9eb
ram:00ffcc f1 clrb A
ram:00ffcd bdd8 movw 0xffdf8,AX
ram:00ffcf 13 movw AX,BC
ram:00ffd0 fd7304 call !0xf0473
ram:00ffd3 043200 addw AX,0x32
ram:00ffd6 bdd8 movw 0xffdf8,AX
ram:00ffd8 306400 movw AX,0x64
ram:00ffdb fd1905 call !0xf0519
ram:00ffde 12 movw BC,AX
ram:00ffdf 306400 movw AX,0x64
ram:00ffe2 23 subw AX,BC
ram:00ffe3 bc06 movw [HL + 0x6],AX
ram:00ffe5 306400 movw AX,0x64
ram:00ffe8 612908 subw AX,[HL + 0x8]
ram:00ffeb 12 movw BC,AX
ram:00ffec d9f5d9 mov X,!0xfd9f5
ram:00ffef f1 clrb A
ram:00fff0 bdd8 movw 0xffdf8,AX
ram:00fff2 13 movw AX,BC
ram:00fff3 fd7304 call !0xf0473
ram:00fff6 043200 addw AX,0x32
ram:00fff9 bdd8 movw 0xffdf8,AX
ram:00fffb 306400 movw AX,0x64
ram:00fffe fd1905 call !0xf0519
ram:010001 12 movw BC,AX
ram:010002 306400 movw AX,0x64
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
ram:010025 add8 movw AX,0xffdf8
ram:010027 bddc movw 0xffdfc,AX
ram:010029 adda movw AX,0xffdfa
ram:01002b bdde movw 0xffdfe,AX
ram:01002d ac08 movw AX,[HL + 0x8]
ram:01002f bdd8 movw 0xffdf8,AX
ram:010031 31ff sarw AX,0xf
ram:010033 bdda movw 0xffdfa,AX
ram:010035 adde movw AX,0xffdfe
ram:010037 fd8404 call !0xf0484
ram:01003a c9dc1027 movw 0xffdfc,0x2710
ram:01003e f6 clrw AX
ram:01003f fd6805 call !0xf0568
ram:010042 adda movw AX,0xffdfa
ram:010044 bc02 movw [HL + 0x2],AX
ram:010046 add8 movw AX,0xffdf8
ram:010048 bb movw [HL],AX
ram:010049 12 movw BC,AX
ram:01004a 100e addw SP,0xe
ram:01004c c6 pop HL
ram:01004d d7 ret
ram:01004e c7 push HL
ram:01004f c1 push AX
ram:010050 2008 subw SP,0x8
ram:010052 fbf8ff movw HL,!0xffff8
ram:010055 8c08 mov A,[HL + 0x8]
ram:010057 91 dec 
ram:010058 df14 bnz $ 0x1006e
ram:01005a f6 clrw AX
ram:01005b bfc0d9 movw !0xfd9c0,AX
ram:01005e 8c10 mov A,[HL + 0x10]
ram:010060 91 dec 
ram:010061 df07 bnz $ 0x1006a
ram:010063 30bad9 movw AX,0xd9ba
ram:010066 fcfa2001 call !!0x120fa
ram:01006a f7 clrw BC
ram:01006b eea400 br $! 0x10112
ram:01006e 8c10 mov A,[HL + 0x10]
ram:010070 91 dec 
ram:010071 df0a bnz $ 0x1007d
ram:010073 30bad9 movw AX,0xd9ba
ram:010076 fcfa2001 call !!0x120fa
ram:01007a ee8500 br $! 0x10102
ram:01007d 17 movw AX,HL
ram:01007e fcfa2001 call !!0x120fa
ram:010082 afbad9 movw AX,!0xfd9ba
ram:010085 bdd8 movw 0xffdf8,AX
ram:010087 31ff sarw AX,0xf
ram:010089 bdda movw 0xffdfa,AX
ram:01008b add8 movw AX,0xffdf8
ram:01008d bddc movw 0xffdfc,AX
ram:01008f adda movw AX,0xffdfa
ram:010091 bdde movw 0xffdfe,AX
ram:010093 ab movw AX,[HL]
ram:010094 bdd8 movw 0xffdf8,AX
ram:010096 31ff sarw AX,0xf
ram:010098 bdda movw 0xffdfa,AX
ram:01009a adde movw AX,0xffdfe
ram:01009c fd5006 call !0xf0650
ram:01009f c9dc0200 movw 0xffdfc,0x2
ram:0100a3 f6 clrw AX
ram:0100a4 fd6805 call !0xf0568
ram:0100a7 add8 movw AX,0xffdf8
ram:0100a9 bfbad9 movw !0xfd9ba,AX
ram:0100ac afbcd9 movw AX,!0xfd9bc
ram:0100af bdd8 movw 0xffdf8,AX
ram:0100b1 31ff sarw AX,0xf
ram:0100b3 bdda movw 0xffdfa,AX
ram:0100b5 add8 movw AX,0xffdf8
ram:0100b7 bddc movw 0xffdfc,AX
ram:0100b9 adda movw AX,0xffdfa
ram:0100bb bdde movw 0xffdfe,AX
ram:0100bd ac02 movw AX,[HL + 0x2]
ram:0100bf bdd8 movw 0xffdf8,AX
ram:0100c1 31ff sarw AX,0xf
ram:0100c3 bdda movw 0xffdfa,AX
ram:0100c5 adde movw AX,0xffdfe
ram:0100c7 fd5006 call !0xf0650
ram:0100ca c9dc0200 movw 0xffdfc,0x2
ram:0100ce f6 clrw AX
ram:0100cf fd6805 call !0xf0568
ram:0100d2 add8 movw AX,0xffdf8
ram:0100d4 bfbcd9 movw !0xfd9bc,AX
ram:0100d7 afbed9 movw AX,!0xfd9be
ram:0100da bdd8 movw 0xffdf8,AX
ram:0100dc 31ff sarw AX,0xf
ram:0100de bdda movw 0xffdfa,AX
ram:0100e0 add8 movw AX,0xffdf8
ram:0100e2 bddc movw 0xffdfc,AX
ram:0100e4 adda movw AX,0xffdfa
ram:0100e6 bdde movw 0xffdfe,AX
ram:0100e8 ac04 movw AX,[HL + 0x4]
ram:0100ea bdd8 movw 0xffdf8,AX
ram:0100ec 31ff sarw AX,0xf
ram:0100ee bdda movw 0xffdfa,AX
ram:0100f0 adde movw AX,0xffdfe
ram:0100f2 fd5006 call !0xf0650
ram:0100f5 c9dc0200 movw 0xffdfc,0x2
ram:0100f9 f6 clrw AX
ram:0100fa fd6805 call !0xf0568
ram:0100fd add8 movw AX,0xffdf8
ram:0100ff bfbed9 movw !0xfd9be,AX
ram:010102 30bad9 movw AX,0xd9ba
ram:010105 fcf7fd00 call !!0xfdf7
ram:010109 13 movw AX,BC
ram:01010a bc06 movw [HL + 0x6],AX
ram:01010c bfc2d9 movw !0xfd9c2,AX
ram:01010f ac06 movw AX,[HL + 0x6]
ram:010111 12 movw BC,AX
ram:010112 100a addw SP,0xa
ram:010114 c6 pop HL
ram:010115 d7 ret
ram:010116 c7 push HL
ram:010117 16 movw HL,AX
ram:010118 66 mov A,
ram:010119 9dd8 mov 0xffdf8,A
ram:01011b f4d9 clrb 0xffdf9
ram:01011d f6 clrw AX
ram:01011e bdda movw 0xffdfa,AX
ram:010120 c9dc6b03 movw 0xffdfc,0x36b
ram:010124 fd5006 call !0xf0650
ram:010127 c9dc6400 movw 0xffdfc,0x64
ram:01012b f6 clrw AX
ram:01012c fd8404 call !0xf0484
ram:01012f eada movw DE,0xffdfa
ram:010131 dad8 movw BC,0xffdf8
ram:010133 c6 pop HL
ram:010134 d7 ret
ram:010135 c7 push HL
ram:010136 c3 push BC
ram:010137 c1 push AX
ram:010138 fbf8ff movw HL,!0xffff8
ram:01013b ab movw AX,[HL]
ram:01013c bdd8 movw 0xffdf8,AX
ram:01013e ac02 movw AX,[HL + 0x2]
ram:010140 bdda movw 0xffdfa,AX
ram:010142 c9dc6400 movw 0xffdfc,0x64
ram:010146 f6 clrw AX
ram:010147 fda105 call !0xf05a1
ram:01014a c9dc6b03 movw 0xffdfc,0x36b
ram:01014e f6 clrw AX
ram:01014f fd5f06 call !0xf065f
ram:010152 8dd8 mov A,0xffdf8
ram:010154 318e shrw AX,0x8
ram:010156 12 movw BC,AX
ram:010157 1004 addw SP,0x4
ram:010159 c6 pop HL
ram:01015a d7 ret
ram:01015b c7 push HL
ram:01015c 8f71d9 mov A,!0xfd971
ram:01015f 81 inc 
ram:010160 718c mov1 CY,A.0x0
ram:010162 8f71d9 mov A,!0xfd971
ram:010165 7189 mov1 A.0x0,CY
ram:010167 9f71d9 mov !0xfd971,A
ram:01016a 5c01 and A,#0x1
ram:01016c 318e shrw AX,0x8
ram:01016e 312d shlw AX,0x2
ram:010170 12 movw BC,AX
ram:010171 313d shlw AX,0x3
ram:010173 03 addw AX,BC
ram:010174 0472d9 addw AX,0xd972
ram:010177 16 movw HL,AX
ram:010178 302400 movw AX,0x24
ram:01017b c1 push AX
ram:01017c f6 clrw AX
ram:01017d c1 push AX
ram:01017e 17 movw AX,HL
ram:01017f fc40e500 call !!0xe540
ram:010183 1004 addw SP,0x4
ram:010185 f6 clrw AX
ram:010186 fc24f001 call !!0x1f024
ram:01018a 302000 movw AX,0x20
ram:01018d c1 push AX
ram:01018e 501e mov ,0x1e
ram:010190 c1 push AX
ram:010191 30c4d9 movw AX,0xd9c4
ram:010194 fc40e500 call !!0xe540
ram:010198 1004 addw SP,0x4
ram:01019a c6 pop HL
ram:01019b d7 ret
ram:01019c c7 push HL
ram:01019d 8f71d9 mov A,!0xfd971
ram:0101a0 5c01 and A,#0x1
ram:0101a2 318e shrw AX,0x8
ram:0101a4 312d shlw AX,0x2
ram:0101a6 12 movw BC,AX
ram:0101a7 313d shlw AX,0x3
ram:0101a9 03 addw AX,BC
ram:0101aa 0472d9 addw AX,0xd972
ram:0101ad 16 movw HL,AX
ram:0101ae db08e4 movw BC,!0xfe408
ram:0101b1 8c02 mov A,[HL + 0x2]
ram:0101b3 318e shrw AX,0x8
ram:0101b5 c1 push AX
ram:0101b6 17 movw AX,HL
ram:0101b7 040300 addw AX,0x3
ram:0101ba c1 push AX
ram:0101bb 491200 mov A,!0xf0012[BC]
ram:0101be 9dd4 mov 0xffdf4,A
ram:0101c0 791000 movw AX,!0xf0010[BC]
ram:0101c3 c1 push AX
ram:0101c4 8dd4 mov A,0xffdf4
ram:0101c6 9dd6 mov 0xffdf6,A
ram:0101c8 c0 pop AX
ram:0101c9 14 movw DE,AX
ram:0101ca 301300 movw AX,0x13
ram:0101cd f7 clrw BC
ram:0101ce c1 push AX
ram:0101cf 8dd6 mov A,0xffdf6
ram:0101d1 9efc mov CS,A
ram:0101d3 c0 pop AX
ram:0101d4 61ea call DE
ram:0101d6 1004 addw SP,0x4
ram:0101d8 c6 pop HL
ram:0101d9 d7 ret
ram:0102cf c7 push HL
ram:0102d0 16 movw HL,AX
ram:0102d1 66 mov A,
ram:0102d2 3470d9 movw DE,0xd970
ram:0102d5 718c mov1 CY,A.0x0
ram:0102d7 89 mov A,[DE]
ram:0102d8 71e9 mov1 A.0x6,CY
ram:0102da 99 mov [DE],A
ram:0102db 317318 bt A.0x7,$ 0x102f5
ram:0102de 316315 bt A.0x6,$ 0x102f5
ram:0102e1 af0ae4 movw AX,!0xfe40a
ram:0102e4 f7 clrw BC
ram:0102e5 c3 push BC
ram:0102e6 14 movw DE,AX
ram:0102e7 8a0e mov A,[DE + 0xe]
ram:0102e9 9efc mov CS,A
ram:0102eb aa0c movw AX,[DE + 0xc]
ram:0102ed 14 movw DE,AX
ram:0102ee 301d00 movw AX,0x1d
ram:0102f1 61ea call DE
ram:0102f3 c0 pop AX
ram:0102f4 ef13 br $ 0x10309
ram:0102f6 af0ae4 movw AX,!0xfe40a
ram:0102f9 f7 clrw BC
ram:0102fa c3 push BC
ram:0102fb 14 movw DE,AX
ram:0102fc 8a0e mov A,[DE + 0xe]
ram:0102fe 9efc mov CS,A
ram:010300 aa0c movw AX,[DE + 0xc]
ram:010302 14 movw DE,AX
ram:010303 301c00 movw AX,0x1c
ram:010306 61ea call DE
ram:010308 c0 pop AX
ram:010309 c6 pop HL
ram:01030a d7 ret
ram:01030b c7 push HL
ram:01030c 16 movw HL,AX
ram:01030d 66 mov A,
ram:01030e 3470d9 movw DE,0xd970
ram:010311 718c mov1 CY,A.0x0
ram:010313 89 mov A,[DE]
ram:010314 71f9 mov1 A.0x7,CY
ram:010316 99 mov [DE],A
ram:010317 317318 bt A.0x7,$ 0x10331
ram:01031a 316315 bt A.0x6,$ 0x10331
ram:01031d af0ae4 movw AX,!0xfe40a
ram:010320 f7 clrw BC
ram:010321 c3 push BC
ram:010322 14 movw DE,AX
ram:010323 8a0e mov A,[DE + 0xe]
ram:010325 9efc mov CS,A
ram:010327 aa0c movw AX,[DE + 0xc]
ram:010329 14 movw DE,AX
ram:01032a 301d00 movw AX,0x1d
ram:01032d 61ea call DE
ram:01032f c0 pop AX
ram:010330 ef13 br $ 0x10345
ram:010332 af0ae4 movw AX,!0xfe40a
ram:010335 f7 clrw BC
ram:010336 c3 push BC
ram:010337 14 movw DE,AX
ram:010338 8a0e mov A,[DE + 0xe]
ram:01033a 9efc mov CS,A
ram:01033c aa0c movw AX,[DE + 0xc]
ram:01033e 14 movw DE,AX
ram:01033f 301c00 movw AX,0x1c
ram:010342 61ea call DE
ram:010344 c0 pop AX
ram:010345 c6 pop HL
ram:010346 d7 ret
ram:010347 c7 push HL
ram:010348 c1 push AX
ram:010349 2004 subw SP,0x4
ram:01034b fbf8ff movw HL,!0xffff8
ram:01034e f6 clrw AX
ram:01034f bc02 movw [HL + 0x2],AX
ram:010351 ac04 movw AX,[HL + 0x4]
ram:010353 14 movw DE,AX
ram:010354 aa04 movw AX,[DE + 0x4]
ram:010356 e7 onew BC
ram:010357 240000 subw AX,0x0
ram:01035a dd06 bz $ 0x10362
ram:01035c 23 subw AX,BC
ram:01035d dd51 bz $ 0x103b0
ram:01035f ee9b00 br $! 0x103fd
ram:010362 d917da mov X,!0xfda17
ram:010365 f1 clrb A
ram:010366 fca2e600 call !!0xe6a2
ram:01036a f6 clrw AX
ram:01036b fc8c1501 call !!0x1158c
ram:01036f af6cd9 movw AX,!0xfd96c
ram:010372 c1 push AX
ram:010373 af6ad9 movw AX,!0xfd96a
ram:010376 c1 push AX
ram:010377 d967d9 mov X,!0xfd967
ram:01037a f1 clrb A
ram:01037b c1 push AX
ram:01037c f6 clrw AX
ram:01037d fcce1401 call !!0x114ce
ram:010381 1006 addw SP,0x6
ram:010383 4016da01 cmp !0xfda16,0x1
ram:010387 df15 bnz $ 0x1039e
ram:010389 af02e4 movw AX,!0xfe402
ram:01038c 346ad9 movw DE,0xd96a
ram:01038f c5 push DE
ram:010390 14 movw DE,AX
ram:010391 8a1a mov A,[DE + 0x1a]
ram:010393 9efc mov CS,A
ram:010395 aa18 movw AX,[DE + 0x18]
ram:010397 14 movw DE,AX
ram:010398 304000 movw AX,0x40
ram:01039b 61ea call DE
ram:01039d c0 pop AX
ram:01039e ac04 movw AX,[HL + 0x4]
ram:0103a0 14 movw DE,AX
ram:0103a1 303c00 movw AX,0x3c
ram:0103a4 ba06 movw [DE + 0x6],AX
ram:0103a6 ac04 movw AX,[HL + 0x4]
ram:0103a8 14 movw DE,AX
ram:0103a9 aa04 movw AX,[DE + 0x4]
ram:0103ab a1 incw AX
ram:0103ac ba04 movw [DE + 0x4],AX
ram:0103ae ef4d br $ 0x103fd
ram:0103b0 f6 clrw AX
ram:0103b1 fcc31501 call !!0x115c3
ram:0103b5 d2 cmp0 C
ram:0103b6 df45 bnz $ 0x103fd
ram:0103b8 cc0100 mov [HL + 0x1],0x0
ram:0103bb 4067d904 cmp !0xfd967,0x4
ram:0103bf df26 bnz $ 0x103e7
ram:0103c1 f6 clrw AX
ram:0103c2 c1 push AX
ram:0103c3 e6 onew AX
ram:0103c4 fc8cfc00 call !!0xfc8c
ram:0103c8 c0 pop AX
ram:0103c9 af08e4 movw AX,!0xfe408
ram:0103cc 3468d9 movw DE,0xd968
ram:0103cf c5 push DE
ram:0103d0 14 movw DE,AX
ram:0103d1 8a0e mov A,[DE + 0xe]
ram:0103d3 9efc mov CS,A
ram:0103d5 aa0c movw AX,[DE + 0xc]
ram:0103d7 14 movw DE,AX
ram:0103d8 e6 onew AX
ram:0103d9 a1 incw AX
ram:0103da 61ea call DE
ram:0103dc c0 pop AX
ram:0103dd f6 clrw AX
ram:0103de 4268d9 cmpw AX,!0xfd968
ram:0103e1 61e8 skz
ram:0103e3 fc9c0101 _call !!0x1019c
ram:0103e7 f6 clrw AX
ram:0103e8 fc0b0301 call !!0x1030b
ram:0103ec 4018da01 cmp !0xfda18,0x1
ram:0103f0 df07 bnz $ 0x103f9
ram:0103f2 f6 clrw AX
ram:0103f3 fc267002 call !!0x27026
ram:0103f7 ef04 br $ 0x103fd
ram:0103f9 fc010902 call !!0x20901
ram:0103fd e7 onew BC
ram:0103fe 1006 addw SP,0x6
ram:010400 c6 pop HL
ram:010401 d7 ret
ram:010402 c7 push HL
ram:010403 c1 push AX
ram:010404 fbf8ff movw HL,!0xffff8
ram:010407 af08e4 movw AX,!0xfe408
ram:01040a f7 clrw BC
ram:01040b c3 push BC
ram:01040c 14 movw DE,AX
ram:01040d 8a0e mov A,[DE + 0xe]
ram:01040f 9efc mov CS,A
ram:010411 aa0c movw AX,[DE + 0xc]
ram:010413 14 movw DE,AX
ram:010414 300400 movw AX,0x4
ram:010417 61ea call DE
ram:010419 c0 pop AX
ram:01041a fc98f600 call !!0xf698
ram:01041e fc18ef01 call !!0x1ef18
ram:010422 e6 onew AX
ram:010423 fc0b0301 call !!0x1030b
ram:010427 8c0a mov A,[HL + 0xa]
ram:010429 9f18da mov !0xfda18,A
ram:01042c e565d9 oneb !0xfd965
ram:01042f e6 onew AX
ram:010430 a1 incw AX
ram:010431 c1 push AX
ram:010432 304703 movw AX,0x347
ram:010435 5201 mov ,0x1
ram:010437 f3 clrb B
ram:010438 fcea7d00 call !!0x7dea
ram:01043c c0 pop AX
ram:01043d 62 mov A,
ram:01043e 9f6ed9 mov !0xfd96e,A
ram:010441 8b mov A,[HL]
ram:010442 9f16da mov !0xfda16,A
ram:010445 8c08 mov A,[HL + 0x8]
ram:010447 9f17da mov !0xfda17,A
ram:01044a c0 pop AX
ram:01044b c6 pop HL
ram:01044c d7 ret
ram:01044d c7 push HL
ram:01044e c1 push AX
ram:01044f fbf8ff movw HL,!0xffff8
ram:010452 af08e4 movw AX,!0xfe408
ram:010455 f7 clrw BC
ram:010456 c3 push BC
ram:010457 14 movw DE,AX
ram:010458 8a0e mov A,[DE + 0xe]
ram:01045a 9efc mov CS,A
ram:01045c aa0c movw AX,[DE + 0xc]
ram:01045e 14 movw DE,AX
ram:01045f 300400 movw AX,0x4
ram:010462 61ea call DE
ram:010464 c0 pop AX
ram:010465 fc98f600 call !!0xf698
ram:010469 fc18ef01 call !!0x1ef18
ram:01046d f6 clrw AX
ram:01046e fc0b0301 call !!0x1030b
ram:010472 8c0a mov A,[HL + 0xa]
ram:010474 9f18da mov !0xfda18,A
ram:010477 e565d9 oneb !0xfd965
ram:01047a e6 onew AX
ram:01047b a1 incw AX
ram:01047c c1 push AX
ram:01047d 304703 movw AX,0x347
ram:010480 5201 mov ,0x1
ram:010482 f3 clrb B
ram:010483 fcea7d00 call !!0x7dea
ram:010487 c0 pop AX
ram:010488 62 mov A,
ram:010489 9f6ed9 mov !0xfd96e,A
ram:01048c 8b mov A,[HL]
ram:01048d 9f16da mov !0xfda16,A
ram:010490 8c08 mov A,[HL + 0x8]
ram:010492 9f17da mov !0xfda17,A
ram:010495 c0 pop AX
ram:010496 c6 pop HL
ram:010497 d7 ret
ram:010498 d7 ret
ram:010c3b c7 push HL
ram:010c3c c1 push AX
ram:010c3d 2004 subw SP,0x4
ram:010c3f fbf8ff movw HL,!0xffff8
ram:010c42 ac0e movw AX,[HL + 0xe]
ram:010c44 bc02 movw [HL + 0x2],AX
ram:010c46 ac0c movw AX,[HL + 0xc]
ram:010c48 bb movw [HL],AX
ram:010c49 8c04 mov A,[HL + 0x4]
ram:010c4b 2c03 sub A,#0x3
ram:010c4d dc12 bc $ 0x10c61
ram:010c4f d1 cmp0 A
ram:010c50 dd19 bz $ 0x10c6b
ram:010c52 91 dec 
ram:010c53 dd2f bz $ 0x10c84
ram:010c55 91 dec 
ram:010c56 dd45 bz $ 0x10c9d
ram:010c58 91 dec 
ram:010c59 dd5b bz $ 0x10cb6
ram:010c5b 91 dec 
ram:010c5c dd71 bz $ 0x10ccf
ram:010c5e ee8d00 br $! 0x10cee
ram:010c61 ac0e movw AX,[HL + 0xe]
ram:010c63 bc02 movw [HL + 0x2],AX
ram:010c65 ac0c movw AX,[HL + 0xc]
ram:010c67 bb movw [HL],AX
ram:010c68 ee8300 br $! 0x10cee
ram:010c6b ac0c movw AX,[HL + 0xc]
ram:010c6d bdd8 movw 0xffdf8,AX
ram:010c6f ac0e movw AX,[HL + 0xe]
ram:010c71 bdda movw 0xffdfa,AX
ram:010c73 c9dc1900 movw 0xffdfc,0x19
ram:010c77 f6 clrw AX
ram:010c78 fda105 call !0xf05a1
ram:010c7b adda movw AX,0xffdfa
ram:010c7d bc02 movw [HL + 0x2],AX
ram:010c7f add8 movw AX,0xffdf8
ram:010c81 bb movw [HL],AX
ram:010c82 ef6a br $ 0x10cee
ram:010c84 ac0c movw AX,[HL + 0xc]
ram:010c86 bdd8 movw 0xffdf8,AX
ram:010c88 ac0e movw AX,[HL + 0xe]
ram:010c8a bdda movw 0xffdfa,AX
ram:010c8c c9dc3200 movw 0xffdfc,0x32
ram:010c90 f6 clrw AX
ram:010c91 fda105 call !0xf05a1
ram:010c94 adda movw AX,0xffdfa
ram:010c96 bc02 movw [HL + 0x2],AX
ram:010c98 add8 movw AX,0xffdf8
ram:010c9a bb movw [HL],AX
ram:010c9b ef51 br $ 0x10cee
ram:010c9d ac0c movw AX,[HL + 0xc]
ram:010c9f bdd8 movw 0xffdf8,AX
ram:010ca1 ac0e movw AX,[HL + 0xe]
ram:010ca3 bdda movw 0xffdfa,AX
ram:010ca5 c9dc0a00 movw 0xffdfc,0xa
ram:010ca9 f6 clrw AX
ram:010caa fda105 call !0xf05a1
ram:010cad adda movw AX,0xffdfa
ram:010caf bc02 movw [HL + 0x2],AX
ram:010cb1 add8 movw AX,0xffdf8
ram:010cb3 bb movw [HL],AX
ram:010cb4 ef38 br $ 0x10cee
ram:010cb6 ac0c movw AX,[HL + 0xc]
ram:010cb8 bdd8 movw 0xffdf8,AX
ram:010cba ac0e movw AX,[HL + 0xe]
ram:010cbc bdda movw 0xffdfa,AX
ram:010cbe c9dc0a00 movw 0xffdfc,0xa
ram:010cc2 f6 clrw AX
ram:010cc3 fda105 call !0xf05a1
ram:010cc6 adda movw AX,0xffdfa
ram:010cc8 bc02 movw [HL + 0x2],AX
ram:010cca add8 movw AX,0xffdf8
ram:010ccc bb movw [HL],AX
ram:010ccd ef1f br $ 0x10cee
ram:010ccf ac0c movw AX,[HL + 0xc]
ram:010cd1 bdd8 movw 0xffdf8,AX
ram:010cd3 ac0e movw AX,[HL + 0xe]
ram:010cd5 bdda movw 0xffdfa,AX
ram:010cd7 c9dc0a00 movw 0xffdfc,0xa
ram:010cdb f6 clrw AX
ram:010cdc fda105 call !0xf05a1
ram:010cdf c9dc0020 movw 0xffdfc,0x2000
ram:010ce3 f6 clrw AX
ram:010ce4 fd5f06 call !0xf065f
ram:010ce7 adda movw AX,0xffdfa
ram:010ce9 bc02 movw [HL + 0x2],AX
ram:010ceb add8 movw AX,0xffdf8
ram:010ced bb movw [HL],AX
ram:010cee ab movw AX,[HL]
ram:010cef 12 movw BC,AX
ram:010cf0 1006 addw SP,0x6
ram:010cf2 c6 pop HL
ram:010cf3 d7 ret
ram:010cf4 c7 push HL
ram:010cf5 c1 push AX
ram:010cf6 2006 subw SP,0x6
ram:010cf8 fbf8ff movw HL,!0xffff8
ram:010cfb ac16 movw AX,[HL + 0x16]
ram:010cfd c1 push AX
ram:010cfe ac14 movw AX,[HL + 0x14]
ram:010d00 c1 push AX
ram:010d01 8c12 mov A,[HL + 0x12]
ram:010d03 318e shrw AX,0x8
ram:010d05 fc3b0c01 call !!0x10c3b
ram:010d09 1004 addw SP,0x4
ram:010d0b 13 movw AX,BC
ram:010d0c bc04 movw [HL + 0x4],AX
ram:010d0e 8c06 mov A,[HL + 0x6]
ram:010d10 f0 clrb X
ram:010d11 315e shrw AX,0x5
ram:010d13 040ee6 addw AX,0xe60e
ram:010d16 14 movw DE,AX
ram:010d17 8c0e mov A,[HL + 0xe]
ram:010d19 3159 shl A,0x5
ram:010d1b 70 mov ,A
ram:010d1c 89 mov A,[DE]
ram:010d1d 5c1f and A,#0x1f
ram:010d1f 6168 or A,
ram:010d21 99 mov [DE],A
ram:010d22 8c06 mov A,[HL + 0x6]
ram:010d24 f0 clrb X
ram:010d25 315e shrw AX,0x5
ram:010d27 040ee6 addw AX,0xe60e
ram:010d2a 14 movw DE,AX
ram:010d2b 8c10 mov A,[HL + 0x10]
ram:010d2d 718c mov1 CY,A.0x0
ram:010d2f 89 mov A,[DE]
ram:010d30 71c9 mov1 A.0x4,CY
ram:010d32 99 mov [DE],A
ram:010d33 ac04 movw AX,[HL + 0x4]
ram:010d35 318e shrw AX,0x8
ram:010d37 08 xch A,X
ram:010d38 5c1f and A,#0x1f
ram:010d3a 08 xch A,X
ram:010d3b 12 movw BC,AX
ram:010d3c 8c06 mov A,[HL + 0x6]
ram:010d3e f0 clrb X
ram:010d3f 315e shrw AX,0x5
ram:010d41 040ee6 addw AX,0xe60e
ram:010d44 14 movw DE,AX
ram:010d45 62 mov A,
ram:010d46 5c1f and A,#0x1f
ram:010d48 70 mov ,A
ram:010d49 8a01 mov A,[DE + 0x1]
ram:010d4b 5ce0 and A,#0xe0
ram:010d4d 6168 or A,
ram:010d4f 9a01 mov [DE + 0x1],A
ram:010d51 8c06 mov A,[HL + 0x6]
ram:010d53 f0 clrb X
ram:010d54 315e shrw AX,0x5
ram:010d56 040ee6 addw AX,0xe60e
ram:010d59 14 movw DE,AX
ram:010d5a 8c12 mov A,[HL + 0x12]
ram:010d5c 3159 shl A,0x5
ram:010d5e 70 mov ,A
ram:010d5f 8a01 mov A,[DE + 0x1]
ram:010d61 5c1f and A,#0x1f
ram:010d63 6168 or A,
ram:010d65 9a01 mov [DE + 0x1],A
ram:010d67 51ff mov ,0xff
ram:010d69 5e04 and A,[HL + 0x4]
ram:010d6b 318e shrw AX,0x8
ram:010d6d 12 movw BC,AX
ram:010d6e 8c06 mov A,[HL + 0x6]
ram:010d70 f0 clrb X
ram:010d71 315e shrw AX,0x5
ram:010d73 040ee6 addw AX,0xe60e
ram:010d76 14 movw DE,AX
ram:010d77 62 mov A,
ram:010d78 9a02 mov [DE + 0x2],A
ram:010d7a 8c06 mov A,[HL + 0x6]
ram:010d7c f0 clrb X
ram:010d7d 315e shrw AX,0x5
ram:010d7f 040ee6 addw AX,0xe60e
ram:010d82 14 movw DE,AX
ram:010d83 8a03 mov A,[DE + 0x3]
ram:010d85 5cef and A,#0xef
ram:010d87 9a03 mov [DE + 0x3],A
ram:010d89 8c06 mov A,[HL + 0x6]
ram:010d8b f0 clrb X
ram:010d8c 315e shrw AX,0x5
ram:010d8e 040ee6 addw AX,0xe60e
ram:010d91 14 movw DE,AX
ram:010d92 8a04 mov A,[DE + 0x4]
ram:010d94 5ccf and A,#0xcf
ram:010d96 9a04 mov [DE + 0x4],A
ram:010d98 8c06 mov A,[HL + 0x6]
ram:010d9a f0 clrb X
ram:010d9b 315e shrw AX,0x5
ram:010d9d 040ee6 addw AX,0xe60e
ram:010da0 14 movw DE,AX
ram:010da1 8c18 mov A,[HL + 0x18]
ram:010da3 5c0f and A,#0xf
ram:010da5 70 mov ,A
ram:010da6 8a04 mov A,[DE + 0x4]
ram:010da8 5cf0 and A,#0xf0
ram:010daa 6168 or A,
ram:010dac 9a04 mov [DE + 0x4],A
ram:010dae 8c12 mov A,[HL + 0x12]
ram:010db0 4c04 cmp A,#0x4
ram:010db2 df34 bnz $ 0x10de8
ram:010db4 8c06 mov A,[HL + 0x6]
ram:010db6 f0 clrb X
ram:010db7 315e shrw AX,0x5
ram:010db9 040ee6 addw AX,0xe60e
ram:010dbc 14 movw DE,AX
ram:010dbd 8a03 mov A,[DE + 0x3]
ram:010dbf 6cc0 or A,#0xc0
ram:010dc1 9a03 mov [DE + 0x3],A
ram:010dc3 8c06 mov A,[HL + 0x6]
ram:010dc5 f0 clrb X
ram:010dc6 315e shrw AX,0x5
ram:010dc8 040ee6 addw AX,0xe60e
ram:010dcb 14 movw DE,AX
ram:010dcc 8a04 mov A,[DE + 0x4]
ram:010dce 6cc0 or A,#0xc0
ram:010dd0 9a04 mov [DE + 0x4],A
ram:010dd2 8c06 mov A,[HL + 0x6]
ram:010dd4 d1 cmp0 A
ram:010dd5 df45 bnz $ 0x10e1c
ram:010dd7 8c06 mov A,[HL + 0x6]
ram:010dd9 f0 clrb X
ram:010dda 315e shrw AX,0x5
ram:010ddc 040ee6 addw AX,0xe60e
ram:010ddf 14 movw DE,AX
ram:010de0 8a03 mov A,[DE + 0x3]
ram:010de2 6c10 or A,#0x10
ram:010de4 9a03 mov [DE + 0x3],A
ram:010de6 ef34 br $ 0x10e1c
ram:010de8 8c06 mov A,[HL + 0x6]
ram:010dea f0 clrb X
ram:010deb 315e shrw AX,0x5
ram:010ded 040ee6 addw AX,0xe60e
ram:010df0 14 movw DE,AX
ram:010df1 8a03 mov A,[DE + 0x3]
ram:010df3 6cc0 or A,#0xc0
ram:010df5 9a03 mov [DE + 0x3],A
ram:010df7 8c06 mov A,[HL + 0x6]
ram:010df9 f0 clrb X
ram:010dfa 315e shrw AX,0x5
ram:010dfc 040ee6 addw AX,0xe60e
ram:010dff 14 movw DE,AX
ram:010e00 8a04 mov A,[DE + 0x4]
ram:010e02 6cc0 or A,#0xc0
ram:010e04 9a04 mov [DE + 0x4],A
ram:010e06 8c06 mov A,[HL + 0x6]
ram:010e08 91 dec 
ram:010e09 df11 bnz $ 0x10e1c
ram:010e0b 8c06 mov A,[HL + 0x6]
ram:010e0d f0 clrb X
ram:010e0e 315e shrw AX,0x5
ram:010e10 040ee6 addw AX,0xe60e
ram:010e13 14 movw DE,AX
ram:010e14 8a04 mov A,[DE + 0x4]
ram:010e16 5ccf and A,#0xcf
ram:010e18 6c10 or A,#0x10
ram:010e1a 9a04 mov [DE + 0x4],A
ram:010e1c 8c06 mov A,[HL + 0x6]
ram:010e1e d1 cmp0 A
ram:010e1f df05 bnz $ 0x10e26
ram:010e21 cc00c0 mov [HL + 0x0],0xc0
ram:010e24 ef03 br $ 0x10e29
ram:010e26 cc00c4 mov [HL + 0x0],0xc4
ram:010e29 8c06 mov A,[HL + 0x6]
ram:010e2b f0 clrb X
ram:010e2c 315e shrw AX,0x5
ram:010e2e 040ee6 addw AX,0xe60e
ram:010e31 bc02 movw [HL + 0x2],AX
ram:010e33 cc0108 mov [HL + 0x1],0x8
ram:010e36 db04e4 movw BC,!0xfe404
ram:010e39 17 movw AX,HL
ram:010e3a c1 push AX
ram:010e3b 490e00 mov A,!0xf000e[BC]
ram:010e3e 9efc mov CS,A
ram:010e40 790c00 movw AX,!0xf000c[BC]
ram:010e43 14 movw DE,AX
ram:010e44 f6 clrw AX
ram:010e45 61ea call DE
ram:010e47 c0 pop AX
ram:010e48 d2 cmp0 C
ram:010e49 df04 bnz $ 0x10e4f
ram:010e4b f7 clrw BC
ram:010e4c ee0e06 br $! 0x1145d
ram:010e4f af02e4 movw AX,!0xfe402
ram:010e52 e7 onew BC
ram:010e53 c3 push BC
ram:010e54 12 movw BC,AX
ram:010e55 17 movw AX,HL
ram:010e56 040300 addw AX,0x3
ram:010e59 c1 push AX
ram:010e5a 491600 mov A,!0xf0016[BC]
ram:010e5d 9dd4 mov 0xffdf4,A
ram:010e5f 791400 movw AX,!0xf0014[BC]
ram:010e62 c1 push AX
ram:010e63 8dd4 mov A,0xffdf4
ram:010e65 9dd6 mov 0xffdf6,A
ram:010e67 c0 pop AX
ram:010e68 14 movw DE,AX
ram:010e69 300600 movw AX,0x6
ram:010e6c f7 clrw BC
ram:010e6d c1 push AX
ram:010e6e 8dd6 mov A,0xffdf6
ram:010e70 9efc mov CS,A
ram:010e72 c0 pop AX
ram:010e73 61ea call DE
ram:010e75 1004 addw SP,0x4
ram:010e77 e6 onew AX
ram:010e78 43 cmpw AX,BC
ram:010e79 61e8 skz
ram:010e7b eede05 _br $! 0x1145c
ram:010e7e 8c03 mov A,[HL + 0x3]
ram:010e80 d1 cmp0 A
ram:010e81 61e8 skz
ram:010e83 eec301 _br $! 0x11049
ram:010e86 f6 clrw AX
ram:010e87 614916 cmpw AX,[HL + 0x16]
ram:010e8a df06 bnz $ 0x10e92
ram:010e8c 301102 movw AX,0x211
ram:010e8f 614914 cmpw AX,[HL + 0x14]
ram:010e92 de11 bnc $ 0x10ea5
ram:010e94 f6 clrw AX
ram:010e95 614916 cmpw AX,[HL + 0x16]
ram:010e98 df06 bnz $ 0x10ea0
ram:010e9a 305802 movw AX,0x258
ram:010e9d 614914 cmpw AX,[HL + 0x14]
ram:010ea0 61c8 skc
ram:010ea2 ee9901 _br $! 0x1103e
ram:010ea5 f6 clrw AX
ram:010ea6 614916 cmpw AX,[HL + 0x16]
ram:010ea9 df06 bnz $ 0x10eb1
ram:010eab 30d503 movw AX,0x3d5
ram:010eae 614914 cmpw AX,[HL + 0x14]
ram:010eb1 61f8 sknz
ram:010eb3 ee8801 _br $! 0x1103e
ram:010eb6 f6 clrw AX
ram:010eb7 614916 cmpw AX,[HL + 0x16]
ram:010eba df06 bnz $ 0x10ec2
ram:010ebc 30dd03 movw AX,0x3dd
ram:010ebf 614914 cmpw AX,[HL + 0x14]
ram:010ec2 de11 bnc $ 0x10ed5
ram:010ec4 f6 clrw AX
ram:010ec5 614916 cmpw AX,[HL + 0x16]
ram:010ec8 df06 bnz $ 0x10ed0
ram:010eca 30fc03 movw AX,0x3fc
ram:010ecd 614914 cmpw AX,[HL + 0x14]
ram:010ed0 61c8 skc
ram:010ed2 ee6901 _br $! 0x1103e
ram:010ed5 f6 clrw AX
ram:010ed6 614916 cmpw AX,[HL + 0x16]
ram:010ed9 df06 bnz $ 0x10ee1
ram:010edb 30c405 movw AX,0x5c4
ram:010ede 614914 cmpw AX,[HL + 0x14]
ram:010ee1 61f8 sknz
ram:010ee3 ee5801 _br $! 0x1103e
ram:010ee6 f6 clrw AX
ram:010ee7 614916 cmpw AX,[HL + 0x16]
ram:010eea df06 bnz $ 0x10ef2
ram:010eec 30d105 movw AX,0x5d1
ram:010eef 614914 cmpw AX,[HL + 0x14]
ram:010ef2 de11 bnc $ 0x10f05
ram:010ef4 f6 clrw AX
ram:010ef5 614916 cmpw AX,[HL + 0x16]
ram:010ef8 df06 bnz $ 0x10f00
ram:010efa 30f005 movw AX,0x5f0
ram:010efd 614914 cmpw AX,[HL + 0x14]
ram:010f00 61c8 skc
ram:010f02 ee3901 _br $! 0x1103e
ram:010f05 f6 clrw AX
ram:010f06 614916 cmpw AX,[HL + 0x16]
ram:010f09 df06 bnz $ 0x10f11
ram:010f0b 30fe04 movw AX,0x4fe
ram:010f0e 614914 cmpw AX,[HL + 0x14]
ram:010f11 61f8 sknz
ram:010f13 ee2801 _br $! 0x1103e
ram:010f16 e6 onew AX
ram:010f17 614916 cmpw AX,[HL + 0x16]
ram:010f1a df06 bnz $ 0x10f22
ram:010f1c 305c57 movw AX,0x575c
ram:010f1f 614914 cmpw AX,[HL + 0x14]
ram:010f22 61f8 sknz
ram:010f24 ee1701 _br $! 0x1103e
ram:010f27 e6 onew AX
ram:010f28 614916 cmpw AX,[HL + 0x16]
ram:010f2b df06 bnz $ 0x10f33
ram:010f2d 30a464 movw AX,0x64a4
ram:010f30 614914 cmpw AX,[HL + 0x14]
ram:010f33 61f8 sknz
ram:010f35 ee0601 _br $! 0x1103e
ram:010f38 e6 onew AX
ram:010f39 614916 cmpw AX,[HL + 0x16]
ram:010f3c df06 bnz $ 0x10f44
ram:010f3e 309866 movw AX,0x6698
ram:010f41 614914 cmpw AX,[HL + 0x14]
ram:010f44 61f8 sknz
ram:010f46 eef500 _br $! 0x1103e
ram:010f49 e6 onew AX
ram:010f4a 614916 cmpw AX,[HL + 0x16]
ram:010f4d df06 bnz $ 0x10f55
ram:010f4f 308c68 movw AX,0x688c
ram:010f52 614914 cmpw AX,[HL + 0x14]
ram:010f55 61f8 sknz
ram:010f57 eee400 _br $! 0x1103e
ram:010f5a e6 onew AX
ram:010f5b 614916 cmpw AX,[HL + 0x16]
ram:010f5e df06 bnz $ 0x10f66
ram:010f60 30e073 movw AX,0x73e0
ram:010f63 614914 cmpw AX,[HL + 0x14]
ram:010f66 61f8 sknz
ram:010f68 eed300 _br $! 0x1103e
ram:010f6b e6 onew AX
ram:010f6c 614916 cmpw AX,[HL + 0x16]
ram:010f6f df06 bnz $ 0x10f77
ram:010f71 30d475 movw AX,0x75d4
ram:010f74 614914 cmpw AX,[HL + 0x14]
ram:010f77 61f8 sknz
ram:010f79 eec200 _br $! 0x1103e
ram:010f7c e6 onew AX
ram:010f7d 614916 cmpw AX,[HL + 0x16]
ram:010f80 df06 bnz $ 0x10f88
ram:010f82 30c877 movw AX,0x77c8
ram:010f85 614914 cmpw AX,[HL + 0x14]
ram:010f88 61f8 sknz
ram:010f8a eeb100 _br $! 0x1103e
ram:010f8d e6 onew AX
ram:010f8e 614916 cmpw AX,[HL + 0x16]
ram:010f91 df06 bnz $ 0x10f99
ram:010f93 30987f movw AX,0x7f98
ram:010f96 614914 cmpw AX,[HL + 0x14]
ram:010f99 61f8 sknz
ram:010f9b eea000 _br $! 0x1103e
ram:010f9e e6 onew AX
ram:010f9f 614916 cmpw AX,[HL + 0x16]
ram:010fa2 df06 bnz $ 0x10faa
ram:010fa4 304e83 movw AX,0x834e
ram:010fa7 614914 cmpw AX,[HL + 0x14]
ram:010faa 61f8 sknz
ram:010fac ee8f00 _br $! 0x1103e
ram:010faf e6 onew AX
ram:010fb0 614916 cmpw AX,[HL + 0x16]
ram:010fb3 df06 bnz $ 0x10fbb
ram:010fb5 30ec8a movw AX,0x8aec
ram:010fb8 614914 cmpw AX,[HL + 0x14]
ram:010fbb 61f8 sknz
ram:010fbd ee7e00 _br $! 0x1103e
ram:010fc0 e6 onew AX
ram:010fc1 614916 cmpw AX,[HL + 0x16]
ram:010fc4 df06 bnz $ 0x10fcc
ram:010fc6 30d48e movw AX,0x8ed4
ram:010fc9 614914 cmpw AX,[HL + 0x14]
ram:010fcc dd70 bz $ 0x1103e
ram:010fce e6 onew AX
ram:010fcf 614916 cmpw AX,[HL + 0x16]
ram:010fd2 df06 bnz $ 0x10fda
ram:010fd4 308a92 movw AX,0x928a
ram:010fd7 614914 cmpw AX,[HL + 0x14]
ram:010fda dd62 bz $ 0x1103e
ram:010fdc e6 onew AX
ram:010fdd 614916 cmpw AX,[HL + 0x16]
ram:010fe0 df06 bnz $ 0x10fe8
ram:010fe2 30bc92 movw AX,0x92bc
ram:010fe5 614914 cmpw AX,[HL + 0x14]
ram:010fe8 dd54 bz $ 0x1103e
ram:010fea e6 onew AX
ram:010feb 614916 cmpw AX,[HL + 0x16]
ram:010fee df06 bnz $ 0x10ff6
ram:010ff0 307296 movw AX,0x9672
ram:010ff3 614914 cmpw AX,[HL + 0x14]
ram:010ff6 dd46 bz $ 0x1103e
ram:010ff8 e6 onew AX
ram:010ff9 614916 cmpw AX,[HL + 0x16]
ram:010ffc df06 bnz $ 0x11004
ram:010ffe 305a9a movw AX,0x9a5a
ram:011001 614914 cmpw AX,[HL + 0x14]
ram:011004 dd38 bz $ 0x1103e
ram:011006 e6 onew AX
ram:011007 614916 cmpw AX,[HL + 0x16]
ram:01100a df06 bnz $ 0x11012
ram:01100c 301c9c movw AX,0x9c1c
ram:01100f 614914 cmpw AX,[HL + 0x14]
ram:011012 dd2a bz $ 0x1103e
ram:011014 e6 onew AX
ram:011015 614916 cmpw AX,[HL + 0x16]
ram:011018 df06 bnz $ 0x11020
ram:01101a 30109e movw AX,0x9e10
ram:01101d 614914 cmpw AX,[HL + 0x14]
ram:011020 dd1c bz $ 0x1103e
ram:011022 e6 onew AX
ram:011023 614916 cmpw AX,[HL + 0x16]
ram:011026 df06 bnz $ 0x1102e
ram:011028 30f8a1 movw AX,0xa1f8
ram:01102b 614914 cmpw AX,[HL + 0x14]
ram:01102e dd0e bz $ 0x1103e
ram:011030 e6 onew AX
ram:011031 614916 cmpw AX,[HL + 0x16]
ram:011034 df06 bnz $ 0x1103c
ram:011036 30eca3 movw AX,0xa3ec
ram:011039 614914 cmpw AX,[HL + 0x14]
ram:01103c df05 bnz $ 0x11043
ram:01103e 716206 set1 0xffe26.0x6
ram:011041 ef03 br $ 0x11046
ram:011043 716306 clr1 0xffe26.0x6
ram:011046 ee1304 br $! 0x1145c
ram:011049 f6 clrw AX
ram:01104a 614916 cmpw AX,[HL + 0x16]
ram:01104d df06 bnz $ 0x11055
ram:01104f 301102 movw AX,0x211
ram:011052 614914 cmpw AX,[HL + 0x14]
ram:011055 de11 bnc $ 0x11068
ram:011057 f6 clrw AX
ram:011058 614916 cmpw AX,[HL + 0x16]
ram:01105b df06 bnz $ 0x11063
ram:01105d 305802 movw AX,0x258
ram:011060 614914 cmpw AX,[HL + 0x14]
ram:011063 61c8 skc
ram:011065 eeec03 _br $! 0x11454
ram:011068 f6 clrw AX
ram:011069 614916 cmpw AX,[HL + 0x16]
ram:01106c df06 bnz $ 0x11074
ram:01106e 30d503 movw AX,0x3d5
ram:011071 614914 cmpw AX,[HL + 0x14]
ram:011074 61f8 sknz
ram:011076 eedb03 _br $! 0x11454
ram:011079 f6 clrw AX
ram:01107a 614916 cmpw AX,[HL + 0x16]
ram:01107d df06 bnz $ 0x11085
ram:01107f 30e703 movw AX,0x3e7
ram:011082 614914 cmpw AX,[HL + 0x14]
ram:011085 61f8 sknz
ram:011087 eeca03 _br $! 0x11454
ram:01108a f6 clrw AX
ram:01108b 614916 cmpw AX,[HL + 0x16]
ram:01108e df06 bnz $ 0x11096
ram:011090 30dd03 movw AX,0x3dd
ram:011093 614914 cmpw AX,[HL + 0x14]
ram:011096 de11 bnc $ 0x110a9
ram:011098 f6 clrw AX
ram:011099 614916 cmpw AX,[HL + 0x16]
ram:01109c df06 bnz $ 0x110a4
ram:01109e 30fc03 movw AX,0x3fc
ram:0110a1 614914 cmpw AX,[HL + 0x14]
ram:0110a4 61c8 skc
ram:0110a6 eeab03 _br $! 0x11454
ram:0110a9 f6 clrw AX
ram:0110aa 614916 cmpw AX,[HL + 0x16]
ram:0110ad df06 bnz $ 0x110b5
ram:0110af 30c405 movw AX,0x5c4
ram:0110b2 614914 cmpw AX,[HL + 0x14]
ram:0110b5 61f8 sknz
ram:0110b7 ee9a03 _br $! 0x11454
ram:0110ba f6 clrw AX
ram:0110bb 614916 cmpw AX,[HL + 0x16]
ram:0110be df06 bnz $ 0x110c6
ram:0110c0 30d105 movw AX,0x5d1
ram:0110c3 614914 cmpw AX,[HL + 0x14]
ram:0110c6 de11 bnc $ 0x110d9
ram:0110c8 f6 clrw AX
ram:0110c9 614916 cmpw AX,[HL + 0x16]
ram:0110cc df06 bnz $ 0x110d4
ram:0110ce 30f005 movw AX,0x5f0
ram:0110d1 614914 cmpw AX,[HL + 0x14]
ram:0110d4 61c8 skc
ram:0110d6 ee7b03 _br $! 0x11454
ram:0110d9 f6 clrw AX
ram:0110da 614916 cmpw AX,[HL + 0x16]
ram:0110dd df06 bnz $ 0x110e5
ram:0110df 30fe04 movw AX,0x4fe
ram:0110e2 614914 cmpw AX,[HL + 0x14]
ram:0110e5 61f8 sknz
ram:0110e7 ee6a03 _br $! 0x11454
ram:0110ea e6 onew AX
ram:0110eb 614916 cmpw AX,[HL + 0x16]
ram:0110ee df06 bnz $ 0x110f6
ram:0110f0 309456 movw AX,0x5694
ram:0110f3 614914 cmpw AX,[HL + 0x14]
ram:0110f6 61f8 sknz
ram:0110f8 ee5903 _br $! 0x11454
ram:0110fb e6 onew AX
ram:0110fc 614916 cmpw AX,[HL + 0x16]
ram:0110ff df06 bnz $ 0x11107
ram:011101 308858 movw AX,0x5888
ram:011104 614914 cmpw AX,[HL + 0x14]
ram:011107 61f8 sknz
ram:011109 ee4803 _br $! 0x11454
ram:01110c e6 onew AX
ram:01110d 614916 cmpw AX,[HL + 0x16]
ram:011110 df06 bnz $ 0x11118
ram:011112 307c5a movw AX,0x5a7c
ram:011115 614914 cmpw AX,[HL + 0x14]
ram:011118 61f8 sknz
ram:01111a ee3703 _br $! 0x11454
ram:01111d e6 onew AX
ram:01111e 614916 cmpw AX,[HL + 0x16]
ram:011121 df06 bnz $ 0x11129
ram:011123 30705c movw AX,0x5c70
ram:011126 614914 cmpw AX,[HL + 0x14]
ram:011129 61f8 sknz
ram:01112b ee2603 _br $! 0x11454
ram:01112e e6 onew AX
ram:01112f 614916 cmpw AX,[HL + 0x16]
ram:011132 df06 bnz $ 0x1113a
ram:011134 30b062 movw AX,0x62b0
ram:011137 614914 cmpw AX,[HL + 0x14]
ram:01113a 61f8 sknz
ram:01113c ee1503 _br $! 0x11454
ram:01113f e6 onew AX
ram:011140 614916 cmpw AX,[HL + 0x16]
ram:011143 df06 bnz $ 0x1114b
ram:011145 304064 movw AX,0x6440
ram:011148 614914 cmpw AX,[HL + 0x14]
ram:01114b 61f8 sknz
ram:01114d ee0403 _br $! 0x11454
ram:011150 e6 onew AX
ram:011151 614916 cmpw AX,[HL + 0x16]
ram:011154 df06 bnz $ 0x1115c
ram:011156 30a464 movw AX,0x64a4
ram:011159 614914 cmpw AX,[HL + 0x14]
ram:01115c 61f8 sknz
ram:01115e eef302 _br $! 0x11454
ram:011161 e6 onew AX
ram:011162 614916 cmpw AX,[HL + 0x16]
ram:011165 df06 bnz $ 0x1116d
ram:011167 303466 movw AX,0x6634
ram:01116a 614914 cmpw AX,[HL + 0x14]
ram:01116d 61f8 sknz
ram:01116f eee202 _br $! 0x11454
ram:011172 e6 onew AX
ram:011173 614916 cmpw AX,[HL + 0x16]
ram:011176 df06 bnz $ 0x1117e
ram:011178 309866 movw AX,0x6698
ram:01117b 614914 cmpw AX,[HL + 0x14]
ram:01117e 61f8 sknz
ram:011180 eed102 _br $! 0x11454
ram:011183 e6 onew AX
ram:011184 614916 cmpw AX,[HL + 0x16]
ram:011187 df06 bnz $ 0x1118f
ram:011189 302868 movw AX,0x6828
ram:01118c 614914 cmpw AX,[HL + 0x14]
ram:01118f 61f8 sknz
ram:011191 eec002 _br $! 0x11454
ram:011194 e6 onew AX
ram:011195 614916 cmpw AX,[HL + 0x16]
ram:011198 df06 bnz $ 0x111a0
ram:01119a 301c6a movw AX,0x6a1c
ram:01119d 614914 cmpw AX,[HL + 0x14]
ram:0111a0 61f8 sknz
ram:0111a2 eeaf02 _br $! 0x11454
ram:0111a5 e6 onew AX
ram:0111a6 614916 cmpw AX,[HL + 0x16]
ram:0111a9 df06 bnz $ 0x111b1
ram:0111ab 30806a movw AX,0x6a80
ram:0111ae 614914 cmpw AX,[HL + 0x14]
ram:0111b1 61f8 sknz
ram:0111b3 ee9e02 _br $! 0x11454
ram:0111b6 e6 onew AX
ram:0111b7 614916 cmpw AX,[HL + 0x16]
ram:0111ba df06 bnz $ 0x111c2
ram:0111bc 30106c movw AX,0x6c10
ram:0111bf 614914 cmpw AX,[HL + 0x14]
ram:0111c2 61f8 sknz
ram:0111c4 ee8d02 _br $! 0x11454
ram:0111c7 e6 onew AX
ram:0111c8 614916 cmpw AX,[HL + 0x16]
ram:0111cb df06 bnz $ 0x111d3
ram:0111cd 30046e movw AX,0x6e04
ram:0111d0 614914 cmpw AX,[HL + 0x14]
ram:0111d3 61f8 sknz
ram:0111d5 ee7c02 _br $! 0x11454
ram:0111d8 e6 onew AX
ram:0111d9 614916 cmpw AX,[HL + 0x16]
ram:0111dc df06 bnz $ 0x111e4
ram:0111de 30f86f movw AX,0x6ff8
ram:0111e1 614914 cmpw AX,[HL + 0x14]
ram:0111e4 61f8 sknz
ram:0111e6 ee6b02 _br $! 0x11454
ram:0111e9 e6 onew AX
ram:0111ea 614916 cmpw AX,[HL + 0x16]
ram:0111ed df06 bnz $ 0x111f5
ram:0111ef 30ec71 movw AX,0x71ec
ram:0111f2 614914 cmpw AX,[HL + 0x14]
ram:0111f5 61f8 sknz
ram:0111f7 ee5a02 _br $! 0x11454
ram:0111fa e6 onew AX
ram:0111fb 614916 cmpw AX,[HL + 0x16]
ram:0111fe df06 bnz $ 0x11206
ram:011200 30e073 movw AX,0x73e0
ram:011203 614914 cmpw AX,[HL + 0x14]
ram:011206 61f8 sknz
ram:011208 ee4902 _br $! 0x11454
ram:01120b e6 onew AX
ram:01120c 614916 cmpw AX,[HL + 0x16]
ram:01120f df06 bnz $ 0x11217
ram:011211 30d475 movw AX,0x75d4
ram:011214 614914 cmpw AX,[HL + 0x14]
ram:011217 61f8 sknz
ram:011219 ee3802 _br $! 0x11454
ram:01121c e6 onew AX
ram:01121d 614916 cmpw AX,[HL + 0x16]
ram:011220 df06 bnz $ 0x11228
ram:011222 30c877 movw AX,0x77c8
ram:011225 614914 cmpw AX,[HL + 0x14]
ram:011228 61f8 sknz
ram:01122a ee2702 _br $! 0x11454
ram:01122d e6 onew AX
ram:01122e 614916 cmpw AX,[HL + 0x16]
ram:011231 df06 bnz $ 0x11239
ram:011233 30b07b movw AX,0x7bb0
ram:011236 614914 cmpw AX,[HL + 0x14]
ram:011239 61f8 sknz
ram:01123b ee1602 _br $! 0x11454
ram:01123e e6 onew AX
ram:01123f 614916 cmpw AX,[HL + 0x16]
ram:011242 df06 bnz $ 0x1124a
ram:011244 30a47d movw AX,0x7da4
ram:011247 614914 cmpw AX,[HL + 0x14]
ram:01124a 61f8 sknz
ram:01124c ee0502 _br $! 0x11454
ram:01124f e6 onew AX
ram:011250 614916 cmpw AX,[HL + 0x16]
ram:011253 df06 bnz $ 0x1125b
ram:011255 30987f movw AX,0x7f98
ram:011258 614914 cmpw AX,[HL + 0x14]
ram:01125b 61f8 sknz
ram:01125d eef401 _br $! 0x11454
ram:011260 e6 onew AX
ram:011261 614916 cmpw AX,[HL + 0x16]
ram:011264 df06 bnz $ 0x1126c
ram:011266 308c81 movw AX,0x818c
ram:011269 614914 cmpw AX,[HL + 0x14]
ram:01126c 61f8 sknz
ram:01126e eee301 _br $! 0x11454
ram:011271 e6 onew AX
ram:011272 614916 cmpw AX,[HL + 0x16]
ram:011275 df06 bnz $ 0x1127d
ram:011277 301c83 movw AX,0x831c
ram:01127a 614914 cmpw AX,[HL + 0x14]
ram:01127d 61f8 sknz
ram:01127f eed201 _br $! 0x11454
ram:011282 e6 onew AX
ram:011283 614916 cmpw AX,[HL + 0x16]
ram:011286 df06 bnz $ 0x1128e
ram:011288 307485 movw AX,0x8574
ram:01128b 614914 cmpw AX,[HL + 0x14]
ram:01128e 61f8 sknz
ram:011290 eec101 _br $! 0x11454
ram:011293 e6 onew AX
ram:011294 614916 cmpw AX,[HL + 0x16]
ram:011297 df06 bnz $ 0x1129f
ram:011299 306887 movw AX,0x8768
ram:01129c 614914 cmpw AX,[HL + 0x14]
ram:01129f 61f8 sknz
ram:0112a1 eeb001 _br $! 0x11454
ram:0112a4 e6 onew AX
ram:0112a5 614916 cmpw AX,[HL + 0x16]
ram:0112a8 df06 bnz $ 0x112b0
ram:0112aa 309488 movw AX,0x8894
ram:0112ad 614914 cmpw AX,[HL + 0x14]
ram:0112b0 61f8 sknz
ram:0112b2 ee9f01 _br $! 0x11454
ram:0112b5 e6 onew AX
ram:0112b6 614916 cmpw AX,[HL + 0x16]
ram:0112b9 df06 bnz $ 0x112c1
ram:0112bb 30f888 movw AX,0x88f8
ram:0112be 614914 cmpw AX,[HL + 0x14]
ram:0112c1 61f8 sknz
ram:0112c3 ee8e01 _br $! 0x11454
ram:0112c6 e6 onew AX
ram:0112c7 614916 cmpw AX,[HL + 0x16]
ram:0112ca df06 bnz $ 0x112d2
ram:0112cc 305c89 movw AX,0x895c
ram:0112cf 614914 cmpw AX,[HL + 0x14]
ram:0112d2 61f8 sknz
ram:0112d4 ee7d01 _br $! 0x11454
ram:0112d7 e6 onew AX
ram:0112d8 614916 cmpw AX,[HL + 0x16]
ram:0112db df06 bnz $ 0x112e3
ram:0112dd 30888a movw AX,0x8a88
ram:0112e0 614914 cmpw AX,[HL + 0x14]
ram:0112e3 61f8 sknz
ram:0112e5 ee6c01 _br $! 0x11454
ram:0112e8 e6 onew AX
ram:0112e9 614916 cmpw AX,[HL + 0x16]
ram:0112ec df06 bnz $ 0x112f4
ram:0112ee 30508b movw AX,0x8b50
ram:0112f1 614914 cmpw AX,[HL + 0x14]
ram:0112f4 61f8 sknz
ram:0112f6 ee5b01 _br $! 0x11454
ram:0112f9 e6 onew AX
ram:0112fa 614916 cmpw AX,[HL + 0x16]
ram:0112fd df06 bnz $ 0x11305
ram:0112ff 30d48e movw AX,0x8ed4
ram:011302 614914 cmpw AX,[HL + 0x14]
ram:011305 61f8 sknz
ram:011307 ee4a01 _br $! 0x11454
ram:01130a e6 onew AX
ram:01130b 614916 cmpw AX,[HL + 0x16]
ram:01130e df06 bnz $ 0x11316
ram:011310 30c890 movw AX,0x90c8
ram:011313 614914 cmpw AX,[HL + 0x14]
ram:011316 61f8 sknz
ram:011318 ee3901 _br $! 0x11454
ram:01131b e6 onew AX
ram:01131c 614916 cmpw AX,[HL + 0x16]
ram:01131f df06 bnz $ 0x11327
ram:011321 302c91 movw AX,0x912c
ram:011324 614914 cmpw AX,[HL + 0x14]
ram:011327 61f8 sknz
ram:011329 ee2801 _br $! 0x11454
ram:01132c e6 onew AX
ram:01132d 614916 cmpw AX,[HL + 0x16]
ram:011330 df06 bnz $ 0x11338
ram:011332 305892 movw AX,0x9258
ram:011335 614914 cmpw AX,[HL + 0x14]
ram:011338 61f8 sknz
ram:01133a ee1701 _br $! 0x11454
ram:01133d e6 onew AX
ram:01133e 614916 cmpw AX,[HL + 0x16]
ram:011341 df06 bnz $ 0x11349
ram:011343 308a92 movw AX,0x928a
ram:011346 614914 cmpw AX,[HL + 0x14]
ram:011349 61f8 sknz
ram:01134b ee0601 _br $! 0x11454
ram:01134e e6 onew AX
ram:01134f 614916 cmpw AX,[HL + 0x16]
ram:011352 df06 bnz $ 0x1135a
ram:011354 30bc92 movw AX,0x92bc
ram:011357 614914 cmpw AX,[HL + 0x14]
ram:01135a 61f8 sknz
ram:01135c eef500 _br $! 0x11454
ram:01135f e6 onew AX
ram:011360 614916 cmpw AX,[HL + 0x16]
ram:011363 df06 bnz $ 0x1136b
ram:011365 30b094 movw AX,0x94b0
ram:011368 614914 cmpw AX,[HL + 0x14]
ram:01136b 61f8 sknz
ram:01136d eee400 _br $! 0x11454
ram:011370 e6 onew AX
ram:011371 614916 cmpw AX,[HL + 0x16]
ram:011374 df06 bnz $ 0x1137c
ram:011376 307296 movw AX,0x9672
ram:011379 614914 cmpw AX,[HL + 0x14]
ram:01137c 61f8 sknz
ram:01137e eed300 _br $! 0x11454
ram:011381 e6 onew AX
ram:011382 614916 cmpw AX,[HL + 0x16]
ram:011385 df06 bnz $ 0x1138d
ram:011387 30a496 movw AX,0x96a4
ram:01138a 614914 cmpw AX,[HL + 0x14]
ram:01138d 61f8 sknz
ram:01138f eec200 _br $! 0x11454
ram:011392 e6 onew AX
ram:011393 614916 cmpw AX,[HL + 0x16]
ram:011396 df06 bnz $ 0x1139e
ram:011398 309898 movw AX,0x9898
ram:01139b 614914 cmpw AX,[HL + 0x14]
ram:01139e 61f8 sknz
ram:0113a0 eeb100 _br $! 0x11454
ram:0113a3 e6 onew AX
ram:0113a4 614916 cmpw AX,[HL + 0x16]
ram:0113a7 df06 bnz $ 0x113af
ram:0113a9 30ca98 movw AX,0x98ca
ram:0113ac 614914 cmpw AX,[HL + 0x14]
ram:0113af 61f8 sknz
ram:0113b1 eea000 _br $! 0x11454
ram:0113b4 e6 onew AX
ram:0113b5 614916 cmpw AX,[HL + 0x16]
ram:0113b8 df06 bnz $ 0x113c0
ram:0113ba 305a9a movw AX,0x9a5a
ram:0113bd 614914 cmpw AX,[HL + 0x14]
ram:0113c0 61f8 sknz
ram:0113c2 ee8f00 _br $! 0x11454
ram:0113c5 e6 onew AX
ram:0113c6 614916 cmpw AX,[HL + 0x16]
ram:0113c9 df06 bnz $ 0x113d1
ram:0113cb 308c9a movw AX,0x9a8c
ram:0113ce 614914 cmpw AX,[HL + 0x14]
ram:0113d1 61f8 sknz
ram:0113d3 ee7e00 _br $! 0x11454
ram:0113d6 e6 onew AX
ram:0113d7 614916 cmpw AX,[HL + 0x16]
ram:0113da df06 bnz $ 0x113e2
ram:0113dc 301c9c movw AX,0x9c1c
ram:0113df 614914 cmpw AX,[HL + 0x14]
ram:0113e2 dd70 bz $ 0x11454
ram:0113e4 e6 onew AX
ram:0113e5 614916 cmpw AX,[HL + 0x16]
ram:0113e8 df06 bnz $ 0x113f0
ram:0113ea 30809c movw AX,0x9c80
ram:0113ed 614914 cmpw AX,[HL + 0x14]
ram:0113f0 dd62 bz $ 0x11454
ram:0113f2 e6 onew AX
ram:0113f3 614916 cmpw AX,[HL + 0x16]
ram:0113f6 df06 bnz $ 0x113fe
ram:0113f8 30109e movw AX,0x9e10
ram:0113fb 614914 cmpw AX,[HL + 0x14]
ram:0113fe dd54 bz $ 0x11454
ram:011400 e6 onew AX
ram:011401 614916 cmpw AX,[HL + 0x16]
ram:011404 df06 bnz $ 0x1140c
ram:011406 30429e movw AX,0x9e42
ram:011409 614914 cmpw AX,[HL + 0x14]
ram:01140c dd46 bz $ 0x11454
ram:01140e e6 onew AX
ram:01140f 614916 cmpw AX,[HL + 0x16]
ram:011412 df06 bnz $ 0x1141a
ram:011414 3068a0 movw AX,0xa068
ram:011417 614914 cmpw AX,[HL + 0x14]
ram:01141a dd38 bz $ 0x11454
ram:01141c e6 onew AX
ram:01141d 614916 cmpw AX,[HL + 0x16]
ram:011420 df06 bnz $ 0x11428
ram:011422 30f8a1 movw AX,0xa1f8
ram:011425 614914 cmpw AX,[HL + 0x14]
ram:011428 dd2a bz $ 0x11454
ram:01142a e6 onew AX
ram:01142b 614916 cmpw AX,[HL + 0x16]
ram:01142e df06 bnz $ 0x11436
ram:011430 305ca2 movw AX,0xa25c
ram:011433 614914 cmpw AX,[HL + 0x14]
ram:011436 dd1c bz $ 0x11454
ram:011438 e6 onew AX
ram:011439 614916 cmpw AX,[HL + 0x16]
ram:01143c df06 bnz $ 0x11444
ram:01143e 30eca3 movw AX,0xa3ec
ram:011441 614914 cmpw AX,[HL + 0x14]
ram:011444 dd0e bz $ 0x11454
ram:011446 e6 onew AX
ram:011447 614916 cmpw AX,[HL + 0x16]
ram:01144a df06 bnz $ 0x11452
ram:01144c 3050a4 movw AX,0xa450
ram:01144f 614914 cmpw AX,[HL + 0x14]
ram:011452 df05 bnz $ 0x11459
ram:011454 716206 set1 0xffe26.0x6
ram:011457 ef03 br $ 0x1145c
ram:011459 716306 clr1 0xffe26.0x6
ram:01145c e7 onew BC
ram:01145d 1008 addw SP,0x8
ram:01145f c6 pop HL
ram:011460 d7 ret
ram:011461 c7 push HL
ram:011462 c1 push AX
ram:011463 c1 push AX
ram:011464 fbf8ff movw HL,!0xffff8
ram:011467 cc0100 mov [HL + 0x1],0x0
ram:01146a 8c0a mov A,[HL + 0xa]
ram:01146c 2c04 sub A,#0x4
ram:01146e dc0c bc $ 0x1147c
ram:011470 d1 cmp0 A
ram:011471 dd15 bz $ 0x11488
ram:011473 91 dec 
ram:011474 dd1c bz $ 0x11492
ram:011476 91 dec 
ram:011477 dd19 bz $ 0x11492
ram:011479 91 dec 
ram:01147a ef16 br $ 0x11492
ram:01147c 8c02 mov A,[HL + 0x2]
ram:01147e d1 cmp0 A
ram:01147f df11 bnz $ 0x11492
ram:011481 8f43da mov A,!0xfda43
ram:011484 9c01 mov [HL + 0x1],A
ram:011486 ef0a br $ 0x11492
ram:011488 8c02 mov A,[HL + 0x2]
ram:01148a d1 cmp0 A
ram:01148b df05 bnz $ 0x11492
ram:01148d 8f42da mov A,!0xfda42
ram:011490 9c01 mov [HL + 0x1],A
ram:011492 8c01 mov A,[HL + 0x1]
ram:011494 318e shrw AX,0x8
ram:011496 12 movw BC,AX
ram:011497 1004 addw SP,0x4
ram:011499 c6 pop HL
ram:01149a d7 ret
ram:0114ce c7 push HL
ram:0114cf c1 push AX
ram:0114d0 fbf8ff movw HL,!0xffff8
ram:0114d3 8c08 mov A,[HL + 0x8]
ram:0114d5 318e shrw AX,0x8
ram:0114d7 c1 push AX
ram:0114d8 8b mov A,[HL]
ram:0114d9 318e shrw AX,0x8
ram:0114db fc611401 call !!0x11461
ram:0114df c0 pop AX
ram:0114e0 f3 clrb B
ram:0114e1 c3 push BC
ram:0114e2 ac0c movw AX,[HL + 0xc]
ram:0114e4 c1 push AX
ram:0114e5 ac0a movw AX,[HL + 0xa]
ram:0114e7 c1 push AX
ram:0114e8 8c08 mov A,[HL + 0x8]
ram:0114ea 318e shrw AX,0x8
ram:0114ec c1 push AX
ram:0114ed e6 onew AX
ram:0114ee c1 push AX
ram:0114ef c1 push AX
ram:0114f0 8b mov A,[HL]
ram:0114f1 318e shrw AX,0x8
ram:0114f3 fcf40c01 call !!0x10cf4
ram:0114f7 100c addw SP,0xc
ram:0114f9 f3 clrb B
ram:0114fa c0 pop AX
ram:0114fb c6 pop HL
ram:0114fc d7 ret
ram:0114fd c7 push HL
ram:0114fe c1 push AX
ram:0114ff 2006 subw SP,0x6
ram:011501 fbf8ff movw HL,!0xffff8
ram:011504 8c0e mov A,[HL + 0xe]
ram:011506 318e shrw AX,0x8
ram:011508 c1 push AX
ram:011509 8c06 mov A,[HL + 0x6]
ram:01150b 318e shrw AX,0x8
ram:01150d fc611401 call !!0x11461
ram:011511 c0 pop AX
ram:011512 f3 clrb B
ram:011513 c3 push BC
ram:011514 ac12 movw AX,[HL + 0x12]
ram:011516 c1 push AX
ram:011517 ac10 movw AX,[HL + 0x10]
ram:011519 c1 push AX
ram:01151a 8c0e mov A,[HL + 0xe]
ram:01151c 318e shrw AX,0x8
ram:01151e c1 push AX
ram:01151f f6 clrw AX
ram:011520 c1 push AX
ram:011521 c1 push AX
ram:011522 8c06 mov A,[HL + 0x6]
ram:011524 318e shrw AX,0x8
ram:011526 fcf40c01 call !!0x10cf4
ram:01152a 100c addw SP,0xc
ram:01152c cc0160 mov [HL + 0x1],0x60
ram:01152f 8c06 mov A,[HL + 0x6]
ram:011531 d1 cmp0 A
ram:011532 df05 bnz $ 0x11539
ram:011534 cc02c0 mov [HL + 0x2],0xc0
ram:011537 ef03 br $ 0x1153c
ram:011539 cc02c4 mov [HL + 0x2],0xc4
ram:01153c 17 movw AX,HL
ram:01153d a1 incw AX
ram:01153e bc04 movw [HL + 0x4],AX
ram:011540 cc0301 mov [HL + 0x3],0x1
ram:011543 db04e4 movw BC,!0xfe404
ram:011546 17 movw AX,HL
ram:011547 040200 addw AX,0x2
ram:01154a c1 push AX
ram:01154b 490e00 mov A,!0xf000e[BC]
ram:01154e 9efc mov CS,A
ram:011550 790c00 movw AX,!0xf000c[BC]
ram:011553 14 movw DE,AX
ram:011554 f6 clrw AX
ram:011555 61ea call DE
ram:011557 c0 pop AX
ram:011558 1008 addw SP,0x8
ram:01155a c6 pop HL
ram:01155b d7 ret
ram:01155c c7 push HL
ram:01155d c1 push AX
ram:01155e fbf8ff movw HL,!0xffff8
ram:011561 8c08 mov A,[HL + 0x8]
ram:011563 318e shrw AX,0x8
ram:011565 c1 push AX
ram:011566 8b mov A,[HL]
ram:011567 318e shrw AX,0x8
ram:011569 fc611401 call !!0x11461
ram:01156d c0 pop AX
ram:01156e f3 clrb B
ram:01156f c3 push BC
ram:011570 ac0c movw AX,[HL + 0xc]
ram:011572 c1 push AX
ram:011573 ac0a movw AX,[HL + 0xa]
ram:011575 c1 push AX
ram:011576 8c08 mov A,[HL + 0x8]
ram:011578 318e shrw AX,0x8
ram:01157a c1 push AX
ram:01157b e6 onew AX
ram:01157c c1 push AX
ram:01157d 5004 mov ,0x4
ram:01157f c1 push AX
ram:011580 8b mov A,[HL]
ram:011581 318e shrw AX,0x8
ram:011583 fcf40c01 call !!0x10cf4
ram:011587 100c addw SP,0xc
ram:011589 c0 pop AX
ram:01158a c6 pop HL
ram:01158b d7 ret
ram:01158c c7 push HL
ram:01158d c1 push AX
ram:01158e 2006 subw SP,0x6
ram:011590 fbf8ff movw HL,!0xffff8
ram:011593 cc01e0 mov [HL + 0x1],0xe0
ram:011596 8c06 mov A,[HL + 0x6]
ram:011598 d1 cmp0 A
ram:011599 df05 bnz $ 0x115a0
ram:01159b cc02c0 mov [HL + 0x2],0xc0
ram:01159e ef03 br $ 0x115a3
ram:0115a0 cc02c4 mov [HL + 0x2],0xc4
ram:0115a3 17 movw AX,HL
ram:0115a4 a1 incw AX
ram:0115a5 bc04 movw [HL + 0x4],AX
ram:0115a7 cc0301 mov [HL + 0x3],0x1
ram:0115aa db04e4 movw BC,!0xfe404
ram:0115ad 17 movw AX,HL
ram:0115ae 040200 addw AX,0x2
ram:0115b1 c1 push AX
ram:0115b2 490e00 mov A,!0xf000e[BC]
ram:0115b5 9efc mov CS,A
ram:0115b7 790c00 movw AX,!0xf000c[BC]
ram:0115ba 14 movw DE,AX
ram:0115bb f6 clrw AX
ram:0115bc 61ea call DE
ram:0115be c0 pop AX
ram:0115bf 1008 addw SP,0x8
ram:0115c1 c6 pop HL
ram:0115c2 d7 ret
ram:0115c3 c7 push HL
ram:0115c4 c1 push AX
ram:0115c5 2006 subw SP,0x6
ram:0115c7 fbf8ff movw HL,!0xffff8
ram:0115ca 8c06 mov A,[HL + 0x6]
ram:0115cc d1 cmp0 A
ram:0115cd df05 bnz $ 0x115d4
ram:0115cf cc02c0 mov [HL + 0x2],0xc0
ram:0115d2 ef03 br $ 0x115d7
ram:0115d4 cc02c4 mov [HL + 0x2],0xc4
ram:0115d7 17 movw AX,HL
ram:0115d8 a1 incw AX
ram:0115d9 bc04 movw [HL + 0x4],AX
ram:0115db cc0301 mov [HL + 0x3],0x1
ram:0115de db04e4 movw BC,!0xfe404
ram:0115e1 17 movw AX,HL
ram:0115e2 040200 addw AX,0x2
ram:0115e5 c1 push AX
ram:0115e6 490e00 mov A,!0xf000e[BC]
ram:0115e9 9efc mov CS,A
ram:0115eb 790c00 movw AX,!0xf000c[BC]
ram:0115ee 14 movw DE,AX
ram:0115ef e6 onew AX
ram:0115f0 61ea call DE
ram:0115f2 c0 pop AX
ram:0115f3 8c01 mov A,[HL + 0x1]
ram:0115f5 314a shr A,0x4
ram:0115f7 5c03 and A,#0x3
ram:0115f9 318e shrw AX,0x8
ram:0115fb 12 movw BC,AX
ram:0115fc 1008 addw SP,0x8
ram:0115fe c6 pop HL
ram:0115ff d7 ret
ram:01164e d51fe6 cmp0 !0xfe61f
ram:011651 dd0b bz $ 0x1165e
ram:011653 d91fe6 mov X,!0xfe61f
ram:011656 f1 clrb A
ram:011657 fc927e00 call !!0x7e92
ram:01165b f51fe6 clrb !0xfe61f
ram:01165e fcf83501 call !!0x135f8
ram:011662 cf64d902 mov !0xfd964,0x2
ram:011666 f6 clrw AX
ram:011667 fc6c3601 call !!0x1366c
ram:01166b e51ee6 oneb !0xfe61e
ram:01166e 300016 movw AX,0x1600
ram:011671 5201 mov ,0x1
ram:011673 f3 clrb B
ram:011674 fc057e00 call !!0x7e05
ram:011678 62 mov A,
ram:011679 9f1fe6 mov !0xfe61f,A
ram:01167c d7 ret
ram:01167d e51ee6 oneb !0xfe61e
ram:011680 d7 ret
ram:011681 c7 push HL
ram:011682 20b0 subw SP,0xb0
ram:011684 fbf8ff movw HL,!0xffff8
ram:011687 30b000 movw AX,0xb0
ram:01168a bb movw [HL],AX
ram:01168b db1ee4 movw BC,!0xfe41e
ram:01168e 17 movw AX,HL
ram:01168f c1 push AX
ram:011690 490e00 mov A,!0xf000e[BC]
ram:011693 9efc mov CS,A
ram:011695 790c00 movw AX,!0xf000c[BC]
ram:011698 14 movw DE,AX
ram:011699 e6 onew AX
ram:01169a 61ea call DE
ram:01169c c0 pop AX
ram:01169d 30b000 movw AX,0xb0
ram:0116a0 bb movw [HL],AX
ram:0116a1 cc025a mov [HL + 0x2],0x5a
ram:0116a4 c7 push HL
ram:0116a5 17 movw AX,HL
ram:0116a6 040400 addw AX,0x4
ram:0116a9 16 movw HL,AX
ram:0116aa 5256 mov ,0x56
ram:0116ac 92 dec 
ram:0116ad 2942da mov A,!0xfda42[C]
ram:0116b0 61f9 mov [HL + C],A
ram:0116b2 dff8 bnz $ 0x116ac
ram:0116b4 c6 pop HL
ram:0116b5 db1ee4 movw BC,!0xfe41e
ram:0116b8 17 movw AX,HL
ram:0116b9 c1 push AX
ram:0116ba 490e00 mov A,!0xf000e[BC]
ram:0116bd 9efc mov CS,A
ram:0116bf 790c00 movw AX,!0xf000c[BC]
ram:0116c2 14 movw DE,AX
ram:0116c3 f6 clrw AX
ram:0116c4 61ea call DE
ram:0116c6 c0 pop AX
ram:0116c7 d2 cmp0 C
ram:0116c8 10b0 addw SP,0xb0
ram:0116ca c6 pop HL
ram:0116cb d7 ret
ram:0116cc c7 push HL
ram:0116cd 16 movw HL,AX
ram:0116ce 17 movw AX,HL
ram:0116cf 14 movw DE,AX
ram:0116d0 ca0006 mov [DE + 0x0],0x6
ram:0116d3 ca0107 mov [DE + 0x1],0x7
ram:0116d6 a5 incw DE
ram:0116d7 a5 incw DE
ram:0116d8 a5 incw DE
ram:0116d9 a5 incw DE
ram:0116da 15 movw AX,DE
ram:0116db 042000 addw AX,0x20
ram:0116de 14 movw DE,AX
ram:0116df 30636d movw AX,0x6d63
ram:0116e2 b9 movw [DE],AX
ram:0116e3 30e200 movw AX,0xe2
ram:0116e6 ba02 movw [DE + 0x2],AX
ram:0116e8 17 movw AX,HL
ram:0116e9 14 movw DE,AX
ram:0116ea a5 incw DE
ram:0116eb a5 incw DE
ram:0116ec a5 incw DE
ram:0116ed a5 incw DE
ram:0116ee 15 movw AX,DE
ram:0116ef 042400 addw AX,0x24
ram:0116f2 14 movw DE,AX
ram:0116f3 30ec7e movw AX,0x7eec
ram:0116f6 b9 movw [DE],AX
ram:0116f7 30e200 movw AX,0xe2
ram:0116fa ba02 movw [DE + 0x2],AX
ram:0116fc 17 movw AX,HL
ram:0116fd 040400 addw AX,0x4
ram:011700 14 movw DE,AX
ram:011701 30e46f movw AX,0x6fe4
ram:011704 b9 movw [DE],AX
ram:011705 30fa00 movw AX,0xfa
ram:011708 ba02 movw [DE + 0x2],AX
ram:01170a 17 movw AX,HL
ram:01170b 040800 addw AX,0x8
ram:01170e 14 movw DE,AX
ram:01170f 30d16f movw AX,0x6fd1
ram:011712 b9 movw [DE],AX
ram:011713 30fa00 movw AX,0xfa
ram:011716 ba02 movw [DE + 0x2],AX
ram:011718 17 movw AX,HL
ram:011719 14 movw DE,AX
ram:01171a a5 incw DE
ram:01171b a5 incw DE
ram:01171c a5 incw DE
ram:01171d a5 incw DE
ram:01171e 15 movw AX,DE
ram:01171f 040800 addw AX,0x8
ram:011722 14 movw DE,AX
ram:011723 300c70 movw AX,0x700c
ram:011726 b9 movw [DE],AX
ram:011727 30fa00 movw AX,0xfa
ram:01172a ba02 movw [DE + 0x2],AX
ram:01172c 17 movw AX,HL
ram:01172d 14 movw DE,AX
ram:01172e a5 incw DE
ram:01172f a5 incw DE
ram:011730 a5 incw DE
ram:011731 a5 incw DE
ram:011732 15 movw AX,DE
ram:011733 040c00 addw AX,0xc
ram:011736 14 movw DE,AX
ram:011737 30aa6f movw AX,0x6faa
ram:01173a b9 movw [DE],AX
ram:01173b 30fa00 movw AX,0xfa
ram:01173e ba02 movw [DE + 0x2],AX
ram:011740 17 movw AX,HL
ram:011741 14 movw DE,AX
ram:011742 30c70f movw AX,0xfc7
ram:011745 ba4c movw [DE + 0x4c],AX
ram:011747 50d3 mov ,0xd3
ram:011749 bc44 movw [HL + 0x44],AX
ram:01174b 30c60f movw AX,0xfc6
ram:01174e ba46 movw [DE + 0x46],AX
ram:011750 306005 movw AX,0x560
ram:011753 bc54 movw [HL + 0x54],AX
ram:011755 c6 pop HL
ram:011756 d7 ret
ram:011757 c7 push HL
ram:011758 8806 mov A,[SP + 0x6]
ram:01175a 16 movw HL,AX
ram:01175b 67 mov A,
ram:01175c d1 cmp0 A
ram:01175d dd48 bz $ 0x117a7
ram:01175f 91 dec 
ram:011760 dd2d bz $ 0x1178f
ram:011762 2c03 sub A,#0x3
ram:011764 df57 bnz $ 0x117bd
ram:011766 67 mov A,
ram:011767 f0 clrb X
ram:011768 317e shrw AX,0x7
ram:01176a 12 movw BC,AX
ram:01176b 7986da movw AX,!0xfda86[BC]
ram:01176e f7 clrw BC
ram:01176f c3 push BC
ram:011770 c1 push AX
ram:011771 301a10 movw AX,0x101a
ram:011774 5203 mov ,0x3
ram:011776 fc161e01 call !!0x11e16
ram:01177a 1004 addw SP,0x4
ram:01177c af96da movw AX,!0xfda96
ram:01177f f7 clrw BC
ram:011780 c3 push BC
ram:011781 c1 push AX
ram:011782 301213 movw AX,0x1312
ram:011785 5203 mov ,0x3
ram:011787 fc161e01 call !!0x11e16
ram:01178b 1004 addw SP,0x4
ram:01178d ef2e br $ 0x117bd
ram:01178f 67 mov A,
ram:011790 f0 clrb X
ram:011791 317e shrw AX,0x7
ram:011793 12 movw BC,AX
ram:011794 7986da movw AX,!0xfda86[BC]
ram:011797 f7 clrw BC
ram:011798 c3 push BC
ram:011799 c1 push AX
ram:01179a 302210 movw AX,0x1022
ram:01179d 5203 mov ,0x3
ram:01179f fc161e01 call !!0x11e16
ram:0117a3 1004 addw SP,0x4
ram:0117a5 ef16 br $ 0x117bd
ram:0117a7 67 mov A,
ram:0117a8 f0 clrb X
ram:0117a9 317e shrw AX,0x7
ram:0117ab 12 movw BC,AX
ram:0117ac 7986da movw AX,!0xfda86[BC]
ram:0117af f7 clrw BC
ram:0117b0 c3 push BC
ram:0117b1 c1 push AX
ram:0117b2 302210 movw AX,0x1022
ram:0117b5 5203 mov ,0x3
ram:0117b7 fc161e01 call !!0x11e16
ram:0117bb 1004 addw SP,0x4
ram:0117bd 67 mov A,
ram:0117be f0 clrb X
ram:0117bf 315e shrw AX,0x5
ram:0117c1 0446da addw AX,0xda46
ram:0117c4 14 movw DE,AX
ram:0117c5 aa02 movw AX,[DE + 0x2]
ram:0117c7 c1 push AX
ram:0117c8 a9 movw AX,[DE]
ram:0117c9 c1 push AX
ram:0117ca 30f50f movw AX,0xff5
ram:0117cd 320500 movw BC,0x5
ram:0117d0 fc161e01 call !!0x11e16
ram:0117d4 1004 addw SP,0x4
ram:0117d6 67 mov A,
ram:0117d7 f0 clrb X
ram:0117d8 315e shrw AX,0x5
ram:0117da 044ada addw AX,0xda4a
ram:0117dd 14 movw DE,AX
ram:0117de aa02 movw AX,[DE + 0x2]
ram:0117e0 c1 push AX
ram:0117e1 a9 movw AX,[DE]
ram:0117e2 c1 push AX
ram:0117e3 30d80f movw AX,0xfd8
ram:0117e6 320500 movw BC,0x5
ram:0117e9 fc161e01 call !!0x11e16
ram:0117ed 1004 addw SP,0x4
ram:0117ef c6 pop HL
ram:0117f0 d7 ret
ram:0117f1 c7 push HL
ram:0117f2 c1 push AX
ram:0117f3 2004 subw SP,0x4
ram:0117f5 fbf8ff movw HL,!0xffff8
ram:0117f8 f6 clrw AX
ram:0117f9 bc02 movw [HL + 0x2],AX
ram:0117fb bb movw [HL],AX
ram:0117fc ab movw AX,[HL]
ram:0117fd 441e03 cmpw AX,0x31e
ram:011800 de17 bnc $ 0x11819
ram:011802 ab movw AX,[HL]
ram:011803 610904 addw AX,[HL + 0x4]
ram:011806 14 movw DE,AX
ram:011807 89 mov A,[DE]
ram:011808 72 mov ,A
ram:011809 8c02 mov A,[HL + 0x2]
ram:01180b 610a add A,
ram:01180d 70 mov ,A
ram:01180e 8c03 mov A,[HL + 0x3]
ram:011810 1c00 addc A,#0x0
ram:011812 bc02 movw [HL + 0x2],AX
ram:011814 617900 incw [HL + 0x0]
ram:011817 efe3 br $ 0x117fc
ram:011819 ac04 movw AX,[HL + 0x4]
ram:01181b 041e03 addw AX,0x31e
ram:01181e 14 movw DE,AX
ram:01181f ac02 movw AX,[HL + 0x2]
ram:011821 318e shrw AX,0x8
ram:011823 89 mov A,[DE]
ram:011824 6148 cmp A,
ram:011826 df16 bnz $ 0x1183e
ram:011828 ac04 movw AX,[HL + 0x4]
ram:01182a 041f03 addw AX,0x31f
ram:01182d 14 movw DE,AX
ram:01182e 51ff mov ,0xff
ram:011830 5e02 and A,[HL + 0x2]
ram:011832 318e shrw AX,0x8
ram:011834 12 movw BC,AX
ram:011835 89 mov A,[DE]
ram:011836 318e shrw AX,0x8
ram:011838 43 cmpw AX,BC
ram:011839 df03 bnz $ 0x1183e
ram:01183b e7 onew BC
ram:01183c ef01 br $ 0x1183f
ram:01183e f7 clrw BC
ram:01183f 1006 addw SP,0x6
ram:011841 c6 pop HL
ram:011842 d7 ret
ram:011843 c7 push HL
ram:011844 c1 push AX
ram:011845 200a subw SP,0xa
ram:011847 fbf8ff movw HL,!0xffff8
ram:01184a ac0a movw AX,[HL + 0xa]
ram:01184c fcf11701 call !!0x117f1
ram:011850 d2 cmp0 C
ram:011851 dd0e bz $ 0x11861
ram:011853 ac0a movw AX,[HL + 0xa]
ram:011855 040203 addw AX,0x302
ram:011858 14 movw DE,AX
ram:011859 89 mov A,[DE]
ram:01185a 81 inc 
ram:01185b dd04 bz $ 0x11861
ram:01185d 89 mov A,[DE]
ram:01185e d1 cmp0 A
ram:01185f df05 bnz $ 0x11866
ram:011861 304240 movw AX,0x4042
ram:011864 bc0a movw [HL + 0xa],AX
ram:011866 ac0a movw AX,[HL + 0xa]
ram:011868 bc04 movw [HL + 0x4],AX
ram:01186a f6 clrw AX
ram:01186b bc08 movw [HL + 0x8],AX
ram:01186d ac08 movw AX,[HL + 0x8]
ram:01186f 312d shlw AX,0x2
ram:011871 04ee45 addw AX,0x45ee
ram:011874 14 movw DE,AX
ram:011875 aa02 movw AX,[DE + 0x2]
ram:011877 12 movw BC,AX
ram:011878 a9 movw AX,[DE]
ram:011879 6168 or A,
ram:01187b 616b or A,
ram:01187d 616a or A,
ram:01187f dd64 bz $ 0x118e5
ram:011881 aa02 movw AX,[DE + 0x2]
ram:011883 12 movw BC,AX
ram:011884 a9 movw AX,[DE]
ram:011885 33 xchw AX,BC
ram:011886 08 xch A,X
ram:011887 5c0f and A,#0xf
ram:011889 08 xch A,X
ram:01188a f1 clrb A
ram:01188b 33 xchw AX,BC
ram:01188c bb movw [HL],AX
ram:01188d 33 xchw AX,BC
ram:01188e bc02 movw [HL + 0x2],AX
ram:011890 ac08 movw AX,[HL + 0x8]
ram:011892 312d shlw AX,0x2
ram:011894 04ee45 addw AX,0x45ee
ram:011897 14 movw DE,AX
ram:011898 a9 movw AX,[DE]
ram:011899 bdd8 movw 0xffdf8,AX
ram:01189b aa02 movw AX,[DE + 0x2]
ram:01189d bdda movw 0xffdfa,AX
ram:01189f 5118 mov ,0x18
ram:0118a1 fd8c06 call !0xf068c
ram:0118a4 c9dc0300 movw 0xffdfc,0x3
ram:0118a8 f6 clrw AX
ram:0118a9 fdb706 call !0xf06b7
ram:0118ac add8 movw AX,0xffdf8
ram:0118ae bc06 movw [HL + 0x6],AX
ram:0118b0 300f00 movw AX,0xf
ram:0118b3 614902 cmpw AX,[HL + 0x2]
ram:0118b6 df05 bnz $ 0x118bd
ram:0118b8 f6 clrw AX
ram:0118b9 b1 decw AX
ram:0118ba 614900 cmpw AX,[HL + 0x0]
ram:0118bd dd1a bz $ 0x118d9
ram:0118bf db04e4 movw BC,!0xfe404
ram:0118c2 ac06 movw AX,[HL + 0x6]
ram:0118c4 c1 push AX
ram:0118c5 ac04 movw AX,[HL + 0x4]
ram:0118c7 c1 push AX
ram:0118c8 491200 mov A,!0xf0012[BC]
ram:0118cb 9efc mov CS,A
ram:0118cd 791000 movw AX,!0xf0010[BC]
ram:0118d0 14 movw DE,AX
ram:0118d1 ac02 movw AX,[HL + 0x2]
ram:0118d3 12 movw BC,AX
ram:0118d4 ab movw AX,[HL]
ram:0118d5 61ea call DE
ram:0118d7 1004 addw SP,0x4
ram:0118d9 ac06 movw AX,[HL + 0x6]
ram:0118db 610904 addw AX,[HL + 0x4]
ram:0118de bc04 movw [HL + 0x4],AX
ram:0118e0 617908 incw [HL + 0x8]
ram:0118e3 ef88 br $ 0x1186d
ram:0118e5 ac0a movw AX,[HL + 0xa]
ram:0118e7 042b02 addw AX,0x22b
ram:0118ea bc04 movw [HL + 0x4],AX
ram:0118ec a1 incw AX
ram:0118ed bc04 movw [HL + 0x4],AX
ram:0118ef b1 decw AX
ram:0118f0 14 movw DE,AX
ram:0118f1 89 mov A,[DE]
ram:0118f2 9f25e6 mov !0xfe625,A
ram:0118f5 ac04 movw AX,[HL + 0x4]
ram:0118f7 a1 incw AX
ram:0118f8 bc04 movw [HL + 0x4],AX
ram:0118fa b1 decw AX
ram:0118fb 14 movw DE,AX
ram:0118fc 89 mov A,[DE]
ram:0118fd 9f26e6 mov !0xfe626,A
ram:011900 ac04 movw AX,[HL + 0x4]
ram:011902 a1 incw AX
ram:011903 bc04 movw [HL + 0x4],AX
ram:011905 b1 decw AX
ram:011906 14 movw DE,AX
ram:011907 89 mov A,[DE]
ram:011908 9f27e6 mov !0xfe627,A
ram:01190b ac04 movw AX,[HL + 0x4]
ram:01190d a1 incw AX
ram:01190e bc04 movw [HL + 0x4],AX
ram:011910 b1 decw AX
ram:011911 14 movw DE,AX
ram:011912 89 mov A,[DE]
ram:011913 9f28e6 mov !0xfe628,A
ram:011916 ac04 movw AX,[HL + 0x4]
ram:011918 a1 incw AX
ram:011919 bc04 movw [HL + 0x4],AX
ram:01191b b1 decw AX
ram:01191c 14 movw DE,AX
ram:01191d 89 mov A,[DE]
ram:01191e 9f2ee6 mov !0xfe62e,A
ram:011921 ac04 movw AX,[HL + 0x4]
ram:011923 a1 incw AX
ram:011924 bc04 movw [HL + 0x4],AX
ram:011926 b1 decw AX
ram:011927 14 movw DE,AX
ram:011928 89 mov A,[DE]
ram:011929 9f2fe6 mov !0xfe62f,A
ram:01192c ac04 movw AX,[HL + 0x4]
ram:01192e a1 incw AX
ram:01192f bc04 movw [HL + 0x4],AX
ram:011931 b1 decw AX
ram:011932 14 movw DE,AX
ram:011933 89 mov A,[DE]
ram:011934 9f30e6 mov !0xfe630,A
ram:011937 ac04 movw AX,[HL + 0x4]
ram:011939 a1 incw AX
ram:01193a bc04 movw [HL + 0x4],AX
ram:01193c b1 decw AX
ram:01193d 14 movw DE,AX
ram:01193e 89 mov A,[DE]
ram:01193f 9f31e6 mov !0xfe631,A
ram:011942 ac04 movw AX,[HL + 0x4]
ram:011944 a1 incw AX
ram:011945 bc04 movw [HL + 0x4],AX
ram:011947 b1 decw AX
ram:011948 14 movw DE,AX
ram:011949 89 mov A,[DE]
ram:01194a 9f67e6 mov !0xfe667,A
ram:01194d 9f38e6 mov !0xfe638,A
ram:011950 ac04 movw AX,[HL + 0x4]
ram:011952 a1 incw AX
ram:011953 bc04 movw [HL + 0x4],AX
ram:011955 b1 decw AX
ram:011956 14 movw DE,AX
ram:011957 89 mov A,[DE]
ram:011958 9f68e6 mov !0xfe668,A
ram:01195b 9f39e6 mov !0xfe639,A
ram:01195e ac04 movw AX,[HL + 0x4]
ram:011960 a1 incw AX
ram:011961 bc04 movw [HL + 0x4],AX
ram:011963 b1 decw AX
ram:011964 14 movw DE,AX
ram:011965 89 mov A,[DE]
ram:011966 9f69e6 mov !0xfe669,A
ram:011969 9f3ae6 mov !0xfe63a,A
ram:01196c ac04 movw AX,[HL + 0x4]
ram:01196e a1 incw AX
ram:01196f bc04 movw [HL + 0x4],AX
ram:011971 b1 decw AX
ram:011972 14 movw DE,AX
ram:011973 89 mov A,[DE]
ram:011974 9f6ae6 mov !0xfe66a,A
ram:011977 9f3be6 mov !0xfe63b,A
ram:01197a ac04 movw AX,[HL + 0x4]
ram:01197c a1 incw AX
ram:01197d bc04 movw [HL + 0x4],AX
ram:01197f b1 decw AX
ram:011980 14 movw DE,AX
ram:011981 89 mov A,[DE]
ram:011982 9f70e6 mov !0xfe670,A
ram:011985 9f41e6 mov !0xfe641,A
ram:011988 ac04 movw AX,[HL + 0x4]
ram:01198a a1 incw AX
ram:01198b bc04 movw [HL + 0x4],AX
ram:01198d b1 decw AX
ram:01198e 14 movw DE,AX
ram:01198f 89 mov A,[DE]
ram:011990 9f71e6 mov !0xfe671,A
ram:011993 9f42e6 mov !0xfe642,A
ram:011996 ac04 movw AX,[HL + 0x4]
ram:011998 a1 incw AX
ram:011999 bc04 movw [HL + 0x4],AX
ram:01199b b1 decw AX
ram:01199c 14 movw DE,AX
ram:01199d 89 mov A,[DE]
ram:01199e 9f72e6 mov !0xfe672,A
ram:0119a1 9f43e6 mov !0xfe643,A
ram:0119a4 ac04 movw AX,[HL + 0x4]
ram:0119a6 a1 incw AX
ram:0119a7 bc04 movw [HL + 0x4],AX
ram:0119a9 b1 decw AX
ram:0119aa 14 movw DE,AX
ram:0119ab 89 mov A,[DE]
ram:0119ac 9f73e6 mov !0xfe673,A
ram:0119af 9f44e6 mov !0xfe644,A
ram:0119b2 ac0a movw AX,[HL + 0xa]
ram:0119b4 04b201 addw AX,0x1b2
ram:0119b7 bc04 movw [HL + 0x4],AX
ram:0119b9 a1 incw AX
ram:0119ba bc04 movw [HL + 0x4],AX
ram:0119bc b1 decw AX
ram:0119bd 14 movw DE,AX
ram:0119be 89 mov A,[DE]
ram:0119bf 9f4ae6 mov !0xfe64a,A
ram:0119c2 ac04 movw AX,[HL + 0x4]
ram:0119c4 a1 incw AX
ram:0119c5 bc04 movw [HL + 0x4],AX
ram:0119c7 b1 decw AX
ram:0119c8 14 movw DE,AX
ram:0119c9 89 mov A,[DE]
ram:0119ca 9f4be6 mov !0xfe64b,A
ram:0119cd ac04 movw AX,[HL + 0x4]
ram:0119cf a1 incw AX
ram:0119d0 bc04 movw [HL + 0x4],AX
ram:0119d2 b1 decw AX
ram:0119d3 14 movw DE,AX
ram:0119d4 89 mov A,[DE]
ram:0119d5 9f4ce6 mov !0xfe64c,A
ram:0119d8 ac04 movw AX,[HL + 0x4]
ram:0119da a1 incw AX
ram:0119db bc04 movw [HL + 0x4],AX
ram:0119dd b1 decw AX
ram:0119de 14 movw DE,AX
ram:0119df 89 mov A,[DE]
ram:0119e0 9f4de6 mov !0xfe64d,A
ram:0119e3 ac04 movw AX,[HL + 0x4]
ram:0119e5 a1 incw AX
ram:0119e6 bc04 movw [HL + 0x4],AX
ram:0119e8 b1 decw AX
ram:0119e9 14 movw DE,AX
ram:0119ea 89 mov A,[DE]
ram:0119eb 9f4ee6 mov !0xfe64e,A
ram:0119ee ac04 movw AX,[HL + 0x4]
ram:0119f0 a1 incw AX
ram:0119f1 bc04 movw [HL + 0x4],AX
ram:0119f3 b1 decw AX
ram:0119f4 14 movw DE,AX
ram:0119f5 89 mov A,[DE]
ram:0119f6 9f4fe6 mov !0xfe64f,A
ram:0119f9 ac04 movw AX,[HL + 0x4]
ram:0119fb a1 incw AX
ram:0119fc bc04 movw [HL + 0x4],AX
ram:0119fe b1 decw AX
ram:0119ff 14 movw DE,AX
ram:011a00 89 mov A,[DE]
ram:011a01 9f55e6 mov !0xfe655,A
ram:011a04 ac04 movw AX,[HL + 0x4]
ram:011a06 a1 incw AX
ram:011a07 bc04 movw [HL + 0x4],AX
ram:011a09 b1 decw AX
ram:011a0a 14 movw DE,AX
ram:011a0b 89 mov A,[DE]
ram:011a0c 9f56e6 mov !0xfe656,A
ram:011a0f ac04 movw AX,[HL + 0x4]
ram:011a11 a1 incw AX
ram:011a12 bc04 movw [HL + 0x4],AX
ram:011a14 b1 decw AX
ram:011a15 14 movw DE,AX
ram:011a16 89 mov A,[DE]
ram:011a17 9f57e6 mov !0xfe657,A
ram:011a1a ac04 movw AX,[HL + 0x4]
ram:011a1c a1 incw AX
ram:011a1d bc04 movw [HL + 0x4],AX
ram:011a1f b1 decw AX
ram:011a20 14 movw DE,AX
ram:011a21 89 mov A,[DE]
ram:011a22 9f58e6 mov !0xfe658,A
ram:011a25 ac04 movw AX,[HL + 0x4]
ram:011a27 a1 incw AX
ram:011a28 bc04 movw [HL + 0x4],AX
ram:011a2a b1 decw AX
ram:011a2b 14 movw DE,AX
ram:011a2c 89 mov A,[DE]
ram:011a2d 9f5ee6 mov !0xfe65e,A
ram:011a30 ac04 movw AX,[HL + 0x4]
ram:011a32 a1 incw AX
ram:011a33 bc04 movw [HL + 0x4],AX
ram:011a35 b1 decw AX
ram:011a36 14 movw DE,AX
ram:011a37 89 mov A,[DE]
ram:011a38 9f5fe6 mov !0xfe65f,A
ram:011a3b ac04 movw AX,[HL + 0x4]
ram:011a3d a1 incw AX
ram:011a3e bc04 movw [HL + 0x4],AX
ram:011a40 b1 decw AX
ram:011a41 14 movw DE,AX
ram:011a42 89 mov A,[DE]
ram:011a43 9f60e6 mov !0xfe660,A
ram:011a46 ac0a movw AX,[HL + 0xa]
ram:011a48 04e802 addw AX,0x2e8
ram:011a4b bc04 movw [HL + 0x4],AX
ram:011a4d a1 incw AX
ram:011a4e bc04 movw [HL + 0x4],AX
ram:011a50 b1 decw AX
ram:011a51 14 movw DE,AX
ram:011a52 89 mov A,[DE]
ram:011a53 9f79e6 mov !0xfe679,A
ram:011a56 ac04 movw AX,[HL + 0x4]
ram:011a58 a1 incw AX
ram:011a59 bc04 movw [HL + 0x4],AX
ram:011a5b b1 decw AX
ram:011a5c 14 movw DE,AX
ram:011a5d 89 mov A,[DE]
ram:011a5e 9f7ae6 mov !0xfe67a,A
ram:011a61 ac04 movw AX,[HL + 0x4]
ram:011a63 a1 incw AX
ram:011a64 bc04 movw [HL + 0x4],AX
ram:011a66 b1 decw AX
ram:011a67 14 movw DE,AX
ram:011a68 89 mov A,[DE]
ram:011a69 9f7be6 mov !0xfe67b,A
ram:011a6c ac04 movw AX,[HL + 0x4]
ram:011a6e a1 incw AX
ram:011a6f bc04 movw [HL + 0x4],AX
ram:011a71 b1 decw AX
ram:011a72 14 movw DE,AX
ram:011a73 89 mov A,[DE]
ram:011a74 9f7ce6 mov !0xfe67c,A
ram:011a77 ac04 movw AX,[HL + 0x4]
ram:011a79 a1 incw AX
ram:011a7a bc04 movw [HL + 0x4],AX
ram:011a7c b1 decw AX
ram:011a7d 14 movw DE,AX
ram:011a7e 89 mov A,[DE]
ram:011a7f 9f7de6 mov !0xfe67d,A
ram:011a82 ac04 movw AX,[HL + 0x4]
ram:011a84 a1 incw AX
ram:011a85 bc04 movw [HL + 0x4],AX
ram:011a87 b1 decw AX
ram:011a88 14 movw DE,AX
ram:011a89 89 mov A,[DE]
ram:011a8a 9f7ee6 mov !0xfe67e,A
ram:011a8d ac04 movw AX,[HL + 0x4]
ram:011a8f a1 incw AX
ram:011a90 bc04 movw [HL + 0x4],AX
ram:011a92 b1 decw AX
ram:011a93 14 movw DE,AX
ram:011a94 89 mov A,[DE]
ram:011a95 9f84e6 mov !0xfe684,A
ram:011a98 ac04 movw AX,[HL + 0x4]
ram:011a9a a1 incw AX
ram:011a9b bc04 movw [HL + 0x4],AX
ram:011a9d b1 decw AX
ram:011a9e 14 movw DE,AX
ram:011a9f 89 mov A,[DE]
ram:011aa0 9f85e6 mov !0xfe685,A
ram:011aa3 ac04 movw AX,[HL + 0x4]
ram:011aa5 a1 incw AX
ram:011aa6 bc04 movw [HL + 0x4],AX
ram:011aa8 b1 decw AX
ram:011aa9 14 movw DE,AX
ram:011aaa 89 mov A,[DE]
ram:011aab 9f86e6 mov !0xfe686,A
ram:011aae ac04 movw AX,[HL + 0x4]
ram:011ab0 a1 incw AX
ram:011ab1 bc04 movw [HL + 0x4],AX
ram:011ab3 b1 decw AX
ram:011ab4 14 movw DE,AX
ram:011ab5 89 mov A,[DE]
ram:011ab6 9f87e6 mov !0xfe687,A
ram:011ab9 ac04 movw AX,[HL + 0x4]
ram:011abb a1 incw AX
ram:011abc bc04 movw [HL + 0x4],AX
ram:011abe b1 decw AX
ram:011abf 14 movw DE,AX
ram:011ac0 89 mov A,[DE]
ram:011ac1 9f8de6 mov !0xfe68d,A
ram:011ac4 ac04 movw AX,[HL + 0x4]
ram:011ac6 a1 incw AX
ram:011ac7 bc04 movw [HL + 0x4],AX
ram:011ac9 b1 decw AX
ram:011aca 14 movw DE,AX
ram:011acb 89 mov A,[DE]
ram:011acc 9f8ee6 mov !0xfe68e,A
ram:011acf ac04 movw AX,[HL + 0x4]
ram:011ad1 a1 incw AX
ram:011ad2 bc04 movw [HL + 0x4],AX
ram:011ad4 b1 decw AX
ram:011ad5 14 movw DE,AX
ram:011ad6 89 mov A,[DE]
ram:011ad7 9f8fe6 mov !0xfe68f,A
ram:011ada ac0a movw AX,[HL + 0xa]
ram:011adc 12 movw BC,AX
ram:011add 497602 mov A,!0xf0276[BC]
ram:011ae0 9f98da mov !0xfda98,A
ram:011ae3 497702 mov A,!0xf0277[BC]
ram:011ae6 9f99da mov !0xfda99,A
ram:011ae9 cf9ada06 mov !0xfda9a,0x6
ram:011aed cf9bdab4 mov !0xfda9b,0xb4
ram:011af1 ac0a movw AX,[HL + 0xa]
ram:011af3 040203 addw AX,0x302
ram:011af6 14 movw DE,AX
ram:011af7 89 mov A,[DE]
ram:011af8 81 inc 
ram:011af9 dd04 bz $ 0x11aff
ram:011afb 89 mov A,[DE]
ram:011afc d1 cmp0 A
ram:011afd df2a bnz $ 0x11b29
ram:011aff cfead964 mov !0xfd9ea,0x64
ram:011b03 cfebd964 mov !0xfd9eb,0x64
ram:011b07 cfecd964 mov !0xfd9ec,0x64
ram:011b0b cfedd964 mov !0xfd9ed,0x64
ram:011b0f cfeed92d mov !0xfd9ee,0x2d
ram:011b13 cfefd90a mov !0xfd9ef,0xa
ram:011b17 cff0d950 mov !0xfd9f0,0x50
ram:011b1b cff1d92d mov !0xfd9f1,0x2d
ram:011b1f cff2d908 mov !0xfd9f2,0x8
ram:011b23 cff3d937 mov !0xfd9f3,0x37
ram:011b27 ef3f br $ 0x11b68
ram:011b29 ac0a movw AX,[HL + 0xa]
ram:011b2b 12 movw BC,AX
ram:011b2c 490203 mov A,!0xf0302[BC]
ram:011b2f 9fead9 mov !0xfd9ea,A
ram:011b32 490303 mov A,!0xf0303[BC]
ram:011b35 9febd9 mov !0xfd9eb,A
ram:011b38 490403 mov A,!0xf0304[BC]
ram:011b3b 9fecd9 mov !0xfd9ec,A
ram:011b3e 490503 mov A,!0xf0305[BC]
ram:011b41 9fedd9 mov !0xfd9ed,A
ram:011b44 490603 mov A,!0xf0306[BC]
ram:011b47 9feed9 mov !0xfd9ee,A
ram:011b4a 490703 mov A,!0xf0307[BC]
ram:011b4d 9fefd9 mov !0xfd9ef,A
ram:011b50 490803 mov A,!0xf0308[BC]
ram:011b53 9ff0d9 mov !0xfd9f0,A
ram:011b56 490903 mov A,!0xf0309[BC]
ram:011b59 9ff1d9 mov !0xfd9f1,A
ram:011b5c 490a03 mov A,!0xf030a[BC]
ram:011b5f 9ff2d9 mov !0xfd9f2,A
ram:011b62 490b03 mov A,!0xf030b[BC]
ram:011b65 9ff3d9 mov !0xfd9f3,A
ram:011b68 ac0a movw AX,[HL + 0xa]
ram:011b6a 040c03 addw AX,0x30c
ram:011b6d 14 movw DE,AX
ram:011b6e 89 mov A,[DE]
ram:011b6f 81 inc 
ram:011b70 dd04 bz $ 0x11b76
ram:011b72 89 mov A,[DE]
ram:011b73 d1 cmp0 A
ram:011b74 df08 bnz $ 0x11b7e
ram:011b76 8feed9 mov A,!0xfd9ee
ram:011b79 9ff4d9 mov !0xfd9f4,A
ram:011b7c ef09 br $ 0x11b87
ram:011b7e ac0a movw AX,[HL + 0xa]
ram:011b80 12 movw BC,AX
ram:011b81 490d03 mov A,!0xf030d[BC]
ram:011b84 9ff4d9 mov !0xfd9f4,A
ram:011b87 cff5d964 mov !0xfd9f5,0x64
ram:011b8b 100c addw SP,0xc
ram:011b8d c6 pop HL
ram:011b8e d7 ret
ram:011b9a c7 push HL
ram:011b9b c1 push AX
ram:011b9c 20b0 subw SP,0xb0
ram:011b9e fbf8ff movw HL,!0xffff8
ram:011ba1 af04e4 movw AX,!0xfe404
ram:011ba4 340644 movw DE,0x4406
ram:011ba7 c5 push DE
ram:011ba8 14 movw DE,AX
ram:011ba9 8a0e mov A,[DE + 0xe]
ram:011bab 9efc mov CS,A
ram:011bad aa0c movw AX,[DE + 0xc]
ram:011baf 14 movw DE,AX
ram:011bb0 e6 onew AX
ram:011bb1 a1 incw AX
ram:011bb2 61ea call DE
ram:011bb4 c0 pop AX
ram:011bb5 300004 movw AX,0x400
ram:011bb8 fc82e300 call !!0xe382
ram:011bbc 13 movw AX,BC
ram:011bbd bcae movw [HL + 0xae],AX
ram:011bbf af1ee4 movw AX,!0xfe41e
ram:011bc2 320004 movw BC,0x400
ram:011bc5 c3 push BC
ram:011bc6 12 movw BC,AX
ram:011bc7 acae movw AX,[HL + 0xae]
ram:011bc9 c1 push AX
ram:011bca 491600 mov A,!0xf0016[BC]
ram:011bcd 9dd4 mov 0xffdf4,A
ram:011bcf 791400 movw AX,!0xf0014[BC]
ram:011bd2 c1 push AX
ram:011bd3 8dd4 mov A,0xffdf4
ram:011bd5 9dd6 mov 0xffdf6,A
ram:011bd7 c0 pop AX
ram:011bd8 14 movw DE,AX
ram:011bd9 301000 movw AX,0x10
ram:011bdc f7 clrw BC
ram:011bdd c1 push AX
ram:011bde 8dd6 mov A,0xffdf6
ram:011be0 9efc mov CS,A
ram:011be2 c0 pop AX
ram:011be3 61ea call DE
ram:011be5 1004 addw SP,0x4
ram:011be7 acae movw AX,[HL + 0xae]
ram:011be9 fc431801 call !!0x11843
ram:011bed acae movw AX,[HL + 0xae]
ram:011bef fccae400 call !!0xe4ca
ram:011bf3 ccaf00 mov [HL + 0xaf],0x0
ram:011bf6 af1ae4 movw AX,!0xfe41a
ram:011bf9 e7 onew BC
ram:011bfa c3 push BC
ram:011bfb 12 movw BC,AX
ram:011bfc 17 movw AX,HL
ram:011bfd 04af00 addw AX,0xaf
ram:011c00 c1 push AX
ram:011c01 491600 mov A,!0xf0016[BC]
ram:011c04 9dd4 mov 0xffdf4,A
ram:011c06 791400 movw AX,!0xf0014[BC]
ram:011c09 c1 push AX
ram:011c0a 8dd4 mov A,0xffdf4
ram:011c0c 9dd6 mov 0xffdf6,A
ram:011c0e c0 pop AX
ram:011c0f 14 movw DE,AX
ram:011c10 300600 movw AX,0x6
ram:011c13 f7 clrw BC
ram:011c14 c1 push AX
ram:011c15 8dd6 mov A,0xffdf6
ram:011c17 9efc mov CS,A
ram:011c19 c0 pop AX
ram:011c1a 61ea call DE
ram:011c1c 1004 addw SP,0x4
ram:011c1e e6 onew AX
ram:011c1f 43 cmpw AX,BC
ram:011c20 61e8 skz
ram:011c22 ee4e01 _br $! 0x11d73
ram:011c25 c7 push HL
ram:011c26 17 movw AX,HL
ram:011c27 04a900 addw AX,0xa9
ram:011c2a 16 movw HL,AX
ram:011c2b f7 clrw BC
ram:011c2c 496243 mov A,!0xf4362[BC]
ram:011c2f 9b mov [HL],A
ram:011c30 a3 incw BC
ram:011c31 a7 incw HL
ram:011c32 5106 mov ,0x6
ram:011c34 614a cmp A,
ram:011c36 dff4 bnz $ 0x11c2c
ram:011c38 c6 pop HL
ram:011c39 c7 push HL
ram:011c3a 17 movw AX,HL
ram:011c3b 04a300 addw AX,0xa3
ram:011c3e 16 movw HL,AX
ram:011c3f f7 clrw BC
ram:011c40 496843 mov A,!0xf4368[BC]
ram:011c43 9b mov [HL],A
ram:011c44 a3 incw BC
ram:011c45 a7 incw HL
ram:011c46 5106 mov ,0x6
ram:011c48 614a cmp A,
ram:011c4a dff4 bnz $ 0x11c40
ram:011c4c c6 pop HL
ram:011c4d c7 push HL
ram:011c4e 17 movw AX,HL
ram:011c4f 049d00 addw AX,0x9d
ram:011c52 16 movw HL,AX
ram:011c53 f7 clrw BC
ram:011c54 496e43 mov A,!0xf436e[BC]
ram:011c57 9b mov [HL],A
ram:011c58 a3 incw BC
ram:011c59 a7 incw HL
ram:011c5a 5106 mov ,0x6
ram:011c5c 614a cmp A,
ram:011c5e dff4 bnz $ 0x11c54
ram:011c60 c6 pop HL
ram:011c61 8caf mov A,[HL + 0xaf]
ram:011c63 2c04 sub A,#0x4
ram:011c65 dc07 bc $ 0x11c6e
ram:011c67 d1 cmp0 A
ram:011c68 61f8 sknz
ram:011c6a ee8500 _br $! 0x11cf2
ram:011c6d 91 dec 
ram:011c6e af04e4 movw AX,!0xfe404
ram:011c71 e7 onew BC
ram:011c72 a3 incw BC
ram:011c73 c3 push BC
ram:011c74 12 movw BC,AX
ram:011c75 17 movw AX,HL
ram:011c76 04a900 addw AX,0xa9
ram:011c79 c1 push AX
ram:011c7a 491200 mov A,!0xf0012[BC]
ram:011c7d 9dd4 mov 0xffdf4,A
ram:011c7f 791000 movw AX,!0xf0010[BC]
ram:011c82 c1 push AX
ram:011c83 8dd4 mov A,0xffdf4
ram:011c85 9dd6 mov 0xffdf6,A
ram:011c87 c0 pop AX
ram:011c88 14 movw DE,AX
ram:011c89 308212 movw AX,0x1282
ram:011c8c 320300 movw BC,0x3
ram:011c8f c1 push AX
ram:011c90 8dd6 mov A,0xffdf6
ram:011c92 9efc mov CS,A
ram:011c94 c0 pop AX
ram:011c95 61ea call DE
ram:011c97 1004 addw SP,0x4
ram:011c99 af04e4 movw AX,!0xfe404
ram:011c9c e7 onew BC
ram:011c9d a3 incw BC
ram:011c9e c3 push BC
ram:011c9f 12 movw BC,AX
ram:011ca0 17 movw AX,HL
ram:011ca1 04a300 addw AX,0xa3
ram:011ca4 c1 push AX
ram:011ca5 491200 mov A,!0xf0012[BC]
ram:011ca8 9dd4 mov 0xffdf4,A
ram:011caa 791000 movw AX,!0xf0010[BC]
ram:011cad c1 push AX
ram:011cae 8dd4 mov A,0xffdf4
ram:011cb0 9dd6 mov 0xffdf6,A
ram:011cb2 c0 pop AX
ram:011cb3 14 movw DE,AX
ram:011cb4 308312 movw AX,0x1283
ram:011cb7 320300 movw BC,0x3
ram:011cba c1 push AX
ram:011cbb 8dd6 mov A,0xffdf6
ram:011cbd 9efc mov CS,A
ram:011cbf c0 pop AX
ram:011cc0 61ea call DE
ram:011cc2 1004 addw SP,0x4
ram:011cc4 af04e4 movw AX,!0xfe404
ram:011cc7 e7 onew BC
ram:011cc8 a3 incw BC
ram:011cc9 c3 push BC
ram:011cca 12 movw BC,AX
ram:011ccb 17 movw AX,HL
ram:011ccc 049d00 addw AX,0x9d
ram:011ccf c1 push AX
ram:011cd0 491200 mov A,!0xf0012[BC]
ram:011cd3 9dd4 mov 0xffdf4,A
ram:011cd5 791000 movw AX,!0xf0010[BC]
ram:011cd8 c1 push AX
ram:011cd9 8dd4 mov A,0xffdf4
ram:011cdb 9dd6 mov 0xffdf6,A
ram:011cdd c0 pop AX
ram:011cde 14 movw DE,AX
ram:011cdf 308412 movw AX,0x1284
ram:011ce2 320300 movw BC,0x3
ram:011ce5 c1 push AX
ram:011ce6 8dd6 mov A,0xffdf6
ram:011ce8 9efc mov CS,A
ram:011cea c0 pop AX
ram:011ceb 61ea call DE
ram:011ced 1004 addw SP,0x4
ram:011cef ee8100 br $! 0x11d73
ram:011cf2 af04e4 movw AX,!0xfe404
ram:011cf5 e7 onew BC
ram:011cf6 a3 incw BC
ram:011cf7 c3 push BC
ram:011cf8 12 movw BC,AX
ram:011cf9 17 movw AX,HL
ram:011cfa 04ab00 addw AX,0xab
ram:011cfd c1 push AX
ram:011cfe 491200 mov A,!0xf0012[BC]
ram:011d01 9dd4 mov 0xffdf4,A
ram:011d03 791000 movw AX,!0xf0010[BC]
ram:011d06 c1 push AX
ram:011d07 8dd4 mov A,0xffdf4
ram:011d09 9dd6 mov 0xffdf6,A
ram:011d0b c0 pop AX
ram:011d0c 14 movw DE,AX
ram:011d0d 308212 movw AX,0x1282
ram:011d10 320300 movw BC,0x3
ram:011d13 c1 push AX
ram:011d14 8dd6 mov A,0xffdf6
ram:011d16 9efc mov CS,A
ram:011d18 c0 pop AX
ram:011d19 61ea call DE
ram:011d1b 1004 addw SP,0x4
ram:011d1d af04e4 movw AX,!0xfe404
ram:011d20 e7 onew BC
ram:011d21 a3 incw BC
ram:011d22 c3 push BC
ram:011d23 12 movw BC,AX
ram:011d24 17 movw AX,HL
ram:011d25 04a500 addw AX,0xa5
ram:011d28 c1 push AX
ram:011d29 491200 mov A,!0xf0012[BC]
ram:011d2c 9dd4 mov 0xffdf4,A
ram:011d2e 791000 movw AX,!0xf0010[BC]
ram:011d31 c1 push AX
ram:011d32 8dd4 mov A,0xffdf4
ram:011d34 9dd6 mov 0xffdf6,A
ram:011d36 c0 pop AX
ram:011d37 14 movw DE,AX
ram:011d38 308312 movw AX,0x1283
ram:011d3b 320300 movw BC,0x3
ram:011d3e c1 push AX
ram:011d3f 8dd6 mov A,0xffdf6
ram:011d41 9efc mov CS,A
ram:011d43 c0 pop AX
ram:011d44 61ea call DE
ram:011d46 1004 addw SP,0x4
ram:011d48 af04e4 movw AX,!0xfe404
ram:011d4b e7 onew BC
ram:011d4c a3 incw BC
ram:011d4d c3 push BC
ram:011d4e 12 movw BC,AX
ram:011d4f 17 movw AX,HL
ram:011d50 049f00 addw AX,0x9f
ram:011d53 c1 push AX
ram:011d54 491200 mov A,!0xf0012[BC]
ram:011d57 9dd4 mov 0xffdf4,A
ram:011d59 791000 movw AX,!0xf0010[BC]
ram:011d5c c1 push AX
ram:011d5d 8dd4 mov A,0xffdf4
ram:011d5f 9dd6 mov 0xffdf6,A
ram:011d61 c0 pop AX
ram:011d62 14 movw DE,AX
ram:011d63 308412 movw AX,0x1284
ram:011d66 320300 movw BC,0x3
ram:011d69 c1 push AX
ram:011d6a 8dd6 mov A,0xffdf6
ram:011d6c 9efc mov CS,A
ram:011d6e c0 pop AX
ram:011d6f 61ea call DE
ram:011d71 1004 addw SP,0x4
ram:011d73 8cb0 mov A,[HL + 0xb0]
ram:011d75 91 dec 
ram:011d76 df36 bnz $ 0x11dae
ram:011d78 30b000 movw AX,0xb0
ram:011d7b bb movw [HL],AX
ram:011d7c db1ee4 movw BC,!0xfe41e
ram:011d7f 17 movw AX,HL
ram:011d80 c1 push AX
ram:011d81 490e00 mov A,!0xf000e[BC]
ram:011d84 9efc mov CS,A
ram:011d86 790c00 movw AX,!0xf000c[BC]
ram:011d89 14 movw DE,AX
ram:011d8a e6 onew AX
ram:011d8b 61ea call DE
ram:011d8d c0 pop AX
ram:011d8e 8c02 mov A,[HL + 0x2]
ram:011d90 4c5a cmp A,#0x5a
ram:011d92 dd09 bz $ 0x11d9d
ram:011d94 3042da movw AX,0xda42
ram:011d97 fccc1601 call !!0x116cc
ram:011d9b ef11 br $ 0x11dae
ram:011d9d c7 push HL
ram:011d9e 17 movw AX,HL
ram:011d9f 040400 addw AX,0x4
ram:011da2 16 movw HL,AX
ram:011da3 5256 mov ,0x56
ram:011da5 92 dec 
ram:011da6 61e9 mov A,[HL + C]
ram:011da8 2842da mov !0xfda42[C],A
ram:011dab dff8 bnz $ 0x11da5
ram:011dad c6 pop HL
ram:011dae 10b2 addw SP,0xb2
ram:011db0 c6 pop HL
ram:011db1 d7 ret
ram:011e16 c7 push HL
ram:011e17 c3 push BC
ram:011e18 c1 push AX
ram:011e19 2004 subw SP,0x4
ram:011e1b fbf8ff movw HL,!0xffff8
ram:011e1e ac04 movw AX,[HL + 0x4]
ram:011e20 bdd8 movw 0xffdf8,AX
ram:011e22 ac06 movw AX,[HL + 0x6]
ram:011e24 bdda movw 0xffdfa,AX
ram:011e26 5108 mov ,0x8
ram:011e28 fd8c06 call !0xf068c
ram:011e2b c9dcf000 movw 0xffdfc,0xf0
ram:011e2f f6 clrw AX
ram:011e30 fdb706 call !0xf06b7
ram:011e33 f6 clrw AX
ram:011e34 46da cmpw AX,0xffdfa
ram:011e36 61f8 sknz
ram:011e38 46d8 _cmpw AX,0xffdf8
ram:011e3a dd1a bz $ 0x11e56
ram:011e3c ac0e movw AX,[HL + 0xe]
ram:011e3e bdd8 movw 0xffdf8,AX
ram:011e40 ac10 movw AX,[HL + 0x10]
ram:011e42 bdda movw 0xffdfa,AX
ram:011e44 5108 mov ,0x8
ram:011e46 fd8c06 call !0xf068c
ram:011e49 f8d8 mov C,0xffdf8
ram:011e4b 62 mov A,
ram:011e4c 9b mov [HL],A
ram:011e4d 8c0e mov A,[HL + 0xe]
ram:011e4f 9c01 mov [HL + 0x1],A
ram:011e51 cc0302 mov [HL + 0x3],0x2
ram:011e54 ef2a br $ 0x11e80
ram:011e56 ac0e movw AX,[HL + 0xe]
ram:011e58 bdd8 movw 0xffdf8,AX
ram:011e5a ac10 movw AX,[HL + 0x10]
ram:011e5c bdda movw 0xffdfa,AX
ram:011e5e 5110 mov ,0x10
ram:011e60 fd8c06 call !0xf068c
ram:011e63 f8d8 mov C,0xffdf8
ram:011e65 62 mov A,
ram:011e66 9b mov [HL],A
ram:011e67 ac0e movw AX,[HL + 0xe]
ram:011e69 bdd8 movw 0xffdf8,AX
ram:011e6b ac10 movw AX,[HL + 0x10]
ram:011e6d bdda movw 0xffdfa,AX
ram:011e6f 5108 mov ,0x8
ram:011e71 fd8c06 call !0xf068c
ram:011e74 f8d8 mov C,0xffdf8
ram:011e76 62 mov A,
ram:011e77 9c01 mov [HL + 0x1],A
ram:011e79 8c0e mov A,[HL + 0xe]
ram:011e7b 9c02 mov [HL + 0x2],A
ram:011e7d cc0303 mov [HL + 0x3],0x3
ram:011e80 db04e4 movw BC,!0xfe404
ram:011e83 8c03 mov A,[HL + 0x3]
ram:011e85 318e shrw AX,0x8
ram:011e87 c1 push AX
ram:011e88 17 movw AX,HL
ram:011e89 c1 push AX
ram:011e8a 491200 mov A,!0xf0012[BC]
ram:011e8d 9efc mov CS,A
ram:011e8f 791000 movw AX,!0xf0010[BC]
ram:011e92 14 movw DE,AX
ram:011e93 ac06 movw AX,[HL + 0x6]
ram:011e95 12 movw BC,AX
ram:011e96 ac04 movw AX,[HL + 0x4]
ram:011e98 61ea call DE
ram:011e9a 1004 addw SP,0x4
ram:011e9c 1008 addw SP,0x8
ram:011e9e c6 pop HL
ram:011e9f d7 ret
ram:011f0e c7 push HL
ram:011f0f c1 push AX
ram:011f10 2016 subw SP,0x16
ram:011f12 fbf8ff movw HL,!0xffff8
ram:011f15 ac16 movw AX,[HL + 0x16]
ram:011f17 bc14 movw [HL + 0x14],AX
ram:011f19 c7 push HL
ram:011f1a 17 movw AX,HL
ram:011f1b 041000 addw AX,0x10
ram:011f1e 16 movw HL,AX
ram:011f1f f7 clrw BC
ram:011f20 497a43 mov A,!0xf437a[BC]
ram:011f23 9b mov [HL],A
ram:011f24 a3 incw BC
ram:011f25 a7 incw HL
ram:011f26 5103 mov ,0x3
ram:011f28 614a cmp A,
ram:011f2a dff4 bnz $ 0x11f20
ram:011f2c c6 pop HL
ram:011f2d c7 push HL
ram:011f2e 17 movw AX,HL
ram:011f2f 16 movw HL,AX
ram:011f30 f7 clrw BC
ram:011f31 497e43 mov A,!0xf437e[BC]
ram:011f34 9b mov [HL],A
ram:011f35 a3 incw BC
ram:011f36 a7 incw HL
ram:011f37 5110 mov ,0x10
ram:011f39 614a cmp A,
ram:011f3b dff4 bnz $ 0x11f31
ram:011f3d c6 pop HL
ram:011f3e cc1300 mov [HL + 0x13],0x0
ram:011f41 8c13 mov A,[HL + 0x13]
ram:011f43 4c04 cmp A,#0x4
ram:011f45 de55 bnc $ 0x11f9c
ram:011f47 af04e4 movw AX,!0xfe404
ram:011f4a e7 onew BC
ram:011f4b a3 incw BC
ram:011f4c c3 push BC
ram:011f4d 12 movw BC,AX
ram:011f4e 17 movw AX,HL
ram:011f4f 041000 addw AX,0x10
ram:011f52 c1 push AX
ram:011f53 8c13 mov A,[HL + 0x13]
ram:011f55 f0 clrb X
ram:011f56 316e shrw AX,0x6
ram:011f58 07 addw AX,HL
ram:011f59 14 movw DE,AX
ram:011f5a a9 movw AX,[DE]
ram:011f5b bdd8 movw 0xffdf8,AX
ram:011f5d aa02 movw AX,[DE + 0x2]
ram:011f5f bdda movw 0xffdfa,AX
ram:011f61 491600 mov A,!0xf0016[BC]
ram:011f64 9efc mov CS,A
ram:011f66 791400 movw AX,!0xf0014[BC]
ram:011f69 14 movw DE,AX
ram:011f6a dada movw BC,0xffdfa
ram:011f6c add8 movw AX,0xffdf8
ram:011f6e 61ea call DE
ram:011f70 1004 addw SP,0x4
ram:011f72 e6 onew AX
ram:011f73 a1 incw AX
ram:011f74 43 cmpw AX,BC
ram:011f75 dd03 bz $ 0x11f7a
ram:011f77 f7 clrw BC
ram:011f78 ef23 br $ 0x11f9d
ram:011f7a 8c10 mov A,[HL + 0x10]
ram:011f7c 318e shrw AX,0x8
ram:011f7e 318d shlw AX,0x8
ram:011f80 12 movw BC,AX
ram:011f81 8c11 mov A,[HL + 0x11]
ram:011f83 318e shrw AX,0x8
ram:011f85 616b or A,
ram:011f87 08 xch A,X
ram:011f88 616a or A,
ram:011f8a 08 xch A,X
ram:011f8b 12 movw BC,AX
ram:011f8c 8c13 mov A,[HL + 0x13]
ram:011f8e f0 clrb X
ram:011f8f 317e shrw AX,0x7
ram:011f91 610914 addw AX,[HL + 0x14]
ram:011f94 14 movw DE,AX
ram:011f95 13 movw AX,BC
ram:011f96 b9 movw [DE],AX
ram:011f97 615913 inc [HL + 0x13]
ram:011f9a efa5 br $ 0x11f41
ram:011f9c e7 onew BC
ram:011f9d 1018 addw SP,0x18
ram:011f9f c6 pop HL
ram:011fa0 d7 ret
ram:0120fa c7 push HL
ram:0120fb c1 push AX
ram:0120fc 2014 subw SP,0x14
ram:0120fe fbf8ff movw HL,!0xffff8
ram:012101 ac14 movw AX,[HL + 0x14]
ram:012103 bc12 movw [HL + 0x12],AX
ram:012105 c7 push HL
ram:012106 17 movw AX,HL
ram:012107 040e00 addw AX,0xe
ram:01210a 16 movw HL,AX
ram:01210b f7 clrw BC
ram:01210c 49ae43 mov A,!0xf43ae[BC]
ram:01210f 9b mov [HL],A
ram:012110 a3 incw BC
ram:012111 a7 incw HL
ram:012112 5103 mov ,0x3
ram:012114 614a cmp A,
ram:012116 dff4 bnz $ 0x1210c
ram:012118 c6 pop HL
ram:012119 c7 push HL
ram:01211a 17 movw AX,HL
ram:01211b 040200 addw AX,0x2
ram:01211e 16 movw HL,AX
ram:01211f f7 clrw BC
ram:012120 49b243 mov A,!0xf43b2[BC]
ram:012123 9b mov [HL],A
ram:012124 a3 incw BC
ram:012125 a7 incw HL
ram:012126 510c mov ,0xc
ram:012128 614a cmp A,
ram:01212a dff4 bnz $ 0x12120
ram:01212c c6 pop HL
ram:01212d cc1100 mov [HL + 0x11],0x0
ram:012130 8c11 mov A,[HL + 0x11]
ram:012132 4c03 cmp A,#0x3
ram:012134 de5a bnc $ 0x12190
ram:012136 af04e4 movw AX,!0xfe404
ram:012139 320300 movw BC,0x3
ram:01213c c3 push BC
ram:01213d 12 movw BC,AX
ram:01213e 17 movw AX,HL
ram:01213f 040e00 addw AX,0xe
ram:012142 c1 push AX
ram:012143 8c11 mov A,[HL + 0x11]
ram:012145 f0 clrb X
ram:012146 316e shrw AX,0x6
ram:012148 07 addw AX,HL
ram:012149 040200 addw AX,0x2
ram:01214c 14 movw DE,AX
ram:01214d a9 movw AX,[DE]
ram:01214e bdd8 movw 0xffdf8,AX
ram:012150 aa02 movw AX,[DE + 0x2]
ram:012152 bdda movw 0xffdfa,AX
ram:012154 491600 mov A,!0xf0016[BC]
ram:012157 9efc mov CS,A
ram:012159 791400 movw AX,!0xf0014[BC]
ram:01215c 14 movw DE,AX
ram:01215d dada movw BC,0xffdfa
ram:01215f add8 movw AX,0xffdf8
ram:012161 61ea call DE
ram:012163 1004 addw SP,0x4
ram:012165 300300 movw AX,0x3
ram:012168 43 cmpw AX,BC
ram:012169 dd03 bz $ 0x1216e
ram:01216b f7 clrw BC
ram:01216c ef5e br $ 0x121cc
ram:01216e 8c0e mov A,[HL + 0xe]
ram:012170 318e shrw AX,0x8
ram:012172 318d shlw AX,0x8
ram:012174 12 movw BC,AX
ram:012175 8c0f mov A,[HL + 0xf]
ram:012177 318e shrw AX,0x8
ram:012179 616b or A,
ram:01217b 08 xch A,X
ram:01217c 616a or A,
ram:01217e 08 xch A,X
ram:01217f 12 movw BC,AX
ram:012180 8c11 mov A,[HL + 0x11]
ram:012182 f0 clrb X
ram:012183 317e shrw AX,0x7
ram:012185 610912 addw AX,[HL + 0x12]
ram:012188 14 movw DE,AX
ram:012189 13 movw AX,BC
ram:01218a b9 movw [DE],AX
ram:01218b 615911 inc [HL + 0x11]
ram:01218e efa0 br $ 0x12130
ram:012190 ac14 movw AX,[HL + 0x14]
ram:012192 14 movw DE,AX
ram:012193 a9 movw AX,[DE]
ram:012194 bdd8 movw 0xffdf8,AX
ram:012196 306400 movw AX,0x64
ram:012199 fd1905 call !0xf0519
ram:01219c bb movw [HL],AX
ram:01219d f6 clrw AX
ram:01219e 614900 cmpw AX,[HL + 0x0]
ram:0121a1 df08 bnz $ 0x121ab
ram:0121a3 ac14 movw AX,[HL + 0x14]
ram:0121a5 14 movw DE,AX
ram:0121a6 f6 clrw AX
ram:0121a7 ba04 movw [DE + 0x4],AX
ram:0121a9 ef20 br $ 0x121cb
ram:0121ab ac14 movw AX,[HL + 0x14]
ram:0121ad 040400 addw AX,0x4
ram:0121b0 14 movw DE,AX
ram:0121b1 a9 movw AX,[DE]
ram:0121b2 bdd8 movw 0xffdf8,AX
ram:0121b4 ab movw AX,[HL]
ram:0121b5 fd1905 call !0xf0519
ram:0121b8 b9 movw [DE],AX
ram:0121b9 ac14 movw AX,[HL + 0x14]
ram:0121bb 040400 addw AX,0x4
ram:0121be 14 movw DE,AX
ram:0121bf a9 movw AX,[DE]
ram:0121c0 f7 clrw BC
ram:0121c1 43 cmpw AX,BC
ram:0121c2 71fe or1 CY,A.0x7
ram:0121c4 de05 bnc $ 0x121cb
ram:0121c6 a9 movw AX,[DE]
ram:0121c7 12 movw BC,AX
ram:0121c8 f6 clrw AX
ram:0121c9 23 subw AX,BC
ram:0121ca b9 movw [DE],AX
ram:0121cb e7 onew BC
ram:0121cc 1016 addw SP,0x16
ram:0121ce c6 pop HL
ram:0121cf d7 ret
ram:01223e c7 push HL
ram:01223f c1 push AX
ram:012240 2022 subw SP,0x22
ram:012242 fbf8ff movw HL,!0xffff8
ram:012245 8c22 mov A,[HL + 0x22]
ram:012247 2c02 sub A,#0x2
ram:012249 dc69 bc $ 0x122b4
ram:01224b 2c02 sub A,#0x2
ram:01224d 61e8 skz
ram:01224f eedd00 _br $! 0x1232f
ram:012252 c7 push HL
ram:012253 17 movw AX,HL
ram:012254 a1 incw AX
ram:012255 16 movw HL,AX
ram:012256 f7 clrw BC
ram:012257 49c243 mov A,!0xf43c2[BC]
ram:01225a 9b mov [HL],A
ram:01225b a3 incw BC
ram:01225c a7 incw HL
ram:01225d 5121 mov ,0x21
ram:01225f 614a cmp A,
ram:012261 dff4 bnz $ 0x12257
ram:012263 c6 pop HL
ram:012264 db04e4 movw BC,!0xfe404
ram:012267 17 movw AX,HL
ram:012268 a1 incw AX
ram:012269 c1 push AX
ram:01226a 490e00 mov A,!0xf000e[BC]
ram:01226d 9efc mov CS,A
ram:01226f 790c00 movw AX,!0xf000c[BC]
ram:012272 14 movw DE,AX
ram:012273 e6 onew AX
ram:012274 a1 incw AX
ram:012275 61ea call DE
ram:012277 c0 pop AX
ram:012278 af04e4 movw AX,!0xfe404
ram:01227b 3420e6 movw DE,0xe620
ram:01227e c5 push DE
ram:01227f 14 movw DE,AX
ram:012280 8a0e mov A,[DE + 0xe]
ram:012282 9efc mov CS,A
ram:012284 aa0c movw AX,[DE + 0xc]
ram:012286 14 movw DE,AX
ram:012287 e6 onew AX
ram:012288 a1 incw AX
ram:012289 61ea call DE
ram:01228b c0 pop AX
ram:01228c af04e4 movw AX,!0xfe404
ram:01228f e7 onew BC
ram:012290 a3 incw BC
ram:012291 c3 push BC
ram:012292 3498da movw DE,0xda98
ram:012295 c5 push DE
ram:012296 14 movw DE,AX
ram:012297 8a12 mov A,[DE + 0x12]
ram:012299 9dd4 mov 0xffdf4,A
ram:01229b aa10 movw AX,[DE + 0x10]
ram:01229d c1 push AX
ram:01229e 8dd4 mov A,0xffdf4
ram:0122a0 9dd6 mov 0xffdf6,A
ram:0122a2 c0 pop AX
ram:0122a3 14 movw DE,AX
ram:0122a4 301710 movw AX,0x1017
ram:0122a7 a3 incw BC
ram:0122a8 c1 push AX
ram:0122a9 8dd6 mov A,0xffdf6
ram:0122ab 9efc mov CS,A
ram:0122ad c0 pop AX
ram:0122ae 61ea call DE
ram:0122b0 1004 addw SP,0x4
ram:0122b2 ef7b br $ 0x1232f
ram:0122b4 c7 push HL
ram:0122b5 17 movw AX,HL
ram:0122b6 a1 incw AX
ram:0122b7 16 movw HL,AX
ram:0122b8 f7 clrw BC
ram:0122b9 49e443 mov A,!0xf43e4[BC]
ram:0122bc 9b mov [HL],A
ram:0122bd a3 incw BC
ram:0122be a7 incw HL
ram:0122bf 5121 mov ,0x21
ram:0122c1 614a cmp A,
ram:0122c3 dff4 bnz $ 0x122b9
ram:0122c5 c6 pop HL
ram:0122c6 db04e4 movw BC,!0xfe404
ram:0122c9 17 movw AX,HL
ram:0122ca a1 incw AX
ram:0122cb c1 push AX
ram:0122cc 490e00 mov A,!0xf000e[BC]
ram:0122cf 9efc mov CS,A
ram:0122d1 790c00 movw AX,!0xf000c[BC]
ram:0122d4 14 movw DE,AX
ram:0122d5 e6 onew AX
ram:0122d6 a1 incw AX
ram:0122d7 61ea call DE
ram:0122d9 c0 pop AX
ram:0122da 8c22 mov A,[HL + 0x22]
ram:0122dc d1 cmp0 A
ram:0122dd df16 bnz $ 0x122f5
ram:0122df af04e4 movw AX,!0xfe404
ram:0122e2 3462e6 movw DE,0xe662
ram:0122e5 c5 push DE
ram:0122e6 14 movw DE,AX
ram:0122e7 8a0e mov A,[DE + 0xe]
ram:0122e9 9efc mov CS,A
ram:0122eb aa0c movw AX,[DE + 0xc]
ram:0122ed 14 movw DE,AX
ram:0122ee e6 onew AX
ram:0122ef a1 incw AX
ram:0122f0 61ea call DE
ram:0122f2 c0 pop AX
ram:0122f3 ef14 br $ 0x12309
ram:0122f5 af04e4 movw AX,!0xfe404
ram:0122f8 3433e6 movw DE,0xe633
ram:0122fb c5 push DE
ram:0122fc 14 movw DE,AX
ram:0122fd 8a0e mov A,[DE + 0xe]
ram:0122ff 9efc mov CS,A
ram:012301 aa0c movw AX,[DE + 0xc]
ram:012303 14 movw DE,AX
ram:012304 e6 onew AX
ram:012305 a1 incw AX
ram:012306 61ea call DE
ram:012308 c0 pop AX
ram:012309 af04e4 movw AX,!0xfe404
ram:01230c e7 onew BC
ram:01230d a3 incw BC
ram:01230e c3 push BC
ram:01230f 349ada movw DE,0xda9a
ram:012312 c5 push DE
ram:012313 14 movw DE,AX
ram:012314 8a12 mov A,[DE + 0x12]
ram:012316 9dd4 mov 0xffdf4,A
ram:012318 aa10 movw AX,[DE + 0x10]
ram:01231a c1 push AX
ram:01231b 8dd4 mov A,0xffdf4
ram:01231d 9dd6 mov 0xffdf6,A
ram:01231f c0 pop AX
ram:012320 14 movw DE,AX
ram:012321 301710 movw AX,0x1017
ram:012324 a3 incw BC
ram:012325 c1 push AX
ram:012326 8dd6 mov A,0xffdf6
ram:012328 9efc mov CS,A
ram:01232a c0 pop AX
ram:01232b 61ea call DE
ram:01232d 1004 addw SP,0x4
ram:01232f 8c22 mov A,[HL + 0x22]
ram:012331 318e shrw AX,0x8
ram:012333 c1 push AX
ram:012334 f6 clrw AX
ram:012335 fc571701 call !!0x11757
ram:012339 c0 pop AX
ram:01233a 1024 addw SP,0x24
ram:01233c c6 pop HL
ram:01233d d7 ret
ram:0135f8 30c70f movw AX,0xfc7
ram:0135fb bf24da movw !0xfda24,AX
ram:0135fe 50be mov ,0xbe
ram:013600 bf26da movw !0xfda26,AX
ram:013603 30f1b4 movw AX,0xb4f1
ram:013606 bf28da movw !0xfda28,AX
ram:013609 30e200 movw AX,0xe2
ram:01360c bf2ada movw !0xfda2a,AX
ram:01360f 305e37 movw AX,0x375e
ram:013612 bf2cda movw !0xfda2c,AX
ram:013615 30e200 movw AX,0xe2
ram:013618 bf2eda movw !0xfda2e,AX
ram:01361b 304c05 movw AX,0x54c
ram:01361e bf38da movw !0xfda38,AX
ram:013621 30d20f movw AX,0xfd2
ram:013624 bf3ada movw !0xfda3a,AX
ram:013627 4020da0a cmp !0xfda20,0xa
ram:01362b df1a bnz $ 0x13647
ram:01362d 30c857 movw AX,0x57c8
ram:013630 bf30da movw !0xfda30,AX
ram:013633 30fa00 movw AX,0xfa
ram:013636 bf32da movw !0xfda32,AX
ram:013639 308455 movw AX,0x5584
ram:01363c bf34da movw !0xfda34,AX
ram:01363f 30fa00 movw AX,0xfa
ram:013642 bf36da movw !0xfda36,AX
ram:013645 ef18 br $ 0x1365f
ram:013647 308c70 movw AX,0x708c
ram:01364a bf30da movw !0xfda30,AX
ram:01364d 30fa00 movw AX,0xfa
ram:013650 bf32da movw !0xfda32,AX
ram:013653 30296f movw AX,0x6f29
ram:013656 bf34da movw !0xfda34,AX
ram:013659 30fa00 movw AX,0xfa
ram:01365c bf36da movw !0xfda36,AX
ram:01365f cf3eda05 mov !0xfda3e,0x5
ram:013663 cf3cda05 mov !0xfda3c,0x5
ram:013667 cf3dda06 mov !0xfda3d,0x6
ram:01366b d7 ret
ram:01366c c7 push HL
ram:01366d c1 push AX
ram:01366e 200e subw SP,0xe
ram:013670 fbf8ff movw HL,!0xffff8
ram:013673 c7 push HL
ram:013674 17 movw AX,HL
ram:013675 16 movw HL,AX
ram:013676 f7 clrw BC
ram:013677 494e4b mov A,!0xf4b4e[BC]
ram:01367a 9b mov [HL],A
ram:01367b a3 incw BC
ram:01367c a7 incw HL
ram:01367d 510e mov ,0xe
ram:01367f 614a cmp A,
ram:013681 dff4 bnz $ 0x13677
ram:013683 c6 pop HL
ram:013684 8c0e mov A,[HL + 0xe]
ram:013686 318e shrw AX,0x8
ram:013688 07 addw AX,HL
ram:013689 14 movw DE,AX
ram:01368a 89 mov A,[DE]
ram:01368b 81 inc 
ram:01368c df0a bnz $ 0x13698
ram:01368e f59cda clrb !0xfda9c
ram:013691 f59dda clrb !0xfda9d
ram:013694 e7 onew BC
ram:013695 a3 incw BC
ram:013696 ef20 br $ 0x136b8
ram:013698 8c0e mov A,[HL + 0xe]
ram:01369a 318e shrw AX,0x8
ram:01369c 07 addw AX,HL
ram:01369d 14 movw DE,AX
ram:01369e 89 mov A,[DE]
ram:01369f d1 cmp0 A
ram:0136a0 df08 bnz $ 0x136aa
ram:0136a2 f59cda clrb !0xfda9c
ram:0136a5 f59dda clrb !0xfda9d
ram:0136a8 ef0d br $ 0x136b7
ram:0136aa 8c0e mov A,[HL + 0xe]
ram:0136ac 318e shrw AX,0x8
ram:0136ae 07 addw AX,HL
ram:0136af 14 movw DE,AX
ram:0136b0 89 mov A,[DE]
ram:0136b1 9f9cda mov !0xfda9c,A
ram:0136b4 e59dda oneb !0xfda9d
ram:0136b7 f7 clrw BC
ram:0136b8 1010 addw SP,0x10
ram:0136ba c6 pop HL
ram:0136bb d7 ret
ram:0136d5 c7 push HL
ram:0136d6 c1 push AX
ram:0136d7 c1 push AX
ram:0136d8 fbf8ff movw HL,!0xffff8
ram:0136db cc0100 mov [HL + 0x1],0x0
ram:0136de f1 clrb A
ram:0136df 73 mov ,A
ram:0136e0 0994e6 mov A,!0xfe694[B]
ram:0136e3 91 dec 
ram:0136e4 df03 bnz $ 0x136e9
ram:0136e6 e7 onew BC
ram:0136e7 ef22 br $ 0x1370b
ram:0136e9 8c01 mov A,[HL + 0x1]
ram:0136eb 50ba mov ,0xba
ram:0136ed d6 mulu X
ram:0136ee 0422db addw AX,0xdb22
ram:0136f1 14 movw DE,AX
ram:0136f2 a9 movw AX,[DE]
ram:0136f3 12 movw BC,AX
ram:0136f4 aa02 movw AX,[DE + 0x2]
ram:0136f6 43 cmpw AX,BC
ram:0136f7 dd0a bz $ 0x13703
ram:0136f9 e6 onew AX
ram:0136fa c1 push AX
ram:0136fb f6 clrw AX
ram:0136fc fcf54901 call !!0x149f5
ram:013700 c0 pop AX
ram:013701 ef07 br $ 0x1370a
ram:013703 f6 clrw AX
ram:013704 c1 push AX
ram:013705 fcf54901 call !!0x149f5
ram:013709 c0 pop AX
ram:01370a e7 onew BC
ram:01370b 1004 addw SP,0x4
ram:01370d c6 pop HL
ram:01370e d7 ret
ram:01370f c7 push HL
ram:013710 16 movw HL,AX
ram:013711 66 mov A,
ram:013712 91 dec 
ram:013713 df0f bnz $ 0x13724
ram:013715 f594e6 clrb !0xfe694
ram:013718 f595e6 clrb !0xfe695
ram:01371b cf92e603 mov !0xfe692,0x3
ram:01371f f596e6 clrb !0xfe696
ram:013722 ef13 br $ 0x13737
ram:013724 d596e6 cmp0 !0xfe696
ram:013727 dd0b bz $ 0x13734
ram:013729 d996e6 mov X,!0xfe696
ram:01372c f1 clrb A
ram:01372d fc927e00 call !!0x7e92
ram:013731 f596e6 clrb !0xfe696
ram:013734 f592e6 clrb !0xfe692
ram:013737 c6 pop HL
ram:013738 d7 ret
ram:013744 d596e6 cmp0 !0xfe696
ram:013747 dd0b bz $ 0x13754
ram:013749 d996e6 mov X,!0xfe696
ram:01374c f1 clrb A
ram:01374d fc927e00 call !!0x7e92
ram:013751 f596e6 clrb !0xfe696
ram:013754 d7 ret
ram:013755 c7 push HL
ram:013756 c1 push AX
ram:013757 c1 push AX
ram:013758 fbf8ff movw HL,!0xffff8
ram:01375b 8c02 mov A,[HL + 0x2]
ram:01375d 5c80 and A,#0x80
ram:01375f d1 cmp0 A
ram:013760 df05 bnz $ 0x13767
ram:013762 cc0100 mov [HL + 0x1],0x0
ram:013765 ef03 br $ 0x1376a
ram:013767 cc0101 mov [HL + 0x1],0x1
ram:01376a 8c02 mov A,[HL + 0x2]
ram:01376c 5c7f and A,#0x7f
ram:01376e d1 cmp0 A
ram:01376f dd21 bz $ 0x13792
ram:013771 91 dec 
ram:013772 dd2c bz $ 0x137a0
ram:013774 91 dec 
ram:013775 dd37 bz $ 0x137ae
ram:013777 91 dec 
ram:013778 61f8 sknz
ram:01377a eeca00 _br $! 0x13847
ram:01377d 91 dec 
ram:01377e 61f8 sknz
ram:013780 ee0401 _br $! 0x13887
ram:013783 91 dec 
ram:013784 61f8 sknz
ram:013786 ee0401 _br $! 0x1388d
ram:013789 91 dec 
ram:01378a 61f8 sknz
ram:01378c ee0401 _br $! 0x13893
ram:01378f ee2801 br $! 0x138ba
ram:013792 e6 onew AX
ram:013793 c1 push AX
ram:013794 8c01 mov A,[HL + 0x1]
ram:013796 318e shrw AX,0x8
ram:013798 fc572e02 call !!0x22e57
ram:01379c c0 pop AX
ram:01379d ee1a01 br $! 0x138ba
ram:0137a0 f6 clrw AX
ram:0137a1 c1 push AX
ram:0137a2 8c01 mov A,[HL + 0x1]
ram:0137a4 318e shrw AX,0x8
ram:0137a6 fc572e02 call !!0x22e57
ram:0137aa c0 pop AX
ram:0137ab ee0c01 br $! 0x138ba
ram:0137ae fc443701 call !!0x13744
ram:0137b2 30ba00 movw AX,0xba
ram:0137b5 c1 push AX
ram:0137b6 f6 clrw AX
ram:0137b7 c1 push AX
ram:0137b8 8c01 mov A,[HL + 0x1]
ram:0137ba 50ba mov ,0xba
ram:0137bc d6 mulu X
ram:0137bd 0422db addw AX,0xdb22
ram:0137c0 fc40e500 call !!0xe540
ram:0137c4 1004 addw SP,0x4
ram:0137c6 8c01 mov A,[HL + 0x1]
ram:0137c8 50ba mov ,0xba
ram:0137ca d6 mulu X
ram:0137cb 0422db addw AX,0xdb22
ram:0137ce 14 movw DE,AX
ram:0137cf 301027 movw AX,0x2710
ram:0137d2 bab8 movw [DE + 0xb8],AX
ram:0137d4 8c01 mov A,[HL + 0x1]
ram:0137d6 50ba mov ,0xba
ram:0137d8 d6 mulu X
ram:0137d9 0422db addw AX,0xdb22
ram:0137dc 14 movw DE,AX
ram:0137dd 8a25 mov A,[DE + 0x25]
ram:0137df 5cfc and A,#0xfc
ram:0137e1 6c02 or A,#0x2
ram:0137e3 9a25 mov [DE + 0x25],A
ram:0137e5 8c01 mov A,[HL + 0x1]
ram:0137e7 50ba mov ,0xba
ram:0137e9 d6 mulu X
ram:0137ea 0422db addw AX,0xdb22
ram:0137ed 14 movw DE,AX
ram:0137ee 8a25 mov A,[DE + 0x25]
ram:0137f0 5cf3 and A,#0xf3
ram:0137f2 6c08 or A,#0x8
ram:0137f4 9a25 mov [DE + 0x25],A
ram:0137f6 8c01 mov A,[HL + 0x1]
ram:0137f8 50ba mov ,0xba
ram:0137fa d6 mulu X
ram:0137fb 0422db addw AX,0xdb22
ram:0137fe 14 movw DE,AX
ram:0137ff 8a26 mov A,[DE + 0x26]
ram:013801 5cc0 and A,#0xc0
ram:013803 6c20 or A,#0x20
ram:013805 9a26 mov [DE + 0x26],A
ram:013807 af02e4 movw AX,!0xfe402
ram:01380a f7 clrw BC
ram:01380b c3 push BC
ram:01380c 14 movw DE,AX
ram:01380d 8a1a mov A,[DE + 0x1a]
ram:01380f 9efc mov CS,A
ram:013811 aa18 movw AX,[DE + 0x18]
ram:013813 14 movw DE,AX
ram:013814 305200 movw AX,0x52
ram:013817 61ea call DE
ram:013819 c0 pop AX
ram:01381a ac0a movw AX,[HL + 0xa]
ram:01381c 14 movw DE,AX
ram:01381d a9 movw AX,[DE]
ram:01381e 12 movw BC,AX
ram:01381f 8c01 mov A,[HL + 0x1]
ram:013821 50ba mov ,0xba
ram:013823 d6 mulu X
ram:013824 0422db addw AX,0xdb22
ram:013827 14 movw DE,AX
ram:013828 13 movw AX,BC
ram:013829 b9 movw [DE],AX
ram:01382a 8c01 mov A,[HL + 0x1]
ram:01382c 318e shrw AX,0x8
ram:01382e fc204c01 call !!0x14c20
ram:013832 301400 movw AX,0x14
ram:013835 c1 push AX
ram:013836 30d536 movw AX,0x36d5
ram:013839 5201 mov ,0x1
ram:01383b f3 clrb B
ram:01383c fcea7d00 call !!0x7dea
ram:013840 c0 pop AX
ram:013841 62 mov A,
ram:013842 9f96e6 mov !0xfe696,A
ram:013845 ef73 br $ 0x138ba
ram:013847 fc443701 call !!0x13744
ram:01384b 8c01 mov A,[HL + 0x1]
ram:01384d 50ba mov ,0xba
ram:01384f d6 mulu X
ram:013850 0422db addw AX,0xdb22
ram:013853 14 movw DE,AX
ram:013854 f6 clrw AX
ram:013855 ba02 movw [DE + 0x2],AX
ram:013857 c1 push AX
ram:013858 8c01 mov A,[HL + 0x1]
ram:01385a 318e shrw AX,0x8
ram:01385c fc572e02 call !!0x22e57
ram:013860 c0 pop AX
ram:013861 8c01 mov A,[HL + 0x1]
ram:013863 50ba mov ,0xba
ram:013865 d6 mulu X
ram:013866 0422db addw AX,0xdb22
ram:013869 14 movw DE,AX
ram:01386a 8a24 mov A,[DE + 0x24]
ram:01386c 5c01 and A,#0x1
ram:01386e 6cc8 or A,#0xc8
ram:013870 9a24 mov [DE + 0x24],A
ram:013872 301400 movw AX,0x14
ram:013875 c1 push AX
ram:013876 30d536 movw AX,0x36d5
ram:013879 5201 mov ,0x1
ram:01387b f3 clrb B
ram:01387c fcea7d00 call !!0x7dea
ram:013880 c0 pop AX
ram:013881 62 mov A,
ram:013882 9f96e6 mov !0xfe696,A
ram:013885 ef33 br $ 0x138ba
ram:013887 fc443701 call !!0x13744
ram:01388b ef2d br $ 0x138ba
ram:01388d fc443701 call !!0x13744
ram:013891 ef27 br $ 0x138ba
ram:013893 d596e6 cmp0 !0xfe696
ram:013896 df22 bnz $ 0x138ba
ram:013898 fc443701 call !!0x13744
ram:01389c f6 clrw AX
ram:01389d c1 push AX
ram:01389e 8c01 mov A,[HL + 0x1]
ram:0138a0 318e shrw AX,0x8
ram:0138a2 fc572e02 call !!0x22e57
ram:0138a6 c0 pop AX
ram:0138a7 301400 movw AX,0x14
ram:0138aa c1 push AX
ram:0138ab 30d536 movw AX,0x36d5
ram:0138ae 5201 mov ,0x1
ram:0138b0 f3 clrb B
ram:0138b1 fcea7d00 call !!0x7dea
ram:0138b5 c0 pop AX
ram:0138b6 62 mov A,
ram:0138b7 9f96e6 mov !0xfe696,A
ram:0138ba e7 onew BC
ram:0138bb 1004 addw SP,0x4
ram:0138bd c6 pop HL
ram:0138be d7 ret
ram:0149f5 c7 push HL
ram:0149f6 c1 push AX
ram:0149f7 2012 subw SP,0x12
ram:0149f9 fbf8ff movw HL,!0xffff8
ram:0149fc cc1100 mov [HL + 0x11],0x0
ram:0149ff f6 clrw AX
ram:014a00 bc06 movw [HL + 0x6],AX
ram:014a02 8c12 mov A,[HL + 0x12]
ram:014a04 5086 mov ,0x86
ram:014a06 d6 mulu X
ram:014a07 0e12 add A,[HL + 0x12]
ram:014a09 04dcdb addw AX,0xdbdc
ram:014a0c bc04 movw [HL + 0x4],AX
ram:014a0e cc0300 mov [HL + 0x3],0x0
ram:014a11 cc0200 mov [HL + 0x2],0x0
ram:014a14 17 movw AX,HL
ram:014a15 040600 addw AX,0x6
ram:014a18 c1 push AX
ram:014a19 17 movw AX,HL
ram:014a1a 040800 addw AX,0x8
ram:014a1d c1 push AX
ram:014a1e 8c12 mov A,[HL + 0x12]
ram:014a20 318e shrw AX,0x8
ram:014a22 fc452c02 call !!0x22c45
ram:014a26 1004 addw SP,0x4
ram:014a28 62 mov A,
ram:014a29 9c03 mov [HL + 0x3],A
ram:014a2b f6 clrw AX
ram:014a2c 614906 cmpw AX,[HL + 0x6]
ram:014a2f dd75 bz $ 0x14aa6
ram:014a31 ac04 movw AX,[HL + 0x4]
ram:014a33 14 movw DE,AX
ram:014a34 300d02 movw AX,0x20d
ram:014a37 ba42 movw [DE + 0x42],AX
ram:014a39 ac04 movw AX,[HL + 0x4]
ram:014a3b 12 movw BC,AX
ram:014a3c 798401 movw AX,!0xf0184[BC]
ram:014a3f 14 movw DE,AX
ram:014a40 aa02 movw AX,[DE + 0x2]
ram:014a42 614906 cmpw AX,[HL + 0x6]
ram:014a45 df08 bnz $ 0x14a4f
ram:014a47 ac04 movw AX,[HL + 0x4]
ram:014a49 14 movw DE,AX
ram:014a4a ac06 movw AX,[HL + 0x6]
ram:014a4c b9 movw [DE],AX
ram:014a4d ef57 br $ 0x14aa6
ram:014a4f ac04 movw AX,[HL + 0x4]
ram:014a51 12 movw BC,AX
ram:014a52 798401 movw AX,!0xf0184[BC]
ram:014a55 14 movw DE,AX
ram:014a56 aa02 movw AX,[DE + 0x2]
ram:014a58 614906 cmpw AX,[HL + 0x6]
ram:014a5b dd49 bz $ 0x14aa6
ram:014a5d ac04 movw AX,[HL + 0x4]
ram:014a5f 14 movw DE,AX
ram:014a60 a9 movw AX,[DE]
ram:014a61 614906 cmpw AX,[HL + 0x6]
ram:014a64 df3a bnz $ 0x14aa0
ram:014a66 798401 movw AX,!0xf0184[BC]
ram:014a69 14 movw DE,AX
ram:014a6a aa02 movw AX,[DE + 0x2]
ram:014a6c 6168 or A,
ram:014a6e dd0c bz $ 0x14a7c
ram:014a70 ac04 movw AX,[HL + 0x4]
ram:014a72 14 movw DE,AX
ram:014a73 ac06 movw AX,[HL + 0x6]
ram:014a75 ba02 movw [DE + 0x2],AX
ram:014a77 cc0201 mov [HL + 0x2],0x1
ram:014a7a ef0b br $ 0x14a87
ram:014a7c ac04 movw AX,[HL + 0x4]
ram:014a7e 12 movw BC,AX
ram:014a7f 798401 movw AX,!0xf0184[BC]
ram:014a82 14 movw DE,AX
ram:014a83 ac06 movw AX,[HL + 0x6]
ram:014a85 ba02 movw [DE + 0x2],AX
ram:014a87 db06e4 movw BC,!0xfe406
ram:014a8a 17 movw AX,HL
ram:014a8b 040600 addw AX,0x6
ram:014a8e c1 push AX
ram:014a8f 491a00 mov A,!0xf001a[BC]
ram:014a92 9efc mov CS,A
ram:014a94 791800 movw AX,!0xf0018[BC]
ram:014a97 14 movw DE,AX
ram:014a98 302000 movw AX,0x20
ram:014a9b 61ea call DE
ram:014a9d c0 pop AX
ram:014a9e ef06 br $ 0x14aa6
ram:014aa0 ac04 movw AX,[HL + 0x4]
ram:014aa2 14 movw DE,AX
ram:014aa3 ac06 movw AX,[HL + 0x6]
ram:014aa5 b9 movw [DE],AX
ram:014aa6 8c03 mov A,[HL + 0x3]
ram:014aa8 91 dec 
ram:014aa9 dd06 bz $ 0x14ab1
ram:014aab f6 clrw AX
ram:014aac 614906 cmpw AX,[HL + 0x6]
ram:014aaf dd4b bz $ 0x14afc
ram:014ab1 ac04 movw AX,[HL + 0x4]
ram:014ab3 12 movw BC,AX
ram:014ab4 798401 movw AX,!0xf0184[BC]
ram:014ab7 14 movw DE,AX
ram:014ab8 8a27 mov A,[DE + 0x27]
ram:014aba 5c03 and A,#0x3
ram:014abc d1 cmp0 A
ram:014abd dd0c bz $ 0x14acb
ram:014abf 798401 movw AX,!0xf0184[BC]
ram:014ac2 14 movw DE,AX
ram:014ac3 8a27 mov A,[DE + 0x27]
ram:014ac5 5c03 and A,#0x3
ram:014ac7 4c02 cmp A,#0x2
ram:014ac9 df26 bnz $ 0x14af1
ram:014acb ac04 movw AX,[HL + 0x4]
ram:014acd 12 movw BC,AX
ram:014ace 798401 movw AX,!0xf0184[BC]
ram:014ad1 14 movw DE,AX
ram:014ad2 8a27 mov A,[DE + 0x27]
ram:014ad4 5cfc and A,#0xfc
ram:014ad6 81 inc 
ram:014ad7 9a27 mov [DE + 0x27],A
ram:014ad9 cc0101 mov [HL + 0x1],0x1
ram:014adc db02e4 movw BC,!0xfe402
ram:014adf 17 movw AX,HL
ram:014ae0 a1 incw AX
ram:014ae1 c1 push AX
ram:014ae2 491a00 mov A,!0xf001a[BC]
ram:014ae5 9efc mov CS,A
ram:014ae7 791800 movw AX,!0xf0018[BC]
ram:014aea 14 movw DE,AX
ram:014aeb 305800 movw AX,0x58
ram:014aee 61ea call DE
ram:014af0 c0 pop AX
ram:014af1 ac04 movw AX,[HL + 0x4]
ram:014af3 14 movw DE,AX
ram:014af4 300d02 movw AX,0x20d
ram:014af7 ba42 movw [DE + 0x42],AX
ram:014af9 eec700 br $! 0x14bc3
ram:014afc ac04 movw AX,[HL + 0x4]
ram:014afe 14 movw DE,AX
ram:014aff aa42 movw AX,[DE + 0x42]
ram:014b01 e7 onew BC
ram:014b02 240000 subw AX,0x0
ram:014b05 dd0e bz $ 0x14b15
ram:014b07 23 subw AX,BC
ram:014b08 dd0e bz $ 0x14b18
ram:014b0a 24f900 subw AX,0xf9
ram:014b0d 61f8 sknz
ram:014b0f ee9c00 _br $! 0x14bae
ram:014b12 eea600 br $! 0x14bbb
ram:014b15 eeab00 br $! 0x14bc3
ram:014b18 ac04 movw AX,[HL + 0x4]
ram:014b1a 12 movw BC,AX
ram:014b1b 798401 movw AX,!0xf0184[BC]
ram:014b1e 14 movw DE,AX
ram:014b1f 8a25 mov A,[DE + 0x25]
ram:014b21 5cfc and A,#0xfc
ram:014b23 6c02 or A,#0x2
ram:014b25 9a25 mov [DE + 0x25],A
ram:014b27 ac04 movw AX,[HL + 0x4]
ram:014b29 12 movw BC,AX
ram:014b2a 798401 movw AX,!0xf0184[BC]
ram:014b2d 14 movw DE,AX
ram:014b2e 8a25 mov A,[DE + 0x25]
ram:014b30 5cf3 and A,#0xf3
ram:014b32 6c08 or A,#0x8
ram:014b34 9a25 mov [DE + 0x25],A
ram:014b36 ac04 movw AX,[HL + 0x4]
ram:014b38 12 movw BC,AX
ram:014b39 798401 movw AX,!0xf0184[BC]
ram:014b3c 14 movw DE,AX
ram:014b3d 8a26 mov A,[DE + 0x26]
ram:014b3f 5cc0 and A,#0xc0
ram:014b41 6c20 or A,#0x20
ram:014b43 9a26 mov [DE + 0x26],A
ram:014b45 cc0100 mov [HL + 0x1],0x0
ram:014b48 db02e4 movw BC,!0xfe402
ram:014b4b 17 movw AX,HL
ram:014b4c a1 incw AX
ram:014b4d c1 push AX
ram:014b4e 491a00 mov A,!0xf001a[BC]
ram:014b51 9efc mov CS,A
ram:014b53 791800 movw AX,!0xf0018[BC]
ram:014b56 14 movw DE,AX
ram:014b57 305400 movw AX,0x54
ram:014b5a 61ea call DE
ram:014b5c c0 pop AX
ram:014b5d ac04 movw AX,[HL + 0x4]
ram:014b5f 12 movw BC,AX
ram:014b60 798401 movw AX,!0xf0184[BC]
ram:014b63 14 movw DE,AX
ram:014b64 8a27 mov A,[DE + 0x27]
ram:014b66 5c03 and A,#0x3
ram:014b68 91 dec 
ram:014b69 dd0b bz $ 0x14b76
ram:014b6b 798401 movw AX,!0xf0184[BC]
ram:014b6e 14 movw DE,AX
ram:014b6f 8a27 mov A,[DE + 0x27]
ram:014b71 5c03 and A,#0x3
ram:014b73 d1 cmp0 A
ram:014b74 df30 bnz $ 0x14ba6
ram:014b76 ac04 movw AX,[HL + 0x4]
ram:014b78 12 movw BC,AX
ram:014b79 798401 movw AX,!0xf0184[BC]
ram:014b7c 14 movw DE,AX
ram:014b7d 8a27 mov A,[DE + 0x27]
ram:014b7f 5cfc and A,#0xfc
ram:014b81 6c02 or A,#0x2
ram:014b83 9a27 mov [DE + 0x27],A
ram:014b85 ac04 movw AX,[HL + 0x4]
ram:014b87 12 movw BC,AX
ram:014b88 798401 movw AX,!0xf0184[BC]
ram:014b8b 14 movw DE,AX
ram:014b8c f6 clrw AX
ram:014b8d ba02 movw [DE + 0x2],AX
ram:014b8f 9c01 mov [HL + 0x1],A
ram:014b91 db02e4 movw BC,!0xfe402
ram:014b94 17 movw AX,HL
ram:014b95 a1 incw AX
ram:014b96 c1 push AX
ram:014b97 491a00 mov A,!0xf001a[BC]
ram:014b9a 9efc mov CS,A
ram:014b9c 791800 movw AX,!0xf0018[BC]
ram:014b9f 14 movw DE,AX
ram:014ba0 305800 movw AX,0x58
ram:014ba3 61ea call DE
ram:014ba5 c0 pop AX
ram:014ba6 ac04 movw AX,[HL + 0x4]
ram:014ba8 14 movw DE,AX
ram:014ba9 f6 clrw AX
ram:014baa ba42 movw [DE + 0x42],AX
ram:014bac ef15 br $ 0x14bc3
ram:014bae ac04 movw AX,[HL + 0x4]
ram:014bb0 12 movw BC,AX
ram:014bb1 798401 movw AX,!0xf0184[BC]
ram:014bb4 14 movw DE,AX
ram:014bb5 8a25 mov A,[DE + 0x25]
ram:014bb7 5cf3 and A,#0xf3
ram:014bb9 9a25 mov [DE + 0x25],A
ram:014bbb ac04 movw AX,[HL + 0x4]
ram:014bbd 14 movw DE,AX
ram:014bbe aa42 movw AX,[DE + 0x42]
ram:014bc0 b1 decw AX
ram:014bc1 ba42 movw [DE + 0x42],AX
ram:014bc3 8c1a mov A,[HL + 0x1a]
ram:014bc5 91 dec 
ram:014bc6 df03 bnz $ 0x14bcb
ram:014bc8 f7 clrw BC
ram:014bc9 ef51 br $ 0x14c1c
ram:014bcb 8c02 mov A,[HL + 0x2]
ram:014bcd 91 dec 
ram:014bce df03 bnz $ 0x14bd3
ram:014bd0 f7 clrw BC
ram:014bd1 ef49 br $ 0x14c1c
ram:014bd3 8c03 mov A,[HL + 0x3]
ram:014bd5 91 dec 
ram:014bd6 df3f bnz $ 0x14c17
ram:014bd8 ac04 movw AX,[HL + 0x4]
ram:014bda 14 movw DE,AX
ram:014bdb aa2e movw AX,[DE + 0x2e]
ram:014bdd 5c07 and A,#0x7
ram:014bdf 440200 cmpw AX,0x2
ram:014be2 dc12 bc $ 0x14bf6
ram:014be4 aa2e movw AX,[DE + 0x2e]
ram:014be6 5c07 and A,#0x7
ram:014be8 b1 decw AX
ram:014be9 315d shlw AX,0x5
ram:014beb 315e shrw AX,0x5
ram:014bed 12 movw BC,AX
ram:014bee aa2e movw AX,[DE + 0x2e]
ram:014bf0 5cf8 and A,#0xf8
ram:014bf2 f0 clrb X
ram:014bf3 03 addw AX,BC
ram:014bf4 ba2e movw [DE + 0x2e],AX
ram:014bf6 ac0a movw AX,[HL + 0xa]
ram:014bf8 31ce shrw AX,0xc
ram:014bfa 08 xch A,X
ram:014bfb 5c0f and A,#0xf
ram:014bfd 08 xch A,X
ram:014bfe 312d shlw AX,0x2
ram:014c00 04b4e6 addw AX,0xe6b4
ram:014c03 12 movw BC,AX
ram:014c04 17 movw AX,HL
ram:014c05 040800 addw AX,0x8
ram:014c08 c1 push AX
ram:014c09 490200 mov A,!0xf0002[BC]
ram:014c0c 9efc mov CS,A
ram:014c0e 790000 movw AX,!0xf0000[BC]
ram:014c11 14 movw DE,AX
ram:014c12 ac04 movw AX,[HL + 0x4]
ram:014c14 61ea call DE
ram:014c16 c0 pop AX
ram:014c17 8c11 mov A,[HL + 0x11]
ram:014c19 318e shrw AX,0x8
ram:014c1b 12 movw BC,AX
ram:014c1c 1014 addw SP,0x14
ram:014c1e c6 pop HL
ram:014c1f d7 ret
ram:014c20 c7 push HL
ram:014c21 c1 push AX
ram:014c22 c1 push AX
ram:014c23 fbf8ff movw HL,!0xffff8
ram:014c26 8c02 mov A,[HL + 0x2]
ram:014c28 5086 mov ,0x86
ram:014c2a d6 mulu X
ram:014c2b 0e02 add A,[HL + 0x2]
ram:014c2d 04dcdb addw AX,0xdbdc
ram:014c30 bb movw [HL],AX
ram:014c31 308601 movw AX,0x186
ram:014c34 c1 push AX
ram:014c35 f6 clrw AX
ram:014c36 c1 push AX
ram:014c37 ab movw AX,[HL]
ram:014c38 fc40e500 call !!0xe540
ram:014c3c 1004 addw SP,0x4
ram:014c3e 8c02 mov A,[HL + 0x2]
ram:014c40 50ba mov ,0xba
ram:014c42 d6 mulu X
ram:014c43 0422db addw AX,0xdb22
ram:014c46 12 movw BC,AX
ram:014c47 ab movw AX,[HL]
ram:014c48 048401 addw AX,0x184
ram:014c4b 14 movw DE,AX
ram:014c4c 13 movw AX,BC
ram:014c4d b9 movw [DE],AX
ram:014c4e ab movw AX,[HL]
ram:014c4f 12 movw BC,AX
ram:014c50 798401 movw AX,!0xf0184[BC]
ram:014c53 14 movw DE,AX
ram:014c54 a9 movw AX,[DE]
ram:014c55 12 movw BC,AX
ram:014c56 ab movw AX,[HL]
ram:014c57 14 movw DE,AX
ram:014c58 13 movw AX,BC
ram:014c59 b9 movw [DE],AX
ram:014c5a ab movw AX,[HL]
ram:014c5b 14 movw DE,AX
ram:014c5c 302000 movw AX,0x20
ram:014c5f ba32 movw [DE + 0x32],AX
ram:014c61 ab movw AX,[HL]
ram:014c62 043200 addw AX,0x32
ram:014c65 14 movw DE,AX
ram:014c66 a5 incw DE
ram:014c67 a5 incw DE
ram:014c68 302000 movw AX,0x20
ram:014c6b b9 movw [DE],AX
ram:014c6c ab movw AX,[HL]
ram:014c6d 14 movw DE,AX
ram:014c6e 302000 movw AX,0x20
ram:014c71 ba36 movw [DE + 0x36],AX
ram:014c73 ab movw AX,[HL]
ram:014c74 14 movw DE,AX
ram:014c75 302000 movw AX,0x20
ram:014c78 ba38 movw [DE + 0x38],AX
ram:014c7a ab movw AX,[HL]
ram:014c7b 14 movw DE,AX
ram:014c7c aa2e movw AX,[DE + 0x2e]
ram:014c7e 5cf8 and A,#0xf8
ram:014c80 f0 clrb X
ram:014c81 04c800 addw AX,0xc8
ram:014c84 ba2e movw [DE + 0x2e],AX
ram:014c86 ab movw AX,[HL]
ram:014c87 12 movw BC,AX
ram:014c88 798401 movw AX,!0xf0184[BC]
ram:014c8b 14 movw DE,AX
ram:014c8c a9 movw AX,[DE]
ram:014c8d 6168 or A,
ram:014c8f dd07 bz $ 0x14c98
ram:014c91 ab movw AX,[HL]
ram:014c92 14 movw DE,AX
ram:014c93 300d02 movw AX,0x20d
ram:014c96 ba42 movw [DE + 0x42],AX
ram:014c98 308000 movw AX,0x80
ram:014c9b c1 push AX
ram:014c9c f6 clrw AX
ram:014c9d 90 dec 
ram:014c9e c1 push AX
ram:014c9f ab movw AX,[HL]
ram:014ca0 04c400 addw AX,0xc4
ram:014ca3 fc40e500 call !!0xe540
ram:014ca7 1004 addw SP,0x4
ram:014ca9 f6 clrw AX
ram:014caa c1 push AX
ram:014cab 8c02 mov A,[HL + 0x2]
ram:014cad 318e shrw AX,0x8
ram:014caf fc572e02 call !!0x22e57
ram:014cb3 c0 pop AX
ram:014cb4 1004 addw SP,0x4
ram:014cb6 c6 pop HL
ram:014cb7 d7 ret
ram:014ce2 c7 push HL
ram:014ce3 16 movw HL,AX
ram:014ce4 17 movw AX,HL
ram:014ce5 f1 clrb A
ram:014ce6 c9d84402 movw 0xffdf8,0x244
ram:014cea fd7304 call !0xf0473
ram:014ced 0462dd addw AX,0xdd62
ram:014cf0 12 movw BC,AX
ram:014cf1 17 movw AX,HL
ram:014cf2 f1 clrb A
ram:014cf3 c9d84402 movw 0xffdf8,0x244
ram:014cf7 fd7304 call !0xf0473
ram:014cfa 0462dd addw AX,0xdd62
ram:014cfd 14 movw DE,AX
ram:014cfe 13 movw AX,BC
ram:014cff 040800 addw AX,0x8
ram:014d02 ba3a movw [DE + 0x3a],AX
ram:014d04 17 movw AX,HL
ram:014d05 f1 clrb A
ram:014d06 c9d84402 movw 0xffdf8,0x244
ram:014d0a fd7304 call !0xf0473
ram:014d0d 0462dd addw AX,0xdd62
ram:014d10 12 movw BC,AX
ram:014d11 17 movw AX,HL
ram:014d12 f1 clrb A
ram:014d13 c9d84402 movw 0xffdf8,0x244
ram:014d17 fd7304 call !0xf0473
ram:014d1a 0462dd addw AX,0xdd62
ram:014d1d 14 movw DE,AX
ram:014d1e 13 movw AX,BC
ram:014d1f 040800 addw AX,0x8
ram:014d22 ba3c movw [DE + 0x3c],AX
ram:014d24 17 movw AX,HL
ram:014d25 f1 clrb A
ram:014d26 c9d84402 movw 0xffdf8,0x244
ram:014d2a fd7304 call !0xf0473
ram:014d2d 049add addw AX,0xdd9a
ram:014d30 14 movw DE,AX
ram:014d31 17 movw AX,HL
ram:014d32 f1 clrb A
ram:014d33 c9d84402 movw 0xffdf8,0x244
ram:014d37 fd7304 call !0xf0473
ram:014d3a 0462dd addw AX,0xdd62
ram:014d3d 12 movw BC,AX
ram:014d3e 15 movw AX,DE
ram:014d3f c3 push BC
ram:014d40 c4 pop DE
ram:014d41 ba38 movw [DE + 0x38],AX
ram:014d43 17 movw AX,HL
ram:014d44 f1 clrb A
ram:014d45 c9d84402 movw 0xffdf8,0x244
ram:014d49 fd7304 call !0xf0473
ram:014d4c 12 movw BC,AX
ram:014d4d 3962dd00 mov !0xfdd62[BC],0x0
ram:014d51 17 movw AX,HL
ram:014d52 f1 clrb A
ram:014d53 c9d84402 movw 0xffdf8,0x244
ram:014d57 fd7304 call !0xf0473
ram:014d5a 0462dd addw AX,0xdd62
ram:014d5d 12 movw BC,AX
ram:014d5e 17 movw AX,HL
ram:014d5f f1 clrb A
ram:014d60 c9d84402 movw 0xffdf8,0x244
ram:014d64 fd7304 call !0xf0473
ram:014d67 04a2df addw AX,0xdfa2
ram:014d6a 14 movw DE,AX
ram:014d6b 13 movw AX,BC
ram:014d6c 043e00 addw AX,0x3e
ram:014d6f b9 movw [DE],AX
ram:014d70 17 movw AX,HL
ram:014d71 f1 clrb A
ram:014d72 c9d84402 movw 0xffdf8,0x244
ram:014d76 fd7304 call !0xf0473
ram:014d79 0462dd addw AX,0xdd62
ram:014d7c 12 movw BC,AX
ram:014d7d 17 movw AX,HL
ram:014d7e f1 clrb A
ram:014d7f c9d84402 movw 0xffdf8,0x244
ram:014d83 fd7304 call !0xf0473
ram:014d86 04a4df addw AX,0xdfa4
ram:014d89 14 movw DE,AX
ram:014d8a 13 movw AX,BC
ram:014d8b 043e00 addw AX,0x3e
ram:014d8e b9 movw [DE],AX
ram:014d8f 17 movw AX,HL
ram:014d90 f1 clrb A
ram:014d91 c9d84402 movw 0xffdf8,0x244
ram:014d95 fd7304 call !0xf0473
ram:014d98 04a0dd addw AX,0xdda0
ram:014d9b 0c02 add A,#0x2
ram:014d9d 14 movw DE,AX
ram:014d9e 17 movw AX,HL
ram:014d9f f1 clrb A
ram:014da0 c9d84402 movw 0xffdf8,0x244
ram:014da4 fd7304 call !0xf0473
ram:014da7 0462dd addw AX,0xdd62
ram:014daa 12 movw BC,AX
ram:014dab 15 movw AX,DE
ram:014dac c3 push BC
ram:014dad c4 pop DE
ram:014dae 35 xchw AX,DE
ram:014daf 043e02 addw AX,0x23e
ram:014db2 35 xchw AX,DE
ram:014db3 b9 movw [DE],AX
ram:014db4 c6 pop HL
ram:014db5 d7 ret
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
ram:014ef9 0462dd addw AX,0xdd62
ram:014efc 12 movw BC,AX
ram:014efd 793c00 movw AX,!0xf003c[BC]
ram:014f00 14 movw DE,AX
ram:014f01 8c10 mov A,[HL + 0x10]
ram:014f03 9a02 mov [DE + 0x2],A
ram:014f05 8c08 mov A,[HL + 0x8]
ram:014f07 318e shrw AX,0x8
ram:014f09 c9d84402 movw 0xffdf8,0x244
ram:014f0d fd7304 call !0xf0473
ram:014f10 0462dd addw AX,0xdd62
ram:014f13 12 movw BC,AX
ram:014f14 794202 movw AX,!0xf0242[BC]
ram:014f17 12 movw BC,AX
ram:014f18 8c08 mov A,[HL + 0x8]
ram:014f1a 318e shrw AX,0x8
ram:014f1c c9d84402 movw 0xffdf8,0x244
ram:014f20 fd7304 call !0xf0473
ram:014f23 0462dd addw AX,0xdd62
ram:014f26 14 movw DE,AX
ram:014f27 13 movw AX,BC
ram:014f28 ba04 movw [DE + 0x4],AX
ram:014f2a 8c08 mov A,[HL + 0x8]
ram:014f2c 318e shrw AX,0x8
ram:014f2e c9d84402 movw 0xffdf8,0x244
ram:014f32 fd7304 call !0xf0473
ram:014f35 0462dd addw AX,0xdd62
ram:014f38 14 movw DE,AX
ram:014f39 8c10 mov A,[HL + 0x10]
ram:014f3b 9a06 mov [DE + 0x6],A
ram:014f3d 8c10 mov A,[HL + 0x10]
ram:014f3f d1 cmp0 A
ram:014f40 dd12 bz $ 0x14f54
ram:014f42 8c08 mov A,[HL + 0x8]
ram:014f44 318e shrw AX,0x8
ram:014f46 c9d84402 movw 0xffdf8,0x244
ram:014f4a fd7304 call !0xf0473
ram:014f4d 12 movw BC,AX
ram:014f4e 3962dd04 mov !0xfdd62[BC],0x4
ram:014f52 ef10 br $ 0x14f64
ram:014f54 8c08 mov A,[HL + 0x8]
ram:014f56 318e shrw AX,0x8
ram:014f58 c9d84402 movw 0xffdf8,0x244
ram:014f5c fd7304 call !0xf0473
ram:014f5f 12 movw BC,AX
ram:014f60 3962dd05 mov !0xfdd62[BC],0x5
ram:014f64 eefe02 br $! 0x15265
ram:014f67 8c08 mov A,[HL + 0x8]
ram:014f69 318e shrw AX,0x8
ram:014f6b c9d84402 movw 0xffdf8,0x244
ram:014f6f fd7304 call !0xf0473
ram:014f72 0462dd addw AX,0xdd62
ram:014f75 12 movw BC,AX
ram:014f76 790400 movw AX,!0xf0004[BC]
ram:014f79 a1 incw AX
ram:014f7a 780400 movw !0xf0004[BC],AX
ram:014f7d b1 decw AX
ram:014f7e 14 movw DE,AX
ram:014f7f 8c10 mov A,[HL + 0x10]
ram:014f81 99 mov [DE],A
ram:014f82 8c08 mov A,[HL + 0x8]
ram:014f84 318e shrw AX,0x8
ram:014f86 c9d84402 movw 0xffdf8,0x244
ram:014f8a fd7304 call !0xf0473
ram:014f8d 0462dd addw AX,0xdd62
ram:014f90 12 movw BC,AX
ram:014f91 790400 movw AX,!0xf0004[BC]
ram:014f94 12 movw BC,AX
ram:014f95 8c08 mov A,[HL + 0x8]
ram:014f97 318e shrw AX,0x8
ram:014f99 c9d84402 movw 0xffdf8,0x244
ram:014f9d fd7304 call !0xf0473
ram:014fa0 04a0df addw AX,0xdfa0
ram:014fa3 14 movw DE,AX
ram:014fa4 a9 movw AX,[DE]
ram:014fa5 43 cmpw AX,BC
ram:014fa6 df24 bnz $ 0x14fcc
ram:014fa8 8c08 mov A,[HL + 0x8]
ram:014faa 318e shrw AX,0x8
ram:014fac c9d84402 movw 0xffdf8,0x244
ram:014fb0 fd7304 call !0xf0473
ram:014fb3 0462dd addw AX,0xdd62
ram:014fb6 12 movw BC,AX
ram:014fb7 8c08 mov A,[HL + 0x8]
ram:014fb9 318e shrw AX,0x8
ram:014fbb c9d84402 movw 0xffdf8,0x244
ram:014fbf fd7304 call !0xf0473
ram:014fc2 0462dd addw AX,0xdd62
ram:014fc5 14 movw DE,AX
ram:014fc6 13 movw AX,BC
ram:014fc7 043e00 addw AX,0x3e
ram:014fca ba04 movw [DE + 0x4],AX
ram:014fcc 8c08 mov A,[HL + 0x8]
ram:014fce 318e shrw AX,0x8
ram:014fd0 c9d84402 movw 0xffdf8,0x244
ram:014fd4 fd7304 call !0xf0473
ram:014fd7 0462dd addw AX,0xdd62
ram:014fda 12 movw BC,AX
ram:014fdb 790400 movw AX,!0xf0004[BC]
ram:014fde 12 movw BC,AX
ram:014fdf 8c08 mov A,[HL + 0x8]
ram:014fe1 318e shrw AX,0x8
ram:014fe3 c9d84402 movw 0xffdf8,0x244
ram:014fe7 fd7304 call !0xf0473
ram:014fea 04a2df addw AX,0xdfa2
ram:014fed 14 movw DE,AX
ram:014fee a9 movw AX,[DE]
ram:014fef 43 cmpw AX,BC
ram:014ff0 df08 bnz $ 0x14ffa
ram:014ff2 8c08 mov A,[HL + 0x8]
ram:014ff4 318e shrw AX,0x8
ram:014ff6 fce24c01 call !!0x14ce2
ram:014ffa 8c08 mov A,[HL + 0x8]
ram:014ffc 318e shrw AX,0x8
ram:014ffe c9d84402 movw 0xffdf8,0x244
ram:015002 fd7304 call !0xf0473
ram:015005 0462dd addw AX,0xdd62
ram:015008 12 movw BC,AX
ram:015009 490600 mov A,!0xf0006[BC]
ram:01500c 91 dec 
ram:01500d 480600 mov !0xf0006[BC],A
ram:015010 8c08 mov A,[HL + 0x8]
ram:015012 318e shrw AX,0x8
ram:015014 c9d84402 movw 0xffdf8,0x244
ram:015018 fd7304 call !0xf0473
ram:01501b 0462dd addw AX,0xdd62
ram:01501e 12 movw BC,AX
ram:01501f 490600 mov A,!0xf0006[BC]
ram:015022 d1 cmp0 A
ram:015023 df10 bnz $ 0x15035
ram:015025 8c08 mov A,[HL + 0x8]
ram:015027 318e shrw AX,0x8
ram:015029 c9d84402 movw 0xffdf8,0x244
ram:01502d fd7304 call !0xf0473
ram:015030 12 movw BC,AX
ram:015031 3962dd05 mov !0xfdd62[BC],0x5
ram:015035 ee2d02 br $! 0x15265
ram:015038 8c08 mov A,[HL + 0x8]
ram:01503a 318e shrw AX,0x8
ram:01503c c9d84402 movw 0xffdf8,0x244
ram:015040 fd7304 call !0xf0473
ram:015043 0462dd addw AX,0xdd62
ram:015046 12 movw BC,AX
ram:015047 794202 movw AX,!0xf0242[BC]
ram:01504a bc02 movw [HL + 0x2],AX
ram:01504c 8c08 mov A,[HL + 0x8]
ram:01504e 318e shrw AX,0x8
ram:015050 c9d84402 movw 0xffdf8,0x244
ram:015054 fd7304 call !0xf0473
ram:015057 0462dd addw AX,0xdd62
ram:01505a 12 movw BC,AX
ram:01505b 793c00 movw AX,!0xf003c[BC]
ram:01505e 14 movw DE,AX
ram:01505f 89 mov A,[DE]
ram:015060 7caa xor A,#0xaa
ram:015062 72 mov ,A
ram:015063 8c08 mov A,[HL + 0x8]
ram:015065 318e shrw AX,0x8
ram:015067 c9d84402 movw 0xffdf8,0x244
ram:01506b fd7304 call !0xf0473
ram:01506e 0462dd addw AX,0xdd62
ram:015071 14 movw DE,AX
ram:015072 aa3c movw AX,[DE + 0x3c]
ram:015074 14 movw DE,AX
ram:015075 8a01 mov A,[DE + 0x1]
ram:015077 6172 xor ,A
ram:015079 8c08 mov A,[HL + 0x8]
ram:01507b 318e shrw AX,0x8
ram:01507d c9d84402 movw 0xffdf8,0x244
ram:015081 fd7304 call !0xf0473
ram:015084 0462dd addw AX,0xdd62
ram:015087 14 movw DE,AX
ram:015088 aa3c movw AX,[DE + 0x3c]
ram:01508a 14 movw DE,AX
ram:01508b 8a02 mov A,[DE + 0x2]
ram:01508d 6172 xor ,A
ram:01508f 62 mov A,
ram:015090 9c01 mov [HL + 0x1],A
ram:015092 f6 clrw AX
ram:015093 bc04 movw [HL + 0x4],AX
ram:015095 8c08 mov A,[HL + 0x8]
ram:015097 318e shrw AX,0x8
ram:015099 c9d84402 movw 0xffdf8,0x244
ram:01509d fd7304 call !0xf0473
ram:0150a0 0462dd addw AX,0xdd62
ram:0150a3 12 movw BC,AX
ram:0150a4 793c00 movw AX,!0xf003c[BC]
ram:0150a7 14 movw DE,AX
ram:0150a8 8a02 mov A,[DE + 0x2]
ram:0150aa 318e shrw AX,0x8
ram:0150ac 12 movw BC,AX
ram:0150ad ac04 movw AX,[HL + 0x4]
ram:0150af 43 cmpw AX,BC
ram:0150b0 de38 bnc $ 0x150ea
ram:0150b2 ac02 movw AX,[HL + 0x2]
ram:0150b4 a1 incw AX
ram:0150b5 bc02 movw [HL + 0x2],AX
ram:0150b7 b1 decw AX
ram:0150b8 14 movw DE,AX
ram:0150b9 89 mov A,[DE]
ram:0150ba 7e01 xor A,[HL + 0x1]
ram:0150bc 9c01 mov [HL + 0x1],A
ram:0150be 8c08 mov A,[HL + 0x8]
ram:0150c0 318e shrw AX,0x8
ram:0150c2 c9d84402 movw 0xffdf8,0x244
ram:0150c6 fd7304 call !0xf0473
ram:0150c9 0462dd addw AX,0xdd62
ram:0150cc 12 movw BC,AX
ram:0150cd 793e02 movw AX,!0xf023e[BC]
ram:0150d0 614902 cmpw AX,[HL + 0x2]
ram:0150d3 df10 bnz $ 0x150e5
ram:0150d5 8c08 mov A,[HL + 0x8]
ram:0150d7 318e shrw AX,0x8
ram:0150d9 c9d84402 movw 0xffdf8,0x244
ram:0150dd fd7304 call !0xf0473
ram:0150e0 04a0dd addw AX,0xdda0
ram:0150e3 bc02 movw [HL + 0x2],AX
ram:0150e5 617904 incw [HL + 0x4]
ram:0150e8 efab br $ 0x15095
ram:0150ea 8c01 mov A,[HL + 0x1]
ram:0150ec 4e10 cmp A,[HL + 0x10]
ram:0150ee 61e8 skz
ram:0150f0 ee3901 _br $! 0x1522c
ram:0150f3 8c08 mov A,[HL + 0x8]
ram:0150f5 318e shrw AX,0x8
ram:0150f7 c9d84402 movw 0xffdf8,0x244
ram:0150fb fd7304 call !0xf0473
ram:0150fe 0462dd addw AX,0xdd62
ram:015101 12 movw BC,AX
ram:015102 794202 movw AX,!0xf0242[BC]
ram:015105 12 movw BC,AX
ram:015106 8c08 mov A,[HL + 0x8]
ram:015108 318e shrw AX,0x8
ram:01510a c9d84402 movw 0xffdf8,0x244
ram:01510e fd7304 call !0xf0473
ram:015111 0462dd addw AX,0xdd62
ram:015114 14 movw DE,AX
ram:015115 aa3c movw AX,[DE + 0x3c]
ram:015117 14 movw DE,AX
ram:015118 13 movw AX,BC
ram:015119 ba04 movw [DE + 0x4],AX
ram:01511b 8c08 mov A,[HL + 0x8]
ram:01511d 318e shrw AX,0x8
ram:01511f c9d84402 movw 0xffdf8,0x244
ram:015123 fd7304 call !0xf0473
ram:015126 0462dd addw AX,0xdd62
ram:015129 12 movw BC,AX
ram:01512a 790400 movw AX,!0xf0004[BC]
ram:01512d 12 movw BC,AX
ram:01512e 8c08 mov A,[HL + 0x8]
ram:015130 318e shrw AX,0x8
ram:015132 c9d84402 movw 0xffdf8,0x244
ram:015136 fd7304 call !0xf0473
ram:015139 04a4df addw AX,0xdfa4
ram:01513c 14 movw DE,AX
ram:01513d 13 movw AX,BC
ram:01513e b9 movw [DE],AX
ram:01513f 8c08 mov A,[HL + 0x8]
ram:015141 318e shrw AX,0x8
ram:015143 c9d84402 movw 0xffdf8,0x244
ram:015147 fd7304 call !0xf0473
ram:01514a 0462dd addw AX,0xdd62
ram:01514d 12 movw BC,AX
ram:01514e 793c00 movw AX,!0xf003c[BC]
ram:015151 040600 addw AX,0x6
ram:015154 783c00 movw !0xf003c[BC],AX
ram:015157 8c08 mov A,[HL + 0x8]
ram:015159 318e shrw AX,0x8
ram:01515b c9d84402 movw 0xffdf8,0x244
ram:01515f fd7304 call !0xf0473
ram:015162 0462dd addw AX,0xdd62
ram:015165 12 movw BC,AX
ram:015166 793c00 movw AX,!0xf003c[BC]
ram:015169 12 movw BC,AX
ram:01516a 8c08 mov A,[HL + 0x8]
ram:01516c 318e shrw AX,0x8
ram:01516e c9d84402 movw 0xffdf8,0x244
ram:015172 fd7304 call !0xf0473
ram:015175 0462dd addw AX,0xdd62
ram:015178 14 movw DE,AX
ram:015179 aa38 movw AX,[DE + 0x38]
ram:01517b 43 cmpw AX,BC
ram:01517c df24 bnz $ 0x151a2
ram:01517e 8c08 mov A,[HL + 0x8]
ram:015180 318e shrw AX,0x8
ram:015182 c9d84402 movw 0xffdf8,0x244
ram:015186 fd7304 call !0xf0473
ram:015189 0462dd addw AX,0xdd62
ram:01518c 12 movw BC,AX
ram:01518d 8c08 mov A,[HL + 0x8]
ram:01518f 318e shrw AX,0x8
ram:015191 c9d84402 movw 0xffdf8,0x244
ram:015195 fd7304 call !0xf0473
ram:015198 0462dd addw AX,0xdd62
ram:01519b 14 movw DE,AX
ram:01519c 13 movw AX,BC
ram:01519d 040800 addw AX,0x8
ram:0151a0 ba3c movw [DE + 0x3c],AX
ram:0151a2 8c08 mov A,[HL + 0x8]
ram:0151a4 318e shrw AX,0x8
ram:0151a6 c9d84402 movw 0xffdf8,0x244
ram:0151aa fd7304 call !0xf0473
ram:0151ad 0462dd addw AX,0xdd62
ram:0151b0 12 movw BC,AX
ram:0151b1 793c00 movw AX,!0xf003c[BC]
ram:0151b4 12 movw BC,AX
ram:0151b5 8c08 mov A,[HL + 0x8]
ram:0151b7 318e shrw AX,0x8
ram:0151b9 c9d84402 movw 0xffdf8,0x244
ram:0151bd fd7304 call !0xf0473
ram:0151c0 0462dd addw AX,0xdd62
ram:0151c3 14 movw DE,AX
ram:0151c4 aa3a movw AX,[DE + 0x3a]
ram:0151c6 43 cmpw AX,BC
ram:0151c7 df63 bnz $ 0x1522c
ram:0151c9 8c08 mov A,[HL + 0x8]
ram:0151cb 318e shrw AX,0x8
ram:0151cd c9d84402 movw 0xffdf8,0x244
ram:0151d1 fd7304 call !0xf0473
ram:0151d4 0462dd addw AX,0xdd62
ram:0151d7 12 movw BC,AX
ram:0151d8 793a00 movw AX,!0xf003a[BC]
ram:0151db 040600 addw AX,0x6
ram:0151de 783a00 movw !0xf003a[BC],AX
ram:0151e1 8c08 mov A,[HL + 0x8]
ram:0151e3 318e shrw AX,0x8
ram:0151e5 c9d84402 movw 0xffdf8,0x244
ram:0151e9 fd7304 call !0xf0473
ram:0151ec 0462dd addw AX,0xdd62
ram:0151ef 12 movw BC,AX
ram:0151f0 793a00 movw AX,!0xf003a[BC]
ram:0151f3 12 movw BC,AX
ram:0151f4 8c08 mov A,[HL + 0x8]
ram:0151f6 318e shrw AX,0x8
ram:0151f8 c9d84402 movw 0xffdf8,0x244
ram:0151fc fd7304 call !0xf0473
ram:0151ff 0462dd addw AX,0xdd62
ram:015202 14 movw DE,AX
ram:015203 aa38 movw AX,[DE + 0x38]
ram:015205 43 cmpw AX,BC
ram:015206 df24 bnz $ 0x1522c
ram:015208 8c08 mov A,[HL + 0x8]
ram:01520a 318e shrw AX,0x8
ram:01520c c9d84402 movw 0xffdf8,0x244
ram:015210 fd7304 call !0xf0473
ram:015213 0462dd addw AX,0xdd62
ram:015216 12 movw BC,AX
ram:015217 8c08 mov A,[HL + 0x8]
ram:015219 318e shrw AX,0x8
ram:01521b c9d84402 movw 0xffdf8,0x244
ram:01521f fd7304 call !0xf0473
ram:015222 0462dd addw AX,0xdd62
ram:015225 14 movw DE,AX
ram:015226 13 movw AX,BC
ram:015227 040800 addw AX,0x8
ram:01522a ba3a movw [DE + 0x3a],AX
ram:01522c 8c08 mov A,[HL + 0x8]
ram:01522e d1 cmp0 A
ram:01522f df12 bnz $ 0x15243
ram:015231 8c08 mov A,[HL + 0x8]
ram:015233 318e shrw AX,0x8
ram:015235 c9d84402 movw 0xffdf8,0x244
ram:015239 fd7304 call !0xf0473
ram:01523c 12 movw BC,AX
ram:01523d 3962dd00 mov !0xfdd62[BC],0x0
ram:015241 ef22 br $ 0x15265
ram:015243 8c08 mov A,[HL + 0x8]
ram:015245 318e shrw AX,0x8
ram:015247 c9d84402 movw 0xffdf8,0x244
ram:01524b fd7304 call !0xf0473
ram:01524e 12 movw BC,AX
ram:01524f 3962dd06 mov !0xfdd62[BC],0x6
ram:015253 ef10 br $ 0x15265
ram:015255 8c08 mov A,[HL + 0x8]
ram:015257 318e shrw AX,0x8
ram:015259 c9d84402 movw 0xffdf8,0x244
ram:01525d fd7304 call !0xf0473
ram:015260 12 movw BC,AX
ram:015261 3962dd00 mov !0xfdd62[BC],0x0
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
ram:01527c c7 push HL
ram:01527d c1 push AX
ram:01527e c1 push AX
ram:01527f fbf8ff movw HL,!0xffff8
ram:015282 8c02 mov A,[HL + 0x2]
ram:015284 318e shrw AX,0x8
ram:015286 c9d84402 movw 0xffdf8,0x244
ram:01528a fd7304 call !0xf0473
ram:01528d 0462dd addw AX,0xdd62
ram:015290 12 movw BC,AX
ram:015291 793c00 movw AX,!0xf003c[BC]
ram:015294 12 movw BC,AX
ram:015295 8c02 mov A,[HL + 0x2]
ram:015297 318e shrw AX,0x8
ram:015299 c9d84402 movw 0xffdf8,0x244
ram:01529d fd7304 call !0xf0473
ram:0152a0 0462dd addw AX,0xdd62
ram:0152a3 14 movw DE,AX
ram:0152a4 aa3a movw AX,[DE + 0x3a]
ram:0152a6 43 cmpw AX,BC
ram:0152a7 df04 bnz $ 0x152ad
ram:0152a9 f7 clrw BC
ram:0152aa ee5f01 br $! 0x1540c
ram:0152ad 8c02 mov A,[HL + 0x2]
ram:0152af 318e shrw AX,0x8
ram:0152b1 c9d84402 movw 0xffdf8,0x244
ram:0152b5 fd7304 call !0xf0473
ram:0152b8 0462dd addw AX,0xdd62
ram:0152bb 12 movw BC,AX
ram:0152bc 793a00 movw AX,!0xf003a[BC]
ram:0152bf 14 movw DE,AX
ram:0152c0 89 mov A,[DE]
ram:0152c1 72 mov ,A
ram:0152c2 ac0a movw AX,[HL + 0xa]
ram:0152c4 14 movw DE,AX
ram:0152c5 62 mov A,
ram:0152c6 99 mov [DE],A
ram:0152c7 8c02 mov A,[HL + 0x2]
ram:0152c9 318e shrw AX,0x8
ram:0152cb c9d84402 movw 0xffdf8,0x244
ram:0152cf fd7304 call !0xf0473
ram:0152d2 0462dd addw AX,0xdd62
ram:0152d5 12 movw BC,AX
ram:0152d6 793a00 movw AX,!0xf003a[BC]
ram:0152d9 14 movw DE,AX
ram:0152da 8a01 mov A,[DE + 0x1]
ram:0152dc 72 mov ,A
ram:0152dd ac0a movw AX,[HL + 0xa]
ram:0152df 14 movw DE,AX
ram:0152e0 62 mov A,
ram:0152e1 9a01 mov [DE + 0x1],A
ram:0152e3 8c02 mov A,[HL + 0x2]
ram:0152e5 318e shrw AX,0x8
ram:0152e7 c9d84402 movw 0xffdf8,0x244
ram:0152eb fd7304 call !0xf0473
ram:0152ee 0462dd addw AX,0xdd62
ram:0152f1 12 movw BC,AX
ram:0152f2 793a00 movw AX,!0xf003a[BC]
ram:0152f5 14 movw DE,AX
ram:0152f6 8a02 mov A,[DE + 0x2]
ram:0152f8 72 mov ,A
ram:0152f9 ac0a movw AX,[HL + 0xa]
ram:0152fb 14 movw DE,AX
ram:0152fc 62 mov A,
ram:0152fd 9a02 mov [DE + 0x2],A
ram:0152ff cc0100 mov [HL + 0x1],0x0
ram:015302 8c02 mov A,[HL + 0x2]
ram:015304 318e shrw AX,0x8
ram:015306 c9d84402 movw 0xffdf8,0x244
ram:01530a fd7304 call !0xf0473
ram:01530d 0462dd addw AX,0xdd62
ram:015310 12 movw BC,AX
ram:015311 793a00 movw AX,!0xf003a[BC]
ram:015314 14 movw DE,AX
ram:015315 8a02 mov A,[DE + 0x2]
ram:015317 4e01 cmp A,[HL + 0x1]
ram:015319 61e3 skh
ram:01531b ee8a00 _br $! 0x153a8
ram:01531e 8c02 mov A,[HL + 0x2]
ram:015320 318e shrw AX,0x8
ram:015322 c9d84402 movw 0xffdf8,0x244
ram:015326 fd7304 call !0xf0473
ram:015329 0462dd addw AX,0xdd62
ram:01532c 12 movw BC,AX
ram:01532d 794002 movw AX,!0xf0240[BC]
ram:015330 14 movw DE,AX
ram:015331 89 mov A,[DE]
ram:015332 72 mov ,A
ram:015333 ac0a movw AX,[HL + 0xa]
ram:015335 14 movw DE,AX
ram:015336 8c01 mov A,[HL + 0x1]
ram:015338 318e shrw AX,0x8
ram:01533a c3 push BC
ram:01533b 12 movw BC,AX
ram:01533c aa04 movw AX,[DE + 0x4]
ram:01533e 03 addw AX,BC
ram:01533f c2 pop BC
ram:015340 14 movw DE,AX
ram:015341 62 mov A,
ram:015342 99 mov [DE],A
ram:015343 8c02 mov A,[HL + 0x2]
ram:015345 318e shrw AX,0x8
ram:015347 c9d84402 movw 0xffdf8,0x244
ram:01534b fd7304 call !0xf0473
ram:01534e 0462dd addw AX,0xdd62
ram:015351 12 movw BC,AX
ram:015352 794002 movw AX,!0xf0240[BC]
ram:015355 a1 incw AX
ram:015356 784002 movw !0xf0240[BC],AX
ram:015359 8c02 mov A,[HL + 0x2]
ram:01535b 318e shrw AX,0x8
ram:01535d c9d84402 movw 0xffdf8,0x244
ram:015361 fd7304 call !0xf0473
ram:015364 0462dd addw AX,0xdd62
ram:015367 12 movw BC,AX
ram:015368 794002 movw AX,!0xf0240[BC]
ram:01536b 12 movw BC,AX
ram:01536c 8c02 mov A,[HL + 0x2]
ram:01536e 318e shrw AX,0x8
ram:015370 c9d84402 movw 0xffdf8,0x244
ram:015374 fd7304 call !0xf0473
ram:015377 04a0df addw AX,0xdfa0
ram:01537a 14 movw DE,AX
ram:01537b a9 movw AX,[DE]
ram:01537c 43 cmpw AX,BC
ram:01537d df23 bnz $ 0x153a2
ram:01537f 8c02 mov A,[HL + 0x2]
ram:015381 318e shrw AX,0x8
ram:015383 c9d84402 movw 0xffdf8,0x244
ram:015387 fd7304 call !0xf0473
ram:01538a 0462dd addw AX,0xdd62
ram:01538d 12 movw BC,AX
ram:01538e 8c02 mov A,[HL + 0x2]
ram:015390 318e shrw AX,0x8
ram:015392 c9d84402 movw 0xffdf8,0x244
ram:015396 fd7304 call !0xf0473
ram:015399 04a2df addw AX,0xdfa2
ram:01539c 14 movw DE,AX
ram:01539d 13 movw AX,BC
ram:01539e 043e00 addw AX,0x3e
ram:0153a1 b9 movw [DE],AX
ram:0153a2 615901 inc [HL + 0x1]
ram:0153a5 ee5aff br $! 0x15302
ram:0153a8 8c02 mov A,[HL + 0x2]
ram:0153aa 318e shrw AX,0x8
ram:0153ac c9d84402 movw 0xffdf8,0x244
ram:0153b0 fd7304 call !0xf0473
ram:0153b3 0462dd addw AX,0xdd62
ram:0153b6 12 movw BC,AX
ram:0153b7 793a00 movw AX,!0xf003a[BC]
ram:0153ba 040600 addw AX,0x6
ram:0153bd 783a00 movw !0xf003a[BC],AX
ram:0153c0 8c02 mov A,[HL + 0x2]
ram:0153c2 318e shrw AX,0x8
ram:0153c4 c9d84402 movw 0xffdf8,0x244
ram:0153c8 fd7304 call !0xf0473
ram:0153cb 0462dd addw AX,0xdd62
ram:0153ce 12 movw BC,AX
ram:0153cf 793a00 movw AX,!0xf003a[BC]
ram:0153d2 12 movw BC,AX
ram:0153d3 8c02 mov A,[HL + 0x2]
ram:0153d5 318e shrw AX,0x8
ram:0153d7 c9d84402 movw 0xffdf8,0x244
ram:0153db fd7304 call !0xf0473
ram:0153de 0462dd addw AX,0xdd62
ram:0153e1 14 movw DE,AX
ram:0153e2 aa38 movw AX,[DE + 0x38]
ram:0153e4 43 cmpw AX,BC
ram:0153e5 df24 bnz $ 0x1540b
ram:0153e7 8c02 mov A,[HL + 0x2]
ram:0153e9 318e shrw AX,0x8
ram:0153eb c9d84402 movw 0xffdf8,0x244
ram:0153ef fd7304 call !0xf0473
ram:0153f2 0462dd addw AX,0xdd62
ram:0153f5 12 movw BC,AX
ram:0153f6 8c02 mov A,[HL + 0x2]
ram:0153f8 318e shrw AX,0x8
ram:0153fa c9d84402 movw 0xffdf8,0x244
ram:0153fe fd7304 call !0xf0473
ram:015401 0462dd addw AX,0xdd62
ram:015404 14 movw DE,AX
ram:015405 13 movw AX,BC
ram:015406 040800 addw AX,0x8
ram:015409 ba3a movw [DE + 0x3a],AX
ram:01540b e7 onew BC
ram:01540c 1004 addw SP,0x4
ram:01540e c6 pop HL
ram:01540f d7 ret
ram:0154a0 c7 push HL
ram:0154a1 c1 push AX
ram:0154a2 fbf8ff movw HL,!0xffff8
ram:0154a5 cc01a6 mov [HL + 0x1],0xa6
ram:0154a8 e6 onew AX
ram:0154a9 c1 push AX
ram:0154aa 17 movw AX,HL
ram:0154ab a1 incw AX
ram:0154ac c1 push AX
ram:0154ad f6 clrw AX
ram:0154ae fce0e100 call !!0xe1e0
ram:0154b2 1004 addw SP,0x4
ram:0154b4 c0 pop AX
ram:0154b5 c6 pop HL
ram:0154b6 d7 ret
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
ram:01552d 8c09 mov A,[HL + 0x9]
ram:01552f 318e shrw AX,0x8
ram:015531 07 addw AX,HL
ram:015532 040a00 addw AX,0xa
ram:015535 14 movw DE,AX
ram:015536 8c05 mov A,[HL + 0x5]
ram:015538 99 mov [DE],A
ram:015539 8c58 mov A,[HL + 0x58]
ram:01553b 0c05 add A,#0x5
ram:01553d 318e shrw AX,0x8
ram:01553f c1 push AX
ram:015540 17 movw AX,HL
ram:015541 040600 addw AX,0x6
ram:015544 c1 push AX
ram:015545 f6 clrw AX
ram:015546 fce0e100 call !!0xe1e0
ram:01554a 1004 addw SP,0x4
ram:01554c 104c addw SP,0x4c
ram:01554e c6 pop HL
ram:01554f d7 ret
ram:015550 c7 push HL
ram:015551 c1 push AX
ram:015552 20fe subw SP,0xfe
ram:015554 200c subw SP,0xc
ram:015556 fbf8ff movw HL,!0xffff8
ram:015559 cc05aa mov [HL + 0x5],0xaa
ram:01555c 17 movw AX,HL
ram:01555d 040600 addw AX,0x6
ram:015560 bc02 movw [HL + 0x2],AX
ram:015562 cc06aa mov [HL + 0x6],0xaa
ram:015565 17 movw AX,HL
ram:015566 12 movw BC,AX
ram:015567 490a01 mov A,!0xf010a[BC]
ram:01556a 9c07 mov [HL + 0x7],A
ram:01556c 491401 mov A,!0xf0114[BC]
ram:01556f 9c08 mov [HL + 0x8],A
ram:015571 cc0100 mov [HL + 0x1],0x0
ram:015574 8c01 mov A,[HL + 0x1]
ram:015576 4e08 cmp A,[HL + 0x8]
ram:015578 de1f bnc $ 0x15599
ram:01557a 8c01 mov A,[HL + 0x1]
ram:01557c 318e shrw AX,0x8
ram:01557e 12 movw BC,AX
ram:01557f 17 movw AX,HL
ram:015580 041201 addw AX,0x112
ram:015583 14 movw DE,AX
ram:015584 a9 movw AX,[DE]
ram:015585 03 addw AX,BC
ram:015586 14 movw DE,AX
ram:015587 89 mov A,[DE]
ram:015588 72 mov ,A
ram:015589 8c01 mov A,[HL + 0x1]
ram:01558b 318e shrw AX,0x8
ram:01558d 07 addw AX,HL
ram:01558e 040900 addw AX,0x9
ram:015591 14 movw DE,AX
ram:015592 62 mov A,
ram:015593 99 mov [DE],A
ram:015594 615901 inc [HL + 0x1]
ram:015597 efdb br $ 0x15574
ram:015599 cc0101 mov [HL + 0x1],0x1
ram:01559c 8c08 mov A,[HL + 0x8]
ram:01559e 0c03 add A,#0x3
ram:0155a0 4e01 cmp A,[HL + 0x1]
ram:0155a2 61d312 bnh $ 0x155b6
ram:0155a5 8c01 mov A,[HL + 0x1]
ram:0155a7 318e shrw AX,0x8
ram:0155a9 610902 addw AX,[HL + 0x2]
ram:0155ac 14 movw DE,AX
ram:0155ad 89 mov A,[DE]
ram:0155ae 7e05 xor A,[HL + 0x5]
ram:0155b0 9c05 mov [HL + 0x5],A
ram:0155b2 615901 inc [HL + 0x1]
ram:0155b5 efe5 br $ 0x1559c
ram:0155b7 8c08 mov A,[HL + 0x8]
ram:0155b9 318e shrw AX,0x8
ram:0155bb 07 addw AX,HL
ram:0155bc 040900 addw AX,0x9
ram:0155bf 14 movw DE,AX
ram:0155c0 8c05 mov A,[HL + 0x5]
ram:0155c2 99 mov [DE],A
ram:0155c3 8c08 mov A,[HL + 0x8]
ram:0155c5 81 inc 
ram:0155c6 318e shrw AX,0x8
ram:0155c8 07 addw AX,HL
ram:0155c9 040900 addw AX,0x9
ram:0155cc 14 movw DE,AX
ram:0155cd ca0055 mov [DE + 0x0],0x55
ram:0155d0 17 movw AX,HL
ram:0155d1 12 movw BC,AX
ram:0155d2 491401 mov A,!0xf0114[BC]
ram:0155d5 0c05 add A,#0x5
ram:0155d7 318e shrw AX,0x8
ram:0155d9 c1 push AX
ram:0155da 17 movw AX,HL
ram:0155db 040600 addw AX,0x6
ram:0155de c1 push AX
ram:0155df e6 onew AX
ram:0155e0 fce0e100 call !!0xe1e0
ram:0155e4 1004 addw SP,0x4
ram:0155e6 10fe addw SP,0xfe
ram:0155e8 100e addw SP,0xe
ram:0155ea c6 pop HL
ram:0155eb d7 ret
ram:0155f0 c7 push HL
ram:0155f1 c1 push AX
ram:0155f2 20fe subw SP,0xfe
ram:0155f4 208a subw SP,0x8a
ram:0155f6 fbf8ff movw HL,!0xffff8
ram:0155f9 17 movw AX,HL
ram:0155fa 12 movw BC,AX
ram:0155fb 798801 movw AX,!0xf0188[BC]
ram:0155fe 14 movw DE,AX
ram:0155ff aa04 movw AX,[DE + 0x4]
ram:015601 6168 or A,
ram:015603 df2c bnz $ 0x15631
ram:015605 f6 clrw AX
ram:015606 fce24c01 call !!0x14ce2
ram:01560a e6 onew AX
ram:01560b fce24c01 call !!0x14ce2
ram:01560f f6 clrw AX
ram:015610 fc1ae300 call !!0xe31a
ram:015614 e6 onew AX
ram:015615 fc1ae300 call !!0xe31a
ram:015619 17 movw AX,HL
ram:01561a 12 movw BC,AX
ram:01561b 798801 movw AX,!0xf0188[BC]
ram:01561e 14 movw DE,AX
ram:01561f aa04 movw AX,[DE + 0x4]
ram:015621 a1 incw AX
ram:015622 ba04 movw [DE + 0x4],AX
ram:015624 798801 movw AX,!0xf0188[BC]
ram:015627 14 movw DE,AX
ram:015628 301e00 movw AX,0x1e
ram:01562b ba06 movw [DE + 0x6],AX
ram:01562d e7 onew BC
ram:01562e ee4501 br $! 0x15776
ram:015631 17 movw AX,HL
ram:015632 048800 addw AX,0x88
ram:015635 bc86 movw [HL + 0x86],AX
ram:015637 17 movw AX,HL
ram:015638 12 movw BC,AX
ram:015639 798801 movw AX,!0xf0188[BC]
ram:01563c 14 movw DE,AX
ram:01563d 301e00 movw AX,0x1e
ram:015640 ba06 movw [DE + 0x6],AX
ram:015642 17 movw AX,HL
ram:015643 048200 addw AX,0x82
ram:015646 c1 push AX
ram:015647 f6 clrw AX
ram:015648 fc7c5201 call !!0x1527c
ram:01564c c0 pop AX
ram:01564d 92 dec 
ram:01564e 61e8 skz
ram:015650 eef900 _br $! 0x1574c
ram:015653 8c82 mov A,[HL + 0x82]
ram:015655 314a shr A,0x4
ram:015657 9c81 mov [HL + 0x81],A
ram:015659 8c82 mov A,[HL + 0x82]
ram:01565b 5c08 and A,#0x8
ram:01565d d1 cmp0 A
ram:01565e 61e8 skz
ram:015660 eee000 _br $! 0x15743
ram:015663 8c82 mov A,[HL + 0x82]
ram:015665 5c07 and A,#0x7
ram:015667 91 dec 
ram:015668 dd10 bz $ 0x1567a
ram:01566a 91 dec 
ram:01566b dd37 bz $ 0x156a4
ram:01566d 2c03 sub A,#0x3
ram:01566f dd57 bz $ 0x156c8
ram:015671 91 dec 
ram:015672 61f8 sknz
ram:015674 ee9700 _br $! 0x1570e
ram:015677 eec900 br $! 0x15743
ram:01567a 8c81 mov A,[HL + 0x81]
ram:01567c f0 clrb X
ram:01567d 317e shrw AX,0x7
ram:01567f 0400e4 addw AX,0xe400
ram:015682 14 movw DE,AX
ram:015683 a9 movw AX,[DE]
ram:015684 12 movw BC,AX
ram:015685 ac86 movw AX,[HL + 0x86]
ram:015687 c1 push AX
ram:015688 490e00 mov A,!0xf000e[BC]
ram:01568b 9efc mov CS,A
ram:01568d 790c00 movw AX,!0xf000c[BC]
ram:015690 14 movw DE,AX
ram:015691 8c83 mov A,[HL + 0x83]
ram:015693 318e shrw AX,0x8
ram:015695 61ea call DE
ram:015697 c0 pop AX
ram:015698 62 mov A,
ram:015699 2c02 sub A,#0x2
ram:01569b 61d8 sknc
ram:01569d fca05401 _call !!0x154a0
ram:0156a1 ee9f00 br $! 0x15743
ram:0156a4 8c81 mov A,[HL + 0x81]
ram:0156a6 f0 clrb X
ram:0156a7 317e shrw AX,0x7
ram:0156a9 0400e4 addw AX,0xe400
ram:0156ac 14 movw DE,AX
ram:0156ad a9 movw AX,[DE]
ram:0156ae 12 movw BC,AX
ram:0156af ac86 movw AX,[HL + 0x86]
ram:0156b1 c1 push AX
ram:0156b2 491a00 mov A,!0xf001a[BC]
ram:0156b5 9efc mov CS,A
ram:0156b7 791800 movw AX,!0xf0018[BC]
ram:0156ba 14 movw DE,AX
ram:0156bb 8c83 mov A,[HL + 0x83]
ram:0156bd 318e shrw AX,0x8
ram:0156bf 61ea call DE
ram:0156c1 c0 pop AX
ram:0156c2 fca05401 call !!0x154a0
ram:0156c6 ef7b br $ 0x15743
ram:0156c8 8c81 mov A,[HL + 0x81]
ram:0156ca f0 clrb X
ram:0156cb 317e shrw AX,0x7
ram:0156cd 0400e4 addw AX,0xe400
ram:0156d0 14 movw DE,AX
ram:0156d1 a9 movw AX,[DE]
ram:0156d2 12 movw BC,AX
ram:0156d3 8c83 mov A,[HL + 0x83]
ram:0156d5 318e shrw AX,0x8
ram:0156d7 c1 push AX
ram:0156d8 17 movw AX,HL
ram:0156d9 c1 push AX
ram:0156da ac86 movw AX,[HL + 0x86]
ram:0156dc 14 movw DE,AX
ram:0156dd a9 movw AX,[DE]
ram:0156de bdd8 movw 0xffdf8,AX
ram:0156e0 aa02 movw AX,[DE + 0x2]
ram:0156e2 bdda movw 0xffdfa,AX
ram:0156e4 491600 mov A,!0xf0016[BC]
ram:0156e7 9efc mov CS,A
ram:0156e9 791400 movw AX,!0xf0014[BC]
ram:0156ec 14 movw DE,AX
ram:0156ed dada movw BC,0xffdfa
ram:0156ef add8 movw AX,0xffdf8
ram:0156f1 61ea call DE
ram:0156f3 1004 addw SP,0x4
ram:0156f5 62 mov A,
ram:0156f6 9c80 mov [HL + 0x80],A
ram:0156f8 318e shrw AX,0x8
ram:0156fa c1 push AX
ram:0156fb 17 movw AX,HL
ram:0156fc c1 push AX
ram:0156fd 8c83 mov A,[HL + 0x83]
ram:0156ff 318e shrw AX,0x8
ram:015701 c1 push AX
ram:015702 500d mov ,0xd
ram:015704 c1 push AX
ram:015705 e6 onew AX
ram:015706 fcb75401 call !!0x154b7
ram:01570a 1008 addw SP,0x8
ram:01570c ef35 br $ 0x15743
ram:01570e 8c81 mov A,[HL + 0x81]
ram:015710 f0 clrb X
ram:015711 317e shrw AX,0x7
ram:015713 0400e4 addw AX,0xe400
ram:015716 14 movw DE,AX
ram:015717 a9 movw AX,[DE]
ram:015718 12 movw BC,AX
ram:015719 8c83 mov A,[HL + 0x83]
ram:01571b 318e shrw AX,0x8
ram:01571d c1 push AX
ram:01571e ac86 movw AX,[HL + 0x86]
ram:015720 040400 addw AX,0x4
ram:015723 c1 push AX
ram:015724 ac86 movw AX,[HL + 0x86]
ram:015726 14 movw DE,AX
ram:015727 a9 movw AX,[DE]
ram:015728 bdd8 movw 0xffdf8,AX
ram:01572a aa02 movw AX,[DE + 0x2]
ram:01572c bdda movw 0xffdfa,AX
ram:01572e 491200 mov A,!0xf0012[BC]
ram:015731 9efc mov CS,A
ram:015733 791000 movw AX,!0xf0010[BC]
ram:015736 14 movw DE,AX
ram:015737 dada movw BC,0xffdfa
ram:015739 add8 movw AX,0xffdf8
ram:01573b 61ea call DE
ram:01573d 1004 addw SP,0x4
ram:01573f fca05401 call !!0x154a0
ram:015743 17 movw AX,HL
ram:015744 12 movw BC,AX
ram:015745 798801 movw AX,!0xf0188[BC]
ram:015748 14 movw DE,AX
ram:015749 f6 clrw AX
ram:01574a ba06 movw [DE + 0x6],AX
ram:01574c 17 movw AX,HL
ram:01574d 048200 addw AX,0x82
ram:015750 c1 push AX
ram:015751 e6 onew AX
ram:015752 fc7c5201 call !!0x1527c
ram:015756 c0 pop AX
ram:015757 92 dec 
ram:015758 df1b bnz $ 0x15775
ram:01575a ac86 movw AX,[HL + 0x86]
ram:01575c c1 push AX
ram:01575d 8c84 mov A,[HL + 0x84]
ram:01575f 318e shrw AX,0x8
ram:015761 c1 push AX
ram:015762 8c83 mov A,[HL + 0x83]
ram:015764 318e shrw AX,0x8
ram:015766 fcfd8a01 call !!0x18afd
ram:01576a 1004 addw SP,0x4
ram:01576c 17 movw AX,HL
ram:01576d 12 movw BC,AX
ram:01576e 798801 movw AX,!0xf0188[BC]
ram:015771 14 movw DE,AX
ram:015772 f6 clrw AX
ram:015773 ba06 movw [DE + 0x6],AX
ram:015775 e7 onew BC
ram:015776 10fe addw SP,0xfe
ram:015778 108c addw SP,0x8c
ram:01577a c6 pop HL
ram:01577b d7 ret
ram:01577c f6 clrw AX
ram:01577d fc37e300 call !!0xe337
ram:015781 e6 onew AX
ram:015782 ec37e300 br !!0xe337
ram:0157da c7 push HL
ram:0157db c1 push AX
ram:0157dc 2008 subw SP,0x8
ram:0157de fbf8ff movw HL,!0xffff8
ram:0157e1 ac08 movw AX,[HL + 0x8]
ram:0157e3 bc06 movw [HL + 0x6],AX
ram:0157e5 301c00 movw AX,0x1c
ram:0157e8 bc02 movw [HL + 0x2],AX
ram:0157ea bb movw [HL],AX
ram:0157eb f6 clrw AX
ram:0157ec bc04 movw [HL + 0x4],AX
ram:0157ee ac04 movw AX,[HL + 0x4]
ram:0157f0 614902 cmpw AX,[HL + 0x2]
ram:0157f3 de16 bnc $ 0x1580b
ram:0157f5 ac04 movw AX,[HL + 0x4]
ram:0157f7 610906 addw AX,[HL + 0x6]
ram:0157fa 14 movw DE,AX
ram:0157fb 89 mov A,[DE]
ram:0157fc 72 mov ,A
ram:0157fd 8b mov A,[HL]
ram:0157fe 610a add A,
ram:015800 70 mov ,A
ram:015801 8c01 mov A,[HL + 0x1]
ram:015803 1c00 addc A,#0x0
ram:015805 bb movw [HL],AX
ram:015806 617904 incw [HL + 0x4]
ram:015809 efe3 br $ 0x157ee
ram:01580b ab movw AX,[HL]
ram:01580c 12 movw BC,AX
ram:01580d 100a addw SP,0xa
ram:01580f c6 pop HL
ram:015810 d7 ret
ram:015811 c7 push HL
ram:015812 16 movw HL,AX
ram:015813 17 movw AX,HL
ram:015814 fcda5701 call !!0x157da
ram:015818 ac1c movw AX,[HL + 0x1c]
ram:01581a 43 cmpw AX,BC
ram:01581b df03 bnz $ 0x15820
ram:01581d e7 onew BC
ram:01581e ef01 br $ 0x15821
ram:015820 f7 clrw BC
ram:015821 c6 pop HL
ram:015822 d7 ret
ram:015823 c7 push HL
ram:015824 c1 push AX
ram:015825 c1 push AX
ram:015826 fbf8ff movw HL,!0xffff8
ram:015829 ac02 movw AX,[HL + 0x2]
ram:01582b 14 movw DE,AX
ram:01582c 30aa00 movw AX,0xaa
ram:01582f b9 movw [DE],AX
ram:015830 ac02 movw AX,[HL + 0x2]
ram:015832 14 movw DE,AX
ram:015833 8a02 mov A,[DE + 0x2]
ram:015835 5cfb and A,#0xfb
ram:015837 9a02 mov [DE + 0x2],A
ram:015839 ac02 movw AX,[HL + 0x2]
ram:01583b 14 movw DE,AX
ram:01583c 8a02 mov A,[DE + 0x2]
ram:01583e 5cfe and A,#0xfe
ram:015840 9a02 mov [DE + 0x2],A
ram:015842 ac02 movw AX,[HL + 0x2]
ram:015844 14 movw DE,AX
ram:015845 8a02 mov A,[DE + 0x2]
ram:015847 6c02 or A,#0x2
ram:015849 9a02 mov [DE + 0x2],A
ram:01584b ac02 movw AX,[HL + 0x2]
ram:01584d 14 movw DE,AX
ram:01584e ca0455 mov [DE + 0x4],0x55
ram:015851 ac02 movw AX,[HL + 0x2]
ram:015853 14 movw DE,AX
ram:015854 a5 incw DE
ram:015855 a5 incw DE
ram:015856 a5 incw DE
ram:015857 a5 incw DE
ram:015858 ca014c mov [DE + 0x1],0x4c
ram:01585b ac02 movw AX,[HL + 0x2]
ram:01585d 14 movw DE,AX
ram:01585e a5 incw DE
ram:01585f a5 incw DE
ram:015860 a5 incw DE
ram:015861 a5 incw DE
ram:015862 ca0243 mov [DE + 0x2],0x43
ram:015865 cc0103 mov [HL + 0x1],0x3
ram:015868 8c01 mov A,[HL + 0x1]
ram:01586a 4c0e cmp A,#0xe
ram:01586c de11 bnc $ 0x1587f
ram:01586e ac02 movw AX,[HL + 0x2]
ram:015870 14 movw DE,AX
ram:015871 8c01 mov A,[HL + 0x1]
ram:015873 318e shrw AX,0x8
ram:015875 05 addw AX,DE
ram:015876 14 movw DE,AX
ram:015877 ca0430 mov [DE + 0x4],0x30
ram:01587a 615901 inc [HL + 0x1]
ram:01587d efe9 br $ 0x15868
ram:01587f ac02 movw AX,[HL + 0x2]
ram:015881 14 movw DE,AX
ram:015882 8c01 mov A,[HL + 0x1]
ram:015884 318e shrw AX,0x8
ram:015886 05 addw AX,DE
ram:015887 14 movw DE,AX
ram:015888 ca0431 mov [DE + 0x4],0x31
ram:01588b cc0100 mov [HL + 0x1],0x0
ram:01588e 8c01 mov A,[HL + 0x1]
ram:015890 4c04 cmp A,#0x4
ram:015892 de1d bnc $ 0x158b1
ram:015894 ac02 movw AX,[HL + 0x2]
ram:015896 14 movw DE,AX
ram:015897 8c01 mov A,[HL + 0x1]
ram:015899 318e shrw AX,0x8
ram:01589b 05 addw AX,DE
ram:01589c 14 movw DE,AX
ram:01589d ca1730 mov [DE + 0x17],0x30
ram:0158a0 ac02 movw AX,[HL + 0x2]
ram:0158a2 14 movw DE,AX
ram:0158a3 8c01 mov A,[HL + 0x1]
ram:0158a5 318e shrw AX,0x8
ram:0158a7 05 addw AX,DE
ram:0158a8 14 movw DE,AX
ram:0158a9 ca1331 mov [DE + 0x13],0x31
ram:0158ac 615901 inc [HL + 0x1]
ram:0158af efdd br $ 0x1588e
ram:0158b1 ac02 movw AX,[HL + 0x2]
ram:0158b3 14 movw DE,AX
ram:0158b4 8a02 mov A,[DE + 0x2]
ram:0158b6 5cf7 and A,#0xf7
ram:0158b8 9a02 mov [DE + 0x2],A
ram:0158ba ac02 movw AX,[HL + 0x2]
ram:0158bc 14 movw DE,AX
ram:0158bd 8a02 mov A,[DE + 0x2]
ram:0158bf 5cef and A,#0xef
ram:0158c1 9a02 mov [DE + 0x2],A
ram:0158c3 ac02 movw AX,[HL + 0x2]
ram:0158c5 14 movw DE,AX
ram:0158c6 ca1b00 mov [DE + 0x1b],0x0
ram:0158c9 ac02 movw AX,[HL + 0x2]
ram:0158cb fcda5701 call !!0x157da
ram:0158cf ac02 movw AX,[HL + 0x2]
ram:0158d1 14 movw DE,AX
ram:0158d2 13 movw AX,BC
ram:0158d3 ba1c movw [DE + 0x1c],AX
ram:0158d5 1004 addw SP,0x4
ram:0158d7 c6 pop HL
ram:0158d8 d7 ret
ram:0158d9 c7 push HL
ram:0158da 16 movw HL,AX
ram:0158db 17 movw AX,HL
ram:0158dc 14 movw DE,AX
ram:0158dd 8a02 mov A,[DE + 0x2]
ram:0158df 5cfb and A,#0xfb
ram:0158e1 9a02 mov [DE + 0x2],A
ram:0158e3 5cfd and A,#0xfd
ram:0158e5 9a02 mov [DE + 0x2],A
ram:0158e7 c6 pop HL
ram:0158e8 d7 ret
ram:0158e9 c7 push HL
ram:0158ea 16 movw HL,AX
ram:0158eb 17 movw AX,HL
ram:0158ec 14 movw DE,AX
ram:0158ed 8a02 mov A,[DE + 0x2]
ram:0158ef 5cfe and A,#0xfe
ram:0158f1 9a02 mov [DE + 0x2],A
ram:0158f3 5cfb and A,#0xfb
ram:0158f5 9a02 mov [DE + 0x2],A
ram:0158f7 7128f4e6 clr1 !0xfe6f4.0x2
ram:0158fb c6 pop HL
ram:0158fc d7 ret
ram:015988 c7 push HL
ram:015989 c1 push AX
ram:01598a 200c subw SP,0xc
ram:01598c fbf8ff movw HL,!0xffff8
ram:01598f cc0b01 mov [HL + 0xb],0x1
ram:015992 ac0c movw AX,[HL + 0xc]
ram:015994 14 movw DE,AX
ram:015995 aa04 movw AX,[DE + 0x4]
ram:015997 e7 onew BC
ram:015998 240000 subw AX,0x0
ram:01599b dd1e bz $ 0x159bb
ram:01599d 23 subw AX,BC
ram:01599e dd38 bz $ 0x159d8
ram:0159a0 23 subw AX,BC
ram:0159a1 dd53 bz $ 0x159f6
ram:0159a3 23 subw AX,BC
ram:0159a4 dd6f bz $ 0x15a15
ram:0159a6 23 subw AX,BC
ram:0159a7 61f8 sknz
ram:0159a9 ee9d00 _br $! 0x15a49
ram:0159ac 23 subw AX,BC
ram:0159ad 61f8 sknz
ram:0159af eec000 _br $! 0x15a72
ram:0159b2 23 subw AX,BC
ram:0159b3 61f8 sknz
ram:0159b5 eed100 _br $! 0x15a89
ram:0159b8 eef802 br $! 0x15cb3
ram:0159bb eb0ce4 movw DE,!0xfe40c
ram:0159be 8a02 mov A,[DE + 0x2]
ram:0159c0 9efc mov CS,A
ram:0159c2 a9 movw AX,[DE]
ram:0159c3 14 movw DE,AX
ram:0159c4 e6 onew AX
ram:0159c5 61ea call DE
ram:0159c7 ac0c movw AX,[HL + 0xc]
ram:0159c9 14 movw DE,AX
ram:0159ca e6 onew AX
ram:0159cb ba04 movw [DE + 0x4],AX
ram:0159cd ac0c movw AX,[HL + 0xc]
ram:0159cf 14 movw DE,AX
ram:0159d0 306400 movw AX,0x64
ram:0159d3 ba06 movw [DE + 0x6],AX
ram:0159d5 eedb02 br $! 0x15cb3
ram:0159d8 eb0ce4 movw DE,!0xfe40c
ram:0159db 8a0a mov A,[DE + 0xa]
ram:0159dd 9efc mov CS,A
ram:0159df aa08 movw AX,[DE + 0x8]
ram:0159e1 61ca call AX
ram:0159e3 92 dec 
ram:0159e4 dd0d bz $ 0x159f3
ram:0159e6 ac0c movw AX,[HL + 0xc]
ram:0159e8 14 movw DE,AX
ram:0159e9 e6 onew AX
ram:0159ea a1 incw AX
ram:0159eb ba04 movw [DE + 0x4],AX
ram:0159ed ac0c movw AX,[HL + 0xc]
ram:0159ef 14 movw DE,AX
ram:0159f0 f6 clrw AX
ram:0159f1 ba06 movw [DE + 0x6],AX
ram:0159f3 eebd02 br $! 0x15cb3
ram:0159f6 eb04e4 movw DE,!0xfe404
ram:0159f9 8a02 mov A,[DE + 0x2]
ram:0159fb 9efc mov CS,A
ram:0159fd a9 movw AX,[DE]
ram:0159fe 14 movw DE,AX
ram:0159ff e6 onew AX
ram:015a00 61ea call DE
ram:015a02 ac0c movw AX,[HL + 0xc]
ram:015a04 14 movw DE,AX
ram:015a05 300300 movw AX,0x3
ram:015a08 ba04 movw [DE + 0x4],AX
ram:015a0a ac0c movw AX,[HL + 0xc]
ram:015a0c 14 movw DE,AX
ram:015a0d 306400 movw AX,0x64
ram:015a10 ba06 movw [DE + 0x6],AX
ram:015a12 ee9e02 br $! 0x15cb3
ram:015a15 eb04e4 movw DE,!0xfe404
ram:015a18 8a0a mov A,[DE + 0xa]
ram:015a1a 9efc mov CS,A
ram:015a1c aa08 movw AX,[DE + 0x8]
ram:015a1e 61ca call AX
ram:015a20 62 mov A,
ram:015a21 91 dec 
ram:015a22 dd22 bz $ 0x15a46
ram:015a24 2c04 sub A,#0x4
ram:015a26 df10 bnz $ 0x15a38
ram:015a28 ac0c movw AX,[HL + 0xc]
ram:015a2a 14 movw DE,AX
ram:015a2b 300600 movw AX,0x6
ram:015a2e ba04 movw [DE + 0x4],AX
ram:015a30 ac0c movw AX,[HL + 0xc]
ram:015a32 14 movw DE,AX
ram:015a33 f6 clrw AX
ram:015a34 ba06 movw [DE + 0x6],AX
ram:015a36 ef0e br $ 0x15a46
ram:015a38 ac0c movw AX,[HL + 0xc]
ram:015a3a 14 movw DE,AX
ram:015a3b 300400 movw AX,0x4
ram:015a3e ba04 movw [DE + 0x4],AX
ram:015a40 ac0c movw AX,[HL + 0xc]
ram:015a42 14 movw DE,AX
ram:015a43 f6 clrw AX
ram:015a44 ba06 movw [DE + 0x6],AX
ram:015a46 ee6a02 br $! 0x15cb3
ram:015a49 eb06e4 movw DE,!0xfe406
ram:015a4c 8a02 mov A,[DE + 0x2]
ram:015a4e 9efc mov CS,A
ram:015a50 a9 movw AX,[DE]
ram:015a51 14 movw DE,AX
ram:015a52 e6 onew AX
ram:015a53 61ea call DE
ram:015a55 eb08e4 movw DE,!0xfe408
ram:015a58 8a02 mov A,[DE + 0x2]
ram:015a5a 9efc mov CS,A
ram:015a5c a9 movw AX,[DE]
ram:015a5d 14 movw DE,AX
ram:015a5e e6 onew AX
ram:015a5f 61ea call DE
ram:015a61 ac0c movw AX,[HL + 0xc]
ram:015a63 14 movw DE,AX
ram:015a64 300500 movw AX,0x5
ram:015a67 ba04 movw [DE + 0x4],AX
ram:015a69 ac0c movw AX,[HL + 0xc]
ram:015a6b 14 movw DE,AX
ram:015a6c f6 clrw AX
ram:015a6d ba06 movw [DE + 0x6],AX
ram:015a6f ee4102 br $! 0x15cb3
ram:015a72 eb0ae4 movw DE,!0xfe40a
ram:015a75 8a02 mov A,[DE + 0x2]
ram:015a77 9efc mov CS,A
ram:015a79 a9 movw AX,[DE]
ram:015a7a 14 movw DE,AX
ram:015a7b e6 onew AX
ram:015a7c 61ea call DE
ram:015a7e ac0c movw AX,[HL + 0xc]
ram:015a80 14 movw DE,AX
ram:015a81 aa04 movw AX,[DE + 0x4]
ram:015a83 a1 incw AX
ram:015a84 ba04 movw [DE + 0x4],AX
ram:015a86 ee2a02 br $! 0x15cb3
ram:015a89 eb0ae4 movw DE,!0xfe40a
ram:015a8c 8a0a mov A,[DE + 0xa]
ram:015a8e 9efc mov CS,A
ram:015a90 aa08 movw AX,[DE + 0x8]
ram:015a92 61ca call AX
ram:015a94 92 dec 
ram:015a95 61f8 sknz
ram:015a97 ee1902 _br $! 0x15cb3
ram:015a9a 7138f4e6 clr1 !0xfe6f4.0x3
ram:015a9e c7 push HL
ram:015a9f 17 movw AX,HL
ram:015aa0 040200 addw AX,0x2
ram:015aa3 16 movw HL,AX
ram:015aa4 f7 clrw BC
ram:015aa5 495c4b mov A,!0xf4b5c[BC]
ram:015aa8 9b mov [HL],A
ram:015aa9 a3 incw BC
ram:015aaa a7 incw HL
ram:015aab 5102 mov ,0x2
ram:015aad 614a cmp A,
ram:015aaf dff4 bnz $ 0x15aa5
ram:015ab1 c6 pop HL
ram:015ab2 af1ee4 movw AX,!0xfe41e
ram:015ab5 321e00 movw BC,0x1e
ram:015ab8 c3 push BC
ram:015ab9 34ece1 movw DE,0xe1ec
ram:015abc c5 push DE
ram:015abd 14 movw DE,AX
ram:015abe 8a16 mov A,[DE + 0x16]
ram:015ac0 9dd4 mov 0xffdf4,A
ram:015ac2 aa14 movw AX,[DE + 0x14]
ram:015ac4 c1 push AX
ram:015ac5 8dd4 mov A,0xffdf4
ram:015ac7 9dd6 mov 0xffdf6,A
ram:015ac9 c0 pop AX
ram:015aca 14 movw DE,AX
ram:015acb f6 clrw AX
ram:015acc 12 movw BC,AX
ram:015acd c1 push AX
ram:015ace 8dd6 mov A,0xffdf6
ram:015ad0 9efc mov CS,A
ram:015ad2 c0 pop AX
ram:015ad3 61ea call DE
ram:015ad5 1004 addw SP,0x4
ram:015ad7 13 movw AX,BC
ram:015ad8 bc04 movw [HL + 0x4],AX
ram:015ada 301e00 movw AX,0x1e
ram:015add 614904 cmpw AX,[HL + 0x4]
ram:015ae0 df0f bnz $ 0x15af1
ram:015ae2 30ece1 movw AX,0xe1ec
ram:015ae5 fc115801 call !!0x15811
ram:015ae9 92 dec 
ram:015aea df05 bnz $ 0x15af1
ram:015aec cc0301 mov [HL + 0x3],0x1
ram:015aef ef33 br $ 0x15b24
ram:015af1 30ece1 movw AX,0xe1ec
ram:015af4 fc235801 call !!0x15823
ram:015af8 af1ee4 movw AX,!0xfe41e
ram:015afb 321e00 movw BC,0x1e
ram:015afe c3 push BC
ram:015aff 34ece1 movw DE,0xe1ec
ram:015b02 c5 push DE
ram:015b03 14 movw DE,AX
ram:015b04 8a12 mov A,[DE + 0x12]
ram:015b06 9dd4 mov 0xffdf4,A
ram:015b08 aa10 movw AX,[DE + 0x10]
ram:015b0a c1 push AX
ram:015b0b 8dd4 mov A,0xffdf4
ram:015b0d 9dd6 mov 0xffdf6,A
ram:015b0f c0 pop AX
ram:015b10 14 movw DE,AX
ram:015b11 f6 clrw AX
ram:015b12 12 movw BC,AX
ram:015b13 c1 push AX
ram:015b14 8dd6 mov A,0xffdf6
ram:015b16 9efc mov CS,A
ram:015b18 c0 pop AX
ram:015b19 61ea call DE
ram:015b1b 1004 addw SP,0x4
ram:015b1d d2 cmp0 C
ram:015b1e 61f8 sknz
ram:015b20 7130f4e6 _set1 !0xfe6f4.0x3
ram:015b24 af1ae4 movw AX,!0xfe41a
ram:015b27 e7 onew BC
ram:015b28 a3 incw BC
ram:015b29 c3 push BC
ram:015b2a 12 movw BC,AX
ram:015b2b 17 movw AX,HL
ram:015b2c 040200 addw AX,0x2
ram:015b2f c1 push AX
ram:015b30 491200 mov A,!0xf0012[BC]
ram:015b33 9dd4 mov 0xffdf4,A
ram:015b35 791000 movw AX,!0xf0010[BC]
ram:015b38 c1 push AX
ram:015b39 8dd4 mov A,0xffdf4
ram:015b3b 9dd6 mov 0xffdf6,A
ram:015b3d c0 pop AX
ram:015b3e 14 movw DE,AX
ram:015b3f 302100 movw AX,0x21
ram:015b42 f7 clrw BC
ram:015b43 c1 push AX
ram:015b44 8dd6 mov A,0xffdf6
ram:015b46 9efc mov CS,A
ram:015b48 c0 pop AX
ram:015b49 61ea call DE
ram:015b4b 1004 addw SP,0x4
ram:015b4d c7 push HL
ram:015b4e 36f4e6 movw HL,0xe6f4
ram:015b51 8feee1 mov A,!0xfe1ee
ram:015b54 718c mov1 CY,A.0x0
ram:015b56 7181 mov1 [HL].0x0,CY
ram:015b58 8feee1 mov A,!0xfe1ee
ram:015b5b 719c mov1 CY,A.0x1
ram:015b5d 7191 mov1 [HL].0x1,CY
ram:015b5f c6 pop HL
ram:015b60 8ff4e6 mov A,!0xfe6f4
ram:015b63 3169 shl A,0x6
ram:015b65 317a shr A,0x7
ram:015b67 9c06 mov [HL + 0x6],A
ram:015b69 af1ae4 movw AX,!0xfe41a
ram:015b6c e7 onew BC
ram:015b6d c3 push BC
ram:015b6e 12 movw BC,AX
ram:015b6f 17 movw AX,HL
ram:015b70 040600 addw AX,0x6
ram:015b73 c1 push AX
ram:015b74 491200 mov A,!0xf0012[BC]
ram:015b77 9dd4 mov 0xffdf4,A
ram:015b79 791000 movw AX,!0xf0010[BC]
ram:015b7c c1 push AX
ram:015b7d 8dd4 mov A,0xffdf4
ram:015b7f 9dd6 mov 0xffdf6,A
ram:015b81 c0 pop AX
ram:015b82 14 movw DE,AX
ram:015b83 300300 movw AX,0x3
ram:015b86 f7 clrw BC
ram:015b87 c1 push AX
ram:015b88 8dd6 mov A,0xffdf6
ram:015b8a 9efc mov CS,A
ram:015b8c c0 pop AX
ram:015b8d 61ea call DE
ram:015b8f 1004 addw SP,0x4
ram:015b91 af00e4 movw AX,!0xfe400
ram:015b94 e7 onew BC
ram:015b95 c3 push BC
ram:015b96 12 movw BC,AX
ram:015b97 17 movw AX,HL
ram:015b98 a1 incw AX
ram:015b99 c1 push AX
ram:015b9a 491600 mov A,!0xf0016[BC]
ram:015b9d 9dd4 mov 0xffdf4,A
ram:015b9f 791400 movw AX,!0xf0014[BC]
ram:015ba2 c1 push AX
ram:015ba3 8dd4 mov A,0xffdf4
ram:015ba5 9dd6 mov 0xffdf6,A
ram:015ba7 c0 pop AX
ram:015ba8 14 movw DE,AX
ram:015ba9 304300 movw AX,0x43
ram:015bac f7 clrw BC
ram:015bad c1 push AX
ram:015bae 8dd6 mov A,0xffdf6
ram:015bb0 9efc mov CS,A
ram:015bb2 c0 pop AX
ram:015bb3 61ea call DE
ram:015bb5 1004 addw SP,0x4
ram:015bb7 8c01 mov A,[HL + 0x1]
ram:015bb9 d1 cmp0 A
ram:015bba 61e8 skz
ram:015bbc 7140f4e6 _set1 !0xfe6f4.0x4
ram:015bc0 af06e4 movw AX,!0xfe406
ram:015bc3 f7 clrw BC
ram:015bc4 c3 push BC
ram:015bc5 14 movw DE,AX
ram:015bc6 8a0e mov A,[DE + 0xe]
ram:015bc8 9efc mov CS,A
ram:015bca aa0c movw AX,[DE + 0xc]
ram:015bcc 14 movw DE,AX
ram:015bcd 303600 movw AX,0x36
ram:015bd0 61ea call DE
ram:015bd2 c0 pop AX
ram:015bd3 cc0603 mov [HL + 0x6],0x3
ram:015bd6 cc070f mov [HL + 0x7],0xf
ram:015bd9 db0ae4 movw BC,!0xfe40a
ram:015bdc 17 movw AX,HL
ram:015bdd 040600 addw AX,0x6
ram:015be0 c1 push AX
ram:015be1 490e00 mov A,!0xf000e[BC]
ram:015be4 9efc mov CS,A
ram:015be6 790c00 movw AX,!0xf000c[BC]
ram:015be9 14 movw DE,AX
ram:015bea f6 clrw AX
ram:015beb 61ea call DE
ram:015bed c0 pop AX
ram:015bee cc0600 mov [HL + 0x6],0x0
ram:015bf1 db0ae4 movw BC,!0xfe40a
ram:015bf4 17 movw AX,HL
ram:015bf5 040600 addw AX,0x6
ram:015bf8 c1 push AX
ram:015bf9 490e00 mov A,!0xf000e[BC]
ram:015bfc 9efc mov CS,A
ram:015bfe 790c00 movw AX,!0xf000c[BC]
ram:015c01 14 movw DE,AX
ram:015c02 301400 movw AX,0x14
ram:015c05 61ea call DE
ram:015c07 c0 pop AX
ram:015c08 cc0680 mov [HL + 0x6],0x80
ram:015c0b db0ae4 movw BC,!0xfe40a
ram:015c0e 17 movw AX,HL
ram:015c0f 040600 addw AX,0x6
ram:015c12 c1 push AX
ram:015c13 490e00 mov A,!0xf000e[BC]
ram:015c16 9efc mov CS,A
ram:015c18 790c00 movw AX,!0xf000c[BC]
ram:015c1b 14 movw DE,AX
ram:015c1c 302000 movw AX,0x20
ram:015c1f 61ea call DE
ram:015c21 c0 pop AX
ram:015c22 cc0680 mov [HL + 0x6],0x80
ram:015c25 db0ae4 movw BC,!0xfe40a
ram:015c28 17 movw AX,HL
ram:015c29 040600 addw AX,0x6
ram:015c2c c1 push AX
ram:015c2d 490e00 mov A,!0xf000e[BC]
ram:015c30 9efc mov CS,A
ram:015c32 790c00 movw AX,!0xf000c[BC]
ram:015c35 14 movw DE,AX
ram:015c36 302100 movw AX,0x21
ram:015c39 61ea call DE
ram:015c3b c0 pop AX
ram:015c3c cc0680 mov [HL + 0x6],0x80
ram:015c3f db0ae4 movw BC,!0xfe40a
ram:015c42 17 movw AX,HL
ram:015c43 040600 addw AX,0x6
ram:015c46 c1 push AX
ram:015c47 490e00 mov A,!0xf000e[BC]
ram:015c4a 9efc mov CS,A
ram:015c4c 790c00 movw AX,!0xf000c[BC]
ram:015c4f 14 movw DE,AX
ram:015c50 302200 movw AX,0x22
ram:015c53 61ea call DE
ram:015c55 c0 pop AX
ram:015c56 cc0680 mov [HL + 0x6],0x80
ram:015c59 db0ae4 movw BC,!0xfe40a
ram:015c5c 17 movw AX,HL
ram:015c5d 040600 addw AX,0x6
ram:015c60 c1 push AX
ram:015c61 490e00 mov A,!0xf000e[BC]
ram:015c64 9efc mov CS,A
ram:015c66 790c00 movw AX,!0xf000c[BC]
ram:015c69 14 movw DE,AX
ram:015c6a 302300 movw AX,0x23
ram:015c6d 61ea call DE
ram:015c6f c0 pop AX
ram:015c70 cc0680 mov [HL + 0x6],0x80
ram:015c73 db0ae4 movw BC,!0xfe40a
ram:015c76 17 movw AX,HL
ram:015c77 040600 addw AX,0x6
ram:015c7a c1 push AX
ram:015c7b 490e00 mov A,!0xf000e[BC]
ram:015c7e 9efc mov CS,A
ram:015c80 790c00 movw AX,!0xf000c[BC]
ram:015c83 14 movw DE,AX
ram:015c84 302400 movw AX,0x24
ram:015c87 61ea call DE
ram:015c89 c0 pop AX
ram:015c8a eb10e4 movw DE,!0xfe410
ram:015c8d 8a02 mov A,[DE + 0x2]
ram:015c8f 9efc mov CS,A
ram:015c91 a9 movw AX,[DE]
ram:015c92 14 movw DE,AX
ram:015c93 e6 onew AX
ram:015c94 61ea call DE
ram:015c96 cfeae103 mov !0xfe1ea,0x3
ram:015c9a 30e803 movw AX,0x3e8
ram:015c9d c1 push AX
ram:015c9e 30f055 movw AX,0x55f0
ram:015ca1 5201 mov ,0x1
ram:015ca3 f3 clrb B
ram:015ca4 fcea7d00 call !!0x7dea
ram:015ca8 c0 pop AX
ram:015ca9 62 mov A,
ram:015caa 9f0ae2 mov !0xfe20a,A
ram:015cad f5f8e6 clrb !0xfe6f8
ram:015cb0 cc0b00 mov [HL + 0xb],0x0
ram:015cb3 8c0b mov A,[HL + 0xb]
ram:015cb5 318e shrw AX,0x8
ram:015cb7 12 movw BC,AX
ram:015cb8 100e addw SP,0xe
ram:015cba c6 pop HL
ram:015cbb d7 ret
ram:015cbc c7 push HL
ram:015cbd eb0ce4 movw DE,!0xfe40c
ram:015cc0 8a02 mov A,[DE + 0x2]
ram:015cc2 9efc mov CS,A
ram:015cc4 a9 movw AX,[DE]
ram:015cc5 16 movw HL,AX
ram:015cc6 f6 clrw AX
ram:015cc7 61fa call HL
ram:015cc9 eb10e4 movw DE,!0xfe410
ram:015ccc 8a02 mov A,[DE + 0x2]
ram:015cce 9efc mov CS,A
ram:015cd0 a9 movw AX,[DE]
ram:015cd1 16 movw HL,AX
ram:015cd2 f6 clrw AX
ram:015cd3 61fa call HL
ram:015cd5 eb0ae4 movw DE,!0xfe40a
ram:015cd8 8a02 mov A,[DE + 0x2]
ram:015cda 9efc mov CS,A
ram:015cdc a9 movw AX,[DE]
ram:015cdd 16 movw HL,AX
ram:015cde f6 clrw AX
ram:015cdf 61fa call HL
ram:015ce1 eb08e4 movw DE,!0xfe408
ram:015ce4 8a02 mov A,[DE + 0x2]
ram:015ce6 9efc mov CS,A
ram:015ce8 a9 movw AX,[DE]
ram:015ce9 16 movw HL,AX
ram:015cea f6 clrw AX
ram:015ceb 61fa call HL
ram:015ced eb06e4 movw DE,!0xfe406
ram:015cf0 8a02 mov A,[DE + 0x2]
ram:015cf2 9efc mov CS,A
ram:015cf4 a9 movw AX,[DE]
ram:015cf5 16 movw HL,AX
ram:015cf6 f6 clrw AX
ram:015cf7 61fa call HL
ram:015cf9 eb04e4 movw DE,!0xfe404
ram:015cfc 8a02 mov A,[DE + 0x2]
ram:015cfe 9efc mov CS,A
ram:015d00 a9 movw AX,[DE]
ram:015d01 16 movw HL,AX
ram:015d02 f6 clrw AX
ram:015d03 61fa call HL
ram:015d05 eb0ee4 movw DE,!0xfe40e
ram:015d08 8a02 mov A,[DE + 0x2]
ram:015d0a 9efc mov CS,A
ram:015d0c a9 movw AX,[DE]
ram:015d0d 16 movw HL,AX
ram:015d0e f6 clrw AX
ram:015d0f 61fa call HL
ram:015d11 eb1ce4 movw DE,!0xfe41c
ram:015d14 8a02 mov A,[DE + 0x2]
ram:015d16 9efc mov CS,A
ram:015d18 a9 movw AX,[DE]
ram:015d19 16 movw HL,AX
ram:015d1a f6 clrw AX
ram:015d1b 61fa call HL
ram:015d1d eb1ee4 movw DE,!0xfe41e
ram:015d20 8a02 mov A,[DE + 0x2]
ram:015d22 9efc mov CS,A
ram:015d24 a9 movw AX,[DE]
ram:015d25 16 movw HL,AX
ram:015d26 f6 clrw AX
ram:015d27 61fa call HL
ram:015d29 eb1ae4 movw DE,!0xfe41a
ram:015d2c 8a02 mov A,[DE + 0x2]
ram:015d2e 9efc mov CS,A
ram:015d30 a9 movw AX,[DE]
ram:015d31 16 movw HL,AX
ram:015d32 f6 clrw AX
ram:015d33 61fa call HL
ram:015d35 eb18e4 movw DE,!0xfe418
ram:015d38 8a02 mov A,[DE + 0x2]
ram:015d3a 9efc mov CS,A
ram:015d3c a9 movw AX,[DE]
ram:015d3d 16 movw HL,AX
ram:015d3e f6 clrw AX
ram:015d3f 61fa call HL
ram:015d41 c6 pop HL
ram:015d42 d7 ret
ram:015dc1 c7 push HL
ram:015dc2 c1 push AX
ram:015dc3 c1 push AX
ram:015dc4 fbf8ff movw HL,!0xffff8
ram:015dc7 cc0132 mov [HL + 0x1],0x32
ram:015dca db0ee4 movw BC,!0xfe40e
ram:015dcd 17 movw AX,HL
ram:015dce a1 incw AX
ram:015dcf c1 push AX
ram:015dd0 490e00 mov A,!0xf000e[BC]
ram:015dd3 9efc mov CS,A
ram:015dd5 790c00 movw AX,!0xf000c[BC]
ram:015dd8 14 movw DE,AX
ram:015dd9 e6 onew AX
ram:015dda a1 incw AX
ram:015ddb 61ea call DE
ram:015ddd c0 pop AX
ram:015dde f5f9e6 clrb !0xfe6f9
ram:015de1 f7 clrw BC
ram:015de2 1004 addw SP,0x4
ram:015de4 c6 pop HL
ram:015de5 d7 ret
ram:015de6 c7 push HL
ram:015de7 c1 push AX
ram:015de8 c1 push AX
ram:015de9 fbf8ff movw HL,!0xffff8
ram:015dec cc0101 mov [HL + 0x1],0x1
ram:015def ac02 movw AX,[HL + 0x2]
ram:015df1 14 movw DE,AX
ram:015df2 aa04 movw AX,[DE + 0x4]
ram:015df4 e7 onew BC
ram:015df5 240000 subw AX,0x0
ram:015df8 dd08 bz $ 0x15e02
ram:015dfa 23 subw AX,BC
ram:015dfb dd18 bz $ 0x15e15
ram:015dfd 23 subw AX,BC
ram:015dfe dd30 bz $ 0x15e30
ram:015e00 ef4a br $ 0x15e4c
ram:015e02 714207 set1 0xffe27.0x4
ram:015e05 ac02 movw AX,[HL + 0x2]
ram:015e07 14 movw DE,AX
ram:015e08 306400 movw AX,0x64
ram:015e0b ba06 movw [DE + 0x6],AX
ram:015e0d ac02 movw AX,[HL + 0x2]
ram:015e0f 14 movw DE,AX
ram:015e10 e6 onew AX
ram:015e11 ba04 movw [DE + 0x4],AX
ram:015e13 ef37 br $ 0x15e4c
ram:015e15 fc3e7c00 call !!0x7c3e
ram:015e19 d2 cmp0 C
ram:015e1a 61f8 sknz
ram:015e1c 714307 _clr1 0xffe27.0x4
ram:015e1f ac02 movw AX,[HL + 0x2]
ram:015e21 14 movw DE,AX
ram:015e22 30c800 movw AX,0xc8
ram:015e25 ba06 movw [DE + 0x6],AX
ram:015e27 ac02 movw AX,[HL + 0x2]
ram:015e29 14 movw DE,AX
ram:015e2a e6 onew AX
ram:015e2b a1 incw AX
ram:015e2c ba04 movw [DE + 0x4],AX
ram:015e2e ef1c br $ 0x15e4c
ram:015e30 fc3e7c00 call !!0x7c3e
ram:015e34 d2 cmp0 C
ram:015e35 61f8 sknz
ram:015e37 714207 _set1 0xffe27.0x4
ram:015e3a 30f401 movw AX,0x1f4
ram:015e3d c1 push AX
ram:015e3e 30c15d movw AX,0x5dc1
ram:015e41 5201 mov ,0x1
ram:015e43 f3 clrb B
ram:015e44 fcea7d00 call !!0x7dea
ram:015e48 c0 pop AX
ram:015e49 cc0100 mov [HL + 0x1],0x0
ram:015e4c 8c01 mov A,[HL + 0x1]
ram:015e4e 318e shrw AX,0x8
ram:015e50 12 movw BC,AX
ram:015e51 1004 addw SP,0x4
ram:015e53 c6 pop HL
ram:015e54 d7 ret
ram:015e92 c7 push HL
ram:015e93 16 movw HL,AX
ram:015e94 66 mov A,
ram:015e95 91 dec 
ram:015e96 61e8 skz
ram:015e98 ee7f00 _br $! 0x15f1a
ram:015e9b 8febe1 mov A,!0xfe1eb
ram:015e9e 5cf0 and A,#0xf0
ram:015ea0 9febe1 mov !0xfe1eb,A
ram:015ea3 30b772 movw AX,0x72b7
ram:015ea6 bf16e7 movw !0xfe716,AX
ram:015ea9 cf18e701 mov !0xfe718,0x1
ram:015ead f50ae2 clrb !0xfe20a
ram:015eb0 f50be2 clrb !0xfe20b
ram:015eb3 f50ce2 clrb !0xfe20c
ram:015eb6 f5f8e6 clrb !0xfe6f8
ram:015eb9 f5f9e6 clrb !0xfe6f9
ram:015ebc eb0ee4 movw DE,!0xfe40e
ram:015ebf 8a02 mov A,[DE + 0x2]
ram:015ec1 9efc mov CS,A
ram:015ec3 a9 movw AX,[DE]
ram:015ec4 14 movw DE,AX
ram:015ec5 e6 onew AX
ram:015ec6 61ea call DE
ram:015ec8 eb1ce4 movw DE,!0xfe41c
ram:015ecb 8a02 mov A,[DE + 0x2]
ram:015ecd 9efc mov CS,A
ram:015ecf a9 movw AX,[DE]
ram:015ed0 14 movw DE,AX
ram:015ed1 e6 onew AX
ram:015ed2 61ea call DE
ram:015ed4 eb1ee4 movw DE,!0xfe41e
ram:015ed7 8a02 mov A,[DE + 0x2]
ram:015ed9 9efc mov CS,A
ram:015edb a9 movw AX,[DE]
ram:015edc 14 movw DE,AX
ram:015edd e6 onew AX
ram:015ede 61ea call DE
ram:015ee0 e5eae1 oneb !0xfe1ea
ram:015ee3 f5fae6 clrb !0xfe6fa
ram:015ee6 f5fbe6 clrb !0xfe6fb
ram:015ee9 f5fce6 clrb !0xfe6fc
ram:015eec f5fde6 clrb !0xfe6fd
ram:015eef f6 clrw AX
ram:015ef0 c1 push AX
ram:015ef1 308859 movw AX,0x5988
ram:015ef4 5201 mov ,0x1
ram:015ef6 f3 clrb B
ram:015ef7 fcea7d00 call !!0x7dea
ram:015efb c0 pop AX
ram:015efc 62 mov A,
ram:015efd 9ff8e6 mov !0xfe6f8,A
ram:015f00 30bc02 movw AX,0x2bc
ram:015f03 c1 push AX
ram:015f04 30e65d movw AX,0x5de6
ram:015f07 5201 mov ,0x1
ram:015f09 f3 clrb B
ram:015f0a fcea7d00 call !!0x7dea
ram:015f0e c0 pop AX
ram:015f0f 62 mov A,
ram:015f10 9ff9e6 mov !0xfe6f9,A
ram:015f13 fcc17f00 call !!0x7fc1
ram:015f17 eea600 br $! 0x15fc0
ram:015f1a fca18000 call !!0x80a1
ram:015f1e 7108ebe1 clr1 !0xfe1eb.0x0
ram:015f22 7138ebe1 clr1 !0xfe1eb.0x3
ram:015f26 30b772 movw AX,0x72b7
ram:015f29 bf16e7 movw !0xfe716,AX
ram:015f2c cf18e701 mov !0xfe718,0x1
ram:015f30 d50ae2 cmp0 !0xfe20a
ram:015f33 dd0b bz $ 0x15f40
ram:015f35 d90ae2 mov X,!0xfe20a
ram:015f38 f1 clrb A
ram:015f39 fc927e00 call !!0x7e92
ram:015f3d f50ae2 clrb !0xfe20a
ram:015f40 d50be2 cmp0 !0xfe20b
ram:015f43 dd0b bz $ 0x15f50
ram:015f45 d90be2 mov X,!0xfe20b
ram:015f48 f1 clrb A
ram:015f49 fc927e00 call !!0x7e92
ram:015f4d f50be2 clrb !0xfe20b
ram:015f50 d5f7e6 cmp0 !0xfe6f7
ram:015f53 dd0b bz $ 0x15f60
ram:015f55 d9f7e6 mov X,!0xfe6f7
ram:015f58 f1 clrb A
ram:015f59 fc927e00 call !!0x7e92
ram:015f5d f5f7e6 clrb !0xfe6f7
ram:015f60 d5f8e6 cmp0 !0xfe6f8
ram:015f63 dd0b bz $ 0x15f70
ram:015f65 d9f8e6 mov X,!0xfe6f8
ram:015f68 f1 clrb A
ram:015f69 fc927e00 call !!0x7e92
ram:015f6d f5f8e6 clrb !0xfe6f8
ram:015f70 d5f9e6 cmp0 !0xfe6f9
ram:015f73 dd0b bz $ 0x15f80
ram:015f75 d9f9e6 mov X,!0xfe6f9
ram:015f78 f1 clrb A
ram:015f79 fc927e00 call !!0x7e92
ram:015f7d f5f9e6 clrb !0xfe6f9
ram:015f80 cfeae106 mov !0xfe1ea,0x6
ram:015f84 30435d movw AX,0x5d43
ram:015f87 5201 mov ,0x1
ram:015f89 f3 clrb B
ram:015f8a fc057e00 call !!0x7e05
ram:015f8e d2 cmp0 C
ram:015f8f df2f bnz $ 0x15fc0
ram:015f91 af0ae4 movw AX,!0xfe40a
ram:015f94 f7 clrw BC
ram:015f95 c3 push BC
ram:015f96 14 movw DE,AX
ram:015f97 8a0e mov A,[DE + 0xe]
ram:015f99 9efc mov CS,A
ram:015f9b aa0c movw AX,[DE + 0xc]
ram:015f9d 14 movw DE,AX
ram:015f9e 301700 movw AX,0x17
ram:015fa1 61ea call DE
ram:015fa3 c0 pop AX
ram:015fa4 af0ce4 movw AX,!0xfe40c
ram:015fa7 f7 clrw BC
ram:015fa8 c3 push BC
ram:015fa9 14 movw DE,AX
ram:015faa 8a0e mov A,[DE + 0xe]
ram:015fac 9efc mov CS,A
ram:015fae aa0c movw AX,[DE + 0xc]
ram:015fb0 14 movw DE,AX
ram:015fb1 f6 clrw AX
ram:015fb2 61ea call DE
ram:015fb4 c0 pop AX
ram:015fb5 fcbc5c01 call !!0x15cbc
ram:015fb9 fc7c5701 call !!0x1577c
ram:015fbd f5eae1 clrb !0xfe1ea
ram:015fc0 c6 pop HL
ram:015fc1 d7 ret
ram:015fc6 8feae1 mov A,!0xfe1ea
ram:015fc9 318f sarw AX,0x8
ram:015fcb 12 movw BC,AX
ram:015fcc d7 ret
ram:01611c c7 push HL
ram:01611d c1 push AX
ram:01611e 2042 subw SP,0x42
ram:016120 fbf8ff movw HL,!0xffff8
ram:016123 8c42 mov A,[HL + 0x42]
ram:016125 2cfc sub A,#0xfc
ram:016127 61f8 sknz
ram:016129 ee9905 _br $! 0x166c5
ram:01612c 91 dec 
ram:01612d 61f8 sknz
ram:01612f eec707 _br $! 0x168f9
ram:016132 91 dec 
ram:016133 61f8 sknz
ram:016135 eebb05 _br $! 0x166f3
ram:016138 91 dec 
ram:016139 61f8 sknz
ram:01613b ee6a07 _br $! 0x168a8
ram:01613e 91 dec 
ram:01613f 61f8 sknz
ram:016141 ee8303 _br $! 0x164c7
ram:016144 91 dec 
ram:016145 61f8 sknz
ram:016147 eebc04 _br $! 0x16606
ram:01614a 91 dec 
ram:01614b 61f8 sknz
ram:01614d ee0e05 _br $! 0x1665e
ram:016150 2c03 sub A,#0x3
ram:016152 61f8 sknz
ram:016154 ee2b05 _br $! 0x16682
ram:016157 91 dec 
ram:016158 61f8 sknz
ram:01615a ee5005 _br $! 0x166ad
ram:01615d 91 dec 
ram:01615e 61f8 sknz
ram:016160 ee6302 _br $! 0x163c6
ram:016163 91 dec 
ram:016164 61f8 sknz
ram:016166 ee8602 _br $! 0x163ef
ram:016169 2c02 sub A,#0x2
ram:01616b dd30 bz $ 0x1619d
ram:01616d 91 dec 
ram:01616e 61f8 sknz
ram:016170 ee9b07 _br $! 0x1690e
ram:016173 91 dec 
ram:016174 61f8 sknz
ram:016176 eeea07 _br $! 0x16963
ram:016179 2c04 sub A,#0x4
ram:01617b 61f8 sknz
ram:01617d ee8f05 _br $! 0x1670f
ram:016180 2c08 sub A,#0x8
ram:016182 61f8 sknz
ram:016184 ee4006 _br $! 0x167c7
ram:016187 91 dec 
ram:016188 61f8 sknz
ram:01618a ee7806 _br $! 0x16805
ram:01618d 2c06 sub A,#0x6
ram:01618f 61f8 sknz
ram:016191 eeab06 _br $! 0x1683f
ram:016194 91 dec 
ram:016195 61f8 sknz
ram:016197 ee1507 _br $! 0x168af
ram:01619a eed907 br $! 0x16976
ram:01619d c7 push HL
ram:01619e 17 movw AX,HL
ram:01619f 040200 addw AX,0x2
ram:0161a2 16 movw HL,AX
ram:0161a3 f7 clrw BC
ram:0161a4 49684b mov A,!0xf4b68[BC]
ram:0161a7 9b mov [HL],A
ram:0161a8 a3 incw BC
ram:0161a9 a7 incw HL
ram:0161aa 5140 mov ,0x40
ram:0161ac 614a cmp A,
ram:0161ae dff4 bnz $ 0x161a4
ram:0161b0 c6 pop HL
ram:0161b1 ac4a movw AX,[HL + 0x4a]
ram:0161b3 14 movw DE,AX
ram:0161b4 89 mov A,[DE]
ram:0161b5 2c04 sub A,#0x4
ram:0161b7 61e8 skz
ram:0161b9 ee2501 _br $! 0x162e1
ram:0161bc cc0201 mov [HL + 0x2],0x1
ram:0161bf 8ff4e6 mov A,!0xfe6f4
ram:0161c2 311303 bt A.0x1,$ 0x161c7
ram:0161c5 eeee00 br $! 0x162b6
ram:0161c8 af1ae4 movw AX,!0xfe41a
ram:0161cb e7 onew BC
ram:0161cc c3 push BC
ram:0161cd 12 movw BC,AX
ram:0161ce 17 movw AX,HL
ram:0161cf a1 incw AX
ram:0161d0 c1 push AX
ram:0161d1 491600 mov A,!0xf0016[BC]
ram:0161d4 9dd4 mov 0xffdf4,A
ram:0161d6 791400 movw AX,!0xf0014[BC]
ram:0161d9 c1 push AX
ram:0161da 8dd4 mov A,0xffdf4
ram:0161dc 9dd6 mov 0xffdf6,A
ram:0161de c0 pop AX
ram:0161df 14 movw DE,AX
ram:0161e0 302900 movw AX,0x29
ram:0161e3 f7 clrw BC
ram:0161e4 c1 push AX
ram:0161e5 8dd6 mov A,0xffdf6
ram:0161e7 9efc mov CS,A
ram:0161e9 c0 pop AX
ram:0161ea 61ea call DE
ram:0161ec 1004 addw SP,0x4
ram:0161ee 8c01 mov A,[HL + 0x1]
ram:0161f0 91 dec 
ram:0161f1 df06 bnz $ 0x161f9
ram:0161f3 7110eee1 set1 !0xfe1ee.0x1
ram:0161f7 ef1e br $ 0x16217
ram:0161f9 8c01 mov A,[HL + 0x1]
ram:0161fb 4c02 cmp A,#0x2
ram:0161fd df0a bnz $ 0x16209
ram:0161ff 7118eee1 clr1 !0xfe1ee.0x1
ram:016203 7108eee1 clr1 !0xfe1ee.0x0
ram:016207 ef0e br $ 0x16217
ram:016209 8c01 mov A,[HL + 0x1]
ram:01620b 4c03 cmp A,#0x3
ram:01620d df08 bnz $ 0x16217
ram:01620f 7118eee1 clr1 !0xfe1ee.0x1
ram:016213 7108eee1 clr1 !0xfe1ee.0x0
ram:016217 cc4100 mov [HL + 0x41],0x0
ram:01621a af1ae4 movw AX,!0xfe41a
ram:01621d e7 onew BC
ram:01621e c3 push BC
ram:01621f 12 movw BC,AX
ram:016220 17 movw AX,HL
ram:016221 044100 addw AX,0x41
ram:016224 c1 push AX
ram:016225 491200 mov A,!0xf0012[BC]
ram:016228 9dd4 mov 0xffdf4,A
ram:01622a 791000 movw AX,!0xf0010[BC]
ram:01622d c1 push AX
ram:01622e 8dd4 mov A,0xffdf4
ram:016230 9dd6 mov 0xffdf6,A
ram:016232 c0 pop AX
ram:016233 14 movw DE,AX
ram:016234 302900 movw AX,0x29
ram:016237 f7 clrw BC
ram:016238 c1 push AX
ram:016239 8dd6 mov A,0xffdf6
ram:01623b 9efc mov CS,A
ram:01623d c0 pop AX
ram:01623e 61ea call DE
ram:016240 1004 addw SP,0x4
ram:016242 30ece1 movw AX,0xe1ec
ram:016245 fcda5701 call !!0x157da
ram:016249 13 movw AX,BC
ram:01624a bf08e2 movw !0xfe208,AX
ram:01624d af1ee4 movw AX,!0xfe41e
ram:016250 321e00 movw BC,0x1e
ram:016253 c3 push BC
ram:016254 34ece1 movw DE,0xe1ec
ram:016257 c5 push DE
ram:016258 14 movw DE,AX
ram:016259 8a12 mov A,[DE + 0x12]
ram:01625b 9dd4 mov 0xffdf4,A
ram:01625d aa10 movw AX,[DE + 0x10]
ram:01625f c1 push AX
ram:016260 8dd4 mov A,0xffdf4
ram:016262 9dd6 mov 0xffdf6,A
ram:016264 c0 pop AX
ram:016265 14 movw DE,AX
ram:016266 f6 clrw AX
ram:016267 12 movw BC,AX
ram:016268 c1 push AX
ram:016269 8dd6 mov A,0xffdf6
ram:01626b 9efc mov CS,A
ram:01626d c0 pop AX
ram:01626e 61ea call DE
ram:016270 1004 addw SP,0x4
ram:016272 d2 cmp0 C
ram:016273 61f8 sknz
ram:016275 7130f4e6 _set1 !0xfe6f4.0x3
ram:016279 8c01 mov A,[HL + 0x1]
ram:01627b 91 dec 
ram:01627c dd0b bz $ 0x16289
ram:01627e 8c01 mov A,[HL + 0x1]
ram:016280 d1 cmp0 A
ram:016281 dd06 bz $ 0x16289
ram:016283 8c01 mov A,[HL + 0x1]
ram:016285 4c03 cmp A,#0x3
ram:016287 df55 bnz $ 0x162de
ram:016289 eb0ee4 movw DE,!0xfe40e
ram:01628c 8a06 mov A,[DE + 0x6]
ram:01628e 9efc mov CS,A
ram:016290 aa04 movw AX,[DE + 0x4]
ram:016292 14 movw DE,AX
ram:016293 f6 clrw AX
ram:016294 61ea call DE
ram:016296 eb0ce4 movw DE,!0xfe40c
ram:016299 8a06 mov A,[DE + 0x6]
ram:01629b 9efc mov CS,A
ram:01629d aa04 movw AX,[DE + 0x4]
ram:01629f 14 movw DE,AX
ram:0162a0 f6 clrw AX
ram:0162a1 61ea call DE
ram:0162a3 af00e4 movw AX,!0xfe400
ram:0162a6 f7 clrw BC
ram:0162a7 c3 push BC
ram:0162a8 14 movw DE,AX
ram:0162a9 8a0e mov A,[DE + 0xe]
ram:0162ab 9efc mov CS,A
ram:0162ad aa0c movw AX,[DE + 0xc]
ram:0162af 14 movw DE,AX
ram:0162b0 e6 onew AX
ram:0162b1 61ea call DE
ram:0162b3 c0 pop AX
ram:0162b4 ef28 br $ 0x162de
ram:0162b6 af1ae4 movw AX,!0xfe41a
ram:0162b9 e7 onew BC
ram:0162ba c3 push BC
ram:0162bb 12 movw BC,AX
ram:0162bc 17 movw AX,HL
ram:0162bd 040200 addw AX,0x2
ram:0162c0 c1 push AX
ram:0162c1 491200 mov A,!0xf0012[BC]
ram:0162c4 9dd4 mov 0xffdf4,A
ram:0162c6 791000 movw AX,!0xf0010[BC]
ram:0162c9 c1 push AX
ram:0162ca 8dd4 mov A,0xffdf4
ram:0162cc 9dd6 mov 0xffdf6,A
ram:0162ce c0 pop AX
ram:0162cf 14 movw DE,AX
ram:0162d0 300300 movw AX,0x3
ram:0162d3 f7 clrw BC
ram:0162d4 c1 push AX
ram:0162d5 8dd6 mov A,0xffdf6
ram:0162d7 9efc mov CS,A
ram:0162d9 c0 pop AX
ram:0162da 61ea call DE
ram:0162dc 1004 addw SP,0x4
ram:0162de eee200 br $! 0x163c3
ram:0162e1 ac4a movw AX,[HL + 0x4a]
ram:0162e3 14 movw DE,AX
ram:0162e4 89 mov A,[DE]
ram:0162e5 9c03 mov [HL + 0x3],A
ram:0162e7 ac4a movw AX,[HL + 0x4a]
ram:0162e9 14 movw DE,AX
ram:0162ea 8a01 mov A,[DE + 0x1]
ram:0162ec 9c04 mov [HL + 0x4],A
ram:0162ee ac4a movw AX,[HL + 0x4a]
ram:0162f0 14 movw DE,AX
ram:0162f1 89 mov A,[DE]
ram:0162f2 d1 cmp0 A
ram:0162f3 dd0f bz $ 0x16304
ram:0162f5 91 dec 
ram:0162f6 dd3b bz $ 0x16333
ram:0162f8 91 dec 
ram:0162f9 dd67 bz $ 0x16362
ram:0162fb 91 dec 
ram:0162fc 61f8 sknz
ram:0162fe ee9000 _br $! 0x16391
ram:016301 eea500 br $! 0x163a9
ram:016304 af1ae4 movw AX,!0xfe41a
ram:016307 f7 clrw BC
ram:016308 c3 push BC
ram:016309 12 movw BC,AX
ram:01630a 17 movw AX,HL
ram:01630b 040400 addw AX,0x4
ram:01630e c1 push AX
ram:01630f 491600 mov A,!0xf0016[BC]
ram:016312 9dd4 mov 0xffdf4,A
ram:016314 791400 movw AX,!0xf0014[BC]
ram:016317 c1 push AX
ram:016318 8dd4 mov A,0xffdf4
ram:01631a 9dd6 mov 0xffdf6,A
ram:01631c c0 pop AX
ram:01631d 14 movw DE,AX
ram:01631e 302400 movw AX,0x24
ram:016321 f7 clrw BC
ram:016322 c1 push AX
ram:016323 8dd6 mov A,0xffdf6
ram:016325 9efc mov CS,A
ram:016327 c0 pop AX
ram:016328 61ea call DE
ram:01632a 1004 addw SP,0x4
ram:01632c 62 mov A,
ram:01632d 0c03 add A,#0x3
ram:01632f 9c02 mov [HL + 0x2],A
ram:016331 ef76 br $ 0x163a9
ram:016333 af1ae4 movw AX,!0xfe41a
ram:016336 f7 clrw BC
ram:016337 c3 push BC
ram:016338 12 movw BC,AX
ram:016339 17 movw AX,HL
ram:01633a 040400 addw AX,0x4
ram:01633d c1 push AX
ram:01633e 491600 mov A,!0xf0016[BC]
ram:016341 9dd4 mov 0xffdf4,A
ram:016343 791400 movw AX,!0xf0014[BC]
ram:016346 c1 push AX
ram:016347 8dd4 mov A,0xffdf4
ram:016349 9dd6 mov 0xffdf6,A
ram:01634b c0 pop AX
ram:01634c 14 movw DE,AX
ram:01634d 302500 movw AX,0x25
ram:016350 f7 clrw BC
ram:016351 c1 push AX
ram:016352 8dd6 mov A,0xffdf6
ram:016354 9efc mov CS,A
ram:016356 c0 pop AX
ram:016357 61ea call DE
ram:016359 1004 addw SP,0x4
ram:01635b 62 mov A,
ram:01635c 0c03 add A,#0x3
ram:01635e 9c02 mov [HL + 0x2],A
ram:016360 ef47 br $ 0x163a9
ram:016362 af1ae4 movw AX,!0xfe41a
ram:016365 f7 clrw BC
ram:016366 c3 push BC
ram:016367 12 movw BC,AX
ram:016368 17 movw AX,HL
ram:016369 040400 addw AX,0x4
ram:01636c c1 push AX
ram:01636d 491600 mov A,!0xf0016[BC]
ram:016370 9dd4 mov 0xffdf4,A
ram:016372 791400 movw AX,!0xf0014[BC]
ram:016375 c1 push AX
ram:016376 8dd4 mov A,0xffdf4
ram:016378 9dd6 mov 0xffdf6,A
ram:01637a c0 pop AX
ram:01637b 14 movw DE,AX
ram:01637c 302600 movw AX,0x26
ram:01637f f7 clrw BC
ram:016380 c1 push AX
ram:016381 8dd6 mov A,0xffdf6
ram:016383 9efc mov CS,A
ram:016385 c0 pop AX
ram:016386 61ea call DE
ram:016388 1004 addw SP,0x4
ram:01638a 62 mov A,
ram:01638b 0c03 add A,#0x3
ram:01638d 9c02 mov [HL + 0x2],A
ram:01638f ef18 br $ 0x163a9
ram:016391 cc0227 mov [HL + 0x2],0x27
ram:016394 cc0501 mov [HL + 0x5],0x1
ram:016397 302400 movw AX,0x24
ram:01639a c1 push AX
ram:01639b 34d4e9 movw DE,0xe9d4
ram:01639e c5 push DE
ram:01639f 17 movw AX,HL
ram:0163a0 040600 addw AX,0x6
ram:0163a3 fc66e500 call !!0xe566
ram:0163a7 1004 addw SP,0x4
ram:0163a9 8c02 mov A,[HL + 0x2]
ram:0163ab 0c04 add A,#0x4
ram:0163ad 318e shrw AX,0x8
ram:0163af c1 push AX
ram:0163b0 17 movw AX,HL
ram:0163b1 040200 addw AX,0x2
ram:0163b4 c1 push AX
ram:0163b5 300a00 movw AX,0xa
ram:0163b8 c1 push AX
ram:0163b9 e6 onew AX
ram:0163ba a1 incw AX
ram:0163bb c1 push AX
ram:0163bc e6 onew AX
ram:0163bd fcb75401 call !!0x154b7
ram:0163c1 1008 addw SP,0x8
ram:0163c3 eeb005 br $! 0x16976
ram:0163c6 af00e4 movw AX,!0xfe400
ram:0163c9 e7 onew BC
ram:0163ca c3 push BC
ram:0163cb 12 movw BC,AX
ram:0163cc ac4a movw AX,[HL + 0x4a]
ram:0163ce c1 push AX
ram:0163cf 491200 mov A,!0xf0012[BC]
ram:0163d2 9dd4 mov 0xffdf4,A
ram:0163d4 791000 movw AX,!0xf0010[BC]
ram:0163d7 c1 push AX
ram:0163d8 8dd4 mov A,0xffdf4
ram:0163da 9dd6 mov 0xffdf6,A
ram:0163dc c0 pop AX
ram:0163dd 14 movw DE,AX
ram:0163de 304200 movw AX,0x42
ram:0163e1 f7 clrw BC
ram:0163e2 c1 push AX
ram:0163e3 8dd6 mov A,0xffdf6
ram:0163e5 9efc mov CS,A
ram:0163e7 c0 pop AX
ram:0163e8 61ea call DE
ram:0163ea 1004 addw SP,0x4
ram:0163ec ee8705 br $! 0x16976
ram:0163ef ac4a movw AX,[HL + 0x4a]
ram:0163f1 14 movw DE,AX
ram:0163f2 89 mov A,[DE]
ram:0163f3 2c04 sub A,#0x4
ram:0163f5 61e8 skz
ram:0163f7 eeca00 _br $! 0x164c4
ram:0163fa af1ae4 movw AX,!0xfe41a
ram:0163fd e7 onew BC
ram:0163fe c3 push BC
ram:0163ff 12 movw BC,AX
ram:016400 17 movw AX,HL
ram:016401 044100 addw AX,0x41
ram:016404 c1 push AX
ram:016405 491600 mov A,!0xf0016[BC]
ram:016408 9dd4 mov 0xffdf4,A
ram:01640a 791400 movw AX,!0xf0014[BC]
ram:01640d c1 push AX
ram:01640e 8dd4 mov A,0xffdf4
ram:016410 9dd6 mov 0xffdf6,A
ram:016412 c0 pop AX
ram:016413 14 movw DE,AX
ram:016414 302900 movw AX,0x29
ram:016417 f7 clrw BC
ram:016418 c1 push AX
ram:016419 8dd6 mov A,0xffdf6
ram:01641b 9efc mov CS,A
ram:01641d c0 pop AX
ram:01641e 61ea call DE
ram:016420 1004 addw SP,0x4
ram:016422 8c41 mov A,[HL + 0x41]
ram:016424 91 dec 
ram:016425 df06 bnz $ 0x1642d
ram:016427 7110eee1 set1 !0xfe1ee.0x1
ram:01642b ef0a br $ 0x16437
ram:01642d 8c41 mov A,[HL + 0x41]
ram:01642f 4c02 cmp A,#0x2
ram:016431 61f8 sknz
ram:016433 7118eee1 _clr1 !0xfe1ee.0x1
ram:016437 cc4100 mov [HL + 0x41],0x0
ram:01643a af1ae4 movw AX,!0xfe41a
ram:01643d e7 onew BC
ram:01643e c3 push BC
ram:01643f 12 movw BC,AX
ram:016440 17 movw AX,HL
ram:016441 044100 addw AX,0x41
ram:016444 c1 push AX
ram:016445 491200 mov A,!0xf0012[BC]
ram:016448 9dd4 mov 0xffdf4,A
ram:01644a 791000 movw AX,!0xf0010[BC]
ram:01644d c1 push AX
ram:01644e 8dd4 mov A,0xffdf4
ram:016450 9dd6 mov 0xffdf6,A
ram:016452 c0 pop AX
ram:016453 14 movw DE,AX
ram:016454 302900 movw AX,0x29
ram:016457 f7 clrw BC
ram:016458 c1 push AX
ram:016459 8dd6 mov A,0xffdf6
ram:01645b 9efc mov CS,A
ram:01645d c0 pop AX
ram:01645e 61ea call DE
ram:016460 1004 addw SP,0x4
ram:016462 30ece1 movw AX,0xe1ec
ram:016465 fcda5701 call !!0x157da
ram:016469 13 movw AX,BC
ram:01646a bf08e2 movw !0xfe208,AX
ram:01646d af1ee4 movw AX,!0xfe41e
ram:016470 321e00 movw BC,0x1e
ram:016473 c3 push BC
ram:016474 34ece1 movw DE,0xe1ec
ram:016477 c5 push DE
ram:016478 14 movw DE,AX
ram:016479 8a12 mov A,[DE + 0x12]
ram:01647b 9dd4 mov 0xffdf4,A
ram:01647d aa10 movw AX,[DE + 0x10]
ram:01647f c1 push AX
ram:016480 8dd4 mov A,0xffdf4
ram:016482 9dd6 mov 0xffdf6,A
ram:016484 c0 pop AX
ram:016485 14 movw DE,AX
ram:016486 f6 clrw AX
ram:016487 12 movw BC,AX
ram:016488 c1 push AX
ram:016489 8dd6 mov A,0xffdf6
ram:01648b 9efc mov CS,A
ram:01648d c0 pop AX
ram:01648e 61ea call DE
ram:016490 1004 addw SP,0x4
ram:016492 d2 cmp0 C
ram:016493 61f8 sknz
ram:016495 7130f4e6 _set1 !0xfe6f4.0x3
ram:016499 eb0ee4 movw DE,!0xfe40e
ram:01649c 8a06 mov A,[DE + 0x6]
ram:01649e 9efc mov CS,A
ram:0164a0 aa04 movw AX,[DE + 0x4]
ram:0164a2 14 movw DE,AX
ram:0164a3 f6 clrw AX
ram:0164a4 61ea call DE
ram:0164a6 eb0ce4 movw DE,!0xfe40c
ram:0164a9 8a06 mov A,[DE + 0x6]
ram:0164ab 9efc mov CS,A
ram:0164ad aa04 movw AX,[DE + 0x4]
ram:0164af 14 movw DE,AX
ram:0164b0 f6 clrw AX
ram:0164b1 61ea call DE
ram:0164b3 af00e4 movw AX,!0xfe400
ram:0164b6 f7 clrw BC
ram:0164b7 c3 push BC
ram:0164b8 14 movw DE,AX
ram:0164b9 8a0e mov A,[DE + 0xe]
ram:0164bb 9efc mov CS,A
ram:0164bd aa0c movw AX,[DE + 0xc]
ram:0164bf 14 movw DE,AX
ram:0164c0 e6 onew AX
ram:0164c1 61ea call DE
ram:0164c3 c0 pop AX
ram:0164c4 eeaf04 br $! 0x16976
ram:0164c7 7130ebe1 set1 !0xfe1eb.0x3
ram:0164cb 8febe1 mov A,!0xfe1eb
ram:0164ce 310516 bf A.0x0,$ 0x164e6
ram:0164d1 af02e4 movw AX,!0xfe402
ram:0164d4 34f4e6 movw DE,0xe6f4
ram:0164d7 c5 push DE
ram:0164d8 14 movw DE,AX
ram:0164d9 8a1a mov A,[DE + 0x1a]
ram:0164db 9efc mov CS,A
ram:0164dd aa18 movw AX,[DE + 0x18]
ram:0164df 14 movw DE,AX
ram:0164e0 f6 clrw AX
ram:0164e1 61ea call DE
ram:0164e3 c0 pop AX
ram:0164e4 ee1c01 br $! 0x16603
ram:0164e7 cc4102 mov [HL + 0x41],0x2
ram:0164ea db00e4 movw BC,!0xfe400
ram:0164ed 17 movw AX,HL
ram:0164ee 044100 addw AX,0x41
ram:0164f1 c1 push AX
ram:0164f2 491a00 mov A,!0xf001a[BC]
ram:0164f5 9efc mov CS,A
ram:0164f7 791800 movw AX,!0xf0018[BC]
ram:0164fa 14 movw DE,AX
ram:0164fb 300600 movw AX,0x6
ram:0164fe 61ea call DE
ram:016500 c0 pop AX
ram:016501 af12e4 movw AX,!0xfe412
ram:016504 e7 onew BC
ram:016505 c3 push BC
ram:016506 12 movw BC,AX
ram:016507 17 movw AX,HL
ram:016508 044100 addw AX,0x41
ram:01650b c1 push AX
ram:01650c 491200 mov A,!0xf0012[BC]
ram:01650f 9dd4 mov 0xffdf4,A
ram:016511 791000 movw AX,!0xf0010[BC]
ram:016514 c1 push AX
ram:016515 8dd4 mov A,0xffdf4
ram:016517 9dd6 mov 0xffdf6,A
ram:016519 c0 pop AX
ram:01651a 14 movw DE,AX
ram:01651b 304400 movw AX,0x44
ram:01651e f7 clrw BC
ram:01651f c1 push AX
ram:016520 8dd6 mov A,0xffdf6
ram:016522 9efc mov CS,A
ram:016524 c0 pop AX
ram:016525 61ea call DE
ram:016527 1004 addw SP,0x4
ram:016529 c7 push HL
ram:01652a 17 movw AX,HL
ram:01652b 044000 addw AX,0x40
ram:01652e 16 movw HL,AX
ram:01652f f7 clrw BC
ram:016530 49a84b mov A,!0xf4ba8[BC]
ram:016533 9b mov [HL],A
ram:016534 a3 incw BC
ram:016535 a7 incw HL
ram:016536 5102 mov ,0x2
ram:016538 614a cmp A,
ram:01653a dff4 bnz $ 0x16530
ram:01653c c6 pop HL
ram:01653d d5fae6 cmp0 !0xfe6fa
ram:016540 df7a bnz $ 0x165bc
ram:016542 8ff4e6 mov A,!0xfe6f4
ram:016545 311348 bt A.0x1,$ 0x1658f
ram:016548 7120ebe1 set1 !0xfe1eb.0x2
ram:01654c af1ae4 movw AX,!0xfe41a
ram:01654f e7 onew BC
ram:016550 a3 incw BC
ram:016551 c3 push BC
ram:016552 12 movw BC,AX
ram:016553 17 movw AX,HL
ram:016554 044000 addw AX,0x40
ram:016557 c1 push AX
ram:016558 491200 mov A,!0xf0012[BC]
ram:01655b 9dd4 mov 0xffdf4,A
ram:01655d 791000 movw AX,!0xf0010[BC]
ram:016560 c1 push AX
ram:016561 8dd4 mov A,0xffdf4
ram:016563 9dd6 mov 0xffdf6,A
ram:016565 c0 pop AX
ram:016566 14 movw DE,AX
ram:016567 302100 movw AX,0x21
ram:01656a f7 clrw BC
ram:01656b c1 push AX
ram:01656c 8dd6 mov A,0xffdf6
ram:01656e 9efc mov CS,A
ram:016570 c0 pop AX
ram:016571 61ea call DE
ram:016573 1004 addw SP,0x4
ram:016575 d5f7e6 cmp0 !0xfe6f7
ram:016578 df13 bnz $ 0x1658d
ram:01657a 30e803 movw AX,0x3e8
ram:01657d c1 push AX
ram:01657e 30e95f movw AX,0x5fe9
ram:016581 5201 mov ,0x1
ram:016583 f3 clrb B
ram:016584 fcea7d00 call !!0x7dea
ram:016588 c0 pop AX
ram:016589 62 mov A,
ram:01658a 9ff7e6 mov !0xfe6f7,A
ram:01658d eee603 br $! 0x16976
ram:016590 cc4101 mov [HL + 0x41],0x1
ram:016593 af1ae4 movw AX,!0xfe41a
ram:016596 e7 onew BC
ram:016597 a3 incw BC
ram:016598 c3 push BC
ram:016599 12 movw BC,AX
ram:01659a 17 movw AX,HL
ram:01659b 044000 addw AX,0x40
ram:01659e c1 push AX
ram:01659f 491200 mov A,!0xf0012[BC]
ram:0165a2 9dd4 mov 0xffdf4,A
ram:0165a4 791000 movw AX,!0xf0010[BC]
ram:0165a7 c1 push AX
ram:0165a8 8dd4 mov A,0xffdf4
ram:0165aa 9dd6 mov 0xffdf6,A
ram:0165ac c0 pop AX
ram:0165ad 14 movw DE,AX
ram:0165ae 302100 movw AX,0x21
ram:0165b1 f7 clrw BC
ram:0165b2 c1 push AX
ram:0165b3 8dd6 mov A,0xffdf6
ram:0165b5 9efc mov CS,A
ram:0165b7 c0 pop AX
ram:0165b8 61ea call DE
ram:0165ba 1004 addw SP,0x4
ram:0165bc 7100ebe1 set1 !0xfe1eb.0x0
ram:0165c0 301673 movw AX,0x7316
ram:0165c3 bf16e7 movw !0xfe716,AX
ram:0165c6 cf18e701 mov !0xfe718,0x1
ram:0165ca af02e4 movw AX,!0xfe402
ram:0165cd 34f4e6 movw DE,0xe6f4
ram:0165d0 c5 push DE
ram:0165d1 14 movw DE,AX
ram:0165d2 8a1a mov A,[DE + 0x1a]
ram:0165d4 9efc mov CS,A
ram:0165d6 aa18 movw AX,[DE + 0x18]
ram:0165d8 14 movw DE,AX
ram:0165d9 f6 clrw AX
ram:0165da 61ea call DE
ram:0165dc c0 pop AX
ram:0165dd 303075 movw AX,0x7530
ram:0165e0 c1 push AX
ram:0165e1 30555e movw AX,0x5e55
ram:0165e4 5201 mov ,0x1
ram:0165e6 f3 clrb B
ram:0165e7 fcea7d00 call !!0x7dea
ram:0165eb c0 pop AX
ram:0165ec 62 mov A,
ram:0165ed 9f0be2 mov !0xfe20b,A
ram:0165f0 af08e4 movw AX,!0xfe408
ram:0165f3 f7 clrw BC
ram:0165f4 c3 push BC
ram:0165f5 14 movw DE,AX
ram:0165f6 8a0e mov A,[DE + 0xe]
ram:0165f8 9efc mov CS,A
ram:0165fa aa0c movw AX,[DE + 0xc]
ram:0165fc 14 movw DE,AX
ram:0165fd 300300 movw AX,0x3
ram:016600 61ea call DE
ram:016602 c0 pop AX
ram:016603 ee7003 br $! 0x16976
ram:016606 ac4a movw AX,[HL + 0x4a]
ram:016608 14 movw DE,AX
ram:016609 89 mov A,[DE]
ram:01660a 91 dec 
ram:01660b df27 bnz $ 0x16634
ram:01660d e5fbe6 oneb !0xfe6fb
ram:016610 af0ae4 movw AX,!0xfe40a
ram:016613 f7 clrw BC
ram:016614 c3 push BC
ram:016615 14 movw DE,AX
ram:016616 8a0e mov A,[DE + 0xe]
ram:016618 9efc mov CS,A
ram:01661a aa0c movw AX,[DE + 0xc]
ram:01661c 14 movw DE,AX
ram:01661d 301000 movw AX,0x10
ram:016620 61ea call DE
ram:016622 c0 pop AX
ram:016623 302c01 movw AX,0x12c
ram:016626 c1 push AX
ram:016627 30cd5f movw AX,0x5fcd
ram:01662a 5201 mov ,0x1
ram:01662c f3 clrb B
ram:01662d fcea7d00 call !!0x7dea
ram:016631 c0 pop AX
ram:016632 ef27 br $ 0x1665b
ram:016634 f5fbe6 clrb !0xfe6fb
ram:016637 af0ce4 movw AX,!0xfe40c
ram:01663a f7 clrw BC
ram:01663b c3 push BC
ram:01663c 14 movw DE,AX
ram:01663d 8a0e mov A,[DE + 0xe]
ram:01663f 9efc mov CS,A
ram:016641 aa0c movw AX,[DE + 0xc]
ram:016643 14 movw DE,AX
ram:016644 e6 onew AX
ram:016645 61ea call DE
ram:016647 c0 pop AX
ram:016648 af0ae4 movw AX,!0xfe40a
ram:01664b f7 clrw BC
ram:01664c c3 push BC
ram:01664d 14 movw DE,AX
ram:01664e 8a0e mov A,[DE + 0xe]
ram:016650 9efc mov CS,A
ram:016652 aa0c movw AX,[DE + 0xc]
ram:016654 14 movw DE,AX
ram:016655 301100 movw AX,0x11
ram:016658 61ea call DE
ram:01665a c0 pop AX
ram:01665b ee1803 br $! 0x16976
ram:01665e ac4a movw AX,[HL + 0x4a]
ram:016660 14 movw DE,AX
ram:016661 89 mov A,[DE]
ram:016662 318e shrw AX,0x8
ram:016664 c1 push AX
ram:016665 ac4a movw AX,[HL + 0x4a]
ram:016667 c1 push AX
ram:016668 e6 onew AX
ram:016669 a1 incw AX
ram:01666a c1 push AX
ram:01666b a1 incw AX
ram:01666c c1 push AX
ram:01666d e6 onew AX
ram:01666e fcb75401 call !!0x154b7
ram:016672 1008 addw SP,0x8
ram:016674 ac4a movw AX,[HL + 0x4a]
ram:016676 14 movw DE,AX
ram:016677 8a01 mov A,[DE + 0x1]
ram:016679 318e shrw AX,0x8
ram:01667b fc2b8b01 call !!0x18b2b
ram:01667f eef402 br $! 0x16976
ram:016682 af0ce4 movw AX,!0xfe40c
ram:016685 f7 clrw BC
ram:016686 c3 push BC
ram:016687 14 movw DE,AX
ram:016688 8a0e mov A,[DE + 0xe]
ram:01668a 9efc mov CS,A
ram:01668c aa0c movw AX,[DE + 0xc]
ram:01668e 14 movw DE,AX
ram:01668f f6 clrw AX
ram:016690 61ea call DE
ram:016692 c0 pop AX
ram:016693 af0ae4 movw AX,!0xfe40a
ram:016696 f7 clrw BC
ram:016697 c3 push BC
ram:016698 14 movw DE,AX
ram:016699 8a0e mov A,[DE + 0xe]
ram:01669b 9efc mov CS,A
ram:01669d aa0c movw AX,[DE + 0xc]
ram:01669f 14 movw DE,AX
ram:0166a0 301000 movw AX,0x10
ram:0166a3 61ea call DE
ram:0166a5 c0 pop AX
ram:0166a6 fc931900 call !!0x1993
ram:0166aa eec902 br $! 0x16976
ram:0166ad db0ae4 movw BC,!0xfe40a
ram:0166b0 ac4a movw AX,[HL + 0x4a]
ram:0166b2 c1 push AX
ram:0166b3 490e00 mov A,!0xf000e[BC]
ram:0166b6 9efc mov CS,A
ram:0166b8 790c00 movw AX,!0xf000c[BC]
ram:0166bb 14 movw DE,AX
ram:0166bc 304000 movw AX,0x40
ram:0166bf 61ea call DE
ram:0166c1 c0 pop AX
ram:0166c2 eeb102 br $! 0x16976
ram:0166c5 eb0ee4 movw DE,!0xfe40e
ram:0166c8 8a06 mov A,[DE + 0x6]
ram:0166ca 9efc mov CS,A
ram:0166cc aa04 movw AX,[DE + 0x4]
ram:0166ce 14 movw DE,AX
ram:0166cf f6 clrw AX
ram:0166d0 61ea call DE
ram:0166d2 eb0ce4 movw DE,!0xfe40c
ram:0166d5 8a06 mov A,[DE + 0x6]
ram:0166d7 9efc mov CS,A
ram:0166d9 aa04 movw AX,[DE + 0x4]
ram:0166db 14 movw DE,AX
ram:0166dc f6 clrw AX
ram:0166dd 61ea call DE
ram:0166df af00e4 movw AX,!0xfe400
ram:0166e2 f7 clrw BC
ram:0166e3 c3 push BC
ram:0166e4 14 movw DE,AX
ram:0166e5 8a0e mov A,[DE + 0xe]
ram:0166e7 9efc mov CS,A
ram:0166e9 aa0c movw AX,[DE + 0xc]
ram:0166eb 14 movw DE,AX
ram:0166ec e6 onew AX
ram:0166ed 61ea call DE
ram:0166ef c0 pop AX
ram:0166f0 ee8302 br $! 0x16976
ram:0166f3 fcbc5c01 call !!0x15cbc
ram:0166f7 7108ebe1 clr1 !0xfe1eb.0x0
ram:0166fb 7138ebe1 clr1 !0xfe1eb.0x3
ram:0166ff 30b772 movw AX,0x72b7
ram:016702 bf16e7 movw !0xfe716,AX
ram:016705 cf18e701 mov !0xfe718,0x1
ram:016709 f5eae1 clrb !0xfe1ea
ram:01670c ee6702 br $! 0x16976
ram:01670f c7 push HL
ram:016710 17 movw AX,HL
ram:016711 044000 addw AX,0x40
ram:016714 16 movw HL,AX
ram:016715 f7 clrw BC
ram:016716 49aa4b mov A,!0xf4baa[BC]
ram:016719 9b mov [HL],A
ram:01671a a3 incw BC
ram:01671b a7 incw HL
ram:01671c 5102 mov ,0x2
ram:01671e 614a cmp A,
ram:016720 dff4 bnz $ 0x16716
ram:016722 c6 pop HL
ram:016723 ac4a movw AX,[HL + 0x4a]
ram:016725 14 movw DE,AX
ram:016726 89 mov A,[DE]
ram:016727 d1 cmp0 A
ram:016728 dd6d bz $ 0x16797
ram:01672a 7100eee1 set1 !0xfe1ee.0x0
ram:01672e 30ece1 movw AX,0xe1ec
ram:016731 fcda5701 call !!0x157da
ram:016735 13 movw AX,BC
ram:016736 bf08e2 movw !0xfe208,AX
ram:016739 af1ee4 movw AX,!0xfe41e
ram:01673c 321e00 movw BC,0x1e
ram:01673f c3 push BC
ram:016740 34ece1 movw DE,0xe1ec
ram:016743 c5 push DE
ram:016744 14 movw DE,AX
ram:016745 8a12 mov A,[DE + 0x12]
ram:016747 9dd4 mov 0xffdf4,A
ram:016749 aa10 movw AX,[DE + 0x10]
ram:01674b c1 push AX
ram:01674c 8dd4 mov A,0xffdf4
ram:01674e 9dd6 mov 0xffdf6,A
ram:016750 c0 pop AX
ram:016751 14 movw DE,AX
ram:016752 f6 clrw AX
ram:016753 12 movw BC,AX
ram:016754 c1 push AX
ram:016755 8dd6 mov A,0xffdf6
ram:016757 9efc mov CS,A
ram:016759 c0 pop AX
ram:01675a 61ea call DE
ram:01675c 1004 addw SP,0x4
ram:01675e d2 cmp0 C
ram:01675f 61f8 sknz
ram:016761 7130f4e6 _set1 !0xfe6f4.0x3
ram:016765 cc4101 mov [HL + 0x41],0x1
ram:016768 af1ae4 movw AX,!0xfe41a
ram:01676b e7 onew BC
ram:01676c a3 incw BC
ram:01676d c3 push BC
ram:01676e 12 movw BC,AX
ram:01676f 17 movw AX,HL
ram:016770 044000 addw AX,0x40
ram:016773 c1 push AX
ram:016774 491200 mov A,!0xf0012[BC]
ram:016777 9dd4 mov 0xffdf4,A
ram:016779 791000 movw AX,!0xf0010[BC]
ram:01677c c1 push AX
ram:01677d 8dd4 mov A,0xffdf4
ram:01677f 9dd6 mov 0xffdf6,A
ram:016781 c0 pop AX
ram:016782 14 movw DE,AX
ram:016783 302100 movw AX,0x21
ram:016786 f7 clrw BC
ram:016787 c1 push AX
ram:016788 8dd6 mov A,0xffdf6
ram:01678a 9efc mov CS,A
ram:01678c c0 pop AX
ram:01678d 61ea call DE
ram:01678f 1004 addw SP,0x4
ram:016791 7120f4e6 set1 !0xfe6f4.0x2
ram:016795 ef2d br $ 0x167c4
ram:016797 7128f4e6 clr1 !0xfe6f4.0x2
ram:01679b af1ae4 movw AX,!0xfe41a
ram:01679e e7 onew BC
ram:01679f a3 incw BC
ram:0167a0 c3 push BC
ram:0167a1 12 movw BC,AX
ram:0167a2 17 movw AX,HL
ram:0167a3 044000 addw AX,0x40
ram:0167a6 c1 push AX
ram:0167a7 491200 mov A,!0xf0012[BC]
ram:0167aa 9dd4 mov 0xffdf4,A
ram:0167ac 791000 movw AX,!0xf0010[BC]
ram:0167af c1 push AX
ram:0167b0 8dd4 mov A,0xffdf4
ram:0167b2 9dd6 mov 0xffdf6,A
ram:0167b4 c0 pop AX
ram:0167b5 14 movw DE,AX
ram:0167b6 302100 movw AX,0x21
ram:0167b9 f7 clrw BC
ram:0167ba c1 push AX
ram:0167bb 8dd6 mov A,0xffdf6
ram:0167bd 9efc mov CS,A
ram:0167bf c0 pop AX
ram:0167c0 61ea call DE
ram:0167c2 1004 addw SP,0x4
ram:0167c4 eeaf01 br $! 0x16976
ram:0167c7 7118eee1 clr1 !0xfe1ee.0x1
ram:0167cb 30ece1 movw AX,0xe1ec
ram:0167ce fcda5701 call !!0x157da
ram:0167d2 13 movw AX,BC
ram:0167d3 bf08e2 movw !0xfe208,AX
ram:0167d6 af1ee4 movw AX,!0xfe41e
ram:0167d9 321e00 movw BC,0x1e
ram:0167dc c3 push BC
ram:0167dd 34ece1 movw DE,0xe1ec
ram:0167e0 c5 push DE
ram:0167e1 14 movw DE,AX
ram:0167e2 8a12 mov A,[DE + 0x12]
ram:0167e4 9dd4 mov 0xffdf4,A
ram:0167e6 aa10 movw AX,[DE + 0x10]
ram:0167e8 c1 push AX
ram:0167e9 8dd4 mov A,0xffdf4
ram:0167eb 9dd6 mov 0xffdf6,A
ram:0167ed c0 pop AX
ram:0167ee 14 movw DE,AX
ram:0167ef f6 clrw AX
ram:0167f0 12 movw BC,AX
ram:0167f1 c1 push AX
ram:0167f2 8dd6 mov A,0xffdf6
ram:0167f4 9efc mov CS,A
ram:0167f6 c0 pop AX
ram:0167f7 61ea call DE
ram:0167f9 1004 addw SP,0x4
ram:0167fb d2 cmp0 C
ram:0167fc 61f8 sknz
ram:0167fe 7130f4e6 _set1 !0xfe6f4.0x3
ram:016802 ee7101 br $! 0x16976
ram:016805 30ece1 movw AX,0xe1ec
ram:016808 fcda5701 call !!0x157da
ram:01680c 13 movw AX,BC
ram:01680d bf08e2 movw !0xfe208,AX
ram:016810 af1ee4 movw AX,!0xfe41e
ram:016813 321e00 movw BC,0x1e
ram:016816 c3 push BC
ram:016817 34ece1 movw DE,0xe1ec
ram:01681a c5 push DE
ram:01681b 14 movw DE,AX
ram:01681c 8a12 mov A,[DE + 0x12]
ram:01681e 9dd4 mov 0xffdf4,A
ram:016820 aa10 movw AX,[DE + 0x10]
ram:016822 c1 push AX
ram:016823 8dd4 mov A,0xffdf4
ram:016825 9dd6 mov 0xffdf6,A
ram:016827 c0 pop AX
ram:016828 14 movw DE,AX
ram:016829 f6 clrw AX
ram:01682a 12 movw BC,AX
ram:01682b c1 push AX
ram:01682c 8dd6 mov A,0xffdf6
ram:01682e 9efc mov CS,A
ram:016830 c0 pop AX
ram:016831 61ea call DE
ram:016833 1004 addw SP,0x4
ram:016835 d2 cmp0 C
ram:016836 61f8 sknz
ram:016838 7130f4e6 _set1 !0xfe6f4.0x3
ram:01683c ee3701 br $! 0x16976
ram:01683f ac4a movw AX,[HL + 0x4a]
ram:016841 14 movw DE,AX
ram:016842 89 mov A,[DE]
ram:016843 91 dec 
ram:016844 df09 bnz $ 0x1684f
ram:016846 30ece1 movw AX,0xe1ec
ram:016849 fcd95801 call !!0x158d9
ram:01684d ef1f br $ 0x1686e
ram:01684f ac4a movw AX,[HL + 0x4a]
ram:016851 14 movw DE,AX
ram:016852 89 mov A,[DE]
ram:016853 d1 cmp0 A
ram:016854 df09 bnz $ 0x1685f
ram:016856 30ece1 movw AX,0xe1ec
ram:016859 fc235801 call !!0x15823
ram:01685d ef0f br $ 0x1686e
ram:01685f ac4a movw AX,[HL + 0x4a]
ram:016861 14 movw DE,AX
ram:016862 89 mov A,[DE]
ram:016863 4c02 cmp A,#0x2
ram:016865 df07 bnz $ 0x1686e
ram:016867 30ece1 movw AX,0xe1ec
ram:01686a fce95801 call !!0x158e9
ram:01686e 30ece1 movw AX,0xe1ec
ram:016871 fcda5701 call !!0x157da
ram:016875 13 movw AX,BC
ram:016876 bf08e2 movw !0xfe208,AX
ram:016879 af1ee4 movw AX,!0xfe41e
ram:01687c 321e00 movw BC,0x1e
ram:01687f c3 push BC
ram:016880 34ece1 movw DE,0xe1ec
ram:016883 c5 push DE
ram:016884 14 movw DE,AX
ram:016885 8a12 mov A,[DE + 0x12]
ram:016887 9dd4 mov 0xffdf4,A
ram:016889 aa10 movw AX,[DE + 0x10]
ram:01688b c1 push AX
ram:01688c 8dd4 mov A,0xffdf4
ram:01688e 9dd6 mov 0xffdf6,A
ram:016890 c0 pop AX
ram:016891 14 movw DE,AX
ram:016892 f6 clrw AX
ram:016893 12 movw BC,AX
ram:016894 c1 push AX
ram:016895 8dd6 mov A,0xffdf6
ram:016897 9efc mov CS,A
ram:016899 c0 pop AX
ram:01689a 61ea call DE
ram:01689c 1004 addw SP,0x4
ram:01689e d2 cmp0 C
ram:01689f 61f8 sknz
ram:0168a1 7130f4e6 _set1 !0xfe6f4.0x3
ram:0168a5 eece00 br $! 0x16976
ram:0168a8 7118ebe1 clr1 !0xfe1eb.0x1
ram:0168ac eec700 br $! 0x16976
ram:0168af ac4a movw AX,[HL + 0x4a]
ram:0168b1 14 movw DE,AX
ram:0168b2 89 mov A,[DE]
ram:0168b3 d1 cmp0 A
ram:0168b4 df06 bnz $ 0x168bc
ram:0168b6 7110eee1 set1 !0xfe1ee.0x1
ram:0168ba ef04 br $ 0x168c0
ram:0168bc 7118eee1 clr1 !0xfe1ee.0x1
ram:0168c0 30ece1 movw AX,0xe1ec
ram:0168c3 fcda5701 call !!0x157da
ram:0168c7 13 movw AX,BC
ram:0168c8 bf08e2 movw !0xfe208,AX
ram:0168cb af1ee4 movw AX,!0xfe41e
ram:0168ce 321e00 movw BC,0x1e
ram:0168d1 c3 push BC
ram:0168d2 34ece1 movw DE,0xe1ec
ram:0168d5 c5 push DE
ram:0168d6 14 movw DE,AX
ram:0168d7 8a12 mov A,[DE + 0x12]
ram:0168d9 9dd4 mov 0xffdf4,A
ram:0168db aa10 movw AX,[DE + 0x10]
ram:0168dd c1 push AX
ram:0168de 8dd4 mov A,0xffdf4
ram:0168e0 9dd6 mov 0xffdf6,A
ram:0168e2 c0 pop AX
ram:0168e3 14 movw DE,AX
ram:0168e4 f6 clrw AX
ram:0168e5 12 movw BC,AX
ram:0168e6 c1 push AX
ram:0168e7 8dd6 mov A,0xffdf6
ram:0168e9 9efc mov CS,A
ram:0168eb c0 pop AX
ram:0168ec 61ea call DE
ram:0168ee 1004 addw SP,0x4
ram:0168f0 d2 cmp0 C
ram:0168f1 61f8 sknz
ram:0168f3 7130f4e6 _set1 !0xfe6f4.0x3
ram:0168f7 ef7d br $ 0x16976
ram:0168f9 af00e4 movw AX,!0xfe400
ram:0168fc f7 clrw BC
ram:0168fd c3 push BC
ram:0168fe 14 movw DE,AX
ram:0168ff 8a1a mov A,[DE + 0x1a]
ram:016901 9efc mov CS,A
ram:016903 aa18 movw AX,[DE + 0x18]
ram:016905 14 movw DE,AX
ram:016906 300600 movw AX,0x6
ram:016909 61ea call DE
ram:01690b c0 pop AX
ram:01690c ef68 br $ 0x16976
ram:01690e c7 push HL
ram:01690f 17 movw AX,HL
ram:016910 042600 addw AX,0x26
ram:016913 16 movw HL,AX
ram:016914 f7 clrw BC
ram:016915 49ac4b mov A,!0xf4bac[BC]
ram:016918 9b mov [HL],A
ram:016919 a3 incw BC
ram:01691a a7 incw HL
ram:01691b 511c mov ,0x1c
ram:01691d 614a cmp A,
ram:01691f dff4 bnz $ 0x16915
ram:016921 c6 pop HL
ram:016922 db18e4 movw BC,!0xfe418
ram:016925 8c26 mov A,[HL + 0x26]
ram:016927 318e shrw AX,0x8
ram:016929 c1 push AX
ram:01692a 17 movw AX,HL
ram:01692b 042700 addw AX,0x27
ram:01692e c1 push AX
ram:01692f 491600 mov A,!0xf0016[BC]
ram:016932 9dd4 mov 0xffdf4,A
ram:016934 791400 movw AX,!0xf0014[BC]
ram:016937 c1 push AX
ram:016938 8dd4 mov A,0xffdf4
ram:01693a 9dd6 mov 0xffdf6,A
ram:01693c c0 pop AX
ram:01693d 14 movw DE,AX
ram:01693e f6 clrw AX
ram:01693f 12 movw BC,AX
ram:016940 c1 push AX
ram:016941 8dd6 mov A,0xffdf6
ram:016943 9efc mov CS,A
ram:016945 c0 pop AX
ram:016946 61ea call DE
ram:016948 1004 addw SP,0x4
ram:01694a db02e4 movw BC,!0xfe402
ram:01694d 17 movw AX,HL
ram:01694e 042600 addw AX,0x26
ram:016951 c1 push AX
ram:016952 491a00 mov A,!0xf001a[BC]
ram:016955 9efc mov CS,A
ram:016957 791800 movw AX,!0xf0018[BC]
ram:01695a 14 movw DE,AX
ram:01695b 306900 movw AX,0x69
ram:01695e 61ea call DE
ram:016960 c0 pop AX
ram:016961 ef13 br $ 0x16976
ram:016963 db18e4 movw BC,!0xfe418
ram:016966 ac4a movw AX,[HL + 0x4a]
ram:016968 c1 push AX
ram:016969 490e00 mov A,!0xf000e[BC]
ram:01696c 9efc mov CS,A
ram:01696e 790c00 movw AX,!0xf000c[BC]
ram:016971 14 movw DE,AX
ram:016972 f6 clrw AX
ram:016973 61ea call DE
ram:016975 c0 pop AX
ram:016976 e7 onew BC
ram:016977 1044 addw SP,0x44
ram:016979 c6 pop HL
ram:01697a d7 ret
ram:0172b7 c7 push HL
ram:0172b8 c1 push AX
ram:0172b9 fbf8ff movw HL,!0xffff8
ram:0172bc 8b mov A,[HL]
ram:0172bd 2c02 sub A,#0x2
ram:0172bf 2c02 sub A,#0x2
ram:0172c1 de11 bnc $ 0x172d4
ram:0172c3 af00e4 movw AX,!0xfe400
ram:0172c6 f7 clrw BC
ram:0172c7 c3 push BC
ram:0172c8 14 movw DE,AX
ram:0172c9 8a0e mov A,[DE + 0xe]
ram:0172cb 9efc mov CS,A
ram:0172cd aa0c movw AX,[DE + 0xc]
ram:0172cf 14 movw DE,AX
ram:0172d0 e6 onew AX
ram:0172d1 61ea call DE
ram:0172d3 c0 pop AX
ram:0172d4 40eae103 cmp !0xfe1ea,0x3
ram:0172d8 dd03 bz $ 0x172dd
ram:0172da f7 clrw BC
ram:0172db ef01 br $ 0x172de
ram:0172dd e7 onew BC
ram:0172de c0 pop AX
ram:0172df c6 pop HL
ram:0172e0 d7 ret
ram:018afd c7 push HL
ram:018afe c1 push AX
ram:018aff fbf8ff movw HL,!0xffff8
ram:018b02 8b mov A,[HL]
ram:018b03 4c41 cmp A,#0x41
ram:018b05 de21 bnc $ 0x18b28
ram:018b07 8b mov A,[HL]
ram:018b08 91 dec 
ram:018b09 f0 clrb X
ram:018b0a 316e shrw AX,0x6
ram:018b0c 042ce7 addw AX,0xe72c
ram:018b0f 12 movw BC,AX
ram:018b10 ac0a movw AX,[HL + 0xa]
ram:018b12 c1 push AX
ram:018b13 8c08 mov A,[HL + 0x8]
ram:018b15 318e shrw AX,0x8
ram:018b17 c1 push AX
ram:018b18 490200 mov A,!0xf0002[BC]
ram:018b1b 9efc mov CS,A
ram:018b1d 790000 movw AX,!0xf0000[BC]
ram:018b20 14 movw DE,AX
ram:018b21 8b mov A,[HL]
ram:018b22 318e shrw AX,0x8
ram:018b24 61ea call DE
ram:018b26 1004 addw SP,0x4
ram:018b28 c0 pop AX
ram:018b29 c6 pop HL
ram:018b2a d7 ret
ram:018b2b c7 push HL
ram:018b2c c1 push AX
ram:018b2d c1 push AX
ram:018b2e fbf8ff movw HL,!0xffff8
ram:018b31 401ae701 cmp !0xfe71a,0x1
ram:018b35 61e8 skz
ram:018b37 ee9200 _br $! 0x18bcc
ram:018b3a 8c02 mov A,[HL + 0x2]
ram:018b3c 2c04 sub A,#0x4
ram:018b3e dd39 bz $ 0x18b79
ram:018b40 2c03 sub A,#0x3
ram:018b42 dd1e bz $ 0x18b62
ram:018b44 91 dec 
ram:018b45 dd32 bz $ 0x18b79
ram:018b47 2c02 sub A,#0x2
ram:018b49 dd2e bz $ 0x18b79
ram:018b4b 91 dec 
ram:018b4c dd14 bz $ 0x18b62
ram:018b4e 91 dec 
ram:018b4f dd28 bz $ 0x18b79
ram:018b51 2c14 sub A,#0x14
ram:018b53 dd0d bz $ 0x18b62
ram:018b55 91 dec 
ram:018b56 2c03 sub A,#0x3
ram:018b58 dc1f bc $ 0x18b79
ram:018b5a d1 cmp0 A
ram:018b5b dd05 bz $ 0x18b62
ram:018b5d 91 dec 
ram:018b5e dd2e bz $ 0x18b8e
ram:018b60 ef6a br $ 0x18bcc
ram:018b62 8f1be7 mov A,!0xfe71b
ram:018b65 9b mov [HL],A
ram:018b66 cc0101 mov [HL + 0x1],0x1
ram:018b69 e6 onew AX
ram:018b6a a1 incw AX
ram:018b6b c1 push AX
ram:018b6c 17 movw AX,HL
ram:018b6d c1 push AX
ram:018b6e 308400 movw AX,0x84
ram:018b71 fc505501 call !!0x15550
ram:018b75 1004 addw SP,0x4
ram:018b77 ef53 br $ 0x18bcc
ram:018b79 af06e4 movw AX,!0xfe406
ram:018b7c f7 clrw BC
ram:018b7d c3 push BC
ram:018b7e 14 movw DE,AX
ram:018b7f 8a0e mov A,[DE + 0xe]
ram:018b81 9efc mov CS,A
ram:018b83 aa0c movw AX,[DE + 0xc]
ram:018b85 14 movw DE,AX
ram:018b86 308100 movw AX,0x81
ram:018b89 61ea call DE
ram:018b8b c0 pop AX
ram:018b8c ef3e br $ 0x18bcc
ram:018b8e f51ae7 clrb !0xfe71a
ram:018b91 af06e4 movw AX,!0xfe406
ram:018b94 f7 clrw BC
ram:018b95 c3 push BC
ram:018b96 14 movw DE,AX
ram:018b97 8a0e mov A,[DE + 0xe]
ram:018b99 9efc mov CS,A
ram:018b9b aa0c movw AX,[DE + 0xc]
ram:018b9d 14 movw DE,AX
ram:018b9e 308100 movw AX,0x81
ram:018ba1 61ea call DE
ram:018ba3 c0 pop AX
ram:018ba4 af06e4 movw AX,!0xfe406
ram:018ba7 f7 clrw BC
ram:018ba8 c3 push BC
ram:018ba9 14 movw DE,AX
ram:018baa 8a0e mov A,[DE + 0xe]
ram:018bac 9efc mov CS,A
ram:018bae aa0c movw AX,[DE + 0xc]
ram:018bb0 14 movw DE,AX
ram:018bb1 308300 movw AX,0x83
ram:018bb4 61ea call DE
ram:018bb6 c0 pop AX
ram:018bb7 8f1be7 mov A,!0xfe71b
ram:018bba 9b mov [HL],A
ram:018bbb cc0101 mov [HL + 0x1],0x1
ram:018bbe e6 onew AX
ram:018bbf a1 incw AX
ram:018bc0 c1 push AX
ram:018bc1 17 movw AX,HL
ram:018bc2 c1 push AX
ram:018bc3 308400 movw AX,0x84
ram:018bc6 fc505501 call !!0x15550
ram:018bca 1004 addw SP,0x4
ram:018bcc 1004 addw SP,0x4
ram:018bce c6 pop HL
ram:018bcf d7 ret
ram:018bd0 c7 push HL
ram:018bd1 c1 push AX
ram:018bd2 c1 push AX
ram:018bd3 fbf8ff movw HL,!0xffff8
ram:018bd6 31540506 bf 0xffe25.0x5,$ 0x18bde
ram:018bda f535e8 clrb !0xfe835
ram:018bdd f7 clrw BC
ram:018bde ef35 br $ 0x18c15
ram:018be0 4103 mov ES,0x3
ram:018be2 118f00f4 mov A,ES:!0xff400
ram:018be6 9c01 mov [HL + 0x1],A
ram:018be8 81 inc 
ram:018be9 df15 bnz $ 0x18c00
ram:018beb ac02 movw AX,[HL + 0x2]
ram:018bed 14 movw DE,AX
ram:018bee aa04 movw AX,[DE + 0x4]
ram:018bf0 a1 incw AX
ram:018bf1 ba04 movw [DE + 0x4],AX
ram:018bf3 ac02 movw AX,[HL + 0x2]
ram:018bf5 14 movw DE,AX
ram:018bf6 aa04 movw AX,[DE + 0x4]
ram:018bf8 440600 cmpw AX,0x6
ram:018bfb de03 bnc $ 0x18c00
ram:018bfd e7 onew BC
ram:018bfe ef15 br $ 0x18c15
ram:018c00 af00e4 movw AX,!0xfe400
ram:018c03 f7 clrw BC
ram:018c04 c3 push BC
ram:018c05 14 movw DE,AX
ram:018c06 8a0e mov A,[DE + 0xe]
ram:018c08 9efc mov CS,A
ram:018c0a aa0c movw AX,[DE + 0xc]
ram:018c0c 14 movw DE,AX
ram:018c0d e6 onew AX
ram:018c0e 61ea call DE
ram:018c10 c0 pop AX
ram:018c11 f535e8 clrb !0xfe835
ram:018c14 f7 clrw BC
ram:018c15 1004 addw SP,0x4
ram:018c17 c6 pop HL
ram:018c18 d7 ret
ram:018d9e c7 push HL
ram:018d9f 16 movw HL,AX
ram:018da0 eb12e4 movw DE,!0xfe412
ram:018da3 8a02 mov A,[DE + 0x2]
ram:018da5 9efc mov CS,A
ram:018da7 a9 movw AX,[DE]
ram:018da8 14 movw DE,AX
ram:018da9 f6 clrw AX
ram:018daa 61ea call DE
ram:018dac 714305 clr1 0xffe25.0x4
ram:018daf 710301 clr1 0xffe21.0x0
ram:018db2 711301 clr1 0xffe21.0x1
ram:018db5 f6 clrw AX
ram:018db6 fc887a00 call !!0x7a88
ram:018dba f52ce8 clrb !0xfe82c
ram:018dbd f7 clrw BC
ram:018dbe c6 pop HL
ram:018dbf d7 ret
ram:018dc0 c7 push HL
ram:018dc1 16 movw HL,AX
ram:018dc2 17 movw AX,HL
ram:018dc3 14 movw DE,AX
ram:018dc4 aa04 movw AX,[DE + 0x4]
ram:018dc6 a1 incw AX
ram:018dc7 ba04 movw [DE + 0x4],AX
ram:018dc9 441e00 cmpw AX,0x1e
ram:018dcc dc3d bc $ 0x18e0b
ram:018dce 30a88c movw AX,0x8ca8
ram:018dd1 5201 mov ,0x1
ram:018dd3 f3 clrb B
ram:018dd4 fc057e00 call !!0x7e05
ram:018dd8 308813 movw AX,0x1388
ram:018ddb c1 push AX
ram:018ddc 309e8d movw AX,0x8d9e
ram:018ddf 5201 mov ,0x1
ram:018de1 f3 clrb B
ram:018de2 fcea7d00 call !!0x7dea
ram:018de6 c0 pop AX
ram:018de7 307017 movw AX,0x1770
ram:018dea c1 push AX
ram:018deb 309e8d movw AX,0x8d9e
ram:018dee 5201 mov ,0x1
ram:018df0 f3 clrb B
ram:018df1 fcea7d00 call !!0x7dea
ram:018df5 c0 pop AX
ram:018df6 30581b movw AX,0x1b58
ram:018df9 c1 push AX
ram:018dfa 309e8d movw AX,0x8d9e
ram:018dfd 5201 mov ,0x1
ram:018dff f3 clrb B
ram:018e00 fcea7d00 call !!0x7dea
ram:018e04 c0 pop AX
ram:018e05 f532e8 clrb !0xfe832
ram:018e08 f7 clrw BC
ram:018e09 ef01 br $ 0x18e0c
ram:018e0b e7 onew BC
ram:018e0c c6 pop HL
ram:018e0d d7 ret
ram:018e0e c7 push HL
ram:018e0f 2004 subw SP,0x4
ram:018e11 fbf8ff movw HL,!0xffff8
ram:018e14 402ce803 cmp !0xfe82c,0x3
ram:018e18 61e8 skz
ram:018e1a ee3e01 _br $! 0x18f5b
ram:018e1d 8f2fe8 mov A,!0xfe82f
ram:018e20 3129 shl A,0x2
ram:018e22 316a shr A,0x6
ram:018e24 9c02 mov [HL + 0x2],A
ram:018e26 d1 cmp0 A
ram:018e27 61e8 skz
ram:018e29 eeab00 _br $! 0x18ed7
ram:018e2c 8f2fe8 mov A,!0xfe82f
ram:018e2f 31130c bt A.0x1,$ 0x18e3d
ram:018e32 312309 bt A.0x2,$ 0x18e3d
ram:018e35 313306 bt A.0x3,$ 0x18e3d
ram:018e38 8f30e8 mov A,!0xfe830
ram:018e3b 31752b bf A.0x7,$ 0x18e68
ram:018e3e cc0301 mov [HL + 0x3],0x1
ram:018e41 8f2fe8 mov A,!0xfe82f
ram:018e44 311510 bf A.0x1,$ 0x18e56
ram:018e47 d533e8 cmp0 !0xfe833
ram:018e4a dd0b bz $ 0x18e57
ram:018e4c d933e8 mov X,!0xfe833
ram:018e4f f1 clrb A
ram:018e50 fc927e00 call !!0x7e92
ram:018e54 f533e8 clrb !0xfe833
ram:018e57 d532e8 cmp0 !0xfe832
ram:018e5a dd64 bz $ 0x18ec0
ram:018e5c d932e8 mov X,!0xfe832
ram:018e5f f1 clrb A
ram:018e60 fc927e00 call !!0x7e92
ram:018e64 f532e8 clrb !0xfe832
ram:018e67 ef57 br $ 0x18ec0
ram:018e69 cc0302 mov [HL + 0x3],0x2
ram:018e6c d532e8 cmp0 !0xfe832
ram:018e6f df4f bnz $ 0x18ec0
ram:018e71 eb0ee4 movw DE,!0xfe40e
ram:018e74 8a06 mov A,[DE + 0x6]
ram:018e76 9efc mov CS,A
ram:018e78 aa04 movw AX,[DE + 0x4]
ram:018e7a 14 movw DE,AX
ram:018e7b f6 clrw AX
ram:018e7c 61ea call DE
ram:018e7e eb0ce4 movw DE,!0xfe40c
ram:018e81 8a06 mov A,[DE + 0x6]
ram:018e83 9efc mov CS,A
ram:018e85 aa04 movw AX,[DE + 0x4]
ram:018e87 14 movw DE,AX
ram:018e88 f6 clrw AX
ram:018e89 61ea call DE
ram:018e8b 8f2fe8 mov A,!0xfe82f
ram:018e8e 31051a bf A.0x0,$ 0x18eaa
ram:018e91 71082fe8 clr1 !0xfe82f.0x0
ram:018e95 d533e8 cmp0 !0xfe833
ram:018e98 dd0b bz $ 0x18ea5
ram:018e9a d933e8 mov X,!0xfe833
ram:018e9d f1 clrb A
ram:018e9e fc927e00 call !!0x7e92
ram:018ea2 f533e8 clrb !0xfe833
ram:018ea5 30d007 movw AX,0x7d0
ram:018ea8 bb movw [HL],AX
ram:018ea9 ef04 br $ 0x18eaf
ram:018eab 301027 movw AX,0x2710
ram:018eae bb movw [HL],AX
ram:018eaf ab movw AX,[HL]
ram:018eb0 c1 push AX
ram:018eb1 30c08d movw AX,0x8dc0
ram:018eb4 5201 mov ,0x1
ram:018eb6 f3 clrb B
ram:018eb7 fcea7d00 call !!0x7dea
ram:018ebb c0 pop AX
ram:018ebc 62 mov A,
ram:018ebd 9f32e8 mov !0xfe832,A
ram:018ec0 af02e4 movw AX,!0xfe402
ram:018ec3 f7 clrw BC
ram:018ec4 c3 push BC
ram:018ec5 14 movw DE,AX
ram:018ec6 8a1a mov A,[DE + 0x1a]
ram:018ec8 9efc mov CS,A
ram:018eca aa18 movw AX,[DE + 0x18]
ram:018ecc 14 movw DE,AX
ram:018ecd 8c03 mov A,[HL + 0x3]
ram:018ecf 318e shrw AX,0x8
ram:018ed1 61ea call DE
ram:018ed3 c0 pop AX
ram:018ed4 ee8400 br $! 0x18f5b
ram:018ed7 eb0ee4 movw DE,!0xfe40e
ram:018eda 8a06 mov A,[DE + 0x6]
ram:018edc 9efc mov CS,A
ram:018ede aa04 movw AX,[DE + 0x4]
ram:018ee0 14 movw DE,AX
ram:018ee1 f6 clrw AX
ram:018ee2 61ea call DE
ram:018ee4 eb0ce4 movw DE,!0xfe40c
ram:018ee7 8a06 mov A,[DE + 0x6]
ram:018ee9 9efc mov CS,A
ram:018eeb aa04 movw AX,[DE + 0x4]
ram:018eed 14 movw DE,AX
ram:018eee f6 clrw AX
ram:018eef 61ea call DE
ram:018ef1 8c02 mov A,[HL + 0x2]
ram:018ef3 91 dec 
ram:018ef4 df28 bnz $ 0x18f1e
ram:018ef6 30e803 movw AX,0x3e8
ram:018ef9 c1 push AX
ram:018efa 30c08d movw AX,0x8dc0
ram:018efd 5201 mov ,0x1
ram:018eff f3 clrb B
ram:018f00 fcea7d00 call !!0x7dea
ram:018f04 c0 pop AX
ram:018f05 62 mov A,
ram:018f06 9f32e8 mov !0xfe832,A
ram:018f09 af02e4 movw AX,!0xfe402
ram:018f0c f7 clrw BC
ram:018f0d c3 push BC
ram:018f0e 14 movw DE,AX
ram:018f0f 8a1a mov A,[DE + 0x1a]
ram:018f11 9efc mov CS,A
ram:018f13 aa18 movw AX,[DE + 0x18]
ram:018f15 14 movw DE,AX
ram:018f16 300300 movw AX,0x3
ram:018f19 61ea call DE
ram:018f1b c0 pop AX
ram:018f1c ef3d br $ 0x18f5b
ram:018f1e 8c02 mov A,[HL + 0x2]
ram:018f20 4c02 cmp A,#0x2
ram:018f22 df37 bnz $ 0x18f5b
ram:018f24 30a88c movw AX,0x8ca8
ram:018f27 5201 mov ,0x1
ram:018f29 f3 clrb B
ram:018f2a fc057e00 call !!0x7e05
ram:018f2e 308813 movw AX,0x1388
ram:018f31 c1 push AX
ram:018f32 309e8d movw AX,0x8d9e
ram:018f35 5201 mov ,0x1
ram:018f37 f3 clrb B
ram:018f38 fcea7d00 call !!0x7dea
ram:018f3c c0 pop AX
ram:018f3d 307017 movw AX,0x1770
ram:018f40 c1 push AX
ram:018f41 309e8d movw AX,0x8d9e
ram:018f44 5201 mov ,0x1
ram:018f46 f3 clrb B
ram:018f47 fcea7d00 call !!0x7dea
ram:018f4b c0 pop AX
ram:018f4c 30581b movw AX,0x1b58
ram:018f4f c1 push AX
ram:018f50 309e8d movw AX,0x8d9e
ram:018f53 5201 mov ,0x1
ram:018f55 f3 clrb B
ram:018f56 fcea7d00 call !!0x7dea
ram:018f5a c0 pop AX
ram:018f5b 1004 addw SP,0x4
ram:018f5d c6 pop HL
ram:018f5e d7 ret
ram:018f9a c7 push HL
ram:018f9b 16 movw HL,AX
ram:018f9c 17 movw AX,HL
ram:018f9d 14 movw DE,AX
ram:018f9e aa04 movw AX,[DE + 0x4]
ram:018fa0 a1 incw AX
ram:018fa1 ba04 movw [DE + 0x4],AX
ram:018fa3 441f00 cmpw AX,0x1f
ram:018fa6 dc1f bc $ 0x18fc7
ram:018fa8 8f30e8 mov A,!0xfe830
ram:018fab 317319 bt A.0x7,$ 0x18fc6
ram:018fae 71082fe8 clr1 !0xfe82f.0x0
ram:018fb2 71382fe8 clr1 !0xfe82f.0x3
ram:018fb6 342fe8 movw DE,0xe82f
ram:018fb9 89 mov A,[DE]
ram:018fba 5ccf and A,#0xcf
ram:018fbc 99 mov [DE],A
ram:018fbd fc0e8e01 call !!0x18e0e
ram:018fc1 f533e8 clrb !0xfe833
ram:018fc4 f7 clrw BC
ram:018fc5 ef01 br $ 0x18fc8
ram:018fc7 e7 onew BC
ram:018fc8 c6 pop HL
ram:018fc9 d7 ret
ram:018fca c7 push HL
ram:018fcb c1 push AX
ram:018fcc 2004 subw SP,0x4
ram:018fce fbf8ff movw HL,!0xffff8
ram:018fd1 cc0301 mov [HL + 0x3],0x1
ram:018fd4 ac04 movw AX,[HL + 0x4]
ram:018fd6 14 movw DE,AX
ram:018fd7 aa04 movw AX,[DE + 0x4]
ram:018fd9 e7 onew BC
ram:018fda 240000 subw AX,0x0
ram:018fdd dd12 bz $ 0x18ff1
ram:018fdf 23 subw AX,BC
ram:018fe0 dd27 bz $ 0x19009
ram:018fe2 23 subw AX,BC
ram:018fe3 61f8 sknz
ram:018fe5 ee9400 _br $! 0x1907c
ram:018fe8 23 subw AX,BC
ram:018fe9 61f8 sknz
ram:018feb eeb600 _br $! 0x190a4
ram:018fee eecf00 br $! 0x190c0
ram:018ff1 e6 onew AX
ram:018ff2 fc887a00 call !!0x7a88
ram:018ff6 ac04 movw AX,[HL + 0x4]
ram:018ff8 14 movw DE,AX
ram:018ff9 aa04 movw AX,[DE + 0x4]
ram:018ffb a1 incw AX
ram:018ffc ba04 movw [DE + 0x4],AX
ram:018ffe ac04 movw AX,[HL + 0x4]
ram:019000 14 movw DE,AX
ram:019001 301e00 movw AX,0x1e
ram:019004 ba06 movw [DE + 0x6],AX
ram:019006 eeb700 br $! 0x190c0
ram:019009 af12e4 movw AX,!0xfe412
ram:01900c e7 onew BC
ram:01900d a3 incw BC
ram:01900e c3 push BC
ram:01900f 12 movw BC,AX
ram:019010 17 movw AX,HL
ram:019011 a1 incw AX
ram:019012 c1 push AX
ram:019013 491600 mov A,!0xf0016[BC]
ram:019016 9dd4 mov 0xffdf4,A
ram:019018 791400 movw AX,!0xf0014[BC]
ram:01901b c1 push AX
ram:01901c 8dd4 mov A,0xffdf4
ram:01901e 9dd6 mov 0xffdf6,A
ram:019020 c0 pop AX
ram:019021 14 movw DE,AX
ram:019022 301000 movw AX,0x10
ram:019025 f7 clrw BC
ram:019026 c1 push AX
ram:019027 8dd6 mov A,0xffdf6
ram:019029 9efc mov CS,A
ram:01902b c0 pop AX
ram:01902c 61ea call DE
ram:01902e 1004 addw SP,0x4
ram:019030 8c02 mov A,[HL + 0x2]
ram:019032 d1 cmp0 A
ram:019033 dd06 bz $ 0x1903b
ram:019035 8c02 mov A,[HL + 0x2]
ram:019037 4c07 cmp A,#0x7
ram:019039 dc07 bc $ 0x19042
ram:01903b f52ce8 clrb !0xfe82c
ram:01903e f7 clrw BC
ram:01903f ee8300 br $! 0x190c5
ram:019042 cc0001 mov [HL + 0x0],0x1
ram:019045 af12e4 movw AX,!0xfe412
ram:019048 e7 onew BC
ram:019049 c3 push BC
ram:01904a 12 movw BC,AX
ram:01904b 17 movw AX,HL
ram:01904c c1 push AX
ram:01904d 491200 mov A,!0xf0012[BC]
ram:019050 9dd4 mov 0xffdf4,A
ram:019052 791000 movw AX,!0xf0010[BC]
ram:019055 c1 push AX
ram:019056 8dd4 mov A,0xffdf4
ram:019058 9dd6 mov 0xffdf6,A
ram:01905a c0 pop AX
ram:01905b 14 movw DE,AX
ram:01905c 304400 movw AX,0x44
ram:01905f f7 clrw BC
ram:019060 c1 push AX
ram:019061 8dd6 mov A,0xffdf6
ram:019063 9efc mov CS,A
ram:019065 c0 pop AX
ram:019066 61ea call DE
ram:019068 1004 addw SP,0x4
ram:01906a ac04 movw AX,[HL + 0x4]
ram:01906c 14 movw DE,AX
ram:01906d aa04 movw AX,[DE + 0x4]
ram:01906f a1 incw AX
ram:019070 ba04 movw [DE + 0x4],AX
ram:019072 ac04 movw AX,[HL + 0x4]
ram:019074 14 movw DE,AX
ram:019075 302800 movw AX,0x28
ram:019078 ba06 movw [DE + 0x6],AX
ram:01907a ef44 br $ 0x190c0
ram:01907c 30198c movw AX,0x8c19
ram:01907f 5201 mov ,0x1
ram:019081 f3 clrb B
ram:019082 fc057e00 call !!0x7e05
ram:019086 eb02e4 movw DE,!0xfe402
ram:019089 8a02 mov A,[DE + 0x2]
ram:01908b 9efc mov CS,A
ram:01908d a9 movw AX,[DE]
ram:01908e 14 movw DE,AX
ram:01908f e6 onew AX
ram:019090 61ea call DE
ram:019092 ac04 movw AX,[HL + 0x4]
ram:019094 14 movw DE,AX
ram:019095 aa04 movw AX,[DE + 0x4]
ram:019097 a1 incw AX
ram:019098 ba04 movw [DE + 0x4],AX
ram:01909a ac04 movw AX,[HL + 0x4]
ram:01909c 14 movw DE,AX
ram:01909d 300a00 movw AX,0xa
ram:0190a0 ba06 movw [DE + 0x6],AX
ram:0190a2 ef1c br $ 0x190c0
ram:0190a4 eb02e4 movw DE,!0xfe402
ram:0190a7 8a0a mov A,[DE + 0xa]
ram:0190a9 9efc mov CS,A
ram:0190ab aa08 movw AX,[DE + 0x8]
ram:0190ad 61ca call AX
ram:0190af 92 dec 
ram:0190b0 dd0e bz $ 0x190c0
ram:0190b2 e52de8 oneb !0xfe82d
ram:0190b5 cf2ce803 mov !0xfe82c,0x3
ram:0190b9 fc0e8e01 call !!0x18e0e
ram:0190bd cc0300 mov [HL + 0x3],0x0
ram:0190c0 8c03 mov A,[HL + 0x3]
ram:0190c2 318e shrw AX,0x8
ram:0190c4 12 movw BC,AX
ram:0190c5 1006 addw SP,0x6
ram:0190c7 c6 pop HL
ram:0190c8 d7 ret
ram:0190c9 c7 push HL
ram:0190ca c1 push AX
ram:0190cb c1 push AX
ram:0190cc fbf8ff movw HL,!0xffff8
ram:0190cf 306400 movw AX,0x64
ram:0190d2 bb movw [HL],AX
ram:0190d3 8c02 mov A,[HL + 0x2]
ram:0190d5 91 dec 
ram:0190d6 61e8 skz
ram:0190d8 eea900 _br $! 0x19184
ram:0190db e52ce8 oneb !0xfe82c
ram:0190de f52de8 clrb !0xfe82d
ram:0190e1 f532e8 clrb !0xfe832
ram:0190e4 71182fe8 clr1 !0xfe82f.0x1
ram:0190e8 71282fe8 clr1 !0xfe82f.0x2
ram:0190ec 342fe8 movw DE,0xe82f
ram:0190ef 89 mov A,[DE]
ram:0190f0 5ccf and A,#0xcf
ram:0190f2 99 mov [DE],A
ram:0190f3 a5 incw DE
ram:0190f4 89 mov A,[DE]
ram:0190f5 5ccf and A,#0xcf
ram:0190f7 99 mov [DE],A
ram:0190f8 716030e8 set1 !0xfe830.0x6
ram:0190fc e52ee8 oneb !0xfe82e
ram:0190ff 717830e8 clr1 !0xfe830.0x7
ram:019103 31020303 bt 0xffe23.0x0,$ 0x19108
ram:019107 e1 oneb A
ram:019108 ef01 br $ 0x1910b
ram:01910a f1 clrb A
ram:01910b d1 cmp0 A
ram:01910c df1d bnz $ 0x1912b
ram:01910e 71002fe8 set1 !0xfe82f.0x0
ram:019112 71302fe8 set1 !0xfe82f.0x3
ram:019116 30409c movw AX,0x9c40
ram:019119 c1 push AX
ram:01911a 309a8f movw AX,0x8f9a
ram:01911d 5201 mov ,0x1
ram:01911f f3 clrb B
ram:019120 fcea7d00 call !!0x7dea
ram:019124 c0 pop AX
ram:019125 62 mov A,
ram:019126 9f33e8 mov !0xfe833,A
ram:019129 ef08 br $ 0x19133
ram:01912b 71082fe8 clr1 !0xfe82f.0x0
ram:01912f 71382fe8 clr1 !0xfe82f.0x3
ram:019133 716b24 clr1 0xfff24.0x6
ram:019136 715b24 clr1 0xfff24.0x5
ram:019139 716204 set1 0xffe24.0x6
ram:01913c 715304 clr1 0xffe24.0x5
ram:01913f 303075 movw AX,0x7530
ram:019142 c1 push AX
ram:019143 30d08b movw AX,0x8bd0
ram:019146 5201 mov ,0x1
ram:019148 f3 clrb B
ram:019149 fcea7d00 call !!0x7dea
ram:01914d c0 pop AX
ram:01914e 62 mov A,
ram:01914f 9f35e8 mov !0xfe835,A
ram:019152 4103 mov ES,0x3
ram:019154 114000f4ff cmp ES:!0xff400,0xff
ram:019159 61f8 sknz
ram:01915b 717030e8 _set1 !0xfe830.0x7
ram:01915f eb12e4 movw DE,!0xfe412
ram:019162 8a02 mov A,[DE + 0x2]
ram:019164 9efc mov CS,A
ram:019166 a9 movw AX,[DE]
ram:019167 14 movw DE,AX
ram:019168 e6 onew AX
ram:019169 61ea call DE
ram:01916b fc3e7c00 call !!0x7c3e
ram:01916f d2 cmp0 C
ram:019170 dd05 bz $ 0x19177
ram:019172 ab movw AX,[HL]
ram:019173 049001 addw AX,0x190
ram:019176 bb movw [HL],AX
ram:019177 ab movw AX,[HL]
ram:019178 c1 push AX
ram:019179 30ca8f movw AX,0x8fca
ram:01917c 5201 mov ,0x1
ram:01917e f3 clrb B
ram:01917f fcea7d00 call !!0x7dea
ram:019183 c0 pop AX
ram:019184 1004 addw SP,0x4
ram:019186 c6 pop HL
ram:019187 d7 ret
ram:01918c 8f2ce8 mov A,!0xfe82c
ram:01918f 318f sarw AX,0x8
ram:019191 12 movw BC,AX
ram:019192 d7 ret
ram:019193 c7 push HL
ram:019194 c1 push AX
ram:019195 fbf8ff movw HL,!0xffff8
ram:019198 8b mov A,[HL]
ram:019199 91 dec 
ram:01919a dd1e bz $ 0x191ba
ram:01919c 2c0f sub A,#0xf
ram:01919e dd64 bz $ 0x19204
ram:0191a0 91 dec 
ram:0191a1 61f8 sknz
ram:0191a3 ee9600 _br $! 0x1923c
ram:0191a6 2c0f sub A,#0xf
ram:0191a8 61f8 sknz
ram:0191aa eea800 _br $! 0x19255
ram:0191ad 2c60 sub A,#0x60
ram:0191af dd42 bz $ 0x191f3
ram:0191b1 91 dec 
ram:0191b2 dd44 bz $ 0x191f8
ram:0191b4 91 dec 
ram:0191b5 dd47 bz $ 0x191fe
ram:0191b7 eeab00 br $! 0x19265
ram:0191ba 30a88c movw AX,0x8ca8
ram:0191bd 5201 mov ,0x1
ram:0191bf f3 clrb B
ram:0191c0 fc057e00 call !!0x7e05
ram:0191c4 301027 movw AX,0x2710
ram:0191c7 c1 push AX
ram:0191c8 309e8d movw AX,0x8d9e
ram:0191cb 5201 mov ,0x1
ram:0191cd f3 clrb B
ram:0191ce fcea7d00 call !!0x7dea
ram:0191d2 c0 pop AX
ram:0191d3 30e02e movw AX,0x2ee0
ram:0191d6 c1 push AX
ram:0191d7 309e8d movw AX,0x8d9e
ram:0191da 5201 mov ,0x1
ram:0191dc f3 clrb B
ram:0191dd fcea7d00 call !!0x7dea
ram:0191e1 c0 pop AX
ram:0191e2 30b036 movw AX,0x36b0
ram:0191e5 c1 push AX
ram:0191e6 309e8d movw AX,0x8d9e
ram:0191e9 5201 mov ,0x1
ram:0191eb f3 clrb B
ram:0191ec fcea7d00 call !!0x7dea
ram:0191f0 c0 pop AX
ram:0191f1 ef72 br $ 0x19265
ram:0191f3 e52de8 oneb !0xfe82d
ram:0191f6 ef6d br $ 0x19265
ram:0191f8 cf2de802 mov !0xfe82d,0x2
ram:0191fc ef67 br $ 0x19265
ram:0191fe cf2de803 mov !0xfe82d,0x3
ram:019202 ef61 br $ 0x19265
ram:019204 d532e8 cmp0 !0xfe832
ram:019207 df1a bnz $ 0x19223
ram:019209 eb0ee4 movw DE,!0xfe40e
ram:01920c 8a06 mov A,[DE + 0x6]
ram:01920e 9efc mov CS,A
ram:019210 aa04 movw AX,[DE + 0x4]
ram:019212 14 movw DE,AX
ram:019213 e6 onew AX
ram:019214 61ea call DE
ram:019216 eb0ce4 movw DE,!0xfe40c
ram:019219 8a06 mov A,[DE + 0x6]
ram:01921b 9efc mov CS,A
ram:01921d aa04 movw AX,[DE + 0x4]
ram:01921f 14 movw DE,AX
ram:019220 e6 onew AX
ram:019221 61ea call DE
ram:019223 8f30e8 mov A,!0xfe830
ram:019226 3129 shl A,0x2
ram:019228 316a shr A,0x6
ram:01922a 5cfd and A,#0xfd
ram:01922c 3149 shl A,0x4
ram:01922e 5c30 and A,#0x30
ram:019230 3430e8 movw DE,0xe830
ram:019233 70 mov ,A
ram:019234 89 mov A,[DE]
ram:019235 5ccf and A,#0xcf
ram:019237 6168 or A,
ram:019239 99 mov [DE],A
ram:01923a ef29 br $ 0x19265
ram:01923c 8f30e8 mov A,!0xfe830
ram:01923f 3129 shl A,0x2
ram:019241 316a shr A,0x6
ram:019243 5cfd and A,#0xfd
ram:019245 3149 shl A,0x4
ram:019247 5c30 and A,#0x30
ram:019249 3430e8 movw DE,0xe830
ram:01924c 70 mov ,A
ram:01924d 89 mov A,[DE]
ram:01924e 5ccf and A,#0xcf
ram:019250 6168 or A,
ram:019252 99 mov [DE],A
ram:019253 ef10 br $ 0x19265
ram:019255 716830e8 clr1 !0xfe830.0x6
ram:019259 eb10e4 movw DE,!0xfe410
ram:01925c 8a02 mov A,[DE + 0x2]
ram:01925e 9efc mov CS,A
ram:019260 a9 movw AX,[DE]
ram:019261 14 movw DE,AX
ram:019262 f6 clrw AX
ram:019263 61ea call DE
ram:019265 e7 onew BC
ram:019266 c0 pop AX
ram:019267 c6 pop HL
ram:019268 d7 ret
ram:019474 c7 push HL
ram:019475 c1 push AX
ram:019476 2006 subw SP,0x6
ram:019478 fbf8ff movw HL,!0xffff8
ram:01947b 8c06 mov A,[HL + 0x6]
ram:01947d d1 cmp0 A
ram:01947e dd27 bz $ 0x194a7
ram:019480 91 dec 
ram:019481 61f8 sknz
ram:019483 eed400 _br $! 0x1955a
ram:019486 91 dec 
ram:019487 61f8 sknz
ram:019489 ee3201 _br $! 0x195be
ram:01948c 91 dec 
ram:01948d 61f8 sknz
ram:01948f eeb501 _br $! 0x19647
ram:019492 91 dec 
ram:019493 61f8 sknz
ram:019495 eedf00 _br $! 0x19577
ram:019498 91 dec 
ram:019499 61f8 sknz
ram:01949b eed600 _br $! 0x19574
ram:01949e 91 dec 
ram:01949f 61f8 sknz
ram:0194a1 eec001 _br $! 0x19664
ram:0194a4 eefd01 br $! 0x196a4
ram:0194a7 8f2fe8 mov A,!0xfe82f
ram:0194aa 311317 bt A.0x1,$ 0x194c3
ram:0194ad 310514 bf A.0x0,$ 0x194c3
ram:0194b0 313306 bt A.0x3,$ 0x194b8
ram:0194b3 71302fe8 set1 !0xfe82f.0x3
ram:0194b7 ef04 br $ 0x194bd
ram:0194b9 71382fe8 clr1 !0xfe82f.0x3
ram:0194bd fc0e8e01 call !!0x18e0e
ram:0194c1 ee9300 br $! 0x19557
ram:0194c4 8f2fe8 mov A,!0xfe82f
ram:0194c7 311329 bt A.0x1,$ 0x194f2
ram:0194ca 310326 bt A.0x0,$ 0x194f2
ram:0194cd 71002fe8 set1 !0xfe82f.0x0
ram:0194d1 71302fe8 set1 !0xfe82f.0x3
ram:0194d5 fc0e8e01 call !!0x18e0e
ram:0194d9 d533e8 cmp0 !0xfe833
ram:0194dc df79 bnz $ 0x19557
ram:0194de 30409c movw AX,0x9c40
ram:0194e1 c1 push AX
ram:0194e2 309a8f movw AX,0x8f9a
ram:0194e5 5201 mov ,0x1
ram:0194e7 f3 clrb B
ram:0194e8 fcea7d00 call !!0x7dea
ram:0194ec c0 pop AX
ram:0194ed 62 mov A,
ram:0194ee 9f33e8 mov !0xfe833,A
ram:0194f1 ef64 br $ 0x19557
ram:0194f3 8f2fe8 mov A,!0xfe82f
ram:0194f6 31155e bf A.0x1,$ 0x19556
ram:0194f9 af02e4 movw AX,!0xfe402
ram:0194fc e7 onew BC
ram:0194fd a3 incw BC
ram:0194fe c3 push BC
ram:0194ff 12 movw BC,AX
ram:019500 17 movw AX,HL
ram:019501 040200 addw AX,0x2
ram:019504 c1 push AX
ram:019505 491600 mov A,!0xf0016[BC]
ram:019508 9dd4 mov 0xffdf4,A
ram:01950a 791400 movw AX,!0xf0014[BC]
ram:01950d c1 push AX
ram:01950e 8dd4 mov A,0xffdf4
ram:019510 9dd6 mov 0xffdf6,A
ram:019512 c0 pop AX
ram:019513 14 movw DE,AX
ram:019514 e6 onew AX
ram:019515 f7 clrw BC
ram:019516 c1 push AX
ram:019517 8dd6 mov A,0xffdf6
ram:019519 9efc mov CS,A
ram:01951b c0 pop AX
ram:01951c 61ea call DE
ram:01951e 1004 addw SP,0x4
ram:019520 8c02 mov A,[HL + 0x2]
ram:019522 3139 shl A,0x3
ram:019524 317a shr A,0x7
ram:019526 7c01 xor A,#0x1
ram:019528 718c mov1 CY,A.0x0
ram:01952a 8c02 mov A,[HL + 0x2]
ram:01952c 71c9 mov1 A.0x4,CY
ram:01952e 9c02 mov [HL + 0x2],A
ram:019530 af02e4 movw AX,!0xfe402
ram:019533 e7 onew BC
ram:019534 a3 incw BC
ram:019535 c3 push BC
ram:019536 12 movw BC,AX
ram:019537 17 movw AX,HL
ram:019538 040200 addw AX,0x2
ram:01953b c1 push AX
ram:01953c 491200 mov A,!0xf0012[BC]
ram:01953f 9dd4 mov 0xffdf4,A
ram:019541 791000 movw AX,!0xf0010[BC]
ram:019544 c1 push AX
ram:019545 8dd4 mov A,0xffdf4
ram:019547 9dd6 mov 0xffdf6,A
ram:019549 c0 pop AX
ram:01954a 14 movw DE,AX
ram:01954b e6 onew AX
ram:01954c f7 clrw BC
ram:01954d c1 push AX
ram:01954e 8dd6 mov A,0xffdf6
ram:019550 9efc mov CS,A
ram:019552 c0 pop AX
ram:019553 61ea call DE
ram:019555 1004 addw SP,0x4
ram:019557 ee4a01 br $! 0x196a4
ram:01955a 8f2fe8 mov A,!0xfe82f
ram:01955d 310511 bf A.0x0,$ 0x19570
ram:019560 313306 bt A.0x3,$ 0x19568
ram:019563 71302fe8 set1 !0xfe82f.0x3
ram:019567 ef04 br $ 0x1956d
ram:019569 71382fe8 clr1 !0xfe82f.0x3
ram:01956d fc0e8e01 call !!0x18e0e
ram:019571 ee3001 br $! 0x196a4
ram:019574 ee2d01 br $! 0x196a4
ram:019577 ac0e movw AX,[HL + 0xe]
ram:019579 14 movw DE,AX
ram:01957a 89 mov A,[DE]
ram:01957b d1 cmp0 A
ram:01957c dd0c bz $ 0x1958a
ram:01957e 91 dec 
ram:01957f dd3a bz $ 0x195bb
ram:019581 2c04 sub A,#0x4
ram:019583 2c02 sub A,#0x2
ram:019585 dc18 bc $ 0x1959f
ram:019587 d1 cmp0 A
ram:019588 df1b bnz $ 0x195a5
ram:01958a 402ce803 cmp !0xfe82c,0x3
ram:01958e df2b bnz $ 0x195bb
ram:019590 342fe8 movw DE,0xe82f
ram:019593 89 mov A,[DE]
ram:019594 5ccf and A,#0xcf
ram:019596 6c20 or A,#0x20
ram:019598 99 mov [DE],A
ram:019599 fc0e8e01 call !!0x18e0e
ram:01959d ef1c br $ 0x195bb
ram:01959f 402ce803 cmp !0xfe82c,0x3
ram:0195a3 ef16 br $ 0x195bb
ram:0195a5 402ce803 cmp !0xfe82c,0x3
ram:0195a9 df10 bnz $ 0x195bb
ram:0195ab d534e8 cmp0 !0xfe834
ram:0195ae dd0b bz $ 0x195bb
ram:0195b0 d934e8 mov X,!0xfe834
ram:0195b3 f1 clrb A
ram:0195b4 fc927e00 call !!0x7e92
ram:0195b8 f534e8 clrb !0xfe834
ram:0195bb eee600 br $! 0x196a4
ram:0195be 8f30e8 mov A,!0xfe830
ram:0195c1 316303 bt A.0x6,$ 0x195c6
ram:0195c4 eedd00 br $! 0x196a4
ram:0195c7 ac0e movw AX,[HL + 0xe]
ram:0195c9 14 movw DE,AX
ram:0195ca 89 mov A,[DE]
ram:0195cb d1 cmp0 A
ram:0195cc df06 bnz $ 0x195d4
ram:0195ce 71182fe8 clr1 !0xfe82f.0x1
ram:0195d2 ef04 br $ 0x195d8
ram:0195d4 71102fe8 set1 !0xfe82f.0x1
ram:0195d8 8f2fe8 mov A,!0xfe82f
ram:0195db 3169 shl A,0x6
ram:0195dd 317a shr A,0x7
ram:0195df 0c02 add A,#0x2
ram:0195e1 3149 shl A,0x4
ram:0195e3 5c30 and A,#0x30
ram:0195e5 3430e8 movw DE,0xe830
ram:0195e8 70 mov ,A
ram:0195e9 89 mov A,[DE]
ram:0195ea 5ccf and A,#0xcf
ram:0195ec 6168 or A,
ram:0195ee 99 mov [DE],A
ram:0195ef 8f2fe8 mov A,!0xfe82f
ram:0195f2 31151b bf A.0x1,$ 0x1960f
ram:0195f5 310518 bf A.0x0,$ 0x1960f
ram:0195f8 71082fe8 clr1 !0xfe82f.0x0
ram:0195fc 71382fe8 clr1 !0xfe82f.0x3
ram:019600 d532e8 cmp0 !0xfe832
ram:019603 dd0b bz $ 0x19610
ram:019605 d932e8 mov X,!0xfe832
ram:019608 f1 clrb A
ram:019609 fc927e00 call !!0x7e92
ram:01960d f532e8 clrb !0xfe832
ram:019610 af1ae4 movw AX,!0xfe41a
ram:019613 e7 onew BC
ram:019614 c3 push BC
ram:019615 12 movw BC,AX
ram:019616 17 movw AX,HL
ram:019617 a1 incw AX
ram:019618 c1 push AX
ram:019619 491600 mov A,!0xf0016[BC]
ram:01961c 9dd4 mov 0xffdf4,A
ram:01961e 791400 movw AX,!0xf0014[BC]
ram:019621 c1 push AX
ram:019622 8dd4 mov A,0xffdf4
ram:019624 9dd6 mov 0xffdf6,A
ram:019626 c0 pop AX
ram:019627 14 movw DE,AX
ram:019628 302900 movw AX,0x29
ram:01962b f7 clrw BC
ram:01962c c1 push AX
ram:01962d 8dd6 mov A,0xffdf6
ram:01962f 9efc mov CS,A
ram:019631 c0 pop AX
ram:019632 61ea call DE
ram:019634 1004 addw SP,0x4
ram:019636 8c01 mov A,[HL + 0x1]
ram:019638 91 dec 
ram:019639 dd0a bz $ 0x19645
ram:01963b 8c01 mov A,[HL + 0x1]
ram:01963d 4c02 cmp A,#0x2
ram:01963f dd63 bz $ 0x196a4
ram:019641 fc0e8e01 call !!0x18e0e
ram:019645 ef5d br $ 0x196a4
ram:019647 ac0e movw AX,[HL + 0xe]
ram:019649 14 movw DE,AX
ram:01964a 89 mov A,[DE]
ram:01964b d1 cmp0 A
ram:01964c df06 bnz $ 0x19654
ram:01964e 71282fe8 clr1 !0xfe82f.0x2
ram:019652 ef04 br $ 0x19658
ram:019654 71202fe8 set1 !0xfe82f.0x2
ram:019658 8f2fe8 mov A,!0xfe82f
ram:01965b 312346 bt A.0x2,$ 0x196a3
ram:01965e fc0e8e01 call !!0x18e0e
ram:019662 ef40 br $ 0x196a4
ram:019664 d935e8 mov X,!0xfe835
ram:019667 f1 clrb A
ram:019668 fc927e00 call !!0x7e92
ram:01966c f535e8 clrb !0xfe835
ram:01966f 4103 mov ES,0x3
ram:019671 11d500f4 cmp0 ES:$! 0x18a74
ram:019675 dd2d bz $ 0x196a4
ram:019677 cc0100 mov [HL + 0x1],0x0
ram:01967a 717830e8 clr1 !0xfe830.0x7
ram:01967e af1ee4 movw AX,!0xfe41e
ram:019681 e7 onew BC
ram:019682 c3 push BC
ram:019683 12 movw BC,AX
ram:019684 17 movw AX,HL
ram:019685 a1 incw AX
ram:019686 c1 push AX
ram:019687 491200 mov A,!0xf0012[BC]
ram:01968a 9dd4 mov 0xffdf4,A
ram:01968c 791000 movw AX,!0xf0010[BC]
ram:01968f c1 push AX
ram:019690 8dd4 mov A,0xffdf4
ram:019692 9dd6 mov 0xffdf6,A
ram:019694 c0 pop AX
ram:019695 14 movw DE,AX
ram:019696 30fe00 movw AX,0xfe
ram:019699 f7 clrw BC
ram:01969a c1 push AX
ram:01969b 8dd6 mov A,0xffdf6
ram:01969d 9efc mov CS,A
ram:01969f c0 pop AX
ram:0196a0 61ea call DE
ram:0196a2 1004 addw SP,0x4
ram:0196a4 e7 onew BC
ram:0196a5 1008 addw SP,0x8
ram:0196a7 c6 pop HL
ram:0196a8 d7 ret
ram:0196a9 c7 push HL
ram:0196aa c1 push AX
ram:0196ab c1 push AX
ram:0196ac fbf8ff movw HL,!0xffff8
ram:0196af c7 push HL
ram:0196b0 17 movw AX,HL
ram:0196b1 16 movw HL,AX
ram:0196b2 f7 clrw BC
ram:0196b3 49ee4b mov A,!0xf4bee[BC]
ram:0196b6 9b mov [HL],A
ram:0196b7 a3 incw BC
ram:0196b8 a7 incw HL
ram:0196b9 5102 mov ,0x2
ram:0196bb 614a cmp A,
ram:0196bd dff4 bnz $ 0x196b3
ram:0196bf c6 pop HL
ram:0196c0 db1ce4 movw BC,!0xfe41c
ram:0196c3 17 movw AX,HL
ram:0196c4 c1 push AX
ram:0196c5 490e00 mov A,!0xf000e[BC]
ram:0196c8 9efc mov CS,A
ram:0196ca 790c00 movw AX,!0xf000c[BC]
ram:0196cd 14 movw DE,AX
ram:0196ce f6 clrw AX
ram:0196cf 61ea call DE
ram:0196d1 c0 pop AX
ram:0196d2 d2 cmp0 C
ram:0196d3 df03 bnz $ 0x196d8
ram:0196d5 f7 clrw BC
ram:0196d6 ef60 br $ 0x19738
ram:0196d8 af1ce4 movw AX,!0xfe41c
ram:0196db 320300 movw BC,0x3
ram:0196de c3 push BC
ram:0196df 12 movw BC,AX
ram:0196e0 ac02 movw AX,[HL + 0x2]
ram:0196e2 c1 push AX
ram:0196e3 491200 mov A,!0xf0012[BC]
ram:0196e6 9dd4 mov 0xffdf4,A
ram:0196e8 791000 movw AX,!0xf0010[BC]
ram:0196eb c1 push AX
ram:0196ec 8dd4 mov A,0xffdf4
ram:0196ee 9dd6 mov 0xffdf6,A
ram:0196f0 c0 pop AX
ram:0196f1 14 movw DE,AX
ram:0196f2 f6 clrw AX
ram:0196f3 12 movw BC,AX
ram:0196f4 c1 push AX
ram:0196f5 8dd6 mov A,0xffdf6
ram:0196f7 9efc mov CS,A
ram:0196f9 c0 pop AX
ram:0196fa 61ea call DE
ram:0196fc 1004 addw SP,0x4
ram:0196fe db1ce4 movw BC,!0xfe41c
ram:019701 8c0c mov A,[HL + 0xc]
ram:019703 318e shrw AX,0x8
ram:019705 c1 push AX
ram:019706 ac0a movw AX,[HL + 0xa]
ram:019708 c1 push AX
ram:019709 491200 mov A,!0xf0012[BC]
ram:01970c 9dd4 mov 0xffdf4,A
ram:01970e 791000 movw AX,!0xf0010[BC]
ram:019711 c1 push AX
ram:019712 8dd4 mov A,0xffdf4
ram:019714 9dd6 mov 0xffdf6,A
ram:019716 c0 pop AX
ram:019717 14 movw DE,AX
ram:019718 f6 clrw AX
ram:019719 12 movw BC,AX
ram:01971a c1 push AX
ram:01971b 8dd6 mov A,0xffdf6
ram:01971d 9efc mov CS,A
ram:01971f c0 pop AX
ram:019720 61ea call DE
ram:019722 1004 addw SP,0x4
ram:019724 db1ce4 movw BC,!0xfe41c
ram:019727 17 movw AX,HL
ram:019728 c1 push AX
ram:019729 490e00 mov A,!0xf000e[BC]
ram:01972c 9efc mov CS,A
ram:01972e 790c00 movw AX,!0xf000c[BC]
ram:019731 14 movw DE,AX
ram:019732 e6 onew AX
ram:019733 a1 incw AX
ram:019734 61ea call DE
ram:019736 c0 pop AX
ram:019737 e7 onew BC
ram:019738 1004 addw SP,0x4
ram:01973a c6 pop HL
ram:01973b d7 ret
ram:0197da c7 push HL
ram:0197db c1 push AX
ram:0197dc 2006 subw SP,0x6
ram:0197de fbf8ff movw HL,!0xffff8
ram:0197e1 c7 push HL
ram:0197e2 17 movw AX,HL
ram:0197e3 040400 addw AX,0x4
ram:0197e6 16 movw HL,AX
ram:0197e7 f7 clrw BC
ram:0197e8 49f24b mov A,!0xf4bf2[BC]
ram:0197eb 9b mov [HL],A
ram:0197ec a3 incw BC
ram:0197ed a7 incw HL
ram:0197ee 5102 mov ,0x2
ram:0197f0 614a cmp A,
ram:0197f2 dff4 bnz $ 0x197e8
ram:0197f4 c6 pop HL
ram:0197f5 c7 push HL
ram:0197f6 17 movw AX,HL
ram:0197f7 a1 incw AX
ram:0197f8 16 movw HL,AX
ram:0197f9 f7 clrw BC
ram:0197fa 49f44b mov A,!0xf4bf4[BC]
ram:0197fd 9b mov [HL],A
ram:0197fe a3 incw BC
ram:0197ff a7 incw HL
ram:019800 5103 mov ,0x3
ram:019802 614a cmp A,
ram:019804 dff4 bnz $ 0x197fa
ram:019806 c6 pop HL
ram:019807 db1ce4 movw BC,!0xfe41c
ram:01980a 17 movw AX,HL
ram:01980b 040400 addw AX,0x4
ram:01980e c1 push AX
ram:01980f 490e00 mov A,!0xf000e[BC]
ram:019812 9efc mov CS,A
ram:019814 790c00 movw AX,!0xf000c[BC]
ram:019817 14 movw DE,AX
ram:019818 f6 clrw AX
ram:019819 61ea call DE
ram:01981b c0 pop AX
ram:01981c d2 cmp0 C
ram:01981d df04 bnz $ 0x19823
ram:01981f f7 clrw BC
ram:019820 ee8200 br $! 0x198a5
ram:019823 af1ce4 movw AX,!0xfe41c
ram:019826 320300 movw BC,0x3
ram:019829 c3 push BC
ram:01982a 12 movw BC,AX
ram:01982b 17 movw AX,HL
ram:01982c a1 incw AX
ram:01982d c1 push AX
ram:01982e 491200 mov A,!0xf0012[BC]
ram:019831 9dd4 mov 0xffdf4,A
ram:019833 791000 movw AX,!0xf0010[BC]
ram:019836 c1 push AX
ram:019837 8dd4 mov A,0xffdf4
ram:019839 9dd6 mov 0xffdf6,A
ram:01983b c0 pop AX
ram:01983c 14 movw DE,AX
ram:01983d f6 clrw AX
ram:01983e 12 movw BC,AX
ram:01983f c1 push AX
ram:019840 8dd6 mov A,0xffdf6
ram:019842 9efc mov CS,A
ram:019844 c0 pop AX
ram:019845 61ea call DE
ram:019847 1004 addw SP,0x4
ram:019849 8c06 mov A,[HL + 0x6]
ram:01984b 9c05 mov [HL + 0x5],A
ram:01984d db1ce4 movw BC,!0xfe41c
ram:019850 17 movw AX,HL
ram:019851 040400 addw AX,0x4
ram:019854 c1 push AX
ram:019855 490e00 mov A,!0xf000e[BC]
ram:019858 9efc mov CS,A
ram:01985a 790c00 movw AX,!0xf000c[BC]
ram:01985d 14 movw DE,AX
ram:01985e e6 onew AX
ram:01985f 61ea call DE
ram:019861 c0 pop AX
ram:019862 d2 cmp0 C
ram:019863 df03 bnz $ 0x19868
ram:019865 f7 clrw BC
ram:019866 ef3d br $ 0x198a5
ram:019868 db1ce4 movw BC,!0xfe41c
ram:01986b 8c10 mov A,[HL + 0x10]
ram:01986d 318e shrw AX,0x8
ram:01986f c1 push AX
ram:019870 ac0e movw AX,[HL + 0xe]
ram:019872 c1 push AX
ram:019873 491200 mov A,!0xf0012[BC]
ram:019876 9dd4 mov 0xffdf4,A
ram:019878 791000 movw AX,!0xf0010[BC]
ram:01987b c1 push AX
ram:01987c 8dd4 mov A,0xffdf4
ram:01987e 9dd6 mov 0xffdf6,A
ram:019880 c0 pop AX
ram:019881 14 movw DE,AX
ram:019882 f6 clrw AX
ram:019883 12 movw BC,AX
ram:019884 c1 push AX
ram:019885 8dd6 mov A,0xffdf6
ram:019887 9efc mov CS,A
ram:019889 c0 pop AX
ram:01988a 61ea call DE
ram:01988c 1004 addw SP,0x4
ram:01988e db1ce4 movw BC,!0xfe41c
ram:019891 17 movw AX,HL
ram:019892 040400 addw AX,0x4
ram:019895 c1 push AX
ram:019896 490e00 mov A,!0xf000e[BC]
ram:019899 9efc mov CS,A
ram:01989b 790c00 movw AX,!0xf000c[BC]
ram:01989e 14 movw DE,AX
ram:01989f e6 onew AX
ram:0198a0 a1 incw AX
ram:0198a1 61ea call DE
ram:0198a3 c0 pop AX
ram:0198a4 e7 onew BC
ram:0198a5 1008 addw SP,0x8
ram:0198a7 c6 pop HL
ram:0198a8 d7 ret
ram:0198a9 c7 push HL
ram:0198aa c1 push AX
ram:0198ab 2006 subw SP,0x6
ram:0198ad fbf8ff movw HL,!0xffff8
ram:0198b0 c7 push HL
ram:0198b1 17 movw AX,HL
ram:0198b2 040400 addw AX,0x4
ram:0198b5 16 movw HL,AX
ram:0198b6 f7 clrw BC
ram:0198b7 49f84b mov A,!0xf4bf8[BC]
ram:0198ba 9b mov [HL],A
ram:0198bb a3 incw BC
ram:0198bc a7 incw HL
ram:0198bd 5102 mov ,0x2
ram:0198bf 614a cmp A,
ram:0198c1 dff4 bnz $ 0x198b7
ram:0198c3 c6 pop HL
ram:0198c4 c7 push HL
ram:0198c5 17 movw AX,HL
ram:0198c6 a1 incw AX
ram:0198c7 16 movw HL,AX
ram:0198c8 f7 clrw BC
ram:0198c9 49fa4b mov A,!0xf4bfa[BC]
ram:0198cc 9b mov [HL],A
ram:0198cd a3 incw BC
ram:0198ce a7 incw HL
ram:0198cf 5103 mov ,0x3
ram:0198d1 614a cmp A,
ram:0198d3 dff4 bnz $ 0x198c9
ram:0198d5 c6 pop HL
ram:0198d6 db1ce4 movw BC,!0xfe41c
ram:0198d9 17 movw AX,HL
ram:0198da 040400 addw AX,0x4
ram:0198dd c1 push AX
ram:0198de 490e00 mov A,!0xf000e[BC]
ram:0198e1 9efc mov CS,A
ram:0198e3 790c00 movw AX,!0xf000c[BC]
ram:0198e6 14 movw DE,AX
ram:0198e7 f6 clrw AX
ram:0198e8 61ea call DE
ram:0198ea c0 pop AX
ram:0198eb d2 cmp0 C
ram:0198ec df03 bnz $ 0x198f1
ram:0198ee f7 clrw BC
ram:0198ef ef6e br $ 0x1995f
ram:0198f1 af1ce4 movw AX,!0xfe41c
ram:0198f4 320300 movw BC,0x3
ram:0198f7 c3 push BC
ram:0198f8 12 movw BC,AX
ram:0198f9 17 movw AX,HL
ram:0198fa a1 incw AX
ram:0198fb c1 push AX
ram:0198fc 491200 mov A,!0xf0012[BC]
ram:0198ff 9dd4 mov 0xffdf4,A
ram:019901 791000 movw AX,!0xf0010[BC]
ram:019904 c1 push AX
ram:019905 8dd4 mov A,0xffdf4
ram:019907 9dd6 mov 0xffdf6,A
ram:019909 c0 pop AX
ram:01990a 14 movw DE,AX
ram:01990b f6 clrw AX
ram:01990c 12 movw BC,AX
ram:01990d c1 push AX
ram:01990e 8dd6 mov A,0xffdf6
ram:019910 9efc mov CS,A
ram:019912 c0 pop AX
ram:019913 61ea call DE
ram:019915 1004 addw SP,0x4
ram:019917 8c06 mov A,[HL + 0x6]
ram:019919 6c01 or A,#0x1
ram:01991b 9c05 mov [HL + 0x5],A
ram:01991d db1ce4 movw BC,!0xfe41c
ram:019920 17 movw AX,HL
ram:019921 040400 addw AX,0x4
ram:019924 c1 push AX
ram:019925 490e00 mov A,!0xf000e[BC]
ram:019928 9efc mov CS,A
ram:01992a 790c00 movw AX,!0xf000c[BC]
ram:01992d 14 movw DE,AX
ram:01992e e6 onew AX
ram:01992f 61ea call DE
ram:019931 c0 pop AX
ram:019932 d2 cmp0 C
ram:019933 df03 bnz $ 0x19938
ram:019935 f7 clrw BC
ram:019936 ef27 br $ 0x1995f
ram:019938 db1ce4 movw BC,!0xfe41c
ram:01993b 8c10 mov A,[HL + 0x10]
ram:01993d 318e shrw AX,0x8
ram:01993f c1 push AX
ram:019940 ac0e movw AX,[HL + 0xe]
ram:019942 c1 push AX
ram:019943 491600 mov A,!0xf0016[BC]
ram:019946 9dd4 mov 0xffdf4,A
ram:019948 791400 movw AX,!0xf0014[BC]
ram:01994b c1 push AX
ram:01994c 8dd4 mov A,0xffdf4
ram:01994e 9dd6 mov 0xffdf6,A
ram:019950 c0 pop AX
ram:019951 14 movw DE,AX
ram:019952 f6 clrw AX
ram:019953 12 movw BC,AX
ram:019954 c1 push AX
ram:019955 8dd6 mov A,0xffdf6
ram:019957 9efc mov CS,A
ram:019959 c0 pop AX
ram:01995a 61ea call DE
ram:01995c 1004 addw SP,0x4
ram:01995e e7 onew BC
ram:01995f 1008 addw SP,0x8
ram:019961 c6 pop HL
ram:019962 d7 ret
ram:019963 c7 push HL
ram:019964 c1 push AX
ram:019965 2004 subw SP,0x4
ram:019967 fbf8ff movw HL,!0xffff8
ram:01996a f6 clrw AX
ram:01996b bb movw [HL],AX
ram:01996c ac04 movw AX,[HL + 0x4]
ram:01996e 14 movw DE,AX
ram:01996f 89 mov A,[DE]
ram:019970 d1 cmp0 A
ram:019971 dd75 bz $ 0x199e8
ram:019973 89 mov A,[DE]
ram:019974 91 dec 
ram:019975 df36 bnz $ 0x199ad
ram:019977 8a01 mov A,[DE + 0x1]
ram:019979 2c03 sub A,#0x3
ram:01997b 9c02 mov [HL + 0x2],A
ram:01997d 318e shrw AX,0x8
ram:01997f c1 push AX
ram:019980 ac04 movw AX,[HL + 0x4]
ram:019982 040500 addw AX,0x5
ram:019985 c1 push AX
ram:019986 ac04 movw AX,[HL + 0x4]
ram:019988 a1 incw AX
ram:019989 a1 incw AX
ram:01998a fca99601 call !!0x196a9
ram:01998e 1004 addw SP,0x4
ram:019990 62 mov A,
ram:019991 9c03 mov [HL + 0x3],A
ram:019993 d1 cmp0 A
ram:019994 df07 bnz $ 0x1999d
ram:019996 710058e8 set1 !0xfe858.0x0
ram:01999a f7 clrw BC
ram:01999b ef4c br $ 0x199e9
ram:01999d ac04 movw AX,[HL + 0x4]
ram:01999f 14 movw DE,AX
ram:0199a0 8a01 mov A,[DE + 0x1]
ram:0199a2 0c02 add A,#0x2
ram:0199a4 318e shrw AX,0x8
ram:0199a6 610904 addw AX,[HL + 0x4]
ram:0199a9 bc04 movw [HL + 0x4],AX
ram:0199ab efbf br $ 0x1996c
ram:0199ad ac04 movw AX,[HL + 0x4]
ram:0199af 14 movw DE,AX
ram:0199b0 8a01 mov A,[DE + 0x1]
ram:0199b2 91 dec 
ram:0199b3 9c02 mov [HL + 0x2],A
ram:0199b5 318e shrw AX,0x8
ram:0199b7 c1 push AX
ram:0199b8 ac04 movw AX,[HL + 0x4]
ram:0199ba 040300 addw AX,0x3
ram:0199bd c1 push AX
ram:0199be ac04 movw AX,[HL + 0x4]
ram:0199c0 14 movw DE,AX
ram:0199c1 8a02 mov A,[DE + 0x2]
ram:0199c3 318e shrw AX,0x8
ram:0199c5 fcda9701 call !!0x197da
ram:0199c9 1004 addw SP,0x4
ram:0199cb 62 mov A,
ram:0199cc 9c03 mov [HL + 0x3],A
ram:0199ce d1 cmp0 A
ram:0199cf df07 bnz $ 0x199d8
ram:0199d1 711058e8 set1 !0xfe858.0x1
ram:0199d5 f7 clrw BC
ram:0199d6 ef11 br $ 0x199e9
ram:0199d8 ac04 movw AX,[HL + 0x4]
ram:0199da 14 movw DE,AX
ram:0199db 8a01 mov A,[DE + 0x1]
ram:0199dd 0c02 add A,#0x2
ram:0199df 318e shrw AX,0x8
ram:0199e1 610904 addw AX,[HL + 0x4]
ram:0199e4 bc04 movw [HL + 0x4],AX
ram:0199e6 ef84 br $ 0x1996c
ram:0199e8 e7 onew BC
ram:0199e9 1006 addw SP,0x6
ram:0199eb c6 pop HL
ram:0199ec d7 ret
ram:019a62 c7 push HL
ram:019a63 16 movw HL,AX
ram:019a64 66 mov A,
ram:019a65 91 dec 
ram:019a66 df18 bnz $ 0x19a80
ram:019a68 e6 onew AX
ram:019a69 fc159c01 call !!0x19c15
ram:019a6d 30ed99 movw AX,0x99ed
ram:019a70 5201 mov ,0x1
ram:019a72 f3 clrb B
ram:019a73 fc057e00 call !!0x7e05
ram:019a77 62 mov A,
ram:019a78 9f57e8 mov !0xfe857,A
ram:019a7b e556e8 oneb !0xfe856
ram:019a7e ef1e br $ 0x19a9e
ram:019a80 4056e801 cmp !0xfe856,0x1
ram:019a84 df0b bnz $ 0x19a91
ram:019a86 d957e8 mov X,!0xfe857
ram:019a89 f1 clrb A
ram:019a8a fc927e00 call !!0x7e92
ram:019a8e f557e8 clrb !0xfe857
ram:019a91 f556e8 clrb !0xfe856
ram:019a94 e6 onew AX
ram:019a95 fc259c01 call !!0x19c25
ram:019a99 f6 clrw AX
ram:019a9a fc159c01 call !!0x19c15
ram:019a9e c6 pop HL
ram:019a9f d7 ret
ram:019aa4 8f56e8 mov A,!0xfe856
ram:019aa7 318f sarw AX,0x8
ram:019aa9 12 movw BC,AX
ram:019aaa d7 ret
ram:019aab c7 push HL
ram:019aac c1 push AX
ram:019aad 2004 subw SP,0x4
ram:019aaf fbf8ff movw HL,!0xffff8
ram:019ab2 cc0301 mov [HL + 0x3],0x1
ram:019ab5 8c04 mov A,[HL + 0x4]
ram:019ab7 d1 cmp0 A
ram:019ab8 dd08 bz $ 0x19ac2
ram:019aba 91 dec 
ram:019abb dd22 bz $ 0x19adf
ram:019abd 91 dec 
ram:019abe dd3c bz $ 0x19afc
ram:019ac0 ef46 br $ 0x19b08
ram:019ac2 ac0c movw AX,[HL + 0xc]
ram:019ac4 bb movw [HL],AX
ram:019ac5 14 movw DE,AX
ram:019ac6 8a01 mov A,[DE + 0x1]
ram:019ac8 318e shrw AX,0x8
ram:019aca c1 push AX
ram:019acb aa02 movw AX,[DE + 0x2]
ram:019acd c1 push AX
ram:019ace 89 mov A,[DE]
ram:019acf 318e shrw AX,0x8
ram:019ad1 fcda9701 call !!0x197da
ram:019ad5 1004 addw SP,0x4
ram:019ad7 d2 cmp0 C
ram:019ad8 df2e bnz $ 0x19b08
ram:019ada cc0300 mov [HL + 0x3],0x0
ram:019add ef29 br $ 0x19b08
ram:019adf ac0c movw AX,[HL + 0xc]
ram:019ae1 bb movw [HL],AX
ram:019ae2 14 movw DE,AX
ram:019ae3 8a01 mov A,[DE + 0x1]
ram:019ae5 318e shrw AX,0x8
ram:019ae7 c1 push AX
ram:019ae8 aa02 movw AX,[DE + 0x2]
ram:019aea c1 push AX
ram:019aeb 89 mov A,[DE]
ram:019aec 318e shrw AX,0x8
ram:019aee fca99801 call !!0x198a9
ram:019af2 1004 addw SP,0x4
ram:019af4 d2 cmp0 C
ram:019af5 df11 bnz $ 0x19b08
ram:019af7 cc0300 mov [HL + 0x3],0x0
ram:019afa ef0c br $ 0x19b08
ram:019afc ac0c movw AX,[HL + 0xc]
ram:019afe fc639901 call !!0x19963
ram:019b02 d2 cmp0 C
ram:019b03 61f8 sknz
ram:019b05 cc0300 _mov [HL + 0x3],0x0
ram:019b08 8c03 mov A,[HL + 0x3]
ram:019b0a 318e shrw AX,0x8
ram:019b0c 12 movw BC,AX
ram:019b0d 1006 addw SP,0x6
ram:019b0f c6 pop HL
ram:019b10 d7 ret
ram:019c15 c7 push HL
ram:019c16 16 movw HL,AX
ram:019c17 66 mov A,
ram:019c18 91 dec 
ram:019c19 df05 bnz $ 0x19c20
ram:019c1b 717201 set1 0xffe21.0x7
ram:019c1e ef03 br $ 0x19c23
ram:019c20 717301 clr1 0xffe21.0x7
ram:019c23 c6 pop HL
ram:019c24 d7 ret
ram:019c25 c7 push HL
ram:019c26 16 movw HL,AX
ram:019c27 66 mov A,
ram:019c28 91 dec 
ram:019c29 df05 bnz $ 0x19c30
ram:019c2b 71630c clr1 0xffe2c.0x6
ram:019c2e ef03 br $ 0x19c33
ram:019c30 71620c set1 0xffe2c.0x6
ram:019c33 c6 pop HL
ram:019c34 d7 ret
ram:019c35 c7 push HL
ram:019c36 c1 push AX
ram:019c37 c1 push AX
ram:019c38 fbf8ff movw HL,!0xffff8
ram:019c3b c7 push HL
ram:019c3c 17 movw AX,HL
ram:019c3d 16 movw HL,AX
ram:019c3e f7 clrw BC
ram:019c3f 49d850 mov A,!0xf50d8[BC]
ram:019c42 9b mov [HL],A
ram:019c43 a3 incw BC
ram:019c44 a7 incw HL
ram:019c45 5102 mov ,0x2
ram:019c47 614a cmp A,
ram:019c49 dff4 bnz $ 0x19c3f
ram:019c4b c6 pop HL
ram:019c4c ac02 movw AX,[HL + 0x2]
ram:019c4e 14 movw DE,AX
ram:019c4f 8a04 mov A,[DE + 0x4]
ram:019c51 5c01 and A,#0x1
ram:019c53 318e shrw AX,0x8
ram:019c55 e7 onew BC
ram:019c56 240000 subw AX,0x0
ram:019c59 dd05 bz $ 0x19c60
ram:019c5b 23 subw AX,BC
ram:019c5c dd42 bz $ 0x19ca0
ram:019c5e ef7b br $ 0x19cdb
ram:019c60 cc0008 mov [HL + 0x0],0x8
ram:019c63 af04e4 movw AX,!0xfe404
ram:019c66 e7 onew BC
ram:019c67 a3 incw BC
ram:019c68 c3 push BC
ram:019c69 12 movw BC,AX
ram:019c6a 17 movw AX,HL
ram:019c6b c1 push AX
ram:019c6c 491200 mov A,!0xf0012[BC]
ram:019c6f 9dd4 mov 0xffdf4,A
ram:019c71 791000 movw AX,!0xf0010[BC]
ram:019c74 c1 push AX
ram:019c75 8dd4 mov A,0xffdf4
ram:019c77 9dd6 mov 0xffdf6,A
ram:019c79 c0 pop AX
ram:019c7a 14 movw DE,AX
ram:019c7b 309010 movw AX,0x1090
ram:019c7e 320d00 movw BC,0xd
ram:019c81 c1 push AX
ram:019c82 8dd6 mov A,0xffdf6
ram:019c84 9efc mov CS,A
ram:019c86 c0 pop AX
ram:019c87 61ea call DE
ram:019c89 1004 addw SP,0x4
ram:019c8b ac02 movw AX,[HL + 0x2]
ram:019c8d 14 movw DE,AX
ram:019c8e aa04 movw AX,[DE + 0x4]
ram:019c90 311e shrw AX,0x1
ram:019c92 31ed shlw AX,0xe
ram:019c94 31ee shrw AX,0xe
ram:019c96 01 addw AX,AX
ram:019c97 12 movw BC,AX
ram:019c98 7978e8 movw AX,!0xfe878[BC]
ram:019c9b 12 movw BC,AX
ram:019c9c ba06 movw [DE + 0x6],AX
ram:019c9e ef3b br $ 0x19cdb
ram:019ca0 af04e4 movw AX,!0xfe404
ram:019ca3 e7 onew BC
ram:019ca4 a3 incw BC
ram:019ca5 c3 push BC
ram:019ca6 12 movw BC,AX
ram:019ca7 17 movw AX,HL
ram:019ca8 c1 push AX
ram:019ca9 491200 mov A,!0xf0012[BC]
ram:019cac 9dd4 mov 0xffdf4,A
ram:019cae 791000 movw AX,!0xf0010[BC]
ram:019cb1 c1 push AX
ram:019cb2 8dd4 mov A,0xffdf4
ram:019cb4 9dd6 mov 0xffdf6,A
ram:019cb6 c0 pop AX
ram:019cb7 14 movw DE,AX
ram:019cb8 309010 movw AX,0x1090
ram:019cbb 320d00 movw BC,0xd
ram:019cbe c1 push AX
ram:019cbf 8dd6 mov A,0xffdf6
ram:019cc1 9efc mov CS,A
ram:019cc3 c0 pop AX
ram:019cc4 61ea call DE
ram:019cc6 1004 addw SP,0x4
ram:019cc8 ac02 movw AX,[HL + 0x2]
ram:019cca 14 movw DE,AX
ram:019ccb aa04 movw AX,[DE + 0x4]
ram:019ccd 311e shrw AX,0x1
ram:019ccf 31ed shlw AX,0xe
ram:019cd1 31ee shrw AX,0xe
ram:019cd3 01 addw AX,AX
ram:019cd4 12 movw BC,AX
ram:019cd5 7980e8 movw AX,!0xfe880[BC]
ram:019cd8 12 movw BC,AX
ram:019cd9 ba06 movw [DE + 0x6],AX
ram:019cdb ac02 movw AX,[HL + 0x2]
ram:019cdd 14 movw DE,AX
ram:019cde aa04 movw AX,[DE + 0x4]
ram:019ce0 a1 incw AX
ram:019ce1 ba04 movw [DE + 0x4],AX
ram:019ce3 f6 clrw AX
ram:019ce4 4288e8 cmpw AX,!0xfe888
ram:019ce7 dd14 bz $ 0x19cfd
ram:019ce9 ac02 movw AX,[HL + 0x2]
ram:019ceb c1 push AX
ram:019cec af88e8 movw AX,!0xfe888
ram:019cef 01 addw AX,AX
ram:019cf0 c4 pop DE
ram:019cf1 12 movw BC,AX
ram:019cf2 aa04 movw AX,[DE + 0x4]
ram:019cf4 43 cmpw AX,BC
ram:019cf5 dc06 bc $ 0x19cfd
ram:019cf7 f576e8 clrb !0xfe876
ram:019cfa f7 clrw BC
ram:019cfb ef01 br $ 0x19cfe
ram:019cfd e7 onew BC
ram:019cfe 1004 addw SP,0x4
ram:019d00 c6 pop HL
ram:019d01 d7 ret
ram:019d02 c7 push HL
ram:019d03 d576e8 cmp0 !0xfe876
ram:019d06 dd1f bz $ 0x19d27
ram:019d08 d976e8 mov X,!0xfe876
ram:019d0b f1 clrb A
ram:019d0c fc927e00 call !!0x7e92
ram:019d10 f576e8 clrb !0xfe876
ram:019d13 af04e4 movw AX,!0xfe404
ram:019d16 365050 movw HL,0x5050
ram:019d19 c7 push HL
ram:019d1a 14 movw DE,AX
ram:019d1b 8a0e mov A,[DE + 0xe]
ram:019d1d 9efc mov CS,A
ram:019d1f aa0c movw AX,[DE + 0xc]
ram:019d21 16 movw HL,AX
ram:019d22 e6 onew AX
ram:019d23 a1 incw AX
ram:019d24 61fa call HL
ram:019d26 c0 pop AX
ram:019d27 c6 pop HL
ram:019d28 d7 ret
ram:019d29 c7 push HL
ram:019d2a c1 push AX
ram:019d2b c1 push AX
ram:019d2c fbf8ff movw HL,!0xffff8
ram:019d2f fc029d01 call !!0x19d02
ram:019d33 8c02 mov A,[HL + 0x2]
ram:019d35 4c04 cmp A,#0x4
ram:019d37 dc05 bc $ 0x19d3e
ram:019d39 cc0103 mov [HL + 0x1],0x3
ram:019d3c ef04 br $ 0x19d42
ram:019d3e 8c02 mov A,[HL + 0x2]
ram:019d40 9c01 mov [HL + 0x1],A
ram:019d42 db04e4 movw BC,!0xfe404
ram:019d45 8c01 mov A,[HL + 0x1]
ram:019d47 f0 clrb X
ram:019d48 312e shrw AX,0x2
ram:019d4a 04504f addw AX,0x4f50
ram:019d4d c1 push AX
ram:019d4e 490e00 mov A,!0xf000e[BC]
ram:019d51 9efc mov CS,A
ram:019d53 790c00 movw AX,!0xf000c[BC]
ram:019d56 14 movw DE,AX
ram:019d57 e6 onew AX
ram:019d58 a1 incw AX
ram:019d59 61ea call DE
ram:019d5b c0 pop AX
ram:019d5c af04e4 movw AX,!0xfe404
ram:019d5f e7 onew BC
ram:019d60 a3 incw BC
ram:019d61 c3 push BC
ram:019d62 c1 push AX
ram:019d63 8c0a mov A,[HL + 0xa]
ram:019d65 73 mov ,A
ram:019d66 09a655 mov A,!0xf55a6[B]
ram:019d69 318f sarw AX,0x8
ram:019d6b fc422f02 call !!0x22f42
ram:019d6f c0 pop AX
ram:019d70 c3 push BC
ram:019d71 14 movw DE,AX
ram:019d72 8a12 mov A,[DE + 0x12]
ram:019d74 9dd4 mov 0xffdf4,A
ram:019d76 aa10 movw AX,[DE + 0x10]
ram:019d78 c1 push AX
ram:019d79 8dd4 mov A,0xffdf4
ram:019d7b 9dd6 mov 0xffdf6,A
ram:019d7d c0 pop AX
ram:019d7e 14 movw DE,AX
ram:019d7f 308c10 movw AX,0x108c
ram:019d82 320d00 movw BC,0xd
ram:019d85 c1 push AX
ram:019d86 8dd6 mov A,0xffdf6
ram:019d88 9efc mov CS,A
ram:019d8a c0 pop AX
ram:019d8b 61ea call DE
ram:019d8d 1004 addw SP,0x4
ram:019d8f 8c02 mov A,[HL + 0x2]
ram:019d91 5018 mov ,0x18
ram:019d93 d6 mulu X
ram:019d94 12 movw BC,AX
ram:019d95 796250 movw AX,!0xf5062[BC]
ram:019d98 bf78e8 movw !0xfe878,AX
ram:019d9b 796450 movw AX,!0xf5064[BC]
ram:019d9e bf80e8 movw !0xfe880,AX
ram:019da1 796650 movw AX,!0xf5066[BC]
ram:019da4 bf7ae8 movw !0xfe87a,AX
ram:019da7 796850 movw AX,!0xf5068[BC]
ram:019daa bf82e8 movw !0xfe882,AX
ram:019dad 796a50 movw AX,!0xf506a[BC]
ram:019db0 bf7ce8 movw !0xfe87c,AX
ram:019db3 796c50 movw AX,!0xf506c[BC]
ram:019db6 bf84e8 movw !0xfe884,AX
ram:019db9 796e50 movw AX,!0xf506e[BC]
ram:019dbc bf7ee8 movw !0xfe87e,AX
ram:019dbf 797050 movw AX,!0xf5070[BC]
ram:019dc2 bf86e8 movw !0xfe886,AX
ram:019dc5 797250 movw AX,!0xf5072[BC]
ram:019dc8 bf88e8 movw !0xfe888,AX
ram:019dcb 796050 movw AX,!0xf5060[BC]
ram:019dce c1 push AX
ram:019dcf 30359c movw AX,0x9c35
ram:019dd2 5201 mov ,0x1
ram:019dd4 f3 clrb B
ram:019dd5 fcea7d00 call !!0x7dea
ram:019dd9 c0 pop AX
ram:019dda 62 mov A,
ram:019ddb 9f76e8 mov !0xfe876,A
ram:019dde 1004 addw SP,0x4
ram:019de0 c6 pop HL
ram:019de1 d7 ret
ram:019de2 c7 push HL
ram:019de3 c3 push BC
ram:019de4 c1 push AX
ram:019de5 2004 subw SP,0x4
ram:019de7 fbf8ff movw HL,!0xffff8
ram:019dea e6 onew AX
ram:019deb bc02 movw [HL + 0x2],AX
ram:019ded f6 clrw AX
ram:019dee bb movw [HL],AX
ram:019def ab movw AX,[HL]
ram:019df0 449303 cmpw AX,0x393
ram:019df3 de1c bnc $ 0x19e11
ram:019df5 ab movw AX,[HL]
ram:019df6 610904 addw AX,[HL + 0x4]
ram:019df9 14 movw DE,AX
ram:019dfa 8c06 mov A,[HL + 0x6]
ram:019dfc 9efd mov ES,A
ram:019dfe 1189 mov A,ES:[DE]
ram:019e00 72 mov ,A
ram:019e01 8c02 mov A,[HL + 0x2]
ram:019e03 610a add A,
ram:019e05 70 mov ,A
ram:019e06 8c03 mov A,[HL + 0x3]
ram:019e08 1c00 addc A,#0x0
ram:019e0a bc02 movw [HL + 0x2],AX
ram:019e0c 617900 incw [HL + 0x0]
ram:019e0f efde br $ 0x19def
ram:019e11 8c06 mov A,[HL + 0x6]
ram:019e13 9dd4 mov 0xffdf4,A
ram:019e15 ac04 movw AX,[HL + 0x4]
ram:019e17 049303 addw AX,0x393
ram:019e1a 14 movw DE,AX
ram:019e1b 8dd4 mov A,0xffdf4
ram:019e1d 9dd6 mov 0xffdf6,A
ram:019e1f ac02 movw AX,[HL + 0x2]
ram:019e21 318e shrw AX,0x8
ram:019e23 61b8d6 mov ES,0xffdf6
ram:019e26 1189 mov A,ES:[DE]
ram:019e28 6148 cmp A,
ram:019e2a df22 bnz $ 0x19e4e
ram:019e2c 8c06 mov A,[HL + 0x6]
ram:019e2e 9dd4 mov 0xffdf4,A
ram:019e30 ac04 movw AX,[HL + 0x4]
ram:019e32 049403 addw AX,0x394
ram:019e35 14 movw DE,AX
ram:019e36 8dd4 mov A,0xffdf4
ram:019e38 9dd6 mov 0xffdf6,A
ram:019e3a 51ff mov ,0xff
ram:019e3c 5e02 and A,[HL + 0x2]
ram:019e3e 318e shrw AX,0x8
ram:019e40 61b8d6 mov ES,0xffdf6
ram:019e43 12 movw BC,AX
ram:019e44 1189 mov A,ES:[DE]
ram:019e46 318e shrw AX,0x8
ram:019e48 43 cmpw AX,BC
ram:019e49 df03 bnz $ 0x19e4e
ram:019e4b e7 onew BC
ram:019e4c ef01 br $ 0x19e4f
ram:019e4e f7 clrw BC
ram:019e4f 1008 addw SP,0x8
ram:019e51 c6 pop HL
ram:019e52 d7 ret
ram:019e53 c7 push HL
ram:019e54 206a subw SP,0x6a
ram:019e56 fbf8ff movw HL,!0xffff8
ram:019e59 300080 movw AX,0x8000
ram:019e5c bc66 movw [HL + 0x66],AX
ram:019e5e 5103 mov ,0x3
ram:019e60 9c68 mov [HL + 0x68],A
ram:019e62 72 mov ,A
ram:019e63 f3 clrb B
ram:019e64 ac66 movw AX,[HL + 0x66]
ram:019e66 fce29d01 call !!0x19de2
ram:019e6a d2 cmp0 C
ram:019e6b df08 bnz $ 0x19e75
ram:019e6d 30e469 movw AX,0x69e4
ram:019e70 bc66 movw [HL + 0x66],AX
ram:019e72 cc6800 mov [HL + 0x68],0x0
ram:019e75 cc6500 mov [HL + 0x65],0x0
ram:019e78 8c65 mov A,[HL + 0x65]
ram:019e7a 4c16 cmp A,#0x16
ram:019e7c 61c8 skc
ram:019e7e eec900 _br $! 0x19f4a
ram:019e81 ac66 movw AX,[HL + 0x66]
ram:019e83 14 movw DE,AX
ram:019e84 8c68 mov A,[HL + 0x68]
ram:019e86 9efd mov ES,A
ram:019e88 1189 mov A,ES:[DE]
ram:019e8a 9dd8 mov 0xffdf8,A
ram:019e8c f4d9 clrb 0xffdf9
ram:019e8e f6 clrw AX
ram:019e8f bdda movw 0xffdfa,AX
ram:019e91 5110 mov ,0x10
ram:019e93 fd7106 call !0xf0671
ram:019e96 8c68 mov A,[HL + 0x68]
ram:019e98 9dd4 mov 0xffdf4,A
ram:019e9a ac66 movw AX,[HL + 0x66]
ram:019e9c a1 incw AX
ram:019e9d c1 push AX
ram:019e9e add8 movw AX,0xffdf8
ram:019ea0 bddc movw 0xffdfc,AX
ram:019ea2 adda movw AX,0xffdfa
ram:019ea4 bdde movw 0xffdfe,AX
ram:019ea6 c0 pop AX
ram:019ea7 14 movw DE,AX
ram:019ea8 61b8d4 mov ES,0xffdf4
ram:019eab 1189 mov A,ES:[DE]
ram:019ead 9dd8 mov 0xffdf8,A
ram:019eaf f4d9 clrb 0xffdf9
ram:019eb1 f6 clrw AX
ram:019eb2 bdda movw 0xffdfa,AX
ram:019eb4 5108 mov ,0x8
ram:019eb6 fd7106 call !0xf0671
ram:019eb9 adde movw AX,0xffdfe
ram:019ebb fdcb06 call !0xf06cb
ram:019ebe 8c68 mov A,[HL + 0x68]
ram:019ec0 9dd4 mov 0xffdf4,A
ram:019ec2 ac66 movw AX,[HL + 0x66]
ram:019ec4 a1 incw AX
ram:019ec5 a1 incw AX
ram:019ec6 c1 push AX
ram:019ec7 add8 movw AX,0xffdf8
ram:019ec9 bddc movw 0xffdfc,AX
ram:019ecb adda movw AX,0xffdfa
ram:019ecd bdde movw 0xffdfe,AX
ram:019ecf c0 pop AX
ram:019ed0 14 movw DE,AX
ram:019ed1 61b8d4 mov ES,0xffdf4
ram:019ed4 1189 mov A,ES:[DE]
ram:019ed6 9dd8 mov 0xffdf8,A
ram:019ed8 f4d9 clrb 0xffdf9
ram:019eda f6 clrw AX
ram:019edb bdda movw 0xffdfa,AX
ram:019edd adde movw AX,0xffdfe
ram:019edf fdcb06 call !0xf06cb
ram:019ee2 adda movw AX,0xffdfa
ram:019ee4 bc02 movw [HL + 0x2],AX
ram:019ee6 add8 movw AX,0xffdf8
ram:019ee8 bb movw [HL],AX
ram:019ee9 ac66 movw AX,[HL + 0x66]
ram:019eeb 040300 addw AX,0x3
ram:019eee bc66 movw [HL + 0x66],AX
ram:019ef0 cc6400 mov [HL + 0x64],0x0
ram:019ef3 8c65 mov A,[HL + 0x65]
ram:019ef5 73 mov ,A
ram:019ef6 09da50 mov A,!0xf50da[B]
ram:019ef9 4e64 cmp A,[HL + 0x64]
ram:019efb 61d321 bnh $ 0x19f1e
ram:019efe 8c68 mov A,[HL + 0x68]
ram:019f00 9dd4 mov 0xffdf4,A
ram:019f02 ac66 movw AX,[HL + 0x66]
ram:019f04 a1 incw AX
ram:019f05 bc66 movw [HL + 0x66],AX
ram:019f07 b1 decw AX
ram:019f08 14 movw DE,AX
ram:019f09 61b8d4 mov ES,0xffdf4
ram:019f0c 1189 mov A,ES:[DE]
ram:019f0e 72 mov ,A
ram:019f0f 8c64 mov A,[HL + 0x64]
ram:019f11 318e shrw AX,0x8
ram:019f13 07 addw AX,HL
ram:019f14 040400 addw AX,0x4
ram:019f17 14 movw DE,AX
ram:019f18 62 mov A,
ram:019f19 99 mov [DE],A
ram:019f1a 615964 inc [HL + 0x64]
ram:019f1d efd4 br $ 0x19ef3
ram:019f1f db04e4 movw BC,!0xfe404
ram:019f22 8c65 mov A,[HL + 0x65]
ram:019f24 318e shrw AX,0x8
ram:019f26 04da50 addw AX,0x50da
ram:019f29 14 movw DE,AX
ram:019f2a 89 mov A,[DE]
ram:019f2b 318e shrw AX,0x8
ram:019f2d c1 push AX
ram:019f2e 17 movw AX,HL
ram:019f2f 040400 addw AX,0x4
ram:019f32 c1 push AX
ram:019f33 491200 mov A,!0xf0012[BC]
ram:019f36 9efc mov CS,A
ram:019f38 791000 movw AX,!0xf0010[BC]
ram:019f3b 14 movw DE,AX
ram:019f3c ac02 movw AX,[HL + 0x2]
ram:019f3e 12 movw BC,AX
ram:019f3f ab movw AX,[HL]
ram:019f40 61ea call DE
ram:019f42 1004 addw SP,0x4
ram:019f44 615965 inc [HL + 0x65]
ram:019f47 ee2eff br $! 0x19e78
ram:019f4a 106a addw SP,0x6a
ram:019f4c c6 pop HL
ram:019f4d d7 ret
ram:01aa82 c7 push HL
ram:01aa83 c1 push AX
ram:01aa84 2004 subw SP,0x4
ram:01aa86 fbf8ff movw HL,!0xffff8
ram:01aa89 8c04 mov A,[HL + 0x4]
ram:01aa8b 4c80 cmp A,#0x80
ram:01aa8d df0f bnz $ 0x1aa9e
ram:01aa8f 8f8e55 mov A,!0xf558e
ram:01aa92 9b mov [HL],A
ram:01aa93 9c02 mov [HL + 0x2],A
ram:01aa95 8f8f55 mov A,!0xf558f
ram:01aa98 9c01 mov [HL + 0x1],A
ram:01aa9a 9c03 mov [HL + 0x3],A
ram:01aa9c ef4e br $ 0x1aaec
ram:01aa9e 8c04 mov A,[HL + 0x4]
ram:01aaa0 4c81 cmp A,#0x81
ram:01aaa2 dc24 bc $ 0x1aac8
ram:01aaa4 8c04 mov A,[HL + 0x4]
ram:01aaa6 2c80 sub A,#0x80
ram:01aaa8 9c04 mov [HL + 0x4],A
ram:01aaaa 3119 shl A,0x1
ram:01aaac 73 mov ,A
ram:01aaad 098e55 mov A,!0xf558e[B]
ram:01aab0 9b mov [HL],A
ram:01aab1 8c04 mov A,[HL + 0x4]
ram:01aab3 3119 shl A,0x1
ram:01aab5 81 inc 
ram:01aab6 73 mov ,A
ram:01aab7 098e55 mov A,!0xf558e[B]
ram:01aaba 9c01 mov [HL + 0x1],A
ram:01aabc 8f8e55 mov A,!0xf558e
ram:01aabf 9c02 mov [HL + 0x2],A
ram:01aac1 8f8f55 mov A,!0xf558f
ram:01aac4 9c03 mov [HL + 0x3],A
ram:01aac6 ef24 br $ 0x1aaec
ram:01aac8 5180 mov ,0x80
ram:01aaca 2e04 sub A,[HL + 0x4]
ram:01aacc 9c04 mov [HL + 0x4],A
ram:01aace 8f8e55 mov A,!0xf558e
ram:01aad1 9b mov [HL],A
ram:01aad2 8f8f55 mov A,!0xf558f
ram:01aad5 9c01 mov [HL + 0x1],A
ram:01aad7 8c04 mov A,[HL + 0x4]
ram:01aad9 3119 shl A,0x1
ram:01aadb 73 mov ,A
ram:01aadc 098e55 mov A,!0xf558e[B]
ram:01aadf 9c02 mov [HL + 0x2],A
ram:01aae1 8c04 mov A,[HL + 0x4]
ram:01aae3 3119 shl A,0x1
ram:01aae5 81 inc 
ram:01aae6 73 mov ,A
ram:01aae7 098e55 mov A,!0xf558e[B]
ram:01aaea 9c03 mov [HL + 0x3],A
ram:01aaec af04e4 movw AX,!0xfe404
ram:01aaef 320400 movw BC,0x4
ram:01aaf2 c3 push BC
ram:01aaf3 12 movw BC,AX
ram:01aaf4 17 movw AX,HL
ram:01aaf5 c1 push AX
ram:01aaf6 491200 mov A,!0xf0012[BC]
ram:01aaf9 9dd4 mov 0xffdf4,A
ram:01aafb 791000 movw AX,!0xf0010[BC]
ram:01aafe c1 push AX
ram:01aaff 8dd4 mov A,0xffdf4
ram:01ab01 9dd6 mov 0xffdf6,A
ram:01ab03 c0 pop AX
ram:01ab04 14 movw DE,AX
ram:01ab05 302510 movw AX,0x1025
ram:01ab08 320d00 movw BC,0xd
ram:01ab0b c1 push AX
ram:01ab0c 8dd6 mov A,0xffdf6
ram:01ab0e 9efc mov CS,A
ram:01ab10 c0 pop AX
ram:01ab11 61ea call DE
ram:01ab13 1004 addw SP,0x4
ram:01ab15 af04e4 movw AX,!0xfe404
ram:01ab18 320400 movw BC,0x4
ram:01ab1b c3 push BC
ram:01ab1c 12 movw BC,AX
ram:01ab1d 17 movw AX,HL
ram:01ab1e c1 push AX
ram:01ab1f 491200 mov A,!0xf0012[BC]
ram:01ab22 9dd4 mov 0xffdf4,A
ram:01ab24 791000 movw AX,!0xf0010[BC]
ram:01ab27 c1 push AX
ram:01ab28 8dd4 mov A,0xffdf4
ram:01ab2a 9dd6 mov 0xffdf6,A
ram:01ab2c c0 pop AX
ram:01ab2d 14 movw DE,AX
ram:01ab2e 302910 movw AX,0x1029
ram:01ab31 320d00 movw BC,0xd
ram:01ab34 c1 push AX
ram:01ab35 8dd6 mov A,0xffdf6
ram:01ab37 9efc mov CS,A
ram:01ab39 c0 pop AX
ram:01ab3a 61ea call DE
ram:01ab3c 1004 addw SP,0x4
ram:01ab3e 1006 addw SP,0x6
ram:01ab40 c6 pop HL
ram:01ab41 d7 ret
ram:01ab42 c7 push HL
ram:01ab43 c1 push AX
ram:01ab44 2004 subw SP,0x4
ram:01ab46 fbf8ff movw HL,!0xffff8
ram:01ab49 8c04 mov A,[HL + 0x4]
ram:01ab4b 4c80 cmp A,#0x80
ram:01ab4d df0f bnz $ 0x1ab5e
ram:01ab4f 8f9a55 mov A,!0xf559a
ram:01ab52 9b mov [HL],A
ram:01ab53 9c02 mov [HL + 0x2],A
ram:01ab55 8f9b55 mov A,!0xf559b
ram:01ab58 9c01 mov [HL + 0x1],A
ram:01ab5a 9c03 mov [HL + 0x3],A
ram:01ab5c ef4e br $ 0x1abac
ram:01ab5e 8c04 mov A,[HL + 0x4]
ram:01ab60 4c81 cmp A,#0x81
ram:01ab62 dc24 bc $ 0x1ab88
ram:01ab64 8c04 mov A,[HL + 0x4]
ram:01ab66 2c80 sub A,#0x80
ram:01ab68 9c04 mov [HL + 0x4],A
ram:01ab6a 3119 shl A,0x1
ram:01ab6c 73 mov ,A
ram:01ab6d 099a55 mov A,!0xf559a[B]
ram:01ab70 9b mov [HL],A
ram:01ab71 8c04 mov A,[HL + 0x4]
ram:01ab73 3119 shl A,0x1
ram:01ab75 81 inc 
ram:01ab76 73 mov ,A
ram:01ab77 099a55 mov A,!0xf559a[B]
ram:01ab7a 9c01 mov [HL + 0x1],A
ram:01ab7c 8f9a55 mov A,!0xf559a
ram:01ab7f 9c02 mov [HL + 0x2],A
ram:01ab81 8f9b55 mov A,!0xf559b
ram:01ab84 9c03 mov [HL + 0x3],A
ram:01ab86 ef24 br $ 0x1abac
ram:01ab88 5180 mov ,0x80
ram:01ab8a 2e04 sub A,[HL + 0x4]
ram:01ab8c 9c04 mov [HL + 0x4],A
ram:01ab8e 8f9a55 mov A,!0xf559a
ram:01ab91 9b mov [HL],A
ram:01ab92 8f9b55 mov A,!0xf559b
ram:01ab95 9c01 mov [HL + 0x1],A
ram:01ab97 8c04 mov A,[HL + 0x4]
ram:01ab99 3119 shl A,0x1
ram:01ab9b 73 mov ,A
ram:01ab9c 099a55 mov A,!0xf559a[B]
ram:01ab9f 9c02 mov [HL + 0x2],A
ram:01aba1 8c04 mov A,[HL + 0x4]
ram:01aba3 3119 shl A,0x1
ram:01aba5 81 inc 
ram:01aba6 73 mov ,A
ram:01aba7 099a55 mov A,!0xf559a[B]
ram:01abaa 9c03 mov [HL + 0x3],A
ram:01abac af04e4 movw AX,!0xfe404
ram:01abaf 320400 movw BC,0x4
ram:01abb2 c3 push BC
ram:01abb3 12 movw BC,AX
ram:01abb4 17 movw AX,HL
ram:01abb5 c1 push AX
ram:01abb6 491200 mov A,!0xf0012[BC]
ram:01abb9 9dd4 mov 0xffdf4,A
ram:01abbb 791000 movw AX,!0xf0010[BC]
ram:01abbe c1 push AX
ram:01abbf 8dd4 mov A,0xffdf4
ram:01abc1 9dd6 mov 0xffdf6,A
ram:01abc3 c0 pop AX
ram:01abc4 14 movw DE,AX
ram:01abc5 302310 movw AX,0x1023
ram:01abc8 320d00 movw BC,0xd
ram:01abcb c1 push AX
ram:01abcc 8dd6 mov A,0xffdf6
ram:01abce 9efc mov CS,A
ram:01abd0 c0 pop AX
ram:01abd1 61ea call DE
ram:01abd3 1004 addw SP,0x4
ram:01abd5 af04e4 movw AX,!0xfe404
ram:01abd8 320400 movw BC,0x4
ram:01abdb c3 push BC
ram:01abdc 12 movw BC,AX
ram:01abdd 17 movw AX,HL
ram:01abde c1 push AX
ram:01abdf 491200 mov A,!0xf0012[BC]
ram:01abe2 9dd4 mov 0xffdf4,A
ram:01abe4 791000 movw AX,!0xf0010[BC]
ram:01abe7 c1 push AX
ram:01abe8 8dd4 mov A,0xffdf4
ram:01abea 9dd6 mov 0xffdf6,A
ram:01abec c0 pop AX
ram:01abed 14 movw DE,AX
ram:01abee 302710 movw AX,0x1027
ram:01abf1 320d00 movw BC,0xd
ram:01abf4 c1 push AX
ram:01abf5 8dd6 mov A,0xffdf6
ram:01abf7 9efc mov CS,A
ram:01abf9 c0 pop AX
ram:01abfa 61ea call DE
ram:01abfc 1004 addw SP,0x4
ram:01abfe 1006 addw SP,0x6
ram:01ac00 c6 pop HL
ram:01ac01 d7 ret
ram:01ac02 c7 push HL
ram:01ac03 c1 push AX
ram:01ac04 2006 subw SP,0x6
ram:01ac06 fbf8ff movw HL,!0xffff8
ram:01ac09 8c0e mov A,[HL + 0xe]
ram:01ac0b d1 cmp0 A
ram:01ac0c df3c bnz $ 0x1ac4a
ram:01ac0e c7 push HL
ram:01ac0f 17 movw AX,HL
ram:01ac10 16 movw HL,AX
ram:01ac11 f7 clrw BC
ram:01ac12 49425b mov A,!0xf5b42[BC]
ram:01ac15 9b mov [HL],A
ram:01ac16 a3 incw BC
ram:01ac17 a7 incw HL
ram:01ac18 5106 mov ,0x6
ram:01ac1a 614a cmp A,
ram:01ac1c dff4 bnz $ 0x1ac12
ram:01ac1e c6 pop HL
ram:01ac1f af04e4 movw AX,!0xfe404
ram:01ac22 320600 movw BC,0x6
ram:01ac25 c3 push BC
ram:01ac26 12 movw BC,AX
ram:01ac27 17 movw AX,HL
ram:01ac28 c1 push AX
ram:01ac29 491200 mov A,!0xf0012[BC]
ram:01ac2c 9dd4 mov 0xffdf4,A
ram:01ac2e 791000 movw AX,!0xf0010[BC]
ram:01ac31 c1 push AX
ram:01ac32 8dd4 mov A,0xffdf4
ram:01ac34 9dd6 mov 0xffdf6,A
ram:01ac36 c0 pop AX
ram:01ac37 14 movw DE,AX
ram:01ac38 303e00 movw AX,0x3e
ram:01ac3b 320d00 movw BC,0xd
ram:01ac3e c1 push AX
ram:01ac3f 8dd6 mov A,0xffdf6
ram:01ac41 9efc mov CS,A
ram:01ac43 c0 pop AX
ram:01ac44 61ea call DE
ram:01ac46 1004 addw SP,0x4
ram:01ac48 ef3a br $ 0x1ac84
ram:01ac4a c7 push HL
ram:01ac4b 17 movw AX,HL
ram:01ac4c 16 movw HL,AX
ram:01ac4d f7 clrw BC
ram:01ac4e 49485b mov A,!0xf5b48[BC]
ram:01ac51 9b mov [HL],A
ram:01ac52 a3 incw BC
ram:01ac53 a7 incw HL
ram:01ac54 5106 mov ,0x6
ram:01ac56 614a cmp A,
ram:01ac58 dff4 bnz $ 0x1ac4e
ram:01ac5a c6 pop HL
ram:01ac5b af04e4 movw AX,!0xfe404
ram:01ac5e 320600 movw BC,0x6
ram:01ac61 c3 push BC
ram:01ac62 12 movw BC,AX
ram:01ac63 17 movw AX,HL
ram:01ac64 c1 push AX
ram:01ac65 491200 mov A,!0xf0012[BC]
ram:01ac68 9dd4 mov 0xffdf4,A
ram:01ac6a 791000 movw AX,!0xf0010[BC]
ram:01ac6d c1 push AX
ram:01ac6e 8dd4 mov A,0xffdf4
ram:01ac70 9dd6 mov 0xffdf6,A
ram:01ac72 c0 pop AX
ram:01ac73 14 movw DE,AX
ram:01ac74 303e00 movw AX,0x3e
ram:01ac77 320d00 movw BC,0xd
ram:01ac7a c1 push AX
ram:01ac7b 8dd6 mov A,0xffdf6
ram:01ac7d 9efc mov CS,A
ram:01ac7f c0 pop AX
ram:01ac80 61ea call DE
ram:01ac82 1004 addw SP,0x4
ram:01ac84 8c06 mov A,[HL + 0x6]
ram:01ac86 91 dec 
ram:01ac87 df41 bnz $ 0x1acca
ram:01ac89 c7 push HL
ram:01ac8a 17 movw AX,HL
ram:01ac8b 040400 addw AX,0x4
ram:01ac8e 16 movw HL,AX
ram:01ac8f f7 clrw BC
ram:01ac90 494e5b mov A,!0xf5b4e[BC]
ram:01ac93 9b mov [HL],A
ram:01ac94 a3 incw BC
ram:01ac95 a7 incw HL
ram:01ac96 5102 mov ,0x2
ram:01ac98 614a cmp A,
ram:01ac9a dff4 bnz $ 0x1ac90
ram:01ac9c c6 pop HL
ram:01ac9d af04e4 movw AX,!0xfe404
ram:01aca0 e7 onew BC
ram:01aca1 a3 incw BC
ram:01aca2 c3 push BC
ram:01aca3 12 movw BC,AX
ram:01aca4 17 movw AX,HL
ram:01aca5 040400 addw AX,0x4
ram:01aca8 c1 push AX
ram:01aca9 491200 mov A,!0xf0012[BC]
ram:01acac 9dd4 mov 0xffdf4,A
ram:01acae 791000 movw AX,!0xf0010[BC]
ram:01acb1 c1 push AX
ram:01acb2 8dd4 mov A,0xffdf4
ram:01acb4 9dd6 mov 0xffdf6,A
ram:01acb6 c0 pop AX
ram:01acb7 14 movw DE,AX
ram:01acb8 306d10 movw AX,0x106d
ram:01acbb 320d00 movw BC,0xd
ram:01acbe c1 push AX
ram:01acbf 8dd6 mov A,0xffdf6
ram:01acc1 9efc mov CS,A
ram:01acc3 c0 pop AX
ram:01acc4 61ea call DE
ram:01acc6 1004 addw SP,0x4
ram:01acc8 ef3f br $ 0x1ad09
ram:01acca c7 push HL
ram:01accb 17 movw AX,HL
ram:01accc 040400 addw AX,0x4
ram:01accf 16 movw HL,AX
ram:01acd0 f7 clrw BC
ram:01acd1 49505b mov A,!0xf5b50[BC]
ram:01acd4 9b mov [HL],A
ram:01acd5 a3 incw BC
ram:01acd6 a7 incw HL
ram:01acd7 5102 mov ,0x2
ram:01acd9 614a cmp A,
ram:01acdb dff4 bnz $ 0x1acd1
ram:01acdd c6 pop HL
ram:01acde af04e4 movw AX,!0xfe404
ram:01ace1 e7 onew BC
ram:01ace2 a3 incw BC
ram:01ace3 c3 push BC
ram:01ace4 12 movw BC,AX
ram:01ace5 17 movw AX,HL
ram:01ace6 040400 addw AX,0x4
ram:01ace9 c1 push AX
ram:01acea 491200 mov A,!0xf0012[BC]
ram:01aced 9dd4 mov 0xffdf4,A
ram:01acef 791000 movw AX,!0xf0010[BC]
ram:01acf2 c1 push AX
ram:01acf3 8dd4 mov A,0xffdf4
ram:01acf5 9dd6 mov 0xffdf6,A
ram:01acf7 c0 pop AX
ram:01acf8 14 movw DE,AX
ram:01acf9 306d10 movw AX,0x106d
ram:01acfc 320d00 movw BC,0xd
ram:01acff c1 push AX
ram:01ad00 8dd6 mov A,0xffdf6
ram:01ad02 9efc mov CS,A
ram:01ad04 c0 pop AX
ram:01ad05 61ea call DE
ram:01ad07 1004 addw SP,0x4
ram:01ad09 1008 addw SP,0x8
ram:01ad0b c6 pop HL
ram:01ad0c d7 ret
ram:01ad0d c7 push HL
ram:01ad0e c1 push AX
ram:01ad0f c1 push AX
ram:01ad10 fbf8ff movw HL,!0xffff8
ram:01ad13 8c02 mov A,[HL + 0x2]
ram:01ad15 91 dec 
ram:01ad16 df3b bnz $ 0x1ad53
ram:01ad18 c7 push HL
ram:01ad19 17 movw AX,HL
ram:01ad1a 16 movw HL,AX
ram:01ad1b f7 clrw BC
ram:01ad1c 49525b mov A,!0xf5b52[BC]
ram:01ad1f 9b mov [HL],A
ram:01ad20 a3 incw BC
ram:01ad21 a7 incw HL
ram:01ad22 5102 mov ,0x2
ram:01ad24 614a cmp A,
ram:01ad26 dff4 bnz $ 0x1ad1c
ram:01ad28 c6 pop HL
ram:01ad29 af04e4 movw AX,!0xfe404
ram:01ad2c e7 onew BC
ram:01ad2d a3 incw BC
ram:01ad2e c3 push BC
ram:01ad2f 12 movw BC,AX
ram:01ad30 17 movw AX,HL
ram:01ad31 c1 push AX
ram:01ad32 491200 mov A,!0xf0012[BC]
ram:01ad35 9dd4 mov 0xffdf4,A
ram:01ad37 791000 movw AX,!0xf0010[BC]
ram:01ad3a c1 push AX
ram:01ad3b 8dd4 mov A,0xffdf4
ram:01ad3d 9dd6 mov 0xffdf6,A
ram:01ad3f c0 pop AX
ram:01ad40 14 movw DE,AX
ram:01ad41 306e10 movw AX,0x106e
ram:01ad44 320d00 movw BC,0xd
ram:01ad47 c1 push AX
ram:01ad48 8dd6 mov A,0xffdf6
ram:01ad4a 9efc mov CS,A
ram:01ad4c c0 pop AX
ram:01ad4d 61ea call DE
ram:01ad4f 1004 addw SP,0x4
ram:01ad51 ef39 br $ 0x1ad8c
ram:01ad53 c7 push HL
ram:01ad54 17 movw AX,HL
ram:01ad55 16 movw HL,AX
ram:01ad56 f7 clrw BC
ram:01ad57 49545b mov A,!0xf5b54[BC]
ram:01ad5a 9b mov [HL],A
ram:01ad5b a3 incw BC
ram:01ad5c a7 incw HL
ram:01ad5d 5102 mov ,0x2
ram:01ad5f 614a cmp A,
ram:01ad61 dff4 bnz $ 0x1ad57
ram:01ad63 c6 pop HL
ram:01ad64 af04e4 movw AX,!0xfe404
ram:01ad67 e7 onew BC
ram:01ad68 a3 incw BC
ram:01ad69 c3 push BC
ram:01ad6a 12 movw BC,AX
ram:01ad6b 17 movw AX,HL
ram:01ad6c c1 push AX
ram:01ad6d 491200 mov A,!0xf0012[BC]
ram:01ad70 9dd4 mov 0xffdf4,A
ram:01ad72 791000 movw AX,!0xf0010[BC]
ram:01ad75 c1 push AX
ram:01ad76 8dd4 mov A,0xffdf4
ram:01ad78 9dd6 mov 0xffdf6,A
ram:01ad7a c0 pop AX
ram:01ad7b 14 movw DE,AX
ram:01ad7c 306e10 movw AX,0x106e
ram:01ad7f 320d00 movw BC,0xd
ram:01ad82 c1 push AX
ram:01ad83 8dd6 mov A,0xffdf6
ram:01ad85 9efc mov CS,A
ram:01ad87 c0 pop AX
ram:01ad88 61ea call DE
ram:01ad8a 1004 addw SP,0x4
ram:01ad8c 1004 addw SP,0x4
ram:01ad8e c6 pop HL
ram:01ad8f d7 ret
ram:01ad90 c7 push HL
ram:01ad91 8806 mov A,[SP + 0x6]
ram:01ad93 16 movw HL,AX
ram:01ad94 66 mov A,
ram:01ad95 91 dec 
ram:01ad96 df06 bnz $ 0x1ad9e
ram:01ad98 714096e8 set1 !0xfe896.0x4
ram:01ad9c ef04 br $ 0x1ada2
ram:01ad9e 714896e8 clr1 !0xfe896.0x4
ram:01ada2 af96e8 movw AX,!0xfe896
ram:01ada5 315d shlw AX,0x5
ram:01ada7 31ae shrw AX,0xa
ram:01ada9 6168 or A,
ram:01adab df0c bnz $ 0x1adb9
ram:01adad 67 mov A,
ram:01adae 318e shrw AX,0x8
ram:01adb0 c1 push AX
ram:01adb1 e6 onew AX
ram:01adb2 fc02ac01 call !!0x1ac02
ram:01adb6 c0 pop AX
ram:01adb7 ef0b br $ 0x1adc4
ram:01adb9 67 mov A,
ram:01adba 318e shrw AX,0x8
ram:01adbc c1 push AX
ram:01adbd 17 movw AX,HL
ram:01adbe f1 clrb A
ram:01adbf fc02ac01 call !!0x1ac02
ram:01adc3 c0 pop AX
ram:01adc4 c6 pop HL
ram:01adc5 d7 ret
ram:01adc6 c7 push HL
ram:01adc7 c1 push AX
ram:01adc8 2012 subw SP,0x12
ram:01adca fbf8ff movw HL,!0xffff8
ram:01adcd 8f97e8 mov A,!0xfe897
ram:01add0 31333d bt A.0x3,$ 0x1ae0f
ram:01add3 8c12 mov A,[HL + 0x12]
ram:01add5 91 dec 
ram:01add6 df38 bnz $ 0x1ae10
ram:01add8 af04e4 movw AX,!0xfe404
ram:01addb e7 onew BC
ram:01addc a3 incw BC
ram:01addd c3 push BC
ram:01adde 12 movw BC,AX
ram:01addf af96e8 movw AX,!0xfe896
ram:01ade2 315d shlw AX,0x5
ram:01ade4 31ae shrw AX,0xa
ram:01ade6 01 addw AX,AX
ram:01ade7 04c655 addw AX,0x55c6
ram:01adea c1 push AX
ram:01adeb 491200 mov A,!0xf0012[BC]
ram:01adee 9dd4 mov 0xffdf4,A
ram:01adf0 791000 movw AX,!0xf0010[BC]
ram:01adf3 c1 push AX
ram:01adf4 8dd4 mov A,0xffdf4
ram:01adf6 9dd6 mov 0xffdf6,A
ram:01adf8 c0 pop AX
ram:01adf9 14 movw DE,AX
ram:01adfa 30fb12 movw AX,0x12fb
ram:01adfd 320d00 movw BC,0xd
ram:01ae00 c1 push AX
ram:01ae01 8dd6 mov A,0xffdf6
ram:01ae03 9efc mov CS,A
ram:01ae05 c0 pop AX
ram:01ae06 61ea call DE
ram:01ae08 1004 addw SP,0x4
ram:01ae0a 713097e8 set1 !0xfe897.0x3
ram:01ae0e ef33 br $ 0x1ae43
ram:01ae10 8f97e8 mov A,!0xfe897
ram:01ae13 31352d bf A.0x3,$ 0x1ae42
ram:01ae16 8c12 mov A,[HL + 0x12]
ram:01ae18 d1 cmp0 A
ram:01ae19 df28 bnz $ 0x1ae43
ram:01ae1b c7 push HL
ram:01ae1c 17 movw AX,HL
ram:01ae1d 16 movw HL,AX
ram:01ae1e f7 clrw BC
ram:01ae1f 49565b mov A,!0xf5b56[BC]
ram:01ae22 9b mov [HL],A
ram:01ae23 a3 incw BC
ram:01ae24 a7 incw HL
ram:01ae25 5112 mov ,0x12
ram:01ae27 614a cmp A,
ram:01ae29 dff4 bnz $ 0x1ae1f
ram:01ae2b c6 pop HL
ram:01ae2c db04e4 movw BC,!0xfe404
ram:01ae2f 17 movw AX,HL
ram:01ae30 c1 push AX
ram:01ae31 490e00 mov A,!0xf000e[BC]
ram:01ae34 9efc mov CS,A
ram:01ae36 790c00 movw AX,!0xf000c[BC]
ram:01ae39 14 movw DE,AX
ram:01ae3a e6 onew AX
ram:01ae3b a1 incw AX
ram:01ae3c 61ea call DE
ram:01ae3e c0 pop AX
ram:01ae3f 713897e8 clr1 !0xfe897.0x3
ram:01ae43 1014 addw SP,0x14
ram:01ae45 c6 pop HL
ram:01ae46 d7 ret
ram:01ae47 c7 push HL
ram:01ae48 af04e4 movw AX,!0xfe404
ram:01ae4b e7 onew BC
ram:01ae4c a3 incw BC
ram:01ae4d c3 push BC
ram:01ae4e 12 movw BC,AX
ram:01ae4f 8f98e8 mov A,!0xfe898
ram:01ae52 5c0f and A,#0xf
ram:01ae54 3119 shl A,0x1
ram:01ae56 74 mov ,A
ram:01ae57 af96e8 movw AX,!0xfe896
ram:01ae5a 315d shlw AX,0x5
ram:01ae5c 31ae shrw AX,0xa
ram:01ae5e 040656 addw AX,0x5606
ram:01ae61 16 movw HL,AX
ram:01ae62 8b mov A,[HL]
ram:01ae63 5016 mov ,0x16
ram:01ae65 d6 mulu X
ram:01ae66 044656 addw AX,0x5646
ram:01ae69 16 movw HL,AX
ram:01ae6a 5500 mov ,0x0
ram:01ae6c 15 movw AX,DE
ram:01ae6d 07 addw AX,HL
ram:01ae6e c1 push AX
ram:01ae6f 491200 mov A,!0xf0012[BC]
ram:01ae72 9dd4 mov 0xffdf4,A
ram:01ae74 791000 movw AX,!0xf0010[BC]
ram:01ae77 c1 push AX
ram:01ae78 8dd4 mov A,0xffdf4
ram:01ae7a 9dd7 mov 0xffdf7,A
ram:01ae7c c0 pop AX
ram:01ae7d 16 movw HL,AX
ram:01ae7e 302514 movw AX,0x1425
ram:01ae81 320d00 movw BC,0xd
ram:01ae84 c1 push AX
ram:01ae85 8dd7 mov A,0xffdf7
ram:01ae87 9efc mov CS,A
ram:01ae89 c0 pop AX
ram:01ae8a 61fa call HL
ram:01ae8c 1004 addw SP,0x4
ram:01ae8e c6 pop HL
ram:01ae8f d7 ret
ram:01ae90 c7 push HL
ram:01ae91 2004 subw SP,0x4
ram:01ae93 fbf8ff movw HL,!0xffff8
ram:01ae96 af04e4 movw AX,!0xfe404
ram:01ae99 320e00 movw BC,0xe
ram:01ae9c c3 push BC
ram:01ae9d 12 movw BC,AX
ram:01ae9e 8f98e8 mov A,!0xfe898
ram:01aea1 31ce shrw AX,0xc
ram:01aea3 14 movw DE,AX
ram:01aea4 314d shlw AX,0x4
ram:01aea6 25 subw AX,DE
ram:01aea7 25 subw AX,DE
ram:01aea8 04ca56 addw AX,0x56ca
ram:01aeab c1 push AX
ram:01aeac 491200 mov A,!0xf0012[BC]
ram:01aeaf 9dd4 mov 0xffdf4,A
ram:01aeb1 791000 movw AX,!0xf0010[BC]
ram:01aeb4 c1 push AX
ram:01aeb5 8dd4 mov A,0xffdf4
ram:01aeb7 9dd6 mov 0xffdf6,A
ram:01aeb9 c0 pop AX
ram:01aeba 14 movw DE,AX
ram:01aebb 300010 movw AX,0x1000
ram:01aebe 320d00 movw BC,0xd
ram:01aec1 c1 push AX
ram:01aec2 8dd6 mov A,0xffdf6
ram:01aec4 9efc mov CS,A
ram:01aec6 c0 pop AX
ram:01aec7 61ea call DE
ram:01aec9 1004 addw SP,0x4
ram:01aecb c7 push HL
ram:01aecc 17 movw AX,HL
ram:01aecd a1 incw AX
ram:01aece 16 movw HL,AX
ram:01aecf f7 clrw BC
ram:01aed0 49685b mov A,!0xf5b68[BC]
ram:01aed3 9b mov [HL],A
ram:01aed4 a3 incw BC
ram:01aed5 a7 incw HL
ram:01aed6 5103 mov ,0x3
ram:01aed8 614a cmp A,
ram:01aeda dff4 bnz $ 0x1aed0
ram:01aedc c6 pop HL
ram:01aedd af04e4 movw AX,!0xfe404
ram:01aee0 320300 movw BC,0x3
ram:01aee3 c3 push BC
ram:01aee4 12 movw BC,AX
ram:01aee5 17 movw AX,HL
ram:01aee6 a1 incw AX
ram:01aee7 c1 push AX
ram:01aee8 491200 mov A,!0xf0012[BC]
ram:01aeeb 9dd4 mov 0xffdf4,A
ram:01aeed 791000 movw AX,!0xf0010[BC]
ram:01aef0 c1 push AX
ram:01aef1 8dd4 mov A,0xffdf4
ram:01aef3 9dd6 mov 0xffdf6,A
ram:01aef5 c0 pop AX
ram:01aef6 14 movw DE,AX
ram:01aef7 306e00 movw AX,0x6e
ram:01aefa 320d00 movw BC,0xd
ram:01aefd c1 push AX
ram:01aefe 8dd6 mov A,0xffdf6
ram:01af00 9efc mov CS,A
ram:01af02 c0 pop AX
ram:01af03 61ea call DE
ram:01af05 1004 addw SP,0x4
ram:01af07 c7 push HL
ram:01af08 17 movw AX,HL
ram:01af09 a1 incw AX
ram:01af0a 16 movw HL,AX
ram:01af0b f7 clrw BC
ram:01af0c 496c5b mov A,!0xf5b6c[BC]
ram:01af0f 9b mov [HL],A
ram:01af10 a3 incw BC
ram:01af11 a7 incw HL
ram:01af12 5103 mov ,0x3
ram:01af14 614a cmp A,
ram:01af16 dff4 bnz $ 0x1af0c
ram:01af18 c6 pop HL
ram:01af19 af04e4 movw AX,!0xfe404
ram:01af1c 320300 movw BC,0x3
ram:01af1f c3 push BC
ram:01af20 12 movw BC,AX
ram:01af21 17 movw AX,HL
ram:01af22 a1 incw AX
ram:01af23 c1 push AX
ram:01af24 491200 mov A,!0xf0012[BC]
ram:01af27 9dd4 mov 0xffdf4,A
ram:01af29 791000 movw AX,!0xf0010[BC]
ram:01af2c c1 push AX
ram:01af2d 8dd4 mov A,0xffdf4
ram:01af2f 9dd6 mov 0xffdf6,A
ram:01af31 c0 pop AX
ram:01af32 14 movw DE,AX
ram:01af33 306f00 movw AX,0x6f
ram:01af36 320d00 movw BC,0xd
ram:01af39 c1 push AX
ram:01af3a 8dd6 mov A,0xffdf6
ram:01af3c 9efc mov CS,A
ram:01af3e c0 pop AX
ram:01af3f 61ea call DE
ram:01af41 1004 addw SP,0x4
ram:01af43 1004 addw SP,0x4
ram:01af45 c6 pop HL
ram:01af46 d7 ret
ram:01af47 c7 push HL
ram:01af48 2004 subw SP,0x4
ram:01af4a fbf8ff movw HL,!0xffff8
ram:01af4d af96e8 movw AX,!0xfe896
ram:01af50 315d shlw AX,0x5
ram:01af52 31ae shrw AX,0xa
ram:01af54 12 movw BC,AX
ram:01af55 492656 mov A,!0xf5626[BC]
ram:01af58 9c03 mov [HL + 0x3],A
ram:01af5a 500b mov ,0xb
ram:01af5c d6 mulu X
ram:01af5d 04e857 addw AX,0x57e8
ram:01af60 14 movw DE,AX
ram:01af61 8f99e8 mov A,!0xfe899
ram:01af64 5c0f and A,#0xf
ram:01af66 318e shrw AX,0x8
ram:01af68 05 addw AX,DE
ram:01af69 14 movw DE,AX
ram:01af6a 89 mov A,[DE]
ram:01af6b 9c02 mov [HL + 0x2],A
ram:01af6d af04e4 movw AX,!0xfe404
ram:01af70 520c mov ,0xc
ram:01af72 c3 push BC
ram:01af73 12 movw BC,AX
ram:01af74 8c02 mov A,[HL + 0x2]
ram:01af76 500c mov ,0xc
ram:01af78 d6 mulu X
ram:01af79 046457 addw AX,0x5764
ram:01af7c c1 push AX
ram:01af7d 491200 mov A,!0xf0012[BC]
ram:01af80 9dd4 mov 0xffdf4,A
ram:01af82 791000 movw AX,!0xf0010[BC]
ram:01af85 c1 push AX
ram:01af86 8dd4 mov A,0xffdf4
ram:01af88 9dd6 mov 0xffdf6,A
ram:01af8a c0 pop AX
ram:01af8b 14 movw DE,AX
ram:01af8c 300010 movw AX,0x1000
ram:01af8f 320d00 movw BC,0xd
ram:01af92 c1 push AX
ram:01af93 8dd6 mov A,0xffdf6
ram:01af95 9efc mov CS,A
ram:01af97 c0 pop AX
ram:01af98 61ea call DE
ram:01af9a 1004 addw SP,0x4
ram:01af9c c7 push HL
ram:01af9d 17 movw AX,HL
ram:01af9e a1 incw AX
ram:01af9f 16 movw HL,AX
ram:01afa0 f7 clrw BC
ram:01afa1 49705b mov A,!0xf5b70[BC]
ram:01afa4 9b mov [HL],A
ram:01afa5 a3 incw BC
ram:01afa6 a7 incw HL
ram:01afa7 5103 mov ,0x3
ram:01afa9 614a cmp A,
ram:01afab dff4 bnz $ 0x1afa1
ram:01afad c6 pop HL
ram:01afae af04e4 movw AX,!0xfe404
ram:01afb1 320300 movw BC,0x3
ram:01afb4 c3 push BC
ram:01afb5 12 movw BC,AX
ram:01afb6 17 movw AX,HL
ram:01afb7 a1 incw AX
ram:01afb8 c1 push AX
ram:01afb9 491200 mov A,!0xf0012[BC]
ram:01afbc 9dd4 mov 0xffdf4,A
ram:01afbe 791000 movw AX,!0xf0010[BC]
ram:01afc1 c1 push AX
ram:01afc2 8dd4 mov A,0xffdf4
ram:01afc4 9dd6 mov 0xffdf6,A
ram:01afc6 c0 pop AX
ram:01afc7 14 movw DE,AX
ram:01afc8 306e00 movw AX,0x6e
ram:01afcb 320d00 movw BC,0xd
ram:01afce c1 push AX
ram:01afcf 8dd6 mov A,0xffdf6
ram:01afd1 9efc mov CS,A
ram:01afd3 c0 pop AX
ram:01afd4 61ea call DE
ram:01afd6 1004 addw SP,0x4
ram:01afd8 c7 push HL
ram:01afd9 17 movw AX,HL
ram:01afda a1 incw AX
ram:01afdb 16 movw HL,AX
ram:01afdc f7 clrw BC
ram:01afdd 49745b mov A,!0xf5b74[BC]
ram:01afe0 9b mov [HL],A
ram:01afe1 a3 incw BC
ram:01afe2 a7 incw HL
ram:01afe3 5103 mov ,0x3
ram:01afe5 614a cmp A,
ram:01afe7 dff4 bnz $ 0x1afdd
ram:01afe9 c6 pop HL
ram:01afea af04e4 movw AX,!0xfe404
ram:01afed 320300 movw BC,0x3
ram:01aff0 c3 push BC
ram:01aff1 12 movw BC,AX
ram:01aff2 17 movw AX,HL
ram:01aff3 a1 incw AX
ram:01aff4 c1 push AX
ram:01aff5 491200 mov A,!0xf0012[BC]
ram:01aff8 9dd4 mov 0xffdf4,A
ram:01affa 791000 movw AX,!0xf0010[BC]
ram:01affd c1 push AX
ram:01affe 8dd4 mov A,0xffdf4
ram:01b000 9dd6 mov 0xffdf6,A
ram:01b002 c0 pop AX
ram:01b003 14 movw DE,AX
ram:01b004 306f00 movw AX,0x6f
ram:01b007 320d00 movw BC,0xd
ram:01b00a c1 push AX
ram:01b00b 8dd6 mov A,0xffdf6
ram:01b00d 9efc mov CS,A
ram:01b00f c0 pop AX
ram:01b010 61ea call DE
ram:01b012 1004 addw SP,0x4
ram:01b014 1004 addw SP,0x4
ram:01b016 c6 pop HL
ram:01b017 d7 ret
ram:01b018 c7 push HL
ram:01b019 16 movw HL,AX
ram:01b01a 66 mov A,
ram:01b01b 4c20 cmp A,#0x20
ram:01b01d 61c8 skc
ram:01b01f ee4c01 _br $! 0x1b16e
ram:01b022 d1 cmp0 A
ram:01b023 61e8 skz
ram:01b025 eea500 _br $! 0x1b0cd
ram:01b028 f6 clrw AX
ram:01b029 c1 push AX
ram:01b02a e6 onew AX
ram:01b02b fc02ac01 call !!0x1ac02
ram:01b02f c0 pop AX
ram:01b030 17 movw AX,HL
ram:01b031 f1 clrb A
ram:01b032 31ad shlw AX,0xa
ram:01b034 31ae shrw AX,0xa
ram:01b036 315d shlw AX,0x5
ram:01b038 12 movw BC,AX
ram:01b039 af96e8 movw AX,!0xfe896
ram:01b03c 5cf8 and A,#0xf8
ram:01b03e 08 xch A,X
ram:01b03f 5c1f and A,#0x1f
ram:01b041 08 xch A,X
ram:01b042 03 addw AX,BC
ram:01b043 bf96e8 movw !0xfe896,AX
ram:01b046 66 mov A,
ram:01b047 73 mov ,A
ram:01b048 09a655 mov A,!0xf55a6[B]
ram:01b04b 70 mov ,A
ram:01b04c 8f97e8 mov A,!0xfe897
ram:01b04f 314a shr A,0x4
ram:01b051 6108 add A,
ram:01b053 77 mov ,A
ram:01b054 6101 add ,A
ram:01b056 61f3 sknh
ram:01b058 5700 _mov ,0x0
ram:01b05a af04e4 movw AX,!0xfe404
ram:01b05d 320400 movw BC,0x4
ram:01b060 c3 push BC
ram:01b061 c1 push AX
ram:01b062 67 mov A,
ram:01b063 318f sarw AX,0x8
ram:01b065 fc5cb901 call !!0x1b95c
ram:01b069 c0 pop AX
ram:01b06a c3 push BC
ram:01b06b 14 movw DE,AX
ram:01b06c 8a12 mov A,[DE + 0x12]
ram:01b06e 9dd4 mov 0xffdf4,A
ram:01b070 aa10 movw AX,[DE + 0x10]
ram:01b072 c1 push AX
ram:01b073 8dd4 mov A,0xffdf4
ram:01b075 9dd6 mov 0xffdf6,A
ram:01b077 c0 pop AX
ram:01b078 14 movw DE,AX
ram:01b079 305010 movw AX,0x1050
ram:01b07c 320d00 movw BC,0xd
ram:01b07f c1 push AX
ram:01b080 8dd6 mov A,0xffdf6
ram:01b082 9efc mov CS,A
ram:01b084 c0 pop AX
ram:01b085 61ea call DE
ram:01b087 1004 addw SP,0x4
ram:01b089 8f97e8 mov A,!0xfe897
ram:01b08c 31352f bf A.0x3,$ 0x1b0bd
ram:01b08f af04e4 movw AX,!0xfe404
ram:01b092 e7 onew BC
ram:01b093 a3 incw BC
ram:01b094 c3 push BC
ram:01b095 12 movw BC,AX
ram:01b096 66 mov A,
ram:01b097 3119 shl A,0x1
ram:01b099 318e shrw AX,0x8
ram:01b09b 04c655 addw AX,0x55c6
ram:01b09e c1 push AX
ram:01b09f 491200 mov A,!0xf0012[BC]
ram:01b0a2 9dd4 mov 0xffdf4,A
ram:01b0a4 791000 movw AX,!0xf0010[BC]
ram:01b0a7 c1 push AX
ram:01b0a8 8dd4 mov A,0xffdf4
ram:01b0aa 9dd6 mov 0xffdf6,A
ram:01b0ac c0 pop AX
ram:01b0ad 14 movw DE,AX
ram:01b0ae 30fb12 movw AX,0x12fb
ram:01b0b1 320d00 movw BC,0xd
ram:01b0b4 c1 push AX
ram:01b0b5 8dd6 mov A,0xffdf6
ram:01b0b7 9efc mov CS,A
ram:01b0b9 c0 pop AX
ram:01b0ba 61ea call DE
ram:01b0bc 1004 addw SP,0x4
ram:01b0be fc47ae01 call !!0x1ae47
ram:01b0c2 fc90ae01 call !!0x1ae90
ram:01b0c6 fc47af01 call !!0x1af47
ram:01b0ca eea100 br $! 0x1b16e
ram:01b0cd f6 clrw AX
ram:01b0ce c1 push AX
ram:01b0cf fc02ac01 call !!0x1ac02
ram:01b0d3 c0 pop AX
ram:01b0d4 17 movw AX,HL
ram:01b0d5 f1 clrb A
ram:01b0d6 31ad shlw AX,0xa
ram:01b0d8 31ae shrw AX,0xa
ram:01b0da 315d shlw AX,0x5
ram:01b0dc 12 movw BC,AX
ram:01b0dd af96e8 movw AX,!0xfe896
ram:01b0e0 5cf8 and A,#0xf8
ram:01b0e2 08 xch A,X
ram:01b0e3 5c1f and A,#0x1f
ram:01b0e5 08 xch A,X
ram:01b0e6 03 addw AX,BC
ram:01b0e7 bf96e8 movw !0xfe896,AX
ram:01b0ea 66 mov A,
ram:01b0eb 73 mov ,A
ram:01b0ec 09a655 mov A,!0xf55a6[B]
ram:01b0ef 70 mov ,A
ram:01b0f0 8f97e8 mov A,!0xfe897
ram:01b0f3 314a shr A,0x4
ram:01b0f5 6108 add A,
ram:01b0f7 77 mov ,A
ram:01b0f8 6101 add ,A
ram:01b0fa 61f3 sknh
ram:01b0fc 5700 _mov ,0x0
ram:01b0fe af04e4 movw AX,!0xfe404
ram:01b101 320400 movw BC,0x4
ram:01b104 c3 push BC
ram:01b105 c1 push AX
ram:01b106 67 mov A,
ram:01b107 318f sarw AX,0x8
ram:01b109 fc5cb901 call !!0x1b95c
ram:01b10d c0 pop AX
ram:01b10e c3 push BC
ram:01b10f 14 movw DE,AX
ram:01b110 8a12 mov A,[DE + 0x12]
ram:01b112 9dd4 mov 0xffdf4,A
ram:01b114 aa10 movw AX,[DE + 0x10]
ram:01b116 c1 push AX
ram:01b117 8dd4 mov A,0xffdf4
ram:01b119 9dd6 mov 0xffdf6,A
ram:01b11b c0 pop AX
ram:01b11c 14 movw DE,AX
ram:01b11d 305010 movw AX,0x1050
ram:01b120 320d00 movw BC,0xd
ram:01b123 c1 push AX
ram:01b124 8dd6 mov A,0xffdf6
ram:01b126 9efc mov CS,A
ram:01b128 c0 pop AX
ram:01b129 61ea call DE
ram:01b12b 1004 addw SP,0x4
ram:01b12d 8f97e8 mov A,!0xfe897
ram:01b130 31352f bf A.0x3,$ 0x1b161
ram:01b133 af04e4 movw AX,!0xfe404
ram:01b136 e7 onew BC
ram:01b137 a3 incw BC
ram:01b138 c3 push BC
ram:01b139 12 movw BC,AX
ram:01b13a 66 mov A,
ram:01b13b 3119 shl A,0x1
ram:01b13d 318e shrw AX,0x8
ram:01b13f 04c655 addw AX,0x55c6
ram:01b142 c1 push AX
ram:01b143 491200 mov A,!0xf0012[BC]
ram:01b146 9dd4 mov 0xffdf4,A
ram:01b148 791000 movw AX,!0xf0010[BC]
ram:01b14b c1 push AX
ram:01b14c 8dd4 mov A,0xffdf4
ram:01b14e 9dd6 mov 0xffdf6,A
ram:01b150 c0 pop AX
ram:01b151 14 movw DE,AX
ram:01b152 30fb12 movw AX,0x12fb
ram:01b155 320d00 movw BC,0xd
ram:01b158 c1 push AX
ram:01b159 8dd6 mov A,0xffdf6
ram:01b15b 9efc mov CS,A
ram:01b15d c0 pop AX
ram:01b15e 61ea call DE
ram:01b160 1004 addw SP,0x4
ram:01b162 fc47ae01 call !!0x1ae47
ram:01b166 fc90ae01 call !!0x1ae90
ram:01b16a fc47af01 call !!0x1af47
ram:01b16e c6 pop HL
ram:01b16f d7 ret
ram:01b170 c7 push HL
ram:01b171 c1 push AX
ram:01b172 2004 subw SP,0x4
ram:01b174 fbf8ff movw HL,!0xffff8
ram:01b177 8c04 mov A,[HL + 0x4]
ram:01b179 5c3f and A,#0x3f
ram:01b17b 349ae8 movw DE,0xe89a
ram:01b17e 70 mov ,A
ram:01b17f 89 mov A,[DE]
ram:01b180 5cc0 and A,#0xc0
ram:01b182 6168 or A,
ram:01b184 99 mov [DE],A
ram:01b185 5c3f and A,#0x3f
ram:01b187 df42 bnz $ 0x1b1cb
ram:01b189 c7 push HL
ram:01b18a 17 movw AX,HL
ram:01b18b a1 incw AX
ram:01b18c 16 movw HL,AX
ram:01b18d f7 clrw BC
ram:01b18e 49785b mov A,!0xf5b78[BC]
ram:01b191 9b mov [HL],A
ram:01b192 a3 incw BC
ram:01b193 a7 incw HL
ram:01b194 5102 mov ,0x2
ram:01b196 614a cmp A,
ram:01b198 dff4 bnz $ 0x1b18e
ram:01b19a c6 pop HL
ram:01b19b af04e4 movw AX,!0xfe404
ram:01b19e e7 onew BC
ram:01b19f a3 incw BC
ram:01b1a0 c3 push BC
ram:01b1a1 12 movw BC,AX
ram:01b1a2 17 movw AX,HL
ram:01b1a3 a1 incw AX
ram:01b1a4 c1 push AX
ram:01b1a5 491200 mov A,!0xf0012[BC]
ram:01b1a8 9dd4 mov 0xffdf4,A
ram:01b1aa 791000 movw AX,!0xf0010[BC]
ram:01b1ad c1 push AX
ram:01b1ae 8dd4 mov A,0xffdf4
ram:01b1b0 9dd6 mov 0xffdf6,A
ram:01b1b2 c0 pop AX
ram:01b1b3 14 movw DE,AX
ram:01b1b4 306f10 movw AX,0x106f
ram:01b1b7 320d00 movw BC,0xd
ram:01b1ba c1 push AX
ram:01b1bb 8dd6 mov A,0xffdf6
ram:01b1bd 9efc mov CS,A
ram:01b1bf c0 pop AX
ram:01b1c0 61ea call DE
ram:01b1c2 1004 addw SP,0x4
ram:01b1c4 71409be8 set1 !0xfe89b.0x4
ram:01b1c8 ee8b00 br $! 0x1b256
ram:01b1cb 8c04 mov A,[HL + 0x4]
ram:01b1cd 73 mov ,A
ram:01b1ce 09a655 mov A,!0xf55a6[B]
ram:01b1d1 70 mov ,A
ram:01b1d2 8f97e8 mov A,!0xfe897
ram:01b1d5 314a shr A,0x4
ram:01b1d7 6108 add A,
ram:01b1d9 9c03 mov [HL + 0x3],A
ram:01b1db 6101 add ,A
ram:01b1dd 61f3 sknh
ram:01b1df cc0300 _mov [HL + 0x3],0x0
ram:01b1e2 af04e4 movw AX,!0xfe404
ram:01b1e5 e7 onew BC
ram:01b1e6 a3 incw BC
ram:01b1e7 c3 push BC
ram:01b1e8 c1 push AX
ram:01b1e9 8c03 mov A,[HL + 0x3]
ram:01b1eb 318f sarw AX,0x8
ram:01b1ed fc422f02 call !!0x22f42
ram:01b1f1 c0 pop AX
ram:01b1f2 c3 push BC
ram:01b1f3 14 movw DE,AX
ram:01b1f4 8a12 mov A,[DE + 0x12]
ram:01b1f6 9dd4 mov 0xffdf4,A
ram:01b1f8 aa10 movw AX,[DE + 0x10]
ram:01b1fa c1 push AX
ram:01b1fb 8dd4 mov A,0xffdf4
ram:01b1fd 9dd6 mov 0xffdf6,A
ram:01b1ff c0 pop AX
ram:01b200 14 movw DE,AX
ram:01b201 304e10 movw AX,0x104e
ram:01b204 320d00 movw BC,0xd
ram:01b207 c1 push AX
ram:01b208 8dd6 mov A,0xffdf6
ram:01b20a 9efc mov CS,A
ram:01b20c c0 pop AX
ram:01b20d 61ea call DE
ram:01b20f 1004 addw SP,0x4
ram:01b211 8f9be8 mov A,!0xfe89b
ram:01b214 31453f bf A.0x4,$ 0x1b255
ram:01b217 c7 push HL
ram:01b218 17 movw AX,HL
ram:01b219 a1 incw AX
ram:01b21a 16 movw HL,AX
ram:01b21b f7 clrw BC
ram:01b21c 497a5b mov A,!0xf5b7a[BC]
ram:01b21f 9b mov [HL],A
ram:01b220 a3 incw BC
ram:01b221 a7 incw HL
ram:01b222 5102 mov ,0x2
ram:01b224 614a cmp A,
ram:01b226 dff4 bnz $ 0x1b21c
ram:01b228 c6 pop HL
ram:01b229 af04e4 movw AX,!0xfe404
ram:01b22c e7 onew BC
ram:01b22d a3 incw BC
ram:01b22e c3 push BC
ram:01b22f 12 movw BC,AX
ram:01b230 17 movw AX,HL
ram:01b231 a1 incw AX
ram:01b232 c1 push AX
ram:01b233 491200 mov A,!0xf0012[BC]
ram:01b236 9dd4 mov 0xffdf4,A
ram:01b238 791000 movw AX,!0xf0010[BC]
ram:01b23b c1 push AX
ram:01b23c 8dd4 mov A,0xffdf4
ram:01b23e 9dd6 mov 0xffdf6,A
ram:01b240 c0 pop AX
ram:01b241 14 movw DE,AX
ram:01b242 306f10 movw AX,0x106f
ram:01b245 320d00 movw BC,0xd
ram:01b248 c1 push AX
ram:01b249 8dd6 mov A,0xffdf6
ram:01b24b 9efc mov CS,A
ram:01b24d c0 pop AX
ram:01b24e 61ea call DE
ram:01b250 1004 addw SP,0x4
ram:01b252 71489be8 clr1 !0xfe89b.0x4
ram:01b256 1006 addw SP,0x6
ram:01b258 c6 pop HL
ram:01b259 d7 ret
ram:01b25a c7 push HL
ram:01b25b c1 push AX
ram:01b25c 2004 subw SP,0x4
ram:01b25e fbf8ff movw HL,!0xffff8
ram:01b261 8c04 mov A,[HL + 0x4]
ram:01b263 318e shrw AX,0x8
ram:01b265 31ad shlw AX,0xa
ram:01b267 31ae shrw AX,0xa
ram:01b269 316d shlw AX,0x6
ram:01b26b 12 movw BC,AX
ram:01b26c af9ae8 movw AX,!0xfe89a
ram:01b26f 5cf0 and A,#0xf0
ram:01b271 08 xch A,X
ram:01b272 5c3f and A,#0x3f
ram:01b274 08 xch A,X
ram:01b275 03 addw AX,BC
ram:01b276 bf9ae8 movw !0xfe89a,AX
ram:01b279 314d shlw AX,0x4
ram:01b27b 31ae shrw AX,0xa
ram:01b27d 6168 or A,
ram:01b27f df42 bnz $ 0x1b2c3
ram:01b281 c7 push HL
ram:01b282 17 movw AX,HL
ram:01b283 a1 incw AX
ram:01b284 16 movw HL,AX
ram:01b285 f7 clrw BC
ram:01b286 497c5b mov A,!0xf5b7c[BC]
ram:01b289 9b mov [HL],A
ram:01b28a a3 incw BC
ram:01b28b a7 incw HL
ram:01b28c 5102 mov ,0x2
ram:01b28e 614a cmp A,
ram:01b290 dff4 bnz $ 0x1b286
ram:01b292 c6 pop HL
ram:01b293 af04e4 movw AX,!0xfe404
ram:01b296 e7 onew BC
ram:01b297 a3 incw BC
ram:01b298 c3 push BC
ram:01b299 12 movw BC,AX
ram:01b29a 17 movw AX,HL
ram:01b29b a1 incw AX
ram:01b29c c1 push AX
ram:01b29d 491200 mov A,!0xf0012[BC]
ram:01b2a0 9dd4 mov 0xffdf4,A
ram:01b2a2 791000 movw AX,!0xf0010[BC]
ram:01b2a5 c1 push AX
ram:01b2a6 8dd4 mov A,0xffdf4
ram:01b2a8 9dd6 mov 0xffdf6,A
ram:01b2aa c0 pop AX
ram:01b2ab 14 movw DE,AX
ram:01b2ac 307010 movw AX,0x1070
ram:01b2af 320d00 movw BC,0xd
ram:01b2b2 c1 push AX
ram:01b2b3 8dd6 mov A,0xffdf6
ram:01b2b5 9efc mov CS,A
ram:01b2b7 c0 pop AX
ram:01b2b8 61ea call DE
ram:01b2ba 1004 addw SP,0x4
ram:01b2bc 71509be8 set1 !0xfe89b.0x5
ram:01b2c0 ee8b00 br $! 0x1b34e
ram:01b2c3 8c04 mov A,[HL + 0x4]
ram:01b2c5 73 mov ,A
ram:01b2c6 09a655 mov A,!0xf55a6[B]
ram:01b2c9 70 mov ,A
ram:01b2ca 8f97e8 mov A,!0xfe897
ram:01b2cd 314a shr A,0x4
ram:01b2cf 6108 add A,
ram:01b2d1 9c03 mov [HL + 0x3],A
ram:01b2d3 6101 add ,A
ram:01b2d5 61f3 sknh
ram:01b2d7 cc0300 _mov [HL + 0x3],0x0
ram:01b2da af04e4 movw AX,!0xfe404
ram:01b2dd e7 onew BC
ram:01b2de a3 incw BC
ram:01b2df c3 push BC
ram:01b2e0 c1 push AX
ram:01b2e1 8c03 mov A,[HL + 0x3]
ram:01b2e3 318f sarw AX,0x8
ram:01b2e5 fc422f02 call !!0x22f42
ram:01b2e9 c0 pop AX
ram:01b2ea c3 push BC
ram:01b2eb 14 movw DE,AX
ram:01b2ec 8a12 mov A,[DE + 0x12]
ram:01b2ee 9dd4 mov 0xffdf4,A
ram:01b2f0 aa10 movw AX,[DE + 0x10]
ram:01b2f2 c1 push AX
ram:01b2f3 8dd4 mov A,0xffdf4
ram:01b2f5 9dd6 mov 0xffdf6,A
ram:01b2f7 c0 pop AX
ram:01b2f8 14 movw DE,AX
ram:01b2f9 304f10 movw AX,0x104f
ram:01b2fc 320d00 movw BC,0xd
ram:01b2ff c1 push AX
ram:01b300 8dd6 mov A,0xffdf6
ram:01b302 9efc mov CS,A
ram:01b304 c0 pop AX
ram:01b305 61ea call DE
ram:01b307 1004 addw SP,0x4
ram:01b309 8f9be8 mov A,!0xfe89b
ram:01b30c 31553f bf A.0x5,$ 0x1b34d
ram:01b30f c7 push HL
ram:01b310 17 movw AX,HL
ram:01b311 a1 incw AX
ram:01b312 16 movw HL,AX
ram:01b313 f7 clrw BC
ram:01b314 497e5b mov A,!0xf5b7e[BC]
ram:01b317 9b mov [HL],A
ram:01b318 a3 incw BC
ram:01b319 a7 incw HL
ram:01b31a 5102 mov ,0x2
ram:01b31c 614a cmp A,
ram:01b31e dff4 bnz $ 0x1b314
ram:01b320 c6 pop HL
ram:01b321 af04e4 movw AX,!0xfe404
ram:01b324 e7 onew BC
ram:01b325 a3 incw BC
ram:01b326 c3 push BC
ram:01b327 12 movw BC,AX
ram:01b328 17 movw AX,HL
ram:01b329 a1 incw AX
ram:01b32a c1 push AX
ram:01b32b 491200 mov A,!0xf0012[BC]
ram:01b32e 9dd4 mov 0xffdf4,A
ram:01b330 791000 movw AX,!0xf0010[BC]
ram:01b333 c1 push AX
ram:01b334 8dd4 mov A,0xffdf4
ram:01b336 9dd6 mov 0xffdf6,A
ram:01b338 c0 pop AX
ram:01b339 14 movw DE,AX
ram:01b33a 307010 movw AX,0x1070
ram:01b33d 320d00 movw BC,0xd
ram:01b340 c1 push AX
ram:01b341 8dd6 mov A,0xffdf6
ram:01b343 9efc mov CS,A
ram:01b345 c0 pop AX
ram:01b346 61ea call DE
ram:01b348 1004 addw SP,0x4
ram:01b34a 71589be8 clr1 !0xfe89b.0x5
ram:01b34e 1006 addw SP,0x6
ram:01b350 c6 pop HL
ram:01b351 d7 ret
ram:01b352 c7 push HL
ram:01b353 16 movw HL,AX
ram:01b354 8f97e8 mov A,!0xfe897
ram:01b357 314a shr A,0x4
ram:01b359 614e cmp A,
ram:01b35b dd19 bz $ 0x1b376
ram:01b35d 66 mov A,
ram:01b35e 3149 shl A,0x4
ram:01b360 70 mov ,A
ram:01b361 8f97e8 mov A,!0xfe897
ram:01b364 5c0f and A,#0xf
ram:01b366 6168 or A,
ram:01b368 9f97e8 mov !0xfe897,A
ram:01b36b af96e8 movw AX,!0xfe896
ram:01b36e 315d shlw AX,0x5
ram:01b370 31ae shrw AX,0xa
ram:01b372 fc18b001 call !!0x1b018
ram:01b376 c6 pop HL
ram:01b377 d7 ret
ram:01b418 c7 push HL
ram:01b419 c1 push AX
ram:01b41a c1 push AX
ram:01b41b fbf8ff movw HL,!0xffff8
ram:01b41e d59ce8 cmp0 !0xfe89c
ram:01b421 dd0b bz $ 0x1b42e
ram:01b423 d99ce8 mov X,!0xfe89c
ram:01b426 f1 clrb A
ram:01b427 fc927e00 call !!0x7e92
ram:01b42b f59ce8 clrb !0xfe89c
ram:01b42e 8c02 mov A,[HL + 0x2]
ram:01b430 9f9ee8 mov !0xfe89e,A
ram:01b433 8c0a mov A,[HL + 0xa]
ram:01b435 9f9fe8 mov !0xfe89f,A
ram:01b438 cf94e802 mov !0xfe894,0x2
ram:01b43c 3078b3 movw AX,0xb378
ram:01b43f 5201 mov ,0x1
ram:01b441 f3 clrb B
ram:01b442 fc057e00 call !!0x7e05
ram:01b446 62 mov A,
ram:01b447 9f9ce8 mov !0xfe89c,A
ram:01b44a 1004 addw SP,0x4
ram:01b44c c6 pop HL
ram:01b44d d7 ret
ram:01b565 c7 push HL
ram:01b566 16 movw HL,AX
ram:01b567 66 mov A,
ram:01b568 91 dec 
ram:01b569 df26 bnz $ 0x1b591
ram:01b56b 304eb4 movw AX,0xb44e
ram:01b56e 5201 mov ,0x1
ram:01b570 f3 clrb B
ram:01b571 fc057e00 call !!0x7e05
ram:01b575 62 mov A,
ram:01b576 9f95e8 mov !0xfe895,A
ram:01b579 714096e8 set1 !0xfe896.0x4
ram:01b57d 71409be8 set1 !0xfe89b.0x4
ram:01b581 71609be8 set1 !0xfe89b.0x6
ram:01b585 e594e8 oneb !0xfe894
ram:01b588 f59ce8 clrb !0xfe89c
ram:01b58b 71709be8 set1 !0xfe89b.0x7
ram:01b58f ef18 br $ 0x1b5a9
ram:01b591 fc029d01 call !!0x19d02
ram:01b595 4094e801 cmp !0xfe894,0x1
ram:01b599 df0b bnz $ 0x1b5a6
ram:01b59b d995e8 mov X,!0xfe895
ram:01b59e f1 clrb A
ram:01b59f fc927e00 call !!0x7e92
ram:01b5a3 f595e8 clrb !0xfe895
ram:01b5a6 f594e8 clrb !0xfe894
ram:01b5a9 c6 pop HL
ram:01b5aa d7 ret
ram:01b5af 8f94e8 mov A,!0xfe894
ram:01b5b2 318f sarw AX,0x8
ram:01b5b4 12 movw BC,AX
ram:01b5b5 d7 ret
ram:01b5b6 c7 push HL
ram:01b5b7 c1 push AX
ram:01b5b8 2004 subw SP,0x4
ram:01b5ba fbf8ff movw HL,!0xffff8
ram:01b5bd 8c04 mov A,[HL + 0x4]
ram:01b5bf d1 cmp0 A
ram:01b5c0 61f8 sknz
ram:01b5c2 ee9c00 _br $! 0x1b661
ram:01b5c5 2c10 sub A,#0x10
ram:01b5c7 61f8 sknz
ram:01b5c9 eea800 _br $! 0x1b674
ram:01b5cc 91 dec 
ram:01b5cd 61f8 sknz
ram:01b5cf eead00 _br $! 0x1b67f
ram:01b5d2 91 dec 
ram:01b5d3 61f8 sknz
ram:01b5d5 eec600 _br $! 0x1b69e
ram:01b5d8 91 dec 
ram:01b5d9 61f8 sknz
ram:01b5db eef800 _br $! 0x1b6d6
ram:01b5de 91 dec 
ram:01b5df 61f8 sknz
ram:01b5e1 eeff00 _br $! 0x1b6e3
ram:01b5e4 91 dec 
ram:01b5e5 61f8 sknz
ram:01b5e7 ee0601 _br $! 0x1b6f0
ram:01b5ea 91 dec 
ram:01b5eb 61f8 sknz
ram:01b5ed ee0801 _br $! 0x1b6f8
ram:01b5f0 91 dec 
ram:01b5f1 61f8 sknz
ram:01b5f3 ee9300 _br $! 0x1b689
ram:01b5f6 91 dec 
ram:01b5f7 61f8 sknz
ram:01b5f9 ee9700 _br $! 0x1b693
ram:01b5fc 91 dec 
ram:01b5fd 61f8 sknz
ram:01b5ff eefe00 _br $! 0x1b700
ram:01b602 91 dec 
ram:01b603 61f8 sknz
ram:01b605 ee3501 _br $! 0x1b73d
ram:01b608 91 dec 
ram:01b609 61f8 sknz
ram:01b60b eebb00 _br $! 0x1b6c9
ram:01b60e 91 dec 
ram:01b60f 61f8 sknz
ram:01b611 eee601 _br $! 0x1b7fa
ram:01b614 91 dec 
ram:01b615 61f8 sknz
ram:01b617 ee2202 _br $! 0x1b83c
ram:01b61a 91 dec 
ram:01b61b 61f8 sknz
ram:01b61d ee5e02 _br $! 0x1b87e
ram:01b620 91 dec 
ram:01b621 61f8 sknz
ram:01b623 ee9902 _br $! 0x1b8bf
ram:01b626 91 dec 
ram:01b627 61f8 sknz
ram:01b629 ee4e01 _br $! 0x1b77a
ram:01b62c 91 dec 
ram:01b62d 61f8 sknz
ram:01b62f ee5501 _br $! 0x1b787
ram:01b632 91 dec 
ram:01b633 61f8 sknz
ram:01b635 ee5c01 _br $! 0x1b794
ram:01b638 91 dec 
ram:01b639 61f8 sknz
ram:01b63b ee6f01 _br $! 0x1b7ad
ram:01b63e 91 dec 
ram:01b63f 61f8 sknz
ram:01b641 ee8201 _br $! 0x1b7c6
ram:01b644 2c1c sub A,#0x1c
ram:01b646 61f8 sknz
ram:01b648 ee9501 _br $! 0x1b7e0
ram:01b64b 91 dec 
ram:01b64c 61f8 sknz
ram:01b64e eea201 _br $! 0x1b7f3
ram:01b651 2c1f sub A,#0x1f
ram:01b653 61f8 sknz
ram:01b655 eea802 _br $! 0x1b900
ram:01b658 91 dec 
ram:01b659 61f8 sknz
ram:01b65b eea802 _br $! 0x1b906
ram:01b65e eeb902 br $! 0x1b91a
ram:01b661 ac0c movw AX,[HL + 0xc]
ram:01b663 14 movw DE,AX
ram:01b664 8a01 mov A,[DE + 0x1]
ram:01b666 318e shrw AX,0x8
ram:01b668 c1 push AX
ram:01b669 89 mov A,[DE]
ram:01b66a 318e shrw AX,0x8
ram:01b66c fc18b401 call !!0x1b418
ram:01b670 c0 pop AX
ram:01b671 eea602 br $! 0x1b91a
ram:01b674 f6 clrw AX
ram:01b675 c1 push AX
ram:01b676 e6 onew AX
ram:01b677 fc90ad01 call !!0x1ad90
ram:01b67b c0 pop AX
ram:01b67c ee9b02 br $! 0x1b91a
ram:01b67f f6 clrw AX
ram:01b680 c1 push AX
ram:01b681 fc90ad01 call !!0x1ad90
ram:01b685 c0 pop AX
ram:01b686 ee9102 br $! 0x1b91a
ram:01b689 e6 onew AX
ram:01b68a c1 push AX
ram:01b68b fc90ad01 call !!0x1ad90
ram:01b68f c0 pop AX
ram:01b690 ee8702 br $! 0x1b91a
ram:01b693 e6 onew AX
ram:01b694 c1 push AX
ram:01b695 f6 clrw AX
ram:01b696 fc90ad01 call !!0x1ad90
ram:01b69a c0 pop AX
ram:01b69b ee7c02 br $! 0x1b91a
ram:01b69e 8f96e8 mov A,!0xfe896
ram:01b6a1 5c0f and A,#0xf
ram:01b6a3 4c0a cmp A,#0xa
ram:01b6a5 dd09 bz $ 0x1b6b0
ram:01b6a7 8f96e8 mov A,!0xfe896
ram:01b6aa 5c0f and A,#0xf
ram:01b6ac 4c08 cmp A,#0x8
ram:01b6ae df0c bnz $ 0x1b6bc
ram:01b6b0 ac0c movw AX,[HL + 0xc]
ram:01b6b2 14 movw DE,AX
ram:01b6b3 89 mov A,[DE]
ram:01b6b4 318e shrw AX,0x8
ram:01b6b6 fc5ab201 call !!0x1b25a
ram:01b6ba ef0a br $ 0x1b6c6
ram:01b6bc ac0c movw AX,[HL + 0xc]
ram:01b6be 14 movw DE,AX
ram:01b6bf 89 mov A,[DE]
ram:01b6c0 318e shrw AX,0x8
ram:01b6c2 fc18b001 call !!0x1b018
ram:01b6c6 ee5102 br $! 0x1b91a
ram:01b6c9 ac0c movw AX,[HL + 0xc]
ram:01b6cb 14 movw DE,AX
ram:01b6cc 89 mov A,[DE]
ram:01b6cd 318e shrw AX,0x8
ram:01b6cf fc70b101 call !!0x1b170
ram:01b6d3 ee4402 br $! 0x1b91a
ram:01b6d6 ac0c movw AX,[HL + 0xc]
ram:01b6d8 14 movw DE,AX
ram:01b6d9 89 mov A,[DE]
ram:01b6da 318e shrw AX,0x8
ram:01b6dc fcc6ad01 call !!0x1adc6
ram:01b6e0 ee3702 br $! 0x1b91a
ram:01b6e3 ac0c movw AX,[HL + 0xc]
ram:01b6e5 14 movw DE,AX
ram:01b6e6 89 mov A,[DE]
ram:01b6e7 318e shrw AX,0x8
ram:01b6e9 fc52b301 call !!0x1b352
ram:01b6ed ee2a02 br $! 0x1b91a
ram:01b6f0 e6 onew AX
ram:01b6f1 fc0dad01 call !!0x1ad0d
ram:01b6f5 ee2202 br $! 0x1b91a
ram:01b6f8 f6 clrw AX
ram:01b6f9 fc0dad01 call !!0x1ad0d
ram:01b6fd ee1a02 br $! 0x1b91a
ram:01b700 c7 push HL
ram:01b701 17 movw AX,HL
ram:01b702 16 movw HL,AX
ram:01b703 f7 clrw BC
ram:01b704 49825b mov A,!0xf5b82[BC]
ram:01b707 9b mov [HL],A
ram:01b708 a3 incw BC
ram:01b709 a7 incw HL
ram:01b70a 5104 mov ,0x4
ram:01b70c 614a cmp A,
ram:01b70e dff4 bnz $ 0x1b704
ram:01b710 c6 pop HL
ram:01b711 af04e4 movw AX,!0xfe404
ram:01b714 320400 movw BC,0x4
ram:01b717 c3 push BC
ram:01b718 12 movw BC,AX
ram:01b719 17 movw AX,HL
ram:01b71a c1 push AX
ram:01b71b 491200 mov A,!0xf0012[BC]
ram:01b71e 9dd4 mov 0xffdf4,A
ram:01b720 791000 movw AX,!0xf0010[BC]
ram:01b723 c1 push AX
ram:01b724 8dd4 mov A,0xffdf4
ram:01b726 9dd6 mov 0xffdf6,A
ram:01b728 c0 pop AX
ram:01b729 14 movw DE,AX
ram:01b72a 30cd10 movw AX,0x10cd
ram:01b72d 320d00 movw BC,0xd
ram:01b730 c1 push AX
ram:01b731 8dd6 mov A,0xffdf6
ram:01b733 9efc mov CS,A
ram:01b735 c0 pop AX
ram:01b736 61ea call DE
ram:01b738 1004 addw SP,0x4
ram:01b73a eedd01 br $! 0x1b91a
ram:01b73d c7 push HL
ram:01b73e 17 movw AX,HL
ram:01b73f 16 movw HL,AX
ram:01b740 f7 clrw BC
ram:01b741 49865b mov A,!0xf5b86[BC]
ram:01b744 9b mov [HL],A
ram:01b745 a3 incw BC
ram:01b746 a7 incw HL
ram:01b747 5104 mov ,0x4
ram:01b749 614a cmp A,
ram:01b74b dff4 bnz $ 0x1b741
ram:01b74d c6 pop HL
ram:01b74e af04e4 movw AX,!0xfe404
ram:01b751 320400 movw BC,0x4
ram:01b754 c3 push BC
ram:01b755 12 movw BC,AX
ram:01b756 17 movw AX,HL
ram:01b757 c1 push AX
ram:01b758 491200 mov A,!0xf0012[BC]
ram:01b75b 9dd4 mov 0xffdf4,A
ram:01b75d 791000 movw AX,!0xf0010[BC]
ram:01b760 c1 push AX
ram:01b761 8dd4 mov A,0xffdf4
ram:01b763 9dd6 mov 0xffdf6,A
ram:01b765 c0 pop AX
ram:01b766 14 movw DE,AX
ram:01b767 30cd10 movw AX,0x10cd
ram:01b76a 320d00 movw BC,0xd
ram:01b76d c1 push AX
ram:01b76e 8dd6 mov A,0xffdf6
ram:01b770 9efc mov CS,A
ram:01b772 c0 pop AX
ram:01b773 61ea call DE
ram:01b775 1004 addw SP,0x4
ram:01b777 eea001 br $! 0x1b91a
ram:01b77a ac0c movw AX,[HL + 0xc]
ram:01b77c 14 movw DE,AX
ram:01b77d 89 mov A,[DE]
ram:01b77e 318e shrw AX,0x8
ram:01b780 fc82aa01 call !!0x1aa82
ram:01b784 ee9301 br $! 0x1b91a
ram:01b787 ac0c movw AX,[HL + 0xc]
ram:01b789 14 movw DE,AX
ram:01b78a 89 mov A,[DE]
ram:01b78b 318e shrw AX,0x8
ram:01b78d fc42ab01 call !!0x1ab42
ram:01b791 ee8601 br $! 0x1b91a
ram:01b794 ac0c movw AX,[HL + 0xc]
ram:01b796 14 movw DE,AX
ram:01b797 89 mov A,[DE]
ram:01b798 2c7b sub A,#0x7b
ram:01b79a 5c0f and A,#0xf
ram:01b79c 3498e8 movw DE,0xe898
ram:01b79f 70 mov ,A
ram:01b7a0 89 mov A,[DE]
ram:01b7a1 5cf0 and A,#0xf0
ram:01b7a3 6168 or A,
ram:01b7a5 99 mov [DE],A
ram:01b7a6 fc47ae01 call !!0x1ae47
ram:01b7aa ee6d01 br $! 0x1b91a
ram:01b7ad ac0c movw AX,[HL + 0xc]
ram:01b7af 14 movw DE,AX
ram:01b7b0 89 mov A,[DE]
ram:01b7b1 2c7b sub A,#0x7b
ram:01b7b3 3149 shl A,0x4
ram:01b7b5 3498e8 movw DE,0xe898
ram:01b7b8 70 mov ,A
ram:01b7b9 89 mov A,[DE]
ram:01b7ba 5c0f and A,#0xf
ram:01b7bc 6168 or A,
ram:01b7be 99 mov [DE],A
ram:01b7bf fc90ae01 call !!0x1ae90
ram:01b7c3 ee5401 br $! 0x1b91a
ram:01b7c6 ac0c movw AX,[HL + 0xc]
ram:01b7c8 14 movw DE,AX
ram:01b7c9 89 mov A,[DE]
ram:01b7ca 2c7b sub A,#0x7b
ram:01b7cc 5c0f and A,#0xf
ram:01b7ce 70 mov ,A
ram:01b7cf 8f99e8 mov A,!0xfe899
ram:01b7d2 5cf0 and A,#0xf0
ram:01b7d4 6168 or A,
ram:01b7d6 9f99e8 mov !0xfe899,A
ram:01b7d9 fc47af01 call !!0x1af47
ram:01b7dd ee3a01 br $! 0x1b91a
ram:01b7e0 ac0c movw AX,[HL + 0xc]
ram:01b7e2 14 movw DE,AX
ram:01b7e3 8a01 mov A,[DE + 0x1]
ram:01b7e5 318e shrw AX,0x8
ram:01b7e7 c1 push AX
ram:01b7e8 89 mov A,[DE]
ram:01b7e9 318e shrw AX,0x8
ram:01b7eb fc299d01 call !!0x19d29
ram:01b7ef c0 pop AX
ram:01b7f0 ee2701 br $! 0x1b91a
ram:01b7f3 fc029d01 call !!0x19d02
ram:01b7f7 ee2001 br $! 0x1b91a
ram:01b7fa c7 push HL
ram:01b7fb 17 movw AX,HL
ram:01b7fc 040200 addw AX,0x2
ram:01b7ff 16 movw HL,AX
ram:01b800 f7 clrw BC
ram:01b801 498a5b mov A,!0xf5b8a[BC]
ram:01b804 9b mov [HL],A
ram:01b805 a3 incw BC
ram:01b806 a7 incw HL
ram:01b807 5102 mov ,0x2
ram:01b809 614a cmp A,
ram:01b80b dff4 bnz $ 0x1b801
ram:01b80d c6 pop HL
ram:01b80e af04e4 movw AX,!0xfe404
ram:01b811 e7 onew BC
ram:01b812 a3 incw BC
ram:01b813 c3 push BC
ram:01b814 12 movw BC,AX
ram:01b815 17 movw AX,HL
ram:01b816 040200 addw AX,0x2
ram:01b819 c1 push AX
ram:01b81a 491200 mov A,!0xf0012[BC]
ram:01b81d 9dd4 mov 0xffdf4,A
ram:01b81f 791000 movw AX,!0xf0010[BC]
ram:01b822 c1 push AX
ram:01b823 8dd4 mov A,0xffdf4
ram:01b825 9dd6 mov 0xffdf6,A
ram:01b827 c0 pop AX
ram:01b828 14 movw DE,AX
ram:01b829 308d10 movw AX,0x108d
ram:01b82c 320d00 movw BC,0xd
ram:01b82f c1 push AX
ram:01b830 8dd6 mov A,0xffdf6
ram:01b832 9efc mov CS,A
ram:01b834 c0 pop AX
ram:01b835 61ea call DE
ram:01b837 1004 addw SP,0x4
ram:01b839 eede00 br $! 0x1b91a
ram:01b83c c7 push HL
ram:01b83d 17 movw AX,HL
ram:01b83e 040200 addw AX,0x2
ram:01b841 16 movw HL,AX
ram:01b842 f7 clrw BC
ram:01b843 498c5b mov A,!0xf5b8c[BC]
ram:01b846 9b mov [HL],A
ram:01b847 a3 incw BC
ram:01b848 a7 incw HL
ram:01b849 5102 mov ,0x2
ram:01b84b 614a cmp A,
ram:01b84d dff4 bnz $ 0x1b843
ram:01b84f c6 pop HL
ram:01b850 af04e4 movw AX,!0xfe404
ram:01b853 e7 onew BC
ram:01b854 a3 incw BC
ram:01b855 c3 push BC
ram:01b856 12 movw BC,AX
ram:01b857 17 movw AX,HL
ram:01b858 040200 addw AX,0x2
ram:01b85b c1 push AX
ram:01b85c 491200 mov A,!0xf0012[BC]
ram:01b85f 9dd4 mov 0xffdf4,A
ram:01b861 791000 movw AX,!0xf0010[BC]
ram:01b864 c1 push AX
ram:01b865 8dd4 mov A,0xffdf4
ram:01b867 9dd6 mov 0xffdf6,A
ram:01b869 c0 pop AX
ram:01b86a 14 movw DE,AX
ram:01b86b 308d10 movw AX,0x108d
ram:01b86e 320d00 movw BC,0xd
ram:01b871 c1 push AX
ram:01b872 8dd6 mov A,0xffdf6
ram:01b874 9efc mov CS,A
ram:01b876 c0 pop AX
ram:01b877 61ea call DE
ram:01b879 1004 addw SP,0x4
ram:01b87b ee9c00 br $! 0x1b91a
ram:01b87e c7 push HL
ram:01b87f 17 movw AX,HL
ram:01b880 040200 addw AX,0x2
ram:01b883 16 movw HL,AX
ram:01b884 f7 clrw BC
ram:01b885 498e5b mov A,!0xf5b8e[BC]
ram:01b888 9b mov [HL],A
ram:01b889 a3 incw BC
ram:01b88a a7 incw HL
ram:01b88b 5102 mov ,0x2
ram:01b88d 614a cmp A,
ram:01b88f dff4 bnz $ 0x1b885
ram:01b891 c6 pop HL
ram:01b892 af04e4 movw AX,!0xfe404
ram:01b895 e7 onew BC
ram:01b896 a3 incw BC
ram:01b897 c3 push BC
ram:01b898 12 movw BC,AX
ram:01b899 17 movw AX,HL
ram:01b89a 040200 addw AX,0x2
ram:01b89d c1 push AX
ram:01b89e 491200 mov A,!0xf0012[BC]
ram:01b8a1 9dd4 mov 0xffdf4,A
ram:01b8a3 791000 movw AX,!0xf0010[BC]
ram:01b8a6 c1 push AX
ram:01b8a7 8dd4 mov A,0xffdf4
ram:01b8a9 9dd6 mov 0xffdf6,A
ram:01b8ab c0 pop AX
ram:01b8ac 14 movw DE,AX
ram:01b8ad 308e10 movw AX,0x108e
ram:01b8b0 320d00 movw BC,0xd
ram:01b8b3 c1 push AX
ram:01b8b4 8dd6 mov A,0xffdf6
ram:01b8b6 9efc mov CS,A
ram:01b8b8 c0 pop AX
ram:01b8b9 61ea call DE
ram:01b8bb 1004 addw SP,0x4
ram:01b8bd ef5b br $ 0x1b91a
ram:01b8bf c7 push HL
ram:01b8c0 17 movw AX,HL
ram:01b8c1 040200 addw AX,0x2
ram:01b8c4 16 movw HL,AX
ram:01b8c5 f7 clrw BC
ram:01b8c6 49905b mov A,!0xf5b90[BC]
ram:01b8c9 9b mov [HL],A
ram:01b8ca a3 incw BC
ram:01b8cb a7 incw HL
ram:01b8cc 5102 mov ,0x2
ram:01b8ce 614a cmp A,
ram:01b8d0 dff4 bnz $ 0x1b8c6
ram:01b8d2 c6 pop HL
ram:01b8d3 af04e4 movw AX,!0xfe404
ram:01b8d6 e7 onew BC
ram:01b8d7 a3 incw BC
ram:01b8d8 c3 push BC
ram:01b8d9 12 movw BC,AX
ram:01b8da 17 movw AX,HL
ram:01b8db 040200 addw AX,0x2
ram:01b8de c1 push AX
ram:01b8df 491200 mov A,!0xf0012[BC]
ram:01b8e2 9dd4 mov 0xffdf4,A
ram:01b8e4 791000 movw AX,!0xf0010[BC]
ram:01b8e7 c1 push AX
ram:01b8e8 8dd4 mov A,0xffdf4
ram:01b8ea 9dd6 mov 0xffdf6,A
ram:01b8ec c0 pop AX
ram:01b8ed 14 movw DE,AX
ram:01b8ee 308e10 movw AX,0x108e
ram:01b8f1 320d00 movw BC,0xd
ram:01b8f4 c1 push AX
ram:01b8f5 8dd6 mov A,0xffdf6
ram:01b8f7 9efc mov CS,A
ram:01b8f9 c0 pop AX
ram:01b8fa 61ea call DE
ram:01b8fc 1004 addw SP,0x4
ram:01b8fe ef1a br $ 0x1b91a
ram:01b900 fc539e01 call !!0x19e53
ram:01b904 ef14 br $ 0x1b91a
ram:01b906 af04e4 movw AX,!0xfe404
ram:01b909 34f050 movw DE,0x50f0
ram:01b90c c5 push DE
ram:01b90d 14 movw DE,AX
ram:01b90e 8a0e mov A,[DE + 0xe]
ram:01b910 9efc mov CS,A
ram:01b912 aa0c movw AX,[DE + 0xc]
ram:01b914 14 movw DE,AX
ram:01b915 e6 onew AX
ram:01b916 a1 incw AX
ram:01b917 61ea call DE
ram:01b919 c0 pop AX
ram:01b91a e7 onew BC
ram:01b91b 1006 addw SP,0x6
ram:01b91d c6 pop HL
ram:01b91e d7 ret
ram:01b95c c7 push HL
ram:01b95d c1 push AX
ram:01b95e c1 push AX
ram:01b95f fbf8ff movw HL,!0xffff8
ram:01b962 8c02 mov A,[HL + 0x2]
ram:01b964 7c80 xor A,#0x80
ram:01b966 4c30 cmp A,#0x30
ram:01b968 de05 bnc $ 0x1b96f
ram:01b96a 32925b movw BC,0x5b92
ram:01b96d ef1b br $ 0x1b98a
ram:01b96f 8c02 mov A,[HL + 0x2]
ram:01b971 7c80 xor A,#0x80
ram:01b973 4c8b cmp A,#0x8b
ram:01b975 dc05 bc $ 0x1b97c
ram:01b977 32fa5c movw BC,0x5cfa
ram:01b97a ef0e br $ 0x1b98a
ram:01b97c 8c02 mov A,[HL + 0x2]
ram:01b97e 318f sarw AX,0x8
ram:01b980 045000 addw AX,0x50
ram:01b983 bb movw [HL],AX
ram:01b984 312d shlw AX,0x2
ram:01b986 04925b addw AX,0x5b92
ram:01b989 12 movw BC,AX
ram:01b98a 1004 addw SP,0x4
ram:01b98c c6 pop HL
ram:01b98d d7 ret
ram:01b98e d50fe2 cmp0 !0xfe20f
ram:01b991 df06 bnz $ 0x1b999
ram:01b993 f6 clrw AX
ram:01b994 fc28be01 call !!0x1be28
ram:01b998 d7 ret
ram:01b999 d90ee2 mov X,!0xfe20e
ram:01b99c f1 clrb A
ram:01b99d fc28be01 call !!0x1be28
ram:01b9a1 d7 ret
ram:01b9a2 c7 push HL
ram:01b9a3 16 movw HL,AX
ram:01b9a4 66 mov A,
ram:01b9a5 91 dec 
ram:01b9a6 df19 bnz $ 0x1b9c1
ram:01b9a8 f50ee2 clrb !0xfe20e
ram:01b9ab e50fe2 oneb !0xfe20f
ram:01b9ae e519e2 oneb !0xfe219
ram:01b9b1 307fbc movw AX,0xbc7f
ram:01b9b4 5201 mov ,0x1
ram:01b9b6 f3 clrb B
ram:01b9b7 fc057e00 call !!0x7e05
ram:01b9bb 62 mov A,
ram:01b9bc 9f10e2 mov !0xfe210,A
ram:01b9bf ef15 br $ 0x1b9d6
ram:01b9c1 4019e201 cmp !0xfe219,0x1
ram:01b9c5 df0b bnz $ 0x1b9d2
ram:01b9c7 d910e2 mov X,!0xfe210
ram:01b9ca f1 clrb A
ram:01b9cb fc927e00 call !!0x7e92
ram:01b9cf f510e2 clrb !0xfe210
ram:01b9d2 fc58be01 call !!0x1be58
ram:01b9d6 c6 pop HL
ram:01b9d7 d7 ret
ram:01b9d8 c7 push HL
ram:01b9d9 16 movw HL,AX
ram:01b9da 4019e203 cmp !0xfe219,0x3
ram:01b9de df08 bnz $ 0x1b9e8
ram:01b9e0 66 mov A,
ram:01b9e1 9f0fe2 mov !0xfe20f,A
ram:01b9e4 fc8eb901 call !!0x1b98e
ram:01b9e8 c6 pop HL
ram:01b9e9 d7 ret
ram:01b9ea 8f19e2 mov A,!0xfe219
ram:01b9ed 318f sarw AX,0x8
ram:01b9ef 12 movw BC,AX
ram:01b9f0 d7 ret
ram:01b9f1 c7 push HL
ram:01b9f2 c1 push AX
ram:01b9f3 c1 push AX
ram:01b9f4 fbf8ff movw HL,!0xffff8
ram:01b9f7 8c02 mov A,[HL + 0x2]
ram:01b9f9 d1 cmp0 A
ram:01b9fa dd0b bz $ 0x1ba07
ram:01b9fc 91 dec 
ram:01b9fd dd11 bz $ 0x1ba10
ram:01b9ff 91 dec 
ram:01ba00 dd17 bz $ 0x1ba19
ram:01ba02 91 dec 
ram:01ba03 dd22 bz $ 0x1ba27
ram:01ba05 ef37 br $ 0x1ba3e
ram:01ba07 f50ee2 clrb !0xfe20e
ram:01ba0a fc8eb901 call !!0x1b98e
ram:01ba0e ef2e br $ 0x1ba3e
ram:01ba10 e50ee2 oneb !0xfe20e
ram:01ba13 fc8eb901 call !!0x1b98e
ram:01ba17 ef25 br $ 0x1ba3e
ram:01ba19 ac0a movw AX,[HL + 0xa]
ram:01ba1b 14 movw DE,AX
ram:01ba1c 89 mov A,[DE]
ram:01ba1d 9c01 mov [HL + 0x1],A
ram:01ba1f 318e shrw AX,0x8
ram:01ba21 fc18bf01 call !!0x1bf18
ram:01ba25 ef17 br $ 0x1ba3e
ram:01ba27 ac0a movw AX,[HL + 0xa]
ram:01ba29 14 movw DE,AX
ram:01ba2a 89 mov A,[DE]
ram:01ba2b 91 dec 
ram:01ba2c df0d bnz $ 0x1ba3b
ram:01ba2e 71520a set1 0xffe2a.0x5
ram:01ba31 f6 clrw AX
ram:01ba32 c1 push AX
ram:01ba33 e6 onew AX
ram:01ba34 fcf1b901 call !!0x1b9f1
ram:01ba38 c0 pop AX
ram:01ba39 ef03 br $ 0x1ba3e
ram:01ba3b 71530a clr1 0xffe2a.0x5
ram:01ba3e e7 onew BC
ram:01ba3f 1004 addw SP,0x4
ram:01ba41 c6 pop HL
ram:01ba42 d7 ret
ram:01ba99 c7 push HL
ram:01ba9a 2006 subw SP,0x6
ram:01ba9c fbf8ff movw HL,!0xffff8
ram:01ba9f c7 push HL
ram:01baa0 17 movw AX,HL
ram:01baa1 040400 addw AX,0x4
ram:01baa4 16 movw HL,AX
ram:01baa5 f7 clrw BC
ram:01baa6 49045d mov A,!0xf5d04[BC]
ram:01baa9 9b mov [HL],A
ram:01baaa a3 incw BC
ram:01baab a7 incw HL
ram:01baac 5102 mov ,0x2
ram:01baae 614a cmp A,
ram:01bab0 dff4 bnz $ 0x1baa6
ram:01bab2 c6 pop HL
ram:01bab3 3012e2 movw AX,0xe212
ram:01bab6 bb movw [HL],AX
ram:01bab7 db1ce4 movw BC,!0xfe41c
ram:01baba 17 movw AX,HL
ram:01babb 040400 addw AX,0x4
ram:01babe c1 push AX
ram:01babf 490e00 mov A,!0xf000e[BC]
ram:01bac2 9efc mov CS,A
ram:01bac4 790c00 movw AX,!0xf000c[BC]
ram:01bac7 14 movw DE,AX
ram:01bac8 f6 clrw AX
ram:01bac9 61ea call DE
ram:01bacb c0 pop AX
ram:01bacc d2 cmp0 C
ram:01bacd df03 bnz $ 0x1bad2
ram:01bacf f7 clrw BC
ram:01bad0 ef3c br $ 0x1bb0e
ram:01bad2 af1ce4 movw AX,!0xfe41c
ram:01bad5 320500 movw BC,0x5
ram:01bad8 c3 push BC
ram:01bad9 12 movw BC,AX
ram:01bada ab movw AX,[HL]
ram:01badb c1 push AX
ram:01badc 491200 mov A,!0xf0012[BC]
ram:01badf 9dd4 mov 0xffdf4,A
ram:01bae1 791000 movw AX,!0xf0010[BC]
ram:01bae4 c1 push AX
ram:01bae5 8dd4 mov A,0xffdf4
ram:01bae7 9dd6 mov 0xffdf6,A
ram:01bae9 c0 pop AX
ram:01baea 14 movw DE,AX
ram:01baeb e6 onew AX
ram:01baec f7 clrw BC
ram:01baed c1 push AX
ram:01baee 8dd6 mov A,0xffdf6
ram:01baf0 9efc mov CS,A
ram:01baf2 c0 pop AX
ram:01baf3 61ea call DE
ram:01baf5 1004 addw SP,0x4
ram:01baf7 db1ce4 movw BC,!0xfe41c
ram:01bafa 17 movw AX,HL
ram:01bafb 040400 addw AX,0x4
ram:01bafe c1 push AX
ram:01baff 490e00 mov A,!0xf000e[BC]
ram:01bb02 9efc mov CS,A
ram:01bb04 790c00 movw AX,!0xf000c[BC]
ram:01bb07 14 movw DE,AX
ram:01bb08 e6 onew AX
ram:01bb09 a1 incw AX
ram:01bb0a 61ea call DE
ram:01bb0c c0 pop AX
ram:01bb0d e7 onew BC
ram:01bb0e 1006 addw SP,0x6
ram:01bb10 c6 pop HL
ram:01bb11 d7 ret
ram:01bb12 c7 push HL
ram:01bb13 16 movw HL,AX
ram:01bb14 66 mov A,
ram:01bb15 91 dec 
ram:01bb16 df05 bnz $ 0x1bb1d
ram:01bb18 71520a set1 0xffe2a.0x5
ram:01bb1b ef03 br $ 0x1bb20
ram:01bb1d 71530a clr1 0xffe2a.0x5
ram:01bb20 c6 pop HL
ram:01bb21 d7 ret
ram:01bb7e c7 push HL
ram:01bb7f c1 push AX
ram:01bb80 2004 subw SP,0x4
ram:01bb82 fbf8ff movw HL,!0xffff8
ram:01bb85 cc0301 mov [HL + 0x3],0x1
ram:01bb88 af1ae4 movw AX,!0xfe41a
ram:01bb8b e7 onew BC
ram:01bb8c a3 incw BC
ram:01bb8d c3 push BC
ram:01bb8e 12 movw BC,AX
ram:01bb8f 17 movw AX,HL
ram:01bb90 a1 incw AX
ram:01bb91 c1 push AX
ram:01bb92 491600 mov A,!0xf0016[BC]
ram:01bb95 9dd4 mov 0xffdf4,A
ram:01bb97 791400 movw AX,!0xf0014[BC]
ram:01bb9a c1 push AX
ram:01bb9b 8dd4 mov A,0xffdf4
ram:01bb9d 9dd6 mov 0xffdf6,A
ram:01bb9f c0 pop AX
ram:01bba0 14 movw DE,AX
ram:01bba1 300800 movw AX,0x8
ram:01bba4 f7 clrw BC
ram:01bba5 c1 push AX
ram:01bba6 8dd6 mov A,0xffdf6
ram:01bba8 9efc mov CS,A
ram:01bbaa c0 pop AX
ram:01bbab 61ea call DE
ram:01bbad 1004 addw SP,0x4
ram:01bbaf 8c02 mov A,[HL + 0x2]
ram:01bbb1 5c10 and A,#0x10
ram:01bbb3 d1 cmp0 A
ram:01bbb4 dd2e bz $ 0x1bbe4
ram:01bbb6 712014e2 set1 !0xfe214.0x2
ram:01bbba 8c0c mov A,[HL + 0xc]
ram:01bbbc d1 cmp0 A
ram:01bbbd df03 bnz $ 0x1bbc2
ram:01bbbf e1 oneb A
ram:01bbc0 ef01 br $ 0x1bbc3
ram:01bbc2 f1 clrb A
ram:01bbc3 3414e2 movw DE,0xe214
ram:01bbc6 718c mov1 CY,A.0x0
ram:01bbc8 89 mov A,[DE]
ram:01bbc9 7189 mov1 A.0x0,CY
ram:01bbcb 99 mov [DE],A
ram:01bbcc 8c0e mov A,[HL + 0xe]
ram:01bbce d1 cmp0 A
ram:01bbcf df03 bnz $ 0x1bbd4
ram:01bbd1 e1 oneb A
ram:01bbd2 ef01 br $ 0x1bbd5
ram:01bbd4 f1 clrb A
ram:01bbd5 3414e2 movw DE,0xe214
ram:01bbd8 718c mov1 CY,A.0x0
ram:01bbda 89 mov A,[DE]
ram:01bbdb 71b9 mov1 A.0x3,CY
ram:01bbdd 99 mov [DE],A
ram:01bbde 711014e2 set1 !0xfe214.0x1
ram:01bbe2 ef48 br $ 0x1bc2c
ram:01bbe4 8c04 mov A,[HL + 0x4]
ram:01bbe6 d1 cmp0 A
ram:01bbe7 df03 bnz $ 0x1bbec
ram:01bbe9 e1 oneb A
ram:01bbea ef01 br $ 0x1bbed
ram:01bbec f1 clrb A
ram:01bbed 3414e2 movw DE,0xe214
ram:01bbf0 718c mov1 CY,A.0x0
ram:01bbf2 89 mov A,[DE]
ram:01bbf3 71a9 mov1 A.0x2,CY
ram:01bbf5 99 mov [DE],A
ram:01bbf6 8c0c mov A,[HL + 0xc]
ram:01bbf8 d1 cmp0 A
ram:01bbf9 df03 bnz $ 0x1bbfe
ram:01bbfb e1 oneb A
ram:01bbfc ef01 br $ 0x1bbff
ram:01bbfe f1 clrb A
ram:01bbff 3414e2 movw DE,0xe214
ram:01bc02 718c mov1 CY,A.0x0
ram:01bc04 89 mov A,[DE]
ram:01bc05 7189 mov1 A.0x0,CY
ram:01bc07 99 mov [DE],A
ram:01bc08 8c0e mov A,[HL + 0xe]
ram:01bc0a d1 cmp0 A
ram:01bc0b df03 bnz $ 0x1bc10
ram:01bc0d e1 oneb A
ram:01bc0e ef01 br $ 0x1bc11
ram:01bc10 f1 clrb A
ram:01bc11 3414e2 movw DE,0xe214
ram:01bc14 718c mov1 CY,A.0x0
ram:01bc16 89 mov A,[DE]
ram:01bc17 71b9 mov1 A.0x3,CY
ram:01bc19 99 mov [DE],A
ram:01bc1a 8c10 mov A,[HL + 0x10]
ram:01bc1c d1 cmp0 A
ram:01bc1d df03 bnz $ 0x1bc22
ram:01bc1f e1 oneb A
ram:01bc20 ef01 br $ 0x1bc23
ram:01bc22 f1 clrb A
ram:01bc23 3414e2 movw DE,0xe214
ram:01bc26 718c mov1 CY,A.0x0
ram:01bc28 89 mov A,[DE]
ram:01bc29 7199 mov1 A.0x1,CY
ram:01bc2b 99 mov [DE],A
ram:01bc2c 8c12 mov A,[HL + 0x12]
ram:01bc2e 91 dec 
ram:01bc2f df07 bnz $ 0x1bc38
ram:01bc31 fc99ba01 call !!0x1ba99
ram:01bc35 62 mov A,
ram:01bc36 9c03 mov [HL + 0x3],A
ram:01bc38 8c03 mov A,[HL + 0x3]
ram:01bc3a 318e shrw AX,0x8
ram:01bc3c 12 movw BC,AX
ram:01bc3d 1006 addw SP,0x6
ram:01bc3f c6 pop HL
ram:01bc40 d7 ret
ram:01bc41 c7 push HL
ram:01bc42 c1 push AX
ram:01bc43 c1 push AX
ram:01bc44 fbf8ff movw HL,!0xffff8
ram:01bc47 cc0101 mov [HL + 0x1],0x1
ram:01bc4a 8c02 mov A,[HL + 0x2]
ram:01bc4c 91 dec 
ram:01bc4d df03 bnz $ 0x1bc52
ram:01bc4f e1 oneb A
ram:01bc50 ef01 br $ 0x1bc53
ram:01bc52 f1 clrb A
ram:01bc53 3413e2 movw DE,0xe213
ram:01bc56 718c mov1 CY,A.0x0
ram:01bc58 89 mov A,[DE]
ram:01bc59 7189 mov1 A.0x0,CY
ram:01bc5b 99 mov [DE],A
ram:01bc5c 8c0a mov A,[HL + 0xa]
ram:01bc5e 91 dec 
ram:01bc5f df07 bnz $ 0x1bc68
ram:01bc61 fc99ba01 call !!0x1ba99
ram:01bc65 62 mov A,
ram:01bc66 9c01 mov [HL + 0x1],A
ram:01bc68 8c01 mov A,[HL + 0x1]
ram:01bc6a 318e shrw AX,0x8
ram:01bc6c 12 movw BC,AX
ram:01bc6d 1004 addw SP,0x4
ram:01bc6f c6 pop HL
ram:01bc70 d7 ret
ram:01be28 c7 push HL
ram:01be29 16 movw HL,AX
ram:01be2a 66 mov A,
ram:01be2b 91 dec 
ram:01be2c df16 bnz $ 0x1be44
ram:01be2e f6 clrw AX
ram:01be2f c1 push AX
ram:01be30 e6 onew AX
ram:01be31 c1 push AX
ram:01be32 c1 push AX
ram:01be33 c1 push AX
ram:01be34 fc7ebb01 call !!0x1bb7e
ram:01be38 1008 addw SP,0x8
ram:01be3a e6 onew AX
ram:01be3b c1 push AX
ram:01be3c f6 clrw AX
ram:01be3d fc41bc01 call !!0x1bc41
ram:01be41 c0 pop AX
ram:01be42 ef12 br $ 0x1be56
ram:01be44 f6 clrw AX
ram:01be45 c1 push AX
ram:01be46 c1 push AX
ram:01be47 c1 push AX
ram:01be48 c1 push AX
ram:01be49 fc7ebb01 call !!0x1bb7e
ram:01be4d 1008 addw SP,0x8
ram:01be4f e6 onew AX
ram:01be50 c1 push AX
ram:01be51 fc41bc01 call !!0x1bc41
ram:01be55 c0 pop AX
ram:01be56 c6 pop HL
ram:01be57 d7 ret
ram:01be58 f6 clrw AX
ram:01be59 fc28be01 call !!0x1be28
ram:01be5d f6 clrw AX
ram:01be5e fc12bb01 call !!0x1bb12
ram:01be62 f519e2 clrb !0xfe219
ram:01be65 715a2a set1 0xfff2a.0x5
ram:01be68 d7 ret
ram:01bf18 c7 push HL
ram:01bf19 16 movw HL,AX
ram:01bf1a 66 mov A,
ram:01bf1b 91 dec 
ram:01bf1c df0f bnz $ 0x1bf2d
ram:01bf1e e6 onew AX
ram:01bf1f c1 push AX
ram:01bf20 f6 clrw AX
ram:01bf21 c1 push AX
ram:01bf22 c1 push AX
ram:01bf23 c1 push AX
ram:01bf24 e6 onew AX
ram:01bf25 fc7ebb01 call !!0x1bb7e
ram:01bf29 1008 addw SP,0x8
ram:01bf2b ef3b br $ 0x1bf68
ram:01bf2d 66 mov A,
ram:01bf2e 4c02 cmp A,#0x2
ram:01bf30 df10 bnz $ 0x1bf42
ram:01bf32 e6 onew AX
ram:01bf33 c1 push AX
ram:01bf34 f6 clrw AX
ram:01bf35 c1 push AX
ram:01bf36 c1 push AX
ram:01bf37 e6 onew AX
ram:01bf38 c1 push AX
ram:01bf39 f6 clrw AX
ram:01bf3a fc7ebb01 call !!0x1bb7e
ram:01bf3e 1008 addw SP,0x8
ram:01bf40 ef26 br $ 0x1bf68
ram:01bf42 66 mov A,
ram:01bf43 4c03 cmp A,#0x3
ram:01bf45 df10 bnz $ 0x1bf57
ram:01bf47 e6 onew AX
ram:01bf48 c1 push AX
ram:01bf49 f6 clrw AX
ram:01bf4a c1 push AX
ram:01bf4b e6 onew AX
ram:01bf4c c1 push AX
ram:01bf4d f6 clrw AX
ram:01bf4e c1 push AX
ram:01bf4f fc7ebb01 call !!0x1bb7e
ram:01bf53 1008 addw SP,0x8
ram:01bf55 ef11 br $ 0x1bf68
ram:01bf57 66 mov A,
ram:01bf58 4c04 cmp A,#0x4
ram:01bf5a df0c bnz $ 0x1bf68
ram:01bf5c e6 onew AX
ram:01bf5d c1 push AX
ram:01bf5e c1 push AX
ram:01bf5f f6 clrw AX
ram:01bf60 c1 push AX
ram:01bf61 c1 push AX
ram:01bf62 fc7ebb01 call !!0x1bb7e
ram:01bf66 1008 addw SP,0x8
ram:01bf68 c6 pop HL
ram:01bf69 d7 ret
ram:01c44b c7 push HL
ram:01c44c c1 push AX
ram:01c44d 2004 subw SP,0x4
ram:01c44f fbf8ff movw HL,!0xffff8
ram:01c452 8c04 mov A,[HL + 0x4]
ram:01c454 d1 cmp0 A
ram:01c455 df09 bnz $ 0x1c460
ram:01c457 300104 movw AX,0x401
ram:01c45a bb movw [HL],AX
ram:01c45b f6 clrw AX
ram:01c45c bc02 movw [HL + 0x2],AX
ram:01c45e ef31 br $ 0x1c491
ram:01c460 5164 mov ,0x64
ram:01c462 2e04 sub A,[HL + 0x4]
ram:01c464 318e shrw AX,0x8
ram:01c466 f7 clrw BC
ram:01c467 bb movw [HL],AX
ram:01c468 33 xchw AX,BC
ram:01c469 bc02 movw [HL + 0x2],AX
ram:01c46b ab movw AX,[HL]
ram:01c46c bdd8 movw 0xffdf8,AX
ram:01c46e ac02 movw AX,[HL + 0x2]
ram:01c470 bdda movw 0xffdfa,AX
ram:01c472 510a mov ,0xa
ram:01c474 fd7106 call !0xf0671
ram:01c477 adda movw AX,0xffdfa
ram:01c479 bc02 movw [HL + 0x2],AX
ram:01c47b add8 movw AX,0xffdf8
ram:01c47d bb movw [HL],AX
ram:01c47e ac02 movw AX,[HL + 0x2]
ram:01c480 bdda movw 0xffdfa,AX
ram:01c482 c9dc6400 movw 0xffdfc,0x64
ram:01c486 f6 clrw AX
ram:01c487 fda105 call !0xf05a1
ram:01c48a adda movw AX,0xffdfa
ram:01c48c bc02 movw [HL + 0x2],AX
ram:01c48e add8 movw AX,0xffdf8
ram:01c490 bb movw [HL],AX
ram:01c491 ab movw AX,[HL]
ram:01c492 be7a movw 0xfff7a,AX
ram:01c494 1006 addw SP,0x6
ram:01c496 c6 pop HL
ram:01c497 d7 ret
ram:01c498 c7 push HL
ram:01c499 16 movw HL,AX
ram:01c49a 8f1ce2 mov A,!0xfe21c
ram:01c49d 4f1be2 cmp A,!0xfe21b
ram:01c4a0 df03 bnz $ 0x1c4a5
ram:01c4a2 f7 clrw BC
ram:01c4a3 ef2f br $ 0x1c4d4
ram:01c4a5 8f1be2 mov A,!0xfe21b
ram:01c4a8 4f1ce2 cmp A,!0xfe21c
ram:01c4ab de0d bnc $ 0x1c4ba
ram:01c4ad a01be2 inc !0xfe21b
ram:01c4b0 d91be2 mov X,!0xfe21b
ram:01c4b3 f1 clrb A
ram:01c4b4 fc4bc401 call !!0x1c44b
ram:01c4b8 ef0b br $ 0x1c4c5
ram:01c4ba b01be2 dec !0xfe21b
ram:01c4bd d91be2 mov X,!0xfe21b
ram:01c4c0 f1 clrb A
ram:01c4c1 fc4bc401 call !!0x1c44b
ram:01c4c5 8f1ce2 mov A,!0xfe21c
ram:01c4c8 4f1be2 cmp A,!0xfe21b
ram:01c4cb df06 bnz $ 0x1c4d3
ram:01c4cd f51fe2 clrb !0xfe21f
ram:01c4d0 f7 clrw BC
ram:01c4d1 ef01 br $ 0x1c4d4
ram:01c4d3 e7 onew BC
ram:01c4d4 c6 pop HL
ram:01c4d5 d7 ret
ram:01c4d6 c7 push HL
ram:01c4d7 16 movw HL,AX
ram:01c4d8 d51ee2 cmp0 !0xfe21e
ram:01c4db 61f8 sknz
ram:01c4dd 5600 _mov ,0x0
ram:01c4df 8f1ce2 mov A,!0xfe21c
ram:01c4e2 4f1be2 cmp A,!0xfe21b
ram:01c4e5 df2a bnz $ 0x1c511
ram:01c4e7 8f1be2 mov A,!0xfe21b
ram:01c4ea 614e cmp A,
ram:01c4ec dd19 bz $ 0x1c507
ram:01c4ee 66 mov A,
ram:01c4ef 9f1ce2 mov !0xfe21c,A
ram:01c4f2 300500 movw AX,0x5
ram:01c4f5 c1 push AX
ram:01c4f6 3098c4 movw AX,0xc498
ram:01c4f9 5201 mov ,0x1
ram:01c4fb f3 clrb B
ram:01c4fc fcea7d00 call !!0x7dea
ram:01c500 c0 pop AX
ram:01c501 62 mov A,
ram:01c502 9f1fe2 mov !0xfe21f,A
ram:01c505 ef0e br $ 0x1c515
ram:01c507 d91be2 mov X,!0xfe21b
ram:01c50a f1 clrb A
ram:01c50b fc4bc401 call !!0x1c44b
ram:01c50f ef04 br $ 0x1c515
ram:01c511 66 mov A,
ram:01c512 9f1ce2 mov !0xfe21c,A
ram:01c515 c6 pop HL
ram:01c516 d7 ret
ram:01c517 c7 push HL
ram:01c518 16 movw HL,AX
ram:01c519 66 mov A,
ram:01c51a 91 dec 
ram:01c51b df17 bnz $ 0x1c534
ram:01c51d cf1ae203 mov !0xfe21a,0x3
ram:01c521 e51ee2 oneb !0xfe21e
ram:01c524 f51de2 clrb !0xfe21d
ram:01c527 f51be2 clrb !0xfe21b
ram:01c52a f51ce2 clrb !0xfe21c
ram:01c52d f6 clrw AX
ram:01c52e fc4bc401 call !!0x1c44b
ram:01c532 ef1b br $ 0x1c54f
ram:01c534 f51ae2 clrb !0xfe21a
ram:01c537 d51fe2 cmp0 !0xfe21f
ram:01c53a dd0b bz $ 0x1c547
ram:01c53c d91fe2 mov X,!0xfe21f
ram:01c53f f1 clrb A
ram:01c540 fc927e00 call !!0x7e92
ram:01c544 f51fe2 clrb !0xfe21f
ram:01c547 f6 clrw AX
ram:01c548 fc4bc401 call !!0x1c44b
ram:01c54c 714307 clr1 0xffe27.0x4
ram:01c54f c6 pop HL
ram:01c550 d7 ret
ram:01c551 c7 push HL
ram:01c552 16 movw HL,AX
ram:01c553 401ae203 cmp !0xfe21a,0x3
ram:01c557 df0c bnz $ 0x1c565
ram:01c559 66 mov A,
ram:01c55a 9f1ee2 mov !0xfe21e,A
ram:01c55d d91de2 mov X,!0xfe21d
ram:01c560 f1 clrb A
ram:01c561 fcd6c401 call !!0x1c4d6
ram:01c565 c6 pop HL
ram:01c566 d7 ret
ram:01c5c1 716ad6 set1 0xfffd6.0x6
ram:01c5c4 716bd2 clr1 0xfffd2.0x6
ram:01c5c7 716ade set1 0xfffde.0x6
ram:01c5ca 716ada set1 0xfffda.0x6
ram:01c5cd 300140 movw AX,0x4001
ram:01c5d0 bf1202 movw !0xf0212,AX
ram:01c5d3 cb920020 movw 0xfff92,0x2000
ram:01c5d7 af3e02 movw AX,!0xf023e
ram:01c5da 08 xch A,X
ram:01c5db 5cfd and A,#0xfd
ram:01c5dd 08 xch A,X
ram:01c5de bf3e02 movw !0xf023e,AX
ram:01c5e1 af3c02 movw AX,!0xf023c
ram:01c5e4 08 xch A,X
ram:01c5e5 5cfd and A,#0xfd
ram:01c5e7 08 xch A,X
ram:01c5e8 bf3c02 movw !0xf023c,AX
ram:01c5eb af3a02 movw AX,!0xf023a
ram:01c5ee 08 xch A,X
ram:01c5ef 5cfd and A,#0xfd
ram:01c5f1 08 xch A,X
ram:01c5f2 bf3a02 movw !0xf023a,AX
ram:01c5f5 716bd2 clr1 0xfffd2.0x6
ram:01c5f8 716bd6 clr1 0xfffd6.0x6
ram:01c5fb af3202 movw AX,!0xf0232
ram:01c5fe 08 xch A,X
ram:01c5ff 6c02 or A,#0x2
ram:01c601 08 xch A,X
ram:01c602 bf3202 movw !0xf0232,AX
ram:01c605 f6 clrw AX
ram:01c606 bff6e8 movw !0xfe8f6,AX
ram:01c609 bff8e8 movw !0xfe8f8,AX
ram:01c60c bffae8 movw !0xfe8fa,AX
ram:01c60f f5fce8 clrb !0xfe8fc
ram:01c612 8ffde8 mov A,!0xfe8fd
ram:01c615 5cf8 and A,#0xf8
ram:01c617 9ffde8 mov !0xfe8fd,A
ram:01c61a d7 ret
ram:01c61b af3402 movw AX,!0xf0234
ram:01c61e 08 xch A,X
ram:01c61f 6c02 or A,#0x2
ram:01c621 08 xch A,X
ram:01c622 bf3402 movw !0xf0234,AX
ram:01c625 716ad6 set1 0xfffd6.0x6
ram:01c628 716bd2 clr1 0xfffd2.0x6
ram:01c62b d7 ret
ram:01c62c c7 push HL
ram:01c62d c1 push AX
ram:01c62e fbf8ff movw HL,!0xffff8
ram:01c631 ab movw AX,[HL]
ram:01c632 14 movw DE,AX
ram:01c633 aff8e8 movw AX,!0xfe8f8
ram:01c636 b9 movw [DE],AX
ram:01c637 ac08 movw AX,[HL + 0x8]
ram:01c639 14 movw DE,AX
ram:01c63a affae8 movw AX,!0xfe8fa
ram:01c63d b9 movw [DE],AX
ram:01c63e f6 clrw AX
ram:01c63f bffae8 movw !0xfe8fa,AX
ram:01c642 c0 pop AX
ram:01c643 c6 pop HL
ram:01c644 d7 ret
ram:01c645 c7 push HL
ram:01c646 16 movw HL,AX
ram:01c647 f50de9 clrb !0xfe90d
ram:01c64a f7 clrw BC
ram:01c64b c6 pop HL
ram:01c64c d7 ret
ram:01c64d c7 push HL
ram:01c64e 16 movw HL,AX
ram:01c64f 17 movw AX,HL
ram:01c650 14 movw DE,AX
ram:01c651 aa04 movw AX,[DE + 0x4]
ram:01c653 6168 or A,
ram:01c655 df21 bnz $ 0x1c678
ram:01c657 af02e4 movw AX,!0xfe402
ram:01c65a 3412e9 movw DE,0xe912
ram:01c65d c5 push DE
ram:01c65e 14 movw DE,AX
ram:01c65f 8a1a mov A,[DE + 0x1a]
ram:01c661 9efc mov CS,A
ram:01c663 aa18 movw AX,[DE + 0x18]
ram:01c665 14 movw DE,AX
ram:01c666 302000 movw AX,0x20
ram:01c669 61ea call DE
ram:01c66b c0 pop AX
ram:01c66c 17 movw AX,HL
ram:01c66d 14 movw DE,AX
ram:01c66e 303200 movw AX,0x32
ram:01c671 ba06 movw [DE + 0x6],AX
ram:01c673 aa04 movw AX,[DE + 0x4]
ram:01c675 a1 incw AX
ram:01c676 ba04 movw [DE + 0x4],AX
ram:01c678 17 movw AX,HL
ram:01c679 14 movw DE,AX
ram:01c67a aa04 movw AX,[DE + 0x4]
ram:01c67c 440b00 cmpw AX,0xb
ram:01c67f dc1c bc $ 0x1c69d
ram:01c681 304600 movw AX,0x46
ram:01c684 ba06 movw [DE + 0x6],AX
ram:01c686 af02e4 movw AX,!0xfe402
ram:01c689 3413e9 movw DE,0xe913
ram:01c68c c5 push DE
ram:01c68d 14 movw DE,AX
ram:01c68e 8a1a mov A,[DE + 0x1a]
ram:01c690 9efc mov CS,A
ram:01c692 aa18 movw AX,[DE + 0x18]
ram:01c694 14 movw DE,AX
ram:01c695 302000 movw AX,0x20
ram:01c698 61ea call DE
ram:01c69a c0 pop AX
ram:01c69b ef07 br $ 0x1c6a4
ram:01c69d 17 movw AX,HL
ram:01c69e 14 movw DE,AX
ram:01c69f aa04 movw AX,[DE + 0x4]
ram:01c6a1 a1 incw AX
ram:01c6a2 ba04 movw [DE + 0x4],AX
ram:01c6a4 af0ee9 movw AX,!0xfe90e
ram:01c6a7 5f11e9 and A,!0xfe911
ram:01c6aa 08 xch A,X
ram:01c6ab 5f10e9 and A,!0xfe910
ram:01c6ae 08 xch A,X
ram:01c6af 6168 or A,
ram:01c6b1 df06 bnz $ 0x1c6b9
ram:01c6b3 f50de9 clrb !0xfe90d
ram:01c6b6 f7 clrw BC
ram:01c6b7 ef01 br $ 0x1c6ba
ram:01c6b9 e7 onew BC
ram:01c6ba c6 pop HL
ram:01c6bb d7 ret
ram:01c6bc c7 push HL
ram:01c6bd 16 movw HL,AX
ram:01c6be 17 movw AX,HL
ram:01c6bf 14 movw DE,AX
ram:01c6c0 aa04 movw AX,[DE + 0x4]
ram:01c6c2 6168 or A,
ram:01c6c4 df23 bnz $ 0x1c6e9
ram:01c6c6 af02e4 movw AX,!0xfe402
ram:01c6c9 3412e9 movw DE,0xe912
ram:01c6cc c5 push DE
ram:01c6cd 14 movw DE,AX
ram:01c6ce 8a1a mov A,[DE + 0x1a]
ram:01c6d0 9efc mov CS,A
ram:01c6d2 aa18 movw AX,[DE + 0x18]
ram:01c6d4 14 movw DE,AX
ram:01c6d5 302000 movw AX,0x20
ram:01c6d8 61ea call DE
ram:01c6da c0 pop AX
ram:01c6db 17 movw AX,HL
ram:01c6dc 14 movw DE,AX
ram:01c6dd 301900 movw AX,0x19
ram:01c6e0 ba06 movw [DE + 0x6],AX
ram:01c6e2 aa04 movw AX,[DE + 0x4]
ram:01c6e4 a1 incw AX
ram:01c6e5 ba04 movw [DE + 0x4],AX
ram:01c6e7 ef2c br $ 0x1c715
ram:01c6e9 17 movw AX,HL
ram:01c6ea 14 movw DE,AX
ram:01c6eb aa04 movw AX,[DE + 0x4]
ram:01c6ed 440200 cmpw AX,0x2
ram:01c6f0 dc1c bc $ 0x1c70e
ram:01c6f2 301400 movw AX,0x14
ram:01c6f5 ba06 movw [DE + 0x6],AX
ram:01c6f7 af02e4 movw AX,!0xfe402
ram:01c6fa 3413e9 movw DE,0xe913
ram:01c6fd c5 push DE
ram:01c6fe 14 movw DE,AX
ram:01c6ff 8a1a mov A,[DE + 0x1a]
ram:01c701 9efc mov CS,A
ram:01c703 aa18 movw AX,[DE + 0x18]
ram:01c705 14 movw DE,AX
ram:01c706 302000 movw AX,0x20
ram:01c709 61ea call DE
ram:01c70b c0 pop AX
ram:01c70c ef07 br $ 0x1c715
ram:01c70e 17 movw AX,HL
ram:01c70f 14 movw DE,AX
ram:01c710 aa04 movw AX,[DE + 0x4]
ram:01c712 a1 incw AX
ram:01c713 ba04 movw [DE + 0x4],AX
ram:01c715 af0ee9 movw AX,!0xfe90e
ram:01c718 5f11e9 and A,!0xfe911
ram:01c71b 08 xch A,X
ram:01c71c 5f10e9 and A,!0xfe910
ram:01c71f 08 xch A,X
ram:01c720 6168 or A,
ram:01c722 df06 bnz $ 0x1c72a
ram:01c724 f50de9 clrb !0xfe90d
ram:01c727 f7 clrw BC
ram:01c728 ef01 br $ 0x1c72b
ram:01c72a e7 onew BC
ram:01c72b c6 pop HL
ram:01c72c d7 ret
ram:01c72d c7 push HL
ram:01c72e c1 push AX
ram:01c72f c1 push AX
ram:01c730 fbf8ff movw HL,!0xffff8
ram:01c733 cc0101 mov [HL + 0x1],0x1
ram:01c736 ac02 movw AX,[HL + 0x2]
ram:01c738 14 movw DE,AX
ram:01c739 aa04 movw AX,[DE + 0x4]
ram:01c73b 441400 cmpw AX,0x14
ram:01c73e de5a bnc $ 0x1c79a
ram:01c740 af0ee9 movw AX,!0xfe90e
ram:01c743 5f11e9 and A,!0xfe911
ram:01c746 08 xch A,X
ram:01c747 5f10e9 and A,!0xfe910
ram:01c74a 08 xch A,X
ram:01c74b 6168 or A,
ram:01c74d df41 bnz $ 0x1c790
ram:01c74f d512e9 cmp0 !0xfe912
ram:01c752 df11 bnz $ 0x1c765
ram:01c754 af00e4 movw AX,!0xfe400
ram:01c757 f7 clrw BC
ram:01c758 c3 push BC
ram:01c759 14 movw DE,AX
ram:01c75a 8a1a mov A,[DE + 0x1a]
ram:01c75c 9efc mov CS,A
ram:01c75e aa18 movw AX,[DE + 0x18]
ram:01c760 14 movw DE,AX
ram:01c761 f6 clrw AX
ram:01c762 61ea call DE
ram:01c764 c0 pop AX
ram:01c765 af02e4 movw AX,!0xfe402
ram:01c768 3412e9 movw DE,0xe912
ram:01c76b c5 push DE
ram:01c76c 14 movw DE,AX
ram:01c76d 8a1a mov A,[DE + 0x1a]
ram:01c76f 9efc mov CS,A
ram:01c771 aa18 movw AX,[DE + 0x18]
ram:01c773 14 movw DE,AX
ram:01c774 302000 movw AX,0x20
ram:01c777 61ea call DE
ram:01c779 c0 pop AX
ram:01c77a af14e9 movw AX,!0xfe914
ram:01c77d c1 push AX
ram:01c77e 3045c6 movw AX,0xc645
ram:01c781 5201 mov ,0x1
ram:01c783 f3 clrb B
ram:01c784 fcea7d00 call !!0x7dea
ram:01c788 c0 pop AX
ram:01c789 62 mov A,
ram:01c78a 9f0de9 mov !0xfe90d,A
ram:01c78d cc0100 mov [HL + 0x1],0x0
ram:01c790 ac02 movw AX,[HL + 0x2]
ram:01c792 14 movw DE,AX
ram:01c793 aa04 movw AX,[DE + 0x4]
ram:01c795 a1 incw AX
ram:01c796 ba04 movw [DE + 0x4],AX
ram:01c798 ef5f br $ 0x1c7f9
ram:01c79a ac02 movw AX,[HL + 0x2]
ram:01c79c 14 movw DE,AX
ram:01c79d aa04 movw AX,[DE + 0x4]
ram:01c79f 441400 cmpw AX,0x14
ram:01c7a2 df36 bnz $ 0x1c7da
ram:01c7a4 af02e4 movw AX,!0xfe402
ram:01c7a7 3413e9 movw DE,0xe913
ram:01c7aa c5 push DE
ram:01c7ab 14 movw DE,AX
ram:01c7ac 8a1a mov A,[DE + 0x1a]
ram:01c7ae 9efc mov CS,A
ram:01c7b0 aa18 movw AX,[DE + 0x18]
ram:01c7b2 14 movw DE,AX
ram:01c7b3 302000 movw AX,0x20
ram:01c7b6 61ea call DE
ram:01c7b8 c0 pop AX
ram:01c7b9 4013e901 cmp !0xfe913,0x1
ram:01c7bd df11 bnz $ 0x1c7d0
ram:01c7bf af00e4 movw AX,!0xfe400
ram:01c7c2 f7 clrw BC
ram:01c7c3 c3 push BC
ram:01c7c4 14 movw DE,AX
ram:01c7c5 8a1a mov A,[DE + 0x1a]
ram:01c7c7 9efc mov CS,A
ram:01c7c9 aa18 movw AX,[DE + 0x18]
ram:01c7cb 14 movw DE,AX
ram:01c7cc e6 onew AX
ram:01c7cd 61ea call DE
ram:01c7cf c0 pop AX
ram:01c7d0 ac02 movw AX,[HL + 0x2]
ram:01c7d2 14 movw DE,AX
ram:01c7d3 aa04 movw AX,[DE + 0x4]
ram:01c7d5 a1 incw AX
ram:01c7d6 ba04 movw [DE + 0x4],AX
ram:01c7d8 ef1f br $ 0x1c7f9
ram:01c7da ac02 movw AX,[HL + 0x2]
ram:01c7dc 14 movw DE,AX
ram:01c7dd aa04 movw AX,[DE + 0x4]
ram:01c7df 441500 cmpw AX,0x15
ram:01c7e2 dc15 bc $ 0x1c7f9
ram:01c7e4 af0ee9 movw AX,!0xfe90e
ram:01c7e7 5f11e9 and A,!0xfe911
ram:01c7ea 08 xch A,X
ram:01c7eb 5f10e9 and A,!0xfe910
ram:01c7ee 08 xch A,X
ram:01c7ef 6168 or A,
ram:01c7f1 df06 bnz $ 0x1c7f9
ram:01c7f3 f50de9 clrb !0xfe90d
ram:01c7f6 cc0100 mov [HL + 0x1],0x0
ram:01c7f9 8c01 mov A,[HL + 0x1]
ram:01c7fb 318e shrw AX,0x8
ram:01c7fd 12 movw BC,AX
ram:01c7fe 1004 addw SP,0x4
ram:01c800 c6 pop HL
ram:01c801 d7 ret
ram:01c802 c7 push HL
ram:01c803 c1 push AX
ram:01c804 c1 push AX
ram:01c805 fbf8ff movw HL,!0xffff8
ram:01c808 cc0101 mov [HL + 0x1],0x1
ram:01c80b af0ee9 movw AX,!0xfe90e
ram:01c80e 5f11e9 and A,!0xfe911
ram:01c811 08 xch A,X
ram:01c812 5f10e9 and A,!0xfe910
ram:01c815 08 xch A,X
ram:01c816 6168 or A,
ram:01c818 df41 bnz $ 0x1c85b
ram:01c81a d512e9 cmp0 !0xfe912
ram:01c81d df11 bnz $ 0x1c830
ram:01c81f af00e4 movw AX,!0xfe400
ram:01c822 f7 clrw BC
ram:01c823 c3 push BC
ram:01c824 14 movw DE,AX
ram:01c825 8a1a mov A,[DE + 0x1a]
ram:01c827 9efc mov CS,A
ram:01c829 aa18 movw AX,[DE + 0x18]
ram:01c82b 14 movw DE,AX
ram:01c82c f6 clrw AX
ram:01c82d 61ea call DE
ram:01c82f c0 pop AX
ram:01c830 af02e4 movw AX,!0xfe402
ram:01c833 3412e9 movw DE,0xe912
ram:01c836 c5 push DE
ram:01c837 14 movw DE,AX
ram:01c838 8a1a mov A,[DE + 0x1a]
ram:01c83a 9efc mov CS,A
ram:01c83c aa18 movw AX,[DE + 0x18]
ram:01c83e 14 movw DE,AX
ram:01c83f 302000 movw AX,0x20
ram:01c842 61ea call DE
ram:01c844 c0 pop AX
ram:01c845 af14e9 movw AX,!0xfe914
ram:01c848 c1 push AX
ram:01c849 3045c6 movw AX,0xc645
ram:01c84c 5201 mov ,0x1
ram:01c84e f3 clrb B
ram:01c84f fcea7d00 call !!0x7dea
ram:01c853 c0 pop AX
ram:01c854 62 mov A,
ram:01c855 9f0de9 mov !0xfe90d,A
ram:01c858 cc0100 mov [HL + 0x1],0x0
ram:01c85b 8c01 mov A,[HL + 0x1]
ram:01c85d 318e shrw AX,0x8
ram:01c85f 12 movw BC,AX
ram:01c860 1004 addw SP,0x4
ram:01c862 c6 pop HL
ram:01c863 d7 ret
ram:01c864 c7 push HL
ram:01c865 c1 push AX
ram:01c866 c1 push AX
ram:01c867 fbf8ff movw HL,!0xffff8
ram:01c86a cc0101 mov [HL + 0x1],0x1
ram:01c86d ac02 movw AX,[HL + 0x2]
ram:01c86f 14 movw DE,AX
ram:01c870 aa04 movw AX,[DE + 0x4]
ram:01c872 6168 or A,
ram:01c874 df1f bnz $ 0x1c895
ram:01c876 af02e4 movw AX,!0xfe402
ram:01c879 3412e9 movw DE,0xe912
ram:01c87c c5 push DE
ram:01c87d 14 movw DE,AX
ram:01c87e 8a1a mov A,[DE + 0x1a]
ram:01c880 9efc mov CS,A
ram:01c882 aa18 movw AX,[DE + 0x18]
ram:01c884 14 movw DE,AX
ram:01c885 302000 movw AX,0x20
ram:01c888 61ea call DE
ram:01c88a c0 pop AX
ram:01c88b ac02 movw AX,[HL + 0x2]
ram:01c88d 14 movw DE,AX
ram:01c88e aa04 movw AX,[DE + 0x4]
ram:01c890 a1 incw AX
ram:01c891 ba04 movw [DE + 0x4],AX
ram:01c893 ef15 br $ 0x1c8aa
ram:01c895 af0ee9 movw AX,!0xfe90e
ram:01c898 5f11e9 and A,!0xfe911
ram:01c89b 08 xch A,X
ram:01c89c 5f10e9 and A,!0xfe910
ram:01c89f 08 xch A,X
ram:01c8a0 6168 or A,
ram:01c8a2 df06 bnz $ 0x1c8aa
ram:01c8a4 f50de9 clrb !0xfe90d
ram:01c8a7 cc0100 mov [HL + 0x1],0x0
ram:01c8aa 8c01 mov A,[HL + 0x1]
ram:01c8ac 318e shrw AX,0x8
ram:01c8ae 12 movw BC,AX
ram:01c8af 1004 addw SP,0x4
ram:01c8b1 c6 pop HL
ram:01c8b2 d7 ret
ram:01c8b3 c7 push HL
ram:01c8b4 c1 push AX
ram:01c8b5 2004 subw SP,0x4
ram:01c8b7 fbf8ff movw HL,!0xffff8
ram:01c8ba 8f0ae9 mov A,!0xfe90a
ram:01c8bd 9c01 mov [HL + 0x1],A
ram:01c8bf f6 clrw AX
ram:01c8c0 614904 cmpw AX,[HL + 0x4]
ram:01c8c3 61e8 skz
ram:01c8c5 ee8b00 _br $! 0x1c953
ram:01c8c8 61490c cmpw AX,[HL + 0xc]
ram:01c8cb 61e8 skz
ram:01c8cd ee8300 _br $! 0x1c953
ram:01c8d0 bf1ce9 movw !0xfe91c,AX
ram:01c8d3 bf1ee9 movw !0xfe91e,AX
ram:01c8d6 714818e9 clr1 !0xfe918.0x4
ram:01c8da f526e2 clrb !0xfe226
ram:01c8dd 8c01 mov A,[HL + 0x1]
ram:01c8df 91 dec 
ram:01c8e0 df1c bnz $ 0x1c8fe
ram:01c8e2 4025e201 cmp !0xfe225,0x1
ram:01c8e6 df07 bnz $ 0x1c8ef
ram:01c8e8 715818e9 clr1 !0xfe918.0x5
ram:01c8ec f525e2 clrb !0xfe225
ram:01c8ef 4024e201 cmp !0xfe224,0x1
ram:01c8f3 df17 bnz $ 0x1c90c
ram:01c8f5 716818e9 clr1 !0xfe918.0x6
ram:01c8f9 f524e2 clrb !0xfe224
ram:01c8fc ef0e br $ 0x1c90c
ram:01c8fe 715818e9 clr1 !0xfe918.0x5
ram:01c902 f525e2 clrb !0xfe225
ram:01c905 716818e9 clr1 !0xfe918.0x6
ram:01c909 f524e2 clrb !0xfe224
ram:01c90c 713817e9 clr1 !0xfe917.0x3
ram:01c910 f528e2 clrb !0xfe228
ram:01c913 714817e9 clr1 !0xfe917.0x4
ram:01c917 f527e2 clrb !0xfe227
ram:01c91a 710817e9 clr1 !0xfe917.0x0
ram:01c91e f529e2 clrb !0xfe229
ram:01c921 712817e9 clr1 !0xfe917.0x2
ram:01c925 f52ae2 clrb !0xfe22a
ram:01c928 711817e9 clr1 !0xfe917.0x1
ram:01c92c f52be2 clrb !0xfe22b
ram:01c92f 715817e9 clr1 !0xfe917.0x5
ram:01c933 f52ee2 clrb !0xfe22e
ram:01c936 402ce201 cmp !0xfe22c,0x1
ram:01c93a df07 bnz $ 0x1c943
ram:01c93c 716817e9 clr1 !0xfe917.0x6
ram:01c940 f52ce2 clrb !0xfe22c
ram:01c943 402de201 cmp !0xfe22d,0x1
ram:01c947 df07 bnz $ 0x1c950
ram:01c949 717817e9 clr1 !0xfe917.0x7
ram:01c94d f52de2 clrb !0xfe22d
ram:01c950 ee0401 br $! 0x1ca57
ram:01c953 ac0c movw AX,[HL + 0xc]
ram:01c955 e7 onew BC
ram:01c956 b1 decw AX
ram:01c957 23 subw AX,BC
ram:01c958 61d312 bnh $ 0x1c96c
ram:01c95b 240200 subw AX,0x2
ram:01c95e df18 bnz $ 0x1c978
ram:01c960 af1ee9 movw AX,!0xfe91e
ram:01c963 44a10f cmpw AX,0xfa1
ram:01c966 de10 bnc $ 0x1c978
ram:01c968 a21ee9 incw !0xfe91e
ram:01c96b ef0b br $ 0x1c978
ram:01c96d af1ce9 movw AX,!0xfe91c
ram:01c970 44a10f cmpw AX,0xfa1
ram:01c973 61d8 sknc
ram:01c975 a21ce9 _incw !0xfe91c
ram:01c978 8c04 mov A,[HL + 0x4]
ram:01c97a 6e0c or A,[HL + 0xc]
ram:01c97c 70 mov ,A
ram:01c97d 8c05 mov A,[HL + 0x5]
ram:01c97f 6e0d or A,[HL + 0xd]
ram:01c981 e7 onew BC
ram:01c982 23 subw AX,BC
ram:01c983 dd48 bz $ 0x1c9cd
ram:01c985 23 subw AX,BC
ram:01c986 dd53 bz $ 0x1c9db
ram:01c988 240200 subw AX,0x2
ram:01c98b dd31 bz $ 0x1c9be
ram:01c98d 240400 subw AX,0x4
ram:01c990 dd57 bz $ 0x1c9e9
ram:01c992 240800 subw AX,0x8
ram:01c995 dd60 bz $ 0x1c9f7
ram:01c997 241000 subw AX,0x10
ram:01c99a dd69 bz $ 0x1ca05
ram:01c99c 242000 subw AX,0x20
ram:01c99f dd72 bz $ 0x1ca13
ram:01c9a1 244000 subw AX,0x40
ram:01c9a4 61f8 sknz
ram:01c9a6 eea200 _br $! 0x1ca4b
ram:01c9a9 248000 subw AX,0x80
ram:01c9ac dd73 bz $ 0x1ca21
ram:01c9ae 240001 subw AX,0x100
ram:01c9b1 dd7c bz $ 0x1ca2f
ram:01c9b3 240002 subw AX,0x200
ram:01c9b6 61f8 sknz
ram:01c9b8 ee8200 _br $! 0x1ca3d
ram:01c9bb ee9900 br $! 0x1ca57
ram:01c9be 710018e9 set1 !0xfe918.0x0
ram:01c9c2 714018e9 set1 !0xfe918.0x4
ram:01c9c6 cf26e243 mov !0xfe226,0x43
ram:01c9ca ee8a00 br $! 0x1ca57
ram:01c9cd 711018e9 set1 !0xfe918.0x1
ram:01c9d1 715018e9 set1 !0xfe918.0x5
ram:01c9d5 cf25e243 mov !0xfe225,0x43
ram:01c9d9 ef7c br $ 0x1ca57
ram:01c9db 712018e9 set1 !0xfe918.0x2
ram:01c9df 716018e9 set1 !0xfe918.0x6
ram:01c9e3 cf24e243 mov !0xfe224,0x43
ram:01c9e7 ef6e br $ 0x1ca57
ram:01c9e9 713016e9 set1 !0xfe916.0x3
ram:01c9ed 713017e9 set1 !0xfe917.0x3
ram:01c9f1 cf28e243 mov !0xfe228,0x43
ram:01c9f5 ef60 br $ 0x1ca57
ram:01c9f7 714016e9 set1 !0xfe916.0x4
ram:01c9fb 714017e9 set1 !0xfe917.0x4
ram:01c9ff cf27e243 mov !0xfe227,0x43
ram:01ca03 ef52 br $ 0x1ca57
ram:01ca05 710016e9 set1 !0xfe916.0x0
ram:01ca09 710017e9 set1 !0xfe917.0x0
ram:01ca0d cf29e243 mov !0xfe229,0x43
ram:01ca11 ef44 br $ 0x1ca57
ram:01ca13 712016e9 set1 !0xfe916.0x2
ram:01ca17 712017e9 set1 !0xfe917.0x2
ram:01ca1b cf2ae243 mov !0xfe22a,0x43
ram:01ca1f ef36 br $ 0x1ca57
ram:01ca21 711016e9 set1 !0xfe916.0x1
ram:01ca25 711017e9 set1 !0xfe917.0x1
ram:01ca29 cf2be243 mov !0xfe22b,0x43
ram:01ca2d ef28 br $ 0x1ca57
ram:01ca2f 716016e9 set1 !0xfe916.0x6
ram:01ca33 716017e9 set1 !0xfe917.0x6
ram:01ca37 cf2ce243 mov !0xfe22c,0x43
ram:01ca3b ef1a br $ 0x1ca57
ram:01ca3d 717016e9 set1 !0xfe916.0x7
ram:01ca41 717017e9 set1 !0xfe917.0x7
ram:01ca45 cf2de243 mov !0xfe22d,0x43
ram:01ca49 ef0c br $ 0x1ca57
ram:01ca4b 715016e9 set1 !0xfe916.0x5
ram:01ca4f 715017e9 set1 !0xfe917.0x5
ram:01ca53 cf2ee243 mov !0xfe22e,0x43
ram:01ca57 d524e2 cmp0 !0xfe224
ram:01ca5a 61e8 skz
ram:01ca5c b024e2 _dec !0xfe224
ram:01ca5f d525e2 cmp0 !0xfe225
ram:01ca62 61e8 skz
ram:01ca64 b025e2 _dec !0xfe225
ram:01ca67 d526e2 cmp0 !0xfe226
ram:01ca6a 61e8 skz
ram:01ca6c b026e2 _dec !0xfe226
ram:01ca6f d527e2 cmp0 !0xfe227
ram:01ca72 61e8 skz
ram:01ca74 b027e2 _dec !0xfe227
ram:01ca77 d528e2 cmp0 !0xfe228
ram:01ca7a 61e8 skz
ram:01ca7c b028e2 _dec !0xfe228
ram:01ca7f d529e2 cmp0 !0xfe229
ram:01ca82 61e8 skz
ram:01ca84 b029e2 _dec !0xfe229
ram:01ca87 d52ae2 cmp0 !0xfe22a
ram:01ca8a 61e8 skz
ram:01ca8c b02ae2 _dec !0xfe22a
ram:01ca8f d52be2 cmp0 !0xfe22b
ram:01ca92 61e8 skz
ram:01ca94 b02be2 _dec !0xfe22b
ram:01ca97 d52ce2 cmp0 !0xfe22c
ram:01ca9a 61e8 skz
ram:01ca9c b02ce2 _dec !0xfe22c
ram:01ca9f d52de2 cmp0 !0xfe22d
ram:01caa2 61e8 skz
ram:01caa4 b02de2 _dec !0xfe22d
ram:01caa7 d52ee2 cmp0 !0xfe22e
ram:01caaa 61e8 skz
ram:01caac b02ee2 _dec !0xfe22e
ram:01caaf 1006 addw SP,0x6
ram:01cab1 c6 pop HL
ram:01cab2 d7 ret
ram:01cab3 c7 push HL
ram:01cab4 c1 push AX
ram:01cab5 2006 subw SP,0x6
ram:01cab7 fbf8ff movw HL,!0xffff8
ram:01caba ac06 movw AX,[HL + 0x6]
ram:01cabc 14 movw DE,AX
ram:01cabd aa04 movw AX,[DE + 0x4]
ram:01cabf 6168 or A,
ram:01cac1 df19 bnz $ 0x1cadc
ram:01cac3 17 movw AX,HL
ram:01cac4 040200 addw AX,0x2
ram:01cac7 c1 push AX
ram:01cac8 17 movw AX,HL
ram:01cac9 040400 addw AX,0x4
ram:01cacc fc2cc601 call !!0x1c62c
ram:01cad0 c0 pop AX
ram:01cad1 ac06 movw AX,[HL + 0x6]
ram:01cad3 14 movw DE,AX
ram:01cad4 aa04 movw AX,[DE + 0x4]
ram:01cad6 a1 incw AX
ram:01cad7 ba04 movw [DE + 0x4],AX
ram:01cad9 eecd03 br $! 0x1cea9
ram:01cadc 17 movw AX,HL
ram:01cadd 040200 addw AX,0x2
ram:01cae0 c1 push AX
ram:01cae1 17 movw AX,HL
ram:01cae2 040400 addw AX,0x4
ram:01cae5 fc2cc601 call !!0x1c62c
ram:01cae9 c0 pop AX
ram:01caea ac04 movw AX,[HL + 0x4]
ram:01caec c1 push AX
ram:01caed ac02 movw AX,[HL + 0x2]
ram:01caef fcb3c801 call !!0x1c8b3
ram:01caf3 c0 pop AX
ram:01caf4 f6 clrw AX
ram:01caf5 614902 cmpw AX,[HL + 0x2]
ram:01caf8 61f8 sknz
ram:01cafa eeac03 _br $! 0x1cea9
ram:01cafd ac04 movw AX,[HL + 0x4]
ram:01caff bf0ee9 movw !0xfe90e,AX
ram:01cb02 d50de9 cmp0 !0xfe90d
ram:01cb05 61e8 skz
ram:01cb07 ee9f03 _br $! 0x1cea9
ram:01cb0a 4019e902 cmp !0xfe919,0x2
ram:01cb0e 61f8 sknz
ram:01cb10 ee8a00 _br $! 0x1cb9d
ram:01cb13 cc0100 mov [HL + 0x1],0x0
ram:01cb16 8f19e9 mov A,!0xfe919
ram:01cb19 d1 cmp0 A
ram:01cb1a dd05 bz $ 0x1cb21
ram:01cb1c 91 dec 
ram:01cb1d dd32 bz $ 0x1cb51
ram:01cb1f ef60 br $ 0x1cb81
ram:01cb21 e6 onew AX
ram:01cb22 614902 cmpw AX,[HL + 0x2]
ram:01cb25 df09 bnz $ 0x1cb30
ram:01cb27 71001ae9 set1 !0xfe91a.0x0
ram:01cb2b cc0101 mov [HL + 0x1],0x1
ram:01cb2e ef51 br $ 0x1cb81
ram:01cb30 e6 onew AX
ram:01cb31 a1 incw AX
ram:01cb32 614902 cmpw AX,[HL + 0x2]
ram:01cb35 df09 bnz $ 0x1cb40
ram:01cb37 71101ae9 set1 !0xfe91a.0x1
ram:01cb3b cc0102 mov [HL + 0x1],0x2
ram:01cb3e ef41 br $ 0x1cb81
ram:01cb40 300400 movw AX,0x4
ram:01cb43 614902 cmpw AX,[HL + 0x2]
ram:01cb46 df39 bnz $ 0x1cb81
ram:01cb48 71201ae9 set1 !0xfe91a.0x2
ram:01cb4c cc0103 mov [HL + 0x1],0x3
ram:01cb4f ef30 br $ 0x1cb81
ram:01cb51 302000 movw AX,0x20
ram:01cb54 614902 cmpw AX,[HL + 0x2]
ram:01cb57 df09 bnz $ 0x1cb62
ram:01cb59 71001ae9 set1 !0xfe91a.0x0
ram:01cb5d cc0101 mov [HL + 0x1],0x1
ram:01cb60 ef1f br $ 0x1cb81
ram:01cb62 300002 movw AX,0x200
ram:01cb65 614902 cmpw AX,[HL + 0x2]
ram:01cb68 df08 bnz $ 0x1cb72
ram:01cb6a 71101ae9 set1 !0xfe91a.0x1
ram:01cb6e 9c01 mov [HL + 0x1],A
ram:01cb70 ef0f br $ 0x1cb81
ram:01cb72 304000 movw AX,0x40
ram:01cb75 614902 cmpw AX,[HL + 0x2]
ram:01cb78 df07 bnz $ 0x1cb81
ram:01cb7a 71201ae9 set1 !0xfe91a.0x2
ram:01cb7e cc0103 mov [HL + 0x1],0x3
ram:01cb81 8c01 mov A,[HL + 0x1]
ram:01cb83 d1 cmp0 A
ram:01cb84 dd14 bz $ 0x1cb9a
ram:01cb86 e6 onew AX
ram:01cb87 c1 push AX
ram:01cb88 17 movw AX,HL
ram:01cb89 a1 incw AX
ram:01cb8a c1 push AX
ram:01cb8b d919e9 mov X,!0xfe919
ram:01cb8e f1 clrb A
ram:01cb8f c1 push AX
ram:01cb90 500f mov ,0xf
ram:01cb92 c1 push AX
ram:01cb93 e6 onew AX
ram:01cb94 fcb75401 call !!0x154b7
ram:01cb98 1008 addw SP,0x8
ram:01cb9a ee0c03 br $! 0x1cea9
ram:01cb9d ac02 movw AX,[HL + 0x2]
ram:01cb9f bf10e9 movw !0xfe910,AX
ram:01cba2 8c04 mov A,[HL + 0x4]
ram:01cba4 5e02 and A,[HL + 0x2]
ram:01cba6 70 mov ,A
ram:01cba7 8c05 mov A,[HL + 0x5]
ram:01cba9 5e03 and A,[HL + 0x3]
ram:01cbab 614902 cmpw AX,[HL + 0x2]
ram:01cbae df2b bnz $ 0x1cbdb
ram:01cbb0 ac02 movw AX,[HL + 0x2]
ram:01cbb2 240400 subw AX,0x4
ram:01cbb5 df24 bnz $ 0x1cbdb
ram:01cbb7 f512e9 clrb !0xfe912
ram:01cbba e513e9 oneb !0xfe913
ram:01cbbd 302602 movw AX,0x226
ram:01cbc0 bf14e9 movw !0xfe914,AX
ram:01cbc3 d50de9 cmp0 !0xfe90d
ram:01cbc6 df13 bnz $ 0x1cbdb
ram:01cbc8 303200 movw AX,0x32
ram:01cbcb c1 push AX
ram:01cbcc 3002c8 movw AX,0xc802
ram:01cbcf 5201 mov ,0x1
ram:01cbd1 f3 clrb B
ram:01cbd2 fcea7d00 call !!0x7dea
ram:01cbd6 c0 pop AX
ram:01cbd7 62 mov A,
ram:01cbd8 9f0de9 mov !0xfe90d,A
ram:01cbdb cc0100 mov [HL + 0x1],0x0
ram:01cbde af02e4 movw AX,!0xfe402
ram:01cbe1 e7 onew BC
ram:01cbe2 c3 push BC
ram:01cbe3 12 movw BC,AX
ram:01cbe4 17 movw AX,HL
ram:01cbe5 a1 incw AX
ram:01cbe6 c1 push AX
ram:01cbe7 491600 mov A,!0xf0016[BC]
ram:01cbea 9dd4 mov 0xffdf4,A
ram:01cbec 791400 movw AX,!0xf0014[BC]
ram:01cbef c1 push AX
ram:01cbf0 8dd4 mov A,0xffdf4
ram:01cbf2 9dd6 mov 0xffdf6,A
ram:01cbf4 c0 pop AX
ram:01cbf5 14 movw DE,AX
ram:01cbf6 300800 movw AX,0x8
ram:01cbf9 f7 clrw BC
ram:01cbfa c1 push AX
ram:01cbfb 8dd6 mov A,0xffdf6
ram:01cbfd 9efc mov CS,A
ram:01cbff c0 pop AX
ram:01cc00 61ea call DE
ram:01cc02 1004 addw SP,0x4
ram:01cc04 8c01 mov A,[HL + 0x1]
ram:01cc06 d1 cmp0 A
ram:01cc07 df0d bnz $ 0x1cc16
ram:01cc09 d51be9 cmp0 !0xfe91b
ram:01cc0c df08 bnz $ 0x1cc16
ram:01cc0e 5107 mov ,0x7
ram:01cc10 5e02 and A,[HL + 0x2]
ram:01cc12 318e shrw AX,0x8
ram:01cc14 bc02 movw [HL + 0x2],AX
ram:01cc16 ac02 movw AX,[HL + 0x2]
ram:01cc18 e7 onew BC
ram:01cc19 340800 movw DE,0x8
ram:01cc1c 23 subw AX,BC
ram:01cc1d dd6c bz $ 0x1cc8b
ram:01cc1f 23 subw AX,BC
ram:01cc20 61f8 sknz
ram:01cc22 eebd00 _br $! 0x1cce2
ram:01cc25 240600 subw AX,0x6
ram:01cc28 61f8 sknz
ram:01cc2a ee9700 _br $! 0x1ccc4
ram:01cc2d 25 subw AX,DE
ram:01cc2e 61f8 sknz
ram:01cc30 eee800 _br $! 0x1cd1b
ram:01cc33 25 subw AX,DE
ram:01cc34 dd31 bz $ 0x1cc67
ram:01cc36 25 subw AX,DE
ram:01cc37 61f8 sknz
ram:01cc39 eefd00 _br $! 0x1cd39
ram:01cc3c 242000 subw AX,0x20
ram:01cc3f 61f8 sknz
ram:01cc41 ee1301 _br $! 0x1cd57
ram:01cc44 244000 subw AX,0x40
ram:01cc47 61f8 sknz
ram:01cc49 ee3901 _br $! 0x1cd85
ram:01cc4c 248000 subw AX,0x80
ram:01cc4f 61f8 sknz
ram:01cc51 eeb501 _br $! 0x1ce09
ram:01cc54 240001 subw AX,0x100
ram:01cc57 61f8 sknz
ram:01cc59 ee1902 _br $! 0x1ce75
ram:01cc5c 240002 subw AX,0x200
ram:01cc5f 61f8 sknz
ram:01cc61 ee2c02 _br $! 0x1ce90
ram:01cc64 ee4202 br $! 0x1cea9
ram:01cc67 401be902 cmp !0xfe91b,0x2
ram:01cc6b df1b bnz $ 0x1cc88
ram:01cc6d cf12e906 mov !0xfe912,0x6
ram:01cc71 cf13e906 mov !0xfe913,0x6
ram:01cc75 301400 movw AX,0x14
ram:01cc78 c1 push AX
ram:01cc79 3064c8 movw AX,0xc864
ram:01cc7c 5201 mov ,0x1
ram:01cc7e f3 clrb B
ram:01cc7f fcea7d00 call !!0x7dea
ram:01cc83 c0 pop AX
ram:01cc84 62 mov A,
ram:01cc85 9f0de9 mov !0xfe90d,A
ram:01cc88 ee1e02 br $! 0x1cea9
ram:01cc8b cf12e903 mov !0xfe912,0x3
ram:01cc8f cf13e905 mov !0xfe913,0x5
ram:01cc93 400ae901 cmp !0xfe90a,0x1
ram:01cc97 df15 bnz $ 0x1ccae
ram:01cc99 302300 movw AX,0x23
ram:01cc9c c1 push AX
ram:01cc9d 30bcc6 movw AX,0xc6bc
ram:01cca0 5201 mov ,0x1
ram:01cca2 f3 clrb B
ram:01cca3 fcea7d00 call !!0x7dea
ram:01cca7 c0 pop AX
ram:01cca8 62 mov A,
ram:01cca9 9f0de9 mov !0xfe90d,A
ram:01ccac ef13 br $ 0x1ccc1
ram:01ccae 301400 movw AX,0x14
ram:01ccb1 c1 push AX
ram:01ccb2 304dc6 movw AX,0xc64d
ram:01ccb5 5201 mov ,0x1
ram:01ccb7 f3 clrb B
ram:01ccb8 fcea7d00 call !!0x7dea
ram:01ccbc c0 pop AX
ram:01ccbd 62 mov A,
ram:01ccbe 9f0de9 mov !0xfe90d,A
ram:01ccc1 eee501 br $! 0x1cea9
ram:01ccc4 cf12e903 mov !0xfe912,0x3
ram:01ccc8 cf13e905 mov !0xfe913,0x5
ram:01cccc 301400 movw AX,0x14
ram:01cccf c1 push AX
ram:01ccd0 304dc6 movw AX,0xc64d
ram:01ccd3 5201 mov ,0x1
ram:01ccd5 f3 clrb B
ram:01ccd6 fcea7d00 call !!0x7dea
ram:01ccda c0 pop AX
ram:01ccdb 62 mov A,
ram:01ccdc 9f0de9 mov !0xfe90d,A
ram:01ccdf eec701 br $! 0x1cea9
ram:01cce2 cf12e902 mov !0xfe912,0x2
ram:01cce6 cf13e904 mov !0xfe913,0x4
ram:01ccea 400ae901 cmp !0xfe90a,0x1
ram:01ccee df15 bnz $ 0x1cd05
ram:01ccf0 302300 movw AX,0x23
ram:01ccf3 c1 push AX
ram:01ccf4 30bcc6 movw AX,0xc6bc
ram:01ccf7 5201 mov ,0x1
ram:01ccf9 f3 clrb B
ram:01ccfa fcea7d00 call !!0x7dea
ram:01ccfe c0 pop AX
ram:01ccff 62 mov A,
ram:01cd00 9f0de9 mov !0xfe90d,A
ram:01cd03 ef13 br $ 0x1cd18
ram:01cd05 301400 movw AX,0x14
ram:01cd08 c1 push AX
ram:01cd09 304dc6 movw AX,0xc64d
ram:01cd0c 5201 mov ,0x1
ram:01cd0e f3 clrb B
ram:01cd0f fcea7d00 call !!0x7dea
ram:01cd13 c0 pop AX
ram:01cd14 62 mov A,
ram:01cd15 9f0de9 mov !0xfe90d,A
ram:01cd18 ee8e01 br $! 0x1cea9
ram:01cd1b cf12e902 mov !0xfe912,0x2
ram:01cd1f cf13e904 mov !0xfe913,0x4
ram:01cd23 301400 movw AX,0x14
ram:01cd26 c1 push AX
ram:01cd27 304dc6 movw AX,0xc64d
ram:01cd2a 5201 mov ,0x1
ram:01cd2c f3 clrb B
ram:01cd2d fcea7d00 call !!0x7dea
ram:01cd31 c0 pop AX
ram:01cd32 62 mov A,
ram:01cd33 9f0de9 mov !0xfe90d,A
ram:01cd36 ee7001 br $! 0x1cea9
ram:01cd39 cf12e907 mov !0xfe912,0x7
ram:01cd3d cf13e907 mov !0xfe913,0x7
ram:01cd41 303200 movw AX,0x32
ram:01cd44 c1 push AX
ram:01cd45 3064c8 movw AX,0xc864
ram:01cd48 5201 mov ,0x1
ram:01cd4a f3 clrb B
ram:01cd4b fcea7d00 call !!0x7dea
ram:01cd4f c0 pop AX
ram:01cd50 62 mov A,
ram:01cd51 9f0de9 mov !0xfe90d,A
ram:01cd54 ee5201 br $! 0x1cea9
ram:01cd57 401be901 cmp !0xfe91b,0x1
ram:01cd5b df0a bnz $ 0x1cd67
ram:01cd5d cf12e90e mov !0xfe912,0xe
ram:01cd61 cf13e90e mov !0xfe913,0xe
ram:01cd65 ef08 br $ 0x1cd6f
ram:01cd67 cf12e908 mov !0xfe912,0x8
ram:01cd6b cf13e908 mov !0xfe913,0x8
ram:01cd6f 303200 movw AX,0x32
ram:01cd72 c1 push AX
ram:01cd73 3064c8 movw AX,0xc864
ram:01cd76 5201 mov ,0x1
ram:01cd78 f3 clrb B
ram:01cd79 fcea7d00 call !!0x7dea
ram:01cd7d c0 pop AX
ram:01cd7e 62 mov A,
ram:01cd7f 9f0de9 mov !0xfe90d,A
ram:01cd82 ee2401 br $! 0x1cea9
ram:01cd85 401be901 cmp !0xfe91b,0x1
ram:01cd89 df7b bnz $ 0x1ce06
ram:01cd8b af0ae4 movw AX,!0xfe40a
ram:01cd8e e7 onew BC
ram:01cd8f c3 push BC
ram:01cd90 12 movw BC,AX
ram:01cd91 17 movw AX,HL
ram:01cd92 a1 incw AX
ram:01cd93 c1 push AX
ram:01cd94 491600 mov A,!0xf0016[BC]
ram:01cd97 9dd4 mov 0xffdf4,A
ram:01cd99 791400 movw AX,!0xf0014[BC]
ram:01cd9c c1 push AX
ram:01cd9d 8dd4 mov A,0xffdf4
ram:01cd9f 9dd6 mov 0xffdf6,A
ram:01cda1 c0 pop AX
ram:01cda2 14 movw DE,AX
ram:01cda3 302000 movw AX,0x20
ram:01cda6 f7 clrw BC
ram:01cda7 c1 push AX
ram:01cda8 8dd6 mov A,0xffdf6
ram:01cdaa 9efc mov CS,A
ram:01cdac c0 pop AX
ram:01cdad 61ea call DE
ram:01cdaf 1004 addw SP,0x4
ram:01cdb1 8c01 mov A,[HL + 0x1]
ram:01cdb3 4c07 cmp A,#0x7
ram:01cdb5 dd0c bz $ 0x1cdc3
ram:01cdb7 8c01 mov A,[HL + 0x1]
ram:01cdb9 4c0a cmp A,#0xa
ram:01cdbb dd06 bz $ 0x1cdc3
ram:01cdbd 8c01 mov A,[HL + 0x1]
ram:01cdbf 4c08 cmp A,#0x8
ram:01cdc1 df28 bnz $ 0x1cdeb
ram:01cdc3 cf12e909 mov !0xfe912,0x9
ram:01cdc7 cf13e90c mov !0xfe913,0xc
ram:01cdcb 307e04 movw AX,0x47e
ram:01cdce bf14e9 movw !0xfe914,AX
ram:01cdd1 d50de9 cmp0 !0xfe90d
ram:01cdd4 df30 bnz $ 0x1ce06
ram:01cdd6 303200 movw AX,0x32
ram:01cdd9 c1 push AX
ram:01cdda 302dc7 movw AX,0xc72d
ram:01cddd 5201 mov ,0x1
ram:01cddf f3 clrb B
ram:01cde0 fcea7d00 call !!0x7dea
ram:01cde4 c0 pop AX
ram:01cde5 62 mov A,
ram:01cde6 9f0de9 mov !0xfe90d,A
ram:01cde9 ef1b br $ 0x1ce06
ram:01cdeb cf12e906 mov !0xfe912,0x6
ram:01cdef cf13e906 mov !0xfe913,0x6
ram:01cdf3 301400 movw AX,0x14
ram:01cdf6 c1 push AX
ram:01cdf7 3064c8 movw AX,0xc864
ram:01cdfa 5201 mov ,0x1
ram:01cdfc f3 clrb B
ram:01cdfd fcea7d00 call !!0x7dea
ram:01ce01 c0 pop AX
ram:01ce02 62 mov A,
ram:01ce03 9f0de9 mov !0xfe90d,A
ram:01ce06 eea000 br $! 0x1cea9
ram:01ce09 401be901 cmp !0xfe91b,0x1
ram:01ce0d df1d bnz $ 0x1ce2c
ram:01ce0f cf12e90d mov !0xfe912,0xd
ram:01ce13 cf13e90d mov !0xfe913,0xd
ram:01ce17 303200 movw AX,0x32
ram:01ce1a c1 push AX
ram:01ce1b 3064c8 movw AX,0xc864
ram:01ce1e 5201 mov ,0x1
ram:01ce20 f3 clrb B
ram:01ce21 fcea7d00 call !!0x7dea
ram:01ce25 c0 pop AX
ram:01ce26 62 mov A,
ram:01ce27 9f0de9 mov !0xfe90d,A
ram:01ce2a ef47 br $ 0x1ce73
ram:01ce2c af0ae4 movw AX,!0xfe40a
ram:01ce2f e7 onew BC
ram:01ce30 c3 push BC
ram:01ce31 12 movw BC,AX
ram:01ce32 17 movw AX,HL
ram:01ce33 a1 incw AX
ram:01ce34 c1 push AX
ram:01ce35 491600 mov A,!0xf0016[BC]
ram:01ce38 9dd4 mov 0xffdf4,A
ram:01ce3a 791400 movw AX,!0xf0014[BC]
ram:01ce3d c1 push AX
ram:01ce3e 8dd4 mov A,0xffdf4
ram:01ce40 9dd6 mov 0xffdf6,A
ram:01ce42 c0 pop AX
ram:01ce43 14 movw DE,AX
ram:01ce44 302000 movw AX,0x20
ram:01ce47 f7 clrw BC
ram:01ce48 c1 push AX
ram:01ce49 8dd6 mov A,0xffdf6
ram:01ce4b 9efc mov CS,A
ram:01ce4d c0 pop AX
ram:01ce4e 61ea call DE
ram:01ce50 1004 addw SP,0x4
ram:01ce52 8c01 mov A,[HL + 0x1]
ram:01ce54 4c09 cmp A,#0x9
ram:01ce56 dd51 bz $ 0x1cea9
ram:01ce58 cf12e909 mov !0xfe912,0x9
ram:01ce5c cf13e90c mov !0xfe913,0xc
ram:01ce60 303200 movw AX,0x32
ram:01ce63 c1 push AX
ram:01ce64 302dc7 movw AX,0xc72d
ram:01ce67 5201 mov ,0x1
ram:01ce69 f3 clrb B
ram:01ce6a fcea7d00 call !!0x7dea
ram:01ce6e c0 pop AX
ram:01ce6f 62 mov A,
ram:01ce70 9f0de9 mov !0xfe90d,A
ram:01ce73 ef34 br $ 0x1cea9
ram:01ce75 cf12e90a mov !0xfe912,0xa
ram:01ce79 cf13e90a mov !0xfe913,0xa
ram:01ce7d f6 clrw AX
ram:01ce7e c1 push AX
ram:01ce7f 3064c8 movw AX,0xc864
ram:01ce82 5201 mov ,0x1
ram:01ce84 f3 clrb B
ram:01ce85 fcea7d00 call !!0x7dea
ram:01ce89 c0 pop AX
ram:01ce8a 62 mov A,
ram:01ce8b 9f0de9 mov !0xfe90d,A
ram:01ce8e ef19 br $ 0x1cea9
ram:01ce90 cf12e90b mov !0xfe912,0xb
ram:01ce94 cf13e90b mov !0xfe913,0xb
ram:01ce98 f6 clrw AX
ram:01ce99 c1 push AX
ram:01ce9a 3064c8 movw AX,0xc864
ram:01ce9d 5201 mov ,0x1
ram:01ce9f f3 clrb B
ram:01cea0 fcea7d00 call !!0x7dea
ram:01cea4 c0 pop AX
ram:01cea5 62 mov A,
ram:01cea6 9f0de9 mov !0xfe90d,A
ram:01cea9 e7 onew BC
ram:01ceaa 1008 addw SP,0x8
ram:01ceac c6 pop HL
ram:01cead d7 ret
ram:01ceae c7 push HL
ram:01ceaf c1 push AX
ram:01ceb0 c1 push AX
ram:01ceb1 fbf8ff movw HL,!0xffff8
ram:01ceb4 8c02 mov A,[HL + 0x2]
ram:01ceb6 91 dec 
ram:01ceb7 61e8 skz
ram:01ceb9 ee8900 _br $! 0x1cf45
ram:01cebc fcc1c501 call !!0x1c5c1
ram:01cec0 af1ae4 movw AX,!0xfe41a
ram:01cec3 e7 onew BC
ram:01cec4 a3 incw BC
ram:01cec5 c3 push BC
ram:01cec6 12 movw BC,AX
ram:01cec7 17 movw AX,HL
ram:01cec8 c1 push AX
ram:01cec9 491600 mov A,!0xf0016[BC]
ram:01cecc 9dd4 mov 0xffdf4,A
ram:01cece 791400 movw AX,!0xf0014[BC]
ram:01ced1 c1 push AX
ram:01ced2 8dd4 mov A,0xffdf4
ram:01ced4 9dd6 mov 0xffdf6,A
ram:01ced6 c0 pop AX
ram:01ced7 14 movw DE,AX
ram:01ced8 300800 movw AX,0x8
ram:01cedb f7 clrw BC
ram:01cedc c1 push AX
ram:01cedd 8dd6 mov A,0xffdf6
ram:01cedf 9efc mov CS,A
ram:01cee1 c0 pop AX
ram:01cee2 61ea call DE
ram:01cee4 1004 addw SP,0x4
ram:01cee6 8b mov A,[HL]
ram:01cee7 316a shr A,0x6
ram:01cee9 9b mov [HL],A
ram:01ceea 9f1be9 mov !0xfe91b,A
ram:01ceed af12e4 movw AX,!0xfe412
ram:01cef0 e7 onew BC
ram:01cef1 c3 push BC
ram:01cef2 12 movw BC,AX
ram:01cef3 17 movw AX,HL
ram:01cef4 a1 incw AX
ram:01cef5 c1 push AX
ram:01cef6 491600 mov A,!0xf0016[BC]
ram:01cef9 9dd4 mov 0xffdf4,A
ram:01cefb 791400 movw AX,!0xf0014[BC]
ram:01cefe c1 push AX
ram:01ceff 8dd4 mov A,0xffdf4
ram:01cf01 9dd6 mov 0xffdf6,A
ram:01cf03 c0 pop AX
ram:01cf04 14 movw DE,AX
ram:01cf05 304100 movw AX,0x41
ram:01cf08 f7 clrw BC
ram:01cf09 c1 push AX
ram:01cf0a 8dd6 mov A,0xffdf6
ram:01cf0c 9efc mov CS,A
ram:01cf0e c0 pop AX
ram:01cf0f 61ea call DE
ram:01cf11 1004 addw SP,0x4
ram:01cf13 8c01 mov A,[HL + 0x1]
ram:01cf15 d1 cmp0 A
ram:01cf16 df05 bnz $ 0x1cf1d
ram:01cf18 f50ae9 clrb !0xfe90a
ram:01cf1b ef03 br $ 0x1cf20
ram:01cf1d e50ae9 oneb !0xfe90a
ram:01cf20 f516e9 clrb !0xfe916
ram:01cf23 f517e9 clrb !0xfe917
ram:01cf26 f518e9 clrb !0xfe918
ram:01cf29 f50de9 clrb !0xfe90d
ram:01cf2c 301e00 movw AX,0x1e
ram:01cf2f c1 push AX
ram:01cf30 30b3ca movw AX,0xcab3
ram:01cf33 5201 mov ,0x1
ram:01cf35 f3 clrb B
ram:01cf36 fcea7d00 call !!0x7dea
ram:01cf3a c0 pop AX
ram:01cf3b 62 mov A,
ram:01cf3c 9f0ce9 mov !0xfe90c,A
ram:01cf3f cf0be903 mov !0xfe90b,0x3
ram:01cf43 ef12 br $ 0x1cf57
ram:01cf45 fc1bc601 call !!0x1c61b
ram:01cf49 d90ce9 mov X,!0xfe90c
ram:01cf4c f1 clrb A
ram:01cf4d fc927e00 call !!0x7e92
ram:01cf51 f50ce9 clrb !0xfe90c
ram:01cf54 f50be9 clrb !0xfe90b
ram:01cf57 cf19e902 mov !0xfe919,0x2
ram:01cf5b f51ae9 clrb !0xfe91a
ram:01cf5e 1004 addw SP,0x4
ram:01cf60 c6 pop HL
ram:01cf61 d7 ret
ram:01d06b c7 push HL
ram:01d06c c1 push AX
ram:01d06d 2008 subw SP,0x8
ram:01d06f fbf8ff movw HL,!0xffff8
ram:01d072 c7 push HL
ram:01d073 17 movw AX,HL
ram:01d074 16 movw HL,AX
ram:01d075 f7 clrw BC
ram:01d076 49145d mov A,!0xf5d14[BC]
ram:01d079 9b mov [HL],A
ram:01d07a a3 incw BC
ram:01d07b a7 incw HL
ram:01d07c 5108 mov ,0x8
ram:01d07e 614a cmp A,
ram:01d080 dff4 bnz $ 0x1d076
ram:01d082 c6 pop HL
ram:01d083 af04e4 movw AX,!0xfe404
ram:01d086 320800 movw BC,0x8
ram:01d089 c3 push BC
ram:01d08a 12 movw BC,AX
ram:01d08b 17 movw AX,HL
ram:01d08c c1 push AX
ram:01d08d 491200 mov A,!0xf0012[BC]
ram:01d090 9dd4 mov 0xffdf4,A
ram:01d092 791000 movw AX,!0xf0010[BC]
ram:01d095 c1 push AX
ram:01d096 8dd4 mov A,0xffdf4
ram:01d098 9dd6 mov 0xffdf6,A
ram:01d09a c0 pop AX
ram:01d09b 14 movw DE,AX
ram:01d09c 307110 movw AX,0x1071
ram:01d09f 320d00 movw BC,0xd
ram:01d0a2 c1 push AX
ram:01d0a3 8dd6 mov A,0xffdf6
ram:01d0a5 9efc mov CS,A
ram:01d0a7 c0 pop AX
ram:01d0a8 61ea call DE
ram:01d0aa 1004 addw SP,0x4
ram:01d0ac f55de2 clrb !0xfe25d
ram:01d0af f7 clrw BC
ram:01d0b0 100a addw SP,0xa
ram:01d0b2 c6 pop HL
ram:01d0b3 d7 ret
ram:01d0b4 c7 push HL
ram:01d0b5 16 movw HL,AX
ram:01d0b6 17 movw AX,HL
ram:01d0b7 14 movw DE,AX
ram:01d0b8 aa04 movw AX,[DE + 0x4]
ram:01d0ba 6168 or A,
ram:01d0bc df15 bnz $ 0x1d0d3
ram:01d0be af02e4 movw AX,!0xfe402
ram:01d0c1 3440e9 movw DE,0xe940
ram:01d0c4 c5 push DE
ram:01d0c5 14 movw DE,AX
ram:01d0c6 8a1a mov A,[DE + 0x1a]
ram:01d0c8 9efc mov CS,A
ram:01d0ca aa18 movw AX,[DE + 0x18]
ram:01d0cc 14 movw DE,AX
ram:01d0cd 303400 movw AX,0x34
ram:01d0d0 61ea call DE
ram:01d0d2 c0 pop AX
ram:01d0d3 17 movw AX,HL
ram:01d0d4 14 movw DE,AX
ram:01d0d5 aa04 movw AX,[DE + 0x4]
ram:01d0d7 a1 incw AX
ram:01d0d8 ba04 movw [DE + 0x4],AX
ram:01d0da 5205 mov ,0x5
ram:01d0dc fd1c06 call !0xf061c
ram:01d0df 13 movw AX,BC
ram:01d0e0 f1 clrb A
ram:01d0e1 ba04 movw [DE + 0x4],AX
ram:01d0e3 e7 onew BC
ram:01d0e4 c6 pop HL
ram:01d0e5 d7 ret
ram:01d0e6 c7 push HL
ram:01d0e7 200c subw SP,0xc
ram:01d0e9 fbf8ff movw HL,!0xffff8
ram:01d0ec 31320f03 bt 0xffe2f.0x3,$ 0x1d0f1
ram:01d0f0 f1 clrb A
ram:01d0f1 ef01 br $ 0x1d0f4
ram:01d0f3 e1 oneb A
ram:01d0f4 9c0a mov [HL + 0xa],A
ram:01d0f6 81 inc 
ram:01d0f7 5c01 and A,#0x1
ram:01d0f9 9c0a mov [HL + 0xa],A
ram:01d0fb 61fb rorc A,1
ram:01d0fd 71010c mov1 0xffe2c.0x0,CY
ram:01d100 710b2c clr1 0xfff2c.0x0
ram:01d103 cc0b00 mov [HL + 0xb],0x0
ram:01d106 8c0b mov A,[HL + 0xb]
ram:01d108 4c03 cmp A,#0x3
ram:01d10a de24 bnc $ 0x1d130
ram:01d10c 00 nop
ram:01d10d 00 nop
ram:01d10e 00 nop
ram:01d10f 00 nop
ram:01d110 00 nop
ram:01d111 00 nop
ram:01d112 00 nop
ram:01d113 31320f03 bt 0xffe2f.0x3,$ 0x1d118
ram:01d117 f1 clrb A
ram:01d118 ef01 br $ 0x1d11b
ram:01d11a e1 oneb A
ram:01d11b 4e0a cmp A,[HL + 0xa]
ram:01d11d df11 bnz $ 0x1d130
ram:01d11f 8c0a mov A,[HL + 0xa]
ram:01d121 81 inc 
ram:01d122 5c01 and A,#0x1
ram:01d124 9c0a mov [HL + 0xa],A
ram:01d126 61fb rorc A,1
ram:01d128 71010c mov1 0xffe2c.0x0,CY
ram:01d12b 61590b inc [HL + 0xb]
ram:01d12e efd6 br $ 0x1d106
ram:01d130 8f31e2 mov A,!0xfe231
ram:01d133 310503 bf A.0x0,$ 0x1d138
ram:01d136 eec000 br $! 0x1d1f9
ram:01d139 8c0b mov A,[HL + 0xb]
ram:01d13b 4c03 cmp A,#0x3
ram:01d13d 61e8 skz
ram:01d13f ee8f00 _br $! 0x1d1d1
ram:01d142 af0ae4 movw AX,!0xfe40a
ram:01d145 e7 onew BC
ram:01d146 c3 push BC
ram:01d147 12 movw BC,AX
ram:01d148 17 movw AX,HL
ram:01d149 040900 addw AX,0x9
ram:01d14c c1 push AX
ram:01d14d 491600 mov A,!0xf0016[BC]
ram:01d150 9dd4 mov 0xffdf4,A
ram:01d152 791400 movw AX,!0xf0014[BC]
ram:01d155 c1 push AX
ram:01d156 8dd4 mov A,0xffdf4
ram:01d158 9dd6 mov 0xffdf6,A
ram:01d15a c0 pop AX
ram:01d15b 14 movw DE,AX
ram:01d15c 302000 movw AX,0x20
ram:01d15f f7 clrw BC
ram:01d160 c1 push AX
ram:01d161 8dd6 mov A,0xffdf6
ram:01d163 9efc mov CS,A
ram:01d165 c0 pop AX
ram:01d166 61ea call DE
ram:01d168 1004 addw SP,0x4
ram:01d16a 8c09 mov A,[HL + 0x9]
ram:01d16c 4c02 cmp A,#0x2
ram:01d16e df5f bnz $ 0x1d1cf
ram:01d170 c7 push HL
ram:01d171 17 movw AX,HL
ram:01d172 a1 incw AX
ram:01d173 16 movw HL,AX
ram:01d174 f7 clrw BC
ram:01d175 491c5d mov A,!0xf5d1c[BC]
ram:01d178 9b mov [HL],A
ram:01d179 a3 incw BC
ram:01d17a a7 incw HL
ram:01d17b 5108 mov ,0x8
ram:01d17d 614a cmp A,
ram:01d17f dff4 bnz $ 0x1d175
ram:01d181 c6 pop HL
ram:01d182 af04e4 movw AX,!0xfe404
ram:01d185 320800 movw BC,0x8
ram:01d188 c3 push BC
ram:01d189 12 movw BC,AX
ram:01d18a 17 movw AX,HL
ram:01d18b a1 incw AX
ram:01d18c c1 push AX
ram:01d18d 491200 mov A,!0xf0012[BC]
ram:01d190 9dd4 mov 0xffdf4,A
ram:01d192 791000 movw AX,!0xf0010[BC]
ram:01d195 c1 push AX
ram:01d196 8dd4 mov A,0xffdf4
ram:01d198 9dd6 mov 0xffdf6,A
ram:01d19a c0 pop AX
ram:01d19b 14 movw DE,AX
ram:01d19c 307110 movw AX,0x1071
ram:01d19f 320d00 movw BC,0xd
ram:01d1a2 c1 push AX
ram:01d1a3 8dd6 mov A,0xffdf6
ram:01d1a5 9efc mov CS,A
ram:01d1a7 c0 pop AX
ram:01d1a8 61ea call DE
ram:01d1aa 1004 addw SP,0x4
ram:01d1ac d55de2 cmp0 !0xfe25d
ram:01d1af dd0b bz $ 0x1d1bc
ram:01d1b1 d95de2 mov X,!0xfe25d
ram:01d1b4 f1 clrb A
ram:01d1b5 fc927e00 call !!0x7e92
ram:01d1b9 f55de2 clrb !0xfe25d
ram:01d1bc 309600 movw AX,0x96
ram:01d1bf c1 push AX
ram:01d1c0 306bd0 movw AX,0xd06b
ram:01d1c3 5201 mov ,0x1
ram:01d1c5 f3 clrb B
ram:01d1c6 fcea7d00 call !!0x7dea
ram:01d1ca c0 pop AX
ram:01d1cb 62 mov A,
ram:01d1cc 9f5de2 mov !0xfe25d,A
ram:01d1cf ef25 br $ 0x1d1f6
ram:01d1d1 cc0901 mov [HL + 0x9],0x1
ram:01d1d4 710031e2 set1 !0xfe231.0x0
ram:01d1d8 db02e4 movw BC,!0xfe402
ram:01d1db 17 movw AX,HL
ram:01d1dc 040900 addw AX,0x9
ram:01d1df c1 push AX
ram:01d1e0 491a00 mov A,!0xf001a[BC]
ram:01d1e3 9efc mov CS,A
ram:01d1e5 791800 movw AX,!0xf0018[BC]
ram:01d1e8 14 movw DE,AX
ram:01d1e9 303000 movw AX,0x30
ram:01d1ec 61ea call DE
ram:01d1ee c0 pop AX
ram:01d1ef 3430e2 movw DE,0xe230
ram:01d1f2 89 mov A,[DE]
ram:01d1f3 5cf8 and A,#0xf8
ram:01d1f5 99 mov [DE],A
ram:01d1f6 eeda00 br $! 0x1d2d3
ram:01d1f9 8c0b mov A,[HL + 0xb]
ram:01d1fb 4c03 cmp A,#0x3
ram:01d1fd 61e8 skz
ram:01d1ff eeca00 _br $! 0x1d2cc
ram:01d202 af0ae4 movw AX,!0xfe40a
ram:01d205 e7 onew BC
ram:01d206 c3 push BC
ram:01d207 12 movw BC,AX
ram:01d208 17 movw AX,HL
ram:01d209 040900 addw AX,0x9
ram:01d20c c1 push AX
ram:01d20d 491600 mov A,!0xf0016[BC]
ram:01d210 9dd4 mov 0xffdf4,A
ram:01d212 791400 movw AX,!0xf0014[BC]
ram:01d215 c1 push AX
ram:01d216 8dd4 mov A,0xffdf4
ram:01d218 9dd6 mov 0xffdf6,A
ram:01d21a c0 pop AX
ram:01d21b 14 movw DE,AX
ram:01d21c 302000 movw AX,0x20
ram:01d21f f7 clrw BC
ram:01d220 c1 push AX
ram:01d221 8dd6 mov A,0xffdf6
ram:01d223 9efc mov CS,A
ram:01d225 c0 pop AX
ram:01d226 61ea call DE
ram:01d228 1004 addw SP,0x4
ram:01d22a 8c09 mov A,[HL + 0x9]
ram:01d22c 4c02 cmp A,#0x2
ram:01d22e df5f bnz $ 0x1d28f
ram:01d230 c7 push HL
ram:01d231 17 movw AX,HL
ram:01d232 a1 incw AX
ram:01d233 16 movw HL,AX
ram:01d234 f7 clrw BC
ram:01d235 49245d mov A,!0xf5d24[BC]
ram:01d238 9b mov [HL],A
ram:01d239 a3 incw BC
ram:01d23a a7 incw HL
ram:01d23b 5108 mov ,0x8
ram:01d23d 614a cmp A,
ram:01d23f dff4 bnz $ 0x1d235
ram:01d241 c6 pop HL
ram:01d242 af04e4 movw AX,!0xfe404
ram:01d245 320800 movw BC,0x8
ram:01d248 c3 push BC
ram:01d249 12 movw BC,AX
ram:01d24a 17 movw AX,HL
ram:01d24b a1 incw AX
ram:01d24c c1 push AX
ram:01d24d 491200 mov A,!0xf0012[BC]
ram:01d250 9dd4 mov 0xffdf4,A
ram:01d252 791000 movw AX,!0xf0010[BC]
ram:01d255 c1 push AX
ram:01d256 8dd4 mov A,0xffdf4
ram:01d258 9dd6 mov 0xffdf6,A
ram:01d25a c0 pop AX
ram:01d25b 14 movw DE,AX
ram:01d25c 307110 movw AX,0x1071
ram:01d25f 320d00 movw BC,0xd
ram:01d262 c1 push AX
ram:01d263 8dd6 mov A,0xffdf6
ram:01d265 9efc mov CS,A
ram:01d267 c0 pop AX
ram:01d268 61ea call DE
ram:01d26a 1004 addw SP,0x4
ram:01d26c d55de2 cmp0 !0xfe25d
ram:01d26f dd0b bz $ 0x1d27c
ram:01d271 d95de2 mov X,!0xfe25d
ram:01d274 f1 clrb A
ram:01d275 fc927e00 call !!0x7e92
ram:01d279 f55de2 clrb !0xfe25d
ram:01d27c 309600 movw AX,0x96
ram:01d27f c1 push AX
ram:01d280 306bd0 movw AX,0xd06b
ram:01d283 5201 mov ,0x1
ram:01d285 f3 clrb B
ram:01d286 fcea7d00 call !!0x7dea
ram:01d28a c0 pop AX
ram:01d28b 62 mov A,
ram:01d28c 9f5de2 mov !0xfe25d,A
ram:01d28f 8f30e2 mov A,!0xfe230
ram:01d292 81 inc 
ram:01d293 5c07 and A,#0x7
ram:01d295 3430e2 movw DE,0xe230
ram:01d298 70 mov ,A
ram:01d299 89 mov A,[DE]
ram:01d29a 5cf8 and A,#0xf8
ram:01d29c 6168 or A,
ram:01d29e 99 mov [DE],A
ram:01d29f 5c07 and A,#0x7
ram:01d2a1 4c03 cmp A,#0x3
ram:01d2a3 dc2e bc $ 0x1d2d3
ram:01d2a5 cc0800 mov [HL + 0x8],0x0
ram:01d2a8 710831e2 clr1 !0xfe231.0x0
ram:01d2ac db02e4 movw BC,!0xfe402
ram:01d2af 17 movw AX,HL
ram:01d2b0 040800 addw AX,0x8
ram:01d2b3 c1 push AX
ram:01d2b4 491a00 mov A,!0xf001a[BC]
ram:01d2b7 9efc mov CS,A
ram:01d2b9 791800 movw AX,!0xf0018[BC]
ram:01d2bc 14 movw DE,AX
ram:01d2bd 303000 movw AX,0x30
ram:01d2c0 61ea call DE
ram:01d2c2 c0 pop AX
ram:01d2c3 3430e2 movw DE,0xe230
ram:01d2c6 89 mov A,[DE]
ram:01d2c7 5cf8 and A,#0xf8
ram:01d2c9 99 mov [DE],A
ram:01d2ca ef07 br $ 0x1d2d3
ram:01d2cc 3430e2 movw DE,0xe230
ram:01d2cf 89 mov A,[DE]
ram:01d2d0 5cf8 and A,#0xf8
ram:01d2d2 99 mov [DE],A
ram:01d2d3 710a2c set1 0xfff2c.0x0
ram:01d2d6 100c addw SP,0xc
ram:01d2d8 c6 pop HL
ram:01d2d9 d7 ret
ram:01d2da c7 push HL
ram:01d2db c1 push AX
ram:01d2dc fbf8ff movw HL,!0xffff8
ram:01d2df f1 clrb A
ram:01d2e0 71040f mov1 CY,0xffe2f.0x0
ram:01d2e3 61dc rolc A,1
ram:01d2e5 7c01 xor A,#0x1
ram:01d2e7 9c01 mov [HL + 0x1],A
ram:01d2e9 8f32e2 mov A,!0xfe232
ram:01d2ec 317a shr A,0x7
ram:01d2ee 4e01 cmp A,[HL + 0x1]
ram:01d2f0 dd20 bz $ 0x1d312
ram:01d2f2 8c01 mov A,[HL + 0x1]
ram:01d2f4 3432e2 movw DE,0xe232
ram:01d2f7 718c mov1 CY,A.0x0
ram:01d2f9 89 mov A,[DE]
ram:01d2fa 71f9 mov1 A.0x7,CY
ram:01d2fc 99 mov [DE],A
ram:01d2fd db02e4 movw BC,!0xfe402
ram:01d300 17 movw AX,HL
ram:01d301 a1 incw AX
ram:01d302 c1 push AX
ram:01d303 491a00 mov A,!0xf001a[BC]
ram:01d306 9efc mov CS,A
ram:01d308 791800 movw AX,!0xf0018[BC]
ram:01d30b 14 movw DE,AX
ram:01d30c 303300 movw AX,0x33
ram:01d30f 61ea call DE
ram:01d311 c0 pop AX
ram:01d312 c0 pop AX
ram:01d313 c6 pop HL
ram:01d314 d7 ret
ram:01d315 c7 push HL
ram:01d316 2004 subw SP,0x4
ram:01d318 fbf8ff movw HL,!0xffff8
ram:01d31b 31740703 bf 0xffe27.0x7,$ 0x1d320
ram:01d31f e1 oneb A
ram:01d320 ef01 br $ 0x1d323
ram:01d322 f1 clrb A
ram:01d323 9c03 mov [HL + 0x3],A
ram:01d325 d1 cmp0 A
ram:01d326 df16 bnz $ 0x1d33e
ram:01d328 f568e2 clrb !0xfe268
ram:01d32b a069e2 inc !0xfe269
ram:01d32e 8f6ae2 mov A,!0xfe26a
ram:01d331 4f69e2 cmp A,!0xfe269
ram:01d334 de21 bnc $ 0x1d357
ram:01d336 f569e2 clrb !0xfe269
ram:01d339 e542e9 oneb !0xfe942
ram:01d33c ef19 br $ 0x1d357
ram:01d33e 8c03 mov A,[HL + 0x3]
ram:01d340 91 dec 
ram:01d341 df14 bnz $ 0x1d357
ram:01d343 f569e2 clrb !0xfe269
ram:01d346 a068e2 inc !0xfe268
ram:01d349 8f6be2 mov A,!0xfe26b
ram:01d34c 4f68e2 cmp A,!0xfe268
ram:01d34f de06 bnc $ 0x1d357
ram:01d351 f568e2 clrb !0xfe268
ram:01d354 f542e9 clrb !0xfe942
ram:01d357 cc0200 mov [HL + 0x2],0x0
ram:01d35a af02e4 movw AX,!0xfe402
ram:01d35d e7 onew BC
ram:01d35e c3 push BC
ram:01d35f 12 movw BC,AX
ram:01d360 17 movw AX,HL
ram:01d361 040200 addw AX,0x2
ram:01d364 c1 push AX
ram:01d365 491600 mov A,!0xf0016[BC]
ram:01d368 9dd4 mov 0xffdf4,A
ram:01d36a 791400 movw AX,!0xf0014[BC]
ram:01d36d c1 push AX
ram:01d36e 8dd4 mov A,0xffdf4
ram:01d370 9dd6 mov 0xffdf6,A
ram:01d372 c0 pop AX
ram:01d373 14 movw DE,AX
ram:01d374 300300 movw AX,0x3
ram:01d377 f7 clrw BC
ram:01d378 c1 push AX
ram:01d379 8dd6 mov A,0xffdf6
ram:01d37b 9efc mov CS,A
ram:01d37d c0 pop AX
ram:01d37e 61ea call DE
ram:01d380 1004 addw SP,0x4
ram:01d382 8c02 mov A,[HL + 0x2]
ram:01d384 d1 cmp0 A
ram:01d385 61f8 sknz
ram:01d387 eec000 _br $! 0x1d44a
ram:01d38a d942e9 mov X,!0xfe942
ram:01d38d f1 clrb A
ram:01d38e 12 movw BC,AX
ram:01d38f 8f31e2 mov A,!0xfe231
ram:01d392 3169 shl A,0x6
ram:01d394 31fe shrw AX,0xf
ram:01d396 43 cmpw AX,BC
ram:01d397 61f8 sknz
ram:01d399 eeae00 _br $! 0x1d44a
ram:01d39c af02e4 movw AX,!0xfe402
ram:01d39f e7 onew BC
ram:01d3a0 c3 push BC
ram:01d3a1 12 movw BC,AX
ram:01d3a2 17 movw AX,HL
ram:01d3a3 a1 incw AX
ram:01d3a4 c1 push AX
ram:01d3a5 491600 mov A,!0xf0016[BC]
ram:01d3a8 9dd4 mov 0xffdf4,A
ram:01d3aa 791400 movw AX,!0xf0014[BC]
ram:01d3ad c1 push AX
ram:01d3ae 8dd4 mov A,0xffdf4
ram:01d3b0 9dd6 mov 0xffdf6,A
ram:01d3b2 c0 pop AX
ram:01d3b3 14 movw DE,AX
ram:01d3b4 300800 movw AX,0x8
ram:01d3b7 f7 clrw BC
ram:01d3b8 c1 push AX
ram:01d3b9 8dd6 mov A,0xffdf6
ram:01d3bb 9efc mov CS,A
ram:01d3bd c0 pop AX
ram:01d3be 61ea call DE
ram:01d3c0 1004 addw SP,0x4
ram:01d3c2 8c01 mov A,[HL + 0x1]
ram:01d3c4 d1 cmp0 A
ram:01d3c5 df59 bnz $ 0x1d420
ram:01d3c7 af1ae4 movw AX,!0xfe41a
ram:01d3ca e7 onew BC
ram:01d3cb c3 push BC
ram:01d3cc 12 movw BC,AX
ram:01d3cd 17 movw AX,HL
ram:01d3ce 040200 addw AX,0x2
ram:01d3d1 c1 push AX
ram:01d3d2 491600 mov A,!0xf0016[BC]
ram:01d3d5 9dd4 mov 0xffdf4,A
ram:01d3d7 791400 movw AX,!0xf0014[BC]
ram:01d3da c1 push AX
ram:01d3db 8dd4 mov A,0xffdf4
ram:01d3dd 9dd6 mov 0xffdf6,A
ram:01d3df c0 pop AX
ram:01d3e0 14 movw DE,AX
ram:01d3e1 301000 movw AX,0x10
ram:01d3e4 f7 clrw BC
ram:01d3e5 c1 push AX
ram:01d3e6 8dd6 mov A,0xffdf6
ram:01d3e8 9efc mov CS,A
ram:01d3ea c0 pop AX
ram:01d3eb 61ea call DE
ram:01d3ed 1004 addw SP,0x4
ram:01d3ef 8c02 mov A,[HL + 0x2]
ram:01d3f1 d1 cmp0 A
ram:01d3f2 dd26 bz $ 0x1d41a
ram:01d3f4 af02e4 movw AX,!0xfe402
ram:01d3f7 3442e9 movw DE,0xe942
ram:01d3fa c5 push DE
ram:01d3fb 14 movw DE,AX
ram:01d3fc 8a1a mov A,[DE + 0x1a]
ram:01d3fe 9efc mov CS,A
ram:01d400 aa18 movw AX,[DE + 0x18]
ram:01d402 14 movw DE,AX
ram:01d403 303100 movw AX,0x31
ram:01d406 61ea call DE
ram:01d408 c0 pop AX
ram:01d409 d942e9 mov X,!0xfe942
ram:01d40c f1 clrb A
ram:01d40d 60 mov A,
ram:01d40e 718c mov1 CY,A.0x0
ram:01d410 8f31e2 mov A,!0xfe231
ram:01d413 7199 mov1 A.0x1,CY
ram:01d415 9f31e2 mov !0xfe231,A
ram:01d418 ef2a br $ 0x1d444
ram:01d41a 711831e2 clr1 !0xfe231.0x1
ram:01d41e ef24 br $ 0x1d444
ram:01d420 af02e4 movw AX,!0xfe402
ram:01d423 3442e9 movw DE,0xe942
ram:01d426 c5 push DE
ram:01d427 14 movw DE,AX
ram:01d428 8a1a mov A,[DE + 0x1a]
ram:01d42a 9efc mov CS,A
ram:01d42c aa18 movw AX,[DE + 0x18]
ram:01d42e 14 movw DE,AX
ram:01d42f 303100 movw AX,0x31
ram:01d432 61ea call DE
ram:01d434 c0 pop AX
ram:01d435 d942e9 mov X,!0xfe942
ram:01d438 f1 clrb A
ram:01d439 60 mov A,
ram:01d43a 718c mov1 CY,A.0x0
ram:01d43c 8f31e2 mov A,!0xfe231
ram:01d43f 7199 mov1 A.0x1,CY
ram:01d441 9f31e2 mov !0xfe231,A
ram:01d444 f569e2 clrb !0xfe269
ram:01d447 f568e2 clrb !0xfe268
ram:01d44a 1004 addw SP,0x4
ram:01d44c c6 pop HL
ram:01d44d d7 ret
ram:01d48e c7 push HL
ram:01d48f 2004 subw SP,0x4
ram:01d491 fbf8ff movw HL,!0xffff8
ram:01d494 fc8e7500 call !!0x758e
ram:01d498 13 movw AX,BC
ram:01d499 bf36e2 movw !0xfe236,AX
ram:01d49c bb movw [HL],AX
ram:01d49d 8f30e2 mov A,!0xfe230
ram:01d4a0 31de shrw AX,0xd
ram:01d4a2 312d shlw AX,0x2
ram:01d4a4 12 movw BC,AX
ram:01d4a5 312d shlw AX,0x2
ram:01d4a7 03 addw AX,BC
ram:01d4a8 042c5d addw AX,0x5d2c
ram:01d4ab 14 movw DE,AX
ram:01d4ac 8f31e2 mov A,!0xfe231
ram:01d4af 3119 shl A,0x1
ram:01d4b1 31ce shrw AX,0xc
ram:01d4b3 01 addw AX,AX
ram:01d4b4 05 addw AX,DE
ram:01d4b5 14 movw DE,AX
ram:01d4b6 a9 movw AX,[DE]
ram:01d4b7 614900 cmpw AX,[HL + 0x0]
ram:01d4ba de44 bnc $ 0x1d500
ram:01d4bc 8f31e2 mov A,!0xfe231
ram:01d4bf 0c08 add A,#0x8
ram:01d4c1 5c78 and A,#0x78
ram:01d4c3 70 mov ,A
ram:01d4c4 8f31e2 mov A,!0xfe231
ram:01d4c7 5c87 and A,#0x87
ram:01d4c9 6168 or A,
ram:01d4cb 9f31e2 mov !0xfe231,A
ram:01d4ce 5c78 and A,#0x78
ram:01d4d0 4c50 cmp A,#0x50
ram:01d4d2 df0a bnz $ 0x1d4de
ram:01d4d4 8f31e2 mov A,!0xfe231
ram:01d4d7 5c87 and A,#0x87
ram:01d4d9 6c48 or A,#0x48
ram:01d4db 9f31e2 mov !0xfe231,A
ram:01d4de 8f31e2 mov A,!0xfe231
ram:01d4e1 3119 shl A,0x1
ram:01d4e3 314a shr A,0x4
ram:01d4e5 9c03 mov [HL + 0x3],A
ram:01d4e7 db0ae4 movw BC,!0xfe40a
ram:01d4ea 17 movw AX,HL
ram:01d4eb 040300 addw AX,0x3
ram:01d4ee c1 push AX
ram:01d4ef 490e00 mov A,!0xf000e[BC]
ram:01d4f2 9efc mov CS,A
ram:01d4f4 790c00 movw AX,!0xf000c[BC]
ram:01d4f7 14 movw DE,AX
ram:01d4f8 301400 movw AX,0x14
ram:01d4fb 61ea call DE
ram:01d4fd c0 pop AX
ram:01d4fe ef4e br $ 0x1d54e
ram:01d500 8f30e2 mov A,!0xfe230
ram:01d503 31de shrw AX,0xd
ram:01d505 312d shlw AX,0x2
ram:01d507 12 movw BC,AX
ram:01d508 312d shlw AX,0x2
ram:01d50a 03 addw AX,BC
ram:01d50b 04a45d addw AX,0x5da4
ram:01d50e 14 movw DE,AX
ram:01d50f 8f31e2 mov A,!0xfe231
ram:01d512 3119 shl A,0x1
ram:01d514 31ce shrw AX,0xc
ram:01d516 01 addw AX,AX
ram:01d517 05 addw AX,DE
ram:01d518 14 movw DE,AX
ram:01d519 a9 movw AX,[DE]
ram:01d51a 12 movw BC,AX
ram:01d51b ab movw AX,[HL]
ram:01d51c 43 cmpw AX,BC
ram:01d51d de2f bnc $ 0x1d54e
ram:01d51f 8f31e2 mov A,!0xfe231
ram:01d522 2c08 sub A,#0x8
ram:01d524 5c78 and A,#0x78
ram:01d526 70 mov ,A
ram:01d527 8f31e2 mov A,!0xfe231
ram:01d52a 5c87 and A,#0x87
ram:01d52c 6168 or A,
ram:01d52e 9f31e2 mov !0xfe231,A
ram:01d531 3119 shl A,0x1
ram:01d533 314a shr A,0x4
ram:01d535 9c03 mov [HL + 0x3],A
ram:01d537 db0ae4 movw BC,!0xfe40a
ram:01d53a 17 movw AX,HL
ram:01d53b 040300 addw AX,0x3
ram:01d53e c1 push AX
ram:01d53f 490e00 mov A,!0xf000e[BC]
ram:01d542 9efc mov CS,A
ram:01d544 790c00 movw AX,!0xf000c[BC]
ram:01d547 14 movw DE,AX
ram:01d548 301400 movw AX,0x14
ram:01d54b 61ea call DE
ram:01d54d c0 pop AX
ram:01d54e 1004 addw SP,0x4
ram:01d550 c6 pop HL
ram:01d551 d7 ret
ram:01d552 c7 push HL
ram:01d553 c1 push AX
ram:01d554 c1 push AX
ram:01d555 fbf8ff movw HL,!0xffff8
ram:01d558 af38e2 movw AX,!0xfe238
ram:01d55b 312e shrw AX,0x2
ram:01d55d 12 movw BC,AX
ram:01d55e ac02 movw AX,[HL + 0x2]
ram:01d560 311e shrw AX,0x1
ram:01d562 03 addw AX,BC
ram:01d563 12 movw BC,AX
ram:01d564 ac02 movw AX,[HL + 0x2]
ram:01d566 312e shrw AX,0x2
ram:01d568 03 addw AX,BC
ram:01d569 bf38e2 movw !0xfe238,AX
ram:01d56c 303c5e movw AX,0x5e3c
ram:01d56f 425ae2 cmpw AX,!0xfe25a
ram:01d572 dd28 bz $ 0x1d59c
ram:01d574 eb5ae2 movw DE,!0xfe25a
ram:01d577 aa12 movw AX,[DE + 0x12]
ram:01d579 4238e2 cmpw AX,!0xfe238
ram:01d57c de1e bnc $ 0x1d59c
ram:01d57e 8f3de9 mov A,!0xfe93d
ram:01d581 a03de9 inc !0xfe93d
ram:01d584 4c1a cmp A,#0x1a
ram:01d586 dc54 bc $ 0x1d5dc
ram:01d588 403de9ff cmp !0xfe93d,0xff
ram:01d58c 61c8 skc
ram:01d58e cf3de9fe _mov !0xfe93d,0xfe
ram:01d592 71003ce9 set1 !0xfe93c.0x0
ram:01d596 71103ce9 set1 !0xfe93c.0x1
ram:01d59a ef40 br $ 0x1d5dc
ram:01d59c 303c5e movw AX,0x5e3c
ram:01d59f 425ae2 cmpw AX,!0xfe25a
ram:01d5a2 dd2a bz $ 0x1d5ce
ram:01d5a4 eb5ae2 movw DE,!0xfe25a
ram:01d5a7 aa08 movw AX,[DE + 0x8]
ram:01d5a9 12 movw BC,AX
ram:01d5aa af38e2 movw AX,!0xfe238
ram:01d5ad 43 cmpw AX,BC
ram:01d5ae de1e bnc $ 0x1d5ce
ram:01d5b0 8f3ee9 mov A,!0xfe93e
ram:01d5b3 a03ee9 inc !0xfe93e
ram:01d5b6 4c1a cmp A,#0x1a
ram:01d5b8 dc22 bc $ 0x1d5dc
ram:01d5ba 403ee9ff cmp !0xfe93e,0xff
ram:01d5be 61c8 skc
ram:01d5c0 cf3ee9fe _mov !0xfe93e,0xfe
ram:01d5c4 71203ce9 set1 !0xfe93c.0x2
ram:01d5c8 71303ce9 set1 !0xfe93c.0x3
ram:01d5cc ef0e br $ 0x1d5dc
ram:01d5ce f53de9 clrb !0xfe93d
ram:01d5d1 f53ee9 clrb !0xfe93e
ram:01d5d4 71083ce9 clr1 !0xfe93c.0x0
ram:01d5d8 71283ce9 clr1 !0xfe93c.0x2
ram:01d5dc 8f32e2 mov A,!0xfe232
ram:01d5df 5c07 and A,#0x7
ram:01d5e1 9b mov [HL],A
ram:01d5e2 cc0100 mov [HL + 0x1],0x0
ram:01d5e5 8c01 mov A,[HL + 0x1]
ram:01d5e7 4c08 cmp A,#0x8
ram:01d5e9 de30 bnc $ 0x1d61b
ram:01d5eb 8b mov A,[HL]
ram:01d5ec 3119 shl A,0x1
ram:01d5ee f0 clrb X
ram:01d5ef 317e shrw AX,0x7
ram:01d5f1 025ae2 addw AX,!0xfe25a
ram:01d5f4 14 movw DE,AX
ram:01d5f5 a9 movw AX,[DE]
ram:01d5f6 12 movw BC,AX
ram:01d5f7 af38e2 movw AX,!0xfe238
ram:01d5fa 43 cmpw AX,BC
ram:01d5fb de05 bnc $ 0x1d602
ram:01d5fd 616900 dec [HL + 0x0]
ram:01d600 ef14 br $ 0x1d616
ram:01d602 8b mov A,[HL]
ram:01d603 3119 shl A,0x1
ram:01d605 f0 clrb X
ram:01d606 317e shrw AX,0x7
ram:01d608 025ae2 addw AX,!0xfe25a
ram:01d60b 14 movw DE,AX
ram:01d60c aa02 movw AX,[DE + 0x2]
ram:01d60e 4238e2 cmpw AX,!0xfe238
ram:01d611 de08 bnc $ 0x1d61b
ram:01d613 615900 inc [HL + 0x0]
ram:01d616 615901 inc [HL + 0x1]
ram:01d619 efca br $ 0x1d5e5
ram:01d61b 8f32e2 mov A,!0xfe232
ram:01d61e 5c07 and A,#0x7
ram:01d620 4d cmp A,[HL]
ram:01d621 dd21 bz $ 0x1d644
ram:01d623 8b mov A,[HL]
ram:01d624 5c07 and A,#0x7
ram:01d626 3432e2 movw DE,0xe232
ram:01d629 70 mov ,A
ram:01d62a 89 mov A,[DE]
ram:01d62b 5cf8 and A,#0xf8
ram:01d62d 6168 or A,
ram:01d62f 99 mov [DE],A
ram:01d630 db00e4 movw BC,!0xfe400
ram:01d633 17 movw AX,HL
ram:01d634 c1 push AX
ram:01d635 491a00 mov A,!0xf001a[BC]
ram:01d638 9efc mov CS,A
ram:01d63a 791800 movw AX,!0xf0018[BC]
ram:01d63d 14 movw DE,AX
ram:01d63e 300400 movw AX,0x4
ram:01d641 61ea call DE
ram:01d643 c0 pop AX
ram:01d644 1004 addw SP,0x4
ram:01d646 c6 pop HL
ram:01d647 d7 ret
ram:01d648 c7 push HL
ram:01d649 c1 push AX
ram:01d64a c1 push AX
ram:01d64b fbf8ff movw HL,!0xffff8
ram:01d64e ac02 movw AX,[HL + 0x2]
ram:01d650 440101 cmpw AX,0x101
ram:01d653 dc05 bc $ 0x1d65a
ram:01d655 cc0100 mov [HL + 0x1],0x0
ram:01d658 ef03 br $ 0x1d65d
ram:01d65a cc0101 mov [HL + 0x1],0x1
ram:01d65d 8f30e2 mov A,!0xfe230
ram:01d660 3139 shl A,0x3
ram:01d662 317a shr A,0x7
ram:01d664 4e01 cmp A,[HL + 0x1]
ram:01d666 dd20 bz $ 0x1d688
ram:01d668 8c01 mov A,[HL + 0x1]
ram:01d66a 3430e2 movw DE,0xe230
ram:01d66d 718c mov1 CY,A.0x0
ram:01d66f 89 mov A,[DE]
ram:01d670 71c9 mov1 A.0x4,CY
ram:01d672 99 mov [DE],A
ram:01d673 db00e4 movw BC,!0xfe400
ram:01d676 17 movw AX,HL
ram:01d677 a1 incw AX
ram:01d678 c1 push AX
ram:01d679 491a00 mov A,!0xf001a[BC]
ram:01d67c 9efc mov CS,A
ram:01d67e 791800 movw AX,!0xf0018[BC]
ram:01d681 14 movw DE,AX
ram:01d682 300300 movw AX,0x3
ram:01d685 61ea call DE
ram:01d687 c0 pop AX
ram:01d688 1004 addw SP,0x4
ram:01d68a c6 pop HL
ram:01d68b d7 ret
ram:01d68c c7 push HL
ram:01d68d c1 push AX
ram:01d68e fbf8ff movw HL,!0xffff8
ram:01d691 31040303 bf 0xffe23.0x0,$ 0x1d696
ram:01d695 f1 clrb A
ram:01d696 ef01 br $ 0x1d699
ram:01d698 e1 oneb A
ram:01d699 9c01 mov [HL + 0x1],A
ram:01d69b 8f30e2 mov A,!0xfe230
ram:01d69e 3149 shl A,0x4
ram:01d6a0 317a shr A,0x7
ram:01d6a2 4e01 cmp A,[HL + 0x1]
ram:01d6a4 dd14 bz $ 0x1d6ba
ram:01d6a6 8c01 mov A,[HL + 0x1]
ram:01d6a8 3430e2 movw DE,0xe230
ram:01d6ab 718c mov1 CY,A.0x0
ram:01d6ad 89 mov A,[DE]
ram:01d6ae 71b9 mov1 A.0x3,CY
ram:01d6b0 99 mov [DE],A
ram:01d6b1 f6 clrw AX
ram:01d6b2 bf60e2 movw !0xfe260,AX
ram:01d6b5 bf62e2 movw !0xfe262,AX
ram:01d6b8 ef6b br $ 0x1d725
ram:01d6ba db62e2 movw BC,!0xfe262
ram:01d6bd af60e2 movw AX,!0xfe260
ram:01d6c0 040100 addw AX,0x1
ram:01d6c3 61d8 sknc
ram:01d6c5 a3 _incw BC
ram:01d6c6 bf60e2 movw !0xfe260,AX
ram:01d6c9 33 xchw AX,BC
ram:01d6ca bf62e2 movw !0xfe262,AX
ram:01d6cd 33 xchw AX,BC
ram:01d6ce 240100 subw AX,0x1
ram:01d6d1 61d8 sknc
ram:01d6d3 b3 _decw BC
ram:01d6d4 33 xchw AX,BC
ram:01d6d5 440000 cmpw AX,0x0
ram:01d6d8 33 xchw AX,BC
ram:01d6d9 61f8 sknz
ram:01d6db 440500 _cmpw AX,0x5
ram:01d6de dc45 bc $ 0x1d725
ram:01d6e0 af00e4 movw AX,!0xfe400
ram:01d6e3 e7 onew BC
ram:01d6e4 c3 push BC
ram:01d6e5 12 movw BC,AX
ram:01d6e6 17 movw AX,HL
ram:01d6e7 c1 push AX
ram:01d6e8 491600 mov A,!0xf0016[BC]
ram:01d6eb 9dd4 mov 0xffdf4,A
ram:01d6ed 791400 movw AX,!0xf0014[BC]
ram:01d6f0 c1 push AX
ram:01d6f1 8dd4 mov A,0xffdf4
ram:01d6f3 9dd6 mov 0xffdf6,A
ram:01d6f5 c0 pop AX
ram:01d6f6 14 movw DE,AX
ram:01d6f7 304500 movw AX,0x45
ram:01d6fa f7 clrw BC
ram:01d6fb c1 push AX
ram:01d6fc 8dd6 mov A,0xffdf6
ram:01d6fe 9efc mov CS,A
ram:01d700 c0 pop AX
ram:01d701 61ea call DE
ram:01d703 1004 addw SP,0x4
ram:01d705 8b mov A,[HL]
ram:01d706 4e01 cmp A,[HL + 0x1]
ram:01d708 dd14 bz $ 0x1d71e
ram:01d70a db00e4 movw BC,!0xfe400
ram:01d70d 17 movw AX,HL
ram:01d70e a1 incw AX
ram:01d70f c1 push AX
ram:01d710 491a00 mov A,!0xf001a[BC]
ram:01d713 9efc mov CS,A
ram:01d715 791800 movw AX,!0xf0018[BC]
ram:01d718 14 movw DE,AX
ram:01d719 e6 onew AX
ram:01d71a a1 incw AX
ram:01d71b 61ea call DE
ram:01d71d c0 pop AX
ram:01d71e f6 clrw AX
ram:01d71f bf60e2 movw !0xfe260,AX
ram:01d722 bf62e2 movw !0xfe262,AX
ram:01d725 c0 pop AX
ram:01d726 c6 pop HL
ram:01d727 d7 ret
ram:01d728 c7 push HL
ram:01d729 c1 push AX
ram:01d72a c1 push AX
ram:01d72b fbf8ff movw HL,!0xffff8
ram:01d72e f6 clrw AX
ram:01d72f bb movw [HL],AX
ram:01d730 ac02 movw AX,[HL + 0x2]
ram:01d732 bf40e9 movw !0xfe940,AX
ram:01d735 429e5e cmpw AX,!0xf5e9e
ram:01d738 dc0c bc $ 0x1d746
ram:01d73a af9c5e movw AX,!0xf5e9c
ram:01d73d 614902 cmpw AX,[HL + 0x2]
ram:01d740 dc04 bc $ 0x1d746
ram:01d742 f6 clrw AX
ram:01d743 bb movw [HL],AX
ram:01d744 ef59 br $ 0x1d79f
ram:01d746 ac02 movw AX,[HL + 0x2]
ram:01d748 42a25e cmpw AX,!0xf5ea2
ram:01d74b dc0c bc $ 0x1d759
ram:01d74d afa05e movw AX,!0xf5ea0
ram:01d750 614902 cmpw AX,[HL + 0x2]
ram:01d753 dc04 bc $ 0x1d759
ram:01d755 e6 onew AX
ram:01d756 bb movw [HL],AX
ram:01d757 ef46 br $ 0x1d79f
ram:01d759 ac02 movw AX,[HL + 0x2]
ram:01d75b 42a65e cmpw AX,!0xf5ea6
ram:01d75e dc0d bc $ 0x1d76d
ram:01d760 afa45e movw AX,!0xf5ea4
ram:01d763 614902 cmpw AX,[HL + 0x2]
ram:01d766 dc05 bc $ 0x1d76d
ram:01d768 e6 onew AX
ram:01d769 a1 incw AX
ram:01d76a bb movw [HL],AX
ram:01d76b ef32 br $ 0x1d79f
ram:01d76d ac02 movw AX,[HL + 0x2]
ram:01d76f 42aa5e cmpw AX,!0xf5eaa
ram:01d772 dc0e bc $ 0x1d782
ram:01d774 afa85e movw AX,!0xf5ea8
ram:01d777 614902 cmpw AX,[HL + 0x2]
ram:01d77a dc06 bc $ 0x1d782
ram:01d77c 300300 movw AX,0x3
ram:01d77f bb movw [HL],AX
ram:01d780 ef1d br $ 0x1d79f
ram:01d782 ac02 movw AX,[HL + 0x2]
ram:01d784 42ae5e cmpw AX,!0xf5eae
ram:01d787 dc0e bc $ 0x1d797
ram:01d789 afac5e movw AX,!0xf5eac
ram:01d78c 614902 cmpw AX,[HL + 0x2]
ram:01d78f dc06 bc $ 0x1d797
ram:01d791 300400 movw AX,0x4
ram:01d794 bb movw [HL],AX
ram:01d795 ef08 br $ 0x1d79f
ram:01d797 8f32e2 mov A,!0xfe232
ram:01d79a 3129 shl A,0x2
ram:01d79c 31de shrw AX,0xd
ram:01d79e bb movw [HL],AX
ram:01d79f 8f32e2 mov A,!0xfe232
ram:01d7a2 3129 shl A,0x2
ram:01d7a4 31de shrw AX,0xd
ram:01d7a6 614900 cmpw AX,[HL + 0x0]
ram:01d7a9 dd56 bz $ 0x1d801
ram:01d7ab 8b mov A,[HL]
ram:01d7ac 3139 shl A,0x3
ram:01d7ae 5c38 and A,#0x38
ram:01d7b0 3432e2 movw DE,0xe232
ram:01d7b3 70 mov ,A
ram:01d7b4 89 mov A,[DE]
ram:01d7b5 5cc7 and A,#0xc7
ram:01d7b7 6168 or A,
ram:01d7b9 99 mov [DE],A
ram:01d7ba 3129 shl A,0x2
ram:01d7bc 315a shr A,0x5
ram:01d7be 4c04 cmp A,#0x4
ram:01d7c0 dc1a bc $ 0x1d7dc
ram:01d7c2 d55ee2 cmp0 !0xfe25e
ram:01d7c5 df3a bnz $ 0x1d801
ram:01d7c7 303075 movw AX,0x7530
ram:01d7ca c1 push AX
ram:01d7cb 30b4d0 movw AX,0xd0b4
ram:01d7ce 5201 mov ,0x1
ram:01d7d0 f3 clrb B
ram:01d7d1 fcea7d00 call !!0x7dea
ram:01d7d5 c0 pop AX
ram:01d7d6 62 mov A,
ram:01d7d7 9f5ee2 mov !0xfe25e,A
ram:01d7da ef25 br $ 0x1d801
ram:01d7dc d55ee2 cmp0 !0xfe25e
ram:01d7df dd20 bz $ 0x1d801
ram:01d7e1 af02e4 movw AX,!0xfe402
ram:01d7e4 3440e9 movw DE,0xe940
ram:01d7e7 c5 push DE
ram:01d7e8 14 movw DE,AX
ram:01d7e9 8a1a mov A,[DE + 0x1a]
ram:01d7eb 9efc mov CS,A
ram:01d7ed aa18 movw AX,[DE + 0x18]
ram:01d7ef 14 movw DE,AX
ram:01d7f0 303500 movw AX,0x35
ram:01d7f3 61ea call DE
ram:01d7f5 c0 pop AX
ram:01d7f6 d95ee2 mov X,!0xfe25e
ram:01d7f9 f1 clrb A
ram:01d7fa fc927e00 call !!0x7e92
ram:01d7fe f55ee2 clrb !0xfe25e
ram:01d801 1004 addw SP,0x4
ram:01d803 c6 pop HL
ram:01d804 d7 ret
ram:01d805 c7 push HL
ram:01d806 c1 push AX
ram:01d807 c1 push AX
ram:01d808 fbf8ff movw HL,!0xffff8
ram:01d80b cc0103 mov [HL + 0x1],0x3
ram:01d80e ac0a movw AX,[HL + 0xa]
ram:01d810 443300 cmpw AX,0x33
ram:01d813 dc0a bc $ 0x1d81f
ram:01d815 ac0a movw AX,[HL + 0xa]
ram:01d817 44c800 cmpw AX,0xc8
ram:01d81a de03 bnc $ 0x1d81f
ram:01d81c f7 clrw BC
ram:01d81d ef0c br $ 0x1d82b
ram:01d81f ac02 movw AX,[HL + 0x2]
ram:01d821 44d700 cmpw AX,0xd7
ram:01d824 de03 bnc $ 0x1d829
ram:01d826 e7 onew BC
ram:01d827 ef02 br $ 0x1d82b
ram:01d829 e7 onew BC
ram:01d82a a3 incw BC
ram:01d82b 1004 addw SP,0x4
ram:01d82d c6 pop HL
ram:01d82e d7 ret
ram:01d82f c7 push HL
ram:01d830 c1 push AX
ram:01d831 fbf8ff movw HL,!0xffff8
ram:01d834 ab movw AX,[HL]
ram:01d835 446400 cmpw AX,0x64
ram:01d838 de03 bnc $ 0x1d83d
ram:01d83a f7 clrw BC
ram:01d83b ef0c br $ 0x1d849
ram:01d83d ac08 movw AX,[HL + 0x8]
ram:01d83f 44fa00 cmpw AX,0xfa
ram:01d842 de03 bnc $ 0x1d847
ram:01d844 e7 onew BC
ram:01d845 ef02 br $ 0x1d849
ram:01d847 e7 onew BC
ram:01d848 a3 incw BC
ram:01d849 c0 pop AX
ram:01d84a c6 pop HL
ram:01d84b d7 ret
ram:01d84c c7 push HL
ram:01d84d c1 push AX
ram:01d84e c1 push AX
ram:01d84f fbf8ff movw HL,!0xffff8
ram:01d852 cc0102 mov [HL + 0x1],0x2
ram:01d855 ac0a movw AX,[HL + 0xa]
ram:01d857 446400 cmpw AX,0x64
ram:01d85a de03 bnc $ 0x1d85f
ram:01d85c f7 clrw BC
ram:01d85d ef0c br $ 0x1d86b
ram:01d85f ac02 movw AX,[HL + 0x2]
ram:01d861 447f00 cmpw AX,0x7f
ram:01d864 de03 bnc $ 0x1d869
ram:01d866 e7 onew BC
ram:01d867 ef02 br $ 0x1d86b
ram:01d869 e7 onew BC
ram:01d86a a3 incw BC
ram:01d86b 1004 addw SP,0x4
ram:01d86d c6 pop HL
ram:01d86e d7 ret
ram:01d86f c7 push HL
ram:01d870 c1 push AX
ram:01d871 c1 push AX
ram:01d872 fbf8ff movw HL,!0xffff8
ram:01d875 cc0102 mov [HL + 0x1],0x2
ram:01d878 ac02 movw AX,[HL + 0x2]
ram:01d87a 441701 cmpw AX,0x117
ram:01d87d 61d8 sknc
ram:01d87f cc0101 _mov [HL + 0x1],0x1
ram:01d882 ac02 movw AX,[HL + 0x2]
ram:01d884 444703 cmpw AX,0x347
ram:01d887 61c8 skc
ram:01d889 cc0100 _mov [HL + 0x1],0x0
ram:01d88c 8c01 mov A,[HL + 0x1]
ram:01d88e 318e shrw AX,0x8
ram:01d890 12 movw BC,AX
ram:01d891 1004 addw SP,0x4
ram:01d893 c6 pop HL
ram:01d894 d7 ret
ram:01d895 c7 push HL
ram:01d896 c1 push AX
ram:01d897 2004 subw SP,0x4
ram:01d899 fbf8ff movw HL,!0xffff8
ram:01d89c cc0300 mov [HL + 0x3],0x0
ram:01d89f ac04 movw AX,[HL + 0x4]
ram:01d8a1 14 movw DE,AX
ram:01d8a2 8a04 mov A,[DE + 0x4]
ram:01d8a4 5c01 and A,#0x1
ram:01d8a6 318e shrw AX,0x8
ram:01d8a8 e7 onew BC
ram:01d8a9 240000 subw AX,0x0
ram:01d8ac dd06 bz $ 0x1d8b4
ram:01d8ae 23 subw AX,BC
ram:01d8af dd0a bz $ 0x1d8bb
ram:01d8b1 eee100 br $! 0x1d995
ram:01d8b4 fcb27a00 call !!0x7ab2
ram:01d8b8 eeda00 br $! 0x1d995
ram:01d8bb 303ae2 movw AX,0xe23a
ram:01d8be bb movw [HL],AX
ram:01d8bf fcbf7a00 call !!0x7abf
ram:01d8c3 92 dec 
ram:01d8c4 61e8 skz
ram:01d8c6 eecc00 _br $! 0x1d995
ram:01d8c9 ab movw AX,[HL]
ram:01d8ca 14 movw DE,AX
ram:01d8cb aa0e movw AX,[DE + 0xe]
ram:01d8cd a244e9 incw !0xfe944
ram:01d8d0 db44e9 movw BC,!0xfe944
ram:01d8d3 311c shlw BC,0x1
ram:01d8d5 786ae2 movw !0xfe26a[BC],AX
ram:01d8d8 304000 movw AX,0x40
ram:01d8db 4244e9 cmpw AX,!0xfe944
ram:01d8de df04 bnz $ 0x1d8e4
ram:01d8e0 f6 clrw AX
ram:01d8e1 bf44e9 movw !0xfe944,AX
ram:01d8e4 ab movw AX,[HL]
ram:01d8e5 14 movw DE,AX
ram:01d8e6 aa0e movw AX,[DE + 0xe]
ram:01d8e8 fc52d501 call !!0x1d552
ram:01d8ec ab movw AX,[HL]
ram:01d8ed 14 movw DE,AX
ram:01d8ee aa02 movw AX,[DE + 0x2]
ram:01d8f0 c1 push AX
ram:01d8f1 aa04 movw AX,[DE + 0x4]
ram:01d8f3 fc05d801 call !!0x1d805
ram:01d8f7 c0 pop AX
ram:01d8f8 62 mov A,
ram:01d8f9 5c03 and A,#0x3
ram:01d8fb 70 mov ,A
ram:01d8fc 8f33e2 mov A,!0xfe233
ram:01d8ff 5cfc and A,#0xfc
ram:01d901 6168 or A,
ram:01d903 9f33e2 mov !0xfe233,A
ram:01d906 ab movw AX,[HL]
ram:01d907 14 movw DE,AX
ram:01d908 aa16 movw AX,[DE + 0x16]
ram:01d90a c1 push AX
ram:01d90b aa18 movw AX,[DE + 0x18]
ram:01d90d fc4cd801 call !!0x1d84c
ram:01d911 c0 pop AX
ram:01d912 62 mov A,
ram:01d913 3129 shl A,0x2
ram:01d915 5c0c and A,#0xc
ram:01d917 70 mov ,A
ram:01d918 8f33e2 mov A,!0xfe233
ram:01d91b 5cf3 and A,#0xf3
ram:01d91d 6168 or A,
ram:01d91f 9f33e2 mov !0xfe233,A
ram:01d922 ab movw AX,[HL]
ram:01d923 14 movw DE,AX
ram:01d924 aa10 movw AX,[DE + 0x10]
ram:01d926 fc6fd801 call !!0x1d86f
ram:01d92a 62 mov A,
ram:01d92b 3149 shl A,0x4
ram:01d92d 5c30 and A,#0x30
ram:01d92f 70 mov ,A
ram:01d930 8f33e2 mov A,!0xfe233
ram:01d933 5ccf and A,#0xcf
ram:01d935 6168 or A,
ram:01d937 9f33e2 mov !0xfe233,A
ram:01d93a af00e4 movw AX,!0xfe400
ram:01d93d e7 onew BC
ram:01d93e c3 push BC
ram:01d93f 12 movw BC,AX
ram:01d940 17 movw AX,HL
ram:01d941 040300 addw AX,0x3
ram:01d944 c1 push AX
ram:01d945 491600 mov A,!0xf0016[BC]
ram:01d948 9dd4 mov 0xffdf4,A
ram:01d94a 791400 movw AX,!0xf0014[BC]
ram:01d94d c1 push AX
ram:01d94e 8dd4 mov A,0xffdf4
ram:01d950 9dd6 mov 0xffdf6,A
ram:01d952 c0 pop AX
ram:01d953 14 movw DE,AX
ram:01d954 304600 movw AX,0x46
ram:01d957 f7 clrw BC
ram:01d958 c1 push AX
ram:01d959 8dd6 mov A,0xffdf6
ram:01d95b 9efc mov CS,A
ram:01d95d c0 pop AX
ram:01d95e 61ea call DE
ram:01d960 1004 addw SP,0x4
ram:01d962 8c03 mov A,[HL + 0x3]
ram:01d964 91 dec 
ram:01d965 df1a bnz $ 0x1d981
ram:01d967 ab movw AX,[HL]
ram:01d968 14 movw DE,AX
ram:01d969 aa08 movw AX,[DE + 0x8]
ram:01d96b c1 push AX
ram:01d96c aa06 movw AX,[DE + 0x6]
ram:01d96e fc2fd801 call !!0x1d82f
ram:01d972 c0 pop AX
ram:01d973 62 mov A,
ram:01d974 3169 shl A,0x6
ram:01d976 70 mov ,A
ram:01d977 8f33e2 mov A,!0xfe233
ram:01d97a 5c3f and A,#0x3f
ram:01d97c 6168 or A,
ram:01d97e 9f33e2 mov !0xfe233,A
ram:01d981 ab movw AX,[HL]
ram:01d982 14 movw DE,AX
ram:01d983 aa0e movw AX,[DE + 0xe]
ram:01d985 c1 push AX
ram:01d986 aa14 movw AX,[DE + 0x14]
ram:01d988 fc48d601 call !!0x1d648
ram:01d98c c0 pop AX
ram:01d98d ab movw AX,[HL]
ram:01d98e 14 movw DE,AX
ram:01d98f aa0c movw AX,[DE + 0xc]
ram:01d991 fc28d701 call !!0x1d728
ram:01d995 ac04 movw AX,[HL + 0x4]
ram:01d997 14 movw DE,AX
ram:01d998 aa04 movw AX,[DE + 0x4]
ram:01d99a 5205 mov ,0x5
ram:01d99c fd1c06 call !0xf061c
ram:01d99f 13 movw AX,BC
ram:01d9a0 f1 clrb A
ram:01d9a1 440200 cmpw AX,0x2
ram:01d9a4 61f8 sknz
ram:01d9a6 fce6d001 _call !!0x1d0e6
ram:01d9aa fc8cd601 call !!0x1d68c
ram:01d9ae ac04 movw AX,[HL + 0x4]
ram:01d9b0 14 movw DE,AX
ram:01d9b1 aa04 movw AX,[DE + 0x4]
ram:01d9b3 5205 mov ,0x5
ram:01d9b5 fd1c06 call !0xf061c
ram:01d9b8 13 movw AX,BC
ram:01d9b9 f1 clrb A
ram:01d9ba 440400 cmpw AX,0x4
ram:01d9bd df08 bnz $ 0x1d9c7
ram:01d9bf fc15d301 call !!0x1d315
ram:01d9c3 fcdad201 call !!0x1d2da
ram:01d9c7 ac04 movw AX,[HL + 0x4]
ram:01d9c9 14 movw DE,AX
ram:01d9ca aa04 movw AX,[DE + 0x4]
ram:01d9cc 440200 cmpw AX,0x2
ram:01d9cf 61f8 sknz
ram:01d9d1 fc8ed401 _call !!0x1d48e
ram:01d9d5 ac04 movw AX,[HL + 0x4]
ram:01d9d7 14 movw DE,AX
ram:01d9d8 aa04 movw AX,[DE + 0x4]
ram:01d9da a1 incw AX
ram:01d9db ba04 movw [DE + 0x4],AX
ram:01d9dd ac04 movw AX,[HL + 0x4]
ram:01d9df 14 movw DE,AX
ram:01d9e0 aa04 movw AX,[DE + 0x4]
ram:01d9e2 520a mov ,0xa
ram:01d9e4 fd1c06 call !0xf061c
ram:01d9e7 13 movw AX,BC
ram:01d9e8 f1 clrb A
ram:01d9e9 ba04 movw [DE + 0x4],AX
ram:01d9eb e7 onew BC
ram:01d9ec 1006 addw SP,0x6
ram:01d9ee c6 pop HL
ram:01d9ef d7 ret
ram:01d9f0 c7 push HL
ram:01d9f1 16 movw HL,AX
ram:01d9f2 66 mov A,
ram:01d9f3 91 dec 
ram:01d9f4 df6d bnz $ 0x1da63
ram:01d9f6 713830e2 clr1 !0xfe230.0x3
ram:01d9fa 714830e2 clr1 !0xfe230.0x4
ram:01d9fe 3430e2 movw DE,0xe230
ram:01da01 89 mov A,[DE]
ram:01da02 5c1f and A,#0x1f
ram:01da04 99 mov [DE],A
ram:01da05 710a2c set1 0xfff2c.0x0
ram:01da08 89 mov A,[DE]
ram:01da09 5cf8 and A,#0xf8
ram:01da0b 99 mov [DE],A
ram:01da0c 8a01 mov A,[DE + 0x1]
ram:01da0e 5cf8 and A,#0xf8
ram:01da10 a5 incw DE
ram:01da11 99 mov [DE],A
ram:01da12 5c87 and A,#0x87
ram:01da14 99 mov [DE],A
ram:01da15 30d001 movw AX,0x1d0
ram:01da18 bf38e2 movw !0xfe238,AX
ram:01da1b a5 incw DE
ram:01da1c 89 mov A,[DE]
ram:01da1d 5cc0 and A,#0xc0
ram:01da1f 99 mov [DE],A
ram:01da20 716832e2 clr1 !0xfe232.0x6
ram:01da24 301c5e movw AX,0x5e1c
ram:01da27 bf5ae2 movw !0xfe25a,AX
ram:01da2a 717832e2 clr1 !0xfe232.0x7
ram:01da2e cf6ae205 mov !0xfe26a,0x5
ram:01da32 cf6be232 mov !0xfe26b,0x32
ram:01da36 a5 incw DE
ram:01da37 89 mov A,[DE]
ram:01da38 5cf0 and A,#0xf0
ram:01da3a 99 mov [DE],A
ram:01da3b 301400 movw AX,0x14
ram:01da3e c1 push AX
ram:01da3f 3095d8 movw AX,0xd895
ram:01da42 5201 mov ,0x1
ram:01da44 f3 clrb B
ram:01da45 fcea7d00 call !!0x7dea
ram:01da49 c0 pop AX
ram:01da4a 62 mov A,
ram:01da4b 9f5ce2 mov !0xfe25c,A
ram:01da4e f55de2 clrb !0xfe25d
ram:01da51 f55ee2 clrb !0xfe25e
ram:01da54 f6 clrw AX
ram:01da55 bf60e2 movw !0xfe260,AX
ram:01da58 bf62e2 movw !0xfe262,AX
ram:01da5b bf64e2 movw !0xfe264,AX
ram:01da5e bf66e2 movw !0xfe266,AX
ram:01da61 ef21 br $ 0x1da84
ram:01da63 301c5e movw AX,0x5e1c
ram:01da66 bf5ae2 movw !0xfe25a,AX
ram:01da69 d95ce2 mov X,!0xfe25c
ram:01da6c f1 clrb A
ram:01da6d fc927e00 call !!0x7e92
ram:01da71 f55ce2 clrb !0xfe25c
ram:01da74 d55ee2 cmp0 !0xfe25e
ram:01da77 dd0b bz $ 0x1da84
ram:01da79 d95ee2 mov X,!0xfe25e
ram:01da7c f1 clrb A
ram:01da7d fc927e00 call !!0x7e92
ram:01da81 f55ee2 clrb !0xfe25e
ram:01da84 c6 pop HL
ram:01da85 d7 ret
ram:01e5cf c7 push HL
ram:01e5d0 16 movw HL,AX
ram:01e5d1 c6 pop HL
ram:01e5d2 d7 ret
ram:01e7b6 c7 push HL
ram:01e7b7 16 movw HL,AX
ram:01e7b8 66 mov A,
ram:01e7b9 91 dec 
ram:01e7ba df04 bnz $ 0x1e7c0
ram:01e7bc f6 clrw AX
ram:01e7bd bfece2 movw !0xfe2ec,AX
ram:01e7c0 c6 pop HL
ram:01e7c1 d7 ret
ram:01eeda c7 push HL
ram:01eedb c1 push AX
ram:01eedc 2004 subw SP,0x4
ram:01eede fbf8ff movw HL,!0xffff8
ram:01eee1 ac0c movw AX,[HL + 0xc]
ram:01eee3 bb movw [HL],AX
ram:01eee4 f6 clrw AX
ram:01eee5 bc02 movw [HL + 0x2],AX
ram:01eee7 ac02 movw AX,[HL + 0x2]
ram:01eee9 61490c cmpw AX,[HL + 0xc]
ram:01eeec de20 bnc $ 0x1ef0e
ram:01eeee ac02 movw AX,[HL + 0x2]
ram:01eef0 610904 addw AX,[HL + 0x4]
ram:01eef3 14 movw DE,AX
ram:01eef4 8c02 mov A,[HL + 0x2]
ram:01eef6 5c03 and A,#0x3
ram:01eef8 318e shrw AX,0x8
ram:01eefa a1 incw AX
ram:01eefb 12 movw BC,AX
ram:01eefc 89 mov A,[DE]
ram:01eefd 318e shrw AX,0x8
ram:01eeff bdd8 movw 0xffdf8,AX
ram:01ef01 13 movw AX,BC
ram:01ef02 fd7304 call !0xf0473
ram:01ef05 610900 addw AX,[HL + 0x0]
ram:01ef08 bb movw [HL],AX
ram:01ef09 617902 incw [HL + 0x2]
ram:01ef0c efd9 br $ 0x1eee7
ram:01ef0e 51ff mov ,0xff
ram:01ef10 5d and A,[HL]
ram:01ef11 318e shrw AX,0x8
ram:01ef13 12 movw BC,AX
ram:01ef14 1006 addw SP,0x6
ram:01ef16 c6 pop HL
ram:01ef17 d7 ret
ram:01ef18 c7 push HL
ram:01ef19 5600 mov ,0x0
ram:01ef1b 66 mov A,
ram:01ef1c 4c04 cmp A,#0x4
ram:01ef1e de0b bnc $ 0x1ef2b
ram:01ef20 f0 clrb X
ram:01ef21 317e shrw AX,0x7
ram:01ef23 12 movw BC,AX
ram:01ef24 3972e300 mov !0xfe372[BC],0x0
ram:01ef28 86 inc 
ram:01ef29 eff0 br $ 0x1ef1b
ram:01ef2b c6 pop HL
ram:01ef2c d7 ret
ram:01ef2d c7 push HL
ram:01ef2e 2004 subw SP,0x4
ram:01ef30 fbf8ff movw HL,!0xffff8
ram:01ef33 8feee2 mov A,!0xfe2ee
ram:01ef36 9c02 mov [HL + 0x2],A
ram:01ef38 f5eee2 clrb !0xfe2ee
ram:01ef3b 30ae00 movw AX,0xae
ram:01ef3e c1 push AX
ram:01ef3f 30eee2 movw AX,0xe2ee
ram:01ef42 fcdaee01 call !!0x1eeda
ram:01ef46 c0 pop AX
ram:01ef47 62 mov A,
ram:01ef48 9c01 mov [HL + 0x1],A
ram:01ef4a 8c02 mov A,[HL + 0x2]
ram:01ef4c 4e01 cmp A,[HL + 0x1]
ram:01ef4e dd15 bz $ 0x1ef65
ram:01ef50 30ae00 movw AX,0xae
ram:01ef53 c1 push AX
ram:01ef54 f6 clrw AX
ram:01ef55 c1 push AX
ram:01ef56 30eee2 movw AX,0xe2ee
ram:01ef59 fc40e500 call !!0xe540
ram:01ef5d 1004 addw SP,0x4
ram:01ef5f cfefe220 mov !0xfe2ef,0x20
ram:01ef63 ef36 br $ 0x1ef9b
ram:01ef65 cfefe220 mov !0xfe2ef,0x20
ram:01ef69 cc0300 mov [HL + 0x3],0x0
ram:01ef6c 8c03 mov A,[HL + 0x3]
ram:01ef6e 4c04 cmp A,#0x4
ram:01ef70 de0f bnc $ 0x1ef81
ram:01ef72 8c03 mov A,[HL + 0x3]
ram:01ef74 f0 clrb X
ram:01ef75 317e shrw AX,0x7
ram:01ef77 12 movw BC,AX
ram:01ef78 3972e300 mov !0xfe372[BC],0x0
ram:01ef7c 615903 inc [HL + 0x3]
ram:01ef7f efeb br $ 0x1ef6c
ram:01ef81 cc0300 mov [HL + 0x3],0x0
ram:01ef84 8c03 mov A,[HL + 0x3]
ram:01ef86 4c08 cmp A,#0x8
ram:01ef88 de11 bnc $ 0x1ef9b
ram:01ef8a 8c03 mov A,[HL + 0x3]
ram:01ef8c f0 clrb X
ram:01ef8d 316e shrw AX,0x6
ram:01ef8f 047ae3 addw AX,0xe37a
ram:01ef92 14 movw DE,AX
ram:01ef93 ca0100 mov [DE + 0x1],0x0
ram:01ef96 615903 inc [HL + 0x3]
ram:01ef99 efe9 br $ 0x1ef84
ram:01ef9b 1004 addw SP,0x4
ram:01ef9d c6 pop HL
ram:01ef9e d7 ret
ram:01ef9f 30ae00 movw AX,0xae
ram:01efa2 c1 push AX
ram:01efa3 30eee2 movw AX,0xe2ee
ram:01efa6 fcdaee01 call !!0x1eeda
ram:01efaa c0 pop AX
ram:01efab 62 mov A,
ram:01efac 9feee2 mov !0xfe2ee,A
ram:01efaf d7 ret
ram:01efb0 c7 push HL
ram:01efb1 c1 push AX
ram:01efb2 2004 subw SP,0x4
ram:01efb4 fbf8ff movw HL,!0xffff8
ram:01efb7 cc0100 mov [HL + 0x1],0x0
ram:01efba 8ff0e2 mov A,!0xfe2f0
ram:01efbd 9c02 mov [HL + 0x2],A
ram:01efbf cc0300 mov [HL + 0x3],0x0
ram:01efc2 8c03 mov A,[HL + 0x3]
ram:01efc4 4c20 cmp A,#0x20
ram:01efc6 de34 bnc $ 0x1effc
ram:01efc8 8c03 mov A,[HL + 0x3]
ram:01efca f0 clrb X
ram:01efcb 316e shrw AX,0x6
ram:01efcd 12 movw BC,AX
ram:01efce 49f1e2 mov A,!0xfe2f1[BC]
ram:01efd1 4e04 cmp A,[HL + 0x4]
ram:01efd3 df06 bnz $ 0x1efdb
ram:01efd5 8c03 mov A,[HL + 0x3]
ram:01efd7 9c01 mov [HL + 0x1],A
ram:01efd9 ef21 br $ 0x1effc
ram:01efdb 8c03 mov A,[HL + 0x3]
ram:01efdd f0 clrb X
ram:01efde 316e shrw AX,0x6
ram:01efe0 12 movw BC,AX
ram:01efe1 49f0e2 mov A,!0xfe2f0[BC]
ram:01efe4 4e02 cmp A,[HL + 0x2]
ram:01efe6 de0f bnc $ 0x1eff7
ram:01efe8 8c03 mov A,[HL + 0x3]
ram:01efea 9c01 mov [HL + 0x1],A
ram:01efec 8c03 mov A,[HL + 0x3]
ram:01efee f0 clrb X
ram:01efef 316e shrw AX,0x6
ram:01eff1 12 movw BC,AX
ram:01eff2 49f0e2 mov A,!0xfe2f0[BC]
ram:01eff5 9c02 mov [HL + 0x2],A
ram:01eff7 615903 inc [HL + 0x3]
ram:01effa efc6 br $ 0x1efc2
ram:01effc 8c01 mov A,[HL + 0x1]
ram:01effe f0 clrb X
ram:01efff 316e shrw AX,0x6
ram:01f001 04f0e2 addw AX,0xe2f0
ram:01f004 14 movw DE,AX
ram:01f005 8c04 mov A,[HL + 0x4]
ram:01f007 9a01 mov [DE + 0x1],A
ram:01f009 8c01 mov A,[HL + 0x1]
ram:01f00b f0 clrb X
ram:01f00c 316e shrw AX,0x6
ram:01f00e 04f0e2 addw AX,0xe2f0
ram:01f011 14 movw DE,AX
ram:01f012 ac0c movw AX,[HL + 0xc]
ram:01f014 ba02 movw [DE + 0x2],AX
ram:01f016 8c01 mov A,[HL + 0x1]
ram:01f018 f0 clrb X
ram:01f019 316e shrw AX,0x6
ram:01f01b 12 movw BC,AX
ram:01f01c 39f0e2c8 mov !0xfe2f0[BC],0xc8
ram:01f020 1006 addw SP,0x6
ram:01f022 c6 pop HL
ram:01f023 d7 ret
ram:01f024 c7 push HL
ram:01f025 16 movw HL,AX
ram:01f026 66 mov A,
ram:01f027 d1 cmp0 A
ram:01f028 df06 bnz $ 0x1f030
ram:01f02a cfefe220 mov !0xfe2ef,0x20
ram:01f02e ef20 br $ 0x1f050
ram:01f030 5700 mov ,0x0
ram:01f032 67 mov A,
ram:01f033 4c20 cmp A,#0x20
ram:01f035 de19 bnc $ 0x1f050
ram:01f037 f0 clrb X
ram:01f038 316e shrw AX,0x6
ram:01f03a 04f0e2 addw AX,0xe2f0
ram:01f03d 14 movw DE,AX
ram:01f03e 8a01 mov A,[DE + 0x1]
ram:01f040 614e cmp A,
ram:01f042 df09 bnz $ 0x1f04d
ram:01f044 67 mov A,
ram:01f045 9fefe2 mov !0xfe2ef,A
ram:01f048 ca00c8 mov [DE + 0x0],0xc8
ram:01f04b ef03 br $ 0x1f050
ram:01f04d 87 inc 
ram:01f04e efe2 br $ 0x1f032
ram:01f050 c6 pop HL
ram:01f051 d7 ret
ram:01f052 c7 push HL
ram:01f053 c1 push AX
ram:01f054 c1 push AX
ram:01f055 fbf8ff movw HL,!0xffff8
ram:01f058 cc0100 mov [HL + 0x1],0x0
ram:01f05b 8c01 mov A,[HL + 0x1]
ram:01f05d 4c20 cmp A,#0x20
ram:01f05f de44 bnc $ 0x1f0a5
ram:01f061 8c01 mov A,[HL + 0x1]
ram:01f063 f0 clrb X
ram:01f064 316e shrw AX,0x6
ram:01f066 04f0e2 addw AX,0xe2f0
ram:01f069 14 movw DE,AX
ram:01f06a 89 mov A,[DE]
ram:01f06b 4c02 cmp A,#0x2
ram:01f06d dc31 bc $ 0x1f0a0
ram:01f06f 8a01 mov A,[DE + 0x1]
ram:01f071 4e02 cmp A,[HL + 0x2]
ram:01f073 df2b bnz $ 0x1f0a0
ram:01f075 aa02 movw AX,[DE + 0x2]
ram:01f077 61490a cmpw AX,[HL + 0xa]
ram:01f07a df03 bnz $ 0x1f07f
ram:01f07c f7 clrw BC
ram:01f07d ef27 br $ 0x1f0a6
ram:01f07f 8c01 mov A,[HL + 0x1]
ram:01f081 f0 clrb X
ram:01f082 316e shrw AX,0x6
ram:01f084 04f0e2 addw AX,0xe2f0
ram:01f087 14 movw DE,AX
ram:01f088 8a02 mov A,[DE + 0x2]
ram:01f08a 7e0a xor A,[HL + 0xa]
ram:01f08c 08 xch A,X
ram:01f08d 8a03 mov A,[DE + 0x3]
ram:01f08f 7e0b xor A,[HL + 0xb]
ram:01f091 5cf0 and A,#0xf0
ram:01f093 6168 or A,
ram:01f095 df04 bnz $ 0x1f09b
ram:01f097 e7 onew BC
ram:01f098 a3 incw BC
ram:01f099 ef0b br $ 0x1f0a6
ram:01f09b 320300 movw BC,0x3
ram:01f09e ef06 br $ 0x1f0a6
ram:01f0a0 615901 inc [HL + 0x1]
ram:01f0a3 efb6 br $ 0x1f05b
ram:01f0a5 e7 onew BC
ram:01f0a6 1004 addw SP,0x4
ram:01f0a8 c6 pop HL
ram:01f0a9 d7 ret
ram:01f0aa c7 push HL
ram:01f0ab c1 push AX
ram:01f0ac c1 push AX
ram:01f0ad fbf8ff movw HL,!0xffff8
ram:01f0b0 cc0100 mov [HL + 0x1],0x0
ram:01f0b3 8c01 mov A,[HL + 0x1]
ram:01f0b5 4c20 cmp A,#0x20
ram:01f0b7 de65 bnc $ 0x1f11e
ram:01f0b9 8c01 mov A,[HL + 0x1]
ram:01f0bb f0 clrb X
ram:01f0bc 316e shrw AX,0x6
ram:01f0be 04f0e2 addw AX,0xe2f0
ram:01f0c1 14 movw DE,AX
ram:01f0c2 8a01 mov A,[DE + 0x1]
ram:01f0c4 4e02 cmp A,[HL + 0x2]
ram:01f0c6 df51 bnz $ 0x1f119
ram:01f0c8 aa02 movw AX,[DE + 0x2]
ram:01f0ca 61490a cmpw AX,[HL + 0xa]
ram:01f0cd df0d bnz $ 0x1f0dc
ram:01f0cf 89 mov A,[DE]
ram:01f0d0 4c02 cmp A,#0x2
ram:01f0d2 dc03 bc $ 0x1f0d7
ram:01f0d4 f7 clrw BC
ram:01f0d5 ef48 br $ 0x1f11f
ram:01f0d7 320400 movw BC,0x4
ram:01f0da ef43 br $ 0x1f11f
ram:01f0dc 8c01 mov A,[HL + 0x1]
ram:01f0de f0 clrb X
ram:01f0df 316e shrw AX,0x6
ram:01f0e1 04f0e2 addw AX,0xe2f0
ram:01f0e4 14 movw DE,AX
ram:01f0e5 8a02 mov A,[DE + 0x2]
ram:01f0e7 7e0a xor A,[HL + 0xa]
ram:01f0e9 08 xch A,X
ram:01f0ea 8a03 mov A,[DE + 0x3]
ram:01f0ec 7e0b xor A,[HL + 0xb]
ram:01f0ee 5cf0 and A,#0xf0
ram:01f0f0 6168 or A,
ram:01f0f2 df0e bnz $ 0x1f102
ram:01f0f4 89 mov A,[DE]
ram:01f0f5 4c02 cmp A,#0x2
ram:01f0f7 dc04 bc $ 0x1f0fd
ram:01f0f9 e7 onew BC
ram:01f0fa a3 incw BC
ram:01f0fb ef22 br $ 0x1f11f
ram:01f0fd 320500 movw BC,0x5
ram:01f100 ef1d br $ 0x1f11f
ram:01f102 8c01 mov A,[HL + 0x1]
ram:01f104 f0 clrb X
ram:01f105 316e shrw AX,0x6
ram:01f107 12 movw BC,AX
ram:01f108 49f0e2 mov A,!0xfe2f0[BC]
ram:01f10b 4c02 cmp A,#0x2
ram:01f10d dc05 bc $ 0x1f114
ram:01f10f 320300 movw BC,0x3
ram:01f112 ef0b br $ 0x1f11f
ram:01f114 320600 movw BC,0x6
ram:01f117 ef06 br $ 0x1f11f
ram:01f119 615901 inc [HL + 0x1]
ram:01f11c ef95 br $ 0x1f0b3
ram:01f11e e7 onew BC
ram:01f11f 1004 addw SP,0x4
ram:01f121 c6 pop HL
ram:01f122 d7 ret
ram:01f123 c7 push HL
ram:01f124 c1 push AX
ram:01f125 2004 subw SP,0x4
ram:01f127 fbf8ff movw HL,!0xffff8
ram:01f12a cc0300 mov [HL + 0x3],0x0
ram:01f12d 8c03 mov A,[HL + 0x3]
ram:01f12f 4fefe2 cmp A,!0xfe2ef
ram:01f132 de16 bnc $ 0x1f14a
ram:01f134 8c03 mov A,[HL + 0x3]
ram:01f136 f0 clrb X
ram:01f137 316e shrw AX,0x6
ram:01f139 04f0e2 addw AX,0xe2f0
ram:01f13c 14 movw DE,AX
ram:01f13d 89 mov A,[DE]
ram:01f13e 4c02 cmp A,#0x2
ram:01f140 dc03 bc $ 0x1f145
ram:01f142 89 mov A,[DE]
ram:01f143 91 dec 
ram:01f144 99 mov [DE],A
ram:01f145 615903 inc [HL + 0x3]
ram:01f148 efe3 br $ 0x1f12d
ram:01f14a 8fefe2 mov A,!0xfe2ef
ram:01f14d 81 inc 
ram:01f14e 9c03 mov [HL + 0x3],A
ram:01f150 8c03 mov A,[HL + 0x3]
ram:01f152 4c20 cmp A,#0x20
ram:01f154 de16 bnc $ 0x1f16c
ram:01f156 8c03 mov A,[HL + 0x3]
ram:01f158 f0 clrb X
ram:01f159 316e shrw AX,0x6
ram:01f15b 04f0e2 addw AX,0xe2f0
ram:01f15e 14 movw DE,AX
ram:01f15f 89 mov A,[DE]
ram:01f160 4c02 cmp A,#0x2
ram:01f162 dc03 bc $ 0x1f167
ram:01f164 89 mov A,[DE]
ram:01f165 91 dec 
ram:01f166 99 mov [DE],A
ram:01f167 615903 inc [HL + 0x3]
ram:01f16a efe4 br $ 0x1f150
ram:01f16c cc0300 mov [HL + 0x3],0x0
ram:01f16f 8c03 mov A,[HL + 0x3]
ram:01f171 4f70e3 cmp A,!0xfe370
ram:01f174 de15 bnc $ 0x1f18b
ram:01f176 8c03 mov A,[HL + 0x3]
ram:01f178 f0 clrb X
ram:01f179 317e shrw AX,0x7
ram:01f17b 0472e3 addw AX,0xe372
ram:01f17e 14 movw DE,AX
ram:01f17f 89 mov A,[DE]
ram:01f180 d1 cmp0 A
ram:01f181 dd03 bz $ 0x1f186
ram:01f183 89 mov A,[DE]
ram:01f184 91 dec 
ram:01f185 99 mov [DE],A
ram:01f186 615903 inc [HL + 0x3]
ram:01f189 efe4 br $ 0x1f16f
ram:01f18b 8f70e3 mov A,!0xfe370
ram:01f18e 81 inc 
ram:01f18f 9c03 mov [HL + 0x3],A
ram:01f191 8c03 mov A,[HL + 0x3]
ram:01f193 4c04 cmp A,#0x4
ram:01f195 de15 bnc $ 0x1f1ac
ram:01f197 8c03 mov A,[HL + 0x3]
ram:01f199 f0 clrb X
ram:01f19a 317e shrw AX,0x7
ram:01f19c 0472e3 addw AX,0xe372
ram:01f19f 14 movw DE,AX
ram:01f1a0 89 mov A,[DE]
ram:01f1a1 d1 cmp0 A
ram:01f1a2 dd03 bz $ 0x1f1a7
ram:01f1a4 89 mov A,[DE]
ram:01f1a5 91 dec 
ram:01f1a6 99 mov [DE],A
ram:01f1a7 615903 inc [HL + 0x3]
ram:01f1aa efe5 br $ 0x1f191
ram:01f1ac cc0300 mov [HL + 0x3],0x0
ram:01f1af 8c03 mov A,[HL + 0x3]
ram:01f1b1 4c08 cmp A,#0x8
ram:01f1b3 de18 bnc $ 0x1f1cd
ram:01f1b5 8c03 mov A,[HL + 0x3]
ram:01f1b7 f0 clrb X
ram:01f1b8 316e shrw AX,0x6
ram:01f1ba 047ae3 addw AX,0xe37a
ram:01f1bd 14 movw DE,AX
ram:01f1be 8a01 mov A,[DE + 0x1]
ram:01f1c0 d1 cmp0 A
ram:01f1c1 dd05 bz $ 0x1f1c8
ram:01f1c3 8a01 mov A,[DE + 0x1]
ram:01f1c5 91 dec 
ram:01f1c6 9a01 mov [DE + 0x1],A
ram:01f1c8 615903 inc [HL + 0x3]
ram:01f1cb efe2 br $ 0x1f1af
ram:01f1cd af12e4 movw AX,!0xfe412
ram:01f1d0 e7 onew BC
ram:01f1d1 a3 incw BC
ram:01f1d2 c3 push BC
ram:01f1d3 12 movw BC,AX
ram:01f1d4 17 movw AX,HL
ram:01f1d5 c1 push AX
ram:01f1d6 491600 mov A,!0xf0016[BC]
ram:01f1d9 9dd4 mov 0xffdf4,A
ram:01f1db 791400 movw AX,!0xf0014[BC]
ram:01f1de c1 push AX
ram:01f1df 8dd4 mov A,0xffdf4
ram:01f1e1 9dd6 mov 0xffdf6,A
ram:01f1e3 c0 pop AX
ram:01f1e4 14 movw DE,AX
ram:01f1e5 300400 movw AX,0x4
ram:01f1e8 f7 clrw BC
ram:01f1e9 c1 push AX
ram:01f1ea 8dd6 mov A,0xffdf6
ram:01f1ec 9efc mov CS,A
ram:01f1ee c0 pop AX
ram:01f1ef 61ea call DE
ram:01f1f1 1004 addw SP,0x4
ram:01f1f3 ab movw AX,[HL]
ram:01f1f4 446400 cmpw AX,0x64
ram:01f1f7 de0a bnc $ 0x1f203
ram:01f1f9 ac04 movw AX,[HL + 0x4]
ram:01f1fb 14 movw DE,AX
ram:01f1fc 30401f movw AX,0x1f40
ram:01f1ff ba06 movw [DE + 0x6],AX
ram:01f201 ef48 br $ 0x1f24b
ram:01f203 ab movw AX,[HL]
ram:01f204 44e803 cmpw AX,0x3e8
ram:01f207 de0a bnc $ 0x1f213
ram:01f209 ac04 movw AX,[HL + 0x4]
ram:01f20b 14 movw DE,AX
ram:01f20c 30a00f movw AX,0xfa0
ram:01f20f ba06 movw [DE + 0x6],AX
ram:01f211 ef38 br $ 0x1f24b
ram:01f213 ab movw AX,[HL]
ram:01f214 44d007 cmpw AX,0x7d0
ram:01f217 de0a bnc $ 0x1f223
ram:01f219 ac04 movw AX,[HL + 0x4]
ram:01f21b 14 movw DE,AX
ram:01f21c 30b80b movw AX,0xbb8
ram:01f21f ba06 movw [DE + 0x6],AX
ram:01f221 ef28 br $ 0x1f24b
ram:01f223 ab movw AX,[HL]
ram:01f224 44b80b cmpw AX,0xbb8
ram:01f227 de0a bnc $ 0x1f233
ram:01f229 ac04 movw AX,[HL + 0x4]
ram:01f22b 14 movw DE,AX
ram:01f22c 30d007 movw AX,0x7d0
ram:01f22f ba06 movw [DE + 0x6],AX
ram:01f231 ef18 br $ 0x1f24b
ram:01f233 ab movw AX,[HL]
ram:01f234 44a00f cmpw AX,0xfa0
ram:01f237 de0a bnc $ 0x1f243
ram:01f239 ac04 movw AX,[HL + 0x4]
ram:01f23b 14 movw DE,AX
ram:01f23c 30a406 movw AX,0x6a4
ram:01f23f ba06 movw [DE + 0x6],AX
ram:01f241 ef08 br $ 0x1f24b
ram:01f243 ac04 movw AX,[HL + 0x4]
ram:01f245 14 movw DE,AX
ram:01f246 30dc05 movw AX,0x5dc
ram:01f249 ba06 movw [DE + 0x6],AX
ram:01f24b e7 onew BC
ram:01f24c 1006 addw SP,0x6
ram:01f24e c6 pop HL
ram:01f24f d7 ret
ram:01f250 c7 push HL
ram:01f251 c1 push AX
ram:01f252 2004 subw SP,0x4
ram:01f254 fbf8ff movw HL,!0xffff8
ram:01f257 cc0296 mov [HL + 0x2],0x96
ram:01f25a cc0120 mov [HL + 0x1],0x20
ram:01f25d cc0300 mov [HL + 0x3],0x0
ram:01f260 8c03 mov A,[HL + 0x3]
ram:01f262 4c20 cmp A,#0x20
ram:01f264 de1e bnc $ 0x1f284
ram:01f266 8c03 mov A,[HL + 0x3]
ram:01f268 f0 clrb X
ram:01f269 316e shrw AX,0x6
ram:01f26b 04f0e2 addw AX,0xe2f0
ram:01f26e 14 movw DE,AX
ram:01f26f 89 mov A,[DE]
ram:01f270 d1 cmp0 A
ram:01f271 dd0c bz $ 0x1f27f
ram:01f273 89 mov A,[DE]
ram:01f274 4e02 cmp A,[HL + 0x2]
ram:01f276 de07 bnc $ 0x1f27f
ram:01f278 89 mov A,[DE]
ram:01f279 9c02 mov [HL + 0x2],A
ram:01f27b 8c03 mov A,[HL + 0x3]
ram:01f27d 9c01 mov [HL + 0x1],A
ram:01f27f 615903 inc [HL + 0x3]
ram:01f282 efdc br $ 0x1f260
ram:01f284 8c01 mov A,[HL + 0x1]
ram:01f286 4c20 cmp A,#0x20
ram:01f288 df03 bnz $ 0x1f28d
ram:01f28a f7 clrw BC
ram:01f28b ef1f br $ 0x1f2ac
ram:01f28d 8c01 mov A,[HL + 0x1]
ram:01f28f f0 clrb X
ram:01f290 316e shrw AX,0x6
ram:01f292 12 movw BC,AX
ram:01f293 49f1e2 mov A,!0xfe2f1[BC]
ram:01f296 72 mov ,A
ram:01f297 ac04 movw AX,[HL + 0x4]
ram:01f299 14 movw DE,AX
ram:01f29a 62 mov A,
ram:01f29b 99 mov [DE],A
ram:01f29c 8c01 mov A,[HL + 0x1]
ram:01f29e f0 clrb X
ram:01f29f 316e shrw AX,0x6
ram:01f2a1 12 movw BC,AX
ram:01f2a2 79f2e2 movw AX,!0xfe2f2[BC]
ram:01f2a5 12 movw BC,AX
ram:01f2a6 ac0c movw AX,[HL + 0xc]
ram:01f2a8 14 movw DE,AX
ram:01f2a9 13 movw AX,BC
ram:01f2aa b9 movw [DE],AX
ram:01f2ab e7 onew BC
ram:01f2ac 1006 addw SP,0x6
ram:01f2ae c6 pop HL
ram:01f2af d7 ret
ram:01f2b0 c7 push HL
ram:01f2b1 16 movw HL,AX
ram:01f2b2 5700 mov ,0x0
ram:01f2b4 67 mov A,
ram:01f2b5 4c20 cmp A,#0x20
ram:01f2b7 de11 bnc $ 0x1f2ca
ram:01f2b9 f0 clrb X
ram:01f2ba 316e shrw AX,0x6
ram:01f2bc 12 movw BC,AX
ram:01f2bd 49f1e2 mov A,!0xfe2f1[BC]
ram:01f2c0 614e cmp A,
ram:01f2c2 df03 bnz $ 0x1f2c7
ram:01f2c4 e7 onew BC
ram:01f2c5 ef04 br $ 0x1f2cb
ram:01f2c7 87 inc 
ram:01f2c8 efea br $ 0x1f2b4
ram:01f2ca f7 clrw BC
ram:01f2cb c6 pop HL
ram:01f2cc d7 ret
ram:01f2cd c7 push HL
ram:01f2ce 16 movw HL,AX
ram:01f2cf 5700 mov ,0x0
ram:01f2d1 67 mov A,
ram:01f2d2 4c20 cmp A,#0x20
ram:01f2d4 de15 bnc $ 0x1f2eb
ram:01f2d6 f0 clrb X
ram:01f2d7 316e shrw AX,0x6
ram:01f2d9 04f0e2 addw AX,0xe2f0
ram:01f2dc 14 movw DE,AX
ram:01f2dd 8a01 mov A,[DE + 0x1]
ram:01f2df 614e cmp A,
ram:01f2e1 df05 bnz $ 0x1f2e8
ram:01f2e3 aa02 movw AX,[DE + 0x2]
ram:01f2e5 12 movw BC,AX
ram:01f2e6 ef04 br $ 0x1f2ec
ram:01f2e8 87 inc 
ram:01f2e9 efe6 br $ 0x1f2d1
ram:01f2eb f7 clrw BC
ram:01f2ec c6 pop HL
ram:01f2ed d7 ret
ram:01f2ee c7 push HL
ram:01f2ef 16 movw HL,AX
ram:01f2f0 5700 mov ,0x0
ram:01f2f2 67 mov A,
ram:01f2f3 4c20 cmp A,#0x20
ram:01f2f5 de26 bnc $ 0x1f31d
ram:01f2f7 f0 clrb X
ram:01f2f8 316e shrw AX,0x6
ram:01f2fa 04f0e2 addw AX,0xe2f0
ram:01f2fd 14 movw DE,AX
ram:01f2fe 8a01 mov A,[DE + 0x1]
ram:01f300 614e cmp A,
ram:01f302 df16 bnz $ 0x1f31a
ram:01f304 ca0100 mov [DE + 0x1],0x0
ram:01f307 ca0000 mov [DE + 0x0],0x0
ram:01f30a f6 clrw AX
ram:01f30b ba02 movw [DE + 0x2],AX
ram:01f30d 8fefe2 mov A,!0xfe2ef
ram:01f310 614f cmp A,
ram:01f312 df09 bnz $ 0x1f31d
ram:01f314 cfefe220 mov !0xfe2ef,0x20
ram:01f318 ef03 br $ 0x1f31d
ram:01f31a 87 inc 
ram:01f31b efd5 br $ 0x1f2f2
ram:01f31d c6 pop HL
ram:01f31e d7 ret
ram:01f31f fc2def01 call !!0x1ef2d
ram:01f323 30d007 movw AX,0x7d0
ram:01f326 c1 push AX
ram:01f327 3023f1 movw AX,0xf123
ram:01f32a 5201 mov ,0x1
ram:01f32c f3 clrb B
ram:01f32d fcea7d00 call !!0x7dea
ram:01f331 c0 pop AX
ram:01f332 62 mov A,
ram:01f333 9f9ae3 mov !0xfe39a,A
ram:01f336 d7 ret
ram:01f337 fc9fef01 call !!0x1ef9f
ram:01f33b d99ae3 mov X,!0xfe39a
ram:01f33e f1 clrb A
ram:01f33f fc927e00 call !!0x7e92
ram:01f343 f59ae3 clrb !0xfe39a
ram:01f346 d7 ret
ram:01f347 c7 push HL
ram:01f348 c1 push AX
ram:01f349 2004 subw SP,0x4
ram:01f34b fbf8ff movw HL,!0xffff8
ram:01f34e cc0100 mov [HL + 0x1],0x0
ram:01f351 8f72e3 mov A,!0xfe372
ram:01f354 9c02 mov [HL + 0x2],A
ram:01f356 cc0300 mov [HL + 0x3],0x0
ram:01f359 8c03 mov A,[HL + 0x3]
ram:01f35b 4c04 cmp A,#0x4
ram:01f35d de34 bnc $ 0x1f393
ram:01f35f 8c03 mov A,[HL + 0x3]
ram:01f361 f0 clrb X
ram:01f362 317e shrw AX,0x7
ram:01f364 12 movw BC,AX
ram:01f365 4973e3 mov A,!0xfe373[BC]
ram:01f368 4e04 cmp A,[HL + 0x4]
ram:01f36a df06 bnz $ 0x1f372
ram:01f36c 8c03 mov A,[HL + 0x3]
ram:01f36e 9c01 mov [HL + 0x1],A
ram:01f370 ef21 br $ 0x1f393
ram:01f372 8c03 mov A,[HL + 0x3]
ram:01f374 f0 clrb X
ram:01f375 317e shrw AX,0x7
ram:01f377 12 movw BC,AX
ram:01f378 4972e3 mov A,!0xfe372[BC]
ram:01f37b 4e02 cmp A,[HL + 0x2]
ram:01f37d de0f bnc $ 0x1f38e
ram:01f37f 8c03 mov A,[HL + 0x3]
ram:01f381 9c01 mov [HL + 0x1],A
ram:01f383 8c03 mov A,[HL + 0x3]
ram:01f385 f0 clrb X
ram:01f386 317e shrw AX,0x7
ram:01f388 12 movw BC,AX
ram:01f389 4972e3 mov A,!0xfe372[BC]
ram:01f38c 9c02 mov [HL + 0x2],A
ram:01f38e 615903 inc [HL + 0x3]
ram:01f391 efc6 br $ 0x1f359
ram:01f393 8c01 mov A,[HL + 0x1]
ram:01f395 f0 clrb X
ram:01f396 317e shrw AX,0x7
ram:01f398 0472e3 addw AX,0xe372
ram:01f39b 14 movw DE,AX
ram:01f39c 8c04 mov A,[HL + 0x4]
ram:01f39e 9a01 mov [DE + 0x1],A
ram:01f3a0 8c01 mov A,[HL + 0x1]
ram:01f3a2 f0 clrb X
ram:01f3a3 317e shrw AX,0x7
ram:01f3a5 12 movw BC,AX
ram:01f3a6 3972e314 mov !0xfe372[BC],0x14
ram:01f3aa 8c01 mov A,[HL + 0x1]
ram:01f3ac 9f70e3 mov !0xfe370,A
ram:01f3af 8c04 mov A,[HL + 0x4]
ram:01f3b1 318e shrw AX,0x8
ram:01f3b3 fc24f001 call !!0x1f024
ram:01f3b7 1006 addw SP,0x6
ram:01f3b9 c6 pop HL
ram:01f3ba d7 ret
ram:01f3bb c7 push HL
ram:01f3bc 16 movw HL,AX
ram:01f3bd 5700 mov ,0x0
ram:01f3bf 67 mov A,
ram:01f3c0 4c04 cmp A,#0x4
ram:01f3c2 de17 bnc $ 0x1f3db
ram:01f3c4 f0 clrb X
ram:01f3c5 317e shrw AX,0x7
ram:01f3c7 0472e3 addw AX,0xe372
ram:01f3ca 14 movw DE,AX
ram:01f3cb 89 mov A,[DE]
ram:01f3cc d1 cmp0 A
ram:01f3cd dd09 bz $ 0x1f3d8
ram:01f3cf 8a01 mov A,[DE + 0x1]
ram:01f3d1 614e cmp A,
ram:01f3d3 df03 bnz $ 0x1f3d8
ram:01f3d5 e7 onew BC
ram:01f3d6 ef04 br $ 0x1f3dc
ram:01f3d8 87 inc 
ram:01f3d9 efe4 br $ 0x1f3bf
ram:01f3db f7 clrw BC
ram:01f3dc c6 pop HL
ram:01f3dd d7 ret
ram:01f490 c7 push HL
ram:01f491 16 movw HL,AX
ram:01f492 5700 mov ,0x0
ram:01f494 67 mov A,
ram:01f495 4c04 cmp A,#0x4
ram:01f497 de18 bnc $ 0x1f4b1
ram:01f499 f0 clrb X
ram:01f49a 316e shrw AX,0x6
ram:01f49c 047ae3 addw AX,0xe37a
ram:01f49f 14 movw DE,AX
ram:01f4a0 8a01 mov A,[DE + 0x1]
ram:01f4a2 d1 cmp0 A
ram:01f4a3 dd09 bz $ 0x1f4ae
ram:01f4a5 8a02 mov A,[DE + 0x2]
ram:01f4a7 614e cmp A,
ram:01f4a9 df03 bnz $ 0x1f4ae
ram:01f4ab e7 onew BC
ram:01f4ac ef04 br $ 0x1f4b2
ram:01f4ae 87 inc 
ram:01f4af efe3 br $ 0x1f494
ram:01f4b1 f7 clrw BC
ram:01f4b2 c6 pop HL
ram:01f4b3 d7 ret
ram:01f4b4 c7 push HL
ram:01f4b5 c1 push AX
ram:01f4b6 200c subw SP,0xc
ram:01f4b8 fbf8ff movw HL,!0xffff8
ram:01f4bb cc0a00 mov [HL + 0xa],0x0
ram:01f4be 8f71d9 mov A,!0xfd971
ram:01f4c1 5c01 and A,#0x1
ram:01f4c3 318e shrw AX,0x8
ram:01f4c5 312d shlw AX,0x2
ram:01f4c7 12 movw BC,AX
ram:01f4c8 313d shlw AX,0x3
ram:01f4ca 03 addw AX,BC
ram:01f4cb 0472d9 addw AX,0xd972
ram:01f4ce bc06 movw [HL + 0x6],AX
ram:01f4d0 8f71d9 mov A,!0xfd971
ram:01f4d3 311504 bf A.0x1,$ 0x1f4d9
ram:01f4d6 e7 onew BC
ram:01f4d7 ee6701 br $! 0x1f641
ram:01f4da af12e4 movw AX,!0xfe412
ram:01f4dd e7 onew BC
ram:01f4de a3 incw BC
ram:01f4df c3 push BC
ram:01f4e0 12 movw BC,AX
ram:01f4e1 17 movw AX,HL
ram:01f4e2 040400 addw AX,0x4
ram:01f4e5 c1 push AX
ram:01f4e6 491600 mov A,!0xf0016[BC]
ram:01f4e9 9dd4 mov 0xffdf4,A
ram:01f4eb 791400 movw AX,!0xf0014[BC]
ram:01f4ee c1 push AX
ram:01f4ef 8dd4 mov A,0xffdf4
ram:01f4f1 9dd6 mov 0xffdf6,A
ram:01f4f3 c0 pop AX
ram:01f4f4 14 movw DE,AX
ram:01f4f5 300400 movw AX,0x4
ram:01f4f8 f7 clrw BC
ram:01f4f9 c1 push AX
ram:01f4fa 8dd6 mov A,0xffdf6
ram:01f4fc 9efc mov CS,A
ram:01f4fe c0 pop AX
ram:01f4ff 61ea call DE
ram:01f501 1004 addw SP,0x4
ram:01f503 ac04 movw AX,[HL + 0x4]
ram:01f505 44e803 cmpw AX,0x3e8
ram:01f508 de08 bnc $ 0x1f512
ram:01f50a ac0c movw AX,[HL + 0xc]
ram:01f50c 14 movw DE,AX
ram:01f50d 30d007 movw AX,0x7d0
ram:01f510 ba06 movw [DE + 0x6],AX
ram:01f512 ac04 movw AX,[HL + 0x4]
ram:01f514 44800c cmpw AX,0xc80
ram:01f517 de3e bnc $ 0x1f557
ram:01f519 ac04 movw AX,[HL + 0x4]
ram:01f51b bdd8 movw 0xffdf8,AX
ram:01f51d f6 clrw AX
ram:01f51e bdda movw 0xffdfa,AX
ram:01f520 c9dce803 movw 0xffdfc,0x3e8
ram:01f524 fd5f06 call !0xf065f
ram:01f527 c9dcdc05 movw 0xffdfc,0x5dc
ram:01f52b f6 clrw AX
ram:01f52c fd8404 call !0xf0484
ram:01f52f c9dcb80b movw 0xffdfc,0xbb8
ram:01f533 f6 clrw AX
ram:01f534 fda105 call !0xf05a1
ram:01f537 add8 movw AX,0xffdf8
ram:01f539 bddc movw 0xffdfc,AX
ram:01f53b adda movw AX,0xffdfa
ram:01f53d c9d8d007 movw 0xffdf8,0x7d0
ram:01f541 c9da0000 movw 0xffdfa,0x0
ram:01f545 fd5f06 call !0xf065f
ram:01f548 adda movw AX,0xffdfa
ram:01f54a bc02 movw [HL + 0x2],AX
ram:01f54c add8 movw AX,0xffdf8
ram:01f54e bb movw [HL],AX
ram:01f54f ac0c movw AX,[HL + 0xc]
ram:01f551 14 movw DE,AX
ram:01f552 ab movw AX,[HL]
ram:01f553 ba06 movw [DE + 0x6],AX
ram:01f555 ef08 br $ 0x1f55f
ram:01f557 ac0c movw AX,[HL + 0xc]
ram:01f559 14 movw DE,AX
ram:01f55a 30f401 movw AX,0x1f4
ram:01f55d ba06 movw [DE + 0x6],AX
ram:01f55f af12e4 movw AX,!0xfe412
ram:01f562 e7 onew BC
ram:01f563 a3 incw BC
ram:01f564 c3 push BC
ram:01f565 12 movw BC,AX
ram:01f566 17 movw AX,HL
ram:01f567 040800 addw AX,0x8
ram:01f56a c1 push AX
ram:01f56b 491600 mov A,!0xf0016[BC]
ram:01f56e 9dd4 mov 0xffdf4,A
ram:01f570 791400 movw AX,!0xf0014[BC]
ram:01f573 c1 push AX
ram:01f574 8dd4 mov A,0xffdf4
ram:01f576 9dd6 mov 0xffdf6,A
ram:01f578 c0 pop AX
ram:01f579 14 movw DE,AX
ram:01f57a 300500 movw AX,0x5
ram:01f57d f7 clrw BC
ram:01f57e c1 push AX
ram:01f57f 8dd6 mov A,0xffdf6
ram:01f581 9efc mov CS,A
ram:01f583 c0 pop AX
ram:01f584 61ea call DE
ram:01f586 1004 addw SP,0x4
ram:01f588 ebc8e9 movw DE,!0xfe9c8
ram:01f58b aa08 movw AX,[DE + 0x8]
ram:01f58d 12 movw BC,AX
ram:01f58e ac08 movw AX,[HL + 0x8]
ram:01f590 23 subw AX,BC
ram:01f591 440500 cmpw AX,0x5
ram:01f594 dc07 bc $ 0x1f59d
ram:01f596 cc0a01 mov [HL + 0xa],0x1
ram:01f599 ac08 movw AX,[HL + 0x8]
ram:01f59b ba08 movw [DE + 0x8],AX
ram:01f59d cc0b01 mov [HL + 0xb],0x1
ram:01f5a0 ac06 movw AX,[HL + 0x6]
ram:01f5a2 14 movw DE,AX
ram:01f5a3 8a02 mov A,[DE + 0x2]
ram:01f5a5 4e0b cmp A,[HL + 0xb]
ram:01f5a7 61e3 skh
ram:01f5a9 ee9400 _br $! 0x1f640
ram:01f5ac 8c0b mov A,[HL + 0xb]
ram:01f5ae 73 mov ,A
ram:01f5af 09c4d9 mov A,!0xfd9c4[B]
ram:01f5b2 4c1e cmp A,#0x1e
ram:01f5b4 de73 bnc $ 0x1f629
ram:01f5b6 af68d9 movw AX,!0xfd968
ram:01f5b9 c1 push AX
ram:01f5ba 8c0b mov A,[HL + 0xb]
ram:01f5bc 318e shrw AX,0x8
ram:01f5be a5 incw DE
ram:01f5bf a5 incw DE
ram:01f5c0 a5 incw DE
ram:01f5c1 05 addw AX,DE
ram:01f5c2 14 movw DE,AX
ram:01f5c3 89 mov A,[DE]
ram:01f5c4 318e shrw AX,0x8
ram:01f5c6 fcaaf001 call !!0x1f0aa
ram:01f5ca c0 pop AX
ram:01f5cb 62 mov A,
ram:01f5cc d1 cmp0 A
ram:01f5cd dd1e bz $ 0x1f5ed
ram:01f5cf 91 dec 
ram:01f5d0 dd0e bz $ 0x1f5e0
ram:01f5d2 91 dec 
ram:01f5d3 dd18 bz $ 0x1f5ed
ram:01f5d5 91 dec 
ram:01f5d6 dd62 bz $ 0x1f63a
ram:01f5d8 91 dec 
ram:01f5d9 2c02 sub A,#0x2
ram:01f5db dc2e bc $ 0x1f60b
ram:01f5dd d1 cmp0 A
ram:01f5de df5a bnz $ 0x1f63a
ram:01f5e0 8c0b mov A,[HL + 0xb]
ram:01f5e2 318e shrw AX,0x8
ram:01f5e4 04c4d9 addw AX,0xd9c4
ram:01f5e7 14 movw DE,AX
ram:01f5e8 89 mov A,[DE]
ram:01f5e9 81 inc 
ram:01f5ea 99 mov [DE],A
ram:01f5eb ef4d br $ 0x1f63a
ram:01f5ed 8c0b mov A,[HL + 0xb]
ram:01f5ef 318e shrw AX,0x8
ram:01f5f1 04c4d9 addw AX,0xd9c4
ram:01f5f4 14 movw DE,AX
ram:01f5f5 89 mov A,[DE]
ram:01f5f6 0c05 add A,#0x5
ram:01f5f8 99 mov [DE],A
ram:01f5f9 8c0b mov A,[HL + 0xb]
ram:01f5fb 318e shrw AX,0x8
ram:01f5fd 04c4d9 addw AX,0xd9c4
ram:01f600 14 movw DE,AX
ram:01f601 89 mov A,[DE]
ram:01f602 4c1f cmp A,#0x1f
ram:01f604 dc34 bc $ 0x1f63a
ram:01f606 ca001e mov [DE + 0x0],0x1e
ram:01f609 ef2f br $ 0x1f63a
ram:01f60b 8c0b mov A,[HL + 0xb]
ram:01f60d 318e shrw AX,0x8
ram:01f60f 04c4d9 addw AX,0xd9c4
ram:01f612 14 movw DE,AX
ram:01f613 89 mov A,[DE]
ram:01f614 0c03 add A,#0x3
ram:01f616 99 mov [DE],A
ram:01f617 8c0b mov A,[HL + 0xb]
ram:01f619 318e shrw AX,0x8
ram:01f61b 04c4d9 addw AX,0xd9c4
ram:01f61e 14 movw DE,AX
ram:01f61f 89 mov A,[DE]
ram:01f620 4c1f cmp A,#0x1f
ram:01f622 dc16 bc $ 0x1f63a
ram:01f624 ca001e mov [DE + 0x0],0x1e
ram:01f627 ef11 br $ 0x1f63a
ram:01f629 8c0b mov A,[HL + 0xb]
ram:01f62b 318e shrw AX,0x8
ram:01f62d 04c4d9 addw AX,0xd9c4
ram:01f630 14 movw DE,AX
ram:01f631 89 mov A,[DE]
ram:01f632 4c29 cmp A,#0x29
ram:01f634 dc04 bc $ 0x1f63a
ram:01f636 89 mov A,[DE]
ram:01f637 2e0a sub A,[HL + 0xa]
ram:01f639 99 mov [DE],A
ram:01f63a 61590b inc [HL + 0xb]
ram:01f63d ee60ff br $! 0x1f5a0
ram:01f640 e7 onew BC
ram:01f641 100e addw SP,0xe
ram:01f643 c6 pop HL
ram:01f644 d7 ret
ram:01f791 c7 push HL
ram:01f792 c1 push AX
ram:01f793 2010 subw SP,0x10
ram:01f795 fbf8ff movw HL,!0xffff8
ram:01f798 8f71d9 mov A,!0xfd971
ram:01f79b 5c01 and A,#0x1
ram:01f79d 318e shrw AX,0x8
ram:01f79f 312d shlw AX,0x2
ram:01f7a1 12 movw BC,AX
ram:01f7a2 313d shlw AX,0x3
ram:01f7a4 03 addw AX,BC
ram:01f7a5 0472d9 addw AX,0xd972
ram:01f7a8 bc0e movw [HL + 0xe],AX
ram:01f7aa ac10 movw AX,[HL + 0x10]
ram:01f7ac 14 movw DE,AX
ram:01f7ad f6 clrw AX
ram:01f7ae ba06 movw [DE + 0x6],AX
ram:01f7b0 8f70d9 mov A,!0xfd970
ram:01f7b3 310509 bf A.0x0,$ 0x1f7be
ram:01f7b6 ac0e movw AX,[HL + 0xe]
ram:01f7b8 14 movw DE,AX
ram:01f7b9 8a02 mov A,[DE + 0x2]
ram:01f7bb 4c02 cmp A,#0x2
ram:01f7bd de0c bnc $ 0x1f7cb
ram:01f7bf ac10 movw AX,[HL + 0x10]
ram:01f7c1 14 movw DE,AX
ram:01f7c2 30c800 movw AX,0xc8
ram:01f7c5 ba06 movw [DE + 0x6],AX
ram:01f7c7 e7 onew BC
ram:01f7c8 ee4d0d br $! 0x20518
ram:01f7cb ac10 movw AX,[HL + 0x10]
ram:01f7cd 14 movw DE,AX
ram:01f7ce aa04 movw AX,[DE + 0x4]
ram:01f7d0 e7 onew BC
ram:01f7d1 240000 subw AX,0x0
ram:01f7d4 dd32 bz $ 0x1f808
ram:01f7d6 23 subw AX,BC
ram:01f7d7 61f8 sknz
ram:01f7d9 ee3203 _br $! 0x1fb0e
ram:01f7dc 240400 subw AX,0x4
ram:01f7df 61f8 sknz
ram:01f7e1 eeb109 _br $! 0x20195
ram:01f7e4 23 subw AX,BC
ram:01f7e5 61f8 sknz
ram:01f7e7 eebe0b _br $! 0x203a8
ram:01f7ea 23 subw AX,BC
ram:01f7eb dd44 bz $ 0x1f831
ram:01f7ed 23 subw AX,BC
ram:01f7ee 61f8 sknz
ram:01f7f0 eec200 _br $! 0x1f8b5
ram:01f7f3 23 subw AX,BC
ram:01f7f4 61f8 sknz
ram:01f7f6 ee9c06 _br $! 0x1fe95
ram:01f7f9 23 subw AX,BC
ram:01f7fa 61f8 sknz
ram:01f7fc ee1306 _br $! 0x1fe12
ram:01f7ff 23 subw AX,BC
ram:01f800 61f8 sknz
ram:01f802 ee2d06 _br $! 0x1fe32
ram:01f805 ee0f0d br $! 0x20517
ram:01f808 f5e4d9 clrb !0xfd9e4
ram:01f80b ebc8e9 movw DE,!0xfe9c8
ram:01f80e 89 mov A,[DE]
ram:01f80f 5c03 and A,#0x3
ram:01f811 99 mov [DE],A
ram:01f812 ebc8e9 movw DE,!0xfe9c8
ram:01f815 300500 movw AX,0x5
ram:01f818 ba04 movw [DE + 0x4],AX
ram:01f81a 5020 mov ,0x20
ram:01f81c c1 push AX
ram:01f81d 501e mov ,0x1e
ram:01f81f c1 push AX
ram:01f820 30c4d9 movw AX,0xd9c4
ram:01f823 fc40e500 call !!0xe540
ram:01f827 1004 addw SP,0x4
ram:01f829 ac10 movw AX,[HL + 0x10]
ram:01f82b 14 movw DE,AX
ram:01f82c 300700 movw AX,0x7
ram:01f82f ba04 movw [DE + 0x4],AX
ram:01f831 ebc8e9 movw DE,!0xfe9c8
ram:01f834 aa0a movw AX,[DE + 0xa]
ram:01f836 440500 cmpw AX,0x5
ram:01f839 71fe or1 CY,A.0x7
ram:01f83b dc06 bc $ 0x1f843
ram:01f83d 8f71d9 mov A,!0xfd971
ram:01f840 31150a bf A.0x1,$ 0x1f84c
ram:01f843 ac10 movw AX,[HL + 0x10]
ram:01f845 14 movw DE,AX
ram:01f846 300800 movw AX,0x8
ram:01f849 ba04 movw [DE + 0x4],AX
ram:01f84b ef65 br $ 0x1f8b2
ram:01f84d af12e4 movw AX,!0xfe412
ram:01f850 e7 onew BC
ram:01f851 a3 incw BC
ram:01f852 c3 push BC
ram:01f853 12 movw BC,AX
ram:01f854 17 movw AX,HL
ram:01f855 040c00 addw AX,0xc
ram:01f858 c1 push AX
ram:01f859 491600 mov A,!0xf0016[BC]
ram:01f85c 9dd4 mov 0xffdf4,A
ram:01f85e 791400 movw AX,!0xf0014[BC]
ram:01f861 c1 push AX
ram:01f862 8dd4 mov A,0xffdf4
ram:01f864 9dd6 mov 0xffdf6,A
ram:01f866 c0 pop AX
ram:01f867 14 movw DE,AX
ram:01f868 300500 movw AX,0x5
ram:01f86b f7 clrw BC
ram:01f86c c1 push AX
ram:01f86d 8dd6 mov A,0xffdf6
ram:01f86f 9efc mov CS,A
ram:01f871 c0 pop AX
ram:01f872 61ea call DE
ram:01f874 1004 addw SP,0x4
ram:01f876 ebc8e9 movw DE,!0xfe9c8
ram:01f879 aa06 movw AX,[DE + 0x6]
ram:01f87b 12 movw BC,AX
ram:01f87c ac0c movw AX,[HL + 0xc]
ram:01f87e 23 subw AX,BC
ram:01f87f 12 movw BC,AX
ram:01f880 aa04 movw AX,[DE + 0x4]
ram:01f882 33 xchw AX,BC
ram:01f883 43 cmpw AX,BC
ram:01f884 dc16 bc $ 0x1f89c
ram:01f886 300500 movw AX,0x5
ram:01f889 ba04 movw [DE + 0x4],AX
ram:01f88b ac10 movw AX,[HL + 0x10]
ram:01f88d 14 movw DE,AX
ram:01f88e 300800 movw AX,0x8
ram:01f891 ba04 movw [DE + 0x4],AX
ram:01f893 ebc8e9 movw DE,!0xfe9c8
ram:01f896 ac0c movw AX,[HL + 0xc]
ram:01f898 ba06 movw [DE + 0x6],AX
ram:01f89a ef16 br $ 0x1f8b2
ram:01f89c ebc8e9 movw DE,!0xfe9c8
ram:01f89f aa04 movw AX,[DE + 0x4]
ram:01f8a1 6168 or A,
ram:01f8a3 dd05 bz $ 0x1f8aa
ram:01f8a5 aa04 movw AX,[DE + 0x4]
ram:01f8a7 b1 decw AX
ram:01f8a8 ba04 movw [DE + 0x4],AX
ram:01f8aa ac10 movw AX,[HL + 0x10]
ram:01f8ac 14 movw DE,AX
ram:01f8ad 306400 movw AX,0x64
ram:01f8b0 ba06 movw [DE + 0x6],AX
ram:01f8b2 ee620c br $! 0x20517
ram:01f8b5 8fc5d9 mov A,!0xfd9c5
ram:01f8b8 9c0c mov [HL + 0xc],A
ram:01f8ba cc0b01 mov [HL + 0xb],0x1
ram:01f8bd cc0d02 mov [HL + 0xd],0x2
ram:01f8c0 ac0e movw AX,[HL + 0xe]
ram:01f8c2 14 movw DE,AX
ram:01f8c3 8a02 mov A,[DE + 0x2]
ram:01f8c5 4e0d cmp A,[HL + 0xd]
ram:01f8c7 61d329 bnh $ 0x1f8f2
ram:01f8ca 8c0d mov A,[HL + 0xd]
ram:01f8cc 318e shrw AX,0x8
ram:01f8ce 04c4d9 addw AX,0xd9c4
ram:01f8d1 14 movw DE,AX
ram:01f8d2 89 mov A,[DE]
ram:01f8d3 4e0c cmp A,[HL + 0xc]
ram:01f8d5 61d316 bnh $ 0x1f8ed
ram:01f8d8 89 mov A,[DE]
ram:01f8d9 9c0c mov [HL + 0xc],A
ram:01f8db 8c0d mov A,[HL + 0xd]
ram:01f8dd 9c0b mov [HL + 0xb],A
ram:01f8df ac0e movw AX,[HL + 0xe]
ram:01f8e1 14 movw DE,AX
ram:01f8e2 8c0d mov A,[HL + 0xd]
ram:01f8e4 318e shrw AX,0x8
ram:01f8e6 a5 incw DE
ram:01f8e7 a5 incw DE
ram:01f8e8 a5 incw DE
ram:01f8e9 05 addw AX,DE
ram:01f8ea 14 movw DE,AX
ram:01f8eb 89 mov A,[DE]
ram:01f8ec 9c0a mov [HL + 0xa],A
ram:01f8ee 61590d inc [HL + 0xd]
ram:01f8f1 efcd br $ 0x1f8c0
ram:01f8f3 8c0b mov A,[HL + 0xb]
ram:01f8f5 318e shrw AX,0x8
ram:01f8f7 04c4d9 addw AX,0xd9c4
ram:01f8fa bc08 movw [HL + 0x8],AX
ram:01f8fc 8f71d9 mov A,!0xfd971
ram:01f8ff 311524 bf A.0x1,$ 0x1f925
ram:01f902 ebc8e9 movw DE,!0xfe9c8
ram:01f905 8a0d mov A,[DE + 0xd]
ram:01f907 4e0c cmp A,[HL + 0xc]
ram:01f909 61d31a bnh $ 0x1f925
ram:01f90c 8a0d mov A,[DE + 0xd]
ram:01f90e 9c0c mov [HL + 0xc],A
ram:01f910 ac0e movw AX,[HL + 0xe]
ram:01f912 14 movw DE,AX
ram:01f913 8a02 mov A,[DE + 0x2]
ram:01f915 9c0b mov [HL + 0xb],A
ram:01f917 ebc8e9 movw DE,!0xfe9c8
ram:01f91a 8a0c mov A,[DE + 0xc]
ram:01f91c 9c0a mov [HL + 0xa],A
ram:01f91e afc8e9 movw AX,!0xfe9c8
ram:01f921 040d00 addw AX,0xd
ram:01f924 bc08 movw [HL + 0x8],AX
ram:01f926 ebc8e9 movw DE,!0xfe9c8
ram:01f929 aa0a movw AX,[DE + 0xa]
ram:01f92b 12 movw BC,AX
ram:01f92c d9f2d9 mov X,!0xfd9f2
ram:01f92f f1 clrb A
ram:01f930 33 xchw AX,BC
ram:01f931 bdd8 movw 0xffdf8,AX
ram:01f933 13 movw AX,BC
ram:01f934 fdab06 call !0xf06ab
ram:01f937 61c8 skc
ram:01f939 eecf00 _br $! 0x1fa0b
ram:01f93c af6cd9 movw AX,!0xfd96c
ram:01f93f 42e8d9 cmpw AX,!0xfd9e8
ram:01f942 af6ad9 movw AX,!0xfd96a
ram:01f945 61f8 sknz
ram:01f947 42e6d9 _cmpw AX,!0xfd9e6
ram:01f94a 61f8 sknz
ram:01f94c eebc00 _br $! 0x1fa0b
ram:01f94f afe6d9 movw AX,!0xfd9e6
ram:01f952 dbe8d9 movw BC,!0xfd9e8
ram:01f955 fc350101 call !!0x10135
ram:01f959 ebc8e9 movw DE,!0xfe9c8
ram:01f95c 62 mov A,
ram:01f95d 9a16 mov [DE + 0x16],A
ram:01f95f afe8d9 movw AX,!0xfd9e8
ram:01f962 c1 push AX
ram:01f963 afe6d9 movw AX,!0xfd9e6
ram:01f966 c1 push AX
ram:01f967 d967d9 mov X,!0xfd967
ram:01f96a f1 clrb A
ram:01f96b c1 push AX
ram:01f96c ac10 movw AX,[HL + 0x10]
ram:01f96e fc56f400 call !!0xf456
ram:01f972 1006 addw SP,0x6
ram:01f974 ac10 movw AX,[HL + 0x10]
ram:01f976 14 movw DE,AX
ram:01f977 300600 movw AX,0x6
ram:01f97a ba04 movw [DE + 0x4],AX
ram:01f97c af08e4 movw AX,!0xfe408
ram:01f97f f7 clrw BC
ram:01f980 c3 push BC
ram:01f981 14 movw DE,AX
ram:01f982 8a0e mov A,[DE + 0xe]
ram:01f984 9efc mov CS,A
ram:01f986 aa0c movw AX,[DE + 0xc]
ram:01f988 14 movw DE,AX
ram:01f989 300300 movw AX,0x3
ram:01f98c 61ea call DE
ram:01f98e c0 pop AX
ram:01f98f af68d9 movw AX,!0xfd968
ram:01f992 c1 push AX
ram:01f993 ebc8e9 movw DE,!0xfe9c8
ram:01f996 8a16 mov A,[DE + 0x16]
ram:01f998 318e shrw AX,0x8
ram:01f99a fcaaf001 call !!0x1f0aa
ram:01f99e c0 pop AX
ram:01f99f 62 mov A,
ram:01f9a0 4c02 cmp A,#0x2
ram:01f9a2 df0b bnz $ 0x1f9af
ram:01f9a4 ebc8e9 movw DE,!0xfe9c8
ram:01f9a7 8a03 mov A,[DE + 0x3]
ram:01f9a9 6c10 or A,#0x10
ram:01f9ab 9a03 mov [DE + 0x3],A
ram:01f9ad ef09 br $ 0x1f9b8
ram:01f9af ebc8e9 movw DE,!0xfe9c8
ram:01f9b2 8a03 mov A,[DE + 0x3]
ram:01f9b4 5cef and A,#0xef
ram:01f9b6 9a03 mov [DE + 0x3],A
ram:01f9b8 af6ad9 movw AX,!0xfd96a
ram:01f9bb db6cd9 movw BC,!0xfd96c
ram:01f9be fc350101 call !!0x10135
ram:01f9c2 f3 clrb B
ram:01f9c3 13 movw AX,BC
ram:01f9c4 fceef201 call !!0x1f2ee
ram:01f9c8 8f71d9 mov A,!0xfd971
ram:01f9cb 31353a bf A.0x3,$ 0x1fa07
ram:01f9ce c7 push HL
ram:01f9cf 17 movw AX,HL
ram:01f9d0 16 movw HL,AX
ram:01f9d1 f7 clrw BC
ram:01f9d2 49b85e mov A,!0xf5eb8[BC]
ram:01f9d5 9b mov [HL],A
ram:01f9d6 a3 incw BC
ram:01f9d7 a7 incw HL
ram:01f9d8 5108 mov ,0x8
ram:01f9da 614a cmp A,
ram:01f9dc dff4 bnz $ 0x1f9d2
ram:01f9de c6 pop HL
ram:01f9df 9b mov [HL],A
ram:01f9e0 af6ad9 movw AX,!0xfd96a
ram:01f9e3 db6cd9 movw BC,!0xfd96c
ram:01f9e6 fc350101 call !!0x10135
ram:01f9ea 62 mov A,
ram:01f9eb 9c01 mov [HL + 0x1],A
ram:01f9ed ebc8e9 movw DE,!0xfe9c8
ram:01f9f0 8a16 mov A,[DE + 0x16]
ram:01f9f2 9c02 mov [HL + 0x2],A
ram:01f9f4 db02e4 movw BC,!0xfe402
ram:01f9f7 17 movw AX,HL
ram:01f9f8 c1 push AX
ram:01f9f9 491a00 mov A,!0xf001a[BC]
ram:01f9fc 9efc mov CS,A
ram:01f9fe 791800 movw AX,!0xf0018[BC]
ram:01fa01 14 movw DE,AX
ram:01fa02 305a00 movw AX,0x5a
ram:01fa05 61ea call DE
ram:01fa07 c0 pop AX
ram:01fa08 eef800 br $! 0x1fb03
ram:01fa0b 8f71d9 mov A,!0xfd971
ram:01fa0e 311519 bf A.0x1,$ 0x1fa29
ram:01fa11 8ff3d9 mov A,!0xfd9f3
ram:01fa14 4e0c cmp A,[HL + 0xc]
ram:01fa16 dc39 bc $ 0x1fa51
ram:01fa18 8ff2d9 mov A,!0xfd9f2
ram:01fa1b 4e0c cmp A,[HL + 0xc]
ram:01fa1d de0b bnc $ 0x1fa2a
ram:01fa1f 8c0a mov A,[HL + 0xa]
ram:01fa21 318e shrw AX,0x8
ram:01fa23 fcbbf301 call !!0x1f3bb
ram:01fa27 92 dec 
ram:01fa28 dd27 bz $ 0x1fa51
ram:01fa2a 8f71d9 mov A,!0xfd971
ram:01fa2d 311343 bt A.0x1,$ 0x1fa72
ram:01fa30 ebc8e9 movw DE,!0xfe9c8
ram:01fa33 aa0a movw AX,[DE + 0xa]
ram:01fa35 040a00 addw AX,0xa
ram:01fa38 12 movw BC,AX
ram:01fa39 8c0c mov A,[HL + 0xc]
ram:01fa3b 318e shrw AX,0x8
ram:01fa3d 33 xchw AX,BC
ram:01fa3e bdd8 movw 0xffdf8,AX
ram:01fa40 13 movw AX,BC
ram:01fa41 fdab06 call !0xf06ab
ram:01fa44 de2d bnc $ 0x1fa73
ram:01fa46 8c0a mov A,[HL + 0xa]
ram:01fa48 318e shrw AX,0x8
ram:01fa4a fcbbf301 call !!0x1f3bb
ram:01fa4e 92 dec 
ram:01fa4f df22 bnz $ 0x1fa73
ram:01fa51 ebc8e9 movw DE,!0xfe9c8
ram:01fa54 8c0a mov A,[HL + 0xa]
ram:01fa56 9a16 mov [DE + 0x16],A
ram:01fa58 ebc8e9 movw DE,!0xfe9c8
ram:01fa5b ac08 movw AX,[HL + 0x8]
ram:01fa5d ba14 movw [DE + 0x14],AX
ram:01fa5f ebc8e9 movw DE,!0xfe9c8
ram:01fa62 8a03 mov A,[DE + 0x3]
ram:01fa64 5cef and A,#0xef
ram:01fa66 9a03 mov [DE + 0x3],A
ram:01fa68 ac10 movw AX,[HL + 0x10]
ram:01fa6a 14 movw DE,AX
ram:01fa6b 300900 movw AX,0x9
ram:01fa6e ba04 movw [DE + 0x4],AX
ram:01fa70 ee9000 br $! 0x1fb03
ram:01fa73 8f71d9 mov A,!0xfd971
ram:01fa76 311503 bf A.0x1,$ 0x1fa7b
ram:01fa79 ee8100 br $! 0x1fafd
ram:01fa7c 8ff0d9 mov A,!0xfd9f0
ram:01fa7f 4e0c cmp A,[HL + 0xc]
ram:01fa81 de16 bnc $ 0x1fa99
ram:01fa83 ebc8e9 movw DE,!0xfe9c8
ram:01fa86 aa0a movw AX,[DE + 0xa]
ram:01fa88 040500 addw AX,0x5
ram:01fa8b 12 movw BC,AX
ram:01fa8c 8c0c mov A,[HL + 0xc]
ram:01fa8e 318e shrw AX,0x8
ram:01fa90 33 xchw AX,BC
ram:01fa91 bdd8 movw 0xffdf8,AX
ram:01fa93 13 movw AX,BC
ram:01fa94 fdab06 call !0xf06ab
ram:01fa97 dc29 bc $ 0x1fac2
ram:01fa99 ebc8e9 movw DE,!0xfe9c8
ram:01fa9c aa14 movw AX,[DE + 0x14]
ram:01fa9e 14 movw DE,AX
ram:01fa9f 89 mov A,[DE]
ram:01faa0 72 mov ,A
ram:01faa1 8ff3d9 mov A,!0xfd9f3
ram:01faa4 614a cmp A,
ram:01faa6 de55 bnc $ 0x1fafd
ram:01faa8 ebc8e9 movw DE,!0xfe9c8
ram:01faab aa0a movw AX,[DE + 0xa]
ram:01faad f9f1d9 mov C,!0xfd9f1
ram:01fab0 f3 clrb B
ram:01fab1 03 addw AX,BC
ram:01fab2 12 movw BC,AX
ram:01fab3 aa14 movw AX,[DE + 0x14]
ram:01fab5 14 movw DE,AX
ram:01fab6 89 mov A,[DE]
ram:01fab7 318e shrw AX,0x8
ram:01fab9 33 xchw AX,BC
ram:01faba bdd8 movw 0xffdf8,AX
ram:01fabc 13 movw AX,BC
ram:01fabd fdab06 call !0xf06ab
ram:01fac0 de3b bnc $ 0x1fafd
ram:01fac2 ac0e movw AX,[HL + 0xe]
ram:01fac4 14 movw DE,AX
ram:01fac5 8c0b mov A,[HL + 0xb]
ram:01fac7 318e shrw AX,0x8
ram:01fac9 a5 incw DE
ram:01faca a5 incw DE
ram:01facb a5 incw DE
ram:01facc 05 addw AX,DE
ram:01facd 14 movw DE,AX
ram:01face 89 mov A,[DE]
ram:01facf ebc8e9 movw DE,!0xfe9c8
ram:01fad2 9a16 mov [DE + 0x16],A
ram:01fad4 ebc8e9 movw DE,!0xfe9c8
ram:01fad7 9a12 mov [DE + 0x12],A
ram:01fad9 8c0b mov A,[HL + 0xb]
ram:01fadb 318e shrw AX,0x8
ram:01fadd 04c4d9 addw AX,0xd9c4
ram:01fae0 ebc8e9 movw DE,!0xfe9c8
ram:01fae3 ba14 movw [DE + 0x14],AX
ram:01fae5 ebc8e9 movw DE,!0xfe9c8
ram:01fae8 ba10 movw [DE + 0x10],AX
ram:01faea ebc8e9 movw DE,!0xfe9c8
ram:01faed 8a03 mov A,[DE + 0x3]
ram:01faef 5cef and A,#0xef
ram:01faf1 9a03 mov [DE + 0x3],A
ram:01faf3 ac10 movw AX,[HL + 0x10]
ram:01faf5 14 movw DE,AX
ram:01faf6 300a00 movw AX,0xa
ram:01faf9 ba04 movw [DE + 0x4],AX
ram:01fafb ef06 br $ 0x1fb03
ram:01fafd ac10 movw AX,[HL + 0x10]
ram:01faff 14 movw DE,AX
ram:01fb00 e6 onew AX
ram:01fb01 ba04 movw [DE + 0x4],AX
ram:01fb03 ac10 movw AX,[HL + 0x10]
ram:01fb05 14 movw DE,AX
ram:01fb06 300c00 movw AX,0xc
ram:01fb09 ba06 movw [DE + 0x6],AX
ram:01fb0b ee090a br $! 0x20517
ram:01fb0e 8f71d9 mov A,!0xfd971
ram:01fb11 311303 bt A.0x1,$ 0x1fb16
ram:01fb14 ee1a01 br $! 0x1fc31
ram:01fb17 ebc8e9 movw DE,!0xfe9c8
ram:01fb1a 8a01 mov A,[DE + 0x1]
ram:01fb1c 316367 bt A.0x6,$ 0x1fb85
ram:01fb1f ca0d00 mov [DE + 0xd],0x0
ram:01fb22 ebc8e9 movw DE,!0xfe9c8
ram:01fb25 8a01 mov A,[DE + 0x1]
ram:01fb27 81 inc 
ram:01fb28 5c3f and A,#0x3f
ram:01fb2a 70 mov ,A
ram:01fb2b 8a01 mov A,[DE + 0x1]
ram:01fb2d 5cc0 and A,#0xc0
ram:01fb2f 6168 or A,
ram:01fb31 9a01 mov [DE + 0x1],A
ram:01fb33 ebc8e9 movw DE,!0xfe9c8
ram:01fb36 8a01 mov A,[DE + 0x1]
ram:01fb38 5c3f and A,#0x3f
ram:01fb3a 72 mov ,A
ram:01fb3b ac0e movw AX,[HL + 0xe]
ram:01fb3d 14 movw DE,AX
ram:01fb3e 8a02 mov A,[DE + 0x2]
ram:01fb40 6142 cmp ,A
ram:01fb42 dc0a bc $ 0x1fb4e
ram:01fb44 ebc8e9 movw DE,!0xfe9c8
ram:01fb47 8a01 mov A,[DE + 0x1]
ram:01fb49 5cc0 and A,#0xc0
ram:01fb4b 81 inc 
ram:01fb4c 9a01 mov [DE + 0x1],A
ram:01fb4e ac0e movw AX,[HL + 0xe]
ram:01fb50 040300 addw AX,0x3
ram:01fb53 12 movw BC,AX
ram:01fb54 ebc8e9 movw DE,!0xfe9c8
ram:01fb57 8a01 mov A,[DE + 0x1]
ram:01fb59 5c3f and A,#0x3f
ram:01fb5b 318e shrw AX,0x8
ram:01fb5d 03 addw AX,BC
ram:01fb5e 14 movw DE,AX
ram:01fb5f 89 mov A,[DE]
ram:01fb60 ebc8e9 movw DE,!0xfe9c8
ram:01fb63 9a12 mov [DE + 0x12],A
ram:01fb65 ebc8e9 movw DE,!0xfe9c8
ram:01fb68 8a01 mov A,[DE + 0x1]
ram:01fb6a 5c3f and A,#0x3f
ram:01fb6c 318e shrw AX,0x8
ram:01fb6e 04c4d9 addw AX,0xd9c4
ram:01fb71 12 movw BC,AX
ram:01fb72 ba10 movw [DE + 0x10],AX
ram:01fb74 ebc8e9 movw DE,!0xfe9c8
ram:01fb77 8a01 mov A,[DE + 0x1]
ram:01fb79 0c40 add A,#0x40
ram:01fb7b 71ec mov1 CY,A.0x6
ram:01fb7d 8a01 mov A,[DE + 0x1]
ram:01fb7f 71e9 mov1 A.0x6,CY
ram:01fb81 9a01 mov [DE + 0x1],A
ram:01fb83 ee8500 br $! 0x1fc0b
ram:01fb86 ebc8e9 movw DE,!0xfe9c8
ram:01fb89 8a0c mov A,[DE + 0xc]
ram:01fb8b 81 inc 
ram:01fb8c 9a0c mov [DE + 0xc],A
ram:01fb8e ebc8e9 movw DE,!0xfe9c8
ram:01fb91 8a0c mov A,[DE + 0xc]
ram:01fb93 d1 cmp0 A
ram:01fb94 dd06 bz $ 0x1fb9c
ram:01fb96 8a0c mov A,[DE + 0xc]
ram:01fb98 4ccd cmp A,#0xcd
ram:01fb9a dc06 bc $ 0x1fba2
ram:01fb9c ebc8e9 movw DE,!0xfe9c8
ram:01fb9f ca0c00 mov [DE + 0xc],0x0
ram:01fba2 cc0d00 mov [HL + 0xd],0x0
ram:01fba5 ac0e movw AX,[HL + 0xe]
ram:01fba7 14 movw DE,AX
ram:01fba8 8a02 mov A,[DE + 0x2]
ram:01fbaa 4e0d cmp A,[HL + 0xd]
ram:01fbac 61d31c bnh $ 0x1fbca
ram:01fbaf ebc8e9 movw DE,!0xfe9c8
ram:01fbb2 8a0c mov A,[DE + 0xc]
ram:01fbb4 72 mov ,A
ram:01fbb5 ac0e movw AX,[HL + 0xe]
ram:01fbb7 14 movw DE,AX
ram:01fbb8 8c0d mov A,[HL + 0xd]
ram:01fbba 318e shrw AX,0x8
ram:01fbbc a5 incw DE
ram:01fbbd a5 incw DE
ram:01fbbe a5 incw DE
ram:01fbbf 05 addw AX,DE
ram:01fbc0 14 movw DE,AX
ram:01fbc1 89 mov A,[DE]
ram:01fbc2 6142 cmp ,A
ram:01fbc4 dd05 bz $ 0x1fbcb
ram:01fbc6 61590d inc [HL + 0xd]
ram:01fbc9 efda br $ 0x1fba5
ram:01fbcb ac0e movw AX,[HL + 0xe]
ram:01fbcd 14 movw DE,AX
ram:01fbce 8a02 mov A,[DE + 0x2]
ram:01fbd0 4e0d cmp A,[HL + 0xd]
ram:01fbd2 dfb2 bnz $ 0x1fb86
ram:01fbd4 af68d9 movw AX,!0xfd968
ram:01fbd7 c1 push AX
ram:01fbd8 ebc8e9 movw DE,!0xfe9c8
ram:01fbdb 8a0c mov A,[DE + 0xc]
ram:01fbdd 318e shrw AX,0x8
ram:01fbdf fcaaf001 call !!0x1f0aa
ram:01fbe3 c0 pop AX
ram:01fbe4 62 mov A,
ram:01fbe5 4c03 cmp A,#0x3
ram:01fbe7 dd9d bz $ 0x1fb86
ram:01fbe9 ebc8e9 movw DE,!0xfe9c8
ram:01fbec 8a0c mov A,[DE + 0xc]
ram:01fbee 9a12 mov [DE + 0x12],A
ram:01fbf0 afc8e9 movw AX,!0xfe9c8
ram:01fbf3 040d00 addw AX,0xd
ram:01fbf6 12 movw BC,AX
ram:01fbf7 ebc8e9 movw DE,!0xfe9c8
ram:01fbfa ba10 movw [DE + 0x10],AX
ram:01fbfc ebc8e9 movw DE,!0xfe9c8
ram:01fbff 8a01 mov A,[DE + 0x1]
ram:01fc01 0c40 add A,#0x40
ram:01fc03 71ec mov1 CY,A.0x6
ram:01fc05 8a01 mov A,[DE + 0x1]
ram:01fc07 71e9 mov1 A.0x6,CY
ram:01fc09 9a01 mov [DE + 0x1],A
ram:01fc0b f6 clrw AX
ram:01fc0c c1 push AX
ram:01fc0d 3445f6 movw DE,0xf645
ram:01fc10 5201 mov ,0x1
ram:01fc12 c3 push BC
ram:01fc13 c5 push DE
ram:01fc14 ac10 movw AX,[HL + 0x10]
ram:01fc16 14 movw DE,AX
ram:01fc17 89 mov A,[DE]
ram:01fc18 318e shrw AX,0x8
ram:01fc1a fcd97c00 call !!0x7cd9
ram:01fc1e 1006 addw SP,0x6
ram:01fc20 ac10 movw AX,[HL + 0x10]
ram:01fc22 14 movw DE,AX
ram:01fc23 300700 movw AX,0x7
ram:01fc26 ba04 movw [DE + 0x4],AX
ram:01fc28 ac10 movw AX,[HL + 0x10]
ram:01fc2a 14 movw DE,AX
ram:01fc2b f6 clrw AX
ram:01fc2c ba06 movw [DE + 0x6],AX
ram:01fc2e eede01 br $! 0x1fe0f
ram:01fc31 ebc8e9 movw DE,!0xfe9c8
ram:01fc34 89 mov A,[DE]
ram:01fc35 311303 bt A.0x1,$ 0x1fc3a
ram:01fc38 eee900 br $! 0x1fd24
ram:01fc3b e6 onew AX
ram:01fc3c bc0a movw [HL + 0xa],AX
ram:01fc3e 8fc5d9 mov A,!0xfd9c5
ram:01fc41 9c09 mov [HL + 0x9],A
ram:01fc43 cc0d02 mov [HL + 0xd],0x2
ram:01fc46 ac0e movw AX,[HL + 0xe]
ram:01fc48 14 movw DE,AX
ram:01fc49 8a02 mov A,[DE + 0x2]
ram:01fc4b 4e0d cmp A,[HL + 0xd]
ram:01fc4d 61d377 bnh $ 0x1fcc6
ram:01fc50 ebc8e9 movw DE,!0xfe9c8
ram:01fc53 8a0e mov A,[DE + 0xe]
ram:01fc55 72 mov ,A
ram:01fc56 ac0e movw AX,[HL + 0xe]
ram:01fc58 14 movw DE,AX
ram:01fc59 8c0d mov A,[HL + 0xd]
ram:01fc5b 318e shrw AX,0x8
ram:01fc5d a5 incw DE
ram:01fc5e a5 incw DE
ram:01fc5f a5 incw DE
ram:01fc60 05 addw AX,DE
ram:01fc61 14 movw DE,AX
ram:01fc62 89 mov A,[DE]
ram:01fc63 6142 cmp ,A
ram:01fc65 dd5a bz $ 0x1fcc1
ram:01fc67 8c0d mov A,[HL + 0xd]
ram:01fc69 73 mov ,A
ram:01fc6a 09c4d9 mov A,!0xfd9c4[B]
ram:01fc6d 4e09 cmp A,[HL + 0x9]
ram:01fc6f 61d34f bnh $ 0x1fcc0
ram:01fc72 af68d9 movw AX,!0xfd968
ram:01fc75 c1 push AX
ram:01fc76 ac0e movw AX,[HL + 0xe]
ram:01fc78 14 movw DE,AX
ram:01fc79 8c0d mov A,[HL + 0xd]
ram:01fc7b 318e shrw AX,0x8
ram:01fc7d a5 incw DE
ram:01fc7e a5 incw DE
ram:01fc7f a5 incw DE
ram:01fc80 05 addw AX,DE
ram:01fc81 14 movw DE,AX
ram:01fc82 89 mov A,[DE]
ram:01fc83 318e shrw AX,0x8
ram:01fc85 fcaaf001 call !!0x1f0aa
ram:01fc89 c0 pop AX
ram:01fc8a 62 mov A,
ram:01fc8b 9c08 mov [HL + 0x8],A
ram:01fc8d 2c02 sub A,#0x2
ram:01fc8f dc0b bc $ 0x1fc9c
ram:01fc91 d1 cmp0 A
ram:01fc92 dd18 bz $ 0x1fcac
ram:01fc94 91 dec 
ram:01fc95 dd2a bz $ 0x1fcc1
ram:01fc97 91 dec 
ram:01fc98 2c02 sub A,#0x2
ram:01fc9a de25 bnc $ 0x1fcc1
ram:01fc9c 8c0d mov A,[HL + 0xd]
ram:01fc9e 318e shrw AX,0x8
ram:01fca0 bc0a movw [HL + 0xa],AX
ram:01fca2 8c0d mov A,[HL + 0xd]
ram:01fca4 73 mov ,A
ram:01fca5 09c4d9 mov A,!0xfd9c4[B]
ram:01fca8 9c09 mov [HL + 0x9],A
ram:01fcaa ef15 br $ 0x1fcc1
ram:01fcac ebc8e9 movw DE,!0xfe9c8
ram:01fcaf 89 mov A,[DE]
ram:01fcb0 31050e bf A.0x0,$ 0x1fcc0
ram:01fcb3 8c0d mov A,[HL + 0xd]
ram:01fcb5 318e shrw AX,0x8
ram:01fcb7 bc0a movw [HL + 0xa],AX
ram:01fcb9 8c0d mov A,[HL + 0xd]
ram:01fcbb 73 mov ,A
ram:01fcbc 09c4d9 mov A,!0xfd9c4[B]
ram:01fcbf 9c09 mov [HL + 0x9],A
ram:01fcc1 61590d inc [HL + 0xd]
ram:01fcc4 ee7fff br $! 0x1fc46
ram:01fcc7 8c09 mov A,[HL + 0x9]
ram:01fcc9 4c10 cmp A,#0x10
ram:01fccb dc4c bc $ 0x1fd19
ram:01fccd ac0e movw AX,[HL + 0xe]
ram:01fccf 14 movw DE,AX
ram:01fcd0 ac0a movw AX,[HL + 0xa]
ram:01fcd2 a5 incw DE
ram:01fcd3 a5 incw DE
ram:01fcd4 a5 incw DE
ram:01fcd5 05 addw AX,DE
ram:01fcd6 14 movw DE,AX
ram:01fcd7 89 mov A,[DE]
ram:01fcd8 ebc8e9 movw DE,!0xfe9c8
ram:01fcdb 9a12 mov [DE + 0x12],A
ram:01fcdd ebc8e9 movw DE,!0xfe9c8
ram:01fce0 9a0e mov [DE + 0xe],A
ram:01fce2 ac0a movw AX,[HL + 0xa]
ram:01fce4 04c4d9 addw AX,0xd9c4
ram:01fce7 12 movw BC,AX
ram:01fce8 ebc8e9 movw DE,!0xfe9c8
ram:01fceb ba10 movw [DE + 0x10],AX
ram:01fced f6 clrw AX
ram:01fcee c1 push AX
ram:01fcef 3445f6 movw DE,0xf645
ram:01fcf2 5201 mov ,0x1
ram:01fcf4 c3 push BC
ram:01fcf5 c5 push DE
ram:01fcf6 ac10 movw AX,[HL + 0x10]
ram:01fcf8 14 movw DE,AX
ram:01fcf9 89 mov A,[DE]
ram:01fcfa 318e shrw AX,0x8
ram:01fcfc fcd97c00 call !!0x7cd9
ram:01fd00 1006 addw SP,0x6
ram:01fd02 ac10 movw AX,[HL + 0x10]
ram:01fd04 14 movw DE,AX
ram:01fd05 300700 movw AX,0x7
ram:01fd08 ba04 movw [DE + 0x4],AX
ram:01fd0a ac10 movw AX,[HL + 0x10]
ram:01fd0c 14 movw DE,AX
ram:01fd0d f6 clrw AX
ram:01fd0e ba06 movw [DE + 0x6],AX
ram:01fd10 ebc8e9 movw DE,!0xfe9c8
ram:01fd13 89 mov A,[DE]
ram:01fd14 5cfd and A,#0xfd
ram:01fd16 99 mov [DE],A
ram:01fd17 ef08 br $ 0x1fd21
ram:01fd19 ac10 movw AX,[HL + 0x10]
ram:01fd1b 14 movw DE,AX
ram:01fd1c 303200 movw AX,0x32
ram:01fd1f ba06 movw [DE + 0x6],AX
ram:01fd21 eeeb00 br $! 0x1fe0f
ram:01fd24 ac0e movw AX,[HL + 0xe]
ram:01fd26 14 movw DE,AX
ram:01fd27 8a02 mov A,[DE + 0x2]
ram:01fd29 91 dec 
ram:01fd2a 9c0c mov [HL + 0xc],A
ram:01fd2c cc0d00 mov [HL + 0xd],0x0
ram:01fd2f 8c0d mov A,[HL + 0xd]
ram:01fd31 4e0c cmp A,[HL + 0xc]
ram:01fd33 61c8 skc
ram:01fd35 ee7d00 _br $! 0x1fdb5
ram:01fd38 ebc8e9 movw DE,!0xfe9c8
ram:01fd3b 89 mov A,[DE]
ram:01fd3c 0c04 add A,#0x4
ram:01fd3e 5cfc and A,#0xfc
ram:01fd40 70 mov ,A
ram:01fd41 89 mov A,[DE]
ram:01fd42 5c03 and A,#0x3
ram:01fd44 6168 or A,
ram:01fd46 99 mov [DE],A
ram:01fd47 ebc8e9 movw DE,!0xfe9c8
ram:01fd4a 89 mov A,[DE]
ram:01fd4b 312a shr A,0x2
ram:01fd4d 72 mov ,A
ram:01fd4e ac0e movw AX,[HL + 0xe]
ram:01fd50 14 movw DE,AX
ram:01fd51 8a02 mov A,[DE + 0x2]
ram:01fd53 6142 cmp ,A
ram:01fd55 dc09 bc $ 0x1fd60
ram:01fd57 ebc8e9 movw DE,!0xfe9c8
ram:01fd5a 89 mov A,[DE]
ram:01fd5b 5c03 and A,#0x3
ram:01fd5d 6c04 or A,#0x4
ram:01fd5f 99 mov [DE],A
ram:01fd60 ebc8e9 movw DE,!0xfe9c8
ram:01fd63 89 mov A,[DE]
ram:01fd64 31ae shrw AX,0xa
ram:01fd66 12 movw BC,AX
ram:01fd67 49c4d9 mov A,!0xfd9c4[BC]
ram:01fd6a 4c1e cmp A,#0x1e
ram:01fd6c dc41 bc $ 0x1fdaf
ram:01fd6e cc0b00 mov [HL + 0xb],0x0
ram:01fd71 af68d9 movw AX,!0xfd968
ram:01fd74 c1 push AX
ram:01fd75 ac0e movw AX,[HL + 0xe]
ram:01fd77 14 movw DE,AX
ram:01fd78 8c0d mov A,[HL + 0xd]
ram:01fd7a 318e shrw AX,0x8
ram:01fd7c a5 incw DE
ram:01fd7d a5 incw DE
ram:01fd7e a5 incw DE
ram:01fd7f 05 addw AX,DE
ram:01fd80 14 movw DE,AX
ram:01fd81 89 mov A,[DE]
ram:01fd82 318e shrw AX,0x8
ram:01fd84 fcaaf001 call !!0x1f0aa
ram:01fd88 c0 pop AX
ram:01fd89 62 mov A,
ram:01fd8a 9c0a mov [HL + 0xa],A
ram:01fd8c 2c02 sub A,#0x2
ram:01fd8e dc0b bc $ 0x1fd9b
ram:01fd90 d1 cmp0 A
ram:01fd91 dd0d bz $ 0x1fda0
ram:01fd93 91 dec 
ram:01fd94 dd14 bz $ 0x1fdaa
ram:01fd96 91 dec 
ram:01fd97 2c02 sub A,#0x2
ram:01fd99 de0f bnc $ 0x1fdaa
ram:01fd9b cc0b01 mov [HL + 0xb],0x1
ram:01fd9e ef0a br $ 0x1fdaa
ram:01fda0 ebc8e9 movw DE,!0xfe9c8
ram:01fda3 89 mov A,[DE]
ram:01fda4 310503 bf A.0x0,$ 0x1fda9
ram:01fda7 cc0b01 mov [HL + 0xb],0x1
ram:01fdaa 8c0b mov A,[HL + 0xb]
ram:01fdac 91 dec 
ram:01fdad dd06 bz $ 0x1fdb5
ram:01fdaf 61590d inc [HL + 0xd]
ram:01fdb2 ee7aff br $! 0x1fd2f
ram:01fdb5 8c0d mov A,[HL + 0xd]
ram:01fdb7 4e0c cmp A,[HL + 0xc]
ram:01fdb9 df0a bnz $ 0x1fdc5
ram:01fdbb ac10 movw AX,[HL + 0x10]
ram:01fdbd 14 movw DE,AX
ram:01fdbe 303200 movw AX,0x32
ram:01fdc1 ba06 movw [DE + 0x6],AX
ram:01fdc3 ef43 br $ 0x1fe08
ram:01fdc5 ac0e movw AX,[HL + 0xe]
ram:01fdc7 040300 addw AX,0x3
ram:01fdca 12 movw BC,AX
ram:01fdcb ebc8e9 movw DE,!0xfe9c8
ram:01fdce 89 mov A,[DE]
ram:01fdcf 31ae shrw AX,0xa
ram:01fdd1 03 addw AX,BC
ram:01fdd2 14 movw DE,AX
ram:01fdd3 89 mov A,[DE]
ram:01fdd4 ebc8e9 movw DE,!0xfe9c8
ram:01fdd7 9a12 mov [DE + 0x12],A
ram:01fdd9 ebc8e9 movw DE,!0xfe9c8
ram:01fddc 89 mov A,[DE]
ram:01fddd 31ae shrw AX,0xa
ram:01fddf 04c4d9 addw AX,0xd9c4
ram:01fde2 12 movw BC,AX
ram:01fde3 ba10 movw [DE + 0x10],AX
ram:01fde5 f6 clrw AX
ram:01fde6 c1 push AX
ram:01fde7 3445f6 movw DE,0xf645
ram:01fdea 5201 mov ,0x1
ram:01fdec c3 push BC
ram:01fded c5 push DE
ram:01fdee ac10 movw AX,[HL + 0x10]
ram:01fdf0 14 movw DE,AX
ram:01fdf1 89 mov A,[DE]
ram:01fdf2 318e shrw AX,0x8
ram:01fdf4 fcd97c00 call !!0x7cd9
ram:01fdf8 1006 addw SP,0x6
ram:01fdfa ac10 movw AX,[HL + 0x10]
ram:01fdfc 14 movw DE,AX
ram:01fdfd 300700 movw AX,0x7
ram:01fe00 ba04 movw [DE + 0x4],AX
ram:01fe02 ac10 movw AX,[HL + 0x10]
ram:01fe04 14 movw DE,AX
ram:01fe05 f6 clrw AX
ram:01fe06 ba06 movw [DE + 0x6],AX
ram:01fe08 ebc8e9 movw DE,!0xfe9c8
ram:01fe0b 89 mov A,[DE]
ram:01fe0c 6c02 or A,#0x2
ram:01fe0e 99 mov [DE],A
ram:01fe0f ee0507 br $! 0x20517
ram:01fe12 f6 clrw AX
ram:01fe13 c1 push AX
ram:01fe14 3445f6 movw DE,0xf645
ram:01fe17 5201 mov ,0x1
ram:01fe19 c3 push BC
ram:01fe1a c5 push DE
ram:01fe1b ac10 movw AX,[HL + 0x10]
ram:01fe1d 14 movw DE,AX
ram:01fe1e 89 mov A,[DE]
ram:01fe1f 318e shrw AX,0x8
ram:01fe21 fcd97c00 call !!0x7cd9
ram:01fe25 1006 addw SP,0x6
ram:01fe27 ac10 movw AX,[HL + 0x10]
ram:01fe29 14 movw DE,AX
ram:01fe2a 300b00 movw AX,0xb
ram:01fe2d ba04 movw [DE + 0x4],AX
ram:01fe2f eee506 br $! 0x20517
ram:01fe32 ebc8e9 movw DE,!0xfe9c8
ram:01fe35 aa14 movw AX,[DE + 0x14]
ram:01fe37 14 movw DE,AX
ram:01fe38 89 mov A,[DE]
ram:01fe39 72 mov ,A
ram:01fe3a 8ff0d9 mov A,!0xfd9f0
ram:01fe3d 614a cmp A,
ram:01fe3f de18 bnc $ 0x1fe59
ram:01fe41 ebc8e9 movw DE,!0xfe9c8
ram:01fe44 aa0a movw AX,[DE + 0xa]
ram:01fe46 040500 addw AX,0x5
ram:01fe49 12 movw BC,AX
ram:01fe4a aa14 movw AX,[DE + 0x14]
ram:01fe4c 14 movw DE,AX
ram:01fe4d 89 mov A,[DE]
ram:01fe4e 318e shrw AX,0x8
ram:01fe50 33 xchw AX,BC
ram:01fe51 bdd8 movw 0xffdf8,AX
ram:01fe53 13 movw AX,BC
ram:01fe54 fdab06 call !0xf06ab
ram:01fe57 dc29 bc $ 0x1fe82
ram:01fe59 ebc8e9 movw DE,!0xfe9c8
ram:01fe5c aa14 movw AX,[DE + 0x14]
ram:01fe5e 14 movw DE,AX
ram:01fe5f 89 mov A,[DE]
ram:01fe60 72 mov ,A
ram:01fe61 8ff3d9 mov A,!0xfd9f3
ram:01fe64 614a cmp A,
ram:01fe66 de24 bnc $ 0x1fe8c
ram:01fe68 ebc8e9 movw DE,!0xfe9c8
ram:01fe6b aa0a movw AX,[DE + 0xa]
ram:01fe6d f9f1d9 mov C,!0xfd9f1
ram:01fe70 f3 clrb B
ram:01fe71 03 addw AX,BC
ram:01fe72 12 movw BC,AX
ram:01fe73 aa14 movw AX,[DE + 0x14]
ram:01fe75 14 movw DE,AX
ram:01fe76 89 mov A,[DE]
ram:01fe77 318e shrw AX,0x8
ram:01fe79 33 xchw AX,BC
ram:01fe7a bdd8 movw 0xffdf8,AX
ram:01fe7c 13 movw AX,BC
ram:01fe7d fdab06 call !0xf06ab
ram:01fe80 de0a bnc $ 0x1fe8c
ram:01fe82 ac10 movw AX,[HL + 0x10]
ram:01fe84 14 movw DE,AX
ram:01fe85 300900 movw AX,0x9
ram:01fe88 ba04 movw [DE + 0x4],AX
ram:01fe8a ef06 br $ 0x1fe92
ram:01fe8c ac10 movw AX,[HL + 0x10]
ram:01fe8e 14 movw DE,AX
ram:01fe8f e6 onew AX
ram:01fe90 ba04 movw [DE + 0x4],AX
ram:01fe92 ee8206 br $! 0x20517
ram:01fe95 af68d9 movw AX,!0xfd968
ram:01fe98 c1 push AX
ram:01fe99 ebc8e9 movw DE,!0xfe9c8
ram:01fe9c 8a16 mov A,[DE + 0x16]
ram:01fe9e 318e shrw AX,0x8
ram:01fea0 fcaaf001 call !!0x1f0aa
ram:01fea4 c0 pop AX
ram:01fea5 62 mov A,
ram:01fea6 9c0d mov [HL + 0xd],A
ram:01fea8 d1 cmp0 A
ram:01fea9 61f8 sknz
ram:01feab ee0401 _br $! 0x1ffb2
ram:01feae 91 dec 
ram:01feaf dd1a bz $ 0x1fecb
ram:01feb1 91 dec 
ram:01feb2 61f8 sknz
ram:01feb4 eefb00 _br $! 0x1ffb2
ram:01feb7 91 dec 
ram:01feb8 61f8 sknz
ram:01feba eebc01 _br $! 0x20079
ram:01febd 91 dec 
ram:01febe 2c02 sub A,#0x2
ram:01fec0 61d8 sknc
ram:01fec2 eec601 _br $! 0x2008b
ram:01fec5 d1 cmp0 A
ram:01fec6 dd68 bz $ 0x1ff30
ram:01fec8 eec102 br $! 0x2018c
ram:01fecb e6 onew AX
ram:01fecc fc0b0301 call !!0x1030b
ram:01fed0 af08e4 movw AX,!0xfe408
ram:01fed3 f7 clrw BC
ram:01fed4 c3 push BC
ram:01fed5 14 movw DE,AX
ram:01fed6 8a0e mov A,[DE + 0xe]
ram:01fed8 9efc mov CS,A
ram:01feda aa0c movw AX,[DE + 0xc]
ram:01fedc 14 movw DE,AX
ram:01fedd 300500 movw AX,0x5
ram:01fee0 61ea call DE
ram:01fee2 c0 pop AX
ram:01fee3 ebc8e9 movw DE,!0xfe9c8
ram:01fee6 89 mov A,[DE]
ram:01fee7 31051d bf A.0x0,$ 0x1ff06
ram:01feea af68d9 movw AX,!0xfd968
ram:01feed c1 push AX
ram:01feee 8a16 mov A,[DE + 0x16]
ram:01fef0 318e shrw AX,0x8
ram:01fef2 fc160101 call !!0x10116
ram:01fef6 c5 push DE
ram:01fef7 c3 push BC
ram:01fef8 d967d9 mov X,!0xfd967
ram:01fefb f1 clrb A
ram:01fefc c1 push AX
ram:01fefd ac10 movw AX,[HL + 0x10]
ram:01feff fc40f600 call !!0xf640
ram:01ff03 1008 addw SP,0x8
ram:01ff05 ef1e br $ 0x1ff25
ram:01ff07 af68d9 movw AX,!0xfd968
ram:01ff0a c1 push AX
ram:01ff0b ebc8e9 movw DE,!0xfe9c8
ram:01ff0e 8a16 mov A,[DE + 0x16]
ram:01ff10 318e shrw AX,0x8
ram:01ff12 fc160101 call !!0x10116
ram:01ff16 c5 push DE
ram:01ff17 c3 push BC
ram:01ff18 d967d9 mov X,!0xfd967
ram:01ff1b f1 clrb A
ram:01ff1c c1 push AX
ram:01ff1d ac10 movw AX,[HL + 0x10]
ram:01ff1f fcfdf500 call !!0xf5fd
ram:01ff23 1008 addw SP,0x8
ram:01ff25 ac10 movw AX,[HL + 0x10]
ram:01ff27 14 movw DE,AX
ram:01ff28 300500 movw AX,0x5
ram:01ff2b ba04 movw [DE + 0x4],AX
ram:01ff2d ee6202 br $! 0x20192
ram:01ff30 ebc8e9 movw DE,!0xfe9c8
ram:01ff33 aa0a movw AX,[DE + 0xa]
ram:01ff35 442800 cmpw AX,0x28
ram:01ff38 71fe or1 CY,A.0x7
ram:01ff3a de64 bnc $ 0x1ffa0
ram:01ff3c e6 onew AX
ram:01ff3d fc0b0301 call !!0x1030b
ram:01ff41 af08e4 movw AX,!0xfe408
ram:01ff44 f7 clrw BC
ram:01ff45 c3 push BC
ram:01ff46 14 movw DE,AX
ram:01ff47 8a0e mov A,[DE + 0xe]
ram:01ff49 9efc mov CS,A
ram:01ff4b aa0c movw AX,[DE + 0xc]
ram:01ff4d 14 movw DE,AX
ram:01ff4e 300500 movw AX,0x5
ram:01ff51 61ea call DE
ram:01ff53 c0 pop AX
ram:01ff54 ebc8e9 movw DE,!0xfe9c8
ram:01ff57 89 mov A,[DE]
ram:01ff58 31051d bf A.0x0,$ 0x1ff77
ram:01ff5b af68d9 movw AX,!0xfd968
ram:01ff5e c1 push AX
ram:01ff5f 8a16 mov A,[DE + 0x16]
ram:01ff61 318e shrw AX,0x8
ram:01ff63 fc160101 call !!0x10116
ram:01ff67 c5 push DE
ram:01ff68 c3 push BC
ram:01ff69 d967d9 mov X,!0xfd967
ram:01ff6c f1 clrb A
ram:01ff6d c1 push AX
ram:01ff6e ac10 movw AX,[HL + 0x10]
ram:01ff70 fc40f600 call !!0xf640
ram:01ff74 1008 addw SP,0x8
ram:01ff76 ef1e br $ 0x1ff96
ram:01ff78 af68d9 movw AX,!0xfd968
ram:01ff7b c1 push AX
ram:01ff7c ebc8e9 movw DE,!0xfe9c8
ram:01ff7f 8a16 mov A,[DE + 0x16]
ram:01ff81 318e shrw AX,0x8
ram:01ff83 fc160101 call !!0x10116
ram:01ff87 c5 push DE
ram:01ff88 c3 push BC
ram:01ff89 d967d9 mov X,!0xfd967
ram:01ff8c f1 clrb A
ram:01ff8d c1 push AX
ram:01ff8e ac10 movw AX,[HL + 0x10]
ram:01ff90 fcfdf500 call !!0xf5fd
ram:01ff94 1008 addw SP,0x8
ram:01ff96 ac10 movw AX,[HL + 0x10]
ram:01ff98 14 movw DE,AX
ram:01ff99 300500 movw AX,0x5
ram:01ff9c ba04 movw [DE + 0x4],AX
ram:01ff9e ef0f br $ 0x1ffaf
ram:01ffa0 ebc8e9 movw DE,!0xfe9c8
ram:01ffa3 aa14 movw AX,[DE + 0x14]
ram:01ffa5 14 movw DE,AX
ram:01ffa6 ca0000 mov [DE + 0x0],0x0
ram:01ffa9 ac10 movw AX,[HL + 0x10]
ram:01ffab 14 movw DE,AX
ram:01ffac e6 onew AX
ram:01ffad ba04 movw [DE + 0x4],AX
ram:01ffaf eee001 br $! 0x20192
ram:01ffb2 ebc8e9 movw DE,!0xfe9c8
ram:01ffb5 89 mov A,[DE]
ram:01ffb6 310309 bt A.0x0,$ 0x1ffc1
ram:01ffb9 8c0d mov A,[HL + 0xd]
ram:01ffbb 4c02 cmp A,#0x2
ram:01ffbd 61f8 sknz
ram:01ffbf eeae00 _br $! 0x20070
ram:01ffc2 ebc8e9 movw DE,!0xfe9c8
ram:01ffc5 8a16 mov A,[DE + 0x16]
ram:01ffc7 318e shrw AX,0x8
ram:01ffc9 fc160101 call !!0x10116
ram:01ffcd c5 push DE
ram:01ffce c3 push BC
ram:01ffcf d967d9 mov X,!0xfd967
ram:01ffd2 f1 clrb A
ram:01ffd3 c1 push AX
ram:01ffd4 ac10 movw AX,[HL + 0x10]
ram:01ffd6 fc56f400 call !!0xf456
ram:01ffda 1006 addw SP,0x6
ram:01ffdc ac10 movw AX,[HL + 0x10]
ram:01ffde 14 movw DE,AX
ram:01ffdf 300600 movw AX,0x6
ram:01ffe2 ba04 movw [DE + 0x4],AX
ram:01ffe4 af08e4 movw AX,!0xfe408
ram:01ffe7 f7 clrw BC
ram:01ffe8 c3 push BC
ram:01ffe9 14 movw DE,AX
ram:01ffea 8a0e mov A,[DE + 0xe]
ram:01ffec 9efc mov CS,A
ram:01ffee aa0c movw AX,[DE + 0xc]
ram:01fff0 14 movw DE,AX
ram:01fff1 300300 movw AX,0x3
ram:01fff4 61ea call DE
ram:01fff6 c0 pop AX
ram:01fff7 8c0d mov A,[HL + 0xd]
ram:01fff9 4c02 cmp A,#0x2
ram:01fffb df0b bnz $ 0x20008
ram:01fffd ebc8e9 movw DE,!0xfe9c8
ram:020000 8a03 mov A,[DE + 0x3]
ram:020002 6c10 or A,#0x10
ram:020004 9a03 mov [DE + 0x3],A
ram:020006 ef09 br $ 0x20011
ram:020008 ebc8e9 movw DE,!0xfe9c8
ram:02000b 8a03 mov A,[DE + 0x3]
ram:02000d 5cef and A,#0xef
ram:02000f 9a03 mov [DE + 0x3],A
ram:020011 8f71d9 mov A,!0xfd971
ram:020014 31355f bf A.0x3,$ 0x20075
ram:020017 c7 push HL
ram:020018 17 movw AX,HL
ram:020019 040500 addw AX,0x5
ram:02001c 16 movw HL,AX
ram:02001d f7 clrw BC
ram:02001e 49c05e mov A,!0xf5ec0[BC]
ram:020021 9b mov [HL],A
ram:020022 a3 incw BC
ram:020023 a7 incw HL
ram:020024 5108 mov ,0x8
ram:020026 614a cmp A,
ram:020028 dff4 bnz $ 0x2001e
ram:02002a c6 pop HL
ram:02002b cc0500 mov [HL + 0x5],0x0
ram:02002e af6ad9 movw AX,!0xfd96a
ram:020031 db6cd9 movw BC,!0xfd96c
ram:020034 fc350101 call !!0x10135
ram:020038 62 mov A,
ram:020039 9c06 mov [HL + 0x6],A
ram:02003b ebc8e9 movw DE,!0xfe9c8
ram:02003e 8a0a mov A,[DE + 0xa]
ram:020040 9c07 mov [HL + 0x7],A
ram:020042 8a16 mov A,[DE + 0x16]
ram:020044 9c08 mov [HL + 0x8],A
ram:020046 aa14 movw AX,[DE + 0x14]
ram:020048 14 movw DE,AX
ram:020049 89 mov A,[DE]
ram:02004a 9c09 mov [HL + 0x9],A
ram:02004c ebc8e9 movw DE,!0xfe9c8
ram:02004f 8a03 mov A,[DE + 0x3]
ram:020051 3139 shl A,0x3
ram:020053 317a shr A,0x7
ram:020055 9c0a mov [HL + 0xa],A
ram:020057 db02e4 movw BC,!0xfe402
ram:02005a 17 movw AX,HL
ram:02005b 040500 addw AX,0x5
ram:02005e c1 push AX
ram:02005f 491a00 mov A,!0xf001a[BC]
ram:020062 9efc mov CS,A
ram:020064 791800 movw AX,!0xf0018[BC]
ram:020067 14 movw DE,AX
ram:020068 305a00 movw AX,0x5a
ram:02006b 61ea call DE
ram:02006d c0 pop AX
ram:02006e ef06 br $ 0x20076
ram:020070 ac10 movw AX,[HL + 0x10]
ram:020072 14 movw DE,AX
ram:020073 e6 onew AX
ram:020074 ba04 movw [DE + 0x4],AX
ram:020076 ee1901 br $! 0x20192
ram:020079 ebc8e9 movw DE,!0xfe9c8
ram:02007c aa14 movw AX,[DE + 0x14]
ram:02007e 14 movw DE,AX
ram:02007f ca0000 mov [DE + 0x0],0x0
ram:020082 ac10 movw AX,[HL + 0x10]
ram:020084 14 movw DE,AX
ram:020085 e6 onew AX
ram:020086 ba04 movw [DE + 0x4],AX
ram:020088 ee0701 br $! 0x20192
ram:02008b 8f71d9 mov A,!0xfd971
ram:02008e 311303 bt A.0x1,$ 0x20093
ram:020091 ee9400 br $! 0x20128
ram:020094 ebc8e9 movw DE,!0xfe9c8
ram:020097 8a16 mov A,[DE + 0x16]
ram:020099 318e shrw AX,0x8
ram:02009b fc160101 call !!0x10116
ram:02009f c5 push DE
ram:0200a0 c3 push BC
ram:0200a1 d967d9 mov X,!0xfd967
ram:0200a4 f1 clrb A
ram:0200a5 c1 push AX
ram:0200a6 ac10 movw AX,[HL + 0x10]
ram:0200a8 fc56f400 call !!0xf456
ram:0200ac 1006 addw SP,0x6
ram:0200ae ac10 movw AX,[HL + 0x10]
ram:0200b0 14 movw DE,AX
ram:0200b1 300600 movw AX,0x6
ram:0200b4 ba04 movw [DE + 0x4],AX
ram:0200b6 af08e4 movw AX,!0xfe408
ram:0200b9 f7 clrw BC
ram:0200ba c3 push BC
ram:0200bb 14 movw DE,AX
ram:0200bc 8a0e mov A,[DE + 0xe]
ram:0200be 9efc mov CS,A
ram:0200c0 aa0c movw AX,[DE + 0xc]
ram:0200c2 14 movw DE,AX
ram:0200c3 300300 movw AX,0x3
ram:0200c6 61ea call DE
ram:0200c8 c0 pop AX
ram:0200c9 8f71d9 mov A,!0xfd971
ram:0200cc 313557 bf A.0x3,$ 0x20125
ram:0200cf c7 push HL
ram:0200d0 17 movw AX,HL
ram:0200d1 040500 addw AX,0x5
ram:0200d4 16 movw HL,AX
ram:0200d5 f7 clrw BC
ram:0200d6 49c85e mov A,!0xf5ec8[BC]
ram:0200d9 9b mov [HL],A
ram:0200da a3 incw BC
ram:0200db a7 incw HL
ram:0200dc 5108 mov ,0x8
ram:0200de 614a cmp A,
ram:0200e0 dff4 bnz $ 0x200d6
ram:0200e2 c6 pop HL
ram:0200e3 cc0505 mov [HL + 0x5],0x5
ram:0200e6 af6ad9 movw AX,!0xfd96a
ram:0200e9 db6cd9 movw BC,!0xfd96c
ram:0200ec fc350101 call !!0x10135
ram:0200f0 62 mov A,
ram:0200f1 9c06 mov [HL + 0x6],A
ram:0200f3 ebc8e9 movw DE,!0xfe9c8
ram:0200f6 8a0a mov A,[DE + 0xa]
ram:0200f8 9c07 mov [HL + 0x7],A
ram:0200fa 8a16 mov A,[DE + 0x16]
ram:0200fc 9c08 mov [HL + 0x8],A
ram:0200fe aa14 movw AX,[DE + 0x14]
ram:020100 14 movw DE,AX
ram:020101 89 mov A,[DE]
ram:020102 9c09 mov [HL + 0x9],A
ram:020104 ebc8e9 movw DE,!0xfe9c8
ram:020107 8a03 mov A,[DE + 0x3]
ram:020109 3139 shl A,0x3
ram:02010b 317a shr A,0x7
ram:02010d 9c0a mov [HL + 0xa],A
ram:02010f db02e4 movw BC,!0xfe402
ram:020112 17 movw AX,HL
ram:020113 040500 addw AX,0x5
ram:020116 c1 push AX
ram:020117 491a00 mov A,!0xf001a[BC]
ram:02011a 9efc mov CS,A
ram:02011c 791800 movw AX,!0xf0018[BC]
ram:02011f 14 movw DE,AX
ram:020120 305a00 movw AX,0x5a
ram:020123 61ea call DE
ram:020125 c0 pop AX
ram:020126 ef6a br $ 0x20192
ram:020128 e6 onew AX
ram:020129 fc0b0301 call !!0x1030b
ram:02012d af08e4 movw AX,!0xfe408
ram:020130 f7 clrw BC
ram:020131 c3 push BC
ram:020132 14 movw DE,AX
ram:020133 8a0e mov A,[DE + 0xe]
ram:020135 9efc mov CS,A
ram:020137 aa0c movw AX,[DE + 0xc]
ram:020139 14 movw DE,AX
ram:02013a 300500 movw AX,0x5
ram:02013d 61ea call DE
ram:02013f c0 pop AX
ram:020140 ebc8e9 movw DE,!0xfe9c8
ram:020143 89 mov A,[DE]
ram:020144 31051d bf A.0x0,$ 0x20163
ram:020147 af68d9 movw AX,!0xfd968
ram:02014a c1 push AX
ram:02014b 8a16 mov A,[DE + 0x16]
ram:02014d 318e shrw AX,0x8
ram:02014f fc160101 call !!0x10116
ram:020153 c5 push DE
ram:020154 c3 push BC
ram:020155 d967d9 mov X,!0xfd967
ram:020158 f1 clrb A
ram:020159 c1 push AX
ram:02015a ac10 movw AX,[HL + 0x10]
ram:02015c fc40f600 call !!0xf640
ram:020160 1008 addw SP,0x8
ram:020162 ef1e br $ 0x20182
ram:020164 af68d9 movw AX,!0xfd968
ram:020167 c1 push AX
ram:020168 ebc8e9 movw DE,!0xfe9c8
ram:02016b 8a16 mov A,[DE + 0x16]
ram:02016d 318e shrw AX,0x8
ram:02016f fc160101 call !!0x10116
ram:020173 c5 push DE
ram:020174 c3 push BC
ram:020175 d967d9 mov X,!0xfd967
ram:020178 f1 clrb A
ram:020179 c1 push AX
ram:02017a ac10 movw AX,[HL + 0x10]
ram:02017c fcfdf500 call !!0xf5fd
ram:020180 1008 addw SP,0x8
ram:020182 ac10 movw AX,[HL + 0x10]
ram:020184 14 movw DE,AX
ram:020185 300500 movw AX,0x5
ram:020188 ba04 movw [DE + 0x4],AX
ram:02018a ef06 br $ 0x20192
ram:02018c ac10 movw AX,[HL + 0x10]
ram:02018e 14 movw DE,AX
ram:02018f e6 onew AX
ram:020190 ba04 movw [DE + 0x4],AX
ram:020192 ee8203 br $! 0x20517
ram:020195 fc83f600 call !!0xf683
ram:020199 92 dec 
ram:02019a 61e8 skz
ram:02019c ee9e00 _br $! 0x2023d
ram:02019f 17 movw AX,HL
ram:0201a0 040c00 addw AX,0xc
ram:0201a3 fc8af600 call !!0xf68a
ram:0201a7 ac0c movw AX,[HL + 0xc]
ram:0201a9 4268d9 cmpw AX,!0xfd968
ram:0201ac dd0b bz $ 0x201b9
ram:0201ae ebc8e9 movw DE,!0xfe9c8
ram:0201b1 8a03 mov A,[DE + 0x3]
ram:0201b3 6c10 or A,#0x10
ram:0201b5 9a03 mov [DE + 0x3],A
ram:0201b7 ef09 br $ 0x201c2
ram:0201b9 ebc8e9 movw DE,!0xfe9c8
ram:0201bc 8a03 mov A,[DE + 0x3]
ram:0201be 5cef and A,#0xef
ram:0201c0 9a03 mov [DE + 0x3],A
ram:0201c2 ac10 movw AX,[HL + 0x10]
ram:0201c4 14 movw DE,AX
ram:0201c5 300600 movw AX,0x6
ram:0201c8 ba04 movw [DE + 0x4],AX
ram:0201ca af08e4 movw AX,!0xfe408
ram:0201cd f7 clrw BC
ram:0201ce c3 push BC
ram:0201cf 14 movw DE,AX
ram:0201d0 8a0e mov A,[DE + 0xe]
ram:0201d2 9efc mov CS,A
ram:0201d4 aa0c movw AX,[DE + 0xc]
ram:0201d6 14 movw DE,AX
ram:0201d7 300300 movw AX,0x3
ram:0201da 61ea call DE
ram:0201dc c0 pop AX
ram:0201dd 8f71d9 mov A,!0xfd971
ram:0201e0 313557 bf A.0x3,$ 0x20239
ram:0201e3 c7 push HL
ram:0201e4 17 movw AX,HL
ram:0201e5 040400 addw AX,0x4
ram:0201e8 16 movw HL,AX
ram:0201e9 f7 clrw BC
ram:0201ea 49d05e mov A,!0xf5ed0[BC]
ram:0201ed 9b mov [HL],A
ram:0201ee a3 incw BC
ram:0201ef a7 incw HL
ram:0201f0 5108 mov ,0x8
ram:0201f2 614a cmp A,
ram:0201f4 dff4 bnz $ 0x201ea
ram:0201f6 c6 pop HL
ram:0201f7 cc0401 mov [HL + 0x4],0x1
ram:0201fa af6ad9 movw AX,!0xfd96a
ram:0201fd db6cd9 movw BC,!0xfd96c
ram:020200 fc350101 call !!0x10135
ram:020204 62 mov A,
ram:020205 9c05 mov [HL + 0x5],A
ram:020207 ebc8e9 movw DE,!0xfe9c8
ram:02020a 8a0a mov A,[DE + 0xa]
ram:02020c 9c06 mov [HL + 0x6],A
ram:02020e 8a16 mov A,[DE + 0x16]
ram:020210 9c07 mov [HL + 0x7],A
ram:020212 aa14 movw AX,[DE + 0x14]
ram:020214 14 movw DE,AX
ram:020215 89 mov A,[DE]
ram:020216 9c08 mov [HL + 0x8],A
ram:020218 ebc8e9 movw DE,!0xfe9c8
ram:02021b 8a03 mov A,[DE + 0x3]
ram:02021d 3139 shl A,0x3
ram:02021f 317a shr A,0x7
ram:020221 9c09 mov [HL + 0x9],A
ram:020223 db02e4 movw BC,!0xfe402
ram:020226 17 movw AX,HL
ram:020227 040400 addw AX,0x4
ram:02022a c1 push AX
ram:02022b 491a00 mov A,!0xf001a[BC]
ram:02022e 9efc mov CS,A
ram:020230 791800 movw AX,!0xf0018[BC]
ram:020233 14 movw DE,AX
ram:020234 305a00 movw AX,0x5a
ram:020237 61ea call DE
ram:020239 c0 pop AX
ram:02023a ee6301 br $! 0x203a0
ram:02023d cc0d00 mov [HL + 0xd],0x0
ram:020240 af68d9 movw AX,!0xfd968
ram:020243 c1 push AX
ram:020244 ebc8e9 movw DE,!0xfe9c8
ram:020247 8a16 mov A,[DE + 0x16]
ram:020249 318e shrw AX,0x8
ram:02024b fcaaf001 call !!0x1f0aa
ram:02024f c0 pop AX
ram:020250 62 mov A,
ram:020251 9c0c mov [HL + 0xc],A
ram:020253 ebc8e9 movw DE,!0xfe9c8
ram:020256 aa14 movw AX,[DE + 0x14]
ram:020258 14 movw DE,AX
ram:020259 89 mov A,[DE]
ram:02025a 9c0b mov [HL + 0xb],A
ram:02025c 8c0c mov A,[HL + 0xc]
ram:02025e 91 dec 
ram:02025f dd0d bz $ 0x2026e
ram:020261 2c02 sub A,#0x2
ram:020263 dd24 bz $ 0x20289
ram:020265 91 dec 
ram:020266 dd1c bz $ 0x20284
ram:020268 2c02 sub A,#0x2
ram:02026a dd0d bz $ 0x20279
ram:02026c ef36 br $ 0x202a4
ram:02026e ebc8e9 movw DE,!0xfe9c8
ram:020271 aa14 movw AX,[DE + 0x14]
ram:020273 14 movw DE,AX
ram:020274 ca0000 mov [DE + 0x0],0x0
ram:020277 ef2b br $ 0x202a4
ram:020279 ebc8e9 movw DE,!0xfe9c8
ram:02027c aa14 movw AX,[DE + 0x14]
ram:02027e 14 movw DE,AX
ram:02027f ca0000 mov [DE + 0x0],0x0
ram:020282 ef20 br $ 0x202a4
ram:020284 cc0d01 mov [HL + 0xd],0x1
ram:020287 ef1b br $ 0x202a4
ram:020289 ebc8e9 movw DE,!0xfe9c8
ram:02028c 8a16 mov A,[DE + 0x16]
ram:02028e 318e shrw AX,0x8
ram:020290 fc7bf700 call !!0xf77b
ram:020294 302000 movw AX,0x20
ram:020297 c1 push AX
ram:020298 501e mov ,0x1e
ram:02029a c1 push AX
ram:02029b 30c4d9 movw AX,0xd9c4
ram:02029e fc40e500 call !!0xe540
ram:0202a2 1004 addw SP,0x4
ram:0202a4 8c0d mov A,[HL + 0xd]
ram:0202a6 91 dec 
ram:0202a7 df6e bnz $ 0x20317
ram:0202a9 ac10 movw AX,[HL + 0x10]
ram:0202ab 14 movw DE,AX
ram:0202ac 300600 movw AX,0x6
ram:0202af ba04 movw [DE + 0x4],AX
ram:0202b1 af08e4 movw AX,!0xfe408
ram:0202b4 f7 clrw BC
ram:0202b5 c3 push BC
ram:0202b6 14 movw DE,AX
ram:0202b7 8a0e mov A,[DE + 0xe]
ram:0202b9 9efc mov CS,A
ram:0202bb aa0c movw AX,[DE + 0xc]
ram:0202bd 14 movw DE,AX
ram:0202be 300300 movw AX,0x3
ram:0202c1 61ea call DE
ram:0202c3 c0 pop AX
ram:0202c4 8f71d9 mov A,!0xfd971
ram:0202c7 31354a bf A.0x3,$ 0x20313
ram:0202ca c7 push HL
ram:0202cb 17 movw AX,HL
ram:0202cc 040300 addw AX,0x3
ram:0202cf 16 movw HL,AX
ram:0202d0 f7 clrw BC
ram:0202d1 49d85e mov A,!0xf5ed8[BC]
ram:0202d4 9b mov [HL],A
ram:0202d5 a3 incw BC
ram:0202d6 a7 incw HL
ram:0202d7 5108 mov ,0x8
ram:0202d9 614a cmp A,
ram:0202db dff4 bnz $ 0x202d1
ram:0202dd c6 pop HL
ram:0202de cc0302 mov [HL + 0x3],0x2
ram:0202e1 af6ad9 movw AX,!0xfd96a
ram:0202e4 db6cd9 movw BC,!0xfd96c
ram:0202e7 fc350101 call !!0x10135
ram:0202eb 62 mov A,
ram:0202ec 9c04 mov [HL + 0x4],A
ram:0202ee ebc8e9 movw DE,!0xfe9c8
ram:0202f1 8a0a mov A,[DE + 0xa]
ram:0202f3 9c05 mov [HL + 0x5],A
ram:0202f5 8a16 mov A,[DE + 0x16]
ram:0202f7 9c06 mov [HL + 0x6],A
ram:0202f9 8c0b mov A,[HL + 0xb]
ram:0202fb 9c07 mov [HL + 0x7],A
ram:0202fd db02e4 movw BC,!0xfe402
ram:020300 17 movw AX,HL
ram:020301 040300 addw AX,0x3
ram:020304 c1 push AX
ram:020305 491a00 mov A,!0xf001a[BC]
ram:020308 9efc mov CS,A
ram:02030a 791800 movw AX,!0xf0018[BC]
ram:02030d 14 movw DE,AX
ram:02030e 305a00 movw AX,0x5a
ram:020311 61ea call DE
ram:020313 c0 pop AX
ram:020314 ee8900 br $! 0x203a0
ram:020317 af6cd9 movw AX,!0xfd96c
ram:02031a c1 push AX
ram:02031b af6ad9 movw AX,!0xfd96a
ram:02031e c1 push AX
ram:02031f d967d9 mov X,!0xfd967
ram:020322 f1 clrb A
ram:020323 c1 push AX
ram:020324 ac10 movw AX,[HL + 0x10]
ram:020326 fc56f400 call !!0xf456
ram:02032a 1006 addw SP,0x6
ram:02032c af08e4 movw AX,!0xfe408
ram:02032f f7 clrw BC
ram:020330 c3 push BC
ram:020331 14 movw DE,AX
ram:020332 8a0e mov A,[DE + 0xe]
ram:020334 9efc mov CS,A
ram:020336 aa0c movw AX,[DE + 0xc]
ram:020338 14 movw DE,AX
ram:020339 300600 movw AX,0x6
ram:02033c 61ea call DE
ram:02033e c0 pop AX
ram:02033f ac10 movw AX,[HL + 0x10]
ram:020341 14 movw DE,AX
ram:020342 e6 onew AX
ram:020343 ba04 movw [DE + 0x4],AX
ram:020345 8f71d9 mov A,!0xfd971
ram:020348 313555 bf A.0x3,$ 0x2039f
ram:02034b c7 push HL
ram:02034c 17 movw AX,HL
ram:02034d 040300 addw AX,0x3
ram:020350 16 movw HL,AX
ram:020351 f7 clrw BC
ram:020352 49e05e mov A,!0xf5ee0[BC]
ram:020355 9b mov [HL],A
ram:020356 a3 incw BC
ram:020357 a7 incw HL
ram:020358 5108 mov ,0x8
ram:02035a 614a cmp A,
ram:02035c dff4 bnz $ 0x20352
ram:02035e c6 pop HL
ram:02035f 8c0c mov A,[HL + 0xc]
ram:020361 4c03 cmp A,#0x3
ram:020363 df05 bnz $ 0x2036a
ram:020365 cc0304 mov [HL + 0x3],0x4
ram:020368 ef03 br $ 0x2036d
ram:02036a cc0303 mov [HL + 0x3],0x3
ram:02036d af6ad9 movw AX,!0xfd96a
ram:020370 db6cd9 movw BC,!0xfd96c
ram:020373 fc350101 call !!0x10135
ram:020377 62 mov A,
ram:020378 9c04 mov [HL + 0x4],A
ram:02037a ebc8e9 movw DE,!0xfe9c8
ram:02037d 8a0a mov A,[DE + 0xa]
ram:02037f 9c05 mov [HL + 0x5],A
ram:020381 8a16 mov A,[DE + 0x16]
ram:020383 9c06 mov [HL + 0x6],A
ram:020385 8c0b mov A,[HL + 0xb]
ram:020387 9c07 mov [HL + 0x7],A
ram:020389 db02e4 movw BC,!0xfe402
ram:02038c 17 movw AX,HL
ram:02038d 040300 addw AX,0x3
ram:020390 c1 push AX
ram:020391 491a00 mov A,!0xf001a[BC]
ram:020394 9efc mov CS,A
ram:020396 791800 movw AX,!0xf0018[BC]
ram:020399 14 movw DE,AX
ram:02039a 305a00 movw AX,0x5a
ram:02039d 61ea call DE
ram:02039f c0 pop AX
ram:0203a0 f6 clrw AX
ram:0203a1 fc0b0301 call !!0x1030b
ram:0203a5 ee6f01 br $! 0x20517
ram:0203a8 ebc8e9 movw DE,!0xfe9c8
ram:0203ab 8a03 mov A,[DE + 0x3]
ram:0203ad 315510 bf A.0x5,$ 0x203bf
ram:0203b0 af6ad9 movw AX,!0xfd96a
ram:0203b3 db6cd9 movw BC,!0xfd96c
ram:0203b6 fc350101 call !!0x10135
ram:0203ba f3 clrb B
ram:0203bb 13 movw AX,BC
ram:0203bc fc7bf700 call !!0xf77b
ram:0203c0 ebc8e9 movw DE,!0xfe9c8
ram:0203c3 8a16 mov A,[DE + 0x16]
ram:0203c5 318e shrw AX,0x8
ram:0203c7 fc160101 call !!0x10116
ram:0203cb 13 movw AX,BC
ram:0203cc bf6ad9 movw !0xfd96a,AX
ram:0203cf 15 movw AX,DE
ram:0203d0 bf6cd9 movw !0xfd96c,AX
ram:0203d3 ebc8e9 movw DE,!0xfe9c8
ram:0203d6 8a03 mov A,[DE + 0x3]
ram:0203d8 314303 bt A.0x4,$ 0x203dd
ram:0203db ee9000 br $! 0x2046e
ram:0203de 8a16 mov A,[DE + 0x16]
ram:0203e0 318e shrw AX,0x8
ram:0203e2 fccdf201 call !!0x1f2cd
ram:0203e6 13 movw AX,BC
ram:0203e7 bc08 movw [HL + 0x8],AX
ram:0203e9 af08e4 movw AX,!0xfe408
ram:0203ec f7 clrw BC
ram:0203ed c3 push BC
ram:0203ee 14 movw DE,AX
ram:0203ef 8a0e mov A,[DE + 0xe]
ram:0203f1 9efc mov CS,A
ram:0203f3 aa0c movw AX,[DE + 0xc]
ram:0203f5 14 movw DE,AX
ram:0203f6 300400 movw AX,0x4
ram:0203f9 61ea call DE
ram:0203fb c0 pop AX
ram:0203fc fc5b0101 call !!0x1015b
ram:020400 ac08 movw AX,[HL + 0x8]
ram:020402 bc0a movw [HL + 0xa],AX
ram:020404 ebc8e9 movw DE,!0xfe9c8
ram:020407 8a16 mov A,[DE + 0x16]
ram:020409 318e shrw AX,0x8
ram:02040b bc0c movw [HL + 0xc],AX
ram:02040d db02e4 movw BC,!0xfe402
ram:020410 17 movw AX,HL
ram:020411 040a00 addw AX,0xa
ram:020414 c1 push AX
ram:020415 491a00 mov A,!0xf001a[BC]
ram:020418 9efc mov CS,A
ram:02041a 791800 movw AX,!0xf0018[BC]
ram:02041d 14 movw DE,AX
ram:02041e 304600 movw AX,0x46
ram:020421 61ea call DE
ram:020423 c0 pop AX
ram:020424 fc18ef01 call !!0x1ef18
ram:020428 ac08 movw AX,[HL + 0x8]
ram:02042a bf68d9 movw !0xfd968,AX
ram:02042d afc8e9 movw AX,!0xfe9c8
ram:020430 f7 clrw BC
ram:020431 c3 push BC
ram:020432 14 movw DE,AX
ram:020433 8a1a mov A,[DE + 0x1a]
ram:020435 9efc mov CS,A
ram:020437 aa18 movw AX,[DE + 0x18]
ram:020439 14 movw DE,AX
ram:02043a e6 onew AX
ram:02043b 61ea call DE
ram:02043d c0 pop AX
ram:02043e ebc8e9 movw DE,!0xfe9c8
ram:020441 8a16 mov A,[DE + 0x16]
ram:020443 318e shrw AX,0x8
ram:020445 fc47f301 call !!0x1f347
ram:020449 af08e4 movw AX,!0xfe408
ram:02044c f7 clrw BC
ram:02044d c3 push BC
ram:02044e 14 movw DE,AX
ram:02044f 8a0e mov A,[DE + 0xe]
ram:020451 9efc mov CS,A
ram:020453 aa0c movw AX,[DE + 0xc]
ram:020455 14 movw DE,AX
ram:020456 e6 onew AX
ram:020457 a1 incw AX
ram:020458 61ea call DE
ram:02045a c0 pop AX
ram:02045b fc010902 call !!0x20901
ram:02045f db6cd9 movw BC,!0xfd96c
ram:020462 af6ad9 movw AX,!0xfd96a
ram:020465 bfe6d9 movw !0xfd9e6,AX
ram:020468 33 xchw AX,BC
ram:020469 bfe8d9 movw !0xfd9e8,AX
ram:02046c ef7b br $ 0x204e9
ram:02046e ebc8e9 movw DE,!0xfe9c8
ram:020471 8a16 mov A,[DE + 0x16]
ram:020473 9c0d mov [HL + 0xd],A
ram:020475 db02e4 movw BC,!0xfe402
ram:020478 17 movw AX,HL
ram:020479 040d00 addw AX,0xd
ram:02047c c1 push AX
ram:02047d 491a00 mov A,!0xf001a[BC]
ram:020480 9efc mov CS,A
ram:020482 791800 movw AX,!0xf0018[BC]
ram:020485 14 movw DE,AX
ram:020486 304500 movw AX,0x45
ram:020489 61ea call DE
ram:02048b c0 pop AX
ram:02048c 8c0d mov A,[HL + 0xd]
ram:02048e 318e shrw AX,0x8
ram:020490 fcf9f600 call !!0xf6f9
ram:020494 8c0d mov A,[HL + 0xd]
ram:020496 318e shrw AX,0x8
ram:020498 fc47f301 call !!0x1f347
ram:02049c afc8e9 movw AX,!0xfe9c8
ram:02049f e7 onew BC
ram:0204a0 c3 push BC
ram:0204a1 14 movw DE,AX
ram:0204a2 8a1a mov A,[DE + 0x1a]
ram:0204a4 9efc mov CS,A
ram:0204a6 aa18 movw AX,[DE + 0x18]
ram:0204a8 14 movw DE,AX
ram:0204a9 e6 onew AX
ram:0204aa 61ea call DE
ram:0204ac c0 pop AX
ram:0204ad ac10 movw AX,[HL + 0x10]
ram:0204af 14 movw DE,AX
ram:0204b0 f6 clrw AX
ram:0204b1 ba04 movw [DE + 0x4],AX
ram:0204b3 5020 mov ,0x20
ram:0204b5 c1 push AX
ram:0204b6 501e mov ,0x1e
ram:0204b8 c1 push AX
ram:0204b9 30c4d9 movw AX,0xd9c4
ram:0204bc fc40e500 call !!0xe540
ram:0204c0 1004 addw SP,0x4
ram:0204c2 ebc8e9 movw DE,!0xfe9c8
ram:0204c5 8a03 mov A,[DE + 0x3]
ram:0204c7 5cdf and A,#0xdf
ram:0204c9 9a03 mov [DE + 0x3],A
ram:0204cb ebc8e9 movw DE,!0xfe9c8
ram:0204ce 8a03 mov A,[DE + 0x3]
ram:0204d0 5cf0 and A,#0xf0
ram:0204d2 6c07 or A,#0x7
ram:0204d4 9a03 mov [DE + 0x3],A
ram:0204d6 ebc8e9 movw DE,!0xfe9c8
ram:0204d9 8a01 mov A,[DE + 0x1]
ram:0204db 5cc0 and A,#0xc0
ram:0204dd 9a01 mov [DE + 0x1],A
ram:0204df 711871d9 clr1 !0xfd971.0x1
ram:0204e3 ebc8e9 movw DE,!0xfe9c8
ram:0204e6 ca1c19 mov [DE + 0x1c],0x19
ram:0204e9 db08e4 movw BC,!0xfe408
ram:0204ec ac0e movw AX,[HL + 0xe]
ram:0204ee 14 movw DE,AX
ram:0204ef 8a02 mov A,[DE + 0x2]
ram:0204f1 318e shrw AX,0x8
ram:0204f3 c1 push AX
ram:0204f4 ac0e movw AX,[HL + 0xe]
ram:0204f6 040300 addw AX,0x3
ram:0204f9 c1 push AX
ram:0204fa 491200 mov A,!0xf0012[BC]
ram:0204fd 9dd4 mov 0xffdf4,A
ram:0204ff 791000 movw AX,!0xf0010[BC]
ram:020502 c1 push AX
ram:020503 8dd4 mov A,0xffdf4
ram:020505 9dd6 mov 0xffdf6,A
ram:020507 c0 pop AX
ram:020508 14 movw DE,AX
ram:020509 301300 movw AX,0x13
ram:02050c f7 clrw BC
ram:02050d c1 push AX
ram:02050e 8dd6 mov A,0xffdf6
ram:020510 9efc mov CS,A
ram:020512 c0 pop AX
ram:020513 61ea call DE
ram:020515 1004 addw SP,0x4
ram:020517 e7 onew BC
ram:020518 1012 addw SP,0x12
ram:02051a c6 pop HL
ram:02051b d7 ret
ram:02051c c7 push HL
ram:02051d 2004 subw SP,0x4
ram:02051f fbf8ff movw HL,!0xffff8
ram:020522 4067d904 cmp !0xfd967,0x4
ram:020526 61e8 skz
ram:020528 eeb100 _br $! 0x205dc
ram:02052b 8f70d9 mov A,!0xfd970
ram:02052e 314303 bt A.0x4,$ 0x20533
ram:020531 eea800 br $! 0x205dc
ram:020534 e6 onew AX
ram:020535 426cd9 cmpw AX,!0xfd96c
ram:020538 df06 bnz $ 0x20540
ram:02053a 30ac9d movw AX,0x9dac
ram:02053d 426ad9 cmpw AX,!0xfd96a
ram:020540 dd0e bz $ 0x20550
ram:020542 e6 onew AX
ram:020543 426cd9 cmpw AX,!0xfd96c
ram:020546 df06 bnz $ 0x2054e
ram:020548 308858 movw AX,0x5888
ram:02054b 426ad9 cmpw AX,!0xfd96a
ram:02054e df46 bnz $ 0x20596
ram:020550 8f70d9 mov A,!0xfd970
ram:020553 31533e bt A.0x5,$ 0x20593
ram:020556 c7 push HL
ram:020557 17 movw AX,HL
ram:020558 a1 incw AX
ram:020559 16 movw HL,AX
ram:02055a f7 clrw BC
ram:02055b 49e85e mov A,!0xf5ee8[BC]
ram:02055e 9b mov [HL],A
ram:02055f a3 incw BC
ram:020560 a7 incw HL
ram:020561 5103 mov ,0x3
ram:020563 614a cmp A,
ram:020565 dff4 bnz $ 0x2055b
ram:020567 c6 pop HL
ram:020568 af04e4 movw AX,!0xfe404
ram:02056b 320300 movw BC,0x3
ram:02056e c3 push BC
ram:02056f 12 movw BC,AX
ram:020570 17 movw AX,HL
ram:020571 a1 incw AX
ram:020572 c1 push AX
ram:020573 491200 mov A,!0xf0012[BC]
ram:020576 9dd4 mov 0xffdf4,A
ram:020578 791000 movw AX,!0xf0010[BC]
ram:02057b c1 push AX
ram:02057c 8dd4 mov A,0xffdf4
ram:02057e 9dd6 mov 0xffdf6,A
ram:020580 c0 pop AX
ram:020581 14 movw DE,AX
ram:020582 302203 movw AX,0x322
ram:020585 e7 onew BC
ram:020586 c1 push AX
ram:020587 8dd6 mov A,0xffdf6
ram:020589 9efc mov CS,A
ram:02058b c0 pop AX
ram:02058c 61ea call DE
ram:02058e 1004 addw SP,0x4
ram:020590 715070d9 set1 !0xfd970.0x5
ram:020594 ef44 br $ 0x205da
ram:020596 8f70d9 mov A,!0xfd970
ram:020599 31553e bf A.0x5,$ 0x205d9
ram:02059c c7 push HL
ram:02059d 17 movw AX,HL
ram:02059e a1 incw AX
ram:02059f 16 movw HL,AX
ram:0205a0 f7 clrw BC
ram:0205a1 49ec5e mov A,!0xf5eec[BC]
ram:0205a4 9b mov [HL],A
ram:0205a5 a3 incw BC
ram:0205a6 a7 incw HL
ram:0205a7 5103 mov ,0x3
ram:0205a9 614a cmp A,
ram:0205ab dff4 bnz $ 0x205a1
ram:0205ad c6 pop HL
ram:0205ae af04e4 movw AX,!0xfe404
ram:0205b1 320300 movw BC,0x3
ram:0205b4 c3 push BC
ram:0205b5 12 movw BC,AX
ram:0205b6 17 movw AX,HL
ram:0205b7 a1 incw AX
ram:0205b8 c1 push AX
ram:0205b9 491200 mov A,!0xf0012[BC]
ram:0205bc 9dd4 mov 0xffdf4,A
ram:0205be 791000 movw AX,!0xf0010[BC]
ram:0205c1 c1 push AX
ram:0205c2 8dd4 mov A,0xffdf4
ram:0205c4 9dd6 mov 0xffdf6,A
ram:0205c6 c0 pop AX
ram:0205c7 14 movw DE,AX
ram:0205c8 302203 movw AX,0x322
ram:0205cb e7 onew BC
ram:0205cc c1 push AX
ram:0205cd 8dd6 mov A,0xffdf6
ram:0205cf 9efc mov CS,A
ram:0205d1 c0 pop AX
ram:0205d2 61ea call DE
ram:0205d4 1004 addw SP,0x4
ram:0205d6 715870d9 clr1 !0xfd970.0x5
ram:0205da ef44 br $ 0x20620
ram:0205dc 8f70d9 mov A,!0xfd970
ram:0205df 31553e bf A.0x5,$ 0x2061f
ram:0205e2 c7 push HL
ram:0205e3 17 movw AX,HL
ram:0205e4 a1 incw AX
ram:0205e5 16 movw HL,AX
ram:0205e6 f7 clrw BC
ram:0205e7 49f05e mov A,!0xf5ef0[BC]
ram:0205ea 9b mov [HL],A
ram:0205eb a3 incw BC
ram:0205ec a7 incw HL
ram:0205ed 5103 mov ,0x3
ram:0205ef 614a cmp A,
ram:0205f1 dff4 bnz $ 0x205e7
ram:0205f3 c6 pop HL
ram:0205f4 af04e4 movw AX,!0xfe404
ram:0205f7 320300 movw BC,0x3
ram:0205fa c3 push BC
ram:0205fb 12 movw BC,AX
ram:0205fc 17 movw AX,HL
ram:0205fd a1 incw AX
ram:0205fe c1 push AX
ram:0205ff 491200 mov A,!0xf0012[BC]
ram:020602 9dd4 mov 0xffdf4,A
ram:020604 791000 movw AX,!0xf0010[BC]
ram:020607 c1 push AX
ram:020608 8dd4 mov A,0xffdf4
ram:02060a 9dd6 mov 0xffdf6,A
ram:02060c c0 pop AX
ram:02060d 14 movw DE,AX
ram:02060e 302203 movw AX,0x322
ram:020611 e7 onew BC
ram:020612 c1 push AX
ram:020613 8dd6 mov A,0xffdf6
ram:020615 9efc mov CS,A
ram:020617 c0 pop AX
ram:020618 61ea call DE
ram:02061a 1004 addw SP,0x4
ram:02061c 715870d9 clr1 !0xfd970.0x5
ram:020620 1004 addw SP,0x4
ram:020622 c6 pop HL
ram:020623 d7 ret
ram:020624 c7 push HL
ram:020625 c1 push AX
ram:020626 fbf8ff movw HL,!0xffff8
ram:020629 4067d904 cmp !0xfd967,0x4
ram:02062d 61e8 skz
ram:02062f eeaf00 _br $! 0x206e1
ram:020632 8f70d9 mov A,!0xfd970
ram:020635 312303 bt A.0x2,$ 0x2063a
ram:020638 eea600 br $! 0x206e1
ram:02063b e6 onew AX
ram:02063c 426cd9 cmpw AX,!0xfd96c
ram:02063f df06 bnz $ 0x20647
ram:020641 30ec8a movw AX,0x8aec
ram:020644 426ad9 cmpw AX,!0xfd96a
ram:020647 dd0e bz $ 0x20657
ram:020649 e6 onew AX
ram:02064a 426cd9 cmpw AX,!0xfd96c
ram:02064d df06 bnz $ 0x20655
ram:02064f 303466 movw AX,0x6634
ram:020652 426ad9 cmpw AX,!0xfd96a
ram:020655 df45 bnz $ 0x2069c
ram:020657 8f70d9 mov A,!0xfd970
ram:02065a 31333d bt A.0x3,$ 0x20699
ram:02065d c7 push HL
ram:02065e 17 movw AX,HL
ram:02065f 16 movw HL,AX
ram:020660 f7 clrw BC
ram:020661 49f45e mov A,!0xf5ef4[BC]
ram:020664 9b mov [HL],A
ram:020665 a3 incw BC
ram:020666 a7 incw HL
ram:020667 5102 mov ,0x2
ram:020669 614a cmp A,
ram:02066b dff4 bnz $ 0x20661
ram:02066d c6 pop HL
ram:02066e af04e4 movw AX,!0xfe404
ram:020671 e7 onew BC
ram:020672 a3 incw BC
ram:020673 c3 push BC
ram:020674 12 movw BC,AX
ram:020675 17 movw AX,HL
ram:020676 c1 push AX
ram:020677 491200 mov A,!0xf0012[BC]
ram:02067a 9dd4 mov 0xffdf4,A
ram:02067c 791000 movw AX,!0xf0010[BC]
ram:02067f c1 push AX
ram:020680 8dd4 mov A,0xffdf4
ram:020682 9dd6 mov 0xffdf6,A
ram:020684 c0 pop AX
ram:020685 14 movw DE,AX
ram:020686 30a012 movw AX,0x12a0
ram:020689 320300 movw BC,0x3
ram:02068c c1 push AX
ram:02068d 8dd6 mov A,0xffdf6
ram:02068f 9efc mov CS,A
ram:020691 c0 pop AX
ram:020692 61ea call DE
ram:020694 1004 addw SP,0x4
ram:020696 713070d9 set1 !0xfd970.0x3
ram:02069a ef43 br $ 0x206df
ram:02069c 8f70d9 mov A,!0xfd970
ram:02069f 31353d bf A.0x3,$ 0x206de
ram:0206a2 c7 push HL
ram:0206a3 17 movw AX,HL
ram:0206a4 16 movw HL,AX
ram:0206a5 f7 clrw BC
ram:0206a6 49f65e mov A,!0xf5ef6[BC]
ram:0206a9 9b mov [HL],A
ram:0206aa a3 incw BC
ram:0206ab a7 incw HL
ram:0206ac 5102 mov ,0x2
ram:0206ae 614a cmp A,
ram:0206b0 dff4 bnz $ 0x206a6
ram:0206b2 c6 pop HL
ram:0206b3 af04e4 movw AX,!0xfe404
ram:0206b6 e7 onew BC
ram:0206b7 a3 incw BC
ram:0206b8 c3 push BC
ram:0206b9 12 movw BC,AX
ram:0206ba 17 movw AX,HL
ram:0206bb c1 push AX
ram:0206bc 491200 mov A,!0xf0012[BC]
ram:0206bf 9dd4 mov 0xffdf4,A
ram:0206c1 791000 movw AX,!0xf0010[BC]
ram:0206c4 c1 push AX
ram:0206c5 8dd4 mov A,0xffdf4
ram:0206c7 9dd6 mov 0xffdf6,A
ram:0206c9 c0 pop AX
ram:0206ca 14 movw DE,AX
ram:0206cb 30a012 movw AX,0x12a0
ram:0206ce 320300 movw BC,0x3
ram:0206d1 c1 push AX
ram:0206d2 8dd6 mov A,0xffdf6
ram:0206d4 9efc mov CS,A
ram:0206d6 c0 pop AX
ram:0206d7 61ea call DE
ram:0206d9 1004 addw SP,0x4
ram:0206db 713870d9 clr1 !0xfd970.0x3
ram:0206df ef43 br $ 0x20724
ram:0206e1 8f70d9 mov A,!0xfd970
ram:0206e4 31353d bf A.0x3,$ 0x20723
ram:0206e7 c7 push HL
ram:0206e8 17 movw AX,HL
ram:0206e9 16 movw HL,AX
ram:0206ea f7 clrw BC
ram:0206eb 49f85e mov A,!0xf5ef8[BC]
ram:0206ee 9b mov [HL],A
ram:0206ef a3 incw BC
ram:0206f0 a7 incw HL
ram:0206f1 5102 mov ,0x2
ram:0206f3 614a cmp A,
ram:0206f5 dff4 bnz $ 0x206eb
ram:0206f7 c6 pop HL
ram:0206f8 af04e4 movw AX,!0xfe404
ram:0206fb e7 onew BC
ram:0206fc a3 incw BC
ram:0206fd c3 push BC
ram:0206fe 12 movw BC,AX
ram:0206ff 17 movw AX,HL
ram:020700 c1 push AX
ram:020701 491200 mov A,!0xf0012[BC]
ram:020704 9dd4 mov 0xffdf4,A
ram:020706 791000 movw AX,!0xf0010[BC]
ram:020709 c1 push AX
ram:02070a 8dd4 mov A,0xffdf4
ram:02070c 9dd6 mov 0xffdf6,A
ram:02070e c0 pop AX
ram:02070f 14 movw DE,AX
ram:020710 30a012 movw AX,0x12a0
ram:020713 320300 movw BC,0x3
ram:020716 c1 push AX
ram:020717 8dd6 mov A,0xffdf6
ram:020719 9efc mov CS,A
ram:02071b c0 pop AX
ram:02071c 61ea call DE
ram:02071e 1004 addw SP,0x4
ram:020720 713870d9 clr1 !0xfd970.0x3
ram:020724 c0 pop AX
ram:020725 c6 pop HL
ram:020726 d7 ret
ram:020901 c7 push HL
ram:020902 fc98f600 call !!0xf698
ram:020906 f6 clrw AX
ram:020907 42c8e9 cmpw AX,!0xfe9c8
ram:02090a df0a bnz $ 0x20916
ram:02090c 5020 mov ,0x20
ram:02090e fc82e300 call !!0xe382
ram:020912 13 movw AX,BC
ram:020913 bfc8e9 movw !0xfe9c8,AX
ram:020916 302000 movw AX,0x20
ram:020919 c1 push AX
ram:02091a f6 clrw AX
ram:02091b c1 push AX
ram:02091c afc8e9 movw AX,!0xfe9c8
ram:02091f fc40e500 call !!0xe540
ram:020923 1004 addw SP,0x4
ram:020925 8f70d9 mov A,!0xfd970
ram:020928 311309 bt A.0x1,$ 0x20933
ram:02092b ebc8e9 movw DE,!0xfe9c8
ram:02092e 89 mov A,[DE]
ram:02092f 6c01 or A,#0x1
ram:020931 99 mov [DE],A
ram:020932 ef07 br $ 0x2093b
ram:020934 ebc8e9 movw DE,!0xfe9c8
ram:020937 89 mov A,[DE]
ram:020938 5cfe and A,#0xfe
ram:02093a 99 mov [DE],A
ram:02093b ebc8e9 movw DE,!0xfe9c8
ram:02093e ca0264 mov [DE + 0x2],0x64
ram:020941 ebc8e9 movw DE,!0xfe9c8
ram:020944 8a03 mov A,[DE + 0x3]
ram:020946 5cf0 and A,#0xf0
ram:020948 6c07 or A,#0x7
ram:02094a 9a03 mov [DE + 0x3],A
ram:02094c 711871d9 clr1 !0xfd971.0x1
ram:020950 712871d9 clr1 !0xfd971.0x2
ram:020954 cf65d904 mov !0xfd965,0x4
ram:020958 8f67d9 mov A,!0xfd967
ram:02095b 2c02 sub A,#0x2
ram:02095d dc5d bc $ 0x209bc
ram:02095f 2c02 sub A,#0x2
ram:020961 df75 bnz $ 0x209d8
ram:020963 af08e4 movw AX,!0xfe408
ram:020966 f7 clrw BC
ram:020967 c3 push BC
ram:020968 14 movw DE,AX
ram:020969 8a0e mov A,[DE + 0xe]
ram:02096b 9efc mov CS,A
ram:02096d aa0c movw AX,[DE + 0xc]
ram:02096f 16 movw HL,AX
ram:020970 300600 movw AX,0x6
ram:020973 61fa call HL
ram:020975 c0 pop AX
ram:020976 302707 movw AX,0x727
ram:020979 5202 mov ,0x2
ram:02097b f3 clrb B
ram:02097c fc057e00 call !!0x7e05
ram:020980 62 mov A,
ram:020981 9f6ed9 mov !0xfd96e,A
ram:020984 303200 movw AX,0x32
ram:020987 c1 push AX
ram:020988 3091f7 movw AX,0xf791
ram:02098b 5201 mov ,0x1
ram:02098d f3 clrb B
ram:02098e fcea7d00 call !!0x7dea
ram:020992 c0 pop AX
ram:020993 ebc8e9 movw DE,!0xfe9c8
ram:020996 62 mov A,
ram:020997 9a1d mov [DE + 0x1d],A
ram:020999 30dc05 movw AX,0x5dc
ram:02099c c1 push AX
ram:02099d 30b4f4 movw AX,0xf4b4
ram:0209a0 5201 mov ,0x1
ram:0209a2 f3 clrb B
ram:0209a3 fcea7d00 call !!0x7dea
ram:0209a7 c0 pop AX
ram:0209a8 ebc8e9 movw DE,!0xfe9c8
ram:0209ab 62 mov A,
ram:0209ac 9a1e mov [DE + 0x1e],A
ram:0209ae ebc8e9 movw DE,!0xfe9c8
ram:0209b1 308cfc movw AX,0xfc8c
ram:0209b4 ba18 movw [DE + 0x18],AX
ram:0209b6 5100 mov ,0x0
ram:0209b8 9a1a mov [DE + 0x1a],A
ram:0209ba ef28 br $ 0x209e4
ram:0209bc 302707 movw AX,0x727
ram:0209bf 5202 mov ,0x2
ram:0209c1 f3 clrb B
ram:0209c2 fc057e00 call !!0x7e05
ram:0209c6 62 mov A,
ram:0209c7 9f6ed9 mov !0xfd96e,A
ram:0209ca ebc8e9 movw DE,!0xfe9c8
ram:0209cd 304e00 movw AX,0x4e
ram:0209d0 ba18 movw [DE + 0x18],AX
ram:0209d2 5101 mov ,0x1
ram:0209d4 9a1a mov [DE + 0x1a],A
ram:0209d6 ef0c br $ 0x209e4
ram:0209d8 ebc8e9 movw DE,!0xfe9c8
ram:0209db 308cfc movw AX,0xfc8c
ram:0209de ba18 movw [DE + 0x18],AX
ram:0209e0 5100 mov ,0x0
ram:0209e2 9a1a mov [DE + 0x1a],A
ram:0209e4 afc8e9 movw AX,!0xfe9c8
ram:0209e7 e7 onew BC
ram:0209e8 c3 push BC
ram:0209e9 14 movw DE,AX
ram:0209ea 8a1a mov A,[DE + 0x1a]
ram:0209ec 9efc mov CS,A
ram:0209ee aa18 movw AX,[DE + 0x18]
ram:0209f0 16 movw HL,AX
ram:0209f1 f6 clrw AX
ram:0209f2 61fa call HL
ram:0209f4 c0 pop AX
ram:0209f5 c6 pop HL
ram:0209f6 d7 ret
ram:0209f7 ebc8e9 movw DE,!0xfe9c8
ram:0209fa 8a1d mov A,[DE + 0x1d]
ram:0209fc d1 cmp0 A
ram:0209fd dd0e bz $ 0x20a0d
ram:0209ff 8a1d mov A,[DE + 0x1d]
ram:020a01 318e shrw AX,0x8
ram:020a03 fc927e00 call !!0x7e92
ram:020a07 ebc8e9 movw DE,!0xfe9c8
ram:020a0a ca1d00 mov [DE + 0x1d],0x0
ram:020a0d ebc8e9 movw DE,!0xfe9c8
ram:020a10 8a1e mov A,[DE + 0x1e]
ram:020a12 d1 cmp0 A
ram:020a13 dd0e bz $ 0x20a23
ram:020a15 8a1e mov A,[DE + 0x1e]
ram:020a17 318e shrw AX,0x8
ram:020a19 fc927e00 call !!0x7e92
ram:020a1d ebc8e9 movw DE,!0xfe9c8
ram:020a20 ca1e00 mov [DE + 0x1e],0x0
ram:020a23 f6 clrw AX
ram:020a24 42c8e9 cmpw AX,!0xfe9c8
ram:020a27 dd0b bz $ 0x20a34
ram:020a29 afc8e9 movw AX,!0xfe9c8
ram:020a2c fccae400 call !!0xe4ca
ram:020a30 f6 clrw AX
ram:020a31 bfc8e9 movw !0xfe9c8,AX
ram:020a34 712871d9 clr1 !0xfd971.0x2
ram:020a38 d7 ret
ram:020ecf c7 push HL
ram:020ed0 c1 push AX
ram:020ed1 2006 subw SP,0x6
ram:020ed3 fbf8ff movw HL,!0xffff8
ram:020ed6 cc0500 mov [HL + 0x5],0x0
ram:020ed9 ac06 movw AX,[HL + 0x6]
ram:020edb 14 movw DE,AX
ram:020edc aa04 movw AX,[DE + 0x4]
ram:020ede e7 onew BC
ram:020edf 240000 subw AX,0x0
ram:020ee2 dd39 bz $ 0x20f1d
ram:020ee4 23 subw AX,BC
ram:020ee5 61f8 sknz
ram:020ee7 ee0101 _br $! 0x20feb
ram:020eea 23 subw AX,BC
ram:020eeb 61f8 sknz
ram:020eed ee1201 _br $! 0x21002
ram:020ef0 23 subw AX,BC
ram:020ef1 61f8 sknz
ram:020ef3 ee3501 _br $! 0x2102b
ram:020ef6 23 subw AX,BC
ram:020ef7 61f8 sknz
ram:020ef9 eec601 _br $! 0x210c2
ram:020efc 23 subw AX,BC
ram:020efd 61f8 sknz
ram:020eff ee5d02 _br $! 0x2115f
ram:020f02 23 subw AX,BC
ram:020f03 61f8 sknz
ram:020f05 eef402 _br $! 0x211fc
ram:020f08 23 subw AX,BC
ram:020f09 61f8 sknz
ram:020f0b ee8b03 _br $! 0x21299
ram:020f0e 23 subw AX,BC
ram:020f0f 61f8 sknz
ram:020f11 eeea03 _br $! 0x212fe
ram:020f14 23 subw AX,BC
ram:020f15 61f8 sknz
ram:020f17 ee1004 _br $! 0x2132a
ram:020f1a ee9f04 br $! 0x213bc
ram:020f1d eb9ce3 movw DE,!0xfe39c
ram:020f20 8a18 mov A,[DE + 0x18]
ram:020f22 9efc mov CS,A
ram:020f24 aa16 movw AX,[DE + 0x16]
ram:020f26 61ca call AX
ram:020f28 62 mov A,
ram:020f29 9c05 mov [HL + 0x5],A
ram:020f2b eb9ce3 movw DE,!0xfe39c
ram:020f2e aa06 movw AX,[DE + 0x6]
ram:020f30 bdd8 movw 0xffdf8,AX
ram:020f32 aa08 movw AX,[DE + 0x8]
ram:020f34 bdda movw 0xffdfa,AX
ram:020f36 eb9ce3 movw DE,!0xfe39c
ram:020f39 aa02 movw AX,[DE + 0x2]
ram:020f3b bddc movw 0xffdfc,AX
ram:020f3d aa04 movw AX,[DE + 0x4]
ram:020f3f bdde movw 0xffdfe,AX
ram:020f41 adda movw AX,0xffdfa
ram:020f43 46de cmpw AX,0xffdfe
ram:020f45 add8 movw AX,0xffdf8
ram:020f47 61f8 sknz
ram:020f49 46dc _cmpw AX,0xffdfc
ram:020f4b df0c bnz $ 0x20f59
ram:020f4d eb9ce3 movw DE,!0xfe39c
ram:020f50 89 mov A,[DE]
ram:020f51 310305 bt A.0x0,$ 0x20f58
ram:020f54 6c01 or A,#0x1
ram:020f56 99 mov [DE],A
ram:020f57 ef40 br $ 0x20f99
ram:020f59 eb9ce3 movw DE,!0xfe39c
ram:020f5c aa06 movw AX,[DE + 0x6]
ram:020f5e bdd8 movw 0xffdf8,AX
ram:020f60 aa08 movw AX,[DE + 0x8]
ram:020f62 bdda movw 0xffdfa,AX
ram:020f64 eb9ce3 movw DE,!0xfe39c
ram:020f67 aa02 movw AX,[DE + 0x2]
ram:020f69 bddc movw 0xffdfc,AX
ram:020f6b aa04 movw AX,[DE + 0x4]
ram:020f6d bdde movw 0xffdfe,AX
ram:020f6f adda movw AX,0xffdfa
ram:020f71 46de cmpw AX,0xffdfe
ram:020f73 add8 movw AX,0xffdf8
ram:020f75 61f8 sknz
ram:020f77 46dc _cmpw AX,0xffdfc
ram:020f79 dd1e bz $ 0x20f99
ram:020f7b eb9ce3 movw DE,!0xfe39c
ram:020f7e 89 mov A,[DE]
ram:020f7f 310517 bf A.0x0,$ 0x20f98
ram:020f82 ac06 movw AX,[HL + 0x6]
ram:020f84 14 movw DE,AX
ram:020f85 f6 clrw AX
ram:020f86 ba06 movw [DE + 0x6],AX
ram:020f88 ac06 movw AX,[HL + 0x6]
ram:020f8a 14 movw DE,AX
ram:020f8b 300900 movw AX,0x9
ram:020f8e ba04 movw [DE + 0x4],AX
ram:020f90 eb9ce3 movw DE,!0xfe39c
ram:020f93 ca1b00 mov [DE + 0x1b],0x0
ram:020f96 ee2304 br $! 0x213bc
ram:020f99 eb9ce3 movw DE,!0xfe39c
ram:020f9c 89 mov A,[DE]
ram:020f9d 0c08 add A,#0x8
ram:020f9f 5c18 and A,#0x18
ram:020fa1 70 mov ,A
ram:020fa2 89 mov A,[DE]
ram:020fa3 5ce7 and A,#0xe7
ram:020fa5 6168 or A,
ram:020fa7 99 mov [DE],A
ram:020fa8 eb9ce3 movw DE,!0xfe39c
ram:020fab 89 mov A,[DE]
ram:020fac 3139 shl A,0x3
ram:020fae 316a shr A,0x6
ram:020fb0 d1 cmp0 A
ram:020fb1 df19 bnz $ 0x20fcc
ram:020fb3 db02e4 movw BC,!0xfe402
ram:020fb6 af9ce3 movw AX,!0xfe39c
ram:020fb9 040600 addw AX,0x6
ram:020fbc c1 push AX
ram:020fbd 491a00 mov A,!0xf001a[BC]
ram:020fc0 9efc mov CS,A
ram:020fc2 791800 movw AX,!0xf0018[BC]
ram:020fc5 14 movw DE,AX
ram:020fc6 304800 movw AX,0x48
ram:020fc9 61ea call DE
ram:020fcb c0 pop AX
ram:020fcc eb9ce3 movw DE,!0xfe39c
ram:020fcf aa08 movw AX,[DE + 0x8]
ram:020fd1 c1 push AX
ram:020fd2 aa06 movw AX,[DE + 0x6]
ram:020fd4 c1 push AX
ram:020fd5 8a0a mov A,[DE + 0xa]
ram:020fd7 318e shrw AX,0x8
ram:020fd9 c1 push AX
ram:020fda ac06 movw AX,[HL + 0x6]
ram:020fdc fc56f400 call !!0xf456
ram:020fe0 1006 addw SP,0x6
ram:020fe2 ac06 movw AX,[HL + 0x6]
ram:020fe4 14 movw DE,AX
ram:020fe5 e6 onew AX
ram:020fe6 ba04 movw [DE + 0x4],AX
ram:020fe8 eed103 br $! 0x213bc
ram:020feb eb9ce3 movw DE,!0xfe39c
ram:020fee 8a1a mov A,[DE + 0x1a]
ram:020ff0 72 mov ,A
ram:020ff1 ac06 movw AX,[HL + 0x6]
ram:020ff3 14 movw DE,AX
ram:020ff4 f3 clrb B
ram:020ff5 13 movw AX,BC
ram:020ff6 ba06 movw [DE + 0x6],AX
ram:020ff8 ac06 movw AX,[HL + 0x6]
ram:020ffa 14 movw DE,AX
ram:020ffb e6 onew AX
ram:020ffc a1 incw AX
ram:020ffd ba04 movw [DE + 0x4],AX
ram:020fff eeba03 br $! 0x213bc
ram:021002 af9ce3 movw AX,!0xfe39c
ram:021005 e7 onew BC
ram:021006 c3 push BC
ram:021007 14 movw DE,AX
ram:021008 8a14 mov A,[DE + 0x14]
ram:02100a 9efc mov CS,A
ram:02100c aa12 movw AX,[DE + 0x12]
ram:02100e 14 movw DE,AX
ram:02100f e6 onew AX
ram:021010 61ea call DE
ram:021012 c0 pop AX
ram:021013 eb9ce3 movw DE,!0xfe39c
ram:021016 8a1a mov A,[DE + 0x1a]
ram:021018 72 mov ,A
ram:021019 ac06 movw AX,[HL + 0x6]
ram:02101b 14 movw DE,AX
ram:02101c f3 clrb B
ram:02101d 13 movw AX,BC
ram:02101e ba06 movw [DE + 0x6],AX
ram:021020 ac06 movw AX,[HL + 0x6]
ram:021022 14 movw DE,AX
ram:021023 300300 movw AX,0x3
ram:021026 ba04 movw [DE + 0x4],AX
ram:021028 ee9103 br $! 0x213bc
ram:02102b ac06 movw AX,[HL + 0x6]
ram:02102d 14 movw DE,AX
ram:02102e f6 clrw AX
ram:02102f ba06 movw [DE + 0x6],AX
ram:021031 af9ce3 movw AX,!0xfe39c
ram:021034 f7 clrw BC
ram:021035 c3 push BC
ram:021036 14 movw DE,AX
ram:021037 8a14 mov A,[DE + 0x14]
ram:021039 9efc mov CS,A
ram:02103b aa12 movw AX,[DE + 0x12]
ram:02103d 14 movw DE,AX
ram:02103e f6 clrw AX
ram:02103f 61ea call DE
ram:021041 c0 pop AX
ram:021042 13 movw AX,BC
ram:021043 bc02 movw [HL + 0x2],AX
ram:021045 443d00 cmpw AX,0x3d
ram:021048 71fe or1 CY,A.0x7
ram:02104a dc40 bc $ 0x2108c
ram:02104c eb9ce3 movw DE,!0xfe39c
ram:02104f aa0c movw AX,[DE + 0xc]
ram:021051 6168 or A,
ram:021053 dd21 bz $ 0x21076
ram:021055 30c800 movw AX,0xc8
ram:021058 c1 push AX
ram:021059 5064 mov ,0x64
ram:02105b c1 push AX
ram:02105c f6 clrw AX
ram:02105d c1 push AX
ram:02105e ac06 movw AX,[HL + 0x6]
ram:021060 fc88f200 call !!0xf288
ram:021064 1006 addw SP,0x6
ram:021066 ac06 movw AX,[HL + 0x6]
ram:021068 14 movw DE,AX
ram:021069 f6 clrw AX
ram:02106a ba06 movw [DE + 0x6],AX
ram:02106c ac06 movw AX,[HL + 0x6]
ram:02106e 14 movw DE,AX
ram:02106f 300800 movw AX,0x8
ram:021072 ba04 movw [DE + 0x4],AX
ram:021074 ef49 br $ 0x210bf
ram:021076 ac06 movw AX,[HL + 0x6]
ram:021078 14 movw DE,AX
ram:021079 f6 clrw AX
ram:02107a ba06 movw [DE + 0x6],AX
ram:02107c ac06 movw AX,[HL + 0x6]
ram:02107e 14 movw DE,AX
ram:02107f 300900 movw AX,0x9
ram:021082 ba04 movw [DE + 0x4],AX
ram:021084 eb9ce3 movw DE,!0xfe39c
ram:021087 ca1b01 mov [DE + 0x1b],0x1
ram:02108a ef33 br $ 0x210bf
ram:02108c ac02 movw AX,[HL + 0x2]
ram:02108e 440b00 cmpw AX,0xb
ram:021091 71fe or1 CY,A.0x7
ram:021093 dc1e bc $ 0x210b3
ram:021095 eb9ce3 movw DE,!0xfe39c
ram:021098 ac02 movw AX,[HL + 0x2]
ram:02109a ba0e movw [DE + 0xe],AX
ram:02109c eb9ce3 movw DE,!0xfe39c
ram:02109f 8a1a mov A,[DE + 0x1a]
ram:0210a1 72 mov ,A
ram:0210a2 ac06 movw AX,[HL + 0x6]
ram:0210a4 14 movw DE,AX
ram:0210a5 f3 clrb B
ram:0210a6 13 movw AX,BC
ram:0210a7 ba06 movw [DE + 0x6],AX
ram:0210a9 ac06 movw AX,[HL + 0x6]
ram:0210ab 14 movw DE,AX
ram:0210ac 300400 movw AX,0x4
ram:0210af ba04 movw [DE + 0x4],AX
ram:0210b1 ef0c br $ 0x210bf
ram:0210b3 ac06 movw AX,[HL + 0x6]
ram:0210b5 14 movw DE,AX
ram:0210b6 f6 clrw AX
ram:0210b7 ba06 movw [DE + 0x6],AX
ram:0210b9 ac06 movw AX,[HL + 0x6]
ram:0210bb 14 movw DE,AX
ram:0210bc f6 clrw AX
ram:0210bd ba04 movw [DE + 0x4],AX
ram:0210bf eefa02 br $! 0x213bc
ram:0210c2 ac06 movw AX,[HL + 0x6]
ram:0210c4 14 movw DE,AX
ram:0210c5 f6 clrw AX
ram:0210c6 ba06 movw [DE + 0x6],AX
ram:0210c8 af9ce3 movw AX,!0xfe39c
ram:0210cb f7 clrw BC
ram:0210cc c3 push BC
ram:0210cd 14 movw DE,AX
ram:0210ce 8a14 mov A,[DE + 0x14]
ram:0210d0 9efc mov CS,A
ram:0210d2 aa12 movw AX,[DE + 0x12]
ram:0210d4 14 movw DE,AX
ram:0210d5 f6 clrw AX
ram:0210d6 61ea call DE
ram:0210d8 c0 pop AX
ram:0210d9 13 movw AX,BC
ram:0210da bc02 movw [HL + 0x2],AX
ram:0210dc eb9ce3 movw DE,!0xfe39c
ram:0210df aa10 movw AX,[DE + 0x10]
ram:0210e1 bdd8 movw 0xffdf8,AX
ram:0210e3 ac02 movw AX,[HL + 0x2]
ram:0210e5 fdab06 call !0xf06ab
ram:0210e8 de41 bnc $ 0x2112b
ram:0210ea eb9ce3 movw DE,!0xfe39c
ram:0210ed aa0c movw AX,[DE + 0xc]
ram:0210ef 6168 or A,
ram:0210f1 dd22 bz $ 0x21115
ram:0210f3 302c01 movw AX,0x12c
ram:0210f6 c1 push AX
ram:0210f7 309600 movw AX,0x96
ram:0210fa c1 push AX
ram:0210fb f6 clrw AX
ram:0210fc c1 push AX
ram:0210fd ac06 movw AX,[HL + 0x6]
ram:0210ff fc88f200 call !!0xf288
ram:021103 1006 addw SP,0x6
ram:021105 ac06 movw AX,[HL + 0x6]
ram:021107 14 movw DE,AX
ram:021108 f6 clrw AX
ram:021109 ba06 movw [DE + 0x6],AX
ram:02110b ac06 movw AX,[HL + 0x6]
ram:02110d 14 movw DE,AX
ram:02110e 300800 movw AX,0x8
ram:021111 ba04 movw [DE + 0x4],AX
ram:021113 ef47 br $ 0x2115c
ram:021115 ac06 movw AX,[HL + 0x6]
ram:021117 14 movw DE,AX
ram:021118 f6 clrw AX
ram:021119 ba06 movw [DE + 0x6],AX
ram:02111b ac06 movw AX,[HL + 0x6]
ram:02111d 14 movw DE,AX
ram:02111e 300900 movw AX,0x9
ram:021121 ba04 movw [DE + 0x4],AX
ram:021123 eb9ce3 movw DE,!0xfe39c
ram:021126 ca1b01 mov [DE + 0x1b],0x1
ram:021129 ef31 br $ 0x2115c
ram:02112b eb9ce3 movw DE,!0xfe39c
ram:02112e ac02 movw AX,[HL + 0x2]
ram:021130 bdd8 movw 0xffdf8,AX
ram:021132 aa0e movw AX,[DE + 0xe]
ram:021134 fdab06 call !0xf06ab
ram:021137 dc17 bc $ 0x21150
ram:021139 eb9ce3 movw DE,!0xfe39c
ram:02113c 8a1a mov A,[DE + 0x1a]
ram:02113e 72 mov ,A
ram:02113f ac06 movw AX,[HL + 0x6]
ram:021141 14 movw DE,AX
ram:021142 f3 clrb B
ram:021143 13 movw AX,BC
ram:021144 ba06 movw [DE + 0x6],AX
ram:021146 ac06 movw AX,[HL + 0x6]
ram:021148 14 movw DE,AX
ram:021149 300500 movw AX,0x5
ram:02114c ba04 movw [DE + 0x4],AX
ram:02114e ef0c br $ 0x2115c
ram:021150 ac06 movw AX,[HL + 0x6]
ram:021152 14 movw DE,AX
ram:021153 f6 clrw AX
ram:021154 ba06 movw [DE + 0x6],AX
ram:021156 ac06 movw AX,[HL + 0x6]
ram:021158 14 movw DE,AX
ram:021159 f6 clrw AX
ram:02115a ba04 movw [DE + 0x4],AX
ram:02115c ee5d02 br $! 0x213bc
ram:02115f ac06 movw AX,[HL + 0x6]
ram:021161 14 movw DE,AX
ram:021162 f6 clrw AX
ram:021163 ba06 movw [DE + 0x6],AX
ram:021165 af9ce3 movw AX,!0xfe39c
ram:021168 f7 clrw BC
ram:021169 c3 push BC
ram:02116a 14 movw DE,AX
ram:02116b 8a14 mov A,[DE + 0x14]
ram:02116d 9efc mov CS,A
ram:02116f aa12 movw AX,[DE + 0x12]
ram:021171 14 movw DE,AX
ram:021172 f6 clrw AX
ram:021173 61ea call DE
ram:021175 c0 pop AX
ram:021176 13 movw AX,BC
ram:021177 bc02 movw [HL + 0x2],AX
ram:021179 eb9ce3 movw DE,!0xfe39c
ram:02117c aa10 movw AX,[DE + 0x10]
ram:02117e bdd8 movw 0xffdf8,AX
ram:021180 ac02 movw AX,[HL + 0x2]
ram:021182 fdab06 call !0xf06ab
ram:021185 de41 bnc $ 0x211c8
ram:021187 eb9ce3 movw DE,!0xfe39c
ram:02118a aa0c movw AX,[DE + 0xc]
ram:02118c 6168 or A,
ram:02118e dd22 bz $ 0x211b2
ram:021190 302c01 movw AX,0x12c
ram:021193 c1 push AX
ram:021194 309600 movw AX,0x96
ram:021197 c1 push AX
ram:021198 f6 clrw AX
ram:021199 c1 push AX
ram:02119a ac06 movw AX,[HL + 0x6]
ram:02119c fc88f200 call !!0xf288
ram:0211a0 1006 addw SP,0x6
ram:0211a2 ac06 movw AX,[HL + 0x6]
ram:0211a4 14 movw DE,AX
ram:0211a5 f6 clrw AX
ram:0211a6 ba06 movw [DE + 0x6],AX
ram:0211a8 ac06 movw AX,[HL + 0x6]
ram:0211aa 14 movw DE,AX
ram:0211ab 300800 movw AX,0x8
ram:0211ae ba04 movw [DE + 0x4],AX
ram:0211b0 ef47 br $ 0x211f9
ram:0211b2 ac06 movw AX,[HL + 0x6]
ram:0211b4 14 movw DE,AX
ram:0211b5 f6 clrw AX
ram:0211b6 ba06 movw [DE + 0x6],AX
ram:0211b8 ac06 movw AX,[HL + 0x6]
ram:0211ba 14 movw DE,AX
ram:0211bb 300900 movw AX,0x9
ram:0211be ba04 movw [DE + 0x4],AX
ram:0211c0 eb9ce3 movw DE,!0xfe39c
ram:0211c3 ca1b01 mov [DE + 0x1b],0x1
ram:0211c6 ef31 br $ 0x211f9
ram:0211c8 eb9ce3 movw DE,!0xfe39c
ram:0211cb ac02 movw AX,[HL + 0x2]
ram:0211cd bdd8 movw 0xffdf8,AX
ram:0211cf aa0e movw AX,[DE + 0xe]
ram:0211d1 fdab06 call !0xf06ab
ram:0211d4 dc17 bc $ 0x211ed
ram:0211d6 eb9ce3 movw DE,!0xfe39c
ram:0211d9 8a1a mov A,[DE + 0x1a]
ram:0211db 72 mov ,A
ram:0211dc ac06 movw AX,[HL + 0x6]
ram:0211de 14 movw DE,AX
ram:0211df f3 clrb B
ram:0211e0 13 movw AX,BC
ram:0211e1 ba06 movw [DE + 0x6],AX
ram:0211e3 ac06 movw AX,[HL + 0x6]
ram:0211e5 14 movw DE,AX
ram:0211e6 300600 movw AX,0x6
ram:0211e9 ba04 movw [DE + 0x4],AX
ram:0211eb ef0c br $ 0x211f9
ram:0211ed ac06 movw AX,[HL + 0x6]
ram:0211ef 14 movw DE,AX
ram:0211f0 f6 clrw AX
ram:0211f1 ba06 movw [DE + 0x6],AX
ram:0211f3 ac06 movw AX,[HL + 0x6]
ram:0211f5 14 movw DE,AX
ram:0211f6 f6 clrw AX
ram:0211f7 ba04 movw [DE + 0x4],AX
ram:0211f9 eec001 br $! 0x213bc
ram:0211fc ac06 movw AX,[HL + 0x6]
ram:0211fe 14 movw DE,AX
ram:0211ff f6 clrw AX
ram:021200 ba06 movw [DE + 0x6],AX
ram:021202 af9ce3 movw AX,!0xfe39c
ram:021205 f7 clrw BC
ram:021206 c3 push BC
ram:021207 14 movw DE,AX
ram:021208 8a14 mov A,[DE + 0x14]
ram:02120a 9efc mov CS,A
ram:02120c aa12 movw AX,[DE + 0x12]
ram:02120e 14 movw DE,AX
ram:02120f f6 clrw AX
ram:021210 61ea call DE
ram:021212 c0 pop AX
ram:021213 13 movw AX,BC
ram:021214 bc02 movw [HL + 0x2],AX
ram:021216 eb9ce3 movw DE,!0xfe39c
ram:021219 aa10 movw AX,[DE + 0x10]
ram:02121b bdd8 movw 0xffdf8,AX
ram:02121d ac02 movw AX,[HL + 0x2]
ram:02121f fdab06 call !0xf06ab
ram:021222 de41 bnc $ 0x21265
ram:021224 eb9ce3 movw DE,!0xfe39c
ram:021227 aa0c movw AX,[DE + 0xc]
ram:021229 6168 or A,
ram:02122b dd22 bz $ 0x2124f
ram:02122d 302c01 movw AX,0x12c
ram:021230 c1 push AX
ram:021231 309600 movw AX,0x96
ram:021234 c1 push AX
ram:021235 f6 clrw AX
ram:021236 c1 push AX
ram:021237 ac06 movw AX,[HL + 0x6]
ram:021239 fc88f200 call !!0xf288
ram:02123d 1006 addw SP,0x6
ram:02123f ac06 movw AX,[HL + 0x6]
ram:021241 14 movw DE,AX
ram:021242 f6 clrw AX
ram:021243 ba06 movw [DE + 0x6],AX
ram:021245 ac06 movw AX,[HL + 0x6]
ram:021247 14 movw DE,AX
ram:021248 300800 movw AX,0x8
ram:02124b ba04 movw [DE + 0x4],AX
ram:02124d ef47 br $ 0x21296
ram:02124f ac06 movw AX,[HL + 0x6]
ram:021251 14 movw DE,AX
ram:021252 f6 clrw AX
ram:021253 ba06 movw [DE + 0x6],AX
ram:021255 ac06 movw AX,[HL + 0x6]
ram:021257 14 movw DE,AX
ram:021258 300900 movw AX,0x9
ram:02125b ba04 movw [DE + 0x4],AX
ram:02125d eb9ce3 movw DE,!0xfe39c
ram:021260 ca1b01 mov [DE + 0x1b],0x1
ram:021263 ef31 br $ 0x21296
ram:021265 eb9ce3 movw DE,!0xfe39c
ram:021268 ac02 movw AX,[HL + 0x2]
ram:02126a bdd8 movw 0xffdf8,AX
ram:02126c aa0e movw AX,[DE + 0xe]
ram:02126e fdab06 call !0xf06ab
ram:021271 dc17 bc $ 0x2128a
ram:021273 eb9ce3 movw DE,!0xfe39c
ram:021276 8a1a mov A,[DE + 0x1a]
ram:021278 72 mov ,A
ram:021279 ac06 movw AX,[HL + 0x6]
ram:02127b 14 movw DE,AX
ram:02127c f3 clrb B
ram:02127d 13 movw AX,BC
ram:02127e ba06 movw [DE + 0x6],AX
ram:021280 ac06 movw AX,[HL + 0x6]
ram:021282 14 movw DE,AX
ram:021283 300700 movw AX,0x7
ram:021286 ba04 movw [DE + 0x4],AX
ram:021288 ef0c br $ 0x21296
ram:02128a ac06 movw AX,[HL + 0x6]
ram:02128c 14 movw DE,AX
ram:02128d f6 clrw AX
ram:02128e ba06 movw [DE + 0x6],AX
ram:021290 ac06 movw AX,[HL + 0x6]
ram:021292 14 movw DE,AX
ram:021293 f6 clrw AX
ram:021294 ba04 movw [DE + 0x4],AX
ram:021296 ee2301 br $! 0x213bc
ram:021299 ac06 movw AX,[HL + 0x6]
ram:02129b 14 movw DE,AX
ram:02129c f6 clrw AX
ram:02129d ba06 movw [DE + 0x6],AX
ram:02129f af9ce3 movw AX,!0xfe39c
ram:0212a2 f7 clrw BC
ram:0212a3 c3 push BC
ram:0212a4 14 movw DE,AX
ram:0212a5 8a14 mov A,[DE + 0x14]
ram:0212a7 9efc mov CS,A
ram:0212a9 aa12 movw AX,[DE + 0x12]
ram:0212ab 14 movw DE,AX
ram:0212ac f6 clrw AX
ram:0212ad 61ea call DE
ram:0212af c0 pop AX
ram:0212b0 13 movw AX,BC
ram:0212b1 bc02 movw [HL + 0x2],AX
ram:0212b3 eb9ce3 movw DE,!0xfe39c
ram:0212b6 aa10 movw AX,[DE + 0x10]
ram:0212b8 bdd8 movw 0xffdf8,AX
ram:0212ba ac02 movw AX,[HL + 0x2]
ram:0212bc fdab06 call !0xf06ab
ram:0212bf de34 bnc $ 0x212f5
ram:0212c1 eb9ce3 movw DE,!0xfe39c
ram:0212c4 aa0c movw AX,[DE + 0xc]
ram:0212c6 6168 or A,
ram:0212c8 dd1b bz $ 0x212e5
ram:0212ca 30c800 movw AX,0xc8
ram:0212cd c1 push AX
ram:0212ce 5064 mov ,0x64
ram:0212d0 c1 push AX
ram:0212d1 f6 clrw AX
ram:0212d2 c1 push AX
ram:0212d3 ac06 movw AX,[HL + 0x6]
ram:0212d5 fc88f200 call !!0xf288
ram:0212d9 1006 addw SP,0x6
ram:0212db ac06 movw AX,[HL + 0x6]
ram:0212dd 14 movw DE,AX
ram:0212de 300800 movw AX,0x8
ram:0212e1 ba04 movw [DE + 0x4],AX
ram:0212e3 ef16 br $ 0x212fb
ram:0212e5 ac06 movw AX,[HL + 0x6]
ram:0212e7 14 movw DE,AX
ram:0212e8 300900 movw AX,0x9
ram:0212eb ba04 movw [DE + 0x4],AX
ram:0212ed eb9ce3 movw DE,!0xfe39c
ram:0212f0 ca1b01 mov [DE + 0x1b],0x1
ram:0212f3 ef06 br $ 0x212fb
ram:0212f5 ac06 movw AX,[HL + 0x6]
ram:0212f7 14 movw DE,AX
ram:0212f8 f6 clrw AX
ram:0212f9 ba04 movw [DE + 0x4],AX
ram:0212fb eebe00 br $! 0x213bc
ram:0212fe 17 movw AX,HL
ram:0212ff a1 incw AX
ram:021300 fcf8f200 call !!0xf2f8
ram:021304 13 movw AX,BC
ram:021305 bc02 movw [HL + 0x2],AX
ram:021307 eb9ce3 movw DE,!0xfe39c
ram:02130a aa0c movw AX,[DE + 0xc]
ram:02130c 614902 cmpw AX,[HL + 0x2]
ram:02130f df08 bnz $ 0x21319
ram:021311 ac06 movw AX,[HL + 0x6]
ram:021313 14 movw DE,AX
ram:021314 f6 clrw AX
ram:021315 ba04 movw [DE + 0x4],AX
ram:021317 ef0e br $ 0x21327
ram:021319 ac06 movw AX,[HL + 0x6]
ram:02131b 14 movw DE,AX
ram:02131c 300900 movw AX,0x9
ram:02131f ba04 movw [DE + 0x4],AX
ram:021321 eb9ce3 movw DE,!0xfe39c
ram:021324 ca1b01 mov [DE + 0x1b],0x1
ram:021327 ee9200 br $! 0x213bc
ram:02132a eb9ce3 movw DE,!0xfe39c
ram:02132d 8a1b mov A,[DE + 0x1b]
ram:02132f 91 dec 
ram:021330 df1b bnz $ 0x2134d
ram:021332 db02e4 movw BC,!0xfe402
ram:021335 af9ce3 movw AX,!0xfe39c
ram:021338 040600 addw AX,0x6
ram:02133b c1 push AX
ram:02133c 491a00 mov A,!0xf001a[BC]
ram:02133f 9efc mov CS,A
ram:021341 791800 movw AX,!0xf0018[BC]
ram:021344 14 movw DE,AX
ram:021345 304300 movw AX,0x43
ram:021348 61ea call DE
ram:02134a c0 pop AX
ram:02134b ef18 br $ 0x21365
ram:02134d db02e4 movw BC,!0xfe402
ram:021350 af9ce3 movw AX,!0xfe39c
ram:021353 a1 incw AX
ram:021354 a1 incw AX
ram:021355 c1 push AX
ram:021356 491a00 mov A,!0xf001a[BC]
ram:021359 9efc mov CS,A
ram:02135b 791800 movw AX,!0xf0018[BC]
ram:02135e 14 movw DE,AX
ram:02135f 305b00 movw AX,0x5b
ram:021362 61ea call DE
ram:021364 c0 pop AX
ram:021365 eb9ce3 movw DE,!0xfe39c
ram:021368 8a1b mov A,[DE + 0x1b]
ram:02136a 91 dec 
ram:02136b df1a bnz $ 0x21387
ram:02136d 89 mov A,[DE]
ram:02136e 310316 bt A.0x0,$ 0x21386
ram:021371 aa08 movw AX,[DE + 0x8]
ram:021373 12 movw BC,AX
ram:021374 aa06 movw AX,[DE + 0x6]
ram:021376 bf6ad9 movw !0xfd96a,AX
ram:021379 33 xchw AX,BC
ram:02137a bf6cd9 movw !0xfd96c,AX
ram:02137d 33 xchw AX,BC
ram:02137e bfe6d9 movw !0xfd9e6,AX
ram:021381 33 xchw AX,BC
ram:021382 bfe8d9 movw !0xfd9e8,AX
ram:021385 ef17 br $ 0x2139e
ram:021387 eb9ce3 movw DE,!0xfe39c
ram:02138a aa04 movw AX,[DE + 0x4]
ram:02138c 12 movw BC,AX
ram:02138d aa02 movw AX,[DE + 0x2]
ram:02138f bf6ad9 movw !0xfd96a,AX
ram:021392 33 xchw AX,BC
ram:021393 bf6cd9 movw !0xfd96c,AX
ram:021396 33 xchw AX,BC
ram:021397 bfe6d9 movw !0xfd9e6,AX
ram:02139a 33 xchw AX,BC
ram:02139b bfe8d9 movw !0xfd9e8,AX
ram:02139e eb9ce3 movw DE,!0xfe39c
ram:0213a1 89 mov A,[DE]
ram:0213a2 5cfe and A,#0xfe
ram:0213a4 99 mov [DE],A
ram:0213a5 eb9ce3 movw DE,!0xfe39c
ram:0213a8 ca1b00 mov [DE + 0x1b],0x0
ram:0213ab f6 clrw AX
ram:0213ac bf68d9 movw !0xfd968,AX
ram:0213af e6 onew AX
ram:0213b0 c1 push AX
ram:0213b1 d967d9 mov X,!0xfd967
ram:0213b4 c1 push AX
ram:0213b5 f6 clrw AX
ram:0213b6 fc020401 call !!0x10402
ram:0213ba 1004 addw SP,0x4
ram:0213bc e7 onew BC
ram:0213bd 1008 addw SP,0x8
ram:0213bf c6 pop HL
ram:0213c0 d7 ret
ram:0213c1 c7 push HL
ram:0213c2 af08e4 movw AX,!0xfe408
ram:0213c5 f7 clrw BC
ram:0213c6 c3 push BC
ram:0213c7 14 movw DE,AX
ram:0213c8 8a0e mov A,[DE + 0xe]
ram:0213ca 9efc mov CS,A
ram:0213cc aa0c movw AX,[DE + 0xc]
ram:0213ce 16 movw HL,AX
ram:0213cf 300400 movw AX,0x4
ram:0213d2 61fa call HL
ram:0213d4 c0 pop AX
ram:0213d5 fc98f600 call !!0xf698
ram:0213d9 e6 onew AX
ram:0213da fc0b0301 call !!0x1030b
ram:0213de f6 clrw AX
ram:0213df 429ce3 cmpw AX,!0xfe39c
ram:0213e2 df0a bnz $ 0x213ee
ram:0213e4 5042 mov ,0x42
ram:0213e6 fc82e300 call !!0xe382
ram:0213ea 13 movw AX,BC
ram:0213eb bf9ce3 movw !0xfe39c,AX
ram:0213ee 304200 movw AX,0x42
ram:0213f1 c1 push AX
ram:0213f2 f6 clrw AX
ram:0213f3 c1 push AX
ram:0213f4 af9ce3 movw AX,!0xfe39c
ram:0213f7 fc40e500 call !!0xe540
ram:0213fb 1004 addw SP,0x4
ram:0213fd eb9ce3 movw DE,!0xfe39c
ram:021400 8f67d9 mov A,!0xfd967
ram:021403 9a0a mov [DE + 0xa],A
ram:021405 eb9ce3 movw DE,!0xfe39c
ram:021408 db6cd9 movw BC,!0xfd96c
ram:02140b af6ad9 movw AX,!0xfd96a
ram:02140e ba06 movw [DE + 0x6],AX
ram:021410 33 xchw AX,BC
ram:021411 ba08 movw [DE + 0x8],AX
ram:021413 fc18ef01 call !!0x1ef18
ram:021417 cf65d90b mov !0xfd965,0xb
ram:02141b e6 onew AX
ram:02141c a1 incw AX
ram:02141d c1 push AX
ram:02141e 30cf0e movw AX,0xecf
ram:021421 5202 mov ,0x2
ram:021423 f3 clrb B
ram:021424 fcea7d00 call !!0x7dea
ram:021428 c0 pop AX
ram:021429 62 mov A,
ram:02142a 9f6ed9 mov !0xfd96e,A
ram:02142d eb9ce3 movw DE,!0xfe39c
ram:021430 8a0a mov A,[DE + 0xa]
ram:021432 2c02 sub A,#0x2
ram:021434 dc06 bc $ 0x2143c
ram:021436 2c02 sub A,#0x2
ram:021438 dd1f bz $ 0x21459
ram:02143a ef38 br $ 0x21474
ram:02143c eb9ce3 movw DE,!0xfe39c
ram:02143f 304e00 movw AX,0x4e
ram:021442 ba12 movw [DE + 0x12],AX
ram:021444 5101 mov ,0x1
ram:021446 9a14 mov [DE + 0x14],A
ram:021448 eb9ce3 movw DE,!0xfe39c
ram:02144b ca1a14 mov [DE + 0x1a],0x14
ram:02144e eb9ce3 movw DE,!0xfe39c
ram:021451 d9f4d9 mov X,!0xfd9f4
ram:021454 f1 clrb A
ram:021455 ba10 movw [DE + 0x10],AX
ram:021457 ef1b br $ 0x21474
ram:021459 eb9ce3 movw DE,!0xfe39c
ram:02145c 308cfc movw AX,0xfc8c
ram:02145f ba12 movw [DE + 0x12],AX
ram:021461 5100 mov ,0x0
ram:021463 9a14 mov [DE + 0x14],A
ram:021465 eb9ce3 movw DE,!0xfe39c
ram:021468 ca1a14 mov [DE + 0x1a],0x14
ram:02146b eb9ce3 movw DE,!0xfe39c
ram:02146e d9eed9 mov X,!0xfd9ee
ram:021471 f1 clrb A
ram:021472 ba10 movw [DE + 0x10],AX
ram:021474 c6 pop HL
ram:021475 d7 ret
ram:021476 c7 push HL
ram:021477 16 movw HL,AX
ram:021478 fcc11302 call !!0x213c1
ram:02147c 17 movw AX,HL
ram:02147d 12 movw BC,AX
ram:02147e eb9ce3 movw DE,!0xfe39c
ram:021481 5012 mov ,0x12
ram:021483 490000 mov A,!0xf0000[BC]
ram:021486 a3 incw BC
ram:021487 9a1c mov [DE + 0x1c],A
ram:021489 a5 incw DE
ram:02148a 90 dec 
ram:02148b dff6 bnz $ 0x21483
ram:02148d 8c0f mov A,[HL + 0xf]
ram:02148f 91 dec 
ram:021490 df0e bnz $ 0x214a0
ram:021492 eb9ce3 movw DE,!0xfe39c
ram:021495 30390a movw AX,0xa39
ram:021498 ba16 movw [DE + 0x16],AX
ram:02149a 5102 mov ,0x2
ram:02149c 9a18 mov [DE + 0x18],A
ram:02149e ef0c br $ 0x214ac
ram:0214a0 eb9ce3 movw DE,!0xfe39c
ram:0214a3 30170b movw AX,0xb17
ram:0214a6 ba16 movw [DE + 0x16],AX
ram:0214a8 5102 mov ,0x2
ram:0214aa 9a18 mov [DE + 0x18],A
ram:0214ac eb9ce3 movw DE,!0xfe39c
ram:0214af 8a0a mov A,[DE + 0xa]
ram:0214b1 72 mov ,A
ram:0214b2 8a2a mov A,[DE + 0x2a]
ram:0214b4 6142 cmp ,A
ram:0214b6 dd0f bz $ 0x214c7
ram:0214b8 8a2a mov A,[DE + 0x2a]
ram:0214ba 9a0a mov [DE + 0xa],A
ram:0214bc eb9ce3 movw DE,!0xfe39c
ram:0214bf 8a0a mov A,[DE + 0xa]
ram:0214c1 318e shrw AX,0x8
ram:0214c3 fc3e2201 call !!0x1223e
ram:0214c7 c7 push HL
ram:0214c8 c7 push HL
ram:0214c9 eb9ce3 movw DE,!0xfe39c
ram:0214cc c6 pop HL
ram:0214cd ac02 movw AX,[HL + 0x2]
ram:0214cf 12 movw BC,AX
ram:0214d0 ab movw AX,[HL]
ram:0214d1 ba06 movw [DE + 0x6],AX
ram:0214d3 33 xchw AX,BC
ram:0214d4 ba08 movw [DE + 0x8],AX
ram:0214d6 c6 pop HL
ram:0214d7 c1 push AX
ram:0214d8 c3 push BC
ram:0214d9 eb9ce3 movw DE,!0xfe39c
ram:0214dc c2 pop BC
ram:0214dd c0 pop AX
ram:0214de 33 xchw AX,BC
ram:0214df ba02 movw [DE + 0x2],AX
ram:0214e1 33 xchw AX,BC
ram:0214e2 ba04 movw [DE + 0x4],AX
ram:0214e4 ac0c movw AX,[HL + 0xc]
ram:0214e6 eb9ce3 movw DE,!0xfe39c
ram:0214e9 ba0c movw [DE + 0xc],AX
ram:0214eb eb9ce3 movw DE,!0xfe39c
ram:0214ee 8a0a mov A,[DE + 0xa]
ram:0214f0 4c04 cmp A,#0x4
ram:0214f2 df31 bnz $ 0x21525
ram:0214f4 8a2c mov A,[DE + 0x2c]
ram:0214f6 4c32 cmp A,#0x32
ram:0214f8 df2b bnz $ 0x21525
ram:0214fa aa02 movw AX,[DE + 0x2]
ram:0214fc bdd8 movw 0xffdf8,AX
ram:0214fe aa04 movw AX,[DE + 0x4]
ram:021500 bdda movw 0xffdfa,AX
ram:021502 c9dc6400 movw 0xffdfc,0x64
ram:021506 f6 clrw AX
ram:021507 fde005 call !0xf05e0
ram:02150a f6 clrw AX
ram:02150b 46da cmpw AX,0xffdfa
ram:02150d 61f8 sknz
ram:02150f 46d8 _cmpw AX,0xffdf8
ram:021511 dd0b bz $ 0x2151e
ram:021513 eb9ce3 movw DE,!0xfe39c
ram:021516 89 mov A,[DE]
ram:021517 5ce7 and A,#0xe7
ram:021519 6c08 or A,#0x8
ram:02151b 99 mov [DE],A
ram:02151c ef07 br $ 0x21525
ram:02151e eb9ce3 movw DE,!0xfe39c
ram:021521 89 mov A,[DE]
ram:021522 5ce7 and A,#0xe7
ram:021524 99 mov [DE],A
ram:021525 c6 pop HL
ram:021526 d7 ret
ram:021527 c7 push HL
ram:021528 c1 push AX
ram:021529 c1 push AX
ram:02152a fbf8ff movw HL,!0xffff8
ram:02152d fcc11302 call !!0x213c1
ram:021531 ac02 movw AX,[HL + 0x2]
ram:021533 12 movw BC,AX
ram:021534 eb9ce3 movw DE,!0xfe39c
ram:021537 5026 mov ,0x26
ram:021539 490000 mov A,!0xf0000[BC]
ram:02153c a3 incw BC
ram:02153d 9a1c mov [DE + 0x1c],A
ram:02153f a5 incw DE
ram:021540 90 dec 
ram:021541 dff6 bnz $ 0x21539
ram:021543 ac02 movw AX,[HL + 0x2]
ram:021545 14 movw DE,AX
ram:021546 8a1e mov A,[DE + 0x1e]
ram:021548 91 dec 
ram:021549 df0e bnz $ 0x21559
ram:02154b eb9ce3 movw DE,!0xfe39c
ram:02154e 30f70b movw AX,0xbf7
ram:021551 ba16 movw [DE + 0x16],AX
ram:021553 5102 mov ,0x2
ram:021555 9a18 mov [DE + 0x18],A
ram:021557 ef0c br $ 0x21565
ram:021559 eb9ce3 movw DE,!0xfe39c
ram:02155c 305d0d movw AX,0xd5d
ram:02155f ba16 movw [DE + 0x16],AX
ram:021561 5102 mov ,0x2
ram:021563 9a18 mov [DE + 0x18],A
ram:021565 c7 push HL
ram:021566 ac02 movw AX,[HL + 0x2]
ram:021568 c1 push AX
ram:021569 eb9ce3 movw DE,!0xfe39c
ram:02156c c6 pop HL
ram:02156d ac1a movw AX,[HL + 0x1a]
ram:02156f 12 movw BC,AX
ram:021570 ac18 movw AX,[HL + 0x18]
ram:021572 ba06 movw [DE + 0x6],AX
ram:021574 33 xchw AX,BC
ram:021575 ba08 movw [DE + 0x8],AX
ram:021577 c6 pop HL
ram:021578 c1 push AX
ram:021579 c3 push BC
ram:02157a eb9ce3 movw DE,!0xfe39c
ram:02157d c2 pop BC
ram:02157e c0 pop AX
ram:02157f 33 xchw AX,BC
ram:021580 ba02 movw [DE + 0x2],AX
ram:021582 33 xchw AX,BC
ram:021583 ba04 movw [DE + 0x4],AX
ram:021585 cc0100 mov [HL + 0x1],0x0
ram:021588 eb9ce3 movw DE,!0xfe39c
ram:02158b 8a3b mov A,[DE + 0x3b]
ram:02158d 4e01 cmp A,[HL + 0x1]
ram:02158f 61d35a bnh $ 0x215eb
ram:021592 aa06 movw AX,[DE + 0x6]
ram:021594 bdd8 movw 0xffdf8,AX
ram:021596 aa08 movw AX,[DE + 0x8]
ram:021598 bdda movw 0xffdfa,AX
ram:02159a eb9ce3 movw DE,!0xfe39c
ram:02159d 8c01 mov A,[HL + 0x1]
ram:02159f f0 clrb X
ram:0215a0 316e shrw AX,0x6
ram:0215a2 35 xchw AX,DE
ram:0215a3 041c00 addw AX,0x1c
ram:0215a6 35 xchw AX,DE
ram:0215a7 05 addw AX,DE
ram:0215a8 14 movw DE,AX
ram:0215a9 a9 movw AX,[DE]
ram:0215aa bddc movw 0xffdfc,AX
ram:0215ac aa02 movw AX,[DE + 0x2]
ram:0215ae bdde movw 0xffdfe,AX
ram:0215b0 adda movw AX,0xffdfa
ram:0215b2 46de cmpw AX,0xffdfe
ram:0215b4 add8 movw AX,0xffdf8
ram:0215b6 61f8 sknz
ram:0215b8 46dc _cmpw AX,0xffdfc
ram:0215ba dc2b bc $ 0x215e7
ram:0215bc eb9ce3 movw DE,!0xfe39c
ram:0215bf aa06 movw AX,[DE + 0x6]
ram:0215c1 bdd8 movw 0xffdf8,AX
ram:0215c3 aa08 movw AX,[DE + 0x8]
ram:0215c5 bdda movw 0xffdfa,AX
ram:0215c7 eb9ce3 movw DE,!0xfe39c
ram:0215ca 8c01 mov A,[HL + 0x1]
ram:0215cc f0 clrb X
ram:0215cd 316e shrw AX,0x6
ram:0215cf 35 xchw AX,DE
ram:0215d0 042800 addw AX,0x28
ram:0215d3 35 xchw AX,DE
ram:0215d4 05 addw AX,DE
ram:0215d5 14 movw DE,AX
ram:0215d6 a9 movw AX,[DE]
ram:0215d7 bddc movw 0xffdfc,AX
ram:0215d9 aa02 movw AX,[DE + 0x2]
ram:0215db bdde movw 0xffdfe,AX
ram:0215dd 46da cmpw AX,0xffdfa
ram:0215df addc movw AX,0xffdfc
ram:0215e1 61f8 sknz
ram:0215e3 46d8 _cmpw AX,0xffdf8
ram:0215e5 de05 bnc $ 0x215ec
ram:0215e7 615901 inc [HL + 0x1]
ram:0215ea ef9c br $ 0x21588
ram:0215ec eb9ce3 movw DE,!0xfe39c
ram:0215ef 8a3b mov A,[DE + 0x3b]
ram:0215f1 4e01 cmp A,[HL + 0x1]
ram:0215f3 61f8 sknz
ram:0215f5 ee9800 _br $! 0x21690
ram:0215f8 eb9ce3 movw DE,!0xfe39c
ram:0215fb 8c01 mov A,[HL + 0x1]
ram:0215fd 3119 shl A,0x1
ram:0215ff 5c06 and A,#0x6
ram:021601 70 mov ,A
ram:021602 89 mov A,[DE]
ram:021603 5cf9 and A,#0xf9
ram:021605 6168 or A,
ram:021607 99 mov [DE],A
ram:021608 eb9ce3 movw DE,!0xfe39c
ram:02160b 8a0a mov A,[DE + 0xa]
ram:02160d 72 mov ,A
ram:02160e 15 movw AX,DE
ram:02160f 043c00 addw AX,0x3c
ram:021612 c3 push BC
ram:021613 12 movw BC,AX
ram:021614 eb9ce3 movw DE,!0xfe39c
ram:021617 89 mov A,[DE]
ram:021618 3159 shl A,0x5
ram:02161a 31ee shrw AX,0xe
ram:02161c 03 addw AX,BC
ram:02161d c2 pop BC
ram:02161e 14 movw DE,AX
ram:02161f 89 mov A,[DE]
ram:021620 6142 cmp ,A
ram:021622 dd28 bz $ 0x2164c
ram:021624 eb9ce3 movw DE,!0xfe39c
ram:021627 15 movw AX,DE
ram:021628 043c00 addw AX,0x3c
ram:02162b 12 movw BC,AX
ram:02162c 89 mov A,[DE]
ram:02162d 3159 shl A,0x5
ram:02162f 31ee shrw AX,0xe
ram:021631 03 addw AX,BC
ram:021632 14 movw DE,AX
ram:021633 89 mov A,[DE]
ram:021634 eb9ce3 movw DE,!0xfe39c
ram:021637 9a0a mov [DE + 0xa],A
ram:021639 eb9ce3 movw DE,!0xfe39c
ram:02163c 8a0a mov A,[DE + 0xa]
ram:02163e 318e shrw AX,0x8
ram:021640 fc3e2201 call !!0x1223e
ram:021644 eb9ce3 movw DE,!0xfe39c
ram:021647 8a0a mov A,[DE + 0xa]
ram:021649 9f67d9 mov !0xfd967,A
ram:02164c ac02 movw AX,[HL + 0x2]
ram:02164e 14 movw DE,AX
ram:02164f aa1c movw AX,[DE + 0x1c]
ram:021651 eb9ce3 movw DE,!0xfe39c
ram:021654 ba0c movw [DE + 0xc],AX
ram:021656 eb9ce3 movw DE,!0xfe39c
ram:021659 8a0a mov A,[DE + 0xa]
ram:02165b 4c04 cmp A,#0x4
ram:02165d df31 bnz $ 0x21690
ram:02165f 8a2c mov A,[DE + 0x2c]
ram:021661 4c32 cmp A,#0x32
ram:021663 df2b bnz $ 0x21690
ram:021665 aa02 movw AX,[DE + 0x2]
ram:021667 bdd8 movw 0xffdf8,AX
ram:021669 aa04 movw AX,[DE + 0x4]
ram:02166b bdda movw 0xffdfa,AX
ram:02166d c9dc6400 movw 0xffdfc,0x64
ram:021671 f6 clrw AX
ram:021672 fde005 call !0xf05e0
ram:021675 f6 clrw AX
ram:021676 46da cmpw AX,0xffdfa
ram:021678 61f8 sknz
ram:02167a 46d8 _cmpw AX,0xffdf8
ram:02167c dd0b bz $ 0x21689
ram:02167e eb9ce3 movw DE,!0xfe39c
ram:021681 89 mov A,[DE]
ram:021682 5ce7 and A,#0xe7
ram:021684 6c08 or A,#0x8
ram:021686 99 mov [DE],A
ram:021687 ef07 br $ 0x21690
ram:021689 eb9ce3 movw DE,!0xfe39c
ram:02168c 89 mov A,[DE]
ram:02168d 5ce7 and A,#0xe7
ram:02168f 99 mov [DE],A
ram:021690 1004 addw SP,0x4
ram:021692 c6 pop HL
ram:021693 d7 ret
ram:021694 f6 clrw AX
ram:021695 429ce3 cmpw AX,!0xfe39c
ram:021698 dd0b bz $ 0x216a5
ram:02169a af9ce3 movw AX,!0xfe39c
ram:02169d fccae400 call !!0xe4ca
ram:0216a1 f6 clrw AX
ram:0216a2 bf9ce3 movw !0xfe39c,AX
ram:0216a5 f6 clrw AX
ram:0216a6 ec0b0301 br !!0x1030b
ram:0223a7 c7 push HL
ram:0223a8 af08e4 movw AX,!0xfe408
ram:0223ab f7 clrw BC
ram:0223ac c3 push BC
ram:0223ad 14 movw DE,AX
ram:0223ae 8a0e mov A,[DE + 0xe]
ram:0223b0 9efc mov CS,A
ram:0223b2 aa0c movw AX,[DE + 0xc]
ram:0223b4 16 movw HL,AX
ram:0223b5 300400 movw AX,0x4
ram:0223b8 61fa call HL
ram:0223ba c0 pop AX
ram:0223bb fc98f600 call !!0xf698
ram:0223bf f6 clrw AX
ram:0223c0 429ee3 cmpw AX,!0xfe39e
ram:0223c3 df0b bnz $ 0x223d0
ram:0223c5 307201 movw AX,0x172
ram:0223c8 fc82e300 call !!0xe382
ram:0223cc 13 movw AX,BC
ram:0223cd bf9ee3 movw !0xfe39e,AX
ram:0223d0 307201 movw AX,0x172
ram:0223d3 c1 push AX
ram:0223d4 f6 clrw AX
ram:0223d5 c1 push AX
ram:0223d6 af9ee3 movw AX,!0xfe39e
ram:0223d9 fc40e500 call !!0xe540
ram:0223dd 1004 addw SP,0x4
ram:0223df eb9ee3 movw DE,!0xfe39e
ram:0223e2 8f67d9 mov A,!0xfd967
ram:0223e5 9a0e mov [DE + 0xe],A
ram:0223e7 eb9ee3 movw DE,!0xfe39e
ram:0223ea db6cd9 movw BC,!0xfd96c
ram:0223ed af6ad9 movw AX,!0xfd96a
ram:0223f0 ba0a movw [DE + 0xa],AX
ram:0223f2 33 xchw AX,BC
ram:0223f3 ba0c movw [DE + 0xc],AX
ram:0223f5 fc18ef01 call !!0x1ef18
ram:0223f9 cf65d90d mov !0xfd965,0xd
ram:0223fd 309d1b movw AX,0x1b9d
ram:022400 5202 mov ,0x2
ram:022402 f3 clrb B
ram:022403 fc057e00 call !!0x7e05
ram:022407 62 mov A,
ram:022408 9f6ed9 mov !0xfd96e,A
ram:02240b eb9ee3 movw DE,!0xfe39e
ram:02240e 8a0e mov A,[DE + 0xe]
ram:022410 2c02 sub A,#0x2
ram:022412 dc06 bc $ 0x2241a
ram:022414 2c02 sub A,#0x2
ram:022416 dd24 bz $ 0x2243c
ram:022418 ef42 br $ 0x2245c
ram:02241a db9ee3 movw BC,!0xfe39e
ram:02241d 396c010c mov !0xf016c[BC],0xc
ram:022421 eb9ee3 movw DE,!0xfe39e
ram:022424 304e00 movw AX,0x4e
ram:022427 ba12 movw [DE + 0x12],AX
ram:022429 5101 mov ,0x1
ram:02242b 9a14 mov [DE + 0x14],A
ram:02242d eb9ee3 movw DE,!0xfe39e
ram:022430 89 mov A,[DE]
ram:022431 5cfb and A,#0xfb
ram:022433 99 mov [DE],A
ram:022434 eb9ee3 movw DE,!0xfe39e
ram:022437 ca1e23 mov [DE + 0x1e],0x23
ram:02243a ef20 br $ 0x2245c
ram:02243c db9ee3 movw BC,!0xfe39e
ram:02243f 396c0124 mov !0xf016c[BC],0x24
ram:022443 eb9ee3 movw DE,!0xfe39e
ram:022446 308cfc movw AX,0xfc8c
ram:022449 ba12 movw [DE + 0x12],AX
ram:02244b 5100 mov ,0x0
ram:02244d 9a14 mov [DE + 0x14],A
ram:02244f eb9ee3 movw DE,!0xfe39e
ram:022452 89 mov A,[DE]
ram:022453 6c04 or A,#0x4
ram:022455 99 mov [DE],A
ram:022456 eb9ee3 movw DE,!0xfe39e
ram:022459 ca1e14 mov [DE + 0x1e],0x14
ram:02245c db9ee3 movw BC,!0xfe39e
ram:02245f af9ee3 movw AX,!0xfe39e
ram:022462 046f01 addw AX,0x16f
ram:022465 14 movw DE,AX
ram:022466 496c01 mov A,!0xf016c[BC]
ram:022469 99 mov [DE],A
ram:02246a db9ee3 movw BC,!0xfe39e
ram:02246d af9ee3 movw AX,!0xfe39e
ram:022470 046e01 addw AX,0x16e
ram:022473 14 movw DE,AX
ram:022474 496c01 mov A,!0xf016c[BC]
ram:022477 99 mov [DE],A
ram:022478 e6 onew AX
ram:022479 fc0b0301 call !!0x1030b
ram:02247d c6 pop HL
ram:02247e d7 ret
ram:02247f c7 push HL
ram:022480 16 movw HL,AX
ram:022481 fca72302 call !!0x223a7
ram:022485 17 movw AX,HL
ram:022486 12 movw BC,AX
ram:022487 eb9ee3 movw DE,!0xfe39e
ram:02248a 5012 mov ,0x12
ram:02248c 490000 mov A,!0xf0000[BC]
ram:02248f a3 incw BC
ram:022490 9a26 mov [DE + 0x26],A
ram:022492 a5 incw DE
ram:022493 90 dec 
ram:022494 dff6 bnz $ 0x2248c
ram:022496 8c0f mov A,[HL + 0xf]
ram:022498 91 dec 
ram:022499 df0e bnz $ 0x224a9
ram:02249b eb9ee3 movw DE,!0xfe39e
ram:02249e 30aa16 movw AX,0x16aa
ram:0224a1 ba16 movw [DE + 0x16],AX
ram:0224a3 5102 mov ,0x2
ram:0224a5 9a18 mov [DE + 0x18],A
ram:0224a7 ef0c br $ 0x224b5
ram:0224a9 eb9ee3 movw DE,!0xfe39e
ram:0224ac 307917 movw AX,0x1779
ram:0224af ba16 movw [DE + 0x16],AX
ram:0224b1 5102 mov ,0x2
ram:0224b3 9a18 mov [DE + 0x18],A
ram:0224b5 eb9ee3 movw DE,!0xfe39e
ram:0224b8 301a1b movw AX,0x1b1a
ram:0224bb ba1a movw [DE + 0x1a],AX
ram:0224bd 5102 mov ,0x2
ram:0224bf 9a1c mov [DE + 0x1c],A
ram:0224c1 eb9ee3 movw DE,!0xfe39e
ram:0224c4 8a0e mov A,[DE + 0xe]
ram:0224c6 72 mov ,A
ram:0224c7 8a34 mov A,[DE + 0x34]
ram:0224c9 6142 cmp ,A
ram:0224cb dd17 bz $ 0x224e4
ram:0224cd 8a34 mov A,[DE + 0x34]
ram:0224cf 9a0e mov [DE + 0xe],A
ram:0224d1 eb9ee3 movw DE,!0xfe39e
ram:0224d4 8a0e mov A,[DE + 0xe]
ram:0224d6 318e shrw AX,0x8
ram:0224d8 fc3e2201 call !!0x1223e
ram:0224dc eb9ee3 movw DE,!0xfe39e
ram:0224df 8a0e mov A,[DE + 0xe]
ram:0224e1 9f67d9 mov !0xfd967,A
ram:0224e4 c7 push HL
ram:0224e5 c7 push HL
ram:0224e6 eb9ee3 movw DE,!0xfe39e
ram:0224e9 c6 pop HL
ram:0224ea ac02 movw AX,[HL + 0x2]
ram:0224ec 12 movw BC,AX
ram:0224ed ab movw AX,[HL]
ram:0224ee ba0a movw [DE + 0xa],AX
ram:0224f0 33 xchw AX,BC
ram:0224f1 ba0c movw [DE + 0xc],AX
ram:0224f3 c6 pop HL
ram:0224f4 c1 push AX
ram:0224f5 c3 push BC
ram:0224f6 eb9ee3 movw DE,!0xfe39e
ram:0224f9 c2 pop BC
ram:0224fa c0 pop AX
ram:0224fb 33 xchw AX,BC
ram:0224fc ba06 movw [DE + 0x6],AX
ram:0224fe 33 xchw AX,BC
ram:0224ff ba08 movw [DE + 0x8],AX
ram:022501 17 movw AX,HL
ram:022502 14 movw DE,AX
ram:022503 aa08 movw AX,[DE + 0x8]
ram:022505 bdd8 movw 0xffdf8,AX
ram:022507 aa0a movw AX,[DE + 0xa]
ram:022509 bdda movw 0xffdfa,AX
ram:02250b aa04 movw AX,[DE + 0x4]
ram:02250d bddc movw 0xffdfc,AX
ram:02250f aa06 movw AX,[DE + 0x6]
ram:022511 bdde movw 0xffdfe,AX
ram:022513 fd5f06 call !0xf065f
ram:022516 c7 push HL
ram:022517 add8 movw AX,0xffdf8
ram:022519 bddc movw 0xffdfc,AX
ram:02251b adda movw AX,0xffdfa
ram:02251d bdde movw 0xffdfe,AX
ram:02251f c0 pop AX
ram:022520 14 movw DE,AX
ram:022521 8a10 mov A,[DE + 0x10]
ram:022523 9dd8 mov 0xffdf8,A
ram:022525 f4d9 clrb 0xffdf9
ram:022527 f6 clrw AX
ram:022528 bdda movw 0xffdfa,AX
ram:02252a addc movw AX,0xffdfc
ram:02252c dad8 movw BC,0xffdf8
ram:02252e bdd8 movw 0xffdf8,AX
ram:022530 33 xchw AX,BC
ram:022531 bddc movw 0xffdfc,AX
ram:022533 adde movw AX,0xffdfe
ram:022535 dada movw BC,0xffdfa
ram:022537 bdda movw 0xffdfa,AX
ram:022539 33 xchw AX,BC
ram:02253a fda105 call !0xf05a1
ram:02253d c9dc0100 movw 0xffdfc,0x1
ram:022541 f6 clrw AX
ram:022542 fd5006 call !0xf0650
ram:022545 dad8 movw BC,0xffdf8
ram:022547 eb9ee3 movw DE,!0xfe39e
ram:02254a 13 movw AX,BC
ram:02254b ba02 movw [DE + 0x2],AX
ram:02254d eb9ee3 movw DE,!0xfe39e
ram:022550 f6 clrw AX
ram:022551 ba04 movw [DE + 0x4],AX
ram:022553 c6 pop HL
ram:022554 d7 ret
ram:022555 c7 push HL
ram:022556 c1 push AX
ram:022557 c1 push AX
ram:022558 fbf8ff movw HL,!0xffff8
ram:02255b fca72302 call !!0x223a7
ram:02255f ac02 movw AX,[HL + 0x2]
ram:022561 12 movw BC,AX
ram:022562 eb9ee3 movw DE,!0xfe39e
ram:022565 5026 mov ,0x26
ram:022567 490000 mov A,!0xf0000[BC]
ram:02256a a3 incw BC
ram:02256b 9a26 mov [DE + 0x26],A
ram:02256d a5 incw DE
ram:02256e 90 dec 
ram:02256f dff6 bnz $ 0x22567
ram:022571 ac02 movw AX,[HL + 0x2]
ram:022573 14 movw DE,AX
ram:022574 8a1e mov A,[DE + 0x1e]
ram:022576 91 dec 
ram:022577 df0e bnz $ 0x22587
ram:022579 eb9ee3 movw DE,!0xfe39e
ram:02257c 304a18 movw AX,0x184a
ram:02257f ba16 movw [DE + 0x16],AX
ram:022581 5102 mov ,0x2
ram:022583 9a18 mov [DE + 0x18],A
ram:022585 ef0c br $ 0x22593
ram:022587 eb9ee3 movw DE,!0xfe39e
ram:02258a 30ad19 movw AX,0x19ad
ram:02258d ba16 movw [DE + 0x16],AX
ram:02258f 5102 mov ,0x2
ram:022591 9a18 mov [DE + 0x18],A
ram:022593 eb9ee3 movw DE,!0xfe39e
ram:022596 302c1b movw AX,0x1b2c
ram:022599 ba1a movw [DE + 0x1a],AX
ram:02259b 5102 mov ,0x2
ram:02259d 9a1c mov [DE + 0x1c],A
ram:02259f c7 push HL
ram:0225a0 ac02 movw AX,[HL + 0x2]
ram:0225a2 c1 push AX
ram:0225a3 eb9ee3 movw DE,!0xfe39e
ram:0225a6 c6 pop HL
ram:0225a7 ac1a movw AX,[HL + 0x1a]
ram:0225a9 12 movw BC,AX
ram:0225aa ac18 movw AX,[HL + 0x18]
ram:0225ac ba0a movw [DE + 0xa],AX
ram:0225ae 33 xchw AX,BC
ram:0225af ba0c movw [DE + 0xc],AX
ram:0225b1 c6 pop HL
ram:0225b2 c1 push AX
ram:0225b3 c3 push BC
ram:0225b4 eb9ee3 movw DE,!0xfe39e
ram:0225b7 c2 pop BC
ram:0225b8 c0 pop AX
ram:0225b9 33 xchw AX,BC
ram:0225ba ba06 movw [DE + 0x6],AX
ram:0225bc 33 xchw AX,BC
ram:0225bd ba08 movw [DE + 0x8],AX
ram:0225bf cc0100 mov [HL + 0x1],0x0
ram:0225c2 eb9ee3 movw DE,!0xfe39e
ram:0225c5 8a45 mov A,[DE + 0x45]
ram:0225c7 4e01 cmp A,[HL + 0x1]
ram:0225c9 61d35a bnh $ 0x22625
ram:0225cc aa0a movw AX,[DE + 0xa]
ram:0225ce bdd8 movw 0xffdf8,AX
ram:0225d0 aa0c movw AX,[DE + 0xc]
ram:0225d2 bdda movw 0xffdfa,AX
ram:0225d4 eb9ee3 movw DE,!0xfe39e
ram:0225d7 8c01 mov A,[HL + 0x1]
ram:0225d9 f0 clrb X
ram:0225da 316e shrw AX,0x6
ram:0225dc 35 xchw AX,DE
ram:0225dd 042600 addw AX,0x26
ram:0225e0 35 xchw AX,DE
ram:0225e1 05 addw AX,DE
ram:0225e2 14 movw DE,AX
ram:0225e3 a9 movw AX,[DE]
ram:0225e4 bddc movw 0xffdfc,AX
ram:0225e6 aa02 movw AX,[DE + 0x2]
ram:0225e8 bdde movw 0xffdfe,AX
ram:0225ea adda movw AX,0xffdfa
ram:0225ec 46de cmpw AX,0xffdfe
ram:0225ee add8 movw AX,0xffdf8
ram:0225f0 61f8 sknz
ram:0225f2 46dc _cmpw AX,0xffdfc
ram:0225f4 dc2b bc $ 0x22621
ram:0225f6 eb9ee3 movw DE,!0xfe39e
ram:0225f9 aa0a movw AX,[DE + 0xa]
ram:0225fb bdd8 movw 0xffdf8,AX
ram:0225fd aa0c movw AX,[DE + 0xc]
ram:0225ff bdda movw 0xffdfa,AX
ram:022601 eb9ee3 movw DE,!0xfe39e
ram:022604 8c01 mov A,[HL + 0x1]
ram:022606 f0 clrb X
ram:022607 316e shrw AX,0x6
ram:022609 35 xchw AX,DE
ram:02260a 043200 addw AX,0x32
ram:02260d 35 xchw AX,DE
ram:02260e 05 addw AX,DE
ram:02260f 14 movw DE,AX
ram:022610 a9 movw AX,[DE]
ram:022611 bddc movw 0xffdfc,AX
ram:022613 aa02 movw AX,[DE + 0x2]
ram:022615 bdde movw 0xffdfe,AX
ram:022617 46da cmpw AX,0xffdfa
ram:022619 addc movw AX,0xffdfc
ram:02261b 61f8 sknz
ram:02261d 46d8 _cmpw AX,0xffdf8
ram:02261f de05 bnc $ 0x22626
ram:022621 615901 inc [HL + 0x1]
ram:022624 ef9c br $ 0x225c2
ram:022626 eb9ee3 movw DE,!0xfe39e
ram:022629 8a45 mov A,[DE + 0x45]
ram:02262b 4e01 cmp A,[HL + 0x1]
ram:02262d 61f8 sknz
ram:02262f eee100 _br $! 0x22713
ram:022632 eb9ee3 movw DE,!0xfe39e
ram:022635 8c01 mov A,[HL + 0x1]
ram:022637 5c03 and A,#0x3
ram:022639 70 mov ,A
ram:02263a 89 mov A,[DE]
ram:02263b 5cfc and A,#0xfc
ram:02263d 6168 or A,
ram:02263f 99 mov [DE],A
ram:022640 eb9ee3 movw DE,!0xfe39e
ram:022643 8a0e mov A,[DE + 0xe]
ram:022645 72 mov ,A
ram:022646 15 movw AX,DE
ram:022647 044600 addw AX,0x46
ram:02264a c3 push BC
ram:02264b 12 movw BC,AX
ram:02264c eb9ee3 movw DE,!0xfe39e
ram:02264f 89 mov A,[DE]
ram:022650 5c03 and A,#0x3
ram:022652 318e shrw AX,0x8
ram:022654 03 addw AX,BC
ram:022655 c2 pop BC
ram:022656 14 movw DE,AX
ram:022657 89 mov A,[DE]
ram:022658 6142 cmp ,A
ram:02265a dd28 bz $ 0x22684
ram:02265c eb9ee3 movw DE,!0xfe39e
ram:02265f 15 movw AX,DE
ram:022660 044600 addw AX,0x46
ram:022663 12 movw BC,AX
ram:022664 89 mov A,[DE]
ram:022665 5c03 and A,#0x3
ram:022667 318e shrw AX,0x8
ram:022669 03 addw AX,BC
ram:02266a 14 movw DE,AX
ram:02266b 89 mov A,[DE]
ram:02266c eb9ee3 movw DE,!0xfe39e
ram:02266f 9a0e mov [DE + 0xe],A
ram:022671 eb9ee3 movw DE,!0xfe39e
ram:022674 8a0e mov A,[DE + 0xe]
ram:022676 318e shrw AX,0x8
ram:022678 fc3e2201 call !!0x1223e
ram:02267c eb9ee3 movw DE,!0xfe39e
ram:02267f 8a0e mov A,[DE + 0xe]
ram:022681 9f67d9 mov !0xfd967,A
ram:022684 eb9ee3 movw DE,!0xfe39e
ram:022687 f6 clrw AX
ram:022688 ba02 movw [DE + 0x2],AX
ram:02268a 9c01 mov [HL + 0x1],A
ram:02268c eb9ee3 movw DE,!0xfe39e
ram:02268f 8a45 mov A,[DE + 0x45]
ram:022691 4e01 cmp A,[HL + 0x1]
ram:022693 61d377 bnh $ 0x2270c
ram:022696 8c01 mov A,[HL + 0x1]
ram:022698 f0 clrb X
ram:022699 316e shrw AX,0x6
ram:02269b 35 xchw AX,DE
ram:02269c 043200 addw AX,0x32
ram:02269f 35 xchw AX,DE
ram:0226a0 05 addw AX,DE
ram:0226a1 14 movw DE,AX
ram:0226a2 a9 movw AX,[DE]
ram:0226a3 bdd8 movw 0xffdf8,AX
ram:0226a5 aa02 movw AX,[DE + 0x2]
ram:0226a7 bdda movw 0xffdfa,AX
ram:0226a9 eb9ee3 movw DE,!0xfe39e
ram:0226ac 8c01 mov A,[HL + 0x1]
ram:0226ae f0 clrb X
ram:0226af 316e shrw AX,0x6
ram:0226b1 35 xchw AX,DE
ram:0226b2 042600 addw AX,0x26
ram:0226b5 35 xchw AX,DE
ram:0226b6 05 addw AX,DE
ram:0226b7 14 movw DE,AX
ram:0226b8 a9 movw AX,[DE]
ram:0226b9 bddc movw 0xffdfc,AX
ram:0226bb aa02 movw AX,[DE + 0x2]
ram:0226bd bdde movw 0xffdfe,AX
ram:0226bf fd5f06 call !0xf065f
ram:0226c2 eb9ee3 movw DE,!0xfe39e
ram:0226c5 8c01 mov A,[HL + 0x1]
ram:0226c7 318e shrw AX,0x8
ram:0226c9 35 xchw AX,DE
ram:0226ca 044900 addw AX,0x49
ram:0226cd 35 xchw AX,DE
ram:0226ce 05 addw AX,DE
ram:0226cf c1 push AX
ram:0226d0 add8 movw AX,0xffdf8
ram:0226d2 bddc movw 0xffdfc,AX
ram:0226d4 adda movw AX,0xffdfa
ram:0226d6 bdde movw 0xffdfe,AX
ram:0226d8 c0 pop AX
ram:0226d9 14 movw DE,AX
ram:0226da 89 mov A,[DE]
ram:0226db 9dd8 mov 0xffdf8,A
ram:0226dd f4d9 clrb 0xffdf9
ram:0226df f6 clrw AX
ram:0226e0 bdda movw 0xffdfa,AX
ram:0226e2 addc movw AX,0xffdfc
ram:0226e4 dad8 movw BC,0xffdf8
ram:0226e6 bdd8 movw 0xffdf8,AX
ram:0226e8 33 xchw AX,BC
ram:0226e9 bddc movw 0xffdfc,AX
ram:0226eb adde movw AX,0xffdfe
ram:0226ed dada movw BC,0xffdfa
ram:0226ef bdda movw 0xffdfa,AX
ram:0226f1 33 xchw AX,BC
ram:0226f2 fda105 call !0xf05a1
ram:0226f5 c9dc0100 movw 0xffdfc,0x1
ram:0226f9 f6 clrw AX
ram:0226fa fd5006 call !0xf0650
ram:0226fd dad8 movw BC,0xffdf8
ram:0226ff eb9ee3 movw DE,!0xfe39e
ram:022702 aa02 movw AX,[DE + 0x2]
ram:022704 03 addw AX,BC
ram:022705 ba02 movw [DE + 0x2],AX
ram:022707 615901 inc [HL + 0x1]
ram:02270a ee7fff br $! 0x2268c
ram:02270d eb9ee3 movw DE,!0xfe39e
ram:022710 f6 clrw AX
ram:022711 ba04 movw [DE + 0x4],AX
ram:022713 1004 addw SP,0x4
ram:022715 c6 pop HL
ram:022716 d7 ret
ram:022717 f6 clrw AX
ram:022718 429ee3 cmpw AX,!0xfe39e
ram:02271b dd0b bz $ 0x22728
ram:02271d af9ee3 movw AX,!0xfe39e
ram:022720 fccae400 call !!0xe4ca
ram:022724 f6 clrw AX
ram:022725 bf9ee3 movw !0xfe39e,AX
ram:022728 d7 ret
ram:022729 c7 push HL
ram:02272a c1 push AX
ram:02272b 2004 subw SP,0x4
ram:02272d fbf8ff movw HL,!0xffff8
ram:022730 ac04 movw AX,[HL + 0x4]
ram:022732 14 movw DE,AX
ram:022733 aa04 movw AX,[DE + 0x4]
ram:022735 e7 onew BC
ram:022736 240000 subw AX,0x0
ram:022739 dd15 bz $ 0x22750
ram:02273b 23 subw AX,BC
ram:02273c 61f8 sknz
ram:02273e ee8000 _br $! 0x227c1
ram:022741 23 subw AX,BC
ram:022742 61f8 sknz
ram:022744 ee9400 _br $! 0x227db
ram:022747 23 subw AX,BC
ram:022748 61f8 sknz
ram:02274a eef100 _br $! 0x2283e
ram:02274d ee1501 br $! 0x22865
ram:022750 34cce9 movw DE,0xe9cc
ram:022753 c5 push DE
ram:022754 30cbe9 movw AX,0xe9cb
ram:022757 fc50f201 call !!0x1f250
ram:02275b c0 pop AX
ram:02275c d2 cmp0 C
ram:02275d df26 bnz $ 0x22785
ram:02275f a0cae9 inc !0xfe9ca
ram:022762 40cae9cd cmp !0xfe9ca,0xcd
ram:022766 de05 bnc $ 0x2276d
ram:022768 d5cae9 cmp0 !0xfe9ca
ram:02276b 61f8 sknz
ram:02276d e5cae9 _oneb !0xfe9ca
ram:022770 d9cae9 mov X,!0xfe9ca
ram:022773 f1 clrb A
ram:022774 fcb0f201 call !!0x1f2b0
ram:022778 92 dec 
ram:022779 dde4 bz $ 0x2275f
ram:02277b 8fcae9 mov A,!0xfe9ca
ram:02277e 9fcbe9 mov !0xfe9cb,A
ram:022781 f6 clrw AX
ram:022782 bfcce9 movw !0xfe9cc,AX
ram:022785 d9cbe9 mov X,!0xfe9cb
ram:022788 f1 clrb A
ram:022789 fc160101 call !!0x10116
ram:02278d 13 movw AX,BC
ram:02278e bf6ad9 movw !0xfd96a,AX
ram:022791 15 movw AX,DE
ram:022792 bf6cd9 movw !0xfd96c,AX
ram:022795 f6 clrw AX
ram:022796 fc8c1501 call !!0x1158c
ram:02279a af6cd9 movw AX,!0xfd96c
ram:02279d c1 push AX
ram:02279e af6ad9 movw AX,!0xfd96a
ram:0227a1 c1 push AX
ram:0227a2 d967d9 mov X,!0xfd967
ram:0227a5 f1 clrb A
ram:0227a6 c1 push AX
ram:0227a7 f6 clrw AX
ram:0227a8 fcce1401 call !!0x114ce
ram:0227ac 1006 addw SP,0x6
ram:0227ae ac04 movw AX,[HL + 0x4]
ram:0227b0 14 movw DE,AX
ram:0227b1 303c00 movw AX,0x3c
ram:0227b4 ba06 movw [DE + 0x6],AX
ram:0227b6 ac04 movw AX,[HL + 0x4]
ram:0227b8 14 movw DE,AX
ram:0227b9 aa04 movw AX,[DE + 0x4]
ram:0227bb a1 incw AX
ram:0227bc ba04 movw [DE + 0x4],AX
ram:0227be eea400 br $! 0x22865
ram:0227c1 e6 onew AX
ram:0227c2 c1 push AX
ram:0227c3 fc8cfc00 call !!0xfc8c
ram:0227c7 c0 pop AX
ram:0227c8 ac04 movw AX,[HL + 0x4]
ram:0227ca 14 movw DE,AX
ram:0227cb 300500 movw AX,0x5
ram:0227ce ba06 movw [DE + 0x6],AX
ram:0227d0 ac04 movw AX,[HL + 0x4]
ram:0227d2 14 movw DE,AX
ram:0227d3 aa04 movw AX,[DE + 0x4]
ram:0227d5 a1 incw AX
ram:0227d6 ba04 movw [DE + 0x4],AX
ram:0227d8 ee8a00 br $! 0x22865
ram:0227db f6 clrw AX
ram:0227dc c1 push AX
ram:0227dd fc8cfc00 call !!0xfc8c
ram:0227e1 c0 pop AX
ram:0227e2 13 movw AX,BC
ram:0227e3 01 addw AX,AX
ram:0227e4 61c316 bh $ 0x227fc
ram:0227e7 d9cbe9 mov X,!0xfe9cb
ram:0227ea f1 clrb A
ram:0227eb fceef201 call !!0x1f2ee
ram:0227ef ac04 movw AX,[HL + 0x4]
ram:0227f1 14 movw DE,AX
ram:0227f2 f6 clrw AX
ram:0227f3 ba04 movw [DE + 0x4],AX
ram:0227f5 ac04 movw AX,[HL + 0x4]
ram:0227f7 14 movw DE,AX
ram:0227f8 f6 clrw AX
ram:0227f9 ba06 movw [DE + 0x6],AX
ram:0227fb ef68 br $ 0x22865
ram:0227fd f6 clrw AX
ram:0227fe c1 push AX
ram:0227ff fc8cfc00 call !!0xfc8c
ram:022803 c0 pop AX
ram:022804 13 movw AX,BC
ram:022805 441e00 cmpw AX,0x1e
ram:022808 71fe or1 CY,A.0x7
ram:02280a de0e bnc $ 0x2281a
ram:02280c ac04 movw AX,[HL + 0x4]
ram:02280e 14 movw DE,AX
ram:02280f f6 clrw AX
ram:022810 ba04 movw [DE + 0x4],AX
ram:022812 ac04 movw AX,[HL + 0x4]
ram:022814 14 movw DE,AX
ram:022815 f6 clrw AX
ram:022816 ba06 movw [DE + 0x6],AX
ram:022818 ef4b br $ 0x22865
ram:02281a 30bc02 movw AX,0x2bc
ram:02281d c1 push AX
ram:02281e 302c01 movw AX,0x12c
ram:022821 c1 push AX
ram:022822 afcce9 movw AX,!0xfe9cc
ram:022825 c1 push AX
ram:022826 ac04 movw AX,[HL + 0x4]
ram:022828 fc88f200 call !!0xf288
ram:02282c 1006 addw SP,0x6
ram:02282e ac04 movw AX,[HL + 0x4]
ram:022830 14 movw DE,AX
ram:022831 aa04 movw AX,[DE + 0x4]
ram:022833 a1 incw AX
ram:022834 ba04 movw [DE + 0x4],AX
ram:022836 ac04 movw AX,[HL + 0x4]
ram:022838 14 movw DE,AX
ram:022839 f6 clrw AX
ram:02283a ba06 movw [DE + 0x6],AX
ram:02283c ef27 br $ 0x22865
ram:02283e 17 movw AX,HL
ram:02283f a1 incw AX
ram:022840 fcf8f200 call !!0xf2f8
ram:022844 13 movw AX,BC
ram:022845 bc02 movw [HL + 0x2],AX
ram:022847 f6 clrw AX
ram:022848 614902 cmpw AX,[HL + 0x2]
ram:02284b dd0c bz $ 0x22859
ram:02284d ac02 movw AX,[HL + 0x2]
ram:02284f c1 push AX
ram:022850 d9cbe9 mov X,!0xfe9cb
ram:022853 f1 clrb A
ram:022854 fcb0ef01 call !!0x1efb0
ram:022858 c0 pop AX
ram:022859 ac04 movw AX,[HL + 0x4]
ram:02285b 14 movw DE,AX
ram:02285c f6 clrw AX
ram:02285d ba04 movw [DE + 0x4],AX
ram:02285f ac04 movw AX,[HL + 0x4]
ram:022861 14 movw DE,AX
ram:022862 f6 clrw AX
ram:022863 ba06 movw [DE + 0x6],AX
ram:022865 e7 onew BC
ram:022866 1006 addw SP,0x6
ram:022868 c6 pop HL
ram:022869 d7 ret
ram:02286a c7 push HL
ram:02286b fc98f600 call !!0xf698
ram:02286f e6 onew AX
ram:022870 fc0b0301 call !!0x1030b
ram:022874 af08e4 movw AX,!0xfe408
ram:022877 f7 clrw BC
ram:022878 c3 push BC
ram:022879 14 movw DE,AX
ram:02287a 8a0e mov A,[DE + 0xe]
ram:02287c 9efc mov CS,A
ram:02287e aa0c movw AX,[DE + 0xc]
ram:022880 16 movw HL,AX
ram:022881 300400 movw AX,0x4
ram:022884 61fa call HL
ram:022886 c0 pop AX
ram:022887 cf65d906 mov !0xfd965,0x6
ram:02288b 30c800 movw AX,0xc8
ram:02288e c1 push AX
ram:02288f 302927 movw AX,0x2729
ram:022892 5202 mov ,0x2
ram:022894 f3 clrb B
ram:022895 fcea7d00 call !!0x7dea
ram:022899 c0 pop AX
ram:02289a 62 mov A,
ram:02289b 9f6ed9 mov !0xfd96e,A
ram:02289e c6 pop HL
ram:02289f d7 ret
ram:0228a0 f6 clrw AX
ram:0228a1 ec0b0301 br !!0x1030b
ram:022aaf c7 push HL
ram:022ab0 af08e4 movw AX,!0xfe408
ram:022ab3 f7 clrw BC
ram:022ab4 c3 push BC
ram:022ab5 14 movw DE,AX
ram:022ab6 8a0e mov A,[DE + 0xe]
ram:022ab8 9efc mov CS,A
ram:022aba aa0c movw AX,[DE + 0xc]
ram:022abc 16 movw HL,AX
ram:022abd 300400 movw AX,0x4
ram:022ac0 61fa call HL
ram:022ac2 c0 pop AX
ram:022ac3 fc98f600 call !!0xf698
ram:022ac7 f6 clrw AX
ram:022ac8 42a0e3 cmpw AX,!0xfe3a0
ram:022acb df0a bnz $ 0x22ad7
ram:022acd 5026 mov ,0x26
ram:022acf fc82e300 call !!0xe382
ram:022ad3 13 movw AX,BC
ram:022ad4 bfa0e3 movw !0xfe3a0,AX
ram:022ad7 302600 movw AX,0x26
ram:022ada c1 push AX
ram:022adb f6 clrw AX
ram:022adc c1 push AX
ram:022add afa0e3 movw AX,!0xfe3a0
ram:022ae0 fc40e500 call !!0xe540
ram:022ae4 1004 addw SP,0x4
ram:022ae6 eba0e3 movw DE,!0xfe3a0
ram:022ae9 8f67d9 mov A,!0xfd967
ram:022aec 9a08 mov [DE + 0x8],A
ram:022aee eba0e3 movw DE,!0xfe3a0
ram:022af1 db6cd9 movw BC,!0xfd96c
ram:022af4 af6ad9 movw AX,!0xfd96a
ram:022af7 ba04 movw [DE + 0x4],AX
ram:022af9 33 xchw AX,BC
ram:022afa ba06 movw [DE + 0x6],AX
ram:022afc fc18ef01 call !!0x1ef18
ram:022b00 cf65d90c mov !0xfd965,0xc
ram:022b04 307429 movw AX,0x2974
ram:022b07 5202 mov ,0x2
ram:022b09 f3 clrb B
ram:022b0a fc057e00 call !!0x7e05
ram:022b0e 62 mov A,
ram:022b0f 9f6ed9 mov !0xfd96e,A
ram:022b12 eba0e3 movw DE,!0xfe3a0
ram:022b15 308cfc movw AX,0xfc8c
ram:022b18 ba0c movw [DE + 0xc],AX
ram:022b1a 5100 mov ,0x0
ram:022b1c 9a0e mov [DE + 0xe],A
ram:022b1e eba0e3 movw DE,!0xfe3a0
ram:022b21 d9eed9 mov X,!0xfd9ee
ram:022b24 f1 clrb A
ram:022b25 ba0a movw [DE + 0xa],AX
ram:022b27 e6 onew AX
ram:022b28 fc0b0301 call !!0x1030b
ram:022b2c c6 pop HL
ram:022b2d d7 ret
ram:022b2e c7 push HL
ram:022b2f 16 movw HL,AX
ram:022b30 fcaf2a02 call !!0x22aaf
ram:022b34 17 movw AX,HL
ram:022b35 12 movw BC,AX
ram:022b36 eba0e3 movw DE,!0xfe3a0
ram:022b39 5012 mov ,0x12
ram:022b3b 490000 mov A,!0xf0000[BC]
ram:022b3e a3 incw BC
ram:022b3f 9a14 mov [DE + 0x14],A
ram:022b41 a5 incw DE
ram:022b42 90 dec 
ram:022b43 dff6 bnz $ 0x22b3b
ram:022b45 eba0e3 movw DE,!0xfe3a0
ram:022b48 30a528 movw AX,0x28a5
ram:022b4b ba10 movw [DE + 0x10],AX
ram:022b4d 5102 mov ,0x2
ram:022b4f 9a12 mov [DE + 0x12],A
ram:022b51 eba0e3 movw DE,!0xfe3a0
ram:022b54 8a08 mov A,[DE + 0x8]
ram:022b56 72 mov ,A
ram:022b57 8a22 mov A,[DE + 0x22]
ram:022b59 6142 cmp ,A
ram:022b5b dd0f bz $ 0x22b6c
ram:022b5d 8a22 mov A,[DE + 0x22]
ram:022b5f 9a08 mov [DE + 0x8],A
ram:022b61 eba0e3 movw DE,!0xfe3a0
ram:022b64 8a08 mov A,[DE + 0x8]
ram:022b66 318e shrw AX,0x8
ram:022b68 fc3e2201 call !!0x1223e
ram:022b6c c7 push HL
ram:022b6d c7 push HL
ram:022b6e eba0e3 movw DE,!0xfe3a0
ram:022b71 c6 pop HL
ram:022b72 ac02 movw AX,[HL + 0x2]
ram:022b74 12 movw BC,AX
ram:022b75 ab movw AX,[HL]
ram:022b76 ba04 movw [DE + 0x4],AX
ram:022b78 33 xchw AX,BC
ram:022b79 ba06 movw [DE + 0x6],AX
ram:022b7b c6 pop HL
ram:022b7c c1 push AX
ram:022b7d c3 push BC
ram:022b7e eba0e3 movw DE,!0xfe3a0
ram:022b81 c2 pop BC
ram:022b82 c0 pop AX
ram:022b83 33 xchw AX,BC
ram:022b84 b9 movw [DE],AX
ram:022b85 33 xchw AX,BC
ram:022b86 ba02 movw [DE + 0x2],AX
ram:022b88 c6 pop HL
ram:022b89 d7 ret
ram:022b8a f6 clrw AX
ram:022b8b 42a0e3 cmpw AX,!0xfe3a0
ram:022b8e dd0b bz $ 0x22b9b
ram:022b90 afa0e3 movw AX,!0xfe3a0
ram:022b93 fccae400 call !!0xe4ca
ram:022b97 f6 clrw AX
ram:022b98 bfa0e3 movw !0xfe3a0,AX
ram:022b9b f6 clrw AX
ram:022b9c ec0b0301 br !!0x1030b
ram:022ba0 c7 push HL
ram:022ba1 c1 push AX
ram:022ba2 2004 subw SP,0x4
ram:022ba4 fbf8ff movw HL,!0xffff8
ram:022ba7 cc0300 mov [HL + 0x3],0x0
ram:022baa 8c0c mov A,[HL + 0xc]
ram:022bac 318e shrw AX,0x8
ram:022bae 318d shlw AX,0x8
ram:022bb0 12 movw BC,AX
ram:022bb1 8c0e mov A,[HL + 0xe]
ram:022bb3 318e shrw AX,0x8
ram:022bb5 616b or A,
ram:022bb7 08 xch A,X
ram:022bb8 616a or A,
ram:022bba 08 xch A,X
ram:022bbb bb movw [HL],AX
ram:022bbc 8c04 mov A,[HL + 0x4]
ram:022bbe 4c04 cmp A,#0x4
ram:022bc0 61f8 sknz
ram:022bc2 cc0402 _mov [HL + 0x4],0x2
ram:022bc5 8fa2e3 mov A,!0xfe3a2
ram:022bc8 5c07 and A,#0x7
ram:022bca d1 cmp0 A
ram:022bcb dd18 bz $ 0x22be5
ram:022bcd 8fa2e3 mov A,!0xfe3a2
ram:022bd0 5c07 and A,#0x7
ram:022bd2 91 dec 
ram:022bd3 4e04 cmp A,[HL + 0x4]
ram:022bd5 df0e bnz $ 0x22be5
ram:022bd7 8c04 mov A,[HL + 0x4]
ram:022bd9 f0 clrb X
ram:022bda 317e shrw AX,0x7
ram:022bdc 12 movw BC,AX
ram:022bdd 79a4e3 movw AX,!0xfe3a4[BC]
ram:022be0 614900 cmpw AX,[HL + 0x0]
ram:022be3 dd4f bz $ 0x22c34
ram:022be5 8fa2e3 mov A,!0xfe3a2
ram:022be8 5c07 and A,#0x7
ram:022bea 4e04 cmp A,[HL + 0x4]
ram:022bec df2c bnz $ 0x22c1a
ram:022bee 8fa2e3 mov A,!0xfe3a2
ram:022bf1 5c07 and A,#0x7
ram:022bf3 318e shrw AX,0x8
ram:022bf5 01 addw AX,AX
ram:022bf6 12 movw BC,AX
ram:022bf7 ab movw AX,[HL]
ram:022bf8 78a4e3 movw !0xfe3a4[BC],AX
ram:022bfb 8fa2e3 mov A,!0xfe3a2
ram:022bfe 81 inc 
ram:022bff 5c07 and A,#0x7
ram:022c01 34a2e3 movw DE,0xe3a2
ram:022c04 70 mov ,A
ram:022c05 89 mov A,[DE]
ram:022c06 5cf8 and A,#0xf8
ram:022c08 6168 or A,
ram:022c0a 99 mov [DE],A
ram:022c0b 5c07 and A,#0x7
ram:022c0d 4c04 cmp A,#0x4
ram:022c0f df23 bnz $ 0x22c34
ram:022c11 89 mov A,[DE]
ram:022c12 5cf8 and A,#0xf8
ram:022c14 99 mov [DE],A
ram:022c15 cc0301 mov [HL + 0x3],0x1
ram:022c18 ef1a br $ 0x22c34
ram:022c1a 8c04 mov A,[HL + 0x4]
ram:022c1c d1 cmp0 A
ram:022c1d df0e bnz $ 0x22c2d
ram:022c1f ab movw AX,[HL]
ram:022c20 bfa4e3 movw !0xfe3a4,AX
ram:022c23 34a2e3 movw DE,0xe3a2
ram:022c26 89 mov A,[DE]
ram:022c27 5cf8 and A,#0xf8
ram:022c29 81 inc 
ram:022c2a 99 mov [DE],A
ram:022c2b ef07 br $ 0x22c34
ram:022c2d 34a2e3 movw DE,0xe3a2
ram:022c30 89 mov A,[DE]
ram:022c31 5cf8 and A,#0xf8
ram:022c33 99 mov [DE],A
ram:022c34 8c03 mov A,[HL + 0x3]
ram:022c36 318e shrw AX,0x8
ram:022c38 12 movw BC,AX
ram:022c39 1006 addw SP,0x6
ram:022c3b c6 pop HL
ram:022c3c d7 ret
ram:022c45 c7 push HL
ram:022c46 c1 push AX
ram:022c47 200e subw SP,0xe
ram:022c49 fbf8ff movw HL,!0xffff8
ram:022c4c cc0d00 mov [HL + 0xd],0x0
ram:022c4f c7 push HL
ram:022c50 17 movw AX,HL
ram:022c51 16 movw HL,AX
ram:022c52 f7 clrw BC
ram:022c53 49fa5e mov A,!0xf5efa[BC]
ram:022c56 9b mov [HL],A
ram:022c57 a3 incw BC
ram:022c58 a7 incw HL
ram:022c59 5108 mov ,0x8
ram:022c5b 614a cmp A,
ram:022c5d dff4 bnz $ 0x22c53
ram:022c5f c6 pop HL
ram:022c60 af04e4 movw AX,!0xfe404
ram:022c63 320400 movw BC,0x4
ram:022c66 c3 push BC
ram:022c67 12 movw BC,AX
ram:022c68 17 movw AX,HL
ram:022c69 040800 addw AX,0x8
ram:022c6c c1 push AX
ram:022c6d 8c0e mov A,[HL + 0xe]
ram:022c6f f0 clrb X
ram:022c70 316e shrw AX,0x6
ram:022c72 07 addw AX,HL
ram:022c73 14 movw DE,AX
ram:022c74 a9 movw AX,[DE]
ram:022c75 bdd8 movw 0xffdf8,AX
ram:022c77 aa02 movw AX,[DE + 0x2]
ram:022c79 bdda movw 0xffdfa,AX
ram:022c7b 491600 mov A,!0xf0016[BC]
ram:022c7e 9efc mov CS,A
ram:022c80 791400 movw AX,!0xf0014[BC]
ram:022c83 14 movw DE,AX
ram:022c84 dada movw BC,0xffdfa
ram:022c86 add8 movw AX,0xffdf8
ram:022c88 61ea call DE
ram:022c8a 1004 addw SP,0x4
ram:022c8c f6 clrw AX
ram:022c8d 43 cmpw AX,BC
ram:022c8e df04 bnz $ 0x22c94
ram:022c90 f7 clrw BC
ram:022c91 eeb700 br $! 0x22d4b
ram:022c94 8c09 mov A,[HL + 0x9]
ram:022c96 317303 bt A.0x7,$ 0x22c9b
ram:022c99 ee8d00 br $! 0x22d29
ram:022c9c 5c03 and A,#0x3
ram:022c9e 61e8 skz
ram:022ca0 ee8600 _br $! 0x22d29
ram:022ca3 8fa3e3 mov A,!0xfe3a3
ram:022ca6 4e09 cmp A,[HL + 0x9]
ram:022ca8 dd65 bz $ 0x22d0f
ram:022caa 8c09 mov A,[HL + 0x9]
ram:022cac 5c1c and A,#0x1c
ram:022cae dd08 bz $ 0x22cb8
ram:022cb0 8c09 mov A,[HL + 0x9]
ram:022cb2 5c1c and A,#0x1c
ram:022cb4 4c10 cmp A,#0x10
ram:022cb6 df17 bnz $ 0x22ccf
ram:022cb8 8c0b mov A,[HL + 0xb]
ram:022cba 318e shrw AX,0x8
ram:022cbc 12 movw BC,AX
ram:022cbd 8c0a mov A,[HL + 0xa]
ram:022cbf 318e shrw AX,0x8
ram:022cc1 318d shlw AX,0x8
ram:022cc3 616b or A,
ram:022cc5 08 xch A,X
ram:022cc6 616a or A,
ram:022cc8 08 xch A,X
ram:022cc9 12 movw BC,AX
ram:022cca ac18 movw AX,[HL + 0x18]
ram:022ccc 14 movw DE,AX
ram:022ccd 13 movw AX,BC
ram:022cce b9 movw [DE],AX
ram:022ccf 8c0b mov A,[HL + 0xb]
ram:022cd1 318e shrw AX,0x8
ram:022cd3 c1 push AX
ram:022cd4 8c0a mov A,[HL + 0xa]
ram:022cd6 318e shrw AX,0x8
ram:022cd8 c1 push AX
ram:022cd9 8c09 mov A,[HL + 0x9]
ram:022cdb 3139 shl A,0x3
ram:022cdd 31de shrw AX,0xd
ram:022cdf fca02b02 call !!0x22ba0
ram:022ce3 1004 addw SP,0x4
ram:022ce5 92 dec 
ram:022ce6 df22 bnz $ 0x22d0a
ram:022ce8 ac16 movw AX,[HL + 0x16]
ram:022cea 14 movw DE,AX
ram:022ceb afa4e3 movw AX,!0xfe3a4
ram:022cee b9 movw [DE],AX
ram:022cef ac16 movw AX,[HL + 0x16]
ram:022cf1 14 movw DE,AX
ram:022cf2 afa6e3 movw AX,!0xfe3a6
ram:022cf5 ba02 movw [DE + 0x2],AX
ram:022cf7 ac16 movw AX,[HL + 0x16]
ram:022cf9 14 movw DE,AX
ram:022cfa afa8e3 movw AX,!0xfe3a8
ram:022cfd ba04 movw [DE + 0x4],AX
ram:022cff ac16 movw AX,[HL + 0x16]
ram:022d01 14 movw DE,AX
ram:022d02 afaae3 movw AX,!0xfe3aa
ram:022d05 ba06 movw [DE + 0x6],AX
ram:022d07 cc0d01 mov [HL + 0xd],0x1
ram:022d0a 8c09 mov A,[HL + 0x9]
ram:022d0c 9fa3e3 mov !0xfe3a3,A
ram:022d0f 8c0e mov A,[HL + 0xe]
ram:022d11 50ba mov ,0xba
ram:022d13 d6 mulu X
ram:022d14 0422db addw AX,0xdb22
ram:022d17 14 movw DE,AX
ram:022d18 aab8 movw AX,[DE + 0xb8]
ram:022d1a 12 movw BC,AX
ram:022d1b 301027 movw AX,0x2710
ram:022d1e 23 subw AX,BC
ram:022d1f 312e shrw AX,0x2
ram:022d21 12 movw BC,AX
ram:022d22 aab8 movw AX,[DE + 0xb8]
ram:022d24 03 addw AX,BC
ram:022d25 bab8 movw [DE + 0xb8],AX
ram:022d27 ef1d br $ 0x22d46
ram:022d29 34a2e3 movw DE,0xe3a2
ram:022d2c 89 mov A,[DE]
ram:022d2d 5cf8 and A,#0xf8
ram:022d2f 99 mov [DE],A
ram:022d30 f5a3e3 clrb !0xfe3a3
ram:022d33 8c0e mov A,[HL + 0xe]
ram:022d35 50ba mov ,0xba
ram:022d37 d6 mulu X
ram:022d38 0422db addw AX,0xdb22
ram:022d3b 14 movw DE,AX
ram:022d3c aab8 movw AX,[DE + 0xb8]
ram:022d3e 312e shrw AX,0x2
ram:022d40 12 movw BC,AX
ram:022d41 aab8 movw AX,[DE + 0xb8]
ram:022d43 23 subw AX,BC
ram:022d44 bab8 movw [DE + 0xb8],AX
ram:022d46 8c0d mov A,[HL + 0xd]
ram:022d48 318e shrw AX,0x8
ram:022d4a 12 movw BC,AX
ram:022d4b 1010 addw SP,0x10
ram:022d4d c6 pop HL
ram:022d4e d7 ret
ram:022e57 c7 push HL
ram:022e58 c1 push AX
ram:022e59 200e subw SP,0xe
ram:022e5b fbf8ff movw HL,!0xffff8
ram:022e5e c7 push HL
ram:022e5f 17 movw AX,HL
ram:022e60 040600 addw AX,0x6
ram:022e63 16 movw HL,AX
ram:022e64 f7 clrw BC
ram:022e65 49125f mov A,!0xf5f12[BC]
ram:022e68 9b mov [HL],A
ram:022e69 a3 incw BC
ram:022e6a a7 incw HL
ram:022e6b 5108 mov ,0x8
ram:022e6d 614a cmp A,
ram:022e6f dff4 bnz $ 0x22e65
ram:022e71 c6 pop HL
ram:022e72 c7 push HL
ram:022e73 17 movw AX,HL
ram:022e74 040400 addw AX,0x4
ram:022e77 16 movw HL,AX
ram:022e78 f7 clrw BC
ram:022e79 491a5f mov A,!0xf5f1a[BC]
ram:022e7c 9b mov [HL],A
ram:022e7d a3 incw BC
ram:022e7e a7 incw HL
ram:022e7f 5102 mov ,0x2
ram:022e81 614a cmp A,
ram:022e83 dff4 bnz $ 0x22e79
ram:022e85 c6 pop HL
ram:022e86 8c16 mov A,[HL + 0x16]
ram:022e88 91 dec 
ram:022e89 df06 bnz $ 0x22e91
ram:022e8b 8c05 mov A,[HL + 0x5]
ram:022e8d 6c40 or A,#0x40
ram:022e8f 9c05 mov [HL + 0x5],A
ram:022e91 af04e4 movw AX,!0xfe404
ram:022e94 e7 onew BC
ram:022e95 a3 incw BC
ram:022e96 c3 push BC
ram:022e97 12 movw BC,AX
ram:022e98 17 movw AX,HL
ram:022e99 040400 addw AX,0x4
ram:022e9c c1 push AX
ram:022e9d 8c0e mov A,[HL + 0xe]
ram:022e9f f0 clrb X
ram:022ea0 316e shrw AX,0x6
ram:022ea2 07 addw AX,HL
ram:022ea3 040600 addw AX,0x6
ram:022ea6 14 movw DE,AX
ram:022ea7 a9 movw AX,[DE]
ram:022ea8 bdd8 movw 0xffdf8,AX
ram:022eaa aa02 movw AX,[DE + 0x2]
ram:022eac bdda movw 0xffdfa,AX
ram:022eae 491200 mov A,!0xf0012[BC]
ram:022eb1 9efc mov CS,A
ram:022eb3 791000 movw AX,!0xf0010[BC]
ram:022eb6 14 movw DE,AX
ram:022eb7 dada movw BC,0xffdfa
ram:022eb9 add8 movw AX,0xffdf8
ram:022ebb 61ea call DE
ram:022ebd 1004 addw SP,0x4
ram:022ebf 34a2e3 movw DE,0xe3a2
ram:022ec2 89 mov A,[DE]
ram:022ec3 5cf8 and A,#0xf8
ram:022ec5 99 mov [DE],A
ram:022ec6 c7 push HL
ram:022ec7 17 movw AX,HL
ram:022ec8 a1 incw AX
ram:022ec9 16 movw HL,AX
ram:022eca f7 clrw BC
ram:022ecb 491c5f mov A,!0xf5f1c[BC]
ram:022ece 9b mov [HL],A
ram:022ecf a3 incw BC
ram:022ed0 a7 incw HL
ram:022ed1 5103 mov ,0x3
ram:022ed3 614a cmp A,
ram:022ed5 dff4 bnz $ 0x22ecb
ram:022ed7 c6 pop HL
ram:022ed8 af04e4 movw AX,!0xfe404
ram:022edb 320300 movw BC,0x3
ram:022ede c3 push BC
ram:022edf 12 movw BC,AX
ram:022ee0 17 movw AX,HL
ram:022ee1 a1 incw AX
ram:022ee2 c1 push AX
ram:022ee3 491200 mov A,!0xf0012[BC]
ram:022ee6 9dd4 mov 0xffdf4,A
ram:022ee8 791000 movw AX,!0xf0010[BC]
ram:022eeb c1 push AX
ram:022eec 8dd4 mov A,0xffdf4
ram:022eee 9dd6 mov 0xffdf6,A
ram:022ef0 c0 pop AX
ram:022ef1 14 movw DE,AX
ram:022ef2 30f90f movw AX,0xff9
ram:022ef5 320300 movw BC,0x3
ram:022ef8 c1 push AX
ram:022ef9 8dd6 mov A,0xffdf6
ram:022efb 9efc mov CS,A
ram:022efd c0 pop AX
ram:022efe 61ea call DE
ram:022f00 1004 addw SP,0x4
ram:022f02 cc0410 mov [HL + 0x4],0x10
ram:022f05 cc0520 mov [HL + 0x5],0x20
ram:022f08 af04e4 movw AX,!0xfe404
ram:022f0b e7 onew BC
ram:022f0c a3 incw BC
ram:022f0d c3 push BC
ram:022f0e 12 movw BC,AX
ram:022f0f 17 movw AX,HL
ram:022f10 040400 addw AX,0x4
ram:022f13 c1 push AX
ram:022f14 8c0e mov A,[HL + 0xe]
ram:022f16 f0 clrb X
ram:022f17 316e shrw AX,0x6
ram:022f19 07 addw AX,HL
ram:022f1a 040600 addw AX,0x6
ram:022f1d 14 movw DE,AX
ram:022f1e c3 push BC
ram:022f1f aa02 movw AX,[DE + 0x2]
ram:022f21 12 movw BC,AX
ram:022f22 a9 movw AX,[DE]
ram:022f23 240100 subw AX,0x1
ram:022f26 61d8 sknc
ram:022f28 b3 _decw BC
ram:022f29 c4 pop DE
ram:022f2a bdd8 movw 0xffdf8,AX
ram:022f2c 13 movw AX,BC
ram:022f2d bdda movw 0xffdfa,AX
ram:022f2f 8a12 mov A,[DE + 0x12]
ram:022f31 9efc mov CS,A
ram:022f33 aa10 movw AX,[DE + 0x10]
ram:022f35 14 movw DE,AX
ram:022f36 dada movw BC,0xffdfa
ram:022f38 add8 movw AX,0xffdf8
ram:022f3a 61ea call DE
ram:022f3c 1004 addw SP,0x4
ram:022f3e 1010 addw SP,0x10
ram:022f40 c6 pop HL
ram:022f41 d7 ret
ram:022f42 c7 push HL
ram:022f43 c1 push AX
ram:022f44 c1 push AX
ram:022f45 fbf8ff movw HL,!0xffff8
ram:022f48 8c02 mov A,[HL + 0x2]
ram:022f4a 7c80 xor A,#0x80
ram:022f4c 4c30 cmp A,#0x30
ram:022f4e de05 bnc $ 0x22f55
ram:022f50 32205f movw BC,0x5f20
ram:022f53 ef1a br $ 0x22f6f
ram:022f55 8c02 mov A,[HL + 0x2]
ram:022f57 7c80 xor A,#0x80
ram:022f59 4c8b cmp A,#0x8b
ram:022f5b dc05 bc $ 0x22f62
ram:022f5d 32d45f movw BC,0x5fd4
ram:022f60 ef0d br $ 0x22f6f
ram:022f62 8c02 mov A,[HL + 0x2]
ram:022f64 318f sarw AX,0x8
ram:022f66 045000 addw AX,0x50
ram:022f69 bb movw [HL],AX
ram:022f6a 01 addw AX,AX
ram:022f6b 04205f addw AX,0x5f20
ram:022f6e 12 movw BC,AX
ram:022f6f 1004 addw SP,0x4
ram:022f71 c6 pop HL
ram:022f72 d7 ret
ram:02333d c7 push HL
ram:02333e c1 push AX
ram:02333f c1 push AX
ram:023340 fbf8ff movw HL,!0xffff8
ram:023343 8c02 mov A,[HL + 0x2]
ram:023345 5003 mov ,0x3
ram:023347 d6 mulu X
ram:023348 12 movw BC,AX
ram:023349 49aa63 mov A,!0xf63aa[BC]
ram:02334c 9c01 mov [HL + 0x1],A
ram:02334e 8c02 mov A,[HL + 0x2]
ram:023350 73 mov ,A
ram:023351 09d4e9 mov A,!0xfe9d4[B]
ram:023354 9b mov [HL],A
ram:023355 5c10 and A,#0x10
ram:023357 d1 cmp0 A
ram:023358 dd04 bz $ 0x2335e
ram:02335a 8b mov A,[HL]
ram:02335b 5cef and A,#0xef
ram:02335d 9b mov [HL],A
ram:02335e 8c02 mov A,[HL + 0x2]
ram:023360 5003 mov ,0x3
ram:023362 d6 mulu X
ram:023363 12 movw BC,AX
ram:023364 49a963 mov A,!0xf63a9[BC]
ram:023367 4c0d cmp A,#0xd
ram:023369 df5b bnz $ 0x233c6
ram:02336b 8c01 mov A,[HL + 0x1]
ram:02336d 2c11 sub A,#0x11
ram:02336f dd0c bz $ 0x2337d
ram:023371 91 dec 
ram:023372 dd1b bz $ 0x2338f
ram:023374 91 dec 
ram:023375 dd2a bz $ 0x233a1
ram:023377 2c09 sub A,#0x9
ram:023379 dd38 bz $ 0x233b3
ram:02337b ef46 br $ 0x233c3
ram:02337d 8fcee9 mov A,!0xfe9ce
ram:023380 310506 bf A.0x0,$ 0x23388
ram:023383 8b mov A,[HL]
ram:023384 6c01 or A,#0x1
ram:023386 9b mov [HL],A
ram:023387 ef3a br $ 0x233c3
ram:023389 8b mov A,[HL]
ram:02338a 5cfe and A,#0xfe
ram:02338c 9b mov [HL],A
ram:02338d ef34 br $ 0x233c3
ram:02338f 8fcee9 mov A,!0xfe9ce
ram:023392 311506 bf A.0x1,$ 0x2339a
ram:023395 8b mov A,[HL]
ram:023396 6c01 or A,#0x1
ram:023398 9b mov [HL],A
ram:023399 ef28 br $ 0x233c3
ram:02339b 8b mov A,[HL]
ram:02339c 5cfe and A,#0xfe
ram:02339e 9b mov [HL],A
ram:02339f ef22 br $ 0x233c3
ram:0233a1 8fcee9 mov A,!0xfe9ce
ram:0233a4 312506 bf A.0x2,$ 0x233ac
ram:0233a7 8b mov A,[HL]
ram:0233a8 6c01 or A,#0x1
ram:0233aa 9b mov [HL],A
ram:0233ab ef16 br $ 0x233c3
ram:0233ad 8b mov A,[HL]
ram:0233ae 5cfe and A,#0xfe
ram:0233b0 9b mov [HL],A
ram:0233b1 ef10 br $ 0x233c3
ram:0233b3 8fcee9 mov A,!0xfe9ce
ram:0233b6 315506 bf A.0x5,$ 0x233be
ram:0233b9 8b mov A,[HL]
ram:0233ba 6c01 or A,#0x1
ram:0233bc 9b mov [HL],A
ram:0233bd ef04 br $ 0x233c3
ram:0233bf 8b mov A,[HL]
ram:0233c0 5cfe and A,#0xfe
ram:0233c2 9b mov [HL],A
ram:0233c3 ee3401 br $! 0x234fa
ram:0233c6 8c02 mov A,[HL + 0x2]
ram:0233c8 5003 mov ,0x3
ram:0233ca d6 mulu X
ram:0233cb 12 movw BC,AX
ram:0233cc 49a963 mov A,!0xf63a9[BC]
ram:0233cf 4c0f cmp A,#0xf
ram:0233d1 df5b bnz $ 0x2342e
ram:0233d3 8c01 mov A,[HL + 0x1]
ram:0233d5 2c11 sub A,#0x11
ram:0233d7 dd0c bz $ 0x233e5
ram:0233d9 91 dec 
ram:0233da dd1b bz $ 0x233f7
ram:0233dc 91 dec 
ram:0233dd dd2a bz $ 0x23409
ram:0233df 2c09 sub A,#0x9
ram:0233e1 dd38 bz $ 0x2341b
ram:0233e3 ef46 br $ 0x2342b
ram:0233e5 8fcfe9 mov A,!0xfe9cf
ram:0233e8 310506 bf A.0x0,$ 0x233f0
ram:0233eb 8b mov A,[HL]
ram:0233ec 6c01 or A,#0x1
ram:0233ee 9b mov [HL],A
ram:0233ef ef3a br $ 0x2342b
ram:0233f1 8b mov A,[HL]
ram:0233f2 5cfe and A,#0xfe
ram:0233f4 9b mov [HL],A
ram:0233f5 ef34 br $ 0x2342b
ram:0233f7 8fcfe9 mov A,!0xfe9cf
ram:0233fa 311506 bf A.0x1,$ 0x23402
ram:0233fd 8b mov A,[HL]
ram:0233fe 6c01 or A,#0x1
ram:023400 9b mov [HL],A
ram:023401 ef28 br $ 0x2342b
ram:023403 8b mov A,[HL]
ram:023404 5cfe and A,#0xfe
ram:023406 9b mov [HL],A
ram:023407 ef22 br $ 0x2342b
ram:023409 8fcfe9 mov A,!0xfe9cf
ram:02340c 312506 bf A.0x2,$ 0x23414
ram:02340f 8b mov A,[HL]
ram:023410 6c01 or A,#0x1
ram:023412 9b mov [HL],A
ram:023413 ef16 br $ 0x2342b
ram:023415 8b mov A,[HL]
ram:023416 5cfe and A,#0xfe
ram:023418 9b mov [HL],A
ram:023419 ef10 br $ 0x2342b
ram:02341b 8fcfe9 mov A,!0xfe9cf
ram:02341e 315506 bf A.0x5,$ 0x23426
ram:023421 8b mov A,[HL]
ram:023422 6c01 or A,#0x1
ram:023424 9b mov [HL],A
ram:023425 ef04 br $ 0x2342b
ram:023427 8b mov A,[HL]
ram:023428 5cfe and A,#0xfe
ram:02342a 9b mov [HL],A
ram:02342b eecc00 br $! 0x234fa
ram:02342e 8c02 mov A,[HL + 0x2]
ram:023430 5003 mov ,0x3
ram:023432 d6 mulu X
ram:023433 12 movw BC,AX
ram:023434 49a963 mov A,!0xf63a9[BC]
ram:023437 4c0b cmp A,#0xb
ram:023439 df5a bnz $ 0x23495
ram:02343b 8c01 mov A,[HL + 0x1]
ram:02343d 2c11 sub A,#0x11
ram:02343f dd0c bz $ 0x2344d
ram:023441 91 dec 
ram:023442 dd1b bz $ 0x2345f
ram:023444 91 dec 
ram:023445 dd2a bz $ 0x23471
ram:023447 2c09 sub A,#0x9
ram:023449 dd38 bz $ 0x23483
ram:02344b ef46 br $ 0x23493
ram:02344d 8fd0e9 mov A,!0xfe9d0
ram:023450 310506 bf A.0x0,$ 0x23458
ram:023453 8b mov A,[HL]
ram:023454 6c01 or A,#0x1
ram:023456 9b mov [HL],A
ram:023457 ef3a br $ 0x23493
ram:023459 8b mov A,[HL]
ram:02345a 5cfe and A,#0xfe
ram:02345c 9b mov [HL],A
ram:02345d ef34 br $ 0x23493
ram:02345f 8fd0e9 mov A,!0xfe9d0
ram:023462 311506 bf A.0x1,$ 0x2346a
ram:023465 8b mov A,[HL]
ram:023466 6c01 or A,#0x1
ram:023468 9b mov [HL],A
ram:023469 ef28 br $ 0x23493
ram:02346b 8b mov A,[HL]
ram:02346c 5cfe and A,#0xfe
ram:02346e 9b mov [HL],A
ram:02346f ef22 br $ 0x23493
ram:023471 8fd0e9 mov A,!0xfe9d0
ram:023474 312506 bf A.0x2,$ 0x2347c
ram:023477 8b mov A,[HL]
ram:023478 6c01 or A,#0x1
ram:02347a 9b mov [HL],A
ram:02347b ef16 br $ 0x23493
ram:02347d 8b mov A,[HL]
ram:02347e 5cfe and A,#0xfe
ram:023480 9b mov [HL],A
ram:023481 ef10 br $ 0x23493
ram:023483 8fd0e9 mov A,!0xfe9d0
ram:023486 315506 bf A.0x5,$ 0x2348e
ram:023489 8b mov A,[HL]
ram:02348a 6c01 or A,#0x1
ram:02348c 9b mov [HL],A
ram:02348d ef04 br $ 0x23493
ram:02348f 8b mov A,[HL]
ram:023490 5cfe and A,#0xfe
ram:023492 9b mov [HL],A
ram:023493 ef65 br $ 0x234fa
ram:023495 8c02 mov A,[HL + 0x2]
ram:023497 5003 mov ,0x3
ram:023499 d6 mulu X
ram:02349a 12 movw BC,AX
ram:02349b 49a963 mov A,!0xf63a9[BC]
ram:02349e 4c11 cmp A,#0x11
ram:0234a0 df58 bnz $ 0x234fa
ram:0234a2 8c01 mov A,[HL + 0x1]
ram:0234a4 2c11 sub A,#0x11
ram:0234a6 dd0c bz $ 0x234b4
ram:0234a8 91 dec 
ram:0234a9 dd1b bz $ 0x234c6
ram:0234ab 91 dec 
ram:0234ac dd2a bz $ 0x234d8
ram:0234ae 2c09 sub A,#0x9
ram:0234b0 dd38 bz $ 0x234ea
ram:0234b2 ef46 br $ 0x234fa
ram:0234b4 8fd1e9 mov A,!0xfe9d1
ram:0234b7 310506 bf A.0x0,$ 0x234bf
ram:0234ba 8b mov A,[HL]
ram:0234bb 6c01 or A,#0x1
ram:0234bd 9b mov [HL],A
ram:0234be ef3a br $ 0x234fa
ram:0234c0 8b mov A,[HL]
ram:0234c1 5cfe and A,#0xfe
ram:0234c3 9b mov [HL],A
ram:0234c4 ef34 br $ 0x234fa
ram:0234c6 8fd1e9 mov A,!0xfe9d1
ram:0234c9 311506 bf A.0x1,$ 0x234d1
ram:0234cc 8b mov A,[HL]
ram:0234cd 6c01 or A,#0x1
ram:0234cf 9b mov [HL],A
ram:0234d0 ef28 br $ 0x234fa
ram:0234d2 8b mov A,[HL]
ram:0234d3 5cfe and A,#0xfe
ram:0234d5 9b mov [HL],A
ram:0234d6 ef22 br $ 0x234fa
ram:0234d8 8fd1e9 mov A,!0xfe9d1
ram:0234db 312506 bf A.0x2,$ 0x234e3
ram:0234de 8b mov A,[HL]
ram:0234df 6c01 or A,#0x1
ram:0234e1 9b mov [HL],A
ram:0234e2 ef16 br $ 0x234fa
ram:0234e4 8b mov A,[HL]
ram:0234e5 5cfe and A,#0xfe
ram:0234e7 9b mov [HL],A
ram:0234e8 ef10 br $ 0x234fa
ram:0234ea 8fd1e9 mov A,!0xfe9d1
ram:0234ed 315506 bf A.0x5,$ 0x234f5
ram:0234f0 8b mov A,[HL]
ram:0234f1 6c01 or A,#0x1
ram:0234f3 9b mov [HL],A
ram:0234f4 ef04 br $ 0x234fa
ram:0234f6 8b mov A,[HL]
ram:0234f7 5cfe and A,#0xfe
ram:0234f9 9b mov [HL],A
ram:0234fa 8b mov A,[HL]
ram:0234fb 5c01 and A,#0x1
ram:0234fd d1 cmp0 A
ram:0234fe dd04 bz $ 0x23504
ram:023500 8b mov A,[HL]
ram:023501 6c28 or A,#0x28
ram:023503 9b mov [HL],A
ram:023504 8b mov A,[HL]
ram:023505 318e shrw AX,0x8
ram:023507 12 movw BC,AX
ram:023508 1004 addw SP,0x4
ram:02350a c6 pop HL
ram:02350b d7 ret
ram:02350c c7 push HL
ram:02350d 16 movw HL,AX
ram:02350e 5700 mov ,0x0
ram:023510 66 mov A,
ram:023511 5003 mov ,0x3
ram:023513 d6 mulu X
ram:023514 12 movw BC,AX
ram:023515 49a963 mov A,!0xf63a9[BC]
ram:023518 4c43 cmp A,#0x43
ram:02351a df16 bnz $ 0x23532
ram:02351c 49aa63 mov A,!0xf63aa[BC]
ram:02351f 4c41 cmp A,#0x41
ram:023521 df0f bnz $ 0x23532
ram:023523 66 mov A,
ram:023524 73 mov ,A
ram:023525 09d4e9 mov A,!0xfe9d4[B]
ram:023528 77 mov ,A
ram:023529 5c10 and A,#0x10
ram:02352b d1 cmp0 A
ram:02352c dd04 bz $ 0x23532
ram:02352e 51ef mov ,0xef
ram:023530 6157 and ,A
ram:023532 67 mov A,
ram:023533 5c01 and A,#0x1
ram:023535 d1 cmp0 A
ram:023536 dd04 bz $ 0x2353c
ram:023538 5128 mov ,0x28
ram:02353a 6167 or ,A
ram:02353c 67 mov A,
ram:02353d 318e shrw AX,0x8
ram:02353f 12 movw BC,AX
ram:023540 c6 pop HL
ram:023541 d7 ret
ram:023542 c7 push HL
ram:023543 16 movw HL,AX
ram:023544 5700 mov ,0x0
ram:023546 66 mov A,
ram:023547 5003 mov ,0x3
ram:023549 d6 mulu X
ram:02354a 12 movw BC,AX
ram:02354b 49a963 mov A,!0xf63a9[BC]
ram:02354e 4c47 cmp A,#0x47
ram:023550 df1a bnz $ 0x2356c
ram:023552 49aa63 mov A,!0xf63aa[BC]
ram:023555 4c49 cmp A,#0x49
ram:023557 df13 bnz $ 0x2356c
ram:023559 66 mov A,
ram:02355a 73 mov ,A
ram:02355b 09d4e9 mov A,!0xfe9d4[B]
ram:02355e 77 mov ,A
ram:02355f 5c10 and A,#0x10
ram:023561 d1 cmp0 A
ram:023562 dd04 bz $ 0x23568
ram:023564 51ef mov ,0xef
ram:023566 6157 and ,A
ram:023568 51fe mov ,0xfe
ram:02356a 6157 and ,A
ram:02356c 67 mov A,
ram:02356d 318e shrw AX,0x8
ram:02356f 12 movw BC,AX
ram:023570 c6 pop HL
ram:023571 d7 ret
ram:023572 c7 push HL
ram:023573 c1 push AX
ram:023574 c1 push AX
ram:023575 fbf8ff movw HL,!0xffff8
ram:023578 cc0100 mov [HL + 0x1],0x0
ram:02357b 8c02 mov A,[HL + 0x2]
ram:02357d 5003 mov ,0x3
ram:02357f d6 mulu X
ram:023580 12 movw BC,AX
ram:023581 49a963 mov A,!0xf63a9[BC]
ram:023584 4c51 cmp A,#0x51
ram:023586 df52 bnz $ 0x235da
ram:023588 49aa63 mov A,!0xf63aa[BC]
ram:02358b 4c4b cmp A,#0x4b
ram:02358d df4b bnz $ 0x235da
ram:02358f 8c02 mov A,[HL + 0x2]
ram:023591 73 mov ,A
ram:023592 09d4e9 mov A,!0xfe9d4[B]
ram:023595 9c01 mov [HL + 0x1],A
ram:023597 5c10 and A,#0x10
ram:023599 d1 cmp0 A
ram:02359a dd06 bz $ 0x235a2
ram:02359c 8c01 mov A,[HL + 0x1]
ram:02359e 5cef and A,#0xef
ram:0235a0 9c01 mov [HL + 0x1],A
ram:0235a2 af12e4 movw AX,!0xfe412
ram:0235a5 e7 onew BC
ram:0235a6 c3 push BC
ram:0235a7 12 movw BC,AX
ram:0235a8 17 movw AX,HL
ram:0235a9 c1 push AX
ram:0235aa 491600 mov A,!0xf0016[BC]
ram:0235ad 9dd4 mov 0xffdf4,A
ram:0235af 791400 movw AX,!0xf0014[BC]
ram:0235b2 c1 push AX
ram:0235b3 8dd4 mov A,0xffdf4
ram:0235b5 9dd6 mov 0xffdf6,A
ram:0235b7 c0 pop AX
ram:0235b8 14 movw DE,AX
ram:0235b9 304300 movw AX,0x43
ram:0235bc f7 clrw BC
ram:0235bd c1 push AX
ram:0235be 8dd6 mov A,0xffdf6
ram:0235c0 9efc mov CS,A
ram:0235c2 c0 pop AX
ram:0235c3 61ea call DE
ram:0235c5 1004 addw SP,0x4
ram:0235c7 8b mov A,[HL]
ram:0235c8 4c04 cmp A,#0x4
ram:0235ca dc08 bc $ 0x235d4
ram:0235cc 8c01 mov A,[HL + 0x1]
ram:0235ce 6c01 or A,#0x1
ram:0235d0 9c01 mov [HL + 0x1],A
ram:0235d2 ef06 br $ 0x235da
ram:0235d4 8c01 mov A,[HL + 0x1]
ram:0235d6 5cfe and A,#0xfe
ram:0235d8 9c01 mov [HL + 0x1],A
ram:0235da 8c01 mov A,[HL + 0x1]
ram:0235dc 5c01 and A,#0x1
ram:0235de d1 cmp0 A
ram:0235df dd06 bz $ 0x235e7
ram:0235e1 8c01 mov A,[HL + 0x1]
ram:0235e3 6c28 or A,#0x28
ram:0235e5 9c01 mov [HL + 0x1],A
ram:0235e7 8c01 mov A,[HL + 0x1]
ram:0235e9 318e shrw AX,0x8
ram:0235eb 12 movw BC,AX
ram:0235ec 1004 addw SP,0x4
ram:0235ee c6 pop HL
ram:0235ef d7 ret
ram:0235f0 c7 push HL
ram:0235f1 c1 push AX
ram:0235f2 c1 push AX
ram:0235f3 fbf8ff movw HL,!0xffff8
ram:0235f6 cc0100 mov [HL + 0x1],0x0
ram:0235f9 8c02 mov A,[HL + 0x2]
ram:0235fb 5003 mov ,0x3
ram:0235fd d6 mulu X
ram:0235fe 12 movw BC,AX
ram:0235ff 49a963 mov A,!0xf63a9[BC]
ram:023602 4ce3 cmp A,#0xe3
ram:023604 df52 bnz $ 0x23658
ram:023606 49aa63 mov A,!0xf63aa[BC]
ram:023609 4c4b cmp A,#0x4b
ram:02360b df4b bnz $ 0x23658
ram:02360d 8c02 mov A,[HL + 0x2]
ram:02360f 73 mov ,A
ram:023610 09d4e9 mov A,!0xfe9d4[B]
ram:023613 9c01 mov [HL + 0x1],A
ram:023615 5c10 and A,#0x10
ram:023617 d1 cmp0 A
ram:023618 dd06 bz $ 0x23620
ram:02361a 8c01 mov A,[HL + 0x1]
ram:02361c 5cef and A,#0xef
ram:02361e 9c01 mov [HL + 0x1],A
ram:023620 af12e4 movw AX,!0xfe412
ram:023623 e7 onew BC
ram:023624 c3 push BC
ram:023625 12 movw BC,AX
ram:023626 17 movw AX,HL
ram:023627 c1 push AX
ram:023628 491600 mov A,!0xf0016[BC]
ram:02362b 9dd4 mov 0xffdf4,A
ram:02362d 791400 movw AX,!0xf0014[BC]
ram:023630 c1 push AX
ram:023631 8dd4 mov A,0xffdf4
ram:023633 9dd6 mov 0xffdf6,A
ram:023635 c0 pop AX
ram:023636 14 movw DE,AX
ram:023637 304300 movw AX,0x43
ram:02363a f7 clrw BC
ram:02363b c1 push AX
ram:02363c 8dd6 mov A,0xffdf6
ram:02363e 9efc mov CS,A
ram:023640 c0 pop AX
ram:023641 61ea call DE
ram:023643 1004 addw SP,0x4
ram:023645 8b mov A,[HL]
ram:023646 4c04 cmp A,#0x4
ram:023648 dc08 bc $ 0x23652
ram:02364a 8c01 mov A,[HL + 0x1]
ram:02364c 6c01 or A,#0x1
ram:02364e 9c01 mov [HL + 0x1],A
ram:023650 ef06 br $ 0x23658
ram:023652 8c01 mov A,[HL + 0x1]
ram:023654 5cfe and A,#0xfe
ram:023656 9c01 mov [HL + 0x1],A
ram:023658 8c01 mov A,[HL + 0x1]
ram:02365a 5c01 and A,#0x1
ram:02365c d1 cmp0 A
ram:02365d dd06 bz $ 0x23665
ram:02365f 8c01 mov A,[HL + 0x1]
ram:023661 6c28 or A,#0x28
ram:023663 9c01 mov [HL + 0x1],A
ram:023665 8c01 mov A,[HL + 0x1]
ram:023667 318e shrw AX,0x8
ram:023669 12 movw BC,AX
ram:02366a 1004 addw SP,0x4
ram:02366c c6 pop HL
ram:02366d d7 ret
ram:02366e c7 push HL
ram:02366f c1 push AX
ram:023670 c1 push AX
ram:023671 fbf8ff movw HL,!0xffff8
ram:023674 cc0100 mov [HL + 0x1],0x0
ram:023677 8c02 mov A,[HL + 0x2]
ram:023679 5003 mov ,0x3
ram:02367b d6 mulu X
ram:02367c 12 movw BC,AX
ram:02367d 49a963 mov A,!0xf63a9[BC]
ram:023680 4c50 cmp A,#0x50
ram:023682 df51 bnz $ 0x236d5
ram:023684 49aa63 mov A,!0xf63aa[BC]
ram:023687 4c42 cmp A,#0x42
ram:023689 df4a bnz $ 0x236d5
ram:02368b 8c02 mov A,[HL + 0x2]
ram:02368d 73 mov ,A
ram:02368e 09d4e9 mov A,!0xfe9d4[B]
ram:023691 9c01 mov [HL + 0x1],A
ram:023693 5c10 and A,#0x10
ram:023695 d1 cmp0 A
ram:023696 dd06 bz $ 0x2369e
ram:023698 8c01 mov A,[HL + 0x1]
ram:02369a 5cef and A,#0xef
ram:02369c 9c01 mov [HL + 0x1],A
ram:02369e af12e4 movw AX,!0xfe412
ram:0236a1 e7 onew BC
ram:0236a2 c3 push BC
ram:0236a3 12 movw BC,AX
ram:0236a4 17 movw AX,HL
ram:0236a5 c1 push AX
ram:0236a6 491600 mov A,!0xf0016[BC]
ram:0236a9 9dd4 mov 0xffdf4,A
ram:0236ab 791400 movw AX,!0xf0014[BC]
ram:0236ae c1 push AX
ram:0236af 8dd4 mov A,0xffdf4
ram:0236b1 9dd6 mov 0xffdf6,A
ram:0236b3 c0 pop AX
ram:0236b4 14 movw DE,AX
ram:0236b5 304300 movw AX,0x43
ram:0236b8 f7 clrw BC
ram:0236b9 c1 push AX
ram:0236ba 8dd6 mov A,0xffdf6
ram:0236bc 9efc mov CS,A
ram:0236be c0 pop AX
ram:0236bf 61ea call DE
ram:0236c1 1004 addw SP,0x4
ram:0236c3 8b mov A,[HL]
ram:0236c4 d1 cmp0 A
ram:0236c5 df08 bnz $ 0x236cf
ram:0236c7 8c01 mov A,[HL + 0x1]
ram:0236c9 6c01 or A,#0x1
ram:0236cb 9c01 mov [HL + 0x1],A
ram:0236cd ef06 br $ 0x236d5
ram:0236cf 8c01 mov A,[HL + 0x1]
ram:0236d1 5cfe and A,#0xfe
ram:0236d3 9c01 mov [HL + 0x1],A
ram:0236d5 8c01 mov A,[HL + 0x1]
ram:0236d7 5c01 and A,#0x1
ram:0236d9 d1 cmp0 A
ram:0236da dd06 bz $ 0x236e2
ram:0236dc 8c01 mov A,[HL + 0x1]
ram:0236de 6c28 or A,#0x28
ram:0236e0 9c01 mov [HL + 0x1],A
ram:0236e2 8c01 mov A,[HL + 0x1]
ram:0236e4 318e shrw AX,0x8
ram:0236e6 12 movw BC,AX
ram:0236e7 1004 addw SP,0x4
ram:0236e9 c6 pop HL
ram:0236ea d7 ret
ram:0236eb c7 push HL
ram:0236ec c1 push AX
ram:0236ed c1 push AX
ram:0236ee fbf8ff movw HL,!0xffff8
ram:0236f1 cc0100 mov [HL + 0x1],0x0
ram:0236f4 8c02 mov A,[HL + 0x2]
ram:0236f6 5003 mov ,0x3
ram:0236f8 d6 mulu X
ram:0236f9 12 movw BC,AX
ram:0236fa 49a963 mov A,!0xf63a9[BC]
ram:0236fd 4c41 cmp A,#0x41
ram:0236ff df51 bnz $ 0x23752
ram:023701 49aa63 mov A,!0xf63aa[BC]
ram:023704 4c49 cmp A,#0x49
ram:023706 df4a bnz $ 0x23752
ram:023708 8c02 mov A,[HL + 0x2]
ram:02370a 73 mov ,A
ram:02370b 09d4e9 mov A,!0xfe9d4[B]
ram:02370e 9c01 mov [HL + 0x1],A
ram:023710 5c10 and A,#0x10
ram:023712 d1 cmp0 A
ram:023713 dd06 bz $ 0x2371b
ram:023715 8c01 mov A,[HL + 0x1]
ram:023717 5cef and A,#0xef
ram:023719 9c01 mov [HL + 0x1],A
ram:02371b af04e4 movw AX,!0xfe404
ram:02371e e7 onew BC
ram:02371f c3 push BC
ram:023720 12 movw BC,AX
ram:023721 17 movw AX,HL
ram:023722 c1 push AX
ram:023723 491600 mov A,!0xf0016[BC]
ram:023726 9dd4 mov 0xffdf4,A
ram:023728 791400 movw AX,!0xf0014[BC]
ram:02372b c1 push AX
ram:02372c 8dd4 mov A,0xffdf4
ram:02372e 9dd6 mov 0xffdf6,A
ram:023730 c0 pop AX
ram:023731 14 movw DE,AX
ram:023732 f6 clrw AX
ram:023733 320002 movw BC,0x200
ram:023736 c1 push AX
ram:023737 8dd6 mov A,0xffdf6
ram:023739 9efc mov CS,A
ram:02373b c0 pop AX
ram:02373c 61ea call DE
ram:02373e 1004 addw SP,0x4
ram:023740 8b mov A,[HL]
ram:023741 d1 cmp0 A
ram:023742 df08 bnz $ 0x2374c
ram:023744 8c01 mov A,[HL + 0x1]
ram:023746 5cfe and A,#0xfe
ram:023748 9c01 mov [HL + 0x1],A
ram:02374a ef06 br $ 0x23752
ram:02374c 8c01 mov A,[HL + 0x1]
ram:02374e 6c01 or A,#0x1
ram:023750 9c01 mov [HL + 0x1],A
ram:023752 8c01 mov A,[HL + 0x1]
ram:023754 5c01 and A,#0x1
ram:023756 d1 cmp0 A
ram:023757 dd06 bz $ 0x2375f
ram:023759 8c01 mov A,[HL + 0x1]
ram:02375b 6c28 or A,#0x28
ram:02375d 9c01 mov [HL + 0x1],A
ram:02375f 8c01 mov A,[HL + 0x1]
ram:023761 318e shrw AX,0x8
ram:023763 12 movw BC,AX
ram:023764 1004 addw SP,0x4
ram:023766 c6 pop HL
ram:023767 d7 ret
ram:023768 c7 push HL
ram:023769 c1 push AX
ram:02376a 2004 subw SP,0x4
ram:02376c fbf8ff movw HL,!0xffff8
ram:02376f cc0300 mov [HL + 0x3],0x0
ram:023772 8c04 mov A,[HL + 0x4]
ram:023774 5003 mov ,0x3
ram:023776 d6 mulu X
ram:023777 12 movw BC,AX
ram:023778 49a963 mov A,!0xf63a9[BC]
ram:02377b 4c41 cmp A,#0x41
ram:02377d df1a bnz $ 0x23799
ram:02377f 49aa63 mov A,!0xf63aa[BC]
ram:023782 4c55 cmp A,#0x55
ram:023784 df13 bnz $ 0x23799
ram:023786 8c04 mov A,[HL + 0x4]
ram:023788 73 mov ,A
ram:023789 09d4e9 mov A,!0xfe9d4[B]
ram:02378c 9c03 mov [HL + 0x3],A
ram:02378e 5c10 and A,#0x10
ram:023790 d1 cmp0 A
ram:023791 dd06 bz $ 0x23799
ram:023793 8c03 mov A,[HL + 0x3]
ram:023795 5cef and A,#0xef
ram:023797 9c03 mov [HL + 0x3],A
ram:023799 8c03 mov A,[HL + 0x3]
ram:02379b 5c01 and A,#0x1
ram:02379d d1 cmp0 A
ram:02379e dd06 bz $ 0x237a6
ram:0237a0 8c03 mov A,[HL + 0x3]
ram:0237a2 6c28 or A,#0x28
ram:0237a4 9c03 mov [HL + 0x3],A
ram:0237a6 8c03 mov A,[HL + 0x3]
ram:0237a8 318e shrw AX,0x8
ram:0237aa 12 movw BC,AX
ram:0237ab 1006 addw SP,0x6
ram:0237ad c6 pop HL
ram:0237ae d7 ret
ram:0237af c7 push HL
ram:0237b0 16 movw HL,AX
ram:0237b1 5700 mov ,0x0
ram:0237b3 66 mov A,
ram:0237b4 5003 mov ,0x3
ram:0237b6 d6 mulu X
ram:0237b7 12 movw BC,AX
ram:0237b8 49a963 mov A,!0xf63a9[BC]
ram:0237bb 4c42 cmp A,#0x42
ram:0237bd df16 bnz $ 0x237d5
ram:0237bf 49aa63 mov A,!0xf63aa[BC]
ram:0237c2 4c62 cmp A,#0x62
ram:0237c4 df0f bnz $ 0x237d5
ram:0237c6 66 mov A,
ram:0237c7 73 mov ,A
ram:0237c8 09d4e9 mov A,!0xfe9d4[B]
ram:0237cb 77 mov ,A
ram:0237cc 5c10 and A,#0x10
ram:0237ce d1 cmp0 A
ram:0237cf dd04 bz $ 0x237d5
ram:0237d1 51ef mov ,0xef
ram:0237d3 6157 and ,A
ram:0237d5 67 mov A,
ram:0237d6 5c01 and A,#0x1
ram:0237d8 d1 cmp0 A
ram:0237d9 dd04 bz $ 0x237df
ram:0237db 5128 mov ,0x28
ram:0237dd 6167 or ,A
ram:0237df 67 mov A,
ram:0237e0 318e shrw AX,0x8
ram:0237e2 12 movw BC,AX
ram:0237e3 c6 pop HL
ram:0237e4 d7 ret
ram:0237e5 c7 push HL
ram:0237e6 c1 push AX
ram:0237e7 c1 push AX
ram:0237e8 fbf8ff movw HL,!0xffff8
ram:0237eb cc0100 mov [HL + 0x1],0x0
ram:0237ee 8c02 mov A,[HL + 0x2]
ram:0237f0 5003 mov ,0x3
ram:0237f2 d6 mulu X
ram:0237f3 12 movw BC,AX
ram:0237f4 49a963 mov A,!0xf63a9[BC]
ram:0237f7 4ccf cmp A,#0xcf
ram:0237f9 df51 bnz $ 0x2384c
ram:0237fb 49aa63 mov A,!0xf63aa[BC]
ram:0237fe 4c73 cmp A,#0x73
ram:023800 df4a bnz $ 0x2384c
ram:023802 8c02 mov A,[HL + 0x2]
ram:023804 73 mov ,A
ram:023805 09d4e9 mov A,!0xfe9d4[B]
ram:023808 9c01 mov [HL + 0x1],A
ram:02380a 5c10 and A,#0x10
ram:02380c d1 cmp0 A
ram:02380d dd06 bz $ 0x23815
ram:02380f 8c01 mov A,[HL + 0x1]
ram:023811 5cef and A,#0xef
ram:023813 9c01 mov [HL + 0x1],A
ram:023815 af10e4 movw AX,!0xfe410
ram:023818 e7 onew BC
ram:023819 c3 push BC
ram:02381a 12 movw BC,AX
ram:02381b 17 movw AX,HL
ram:02381c c1 push AX
ram:02381d 491600 mov A,!0xf0016[BC]
ram:023820 9dd4 mov 0xffdf4,A
ram:023822 791400 movw AX,!0xf0014[BC]
ram:023825 c1 push AX
ram:023826 8dd4 mov A,0xffdf4
ram:023828 9dd6 mov 0xffdf6,A
ram:02382a c0 pop AX
ram:02382b 14 movw DE,AX
ram:02382c 304900 movw AX,0x49
ram:02382f f7 clrw BC
ram:023830 c1 push AX
ram:023831 8dd6 mov A,0xffdf6
ram:023833 9efc mov CS,A
ram:023835 c0 pop AX
ram:023836 61ea call DE
ram:023838 1004 addw SP,0x4
ram:02383a 8b mov A,[HL]
ram:02383b 91 dec 
ram:02383c df08 bnz $ 0x23846
ram:02383e 8c01 mov A,[HL + 0x1]
ram:023840 6c01 or A,#0x1
ram:023842 9c01 mov [HL + 0x1],A
ram:023844 ef06 br $ 0x2384c
ram:023846 8c01 mov A,[HL + 0x1]
ram:023848 5cfe and A,#0xfe
ram:02384a 9c01 mov [HL + 0x1],A
ram:02384c 8c01 mov A,[HL + 0x1]
ram:02384e 5c01 and A,#0x1
ram:023850 d1 cmp0 A
ram:023851 dd06 bz $ 0x23859
ram:023853 8c01 mov A,[HL + 0x1]
ram:023855 6c28 or A,#0x28
ram:023857 9c01 mov [HL + 0x1],A
ram:023859 8c01 mov A,[HL + 0x1]
ram:02385b 318e shrw AX,0x8
ram:02385d 12 movw BC,AX
ram:02385e 1004 addw SP,0x4
ram:023860 c6 pop HL
ram:023861 d7 ret
ram:023862 c7 push HL
ram:023863 c1 push AX
ram:023864 2004 subw SP,0x4
ram:023866 fbf8ff movw HL,!0xffff8
ram:023869 cc0300 mov [HL + 0x3],0x0
ram:02386c 8c04 mov A,[HL + 0x4]
ram:02386e 5003 mov ,0x3
ram:023870 d6 mulu X
ram:023871 12 movw BC,AX
ram:023872 49a963 mov A,!0xf63a9[BC]
ram:023875 4cf0 cmp A,#0xf0
ram:023877 61e8 skz
ram:023879 ee9a00 _br $! 0x23916
ram:02387c 8c04 mov A,[HL + 0x4]
ram:02387e 73 mov ,A
ram:02387f 09d4e9 mov A,!0xfe9d4[B]
ram:023882 9c03 mov [HL + 0x3],A
ram:023884 5c10 and A,#0x10
ram:023886 d1 cmp0 A
ram:023887 dd06 bz $ 0x2388f
ram:023889 8c03 mov A,[HL + 0x3]
ram:02388b 5cef and A,#0xef
ram:02388d 9c03 mov [HL + 0x3],A
ram:02388f 8c0c mov A,[HL + 0xc]
ram:023891 d1 cmp0 A
ram:023892 df36 bnz $ 0x238ca
ram:023894 8c04 mov A,[HL + 0x4]
ram:023896 5003 mov ,0x3
ram:023898 d6 mulu X
ram:023899 12 movw BC,AX
ram:02389a 49aa63 mov A,!0xf63aa[BC]
ram:02389d 4c17 cmp A,#0x17
ram:02389f df29 bnz $ 0x238ca
ram:0238a1 af12e4 movw AX,!0xfe412
ram:0238a4 e7 onew BC
ram:0238a5 a3 incw BC
ram:0238a6 c3 push BC
ram:0238a7 12 movw BC,AX
ram:0238a8 17 movw AX,HL
ram:0238a9 a1 incw AX
ram:0238aa c1 push AX
ram:0238ab 491600 mov A,!0xf0016[BC]
ram:0238ae 9dd4 mov 0xffdf4,A
ram:0238b0 791400 movw AX,!0xf0014[BC]
ram:0238b3 c1 push AX
ram:0238b4 8dd4 mov A,0xffdf4
ram:0238b6 9dd6 mov 0xffdf6,A
ram:0238b8 c0 pop AX
ram:0238b9 14 movw DE,AX
ram:0238ba 305100 movw AX,0x51
ram:0238bd f7 clrw BC
ram:0238be c1 push AX
ram:0238bf 8dd6 mov A,0xffdf6
ram:0238c1 9efc mov CS,A
ram:0238c3 c0 pop AX
ram:0238c4 61ea call DE
ram:0238c6 1004 addw SP,0x4
ram:0238c8 ef39 br $ 0x23903
ram:0238ca 8c0c mov A,[HL + 0xc]
ram:0238cc 91 dec 
ram:0238cd df34 bnz $ 0x23903
ram:0238cf 8c04 mov A,[HL + 0x4]
ram:0238d1 5003 mov ,0x3
ram:0238d3 d6 mulu X
ram:0238d4 12 movw BC,AX
ram:0238d5 49aa63 mov A,!0xf63aa[BC]
ram:0238d8 4c16 cmp A,#0x16
ram:0238da df27 bnz $ 0x23903
ram:0238dc af12e4 movw AX,!0xfe412
ram:0238df e7 onew BC
ram:0238e0 a3 incw BC
ram:0238e1 c3 push BC
ram:0238e2 12 movw BC,AX
ram:0238e3 17 movw AX,HL
ram:0238e4 a1 incw AX
ram:0238e5 c1 push AX
ram:0238e6 491600 mov A,!0xf0016[BC]
ram:0238e9 9dd4 mov 0xffdf4,A
ram:0238eb 791400 movw AX,!0xf0014[BC]
ram:0238ee c1 push AX
ram:0238ef 8dd4 mov A,0xffdf4
ram:0238f1 9dd6 mov 0xffdf6,A
ram:0238f3 c0 pop AX
ram:0238f4 14 movw DE,AX
ram:0238f5 305200 movw AX,0x52
ram:0238f8 f7 clrw BC
ram:0238f9 c1 push AX
ram:0238fa 8dd6 mov A,0xffdf6
ram:0238fc 9efc mov CS,A
ram:0238fe c0 pop AX
ram:0238ff 61ea call DE
ram:023901 1004 addw SP,0x4
ram:023903 8c01 mov A,[HL + 0x1]
ram:023905 91 dec 
ram:023906 df08 bnz $ 0x23910
ram:023908 8c03 mov A,[HL + 0x3]
ram:02390a 6c01 or A,#0x1
ram:02390c 9c03 mov [HL + 0x3],A
ram:02390e ef06 br $ 0x23916
ram:023910 8c03 mov A,[HL + 0x3]
ram:023912 5cfe and A,#0xfe
ram:023914 9c03 mov [HL + 0x3],A
ram:023916 8c03 mov A,[HL + 0x3]
ram:023918 5c01 and A,#0x1
ram:02391a d1 cmp0 A
ram:02391b dd06 bz $ 0x23923
ram:02391d 8c03 mov A,[HL + 0x3]
ram:02391f 6c28 or A,#0x28
ram:023921 9c03 mov [HL + 0x3],A
ram:023923 8c03 mov A,[HL + 0x3]
ram:023925 318e shrw AX,0x8
ram:023927 12 movw BC,AX
ram:023928 1006 addw SP,0x6
ram:02392a c6 pop HL
ram:02392b d7 ret
ram:02392c c7 push HL
ram:02392d c1 push AX
ram:02392e c1 push AX
ram:02392f fbf8ff movw HL,!0xffff8
ram:023932 cc0100 mov [HL + 0x1],0x0
ram:023935 8c02 mov A,[HL + 0x2]
ram:023937 5003 mov ,0x3
ram:023939 d6 mulu X
ram:02393a 12 movw BC,AX
ram:02393b 49a963 mov A,!0xf63a9[BC]
ram:02393e 4c15 cmp A,#0x15
ram:023940 df70 bnz $ 0x239b2
ram:023942 8c02 mov A,[HL + 0x2]
ram:023944 73 mov ,A
ram:023945 09d4e9 mov A,!0xfe9d4[B]
ram:023948 9c01 mov [HL + 0x1],A
ram:02394a 5c10 and A,#0x10
ram:02394c d1 cmp0 A
ram:02394d dd06 bz $ 0x23955
ram:02394f 8c01 mov A,[HL + 0x1]
ram:023951 5cef and A,#0xef
ram:023953 9c01 mov [HL + 0x1],A
ram:023955 af12e4 movw AX,!0xfe412
ram:023958 e7 onew BC
ram:023959 c3 push BC
ram:02395a 12 movw BC,AX
ram:02395b 17 movw AX,HL
ram:02395c c1 push AX
ram:02395d 491600 mov A,!0xf0016[BC]
ram:023960 9dd4 mov 0xffdf4,A
ram:023962 791400 movw AX,!0xf0014[BC]
ram:023965 c1 push AX
ram:023966 8dd4 mov A,0xffdf4
ram:023968 9dd6 mov 0xffdf6,A
ram:02396a c0 pop AX
ram:02396b 14 movw DE,AX
ram:02396c 304f00 movw AX,0x4f
ram:02396f f7 clrw BC
ram:023970 c1 push AX
ram:023971 8dd6 mov A,0xffdf6
ram:023973 9efc mov CS,A
ram:023975 c0 pop AX
ram:023976 61ea call DE
ram:023978 1004 addw SP,0x4
ram:02397a 8b mov A,[HL]
ram:02397b d1 cmp0 A
ram:02397c df15 bnz $ 0x23993
ram:02397e 8c02 mov A,[HL + 0x2]
ram:023980 5003 mov ,0x3
ram:023982 d6 mulu X
ram:023983 12 movw BC,AX
ram:023984 49aa63 mov A,!0xf63aa[BC]
ram:023987 4c11 cmp A,#0x11
ram:023989 df08 bnz $ 0x23993
ram:02398b 8c01 mov A,[HL + 0x1]
ram:02398d 6c01 or A,#0x1
ram:02398f 9c01 mov [HL + 0x1],A
ram:023991 ef1f br $ 0x239b2
ram:023993 8b mov A,[HL]
ram:023994 91 dec 
ram:023995 df15 bnz $ 0x239ac
ram:023997 8c02 mov A,[HL + 0x2]
ram:023999 5003 mov ,0x3
ram:02399b d6 mulu X
ram:02399c 12 movw BC,AX
ram:02399d 49aa63 mov A,!0xf63aa[BC]
ram:0239a0 4c13 cmp A,#0x13
ram:0239a2 df08 bnz $ 0x239ac
ram:0239a4 8c01 mov A,[HL + 0x1]
ram:0239a6 6c01 or A,#0x1
ram:0239a8 9c01 mov [HL + 0x1],A
ram:0239aa ef06 br $ 0x239b2
ram:0239ac 8c01 mov A,[HL + 0x1]
ram:0239ae 5cfe and A,#0xfe
ram:0239b0 9c01 mov [HL + 0x1],A
ram:0239b2 8c01 mov A,[HL + 0x1]
ram:0239b4 5c01 and A,#0x1
ram:0239b6 d1 cmp0 A
ram:0239b7 dd06 bz $ 0x239bf
ram:0239b9 8c01 mov A,[HL + 0x1]
ram:0239bb 6c28 or A,#0x28
ram:0239bd 9c01 mov [HL + 0x1],A
ram:0239bf 8c01 mov A,[HL + 0x1]
ram:0239c1 318e shrw AX,0x8
ram:0239c3 12 movw BC,AX
ram:0239c4 1004 addw SP,0x4
ram:0239c6 c6 pop HL
ram:0239c7 d7 ret
ram:0239c8 c7 push HL
ram:0239c9 c1 push AX
ram:0239ca c1 push AX
ram:0239cb fbf8ff movw HL,!0xffff8
ram:0239ce cc0100 mov [HL + 0x1],0x0
ram:0239d1 8c02 mov A,[HL + 0x2]
ram:0239d3 5003 mov ,0x3
ram:0239d5 d6 mulu X
ram:0239d6 12 movw BC,AX
ram:0239d7 49a963 mov A,!0xf63a9[BC]
ram:0239da 4c24 cmp A,#0x24
ram:0239dc df70 bnz $ 0x23a4e
ram:0239de 8c02 mov A,[HL + 0x2]
ram:0239e0 73 mov ,A
ram:0239e1 09d4e9 mov A,!0xfe9d4[B]
ram:0239e4 9c01 mov [HL + 0x1],A
ram:0239e6 5c10 and A,#0x10
ram:0239e8 d1 cmp0 A
ram:0239e9 dd06 bz $ 0x239f1
ram:0239eb 8c01 mov A,[HL + 0x1]
ram:0239ed 5cef and A,#0xef
ram:0239ef 9c01 mov [HL + 0x1],A
ram:0239f1 af12e4 movw AX,!0xfe412
ram:0239f4 e7 onew BC
ram:0239f5 c3 push BC
ram:0239f6 12 movw BC,AX
ram:0239f7 17 movw AX,HL
ram:0239f8 c1 push AX
ram:0239f9 491600 mov A,!0xf0016[BC]
ram:0239fc 9dd4 mov 0xffdf4,A
ram:0239fe 791400 movw AX,!0xf0014[BC]
ram:023a01 c1 push AX
ram:023a02 8dd4 mov A,0xffdf4
ram:023a04 9dd6 mov 0xffdf6,A
ram:023a06 c0 pop AX
ram:023a07 14 movw DE,AX
ram:023a08 304e00 movw AX,0x4e
ram:023a0b f7 clrw BC
ram:023a0c c1 push AX
ram:023a0d 8dd6 mov A,0xffdf6
ram:023a0f 9efc mov CS,A
ram:023a11 c0 pop AX
ram:023a12 61ea call DE
ram:023a14 1004 addw SP,0x4
ram:023a16 8b mov A,[HL]
ram:023a17 d1 cmp0 A
ram:023a18 df15 bnz $ 0x23a2f
ram:023a1a 8c02 mov A,[HL + 0x2]
ram:023a1c 5003 mov ,0x3
ram:023a1e d6 mulu X
ram:023a1f 12 movw BC,AX
ram:023a20 49aa63 mov A,!0xf63aa[BC]
ram:023a23 4c11 cmp A,#0x11
ram:023a25 df08 bnz $ 0x23a2f
ram:023a27 8c01 mov A,[HL + 0x1]
ram:023a29 6c01 or A,#0x1
ram:023a2b 9c01 mov [HL + 0x1],A
ram:023a2d ef1f br $ 0x23a4e
ram:023a2f 8b mov A,[HL]
ram:023a30 91 dec 
ram:023a31 df15 bnz $ 0x23a48
ram:023a33 8c02 mov A,[HL + 0x2]
ram:023a35 5003 mov ,0x3
ram:023a37 d6 mulu X
ram:023a38 12 movw BC,AX
ram:023a39 49aa63 mov A,!0xf63aa[BC]
ram:023a3c 4c13 cmp A,#0x13
ram:023a3e df08 bnz $ 0x23a48
ram:023a40 8c01 mov A,[HL + 0x1]
ram:023a42 6c01 or A,#0x1
ram:023a44 9c01 mov [HL + 0x1],A
ram:023a46 ef06 br $ 0x23a4e
ram:023a48 8c01 mov A,[HL + 0x1]
ram:023a4a 5cfe and A,#0xfe
ram:023a4c 9c01 mov [HL + 0x1],A
ram:023a4e 8c01 mov A,[HL + 0x1]
ram:023a50 5c01 and A,#0x1
ram:023a52 d1 cmp0 A
ram:023a53 dd06 bz $ 0x23a5b
ram:023a55 8c01 mov A,[HL + 0x1]
ram:023a57 6c28 or A,#0x28
ram:023a59 9c01 mov [HL + 0x1],A
ram:023a5b 8c01 mov A,[HL + 0x1]
ram:023a5d 318e shrw AX,0x8
ram:023a5f 12 movw BC,AX
ram:023a60 1004 addw SP,0x4
ram:023a62 c6 pop HL
ram:023a63 d7 ret
ram:023a64 c7 push HL
ram:023a65 c1 push AX
ram:023a66 c1 push AX
ram:023a67 fbf8ff movw HL,!0xffff8
ram:023a6a cc0100 mov [HL + 0x1],0x0
ram:023a6d 8c02 mov A,[HL + 0x2]
ram:023a6f 5003 mov ,0x3
ram:023a71 d6 mulu X
ram:023a72 12 movw BC,AX
ram:023a73 49a963 mov A,!0xf63a9[BC]
ram:023a76 4c03 cmp A,#0x3
ram:023a78 df70 bnz $ 0x23aea
ram:023a7a 8c02 mov A,[HL + 0x2]
ram:023a7c 73 mov ,A
ram:023a7d 09d4e9 mov A,!0xfe9d4[B]
ram:023a80 9c01 mov [HL + 0x1],A
ram:023a82 5c10 and A,#0x10
ram:023a84 d1 cmp0 A
ram:023a85 dd06 bz $ 0x23a8d
ram:023a87 8c01 mov A,[HL + 0x1]
ram:023a89 5cef and A,#0xef
ram:023a8b 9c01 mov [HL + 0x1],A
ram:023a8d af12e4 movw AX,!0xfe412
ram:023a90 e7 onew BC
ram:023a91 c3 push BC
ram:023a92 12 movw BC,AX
ram:023a93 17 movw AX,HL
ram:023a94 c1 push AX
ram:023a95 491600 mov A,!0xf0016[BC]
ram:023a98 9dd4 mov 0xffdf4,A
ram:023a9a 791400 movw AX,!0xf0014[BC]
ram:023a9d c1 push AX
ram:023a9e 8dd4 mov A,0xffdf4
ram:023aa0 9dd6 mov 0xffdf6,A
ram:023aa2 c0 pop AX
ram:023aa3 14 movw DE,AX
ram:023aa4 305300 movw AX,0x53
ram:023aa7 f7 clrw BC
ram:023aa8 c1 push AX
ram:023aa9 8dd6 mov A,0xffdf6
ram:023aab 9efc mov CS,A
ram:023aad c0 pop AX
ram:023aae 61ea call DE
ram:023ab0 1004 addw SP,0x4
ram:023ab2 8b mov A,[HL]
ram:023ab3 d1 cmp0 A
ram:023ab4 df15 bnz $ 0x23acb
ram:023ab6 8c02 mov A,[HL + 0x2]
ram:023ab8 5003 mov ,0x3
ram:023aba d6 mulu X
ram:023abb 12 movw BC,AX
ram:023abc 49aa63 mov A,!0xf63aa[BC]
ram:023abf 4c11 cmp A,#0x11
ram:023ac1 df08 bnz $ 0x23acb
ram:023ac3 8c01 mov A,[HL + 0x1]
ram:023ac5 6c01 or A,#0x1
ram:023ac7 9c01 mov [HL + 0x1],A
ram:023ac9 ef1f br $ 0x23aea
ram:023acb 8b mov A,[HL]
ram:023acc 91 dec 
ram:023acd df15 bnz $ 0x23ae4
ram:023acf 8c02 mov A,[HL + 0x2]
ram:023ad1 5003 mov ,0x3
ram:023ad3 d6 mulu X
ram:023ad4 12 movw BC,AX
ram:023ad5 49aa63 mov A,!0xf63aa[BC]
ram:023ad8 4c13 cmp A,#0x13
ram:023ada df08 bnz $ 0x23ae4
ram:023adc 8c01 mov A,[HL + 0x1]
ram:023ade 6c01 or A,#0x1
ram:023ae0 9c01 mov [HL + 0x1],A
ram:023ae2 ef06 br $ 0x23aea
ram:023ae4 8c01 mov A,[HL + 0x1]
ram:023ae6 5cfe and A,#0xfe
ram:023ae8 9c01 mov [HL + 0x1],A
ram:023aea 8c01 mov A,[HL + 0x1]
ram:023aec 5c01 and A,#0x1
ram:023aee d1 cmp0 A
ram:023aef dd06 bz $ 0x23af7
ram:023af1 8c01 mov A,[HL + 0x1]
ram:023af3 6c28 or A,#0x28
ram:023af5 9c01 mov [HL + 0x1],A
ram:023af7 8c01 mov A,[HL + 0x1]
ram:023af9 318e shrw AX,0x8
ram:023afb 12 movw BC,AX
ram:023afc 1004 addw SP,0x4
ram:023afe c6 pop HL
ram:023aff d7 ret
ram:023b00 c7 push HL
ram:023b01 c1 push AX
ram:023b02 c1 push AX
ram:023b03 fbf8ff movw HL,!0xffff8
ram:023b06 cc0100 mov [HL + 0x1],0x0
ram:023b09 8c02 mov A,[HL + 0x2]
ram:023b0b 5003 mov ,0x3
ram:023b0d d6 mulu X
ram:023b0e 12 movw BC,AX
ram:023b0f 49a963 mov A,!0xf63a9[BC]
ram:023b12 4c28 cmp A,#0x28
ram:023b14 df79 bnz $ 0x23b8f
ram:023b16 8c02 mov A,[HL + 0x2]
ram:023b18 73 mov ,A
ram:023b19 09d4e9 mov A,!0xfe9d4[B]
ram:023b1c 9c01 mov [HL + 0x1],A
ram:023b1e 5c10 and A,#0x10
ram:023b20 d1 cmp0 A
ram:023b21 dd06 bz $ 0x23b29
ram:023b23 8c01 mov A,[HL + 0x1]
ram:023b25 5cef and A,#0xef
ram:023b27 9c01 mov [HL + 0x1],A
ram:023b29 3154015f bf 0xffe21.0x5,$ 0x23b8a
ram:023b2d af12e4 movw AX,!0xfe412
ram:023b30 e7 onew BC
ram:023b31 c3 push BC
ram:023b32 12 movw BC,AX
ram:023b33 17 movw AX,HL
ram:023b34 c1 push AX
ram:023b35 491600 mov A,!0xf0016[BC]
ram:023b38 9dd4 mov 0xffdf4,A
ram:023b3a 791400 movw AX,!0xf0014[BC]
ram:023b3d c1 push AX
ram:023b3e 8dd4 mov A,0xffdf4
ram:023b40 9dd6 mov 0xffdf6,A
ram:023b42 c0 pop AX
ram:023b43 14 movw DE,AX
ram:023b44 305000 movw AX,0x50
ram:023b47 f7 clrw BC
ram:023b48 c1 push AX
ram:023b49 8dd6 mov A,0xffdf6
ram:023b4b 9efc mov CS,A
ram:023b4d c0 pop AX
ram:023b4e 61ea call DE
ram:023b50 1004 addw SP,0x4
ram:023b52 8b mov A,[HL]
ram:023b53 d1 cmp0 A
ram:023b54 df15 bnz $ 0x23b6b
ram:023b56 8c02 mov A,[HL + 0x2]
ram:023b58 5003 mov ,0x3
ram:023b5a d6 mulu X
ram:023b5b 12 movw BC,AX
ram:023b5c 49aa63 mov A,!0xf63aa[BC]
ram:023b5f 4c11 cmp A,#0x11
ram:023b61 df08 bnz $ 0x23b6b
ram:023b63 8c01 mov A,[HL + 0x1]
ram:023b65 6c01 or A,#0x1
ram:023b67 9c01 mov [HL + 0x1],A
ram:023b69 ef24 br $ 0x23b8f
ram:023b6b 8b mov A,[HL]
ram:023b6c 91 dec 
ram:023b6d df15 bnz $ 0x23b84
ram:023b6f 8c02 mov A,[HL + 0x2]
ram:023b71 5003 mov ,0x3
ram:023b73 d6 mulu X
ram:023b74 12 movw BC,AX
ram:023b75 49aa63 mov A,!0xf63aa[BC]
ram:023b78 4c13 cmp A,#0x13
ram:023b7a df08 bnz $ 0x23b84
ram:023b7c 8c01 mov A,[HL + 0x1]
ram:023b7e 6c01 or A,#0x1
ram:023b80 9c01 mov [HL + 0x1],A
ram:023b82 ef0b br $ 0x23b8f
ram:023b84 8c01 mov A,[HL + 0x1]
ram:023b86 5cfe and A,#0xfe
ram:023b88 9c01 mov [HL + 0x1],A
ram:023b8a ef03 br $ 0x23b8f
ram:023b8c cc0110 mov [HL + 0x1],0x10
ram:023b8f 8c01 mov A,[HL + 0x1]
ram:023b91 5c01 and A,#0x1
ram:023b93 d1 cmp0 A
ram:023b94 dd06 bz $ 0x23b9c
ram:023b96 8c01 mov A,[HL + 0x1]
ram:023b98 6c28 or A,#0x28
ram:023b9a 9c01 mov [HL + 0x1],A
ram:023b9c 8c01 mov A,[HL + 0x1]
ram:023b9e 318e shrw AX,0x8
ram:023ba0 12 movw BC,AX
ram:023ba1 1004 addw SP,0x4
ram:023ba3 c6 pop HL
ram:023ba4 d7 ret
ram:0240e7 c7 push HL
ram:0240e8 c1 push AX
ram:0240e9 fbf8ff movw HL,!0xffff8
ram:0240ec 8f0aea mov A,!0xfea0a
ram:0240ef 310503 bf A.0x0,$ 0x240f4
ram:0240f2 e1 oneb A
ram:0240f3 ef01 br $ 0x240f6
ram:0240f5 f1 clrb A
ram:0240f6 9b mov [HL],A
ram:0240f7 8f0bea mov A,!0xfea0b
ram:0240fa 310503 bf A.0x0,$ 0x240ff
ram:0240fd e1 oneb A
ram:0240fe ef01 br $ 0x24101
ram:024100 f1 clrb A
ram:024101 9c01 mov [HL + 0x1],A
ram:024103 af02e4 movw AX,!0xfe402
ram:024106 e7 onew BC
ram:024107 a3 incw BC
ram:024108 c3 push BC
ram:024109 12 movw BC,AX
ram:02410a 17 movw AX,HL
ram:02410b c1 push AX
ram:02410c 491200 mov A,!0xf0012[BC]
ram:02410f 9dd4 mov 0xffdf4,A
ram:024111 791000 movw AX,!0xf0010[BC]
ram:024114 c1 push AX
ram:024115 8dd4 mov A,0xffdf4
ram:024117 9dd6 mov 0xffdf6,A
ram:024119 c0 pop AX
ram:02411a 14 movw DE,AX
ram:02411b 300600 movw AX,0x6
ram:02411e f7 clrw BC
ram:02411f c1 push AX
ram:024120 8dd6 mov A,0xffdf6
ram:024122 9efc mov CS,A
ram:024124 c0 pop AX
ram:024125 61ea call DE
ram:024127 1004 addw SP,0x4
ram:024129 c0 pop AX
ram:02412a c6 pop HL
ram:02412b d7 ret
ram:02412c c7 push HL
ram:02412d c1 push AX
ram:02412e 2004 subw SP,0x4
ram:024130 fbf8ff movw HL,!0xffff8
ram:024133 cc0200 mov [HL + 0x2],0x0
ram:024136 cc0100 mov [HL + 0x1],0x0
ram:024139 af02e4 movw AX,!0xfe402
ram:02413c e7 onew BC
ram:02413d c3 push BC
ram:02413e 12 movw BC,AX
ram:02413f 17 movw AX,HL
ram:024140 a1 incw AX
ram:024141 c1 push AX
ram:024142 491600 mov A,!0xf0016[BC]
ram:024145 9dd4 mov 0xffdf4,A
ram:024147 791400 movw AX,!0xf0014[BC]
ram:02414a c1 push AX
ram:02414b 8dd4 mov A,0xffdf4
ram:02414d 9dd6 mov 0xffdf6,A
ram:02414f c0 pop AX
ram:024150 14 movw DE,AX
ram:024151 300300 movw AX,0x3
ram:024154 f7 clrw BC
ram:024155 c1 push AX
ram:024156 8dd6 mov A,0xffdf6
ram:024158 9efc mov CS,A
ram:02415a c0 pop AX
ram:02415b 61ea call DE
ram:02415d 1004 addw SP,0x4
ram:02415f 8c01 mov A,[HL + 0x1]
ram:024161 91 dec 
ram:024162 dd09 bz $ 0x2416d
ram:024164 8febe1 mov A,!0xfe1eb
ram:024167 312303 bt A.0x2,$ 0x2416c
ram:02416a ee2002 br $! 0x2438d
ram:02416d 8ffbe9 mov A,!0xfe9fb
ram:024170 5c0e and A,#0xe
ram:024172 61e8 skz
ram:024174 ee0402 _br $! 0x2437b
ram:024177 cc0300 mov [HL + 0x3],0x0
ram:02417a 8c03 mov A,[HL + 0x3]
ram:02417c 4c24 cmp A,#0x24
ram:02417e 61c8 skc
ram:024180 eef601 _br $! 0x24379
ram:024183 8c03 mov A,[HL + 0x3]
ram:024185 d1 cmp0 A
ram:024186 dc14 bc $ 0x2419c
ram:024188 8c03 mov A,[HL + 0x3]
ram:02418a 4c08 cmp A,#0x8
ram:02418c de0e bnc $ 0x2419c
ram:02418e 8c03 mov A,[HL + 0x3]
ram:024190 318e shrw AX,0x8
ram:024192 fc3d3302 call !!0x2333d
ram:024196 62 mov A,
ram:024197 9c02 mov [HL + 0x2],A
ram:024199 eed900 br $! 0x24275
ram:02419c 8c03 mov A,[HL + 0x3]
ram:02419e 4c08 cmp A,#0x8
ram:0241a0 df0e bnz $ 0x241b0
ram:0241a2 8c03 mov A,[HL + 0x3]
ram:0241a4 318e shrw AX,0x8
ram:0241a6 fc0c3502 call !!0x2350c
ram:0241aa 62 mov A,
ram:0241ab 9c02 mov [HL + 0x2],A
ram:0241ad eec500 br $! 0x24275
ram:0241b0 8c03 mov A,[HL + 0x3]
ram:0241b2 4c09 cmp A,#0x9
ram:0241b4 df0e bnz $ 0x241c4
ram:0241b6 8c03 mov A,[HL + 0x3]
ram:0241b8 318e shrw AX,0x8
ram:0241ba fc423502 call !!0x23542
ram:0241be 62 mov A,
ram:0241bf 9c02 mov [HL + 0x2],A
ram:0241c1 eeb100 br $! 0x24275
ram:0241c4 8c03 mov A,[HL + 0x3]
ram:0241c6 4c0a cmp A,#0xa
ram:0241c8 df0e bnz $ 0x241d8
ram:0241ca 8c03 mov A,[HL + 0x3]
ram:0241cc 318e shrw AX,0x8
ram:0241ce fc723502 call !!0x23572
ram:0241d2 62 mov A,
ram:0241d3 9c02 mov [HL + 0x2],A
ram:0241d5 ee9d00 br $! 0x24275
ram:0241d8 8c03 mov A,[HL + 0x3]
ram:0241da 4c0b cmp A,#0xb
ram:0241dc df0e bnz $ 0x241ec
ram:0241de 8c03 mov A,[HL + 0x3]
ram:0241e0 318e shrw AX,0x8
ram:0241e2 fcf03502 call !!0x235f0
ram:0241e6 62 mov A,
ram:0241e7 9c02 mov [HL + 0x2],A
ram:0241e9 ee8900 br $! 0x24275
ram:0241ec 8c03 mov A,[HL + 0x3]
ram:0241ee 4c0c cmp A,#0xc
ram:0241f0 df0d bnz $ 0x241ff
ram:0241f2 8c03 mov A,[HL + 0x3]
ram:0241f4 318e shrw AX,0x8
ram:0241f6 fc6e3602 call !!0x2366e
ram:0241fa 62 mov A,
ram:0241fb 9c02 mov [HL + 0x2],A
ram:0241fd ef76 br $ 0x24275
ram:0241ff 8c03 mov A,[HL + 0x3]
ram:024201 4c0d cmp A,#0xd
ram:024203 df0d bnz $ 0x24212
ram:024205 8c03 mov A,[HL + 0x3]
ram:024207 318e shrw AX,0x8
ram:024209 fceb3602 call !!0x236eb
ram:02420d 62 mov A,
ram:02420e 9c02 mov [HL + 0x2],A
ram:024210 ef63 br $ 0x24275
ram:024212 8c03 mov A,[HL + 0x3]
ram:024214 4c0e cmp A,#0xe
ram:024216 df0d bnz $ 0x24225
ram:024218 8c03 mov A,[HL + 0x3]
ram:02421a 318e shrw AX,0x8
ram:02421c fc683702 call !!0x23768
ram:024220 62 mov A,
ram:024221 9c02 mov [HL + 0x2],A
ram:024223 ef50 br $ 0x24275
ram:024225 8c03 mov A,[HL + 0x3]
ram:024227 4c0f cmp A,#0xf
ram:024229 df0d bnz $ 0x24238
ram:02422b 8c03 mov A,[HL + 0x3]
ram:02422d 318e shrw AX,0x8
ram:02422f fcaf3702 call !!0x237af
ram:024233 62 mov A,
ram:024234 9c02 mov [HL + 0x2],A
ram:024236 ef3d br $ 0x24275
ram:024238 8c03 mov A,[HL + 0x3]
ram:02423a 4c10 cmp A,#0x10
ram:02423c df0d bnz $ 0x2424b
ram:02423e 8c03 mov A,[HL + 0x3]
ram:024240 318e shrw AX,0x8
ram:024242 fce53702 call !!0x237e5
ram:024246 62 mov A,
ram:024247 9c02 mov [HL + 0x2],A
ram:024249 ef2a br $ 0x24275
ram:02424b 8c03 mov A,[HL + 0x3]
ram:02424d 4c11 cmp A,#0x11
ram:02424f df10 bnz $ 0x24261
ram:024251 f6 clrw AX
ram:024252 c1 push AX
ram:024253 8c03 mov A,[HL + 0x3]
ram:024255 318e shrw AX,0x8
ram:024257 fc623802 call !!0x23862
ram:02425b c0 pop AX
ram:02425c 62 mov A,
ram:02425d 9c02 mov [HL + 0x2],A
ram:02425f ef14 br $ 0x24275
ram:024261 8c03 mov A,[HL + 0x3]
ram:024263 4c12 cmp A,#0x12
ram:024265 df0e bnz $ 0x24275
ram:024267 e6 onew AX
ram:024268 c1 push AX
ram:024269 8c03 mov A,[HL + 0x3]
ram:02426b 318e shrw AX,0x8
ram:02426d fc623802 call !!0x23862
ram:024271 c0 pop AX
ram:024272 62 mov A,
ram:024273 9c02 mov [HL + 0x2],A
ram:024275 8c03 mov A,[HL + 0x3]
ram:024277 4c13 cmp A,#0x13
ram:024279 dc1f bc $ 0x2429a
ram:02427b 8c03 mov A,[HL + 0x3]
ram:02427d 4c1b cmp A,#0x1b
ram:02427f de19 bnc $ 0x2429a
ram:024281 8f0bea mov A,!0xfea0b
ram:024284 31430d bt A.0x4,$ 0x24293
ram:024287 8c03 mov A,[HL + 0x3]
ram:024289 318e shrw AX,0x8
ram:02428b fc3d3302 call !!0x2333d
ram:02428f 62 mov A,
ram:024290 9c02 mov [HL + 0x2],A
ram:024292 ef06 br $ 0x2429a
ram:024294 8c03 mov A,[HL + 0x3]
ram:024296 0c08 add A,#0x8
ram:024298 9c03 mov [HL + 0x3],A
ram:02429a 8c03 mov A,[HL + 0x3]
ram:02429c 4c1b cmp A,#0x1b
ram:02429e dc1f bc $ 0x242bf
ram:0242a0 8c03 mov A,[HL + 0x3]
ram:0242a2 4c1d cmp A,#0x1d
ram:0242a4 de19 bnc $ 0x242bf
ram:0242a6 8f0aea mov A,!0xfea0a
ram:0242a9 31050d bf A.0x0,$ 0x242b8
ram:0242ac 8c03 mov A,[HL + 0x3]
ram:0242ae 318e shrw AX,0x8
ram:0242b0 fc2c3902 call !!0x2392c
ram:0242b4 62 mov A,
ram:0242b5 9c02 mov [HL + 0x2],A
ram:0242b7 ef06 br $ 0x242bf
ram:0242b9 8c03 mov A,[HL + 0x3]
ram:0242bb 0c02 add A,#0x2
ram:0242bd 9c03 mov [HL + 0x3],A
ram:0242bf 8c03 mov A,[HL + 0x3]
ram:0242c1 4c1d cmp A,#0x1d
ram:0242c3 dc22 bc $ 0x242e7
ram:0242c5 8c03 mov A,[HL + 0x3]
ram:0242c7 4c1f cmp A,#0x1f
ram:0242c9 de1c bnc $ 0x242e7
ram:0242cb 8f0bea mov A,!0xfea0b
ram:0242ce 310503 bf A.0x0,$ 0x242d3
ram:0242d1 311308 bt A.0x1,$ 0x242db
ram:0242d4 8c03 mov A,[HL + 0x3]
ram:0242d6 0c03 add A,#0x3
ram:0242d8 9c03 mov [HL + 0x3],A
ram:0242da ef0b br $ 0x242e7
ram:0242dc 8c03 mov A,[HL + 0x3]
ram:0242de 318e shrw AX,0x8
ram:0242e0 fc643a02 call !!0x23a64
ram:0242e4 62 mov A,
ram:0242e5 9c02 mov [HL + 0x2],A
ram:0242e7 8c03 mov A,[HL + 0x3]
ram:0242e9 4c1f cmp A,#0x1f
ram:0242eb 61f8 sknz
ram:0242ed 615903 _inc [HL + 0x3]
ram:0242f0 8c03 mov A,[HL + 0x3]
ram:0242f2 4c20 cmp A,#0x20
ram:0242f4 dc1f bc $ 0x24315
ram:0242f6 8c03 mov A,[HL + 0x3]
ram:0242f8 4c22 cmp A,#0x22
ram:0242fa de19 bnc $ 0x24315
ram:0242fc 8f0bea mov A,!0xfea0b
ram:0242ff 31330d bt A.0x3,$ 0x2430e
ram:024302 8c03 mov A,[HL + 0x3]
ram:024304 318e shrw AX,0x8
ram:024306 fcc83902 call !!0x239c8
ram:02430a 62 mov A,
ram:02430b 9c02 mov [HL + 0x2],A
ram:02430d ef06 br $ 0x24315
ram:02430f 8c03 mov A,[HL + 0x3]
ram:024311 0c02 add A,#0x2
ram:024313 9c03 mov [HL + 0x3],A
ram:024315 8c03 mov A,[HL + 0x3]
ram:024317 4c22 cmp A,#0x22
ram:024319 dc50 bc $ 0x2436b
ram:02431b 8c03 mov A,[HL + 0x3]
ram:02431d 4c24 cmp A,#0x24
ram:02431f de4a bnc $ 0x2436b
ram:024321 8f0aea mov A,!0xfea0a
ram:024324 31533e bt A.0x5,$ 0x24364
ram:024327 cc0000 mov [HL + 0x0],0x0
ram:02432a af02e4 movw AX,!0xfe402
ram:02432d e7 onew BC
ram:02432e c3 push BC
ram:02432f 12 movw BC,AX
ram:024330 17 movw AX,HL
ram:024331 c1 push AX
ram:024332 491600 mov A,!0xf0016[BC]
ram:024335 9dd4 mov 0xffdf4,A
ram:024337 791400 movw AX,!0xf0014[BC]
ram:02433a c1 push AX
ram:02433b 8dd4 mov A,0xffdf4
ram:02433d 9dd6 mov 0xffdf6,A
ram:02433f c0 pop AX
ram:024340 14 movw DE,AX
ram:024341 300300 movw AX,0x3
ram:024344 f7 clrw BC
ram:024345 c1 push AX
ram:024346 8dd6 mov A,0xffdf6
ram:024348 9efc mov CS,A
ram:02434a c0 pop AX
ram:02434b 61ea call DE
ram:02434d 1004 addw SP,0x4
ram:02434f 8b mov A,[HL]
ram:024350 91 dec 
ram:024351 df0d bnz $ 0x24360
ram:024353 8c03 mov A,[HL + 0x3]
ram:024355 318e shrw AX,0x8
ram:024357 fc003b02 call !!0x23b00
ram:02435b 62 mov A,
ram:02435c 9c02 mov [HL + 0x2],A
ram:02435e ef0b br $ 0x2436b
ram:024360 cc0210 mov [HL + 0x2],0x10
ram:024363 ef06 br $ 0x2436b
ram:024365 8c03 mov A,[HL + 0x3]
ram:024367 0c02 add A,#0x2
ram:024369 9c03 mov [HL + 0x3],A
ram:02436b 8c03 mov A,[HL + 0x3]
ram:02436d 73 mov ,A
ram:02436e 8c02 mov A,[HL + 0x2]
ram:024370 18d4e9 mov !0xfe9d4[B],A
ram:024373 615903 inc [HL + 0x3]
ram:024376 ee01fe br $! 0x2417a
ram:024379 ef12 br $ 0x2438d
ram:02437b 8ffbe9 mov A,!0xfe9fb
ram:02437e 2c02 sub A,#0x2
ram:024380 5c0e and A,#0xe
ram:024382 70 mov ,A
ram:024383 8ffbe9 mov A,!0xfe9fb
ram:024386 5cf1 and A,#0xf1
ram:024388 6168 or A,
ram:02438a 9ffbe9 mov !0xfe9fb,A
ram:02438d d5d2e9 cmp0 !0xfe9d2
ram:024390 dd55 bz $ 0x243e7
ram:024392 40d2e904 cmp !0xfe9d2,0x4
ram:024396 df20 bnz $ 0x243b8
ram:024398 eb0ce4 movw DE,!0xfe40c
ram:02439b 8a0a mov A,[DE + 0xa]
ram:02439d 9efc mov CS,A
ram:02439f aa08 movw AX,[DE + 0x8]
ram:0243a1 61ca call AX
ram:0243a3 d2 cmp0 C
ram:0243a4 df41 bnz $ 0x243e7
ram:0243a6 eb0ce4 movw DE,!0xfe40c
ram:0243a9 8a02 mov A,[DE + 0x2]
ram:0243ab 9efc mov CS,A
ram:0243ad a9 movw AX,[DE]
ram:0243ae 14 movw DE,AX
ram:0243af e6 onew AX
ram:0243b0 61ea call DE
ram:0243b2 cfd2e905 mov !0xfe9d2,0x5
ram:0243b6 ef2f br $ 0x243e7
ram:0243b8 40d2e905 cmp !0xfe9d2,0x5
ram:0243bc df26 bnz $ 0x243e4
ram:0243be eb0ce4 movw DE,!0xfe40c
ram:0243c1 8a0a mov A,[DE + 0xa]
ram:0243c3 9efc mov CS,A
ram:0243c5 aa08 movw AX,[DE + 0x8]
ram:0243c7 61ca call AX
ram:0243c9 62 mov A,
ram:0243ca 4c03 cmp A,#0x3
ram:0243cc df19 bnz $ 0x243e7
ram:0243ce af0ce4 movw AX,!0xfe40c
ram:0243d1 f7 clrw BC
ram:0243d2 c3 push BC
ram:0243d3 14 movw DE,AX
ram:0243d4 8a0e mov A,[DE + 0xe]
ram:0243d6 9efc mov CS,A
ram:0243d8 aa0c movw AX,[DE + 0xc]
ram:0243da 14 movw DE,AX
ram:0243db e6 onew AX
ram:0243dc 61ea call DE
ram:0243de c0 pop AX
ram:0243df f5d2e9 clrb !0xfe9d2
ram:0243e2 ef03 br $ 0x243e7
ram:0243e4 a0d2e9 inc !0xfe9d2
ram:0243e7 e7 onew BC
ram:0243e8 1006 addw SP,0x6
ram:0243ea c6 pop HL
ram:0243eb d7 ret
ram:024481 c7 push HL
ram:024482 c1 push AX
ram:024483 2004 subw SP,0x4
ram:024485 fbf8ff movw HL,!0xffff8
ram:024488 cc0100 mov [HL + 0x1],0x0
ram:02448b 8ffae9 mov A,!0xfe9fa
ram:02448e 5c38 and A,#0x38
ram:024490 61f8 sknz
ram:024492 ee7f00 _br $! 0x24514
ram:024495 af02e4 movw AX,!0xfe402
ram:024498 e7 onew BC
ram:024499 c3 push BC
ram:02449a 12 movw BC,AX
ram:02449b 17 movw AX,HL
ram:02449c a1 incw AX
ram:02449d c1 push AX
ram:02449e 491600 mov A,!0xf0016[BC]
ram:0244a1 9dd4 mov 0xffdf4,A
ram:0244a3 791400 movw AX,!0xf0014[BC]
ram:0244a6 c1 push AX
ram:0244a7 8dd4 mov A,0xffdf4
ram:0244a9 9dd6 mov 0xffdf6,A
ram:0244ab c0 pop AX
ram:0244ac 14 movw DE,AX
ram:0244ad 300300 movw AX,0x3
ram:0244b0 f7 clrw BC
ram:0244b1 c1 push AX
ram:0244b2 8dd6 mov A,0xffdf6
ram:0244b4 9efc mov CS,A
ram:0244b6 c0 pop AX
ram:0244b7 61ea call DE
ram:0244b9 1004 addw SP,0x4
ram:0244bb 8c01 mov A,[HL + 0x1]
ram:0244bd 91 dec 
ram:0244be df37 bnz $ 0x244f7
ram:0244c0 8ffae9 mov A,!0xfe9fa
ram:0244c3 5c38 and A,#0x38
ram:0244c5 4c18 cmp A,#0x18
ram:0244c7 df2e bnz $ 0x244f7
ram:0244c9 cc0208 mov [HL + 0x2],0x8
ram:0244cc cc0300 mov [HL + 0x3],0x0
ram:0244cf 40d3e901 cmp !0xfe9d3,0x1
ram:0244d3 df1f bnz $ 0x244f4
ram:0244d5 8c03 mov A,[HL + 0x3]
ram:0244d7 0c02 add A,#0x2
ram:0244d9 318e shrw AX,0x8
ram:0244db c1 push AX
ram:0244dc 17 movw AX,HL
ram:0244dd 040200 addw AX,0x2
ram:0244e0 c1 push AX
ram:0244e1 306000 movw AX,0x60
ram:0244e4 c1 push AX
ram:0244e5 e6 onew AX
ram:0244e6 a1 incw AX
ram:0244e7 c1 push AX
ram:0244e8 e6 onew AX
ram:0244e9 fcb75401 call !!0x154b7
ram:0244ed 1008 addw SP,0x8
ram:0244ef f5d3e9 clrb !0xfe9d3
ram:0244f2 ef03 br $ 0x244f7
ram:0244f4 a0d3e9 inc !0xfe9d3
ram:0244f7 8ffbe9 mov A,!0xfe9fb
ram:0244fa 310304 bt A.0x0,$ 0x24500
ram:0244fd 7100fbe9 set1 !0xfe9fb.0x0
ram:024501 8ffae9 mov A,!0xfe9fa
ram:024504 2c08 sub A,#0x8
ram:024506 5c38 and A,#0x38
ram:024508 34fae9 movw DE,0xe9fa
ram:02450b 70 mov ,A
ram:02450c 89 mov A,[DE]
ram:02450d 5cc7 and A,#0xc7
ram:02450f 6168 or A,
ram:024511 99 mov [DE],A
ram:024512 ef0a br $ 0x2451e
ram:024514 8ffbe9 mov A,!0xfe9fb
ram:024517 310504 bf A.0x0,$ 0x2451d
ram:02451a 7108fbe9 clr1 !0xfe9fb.0x0
ram:02451e e7 onew BC
ram:02451f 1006 addw SP,0x6
ram:024521 c6 pop HL
ram:024522 d7 ret
ram:0267c8 c7 push HL
ram:0267c9 c1 push AX
ram:0267ca 200a subw SP,0xa
ram:0267cc fbf8ff movw HL,!0xffff8
ram:0267cf 8c0a mov A,[HL + 0xa]
ram:0267d1 91 dec 
ram:0267d2 61e8 skz
ram:0267d4 eeeb01 _br $! 0x269c2
ram:0267d7 e5f8e9 oneb !0xfe9f8
ram:0267da 34fae9 movw DE,0xe9fa
ram:0267dd 89 mov A,[DE]
ram:0267de 5cc7 and A,#0xc7
ram:0267e0 99 mov [DE],A
ram:0267e1 f5fce9 clrb !0xfe9fc
ram:0267e4 f5fde9 clrb !0xfe9fd
ram:0267e7 89 mov A,[DE]
ram:0267e8 5c3f and A,#0x3f
ram:0267ea 99 mov [DE],A
ram:0267eb 7108fbe9 clr1 !0xfe9fb.0x0
ram:0267ef 8a01 mov A,[DE + 0x1]
ram:0267f1 5cf1 and A,#0xf1
ram:0267f3 6c08 or A,#0x8
ram:0267f5 9a01 mov [DE + 0x1],A
ram:0267f7 f543ea clrb !0xfea43
ram:0267fa f5fee9 clrb !0xfe9fe
ram:0267fd f5ffe9 clrb !0xfe9ff
ram:026800 3000a4 movw AX,0xa400
ram:026803 bf30ea movw !0xfea30,AX
ram:026806 cf32ea03 mov !0xfea32,0x3
ram:02680a 51a8 mov ,0xa8
ram:02680c bf34ea movw !0xfea34,AX
ram:02680f cf36ea03 mov !0xfea36,0x3
ram:026813 5180 mov ,0x80
ram:026815 bf38ea movw !0xfea38,AX
ram:026818 cf3aea03 mov !0xfea3a,0x3
ram:02681c 5188 mov ,0x88
ram:02681e bf3cea movw !0xfea3c,AX
ram:026821 cf3eea03 mov !0xfea3e,0x3
ram:026825 3400b4 movw DE,0xb400
ram:026828 15 movw AX,DE
ram:026829 bc06 movw [HL + 0x6],AX
ram:02682b cc0803 mov [HL + 0x8],0x3
ram:02682e 3000ea movw AX,0xea00
ram:026831 bc04 movw [HL + 0x4],AX
ram:026833 cc0300 mov [HL + 0x3],0x0
ram:026836 8c03 mov A,[HL + 0x3]
ram:026838 4c30 cmp A,#0x30
ram:02683a de1e bnc $ 0x2685a
ram:02683c 8c03 mov A,[HL + 0x3]
ram:02683e 318e shrw AX,0x8
ram:026840 610906 addw AX,[HL + 0x6]
ram:026843 14 movw DE,AX
ram:026844 8c08 mov A,[HL + 0x8]
ram:026846 9efd mov ES,A
ram:026848 1189 mov A,ES:[DE]
ram:02684a 72 mov ,A
ram:02684b 8c03 mov A,[HL + 0x3]
ram:02684d 318e shrw AX,0x8
ram:02684f 610904 addw AX,[HL + 0x4]
ram:026852 14 movw DE,AX
ram:026853 62 mov A,
ram:026854 99 mov [DE],A
ram:026855 615903 inc [HL + 0x3]
ram:026858 efdc br $ 0x26836
ram:02685a d500ea cmp0 !0xfea00
ram:02685d dd06 bz $ 0x26865
ram:02685f 4000ea32 cmp !0xfea00,0x32
ram:026863 61c8 skc
ram:026865 f500ea _clrb !0xfea00
ram:026868 d501ea cmp0 !0xfea01
ram:02686b dd06 bz $ 0x26873
ram:02686d 4001ea32 cmp !0xfea01,0x32
ram:026871 61c8 skc
ram:026873 f501ea _clrb !0xfea01
ram:026876 4003ea22 cmp !0xfea03,0x22
ram:02687a 61c8 skc
ram:02687c f503ea _clrb !0xfea03
ram:02687f 4004ea06 cmp !0xfea04,0x6
ram:026883 61c8 skc
ram:026885 f504ea _clrb !0xfea04
ram:026888 4005ea06 cmp !0xfea05,0x6
ram:02688c 61c8 skc
ram:02688e f505ea _clrb !0xfea05
ram:026891 4006ea05 cmp !0xfea06,0x5
ram:026895 61c8 skc
ram:026897 f506ea _clrb !0xfea06
ram:02689a 8f07ea mov A,!0xfea07
ram:02689d 5c30 and A,#0x30
ram:02689f 4c30 cmp A,#0x30
ram:0268a1 df0d bnz $ 0x268b0
ram:0268a3 e6 onew AX
ram:0268a4 c1 push AX
ram:0268a5 f6 clrw AX
ram:0268a6 c1 push AX
ram:0268a7 3007ea movw AX,0xea07
ram:0268aa fc40e500 call !!0xe540
ram:0268ae 1004 addw SP,0x4
ram:0268b0 f6 clrw AX
ram:0268b1 b1 decw AX
ram:0268b2 4208ea cmpw AX,!0xfea08
ram:0268b5 df06 bnz $ 0x268bd
ram:0268b7 302a2a movw AX,0x2a2a
ram:0268ba bf08ea movw !0xfea08,AX
ram:0268bd 8f0bea mov A,!0xfea0b
ram:0268c0 5ce0 and A,#0xe0
ram:0268c2 4ce0 cmp A,#0xe0
ram:0268c4 df0e bnz $ 0x268d4
ram:0268c6 e6 onew AX
ram:0268c7 a1 incw AX
ram:0268c8 c1 push AX
ram:0268c9 f6 clrw AX
ram:0268ca c1 push AX
ram:0268cb 300aea movw AX,0xea0a
ram:0268ce fc40e500 call !!0xe540
ram:0268d2 1004 addw SP,0x4
ram:0268d4 8f0aea mov A,!0xfea0a
ram:0268d7 315303 bt A.0x5,$ 0x268dc
ram:0268da 715201 set1 0xffe21.0x5
ram:0268dd 4022ea09 cmp !0xfea22,0x9
ram:0268e1 dd09 bz $ 0x268ec
ram:0268e3 4022ea04 cmp !0xfea22,0x4
ram:0268e7 61c8 skc
ram:0268e9 f522ea _clrb !0xfea22
ram:0268ec 4023ea02 cmp !0xfea23,0x2
ram:0268f0 61c8 skc
ram:0268f2 f523ea _clrb !0xfea23
ram:0268f5 4024eaff cmp !0xfea24,0xff
ram:0268f9 61f8 sknz
ram:0268fb f524ea _clrb !0xfea24
ram:0268fe d524ea cmp0 !0xfea24
ram:026901 61e8 skz
ram:026903 e5e9e5 _oneb !0xfe5e9
ram:026906 4026eaff cmp !0xfea26,0xff
ram:02690a 61f8 sknz
ram:02690c cf26ea07 _mov !0xfea26,0x7
ram:026910 4027eaff cmp !0xfea27,0xff
ram:026914 61f8 sknz
ram:026916 cf27ea07 _mov !0xfea27,0x7
ram:02691a 4028eaff cmp !0xfea28,0xff
ram:02691e 61f8 sknz
ram:026920 cf28ea24 _mov !0xfea28,0x24
ram:026924 4029eaff cmp !0xfea29,0xff
ram:026928 61f8 sknz
ram:02692a cf29ea80 _mov !0xfea29,0x80
ram:02692e 402aeaff cmp !0xfea2a,0xff
ram:026932 61f8 sknz
ram:026934 cf2aea80 _mov !0xfea2a,0x80
ram:026938 402ceaff cmp !0xfea2c,0xff
ram:02693c 61f8 sknz
ram:02693e f52cea _clrb !0xfea2c
ram:026941 402deaff cmp !0xfea2d,0xff
ram:026945 61f8 sknz
ram:026947 cf2dea2d _mov !0xfea2d,0x2d
ram:02694b af12e4 movw AX,!0xfe412
ram:02694e e7 onew BC
ram:02694f c3 push BC
ram:026950 342cea movw DE,0xea2c
ram:026953 c5 push DE
ram:026954 14 movw DE,AX
ram:026955 8a12 mov A,[DE + 0x12]
ram:026957 9dd4 mov 0xffdf4,A
ram:026959 aa10 movw AX,[DE + 0x10]
ram:02695b c1 push AX
ram:02695c 8dd4 mov A,0xffdf4
ram:02695e 9dd6 mov 0xffdf6,A
ram:026960 c0 pop AX
ram:026961 14 movw DE,AX
ram:026962 307000 movw AX,0x70
ram:026965 f7 clrw BC
ram:026966 c1 push AX
ram:026967 8dd6 mov A,0xffdf6
ram:026969 9efc mov CS,A
ram:02696b c0 pop AX
ram:02696c 61ea call DE
ram:02696e 1004 addw SP,0x4
ram:026970 af12e4 movw AX,!0xfe412
ram:026973 e7 onew BC
ram:026974 c3 push BC
ram:026975 342dea movw DE,0xea2d
ram:026978 c5 push DE
ram:026979 14 movw DE,AX
ram:02697a 8a12 mov A,[DE + 0x12]
ram:02697c 9dd4 mov 0xffdf4,A
ram:02697e aa10 movw AX,[DE + 0x10]
ram:026980 c1 push AX
ram:026981 8dd4 mov A,0xffdf4
ram:026983 9dd6 mov 0xffdf6,A
ram:026985 c0 pop AX
ram:026986 14 movw DE,AX
ram:026987 307100 movw AX,0x71
ram:02698a f7 clrw BC
ram:02698b c1 push AX
ram:02698c 8dd6 mov A,0xffdf6
ram:02698e 9efc mov CS,A
ram:026990 c0 pop AX
ram:026991 61ea call DE
ram:026993 1004 addw SP,0x4
ram:026995 fce74002 call !!0x240e7
ram:026999 30e803 movw AX,0x3e8
ram:02699c c1 push AX
ram:02699d 308144 movw AX,0x4481
ram:0269a0 5202 mov ,0x2
ram:0269a2 f3 clrb B
ram:0269a3 fcea7d00 call !!0x7dea
ram:0269a7 c0 pop AX
ram:0269a8 62 mov A,
ram:0269a9 9ffde9 mov !0xfe9fd,A
ram:0269ac 30f401 movw AX,0x1f4
ram:0269af c1 push AX
ram:0269b0 302c41 movw AX,0x412c
ram:0269b3 5202 mov ,0x2
ram:0269b5 f3 clrb B
ram:0269b6 fcea7d00 call !!0x7dea
ram:0269ba c0 pop AX
ram:0269bb 62 mov A,
ram:0269bc 9fffe9 mov !0xfe9ff,A
ram:0269bf ee9700 br $! 0x26a59
ram:0269c2 303000 movw AX,0x30
ram:0269c5 bc08 movw [HL + 0x8],AX
ram:0269c7 3400b4 movw DE,0xb400
ram:0269ca 15 movw AX,DE
ram:0269cb bc02 movw [HL + 0x2],AX
ram:0269cd cc0403 mov [HL + 0x4],0x3
ram:0269d0 3000ea movw AX,0xea00
ram:0269d3 bb movw [HL],AX
ram:0269d4 f6 clrw AX
ram:0269d5 bc06 movw [HL + 0x6],AX
ram:0269d7 ac06 movw AX,[HL + 0x6]
ram:0269d9 614908 cmpw AX,[HL + 0x8]
ram:0269dc de34 bnc $ 0x26a12
ram:0269de ac06 movw AX,[HL + 0x6]
ram:0269e0 610902 addw AX,[HL + 0x2]
ram:0269e3 14 movw DE,AX
ram:0269e4 8c04 mov A,[HL + 0x4]
ram:0269e6 9efd mov ES,A
ram:0269e8 1189 mov A,ES:[DE]
ram:0269ea 72 mov ,A
ram:0269eb ac06 movw AX,[HL + 0x6]
ram:0269ed 610900 addw AX,[HL + 0x0]
ram:0269f0 14 movw DE,AX
ram:0269f1 89 mov A,[DE]
ram:0269f2 6142 cmp ,A
ram:0269f4 dd17 bz $ 0x26a0d
ram:0269f6 f6 clrw AX
ram:0269f7 c1 push AX
ram:0269f8 ac08 movw AX,[HL + 0x8]
ram:0269fa f7 clrw BC
ram:0269fb c3 push BC
ram:0269fc c1 push AX
ram:0269fd 3400ea movw DE,0xea00
ram:026a00 c5 push DE
ram:026a01 30ed00 movw AX,0xed
ram:026a04 fc1f1900 call !!0x191f
ram:026a08 1008 addw SP,0x8
ram:026a0a 92 dec 
ram:026a0b ef05 br $ 0x26a12
ram:026a0d 617906 incw [HL + 0x6]
ram:026a10 efc5 br $ 0x269d7
ram:026a12 715301 clr1 0xffe21.0x5
ram:026a15 cff8e906 mov !0xfe9f8,0x6
ram:026a19 d5fce9 cmp0 !0xfe9fc
ram:026a1c dd0b bz $ 0x26a29
ram:026a1e d9fce9 mov X,!0xfe9fc
ram:026a21 f1 clrb A
ram:026a22 fc927e00 call !!0x7e92
ram:026a26 f5fce9 clrb !0xfe9fc
ram:026a29 d5fde9 cmp0 !0xfe9fd
ram:026a2c dd0b bz $ 0x26a39
ram:026a2e d9fde9 mov X,!0xfe9fd
ram:026a31 f1 clrb A
ram:026a32 fc927e00 call !!0x7e92
ram:026a36 f5fde9 clrb !0xfe9fd
ram:026a39 d5fee9 cmp0 !0xfe9fe
ram:026a3c dd0b bz $ 0x26a49
ram:026a3e d9fee9 mov X,!0xfe9fe
ram:026a41 f1 clrb A
ram:026a42 fc927e00 call !!0x7e92
ram:026a46 f5fee9 clrb !0xfe9fe
ram:026a49 d5ffe9 cmp0 !0xfe9ff
ram:026a4c dd0b bz $ 0x26a59
ram:026a4e d9ffe9 mov X,!0xfe9ff
ram:026a51 f1 clrb A
ram:026a52 fc927e00 call !!0x7e92
ram:026a56 f5ffe9 clrb !0xfe9ff
ram:026a59 100c addw SP,0xc
ram:026a5b c6 pop HL
ram:026a5c d7 ret
ram:026a5d c7 push HL
ram:026a5e c1 push AX
ram:026a5f 200e subw SP,0xe
ram:026a61 fbf8ff movw HL,!0xffff8
ram:026a64 8f71d9 mov A,!0xfd971
ram:026a67 5c01 and A,#0x1
ram:026a69 318e shrw AX,0x8
ram:026a6b 312d shlw AX,0x2
ram:026a6d 12 movw BC,AX
ram:026a6e 313d shlw AX,0x3
ram:026a70 03 addw AX,BC
ram:026a71 0472d9 addw AX,0xd972
ram:026a74 bc0c movw [HL + 0xc],AX
ram:026a76 f6 clrw AX
ram:026a77 bc0a movw [HL + 0xa],AX
ram:026a79 ac0e movw AX,[HL + 0xe]
ram:026a7b 14 movw DE,AX
ram:026a7c aa04 movw AX,[DE + 0x4]
ram:026a7e e7 onew BC
ram:026a7f 340000 movw DE,0x0
ram:026a82 25 subw AX,DE
ram:026a83 dd37 bz $ 0x26abc
ram:026a85 b1 decw AX
ram:026a86 240300 subw AX,0x3
ram:026a89 dc39 bc $ 0x26ac4
ram:026a8b 25 subw AX,DE
ram:026a8c dd42 bz $ 0x26ad0
ram:026a8e 23 subw AX,BC
ram:026a8f 61f8 sknz
ram:026a91 eec500 _br $! 0x26b59
ram:026a94 23 subw AX,BC
ram:026a95 61f8 sknz
ram:026a97 ee0201 _br $! 0x26b9c
ram:026a9a 23 subw AX,BC
ram:026a9b 61f8 sknz
ram:026a9d eea001 _br $! 0x26c40
ram:026aa0 b1 decw AX
ram:026aa1 23 subw AX,BC
ram:026aa2 61e3 skh
ram:026aa4 ee0802 _br $! 0x26caf
ram:026aa7 23 subw AX,BC
ram:026aa8 61f8 sknz
ram:026aaa eece02 _br $! 0x26d7b
ram:026aad 23 subw AX,BC
ram:026aae 61f8 sknz
ram:026ab0 ee0e03 _br $! 0x26dc1
ram:026ab3 23 subw AX,BC
ram:026ab4 61f8 sknz
ram:026ab6 eeba03 _br $! 0x26e73
ram:026ab9 ee0304 br $! 0x26ebf
ram:026abc d9c4e3 mov X,!0xfe3c4
ram:026abf f1 clrb A
ram:026ac0 fca2e600 call !!0xe6a2
ram:026ac4 cfc5e3ff mov !0xfe3c5,0xff
ram:026ac8 ac0e movw AX,[HL + 0xe]
ram:026aca 14 movw DE,AX
ram:026acb 300400 movw AX,0x4
ram:026ace ba04 movw [DE + 0x4],AX
ram:026ad0 a0c5e3 inc !0xfe3c5
ram:026ad3 ac0c movw AX,[HL + 0xc]
ram:026ad5 14 movw DE,AX
ram:026ad6 8a02 mov A,[DE + 0x2]
ram:026ad8 4fc5e3 cmp A,!0xfe3c5
ram:026adb 61c30a bh $ 0x26ae7
ram:026ade ac0e movw AX,[HL + 0xe]
ram:026ae0 14 movw DE,AX
ram:026ae1 300800 movw AX,0x8
ram:026ae4 ba04 movw [DE + 0x4],AX
ram:026ae6 ef6e br $ 0x26b56
ram:026ae8 af68d9 movw AX,!0xfd968
ram:026aeb c1 push AX
ram:026aec ac0c movw AX,[HL + 0xc]
ram:026aee 040300 addw AX,0x3
ram:026af1 12 movw BC,AX
ram:026af2 8fc5e3 mov A,!0xfe3c5
ram:026af5 318f sarw AX,0x8
ram:026af7 03 addw AX,BC
ram:026af8 14 movw DE,AX
ram:026af9 89 mov A,[DE]
ram:026afa 318e shrw AX,0x8
ram:026afc fc52f001 call !!0x1f052
ram:026b00 c0 pop AX
ram:026b01 62 mov A,
ram:026b02 4c03 cmp A,#0x3
ram:026b04 dd17 bz $ 0x26b1d
ram:026b06 ac0c movw AX,[HL + 0xc]
ram:026b08 040300 addw AX,0x3
ram:026b0b 12 movw BC,AX
ram:026b0c 8fc5e3 mov A,!0xfe3c5
ram:026b0f 318f sarw AX,0x8
ram:026b11 03 addw AX,BC
ram:026b12 14 movw DE,AX
ram:026b13 89 mov A,[DE]
ram:026b14 318e shrw AX,0x8
ram:026b16 fc90f401 call !!0x1f490
ram:026b1a 92 dec 
ram:026b1b df0e bnz $ 0x26b2b
ram:026b1d 8fc5e3 mov A,!0xfe3c5
ram:026b20 318f sarw AX,0x8
ram:026b22 04c4d9 addw AX,0xd9c4
ram:026b25 14 movw DE,AX
ram:026b26 ca0000 mov [DE + 0x0],0x0
ram:026b29 ef2b br $ 0x26b56
ram:026b2b ac0c movw AX,[HL + 0xc]
ram:026b2d 040300 addw AX,0x3
ram:026b30 12 movw BC,AX
ram:026b31 8fc5e3 mov A,!0xfe3c5
ram:026b34 318f sarw AX,0x8
ram:026b36 03 addw AX,BC
ram:026b37 14 movw DE,AX
ram:026b38 89 mov A,[DE]
ram:026b39 318e shrw AX,0x8
ram:026b3b fc160101 call !!0x10116
ram:026b3f c5 push DE
ram:026b40 c3 push BC
ram:026b41 d967d9 mov X,!0xfd967
ram:026b44 f1 clrb A
ram:026b45 c1 push AX
ram:026b46 ac0e movw AX,[HL + 0xe]
ram:026b48 fcc5f400 call !!0xf4c5
ram:026b4c 1006 addw SP,0x6
ram:026b4e ac0e movw AX,[HL + 0xe]
ram:026b50 14 movw DE,AX
ram:026b51 300500 movw AX,0x5
ram:026b54 ba04 movw [DE + 0x4],AX
ram:026b56 ee6603 br $! 0x26ebf
ram:026b59 17 movw AX,HL
ram:026b5a fcf5f400 call !!0xf4f5
ram:026b5e 17 movw AX,HL
ram:026b5f fcedf700 call !!0xf7ed
ram:026b63 13 movw AX,BC
ram:026b64 bc08 movw [HL + 0x8],AX
ram:026b66 8fc5e3 mov A,!0xfe3c5
ram:026b69 318f sarw AX,0x8
ram:026b6b 04c4d9 addw AX,0xd9c4
ram:026b6e 14 movw DE,AX
ram:026b6f 8c08 mov A,[HL + 0x8]
ram:026b71 99 mov [DE],A
ram:026b72 d9f0d9 mov X,!0xfd9f0
ram:026b75 f1 clrb A
ram:026b76 bdd8 movw 0xffdf8,AX
ram:026b78 ac08 movw AX,[HL + 0x8]
ram:026b7a fdab06 call !0xf06ab
ram:026b7d de0a bnc $ 0x26b89
ram:026b7f ac0e movw AX,[HL + 0xe]
ram:026b81 14 movw DE,AX
ram:026b82 300600 movw AX,0x6
ram:026b85 ba04 movw [DE + 0x4],AX
ram:026b87 ef10 br $ 0x26b99
ram:026b89 ac0e movw AX,[HL + 0xe]
ram:026b8b 14 movw DE,AX
ram:026b8c 300a00 movw AX,0xa
ram:026b8f ba06 movw [DE + 0x6],AX
ram:026b91 ac0e movw AX,[HL + 0xe]
ram:026b93 14 movw DE,AX
ram:026b94 300400 movw AX,0x4
ram:026b97 ba04 movw [DE + 0x4],AX
ram:026b99 ee2303 br $! 0x26ebf
ram:026b9c af68d9 movw AX,!0xfd968
ram:026b9f c1 push AX
ram:026ba0 ac0c movw AX,[HL + 0xc]
ram:026ba2 040300 addw AX,0x3
ram:026ba5 12 movw BC,AX
ram:026ba6 8fc5e3 mov A,!0xfe3c5
ram:026ba9 318f sarw AX,0x8
ram:026bab 03 addw AX,BC
ram:026bac 14 movw DE,AX
ram:026bad 89 mov A,[DE]
ram:026bae 318e shrw AX,0x8
ram:026bb0 fcaaf001 call !!0x1f0aa
ram:026bb4 c0 pop AX
ram:026bb5 62 mov A,
ram:026bb6 d1 cmp0 A
ram:026bb7 dd42 bz $ 0x26bfb
ram:026bb9 91 dec 
ram:026bba dd09 bz $ 0x26bc5
ram:026bbc 91 dec 
ram:026bbd 2c02 sub A,#0x2
ram:026bbf dc6c bc $ 0x26c2d
ram:026bc1 2c03 sub A,#0x3
ram:026bc3 de78 bnc $ 0x26c3d
ram:026bc5 ac0c movw AX,[HL + 0xc]
ram:026bc7 040300 addw AX,0x3
ram:026bca 12 movw BC,AX
ram:026bcb 8fc5e3 mov A,!0xfe3c5
ram:026bce 318f sarw AX,0x8
ram:026bd0 03 addw AX,BC
ram:026bd1 14 movw DE,AX
ram:026bd2 89 mov A,[DE]
ram:026bd3 9fc6e3 mov !0xfe3c6,A
ram:026bd6 af68d9 movw AX,!0xfd968
ram:026bd9 c1 push AX
ram:026bda d9c6e3 mov X,!0xfe3c6
ram:026bdd f1 clrb A
ram:026bde fc160101 call !!0x10116
ram:026be2 c5 push DE
ram:026be3 c3 push BC
ram:026be4 d967d9 mov X,!0xfd967
ram:026be7 f1 clrb A
ram:026be8 c1 push AX
ram:026be9 ac0e movw AX,[HL + 0xe]
ram:026beb fc40f600 call !!0xf640
ram:026bef 1008 addw SP,0x8
ram:026bf1 ac0e movw AX,[HL + 0xe]
ram:026bf3 14 movw DE,AX
ram:026bf4 300700 movw AX,0x7
ram:026bf7 ba04 movw [DE + 0x4],AX
ram:026bf9 ef42 br $ 0x26c3d
ram:026bfb ac0c movw AX,[HL + 0xc]
ram:026bfd 040300 addw AX,0x3
ram:026c00 12 movw BC,AX
ram:026c01 8fc5e3 mov A,!0xfe3c5
ram:026c04 318f sarw AX,0x8
ram:026c06 03 addw AX,BC
ram:026c07 14 movw DE,AX
ram:026c08 89 mov A,[DE]
ram:026c09 9fc6e3 mov !0xfe3c6,A
ram:026c0c d9c6e3 mov X,!0xfe3c6
ram:026c0f f1 clrb A
ram:026c10 fc160101 call !!0x10116
ram:026c14 c5 push DE
ram:026c15 c3 push BC
ram:026c16 d967d9 mov X,!0xfd967
ram:026c19 f1 clrb A
ram:026c1a c1 push AX
ram:026c1b ac0e movw AX,[HL + 0xe]
ram:026c1d fc56f400 call !!0xf456
ram:026c21 1006 addw SP,0x6
ram:026c23 ac0e movw AX,[HL + 0xe]
ram:026c25 14 movw DE,AX
ram:026c26 300b00 movw AX,0xb
ram:026c29 ba04 movw [DE + 0x4],AX
ram:026c2b ef10 br $ 0x26c3d
ram:026c2d ac0e movw AX,[HL + 0xe]
ram:026c2f 14 movw DE,AX
ram:026c30 300a00 movw AX,0xa
ram:026c33 ba06 movw [DE + 0x6],AX
ram:026c35 ac0e movw AX,[HL + 0xe]
ram:026c37 14 movw DE,AX
ram:026c38 300400 movw AX,0x4
ram:026c3b ba04 movw [DE + 0x4],AX
ram:026c3d ee7f02 br $! 0x26ebf
ram:026c40 fc83f600 call !!0xf683
ram:026c44 92 dec 
ram:026c45 df2b bnz $ 0x26c72
ram:026c47 17 movw AX,HL
ram:026c48 040800 addw AX,0x8
ram:026c4b fc8af600 call !!0xf68a
ram:026c4f ac08 movw AX,[HL + 0x8]
ram:026c51 4268d9 cmpw AX,!0xfd968
ram:026c54 dd12 bz $ 0x26c68
ram:026c56 ac0e movw AX,[HL + 0xe]
ram:026c58 14 movw DE,AX
ram:026c59 300a00 movw AX,0xa
ram:026c5c ba06 movw [DE + 0x6],AX
ram:026c5e ac0e movw AX,[HL + 0xe]
ram:026c60 14 movw DE,AX
ram:026c61 300400 movw AX,0x4
ram:026c64 ba04 movw [DE + 0x4],AX
ram:026c66 ef44 br $ 0x26cac
ram:026c68 ac0e movw AX,[HL + 0xe]
ram:026c6a 14 movw DE,AX
ram:026c6b 300b00 movw AX,0xb
ram:026c6e ba04 movw [DE + 0x4],AX
ram:026c70 ef3a br $ 0x26cac
ram:026c72 af68d9 movw AX,!0xfd968
ram:026c75 c1 push AX
ram:026c76 ac0c movw AX,[HL + 0xc]
ram:026c78 040300 addw AX,0x3
ram:026c7b 12 movw BC,AX
ram:026c7c 8fc5e3 mov A,!0xfe3c5
ram:026c7f 318f sarw AX,0x8
ram:026c81 03 addw AX,BC
ram:026c82 14 movw DE,AX
ram:026c83 89 mov A,[DE]
ram:026c84 318e shrw AX,0x8
ram:026c86 fcaaf001 call !!0x1f0aa
ram:026c8a c0 pop AX
ram:026c8b 62 mov A,
ram:026c8c 4c03 cmp A,#0x3
ram:026c8e df0c bnz $ 0x26c9c
ram:026c90 8fc5e3 mov A,!0xfe3c5
ram:026c93 318f sarw AX,0x8
ram:026c95 04c4d9 addw AX,0xd9c4
ram:026c98 14 movw DE,AX
ram:026c99 ca0000 mov [DE + 0x0],0x0
ram:026c9c ac0e movw AX,[HL + 0xe]
ram:026c9e 14 movw DE,AX
ram:026c9f 300a00 movw AX,0xa
ram:026ca2 ba06 movw [DE + 0x6],AX
ram:026ca4 ac0e movw AX,[HL + 0xe]
ram:026ca6 14 movw DE,AX
ram:026ca7 300400 movw AX,0x4
ram:026caa ba04 movw [DE + 0x4],AX
ram:026cac ee1002 br $! 0x26ebf
ram:026caf cc0800 mov [HL + 0x8],0x0
ram:026cb2 d9c4d9 mov X,!0xfd9c4
ram:026cb5 f1 clrb A
ram:026cb6 bc06 movw [HL + 0x6],AX
ram:026cb8 cc0901 mov [HL + 0x9],0x1
ram:026cbb ac0c movw AX,[HL + 0xc]
ram:026cbd 14 movw DE,AX
ram:026cbe 8a02 mov A,[DE + 0x2]
ram:026cc0 4e09 cmp A,[HL + 0x9]
ram:026cc2 61d326 bnh $ 0x26cea
ram:026cc5 8c09 mov A,[HL + 0x9]
ram:026cc7 73 mov ,A
ram:026cc8 09c4d9 mov A,!0xfd9c4[B]
ram:026ccb 318e shrw AX,0x8
ram:026ccd 12 movw BC,AX
ram:026cce ac06 movw AX,[HL + 0x6]
ram:026cd0 bdd8 movw 0xffdf8,AX
ram:026cd2 13 movw AX,BC
ram:026cd3 fdab06 call !0xf06ab
ram:026cd6 de0e bnc $ 0x26ce6
ram:026cd8 8c09 mov A,[HL + 0x9]
ram:026cda 9c08 mov [HL + 0x8],A
ram:026cdc 8c09 mov A,[HL + 0x9]
ram:026cde 73 mov ,A
ram:026cdf 09c4d9 mov A,!0xfd9c4[B]
ram:026ce2 318e shrw AX,0x8
ram:026ce4 bc06 movw [HL + 0x6],AX
ram:026ce6 615909 inc [HL + 0x9]
ram:026ce9 efd0 br $ 0x26cbb
ram:026ceb ac06 movw AX,[HL + 0x6]
ram:026ced 442900 cmpw AX,0x29
ram:026cf0 71fe or1 CY,A.0x7
ram:026cf2 dc67 bc $ 0x26d5b
ram:026cf4 8c08 mov A,[HL + 0x8]
ram:026cf6 9fc5e3 mov !0xfe3c5,A
ram:026cf9 ac0c movw AX,[HL + 0xc]
ram:026cfb 14 movw DE,AX
ram:026cfc 8c08 mov A,[HL + 0x8]
ram:026cfe 318e shrw AX,0x8
ram:026d00 a5 incw DE
ram:026d01 a5 incw DE
ram:026d02 a5 incw DE
ram:026d03 05 addw AX,DE
ram:026d04 14 movw DE,AX
ram:026d05 89 mov A,[DE]
ram:026d06 9fc6e3 mov !0xfe3c6,A
ram:026d09 8fc4d9 mov A,!0xfd9c4
ram:026d0c 0c14 add A,#0x14
ram:026d0e 318e shrw AX,0x8
ram:026d10 bdd8 movw 0xffdf8,AX
ram:026d12 ac06 movw AX,[HL + 0x6]
ram:026d14 fdab06 call !0xf06ab
ram:026d17 de1d bnc $ 0x26d36
ram:026d19 af68d9 movw AX,!0xfd968
ram:026d1c c1 push AX
ram:026d1d d9c6e3 mov X,!0xfe3c6
ram:026d20 f1 clrb A
ram:026d21 fc160101 call !!0x10116
ram:026d25 c5 push DE
ram:026d26 c3 push BC
ram:026d27 d967d9 mov X,!0xfd967
ram:026d2a f1 clrb A
ram:026d2b c1 push AX
ram:026d2c ac0e movw AX,[HL + 0xe]
ram:026d2e fc40f600 call !!0xf640
ram:026d32 1008 addw SP,0x8
ram:026d34 ef1b br $ 0x26d51
ram:026d36 af68d9 movw AX,!0xfd968
ram:026d39 c1 push AX
ram:026d3a d9c6e3 mov X,!0xfe3c6
ram:026d3d f1 clrb A
ram:026d3e fc160101 call !!0x10116
ram:026d42 c5 push DE
ram:026d43 c3 push BC
ram:026d44 d967d9 mov X,!0xfd967
ram:026d47 f1 clrb A
ram:026d48 c1 push AX
ram:026d49 ac0e movw AX,[HL + 0xe]
ram:026d4b fcfdf500 call !!0xf5fd
ram:026d4f 1008 addw SP,0x8
ram:026d51 ac0e movw AX,[HL + 0xe]
ram:026d53 14 movw DE,AX
ram:026d54 300a00 movw AX,0xa
ram:026d57 ba04 movw [DE + 0x4],AX
ram:026d59 ef1d br $ 0x26d78
ram:026d5b af6cd9 movw AX,!0xfd96c
ram:026d5e c1 push AX
ram:026d5f af6ad9 movw AX,!0xfd96a
ram:026d62 c1 push AX
ram:026d63 d967d9 mov X,!0xfd967
ram:026d66 f1 clrb A
ram:026d67 c1 push AX
ram:026d68 ac0e movw AX,[HL + 0xe]
ram:026d6a fc56f400 call !!0xf456
ram:026d6e 1006 addw SP,0x6
ram:026d70 ac0e movw AX,[HL + 0xe]
ram:026d72 14 movw DE,AX
ram:026d73 300c00 movw AX,0xc
ram:026d76 ba04 movw [DE + 0x4],AX
ram:026d78 ee4401 br $! 0x26ebf
ram:026d7b fc83f600 call !!0xf683
ram:026d7f 92 dec 
ram:026d80 df28 bnz $ 0x26daa
ram:026d82 17 movw AX,HL
ram:026d83 040800 addw AX,0x8
ram:026d86 fc8af600 call !!0xf68a
ram:026d8a ac08 movw AX,[HL + 0x8]
ram:026d8c 4268d9 cmpw AX,!0xfd968
ram:026d8f dd0b bz $ 0x26d9c
ram:026d91 ac08 movw AX,[HL + 0x8]
ram:026d93 bfc2e3 movw !0xfe3c2,AX
ram:026d96 7100c0e3 set1 !0xfe3c0.0x0
ram:026d9a ef04 br $ 0x26da0
ram:026d9c 7108c0e3 clr1 !0xfe3c0.0x0
ram:026da0 ac0e movw AX,[HL + 0xe]
ram:026da2 14 movw DE,AX
ram:026da3 300b00 movw AX,0xb
ram:026da6 ba04 movw [DE + 0x4],AX
ram:026da8 ef14 br $ 0x26dbe
ram:026daa 8fc5e3 mov A,!0xfe3c5
ram:026dad 318f sarw AX,0x8
ram:026daf 04c4d9 addw AX,0xd9c4
ram:026db2 14 movw DE,AX
ram:026db3 ca0000 mov [DE + 0x0],0x0
ram:026db6 ac0e movw AX,[HL + 0xe]
ram:026db8 14 movw DE,AX
ram:026db9 300900 movw AX,0x9
ram:026dbc ba04 movw [DE + 0x4],AX
ram:026dbe eefe00 br $! 0x26ebf
ram:026dc1 8fc0e3 mov A,!0xfe3c0
ram:026dc4 31054e bf A.0x0,$ 0x26e14
ram:026dc7 afc2e3 movw AX,!0xfe3c2
ram:026dca bc06 movw [HL + 0x6],AX
ram:026dcc d9c6e3 mov X,!0xfe3c6
ram:026dcf f1 clrb A
ram:026dd0 bc08 movw [HL + 0x8],AX
ram:026dd2 db02e4 movw BC,!0xfe402
ram:026dd5 17 movw AX,HL
ram:026dd6 040600 addw AX,0x6
ram:026dd9 c1 push AX
ram:026dda 491a00 mov A,!0xf001a[BC]
ram:026ddd 9efc mov CS,A
ram:026ddf 791800 movw AX,!0xf0018[BC]
ram:026de2 14 movw DE,AX
ram:026de3 304100 movw AX,0x41
ram:026de6 61ea call DE
ram:026de8 c0 pop AX
ram:026de9 d9c6e3 mov X,!0xfe3c6
ram:026dec f1 clrb A
ram:026ded fc160101 call !!0x10116
ram:026df1 13 movw AX,BC
ram:026df2 bf6ad9 movw !0xfd96a,AX
ram:026df5 15 movw AX,DE
ram:026df6 bf6cd9 movw !0xfd96c,AX
ram:026df9 afc2e3 movw AX,!0xfe3c2
ram:026dfc bf68d9 movw !0xfd968,AX
ram:026dff af08e4 movw AX,!0xfe408
ram:026e02 3468d9 movw DE,0xd968
ram:026e05 c5 push DE
ram:026e06 14 movw DE,AX
ram:026e07 8a0e mov A,[DE + 0xe]
ram:026e09 9efc mov CS,A
ram:026e0b aa0c movw AX,[DE + 0xc]
ram:026e0d 14 movw DE,AX
ram:026e0e e6 onew AX
ram:026e0f a1 incw AX
ram:026e10 61ea call DE
ram:026e12 c0 pop AX
ram:026e13 ef45 br $ 0x26e5a
ram:026e15 d9c6e3 mov X,!0xfe3c6
ram:026e18 f1 clrb A
ram:026e19 fcf9f600 call !!0xf6f9
ram:026e1d d9c6e3 mov X,!0xfe3c6
ram:026e20 f1 clrb A
ram:026e21 fc160101 call !!0x10116
ram:026e25 13 movw AX,BC
ram:026e26 bf6ad9 movw !0xfd96a,AX
ram:026e29 15 movw AX,DE
ram:026e2a bf6cd9 movw !0xfd96c,AX
ram:026e2d af02e4 movw AX,!0xfe402
ram:026e30 346ad9 movw DE,0xd96a
ram:026e33 c5 push DE
ram:026e34 14 movw DE,AX
ram:026e35 8a1a mov A,[DE + 0x1a]
ram:026e37 9efc mov CS,A
ram:026e39 aa18 movw AX,[DE + 0x18]
ram:026e3b 14 movw DE,AX
ram:026e3c 304000 movw AX,0x40
ram:026e3f 61ea call DE
ram:026e41 c0 pop AX
ram:026e42 af08e4 movw AX,!0xfe408
ram:026e45 3468d9 movw DE,0xd968
ram:026e48 c5 push DE
ram:026e49 14 movw DE,AX
ram:026e4a 8a0e mov A,[DE + 0xe]
ram:026e4c 9efc mov CS,A
ram:026e4e aa0c movw AX,[DE + 0xc]
ram:026e50 14 movw DE,AX
ram:026e51 e6 onew AX
ram:026e52 a1 incw AX
ram:026e53 61ea call DE
ram:026e55 c0 pop AX
ram:026e56 fc9c0101 call !!0x1019c
ram:026e5a db6cd9 movw BC,!0xfd96c
ram:026e5d af6ad9 movw AX,!0xfd96a
ram:026e60 bfe6d9 movw !0xfd9e6,AX
ram:026e63 33 xchw AX,BC
ram:026e64 bfe8d9 movw !0xfd9e8,AX
ram:026e67 f6 clrw AX
ram:026e68 fc0b0301 call !!0x1030b
ram:026e6c e6 onew AX
ram:026e6d fc267002 call !!0x27026
ram:026e71 ef4c br $ 0x26ebf
ram:026e73 f6 clrw AX
ram:026e74 fc24f001 call !!0x1f024
ram:026e78 302000 movw AX,0x20
ram:026e7b c1 push AX
ram:026e7c 501e mov ,0x1e
ram:026e7e c1 push AX
ram:026e7f 30c4d9 movw AX,0xd9c4
ram:026e82 fc40e500 call !!0xe540
ram:026e86 1004 addw SP,0x4
ram:026e88 af02e4 movw AX,!0xfe402
ram:026e8b 346ad9 movw DE,0xd96a
ram:026e8e c5 push DE
ram:026e8f 14 movw DE,AX
ram:026e90 8a1a mov A,[DE + 0x1a]
ram:026e92 9efc mov CS,A
ram:026e94 aa18 movw AX,[DE + 0x18]
ram:026e96 14 movw DE,AX
ram:026e97 304000 movw AX,0x40
ram:026e9a 61ea call DE
ram:026e9c c0 pop AX
ram:026e9d af08e4 movw AX,!0xfe408
ram:026ea0 3468d9 movw DE,0xd968
ram:026ea3 c5 push DE
ram:026ea4 14 movw DE,AX
ram:026ea5 8a0e mov A,[DE + 0xe]
ram:026ea7 9efc mov CS,A
ram:026ea9 aa0c movw AX,[DE + 0xc]
ram:026eab 14 movw DE,AX
ram:026eac e6 onew AX
ram:026ead a1 incw AX
ram:026eae 61ea call DE
ram:026eb0 c0 pop AX
ram:026eb1 fc9c0101 call !!0x1019c
ram:026eb5 f6 clrw AX
ram:026eb6 fc0b0301 call !!0x1030b
ram:026eba e6 onew AX
ram:026ebb fc267002 call !!0x27026
ram:026ebf e7 onew BC
ram:026ec0 1010 addw SP,0x10
ram:026ec2 c6 pop HL
ram:026ec3 d7 ret
ram:026ec4 c7 push HL
ram:026ec5 16 movw HL,AX
ram:026ec6 af08e4 movw AX,!0xfe408
ram:026ec9 f7 clrw BC
ram:026eca c3 push BC
ram:026ecb 14 movw DE,AX
ram:026ecc 8a0e mov A,[DE + 0xe]
ram:026ece 9efc mov CS,A
ram:026ed0 aa0c movw AX,[DE + 0xc]
ram:026ed2 14 movw DE,AX
ram:026ed3 300400 movw AX,0x4
ram:026ed6 61ea call DE
ram:026ed8 c0 pop AX
ram:026ed9 fc98f600 call !!0xf698
ram:026edd e6 onew AX
ram:026ede fc0b0301 call !!0x1030b
ram:026ee2 fc18ef01 call !!0x1ef18
ram:026ee6 66 mov A,
ram:026ee7 9fc4e3 mov !0xfe3c4,A
ram:026eea 7108c0e3 clr1 !0xfe3c0.0x0
ram:026eee cf65d902 mov !0xfd965,0x2
ram:026ef2 e6 onew AX
ram:026ef3 a1 incw AX
ram:026ef4 c1 push AX
ram:026ef5 305d6a movw AX,0x6a5d
ram:026ef8 5202 mov ,0x2
ram:026efa f3 clrb B
ram:026efb fcea7d00 call !!0x7dea
ram:026eff c0 pop AX
ram:026f00 62 mov A,
ram:026f01 9f6ed9 mov !0xfd96e,A
ram:026f04 c6 pop HL
ram:026f05 d7 ret
ram:026f06 d7 ret
ram:026f07 c7 push HL
ram:026f08 c1 push AX
ram:026f09 2004 subw SP,0x4
ram:026f0b fbf8ff movw HL,!0xffff8
ram:026f0e 8f71d9 mov A,!0xfd971
ram:026f11 5c01 and A,#0x1
ram:026f13 318e shrw AX,0x8
ram:026f15 312d shlw AX,0x2
ram:026f17 12 movw BC,AX
ram:026f18 313d shlw AX,0x3
ram:026f1a 03 addw AX,BC
ram:026f1b 0472d9 addw AX,0xd972
ram:026f1e bc02 movw [HL + 0x2],AX
ram:026f20 4067d904 cmp !0xfd967,0x4
ram:026f24 df09 bnz $ 0x26f2f
ram:026f26 f6 clrw AX
ram:026f27 c1 push AX
ram:026f28 fc8cfc00 call !!0xfc8c
ram:026f2c c0 pop AX
ram:026f2d ef07 br $ 0x26f36
ram:026f2f f6 clrw AX
ram:026f30 c1 push AX
ram:026f31 fc4e0001 call !!0x1004e
ram:026f35 c0 pop AX
ram:026f36 fc240602 call !!0x20624
ram:026f3a fc1c0502 call !!0x2051c
ram:026f3e ac04 movw AX,[HL + 0x4]
ram:026f40 14 movw DE,AX
ram:026f41 aa04 movw AX,[DE + 0x4]
ram:026f43 44c800 cmpw AX,0xc8
ram:026f46 df75 bnz $ 0x26fbd
ram:026f48 40c8e301 cmp !0xfe3c8,0x1
ram:026f4c df6b bnz $ 0x26fb9
ram:026f4e af08e4 movw AX,!0xfe408
ram:026f51 e7 onew BC
ram:026f52 a3 incw BC
ram:026f53 c3 push BC
ram:026f54 12 movw BC,AX
ram:026f55 17 movw AX,HL
ram:026f56 c1 push AX
ram:026f57 491600 mov A,!0xf0016[BC]
ram:026f5a 9dd4 mov 0xffdf4,A
ram:026f5c 791400 movw AX,!0xf0014[BC]
ram:026f5f c1 push AX
ram:026f60 8dd4 mov A,0xffdf4
ram:026f62 9dd6 mov 0xffdf6,A
ram:026f64 c0 pop AX
ram:026f65 14 movw DE,AX
ram:026f66 301000 movw AX,0x10
ram:026f69 f7 clrw BC
ram:026f6a c1 push AX
ram:026f6b 8dd6 mov A,0xffdf6
ram:026f6d 9efc mov CS,A
ram:026f6f c0 pop AX
ram:026f70 61ea call DE
ram:026f72 1004 addw SP,0x4
ram:026f74 f6 clrw AX
ram:026f75 614900 cmpw AX,[HL + 0x0]
ram:026f78 df3f bnz $ 0x26fb9
ram:026f7a bf68d9 movw !0xfd968,AX
ram:026f7d 5024 mov ,0x24
ram:026f7f c1 push AX
ram:026f80 f6 clrw AX
ram:026f81 c1 push AX
ram:026f82 ac02 movw AX,[HL + 0x2]
ram:026f84 fc40e500 call !!0xe540
ram:026f88 1004 addw SP,0x4
ram:026f8a af02e4 movw AX,!0xfe402
ram:026f8d 346ad9 movw DE,0xd96a
ram:026f90 c5 push DE
ram:026f91 14 movw DE,AX
ram:026f92 8a1a mov A,[DE + 0x1a]
ram:026f94 9efc mov CS,A
ram:026f96 aa18 movw AX,[DE + 0x18]
ram:026f98 14 movw DE,AX
ram:026f99 305900 movw AX,0x59
ram:026f9c 61ea call DE
ram:026f9e c0 pop AX
ram:026f9f 4067d904 cmp !0xfd967,0x4
ram:026fa3 df14 bnz $ 0x26fb9
ram:026fa5 af08e4 movw AX,!0xfe408
ram:026fa8 3468d9 movw DE,0xd968
ram:026fab c5 push DE
ram:026fac 14 movw DE,AX
ram:026fad 8a0e mov A,[DE + 0xe]
ram:026faf 9efc mov CS,A
ram:026fb1 aa0c movw AX,[DE + 0xc]
ram:026fb3 14 movw DE,AX
ram:026fb4 e6 onew AX
ram:026fb5 a1 incw AX
ram:026fb6 61ea call DE
ram:026fb8 c0 pop AX
ram:026fb9 fc010902 call !!0x20901
ram:026fbd ac04 movw AX,[HL + 0x4]
ram:026fbf 14 movw DE,AX
ram:026fc0 aa04 movw AX,[DE + 0x4]
ram:026fc2 a1 incw AX
ram:026fc3 ba04 movw [DE + 0x4],AX
ram:026fc5 e7 onew BC
ram:026fc6 1006 addw SP,0x6
ram:026fc8 c6 pop HL
ram:026fc9 d7 ret
ram:027026 c7 push HL
ram:027027 16 movw HL,AX
ram:027028 fc98f600 call !!0xf698
ram:02702c 66 mov A,
ram:02702d 9fc8e3 mov !0xfe3c8,A
ram:027030 cf65d903 mov !0xfd965,0x3
ram:027034 303200 movw AX,0x32
ram:027037 c1 push AX
ram:027038 30076f movw AX,0x6f07
ram:02703b 5202 mov ,0x2
ram:02703d f3 clrb B
ram:02703e fcea7d00 call !!0x7dea
ram:027042 c0 pop AX
ram:027043 62 mov A,
ram:027044 9f6ed9 mov !0xfd96e,A
ram:027047 c6 pop HL
ram:027048 d7 ret
ram:027049 d7 ret
ram:02704a c7 push HL
ram:02704b 16 movw HL,AX
ram:02704c fc3ee000 call !!0xe03e
ram:027050 17 movw AX,HL
ram:027051 f1 clrb A
ram:027052 04d0e3 addw AX,0xe3d0
ram:027055 14 movw DE,AX
ram:027056 89 mov A,[DE]
ram:027057 5c7f and A,#0x7f
ram:027059 99 mov [DE],A
ram:02705a 66 mov A,
ram:02705b 72 mov ,A
ram:02705c 38d1e3ff mov !0xfe3d1[C],0xff
ram:027060 fc62e000 call !!0xe062
ram:027064 66 mov A,
ram:027065 f0 clrb X
ram:027066 317e shrw AX,0x7
ram:027068 12 movw BC,AX
ram:027069 4100 mov ES,0x0
ram:02706b 1179f06d movw AX,ES:!0xf6df0[BC]
ram:02706f fcfb8700 call !!0x87fb
ram:027073 92 dec 
ram:027074 dd18 bz $ 0x2708e
ram:027076 fc3ee000 call !!0xe03e
ram:02707a 17 movw AX,HL
ram:02707b f1 clrb A
ram:02707c 04d0e3 addw AX,0xe3d0
ram:02707f 14 movw DE,AX
ram:027080 89 mov A,[DE]
ram:027081 6c80 or A,#0x80
ram:027083 99 mov [DE],A
ram:027084 66 mov A,
ram:027085 72 mov ,A
ram:027086 38d1e300 mov !0xfe3d1[C],0x0
ram:02708a fc62e000 call !!0xe062
ram:02708e c6 pop HL
ram:02708f d7 ret
ram:027090 ec947002 br !!0x27094
ram:027094 c7 push HL
ram:027095 f5cbe3 clrb !0xfe3cb
ram:027098 5700 mov ,0x0
ram:02709a 67 mov A,
ram:02709b 4c05 cmp A,#0x5
ram:02709d de2d bnc $ 0x270cc
ram:02709f f0 clrb X
ram:0270a0 317e shrw AX,0x7
ram:0270a2 04e264 addw AX,0x64e2
ram:0270a5 14 movw DE,AX
ram:0270a6 4100 mov ES,0x0
ram:0270a8 11a9 movw AX,ES:[DE]
ram:0270aa 6168 or A,
ram:0270ac dd1b bz $ 0x270c9
ram:0270ae 67 mov A,
ram:0270af 73 mov ,A
ram:0270b0 4100 mov ES,0x0
ram:0270b2 1109dc64 mov A,ES:!0xf64dc[B]
ram:0270b6 318e shrw AX,0x8
ram:0270b8 c1 push AX
ram:0270b9 67 mov A,
ram:0270ba f0 clrb X
ram:0270bb 317e shrw AX,0x7
ram:0270bd 12 movw BC,AX
ram:0270be 4100 mov ES,0x0
ram:0270c0 1179e264 movw AX,ES:!0xf64e2[BC]
ram:0270c4 fcb2de00 call !!0xdeb2
ram:0270c8 c0 pop AX
ram:0270c9 87 inc 
ram:0270ca efce br $ 0x2709a
ram:0270cc fc057402 call !!0x27405
ram:0270d0 300400 movw AX,0x4
ram:0270d3 c1 push AX
ram:0270d4 30cce3 movw AX,0xe3cc
ram:0270d7 fcb2de00 call !!0xdeb2
ram:0270db c0 pop AX
ram:0270dc 5600 mov ,0x0
ram:0270de 66 mov A,
ram:0270df d1 cmp0 A
ram:0270e0 df50 bnz $ 0x27132
ram:0270e2 f0 clrb X
ram:0270e3 317e shrw AX,0x7
ram:0270e5 12 movw BC,AX
ram:0270e6 4100 mov ES,0x0
ram:0270e8 1179f06d movw AX,ES:!0xf6df0[BC]
ram:0270ec 01 addw AX,AX
ram:0270ed 04b264 addw AX,0x64b2
ram:0270f0 14 movw DE,AX
ram:0270f1 4100 mov ES,0x0
ram:0270f3 11a9 movw AX,ES:[DE]
ram:0270f5 6168 or A,
ram:0270f7 dd28 bz $ 0x27121
ram:0270f9 4100 mov ES,0x0
ram:0270fb 1179f06d movw AX,ES:!0xf6df0[BC]
ram:0270ff 12 movw BC,AX
ram:027100 4100 mov ES,0x0
ram:027102 1149b064 mov A,ES:!0xf64b0[BC]
ram:027106 318e shrw AX,0x8
ram:027108 c1 push AX
ram:027109 66 mov A,
ram:02710a f0 clrb X
ram:02710b 317e shrw AX,0x7
ram:02710d 12 movw BC,AX
ram:02710e 4100 mov ES,0x0
ram:027110 1179f06d movw AX,ES:!0xf6df0[BC]
ram:027114 01 addw AX,AX
ram:027115 12 movw BC,AX
ram:027116 4100 mov ES,0x0
ram:027118 1179b264 movw AX,ES:!0xf64b2[BC]
ram:02711c fcb2de00 call !!0xdeb2
ram:027120 c0 pop AX
ram:027121 66 mov A,
ram:027122 72 mov ,A
ram:027123 38d0e300 mov !0xfe3d0[C],0x0
ram:027127 38d1e300 mov !0xfe3d1[C],0x0
ram:02712b 38cae300 mov !0xfe3ca[C],0x0
ram:02712f 86 inc 
ram:027130 efac br $ 0x270de
ram:027132 c6 pop HL
ram:027133 d7 ret
ram:027134 8fcbe3 mov A,!0xfe3cb
ram:027137 5c08 and A,#0x8
ram:027139 d1 cmp0 A
ram:02713a df1a bnz $ 0x27156
ram:02713c fc057402 call !!0x27405
ram:027140 300400 movw AX,0x4
ram:027143 c1 push AX
ram:027144 30cce3 movw AX,0xe3cc
ram:027147 fcb2de00 call !!0xdeb2
ram:02714b c0 pop AX
ram:02714c 8fcbe3 mov A,!0xfe3cb
ram:02714f 5cfb and A,#0xfb
ram:027151 6c08 or A,#0x8
ram:027153 9fcbe3 mov !0xfe3cb,A
ram:027156 d7 ret
ram:027157 c7 push HL
ram:027158 8fcbe3 mov A,!0xfe3cb
ram:02715b 5c02 and A,#0x2
ram:02715d d1 cmp0 A
ram:02715e df32 bnz $ 0x27192
ram:027160 5600 mov ,0x0
ram:027162 66 mov A,
ram:027163 d1 cmp0 A
ram:027164 df1e bnz $ 0x27184
ram:027166 73 mov ,A
ram:027167 4100 mov ES,0x0
ram:027169 1109f26d mov A,ES:!0xf6df2[B]
ram:02716d 72 mov ,A
ram:02716e 18d0e3 mov !0xfe3d0[B],A
ram:027171 66 mov A,
ram:027172 72 mov ,A
ram:027173 38d1e300 mov !0xfe3d1[C],0x0
ram:027177 4100 mov ES,0x0
ram:027179 1109e86d mov A,ES:!0xf6de8[B]
ram:02717d 72 mov ,A
ram:02717e 18cae3 mov !0xfe3ca[B],A
ram:027181 86 inc 
ram:027182 efde br $ 0x27162
ram:027184 fc147b02 call !!0x27b14
ram:027188 8fcbe3 mov A,!0xfe3cb
ram:02718b 5cfe and A,#0xfe
ram:02718d 6c02 or A,#0x2
ram:02718f 9fcbe3 mov !0xfe3cb,A
ram:027192 c6 pop HL
ram:027193 d7 ret
ram:027202 fc0a7202 call !!0x2720a
ram:027206 ec0b7202 br !!0x2720b
ram:02720a d7 ret
ram:02720b 8fcbe3 mov A,!0xfe3cb
ram:02720e 5c08 and A,#0x8
ram:027210 d1 cmp0 A
ram:027211 d7 ret
ram:027212 fc1a7202 call !!0x2721a
ram:027216 ecd47202 br !!0x272d4
ram:02721a c7 push HL
ram:02721b 2004 subw SP,0x4
ram:02721d fbf8ff movw HL,!0xffff8
ram:027220 8fcbe3 mov A,!0xfe3cb
ram:027223 5c03 and A,#0x3
ram:027225 d1 cmp0 A
ram:027226 61f8 sknz
ram:027228 eea500 _br $! 0x272d0
ram:02722b cc0301 mov [HL + 0x3],0x1
ram:02722e 616903 dec [HL + 0x3]
ram:027231 8c03 mov A,[HL + 0x3]
ram:027233 f0 clrb X
ram:027234 317e shrw AX,0x7
ram:027236 12 movw BC,AX
ram:027237 4100 mov ES,0x0
ram:027239 1179f06d movw AX,ES:!0xf6df0[BC]
ram:02723d bb movw [HL],AX
ram:02723e f6 clrw AX
ram:02723f b1 decw AX
ram:027240 614900 cmpw AX,[HL + 0x0]
ram:027243 61f8 sknz
ram:027245 ee8000 _br $! 0x272c8
ram:027248 ab movw AX,[HL]
ram:027249 12 movw BC,AX
ram:02724a 4100 mov ES,0x0
ram:02724c 1149c064 mov A,ES:!0xf64c0[BC]
ram:027250 73 mov ,A
ram:027251 0948c0 mov A,!0xfc048[B]
ram:027254 72 mov ,A
ram:027255 ab movw AX,[HL]
ram:027256 04c264 addw AX,0x64c2
ram:027259 14 movw DE,AX
ram:02725a 4100 mov ES,0x0
ram:02725c 1189 mov A,ES:[DE]
ram:02725e 6152 and ,A
ram:027260 d2 cmp0 C
ram:027261 dd65 bz $ 0x272c8
ram:027263 fc3ee000 call !!0xe03e
ram:027267 ab movw AX,[HL]
ram:027268 12 movw BC,AX
ram:027269 4100 mov ES,0x0
ram:02726b 1149c264 mov A,ES:!0xf64c2[BC]
ram:02726f 7cff xor A,#0xff
ram:027271 72 mov ,A
ram:027272 ab movw AX,[HL]
ram:027273 04c064 addw AX,0x64c0
ram:027276 14 movw DE,AX
ram:027277 4100 mov ES,0x0
ram:027279 1189 mov A,ES:[DE]
ram:02727b 318e shrw AX,0x8
ram:02727d 0448c0 addw AX,0xc048
ram:027280 14 movw DE,AX
ram:027281 89 mov A,[DE]
ram:027282 615a and A,
ram:027284 99 mov [DE],A
ram:027285 8c03 mov A,[HL + 0x3]
ram:027287 73 mov ,A
ram:027288 4100 mov ES,0x0
ram:02728a 1109e96d mov A,ES:!0xf6de9[B]
ram:02728e 72 mov ,A
ram:02728f 8c03 mov A,[HL + 0x3]
ram:027291 73 mov ,A
ram:027292 62 mov A,
ram:027293 18d1e3 mov !0xfe3d1[B],A
ram:027296 fc62e000 call !!0xe062
ram:02729a 8c03 mov A,[HL + 0x3]
ram:02729c f0 clrb X
ram:02729d 316e shrw AX,0x6
ram:02729f 04ec6d addw AX,0x6dec
ram:0272a2 14 movw DE,AX
ram:0272a3 4100 mov ES,0x0
ram:0272a5 118a02 mov A,ES:[DE + 0x2]
ram:0272a8 9dd4 mov 0xffdf4,A
ram:0272aa 11a9 movw AX,ES:[DE]
ram:0272ac d4d4 cmp0 0xffdf4
ram:0272ae df02 bnz $ 0x272b2
ram:0272b0 f7 clrw BC
ram:0272b1 43 cmpw AX,BC
ram:0272b2 dd14 bz $ 0x272c8
ram:0272b4 8c03 mov A,[HL + 0x3]
ram:0272b6 f0 clrb X
ram:0272b7 316e shrw AX,0x6
ram:0272b9 04ec6d addw AX,0x6dec
ram:0272bc 14 movw DE,AX
ram:0272bd 4100 mov ES,0x0
ram:0272bf 118a02 mov A,ES:[DE + 0x2]
ram:0272c2 9efc mov CS,A
ram:0272c4 11a9 movw AX,ES:[DE]
ram:0272c6 61ca call AX
ram:0272c8 8c03 mov A,[HL + 0x3]
ram:0272ca d1 cmp0 A
ram:0272cb 61e8 skz
ram:0272cd ee5eff _br $! 0x2722e
ram:0272d0 1004 addw SP,0x4
ram:0272d2 c6 pop HL
ram:0272d3 d7 ret
ram:0272d4 c7 push HL
ram:0272d5 8fcbe3 mov A,!0xfe3cb
ram:0272d8 5c02 and A,#0x2
ram:0272da d1 cmp0 A
ram:0272db dd71 bz $ 0x2734e
ram:0272dd 5601 mov ,0x1
ram:0272df 96 dec 
ram:0272e0 fc3ee000 call !!0xe03e
ram:0272e4 17 movw AX,HL
ram:0272e5 f1 clrb A
ram:0272e6 04d1e3 addw AX,0xe3d1
ram:0272e9 14 movw DE,AX
ram:0272ea 89 mov A,[DE]
ram:0272eb 81 inc 
ram:0272ec dd07 bz $ 0x272f5
ram:0272ee 89 mov A,[DE]
ram:0272ef d1 cmp0 A
ram:0272f0 dd03 bz $ 0x272f5
ram:0272f2 89 mov A,[DE]
ram:0272f3 91 dec 
ram:0272f4 99 mov [DE],A
ram:0272f5 fc62e000 call !!0xe062
ram:0272f9 66 mov A,
ram:0272fa 73 mov ,A
ram:0272fb 09d0e3 mov A,!0xfe3d0[B]
ram:0272fe 5c01 and A,#0x1
ram:027300 d1 cmp0 A
ram:027301 dd31 bz $ 0x27334
ram:027303 17 movw AX,HL
ram:027304 f1 clrb A
ram:027305 04cae3 addw AX,0xe3ca
ram:027308 14 movw DE,AX
ram:027309 89 mov A,[DE]
ram:02730a d1 cmp0 A
ram:02730b dd03 bz $ 0x27310
ram:02730d 89 mov A,[DE]
ram:02730e 91 dec 
ram:02730f 99 mov [DE],A
ram:027310 66 mov A,
ram:027311 73 mov ,A
ram:027312 09cae3 mov A,!0xfe3ca[B]
ram:027315 d1 cmp0 A
ram:027316 df1c bnz $ 0x27334
ram:027318 4100 mov ES,0x0
ram:02731a 1109ea6d mov A,ES:!0xf6dea[B]
ram:02731e 72 mov ,A
ram:02731f 18cae3 mov !0xfe3ca[B],A
ram:027322 fc3ee000 call !!0xe03e
ram:027326 17 movw AX,HL
ram:027327 f1 clrb A
ram:027328 04d0e3 addw AX,0xe3d0
ram:02732b 14 movw DE,AX
ram:02732c 89 mov A,[DE]
ram:02732d 6c80 or A,#0x80
ram:02732f 99 mov [DE],A
ram:027330 fc62e000 call !!0xe062
ram:027334 66 mov A,
ram:027335 73 mov ,A
ram:027336 09d0e3 mov A,!0xfe3d0[B]
ram:027339 5c80 and A,#0x80
ram:02733b d1 cmp0 A
ram:02733c dd0c bz $ 0x2734a
ram:02733e 09d1e3 mov A,!0xfe3d1[B]
ram:027341 d1 cmp0 A
ram:027342 df06 bnz $ 0x2734a
ram:027344 17 movw AX,HL
ram:027345 f1 clrb A
ram:027346 fc4a7002 call !!0x2704a
ram:02734a 66 mov A,
ram:02734b d1 cmp0 A
ram:02734c df91 bnz $ 0x272df
ram:02734e c6 pop HL
ram:02734f d7 ret
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
ram:027405 d7 ret
ram:027406 c7 push HL
ram:027407 5600 mov ,0x0
ram:027409 8fcee3 mov A,!0xfe3ce
ram:02740c 5c04 and A,#0x4
ram:02740e d1 cmp0 A
ram:02740f dd05 bz $ 0x27416
ram:027411 7128cee3 clr1 !0xfe3ce.0x2
ram:027415 86 inc 
ram:027416 8fcee3 mov A,!0xfe3ce
ram:027419 5c08 and A,#0x8
ram:02741b d1 cmp0 A
ram:02741c dd06 bz $ 0x27424
ram:02741e 7138cee3 clr1 !0xfe3ce.0x3
ram:027422 5601 mov ,0x1
ram:027424 8fcee3 mov A,!0xfe3ce
ram:027427 5c10 and A,#0x10
ram:027429 d1 cmp0 A
ram:02742a dd06 bz $ 0x27432
ram:02742c 7148cee3 clr1 !0xfe3ce.0x4
ram:027430 5601 mov ,0x1
ram:027432 8fcee3 mov A,!0xfe3ce
ram:027435 5c20 and A,#0x20
ram:027437 d1 cmp0 A
ram:027438 dd06 bz $ 0x27440
ram:02743a 7158cee3 clr1 !0xfe3ce.0x5
ram:02743e 5601 mov ,0x1
ram:027440 8fcee3 mov A,!0xfe3ce
ram:027443 5c40 and A,#0x40
ram:027445 d1 cmp0 A
ram:027446 dd06 bz $ 0x2744e
ram:027448 7168cee3 clr1 !0xfe3ce.0x6
ram:02744c 5601 mov ,0x1
ram:02744e 8fcee3 mov A,!0xfe3ce
ram:027451 5c80 and A,#0x80
ram:027453 d1 cmp0 A
ram:027454 dd06 bz $ 0x2745c
ram:027456 7178cee3 clr1 !0xfe3ce.0x7
ram:02745a 5601 mov ,0x1
ram:02745c 8fcfe3 mov A,!0xfe3cf
ram:02745f 5c01 and A,#0x1
ram:027461 d1 cmp0 A
ram:027462 dd06 bz $ 0x2746a
ram:027464 7108cfe3 clr1 !0xfe3cf.0x0
ram:027468 5601 mov ,0x1
ram:02746a 66 mov A,
ram:02746b 91 dec 
ram:02746c dd0a bz $ 0x27478
ram:02746e d5e8e5 cmp0 !0xfe5e8
ram:027471 dd16 bz $ 0x27489
ram:027473 d5eae5 cmp0 !0xfe5ea
ram:027476 dd11 bz $ 0x27489
ram:027478 345ec8 movw DE,0xc85e
ram:02747b c5 push DE
ram:02747c 300800 movw AX,0x8
ram:02747f c1 push AX
ram:027480 301403 movw AX,0x314
ram:027483 fc3f7702 call !!0x2773f
ram:027487 1004 addw SP,0x4
ram:027489 c6 pop HL
ram:02748a d7 ret
ram:02748b c7 push HL
ram:02748c 5600 mov ,0x0
ram:02748e 8fcde3 mov A,!0xfe3cd
ram:027491 5c40 and A,#0x40
ram:027493 d1 cmp0 A
ram:027494 dd05 bz $ 0x2749b
ram:027496 7168cde3 clr1 !0xfe3cd.0x6
ram:02749a 86 inc 
ram:02749b 8fcde3 mov A,!0xfe3cd
ram:02749e 5c80 and A,#0x80
ram:0274a0 d1 cmp0 A
ram:0274a1 dd06 bz $ 0x274a9
ram:0274a3 7178cde3 clr1 !0xfe3cd.0x7
ram:0274a7 5601 mov ,0x1
ram:0274a9 8fcee3 mov A,!0xfe3ce
ram:0274ac 5c01 and A,#0x1
ram:0274ae d1 cmp0 A
ram:0274af dd06 bz $ 0x274b7
ram:0274b1 7108cee3 clr1 !0xfe3ce.0x0
ram:0274b5 5601 mov ,0x1
ram:0274b7 8fcee3 mov A,!0xfe3ce
ram:0274ba 5c02 and A,#0x2
ram:0274bc d1 cmp0 A
ram:0274bd dd06 bz $ 0x274c5
ram:0274bf 7118cee3 clr1 !0xfe3ce.0x1
ram:0274c3 5601 mov ,0x1
ram:0274c5 66 mov A,
ram:0274c6 91 dec 
ram:0274c7 dd0a bz $ 0x274d3
ram:0274c9 d5e8e5 cmp0 !0xfe5e8
ram:0274cc dd16 bz $ 0x274e4
ram:0274ce d5eae5 cmp0 !0xfe5ea
ram:0274d1 dd11 bz $ 0x274e4
ram:0274d3 345ac8 movw DE,0xc85a
ram:0274d6 c5 push DE
ram:0274d7 300400 movw AX,0x4
ram:0274da c1 push AX
ram:0274db 301503 movw AX,0x315
ram:0274de fc3f7702 call !!0x2773f
ram:0274e2 1004 addw SP,0x4
ram:0274e4 c6 pop HL
ram:0274e5 d7 ret
ram:0274e6 c7 push HL
ram:0274e7 5600 mov ,0x0
ram:0274e9 8fcce3 mov A,!0xfe3cc
ram:0274ec 5c04 and A,#0x4
ram:0274ee d1 cmp0 A
ram:0274ef dd05 bz $ 0x274f6
ram:0274f1 7128cce3 clr1 !0xfe3cc.0x2
ram:0274f5 86 inc 
ram:0274f6 8fcce3 mov A,!0xfe3cc
ram:0274f9 5c08 and A,#0x8
ram:0274fb d1 cmp0 A
ram:0274fc dd06 bz $ 0x27504
ram:0274fe 7138cce3 clr1 !0xfe3cc.0x3
ram:027502 5601 mov ,0x1
ram:027504 8fcce3 mov A,!0xfe3cc
ram:027507 5c10 and A,#0x10
ram:027509 d1 cmp0 A
ram:02750a dd06 bz $ 0x27512
ram:02750c 7148cce3 clr1 !0xfe3cc.0x4
ram:027510 5601 mov ,0x1
ram:027512 8fcce3 mov A,!0xfe3cc
ram:027515 5c20 and A,#0x20
ram:027517 d1 cmp0 A
ram:027518 dd06 bz $ 0x27520
ram:02751a 7158cce3 clr1 !0xfe3cc.0x5
ram:02751e 5601 mov ,0x1
ram:027520 8fcce3 mov A,!0xfe3cc
ram:027523 5c40 and A,#0x40
ram:027525 d1 cmp0 A
ram:027526 dd06 bz $ 0x2752e
ram:027528 7168cce3 clr1 !0xfe3cc.0x6
ram:02752c 5601 mov ,0x1
ram:02752e 8fcce3 mov A,!0xfe3cc
ram:027531 5c80 and A,#0x80
ram:027533 d1 cmp0 A
ram:027534 dd06 bz $ 0x2753c
ram:027536 7178cce3 clr1 !0xfe3cc.0x7
ram:02753a 5601 mov ,0x1
ram:02753c 8fcde3 mov A,!0xfe3cd
ram:02753f 5c01 and A,#0x1
ram:027541 d1 cmp0 A
ram:027542 dd06 bz $ 0x2754a
ram:027544 7108cde3 clr1 !0xfe3cd.0x0
ram:027548 5601 mov ,0x1
ram:02754a 8fcde3 mov A,!0xfe3cd
ram:02754d 5c02 and A,#0x2
ram:02754f d1 cmp0 A
ram:027550 dd06 bz $ 0x27558
ram:027552 7118cde3 clr1 !0xfe3cd.0x1
ram:027556 5601 mov ,0x1
ram:027558 8fcde3 mov A,!0xfe3cd
ram:02755b 5c04 and A,#0x4
ram:02755d d1 cmp0 A
ram:02755e dd06 bz $ 0x27566
ram:027560 7128cde3 clr1 !0xfe3cd.0x2
ram:027564 5601 mov ,0x1
ram:027566 8fcde3 mov A,!0xfe3cd
ram:027569 5c08 and A,#0x8
ram:02756b d1 cmp0 A
ram:02756c dd06 bz $ 0x27574
ram:02756e 7138cde3 clr1 !0xfe3cd.0x3
ram:027572 5601 mov ,0x1
ram:027574 8fcde3 mov A,!0xfe3cd
ram:027577 5c10 and A,#0x10
ram:027579 d1 cmp0 A
ram:02757a dd06 bz $ 0x27582
ram:02757c 7148cde3 clr1 !0xfe3cd.0x4
ram:027580 5601 mov ,0x1
ram:027582 8fcde3 mov A,!0xfe3cd
ram:027585 5c20 and A,#0x20
ram:027587 d1 cmp0 A
ram:027588 dd06 bz $ 0x27590
ram:02758a 7158cde3 clr1 !0xfe3cd.0x5
ram:02758e 5601 mov ,0x1
ram:027590 66 mov A,
ram:027591 91 dec 
ram:027592 dd0a bz $ 0x2759e
ram:027594 d5e8e5 cmp0 !0xfe5e8
ram:027597 dd16 bz $ 0x275af
ram:027599 d5eae5 cmp0 !0xfe5ea
ram:02759c dd11 bz $ 0x275af
ram:02759e 3452c8 movw DE,0xc852
ram:0275a1 c5 push DE
ram:0275a2 300800 movw AX,0x8
ram:0275a5 c1 push AX
ram:0275a6 301b03 movw AX,0x31b
ram:0275a9 fc3f7702 call !!0x2773f
ram:0275ad 1004 addw SP,0x4
ram:0275af c6 pop HL
ram:0275b0 d7 ret
ram:0275b1 c7 push HL
ram:0275b2 5600 mov ,0x0
ram:0275b4 8fcce3 mov A,!0xfe3cc
ram:0275b7 5c01 and A,#0x1
ram:0275b9 d1 cmp0 A
ram:0275ba dd05 bz $ 0x275c1
ram:0275bc 7108cce3 clr1 !0xfe3cc.0x0
ram:0275c0 86 inc 
ram:0275c1 66 mov A,
ram:0275c2 91 dec 
ram:0275c3 dd0a bz $ 0x275cf
ram:0275c5 d5e8e5 cmp0 !0xfe5e8
ram:0275c8 dd16 bz $ 0x275e0
ram:0275ca d5eae5 cmp0 !0xfe5ea
ram:0275cd dd11 bz $ 0x275e0
ram:0275cf 346cc8 movw DE,0xc86c
ram:0275d2 c5 push DE
ram:0275d3 300300 movw AX,0x3
ram:0275d6 c1 push AX
ram:0275d7 305805 movw AX,0x558
ram:0275da fc3f7702 call !!0x2773f
ram:0275de 1004 addw SP,0x4
ram:0275e0 c6 pop HL
ram:0275e1 d7 ret
ram:0275e2 c7 push HL
ram:0275e3 5600 mov ,0x0
ram:0275e5 8fcce3 mov A,!0xfe3cc
ram:0275e8 5c02 and A,#0x2
ram:0275ea d1 cmp0 A
ram:0275eb dd05 bz $ 0x275f2
ram:0275ed 7118cce3 clr1 !0xfe3cc.0x1
ram:0275f1 86 inc 
ram:0275f2 66 mov A,
ram:0275f3 91 dec 
ram:0275f4 dd0a bz $ 0x27600
ram:0275f6 d5e8e5 cmp0 !0xfe5e8
ram:0275f9 dd15 bz $ 0x27610
ram:0275fb d5eae5 cmp0 !0xfe5ea
ram:0275fe dd10 bz $ 0x27610
ram:027600 346ac8 movw DE,0xc86a
ram:027603 c5 push DE
ram:027604 e6 onew AX
ram:027605 a1 incw AX
ram:027606 c1 push AX
ram:027607 304805 movw AX,0x548
ram:02760a fc3f7702 call !!0x2773f
ram:02760e 1004 addw SP,0x4
ram:027610 c6 pop HL
ram:027611 d7 ret
ram:027612 d5e9e5 cmp0 !0xfe5e9
ram:027615 dd1c bz $ 0x27633
ram:027617 fc067402 call !!0x27406
ram:02761b fc8b7402 call !!0x2748b
ram:02761f fce67402 call !!0x274e6
ram:027623 fcb17502 call !!0x275b1
ram:027627 fce27502 call !!0x275e2
ram:02762b d5e8e5 cmp0 !0xfe5e8
ram:02762e 61e8 skz
ram:027630 f5eae5 _clrb !0xfe5ea
ram:027633 d7 ret
ram:027634 c7 push HL
ram:027635 201a subw SP,0x1a
ram:027637 fbf8ff movw HL,!0xffff8
ram:02763a 8c18 mov A,[HL + 0x18]
ram:02763c 5cf0 and A,#0xf0
ram:02763e 9c18 mov [HL + 0x18],A
ram:027640 8c15 mov A,[HL + 0x15]
ram:027642 5c0f and A,#0xf
ram:027644 9c15 mov [HL + 0x15],A
ram:027646 8c19 mov A,[HL + 0x19]
ram:027648 5c3f and A,#0x3f
ram:02764a 9c19 mov [HL + 0x19],A
ram:02764c cc1402 mov [HL + 0x14],0x2
ram:02764f 8c15 mov A,[HL + 0x15]
ram:027651 5cf0 and A,#0xf0
ram:027653 9c15 mov [HL + 0x15],A
ram:027655 8c16 mov A,[HL + 0x16]
ram:027657 5c3f and A,#0x3f
ram:027659 9c16 mov [HL + 0x16],A
ram:02765b 8c12 mov A,[HL + 0x12]
ram:02765d 5c01 and A,#0x1
ram:02765f 9c12 mov [HL + 0x12],A
ram:027661 cc1300 mov [HL + 0x13],0x0
ram:027664 8c12 mov A,[HL + 0x12]
ram:027666 5cfe and A,#0xfe
ram:027668 9c12 mov [HL + 0x12],A
ram:02766a 8c16 mov A,[HL + 0x16]
ram:02766c 5cc0 and A,#0xc0
ram:02766e 9c16 mov [HL + 0x16],A
ram:027670 cc1700 mov [HL + 0x17],0x0
ram:027673 8c18 mov A,[HL + 0x18]
ram:027675 5c0f and A,#0xf
ram:027677 9c18 mov [HL + 0x18],A
ram:027679 8c19 mov A,[HL + 0x19]
ram:02767b 5cc0 and A,#0xc0
ram:02767d 9c19 mov [HL + 0x19],A
ram:02767f 8c0e mov A,[HL + 0xe]
ram:027681 6cfe or A,#0xfe
ram:027683 9c0e mov [HL + 0xe],A
ram:027685 8c0f mov A,[HL + 0xf]
ram:027687 6cfe or A,#0xfe
ram:027689 9c0f mov [HL + 0xf],A
ram:02768b cc1100 mov [HL + 0x11],0x0
ram:02768e 8c10 mov A,[HL + 0x10]
ram:027690 6cfe or A,#0xfe
ram:027692 9c10 mov [HL + 0x10],A
ram:027694 8c0e mov A,[HL + 0xe]
ram:027696 5cfe and A,#0xfe
ram:027698 9c0e mov [HL + 0xe],A
ram:02769a 8c0f mov A,[HL + 0xf]
ram:02769c 5cfe and A,#0xfe
ram:02769e 9c0f mov [HL + 0xf],A
ram:0276a0 8c10 mov A,[HL + 0x10]
ram:0276a2 5cfe and A,#0xfe
ram:0276a4 9c10 mov [HL + 0x10],A
ram:0276a6 8c06 mov A,[HL + 0x6]
ram:0276a8 5c7f and A,#0x7f
ram:0276aa 9c06 mov [HL + 0x6],A
ram:0276ac cc07ff mov [HL + 0x7],0xff
ram:0276af 8c06 mov A,[HL + 0x6]
ram:0276b1 6c03 or A,#0x3
ram:0276b3 9c06 mov [HL + 0x6],A
ram:0276b5 8c0d mov A,[HL + 0xd]
ram:0276b7 6cf0 or A,#0xf0
ram:0276b9 9c0d mov [HL + 0xd],A
ram:0276bb cc0cff mov [HL + 0xc],0xff
ram:0276be cc0bff mov [HL + 0xb],0xff
ram:0276c1 cc0a7f mov [HL + 0xa],0x7f
ram:0276c4 cc0900 mov [HL + 0x9],0x0
ram:0276c7 cc0800 mov [HL + 0x8],0x0
ram:0276ca 8c06 mov A,[HL + 0x6]
ram:0276cc 6c7c or A,#0x7c
ram:0276ce 9c06 mov [HL + 0x6],A
ram:0276d0 8c0d mov A,[HL + 0xd]
ram:0276d2 5cf0 and A,#0xf0
ram:0276d4 9c0d mov [HL + 0xd],A
ram:0276d6 cc0500 mov [HL + 0x5],0x0
ram:0276d9 cc0400 mov [HL + 0x4],0x0
ram:0276dc cc0000 mov [HL + 0x0],0x0
ram:0276df cc0100 mov [HL + 0x1],0x0
ram:0276e2 cc02ff mov [HL + 0x2],0xff
ram:0276e5 17 movw AX,HL
ram:0276e6 040600 addw AX,0x6
ram:0276e9 c1 push AX
ram:0276ea 300800 movw AX,0x8
ram:0276ed c1 push AX
ram:0276ee 301403 movw AX,0x314
ram:0276f1 fc3f7702 call !!0x2773f
ram:0276f5 1004 addw SP,0x4
ram:0276f7 17 movw AX,HL
ram:0276f8 040e00 addw AX,0xe
ram:0276fb c1 push AX
ram:0276fc 300400 movw AX,0x4
ram:0276ff c1 push AX
ram:027700 301503 movw AX,0x315
ram:027703 fc3f7702 call !!0x2773f
ram:027707 1004 addw SP,0x4
ram:027709 17 movw AX,HL
ram:02770a 041200 addw AX,0x12
ram:02770d c1 push AX
ram:02770e 300800 movw AX,0x8
ram:027711 c1 push AX
ram:027712 301b03 movw AX,0x31b
ram:027715 fc3f7702 call !!0x2773f
ram:027719 1004 addw SP,0x4
ram:02771b 17 movw AX,HL
ram:02771c c1 push AX
ram:02771d 300300 movw AX,0x3
ram:027720 c1 push AX
ram:027721 305805 movw AX,0x558
ram:027724 fc3f7702 call !!0x2773f
ram:027728 1004 addw SP,0x4
ram:02772a 17 movw AX,HL
ram:02772b 040400 addw AX,0x4
ram:02772e c1 push AX
ram:02772f e6 onew AX
ram:027730 a1 incw AX
ram:027731 c1 push AX
ram:027732 304805 movw AX,0x548
ram:027735 fc3f7702 call !!0x2773f
ram:027739 1004 addw SP,0x4
ram:02773b 101a addw SP,0x1a
ram:02773d c6 pop HL
ram:02773e d7 ret
ram:02773f c7 push HL
ram:027740 c1 push AX
ram:027741 200a subw SP,0xa
ram:027743 fbf8ff movw HL,!0xffff8
ram:027746 cc0000 mov [HL + 0x0],0x0
ram:027749 ac0a movw AX,[HL + 0xa]
ram:02774b e7 onew BC
ram:02774c 241403 subw AX,0x314
ram:02774f dd1e bz $ 0x2776f
ram:027751 23 subw AX,BC
ram:027752 dd20 bz $ 0x27774
ram:027754 240600 subw AX,0x6
ram:027757 dd20 bz $ 0x27779
ram:027759 242d02 subw AX,0x22d
ram:02775c dd07 bz $ 0x27765
ram:02775e 241000 subw AX,0x10
ram:027761 dd07 bz $ 0x2776a
ram:027763 ef17 br $ 0x2777c
ram:027765 cc0064 mov [HL + 0x0],0x64
ram:027768 ef12 br $ 0x2777c
ram:02776a cc0065 mov [HL + 0x0],0x65
ram:02776d ef0d br $ 0x2777c
ram:02776f cc0066 mov [HL + 0x0],0x66
ram:027772 ef08 br $ 0x2777c
ram:027774 cc0067 mov [HL + 0x0],0x67
ram:027777 ef03 br $ 0x2777c
ram:027779 cc0068 mov [HL + 0x0],0x68
ram:02777c 8b mov A,[HL]
ram:02777d d1 cmp0 A
ram:02777e dd4f bz $ 0x277cf
ram:027780 8c12 mov A,[HL + 0x12]
ram:027782 9c01 mov [HL + 0x1],A
ram:027784 8c12 mov A,[HL + 0x12]
ram:027786 318e shrw AX,0x8
ram:027788 c1 push AX
ram:027789 ac14 movw AX,[HL + 0x14]
ram:02778b c1 push AX
ram:02778c 17 movw AX,HL
ram:02778d 040200 addw AX,0x2
ram:027790 fc857d02 call !!0x27d85
ram:027794 1004 addw SP,0x4
ram:027796 db02e4 movw BC,!0xfe402
ram:027799 17 movw AX,HL
ram:02779a a1 incw AX
ram:02779b c1 push AX
ram:02779c 491a00 mov A,!0xf001a[BC]
ram:02779f 9efc mov CS,A
ram:0277a1 791800 movw AX,!0xf0018[BC]
ram:0277a4 14 movw DE,AX
ram:0277a5 8b mov A,[HL]
ram:0277a6 318e shrw AX,0x8
ram:0277a8 61ea call DE
ram:0277aa c0 pop AX
ram:0277ab db18e4 movw BC,!0xfe418
ram:0277ae 8c12 mov A,[HL + 0x12]
ram:0277b0 318e shrw AX,0x8
ram:0277b2 c1 push AX
ram:0277b3 ac14 movw AX,[HL + 0x14]
ram:0277b5 c1 push AX
ram:0277b6 ac0a movw AX,[HL + 0xa]
ram:0277b8 c3 push BC
ram:0277b9 c4 pop DE
ram:0277ba f7 clrw BC
ram:0277bb bdd8 movw 0xffdf8,AX
ram:0277bd 13 movw AX,BC
ram:0277be bdda movw 0xffdfa,AX
ram:0277c0 8a12 mov A,[DE + 0x12]
ram:0277c2 9efc mov CS,A
ram:0277c4 aa10 movw AX,[DE + 0x10]
ram:0277c6 14 movw DE,AX
ram:0277c7 dada movw BC,0xffdfa
ram:0277c9 add8 movw AX,0xffdf8
ram:0277cb 61ea call DE
ram:0277cd 1004 addw SP,0x4
ram:0277cf 100c addw SP,0xc
ram:0277d1 c6 pop HL
ram:0277d2 d7 ret
ram:02785c c7 push HL
ram:02785d 16 movw HL,AX
ram:02785e fc3ee000 call !!0xe03e
ram:027862 8fcbe3 mov A,!0xfe3cb
ram:027865 5c0c and A,#0xc
ram:027867 d1 cmp0 A
ram:027868 dd11 bz $ 0x2787b
ram:02786a eb50c0 movw DE,!0xfc050
ram:02786d 8a02 mov A,[DE + 0x2]
ram:02786f 70 mov ,A
ram:027870 8f6ec8 mov A,!0xfc86e
ram:027873 6148 cmp A,
ram:027875 61e8 skz
ram:027877 7100cce3 _set1 !0xfe3cc.0x0
ram:02787b fc62e000 call !!0xe062
ram:02787f e7 onew BC
ram:027880 c6 pop HL
ram:027881 d7 ret
ram:027882 c7 push HL
ram:027883 16 movw HL,AX
ram:027884 fc3ee000 call !!0xe03e
ram:027888 8fcbe3 mov A,!0xfe3cb
ram:02788b 5c0c and A,#0xc
ram:02788d d1 cmp0 A
ram:02788e dd1a bz $ 0x278aa
ram:027890 eb50c0 movw DE,!0xfc050
ram:027893 8a01 mov A,[DE + 0x1]
ram:027895 70 mov ,A
ram:027896 8f6bc8 mov A,!0xfc86b
ram:027899 6148 cmp A,
ram:02789b df09 bnz $ 0x278a6
ram:02789d 89 mov A,[DE]
ram:02789e 70 mov ,A
ram:02789f 8f6ac8 mov A,!0xfc86a
ram:0278a2 6148 cmp A,
ram:0278a4 61e8 skz
ram:0278a6 7110cce3 _set1 !0xfe3cc.0x1
ram:0278aa fc62e000 call !!0xe062
ram:0278ae e7 onew BC
ram:0278af c6 pop HL
ram:0278b0 d7 ret
ram:0278b1 c7 push HL
ram:0278b2 16 movw HL,AX
ram:0278b3 fc3ee000 call !!0xe03e
ram:0278b7 8fcbe3 mov A,!0xfe3cb
ram:0278ba 5c0c and A,#0xc
ram:0278bc d1 cmp0 A
ram:0278bd 61f8 sknz
ram:0278bf ee0601 _br $! 0x279c8
ram:0278c2 eb50c0 movw DE,!0xfc050
ram:0278c5 89 mov A,[DE]
ram:0278c6 3149 shl A,0x4
ram:0278c8 315a shr A,0x5
ram:0278ca 70 mov ,A
ram:0278cb 8f52c8 mov A,!0xfc852
ram:0278ce 3149 shl A,0x4
ram:0278d0 315a shr A,0x5
ram:0278d2 6148 cmp A,
ram:0278d4 61e8 skz
ram:0278d6 7120cce3 _set1 !0xfe3cc.0x2
ram:0278da eb50c0 movw DE,!0xfc050
ram:0278dd 89 mov A,[DE]
ram:0278de 3129 shl A,0x2
ram:0278e0 316a shr A,0x6
ram:0278e2 70 mov ,A
ram:0278e3 8f52c8 mov A,!0xfc852
ram:0278e6 3129 shl A,0x2
ram:0278e8 316a shr A,0x6
ram:0278ea 6148 cmp A,
ram:0278ec 61e8 skz
ram:0278ee 7130cce3 _set1 !0xfe3cc.0x3
ram:0278f2 eb50c0 movw DE,!0xfc050
ram:0278f5 8a01 mov A,[DE + 0x1]
ram:0278f7 70 mov ,A
ram:0278f8 8f53c8 mov A,!0xfc853
ram:0278fb 6148 cmp A,
ram:0278fd 61e8 skz
ram:0278ff 7140cce3 _set1 !0xfe3cc.0x4
ram:027903 eb50c0 movw DE,!0xfc050
ram:027906 8a02 mov A,[DE + 0x2]
ram:027908 5c03 and A,#0x3
ram:02790a 70 mov ,A
ram:02790b 8f54c8 mov A,!0xfc854
ram:02790e 5c03 and A,#0x3
ram:027910 6148 cmp A,
ram:027912 61e8 skz
ram:027914 7150cce3 _set1 !0xfe3cc.0x5
ram:027918 eb50c0 movw DE,!0xfc050
ram:02791b 8a02 mov A,[DE + 0x2]
ram:02791d 3149 shl A,0x4
ram:02791f 316a shr A,0x6
ram:027921 70 mov ,A
ram:027922 8f54c8 mov A,!0xfc854
ram:027925 3149 shl A,0x4
ram:027927 316a shr A,0x6
ram:027929 6148 cmp A,
ram:02792b 61e8 skz
ram:02792d 7160cce3 _set1 !0xfe3cc.0x6
ram:027931 eb50c0 movw DE,!0xfc050
ram:027934 8a02 mov A,[DE + 0x2]
ram:027936 314a shr A,0x4
ram:027938 70 mov ,A
ram:027939 8f54c8 mov A,!0xfc854
ram:02793c 314a shr A,0x4
ram:02793e 6148 cmp A,
ram:027940 61e8 skz
ram:027942 7170cce3 _set1 !0xfe3cc.0x7
ram:027946 eb50c0 movw DE,!0xfc050
ram:027949 8a03 mov A,[DE + 0x3]
ram:02794b 5c0f and A,#0xf
ram:02794d 70 mov ,A
ram:02794e 8f55c8 mov A,!0xfc855
ram:027951 5c0f and A,#0xf
ram:027953 6148 cmp A,
ram:027955 61e8 skz
ram:027957 7100cde3 _set1 !0xfe3cd.0x0
ram:02795b eb50c0 movw DE,!0xfc050
ram:02795e 8a03 mov A,[DE + 0x3]
ram:027960 314a shr A,0x4
ram:027962 70 mov ,A
ram:027963 8f55c8 mov A,!0xfc855
ram:027966 314a shr A,0x4
ram:027968 6148 cmp A,
ram:02796a 61e8 skz
ram:02796c 7110cde3 _set1 !0xfe3cd.0x1
ram:027970 eb50c0 movw DE,!0xfc050
ram:027973 8a04 mov A,[DE + 0x4]
ram:027975 316a shr A,0x6
ram:027977 70 mov ,A
ram:027978 8f56c8 mov A,!0xfc856
ram:02797b 316a shr A,0x6
ram:02797d 6148 cmp A,
ram:02797f 61e8 skz
ram:027981 7120cde3 _set1 !0xfe3cd.0x2
ram:027985 eb50c0 movw DE,!0xfc050
ram:027988 8a06 mov A,[DE + 0x6]
ram:02798a 5c03 and A,#0x3
ram:02798c 70 mov ,A
ram:02798d 8f58c8 mov A,!0xfc858
ram:027990 5c03 and A,#0x3
ram:027992 6148 cmp A,
ram:027994 61e8 skz
ram:027996 7130cde3 _set1 !0xfe3cd.0x3
ram:02799a eb50c0 movw DE,!0xfc050
ram:02799d 8a06 mov A,[DE + 0x6]
ram:02799f 3149 shl A,0x4
ram:0279a1 316a shr A,0x6
ram:0279a3 70 mov ,A
ram:0279a4 8f58c8 mov A,!0xfc858
ram:0279a7 3149 shl A,0x4
ram:0279a9 316a shr A,0x6
ram:0279ab 6148 cmp A,
ram:0279ad 61e8 skz
ram:0279af 7140cde3 _set1 !0xfe3cd.0x4
ram:0279b3 eb50c0 movw DE,!0xfc050
ram:0279b6 8a07 mov A,[DE + 0x7]
ram:0279b8 316a shr A,0x6
ram:0279ba 70 mov ,A
ram:0279bb 8f59c8 mov A,!0xfc859
ram:0279be 316a shr A,0x6
ram:0279c0 6148 cmp A,
ram:0279c2 61e8 skz
ram:0279c4 7150cde3 _set1 !0xfe3cd.0x5
ram:0279c8 fc62e000 call !!0xe062
ram:0279cc e7 onew BC
ram:0279cd c6 pop HL
ram:0279ce d7 ret
ram:0279cf c7 push HL
ram:0279d0 16 movw HL,AX
ram:0279d1 fc3ee000 call !!0xe03e
ram:0279d5 8fcbe3 mov A,!0xfe3cb
ram:0279d8 5c0c and A,#0xc
ram:0279da d1 cmp0 A
ram:0279db dd4f bz $ 0x27a2c
ram:0279dd eb50c0 movw DE,!0xfc050
ram:0279e0 89 mov A,[DE]
ram:0279e1 311a shr A,0x1
ram:0279e3 70 mov ,A
ram:0279e4 8f5ac8 mov A,!0xfc85a
ram:0279e7 311a shr A,0x1
ram:0279e9 6148 cmp A,
ram:0279eb 61e8 skz
ram:0279ed 7160cde3 _set1 !0xfe3cd.0x6
ram:0279f1 eb50c0 movw DE,!0xfc050
ram:0279f4 8a01 mov A,[DE + 0x1]
ram:0279f6 311a shr A,0x1
ram:0279f8 70 mov ,A
ram:0279f9 8f5bc8 mov A,!0xfc85b
ram:0279fc 311a shr A,0x1
ram:0279fe 6148 cmp A,
ram:027a00 61e8 skz
ram:027a02 7170cde3 _set1 !0xfe3cd.0x7
ram:027a06 eb50c0 movw DE,!0xfc050
ram:027a09 8a02 mov A,[DE + 0x2]
ram:027a0b 311a shr A,0x1
ram:027a0d 70 mov ,A
ram:027a0e 8f5cc8 mov A,!0xfc85c
ram:027a11 311a shr A,0x1
ram:027a13 6148 cmp A,
ram:027a15 61e8 skz
ram:027a17 7100cee3 _set1 !0xfe3ce.0x0
ram:027a1b eb50c0 movw DE,!0xfc050
ram:027a1e 8a03 mov A,[DE + 0x3]
ram:027a20 70 mov ,A
ram:027a21 8f5dc8 mov A,!0xfc85d
ram:027a24 6148 cmp A,
ram:027a26 61e8 skz
ram:027a28 7110cee3 _set1 !0xfe3ce.0x1
ram:027a2c fc62e000 call !!0xe062
ram:027a30 e7 onew BC
ram:027a31 c6 pop HL
ram:027a32 d7 ret
ram:027a33 c7 push HL
ram:027a34 16 movw HL,AX
ram:027a35 fc3ee000 call !!0xe03e
ram:027a39 8fcbe3 mov A,!0xfe3cb
ram:027a3c 5c0c and A,#0xc
ram:027a3e d1 cmp0 A
ram:027a3f 61f8 sknz
ram:027a41 eec900 _br $! 0x27b0d
ram:027a44 eb50c0 movw DE,!0xfc050
ram:027a47 8a01 mov A,[DE + 0x1]
ram:027a49 70 mov ,A
ram:027a4a 8f5fc8 mov A,!0xfc85f
ram:027a4d 6148 cmp A,
ram:027a4f df0d bnz $ 0x27a5e
ram:027a51 89 mov A,[DE]
ram:027a52 5c03 and A,#0x3
ram:027a54 70 mov ,A
ram:027a55 8f5ec8 mov A,!0xfc85e
ram:027a58 5c03 and A,#0x3
ram:027a5a 6148 cmp A,
ram:027a5c 61e8 skz
ram:027a5e 7120cee3 _set1 !0xfe3ce.0x2
ram:027a62 eb50c0 movw DE,!0xfc050
ram:027a65 89 mov A,[DE]
ram:027a66 3149 shl A,0x4
ram:027a68 316a shr A,0x6
ram:027a6a 70 mov ,A
ram:027a6b 8f5ec8 mov A,!0xfc85e
ram:027a6e 3149 shl A,0x4
ram:027a70 316a shr A,0x6
ram:027a72 6148 cmp A,
ram:027a74 61e8 skz
ram:027a76 7130cee3 _set1 !0xfe3ce.0x3
ram:027a7a eb50c0 movw DE,!0xfc050
ram:027a7d 89 mov A,[DE]
ram:027a7e 3119 shl A,0x1
ram:027a80 315a shr A,0x5
ram:027a82 70 mov ,A
ram:027a83 8f5ec8 mov A,!0xfc85e
ram:027a86 3119 shl A,0x1
ram:027a88 315a shr A,0x5
ram:027a8a 6148 cmp A,
ram:027a8c 61e8 skz
ram:027a8e 7140cee3 _set1 !0xfe3ce.0x4
ram:027a92 eb50c0 movw DE,!0xfc050
ram:027a95 89 mov A,[DE]
ram:027a96 317a shr A,0x7
ram:027a98 70 mov ,A
ram:027a99 8f5ec8 mov A,!0xfc85e
ram:027a9c 317a shr A,0x7
ram:027a9e 6148 cmp A,
ram:027aa0 61e8 skz
ram:027aa2 7150cee3 _set1 !0xfe3ce.0x5
ram:027aa6 eb50c0 movw DE,!0xfc050
ram:027aa9 8a04 mov A,[DE + 0x4]
ram:027aab 317a shr A,0x7
ram:027aad 70 mov ,A
ram:027aae 8f62c8 mov A,!0xfc862
ram:027ab1 317a shr A,0x7
ram:027ab3 6148 cmp A,
ram:027ab5 df14 bnz $ 0x27acb
ram:027ab7 8a03 mov A,[DE + 0x3]
ram:027ab9 70 mov ,A
ram:027aba 8f61c8 mov A,!0xfc861
ram:027abd 6148 cmp A,
ram:027abf df0a bnz $ 0x27acb
ram:027ac1 8a02 mov A,[DE + 0x2]
ram:027ac3 70 mov ,A
ram:027ac4 8f60c8 mov A,!0xfc860
ram:027ac7 6148 cmp A,
ram:027ac9 61e8 skz
ram:027acb 7160cee3 _set1 !0xfe3ce.0x6
ram:027acf eb50c0 movw DE,!0xfc050
ram:027ad2 8a05 mov A,[DE + 0x5]
ram:027ad4 70 mov ,A
ram:027ad5 8f63c8 mov A,!0xfc863
ram:027ad8 6148 cmp A,
ram:027ada df0e bnz $ 0x27aea
ram:027adc 8a04 mov A,[DE + 0x4]
ram:027ade 5c7f and A,#0x7f
ram:027ae0 70 mov ,A
ram:027ae1 8f62c8 mov A,!0xfc862
ram:027ae4 5c7f and A,#0x7f
ram:027ae6 6148 cmp A,
ram:027ae8 61e8 skz
ram:027aea 7170cee3 _set1 !0xfe3ce.0x7
ram:027aee eb50c0 movw DE,!0xfc050
ram:027af1 8a07 mov A,[DE + 0x7]
ram:027af3 314a shr A,0x4
ram:027af5 70 mov ,A
ram:027af6 8f65c8 mov A,!0xfc865
ram:027af9 314a shr A,0x4
ram:027afb 6148 cmp A,
ram:027afd df0a bnz $ 0x27b09
ram:027aff 8a06 mov A,[DE + 0x6]
ram:027b01 70 mov ,A
ram:027b02 8f64c8 mov A,!0xfc864
ram:027b05 6148 cmp A,
ram:027b07 61e8 skz
ram:027b09 7100cfe3 _set1 !0xfe3cf.0x0
ram:027b0d fc62e000 call !!0xe062
ram:027b11 e7 onew BC
ram:027b12 c6 pop HL
ram:027b13 d7 ret
ram:027b14 fc3ee000 call !!0xe03e
ram:027b18 8f48c0 mov A,!0xfc048
ram:027b1b 5cfe and A,#0xfe
ram:027b1d 9f48c0 mov !0xfc048,A
ram:027b20 ec62e000 br !!0xe062
ram:027d59 c7 push HL
ram:027d5a 16 movw HL,AX
ram:027d5b 66 mov A,
ram:027d5c 91 dec 
ram:027d5d df07 bnz $ 0x27d66
ram:027d5f e566ea oneb !0xfea66
ram:027d62 cf6beaff mov !0xfea6b,0xff
ram:027d66 c6 pop HL
ram:027d67 d7 ret
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
ram:027d85 14 movw DE,AX
ram:027d86 aef8 movw AX,SP
ram:027d88 c7 push HL
ram:027d89 16 movw HL,AX
ram:027d8a ac06 movw AX,[HL + 0x6]
ram:027d8c 12 movw BC,AX
ram:027d8d c5 push DE
ram:027d8e ac04 movw AX,[HL + 0x4]
ram:027d90 16 movw HL,AX
ram:027d91 f6 clrw AX
ram:027d92 43 cmpw AX,BC
ram:027d93 dd07 bz $ 0x27d9c
ram:027d95 8b mov A,[HL]
ram:027d96 99 mov [DE],A
ram:027d97 a7 incw HL
ram:027d98 a5 incw DE
ram:027d99 b3 decw BC
ram:027d9a eff5 br $ 0x27d91
ram:027d9c c2 pop BC
ram:027d9d c6 pop HL
ram:027d9e d7 ret
