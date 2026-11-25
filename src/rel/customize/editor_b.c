#include "types.h"
#include "rel/customize/globals.h"
#include "font.h"

typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 pad_3[0x1];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x1];
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    s16 unk_E;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    s16 unk_18;
    u8 pad_1A[0x2];
    f32 unk_1C;
    s16 unk_20;
    u8 pad_22[0x6];
} Obj_3_bss_A2410;

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Color;

typedef struct BorderColor { u8 r, g, b, a; } BorderColor;


typedef struct StickInput {
    u8 pad_0[0x8];
    f32 unk_8;
    u8 pad_C[0x14];
} StickInput;

/* one pad's button words */
typedef struct PadInput {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} PadInput;

extern f64 __fabs(f64);
extern StickInput lbl_1_bss_BF0[];
extern PadInput lbl_1_bss_D58;
extern PadInput lbl_1_bss_9F8[4];
extern void fn_1_A2D84(u32);
extern u8 lbl_1_rodata_26F8[];
extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s32);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
void fn_3_17100(void);
void fn_3_177AC(Color color);

/* editor palette (own data block of the retail TU) */
Color lbl_3_data_35C0[16] = {
    {0xED, 0x1C, 0x24, 0xFF}, {0xF7, 0x94, 0x1D, 0xFF}, {0xFF, 0xF2, 0x00, 0xFF}, {0x8D, 0xC6, 0x3F, 0xFF},
    {0x39, 0xB5, 0x4A, 0xFF}, {0x00, 0xAE, 0xEF, 0xFF}, {0x00, 0x54, 0xA6, 0xFF}, {0x66, 0x2D, 0x91, 0xFF},
    {0xEC, 0x00, 0x8C, 0xFF}, {0x9E, 0x0B, 0x0E, 0xFF}, {0x82, 0x7B, 0x00, 0xFF}, {0x00, 0x5E, 0x20, 0xFF},
    {0x00, 0x36, 0x63, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}, {0x81, 0x81, 0x81, 0xFF}, {0x00, 0x00, 0x00, 0xFF},
};

Obj_3_bss_A2410 lbl_3_bss_A2410;

/* fzgx:begin fn_3_17098 */
void fn_3_17098(void) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    lbl_3_bss_A2410.unk_C = 0;
    *(Color *)&lbl_3_bss_A2410.unk_4 = lbl_3_data_35C0[lbl_3_bss_A2410.unk_C];
    lbl_3_bss_A2410.unk_10 = 0;
    lbl_3_bss_A2410.unk_12 = 0;
    lbl_3_bss_A2410.unk_14 = 0;
    lbl_3_bss_A2410.unk_16 = 0xFF;
    lbl_3_bss_A2410.unk_20 = 0;
}
/* fzgx:end fn_3_17098 */

/* fzgx:begin fn_3_170E0 */
void fn_3_170E0(void) {
    fn_3_17100();
}
/* fzgx:end fn_3_170E0 */

