/* Non-matching: best partial attempt (88.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
extern void fn_3_3438(void);
extern u32 fn_1_B7F08(void);
extern void fn_80008BA8(void *, void *, u32);
extern s32 fn_1_F7954(void);
extern void fn_1_131004(void);
struct Selection {
    u8 pad_0[8];
    s16 unk_8;
};
struct State {
    u8 pad_0[0x4374];
    void (*unk_4374)(u32);
    u32 unk_4378;
    u8 pad_437C[0x24];
    s32 unk_43A0;
    u8 unk_43A4;
    u8 pad_43A5[0x1B];
    u8 unk_43C0[1];
};
#pragma opt_propagation off
#pragma opt_lifetimes off
u16 fn_3_39F0(void) {
    u32 base = (u32)&lbl_3_bss_0;
    struct State *state = (struct State *)(base + 0x20000);
    s32 lab_t2;
    void * lab_t0;
    if ((s32)fn_1_B7F08() == 1 && state->unk_43A4 == 0 || state->unk_43A0 == 0) {
        lab_t0 = (u8 *)&lbl_3_bss_140 + ((struct Selection *)(base + 0xF0))->unk_8 * 0x81C0;
        fn_80008BA8(lab_t0, state->unk_43C0, 0x81C0);
    } else if ((s32)fn_1_B7F08() != 0 && state->unk_43A4 != 0) {
        fn_1_F7954();
    } else {
        if (state->unk_4374 != 0) {
            state->unk_4374(state->unk_4378);
            state->unk_4374 = 0;
        }
        lab_t2 = 0x81C0;
        lab_t0 = state->unk_43C0;
        fn_80008BA8(lab_t0, (u8 *)&lbl_3_bss_140 + ((struct Selection *)(base + 0xF0))->unk_8 * 0x81C0, lab_t2);
    }
    fn_1_131004();
    fn_3_3438();
    return (u32)state;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

