/* Non-matching: best partial attempt (78.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"

extern u32 lbl_801A6410;
extern void *fn_1_45D0(u32, u32, void *, u32);

typedef struct {
    u8 state[0x1C];
    void *unk_1C;
    u8 unk_20;
} CustomizeInit;

#pragma opt_propagation off
#pragma opt_common_subs off
static inline void init_state(volatile Obj_3_bss_A2438 *p, u32 flags) {
    p->unk_C = 2;
    p->unk_4 = flags;
    p->unk_12 = 0;
    p->unk_14 = 0;
    p->unk_15 = 0;
    p->unk_D = 0;
    p->unk_E = 0;
    p->unk_F = 0;
    p->unk_10 = 0;
    p->unk_18 = 0;
    p->unk_1A = 0;
}

void fn_3_1857C(void) {
    CustomizeInit *p = (CustomizeInit *)&lbl_3_bss_A2438;
    init_state((Obj_3_bss_A2438 *)p->state, 0x80000000);
    p->state[0] = 0;
    p->unk_1C = fn_1_45D0(lbl_801A6410, 0x2000, lbl_3_data_3D14, 0x8C);
    p->unk_20 = 1;
}
