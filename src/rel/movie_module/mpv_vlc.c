#include "types.h"

typedef struct DivResult {
    s32 quot;
    s32 rem;
} DivResult;
extern unsigned int lbl_12_bss_52F0[128];
extern unsigned char lbl_12_bss_54F0[1024];
extern unsigned char lbl_12_bss_58F0[1024];
extern unsigned char lbl_12_bss_5CF0[128];
extern unsigned char lbl_12_bss_5D70[128];
extern s16 lbl_12_bss_6230[0x80];
extern s16 lbl_12_bss_61F0[0x20];
extern signed short lbl_12_bss_6330[64];
extern u16 lbl_12_bss_63B0[32];
extern s16 lbl_12_bss_6430[0x80];
extern s16 lbl_12_bss_63F0[0x20];
extern s16 lbl_12_bss_6570[0x80];
extern s16 lbl_12_bss_6530[0x20];
extern s16 lbl_12_bss_66F0[0x100];
extern s16 lbl_12_bss_6670[0x40];
extern void mpvvlc_InitMbTypeBpic(void);
extern signed short *mpvvlc_InitCbpSub2(signed short *output);
extern void mpvvlc2_InitDcSizY(void);
extern void mpvvlc2_InitDcSizC(void);
extern void fn_12_33364(unsigned int *destination, unsigned int *source, unsigned int count);
extern DivResult fn_8007E914(s32 numer, s32 denom);

/* fzgx:begin fn_12_E0F4 */

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
/* fzgx:end fn_12_E0F4 */

/* fzgx:begin mpvvlc2_InitDcSizC */
#pragma opt_propagation reset

/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */
/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */
/* --- rel/movie_module/mpvvlc2_InitDcSizC.c --- */

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
/* fzgx:end mpvvlc2_InitDcSizC */

/* fzgx:begin mpvvlc2_InitDcSizY */
/* --- rel/movie_module/mpvvlc2_InitDcSizY.c --- */

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
/* fzgx:end mpvvlc2_InitDcSizY */

/* fzgx:begin fn_12_ED30 */

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
/* fzgx:end fn_12_ED30 */

/* fzgx:begin fn_12_EFA4 */

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
/* fzgx:end fn_12_EFA4 */

/* fzgx:begin mpvvlc_InitCbpSub2 */
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
/* fzgx:end mpvvlc_InitCbpSub2 */

/* fzgx:begin fn_12_FA5C */
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
/* fzgx:end fn_12_FA5C */

/* fzgx:begin fn_12_FC04 */


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
/* fzgx:end fn_12_FC04 */

/* fzgx:begin mpvvlc_InitMbTypeBpic */
/* --- rel/movie_module/mpvvlc_InitMbTypeBpic.c --- */
/* --- rel/movie_module/mpvvlc_InitMbTypeBpic.c --- */

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
/* fzgx:end mpvvlc_InitMbTypeBpic */

/* fzgx:begin fn_12_1014C */
/* --- rel/movie_module/fn_12_1014C.c --- */

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
/* fzgx:end fn_12_1014C */

/* fzgx:begin fn_12_10200 */


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
/* fzgx:end fn_12_10200 */

/* fzgx:begin fn_12_105BC */


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
/* fzgx:end fn_12_105BC */

/* fzgx:begin fn_12_10980 */


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
/* fzgx:end fn_12_10980 */

/* fzgx:begin fn_12_10F3C noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_10F3C.c --- */
/* MPVVLC_Init (mpv_vlc.c, CRI Sofdec MPEG video VLC tables). Every object of the
 * TU is defined here under its retail name so the code reaches it off the section
 * bases like retail; names follow mpv_vlc.c in the comments. */

#define MPVVLC_VLC_AREA_SIZE 0x5B0

