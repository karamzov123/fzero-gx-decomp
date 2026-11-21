#include "types.h"

struct fn_800410A4_lbl_80178C18 {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0x4];
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
};

extern f32 lbl_801A71D8;
extern f32 lbl_801A71F8;
extern struct fn_800410A4_lbl_80178C18 lbl_80178C18;
extern u32 GXSetProjection(void *, u32);
extern void (*lbl_801A6C74)(void);

void fn_800410A4(void) {
    struct fn_800410A4_lbl_80178C18 *p = &lbl_80178C18;

    p->unk_30 = lbl_801A71D8;
    p->unk_34 = lbl_801A71D8;
    p->unk_38 = lbl_801A71D8;
    p->unk_3C = lbl_801A71D8;
    p->unk_40 = lbl_801A71D8;
    p->unk_44 = lbl_801A71D8;
    p->unk_48 = lbl_801A71D8;
    p->unk_4C = lbl_801A71D8;
    p->unk_50 = lbl_801A71D8;
    p->unk_54 = lbl_801A71D8;
    p->unk_58 = lbl_801A71D8;
    p->unk_5C = lbl_801A71D8;
    p->unk_60 = lbl_801A71D8;
    p->unk_64 = lbl_801A71D8;
    p->unk_68 = lbl_801A71D8;
    p->unk_6C = lbl_801A71D8;
    p->unk_30 = p->unk_74;
    p->unk_38 = p->unk_78;
    p->unk_44 = p->unk_7C;
    p->unk_48 = p->unk_80;
    p->unk_58 = p->unk_84;
    p->unk_5C = p->unk_88;
    p->unk_68 = lbl_801A71F8;
    GXSetProjection(&p->unk_30, 0);
    lbl_801A6C74();
}

extern u32 lbl_801A6C6C;

void fn_8004115C(u32 arg0) {
    lbl_801A6C6C = arg0;
}
