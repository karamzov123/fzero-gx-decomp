/* Non-matching: best partial attempt (78.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_aur.h"

extern u8 lbl_1_rodata_D048[1200];
extern int fn_1_8D690(s16 value);
extern int fn_1_8D72C(s16 value);

typedef struct Cell {
    s16 id;
    u8 pad[2];
    u32 flags;
} Cell;

s32 fn_1_152A28(s16 id, s16 y, s16 x, Cell *table, s16 nrows, s16 ncols) {
    s16 cols = ncols;
    u32 mode = lbl_1_bss_8B3A0.unk_94 & 0x20000;
    s16 res;
    s16 rows = nrows;
    s16 ent;
    s16 grp;
    s16 total = (s16)(rows * cols);
    s16 i;
    s16 j;

    if (mode != 0) {
        if (id != -1) {
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if ((table[(i * cols) + j].flags & 0xC0000000) == 0 &&
                        table[(i * cols) + j].id == id) {
                        grp = i;
                        ent = j;
                        goto L_found;
                    }
                }
            }
        }
    } else {
        if (id != -1) {
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if ((table[(i * cols) + j].flags & 0x40000000) == 0 &&
                        table[(i * cols) + j].id == id) {
                        grp = i;
                        ent = j;
                        goto L_found;
                    }
                }
            }
        }
    }

L_found:
    if (x != 0) {
        s32 base = grp * cols;
        s32 step = x + total;

        do {
            ent = (s16)((ent + step) % cols);
            if (mode != 0) {
                if ((table[base + ent].flags & 0xC0000000) != 0) {
                    res = -1;
                } else {
                    res = table[base + ent].id;
                    if (res == -1) {
                        res = -1;
                    }
                }
            } else {
                if ((table[base + ent].flags & 0x40000000) != 0) {
                    res = -1;
                } else {
                    res = table[base + ent].id;
                    if (res == -1) {
                        res = -1;
                    }
                }
            }
        } while (res < 0);
    }

    if (y != 0) {
        s32 step = y + total;

        do {
            grp = (s16)((grp + step) % rows);
            if (mode != 0) {
                if ((table[(grp * cols) + ent].flags & 0xC0000000) != 0) {
                    res = -1;
                } else {
                    res = table[(grp * cols) + ent].id;
                    if (res == -1) {
                        res = -1;
                    }
                }
            } else {
                if ((table[(grp * cols) + ent].flags & 0x40000000) != 0) {
                    res = -1;
                } else {
                    res = table[(grp * cols) + ent].id;
                    if (res == -1) {
                        res = -1;
                    }
                }
            }
        } while (res < 0);
    }

    return res;
}
