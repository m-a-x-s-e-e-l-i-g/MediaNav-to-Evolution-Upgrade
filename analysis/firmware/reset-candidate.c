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
