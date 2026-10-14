/* Non-matching: best partial attempt (74.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0x18];
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    u8 pad_2C[0x17C];
} Entry_1_E733C;

typedef struct {
    u8 pad_0[0x20];
    f32 f20;
    u8 pad_24[0xC];
    f32 f30;
    u8 pad_34[0x4];
    f32 f38;
    u8 pad_3C[0x4C];
    f32 f88;
    u8 pad_8C[0x2A0];
    f32 f32C;
} Pool_1_E733C;

typedef struct {
    u16 unk_0;
    u8 pad_2[0xE];
    u16 unk_10;
    u8 pad_12[0x2];
    u16 unk_14;
    u8 pad_16[0xE];
    u16 unk_24;
} Stat_1_E733C;

typedef struct {
    s16 unk_0;
} Ctr_1_E733C;

extern Pool_1_E733C lbl_1_rodata_6780;
extern Stat_1_E733C lbl_1_bss_9F8;
extern Ctr_1_E733C lbl_1_bss_7B14C;

f32 fn_1_E733C(Entry_1_E733C *obj, s32 count) {
    Pool_1_E733C *pool = &lbl_1_rodata_6780;
    f32 f = pool->f20;
    s16 c;
    s16 i;

    if ((s16)count == 0) {
        return f;
    }
    if ((lbl_1_bss_9F8.unk_10 & 0x8) || (lbl_1_bss_9F8.unk_24 & 0x8)) {
        lbl_1_bss_7B14C.unk_0 = lbl_1_bss_7B14C.unk_0 - 1;
    }
    if ((lbl_1_bss_9F8.unk_10 & 0x4) || (lbl_1_bss_9F8.unk_24 & 0x4)) {
        lbl_1_bss_7B14C.unk_0 = lbl_1_bss_7B14C.unk_0 + 1;
    }
    if ((lbl_1_bss_9F8.unk_10 & 0x1) || (lbl_1_bss_9F8.unk_24 & 0x1)) {
        f = pool->f32C;
    }
    if ((lbl_1_bss_9F8.unk_10 & 0x2) || (lbl_1_bss_9F8.unk_24 & 0x2)) {
        f = pool->f30;
    }
    if ((lbl_1_bss_9F8.unk_0 & 0x100) || (lbl_1_bss_9F8.unk_14 & 0x100)) {
        f = f * pool->f38;
    }
    if ((lbl_1_bss_9F8.unk_0 & 0x200) || (lbl_1_bss_9F8.unk_14 & 0x200)) {
        f = f / pool->f38;
    }
    c = lbl_1_bss_7B14C.unk_0;
    if (c > 4) {
        c = 0;
    } else if (c < 0) {
        c = 4;
    }
    lbl_1_bss_7B14C.unk_0 = c;
    for (i = 0; i < (s16)count; i++) {
        switch (lbl_1_bss_7B14C.unk_0) {
        case 0:
            obj[i].f18 = obj[i].f18 + f;
            break;
        case 1:
            obj[i].f1C = obj[i].f1C + f;
            break;
        case 2:
            obj[i].f20 = obj[i].f20 + f;
            break;
        case 3:
            obj[i].f24 = obj[i].f24 + f;
            break;
        case 4:
            obj[i].f28 = obj[i].f28 + f / pool->f88;
            break;
        }
    }
    return f;
}
