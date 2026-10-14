/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 hi;
    u32 lo;
} u64s;

u64s __div2i(u64s n, u64s d) {
    u32 sn;
    u32 sd;
    u32 qh;
    u32 ql;
    u32 rh;
    u32 rl;
    u32 th;
    u32 tl;
    u32 bit;
    u32 bw;
    s32 c1;
    s32 c2;
    s32 sh;
    s32 cnt;
    s32 i;
    u64s q;

    sn = n.hi & 0x80000000;
    sd = d.hi & 0x80000000;
    if (sn != 0) {
        n.lo = 0 - n.lo;
        n.hi = 0 - n.hi - (n.lo != 0);
    }
    if (sd != 0) {
        d.lo = 0 - d.lo;
        d.hi = 0 - d.hi - (d.lo != 0);
    }
    c1 = (n.hi != 0) ? __cntlzw(n.hi) : __cntlzw(n.lo) + 32;
    c2 = (d.hi != 0) ? __cntlzw(d.hi) : __cntlzw(d.lo) + 32;
    if (c1 > c2) {
        q.hi = 0;
        q.lo = 0;
        return q;
    }
    sh = c1 + c2 - 63;
    cnt = 127 - c1 - c2;
    if (cnt >= 32) {
        rh = n.hi >> (cnt - 32);
        rl = 0;
    } else {
        rh = (n.lo >> cnt) | (n.hi << (32 - cnt));
        rl = n.hi >> cnt;
    }
    if (sh >= 32) {
        qh = n.lo << (sh - 32);
        ql = 0;
    } else {
        qh = (n.hi << sh) | (n.lo >> (32 - sh));
        ql = n.lo << sh;
    }
    for (i = 0; i < cnt; i++) {
        bit = 0;
        if (ql != 0) {
            bit = qh >> 31;
            ql = ql + ql;
            qh = qh + qh + bit;
        } else {
            ql = 0;
            qh = qh + qh;
        }
        rl = rl + rl;
        rh = rh + rh + bit;
        bw = (rl <= d.lo) ? 1 : 0;
        tl = rl - d.lo - 1;
        th = rh - d.hi - bw;
        if ((s32)th >= 0) {
            rh = th;
            rl = tl;
            bit = 0;
        } else {
            bit = 1;
        }
    }
    if (rl <= d.lo && rh <= d.hi) {
        ql = ql + ql + 1;
    } else {
        ql = ql + ql;
    }
    qh = qh + qh + (ql > ql);
    q.hi = qh;
    q.lo = ql;
    if ((sn ^ sd) != 0) {
        if (sn != 0) {
            q.lo = 0 - q.lo;
            q.hi = 0 - q.hi - (q.lo != 0);
        }
    }
    return q;
}