static const u32 lbl_12_rodata_938[8] = { /* mpvvlt_run_level_0c */
    0x12011101, 0x10010F01, 0x03060210, 0x020F020E, 0x020D020C, 0x020B011F, 0x011E011D, 0x011C011B,
};
static const u32 lbl_12_rodata_938__fzgx_offset_20[8] = { /* mpvvlt_run_level_0b */
    0x28002700, 0x26002500, 0x24002300, 0x22002100, 0x20000E01, 0x0D010C01, 0x0B010A01, 0x09010801,
};
static const u32 lbl_12_rodata_938__fzgx_offset_40[8] = { /* mpvvlt_run_level_0a */
    0x1F001E00, 0x1D001C00, 0x1B001A00, 0x19001800, 0x17001600, 0x15001400, 0x13001200, 0x11001000,
};
static const u32 lbl_12_rodata_938__fzgx_offset_60[8] = { /* mpvvlt_run_level_1 */
    0x020A0209, 0x03050403, 0x05020701, 0x06010F00, 0x0E000D00, 0x0C00011A, 0x01190118, 0x01170116,
};
static const u32 lbl_12_rodata_938__fzgx_offset_80[8] = { /* mpvvlt_run_level_2 */
    0x0B000208, 0x03040A00, 0x04020207, 0x01150114, 0x09000113, 0x01120501, 0x03030800, 0x02060111,
};
static const u32 lbl_12_rodata_938__fzgx_offset_A0[4] = { /* mpvvlt_run_level_4 */
    0x01100205, 0x07000302, 0x0401010F, 0x010E0204,
};

static s16 *lbl_12_bss_6944; /* mpvvlc_mbai_i_0 */
static s16 *lbl_12_bss_6940; /* mpvvlc_mbai_i_1 */
static s16 *lbl_12_bss_693C; /* mpvvlc_mbai_p_0 */
static s16 *lbl_12_bss_6938; /* mpvvlc_mbai_p_1 */
static s16 *lbl_12_bss_6934; /* mpvvlc_mbai_b_0 */
static s16 *lbl_12_bss_6930; /* mpvvlc_mbai_b_1 */
static s16 *lbl_12_bss_692C; /* mpvvlc_p_mbtype */
static s16 *lbl_12_bss_6928; /* mpvvlc_b_mbtype */
static s16 *lbl_12_bss_6924; /* mpvvlc_motion_0 */
static s16 *lbl_12_bss_6920; /* mpvvlc_motion_1 */
static s16 *lbl_12_bss_691C; /* mpvvlc_cbp */
static s8 *lbl_12_bss_6918;  /* mpvvlc_y_dcsiz */
static s8 *lbl_12_bss_6914;  /* mpvvlc_c_dcsiz */
static s8 *lbl_12_bss_6910;  /* mpvvlc2_y_dcsiz */
static s8 *lbl_12_bss_690C;  /* mpvvlc2_c_dcsiz */
static u32 *lbl_12_bss_6908; /* mpvvlc_run_level_0c */
static u32 *lbl_12_bss_6904; /* mpvvlc_run_level_0b */
static u32 *lbl_12_bss_6900; /* mpvvlc_run_level_0a */
static u32 *lbl_12_bss_68FC; /* mpvvlc_run_level_1 */
static u32 *lbl_12_bss_68F8; /* mpvvlc_run_level_2 */
static u32 *lbl_12_bss_68F4; /* mpvvlc_run_level_4 */
static u32 *lbl_12_bss_68F0; /* mpvvlc_run_level_8 */

