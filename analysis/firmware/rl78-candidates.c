/*
 * Decompiled by rl78dec -- Renesas RL78 (PS4/Vita syscon).
 * Registers a/x/ax/bc/de/hl etc. are the machine registers; mem8/mem16
 * index data memory (SFRs and saddr cells shown by name).  CY/HF compares
 * are unsigned.  Unmodelled opcodes are printed as pseudo-calls.
 */

void sub_3C7(void)
{
    sel(rb0);
    a = 0;
    cy = 0;
    set_bit(PMC, 0, 0);
    sp = 0xFED2;
    sub_27D68();
    ax = 0;
    ram_BF96 = 0;
    ram_BF80 = 0;
    ram_BF84 = 0;
    ax = 1;
    ram_BF82 = 1;
    ax = 0xBF9A;
    ram_BF98 = 0xBF9A;
    b = 0xC0;
    ax = 0;
    do {
        b = b - 1;
        b = b - 1;
        mem16[0x0FE20 + b] = ax;
    } while (b != 0);
    es = 0;
    hl = 0x6EC2;
    de = 0xE3D2;
    goto loc_405;
    do {
        a = es_mem8[hl];
        mem8[de] = a;
        hl = hl + 1;
        de = de + 1;
loc_405:
        ax = hl;
    } while (hl != 0x758E);
    hl = 0x758E;
    de = 0xEAB1;
    goto loc_41D;
    do {
        es = 0;
        a = es_mem8[hl];
        es = 0xF;
        es_mem8[de] = a;
        hl = hl + 1;
        de = de + 1;
loc_41D:
        ax = hl;
    } while (hl != 0x758E);
    hl = 0xBFBA;
    ax = 0xE3D2;
    goto loc_42F;
    do {
        mem8[hl] = 0;
        hl = hl + 1;
loc_42F:
    } while (ax != hl);
    es = 0xF;
    hl = 0xEAB1;
    ax = 0xEAB1;
    goto loc_441;
    do {
        es_mem8[hl] = 0;
        hl = hl + 1;
loc_441:
    } while (ax != hl);
    es = 0;
    hl = 0x758E;
    de = 0xEAB1;
    goto loc_453;
    do {
        a = es_mem8[hl];
        mem8[de] = a;
        hl = hl + 1;
        de = de + 1;
loc_453:
        ax = hl;
    } while (hl != 0x758E);
    hl = 0xEAB1;
    ax = 0xEAB1;
    goto loc_465;
    do {
        mem8[hl] = 0;
        hl = hl + 1;
loc_465:
    } while (ax != hl);
    sub_7F34();
    ax = 0;
    sub_27D69();
    while (1) {
        continue;
    }
}

void sub_473(void)
{
    push(psw);
    psw = psw & 0x7F;
    ram_FFF0 = ax;
    ax = saddr_D8;
    ram_FFF2 = ax;
    ax = ram_FFF6;
    pop(psw);
    return;
}

void sub_650(void)
{
    ax = ax + saddr_DA;
    saddr_DA = ax;
    ax = saddr_DC;
    ax = ax + saddr_D8;
    saddr_D8 = ax;
    if (CY) {
        saddr_DA = saddr_DA + 1;
    }
    return;
}

void sub_671(void)
{
    if (a != 0) {
        push(ax);
        push(bc);
        bc = saddr_D8;
        saddr_D8 = a;
        ax = saddr_DA;
        do {
            bc = bc << 1;
            ax = rolwc(ax);
            saddr_D8 = saddr_D8 - 1;
        } while (saddr_D8 != 0);
        saddr_DA = ax;
        ax = bc;
        saddr_D8 = bc;
        pop(bc);
        pop(ax);
    }
    return;
}

void sub_68C(void)
{
    if (a != 0) {
        push(ax);
        push(bc);
        bc = saddr_DA;
        saddr_DA = a;
        ax = saddr_D8;
        do {
            ax = ax >> 1;
            xch(ax, bc);
            ax = ax >> 1;
            xch(ax, bc);
            set_bit(a, 7, cy);
            saddr_DA = saddr_DA - 1;
        } while (saddr_DA != 0);
        saddr_D8 = ax;
        ax = bc;
        saddr_DA = bc;
        pop(bc);
        pop(ax);
    }
    return;
}

void sub_D3E(void)
{
    ram_E3D2 = ram_E3D2 + 1;
    return;
}

void sub_D43(void)
{
    push(ax);
    push(bc);
    push(hl);
    ax = saddr_DE;
    push(ax);
    ax = saddr_DC;
    push(ax);
    ax = saddr_DA;
    push(ax);
    ax = saddr_D8;
    push(ax);
    ax = ram_01EE;
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    a = 0 | x;
    if (0 != 0) {
        ax = 0;
        ram_E3DA = 0;
        ram_E3DC = 0;
        goto loc_D9D;
    }
    hl = ram_FF7E;
    ax = hl;
    ax = hl >> 1;
    bc = ax;
    ax = hl;
    ax = hl >> 2;
    ax = ax + bc;
    saddr_D8 = ax;
    ax = 0;
    saddr_DA = 0;
    ax = saddr_D8;
    saddr_DC = ax;
    ax = saddr_DA;
    saddr_DE = ax;
    ax = ram_E3DA;
    saddr_D8 = ax;
    ax = ram_E3DC;
    saddr_DA = ax;
    a = 2;
    sub_68C();
    ax = saddr_DE;
    sub_650();
    ax = saddr_DA;
    ram_E3DC = ax;
    ax = saddr_D8;
    ram_E3DA = ax;
loc_D9D:
    ram_E3DE = ram_E3DE + 1;
    ax = ram_E3D2;
    ram_E3E0 = ax;
    pop(ax);
    saddr_D8 = ax;
    pop(ax);
    saddr_DA = ax;
    pop(ax);
    saddr_DC = ax;
    pop(ax);
    saddr_DE = ax;
    pop(hl);
    pop(bc);
    pop(ax);
    return;
}

void sub_DB7(void)
{
    return;
}

void sub_DB9(void)
{
    ram_E3D5 = 1;
    return;
}

void sub_DBE(void)
{
    ram_E3E2 = 1;
    IF1H = IF1H & 0xFE;
    MK1H = MK1H | 1;
    ADM0 = ADM0 & 0x7F;
    return;
}

