#include "types.h"

/* --- rel/movie_module/fn_12_E0F4.c --- */
void fn_12_E0F4(void);

extern unsigned int lbl_12_bss_52F0[128];

static inline void mpvvlc_fill_u32(unsigned int **output, long count, unsigned int value) {
    int i;
    for (i = 0; i < count; i++) {
        *(*output)++ = value;
    }
}

#pragma opt_propagation off
void fn_12_E0F4(void) {
    unsigned int *output = lbl_12_bss_52F0;
    int i = 0;
    mpvvlc_fill_u32(&output, 4, 0x00000000);
    mpvvlc_fill_u32(&output, 4, 0x00064040);
    mpvvlc_fill_u32(&output, 2, 0x00080202);
    mpvvlc_fill_u32(&output, 2, 0x00080109);
    mpvvlc_fill_u32(&output, 2, 0x00080400);
    mpvvlc_fill_u32(&output, 2, 0x00080108);
    mpvvlc_fill_u32(&output, 4, 0x00070107);
    mpvvlc_fill_u32(&output, 4, 0x00070106);
    mpvvlc_fill_u32(&output, 4, 0x00070201);
    mpvvlc_fill_u32(&output, 4, 0x00070105);
    mpvvlc_fill_u32(&output, 1, 0x0009010D);
    mpvvlc_fill_u32(&output, 1, 0x00090600);
    mpvvlc_fill_u32(&output, 1, 0x0009010C);
    mpvvlc_fill_u32(&output, 1, 0x0009010B);
    mpvvlc_fill_u32(&output, 1, 0x00090203);
    mpvvlc_fill_u32(&output, 1, 0x00090301);
    mpvvlc_fill_u32(&output, 1, 0x00090500);
    mpvvlc_fill_u32(&output, 1, 0x0009010A);
    mpvvlc_fill_u32(&output, 8, 0x00060300);
    mpvvlc_fill_u32(&output, 8, 0x00060104);
    mpvvlc_fill_u32(&output, 8, 0x00060103);
    for (i = 0; i < 16; i++)
        *output++ = 0x00050200;
    mpvvlc_fill_u32(&output, 16, 0x00050102);
    mpvvlc_fill_u32(&output, 32, 0x00040101);
}
#pragma opt_propagation reset

/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */
/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */
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

/* --- rel/movie_module/fn_12_FA5C.c --- */
signed short *fn_12_FA5C(signed short *output) {
    *output++ = 0;
    *output++ = 0;
    *output++ = -0x18F7;
    *output++ = -0x24F7;
    *output++ = -0x4F7;
    *output++ = -0x8F7;
    *output++ = -0x10F7;
    *output++ = -0x20F7;
    *output++ = -0x45F8;
    *output++ = -0x45F8;
    *output++ = -0x49F8;
    *output++ = -0x49F8;
    *output++ = -0x51F8;
    *output++ = -0x51F8;
    *output++ = -0x61F8;
    *output++ = -0x61F8;
    *output++ = 0x7908;
    *output++ = 0x7908;
    *output++ = 0x7508;
    *output++ = 0x7508;
    *output++ = 0x6D08;
    *output++ = 0x6D08;
    *output++ = 0x5D08;
    *output++ = 0x5D08;
    *output++ = -0x59F8;
    *output++ = -0x59F8;
    *output++ = -0x65F8;
    *output++ = -0x65F8;
    *output++ = 0x6508;
    *output++ = 0x6508;
    *output++ = 0x5908;
    *output++ = 0x5908;
    *output++ = -0x14F8;
    *output++ = -0x14F8;
    *output++ = -0x28F8;
    *output++ = -0x28F8;
    *output++ = -0xCF8;
    *output++ = -0xCF8;
    *output++ = -0x30F8;
    *output++ = -0x30F8;
    *output++ = -0x55F8;
    *output++ = -0x55F8;
    *output++ = -0x69F8;
    *output++ = -0x69F8;
    *output++ = -0x4DF8;
    *output++ = -0x4DF8;
    *output++ = -0x71F8;
    *output++ = -0x71F8;
    *output++ = 0x6908;
    *output++ = 0x6908;
    *output++ = 0x5508;
    *output++ = 0x5508;
    *output++ = 0x7108;
    *output++ = 0x7108;
    *output++ = 0x4D08;
    *output++ = 0x4D08;
    *output++ = -0x1CF8;
    *output++ = -0x1CF8;
    *output++ = -0x2CF8;
    *output++ = -0x2CF8;
    *output++ = -0x34F8;
    *output++ = -0x34F8;
    *output++ = -0x38F8;
    *output++ = -0x38F8;
    return output;
}

/* --- rel/movie_module/fn_12_FC04.c --- */
void fn_12_FC04(void);

