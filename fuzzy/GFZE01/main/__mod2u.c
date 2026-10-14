/* Non-matching: best partial attempt (14.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

u64 __mod2u(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    s32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v8;
    u32 v9;
    union { u64 value; struct { u32 hi, lo; } word; } v17, v18, divisor, result;
    u32 carry;
    u32 low;
    s32 high;
    v0 = __cntlzw(arg0);
    if ((s32)arg0 == 0) {
        v0 = __cntlzw(arg1) + 32;
    }
    v1 = __cntlzw(arg2);
    if ((s32)arg2 == 0) {
        v1 = __cntlzw(arg3) + 32;
    }
    if ((s32)v0 > (s32)v1) {
        return ((u64)arg0 << 32) | arg1;
    }
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
    v17.word.hi = v6;
    v17.word.lo = v5;
    v18.word.hi = v8;
    v18.word.lo = v9;
    divisor.word.hi = arg2;
    divisor.word.lo = arg3;
    do {
        carry = v18.word.hi >> 31;
        v18.value += v18.value;
        v17.value = v17.value + v17.value + carry;
        result.value = v17.value - divisor.value;
        if ((s32)result.word.hi >= 0) {
            v17.value = result.value;
        }
    } while (--v4);
    return v17.value;
}
