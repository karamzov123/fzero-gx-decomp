/* Non-matching: best partial attempt (16.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

f64 fn_80079D74(u32 arg0, u32 arg1) {
    u32 v0;
    u32 v1;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v8;
    union { f64 d; u64 value; struct { u32 hi; u32 lo; } w; } result;
    v0 = arg1;
    v1 = arg0;
    if ((arg0 & ~0x7FFFFFFF) != 0) {
        result.w.hi = v1;
        result.w.lo = v0;
        result.value = -result.value;
        v1 = result.w.hi;
        v0 = result.w.lo;
    }
    v3 = v1;
    v4 = v0;
    if ((v1 | v0) != 0) {
        v5 = __cntlzw(v3);
        v6 = v5 + (__cntlzw(v4) & ((s32)((v5 << 26) & 0xF8000000) >> 31));
        v3 = (v3 << v6) | (v4 >> (32 - v6)) | (v4 << (v6 - 32));
        v4 <<= v6;
        v8 = (0 - v6) + 1086;
        if ((s32)(v4 & 0x7FF) >= 1024 && ((s32)(v4 & 0x7FF) > 1024 || (v4 & 0x800) != 0)) {
            v4 += 0x800;
            v3 += v4 < 0x800;
            v8 += v4 < 0x800 && v3 == 0;
        }
        v4 = (v4 >> 11) | (v4 << 21);
        v4 = (v4 & ~0xFFE00000) | ((v3 << 21) & 0xFFE00000);
        v3 = (v3 >> 11) & 0xFFFFF;
        v3 = (v8 << 20) | v3;
        v3 = (arg0 & ~0x7FFFFFFF) | v3;
    }
    result.w.hi = v3;
    result.w.lo = v4;
    return result.d;
}
