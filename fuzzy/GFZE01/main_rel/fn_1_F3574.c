/* Non-matching: best partial attempt (68.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} RecVec;

extern void fn_1_862D4(s32 index, RecVec *out);
extern u8 fn_1_8682C(s32 index);

typedef struct {
    u32 w0;
    u32 w4;
    u32 c[4][3];
    u32 d[4][3];
    RecVec e;
    RecVec f;
} Rec;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x10];
    u8 unk_18;
    u8 pad_19[0x27];
    u32 unk_40;
} ReplayState;

void fn_1_F3574(ReplayState *st, u8 index, u8 value, u32 kind, u32 result) {
    u16 *tbl = (u16 *)((u8 *)st->unk_40 + 0xFEF0);
    Rec *rec;
    s32 i;
    u16 v;
    s8 ok;
    u32 t;

    if (tbl[0] >= 4) {
        return;
    }
    if (st->unk_4 > 0x7FFF) {
        return;
    }

    v = tbl[index + 16];
    if (v != 0xFFFF) {
        rec = (Rec *)((u8 *)st->unk_40 + 0xFF4C + (v << 7));
        if ((u32)(st->unk_4 - ((rec->w4 >> 16) & 0x7FFF)) < 0x3C) {
            if (((rec->w0 >> 15) & 7) == (kind & 0xFFFFFF)) {
                ok = 0;
                switch ((rec->w0 >> 15) & 7) {
                case 7:
                    break;
                case 0:
                    if (((rec->w0 >> 23) & 0x1F) == (value & 0xFFFFFF)) {
                        ok = 1;
                    } else {
                        *(u16 *)((u8 *)&rec->w0 + 2) = (u16)((*(u32 *)&rec->w0 & ~0x1F800000u) | ((value << 4) & 0x1F800000u));
                        *(u16 *)((u8 *)&rec->w4 + 2) = (u16)((*(u32 *)&rec->w4 & ~0x01F00000u) | ((result << 7) & 0x01F00000u));
                        ok = 1;
                    }
                    break;
                default:
                    ok = 1;
                    break;
                }
                if (ok) {
                    *(u16 *)&rec->w4 = (u16)((*(u32 *)&rec->w4 & ~0x7FFF0000u) | ((st->unk_4 << 1) & 0x7FFF0000u));
                    fn_1_862D4((rec->w4 >> 25) & 0x1F, &rec->f);
                    for (i = 0; i < st->unk_18; i++) {
                        fn_1_862D4(i, (RecVec *)&rec->d[i]);
                    }
                    return;
                }
            }
        }
    }

    tbl[index + 16] = tbl[0];
    rec = (Rec *)((u8 *)st->unk_40 + 0xFF4C + (tbl[0] << 7));
    tbl[0] = tbl[0] + 1;
    *(u16 *)&rec->w4 = (u16)((*(u32 *)&rec->w4 & ~0x7FFF0000u) | ((st->unk_4 << 1) & 0x7FFF0000u));
    *(u16 *)&rec->w0 = (u16)((*(u32 *)&rec->w0 & ~0x7FFF0000u) | ((rec->w4 >> 15) << 16));
    *(u8 *)((u8 *)&rec->w0 + 2) = (u8)((*(u32 *)&rec->w0 & ~0x1C000000u) | ((index << 25) & 0x1C000000u));
    *(u16 *)((u8 *)&rec->w0 + 2) = (u16)((*(u32 *)&rec->w0 & ~0x1F800000u) | ((value << 4) & 0x1F800000u));
    rec->w0 = (rec->w0 & ~0x00038000u) | ((kind << 14) & 0x00038000u);
    if (kind & 0xFFFFFF) {
        rec->w4 = (rec->w4 & ~0x000F8000u) | ((result << 12) & 0x000F8000u);
    } else {
        rec->w4 = (rec->w4 & ~0x000F8000u) | ((((u32)result & 0xFFFFFF) - 1) << 12) & 0x000F8000u;
    }
    *(u16 *)((u8 *)&rec->w4 + 2) = (u16)((*(u32 *)&rec->w4 & ~0x01F00000u) | ((result << 7) & 0x01F00000u));
    t = fn_1_8682C(0);
    *(u8 *)((u8 *)&rec->w4 + 3) = (u8)((*(u32 *)&rec->w4 & ~0x3E000000u) | ((t << 2) & 0x3E000000u));
    fn_1_862D4((rec->w4 >> 25) & 0x1F, &rec->e);
    rec->f = rec->e;
    for (i = 0; i < st->unk_18; i++) {
        fn_1_862D4(i, (RecVec *)&rec->c[i]);
        ((RecVec *)rec->d)[i] = ((RecVec *)rec->c)[i];
    }
}
