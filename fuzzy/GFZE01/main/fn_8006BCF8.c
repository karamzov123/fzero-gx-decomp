/* Non-matching: best partial attempt (43.61% in the project ledger). Scored for the
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

void fn_8006BCF8(Fn8006BCF8Pad *arg0) {
    Fn8006BCF8Conv cv;
    s32 i;
    s32 acc;

    memset(arg0, 0, 0x40);
    if (lbl_801A6C98[0] == 0) {
        acc = 0;
        for (i = 0; i < 0x40; i++) {
            f32 v;

            cv.w[0] = 0x43300000;
            cv.w[1] = i ^ 0x8000;
            v = (f32)fn_800883E8(((f32)(cv.d - lbl_801A7380)) * lbl_801A7388 * lbl_801A7370);
            lbl_8019E094[i] = (u16)(acc / 63);
            lbl_8019E014[i] = (u16)(lbl_801A738C * v);
            acc += 0x400;
        }
        lbl_801A6C98[0] = 1;
    }
}
