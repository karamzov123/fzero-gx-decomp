/* Non-matching: best partial attempt (98.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    void *value;
} Fn14E5E4Value;

typedef struct {
    u8 pad8[8];
    Fn14E5E4Value *value;
} Fn14E5E4Ref;

typedef struct {
    u8 pad344[0x344];
    Fn14E5E4Ref *ref;
} Fn14E5E4Obj;

extern const f32 lbl_1_rodata_9C30;
extern s16 fn_1_14F344(s16);
extern void fn_1_55FF0(f32);
extern void fn_80072558(void);
extern void fn_1_151C3C(s32 value1, s32 value2);
extern void fn_1_556B8(void *);
extern void fn_1_55210(void *);
extern void fn_1_151C78(void);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);

static inline void * fn_1_14E5E4_find_loop0(void *base, int off) {
    s16 i;
    void *r = 0;
    s16 *entry = (s16 *)base;
    for (i = 0; (u32)(s32)i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            r = (u8 *)base + (s16)i * 0x360 + off;
            break;
        }
        entry = (s16 *)((u8 *)entry + 0x360);
    }
    return r;
}

static inline void *fn_1_14E5E4_find(void *base, int off) {
    void *r = 0;
    r = fn_1_14E5E4_find_loop0(base, off);
    return r;
}

static inline void *fn_1_14E5E4_find2(void *base, int off) {
    s16 i;
    s16 *entry;
    void *r = 0;
    i = 0;
    entry = (s16 *)base;
    for (; (u32)(s32)i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            r = (u8 *)base + (s16)i * 0x360 + off;
            break;
        }
        entry = (s16 *)((u8 *)entry + 0x360);
    }
    return r;
}

/* fn_1_14DEC8 */
static inline void fn_1_14E5E4_pass0(void *arg0, void **arg1, void **arg2, s16 arg3, int arg4, f32 arg5) {
    Fn14E5E4Obj *obj;
    s16 *entry;
    s16 i;
    void *value;
    int same;
    same = lbl_1_rodata_9C30 == arg5;
    if (!same) {
        fn_1_55FF0(arg5);
    }
    i = 0;
    entry = (s16 *)arg0;
    obj = (Fn14E5E4Obj *)((u8 *)arg0 + ((s32)arg3 << 2));
    for (; (u32)(s32)i < 3; i++) {
        if (fn_1_14F344(*entry) == 0) {
            value = obj->ref->value->value;
            if (value != 0) {
                fn_80072558();
                fn_1_151C3C(0, *(s16 *)((u8 *)arg0 + (s16)i * 0x360));
                if (same || arg4 != 0) {
                    fn_1_556B8(value);
                } else {
                    fn_1_55210(value);
                }
                fn_1_151C78();
                *arg1 = fn_1_14E5E4_find(arg0, 0x23c);
                *arg2 = fn_1_14E5E4_find2(arg0, 0x228);
                break;
            }
        }
        entry = (s16 *)((u8 *)entry + 0x360);
        obj = (Fn14E5E4Obj *)((u8 *)obj + 0x360);
    }
}

/* fn_1_14E09C (kind 1) and fn_1_14E1E0 (kind 2) */
static inline void fn_1_14E5E4_pass(void *arg0, void *arg1, s16 arg2, int arg3, f32 arg4, s16 kind) {
    s16 i;
    int same;
    void *value;
    Fn14E5E4Obj *obj;
    s16 *entry;
    same = lbl_1_rodata_9C30 == arg4;
    if (arg1 != 0) {
        if (!same) {
            fn_1_55FF0(arg4);
        }
        entry = (s16 *)arg0;
        obj = (Fn14E5E4Obj *)((u8 *)arg0 + ((s32)arg2 << 2));
        for (i = 0; (u32)(s32)i < 3; i++) {
            if (fn_1_14F344(*entry) == kind) {
                value = obj->ref->value->value;
                if (value != 0) {
                    lbl_8006E0A4(arg1);
                    fn_80072558();
                    fn_1_151C3C(kind, *entry);
                    if (same || arg3 != 0) {
                        fn_1_556B8(value);
                    } else {
                        fn_1_55210(value);
                    }
                    fn_1_151C78();
                }
            }
            entry = (s16 *)((u8 *)entry + 0x360);
            obj = (Fn14E5E4Obj *)((u8 *)obj + 0x360);
        }
    }
}

void fn_1_14E5E4(void *arg0, s16 arg1, f32 arg2) {
    void *upper = 0;
    void *lower = 0;

    fn_1_14E5E4_pass0(arg0, &upper, &lower, arg1, 1, arg2);
    lbl_8006DAEC();
    fn_1_14E5E4_pass(arg0, upper, arg1, 1, arg2, 1);
    lbl_8006DBE4();
    fn_1_14E5E4_pass(arg0, lower, arg1, 1, arg2, 2);
    lbl_8006DC20();
}
