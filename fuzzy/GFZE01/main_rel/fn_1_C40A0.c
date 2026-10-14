/* Non-matching: best partial attempt (93.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

extern u32 fn_1_F47AC(void);
extern u32 lbl_1_bss_7AC50;
extern u8 fn_1_86624(void);
extern u32 fn_800793D4(u32, u32, u32);

typedef struct {
    u8 sel;
    u8 mode;
    u8 pad_2[2];
    f32 f1;
    f32 f2;
    f32 f3;
    u8 pad_10[12];
    f32 f7;
} Bss;

extern Bss lbl_1_bss_7AC64;

typedef struct {
    u8 pad_0[0x31];
    u8 unk_31;
    u8 pad_32[6];
    u8 unk_38;
} Sub;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x480];
    Sub *unk_484;
    u8 pad_488[0x198];
} Rec;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 pad_3[3];
    u8 b6;
    u8 pad_7;
} Row8;

typedef struct {
    u8 b0;
    u8 pad_1[7];
    u32 flags;
} Row12;

static const Row8 rows8[8] = {{0}};
static const Row12 rows12[256] = {{0}};

void fn_1_C40A0(Rec *arg0) {
    u32 i;
    s8 count;
    s32 mode;
    s32 off;
    Sub *sub;
    u8 idx;
    const Row12 *tbl;

    lbl_1_data_3D230 = fn_1_F47AC();
    fn_800793D4(lbl_1_bss_7AC50, 0, 0x21c);
    if (*(s16 *)&lbl_1_bss_960 == 9) {
        return;
    }

    count = (s8)fn_1_86624();
    tbl = rows12;
    mode = lbl_1_bss_7AC64.mode;
    off = (s32)(((s64)mode * 0x40000000LL) << 2);

    for (i = 0; i < count; i++) {
        if ((arg0[i].unk_0 & 0x20) != 0) {
            sub = arg0[i].unk_484;
            idx = sub->unk_38;
            if ((tbl[idx].flags & 2) != 0) {
                sub->unk_31 = tbl[idx].b0;
            } else {
                sub->unk_31 = (u8)((tbl[idx].b0 + off) & ~3);
            }
        }
    }

    switch ((s32)lbl_1_bss_7AC64.mode) {
    case 1:
        if (lbl_1_bss_7AC64.sel == 2 || lbl_1_bss_7AC64.sel == 3) {
            lbl_1_bss_7AC64.f7 = (f32)(1.2 * (0.01 * (f64)rows8[lbl_1_bss_7AC64.sel].b6));
            lbl_1_bss_7AC64.f1 = (f32)(1.1 * (0.01 * (f64)rows8[lbl_1_bss_7AC64.sel].b0));
            lbl_1_bss_7AC64.f2 = (f32)(1.05 * (0.01 * (f64)rows8[lbl_1_bss_7AC64.sel].b1));
            lbl_1_bss_7AC64.f3 = (f32)(1.025 * (0.01 * (f64)rows8[lbl_1_bss_7AC64.sel].b2));
        }
        break;
    case 0x10:
        if (lbl_1_bss_7AC64.sel == 2 || lbl_1_bss_7AC64.sel == 3) {
            lbl_1_bss_7AC64.f7 = (f32)(1.1 * (0.01 * (f64)rows8[lbl_1_bss_7AC64.sel].b6));
        }
        break;
    }
}
