#include "types.h"

struct fn_8003E9EC_lbl_8012B658 {
    u8 pad_0[0xC];
    f32 unk_C;
    u8 pad_10[0x8];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x4];
    f32 unk_28;
    f32 unk_2C;
    u8 pad_30[0x4];
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    u8 pad_40[0xC];
    f32 unk_4C;
    u8 pad_50[0xC];
    f32 unk_5C;
    u8 pad_60[0x24];
    f32 unk_84;
    u8 pad_88[0x4];
    f32 unk_8C;
};

extern f32 lbl_801A6C64;
extern const f32 lbl_801A71C8;
extern const f64 lbl_801A71D0;
extern struct fn_8003E9EC_lbl_8012B658 lbl_8012B658;
extern void PSMTXIdentity(void *);
extern u8 lbl_80178C18[144];
extern u32 lbl_801A6C54;
extern u32 lbl_801A6C60;
extern u32 lbl_801A6C68;
extern u32 lbl_801A6C74;
/* fzgx-allow: A1 SDK absolute-addressed OS clock globals */
u32 __OSBusClock : (0x80000000 + 0xF8);
u32 __OSCoreClock : (0x80000000 + 0xFC);

#pragma opt_propagation off
void fn_8003E9EC(u32 arg0) {
    f32 *fzgx_value;
    f32 v;
    f32 w;
    struct fn_8003E9EC_lbl_8012B658 *p;
    u32 counter;

    p = (struct fn_8003E9EC_lbl_8012B658 *)&lbl_8012B658;
    PSMTXIdentity(&lbl_80178C18);
    counter = lbl_801A6C54;
    lbl_801A6C74 = arg0;
    lbl_801A6C60 = __OSCoreClock / 60 * 3;
    lbl_801A6C64 = (f32)(u32)((counter + 1) * 7);
    lbl_801A6C68 = __OSBusClock / 120;
    v = lbl_801A6C64;
    p->unk_5C = v;
    p->unk_4C = v;
    p->unk_3C = v;
    p->unk_34 = v;
    fzgx_value = &(p->unk_2C);
    *fzgx_value = v;
    p->unk_C = v;
    w = (616.0f);
    p->unk_38 = (616.0f);
    p->unk_28 = (616.0f);
    p->unk_20 = (616.0f);
    p->unk_18 = (616.0f);
    p->unk_84 = (f32)(u32)((counter + 2) * 19);
    p->unk_8C = p->unk_84;
}
#pragma opt_propagation reset

