/* Non-matching: best partial attempt (0.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

u64 __div2u(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    s32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v8;
    u32 v9;
    u64 v17;
    u64 v18;
    u32 carry;
    u32 next;

    v0 = __cntlzw(arg0);
    if ((s32)arg0 == 0) {
        v0 = __cntlzw(arg1) + 32;
    }
    v1 = __cntlzw(arg2);
    if ((s32)arg2 == 0) {
        v1 = __cntlzw(arg3) + 32;
    }
    if ((s32)v0 <= (s32)v1) {
        v2 = 64 - (v1 + 1);
        v3 = v0 + v2;
        v4 = (64 - v0) - v2;
        v6 = v4 - 32;
        if ((s32)v4 >= 32) {
            v5 = arg0 >> v6;
            v6 = 0;
        } else {
            v5 = arg1 >> v4;
            v6 = 32 - v4;
            v6 = arg0 << v6;
            v5 = v6 | v5;
            v6 = arg0 >> v4;
        }
        v8 = arg0;
        v9 = arg1;
        if ((s32)v3 >= 32) {
            v8 = v9 << (v3 - 32);
            v9 = 0;
        } else {
            v8 = v8 << v3;
            v8 = (v9 >> (32 - v3)) | v8;
            v9 = v9 << v3;
        }
        carry = 0;
        do {
            next = v8 >> 31;
            v17 = (((u64)v8 << 32) | v9) * 2 + carry;
            v8 = v17 >> 32;
            v9 = v17;
            v18 = (((u64)v6 << 32) | v5) * 2 + next;
            v17 = v18 - (((u64)arg2 << 32) | arg3);
            carry = 0;
            if ((s64)v17 >= 0) {
                v18 = v17;
                carry = 1;
            }
            v6 = v18 >> 32;
            v5 = v18;
        } while (--v4);
        return (((u64)v8 << 32) | v9) * 2 + carry;
    }
    return 0;
}
