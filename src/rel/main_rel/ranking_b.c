#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/ranking.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0();
extern void fn_8006B7B4();
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern s16 fn_1_159804(s16 value, RankingArchive *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);

/* fzgx:begin fn_1_1577D0 */
extern f32 lbl_1_rodata_D920;
extern u8 lbl_1_data_4A430[];
extern u8 lbl_1_data_4B368[];
extern u8 lbl_1_data_4BDCC[];

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    s16 unk_1C;
    u8 pad_1E[0x2];
    s16 unk_20;
    s16 unk_22;
} Obj_1_bss_8F574_At0;

u8 lbl_1_bss_8F568;
f32 lbl_1_bss_8F56C;
f32 lbl_1_bss_8F570;
Obj_1_bss_8F574_At0 *lbl_1_bss_8F574;
u32 lbl_1_bss_8F578;
s32 lbl_1_bss_8F57C;
s32 lbl_1_bss_8F580;

u32 lbl_1_data_4C788[3] = {(u32)lbl_1_data_4A430, (u32)lbl_1_data_4B368, (u32)lbl_1_data_4BDCC};

f32 fn_1_1577D0(u32 arg0, u32 arg1, f32 arg2) {
    lbl_1_bss_8F568 = arg0;
    lbl_1_bss_8F56C = lbl_1_rodata_D920;
    lbl_1_bss_8F570 = arg2;
    lbl_1_bss_8F574 = (Obj_1_bss_8F574_At0 *)lbl_1_data_4C788[(s8)arg1];
    lbl_1_bss_8F578 = 1;
    lbl_1_bss_8F57C = 0;
    lbl_1_bss_8F580 = 600;
    return arg2;
}
/* fzgx:end fn_1_1577D0 */

/* fzgx:begin fn_1_157820 */
void fn_1_157820(void) {
    u8 index;

    if (lbl_1_bss_8F57C == 0) {
        lbl_1_bss_8F56C += lbl_1_bss_8F570;
    } else {
        if (lbl_1_bss_8F580 > 0) {
            lbl_1_bss_8F580 -= 1;
        }

        index = lbl_1_bss_8B3A0.unk_9E;
        if (((*(&lbl_1_bss_9F8.unk_8 + index * 10) >> 8) & 1) ||
            lbl_1_bss_8F580 == 0) {
            lbl_1_bss_8F578 = 0;
        }
    }

    if ((s32)fn_1_157920() == 0) {
        fn_1_4060();
    }
}
/* fzgx:end fn_1_157820 */

/* fzgx:begin fn_1_1578C4 */
void fn_1_1578C4(void) {
    s8 v0;
    u32 t2;
    v0 = lbl_1_bss_8F568;
    switch (v0) {
    case 0:
    fn_1_157950();
    break;
    case 1:
    fn_1_157FC8();
    }
    t2 = fn_1_157920();
    if ((s32)t2 == 0) {
    fn_1_4060();
    }
}
/* fzgx:end fn_1_1578C4 */

/* fzgx:begin fn_1_157920 */
// Return the current ranking value.
u32 fn_1_157920(void) {
    return lbl_1_bss_8F578;
}
/* fzgx:end fn_1_157920 */

/* fzgx:begin fn_1_157930 */
u32 fn_1_157930(void) {
    return lbl_1_bss_8F57C;
}
/* fzgx:end fn_1_157930 */

/* fzgx:begin fn_1_157940 */
void fn_1_157940(void) {
    lbl_1_bss_8F578 = 0;
}
/* fzgx:end fn_1_157940 */

/* fzgx:begin fn_1_157950 */
#include "font.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0();
extern void fn_8006B7B4();
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern s16 fn_1_159804(s16 value, RankingArchive *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);


struct fn_1_157950_Copy88 { u32 a[22]; };
struct fn_1_157950_lbl_1_rodata_D920 {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x28];
    f64 unk_30;
};
extern struct fn_1_157950_Copy88 lbl_1_rodata_26F8;
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
enum { FONT_DRAW_FLAGS = 3u << 30 };
extern void fn_1_5233C(void);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_495C8(int);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32,f32);
extern void fn_1_49514(u32*);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket*,u32,s16,s16,s16,s16);
extern int fn_1_4F734(FontDrawPacket*);
extern void fn_1_496FC(f32,f32);
extern void fn_1_495A0(f32);
extern void fn_1_4CF3C(const char*,f32,...);
extern void fn_1_4AE0C(const char*,...);

