/* Non-matching: best partial attempt (97.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 w[16];
} Fn8006BCF8Pad;

typedef union {
    f64 d;
    u32 w[2];
} Fn8006BCF8Conv;

extern void *memset(void *dst, int c, unsigned long n);
extern s32 lbl_801A6C98[2];
extern u16 lbl_8019E014[64];
extern u16 lbl_8019E094[64];
extern f64 fn_800883E8(f32 x);
extern const f64 lbl_801A7380;
extern const f32 lbl_801A7388;
extern const f32 lbl_801A7370;
extern const f32 lbl_801A738C;

static inline void fill_zero(void *dst, unsigned long n) {
    unsigned long *lpd;
    unsigned char *cpd;
    unsigned long i;
    unsigned long v = 0;

    lpd = (unsigned long *)dst - 1;
    i = n >> 5;
    if (i) {
        do {
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
            *++lpd = v;
        } while (--i);
    }
    i = (n & 31) >> 2;
    if (i) {
        do {
            *++lpd = v;
        } while (--i);
    }
    cpd = (unsigned char *)(lpd + 1) - 1;
    n &= 3;
    if (n) {
        do {
            *++cpd = v;
        } while (--n);
    }
}

void fn_8006BCF8(Fn8006BCF8Pad *arg0) {
    s32 i;

    fill_zero(arg0, 0x40);
    if (lbl_801A6C98[0] == 0) {
        for (i = 0; i < 0x40; i++) {
            f32 v;
            f32 t;
            t = lbl_801A7388 * (f32)i;
            v = fn_800883E8(t * lbl_801A7370);
            lbl_8019E014[i] = lbl_801A738C * v;
            lbl_8019E094[i] = (i * 0x400) / 63;
        }
        lbl_801A6C98[0] = 1;
    }
}
