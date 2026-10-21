/* Non-matching: best partial attempt (99.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_7_bss_0;
extern u8 lbl_7_data_0[];

extern void fn_7_4050(void);
extern void fn_1_47F74(s32);
extern s32 fn_1_465D0(s32, s32);
extern void fn_1_411A4(u32);
extern void fn_1_12F28C(void *, void *, u32, void *);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_47E54(s32);
extern void fn_80006E10(u32);
extern u32 fn_1_7FD7C(void *);
extern u8 *fn_1_12D254(s32, s32);
extern u32 fn_1_A0680(void);
extern void fn_1_A1588(void *, u32);

extern void **lbl_1_bss_6EAD0;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;

struct fn_7_FB4_state {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
    s8 *unk_14;
    u8 pad_18[0x4];
    u32 unk_1c;
    u8 pad_20[0x8];
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_34[0x8];
    u32 unk_3c;
    u32 unk_40;
    u8 unk_44[1];
};

struct fn_7_FB4_arg {
    u8 pad_0[2];
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x17];
};

void fn_7_FB4(void) {
    u8 *base;
    struct fn_7_FB4_state *state;
    struct fn_7_FB4_arg arg;
    s32 offset;
    s32 index;
    u32 *tbl;
    s32 res;

    base = lbl_7_data_0 + 0x10000;
    state = (struct fn_7_FB4_state *)&lbl_7_bss_0;
    state->unk_4 = 0;
    state->unk_28 = 0;
    state->unk_2c = 10;
    state->unk_3c = 0;
    state->unk_40 = 0;
    state->unk_30 = 0;
    fn_7_4050();
    fn_1_47F74(0xba);
    fn_1_47F74(0x9a);
    fn_1_47F74(0x9b);
    offset = state->unk_14[1] - 0x24;
    index = offset < 0 ? 0 : (offset > 9 ? 9 : offset);
    fn_1_47F74(*(u32 *)(index * 4 + (base + 0x3A14)));
    res = (s32)(base + 0x3E14);
    fn_1_465D0(res, 1);
    fn_1_411A4(1);
    fn_1_12F28C((void *)state->unk_1c, state->unk_44, 7, state->unk_14 + 1);
    fn_1_4A00(1, 0x1e, (void *)state->unk_1c);
    arg.unk_2 = *(s16 *)(state->unk_10 + 4);
    arg.unk_4 = 2;
    arg.unk_8 = 0x10;
    fn_1_47E54(0x30);
    fn_80006E10((u32)(base + 0x3E30));
    res = (s32)(base + 0x3E38);
    fn_1_465D0(res, 1);
    fn_1_7FD7C(&arg);
    fn_80006E10((u32)(base + 0x3E48));
    res = (s32)fn_1_12D254(arg.unk_2, arg.unk_4);
    fn_1_465D0(res, 1);
    fn_1_A0680();
    fn_1_A1588(*(void **)lbl_1_bss_6EAD0, 0x2e);
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
}
