/* Non-matching: best partial attempt (96.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"

struct Obj3_Idx {
    u8 pad_0[0xC2];
    s16 idx;
};

struct Obj3_Tab {
    u8 pad_0[0x850];
    u32 arg;
    u32 base;
};

extern u16 lbl_3_bss_7E084[220];
extern s32 lbl_3_data_11D4;
extern s32 lbl_3_data_B8;
extern u32 lbl_1_bss_6D82C;

extern void fn_1_7B4C0(void);
extern void fn_1_12A2B8(u32);
extern void fn_1_12A2D0(s32);
extern void fn_1_12A734(s32);
extern void fn_1_7F934(void *);
extern void fn_80071718(void *);
extern u32 fn_1_F9A80(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_426C(u32);
extern void fn_1_48140(int);

typedef struct lbl_3_bss_C_t {
    s32 unk_C;
    u8 pad_4[0x8];
} lbl_3_bss_C_t;

typedef struct lbl_3_bss_20_t {
    u8 fzgx_byte_20;
    u8 pad_1[0xcf];
} lbl_3_bss_20_t;

typedef struct lbl_3_bss_140_t {
    u8 fzgx_byte_2000;
    u8 pad_1[0x1e843];
} lbl_3_bss_140_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_3_bss_0[2];
s32 lbl_3_bss_8;
lbl_3_bss_C_t lbl_3_bss_C;
u32 fzgx_obj_lbl_3_bss_18[2];
lbl_3_bss_20_t fzgx_obj_lbl_3_bss_20;
u32 fzgx_obj_lbl_3_bss_F0[12];
u32 lbl_3_bss_120[8];
lbl_3_bss_140_t fzgx_obj_lbl_3_bss_140;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_3_bss_0;
    s = *(u8 *)&lbl_3_bss_8;
    s = *(u8 *)&lbl_3_bss_C;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_20;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_F0;
    s = *(u8 *)&lbl_3_bss_120;
    s = *(u8 *)&fzgx_obj_lbl_3_bss_140;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
#pragma opt_loop_invariants off
void fn_3_6E14(void) {
    struct Obj3_Tab *tab = (struct Obj3_Tab *)((u8 *)&fzgx_obj_lbl_3_bss_140.fzgx_byte_2000);
    struct { s16 value; } i;
    u8 *arr = (u8 *)lbl_3_bss_7E084;

    if (*(s16 *)(arr + ((struct Obj3_Idx *)((u8 *)&fzgx_obj_lbl_3_bss_20.fzgx_byte_20))->idx * 10 + 2) == 1) {
        fn_1_7B4C0();
    }

    if (lbl_3_data_11D4 != -1) {
        fn_1_12A2B8(1);
        fn_1_12A2D0(lbl_3_data_11D4);
    } else {
        fn_1_12A2B8(0);
    }

    for (i.value = 0; i.value < 0x29; i.value++) {
        fn_1_7F934((void *)(tab->base + i.value * 0x440));
    }

    if (lbl_1_bss_6D82C != 0) {
        fn_80071718((void *)lbl_1_bss_6D82C);
        lbl_1_bss_6D82C = 0;
    }

    if (lbl_3_data_11D4 != -1) {
        fn_1_12A734(lbl_3_data_11D4);
    }

    lbl_3_data_11D4 = -1;
    fn_1_12A2B8(0);

    if (lbl_3_bss_8 != 0 && lbl_3_bss_C.unk_C != 0) {
        fn_1_F9A80();
    }

    if (-1 != lbl_3_data_B8) {
        fn_1_435C(tab->arg);
        fn_1_426C(lbl_3_data_B8);
        lbl_3_data_B8 = -1;
    }

    fn_1_48140(0xa3);
}
#pragma opt_loop_invariants reset

#pragma opt_dead_assignments reset

