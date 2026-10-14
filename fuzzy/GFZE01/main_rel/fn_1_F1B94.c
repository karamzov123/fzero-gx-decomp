/* Non-matching: best partial attempt (96.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/ghost.h"

extern u8 *fn_1_3F0D8(u32, f32 *, u8 *);

typedef struct {
    u8 pad_0[0x16b4];
    u8 *unk_16b4;
    u8 pad_16b8[0x10];
    s32 unk_16c8;
    u8 pad_16cc[0x80];
    u8 unk_174c;
} GhostState;

static inline u8 fn_1_F1B94_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_propagation off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_7B180[2];
u32 fzgx_obj_lbl_1_bss_7B188[2];
u32 lbl_1_bss_7B190[2];
u32 lbl_1_bss_7B198;
u32 lbl_1_bss_7B19C[2];
u32 fzgx_obj_lbl_1_bss_7B1A4[2];
u32 fzgx_obj_lbl_1_bss_7B1AC[1270];
u32 lbl_1_bss_7C584__fzgx_offset_0[172];
u8 *lbl_1_bss_7C584__fzgx_offset_2B0;
u32 lbl_1_bss_7C584__fzgx_offset_2B4[4];
s32 lbl_1_bss_7C848;
u32 lbl_1_bss_7C848__fzgx_offset_4;
u32 lbl_1_bss_7C850[3];
u32 lbl_1_bss_7C85C__fzgx_offset_0[28];
u8 lbl_1_bss_7C85C__fzgx_offset_70;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B180;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B188;
    s = *(u8 *)&lbl_1_bss_7B190;
    s = *(u8 *)&lbl_1_bss_7B198;
    s = *(u8 *)&lbl_1_bss_7B19C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1A4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7B1AC;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2B0;
    s = *(u8 *)&lbl_1_bss_7C584__fzgx_offset_2B4;
    s = *(u8 *)&lbl_1_bss_7C848;
    s = *(u8 *)&lbl_1_bss_7C848__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_7C850;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_0;
    s = *(u8 *)&lbl_1_bss_7C85C__fzgx_offset_70;
}
#pragma section code_type ".text"

u32 fn_1_F1B94(void)
{
    
    f32 value;
    u8 *record;
    u32 current_time;
    u32 result;
    u8 *best;
    u32 best_time;

    if (*(s16 *)&lbl_1_bss_960 == 9) {
        if (lbl_1_bss_7C848 >= 0) {
{
    u8 flag;
            record = fn_1_3F0D8(0, &value, &flag);
}
            best = lbl_1_bss_7C584__fzgx_offset_2B0;
            result = 1;
            current_time = fn_1_F1B94_array_read(record, 0x1E1) * 1000 + *(u16 *)(record + 0x1E2);
            current_time = fn_1_F1B94_array_read(record, 0x1E0) * 60000 + current_time;
            best_time = fn_1_F1B94_array_read(best, 0x25) * 1000 + *(u16 *)(best + 0x26);
            if (current_time >= (fn_1_F1B94_array_read(best, 0x24) * 60000 + best_time)) {
                result = 3;
            }
            return result;
        }
        return 0;
    }
    return lbl_1_bss_7C85C__fzgx_offset_70;
}
#pragma opt_propagation reset

