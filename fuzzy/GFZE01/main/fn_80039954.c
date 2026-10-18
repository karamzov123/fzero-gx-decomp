/* Non-matching: best partial attempt (82.61% in the project ledger). Scored for the
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
    s32 unk_4E4;
    u32 unk_4E8;
};

extern struct fn_80039954___cpReg_T *__cpReg;
extern struct fn_80039954_gx_T *gx;

void fn_80039954(struct fn_80039954_Arg0 *arg0, u32 *arg1) {
    struct fn_80039954___cpReg_T *cp = __cpReg;
    u32 v3;
    u32 v2;
    u32 v1;
    u32 v0;
    struct { unsigned int hi; unsigned int prev; } fzgx_copy_state;
    u32 lo;

    fzgx_copy_state.hi = cp->unk_42;
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    do {
        lo = cp->unk_40;
        fzgx_copy_state.hi = cp->unk_42;
    } while (fzgx_copy_state.hi != fzgx_copy_state.prev);
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    v0 = (fzgx_copy_state.hi << 16) | lo;

    fzgx_copy_state.hi = cp->unk_46;
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    do {
        lo = cp->unk_44;
        fzgx_copy_state.hi = cp->unk_46;
    } while (fzgx_copy_state.hi != fzgx_copy_state.prev);
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    v1 = (fzgx_copy_state.hi << 16) | lo;

    fzgx_copy_state.hi = cp->unk_4A;
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    do {
        lo = cp->unk_48;
        fzgx_copy_state.hi = cp->unk_4A;
    } while (fzgx_copy_state.hi != fzgx_copy_state.prev);
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    v2 = (fzgx_copy_state.hi << 16) | lo;

    fzgx_copy_state.hi = cp->unk_4E;
    fzgx_copy_state.prev = fzgx_copy_state.hi;
    do {
        lo = cp->unk_4C;
        fzgx_copy_state.hi = cp->unk_4E;
    } while (fzgx_copy_state.hi != fzgx_copy_state.prev);
    v3 = (fzgx_copy_state.hi << 16) | lo;

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
    case 1:
    case 2:
    case 3:
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