void sub_DCC(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    sub_819C();
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_DFC(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    sub_81CD();
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_E2C(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    sub_82B5();
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_E8C(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    ax = ram_0162;
    a = 0;
    xch(0, es);
    a = 0;
    l = 0;
    ax = hl;
    a = 0;
    ram_0166 = hl;
    ax = hl;
    a = 0;
    push(hl);
    a = RXD1;
    ax = hl >> 8;
    push(ax);
    ax = 0;
    sub_14DB6();
    sp = sp + 4;
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_ED4(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    ax = 0;
    push(0);
    a = RXD2;
    ax = 0;
    push(0);
    ax = 1;
    sub_14DB6();
    sp = sp + 4;
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_F0E(void)
{
    push(ax);
    push(de);
    ax = 0;
    if (0 != ram_C8D8) {
        ax = ram_C8D6;
        ram_C8D6 = ram_C8D6 + 1;
        de = ax;
        a = mem8[ax];
        TXD1 = a;
        ram_C8D8 = ram_C8D8 - 1;
        goto loc_F28;
    }
    ram_C8DA = 0;
loc_F28:
    pop(de);
    pop(ax);
    return;
}

void sub_F2C(void)
{
    push(ax);
    push(de);
    ax = 0;
    if (0 != ram_C91E) {
        MK0H = MK0H | 0x80;
        ax = ram_C91C;
        ram_C91C = ram_C91C + 1;
        de = ax;
        a = mem8[ax];
        TXD2 = a;
        ram_C91E = ram_C91E - 1;
        MK0H = MK0H & 0x7F;
        goto loc_F4C;
    }
    ram_C920 = 0;
loc_F4C:
    pop(de);
    pop(ax);
    return;
}

void sub_F50(void)
{
    push(ax);
    push(hl);
    sp = sp - 4;
    hl = sp;
    ax = RXD2;
    mem16[sp + 2] = ax;
    ax = ram_0246;
    a = 0;
    xch(0, x);
    a = 0;
    mem8[sp + 1] = 0;
    ax = ram_0248;
    xch(0, x);
    a = 7;
    xch(7, x);
    ram_0248 = ax;
    sp = sp + 4;
    pop(hl);
    pop(ax);
    return;
}

void sub_F74(void)
{
    push(ax);
    push(bc);
    push(de);
    push(hl);
    c = 0xC;
    do {
        c = c - 1;
        c = c - 1;
        ax = mem16[0x0FED4 + c];
        push(ax);
    } while (!ZF);
    a = es;
    x = es;
    a = cs;
    push(ax);
    sp = sp - 0xE;
    hl = sp;
    ax = ram_E8F6;
    xch(cs, es);
    a = a & 0xF8;
    xch(a, x);
    mem16[sp + 0xC] = ax;
    mem8[sp + 0xA] = 1;
    psw = psw | 0x80;
    a = ram_E8FC;
    if (a != 0) {
        a = 0xC0;
        a = 0xC0 & P9;
        c = a;
        a = 1;
        a = 1 & P10;
        a = a | c;
        ax = ax >> 8;
        mem16[hl + 8] = ax;
        mem8[hl + 0xB] = a;
        while (1) {
            a = mem8[hl + 0xB];
            if (a >= 0xD) goto loc_FD8;
            a = 0xC0;
            a = 0xC0 & P9;
            c = a;
            a = 1;
            a = 1 & P10;
            a = a | c;
            ax = ax >> 8;
            mem16[hl + 6] = ax;
            ax = mem16[hl + 8];
            if (ax != mem16[hl + 6]) {
                mem8[hl + 0xA] = 0;
                mem8[hl + 0xB] = 0x14;
            }
            mem8[hl + 0xB] = mem8[hl + 0xB] + 1;
            continue;
        }
    }
loc_FD8:
    ax = mem16[hl + 8];
    ram_E906 = ax;
    a = mem8[hl + 0xA];
    if (a != 0) JUMPOUT(0x00FE5);
    mem8[hl + 1] = 0;
    de = ram_E400;
    a = mem8[de + 0xA];
    cs = a;
    ax = mem16[de + 8];
    (*ax)();
    a = c;
    if (c == 3) JUMPOUT(0x011DB);
    ax = ram_E8F8;
    if (ax != mem16[hl + 0xC]) {
        ax = mem16[hl + 0xC];
        if (ax == ram_E8F6) {
            ax = ram_E8F8;
            a = a ^ mem8[hl + 0xD];
            xch(a, x);
            a = a ^ mem8[hl + 0xC];
            xch(a, x);
            ram_E8FA = ax;
            ax = ram_E8F8;
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            a = 0 | x;
            if (0 == 0) {
                ax = ram_E8F8;
                a = 0;
                xch(0, x);
                a = 0;
                xch(0, x);
                a = 0 | x;
                if (0 == 0) goto loc_12D4;
            }
            a = 0x18;
            a = 0x18 & mem8[hl + 0xC];
            ax = ax >> 8;
            if (ax == 0x18) {
                x = 0x18;
                if (ax == ram_E8F8) goto loc_12D4;
                ax = ram_E8FA;
                xch(a, x);
                a = a | 0x18;
                xch(a, x);
                ram_E8FA = ax;
            }
loc_12D4:
            ax = mem16[hl + 0xC];
            ram_E8F8 = ax;
            goto loc_12E0;
        }
        ax = mem16[hl + 0xC];
        ram_E8F6 = ax;
    }
loc_12E0:
    sp = sp + 0xE;
    pop(ax);
    cs = a;
    a = x;
    es = x;
    de = 0xFED4;
    c = 6;
    do {
        pop(ax);
        mem16[de] = ax;
        de = de + 1;
        de = de + 1;
        c = c - 1;
    } while (c != 0);
    pop(hl);
    pop(de);
    pop(bc);
    pop(ax);
    return;
}

void sub_12FA(void)
{
    push(ax);
    ax = ram_0132;
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    if (ax == 2) {
        ax = 1;
        ax = 2;
        ram_0136 = 2;
        ram_E976 = 1;
    }
    ram_E977 = 1;
    pop(ax);
    return;
}

void sub_75D0(void)
{
    WDTE = 0xAC;
    return;
}

void sub_75D4(void)
{
    push(hl);
    sp = sp - 4;
    hl = sp;
    P0 = 0;
    P1 = 0;
    P3 = 0;
    P4 = 0;
    P5 = 0;
    P6 = 0;
    P7 = 0;
    P8 = 0;
    P9 = 0;
    P10 = 0;
    P12 = 0;
    P13 = 0;
    P14 = 0;
    P15 = 0;
    PM0 = 0xFF;
    PM1 = 0xFF;
    PM3 = 0xFF;
    PM4 = 0xFF;
    PM5 = 0xFD;
    PM6 = 0xFF;
    PM7 = 0xFF;
    PM8 = 0xFF;
    PM9 = 0xFF;
    PM10 = 0xFF;
    PM12 = 0xFF;
    PM14 = 0xFF;
    PM15 = 0xFF;
    ram_003F = ram_003F | 0x10;
    PM15 = PM15 | 0x10;
    P6 = P6 & 0x7F;
    PM6 = PM6 & 0x7F;
    ram_003E = ram_003E | 1;
    PM14 = PM14 | 1;
    ram_003F = ram_003F | 0x40;
    PM15 = PM15 | 0x40;
    PM15 = PM15 & 0x7F;
    P15 = P15 & 0x7F;
    PM0 = PM0 & 0xFE;
    P0 = P0 & 0xFE;
    if (((P15 >> 4) & 1)) {
        goto loc_76D9;
    }
    CMC = 0x40;
    OSTS = 7;
    a = ram_0070;
    a = a | 1;
    ram_0070 = a;
    CSC = CSC & 0x7F;
    mem8[hl + 1] = 0xFF;
    do {
        a = OSTC;
        mem8[hl] = a;
        a = a & mem8[hl + 1];
        mem8[hl] = a;
        a = mem8[hl];
    } while (a != mem8[hl + 1]);
    psw = psw & 0x7F;
    ram_00F3 = 5;
    psw = psw | 0x80;
    CKC = CKC | 0x10;
    a = ram_0070;
    a = a | 2;
    ram_0070 = a;
    ram_00F7 = 0x90;
    ram_00F7 = ram_00F7 | 1;
    ax = 0;
    mem16[hl + 2] = 0;
    while (1) {
        ax = mem16[hl + 2];
        if (ax >= 0x961) goto loc_769E;
        mem16[hl + 2] = mem16[hl + 2] + 1;
        continue;
    }
loc_769E:
    do {
loc_769E:
        push(hl);
        hl = 0xF6;
        cy = ((mem8[0xF6] >> 7) & 1);
        pop(0xF6);
    } while (!CY);
    ram_00F7 = ram_00F7 | 4;
    do {
        push(hl);
        hl = 0xF6;
        cy = ((mem8[0xF6] >> 3) & 1);
        pop(0xF6);
    } while (!CY);
    a = ram_0070;
    a = a & 0xFD;
    ram_0070 = a;
    CSC = CSC | 0x40;
    CKC = CKC & 0xBF;
    a = CKC;
    a = a & 0xF8;
    CKC = a;
    a = CKC;
    CKC = a;
    CSC = CSC & 0xFE;
    a = ram_0070;
    a = a & 0xFE;
    ram_0070 = a;
    goto loc_774E;
loc_76D9:
    CMC = 0;
    a = ram_0070;
    a = a | 1;
    ram_0070 = a;
    CSC = CSC | 0x80;
    psw = psw & 0x7F;
    ram_00F3 = 1;
    psw = psw | 0x80;
    CKC = CKC & 0xEF;
    a = ram_0070;
    a = a | 2;
    ram_0070 = a;
    ram_00F7 = 0x50;
    ram_00F7 = ram_00F7 | 1;
    ax = 0;
    mem16[hl + 2] = 0;
    while (1) {
        ax = mem16[hl + 2];
        if (ax >= 0x961) goto loc_7715;
        mem16[hl + 2] = mem16[hl + 2] + 1;
        continue;
    }
loc_7715:
    do {
loc_7715:
        push(hl);
        hl = 0xF6;
        cy = ((mem8[0xF6] >> 7) & 1);
        pop(0xF6);
    } while (!CY);
    ram_00F7 = ram_00F7 | 4;
    do {
        push(hl);
        hl = 0xF6;
        cy = ((mem8[0xF6] >> 3) & 1);
        pop(0xF6);
    } while (!CY);
    a = ram_0070;
    a = a & 0xFD;
    ram_0070 = a;
    CSC = CSC | 0x40;
    CKC = CKC & 0xBF;
    a = CKC;
    a = a & 0xF8;
    CKC = a;
    a = CKC;
    CKC = a;
    CSC = CSC & 0xFE;
    a = ram_0070;
    a = a & 0xFE;
    ram_0070 = a;
loc_774E:
    ram_003F = ram_003F & 0xEF;
    PM6 = PM6 | 0x80;
    ram_E3D4 = 0;
    if (!((P14 >> 0) & 1)) {
        ram_E3D4 = ram_E3D4 | 0x10;
    }
    if (!((P15 >> 6) & 1)) {
        ram_E3D4 = ram_E3D4 | 1;
    }
    ram_003E = ram_003E & 0xFE;
    ram_003F = ram_003F & 0xBF;
    PM15 = PM15 | 0x80;
    PM0 = PM0 | 1;
    ram_00F0 = ram_00F0 | 4;
    ax = 0xF810;
    ram_0236 = 0xF810;
    ax = 0;
    x = x - 1;
    ram_0234 = 0;
    MK3L = MK3L | 0x20;
    IF3L = IF3L & 0xDF;
    PR13L = PR13L & 0xDF;
    PR03L = PR03L & 0xDF;
    ax = 1;
    ram_0210 = 1;
    ram_FF90 = 0x5DBF;
    ax = ram_023E;
    xch(a, x);
    a = a & 0xFE;
    xch(a, x);
    ram_023E = ax;
    ax = ram_023C;
    xch(a, x);
    a = a & 0xFE;
    xch(a, x);
    ram_023C = ax;
    ax = ram_023A;
    xch(a, x);
    a = a & 0xFE;
    xch(a, x);
    ram_023A = ax;
    IF3L = IF3L & 0xDF;
    MK3L = MK3L & 0xDF;
    ax = ram_0232;
    xch(a, x);
    a = a | 1;
    xch(a, x);
    ram_0232 = ax;
    sp = sp + 4;
    pop(hl);
    psw = psw | 0x80;
    return;
}

void sub_77CE(void)
{
    psw = psw & 0x7F;
    PM0 = 0xFF;
    PM1 = 0xFF;
    PM3 = 0xFF;
    PM4 = 0xFF;
    PM5 = 0xFD;
    PM6 = 0xFF;
    PM7 = 0xFF;
    PM8 = 0xFF;
    PM9 = 0xFF;
    PM10 = 0xFF;
    PM12 = 0xFF;
    PM14 = 0xFF;
    PM15 = 0xFB;
    PM14 = PM14 & 0xFE;
    PM15 = PM15 & 0x7F;
    PM15 = PM15 & 0xBF;
    PM0 = PM0 & 0xFE;
    PM15 = PM15 & 0xEF;
    PM6 = PM6 & 0x7F;
    PM1 = PM1 & 0xFB;
    PM10 = PM10 & 0x7F;
    PM10 = PM10 & 0xBF;
    PM8 = PM8 & 0xFE;
    PM9 = PM9 & 0xFD;
    PM4 = PM4 & 0x7F;
    PM4 = PM4 & 0xEF;
    P0 = 0;
    P1 = 0;
    P3 = 0;
    P4 = 0;
    P5 = 0;
    P6 = 0;
    P7 = 0;
    P8 = 0;
    P9 = 0;
    P10 = 0;
    P12 = 0;
    P13 = 0;
    P14 = 0;
    P15 = 0;
    ax = ram_0234;
    xch(a, x);
    a = a | 1;
    xch(a, x);
    ram_0234 = ax;
    MK3L = MK3L | 0x20;
    IF3L = IF3L & 0xDF;
    ax = ram_0144;
    xch(a, x);
    a = a | 2;
    xch(a, x);
    ram_0144 = ax;
    MK1H = MK1H | 0x40;
    ram_00F0 = ram_00F0 & 0xEF;
    ax = ram_0174;
    xch(a, x);
    a = a | 3;
    xch(a, x);
    ram_0174 = ax;
    ax = ram_017A;
    xch(a, x);
    a = a & 0xFE;
    xch(a, x);
    ram_017A = ax;
    MK2H = MK2H | 0x80;
    IF2H = IF2H & 0x7F;
    MK2H = MK2H | 0x40;
    IF2H = IF2H & 0xBF;
    ram_00F1 = ram_00F1 & 0xF7;
    ax = 0;
    x = x - 1;
    ram_01F4 = 0;
    ax = 0;
    ram_01FA = 0;
    ram_00F0 = ram_00F0 & 0xFD;
    ADM0 = ADM0 & 0x7F;
    MK1H = MK1H | 1;
    IF1H = IF1H & 0xFE;
    ram_00F0 = ram_00F0 & 0x7F;
    EGP0 = 0;
    EGN0 = 0;
    EGP1 = 0;
    EGN1 = 0;
    MK0L = MK0L | 0x10;
    IF0L = IF0L & 0xEF;
    MK0L = MK0L | 0x40;
    IF0L = IF0L & 0xBF;
    PR10L = PR10L | 0x10;
    PR00L = PR00L | 0x10;
    PR10L = PR10L | 0x40;
    PR00L = PR00L | 0x40;
    EGN0 = 0x14;
    a = ram_FF36;
    a = a & 0xFB;
    ram_FF36 = a;
    IF0L = IF0L & 0xEF;
    MK0L = MK0L & 0xEF;
    IF0L = IF0L & 0xBF;
    MK0L = MK0L & 0xBF;
    PM6 = PM6 & 0xEF;
    PM6 = PM6 & 0xDF;
    P6 = P6 & 0xEF;
    P6 = P6 & 0xDF;
    ram_E3D5 = 0;
    psw = psw | 0x80;
    if (!((P3 >> 0) & 1)) {
        goto loc_78FD;
    }
    stop();
    return;
loc_78FD:
    psw = psw & 0x7F;
    MK0L = MK0L | 0x10;
    IF0L = IF0L & 0xEF;
    MK0L = MK0L | 0x40;
    IF0L = IF0L & 0xBF;
    IF3L = IF3L & 0xDF;
    MK3L = MK3L & 0xDF;
    ax = ram_0232;
    xch(a, x);
    a = a | 1;
    xch(a, x);
    ram_0232 = ax;
    psw = psw | 0x80;
    return;
}

void sub_7920(void)
{
    psw = psw & 0x7F;
    P4 = P4 | 4;
    P6 = P6 | 3;
    P15 = P15 | 4;
    a = PM0;
    a = a & 0xF5;
    PM0 = a;
    a = PM1;
    a = a & 0x1C;
    PM1 = a;
    a = PM3;
    a = a & 0xFD;
    PM3 = a;
    a = PM4;
    a = a & 0xFB;
    PM4 = a;
    a = PM5;
    a = a & 0xEC;
    PM5 = a;
    a = PM6;
    a = a & 0x88;
    PM6 = a;
    a = PM7;
    a = a & 0xEE;
    PM7 = a;
    a = PM10;
    a = a & 0xEF;
    PM10 = a;
    a = PM12;
    a = a & 0xBF;
    PM12 = a;
    a = PM15;
    a = a & 0xDB;
    PM15 = a;
    ram_00F0 = ram_00F0 | 0x10;
    ax = 0;
    ram_0146 = 0;
    ax = ram_0144;
    xch(a, x);
    a = a | 2;
    xch(a, x);
    ram_0144 = ax;
    MK1H = MK1H | 0x40;
    IF1H = IF1H & 0xBF;
    PR11H = PR11H | 0x40;
    PR01H = PR01H | 0x40;
    ax = 7;
    ram_0136 = 7;
    x = 0x24;
    ram_013A = 7;
    x = 0x17;
    ram_013E = 7;
    RXD3 = 0x3A00;
    ax = ram_0148;
    a = a | 2;
    xch(a, 0x17);
    a = a | 2;
    xch(a, 0x17);
    ram_0148 = ax;
    a = ram_FF3C;
    a = a | 0x20;
    ram_FF3C = a;
    ram_00F0 = ram_00F0 | 2;
    ax = 0xF540;
    ram_01F6 = 0xF540;
    ax = 0;
    x = 0x16;
    ram_01F4 = 0;
    MK2H = MK2H | 2;
    IF2H = IF2H & 0xFD;
    MK3L = MK3L | 4;
    IF3L = IF3L & 0xFB;
    ax = 0x801;
    ram_01D0 = 0x801;
    ram_FF70 = 0x400;
    ax = 0x409;
    ram_01DA = 0x409;
    ax = 0;
    ram_FF7A = 0;
    ax = ram_01FE;
    xch(a, 0x16);
    a = a | 0x20;
    xch(a, 0x16);
    ram_01FE = ax;
    ax = ram_01FC;
    xch(a, 0x16);
    a = a & 0xDF;
    xch(a, 0x16);
    ram_01FC = ax;
    ax = ram_01F8;
    xch(a, 0x16);
    a = a & 0xDF;
    xch(a, 0x16);
    ram_01F8 = ax;
    ax = ram_01FA;
    xch(a, 0x16);
    a = a | 0x20;
    xch(a, 0x16);
    ram_01FA = ax;
    MK3L = MK3L | 0x10;
    IF3L = IF3L & 0xEF;
    PR13L = PR13L | 0x10;
    PR03L = PR03L | 0x10;
    ax = 0x8144;
    ram_01DE = 0x8144;
    a = ram_FF3F;
    a = a | 0x80;
    ram_FF3F = a;
    ax = ram_01FE;
    xch(a, 0x16);
    a = a & 0x7E;
    xch(a, 0x16);
    ram_01FE = ax;
    ax = ram_01FC;
    xch(a, 0x16);
    a = a & 0x7E;
    xch(a, 0x16);
    ram_01FC = ax;
    ax = ram_01FA;
    xch(a, 0x16);
    a = a & 0x7E;
    xch(a, 0x16);
    ram_01FA = ax;
    a = ram_FF61;
    a = a & 0xDF;
    ram_FF61 = a;
    IF3L = IF3L & 0xEF;
    MK3L = MK3L & 0xEF;
    ax = ram_01F2;
    xch(a, 0x16);
    a = a | 0xA1;
    xch(a, 0x16);
    ram_01F2 = ax;
    ram_00F0 = ram_00F0 | 0x80;
    ADM0 = 0;
    MK1H = MK1H | 1;
    IF1H = IF1H & 0xFE;
    PR11H = PR11H | 1;
    PR01H = PR01H | 1;
    ram_0017 = 0xE;
    ADM0 = 2;
    ram_FF42 = 0;
    ADS = 0xD;
    ram_FF33 = 0xB;
    a = ADM0;
    a = a | 0x70;
    ADM0 = a;
    IF1H = IF1H & 0xFE;
    MK1H = MK1H | 1;
    ADM0 = ADM0 & 0x7F;
    psw = psw | 0x80;
    return;
}

void sub_7C2E(void)
{
    ax = ram_0162;
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    bc = 1;
    if (ax == 1) {
        IF2H = IF2H | 0x80;
    }
    return;
}

void sub_7CB5(void)
{
    push(hl);
    hl = ax;
    h = 0;
    while (1) {
        a = h;
        if (h >= 0x20) goto loc_7CD6;
        x = 0xE;
        ax = mulu(a, 0xE);
        bc = ax;
        a = mem8[0x0E420 + ax];
        if (a == l) {
            a = h;
            x = 0xE;
            ax = mulu(h, 0xE);
            ax = ax + 0xE420;
            bc = ax;
            goto loc_7CD7;
        }
        h = h + 1;
        continue;
    }
loc_7CD6:
    bc = 0;
loc_7CD7:
    pop(hl);
    return;
}

void sub_7E1F(void)
{
    push(hl);
    push(ax);
    push(ax);
    hl = sp;
    ax = mem16[sp + 2];
    de = ax;
    a = mem8[ax + 2];
    if (a != 0) {
        a = mem8[de + 2];
        ax = ax >> 8;
        sub_7CB5();
        ax = bc;
        mem16[hl] = bc;
        ax = 0;
        if (0 != mem16[hl]) {
            ax = mem16[hl];
            de = ax;
            mem8[ax + 1] = 0;
            ax = mem16[hl + 0xA];
            push(ax);
            ax = mem16[hl];
            sub_7E1F();
            pop(ax);
        }
        ax = mem16[hl + 2];
        de = ax;
        mem8[ax + 2] = 0;
    }
    ax = mem16[hl + 2];
    de = ax;
    a = mem8[ax + 1];
    if (a != 0) {
        a = mem8[de + 1];
        ax = ax >> 8;
        sub_7CB5();
        ax = bc;
        mem16[hl] = bc;
        ax = 0;
        if (0 != mem16[hl]) {
            ax = mem16[hl];
            de = ax;
            mem8[ax + 2] = 0;
            ax = mem16[hl];
            de = ax;
            mem8[ax + 3] = 0;
            ax = mem16[hl + 0xA];
            push(ax);
            ax = mem16[hl];
            sub_7EB6();
            pop(ax);
        }
        ax = mem16[hl + 2];
        de = ax;
        mem8[ax + 1] = 0;
    }
    ax = mem16[hl + 2];
    de = ax;
    mem8[ax] = 0;
    ax = mem16[hl + 2];
    de = ax;
    mem8[ax + 3] = 0;
    sp = sp + 4;
    pop(hl);
    return;
}

void sub_7EB6(void)
{
    push(hl);
    push(ax);
    hl = sp;
    ax = mem16[sp];
    de = ax;
    a = mem8[ax + 0xC];
    cs = a;
    ax = mem16[ax + 0xA];
    de = ax;
    ax = mem16[sp];
    (*de)();
    if (c == 0) {
        ax = mem16[hl + 8];
        push(ax);
        ax = mem16[hl];
        sub_7E1F();
        pop(ax);
        goto loc_7EDB;
    }
    ax = mem16[hl];
    de = ax;
    ax = mem16[hl + 8];
    mem16[de + 8] = ax;
loc_7EDB:
    pop(ax);
    pop(hl);
    return;
}

void sub_7EDE(void)
{
    push(hl);
    l = 0;
    while (1) {
        a = l;
        if (l >= 0x20) goto loc_7EF1;
        x = 0xE;
        ax = mulu(a, 0xE);
        bc = ax;
        mem8[0x0E420 + ax] = 0;
        l = l + 1;
        continue;
    }
loc_7EF1:
    pop(hl);
    return;
}

void sub_7EF3(void)
{
    push(hl);
    ax = ram_E3D2;
    ram_E5E2 = ax;
    l = 0;
    while (1) {
        a = l;
        if (l >= 0x20) goto loc_7F32;
        x = 0xE;
        ax = mulu(a, 0xE);
        ax = ax + 0xE420;
        de = ax;
        a = mem8[ax];
        if (a != 0) {
            a = mem8[de + 3];
            if (a != 0) goto loc_7F2F;
            ax = mem16[de + 8];
            bc = ax;
            ax = ram_E5E2;
            ax = ax - bc;
            bc = ax;
            ax = mem16[de + 6];
            xch(ax, bc);
            if (ax < bc) goto loc_7F2F;
            ax = ram_E5E2;
            push(ax);
            a = l;
            x = 0xE;
            ax = mulu(l, 0xE);
            ax = ax + 0xE420;
            sub_7EB6();
            pop(ax);
        }
loc_7F2F:
        l = l + 1;
        continue;
    }
loc_7F32:
    pop(hl);
    return;
}

void sub_7F34(void)
{
    while (1) {
        push(hl);
        sub_75D4();
        do {
            sub_E349();
            sub_7EDE();
            sub_77CE();
            sub_7920();
            de = ram_E400;
            a = mem8[de + 2];
            cs = a;
            ax = mem16[de];
            hl = ax;
            ax = 1;
            (*hl)();
loc_7C97:
            de = ram_E400;
            a = mem8[de + 0xA];
            cs = a;
            ax = mem16[de + 8];
            (*ax)();
        } while (c == 0);
        sub_75D0();
        sub_7EF3();
        sub_7C2E();
        goto loc_7C97;
        continue;
    }
}

void sub_804F(void)
{
    push(hl);
    push(ax);
    push(ax);
    hl = sp;
    ax = mem16[sp + 2];
    de = ax;
    ax = mem16[ax + 4];
    de = ax;
    ax = mem16[ax + 0xC];
    ax = ax >> 2;
    mem16[sp] = ax;
    ax = 0x712;
    if (0x712 == mem16[sp]) {
        ram_E5E6 = 0;
        ax = 1;
        sub_B97C();
        goto loc_809C;
    }
    ax = 0x548;
    if (0x548 != mem16[hl]) {
        x = 0x58;
        if (ax == mem16[hl]) goto loc_8096;
        ax = 0x314;
        if (0x314 == mem16[hl]) goto loc_8096;
        ax = ax + 1;
        if (ax == mem16[hl]) goto loc_8096;
        x = 0x1B;
        if (ax != mem16[hl]) goto loc_809C;
    }
loc_8096:
    ram_E5E7 = 0;
    ram_E5E8 = 1;
loc_809C:
    bc = 1;
    sp = sp + 4;
    pop(hl);
    return;
}

void sub_80BE(void)
{
    ax = 0;
    bc = 0;
    push(hl);
    push(bc);
    push(ax);
    sp = sp - 0x18;
    hl = sp;
    ax = 0;
    mem16[sp + 0xC] = 0;
    mem16[sp + 0xE] = 0;
    mem16[sp + 8] = 0;
    mem16[sp + 0xA] = 0;
    ax = 0x5D0;
    mem16[sp + 2] = 0x5D0;
    x = 0xC0;
    mem16[sp] = 0x5D0;
    ax = mem16[sp + 0x1A];
    bc = ax;
    ax = mem16[sp + 0x18];
    ram_C064 = ax;
    xch(ax, bc);
    ram_C066 = ax;
    ax = mem16[sp];
    de = ax;
    ax = mem16[ax];
    a = 0;
    xch(0, 0xC0);
    a = 0;
    xch(0, 0xC0);
    bc = 1;
    if (ax != 1) {
        es = 0;
        a = es_mem8[0x6508];
        mem8[de + 0xE] = a;
        ax = mem16[hl];
        de = ax;
        x = 0;
        a = 1;
        mem16[ax] = ax;
    }
    ax = mem16[hl + 2];
    de = ax;
    ax = mem16[ax + 0x10];
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    a = 0 | x;
    if (0 != 0) {
        ax = mem16[de + 0x10];
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        if (ax == 0x18) {
            x = 0x10;
            mem16[de + 0x10] = ax;
        }
        ax = mem16[hl + 2];
        de = ax;
        ax = mem16[ax + 0x10];
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        if (ax == 8) {
            x = 8;
            mem16[de + 0x10] = ax;
        }
        ax = mem16[hl + 2];
        de = ax;
        ax = mem16[ax + 0x10];
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        mem16[de + 0x10] = ax;
    }
    mem8[hl + 6] = 0;
    mem8[hl + 7] = 1;
    a = mem8[hl + 6];
    x = 0;
    ax = ax >> 4;
    bc = 0x600;
    ax = ax + 0x600;
    mem16[hl + 4] = ax;
    a = mem8[hl + 6];
    ax = ax >> 8;
    mem16[hl + 0x16] = ax;
    while (1) {
        a = mem8[hl + 7];
        ax = ax >> 8;
        bc = ax;
        ax = mem16[hl + 0x16];
        if (ax >= bc) goto loc_8379;
        ax = mem16[hl + 4];
        de = ax;
        ax = 1;
        ax = 2;
        mem16[de + 0xE] = 2;
        ax = mem16[hl + 4];
        ax = ax + 0x10;
        mem16[hl + 4] = ax;
        mem16[hl + 0x16] = mem16[hl + 0x16] + 1;
        continue;
    }
loc_8379:
    ax = mem16[hl + 2];
    de = ax;
    ax = mem16[ax + 0x10];
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    a = 0 | x;
    if (0 != 0) {
        ax = 7;
        mem16[de + 0x10] = 7;
        do {
            ax = mem16[hl + 2];
            de = ax;
            ax = mem16[ax + 0x10];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            a = 0 | x;
        } while (0 != 0);
    }
    ax = mem16[hl + 0x18];
    ax = ax + ax;
    bc = ax;
    es = 0;
    a = es_mem8[0x0650C + ax];
    c = a;
    ax = mem16[hl + 2];
    de = ax;
    a = a;
    mem8[ax + 0x1A] = a;
    ax = mem16[hl + 0x18];
    ax = ax + ax;
    bc = ax;
    es = 0;
    ax = es_mem16[0x0650E + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 0x1C] = bc;
    ax = mem16[hl + 0x18];
    ax = ax + ax;
    bc = ax;
    es = 0;
    ax = es_mem16[0x0650A + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 0x16] = bc;
    ax = 0xC076;
    ram_C050 = 0xC076;
    ax = 0;
    mem16[hl + 0x16] = 0;
    while (1) {
        ax = 0;
        if (0 != mem16[hl + 0x16]) goto loc_843F;
        ax = mem16[hl + 0x16];
        mem16[hl + 0x10] = ax;
        a = ram_C054;
        a = a & 4;
        if (a == 4) {
            ax = mem16[hl + 0x10];
            ax = ax + ax;
            ax = ax + 0xC052;
            de = ax;
            ax = mem16[ax];
            mem16[hl + 0x14] = ax;
            if (ax >= 2) goto loc_83FE;
            ax = mem16[hl + 0x14];
            sub_27350();
        }
loc_83FE:
        ax = mem16[hl + 0x10];
        ax = ax + ax;
        bc = ax;
        ax = 0;
        ax = 0xFFFF;
        mem16[0x0C052 + bc] = 0xFFFF;
        ax = mem16[hl + 0x16];
        ax = ax << 4;
        bc = 0x600;
        ax = ax + 0x600;
        mem16[hl + 4] = ax;
        while (1) {
            ax = mem16[hl + 4];
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            a = 0 | x;
            if (0 == 0) goto loc_8424;
            ax = 1;
            mem16[de + 0xE] = 1;
            continue;
        }
loc_8424:
        ax = mem16[hl + 4];
        de = ax;
        ax = 0x1C;
        mem16[de + 0xE] = 0x1C;
        ax = mem16[hl + 4];
        de = ax;
        mem8[ax + 9] = 1;
        ax = mem16[hl + 4];
        de = ax;
        ax = 0x800;
        mem16[de + 0xE] = 0x800;
        mem16[hl + 0x16] = mem16[hl + 0x16] + 1;
        continue;
    }
loc_843F:
    ax = 1;
    mem16[hl + 0x16] = 1;
    while (1) {
        ax = mem16[hl + 0x16];
        if (ax >= 9) goto loc_8479;
        ax = mem16[hl + 0x16];
        ax = ax << 4;
        bc = 0x600;
        ax = ax + 0x600;
        mem16[hl + 4] = ax;
        while (1) {
            ax = mem16[hl + 4];
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            a = 0 | x;
            if (0 == 0) goto loc_8466;
            ax = 1;
            mem16[de + 0xE] = 1;
            continue;
        }
loc_8466:
        ax = mem16[hl + 4];
        de = ax;
        ax = 0x1E;
        mem16[de + 0xE] = 0x1E;
        ax = mem16[hl + 4];
        de = ax;
        mem8[ax + 9] = 0;
        mem16[hl + 0x16] = mem16[hl + 0x16] + 1;
        continue;
    }
loc_8479:
    ax = 9;
    mem16[hl + 0x16] = 9;
    while (1) {
        ax = mem16[hl + 0x16];
        if (ax >= 0xE) goto loc_84DD;
        ax = mem16[hl + 0x16];
        ax = ax - 9;
        ax = ax + 1;
        mem16[hl + 0x12] = ax;
        ax = mem16[hl + 0x16];
        ax = ax << 4;
        bc = 0x600;
        ax = ax + 0x600;
        mem16[hl + 4] = ax;
        while (1) {
            ax = mem16[hl + 4];
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            a = 0 | x;
            if (0 == 0) goto loc_84AA;
            ax = 1;
            mem16[de + 0xE] = 1;
            continue;
        }
loc_84AA:
        ax = mem16[hl + 4];
        de = ax;
        ax = 0x1E;
        mem16[de + 0xE] = 0x1E;
        ax = mem16[hl + 4];
        de = ax;
        mem8[ax + 9] = 0x89;
        ax = mem16[hl + 0x12];
        ax = ax + ax;
        bc = ax;
        es = 0;
        ax = es_mem16[0x064C4 + ax];
        bc = ax;
        ax = mem16[hl + 4];
        de = ax;
        ax = bc;
        mem16[de + 0xC] = bc;
        ax = mem16[hl + 4];
        de = ax;
        ax = 0x800;
        mem16[de + 0xE] = 0x800;
        ax = mem16[hl + 4];
        de = ax;
        x = 0;
        a = 1;
        mem16[ax + 0xE] = ax;
        mem16[hl + 0x16] = mem16[hl + 0x16] + 1;
        continue;
    }
loc_84DD:
    ax = 0xE;
    mem16[hl + 0x16] = 0xE;
    ax = mem16[hl + 0x16];
    if (ax < 0x10) JUMPOUT(0x084EC);
    bc = ram_C066;
    ax = ram_C064;
    xch(ax, bc);
    ram_C066 = ax;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x06518 + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x06510 + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 2] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    ax = ax + 0x6518;
    de = ax;
    de = ax + 1;
    de = de + 1;
    es = 0;
    ax = es_mem16[de];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 4] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    ax = ax + 0x6510;
    de = ax;
    de = ax + 1;
    de = de + 1;
    es = 0;
    ax = es_mem16[de];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 6] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x0651C + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 8] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x06514 + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 0xA] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x0651E + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 0xC] = bc;
    ax = mem16[hl + 0x18];
    ax = ax << 3;
    bc = ax;
    es = 0;
    ax = es_mem16[0x06516 + ax];
    bc = ax;
    ax = mem16[hl + 2];
    de = ax;
    ax = bc;
    mem16[de + 0xE] = bc;
    ax = mem16[hl + 2];
    de = ax;
    ax = mem16[ax + 0x18];
    ram_C086 = 1;
    ax = 0x20;
    mem16[de + 0x10] = 0x20;
    ax = mem16[hl + 2];
    de = ax;
    ax = 0x106;
    mem16[de + 0x10] = 0x106;
    sp = sp + 0x1C;
    pop(hl);
    return;
}

