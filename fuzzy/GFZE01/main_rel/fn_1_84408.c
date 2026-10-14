/* Non-matching: best partial attempt (97.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 _pad0[0x320];
    s16 unk_320;
    u8 _pad1[0x0A];
    u32 unk_32c;
    u8 _pad2[0x5C];
    u8 flags;
} Sig_fn_1_84124_Fn184124Object;

extern f32 lbl_1_rodata_3AB0;
extern u8 lbl_1_bss_6D9A0[0xBC];
extern u32 fn_1_83D28(Sig_fn_1_84124_Fn184124Object *, f32);

#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_dead_assignments off
s32 fn_1_84408(Sig_fn_1_84124_Fn184124Object *arg0, u32 arg1, u32 arg2) {
    u8 nDown;
    u8 nUp;
    s32 down;
    s32 up;
    s32 v;
    s32 i;

    if (arg0->unk_32c == 0) {
        for (i = 3; (s8)i < 5; i++) {
            if (arg0->flags & (1 << (s8)i)) {
                break;
            }
        }
        for (i = 3; (s8)i > -1; i--) {
            if (arg0->flags & (1 << (s8)i)) {
                break;
            }
        }
    }

    v = fn_1_83D28(arg0, lbl_1_rodata_3AB0);

    nUp = 0;
    if ((s8)v == 5) {
        up = v;
    } else if ((s8)v < 0 || (s8)v > 5) {
        /* s8: the clamp result is narrowed into the s8 slot */
        s8 t = ((s8)v < 0) ? 0 : (((s8)v > 5) ? 5 : (s8)v);
        up = t;
    } else {
        up = v;
        while ((s8)up < 5) {
            if (arg0->flags & (1 << (s8)up)) {
                goto up_done; /* slot found: leave the scan */
            } else {
                up++;
                nUp++;
            }
        }
        up = -1;
    }
up_done:

    down = v;
    nDown = 0;
    if ((s8)v == 5) {
        down = v;
    } else if ((s8)v < 0 || (s8)v > 5) {
        s8 t = ((s8)v < 0) ? 0 : (((s8)v > 5) ? 5 : (s8)v);
        down = t;
    } else {
        while ((s8)down > -1) {
            if (arg0->flags & (1 << (s8)down)) {
                goto down_done; /* slot found: leave the scan */
            } else {
                down--;
                nDown++;
            }
        }
        down = -1;
    }
down_done:

    if ((s8)up == -1 && (s8)down == -1) {
        return 3;
    }
    if ((s8)up == -1) {
        return down;
    }
    if ((s8)down == -1) {
        return up;
    }
    if ((s8)nUp > (s8)nDown) {
        return up;
    }
    if ((s8)nUp < (s8)nDown) {
        return down;
    }
    if (lbl_1_bss_6D9A0[arg0->unk_320] == 1) {
        return up;
    }
    return down;
}
#pragma opt_dead_assignments reset

#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