extern s16 lbl_12_bss_6230[0x80];

extern s16 lbl_12_bss_61F0[0x20];

void fn_12_FC04(void) {
    s16 *p;
    s32 i;
    p = lbl_12_bss_6230;
    for (i = 0; i < 24; i++)
        *p++ = 0x7F;
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (16); k >= (11); k--) {
            v = (((11) << 8) | (u8)(k));
            for (i = 0; i < (1); i++)
                *p++ = v;
            v = (((11) << 8) | (u8)(-k));
            for (i = 0; i < (1); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (10); k >= (8); k--) {
            v = (((10) << 8) | (u8)(k));
            for (i = 0; i < (2); i++)
                *p++ = v;
            v = (((10) << 8) | (u8)(-k));
            for (i = 0; i < (2); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (7); k >= (5); k--) {
            v = (((8) << 8) | (u8)(k));
            for (i = 0; i < (8); i++)
                *p++ = v;
            v = (((8) << 8) | (u8)(-k));
            for (i = 0; i < (8); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (4); k >= (4); k--) {
            v = (((7) << 8) | (u8)(k));
            for (i = 0; i < (16); i++)
                *p++ = v;
            v = (((7) << 8) | (u8)(-k));
            for (i = 0; i < (16); i++)
                *p++ = v;
        }
    };
    p = lbl_12_bss_61F0;
    for (i = 0; i < 2; i++)
        *p++ = 0x7F;
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (3); k >= (3); k--) {
            v = (((5) << 8) | (u8)(k));
            for (i = 0; i < (1); i++)
                *p++ = v;
            v = (((5) << 8) | (u8)(-k));
            for (i = 0; i < (1); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (2); k >= (2); k--) {
            v = (((4) << 8) | (u8)(k));
            for (i = 0; i < (2); i++)
                *p++ = v;
            v = (((4) << 8) | (u8)(-k));
            for (i = 0; i < (2); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (1); k >= (1); k--) {
            v = (((3) << 8) | (u8)(k));
            for (i = 0; i < (4); i++)
                *p++ = v;
            v = (((3) << 8) | (u8)(-k));
            for (i = 0; i < (4); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (0); k >= (0); k--) {
            v = (((1) << 8) | (u8)(k));
            for (i = 0; i < (16); i++)
                *p++ = v;
        }
    };
}

/* --- rel/movie_module/mpvvlc_InitMbTypeBpic.c --- */
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

/* --- rel/movie_module/fn_12_10200.c --- */
void fn_12_10200(void);

extern s16 lbl_12_bss_6430[0x80];

extern s16 lbl_12_bss_63F0[0x20];

void fn_12_10200(void) {
    s16 *p;
    s32 i;
    p = lbl_12_bss_6430;
    for (i = 0; i < 8; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    *p++ = (((0) << 10) | ((35) << 4) | (11));
    for (i = 0; i < 6; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    *p++ = (((0) << 10) | ((34) << 4) | (11));
    for (i = 0; i < 8; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        for (k = (33); k >= (22); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((11)));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (21); k >= (16); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((10)));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (15); k >= (10); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((8)));
            *p++ = ((((0x20 | 0x04)) << 10) | ((k) << 4) | ((8) + 3));
            *p++ = ((((0x20 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((8) + 3));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x08 | 0x04)) << 10) | ((k) << 4) | ((8) + 2));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x08 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((8) + 2));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (9); k >= (8); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((7)));
            *p++ = ((((0x20 | 0x08)) << 10) | ((k) << 4) | ((7) + 4));
            *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((7) + 4));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x04)) << 10) | ((k) << 4) | ((7) + 3));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((7) + 3));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x08 | 0x04)) << 10) | ((k) << 4) | ((7) + 2));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x08 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((7) + 2));
        }
    };
    p = lbl_12_bss_63F0;
    for (i = 0; i < 2; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        for (k = (7); k >= (6); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((5)));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (5); k >= (4); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((4)));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (3); k >= (2); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((3)));
            *p++ = ((((0x20 | 0x08 | 0x04)) << 10) | ((k) << 4) | ((3) + 2));
            *p++ = ((((0x20 | 0x08 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((3) + 2));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (1); k >= (1); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((1)));
            *p++ = ((((0x20 | 0x08)) << 10) | ((k) << 4) | ((1) + 4));
            *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((1) + 4));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x04)) << 10) | ((k) << 4) | ((1) + 3));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((1) + 3));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x08 | 0x04)) << 10) | ((k) << 4) | ((1) + 2));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x08 | 0x04 | 0x02)) << 10) | ((k) << 4) | ((1) + 2));
        }
    };
}

