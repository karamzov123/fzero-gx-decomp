/* Non-matching: best partial attempt (95.10% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f32 lbl_1_rodata_9C30;
extern void fn_1_55FF0(f32);
extern s16 fn_1_14F344(s16);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_1_151C3C(int, s16);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);

typedef struct {
    u8 pad[8];
    void **value;
} RecInner;

typedef struct {
    s16 id;
    u8 pad1[0x226];
    void *f228;
    u8 pad2[0x10];
    void *f23c;
    u8 pad3[0x104];
    RecInner *inner;
    u8 pad4[0x18];
} RecEntry;

#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_1_14E2DC(RecEntry *arg0, u32 arg1, f32 arg2) {
    RecEntry *rec;
    void *p1;
    void *p2;
    RecEntry *base;
    int same;
    s16 i;
    void *t;

    base = arg0;
    p1 = 0;
    p2 = 0;
    same = (lbl_1_rodata_9C30 == arg2);
    if (same == 0) {
        fn_1_55FF0(arg2);
    }

    rec = (RecEntry *)((u8 *)base + ((s32)(s16)arg1 << 2));
    {
        s16 *e = (s16 *)base;
        RecEntry *q = rec;

        for (i = 0; (u32)(s32)i < 3; i++) {
            if (fn_1_14F344(*e) == 0) {
                void *value = *q->inner->value;

                if (value != 0) {
                    s16 *ids;

                    fn_80072558();
                    fn_1_151C3C(0, base[i].id);
                    if (same) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();

                    t = 0;
                    ids = (s16 *)base;
                    for (i = 0; (u32)(s32)i < 3; i++) {
                        if (fn_1_14F344(*ids) == 0) {
                            t = (void *)((u8 *)base + i * 0x360 + 0x23C);
                            break;
                        }
                        ids = (s16 *)((u8 *)ids + 0x360);
                    }
                    p1 = t;

                    t = 0;
                    ids = (s16 *)base;
                    for (i = 0; (u32)(s32)i < 3; i++) {
                        if (fn_1_14F344(*ids) == 0) {
                            t = (void *)((u8 *)base + i * 0x360 + 0x228);
                            break;
                        }
                        ids = (s16 *)((u8 *)ids + 0x360);
                    }
                    p2 = t;
                }
            }
            e = (s16 *)((u8 *)e + 0x360);
            q = (RecEntry *)((u8 *)q + 0x360);
        }
    }

    lbl_8006DAEC();
    same = (lbl_1_rodata_9C30 == arg2);
    if (p1 != 0) {
        if (same == 0) {
            fn_1_55FF0(arg2);
        }
        {
            RecEntry *q = rec;
            s16 *e = (s16 *)base;
            s16 j;

            for (j = 0; (u32)(s32)j < 3; j++) {
                if (fn_1_14F344(*e) == 1) {
                    void *value = *q->inner->value;

                    if (value != 0) {
                        lbl_8006E0A4(p1);
                        fn_80072558();
                        fn_1_151C3C(1, *e);
                        if (same) {
                            fn_1_556B8(value);
                        } else {
                            fn_1_55210(value);
                        }
                        fn_1_151C78();
                    }
                }
                e = (s16 *)((u8 *)e + 0x360);
                q = (RecEntry *)((u8 *)q + 0x360);
            }
        }
    }

    lbl_8006DBE4();
    same = (lbl_1_rodata_9C30 == arg2);
    if (p2 != 0) {
        if (same == 0) {
            fn_1_55FF0(arg2);
        }
        {
            s16 *e = (s16 *)base;
            s16 j;

            for (j = 0; (u32)(s32)j < 3; j++) {
                if (fn_1_14F344(*e) == 2) {
                    void *value = *rec->inner->value;

                    if (value != 0) {
                        lbl_8006E0A4(p2);
                        fn_80072558();
                        fn_1_151C3C(2, *e);
                        if (same) {
                            fn_1_556B8(value);
                        } else {
                            fn_1_55210(value);
                        }
                        fn_1_151C78();
                    }
                }
                e = (s16 *)((u8 *)e + 0x360);
                rec = (RecEntry *)((u8 *)rec + 0x360);
            }
        }
    }
    lbl_8006DC20();
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
