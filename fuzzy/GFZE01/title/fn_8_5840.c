/* Non-matching: best partial attempt (92.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/title/title.h"

#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_8_5840(void *arg0) {
    u8 *base = (u8 *)&lbl_8_data_0;
    u8 * v2_2;
    void *v1 = arg0;
    u8 *v2;
    s32 v3;
    s32 v9;
    s32 v15;
    s32 v22;
    u32 count3;
    u32 count9;
    u32 count15;
    u32 count22;
    v2 = base + 31996;
    v3 = 0;
    for (count3 = 9; count3 != 0; count3--) {
        if (*((volatile u8 *)v1) == v2[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32196;
            v1 = (u8 *)v1 + v3 / 2;
            return (s32)v1;
        }
        v3 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32196;
            v1 = (u8 *)v1 + v3 / 2;
            return (s32)v1;
        }
        v3 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32196;
            v1 = (u8 *)v1 + v3 / 2;
            return (s32)v1;
        }
        v2 += 2;
        v3 += 2;
    }
    v2 = base + 32052;
    v9 = 0;
    for (count9 = 9; count9 != 0; count9--) {
        if (*((volatile u8 *)v1) == v2[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32224;
            v1 = (u8 *)v1 + v9 / 2;
            return (s32)v1;
        }
        v9 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32224;
            v1 = (u8 *)v1 + v9 / 2;
            return (s32)v1;
        }
        v9 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32224;
            v1 = (u8 *)v1 + v9 / 2;
            return (s32)v1;
        }
        v2 += 2;
        v9 += 2;
    }
    v2 = base + 32108;
    v15 = 0;
    for (count15 = 8; count15 != 0; count15--) {
        if (*((volatile u8 *)v1) == v2[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32252;
            v1 = (u8 *)v1 + v15 / 2;
            return (s32)v1;
        }
        v15 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32252;
            v1 = (u8 *)v1 + v15 / 2;
            return (s32)v1;
        }
        v15 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32252;
            v1 = (u8 *)v1 + v15 / 2;
            return (s32)v1;
        }
        v15 += 2;
        if (*((volatile u8 *)v1) == (v2 += 2)[0] && *((volatile u8 *)v1 + 1) == v2[1]) {
            v1 = base + 32252;
            v1 = (u8 *)v1 + v15 / 2;
            return (s32)v1;
        }
        v2 += 2;
        v15 += 2;
    }
    v2_2 = base + 32172;
    v22 = 0;
    for (count22 = 11; count22 != 0; count22--) {
        if (*((volatile u8 *)v1) == v2_2[0] && *((volatile u8 *)v1 + 1) == v2_2[1]) {
            v1 = base + 32288;
            v1 = (u8 *)v1 + v22 / 2;
            return (s32)v1;
        }
        v2_2 += 2;
        v22 += 2;
    }
    return 0;
}
#pragma opt_lifetimes reset