void sub_80D3(void)
{
    push(hl);
    push(ax);
    sp = sp - 8;
    hl = sp;
    ax = 0;
    mem16[sp] = 0;
    mem16[sp + 2] = 0;
    ax = mem16[sp + 8];
    ax = ax << 4;
    bc = 0x600;
    ax = ax + 0x600;
    mem16[sp + 6] = ax;
    ax = 0xC076;
    mem16[sp + 4] = 0xC076;
    while (1) {
        ax = mem16[hl + 6];
        de = ax;
        ax = 4;
        mem16[de + 0xE] = 4;
        ax = mem16[hl + 6];
        de = ax;
        a = mem8[ax + 8];
        c = a;
        ax = mem16[hl + 4];
        de = ax;
        a = a;
        mem8[ax + 8] = a;
        ax = mem16[hl + 4];
        de = ax;
        a = mem8[ax + 8];
        a = a + 1;
        a = a >> 1;
        a = a - 1;
        if (a != 0) {
            a = a - 1;
            if (a != 0) {
                a = a - 1;
                if (a != 0) {
                    a = a - 1;
                    if (a != 0) goto loc_8143;
                    ax = mem16[hl + 6];
                    de = ax;
                    ax = mem16[ax + 6];
                    bc = ax;
                    ax = mem16[hl + 4];
                    de = ax;
                    ax = bc;
                    mem16[de + 6] = bc;
                }
                ax = mem16[hl + 6];
                de = ax;
                ax = mem16[ax + 4];
                bc = ax;
                ax = mem16[hl + 4];
                de = ax;
                ax = bc;
                mem16[de + 4] = bc;
            }
            ax = mem16[hl + 6];
            de = ax;
            ax = mem16[ax + 2];
            bc = ax;
            ax = mem16[hl + 4];
            de = ax;
            ax = bc;
            mem16[de + 2] = bc;
        }
        ax = mem16[hl + 6];
        de = ax;
        ax = mem16[ax];
        bc = ax;
        ax = mem16[hl + 4];
        de = ax;
        ax = bc;
        mem16[de] = bc;
loc_8143:
        ax = mem16[hl + 6];
        de = ax;
        ax = mem16[ax + 0xC];
        bc = ax;
        ax = mem16[hl + 4];
        de = ax;
        ax = bc;
        mem16[de + 0xC] = bc;
        ax = mem16[hl + 6];
        de = ax;
        ax = mem16[ax + 0xE];
        bc = ax;
        ax = mem16[hl + 4];
        de = ax;
        ax = bc;
        mem16[de + 0xE] = bc;
        mem16[hl] = mem16[hl] + 1;
        ax = 0;
        if (0 == mem16[hl]) {
            mem16[hl + 2] = mem16[hl + 2] + 1;
        }
        ax = mem16[hl + 6];
        de = ax;
        ax = mem16[ax + 0xE];
        a = a & 0x20;
        xch(a, x);
        a = a & 4;
        xch(a, x);
        a = a | x;
        if (a == 0) JUMPOUT(0x08179);
        continue;
    }
}

void sub_819C(void)
{
    push(hl);
    sp = sp - 4;
    hl = sp;
    ax = 1;
    ram_05E8 = 1;
    ax = ram_05F4;
    mem16[sp + 2] = ax;
    while (1) {
        a = 2;
        a = 2 & mem8[hl + 2];
        ax = ax >> 8;
        a = a | x;
        if (a != 0) goto loc_81C9;
        a = mem8[hl + 2];
        a = a & 0;
        a = mem8[hl + 3];
        ax = ax >> 8;
        mem16[hl] = ax;
        sub_8E2A();
        ax = ram_05F4;
        mem16[hl + 2] = ax;
        continue;
    }
loc_81C9:
    sp = sp + 4;
    pop(hl);
    return;
}

void sub_81CD(void)
{
    push(hl);
    sp = sp - 8;
    hl = sp;
    ax = 1;
    ax = 2;
    ram_05E8 = 2;
    x = 0x10;
    mem16[sp + 4] = 2;
    ax = 1;
    ax = 0;
    mem16[sp + 2] = 0;
    ax = ram_05F0;
    mem16[sp] = ax;
    while (1) {
        a = 2;
        a = 2 & mem8[hl];
        ax = ax >> 8;
        a = a | x;
        if (a != 0) goto loc_824E;
        a = mem8[hl];
        a = a & 0;
        a = mem8[hl + 1];
        ax = ax >> 8;
        mem16[hl + 6] = ax;
        if (ax >= 0xE) {
            ax = mem16[hl + 6];
            if (ax >= mem16[hl + 4]) goto loc_821F;
            ax = mem16[hl + 6];
            ax = ax << 4;
            bc = 0x600;
            ax = ax + 0x600;
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            if (ax != 4) goto loc_821F;
            ax = mem16[hl + 6];
            sub_8C0E();
            goto loc_8248;
        }
loc_821F:
        ax = mem16[hl + 6];
        if (ax >= 9) {
            ax = mem16[hl + 6];
            if (ax >= mem16[hl + 2]) goto loc_8248;
            ax = mem16[hl + 6];
            ax = ax << 4;
            bc = 0x600;
            ax = ax + 0x600;
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            if (ax != 4) goto loc_8248;
            ax = mem16[hl + 6];
            sub_8CB6();
        }
loc_8248:
        ax = ram_05F0;
        mem16[hl] = ax;
        continue;
    }
loc_824E:
    a = 1;
    a = 1 & mem8[hl];
    ax = ax >> 8;
    a = a | x;
    if (a != 0) {
        ax = 1;
        ram_05F0 = 1;
        x = 0xE;
        mem16[hl + 6] = 1;
        while (1) {
            ax = mem16[hl + 6];
            if (ax >= mem16[hl + 4]) goto loc_8285;
            ax = mem16[hl + 6];
            ax = ax << 4;
            bc = 0x600;
            ax = ax + 0x600;
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            if (ax == 4) {
                ax = mem16[hl + 6];
                sub_8C0E();
            }
            mem16[hl + 6] = mem16[hl + 6] + 1;
            continue;
        }
loc_8285:
        ax = 9;
        mem16[hl + 6] = 9;
        while (1) {
            ax = mem16[hl + 6];
            if (ax >= mem16[hl + 2]) goto loc_82B1;
            ax = mem16[hl + 6];
            ax = ax << 4;
            bc = 0x600;
            ax = ax + 0x600;
            de = ax;
            ax = mem16[ax + 0xE];
            a = 0;
            xch(0, x);
            a = 0;
            xch(0, x);
            if (ax == 4) {
                ax = mem16[hl + 6];
                sub_8CB6();
            }
            mem16[hl + 6] = mem16[hl + 6] + 1;
            continue;
        }
    }
loc_82B1:
    sp = sp + 8;
    pop(hl);
    return;
}

