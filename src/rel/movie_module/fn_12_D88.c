#include "types.h"
#pragma use_lmw_stmw on
#pragma pool_data on
#pragma readonly_strings on

typedef struct fn_12_D88_Arg0 {
    u8 pad_0[0x4];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
} fn_12_D88_Arg0;

typedef struct fn_12_D88_Arg1 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    u8 pad_10[0x4];
    s32 unk_14;
    s32 unk_18;
    u8 pad_1C[0x8];
    s32 unk_24;
    s32 unk_28;
} fn_12_D88_Arg1;

/* retail's 0x50 frame holds ten words here; fn_12_D88 fills the first six */
typedef struct {
    s32 a[10];
} fn_12_D88_Loc;

extern int fn_12_3074(fn_12_D88_Arg1 *, const char *);
extern void fn_12_309C(void *, void *, const char *);
extern void fn_12_3C17C(fn_12_D88_Loc *, s32, s32, s32, s32);

#pragma force_active on
#pragma section code_type ".fzgxpool"
static f32 fzgx_pool_primer_before(s32 value) {
    fn_12_309C(0, 0, "E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
    fn_12_309C(0, 0, "E301282: CnvToRgb888 : compo is not support.");
    fn_12_309C(0, 0, "COMPO");
    fn_12_309C(0, 0, "E301281: SFX_CnvFrmRgb888 : frmfmt is not support.");
    fn_12_309C(0, 0, "E202281: SFX_MakeTblZ32 : zclip is not set.");
    fn_12_309C(0, 0, "E202282: SFX_MakeTblZ16 : zclip is not set.");
    return 1.164f * (f32)value;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_after(void) {
    fn_12_309C(0, 0, "E201311: sfxcnv_MakeTable : compo is not support.");
    fn_12_309C(0, 0, "E201313: sfxcnv_CnvZbitToCft : zbit is invalid.");
    fn_12_309C(0, 0, "E201315: sfxcnv_CnvFrmZcmn : zclip is not set.");
    fn_12_309C(0, 0, "E201191: SFX_CnvFrmZcmn : frmfmt is not support.");
}
#pragma section code_type ".text"
#pragma force_active off

static inline void cnv_to(fn_12_D88_Arg0 *arg0, fn_12_D88_Arg1 *arg1, s32 arg2, s32 arg3) {
    fn_12_D88_Loc loc;
    s32 width;
    s32 height;
    s32 t;

    switch (arg0->unk_4) {
    case 0x11:
    case 0x101:
        loc.a[0] = arg1->unk_4;
        loc.a[1] = arg1->unk_14;
        loc.a[2] = arg1->unk_24;
        loc.a[3] = arg1->unk_8;
        loc.a[4] = arg1->unk_18;
        loc.a[5] = arg1->unk_28;
        width = (arg0->unk_8 == 0) ? arg1->unk_8 : arg0->unk_8;
        height = arg0->unk_C;
        if (height == 0) {
            height = arg1->unk_C;
        }
        switch (arg0->unk_4) {
        case 0x11:
        case 0x31:
        case 0x41:
        case 0xf1:
        case 0x1001:
            t = 0;
            break;
        case 0x21:
        case 0x101:
            t = 1;
            break;
        default:
            fn_12_309C(0, 0, "E201312: sfxcnv_IsCnvUpHalf : compo is invalid.");
            t = 0;
            break;
        }
        if (t == 1) {
            height /= 2;
        }
        fn_12_3C17C(&loc, arg2, arg3, width, height);
        break;
    case 0x21:
    case 0x31:
    case 0x41:
    case 0xf1:
    case 0x1001:
    default:
        fn_12_309C(arg0, arg1, "E201192: CnvToY84C44 : compo is not support.");
        break;
    }
}

void fn_12_D88(fn_12_D88_Arg0 *arg0, fn_12_D88_Arg1 *arg1, s32 arg2, s32 arg3) {
    s32 mode;

    mode = arg1->unk_0;
    if (arg0->unk_4 == 0) {
        arg0->unk_4 = fn_12_3074(arg1, "COMPO");
    }

    switch (mode) {
    case 3:
        cnv_to(arg0, arg1, arg2, arg3);
        break;
    case 1:
    case 2:
    default:
        fn_12_309C(arg0, arg1, "E201193: SFX_CnvFrmY84C44 : frmfmt is not support.");
        break;
    }
}
