/* Non-matching: best partial attempt (71.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 fn_800077E0(u32);
extern void fn_80007700(void *, u32);

typedef struct Entry {
    u32 a : 1;
    u32 b : 24;
    u32 c : 1;
    u32 d : 6;
    u8 pad[3];
    u8 e : 1;
    u8 f : 1;
    u8 g : 1;
    u8 h : 3;
    u8 i : 2;
} Entry;

void fn_800075AC(u32 arg0, u32 arg1, u32 arg2) {
    u32 flags;
    u32 p0;
    u32 i;
    u32 n;
    Entry *t0;

    arg0 &= ~0xFFF;
    flags = (u8)(3 & ((-(s32)arg2 | (s32)arg2) >> 31));
    p0 = arg0;
    i = 0;
    n = (arg1 + (arg0 & 0xFFF) + 0xFFF) >> 12;
    while (i < n) {
        t0 = (Entry *)fn_800077E0(p0);
        if (t0 != 0) {
            t0->i = flags;
            fn_80007700(t0, p0);
        }
        p0 += 0x1000;
        i++;
    }
}