void sub_82B5(void)
{
    ax = ram_05E8;
    a = 0;
    xch(0, x);
    a = 0;
    xch(0, x);
    a = 0 | x;
    if (0 != 0) {
        ax = ram_05E8;
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        a = 0 | x;
        if (0 != 0) {
            ax = 0x18;
            ram_05E8 = 0x18;
        }
        ax = ram_05E8;
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        a = 0 | x;
        if (0 != 0) {
            ax = 4;
            ram_05E8 = 4;
        }
        a = ram_05E3;
        a = a & 0x10;
        if (a == 0) goto loc_8C0D;
        sub_80BE();
    }
loc_8C0D:
    return;
}

void sub_8C0E(void)
{
    push(hl);
    push(ax);
    sp = sp - 6;
    hl = sp;
    ax = 0;
    ax = 0xFFFF;
    mem16[sp] = 0xFFFF;
    ax = mem16[sp + 6];
    sub_80D3();
    ax = 0xC06A;
    mem16[hl + 4] = 0xC06A;
    de = 0xC06A;
    ax = 0xC076;
    mem16[0xC06E] = 0xC076;
    ax = mem16[hl + 4];
    de = ax;
    ax = 0xC076;
    mem16[de + 6] = 0xC076;
    ax = mem16[hl + 4];
    de = ax;
    ax = 0;
    ax = 0xFFFF;
    mem16[de + 8] = 0xFFFF;
    ax = mem16[hl + 4];
    de = ax;
    ax = mem16[ax + 4];
    ax = ax + 0xC;
    de = ax;
    a = mem8[ax];
    a = a & 0;
    xch(a, x);
    a = mem8[ax + 1];
    a = a & 0x80;
    saddr_D8 = ax;
    ax = 0;
    saddr_DA = 0;
    a = 0x10;
    sub_671();
    ax = 0;
    if (0 == saddr_DA) {
    }
    if (ZF) {
        ax = mem16[hl + 4];
        sub_804F();
        if (c == 0) goto loc_8CB2;
        ax = mem16[hl + 4];
        de = ax;
        ax = mem16[ax + 4];
        ax = ax + 0xC;
        de = ax;
        a = mem8[ax];
        a = a & 0xFC;
        xch(a, x);
        a = mem8[ax + 1];
        a = a & 0x1F;
        xch(a, x);
        a = a & 0xFC;
        xch(a, x);
        mem16[hl + 2] = ax;
        ax = 0;
        mem16[hl] = 0;
        while (1) {
            ax = 0;
            if (0 != mem16[hl]) goto loc_8C97;
            ax = mem16[hl];
            ax = ax + ax;
            bc = ax;
            es = 0;
            ax = es_mem16[0x064C4 + ax];
            if (ax == mem16[hl + 2]) goto loc_8C97;
            mem16[hl] = mem16[hl] + 1;
            continue;
        }
loc_8C97:
        ax = 0;
        if (0 != mem16[hl]) goto loc_8CB2;
        ax = mem16[hl];
        ax = ax + ax;
        bc = ax;
        es = 0;
        ax = es_mem16[0x064D0 + ax];
        mem16[hl] = ax;
        ax = mem16[hl + 4];
        de = ax;
        ax = mem16[hl];
        mem16[de + 8] = ax;
        sub_8D20();
        c = c - 1;
    }
loc_8CB2:
    sp = sp + 8;
    pop(hl);
    return;
}

