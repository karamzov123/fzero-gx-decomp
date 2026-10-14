/* Non-matching: best partial attempt (95.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"

extern void fn_1_1380F0(void *);
extern u32 fn_1_B7C00(void);
extern u32 fn_1_13ABA8(u32);
extern s32 lbl_801A66B4;

typedef void (*fn_ptr)(void *);

typedef struct {
    u32 pad_0[3];
    fn_ptr tab_0C[3];
    s32 unk_18;
    u32 pad_1C[17];
    fn_ptr tab_60[4];
} Obj_fn_tab;

static inline fn_ptr *fn_4_AC58_array_read(fn_ptr *array) {
    return array;
}

#pragma opt_propagation off
void fn_4_AC58(void) {
    Obj_fn_tab *p = (Obj_fn_tab *)&lbl_4_data_2F00;
    void * lab_t0;
    lab_t0 = (void *)fn_4_AC58_array_read(p->tab_60)[lbl_801A66B4];
    fn_1_1380F0(lab_t0);
    if ((fn_1_B7C00() & 0xFF) != 0 || (s8)lbl_4_bss_5630.unk_22 == 2) {
        fn_1_13ABA8(0);
    } else {
        fn_1_13ABA8(0x28000000);
    }
    if ((s32)p->unk_18 >= 0) {
        p->tab_0C[p->unk_18](p->tab_0C);
    }
}
#pragma opt_propagation reset