void fn_1_157950(void) {
    f32 v0;
    Obj_1_bss_8F574_At0 *v1;
    f32 v3;
    f32 v2;
    Obj_1_bss_8F574_At0 *v4;
    f32 pos;
    f32 alpha;
    v0 = lbl_1_bss_8F56C;
    v1 = lbl_1_bss_8F574;
    v4 = v1;
    v3 = 0.0f;
    v2 = (v0 - (448.0f / lbl_1_bss_8F570));
    while (*(s16 *)v4 != -2) {
        v3 += (f32)*(s16*)v4 / lbl_1_bss_8F570;
        if (v3 >= v2 && v3 <= lbl_1_bss_8F56C) {
            pos = lbl_1_bss_8F570 * (v3-v2);
            alpha = 1.0f;
            fn_1_49410();
            if (pos < v4->unk_E) alpha = pos / v4->unk_E;
            else if (pos > 448.0f-v4->unk_E) alpha = (448.0f-pos) / v4->unk_E;
            if (lbl_1_bss_8F580 < 30)
                alpha = lbl_1_bss_8F580 / 30.0f;
            switch (v4->unk_10) {
            case 0: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(5.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C(v4->unk_C/24.0f,v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 1: {
                u32 color;
                fn_1_494DC(5);
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C(v4->unk_C/18.0f,v4->unk_E/18.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 2: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(3.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C(v4->unk_C/24.0f,v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 6: {
                u32 color;
                fn_1_495B0(FONT_DRAW_FLAGS);
                fn_1_4965C(2);
                fn_1_49738(fn_1_5233C);
                fn_1_49748(1.0f);
                fn_1_495C8((s8)v4->unk_8);
                fn_1_49590(0.5f);
                fn_1_4955C(v4->unk_C/24.0f,v4->unk_E/24.0f);
                color = v4->unk_14; fn_1_49514(&color);
                break;
            }
            case 3: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,0,120,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 4: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x100;
                *(f32*)&packet.a[11] = alpha;
                fn_1_51678((FontDrawPacket*)&packet,0x100,0,18,248,16);
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            case 5: {
                struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                *(f32*)&packet.a[1] = v4->unk_4;
                *(f32*)&packet.a[2] = pos;
                *(f32*)&packet.a[3] = 0.1f;
                packet.a[12] = 5;
                packet.a[0] = 0x8700;
                *(f32*)&packet.a[11] = alpha;
                fn_1_4F734((FontDrawPacket*)&packet);
                break;
            }
            }
            fn_1_496FC(v4->unk_4,pos);
            fn_1_495A0(alpha);
            if ((s32)v4->unk_10 != 6) fn_1_4CF3C((const char*)v4->unk_18,284.0f-v4->unk_4);
            else fn_1_4AE0C((const char*)v4->unk_18);
        }
        v4 = (Obj_1_bss_8F574_At0*)((u8*)v4+0x1c);
    }
    if (v4->unk_2 < lbl_1_bss_8F56C)
        lbl_1_bss_8F57C = 1;
}
/* fzgx:end fn_1_157950 */

/* fzgx:begin fn_1_157FC8 */
#include "font.h"

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_451C(void);
extern void fn_1_A1340(void);
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern void fn_1_A1360(void);
extern void fn_1_A1364(void);
extern u8 lbl_1_bss_8F420[8];
extern f32 lbl_1_rodata_D8C8[18];
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_1568C4(void *);
extern void fn_80008BA8(void *, void *, int);
extern void fn_1_1574E0();
extern void fn_8006B7B4();
extern void fn_8006B870(void);
extern void fn_1_157950(void);
extern void fn_1_157FC8(void);
extern u32 fn_1_157920(void);
extern void fn_1_4060(void);
extern void fn_1_9AD88(void);
extern void fn_1_1594AC(int index, int flag);
extern void OSReport(const char *format, ...);
extern void fn_1_465D0(void *object, int value);
extern void fn_1_9AD54(void);

extern void fn_1_1568C4(void *entry);

extern u32 lbl_801A6410[];
extern void fn_1_46B4(u32, Obj_1_bss_8EF20_At0 *, u8 *, u32);
extern Obj_1_bss_8EF20_At0 *fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_1569E8(void *entry);
extern void fn_1_12EF80(s16 value, s16 *out_0, s16 *out_1);
extern s32 fn_1_156218(u32 arg, void *out0, void *out1, void *out2);
extern u32 lbl_1_bss_8F3FC[9];
extern s16 fn_1_159804(s16 value, RankingArchive *entry);
extern void fn_1_4811C(s16 value);
extern void fn_1_48004(s16 value, u32 arg);
extern u32 lbl_1_rodata_DAF8[16];
extern void fn_1_9A508(void);


extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495B0(u32);
#define FONT_DRAW_TEXT_FLAGS ((1U << 31) | (1U << 30))
extern void fn_1_49748(f32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_494DC(s16);
extern void fn_1_4965C(u8);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_495A0(f32);
extern void fn_1_4A0D8(const char *);


void fn_1_157FC8(void) {
    Obj_1_bss_8F574_At0 *v2;
    s32 v3;
    f32 v4;
    s16 x;
    s16 y;
    f32 alpha;
    s32 end;
    f32 elapsed;
    f32 remaining;
    v2 = lbl_1_bss_8F574;
    while ((v3 = *(s16 *)v2->pad_0) != -2) {
        v4 = lbl_1_bss_8F56C;
        if (v3 <= v4 && (end = v3 + v2->unk_2) > v4) {
            x = v2->unk_4;
            y = v2->unk_6;
            alpha = 1.0f;
            elapsed = v4 - v3;
            if (elapsed <= 30.0f) {
                alpha = elapsed / 30.0f;
            }
            remaining = end - v4;
            if (remaining <= 30.0f && remaining >= 0.0f) {
                alpha = remaining / 30.0f;
            }
            do {
                fn_1_49410();
                switch (v2->unk_10) {
                case 0: {
                    u32 color;
                    fn_1_496FC(x, y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(5.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C(v2->unk_C / 24.0f, v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 1: {
                    u32 color;
                    fn_1_494DC(5);
                    fn_1_496FC(x, y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C(v2->unk_C / 18.0f, v2->unk_E / 18.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 2: {
                    u32 color;
                    fn_1_496FC(x, y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(3.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C(v2->unk_C / 24.0f, v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 6: {
                    u32 color;
                    fn_1_496FC(x, y);
                    fn_1_495B0(FONT_DRAW_TEXT_FLAGS);
                    fn_1_4965C(2);
                    fn_1_49738(fn_1_5233C);
                    fn_1_49748(1.0f);
                    fn_1_495C8((s8)v2->unk_8);
                    fn_1_49590(0.5f);
                    fn_1_4955C(v2->unk_C / 24.0f, v2->unk_E / 24.0f);
                    color = v2->unk_14;
                    fn_1_49514(&color);
                    break;
                }
                case 3: {
                    struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x100;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_51678((FontDrawPacket *)&packet, 0x100, 0, 0, 0x78, 0x10);
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                case 4: {
                    struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x100;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_51678((FontDrawPacket *)&packet, 0x100, 0, 0x12, 0xF8, 0x10);
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                case 5: {
                    struct fn_1_157950_Copy88 packet = lbl_1_rodata_26F8;
                    *(f32 *)&packet.a[1] = (f32)x;
                    *(f32 *)&packet.a[2] = (f32)y;
                    *(f32 *)&packet.a[3] = 0.1f;
                    packet.a[12] = 10;
                    packet.a[0] = 0x8700;
                    *(f32 *)&packet.a[11] = alpha;
                    fn_1_4F734((FontDrawPacket *)&packet);
                    break;
                }
                }
                fn_1_495A0(alpha);
                fn_1_4A0D8((const char *)v2->unk_18);
                x += v2->unk_20;
                y += v2->unk_22;
                v2 = (Obj_1_bss_8F574_At0 *)((u8 *)v2 + 0x1C);
            } while (*(s16 *)v2->pad_0 == -1);
        } else {
            v2 = (Obj_1_bss_8F574_At0 *)((u8 *)v2 + 0x1C);
        }
    }
    if (v2->unk_2 < lbl_1_bss_8F56C) {
        lbl_1_bss_8F578 = 0;
    }
}
/* fzgx:end fn_1_157FC8 */