void sub_8CB6(void)
{
    push(hl);
    push(ax);
    sp = sp - 4;
    hl = sp;
    ax = mem16[sp + 4];
    sub_80D3();
    ax = 0xC06A;
    mem16[hl] = 0xC06A;
    de = 0xC06A;
    ax = 0xC076;
    mem16[0xC06E] = 0xC076;
    ax = mem16[hl];
    de = ax;
    ax = 0xC076;
    mem16[de + 6] = 0xC076;
    ax = mem16[hl];
    de = ax;
    ax = mem16[ax + 4];
    ax = ax + 0xC;
    de = ax;
    a = mem8[ax];
    a = a & 0;
    xch(a, x);
    a = mem8[ax + 1];
    a = a & 0x80;
    saddr_D8 = ax;
    ax = 0;
    saddr_DA = 0;
    a = 0x10;
    sub_671();
    ax = 0;
    if (0 == saddr_DA) {
    }
    if (ZF) {
        ax = mem16[hl];
        sub_804F();
        if (c == 0) goto loc_8D1C;
        ax = mem16[hl + 4];
        ax = ax - 9;
        ax = ax + 1;
        mem16[hl + 2] = ax;
        ax = ax + ax;
        bc = ax;
        es = 0;
        ax = es_mem16[0x064D0 + ax];
        mem16[hl + 2] = ax;
        ax = mem16[hl];
        de = ax;
        ax = mem16[hl + 2];
        mem16[de + 8] = ax;
        sub_8D20();
        c = c - 1;
    }
loc_8D1C:
    sp = sp + 6;
    pop(hl);
    return;
}

