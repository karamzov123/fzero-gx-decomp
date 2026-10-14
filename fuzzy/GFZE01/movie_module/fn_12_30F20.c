/* Non-matching: best partial attempt (74.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_30F20_Arg0 {
    s32 unk_0;
    u8 *unk_4;
    u32 pad_8;
    s32 unk_C;
};

struct fn_12_30F20_Entry {
    u8 pad_0[0x18];
    u8 key;
    u8 pad_19[7];
    u8 flag;
    u8 pad_21[3];
    u8 value;
    u8 pad_25[0x1B];
};

s32 fn_12_30F20(struct fn_12_30F20_Arg0 *arg0, u32 arg1, u32 *arg2) {
    struct fn_12_30F20_Entry *entry;
    struct fn_12_30F20_Entry *s;
    u32 i;
    u8 *p = arg0->unk_4;
    u32 key;
    s32 b1 = (arg0->unk_0 >= 2) || (arg0->unk_0 < -1);
    s32 b2;
    s32 f;
    u32 cls;
    s32 ok;

    if (b1) {
        b2 = (arg0->unk_C == 0x6B) || (arg0->unk_C >= 0x6E);
        if (b2) {
            f = 1;
        }
    }
    if (f) {
        key = arg1 & 0xFF;
        for (i = 0; i < 13; i++) {
            s = (struct fn_12_30F20_Entry *)(p + 0x180);
            if (s->key == key) {
                entry = s;
                break;
            }
            s = (struct fn_12_30F20_Entry *)(p + 0x1C0);
            if (s->key == key) {
                entry = s;
                break;
            }
            p += 0x80;
        }
    }
    if (entry == 0) {
        return 0;
    }
    if ((arg1 & 0xFF) >= 0xC0 && (arg1 & 0xFF) <= 0xDF) {
        cls = 0xC0;
    } else if ((arg1 & 0xFF) >= 0xE0 && (arg1 & 0xFF) <= 0xEF) {
        cls = 0xE0;
    } else if ((arg1 & 0xFF) == 0xBD || (arg1 & 0xFF) == 0xBF) {
        cls = 0xBD;
    } else {
        cls = 0;
    }
    ok = 0;
    if (cls == 0xE0) {
        if (entry->flag <= 1) {
            if (entry->flag != 0) {
                ok = 1;
            }
        }
    }
    if (ok) {
        *arg2 = entry->value;
        return 1;
    }
    return 0;
}
