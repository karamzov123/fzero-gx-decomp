/* Non-matching: best partial attempt (93.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u32 unk_20;
} Fn_1_1FB80_Entry;

typedef struct {
    u8 pad_0[0x9C];
    u32 unk_9C;
    Fn_1_1FB80_Entry *unk_A0;
} Fn_1_1FB80_Mgr;

extern Fn_1_1FB80_Mgr *lbl_1_bss_3BE0;
extern f32 lbl_1_rodata_708;
extern float __fabsf(float);
extern u32 mathutil_mtxA_rotate_x(s16);
extern u32 mathutil_mtxA_rotate_y(s16);
extern u32 mathutil_mtxA_rotate_z(s16);
extern void fn_8006E250(void *, void *);
extern void lbl_8006D7DC(void *);

#pragma opt_propagation off

u32 fn_1_1FB80(void *arg0, u32 arg1) {
    u32 mask = arg1;
    void *p = arg0;
    u32 res = 0;
    s32 i = 0;
    Fn_1_1FB80_Entry *e = lbl_1_bss_3BE0->unk_A0;
    s32 n = (s32)lbl_1_bss_3BE0->unk_9C;
    struct { f32 a[3]; } loc;

    while (i < n) {
        if (e->unk_20 & mask) {
            lbl_8006D7DC(e);
            if (e->unk_10) {
                mathutil_mtxA_rotate_z(e->unk_10);
            }
            if (e->unk_E) {
                mathutil_mtxA_rotate_y(e->unk_E);
            }
            if (e->unk_C) {
                mathutil_mtxA_rotate_x(e->unk_C);
            }
            fn_8006E250(p, &loc);
            if (__fabsf(loc.a[0]) <= lbl_1_rodata_708 * e->unk_14) {
                if (__fabsf(loc.a[1]) <= lbl_1_rodata_708 * e->unk_18) {
                    if (__fabsf(loc.a[2]) <= lbl_1_rodata_708 * e->unk_1C) {
                        res |= e->unk_20;
                    }
                }
            }
        }
        i++;
        e++;
    }
    return res;
}