/* fzgx:begin fn_3_17100 */
void fn_3_17100(void) {
    s32 v0;
    f32 v1;
    s32 v3;
    u32 v12;
    s32 v14;
    s32 v15;
    s32 v19;
    s16 v32;
    s16 v34;
    u16 v37;
    s16 v40;
    u32 v41;
    if ((lbl_3_bss_A2410.unk_8 & 0x40000000) != 0) {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v3 = lbl_3_bss_A2410.unk_C;
    if ((v3 - 4) < 0) {
    lbl_3_bss_A2410.unk_4 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_5 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_6 = lbl_3_bss_A2410.unk_14;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_E = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = 2;
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    } else {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v3];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C -= 4;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    if ((v0 + 4) < 16) {
    v12 = (v0 << 2);
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = *(u32 *)((u8 *)&lbl_3_data_35C0 + v12);
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_C += 4;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 4) & 0x1) != 0) {
    v14 = lbl_3_bss_A2410.unk_C;
    if (v14 % 4 != 0) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v14];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_C--;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 5) & 0x1) != 0) {
    v15 = lbl_3_bss_A2410.unk_C;
    if (v15 % 4 != 3) {
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    *(u32 *)&lbl_3_bss_A2410.unk_0 = ((u32 *)&lbl_3_data_35C0)[v15];
    fn_1_A2D84(0xA9150600);
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_C++;
    }
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    }
    } else {
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 7) & 0x1) != 0) {
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    if ((v0 - 1) >= 0) {
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    fn_1_A2D84(0xA9150600);
    v0 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_C = (v0 - 1);
    }
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
    }
    if (((lbl_1_bss_9F8[lbl_3_bss_A2410.unk_D].unk_12 >> 6) & 0x1) != 0) {
    v19 = lbl_3_bss_A2410.unk_C;
    lbl_3_bss_A2410.unk_20 = 0;
    lbl_3_bss_A2410.unk_C = (v19 + 1);
    fn_1_A2D84(0xA9150600);
    if (lbl_3_bss_A2410.unk_C >= 3) {
    lbl_3_bss_A2410.unk_C = lbl_3_bss_A2410.unk_E;
    lbl_3_bss_A2410.unk_8 = 0x40000000;
    lbl_3_bss_A2410.unk_0 = lbl_3_bss_A2410.unk_10;
    lbl_3_bss_A2410.unk_1 = lbl_3_bss_A2410.unk_12;
    lbl_3_bss_A2410.unk_2 = lbl_3_bss_A2410.unk_14;
    lbl_3_bss_A2410.unk_1C = 0.0f;
    fn_3_177AC(lbl_3_data_35C0[lbl_3_bss_A2410.unk_C]);
    } else {
    lbl_3_bss_A2410.unk_8 = 0x80000000;
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
    }
    }
    v0 = (u32)&lbl_1_bss_9F8;
    v0 = (u32)(v0 + 2);
    v0 = *(u16 *)(v0 + (lbl_3_bss_A2410.unk_D * 20));
    if (((v0 >> 4) & 0x1) != 0 || ((v0 >> 5) & 0x1) != 0) {
    v32 = (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C];
    fn_3_177AC((Color){lbl_3_bss_A2410.unk_10, lbl_3_bss_A2410.unk_12, lbl_3_bss_A2410.unk_14, 255});
    v0 = (u32)&lbl_3_bss_A2410;
    if ((*(s16 *)((u8 *)v0 + 32)) > 40) {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
    v34 = -8;
    } else {
    v34 = 8;
    }
    v34 = (s16)v34;
    } else {
    if ((*(s16 *)((u8 *)v0 + 32)) > 20) {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
    v34 = -4;
    } else {
    v34 = 4;
    }
    v34 = (s16)v34;
    } else {
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (v1 < 0.0f) {
    v34 = -1;
    } else {
    v34 = 1;
    }
    v34 = (s16)v34;
    }
    }
    if ((*(s16 *)((u8 *)v0 + 32)) >= 20) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    } else {
    v37 = lbl_1_bss_D58.unk_12;
    if (((v37 >> 5) & 0x1) != 0 || ((v37 >> 4) & 0x1) != 0) {
    (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] = ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) < 0 ? 0 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34) > 255 ? 255 : ((&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C] + (s16)v34);
    }
    }
    v1 = (lbl_1_bss_BF0[lbl_3_bss_A2410.unk_D].unk_8);
    if (__fabs(v1) >= 0.8f) {
    v40 = *(s16 *)((u8 *)v0 + 32);
    *(u16 *)((u8 *)v0 + 32) = (v40 + 1);
    } else {
    *(u16 *)((u8 *)v0 + 32) = 0;
    }
    v41 = (&lbl_3_bss_A2410.unk_10)[lbl_3_bss_A2410.unk_C];
    if (v41 != 0 && v41 != 255 && v32 != (s32)v41) {
    fn_1_A2D84(0xA9150700);
    }
    }
    }
}
/* fzgx:end fn_3_17100 */

