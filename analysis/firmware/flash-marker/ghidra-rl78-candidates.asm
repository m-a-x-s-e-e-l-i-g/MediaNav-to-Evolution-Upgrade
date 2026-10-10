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
ram:016976 e7 onew BC
ram:016977 1044 addw SP,0x44
ram:016979 c6 pop HL
ram:01697a d7 ret
ram:01697b c7 push HL
ram:01697c c3 push BC
ram:01697d c1 push AX
ram:01697e 2004 subw SP,0x4
ram:016980 fbf8ff movw HL,!0xffff8
ram:016983 ac06 movw AX,[HL + 0x6]
ram:016985 12 movw BC,AX
ram:016986 ac04 movw AX,[HL + 0x4]
ram:016988 340100 movw DE,0x1
ram:01698b 33 xchw AX,BC
ram:01698c 440000 cmpw AX,0x0
ram:01698f 61e8 skz
ram:016991 ee8c00 _br $! 0x16a20
ram:016994 13 movw AX,BC
ram:016995 25 subw AX,DE
ram:016996 61f8 sknz
ram:016998 ee8800 _br $! 0x16a23
ram:01699b 25 subw AX,DE
ram:01699c 61f8 sknz
ram:01699e ee8c00 _br $! 0x16a2d
ram:0169a1 240200 subw AX,0x2
ram:0169a4 61f8 sknz
ram:0169a6 eec800 _br $! 0x16a71
ram:0169a9 25 subw AX,DE
ram:0169aa 61f8 sknz
ram:0169ac eea000 _br $! 0x16a4f
ram:0169af 25 subw AX,DE
ram:0169b0 61f8 sknz
ram:0169b2 ee2d01 _br $! 0x16ae2
ram:0169b5 240200 subw AX,0x2
ram:0169b8 61f8 sknz
ram:0169ba ee5e01 _br $! 0x16b1b
ram:0169bd 25 subw AX,DE
ram:0169be 61f8 sknz
ram:0169c0 ee6201 _br $! 0x16b25
ram:0169c3 25 subw AX,DE
ram:0169c4 61f8 sknz
ram:0169c6 ee6601 _br $! 0x16b2f
ram:0169c9 247600 subw AX,0x76
ram:0169cc 61f8 sknz
ram:0169ce eec200 _br $! 0x16a93
ram:0169d1 244900 subw AX,0x49
ram:0169d4 61f8 sknz
ram:0169d6 ee6801 _br $! 0x16b41
ram:0169d9 25 subw AX,DE
ram:0169da 61f8 sknz
ram:0169dc eec001 _br $! 0x16b9f
ram:0169df 25 subw AX,DE
ram:0169e0 61f8 sknz
ram:0169e2 ee0302 _br $! 0x16be8
ram:0169e5 25 subw AX,DE
ram:0169e6 61f8 sknz
ram:0169e8 ee4602 _br $! 0x16c31
ram:0169eb 25 subw AX,DE
ram:0169ec 61f8 sknz
ram:0169ee ee6d02 _br $! 0x16c5e
ram:0169f1 25 subw AX,DE
ram:0169f2 61f8 sknz
ram:0169f4 ee9402 _br $! 0x16c8b
ram:0169f7 25 subw AX,DE
ram:0169f8 61f8 sknz
ram:0169fa eebb02 _br $! 0x16cb8
ram:0169fd 25 subw AX,DE
ram:0169fe 61f8 sknz
ram:016a00 eee202 _br $! 0x16ce5
ram:016a03 25 subw AX,DE
ram:016a04 61f8 sknz
ram:016a06 ee0903 _br $! 0x16d12
ram:016a09 25 subw AX,DE
ram:016a0a 61f8 sknz
ram:016a0c ee2f03 _br $! 0x16d3e
ram:016a0f 25 subw AX,DE
ram:016a10 61f8 sknz
ram:016a12 ee5503 _br $! 0x16d6a
ram:016a15 242d00 subw AX,0x2d
ram:016a18 61f8 sknz
ram:016a1a eef500 _br $! 0x16b12
ram:016a1d ee7403 br $! 0x16d94
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
ram:019269 c7 push HL
ram:01926a c3 push BC
ram:01926b c1 push AX
ram:01926c c1 push AX
ram:01926d fbf8ff movw HL,!0xffff8
ram:019270 ac04 movw AX,[HL + 0x4]
ram:019272 12 movw BC,AX
ram:019273 ac02 movw AX,[HL + 0x2]
ram:019275 340100 movw DE,0x1
ram:019278 33 xchw AX,BC
ram:019279 440000 cmpw AX,0x0
ram:01927c df35 bnz $ 0x192b3
ram:01927e 13 movw AX,BC
ram:01927f 25 subw AX,DE
ram:019280 61f8 sknz
ram:019282 ee8e00 _br $! 0x19313
ram:019285 241f00 subw AX,0x1f
ram:019288 dd2c bz $ 0x192b6
ram:01928a 25 subw AX,DE
ram:01928b dd5f bz $ 0x192ec
ram:01928d 240f00 subw AX,0xf
ram:019290 dd6f bz $ 0x19301
ram:019292 25 subw AX,DE
ram:019293 61f8 sknz
ram:019295 ee8d00 _br $! 0x19325
ram:019298 241100 subw AX,0x11
ram:01929b 61f8 sknz
ram:01929d eeab00 _br $! 0x1934b
ram:0192a0 240300 subw AX,0x3
ram:0192a3 61f8 sknz
ram:0192a5 ee8f00 _br $! 0x19337
ram:0192a8 240b00 subw AX,0xb
ram:0192ab 61f8 sknz
ram:0192ad eec800 _br $! 0x19378
ram:0192b0 eed200 br $! 0x19385
ram:0192b3 eecf00 br $! 0x19385
ram:0192b6 ac0c movw AX,[HL + 0xc]
ram:0192b8 14 movw DE,AX
ram:0192b9 89 mov A,[DE]
ram:0192ba d1 cmp0 A
ram:0192bb df05 bnz $ 0x192c2
ram:0192bd 716301 clr1 0xffe21.0x6
ram:0192c0 ef03 br $ 0x192c5
ram:0192c2 716201 set1 0xffe21.0x6
ram:0192c5 ac0c movw AX,[HL + 0xc]
ram:0192c7 14 movw DE,AX
ram:0192c8 89 mov A,[DE]
ram:0192c9 9f36e8 mov !0xfe836,A
ram:0192cc 8a01 mov A,[DE + 0x1]
ram:0192ce d1 cmp0 A
ram:0192cf df05 bnz $ 0x192d6
ram:0192d1 710305 clr1 0xffe25.0x0
ram:0192d4 ef03 br $ 0x192d9
ram:0192d6 710205 set1 0xffe25.0x0
ram:0192d9 ac0c movw AX,[HL + 0xc]
ram:0192db 14 movw DE,AX
ram:0192dc 8a02 mov A,[DE + 0x2]
ram:0192de d1 cmp0 A
ram:0192df df05 bnz $ 0x192e6
ram:0192e1 711303 clr1 0xffe23.0x1
ram:0192e4 ef03 br $ 0x192e9
ram:0192e6 711203 set1 0xffe23.0x1
ram:0192e9 ee9900 br $! 0x19385
ram:0192ec 716201 set1 0xffe21.0x6
ram:0192ef ac0c movw AX,[HL + 0xc]
ram:0192f1 14 movw DE,AX
ram:0192f2 89 mov A,[DE]
ram:0192f3 d1 cmp0 A
ram:0192f4 df05 bnz $ 0x192fb
ram:0192f6 710305 clr1 0xffe25.0x0
ram:0192f9 ef03 br $ 0x192fe
ram:0192fb 710205 set1 0xffe25.0x0
ram:0192fe ee8400 br $! 0x19385
ram:019301 ac0c movw AX,[HL + 0xc]
ram:019303 14 movw DE,AX
ram:019304 89 mov A,[DE]
ram:019305 91 dec 
ram:019306 df03 bnz $ 0x1930b
ram:019308 e1 oneb A
ram:019309 ef01 br $ 0x1930c
ram:01930b f1 clrb A
ram:01930c 61fb rorc A,1
ram:01930e 711100 mov1 0xffe20.0x1,CY
ram:019311 ef72 br $ 0x19385
ram:019313 ac0c movw AX,[HL + 0xc]
ram:019315 14 movw DE,AX
ram:019316 89 mov A,[DE]
ram:019317 91 dec 
ram:019318 df03 bnz $ 0x1931d
ram:01931a e1 oneb A
ram:01931b ef01 br $ 0x1931e
ram:01931d f1 clrb A
ram:01931e 61fb rorc A,1
ram:019320 713100 mov1 0xffe20.0x3,CY
ram:019323 ef60 br $ 0x19385
ram:019325 ac0c movw AX,[HL + 0xc]
ram:019327 14 movw DE,AX
ram:019328 89 mov A,[DE]
ram:019329 91 dec 
ram:01932a df03 bnz $ 0x1932f
ram:01932c e1 oneb A
ram:01932d ef01 br $ 0x19330
ram:01932f f1 clrb A
ram:019330 61fb rorc A,1
ram:019332 716106 mov1 0xffe26.0x6,CY
ram:019335 ef4e br $ 0x19385
ram:019337 ac0c movw AX,[HL + 0xc]
ram:019339 14 movw DE,AX
ram:01933a 89 mov A,[DE]
ram:01933b 3149 shl A,0x4
ram:01933d 5c30 and A,#0x30
ram:01933f 3430e8 movw DE,0xe830
ram:019342 70 mov ,A
ram:019343 89 mov A,[DE]
ram:019344 5ccf and A,#0xcf
ram:019346 6168 or A,
ram:019348 99 mov [DE],A
ram:019349 ef3a br $ 0x19385
ram:01934b ac0c movw AX,[HL + 0xc]
ram:01934d 14 movw DE,AX
ram:01934e 89 mov A,[DE]
ram:01934f 3430e8 movw DE,0xe830
ram:019352 718c mov1 CY,A.0x0
ram:019354 89 mov A,[DE]
ram:019355 71f9 mov1 A.0x7,CY
ram:019357 99 mov [DE],A
ram:019358 317517 bf A.0x7,$ 0x19371
ram:01935b cc01fd mov [HL + 0x1],0xfd
ram:01935e db1ee4 movw BC,!0xfe41e
ram:019361 17 movw AX,HL
ram:019362 a1 incw AX
ram:019363 c1 push AX
ram:019364 490e00 mov A,!0xf000e[BC]
ram:019367 9efc mov CS,A
ram:019369 790c00 movw AX,!0xf000c[BC]
ram:01936c 14 movw DE,AX
ram:01936d e6 onew AX
ram:01936e a1 incw AX
ram:01936f 61ea call DE
ram:019371 c0 pop AX
ram:019372 fc0e8e01 call !!0x18e0e
ram:019376 ef0d br $ 0x19385
ram:019378 ac0c movw AX,[HL + 0xc]
ram:01937a 14 movw DE,AX
ram:01937b 89 mov A,[DE]
ram:01937c 3430e8 movw DE,0xe830
ram:01937f 718c mov1 CY,A.0x0
ram:019381 89 mov A,[DE]
ram:019382 71e9 mov1 A.0x6,CY
ram:019384 99 mov [DE],A
ram:019385 e7 onew BC
ram:019386 1006 addw SP,0x6
ram:019388 c6 pop HL
ram:019389 d7 ret
ram:01938a c7 push HL
ram:01938b c3 push BC
ram:01938c c1 push AX
ram:01938d 2004 subw SP,0x4
ram:01938f fbf8ff movw HL,!0xffff8
ram:019392 cc0300 mov [HL + 0x3],0x0
ram:019395 ac06 movw AX,[HL + 0x6]
ram:019397 12 movw BC,AX
ram:019398 ac04 movw AX,[HL + 0x4]
ram:01939a 340100 movw DE,0x1
ram:01939d 33 xchw AX,BC
ram:01939e 440000 cmpw AX,0x0
ram:0193a1 df2b bnz $ 0x193ce
ram:0193a3 13 movw AX,BC
ram:0193a4 242100 subw AX,0x21
ram:0193a7 dd28 bz $ 0x193d1
ram:0193a9 241f00 subw AX,0x1f
ram:0193ac dd36 bz $ 0x193e4
ram:0193ae 25 subw AX,DE
ram:0193af dd44 bz $ 0x193f5
ram:0193b1 25 subw AX,DE
ram:0193b2 dd52 bz $ 0x19406
ram:0193b4 25 subw AX,DE
ram:0193b5 dd5e bz $ 0x19415
ram:0193b7 25 subw AX,DE
ram:0193b8 dd6c bz $ 0x19426
ram:0193ba 25 subw AX,DE
ram:0193bb dd7b bz $ 0x19438
ram:0193bd 25 subw AX,DE
ram:0193be 61f8 sknz
ram:0193c0 ee8900 _br $! 0x1944c
ram:0193c3 240a00 subw AX,0xa
ram:0193c6 61f8 sknz
ram:0193c8 ee8e00 _br $! 0x19459
ram:0193cb ee9d00 br $! 0x1946b
ram:0193ce ee9a00 br $! 0x1946b
ram:0193d1 ac0e movw AX,[HL + 0xe]
ram:0193d3 bb movw [HL],AX
ram:0193d4 31020503 bt 0xffe25.0x0,$ 0x193d9
ram:0193d8 f1 clrb A
ram:0193d9 ef01 br $ 0x193dc
ram:0193db e1 oneb A
ram:0193dc 72 mov ,A
ram:0193dd ab movw AX,[HL]
ram:0193de 14 movw DE,AX
ram:0193df 62 mov A,
ram:0193e0 99 mov [DE],A
ram:0193e1 ee8700 br $! 0x1946b
ram:0193e4 ac0e movw AX,[HL + 0xe]
ram:0193e6 bb movw [HL],AX
ram:0193e7 8f2fe8 mov A,!0xfe82f
ram:0193ea 3169 shl A,0x6
ram:0193ec 317a shr A,0x7
ram:0193ee 72 mov ,A
ram:0193ef ab movw AX,[HL]
ram:0193f0 14 movw DE,AX
ram:0193f1 62 mov A,
ram:0193f2 99 mov [DE],A
ram:0193f3 ef76 br $ 0x1946b
ram:0193f5 ac0e movw AX,[HL + 0xe]
ram:0193f7 bb movw [HL],AX
ram:0193f8 8f2fe8 mov A,!0xfe82f
ram:0193fb 3159 shl A,0x5
ram:0193fd 317a shr A,0x7
ram:0193ff 72 mov ,A
ram:019400 ab movw AX,[HL]
ram:019401 14 movw DE,AX
ram:019402 62 mov A,
ram:019403 99 mov [DE],A
ram:019404 ef65 br $ 0x1946b
ram:019406 ac0e movw AX,[HL + 0xe]
ram:019408 bb movw [HL],AX
ram:019409 8f30e8 mov A,!0xfe830
ram:01940c 317a shr A,0x7
ram:01940e 72 mov ,A
ram:01940f ab movw AX,[HL]
ram:019410 14 movw DE,AX
ram:019411 62 mov A,
ram:019412 99 mov [DE],A
ram:019413 ef56 br $ 0x1946b
ram:019415 ac0e movw AX,[HL + 0xe]
ram:019417 bb movw [HL],AX
ram:019418 8f2fe8 mov A,!0xfe82f
ram:01941b 3149 shl A,0x4
ram:01941d 317a shr A,0x7
ram:01941f 72 mov ,A
ram:019420 ab movw AX,[HL]
ram:019421 14 movw DE,AX
ram:019422 62 mov A,
ram:019423 99 mov [DE],A
ram:019424 ef45 br $ 0x1946b
ram:019426 ac0e movw AX,[HL + 0xe]
ram:019428 bb movw [HL],AX
ram:019429 8f2fe8 mov A,!0xfe82f
ram:01942c 5c01 and A,#0x1
ram:01942e 72 mov ,A
ram:01942f ab movw AX,[HL]
ram:019430 14 movw DE,AX
ram:019431 62 mov A,
ram:019432 99 mov [DE],A
ram:019433 cc0301 mov [HL + 0x3],0x1
ram:019436 ef33 br $ 0x1946b
ram:019438 ac0e movw AX,[HL + 0xe]
ram:01943a bb movw [HL],AX
ram:01943b 8f30e8 mov A,!0xfe830
ram:01943e 3129 shl A,0x2
ram:019440 316a shr A,0x6
ram:019442 72 mov ,A
ram:019443 ab movw AX,[HL]
ram:019444 14 movw DE,AX
ram:019445 62 mov A,
ram:019446 99 mov [DE],A
ram:019447 cc0301 mov [HL + 0x3],0x1
ram:01944a ef1f br $ 0x1946b
ram:01944c ac0e movw AX,[HL + 0xe]
ram:01944e bb movw [HL],AX
ram:01944f 14 movw DE,AX
ram:019450 8f36e8 mov A,!0xfe836
ram:019453 99 mov [DE],A
ram:019454 cc0301 mov [HL + 0x3],0x1
ram:019457 ef12 br $ 0x1946b
ram:019459 ac0e movw AX,[HL + 0xe]
ram:01945b bb movw [HL],AX
ram:01945c 8f30e8 mov A,!0xfe830
ram:01945f 3119 shl A,0x1
ram:019461 317a shr A,0x7
ram:019463 72 mov ,A
ram:019464 ab movw AX,[HL]
ram:019465 14 movw DE,AX
ram:019466 62 mov A,
ram:019467 99 mov [DE],A
ram:019468 cc0301 mov [HL + 0x3],0x1
ram:01946b 8c03 mov A,[HL + 0x3]
ram:01946d 318e shrw AX,0x8
ram:01946f 12 movw BC,AX
ram:019470 1008 addw SP,0x8
ram:019472 c6 pop HL
ram:019473 d7 ret
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
ram:01e7ca c7 push HL
ram:01e7cb c1 push AX
ram:01e7cc 200c subw SP,0xc
ram:01e7ce fbf8ff movw HL,!0xffff8
ram:01e7d1 cc0b01 mov [HL + 0xb],0x1
ram:01e7d4 8c0c mov A,[HL + 0xc]
ram:01e7d6 d1 cmp0 A
ram:01e7d7 dd0b bz $ 0x1e7e4
ram:01e7d9 91 dec 
ram:01e7da dd2e bz $ 0x1e80a
ram:01e7dc 91 dec 
ram:01e7dd dd61 bz $ 0x1e840
ram:01e7df 91 dec 
ram:01e7e0 dd78 bz $ 0x1e85a
ram:01e7e2 ef7a br $ 0x1e85e
ram:01e7e4 ac14 movw AX,[HL + 0x14]
ram:01e7e6 a1 incw AX
ram:01e7e7 ac14 movw AX,[HL + 0x14]
ram:01e7e9 14 movw DE,AX
ram:01e7ea 89 mov A,[DE]
ram:01e7eb 318e shrw AX,0x8
ram:01e7ed bc08 movw [HL + 0x8],AX
ram:01e7ef f6 clrw AX
ram:01e7f0 c1 push AX
ram:01e7f1 ac08 movw AX,[HL + 0x8]
ram:01e7f3 f7 clrw BC
ram:01e7f4 c3 push BC
ram:01e7f5 c1 push AX
ram:01e7f6 ac14 movw AX,[HL + 0x14]
ram:01e7f8 c1 push AX
ram:01e7f9 30e100 movw AX,0xe1
ram:01e7fc fc1f1900 call !!0x191f
ram:01e800 1008 addw SP,0x8
ram:01e802 92 dec 
ram:01e803 dd59 bz $ 0x1e85e
ram:01e805 cc0b00 mov [HL + 0xb],0x0
ram:01e808 ef54 br $ 0x1e85e
ram:01e80a 340084 movw DE,0x8400
ram:01e80d 15 movw AX,DE
ram:01e80e bc06 movw [HL + 0x6],AX
ram:01e810 cc0803 mov [HL + 0x8],0x3
ram:01e813 ac14 movw AX,[HL + 0x14]
ram:01e815 bc04 movw [HL + 0x4],AX
ram:01e817 a1 incw AX
ram:01e818 ac14 movw AX,[HL + 0x14]
ram:01e81a 14 movw DE,AX
ram:01e81b 89 mov A,[DE]
ram:01e81c 318e shrw AX,0x8
ram:01e81e bc02 movw [HL + 0x2],AX
ram:01e820 f6 clrw AX
ram:01e821 bb movw [HL],AX
ram:01e822 ab movw AX,[HL]
ram:01e823 614902 cmpw AX,[HL + 0x2]
ram:01e826 de36 bnc $ 0x1e85e
ram:01e828 ab movw AX,[HL]
ram:01e829 610906 addw AX,[HL + 0x6]
ram:01e82c 14 movw DE,AX
ram:01e82d 8c08 mov A,[HL + 0x8]
ram:01e82f 9efd mov ES,A
ram:01e831 1189 mov A,ES:[DE]
ram:01e833 72 mov ,A
ram:01e834 ab movw AX,[HL]
ram:01e835 610904 addw AX,[HL + 0x4]
ram:01e838 14 movw DE,AX
ram:01e839 62 mov A,
ram:01e83a 99 mov [DE],A
ram:01e83b 617900 incw [HL + 0x0]
ram:01e83e efe2 br $ 0x1e822
ram:01e840 ac14 movw AX,[HL + 0x14]
ram:01e842 14 movw DE,AX
ram:01e843 89 mov A,[DE]
ram:01e844 9dd8 mov 0xffdf8,A
ram:01e846 f4d9 clrb 0xffdf9
ram:01e848 f6 clrw AX
ram:01e849 bdda movw 0xffdfa,AX
ram:01e84b 510a mov ,0xa
ram:01e84d fd7106 call !0xf0671
ram:01e850 dada movw BC,0xffdfa
ram:01e852 add8 movw AX,0xffdf8
ram:01e854 fc5b1300 call !!0x135b
ram:01e858 ef04 br $ 0x1e85e
ram:01e85a f6 clrw AX
ram:01e85b bfece2 movw !0xfe2ec,AX
ram:01e85e 8c0b mov A,[HL + 0xb]
ram:01e860 318e shrw AX,0x8
ram:01e862 12 movw BC,AX
ram:01e863 100e addw SP,0xe
ram:01e865 c6 pop HL
ram:01e866 d7 ret
ram:01e867 c7 push HL
ram:01e868 c3 push BC
ram:01e869 c1 push AX
ram:01e86a 20fe subw SP,0xfe
ram:01e86c 2010 subw SP,0x10
ram:01e86e fbf8ff movw HL,!0xffff8
ram:01e871 e1 oneb A
ram:01e872 87 inc 
ram:01e873 9c0d mov [HL + 0xd],A
ram:01e875 97 dec 
ram:01e876 17 movw AX,HL
ram:01e877 041001 addw AX,0x110
ram:01e87a 14 movw DE,AX
ram:01e87b a9 movw AX,[DE]
ram:01e87c 12 movw BC,AX
ram:01e87d 17 movw AX,HL
ram:01e87e 040e01 addw AX,0x10e
ram:01e881 14 movw DE,AX
ram:01e882 a9 movw AX,[DE]
ram:01e883 340100 movw DE,0x1
ram:01e886 33 xchw AX,BC
ram:01e887 440000 cmpw AX,0x0
ram:01e88a 61e8 skz
ram:01e88c eef800 _br $! 0x1e987
ram:01e88f 13 movw AX,BC
ram:01e890 240000 subw AX,0x0
ram:01e893 61f8 sknz
ram:01e895 eef200 _br $! 0x1e98a
ram:01e898 240800 subw AX,0x8
ram:01e89b 61f8 sknz
ram:01e89d ee3d02 _br $! 0x1eadd
ram:01e8a0 240800 subw AX,0x8
ram:01e8a3 61f8 sknz
ram:01e8a5 ee1102 _br $! 0x1eab9
ram:01e8a8 25 subw AX,DE
ram:01e8a9 61f8 sknz
ram:01e8ab ee5302 _br $! 0x1eb01
ram:01e8ae 25 subw AX,DE
ram:01e8af 61f8 sknz
ram:01e8b1 ee7102 _br $! 0x1eb25
ram:01e8b4 25 subw AX,DE
ram:01e8b5 61f8 sknz
ram:01e8b7 ee6b02 _br $! 0x1eb25
ram:01e8ba 25 subw AX,DE
ram:01e8bb 61f8 sknz
ram:01e8bd ee6502 _br $! 0x1eb25
ram:01e8c0 25 subw AX,DE
ram:01e8c1 61f8 sknz
ram:01e8c3 ee5f02 _br $! 0x1eb25
ram:01e8c6 25 subw AX,DE
ram:01e8c7 61f8 sknz
ram:01e8c9 ee5902 _br $! 0x1eb25
ram:01e8cc 25 subw AX,DE
ram:01e8cd 61f8 sknz
ram:01e8cf ee5302 _br $! 0x1eb25
ram:01e8d2 25 subw AX,DE
ram:01e8d3 61f8 sknz
ram:01e8d5 ee4d02 _br $! 0x1eb25
ram:01e8d8 240800 subw AX,0x8
ram:01e8db 61f8 sknz
ram:01e8dd ee9b02 _br $! 0x1eb7b
ram:01e8e0 25 subw AX,DE
ram:01e8e1 61f8 sknz
ram:01e8e3 ee1904 _br $! 0x1ecff
ram:01e8e6 25 subw AX,DE
ram:01e8e7 61f8 sknz
ram:01e8e9 ee3704 _br $! 0x1ed23
ram:01e8ec 25 subw AX,DE
ram:01e8ed 61f8 sknz
ram:01e8ef ee3104 _br $! 0x1ed23
ram:01e8f2 25 subw AX,DE
ram:01e8f3 61f8 sknz
ram:01e8f5 ee2b04 _br $! 0x1ed23
ram:01e8f8 25 subw AX,DE
ram:01e8f9 61f8 sknz
ram:01e8fb ee2504 _br $! 0x1ed23
ram:01e8fe 25 subw AX,DE
ram:01e8ff 61f8 sknz
ram:01e901 ee1f04 _br $! 0x1ed23
ram:01e904 25 subw AX,DE
ram:01e905 61f8 sknz
ram:01e907 ee1904 _br $! 0x1ed23
ram:01e90a 25 subw AX,DE
ram:01e90b 61f8 sknz
ram:01e90d ee1304 _br $! 0x1ed23
ram:01e910 25 subw AX,DE
ram:01e911 61f8 sknz
ram:01e913 ee8902 _br $! 0x1eb9f
ram:01e916 25 subw AX,DE
ram:01e917 61f8 sknz
ram:01e919 eea702 _br $! 0x1ebc3
ram:01e91c 25 subw AX,DE
ram:01e91d 61f8 sknz
ram:01e91f eec502 _br $! 0x1ebe7
ram:01e922 25 subw AX,DE
ram:01e923 61f8 sknz
ram:01e925 eee302 _br $! 0x1ec0b
ram:01e928 25 subw AX,DE
ram:01e929 61f8 sknz
ram:01e92b ee0103 _br $! 0x1ec2f
ram:01e92e 25 subw AX,DE
ram:01e92f 61f8 sknz
ram:01e931 eefb02 _br $! 0x1ec2f
ram:01e934 25 subw AX,DE
ram:01e935 61f8 sknz
ram:01e937 eef502 _br $! 0x1ec2f
ram:01e93a 25 subw AX,DE
ram:01e93b 61f8 sknz
ram:01e93d eeef02 _br $! 0x1ec2f
ram:01e940 25 subw AX,DE
ram:01e941 61f8 sknz
ram:01e943 eee902 _br $! 0x1ec2f
ram:01e946 25 subw AX,DE
ram:01e947 61f8 sknz
ram:01e949 eee302 _br $! 0x1ec2f
ram:01e94c 25 subw AX,DE
ram:01e94d 61f8 sknz
ram:01e94f ee3303 _br $! 0x1ec85
ram:01e952 25 subw AX,DE
ram:01e953 61f8 sknz
ram:01e955 ee5103 _br $! 0x1eca9
ram:01e958 25 subw AX,DE
ram:01e959 61f8 sknz
ram:01e95b ee4b03 _br $! 0x1eca9
ram:01e95e 25 subw AX,DE
ram:01e95f 61f8 sknz
ram:01e961 ee4503 _br $! 0x1eca9
ram:01e964 25 subw AX,DE
ram:01e965 61f8 sknz
ram:01e967 ee3f03 _br $! 0x1eca9
ram:01e96a 25 subw AX,DE
ram:01e96b 61f8 sknz
ram:01e96d ee3903 _br $! 0x1eca9
ram:01e970 25 subw AX,DE
ram:01e971 61f8 sknz
ram:01e973 ee3303 _br $! 0x1eca9
ram:01e976 24c500 subw AX,0xc5
ram:01e979 61f8 sknz
ram:01e97b eefa03 _br $! 0x1ed78
ram:01e97e 25 subw AX,DE
ram:01e97f 61f8 sknz
ram:01e981 ee1704 _br $! 0x1ed9b
ram:01e984 ee3704 br $! 0x1edbe
ram:01e987 ee3404 br $! 0x1edbe
ram:01ed78 f6 clrw AX
ram:01ed79 c1 push AX
ram:01ed7a 17 movw AX,HL
ram:01ed7b 12 movw BC,AX
ram:01ed7c 791a01 movw AX,!0xf011a[BC]
ram:01ed7f f7 clrw BC
ram:01ed80 c3 push BC
ram:01ed81 c1 push AX
ram:01ed82 17 movw AX,HL
ram:01ed83 12 movw BC,AX
ram:01ed84 791801 movw AX,!0xf0118[BC]
ram:01ed87 c1 push AX
ram:01ed88 30fd00 movw AX,0xfd
ram:01ed8b fc1f1900 call !!0x191f
ram:01ed8f 1008 addw SP,0x8
ram:01ed91 92 dec 
ram:01ed92 dd2f bz $ 0x1edc3
ram:01ed94 f1 clrb A
ram:01ed95 87 inc 
ram:01ed96 9c0d mov [HL + 0xd],A
ram:01ed98 97 dec 
ram:01ed99 ef28 br $ 0x1edc3
ram:01ed9b f6 clrw AX
ram:01ed9c c1 push AX
ram:01ed9d 17 movw AX,HL
ram:01ed9e 12 movw BC,AX
ram:01ed9f 791a01 movw AX,!0xf011a[BC]
ram:01eda2 f7 clrw BC
ram:01eda3 c3 push BC
ram:01eda4 c1 push AX
ram:01eda5 17 movw AX,HL
ram:01eda6 12 movw BC,AX
ram:01eda7 791801 movw AX,!0xf0118[BC]
ram:01edaa c1 push AX
ram:01edab 30dc00 movw AX,0xdc
ram:01edae fc1f1900 call !!0x191f
ram:01edb2 1008 addw SP,0x8
ram:01edb4 92 dec 
ram:01edb5 dd0c bz $ 0x1edc3
ram:01edb7 f1 clrb A
ram:01edb8 87 inc 
ram:01edb9 9c0d mov [HL + 0xd],A
ram:01edbb 97 dec 
ram:01edbc ef05 br $ 0x1edc3
ram:01edbe f1 clrb A
ram:01edbf 87 inc 
ram:01edc0 9c0d mov [HL + 0xd],A
ram:01edc2 97 dec 
ram:01edc3 87 inc 
ram:01edc4 8c0d mov A,[HL + 0xd]
ram:01edc6 97 dec 
ram:01edc7 318e shrw AX,0x8
ram:01edc9 12 movw BC,AX
ram:01edca 10fe addw SP,0xfe
ram:01edcc 1014 addw SP,0x14
ram:01edce c6 pop HL
ram:01edcf d7 ret