static s16 lbl_12_bss_66F0[0x100];               /* mpvvlt_mbai_i_0 */
static s16 lbl_12_bss_6670[0x40];                /* mpvvlt_mbai_i_1 */
static s16 lbl_12_bss_6570[0x80];                /* mpvvlt_mbai_p_0 */
static s16 lbl_12_bss_6530[0x20];                /* mpvvlt_mbai_p_1 */
static s16 lbl_12_bss_6430[0x80];                /* mpvvlt_mbai_b_0 */
static s16 lbl_12_bss_63F0[0x20];                /* mpvvlt_mbai_b_1 */
static s16 lbl_12_bss_63B0[0x20];                /* mpvvlt_p_mbtype */
static s16 lbl_12_bss_6330[0x40];                /* mpvvlt_b_mbtype */
static s16 lbl_12_bss_6230[0x80];                /* mpvvlt_motion_0 */
static s16 lbl_12_bss_61F0[0x20];                /* mpvvlt_motion_1 */
static s16 lbl_12_bss_5D70__fzgx_offset_80[0x200]; /* mpvvlt_cbp */
static s8 lbl_12_bss_5D70[0x80];                 /* mpvvlt_y_dcsiz */
static s8 lbl_12_bss_5CF0[0x80];                 /* mpvvlt_c_dcsiz */
static s8 lbl_12_bss_58F0[0x400];                /* mpvvlt2_y_dcsiz */
static s8 lbl_12_bss_54F0[0x400];                /* mpvvlt2_c_dcsiz */
static u32 lbl_12_bss_52F0[0x80];                /* mpvvlt_run_level_8 */

#pragma section code_type ".fzgxpool"
static void mpv_vlc_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 TU object first-access order */
    object = &lbl_12_bss_52F0;
    object = &lbl_12_bss_54F0;
    object = &lbl_12_bss_58F0;
    object = &lbl_12_bss_5CF0;
    object = &lbl_12_bss_5D70;
    object = &lbl_12_bss_5D70__fzgx_offset_80;
    object = &lbl_12_bss_61F0;
    object = &lbl_12_bss_6230;
    object = &lbl_12_bss_6330;
    object = &lbl_12_bss_63B0;
    object = &lbl_12_bss_63F0;
    object = &lbl_12_bss_6430;
    object = &lbl_12_bss_6530;
    object = &lbl_12_bss_6570;
    object = &lbl_12_bss_6670;
    object = &lbl_12_bss_66F0;
    object = &lbl_12_bss_68F0;
    object = &lbl_12_bss_68F4;
    object = &lbl_12_bss_68F8;
    object = &lbl_12_bss_68FC;
    object = &lbl_12_bss_6900;
    object = &lbl_12_bss_6904;
    object = &lbl_12_bss_6908;
    object = &lbl_12_bss_690C;
    object = &lbl_12_bss_6910;
    object = &lbl_12_bss_6914;
    object = &lbl_12_bss_6918;
    object = &lbl_12_bss_691C;
    object = &lbl_12_bss_6920;
    object = &lbl_12_bss_6924;
    object = &lbl_12_bss_6928;
    object = &lbl_12_bss_692C;
    object = &lbl_12_bss_6930;
    object = &lbl_12_bss_6934;
    object = &lbl_12_bss_6938;
    object = &lbl_12_bss_693C;
    object = &lbl_12_bss_6940;
    object = &lbl_12_bss_6944;
    object = &lbl_12_rodata_938;
    object = &lbl_12_rodata_938__fzgx_offset_20;
    object = &lbl_12_rodata_938__fzgx_offset_40;
    object = &lbl_12_rodata_938__fzgx_offset_60;
    object = &lbl_12_rodata_938__fzgx_offset_80;
    object = &lbl_12_rodata_938__fzgx_offset_A0;
}
#pragma section code_type ".text"

extern void fn_12_10980(void);          /* mpvvlc_InitMbaiIpic */
extern void fn_12_105BC(void);          /* mpvvlc_InitMbaiPpic */
extern void fn_12_10200(void);          /* mpvvlc_InitMbaiBpic */
extern void fn_12_1014C(void);          /* mpvvlc_InitMbTypePpic */
extern void mpvvlc_InitMbTypeBpic(void);
extern void fn_12_FC04(void);           /* mpvvlc_InitMotion */
extern s16 *fn_12_FA5C(s16 *p);         /* mpvvlc_InitCbpSub1 */
extern s16 *mpvvlc_InitCbpSub2(s16 *p);
extern void fn_12_EFA4(void);           /* mpvvlc_InitDcSizY */
extern void fn_12_ED30(void);           /* mpvvlc_InitDcSizC */
extern void mpvvlc2_InitDcSizY(void);
extern void mpvvlc2_InitDcSizC(void);
extern void fn_12_E0F4(void);           /* mpvvlc_InitIntRunLevel */
extern void fn_12_33364(unsigned int *destination, unsigned int *source, unsigned int count);

