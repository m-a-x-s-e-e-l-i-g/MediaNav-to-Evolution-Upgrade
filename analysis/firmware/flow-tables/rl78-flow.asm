; Candidate ISA; not device execution. + indicates absent in comparison list.
003c7   61cf         sel      RB0
003c9   5100         mov      A, #0x0
003cb   718c         mov1     CY, A.0
003cd   7109fe       mov1     0xffffe.0, CY
003d0   cbf8d2fe     movw     SP, #0xfed2
003d4   fc687d02     call     0x27d68
003d8   f6           clrw     AX
003d9   bf96bf       movw     0xfbf96, AX
003dc   bf80bf       movw     0xfbf80, AX
003df   bf84bf       movw     0xfbf84, AX
003e2   e6           onew     AX
003e3   bf82bf       movw     0xfbf82, AX
003e6   309abf       movw     AX, #0xbf9a
003e9   bf98bf       movw     0xfbf98, AX
003ec   53c0         mov      B, #0xc0
003ee   f6           clrw     AX
003ef   93           dec      B
003f0   93           dec      B
003f1   5820fe       movw     [B+0xfe20], AX
003f4   dff9         bnz      0x3ef
003f6   4100         mov      ES, #0x0
003f8   36c26e       movw     HL, #0x6ec2
003fb   34d2e3       movw     DE, #0xe3d2
003fe   ef05         br       0x405
00400   118b         mov      A, ES:[HL]
00402   99           mov      [DE], A
00403   a7           incw     HL
00404   a5           incw     DE
00405   17           movw     AX, HL
00406   448e75       cmpw     AX, #0x758e
00409   dff5         bnz      0x400
0040b   368e75       movw     HL, #0x758e
0040e   34b1ea       movw     DE, #0xeab1
00411   ef0a         br       0x41d
00413   4100         mov      ES, #0x0
00415   118b         mov      A, ES:[HL]
00417   410f         mov      ES, #0xf
00419   1199         mov      ES:[DE], A
0041b   a7           incw     HL
0041c   a5           incw     DE
0041d   17           movw     AX, HL
0041e   448e75       cmpw     AX, #0x758e
00421   dff0         bnz      0x413
00423   36babf       movw     HL, #0xbfba
00426   30d2e3       movw     AX, #0xe3d2
00429   ef04         br       0x42f
0042b   cc0000       mov      [HL], #0x0
0042e   a7           incw     HL
0042f   47           cmpw     AX, HL
00430   dff9         bnz      0x42b
00432   410f         mov      ES, #0xf
00434   36b1ea       movw     HL, #0xeab1
00437   30b1ea       movw     AX, #0xeab1
0043a   ef05         br       0x441
0043c   11cc0000     mov      ES:[HL], #0x0
00440   a7           incw     HL
00441   47           cmpw     AX, HL
00442   dff8         bnz      0x43c
00444   4100         mov      ES, #0x0
00446   368e75       movw     HL, #0x758e
00449   34b1ea       movw     DE, #0xeab1
0044c   ef05         br       0x453
0044e   118b         mov      A, ES:[HL]
00450   99           mov      [DE], A
00451   a7           incw     HL
00452   a5           incw     DE
00453   17           movw     AX, HL
00454   448e75       cmpw     AX, #0x758e
00457   dff5         bnz      0x44e
00459   36b1ea       movw     HL, #0xeab1
0045c   30b1ea       movw     AX, #0xeab1
0045f   ef04         br       0x465
00461   cc0000       mov      [HL], #0x0
00464   a7           incw     HL
00465   47           cmpw     AX, HL
00466   dff9         bnz      0x461
00468   fc347f00     call     0x7f34
0046c   f6           clrw     AX
0046d   fc697d02     call     0x27d69
00471   effe         br       0x471
00473   61dd         push     PSW
00475   717bfa       clr1     PSW.7
00478   bef0         movw     0xffff0, AX
0047a   add8         movw     AX, 0xffed8
0047c   bef2         movw     0xffff2, AX
0047e   00           nop      
0047f   aef6         movw     AX, 0xffff6
00481   61cd         pop      PSW
00483   d7           ret      
0061c + 82           inc      C
0061d + 92           dec      C
0061e + dd2b         bz       0x64b
00620 + 61dd         push     PSW
00622 + 717bfa       clr1     PSW.7
00625 + cfe80080     mov      0xf00e8, #0x80
00629 + bef0         movw     0xffff0, AX
0062b + f6           clrw     AX
0062c + bef2         movw     0xffff2, AX
0062e + bef4         movw     0xffff4, AX
00630 + 62           mov      A, C
00631 + 08           xch      A, X
00632 + bef6         movw     0xffff6, AX
00634 + cfe80081     mov      0xf00e8, #0x81
00638 + 8fe800       mov      A, 0xf00e8
0063b + 3103fa       bt       A.0, 0x638
0063e + afe000       movw     AX, 0xf00e0
00641 + 60           mov      A, X
00642 + 72           mov      C, A
00643 + aef0         movw     AX, 0xffff0
00645 + f5e800       clrb     0xf00e8
00648 + 61cd         pop      PSW
0064a + d7           ret      
0064b + 60           mov      A, X
0064c + 72           mov      C, A
0064d + f6           clrw     AX
0064e + b1           decw     AX
0064f + d7           ret      
00650   06da         addw     AX, 0xffeda
00652   bdda         movw     0xffeda, AX
00654   addc         movw     AX, 0xffedc
00656   06d8         addw     AX, 0xffed8
00658   bdd8         movw     0xffed8, AX
0065a   61d8         sknc     
0065c   a6da         incw     0xffeda
0065e   d7           ret      
00671   d1           cmp0     A
00672   dd17         bz       0x68b
00674   c1           push     AX
00675   c3           push     BC
00676   dad8         movw     BC, 0xffed8
00678   9dd8         mov      0xffed8, A
0067a   adda         movw     AX, 0xffeda
0067c   311c         shlw     BC, #0x1
0067e   61ee         rolwc    AX, #0x1
00680   b4d8         dec      0xffed8
00682   dff8         bnz      0x67c
00684   bdda         movw     0xffeda, AX
00686   13           movw     AX, BC
00687   bdd8         movw     0xffed8, AX
00689   c2           pop      BC
0068a   c0           pop      AX
0068b   d7           ret      
0068c   d1           cmp0     A
0068d   dd1b         bz       0x6aa
0068f   c1           push     AX
00690   c3           push     BC
00691   dada         movw     BC, 0xffeda
00693   9dda         mov      0xffeda, A
00695   add8         movw     AX, 0xffed8
00697   311e         shrw     AX, #0x1
00699   33           xchw     AX, BC
0069a   311e         shrw     AX, #0x1
0069c   33           xchw     AX, BC
0069d   71f9         mov1     A.7, CY
0069f   b4da         dec      0xffeda
006a1   dff4         bnz      0x697
006a3   bdd8         movw     0xffed8, AX
006a5   13           movw     AX, BC
006a6   bdda         movw     0xffeda, AX
006a8   c2           pop      BC
006a9   c0           pop      AX
006aa   d7           ret      
00d3e   a2d2e3       incw     0xfe3d2
00d41   61fc         reti     
00d43   c1           push     AX
00d44   c3           push     BC
00d45   c7           push     HL
00d46   adde         movw     AX, 0xffede
00d48   c1           push     AX
00d49   addc         movw     AX, 0xffedc
00d4b   c1           push     AX
00d4c   adda         movw     AX, 0xffeda
00d4e   c1           push     AX
00d4f   add8         movw     AX, 0xffed8
00d51   c1           push     AX
00d52   afee01       movw     AX, 0xf01ee
00d55   f1           clrb     A
00d56   08           xch      A, X
00d57   5c01         and      A, #0x1
00d59   08           xch      A, X
00d5a   6168         or       A, X
00d5c   dd09         bz       0xd67
00d5e   f6           clrw     AX
00d5f   bfdae3       movw     0xfe3da, AX
00d62   bfdce3       movw     0xfe3dc, AX
00d65   ef36         br       0xd9d
00d67   fb7eff       movw     HL, 0xfff7e
00d6a   17           movw     AX, HL
00d6b   311e         shrw     AX, #0x1
00d6d   12           movw     BC, AX
00d6e   17           movw     AX, HL
00d6f   312e         shrw     AX, #0x2
00d71   03           addw     AX, BC
00d72   bdd8         movw     0xffed8, AX
00d74   f6           clrw     AX
00d75   bdda         movw     0xffeda, AX
00d77   add8         movw     AX, 0xffed8
00d79   bddc         movw     0xffedc, AX
00d7b   adda         movw     AX, 0xffeda
00d7d   bdde         movw     0xffede, AX
00d7f   afdae3       movw     AX, 0xfe3da
00d82   bdd8         movw     0xffed8, AX
00d84   afdce3       movw     AX, 0xfe3dc
00d87   bdda         movw     0xffeda, AX
00d89   5102         mov      A, #0x2
00d8b   fd8c06       call     0x68c
00d8e   adde         movw     AX, 0xffede
00d90   fd5006       call     0x650
00d93   adda         movw     AX, 0xffeda
00d95   bfdce3       movw     0xfe3dc, AX
00d98   add8         movw     AX, 0xffed8
00d9a   bfdae3       movw     0xfe3da, AX
00d9d   a2dee3       incw     0xfe3de
00da0   afd2e3       movw     AX, 0xfe3d2
00da3   bfe0e3       movw     0xfe3e0, AX
00da6   c0           pop      AX
00da7   bdd8         movw     0xffed8, AX
00da9   c0           pop      AX
00daa   bdda         movw     0xffeda, AX
00dac   c0           pop      AX
00dad   bddc         movw     0xffedc, AX
00daf   c0           pop      AX
00db0   bdde         movw     0xffede, AX
00db2   c6           pop      HL
00db3   c2           pop      BC
00db4   c0           pop      AX
00db5   61fc         reti     
00db7   61fc         reti     
00db9   e5d5e3       oneb     0xfe3d5
00dbc   61fc         reti     
00dbe   e5e2e3       oneb     0xfe3e2
00dc1   710be3       clr1     0xfffe3.0
00dc4   710ae7       set1     0xfffe7.0
00dc7   717b30       clr1     0xfff30.7
00dca   61fc         reti     
00dcc   c1           push     AX
00dcd   c3           push     BC
00dce   c5           push     DE
00dcf   c7           push     HL
00dd0   520c         mov      C, #0xc
00dd2   92           dec      C
00dd3   92           dec      C
00dd4   69d4fe       movw     AX, [C+0xfed4]
00dd7   c1           push     AX
00dd8   dff8         bnz      0xdd2
00dda   8efd         mov      A, ES
00ddc   70           mov      X, A
00ddd   8efc         mov      A, CS
00ddf   c1           push     AX
00de0   fc9c8100     call     0x819c
00de4   c0           pop      AX
00de5   9efc         mov      CS, A
00de7   60           mov      A, X
00de8   9efd         mov      ES, A
00dea   34d4fe       movw     DE, #0xfed4
00ded   5206         mov      C, #0x6
00def   c0           pop      AX
00df0   b9           movw     [DE], AX
00df1   a5           incw     DE
00df2   a5           incw     DE
00df3   92           dec      C
00df4   dff9         bnz      0xdef
00df6   c6           pop      HL
00df7   c4           pop      DE
00df8   c2           pop      BC
00df9   c0           pop      AX
00dfa   61fc         reti     
00dfc   c1           push     AX
00dfd   c3           push     BC
00dfe   c5           push     DE
00dff   c7           push     HL
00e00   520c         mov      C, #0xc
00e02   92           dec      C
00e03   92           dec      C
00e04   69d4fe       movw     AX, [C+0xfed4]
00e07   c1           push     AX
00e08   dff8         bnz      0xe02
00e0a   8efd         mov      A, ES
00e0c   70           mov      X, A
00e0d   8efc         mov      A, CS
00e0f   c1           push     AX
00e10   fccd8100     call     0x81cd
00e14   c0           pop      AX
00e15   9efc         mov      CS, A
00e17   60           mov      A, X
00e18   9efd         mov      ES, A
00e1a   34d4fe       movw     DE, #0xfed4
00e1d   5206         mov      C, #0x6
00e1f   c0           pop      AX
00e20   b9           movw     [DE], AX
00e21   a5           incw     DE
00e22   a5           incw     DE
00e23   92           dec      C
00e24   dff9         bnz      0xe1f
00e26   c6           pop      HL
00e27   c4           pop      DE
00e28   c2           pop      BC
00e29   c0           pop      AX
00e2a   61fc         reti     
00e2c   c1           push     AX
00e2d   c3           push     BC
00e2e   c5           push     DE
00e2f   c7           push     HL
00e30   520c         mov      C, #0xc
00e32   92           dec      C
00e33   92           dec      C
00e34   69d4fe       movw     AX, [C+0xfed4]
00e37   c1           push     AX
00e38   dff8         bnz      0xe32
00e3a   8efd         mov      A, ES
00e3c   70           mov      X, A
00e3d   8efc         mov      A, CS
00e3f   c1           push     AX
00e40   fcb58200     call     0x82b5
00e44   c0           pop      AX
00e45   9efc         mov      CS, A
00e47   60           mov      A, X
00e48   9efd         mov      ES, A
00e4a   34d4fe       movw     DE, #0xfed4
00e4d   5206         mov      C, #0x6
00e4f   c0           pop      AX
00e50   b9           movw     [DE], AX
00e51   a5           incw     DE
00e52   a5           incw     DE
00e53   92           dec      C
00e54   dff9         bnz      0xe4f
00e56   c6           pop      HL
00e57   c4           pop      DE
00e58   c2           pop      BC
00e59   c0           pop      AX
00e5a   61fc         reti     
00e8c   c1           push     AX
00e8d   c3           push     BC
00e8e   c5           push     DE
00e8f   c7           push     HL
00e90   520c         mov      C, #0xc
00e92   92           dec      C
00e93   92           dec      C
00e94   69d4fe       movw     AX, [C+0xfed4]
00e97   c1           push     AX
00e98   dff8         bnz      0xe92
00e9a   8efd         mov      A, ES
00e9c   70           mov      X, A
00e9d   8efc         mov      A, CS
00e9f   c1           push     AX
00ea0   af6201       movw     AX, 0xf0162
00ea3   f1           clrb     A
00ea4   08           xch      A, X
00ea5   5c07         and      A, #0x7
00ea7   76           mov      L, A
00ea8   17           movw     AX, HL
00ea9   f1           clrb     A
00eaa   bf6601       movw     0xf0166, AX
00ead   17           movw     AX, HL
00eae   f1           clrb     A
00eaf   c1           push     AX
00eb0   8e46         mov      A, 0xfff46
00eb2   318e         shrw     AX, #0x8
00eb4   c1           push     AX
00eb5   f6           clrw     AX
00eb6   fcb64d01     call     0x14db6
00eba   1004         addw     SP, #0x4
00ebc   c0           pop      AX
00ebd   9efc         mov      CS, A
00ebf   60           mov      A, X
00ec0   9efd         mov      ES, A
00ec2   34d4fe       movw     DE, #0xfed4
00ec5   5206         mov      C, #0x6
00ec7   c0           pop      AX
00ec8   b9           movw     [DE], AX
00ec9   a5           incw     DE
00eca   a5           incw     DE
00ecb   92           dec      C
00ecc   dff9         bnz      0xec7
00ece   c6           pop      HL
00ecf   c4           pop      DE
00ed0   c2           pop      BC
00ed1   c0           pop      AX
00ed2   61fc         reti     
00ed4   c1           push     AX
00ed5   c3           push     BC
00ed6   c5           push     DE
00ed7   c7           push     HL
00ed8   520c         mov      C, #0xc
00eda   92           dec      C
00edb   92           dec      C
00edc   69d4fe       movw     AX, [C+0xfed4]
00edf   c1           push     AX
00ee0   dff8         bnz      0xeda
00ee2   8efd         mov      A, ES
00ee4   70           mov      X, A
00ee5   8efc         mov      A, CS
00ee7   c1           push     AX
00ee8   f6           clrw     AX
00ee9   c1           push     AX
00eea   8e4a         mov      A, 0xfff4a
00eec   318e         shrw     AX, #0x8
00eee   c1           push     AX
00eef   e6           onew     AX
00ef0   fcb64d01     call     0x14db6
00ef4   1004         addw     SP, #0x4
00ef6   c0           pop      AX
00ef7   9efc         mov      CS, A
00ef9   60           mov      A, X
00efa   9efd         mov      ES, A
00efc   34d4fe       movw     DE, #0xfed4
00eff   5206         mov      C, #0x6
00f01   c0           pop      AX
00f02   b9           movw     [DE], AX
00f03   a5           incw     DE
00f04   a5           incw     DE
00f05   92           dec      C
00f06   dff9         bnz      0xf01
00f08   c6           pop      HL
00f09   c4           pop      DE
00f0a   c2           pop      BC
00f0b   c0           pop      AX
00f0c   61fc         reti     
00f0e   c1           push     AX
00f0f   c5           push     DE
00f10   f6           clrw     AX
00f11   42d8c8       cmpw     AX, 0xfc8d8
00f14   dd0f         bz       0xf25
00f16   afd6c8       movw     AX, 0xfc8d6
00f19   a2d6c8       incw     0xfc8d6
00f1c   14           movw     DE, AX
00f1d   89           mov      A, [DE]
00f1e   9e44         mov      0xfff44, A
00f20   b2d8c8       decw     0xfc8d8
00f23   ef03         br       0xf28
00f25   f5dac8       clrb     0xfc8da
00f28   c4           pop      DE
00f29   c0           pop      AX
00f2a   61fc         reti     
00f2c   c1           push     AX
00f2d   c5           push     DE
00f2e   f6           clrw     AX
00f2f   421ec9       cmpw     AX, 0xfc91e
00f32   dd15         bz       0xf49
00f34   717ae5       set1     0xfffe5.7
00f37   af1cc9       movw     AX, 0xfc91c
00f3a   a21cc9       incw     0xfc91c
00f3d   14           movw     DE, AX
00f3e   89           mov      A, [DE]
00f3f   9e48         mov      0xfff48, A
00f41   b21ec9       decw     0xfc91e
00f44   717be5       clr1     0xfffe5.7
00f47   ef03         br       0xf4c
00f49   f520c9       clrb     0xfc920
00f4c   c4           pop      DE
00f4d   c0           pop      AX
00f4e   61fc         reti     
00f50   c1           push     AX
00f51   c7           push     HL
00f52   2004         subw     SP, #0x4
00f54   fbf8ff       movw     HL, SP
00f57   ae4a         movw     AX, 0xfff4a
00f59   bc02         movw     [HL+0x2], AX
00f5b   af4602       movw     AX, 0xf0246
00f5e   f1           clrb     A
00f5f   08           xch      A, X
00f60   5c07         and      A, #0x7
00f62   9c01         mov      [HL+0x1], A
00f64   af4802       movw     AX, 0xf0248
00f67   08           xch      A, X
00f68   6c07         or       A, #0x7
00f6a   08           xch      A, X
00f6b   bf4802       movw     0xf0248, AX
00f6e   1004         addw     SP, #0x4
00f70   c6           pop      HL
00f71   c0           pop      AX
00f72   61fc         reti     
00f74   c1           push     AX
00f75   c3           push     BC
00f76   c5           push     DE
00f77   c7           push     HL
00f78   520c         mov      C, #0xc
00f7a   92           dec      C
00f7b   92           dec      C
00f7c   69d4fe       movw     AX, [C+0xfed4]
00f7f   c1           push     AX
00f80   dff8         bnz      0xf7a
00f82   8efd         mov      A, ES
00f84   70           mov      X, A
00f85   8efc         mov      A, CS
00f87   c1           push     AX
00f88   200e         subw     SP, #0xe
00f8a   fbf8ff       movw     HL, SP
00f8d   aff6e8       movw     AX, 0xfe8f6
00f90   08           xch      A, X
00f91   5cf8         and      A, #0xf8
00f93   08           xch      A, X
00f94   bc0c         movw     [HL+0xc], AX
00f96   cc0a01       mov      [HL+0xa], #0x1
00f99   717afa       set1     PSW.7
00f9c   8ffce8       mov      A, 0xfe8fc
00f9f   d1           cmp0     A
00fa0   dd36         bz       0xfd8
00fa2   51c0         mov      A, #0xc0
00fa4   5b09         and      A, 0xfff09
00fa6   72           mov      C, A
00fa7   e1           oneb     A
00fa8   5b0a         and      A, 0xfff0a
00faa   616a         or       A, C
00fac   318e         shrw     AX, #0x8
00fae   bc08         movw     [HL+0x8], AX
00fb0   9c0b         mov      [HL+0xb], A
00fb2   8c0b         mov      A, [HL+0xb]
00fb4   4c0d         cmp      A, #0xd
00fb6   de20         bnc      0xfd8
00fb8   51c0         mov      A, #0xc0
00fba   5b09         and      A, 0xfff09
00fbc   72           mov      C, A
00fbd   e1           oneb     A
00fbe   5b0a         and      A, 0xfff0a
00fc0   616a         or       A, C
00fc2   318e         shrw     AX, #0x8
00fc4   bc06         movw     [HL+0x6], AX
00fc6   ac08         movw     AX, [HL+0x8]
00fc8   614906       cmpw     AX, [HL+0x6]
00fcb   dd06         bz       0xfd3
00fcd   cc0a00       mov      [HL+0xa], #0x0
00fd0   cc0b14       mov      [HL+0xb], #0x14
00fd3   61590b       inc      [HL+0xb]
00fd6   efda         br       0xfb2
00fd8   ac08         movw     AX, [HL+0x8]
00fda   bf06e9       movw     0xfe906, AX
00fdd   8c0a         mov      A, [HL+0xa]
00fdf   d1           cmp0     A
00fe0   61f8         sknz     
00fe2   edc511       br       0x11c5
00fe5   8ffce8       mov      A, 0xfe8fc
00fe8   320002       movw     BC, #0x200
00feb   f0           clrb     X
00fec   d1           cmp0     A
00fed   dd53         bz       0x1042
00fef   91           dec      A
00ff0   dd60         bz       0x1052
00ff2   91           dec      A
00ff3   61f8         sknz     
00ff5   ed8710       br       0x1087
00ff8   91           dec      A
00ff9   61f8         sknz     
00ffb   ed0311       br       0x1103
00ffe   91           dec      A
00fff   23           subw     AX, BC
01000   61d8         sknc     
01002   edbe11       br       0x11be
01005   d1           cmp0     A
01006   61f8         sknz     
01008   ed0311       br       0x1103
0100b   91           dec      A
0100c   23           subw     AX, BC
0100d   61d8         sknc     
0100f   edbe11       br       0x11be
01012   d1           cmp0     A
01013   61f8         sknz     
01015   ed0311       br       0x1103
01018   91           dec      A
01019   23           subw     AX, BC
0101a   61d8         sknc     
0101c   edbe11       br       0x11be
0101f   d1           cmp0     A
01020   61f8         sknz     
01022   ed0311       br       0x1103
01025   91           dec      A
01026   23           subw     AX, BC
01027   61d8         sknc     
01029   edbe11       br       0x11be
0102c   d1           cmp0     A
0102d   61f8         sknz     
0102f   ed0311       br       0x1103
01032   91           dec      A
01033   23           subw     AX, BC
01034   61d8         sknc     
01036   edbe11       br       0x11be
01039   d1           cmp0     A
0103a   61f8         sknz     
0103c   ed0311       br       0x1103
0103f   edc511       br       0x11c5
01042   711b2a       clr1     0xfff2a.1
01045   71120a       set1     0xfff0a.1
01048   8ffce8       mov      A, 0xfe8fc
0104b   81           inc      A
0104c   9ffce8       mov      0xfe8fc, A
0104f   edc511       br       0x11c5
01052   51c0         mov      A, #0xc0
01054   5f06e9       and      A, 0xfe906
01057   318e         shrw     AX, #0x8
01059   313e         shrw     AX, #0x3
0105b   bffee8       movw     0xfe8fe, AX
0105e   e1           oneb     A
0105f   5f06e9       and      A, 0xfe906
01062   318e         shrw     AX, #0x8
01064   315d         shlw     AX, #0x5
01066   6fffe8       or       A, 0xfe8ff
01069   08           xch      A, X
0106a   6ffee8       or       A, 0xfe8fe
0106d   08           xch      A, X
0106e   bffee8       movw     0xfe8fe, AX
01071   71130a       clr1     0xfff0a.1
01074   711a2a       set1     0xfff2a.1
01077   712b2a       clr1     0xfff2a.2
0107a   71220a       set1     0xfff0a.2
0107d   8ffce8       mov      A, 0xfe8fc
01080   81           inc      A
01081   9ffce8       mov      0xfe8fc, A
01084   edc511       br       0x11c5
01087   51c0         mov      A, #0xc0
01089   5f06e9       and      A, 0xfe906
0108c   318e         shrw     AX, #0x8
0108e   6fffe8       or       A, 0xfe8ff
01091   08           xch      A, X
01092   6ffee8       or       A, 0xfe8fe
01095   08           xch      A, X
01096   bffee8       movw     0xfe8fe, AX
01099   e1           oneb     A
0109a   5f06e9       and      A, 0xfe906
0109d   318e         shrw     AX, #0x8
0109f   318d         shlw     AX, #0x8
010a1   6fffe8       or       A, 0xfe8ff
010a4   08           xch      A, X
010a5   6ffee8       or       A, 0xfe8fe
010a8   08           xch      A, X
010a9   bffee8       movw     0xfe8fe, AX
010ac   71230a       clr1     0xfff0a.2
010af   712a2a       set1     0xfff2a.2
010b2   713b2a       clr1     0xfff2a.3
010b5   71320a       set1     0xfff0a.3
010b8   affee8       movw     AX, 0xfe8fe
010bb   4200e9       cmpw     AX, 0xfe900
010be   df15         bnz      0x10d5
010c0   aff6e8       movw     AX, 0xfe8f6
010c3   5cfe         and      A, #0xfe
010c5   f0           clrb     X
010c6   bc0c         movw     [HL+0xc], AX
010c8   affee8       movw     AX, 0xfe8fe
010cb   6e0d         or       A, [HL+0xd]
010cd   08           xch      A, X
010ce   6e0c         or       A, [HL+0xc]
010d0   08           xch      A, X
010d1   bc0c         movw     [HL+0xc], AX
010d3   ef24         br       0x10f9
010d5   f6           clrw     AX
010d6   42fee8       cmpw     AX, 0xfe8fe
010d9   df18         bnz      0x10f3
010db   4200e9       cmpw     AX, 0xfe900
010de   dd13         bz       0x10f3
010e0   aff6e8       movw     AX, 0xfe8f6
010e3   5cfe         and      A, #0xfe
010e5   f0           clrb     X
010e6   bc0c         movw     [HL+0xc], AX
010e8   affee8       movw     AX, 0xfe8fe
010eb   6e0d         or       A, [HL+0xd]
010ed   08           xch      A, X
010ee   6e0c         or       A, [HL+0xc]
010f0   08           xch      A, X
010f1   bc0c         movw     [HL+0xc], AX
010f3   affee8       movw     AX, 0xfe8fe
010f6   bf00e9       movw     0xfe900, AX
010f9   8ffce8       mov      A, 0xfe8fc
010fc   81           inc      A
010fd   9ffce8       mov      0xfe8fc, A
01100   edc511       br       0x11c5
01103   51c0         mov      A, #0xc0
01105   5b09         and      A, 0xfff09
01107   318e         shrw     AX, #0x8
01109   316e         shrw     AX, #0x6
0110b   12           movw     BC, AX
0110c   e1           oneb     A
0110d   5b0a         and      A, 0xfff0a
0110f   318e         shrw     AX, #0x8
01111   312d         shlw     AX, #0x2
01113   616b         or       A, B
01115   08           xch      A, X
01116   616a         or       A, C
01118   08           xch      A, X
01119   bc04         movw     [HL+0x4], AX
0111b   8c0c         mov      A, [HL+0xc]
0111d   70           mov      X, A
0111e   8c0d         mov      A, [HL+0xd]
01120   5cf9         and      A, #0xf9
01122   bc0c         movw     [HL+0xc], AX
01124   8ffde8       mov      A, 0xfe8fd
01127   5c07         and      A, #0x7
01129   318e         shrw     AX, #0x8
0112b   614904       cmpw     AX, [HL+0x4]
0112e   dd6d         bz       0x119d
01130   e6           onew     AX
01131   614904       cmpw     AX, [HL+0x4]
01134   dd0d         bz       0x1143
01136   a1           incw     AX
01137   614904       cmpw     AX, [HL+0x4]
0113a   dd07         bz       0x1143
0113c   a1           incw     AX
0113d   a1           incw     AX
0113e   614904       cmpw     AX, [HL+0x4]
01141   df5a         bnz      0x119d
01143   8ffde8       mov      A, 0xfe8fd
01146   5c07         and      A, #0x7
01148   d1           cmp0     A
01149   dd43         bz       0x118e
0114b   8ffde8       mov      A, 0xfe8fd
0114e   5c07         and      A, #0x7
01150   91           dec      A
01151   df07         bnz      0x115a
01153   e6           onew     AX
01154   a1           incw     AX
01155   614904       cmpw     AX, [HL+0x4]
01158   dd20         bz       0x117a
0115a   8ffde8       mov      A, 0xfe8fd
0115d   5c07         and      A, #0x7
0115f   4c02         cmp      A, #0x2
01161   df08         bnz      0x116b
01163   300400       movw     AX, #0x4
01166   614904       cmpw     AX, [HL+0x4]
01169   dd0f         bz       0x117a
0116b   8ffde8       mov      A, 0xfe8fd
0116e   5c07         and      A, #0x7
01170   4c04         cmp      A, #0x4
01172   df11         bnz      0x1185
01174   e6           onew     AX
01175   614904       cmpw     AX, [HL+0x4]
01178   df0b         bnz      0x1185
0117a   8c0c         mov      A, [HL+0xc]
0117c   70           mov      X, A
0117d   8c0d         mov      A, [HL+0xd]
0117f   6c02         or       A, #0x2
01181   bc0c         movw     [HL+0xc], AX
01183   ef09         br       0x118e
01185   8c0c         mov      A, [HL+0xc]
01187   70           mov      X, A
01188   8c0d         mov      A, [HL+0xd]
0118a   6c04         or       A, #0x4
0118c   bc0c         movw     [HL+0xc], AX
0118e   8c04         mov      A, [HL+0x4]
01190   5c07         and      A, #0x7
01192   70           mov      X, A
01193   8ffde8       mov      A, 0xfe8fd
01196   5cf8         and      A, #0xf8
01198   6168         or       A, X
0119a   9ffde8       mov      0xfe8fd, A
0119d   8ffce8       mov      A, 0xfe8fc
011a0   4c12         cmp      A, #0x12
011a2   df11         bnz      0x11b5
011a4   e5fce8       oneb     0xfe8fc
011a7   71330a       clr1     0xfff0a.3
011aa   713a2a       set1     0xfff2a.3
011ad   711b2a       clr1     0xfff2a.1
011b0   71120a       set1     0xfff0a.1
011b3   ef10         br       0x11c5
011b5   8ffce8       mov      A, 0xfe8fc
011b8   81           inc      A
011b9   9ffce8       mov      0xfe8fc, A
011bc   ef07         br       0x11c5
011be   8ffce8       mov      A, 0xfe8fc
011c1   81           inc      A
011c2   9ffce8       mov      0xfe8fc, A
011c5   cc0100       mov      [HL+0x1], #0x0
011c8   eb00e4       movw     DE, 0xfe400
011cb   8a0a         mov      A, [DE+0xa]
011cd   9efc         mov      CS, A
011cf   aa08         movw     AX, [DE+0x8]
011d1   61ca         call     AX
011d3   62           mov      A, C
011d4   4c03         cmp      A, #0x3
011d6   61e8         skz      
011d8   ed8512       br       0x1285
011db   af12e4       movw     AX, 0xfe412
011de   e7           onew     BC
011df   c3           push     BC
011e0   12           movw     BC, AX
011e1   17           movw     AX, HL
011e2   a1           incw     AX
011e3   c1           push     AX
011e4   491600       mov      A, [BC+0x16]
011e7   9dd4         mov      0xffed4, A
011e9   791400       movw     AX, [BC+0x14]
011ec   c1           push     AX
011ed   8dd4         mov      A, 0xffed4
011ef   9dd6         mov      0xffed6, A
011f1   c0           pop      AX
011f2   14           movw     DE, AX
011f3   304100       movw     AX, #0x41
011f6   f7           clrw     BC
011f7   c1           push     AX
011f8   8dd6         mov      A, 0xffed6
011fa   9efc         mov      CS, A
011fc   c0           pop      AX
011fd   61ea         call     DE
011ff   1004         addw     SP, #0x4
01201   8c01         mov      A, [HL+0x1]
01203   d1           cmp0     A
01204   df20         bnz      0x1226
01206   8d07         mov      A, 0xfff07
01208   7cff         xor      A, #0xff
0120a   5c60         and      A, #0x60
0120c   315a         shr      A, #0x5
0120e   72           mov      C, A
0120f   8d03         mov      A, 0xfff03
01211   7cff         xor      A, #0xff
01213   5c04         and      A, #0x4
01215   6162         or       C, A
01217   62           mov      A, C
01218   5c07         and      A, #0x7
0121a   72           mov      C, A
0121b   8c0c         mov      A, [HL+0xc]
0121d   616a         or       A, C
0121f   70           mov      X, A
01220   8c0d         mov      A, [HL+0xd]
01222   bc0c         movw     [HL+0xc], AX
01224   ef5f         br       0x1285
01226   f1           clrb     A
01227   716407       mov1     CY, 0xfff07.6
0122a   61dc         rolc     A, #0x1
0122c   9c05         mov      [HL+0x5], A
0122e   f1           clrb     A
0122f   715407       mov1     CY, 0xfff07.5
01232   61dc         rolc     A, #0x1
01234   9c04         mov      [HL+0x4], A
01236   3119         shl      A, #0x1
01238   6e05         or       A, [HL+0x5]
0123a   9c03         mov      [HL+0x3], A
0123c   8c04         mov      A, [HL+0x4]
0123e   d1           cmp0     A
0123f   df06         bnz      0x1247
01241   8c03         mov      A, [HL+0x3]
01243   7c01         xor      A, #0x1
01245   9c03         mov      [HL+0x3], A
01247   8c03         mov      A, [HL+0x3]
01249   2f08e9       sub      A, 0xfe908
0124c   5c03         and      A, #0x3
0124e   9c02         mov      [HL+0x2], A
01250   91           dec      A
01251   df0b         bnz      0x125e
01253   8c0c         mov      A, [HL+0xc]
01255   6c01         or       A, #0x1
01257   70           mov      X, A
01258   8c0d         mov      A, [HL+0xd]
0125a   bc0c         movw     [HL+0xc], AX
0125c   ef0f         br       0x126d
0125e   8c02         mov      A, [HL+0x2]
01260   4c03         cmp      A, #0x3
01262   df09         bnz      0x126d
01264   8c0c         mov      A, [HL+0xc]
01266   6c02         or       A, #0x2
01268   70           mov      X, A
01269   8c0d         mov      A, [HL+0xd]
0126b   bc0c         movw     [HL+0xc], AX
0126d   8c03         mov      A, [HL+0x3]
0126f   9f08e9       mov      0xfe908, A
01272   31240303     bf       0xfff03.2, 0x1279
01276   f1           clrb     A
01277   ef02         br       0x127b
01279   5104         mov      A, #0x4
0127b   318f         sarw     AX, #0x8
0127d   6e0d         or       A, [HL+0xd]
0127f   08           xch      A, X
01280   6e0c         or       A, [HL+0xc]
01282   08           xch      A, X
01283   bc0c         movw     [HL+0xc], AX
01285   aff8e8       movw     AX, 0xfe8f8
01288   61490c       cmpw     AX, [HL+0xc]
0128b   dd53         bz       0x12e0
0128d   ac0c         movw     AX, [HL+0xc]
0128f   42f6e8       cmpw     AX, 0xfe8f6
01292   df47         bnz      0x12db
01294   aff8e8       movw     AX, 0xfe8f8
01297   7e0d         xor      A, [HL+0xd]
01299   08           xch      A, X
0129a   7e0c         xor      A, [HL+0xc]
0129c   08           xch      A, X
0129d   bffae8       movw     0xfe8fa, AX
012a0   aff8e8       movw     AX, 0xfe8f8
012a3   f1           clrb     A
012a4   08           xch      A, X
012a5   5c10         and      A, #0x10
012a7   08           xch      A, X
012a8   6168         or       A, X
012aa   df0c         bnz      0x12b8
012ac   aff8e8       movw     AX, 0xfe8f8
012af   f1           clrb     A
012b0   08           xch      A, X
012b1   5c08         and      A, #0x8
012b3   08           xch      A, X
012b4   6168         or       A, X
012b6   dd1c         bz       0x12d4
012b8   5118         mov      A, #0x18
012ba   5e0c         and      A, [HL+0xc]
012bc   318e         shrw     AX, #0x8
012be   441800       cmpw     AX, #0x18
012c1   df11         bnz      0x12d4
012c3   5018         mov      X, #0x18
012c5   42f8e8       cmpw     AX, 0xfe8f8
012c8   dd0a         bz       0x12d4
012ca   affae8       movw     AX, 0xfe8fa
012cd   08           xch      A, X
012ce   6c18         or       A, #0x18
012d0   08           xch      A, X
012d1   bffae8       movw     0xfe8fa, AX
012d4   ac0c         movw     AX, [HL+0xc]
012d6   bff8e8       movw     0xfe8f8, AX
012d9   ef05         br       0x12e0
012db   ac0c         movw     AX, [HL+0xc]
012dd   bff6e8       movw     0xfe8f6, AX
012e0   100e         addw     SP, #0xe
012e2   c0           pop      AX
012e3   9efc         mov      CS, A
012e5   60           mov      A, X
012e6   9efd         mov      ES, A
012e8   34d4fe       movw     DE, #0xfed4
012eb   5206         mov      C, #0x6
012ed   c0           pop      AX
012ee   b9           movw     [DE], AX
012ef   a5           incw     DE
012f0   a5           incw     DE
012f1   92           dec      C
012f2   dff9         bnz      0x12ed
012f4   c6           pop      HL
012f5   c4           pop      DE
012f6   c2           pop      BC
012f7   c0           pop      AX
012f8   61fc         reti     
012fa   c1           push     AX
012fb   af3201       movw     AX, 0xf0132
012fe   f1           clrb     A
012ff   08           xch      A, X
01300   5c02         and      A, #0x2
01302   08           xch      A, X
01303   440200       cmpw     AX, #0x2
01306   df08         bnz      0x1310
01308   e6           onew     AX
01309   a1           incw     AX
0130a   bf3601       movw     0xf0136, AX
0130d   e576e9       oneb     0xfe976
01310   e577e9       oneb     0xfe977
01313   c0           pop      AX
01314   61fc         reti     
075d0   ceabac       mov      0xfffab, #0xac
075d3   d7           ret      
075d4   c7           push     HL
075d5   2004         subw     SP, #0x4
075d7   fbf8ff       movw     HL, SP
075da   f400         clrb     0xfff00
075dc   f401         clrb     0xfff01
075de   f403         clrb     0xfff03
075e0   f404         clrb     0xfff04
075e2   f405         clrb     0xfff05
075e4   f406         clrb     0xfff06
075e6   f407         clrb     0xfff07
075e8   f408         clrb     0xfff08
075ea   f409         clrb     0xfff09
075ec   f40a         clrb     0xfff0a
075ee   f40c         clrb     0xfff0c
075f0   f40d         clrb     0xfff0d
075f2   f40e         clrb     0xfff0e
075f4   f40f         clrb     0xfff0f
075f6   ce20ff       mov      0xfff20, #0xff
075f9   ce21ff       mov      0xfff21, #0xff
075fc   ce23ff       mov      0xfff23, #0xff
075ff   ce24ff       mov      0xfff24, #0xff
07602   ce25fd       mov      0xfff25, #0xfd
07605   ce26ff       mov      0xfff26, #0xff
07608   ce27ff       mov      0xfff27, #0xff
0760b   ce28ff       mov      0xfff28, #0xff
0760e   ce29ff       mov      0xfff29, #0xff
07611   ce2aff       mov      0xfff2a, #0xff
07614   ce2cff       mov      0xfff2c, #0xff
07617   ce2eff       mov      0xfff2e, #0xff
0761a   ce2fff       mov      0xfff2f, #0xff
0761d   71403f00     set1     0xf003f.4
07621   714a2f       set1     0xfff2f.4
07624   717306       clr1     0xfff06.7
07627   717b26       clr1     0xfff26.7
0762a   71003e00     set1     0xf003e.0
0762e   710a2e       set1     0xfff2e.0
07631   71603f00     set1     0xf003f.6
07635   716a2f       set1     0xfff2f.6
07638   717b2f       clr1     0xfff2f.7
0763b   71730f       clr1     0xfff0f.7
0763e   710b20       clr1     0xfff20.0
07641   710300       clr1     0xfff00.0
07644   00           nop      
07645   00           nop      
07646   00           nop      
07647   00           nop      
07648   00           nop      
07649   31440f03     bf       0xfff0f.4, 0x7650
0764d   ee8900       br       0x76d9
07650   cea040       mov      0xfffa0, #0x40
07653   cea307       mov      0xfffa3, #0x7
07656   8f7000       mov      A, 0xf0070
07659   6c01         or       A, #0x1
0765b   9f7000       mov      0xf0070, A
0765e   717ba1       clr1     0xfffa1.7
07661   cc01ff       mov      [HL+0x1], #0xff
07664   8ea2         mov      A, 0xfffa2
07666   9b           mov      [HL], A
07667   5e01         and      A, [HL+0x1]
07669   9b           mov      [HL], A
0766a   8b           mov      A, [HL]
0766b   4e01         cmp      A, [HL+0x1]
0766d   dff5         bnz      0x7664
0766f   717bfa       clr1     PSW.7
07672   cff30005     mov      0xf00f3, #0x5
07676   00           nop      
07677   00           nop      
07678   717afa       set1     PSW.7
0767b   714aa4       set1     0xfffa4.4
0767e   8f7000       mov      A, 0xf0070
07681   6c02         or       A, #0x2
07683   9f7000       mov      0xf0070, A
07686   cff70090     mov      0xf00f7, #0x90
0768a   7100f700     set1     0xf00f7.0
0768e   f6           clrw     AX
0768f   bc02         movw     [HL+0x2], AX
07691   ac02         movw     AX, [HL+0x2]
07693   446109       cmpw     AX, #0x961
07696   de06         bnc      0x769e
07698   00           nop      
07699   617902       incw     [HL+0x2]
0769c   eff3         br       0x7691
0769e   c7           push     HL
0769f   36f600       movw     HL, #0xf6
076a2   71f4         mov1     CY, [HL].7
076a4   c6           pop      HL
076a5   def7         bnc      0x769e
076a7   7120f700     set1     0xf00f7.2
076ab   c7           push     HL
076ac   36f600       movw     HL, #0xf6
076af   71b4         mov1     CY, [HL].3
076b1   c6           pop      HL
076b2   def7         bnc      0x76ab
076b4   8f7000       mov      A, 0xf0070
076b7   5cfd         and      A, #0xfd
076b9   9f7000       mov      0xf0070, A
076bc   716aa1       set1     0xfffa1.6
076bf   716ba4       clr1     0xfffa4.6
076c2   8ea4         mov      A, 0xfffa4
076c4   5cf8         and      A, #0xf8
076c6   9ea4         mov      0xfffa4, A
076c8   8ea4         mov      A, 0xfffa4
076ca   9ea4         mov      0xfffa4, A
076cc   710ba1       clr1     0xfffa1.0
076cf   8f7000       mov      A, 0xf0070
076d2   5cfe         and      A, #0xfe
076d4   9f7000       mov      0xf0070, A
076d7   ef75         br       0x774e
076d9   f5a0ff       clrb     0xfffa0
076dc   8f7000       mov      A, 0xf0070
076df   6c01         or       A, #0x1
076e1   9f7000       mov      0xf0070, A
076e4   717aa1       set1     0xfffa1.7
076e7   717bfa       clr1     PSW.7
076ea   e5f300       oneb     0xf00f3
076ed   00           nop      
076ee   00           nop      
076ef   717afa       set1     PSW.7
076f2   714ba4       clr1     0xfffa4.4
076f5   8f7000       mov      A, 0xf0070
076f8   6c02         or       A, #0x2
076fa   9f7000       mov      0xf0070, A
076fd   cff70050     mov      0xf00f7, #0x50
07701   7100f700     set1     0xf00f7.0
07705   f6           clrw     AX
07706   bc02         movw     [HL+0x2], AX
07708   ac02         movw     AX, [HL+0x2]
0770a   446109       cmpw     AX, #0x961
0770d   de06         bnc      0x7715
0770f   00           nop      
07710   617902       incw     [HL+0x2]
07713   eff3         br       0x7708
07715   c7           push     HL
07716   36f600       movw     HL, #0xf6
07719   71f4         mov1     CY, [HL].7
0771b   c6           pop      HL
0771c   def7         bnc      0x7715
0771e   7120f700     set1     0xf00f7.2
07722   c7           push     HL
07723   36f600       movw     HL, #0xf6
07726   71b4         mov1     CY, [HL].3
07728   c6           pop      HL
07729   def7         bnc      0x7722
0772b   8f7000       mov      A, 0xf0070
0772e   5cfd         and      A, #0xfd
07730   9f7000       mov      0xf0070, A
07733   716aa1       set1     0xfffa1.6
07736   716ba4       clr1     0xfffa4.6
07739   8ea4         mov      A, 0xfffa4
0773b   5cf8         and      A, #0xf8
0773d   9ea4         mov      0xfffa4, A
0773f   8ea4         mov      A, 0xfffa4
07741   9ea4         mov      0xfffa4, A
07743   710ba1       clr1     0xfffa1.0
07746   8f7000       mov      A, 0xf0070
07749   5cfe         and      A, #0xfe
0774b   9f7000       mov      0xf0070, A
0774e   71483f00     clr1     0xf003f.4
07752   717a26       set1     0xfff26.7
07755   f5d4e3       clrb     0xfe3d4
07758   31020e04     bt       0xfff0e.0, 0x7760
0775c   7140d4e3     set1     0xfe3d4.4
07760   31620f04     bt       0xfff0f.6, 0x7768
07764   7100d4e3     set1     0xfe3d4.0
07768   71083e00     clr1     0xf003e.0
0776c   71683f00     clr1     0xf003f.6
07770   717a2f       set1     0xfff2f.7
07773   710a20       set1     0xfff20.0
07776   7120f000     set1     0xf00f0.2
0777a   3010f8       movw     AX, #0xf810
0777d   bf3602       movw     0xf0236, AX
07780   f6           clrw     AX
07781   90           dec      X
07782   bf3402       movw     0xf0234, AX
07785   715ad6       set1     0xfffd6.5
07788   715bd2       clr1     0xfffd2.5
0778b   715bde       clr1     0xfffde.5
0778e   715bda       clr1     0xfffda.5
07791   e6           onew     AX
07792   bf1002       movw     0xf0210, AX
07795   cb90bf5d     movw     0xfff90, #0x5dbf
07799   af3e02       movw     AX, 0xf023e
0779c   08           xch      A, X
0779d   5cfe         and      A, #0xfe
0779f   08           xch      A, X
077a0   bf3e02       movw     0xf023e, AX
077a3   af3c02       movw     AX, 0xf023c
077a6   08           xch      A, X
077a7   5cfe         and      A, #0xfe
077a9   08           xch      A, X
077aa   bf3c02       movw     0xf023c, AX
077ad   af3a02       movw     AX, 0xf023a
077b0   08           xch      A, X
077b1   5cfe         and      A, #0xfe
077b3   08           xch      A, X
077b4   bf3a02       movw     0xf023a, AX
077b7   715bd2       clr1     0xfffd2.5
077ba   715bd6       clr1     0xfffd6.5
077bd   af3202       movw     AX, 0xf0232
077c0   08           xch      A, X
077c1   6c01         or       A, #0x1
077c3   08           xch      A, X
077c4   bf3202       movw     0xf0232, AX
077c7   1004         addw     SP, #0x4
077c9   c6           pop      HL
077ca   717afa       set1     PSW.7
077cd   d7           ret      
077ce   717bfa       clr1     PSW.7
077d1   ce20ff       mov      0xfff20, #0xff
077d4   ce21ff       mov      0xfff21, #0xff
077d7   ce23ff       mov      0xfff23, #0xff
077da   ce24ff       mov      0xfff24, #0xff
077dd   ce25fd       mov      0xfff25, #0xfd
077e0   ce26ff       mov      0xfff26, #0xff
077e3   ce27ff       mov      0xfff27, #0xff
077e6   ce28ff       mov      0xfff28, #0xff
077e9   ce29ff       mov      0xfff29, #0xff
077ec   ce2aff       mov      0xfff2a, #0xff
077ef   ce2cff       mov      0xfff2c, #0xff
077f2   ce2eff       mov      0xfff2e, #0xff
077f5   ce2ffb       mov      0xfff2f, #0xfb
077f8   710b2e       clr1     0xfff2e.0
077fb   717b2f       clr1     0xfff2f.7
077fe   716b2f       clr1     0xfff2f.6
07801   710b20       clr1     0xfff20.0
07804   714b2f       clr1     0xfff2f.4
07807   717b26       clr1     0xfff26.7
0780a   712b21       clr1     0xfff21.2
0780d   717b2a       clr1     0xfff2a.7
07810   716b2a       clr1     0xfff2a.6
07813   710b28       clr1     0xfff28.0
07816   711b29       clr1     0xfff29.1
07819   717b24       clr1     0xfff24.7
0781c   714b24       clr1     0xfff24.4
0781f   f400         clrb     0xfff00
07821   f401         clrb     0xfff01
07823   f403         clrb     0xfff03
07825   f404         clrb     0xfff04
07827   f405         clrb     0xfff05
07829   f406         clrb     0xfff06
0782b   f407         clrb     0xfff07
0782d   f408         clrb     0xfff08
0782f   f409         clrb     0xfff09
07831   f40a         clrb     0xfff0a
07833   f40c         clrb     0xfff0c
07835   f40d         clrb     0xfff0d
07837   f40e         clrb     0xfff0e
07839   f40f         clrb     0xfff0f
0783b   af3402       movw     AX, 0xf0234
0783e   08           xch      A, X
0783f   6c01         or       A, #0x1
07841   08           xch      A, X
07842   bf3402       movw     0xf0234, AX
07845   715ad6       set1     0xfffd6.5
07848   715bd2       clr1     0xfffd2.5
0784b   af4401       movw     AX, 0xf0144
0784e   08           xch      A, X
0784f   6c02         or       A, #0x2
07851   08           xch      A, X
07852   bf4401       movw     0xf0144, AX
07855   716ae7       set1     0xfffe7.6
07858   7148f000     clr1     0xf00f0.4
0785c   af7401       movw     AX, 0xf0174
0785f   08           xch      A, X
07860   6c03         or       A, #0x3
07862   08           xch      A, X
07863   bf7401       movw     0xf0174, AX
07866   af7a01       movw     AX, 0xf017a
07869   08           xch      A, X
0786a   5cfe         and      A, #0xfe
0786c   08           xch      A, X
0786d   bf7a01       movw     0xf017a, AX
07870   717ad5       set1     0xfffd5.7
07873   717bd1       clr1     0xfffd1.7
07876   716ad5       set1     0xfffd5.6
07879   716bd1       clr1     0xfffd1.6
0787c   7138f100     clr1     0xf00f1.3
07880   f6           clrw     AX
07881   90           dec      X
07882   bff401       movw     0xf01f4, AX
07885   f6           clrw     AX
07886   bffa01       movw     0xf01fa, AX
07889   7118f000     clr1     0xf00f0.1
0788d   717b30       clr1     0xfff30.7
07890   710ae7       set1     0xfffe7.0
07893   710be3       clr1     0xfffe3.0
07896   7178f000     clr1     0xf00f0.7
0789a   f538ff       clrb     0xfff38
0789d   f539ff       clrb     0xfff39
078a0   f53aff       clrb     0xfff3a
078a3   f53bff       clrb     0xfff3b
078a6   714ae4       set1     0xfffe4.4
078a9   714be0       clr1     0xfffe0.4
078ac   716ae4       set1     0xfffe4.6
078af   716be0       clr1     0xfffe0.6
078b2   714aec       set1     0xfffec.4
078b5   714ae8       set1     0xfffe8.4
078b8   716aec       set1     0xfffec.6
078bb   716ae8       set1     0xfffe8.6
078be   ce3914       mov      0xfff39, #0x14
078c1   8e36         mov      A, 0xfff36
078c3   5cfb         and      A, #0xfb
078c5   9e36         mov      0xfff36, A
078c7   714be0       clr1     0xfffe0.4
078ca   714be4       clr1     0xfffe4.4
078cd   716be0       clr1     0xfffe0.6
078d0   716be4       clr1     0xfffe4.6
078d3   714b26       clr1     0xfff26.4
078d6   715b26       clr1     0xfff26.5
078d9   714306       clr1     0xfff06.4
078dc   715306       clr1     0xfff06.5
078df   f5d5e3       clrb     0xfe3d5
078e2   717afa       set1     PSW.7
078e5   31020302     bt       0xfff03.0, 0x78eb
078e9   ef12         br       0x78fd
078eb   61fd         stop     
078fd   717bfa       clr1     PSW.7
07900   714ae4       set1     0xfffe4.4
07903   714be0       clr1     0xfffe0.4
07906   716ae4       set1     0xfffe4.6
07909   716be0       clr1     0xfffe0.6
0790c   715bd2       clr1     0xfffd2.5
0790f   715bd6       clr1     0xfffd6.5
07912   af3202       movw     AX, 0xf0232
07915   08           xch      A, X
07916   6c01         or       A, #0x1
07918   08           xch      A, X
07919   bf3202       movw     0xf0232, AX
0791c   717afa       set1     PSW.7
0791f   d7           ret      
07920   717bfa       clr1     PSW.7
07923   6a0404       or       0xfff04, #0x4
07926   6a0603       or       0xfff06, #0x3
07929   6a0f04       or       0xfff0f, #0x4
0792c   8e20         mov      A, 0xfff20
0792e   5cf5         and      A, #0xf5
07930   9e20         mov      0xfff20, A
07932   8e21         mov      A, 0xfff21
07934   5c1c         and      A, #0x1c
07936   9e21         mov      0xfff21, A
07938   8e23         mov      A, 0xfff23
0793a   5cfd         and      A, #0xfd
0793c   9e23         mov      0xfff23, A
0793e   8e24         mov      A, 0xfff24
07940   5cfb         and      A, #0xfb
07942   9e24         mov      0xfff24, A
07944   8e25         mov      A, 0xfff25
07946   5cec         and      A, #0xec
07948   9e25         mov      0xfff25, A
0794a   8e26         mov      A, 0xfff26
0794c   5c88         and      A, #0x88
0794e   9e26         mov      0xfff26, A
07950   8e27         mov      A, 0xfff27
07952   5cee         and      A, #0xee
07954   9e27         mov      0xfff27, A
07956   8e2a         mov      A, 0xfff2a
07958   5cef         and      A, #0xef
0795a   9e2a         mov      0xfff2a, A
0795c   8e2c         mov      A, 0xfff2c
0795e   5cbf         and      A, #0xbf
07960   9e2c         mov      0xfff2c, A
07962   8e2f         mov      A, 0xfff2f
07964   5cdb         and      A, #0xdb
07966   9e2f         mov      0xfff2f, A
07968   7140f000     set1     0xf00f0.4
0796c   00           nop      
0796d   00           nop      
0796e   00           nop      
0796f   00           nop      
07970   f6           clrw     AX
07971   bf4601       movw     0xf0146, AX
07974   af4401       movw     AX, 0xf0144
07977   08           xch      A, X
07978   6c02         or       A, #0x2
0797a   08           xch      A, X
0797b   bf4401       movw     0xf0144, AX
0797e   716ae7       set1     0xfffe7.6
07981   716be3       clr1     0xfffe3.6
07984   716aef       set1     0xfffef.6
07987   716aeb       set1     0xfffeb.6
0798a   300700       movw     AX, #0x7
0798d   bf3601       movw     0xf0136, AX
07990   5024         mov      X, #0x24
07992   bf3a01       movw     0xf013a, AX
07995   5017         mov      X, #0x17
07997   bf3e01       movw     0xf013e, AX
0799a   c916003a     movw     0xfff16, #0x3a00
0799e   af4801       movw     AX, 0xf0148
079a1   6c02         or       A, #0x2
079a3   08           xch      A, X
079a4   6c02         or       A, #0x2
079a6   08           xch      A, X
079a7   bf4801       movw     0xf0148, AX
079aa   8e3c         mov      A, 0xfff3c
079ac   6c20         or       A, #0x20
079ae   9e3c         mov      0xfff3c, A
079b0   7110f000     set1     0xf00f0.1
079b4   3040f5       movw     AX, #0xf540
079b7   bff601       movw     0xf01f6, AX
079ba   f6           clrw     AX
079bb   90           dec      X
079bc   bff401       movw     0xf01f4, AX
079bf   711ad5       set1     0xfffd5.1
079c2   711bd1       clr1     0xfffd1.1
079c5   712ad6       set1     0xfffd6.2
079c8   712bd2       clr1     0xfffd2.2
079cb   300108       movw     AX, #0x801
079ce   bfd001       movw     0xf01d0, AX
079d1   cb700004     movw     0xfff70, #0x400
079d5   300904       movw     AX, #0x409
079d8   bfda01       movw     0xf01da, AX
079db   f6           clrw     AX
079dc   be7a         movw     0xfff7a, AX
079de   affe01       movw     AX, 0xf01fe
079e1   08           xch      A, X
079e2   6c20         or       A, #0x20
079e4   08           xch      A, X
079e5   bffe01       movw     0xf01fe, AX
079e8   affc01       movw     AX, 0xf01fc
079eb   08           xch      A, X
079ec   5cdf         and      A, #0xdf
079ee   08           xch      A, X
079ef   bffc01       movw     0xf01fc, AX
079f2   aff801       movw     AX, 0xf01f8
079f5   08           xch      A, X
079f6   5cdf         and      A, #0xdf
079f8   08           xch      A, X
079f9   bff801       movw     0xf01f8, AX
079fc   affa01       movw     AX, 0xf01fa
079ff   08           xch      A, X
07a00   6c20         or       A, #0x20
07a02   08           xch      A, X
07a03   bffa01       movw     0xf01fa, AX
07a06   714ad6       set1     0xfffd6.4
07a09   714bd2       clr1     0xfffd2.4
07a0c   714ade       set1     0xfffde.4
07a0f   714ada       set1     0xfffda.4
07a12   304481       movw     AX, #0x8144
07a15   bfde01       movw     0xf01de, AX
07a18   8e3f         mov      A, 0xfff3f
07a1a   6c80         or       A, #0x80
07a1c   9e3f         mov      0xfff3f, A
07a1e   affe01       movw     AX, 0xf01fe
07a21   08           xch      A, X
07a22   5c7e         and      A, #0x7e
07a24   08           xch      A, X
07a25   bffe01       movw     0xf01fe, AX
07a28   affc01       movw     AX, 0xf01fc
07a2b   08           xch      A, X
07a2c   5c7e         and      A, #0x7e
07a2e   08           xch      A, X
07a2f   bffc01       movw     0xf01fc, AX
07a32   affa01       movw     AX, 0xf01fa
07a35   08           xch      A, X
07a36   5c7e         and      A, #0x7e
07a38   08           xch      A, X
07a39   bffa01       movw     0xf01fa, AX
07a3c   8e61         mov      A, 0xfff61
07a3e   5cdf         and      A, #0xdf
07a40   9e61         mov      0xfff61, A
07a42   714bd2       clr1     0xfffd2.4
07a45   714bd6       clr1     0xfffd6.4
07a48   aff201       movw     AX, 0xf01f2
07a4b   08           xch      A, X
07a4c   6ca1         or       A, #0xa1
07a4e   08           xch      A, X
07a4f   bff201       movw     0xf01f2, AX
07a52   7170f000     set1     0xf00f0.7
07a56   f530ff       clrb     0xfff30
07a59   710ae7       set1     0xfffe7.0
07a5c   710be3       clr1     0xfffe3.0
07a5f   710aef       set1     0xfffef.0
07a62   710aeb       set1     0xfffeb.0
07a65   cf17000e     mov      0xf0017, #0xe
07a69   ce3002       mov      0xfff30, #0x2
07a6c   f542ff       clrb     0xfff42
07a6f   ce310d       mov      0xfff31, #0xd
07a72   ce330b       mov      0xfff33, #0xb
07a75   8e30         mov      A, 0xfff30
07a77   6c70         or       A, #0x70
07a79   9e30         mov      0xfff30, A
07a7b   710be3       clr1     0xfffe3.0
07a7e   710ae7       set1     0xfffe7.0
07a81   717b30       clr1     0xfff30.7
07a84   717afa       set1     PSW.7
07a87   d7           ret      
07c2e   af6201       movw     AX, 0xf0162
07c31   f1           clrb     A
07c32   08           xch      A, X
07c33   5c07         and      A, #0x7
07c35   08           xch      A, X
07c36   e7           onew     BC
07c37   43           cmpw     AX, BC
07c38   61f8         sknz     
07c3a   717ad1       set1     0xfffd1.7
07c3d   d7           ret      
07c76   c7           push     HL
07c77   fcd47500     call     0x75d4
07c7b   fc49e300     call     0xe349
07c7f   fcde7e00     call     0x7ede
07c83   fcce7700     call     0x77ce
07c87   fc207900     call     0x7920
07c8b   eb00e4       movw     DE, 0xfe400
07c8e   8a02         mov      A, [DE+0x2]
07c90   9efc         mov      CS, A
07c92   a9           movw     AX, [DE]
07c93   16           movw     HL, AX
07c94   e6           onew     AX
07c95   61fa         call     HL
07c97   eb00e4       movw     DE, 0xfe400
07c9a   8a0a         mov      A, [DE+0xa]
07c9c   9efc         mov      CS, A
07c9e   aa08         movw     AX, [DE+0x8]
07ca0   61ca         call     AX
07ca2   d2           cmp0     C
07ca3   ddd6         bz       0x7c7b
07ca5   fcd07500     call     0x75d0
07ca9   fcf37e00     call     0x7ef3
07cad   fc2e7c00     call     0x7c2e
07cb1   efe4         br       0x7c97
07cb5   c7           push     HL
07cb6   16           movw     HL, AX
07cb7   5700         mov      H, #0x0
07cb9   67           mov      A, H
07cba   4c20         cmp      A, #0x20
07cbc   de18         bnc      0x7cd6
07cbe   500e         mov      X, #0xe
07cc0   d6           mulu     X
07cc1   12           movw     BC, AX
07cc2   4920e4       mov      A, [BC+0xe420]
07cc5   614e         cmp      A, L
07cc7   df0a         bnz      0x7cd3
07cc9   67           mov      A, H
07cca   500e         mov      X, #0xe
07ccc   d6           mulu     X
07ccd   0420e4       addw     AX, #0xe420
07cd0   12           movw     BC, AX
07cd1   ef04         br       0x7cd7
07cd3   87           inc      H
07cd4   efe3         br       0x7cb9
07cd6   f7           clrw     BC
07cd7   c6           pop      HL
07cd8   d7           ret      
07e1f   c7           push     HL
07e20   c1           push     AX
07e21   c1           push     AX
07e22   fbf8ff       movw     HL, SP
07e25   ac02         movw     AX, [HL+0x2]
07e27   14           movw     DE, AX
07e28   8a02         mov      A, [DE+0x2]
07e2a   d1           cmp0     A
07e2b   dd24         bz       0x7e51
07e2d   8a02         mov      A, [DE+0x2]
07e2f   318e         shrw     AX, #0x8
07e31   fcb57c00     call     0x7cb5
07e35   13           movw     AX, BC
07e36   bb           movw     [HL], AX
07e37   f6           clrw     AX
07e38   614900       cmpw     AX, [HL]
07e3b   dd0e         bz       0x7e4b
07e3d   ab           movw     AX, [HL]
07e3e   14           movw     DE, AX
07e3f   ca0100       mov      [DE+0x1], #0x0
07e42   ac0a         movw     AX, [HL+0xa]
07e44   c1           push     AX
07e45   ab           movw     AX, [HL]
07e46   fc1f7e00     call     0x7e1f
07e4a   c0           pop      AX
07e4b   ac02         movw     AX, [HL+0x2]
07e4d   14           movw     DE, AX
07e4e   ca0200       mov      [DE+0x2], #0x0
07e51   ac02         movw     AX, [HL+0x2]
07e53   14           movw     DE, AX
07e54   8a01         mov      A, [DE+0x1]
07e56   d1           cmp0     A
07e57   dd29         bz       0x7e82
07e59   8a01         mov      A, [DE+0x1]
07e5b   318e         shrw     AX, #0x8
07e5d   fcb57c00     call     0x7cb5
07e61   13           movw     AX, BC
07e62   bb           movw     [HL], AX
07e63   f6           clrw     AX
07e64   614900       cmpw     AX, [HL]
07e67   dd13         bz       0x7e7c
07e69   ab           movw     AX, [HL]
07e6a   14           movw     DE, AX
07e6b   ca0200       mov      [DE+0x2], #0x0
07e6e   ab           movw     AX, [HL]
07e6f   14           movw     DE, AX
07e70   ca0300       mov      [DE+0x3], #0x0
07e73   ac0a         movw     AX, [HL+0xa]
07e75   c1           push     AX
07e76   ab           movw     AX, [HL]
07e77   fcb67e00     call     0x7eb6
07e7b   c0           pop      AX
07e7c   ac02         movw     AX, [HL+0x2]
07e7e   14           movw     DE, AX
07e7f   ca0100       mov      [DE+0x1], #0x0
07e82   ac02         movw     AX, [HL+0x2]
07e84   14           movw     DE, AX
07e85   ca0000       mov      [DE], #0x0
07e88   ac02         movw     AX, [HL+0x2]
07e8a   14           movw     DE, AX
07e8b   ca0300       mov      [DE+0x3], #0x0
07e8e   1004         addw     SP, #0x4
07e90   c6           pop      HL
07e91   d7           ret      
07eb6   c7           push     HL
07eb7   c1           push     AX
07eb8   fbf8ff       movw     HL, SP
07ebb   ab           movw     AX, [HL]
07ebc   14           movw     DE, AX
07ebd   8a0c         mov      A, [DE+0xc]
07ebf   9efc         mov      CS, A
07ec1   aa0a         movw     AX, [DE+0xa]
07ec3   14           movw     DE, AX
07ec4   ab           movw     AX, [HL]
07ec5   61ea         call     DE
07ec7   d2           cmp0     C
07ec8   df0b         bnz      0x7ed5
07eca   ac08         movw     AX, [HL+0x8]
07ecc   c1           push     AX
07ecd   ab           movw     AX, [HL]
07ece   fc1f7e00     call     0x7e1f
07ed2   c0           pop      AX
07ed3   ef06         br       0x7edb
07ed5   ab           movw     AX, [HL]
07ed6   14           movw     DE, AX
07ed7   ac08         movw     AX, [HL+0x8]
07ed9   ba08         movw     [DE+0x8], AX
07edb   c0           pop      AX
07edc   c6           pop      HL
07edd   d7           ret      
07ede   c7           push     HL
07edf   5600         mov      L, #0x0
07ee1   66           mov      A, L
07ee2   4c20         cmp      A, #0x20
07ee4   de0b         bnc      0x7ef1
07ee6   500e         mov      X, #0xe
07ee8   d6           mulu     X
07ee9   12           movw     BC, AX
07eea   3920e400     mov      [BC+0xe420], #0x0
07eee   86           inc      L
07eef   eff0         br       0x7ee1
07ef1   c6           pop      HL
07ef2   d7           ret      
07ef3   c7           push     HL
07ef4   afd2e3       movw     AX, 0xfe3d2
07ef7   bfe2e5       movw     0xfe5e2, AX
07efa   5600         mov      L, #0x0
07efc   66           mov      A, L
07efd   4c20         cmp      A, #0x20
07eff   de31         bnc      0x7f32
07f01   500e         mov      X, #0xe
07f03   d6           mulu     X
07f04   0420e4       addw     AX, #0xe420
07f07   14           movw     DE, AX
07f08   89           mov      A, [DE]
07f09   d1           cmp0     A
07f0a   dd23         bz       0x7f2f
07f0c   8a03         mov      A, [DE+0x3]
07f0e   d1           cmp0     A
07f0f   df1e         bnz      0x7f2f
07f11   aa08         movw     AX, [DE+0x8]
07f13   12           movw     BC, AX
07f14   afe2e5       movw     AX, 0xfe5e2
07f17   23           subw     AX, BC
07f18   12           movw     BC, AX
07f19   aa06         movw     AX, [DE+0x6]
07f1b   33           xchw     AX, BC
07f1c   43           cmpw     AX, BC
07f1d   dc10         bc       0x7f2f
07f1f   afe2e5       movw     AX, 0xfe5e2
07f22   c1           push     AX
07f23   66           mov      A, L
07f24   500e         mov      X, #0xe
07f26   d6           mulu     X
07f27   0420e4       addw     AX, #0xe420
07f2a   fcb67e00     call     0x7eb6
07f2e   c0           pop      AX
07f2f   86           inc      L
07f30   efca         br       0x7efc
07f32   c6           pop      HL
07f33   d7           ret      
07f34   ec767c00     br       0x7c76
0804f   c7           push     HL
08050   c1           push     AX
08051   c1           push     AX
08052   fbf8ff       movw     HL, SP
08055   ac02         movw     AX, [HL+0x2]
08057   14           movw     DE, AX
08058   aa04         movw     AX, [DE+0x4]
0805a   14           movw     DE, AX
0805b   aa0c         movw     AX, [DE+0xc]
0805d   312e         shrw     AX, #0x2
0805f   bb           movw     [HL], AX
08060   301207       movw     AX, #0x712
08063   614900       cmpw     AX, [HL]
08066   df0a         bnz      0x8072
08068   f5e6e5       clrb     0xfe5e6
0806b   e6           onew     AX
0806c   fc7cb900     call     0xb97c
08070   ef2a         br       0x809c
08072   304805       movw     AX, #0x548
08075   614900       cmpw     AX, [HL]
08078   dd1c         bz       0x8096
0807a   5058         mov      X, #0x58
0807c   614900       cmpw     AX, [HL]
0807f   dd15         bz       0x8096
08081   301403       movw     AX, #0x314
08084   614900       cmpw     AX, [HL]
08087   dd0d         bz       0x8096
08089   a1           incw     AX
0808a   614900       cmpw     AX, [HL]
0808d   dd07         bz       0x8096
0808f   501b         mov      X, #0x1b
08091   614900       cmpw     AX, [HL]
08094   df06         bnz      0x809c
08096   f5e7e5       clrb     0xfe5e7
08099   e5e8e5       oneb     0xfe5e8
0809c   e7           onew     BC
0809d   1004         addw     SP, #0x4
0809f   c6           pop      HL
080a0   d7           ret      
080b8 + f6           clrw     AX
080b9 + 12           movw     BC, AX
080ba + ecca8200     br       0x82ca
080be   f6           clrw     AX
080bf   12           movw     BC, AX
080c0   ecca8200     br       0x82ca
080d3   c7           push     HL
080d4   c1           push     AX
080d5   2008         subw     SP, #0x8
080d7   fbf8ff       movw     HL, SP
080da   f6           clrw     AX
080db   bb           movw     [HL], AX
080dc   bc02         movw     [HL+0x2], AX
080de   ac08         movw     AX, [HL+0x8]
080e0   314d         shlw     AX, #0x4
080e2   320006       movw     BC, #0x600
080e5   03           addw     AX, BC
080e6   bc06         movw     [HL+0x6], AX
080e8   3076c0       movw     AX, #0xc076
080eb   bc04         movw     [HL+0x4], AX
080ed   ac06         movw     AX, [HL+0x6]
080ef   14           movw     DE, AX
080f0   300400       movw     AX, #0x4
080f3   ba0e         movw     [DE+0xe], AX
080f5   ac06         movw     AX, [HL+0x6]
080f7   14           movw     DE, AX
080f8   8a08         mov      A, [DE+0x8]
080fa   72           mov      C, A
080fb   ac04         movw     AX, [HL+0x4]
080fd   14           movw     DE, AX
080fe   62           mov      A, C
080ff   9a08         mov      [DE+0x8], A
08101   ac04         movw     AX, [HL+0x4]
08103   14           movw     DE, AX
08104   8a08         mov      A, [DE+0x8]
08106   81           inc      A
08107   311a         shr      A, #0x1
08109   91           dec      A
0810a   dd2d         bz       0x8139
0810c   91           dec      A
0810d   dd1e         bz       0x812d
0810f   91           dec      A
08110   dd0f         bz       0x8121
08112   91           dec      A
08113   df2e         bnz      0x8143
08115   ac06         movw     AX, [HL+0x6]
08117   14           movw     DE, AX
08118   aa06         movw     AX, [DE+0x6]
0811a   12           movw     BC, AX
0811b   ac04         movw     AX, [HL+0x4]
0811d   14           movw     DE, AX
0811e   13           movw     AX, BC
0811f   ba06         movw     [DE+0x6], AX
08121   ac06         movw     AX, [HL+0x6]
08123   14           movw     DE, AX
08124   aa04         movw     AX, [DE+0x4]
08126   12           movw     BC, AX
08127   ac04         movw     AX, [HL+0x4]
08129   14           movw     DE, AX
0812a   13           movw     AX, BC
0812b   ba04         movw     [DE+0x4], AX
0812d   ac06         movw     AX, [HL+0x6]
0812f   14           movw     DE, AX
08130   aa02         movw     AX, [DE+0x2]
08132   12           movw     BC, AX
08133   ac04         movw     AX, [HL+0x4]
08135   14           movw     DE, AX
08136   13           movw     AX, BC
08137   ba02         movw     [DE+0x2], AX
08139   ac06         movw     AX, [HL+0x6]
0813b   14           movw     DE, AX
0813c   a9           movw     AX, [DE]
0813d   12           movw     BC, AX
0813e   ac04         movw     AX, [HL+0x4]
08140   14           movw     DE, AX
08141   13           movw     AX, BC
08142   b9           movw     [DE], AX
08143   ac06         movw     AX, [HL+0x6]
08145   14           movw     DE, AX
08146   aa0c         movw     AX, [DE+0xc]
08148   12           movw     BC, AX
08149   ac04         movw     AX, [HL+0x4]
0814b   14           movw     DE, AX
0814c   13           movw     AX, BC
0814d   ba0c         movw     [DE+0xc], AX
0814f   ac06         movw     AX, [HL+0x6]
08151   14           movw     DE, AX
08152   aa0e         movw     AX, [DE+0xe]
08154   12           movw     BC, AX
08155   ac04         movw     AX, [HL+0x4]
08157   14           movw     DE, AX
08158   13           movw     AX, BC
08159   ba0e         movw     [DE+0xe], AX
0815b   617900       incw     [HL]
0815e   f6           clrw     AX
0815f   614900       cmpw     AX, [HL]
08162   61f8         sknz     
08164   617902       incw     [HL+0x2]
08167   ac06         movw     AX, [HL+0x6]
08169   14           movw     DE, AX
0816a   aa0e         movw     AX, [DE+0xe]
0816c   5c20         and      A, #0x20
0816e   08           xch      A, X
0816f   5c04         and      A, #0x4
08171   08           xch      A, X
08172   6168         or       A, X
08174   61e8         skz      
08176   ee74ff       br       0x80ed
08179   ac06         movw     AX, [HL+0x6]
0817b   14           movw     DE, AX
0817c   301000       movw     AX, #0x10
0817f   ba0e         movw     [DE+0xe], AX
08181   f6           clrw     AX
08182   614902       cmpw     AX, [HL+0x2]
08185   df04         bnz      0x818b
08187   e6           onew     AX
08188   614900       cmpw     AX, [HL]
0818b   de0b         bnc      0x8198
0818d   ac04         movw     AX, [HL+0x4]
0818f   14           movw     DE, AX
08190   aa0e         movw     AX, [DE+0xe]
08192   08           xch      A, X
08193   6c10         or       A, #0x10
08195   08           xch      A, X
08196   ba0e         movw     [DE+0xe], AX
08198   100a         addw     SP, #0xa
0819a   c6           pop      HL
0819b   d7           ret      
0819c   c7           push     HL
0819d   2004         subw     SP, #0x4
0819f   fbf8ff       movw     HL, SP
081a2   e6           onew     AX
081a3   bfe805       movw     0xf05e8, AX
081a6   aff405       movw     AX, 0xf05f4
081a9   bc02         movw     [HL+0x2], AX
081ab   5102         mov      A, #0x2
081ad   5e02         and      A, [HL+0x2]
081af   318e         shrw     AX, #0x8
081b1   6168         or       A, X
081b3   df14         bnz      0x81c9
081b5   8c02         mov      A, [HL+0x2]
081b7   5c00         and      A, #0x0
081b9   8c03         mov      A, [HL+0x3]
081bb   318e         shrw     AX, #0x8
081bd   bb           movw     [HL], AX
081be   fc2a8e00     call     0x8e2a
081c2   aff405       movw     AX, 0xf05f4
081c5   bc02         movw     [HL+0x2], AX
081c7   efe2         br       0x81ab
081c9   1004         addw     SP, #0x4
081cb   c6           pop      HL
081cc   d7           ret      
081cd   c7           push     HL
081ce   2008         subw     SP, #0x8
081d0   fbf8ff       movw     HL, SP
081d3   e6           onew     AX
081d4   a1           incw     AX
081d5   bfe805       movw     0xf05e8, AX
081d8   5010         mov      X, #0x10
081da   bc04         movw     [HL+0x4], AX
081dc   b1           decw     AX
081dd   b1           decw     AX
081de   bc02         movw     [HL+0x2], AX
081e0   aff005       movw     AX, 0xf05f0
081e3   bb           movw     [HL], AX
081e4   5102         mov      A, #0x2
081e6   5d           and      A, [HL]
081e7   318e         shrw     AX, #0x8
081e9   6168         or       A, X
081eb   df61         bnz      0x824e
081ed   8b           mov      A, [HL]
081ee   5c00         and      A, #0x0
081f0   8c01         mov      A, [HL+0x1]
081f2   318e         shrw     AX, #0x8
081f4   bc06         movw     [HL+0x6], AX
081f6   440e00       cmpw     AX, #0xe
081f9   dc24         bc       0x821f
081fb   ac06         movw     AX, [HL+0x6]
081fd   614904       cmpw     AX, [HL+0x4]
08200   de1d         bnc      0x821f
08202   ac06         movw     AX, [HL+0x6]
08204   314d         shlw     AX, #0x4
08206   320006       movw     BC, #0x600
08209   03           addw     AX, BC
0820a   14           movw     DE, AX
0820b   aa0e         movw     AX, [DE+0xe]
0820d   f1           clrb     A
0820e   08           xch      A, X
0820f   5c04         and      A, #0x4
08211   08           xch      A, X
08212   440400       cmpw     AX, #0x4
08215   df08         bnz      0x821f
08217   ac06         movw     AX, [HL+0x6]
08219   fc0e8c00     call     0x8c0e
0821d   ef29         br       0x8248
0821f   ac06         movw     AX, [HL+0x6]
08221   440900       cmpw     AX, #0x9
08224   dc22         bc       0x8248
08226   ac06         movw     AX, [HL+0x6]
08228   614902       cmpw     AX, [HL+0x2]
0822b   de1b         bnc      0x8248
0822d   ac06         movw     AX, [HL+0x6]
0822f   314d         shlw     AX, #0x4
08231   320006       movw     BC, #0x600
08234   03           addw     AX, BC
08235   14           movw     DE, AX
08236   aa0e         movw     AX, [DE+0xe]
08238   f1           clrb     A
08239   08           xch      A, X
0823a   5c04         and      A, #0x4
0823c   08           xch      A, X
0823d   440400       cmpw     AX, #0x4
08240   df06         bnz      0x8248
08242   ac06         movw     AX, [HL+0x6]
08244   fcb68c00     call     0x8cb6
08248   aff005       movw     AX, 0xf05f0
0824b   bb           movw     [HL], AX
0824c   ef96         br       0x81e4
0824e   e1           oneb     A
0824f   5d           and      A, [HL]
08250   318e         shrw     AX, #0x8
08252   6168         or       A, X
08254   dd5b         bz       0x82b1
08256   e6           onew     AX
08257   bff005       movw     0xf05f0, AX
0825a   500e         mov      X, #0xe
0825c   bc06         movw     [HL+0x6], AX
0825e   ac06         movw     AX, [HL+0x6]
08260   614904       cmpw     AX, [HL+0x4]
08263   de20         bnc      0x8285
08265   ac06         movw     AX, [HL+0x6]
08267   314d         shlw     AX, #0x4
08269   320006       movw     BC, #0x600
0826c   03           addw     AX, BC
0826d   14           movw     DE, AX
0826e   aa0e         movw     AX, [DE+0xe]
08270   f1           clrb     A
08271   08           xch      A, X
08272   5c04         and      A, #0x4
08274   08           xch      A, X
08275   440400       cmpw     AX, #0x4
08278   df06         bnz      0x8280
0827a   ac06         movw     AX, [HL+0x6]
0827c   fc0e8c00     call     0x8c0e
08280   617906       incw     [HL+0x6]
08283   efd9         br       0x825e
08285   300900       movw     AX, #0x9
08288   bc06         movw     [HL+0x6], AX
0828a   ac06         movw     AX, [HL+0x6]
0828c   614902       cmpw     AX, [HL+0x2]
0828f   de20         bnc      0x82b1
08291   ac06         movw     AX, [HL+0x6]
08293   314d         shlw     AX, #0x4
08295   320006       movw     BC, #0x600
08298   03           addw     AX, BC
08299   14           movw     DE, AX
0829a   aa0e         movw     AX, [DE+0xe]
0829c   f1           clrb     A
0829d   08           xch      A, X
0829e   5c04         and      A, #0x4
082a0   08           xch      A, X
082a1   440400       cmpw     AX, #0x4
082a4   df06         bnz      0x82ac
082a6   ac06         movw     AX, [HL+0x6]
082a8   fcb68c00     call     0x8cb6
082ac   617906       incw     [HL+0x6]
082af   efd9         br       0x828a
082b1   1008         addw     SP, #0x8
082b3   c6           pop      HL
082b4   d7           ret      
082b5   ecd18b00     br       0x8bd1
082ca   c7           push     HL
082cb   c3           push     BC
082cc   c1           push     AX
082cd   2018         subw     SP, #0x18
082cf   fbf8ff       movw     HL, SP
082d2   f6           clrw     AX
082d3   bc0c         movw     [HL+0xc], AX
082d5   bc0e         movw     [HL+0xe], AX
082d7   bc08         movw     [HL+0x8], AX
082d9   bc0a         movw     [HL+0xa], AX
082db   30d005       movw     AX, #0x5d0
082de   bc02         movw     [HL+0x2], AX
082e0   50c0         mov      X, #0xc0
082e2   bb           movw     [HL], AX
082e3   ac1a         movw     AX, [HL+0x1a]
082e5   12           movw     BC, AX
082e6   ac18         movw     AX, [HL+0x18]
082e8   bf64c0       movw     0xfc064, AX
082eb   33           xchw     AX, BC
082ec   bf66c0       movw     0xfc066, AX
082ef   ab           movw     AX, [HL]
082f0   14           movw     DE, AX
082f1   a9           movw     AX, [DE]
082f2   f1           clrb     A
082f3   08           xch      A, X
082f4   5c01         and      A, #0x1
082f6   08           xch      A, X
082f7   e7           onew     BC
082f8   43           cmpw     AX, BC
082f9   dd0d         bz       0x8308
082fb   4100         mov      ES, #0x0
082fd   118f0865     mov      A, ES:0x6508
08301   9a0e         mov      [DE+0xe], A
08303   ab           movw     AX, [HL]
08304   14           movw     DE, AX
08305   f0           clrb     X
08306   e1           oneb     A
08307   b9           movw     [DE], AX
08308   ac02         movw     AX, [HL+0x2]
0830a   14           movw     DE, AX
0830b   aa10         movw     AX, [DE+0x10]
0830d   f1           clrb     A
0830e   08           xch      A, X
0830f   5c18         and      A, #0x18
08311   08           xch      A, X
08312   6168         or       A, X
08314   dd2f         bz       0x8345
08316   aa10         movw     AX, [DE+0x10]
08318   f1           clrb     A
08319   08           xch      A, X
0831a   5c18         and      A, #0x18
0831c   08           xch      A, X
0831d   441800       cmpw     AX, #0x18
08320   df04         bnz      0x8326
08322   5010         mov      X, #0x10
08324   ba10         movw     [DE+0x10], AX
08326   ac02         movw     AX, [HL+0x2]
08328   14           movw     DE, AX
08329   aa10         movw     AX, [DE+0x10]
0832b   f1           clrb     A
0832c   08           xch      A, X
0832d   5c08         and      A, #0x8
0832f   08           xch      A, X
08330   440800       cmpw     AX, #0x8
08333   df04         bnz      0x8339
08335   5008         mov      X, #0x8
08337   ba10         movw     [DE+0x10], AX
08339   ac02         movw     AX, [HL+0x2]
0833b   14           movw     DE, AX
0833c   aa10         movw     AX, [DE+0x10]
0833e   f1           clrb     A
0833f   08           xch      A, X
08340   5c18         and      A, #0x18
08342   08           xch      A, X
08343   ba10         movw     [DE+0x10], AX
08345   cc0600       mov      [HL+0x6], #0x0
08348   cc0701       mov      [HL+0x7], #0x1
0834b   8c06         mov      A, [HL+0x6]
0834d   f0           clrb     X
0834e   314e         shrw     AX, #0x4
08350   320006       movw     BC, #0x600
08353   03           addw     AX, BC
08354   bc04         movw     [HL+0x4], AX
08356   8c06         mov      A, [HL+0x6]
08358   318e         shrw     AX, #0x8
0835a   bc16         movw     [HL+0x16], AX
0835c   8c07         mov      A, [HL+0x7]
0835e   318e         shrw     AX, #0x8
08360   12           movw     BC, AX
08361   ac16         movw     AX, [HL+0x16]
08363   43           cmpw     AX, BC
08364   de13         bnc      0x8379
08366   ac04         movw     AX, [HL+0x4]
08368   14           movw     DE, AX
08369   e6           onew     AX
0836a   a1           incw     AX
0836b   ba0e         movw     [DE+0xe], AX
0836d   ac04         movw     AX, [HL+0x4]
0836f   041000       addw     AX, #0x10
08372   bc04         movw     [HL+0x4], AX
08374   617916       incw     [HL+0x16]
08377   efe3         br       0x835c
08379   ac02         movw     AX, [HL+0x2]
0837b   14           movw     DE, AX
0837c   aa10         movw     AX, [DE+0x10]
0837e   f1           clrb     A
0837f   08           xch      A, X
08380   5c07         and      A, #0x7
08382   08           xch      A, X
08383   6168         or       A, X
08385   dd13         bz       0x839a
08387   300700       movw     AX, #0x7
0838a   ba10         movw     [DE+0x10], AX
0838c   ac02         movw     AX, [HL+0x2]
0838e   14           movw     DE, AX
0838f   aa10         movw     AX, [DE+0x10]
08391   f1           clrb     A
08392   08           xch      A, X
08393   5c07         and      A, #0x7
08395   08           xch      A, X
08396   6168         or       A, X
08398   dff2         bnz      0x838c
0839a   ac18         movw     AX, [HL+0x18]
0839c   01           addw     AX, AX
0839d   12           movw     BC, AX
0839e   4100         mov      ES, #0x0
083a0   11490c65     mov      A, ES:[BC+0x650c]
083a4   72           mov      C, A
083a5   ac02         movw     AX, [HL+0x2]
083a7   14           movw     DE, AX
083a8   62           mov      A, C
083a9   9a1a         mov      [DE+0x1a], A
083ab   ac18         movw     AX, [HL+0x18]
083ad   01           addw     AX, AX
083ae   12           movw     BC, AX
083af   4100         mov      ES, #0x0
083b1   11790e65     movw     AX, ES:[BC+0x650e]
083b5   12           movw     BC, AX
083b6   ac02         movw     AX, [HL+0x2]
083b8   14           movw     DE, AX
083b9   13           movw     AX, BC
083ba   ba1c         movw     [DE+0x1c], AX
083bc   ac18         movw     AX, [HL+0x18]
083be   01           addw     AX, AX
083bf   12           movw     BC, AX
083c0   4100         mov      ES, #0x0
083c2   11790a65     movw     AX, ES:[BC+0x650a]
083c6   12           movw     BC, AX
083c7   ac02         movw     AX, [HL+0x2]
083c9   14           movw     DE, AX
083ca   13           movw     AX, BC
083cb   ba16         movw     [DE+0x16], AX
083cd   3076c0       movw     AX, #0xc076
083d0   bf50c0       movw     0xfc050, AX
083d3   f6           clrw     AX
083d4   bc16         movw     [HL+0x16], AX
083d6   f6           clrw     AX
083d7   614916       cmpw     AX, [HL+0x16]
083da   df63         bnz      0x843f
083dc   ac16         movw     AX, [HL+0x16]
083de   bc10         movw     [HL+0x10], AX
083e0   8f54c0       mov      A, 0xfc054
083e3   5c04         and      A, #0x4
083e5   4c04         cmp      A, #0x4
083e7   df15         bnz      0x83fe
083e9   ac10         movw     AX, [HL+0x10]
083eb   01           addw     AX, AX
083ec   0452c0       addw     AX, #0xc052
083ef   14           movw     DE, AX
083f0   a9           movw     AX, [DE]
083f1   bc14         movw     [HL+0x14], AX
083f3   440200       cmpw     AX, #0x2
083f6   de06         bnc      0x83fe
083f8   ac14         movw     AX, [HL+0x14]
083fa   fc507302     call     0x27350
083fe   ac10         movw     AX, [HL+0x10]
08400   01           addw     AX, AX
08401   12           movw     BC, AX
08402   f6           clrw     AX
08403   b1           decw     AX
08404   7852c0       movw     [BC+0xc052], AX
08407   ac16         movw     AX, [HL+0x16]
08409   314d         shlw     AX, #0x4
0840b   320006       movw     BC, #0x600
0840e   03           addw     AX, BC
0840f   bc04         movw     [HL+0x4], AX
08411   ac04         movw     AX, [HL+0x4]
08413   14           movw     DE, AX
08414   aa0e         movw     AX, [DE+0xe]
08416   f1           clrb     A
08417   08           xch      A, X
08418   5c01         and      A, #0x1
0841a   08           xch      A, X
0841b   6168         or       A, X
0841d   dd05         bz       0x8424
0841f   e6           onew     AX
08420   ba0e         movw     [DE+0xe], AX
08422   efed         br       0x8411
08424   ac04         movw     AX, [HL+0x4]
08426   14           movw     DE, AX
08427   301c00       movw     AX, #0x1c
0842a   ba0e         movw     [DE+0xe], AX
0842c   ac04         movw     AX, [HL+0x4]
0842e   14           movw     DE, AX
0842f   ca0901       mov      [DE+0x9], #0x1
08432   ac04         movw     AX, [HL+0x4]
08434   14           movw     DE, AX
08435   300008       movw     AX, #0x800
08438   ba0e         movw     [DE+0xe], AX
0843a   617916       incw     [HL+0x16]
0843d   ef97         br       0x83d6
0843f   e6           onew     AX
08440   bc16         movw     [HL+0x16], AX
08442   ac16         movw     AX, [HL+0x16]
08444   440900       cmpw     AX, #0x9
08447   de30         bnc      0x8479
08449   ac16         movw     AX, [HL+0x16]
0844b   314d         shlw     AX, #0x4
0844d   320006       movw     BC, #0x600
08450   03           addw     AX, BC
08451   bc04         movw     [HL+0x4], AX
08453   ac04         movw     AX, [HL+0x4]
08455   14           movw     DE, AX
08456   aa0e         movw     AX, [DE+0xe]
08458   f1           clrb     A
08459   08           xch      A, X
0845a   5c01         and      A, #0x1
0845c   08           xch      A, X
0845d   6168         or       A, X
0845f   dd05         bz       0x8466
08461   e6           onew     AX
08462   ba0e         movw     [DE+0xe], AX
08464   efed         br       0x8453
08466   ac04         movw     AX, [HL+0x4]
08468   14           movw     DE, AX
08469   301e00       movw     AX, #0x1e
0846c   ba0e         movw     [DE+0xe], AX
0846e   ac04         movw     AX, [HL+0x4]
08470   14           movw     DE, AX
08471   ca0900       mov      [DE+0x9], #0x0
08474   617916       incw     [HL+0x16]
08477   efc9         br       0x8442
08479   300900       movw     AX, #0x9
0847c   bc16         movw     [HL+0x16], AX
0847e   ac16         movw     AX, [HL+0x16]
08480   440e00       cmpw     AX, #0xe
08483   de58         bnc      0x84dd
08485   ac16         movw     AX, [HL+0x16]
08487   240900       subw     AX, #0x9
0848a   a1           incw     AX
0848b   bc12         movw     [HL+0x12], AX
0848d   ac16         movw     AX, [HL+0x16]
0848f   314d         shlw     AX, #0x4
08491   320006       movw     BC, #0x600
08494   03           addw     AX, BC
08495   bc04         movw     [HL+0x4], AX
08497   ac04         movw     AX, [HL+0x4]
08499   14           movw     DE, AX
0849a   aa0e         movw     AX, [DE+0xe]
0849c   f1           clrb     A
0849d   08           xch      A, X
0849e   5c01         and      A, #0x1
084a0   08           xch      A, X
084a1   6168         or       A, X
084a3   dd05         bz       0x84aa
084a5   e6           onew     AX
084a6   ba0e         movw     [DE+0xe], AX
084a8   efed         br       0x8497
084aa   ac04         movw     AX, [HL+0x4]
084ac   14           movw     DE, AX
084ad   301e00       movw     AX, #0x1e
084b0   ba0e         movw     [DE+0xe], AX
084b2   ac04         movw     AX, [HL+0x4]
084b4   14           movw     DE, AX
084b5   ca0989       mov      [DE+0x9], #0x89
084b8   ac12         movw     AX, [HL+0x12]
084ba   01           addw     AX, AX
084bb   12           movw     BC, AX
084bc   4100         mov      ES, #0x0
084be   1179c464     movw     AX, ES:[BC+0x64c4]
084c2   12           movw     BC, AX
084c3   ac04         movw     AX, [HL+0x4]
084c5   14           movw     DE, AX
084c6   13           movw     AX, BC
084c7   ba0c         movw     [DE+0xc], AX
084c9   ac04         movw     AX, [HL+0x4]
084cb   14           movw     DE, AX
084cc   300008       movw     AX, #0x800
084cf   ba0e         movw     [DE+0xe], AX
084d1   ac04         movw     AX, [HL+0x4]
084d3   14           movw     DE, AX
084d4   f0           clrb     X
084d5   e1           oneb     A
084d6   ba0e         movw     [DE+0xe], AX
084d8   617916       incw     [HL+0x16]
084db   efa1         br       0x847e
084dd   300e00       movw     AX, #0xe
084e0   bc16         movw     [HL+0x16], AX
084e2   ac16         movw     AX, [HL+0x16]
084e4   441000       cmpw     AX, #0x10
084e7   61c8         skc      
084e9   eebf00       br       0x85ab
084ec   ac16         movw     AX, [HL+0x16]
084ee   314d         shlw     AX, #0x4
084f0   320006       movw     BC, #0x600
084f3   03           addw     AX, BC
084f4   bc04         movw     [HL+0x4], AX
084f6   ac04         movw     AX, [HL+0x4]
084f8   14           movw     DE, AX
084f9   aa0e         movw     AX, [DE+0xe]
084fb   f1           clrb     A
084fc   08           xch      A, X
084fd   5c01         and      A, #0x1
084ff   08           xch      A, X
08500   6168         or       A, X
08502   dd05         bz       0x8509
08504   e6           onew     AX
08505   ba0e         movw     [DE+0xe], AX
08507   efed         br       0x84f6
08509   f6           clrw     AX
0850a   61490a       cmpw     AX, [HL+0xa]
0850d   61f8         sknz     
0850f   614908       cmpw     AX, [HL+0x8]
08512   df07         bnz      0x851b
08514   e6           onew     AX
08515   a1           incw     AX
08516   bc08         movw     [HL+0x8], AX
08518   f6           clrw     AX
08519   bc0a         movw     [HL+0xa], AX
0851b   ac04         movw     AX, [HL+0x4]
0851d   14           movw     DE, AX
0851e   301e00       movw     AX, #0x1e
08521   ba0e         movw     [DE+0xe], AX
08523   ac0e         movw     AX, [HL+0xe]
08525   12           movw     BC, AX
08526   ac0c         movw     AX, [HL+0xc]
08528   040200       addw     AX, #0x2
0852b   61d8         sknc     
0852d   a3           incw     BC
0852e   bdd8         movw     0xffed8, AX
08530   13           movw     AX, BC
08531   bdda         movw     0xffeda, AX
08533   5103         mov      A, #0x3
08535   fd7106       call     0x671
08538   8dd8         mov      A, 0xffed8
0853a   6c81         or       A, #0x81
0853c   72           mov      C, A
0853d   ac04         movw     AX, [HL+0x4]
0853f   14           movw     DE, AX
08540   62           mov      A, C
08541   9a09         mov      [DE+0x9], A
08543   ac18         movw     AX, [HL+0x18]
08545   313d         shlw     AX, #0x3
08547   042865       addw     AX, #0x6528
0854a   14           movw     DE, AX
0854b   ac0c         movw     AX, [HL+0xc]
0854d   01           addw     AX, AX
0854e   05           addw     AX, DE
0854f   14           movw     DE, AX
08550   4100         mov      ES, #0x0
08552   11a9         movw     AX, ES:[DE]
08554   12           movw     BC, AX
08555   ac04         movw     AX, [HL+0x4]
08557   14           movw     DE, AX
08558   13           movw     AX, BC
08559   ba0a         movw     [DE+0xa], AX
0855b   ac18         movw     AX, [HL+0x18]
0855d   313d         shlw     AX, #0x3
0855f   042065       addw     AX, #0x6520
08562   14           movw     DE, AX
08563   ac0c         movw     AX, [HL+0xc]
08565   01           addw     AX, AX
08566   05           addw     AX, DE
08567   14           movw     DE, AX
08568   4100         mov      ES, #0x0
0856a   11a9         movw     AX, ES:[DE]
0856c   12           movw     BC, AX
0856d   ac04         movw     AX, [HL+0x4]
0856f   14           movw     DE, AX
08570   13           movw     AX, BC
08571   ba0c         movw     [DE+0xc], AX
08573   ac04         movw     AX, [HL+0x4]
08575   14           movw     DE, AX
08576   300008       movw     AX, #0x800
08579   ba0e         movw     [DE+0xe], AX
0857b   ac04         movw     AX, [HL+0x4]
0857d   14           movw     DE, AX
0857e   f0           clrb     X
0857f   e1           oneb     A
08580   ba0e         movw     [DE+0xe], AX
08582   f6           clrw     AX
08583   614908       cmpw     AX, [HL+0x8]
08586   618908       decw     [HL+0x8]
08589   61f8         sknz     
0858b   61890a       decw     [HL+0xa]
0858e   f6           clrw     AX
0858f   61490a       cmpw     AX, [HL+0xa]
08592   61f8         sknz     
08594   614908       cmpw     AX, [HL+0x8]
08597   df0c         bnz      0x85a5
08599   61790c       incw     [HL+0xc]
0859c   f6           clrw     AX
0859d   61490c       cmpw     AX, [HL+0xc]
085a0   61f8         sknz     
085a2   61790e       incw     [HL+0xe]
085a5   617916       incw     [HL+0x16]
085a8   ee37ff       br       0x84e2
085ab   db66c0       movw     BC, 0xfc066
085ae   af64c0       movw     AX, 0xfc064
085b1   33           xchw     AX, BC
085b2   bf66c0       movw     0xfc066, AX
085b5   ac18         movw     AX, [HL+0x18]
085b7   313d         shlw     AX, #0x3
085b9   12           movw     BC, AX
085ba   4100         mov      ES, #0x0
085bc   11791865     movw     AX, ES:[BC+0x6518]
085c0   12           movw     BC, AX
085c1   ac02         movw     AX, [HL+0x2]
085c3   14           movw     DE, AX
085c4   13           movw     AX, BC
085c5   b9           movw     [DE], AX
085c6   ac18         movw     AX, [HL+0x18]
085c8   313d         shlw     AX, #0x3
085ca   12           movw     BC, AX
085cb   4100         mov      ES, #0x0
085cd   11791065     movw     AX, ES:[BC+0x6510]
085d1   12           movw     BC, AX
085d2   ac02         movw     AX, [HL+0x2]
085d4   14           movw     DE, AX
085d5   13           movw     AX, BC
085d6   ba02         movw     [DE+0x2], AX
085d8   ac18         movw     AX, [HL+0x18]
085da   313d         shlw     AX, #0x3
085dc   041865       addw     AX, #0x6518
085df   14           movw     DE, AX
085e0   a5           incw     DE
085e1   a5           incw     DE
085e2   4100         mov      ES, #0x0
085e4   11a9         movw     AX, ES:[DE]
085e6   12           movw     BC, AX
085e7   ac02         movw     AX, [HL+0x2]
085e9   14           movw     DE, AX
085ea   13           movw     AX, BC
085eb   ba04         movw     [DE+0x4], AX
085ed   ac18         movw     AX, [HL+0x18]
085ef   313d         shlw     AX, #0x3
085f1   041065       addw     AX, #0x6510
085f4   14           movw     DE, AX
085f5   a5           incw     DE
085f6   a5           incw     DE
085f7   4100         mov      ES, #0x0
085f9   11a9         movw     AX, ES:[DE]
085fb   12           movw     BC, AX
085fc   ac02         movw     AX, [HL+0x2]
085fe   14           movw     DE, AX
085ff   13           movw     AX, BC
08600   ba06         movw     [DE+0x6], AX
08602   ac18         movw     AX, [HL+0x18]
08604   313d         shlw     AX, #0x3
08606   12           movw     BC, AX
08607   4100         mov      ES, #0x0
08609   11791c65     movw     AX, ES:[BC+0x651c]
0860d   12           movw     BC, AX
0860e   ac02         movw     AX, [HL+0x2]
08610   14           movw     DE, AX
08611   13           movw     AX, BC
08612   ba08         movw     [DE+0x8], AX
08614   ac18         movw     AX, [HL+0x18]
08616   313d         shlw     AX, #0x3
08618   12           movw     BC, AX
08619   4100         mov      ES, #0x0
0861b   11791465     movw     AX, ES:[BC+0x6514]
0861f   12           movw     BC, AX
08620   ac02         movw     AX, [HL+0x2]
08622   14           movw     DE, AX
08623   13           movw     AX, BC
08624   ba0a         movw     [DE+0xa], AX
08626   ac18         movw     AX, [HL+0x18]
08628   313d         shlw     AX, #0x3
0862a   12           movw     BC, AX
0862b   4100         mov      ES, #0x0
0862d   11791e65     movw     AX, ES:[BC+0x651e]
08631   12           movw     BC, AX
08632   ac02         movw     AX, [HL+0x2]
08634   14           movw     DE, AX
08635   13           movw     AX, BC
08636   ba0c         movw     [DE+0xc], AX
08638   ac18         movw     AX, [HL+0x18]
0863a   313d         shlw     AX, #0x3
0863c   12           movw     BC, AX
0863d   4100         mov      ES, #0x0
0863f   11791665     movw     AX, ES:[BC+0x6516]
08643   12           movw     BC, AX
08644   ac02         movw     AX, [HL+0x2]
08646   14           movw     DE, AX
08647   13           movw     AX, BC
08648   ba0e         movw     [DE+0xe], AX
0864a   ac02         movw     AX, [HL+0x2]
0864c   14           movw     DE, AX
0864d   aa18         movw     AX, [DE+0x18]
0864f   e586c0       oneb     0xfc086
08652   302000       movw     AX, #0x20
08655   ba10         movw     [DE+0x10], AX
08657   ac02         movw     AX, [HL+0x2]
08659   14           movw     DE, AX
0865a   300601       movw     AX, #0x106
0865d   ba10         movw     [DE+0x10], AX
0865f   101c         addw     SP, #0x1c
08661   c6           pop      HL
08662   d7           ret      
08755 + c7           push     HL
08756 + c1           push     AX
08757 + 200c         subw     SP, #0xc
08759 + fbf8ff       movw     HL, SP
0875c + ac0c         movw     AX, [HL+0xc]
0875e + 440200       cmpw     AX, #0x2
08761 + 61c8         skc      
08763 + ecf78700     br       0x87f7
08767 + fc80e000     call     0xe080
0876b + 62           mov      A, C
0876c + 9c0b         mov      [HL+0xb], A
0876e + 717bfa       clr1     PSW.7
08771 + ac0c         movw     AX, [HL+0xc]
08773 + bb           movw     [HL], AX
08774 + 314e         shrw     AX, #0x4
08776 + bc04         movw     [HL+0x4], AX
08778 + 510f         mov      A, #0xf
0877a + 5d           and      A, [HL]
0877b + 318e         shrw     AX, #0x8
0877d + bc02         movw     [HL+0x2], AX
0877f + ac04         movw     AX, [HL+0x4]
08781 + 01           addw     AX, AX
08782 + 0474c0       addw     AX, #0xc074
08785 + 14           movw     DE, AX
08786 + a9           movw     AX, [DE]
08787 + 12           movw     BC, AX
08788 + ac02         movw     AX, [HL+0x2]
0878a + 01           addw     AX, AX
0878b + 046c64       addw     AX, #0x646c
0878e + 14           movw     DE, AX
0878f + 4100         mov      ES, #0x0
08791 + 1189         mov      A, ES:[DE]
08793 + 615a         and      A, C
08795 + 08           xch      A, X
08796 + 118a01       mov      A, ES:[DE+0x1]
08799 + 615b         and      A, B
0879b + 6168         or       A, X
0879d + dd23         bz       0x87c2
0879f + ac02         movw     AX, [HL+0x2]
087a1 + 01           addw     AX, AX
087a2 + 046c64       addw     AX, #0x646c
087a5 + 14           movw     DE, AX
087a6 + 11a9         movw     AX, ES:[DE]
087a8 + 12           movw     BC, AX
087a9 + f6           clrw     AX
087aa + b1           decw     AX
087ab + 23           subw     AX, BC
087ac + 12           movw     BC, AX
087ad + ac04         movw     AX, [HL+0x4]
087af + 01           addw     AX, AX
087b0 + 0474c0       addw     AX, #0xc074
087b3 + 14           movw     DE, AX
087b4 + a9           movw     AX, [DE]
087b5 + 615b         and      A, B
087b7 + 08           xch      A, X
087b8 + 615a         and      A, C
087ba + 08           xch      A, X
087bb + b9           movw     [DE], AX
087bc + ac0c         movw     AX, [HL+0xc]
087be + fc507302     call     0x27350
087c2 + f6           clrw     AX
087c3 + bc08         movw     [HL+0x8], AX
087c5 + 01           addw     AX, AX
087c6 + 0452c0       addw     AX, #0xc052
087c9 + 14           movw     DE, AX
087ca + a9           movw     AX, [DE]
087cb + 61490c       cmpw     AX, [HL+0xc]
087ce + df1f         bnz      0x87ef
087d0 + 30feff       movw     AX, #0xfffe
087d3 + b9           movw     [DE], AX
087d4 + f6           clrw     AX
087d5 + bc06         movw     [HL+0x6], AX
087d7 + 314d         shlw     AX, #0x4
087d9 + 320006       movw     BC, #0x600
087dc + 03           addw     AX, BC
087dd + 14           movw     DE, AX
087de + e6           onew     AX
087df + a1           incw     AX
087e0 + ba0e         movw     [DE+0xe], AX
087e2 + fcb88000     call     0x80b8
087e6 + e586c0       oneb     0xfc086
087e9 + ac0c         movw     AX, [HL+0xc]
087eb + fc507302     call     0x27350
087ef + 8c0b         mov      A, [HL+0xb]
087f1 + 318e         shrw     AX, #0x8
087f3 + fc85e000     call     0xe085
087f7 + 100e         addw     SP, #0xe
087f9 + c6           pop      HL
087fa + d7           ret      
087fb + c7           push     HL
087fc + c1           push     AX
087fd + 200e         subw     SP, #0xe
087ff + fbf8ff       movw     HL, SP
08802 + 8f54c0       mov      A, 0xfc054
08805 + 5c01         and      A, #0x1
08807 + 91           dec      A
08808 + dd05         bz       0x880f
0880a + f7           clrw     BC
0880b + ecef8800     br       0x88ef
0880f + ac0e         movw     AX, [HL+0xe]
08811 + 12           movw     BC, AX
08812 + 4100         mov      ES, #0x0
08814 + 1149be64     mov      A, ES:[BC+0x64be]
08818 + 5f55c0       and      A, 0xfc055
0881b + d1           cmp0     A
0881c + dd06         bz       0x8824
0881e + e7           onew     BC
0881f + a3           incw     BC
08820 + ecef8800     br       0x88ef
08824 + 8fe305       mov      A, 0xf05e3
08827 + 5c10         and      A, #0x10
08829 + 4c01         cmp      A, #0x1
0882b + e6           onew     AX
0882c + 6130         subc     X, A
0882e + e7           onew     BC
0882f + 43           cmpw     AX, BC
08830 + df05         bnz      0x8837
08832 + f7           clrw     BC
08833 + ecef8800     br       0x88ef
08837 + f6           clrw     AX
08838 + bc0a         movw     [HL+0xa], AX
0883a + bc08         movw     [HL+0x8], AX
0883c + fc80e000     call     0xe080
08840 + 62           mov      A, C
08841 + 9c0d         mov      [HL+0xd], A
08843 + 717bfa       clr1     PSW.7
08846 + 8f54c0       mov      A, 0xfc054
08849 + 5c01         and      A, #0x1
0884b + 91           dec      A
0884c + dd0c         bz       0x885a
0884e + 8c0d         mov      A, [HL+0xd]
08850 + 318e         shrw     AX, #0x8
08852 + fc85e000     call     0xe085
08856 + f7           clrw     BC
08857 + ee9500       br       0x88ef
0885a + ac08         movw     AX, [HL+0x8]
0885c + 01           addw     AX, AX
0885d + 12           movw     BC, AX
0885e + 7952c0       movw     AX, [BC+0xc052]
08861 + 44ffff       cmpw     AX, #0xffff
08864 + dd34         bz       0x889a
08866 + ac0e         movw     AX, [HL+0xe]
08868 + bb           movw     [HL], AX
08869 + 314e         shrw     AX, #0x4
0886b + bc04         movw     [HL+0x4], AX
0886d + 510f         mov      A, #0xf
0886f + 5d           and      A, [HL]
08870 + 318e         shrw     AX, #0x8
08872 + bc02         movw     [HL+0x2], AX
08874 + 01           addw     AX, AX
08875 + 046c64       addw     AX, #0x646c
08878 + 14           movw     DE, AX
08879 + 4100         mov      ES, #0x0
0887b + 11a9         movw     AX, ES:[DE]
0887d + 12           movw     BC, AX
0887e + ac04         movw     AX, [HL+0x4]
08880 + 01           addw     AX, AX
08881 + 0474c0       addw     AX, #0xc074
08884 + 14           movw     DE, AX
08885 + a9           movw     AX, [DE]
08886 + 616b         or       A, B
08888 + 08           xch      A, X
08889 + 616a         or       A, C
0888b + 08           xch      A, X
0888c + b9           movw     [DE], AX
0888d + 8c0d         mov      A, [HL+0xd]
0888f + 318e         shrw     AX, #0x8
08891 + fc85e000     call     0xe085
08895 + e7           onew     BC
08896 + ef57         br       0x88ef
0889a + ac08         movw     AX, [HL+0x8]
0889c + 01           addw     AX, AX
0889d + 12           movw     BC, AX
0889e + 7952c0       movw     AX, [BC+0xc052]
088a1 + 44ffff       cmpw     AX, #0xffff
088a4 + df14         bnz      0x88ba
088a6 + ac0a         movw     AX, [HL+0xa]
088a8 + 314d         shlw     AX, #0x4
088aa + 320006       movw     BC, #0x600
088ad + 03           addw     AX, BC
088ae + 14           movw     DE, AX
088af + aa0e         movw     AX, [DE+0xe]
088b1 + f1           clrb     A
088b2 + 08           xch      A, X
088b3 + 5c03         and      A, #0x3
088b5 + 08           xch      A, X
088b6 + 6168         or       A, X
088b8 + dd0b         bz       0x88c5
088ba + 8c0d         mov      A, [HL+0xd]
088bc + 318e         shrw     AX, #0x8
088be + fc85e000     call     0xe085
088c2 + f7           clrw     BC
088c3 + ef2a         br       0x88ef
088c5 + ac08         movw     AX, [HL+0x8]
088c7 + 01           addw     AX, AX
088c8 + 12           movw     BC, AX
088c9 + ac0e         movw     AX, [HL+0xe]
088cb + 7852c0       movw     [BC+0xc052], AX
088ce + 8c0d         mov      A, [HL+0xd]
088d0 + 318e         shrw     AX, #0x8
088d2 + fc85e000     call     0xe085
088d6 + ac0e         movw     AX, [HL+0xe]
088d8 + c1           push     AX
088d9 + ac0a         movw     AX, [HL+0xa]
088db + fcf38800     call     0x88f3
088df + c0           pop      AX
088e0 + 62           mov      A, C
088e1 + 9c07         mov      [HL+0x7], A
088e3 + 4c05         cmp      A, #0x5
088e5 + 61f8         sknz     
088e7 + cc0700       mov      [HL+0x7], #0x0
088ea + 8c07         mov      A, [HL+0x7]
088ec + 318e         shrw     AX, #0x8
088ee + 12           movw     BC, AX
088ef + 1010         addw     SP, #0x10
088f1 + c6           pop      HL
088f2 + d7           ret      
088f3   c7           push     HL
088f4   c1           push     AX
088f5   200c         subw     SP, #0xc
088f7   fbf8ff       movw     HL, SP
088fa   ac0c         movw     AX, [HL+0xc]
088fc   bc08         movw     [HL+0x8], AX
088fe   314d         shlw     AX, #0x4
08900   320006       movw     BC, #0x600
08903   03           addw     AX, BC
08904   bb           movw     [HL], AX
08905   8fe305       mov      A, 0xf05e3
08908   5c10         and      A, #0x10
0890a   4c01         cmp      A, #0x1
0890c   e6           onew     AX
0890d   6130         subc     X, A
0890f   e7           onew     BC
08910   43           cmpw     AX, BC
08911   df0e         bnz      0x8921
08913   ac0c         movw     AX, [HL+0xc]
08915   01           addw     AX, AX
08916   12           movw     BC, AX
08917   f6           clrw     AX
08918   b1           decw     AX
08919   7852c0       movw     [BC+0xc052], AX
0891c   f7           clrw     BC
0891d   ecf28900     br       0x89f2
08921   ac14         movw     AX, [HL+0x14]
08923   01           addw     AX, AX
08924   12           movw     BC, AX
08925   4100         mov      ES, #0x0
08927   1179ac64     movw     AX, ES:[BC+0x64ac]
0892b   12           movw     BC, AX
0892c   ab           movw     AX, [HL]
0892d   14           movw     DE, AX
0892e   13           movw     AX, BC
0892f   ba0c         movw     [DE+0xc], AX
08931   ac14         movw     AX, [HL+0x14]
08933   12           movw     BC, AX
08934   4100         mov      ES, #0x0
08936   1149b064     mov      A, ES:[BC+0x64b0]
0893a   72           mov      C, A
0893b   ab           movw     AX, [HL]
0893c   14           movw     DE, AX
0893d   62           mov      A, C
0893e   9a08         mov      [DE+0x8], A
08940   ac14         movw     AX, [HL+0x14]
08942   01           addw     AX, AX
08943   12           movw     BC, AX
08944   4100         mov      ES, #0x0
08946   1179b264     movw     AX, ES:[BC+0x64b2]
0894a   bc06         movw     [HL+0x6], AX
0894c   f6           clrw     AX
0894d   614906       cmpw     AX, [HL+0x6]
08950   61f8         sknz     
08952   ec988900     br       0x8998
08956   fc80e000     call     0xe080
0895a   62           mov      A, C
0895b   9c0b         mov      [HL+0xb], A
0895d   717bfa       clr1     PSW.7
08960   f6           clrw     AX
08961   bc02         movw     [HL+0x2], AX
08963   bc04         movw     [HL+0x4], AX
08965   f6           clrw     AX
08966   614904       cmpw     AX, [HL+0x4]
08969   df05         bnz      0x8970
0896b   5007         mov      X, #0x7
0896d   614902       cmpw     AX, [HL+0x2]
08970   dc1e         bc       0x8990
08972   ac02         movw     AX, [HL+0x2]
08974   610906       addw     AX, [HL+0x6]
08977   14           movw     DE, AX
08978   89           mov      A, [DE]
08979   72           mov      C, A
0897a   ab           movw     AX, [HL]
0897b   14           movw     DE, AX
0897c   ac02         movw     AX, [HL+0x2]
0897e   05           addw     AX, DE
0897f   14           movw     DE, AX
08980   62           mov      A, C
08981   99           mov      [DE], A
08982   617902       incw     [HL+0x2]
08985   f6           clrw     AX
08986   614902       cmpw     AX, [HL+0x2]
08989   61f8         sknz     
0898b   617904       incw     [HL+0x4]
0898e   efd5         br       0x8965
08990   8c0b         mov      A, [HL+0xb]
08992   318e         shrw     AX, #0x8
08994   fc85e000     call     0xe085
08998   fc80e000     call     0xe080
0899c   62           mov      A, C
0899d   9c0b         mov      [HL+0xb], A
0899f   717bfa       clr1     PSW.7
089a2   ac08         movw     AX, [HL+0x8]
089a4   01           addw     AX, AX
089a5   12           movw     BC, AX
089a6   7952c0       movw     AX, [BC+0xc052]
089a9   614914       cmpw     AX, [HL+0x14]
089ac   df1a         bnz      0x89c8
089ae   8f54c0       mov      A, 0xfc054
089b1   5c01         and      A, #0x1
089b3   91           dec      A
089b4   df12         bnz      0x89c8
089b6   ab           movw     AX, [HL]
089b7   14           movw     DE, AX
089b8   f0           clrb     X
089b9   e1           oneb     A
089ba   ba0e         movw     [DE+0xe], AX
089bc   ab           movw     AX, [HL]
089bd   14           movw     DE, AX
089be   300002       movw     AX, #0x200
089c1   ba0e         movw     [DE+0xe], AX
089c3   cc0a01       mov      [HL+0xa], #0x1
089c6   ef1d         br       0x89e5
089c8   ac08         movw     AX, [HL+0x8]
089ca   01           addw     AX, AX
089cb   12           movw     BC, AX
089cc   7952c0       movw     AX, [BC+0xc052]
089cf   614914       cmpw     AX, [HL+0x14]
089d2   df05         bnz      0x89d9
089d4   cc0a05       mov      [HL+0xa], #0x5
089d7   ef03         br       0x89dc
089d9   cc0a00       mov      [HL+0xa], #0x0
089dc   ac08         movw     AX, [HL+0x8]
089de   01           addw     AX, AX
089df   12           movw     BC, AX
089e0   f6           clrw     AX
089e1   b1           decw     AX
089e2   7852c0       movw     [BC+0xc052], AX
089e5   8c0b         mov      A, [HL+0xb]
089e7   318e         shrw     AX, #0x8
089e9   fc85e000     call     0xe085
089ed   8c0a         mov      A, [HL+0xa]
089ef   318e         shrw     AX, #0x8
089f1   12           movw     BC, AX
089f2   100e         addw     SP, #0xe
089f4   c6           pop      HL
089f5   d7           ret      
08bd1   afe805       movw     AX, 0xf05e8
08bd4   f1           clrb     A
08bd5   08           xch      A, X
08bd6   5c1c         and      A, #0x1c
08bd8   08           xch      A, X
08bd9   6168         or       A, X
08bdb   dd30         bz       0x8c0d
08bdd   afe805       movw     AX, 0xf05e8
08be0   f1           clrb     A
08be1   08           xch      A, X
08be2   5c18         and      A, #0x18
08be4   08           xch      A, X
08be5   6168         or       A, X
08be7   dd06         bz       0x8bef
08be9   301800       movw     AX, #0x18
08bec   bfe805       movw     0xf05e8, AX
08bef   afe805       movw     AX, 0xf05e8
08bf2   f1           clrb     A
08bf3   08           xch      A, X
08bf4   5c04         and      A, #0x4
08bf6   08           xch      A, X
08bf7   6168         or       A, X
08bf9   dd06         bz       0x8c01
08bfb   300400       movw     AX, #0x4
08bfe   bfe805       movw     0xf05e8, AX
08c01   8fe305       mov      A, 0xf05e3
08c04   5c10         and      A, #0x10
08c06   d1           cmp0     A
08c07   61e8         skz      
08c09   fcbe8000     call     0x80be
08c0d   d7           ret      
08c0e   c7           push     HL
08c0f   c1           push     AX
08c10   2006         subw     SP, #0x6
08c12   fbf8ff       movw     HL, SP
08c15   f6           clrw     AX
08c16   b1           decw     AX
08c17   bb           movw     [HL], AX
08c18   ac06         movw     AX, [HL+0x6]
08c1a   fcd38000     call     0x80d3
08c1e   306ac0       movw     AX, #0xc06a
08c21   bc04         movw     [HL+0x4], AX
08c23   14           movw     DE, AX
08c24   3076c0       movw     AX, #0xc076
08c27   ba04         movw     [DE+0x4], AX
08c29   ac04         movw     AX, [HL+0x4]
08c2b   14           movw     DE, AX
08c2c   3076c0       movw     AX, #0xc076
08c2f   ba06         movw     [DE+0x6], AX
08c31   ac04         movw     AX, [HL+0x4]
08c33   14           movw     DE, AX
08c34   f6           clrw     AX
08c35   b1           decw     AX
08c36   ba08         movw     [DE+0x8], AX
08c38   ac04         movw     AX, [HL+0x4]
08c3a   14           movw     DE, AX
08c3b   aa04         movw     AX, [DE+0x4]
08c3d   040c00       addw     AX, #0xc
08c40   14           movw     DE, AX
08c41   89           mov      A, [DE]
08c42   5c00         and      A, #0x0
08c44   08           xch      A, X
08c45   8a01         mov      A, [DE+0x1]
08c47   5c80         and      A, #0x80
08c49   bdd8         movw     0xffed8, AX
08c4b   f6           clrw     AX
08c4c   bdda         movw     0xffeda, AX
08c4e   5110         mov      A, #0x10
08c50   fd7106       call     0x671
08c53   f6           clrw     AX
08c54   46da         cmpw     AX, 0xffeda
08c56   61f8         sknz     
08c58   46d8         cmpw     AX, 0xffed8
08c5a   df56         bnz      0x8cb2
08c5c   ac04         movw     AX, [HL+0x4]
08c5e   fc4f8000     call     0x804f
08c62   d2           cmp0     C
08c63   dd4d         bz       0x8cb2
08c65   ac04         movw     AX, [HL+0x4]
08c67   14           movw     DE, AX
08c68   aa04         movw     AX, [DE+0x4]
08c6a   040c00       addw     AX, #0xc
08c6d   14           movw     DE, AX
08c6e   89           mov      A, [DE]
08c6f   5cfc         and      A, #0xfc
08c71   08           xch      A, X
08c72   8a01         mov      A, [DE+0x1]
08c74   5c1f         and      A, #0x1f
08c76   08           xch      A, X
08c77   5cfc         and      A, #0xfc
08c79   08           xch      A, X
08c7a   bc02         movw     [HL+0x2], AX
08c7c   f6           clrw     AX
08c7d   bb           movw     [HL], AX
08c7e   f6           clrw     AX
08c7f   614900       cmpw     AX, [HL]
08c82   df13         bnz      0x8c97
08c84   ab           movw     AX, [HL]
08c85   01           addw     AX, AX
08c86   12           movw     BC, AX
08c87   4100         mov      ES, #0x0
08c89   1179c464     movw     AX, ES:[BC+0x64c4]
08c8d   614902       cmpw     AX, [HL+0x2]
08c90   dd05         bz       0x8c97
08c92   617900       incw     [HL]
08c95   efe7         br       0x8c7e
08c97   f6           clrw     AX
08c98   614900       cmpw     AX, [HL]
08c9b   df15         bnz      0x8cb2
08c9d   ab           movw     AX, [HL]
08c9e   01           addw     AX, AX
08c9f   12           movw     BC, AX
08ca0   4100         mov      ES, #0x0
08ca2   1179d064     movw     AX, ES:[BC+0x64d0]
08ca6   bb           movw     [HL], AX
08ca7   ac04         movw     AX, [HL+0x4]
08ca9   14           movw     DE, AX
08caa   ab           movw     AX, [HL]
08cab   ba08         movw     [DE+0x8], AX
08cad   fc208d00     call     0x8d20
08cb1   92           dec      C
08cb2   1008         addw     SP, #0x8
08cb4   c6           pop      HL
08cb5   d7           ret      
08cb6   c7           push     HL
08cb7   c1           push     AX
08cb8   2004         subw     SP, #0x4
08cba   fbf8ff       movw     HL, SP
08cbd   ac04         movw     AX, [HL+0x4]
08cbf   fcd38000     call     0x80d3
08cc3   306ac0       movw     AX, #0xc06a
08cc6   bb           movw     [HL], AX
08cc7   14           movw     DE, AX
08cc8   3076c0       movw     AX, #0xc076
08ccb   ba04         movw     [DE+0x4], AX
08ccd   ab           movw     AX, [HL]
08cce   14           movw     DE, AX
08ccf   3076c0       movw     AX, #0xc076
08cd2   ba06         movw     [DE+0x6], AX
08cd4   ab           movw     AX, [HL]
08cd5   14           movw     DE, AX
08cd6   aa04         movw     AX, [DE+0x4]
08cd8   040c00       addw     AX, #0xc
08cdb   14           movw     DE, AX
08cdc   89           mov      A, [DE]
08cdd   5c00         and      A, #0x0
08cdf   08           xch      A, X
08ce0   8a01         mov      A, [DE+0x1]
08ce2   5c80         and      A, #0x80
08ce4   bdd8         movw     0xffed8, AX
08ce6   f6           clrw     AX
08ce7   bdda         movw     0xffeda, AX
08ce9   5110         mov      A, #0x10
08ceb   fd7106       call     0x671
08cee   f6           clrw     AX
08cef   46da         cmpw     AX, 0xffeda
08cf1   61f8         sknz     
08cf3   46d8         cmpw     AX, 0xffed8
08cf5   df25         bnz      0x8d1c
08cf7   ab           movw     AX, [HL]
08cf8   fc4f8000     call     0x804f
08cfc   d2           cmp0     C
08cfd   dd1d         bz       0x8d1c
08cff   ac04         movw     AX, [HL+0x4]
08d01   240900       subw     AX, #0x9
08d04   a1           incw     AX
08d05   bc02         movw     [HL+0x2], AX
08d07   01           addw     AX, AX
08d08   12           movw     BC, AX
08d09   4100         mov      ES, #0x0
08d0b   1179d064     movw     AX, ES:[BC+0x64d0]
08d0f   bc02         movw     [HL+0x2], AX
08d11   ab           movw     AX, [HL]
08d12   14           movw     DE, AX
08d13   ac02         movw     AX, [HL+0x2]
08d15   ba08         movw     [DE+0x8], AX
08d17   fc208d00     call     0x8d20
08d1b   92           dec      C
08d1c   1006         addw     SP, #0x6
08d1e   c6           pop      HL
08d1f   d7           ret      
08d20   c7           push     HL
08d21   2008         subw     SP, #0x8
08d23   fbf8ff       movw     HL, SP
08d26   306ac0       movw     AX, #0xc06a
08d29   bc06         movw     [HL+0x6], AX
08d2b   14           movw     DE, AX
08d2c   aa08         movw     AX, [DE+0x8]
08d2e   12           movw     BC, AX
08d2f   4100         mov      ES, #0x0
08d31   11493065     mov      A, ES:[BC+0x6530]
08d35   72           mov      C, A
08d36   ac06         movw     AX, [HL+0x6]
08d38   14           movw     DE, AX
08d39   aa04         movw     AX, [DE+0x4]
08d3b   14           movw     DE, AX
08d3c   8a08         mov      A, [DE+0x8]
08d3e   614a         cmp      A, C
08d40   de05         bnc      0x8d47
08d42   f7           clrw     BC
08d43   ec268e00     br       0x8e26
08d47   ac06         movw     AX, [HL+0x6]
08d49   14           movw     DE, AX
08d4a   aa04         movw     AX, [DE+0x4]
08d4c   14           movw     DE, AX
08d4d   8a08         mov      A, [DE+0x8]
08d4f   318e         shrw     AX, #0x8
08d51   c1           push     AX
08d52   ac06         movw     AX, [HL+0x6]
08d54   14           movw     DE, AX
08d55   aa08         movw     AX, [DE+0x8]
08d57   fc549200     call     0x9254
08d5b   c0           pop      AX
08d5c   ac06         movw     AX, [HL+0x6]
08d5e   fc7f7302     call     0x2737f
08d62   92           dec      C
08d63   dd05         bz       0x8d6a
08d65   f7           clrw     BC
08d66   ec268e00     br       0x8e26
08d6a   ac06         movw     AX, [HL+0x6]
08d6c   14           movw     DE, AX
08d6d   aa08         movw     AX, [DE+0x8]
08d6f   312d         shlw     AX, #0x2
08d71   04ee64       addw     AX, #0x64ee
08d74   14           movw     DE, AX
08d75   4100         mov      ES, #0x0
08d77   118a02       mov      A, ES:[DE+0x2]
08d7a   9dd4         mov      0xffed4, A
08d7c   11a9         movw     AX, ES:[DE]
08d7e   d4d4         cmp0     0xffed4
08d80   df02         bnz      0x8d84
08d82   f7           clrw     BC
08d83   43           cmpw     AX, BC
08d84   dd26         bz       0x8dac
08d86   ac06         movw     AX, [HL+0x6]
08d88   14           movw     DE, AX
08d89   aa08         movw     AX, [DE+0x8]
08d8b   bf46c0       movw     0xfc046, AX
08d8e   aa08         movw     AX, [DE+0x8]
08d90   312d         shlw     AX, #0x2
08d92   04ee64       addw     AX, #0x64ee
08d95   14           movw     DE, AX
08d96   4100         mov      ES, #0x0
08d98   118a02       mov      A, ES:[DE+0x2]
08d9b   9efc         mov      CS, A
08d9d   11a9         movw     AX, ES:[DE]
08d9f   14           movw     DE, AX
08da0   ac06         movw     AX, [HL+0x6]
08da2   61ea         call     DE
08da4   d2           cmp0     C
08da5   df05         bnz      0x8dac
08da7   f7           clrw     BC
08da8   ec268e00     br       0x8e26
08dac   ac06         movw     AX, [HL+0x6]
08dae   14           movw     DE, AX
08daf   aa08         movw     AX, [DE+0x8]
08db1   01           addw     AX, AX
08db2   04e264       addw     AX, #0x64e2
08db5   14           movw     DE, AX
08db6   4100         mov      ES, #0x0
08db8   11a9         movw     AX, ES:[DE]
08dba   6168         or       A, X
08dbc   61f8         sknz     
08dbe   ec258e00     br       0x8e25
08dc2   fc80e000     call     0xe080
08dc6   62           mov      A, C
08dc7   9c05         mov      [HL+0x5], A
08dc9   717bfa       clr1     PSW.7
08dcc   f6           clrw     AX
08dcd   bb           movw     [HL], AX
08dce   bc02         movw     [HL+0x2], AX
08dd0   ac06         movw     AX, [HL+0x6]
08dd2   14           movw     DE, AX
08dd3   aa08         movw     AX, [DE+0x8]
08dd5   12           movw     BC, AX
08dd6   4100         mov      ES, #0x0
08dd8   1149dc64     mov      A, ES:[BC+0x64dc]
08ddc   9dd8         mov      0xffed8, A
08dde   f4d9         clrb     0xffed9
08de0   f6           clrw     AX
08de1   bdda         movw     0xffeda, AX
08de3   ac02         movw     AX, [HL+0x2]
08de5   46da         cmpw     AX, 0xffeda
08de7   ab           movw     AX, [HL]
08de8   61f8         sknz     
08dea   46d8         cmpw     AX, 0xffed8
08dec   de2f         bnc      0x8e1d
08dee   ac06         movw     AX, [HL+0x6]
08df0   14           movw     DE, AX
08df1   ab           movw     AX, [HL]
08df2   12           movw     BC, AX
08df3   aa06         movw     AX, [DE+0x6]
08df5   03           addw     AX, BC
08df6   14           movw     DE, AX
08df7   89           mov      A, [DE]
08df8   72           mov      C, A
08df9   ac06         movw     AX, [HL+0x6]
08dfb   14           movw     DE, AX
08dfc   aa08         movw     AX, [DE+0x8]
08dfe   01           addw     AX, AX
08dff   04e264       addw     AX, #0x64e2
08e02   14           movw     DE, AX
08e03   ab           movw     AX, [HL]
08e04   4100         mov      ES, #0x0
08e06   c3           push     BC
08e07   12           movw     BC, AX
08e08   11a9         movw     AX, ES:[DE]
08e0a   03           addw     AX, BC
08e0b   c2           pop      BC
08e0c   14           movw     DE, AX
08e0d   62           mov      A, C
08e0e   99           mov      [DE], A
08e0f   617900       incw     [HL]
08e12   f6           clrw     AX
08e13   614900       cmpw     AX, [HL]
08e16   61f8         sknz     
08e18   617902       incw     [HL+0x2]
08e1b   efb3         br       0x8dd0
08e1d   8c05         mov      A, [HL+0x5]
08e1f   318e         shrw     AX, #0x8
08e21   fc85e000     call     0xe085
08e25   e7           onew     BC
08e26   1008         addw     SP, #0x8
08e28   c6           pop      HL
08e29   d7           ret      
08e2a   c7           push     HL
08e2b   c1           push     AX
08e2c   200e         subw     SP, #0xe
08e2e   fbf8ff       movw     HL, SP
08e31   ac0e         movw     AX, [HL+0xe]
08e33   bc0c         movw     [HL+0xc], AX
08e35   01           addw     AX, AX
08e36   0452c0       addw     AX, #0xc052
08e39   14           movw     DE, AX
08e3a   a9           movw     AX, [DE]
08e3b   bc0a         movw     [HL+0xa], AX
08e3d   ac0e         movw     AX, [HL+0xe]
08e3f   314d         shlw     AX, #0x4
08e41   320006       movw     BC, #0x600
08e44   03           addw     AX, BC
08e45   bb           movw     [HL], AX
08e46   ab           movw     AX, [HL]
08e47   14           movw     DE, AX
08e48   e6           onew     AX
08e49   ba0e         movw     [DE+0xe], AX
08e4b   ab           movw     AX, [HL]
08e4c   14           movw     DE, AX
08e4d   aa0e         movw     AX, [DE+0xe]
08e4f   f1           clrb     A
08e50   08           xch      A, X
08e51   5c01         and      A, #0x1
08e53   08           xch      A, X
08e54   6168         or       A, X
08e56   dfee         bnz      0x8e46
08e58   f6           clrw     AX
08e59   b1           decw     AX
08e5a   61490a       cmpw     AX, [HL+0xa]
08e5d   61f8         sknz     
08e5f   ec0c9000     br       0x900c
08e63   30feff       movw     AX, #0xfffe
08e66   61490a       cmpw     AX, [HL+0xa]
08e69   61f8         sknz     
08e6b   ecce8e00     br       0x8ece
08e6f   fc80e000     call     0xe080
08e73   62           mov      A, C
08e74   9c03         mov      [HL+0x3], A
08e76   717bfa       clr1     PSW.7
08e79   ac0a         movw     AX, [HL+0xa]
08e7b   12           movw     BC, AX
08e7c   4100         mov      ES, #0x0
08e7e   1149c264     mov      A, ES:[BC+0x64c2]
08e82   72           mov      C, A
08e83   ac0a         movw     AX, [HL+0xa]
08e85   04c064       addw     AX, #0x64c0
08e88   14           movw     DE, AX
08e89   4100         mov      ES, #0x0
08e8b   1189         mov      A, ES:[DE]
08e8d   318e         shrw     AX, #0x8
08e8f   0448c0       addw     AX, #0xc048
08e92   14           movw     DE, AX
08e93   89           mov      A, [DE]
08e94   616a         or       A, C
08e96   99           mov      [DE], A
08e97   8c03         mov      A, [HL+0x3]
08e99   318e         shrw     AX, #0x8
08e9b   fc85e000     call     0xe085
08e9f   ac0a         movw     AX, [HL+0xa]
08ea1   312d         shlw     AX, #0x2
08ea3   04b664       addw     AX, #0x64b6
08ea6   14           movw     DE, AX
08ea7   4100         mov      ES, #0x0
08ea9   118a02       mov      A, ES:[DE+0x2]
08eac   9dd4         mov      0xffed4, A
08eae   11a9         movw     AX, ES:[DE]
08eb0   d4d4         cmp0     0xffed4
08eb2   df02         bnz      0x8eb6
08eb4   f7           clrw     BC
08eb5   43           cmpw     AX, BC
08eb6   dd16         bz       0x8ece
08eb8   ac0a         movw     AX, [HL+0xa]
08eba   312d         shlw     AX, #0x2
08ebc   04b664       addw     AX, #0x64b6
08ebf   14           movw     DE, AX
08ec0   4100         mov      ES, #0x0
08ec2   118a02       mov      A, ES:[DE+0x2]
08ec5   9efc         mov      CS, A
08ec7   11a9         movw     AX, ES:[DE]
08ec9   14           movw     DE, AX
08eca   ac0a         movw     AX, [HL+0xa]
08ecc   61ea         call     DE
08ece   fc80e000     call     0xe080
08ed2   62           mov      A, C
08ed3   9c03         mov      [HL+0x3], A
08ed5   717bfa       clr1     PSW.7
08ed8   f6           clrw     AX
08ed9   bc08         movw     [HL+0x8], AX
08edb   8c09         mov      A, [HL+0x9]
08edd   01           addw     AX, AX
08ede   61d8         sknc     
08ee0   ecfb8f00     br       0x8ffb
08ee4   ac08         movw     AX, [HL+0x8]
08ee6   01           addw     AX, AX
08ee7   0474c0       addw     AX, #0xc074
08eea   14           movw     DE, AX
08eeb   a9           movw     AX, [DE]
08eec   bc04         movw     [HL+0x4], AX
08eee   f6           clrw     AX
08eef   614904       cmpw     AX, [HL+0x4]
08ef2   61f8         sknz     
08ef4   ecf48f00     br       0x8ff4
08ef8   8c03         mov      A, [HL+0x3]
08efa   318e         shrw     AX, #0x8
08efc   fc85e000     call     0xe085
08f00   8c04         mov      A, [HL+0x4]
08f02   5c00         and      A, #0x0
08f04   70           mov      X, A
08f05   8c05         mov      A, [HL+0x5]
08f07   6168         or       A, X
08f09   dd33         bz       0x8f3e
08f0b   8c04         mov      A, [HL+0x4]
08f0d   5c00         and      A, #0x0
08f0f   70           mov      X, A
08f10   8c05         mov      A, [HL+0x5]
08f12   5cf0         and      A, #0xf0
08f14   6168         or       A, X
08f16   dd14         bz       0x8f2c
08f18   ac04         movw     AX, [HL+0x4]
08f1a   31ce         shrw     AX, #0xc
08f1c   12           movw     BC, AX
08f1d   4100         mov      ES, #0x0
08f1f   11498c64     mov      A, ES:[BC+0x648c]
08f23   318f         sarw     AX, #0x8
08f25   040c00       addw     AX, #0xc
08f28   bc06         movw     [HL+0x6], AX
08f2a   ef10         br       0x8f3c
08f2c   ac04         movw     AX, [HL+0x4]
08f2e   73           mov      B, A
08f2f   4100         mov      ES, #0x0
08f31   11098c64     mov      A, ES:[B+0x648c]
08f35   318f         sarw     AX, #0x8
08f37   040800       addw     AX, #0x8
08f3a   bc06         movw     [HL+0x6], AX
08f3c   ef2b         br       0x8f69
08f3e   51f0         mov      A, #0xf0
08f40   5e04         and      A, [HL+0x4]
08f42   318e         shrw     AX, #0x8
08f44   6168         or       A, X
08f46   dd14         bz       0x8f5c
08f48   ac04         movw     AX, [HL+0x4]
08f4a   314e         shrw     AX, #0x4
08f4c   12           movw     BC, AX
08f4d   4100         mov      ES, #0x0
08f4f   11498c64     mov      A, ES:[BC+0x648c]
08f53   318f         sarw     AX, #0x8
08f55   040400       addw     AX, #0x4
08f58   bc06         movw     [HL+0x6], AX
08f5a   ef0d         br       0x8f69
08f5c   ac04         movw     AX, [HL+0x4]
08f5e   12           movw     BC, AX
08f5f   4100         mov      ES, #0x0
08f61   11498c64     mov      A, ES:[BC+0x648c]
08f65   318f         sarw     AX, #0x8
08f67   bc06         movw     [HL+0x6], AX
08f69   ac08         movw     AX, [HL+0x8]
08f6b   314d         shlw     AX, #0x4
08f6d   610906       addw     AX, [HL+0x6]
08f70   bc0a         movw     [HL+0xa], AX
08f72   fc80e000     call     0xe080
08f76   62           mov      A, C
08f77   9c03         mov      [HL+0x3], A
08f79   717bfa       clr1     PSW.7
08f7c   ac08         movw     AX, [HL+0x8]
08f7e   01           addw     AX, AX
08f7f   0474c0       addw     AX, #0xc074
08f82   14           movw     DE, AX
08f83   a9           movw     AX, [DE]
08f84   12           movw     BC, AX
08f85   ac06         movw     AX, [HL+0x6]
08f87   01           addw     AX, AX
08f88   046c64       addw     AX, #0x646c
08f8b   14           movw     DE, AX
08f8c   4100         mov      ES, #0x0
08f8e   1189         mov      A, ES:[DE]
08f90   615a         and      A, C
08f92   08           xch      A, X
08f93   118a01       mov      A, ES:[DE+0x1]
08f96   615b         and      A, B
08f98   6168         or       A, X
08f9a   dd45         bz       0x8fe1
08f9c   ac06         movw     AX, [HL+0x6]
08f9e   01           addw     AX, AX
08f9f   046c64       addw     AX, #0x646c
08fa2   14           movw     DE, AX
08fa3   11a9         movw     AX, ES:[DE]
08fa5   12           movw     BC, AX
08fa6   f6           clrw     AX
08fa7   b1           decw     AX
08fa8   23           subw     AX, BC
08fa9   12           movw     BC, AX
08faa   ac08         movw     AX, [HL+0x8]
08fac   01           addw     AX, AX
08fad   0474c0       addw     AX, #0xc074
08fb0   14           movw     DE, AX
08fb1   a9           movw     AX, [DE]
08fb2   615b         and      A, B
08fb4   08           xch      A, X
08fb5   615a         and      A, C
08fb7   08           xch      A, X
08fb8   b9           movw     [DE], AX
08fb9   8c03         mov      A, [HL+0x3]
08fbb   318e         shrw     AX, #0x8
08fbd   fc85e000     call     0xe085
08fc1   ac0c         movw     AX, [HL+0xc]
08fc3   01           addw     AX, AX
08fc4   12           movw     BC, AX
08fc5   ac0a         movw     AX, [HL+0xa]
08fc7   7852c0       movw     [BC+0xc052], AX
08fca   c1           push     AX
08fcb   ac0e         movw     AX, [HL+0xe]
08fcd   fcf38800     call     0x88f3
08fd1   c0           pop      AX
08fd2   62           mov      A, C
08fd3   9c02         mov      [HL+0x2], A
08fd5   4c05         cmp      A, #0x5
08fd7   df06         bnz      0x8fdf
08fd9   ac0a         movw     AX, [HL+0xa]
08fdb   fc507302     call     0x27350
08fdf   ef2b         br       0x900c
08fe1   ac0c         movw     AX, [HL+0xc]
08fe3   01           addw     AX, AX
08fe4   12           movw     BC, AX
08fe5   f6           clrw     AX
08fe6   b1           decw     AX
08fe7   7852c0       movw     [BC+0xc052], AX
08fea   8c03         mov      A, [HL+0x3]
08fec   318e         shrw     AX, #0x8
08fee   fc85e000     call     0xe085
08ff2   ef18         br       0x900c
08ff4   618908       decw     [HL+0x8]
08ff7   ecdb8e00     br       0x8edb
08ffb   ac0c         movw     AX, [HL+0xc]
08ffd   01           addw     AX, AX
08ffe   12           movw     BC, AX
08fff   f6           clrw     AX
09000   b1           decw     AX
09001   7852c0       movw     [BC+0xc052], AX
09004   8c03         mov      A, [HL+0x3]
09006   318e         shrw     AX, #0x8
09008   fc85e000     call     0xe085
0900c   1010         addw     SP, #0x10
0900e   c6           pop      HL
0900f   d7           ret      
09254   c7           push     HL
09255   c1           push     AX
09256   fbf8ff       movw     HL, SP
09259   ab           movw     AX, [HL]
0925a   12           movw     BC, AX
0925b   4100         mov      ES, #0x0
0925d   1149dc64     mov      A, ES:[BC+0x64dc]
09261   4e08         cmp      A, [HL+0x8]
09263   61d307       bnh      0x926d
09266   8c08         mov      A, [HL+0x8]
09268   4849c0       mov      [BC+0xc049], A
0926b   ef0e         br       0x927b
0926d   ab           movw     AX, [HL]
0926e   12           movw     BC, AX
0926f   4100         mov      ES, #0x0
09271   1149dc64     mov      A, ES:[BC+0x64dc]
09275   73           mov      B, A
09276   ab           movw     AX, [HL]
09277   33           xchw     AX, BC
09278   4849c0       mov      [BC+0xc049], A
0927b   c0           pop      AX
0927c   c6           pop      HL
0927d   d7           ret      
0927e + c7           push     HL
0927f + c1           push     AX
09280 + fbf8ff       movw     HL, SP
09283 + effe         br       0x9283
0a376 + c7           push     HL
0a377 + c1           push     AX
0a378 + 2004         subw     SP, #0x4
0a37a + fbf8ff       movw     HL, SP
0a37d + f6           clrw     AX
0a37e + bc02         movw     [HL+0x2], AX
0a380 + 408fc0ff     cmp      0xfc08f, #0xff
0a384 + df36         bnz      0xa3bc
0a386 + ac04         movw     AX, [HL+0x4]
0a388 + 449903       cmpw     AX, #0x399
0a38b + dc09         bc       0xa396
0a38d + 300300       movw     AX, #0x3
0a390 + fc6dde00     call     0xde6d
0a394 + ef26         br       0xa3bc
0a396 + e58ac0       oneb     0xfc08a
0a399 + f58cc0       clrb     0xfc08c
0a39c + ac04         movw     AX, [HL+0x4]
0a39e + bf90c0       movw     0xfc090, AX
0a3a1 + f58fc0       clrb     0xfc08f
0a3a4 + 3088c0       movw     AX, #0xc088
0a3a7 + fc25a700     call     0xa725
0a3ab + 62           mov      A, C
0a3ac + 9c01         mov      [HL+0x1], A
0a3ae + d1           cmp0     A
0a3af + df07         bnz      0xa3b8
0a3b1 + af92c0       movw     AX, 0xfc092
0a3b4 + bc02         movw     [HL+0x2], AX
0a3b6 + ef04         br       0xa3bc
0a3b8 + cf8fc0ff     mov      0xfc08f, #0xff
0a3bc + ac02         movw     AX, [HL+0x2]
0a3be + 12           movw     BC, AX
0a3bf + 1006         addw     SP, #0x6
0a3c1 + c6           pop      HL
0a3c2 + d7           ret      
0a3c3 + c7           push     HL
0a3c4 + 16           movw     HL, AX
0a3c5 + f6           clrw     AX
0a3c6 + c1           push     AX
0a3c7 + 3088c0       movw     AX, #0xc088
0a3ca + fc9ca700     call     0xa79c
0a3ce + c0           pop      AX
0a3cf + fc62de00     call     0xde62
0a3d3 + c6           pop      HL
0a3d4 + d7           ret      
0a3d5 + c7           push     HL
0a3d6 + 16           movw     HL, AX
0a3d7 + 300300       movw     AX, #0x3
0a3da + c1           push     AX
0a3db + 3088c0       movw     AX, #0xc088
0a3de + fc9ca700     call     0xa79c
0a3e2 + c0           pop      AX
0a3e3 + c6           pop      HL
0a3e4 + d7           ret      
0a497 + c7           push     HL
0a498 + 16           movw     HL, AX
0a499 + 66           mov      A, L
0a49a + d1           cmp0     A
0a49b + dd04         bz       0xa4a1
0a49d + 5103         mov      A, #0x3
0a49f + ef01         br       0xa4a2
0a4a1 + f1           clrb     A
0a4a2 + 318f         sarw     AX, #0x8
0a4a4 + c1           push     AX
0a4a5 + af96c0       movw     AX, 0xfc096
0a4a8 + fcd6a700     call     0xa7d6
0a4ac + c0           pop      AX
0a4ad + f6           clrw     AX
0a4ae + bf96c0       movw     0xfc096, AX
0a4b1 + c6           pop      HL
0a4b2 + d7           ret      
0a4b3 + c7           push     HL
0a4b4 + 16           movw     HL, AX
0a4b5 + 17           movw     AX, HL
0a4b6 + f1           clrb     A
0a4b7 + fc97a400     call     0xa497
0a4bb + f7           clrw     BC
0a4bc + c6           pop      HL
0a4bd + d7           ret      
0a4be + c7           push     HL
0a4bf + 16           movw     HL, AX
0a4c0 + 8c02         mov      A, [HL+0x2]
0a4c2 + 91           dec      A
0a4c3 + dd0c         bz       0xa4d1
0a4c5 + 30f80a       movw     AX, #0xaf8
0a4c8 + c1           push     AX
0a4c9 + 304200       movw     AX, #0x42
0a4cc + fc7e9200     call     0x927e
0a4d0 + c0           pop      AX
0a4d1 + 17           movw     AX, HL
0a4d2 + 14           movw     DE, AX
0a4d3 + ca07ff       mov      [DE+0x7], #0xff
0a4d6 + c6           pop      HL
0a4d7 + d7           ret      
0a4f6 + e6           onew     AX
0a4f7 + bf12c8       movw     0xfc812, AX
0a4fa + 71080dc8     clr1     0xfc80d.0
0a4fe + af0ac8       movw     AX, 0xfc80a
0a501 + ec1da700     br       0xa71d
0a6f8 + c7           push     HL
0a6f9 + 16           movw     HL, AX
0a6fa + c6           pop      HL
0a6fb + d7           ret      
0a71d + c7           push     HL
0a71e + 16           movw     HL, AX
0a71f + cff9c7ff     mov      0xfc7f9, #0xff
0a723 + c6           pop      HL
0a724 + d7           ret      
0a725 + c7           push     HL
0a726 + c1           push     AX
0a727 + c1           push     AX
0a728 + fbf8ff       movw     HL, SP
0a72b + cc0101       mov      [HL+0x1], #0x1
0a72e + 8ff0c7       mov      A, 0xfc7f0
0a731 + 5cf0         and      A, #0xf0
0a733 + df5e         bnz      0xa793
0a735 + 8ff1c7       mov      A, 0xfc7f1
0a738 + 5c0f         and      A, #0xf
0a73a + df57         bnz      0xa793
0a73c + ac02         movw     AX, [HL+0x2]
0a73e + 14           movw     DE, AX
0a73f + aa08         movw     AX, [DE+0x8]
0a741 + 449903       cmpw     AX, #0x399
0a744 + de4d         bnc      0xa793
0a746 + f6           clrw     AX
0a747 + bf04c8       movw     0xfc804, AX
0a74a + 8ff0c7       mov      A, 0xfc7f0
0a74d + 5c0f         and      A, #0xf
0a74f + d1           cmp0     A
0a750 + dd0a         bz       0xa75c
0a752 + 91           dec      A
0a753 + dd3e         bz       0xa793
0a755 + 91           dec      A
0a756 + 2c02         sub      A, #0x2
0a758 + dc1c         bc       0xa776
0a75a + ef2d         br       0xa789
0a75c + ac02         movw     AX, [HL+0x2]
0a75e + bf00c8       movw     0xfc800, AX
0a761 + fc33a900     call     0xa933
0a765 + 62           mov      A, C
0a766 + 9c01         mov      [HL+0x1], A
0a768 + d1           cmp0     A
0a769 + df28         bnz      0xa793
0a76b + 34f0c7       movw     DE, #0xc7f0
0a76e + 89           mov      A, [DE]
0a76f + 5c0f         and      A, #0xf
0a771 + 6c10         or       A, #0x10
0a773 + 99           mov      [DE], A
0a774 + ef1d         br       0xa793
0a776 + cc0100       mov      [HL+0x1], #0x0
0a779 + ac02         movw     AX, [HL+0x2]
0a77b + bf00c8       movw     0xfc800, AX
0a77e + 34f0c7       movw     DE, #0xc7f0
0a781 + 89           mov      A, [DE]
0a782 + 5c0f         and      A, #0xf
0a784 + 6c20         or       A, #0x20
0a786 + 99           mov      [DE], A
0a787 + ef0a         br       0xa793
0a789 + 30700e       movw     AX, #0xe70
0a78c + c1           push     AX
0a78d + f6           clrw     AX
0a78e + fc7e9200     call     0x927e
0a792 + c0           pop      AX
0a793 + 8c01         mov      A, [HL+0x1]
0a795 + 318f         sarw     AX, #0x8
0a797 + 12           movw     BC, AX
0a798 + 1004         addw     SP, #0x4
0a79a + c6           pop      HL
0a79b + d7           ret      
0a79c + c7           push     HL
0a79d + c1           push     AX
0a79e + c1           push     AX
0a79f + fbf8ff       movw     HL, SP
0a7a2 + 8c0a         mov      A, [HL+0xa]
0a7a4 + d1           cmp0     A
0a7a5 + df21         bnz      0xa7c8
0a7a7 + af00c8       movw     AX, 0xfc800
0a7aa + 614902       cmpw     AX, [HL+0x2]
0a7ad + df19         bnz      0xa7c8
0a7af + fc9fa800     call     0xa89f
0a7b3 + 62           mov      A, C
0a7b4 + 9c01         mov      [HL+0x1], A
0a7b6 + d1           cmp0     A
0a7b7 + df07         bnz      0xa7c0
0a7b9 + e6           onew     AX
0a7ba + fc25a800     call     0xa825
0a7be + ef0c         br       0xa7cc
0a7c0 + e6           onew     AX
0a7c1 + a1           incw     AX
0a7c2 + fc25a800     call     0xa825
0a7c6 + ef04         br       0xa7cc
0a7c8 + fc83a900     call     0xa983
0a7cc + ac02         movw     AX, [HL+0x2]
0a7ce + fcbea400     call     0xa4be
0a7d2 + 1004         addw     SP, #0x4
0a7d4 + c6           pop      HL
0a7d5 + d7           ret      
0a7d6 + c7           push     HL
0a7d7 + c1           push     AX
0a7d8 + fbf8ff       movw     HL, SP
0a7db + 8ff1c7       mov      A, 0xfc7f1
0a7de + 5c0f         and      A, #0xf
0a7e0 + df0c         bnz      0xa7ee
0a7e2 + 30e20e       movw     AX, #0xee2
0a7e5 + c1           push     AX
0a7e6 + 300500       movw     AX, #0x5
0a7e9 + fc7e9200     call     0x927e
0a7ed + c0           pop      AX
0a7ee + 8ff1c7       mov      A, 0xfc7f1
0a7f1 + 5c0f         and      A, #0xf
0a7f3 + 4c01         cmp      A, #0x1
0a7f5 + df1f         bnz      0xa816
0a7f7 + 40f9c7ff     cmp      0xfc7f9, #0xff
0a7fb + df0c         bnz      0xa809
0a7fd + 30e60e       movw     AX, #0xee6
0a800 + c1           push     AX
0a801 + 300400       movw     AX, #0x4
0a804 + fc7e9200     call     0x927e
0a808 + c0           pop      AX
0a809 + 8c08         mov      A, [HL+0x8]
0a80b + 318f         sarw     AX, #0x8
0a80d + c1           push     AX
0a80e + 30f2c7       movw     AX, #0xc7f2
0a811 + fc99aa00     call     0xaa99
0a815 + c0           pop      AX
0a816 + ab           movw     AX, [HL]
0a817 + fcbea400     call     0xa4be
0a81b + 34f1c7       movw     DE, #0xc7f1
0a81e + 89           mov      A, [DE]
0a81f + 5cf0         and      A, #0xf0
0a821 + 99           mov      [DE], A
0a822 + c0           pop      AX
0a823 + c6           pop      HL
0a824 + d7           ret      
0a825 + c7           push     HL
0a826 + 16           movw     HL, AX
0a827 + fc3ee000     call     0xe03e
0a82b + af06c8       movw     AX, 0xfc806
0a82e + 5cf0         and      A, #0xf0
0a830 + f0           clrb     X
0a831 + 6168         or       A, X
0a833 + dd0b         bz       0xa840
0a835 + 30fe0e       movw     AX, #0xefe
0a838 + c1           push     AX
0a839 + e6           onew     AX
0a83a + a1           incw     AX
0a83b + fc7e9200     call     0x927e
0a83f + c0           pop      AX
0a840 + af06c8       movw     AX, 0xfc806
0a843 + 314d         shlw     AX, #0x4
0a845 + bf06c8       movw     0xfc806, AX
0a848 + 17           movw     AX, HL
0a849 + 6f07c8       or       A, 0xfc807
0a84c + 08           xch      A, X
0a84d + 6f06c8       or       A, 0xfc806
0a850 + 08           xch      A, X
0a851 + bf06c8       movw     0xfc806, AX
0a854 + fc62e000     call     0xe062
0a858 + c6           pop      HL
0a859 + d7           ret      
0a86e + c7           push     HL
0a86f + c1           push     AX
0a870 + c1           push     AX
0a871 + fbf8ff       movw     HL, SP
0a874 + ac0a         movw     AX, [HL+0xa]
0a876 + bb           movw     [HL], AX
0a877 + f6           clrw     AX
0a878 + 614900       cmpw     AX, [HL]
0a87b + dd1e         bz       0xa89b
0a87d + 618900       decw     [HL]
0a880 + ab           movw     AX, [HL]
0a881 + 610902       addw     AX, [HL+0x2]
0a884 + 14           movw     DE, AX
0a885 + 89           mov      A, [DE]
0a886 + 73           mov      B, A
0a887 + ab           movw     AX, [HL]
0a888 + 33           xchw     AX, BC
0a889 + 4833c4       mov      [BC+0xc433], A
0a88c + ab           movw     AX, [HL]
0a88d + 442000       cmpw     AX, #0x20
0a890 + dee5         bnc      0xa877
0a892 + 89           mov      A, [DE]
0a893 + 73           mov      B, A
0a894 + ab           movw     AX, [HL]
0a895 + 33           xchw     AX, BC
0a896 + 48cbc7       mov      [BC+0xc7cb], A
0a899 + efdc         br       0xa877
0a89b + 1004         addw     SP, #0x4
0a89d + c6           pop      HL
0a89e + d7           ret      
0a89f + c7           push     HL
0a8a0 + 2008         subw     SP, #0x8
0a8a2 + fbf8ff       movw     HL, SP
0a8a5 + cc0701       mov      [HL+0x7], #0x1
0a8a8 + eb00c8       movw     DE, 0xfc800
0a8ab + aa0a         movw     AX, [DE+0xa]
0a8ad + bc04         movw     [HL+0x4], AX
0a8af + aa08         movw     AX, [DE+0x8]
0a8b1 + bc02         movw     [HL+0x2], AX
0a8b3 + ac04         movw     AX, [HL+0x4]
0a8b5 + 14           movw     DE, AX
0a8b6 + 89           mov      A, [DE]
0a8b7 + 9feec7       mov      0xfc7ee, A
0a8ba + 8ff0c7       mov      A, 0xfc7f0
0a8bd + 314a         shr      A, #0x4
0a8bf + 91           dec      A
0a8c0 + dd05         bz       0xa8c7
0a8c2 + 91           dec      A
0a8c3 + dd11         bz       0xa8d6
0a8c5 + ef59         br       0xa920
0a8c7 + ac02         movw     AX, [HL+0x2]
0a8c9 + c1           push     AX
0a8ca + ac04         movw     AX, [HL+0x4]
0a8cc + fc6ea800     call     0xa86e
0a8d0 + c0           pop      AX
0a8d1 + cc0700       mov      [HL+0x7], #0x0
0a8d4 + ef54         br       0xa92a
0a8d6 + ac02         movw     AX, [HL+0x2]
0a8d8 + 442100       cmpw     AX, #0x21
0a8db + dc05         bc       0xa8e2
0a8dd + 302000       movw     AX, #0x20
0a8e0 + ef02         br       0xa8e4
0a8e2 + ac02         movw     AX, [HL+0x2]
0a8e4 + 60           mov      A, X
0a8e5 + 9c01         mov      [HL+0x1], A
0a8e7 + 8c01         mov      A, [HL+0x1]
0a8e9 + d1           cmp0     A
0a8ea + dd1a         bz       0xa906
0a8ec + 616901       dec      [HL+0x1]
0a8ef + 8c01         mov      A, [HL+0x1]
0a8f1 + 73           mov      B, A
0a8f2 + 09cbc7       mov      A, [B+0xc7cb]
0a8f5 + 72           mov      C, A
0a8f6 + 8c01         mov      A, [HL+0x1]
0a8f8 + 318e         shrw     AX, #0x8
0a8fa + 610904       addw     AX, [HL+0x4]
0a8fd + 14           movw     DE, AX
0a8fe + 89           mov      A, [DE]
0a8ff + 6142         cmp      C, A
0a901 + dde4         bz       0xa8e7
0a903 + cc0700       mov      [HL+0x7], #0x0
0a906 + 8c07         mov      A, [HL+0x7]
0a908 + d1           cmp0     A
0a909 + df1f         bnz      0xa92a
0a90b + 8ff0c7       mov      A, 0xfc7f0
0a90e + 5c0f         and      A, #0xf
0a910 + 4c03         cmp      A, #0x3
0a912 + df16         bnz      0xa92a
0a914 + ac02         movw     AX, [HL+0x2]
0a916 + c1           push     AX
0a917 + ac04         movw     AX, [HL+0x4]
0a919 + fc6ea800     call     0xa86e
0a91d + c0           pop      AX
0a91e + ef0a         br       0xa92a
0a920 + 30590f       movw     AX, #0xf59
0a923 + c1           push     AX
0a924 + f6           clrw     AX
0a925 + fc7e9200     call     0x927e
0a929 + c0           pop      AX
0a92a + 8c07         mov      A, [HL+0x7]
0a92c + 318e         shrw     AX, #0x8
0a92e + 12           movw     BC, AX
0a92f + 1008         addw     SP, #0x8
0a931 + c6           pop      HL
0a932 + d7           ret      
0a933 + c7           push     HL
0a934 + 5601         mov      L, #0x1
0a936 + 40f9c7ff     cmp      0xfc7f9, #0xff
0a93a + df32         bnz      0xa96e
0a93c + eb00c8       movw     DE, 0xfc800
0a93f + 8a02         mov      A, [DE+0x2]
0a941 + 9ff4c7       mov      0xfc7f4, A
0a944 + eb00c8       movw     DE, 0xfc800
0a947 + 8a04         mov      A, [DE+0x4]
0a949 + 9ff6c7       mov      0xfc7f6, A
0a94c + eb00c8       movw     DE, 0xfc800
0a94f + aa08         movw     AX, [DE+0x8]
0a951 + bffac7       movw     0xfc7fa, AX
0a954 + eb00c8       movw     DE, 0xfc800
0a957 + 89           mov      A, [DE]
0a958 + 9ff2c7       mov      0xfc7f2, A
0a95b + f5f9c7       clrb     0xfc7f9
0a95e + 30f2c7       movw     AX, #0xc7f2
0a961 + fc30aa00     call     0xaa30
0a965 + 62           mov      A, C
0a966 + 76           mov      L, A
0a967 + d1           cmp0     A
0a968 + 61e8         skz      
0a96a + cff9c7ff     mov      0xfc7f9, #0xff
0a96e + 66           mov      A, L
0a96f + 318f         sarw     AX, #0x8
0a971 + 12           movw     BC, AX
0a972 + c6           pop      HL
0a973 + d7           ret      
0a983 + 8ff0c7       mov      A, 0xfc7f0
0a986 + 5c0f         and      A, #0xf
0a988 + df13         bnz      0xa99d
0a98a + 300300       movw     AX, #0x3
0a98d + c1           push     AX
0a98e + 30f2c7       movw     AX, #0xc7f2
0a991 + fc58aa00     call     0xaa58
0a995 + c0           pop      AX
0a996 + 34f0c7       movw     DE, #0xc7f0
0a999 + 89           mov      A, [DE]
0a99a + 5c0f         and      A, #0xf
0a99c + 99           mov      [DE], A
0a99d + d7           ret      
0aa30 + c7           push     HL
0aa31 + c1           push     AX
0aa32 + c1           push     AX
0aa33 + fbf8ff       movw     HL, SP
0aa36 + cc0101       mov      [HL+0x1], #0x1
0aa39 + 8f0dc8       mov      A, 0xfc80d
0aa3c + 310310       bt       A.0, 0xaa4f
0aa3f + 71000dc8     set1     0xfc80d.0
0aa43 + 71000cc8     set1     0xfc80c.0
0aa47 + ac02         movw     AX, [HL+0x2]
0aa49 + bf0ac8       movw     0xfc80a, AX
0aa4c + cc0100       mov      [HL+0x1], #0x0
0aa4f + 8c01         mov      A, [HL+0x1]
0aa51 + 318f         sarw     AX, #0x8
0aa53 + 12           movw     BC, AX
0aa54 + 1004         addw     SP, #0x4
0aa56 + c6           pop      HL
0aa57 + d7           ret      
0aa58 + c7           push     HL
0aa59 + c1           push     AX
0aa5a + c1           push     AX
0aa5b + fbf8ff       movw     HL, SP
0aa5e + 71080cc8     clr1     0xfc80c.0
0aa62 + 8c0a         mov      A, [HL+0xa]
0aa64 + d1           cmp0     A
0aa65 + df2a         bnz      0xaa91
0aa67 + af0ac8       movw     AX, 0xfc80a
0aa6a + 614902       cmpw     AX, [HL+0x2]
0aa6d + df22         bnz      0xaa91
0aa6f + f6           clrw     AX
0aa70 + bb           movw     [HL], AX
0aa71 + 614900       cmpw     AX, [HL]
0aa74 + df1b         bnz      0xaa91
0aa76 + ac02         movw     AX, [HL+0x2]
0aa78 + 14           movw     DE, AX
0aa79 + f7           clrw     BC
0aa7a + 5004         mov      X, #0x4
0aa7c + 89           mov      A, [DE]
0aa7d + a5           incw     DE
0aa7e + 4824c8       mov      [BC+0xc824], A
0aa81 + a3           incw     BC
0aa82 + 90           dec      X
0aa83 + dff7         bnz      0xaa7c
0aa85 + ac02         movw     AX, [HL+0x2]
0aa87 + fcf8a600     call     0xa6f8
0aa8b + 71100cc8     set1     0xfc80c.1
0aa8f + ef04         br       0xaa95
0aa91 + fcf6a400     call     0xa4f6
0aa95 + 1004         addw     SP, #0x4
0aa97 + c6           pop      HL
0aa98 + d7           ret      
0aa99 + c7           push     HL
0aa9a + c1           push     AX
0aa9b + fbf8ff       movw     HL, SP
0aa9e + 8c08         mov      A, [HL+0x8]
0aaa0 + d1           cmp0     A
0aaa1 + ab           movw     AX, [HL]
0aaa2 + 14           movw     DE, AX
0aaa3 + 8a05         mov      A, [DE+0x5]
0aaa5 + 91           dec      A
0aaa6 + 2c03         sub      A, #0x3
0aaa8 + dc03         bc       0xaaad
0aaaa + d1           cmp0     A
0aaab + ef08         br       0xaab5
0aaad + 8c08         mov      A, [HL+0x8]
0aaaf + 318f         sarw     AX, #0x8
0aab1 + fc86b300     call     0xb386
0aab5 + ab           movw     AX, [HL]
0aab6 + 14           movw     DE, AX
0aab7 + ca0500       mov      [DE+0x5], #0x0
0aaba + c0           pop      AX
0aabb + c6           pop      HL
0aabc + d7           ret      
0ae16 + c7           push     HL
0ae17 + c3           push     BC
0ae18 + c1           push     AX
0ae19 + fbf8ff       movw     HL, SP
0ae1c + ab           movw     AX, [HL]
0ae1d + bf2ac8       movw     0xfc82a, AX
0ae20 + 8c02         mov      A, [HL+0x2]
0ae22 + 9f2cc8       mov      0xfc82c, A
0ae25 + 1004         addw     SP, #0x4
0ae27 + c6           pop      HL
0ae28 + d7           ret      
0b386 + c7           push     HL
0b387 + 16           movw     HL, AX
0b388 + 66           mov      A, L
0b389 + 9f08c8       mov      0xfc808, A
0b38c + f6           clrw     AX
0b38d + bf0ec8       movw     0xfc80e, AX
0b390 + cf0cc840     mov      0xfc80c, #0x40
0b394 + 12           movw     BC, AX
0b395 + fc16ae00     call     0xae16
0b399 + fcf6a400     call     0xa4f6
0b39d + c6           pop      HL
0b39e + d7           ret      
0b97c   c7           push     HL
0b97d   c1           push     AX
0b97e   c1           push     AX
0b97f   fbf8ff       movw     HL, SP
0b982   cc0103       mov      [HL+0x1], #0x3
0b985   8c02         mov      A, [HL+0x2]
0b987   d1           cmp0     A
0b988   dd15         bz       0xb99f
0b98a   db1ae4       movw     BC, 0xfe41a
0b98d   17           movw     AX, HL
0b98e   a1           incw     AX
0b98f   c1           push     AX
0b990   490e00       mov      A, [BC+0xe]
0b993   9efc         mov      CS, A
0b995   790c00       movw     AX, [BC+0xc]
0b998   14           movw     DE, AX
0b999   303e00       movw     AX, #0x3e
0b99c   61ea         call     DE
0b99e   c0           pop      AX
0b99f   1004         addw     SP, #0x4
0b9a1   c6           pop      HL
0b9a2   d7           ret      
0d540 + c7           push     HL
0d541 + 16           movw     HL, AX
0d542 + fc3ee000     call     0xe03e
0d546 + 5701         mov      H, #0x1
0d548 + 8f73c8       mov      A, 0xfc873
0d54b + 7c80         xor      A, #0x80
0d54d + 4c82         cmp      A, #0x82
0d54f + dc18         bc       0xd569
0d551 + 4073c809     cmp      0xfc873, #0x9
0d555 + dd12         bz       0xd569
0d557 + cf73c809     mov      0xfc873, #0x9
0d55b + 17           movw     AX, HL
0d55c + f1           clrb     A
0d55d + fcb3a400     call     0xa4b3
0d561 + 62           mov      A, C
0d562 + 77           mov      H, A
0d563 + d1           cmp0     A
0d564 + 61f8         sknz     
0d566 + f573c8       clrb     0xfc873
0d569 + f6           clrw     AX
0d56a + bf70c8       movw     0xfc870, AX
0d56d + 710874c8     clr1     0xfc874.0
0d571 + 712874c8     clr1     0xfc874.2
0d575 + 67           mov      A, H
0d576 + d1           cmp0     A
0d577 + dd11         bz       0xd58a
0d579 + f573c8       clrb     0xfc873
0d57c + 711874c8     clr1     0xfc874.1
0d580 + f57cc8       clrb     0xfc87c
0d583 + 347ec8       movw     DE, #0xc87e
0d586 + 89           mov      A, [DE]
0d587 + 5cf0         and      A, #0xf0
0d589 + 99           mov      [DE], A
0d58a + d591c8       cmp0     0xfc891
0d58d + df09         bnz      0xd598
0d58f + f6           clrw     AX
0d590 + fc558700     call     0x8755
0d594 + cf91c8ff     mov      0xfc891, #0xff
0d598 + fc62e000     call     0xe062
0d59c + c6           pop      HL
0d59d + d7           ret      
0d59e + c7           push     HL
0d59f + 16           movw     HL, AX
0d5a0 + fc3ee000     call     0xe03e
0d5a4 + 8f83c8       mov      A, 0xfc883
0d5a7 + 7c80         xor      A, #0x80
0d5a9 + 4c82         cmp      A, #0x82
0d5ab + dc10         bc       0xd5bd
0d5ad + 4083c807     cmp      0xfc883, #0x7
0d5b1 + dd0a         bz       0xd5bd
0d5b3 + cf83c807     mov      0xfc883, #0x7
0d5b7 + 17           movw     AX, HL
0d5b8 + f1           clrb     A
0d5b9 + fcd5a300     call     0xa3d5
0d5bd + f6           clrw     AX
0d5be + bf80c8       movw     0xfc880, AX
0d5c1 + f583c8       clrb     0xfc883
0d5c4 + 710884c8     clr1     0xfc884.0
0d5c8 + 711884c8     clr1     0xfc884.1
0d5cc + 348ec8       movw     DE, #0xc88e
0d5cf + 89           mov      A, [DE]
0d5d0 + 5cf0         and      A, #0xf0
0d5d2 + 99           mov      [DE], A
0d5d3 + a5           incw     DE
0d5d4 + 89           mov      A, [DE]
0d5d5 + 5cfc         and      A, #0xfc
0d5d7 + 99           mov      [DE], A
0d5d8 + 4091c880     cmp      0xfc891, #0x80
0d5dc + df09         bnz      0xd5e7
0d5de + f6           clrw     AX
0d5df + fc558700     call     0x8755
0d5e3 + cf91c8ff     mov      0xfc891, #0xff
0d5e7 + fc62e000     call     0xe062
0d5eb + c6           pop      HL
0d5ec + d7           ret      
0d5ed + c7           push     HL
0d5ee + c1           push     AX
0d5ef + 2004         subw     SP, #0x4
0d5f1 + fbf8ff       movw     HL, SP
0d5f4 + ac04         movw     AX, [HL+0x4]
0d5f6 + 14           movw     DE, AX
0d5f7 + aa06         movw     AX, [DE+0x6]
0d5f9 + 14           movw     DE, AX
0d5fa + 89           mov      A, [DE]
0d5fb + 5cf0         and      A, #0xf0
0d5fd + d1           cmp0     A
0d5fe + dd15         bz       0xd615
0d600 + 2c10         sub      A, #0x10
0d602 + dd11         bz       0xd615
0d604 + 2c10         sub      A, #0x10
0d606 + 61f8         sknz     
0d608 + eecf01       br       0xd7da
0d60b + 2c10         sub      A, #0x10
0d60d + 61f8         sknz     
0d60f + ee5803       br       0xd96a
0d612 + ee3204       br       0xda47
0d615 + d583c8       cmp0     0xfc883
0d618 + dd11         bz       0xd62b
0d61a + 4083c801     cmp      0xfc883, #0x1
0d61e + df04         bnz      0xd624
0d620 + f7           clrw     BC
0d621 + ee2404       br       0xda48
0d624 + 300600       movw     AX, #0x6
0d627 + fc9ed500     call     0xd59e
0d62b + cf83c802     mov      0xfc883, #0x2
0d62f + f6           clrw     AX
0d630 + bf8ac8       movw     0xfc88a, AX
0d633 + ac04         movw     AX, [HL+0x4]
0d635 + 14           movw     DE, AX
0d636 + aa06         movw     AX, [DE+0x6]
0d638 + 14           movw     DE, AX
0d639 + 89           mov      A, [DE]
0d63a + 5cf0         and      A, #0xf0
0d63c + d1           cmp0     A
0d63d + 61f8         sknz     
0d63f + ee0a01       br       0xd74c
0d642 + 2c10         sub      A, #0x10
0d644 + 61e8         skz      
0d646 + ee8701       br       0xd7d0
0d649 + ac04         movw     AX, [HL+0x4]
0d64b + 14           movw     DE, AX
0d64c + aa06         movw     AX, [DE+0x6]
0d64e + 14           movw     DE, AX
0d64f + 89           mov      A, [DE]
0d650 + 5c0f         and      A, #0xf
0d652 + 318e         shrw     AX, #0x8
0d654 + 318d         shlw     AX, #0x8
0d656 + bf8cc8       movw     0xfc88c, AX
0d659 + ac04         movw     AX, [HL+0x4]
0d65b + 14           movw     DE, AX
0d65c + aa06         movw     AX, [DE+0x6]
0d65e + 14           movw     DE, AX
0d65f + 8a01         mov      A, [DE+0x1]
0d661 + 318e         shrw     AX, #0x8
0d663 + 6f8dc8       or       A, 0xfc88d
0d666 + 08           xch      A, X
0d667 + 6f8cc8       or       A, 0xfc88c
0d66a + 08           xch      A, X
0d66b + bf8cc8       movw     0xfc88c, AX
0d66e + 440800       cmpw     AX, #0x8
0d671 + 61d8         sknc     
0d673 + eecb00       br       0xd741
0d676 + 348fc8       movw     DE, #0xc88f
0d679 + 89           mov      A, [DE]
0d67a + 5cfc         and      A, #0xfc
0d67c + 99           mov      [DE], A
0d67d + ac04         movw     AX, [HL+0x4]
0d67f + 14           movw     DE, AX
0d680 + aa06         movw     AX, [DE+0x6]
0d682 + a1           incw     AX
0d683 + a1           incw     AX
0d684 + bf86c8       movw     0xfc886, AX
0d687 + af8cc8       movw     AX, 0xfc88c
0d68a + fc76a300     call     0xa376
0d68e + 13           movw     AX, BC
0d68f + bf88c8       movw     0xfc888, AX
0d692 + 8f8fc8       mov      A, 0xfc88f
0d695 + 5c03         and      A, #0x3
0d697 + d1           cmp0     A
0d698 + dd24         bz       0xd6be
0d69a + 2c02         sub      A, #0x2
0d69c + dd05         bz       0xd6a3
0d69e + 91           dec      A
0d69f + dd08         bz       0xd6a9
0d6a1 + ef1b         br       0xd6be
0d6a3 + f583c8       clrb     0xfc883
0d6a6 + ee9600       br       0xd73f
0d6a9 + 30c900       movw     AX, #0xc9
0d6ac + bf80c8       movw     0xfc880, AX
0d6af + cf83c806     mov      0xfc883, #0x6
0d6b3 + 710084c8     set1     0xfc884.0
0d6b7 + fc7edb00     call     0xdb7e
0d6bb + ee8100       br       0xd73f
0d6be + f6           clrw     AX
0d6bf + 4288c8       cmpw     AX, 0xfc888
0d6c2 + dd78         bz       0xd73c
0d6c4 + ac04         movw     AX, [HL+0x4]
0d6c6 + 14           movw     DE, AX
0d6c7 + aa06         movw     AX, [DE+0x6]
0d6c9 + 14           movw     DE, AX
0d6ca + 8a02         mov      A, [DE+0x2]
0d6cc + eb88c8       movw     DE, 0xfc888
0d6cf + 99           mov      [DE], A
0d6d0 + ac04         movw     AX, [HL+0x4]
0d6d2 + 14           movw     DE, AX
0d6d3 + aa06         movw     AX, [DE+0x6]
0d6d5 + a1           incw     AX
0d6d6 + 14           movw     DE, AX
0d6d7 + 8a02         mov      A, [DE+0x2]
0d6d9 + eb88c8       movw     DE, 0xfc888
0d6dc + 9a01         mov      [DE+0x1], A
0d6de + ac04         movw     AX, [HL+0x4]
0d6e0 + 14           movw     DE, AX
0d6e1 + aa06         movw     AX, [DE+0x6]
0d6e3 + a1           incw     AX
0d6e4 + a1           incw     AX
0d6e5 + 14           movw     DE, AX
0d6e6 + 8a02         mov      A, [DE+0x2]
0d6e8 + eb88c8       movw     DE, 0xfc888
0d6eb + 9a02         mov      [DE+0x2], A
0d6ed + ac04         movw     AX, [HL+0x4]
0d6ef + 14           movw     DE, AX
0d6f0 + aa06         movw     AX, [DE+0x6]
0d6f2 + a1           incw     AX
0d6f3 + a1           incw     AX
0d6f4 + 14           movw     DE, AX
0d6f5 + 8a03         mov      A, [DE+0x3]
0d6f7 + eb88c8       movw     DE, 0xfc888
0d6fa + 9a03         mov      [DE+0x3], A
0d6fc + ac04         movw     AX, [HL+0x4]
0d6fe + 14           movw     DE, AX
0d6ff + aa06         movw     AX, [DE+0x6]
0d701 + a1           incw     AX
0d702 + a1           incw     AX
0d703 + 14           movw     DE, AX
0d704 + 8a04         mov      A, [DE+0x4]
0d706 + eb88c8       movw     DE, 0xfc888
0d709 + 9a04         mov      [DE+0x4], A
0d70b + ac04         movw     AX, [HL+0x4]
0d70d + 14           movw     DE, AX
0d70e + aa06         movw     AX, [DE+0x6]
0d710 + a1           incw     AX
0d711 + a1           incw     AX
0d712 + 14           movw     DE, AX
0d713 + 8a05         mov      A, [DE+0x5]
0d715 + eb88c8       movw     DE, 0xfc888
0d718 + 9a05         mov      [DE+0x5], A
0d71a + 300600       movw     AX, #0x6
0d71d + bf8ac8       movw     0xfc88a, AX
0d720 + 348ec8       movw     DE, #0xc88e
0d723 + 89           mov      A, [DE]
0d724 + 5cf0         and      A, #0xf0
0d726 + 81           inc      A
0d727 + 99           mov      [DE], A
0d728 + 30c900       movw     AX, #0xc9
0d72b + bf80c8       movw     0xfc880, AX
0d72e + cf83c805     mov      0xfc883, #0x5
0d732 + 710084c8     set1     0xfc884.0
0d736 + fc7edb00     call     0xdb7e
0d73a + ef0c         br       0xd748
0d73c + f583c8       clrb     0xfc883
0d73f + ef07         br       0xd748
0d741 + e583c8       oneb     0xfc883
0d744 + fc62de00     call     0xde62
0d748 + f7           clrw     BC
0d749 + eefc02       br       0xda48
0d74c + ac04         movw     AX, [HL+0x4]
0d74e + 14           movw     DE, AX
0d74f + aa06         movw     AX, [DE+0x6]
0d751 + 14           movw     DE, AX
0d752 + 89           mov      A, [DE]
0d753 + 318e         shrw     AX, #0x8
0d755 + bf8cc8       movw     0xfc88c, AX
0d758 + 440800       cmpw     AX, #0x8
0d75b + de68         bnc      0xd7c5
0d75d + f6           clrw     AX
0d75e + 428cc8       cmpw     AX, 0xfc88c
0d761 + dd62         bz       0xd7c5
0d763 + 348fc8       movw     DE, #0xc88f
0d766 + 89           mov      A, [DE]
0d767 + 5cfc         and      A, #0xfc
0d769 + 99           mov      [DE], A
0d76a + ac04         movw     AX, [HL+0x4]
0d76c + 14           movw     DE, AX
0d76d + aa06         movw     AX, [DE+0x6]
0d76f + a1           incw     AX
0d770 + bf86c8       movw     0xfc886, AX
0d773 + af8cc8       movw     AX, 0xfc88c
0d776 + fc76a300     call     0xa376
0d77a + 13           movw     AX, BC
0d77b + bf88c8       movw     0xfc888, AX
0d77e + f6           clrw     AX
0d77f + 4288c8       cmpw     AX, 0xfc888
0d782 + dd38         bz       0xd7bc
0d784 + 8f8fc8       mov      A, 0xfc88f
0d787 + 5c03         and      A, #0x3
0d789 + df31         bnz      0xd7bc
0d78b + af8cc8       movw     AX, 0xfc88c
0d78e + b1           decw     AX
0d78f + bc02         movw     [HL+0x2], AX
0d791 + 8c03         mov      A, [HL+0x3]
0d793 + 01           addw     AX, AX
0d794 + dc1a         bc       0xd7b0
0d796 + ac04         movw     AX, [HL+0x4]
0d798 + 14           movw     DE, AX
0d799 + aa06         movw     AX, [DE+0x6]
0d79b + a1           incw     AX
0d79c + 12           movw     BC, AX
0d79d + ac02         movw     AX, [HL+0x2]
0d79f + 03           addw     AX, BC
0d7a0 + 14           movw     DE, AX
0d7a1 + 89           mov      A, [DE]
0d7a2 + 72           mov      C, A
0d7a3 + ac02         movw     AX, [HL+0x2]
0d7a5 + 0288c8       addw     AX, 0xfc888
0d7a8 + 14           movw     DE, AX
0d7a9 + 62           mov      A, C
0d7aa + 99           mov      [DE], A
0d7ab + 618902       decw     [HL+0x2]
0d7ae + efe1         br       0xd791
0d7b0 + e583c8       oneb     0xfc883
0d7b3 + af8cc8       movw     AX, 0xfc88c
0d7b6 + fcc3a300     call     0xa3c3
0d7ba + ef10         br       0xd7cc
0d7bc + e583c8       oneb     0xfc883
0d7bf + fc62de00     call     0xde62
0d7c3 + ef07         br       0xd7cc
0d7c5 + e583c8       oneb     0xfc883
0d7c8 + fc62de00     call     0xde62
0d7cc + f7           clrw     BC
0d7cd + ee7802       br       0xda48
0d7d0 + e583c8       oneb     0xfc883
0d7d3 + fc62de00     call     0xde62
0d7d7 + ee6d02       br       0xda47
0d7da + 4083c803     cmp      0xfc883, #0x3
0d7de + dd09         bz       0xd7e9
0d7e0 + 4083c805     cmp      0xfc883, #0x5
0d7e4 + 61e8         skz      
0d7e6 + ee7e01       br       0xd967
0d7e9 + 4083c805     cmp      0xfc883, #0x5
0d7ed + df16         bnz      0xd805
0d7ef + 8f84c8       mov      A, 0xfc884
0d7f2 + 31030c       bt       A.0, 0xd801
0d7f5 + f6           clrw     AX
0d7f6 + fc558700     call     0x8755
0d7fa + f6           clrw     AX
0d7fb + fcd7dc00     call     0xdcd7
0d7ff + ef04         br       0xd805
0d801 + f7           clrw     BC
0d802 + ee4302       br       0xda48
0d805 + af8ac8       movw     AX, 0xfc88a
0d808 + 040700       addw     AX, #0x7
0d80b + 428cc8       cmpw     AX, 0xfc88c
0d80e + dc63         bc       0xd873
0d810 + ac04         movw     AX, [HL+0x4]
0d812 + 14           movw     DE, AX
0d813 + aa06         movw     AX, [DE+0x6]
0d815 + 14           movw     DE, AX
0d816 + 89           mov      A, [DE]
0d817 + 5c0f         and      A, #0xf
0d819 + 72           mov      C, A
0d81a + 8f8ec8       mov      A, 0xfc88e
0d81d + 5c0f         and      A, #0xf
0d81f + 6142         cmp      C, A
0d821 + dd07         bz       0xd82a
0d823 + e6           onew     AX
0d824 + fc9ed500     call     0xd59e
0d828 + ef46         br       0xd870
0d82a + ac04         movw     AX, [HL+0x4]
0d82c + 14           movw     DE, AX
0d82d + aa06         movw     AX, [DE+0x6]
0d82f + a1           incw     AX
0d830 + bf86c8       movw     0xfc886, AX
0d833 + af8ac8       movw     AX, 0xfc88a
0d836 + a1           incw     AX
0d837 + 12           movw     BC, AX
0d838 + af8cc8       movw     AX, 0xfc88c
0d83b + 23           subw     AX, BC
0d83c + bc02         movw     [HL+0x2], AX
0d83e + 8c03         mov      A, [HL+0x3]
0d840 + 01           addw     AX, AX
0d841 + dc1f         bc       0xd862
0d843 + ac04         movw     AX, [HL+0x4]
0d845 + 14           movw     DE, AX
0d846 + aa06         movw     AX, [DE+0x6]
0d848 + a1           incw     AX
0d849 + 12           movw     BC, AX
0d84a + ac02         movw     AX, [HL+0x2]
0d84c + 03           addw     AX, BC
0d84d + 14           movw     DE, AX
0d84e + 89           mov      A, [DE]
0d84f + 72           mov      C, A
0d850 + af8ac8       movw     AX, 0xfc88a
0d853 + 0288c8       addw     AX, 0xfc888
0d856 + 14           movw     DE, AX
0d857 + ac02         movw     AX, [HL+0x2]
0d859 + 05           addw     AX, DE
0d85a + 14           movw     DE, AX
0d85b + 62           mov      A, C
0d85c + 99           mov      [DE], A
0d85d + 618902       decw     [HL+0x2]
0d860 + efdc         br       0xd83e
0d862 + e583c8       oneb     0xfc883
0d865 + f6           clrw     AX
0d866 + bf80c8       movw     0xfc880, AX
0d869 + af8cc8       movw     AX, 0xfc88c
0d86c + fcc3a300     call     0xa3c3
0d870 + eef000       br       0xd963
0d873 + ac04         movw     AX, [HL+0x4]
0d875 + 14           movw     DE, AX
0d876 + aa06         movw     AX, [DE+0x6]
0d878 + 14           movw     DE, AX
0d879 + 89           mov      A, [DE]
0d87a + 5c0f         and      A, #0xf
0d87c + 72           mov      C, A
0d87d + 8f8ec8       mov      A, 0xfc88e
0d880 + 5c0f         and      A, #0xf
0d882 + 6142         cmp      C, A
0d884 + dd08         bz       0xd88e
0d886 + e6           onew     AX
0d887 + fc9ed500     call     0xd59e
0d88b + eed500       br       0xd963
0d88e + ac04         movw     AX, [HL+0x4]
0d890 + 14           movw     DE, AX
0d891 + aa06         movw     AX, [DE+0x6]
0d893 + a1           incw     AX
0d894 + bf86c8       movw     0xfc886, AX
0d897 + aa06         movw     AX, [DE+0x6]
0d899 + 14           movw     DE, AX
0d89a + 8a01         mov      A, [DE+0x1]
0d89c + 72           mov      C, A
0d89d + af8ac8       movw     AX, 0xfc88a
0d8a0 + 0288c8       addw     AX, 0xfc888
0d8a3 + 14           movw     DE, AX
0d8a4 + 62           mov      A, C
0d8a5 + 99           mov      [DE], A
0d8a6 + ac04         movw     AX, [HL+0x4]
0d8a8 + 14           movw     DE, AX
0d8a9 + aa06         movw     AX, [DE+0x6]
0d8ab + 14           movw     DE, AX
0d8ac + 8a02         mov      A, [DE+0x2]
0d8ae + 72           mov      C, A
0d8af + af8ac8       movw     AX, 0xfc88a
0d8b2 + 0288c8       addw     AX, 0xfc888
0d8b5 + 14           movw     DE, AX
0d8b6 + 62           mov      A, C
0d8b7 + 9a01         mov      [DE+0x1], A
0d8b9 + ac04         movw     AX, [HL+0x4]
0d8bb + 14           movw     DE, AX
0d8bc + aa06         movw     AX, [DE+0x6]
0d8be + a1           incw     AX
0d8bf + 14           movw     DE, AX
0d8c0 + 8a02         mov      A, [DE+0x2]
0d8c2 + 72           mov      C, A
0d8c3 + af8ac8       movw     AX, 0xfc88a
0d8c6 + 0288c8       addw     AX, 0xfc888
0d8c9 + 14           movw     DE, AX
0d8ca + 62           mov      A, C
0d8cb + 9a02         mov      [DE+0x2], A
0d8cd + ac04         movw     AX, [HL+0x4]
0d8cf + 14           movw     DE, AX
0d8d0 + aa06         movw     AX, [DE+0x6]
0d8d2 + a1           incw     AX
0d8d3 + 14           movw     DE, AX
0d8d4 + 8a03         mov      A, [DE+0x3]
0d8d6 + 72           mov      C, A
0d8d7 + af8ac8       movw     AX, 0xfc88a
0d8da + 0288c8       addw     AX, 0xfc888
0d8dd + 14           movw     DE, AX
0d8de + 62           mov      A, C
0d8df + 9a03         mov      [DE+0x3], A
0d8e1 + ac04         movw     AX, [HL+0x4]
0d8e3 + 14           movw     DE, AX
0d8e4 + aa06         movw     AX, [DE+0x6]
0d8e6 + a1           incw     AX
0d8e7 + 14           movw     DE, AX
0d8e8 + 8a04         mov      A, [DE+0x4]
0d8ea + 72           mov      C, A
0d8eb + af8ac8       movw     AX, 0xfc88a
0d8ee + 0288c8       addw     AX, 0xfc888
0d8f1 + 14           movw     DE, AX
0d8f2 + 62           mov      A, C
0d8f3 + 9a04         mov      [DE+0x4], A
0d8f5 + ac04         movw     AX, [HL+0x4]
0d8f7 + 14           movw     DE, AX
0d8f8 + aa06         movw     AX, [DE+0x6]
0d8fa + a1           incw     AX
0d8fb + 14           movw     DE, AX
0d8fc + 8a05         mov      A, [DE+0x5]
0d8fe + 72           mov      C, A
0d8ff + af8ac8       movw     AX, 0xfc88a
0d902 + 0288c8       addw     AX, 0xfc888
0d905 + 14           movw     DE, AX
0d906 + 62           mov      A, C
0d907 + 9a05         mov      [DE+0x5], A
0d909 + ac04         movw     AX, [HL+0x4]
0d90b + 14           movw     DE, AX
0d90c + aa06         movw     AX, [DE+0x6]
0d90e + a1           incw     AX
0d90f + 14           movw     DE, AX
0d910 + 8a06         mov      A, [DE+0x6]
0d912 + 72           mov      C, A
0d913 + af8ac8       movw     AX, 0xfc88a
0d916 + 0288c8       addw     AX, 0xfc888
0d919 + 14           movw     DE, AX
0d91a + 62           mov      A, C
0d91b + 9a06         mov      [DE+0x6], A
0d91d + af8ac8       movw     AX, 0xfc88a
0d920 + 040700       addw     AX, #0x7
0d923 + bf8ac8       movw     0xfc88a, AX
0d926 + 8f8ec8       mov      A, 0xfc88e
0d929 + 81           inc      A
0d92a + 5c0f         and      A, #0xf
0d92c + 348ec8       movw     DE, #0xc88e
0d92f + 70           mov      X, A
0d930 + 89           mov      A, [DE]
0d931 + 5cf0         and      A, #0xf0
0d933 + 6168         or       A, X
0d935 + 99           mov      [DE], A
0d936 + d582c8       cmp0     0xfc882
0d939 + dd1e         bz       0xd959
0d93b + b082c8       dec      0xfc882
0d93e + d582c8       cmp0     0xfc882
0d941 + df16         bnz      0xd959
0d943 + cf83c805     mov      0xfc883, #0x5
0d947 + 30c900       movw     AX, #0xc9
0d94a + bf80c8       movw     0xfc880, AX
0d94d + 710084c8     set1     0xfc884.0
0d951 + fc7edb00     call     0xdb7e
0d955 + f7           clrw     BC
0d956 + eeef00       br       0xda48
0d959 + 30c900       movw     AX, #0xc9
0d95c + bf80c8       movw     0xfc880, AX
0d95f + cf83c803     mov      0xfc883, #0x3
0d963 + f7           clrw     BC
0d964 + eee100       br       0xda48
0d967 + eedd00       br       0xda47
0d96a + 4073c802     cmp      0xfc873, #0x2
0d96e + dd0f         bz       0xd97f
0d970 + 4073c806     cmp      0xfc873, #0x6
0d974 + dd09         bz       0xd97f
0d976 + 4073c807     cmp      0xfc873, #0x7
0d97a + 61e8         skz      
0d97c + eec800       br       0xda47
0d97f + 8f74c8       mov      A, 0xfc874
0d982 + 31031e       bt       A.0, 0xd9a3
0d985 + 4073c806     cmp      0xfc873, #0x6
0d989 + dd0c         bz       0xd997
0d98b + 4073c807     cmp      0xfc873, #0x7
0d98f + df16         bnz      0xd9a7
0d991 + 4072c801     cmp      0xfc872, #0x1
0d995 + df10         bnz      0xd9a7
0d997 + f6           clrw     AX
0d998 + fc558700     call     0x8755
0d99c + f6           clrw     AX
0d99d + fcd7dc00     call     0xdcd7
0d9a1 + ef04         br       0xd9a7
0d9a3 + f7           clrw     BC
0d9a4 + eea100       br       0xda48
0d9a7 + 4073c802     cmp      0xfc873, #0x2
0d9ab + 61e8         skz      
0d9ad + ee9400       br       0xda44
0d9b0 + ac04         movw     AX, [HL+0x4]
0d9b2 + 14           movw     DE, AX
0d9b3 + aa06         movw     AX, [DE+0x6]
0d9b5 + 14           movw     DE, AX
0d9b6 + 89           mov      A, [DE]
0d9b7 + 2c30         sub      A, #0x30
0d9b9 + dd08         bz       0xd9c3
0d9bb + 91           dec      A
0d9bc + dd6e         bz       0xda2c
0d9be + 91           dec      A
0d9bf + dd73         bz       0xda34
0d9c1 + ef7a         br       0xda3d
0d9c3 + 8f74c8       mov      A, 0xfc874
0d9c6 + 313353       bt       A.3, 0xda1c
0d9c9 + 713074c8     set1     0xfc874.3
0d9cd + ac04         movw     AX, [HL+0x4]
0d9cf + 14           movw     DE, AX
0d9d0 + aa06         movw     AX, [DE+0x6]
0d9d2 + 14           movw     DE, AX
0d9d3 + 8a01         mov      A, [DE+0x1]
0d9d5 + 9f7cc8       mov      0xfc87c, A
0d9d8 + ac04         movw     AX, [HL+0x4]
0d9da + 14           movw     DE, AX
0d9db + aa06         movw     AX, [DE+0x6]
0d9dd + a1           incw     AX
0d9de + a1           incw     AX
0d9df + 14           movw     DE, AX
0d9e0 + 89           mov      A, [DE]
0d9e1 + 318e         shrw     AX, #0x8
0d9e3 + bb           movw     [HL], AX
0d9e4 + 440500       cmpw     AX, #0x5
0d9e7 + de05         bnc      0xd9ee
0d9e9 + e57dc8       oneb     0xfc87d
0d9ec + ef2e         br       0xda1c
0d9ee + 5180         mov      A, #0x80
0d9f0 + 5d           and      A, [HL]
0d9f1 + 318e         shrw     AX, #0x8
0d9f3 + 6168         or       A, X
0d9f5 + dd17         bz       0xda0e
0d9f7 + ab           movw     AX, [HL]
0d9f8 + 44f100       cmpw     AX, #0xf1
0d9fb + dc0b         bc       0xda08
0d9fd + ab           movw     AX, [HL]
0d9fe + 44fa00       cmpw     AX, #0xfa
0da01 + de05         bnc      0xda08
0da03 + e57dc8       oneb     0xfc87d
0da06 + ef14         br       0xda1c
0da08 + cf7dc81b     mov      0xfc87d, #0x1b
0da0c + ef0e         br       0xda1c
0da0e + ab           movw     AX, [HL]
0da0f + 040400       addw     AX, #0x4
0da12 + 5205         mov      C, #0x5
0da14 + fd1c06       call     0x61c
0da17 + a1           incw     AX
0da18 + 60           mov      A, X
0da19 + 9f7dc8       mov      0xfc87d, A
0da1c + 8f7cc8       mov      A, 0xfc87c
0da1f + 9f72c8       mov      0xfc872, A
0da22 + e6           onew     AX
0da23 + bf70c8       movw     0xfc870, AX
0da26 + cf73c803     mov      0xfc873, #0x3
0da2a + ef18         br       0xda44
0da2c + 30c900       movw     AX, #0xc9
0da2f + bf70c8       movw     0xfc870, AX
0da32 + ef10         br       0xda44
0da34 + 303200       movw     AX, #0x32
0da37 + fc40d500     call     0xd540
0da3b + ef07         br       0xda44
0da3d + 302600       movw     AX, #0x26
0da40 + fc40d500     call     0xd540
0da44 + f7           clrw     BC
0da45 + ef01         br       0xda48
0da47 + f7           clrw     BC
0da48 + 1006         addw     SP, #0x6
0da4a + c6           pop      HL
0da4b + d7           ret      
0db7e + c7           push     HL
0db7f + 2004         subw     SP, #0x4
0db81 + fbf8ff       movw     HL, SP
0db84 + d590c8       cmp0     0xfc890
0db87 + 61e8         skz      
0db89 + ee9b00       br       0xdc27
0db8c + e590c8       oneb     0xfc890
0db8f + 8f84c8       mov      A, 0xfc884
0db92 + 311532       bf       A.1, 0xdbc7
0db95 + fc3ee000     call     0xe03e
0db99 + 3080c8       movw     AX, #0xc880
0db9c + bc02         movw     [HL+0x2], AX
0db9e + 14           movw     DE, AX
0db9f + 8a04         mov      A, [DE+0x4]
0dba1 + 3169         shl      A, #0x6
0dba3 + 317a         shr      A, #0x7
0dba5 + d1           cmp0     A
0dba6 + dd19         bz       0xdbc1
0dba8 + 711884c8     clr1     0xfc884.1
0dbac + fc62e000     call     0xe062
0dbb0 + f6           clrw     AX
0dbb1 + fcfb8700     call     0x87fb
0dbb5 + 62           mov      A, C
0dbb6 + 9c01         mov      [HL+0x1], A
0dbb8 + 91           dec      A
0dbb9 + dd0a         bz       0xdbc5
0dbbb + 711084c8     set1     0xfc884.1
0dbbf + ef63         br       0xdc24
0dbc1 + fc62e000     call     0xe062
0dbc5 + ef5d         br       0xdc24
0dbc7 + 8f84c8       mov      A, 0xfc884
0dbca + 310557       bf       A.0, 0xdc24
0dbcd + fc3ee000     call     0xe03e
0dbd1 + 3080c8       movw     AX, #0xc880
0dbd4 + bc02         movw     [HL+0x2], AX
0dbd6 + 14           movw     DE, AX
0dbd7 + 8a04         mov      A, [DE+0x4]
0dbd9 + 5c01         and      A, #0x1
0dbdb + d1           cmp0     A
0dbdc + dd42         bz       0xdc20
0dbde + 4091c8ff     cmp      0xfc891, #0xff
0dbe2 + df36         bnz      0xdc1a
0dbe4 + cf91c880     mov      0xfc891, #0x80
0dbe8 + 710884c8     clr1     0xfc884.0
0dbec + 4083c806     cmp      0xfc883, #0x6
0dbf0 + df06         bnz      0xdbf8
0dbf2 + cf4ac832     mov      0xfc84a, #0x32
0dbf6 + ef04         br       0xdbfc
0dbf8 + cf4ac830     mov      0xfc84a, #0x30
0dbfc + e54bc8       oneb     0xfc84b
0dbff + f54cc8       clrb     0xfc84c
0dc02 + e582c8       oneb     0xfc882
0dc05 + f6           clrw     AX
0dc06 + fcfb8700     call     0x87fb
0dc0a + 62           mov      A, C
0dc0b + 9c01         mov      [HL+0x1], A
0dc0d + 91           dec      A
0dc0e + 61e8         skz      
0dc10 + 711084c8     set1     0xfc884.1
0dc14 + fc62e000     call     0xe062
0dc18 + ef0a         br       0xdc24
0dc1a + fc62e000     call     0xe062
0dc1e + ef04         br       0xdc24
0dc20 + fc62e000     call     0xe062
0dc24 + f590c8       clrb     0xfc890
0dc27 + 1004         addw     SP, #0x4
0dc29 + c6           pop      HL
0dc2a + d7           ret      
0dcd7 + c7           push     HL
0dcd8 + 16           movw     HL, AX
0dcd9 + d591c8       cmp0     0xfc891
0dcdc + df06         bnz      0xdce4
0dcde + fceadc00     call     0xdcea
0dce2 + ef04         br       0xdce8
0dce4 + fc41dd00     call     0xdd41
0dce8 + c6           pop      HL
0dce9 + d7           ret      
0dcea + 8f73c8       mov      A, 0xfc873
0dced + 2c05         sub      A, #0x5
0dcef + dd09         bz       0xdcfa
0dcf1 + 91           dec      A
0dcf2 + dd14         bz       0xdd08
0dcf4 + 91           dec      A
0dcf5 + dd21         bz       0xdd18
0dcf7 + 91           dec      A
0dcf8 + df46         bnz      0xdd40
0dcfa + f6           clrw     AX
0dcfb + fc97a400     call     0xa497
0dcff + f6           clrw     AX
0dd00 + bf70c8       movw     0xfc870, AX
0dd03 + f573c8       clrb     0xfc873
0dd06 + ef34         br       0xdd3c
0dd08 + 30c900       movw     AX, #0xc9
0dd0b + bf70c8       movw     0xfc870, AX
0dd0e + cf73c802     mov      0xfc873, #0x2
0dd12 + 713874c8     clr1     0xfc874.3
0dd16 + ef24         br       0xdd3c
0dd18 + d572c8       cmp0     0xfc872
0dd1b + dd14         bz       0xdd31
0dd1d + b072c8       dec      0xfc872
0dd20 + d572c8       cmp0     0xfc872
0dd23 + df0c         bnz      0xdd31
0dd25 + 30c900       movw     AX, #0xc9
0dd28 + bf70c8       movw     0xfc870, AX
0dd2b + cf73c802     mov      0xfc873, #0x2
0dd2f + ef0b         br       0xdd3c
0dd31 + d97dc8       mov      X, 0xfc87d
0dd34 + f1           clrb     A
0dd35 + bf70c8       movw     0xfc870, AX
0dd38 + cf73c803     mov      0xfc873, #0x3
0dd3c + cf91c8ff     mov      0xfc891, #0xff
0dd40 + d7           ret      
0dd41 + 8f83c8       mov      A, 0xfc883
0dd44 + 2c05         sub      A, #0x5
0dd46 + dd04         bz       0xdd4c
0dd48 + 91           dec      A
0dd49 + dd0d         bz       0xdd58
0dd4b + d7           ret      
0dd4c + 30c900       movw     AX, #0xc9
0dd4f + bf80c8       movw     0xfc880, AX
0dd52 + cf83c803     mov      0xfc883, #0x3
0dd56 + ef07         br       0xdd5f
0dd58 + f6           clrw     AX
0dd59 + bf80c8       movw     0xfc880, AX
0dd5c + f583c8       clrb     0xfc883
0dd5f + cf91c8ff     mov      0xfc891, #0xff
0dd63 + d7           ret      
0de62 + 300700       movw     AX, #0x7
0de65 + ec9ed500     br       0xd59e
0de6d + c7           push     HL
0de6e + 16           movw     HL, AX
0de6f + 66           mov      A, L
0de70 + 5c03         and      A, #0x3
0de72 + 348fc8       movw     DE, #0xc88f
0de75 + 70           mov      X, A
0de76 + 89           mov      A, [DE]
0de77 + 5cfc         and      A, #0xfc
0de79 + 6168         or       A, X
0de7b + 99           mov      [DE], A
0de7c + c6           pop      HL
0de7d + d7           ret      
0e03e + c7           push     HL
0e03f + c1           push     AX
0e040 + fbf8ff       movw     HL, SP
0e043 + f6           clrw     AX
0e044 + 4294c8       cmpw     AX, 0xfc894
0e047 + 61e8         skz      
0e049 + ec5ce000     br       0xe05c
0e04d + fc80e000     call     0xe080
0e051 + 62           mov      A, C
0e052 + 9c01         mov      [HL+0x1], A
0e054 + 717bfa       clr1     PSW.7
0e057 + 8c01         mov      A, [HL+0x1]
0e059 + 9f92c8       mov      0xfc892, A
0e05c + a294c8       incw     0xfc894
0e05f + c0           pop      AX
0e060 + c6           pop      HL
0e061 + d7           ret      
0e062 + c7           push     HL
0e063 + c1           push     AX
0e064 + fbf8ff       movw     HL, SP
0e067 + b294c8       decw     0xfc894
0e06a + f6           clrw     AX
0e06b + 4294c8       cmpw     AX, 0xfc894
0e06e + df0d         bnz      0xe07d
0e070 + 8f92c8       mov      A, 0xfc892
0e073 + 9c01         mov      [HL+0x1], A
0e075 + 8c01         mov      A, [HL+0x1]
0e077 + 318e         shrw     AX, #0x8
0e079 + fc85e000     call     0xe085
0e07d + c0           pop      AX
0e07e + c6           pop      HL
0e07f + d7           ret      
0e080   8efa         mov      A, PSW
0e082   72           mov      C, A
0e083   f3           clrb     B
0e084   d7           ret      
0e085   c7           push     HL
0e086   16           movw     HL, AX
0e087   60           mov      A, X
0e088   9efa         mov      PSW, A
0e08a   c6           pop      HL
0e08b   d7           ret      
0e349   c7           push     HL
0e34a   f6           clrw     AX
0e34b   16           movw     HL, AX
0e34c   17           movw     AX, HL
0e34d   444000       cmpw     AX, #0x40
0e350   de08         bnc      0xe35a
0e352   12           movw     BC, AX
0e353   3922c900     mov      [BC+0xc922], #0x0
0e357   a7           incw     HL
0e358   eff2         br       0xe34c
0e35a   e561c9       oneb     0xfc961
0e35d   f562d9       clrb     0xfd962
0e360   cf63d93f     mov      0xfd963, #0x3f
0e364   c6           pop      HL
0e365   d7           ret      
14ce2   c7           push     HL
14ce3   16           movw     HL, AX
14ce4   17           movw     AX, HL
14ce5   f1           clrb     A
14ce6   c9d84402     movw     0xffed8, #0x244
14cea   fd7304       call     0x473
14ced   0462dd       addw     AX, #0xdd62
14cf0   12           movw     BC, AX
14cf1   17           movw     AX, HL
14cf2   f1           clrb     A
14cf3   c9d84402     movw     0xffed8, #0x244
14cf7   fd7304       call     0x473
14cfa   0462dd       addw     AX, #0xdd62
14cfd   14           movw     DE, AX
14cfe   13           movw     AX, BC
14cff   040800       addw     AX, #0x8
14d02   ba3a         movw     [DE+0x3a], AX
14d04   17           movw     AX, HL
14d05   f1           clrb     A
14d06   c9d84402     movw     0xffed8, #0x244
14d0a   fd7304       call     0x473
14d0d   0462dd       addw     AX, #0xdd62
14d10   12           movw     BC, AX
14d11   17           movw     AX, HL
14d12   f1           clrb     A
14d13   c9d84402     movw     0xffed8, #0x244
14d17   fd7304       call     0x473
14d1a   0462dd       addw     AX, #0xdd62
14d1d   14           movw     DE, AX
14d1e   13           movw     AX, BC
14d1f   040800       addw     AX, #0x8
14d22   ba3c         movw     [DE+0x3c], AX
14d24   17           movw     AX, HL
14d25   f1           clrb     A
14d26   c9d84402     movw     0xffed8, #0x244
14d2a   fd7304       call     0x473
14d2d   049add       addw     AX, #0xdd9a
14d30   14           movw     DE, AX
14d31   17           movw     AX, HL
14d32   f1           clrb     A
14d33   c9d84402     movw     0xffed8, #0x244
14d37   fd7304       call     0x473
14d3a   0462dd       addw     AX, #0xdd62
14d3d   12           movw     BC, AX
14d3e   15           movw     AX, DE
14d3f   c3           push     BC
14d40   c4           pop      DE
14d41   ba38         movw     [DE+0x38], AX
14d43   17           movw     AX, HL
14d44   f1           clrb     A
14d45   c9d84402     movw     0xffed8, #0x244
14d49   fd7304       call     0x473
14d4c   12           movw     BC, AX
14d4d   3962dd00     mov      [BC+0xdd62], #0x0
14d51   17           movw     AX, HL
14d52   f1           clrb     A
14d53   c9d84402     movw     0xffed8, #0x244
14d57   fd7304       call     0x473
14d5a   0462dd       addw     AX, #0xdd62
14d5d   12           movw     BC, AX
14d5e   17           movw     AX, HL
14d5f   f1           clrb     A
14d60   c9d84402     movw     0xffed8, #0x244
14d64   fd7304       call     0x473
14d67   04a2df       addw     AX, #0xdfa2
14d6a   14           movw     DE, AX
14d6b   13           movw     AX, BC
14d6c   043e00       addw     AX, #0x3e
14d6f   b9           movw     [DE], AX
14d70   17           movw     AX, HL
14d71   f1           clrb     A
14d72   c9d84402     movw     0xffed8, #0x244
14d76   fd7304       call     0x473
14d79   0462dd       addw     AX, #0xdd62
14d7c   12           movw     BC, AX
14d7d   17           movw     AX, HL
14d7e   f1           clrb     A
14d7f   c9d84402     movw     0xffed8, #0x244
14d83   fd7304       call     0x473
14d86   04a4df       addw     AX, #0xdfa4
14d89   14           movw     DE, AX
14d8a   13           movw     AX, BC
14d8b   043e00       addw     AX, #0x3e
14d8e   b9           movw     [DE], AX
14d8f   17           movw     AX, HL
14d90   f1           clrb     A
14d91   c9d84402     movw     0xffed8, #0x244
14d95   fd7304       call     0x473
14d98   04a0dd       addw     AX, #0xdda0
14d9b   0c02         add      A, #0x2
14d9d   14           movw     DE, AX
14d9e   17           movw     AX, HL
14d9f   f1           clrb     A
14da0   c9d84402     movw     0xffed8, #0x244
14da4   fd7304       call     0x473
14da7   0462dd       addw     AX, #0xdd62
14daa   12           movw     BC, AX
14dab   15           movw     AX, DE
14dac   c3           push     BC
14dad   c4           pop      DE
14dae   35           xchw     AX, DE
14daf   043e02       addw     AX, #0x23e
14db2   35           xchw     AX, DE
14db3   b9           movw     [DE], AX
14db4   c6           pop      HL
14db5   d7           ret      
14db6   c7           push     HL
14db7   c1           push     AX
14db8   2008         subw     SP, #0x8
14dba   fbf8ff       movw     HL, SP
14dbd   afd2e3       movw     AX, 0xfe3d2
14dc0   bc06         movw     [HL+0x6], AX
14dc2   8c12         mov      A, [HL+0x12]
14dc4   d1           cmp0     A
14dc5   dd10         bz       0x14dd7
14dc7   8c08         mov      A, [HL+0x8]
14dc9   318e         shrw     AX, #0x8
14dcb   c9d84402     movw     0xffed8, #0x244
14dcf   fd7304       call     0x473
14dd2   12           movw     BC, AX
14dd3   3962dd00     mov      [BC+0xdd62], #0x0
14dd7   8c08         mov      A, [HL+0x8]
14dd9   318e         shrw     AX, #0x8
14ddb   c9d84402     movw     0xffed8, #0x244
14ddf   fd7304       call     0x473
14de2   0462dd       addw     AX, #0xdd62
14de5   12           movw     BC, AX
14de6   490000       mov      A, [BC]
14de9   d1           cmp0     A
14dea   dd2b         bz       0x14e17
14dec   8c08         mov      A, [HL+0x8]
14dee   318e         shrw     AX, #0x8
14df0   c9d84402     movw     0xffed8, #0x244
14df4   fd7304       call     0x473
14df7   0462dd       addw     AX, #0xdd62
14dfa   12           movw     BC, AX
14dfb   790200       movw     AX, [BC+0x2]
14dfe   12           movw     BC, AX
14dff   ac06         movw     AX, [HL+0x6]
14e01   23           subw     AX, BC
14e02   446500       cmpw     AX, #0x65
14e05   dc10         bc       0x14e17
14e07   8c08         mov      A, [HL+0x8]
14e09   318e         shrw     AX, #0x8
14e0b   c9d84402     movw     0xffed8, #0x244
14e0f   fd7304       call     0x473
14e12   12           movw     BC, AX
14e13   3962dd00     mov      [BC+0xdd62], #0x0
14e17   8c08         mov      A, [HL+0x8]
14e19   318e         shrw     AX, #0x8
14e1b   c9d84402     movw     0xffed8, #0x244
14e1f   fd7304       call     0x473
14e22   0462dd       addw     AX, #0xdd62
14e25   12           movw     BC, AX
14e26   490000       mov      A, [BC]
14e29   d1           cmp0     A
14e2a   dd24         bz       0x14e50
14e2c   91           dec      A
14e2d   dd6c         bz       0x14e9b
14e2f   91           dec      A
14e30   61f8         sknz     
14e32   ee8f00       br       0x14ec4
14e35   91           dec      A
14e36   61f8         sknz     
14e38   eeb300       br       0x14eee
14e3b   91           dec      A
14e3c   61f8         sknz     
14e3e   ee2601       br       0x14f67
14e41   91           dec      A
14e42   61f8         sknz     
14e44   eef101       br       0x15038
14e47   91           dec      A
14e48   61f8         sknz     
14e4a   ee0804       br       0x15255
14e4d   ee1504       br       0x15265
14e50   8c10         mov      A, [HL+0x10]
14e52   4caa         cmp      A, #0xaa
14e54   df3f         bnz      0x14e95
14e56   8c08         mov      A, [HL+0x8]
14e58   d1           cmp0     A
14e59   df12         bnz      0x14e6d
14e5b   8c08         mov      A, [HL+0x8]
14e5d   318e         shrw     AX, #0x8
14e5f   c9d84402     movw     0xffed8, #0x244
14e63   fd7304       call     0x473
14e66   12           movw     BC, AX
14e67   3962dd01     mov      [BC+0xdd62], #0x1
14e6b   ef2b         br       0x14e98
14e6d   8c08         mov      A, [HL+0x8]
14e6f   318e         shrw     AX, #0x8
14e71   c9d84402     movw     0xffed8, #0x244
14e75   fd7304       call     0x473
14e78   12           movw     BC, AX
14e79   3962dd02     mov      [BC+0xdd62], #0x2
14e7d   8c08         mov      A, [HL+0x8]
14e7f   318e         shrw     AX, #0x8
14e81   c9d84402     movw     0xffed8, #0x244
14e85   fd7304       call     0x473
14e88   0462dd       addw     AX, #0xdd62
14e8b   12           movw     BC, AX
14e8c   793c00       movw     AX, [BC+0x3c]
14e8f   14           movw     DE, AX
14e90   ca0000       mov      [DE], #0x0
14e93   ef03         br       0x14e98
14e95   cc10aa       mov      [HL+0x10], #0xaa
14e98   eeca03       br       0x15265
14e9b   8c08         mov      A, [HL+0x8]
14e9d   318e         shrw     AX, #0x8
14e9f   c9d84402     movw     0xffed8, #0x244
14ea3   fd7304       call     0x473
14ea6   0462dd       addw     AX, #0xdd62
14ea9   12           movw     BC, AX
14eaa   793c00       movw     AX, [BC+0x3c]
14ead   14           movw     DE, AX
14eae   8c10         mov      A, [HL+0x10]
14eb0   99           mov      [DE], A
14eb1   8c08         mov      A, [HL+0x8]
14eb3   318e         shrw     AX, #0x8
14eb5   c9d84402     movw     0xffed8, #0x244
14eb9   fd7304       call     0x473
14ebc   12           movw     BC, AX
14ebd   3962dd02     mov      [BC+0xdd62], #0x2
14ec1   eea103       br       0x15265
14ec4   8c08         mov      A, [HL+0x8]
14ec6   318e         shrw     AX, #0x8
14ec8   c9d84402     movw     0xffed8, #0x244
14ecc   fd7304       call     0x473
14ecf   0462dd       addw     AX, #0xdd62
14ed2   12           movw     BC, AX
14ed3   793c00       movw     AX, [BC+0x3c]
14ed6   14           movw     DE, AX
14ed7   8c10         mov      A, [HL+0x10]
14ed9   9a01         mov      [DE+0x1], A
14edb   8c08         mov      A, [HL+0x8]
14edd   318e         shrw     AX, #0x8
14edf   c9d84402     movw     0xffed8, #0x244
14ee3   fd7304       call     0x473
14ee6   12           movw     BC, AX
14ee7   3962dd03     mov      [BC+0xdd62], #0x3
14eeb   ee7703       br       0x15265
14eee   8c08         mov      A, [HL+0x8]
14ef0   318e         shrw     AX, #0x8
14ef2   c9d84402     movw     0xffed8, #0x244
14ef6   fd7304       call     0x473
14ef9   0462dd       addw     AX, #0xdd62
14efc   12           movw     BC, AX
14efd   793c00       movw     AX, [BC+0x3c]
14f00   14           movw     DE, AX
14f01   8c10         mov      A, [HL+0x10]
14f03   9a02         mov      [DE+0x2], A
14f05   8c08         mov      A, [HL+0x8]
14f07   318e         shrw     AX, #0x8
14f09   c9d84402     movw     0xffed8, #0x244
14f0d   fd7304       call     0x473
14f10   0462dd       addw     AX, #0xdd62
14f13   12           movw     BC, AX
14f14   794202       movw     AX, [BC+0x242]
14f17   12           movw     BC, AX
14f18   8c08         mov      A, [HL+0x8]
14f1a   318e         shrw     AX, #0x8
14f1c   c9d84402     movw     0xffed8, #0x244
14f20   fd7304       call     0x473
14f23   0462dd       addw     AX, #0xdd62
14f26   14           movw     DE, AX
14f27   13           movw     AX, BC
14f28   ba04         movw     [DE+0x4], AX
14f2a   8c08         mov      A, [HL+0x8]
14f2c   318e         shrw     AX, #0x8
14f2e   c9d84402     movw     0xffed8, #0x244
14f32   fd7304       call     0x473
14f35   0462dd       addw     AX, #0xdd62
14f38   14           movw     DE, AX
14f39   8c10         mov      A, [HL+0x10]
14f3b   9a06         mov      [DE+0x6], A
14f3d   8c10         mov      A, [HL+0x10]
14f3f   d1           cmp0     A
14f40   dd12         bz       0x14f54
14f42   8c08         mov      A, [HL+0x8]
14f44   318e         shrw     AX, #0x8
14f46   c9d84402     movw     0xffed8, #0x244
14f4a   fd7304       call     0x473
14f4d   12           movw     BC, AX
14f4e   3962dd04     mov      [BC+0xdd62], #0x4
14f52   ef10         br       0x14f64
14f54   8c08         mov      A, [HL+0x8]
14f56   318e         shrw     AX, #0x8
14f58   c9d84402     movw     0xffed8, #0x244
14f5c   fd7304       call     0x473
14f5f   12           movw     BC, AX
14f60   3962dd05     mov      [BC+0xdd62], #0x5
14f64   eefe02       br       0x15265
14f67   8c08         mov      A, [HL+0x8]
14f69   318e         shrw     AX, #0x8
14f6b   c9d84402     movw     0xffed8, #0x244
14f6f   fd7304       call     0x473
14f72   0462dd       addw     AX, #0xdd62
14f75   12           movw     BC, AX
14f76   790400       movw     AX, [BC+0x4]
14f79   a1           incw     AX
14f7a   780400       movw     [BC+0x4], AX
14f7d   b1           decw     AX
14f7e   14           movw     DE, AX
14f7f   8c10         mov      A, [HL+0x10]
14f81   99           mov      [DE], A
14f82   8c08         mov      A, [HL+0x8]
14f84   318e         shrw     AX, #0x8
14f86   c9d84402     movw     0xffed8, #0x244
14f8a   fd7304       call     0x473
14f8d   0462dd       addw     AX, #0xdd62
14f90   12           movw     BC, AX
14f91   790400       movw     AX, [BC+0x4]
14f94   12           movw     BC, AX
14f95   8c08         mov      A, [HL+0x8]
14f97   318e         shrw     AX, #0x8
14f99   c9d84402     movw     0xffed8, #0x244
14f9d   fd7304       call     0x473
14fa0   04a0df       addw     AX, #0xdfa0
14fa3   14           movw     DE, AX
14fa4   a9           movw     AX, [DE]
14fa5   43           cmpw     AX, BC
14fa6   df24         bnz      0x14fcc
14fa8   8c08         mov      A, [HL+0x8]
14faa   318e         shrw     AX, #0x8
14fac   c9d84402     movw     0xffed8, #0x244
14fb0   fd7304       call     0x473
14fb3   0462dd       addw     AX, #0xdd62
14fb6   12           movw     BC, AX
14fb7   8c08         mov      A, [HL+0x8]
14fb9   318e         shrw     AX, #0x8
14fbb   c9d84402     movw     0xffed8, #0x244
14fbf   fd7304       call     0x473
14fc2   0462dd       addw     AX, #0xdd62
14fc5   14           movw     DE, AX
14fc6   13           movw     AX, BC
14fc7   043e00       addw     AX, #0x3e
14fca   ba04         movw     [DE+0x4], AX
14fcc   8c08         mov      A, [HL+0x8]
14fce   318e         shrw     AX, #0x8
14fd0   c9d84402     movw     0xffed8, #0x244
14fd4   fd7304       call     0x473
14fd7   0462dd       addw     AX, #0xdd62
14fda   12           movw     BC, AX
14fdb   790400       movw     AX, [BC+0x4]
14fde   12           movw     BC, AX
14fdf   8c08         mov      A, [HL+0x8]
14fe1   318e         shrw     AX, #0x8
14fe3   c9d84402     movw     0xffed8, #0x244
14fe7   fd7304       call     0x473
14fea   04a2df       addw     AX, #0xdfa2
14fed   14           movw     DE, AX
14fee   a9           movw     AX, [DE]
14fef   43           cmpw     AX, BC
14ff0   df08         bnz      0x14ffa
14ff2   8c08         mov      A, [HL+0x8]
14ff4   318e         shrw     AX, #0x8
14ff6   fce24c01     call     0x14ce2
14ffa   8c08         mov      A, [HL+0x8]
14ffc   318e         shrw     AX, #0x8
14ffe   c9d84402     movw     0xffed8, #0x244
15002   fd7304       call     0x473
15005   0462dd       addw     AX, #0xdd62
15008   12           movw     BC, AX
15009   490600       mov      A, [BC+0x6]
1500c   91           dec      A
1500d   480600       mov      [BC+0x6], A
15010   8c08         mov      A, [HL+0x8]
15012   318e         shrw     AX, #0x8
15014   c9d84402     movw     0xffed8, #0x244
15018   fd7304       call     0x473
1501b   0462dd       addw     AX, #0xdd62
1501e   12           movw     BC, AX
1501f   490600       mov      A, [BC+0x6]
15022   d1           cmp0     A
15023   df10         bnz      0x15035
15025   8c08         mov      A, [HL+0x8]
15027   318e         shrw     AX, #0x8
15029   c9d84402     movw     0xffed8, #0x244
1502d   fd7304       call     0x473
15030   12           movw     BC, AX
15031   3962dd05     mov      [BC+0xdd62], #0x5
15035   ee2d02       br       0x15265
15038   8c08         mov      A, [HL+0x8]
1503a   318e         shrw     AX, #0x8
1503c   c9d84402     movw     0xffed8, #0x244
15040   fd7304       call     0x473
15043   0462dd       addw     AX, #0xdd62
15046   12           movw     BC, AX
15047   794202       movw     AX, [BC+0x242]
1504a   bc02         movw     [HL+0x2], AX
1504c   8c08         mov      A, [HL+0x8]
1504e   318e         shrw     AX, #0x8
15050   c9d84402     movw     0xffed8, #0x244
15054   fd7304       call     0x473
15057   0462dd       addw     AX, #0xdd62
1505a   12           movw     BC, AX
1505b   793c00       movw     AX, [BC+0x3c]
1505e   14           movw     DE, AX
1505f   89           mov      A, [DE]
15060   7caa         xor      A, #0xaa
15062   72           mov      C, A
15063   8c08         mov      A, [HL+0x8]
15065   318e         shrw     AX, #0x8
15067   c9d84402     movw     0xffed8, #0x244
1506b   fd7304       call     0x473
1506e   0462dd       addw     AX, #0xdd62
15071   14           movw     DE, AX
15072   aa3c         movw     AX, [DE+0x3c]
15074   14           movw     DE, AX
15075   8a01         mov      A, [DE+0x1]
15077   6172         xor      C, A
15079   8c08         mov      A, [HL+0x8]
1507b   318e         shrw     AX, #0x8
1507d   c9d84402     movw     0xffed8, #0x244
15081   fd7304       call     0x473
15084   0462dd       addw     AX, #0xdd62
15087   14           movw     DE, AX
15088   aa3c         movw     AX, [DE+0x3c]
1508a   14           movw     DE, AX
1508b   8a02         mov      A, [DE+0x2]
1508d   6172         xor      C, A
1508f   62           mov      A, C
15090   9c01         mov      [HL+0x1], A
15092   f6           clrw     AX
15093   bc04         movw     [HL+0x4], AX
15095   8c08         mov      A, [HL+0x8]
15097   318e         shrw     AX, #0x8
15099   c9d84402     movw     0xffed8, #0x244
1509d   fd7304       call     0x473
150a0   0462dd       addw     AX, #0xdd62
150a3   12           movw     BC, AX
150a4   793c00       movw     AX, [BC+0x3c]
150a7   14           movw     DE, AX
150a8   8a02         mov      A, [DE+0x2]
150aa   318e         shrw     AX, #0x8
150ac   12           movw     BC, AX
150ad   ac04         movw     AX, [HL+0x4]
150af   43           cmpw     AX, BC
150b0   de38         bnc      0x150ea
150b2   ac02         movw     AX, [HL+0x2]
150b4   a1           incw     AX
150b5   bc02         movw     [HL+0x2], AX
150b7   b1           decw     AX
150b8   14           movw     DE, AX
150b9   89           mov      A, [DE]
150ba   7e01         xor      A, [HL+0x1]
150bc   9c01         mov      [HL+0x1], A
150be   8c08         mov      A, [HL+0x8]
150c0   318e         shrw     AX, #0x8
150c2   c9d84402     movw     0xffed8, #0x244
150c6   fd7304       call     0x473
150c9   0462dd       addw     AX, #0xdd62
150cc   12           movw     BC, AX
150cd   793e02       movw     AX, [BC+0x23e]
150d0   614902       cmpw     AX, [HL+0x2]
150d3   df10         bnz      0x150e5
150d5   8c08         mov      A, [HL+0x8]
150d7   318e         shrw     AX, #0x8
150d9   c9d84402     movw     0xffed8, #0x244
150dd   fd7304       call     0x473
150e0   04a0dd       addw     AX, #0xdda0
150e3   bc02         movw     [HL+0x2], AX
150e5   617904       incw     [HL+0x4]
150e8   efab         br       0x15095
150ea   8c01         mov      A, [HL+0x1]
150ec   4e10         cmp      A, [HL+0x10]
150ee   61e8         skz      
150f0   ee3901       br       0x1522c
150f3   8c08         mov      A, [HL+0x8]
150f5   318e         shrw     AX, #0x8
150f7   c9d84402     movw     0xffed8, #0x244
150fb   fd7304       call     0x473
150fe   0462dd       addw     AX, #0xdd62
15101   12           movw     BC, AX
15102   794202       movw     AX, [BC+0x242]
15105   12           movw     BC, AX
15106   8c08         mov      A, [HL+0x8]
15108   318e         shrw     AX, #0x8
1510a   c9d84402     movw     0xffed8, #0x244
1510e   fd7304       call     0x473
15111   0462dd       addw     AX, #0xdd62
15114   14           movw     DE, AX
15115   aa3c         movw     AX, [DE+0x3c]
15117   14           movw     DE, AX
15118   13           movw     AX, BC
15119   ba04         movw     [DE+0x4], AX
1511b   8c08         mov      A, [HL+0x8]
1511d   318e         shrw     AX, #0x8
1511f   c9d84402     movw     0xffed8, #0x244
15123   fd7304       call     0x473
15126   0462dd       addw     AX, #0xdd62
15129   12           movw     BC, AX
1512a   790400       movw     AX, [BC+0x4]
1512d   12           movw     BC, AX
1512e   8c08         mov      A, [HL+0x8]
15130   318e         shrw     AX, #0x8
15132   c9d84402     movw     0xffed8, #0x244
15136   fd7304       call     0x473
15139   04a4df       addw     AX, #0xdfa4
1513c   14           movw     DE, AX
1513d   13           movw     AX, BC
1513e   b9           movw     [DE], AX
1513f   8c08         mov      A, [HL+0x8]
15141   318e         shrw     AX, #0x8
15143   c9d84402     movw     0xffed8, #0x244
15147   fd7304       call     0x473
1514a   0462dd       addw     AX, #0xdd62
1514d   12           movw     BC, AX
1514e   793c00       movw     AX, [BC+0x3c]
15151   040600       addw     AX, #0x6
15154   783c00       movw     [BC+0x3c], AX
15157   8c08         mov      A, [HL+0x8]
15159   318e         shrw     AX, #0x8
1515b   c9d84402     movw     0xffed8, #0x244
1515f   fd7304       call     0x473
15162   0462dd       addw     AX, #0xdd62
15165   12           movw     BC, AX
15166   793c00       movw     AX, [BC+0x3c]
15169   12           movw     BC, AX
1516a   8c08         mov      A, [HL+0x8]
1516c   318e         shrw     AX, #0x8
1516e   c9d84402     movw     0xffed8, #0x244
15172   fd7304       call     0x473
15175   0462dd       addw     AX, #0xdd62
15178   14           movw     DE, AX
15179   aa38         movw     AX, [DE+0x38]
1517b   43           cmpw     AX, BC
1517c   df24         bnz      0x151a2
1517e   8c08         mov      A, [HL+0x8]
15180   318e         shrw     AX, #0x8
15182   c9d84402     movw     0xffed8, #0x244
15186   fd7304       call     0x473
15189   0462dd       addw     AX, #0xdd62
1518c   12           movw     BC, AX
1518d   8c08         mov      A, [HL+0x8]
1518f   318e         shrw     AX, #0x8
15191   c9d84402     movw     0xffed8, #0x244
15195   fd7304       call     0x473
15198   0462dd       addw     AX, #0xdd62
1519b   14           movw     DE, AX
1519c   13           movw     AX, BC
1519d   040800       addw     AX, #0x8
151a0   ba3c         movw     [DE+0x3c], AX
151a2   8c08         mov      A, [HL+0x8]
151a4   318e         shrw     AX, #0x8
151a6   c9d84402     movw     0xffed8, #0x244
151aa   fd7304       call     0x473
151ad   0462dd       addw     AX, #0xdd62
151b0   12           movw     BC, AX
151b1   793c00       movw     AX, [BC+0x3c]
151b4   12           movw     BC, AX
151b5   8c08         mov      A, [HL+0x8]
151b7   318e         shrw     AX, #0x8
151b9   c9d84402     movw     0xffed8, #0x244
151bd   fd7304       call     0x473
151c0   0462dd       addw     AX, #0xdd62
151c3   14           movw     DE, AX
151c4   aa3a         movw     AX, [DE+0x3a]
151c6   43           cmpw     AX, BC
151c7   df63         bnz      0x1522c
151c9   8c08         mov      A, [HL+0x8]
151cb   318e         shrw     AX, #0x8
151cd   c9d84402     movw     0xffed8, #0x244
151d1   fd7304       call     0x473
151d4   0462dd       addw     AX, #0xdd62
151d7   12           movw     BC, AX
151d8   793a00       movw     AX, [BC+0x3a]
151db   040600       addw     AX, #0x6
151de   783a00       movw     [BC+0x3a], AX
151e1   8c08         mov      A, [HL+0x8]
151e3   318e         shrw     AX, #0x8
151e5   c9d84402     movw     0xffed8, #0x244
151e9   fd7304       call     0x473
151ec   0462dd       addw     AX, #0xdd62
151ef   12           movw     BC, AX
151f0   793a00       movw     AX, [BC+0x3a]
151f3   12           movw     BC, AX
151f4   8c08         mov      A, [HL+0x8]
151f6   318e         shrw     AX, #0x8
151f8   c9d84402     movw     0xffed8, #0x244
151fc   fd7304       call     0x473
151ff   0462dd       addw     AX, #0xdd62
15202   14           movw     DE, AX
15203   aa38         movw     AX, [DE+0x38]
15205   43           cmpw     AX, BC
15206   df24         bnz      0x1522c
15208   8c08         mov      A, [HL+0x8]
1520a   318e         shrw     AX, #0x8
1520c   c9d84402     movw     0xffed8, #0x244
15210   fd7304       call     0x473
15213   0462dd       addw     AX, #0xdd62
15216   12           movw     BC, AX
15217   8c08         mov      A, [HL+0x8]
15219   318e         shrw     AX, #0x8
1521b   c9d84402     movw     0xffed8, #0x244
1521f   fd7304       call     0x473
15222   0462dd       addw     AX, #0xdd62
15225   14           movw     DE, AX
15226   13           movw     AX, BC
15227   040800       addw     AX, #0x8
1522a   ba3a         movw     [DE+0x3a], AX
1522c   8c08         mov      A, [HL+0x8]
1522e   d1           cmp0     A
1522f   df12         bnz      0x15243
15231   8c08         mov      A, [HL+0x8]
15233   318e         shrw     AX, #0x8
15235   c9d84402     movw     0xffed8, #0x244
15239   fd7304       call     0x473
1523c   12           movw     BC, AX
1523d   3962dd00     mov      [BC+0xdd62], #0x0
15241   ef22         br       0x15265
15243   8c08         mov      A, [HL+0x8]
15245   318e         shrw     AX, #0x8
15247   c9d84402     movw     0xffed8, #0x244
1524b   fd7304       call     0x473
1524e   12           movw     BC, AX
1524f   3962dd06     mov      [BC+0xdd62], #0x6
15253   ef10         br       0x15265
15255   8c08         mov      A, [HL+0x8]
15257   318e         shrw     AX, #0x8
15259   c9d84402     movw     0xffed8, #0x244
1525d   fd7304       call     0x473
15260   12           movw     BC, AX
15261   3962dd00     mov      [BC+0xdd62], #0x0
15265   8c08         mov      A, [HL+0x8]
15267   318e         shrw     AX, #0x8
15269   c9d84402     movw     0xffed8, #0x244
1526d   fd7304       call     0x473
15270   0462dd       addw     AX, #0xdd62
15273   14           movw     DE, AX
15274   ac06         movw     AX, [HL+0x6]
15276   ba02         movw     [DE+0x2], AX
15278   100a         addw     SP, #0xa
1527a   c6           pop      HL
1527b   d7           ret      
27350   c7           push     HL
27351   c1           push     AX
27352   c1           push     AX
27353   fbf8ff       movw     HL, SP
27356   cc0100       mov      [HL+0x1], #0x0
27359   8c01         mov      A, [HL+0x1]
2735b   d1           cmp0     A
2735c   df1d         bnz      0x2737b
2735e   8c01         mov      A, [HL+0x1]
27360   f0           clrb     X
27361   317e         shrw     AX, #0x7
27363   12           movw     BC, AX
27364   4100         mov      ES, #0x0
27366   1179f06d     movw     AX, ES:[BC+0x6df0]
2736a   614902       cmpw     AX, [HL+0x2]
2736d   df07         bnz      0x27376
2736f   8c01         mov      A, [HL+0x1]
27371   72           mov      C, A
27372   38d1e300     mov      [C+0xe3d1], #0x0
27376   615901       inc      [HL+0x1]
27379   efde         br       0x27359
2737b   1004         addw     SP, #0x4
2737d   c6           pop      HL
2737e   d7           ret      
2737f   c7           push     HL
27380   16           movw     HL, AX
27381   ac08         movw     AX, [HL+0x8]
27383   440500       cmpw     AX, #0x5
27386   dc03         bc       0x2738b
27388   e7           onew     BC
27389   ef0c         br       0x27397
2738b   8fcbe3       mov      A, 0xfe3cb
2738e   5c0c         and      A, #0xc
27390   d1           cmp0     A
27391   df03         bnz      0x27396
27393   f7           clrw     BC
27394   ef01         br       0x27397
27396   e7           onew     BC
27397   c6           pop      HL
27398   d7           ret      
2785c + c7           push     HL
2785d + 16           movw     HL, AX
2785e + fc3ee000     call     0xe03e
27862 + 8fcbe3       mov      A, 0xfe3cb
27865 + 5c0c         and      A, #0xc
27867 + d1           cmp0     A
27868 + dd11         bz       0x2787b
2786a + eb50c0       movw     DE, 0xfc050
2786d + 8a02         mov      A, [DE+0x2]
2786f + 70           mov      X, A
27870 + 8f6ec8       mov      A, 0xfc86e
27873 + 6148         cmp      A, X
27875 + 61e8         skz      
27877 + 7100cce3     set1     0xfe3cc.0
2787b + fc62e000     call     0xe062
2787f + e7           onew     BC
27880 + c6           pop      HL
27881 + d7           ret      
27882 + c7           push     HL
27883 + 16           movw     HL, AX
27884 + fc3ee000     call     0xe03e
27888 + 8fcbe3       mov      A, 0xfe3cb
2788b + 5c0c         and      A, #0xc
2788d + d1           cmp0     A
2788e + dd1a         bz       0x278aa
27890 + eb50c0       movw     DE, 0xfc050
27893 + 8a01         mov      A, [DE+0x1]
27895 + 70           mov      X, A
27896 + 8f6bc8       mov      A, 0xfc86b
27899 + 6148         cmp      A, X
2789b + df09         bnz      0x278a6
2789d + 89           mov      A, [DE]
2789e + 70           mov      X, A
2789f + 8f6ac8       mov      A, 0xfc86a
278a2 + 6148         cmp      A, X
278a4 + 61e8         skz      
278a6 + 7110cce3     set1     0xfe3cc.1
278aa + fc62e000     call     0xe062
278ae + e7           onew     BC
278af + c6           pop      HL
278b0 + d7           ret      
278b1 + c7           push     HL
278b2 + 16           movw     HL, AX
278b3 + fc3ee000     call     0xe03e
278b7 + 8fcbe3       mov      A, 0xfe3cb
278ba + 5c0c         and      A, #0xc
278bc + d1           cmp0     A
278bd + 61f8         sknz     
278bf + ee0601       br       0x279c8
278c2 + eb50c0       movw     DE, 0xfc050
278c5 + 89           mov      A, [DE]
278c6 + 3149         shl      A, #0x4
278c8 + 315a         shr      A, #0x5
278ca + 70           mov      X, A
278cb + 8f52c8       mov      A, 0xfc852
278ce + 3149         shl      A, #0x4
278d0 + 315a         shr      A, #0x5
278d2 + 6148         cmp      A, X
278d4 + 61e8         skz      
278d6 + 7120cce3     set1     0xfe3cc.2
278da + eb50c0       movw     DE, 0xfc050
278dd + 89           mov      A, [DE]
278de + 3129         shl      A, #0x2
278e0 + 316a         shr      A, #0x6
278e2 + 70           mov      X, A
278e3 + 8f52c8       mov      A, 0xfc852
278e6 + 3129         shl      A, #0x2
278e8 + 316a         shr      A, #0x6
278ea + 6148         cmp      A, X
278ec + 61e8         skz      
278ee + 7130cce3     set1     0xfe3cc.3
278f2 + eb50c0       movw     DE, 0xfc050
278f5 + 8a01         mov      A, [DE+0x1]
278f7 + 70           mov      X, A
278f8 + 8f53c8       mov      A, 0xfc853
278fb + 6148         cmp      A, X
278fd + 61e8         skz      
278ff + 7140cce3     set1     0xfe3cc.4
27903 + eb50c0       movw     DE, 0xfc050
27906 + 8a02         mov      A, [DE+0x2]
27908 + 5c03         and      A, #0x3
2790a + 70           mov      X, A
2790b + 8f54c8       mov      A, 0xfc854
2790e + 5c03         and      A, #0x3
27910 + 6148         cmp      A, X
27912 + 61e8         skz      
27914 + 7150cce3     set1     0xfe3cc.5
27918 + eb50c0       movw     DE, 0xfc050
2791b + 8a02         mov      A, [DE+0x2]
2791d + 3149         shl      A, #0x4
2791f + 316a         shr      A, #0x6
27921 + 70           mov      X, A
27922 + 8f54c8       mov      A, 0xfc854
27925 + 3149         shl      A, #0x4
27927 + 316a         shr      A, #0x6
27929 + 6148         cmp      A, X
2792b + 61e8         skz      
2792d + 7160cce3     set1     0xfe3cc.6
27931 + eb50c0       movw     DE, 0xfc050
27934 + 8a02         mov      A, [DE+0x2]
27936 + 314a         shr      A, #0x4
27938 + 70           mov      X, A
27939 + 8f54c8       mov      A, 0xfc854
2793c + 314a         shr      A, #0x4
2793e + 6148         cmp      A, X
27940 + 61e8         skz      
27942 + 7170cce3     set1     0xfe3cc.7
27946 + eb50c0       movw     DE, 0xfc050
27949 + 8a03         mov      A, [DE+0x3]
2794b + 5c0f         and      A, #0xf
2794d + 70           mov      X, A
2794e + 8f55c8       mov      A, 0xfc855
27951 + 5c0f         and      A, #0xf
27953 + 6148         cmp      A, X
27955 + 61e8         skz      
27957 + 7100cde3     set1     0xfe3cd.0
2795b + eb50c0       movw     DE, 0xfc050
2795e + 8a03         mov      A, [DE+0x3]
27960 + 314a         shr      A, #0x4
27962 + 70           mov      X, A
27963 + 8f55c8       mov      A, 0xfc855
27966 + 314a         shr      A, #0x4
27968 + 6148         cmp      A, X
2796a + 61e8         skz      
2796c + 7110cde3     set1     0xfe3cd.1
27970 + eb50c0       movw     DE, 0xfc050
27973 + 8a04         mov      A, [DE+0x4]
27975 + 316a         shr      A, #0x6
27977 + 70           mov      X, A
27978 + 8f56c8       mov      A, 0xfc856
2797b + 316a         shr      A, #0x6
2797d + 6148         cmp      A, X
2797f + 61e8         skz      
27981 + 7120cde3     set1     0xfe3cd.2
27985 + eb50c0       movw     DE, 0xfc050
27988 + 8a06         mov      A, [DE+0x6]
2798a + 5c03         and      A, #0x3
2798c + 70           mov      X, A
2798d + 8f58c8       mov      A, 0xfc858
27990 + 5c03         and      A, #0x3
27992 + 6148         cmp      A, X
27994 + 61e8         skz      
27996 + 7130cde3     set1     0xfe3cd.3
2799a + eb50c0       movw     DE, 0xfc050
2799d + 8a06         mov      A, [DE+0x6]
2799f + 3149         shl      A, #0x4
279a1 + 316a         shr      A, #0x6
279a3 + 70           mov      X, A
279a4 + 8f58c8       mov      A, 0xfc858
279a7 + 3149         shl      A, #0x4
279a9 + 316a         shr      A, #0x6
279ab + 6148         cmp      A, X
279ad + 61e8         skz      
279af + 7140cde3     set1     0xfe3cd.4
279b3 + eb50c0       movw     DE, 0xfc050
279b6 + 8a07         mov      A, [DE+0x7]
279b8 + 316a         shr      A, #0x6
279ba + 70           mov      X, A
279bb + 8f59c8       mov      A, 0xfc859
279be + 316a         shr      A, #0x6
279c0 + 6148         cmp      A, X
279c2 + 61e8         skz      
279c4 + 7150cde3     set1     0xfe3cd.5
279c8 + fc62e000     call     0xe062
279cc + e7           onew     BC
279cd + c6           pop      HL
279ce + d7           ret      
279cf + c7           push     HL
279d0 + 16           movw     HL, AX
279d1 + fc3ee000     call     0xe03e
279d5 + 8fcbe3       mov      A, 0xfe3cb
279d8 + 5c0c         and      A, #0xc
279da + d1           cmp0     A
279db + dd4f         bz       0x27a2c
279dd + eb50c0       movw     DE, 0xfc050
279e0 + 89           mov      A, [DE]
279e1 + 311a         shr      A, #0x1
279e3 + 70           mov      X, A
279e4 + 8f5ac8       mov      A, 0xfc85a
279e7 + 311a         shr      A, #0x1
279e9 + 6148         cmp      A, X
279eb + 61e8         skz      
279ed + 7160cde3     set1     0xfe3cd.6
279f1 + eb50c0       movw     DE, 0xfc050
279f4 + 8a01         mov      A, [DE+0x1]
279f6 + 311a         shr      A, #0x1
279f8 + 70           mov      X, A
279f9 + 8f5bc8       mov      A, 0xfc85b
279fc + 311a         shr      A, #0x1
279fe + 6148         cmp      A, X
27a00 + 61e8         skz      
27a02 + 7170cde3     set1     0xfe3cd.7
27a06 + eb50c0       movw     DE, 0xfc050
27a09 + 8a02         mov      A, [DE+0x2]
27a0b + 311a         shr      A, #0x1
27a0d + 70           mov      X, A
27a0e + 8f5cc8       mov      A, 0xfc85c
27a11 + 311a         shr      A, #0x1
27a13 + 6148         cmp      A, X
27a15 + 61e8         skz      
27a17 + 7100cee3     set1     0xfe3ce.0
27a1b + eb50c0       movw     DE, 0xfc050
27a1e + 8a03         mov      A, [DE+0x3]
27a20 + 70           mov      X, A
27a21 + 8f5dc8       mov      A, 0xfc85d
27a24 + 6148         cmp      A, X
27a26 + 61e8         skz      
27a28 + 7110cee3     set1     0xfe3ce.1
27a2c + fc62e000     call     0xe062
27a30 + e7           onew     BC
27a31 + c6           pop      HL
27a32 + d7           ret      
27a33 + c7           push     HL
27a34 + 16           movw     HL, AX
27a35 + fc3ee000     call     0xe03e
27a39 + 8fcbe3       mov      A, 0xfe3cb
27a3c + 5c0c         and      A, #0xc
27a3e + d1           cmp0     A
27a3f + 61f8         sknz     
27a41 + eec900       br       0x27b0d
27a44 + eb50c0       movw     DE, 0xfc050
27a47 + 8a01         mov      A, [DE+0x1]
27a49 + 70           mov      X, A
27a4a + 8f5fc8       mov      A, 0xfc85f
27a4d + 6148         cmp      A, X
27a4f + df0d         bnz      0x27a5e
27a51 + 89           mov      A, [DE]
27a52 + 5c03         and      A, #0x3
27a54 + 70           mov      X, A
27a55 + 8f5ec8       mov      A, 0xfc85e
27a58 + 5c03         and      A, #0x3
27a5a + 6148         cmp      A, X
27a5c + 61e8         skz      
27a5e + 7120cee3     set1     0xfe3ce.2
27a62 + eb50c0       movw     DE, 0xfc050
27a65 + 89           mov      A, [DE]
27a66 + 3149         shl      A, #0x4
27a68 + 316a         shr      A, #0x6
27a6a + 70           mov      X, A
27a6b + 8f5ec8       mov      A, 0xfc85e
27a6e + 3149         shl      A, #0x4
27a70 + 316a         shr      A, #0x6
27a72 + 6148         cmp      A, X
27a74 + 61e8         skz      
27a76 + 7130cee3     set1     0xfe3ce.3
27a7a + eb50c0       movw     DE, 0xfc050
27a7d + 89           mov      A, [DE]
27a7e + 3119         shl      A, #0x1
27a80 + 315a         shr      A, #0x5
27a82 + 70           mov      X, A
27a83 + 8f5ec8       mov      A, 0xfc85e
27a86 + 3119         shl      A, #0x1
27a88 + 315a         shr      A, #0x5
27a8a + 6148         cmp      A, X
27a8c + 61e8         skz      
27a8e + 7140cee3     set1     0xfe3ce.4
27a92 + eb50c0       movw     DE, 0xfc050
27a95 + 89           mov      A, [DE]
27a96 + 317a         shr      A, #0x7
27a98 + 70           mov      X, A
27a99 + 8f5ec8       mov      A, 0xfc85e
27a9c + 317a         shr      A, #0x7
27a9e + 6148         cmp      A, X
27aa0 + 61e8         skz      
27aa2 + 7150cee3     set1     0xfe3ce.5
27aa6 + eb50c0       movw     DE, 0xfc050
27aa9 + 8a04         mov      A, [DE+0x4]
27aab + 317a         shr      A, #0x7
27aad + 70           mov      X, A
27aae + 8f62c8       mov      A, 0xfc862
27ab1 + 317a         shr      A, #0x7
27ab3 + 6148         cmp      A, X
27ab5 + df14         bnz      0x27acb
27ab7 + 8a03         mov      A, [DE+0x3]
27ab9 + 70           mov      X, A
27aba + 8f61c8       mov      A, 0xfc861
27abd + 6148         cmp      A, X
27abf + df0a         bnz      0x27acb
27ac1 + 8a02         mov      A, [DE+0x2]
27ac3 + 70           mov      X, A
27ac4 + 8f60c8       mov      A, 0xfc860
27ac7 + 6148         cmp      A, X
27ac9 + 61e8         skz      
27acb + 7160cee3     set1     0xfe3ce.6
27acf + eb50c0       movw     DE, 0xfc050
27ad2 + 8a05         mov      A, [DE+0x5]
27ad4 + 70           mov      X, A
27ad5 + 8f63c8       mov      A, 0xfc863
27ad8 + 6148         cmp      A, X
27ada + df0e         bnz      0x27aea
27adc + 8a04         mov      A, [DE+0x4]
27ade + 5c7f         and      A, #0x7f
27ae0 + 70           mov      X, A
27ae1 + 8f62c8       mov      A, 0xfc862
27ae4 + 5c7f         and      A, #0x7f
27ae6 + 6148         cmp      A, X
27ae8 + 61e8         skz      
27aea + 7170cee3     set1     0xfe3ce.7
27aee + eb50c0       movw     DE, 0xfc050
27af1 + 8a07         mov      A, [DE+0x7]
27af3 + 314a         shr      A, #0x4
27af5 + 70           mov      X, A
27af6 + 8f65c8       mov      A, 0xfc865
27af9 + 314a         shr      A, #0x4
27afb + 6148         cmp      A, X
27afd + df0a         bnz      0x27b09
27aff + 8a06         mov      A, [DE+0x6]
27b01 + 70           mov      X, A
27b02 + 8f64c8       mov      A, 0xfc864
27b05 + 6148         cmp      A, X
27b07 + 61e8         skz      
27b09 + 7100cfe3     set1     0xfe3cf.0
27b0d + fc62e000     call     0xe062
27b11 + e7           onew     BC
27b12 + c6           pop      HL
27b13 + d7           ret      
27d68   d7           ret      
27d69   fb80bf       movw     HL, 0xfbf80
27d6c   f6           clrw     AX
27d6d   47           cmpw     AX, HL
27d6e   dd13         bz       0x27d83
27d70   b7           decw     HL
27d71   c7           push     HL
27d72   17           movw     AX, HL
27d73   312d         shlw     AX, #0x2
27d75   0400bf       addw     AX, #0xbf00
27d78   16           movw     HL, AX
27d79   8c02         mov      A, [HL+0x2]
27d7b   9efc         mov      CS, A
27d7d   ab           movw     AX, [HL]
27d7e   c6           pop      HL
27d7f   61ca         call     AX
27d81   efe9         br       0x27d6c
27d83   effe         br       0x27d83
