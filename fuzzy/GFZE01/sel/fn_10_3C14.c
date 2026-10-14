/* Non-matching: best partial attempt (75.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad[4];
    u32 flags;
} SelSlot;

typedef struct {
    u8 pad[0x18];
    s16 index_x;
    s16 index_y;
    SelSlot slots[][19];
} SelState;

typedef struct {
    u8 pad[0x94];
    u32 flags;
} GlobalState;

extern GlobalState lbl_1_bss_8B3A0;
extern SelState lbl_10_bss_0;
extern void fn_1_152970(s16 *, s16 *, s32, s32, SelSlot *, s16, s16);

#pragma opt_propagation off
void fn_10_3C14(void) {
    u8 *fzgx_live;
    SelState *sel = &lbl_10_bss_0;
    s16 slot_y;
    s16 slot_x;
    s16 iy;
    s16 ix;

    if (lbl_1_bss_8B3A0.flags & 4) {
        return;
    }

    iy = sel->index_y;
    ix = sel->index_x;
    fn_1_152970(&slot_y, &slot_x, 0x36, 0, (SelSlot *)&sel->slots[0][0], iy, ix);
    fzgx_live = (u8 *)&sel->slots[0][0].flags;
    *(u32 *)(fzgx_live + slot_y * 0x98 + slot_x * 8) |= 0x10000000;

    iy = sel->index_y;
    ix = sel->index_x;
    fn_1_152970(&slot_y, &slot_x, 0x37, 0, (SelSlot *)&sel->slots[0][0], iy, ix);
    *(u32 *)(fzgx_live + slot_y * 0x98 + slot_x * 8) |= 0x10000000;

    iy = sel->index_y;
    ix = sel->index_x;
    fn_1_152970(&slot_y, &slot_x, 0x38, 0, (SelSlot *)&sel->slots[0][0], iy, ix);
    *(u32 *)(fzgx_live + slot_y * 0x98 + slot_x * 8) |= 0x10000000;

    iy = sel->index_y;
    ix = sel->index_x;
    fn_1_152970(&slot_y, &slot_x, 0x39, 0, (SelSlot *)&sel->slots[0][0], iy, ix);
    *(u32 *)(fzgx_live + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
}
#pragma opt_propagation reset
