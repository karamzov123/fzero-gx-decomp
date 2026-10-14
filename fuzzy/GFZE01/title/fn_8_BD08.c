/* Non-matching: best partial attempt (98.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    s32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u8 pad_3C[0x1C];
} BD08Packet;

struct fn_8_BD08_bss {
    s32 unk_0;
    u8 pad_4[0x18];
    s32 unk_1C;
    s32 unk_20;
    s16 unk_24;
    u8 pad_26[0x3A];
    s16 unk_60;
    u8 pad_62[0x3A];
    s16 unk_9C;
    u8 pad_9E[0x86];
    s32 unk_124;
    s32 unk_128;
    u8 pad_12C[8];
    s32 unk_134;
};

struct fn_8_BD08_data {
    u8 pad_0[0x1790];
    void (*funcs[11])(void);
    s32 lens[11];
    s32 durs[11];
    s32 count;
    u8 pad_1818[0x2204 - 0x1818];
    char str0[0x14];
    char str1[0x14];
    char str2[0x14];
};

extern f32 lbl_8_rodata_160[];
extern struct fn_8_BD08_data lbl_8_data_7E50;
extern struct fn_8_BD08_bss lbl_8_bss_2A8;
extern BD08Packet lbl_1_rodata_26F8;
extern s16 lbl_1_bss_96A;
extern void **lbl_1_bss_6EAD0[];
extern s32 lbl_801A66A0;

extern void fn_8_CC2C(void);
extern void fn_1_3EF14(void *);
extern int fn_1_4F734(BD08Packet *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4CF3C(const char *, f32, ...);
extern int fn_1_3F038(void);
extern u32 fn_1_A1588(void *, u32);
extern void fn_8006CE1C(f32);
extern void fn_1_3F894(void);

void fn_8_BD08(void) {
    u8 buf[0x14B8];
    BD08Packet pkt;
    f32 *ro = (f32 *)lbl_8_rodata_160;
    struct fn_8_BD08_data *data = (struct fn_8_BD08_data *)&lbl_8_data_7E50;
    struct fn_8_BD08_bss *bss = (struct fn_8_BD08_bss *)&lbl_8_bss_2A8;
    s32 *durs;
    s32 *lens;
    s32 frame;
    s32 count;
    s32 i;
    s32 sum;
    s32 idx;
    f32 lab_t1;
    void (**funcs)(void);

    fn_1_3EF14(buf);
    pkt = lbl_1_rodata_26F8;
    pkt.unk_0 = 0x12;
    pkt.unk_38 = *(u32 *)((u8 *)ro + 0x180);
    pkt.unk_2C = *(f32 *)((u8 *)ro + 0x3C);
    pkt.unk_30 = 6;
    pkt.unk_4 = *(f32 *)((u8 *)ro + 0x8);
    pkt.unk_8 = *(f32 *)((u8 *)ro + 0x34);
    pkt.unk_14 = *(f32 *)((u8 *)ro + 0x184);
    pkt.unk_10 = *(f32 *)((u8 *)ro + 0x188);
    fn_1_4F734(&pkt);
    fn_1_49410();
    fn_1_494DC(5);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_8_CC2C);
    fn_1_49748(*(f32 *)((u8 *)ro + 0x44));
    fn_1_49590(*(f32 *)((u8 *)ro + 0x3C));
    fn_1_495C8(1);
    lab_t1 = *(f32 *)((u8 *)ro + 0x18C);
    fn_1_496FC(*(f32 *)((u8 *)ro + 0x8), lab_t1);
    fn_1_4954C(*(f32 *)((u8 *)ro + 0x40));
    fn_1_4955C(*(f32 *)((u8 *)ro + 0x144), *(f32 *)((u8 *)ro + 0x144));
    if (bss->unk_20 < 0x96F) {
        fn_1_4CF3C(data->str0, *(f32 *)((u8 *)ro + 0x190));
    } else if (bss->unk_20 < 0xBE5) {
        fn_1_4CF3C(data->str1, *(f32 *)((u8 *)ro + 0x190));
    } else if (bss->unk_20 < 0xFB4) {
        fn_1_4CF3C(data->str2, *(f32 *)((u8 *)ro + 0x190));
    }
    if (fn_1_3F038() != 0) {
        lbl_1_bss_96A = 0xA3;
        return;
    }
    if (bss->unk_20 > 3 && bss->unk_0 == 0) {
        fn_1_A1588(lbl_1_bss_6EAD0[0][0], 0x34);
        bss->unk_0 = 1;
    }
    count = data->count;
    durs = data->durs;
    (void) durs;  /* fzgx: keeps the web at its definition */
    lens = data->lens;
    frame = bss->unk_20;
    sum = 0;
    for (i = 0; i < count; i++) {
        if (sum == frame) {
            bss->unk_134 = i;
            bss->unk_124 = bss->unk_128 = *durs;
        }
        sum += *lens;
        durs++;
        lens++;
    }
    if (bss->unk_124 <= 0) {
        bss->unk_124 = 0;
        bss->unk_128 = 0;
        bss->unk_134 = -1;
    }
    bss->unk_9C = bss->unk_24 = bss->unk_60 = lbl_801A66A0 << 9;
    if (bss->unk_124 > 0) {
        bss->unk_124--;
        idx = bss->unk_134;
        if (idx >= 0 && idx < count) {
            funcs = data->funcs;
            funcs[idx]();
        }
    }
    if (bss->unk_20 == 0xFB4) {
        bss->unk_20 = 59940;
    }
    if (bss->unk_20 >= 59940) {
        if (bss->unk_1C != 0) {
            fn_8006CE1C(*(f32 *)((u8 *)ro + 0x38));
        } else {
            f32 conv;
            *(u32 *)&conv = 0x43300000;
            *((u32 *)&conv + 1) = (bss->unk_20 - 59940) ^ 0x80000000;
            fn_8006CE1C((f32)(conv - *(f32 *)((u8 *)ro + 0x28)) / *(f32 *)((u8 *)ro + 0xAC));
        }
    }
    if (bss->unk_20 > 60000) {
        fn_8006CE1C(*(f32 *)((u8 *)ro + 0x38));
        fn_1_3F894();
    }
    bss->unk_20++;
}
