ram:000314 61dd push PSW
ram:000316 717bfa DI
ram:000319 cf060800 mov !0xf0806,0x0
ram:00031d 61ff SEL RB3
ram:00031f 520c mov ,0xc
ram:000321 fc120200 call !!0x212
ram:000325 fcf8ff0e call !!0xefff8
ram:000329 d3 cmp0 B
ram:00032a dd09 bz $ 0x335
ram:00032c fc380200 call !!0x238
ram:000330 61cd pop PSW
ram:000332 f8e3 mov C,0xffe03
ram:000334 d7 ret
ram:000335 cec0a5 mov 0xfffc0,0xa5
ram:000338 cec40c mov 0xfffc4,0xc
ram:00033b cec4f3 mov 0xfffc4,0xf3
ram:00033e cec40c mov 0xfffc4,0xc
ram:000341 717bbe clr1 0xfffbe.0x7
ram:000344 61cf SEL RB0
ram:000346 4100 mov ES,0x0
ram:000348 11af0000 movw AX,ES:!0xf0000
ram:00034c cefc00 mov CS,0x0
ram:00034f 61cb br AX