/* --- rel/movie_module/fn_12_105BC.c --- */
/* --- rel/movie_module/fn_12_105BC.c --- */
void fn_12_105BC(void);

extern s16 lbl_12_bss_6570[0x80];

extern s16 lbl_12_bss_6530[0x20];

void fn_12_105BC(void) {
    s16 *p;
    s32 i;
    p = lbl_12_bss_6570;
    for (i = 0; i < 8; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    *p++ = (((0) << 10) | ((35) << 4) | (11));
    for (i = 0; i < 6; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    *p++ = (((0) << 10) | ((34) << 4) | (11));
    for (i = 0; i < 8; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        for (k = (33); k >= (22); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((11)));
        }
    };
    {
        s32 k;
        for (k = (21); k >= (16); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((10)));
            *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((10) + 1));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (15); k >= (10); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((8)));
            *p++ = ((((0x20 | 0x08)) << 10) | ((k) << 4) | ((8) + 3));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x02)) << 10) | ((k) << 4) | ((8) + 2));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((8) + 1));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (9); k >= (8); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((7)));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x08)) << 10) | ((k) << 4) | ((7) + 3));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x02)) << 10) | ((k) << 4) | ((7) + 2));
            for (i = 0; i < 8; i++)
                *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((7) + 1));
        }
    };
    p = lbl_12_bss_6530;
    for (i = 0; i < 2; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        for (k = (7); k >= (6); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((5)));
        }
    };
    {
        s32 k;
        for (k = (5); k >= (4); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((4)));
            *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((4) + 1));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (3); k >= (2); k--) {
            *p++ = (((0) << 10) | ((k) << 4) | ((3)));
            *p++ = ((((0x20 | 0x02)) << 10) | ((k) << 4) | ((3) + 2));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((3) + 1));
        }
    };
    {
        s32 k;
        s32 i;
        for (k = (1); k >= (1); k--) {
            for (i = 0; i < 2; i++)
                *p++ = (((0) << 10) | ((k) << 4) | ((1)));
            for (i = 0; i < 2; i++)
                *p++ = ((((0x20 | 0x08)) << 10) | ((k) << 4) | ((1) + 3));
            for (i = 0; i < 4; i++)
                *p++ = ((((0x20 | 0x02)) << 10) | ((k) << 4) | ((1) + 2));
            for (i = 0; i < 8; i++)
                *p++ = ((((0x20 | 0x08 | 0x02)) << 10) | ((k) << 4) | ((1) + 1));
        }
    };
}

/* --- rel/movie_module/fn_12_10980.c --- */
void fn_12_10980(void);

extern s16 lbl_12_bss_66F0[0x100];

extern s16 lbl_12_bss_6670[0x40];

void fn_12_10980(void) {
    s16 *p;
    s32 i;
    p = lbl_12_bss_66F0;
    for (i = 0; i < 16; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    for (i = 0; i < 2; i++)
        *p++ = (((0) << 10) | ((35) << 4) | (11));
    for (i = 0; i < 12; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    for (i = 0; i < 2; i++)
        *p++ = (((0) << 10) | ((34) << 4) | (11));
    for (i = 0; i < 16; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (33); k >= (22); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((11) + 2));
            for (i = 0; i < (1); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((11) + 1));
            for (i = 0; i < (1); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (21); k >= (16); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((10) + 2));
            for (i = 0; i < (2); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((10) + 1));
            for (i = 0; i < (2); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (15); k >= (10); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((8) + 2));
            for (i = 0; i < (8); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((8) + 1));
            for (i = 0; i < (8); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (9); k >= (8); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((7) + 2));
            for (i = 0; i < (16); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((7) + 1));
            for (i = 0; i < (16); i++)
                *p++ = v;
        }
    };
    p = lbl_12_bss_6670;
    for (i = 0; i < 4; i++)
        *p++ = (((0) << 10) | ((36) << 4) | (0));
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (7); k >= (6); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((5) + 2));
            for (i = 0; i < (1); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((5) + 1));
            for (i = 0; i < (1); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (5); k >= (4); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((4) + 2));
            for (i = 0; i < (2); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((4) + 1));
            for (i = 0; i < (2); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (3); k >= (2); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((3) + 2));
            for (i = 0; i < (4); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((3) + 1));
            for (i = 0; i < (4); i++)
                *p++ = v;
        }
    };
    {
        s32 k;
        s32 i;
        s16 v;
        for (k = (1); k >= (1); k--) {
            v = (((0x01 | 0x10) << 10) | ((k) << 4) | ((1) + 2));
            for (i = 0; i < (16); i++)
                *p++ = v;
            v = (((0x01) << 10) | ((k) << 4) | ((1) + 1));
            for (i = 0; i < (16); i++)
                *p++ = v;
        }
    };
}
