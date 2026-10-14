/* Non-matching: best partial attempt (97.81% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80057494_Buf {
    u8 pad_0[0x4];
    s32 unk_4;
    u8 pad_8[0x4];
    s32 unk_C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
};

struct fn_80057494_Obj {
    u8 pad_0[0x1];
    s8 unk_1;
    s8 unk_2;
    s8 unk_3;
    s8 unk_4;
    u8 pad_5[0xF];
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x4];
    s32 unk_20;
    s32 unk_24;
    u32 unk_28;
    s32 unk_2C;
    u8 pad_30[0x8];
    struct fn_80057494_Buf bufs[8];
};

extern char lbl_800922C8[];
extern void fn_800565FC(const char *, ...);
extern s32 fn_8004AEE4(u32);
extern s32 fn_8004AE78(u32);
extern void fn_8005676C(void);
extern void fn_80056E9C(struct fn_80057494_Obj *, s32, s32, s32, s32);
extern void fn_8004AD84(u32);
extern void fn_8004B0EC(u32);
extern void fn_8004B180(u32, u32, u32, u32, u32);
extern u32 fn_8004AC04(u32, u32);
extern s32 fn_8004A550(u32, s32, s32);
extern s32 fn_8004AE94(u32, u32);
extern s32 fn_8004ADF4(u32);

#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma opt_propagation off
void fn_80057494(struct fn_80057494_Obj *obj) {
    s32 lab_t1;
    if (obj->unk_4 == 1) {
        return;
    }
    if (obj->unk_1 != 2) {
        return;
    }
    if (obj->unk_24 <= 0) {
        return;
    }

    if (obj->bufs[obj->unk_20].unk_18 == 1) {
        if (obj->unk_28 == 0) {
            fn_800565FC(lbl_800922C8);
        } else {
            struct fn_80057494_Buf *p = &obj->bufs[obj->unk_20];
            s32 st = fn_8004AEE4(obj->unk_28);
            if (st == 4) {
                obj->unk_1 = 3;
            } else if (st == 2) {
                p->unk_1C = fn_8004AE78(obj->unk_28);
            } else if (st == 3) {
                p->unk_1C = obj->unk_2C;
                p->unk_18 = 2;
            }
        }
    }

    if (((2) == (obj->bufs[obj->unk_20].unk_18))) {
        s8 tmp_st;
        s32 v14;
        s32 v10;
        u32 vC;
        s32 v4;
        v14 = v10 = vC = v4 = 0;
        tmp_st = obj->unk_28;
        if (tmp_st != 0) {
            if (obj->unk_3 == 1) {
                struct fn_80057494_Buf *p = &obj->bufs[obj->unk_20];
                v4 = p->unk_4;
                vC = p->unk_C;
                v10 = p->unk_10;
                v14 = p->unk_14;
            }
            obj->unk_24 = obj->unk_24 - 1;
            obj->unk_20 = (obj->unk_20 + 1) % 16;
            if (obj->unk_24 <= 0) {
                fn_8005676C();
                obj->unk_1 = 1;
            }
            if (obj->unk_3 == 1) {
                fn_80056E9C(obj, v4, vC, v10, v14);
            }
        }
    }

    if (obj->bufs[obj->unk_20].unk_18 == 0) {
        struct fn_80057494_Buf *p = &obj->bufs[obj->unk_20];
        s32 cnt = obj->unk_24;
        if (cnt > 0) {
            fn_8004AD84(obj->unk_28);
            fn_8004B0EC(obj->unk_28);
            fn_8004B180(obj->unk_28, p->unk_4, p->unk_C, p->unk_10, p->unk_14);
            fn_8004AC04(obj->unk_28, p->unk_14);
            obj->unk_2C = p->unk_14;
            p->unk_1C = 0;
            obj->unk_2 = 0;
            if (0 == obj->unk_2) {
                fn_8004A550(obj->unk_28, obj->unk_14, obj->unk_18);
                lab_t1 = 0;
                fn_8004AE94(obj->unk_28, lab_t1);
                fn_8004ADF4(obj->unk_28);
                obj->unk_2 = 1;
            }
            p->unk_18 = 1;
        }
    }
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset
