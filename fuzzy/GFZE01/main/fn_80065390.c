/* Non-matching: best partial attempt (95.88% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

void fn_80064FDC(void);

static inline u8 fn_80065390_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
static inline u8 * fn_80065390_address_2038(u8 * base, u32 offset) {
    return base + offset;
}
void fn_80065390(void) {
    u32 v = *(u32 *)((u8 *)lbl_801A6C80 + 0x444);
    u32 n = v & 0xF;
    u8 *tb = (u8 *)lbl_801A6C80 + n * 16;
    u8 *node = *(u8 **)(tb + 8);
    u8 *np = node + *(u32 *)(node + 0x18);
    struct { u8 value; } i;
    struct { u8 value; } j;
    u8 c;
    u32 e;
    u8 f;
    u8 * t_2;
    u8 *p;
    u8 *t;
    u8 *q;
    u8 b;
    s8 lab_t1;

    if (*(u16 *)(node + 0x3e) != 0) {
        for (i.value = 0; i.value < 0x10; i.value++) {
            for (j.value = 0; j.value < 4; j.value++) {
                t = ((((u8 *)lbl_801A6C80) + (j.value)) + (0xd88));
                lab_t1 = (u8)n * 64 + i.value * 4;
                c = fn_80065390_array_read(t, lab_t1);
                if (c != 0xff) {
                    e = c * 32;
                    f = 0;
                    p = (u8 *)lbl_801A6C80 + e;
                    if (fn_80065390_array_read(p, 0x589) & 1) {
                        f = 1;
                    }
                    if (f != 0) {
                        p[0x588] = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x589) = 0;
                        *(u32 *)((u8 *)lbl_801A6C80 + e + 0x5a0) = 0;
                        *(u32 *)((u8 *)lbl_801A6C80 + e + 0x5a4) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x58a) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x599) = 0x40;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x59a) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x59b) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x59c) = 0;
                        *(u8 *)((u8 *)lbl_801A6C80 + e + 0x59d) = 0;
                        t_2 = (u8 *)lbl_801A6C80 + j.value + 0xd88;
                        t_2[((i.value * 4) + ((u8)n * 64))] = 0xff;
                    }
                }
            }
        }
        tb = (u8 *)lbl_801A6C80 + n * 16;
        *(u32 *)(tb + 0x48c) = ((*(u16 *)(node + 0x3e)) + ((u32)np));
        tb = (u8 *)lbl_801A6C80 + n * 16;
        q = *(u8 **)(tb + 0x48c);
        b = fn_80065390_array_read(q, 1);
        if (b != 0x80) {
            *(u8 *)(tb + 0x493) = b;
        }
        fn_80064FDC();
    } else {
        *(u32 *)(tb + 0x48c) = 0;
    }
}
#pragma opt_lifetimes reset
