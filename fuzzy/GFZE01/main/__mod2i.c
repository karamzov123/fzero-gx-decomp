/* Non-matching: best partial attempt (22.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 hi;
    u32 lo;
} u64w;

u64w __mod2i(u32 ah, u32 al, u32 bh, u32 bl) {
    s32 la, lt, lb, lz, k, i, th;
    u32 ba, nb, rh, rl, dh, dl;
    u64w r;

    if ((s32)ah < 0) {
        al = 0 - al;
        ah = 0 - ah - (al != 0);
    }
    if ((s32)bh < 0) {
        bl = 0 - bl;
        bh = 0 - bh - (bl != 0);
    }
    la = __cntlzw(ah);
    lt = __cntlzw(al);
    if ((s32)ah == 0) {
        la = lt + 32;
    }
    lb = __cntlzw(bh);
    lz = __cntlzw(bl);
    if ((s32)bh == 0) {
        lb = lz + 32;
    }
    ba = 64 - la;
    if (la <= lb) {
        nb = 64 - (lb + 1);
        th = la + nb;
        k = ba - nb;
        if (k >= 32) {
            rl = ah >> (k - 32);
            rh = 0;
        } else {
            rl = (al >> k) | (ah << (32 - k));
            rh = ah >> k;
        }
        if (th >= 32) {
            ah = al << (th - 32);
            al = 0;
        } else {
            ah = (ah << th) | (al >> (32 - th));
            al = al << th;
        }
        i = k;
        do {
            al = al + al;
            ah = ah + ah;
            rl = rl + rl;
            rh = rh + rh;
            dl = rl - bl;
            dh = rh - bh - (rl < bl);
            if ((s32)dh >= 0) {
                rl = dl;
                rh = dh;
            }
            i--;
        } while (i != 0);
    } else {
        rh = ah;
        rl = al;
    }
    if ((s32)ah < 0) {
        rl = 0 - rl;
        rh = 0 - rh - (rl != 0);
    }
    r.hi = rh;
    r.lo = rl;
    return r;
}
