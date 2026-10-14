/* Non-matching: best partial attempt (65.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/game.h"

extern u32 fn_1_2EBB8(u32 flags, u32 arg1);

typedef struct {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[2];
    u8 unk_8;
    u8 pad_9[0x9E];
    u8 unk_A7;
} St_3C00_30;

typedef struct {
    u8 pad_0[0x20];
    u8 unk_20;
    u8 pad_21[0x0F];
    St_3C00_30 unk_30;
    u8 pad_D8[0x1504 - 0xD8];
    u8 unk_1504;
} Bss1_3C00;

typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[0x2298 - 0x34];
    u8 unk_2298;
    u8 pad_2299[0x2F14 - 0x2299];
    u32 unk_2F14;
} Bss2_3C00;

typedef struct {
    u8 pad_0[0x43C];
    f32 unk_43C;
    f32 unk_440;
    u8 pad_444[4];
    f32 unk_448;
} Data_5730;

void fn_1_320A4(void)
{
    Bss1_3C00 *obj = (Bss1_3C00 *)&lbl_1_bss_3C00;
    Bss2_3C00 *sub = (Bss2_3C00 *)((u8 *)obj + 0x2000);
    Data_5730 *data = (Data_5730 *)&lbl_1_data_5730;
    s32 flag;
    u32 flags;
    s32 t;
    f32 scale;

    flags = 0x2028;
    if (obj->unk_30.unk_0 & 0x100) {
        flags |= 0x180;
    }

    flag = 0;
    if (obj->unk_30.unk_5 == 1) {
        if (obj->unk_30.unk_A7 >= 4) {
            flag = 1;
        }
        if (flag) {
            flags = (flags | 0x2) & ~(1 << 18);
        } else {
            flags |= 0x4;
        }
        flags &= ~(0x8 | 0x20);
    } else {
        flags |= 0x40;
        if (obj->unk_30.unk_5 == 2) {
            flags |= 0x200;
        }
    }

    if (obj->unk_30.unk_5 == 5) {
        flags &= ~(3 << 23);
    }

    obj->unk_1504 = 0xFF;
    t = (s32)fn_1_2EBB8(flags, 2);

    scale = sub->unk_30 * 0.5f;
    data->unk_43C = 620.0f - scale;
    data->unk_448 = 140.0f;
    data->unk_440 = (f32)(450 - t);

    if (obj->unk_30.unk_8 == 0) {
        obj->unk_20 = 0;
    } else {
        obj->unk_20 = sub->unk_2298;
    }
    sub->unk_2F14 = 1;
}
