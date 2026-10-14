/* Non-matching: best partial attempt (86.49% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bitmap.h"

extern s32 fn_1_48A0C(u32, u32, void *, u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3E058;
u32 fzgx_obj_lbl_1_bss_3E05C;
u32 lbl_1_bss_3E060_fill_3E060[6];
u8 lbl_1_bss_3E060_18;
u8 lbl_1_bss_3E060_fill_3E079;
u16 lbl_1_bss_3E060_fill_3E07A;
u32 lbl_1_bss_3E060_fill_3E07C[1380];
u32 lbl_1_bss_3F60C_fill_3F60C[1387];
u32 lbl_1_bss_3F60C_15AC;
u32 fzgx_obj_lbl_1_bss_40BBC;
u32 lbl_1_bss_40BBC_fill_40BC0[43];
u32 lbl_1_bss_40C6C_fill_40C6C[2735];
u8 lbl_1_bss_40C6C_2ABC;
u8 lbl_1_bss_40C6C_fill_43729;
u16 lbl_1_bss_40C6C_fill_4372A;
u32 lbl_1_bss_40C6C_fill_4372C[8360];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E058;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3E05C;
    s = *(u8 *)&lbl_1_bss_3E060_fill_3E060;
    s = *(u8 *)&lbl_1_bss_3E060_18;
    s = *(u8 *)&lbl_1_bss_3E060_fill_3E079;
    s = *(u8 *)&lbl_1_bss_3E060_fill_3E07A;
    s = *(u8 *)&lbl_1_bss_3E060_fill_3E07C;
    s = *(u8 *)&lbl_1_bss_3F60C_fill_3F60C;
    s = *(u8 *)&lbl_1_bss_3F60C_15AC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_40BBC;
    s = *(u8 *)&lbl_1_bss_40BBC_fill_40BC0;
    s = *(u8 *)&lbl_1_bss_40C6C_fill_40C6C;
    s = *(u8 *)&lbl_1_bss_40C6C_2ABC;
    s = *(u8 *)&lbl_1_bss_40C6C_fill_43729;
    s = *(u8 *)&lbl_1_bss_40C6C_fill_4372A;
    s = *(u8 *)&lbl_1_bss_40C6C_fill_4372C;
}
#pragma section code_type ".text"

void fn_1_487EC(void) {
    
    Obj_1_data_1AEA8 *obj;
    Obj_1_data_1AEA8 *sub;
    u16 *ids;
    u16 *s;
    u32 *counts;
    int i;
    struct { u32 value; } j;

    for (i = 0; i < 0x56B; i++) {
        ((u32 *)((u8 *)(u32 *)&lbl_1_bss_3E060_18))[i] = 0;
        ((s32 *)((u8 *)(u32 *)&lbl_1_bss_40C6C_2ABC))[i] = -1;
    }

    i = 0;
    obj = &lbl_1_data_1AEA8;
    lbl_1_bss_3F60C_15AC = 0;
    counts = &fzgx_obj_lbl_1_bss_40BBC;
    for (; i < 0x2C; i++) {
        counts[i] = 0;
        if ((s32)obj->unk_0 == -1) {
            s = (u16 *)obj->unk_2C;
            j.value = 0;
            while (*s != 0) {
                s++;
                *(s16 *)((u8 *)obj->unk_30 + j.value) = -1;
                j.value += 2;
                counts[i]++;
            }
        }
        obj = (Obj_1_data_1AEA8 *)((u8 *)obj + 0x4);
    }

    ids = (u16 *)&lbl_1_data_1A3B8;
    sub = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + 0x930);
    {
    u32 fzgx_loop_i_2595;
for (fzgx_loop_i_2595 = 0; fzgx_loop_i_2595 < 0x56B; fzgx_loop_i_2595++) {
        u16 id = ids[fzgx_loop_i_2595];
{
    u16 * fzgx_loop_s_2711;
        j.value = 0;
        fzgx_loop_s_2711 = (u16 *)sub->unk_2C;
        while (*fzgx_loop_s_2711 != 0) {
            if (*fzgx_loop_s_2711 == id) {
                if (fn_1_48A0C(j.value, 0x2A, sub, 1) != 0) {
                    lbl_1_bss_3F60C_15AC = lbl_1_bss_3F60C_15AC + 1;
                    break;
                }
            }
            j.value++;
            fzgx_loop_s_2711++;
        }
    s = fzgx_loop_s_2711;
}
    }
    i = fzgx_loop_i_2595;
}
}
