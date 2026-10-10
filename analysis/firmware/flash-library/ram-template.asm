; 61-byte RAM template, source coordinates; ISA candidate, not executed
00314 61dd         push     PSW
00316 717bfa       clr1     PSW.7
00319 cf060800     mov      0xf0806, #0x0
0031d 61ff         sel      RB3
0031f 520c         mov      C, #0xc
00321 fc120200     call     0x212
00325 fcf8ff0e     call     0xefff8
00329 d3           cmp0     B
0032a dd09         bz       0x335
0032c fc380200     call     0x238
00330 61cd         pop      PSW
00332 f8e3         mov      C, 0xffee3
00334 d7           ret      
00335 cec0a5       mov      0xfffc0, #0xa5
00338 cec40c       mov      0xfffc4, #0xc
0033b cec4f3       mov      0xfffc4, #0xf3
0033e cec40c       mov      0xfffc4, #0xc
00341 717bbe       clr1     0xfffbe.7
00344 61cf         sel      RB0
00346 4100         mov      ES, #0x0
00348 11af0000     movw     AX, ES:0x0
0034c cefc00       mov      CS, #0x0
0034f 61cb         br       AX
