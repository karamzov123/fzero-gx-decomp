/* Non-matching: best partial attempt (98.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern void fn_80008BEC(void *, int, u32);
#pragma opt_strength_reduction on
void fn_1_2F04(void) {
    u8 *chk = lbl_1_bss_978 + 0x50;
    u8 *a = lbl_1_bss_978 + 0x34c;
    u8 *b = lbl_1_bss_978 + 0x380;
    u8 *c = lbl_1_bss_978 + 0x3b0;
    u8 *d = (u8 *)&lbl_1_data_2B78;
    u16 *e = (u16 *)(lbl_1_bss_978 + 0x80);
    u8 *lim = lbl_1_bss_978 + 0xd0;
    u32 i;
    u8 *q;
    u32 mask;
    for (i = 0; i < 4; i++) {
        s32 j;
        s32 k;
        u8 *p;
        if ((s8)chk[10] == -1) {
            fn_80008BEC(e, 0, 0x14);
        } else {
            p = a;
            for (j = 0; j < 13; j++) {
                s32 f;
                u32 bit = 31u - j;
                if (bit != 24) {
                    u32 shift = (32 - j) & 31;
                    if (__rlwnm(e[4], shift, 31, 31)) {
                        *p = 0;
                        f = 1;
                    } else {
                        f = 0;
                        if (*p) (*p)--;
                    }
                    if (*p != 0 || !__rlwnm(e[0], shift, 31, 31)) {
                        e[8] &= ~(0x80000000u >> bit);
                    } else {
                        if (f) *p = 20; else *p = 4;
                        e[8] |= 0x80000000u >> bit;
                    }
                }
                p++;
            }
            p = b;
            q = c;
            for (k = 0; k < 12; k++) {
                s32 f;
                s32 t;
                u8 v;
                u8 o;
                s32 bit;
                u32 remaining;
                u32 shift = (32 - k) & 31;
                if (__rlwnm(e[5], shift, 31, 31)) {
                    *p = 0;
                    f = 1;
                } else {
                    f = 0;
                    if (*p) (*p)--;
                }
                bit = 31 - k;
                remaining = *p;
                mask = 0x80000000u >> bit;
                e[9] &= ~mask;
                if (!remaining && __rlwnm(e[1], shift, 31, 31)) {
                    o = *q;
                    switch (bit) {
                    case 31: case 30:
                        t = (s8)lim[0];
                        v = ((t >> 31) ^ t) - (t >> 31); break;
                    case 29: case 28:
                        t = (s8)lim[1];
                        v = ((t >> 31) ^ t) - (t >> 31); break;
                    case 27: case 26:
                        t = (s8)lim[2];
                        v = ((t >> 31) ^ t) - (t >> 31); break;
                    case 25: case 24:
                        t = (s8)lim[3];
                        v = ((t >> 31) ^ t) - (t >> 31); break;
                    default: v = 0x48; break;
                    }
                    *q = v;
                    if (f) {
                        *p = 20;
                    } else {
                        if (v < 30 || v < o) goto next;
                        if (((u8 *)&lbl_1_data_2B78)[i] == 1) *p = (v * -4 + 0x154) / 13;
                        else *p = (v * -17 + 0x546) / 42;
                    }
                    e[9] |= mask;
                }
next:
                p++;
                q++;
            }
        }
        b += 0xc;
        a += 0xd;
        c += 0xc;
        d++;
        e = (u16 *)((u8 *)e + 0x14);
        lim += 0x10;
        chk += 0xc;
    }
}
#pragma opt_strength_reduction reset
