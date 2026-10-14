/* Non-matching: best partial attempt (98.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/editor.h"

typedef struct { u8 pad_0[4]; f32 unk_4; f32 unk_8; } Arg0_3_1683C;

#define E(v) ((((u32)(v)) & 1u) ^ (((u32)(v)) >> 31)) - (((u32)(v)) >> 31)

extern s8 fn_1_A5DC4(void);
extern void fn_1_A9868(void);
extern s16 fn_1_A9FFC(s16, s16, s16, s16, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern u32 lbl_3_rodata_5B8;
extern s32 lbl_3_rodata_5BC[12];

static inline s16 fn_3_1683C_call_fn_1_A9FFC(s16 a0, s16 a1, s16 a2, s16 a3, void * a4) { return fn_1_A9FFC(a0, a1, a2, a3, a4); }
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_3_1683C(Arg0_3_1683C *arg0) {
    Obj_3_bss_A23EC *p = &lbl_3_bss_A23EC;
    s32 x = (s32)arg0->unk_4;
    s32 i;
    u8 j;
    s16 step = (s16)(p->unk_11 << 3);
    volatile u32 colA = lbl_3_rodata_5B8;   /* frame-resident: reloaded per cell */
    volatile u32 colB = lbl_3_rodata_5BC[0];
    s16 start = 0;
    u32 y = (s32)arg0->unk_8;
    s8 ii, jj;

    if (fn_1_A5DC4()) {
        start = (s16)(4 / p->unk_11);
    }
    fn_1_A9868();
    for (i = 0; (ii = (s8)i) < 256 / (s32)step; i++) {
        for (j = start; (jj = (s8)j) < 256 / (s32)step - (s32)start; j++) {
            if (E(ii) ^ E(jj)) {
                u32 c = colA;
                fn_1_A9FFC((s16)((s16)x + step * jj), (s16)((s16)y + step * ii), step, step, &c);
            } else {
                u32 c2 = colB;
                fn_3_1683C_call_fn_1_A9FFC((s16)((s16)x + step * jj), (s16)((s16)y + step * ii), step, step, &c2);
            }
        }
    }
    fn_1_AA538();
    fn_1_4E0F4();
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
