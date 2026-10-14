/* Non-matching: best partial attempt (70.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f64 __fabs(f64);

typedef struct Hdr {
    u32 base;
    u8 pad_4[0x114];
} Hdr;

extern Hdr lbl_801A6C80[];

typedef struct Ctrl {
    u8 pad_0[0xD];
    s8 unk_D;
    u8 unk_E;
    s8 unk_F;
} Ctrl;

typedef struct Sub {
    u8 pad_0[0x28];
    u16 unk_28;
    u16 unk_2A;
} Sub;

typedef struct Rec {
    u8 pad_0[0x59B];
    u8 unk_59B;
    u8 pad_59C[8];
    u32 unk_5A4;
} Rec;

typedef struct Entry {
    u8 pad_0[0x140A];
    u8 unk_140A;
    u8 pad_140B[0x11];
    u32 unk_141C;
    u8 pad_1420[4];
    Sub *unk_1424;
    Ctrl *unk_1428;
    u8 pad_142C[0x60];
    u32 unk_148C;
    u8 pad_1490[0x60];
    u32 unk_14F0;
    u8 pad_14F4[0x28];
    u32 unk_151C;
} Entry;

void fn_8005C298(s32 idx, s32 type) {
    u32 base;
    Entry *entry;
    Rec *rec;
    Ctrl *ctrl;
    Sub *sub;
    s32 val;
    s8 v;

    base = lbl_801A6C80[idx].base;
    entry = (Entry *)(base + idx * 0x118);
    rec = (Rec *)(base + ((entry->unk_140A & 0xFF) << 5));
    if (rec->unk_5A4 != 0) {
        ctrl = entry->unk_1428;
        sub = entry->unk_1424;
        if ((u8)type == 1) {
            v = ctrl->unk_D;
            if (v > 0) {
                val = sub->unk_28 + ((((v + 1) * 0x4B0) >> 7) * rec->unk_59B >> 7);
                if (val > 0x4B0) {
                    val = 0x4B0;
                }
            } else if (v < 0) {
                val = sub->unk_28 - ((((s32)__fabs((f64)v) * 0x4B0) >> 7) * rec->unk_59B >> 7);
                if (val < 0) {
                    val = 0;
                }
            } else {
                val = sub->unk_28;
            }
            entry->unk_14F0 = val << 16;

            rec = (Rec *)(base + ((entry->unk_140A & 0xFF) << 5));
            v = ctrl->unk_F;
            if (v > 0) {
                val = sub->unk_2A + ((((v + 1) * 0x78) >> 7) * rec->unk_59B >> 7);
                if (val > 0x78) {
                    val = 0x78;
                }
            } else if (v < 0) {
                val = sub->unk_2A - ((((s32)__fabs((f64)v) * 0x78) >> 7) * rec->unk_59B >> 7);
                if (val < 0) {
                    val = 0;
                }
            } else {
                val = sub->unk_2A;
            }
            entry->unk_151C = val << 16;
            entry->unk_148C = (entry->unk_141C - val) << 16;
        }
    }
}
