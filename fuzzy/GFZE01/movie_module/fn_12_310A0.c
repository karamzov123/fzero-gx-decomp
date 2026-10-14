/* Non-matching: best partial attempt (76.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_310A0_Entry {
    u8 pad_0[0x18];
    u8 unk_18;
    u8 pad_19[7];
    u8 unk_20;
    u8 pad_21[2];
    u8 unk_23;
    u8 pad_24[0x1C];
};

struct fn_12_310A0_Item {
    struct fn_12_310A0_Entry a;
    struct fn_12_310A0_Entry b;
};

struct fn_12_310A0_Table {
    u8 pad_0[0x180];
    struct fn_12_310A0_Item items[13];
};

struct fn_12_310A0_Arg0 {
    s32 unk_0;
    struct fn_12_310A0_Table *unk_4;
    u32 pad_8;
    s32 unk_C;
};

struct fn_12_310A0_Arg2 {
    u32 unk_0;
};

s32 fn_12_310A0(struct fn_12_310A0_Arg0 *a, u32 b, struct fn_12_310A0_Arg2 *c) {
    s32 v0;
    s32 f;
    u32 g;
    u32 cat;
    int i;
    struct fn_12_310A0_Entry *e;

    if (a->unk_0 < 2 && a->unk_0 >= -1) {
        v0 = 0;
    } else {
        v0 = 1;
    }
    if (v0 == 0) {
        e = 0;
    } else {
        if (a->unk_C == 107 || a->unk_C >= 110) {
            e = 0;
        } else {
            e = 0;
            for (i = 0; i < 13; i++) {
                if (a->unk_4->items[i].a.unk_18 == (u8)b) {
                    e = &a->unk_4->items[i].a;
                    break;
                }
                if (a->unk_4->items[i].b.unk_18 == (u8)b) {
                    e = &a->unk_4->items[i].b;
                    break;
                }
            }
        }
    }
    if (e == 0) {
        return 0;
    }
    g = (u8)b;
    if (g >= 0xC0 && g <= 0xDF) {
        cat = 0xC0;
    } else if (g >= 0xE0 && g <= 0xEF) {
        cat = 0xE0;
    } else if (g == 0xBD || g == 0xBF) {
        cat = 0xBD;
    } else {
        cat = 0;
    }
    if (cat != 0xE0) {
        return 0;
    }
    if (e->unk_20 <= 1 && e->unk_20 != 0) {
        f = 1;
    } else {
        f = 0;
    }
    if (f == 0) {
        return 0;
    }
    c->unk_0 = (e->unk_23 >> 4) & 1;
    return 1;
}