static inline void mpvvlc_InitCbp(void) {
    s16 *p = fn_12_FA5C(lbl_12_bss_5D70__fzgx_offset_80);
    mpvvlc_InitCbpSub2(p);
}

void fn_12_10F3C(u8 *vlc, void *ixa) {
    fn_12_10980();
    fn_12_105BC();
    fn_12_10200();
    fn_12_1014C();
    mpvvlc_InitMbTypeBpic();
    fn_12_FC04();
    mpvvlc_InitCbp();
    fn_12_EFA4();
    fn_12_ED30();
    mpvvlc2_InitDcSizY();
    mpvvlc2_InitDcSizC();
    fn_12_E0F4();

    lbl_12_bss_6944 = lbl_12_bss_66F0;
    lbl_12_bss_6940 = lbl_12_bss_6670;
    lbl_12_bss_693C = lbl_12_bss_6570;
    lbl_12_bss_6938 = lbl_12_bss_6530;
    lbl_12_bss_6934 = lbl_12_bss_6430;
    lbl_12_bss_6930 = lbl_12_bss_63F0;
    lbl_12_bss_692C = lbl_12_bss_63B0;
    lbl_12_bss_6928 = lbl_12_bss_6330;
    lbl_12_bss_6924 = lbl_12_bss_6230;
    lbl_12_bss_6920 = lbl_12_bss_61F0;
    lbl_12_bss_691C = lbl_12_bss_5D70__fzgx_offset_80;
    lbl_12_bss_6918 = lbl_12_bss_5D70;
    lbl_12_bss_6914 = lbl_12_bss_5CF0;
    lbl_12_bss_6910 = lbl_12_bss_58F0;
    lbl_12_bss_690C = lbl_12_bss_54F0;
    lbl_12_bss_6908 = (u32 *)lbl_12_rodata_938;
    lbl_12_bss_6904 = (u32 *)lbl_12_rodata_938__fzgx_offset_20;
    lbl_12_bss_6900 = (u32 *)lbl_12_rodata_938__fzgx_offset_40;
    lbl_12_bss_68FC = (u32 *)lbl_12_rodata_938__fzgx_offset_60;
    lbl_12_bss_68F8 = (u32 *)lbl_12_rodata_938__fzgx_offset_80;
    lbl_12_bss_68F4 = (u32 *)lbl_12_rodata_938__fzgx_offset_A0;
    lbl_12_bss_68F0 = lbl_12_bss_52F0;

    if (vlc != 0) {
        u8 *p;
        u8 *rl;

        p = vlc + MPVVLC_VLC_AREA_SIZE;
        p -= sizeof(lbl_12_bss_52F0);
        lbl_12_bss_68F0 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_52F0, sizeof(lbl_12_bss_52F0) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_A0);
        lbl_12_bss_68F4 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_A0, sizeof(lbl_12_rodata_938__fzgx_offset_A0) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_80);
        lbl_12_bss_68F8 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_80, sizeof(lbl_12_rodata_938__fzgx_offset_80) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_60);
        lbl_12_bss_68FC = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_60, sizeof(lbl_12_rodata_938__fzgx_offset_60) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_40);
        lbl_12_bss_6900 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_40, sizeof(lbl_12_rodata_938__fzgx_offset_40) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_20);
        lbl_12_bss_6904 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_20, sizeof(lbl_12_rodata_938__fzgx_offset_20) / 4);
        p -= sizeof(lbl_12_rodata_938);
        lbl_12_bss_6908 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938, sizeof(lbl_12_rodata_938) / 4);
        rl = p;
        p -= sizeof(lbl_12_bss_5D70);
        lbl_12_bss_6918 = (s8 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_5D70, sizeof(lbl_12_bss_5D70) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0));
        lbl_12_bss_6914 = (s8 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_5CF0, sizeof(lbl_12_bss_5CF0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230));
        lbl_12_bss_6924 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_6230, sizeof(lbl_12_bss_6230) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0));
        lbl_12_bss_6920 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_61F0, sizeof(lbl_12_bss_61F0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0) + sizeof(lbl_12_bss_63B0));
        lbl_12_bss_692C = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_63B0, sizeof(lbl_12_bss_63B0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0) + sizeof(lbl_12_bss_63B0) + sizeof(lbl_12_bss_6330));
        lbl_12_bss_6928 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_6330, sizeof(lbl_12_bss_6330) / 4);
    }
}
/* fzgx:end fn_12_10F3C */

