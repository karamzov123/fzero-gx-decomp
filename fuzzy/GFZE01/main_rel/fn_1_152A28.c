/* Non-matching: best partial attempt (98.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s8 value);
extern int fn_1_8D72C(s16 value);

typedef struct Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

static inline s32 get_cell(s16 grp, s16 ent, Cell *table, s16 cols, u32 mode) {
    s32 value;
    if (mode != 0) {
        if (table[grp * cols + ent].flags & 0xC0000000)
            return -1;
    } else {
        if (table[grp * cols + ent].flags & 0x40000000)
            return -1;
    }
    value = table[grp * cols + ent].id;
    if (value == -1) value = -1;
    return value;
}

#pragma opt_lifetimes off
typedef struct lbl_1_bss_8B3A0_t {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0xb4];
} lbl_1_bss_8B3A0_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_8B3A0_t fzgx_obj_lbl_1_bss_8B3A0;
u32 lbl_1_bss_8B4EC[32];
u32 fzgx_obj_lbl_1_bss_8B56C[24];
u32 lbl_1_bss_8B5CC[8];
u32 fzgx_obj_lbl_1_bss_8B5EC;
u8 fzgx_obj_lbl_1_bss_8B5F0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B3A0;
    s = *(u8 *)&lbl_1_bss_8B4EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B56C;
    s = *(u8 *)&lbl_1_bss_8B5CC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B5EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8B5F0;
}
#pragma section code_type ".text"

s32 fn_1_152A28(s16 id, s16 y, s16 x, Cell *table, s16 nrows, s16 ncols) {
    struct { s16 value; } j;
    s16 cols = ncols;
    u32 mode;
    s32 res;
    s16 rows = nrows;
    s16 ent;
    s16 grp;
    s16 total = (s16)(rows * cols);
    struct { s16 value; } i;
    mode = fzgx_obj_lbl_1_bss_8B3A0.unk_94 & 0x20000;

    if (mode != 0) {
        if (id != -1) {
            for (i.value = 0; i.value < rows; i.value++) {
                for (j.value = 0; j.value < cols; j.value++) {
                    if ((table[(i.value * cols) + j.value].flags & 0xC0000000) == 0 &&
                        id == table[(i.value * cols) + j.value].id) {
                        grp = i.value;
                        ent = j.value;
                        goto L_found;
                    }
                }
            }
        }
    } else {
        if (id != -1) {
            for (i.value = 0; i.value < rows; i.value++) {
                for (j.value = 0; j.value < cols; j.value++) {
                    if ((table[(i.value * cols) + j.value].flags & 0x40000000) == 0 &&
                        id == table[(i.value * cols) + j.value].id) {
                        grp = i.value;
                        ent = j.value;
                        goto L_found;
                    }
                }
            }
        }
    }
L_found:
    if (x != 0) {
        s32 step = x + total;
        do {
            ent = (s16)((ent + step) % cols);
            res = get_cell(grp, ent, table, cols, mode);
        } while ((s16)res < 0);
    }
    if (y != 0) {
        s32 step = y + total;
        do {
            grp = (s16)((grp + step) % rows);
            res = get_cell(grp, ent, table, cols, mode);
        } while ((s16)res < 0);
    }
    return res;
}
#pragma opt_lifetimes reset

