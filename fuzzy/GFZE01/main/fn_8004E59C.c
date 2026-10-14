/* Non-matching: best partial attempt (94.10% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_8009115C;

struct Prios {
    u32 p0;
    u32 p1;
    u32 p2;
    u32 p3;
    u32 p4;
    u32 p5;
};
extern struct Prios lbl_8012B918;

extern void fn_80058BFC(u32);
extern void fn_80058EE4(void (*)(void *), u32);
extern void fn_80058ED4(void (*)(void *), u32);
extern void fn_8004EB00(void *);
extern void fn_8004EA94(void *);

extern u32 OSCreateThread(void *thread, void (*func)(void *), void *arg, void *stackEnd, u32 stackSize, u32 priority, u16 attr);
extern void fn_8004E9A8(void *);
extern void fn_8004E8F8(void *);
extern void fn_8004E8A0(void *);
extern void fn_8004E7D4(void *);
extern void fn_8004E9D8(void);
extern u32 fn_800102AC(void);
extern void fn_80010CB0(void *);
extern void fn_80059028(u32, void (*)(void), u32);

struct State {
    u8 pad_0[0x4];
    s32 count;
    u8 pad_8[0x1C];
    u32 unk_24;
    u8 thread_7D4[0x318];
    s8 thread_8F8[0x318];
    u8 thread_8A0[0x318];
    u8 thread_9A8[0x318];
    s32 pad_C88;
    s32 unk_c8c;
    s32 unk_c90;
    s32 unk_c94;
    s32 unk_c98;
    s32 unk_c9c;
    s32 unk_ca0;
    s32 unk_ca4;
    s32 unk_ca8;
    s32 unk_cac;
    u8 stacks[4][0x2000];
};

extern struct State lbl_8017E980;

#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_8004E59C(u32 *arg0, u32 arg1) {
    struct State *state = &lbl_8017E980;
    u32 *cfg = &lbl_8009115C;
    u32 cfgval = cfg[8192];
    void * lab_t3_2;
    void * lab_t3;
    u32 tmp_call5;

    if (state->count == 0) {
        fn_80058BFC(cfgval);
        fn_80058EE4(fn_8004EB00, 0);
        fn_80058ED4(fn_8004EA94, 0);
        if (arg0 == 0) {
            lbl_8012B918.p4 = 16;
            lbl_8012B918.p0 = 1;
            lbl_8012B918.p1 = 8;
            lbl_8012B918.p2 = 12;
            lbl_8012B918.p3 = 14;
            lbl_8012B918.p5 = 24;
        } else {
            lbl_8012B918 = *(struct Prios *)arg0;
        }
        lab_t3 = (void *)&state->stacks[3][0x1000];
        OSCreateThread(&state->thread_9A8, fn_8004E9A8, 0, lab_t3, 0x1000, lbl_8012B918.p1, 1);
        lab_t3 = (void *)&state->stacks[2][0x0];
        tmp_call5 = OSCreateThread(&state->thread_8F8, fn_8004E8F8, 0, lab_t3, 0x2000, lbl_8012B918.p2, 1);
        tmp_call5;
        lab_t3 = (void *)&state->stacks[0][0x2000];
        OSCreateThread(&state->thread_8A0, fn_8004E8A0, 0, lab_t3, 0x2000, lbl_8012B918.p3, 1);
        lab_t3_2 = (void *)&state->stacks[0][0x0];
        OSCreateThread(&state->thread_7D4, fn_8004E7D4, 0, lab_t3_2, 0x2000, lbl_8012B918.p5, 1);
        state->unk_24 = fn_800102AC();
        state->unk_c94 = 1;
        state->unk_ca4 = 1;
        state->unk_c9c = 1;
        state->unk_cac = 1;
        state->unk_c90 = 0;
        state->unk_ca0 = 0;
        state->unk_c98 = 0;
        state->unk_ca8 = 0;
        state->unk_c8c = 0;
        fn_80010CB0(&state->thread_8F8);
        fn_80010CB0(&state->thread_8A0);
        fn_80010CB0(&state->thread_7D4);
        fn_80059028(6, fn_8004E9D8, 0);
    }
    state->count++;
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

