/* Non-matching: best partial attempt (89.50% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad[0xA];
    s8 status;
    u8 pad2;
} SelSlot;

typedef struct {
    u8 pad[0x10];
    u16 a;
    u16 b;
} SelEntry;

typedef struct {
    u8 pad[0x98];
    u32 flags;
} SelState;

typedef struct {
    u8 pad[0x4];
    s16 max;
    s16 value;
    u8 pad2[0x8C];
    u32 flags;
} SelCtrl;

extern SelState lbl_1_bss_8B3A0;
extern SelSlot lbl_1_bss_9C8[4];
extern SelEntry lbl_1_bss_9F8[4];
extern u8 lbl_10_bss_4938E;
extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16);
extern void fn_1_A2D84(u32);

void fn_10_A480(SelCtrl *arg0) {
    s32 v;
    s32 tmp;
    s16 delta = 0;
    s16 base;
    s16 i;

    tmp = 30;
    if ((arg0->flags & 2) != 0) {
        tmp = (s8)lbl_10_bss_4938E;
    }
    base = (s16)tmp;

    for (i = 0; i != 4; i++) {
    }

    {
    s16 fzgx_loop_i_804;
for (fzgx_loop_i_804 = 0; fzgx_loop_i_804 < 4; fzgx_loop_i_804++) {
        if (lbl_1_bss_9C8[fzgx_loop_i_804].status == -1) {
            continue;
        }

        if (((lbl_1_bss_8B3A0.flags << (fzgx_loop_i_804 + 1)) & 0x80000000U) == 0) {
            continue;
        }

        if (((__rlwnm(lbl_1_bss_9F8[fzgx_loop_i_804].a, 32 - (3), 31, 31))) != 0 || ((__rlwnm(lbl_1_bss_9F8[fzgx_loop_i_804].b, 32 - (3), 31, 31))) != 0) {
            delta--;
        }

        if (((lbl_1_bss_9F8[fzgx_loop_i_804].a >> 2) & 1) != 0 || ((lbl_1_bss_9F8[fzgx_loop_i_804].b >> 2) & 1) != 0) {
            delta++;
        }

        if (((lbl_1_bss_9F8[fzgx_loop_i_804].a >> 2) & 1) != 0 || ((lbl_1_bss_9F8[fzgx_loop_i_804].b >> 2) & 1) != 0) {
            fn_1_12F128(fzgx_loop_i_804);
        } else if ((((*((lbl_1_bss_9F8) + (fzgx_loop_i_804))).a >> 3) & 1) != 0 || ((lbl_1_bss_9F8[fzgx_loop_i_804].b >> 3) & 1) != 0) {
            fn_1_12F128(fzgx_loop_i_804);
        }
    }
    i = fzgx_loop_i_804;
}

    v = arg0->value + delta;
    if (v > base) {
        v = (arg0->max > 1) ? arg0->max : 1;
    } else {
        if (v < ((arg0->max > 1) ? arg0->max : 1)) {
            v = base;
        }
    }
    arg0->value = v;

    if (delta != 0) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
}