void sub_8D20(void)
{
    push(hl);
    sp = sp - 8;
    hl = sp;
    ax = 0xC06A;
    mem16[sp + 6] = 0xC06A;
    de = 0xC06A;
    ax = mem16[0xC072];
    bc = ax;
    es = 0;
    a = es_mem8[0x06530 + ax];
    c = a;
    ax = mem16[sp + 6];
    de = ax;
    ax = mem16[ax + 4];
    de = ax;
    a = mem8[ax + 8];
    if (a < c) {
        bc = 0;
        goto loc_8E26;
    }
    ax = mem16[hl + 6];
    de = ax;
    ax = mem16[ax + 4];
    de = ax;
    a = mem8[ax + 8];
    ax = ax >> 8;
    push(ax);
    ax = mem16[hl + 6];
    de = ax;
    ax = mem16[ax + 8];
    sub_9254();
    pop(ax);
    ax = mem16[hl + 6];
    sub_2737F();
    c = c - 1;
    if (c != 0) {
        bc = 0;
        goto loc_8E26;
    }
    ax = mem16[hl + 6];
    de = ax;
    ax = mem16[ax + 8];
    ax = ax << 2;
    ax = ax + 0x64EE;
    de = ax;
    es = 0;
    a = es_mem8[ax + 2];
    saddr_D4 = a;
    ax = es_mem16[ax];
    if (saddr_D4 == 0) {
        bc = 0;
    }
    if (!ZF) {
        ax = mem16[hl + 6];
        de = ax;
        ax = mem16[ax + 8];
        ram_C046 = ax;
        ax = mem16[de + 8];
        ax = ax << 2;
        ax = ax + 0x64EE;
        de = ax;
        es = 0;
        a = es_mem8[ax + 2];
        cs = a;
        ax = es_mem16[ax];
        de = ax;
        ax = mem16[hl + 6];
        (*de)();
        if (c != 0) goto loc_8DAC;
        bc = 0;
        goto loc_8E26;
    }
loc_8DAC:
    ax = mem16[hl + 6];
    de = ax;
    ax = mem16[ax + 8];
    ax = ax + ax;
    ax = ax + 0x64E2;
    de = ax;
    es = 0;
    ax = es_mem16[ax];
    a = a | x;
    if (a != 0) JUMPOUT(0x08DC2);
    bc = 1;
loc_8E26:
    sp = sp + 8;
    pop(hl);
    return;
}

