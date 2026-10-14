/* Non-matching: best partial attempt (98.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/car.h"

struct fn_1_866B4_entry {
    u8 pad_0[4];
    s16 unk_4;
    u8 pad_6[0x46E];
    s8 unk_474;
};
struct fn_1_866B4_car {
    u8 pad_0[0x32C];
    struct fn_1_866B4_entry *unk_32C;
    u8 pad_330[0x110];
};
struct fn_1_866B4_state {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u8 pad_20[0xA];
    u8 unk_2A;
    u8 pad_2B[0x1D];
    volatile u8 unk_48[1];
};

#pragma opt_loop_invariants on
#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
u32 fzgx_obj_lbl_1_bss_6D838;
u32 fzgx_obj_lbl_1_bss_6D83C;
u32 lbl_1_bss_6D83C_fill_6D840[2];
u16 lbl_1_bss_6D83C_fill_6D848;
u8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A_fill_6D84B;
u32 lbl_1_bss_6D84A_fill_6D84C;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
volatile u8 fzgx_obj_lbl_1_bss_6D868[1];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C_fill_6D840;
    s = *(u8 *)&lbl_1_bss_6D83C_fill_6D848;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84B;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84C;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D864;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D868;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
s16 fn_1_866B4(u32 arg0) {
    s16 v6;
    struct fn_1_866B4_car *v0;
    u8 v1;
    s8 v4;
    s16 v2;
    
    v2 = 0;
    v0 = (struct fn_1_866B4_car *)fzgx_obj_lbl_1_bss_6D83C;
    v1 = (s8)fzgx_obj_lbl_1_bss_6D84A;
    while (v2 < v1) {
        if ((s8)arg0 == ((v2)[v0]).unk_32C->unk_474) {
            v4 = (s8)((v2)[v0]).unk_32C->unk_4;
            return v4;
        }
        v2++;
    }
    {
    volatile u8 *table = fzgx_obj_lbl_1_bss_6D868;
    v2 = 0;
    while (v2 < v1) {
        if ((s32)(((s8)arg0)[table]) == ((v2)[v0]).unk_32C->unk_4) {
            return (s8)((v2)[v0]).unk_32C->unk_4;
        }
        v2++;
    }
    }
    return -1;
}
#pragma opt_lifetimes reset