/* fzgx:begin fn_3_177AC */
void fn_3_177AC(Color color) {
    *(Color *)&lbl_3_bss_A2410.unk_4 = color;
    if (__rlwnm(lbl_3_bss_A2410.unk_8, 3, 31, 31)) {
        Color prev = {0, 0, 0, 255};
        prev.r = lbl_3_bss_A2410.unk_10;
        prev.g = lbl_3_bss_A2410.unk_12;
        prev.b = lbl_3_bss_A2410.unk_14;
        *(Color *)&lbl_3_bss_A2410.unk_0 = prev;
        lbl_3_bss_A2410.unk_10 = color.r;
        lbl_3_bss_A2410.unk_12 = color.g;
        lbl_3_bss_A2410.unk_14 = color.b;
    }
}
/* fzgx:end fn_3_177AC */

/* fzgx:begin fn_3_17820 */
u32 fn_3_17820(void) {
    return *(u32 *)&lbl_3_bss_A2410.unk_4;
}
/* fzgx:end fn_3_17820 */

/* fzgx:begin fn_3_17830 */
void fn_3_17830(void) {
    lbl_3_bss_A2410.unk_1C = 0.0f;
    lbl_3_bss_A2410.unk_8 |= 0x20000000u;
}
/* fzgx:end fn_3_17830 */

/* fzgx:begin fn_3_17854 */
#define PALETTE lbl_3_data_35C0
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
#define EDITOR lbl_3_bss_A2410
#define RGB(i) ((&lbl_3_bss_A2410.unk_10)[i])