void sub_8E2A(void)
{
    push(hl);
    push(ax);
    sp = sp - 0xE;
    hl = sp;
    ax = mem16[sp + 0xE];
    mem16[sp + 0xC] = ax;
    ax = ax + ax;
    ax = ax + 0xC052;
    de = ax;
    ax = mem16[ax];
    mem16[sp + 0xA] = ax;
    ax = mem16[sp + 0xE];
    ax = ax << 4;
    bc = 0x600;
    ax = ax + 0x600;
    mem16[sp] = ax;
    do {
        ax = mem16[hl];
        de = ax;
        ax = 1;
        mem16[de + 0xE] = 1;
        ax = mem16[hl];
        de = ax;
        ax = mem16[ax + 0xE];
        a = 0;
        xch(0, x);
        a = 0;
        xch(0, x);
        a = 0 | x;
    } while (0 != 0);
    ax = 0;
    ax = 0xFFFF;
    if (0xFFFF != mem16[hl + 0xA]) JUMPOUT(0x08E63);
    sp = sp + 0x10;
    pop(hl);
    return;
}

void sub_9254(void)
{
    push(hl);
    push(ax);
    hl = sp;
    ax = mem16[sp];
    bc = ax;
    es = 0;
    a = es_mem8[0x064DC + ax];
    if (a > mem8[sp + 8]) {
        a = mem8[hl + 8];
        mem8[0x0C049 + bc] = a;
        goto loc_927B;
    }
    ax = mem16[hl];
    bc = ax;
    es = 0;
    a = es_mem8[0x064DC + ax];
    b = a;
    ax = mem16[hl];
    xch(ax, bc);
    mem8[0x0C049 + bc] = a;
loc_927B:
    pop(ax);
    pop(hl);
    return;
}

void sub_B97C(void)
{
    push(hl);
    push(ax);
    push(ax);
    hl = sp;
    mem8[sp + 1] = 3;
    a = mem8[sp + 2];
    if (a != 0) {
        bc = ram_E41A;
        ax = hl;
        ax = hl + 1;
        push(ax);
        a = mem8[0x0000E + bc];
        cs = a;
        ax = mem16[0x0000C + bc];
        de = ax;
        ax = 0x3E;
        (*de)();
        pop(ax);
    }
    sp = sp + 4;
    pop(hl);
    return;
}

void sub_E349(void)
{
    push(hl);
    ax = 0;
    hl = 0;
    while (1) {
        ax = hl;
        if (hl >= 0x40) goto loc_E35A;
        bc = ax;
        mem8[0x0C922 + ax] = 0;
        hl = hl + 1;
        continue;
    }
loc_E35A:
    ram_C961 = 1;
    ram_D962 = 0;
    ram_D963 = 0x3F;
    pop(hl);
    return;
}

void sub_14DB6(void)
{
    push(hl);
    push(ax);
    sp = sp - 8;
    hl = sp;
    ax = ram_E3D2;
    mem16[sp + 6] = ax;
    a = mem8[sp + 0x12];
    if (a != 0) {
        a = mem8[hl + 8];
        ax = ax >> 8;
        saddr_D8 = 0x244;
        sub_473();
        bc = ax;
        mem8[0x0DD62 + ax] = 0;
    }
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    ax = ax + 0xDD62;
    bc = ax;
    a = mem8[0x00000 + ax];
    if (a != 0) {
        a = mem8[hl + 8];
        ax = ax >> 8;
        saddr_D8 = 0x244;
        sub_473();
        ax = ax + 0xDD62;
        bc = ax;
        ax = mem16[0x00002 + ax];
        bc = ax;
        ax = mem16[hl + 6];
        ax = ax - bc;
        if (ax < 0x65) goto loc_14E17;
        a = mem8[hl + 8];
        ax = ax >> 8;
        saddr_D8 = 0x244;
        sub_473();
        bc = ax;
        mem8[0x0DD62 + ax] = 0;
    }
loc_14E17:
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    ax = ax + 0xDD62;
    bc = ax;
    a = mem8[0x00000 + ax];
    if (a != 0) {
        a = a - 1;
        if (a == 0) goto loc_14E9B;
        a = a - 1;
        if (a != 0) JUMPOUT(0x14E35);
        goto loc_14EC4;
    }
    a = mem8[hl + 0x10];
    if (a == 0xAA) {
        a = mem8[hl + 8];
        if (a == 0) {
            a = mem8[hl + 8];
            ax = ax >> 8;
            saddr_D8 = 0x244;
            sub_473();
            bc = ax;
            mem8[0x0DD62 + ax] = 1;
            goto loc_14E98;
        }
        a = mem8[hl + 8];
        ax = ax >> 8;
        saddr_D8 = 0x244;
        sub_473();
        bc = ax;
        mem8[0x0DD62 + ax] = 2;
        a = mem8[hl + 8];
        ax = ax >> 8;
        saddr_D8 = 0x244;
        sub_473();
        ax = ax + 0xDD62;
        bc = ax;
        ax = mem16[0x0003C + ax];
        de = ax;
        mem8[ax] = 0;
        goto loc_14E98;
    }
    mem8[hl + 0x10] = 0xAA;
loc_14E98:
    goto loc_15265;
loc_14E9B:
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    ax = ax + 0xDD62;
    bc = ax;
    ax = mem16[0x0003C + ax];
    de = ax;
    a = mem8[hl + 0x10];
    mem8[ax] = a;
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    bc = ax;
    mem8[0x0DD62 + ax] = 2;
    goto loc_15265;
loc_14EC4:
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    ax = ax + 0xDD62;
    bc = ax;
    ax = mem16[0x0003C + ax];
    de = ax;
    a = mem8[hl + 0x10];
    mem8[ax + 1] = a;
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    bc = ax;
    mem8[0x0DD62 + ax] = 3;
loc_15265:
    a = mem8[hl + 8];
    ax = ax >> 8;
    saddr_D8 = 0x244;
    sub_473();
    ax = ax + 0xDD62;
    de = ax;
    ax = mem16[hl + 6];
    mem16[de + 2] = ax;
    sp = sp + 0xA;
    pop(hl);
    return;
}

void sub_27350(void)
{
    push(hl);
    push(ax);
    push(ax);
    hl = sp;
    mem8[sp + 1] = 0;
    while (1) {
        a = mem8[hl + 1];
        if (a != 0) goto loc_2737B;
        a = mem8[hl + 1];
        x = 0;
        ax = ax >> 7;
        bc = ax;
        es = 0;
        ax = es_mem16[0x06DF0 + ax];
        if (ax == mem16[hl + 2]) {
            a = mem8[hl + 1];
            c = a;
            mem8[0x0E3D1 + a] = 0;
        }
        mem8[hl + 1] = mem8[hl + 1] + 1;
        continue;
    }
loc_2737B:
    sp = sp + 4;
    pop(hl);
    return;
}

void sub_2737F(void)
{
    push(hl);
    hl = ax;
    ax = mem16[ax + 8];
    if (ax >= 5) {
        bc = 1;
        goto loc_27397;
    }
    a = ram_E3CB;
    a = a & 0xC;
    if (a == 0) {
        bc = 0;
        goto loc_27397;
    }
    bc = 1;
loc_27397:
    pop(hl);
    return;
}

void sub_27D68(void)
{
    return;
}

void sub_27D69(void)
{
    hl = ram_BF80;
    while (1) {
        ax = 0;
        if (0 == hl) goto loc_27D83;
        hl = hl - 1;
        push(hl);
        ax = hl;
        ax = hl << 2;
        ax = ax + 0xBF00;
        hl = ax;
        a = mem8[ax + 2];
        cs = a;
        ax = mem16[ax];
        pop(hl);
        (*ax)();
        continue;
    }
loc_27D83:
    while (1) {
loc_27D83:
        continue;
    }
}