/* fzgx:begin fn_12_11168 noprologue */
/* --- rel/movie_module/fn_12_11168.c --- */
#pragma opt_propagation off
s32 fn_12_11168(void) {
    s32 second = 0x5b0;
{
    s32 first = 0x5b0;
    return first < second;
}
}
/* fzgx:end fn_12_11168 */

/* fzgx:begin fn_12_11188 */
/* --- rel/movie_module/fn_12_11188.c --- */
typedef struct MovieContext {
    u8 unk_000[0x1d8];
    u32 unk_1d8;
} MovieContext;

typedef struct MovieDimensions {
    u8 unk_00[0x0c];
    s16 width;
    s16 height;
} MovieDimensions;



void fn_12_11188(MovieContext *movie, u32 value, u32 *out, const MovieDimensions *dimensions) {
    DivResult d = fn_8007E914(value, movie->unk_1d8);
    s32 width = dimensions->width;
    s32 height = dimensions->height;

    out[0] = (d.quot << 3) * width + (d.rem << 3);
    out[1] = (d.quot << 4) * height + (d.rem << 4);
}
/* fzgx:end fn_12_11188 */

/* fzgx:begin fn_12_11204 */
/* --- rel/movie_module/fn_12_11204.c --- */
struct fn_12_7870_Arg2 {
    u32 unk_0;
    s32 unk_4;
};
struct fn_12_7870_Arg3 {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
};

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_12_11204(u32 arg0, u32 arg1, struct fn_12_7870_Arg2 *arg2, struct fn_12_7870_Arg3 *arg3) {
    u8 *entry;
    s16 y;
    s8 a;
    s8 b;
    s32 a8;

    y = arg3->unk_E;
    arg1 <<= 1;
    entry = (u8 *)arg1 + 0x1344;
    entry = (u8 *)arg0 + (u32)entry;
    a = (s8)entry[0];
    b = (s8)entry[1];
    a8 = a << 3;
    arg2->unk_0 = (a8 * arg3->unk_C) + (b << 3);
    arg2->unk_4 = (a << 4) * y + (b << 4);
}
/* fzgx:end fn_12_11204 */

/* fzgx:begin fn_12_11254 */
#pragma opt_lifetimes reset
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_11254.c --- */
/* --- rel/movie_module/fn_12_11254.c --- */
typedef struct MovieModule {
    u8 unk_000[0x2a8];
    void (*callback)(struct MovieModule *);
    u8 unk_2ac[0x5c];
    s32 current_frame;
    u8 unk_30c[0x08];
    s32 field_314;
} MovieModule;

void fn_12_11254(MovieModule *movie, s32 frame) {
    s32 end_frame;
    s32 current_frame;
    void (*callback)(MovieModule *);

    end_frame = movie->current_frame;
    movie->field_314 = 0;
    current_frame = end_frame - frame + 1;
    callback = movie->callback;
    while (current_frame < end_frame) {
        movie->current_frame = current_frame;
        callback(movie);
        current_frame += 1;
    }
    movie->current_frame = end_frame;
}

/* One 8x8 block row pair: two 8-byte rows a stride apart, then advance two rows. */
#define ROW2_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    __dcbz(d, (_n) * 8); \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

#define ROW2(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

/* One 16-byte row, then advance one row. */
#define ROW16_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8

#define ROW16(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8
/* fzgx:end fn_12_11254 */
