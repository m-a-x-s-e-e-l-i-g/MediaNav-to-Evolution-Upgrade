0191f c7           push     HL
01920 c1           push     AX
01921 200c         subw     SP, #0xc
01923 fbf8ff       movw     HL, SP
01926 8c0c         mov      A, [HL+0xc]
01928 9b           mov      [HL], A
01929 ac14         movw     AX, [HL+0x14]
0192b bc02         movw     [HL+0x2], AX
0192d ac18         movw     AX, [HL+0x18]
0192f bc06         movw     [HL+0x6], AX
01931 ac16         movw     AX, [HL+0x16]
01933 bc04         movw     [HL+0x4], AX
01935 8c1a         mov      A, [HL+0x1a]
01937 9c08         mov      [HL+0x8], A
01939 17           movw     AX, HL
0193a fcf51400     call     0x14f5
0193e 62           mov      A, C
0193f 9c0a         mov      [HL+0xa], A
01941 d1           cmp0     A
01942 df05         bnz      0x1949
01944 cc0b01       mov      [HL+0xb], #0x1
01947 ef34         br       0x197d
01949 8c0a         mov      A, [HL+0xa]
0194b 5c80         and      A, #0x80
0194d 4c80         cmp      A, #0x80
0194f dd17         bz       0x1968
01951 8c0a         mov      A, [HL+0xa]
01953 91           dec      A
01954 dd24         bz       0x197a
01956 2c04         sub      A, #0x4
01958 dd20         bz       0x197a
0195a 2c0b         sub      A, #0xb
0195c dd1c         bz       0x197a
0195e 2c0a         sub      A, #0xa
01960 2c03         sub      A, #0x3
01962 dc16         bc       0x197a
01964 2c62         sub      A, #0x62
01966 ef12         br       0x197a
01968 8c0a         mov      A, [HL+0xa]
0196a 5c7f         and      A, #0x7f
0196c 9c0a         mov      [HL+0xa], A
0196e 2c05         sub      A, #0x5
01970 dd08         bz       0x197a
01972 2c0b         sub      A, #0xb
01974 dd04         bz       0x197a
01976 2c0a         sub      A, #0xa
01978 2c03         sub      A, #0x3
0197a cc0b00       mov      [HL+0xb], #0x0
0197d 8c1a         mov      A, [HL+0x1a]
0197f 4c04         cmp      A, #0x4
01981 dd05         bz       0x1988
01983 8c1a         mov      A, [HL+0x1a]
01985 91           dec      A
01986 61f8         sknz     
01988 effe         br       0x1988
0198a 8c0b         mov      A, [HL+0xb]
0198c 318e         shrw     AX, #0x8
0198e 12           movw     BC, AX
0198f 100e         addw     SP, #0xe
01991 c6           pop      HL
01992 d7           ret      
01993 c7           push     HL
01994 aef8         movw     AX, SP
01996 240804       subw     AX, #0x408
01999 bef8         movw     SP, AX
0199b 16           movw     HL, AX
0199c 4103         mov      ES, #0x3
0199e 118f00f4     mov      A, ES:0xf400
019a2 c7           push     HL
019a3 c2           pop      BC
019a4 480704       mov      [BC+0x407], A
019a7 17           movw     AX, HL
019a8 12           movw     BC, AX
019a9 490704       mov      A, [BC+0x407]
019ac 81           inc      A
019ad dd0a         bz       0x19b9
019af 3000f4       movw     AX, #0xf400
019b2 320300       movw     BC, #0x3
019b5 fc5b1300     call     0x135b
019b9 fc731800     call     0x1873
154a0 c7           push     HL
154a1 c1           push     AX
154a2 fbf8ff       movw     HL, SP
154a5 cc01a6       mov      [HL+0x1], #0xa6
154a8 e6           onew     AX
154a9 c1           push     AX
154aa 17           movw     AX, HL
154ab a1           incw     AX
154ac c1           push     AX
154ad f6           clrw     AX
154ae fce0e100     call     0xe1e0
154b2 1004         addw     SP, #0x4
154b4 c0           pop      AX
154b5 c6           pop      HL
154b6 d7           ret      
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
1567a 8c81         mov      A, [HL+0x81]
1567c f0           clrb     X
1567d 317e         shrw     AX, #0x7
1567f 0400e4       addw     AX, #0xe400
15682 14           movw     DE, AX
15683 a9           movw     AX, [DE]
15684 12           movw     BC, AX
15685 ac86         movw     AX, [HL+0x86]
15687 c1           push     AX
15688 490e00       mov      A, [BC+0xe]
1568b 9efc         mov      CS, A
1568d 790c00       movw     AX, [BC+0xc]
15690 14           movw     DE, AX
15691 8c83         mov      A, [HL+0x83]
15693 318e         shrw     AX, #0x8
15695 61ea         call     DE
15697 c0           pop      AX
15698 62           mov      A, C
15699 2c02         sub      A, #0x2
1569b 61d8         sknc     
1569d fca05401     call     0x154a0
156a1 ee9f00       br       0x15743
156a4 8c81         mov      A, [HL+0x81]
156a6 f0           clrb     X
156a7 317e         shrw     AX, #0x7
156a9 0400e4       addw     AX, #0xe400
156ac 14           movw     DE, AX
156ad a9           movw     AX, [DE]
156ae 12           movw     BC, AX
156af ac86         movw     AX, [HL+0x86]
156b1 c1           push     AX
156b2 491a00       mov      A, [BC+0x1a]
156b5 9efc         mov      CS, A
156b7 791800       movw     AX, [BC+0x18]
156ba 14           movw     DE, AX
156bb 8c83         mov      A, [HL+0x83]
156bd 318e         shrw     AX, #0x8
156bf 61ea         call     DE
156c1 c0           pop      AX
156c2 fca05401     call     0x154a0
156c6 ef7b         br       0x15743
156c8 8c81         mov      A, [HL+0x81]
156ca f0           clrb     X
156cb 317e         shrw     AX, #0x7
156cd 0400e4       addw     AX, #0xe400
156d0 14           movw     DE, AX
156d1 a9           movw     AX, [DE]
156d2 12           movw     BC, AX
156d3 8c83         mov      A, [HL+0x83]
156d5 318e         shrw     AX, #0x8
156d7 c1           push     AX
156d8 17           movw     AX, HL
156d9 c1           push     AX
156da ac86         movw     AX, [HL+0x86]
156dc 14           movw     DE, AX
156dd a9           movw     AX, [DE]
156de bdd8         movw     0xffed8, AX
156e0 aa02         movw     AX, [DE+0x2]
156e2 bdda         movw     0xffeda, AX
156e4 491600       mov      A, [BC+0x16]
156e7 9efc         mov      CS, A
156e9 791400       movw     AX, [BC+0x14]
156ec 14           movw     DE, AX
156ed dada         movw     BC, 0xffeda
156ef add8         movw     AX, 0xffed8
156f1 61ea         call     DE
156f3 1004         addw     SP, #0x4
156f5 62           mov      A, C
156f6 9c80         mov      [HL+0x80], A
156f8 318e         shrw     AX, #0x8
156fa c1           push     AX
156fb 17           movw     AX, HL
156fc c1           push     AX
156fd 8c83         mov      A, [HL+0x83]
156ff 318e         shrw     AX, #0x8
15701 c1           push     AX
15702 500d         mov      X, #0xd
15704 c1           push     AX
15705 e6           onew     AX
15706 fcb75401     call     0x154b7
1570a 1008         addw     SP, #0x8
1570c ef35         br       0x15743
1570e 8c81         mov      A, [HL+0x81]
15710 f0           clrb     X
15711 317e         shrw     AX, #0x7
15713 0400e4       addw     AX, #0xe400
15716 14           movw     DE, AX
15717 a9           movw     AX, [DE]
15718 12           movw     BC, AX
15719 8c83         mov      A, [HL+0x83]
1571b 318e         shrw     AX, #0x8
1571d c1           push     AX
1571e ac86         movw     AX, [HL+0x86]
15720 040400       addw     AX, #0x4
15723 c1           push     AX
15724 ac86         movw     AX, [HL+0x86]
15726 14           movw     DE, AX
15727 a9           movw     AX, [DE]
15728 bdd8         movw     0xffed8, AX
1572a aa02         movw     AX, [DE+0x2]
1572c bdda         movw     0xffeda, AX
1572e 491200       mov      A, [BC+0x12]
15731 9efc         mov      CS, A
15733 791000       movw     AX, [BC+0x10]
15736 14           movw     DE, AX
15737 dada         movw     BC, 0xffeda
15739 add8         movw     AX, 0xffed8
1573b 61ea         call     DE
1573d 1004         addw     SP, #0x4
1573f fca05401     call     0x154a0
1611c c7           push     HL
1611d c1           push     AX
1611e 2042         subw     SP, #0x42
16120 fbf8ff       movw     HL, SP
16123 8c42         mov      A, [HL+0x42]
16125 2cfc         sub      A, #0xfc
16127 61f8         sknz     
16129 ee9905       br       0x166c5
1612c 91           dec      A
1612d 61f8         sknz     
1612f eec707       br       0x168f9
16132 91           dec      A
16133 61f8         sknz     
16135 eebb05       br       0x166f3
16138 91           dec      A
16139 61f8         sknz     
1613b ee6a07       br       0x168a8
1613e 91           dec      A
1613f 61f8         sknz     
16141 ee8303       br       0x164c7
16144 91           dec      A
16145 61f8         sknz     
16147 eebc04       br       0x16606
1614a 91           dec      A
1614b 61f8         sknz     
1614d ee0e05       br       0x1665e
16150 2c03         sub      A, #0x3
16152 61f8         sknz     
16154 ee2b05       br       0x16682
16157 91           dec      A
16158 61f8         sknz     
1615a ee5005       br       0x166ad
1615d 91           dec      A
1615e 61f8         sknz     
16160 ee6302       br       0x163c6
16163 91           dec      A
16164 61f8         sknz     
16166 ee8602       br       0x163ef
16169 2c02         sub      A, #0x2
1616b dd30         bz       0x1619d
1616d 91           dec      A
1616e 61f8         sknz     
16170 ee9b07       br       0x1690e
16173 91           dec      A
16174 61f8         sknz     
16176 eeea07       br       0x16963
16179 2c04         sub      A, #0x4
1617b 61f8         sknz     
1617d ee8f05       br       0x1670f
16180 2c08         sub      A, #0x8
16182 61f8         sknz     
16184 ee4006       br       0x167c7
16187 91           dec      A
16188 61f8         sknz     
1618a ee7806       br       0x16805
1618d 2c06         sub      A, #0x6
1618f 61f8         sknz     
16191 eeab06       br       0x1683f
16194 91           dec      A
16195 61f8         sknz     
16197 ee1507       br       0x168af
1619a eed907       br       0x16976
163c6 af00e4       movw     AX, 0xfe400
163c9 e7           onew     BC
163ca c3           push     BC
163cb 12           movw     BC, AX
163cc ac4a         movw     AX, [HL+0x4a]
163ce c1           push     AX
163cf 491200       mov      A, [BC+0x12]
163d2 9dd4         mov      0xffed4, A
163d4 791000       movw     AX, [BC+0x10]
163d7 c1           push     AX
163d8 8dd4         mov      A, 0xffed4
163da 9dd6         mov      0xffed6, A
163dc c0           pop      AX
163dd 14           movw     DE, AX
163de 304200       movw     AX, #0x42
163e1 f7           clrw     BC
163e2 c1           push     AX
163e3 8dd6         mov      A, 0xffed6
163e5 9efc         mov      CS, A
163e7 c0           pop      AX
163e8 61ea         call     DE
163ea 1004         addw     SP, #0x4
163ec ee8705       br       0x16976
164c7 7130ebe1     set1     0xfe1eb.3
164cb 8febe1       mov      A, 0xfe1eb
164ce 310516       bf       A.0, 0x164e7
164d1 af02e4       movw     AX, 0xfe402
164d4 34f4e6       movw     DE, #0xe6f4
164d7 c5           push     DE
164d8 14           movw     DE, AX
164d9 8a1a         mov      A, [DE+0x1a]
164db 9efc         mov      CS, A
164dd aa18         movw     AX, [DE+0x18]
164df 14           movw     DE, AX
164e0 f6           clrw     AX
164e1 61ea         call     DE
164e3 c0           pop      AX
164e4 ee1c01       br       0x16603
164e7 cc4102       mov      [HL+0x41], #0x2
164ea db00e4       movw     BC, 0xfe400
164ed 17           movw     AX, HL
164ee 044100       addw     AX, #0x41
164f1 c1           push     AX
164f2 491a00       mov      A, [BC+0x1a]
164f5 9efc         mov      CS, A
164f7 791800       movw     AX, [BC+0x18]
164fa 14           movw     DE, AX
164fb 300600       movw     AX, #0x6
164fe 61ea         call     DE
16500 c0           pop      AX
16501 af12e4       movw     AX, 0xfe412
16504 e7           onew     BC
16505 c3           push     BC
16506 12           movw     BC, AX
16507 17           movw     AX, HL
16508 044100       addw     AX, #0x41
1650b c1           push     AX
1650c 491200       mov      A, [BC+0x12]
1650f 9dd4         mov      0xffed4, A
16511 791000       movw     AX, [BC+0x10]
16514 c1           push     AX
16515 8dd4         mov      A, 0xffed4
16517 9dd6         mov      0xffed6, A
16519 c0           pop      AX
1651a 14           movw     DE, AX
1651b 304400       movw     AX, #0x44
1651e f7           clrw     BC
1651f c1           push     AX
16520 8dd6         mov      A, 0xffed6
16522 9efc         mov      CS, A
16524 c0           pop      AX
16525 61ea         call     DE
16527 1004         addw     SP, #0x4
16529 c7           push     HL
1652a 17           movw     AX, HL
1652b 044000       addw     AX, #0x40
1652e 16           movw     HL, AX
1652f f7           clrw     BC
16530 49a84b       mov      A, [BC+0x4ba8]
16533 9b           mov      [HL], A
16534 a3           incw     BC
16535 a7           incw     HL
16536 5102         mov      A, #0x2
16538 614a         cmp      A, C
1653a dff4         bnz      0x16530
1653c c6           pop      HL
1653d d5fae6       cmp0     0xfe6fa
16540 df7a         bnz      0x165bc
16542 8ff4e6       mov      A, 0xfe6f4
16545 311348       bt       A.1, 0x16590
16548 7120ebe1     set1     0xfe1eb.2
1654c af1ae4       movw     AX, 0xfe41a
1654f e7           onew     BC
16550 a3           incw     BC
16551 c3           push     BC
16552 12           movw     BC, AX
16553 17           movw     AX, HL
16554 044000       addw     AX, #0x40
16557 c1           push     AX
16558 491200       mov      A, [BC+0x12]
1655b 9dd4         mov      0xffed4, A
1655d 791000       movw     AX, [BC+0x10]
16560 c1           push     AX
16561 8dd4         mov      A, 0xffed4
16563 9dd6         mov      0xffed6, A
16565 c0           pop      AX
16566 14           movw     DE, AX
16567 302100       movw     AX, #0x21
1656a f7           clrw     BC
1656b c1           push     AX
1656c 8dd6         mov      A, 0xffed6
1656e 9efc         mov      CS, A
16570 c0           pop      AX
16571 61ea         call     DE
16573 1004         addw     SP, #0x4
16575 d5f7e6       cmp0     0xfe6f7
16578 df13         bnz      0x1658d
1657a 30e803       movw     AX, #0x3e8
1657d c1           push     AX
1657e 30e95f       movw     AX, #0x5fe9
16581 5201         mov      C, #0x1
16583 f3           clrb     B
16584 fcea7d00     call     0x7dea
16588 c0           pop      AX
16589 62           mov      A, C
1658a 9ff7e6       mov      0xfe6f7, A
1658d eee603       br       0x16976
16590 cc4101       mov      [HL+0x41], #0x1
16593 af1ae4       movw     AX, 0xfe41a
16596 e7           onew     BC
16597 a3           incw     BC
16598 c3           push     BC
16599 12           movw     BC, AX
1659a 17           movw     AX, HL
1659b 044000       addw     AX, #0x40
1659e c1           push     AX
1659f 491200       mov      A, [BC+0x12]
165a2 9dd4         mov      0xffed4, A
165a4 791000       movw     AX, [BC+0x10]
165a7 c1           push     AX
165a8 8dd4         mov      A, 0xffed4
165aa 9dd6         mov      0xffed6, A
165ac c0           pop      AX
165ad 14           movw     DE, AX
165ae 302100       movw     AX, #0x21
165b1 f7           clrw     BC
165b2 c1           push     AX
165b3 8dd6         mov      A, 0xffed6
165b5 9efc         mov      CS, A
165b7 c0           pop      AX
165b8 61ea         call     DE
165ba 1004         addw     SP, #0x4
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
168f9 af00e4       movw     AX, 0xfe400
168fc f7           clrw     BC
168fd c3           push     BC
168fe 14           movw     DE, AX
168ff 8a1a         mov      A, [DE+0x1a]
16901 9efc         mov      CS, A
16903 aa18         movw     AX, [DE+0x18]
16905 14           movw     DE, AX
16906 300600       movw     AX, #0x6
16909 61ea         call     DE
1690b c0           pop      AX
1690c ef68         br       0x16976
16976 e7           onew     BC
16977 1044         addw     SP, #0x44
16979 c6           pop      HL
1697a d7           ret      
1697b c7           push     HL
1697c c3           push     BC
18bd0 c7           push     HL
18bd1 c1           push     AX
18bd2 c1           push     AX
18bd3 fbf8ff       movw     HL, SP
18bd6 31540506     bf       0xfff05.5, 0x18be0
18bda f535e8       clrb     0xfe835
18bdd f7           clrw     BC
18bde ef35         br       0x18c15
18be0 4103         mov      ES, #0x3
18be2 118f00f4     mov      A, ES:0xf400
18be6 9c01         mov      [HL+0x1], A
18be8 81           inc      A
18be9 df15         bnz      0x18c00
18beb ac02         movw     AX, [HL+0x2]
18bed 14           movw     DE, AX
18bee aa04         movw     AX, [DE+0x4]
18bf0 a1           incw     AX
18bf1 ba04         movw     [DE+0x4], AX
18bf3 ac02         movw     AX, [HL+0x2]
18bf5 14           movw     DE, AX
18bf6 aa04         movw     AX, [DE+0x4]
18bf8 440600       cmpw     AX, #0x6
18bfb de03         bnc      0x18c00
18bfd e7           onew     BC
18bfe ef15         br       0x18c15
18c00 af00e4       movw     AX, 0xfe400
18c03 f7           clrw     BC
18c04 c3           push     BC
18c05 14           movw     DE, AX
18c06 8a0e         mov      A, [DE+0xe]
18c08 9efc         mov      CS, A
18c0a aa0c         movw     AX, [DE+0xc]
18c0c 14           movw     DE, AX
18c0d e6           onew     AX
18c0e 61ea         call     DE
18c10 c0           pop      AX
18c11 f535e8       clrb     0xfe835
18c14 f7           clrw     BC
18c15 1004         addw     SP, #0x4
18c17 c6           pop      HL
18c18 d7           ret      
190c9 c7           push     HL
190ca c1           push     AX
190cb c1           push     AX
190cc fbf8ff       movw     HL, SP
190cf 306400       movw     AX, #0x64
190d2 bb           movw     [HL], AX
190d3 8c02         mov      A, [HL+0x2]
190d5 91           dec      A
190d6 61e8         skz      
190d8 eea900       br       0x19184
190db e52ce8       oneb     0xfe82c
190de f52de8       clrb     0xfe82d
190e1 f532e8       clrb     0xfe832
190e4 71182fe8     clr1     0xfe82f.1
190e8 71282fe8     clr1     0xfe82f.2
190ec 342fe8       movw     DE, #0xe82f
190ef 89           mov      A, [DE]
190f0 5ccf         and      A, #0xcf
190f2 99           mov      [DE], A
190f3 a5           incw     DE
190f4 89           mov      A, [DE]
190f5 5ccf         and      A, #0xcf
190f7 99           mov      [DE], A
190f8 716030e8     set1     0xfe830.6
190fc e52ee8       oneb     0xfe82e
190ff 717830e8     clr1     0xfe830.7
19103 31020303     bt       0xfff03.0, 0x1910a
19107 e1           oneb     A
19108 ef01         br       0x1910b
1910a f1           clrb     A
1910b d1           cmp0     A
1910c df1d         bnz      0x1912b
1910e 71002fe8     set1     0xfe82f.0
19112 71302fe8     set1     0xfe82f.3
19116 30409c       movw     AX, #0x9c40
19119 c1           push     AX
1911a 309a8f       movw     AX, #0x8f9a
1911d 5201         mov      C, #0x1
1911f f3           clrb     B
19120 fcea7d00     call     0x7dea
19124 c0           pop      AX
19125 62           mov      A, C
19126 9f33e8       mov      0xfe833, A
19129 ef08         br       0x19133
1912b 71082fe8     clr1     0xfe82f.0
1912f 71382fe8     clr1     0xfe82f.3
19133 716b24       clr1     0xfff24.6
19136 715b24       clr1     0xfff24.5
19139 716204       set1     0xfff04.6
1913c 715304       clr1     0xfff04.5
1913f 303075       movw     AX, #0x7530
19142 c1           push     AX
19143 30d08b       movw     AX, #0x8bd0
19146 5201         mov      C, #0x1
19148 f3           clrb     B
19149 fcea7d00     call     0x7dea
1914d c0           pop      AX
1914e 62           mov      A, C
1914f 9f35e8       mov      0xfe835, A
19152 4103         mov      ES, #0x3
19154 114000f4ff   cmp      ES:0xf400, #0xff
19159 61f8         sknz     
1915b 717030e8     set1     0xfe830.7
1915f eb12e4       movw     DE, 0xfe412
19162 8a02         mov      A, [DE+0x2]
19164 9efc         mov      CS, A
19166 a9           movw     AX, [DE]
19167 14           movw     DE, AX
19168 e6           onew     AX
19169 61ea         call     DE
1916b fc3e7c00     call     0x7c3e
1916f d2           cmp0     C
19170 dd05         bz       0x19177
19172 ab           movw     AX, [HL]
19173 049001       addw     AX, #0x190
19176 bb           movw     [HL], AX
19177 ab           movw     AX, [HL]
19178 c1           push     AX
19179 30ca8f       movw     AX, #0x8fca
1917c 5201         mov      C, #0x1
1917e f3           clrb     B
1917f fcea7d00     call     0x7dea
19183 c0           pop      AX
19184 1004         addw     SP, #0x4
19186 c6           pop      HL
19187 d7           ret      
19269 c7           push     HL
1926a c3           push     BC
1926b c1           push     AX
1926c c1           push     AX
1926d fbf8ff       movw     HL, SP
19270 ac04         movw     AX, [HL+0x4]
19272 12           movw     BC, AX
19273 ac02         movw     AX, [HL+0x2]
19275 340100       movw     DE, #0x1
19278 33           xchw     AX, BC
19279 440000       cmpw     AX, #0x0
1927c df35         bnz      0x192b3
1927e 13           movw     AX, BC
1927f 25           subw     AX, DE
19280 61f8         sknz     
19282 ee8e00       br       0x19313
19285 241f00       subw     AX, #0x1f
19288 dd2c         bz       0x192b6
1928a 25           subw     AX, DE
1928b dd5f         bz       0x192ec
1928d 240f00       subw     AX, #0xf
19290 dd6f         bz       0x19301
19292 25           subw     AX, DE
19293 61f8         sknz     
19295 ee8d00       br       0x19325
19298 241100       subw     AX, #0x11
1929b 61f8         sknz     
1929d eeab00       br       0x1934b
192a0 240300       subw     AX, #0x3
192a3 61f8         sknz     
192a5 ee8f00       br       0x19337
192a8 240b00       subw     AX, #0xb
192ab 61f8         sknz     
192ad eec800       br       0x19378
192b0 eed200       br       0x19385
192b3 eecf00       br       0x19385
192b6 ac0c         movw     AX, [HL+0xc]
192b8 14           movw     DE, AX
192b9 89           mov      A, [DE]
192ba d1           cmp0     A
192bb df05         bnz      0x192c2
192bd 716301       clr1     0xfff01.6
192c0 ef03         br       0x192c5
192c2 716201       set1     0xfff01.6
192c5 ac0c         movw     AX, [HL+0xc]
192c7 14           movw     DE, AX
192c8 89           mov      A, [DE]
192c9 9f36e8       mov      0xfe836, A
192cc 8a01         mov      A, [DE+0x1]
192ce d1           cmp0     A
192cf df05         bnz      0x192d6
192d1 710305       clr1     0xfff05.0
192d4 ef03         br       0x192d9
192d6 710205       set1     0xfff05.0
192d9 ac0c         movw     AX, [HL+0xc]
192db 14           movw     DE, AX
192dc 8a02         mov      A, [DE+0x2]
192de d1           cmp0     A
192df df05         bnz      0x192e6
192e1 711303       clr1     0xfff03.1
192e4 ef03         br       0x192e9
192e6 711203       set1     0xfff03.1
192e9 ee9900       br       0x19385
192ec 716201       set1     0xfff01.6
192ef ac0c         movw     AX, [HL+0xc]
192f1 14           movw     DE, AX
192f2 89           mov      A, [DE]
192f3 d1           cmp0     A
192f4 df05         bnz      0x192fb
192f6 710305       clr1     0xfff05.0
192f9 ef03         br       0x192fe
192fb 710205       set1     0xfff05.0
192fe ee8400       br       0x19385
19301 ac0c         movw     AX, [HL+0xc]
19303 14           movw     DE, AX
19304 89           mov      A, [DE]
19305 91           dec      A
19306 df03         bnz      0x1930b
19308 e1           oneb     A
19309 ef01         br       0x1930c
1930b f1           clrb     A
1930c 61fb         rorc     A, #0x1
1930e 711100       mov1     0xfff00.1, CY
19311 ef72         br       0x19385
19313 ac0c         movw     AX, [HL+0xc]
19315 14           movw     DE, AX
19316 89           mov      A, [DE]
19317 91           dec      A
19318 df03         bnz      0x1931d
1931a e1           oneb     A
1931b ef01         br       0x1931e
1931d f1           clrb     A
1931e 61fb         rorc     A, #0x1
19320 713100       mov1     0xfff00.3, CY
19323 ef60         br       0x19385
19325 ac0c         movw     AX, [HL+0xc]
19327 14           movw     DE, AX
19328 89           mov      A, [DE]
19329 91           dec      A
1932a df03         bnz      0x1932f
1932c e1           oneb     A
1932d ef01         br       0x19330
1932f f1           clrb     A
19330 61fb         rorc     A, #0x1
19332 716106       mov1     0xfff06.6, CY
19335 ef4e         br       0x19385
19337 ac0c         movw     AX, [HL+0xc]
19339 14           movw     DE, AX
1933a 89           mov      A, [DE]
1933b 3149         shl      A, #0x4
1933d 5c30         and      A, #0x30
1933f 3430e8       movw     DE, #0xe830
19342 70           mov      X, A
19343 89           mov      A, [DE]
19344 5ccf         and      A, #0xcf
19346 6168         or       A, X
19348 99           mov      [DE], A
19349 ef3a         br       0x19385
1934b ac0c         movw     AX, [HL+0xc]
1934d 14           movw     DE, AX
1934e 89           mov      A, [DE]
1934f 3430e8       movw     DE, #0xe830
19352 718c         mov1     CY, A.0
19354 89           mov      A, [DE]
19355 71f9         mov1     A.7, CY
19357 99           mov      [DE], A
19358 317517       bf       A.7, 0x19372
1935b cc01fd       mov      [HL+0x1], #0xfd
1935e db1ee4       movw     BC, 0xfe41e
19361 17           movw     AX, HL
19362 a1           incw     AX
19363 c1           push     AX
19364 490e00       mov      A, [BC+0xe]
19367 9efc         mov      CS, A
19369 790c00       movw     AX, [BC+0xc]
1936c 14           movw     DE, AX
1936d e6           onew     AX
1936e a1           incw     AX
1936f 61ea         call     DE
19371 c0           pop      AX
19372 fc0e8e01     call     0x18e0e
19376 ef0d         br       0x19385
19378 ac0c         movw     AX, [HL+0xc]
1937a 14           movw     DE, AX
1937b 89           mov      A, [DE]
1937c 3430e8       movw     DE, #0xe830
1937f 718c         mov1     CY, A.0
19381 89           mov      A, [DE]
19382 71e9         mov1     A.6, CY
19384 99           mov      [DE], A
19385 e7           onew     BC
19386 1006         addw     SP, #0x6
19388 c6           pop      HL
19389 d7           ret      
1938a c7           push     HL
1938b c3           push     BC
1938c c1           push     AX
1938d 2004         subw     SP, #0x4
1938f fbf8ff       movw     HL, SP
19392 cc0300       mov      [HL+0x3], #0x0
19395 ac06         movw     AX, [HL+0x6]
19397 12           movw     BC, AX
19398 ac04         movw     AX, [HL+0x4]
1939a 340100       movw     DE, #0x1
1939d 33           xchw     AX, BC
1939e 440000       cmpw     AX, #0x0
193a1 df2b         bnz      0x193ce
193a3 13           movw     AX, BC
193a4 242100       subw     AX, #0x21
193a7 dd28         bz       0x193d1
193a9 241f00       subw     AX, #0x1f
193ac dd36         bz       0x193e4
193ae 25           subw     AX, DE
193af dd44         bz       0x193f5
193b1 25           subw     AX, DE
193b2 dd52         bz       0x19406
193b4 25           subw     AX, DE
193b5 dd5e         bz       0x19415
193b7 25           subw     AX, DE
193b8 dd6c         bz       0x19426
193ba 25           subw     AX, DE
193bb dd7b         bz       0x19438
193bd 25           subw     AX, DE
193be 61f8         sknz     
193c0 ee8900       br       0x1944c
193c3 240a00       subw     AX, #0xa
193c6 61f8         sknz     
193c8 ee8e00       br       0x19459
193cb ee9d00       br       0x1946b
193ce ee9a00       br       0x1946b
193d1 ac0e         movw     AX, [HL+0xe]
193d3 bb           movw     [HL], AX
193d4 31020503     bt       0xfff05.0, 0x193db
193d8 f1           clrb     A
193d9 ef01         br       0x193dc
193db e1           oneb     A
193dc 72           mov      C, A
193dd ab           movw     AX, [HL]
193de 14           movw     DE, AX
193df 62           mov      A, C
193e0 99           mov      [DE], A
193e1 ee8700       br       0x1946b
193e4 ac0e         movw     AX, [HL+0xe]
193e6 bb           movw     [HL], AX
193e7 8f2fe8       mov      A, 0xfe82f
193ea 3169         shl      A, #0x6
193ec 317a         shr      A, #0x7
193ee 72           mov      C, A
193ef ab           movw     AX, [HL]
193f0 14           movw     DE, AX
193f1 62           mov      A, C
193f2 99           mov      [DE], A
193f3 ef76         br       0x1946b
193f5 ac0e         movw     AX, [HL+0xe]
193f7 bb           movw     [HL], AX
193f8 8f2fe8       mov      A, 0xfe82f
193fb 3159         shl      A, #0x5
193fd 317a         shr      A, #0x7
193ff 72           mov      C, A
19400 ab           movw     AX, [HL]
19401 14           movw     DE, AX
19402 62           mov      A, C
19403 99           mov      [DE], A
19404 ef65         br       0x1946b
19406 ac0e         movw     AX, [HL+0xe]
19408 bb           movw     [HL], AX
19409 8f30e8       mov      A, 0xfe830
1940c 317a         shr      A, #0x7
1940e 72           mov      C, A
1940f ab           movw     AX, [HL]
19410 14           movw     DE, AX
19411 62           mov      A, C
19412 99           mov      [DE], A
19413 ef56         br       0x1946b
19415 ac0e         movw     AX, [HL+0xe]
19417 bb           movw     [HL], AX
19418 8f2fe8       mov      A, 0xfe82f
1941b 3149         shl      A, #0x4
1941d 317a         shr      A, #0x7
1941f 72           mov      C, A
19420 ab           movw     AX, [HL]
19421 14           movw     DE, AX
19422 62           mov      A, C
19423 99           mov      [DE], A
19424 ef45         br       0x1946b
19426 ac0e         movw     AX, [HL+0xe]
19428 bb           movw     [HL], AX
19429 8f2fe8       mov      A, 0xfe82f
1942c 5c01         and      A, #0x1
1942e 72           mov      C, A
1942f ab           movw     AX, [HL]
19430 14           movw     DE, AX
19431 62           mov      A, C
19432 99           mov      [DE], A
19433 cc0301       mov      [HL+0x3], #0x1
19436 ef33         br       0x1946b
19438 ac0e         movw     AX, [HL+0xe]
1943a bb           movw     [HL], AX
1943b 8f30e8       mov      A, 0xfe830
1943e 3129         shl      A, #0x2
19440 316a         shr      A, #0x6
19442 72           mov      C, A
19443 ab           movw     AX, [HL]
19444 14           movw     DE, AX
19445 62           mov      A, C
19446 99           mov      [DE], A
19447 cc0301       mov      [HL+0x3], #0x1
1944a ef1f         br       0x1946b
1944c ac0e         movw     AX, [HL+0xe]
1944e bb           movw     [HL], AX
1944f 14           movw     DE, AX
19450 8f36e8       mov      A, 0xfe836
19453 99           mov      [DE], A
19454 cc0301       mov      [HL+0x3], #0x1
19457 ef12         br       0x1946b
19459 ac0e         movw     AX, [HL+0xe]
1945b bb           movw     [HL], AX
1945c 8f30e8       mov      A, 0xfe830
1945f 3119         shl      A, #0x1
19461 317a         shr      A, #0x7
19463 72           mov      C, A
19464 ab           movw     AX, [HL]
19465 14           movw     DE, AX
19466 62           mov      A, C
19467 99           mov      [DE], A
19468 cc0301       mov      [HL+0x3], #0x1
1946b 8c03         mov      A, [HL+0x3]
1946d 318e         shrw     AX, #0x8
1946f 12           movw     BC, AX
19470 1008         addw     SP, #0x8
19472 c6           pop      HL
19473 d7           ret      
19474 c7           push     HL
19475 c1           push     AX
19476 2006         subw     SP, #0x6
19478 fbf8ff       movw     HL, SP
1947b 8c06         mov      A, [HL+0x6]
1947d d1           cmp0     A
1947e dd27         bz       0x194a7
19480 91           dec      A
19481 61f8         sknz     
19483 eed400       br       0x1955a
19486 91           dec      A
19487 61f8         sknz     
19489 ee3201       br       0x195be
1948c 91           dec      A
1948d 61f8         sknz     
1948f eeb501       br       0x19647
19492 91           dec      A
19493 61f8         sknz     
19495 eedf00       br       0x19577
19498 91           dec      A
19499 61f8         sknz     
1949b eed600       br       0x19574
1949e 91           dec      A
1949f 61f8         sknz     
194a1 eec001       br       0x19664
194a4 eefd01       br       0x196a4
19664 d935e8       mov      X, 0xfe835
19667 f1           clrb     A
19668 fc927e00     call     0x7e92
1966c f535e8       clrb     0xfe835
1966f 4103         mov      ES, #0x3
19671 11d500f4     cmp0     ES:0xf400
19675 dd2d         bz       0x196a4
19677 cc0100       mov      [HL+0x1], #0x0
1967a 717830e8     clr1     0xfe830.7
1967e af1ee4       movw     AX, 0xfe41e
19681 e7           onew     BC
19682 c3           push     BC
19683 12           movw     BC, AX
19684 17           movw     AX, HL
19685 a1           incw     AX
19686 c1           push     AX
19687 491200       mov      A, [BC+0x12]
1968a 9dd4         mov      0xffed4, A
1968c 791000       movw     AX, [BC+0x10]
1968f c1           push     AX
19690 8dd4         mov      A, 0xffed4
19692 9dd6         mov      0xffed6, A
19694 c0           pop      AX
19695 14           movw     DE, AX
19696 30fe00       movw     AX, #0xfe
19699 f7           clrw     BC
1969a c1           push     AX
1969b 8dd6         mov      A, 0xffed6
1969d 9efc         mov      CS, A
1969f c0           pop      AX
196a0 61ea         call     DE
196a2 1004         addw     SP, #0x4
196a4 e7           onew     BC
196a5 1008         addw     SP, #0x8
196a7 c6           pop      HL
196a8 d7           ret      
1e7ca c7           push     HL
1e7cb c1           push     AX
1e7cc 200c         subw     SP, #0xc
1e7ce fbf8ff       movw     HL, SP
1e7d1 cc0b01       mov      [HL+0xb], #0x1
1e7d4 8c0c         mov      A, [HL+0xc]
1e7d6 d1           cmp0     A
1e7d7 dd0b         bz       0x1e7e4
1e7d9 91           dec      A
1e7da dd2e         bz       0x1e80a
1e7dc 91           dec      A
1e7dd dd61         bz       0x1e840
1e7df 91           dec      A
1e7e0 dd78         bz       0x1e85a
1e7e2 ef7a         br       0x1e85e
1e7e4 ac14         movw     AX, [HL+0x14]
1e7e6 a1           incw     AX
1e7e7 ac14         movw     AX, [HL+0x14]
1e7e9 14           movw     DE, AX
1e7ea 89           mov      A, [DE]
1e7eb 318e         shrw     AX, #0x8
1e7ed bc08         movw     [HL+0x8], AX
1e7ef f6           clrw     AX
1e7f0 c1           push     AX
1e7f1 ac08         movw     AX, [HL+0x8]
1e7f3 f7           clrw     BC
1e7f4 c3           push     BC
1e7f5 c1           push     AX
1e7f6 ac14         movw     AX, [HL+0x14]
1e7f8 c1           push     AX
1e7f9 30e100       movw     AX, #0xe1
1e7fc fc1f1900     call     0x191f
1e800 1008         addw     SP, #0x8
1e802 92           dec      C
1e803 dd59         bz       0x1e85e
1e805 cc0b00       mov      [HL+0xb], #0x0
1e808 ef54         br       0x1e85e
1e80a 340084       movw     DE, #0x8400
1e80d 15           movw     AX, DE
1e80e bc06         movw     [HL+0x6], AX
1e810 cc0803       mov      [HL+0x8], #0x3
1e813 ac14         movw     AX, [HL+0x14]
1e815 bc04         movw     [HL+0x4], AX
1e817 a1           incw     AX
1e818 ac14         movw     AX, [HL+0x14]
1e81a 14           movw     DE, AX
1e81b 89           mov      A, [DE]
1e81c 318e         shrw     AX, #0x8
1e81e bc02         movw     [HL+0x2], AX
1e820 f6           clrw     AX
1e821 bb           movw     [HL], AX
1e822 ab           movw     AX, [HL]
1e823 614902       cmpw     AX, [HL+0x2]
1e826 de36         bnc      0x1e85e
1e828 ab           movw     AX, [HL]
1e829 610906       addw     AX, [HL+0x6]
1e82c 14           movw     DE, AX
1e82d 8c08         mov      A, [HL+0x8]
1e82f 9efd         mov      ES, A
1e831 1189         mov      A, ES:[DE]
1e833 72           mov      C, A
1e834 ab           movw     AX, [HL]
1e835 610904       addw     AX, [HL+0x4]
1e838 14           movw     DE, AX
1e839 62           mov      A, C
1e83a 99           mov      [DE], A
1e83b 617900       incw     [HL]
1e83e efe2         br       0x1e822
1e840 ac14         movw     AX, [HL+0x14]
1e842 14           movw     DE, AX
1e843 89           mov      A, [DE]
1e844 9dd8         mov      0xffed8, A
1e846 f4d9         clrb     0xffed9
1e848 f6           clrw     AX
1e849 bdda         movw     0xffeda, AX
1e84b 510a         mov      A, #0xa
1e84d fd7106       call     0x671
1e850 dada         movw     BC, 0xffeda
1e852 add8         movw     AX, 0xffed8
1e854 fc5b1300     call     0x135b
1e858 ef04         br       0x1e85e
1e85a f6           clrw     AX
1e85b bfece2       movw     0xfe2ec, AX
1e85e 8c0b         mov      A, [HL+0xb]
1e860 318e         shrw     AX, #0x8
1e862 12           movw     BC, AX
1e863 100e         addw     SP, #0xe
1e865 c6           pop      HL
1e866 d7           ret      
1e867 c7           push     HL
1e868 c3           push     BC
1e869 c1           push     AX
1e86a 20fe         subw     SP, #0xfe
1e86c 2010         subw     SP, #0x10
1e86e fbf8ff       movw     HL, SP
1e871 e1           oneb     A
1e872 87           inc      H
1e873 9c0d         mov      [HL+0xd], A
1e875 97           dec      H
1e876 17           movw     AX, HL
1e877 041001       addw     AX, #0x110
1e87a 14           movw     DE, AX
1e87b a9           movw     AX, [DE]
1e87c 12           movw     BC, AX
1e87d 17           movw     AX, HL
1e87e 040e01       addw     AX, #0x10e
1e881 14           movw     DE, AX
1e882 a9           movw     AX, [DE]
1e883 340100       movw     DE, #0x1
1e886 33           xchw     AX, BC
1e887 440000       cmpw     AX, #0x0
1e88a 61e8         skz      
1e88c eef800       br       0x1e987
1e88f 13           movw     AX, BC
1e890 240000       subw     AX, #0x0
1e893 61f8         sknz     
1e895 eef200       br       0x1e98a
1e898 240800       subw     AX, #0x8
1e89b 61f8         sknz     
1e89d ee3d02       br       0x1eadd
1e8a0 240800       subw     AX, #0x8
1e8a3 61f8         sknz     
1e8a5 ee1102       br       0x1eab9
1e8a8 25           subw     AX, DE
1e8a9 61f8         sknz     
1e8ab ee5302       br       0x1eb01
1e8ae 25           subw     AX, DE
1e8af 61f8         sknz     
1e8b1 ee7102       br       0x1eb25
1e8b4 25           subw     AX, DE
1e8b5 61f8         sknz     
1e8b7 ee6b02       br       0x1eb25
1e8ba 25           subw     AX, DE
1e8bb 61f8         sknz     
1e8bd ee6502       br       0x1eb25
1e8c0 25           subw     AX, DE
1e8c1 61f8         sknz     
1e8c3 ee5f02       br       0x1eb25
1e8c6 25           subw     AX, DE
1e8c7 61f8         sknz     
1e8c9 ee5902       br       0x1eb25
1e8cc 25           subw     AX, DE
1e8cd 61f8         sknz     
1e8cf ee5302       br       0x1eb25
1e8d2 25           subw     AX, DE
1e8d3 61f8         sknz     
1e8d5 ee4d02       br       0x1eb25
1e8d8 240800       subw     AX, #0x8
1e8db 61f8         sknz     
1e8dd ee9b02       br       0x1eb7b
1e8e0 25           subw     AX, DE
1e8e1 61f8         sknz     
1e8e3 ee1904       br       0x1ecff
1e8e6 25           subw     AX, DE
1e8e7 61f8         sknz     
1e8e9 ee3704       br       0x1ed23
1e8ec 25           subw     AX, DE
1e8ed 61f8         sknz     
1e8ef ee3104       br       0x1ed23
1e8f2 25           subw     AX, DE
1e8f3 61f8         sknz     
1e8f5 ee2b04       br       0x1ed23
1e8f8 25           subw     AX, DE
1e8f9 61f8         sknz     
1e8fb ee2504       br       0x1ed23
1e8fe 25           subw     AX, DE
1e8ff 61f8         sknz     
1e901 ee1f04       br       0x1ed23
1e904 25           subw     AX, DE
1e905 61f8         sknz     
1e907 ee1904       br       0x1ed23
1e90a 25           subw     AX, DE
1e90b 61f8         sknz     
1e90d ee1304       br       0x1ed23
1e910 25           subw     AX, DE
1e911 61f8         sknz     
1e913 ee8902       br       0x1eb9f
1e916 25           subw     AX, DE
1e917 61f8         sknz     
1e919 eea702       br       0x1ebc3
1e91c 25           subw     AX, DE
1e91d 61f8         sknz     
1e91f eec502       br       0x1ebe7
1e922 25           subw     AX, DE
1e923 61f8         sknz     
1e925 eee302       br       0x1ec0b
1e928 25           subw     AX, DE
1e929 61f8         sknz     
1e92b ee0103       br       0x1ec2f
1e92e 25           subw     AX, DE
1e92f 61f8         sknz     
1e931 eefb02       br       0x1ec2f
1e934 25           subw     AX, DE
1e935 61f8         sknz     
1e937 eef502       br       0x1ec2f
1e93a 25           subw     AX, DE
1e93b 61f8         sknz     
1e93d eeef02       br       0x1ec2f
1e940 25           subw     AX, DE
1e941 61f8         sknz     
1e943 eee902       br       0x1ec2f
1e946 25           subw     AX, DE
1e947 61f8         sknz     
1e949 eee302       br       0x1ec2f
1e94c 25           subw     AX, DE
1e94d 61f8         sknz     
1e94f ee3303       br       0x1ec85
1e952 25           subw     AX, DE
1e953 61f8         sknz     
1e955 ee5103       br       0x1eca9
1e958 25           subw     AX, DE
1e959 61f8         sknz     
1e95b ee4b03       br       0x1eca9
1e95e 25           subw     AX, DE
1e95f 61f8         sknz     
1e961 ee4503       br       0x1eca9
1e964 25           subw     AX, DE
1e965 61f8         sknz     
1e967 ee3f03       br       0x1eca9
1e96a 25           subw     AX, DE
1e96b 61f8         sknz     
1e96d ee3903       br       0x1eca9
1e970 25           subw     AX, DE
1e971 61f8         sknz     
1e973 ee3303       br       0x1eca9
1e976 24c500       subw     AX, #0xc5
1e979 61f8         sknz     
1e97b eefa03       br       0x1ed78
1e97e 25           subw     AX, DE
1e97f 61f8         sknz     
1e981 ee1704       br       0x1ed9b
1e984 ee3704       br       0x1edbe
1e987 ee3404       br       0x1edbe
1ed78 f6           clrw     AX
1ed79 c1           push     AX
1ed7a 17           movw     AX, HL
1ed7b 12           movw     BC, AX
1ed7c 791a01       movw     AX, [BC+0x11a]
1ed7f f7           clrw     BC
1ed80 c3           push     BC
1ed81 c1           push     AX
1ed82 17           movw     AX, HL
1ed83 12           movw     BC, AX
1ed84 791801       movw     AX, [BC+0x118]
1ed87 c1           push     AX
1ed88 30fd00       movw     AX, #0xfd
1ed8b fc1f1900     call     0x191f
1ed8f 1008         addw     SP, #0x8
1ed91 92           dec      C
1ed92 dd2f         bz       0x1edc3
1ed94 f1           clrb     A
1ed95 87           inc      H
1ed96 9c0d         mov      [HL+0xd], A
1ed98 97           dec      H
1ed99 ef28         br       0x1edc3
1ed9b f6           clrw     AX
1ed9c c1           push     AX
1ed9d 17           movw     AX, HL
1ed9e 12           movw     BC, AX
1ed9f 791a01       movw     AX, [BC+0x11a]
1eda2 f7           clrw     BC
1eda3 c3           push     BC
1eda4 c1           push     AX
1eda5 17           movw     AX, HL
1eda6 12           movw     BC, AX
1eda7 791801       movw     AX, [BC+0x118]
1edaa c1           push     AX
1edab 30dc00       movw     AX, #0xdc
1edae fc1f1900     call     0x191f
1edb2 1008         addw     SP, #0x8
1edb4 92           dec      C
1edb5 dd0c         bz       0x1edc3
1edb7 f1           clrb     A
1edb8 87           inc      H
1edb9 9c0d         mov      [HL+0xd], A
1edbb 97           dec      H
1edbc ef05         br       0x1edc3
1edbe f1           clrb     A
1edbf 87           inc      H
1edc0 9c0d         mov      [HL+0xd], A
1edc2 97           dec      H
1edc3 87           inc      H
1edc4 8c0d         mov      A, [HL+0xd]
1edc6 97           dec      H
1edc7 318e         shrw     AX, #0x8
1edc9 12           movw     BC, AX
1edca 10fe         addw     SP, #0xfe
1edcc 1014         addw     SP, #0x14
1edce c6           pop      HL
1edcf d7           ret      
