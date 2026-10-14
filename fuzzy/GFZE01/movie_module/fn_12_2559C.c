/* Non-matching: best partial attempt (88.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct MovieState {
    u8 pad_0[0x30];
    s32 f_30;
};

struct MovieModule {
    u8 pad_00[0x28];
    s32 f_28;
    u8 pad_2C[0x1AC0];
    struct MovieState *f_1AEC;
    u32 f_1AF0;
    u32 f_1AF4;
    u32 f_1AF8;
    u32 f_1AFC;
    u32 f_1B00;
    s32 f_1B04;
};

extern s32 fn_12_21F28(struct MovieModule *, u32);
extern s32 fn_12_23250(struct MovieModule *);
extern s32 fn_12_231F8(struct MovieModule *);
extern s32 fn_12_21D30(struct MovieModule *, u32);
extern void fn_12_21D40(struct MovieModule *, u32, s32);
extern u32 fn_12_67A4(const u8 *);

s32 fn_12_2559C(struct MovieModule *arg0, const u8 *arg1, s32 arg2, s32 arg3) {
    s32 v2;
    struct MovieState *st = arg0->f_1AEC;
    u32 v1;
    s32 state;
    u32 lab_t1;
    v1 = arg0->f_1AF4;
    v2 = arg0->f_28;

    if (arg2 >= 4) {
        state = fn_12_67A4(arg1);
        if (state == 0x80000) {
            if (arg0->f_1B04 < 0) {
                arg0->f_1B04 = fn_12_21F28(arg0, v1) + 4;
            }
            st->f_30 = 1;
        } else if (state != 0) {
            st->f_30 = 0;
        }
    } else {
        state = 0;
    }

    if (state != 0x80000 && fn_12_23250(arg0) != 0 && fn_12_231F8(arg0) != 0) {
        fn_12_21D40(arg0, arg0->f_1AFC, 1);
        lab_t1 = arg0->f_1AF8;
        fn_12_21D40(arg0, lab_t1, 1);
        fn_12_21D40(arg0, arg0->f_1B00, 1);
        return 0;
    }

    if (arg3 < 4 && fn_12_21D30(arg0, v1) == 1) {
        fn_12_21D40(arg0, arg0->f_1AFC, 1);
        fn_12_21D40(arg0, arg0->f_1AF8, 1);
        fn_12_21D40(arg0, arg0->f_1B00, 1);
        return 0;
    }

    if (arg2 < v2) {
        if (state == 0x10000) {
            return 0;
        } else if (state == 0x40000) {
            return 1;
        }
    }

    return 1;
}
