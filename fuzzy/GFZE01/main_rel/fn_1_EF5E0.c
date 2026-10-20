/* Non-matching: best partial attempt (82.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/ghost.h"

extern u32 lbl_801A6410;
extern u8 lbl_1_data_3E358[];
extern void fn_1_EE530(void);
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_80008BA8(u32, u32, u32);
extern u8 *fn_1_3F0D8(u32, f32 *, u8 *);
extern u8 *fn_1_36AD0(void);

typedef struct MsgT {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 unk_A;
    u8 pad_B[0xD];
    u16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
} MsgT;

void fn_1_EF5E0(void) {
    u32 handle;
    u8 *data;
    u8 *bss;
    MsgT *msg;
    u8 *state;
    u8 *state2;
    u32 cur;
    u32 w;
    u8 x;
    s16 v;
    u8 b1;
    f32 f1;

    data = lbl_1_data_3E358;
    bss = (u8 *)&lbl_1_bss_7B180;
    if (*(s32 *)(bss + 8) == 0) {
        return;
    }
    if (*(s32 *)(bss + 0xC) == 0) {
        return;
    }
    fn_1_EE530();
    cur = *(u32 *)(bss + 0x1404);
    if (cur != 0) {
        fn_1_46B4(lbl_801A6410, cur, data + 0x2d4, 0xedd);
    }
    handle = fn_1_4630(lbl_801A6410, 0x3e80, data + 0x2d4, 0xee0);
    fn_80008BA8(handle, *(u32 *)(bss + 0x16e4), 0x3e80);
    state = fn_1_3F0D8(0, &f1, &b1);
    v = *(s16 *)(data + 0x1dc);
    msg = (MsgT *)(bss + 0x2c);
    w = *(u32 *)(bss + 0x1820);
    x = *(u8 *)(bss + 0x16e0);
    *(u8 *)(bss + 0x2c) = (u8)v;
    msg->unk_1 = x;
    msg->unk_18 = (u16)w;
    msg->unk_1C = *(u32 *)(state + 0x1d8);
    msg->unk_20 = *(u32 *)(state + 0x1dc);
    msg->unk_24 = *(u32 *)(state + 0x1e0);
    msg->unk_8 = 0x46;
    msg->unk_9 = 0x5a;
    msg->unk_A = 0;
    msg->unk_3 = 1;
    if (v >= 0x29 && v < 0x3a) {
        state2 = fn_1_36AD0();
        msg->unk_4 = 1;
        msg->unk_5 = state2[0x81a4];
        msg->unk_6 = state2[0x81ac];
        msg->unk_7 = state2[0x81b4];
    } else {
        msg->unk_4 = 0;
    }
    *(u32 *)(bss + 0x1404) = handle;
    x = lbl_1_bss_8B3A0.unk_9F;
    *(u32 *)(data + 0x1d4) = 6;
    msg->unk_2 = (u8)(x << 8);
}
