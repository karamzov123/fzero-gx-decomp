/* Non-matching: best partial attempt (89.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/car.h"

extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_1071C0(void);
extern u32 fn_80008E84(u32);
extern u32 lbl_801A6410;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_6D820;
u32 fzgx_obj_lbl_1_bss_6D824;
u32 lbl_1_bss_6D828;
u32 fzgx_obj_lbl_1_bss_6D82C[3];
u32 fzgx_obj_lbl_1_bss_6D838;
u32 fzgx_obj_lbl_1_bss_6D83C[3];
u16 lbl_1_bss_6D83C_fill_6D848;
s8 fzgx_obj_lbl_1_bss_6D84A;
u8 lbl_1_bss_6D84A_fill_6D84B;
u32 lbl_1_bss_6D84A_fill_6D84C;
u32 lbl_1_bss_6D850;
u32 lbl_1_bss_6D854[4];
u32 fzgx_obj_lbl_1_bss_6D864;
u8 fzgx_obj_lbl_1_bss_6D868;
u8 lbl_1_bss_6D820_gap_6D869;
u16 lbl_1_bss_6D820_gap_6D869_fill_6D86A;
u32 lbl_1_bss_6D86C[34];
u32 lbl_1_bss_6D8F4_fill_6D8F4[30];
s8 lbl_1_bss_6D8F4_78;
u8 lbl_1_bss_6D8F4_fill_6D96D;
u16 lbl_1_bss_6D8F4_fill_6D96E;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D820;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D824;
    s = *(u8 *)&lbl_1_bss_6D828;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D82C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D838;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D83C;
    s = *(u8 *)&lbl_1_bss_6D83C_fill_6D848;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D84A;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84B;
    s = *(u8 *)&lbl_1_bss_6D84A_fill_6D84C;
    s = *(u8 *)&lbl_1_bss_6D850;
    s = *(u8 *)&lbl_1_bss_6D854;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D864;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D868;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6D869;
    s = *(u8 *)&lbl_1_bss_6D820_gap_6D869_fill_6D86A;
    s = *(u8 *)&lbl_1_bss_6D86C;
    s = *(u8 *)&lbl_1_bss_6D8F4_fill_6D8F4;
    s = *(u8 *)&lbl_1_bss_6D8F4_78;
    s = *(u8 *)&lbl_1_bss_6D8F4_fill_6D96D;
    s = *(u8 *)&lbl_1_bss_6D8F4_fill_6D96E;
}
#pragma section code_type ".text"

#pragma opt_lifetimes off
void fn_1_854D4(void)
{
    
    u8 *data = (u8 *)&lbl_1_data_1F1D8;
    u32 i;
    u8 *el;
    s8 (*m)[4] = (s8 (*)[4])(data + 0x1484);
    u32 j;
    u32 k;
    u32 saved;

    for (j = 0; j < 4; j++) {
        for (k = 0; k < 3; k++) {
            (*((k) + (m)))[j] = -1;
        }
    }

    for (; i < (u32)(s32)fzgx_obj_lbl_1_bss_6D84A; ) {
        if (*(u32 *)(0x484 + el) != 0) {
            saved = fn_80008E84(*(u32 *)(*(u32 *)(el + 0x484) + 0x40));
            fn_1_46B4(*(u32 *)&lbl_801A6410, *(u32 *)(el + 0x484),
                       (const char *)(data + 0xe18), 0xdd2);
            *(u32 *)(el + 0x484) = 0;
            fn_80008E84(saved);
        }
        for (j = 0; j < 4; j++) {
            if (*(u32 *)(el + 0x488 + 4 * j) != 0) {
                fn_1_46B4(*(u32 *)&lbl_801A6410, *(u32 *)(el + 0x488 + 4 * j),
                           (const char *)(data + 0xe18), 0xdd9);
                *(u32 *)(((0x488) + ((4 * j) + (el)))) = 0;
            }
        }
        if (*(u32 *)(el + 0x498) != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, *(u32 *)(el + 0x498),
                       (const char *)(((0xe18) + (data))), 0xddf);
            *(u32 *)(el + 0x498) = 0;
        }
        if (*(u32 *)(el + 0x49c) != 0) {
            fn_1_46B4(*(u32 *)&lbl_801A6410, *(u32 *)(el + 0x49c),
                       (const char *)(data + 0xe18), 0xde4);
            *(u32 *)(el + 0x49c) = 0;
        }
        i++;
        el += 0x620;
    }

    fn_1_1071C0();
    fn_1_46B4(*(u32 *)&lbl_801A6410, fzgx_obj_lbl_1_bss_6D838,
               (const char *)(data + 0xe18), 0xdeb);
    fzgx_obj_lbl_1_bss_6D838 = 0;
    fzgx_obj_lbl_1_bss_6D84A = 0;
    lbl_1_bss_6D8F4_78 = 0;
}
#pragma opt_lifetimes reset

