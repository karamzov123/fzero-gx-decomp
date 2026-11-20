#include "types.h"


/* --- rel/movie_module/mpvvlc_InitMbTypeBpic.c --- */
extern signed short lbl_12_bss_6330[64];

void mpvvlc_InitMbTypeBpic(void) {
    signed short *output = lbl_12_bss_6330;
    int i;
    long entry_count = 16;
    *output++ = 0x1F00;
    *output++ = 0x1106;
    *output++ = 0x1606;
    *output++ = 0x1A06;
    for (i = 0; i < 2; i++)
        *output++ = 0x1E05;
    for (i = 0; i < 2; i++)
        *output++ = 0x0105;
    for (i = 0; i < 4; i++)
        *output++ = 0x0804;
    for (i = 0; i < 4; i++)
        *output++ = 0x0A04;
    for (i = 0; i < 8; i++)
        *output++ = 0x0403;
    for (i = 0; i < 8; i++)
        *output++ = 0x0603;
    for (i = 0; i < entry_count; i++)
        *output++ = 0x0C02;
    for (i = 0; i < entry_count; i++)
        *output++ = 0x0E02;
}

/* --- rel/movie_module/fn_12_1014C.c --- */
extern u16 lbl_12_bss_63B0[32];

void fn_12_1014C(void) {
    u16 *table = lbl_12_bss_63B0;
    s32 i = 0;

    table[0] = 0x1106;
    table[1] = 0x1205;
    table[2] = 0x1a05;
    table[3] = 0x0105;
    table[4] = 0x0803;
    table[5] = 0x0803;
    table[6] = 0x0803;
    table[7] = 0x0803;
    table[8] = 0x0202;
    table[9] = 0x0202;
    table[10] = 0x0202;
    table[11] = 0x0202;
    table[12] = 0x0202;
    table[13] = 0x0202;
    table[14] = 0x0202;
    table[15] = 0x0202;
    if (i < 0x10) {
        table[16] = 0x0a01;
        table[17] = 0x0a01;
        table[18] = 0x0a01;
        table[19] = 0x0a01;
        table[20] = 0x0a01;
        table[21] = 0x0a01;
        table[22] = 0x0a01;
        table[23] = 0x0a01;
        table[24] = 0x0a01;
        table[25] = 0x0a01;
        table[26] = 0x0a01;
        table[27] = 0x0a01;
        table[28] = 0x0a01;
        table[29] = 0x0a01;
        table[30] = 0x0a01;
        table[31] = 0x0a01;
    }
}
