#include "types.h"


/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */
extern unsigned char lbl_12_bss_54F0[1024];

static inline void mpvvlc_EmitDc(signed char **output, long count, signed char value) {
    int i;
    for (i = 0; i < count; i++) {
        *(*output)++ = value;
    }
}

void mpvvlc2_InitDcSizC(void) {
    signed char *output = (signed char *)lbl_12_bss_54F0;
    mpvvlc_EmitDc(&output, 256, 0x02);
    mpvvlc_EmitDc(&output, 256, 0x12);
    mpvvlc_EmitDc(&output, 256, 0x22);
    mpvvlc_EmitDc(&output, 128, 0x33);
    mpvvlc_EmitDc(&output, 64, 0x44);
    mpvvlc_EmitDc(&output, 32, 0x55);
    mpvvlc_EmitDc(&output, 16, 0x66);
    output[0] = 0x77;
    output[1] = 0x77;
    output[2] = 0x77;
    output[3] = 0x77;
    output[4] = 0x77;
    output[5] = 0x77;
    output[6] = 0x77;
    output[7] = 0x77;
    output[8] = 0x88;
    output[9] = 0x88;
    output[10] = 0x88;
    output[11] = 0x88;
    output[12] = 0x99;
    output[13] = 0x99;
    output[14] = 0xAA;
    output[15] = 0xBA;
}

/* --- rel/movie_module/mpvvlc2_InitDcSizY.c --- */
extern unsigned char lbl_12_bss_58F0[1024];


void mpvvlc2_InitDcSizY(void) {
    signed char *output = (signed char *)lbl_12_bss_58F0;
    mpvvlc_EmitDc(&output, 256, 0x12);
    mpvvlc_EmitDc(&output, 256, 0x22);
    mpvvlc_EmitDc(&output, 128, 0x03);
    mpvvlc_EmitDc(&output, 128, 0x33);
    mpvvlc_EmitDc(&output, 128, 0x43);
    mpvvlc_EmitDc(&output, 64, 0x54);
    mpvvlc_EmitDc(&output, 32, 0x65);
    mpvvlc_EmitDc(&output, 16, 0x76);
    output[0] = 0x87;
    output[1] = 0x87;
    output[2] = 0x87;
    output[3] = 0x87;
    output[4] = 0x87;
    output[5] = 0x87;
    output[6] = 0x87;
    output[7] = 0x87;
    output[8] = 0x98;
    output[9] = 0x98;
    output[10] = 0x98;
    output[11] = 0x98;
    output[12] = 0xA9;
    output[13] = 0xA9;
    output[14] = 0xB9;
    output[15] = 0xB9;
}

/* --- rel/movie_module/fn_12_ED30.c --- */
void fn_12_ED30(void);

extern unsigned char lbl_12_bss_5CF0[128];

static inline void mpvvlc_fill_u8(signed char **output, long count, signed char value) {
    int i;
    for (i = 0; i < count; i++) {
        *(*output)++ = value;
    }
}

void fn_12_ED30(void) {
    signed char *output = (signed char *)lbl_12_bss_5CF0;
    mpvvlc_fill_u8(&output, 32, 0x02);
    mpvvlc_fill_u8(&output, 32, 0x12);
    mpvvlc_fill_u8(&output, 32, 0x22);
    mpvvlc_fill_u8(&output, 16, 0x33);
    mpvvlc_fill_u8(&output, 8, 0x44);
    mpvvlc_fill_u8(&output, 4, 0x55);
    mpvvlc_fill_u8(&output, 2, 0x66);
    *output++ = 0x77;
    *output = 0x88;
}

/* --- rel/movie_module/fn_12_EFA4.c --- */
void fn_12_EFA4(void);

extern unsigned char lbl_12_bss_5D70[128];


void fn_12_EFA4(void) {
    signed char *output = (signed char *)lbl_12_bss_5D70;
    mpvvlc_fill_u8(&output, 32, 0x12);
    mpvvlc_fill_u8(&output, 32, 0x22);
    mpvvlc_fill_u8(&output, 16, 0x03);
    mpvvlc_fill_u8(&output, 16, 0x33);
    mpvvlc_fill_u8(&output, 16, 0x43);
    mpvvlc_fill_u8(&output, 8, 0x54);
    mpvvlc_fill_u8(&output, 4, 0x65);
    mpvvlc_fill_u8(&output, 2, 0x76);
    *output++ = 0x87;
    *output = 0x87;
}

/* --- rel/movie_module/mpvvlc_InitCbpSub2.c --- */
static inline void mpvvlc_EmitCbp(signed short **output, long count, signed short value) {
    int i;
    for (i = 0; i < count; i++) {
        *(*output)++ = value;
    }
}

signed short *mpvvlc_InitCbpSub2(signed short *output) {
    int i;
    for (i = 0; i < 4; i++)
        *output++ = 0xA207;
    for (i = 0; i < 4; i++)
        *output++ = 0x9207;
    for (i = 0; i < 4; i++)
        *output++ = 0x8A07;
    for (i = 0; i < 4; i++)
        *output++ = 0x8607;
    for (i = 0; i < 4; i++)
        *output++ = 0x6107;
    for (i = 0; i < 4; i++)
        *output++ = 0x5107;
    for (i = 0; i < 4; i++)
        *output++ = 0x4907;
    for (i = 0; i < 4; i++)
        *output++ = 0x4507;
    for (i = 0; i < 8; i++)
        *output++ = 0xFF06;
    for (i = 0; i < 8; i++)
        *output++ = 0xC306;
    for (i = 0; i < 8; i++)
        *output++ = 0x2406;
    for (i = 0; i < 8; i++)
        *output++ = 0x1806;
    mpvvlc_EmitCbp(&output, 16, 0xBE05);
    mpvvlc_EmitCbp(&output, 16, 0x8205);
    mpvvlc_EmitCbp(&output, 16, 0x7D05);
    mpvvlc_EmitCbp(&output, 16, 0x4105);
    mpvvlc_EmitCbp(&output, 16, 0x3805);
    mpvvlc_EmitCbp(&output, 16, 0x3405);
    mpvvlc_EmitCbp(&output, 16, 0x2C05);
    mpvvlc_EmitCbp(&output, 16, 0x1C05);
    mpvvlc_EmitCbp(&output, 16, 0x2805);
    mpvvlc_EmitCbp(&output, 16, 0x1405);
    mpvvlc_EmitCbp(&output, 16, 0x3005);
    mpvvlc_EmitCbp(&output, 16, 0x0C05);
    mpvvlc_EmitCbp(&output, 32, 0x2004);
    mpvvlc_EmitCbp(&output, 32, 0x1004);
    mpvvlc_EmitCbp(&output, 32, 0x0804);
    mpvvlc_EmitCbp(&output, 32, 0x0404);
    mpvvlc_EmitCbp(&output, 64, 0x3C03);
    return output;
}
