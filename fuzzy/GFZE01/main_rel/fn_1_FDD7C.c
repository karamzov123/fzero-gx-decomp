/* Non-matching: best partial attempt (96.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const f64 lbl_1_rodata_7614;
extern f32 lbl_1_rodata_765C[19];

extern f32 fn_1_843BC(void *object);
extern void fn_1_FCF50(void);
extern void *fn_1_563B8(void *value);
extern void fn_1_566EC(s32, s32);
extern void fn_1_7EB8C(void *object, f32 value);
extern void fn_1_7F20C(void *object, f32 value, s16 value2);
extern void fn_1_7F1E8(void *object, f32 value, s16 value2);
extern void lbl_8006DFE8(void *value);
extern void lbl_8006DCA4(void);

typedef struct Fn1FDD7CObject {
    u8 pad000[0x32c];
    void *field32c;
    u8 pad330[0x60];
    s32 field390;
    u8 pad394[0x26];
    s16 field3ba;
} Fn1FDD7CObject;

typedef struct Fn1FDD7CIndex {
    s16 value;
} Fn1FDD7CIndex;

typedef struct Fn1FDD7CContext {
    u8 pad000[0x40e0];
    f32 field40e0;
    u8 pad40e4[0xc];
    Fn1FDD7CIndex *field40f0;
} Fn1FDD7CContext;

typedef struct Fn1FDD7CArg {
    Fn1FDD7CObject *object;
} Fn1FDD7CArg;

#pragma opt_common_subs off
#pragma opt_propagation on
#pragma opt_strength_reduction off
#pragma opt_loop_invariants on
#pragma opt_lifetimes off
static inline void * fn_1_FDD7C_read_pointer(Fn1FDD7CObject * owner) { return owner->field32c; }
#pragma opt_lifetimes reset

void fn_1_FDD7C(Fn1FDD7CArg *arg, Fn1FDD7CContext *context) {
    Fn1FDD7CIndex * fzgx_live;
    Fn1FDD7CObject *object;
    f32 value;
    s16 index;
    struct { void * value; } saved_value;
    s16 state;

    object = arg->object;
    state = object->field3ba;
    if (((3) == (state))) {
        object->field3ba = 2;
    }

    if (context->field40f0) {
        fzgx_live = context->field40f0;
        index = fzgx_live->value;
        if (((0) == (fn_1_FDD7C_read_pointer(object)))) {
            value = *(const f32 *)(void *)&lbl_1_rodata_7614;
        } else {
            context->field40e0 = value = fn_1_843BC(object);
            if (value <= (0.699999988f)) {
                return;
            }
        }

        saved_value.value = fn_1_563B8((void *)&fn_1_FCF50);
        fn_1_566EC(1, 0xff);
        if (fn_1_FDD7C_read_pointer(object) != 0) {
            lbl_8006DFE8((u8 *)fn_1_FDD7C_read_pointer(object) + 0x14c);
        } else {
            lbl_8006DCA4();
        }

        if (((0) == (index))) {
            fn_1_7EB8C(object, value);
        } else if ((object->field390 & 0x04000000) != 0) {
            fn_1_7F20C(object, value, index);
        } else {
            fn_1_7F1E8(object, value, index);
        }

        fn_1_566EC(0, 0);
        fn_1_563B8(saved_value.value);
        object->field3ba = state;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_common_subs reset

