/* Non-matching: best partial attempt (69.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80039954_Arg0 {
    u32 unk_0;
};

struct fn_80039954___cpReg_T {
    u8 pad_0[0x40];
    volatile u16 unk_40;
    volatile u16 unk_42;
    volatile u16 unk_44;
    volatile u16 unk_46;
    volatile u16 unk_48;
    volatile u16 unk_4A;
    volatile u16 unk_4C;
    volatile u16 unk_4E;
};

struct fn_80039954_gx_T {
    u8 pad_0[0x4E4];
    s16 unk_4E4;
    u32 unk_4E8;
};

extern struct fn_80039954___cpReg_T *__cpReg;
extern struct fn_80039954_gx_T *gx;

static u16 CpWaitRead(volatile u16 *lop, volatile u16 *hip) {
    u32 hi = *hip;
    u32 lo;
    u32 prev;
    do {
        prev = hi;
        lo = *lop;
        hi = *hip;
    } while (hi != prev);
    return (hi << 16) | lo;
}

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void fn_80039954(struct fn_80039954_Arg0 *arg0, u32 *arg1) {
    u32 v0;
    u32 v1;
    u16 v2;
    u16 v3;
    s32 tmp_call3;

    v0 = CpWaitRead(&__cpReg->unk_40, &__cpReg->unk_42);
    v1 = CpWaitRead(&__cpReg->unk_44, &__cpReg->unk_46);
    tmp_call3 = CpWaitRead(&__cpReg->unk_48, &__cpReg->unk_4A);
    v2 = tmp_call3;
    v3 = CpWaitRead(&__cpReg->unk_4C, &__cpReg->unk_4E);

    switch (gx->unk_4E4) {
    case 10:
        arg0->unk_0 = (v1 * 1000) / v0;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
        arg0->unk_0 = v0;
        break;
    case 35:
        arg0->unk_0 = 0;
        break;
    default:
        arg0->unk_0 = 0;
        break;
    }

    switch (gx->unk_4E8) {
    case 0:
        arg1[0] = v3 * 4;
        break;
    case 1:
    case 2:
    case 3:
        break;
        arg1[0] = v3;
    case 4:
        arg1[0] = v2 + v3 * 2;
        break;
    case 5:
        arg1[0] = v2 * 3 + v3 * 4;
        break;
    case 6:
        arg1[0] = v2 * 5 + v3 * 6;
        break;
    case 7:
        arg1[0] = v2 * 7 + v3 * 8;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 21:
        arg1[0] = v3;
        break;
    case 17:
    case 18:
    case 19:
    case 20:
        arg1[0] = v2;
        break;
    case 22:
        arg1[0] = 0;
        break;
    default:
        arg1[0] = 0;
        break;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

