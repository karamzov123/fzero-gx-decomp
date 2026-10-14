/* Non-matching: best partial attempt (97.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Sig_fn_12_24670_MovieBuffer {
    u8 data[0x894];
} Sig_fn_12_24670_MovieBuffer;

typedef struct Sig_fn_12_24670_MovieData {
    u8 pad_00[0x0c];
    Sig_fn_12_24670_MovieBuffer buffer;
} Sig_fn_12_24670_MovieData;

typedef struct Sig_fn_12_24670_MovieModule {
    u8 pad_00[0x78];
    Sig_fn_12_24670_MovieBuffer buffer;
    u8 pad_90c[0x2908 - 0x90c];
    Sig_fn_12_24670_MovieData *movie;
} Sig_fn_12_24670_MovieModule;

typedef struct Tag4 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} Tag4;

extern void *fn_12_3310C(const void *, u32);
extern int fn_12_32EAC(void *, s32 *);
extern void fn_12_330E0(void *);
extern s32 fn_12_24670(Sig_fn_12_24670_MovieModule *, void *, int);

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
int fn_12_247BC(Sig_fn_12_24670_MovieModule *self, int size, u8 *data, u8 *p6, s32 *out) {
    s32 *outp = out;
    u32 lab_v;
    u8 *b;
    u8 *a;
    void *movie;
    s32 value;
    s32 ok;
    s32 v_2;
    struct { s32 value; } v;
    Sig_fn_12_24670_MovieModule *s = self;
    u32 lab_v_2;

    *out = 0;
    if (2 != size) {
        return 0;
    }
    a = data - 6;
    v.value = (*((-6) + (data))) << 8 | ((Tag4 *)a)->b1;
    b = p6 + 6;
    v.value = (((((Tag4 *)a)->b2)) | (v.value << 8));
    v.value = v.value << 8 | ((Tag4 *)a)->b3;
    if (0x1bf != v.value) {
        a -= 2;
        b += 2;
        v.value = ((Tag4 *)a)->b0 << 8 | ((Tag4 *)a)->b1;
        lab_v_2 = (v.value << 8 | lab_v_2);
        lab_v_2 = lab_v_2 << 8 | ((Tag4 *)a)->b3;
        v_2 = lab_v_2;
        if (0x1bf != v_2) {
            return 0;
        }
    }
    movie = fn_12_3310C((const void *)(a - 0xc), (u32)(0xc + b));
    if (0 == movie) {
        ok = 0;
    } else {
        if (fn_12_32EAC(movie, &value) == 0) {
            value = 0;
        }
        fn_12_330E0(movie);
        ok = value;
    }
    if (0 == ok) {
        return 0;
    }
    *outp = fn_12_24670(self, (void *)(a - 0xc), (int)(u32)(0xc + b));
    return 1;
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
