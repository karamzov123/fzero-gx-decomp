/* Non-matching: best partial attempt (94.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u16 lbl_12_rodata_448[40];
extern void fn_12_3D624(void *a);
extern void fn_12_4A18(void);
extern void fn_12_4938(void);
extern void fn_12_35F0(void);
extern void *memset(void *dst, int val, u32 len);

typedef struct lbl_12_bss_10_t {
    u32 unk8;
    u32 unkC;
    u8 pad_8[0xc];
    u32 unk1C;
    u8 pad_18[0x494];
} lbl_12_bss_10_t;

typedef struct MovieState {
    s32 unk0;
    u32 unk4;
    u8 pad8[0x4A8];
    u32 unk4B0;
} MovieState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s32 lbl_12_bss_8;
u32 lbl_12_bss_C;
lbl_12_bss_10_t lbl_12_bss_10;
u32 lbl_12_bss_4C0[42];
u32 lbl_12_bss_568[140];
u32 lbl_12_bss_798[258];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_8;
    s = *(u8 *)&lbl_12_bss_C;
    s = *(u8 *)&lbl_12_bss_10;
    s = *(u8 *)&lbl_12_bss_4C0;
    s = *(u8 *)&lbl_12_bss_568;
    s = *(u8 *)&lbl_12_bss_798;
}
#pragma section code_type ".text"

#pragma opt_strength_reduction off
void fn_12_341C(void) {
    u32 lab_t1;
    MovieState *st = (MovieState *)&lbl_12_bss_8;

    if (lbl_12_bss_8 < 1) {
        st->unk4B0 = (u32)lbl_12_rodata_448;
        memset(&lbl_12_bss_10.unk8, 0, 0x4a8);
        lbl_12_bss_10.unkC = 8;
        lab_t1 = 8;
        lbl_12_bss_10.unk1C = 1;
        fn_12_3D624(&lbl_12_bss_10.unk8);
        fn_12_4A18();
        fn_12_4938();
        fn_12_35F0();
        lbl_12_bss_8++;
        lbl_12_bss_C = 0;
    }
}
#pragma opt_strength_reduction reset
