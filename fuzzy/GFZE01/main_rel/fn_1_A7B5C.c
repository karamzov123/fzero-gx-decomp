/* Non-matching: best partial attempt (99.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/driver.h"

typedef struct FnA7B5CVec {
    s32 x;
    s32 y;
    s32 z;
} FnA7B5CVec;

typedef struct FnA7B5CMtx {
    f32 m[12];
} FnA7B5CMtx;

typedef struct FnA7B5CObj {
    FnA7B5CMtx unk_0[4];
    f32 unk_C0;
    f32 unk_C4;
    f32 unk_C8;
    f32 unk_CC;
    f32 unk_D0;
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
    f32 unk_E0;
    f32 unk_E4;
    s8 unk_E8;
    u8 unk_E9;
    u8 pad_EA[0x22];
    f32 unk_10C;
    f32 unk_110;
    FnA7B5CVec unk_114;
    f32 unk_120;
    f32 unk_124;
    f32 unk_128;
    FnA7B5CMtx unk_12C[10];
} FnA7B5CObj;

typedef struct FnA7B5CSrc {
    u8 pad_0[8];
    u8 *unk_8;
} FnA7B5CSrc;

typedef struct FnA7B5CEntry {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
} FnA7B5CEntry;

extern void fn_1_A7F84(void *, s32);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DD7C(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DFC4(void *);
extern void lbl_8006DB30(void);

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_A7B5C(FnA7B5CObj *obj, FnA7B5CSrc *src, s8 arg2, s8 arg3, FnA7B5CVec *arg4, u32 lab_unused0, u32 lab_unused1, u32 lab_unused2) {
    f32 fzgx_value;
    u8 * fzgx_live;
    FnA7B5CMtx *m;
    s32 i;

    obj->unk_E0 = 0.0f;
    obj->unk_DC = 0.0f;
    fzgx_value = 0.0f;
    obj->unk_E4 = fzgx_value;
    obj->unk_D8 = 0.0f;
    obj->unk_120 = 0.0f;
    obj->unk_124 = 0.0f;
    obj->unk_128 = 0.0f;
    obj->unk_E8 = arg3;
    obj->unk_E9 = arg2 >= 41;
    if (obj->unk_E9) {
        if (arg3 == 33) {
            obj->unk_120 = 0.0f;
            obj->unk_124 = 0.0f;
            obj->unk_128 = -0.1f;
        } else if (arg3 == 42) {
            obj->unk_120 = 0.1f;
            obj->unk_124 = 0.0f;
            obj->unk_128 = 0.1f;
        } else if (arg3 == 43) {
            obj->unk_120 = -0.1f;
            obj->unk_124 = 0.0f;
            obj->unk_128 = 0.1f;
        } else if (arg3 == 21) {
            obj->unk_120 = 0.0f;
            obj->unk_124 = 0.0f;
            obj->unk_128 = 0.1f;
        } else if (arg3 == 41) {
            obj->unk_120 = 0.0f;
            obj->unk_124 = 0.0f;
            obj->unk_128 = -0.1f;
        }
    }
    if (arg4 != 0) {
        obj->unk_114 = *arg4;
    } else {
        obj->unk_114 = ((FnA7B5CVec *)&lbl_1_data_343C4)[arg3];
    }
    if (src != 0) {
        m = obj->unk_12C;
        for (i = 0; i < 10; i++, m++) {
            fzgx_live = src->unk_8;
            lbl_8006DD14(fzgx_live + ((s8 *)&lbl_1_data_34348)[i] * 0x18c + 0x88, m);
        }
        fzgx_live = src->unk_8;
        obj->unk_C0 = *(f32 *)(fzgx_live + 0xe80);
        fzgx_live = src->unk_8;
        obj->unk_C4 = *(f32 *)(fzgx_live + 0xe90);
        fzgx_live = src->unk_8;
        obj->unk_C8 = *(f32 *)(fzgx_live + 0xea0);
        fzgx_live = src->unk_8;
        obj->unk_CC = *(f32 *)(fzgx_live + 0x163c);
        fzgx_live = src->unk_8;
        obj->unk_D0 = *(f32 *)(fzgx_live + 0x164c);
        fzgx_live = src->unk_8;
        obj->unk_D4 = *(f32 *)(fzgx_live + 0x165c);
        fzgx_live = src->unk_8;
        obj->unk_10C = *(f32 *)(fzgx_live + 0xc74);
        fzgx_live = src->unk_8;
        obj->unk_110 = *(f32 *)(fzgx_live + 0xe00);
    } else {
        FnA7B5CMtx *m2;
        s32 j;
        s32 off;

        off = arg3 * 0x5c;
        m2 = obj->unk_12C;
        for (j = 0; j < 10; j++, m2++) {
            fn_1_A7F84((u8 *)&lbl_1_data_345D4 + off, j);
            lbl_8006DB74(m2);
        }
#define ENT ((FnA7B5CEntry *)((u8 *)&lbl_1_data_345D4 + off))
        obj->unk_C0 = ENT->unk_48;
        obj->unk_C4 = ENT->unk_4C;
        obj->unk_C8 = ENT->unk_50;
        obj->unk_CC = -ENT->unk_48;
        obj->unk_D0 = ENT->unk_4C;
        obj->unk_D4 = ENT->unk_50;
        obj->unk_10C = ENT->unk_54;
        obj->unk_110 = ENT->unk_58;
        goto end;
        obj->unk_C0 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_48;
        obj->unk_C4 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_4C;
        obj->unk_C8 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_50;
        obj->unk_CC = -((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_48;
        obj->unk_D0 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_4C;
        obj->unk_D4 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_50;
        obj->unk_10C = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_54;
        obj->unk_110 = ((FnA7B5CEntry *)&lbl_1_data_345D4)[arg3].unk_58;
    }
end:
    lbl_8006DBAC(&obj->unk_12C[1]);
    lbl_8006DB74(obj);
    lbl_8006DD7C();
    lbl_8006DAEC();
    lbl_8006DFC4(&obj->unk_12C[3]);
    lbl_8006DB74(&obj->unk_0[1]);
    lbl_8006DB30();
    lbl_8006DAEC();
    lbl_8006DFC4(&obj->unk_12C[5]);
    lbl_8006DB74(&obj->unk_0[2]);
    lbl_8006DB30();
    lbl_8006DAEC();
    lbl_8006DFC4(&obj->unk_12C[2]);
    lbl_8006DB74(&obj->unk_0[3]);
    lbl_8006DB30();
}
#pragma opt_propagation reset

#pragma opt_common_subs reset

