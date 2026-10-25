#include "types.h"

struct fn_8003EAE4_lbl_80178C18 {
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
};

extern const f32 lbl_801A71D8;
extern const f32 lbl_801A71DC;
extern const f32 lbl_801A71E0;
extern const f32 lbl_801A71E4;
extern const f32 lbl_801A71E8;
extern const f32 lbl_801A71EC;
extern struct fn_8003EAE4_lbl_80178C18 lbl_80178C18;

extern u32 GXSetProjection(void *, u32);
extern void GXClearVtxDesc(void);
extern void GXInvalidateVtxCache(void);
extern void GXSetTevOrder(u32, u32, u32, u32);
extern void GXSetTevOp(u32, u32);
extern void GXSetVtxDesc(u32, u32);
extern void GXSetVtxAttrFmt(u32, u32, u32, u32, u8);
extern u32 fn_80035960(u32, u32, u32, u32, u32, u32, u32);
extern void GXSetNumTexGens(u32);
extern void fn_8003591C(u8);
extern void GXSetNumTevStages(u32);
extern void fn_80037B14(s32, s32, s32, s32);
extern void fn_80037BC0(u8, s32, u8);
extern void GXSetZCompLoc(u32);
extern void GXGetProjectionv(f32 *);

void fn_8003EAE4(void) {
    f32 tmp[4];
    struct fn_8003EAE4_lbl_80178C18 *p = &lbl_80178C18;

    GXGetProjectionv((f32 *)((u8 *)p + 0x70));
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
    p->unk_30 = lbl_801A71DC;
    p->unk_44 = lbl_801A71E0;
    p->unk_58 = lbl_801A71E4;
    p->unk_6C = lbl_801A71E4;
    p->unk_3C = lbl_801A71E8;
    p->unk_4C = lbl_801A71EC;
    GXSetProjection(&p->unk_30, 1);
    GXClearVtxDesc();
    GXInvalidateVtxCache();
    fn_80037B14(1, 4, 5, 0);
    GXSetZCompLoc(0);
    fn_8003591C(1);
    fn_80035960(4, 0, 0, 0, 0, 0, 2);
    GXSetTevOrder(0, 0xff, 0xff, 4);
    GXSetTevOp(0, 4);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    fn_80037BC0(0, 7, 0);
    GXSetVtxDesc(9, 1);
    GXSetVtxAttrFmt(0, 9, 1, 4, 0);
}
