/* Non-matching: best partial attempt (87.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_win.h"

extern f32 lbl_1_rodata_DD98[46];

typedef struct {
    u8 unk_0[4];
    u8 pad_4[4];
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 unk_B;
    u8 pad_C[0x24];
    f32 unk_30;
} Entry;

typedef struct lbl_1_bss_8FD68_t {
    u8 fzgx_byte_0;
    u8 pad_1[0xf];
    u8 pad_10[0x30];
} lbl_1_bss_8FD68_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_8FD68_t fzgx_obj_lbl_1_bss_8FD68;
u32 fzgx_obj_lbl_1_bss_8FDA8[53];
u8 lbl_1_bss_8FE7C;
u8 lbl_1_bss_8FD68_gap_8FE7D;
u16 lbl_1_bss_8FD68_gap_8FE7D_fill_8FE7E;
u32 lbl_1_bss_8FE80[8];
u32 lbl_1_bss_8FEA0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FD68;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8FDA8;
    s = *(u8 *)&lbl_1_bss_8FE7C;
    s = *(u8 *)&lbl_1_bss_8FD68_gap_8FE7D;
    s = *(u8 *)&lbl_1_bss_8FD68_gap_8FE7D_fill_8FE7E;
    s = *(u8 *)&lbl_1_bss_8FE80;
    s = *(u8 *)&lbl_1_bss_8FEA0;
}
#pragma section code_type ".text"

static inline f32 fn_1_15E27C_array_read(s32 index, f32 *array) { return array[index]; }
#pragma peephole off
void fn_1_15E27C(void) {
    Entry *e = (Entry *)&fzgx_obj_lbl_1_bss_8FD68.pad_10[0x30];
    f32 z = fn_1_15E27C_array_read(0, lbl_1_rodata_DD98);

    e[0].unk_0[0] = 0;
    e[0].unk_0[1] = 0;
    e[0].unk_0[2] = 0;
    e[0].unk_0[3] = 0;
    e[0].unk_8 = 0;
    e[0].unk_9 = 0;
    e[0].unk_B = 0;
    e[0].unk_A = 0;
    e[0].unk_30 = z;

    ((1)[e]).unk_0[0] = 0;
    e[1].unk_0[1] = 0;
    e[1].unk_0[2] = 0;
    e[1].unk_0[3] = 0;
    e[1].unk_8 = 0;
    e[1].unk_9 = 0;
    e[1].unk_B = 0;
    e[1].unk_A = 0;
    e[1].unk_30 = z;

    e[2].unk_0[0] = 0;
    e[2].unk_0[1] = 0;
    e[2].unk_0[2] = 0;
    e[2].unk_0[3] = 0;
    e[2].unk_8 = 0;
    e[2].unk_9 = 0;
    e[2].unk_B = 0;
    e[2].unk_A = 0;
    e[2].unk_30 = z;

    e[3].unk_0[0] = 0;
    e[3].unk_0[1] = 0;
    e[3].unk_0[2] = 0;
    e[3].unk_0[3] = 0;
    e[3].unk_8 = 0;
    e[3].unk_9 = 0;
    e[3].unk_B = 0;
    e[3].unk_A = 0;
    e[3].unk_30 = z;

    *(f32 *)((u8 *)((u8 *)&fzgx_obj_lbl_1_bss_8FD68.fzgx_byte_0) + 0x110) = z;
    *((u8 *)((u8 *)&fzgx_obj_lbl_1_bss_8FD68.fzgx_byte_0) + 0x114) = 0;
}
#pragma peephole reset

