/* Non-matching: best partial attempt (94.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct MovieCtx0 {
    u8 pad_0[0x114C];
    u32 unk_114C;
};

struct MovieModule {
    u8 pad00[0x48];
    int field48;
    u8 pad4c[0x1AF4 - 0x4C];
    int field1af4;
    int field1af8;
    int field1afc;
    int field1b00;
};

struct MovieVec {
    u32 f0;
    u32 f1;
    u32 f2;
    u32 f3;
    u32 f4;
    u32 f5;
    u32 f6;
    u32 f7;
};

extern u32 fn_12_21D30(struct MovieCtx0 *, u32);
extern int fn_12_22390(u8 *, int, u32 *);
extern int fn_12_26218(struct MovieModule *, u32, u32, int *, u32);
extern int fn_12_22008(struct MovieModule *, int);
extern void fn_12_252A0(struct MovieModule *);

#pragma opt_common_subs off
#pragma peephole off
int fn_12_26534(struct MovieModule *m) {
    int err;
    int total;
    int limit;
    u32 c;
    u32 f1;
    int err_2;
    u32 a;
    u32 b;
    u32 f2;
    u32 f3;
    int d;
    struct MovieVec vec;
    u32 lab_t1;

    lab_t1 = m->field1afc;
    f1 = fn_12_21D30((struct MovieCtx0 *)m, lab_t1);
    f2 = fn_12_21D30((struct MovieCtx0 *)m, m->field1af8);
    f3 = fn_12_21D30((struct MovieCtx0 *)m, m->field1b00);
    if ((int)(f1 & f2 & f3) == 1) {
        return 0;
    }
    err = 0;
    total = err;
    limit = 0x7FFFFFFF;
    while (total < limit) {
        int e;
        int r;

        e = fn_12_22390((u8 *)m, m->field1af4, (u32 *)&vec);
        if ((s32)e == 0) {
            a = vec.f0;
            b = vec.f1;
            c = vec.f1 + vec.f3;
            e = 0;
        }
        if ((err = e) != 0) {
            break;
        }
        if ((err = fn_12_26218(m, a, b, &d, c)) != 0) {
            break;
        }
        if (d == 0) {
            break;
        }
        r = fn_12_22008(m, m->field1af4);
        err_2 = 0;
        if (r != 0) {
            err_2 = r;
        }
        if (err_2 != 0) {
            break;
        }
        total += d;
    }
    if (m->field48 == 2) {
        fn_12_252A0(m);
    }
    return err_2;
}
#pragma peephole reset
#pragma opt_common_subs reset
