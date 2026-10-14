/* Non-matching: best partial attempt (98.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"
typedef struct {
    u8 pad_0[8];
    u32 unk_8;
    u32 unk_C;
    u8 pad_10[4];
    s8 type;
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Sig_fn_1_C0B0C_Fn1C0510Obj;
struct fn_1_C0B0C_lbl_801A6410 { u32 unk_0; };
extern struct fn_1_C0B0C_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_4630(u32, u32, const char *, int);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_80008BA8(u32, u32, u32);
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 text[0x2A];
    u32 unk_2C;
} C0B0CEntry;

void fn_1_C0B0C(u32 arg0) {
    C0B0CEntry *v0;
    Sig_fn_1_C0B0C_Fn1C0510Obj *obj = (Sig_fn_1_C0B0C_Fn1C0510Obj *)arg0;
    u32 v13;
    u32 v4;
    s32 v17;
    u8 *v2;
    v0 = (C0B0CEntry *)((u8 *)&lbl_1_bss_77380 + obj->third * 0x1800 + obj->fourth * 0x30);
    if (v0->unk_1 == 2) {
        obj->unk_C = 16040;
    } else if (v0->unk_1 == 4) {
        v13 = 0;
        v2 = v0->text;
#pragma unroll on
        for (v17 = 0; v17 < 5; v17++) {
            v4 = *v2;
            if (v4 >= 65 && v4 <= 70) v4 -= 55;
            else v4 -= 48;
            v13 += v4 << ((4 - v17) << 2);
            v2++;
        }
        obj->unk_C = v13;
    } else if (v0->unk_1 == 5) {
        v13 = 0;
        v2 = v0->text;
        for (v17 = 0; v17 < 8; v17++) {
            v4 = *v2;
            if (v4 >= 65 && v4 <= 70) v4 -= 55;
            else v4 -= 48;
            v13 += v4 << ((7 - v17) << 2);
            v2++;
        }
        obj->unk_C = v13;
    }
    if (obj->unk_8 != 0) {
        fn_1_46B4(lbl_801A6410.unk_0, obj->unk_8, (const char *)&lbl_1_data_3C7B8, 12778);
        obj->unk_8 = 0;
    }
    if (v0->unk_2C != 0) {
        obj->unk_8 = fn_1_4630(lbl_801A6410.unk_0, obj->unk_C, (const char *)&lbl_1_data_3C7B8, 12783);
        fn_80008BA8(obj->unk_8, v0->unk_2C, obj->unk_C);
    } else {
        obj->unk_8 = 0;
    }
}
