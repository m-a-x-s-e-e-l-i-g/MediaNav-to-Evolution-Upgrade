154b7 c7           push     HL
154b8 c1           push     AX
154b9 204a         subw     SP, #0x4a
154bb fbf8ff       movw     HL, SP
154be cc05aa       mov      [HL+0x5], #0xaa
154c1 17           movw     AX, HL
154c2 040600       addw     AX, #0x6
154c5 bc02         movw     [HL+0x2], AX
154c7 cc06aa       mov      [HL+0x6], #0xaa
154ca 8c52         mov      A, [HL+0x52]
154cc 5c0f         and      A, #0xf
154ce 70           mov      X, A
154cf 8c07         mov      A, [HL+0x7]
154d1 5cf0         and      A, #0xf0
154d3 6168         or       A, X
154d5 9c07         mov      [HL+0x7], A
154d7 8c4a         mov      A, [HL+0x4a]
154d9 3149         shl      A, #0x4
154db 70           mov      X, A
154dc 8c07         mov      A, [HL+0x7]
154de 5c0f         and      A, #0xf
154e0 6168         or       A, X
154e2 9c07         mov      [HL+0x7], A
154e4 8c54         mov      A, [HL+0x54]
154e6 9c08         mov      [HL+0x8], A
154e8 8c58         mov      A, [HL+0x58]
154ea 9c09         mov      [HL+0x9], A
154ec cc0100       mov      [HL+0x1], #0x0
154ef 8c01         mov      A, [HL+0x1]
154f1 4e09         cmp      A, [HL+0x9]
154f3 de1a         bnc      0x1550f
154f5 8c01         mov      A, [HL+0x1]
154f7 318e         shrw     AX, #0x8
154f9 610956       addw     AX, [HL+0x56]
154fc 14           movw     DE, AX
154fd 89           mov      A, [DE]
154fe 72           mov      C, A
154ff 8c01         mov      A, [HL+0x1]
15501 318e         shrw     AX, #0x8
15503 07           addw     AX, HL
15504 040a00       addw     AX, #0xa
15507 14           movw     DE, AX
15508 62           mov      A, C
15509 99           mov      [DE], A
1550a 615901       inc      [HL+0x1]
1550d efe0         br       0x154ef
1550f cc0101       mov      [HL+0x1], #0x1
15512 8c09         mov      A, [HL+0x9]
15514 0c04         add      A, #0x4
15516 4e01         cmp      A, [HL+0x1]
15518 61d312       bnh      0x1552d
1551b 8c01         mov      A, [HL+0x1]
1551d 318e         shrw     AX, #0x8
1551f 610902       addw     AX, [HL+0x2]
15522 14           movw     DE, AX
15523 89           mov      A, [DE]
15524 7e05         xor      A, [HL+0x5]
15526 9c05         mov      [HL+0x5], A
15528 615901       inc      [HL+0x1]
1552b efe5         br       0x15512
1552d 8c09         mov      A, [HL+0x9]
1552f 318e         shrw     AX, #0x8
15531 07           addw     AX, HL
15532 040a00       addw     AX, #0xa
15535 14           movw     DE, AX
15536 8c05         mov      A, [HL+0x5]
15538 99           mov      [DE], A
15539 8c58         mov      A, [HL+0x58]
1553b 0c05         add      A, #0x5
1553d 318e         shrw     AX, #0x8
1553f c1           push     AX
15540 17           movw     AX, HL
15541 040600       addw     AX, #0x6
15544 c1           push     AX
15545 f6           clrw     AX
15546 fce0e100     call     0xe1e0
1554a 1004         addw     SP, #0x4
1554c 104c         addw     SP, #0x4c
1554e c6           pop      HL
1554f d7           ret      
15c96 cfeae103     mov      0xfe1ea, #0x3
15c9a 30e803       movw     AX, #0x3e8
15c9d c1           push     AX
15c9e 30f055       movw     AX, #0x55f0
15ca1 5201         mov      C, #0x1
15ca3 f3           clrb     B
15ca4 fcea7d00     call     0x7dea
15ca8 c0           pop      AX
15ca9 62           mov      A, C
15caa 9f0ae2       mov      0xfe20a, A
15e92 c7           push     HL
15e93 16           movw     HL, AX
15e94 66           mov      A, L
15e95 91           dec      A
15e96 61e8         skz      
15e98 ee7f00       br       0x15f1a
15e9b 8febe1       mov      A, 0xfe1eb
15e9e 5cf0         and      A, #0xf0
15ea0 9febe1       mov      0xfe1eb, A
15ea3 30b772       movw     AX, #0x72b7
15ea6 bf16e7       movw     0xfe716, AX
15ea9 cf18e701     mov      0xfe718, #0x1
15ead f50ae2       clrb     0xfe20a
15eb0 f50be2       clrb     0xfe20b
15eb3 f50ce2       clrb     0xfe20c
15eb6 f5f8e6       clrb     0xfe6f8
15eb9 f5f9e6       clrb     0xfe6f9
15ebc eb0ee4       movw     DE, 0xfe40e
15ebf 8a02         mov      A, [DE+0x2]
15ec1 9efc         mov      CS, A
15ec3 a9           movw     AX, [DE]
15ec4 14           movw     DE, AX
15ec5 e6           onew     AX
15ec6 61ea         call     DE
15ec8 eb1ce4       movw     DE, 0xfe41c
15ecb 8a02         mov      A, [DE+0x2]
15ecd 9efc         mov      CS, A
15ecf a9           movw     AX, [DE]
15ed0 14           movw     DE, AX
15ed1 e6           onew     AX
15ed2 61ea         call     DE
15ed4 eb1ee4       movw     DE, 0xfe41e
15ed7 8a02         mov      A, [DE+0x2]
15ed9 9efc         mov      CS, A
15edb a9           movw     AX, [DE]
15edc 14           movw     DE, AX
15edd e6           onew     AX
15ede 61ea         call     DE
15ee0 e5eae1       oneb     0xfe1ea
15ee3 f5fae6       clrb     0xfe6fa
15ee6 f5fbe6       clrb     0xfe6fb
15ee9 f5fce6       clrb     0xfe6fc
15eec f5fde6       clrb     0xfe6fd
15eef f6           clrw     AX
15ef0 c1           push     AX
15ef1 308859       movw     AX, #0x5988
15ef4 5201         mov      C, #0x1
15ef6 f3           clrb     B
15ef7 fcea7d00     call     0x7dea
15efb c0           pop      AX
15efc 62           mov      A, C
15efd 9ff8e6       mov      0xfe6f8, A
15f00 30bc02       movw     AX, #0x2bc
15f03 c1           push     AX
15f04 30e65d       movw     AX, #0x5de6
15f07 5201         mov      C, #0x1
15f09 f3           clrb     B
15f0a fcea7d00     call     0x7dea
15f0e c0           pop      AX
15f0f 62           mov      A, C
15f10 9ff9e6       mov      0xfe6f9, A
15f13 fcc17f00     call     0x7fc1
15f17 eea600       br       0x15fc0
15f1a fca18000     call     0x80a1
15f1e 7108ebe1     clr1     0xfe1eb.0
15f22 7138ebe1     clr1     0xfe1eb.3
15f26 30b772       movw     AX, #0x72b7
15f29 bf16e7       movw     0xfe716, AX
15f2c cf18e701     mov      0xfe718, #0x1
15f30 d50ae2       cmp0     0xfe20a
15f33 dd0b         bz       0x15f40
15f35 d90ae2       mov      X, 0xfe20a
15f38 f1           clrb     A
15f39 fc927e00     call     0x7e92
15f3d f50ae2       clrb     0xfe20a
15f40 d50be2       cmp0     0xfe20b
15f43 dd0b         bz       0x15f50
15f45 d90be2       mov      X, 0xfe20b
15f48 f1           clrb     A
15f49 fc927e00     call     0x7e92
15f4d f50be2       clrb     0xfe20b
15f50 d5f7e6       cmp0     0xfe6f7
15f53 dd0b         bz       0x15f60
15f55 d9f7e6       mov      X, 0xfe6f7
15f58 f1           clrb     A
15f59 fc927e00     call     0x7e92
15f5d f5f7e6       clrb     0xfe6f7
15f60 d5f8e6       cmp0     0xfe6f8
15f63 dd0b         bz       0x15f70
15f65 d9f8e6       mov      X, 0xfe6f8
15f68 f1           clrb     A
15f69 fc927e00     call     0x7e92
15f6d f5f8e6       clrb     0xfe6f8
15f70 d5f9e6       cmp0     0xfe6f9
15f73 dd0b         bz       0x15f80
15f75 d9f9e6       mov      X, 0xfe6f9
15f78 f1           clrb     A
15f79 fc927e00     call     0x7e92
15f7d f5f9e6       clrb     0xfe6f9
15f80 cfeae106     mov      0xfe1ea, #0x6
15f84 30435d       movw     AX, #0x5d43
15f87 5201         mov      C, #0x1
15f89 f3           clrb     B
15f8a fc057e00     call     0x7e05
15f8e d2           cmp0     C
15f8f df2f         bnz      0x15fc0
15f91 af0ae4       movw     AX, 0xfe40a
15f94 f7           clrw     BC
15f95 c3           push     BC
15f96 14           movw     DE, AX
15f97 8a0e         mov      A, [DE+0xe]
15f99 9efc         mov      CS, A
15f9b aa0c         movw     AX, [DE+0xc]
15f9d 14           movw     DE, AX
15f9e 301700       movw     AX, #0x17
15fa1 61ea         call     DE
15fa3 c0           pop      AX
15fa4 af0ce4       movw     AX, 0xfe40c
15fa7 f7           clrw     BC
15fa8 c3           push     BC
15fa9 14           movw     DE, AX
15faa 8a0e         mov      A, [DE+0xe]
15fac 9efc         mov      CS, A
15fae aa0c         movw     AX, [DE+0xc]
15fb0 14           movw     DE, AX
15fb1 f6           clrw     AX
15fb2 61ea         call     DE
15fb4 c0           pop      AX
15fb5 fcbc5c01     call     0x15cbc
15fb9 fc7c5701     call     0x1577c
15fbd f5eae1       clrb     0xfe1ea
15fc0 c6           pop      HL
15fc1 d7           ret      
165bc 7100ebe1     set1     0xfe1eb.0
165c0 301673       movw     AX, #0x7316
165c3 bf16e7       movw     0xfe716, AX
165c6 cf18e701     mov      0xfe718, #0x1
165ca af02e4       movw     AX, 0xfe402
165cd 34f4e6       movw     DE, #0xe6f4
165d0 c5           push     DE
165d1 14           movw     DE, AX
165d2 8a1a         mov      A, [DE+0x1a]
165d4 9efc         mov      CS, A
165d6 aa18         movw     AX, [DE+0x18]
165d8 14           movw     DE, AX
165d9 f6           clrw     AX
165da 61ea         call     DE
165dc c0           pop      AX
165dd 303075       movw     AX, #0x7530
165e0 c1           push     AX
165e1 30555e       movw     AX, #0x5e55
165e4 5201         mov      C, #0x1
165e6 f3           clrb     B
165e7 fcea7d00     call     0x7dea
165eb c0           pop      AX
165ec 62           mov      A, C
165ed 9f0be2       mov      0xfe20b, A
165f0 af08e4       movw     AX, 0xfe408
165f3 f7           clrw     BC
165f4 c3           push     BC
165f5 14           movw     DE, AX
165f6 8a0e         mov      A, [DE+0xe]
165f8 9efc         mov      CS, A
165fa aa0c         movw     AX, [DE+0xc]
165fc 14           movw     DE, AX
165fd 300300       movw     AX, #0x3
16600 61ea         call     DE
16602 c0           pop      AX
16603 ee7003       br       0x16976
166f3 fcbc5c01     call     0x15cbc
166f7 7108ebe1     clr1     0xfe1eb.0
166fb 7138ebe1     clr1     0xfe1eb.3
166ff 30b772       movw     AX, #0x72b7
16702 bf16e7       movw     0xfe716, AX
16705 cf18e701     mov      0xfe718, #0x1
16709 f5eae1       clrb     0xfe1ea
1670c ee6702       br       0x16976
172b7 c7           push     HL
172b8 c1           push     AX
172b9 fbf8ff       movw     HL, SP
172bc 8b           mov      A, [HL]
172bd 2c02         sub      A, #0x2
172bf 2c02         sub      A, #0x2
172c1 de11         bnc      0x172d4
172c3 af00e4       movw     AX, 0xfe400
172c6 f7           clrw     BC
172c7 c3           push     BC
172c8 14           movw     DE, AX
172c9 8a0e         mov      A, [DE+0xe]
172cb 9efc         mov      CS, A
172cd aa0c         movw     AX, [DE+0xc]
172cf 14           movw     DE, AX
172d0 e6           onew     AX
172d1 61ea         call     DE
172d3 c0           pop      AX
172d4 40eae103     cmp      0xfe1ea, #0x3
172d8 dd03         bz       0x172dd
172da f7           clrw     BC
172db ef01         br       0x172de
172dd e7           onew     BC
172de c0           pop      AX
172df c6           pop      HL
172e0 d7           ret      
17316 c7           push     HL
17317 c1           push     AX
17318 c1           push     AX
17319 fbf8ff       movw     HL, SP
1731c cc01ff       mov      [HL+0x1], #0xff
1731f 40eae103     cmp      0xfe1ea, #0x3
17323 dd04         bz       0x17329
17325 f7           clrw     BC
17326 eea201       br       0x174cb
17329 8c02         mov      A, [HL+0x2]
1732b 320002       movw     BC, #0x200
1732e f0           clrb     X
1732f d1           cmp0     A
17330 61f8         sknz     
17332 ee8a00       br       0x173bf
17335 23           subw     AX, BC
17336 61f8         sknz     
17338 ee4001       br       0x1747b
1733b 2c1d         sub      A, #0x1d
1733d 61f8         sknz     
1733f ee2a01       br       0x1746c
17342 91           dec      A
17343 61f8         sknz     
17345 ee8300       br       0x173cb
17348 2c10         sub      A, #0x10
1734a 61f8         sknz     
1734c ee2701       br       0x17476
1734f 91           dec      A
17350 61f8         sknz     
17352 eeb800       br       0x1740d
17355 23           subw     AX, BC
17356 61f8         sknz     
17358 ee3001       br       0x1748b
1735b 91           dec      A
1735c 61f8         sknz     
1735e ee2f01       br       0x17490
17361 91           dec      A
17362 61f8         sknz     
17364 ee2e01       br       0x17495
17367 2c03         sub      A, #0x3
17369 61f8         sknz     
1736b ee0301       br       0x17471
1736e 2c08         sub      A, #0x8
17370 2c03         sub      A, #0x3
17372 dc69         bc       0x173dd
17374 d1           cmp0     A
17375 61f8         sknz     
17377 ee8100       br       0x173fb
1737a 91           dec      A
1737b 61f8         sknz     
1737d ee8700       br       0x17407
17380 91           dec      A
17381 dd72         bz       0x173f5
17383 91           dec      A
17384 23           subw     AX, BC
17385 dc56         bc       0x173dd
17387 d1           cmp0     A
17388 dd77         bz       0x17401
1738a 91           dec      A
1738b dd38         bz       0x173c5
1738d 91           dec      A
1738e 23           subw     AX, BC
1738f dc46         bc       0x173d7
17391 d1           cmp0     A
17392 dd49         bz       0x173dd
17394 91           dec      A
17395 23           subw     AX, BC
17396 dc39         bc       0x173d1
17398 91           dec      A
17399 dd3c         bz       0x173d7
1739b 91           dec      A
1739c dd51         bz       0x173ef
1739e 23           subw     AX, BC
1739f 23           subw     AX, BC
173a0 dc2f         bc       0x173d1
173a2 d1           cmp0     A
173a3 dd44         bz       0x173e9
173a5 91           dec      A
173a6 2c03         sub      A, #0x3
173a8 dc27         bc       0x173d1
173aa 91           dec      A
173ab dd36         bz       0x173e3
173ad 91           dec      A
173ae 61f8         sknz     
173b0 eeb400       br       0x17467
173b3 2c09         sub      A, #0x9
173b5 2c06         sub      A, #0x6
173b7 61d8         sknc     
173b9 eede00       br       0x1749a
173bc eeec00       br       0x174ab
173bf cc0102       mov      [HL+0x1], #0x2
173c2 eee900       br       0x174ae
173c5 cc0101       mov      [HL+0x1], #0x1
173c8 eee300       br       0x174ae
173cb cc0101       mov      [HL+0x1], #0x1
173ce eedd00       br       0x174ae
173d1 cc0101       mov      [HL+0x1], #0x1
173d4 eed700       br       0x174ae
173d7 cc0102       mov      [HL+0x1], #0x2
173da eed100       br       0x174ae
173dd cc0104       mov      [HL+0x1], #0x4
173e0 eecb00       br       0x174ae
173e3 cc0108       mov      [HL+0x1], #0x8
173e6 eec500       br       0x174ae
173e9 cc0108       mov      [HL+0x1], #0x8
173ec eebf00       br       0x174ae
173ef cc010a       mov      [HL+0x1], #0xa
173f2 eeb900       br       0x174ae
173f5 cc0101       mov      [HL+0x1], #0x1
173f8 eeb300       br       0x174ae
173fb cc0104       mov      [HL+0x1], #0x4
173fe eead00       br       0x174ae
17401 cc0104       mov      [HL+0x1], #0x4
17404 eea700       br       0x174ae
17407 cc0104       mov      [HL+0x1], #0x4
1740a eea100       br       0x174ae
1740d ac0a         movw     AX, [HL+0xa]
1740f 14           movw     DE, AX
17410 89           mov      A, [DE]
17411 91           dec      A
17412 df36         bnz      0x1744a
17414 af00e4       movw     AX, 0xfe400
17417 e7           onew     BC
17418 c3           push     BC
17419 12           movw     BC, AX
1741a ac0a         movw     AX, [HL+0xa]
1741c c1           push     AX
1741d 491200       mov      A, [BC+0x12]
17420 9dd4         mov      0xffed4, A
17422 791000       movw     AX, [BC+0x10]
17425 c1           push     AX
17426 8dd4         mov      A, 0xffed4
17428 9dd6         mov      0xffed6, A
1742a c0           pop      AX
1742b 14           movw     DE, AX
1742c e6           onew     AX
1742d f7           clrw     BC
1742e c1           push     AX
1742f 8dd6         mov      A, 0xffed6
17431 9efc         mov      CS, A
17433 c0           pop      AX
17434 61ea         call     DE
17436 1004         addw     SP, #0x4
17438 d50ce2       cmp0     0xfe20c
1743b dd25         bz       0x17462
1743d d90ce2       mov      X, 0xfe20c
17440 f1           clrb     A
17441 fc927e00     call     0x7e92
17445 f50ce2       clrb     0xfe20c
17448 ef18         br       0x17462
1744a d50ce2       cmp0     0xfe20c
1744d df13         bnz      0x17462
1744f 30e803       movw     AX, #0x3e8
17452 c1           push     AX
17453 30e172       movw     AX, #0x72e1
17456 5201         mov      C, #0x1
17458 f3           clrb     B
17459 fcea7d00     call     0x7dea
1745d c0           pop      AX
1745e 62           mov      A, C
1745f 9f0ce2       mov      0xfe20c, A
17462 cc0101       mov      [HL+0x1], #0x1
17465 ef47         br       0x174ae
17467 cc0104       mov      [HL+0x1], #0x4
1746a ef42         br       0x174ae
1746c cc010e       mov      [HL+0x1], #0xe
1746f ef3d         br       0x174ae
17471 cc0102       mov      [HL+0x1], #0x2
17474 ef38         br       0x174ae
17476 cc0101       mov      [HL+0x1], #0x1
17479 ef33         br       0x174ae
1747b f6           clrw     AX
1747c 61490a       cmpw     AX, [HL+0xa]
1747f dd05         bz       0x17486
17481 cc0104       mov      [HL+0x1], #0x4
17484 ef28         br       0x174ae
17486 cc0100       mov      [HL+0x1], #0x0
17489 ef23         br       0x174ae
1748b cc0101       mov      [HL+0x1], #0x1
1748e ef1e         br       0x174ae
17490 cc0102       mov      [HL+0x1], #0x2
17493 ef19         br       0x174ae
17495 cc0100       mov      [HL+0x1], #0x0
17498 ef14         br       0x174ae
1749a 8febe1       mov      A, 0xfe1eb
1749d 31050e       bf       A.0, 0x174ae
174a0 ac0a         movw     AX, [HL+0xa]
174a2 14           movw     DE, AX
174a3 89           mov      A, [DE]
174a4 9c01         mov      [HL+0x1], A
174a6 61790a       incw     [HL+0xa]
174a9 ef03         br       0x174ae
174ab cc0100       mov      [HL+0x1], #0x0
174ae 8c01         mov      A, [HL+0x1]
174b0 81           inc      A
174b1 dd17         bz       0x174ca
174b3 8c01         mov      A, [HL+0x1]
174b5 318e         shrw     AX, #0x8
174b7 c1           push     AX
174b8 ac0a         movw     AX, [HL+0xa]
174ba c1           push     AX
174bb 8c02         mov      A, [HL+0x2]
174bd 318e         shrw     AX, #0x8
174bf c1           push     AX
174c0 e6           onew     AX
174c1 a1           incw     AX
174c2 c1           push     AX
174c3 e6           onew     AX
174c4 fcb75401     call     0x154b7
174c8 1008         addw     SP, #0x8
174ca e7           onew     BC
174cb 1004         addw     SP, #0x4
174cd c6           pop      HL
174ce d7           ret      
