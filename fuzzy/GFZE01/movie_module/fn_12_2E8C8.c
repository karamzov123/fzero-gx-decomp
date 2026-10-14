/* Non-matching: best partial attempt (89.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieModuleState MovieModuleState;
typedef s32 (*MovieCallback)(MovieModuleState *, s32 *, s32 *);
typedef struct MovieObject MovieObject;

typedef struct RateInfo {
    s32 enabled;
    u8 pad_004[0x1c];
    s32 numerator;
    s32 denominator;
} RateInfo;

struct MovieModuleState {
    u8 padding_000[0xcc0];
    MovieCallback callbacks[16];
    u8 pad_d00[0xa4];
    RateInfo rate;
    s32 offset;
    s32 marker;
    u8 pad_dd4[0x134];
    s32 state;
    s32 value;
};

extern s32 fn_12_24990(u32);
extern s32 fn_12_24A88(MovieObject *, u32);
extern void fn_12_24970(s32 *);
extern s32 fn_12_2D73C(MovieModuleState *, s32);
extern s32 fn_12_2E6AC(MovieModuleState *, s32 *, s32 *);
extern void fn_12_24950(s32 *);
extern unsigned int UTY_MulDiv(int, int, int);

#pragma peephole off
s32 fn_12_2E8C8(MovieModuleState *module, s32 *result, s32 *flag) {
    RateInfo *rate = &module->rate;
    s32 index;
    struct { s32 value; } ret;
    struct { MovieCallback value; } callback;
    struct {
    u8 lab_pad[4]; s32 value; } work;

#pragma opt_propagation off

    if (fn_12_24990((u32)module)) {
        return fn_12_24A88(0, 0xFF000121u);
    }
    if (module->state == -5) {
        fn_12_24970(&work.value);
        index = fn_12_2D73C(module, 15);
        callback.value = (*((module->callbacks) + (index)));
        if (callback.value == 0) {
            callback.value = fn_12_2E6AC;
        }
        ret.value = callback.value(module, result, flag);
        fn_12_24950(&work.value);
    } else {
        *result = module->state;
        ret.value = 0;
        *flag = module->value;
    }
    if (*flag != 1) {
    } else if (*flag == module->marker) {
        *result += module->offset;
    } else if (rate->enabled != 0) {
        *result += UTY_MulDiv(rate->numerator, *flag, rate->denominator);
    }
    return ret.value;
}
#pragma peephole reset

