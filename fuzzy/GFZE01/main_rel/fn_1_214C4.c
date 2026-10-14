/* Non-matching: best partial attempt (97.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern const f32 lbl_1_rodata_6D0;
extern Obj_1_bss_3BE0_Target *lbl_1_bss_3BE0;

typedef struct Fn_1_214C4_Item {
    u8 pad_00[0x40];
    f32 unk_40;
    f32 unk_44;
} Fn_1_214C4_Item;

typedef struct Fn_1_214C4_Entry {
    u8 pad_00[0x4];
    Fn_1_214C4_Item *unk_4;
    u8 pad_08[0x4];
} Fn_1_214C4_Entry;

typedef struct Fn_1_214C4_Obj {
    u8 pad_00[0x8];
    int count;
    Fn_1_214C4_Entry *entries;
    u8 pad_10[0x80];
    f32 *period;
} Fn_1_214C4_Obj;

#pragma opt_lifetimes off
static inline int *fn_1_214C4_array_read(int *array) { return array; }
#pragma opt_pointer_analysis on
#pragma opt_loop_invariants off
static inline f32 fn_1_214C4_read_pointer(Fn_1_214C4_Item * owner) { return owner->unk_40; }
#pragma opt_loop_invariants reset

int fn_1_214C4(f32 *out, int index, f32 angle) {
    f32 fzgx_live;
    int count;
    int directions[2];
    int result;
    int i;
    int remainder;
    f32 lower;
    f32 upper;
    Fn_1_214C4_Item *item;
    union {
        f32 value;
        u32 bits;
    } angle_bits;

    *out = (0.0f);
    if (lbl_1_bss_3BE0 == 0) {
        return 0;
    }
    count = lbl_1_bss_3BE0->unk_8;
    if (count == 0) {
        return 0;
    }
    if (index < 0 || count <= index) {
        index = 0;
    }

    angle_bits.value = angle;
    directions[0] = 0;
    directions[1] = -1;
    result = 0;

    if ((angle_bits.bits & 0x7f800000) == 0x7f800000) {
        return 0;
    }

    while (angle < (0.0f)) {
        angle += *(f32 *)lbl_1_bss_3BE0->unk_90;
    }
    while (angle >= *(f32 *)lbl_1_bss_3BE0->unk_90) {
        angle -= *(f32 *)lbl_1_bss_3BE0->unk_90;
    }

    for (i = 0; i < count; i++) {
        remainder = (index + fn_1_214C4_array_read(directions)[i & 1] + count) % count;
        if (i & 1) {
            directions[((1) & (i))]--;
        } else {
            directions[i & 1] = (*((i & 1) + (directions))) + 1;
        }
        item = ((Fn_1_214C4_Obj *)lbl_1_bss_3BE0)->entries[remainder].unk_4;
        fzgx_live = fn_1_214C4_read_pointer(item);
        lower = fzgx_live;
        upper = item->unk_44;
        if (lower <= angle && angle <= upper) {
            *out = (angle - lower) / (upper - lower);
            result = remainder;
            break;
        }
    }
    return result;
}
#pragma opt_pointer_analysis reset

#pragma opt_lifetimes reset

