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
ram:0166f3 fcbc5c01 call !!0x15cbc
ram:0166f7 7108ebe1 clr1 !0xfe1eb.0x0
ram:0166fb 7138ebe1 clr1 !0xfe1eb.0x3
ram:0166ff 30b772 movw AX,0x72b7
ram:016702 bf16e7 movw !0xfe716,AX
ram:016705 cf18e701 mov !0xfe718,0x1
ram:016709 f5eae1 clrb !0xfe1ea
ram:01670c ee6702 br $! 0x16976
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
ram:017316 c7 push HL
ram:017317 c1 push AX
ram:017318 c1 push AX
ram:017319 fbf8ff movw HL,!0xffff8
ram:01731c cc01ff mov [HL + 0x1],0xff
ram:01731f 40eae103 cmp !0xfe1ea,0x3
ram:017323 dd04 bz $ 0x17329
ram:017325 f7 clrw BC
ram:017326 eea201 br $! 0x174cb
ram:017329 8c02 mov A,[HL + 0x2]
ram:01732b 320002 movw BC,0x200
ram:01732e f0 clrb X
ram:01732f d1 cmp0 A
ram:017330 61f8 sknz
ram:017332 ee8a00 _br $! 0x173bf
ram:017335 23 subw AX,BC
ram:017336 61f8 sknz
ram:017338 ee4001 _br $! 0x1747b
ram:01733b 2c1d sub A,#0x1d
ram:01733d 61f8 sknz
ram:01733f ee2a01 _br $! 0x1746c
ram:017342 91 dec 
ram:017343 61f8 sknz
ram:017345 ee8300 _br $! 0x173cb
ram:017348 2c10 sub A,#0x10
ram:01734a 61f8 sknz
ram:01734c ee2701 _br $! 0x17476
ram:01734f 91 dec 
ram:017350 61f8 sknz
ram:017352 eeb800 _br $! 0x1740d
ram:017355 23 subw AX,BC
ram:017356 61f8 sknz
ram:017358 ee3001 _br $! 0x1748b
ram:01735b 91 dec 
ram:01735c 61f8 sknz
ram:01735e ee2f01 _br $! 0x17490
ram:017361 91 dec 
ram:017362 61f8 sknz
ram:017364 ee2e01 _br $! 0x17495
ram:017367 2c03 sub A,#0x3
ram:017369 61f8 sknz
ram:01736b ee0301 _br $! 0x17471
ram:01736e 2c08 sub A,#0x8
ram:017370 2c03 sub A,#0x3
ram:017372 dc69 bc $ 0x173dd
ram:017374 d1 cmp0 A
ram:017375 61f8 sknz
ram:017377 ee8100 _br $! 0x173fb
ram:01737a 91 dec 
ram:01737b 61f8 sknz
ram:01737d ee8700 _br $! 0x17407
ram:017380 91 dec 
ram:017381 dd72 bz $ 0x173f5
ram:017383 91 dec 
ram:017384 23 subw AX,BC
ram:017385 dc56 bc $ 0x173dd
ram:017387 d1 cmp0 A
ram:017388 dd77 bz $ 0x17401
ram:01738a 91 dec 
ram:01738b dd38 bz $ 0x173c5
ram:01738d 91 dec 
ram:01738e 23 subw AX,BC
ram:01738f dc46 bc $ 0x173d7
ram:017391 d1 cmp0 A
ram:017392 dd49 bz $ 0x173dd
ram:017394 91 dec 
ram:017395 23 subw AX,BC
ram:017396 dc39 bc $ 0x173d1
ram:017398 91 dec 
ram:017399 dd3c bz $ 0x173d7
ram:01739b 91 dec 
ram:01739c dd51 bz $ 0x173ef
ram:01739e 23 subw AX,BC
ram:01739f 23 subw AX,BC
ram:0173a0 dc2f bc $ 0x173d1
ram:0173a2 d1 cmp0 A
ram:0173a3 dd44 bz $ 0x173e9
ram:0173a5 91 dec 
ram:0173a6 2c03 sub A,#0x3
ram:0173a8 dc27 bc $ 0x173d1
ram:0173aa 91 dec 
ram:0173ab dd36 bz $ 0x173e3
ram:0173ad 91 dec 
ram:0173ae 61f8 sknz
ram:0173b0 eeb400 _br $! 0x17467
ram:0173b3 2c09 sub A,#0x9
ram:0173b5 2c06 sub A,#0x6
ram:0173b7 61d8 sknc
ram:0173b9 eede00 _br $! 0x1749a
ram:0173bc eeec00 br $! 0x174ab
ram:0173bf cc0102 mov [HL + 0x1],0x2
ram:0173c2 eee900 br $! 0x174ae
ram:0173c5 cc0101 mov [HL + 0x1],0x1
ram:0173c8 eee300 br $! 0x174ae
ram:0173cb cc0101 mov [HL + 0x1],0x1
ram:0173ce eedd00 br $! 0x174ae
ram:0173d1 cc0101 mov [HL + 0x1],0x1
ram:0173d4 eed700 br $! 0x174ae
ram:0173d7 cc0102 mov [HL + 0x1],0x2
ram:0173da eed100 br $! 0x174ae
ram:0173dd cc0104 mov [HL + 0x1],0x4
ram:0173e0 eecb00 br $! 0x174ae
ram:0173e3 cc0108 mov [HL + 0x1],0x8
ram:0173e6 eec500 br $! 0x174ae
ram:0173e9 cc0108 mov [HL + 0x1],0x8
ram:0173ec eebf00 br $! 0x174ae
ram:0173ef cc010a mov [HL + 0x1],0xa
ram:0173f2 eeb900 br $! 0x174ae
ram:0173f5 cc0101 mov [HL + 0x1],0x1
ram:0173f8 eeb300 br $! 0x174ae
ram:0173fb cc0104 mov [HL + 0x1],0x4
ram:0173fe eead00 br $! 0x174ae
ram:017401 cc0104 mov [HL + 0x1],0x4
ram:017404 eea700 br $! 0x174ae
ram:017407 cc0104 mov [HL + 0x1],0x4
ram:01740a eea100 br $! 0x174ae
ram:01740d ac0a movw AX,[HL + 0xa]
ram:01740f 14 movw DE,AX
ram:017410 89 mov A,[DE]
ram:017411 91 dec 
ram:017412 df36 bnz $ 0x1744a
ram:017414 af00e4 movw AX,!0xfe400
ram:017417 e7 onew BC
ram:017418 c3 push BC
ram:017419 12 movw BC,AX
ram:01741a ac0a movw AX,[HL + 0xa]
ram:01741c c1 push AX
ram:01741d 491200 mov A,!0xf0012[BC]
ram:017420 9dd4 mov 0xffdf4,A
ram:017422 791000 movw AX,!0xf0010[BC]
ram:017425 c1 push AX
ram:017426 8dd4 mov A,0xffdf4
ram:017428 9dd6 mov 0xffdf6,A
ram:01742a c0 pop AX
ram:01742b 14 movw DE,AX
ram:01742c e6 onew AX
ram:01742d f7 clrw BC
ram:01742e c1 push AX
ram:01742f 8dd6 mov A,0xffdf6
ram:017431 9efc mov CS,A
ram:017433 c0 pop AX
ram:017434 61ea call DE
ram:017436 1004 addw SP,0x4
ram:017438 d50ce2 cmp0 !0xfe20c
ram:01743b dd25 bz $ 0x17462
ram:01743d d90ce2 mov X,!0xfe20c
ram:017440 f1 clrb A
ram:017441 fc927e00 call !!0x7e92
ram:017445 f50ce2 clrb !0xfe20c
ram:017448 ef18 br $ 0x17462
ram:01744a d50ce2 cmp0 !0xfe20c
ram:01744d df13 bnz $ 0x17462
ram:01744f 30e803 movw AX,0x3e8
ram:017452 c1 push AX
ram:017453 30e172 movw AX,0x72e1
ram:017456 5201 mov ,0x1
ram:017458 f3 clrb B
ram:017459 fcea7d00 call !!0x7dea
ram:01745d c0 pop AX
ram:01745e 62 mov A,
ram:01745f 9f0ce2 mov !0xfe20c,A
ram:017462 cc0101 mov [HL + 0x1],0x1
ram:017465 ef47 br $ 0x174ae
ram:017467 cc0104 mov [HL + 0x1],0x4
ram:01746a ef42 br $ 0x174ae
ram:01746c cc010e mov [HL + 0x1],0xe
ram:01746f ef3d br $ 0x174ae
ram:017471 cc0102 mov [HL + 0x1],0x2
ram:017474 ef38 br $ 0x174ae
ram:017476 cc0101 mov [HL + 0x1],0x1
ram:017479 ef33 br $ 0x174ae
ram:01747b f6 clrw AX
ram:01747c 61490a cmpw AX,[HL + 0xa]
ram:01747f dd05 bz $ 0x17486
ram:017481 cc0104 mov [HL + 0x1],0x4
ram:017484 ef28 br $ 0x174ae
ram:017486 cc0100 mov [HL + 0x1],0x0
ram:017489 ef23 br $ 0x174ae
ram:01748b cc0101 mov [HL + 0x1],0x1
ram:01748e ef1e br $ 0x174ae
ram:017490 cc0102 mov [HL + 0x1],0x2
ram:017493 ef19 br $ 0x174ae
ram:017495 cc0100 mov [HL + 0x1],0x0
ram:017498 ef14 br $ 0x174ae
ram:01749a 8febe1 mov A,!0xfe1eb
ram:01749d 31050e bf A.0x0,$ 0x174ad
ram:0174a0 ac0a movw AX,[HL + 0xa]
ram:0174a2 14 movw DE,AX
ram:0174a3 89 mov A,[DE]
ram:0174a4 9c01 mov [HL + 0x1],A
ram:0174a6 61790a incw [HL + 0xa]
ram:0174a9 ef03 br $ 0x174ae
ram:0174ab cc0100 mov [HL + 0x1],0x0
ram:0174ae 8c01 mov A,[HL + 0x1]
ram:0174b0 81 inc 
ram:0174b1 dd17 bz $ 0x174ca
ram:0174b3 8c01 mov A,[HL + 0x1]
ram:0174b5 318e shrw AX,0x8
ram:0174b7 c1 push AX
ram:0174b8 ac0a movw AX,[HL + 0xa]
ram:0174ba c1 push AX
ram:0174bb 8c02 mov A,[HL + 0x2]
ram:0174bd 318e shrw AX,0x8
ram:0174bf c1 push AX
ram:0174c0 e6 onew AX
ram:0174c1 a1 incw AX
ram:0174c2 c1 push AX
ram:0174c3 e6 onew AX
ram:0174c4 fcb75401 call !!0x154b7
ram:0174c8 1008 addw SP,0x8
ram:0174ca e7 onew BC
ram:0174cb 1004 addw SP,0x4
ram:0174cd c6 pop HL
ram:0174ce d7 ret
