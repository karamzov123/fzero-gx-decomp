/* Non-matching: best partial attempt (91.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 unk1;
    u8 unk2;
    u8 pad3[3];
    u16 unk6;
    u8 pad8[0x10];
    s32 unk18;
    u32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} Row;

typedef struct {
    u8 pad_0[0x408];
    u16 unk_408;
    u16 unk_40A;
    u8 pad_40C[0xE];
    u8 unk_41A;
    u8 unk_41B;
    u8 unk_41C;
    u8 pad_41D[0x2A3];
    Row rows[256];
} fn_8003A91C_Arg0;

typedef struct {
    u8 pad0[0x790];
    u8 list[16];
    u16 unk_7A0;
    u16 unk_7A2;
    u16 unk_7A4;
} List;

#define PUSH() \
    do { \
        c = lv->unk_7A2; \
        lv->unk_7A2 = c + 1; \
        lv->list[c] = tag; \
    } while (0)

#pragma opt_common_subs on
#pragma opt_dead_assignments off
s32 fn_8003A91C(fn_8003A91C_Arg0 *arg0) {
    List *lv = (List *)arg0;
    u32 i;
    Row *row;
    s32 v;
    s32 n;
    s32 m;
    s32 k;
    u16 c;
    u8 tag;

    v = arg0->unk_41A << 3;
    lv->unk_7A0 = (v + arg0->unk_408 - 1) / v;
    v = arg0->unk_41B << 3;
    lv->unk_7A4 = (v + arg0->unk_40A - 1) / v;
    lv->unk_7A2 = 0;
    for (i = 0; i < arg0->unk_41C; i++) {
        row = &arg0->rows[i];
        v = arg0->unk_41A << 3;
        row->unk2C = (v + arg0->unk_408 * row->unk1 - 1) / v;
        v = arg0->unk_41B << 3;
        row->unk28 = (v + arg0->unk_40A * row->unk2 - 1) / v;
        row->unk18 = row->unk1;
        row->unk1C = row->unk2;
        row->unk20 = row->unk18 * row->unk1C;
        row->unk24 = row->unk18 << 3;
        n = row->unk20;
        (void)n;
        if (lv->unk_7A2 + n > 16) {
            return 11;
        }
        m = n;
        tag = (u8)i;
        for (k = m; k > 0; k--) {
            PUSH();
        }
        row->unk6 = 0;
    }
    return 0;
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