void fn_3_17854(void) {
    FontDrawPacket pkt;
    u8 step;
    u8 channel;
    u8 i;
    u8 j;

    if (EDITOR.unk_8 & 0x80000000) {
        EDITOR.unk_18 = CLAMP(EDITOR.unk_18 + 1, 0, 10);
    } else {
        EDITOR.unk_18 = CLAMP(EDITOR.unk_18 - 1, 0, 10);
    }
    EDITOR.unk_1C = CLAMP(EDITOR.unk_1C + 0.1f, 0.0f, 1.0f);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8609;
    pkt.x = 456.0f;
    pkt.y = 86.0f;
    pkt.z = 75.0f;
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860B;
    pkt.x = 474.0f;
    pkt.y = 141.0f;
    pkt.z = 60.0f;
    pkt.color[0] = 255;
    pkt.color[1] = 242;
    pkt.color[2] = 0;
    pkt.color[3] = 255;
    pkt.alpha = CLAMP(EDITOR.unk_18 / 10.0f, 0.0f, 1.0f);
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860A;
    pkt.x = 474.0f;
    pkt.y = 294.0f;
    pkt.z = 60.0f;
    pkt.color[0] = 255;
    pkt.color[1] = 242;
    pkt.color[2] = 0;
    pkt.color[3] = 255;
    pkt.alpha = CLAMP(1.0f - EDITOR.unk_18 / 10.0f, 0.0f, 1.0f);
    pkt.flags = 5;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8634;
    pkt.x = 564.0f;
    pkt.y = 91.0f;
    pkt.z = 40.0f;
    if (__rlwnm(EDITOR.unk_8, 2, 31, 31) && !__rlwnm(EDITOR.unk_8, 3, 31, 31)) {
        pkt.color[0] = EDITOR.unk_0 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].r;
        pkt.color[1] = EDITOR.unk_1 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].g;
        pkt.color[2] = EDITOR.unk_2 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_1C * PALETTE[EDITOR.unk_C].b;
    } else if (EDITOR.unk_8 & 0xA0000000) {
        pkt.color[0] = EDITOR.unk_0 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_10 * EDITOR.unk_1C;
        pkt.color[1] = EDITOR.unk_1 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_12 * EDITOR.unk_1C;
        pkt.color[2] = EDITOR.unk_2 * (1.0f - EDITOR.unk_1C) + EDITOR.unk_14 * EDITOR.unk_1C;
        pkt.color[3] = 255;
    }
    pkt.flags = 5;
    fn_1_4F734(&pkt);
    pkt.x = 587.0f;
    pkt.flags |= 0x80000;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x860D;
    pkt.x = 565.0f;
    pkt.y = 152.0f;
    pkt.z = 50.0f;
    pkt.color[0] = EDITOR.unk_10;
    pkt.color[1] = EDITOR.unk_12;
    pkt.color[2] = EDITOR.unk_14;
    pkt.color[3] = 255;
    pkt.flags = 5;
    fn_1_4F734(&pkt);
    pkt.x = 585.0f;
    pkt.flags |= 0x80000;
    fn_1_4F734(&pkt);

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8600;
    for (i = 0; i < 3; i++) {
        pkt.x = RGB(i) * 124 / 255 + 479;
        pkt.y = i * 40 + 203;
        pkt.z = 50.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
    }

    if (EDITOR.unk_8 & 0x40000000) {
        pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = 0x8635;
        pkt.x = 474 + (EDITOR.unk_C % 4) * 33 + (EDITOR.unk_C % 4) / 2;
        pkt.y = (EDITOR.unk_C / 4) * 24 + 297;
        pkt.z = 40.0f;
        pkt.alpha = 1.0f - lbl_8006D188(65535.0f * (lbl_801A66A0 % 60) / 120.0f) / 2.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
    }

    if ((EDITOR.unk_8 & 0x80000000) && EDITOR.unk_C < 3) {
        pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        pkt.image = 0x8636;
        pkt.x = 472.0f;
        pkt.y = EDITOR.unk_C * 40 + 186;
        pkt.z = 40.0f;
        pkt.alpha = 1.0f - lbl_8006D188(65535.0f * (lbl_801A66A0 % 60) / 120.0f) / 2.0f;
        pkt.flags = 5;
        fn_1_4F734(&pkt);
        pkt.x = 544.0f;
        pkt.y = EDITOR.unk_C * 40 + 186;
        pkt.flags |= 0x80000;
        fn_1_4F734(&pkt);
    }

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x863A;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            pkt.x = 482 + j * 33 + j / 2;
            pkt.y = i * 24 + 303;
            pkt.z = 40.0f;
            pkt.scale_x = 3.0f;
            pkt.scale_y = 1.5f;
            pkt.flags = 5;
            *(Color *)pkt.color = PALETTE[i * 4 + j];
            fn_1_4F734(&pkt);
        }
    }

    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 174.0f);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495B0(0x80000000);
    fn_1_4AE0C("R%3u", EDITOR.unk_10);
    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 215.0f);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_495C8(0);
    fn_1_495B0(0x80000000);
    fn_1_4AE0C("G%3u", EDITOR.unk_12);
    fn_1_49410();
    fn_1_4954C(30.0f);
    fn_1_496FC(484.0f, 255.0f);
    fn_1_495B0(0x80000000);
    fn_1_495C8(0);
    fn_1_4955C(0.5f, 0.5f);
    fn_1_4AE0C("B%3u", EDITOR.unk_14);

    pkt.image = 0x863A;
    pkt.z = 30.0f;
    pkt.scale_x = 0.5f;
    pkt.scale_y = 1.5f;
    pkt.flags = 5;
    for (channel = 0; channel < 3; channel++) {
        pkt.y = channel * 40 + 191;
        for (step = 0; step < 31; step++) {
            pkt.x = step * 4 + 482;
            switch (channel) {
            case 0:
                pkt.color[0] = step << 3;
                pkt.color[1] = EDITOR.unk_12;
                pkt.color[2] = EDITOR.unk_14;
                break;
            case 1:
                pkt.color[0] = EDITOR.unk_10;
                pkt.color[1] = step << 3;
                pkt.color[2] = EDITOR.unk_14;
                break;
            case 2:
                pkt.color[0] = EDITOR.unk_10;
                pkt.color[1] = EDITOR.unk_12;
                pkt.color[2] = step << 3;
                break;
            }
            fn_1_4F734(&pkt);
        }
    }

    pkt = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
    pkt.image = 0x8601;
    pkt.x = 594.0f;
    pkt.y = 92.0f;
    pkt.z = 30.0f;
    pkt.flags = 5;
    fn_1_4F734(&pkt);
}
/* fzgx:end fn_3_17854 */
